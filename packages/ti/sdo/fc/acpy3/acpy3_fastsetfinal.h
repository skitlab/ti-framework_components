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
 *  ======== acpy3_fastsetfinal.h ========
 */


#ifdef _ACPY3_

#ifndef _ACPY3_FASTSETFINAL_
#define _ACPY3_FASTSETFINAL_

#include <ti/xdais/idma3.h>
#include <ti/sdo/fc/acpy3/acpy3_util.h>
#include <ti/sdo/fc/acpy3/acpy3.h>
#include <ti/sdo/fc/utils/dbc.h>

#if defined(ACPY3_FASTSETFINAL_INLINE) || defined(ACPY3_INLINE_ALL)
ACPY3_VERSION_MACRO
static __inline
#endif
#if defined(ACPY3_FASTSETFINAL_INLINE) || defined(ACPY3_INLINE_ALL) || \
    defined(ACPY3_FASTSETFINAL_IMPLEMENTATION)

/*
 *  ======== ACPY3_fastSetFinal ========
 */
Void ACPY3_fastSetFinal(IDMA3_Handle restrict handle, short transferNo)
{
    ACPY3_PaRamRegs * restrict paRamCacheOld;
    ACPY3_PaRamRegs * restrict paRamCacheNew;
    ACPY3_MoreEnv   * restrict env;
    short                      transferNoP1;
    short                      finalP1;
#if _ACPY3_DIRTY_BITS
    short                      final;
    unsigned char   * restrict dirtyBitTblPtr;
#endif

#if defined(ACPY3_FASTSETFINAL_IMPLEMENTATION)
    Log_print2(Diags_ENTRY, "[+E] ACPY3_fastSetFinal> Enter "
            "(handle=0x%x, transferNo=%d)", (IArg)handle, (IArg)transferNo);


    DBC_require(handle != NULL);
    DBC_require(handle->env != NULL);
    DBC_require(handle->protocol == &ACPY3_PROTOCOL);
    DBC_require((transferNo < ((ACPY3_MoreEnv *)(handle->env))->numPaRams) &&
                (transferNo >= 0));
    /* The handle is only allowed a single TCC */
    DBC_require(((ACPY3_MoreEnv *)(handle->env))->numTccs == 1);

    Assert_isTrue(handle != NULL, (Assert_Id)NULL);
    Assert_isTrue(handle->env != NULL, (Assert_Id)NULL);
    Assert_isTrue(handle->protocol == &ACPY3_PROTOCOL, (Assert_Id)NULL);
    Assert_isTrue((transferNo < ((ACPY3_MoreEnv *)(handle->env))->numPaRams) &&
            (transferNo >= 0), (Assert_Id)NULL);
    /* The handle is only allowed a single TCC */
    Assert_isTrue(((ACPY3_MoreEnv *)(handle->env))->numTccs == 1,
            (Assert_Id)NULL);
#endif /* if defined(ACPY3_FASTSETFINAL_IMPLEMENTATION) */

    env = (ACPY3_MoreEnv *)handle->env;

    ACPY3_INSTR_CALLHOOKFXN(env->extendedHooks, handle,
            ACPY3_INSTR_SETFASTFINAL_ENTER);

    /* The previous transfer number that was configured as final. */
    finalP1 = (short)handle->numPaRams;
    transferNoP1 = transferNo + 1;
    handle->numPaRams = transferNoP1;

#if defined(ACPY3_FASTSETFINAL_IMPLEMENTATION)
    Log_print2(Diags_USER2, "[+2] ACPY3_fastSetFinal> Previous"
            "final transfer %d Number of paRams %d",
            (IArg)finalP1, (IArg)transferNoP1);
#endif /* if defined(ACPY3_FASTSETFINAL_IMPLEMENTATION) */

#if _ACPY3_DIRTY_BITS
    final = finalP1 - 1;
#endif

    /* paRamCacheOld = (ACPY3_PaRamRegs *)ACPY3_getPaRamCache(handle,final); */
    /* paRamCacheNew = (ACPY3_PaRamRegs *)ACPY3_getPaRamCache(handle,
    transferNo); */
    paRamCacheOld = (ACPY3_PaRamRegs *)env - finalP1;
    paRamCacheNew = (ACPY3_PaRamRegs *)env - transferNoP1;

#if _ACPY3_DIRTY_BITS
    dirtyBitTblPtr = env->dirtyBitTable;
#endif

    /*
     *  Reset the link id of the previous transfer that was configured as
     *  final, unless it is the last PaRam allocated to the channel.
     */

    paRamCacheOld->link =
        (unsigned short)ACPY3_getPaRamLinkIndex(handle, finalP1);

#if defined(ACPY3_FASTSETFINAL_IMPLEMENTATION)
    Log_print1(Diags_USER2, "[+2] ACPY3_fastSetFinal> Reset "
            " the link id of the previous final paRam 0x%x",
            (IArg)(paRamCacheOld->link));
#endif /* if defined(ACPY3_FASTSETFINAL_IMPLEMENTATION) */

    /*
     *  Clear the static bit since "final" is no longer the last transfer.
     *  Clear the old tcc and TCC_INTEN.
     */
    paRamCacheOld->opt &= ~(ACPY3_TCCMASK             |
                            ACPY3_PARAMOPTS_TCC_INTEN |
                            ACPY3_PARAMOPTS_STATIC);

#if defined(ACPY3_FASTSETFINAL_IMPLEMENTATION)
    Log_print1(Diags_USER2, "[+2] ACPY3_fastSetFinal> Set the"
            " OPT of the previous final paRam 0x%x",
            (IArg)(paRamCacheOld->opt));
#endif /* if defined(ACPY3_FASTSETFINAL_IMPLEMENTATION) */

    /*
     * Update the paRam cache for the new final transfer.
     * Set up final transfer with no linking.
     */

    paRamCacheNew->link = 0xffff;

#if defined(ACPY3_FASTSETFINAL_IMPLEMENTATION)
    Log_print1(Diags_USER2, "[+2] ACPY3_fastSetFinal> Set the"
            " link of the new final paRam 0x%x", (IArg)(paRamCacheNew->link));
#endif /* if defined(ACPY3_FASTSETFINAL_IMPLEMENTATION) */

    /*
     *  Since this will be the last transfer, we need to use a tcc.
     *  Since the last transfer always uses the first tcc in the table,
     *  we update the opt field of the PaRam to use that.
     */

    paRamCacheNew->opt = ACPY3_TCCBITS(handle->tccTable[0]) |   /* TCC_CHAN */
                         ACPY3_PARAMOPTS_AB_SYNC            |
                         ACPY3_PARAMOPTS_TCC_INTEN          |
                         ACPY3_PARAMOPTS_STATIC;

#if defined(ACPY3_FASTSETFINAL_IMPLEMENTATION)
    Log_print1(Diags_USER2, "[+2] ACPY3_fastSetFinal> Set the"
            " OPT of the new final paRam 0x%x", (IArg)(paRamCacheNew->opt));
#endif /* if defined(ACPY3_FASTSETFINAL_IMPLEMENTATION) */

#if _ACPY3_DIRTY_BITS
    /* Mark the link field as dirty, since it has changed. */
    dirtyBitTblPtr[final] |= ACPY3_DIRTYLINK;

    /* Mark the opts field of the PaRam for this transfer as dirty. */
    dirtyBitTblPtr[transferNo] |= ACPY3_DIRTYLINK | ACPY3_DIRTYOPTS;
#endif
    ACPY3_INSTR_CALLHOOKFXN(env->extendedHooks, handle,
            ACPY3_INSTR_SETFASTFINAL_EXIT);

#if defined(ACPY3_FASTSETFINAL_IMPLEMENTATION)
    Log_print0(Diags_EXIT, "[+X] ACPY3_fastSetFinal> Exit");
#endif /* if defined(ACPY3_FASTSETFINAL_IMPLEMENTATION) */
}
#endif /* if defined(ACPY3_FASTSETFINAL_INLINE) ||
       **    defined(ACPY3_INLINE_ALL) ||
       **    defined(ACPY3_FASTSETFINAL_IMPLEMENTATION)
       */
#endif /* _ACPY3_FASTSETFINAL_ */
#else
#error "ti/sdo/fc/acpy3/acpy3.h must be included first"
#endif

/*
 *  @(#) ti.sdo.fc.acpy3; 1, 0, 4,4; 2-22-2012 18:03:28; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

