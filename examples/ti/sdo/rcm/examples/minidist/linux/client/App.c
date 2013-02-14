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
 *  ======== App.c ========
 *
 */

/* this define must precede inclusion of any xdc header file */
#define Registry_CURDESC App__Desc
#define MODULE_NAME "App"

/* standard include files */
// #include <stdio.h>

/* xdctools header files */
#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Registry.h>

/* package header files */
#include <ti/sdo/rcm/RcmClient.h>
#include <ti/sdo/rcm/examples/appcfg/App.h>

/* shared header file with server */
#include <ti/sdo/rcm/examples/minidist/linux/server/Global.h>

/* local header files */
#include "AppObject.h"

/* private constants and types */
#define LED_OFF 0
#define LED_ON 1

/* private functions */
static Int App_createRcmClient_P(RcmClient_Handle *rcmH);
static Int App_mainLoop_P(RcmClient_Handle rcmH);

static Int App_ledCtrl_P(
        RcmClient_Handle        rcmH,
        UInt16                  ledIdx,
        Int                     state,
        Int *                   ledStatus
    );


/* private data */
static Int curInit = 0;
Registry_Desc Registry_CURDESC; /* module diags mask */
struct App_Object_tag App_Object_V;

/* RcmServer message function index */
static UInt32 LED_on_Idx;
static UInt32 LED_off_Idx;


/*
 *  ======== App_init ========
 */
Void App_init(Void)
{
    Registry_Result     result;
    App_Object *        app;


    if (curInit++ != 0) {
        return;  /* already initialized */
    }

    /* register with xdc.runtime to get a diags mask */
    result = Registry_addModule(&Registry_CURDESC, MODULE_NAME);
    Assert_isTrue(result == Registry_SUCCESS, (Assert_Id)NULL);

    /* set the default diags mask for this module */
    Diags_setMask(MODULE_NAME"+F");

    /* initialize other modules */
    RcmClient_init();

    /* initialize application object */
    app = &App_Object_V;
    app->remoteProcName = NULL;  /* set in main_host_HLOS.c */
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

    RcmClient_exit();

    /* unregister from xdc.runtime */
//  result = Registry_removeModule(MODULE_NAME);
//  Assert_isTrue(result == Registry_SUCCESS, (Assert_Id)NULL);
}


/*
 *  ======== App_exec ========
 */
#define FXNN "App_exec"
Int App_exec(App_Object *app)
{
    Int                 status = 0;
    RcmClient_Handle    rcmH = NULL;


    Log_print1(Diags_ENTRY, "--> "FXNN": (app=0x%x)", (IArg)app);

    /* create the rcm client instance */
    status = App_createRcmClient_P(&rcmH);

    if (status < 0) {
        Log_error0(FXNN": RcmClient create failed, App_exec() aborting");
        goto leave;
    }

    /* the application main loop */
    status = App_mainLoop_P(rcmH);

    if (status < 0) {
        goto leave;
    }


leave:
    /* delete the rcm client instance */
    if (rcmH != NULL) {
        Log_print0(Diags_INFO, FXNN": RcmClient_delete: (...)");
        RcmClient_delete(&rcmH);
    }

    Log_print1(Diags_EXIT, "<-- "FXNN": %d", (IArg)status);
    return(status);
}
#undef FXNN


/*
 *  ======== App_startup ========
 */
#define FXNN "App_startup"
Int App_startup(App_Object *app)
{
    Int status = 0;


    Log_print1(Diags_ENTRY, "--> "FXNN": (app: 0x%x)", (IArg)app);

    /* add code here */

    Log_print1(Diags_EXIT, "<-- "FXNN": %d", (IArg)status);
    return(status);
}
#undef FXNN


/*
 *  ======== App_shutdown ========
 */
#define FXNN "App_shutdown"
Int App_shutdown(App_Object *app)
{
    Int status = 0;


    Log_print1(Diags_ENTRY, "--> "FXNN": (app: 0x%x)", (IArg)app);

    /* add code here */

    Log_print1(Diags_EXIT, "<-- "FXNN": %d", (IArg)status);
    return(status);
}
#undef FXNN


/*
 *  ======== App_mainLoop_P ========
 */
