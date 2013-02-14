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
 *  ======== Hello.c ========
 */

/* cstdlib header files */
#include <stdio.h>

/* package header files */
#include <xdc/std.h>            /* must be first */

#include <ti/ipc/HeapBufMP.h>
#include <ti/ipc/MessageQ.h>
#include <ti/ipc/MultiProc.h>
#include <ti/ipc/Notify.h>

#include <ti/sdo/rcm/RcmClient.h>

#include <xdc/runtime/Error.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/knl/SemThread.h>
#include <xdc/runtime/knl/Thread.h>

/* local header files */
#include "Global.h"
#include "Hello.h"

#define QUEUESIZE 8

/* module structure */
typedef struct {
    UInt16                  remoteProcId;
    UInt16                  lineId;     // notify line id
    UInt32                  eventId;    // notify event id
    SemThread_Struct        semS;
    SemThread_Handle        semH;
    UInt32                  eventQue[QUEUESIZE];
    UInt                    head;       // queue head pointer
    UInt                    tail;       // queue tail pointer
    UInt32                  error;
    HeapBufMP_Handle        msgHeap;    // created locally
} Hello_Module;


/* private functions */
static Void     Hello_notifyCB(
        UInt16  procId,
        UInt16  lineId,
        UInt32  eventId,
        UArg    arg,
        UInt32  payload);

static UInt32   Hello_waitForEvent(Void);


/* Module state object */
static Hello_Module Module = {
    .remoteProcId = MultiProc_INVALIDID,
    .lineId = SystemCfg_LineId,
    .eventId = SystemCfg_AppEventId,
    .semH = NULL,
    .head = 0,
    .tail = 0,
    .error = 0,
    .msgHeap = NULL
};


/*
 *  ======== Hello_start ========
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
Int Hello_start(UInt16 remoteProcId)
{
    Int                 status;
    UInt32              event;
    SemThread_Params    semParams;
    HeapBufMP_Params    heapParams;
    Error_Block         eb;


    Error_init(&eb);
    Module.remoteProcId = remoteProcId;


    /*
     *  1. create semaphore object
     */
    SemThread_Params_init(&semParams);
    semParams.mode = SemThread_Mode_COUNTING;

    SemThread_construct(&Module.semS, 0, &semParams, &eb);

    if (Error_check(&eb)) {
        status = -15;
        goto leave;
    }

    Module.semH = SemThread_handle(&Module.semS);


    /*
     *  2. register notify callback
     */
    status = Notify_registerEventSingle(Module.remoteProcId, Module.lineId,
        Module.eventId, Hello_notifyCB, (UArg)&Module);

    if (status < 0) {
        goto leave;
    }


    /*
     *  3. wait until remote core has also registered notify callback
     */
    do {
        status = Notify_sendEvent(Module.remoteProcId, Module.lineId,
            Module.eventId, App_CMD_NOP, TRUE);

        if (status == Notify_E_EVTNOTREGISTERED) {
            Thread_sleep(1000, &eb);  /* microseconds */
        }
    } while (status == Notify_E_EVTNOTREGISTERED);

    if (status < 0) {
        goto leave;
    }


    /*
     *  4. create local & shared resources (to be opened by remote processor)
     */

    /* create heap for rcm messages */
    HeapBufMP_Params_init(&heapParams);
    heapParams.name = Global_RcmClientHeapName;
    heapParams.regionId = 0;
    heapParams.blockSize = 0x200;  /* 512 B */
    heapParams.numBlocks = 8;

    Module.msgHeap = HeapBufMP_create(&heapParams);

    if (Module.msgHeap == NULL) {
        Log_error0("Hello_start: HeapBuf_create() failed");
        status = -1;
        goto leave;
    }

    /* register heap with MessageQ */
    status = MessageQ_registerHeap((Ptr)(Module.msgHeap),
        Global_RcmClientHeapId);

    if (status < 0) {
        goto leave;
    }


    /*
     *  5. send resource ready event
     */
    status = Notify_sendEvent(Module.remoteProcId, Module.lineId,
        Module.eventId, App_CMD_RESRDY, TRUE);

    if (status < 0) {
        goto leave;
    }


    /*
     *  6. wait for remote resource ready event
     */
    do {
        event = Hello_waitForEvent();

        if (event >= App_E_FAILURE) {
            status = -1;
            goto leave;
        }
    } while (event != App_CMD_RESRDY);


    /*
     *  7. open remote resources
     */


    /*
     *  8. handshake the ready event
     */
    status = Notify_sendEvent(Module.remoteProcId, Module.lineId,
        Module.eventId, App_CMD_READY, TRUE);

    if (status < 0) {
        goto leave;
    }

    do {
        event = Hello_waitForEvent();

        if (event >= App_E_FAILURE) {
            status = -1;
            goto leave;
        }
    } while (event != App_CMD_READY);


leave:
    return(status);
}


/*
 *  ======== Hello_stop ========
 *
 *  1. send shutdown event
 *  2. wait for shutdown acknowledgement
 *  3. close remote resources
 *  4. handshake close event
 *  5. delete shared resoures
 *  6. send disconnect event (last event sent)
 *  7. wait for disconnect event
 *  8. unregister notify callback
 *  9. delete semaphore object
 */
