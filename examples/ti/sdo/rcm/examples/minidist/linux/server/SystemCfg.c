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
 *  ======== SystemCfg.c ========
 *
 */

/* this define must precede inclusion of any xdc header file */
#define Registry_CURDESC SystemCfg__Desc
#define MODULE_NAME "SystemCfg"

/* standard include files */
#include <string.h>

/* xdctools header files */
#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Registry.h>
#include <xdc/runtime/knl/SemThread.h>
#include <xdc/runtime/knl/Thread.h>

/* package header files */
#include <ti/ipc/Ipc.h>
#include <ti/ipc/MultiProc.h>
#include <ti/ipc/Notify.h>
#include <ti/sdo/rcm/examples/appcfg/SystemCfg.h>

/* local header files */
#include "Global.h"

/* instance object */
typedef struct SystemCfg_Object_tag {
    String              remoteProcName;
    UInt16              remoteProcId;
    SemThread_Struct    semObj;
    SemThread_Handle    semH;
    SemThread_Struct    shutdownSemObj;
    SemThread_Handle    shutdownSemH;
} SystemCfg_Object;

/* private functions */
static Int SystemCfg_createLocalResources_P(SystemCfg_Object *sysCfg);
static Int SystemCfg_deleteLocalResources_P(SystemCfg_Object *sysCfg);
static Int SystemCfg_openSharedResources_P(SystemCfg_Object *sysCfg);
static Int SystemCfg_closeSharedResources_P(SystemCfg_Object *sysCfg);

static Void SystemCfg_notifyCB_P(
        UInt16          procId,
        UInt16          lineId,
        UInt32          eventNum,
        UArg            arg,
        UInt32          payload
    );

/* private data */
Registry_Desc Registry_CURDESC;
static Int curInit = 0;


/*
 *  ======== SystemCfg_init ========
 */
Void SystemCfg_init(Void)
{
    Registry_Result result;


    if (curInit++ != 0) {
        return;  /* already initialized */
    }

    /* register with xdc.runtime to get a diags mask */
    result = Registry_addModule(&Registry_CURDESC, MODULE_NAME);
    Assert_isTrue(result == Registry_SUCCESS, (Assert_Id)NULL);
}


/*
 *  ======== SystemCfg_exit ========
 */
Void SystemCfg_exit(Void)
{
//  Registry_Result result;


    if (curInit-- != 1) {
        return;  /* object still being used */
    }

    /* unregister from xdc.runtime */
//  result = Registry_removeModule(MODULE_NAME);
//  Assert_isTrue(result == Registry_SUCCESS, (Assert_Id)NULL);
}


/*
 *  ======== SystemCfg_Params_init ========
 */
Void SystemCfg_Params_init(SystemCfg_Params *params)
{
    params->remoteProcName = NULL;
}


/*
 *  ======== SystemCfg_create ========
 */
