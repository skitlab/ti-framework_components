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
 *  ======== main_HLOS.c ========
 *
 */


/* C Standard Library header files */
#include <stdio.h>

/* xdctools header files */
#include <xdc/std.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/knl/SemThread.h>
#include <xdc/runtime/knl/Thread.h>

/* IPC header files */
#include <ti/ipc/MultiProc.h>
#include <ti/ipc/Notify.h>

/* SysLink header files */
#include <ti/syslink/SysLink.h>

/* package header files */

/* local header files */
#include "App.h"
#include "SystemCfg.h"

/* global application state */
App_State App_State_obj;

/* private constants and types */
#define WAIT_TICKS 2000

typedef struct {
    Bool                pause;
    String              remoteProcName;
    String              filename;
    String              usage;
} AppMain_Data;

/* private functions */
static
Void main_pause(
        String          msg,
        AppMain_Data *  appData
    );

static
Int main_parseArgs(
        Int             argc,
        Char *          argv[],
        AppMain_Data *  appData
    );


/* private data */
#define USAGE "\
Usage:\n\
    AppTest [options] <remoteProcName> <executable>\n\
\n\
Options:\n\
    d control   : set diags according to control string\n\
    h           : print this help message\n\
    l           : list the available remote names\n\
    p           : pause at interesting points\n\
\n\
Examples:\n\
    AppTest VIDEO program\n\
    AppTest -d \"xdc.runtime.%+EX12;ti.sdo.%+EX12\" Server\n\
    AppTest -h\n\
\n"

static AppMain_Data AppMain_data;


/*
 *  ======== main ========
 */
#define FXNN "main"
Int main(Int argc, Char* argv[])
{
    Error_Block eb;
    Int cfgStat;
    AppMain_Data *appData = &AppMain_data;
    App_State *appState = &App_State_obj;
    Int status = 0;


    System_printf("--> %s: (argc: %d, argv: 0x%x)\n", FXNN, argc, argv);

    /* must initialize the error block before using it */
    SystemCfg_init();
    Error_init(&eb);

    /* initialize local object */
    appData->pause = FALSE;
    appData->remoteProcName = NULL;
    appData->filename = NULL;
    appData->usage = USAGE;

    /* initialize application state */
    appState->remoteProcName = NULL;
    appState->remoteProcId = MultiProc_INVALIDID;

    /* start all statically created threads now */
    Thread_start(&eb);

    if (Error_check(&eb)) {
        System_printf(
            "Error: %s, line %d: Thread_start() failed\n" __FILE__, __LINE__);
        status = -1;
        goto leave;
    }

    /* parse the command line arguments */
    status = main_parseArgs(argc, argv, appData);

    if (status < 0) {
        status = -2;
        goto leave;
    }
    main_pause(NULL, appData);

    /* bring up the remote processor */
    System_printf("%s: starting remote processor\n", FXNN);

    cfgStat = SystemCfg_start(appData->remoteProcName, appData->filename);

    if (cfgStat < 0) {
        status = -3;
        goto leave;
    }

    /* create local resources, some might be shared */
    cfgStat = SystemCfg_createLocalResources();

    if (cfgStat < 0) {
        status = -4;
        goto leave;
    }
    main_pause(NULL, appData);

    /* open shared resources */
    cfgStat = SystemCfg_openSharedResources(App_startup, (Ptr)appState);

    if (cfgStat < 0) {
        status = -5;
        goto leave;
    }

    /* invoke the application entry point */
    System_printf("%s: entering application exec phase\n", FXNN);

    status = App_exec((Ptr)appState);

    if (status < 0) {
        status = -4;
    }

    /* start the shutdown process */
    if (cfgStat >= 0) {
        cfgStat = SystemCfg_closeSharedResources(App_shutdown, (Ptr)appState);

        if (cfgStat < 0) {
            status = -6;
        }
    }

    if (cfgStat >= 0) {
        cfgStat = SystemCfg_deleteLocalResources();

        if (cfgStat < 0) {
            status = -7;
        }
    }

    main_pause("*** disconnect CCS now ***", appData);

    /* stop remote processor */
    if (cfgStat >= 0) {
        System_printf("%s: stopping remote processor\n", FXNN);

        cfgStat = SystemCfg_stop();

        if (cfgStat < 0) {
            status = -8;
        }
    }

    /* finalize used modules */
    SystemCfg_exit();


leave:
    System_printf("<-- %s: %d\n", FXNN, status);

    if (status < 0) {
        System_printf("\nFAIL: test encountered errors\n");
    }
    else {
        System_printf("\nPASS: test was successful\n");
        status = 0;
    }
    return(status);
}
#undef FXNN