#define FXNN "App_mainLoop_P"
Int App_mainLoop_P(RcmClient_Handle rcmH)
{
    Int         status = 0;
    Int         ledStat;


    Log_print2(Diags_ENTRY, "--> %s: (rcmH: 0x%x)", (IArg)FXNN, (IArg)rcmH);

    /* turn on led #2 */
    status = App_ledCtrl_P(rcmH, 2, LED_ON, &ledStat);

    if (status < 0) {
        goto leave;
    }
    else if (ledStat != 0x4) {
        /* Log_error() */
        Log_print5(Diags_USER8,
            "Error: %s, line %d: %s: "
            "incorrect LED status: 0x%x, should be 0x%x",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN,
            (IArg)ledStat, (IArg)0x4);
        status = -1;
        goto leave;
    }
    else {
        Log_print2(Diags_INFO,
            "%s: LED status: 0x%x (ref: 0x4)", (IArg)FXNN, (IArg)ledStat);
    }

    /* turn on led #4 */
    status = App_ledCtrl_P(rcmH, 4, LED_ON, &ledStat);

    if (status < 0) {
        goto leave;
    }
    else if (ledStat != 0x14) {
        /* Log_error() */
        Log_print5(Diags_USER8,
            "Error: %s, line %d: %s: "
            "incorrect LED status: 0x%x, should be 0x%x",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN,
            (IArg)ledStat, (IArg)0x14);
        status = -1;
        goto leave;
    }
    else {
        Log_print2(Diags_INFO,
            "%s: LED status: 0x%x (ref: 0x14)", (IArg)FXNN, (IArg)ledStat);
    }

    /* turn on led #6 */
    status = App_ledCtrl_P(rcmH, 6, LED_ON, &ledStat);

    if (status < 0) {
        goto leave;
    }
    else if (ledStat != 0x54) {
        /* Log_error() */
        Log_print5(Diags_USER8,
            "Error: %s, line %d: %s: "
            "incorrect LED status: 0x%x, should be 0x%x",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN,
            (IArg)ledStat, (IArg)0x54);
        status = -1;
        goto leave;
    }
    else {
        Log_print2(Diags_INFO,
            "%s: LED status: 0x%x (ref: 0x54)", (IArg)FXNN, (IArg)ledStat);
    }

    /* turn off led #4 */
    status = App_ledCtrl_P(rcmH, 4, LED_OFF, &ledStat);

    if (status < 0) {
        goto leave;
    }
    else if (ledStat != 0x44) {
        /* Log_error() */
        Log_print5(Diags_USER8,
            "Error: %s, line %d: %s: "
            "incorrect LED status: 0x%x, should be 0x%x",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN,
            (IArg)ledStat, (IArg)0x44);
        status = -1;
        goto leave;
    }
    else {
        Log_print2(Diags_INFO,
            "%s: LED status: 0x%x (ref: 0x44)", (IArg)FXNN, (IArg)ledStat);
    }

leave:
    Log_print2(Diags_EXIT, "<-- %s: %d", (IArg)FXNN, (IArg)status);
    return(status);
}
#undef FXNN


/*
 *  ======== App_createRcmClient_P ========
 */
