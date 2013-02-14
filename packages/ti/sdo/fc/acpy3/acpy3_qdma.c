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
 *  ======== acpy3_qdma.c ========
 *
 * New functions that are called to do Channel activation/deactivation
 * for scratch DMA channels.
 */

/* This define must precede inclusion of any xdc header files */
#define Registry_CURDESC ti_sdo_fc_acpy3_desc

#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Registry.h>

#include <ti/xdais/idma3.h>
#include "acpy3.h"
#include "acpy3_qdma.h"
#include "acpy3_util.h"


#pragma CODE_SECTION(ACPY3_activate, ".text:ACPY3_activate")
#pragma CODE_SECTION(ACPY3_deactivate, ".text:ACPY3_deactivate")

extern Registry_Desc ti_sdo_fc_acpy3_desc;

/*
 *  ======== ACPY3_activate ========
 */
Void ACPY3_activate(IDMA3_Handle handle)
{
#if _ACPY3_DIRTY_BITS
    unsigned char * restrict dirtyBytePtr;
#endif
    Int    i;
    Int    numPaRamsM1;
    Uns    nBytesPaRams;
    Uns    nBytes;
    Uns    nWords;
    ACPY3_MoreEnv *env;
    Void  * restrict scratchEnv;
    Int   * restrict ptrPersist;
    Int   * restrict ptrScratch;
#ifndef _ACPY3_CPUCOPY_
    Uns    paRam;
    Uns    begPaRam;
    Uns    endPaRam;
    unsigned short qdmaChan;
    volatile Uns   *paRamRegs;
    volatile Uns   *lastPaRam;
    Uns    triggerIdx;
    Uns    nullPaRam = ACPY3_QDMA.nullPaRamIndex;
#endif

    Log_print1(Diags_ENTRY, "[+E] ACPY3_activate> Enter, handle = 0x%x",
            (IArg)handle);

    Assert_isTrue(handle != NULL, (Assert_Id)NULL);

    env = (ACPY3_MoreEnv *)(handle->env);

    ACPY3_INSTR_CALLHOOKFXN(env->extendedHooks, handle, 
            ACPY3_INSTR_ACTIVATE_ENTER);

    if ((scratchEnv = env->scratchEnv) && (scratchEnv != env)) {
        /*
         * Copy env->persistEnv to env->scratchEnv.
         * Then set env in handle to point to scratch memory until
         * ACPY3_deactivate() is called.
         */
        nBytesPaRams = env->numPaRams * (sizeof(ACPY3_PaRamRegs));
#if _ACPY3_DIRTY_BITS
        nBytes = (sizeof(ACPY3_MoreEnv) - sizeof(unsigned char)) +
            nBytesPaRams + (env->numPaRams * sizeof(unsigned char));
#else
        nBytes = sizeof(ACPY3_MoreEnv) + nBytesPaRams;
#endif
        ptrPersist = (Int *)(((char *)env) - nBytesPaRams);
        ptrScratch = (Int *)(((char *)scratchEnv) - nBytesPaRams);

        Log_print3(Diags_USER2, "[+2] ACPY3_activate> Copy env"
                " %d byte from persistent 0x%x to scratch 0x%x",
                (IArg)nBytes, (IArg)ptrPersist, (IArg)ptrScratch);

        /* Copy 4 bytes at a time for optimization */
        nWords = (nBytes + 3) >> 2;

#pragma MUST_ITERATE((sizeof(ACPY3_MoreEnv) + sizeof(ACPY3_PaRamRegs) + 3) / 4)
        for (i = 0; i < nWords; i++) {
            *ptrScratch++ = *ptrPersist++;
        }
        handle->env = env = scratchEnv;
    }
#ifndef _ACPY3_CPUCOPY_
    qdmaChan = handle->qdmaChan;

    Log_print1(Diags_USER2, "[+2] ACPY3_activate> Qdma channel = %d",
            (IArg)qdmaChan);
#endif
    /* Set CCNT to 1 in all physical PaRams owned by this channel */
    numPaRamsM1 = env->numPaRams - 1;

#ifndef _ACPY3_CPUCOPY_
    /*
     * If any other QDMA channel uses the current PaRam set for this channel,
     * Modify it to use paRam 0 or 127 instead.
     * This shouldn't really happen, but we really need to avoid it.
     */
    endPaRam = ((Uns)handle->paRamAddr) - (Uns)ACPY3_QDMA_PARAM_BASE;
    begPaRam = endPaRam - (numPaRamsM1 << 5);

    for (i = 0; i < ACPY3_NUM_QDMA_CHANNELS; i++) {
        if (i == qdmaChan) {
            continue;
        }
        

        paRam = (ACPY3_QCHMAP[i] & 0x3fe0);
        if ((paRam >= begPaRam) && (paRam <= endPaRam)) {
            /*
             *  Set trigger word of other channels to a paRam not in use
             *  (trigger word is ccnt of the null PaRam)
             */
            ACPY3_QCHMAP[i] = (Uns)(nullPaRam << 5) | (0x7 << 2);

            Log_print3(Diags_USER2, "[+2] ACPY3_activate> Qdma"
                    " channel %d, points to paRam 0x%x, changing the QCHMAP "
                    "register to 0x%x",
                    (IArg)i, (IArg)paRam, (IArg)(ACPY3_QCHMAP[i]));
        }
    }

    /*
     *  Set the QCHMAP for this channel to the null PaRam, since the static bit
     *  will always be set for it (and we know there is no transfer in progress
     *  on first call to ACPY3_start()).
     */
    ACPY3_QCHMAP[qdmaChan] = (Uns)(nullPaRam << 5) | (0x7 << 2);

    Log_print1(Diags_USER2, "[+2] ACPY3_activate> QCHMAP "
            "register for this channel is 0x%x",
            (IArg)(ACPY3_QCHMAP[qdmaChan]));

    /* Enable QEER */
    *ACPY3_QEESR = 0x1 << (qdmaChan);

    Log_print1(Diags_USER2, "[+2] ACPY3_activate> QEER "
            "register for this channel is 0x%x", (IArg)(*ACPY3_QEER));
    /*
     * Set the last two elements of each real allocated paRam to their
     * expected values.  They should never get written again as long as
     * this handle is activated.
     */
    lastPaRam = (Uns *)((Uns)ACPY3_QDMA_PARAM_BASE +
            (ACPY3_QCHMAP[qdmaChan] & 0x3fe0));
    triggerIdx = (ACPY3_QCHMAP[qdmaChan] & (0x7 << 2))  >> 2;

    //TODO: Add trace here 
    for (i = env->numPaRams - 1; i >= 0; i--) {
        paRamRegs = (Uns *)ACPY3_getPaRamPhysicalAddress(handle, i);

        if ((paRamRegs == lastPaRam) && (triggerIdx >= 6)) {
            /* set trigger word to link|bCntrld of 1st paRam */
            ACPY3_QCHMAP[qdmaChan] = (Uns)(handle->paRamAddr) | (0x5 << 2);
        }
        paRamRegs[0x6] = 0; /* frame indices = 0 */
        paRamRegs[0x7] = 1; /* ccnt=1, rsvd=0 */
    }
#endif /* _ACPY3_CPUCOPY_ */

#if _ACPY3_DIRTY_BITS
    /* Set all PaRAM cache bits as "dirty". */
    dirtyBytePtr = env->dirtyBitTable;

    for (i = handle->numPaRams; i > 0; i--) {
        *dirtyBytePtr++ = 0xff;
    }
#endif

    handle->transferPending = FALSE;
    handle->numPaRams = numPaRamsM1 + 1;
    handle->numTccs = env->numTccs;

    ACPY3_INSTR_CALLHOOKFXN(env->extendedHooks, handle, 
            ACPY3_INSTR_ACTIVATE_EXIT);

    Log_print2(Diags_USER4, "[+4] ACPY3_activate> numPaRams %d, numTccs %d",
            (IArg)(handle->numPaRams), (IArg)(handle->numTccs));

    Log_print0(Diags_EXIT, "[+X] ACPY3_activate> Exit");

    return;
}

