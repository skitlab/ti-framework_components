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
 *  ======== dman3_api.c ========
 *  DMA Resource manager and utilities for granting logical channel
 *  resources to algorithms.
 */

/* This difine must precede inclusion of any xdc header files */
#define Registry_CURDESC ti_sdo_fc_dman3_desc

#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/IGateProvider.h>
#include <xdc/runtime/Registry.h>

#include "dman3.h"
#include "dman3_impl.h"
#include "rmm.h"

#include <ti/xdais/idma3.h>
#include <ti/sdo/fc/global/gt_dais.h>


#ifdef __TI_COMPILER_VERSION__

#pragma CODE_SECTION(DMAN3_grantDmaChannels, ".text:DMAN3_grantDmaChannels");
#pragma CODE_SECTION(DMAN3_releaseDmaChannels,".text:DMAN3_releaseDmaChannels");

#pragma CODE_SECTION(DMAN3_createChannels, ".text:DMAN3_createChannels");
#pragma CODE_SECTION(DMAN3_freeChannels, ".text:DMAN3_freeChannels");

#endif


extern Uint32 *_DMAN3_paRamAddr;
extern Uint32 * _DMAN3_edma3Addr;
extern UInt32 _DMAN3_maxAssignedTcc;

/*
 *  Number of words and MAUs in one PaRam entry. PARAMSIZEMAUS should be
 *  sizeof(ACPY3_PaRamRegs), but use #define since we can't include ACPY3
 *  header file here.
 */
#define PARAMSIZE 8
#define PARAMSIZEMAUS (PARAMSIZE * sizeof(Int))

/*
 *  ======== DMAN3_ChannelObj ========
 *  Structure to store a handle to the DMAN3 context object that
 *  was used to create the IDMA3 channel.
 */
typedef struct DMAN3_ChannelObj {
    IDMA3_Obj                idmaChan;
    DMAN3_Context            context;
    xdc_runtime_IHeap_Handle segEnv;  /* Heap where env is allocated */
    Uint16                   sizeEnv; /* size of env */
} DMAN3_ChannelObj, *DMAN3_Channel;


static Bool checkDMAN3Configuration();
static Int  createChannels(DMAN3_Context context, IALG_Handle alg, Int groupId,
                           IDMA3_ChannelRec dmaTab[], Int numChans);

static Int  createContext(DMAN3_Context *pContext, Int groupId, Int nTccs,
                       Int nPaRams, Int scratchId);
static Void freeChannels(IDMA3_ChannelRec dmaTab[], Int numChan);
static Void freeContext(DMAN3_Context context);
static Void freeScratch(Int groupId, IALG_MemRec memTab[], Int numRecs);
static Int  getContext(DMAN3_Context *pContext, Int groupId, Int nTccs,
        Int nPaRams);

static Bool initHandle(IDMA3_Handle handle, IDMA3_ChannelRec *dmaTab,
        Uint8 *tccList, Uns qdmaChannel, Int16 envSize, Void *env,
        Void *scratchEnv, xdc_runtime_IHeap_Handle envSeg,
        DMAN3_Context context);
static Void *myMalloc(xdc_runtime_IHeap_Handle heap, SizeT size, SizeT align,
        Error_Block *dummy);

static Bool checkedConfig = FALSE;

extern IGateProvider_Handle DMAN3_gate;

extern Registry_Desc ti_sdo_fc_dman3_desc;

/*
 *  ======== DMAN3_createChannels ========
 *  Allocate and initialize memory for channel handle.
 */
Int DMAN3_createChannels(Int groupId, IDMA3_ChannelRec dmaTab[], Int numChans)
{
    Int             i, j;
    DMAN3_Context   context;
    Int             maxWaits = 0;
    Int             maxTransfers = 0;
    Int             status = DMAN3_SOK;
    Uns             * gtPaRamAddr = NULL;
    IArg            key;

    Assert_isTrue(groupId < DMAN3_MAXGROUPS, (Assert_Id)NULL);
    Assert_isTrue(numChans >= 0, (Assert_Id)NULL);
    Assert_isTrue((dmaTab != NULL) || (numChans == 0), (Assert_Id)NULL);

    /* Check that DMAN3 is properly initialized before continuing */
    if (_DMAN3_initStatus != DMAN3_SOK) {
        Log_print1(Diags_USER7, "[+7] DMAN3_createChannels> DMAN3 not "
                "initialization failed: %d Exit (status=DMAN3_EFAIL)",
                _DMAN3_initStatus);
        return (DMAN3_EFAIL);
    }

    Log_print3(Diags_ENTRY, "[+E] DMAN3_createChannels> Enter (groupId=%d, "
            "dmaTab=0x%x, numChans=%d",
            (IArg)groupId, (IArg)dmaTab, (IArg)numChans);

    if (numChans < 1) {
        return (DMAN3_SOK);
    }

    if (!(checkedConfig)) {
        if (FALSE == checkDMAN3Configuration()) {
            Log_print0(Diags_EXIT,
                    "[+7] DMAN3_createChannels> Bad DMAN3 Configuration. "
                    "Exit (status=DMAN3_EFAIL)");
            return (DMAN3_EFAIL);
        }
        checkedConfig = TRUE;
    }

    /*
     *  Get the maximum number of waits and transfers to see how many
     *  PaRams and TCCs are needed.
     */
    for (i = 0; i < numChans; i++) {
        Assert_isTrue(dmaTab[i].numWaits >= 0, (Assert_Id)NULL);
        Assert_isTrue(dmaTab[i].numTransfers > 0, (Assert_Id)NULL);

        dmaTab[i].handle = NULL;
        maxWaits += dmaTab[i].numWaits;
        maxTransfers += dmaTab[i].numTransfers;
    }

    Log_print3(Diags_USER4, "[+4] DMAN3_createChannels> "
            "Total Qdma channels requested %d, PaRams requested %d, "
            "Tccs requested %d",
            (IArg)numChans, (IArg)maxTransfers, (IArg)maxWaits);

//    key = Gate_enterModule();
    key = IGateProvider_enter(DMAN3_gate);

    /* Get the context for this group ID, or create a new one. */
    status = getContext(&context, groupId, maxWaits, maxTransfers);

    Log_print1(Diags_USER2, "[+2] DMAN3_createChannels> Context 0x%x",
            (IArg)context);

    /* Now create the channels */
    if (status == DMAN3_SOK) {
        status = createChannels(context, NULL, groupId, dmaTab, numChans);
    }

    if (status == DMAN3_SOK) {

        for (i = 0; i < numChans; i++) {

            Log_print1(Diags_USER4, "[+4] DMAN3_createChannels> Assigned Qdma: %d",
                    (IArg)(dmaTab[i].handle->qdmaChan));

            Log_print0(Diags_USER4,
                    "[+4] DMAN3_createChannels> Assigned PaRam(s):");

            gtPaRamAddr = dmaTab[i].handle->paRamAddr;

            Log_print2(Diags_USER2, "[+2] DMAN3_createChannels> "
                    "dmaTab[%d].handle's paRamAddr 0x%x",
                    (IArg)i, (IArg)gtPaRamAddr);

            for (j = 0; j < dmaTab[i].handle->numPaRams; j++) {

                Log_print2(Diags_USER4, "[+4] DMAN3_createChannels> %d (Addr 0x%x)",
                        (IArg)(((Uns)gtPaRamAddr - (Uns)_DMAN3_paRamAddr) /
                        PARAMSIZEMAUS), (IArg)gtPaRamAddr);
                gtPaRamAddr -= (PARAMSIZE);
            }

            Log_print0(Diags_USER4, "[+4] DMAN3_createChannels> Assigned Tcc(s):");

            for (j = 0; j < dmaTab[i].handle->numTccs; j++) {
                Log_print1(Diags_USER4, "[+4] DMAN3_createChannels> %d",
                        (IArg)(dmaTab[i].handle->tccTable[j]));
            }
        }
    }

//    Gate_leaveModule(key);
    IGateProvider_leave(DMAN3_gate, key);

    Log_print1(Diags_EXIT, "[+X] DMAN3_createChannels> Exit (return=%d)",
            (IArg)status);

    return (status);
}

