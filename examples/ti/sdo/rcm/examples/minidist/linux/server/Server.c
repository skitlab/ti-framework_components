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
 *  ======== Server.c ========
 *
 */

/* this define must precede inclusion of any xdc header file */
#define Registry_CURDESC App__Desc
#define MODULE_NAME "App"


/* xdctools header files */
#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Registry.h>
#include <xdc/runtime/knl/SemThread.h>

/* package header files */
#include <ti/ipc/MultiProc.h>
#include <ti/ipc/Notify.h>
#include <ti/sdo/rcm/RcmServer.h>
#include <ti/sdo/rcm/examples/appcfg/App.h>

/* local header files */
#include "AppObject.h"
#include "Global.h"

/* private functions */
static Int32 LED_on(UInt32 dataSize, UInt32 *data);
static Int32 LED_off(UInt32 dataSize, UInt32 *data);

#if 0
static
Void App_notifyCB_P(
        UInt16          procId,
        UInt16          lineId,
        UInt32          eventNum,
        UArg            arg,
        UInt32          payload
    );
#endif


/* private data */
static Int curInit = 0;
Registry_Desc Registry_CURDESC; /* module diags mask */
struct App_Object_tag App_Object_V;
static UInt16 ledState = 0;

static RcmServer_FxnDesc serverFxnAry[] = {
    { "LED_on",         LED_on },
    { "LED_off",        LED_off }
};

#define serverFxnAryLen (sizeof serverFxnAry / sizeof serverFxnAry[0])

static const RcmServer_FxnDescAry Server_fxnTab = {
    serverFxnAryLen,
    serverFxnAry
};

static RcmServer_Handle rcmServerH = NULL;
// static SemThread_Struct shutdownSemObj;
// static SemThread_Handle shutdownSemH = NULL;


/*
 *  ======== App_init ========
 */
Void App_init(Void)
{
    Registry_Result     result;
    App_Object *        appObj;


    if (curInit++ != 0) {
        return;  /* already initialized */
    }

    /* register with xdc.runtime to get a diags mask */
    result = Registry_addModule(&Registry_CURDESC, MODULE_NAME);
    Assert_isTrue(result == Registry_SUCCESS, (Assert_Id)NULL);

    /* initialize other modules */
    RcmServer_init();

    /* initialize application object */
    appObj = &App_Object_V;
    appObj->hostProcName = Global_HostProcName;
    appObj->hostProcId = MultiProc_getId(appObj->hostProcName);
}


/*
 *  ======== App_exit ========
 */
Void App_exit(Void)
{
//  Registry_Result result;


    if (curInit-- != 1) {
        return;  /* object still being used */
    }

    RcmServer_exit();

    /* unregister from xdc.runtime */
//  result = Registry_removeModule(MODULE_NAME);
//  Assert_isTrue(result == Registry_SUCCESS, (Assert_Id)NULL);
}


#if 0
/*
 *  ======== App_exec ========
 */
#define FXNN "App_exec"
Int App_exec(App_Object *app)
{
    Error_Block eb;
    Int status = 0;


    Log_print1(Diags_ENTRY, "--> "FXNN": (app: 0x%x)", (IArg)app);

    Error_init(&eb);

    /* wait for shutdown event */
    Log_print0(Diags_INFO, FXNN": waiting for shutdown event...");

    SemThread_pend(shutdownSemH, SemThread_FOREVER, &eb);

    if (Error_check(&eb)) {
        Log_error0(FXNN": SemThread_pend() returned with error");
        status = -1;
        goto leave;
    }
    Log_print0(Diags_INFO, FXNN": ...received shutdown event");


leave:
    Log_print1(Diags_EXIT, "<-- "FXNN": %d", (IArg)status);
    return(status);
}
#undef FXNN
#endif


/*
 *  ======== App_startup ========
 */
#define FXNN "App_startup"
Int App_startup(App_Object *appObj)
{
    Error_Block eb;
    RcmServer_Params rcmServerP;
//  SemThread_Params semThreadP;
    Int status = 0;


    Log_print1(Diags_ENTRY | Diags_INFO,
        "--> "FXNN": (appObj=0x%x)", (IArg)appObj);

    Error_init(&eb);

#if 0
    /* create the shutdown semaphore */
    SemThread_Params_init(&semThreadP);
    SemThread_construct(&shutdownSemObj, 0, &semThreadP, &eb);

    if (Error_check(&eb)) {
        Log_error0(FXNN": SemThread_construct() failed");
        status = -1;
        goto leave;
    }
    shutdownSemH = SemThread_handle(&shutdownSemObj);

    /* translate remote proc name into proc id */
    appObj->hostProcId = MultiProc_getId(appObj->hostProcName);

    if (MultiProc_INVALIDID == appObj->remoteProcId) {
        Log_error0(FXNN": MultiProc_getId() returned INVALID");
        status = -1;
        goto leave;
    }

    /* register notify callback for shutdown event from remote core */
    status = Notify_registerEvent(appObj->remoteProcId, Global_NotifyLineId,
        Global_HostDspEvtNum, App_notifyCB_P, (UArg)NULL);

    if (status < 0) {
        Log_error1(FXNN": Notify_registerEventSingle() returned error %d",
            (IArg)status);
        goto leave;
    }
#endif

    /* initialize RcmServer create params */
    RcmServer_Params_init(&rcmServerP);
    rcmServerP.fxns.length = Server_fxnTab.length;
    rcmServerP.fxns.elem = Server_fxnTab.elem;

    /* create the RcmServer instance */
    status = RcmServer_create(Global_RcmServerName, &rcmServerP, &rcmServerH);

    if (status < 0) {
        Log_error1(FXNN": RcmServer_create() returned error %d", (IArg)status);
        goto leave;
    }

    /* start the server */
    RcmServer_start(rcmServerH);


leave:
    Log_print1(Diags_EXIT, "<-- "FXNN": %d", (IArg)status);
    return(status);
}
#undef FXNN


