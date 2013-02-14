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
 *  ======== SystemCfg_host.c ========
 *
 */

/* this define must precede inclusion of any xdc header file */
#define Registry_CURDESC SystemCfg__Desc
#define MODULE_NAME "SystemCfg"

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
#include <ti/ipc/HeapBufMP.h>
#include <ti/ipc/MessageQ.h>
#include <ti/ipc/MultiProc.h>
#include <ti/ipc/Notify.h>
#include <ti/syslink/IpcHost.h>
#include <ti/syslink/ProcMgr.h>
#include <ti/syslink/SysLink.h>

/* interface definition for this module */
#include <ti/sdo/rcm/examples/appcfg/SystemCfg.h>

/* shared constants between client and server */
#include <ti/sdo/rcm/examples/minidist/linux/server/Global.h>

/* instance object */
typedef struct SystemCfg_Object_tag {
    String              remoteProcName;
    ProcMgr_Handle      procMgrH;
    UInt32              fileId;
    SemThread_Struct    semObj;
    SemThread_Handle    semH;
    UInt16              remoteProcId;
    HeapBufMP_Handle    heapH;
} SystemCfg_Object;

/* private functions */
static Int SystemCfg_createLocalResources_P(SystemCfg_Object *obj);
static Int SystemCfg_deleteLocalResources_P(SystemCfg_Object *obj);
static Int SystemCfg_openSharedResources_P(SystemCfg_Object *obj);
static Int SystemCfg_closeSharedResources_P(SystemCfg_Object *obj);

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
static Char *procState[] = {
    "Unknown", "Powered", "Reset", "Loaded", "Running"
};


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
    Int                 status, n, bufSize;
    Char *              cp;
    Error_Block         eb;
    SystemCfg_Object *  obj;


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
    obj->procMgrH = NULL;
    obj->fileId = 0xFFFFFFFF;
    obj->semH = NULL;
    obj->remoteProcId = MultiProc_INVALIDID;
    obj->heapH = NULL;
    
    /* initialize SemThread_Struct to zero */
    for (cp = (Char *)&obj->semObj, n = sizeof(SemThread_Struct); n > 0; n--) {
        *cp++ = 0;
    }

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
 *  ======== SystemCfg_start ========
 */