/*
 *  ======== DMAN3_grantDmaChannels ========
 *  Add an algorithm to the DMA Manager.  The DMA Manager will grant DMA
 *  resources to the algorithm as a result.  This function is called when
 *  initializing an algorithm instance.
 */
Int DMAN3_grantDmaChannels(Int groupId, IALG_Handle algHandle[],
        IDMA3_Fxns *dmaFxnsArray[], Int numAlgs)
{
    Uns              numChans;
    Int              maxChans = 0;
    Int              i, j, k;
    IALG_Handle      alg;
    IDMA3_Fxns      *dmaFxns;
    IDMA3_ChannelRec *dmaTab;
    Int              dmaTabSize;
    Int              maxWaits = 0;
    Int              maxTransfers = 0;
    Int              nWaits = 0;
    Int              nTransfers = 0;
    DMAN3_Context    context;
    Int              status = DMAN3_EFAIL;
    Uns             *gtPaRamAddr = NULL;
    IArg             key;

    Assert_isTrue(algHandle != NULL, (Assert_Id)NULL);
    Assert_isTrue(dmaFxnsArray != NULL, (Assert_Id)NULL);
    Assert_isTrue(numAlgs > 0, (Assert_Id)NULL);
    Assert_isTrue(groupId < DMAN3_MAXGROUPS, (Assert_Id)NULL);

    Log_print4(Diags_ENTRY, "[+E] DMAN3_grantDmaChannels> "
            "Enter (groupId=%d, algHandle=0x%x, dmaFxns=0x%x, numAlgs=%d)",
            (IArg)groupId, (IArg)algHandle, (IArg)dmaFxnsArray,
            (IArg)numAlgs);

    /* Check that DMAN3 is properly initialized before continuing */
    if (_DMAN3_initStatus != DMAN3_SOK) {
        Log_print1(Diags_USER7, "[+7] DMAN3_grantDmaChannels> DMAN3 not "
                "initialization failed: %d Exit (status=DMAN3_EFAIL)",
                _DMAN3_initStatus);
        return (DMAN3_EFAIL);
    }

    if (!(checkedConfig)) {
        if (FALSE == checkDMAN3Configuration()) {
            Log_print0(Diags_EXIT,
                    "[+7] DMAN3_grantDmaChannels> Bad DMAN3 Configuration. "
                    "Exit (status=DMAN3_EFAIL)");
            return (DMAN3_EFAIL);
        }
        checkedConfig = TRUE;
    }

    /*
     *  Use dynamic allocation instead of stack to avoid large array on
     *  stack. First we need to figure out the largest number of channels
     *  requested by any one of the algorithms.
     */
    for (i = 0; i < numAlgs; i++) {
        alg = algHandle[i];
        dmaFxns = dmaFxnsArray[i];

        Assert_isTrue(alg != NULL, (Assert_Id)NULL);
        Assert_isTrue(dmaFxns != NULL, (Assert_Id)NULL);

        /* alg and idma3 fxns must be from same implementation */
        Assert_isTrue(dmaFxns->implementationId == alg->fxns->implementationId,
                (Assert_Id)NULL);

        numChans = dmaFxns->dmaGetChannelCnt();
        maxChans = (numChans > maxChans) ? numChans : maxChans;
    }

    if (maxChans == 0) {
        /* Don't allocate anything if no algorithm uses dma */
        return (DMAN3_SOK);
    }

    dmaTabSize = sizeof(IDMA3_ChannelRec) * maxChans;

    dmaTab = (IDMA3_ChannelRec *)myMalloc(_DMAN3_heapExt, dmaTabSize,
            sizeof(Int), NULL);

    if (dmaTab == NULL) {
        Log_print0(Diags_EXIT,
                "[+X] DMAN3_grantDmaChannels> Exit (status=DMAN3_EOUTOFMEMORY)");
        return (DMAN3_EOUTOFMEMORY);
    }

    /*
     *  Determine the maximum number of TCCs and PaRams that will be needed
     *  by this group of algorithms.
     */
    for (i = 0; i < numAlgs; i++) {

        alg = algHandle[i];
        dmaFxns = dmaFxnsArray[i];
        numChans = dmaFxns->dmaGetChannels(alg, dmaTab);

        /* Total number of PaRams and TCCs needed by the algorithm */
        nWaits = nTransfers = 0;

        /* TODO:L  should additionally dump dmaTab? */
        for (j = 0; j < numChans; j++) {

            dmaTab[j].handle = NULL;
            Assert_isTrue(dmaTab[j].numWaits >= 0, (Assert_Id)NULL);
            Assert_isTrue(dmaTab[j].numTransfers > 0, (Assert_Id)NULL);

            maxWaits += dmaTab[j].numWaits;
            nWaits += dmaTab[j].numWaits;

            maxTransfers += dmaTab[j].numTransfers;
            nTransfers += dmaTab[j].numTransfers;
        }

        Log_print1(Diags_USER4, "[+4] DMAN3_grantDmaChannels> Alg 0x%x:",
                (IArg)alg);

        Log_print4(Diags_USER4, "[+4] DMAN3_grantDmaChannels> "
                "Channels requested by alg[%d]: %d, PaRams requested %d, "
                "Tccs requested %d",
                (IArg)i, (IArg)numChans, (IArg)nTransfers, (IArg)nWaits);

        /*
         * Note, we check tccs here, but can't check PaRams because it's a
         * more complex check... and it's done in getContext().
         */
        if (maxWaits > _DMAN3_numAssignedTccs) {

            Memory_free(_DMAN3_heapExt, dmaTab, dmaTabSize);
            Log_print0(Diags_EXIT,
                    "[+X] DMAN3_grantDmaChannels> Exit (status=EOUTOFTCCS)");
            return (DMAN3_EOUTOFTCCS);
        }
    }

    key = IGateProvider_enter(DMAN3_gate);

    /* Get the context for this group, or create a new one. */
    status = getContext(&context, groupId, maxWaits, maxTransfers);

    Log_print1(Diags_USER2, "[+2] DMAN3_grantDmaChannels> Context 0x%x",
            (IArg)context);

    if (status == DMAN3_SOK) {
        for (i = 0; i < numAlgs; i++) {
            alg = algHandle[i];
            dmaFxns = dmaFxnsArray[i];

            Assert_isTrue(alg != NULL, (Assert_Id)NULL);
            Assert_isTrue(dmaFxns != NULL, (Assert_Id)NULL);

            /*  alg and idma3 fxns must be from same implementation */
            Assert_isTrue(dmaFxns->implementationId ==
                    alg->fxns->implementationId, (Assert_Id)NULL);

            numChans = dmaFxns->dmaGetChannels(alg, dmaTab);
            if (numChans < 1) {
                /* This alg requests no channels - that's ok. */
                continue;
            }

            status = createChannels(context, alg, groupId, dmaTab, numChans);

            if ((status == DMAN3_SOK)) {

                if ((status = dmaFxns->dmaInit(alg, dmaTab)) != IALG_EOK) {
                    /* If dmaInit fails, free channel resources for alg[i] */
                    freeChannels(dmaTab, numChans);

                    Log_print1(Diags_USER4, "[+4] DMAN3_grantDmaChannels> "
                            "Alg 0x%x dmaInit failed, freeing channel "
                            "resources", (IArg)alg);

                    status = DMAN3_EFAIL;
                }
                else {
                    for (k = 0; k < numChans; k++) {

                        /* Print out trace information */
                        Log_print1(Diags_USER4,
                                "[+4] DMAN3_createChannels> Assigned Qdma: %d",
                                (IArg)(dmaTab[k].handle->qdmaChan));

                        Log_print0(Diags_USER4,
                                "[+4] DMAN3_createChannels> Assigned PaRam(s):");

                        gtPaRamAddr = dmaTab[k].handle->paRamAddr;

                        Log_print2(Diags_USER2,
                                "[+2] DMAN3_createChannels> dmaTab[%d].handle's "
                                "paRamAddr 0x%x", (IArg)k, (IArg)gtPaRamAddr);

                        for (j = 0; j < dmaTab[k].handle->numPaRams; j++) {
                            Log_print2(Diags_USER4,
                                    "[+4] DMAN3_createChannels> %d (Addr 0x%x)",
                                    (IArg)(((Uns)gtPaRamAddr - (Uns)_DMAN3_paRamAddr)
                                    / PARAMSIZEMAUS), (IArg)gtPaRamAddr);

                            gtPaRamAddr -= (PARAMSIZE);
                        }

                        Log_print0(Diags_USER4,
                                "[+4] DMAN3_createChannels> Assigned Tcc(s):");

                        for (j = 0; j < dmaTab[k].handle->numTccs; j++) {
                            Log_print1(Diags_USER4, "[+4] DMAN3_createChannels> %d",
                                    (IArg)(dmaTab[k].handle->tccTable[j]));
                        }
                    }
                }
            }

            if (status != DMAN3_SOK) {
                /* Free channels allocated for alg[0],...,alg[i-1] */
                for (j = 0; j < i; j++) {
                    alg = algHandle[j];
                    dmaFxns = dmaFxnsArray[j];
                    numChans = dmaFxns->dmaGetChannels(alg, dmaTab);

                    /* freeChannels frees context if refCount goes to 0 */
                    freeChannels(dmaTab, numChans);

                    Log_print1(Diags_USER4, "[+4] DMAN3_grantDmaChannels> "
                            "Alg 0x%x Freeing channel resources", (IArg)alg);
                }
                break;
            }
        }
    }

    //Gate_leaveModule(key);
    IGateProvider_leave(DMAN3_gate, key);

    Memory_free(_DMAN3_heapExt, dmaTab, dmaTabSize);

    Log_print1(Diags_EXIT, "[+X] DMAN3_grantDmaChannels> Exit (status=%d)",
            (IArg)status);

    return (status);
}

