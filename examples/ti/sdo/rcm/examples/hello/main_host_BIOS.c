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
 *  ======== main_host_BIOS.c ========
 *
 */

/* xdctools header files */
#include <xdc/std.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/System.h>

/* package header files */
#include <ti/ipc/Ipc.h>
#include <ti/ipc/HeapBufMP.h>
#include <ti/ipc/MessageQ.h>
#include <ti/ipc/MultiProc.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sdo/rcm/examples/appcfg/App.h>

/* local header files */
#include "Global.h"

/* private functions */
static Void smain(UArg arg0, UArg arg1);


/*
 *  ======== main ========
 */
Int main(Int argc, Char* argv[])
{
    Int         status;
    Task_Params taskParams;


    /* initialize ipc layer */
    do {
        status = Ipc_start();
    } while (status < 0);

    /* create main thread (interrupts not enabled in main on BIOS) */
    Task_Params_init(&taskParams);
    taskParams.instance->name = "smain";
    taskParams.arg0 = (UArg)argc;
    taskParams.arg1 = (UArg)argv;
    taskParams.stackSize = 0x4000;
    Task_create(smain, &taskParams, NULL);

    /* start scheduler, this never returns */
    BIOS_start();
    
    /* should never get here */
    return(0);
}


/*
 *  ======== smain ========
 */
#define FXNN "smain"
Void smain(UArg arg0, UArg arg1)
{
    HeapBufMP_Params    heapBufMPP;
    HeapBufMP_Handle    heapH = NULL;
    UInt16              serverProcId;
    Int                 status = 0;


    /* create heap for rcm messages */
    HeapBufMP_Params_init(&heapBufMPP);
    heapBufMPP.name = Global_RcmClientHeapName;
    heapBufMPP.regionId = 0;
    heapBufMPP.blockSize = 0x80;  /* 128 B */
    heapBufMPP.numBlocks = 4;

    heapH = HeapBufMP_create(&heapBufMPP);

    if (heapH == NULL) {
        Log_error0(FXNN": HeapBuf_create() failed");
        goto leave;
    }

    /* register this heap with MessageQ */
    MessageQ_registerHeap((Ptr)heapH, Global_RcmClientHeapId);

    /* attach to the server processor */
    serverProcId = MultiProc_getId(Global_ServerProcName);

    do {
        status = Ipc_attach(serverProcId);

        if (status < 0) {
#ifdef __ARCTIC__
            Task_yield();  /* no timers on EVE simulator */
#else
            Task_sleep(10); /* 10ms (when 1 tick == 1 ms) */
#endif
        }
    } while (status < 0);

    /* delay 500ms to give server a chance to boot */
#ifdef __ARCTIC__
    Task_yield();
#else
    Task_sleep(500);
#endif

    /* invoke the application entry point */
    App_exec(NULL);


leave:
    /* detach from server processor */
    Ipc_detach(serverProcId);

    /* unregister the heap and delete it */
    if (heapH != NULL) {
        MessageQ_unregisterHeap(Global_RcmClientHeapId);
        HeapBufMP_delete(&heapH);
    }

    /* report if error */
    if (status < 0) {
        System_printf("FAIL: example encountered errors\n");
    }
    return;
}
#undef FXNN
/*
 *  @(#) ti.sdo.rcm.examples.hello; 1,0,0,4; 2-22-2012 18:10:14; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

