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
#include <xdc/runtime/IGateProvider.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Registry.h>
#include <xdc/runtime/knl/GateH.h>

/* package header files */
#include <ti/ipc/Ipc.h>
#include <ti/ipc/HeapBufMP.h>
#include <ti/ipc/MessageQ.h>
#include <ti/ipc/MultiProc.h>
#include <ti/ipc/Notify.h>
#include <ti/sdo/utils/List.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/gates/GateHwi.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Task.h>

/* local header files */
#include "SystemCfg.h"

/* instance object */
typedef struct SystemCfg_Object_tag {
    List_Elem           link;
    String              remoteProcName;
    UInt16              remoteProcId;
    UInt32              event;              // received event mask
    Semaphore_Struct    semObj;
    Semaphore_Handle    semH;
    HeapBufMP_Handle    rcmHeapH;           // RCM message heap
} SystemCfg_Object;

/* private functions */
static Void SystemCfg_notifyCB(
        UInt16          procId,
        UInt16          lineId,
        UInt32          eventNum,
        UArg            arg,
        UInt32          payload
    );

/* private data */
Registry_Desc                   Registry_CURDESC;
static Int                      curInit = 0;
static List_Handle              Mod_objList;
static List_Struct              Mod_objListStruct;
static IGateProvider_Handle     Mod_gate;
static GateHwi_Struct           Mod_gateStruct;


/*
 *  ======== SystemCfg_init ========
 */