/*
 *  ======== DMAN3_freeChannels ========
 *  Free memory for channel handles in dmaTab[].
 */
Int DMAN3_freeChannels(IDMA3_Handle channelTab[], Int numChan)
{
    Int             i;
    IDMA3_Handle    chan;
    DMAN3_Context   context;
    DMAN3_Channel   dmanChan;
    Void           *scratchEnv;
    IArg            key;
#ifndef xdc_runtime_Assert_DISABLE_ALL
    Bool            fRet;
#endif

    Assert_isTrue(numChan >= 0, (Assert_Id)NULL);
    Assert_isTrue((channelTab != NULL) || (numChan == 0), (Assert_Id)NULL);

    Log_print2(Diags_ENTRY, "[+E] DMAN3_freeChannels> Enter "
            " (channelTab=0x%x, numChan=%d)", (IArg)channelTab, (IArg)numChan);

    if (numChan < 1) {
        return (DMAN3_SOK);
    }

    for (i = 0; i < numChan; i++) {

        chan = channelTab[i];
        Assert_isTrue(chan != NULL, (Assert_Id)NULL);

        dmanChan = (DMAN3_Channel)chan;
        context = dmanChan->context;
        Assert_isTrue(context != NULL, (Assert_Id)NULL);

        /* De-init the environment */
        if (chan->protocol && chan->protocol->deInitHandle) {

            Log_print1(Diags_USER2, "[+2] DMAN3_freeChannels> "
                    "Calling deinit on protocol on Channel %d", (IArg)i);

#ifndef xdc_runtime_Assert_DISABLE_ALL
            fRet =
#endif
                    chan->protocol->deInitHandle(chan);
            Assert_isTrue(fRet, (Assert_Id)NULL);
        }

        /* Free 'env' buffer, but only if it has been allocated. */
        if ((dmanChan->sizeEnv > 0) && (chan->env != NULL)) {

            /*
             *  Free scratchEnv if it has been allocated. The deInit() function
             *  must put the scratch pointer back at the beginning of the env
             *  address.
             */
            scratchEnv = (Void *)(*(Uint32 *)(chan->env));

            if ((scratchEnv != NULL) && (_DMAN3_freeScratch != NULL)) {

                Log_print1(Diags_USER2,
                        "[+2] DMAN3_freeChannels> Free scratchEnv 0x%x",
                        (IArg)scratchEnv);

                (_DMAN3_freeScratch)(context->scratchId, scratchEnv,
                        dmanChan->sizeEnv);
            }
            /* Get the memory segment for the environment */
            Memory_free(dmanChan->segEnv, chan->env, dmanChan->sizeEnv);
        }

        /* Free DMAN3 channel object memory */
        Memory_free(_DMAN3_heapIdma3, chan, sizeof(DMAN3_ChannelObj));

        //key = Gate_enterModule();
        key = IGateProvider_enter(DMAN3_gate);

        context->refCount--;

        /* Free the context object if the refCount is 0 */
        if (context->refCount == 0) {
            freeContext(context);
        }

        //Gate_leaveModule(key);
        IGateProvider_leave(DMAN3_gate, key);
    }

    Log_print0(Diags_EXIT, "[+X] DMAN3_freeChannels> Exit (status=DMAN3_SOK)");

    return (DMAN3_SOK);
}


/*
 *  ======== DMAN3_releaseDmaChannels ========
 *  Remove logical channel resources from an algorithm instance
 */
