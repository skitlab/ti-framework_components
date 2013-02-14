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
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/knl/Thread.h>

#include <ti/ipc/Ipc.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

/* platform specific header file, defined in makefile */
#define SYSINC(m) <m>
#include SYSINC(Platform_SystemCfg_h)

/* main(), running at thread level */
Void smain(UArg arg0, UArg arg1);

/* external function */
Int main_app(Char *progConfig);


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
 *  ======== smain ========
 */
#define FXNN "smain"
Void smain(UArg arg0, UArg arg1)
{
    Int                 status = -1;
    SystemCfg_Params    systemCfgP;
    SystemCfg_Handle    systemCfgH;
//  Int                 argc = (Int)arg0;
//  Char **             argv = (Char **)arg1;


    /* initialize modules */
    SystemCfg_init();

    /* start all statically created threads now */
    Thread_start(NULL);

    /* enable some trace */
//  Diags_setMask("SystemCfg+EXF");

    /* create a SystemCfg instance for the remote processor */
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

    /* attach to the server processor, blocks until remote side attaches */
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

    /* send create done event */
    SystemCfg_sendEvent(systemCfgH, SystemCfg_EvtCreateDone);

    /* wait for handshake before starting execute phase */
    SystemCfg_handshakeEvent(systemCfgH, SystemCfg_EvtReady);

    /*
     *  BEGIN execute phase
     */

    /* invoke the application entry point */
    status = main_app(SystemCfg_PROG_CONFIG);

    if (status < 0) {
        goto leave;
    }

    /*
     *  END execute phase
     */

    /* start the shutdown process */
    SystemCfg_sendEvent(systemCfgH, SystemCfg_EvtShutdown);

    /* wait for remote close done event */
    SystemCfg_waitForEvent(systemCfgH, SystemCfg_EvtCloseDone);

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

    /* stop the remote processor, make sure this does not happen too soon */
    SystemCfg_stop(systemCfgH);
#endif

    /* delete SystemCfg instance */
    SystemCfg_delete(&systemCfgH);

    /* finalize used modules */
    SystemCfg_exit();

leave:
    Log_print1(Diags_EXIT | Diags_INFO, "<-- "FXNN": %d", (IArg)status);
}
#undef FXNN
/*
 *  @(#) ti.sdo.opencl.examples.hello; 1, 0, 0,4; 2-22-2012 18:09:29; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