#define FXNN "SystemCfg_create"
Int SystemCfg_create(const SystemCfg_Params *params, SystemCfg_Handle *handleP)
{
    Int                 status, bufSize;
    Error_Block         eb;
    SystemCfg_Object *  obj;
    SemThread_Params    semThreadP;


    Log_print0(Diags_ENTRY, "--> "FXNN": ()");

    /* initialize local vars */
    status = 0;
    Error_init(&eb);
    *handleP = (SystemCfg_Handle)NULL;

    /* allocate the object */
    obj = (SystemCfg_Handle)xdc_runtime_Memory_calloc(NULL,
        sizeof(SystemCfg_Object), sizeof(Int), &eb);

    if (obj == NULL) {
        Log_error1(FXNN": out of memory: size=%u", sizeof(SystemCfg_Object));
        status = SystemCfg_E_NOMEMORY;
        goto leave;
    }

    /* object-specific initialization */
    obj->remoteProcName = NULL;
    obj->remoteProcId = MultiProc_INVALIDID;
    obj->semH = NULL;
    obj->shutdownSemH = NULL;
    
    /* initialize structures to zero */
    memset((Void *)&obj->semObj, 0, sizeof(SemThread_Struct));
    memset((Void *)&obj->shutdownSemObj, 0, sizeof(SemThread_Struct));

    /* store the remote processor name */
    bufSize = strlen(params->remoteProcName) + 1;
    obj->remoteProcName = (String)xdc_runtime_Memory_calloc(NULL,
        bufSize, sizeof(String), &eb);

    if (obj == NULL) {
        Log_error1(FXNN": out of memory: size=%u", bufSize);
        status = SystemCfg_E_NOMEMORY;
        goto leave;
    }

    strcpy(obj->remoteProcName, params->remoteProcName);

    /* lookup the remote processor id */
    obj->remoteProcId = MultiProc_getId(obj->remoteProcName);

    /* create sync object used for synchronizing with remote core */
    SemThread_Params_init(&semThreadP);
    semThreadP.mode = SemThread_Mode_COUNTING;
    SemThread_construct(&obj->semObj, 0, &semThreadP, &eb);

    if (Error_check(&eb)) {
        Log_error0(FXNN": SemThread_construct() failed");
        status = -1;
        goto leave;
    }
    obj->semH = SemThread_handle(&obj->semObj);

    /* create sync object used for shutdown signal */
    SemThread_Params_init(&semThreadP);
    semThreadP.mode = SemThread_Mode_BINARY;
    SemThread_construct(&obj->shutdownSemObj, 0, &semThreadP, &eb);

    if (Error_check(&eb)) {
        Log_error0(FXNN": SemThread_construct() failed");
        status = -1;
        goto leave;
    }
    obj->shutdownSemH = SemThread_handle(&obj->shutdownSemObj);

    /* success, return opaque pointer */
    *handleP = (SystemCfg_Handle)obj;


leave:
    Log_print1(Diags_EXIT, "<-- "FXNN": %d", (IArg)status);
    return(status);
}
#undef FXNN


/*
 *  ======== SystemCfg_delete ========
 */
#define FXNN "SystemCfg_delete"
Int SystemCfg_delete(SystemCfg_Object **objPtr)
{
    Int bufSize;


    Log_print0(Diags_ENTRY, "--> "FXNN": ()");

    /* free the name buffer */
    bufSize = strlen((*objPtr)->remoteProcName) + 1;
    xdc_runtime_Memory_free(NULL, (Ptr)((*objPtr)->remoteProcName), bufSize);

    /* free the object memory */
    xdc_runtime_Memory_free(NULL, (Ptr)(*objPtr), sizeof(SystemCfg_Object));
    *objPtr = NULL;

    Log_print1(Diags_EXIT, "<-- "FXNN": %d", (IArg)SystemCfg_S_SUCCESS);
    return(SystemCfg_S_SUCCESS);
}
#undef FXNN


/*
 *  ======== SystemCfg_attach ========
 */
#define FXNN "SystemCfg_attach"
Int SystemCfg_attach(SystemCfg_Object *obj)
{
    Int             status;
    Int             count;
    Error_Block     eb;


    Log_print0(Diags_ENTRY, "--> "FXNN": ()");

    /* initialize local vars */
    status = 0;
    Error_init(&eb);

    Log_print1(Diags_INFO,
        FXNN": Ipc_attach(remoteProcId=%d)", (IArg)obj->remoteProcId);

    /* connect to remote processor */
    count = 0;
    do {
        status = Ipc_attach(obj->remoteProcId);

        if (status < 0) {
            Thread_sleep(500, &eb); /* 0.5 ms */
            /* TODO: check error block */
        }
    } while ((++count < 500) && (status < 0));

    if (status < 0) {
        Log_error1(FXNN": Ipc_attach() failed to connect after %d tries",
            (IArg)count);
        goto leave;
    }
    Log_print1(Diags_INFO, FXNN": Ipc_attach completed on try %d", (IArg)count);


leave:
    Log_print1(Diags_EXIT, "<-- "FXNN": %d", (IArg)status);
    return(status);
}
#undef FXNN


/*
 *  ======== SystemCfg_detach ========
 */