Int DMAN3_releaseDmaChannels(IALG_Handle algs[], IDMA3_Fxns *dmaFxnsArray[],
        Int numAlgs)
{
    IALG_Handle         alg;
    IDMA3_Fxns         *dmaFxns;
    IDMA3_ChannelRec    *dmaTab;
    Int                 dmaTabSize;
    Uns                 nChans;
    Int                 maxChans = 0;
    Int                 i;

    Assert_isTrue(algs != NULL, (Assert_Id)NULL);
    Assert_isTrue(dmaFxnsArray != NULL, (Assert_Id)NULL);
    Assert_isTrue(numAlgs > 0, (Assert_Id)NULL);

    Log_print3(Diags_ENTRY, "[+E] DMAN3_releaseDmaChannels> "
            "Enter (algs=0x%x, dmaFxnsArray=0x%x, numAlgs=%d)",
            (IArg)algs, (IArg)dmaFxnsArray, (IArg)numAlgs);

    /*
     *  Get the maximum number of channels requested by any of the algs, so
     *  we know how big to allocate the dmaTab array.
     */
    for (i = 0; i < numAlgs; i++) {
        dmaFxns = dmaFxnsArray[i];
        alg = algs[i];

        Assert_isTrue(dmaFxns->implementationId == alg->fxns->implementationId,
                (Assert_Id)NULL);

        nChans = dmaFxns->dmaGetChannelCnt();
        maxChans = (nChans > maxChans) ? nChans : maxChans;
    }

    /* If no DMA channels were allocated, return. */
    if (maxChans < 1) {
        return (DMAN3_SOK);
    }

    dmaTabSize = sizeof(IDMA3_ChannelRec) * maxChans;

    /* use dynamic allocation instead of stack to avoid large array on stack */
    dmaTab = (IDMA3_ChannelRec *)myMalloc(_DMAN3_heapExt, dmaTabSize,
            sizeof(Int), NULL);

    if (dmaTab == NULL) {
        Log_print0(Diags_EXIT,
                "[+X] DMAN3_releaseDmaChannels> Exit (status=DMAN3_EOUTOFMEMORY");
        return (DMAN3_EOUTOFMEMORY);
    }

    for (i = 0; i < numAlgs; i++) {
        dmaFxns = dmaFxnsArray[i];
        alg = algs[i];

        nChans = dmaFxns->dmaGetChannels(alg, dmaTab);

        Log_print1(Diags_USER2, "[+2] DMAN3_releaseDmaChannels> Free %d channels",
                (IArg)nChans);

        freeChannels(dmaTab, nChans);
    }

    Memory_free(_DMAN3_heapExt, dmaTab, dmaTabSize);

    Log_print0(Diags_EXIT,
            "[+X] DMAN3_releaseDmaChannels> Exit (status=DMAN3_SOK)");

    return (DMAN3_SOK);
}


/*
 *  ======== createChannels ========
 */
