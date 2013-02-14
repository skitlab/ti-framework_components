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
#define Registry_CURDESC Server__Desc
#define MODULE_NAME "Server"

#include <string.h>

/* package header files */
#include <xdc/std.h>            /* must be first */

#include <ti/ipc/HeapBufMP.h>
#include <ti/ipc/MessageQ.h>
#include <ti/ipc/MultiProc.h>
#include <ti/ipc/Notify.h>

#include <ti/sdo/rcm/RcmServer.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Task.h>

#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Registry.h>


/* local header files */
#include "Global.h"

#define QUEUESIZE 8

/* module structure */
typedef struct {
    UInt16              hostProcId;
    UInt16              lineId;         // notify line id
    UInt32              eventId;        // notify event id
    Semaphore_Struct    semS;
    Semaphore_Handle    semH;
    HeapBufMP_Handle    heapH;          // rcm heap (opened)
    UInt32              eventQue[QUEUESIZE];
    UInt                head;           // queue head pointer
    UInt                tail;           // queue tail pointer
    UInt32              error;
    RcmServer_Handle    rcmServerH;     // RcmServer instance handle
} Server_Module;


/* private functions */
static Int32 Server_hello_fxn(UInt32 dataSize, UInt32 *data);
Void Server_notifyCB(UInt16 procId, UInt16 lineId, UInt32 eventId, UArg arg,
        UInt32 payload);
static UInt32   Server_waitForEvent(Void);

/* Module state object */
static Server_Module Module;

/* private data */
static Int curInit = 0;
Registry_Desc Registry_CURDESC; /* module diags mask */

/* RcmServer static function table */
static RcmServer_FxnDesc serverFxnAry[] = {
    { "Hello",  Server_hello_fxn }
};

#define serverFxnAryLen (sizeof serverFxnAry / sizeof serverFxnAry[0])

static const RcmServer_FxnDescAry Server_fxnTab = {
    serverFxnAryLen,
    serverFxnAry
};



/*
 *  ======== Server_init ========
 */
Void Server_init(Void)
{
    Registry_Result result;

    if (curInit++ != 0) {
        return;  /* already initialized */
    }

    /* register with xdc.runtime to get a diags mask */
    result = Registry_addModule(&Registry_CURDESC, MODULE_NAME);
    Assert_isTrue(result == Registry_SUCCESS, (Assert_Id)NULL);

    /* initialize module state */
    Module.hostProcId = MultiProc_getId("HOST");
    Module.lineId = SystemCfg_LineId;
    Module.eventId = SystemCfg_AppEventId;
    Module.semH = NULL;
    Module.heapH = NULL;
    Module.head = 0;
    Module.tail = 0;
    Module.error = 0;
    Module.rcmServerH = NULL;

    RcmServer_init();
}


/*
 *  ======== Server_exit ========
 */
Void Server_exit(Void)
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


/*
 *  ======== Server_setup ========
 *
 *  1. create semaphore object
 *  2. register notify callback
 *  3. wait until remote core has also registered notify callback
 *  4. create local & shared resources
 *  5. send resource ready event
 *  6. wait for remote resource ready event
 *  7. open remote resources
 *  8. handshake the ready event
 */