Void SystemCfg_init(Void)
{
    Registry_Result     result;
    GateHwi_Handle      gate;


    if (curInit++ != 0) {
        return;  /* already initialized */
    }

    /* register with xdc.runtime to get a diags mask */
    result = Registry_addModule(&Registry_CURDESC, MODULE_NAME);
    Assert_isTrue(result == Registry_SUCCESS, (Assert_Id)NULL);

    List_construct(&Mod_objListStruct, NULL);
    Mod_objList = List_handle(&Mod_objListStruct);

    GateHwi_construct(&Mod_gateStruct, NULL);
    gate = GateHwi_handle(&Mod_gateStruct);
    Mod_gate = GateHwi_Handle_upCast(gate);
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

    List_destruct(&Mod_objListStruct);
    Mod_objList = NULL;

    GateHwi_destruct(&Mod_gateStruct);
    Mod_gate = NULL;
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
    Semaphore_Params    semParams;


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
    obj->event = 0;
    obj->semH = NULL;
    obj->rcmHeapH = NULL;
    
    /* initialize structures to zero */
    memset((Void *)&obj->semObj, 0, sizeof(Semaphore_Struct));

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
    Semaphore_Params_init(&semParams);
    semParams.mode = Semaphore_Mode_COUNTING;
    Semaphore_construct(&obj->semObj, 0, &semParams);
    obj->semH = Semaphore_handle(&obj->semObj);

    /* add object to module list for register hook */
    List_putHead(Mod_objList, &obj->link);

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
    Int                 bufSize;
    List_Elem *         elem = NULL;
    SystemCfg_Object *  obj;
    IArg                key;


    Log_print0(Diags_ENTRY, "--> "FXNN": ()");

    /* remove object from module list */
    key = GateH_enter(Mod_gate);

    while ((elem = List_next(Mod_objList, elem)) != NULL) {
        obj = (SystemCfg_Object *)elem;

        if (obj == *objPtr) {
            List_remove(Mod_objList, elem);
            break;
        }
    }

    GateH_leave(Mod_gate, key);

    /* delete sync object */
    if ((*objPtr)->semH != NULL) {
        Semaphore_destruct(&(*objPtr)->semObj);
        (*objPtr)->semH = NULL;
    }

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
 *  ======== SystemCfg_startAck ========
 */
#define FXNN "SystemCfg_startAck"
Int SystemCfg_startAck(SystemCfg_Handle handle)
{
    Int status;

    /* initialize ipc layer */
    status = Ipc_start();

    if (status < 0) {
        Log_error1(FXNN": Ipc_start() error %d", (IArg)status);
    }

    return(status);
}
#undef FXNN


/*
 *  ======== SystemCfg_stop ========
 */
#define FXNN "SystemCfg_stop"
Void SystemCfg_stop(SystemCfg_Handle handle)
{
    /* not yet implemented */
//  Ipc_stop();
}
#undef FXNN


/*
 *  ======== SystemCfg_attach ========
 */
#define FXNN "SystemCfg_attach"
Int SystemCfg_attach(SystemCfg_Object *obj)
{
    Int status;

    Log_print1(Diags_ENTRY,
        "--> "FXNN": (remoteProcId=%d)", (IArg)obj->remoteProcId);

    /* connect to remote processor */
    do {
        status = Ipc_attach(obj->remoteProcId);

        if (status < 0) {
            Task_yield();
        }
    } while (status == Ipc_E_NOTREADY);

    if (status < 0) {
        Log_error1(FXNN": Ipc_attach() failed, error=%d", (IArg)status);
        goto leave;
    }
    Log_print1(Diags_INFO, FXNN": remoteProcId=%d", (IArg)obj->remoteProcId);

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
    Int status;

    Log_print1(Diags_ENTRY,
        "--> "FXNN": (remoteProcId=%d)", (IArg)obj->remoteProcId);

    /* connect to remote processor */
    do {
        status = Ipc_detach(obj->remoteProcId);

        if (status < 0) {
            Task_yield();
        }
    } while (status == Ipc_E_NOTREADY);

    if (status < 0) {
        Log_error1(FXNN": Ipc_detach() failed, error=%d", (IArg)status);
        goto leave;
    }
    Log_print1(Diags_INFO, FXNN": remoteProcId=%d", (IArg)obj->remoteProcId);

leave:
    Log_print1(Diags_EXIT, "<-- "FXNN": %d", (IArg)status);
    return(status);
}
#undef FXNN


/*
 *  ======== SystemCfg_handshakeEvent ========
 */
#define FXNN "SystemCfg_handshakeEvent"
Int SystemCfg_handshakeEvent(SystemCfg_Object *obj, UInt32 event)
{
    Int status;

    /* send event to remote core */
    status = SystemCfg_sendEvent(obj, event);

    if (status < 0) {
        Log_error1(FXNN": Notify_sendEvent() error %d", (IArg)status);
        goto leave;
    }

    /* wait for same event */
    SystemCfg_waitForEvent(obj, event);

leave:
    return(status);
}
#undef FXNN


/*
 *  ======== SystemCfg_sendEvent ========
 */
#define FXNN "SystemCfg_sendEvent"
Int SystemCfg_sendEvent(SystemCfg_Object *obj, UInt32 event)
{
    Int status;

    /* send event to remote core */
    status = Notify_sendEvent(obj->remoteProcId, SystemCfg_NotifyLineId,
        SystemCfg_HostDspEvtNum, event, TRUE);

    if (status < 0) {
        Log_error1(FXNN": Notify_sendEvent() error %d", (IArg)status);
    }

    return(status);
}
#undef FXNN


/*
 *  ======== SystemCfg_waitForEvent ========
 */
#define FXNN "SystemCfg_waitForEvent"
Void SystemCfg_waitForEvent(SystemCfg_Object *obj, UInt32 event)
{
    IArg    key;
    Bool    waitForEvent = TRUE;


    Log_print1(Diags_ENTRY|Diags_INFO,
        "--> "FXNN": waiting for event 0x%x ...", event);

    key = GateH_enter(Mod_gate);

    /* check if event already received */
    if (obj->event & event) {
        obj->event &= ~(event);
        waitForEvent = FALSE;
    }

    GateH_leave(Mod_gate, key);

    while (waitForEvent) {
        Semaphore_pend(obj->semH, BIOS_WAIT_FOREVER);

        /* check if event received */
        if (obj->event & event) {
            obj->event &= ~(event);
            waitForEvent = FALSE;
        }
    }

    Log_print1(Diags_EXIT|Diags_INFO,
        "<-- "FXNN": ...received event 0x%x", event);
}
#undef FXNN


/*
 *  ======== SystemCfg_notifyCB ========
 */
#define FXNN "SystemCfg_notifyCB"
Void SystemCfg_notifyCB(UInt16 procId, UInt16 lineId, UInt32 eventNum,
        UArg arg, UInt32 payload)
{
    SystemCfg_Object *  obj = (SystemCfg_Object *)arg;
    IArg                key;


    Log_print3(Diags_ENTRY,
        "--> "FXNN": (procId=%d, eventNum=%d, payload=0x%x)",
        (IArg)procId, (IArg)eventNum, (IArg)payload);
    Log_print1(Diags_INFO, FXNN": event=0x%x", (IArg)payload);

    key = GateH_enter(Mod_gate);

    /* latch the event */
    obj->event |= payload;
    Semaphore_post(obj->semH);

    GateH_leave(Mod_gate, key);

    Log_print0(Diags_EXIT, "<-- "FXNN":");
}
#undef FXNN


/*
 *  ======== SystemCfg_attachHook ========
 *  Ipc attach hook, register notify event here.
 */
#define FXNN "SystemCfg_attachHook"
Int SystemCfg_attachHook(Ptr *userObj, UInt16 remoteProcId)
{
    Int                 status;
    List_Elem *         elem = NULL;
    SystemCfg_Object *  obj = NULL;
    IArg                key;

    /* find object on module list */
    key = GateH_enter(Mod_gate);

    while ((elem = List_next(Mod_objList, elem)) != NULL) {
        obj = (SystemCfg_Object *)elem;
        if (obj->remoteProcId == remoteProcId) {
            break;
        }
        obj = NULL;
    }

    GateH_leave(Mod_gate, key);

    if (obj != NULL) {
        status = Notify_registerEvent(remoteProcId, SystemCfg_NotifyLineId,
            SystemCfg_HostDspEvtNum, SystemCfg_notifyCB, (UArg)obj);

        if (status < 0) {
            Log_error1(FXNN": Notify_registerEvent() error %d", (IArg)status);
        }
    }

    return(status);
}
#undef FXNN


/*
 *  ======== SystemCfg_detachHook ========
 *  Ipc attach hook, register notify event here.
 */
#define FXNN "SystemCfg_detachHook"
Int SystemCfg_detachHook(Ptr *userObj, UInt16 remoteProcId)
{
    Int                 status;
    List_Elem *         elem = NULL;
    SystemCfg_Object *  obj = NULL;
    IArg                key;

    /* find object on module list */
    key = GateH_enter(Mod_gate);

    while ((elem = List_next(Mod_objList, elem)) != NULL) {
        obj = (SystemCfg_Object *)elem;
        if (obj->remoteProcId == remoteProcId) {
            break;
        }
        obj = NULL;
    }

    GateH_leave(Mod_gate, key);

    if (obj != NULL) {
        status = Notify_unregisterEvent(remoteProcId, SystemCfg_NotifyLineId,
            SystemCfg_HostDspEvtNum, SystemCfg_notifyCB, (UArg)obj);

        if (status < 0) {
            Log_error1(FXNN": Notify_unregisterEvent() error %d", (IArg)status);
        }
    }

    return(status);
}
#undef FXNN


/*
 *  ======== SystemCfg_openResources ========
 */
Int SystemCfg_openResources(SystemCfg_Object *obj)
{
    Int status;

    /* open rcm heap created on host processor */
    status = HeapBufMP_open(SystemCfg_RcmMsgHeapName_CompDev, &(obj->rcmHeapH));

    if (status < 0) {
        Log_error1("HeapBufMP_open() error %d", (IArg)status);
        goto leave;
    }

    /* register this heap with MessageQ */
    MessageQ_registerHeap((Ptr)(obj->rcmHeapH), SystemCfg_RcmMsgHeapId_CompDev);


leave:
    return(status);
}


/*
 *  ======== SystemCfg_closeResources ========
 */
Int SystemCfg_closeResources(SystemCfg_Object *obj)
{
    /* unregister rcm message heap with MessageQ */
    MessageQ_unregisterHeap(SystemCfg_RcmMsgHeapId_CompDev);

    /* close rcm heap reference */
    HeapBufMP_close(&(obj->rcmHeapH));

    return(0);
}
/*
 *  @(#) ti.sdo.opencl.examples.hello; 1, 0, 0,4; 2-22-2012 18:09:32; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