static Int createChannels(DMAN3_Context context, IALG_Handle alg, Int groupId,
    IDMA3_ChannelRec dmaTab[], Int numChans)
{
    Void           *env;
    Void           *scratchEnv;
    Int             envSize;
    xdc_runtime_IHeap_Handle seg;
    Int             align;
    IDMA3_MemRec    memRec;
    IALG_MemRec    *memTab = NULL;
    IALG_MemAttrs   memType;
    Int             i, j;
    Uns             qDmaChan;
    Uint8          *tccTablePtr;
    Uns            *paRamAddr;
    Bool            fRet;
    Int             status = DMAN3_SOK;
    Uns             * gtPaRamAddr = NULL;

    Log_print5(Diags_ENTRY, "[+E] createChannels> Enter "
            "(context=0x%x, alg=0x%x, groupId=%d, dmaTab=0x%x, numChans=%d)",
            (IArg)context, (IArg)alg, (IArg)groupId, (IArg)dmaTab,
            (IArg)numChans);

    Assert_isTrue(numChans > 0, (Assert_Id)NULL);

    /*
     *  Allocate array of memTab to be used if env can be allocated from
     *  shared scratch memory. Scratch memory for the alg has to be allocated
     *  all at once, so we need to collect the env memory requirements for
     *  each of the alg's channels. All sizes are initialized to 0 here.
     */
    memTab = (IALG_MemRec *)myMalloc(_DMAN3_heapExt,
            sizeof(IALG_MemRec) * numChans, sizeof(Int), NULL);

    if (memTab == NULL) {
        status = DMAN3_EOUTOFMEMORY;
    }
    else {
        /* Type of memory for env allocated in internal memory */
        memType = (_DMAN3_allocScratch != NULL) ? IALG_SCRATCH : IALG_PERSIST;

        /* Fill in memTab with each channels' env memory requirements */
        for (i = 0; i < numChans; i++) {

            Log_print1(Diags_USER2, "[+2] createChannels> Channel %d", (IArg)i);

            memTab[i].attrs = IALG_PERSIST;

            if (dmaTab[i].protocol && dmaTab[i].protocol->getEnvMemRec) {

                dmaTab[i].protocol->getEnvMemRec(&dmaTab[i], &memRec);
                memTab[i].size = memRec.size;
                memTab[i].alignment = memRec.align;

                /*
                 *  If memRec.memType = IDMA3_INTERNAL, we arbitrarily set the
                 *  space to IALG_DARAM0.
                 */
                if (memRec.memType == IDMA3_INTERNAL) {
                    memTab[i].space = IALG_DARAM0;
                    memTab[i].attrs = memType;
                }
                else {
                    memTab[i].space = IALG_EXTERNAL;
                }

                Log_print5(Diags_USER4, "[+4] createChannels>"
                        " Env Requested memTab[%d]: size=0x%x, align=0x%x, "
                        "space=%s, attrs=%s",
                        (IArg)i, (IArg)(memTab[i].size),
                        (IArg)(memTab[i].alignment),
                        (IArg)(gt_MemAttrs(memTab[i].attrs)),
                        (IArg)(gt_MemSpace(memTab[i].space)));
            }
        }

        /* Allocate scratch env */
        if ((_DMAN3_allocScratch != NULL) &&
                !_DMAN3_allocScratch(alg, groupId, memTab, numChans)) {
            /*
             *  Don't fail if allocation in scratch memory failed. We will
             *  try to allocate in persistent memory.
             */
            Log_print0(Diags_USER2, "[+2] createChannels> "
                    "Scratch Allocation failed");

            for (i = 0; i < numChans; i++) {
                memTab[i].attrs = IALG_PERSIST;
                memTab[i].base = NULL;
            }
        }
        else {
            if ((_DMAN3_allocScratch != NULL) && (dmaTab[i].protocol)) {

                for (i = 0; i < numChans; i++) {

                    Log_print6(Diags_USER4,
                            "[+4] createChannels> Scratch Env Allocated memTab[%d]: "
                            "size=0x%x, align=0x%x, space=%s, attrs=%s, "
                            "base=0x%x",
                            (IArg)i, (IArg)(memTab[i].size),
                            (IArg)(memTab[i].alignment),
                            (IArg)(gt_MemAttrs(memTab[i].attrs)),
                            (IArg)(gt_MemSpace(memTab[i].space)),
                            (IArg)(memTab[i].base));
                }
            }
        }
    }

    if (status != DMAN3_SOK) {
        /* Check the context refCount to see if it should be freed. */
        if (context->refCount == 0) {
            freeContext(context);
        }
        return (status);
    }

    /* Now we can start creating channels */
    for (i = 0; i < numChans; i++) {

        envSize = memTab[i].size;
        seg = (memTab[i].space == IALG_EXTERNAL) ? _DMAN3_heapExt :
                                                   _DMAN3_heapInt;
        align = memTab[i].alignment;
        scratchEnv = memTab[i].base; /* NULL unless allocated in scratch */

        Log_print4(Diags_USER2, "[+2] createChannels> "
                "Creating channel %d, size 0x%x, align 0x%x, scratchEnv 0x%x",
                (IArg)i, (IArg)envSize, (IArg)align, (IArg)scratchEnv);

        /*
         *  Align on word boundary to simplify accesses of IDMA3_Obj
         *  fields by assembly implementations of ACPY3. Allocate more
         *  than IDMA3_Obj, so we can store the context associated with
         *  this channel.
         */

        Log_print4(Diags_USER4, "[+4] createChannels> "
                "IDMA3 Object Requested mem[%d]: size=0x%x, align=0x%x "
                "heapId=%d",
                (IArg)i, (IArg)(sizeof(DMAN3_ChannelObj)), (IArg)(sizeof(Int)),
                (IArg)_DMAN3_heapIdma3);

        dmaTab[i].handle = (IDMA3_Obj *)myMalloc(_DMAN3_heapIdma3,
                sizeof(DMAN3_ChannelObj), sizeof(Int), NULL);

        if (dmaTab[i].handle == NULL) {

            Log_print1(Diags_USER2, "[+2] createChannels> "
                    "Error allocating memory for channel %d", (IArg)i);

            /*
             *  If we failed to create the first channel, then freeChannels()
             *  will not get called to free the context if its ref count is 0.
             *  This can only happen when i = 0.
             */
            if (context->refCount == 0) {

                Log_print1(Diags_USER2, "[+2] createChannels> Freeing context 0x%x",
                        (IArg)context);

                freeContext(context);
            }

            Log_print1(Diags_USER2, "[+2] createChannels> Freeing channels %d",
                    (IArg)i);

            /* Free up the channels that were already allocated. */
            freeChannels(dmaTab, i);

            Log_print1(Diags_USER2, "[+2] createChannels> "
                    "Freeing scratch memory of group %d", (IArg)groupId);

            /* Free scratch memory not freed in call to freeChannels(). */
            freeScratch(groupId, memTab + i, numChans - i);

            status = DMAN3_EOUTOFMEMORY;
            break;
        }
        else {
            /* Assert that Physical DMA resources can be provided */
            Log_print5(Diags_USER4, "[+4] createChannels> "
                    "IDMA3 Object Allocated mem[%d]: size=0x%x, align=0x%x, "
                    "heapId=%d, base=0x%x",
                    (IArg)i, (IArg)(sizeof(DMAN3_ChannelObj)),
                    (IArg)(sizeof(Int)), (IArg)_DMAN3_heapIdma3,
                    (IArg)(dmaTab[i].handle));

            /* Assign QDMA Channel in a roundrobin fashion */
            qDmaChan = DMAN3_PARAMS.qdmaChannels[(context->nextQdmaChannel++
                    - context->qdmaBase) % context->numQdmas +
                    context->qdmaBase];

            Log_print1(Diags_USER2, "[+2] createChannels> Assigning qdmaChannel %d",
                    (IArg)qDmaChan);

            /* Assign TCCs sequentially from a free list */
            tccTablePtr = &_DMAN3_tccAllocationTable[context->nextFreeTccIdx];
            context->nextFreeTccIdx += dmaTab[i].numWaits;

            /* Allocate the 'env' buffer only when requested (i.e. > 0) */
            if ((envSize > 0)) {

                Log_print1(Diags_USER2, "[+2] createChannels>"
                        " Env buffer of size 0x%x requested", (IArg)envSize);

                /*
                 *  If we have env allocated in scratch, we need to allocate
                 *  a persistent copy in external memory.
                 */
                if (scratchEnv != NULL) {
                    seg = _DMAN3_heapExt;
                }

                env = myMalloc(seg, envSize, align, NULL);
            }
            else {

                env = NULL;
            }

            if ((envSize <= 0) || (env != NULL)) {
                //TODO: need for atomicity when reading/writing context? (nd)
                context->refCount++;

                if (envSize > 0) {

                    Log_print5(Diags_USER4,
                            "[+4] createChannels> "
                            "Env Allocated memTab[%d]: size=0x%x, "
                            "align=0x%x, heapId=%d, base=0x%x",
                            (IArg)i, (IArg)envSize, (IArg)align, (IArg)seg,
                            (IArg)env);
                }

                Log_print0(Diags_USER2, "[+2] createChannels>"
                        " Initializing IDMA3_handle");

                /*
                 * Initialize the IDMA3_Handle handle with resource allocation
                 * & channel state
                 */
                fRet = initHandle(dmaTab[i].handle, &dmaTab[i], tccTablePtr,
                        qDmaChan, envSize, env, scratchEnv, seg, context);

                if (!fRet) {

                    Log_print1(Diags_USER2,
                            "[+2] createChannels> Error initializing IDMA3_handle, "
                            "freeChannels %d", (IArg)(i+1));

                    /* free the channels created so far, including this one */
                    freeChannels(dmaTab, i + 1);

                    Log_print1(Diags_USER2,
                            "[+2] createChannels> Free remaining scratch from "
                            "group %d", (IArg)groupId);

                    /* Free remaining scratch */
                    freeScratch(groupId, memTab + i + 1, numChans - i - 1);
                    status = DMAN3_EFAIL;
                    break;
                }
                else {

                    Log_print1(Diags_USER2,
                            "[+2] createChannels> Assigned Qdma Channel(s):%d",
                            (IArg)qDmaChan);

                    Log_print0(Diags_USER2,
                            "[+2] createChannels> Assigned PaRam(s):");

                    gtPaRamAddr = dmaTab[i].handle->paRamAddr;

                    Log_print2(Diags_USER2,
                            "[+2] createChannels> dmaTab[%d].handle's "
                            "paRamAddr 0x%x", (IArg)i, (IArg)gtPaRamAddr);

                    for(j = 0; j < dmaTab[i].handle->numPaRams; j++) {

                        Log_print2(Diags_USER2,
                                "[+2] createChannels> %d (Addr 0x%x)",
                                (IArg)(((Uns)gtPaRamAddr - (Uns)_DMAN3_paRamAddr) /
                                PARAMSIZEMAUS), (IArg)gtPaRamAddr);

                        gtPaRamAddr -= (PARAMSIZE);
                    }

                    Log_print0(Diags_USER2,
                            "[+2] createChannels> Assigned Tcc(s):");

                    for (j = 0; j < dmaTab[i].handle->numTccs; j++) {
                        Log_print1(Diags_USER2, "[+2] createChannels> %d",
                                (IArg)(dmaTab[i].handle->tccTable[j]));

                    }

                    /* Update paRamAddr for next channel */
                    paRamAddr = ((Uns *)context->nextFreePaRamAddr) +
                        (PARAMSIZE * dmaTab[i].numTransfers);

                    /* Set free ptr to next entry */
                    context->nextFreePaRamAddr = ((Uns *)paRamAddr);
                    context->numAssignedPaRams += dmaTab[i].numTransfers;
                }
            }
            else {

                Log_print0(Diags_USER2, "[+2] createChannels> "
                        "Error allocating environment memory, freeing Channel "
                        "objects");

                /* Couldn't allocate env */
                Memory_free(_DMAN3_heapIdma3, dmaTab[i].handle,
                        sizeof(DMAN3_ChannelObj));

                /*
                 *  Check the context refCount to see if it should be freed
                 *  (ie, if this were the first channel we attempted to
                 *  create).
                 */
                if (context->refCount == 0) {

                    Log_print1(Diags_USER2,
                            "[+2] createChannels> Free context 0x%x", (IArg)context);

                    freeContext(context);
                }

                Log_print1(Diags_USER2, "[+2] createChannels> Free Channels %d",
                        (IArg)i);

                freeChannels(dmaTab, i);

                /* Free remaining scratch */
                Log_print1(Diags_USER2,
                        "[+2] createChannels> Free scratch from group %d",
                        (IArg)groupId);

                freeScratch(groupId, memTab + i, numChans - i);
                status = DMAN3_EOUTOFMEMORY;
                break;
            }
        }
    }

    if (memTab) {
        Memory_free(_DMAN3_heapExt, memTab, sizeof(IALG_MemRec) * numChans);
    }

    Log_print1(Diags_EXIT, "[+X] createChannels> Exit (status=%d)", (IArg)status);

    return (status);
}