#define FXNN "SystemCfg_detach"
Int SystemCfg_detach(SystemCfg_Object *obj)
{
    Int             status;
    Int             count;
    Error_Block     eb;


    Log_print0(Diags_ENTRY, "--> "FXNN": ()");

    /* initialize local vars */
    status = 0;
    Error_init(&eb);

    Log_print1(Diags_INFO,
        FXNN": Ipc_detach(remoteProcId=%d)", (IArg)obj->remoteProcId);

    /* connect to remote processor */
    count = 0;
    do {
        status = Ipc_detach(obj->remoteProcId);

        if (status < 0) {
            Thread_sleep(500, &eb); /* 0.5 ms */
            /* TODO: check error block */
        }
    } while ((++count < 500) && (status < 0));

    if (status < 0) {
        Log_error1(FXNN": Ipc_detach() failed to connect after %d tries",
            (IArg)count);
        goto leave;
    }
    Log_print1(Diags_INFO, FXNN": Ipc_detach completed on try %d", (IArg)count);


leave:
    Log_print1(Diags_EXIT, "<-- "FXNN": %d", (IArg)status);
    return(status);
}
#undef FXNN


/*
 *  ======== SystemCfg_initializeResources ========
 */
#define FXNN "SystemCfg_initializeResources"
Int SystemCfg_initializeResources(SystemCfg_Object *obj,
        App_Fxn appStartupFxn, App_Handle app)
{
    Int             status = 0;
    Int             count;
    Error_Block     eb;


    Log_print0(Diags_ENTRY, "--> "FXNN":");

    Error_init(&eb);

    /* register notify callback for ready event from remote core */
    status = Notify_registerEvent(obj->remoteProcId, Global_NotifyLineId,
        Global_HostDspEvtNum, SystemCfg_notifyCB_P, (UArg)obj);

    if (status < 0) {
        Log_error1(FXNN": Notify_registerEventSingle() returned error %d",
            (IArg)status);
        goto leave;
    }

    /* create local resources */
    status = SystemCfg_createLocalResources_P(obj);

    if (status < 0) {
        Log_error0(FXNN": SystemCfg_createLocalResources_P() failed");
        goto leave;
    }

    /*  Send create done event to remote core. Need to loop in case
     *  the remote core has not yet registered with notify to receive
     *  this event.
     */
    Log_print0(Diags_INFO, FXNN": send EvtCreateDone to remote core");

    count = 0;
    do {
        status = Notify_sendEvent(obj->remoteProcId, Global_NotifyLineId,
            Global_HostDspEvtNum, Global_EvtCreateDone, TRUE);

        if (status == Notify_E_EVTNOTREGISTERED) {
            Thread_sleep(500, &eb); /* 0.5 ms */
        }
    } while ((++count < 10) && (status == Notify_E_EVTNOTREGISTERED));

    if (status < 0) {
        Log_error2(FXNN": Notify_sendEvent() returned error %d,"
            "giving up after %d tries", (IArg)status, (IArg)count);
        goto leave;
    }

    /* wait for create done event from remote core */
    Log_print0(Diags_INFO, FXNN": waiting for EvtCreateDone event...");

    SemThread_pend(obj->semH, SemThread_FOREVER, &eb);

    if (Error_check(&eb)) {
        Log_error0(FXNN": SemThread_pend() returned with error");
        status = -1;
        goto leave;
    }
    Log_print0(Diags_INFO, FXNN": ...received EvtCreatDone event");

    /* open shared resources from remote core */
    status = SystemCfg_openSharedResources_P(obj);

    if (status < 0) {
        Log_error0(FXNN": SystemCfg_openSharedResources_P() failed");
        goto leave;
    }

    /* invoke the application startup function */
    if (appStartupFxn != NULL) {
        status = appStartupFxn(app);

        if (status < 0) {
            goto leave;
        }
    }

    /* send ready event to remote core */
    Log_print0(Diags_INFO, FXNN": send EvtReady to remote core");

    status = Notify_sendEvent(obj->remoteProcId, Global_NotifyLineId,
        Global_HostDspEvtNum, Global_EvtReady, TRUE);

    if (status < 0) {
        Log_error1(FXNN": Notify_sendEvent() returned error %d", (IArg)status);
        goto leave;
    }

    /* wait for ready event from remote core */
    Log_print0(Diags_INFO, FXNN": waiting for EvtReady event...");

    SemThread_pend(obj->semH, SemThread_FOREVER, &eb);

    if (Error_check(&eb)) {
        Log_error0(FXNN": SemThread_pend() returned with error");
        status = -1;
        goto leave;
    }
    Log_print0(Diags_INFO, FXNN": ...received EvtReady event");


leave:
    Log_print1(Diags_EXIT, "<-- "FXNN": %d", (IArg)status);
    return(status);
}
#undef FXNN


