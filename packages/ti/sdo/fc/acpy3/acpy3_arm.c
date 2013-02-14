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
 *  ======== acpy3_arm.c ========
 */

/* This difine must precede inclusion of any xdc header files */
#define Registry_CURDESC ti_sdo_fc_acpy3_desc

#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Registry.h>

/* For creating a gate */
#include <xdc/runtime/IGateProvider.h>
#include <ti/sdo/fc/utils/osalsupport/OsalSupport.h>

#include "acpy3.h"
#include "acpy3_util.h"
#include "acpy3_qdma_arm.h"
#include <ti/xdais/idma3.h>
//#include <ti/sdo/fc/dman3/DMAN3CFG.h> /* Note - unfortunate DMAN3 dependency! */ // TODO: (jeh)


#define PARAMSIZE (ACPY3_PARAMENTRYSIZE * sizeof(Uns))

/*
 *  Cache PaRams must be aligned on 32 bytes.
 */
#define PARAMREGS_ALIGN 32

static Bool ACPY3_deInitEnv(IDMA3_Handle handle);
static Bool ACPY3_initEnv(IDMA3_Handle handle);
static Void ACPY3_getEnvMem(IDMA3_ChannelRec *dmaTab, IDMA3_MemRec *memRec);

#define FIELD_OFFSET(c,f) ((Int)(&((c *)0)->f))

#define verifyOffset(offset, structName, field) \
        (offset == FIELD_OFFSET(structName,field))

static Void initQdmaSettings(Void);
static Void _ACPY3_init();
static Void _ACPY3_exit();
static Int refCount  = 0;

IDMA3_Handle  _ACPY3_qchLockTbl[_ACPY3_NUMQDMACHANNELS];

/*
** This is used to ensure that routines that were previously compiled
** with inline ACPY3 functions are compatible with the current version
** of ACPY3.
** Therefore, whenever the ACPY3 code is modified such that it is no
** longer compatible with the previous inline versions, the final
** two digits of __ACPY3_inlineCompatibilityKey_NN should be incremented.
*/
Bool ACPY3_INLINE_COMPATIBILITY_KEY_NAME;
/*
 * Make sure the compiler setting for _ACPY3_DIRTY_BITS is the same for
 * previously compiled inline and non-inline
 */
Bool ACPY3_DIRTY_BITS_VERSION_NAME;

IGateProvider_Handle _ACPY3_gate = NULL;

extern UInt32 ti_sdo_fc_acpy3_ACPY3_ipcKeyBase;

#ifndef _ACPY3_CPUCOPY_
extern Uint32 *_DMAN3_edma3Addr;

Void _ACPY3_qdmaInit(); 
#endif

/*
 *  ======== ACPY3_PROTOCOL ========
 *  ACPY3 channel access protocol for initializing environment.
 */
IDMA3_ProtocolObj ACPY3_PROTOCOL = {
    "acpy3",
    ACPY3_getEnvMem,
    ACPY3_initEnv,
    ACPY3_deInitEnv,
};

extern Registry_Desc ti_sdo_fc_acpy3_desc;

/*
 *  ======== _ACPY3_exit ========
 *  Finalize the ACPY3 module
 */
static Void _ACPY3_exit(Void)
{
    Log_print0(Diags_ENTRY, "[+E] _ACPY3_exit > Enter");

    refCount--;

    if (refCount == 0) {
#ifndef _ACPY3_CPUCOPY_
        if (_ACPY3_gate != NULL) {
            OsalSupport_deleteGate(_ACPY3_gate);
        }
#endif
    }

    Log_print0(Diags_EXIT, "[+X] _ACPY3_exit > Enter");
}

/*
 *  ======== _ACPY3_init ========
 *  Initialize the ACPY3 module
 */