#define FXNN "App_createRcmClient_P"
Int App_createRcmClient_P(RcmClient_Handle *rcmPtrH)
{
    Int                 status = 0;
    Int                 count = 0;
    RcmClient_Params    rcmP;
    RcmClient_Handle    rcmH = NULL;


    Log_print1(Diags_ENTRY, "--> %s:", (IArg)FXNN);

    /* create an rcm client instance */
    RcmClient_Params_init(&rcmP);
    rcmP.heapId = Global_RcmClientHeapId;

    /* retry in case the slave is still booting */
    do {
        status = RcmClient_create(Global_RcmServerName, &rcmP, &rcmH);

        if (status < 0) {
            if (RcmClient_E_SERVERNOTFOUND != status) {
                /* Log_error() */
                Log_print2(Diags_USER8, 
                    "Error: %s, line %d: RcmClient_create() failed",
                    (IArg)__FILE__, (IArg)__LINE__);
                goto leave;
            }
        }
    } while ((++count < 32) && (rcmH == NULL));

    if (status < 0) {
        /* Log_error() */
        Log_print4(Diags_USER8,
            "Error: %s, line %d: %s: RcmServer not found after %d tries",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN, (IArg)count);
        goto leave;
    }
    else {
        Log_print2(Diags_INFO,
            "%s: RcmClient created on try %d", (IArg)FXNN, (IArg)count);
    }

    /* query for the remote message function indexes */
    status = RcmClient_getSymbolIndex(rcmH, "LED_on", &LED_on_Idx);

    if (status < 0) {
        /* Log_error() */
        Log_print3(Diags_USER8,
            "Error: %s, line %d: %s: LED_on() index not found",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN);
        goto leave;
    }
    Log_print2(Diags_INFO,
        "%s: LED_on() fxnIdx: 0x%x", (IArg)FXNN, (IArg)LED_on_Idx);

    status = RcmClient_getSymbolIndex(rcmH, "LED_off", &LED_off_Idx);

    if (status < 0) {
        /* Log_error() */
        Log_print3(Diags_USER8,
            "Error: %s, line %d: %s: LED_off() index not found",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN);
        goto leave;
    }
    Log_print2(Diags_INFO,
        "%s: LED_off() fxnIdx: 0x%x", (IArg)FXNN, (IArg)LED_off_Idx);


leave:
    if ((status < 0) && (rcmH != NULL)) {
        if (RcmClient_delete(&rcmH) < 0) {
            /* Log_error() */
            Log_print3(Diags_USER8,
                "Error: %s, line %d: %s: RcmClient_delete() failed",
                (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN);
        }
    }
    if (status < 0 ) {
        *rcmPtrH = NULL;
    }
    else {
        *rcmPtrH = rcmH;
        status = 0;
    }
    Log_print2(Diags_EXIT, "<-- %s: %d", (IArg)FXNN, (IArg)status);
    return(status);
}
#undef FXNN


/*
 *  ======== App_ledCtrl_P ========
 *
 *  Message payload semantics w.r.t. RcmClient message function
 *  ------------------------------------------------------------ 
 *  out data[0] Int     led status
 *  in  data[1] Int     led index
 */
#define FXNN "App_ledCtrl_P"
Int App_ledCtrl_P(RcmClient_Handle rcmH, UInt16 ledIdx, Int state,
        Int *ledStat)
{
    Int                 status = 0;
    UInt32              size;
    RcmClient_Message * msg;


    Log_print3(Diags_ENTRY,
        "--> %s: (index: %d, state: %s)",
        (IArg)FXNN, (IArg)ledIdx, (IArg)(state == 0 ? "OFF" : "ON"));

    /* allocate a remote command message */
    size = sizeof(RcmClient_Message) + sizeof(UInt32[2]);
    status = RcmClient_alloc(rcmH, size, &msg);

    if (status < 0) {
        msg = NULL;
        /* Log_error() */
        Log_print4(Diags_USER8,
            "Error: %s, line %d: %s: RcmClient_alloc() failed, %d",
            (IArg)FXNN, (IArg)__FILE__, (IArg)__LINE__, (IArg)status);
        goto leave;
    }

    /* fill in the remote command message */
    msg->fxnIdx = (state == LED_OFF ? LED_off_Idx : LED_on_Idx);
    msg->data[0] = (UInt32)0xFFFFFFFF;
    msg->data[1] = (UInt32)ledIdx;

    /* execute the remote command message */
    status = RcmClient_exec(rcmH, msg, &msg);

    switch (status) {
        case RcmClient_S_SUCCESS:
            Log_print1(Diags_INFO, "%s: RcmClient_exec completed", (IArg)FXNN);
            break;

        case RcmClient_E_MSGFXNERROR:
            // Decode library function error.
            status = (Int)(msg->data[0]);

            if (status == -1) {
                /* Log_error() */
                Log_print4(Diags_USER8,
                    "Error: %s, line %d: %s: invalid led index, %d",
                    (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN, (IArg)ledIdx);
            }
            else {
                /* Log_error() */
                Log_print4(Diags_USER8,
                    "Error: %s, line %d: %s: RCM msg fxn returned error %d",
                    (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN, (IArg)status);
            }
            goto leave;

        default:
            /* Log_error() */
            Log_print4(Diags_USER8,
                "Error: %s, line %d: %s: RcmClient_exec() returned error %d",
                (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN, (IArg)status);
            goto leave;
    }

    /* unmarshal return value */
    *ledStat = (Int)(msg->data[0]);


leave:
    /* return message to the heap */
    if (msg != NULL) {
        RcmClient_free(rcmH, msg);
        msg = NULL;
    }

    Log_print2(Diags_EXIT, "<-- %s: %d", (IArg)FXNN, (IArg)status);
    return(status);
}
#undef FXNN
/*
 *  @(#) ti.sdo.rcm.examples.minidist.linux.client; 1,0,0,4; 2-22-2012 18:10:10; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