Int Server_setup(Void)
{
    Int                 status;
    UInt32              event;
    Semaphore_Params    semParams;
    RcmServer_Params    rcmServerP;


    Log_print0(Diags_ENTRY | Diags_INFO, "--> Server_setup:");

    /*
     *  1. create semaphore object
     */
    Semaphore_Params_init(&semParams);
    semParams.mode = Semaphore_Mode_COUNTING;
    Semaphore_construct(&Module.semS, 0, &semParams);
    Module.semH = Semaphore_handle(&Module.semS);


    /*
     *  2. register notify callback
     */
    status = Notify_registerEventSingle(Module.hostProcId, Module.lineId,
        Module.eventId, Server_notifyCB, (UArg)&Module);

    if (status < 0) {
        goto leave;
    }


    /*
     *  3. wait until remote core has also registered notify callback
     */
    do {
        status = Notify_sendEvent(Module.hostProcId, Module.lineId,
            Module.eventId, App_CMD_NOP, TRUE);

        if (status == Notify_E_EVTNOTREGISTERED) {
            Task_sleep(200);  /* ticks */
        }
    } while (status == Notify_E_EVTNOTREGISTERED);

    if (status < 0) {
        goto leave;
    }


    /*
     *  4. create local & shared resources (to be opened by remote processor)
     */


    /*
     *  5. send resource ready event
     */
    status = Notify_sendEvent(Module.hostProcId, Module.lineId, Module.eventId,
        App_CMD_RESRDY, TRUE);

    if (status < 0) {
        goto leave;
    }


    /*
     *  6. wait for remote resource ready event
     */
    do {
        event = Server_waitForEvent();

        if (event >= App_E_FAILURE) {
            status = -1;
            goto leave;
        }
    } while (event != App_CMD_RESRDY);


    /*
     *  7. open remote resources
     */

    /* open the rcm heap */
    status = HeapBufMP_open(Global_RcmClientHeapName, &Module.heapH);

    if (status < 0) {
        Log_error1("Server_setup: HeapBufMP_open() returned error %d",
            (IArg)status);
        goto leave;
    }

    /* register the rcm heap with MessageQ */
    status = MessageQ_registerHeap((Ptr)(Module.heapH), Global_RcmClientHeapId);

    if (status < 0) {
        Log_error1("Server_setup: MessageQ_restierHeap() returned error %d",
            (IArg)status);
        goto leave;
    }

    /* initialize RcmServer create params */
    RcmServer_Params_init(&rcmServerP);
    rcmServerP.fxns.length = Server_fxnTab.length;
    rcmServerP.fxns.elem = Server_fxnTab.elem;

    /* create the RcmServer instance */
    status = RcmServer_create(Global_RcmServerName, &rcmServerP,
        &Module.rcmServerH);

    if (status < 0) {
        Log_error1("Server_setup: RcmServer_create() returned error %d",
            (IArg)status);
        goto leave;
    }

    /* start the server */
    RcmServer_start(Module.rcmServerH);


    /*
     *  8. handshake the ready event
     */
    status = Notify_sendEvent(Module.hostProcId, Module.lineId, Module.eventId,
        App_CMD_READY, TRUE);

    if (status < 0) {
        goto leave;
    }

    do {
        event = Server_waitForEvent();

        if (event >= App_E_FAILURE) {
            status = -1;
            goto leave;
        }
    } while (event != App_CMD_READY);


leave:
    Log_print1(Diags_EXIT, "<-- Server_setup: %d", (IArg)status);
    return(status);
}


/*
 *  ======== Server_finish ========
 *
 *  1. close remote resources
 *  2. handshake close event
 *  3. delete shared resoures
 *  4. send disconnect event (last event sent)
 *  5. wait for disconnect event
 *  6. unregister notify callback
 *  9. delete semaphore object
 */