static void _ACPY3_init(Void)
{
    Log_print0(Diags_ENTRY, "[+E] _ACPY3_init > Enter");


    if (refCount == 0) {

#ifndef _ACPY3_CPUCOPY_
        _ACPY3_gate = OsalSupport_createGate(ti_sdo_fc_acpy3_ACPY3_ipcKeyBase);
        if (_ACPY3_gate == NULL) {
            Log_print0(Diags_USER7,
                    "[+7] _ACPY3_init > Failed to create gate!");
        }

        /*
         *  Create a Gate. Arm side needs a gate to protect registers in a
         *  multi-process environment.
         */

        _ACPY3_qdmaInit();
#endif
        initQdmaSettings();

#ifndef _ACPY3_CPUCOPY_
#endif
    }

     /* count references even if no allocation is done */
     /* so that memory free is done only when last node requires ACPY3 */
    refCount++;

    Assert_isTrue(verifyOffset(ACPY3_PARAMFIELD_ELEMENTSIZE,
                            ACPY3_PaRamRegs, acnt), (Assert_Id)NULL);
    Assert_isTrue(verifyOffset(ACPY3_PARAMFIELD_NUMELEMENTS,
            ACPY3_PaRamRegs, bcnt), (Assert_Id)NULL);
    Assert_isTrue(verifyOffset(
            ACPY3_PARAMFIELD_ELEMENTINDEX_SRC, ACPY3_PaRamRegs,
            srcElementIndex), (Assert_Id)NULL);
    Assert_isTrue(verifyOffset(
            ACPY3_PARAMFIELD_ELEMENTINDEX_DST, ACPY3_PaRamRegs,
            dstElementIndex), (Assert_Id)NULL);
    Assert_isTrue(verifyOffset(
            ACPY3_PARAMFIELD_FRAMEINDEX_SRC, ACPY3_PaRamRegs, srcFrameIndex),
            (Assert_Id)NULL);
    Assert_isTrue(verifyOffset(
            ACPY3_PARAMFIELD_FRAMEINDEX_DST, ACPY3_PaRamRegs, dstFrameIndex),
            (Assert_Id)NULL);
    Assert_isTrue(verifyOffset(ACPY3_PARAMFIELD_NUMFRAMES,
            ACPY3_PaRamRegs, ccnt), (Assert_Id)NULL);
    Assert_isTrue(verifyOffset(ACPY3_PARAMFIELD_SRCADDR, ACPY3_PaRamRegs, src),
            (Assert_Id)NULL);
    Assert_isTrue(verifyOffset(ACPY3_PARAMFIELD_DSTADDR, ACPY3_PaRamRegs, dst),
            (Assert_Id)NULL);

    Log_print0(Diags_EXIT, "[+X] _ACPY3_init > Exit");
}

/*
 *  ======== ACPY3_initQdmaSettings ========
 */
static Void initQdmaSettings(Void)
{
#ifndef _ACPY3_CPUCOPY_
    Int     i;

    Log_print0(Diags_ENTRY, "[+E] initQdmaSettings> Enter");

    /* unlock all qdma channels */
    for (i = 0; i < _ACPY3_NUMQDMACHANNELS; i++) {
        _ACPY3_qchLockTbl[i] = 0;
    }
#else
    Log_print0(Diags_ENTRY, "[+E] initQdmaSettings> Enter");
#endif
    Log_print0(Diags_EXIT, "[+X] initQdmaSettings > Exit");
}



/*
 *  ======== ACPY3_deInitEnv ========
 */
static Bool ACPY3_deInitEnv(IDMA3_Handle handle)
{
    Void   *scratchEnv;

    Log_print1(Diags_ENTRY, "[+E] ACPY3_deInitEnv > Enter (handle=0x%x)",
            (IArg)handle);

    Assert_isTrue(handle->protocol == &ACPY3_PROTOCOL, (Assert_Id)NULL);

    scratchEnv = ((ACPY3_MoreEnv *)(handle->env))->scratchEnv;

    if (scratchEnv != NULL) {
        scratchEnv = (Void *)((Uns)scratchEnv - handle->numPaRams * PARAMSIZE);
    }

    /*
     *  Restore original values of numTccs and numPaRams, since
     *  ACPY3_setFinal() may have changed them.
     */
    handle->numTccs = ((ACPY3_MoreEnv *)(handle->env))->numTccs;
    handle->numPaRams = ((ACPY3_MoreEnv *)(handle->env))->numPaRams;

    /* Restore env pointer */
    handle->env = (Void *)((Uns)handle->env - handle->numPaRams * PARAMSIZE);

    /* Restore scratch env pointer */
    *((unsigned *)(handle->env)) = (unsigned)scratchEnv;

    _ACPY3_exit();

    Log_print0(Diags_ENTRY, "[+E] ACPY3_deInitEnv > Enter (status=TRUE)");

    return (TRUE);
}

/*
 *  ======== ACPY3_getEnvMem ========
 */
