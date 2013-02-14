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
 *  ======== ProgRemote.c ========
 *
 */


/* xdctools header files */
#include <xdc/std.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>

/* package header files */
#include <ti/ipc/MultiProc.h>
#include <ti/ipc/Notify.h>
#include <ti/sdo/tiler/MemMgr.h>
#include <ti/sdo/tiler/Settings.h>


/* local header files */
#include "App.h"
#include "SystemCfg.h"


#define MEMSET(addr, val, count)        \
{                                       \
    UInt i;                             \
    UInt8 *ptr = (UInt8 *)(addr);       \
                                        \
    for (i = 0; i < count; i++) {       \
        *ptr++ = val;                   \
    }                                   \
}


/* local functions */
static Int App_testMemMgr(Void);


/*
 *  ======== App_startup ========
 */
#define FXNN "App_startup"
Int App_startup(Ptr arg)
{
    Int status = 0;


    Log_print2(Diags_ENTRY, "--> %s: (arg: 0x%x)", (IArg)FXNN, (IArg)arg);


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
    Int status = 0;


    Log_print2(Diags_ENTRY, "--> %s: (arg: 0x%x)", (IArg)FXNN, (IArg)arg);

    /* test tiler api calls */
    Log_print0(Diags_INFO, FXNN": starting work loop");

    status = App_testMemMgr();

    if (status < 0) {
        goto leave;
    }

    Log_print0(Diags_INFO, FXNN": work loop completed");


leave:
    Log_print2(Diags_EXIT, "<-- %s: %d", (IArg)FXNN, (IArg)status);
    return (status >= 0 ? 0 : status);
}
#undef FXNN


/*
 *  ======== App_shutdown ========
 */
#define FXNN "App_shutdown"
Int App_shutdown(Ptr arg)
{
    UInt16 hostProcId;
    Int status = 0;


    Log_print2(Diags_ENTRY, "--> %s: (arg: 0x%x)", (IArg)FXNN, (IArg)arg);

    /* get the host proc id */
    hostProcId = MultiProc_getId("HOST");

    if (MultiProc_INVALIDID == hostProcId) {
        /* Log_error() */
        Log_print3(Diags_USER8,
            "Error: %s, line %d: %s: MultiProc_getId() returned INVALID",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN);
        status = -1;
        goto leave;
    }

    /* send done event to remote core */
    Log_print0(Diags_INFO, FXNN": send shutdown event to host");

    status = Notify_sendEvent(hostProcId, Global_NotifyLineId,
        Global_HostDspEvtNum, Global_EvtAppShutdown, TRUE);

    if (status < 0) {
        /* Log_error() */
        Log_print4(Diags_USER8,
            "Error: %s, line %d: %s: Notify_sendEvent() returned error %d",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN, (IArg)status);
        goto leave;
    }


leave:
    Log_print2(Diags_EXIT, "<-- %s: %d", (IArg)FXNN, (IArg)status);
    return(status);
}
#undef FXNN

volatile int spin = 1;

/*
 *  ======== App_testMemMgr ========
 */
#define FXNN "App_testMemMgr"
Int App_testMemMgr(Void)
{
    MemAllocBlock block;
    void *bufPtr[2];
    UInt8 *ptr8;
    UInt32 x, y;
    UInt8 val;
    Int status = 0;

    Log_print0(Diags_ENTRY, "--> "FXNN":");

    /* allocate in 8-bit container */
    Log_print0(Diags_INFO, "MemMgr_Alloc(8, 8, 8-bit)");

    MEMSET(&block, 0, sizeof(block));
    block.pixelFormat = PIXEL_FMT_8BIT;
    block.dim.area.width  = 8;
    block.dim.area.height = 8;
    bufPtr[0] = MemMgr_Alloc(&block, 1);

    if (bufPtr[0] == NULL) {
        status = -1;
        /* Log_error() */
        Log_print3(Diags_USER8,
            "Error: %s, line %d: %s: MemMgr_Alloc() failed",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN);
        goto leave;
    }

    Log_print2(Diags_INFO, "bufPtr[0]: 0x%x, stride = %d",
        (IArg)bufPtr[0], (IArg)block.stride);
    Log_print1(Diags_INFO, "reserved: 0x%x", (IArg)block.reserved);

    /* allocate in 8-bit container */
    Log_print0(Diags_INFO, "MemMgr_Alloc(8, 8, 8-bit)");

    MEMSET(&block, 0, sizeof(block));
    block.pixelFormat = PIXEL_FMT_8BIT;
    block.dim.area.width  = 8;
    block.dim.area.height = 8;
    bufPtr[1] = MemMgr_Alloc(&block, 1);

    if (bufPtr[1] == NULL) {
        status = -1;
        /* Log_error() */
        Log_print3(Diags_USER8,
            "Error: %s, line %d: %s: MemMgr_Alloc() failed",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN);
        goto leave;
    }

    Log_print2(Diags_INFO, "bufPtr[1]: 0x%x, stride = %d",
        (IArg)bufPtr[1], (IArg)block.stride);
    Log_print1(Diags_INFO, "reserved: 0x%x", (IArg)block.reserved);

    /* write data to memory */
    ptr8 = (UInt8 *)bufPtr[0];
    val = 0xA0;

    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++) {
            *(ptr8 + (y * block.stride) + x) = val++;
        }
    }

Log_print1(Diags_INFO, "bufPtr[0](0x%x) 8x8 block written, spinning on 'spin'", (IArg)bufPtr[0]);
while (spin);

    /* free buffer in 8-bit containter */
    Log_print1(Diags_INFO, "MemMgr_Free(0x%x)", (IArg)bufPtr[0]);
    if (MemMgr_Free(bufPtr[0]) != 0) {
        status = -2;
        /* Log_error() */
        Log_print3(Diags_USER8,
            "Error: %s, line %d: %s: MemMgr_Free() failed",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN);
        goto leave;
    }

    /* free buffer in 8-bit containter */
    Log_print1(Diags_INFO, "MemMgr_Free(0x%x)", (IArg)bufPtr[1]);
    if (MemMgr_Free(bufPtr[1]) != 0) {
        status = -2;
        /* Log_error() */
        Log_print3(Diags_USER8,
            "Error: %s, line %d: %s: MemMgr_Free() failed",
            (IArg)__FILE__, (IArg)__LINE__, (IArg)FXNN);
        goto leave;
    }


leave:
    Log_print2(Diags_EXIT, "<-- %s: %d", (IArg)FXNN, (IArg)status);
    return (status >= 0 ? 0 : status);
}
#undef FXNN
/*
 *  @(#) ti.sdo.tiler.examples.remote; 1, 0, 0,4; 2-22-2012 18:10:55; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

