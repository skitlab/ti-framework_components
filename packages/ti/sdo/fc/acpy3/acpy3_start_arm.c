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
 *  ======== acpy3_start_arm.c ========
 */


/* This define must precede inclusion of any xdc header files */
#define Registry_CURDESC ti_sdo_fc_acpy3_desc

#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Gate.h>
#include <xdc/runtime/IGateProvider.h>

#include <xdc/runtime/Registry.h>

#ifndef xdc_target__isaCompatible_64P
#include "acpy3_qdma_arm.h"
#else
/*
 *  This is only so we can debug this code on the DSP. This code is meant to
 *  run on the ARM, but it can be built for the 64P so we can step through
 *  the code in CCS.
 */
#include "acpy3_qdma.h"
#endif

#include "acpy3_util.h"

#ifndef _ACPY3_CPUCOPY_

extern Registry_Desc ti_sdo_fc_acpy3_desc;

extern IGateProvider_Handle _ACPY3_gate;


/*
 *  ======== ACPY3_start ========
 */
void ACPY3_start(IDMA3_Handle handle)
{
    volatile Uns *lastPaRam;
    Int            transferNo;
    Int            numTransfers;
    Int            numTransfersM1;
    Int            i;
    unsigned short qdmaChan;
    Uns            qDmaChanMask;
    volatile Uns  *paRamAddr;
    Uns            paRamOffset;
    volatile Uns  *paRamPhys;
    volatile Uns  *paRamCache;
    //IDMA3_Handle  *lockTblPtr;
    Int            count = 0;
    IArg            key;

    Assert_isTrue(handle != NULL, (Assert_Id)NULL);
    Assert_isTrue(handle->transferPending == FALSE, (Assert_Id)NULL);

    Log_print0(Diags_ENTRY, "[+E] ACPY3_start> Enter");

    /*
     * Do as much work as possible before waiting for any
     * shared hardware registers.
     */
    numTransfers = handle->numPaRams;
    numTransfersM1 = numTransfers - 1;

    /*
     *  _ACPY3_qchLockTbl[] is used to optimize checks on the static bit
     *  of the PaRam in QCHMAP (to make sure all linked transfers have
     *  been submitted before changing the QCHMAP). To make this usable
     *  accross processes, we would need to put it in an IPC shared memory
     *  segment. We could add onto the one in DMAN3, but this adds another
     *  dependency on DMAN3. For now, always check that the currently
     *  mapped PaRam's static bit is set. Not as efficient, but safe.
     */
    //lockTblPtr = (IDMA3_Handle *)_ACPY3_qchLockTbl;

    /* Remaining transfers are handled via a separate IDMA transfer */
    qdmaChan = handle->qdmaChan;

    paRamAddr = handle->paRamAddr;
    paRamOffset = (Uns)paRamAddr - (Uns)ACPY3_QDMA_PARAM_BASE;

    /*
     *  Enter critical section when modifying or reading QCHMAP registers.
     *  This is necessary since these registers are shared resources.
     */
    key = IGateProvider_enter(_ACPY3_gate);

    /*
     *  Program the QDMA Channel Map register for this handle's qdmaChan
     *  so that DMA transfer is triggerred by the last Physical PARAM write
     *  issued by this 'start'.
     *
     *  NOTE: System must ensure that when the last PARAM write occurs this
     *  QCHMAP setting is still intact. Otherwise the rest of this function
     *  must be executed as a critical section.
     *    Bits 13...5: paRam address
     *    Bits 4..2:   triger word (in this case, word 7)
     */
    /* TODO: need to understand the use of all bits in QCHMAP */

    if (/* lockTblPtr[qdmaChan] */ TRUE)
    {
        qDmaChanMask = 1 << qdmaChan;

        /*
         *  Program the QDMA Channel Map register for this handle's qdmaChan
         *  so that DMA transfer is triggerred by the last Physical PARAM write
         *  issued by this 'start'.
         */
        /*
         *  NOTE: System must ensure that when the last PARAM write occurs
         *  this QCHMAP setting is still intact. Otherwise the rest of
         *  this function  must be executed as a critical section.
         *    Bits 13...5: paRam address
         *    Bits 4..2:   trigger word (in this case, word 7)
         */

        /*
         * Ensure that we can use the corresponding QDMA channel.
         * a) wait for the PaRAM location for STATIC = 1, and
         * b) wait for QER to be cleared.
         * Step (a) is necessary to detect that the final link in the QDNA
         * linked list has been copied to the QDMA PaRAM entry location.
         * Step (b) confirms that the newly linked PaRAM entry has been
         * submitted to TC.
         */
        /* step (a) */
        lastPaRam = (Uns *)((Uns)ACPY3_QDMA_PARAM_BASE +
                           (ACPY3_QCHMAP[qdmaChan] & 0x3fe0));

        while (!((*lastPaRam) & 0x8)) {
            if (++count >= _ACPY3_TIMEOUT) {

                Log_print2(Diags_USER6,
                        "[+6] ACPY3_start> Timed out polling for static bit in "
                        "paRam %p, opts = [0x%x]",
                        (IArg)lastPaRam, (IArg)(*lastPaRam));

                Log_print1(Diags_USER6, "[+6] ACPY3_start> PaRam base = [0x%x]",
                        (IArg)ACPY3_QDMA_PARAM_BASE);

                Log_print2(Diags_USER6,
                        "[+6] ACPY3_start> qdmaChan [0x%x], mapped PaRam [0x%x]",
                        (IArg)qdmaChan,
                        (IArg)(ACPY3_QCHMAP[qdmaChan] & 0x3fe0));

                /* Reset count */
                count = 0;
            }
        }

        /* step (b) */
        while ((*ACPY3_QER) & qDmaChanMask) {

            if (++count >= _ACPY3_TIMEOUT) {

                Log_print2(Diags_USER6, "[+6] ACPY3_start> "
                        "Timed out polling for ACPY3_QER [0x%x] to clear, "
                        "qDmaChanMask [0x%x]",
                        (IArg)(*ACPY3_QER), (IArg)qDmaChanMask);
                count = 0;
            }
        }
    }

    /* Mark the trigger word for the transfer */
    /* trigger word is link|bCntrld */
    ACPY3_QCHMAP[qdmaChan] = (Uns)(paRamOffset) | (0x5 << 2);

    for (transferNo = numTransfersM1; transferNo >= 0 ; transferNo--) {
        /*
         * Use each transfer's cached paRam settings. The
         */
        paRamCache = (unsigned int *)ACPY3_getPaRamCache(handle, transferNo);

        /* Obtain the Physical PaRam Address to write to for this transfer */
        paRamPhys = (unsigned int *) ACPY3_getPaRamPhysicalAddress(handle,
                transferNo);

        /* Trigger DMA transfer by writing cached DMA parameters to PARAM */
#ifdef xdc_target__isaCompatible_64P
#pragma MUST_ITERATE(6)
#endif
        for (i = 0; i <= 5; i++) {
            paRamPhys[i] = paRamCache[i];
        }
    } /* for each transfer */

    /* Mark that the QDMA channel is locked */
    //lockTblPtr[qdmaChan] = handle;
    IGateProvider_leave(_ACPY3_gate, key);
    
    /*
     *  As soon as channel is clear, mark the channel state to indicate a
     *  new transfer is being issued and 'transfer is pending'.
     *  Only a subsequent 'ACPY3_wait' will clear the pending state.
     */
    handle->transferPending = TRUE;

    Log_print0(Diags_EXIT, "[+X] ACPY3_start > Exit");

    Assert_isTrue(handle->transferPending == TRUE, (Assert_Id)NULL);
}
#endif
/*
 *  @(#) ti.sdo.fc.acpy3; 1, 0, 4,4; 2-22-2012 18:03:28; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