#define FXNN "SystemCfg_start"
Int SystemCfg_start(SystemCfg_Object *obj, String filename)
{
    Int                     status = 0;
    Int                     argc;
    String                  argv[2];
    ProcMgr_AttachParams    attachP;
    ProcMgr_StartParams     startP;
    ProcMgr_State           state;


    Log_print1(Diags_ENTRY, "--> "FXNN": (object: 0x%x)", (IArg)obj);

    /* SysLink initialize */
    Log_print0(Diags_INFO, FXNN": SysLink_setup");

    SysLink_setup();

    /* get the dsp procId, must be called *after* SysLink_setup() */
    obj->remoteProcId = MultiProc_getId(obj->remoteProcName);

    if (MultiProc_INVALIDID == obj->remoteProcId) {
        Log_error0(FXNN": MultiProc_getId() returned INVALID");
        status = -1;
        goto leave;
    }

    /* open a ProcMgr handle to the dsp */
    Log_print1(Diags_INFO,
        FXNN": ProcMgr_open: (remoteProcId: %d)",
        (IArg)obj->remoteProcId);

    status = ProcMgr_open(&obj->procMgrH, obj->remoteProcId);

    if (status < 0) {
        Log_error1(FXNN": ProcMgr_open() failed, %d", (IArg)status);
        goto leave;
    }

    /* attach to the remote processor */
    Log_print0(Diags_INFO, FXNN": ProcMgr_attach: (...)");

    ProcMgr_getAttachParams(NULL, &attachP);
    status = ProcMgr_attach(obj->procMgrH, &attachP);

    if (status < 0) {
        Log_error1(FXNN": ProcMgr_attach() failed, %d", (IArg)status);
        goto leave;
    }

    /* setup argc & argv for remote processor */
    argc = 1;
    argv[0] = filename;

    /* load and run the remote processor */
    Log_print2(Diags_INFO,
        FXNN": ProcMgr_load: (procId: %d, file: 0x%x)",
        (IArg)obj->remoteProcId, (IArg)filename);

    status = ProcMgr_load(obj->procMgrH, filename, argc, argv, NULL,
        &obj->fileId);

    if (status < 0) {
        Log_error1(FXNN": ProcMgr_load() failed, %d", (IArg)status);
        goto leave;
    }

    /* temporary: to be done by SysLink in the future */
    Log_print0(Diags_INFO, FXNN": Ipc_control: (LOADCALLBACK)");

    status = Ipc_control(obj->remoteProcId,
        Ipc_CONTROLCMD_LOADCALLBACK, NULL);

    if (status < 0) {
        Log_error1(FXNN": Ipc_control() failed, %d", (IArg)status);
        goto leave;
    }

    state = ProcMgr_getState(obj->procMgrH);
    Log_print1(Diags_INFO,
        FXNN": Processor state is %s", (IArg)procState[state]);

    /* start remote processor */
    Log_print0(Diags_INFO, FXNN": ProcMgr_start: (...)");

    ProcMgr_getStartParams(obj->procMgrH, &startP);
    status = ProcMgr_start(obj->procMgrH, &startP);

    if (status < 0) {
        Log_error1(FXNN": ProcMgr_start() failed, %d", (IArg)status);
        goto leave;
    }

    /* temporary: to be done by SysLink in the future */
    Log_print0(Diags_INFO, FXNN": Ipc_control: (STARTCALLBACK)");

    status = Ipc_control(obj->remoteProcId,
        Ipc_CONTROLCMD_STARTCALLBACK, NULL);

    if (status < 0) {
        Log_error1(FXNN": Ipc_control() failed, %d", (IArg)status);
        goto leave;
    }

    state = ProcMgr_getState(obj->procMgrH);
    Log_print1(Diags_INFO,
        FXNN": Processor state is %s", (IArg)procState[state]);


leave:
    status = (status >= 0 ? 0 : status);
    Log_print2(Diags_EXIT, "<-- %s: %d", (IArg)FXNN, (IArg)status);
    return(status);
}
#undef FXNN


/*
 *  ======== SystemCfg_stop ========
 */
#define FXNN "SystemCfg_stop"
Int SystemCfg_stop(SystemCfg_Object *obj)
{
    Int             status = 0;
    ProcMgr_State   state;


    Log_print0(Diags_ENTRY, "--> "FXNN": ()");

    /* temporary, to be removed later */
    Log_print0(Diags_INFO, FXNN": Ipc_control: (STOPCALLBACK)");

    status = Ipc_control(obj->remoteProcId,
        Ipc_CONTROLCMD_STOPCALLBACK, NULL);

    if (status < 0) {
        Log_error1(FXNN": Ipc_control() failed, %d", (IArg)status);
        goto leave;
    }

    /* stop remote processor */
    Log_print0(Diags_INFO, FXNN": ProcMgr_stop: (...)");

    status = ProcMgr_stop(obj->procMgrH);

    if (status < 0) {
        Log_error1(FXNN": ProcMgr_stop() failed, %d", (IArg)status);
        goto leave;
    }

    /* unload the remote processor */
    Log_print0(Diags_INFO, FXNN": ProcMgr_unload: (...)");

    status = ProcMgr_unload(obj->procMgrH, obj->fileId);

    if (status < 0) {
        Log_error1(FXNN": ProcMgr_unload() failed, %d", (IArg)status);
        goto leave;
    }

    state = ProcMgr_getState(obj->procMgrH);
    Log_print1(Diags_INFO,
        FXNN": Processor state is %s", (IArg)procState[state]);

    /* detach from the remote processor */
    Log_print0(Diags_INFO, FXNN": ProcMgr_detach: (...)");

    status = ProcMgr_detach(obj->procMgrH);

    if (status < 0) {
        Log_error1(FXNN": ProcMgr_detach failed, %d", (IArg)status);
        goto leave;
    }

    /* close the ProcMgr object */
    Log_print0(Diags_INFO, FXNN": ProcMgr_close: (...)");

    status = ProcMgr_close(&obj->procMgrH);

    if (status < 0) {
        Log_error1(FXNN": ProcMgr_close() failed, %d", (IArg)status);
        goto leave;
    }

    /* SysLink finalize */
    Log_print0(Diags_INFO, FXNN": SysLink_destroy");

    SysLink_destroy();


leave:
    Log_print1(Diags_EXIT, "<-- "FXNN": %d", (IArg)status);
    return(status);
}
#undef FXNN