/*
 *  ======== SystemCfg_finalizeResources ========
 */
#define FXNN "SystemCfg_finalizeResources"
Int SystemCfg_finalizeResources(SystemCfg_Object *obj,
        App_Fxn appShutdownFxn, App_Handle app)
{
    Int             status = 0;
    Error_Block     eb;


    Log_print0(Diags_ENTRY, "--> "FXNN":");

    Error_init(&eb);

    /* invoke the application shutdown function */
    if (appShutdownFxn != NULL) {
        status = appShutdownFxn(app);

        if (status < 0) {
            goto leave;
        }
    }

    /* close shared resources from remote core */
    status = SystemCfg_closeSharedResources_P(obj);

    if (status < 0) {
        Log_error0(FXNN": SystemCfg_closeSharedResources_P() failed");
        goto leave;
    }

    /* send close done event to remote core */
    Log_print0(Diags_INFO, FXNN": send EvtCloseDone to remote core");

    status = Notify_sendEvent(obj->remoteProcId, Global_NotifyLineId,
        Global_HostDspEvtNum, Global_EvtCloseDone, TRUE);

    if (status < 0) {
        Log_error1(FXNN": Notify_sendEvent() returned error %d", (IArg)status);
        goto leave;
    }

    /* wait for close event from remote core */
    Log_print0(Diags_INFO, FXNN": waiting for EvtCloseDone event...");

    SemThread_pend(obj->semH, SemThread_FOREVER, &eb);

    if (Error_check(&eb)) {
        Log_error0(FXNN": SemThread_pend() returned with error");
        status = -1;
        goto leave;
    }
    Log_print0(Diags_INFO, FXNN": ...received EvtCloseDone event");

    /* delete local resources */
    status = SystemCfg_deleteLocalResources_P(obj);

    if (status < 0) {
        Log_error0(FXNN": SystemCfg_deleteLocalResources_P() failed");
        goto leave;
    }

    /* send done event to remote core */
    Log_print0(Diags_INFO, FXNN": send done event to remote core");

    status = Notify_sendEvent(obj->remoteProcId, Global_NotifyLineId,
        Global_HostDspEvtNum, Global_EvtDone, TRUE);

    if (status < 0) {
        Log_error1(FXNN": Notify_sendEvent() returned error %d", (IArg)status);
        goto leave;
    }

    /* wait for done event from remote core */
    Log_print0(Diags_INFO, FXNN": waiting for done event...");

    SemThread_pend(obj->semH, SemThread_FOREVER, &eb);

    if (Error_check(&eb)) {
        Log_error0(FXNN": SemThread_pend() returned with error");
        status = -1;
        goto leave;
    }
    Log_print0(Diags_INFO, FXNN": ...received done event");

    /* unregister notify callback */
    status = Notify_unregisterEvent(obj->remoteProcId, Global_NotifyLineId,
        Global_HostDspEvtNum, SystemCfg_notifyCB_P, (UArg)obj);

    if (status < 0) {
        Log_error1(FXNN": Notify_unregisterEventSingle() returned error %d",
            (IArg)status);
        goto leave;
    }

    /* delete sync objects */
    if (obj->shutdownSemH != NULL) {
        SemThread_destruct(&obj->shutdownSemObj);
        obj->shutdownSemH = NULL;
    }

    if (obj->semH != NULL) {
        SemThread_destruct(&obj->semObj);
        obj->semH = NULL;
    }


leave:
    Log_print1(Diags_EXIT, "<-- "FXNN": %d", (IArg)status);
    return(status);
}
#undef FXNN


/*
 *  ======== SystemCfg_waitForShutdown ========
 */