Int Hello_stop(Void)
{
    Int         status;
    UInt32      event;


    /*
     *  1. send shutdown command (out-of-band)
     */
    status = Notify_sendEvent(Module.remoteProcId, Module.lineId,
        Module.eventId, App_CMD_SHUTDOWN, TRUE);

    if (status < 0) {
        goto leave;
    }


    /*
     *  2. wait for shutdown acknowledgement
     */
    do {
        event = Hello_waitForEvent();

        if (event >= App_E_FAILURE) {
            status = -1;
            goto leave;
        }
    } while (event != App_CMD_SDACK);


    /*
     *  3. close remote resources
     */


    /*
     *  4. handshake close event
     */
    status = Notify_sendEvent(Module.remoteProcId, Module.lineId,
        Module.eventId, App_CMD_CLOSED, TRUE);

    if (status < 0) {
        goto leave;
    }

    do {
        event = Hello_waitForEvent();

        if (event >= App_E_FAILURE) {
            status = -1;
            goto leave;
        }
    } while (event != App_CMD_CLOSED);


    /*
     *  5. delete shared resoures
     */

    /* unregister heap with MessageQ */
    status = MessageQ_unregisterHeap(Global_RcmClientHeapId);

    if (status < 0) {
        goto leave;
    }

    /* delete the message heap */
    status = HeapBufMP_delete(&Module.msgHeap);

    if (status < 0) {
        goto leave;
    }


    /*
     *  6. send disconnect event (last event sent)
     */
    status = Notify_sendEvent(Module.remoteProcId, Module.lineId,
        Module.eventId, App_CMD_DONE, TRUE);

    if (status < 0) {
        goto leave;
    }


    /*
     *  7. wait for disconnect event (last event received)
     */
    do {
        event = Hello_waitForEvent();

        if (event >= App_E_FAILURE) {
            status = -1;
            goto leave;
        }
    } while (event != App_CMD_DONE);


    /*
     *  8. unregister notify callback
     */
    status = Notify_unregisterEventSingle(Module.remoteProcId, Module.lineId,
        Module.eventId);

    if (status < 0) {
        goto leave;
    }


    /*
     *  9. delete semaphore object
     */
    SemThread_destruct(&Module.semS);


leave:
    return(status);
}


/*
 *  ======== Hello_exec ========
 */
Int Hello_exec(Void)
{
    RcmClient_Params    rcmP;
    RcmClient_Handle    rcmH;
    RcmClient_Message * msg;
    UInt32              size;
    Int                 status;


    /* must initialize the module before using it */
    RcmClient_init();

    /* create an rcm client instance */
    RcmClient_Params_init(&rcmP);
    rcmP.heapId = Global_RcmClientHeapId;

    /* retry in case the slave is still booting */
    do {
        status = RcmClient_create(Global_RcmServerName, &rcmP, &rcmH);
    } while (status == RcmClient_E_SERVERNOTFOUND);

    if (status < 0) {
        Log_error0("Hello_exec: RcmClient create failed");
        goto leave;
    }

    /* allocate a remote command message */
    size = sizeof(RcmClient_Message) + sizeof(UInt32[32]);
    status = RcmClient_alloc(rcmH, size, &msg);

    if (status < 0) {
        msg = NULL;
        Log_error1("Hello_exec: RcmClient_alloc() returned error %d",
            (IArg)status);
        goto leave;
    }

    /* fill in the remote command message */
    msg->fxnIdx = Global_Hello_idx;
    msg->data[0] = (UInt32)0xFFFFFFFF;
    System_sprintf((Char *)(&msg->data[1]), "@@@@"); 

    /* execute the remote command message */
    status = RcmClient_exec(rcmH, msg, &msg);

    if (status < 0) {
        Log_error1("Hello_exec: RcmClient_exec() returned error %d",
            (IArg)status);
        goto leave;
    }

    /* unmarshal return value */
    System_printf("%s\n", (Char *)(&msg->data[1]));

leave:
    /* return message to the heap */
    if (msg != NULL) {
        RcmClient_free(rcmH, msg);
        msg = NULL;
    }

    /* delete the rcm client instance */
    if (rcmH != NULL) {
        RcmClient_delete(&rcmH);
    }

    /* finalize the module to support clean shutdown */
    RcmClient_exit();

    return(status);
}


/*
 *  ======== Hello_notifyCB ========
 */
static Void Hello_notifyCB(
    UInt16      procId,
    UInt16      lineId,
    UInt32      eventId,
    UArg        arg,
    UInt32      payload)
{
    UInt next;
    Error_Block eb;

    Error_init(&eb);

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
    SemThread_post(Module.semH, &eb);
}


/*
 *  ======== Hello_waitForEvent ========
 */
static UInt32 Hello_waitForEvent(Void)
{
    UInt32 event;
    Error_Block eb;

    if (Module.error >= App_E_FAILURE) {
        event = Module.error;
        goto leave;
    }

    Error_init(&eb);

    /* use counting semaphore to wait for next event */
    SemThread_pend(Module.semH, SemThread_FOREVER, &eb);

    if (Error_check(&eb)) {
        event = Module.error;
        goto leave;
    }

    /* remove next command from queue */
    event = Module.eventQue[Module.tail];
    Module.tail = (Module.tail + 1) % QUEUESIZE;

leave:
    return(event);
}
/*
 *  @(#) ti.sdo.rcm.examples.hello; 1,0,0,4; 2-22-2012 18:10:12; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

