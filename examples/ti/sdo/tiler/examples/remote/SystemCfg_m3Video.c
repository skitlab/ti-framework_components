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
 *  ======== SystemCfg_m3Video.c ========
 *
 */

/* xdctools header files */
#include <xdc/std.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/knl/SemThread.h>
#include <xdc/runtime/knl/Thread.h>

/* ipc header files */
#include <ti/ipc/HeapBufMP.h>
#include <ti/ipc/Ipc.h>
#include <ti/ipc/MessageQ.h>
#include <ti/ipc/MultiProc.h>
#include <ti/ipc/Notify.h>

/* package header files */
#include <ti/sdo/rcm/RcmClient.h>

/* local header files */
#include "SystemCfg.h"

/* private constants and types */

/* private functions */
static
Void SystemCfg_notifyCB__P(
        UInt16          procId,
        UInt16          lineId,
        UInt32          eventNum,
        UArg            arg,
        UInt32          payload
    );

/* private data */
static struct SystemCfg {
    HeapBufMP_Handle    heapH;
    SemThread_Struct    semObj;
    SemThread_Handle    semH;
    UInt16              hostProcId;
} SystemCfg_State;

static Int curInit = 0;


/*
 *  ======== SystemCfg_init ========
 */
Void SystemCfg_init(Void)
{
    struct SystemCfg *stateObj = &SystemCfg_State;

    if (curInit++ != 0) {
        return;  /* already initialized */
    }

    RcmClient_init();
//  Diags_setMask("ti.sdo.rcm.RcmClient+EXF");

    stateObj->heapH = NULL;
    stateObj->semH = NULL;
    stateObj->hostProcId = MultiProc_INVALIDID;
}


/*
 *  ======== SystemCfg_exit ========
 */
Void SystemCfg_exit(Void)
{

    if (curInit-- != 1) {
        return;  /* object still being used */
    }

    RcmClient_exit();
}


/*
 *  ======== SystemCfg_startAck ========
 */
#define FXNN "SystemCfg_startAck"
Int SystemCfg_startAck(Void)
{
    Int count;
    Int status = 0;
    struct SystemCfg *stateObj = &SystemCfg_State;


    Log_print1(Diags_ENTRY, "--> %s: ()", (IArg)FXNN);

    /* initialize the transport between DSP (local) <---> HOST (remote) */
    stateObj->hostProcId = MultiProc_getId("HOST");

    Log_print1(Diags_USER1,
        FXNN": Ipc_attach(hostProcId: %d)", (IArg)stateObj->hostProcId);

    /* connect to remote processor */
    count = 0;
    do {
        status = Ipc_attach(stateObj->hostProcId);
        /* TODO should delay on failure */
    } while ((++count < 500) && (status < 0));

    if (status < 0) {
        /* Log_error() */
        Log_print4(Diags_USER8,
            "Error: %s, line %d: %s:"
            "Ipc_attach() failed to connect after %d tries",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN, (IArg)count);
        goto leave;
    }
    Log_print1(Diags_USER1,
        FXNN": Ipc_attach completed on try %d", (IArg)count);


leave:
    status = (status >= 0 ? 0 : status);
    Log_print2(Diags_EXIT, "<-- %s: %d", (IArg)FXNN, (IArg)status);
    return(status);
}
#undef FXNN


/*
 *  ======== SystemCfg_createLocalResources ========
 */