/*
 *  ======== createContext ========
 */
static Int createContext(DMAN3_Context *pContext, Int groupId, Int nTccs,
        Int nPaRams, Int scratchId)
{
    Int             maxTccs;
    Int             maxPaRams;
    Int             paRamBaseIndex;
    DMAN3_Context   context;
    Int             status = DMAN3_SOK;

    Log_print4(Diags_ENTRY, "[+E] createContext> Enter "
            "(pContext=0x%x, groupId=%d, nTccs=%d, nPaRams=%d)",
            (IArg)pContext, (IArg)groupId, (IArg)nTccs, (IArg)nPaRams);

    *pContext = NULL;

    Log_print0(Diags_USER2, "[+2] createContext> Allocate memory for the context");

    if (_DMAN3_numQdmaGroup(scratchId) <= 0) {
        //Better bail now, no point proceeding with 0 channels in your group
        Log_print1(Diags_USER2, "[+2] createContext> Can't  "
                "create handle, no QDMA channels configured for scratch group ",
                scratchId);

        return(DMAN3_EFAIL);
    }
    if (groupId < 0) {
        context = (DMAN3_Context)myMalloc(_DMAN3_heapExt,
                sizeof(DMAN3_ContextObj), sizeof(Int), NULL);
    }
    else {
        /* Use the pre-allocated context object */
        context = _DMAN3_groupContext(groupId);
    }

    if (context == NULL) {
        Log_print0(Diags_USER2, "[+2] createContext> Could "
                "not allocate memory for the context");
        status = DMAN3_EOUTOFMEMORY;
    }
    else {
        /* Initialize the context object */
        context->groupId = groupId;
        context->refCount = 0;
        context->numTccs = 0;
        context->numPaRams = 0;
        context->tccBase = -1;  /* Initialize, in case maxTccs = 0 */

        context->qdmaBase = _DMAN3_qdma(scratchId);
        context->numQdmas = _DMAN3_numQdmaGroup(scratchId);

        if (ti_sdo_fc_dman3_DMAN3_useCustomDma) {

            if (scratchId == -1) {
                //If original request was for persistent resources, need to
                //allocate discrete resources
                //Mark those resources are persistently "used"
                _DMAN3_data->qdmaPersistentNum--;
                _DMAN3_data->qdmaPersistentBase++;
            }
        }

        maxTccs = nTccs;
        maxPaRams = nPaRams;

        if (groupId >= 0) {
            /*
             *  Allocate the maximum of nTccs and the number of TCCs
             *  configured for this groupId.
             */
            maxTccs = (_DMAN3_numTccGroup[groupId] > maxTccs) ?
                _DMAN3_numTccGroup[groupId] : maxTccs;

            /*
             *  Allocate the maximum of nPaRams and the number of PaRams
             *  configured for this groupId.
             */
            maxPaRams = (_DMAN3_numPaRamGroup[groupId] > maxPaRams) ?
                _DMAN3_numPaRamGroup[groupId] : maxPaRams;
        }

        Log_print1(Diags_USER2, "[+2] createContext> Allocate %d tccs",
                (IArg)maxTccs);

        /* Allocate the TCCs */
        if ((maxTccs > 0) && !RMM_alloc(_DMAN3_rmmTccs, maxTccs,
                    (Uint32 *)&(context->tccBase))) {

            freeContext(context);

            Log_print0(Diags_EXIT, "[+X] createContext> Exit"
                    " (status=DMAN3_OUTOFTCCS)");

            return (DMAN3_EOUTOFTCCS);
        }
        else {
            context->numTccs = maxTccs;
            context->nextFreeTccIdx = context->tccBase;

            Log_print1(Diags_USER2, "[+2] createContext> Next free tcc index %d",
                    (IArg)(context->nextFreeTccIdx));

        }

        Log_print1(Diags_USER2, "[+2] createContext> Allocate %d paRams",
                (IArg)maxPaRams);

        /* Allocate the PaRam */
        if (!RMM_alloc(_DMAN3_rmmPaRams, maxPaRams, (Uint32 *)&paRamBaseIndex)){

            freeContext(context);

            Log_print0(Diags_EXIT, "[+X] createContext> Exit"
                    " (status=DMAN3_OUTOFPARAMS)");

            return (DMAN3_EOUTOFPARAMS);
        }
        else {
            context->numPaRams = maxPaRams;
            context->paRamBaseIdx = paRamBaseIndex; /* For freeing later */

            Log_print1(Diags_USER2, "[+2] createContext> NextpaRam index %d",
                    (IArg)(context->paRamBaseIdx));

        }

        /* If successful allocation of TCCs and PaRam... */
#ifndef _DMAN3_CPUCOPY_
        Assert_isTrue(_DMAN3_paRamAddr != NULL, (Assert_Id)NULL);
#endif
        context->paRamBase = (Uns *)((Uns)_DMAN3_paRamAddr +
                (paRamBaseIndex * PARAMSIZEMAUS));
        context->nextFreePaRamAddr = context->paRamBase;
        context->numAssignedPaRams = 0;

        context->nextQdmaChannel = context->qdmaBase;
        *pContext = context;
    }

    Log_print1(Diags_EXIT, "[+X] createContext> Exit (status=%d)", (IArg)status);

    return (status);
}


/*
 *  ======== freeChannels ========
 *  Free memory for channel handles in dmaTab[].
 */
static Void freeChannels(IDMA3_ChannelRec dmaTab[], Int numChan)
{
    Int             i;
    IDMA3_Handle    chan;

    Log_print2(Diags_ENTRY, "[+E] freeChannels> Enter (dmaTab=0x%x, numChan=%d)",
            (IArg)dmaTab, (IArg)numChan);

    for (i = 0; i < numChan; i++) {
        if ((chan = dmaTab[i].handle) != NULL) {

            Log_print1(Diags_USER2, "[+2] _freeChannels> Freeing channel %d",
                    (IArg)chan);

            DMAN3_freeChannels(&chan, 1);
            dmaTab[i].handle = NULL;
        }
    }

    Log_print0(Diags_EXIT, "[+X] freeChannels> Exit");
}


