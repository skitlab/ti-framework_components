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
 *  ======== main_BIOS.c ========
 *
 */

/* xdctools header files */
#include <xdc/std.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/System.h>

/* package header files */
#include <ti/ipc/Ipc.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sdo/rcm/examples/appcfg/App.h>
#include <ti/sdo/rcm/examples/appcfg/SystemCfg.h>

/* local header files */
#include "AppObject.h"
#include "Global.h"

/* private constants and types */

/* private functions */
static Void AppMain_main_P(UArg arg0, UArg arg1);

/* private data */


/*
 *  ======== main ========
 */
#define FXNN "main"
Int main(Int argc, Char* argv[])
{
    Error_Block     eb;
    Task_Params     taskParams;


    /* must initialize the error block before using it */
    Error_init(&eb);

    /* initialize ipc layer */
    Ipc_start();

    /* create main thread (interrupts not enabled in main on BIOS) */
    Task_Params_init(&taskParams);
    taskParams.instance->name = "AppMain_main_P";
    taskParams.arg0 = (UArg)argc;
    taskParams.arg1 = (UArg)argv;
    taskParams.stackSize = 0x4000;
    Task_create(AppMain_main_P, &taskParams, &eb);

    if (Error_check(&eb)) {
        System_abort("main() failed to create application startup thread");
    }

    /* start scheduler, this never returns */
    BIOS_start();
    
    /* should never get here */
    return(0);
}
#undef FXNN


/*
 *  ======== AppMain_main_P ========
 */
#define FXNN "AppMain_main_P"
Void AppMain_main_P(UArg arg0, UArg arg1)
{
    Int                 status;
    Error_Block         eb;
    App_Object *        app;
    SystemCfg_Params    systemCfgP;
    SystemCfg_Handle    systemCfgH;


    Log_print2(Diags_ENTRY,
        "--> "FXNN": (arg0: 0x%x, arg1: 0x%x)", (IArg)arg0, (IArg)arg1);

    /* initialize local vars */
    status = 0;
    systemCfgH = NULL;
    app = &App_Object_V;
    Error_init(&eb);

    /* initialize used modules */
    SystemCfg_init();
    App_init();

    /* turn on some trace */
    Diags_setMask("SystemCfg+EXF;App+EXF");

    /* create a SystemCfg instance for the remote processor */
    SystemCfg_Params_init(&systemCfgP);
    systemCfgP.remoteProcName = app->hostProcName;

    status = SystemCfg_create(&systemCfgP, &systemCfgH);

    if (status < 0) {
        goto leave;
    }

    /* attach to the remote processor */
    status = SystemCfg_attach(systemCfgH);

    if (status < 0) {
        Log_error1(FXNN": SystemCfg_attach() returned error %d", (IArg)status);
        goto leave;
    }

    /* create local resources and open remote resources */
    status = SystemCfg_initializeResources(systemCfgH, App_startup, app);

    if (status < 0) {
        Log_error1(FXNN": SystemCfg_initializeResources() returned error %d",
            (IArg)status);
        goto leave;
    }

    /* wait for the shutdown signal */
    SystemCfg_waitForShutdown(systemCfgH);

    /* start the shutdown process */
    status = SystemCfg_finalizeResources(systemCfgH, App_shutdown, app);

    if (status < 0) {
        Log_error1(FXNN": SystemCfg_finalizeResources() returned error %d",
            (IArg)status);
        goto leave;
    }

    /* detach from the remote processor */
    status = SystemCfg_detach(systemCfgH);

    if (status < 0) {
        Log_error1(FXNN": SystemCfg_detach() returned error %d", (IArg)status);
        goto leave;
    }

    /* delete SystemCfg instance */
    if (systemCfgH != NULL) {
        SystemCfg_delete(&systemCfgH);
    }

    /* finalize used modules */
    App_exit();
    SystemCfg_exit();


leave:
    Log_print1(Diags_EXIT, "<-- "FXNN": %d", (IArg)status);
    return;
}
#undef FXNN
/*
 *  @(#) ti.sdo.rcm.examples.minidist.linux.server; 1,0,0,4; 2-22-2012 18:10:25; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