/*
 *  ======== main_pause ========
 */
#define FXNN "main_pause"
Void main_pause(String msg, AppMain_Data *appData)
{

    if (appData->pause) {
        if (msg != NULL) {
            System_printf("%s\n", msg);
        }
        System_printf("Press the Enter key to continue...\n");

        if (getchar() == 'c') {
            appData->pause = FALSE;
        }
    }
}
#undef FXNN


/*
 *  ======== main_parseArgs ========
 */
#define FXNN "main_parseArgs"
Int main_parseArgs(Int argc, Char *argv[], AppMain_Data *appData)
{
    Char *arg;
    Int x, cp, opt, argNum;
    UInt16 i, numProcs;
    String name;
    Int status = 0;


    Log_print1(Diags_ENTRY, "--> %s: (...)", (IArg)FXNN);

    /* parse the command line options */
    for (opt = 1; (opt < argc) && (argv[opt][0] == '-'); opt++) {
        for (x = 0, cp = 1; argv[opt][cp] != '\0'; cp++) {
            x = (x << 8) | (int)argv[opt][cp];
        }
        arg = argv[opt+1];

        switch (x) {
            case 'd':       /* -d */
                Diags_setMask(arg);
                opt++;
                break;

            case 'h': /* -h */
                System_printf("%s", appData->usage);
                System_exit(0);
                break;

            case 'l': /* -l */
                System_printf("Remote Processor List\n");
                SysLink_setup();
                numProcs = MultiProc_getNumProcessors();
                for (i = 0; i < numProcs; i++) {
                    name = MultiProc_getName(i);
                    System_printf(
                        "    procId=%d, remoteProcName=%s\n", i, name);
                }
                SysLink_destroy();
                System_exit(0);
                break;

            case 'p':       /* -p */
                appData->pause = TRUE;
                break;

            default:
                System_printf(
                    "Error: %s, line %d: invalid option, %c\n",
                    __FILE__, __LINE__, (Char)x);
                System_printf("%s", appData->usage);
                status = -1;
                goto leave;
        }
    }

    /* parse the command line arguments */
    for (argNum = 1; opt < argc; argNum++, opt++) {

        switch (argNum) {
            case 1: /* remoteProcName */
                appData->remoteProcName = argv[opt];
                App_State_obj.remoteProcName = argv[opt];
                break;

            case 2: /* filename */
                appData->filename = argv[opt];
                break;

            default:
                System_printf(
                    "Error: %s, line %d: too many arguments\n",
                    __FILE__, __LINE__);
                System_printf("%s", appData->usage);
                status = -1;
                goto leave;
        }
    }

    /* validate command line arguments */
    if (NULL == appData->remoteProcName) {
        System_printf(
            "Error: %s, line %d: missing argument: <remoteProcName>\n",
            __FILE__, __LINE__);
        System_printf("%s", appData->usage);
        status = -1;
        goto leave;
    }

    if (NULL == appData->filename) {
        System_printf(
            "Error: %s, line %d: missing argument: <program>\n",
            __FILE__, __LINE__);
        System_printf("%s", appData->usage);
        status = -1;
        goto leave;
    }

leave:
    Log_print2(Diags_EXIT, "<-- %s: %d", (IArg)FXNN, (IArg)status);
    return(status);
}
#undef FXNN
/*
 *  @(#) ti.sdo.tiler.examples.remote; 1, 0, 0,4; 2-22-2012 18:10:56; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