#define FXNN "SystemCfg_createLocalResources"
Int SystemCfg_createLocalResources(Void)
{
    Error_Block eb;
    SemThread_Params semThreadP;
    HeapBufMP_Params heapBufMPP;
    Int count;
    Char heapName[32];
    Int status = 0;
    struct SystemCfg *stateObj = &SystemCfg_State;
    static Int heapId = 1;


    Log_print1(Diags_ENTRY, "--> %s: ()", (IArg)FXNN);

    Error_init(&eb);

    /* create sync object used to wait on remote core startup */
    SemThread_Params_init(&semThreadP);
    semThreadP.mode = SemThread_Mode_COUNTING;
    SemThread_construct(&stateObj->semObj, 0, &semThreadP, &eb);

    if (Error_check(&eb)) {
        /* Log_error() */
        Log_print3(Diags_USER8,
            "Error: %s, line %d: %s: SemThread_construct() failed",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN);
        status = -1;
        goto leave;
    }
    stateObj->semH = SemThread_handle(&stateObj->semObj);

    /* register notify callback for ready event from remote core */
    status = Notify_registerEvent(stateObj->hostProcId, Global_NotifyLineId,
        Global_HostDspEvtNum, SystemCfg_notifyCB__P, (UArg)stateObj);

    if (status < 0) {
        /* Log_error() */
        Log_print4(Diags_USER8,
            "Error: %s, line %d: %s: "
            "Notify_registerEventSingle() returned error %d",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN, (IArg)status);
        goto leave;
    }

    /* create a heap for tiler usage */
    Log_print0(Diags_USER2, FXNN": HeapBufMP_create for tiler");

    HeapBufMP_Params_init(&heapBufMPP);
    heapBufMPP.regionId = 0;
    heapBufMPP.blockSize = 0x200;  /* 512 B */
    heapBufMPP.numBlocks = 8;

    /* hack: make a unique heap name */
    System_sprintf(heapName, "rcmHeap-%d", heapId);
    heapBufMPP.name = heapName;

    stateObj->heapH = HeapBufMP_create(&heapBufMPP);

    if (stateObj->heapH == NULL) {
        /* Log_error() */
        Log_print3(Diags_USER8,
            "Error: %s, line %d: %s: HeapBuf_create() failed",
            (IArg)FXNN, (IArg)__FILE__, (IArg)__LINE__);
        status = -1;
        goto leave;
    }

    /* register this heap with MessageQ */
    Log_print2(Diags_USER2,
        FXNN": MessageQ_registerHeap: (heapH: 0x%x, heapId: %d)",
        (IArg)(stateObj->heapH), (IArg)Global_TilerHeapId);

    MessageQ_registerHeap((Ptr)(stateObj->heapH), Global_TilerHeapId);


    /*  Send create done event to remote core. Need to loop in case
     *  the remote core has not yet registered with notify to receive
     *  this event.
     */
    Log_print0(Diags_USER1, FXNN": send EvtCreateDone to remote core");

    count = 0;
    do {
        status = Notify_sendEvent(stateObj->hostProcId, Global_NotifyLineId,
            Global_HostDspEvtNum, Global_EvtCreateDone, TRUE);

        if (status == Notify_E_EVTNOTREGISTERED) {
            Thread_sleep(500, &eb); /* 0.5 ms */
        }
    } while ((++count < 10) && (status == Notify_E_EVTNOTREGISTERED));

    if (status < 0) {
        /* Log_error() */
        Log_print5(Diags_USER8,
            "Error: %s, line %d: %s: Notify_sendEvent() returned error %d,"
            "giving up after %d tries", (IArg)__FILE__, (IArg)__LINE__,
            (IArg)FXNN, (IArg)status, (IArg)count);
        goto leave;
    }

    /* wait for create done event from remote core */
    Log_print0(Diags_USER1, FXNN": waiting for EvtCreateDone event...");

    SemThread_pend(stateObj->semH, SemThread_FOREVER, &eb);

    if (Error_check(&eb)) {
        /* Log_error() */
        Log_print3(Diags_USER8,
            "Error: %s, line %d: %s:  SemThread_pend() returned with error",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN);
        status = -1;
        goto leave;
    }
    Log_print0(Diags_USER1, FXNN": ...received EvtCreatDone event");


leave:
    Log_print2(Diags_EXIT, "<-- %s: %d", (IArg)FXNN, (IArg)status);
    return(status);
}
#undef FXNN


/*
 *  ======== SystemCfg_deleteLocalResources ========
 */
#define FXNN "SystemCfg_deleteLocalResources"
Int SystemCfg_deleteLocalResources(Void)
{
    Error_Block eb;
    Int status = 0;
    struct SystemCfg *stateObj = &SystemCfg_State;


    Log_print1(Diags_ENTRY, "--> %s: ()", (IArg)FXNN);

    Error_init(&eb);

    /* unregister heap with MessageQ */
    MessageQ_unregisterHeap(Global_TilerHeapId);

    /* delete heap used for rcm message queue */
    HeapBufMP_delete(&stateObj->heapH);

    /* send done event to remote core */
    Log_print0(Diags_USER1, FXNN": send done event to remote core");

    status = Notify_sendEvent(stateObj->hostProcId, Global_NotifyLineId,
        Global_HostDspEvtNum, Global_EvtDone, TRUE);

    if (status < 0) {
        /* Log_error() */
        Log_print4(Diags_USER8,
            "Error: %s, line %d: %s: Notify_sendEvent() returned error %d",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN, (IArg)status);
        goto leave;
    }

    /* wait for done event from remote core */
    Log_print0(Diags_USER1, FXNN": waiting for done event...");

    SemThread_pend(stateObj->semH, SemThread_FOREVER, &eb);

    if (Error_check(&eb)) {
        /* Log_error() */
        Log_print3(Diags_USER8,
            "Error: %s, line %d: %s:  SemThread_pend() returned with error",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN);
        status = -1;
        goto leave;
    }
    Log_print0(Diags_USER1, FXNN": ...received done event");

    /* unregister notify callback */
    status = Notify_unregisterEvent(stateObj->hostProcId, Global_NotifyLineId,
        Global_HostDspEvtNum, SystemCfg_notifyCB__P, (UArg)stateObj);

    if (status < 0) {
        /* Log_error() */
        Log_print4(Diags_USER8,
            "Error: %s, line %d: %s: "
            "Notify_unregisterEventSingle() returned error %d",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN, (IArg)status);
        goto leave;
    }

    /* delete sync object */
    if (stateObj->semH != NULL) {
        SemThread_destruct(&stateObj->semObj);
        stateObj->semH = NULL;
    }

leave:
    Log_print2(Diags_EXIT, "<-- %s: %d", (IArg)FXNN, (IArg)status);
    return(status);
}
#undef FXNN