#define FXNN "SystemCfg_waitForShutdown"
Void SystemCfg_waitForShutdown(SystemCfg_Object *obj)
{
    Error_Block eb;


    Log_print0(Diags_ENTRY, "--> "FXNN": ()");
    Error_init(&eb);

    Log_print0(Diags_INFO, FXNN": waiting for EvtShutdown event...");

    SemThread_pend(obj->shutdownSemH, SemThread_FOREVER, &eb);

    if (Error_check(&eb)) {
        Log_error0(FXNN": SemThread_pend() returned with error");
    }
    else {
        Log_print0(Diags_INFO, FXNN": ...received EvtShutdown event");
    }

    Log_print0(Diags_EXIT, "<-- "FXNN":");
}
#undef FXNN

/*
 *  ======== SystemCfg_notifyCB_P ========
 */
#define FXNN "SystemCfg_notifyCB_P"
Void SystemCfg_notifyCB_P(UInt16 procId, UInt16 lineId, UInt32 eventNum,
        UArg arg, UInt32 payload)
{
    Error_Block         eb;
    SystemCfg_Object *  obj = (SystemCfg_Object *)arg;


    Log_print3(Diags_ENTRY,
        "--> "FXNN": (procId=%d, eventNum=%d, payload=0x%x)",
        (IArg)procId, (IArg)eventNum, (IArg)payload);

    Error_init(&eb);

    switch (Global_EvtMask & payload) {

        case Global_EvtCreateDone:
        case Global_EvtReady:
        case Global_EvtCloseDone:
        case Global_EvtDone:

            SemThread_post(obj->semH, &eb);

            if (Error_check(&eb)) {
                Log_error0(FXNN": SemThread_post() returned error");
            }
            break;

        case Global_EvtShutdown:
            SemThread_post(obj->shutdownSemH, &eb);
            break;
    }

    Log_print0(Diags_EXIT, "<-- "FXNN":");
}
#undef FXNN


/*
 *  ======== SystemCfg_createLocalResources_P ========
 */
#define FXNN "SystemCfg_createLocalResources_P"
Int SystemCfg_createLocalResources_P(SystemCfg_Object *obj)
{
    Int status = 0;


    Log_print1(Diags_ENTRY | Diags_INFO, "--> "FXNN": (obj=0x%x)",(IArg)obj);


    Log_print1(Diags_EXIT, "<-- "FXNN": %d", (IArg)status);
    return(status);
}
#undef FXNN


/*
 *  ======== SystemCfg_deleteLocalResources_P ========
 */
#define FXNN "SystemCfg_deleteLocalResources_P"
Int SystemCfg_deleteLocalResources_P(SystemCfg_Object *obj)
{
    Int status = 0;


    Log_print1(Diags_ENTRY | Diags_INFO, "--> "FXNN": (obj=0x%x)",(IArg)obj);


    Log_print1(Diags_EXIT, "<-- "FXNN": %d", (IArg)status);
    return(status);
}
#undef FXNN


/*
 *  ======== SystemCfg_openSharedResources_P ========
 */
#define FXNN "SystemCfg_openSharedResources_P"
Int SystemCfg_openSharedResources_P(SystemCfg_Object *obj)
{
    Int status = 0;


    Log_print1(Diags_ENTRY | Diags_INFO, "--> "FXNN": (obj=0x%x)",(IArg)obj);


    Log_print1(Diags_EXIT, "<-- "FXNN": %d", (IArg)status);
    return(status);
}
#undef FXNN


/*
 *  ======== SystemCfg_closeSharedResources_P ========
 */
#define FXNN "SystemCfg_closeSharedResources_P"
Int SystemCfg_closeSharedResources_P(SystemCfg_Object *obj)
{
    Int status = 0;


    Log_print1(Diags_ENTRY | Diags_INFO, "--> "FXNN": (obj=0x%x)",(IArg)obj);


    Log_print1(Diags_EXIT, "<-- "FXNN": %d", (IArg)status);
    return(status);
}
#undef FXNN
/*
 *  @(#) ti.sdo.rcm.examples.minidist.linux.server; 1,0,0,4; 2-22-2012 18:10:25; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

