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
 * ======== acpy3_configure.c ========
 * Configure a logical channel
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

#include <ti/sdo/fc/memutils/memutils.h>


#ifndef xdc_target__isaCompatible_64P
#include "acpy3_qdma_arm.h"
#else
#include "acpy3_qdma.h"
#endif

#include "acpy3.h"


#ifdef __TI_COMPILER_VERSION__
#pragma CODE_SECTION(ACPY3_configure, ".text:ACPY3_configure")
#endif

/* For Logging */
extern Registry_Desc ti_sdo_fc_acpy3_desc;


/*
 *  ======= ACPY3_configure ========
 *  Configure all DMA transfer settings for the logical channel.
 */
Void ACPY3_configure(IDMA3_Handle handle, ACPY3_Params * restrict params,
    short transferNo)
{
    ACPY3_PaRamRegs * restrict paRamCache;
    unsigned short   tcc;
    short            waitId;
    ACPY3_MoreEnv   * restrict env;

    Assert_isTrue(handle != NULL, (Assert_Id)NULL);
    Assert_isTrue(handle->protocol == &ACPY3_PROTOCOL, (Assert_Id)NULL);
    Assert_isTrue(params->waitId < ((ACPY3_MoreEnv *)(handle->env))->numTccs,
            (Assert_Id)NULL);
    Assert_isTrue(transferNo >= 0, (Assert_Id)NULL);
    Assert_isTrue(transferNo < ((ACPY3_MoreEnv *)(handle->env))->numPaRams,
            (Assert_Id)NULL);
    Assert_isTrue(!handle->transferPending, (Assert_Id)NULL);
    Assert_isTrue(params->waitId <= transferNo, (Assert_Id)NULL);

    Log_print2(Diags_ENTRY, "[+E] ACPY3_configure> Enter "
            "(handle=0x%x, transferNo=%d)", (IArg)handle, (IArg)transferNo);

    env = (ACPY3_MoreEnv *)(handle->env);

    ACPY3_INSTR_CALLHOOKFXN(env->extendedHooks, handle,
            ACPY3_INSTR_CONFIGURE_ENTER);

#if 0
    paRamCache = (ACPY3_PaRamRegs *)ACPY3_getPaRamCache(handle, transferNo);
#else
    paRamCache = (ACPY3_PaRamRegs *)env - (transferNo + 1);
#endif

    /*
     * If the waitId is set to the last allocated waitId, just ignore it.
     * This will be handled by ACPY3_setFinal instead.
     */
    if ((waitId = params->waitId) == env->numTccs - 1) {
        waitId = -1;

        Log_print0(Diags_USER2, "[+2] ACPY3_configure> WaitId "
                "is the last allocated waitId");
    }

#if _ACPY3_DIRTY_BITS
    /*
     * Mark all bits in the dirty bit table for this PaRAM as dirty
     */
    env->dirtyBitTable[transferNo] = 0x3f;
#endif /* if _ACPY3_DIRTY_BITS */

    /* #1 - Source address */
#ifndef xdc_target__isaCompatible_64P
#ifndef _ACPY3_CPUCOPY_
    paRamCache->src = MEMUTILS_getPhysicalAddr(params->srcAddr);
#else
    paRamCache->src = params->srcAddr;
#endif
#else
    paRamCache->src = params->srcAddr;
#endif

    /* #2 */
    paRamCache->acnt = params->elementSize;
    paRamCache->bcnt = 1; /* default for 1D1D */

    /* #3 - Destination address */
#ifndef xdc_target__isaCompatible_64P
#ifndef _ACPY3_CPUCOPY_
    paRamCache->dst = (Void *)MEMUTILS_getPhysicalAddr(params->dstAddr);
#else
    paRamCache->dst = params->dstAddr;
#endif
#else
    paRamCache->dst = params->dstAddr;
#endif

    /* #5 - Set bcnt reload value to bcnt, set to no link */
    paRamCache->bCntrld = params->numElements;

#ifdef _ACPY3_NO_IDMA_
    paRamCache->ccnt = 1;
#endif
    if (params->transferType != ACPY3_1D1D) {
        Assert_isTrue(params->numFrames < 2, (Assert_Id)NULL);

        /* Field #2: update with 2nd dimension */
        paRamCache->bcnt = params->numElements;

        /* Field #3: set Element Indexes for 2D2D */
        paRamCache->srcElementIndex = params->srcElementIndex;
        paRamCache->dstElementIndex = params->dstElementIndex;

        if (params->transferType == ACPY3_1D2D) {
            paRamCache->srcElementIndex = params->elementSize;

            Log_print0(Diags_USER4, "[+4] ACPY3_configure> 1D2D transfer");
        }
        else if (params->transferType == ACPY3_2D1D) {
            paRamCache->dstElementIndex = params->elementSize;

            Log_print0(Diags_USER4, "[+4] ACPY3_configure> 2D1D transfer");
        }
        else {

            Log_print0(Diags_USER4, "[+4] ACPY3_configure> 2D2D transfer");
        }
    }
    else {

        Log_print0(Diags_USER4, "[+4] ACPY3_configure> 1D1D transfer");

    }


    Log_print4(Diags_USER4, "[+4] ACPY3_configure> src 0x%x, "
            "dst 0x%x, acnt 0x%x, bcnt 0x%x ",
            (IArg)(paRamCache->src), (IArg)(paRamCache->dst),
            (IArg)(paRamCache->acnt), (IArg)(paRamCache->bcnt));

    Log_print3(Diags_USER4, "[+4] ACPY3_configure> bcnt reload"
            " 0x%x, srcIndex 0x%x, dstIndex 0x%x",
            (IArg)(paRamCache->bCntrld), (IArg)(paRamCache->srcElementIndex),
            (IArg)(paRamCache->dstElementIndex));

    /*
     * If configuring handle with linked transfers then
     * adjust the 'link' and 'tcc' synchronization, etc., in opt.
     */
    if ((transferNo < (env->numPaRams - 1)) &&
        (transferNo != (handle->numPaRams - 1))) {

        /* #5 */
        /*
         *  Setup this param's link field to point to the NEXT transfer when
         *  setting up linked transfers we assign PARAM addresses in
         *  descending order, so that the last entry is the first transfer,
         *  etc., handle's paRamAddr is pointing to the 'last' PARAM entry
         *  assigned to the channel handle (along with the preceding
         *  "numTransfer" PARAM entries.
         */
        paRamCache->link =
            (unsigned short)ACPY3_getPaRamLinkIndex(handle, transferNo + 1);

        /* setup tcc for intermediate transfers waits and unset STATIC */

        if (waitId >= 0) {
            tcc  = handle->tccTable[waitId + 1];

            Log_print1(Diags_USER2, "[+2] ACPY3_configure> Tcc %d", (IArg)tcc);

            /*
             * If this is the highest intermediate waitId,
             * then update handle->numTccs
             */
            if (waitId > ((int)handle->numTccs) - 2) {
                handle->numTccs = waitId + 2;

                Log_print1(Diags_USER2, "[+2] ACPY3_configure>"
                        " Configured number of Tccs for this handle %d",
                        (IArg)(handle->numTccs));

            }

            paRamCache->opt = ACPY3_TCCBITS(tcc)       |   /* TCC_CHAN */
                              ACPY3_PARAMOPTS_AB_SYNC  |
                              ACPY3_PARAMOPTS_TCC_INTEN;
        }
        else { /* cannot wait on this transfer */
            paRamCache->opt = ACPY3_PARAMOPTS_AB_SYNC;
        }

    }
    else {
        /* #5 - Set no link for final PaRam */
        paRamCache->link = 0xffff;

        env->prevWaitIdOfFinal = waitId;

        /* Single transfer or the last one of the Linked transfers */
        /* Pick the tcc from the handle - even when waitId is (-1) */
        tcc = handle->tccTable[0];

        Log_print1(Diags_USER2, "[+2] ACPY3_configure> Tcc %d", (IArg)tcc);

        if ((transferNo == handle->numPaRams - 1) && (waitId >= 0)) {
            handle->numTccs = waitId + 1;

            Log_print1(Diags_USER2, "[+2] ACPY3_configure> "
                    "Configured number of Tccs for this handle %d",
                    (IArg)(handle->numTccs));
        }

        /* #0 */
        paRamCache->opt = ACPY3_TCCBITS(tcc)        |   /* TCC_CHAN */
                          ACPY3_PARAMOPTS_AB_SYNC   |
                          ACPY3_PARAMOPTS_TCC_INTEN |
                          ACPY3_PARAMOPTS_STATIC;
    }

    Log_print2(Diags_USER4, "[+4] ACPY3_configure> Link this"
            " transfer to 0x%x Opt is 0x%x",
            (IArg)(paRamCache->link), (IArg)(paRamCache->opt));

    ACPY3_INSTR_CALLHOOKFXN(env->extendedHooks, handle,
            ACPY3_INSTR_CONFIGURE_EXIT);
}
/*
 *  @(#) ti.sdo.fc.acpy3; 1, 0, 4,4; 2-22-2012 18:03:27; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

