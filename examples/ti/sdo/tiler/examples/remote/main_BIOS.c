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
#include <xdc/runtime/Types.h>

/* package header files */
#include <ti/ipc/Ipc.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

/* local header files */
#include "App.h"
#include "SystemCfg.h"

/* private constants and types */

/* private functions */
static
Void AppMain_main__P(
        UArg            arg0,
        UArg            arg1
    );

/* private data */


/*
 *  ======== main ========
 */
#define FXNN "main"
Int main(Int argc, Char* argv[])
{
    Error_Block eb;
    Task_Params taskParams;


    Log_print3(Diags_ENTRY,
        "--> %s: (argc: %d, argv: 0x%x)", (IArg)FXNN, (IArg)argc, (IArg)argv);

    /* must initialize the error block before using it */
    Error_init(&eb);

    /* initialize ipc layer */
    Ipc_start();

    /* create main thread (interrupts not enabled in main on BIOS) */
    Task_Params_init(&taskParams);
    taskParams.instance->name = "AppMain_main__P";
    taskParams.arg0 = (UArg)argc;
    taskParams.arg1 = (UArg)argv;
    taskParams.stackSize = 0x4000;
    Task_create(AppMain_main__P, &taskParams, &eb);

    if (Error_check(&eb)) {
        System_abort("main() failed to create application startup thread");
    }

    /* start scheduler, this never returns */
    BIOS_start();
    
    /* should never get here */
    Log_print1(Diags_EXIT, "<-- %s: should never get here", (IArg)FXNN);
    return(0);
}
#undef FXNN


/*
 *  ======== AppMain_main__P ========
 */
#define FXNN "AppMain_main__P"
Void AppMain_main__P(UArg arg0, UArg arg1)
{
    Error_Block eb;
    Int status = 0;


    Log_print3(Diags_ENTRY,
        "--> %s: (arg0: 0x%x, arg1: 0x%x)", (IArg)FXNN, (IArg)arg0, (IArg)arg1);


    /* initialize used modules */
    SystemCfg_init();
    Error_init(&eb);

    /* start acknowledgement */
    status = SystemCfg_startAck();

    if (status < 0) {
        /* Log_error() */
        Log_print4(Diags_USER8,
            "Error: %s, line %d: %s: SystemCfg_startAck() returned error %d",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN, (IArg)status);
        goto leave;
    }

    /* system and application configuration */
    status = SystemCfg_createLocalResources();

    if (status < 0) {
        /* Log_error() */
        Log_print4(Diags_USER8,
            "Error: %s, line %d: %s: "
            "SystemCfg_createLocalResources() returned error %d",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN, (IArg)status);
        goto leave;
    }

    /* open shared resources */
    status = SystemCfg_openSharedResources(App_startup, NULL);

    if (status < 0) {
        /* Log_error() */
        Log_print4(Diags_USER8,
            "Error: %s, line %d: %s: "
            "SystemCfg_openSharedResources() returned error %d",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN, (IArg)status);
        goto leave;
    }

    /* invoke the application entry point */
    status = App_exec(NULL);

    if (status < 0) {
        /* Log_error() */
        Log_print4(Diags_USER8,
            "Error: %s, line %d: %s: App_exec() returned error %d",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN, (IArg)status);
        goto leave;
    }

    /* start the shutdown process */
    status = SystemCfg_closeSharedResources(App_shutdown, NULL);

    if (status < 0) {
        /* Log_error() */
        Log_print4(Diags_USER8,
            "Error: %s, line %d: %s: "
            "SystemCfg_closeSharedResources() returned error %d",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN, (IArg)status);
        goto leave;
    }

    status = SystemCfg_deleteLocalResources();

    if (status < 0) {
        /* Log_error() */
        Log_print4(Diags_USER8,
            "Error: %s, line %d: %s: "
            "SystemCfg_deleteLocalResources() returned error %d",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN, (IArg)status);
        goto leave;
    }

    /* finalize used modules */
    SystemCfg_exit();


leave:
    Log_print2(Diags_EXIT, "<-- %s: %d", (IArg)FXNN, (IArg)status);
    return;
}
#undef FXNN


/*
 *  ======== AppMain_errorHook ========
 */
Void AppMain_errorHook(Error_Block *eb)
{
    String fmt;
    Error_Data *data;
    Types_Site *site;

    if (eb == NULL) {
        return;
    }

    fmt = Error_getMsg(eb);

    if (fmt != NULL) {
        data = Error_getData(eb);
        Log_print2(Diags_USER8, fmt, (IArg)data->arg[0], (IArg)data->arg[1]);
        site = Error_getSite(eb);
        Log_print2(Diags_USER8,
            "Site: %s: line: %d", (IArg)site->file, (IArg)site->line);
        Error_print(eb);
    }
}
/*
 *  @(#) ti.sdo.tiler.examples.remote; 1, 0, 0,4; 2-22-2012 18:10:55; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