Int Server_finish(Void)
{
    Int         status;
    UInt32      event;


    /*
     *  1. close remote resources
     */

    /* delete the RcmServer instance */
    status = RcmServer_delete(&Module.rcmServerH);

    if (status < 0) {
        Log_error1("Server_finish: RcmServer_delete() returned error %d",
            (IArg)status);
        goto leave;
    }

    /* unregister rcm heap with MessageQ */
    status = MessageQ_unregisterHeap(Global_RcmClientHeapId);

    if (status < 0) {
        goto leave;
    }

    /* close the rcm heap */
    status = HeapBufMP_close(&Module.heapH);

    if (status < 0) {
        Log_error1("Server_finish: HeapBufMP_close() returned error %d",
            (IArg)status);
        goto leave;
    }


    /*
     *  2. handshake close event
     */
    status = Notify_sendEvent(Module.hostProcId, Module.lineId,
        Module.eventId, App_CMD_CLOSED, TRUE);

    if (status < 0) {
        goto leave;
    }

    do {
        event = Server_waitForEvent();

        if (event >= App_E_FAILURE) {
            status = -1;
            goto leave;
        }
    } while (event != App_CMD_CLOSED);


    /*
     *  3. delete shared resoures
     */


    /*
     *  4. send disconnect event (last event sent)
     */
    status = Notify_sendEvent(Module.hostProcId, Module.lineId,
        Module.eventId, App_CMD_DONE, TRUE);

    if (status < 0) {
        goto leave;
    }


    /*
     *  5. wait for disconnect event (last event received)
     */
    do {
        event = Server_waitForEvent();

        if (event >= App_E_FAILURE) {
            status = -1;
            goto leave;
        }
    } while (event != App_CMD_DONE);


    /*
     *  6. unregister notify callback
     */
    status = Notify_unregisterEventSingle(Module.hostProcId, Module.lineId,
        Module.eventId);

    if (status < 0) {
        goto leave;
    }


    /*
     *  9. delete semaphore object
     */
    Semaphore_destruct(&Module.semS);
    Module.semH = NULL;


leave:
    return(status);
}


/*
 *  ======== Server_run ========
 */
Int Server_run(Void)
{
    Int         status = 0;
    UInt32      event;


    Log_print0(Diags_ENTRY, "--> Server_run:");

    /* wait for the shutdown command */
    do {
        event = Server_waitForEvent();

        if (event >= App_E_FAILURE) {
            status = -1;
            goto leave;
        }
    } while (event != App_CMD_SHUTDOWN);

    /* send shutdown acknowledgement */
    Notify_sendEvent(Module.hostProcId, Module.lineId,
        Module.eventId, App_CMD_SDACK, TRUE);

leave:
    Log_print1(Diags_EXIT, "<-- Server_run: %d", (IArg)status);
    return(status);
}


/*
 *  ======== Server_hello_fxn ========
 *
 *  data[0]    out Int          status
 *  data[1-31] out Char[124]    message
 */
Int32 Server_hello_fxn(UInt32 dataSize, UInt32 *data)
{
    Char *cp;

    /* write message into payload */
    cp = (Char *)(&data[1]);
    strcpy(cp, "Hello World!");

    /* return success status code */
    *(Int *)(&data[0]) = 0;

    return(0);
}


/*
 *  ======== Server_notifyCB ========
 */
Void Server_notifyCB(
    UInt16      procId,
    UInt16      lineId,
    UInt32      eventId,
    UArg        arg,
    UInt32      payload)
{
    UInt next;

    /* ignore no-op events */
    if (payload == App_CMD_NOP) {
        return;
    }

    /* compute next slot in queue */
    next = (Module.head + 1) % QUEUESIZE;

    if (next == Module.tail) {
        /* queue is full, drop event and set error flag */
        Module.error = App_E_OVERFLOW;
        return;
    }
    else {
        Module.eventQue[Module.head] = payload;
        Module.head = next;
    }

    /* signal semaphore (counting) that new event is in queue */
    Semaphore_post(Module.semH);
}


/*
 *  ======== Server_waitForEvent ========
 */
static UInt32 Server_waitForEvent(Void)
{
    UInt32 event;

    if (Module.error >= App_E_FAILURE) {
        event = Module.error;
        goto leave;
    }

    /* use counting semaphore to wait for next event */
    Semaphore_pend(Module.semH, BIOS_WAIT_FOREVER);

    /* remove next command from queue */
    event = Module.eventQue[Module.tail];
    Module.tail = (Module.tail + 1) % QUEUESIZE;

leave:
    return(event);
}
/*
 *  @(#) ti.sdo.rcm.examples.hello; 1,0,0,4; 2-22-2012 18:10:13; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