/*
 *  ======== App_shutdown ========
 */
#define FXNN "App_shutdown"
Int App_shutdown(App_Object *appObj)
{
    Int status = 0;


    Log_print1(Diags_ENTRY | Diags_INFO, "--> "FXNN": (appObj: 0x%x)", (IArg)appObj);

    /* delete RcmServer instance */
    status = RcmServer_delete(&rcmServerH);

    if (status < 0) {
        Log_error1(FXNN": RcmServer_delete() returned error %d", (IArg)status);
        status = -1;
        goto leave;
    }

#if 0
    /* unregister notify callback */
    status = Notify_unregisterEvent(appObj->remoteProcId, Global_NotifyLineId,
        Global_HostDspEvtNum, App_notifyCB_P, (UArg)NULL);

    if (status < 0) {
        Log_error1(FXNN": Notify_unregisterEvent() returned error %d",
            (IArg)status);
        goto leave;
    }

    /* delete sync object */
    if (shutdownSemH != NULL) {
        SemThread_destruct(&shutdownSemObj);
        shutdownSemH = NULL;
    }
#endif


leave:
    Log_print1(Diags_EXIT, "<-- "FXNN": %d", (IArg)status);
    return(status);
}
#undef FXNN


#if 0
/*
 *  ======== App_notifyCB_P ========
 */
#define FXNN "App_notifyCB_P"
Void App_notifyCB_P(UInt16 procId, UInt16 lineId, UInt32 eventNum,
        UArg arg, UInt32 payload)
{
    Error_Block eb;


    Log_print3(Diags_ENTRY,
        "--> "FXNN": (procId=%d, eventNum=%d, payload=0x%x)",
        (IArg)procId, (IArg)eventNum, (IArg)payload);

    Error_init(&eb);

    switch (Global_EvtMask & payload) {

        case Global_EvtAppShutdown:

            SemThread_post(shutdownSemH, &eb);

            if (Error_check(&eb)) {
                Log_error0(FXNN": SemThread_post() returned error");
            }
            break;
    }

    Log_print0(Diags_EXIT, "<-- "FXNN":");
}
#undef FXNN
#endif


/*
 *  ======== LED_on ========
 *
 *  data[0] out Int     led status
 *  data[1] in  Int     led index
 */
#define FXNN "LED_on"
Int32 LED_on(UInt32 dataSize, UInt32 *data)
{
    Int ledIdx;
    Int32 status = 0;

    Log_print2(Diags_ENTRY,
        "--> "FXNN": (dataSize: %d, data: 0x%x)", (IArg)dataSize, (IArg)data);

    /* unmarshal agruments */
    ledIdx = (Int)(data[1]);  /* led index */

    /* validate led index */
    if (! ((0 <= ledIdx) && (ledIdx <= 15))) {
        Log_error1(FXNN": invalid LED index %d", (IArg)ledIdx);
        status = -1;
        goto leave;
    }

    Log_print1(Diags_INFO, FXNN": LED# %d, ON", (IArg)ledIdx);

    /* update led state */
    ledState |= (1 << ledIdx);

    /* marshal return value */
    data[0] = (UInt32)ledState;

leave:
    Log_print1(Diags_EXIT, "<-- "FXNN": %d", (IArg)status);
    return(status);
}
#undef FXNN


/*
 *  ======== LED_off ========
 *
 *  data[0] out Int     led status
 *  data[1] in  Int     led index
 */
#define FXNN "LED_off"
Int32 LED_off(UInt32 dataSize, UInt32 *data)
{
    Int ledIdx;
    Int32 status = 0;

    Log_print2(Diags_ENTRY,
        "--> "FXNN": (dataSize: %d, data: 0x%x)", (IArg)dataSize, (IArg)data);

    /* unmarshal agruments */
    ledIdx = (Int)(data[1]);  /* led index */

    /* validate led index */
    if (! ((0 <= ledIdx) && (ledIdx <= 15))) {
        Log_error1(FXNN": invalid LED index %d", (IArg)ledIdx);
        status = -1;
        goto leave;
    }

    Log_print1(Diags_INFO, FXNN": LED# %d, OFF", (IArg)ledIdx);

    /* update led state */
    ledState &= (UInt16)(~(1 << ledIdx));

    /* marshal return value */
    data[0] = (UInt32)ledState;

leave:
    Log_print1(Diags_EXIT, "<-- "FXNN": %d", (IArg)status);
    return(status);
}
#undef FXNN
/*
 *  @(#) ti.sdo.rcm.examples.minidist.linux.server; 1,0,0,4; 2-22-2012 18:10:25; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

