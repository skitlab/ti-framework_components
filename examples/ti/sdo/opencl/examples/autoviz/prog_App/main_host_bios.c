/* 
 * Copyright (c) 2012, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */


/*
 *  ======== main_host_BIOS.c ========
 *
 */


/* xdctools header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/knl/Thread.h>

/* package header files */
#include <ti/ipc/Ipc.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

/* application header files */
#include <AutoViz.h>
#include <SystemCfg.h>


/* private functions */
static Void smain(UArg arg0, UArg arg1);

/* private data */
const unsigned char *PROG_ENG1 = (const unsigned char *)SystemCfg_PROG_CONFIG;

/*
 *  ======== main ========
 */
Int main(Int argc, Char* argv[])
{
    Task_Params taskParams;

    /* create main thread (interrupts not enabled in main on BIOS) */
    Task_Params_init(&taskParams);
    taskParams.instance->name = "smain";
    taskParams.arg0 = (UArg)argc;
    taskParams.arg1 = (UArg)argv;
    taskParams.stackSize = 0x4000;
    Task_create(smain, &taskParams, NULL);

    /* start scheduler, this never returns */
    BIOS_start();
    
    /* should never get here */
    return(0);
}


/*
 *  ======== main ========
 */
#define FXNN "smain"
Void smain(UArg arg0, UArg arg1)
{
    Int                 status;
    SystemCfg_Params    systemCfgP;
    SystemCfg_Handle    systemCfgH;
    AutoViz_Cfg         autoVizCfg;


    Log_print0(Diags_ENTRY | Diags_INFO, "--> "FXNN":");

    /* initialize modules */
    SystemCfg_init();
    AutoViz_init();

    /* start all statically created threads now */
    Thread_start(NULL);

    /* enable some trace */
    Diags_setMask("SystemCfg+F;AutoViz+EXF");

    /* create a SystemCfg instance for the remote processor core 1 */
    SystemCfg_Params_init(&systemCfgP);
    systemCfgP.remoteProcName = SystemCfg_ComputeDevice_ProcName;

    status = SystemCfg_create(&systemCfgP, &systemCfgH);

    if (status < 0) {
        goto leave;
    }

    /* start remote processor */
    status = SystemCfg_start(systemCfgH, "");

    if (status < 0) {
        goto leave;
    }

    /* attach to the remote processor */
    status = SystemCfg_attach(systemCfgH);

    if (status < 0) {
        goto leave;
    }

    /* create local resources */
    status = SystemCfg_createResources(systemCfgH);

    if (status < 0) {
        Log_error1(
            FXNN": SystemCfg_createResources() returned error %d",
            (IArg)status);
        goto leave;
    }

    /* wait for handshake before opening remote resources */
    SystemCfg_handshakeEvent(systemCfgH, SystemCfg_EvtCreateDone);

    /* open shared resources from remote core */
    status = SystemCfg_openResources(systemCfgH);

    if (status < 0) {
        Log_error0(FXNN": SystemCfg_openResources() failed");
        goto leave;
    }

    /* wait for handshake before starting execute phase */
    SystemCfg_handshakeEvent(systemCfgH, SystemCfg_EvtReady);

    /*
     *  BEGIN execute phase
     */

    /* application start phase */
    autoVizCfg.program = (String)PROG_ENG1;

    status = AutoViz_start((Ptr)&autoVizCfg);

    if (status < 0) {
        goto leave;
    }

    /* application execute phase */
    status = AutoViz_exec((Ptr)(&autoVizCfg));

    if (status < 0) {
        goto leave;
    }

    /* application stop phase */
    status = AutoViz_stop((Ptr)&autoVizCfg);

    if (status < 0) {
        goto leave;
    }

    /*
     *  END execute phase
     */

    /* start the shutdown process */
    SystemCfg_sendEvent(systemCfgH, SystemCfg_EvtShutdown);

    /* close shared resources from remote core */
    status = SystemCfg_closeResources(systemCfgH);

    if (status < 0) {
        Log_error0(FXNN": SystemCfg_closeResources() failed");
        goto leave;
    }

    /* wait for handshake before deleting local resources */
    SystemCfg_handshakeEvent(systemCfgH, SystemCfg_EvtCloseDone);

    /* delete local resources */
    status = SystemCfg_deleteResources(systemCfgH);

    if (status < 0) {
        Log_error0(FXNN": SystemCfg_deleteResources() failed");
        goto leave;
    }

    /* wait for handshake before terminating */
    SystemCfg_handshakeEvent(systemCfgH, SystemCfg_EvtDone);

#if 0  /* SDOCM85206, SDOCM85207 */
    /* detach from the server processor */
    SystemCfg_detach(systemCfgH);

    /* stop the remote processor, TODO ensure this does not happen too soon */
    SystemCfg_stop(systemCfgH);
#endif

    /* delete SystemCfg instance */
    if (systemCfgH != NULL) {
        SystemCfg_delete(&systemCfgH);
    }

    /* finalize modules */
    AutoViz_exit();
    SystemCfg_exit();

leave:
    Log_print1(Diags_EXIT | Diags_INFO, "<-- "FXNN": %d", (IArg)status);
}
#undef FXNN
/*
 *  @(#) ti.sdo.opencl.examples.autoviz; 1, 0, 0,4; 2-22-2012 18:09:19; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

