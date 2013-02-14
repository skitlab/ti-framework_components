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

/* local header files */
#include <SystemCfg.h>

/* log string macros */
#define LOGSECT ".string.log.autoviz.prog_ComputeDevice"
#define mkpragma(x) _Pragma(#x)
#define mkdata(n,s) mkpragma(DATA_SECTION(n,s))
#define MKLOGSTR(i,s) mkdata(LogStr_##i, LOGSECT) \
static const char LogStr_##i[] = s
#define LOGSTR(i) (LogStr_##i)

/* define log strings */
#if xdc_runtime_Log_DISABLE_ALL == 0
MKLOGSTR( 1, "--> main:");
MKLOGSTR( 2, "--> smain:");
MKLOGSTR( 3, "<-- smain: %d");
MKLOGSTR( 4, "smain: SystemCfg_startAck() failed");
MKLOGSTR( 5, "smain: SystemCfg_attach() failed");
MKLOGSTR( 6, "smain: SystemCfg_createResources() failed");
MKLOGSTR( 7, "smain: SystemCfg_openResources() failed");
MKLOGSTR( 8, "smain: ComputeDevice_start() failed");
MKLOGSTR( 9, "smain: ComputeDevice_stop() failed");
MKLOGSTR(10, "smain: SystemCfg_closeResources() failed");
MKLOGSTR(11, "smain: SystemCfg_deleteResources() failed");
MKLOGSTR(12, "smain: SystemCfg_detach() error %d");
#endif
MKLOGSTR(13, "main: failed to create application startup thread");

/* private constants and types */

/* private functions */
static Void smain(UArg arg0, UArg arg1);


/*
 *  ======== main ========
 */
Int main(Int argc, Char* argv[])
{
    Error_Block     eb;
    Task_Params     taskParams;


    Log_print0(Diags_INFO, LOGSTR(1));

    /* must initialize the error block before using it */
    Error_init(&eb);

    /* create main thread (interrupts not enabled in main on BIOS) */
    Task_Params_init(&taskParams);
    taskParams.instance->name = "smain";
    taskParams.arg0 = (UArg)argc;
    taskParams.arg1 = (UArg)argv;
    taskParams.stackSize = 0x700;
    Task_create(smain, &taskParams, &eb);

    if (Error_check(&eb)) {
        System_abort((String)(LOGSTR(13)));
    }

    /* start scheduler, this never returns */
    BIOS_start();
    
    /* should never get here */
    return(0);
}


/*
 *  ======== smain ========
 */
Void smain(UArg arg0, UArg arg1)
{
    Int                 status = 0;
    Error_Block         eb;
    SystemCfg_Params    systemCfgP;
    SystemCfg_Handle    systemCfgH = NULL;
    ComputeDevice_Cfg   compDevCfg;


    Log_print0(Diags_ENTRY | Diags_INFO, LOGSTR(2));

    Error_init(&eb);

    /* initialize modules */
    SystemCfg_init();
    ComputeDevice_init();

    /* start all statically created threads now */
    Thread_start(NULL);

    /* turn on some trace */
//  Diags_setMask("SystemCfg+F;ComputeDevice+F");
    Diags_setMask("ComputeDevice+F");
//  Diags_setMask("TsrKnl+F1");

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
        Log_error0(LOGSTR(4));
        goto leave;
    }

    /* attach to the remote processor */
    status = SystemCfg_attach(systemCfgH);

    if (status < 0) {
        Log_error0(LOGSTR(5));
        goto leave;
    }

    /* create local resources */
    status = SystemCfg_createResources(systemCfgH);

    if (status < 0) {
        Log_error0(LOGSTR(6));
        goto leave;
    }

    /* wait for handshake before opening remote resources */
    SystemCfg_handshakeEvent(systemCfgH, SystemCfg_EvtCreateDone);

    /* open shared resources from remote core */
    status = SystemCfg_openResources(systemCfgH);

    if (status < 0) {
        Log_error0(LOGSTR(7));
        goto leave;
    }

    /* start the compute device, start the OpenCL Runtime */
    compDevCfg.rcmServerName = SystemCfg_RcmServer_CompDev;
    status = ComputeDevice_start((Ptr)(&compDevCfg));

    if (status < 0) {
        Log_error0(LOGSTR(8));
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
        Log_error0(LOGSTR(9));
        goto leave;
    }

    /* close shared resources from remote core */
    status = SystemCfg_closeResources(systemCfgH);

    if (status < 0) {
        Log_error0(LOGSTR(10));
        goto leave;
    }

    /* wait for handshake before deleting local resources */
    SystemCfg_handshakeEvent(systemCfgH, SystemCfg_EvtCloseDone);

    /* delete local resources */
    status = SystemCfg_deleteResources(systemCfgH);

    if (status < 0) {
        Log_error0(LOGSTR(11));
        goto leave;
    }

    /* wait for handshake before terminating */
    SystemCfg_handshakeEvent(systemCfgH, SystemCfg_EvtDone);

#if 0  /* SDOCM85206, SDOCM85207 */
    /* detach from the remote processor */
    status = SystemCfg_detach(systemCfgH);

    if (status < 0) {
        Log_error1(LOGSTR(12), (IArg)status);
        goto leave;
    }

    /* prepare to be stopped */
    SystemCfg_stop(systemCfgH);
#endif

    /* delete SystemCfg instance */
    if (systemCfgH != NULL) {
        SystemCfg_delete(&systemCfgH);
    }

    /* finalize modules */
    ComputeDevice_exit();
    SystemCfg_exit();

leave:
    Log_print1(Diags_EXIT, LOGSTR(3), (IArg)status);
    return;
}
/*
 *  @(#) ti.sdo.opencl.examples.autoviz; 1, 0, 0,4; 2-22-2012 18:09:19; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