/*
 *  ======== SystemCfg_openSharedResources ========
 */
#define FXNN "SystemCfg_openSharedResources"
Int SystemCfg_openSharedResources(SystemCfg_AppFxn appStartupFxn, Ptr arg)
{
    Error_Block eb;
    Int status = 0;
    struct SystemCfg *stateObj = &SystemCfg_State;


    Log_print1(Diags_ENTRY, "--> %s: ()", (IArg)FXNN);

    Error_init(&eb);

    /* open shared resources from remote core */

    /* <add code here> */

    /* invoke the application startup function */
    if (appStartupFxn != NULL) {
        status = appStartupFxn(arg);

        if (status < 0) {
            goto leave;
        }
    }

    /* send ready event to remote core */
    Log_print0(Diags_USER1, FXNN": send EvtReady to remote core");

    status = Notify_sendEvent(stateObj->hostProcId, Global_NotifyLineId,
        Global_HostDspEvtNum, Global_EvtReady, TRUE);

    if (status < 0) {
        /* Log_error() */
        Log_print4(Diags_USER8,
            "Error: %s, line %d: %s: Notify_sendEvent() returned error %d",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN, (IArg)status);
        goto leave;
    }

    /* wait for ready event from remote core */
    Log_print0(Diags_USER1, FXNN": waiting for EvtReady event...");

    SemThread_pend(stateObj->semH, SemThread_FOREVER, &eb);

    if (Error_check(&eb)) {
        /* Log_error() */
        Log_print3(Diags_USER8,
            "Error: %s, line %d: %s:  SemThread_pend() returned with error",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN);
        status = -1;
        goto leave;
    }
    Log_print0(Diags_USER1, FXNN": ...received EvtReady event");


leave:
    Log_print2(Diags_EXIT, "<-- %s: %d", (IArg)FXNN, (IArg)status);
    return(status);
}
#undef FXNN


/*
 *  ======== SystemCfg_closeSharedResources ========
 */
#define FXNN "SystemCfg_closeSharedResources"
Int SystemCfg_closeSharedResources(SystemCfg_AppFxn appShutdownFxn, Ptr arg)
{
    Error_Block eb;
    Int status = 0;
    struct SystemCfg *stateObj = &SystemCfg_State;


    Log_print1(Diags_ENTRY, "--> %s: ()", (IArg)FXNN);

    Error_init(&eb);

    /* invoke the application shutdown function */
    if (appShutdownFxn != NULL) {
        status = appShutdownFxn(arg);

        if (status < 0) {
            goto leave;
        }
    }

    /* close shared resources from remote core */

    /* <add code here> */

    /* send close done event to remote core */
    Log_print0(Diags_USER1, FXNN": send EvtCloseDone to remote core");

    status = Notify_sendEvent(stateObj->hostProcId, Global_NotifyLineId,
        Global_HostDspEvtNum, Global_EvtCloseDone, TRUE);

    if (status < 0) {
        /* Log_error() */
        Log_print4(Diags_USER8,
            "Error: %s, line %d: %s: Notify_sendEvent() returned error %d",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN, (IArg)status);
        goto leave;
    }

    /* wait for close event from remote core */
    Log_print0(Diags_USER1, FXNN": waiting for EvtCloseDone event...");

    SemThread_pend(stateObj->semH, SemThread_FOREVER, &eb);

    if (Error_check(&eb)) {
        /* Log_error() */
        Log_print3(Diags_USER8,
            "Error: %s, line %d: %s:  SemThread_pend() returned with error",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN);
        status = -1;
        goto leave;
    }
    Log_print0(Diags_USER1, FXNN": ...received EvtCloseDone event");


leave:
    Log_print2(Diags_EXIT, "<-- %s: %d", (IArg)FXNN, (IArg)status);
    return(status);
}
#undef FXNN


/*
 *  ======== SystemCfg_notifyCB__P ========
 */
#define FXNN "SystemCfg_notifyCB__P"
Void SystemCfg_notifyCB__P(UInt16 procId, UInt16 lineId, UInt32 eventNum,
        UArg arg, UInt32 payload)
{
    Error_Block eb;
    struct SystemCfg *stateObj = (struct SystemCfg *)arg;


    Log_print4(Diags_ENTRY,
        "--> %s: (prodId: %d, eventNum: %d, payload: 0x%x)",
        (IArg)FXNN, (IArg)procId, (IArg)eventNum, (IArg)payload);

    Error_init(&eb);

    switch (Global_EvtMask & payload) {

        case Global_EvtCreateDone:
        case Global_EvtReady:
        case Global_EvtCloseDone:
        case Global_EvtDone:

            SemThread_post(stateObj->semH, &eb);

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

