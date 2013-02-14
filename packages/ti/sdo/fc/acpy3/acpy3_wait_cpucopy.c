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
 *  ======== acpy3_wait_cpucopy.c ========
 */


/* This define must precede inclusion of any xdc header files */
#define Registry_CURDESC ti_sdo_fc_acpy3_desc

#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Registry.h>

#include <ti/xdais/idma3.h>
#include "acpy3_util.h"


#ifdef _ACPY3_CPUCOPY_

#ifdef xdc_target__isaCompatible_64P
#pragma CODE_SECTION(ACPY3_wait, ".text:ACPY3_wait")
#endif

extern Registry_Desc ti_sdo_fc_acpy3_desc;

static Void doTransfer(IDMA3_Handle handle);

/*
 *  ======== ACPY3_wait ========
 *  Wait for all submitted DMA transfer on this logical channel to complete.
 */
Void ACPY3_wait(IDMA3_Handle handle)
{

    Log_print1(Diags_ENTRY, "[+E] ACPY3_wait> Enter (handle=0x%x)",
            (IArg)handle);
    
    Assert_isTrue(handle != NULL, (Assert_Id)NULL);

     ACPY3_INSTR_CALLHOOKFXN(((ACPY3_MoreEnv *)(handle->env))->hooks,handle,\
            ACPY3_INSTR_WAIT_ENTER);

    /*
     * Wait for a channel only once. Set the 'pending' flag whenever new
     * transfer is submitted, then clear it when ACPY3_wait* is issued.
     */
    if (!handle->transferPending) {
        ACPY3_INSTR_CALLHOOKFXN(((ACPY3_MoreEnv *)(handle->env))->hooks,handle,
                ACPY3_INSTR_WAIT_EXIT);

        Log_print0(Diags_USER4, "[+4] _ACPY3_start> No transfer pending");

        Log_print0(Diags_EXIT, "[+X] _ACPY3_start> Exit");

        return;  /* already  waited since last start. */
    }

    doTransfer(handle);

    /*
     * Mark channel handle state to indicate pending transfer has completed
     * and 'wait' done
     */
    handle->transferPending = FALSE;

     ACPY3_INSTR_CALLHOOKFXN(((ACPY3_MoreEnv *)(handle->env))->hooks,handle,\
            ACPY3_INSTR_WAIT_EXIT);

    Assert_isTrue(handle->transferPending == FALSE, (Assert_Id)NULL);

    Log_print0(Diags_EXIT, "[+X] ACPY3_wait> Exit");
    
}

/*
 *  ======= ACPY3_waitLinked ========
 * Blocking wait for an individual transfer in a Linked transfer to finish.
 * Requires the individual transfer indicated by the 'waitId'
 * to be configured as synchronous, otherwise returns immediately.
 */
Void ACPY3_waitLinked(IDMA3_Handle handle, unsigned short waitId)
{

    Log_print2(Diags_ENTRY, "[+E] ACPY3_waitLinked> Enter "
            "(handle=0x%x, waitId=%d)", (IArg)handle, (IArg)waitId);

    Assert_isTrue((handle != NULL) && (waitId < handle->numTccs),
            (Assert_Id)NULL);

    ACPY3_INSTR_CALLHOOKFXN(((ACPY3_MoreEnv *)(handle->env))->extendedHooks,
            handle, ACPY3_INSTR_WAITLINKED_ENTER);
    /*
     * Wait for a channel only once. Set the 'pending' flag whenever new
     * transfer is submitted, then clear it when ACPY3_wait* is issued.
     */
    if (handle->transferPending == FALSE) {
        ACPY3_INSTR_CALLHOOKFXN(((ACPY3_MoreEnv *)(handle->env))->extendedHooks,
                handle, ACPY3_INSTR_WAITLINKED_EXIT);

        Log_print0(Diags_USER4, "[+4] ACPY3_waitLinked> No transfer pending");

        Log_print0(Diags_EXIT, "[+X] ACPY3_waitLinked> Exit");

        return;  /* already  waited since last start. */
    }

    if (waitId == (handle->numTccs - 1)) {

        Log_print0(Diags_USER4, "[+4] ACPY3_waitLinked> "
                "Waiting on the last transfer");

        ACPY3_wait(handle);
    }
    else {
        doTransfer(handle);
    }

    /*
     * Mark channel handle state to indicate pending transfer has completed
     * and 'wait' done
     */
    handle->transferPending = FALSE;

    ACPY3_INSTR_CALLHOOKFXN(((ACPY3_MoreEnv *)(handle->env))->extendedHooks,
            handle, ACPY3_INSTR_WAITLINKED_EXIT);

    Log_print0(Diags_EXIT, "[+X] ACPY3_waitLinked> Exit");
}


/*
 *  ======== doTransfer ========
 */
static Void doTransfer(IDMA3_Handle handle)
{
    unsigned char *src, *dst;
    unsigned char *srcFrameStart, *dstFrameStart;
    ACPY3_PaRamRegs *paRamCache;
    Int numTransfers = handle->numPaRams;
    Int transferNo;
    unsigned short ccnt;
    unsigned short bcnt;
    unsigned short acnt;
    short srcElementIndex;
    short dstElementIndex;
    short srcFrameIndex;
    short dstFrameIndex;

    Log_print1(Diags_ENTRY, "[+E] doTransfer> Enter (handle=0x%x) ",
            (IArg)handle);

    for (transferNo = 0; transferNo < numTransfers; transferNo++) {
        /*
         * Use each transfer's cached paRam settings. The
         */
        paRamCache = (ACPY3_PaRamRegs *)ACPY3_getPaRamCache(handle,
                transferNo);

        src  = paRamCache->src;
        dst  = paRamCache->dst;
        acnt = paRamCache->acnt;
        bcnt = paRamCache->bcnt;

        /*
         *  QDMA can only transfer a single frame, so ccnt must always be 1.
         */
        ccnt = 1;

        srcElementIndex = paRamCache->srcElementIndex;
        dstElementIndex = paRamCache->dstElementIndex;
        srcFrameIndex = paRamCache->srcFrameIndex;
        dstFrameIndex = paRamCache->dstFrameIndex;

        Log_print6(Diags_USER2, "[+2] doTransfer> Transfer %d,"
                " acnt  0x%x, bcnt 0x%x, src 0x%x, dst 0x%x, srcIndex 0x%x, "
                "dstIndex 0x%x",
                (IArg)acnt, (IArg)bcnt, (IArg)src, (IArg)dst,
                (IArg)srcElementIndex, (IArg)dstElementIndex);

        while (ccnt-- > 0) {
            /* Keep track of the start of the frame */
            srcFrameStart = src;
            dstFrameStart = dst;

            /* Copy a frame */
            while (bcnt-- > 0) {

                /* Copy an element */
                while (acnt-- > 0) {
                    *dst++ = *src++;
                }

                /*
                 * Reset ACNT counter.
                 * Advance src/dst ptrs to beginning of next line/1D-vector
                 */
                acnt = paRamCache->acnt;
                src = (src - acnt) + srcElementIndex ;
                dst = (dst - acnt) + dstElementIndex;
            }

            /* adjust src and dst to the beginning of a frame + frameIndex*/
            bcnt = paRamCache->bcnt;
            src = srcFrameStart + srcFrameIndex;
            dst = dstFrameStart + dstFrameIndex;
        }
    } /* for each transfer */

    Log_print0(Diags_EXIT, "[+X] doTransfer> Exit");
}

#endif

/*
 *  @(#) ti.sdo.fc.acpy3; 1, 0, 4,4; 2-22-2012 18:03:29; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