/*
 *  ======== freeContext ========
 *  Free context handle object that was used to start allocating from a fresh
 *  scratch allocation context.
 */
static Void freeContext(DMAN3_Context context)
{
#ifndef xdc_runtime_Assert_DISABLE_ALL
    Bool    fRet;
#endif

    Log_print1(Diags_ENTRY, "[+E] _freeContext> Enter (context=0x%x)",
            (IArg)context);

    Assert_isTrue(context->refCount == 0, (Assert_Id)NULL);

    /* Free the TCCs */
    Log_print1(Diags_USER2, "[+2] freeContext> Freeing %d tccs",
            (IArg)(context->numTccs));

    /* TODO:M should we 'invalidate' context->tccBase even if !Assert? */
    if (context->numTccs > 0) {
#ifndef xdc_runtime_Assert_DISABLE_ALL
        fRet =
                RMM_free(_DMAN3_rmmTccs, context->tccBase, context->numTccs);
#endif
        context->tccBase = -1;
        Assert_isTrue(fRet, (Assert_Id)NULL);
    }

    /* Free the PaRams */
    Log_print1(Diags_USER2, "[+2] freeContext> Freeing %d params",
            (IArg)(context->numPaRams));

    if (context->numPaRams > 0) {
#ifndef xdc_runtime_Assert_DISABLE_ALL
        fRet =
#endif
                RMM_free(_DMAN3_rmmPaRams, context->paRamBaseIdx,
                context->numPaRams);
        context->paRamBaseIdx = -1;
        Assert_isTrue(fRet, (Assert_Id)NULL);
    }

    if (context->groupId < 0) {
        Memory_free(_DMAN3_heapExt, context, sizeof(DMAN3_ContextObj));
    }

    Log_print1(Diags_USER2, "[+2] freeContext> Freeing context memory size 0x%x",
            (IArg)(sizeof(DMAN3_ContextObj)));

    Log_print0(Diags_EXIT, "[+X] freeContext> Exit");
}


/*
 *  ======== freeScratch ========
 */
/**
 *  Free any scratch memory in memTab[].
 */
static Void freeScratch(Int groupId, IALG_MemRec memTab[], Int numRecs)
{
    Int             i;

    Log_print3(Diags_ENTRY, "[+E] freeScratch> Enter "
            "(groupId=%d, memTab=0x%x, numRecs=%d)",
            (IArg)groupId, (IArg)memTab, (IArg)numRecs);

    if (_DMAN3_freeScratch != NULL) {


        for (i = 0; i < numRecs; i++) {
            if ((memTab[i].attrs == IALG_SCRATCH) && (memTab[i].size > 0)) {

                Log_print2(Diags_USER2, "[+2] freeScratch> "
                        "Freeing scratch memory 0x%x of size 0x%x",
                        (IArg)(memTab[i].base), (IArg)(memTab[i].size));

                _DMAN3_freeScratch(groupId, memTab[i].base, memTab[i].size);
                memTab[i].base = NULL;
            }
        }
    }

    Log_print0(Diags_EXIT, "[+X] freeScratch> Exit");

}


/*
 *  ======== getContext ========
 *  Get context handle for groupId. (In the future, we might have a linked
 *  list of contexts for a given groupId, with varying amounts of TCCs and
 *  PaRams. Therefore, we pass nTccs and nPaRams to this function).
 */
static Int getContext(DMAN3_Context *pContext, Int groupId, Int nTccs,
        Int nPaRams)
{
    Int           scratchId = groupId;
    DMAN3_Context context = NULL;
    Int status = DMAN3_SOK;

    Log_print4(Diags_ENTRY, "[+E] getContext> Enter "
            "(pContext=0x%x, groupId=%d, nTccs=%d, nPaRams=%d)",
            (IArg)pContext, (IArg)groupId, (IArg)nTccs, (IArg)nPaRams);

    *pContext = NULL;

    if (groupId >= 0) {
#if defined(xdc_target__isaCompatible_64P) || \
    defined(xdc_target__isaCompatible_64T)
        /* TODO: Why do we only care about this for DSP targets? */
        /*
         *  If allowUnshared is FALSE, don't allow channels to be created
         *  if the number of TCCs or PaRams needed is more than the number
         *  configured for the given scratch group.
         */
        if (DMAN3_PARAMS.allowUnshared == FALSE) {
            if (_DMAN3_numTccGroup[groupId] < nTccs) {
                return (DMAN3_ETCCCONFIG);
            }

            if (_DMAN3_numPaRamGroup[groupId] < nPaRams) {
                return (DMAN3_EPARAMCONFIG);
            }
        }
#endif
        context = _DMAN3_groupContext(groupId);

        Log_print2(Diags_USER2, "[+2] getContext> Context "
                "exists for groupId %d, context 0x%x",
                (IArg)groupId, (IArg)context);

        /*
         *  Need to allocate a new context if one exists for the given
         *  groupId, but does not have enough PaRam or TCCs.
         *  Note: For non-64P targets where group contexts are pre-defined
         *  (and therefore never NULL), we need to check that the context
         *  reference count is > 0 before accessing the other fields.
         */
        if (context && (context->refCount > 0) && (
                (nPaRams > context->numPaRams) ||
                (nTccs > context->numTccs))) {
            /*
             *  The context for this groupId has been created with too few
             *  tccs or PaRams, so it cannot be used for this channel
             *  allocation. In this case, we will need to allocate a new
             *  context which will not share its tccs and PaRams.
             */
            Log_print3(Diags_USER2,
                    "[+2] getContext> "
                    "Existing context has insufficient tccs and PaRams: "
                    "params: %d, tccs: %d, refCount: %d",
                    (IArg)(context->numPaRams), (IArg)(context->numTccs),
                    (IArg)(context->refCount));

            groupId = -1;
            context = NULL;
        }
    }

    /*
     *  Create the context handle if not using any sharing group, or if
     *  using a sharing group but the context for that group has not yet
     *  been allocated, or, if not enough TCCs or PaRams are available.
     */
    if ((context == NULL) || (context->refCount == 0)) {

        Log_print3(Diags_USER2, "[+2] getContext> Creating "
                "context for group %d Tccs %d PaRams %d",
                (IArg)groupId, (IArg)nTccs, (IArg)nPaRams);

        status = createContext(&context, groupId, nTccs, nPaRams, scratchId);
        if (status != DMAN3_SOK) {
            Log_print1(Diags_EXIT, "[+X] getContext> Exit (status=%d)",
                    (IArg)status);
            return (status);

        }
        context->scratchId = scratchId;
    }

    Assert_isTrue(context != NULL, (Assert_Id)NULL);

    /*
     *  Re-initialize next available TCC and PaRam back to the beginning.
     *  The channels allocated in this call will not share TCCs, PaRam.
     */
    context->nextFreeTccIdx = context->tccBase;
    context->nextFreePaRamAddr = context->paRamBase;
    context->numAssignedPaRams = 0;
    *pContext = context;

    Log_print0(Diags_EXIT, "[+X] getContext> Exit (status=DMAN3_SOK)");

    return (DMAN3_SOK);
}


/*
 *  ======== initHandle ========
 *  Initialize the IDMA3_Handle handle with resource allocation/channel state.
 */