static Void ACPY3_getEnvMem(IDMA3_ChannelRec *dmaTab, IDMA3_MemRec *memRec)
{
    /*
     *  Be aware that _ACPY3_init() may not have been called at this
     *  point!
     */

    Log_print2(Diags_ENTRY, "[+E] ACPY3_getEnvMem> Enter "
            "(dmaTab=0x%x, memRec=0x%x)", (IArg)dmaTab, (IArg)memRec);

    memRec->memType = IDMA3_INTERNAL;

    /*
     *  Size of env:
     *     numTransfers cache PaRam registers
     *     + 2 'unsigned short' for numTransfers and numTccs
     *     + 1 'short' for prevWaitIdOfFinal
     *     + numTransfers words for dirty bits.
     */
    /***** TO DO: Make size a multiple of 4 bytes *****/
    memRec->size = sizeof(ACPY3_MoreEnv) +
                   (dmaTab->numTransfers * (sizeof(ACPY3_PaRamRegs)));

    memRec->align = PARAMREGS_ALIGN;

    Log_print0(Diags_EXIT, "[+X] ACPY3_getEnvMem> Exit");
}

/*
 *  ======== ACPY3_initEnv ========
 */
static Bool ACPY3_initEnv(IDMA3_Handle handle)
{
    Uns     tcc;
    Uns     maskL;
    Uns     maskH;
    Void   *scratchEnv;
    Int     i;

    Log_print1(Diags_ENTRY, "[+E] ACPY3_initEnv> Enter (handle=0x%x)",
            (IArg)handle);

    _ACPY3_init();

    /*
     *  *(handle->env) has been initialized to a scratch buffer in internal
     *  memory, while handle->env is the persistent env.
     */
    scratchEnv = (Void *)(*(unsigned *)(handle->env));

    /*
     *  Move env to be immediately after paRam cache.
     */
    handle->env = (Void *)((Uns)handle->env + handle->numPaRams * PARAMSIZE);

    if (scratchEnv != NULL) {
        scratchEnv = (Void *)((Uns)scratchEnv + handle->numPaRams * PARAMSIZE);
    }

    ((ACPY3_MoreEnv *)(handle->env))->scratchEnv = scratchEnv;
    ((ACPY3_MoreEnv *)(handle->env))->persistEnv = handle->env;

    /*
     * Fill in the mask values for the final TCC.
     */
    tcc = handle->tccTable[0];

    if (tcc >= 32) {
#ifndef _ACPY3_CPUCOPY_
        ((ACPY3_MoreEnv *)(handle->env))->iprRegister = (Uns *)ACPY3_QDMA_IPRH;
#endif
        ((ACPY3_MoreEnv *)(handle->env))->iprMask = 0x1 << (tcc - 32);
    }
    else {
#ifndef _ACPY3_CPUCOPY_
        ((ACPY3_MoreEnv *)(handle->env))->iprRegister = (Uns *)ACPY3_QDMA_IPR;
#endif
        ((ACPY3_MoreEnv *)(handle->env))->iprMask = 0x1 << tcc;
    }

    /*
     * Fill in the mask values for clearing the whole set of TCCs.
     */
    maskH = maskL = 0;
    for (i = 0; i < handle->numTccs; i++) {
        tcc = handle->tccTable[i];
        if (tcc >= 32) {
            maskH |= 0x1 << (tcc - 32);
        }
        else {
            maskL |= 0x1 << tcc;
        }
    }
    ((ACPY3_MoreEnv *)(handle->env))->icrlMask = maskL;
    ((ACPY3_MoreEnv *)(handle->env))->icrhMask = maskH;

    /*
     *  Save a copy of original values of numTccs and numPaRams, since
     *  ACPY3_setFinal() will need to change them.
     */
    ((ACPY3_MoreEnv *)(handle->env))->numTccs = handle->numTccs;
    ((ACPY3_MoreEnv *)(handle->env))->numPaRams = handle->numPaRams;
    ((ACPY3_MoreEnv *)(handle->env))->prevWaitIdOfFinal = -1; /* i.e. none */

    Log_print0(Diags_EXIT, "[+X] ACPY3_initEnv> Exit (status=TRUE)");

    return (TRUE);
}

/*
 *  @(#) ti.sdo.fc.acpy3; 1, 0, 4,4; 2-22-2012 18:03:27; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

