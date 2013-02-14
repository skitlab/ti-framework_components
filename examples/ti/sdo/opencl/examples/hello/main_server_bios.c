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
 *  ======== main_server_BIOS.c ========
 *
 */

/* xdctools header files */
#include <xdc/std.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/knl/Thread.h>

/* package header files */
#include <ti/ipc/Ipc.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sdo/opencl/ComputeDevice.h>

/* platform specific header files */
#define SYSINC(m) <m>
#include SYSINC(Platform_SystemCfg_h)

/* private functions */
static Void smain(UArg arg0, UArg arg1);


/*
 *  ======== main ========
 */
#define FXNN "main"
Int main(Int argc, Char* argv[])
{
    Task_Params taskParams;

    /* create main thread (interrupts not enabled in main on BIOS) */
    Task_Params_init(&taskParams);
    taskParams.instance->name = "smain";
    taskParams.arg0 = (UArg)argc;
    taskParams.arg1 = (UArg)argv;
    taskParams.stackSize = 0x700;
    Task_create(smain, &taskParams, NULL);

    /* start scheduler, this never returns */
    BIOS_start();
    
    /* should never get here */
    return(0);
}
#undef FXNN


/*
 *  ======== smain ========
 */
#define FXNN "smain"
Void smain(UArg arg0, UArg arg1)
{
    Int                 status = 0;
    SystemCfg_Params    systemCfgP;
    SystemCfg_Handle    systemCfgH = NULL;
    ComputeDevice_Cfg   compDevCfg;


    /* initialize modules */
    SystemCfg_init();
    ComputeDevice_init();

    /* start all statically created threads now */
    Thread_start(NULL);

    /* turn on some trace */
//  Diags_setMask("SystemCfg+F;ComputeDevice+F");
    Diags_setMask("ComputeDevice+FEX");

    /* create a SystemCfg instance for the remote processor */
    SystemCfg_Params_init(&systemCfgP);
    systemCfgP.remoteProcName = SystemCfg_Host_ProcName;

    status = SystemCfg_create(&systemCfgP, &systemCfgH);

    if (status < 0) {
        goto leave;
    }

    /* let the host know this processor has started */
    status = SystemCfg_startAck(systemCfgH);

    if (status < 0) {
        Log_error0(FXNN": SystemCfg_startAck() failed");
        goto leave;
    }

    /* attach to the remote processor, blocks until remote side attaches */
    status = SystemCfg_attach(systemCfgH);

    if (status < 0) {
        Log_error0(FXNN": SystemCfg_attach() failed");
        goto leave;
    }

    /* wait for remote create done event */
    SystemCfg_waitForEvent(systemCfgH, SystemCfg_EvtCreateDone);

    /* open remote resources */
    SystemCfg_openResources(systemCfgH);

    /* start the compute device, start the OpenCL Runtime */
    compDevCfg.rcmServerName = SystemCfg_RcmServer_CompDev;

    status = ComputeDevice_start((Ptr)(&compDevCfg));

    if (status < 0) {
        Log_error0(FXNN": ComputeDevice_start() failed");
        goto leave;
    }

    /* send ready event */
    SystemCfg_sendEvent(systemCfgH, SystemCfg_EvtReady);

    /*
     *  BEGIN execute phase
     */

    /* wait for the shutdown signal */
    SystemCfg_waitForEvent(systemCfgH, SystemCfg_EvtShutdown);

    /*
     *  END execute phase
     */

    /* stop the compute device */
    status = ComputeDevice_stop((Ptr)(&compDevCfg));

    if (status < 0) {
        Log_error0(FXNN": ComputeDevice_stop() failed");
        goto leave;
    }

    /* close remote resources */
    SystemCfg_closeResources(systemCfgH);

    /* send close done event */
    SystemCfg_sendEvent(systemCfgH, SystemCfg_EvtCloseDone);

    /* wait for handshake before terminating */
    SystemCfg_handshakeEvent(systemCfgH, SystemCfg_EvtDone);

#if 0  /* SDOCM85206, SDOCM85207 */
    /* detach from the remote processor */
    SystemCfg_detach(systemCfgH);

    /* prepare to be stopped */
    SystemCfg_stop(systemCfgH);
#endif

    /* delete SystemCfg instance */
    SystemCfg_delete(&systemCfgH);

    /* finalize modules */
    ComputeDevice_exit();
    SystemCfg_exit();

leave:
    Log_print1(Diags_EXIT, "<-- "FXNN": %d", (IArg)status);
    return;
}
#undef FXNN
/*
 *  @(#) ti.sdo.opencl.examples.hello; 1, 0, 0,4; 2-22-2012 18:09:29; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

