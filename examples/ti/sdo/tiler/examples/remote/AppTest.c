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
 *  ======== AppTest.c ========
 *
 */


/* xdctools header files */
#include <xdc/std.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/knl/SemThread.h>

/* package header files */
#include <ti/ipc/MultiProc.h>
#include <ti/ipc/Notify.h>
#include <ti/sdo/tiler/MemMgr.h>
#include <ti/sdo/tiler/Settings.h>

/* local header files */
#include "App.h"
#include "SystemCfg.h"

/* private constants and types */

/* private functions */
static
Void App_notifyCB__P(
        UInt16          procId,
        UInt16          lineId,
        UInt32          eventNum,
        UArg            arg,
        UInt32          payload
    );


/* private data */
static MemMgr_Daemon_Handle gTilerDaemonH = NULL;
static SemThread_Struct gSemObj;
static SemThread_Handle gSemH = NULL;


/*
 *  ======== App_startup ========
 */
#define FXNN "App_startup"
Int App_startup(Ptr arg)
{
    Error_Block eb;
    SemThread_Params semThreadP;
    App_State *state = (App_State *)arg;
    Int status = 0;


    Log_print2(Diags_ENTRY, "--> %s: (arg: 0x%x)", (IArg)FXNN, (IArg)arg);

    Error_init(&eb);

    /* translate remote proc name into proc id */
    state->remoteProcId = MultiProc_getId(state->remoteProcName);

    if (MultiProc_INVALIDID == state->remoteProcId) {
        /* Log_error() */
        Log_print3(Diags_USER8,
            "Error: %s, line %d: %s: MultiProc_getId() returned INVALID",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN);
        status = -1;
        goto leave;
    }

    /* create sync object used to wait on shutdown event */
    SemThread_Params_init(&semThreadP);
    SemThread_construct(&gSemObj, 0, &semThreadP, &eb);

    if (Error_check(&eb)) {
        /* Log_error() */
        Log_print3(Diags_USER8,
            "Error: %s, line %d: %s: SemThread_construct() failed",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN);
        status = -1;
        goto leave;
    }
    gSemH = SemThread_handle(&gSemObj);

    /* register notify callback for shutdown event from remote core */
    status = Notify_registerEvent(state->remoteProcId, Global_NotifyLineId,
        Global_HostDspEvtNum, App_notifyCB__P, (UArg)NULL);

    if (status < 0) {
        /* Log_error() */
        Log_print4(Diags_USER8,
            "Error: %s, line %d: %s: "
            "Notify_registerEventSingle() returned error %d",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN, (IArg)status);
        goto leave;
    }

    /* create the tiler daemon */
    Log_print1(Diags_USER1,
        FXNN": MemMgr_createDaemon(name: %s)", (IArg)ti_sdo_tiler_Settings_tilerDaemonName);

    gTilerDaemonH = MemMgr_createDaemon(ti_sdo_tiler_Settings_tilerDaemonName);

    if (gTilerDaemonH == NULL) {
        /* Log_error() */
        Log_print3(Diags_USER8,
            "Error: %s, line %d: %s:  MemMgr_createDaemon() failed",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN);
        goto leave;
    }


leave:
    Log_print2(Diags_EXIT, "<-- %s: %d", (IArg)FXNN, (IArg)status);
    return(status);
}
#undef FXNN


/*
 *  ======== App_exec ========
 */
#define FXNN "App_exec"
Int App_exec(Ptr arg)
{
    Error_Block eb;
//  App_State *state = (App_State *)arg;
    Int status = 0;


    Log_print2(Diags_ENTRY, "--> %s: (arg: 0x%x)", (IArg)FXNN, (IArg)arg);

    Error_init(&eb);

    /* wait for shutdown event */
    SemThread_pend(gSemH, SemThread_FOREVER, &eb);

    Log_print2(Diags_EXIT, "<-- %s: %d", (IArg)FXNN, (IArg)status);
    return(status);
}
#undef FXNN


/*
 *  ======== App_shutdown ========
 */
#define FXNN "App_shutdown"
Int App_shutdown(Ptr arg)
{
    App_State *state = (App_State *)arg;
    Int status = 0;


    Log_print2(Diags_ENTRY, "--> %s: (arg: 0x%x)", (IArg)FXNN, (IArg)arg);

    /* delete the tiler daemon */
    Log_print0(Diags_USER1, FXNN": MemMgr_deleteDaemon()");

    MemMgr_deleteDaemon(&gTilerDaemonH);

    /* unregister notify callback */
    status = Notify_unregisterEvent(state->remoteProcId, Global_NotifyLineId,
        Global_HostDspEvtNum, App_notifyCB__P, (UArg)NULL);

    if (status < 0) {
        /* Log_error() */
        Log_print4(Diags_USER8,
            "Error: %s, line %d: %s: "
            "Notify_unregisterEvent() returned error %d",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN, (IArg)status);
        goto leave;
    }

    /* delete sync object */
    if (gSemH != NULL) {
        SemThread_destruct(&gSemObj);
        gSemH = NULL;
    }


leave:
    Log_print2(Diags_EXIT, "<-- %s: %d", (IArg)FXNN, (IArg)status);
    return(status);
}
#undef FXNN


/*
 *  ======== App_notifyCB__P ========
 */
#define FXNN "App_notifyCB__P"
Void App_notifyCB__P(UInt16 procId, UInt16 lineId, UInt32 eventNum,
        UArg arg, UInt32 payload)
{
    Error_Block eb;


    Log_print4(Diags_ENTRY,
        "--> %s: (procId: %d, eventNum: %d, payload: 0x%x)",
        (IArg)FXNN, (IArg)procId, (IArg)eventNum, (IArg)payload);

    Error_init(&eb);

    switch (Global_EvtMask & payload) {

        case Global_EvtAppShutdown:

            SemThread_post(gSemH, &eb);

            if (Error_check(&eb)) {
                /* Log_error() */
                Log_print3(
                    Diags_USER8,
                    "Error: %s, line %d: %s: SemThread_post() returned error",
                    (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN);
            }
            break;
    }

    Log_print1(Diags_EXIT, "<-- %s:", (IArg)FXNN);
}
#undef FXNN
/*
 *  @(#) ti.sdo.tiler.examples.remote; 1, 0, 0,4; 2-22-2012 18:10:55; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