static Bool initHandle(IDMA3_Handle handle, IDMA3_ChannelRec *dmaTab,
        Uint8 *tccList, Uns qdmaChannel, Int16 envSize, Void *env,
        Void *scratchEnv, xdc_runtime_IHeap_Handle seg, DMAN3_Context context)
{
    Bool          fRet = TRUE;

    Log_print6(Diags_ENTRY, "[+E] initHandle> Enter "
            "(handle=0x%x, dmaTab=0x%x, qdmaChannel=%d, env=0x%x, "
            "scratchEnv=0x%x, context=0x%x)",
            (IArg)handle, (IArg)dmaTab, (IArg)qdmaChannel, (IArg)env,
            (IArg)scratchEnv, (IArg)context);

    handle->numTccs = dmaTab->numWaits;
    handle->numPaRams = dmaTab->numTransfers;
    handle->qdmaChan  = qdmaChannel;
    handle->env  = env;

    Log_print4(Diags_USER2, "[+2] initHandle> Initializing "
            "IDMA3 handle with %d tccs, %d PaRams, qdmaChannel %d, env 0x%x",
            (IArg)(handle->numTccs), (IArg)(handle->numPaRams),
            (IArg)(handle->qdmaChan), (IArg)env);

    if (env) {

        Log_print0(Diags_USER2, "[+2] initHandle> Non-zero env handle");

        Assert_isTrue(envSize > 0, (Assert_Id)NULL);
        *(Uint32 *)handle->env = (Uint32)scratchEnv;
    }

    handle->protocol = dmaTab->protocol;

    /* Keep these for when we free the channel */
    ((DMAN3_Channel)handle)->context = context;
    ((DMAN3_Channel)handle)->sizeEnv = envSize;
    ((DMAN3_Channel)handle)->segEnv = seg;

    /*
     *  Assign Physical PARAM Blocks:
     *  Grant "numTransfers" many PARAM blocks, but initialize handle with the
     *  address of the "last" PARAM block.
     */
    handle->paRamAddr = ((Uns *)context->nextFreePaRamAddr) +
        (PARAMSIZE * (dmaTab->numTransfers - 1));

    /* Note: TccTable is provided by the framework. */
    handle->tccTable = tccList;

    /* until first transfer gets started there is no transfer to wait. */
    handle->transferPending = 0;

    Log_print2(Diags_USER2, "[+2] initHandle> paRam block 0x%x, tcc Table 0x%x",
            (IArg)(handle->paRamAddr), (IArg)(handle->tccTable));

    /* Call the protocol's init function. */
    if (dmaTab->protocol && dmaTab->protocol->initHandle) {

        Log_print0(Diags_USER2, "[+2] initHandle> Call protocol Init function");

        fRet = dmaTab->protocol->initHandle(handle);
    }

    Log_print1(Diags_EXIT, "[+X] initHandle> Exit (status=%d)", (IArg)fRet);

    return (fRet);
}

/*
 * ======== checkDMAN3Configuration ========
 */
/* ARGSUSED */
static Bool checkDMAN3Configuration()
{
    Bool status = TRUE;
#ifndef _DMAN3_CPUCOPY_
    Uns cccfg = 0x0;
    short numQdma = 0;
    short numParam = 0;
    short chipTccs = 0;
    //short numTC = 0;
    volatile Uns * edma3Base = (Uns *)_DMAN3_edma3Addr;
    int i;

    Log_print0(Diags_ENTRY, "[+E] checkDMAN3Configuration> Enter");

    cccfg = edma3Base[1];
    cccfg = (edma3Base[1] >> 4);
    numQdma = (cccfg & 0x7) << 0x1;

    /* Check if qdma channels assigned are all within range */
    for (i = 0; i < DMAN3_PARAMS.numQdmaChannels ; i++) {
        if (DMAN3_PARAMS.qdmaChannels[i] >= numQdma) {
            status = FALSE;
            Log_print1(Diags_EXIT, "[+7] checkDMAN3Configuration> Bad "
                    "Qdma channel configuration 0x%x\n",
                    DMAN3_PARAMS.qdmaChannels[i]);
            return (FALSE);
        }
    }

    cccfg = (cccfg >> 4);
    chipTccs = ((cccfg&0x7)==0) ? 0 : (0x4 << (cccfg & 0x7));
    if (_DMAN3_maxAssignedTcc >= chipTccs) {

        Log_print1(Diags_EXIT, "[+7] checkDMAN3Configuration> Bad TCC "
                " configuration, SOC has only %d Tccs\n", chipTccs);
        return (FALSE);
    }

    cccfg = (cccfg >> 4);
    numParam = (((cccfg & 0x7) == 0) ? 0x0 : (0x10 << (cccfg & 0x7)));

    if ((DMAN3_PARAMS.paRamBaseIndex + DMAN3_PARAMS.numPaRamEntries) >
            numParam) {
        status = FALSE;
        Log_print3(Diags_EXIT, "[+7] checkDMAN3Configuration> Bad "
                "PaRam configuration: %d to %d, max PaRam = %d\n",
                DMAN3_PARAMS.paRamBaseIndex,
                DMAN3_PARAMS.paRamBaseIndex + DMAN3_PARAMS.numPaRamEntries - 1,
                numParam - 1);
    }

    if (DMAN3_PARAMS.nullPaRamIndex >= numParam) {
        status = FALSE;
        Log_print1(Diags_EXIT, "[+7] checkDMAN3Configuration> Bad "
                "NULL PaRam configuration %d\n", DMAN3_PARAMS.nullPaRamIndex);
    }

    /* Commenting this out, most configs don't even set this param
    cccfg = (cccfg>>4);
    numTC = (cccfg &0x7) + 1;

    if  (DMAN3_PARAMS.maxTCs != numTC) {
                Log_print2(Diags_EXIT, "[+7] checkDMAN3Configuration> Bad maxTCs "
                                "configuration %d\n, hardware reads %d\n", DMAN3_PARAMS.maxTCs,
                                numTC);

        status = FALSE;
    }
    */
#endif

    Log_print1(Diags_EXIT, "[+X] checkDMAN3Configuration> Exit (status=%d)",
            (IArg)status);

    return (status);
}

/*
 *  ======== myMalloc ========
 *  xdc.runtime.Memory_alloc will raise an exception if memory allocation fails
 *  and the error block passed in is NULL. Instead of putting error block
 *  checks throughout code, just call this function, passing NULL for the
 *  error block.
 */
static Void *myMalloc(xdc_runtime_IHeap_Handle heap, SizeT size, SizeT align,
        Error_Block *dummy)
{
    Void       *buf;
    Error_Block eb;

    /* Must initialize prior to first use */
    Error_init(&eb);

    /*
     *  We need to pass a non-NULL error block to Memory_calloc(), in order
     *  not to abort on allocation failure. Some DMAN3 tests check memory
     *  allocation failures so we don't want to abort.
     */
    buf = Memory_calloc(heap, size, align, &eb);

    /*
     *  Error_check() returns TRUE if an error occurred. (Memory_calloc() will
     *  also return NULL if an error occurred.)
     */
    if (Error_check(&eb)) {
        return (NULL);
    }
    else {
        return (buf);
    }
}
/*
 *  @(#) ti.sdo.fc.dman3; 1, 0, 4,4; 2-22-2012 18:03:19; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

