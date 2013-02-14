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
 *  ======== acpy3_setfinal.h ========
 */

#ifdef _ACPY3_

#ifndef _ACPY3_SETFINAL_
#define _ACPY3_SETFINAL_

#include <ti/xdais/idma3.h>
#include <ti/sdo/fc/acpy3/acpy3_util.h>
#include <ti/sdo/fc/acpy3/acpy3.h>

#if defined(ACPY3_SETFINAL_INLINE) || defined(ACPY3_INLINE_ALL)
ACPY3_VERSION_MACRO
static __inline
#endif
#if defined(ACPY3_SETFINAL_INLINE) || defined(ACPY3_INLINE_ALL) || \
    defined(ACPY3_SETFINAL_IMPLEMENTATION)

/*
 *  ======== ACPY3_setFinal ========
 */
Void ACPY3_setFinal(IDMA3_Handle restrict handle, short transferNo)
{
    ACPY3_PaRamRegs * restrict paRamCache;
    ACPY3_MoreEnv   * restrict env;
    unsigned char   * restrict tccTblPtr;
    unsigned short             numTotalPaRams;
    unsigned short             final;
    unsigned short             tcc;
    Int                        i, j;
    Int                        moreNumTccs;
    Int                        prevWaitIdOfFinal;
#if _ACPY3_DIRTY_BITS
    unsigned char   * restrict dirtyBitTblPtr;
#endif

#if defined(ACPY3_SETFINAL_IMPLEMENTATION)
    Log_print2(Diags_ENTRY, "[+E] ACPY3_setFinal> Enter "
            "(handle=0x%x, transferNo=%d)", (IArg)handle, (IArg)(transferNo ));

    Assert_isTrue(handle != NULL, (Assert_Id)NULL);
    Assert_isTrue(handle->env != NULL, (Assert_Id)NULL);
    Assert_isTrue(handle->protocol == &ACPY3_PROTOCOL, (Assert_Id)NULL);
#endif

    env = (ACPY3_MoreEnv *)handle->env;
    ACPY3_INSTR_CALLHOOKFXN(env->extendedHooks, handle, \
        ACPY3_INSTR_SETFINAL_ENTER);

    numTotalPaRams = env->numPaRams;
#if defined(ACPY3_SETFINAL_IMPLEMENTATION)
    Assert_isTrue((transferNo < numTotalPaRams) && (transferNo >= 0),
            (Assert_Id)NULL);
#endif

    /* The previous transfer number that was configured as final. */
    final = handle->numPaRams - 1;
    
#if defined(ACPY3_SETFINAL_IMPLEMENTATION)
    Log_print1(Diags_USER4, "[+4] ACPY3_setFinal> Previous "
            "final transfer number %d", (IArg)final);

#endif

    if ((numTotalPaRams == 1) || (transferNo == final)) {

#if defined(ACPY3_SETFINAL_IMPLEMENTATION)
        Log_print0(Diags_USER4, "[+4] ACPY3_setFinal> Final "
                "transfer same as before");
#endif

        /* Nothing to do */
        ACPY3_INSTR_CALLHOOKFXN(env->extendedHooks, handle, \
                ACPY3_INSTR_SETFINAL_EXIT);
#if defined(ACPY3_SETFINAL_IMPLEMENTATION)
        Log_print0(Diags_EXIT, "[+X] ACPY3_setFinal> Exit");
#endif

        return;
    }

#if defined(ACPY3_SETFINAL_IMPLEMENTATION)
    /* Following code makes this assumption. */
    Assert_isTrue(transferNo != final, (Assert_Id)NULL);
#endif

    tccTblPtr = handle->tccTable;

#if _ACPY3_DIRTY_BITS
    dirtyBitTblPtr = env->dirtyBitTable;
#endif

    /*
     *  Reset the link id of the previous transfer that was configured as
     *  final, unless it is the last PaRam allocated to the channel.
     */

    if (final < (numTotalPaRams - 1)) {
    /* 
        paRamCache = (ACPY3_PaRamRegs *)ACPY3_getPaRamCache(handle, final); 
     */
        paRamCache = (ACPY3_PaRamRegs *)env - (final + 1);

        prevWaitIdOfFinal = env->prevWaitIdOfFinal;

        paRamCache->link =
            (unsigned short)ACPY3_getPaRamLinkIndex(handle, final + 1);


        /*
         *  Clear the static bit since "final" is no longer the last transfer.
         *  Clear the old tcc and TCC_INTEN.
         */
        paRamCache->opt &= ~(ACPY3_TCCMASK |
                             ACPY3_PARAMOPTS_TCC_INTEN |
                             ACPY3_PARAMOPTS_STATIC);

        /*
         * If the previous "final" paRam used to have a waitId
         *  associated with it, restore that one.
         */
        if (prevWaitIdOfFinal >= 0)
        {
            tcc  = tccTblPtr[prevWaitIdOfFinal + 1];
            paRamCache->opt = ACPY3_TCCBITS(tcc)       |   /* TCC_CHAN */
                              ACPY3_PARAMOPTS_AB_SYNC  |
                              ACPY3_PARAMOPTS_TCC_INTEN;
        }

#if _ACPY3_DIRTY_BITS
        /* Mark the link field as dirty, since it has changed. */
        /* Mark the opt field as dirty */
        dirtyBitTblPtr[final] |= ACPY3_DIRTYOPTS | ACPY3_DIRTYLINK;
#endif

#if defined(ACPY3_SETFINAL_IMPLEMENTATION)
        Log_print2(Diags_USER2, "[+2] ACPY3_setFinal> Previous"
                " final transfer's link changed to 0x%x, OPT 0x%x",
                (IArg)(paRamCache->link), (IArg)(paRamCache->opt));
#endif
    }

    /*
     * Update the paRam cache for the new final transfer
     */

    /* 
     * paRamCache = (ACPY3_PaRamRegs *)ACPY3_getPaRamCache(handle, transferNo); 
     */
    paRamCache = (ACPY3_PaRamRegs *)env - (transferNo + 1);

    handle->numPaRams = transferNo + 1;

    /* Set up final transfer with no linking */
    paRamCache->link = 0xffff;

    /*
     *  Since this will be the last transfer, we need to use a tcc,
     *  whether or not the transfer was configured with a waitId >= 0.
     *
     *  Since the last transfer always uses the first tcc in the table,
     *  we update the opt field of the PaRam to use that. If the transfer
     *  was configured with a waitId >= 0, we must guarentee that when
     *  ACPY3_waitLinked() is called with that waitId, we use the first tcc.
     *  Therefore, we set handle->numWaits to waitId + 1.
     *  Determine if a TCC was set for this transfer by checking the
     *  TCC_INT_EN bit of the opts field. If so, extract the tcc and
     *  use it to determine the waitId so we can set numWaits.
     */

    //TODO: Add trace here 
    if (paRamCache->opt & ACPY3_PARAMOPTS_TCC_INTEN) {
        tcc = (paRamCache->opt & ACPY3_TCCMASK) >> ACPY3_TCCSHIFT;

#ifdef xdc_target__isaCompatible_64P
#pragma MUST_ITERATE(1)
#endif
        for (i = 0; i < env->numTccs; i++) {
            if (tccTblPtr[i] == tcc)
                break;
        }

        /* i = waitId + 1 */
#if defined(ACPY3_SETFINAL_IMPLEMENTATION)
        Assert_isTrue(i < env->numTccs, (Assert_Id)NULL);
#endif

        /*
         *  TCC used is handle->tccTable[waitId + 1], or tccTable[0]
         *  for the last transfer.
         */
        env->prevWaitIdOfFinal = i - 1;
    }
    else {
        /*
         *  This transfer is not a synchronization point, so we don't really
         *  care that handle->numWaits may be more than the actual number
         *  of calls to ACPY3_waitLinked().
         */
        env->prevWaitIdOfFinal = -1;
    }

    tcc = tccTblPtr[0];
    paRamCache->opt = ACPY3_TCCBITS(tcc)        |   /* TCC_CHAN */
                      ACPY3_PARAMOPTS_AB_SYNC   |
                      ACPY3_PARAMOPTS_TCC_INTEN |
                      ACPY3_PARAMOPTS_STATIC;

#if defined(ACPY3_SETFINAL_IMPLEMENTATION)
    Log_print2(Diags_USER2, "[+2] ACPY3_setFinal> Final "
            "transfer's link changed to 0x%x OPT set to 0x%x",
            (IArg)(paRamCache->link), (IArg)(paRamCache->opt));
#endif


#if _ACPY3_DIRTY_BITS
    /* Mark the opts field of the PaRam for this transfer as dirty. */
    dirtyBitTblPtr[transferNo] |= ACPY3_DIRTYLINK | ACPY3_DIRTYOPTS;
#endif

    /*
     * Determine total number of tccs
     */
    //TODO: Add trace here
    if (((moreNumTccs = env->numTccs) > 1) && (handle->numPaRams > 1)) {

        /* Determine highest intermediate tcc */
#ifdef xdc_target__isaCompatible_64P
#pragma MUST_ITERATE(1)
#endif
        for (j = handle->numPaRams - 1; j > 0; j--) {
            paRamCache++;
            if (paRamCache->opt & ACPY3_PARAMOPTS_TCC_INTEN) {
                tcc = (paRamCache->opt & ACPY3_TCCMASK) >> ACPY3_TCCSHIFT;
                /* Skip over tccTable[0] because it's only used
                 * for the "final" paRam.
                 */
#ifdef xdc_target__isaCompatible_64P
#pragma MUST_ITERATE(1)
#endif
                for (i = 1; i < moreNumTccs; i++) {
                    if (tccTblPtr[i] == tcc) {
                        handle->numTccs = i + 1;
                        return;
                    }
                }
            }
        }
    }
    handle->numTccs = 1;

    ACPY3_INSTR_CALLHOOKFXN(env->extendedHooks, handle, \
            ACPY3_INSTR_SETFINAL_EXIT);

#if defined(ACPY3_SETFINAL_IMPLEMENTATION)
    Log_print0(Diags_EXIT, "[+X] ACPY3_setFinal> Exit");
#endif

}
#endif /* if defined(ACPY3_SETFINAL_INLINE) || defined(ACPY3_INLINE_ALL) ||
       ** defined(ACPY3_SETFINAL_IMPLEMENTATION)
       */
#endif /* _ACPY3_SETFINAL_ */
#else
#error "ti/sdo/fc/acpy3/acpy3.h must be included first"
#endif
/*
 *  @(#) ti.sdo.fc.acpy3; 1, 0, 4,4; 2-22-2012 18:03:28; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

