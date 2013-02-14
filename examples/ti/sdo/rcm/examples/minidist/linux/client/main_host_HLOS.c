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
#include <xdc/runtime/knl/Thread.h>

/* package header files */
#include <ti/ipc/MultiProc.h>
#include <ti/syslink/SysLink.h>
#include <ti/sdo/rcm/examples/appcfg/App.h>
#include <ti/sdo/rcm/examples/appcfg/SystemCfg.h>

#include <ti/sdo/rcm/examples/minidist/linux/server/Global.h>

/* local header files */
#include "AppObject.h"

/* private constants and types */

/* private functions */
static Void Main_pause(String msg);
static Int Main_parseArgs(Int argc, Char *argv[]);


/* private data */
#define Main_Usage_C "\
Usage:\n\
    ClientApp [options] <remoteProcName> <program>\n\
\n\
Options:\n\
    d control   : set diags according to control string\n\
    h           : print this help message\n\
    l           : list the available remote names\n\
    p           : pause at interesting points\n\
\n\
Examples:\n\
    ClientApp VIDEO Server\n\
    ClientApp -p VIDEO Server\n\
    ClientApp -d \"SystemCfg+EXF;App+EXF\" VIDEO Server\n\
    ClientApp -d \"ti.sdo.rcm.%+F\" VIDEO Server\n\
    ClientApp -l\n\
    ClientApp -h\n\
\n"

/* private data */
static String   Main_Filename_V = NULL;
static Bool     Main_Pause_V = FALSE;


/*
 *  ======== main ========
 */
#define FXNN "main"
Int main(Int argc, Char* argv[])
{
    Int                 status, startStat, resStat;
    Error_Block         eb;
    App_Object *        app;
    SystemCfg_Params    systemCfgP;
    SystemCfg_Handle    systemCfgH;


    /* initialize local vars */
    status = 0;
    systemCfgH = NULL;
    app = &App_Object_V;
    Error_init(&eb);

    /* must initialize a module before using it */
    SystemCfg_init();
    App_init();

    /* start all statically created threads now */
    Thread_start(&eb);

    if (Error_check(&eb)) {
        Log_error0(FXNN": Thread_start() failed");
        status = -1;
        goto leave;
    }

    /* turn on some trace */
    Diags_setMask("SystemCfg+F;App+F");

    /* parse the command line arguments */
    status = Main_parseArgs(argc, argv);

    if (status < 0) {
        status = -2;
        goto leave;
    }
    Main_pause(NULL);

    /* create a SystemCfg instance for the remote processor */
    SystemCfg_Params_init(&systemCfgP);
    systemCfgP.remoteProcName = app->remoteProcName;

    status = SystemCfg_create(&systemCfgP, &systemCfgH);

    if (status < 0) {
        goto leave;
    }

    /* bring up the remote processor */
    System_printf(FXNN": starting remote processor\n");

    startStat = SystemCfg_start(systemCfgH, Main_Filename_V);

    if (startStat < 0) {
        status = -1;
        goto leave;
    }

    /* create local resources, some might be shared */
    resStat = SystemCfg_initializeResources(systemCfgH, App_startup, app);

    if (resStat < 0) {
        status = -1;
        goto leave;
    }
    Main_pause(NULL);

    /* invoke the application entry point */
    System_printf(FXNN": entering application exec phase\n");

    status = App_exec(app);

    if (status < 0) {
        goto leave;
    }

    /* start the shutdown process */
    SystemCfg_sendShutdown(systemCfgH);


leave:
    if (resStat >= 0) {
        SystemCfg_finalizeResources(systemCfgH, App_shutdown, app);
    }

    Main_pause("*** disconnect CCS now ***");

    /* stop remote processor */
    if (startStat >= 0) {
        System_printf(FXNN": stopping remote processor\n");
        SystemCfg_stop(systemCfgH);
    }

    /* delete SystemCfg instance */
    if (systemCfgH != NULL) {
        SystemCfg_delete(&systemCfgH);
    }

    /* finalize used modules */
    App_exit();
    SystemCfg_exit();

    /* report if error */
    if (status < 0) {
        System_printf("FAIL: example encountered errors\n");
    }
    return(status);
}
#undef FXNN


/*
 *  ======== Main_pause ========
 */
#define FXNN "Main_pause"
Void Main_pause(String msg)
{

    if (Main_Pause_V) {
        if (msg != NULL) {
            System_printf("%s\n", msg);
        }
        System_printf("Press the Enter key to continue...\n");

        if (getchar() == 'c') {
            Main_Pause_V = FALSE;
        }
    }
}
#undef FXNN


/*
 *  ======== Main_parseArgs ========
 */
#define FXNN "Main_parseArgs"
Int Main_parseArgs(Int argc, Char *argv[])
{
    Int             x, cp, opt, argNum;
    UInt16          i, numProcs;
    Char *          arg;
    String          name;
    Int             status = 0;
    App_Object *    app = &App_Object_V;


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
                System_printf("%s", Main_Usage_C);
                System_exit(0);
                break;

            case 'l': /* -l */
                System_printf("Processor List\n");
                SysLink_setup();
                numProcs = MultiProc_getNumProcessors();
                for (i = 0; i < numProcs; i++) {
                    name = MultiProc_getName(i);
                    System_printf("    procId=%d, procName=%s\n", i, name);
                }
                SysLink_destroy();
                System_exit(0);
                break;

            case 'p':       /* -p */
                Main_Pause_V = TRUE;
                break;

            default:
                System_printf(
                    "Error: %s, line %d: invalid option, %c\n",
                    __FILE__, __LINE__, (Char)x);
                System_printf("%s", Main_Usage_C);
                status = -1;
                goto leave;
        }
    }

    /* parse the command line arguments */
    for (argNum = 1; opt < argc; argNum++, opt++) {

        switch (argNum) {
            case 1: /* remoteProcName */
                app->remoteProcName = argv[opt];
                break;

            case 2: /* filename */
                Main_Filename_V = argv[opt];
                break;

            default:
                System_printf(
                    "Error: %s, line %d: too many arguments\n",
                    __FILE__, __LINE__);
                System_printf("%s", Main_Usage_C);
                status = -1;
                goto leave;
        }
    }

    /* validate command line arguments */
    if (app->remoteProcName == NULL) {
        System_printf(
            "Error: %s, line %d: missing argument: <remoteProcName>\n",
            __FILE__, __LINE__);
        System_printf("%s", Main_Usage_C);
        status = -1;
        goto leave;
    }

    if (Main_Filename_V == NULL) {
        System_printf(
            "Error: %s, line %d: missing argument: <program>",
            __FILE__, __LINE__);
        System_printf("%s", Main_Usage_C);
        status = -1;
        goto leave;
    }

leave:
    return(status);
}
#undef FXNN
/*
 *  @(#) ti.sdo.rcm.examples.minidist.linux.client; 1,0,0,4; 2-22-2012 18:10:10; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