/*
 *  ======== SystemCfg_initializeResources ========
 */
#define FXNN "SystemCfg_initializeResources"
Int SystemCfg_initializeResources(SystemCfg_Object *obj, App_Fxn appStartupFxn,
    App_Handle arg)
{
    Int                 status = 0;
    Int                 count;
    Error_Block         eb;
    SemThread_Params    semThreadP;


    Log_print0(Diags_ENTRY, "--> "FXNN": ()");

    Error_init(&eb);

    /* create sync object used to wait on remote core startup */
    SemThread_Params_init(&semThreadP);
    semThreadP.mode = SemThread_Mode_COUNTING;
    SemThread_construct(&obj->semObj, 0, &semThreadP, &eb);

    if (Error_check(&eb)) {
        Log_error0(FXNN": SemThread_construct() failed");
        status = -1;
        goto leave;
    }
    obj->semH = SemThread_handle(&obj->semObj);

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
        status = appStartupFxn(arg);

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
Int SystemCfg_finalizeResources(SystemCfg_Object *obj, App_Fxn appShutdownFxn,
    App_Handle arg)
{
    Int             status = 0;
    Error_Block     eb;


    Log_print0(Diags_ENTRY, "--> "FXNN": ()");

    Error_init(&eb);

    /* invoke the application shutdown function */
    if (appShutdownFxn != NULL) {
        status = appShutdownFxn(arg);

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
        Log_error1(FXNN": Notify_unregisterEvent() returned error %d",
            (IArg)status);
        goto leave;
    }

    /* delete sync object */
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
 *  ======== SystemCfg_sendShutdown ========
 */
#define FXNN "SystemCfg_sendShutdown"
Void SystemCfg_sendShutdown(SystemCfg_Object *obj)
{
    Int status;


    Log_print0(Diags_ENTRY, "--> "FXNN": ()");

    status = Notify_sendEvent(obj->remoteProcId, Global_NotifyLineId,
        Global_HostDspEvtNum, Global_EvtShutdown, TRUE);

    if (status < 0) {
        Log_error1(FXNN": Notify_sendEvent() returned error %d", (IArg)status);
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
    SystemCfg_Object *  obj = (SystemCfg_Object*)arg;


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
    Int                 status = 0;
    HeapBufMP_Params    heapBufMPP;


    Log_print1(Diags_ENTRY | Diags_INFO, "--> "FXNN": (obj=0x%x)",(IArg)obj);

    /* create heap for messages */
    HeapBufMP_Params_init(&heapBufMPP);
    heapBufMPP.name = Global_RcmClientHeapName;
    heapBufMPP.regionId = 0;
    heapBufMPP.blockSize = 0x200;  /* 512 B */
    heapBufMPP.numBlocks = 8;

    obj->heapH = HeapBufMP_create(&heapBufMPP);

    if (obj->heapH == NULL) {
        Log_error0(FXNN": HeapBuf_create() failed");
        status = -1;
        goto leave;
    }

    /* register this heap with MessageQ */
    Log_print2(Diags_INFO,
        FXNN": MessageQ_registerHeap: (heapH: 0x%x, heapId: %d)",
        (IArg)(obj->heapH), (IArg)Global_RcmClientHeapId);

    MessageQ_registerHeap((Ptr)(obj->heapH), Global_RcmClientHeapId);


leave:
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

    /* unregister heap with MessageQ */
    MessageQ_unregisterHeap(Global_RcmClientHeapId);

    /* delete heap used for rcm message queue */
    HeapBufMP_delete(&obj->heapH);

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

    /* add code here */

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

    /* add code here */

    Log_print1(Diags_EXIT, "<-- "FXNN": %d", (IArg)status);
    return(status);
}
#undef FXNN
/*
 *  @(#) ti.sdo.rcm.examples.minidist.linux.client; 1,0,0,4; 2-22-2012 18:10:10; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