/*
 *  ======== ACPY3_deactivate ========
 */
Void ACPY3_deactivate(IDMA3_Handle handle)
{
    Uns    nBytesPaRams;
    Uns    nBytes;
    Uns    nWords;
    Int    i;
    ACPY3_MoreEnv *env;
    Void  * restrict scratchEnv;
    Void  * restrict persistEnv;
    Int   * restrict ptrPersist;
    Int   * restrict ptrScratch;
#ifndef _ACPY3_CPUCOPY_
    Uns    nullPaRam = ACPY3_QDMA.nullPaRamIndex;
#endif

    Log_print1(Diags_ENTRY, "[+E] ACPY3_deactivate> Enter (handle=0x%x)",
            (IArg)handle);

    Assert_isTrue(handle != NULL, (Assert_Id)NULL);

    env = (ACPY3_MoreEnv *)(handle->env);

    ACPY3_INSTR_CALLHOOKFXN(env->extendedHooks, handle, 
            ACPY3_INSTR_DEACTIVATE_ENTER);

    if ((scratchEnv = env->scratchEnv) && (env == scratchEnv)) {
        /*
         * Copy env->scratchEnv to env->persisthEnv.
         * Then set env in handle to point to persistent shadow until
         * next ACPY3_activate() is called.
         */
        nBytesPaRams = env->numPaRams * (sizeof(ACPY3_PaRamRegs));
        persistEnv = env->persistEnv;
#if _ACPY3_DIRTY_BITS
        nBytes = (sizeof(ACPY3_MoreEnv) - sizeof(unsigned char)) +
            nBytesPaRams + (env->numPaRams * sizeof(unsigned char));
#else
        nBytes = sizeof(ACPY3_MoreEnv) + nBytesPaRams;
#endif
        ptrScratch = (Int *)(((char *)scratchEnv) - nBytesPaRams);
        ptrPersist = (Int *)(((char *)persistEnv) - nBytesPaRams);

        Log_print3(Diags_USER2, "[+2] ACPY3_deactivate> "
                "Copy %d nBytes of env from Scratch 0x%x to Persistent 0x%x",
                (IArg)nBytes, (IArg)ptrScratch, (IArg)ptrPersist);

        /* Copy 4 bytes at a time for optimization */
        nWords = (nBytes + 3) >> 2;

#pragma MUST_ITERATE((sizeof(ACPY3_MoreEnv) + sizeof(ACPY3_PaRamRegs) + 3) / 4)
        for (i = 0; i < nWords; i++) {
            *ptrPersist++ = *ptrScratch++;
        }
        handle->env = persistEnv;
    }

#ifndef _ACPY3_CPUCOPY_
    /* Set the QCHMAP back to null PaRam */
    ACPY3_QCHMAP[handle->qdmaChan] = (Uns)(nullPaRam << 5) | (0x7 << 2);

    Log_print1(Diags_USER2, "[+2] ACPY3_deactivate> Set QCHMAP"
            " register back to NULL param 0x%x",
            (IArg)(ACPY3_QCHMAP[handle->qdmaChan]));

#endif

    ACPY3_INSTR_CALLHOOKFXN(env->extendedHooks, handle, 
            ACPY3_INSTR_DEACTIVATE_EXIT);

    Log_print0(Diags_EXIT, "[+X] ACPY3_deactivate> Exit");

    return;
}

/*
 *  @(#) ti.sdo.fc.acpy3; 1, 0, 4,4; 2-22-2012 18:03:28; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

