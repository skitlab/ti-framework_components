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
 *  ======== dman3_externalRM_api.c ========
 *  DMA Resource manager and utilities for granting logical channel
 *  resources to algorithms.
 */

/* This difine must precede inclusion of any xdc header files */
#define Registry_CURDESC ti_sdo_fc_dman3_desc

#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Registry.h>
#include <xdc/runtime/IGateProvider.h>

#include <ti/sdo/edma3/rm/edma3_rm.h>
#include <ti/sdo/fc/edma3/edma3_config.h>

#include "dman3.h"
#include "dman3_externalRM_impl.h"
#include "rmm.h"

#include <ti/xdais/idma3.h>
#include <ti/sdo/fc/global/gt_dais.h>

#include <ti/sdo/edma3/rm/edma3_rm.h>
#include <ti/sdo/fc/edma3/edma3_config.h>


#pragma CODE_SECTION(DMAN3_grantDmaChannels, ".text:DMAN3_grantDmaChannels");
#pragma CODE_SECTION(DMAN3_releaseDmaChannels,".text:DMAN3_releaseDmaChannels");

#pragma CODE_SECTION(DMAN3_createChannels, ".text:DMAN3_createChannels");
#pragma CODE_SECTION(DMAN3_freeChannels, ".text:DMAN3_freeChannels");

extern IGateProvider_Handle DMAN3_gate;

EDMA3_RM_Handle _DMAN3_systemRMHandle = NULL;

extern Uint32 *_DMAN3_paRamAddr;
extern UInt32 *_DMAN3_edma3Addr;
extern UInt32 _DMAN3_nullPaRam;

/*
 *  ======== DMAN3_ChannelObj ========
 *  Structure to store a handle to the DMAN3 context object that
 *  was used to create the IDMA3 channel.
 */
typedef struct DMAN3_ChannelObj {
    IDMA3_Obj           idmaChan;
    DMAN3_Context       context;
    xdc_runtime_IHeap_Handle segEnv;  /* segment id where env is allocated */
    Uint16              sizeEnv; /* size of env */
} DMAN3_ChannelObj, *DMAN3_Channel;

/* Tracks if the external RM has been suitably and successfully iniitalized
   or not */
static Int externalRMInit = 0;
static Int initialized = 0;
static inline Int finalizeExternalRM();
static inline Int initializeExternalRM();

static Int  createChannels(IALG_Handle alg, Int groupId,
        IDMA3_ChannelRec dmaTab[], Int numChans);
static Int createContext(DMAN3_Context *pContext, Int groupId);
static Void freeChannels(IDMA3_ChannelRec dmaTab[], Int numChan);
static Void freeContext(DMAN3_Context context);
static Void freeScratch(Int groupId, IALG_MemRec memTab[], Int numRecs);
static Int  getContext(DMAN3_Context *pContext, Int groupId, IALG_Handle alg);
static Bool initHandle(IDMA3_Handle handle, IDMA3_ChannelRec *dmaTab,
        Uint8 *tccList, Uns paRamAddr, Uns qdmaChannel, Int16 envSize,
        Void *env, Void *scratchEnv, xdc_runtime_IHeap_Handle seg,
        DMAN3_Context context);
static Void freeResource(EDMA3_RM_Handle rmHandle, Uns qDmaChan, Uns numWaits,
        unsigned char * tccTablePtr, Uns numPaRams, Uns paRamIndex);
static inline Void freeResourceManager (EDMA3_RM_Handle rmHandle,
        IALG_Handle algHandle, Int groupId);

extern Registry_Desc ti_sdo_fc_dman3_desc;

/*
 *  ======== DMAN3_createChannels ========
 *  Allocate and initialize memory for channel handle.
 *  What do I do in this case, algHandle is now NULL and groupId could be > 0
 *  Could store the algorithm as NULL
 *  Allocate resources from the same handle for all dmaTab(s) in this call ?
 */
Int DMAN3_createChannels(Int groupId, IDMA3_ChannelRec dmaTab[], Int numChans)
{
    Int             i, j;
    Int             status = DMAN3_SOK;
    Uns             * gtPaRamAddr = NULL;

    Assert_isTrue(groupId < DMAN3_MAXGROUPS, (Assert_Id)NULL);
    Assert_isTrue(numChans >= 0, (Assert_Id)NULL);
    Assert_isTrue((dmaTab != NULL) || (numChans == 0), (Assert_Id)NULL);

    Log_print3(Diags_ENTRY, "[+E] DMAN3_createChannels> Enter "
            "(groupId=%d, dmaTab=0x%x, numChans=%d",
            (IArg)groupId, (IArg)dmaTab, (IArg)numChans);

    for (i = 0; i < numChans; i++) {
        dmaTab[i].handle = NULL;
    }


    if (0 == externalRMInit) {

        status = initializeExternalRM();

        if (status != DMAN3_SOK) {

            Log_print0(Diags_USER4, "[+4] DMAN3_createChannels> Error "
                                        "initializing Resource Manager and allocating initial "
                                        "resources\n");

            Log_print1(Diags_EXIT, "[+X] DMAN3_createChannels> (status=%d)\n",
                                        status);

            return (status);
        }
    }

    /* Now create the channels */
    status = createChannels(NULL, groupId, dmaTab, numChans);

    if (status == DMAN3_SOK) {

        for (i = 0; i < numChans; i++) {

            Log_print1(Diags_USER4, "[+4] DMAN3_createChannels> Assigned Qdma: %d",
                    (IArg)(dmaTab[i].handle->qdmaChan));

            Log_print0(Diags_USER4,
                    "[+4] DMAN3_createChannels> Assigned PaRam(s):");

            gtPaRamAddr = dmaTab[i].handle->paRamAddr;

            Log_print2(Diags_USER2,
                    "[+2] DMAN3_createChannels> dmaTab[%d].handle's paRamAddr 0x%x",
                    (IArg)i, (IArg)gtPaRamAddr);

            for(j = 0; j < dmaTab[i].handle->numPaRams; j++) {

                Log_print2(Diags_USER4, "[+4] DMAN3_createChannels> %d (Addr 0x%x)",
                        (IArg)(((Uns)gtPaRamAddr - (Uns)_DMAN3_paRamAddr) /
                        PARAMSIZEMAUS), (IArg)gtPaRamAddr);

                gtPaRamAddr -= (PARAMSIZE);
            }

            Log_print0(Diags_USER4, "[+4] DMAN3_createChannels> Assigned Tcc(s):");

            for(j = 0; j < dmaTab[i].handle->numTccs; j++) {

                Log_print1(Diags_USER4, "[+4] DMAN3_createChannels> %d",
                        (IArg)(dmaTab[i].handle->tccTable[j]));
            }
        }
    }

    Log_print1(Diags_EXIT, "[+X] DMAN3_createChannels> Exit (returnVal=%d)",
            (IArg)status);

    return (status);
}

/*
 *  ======== DMAN3_grantDmaChannels ========
 *  Add an algorithm to the DMA Manager.  The DMA Manager will grant DMA
 *  resources to the algorithm as a result.  This function is called when
 *  initializing an algorithm instance.
 *  Supporting this for only 1 algorithm (numAlgs = 1)
 */
/* ARGSUSED - Directive to compiler to not complain about unused args */
Int DMAN3_grantDmaChannels(Int groupId, IALG_Handle algHandle[],
        IDMA3_Fxns *dmaFxnsArray[], Int numAlgs)
{
    Uns              numChans;
    Int              j, k;
    IALG_Handle      alg;
    IDMA3_Fxns      *dmaFxns;
    IDMA3_ChannelRec *dmaTab;
    Int              maxChans = _DMAN3_MAXCHANS;
    Int              status = DMAN3_EFAIL;
    Uns             *gtPaRamAddr = NULL;

    Assert_isTrue(algHandle != NULL, (Assert_Id)NULL);
    Assert_isTrue(dmaFxnsArray != NULL, (Assert_Id)NULL);
    Assert_isTrue(numAlgs == 1, (Assert_Id)NULL);
    Assert_isTrue(groupId < DMAN3_MAXGROUPS, (Assert_Id)NULL);

    Log_print4(Diags_ENTRY, "[+E] DMAN3_grantDmaChannels> "
            "Enter (groupId=%d, algHandle=0x%x, dmaFxns=0x%x, numAlgs=%d)",
            (IArg)groupId, (IArg)algHandle, (IArg)dmaFxnsArray,
            (IArg)numAlgs);

    if (1 != numAlgs) {
        Log_print0(Diags_USER7,
                "[+7] DMAN3_grantDmaChannels> API supported only for 1 algorithm at"
                " time when using an external Resource Manager.");
        Log_print0(Diags_EXIT,
                "[+X] DMAN3_grantDmaChannels> Exit (status=DMAN3_EOUTOFMEMORY)");
        return (DMAN3_EFAIL);
    }


    if (0 == externalRMInit) {


        status = initializeExternalRM();

        if (status != DMAN3_SOK) {

            Log_print0(Diags_USER7, "[+7] DMAN3_grantDmaChannels> Error "
                    "initializing Resource Manager and allocating initial"
                    "resources\n");

            Log_print1(Diags_USER7, "[+7] DMAN3_grantDmaChannels> "
                    "(status=%d)\n",status);

            return (status);
        }
    }

    /* use dynamic allocation instead of stack to avoid large array on stack */
    dmaTab = (IDMA3_ChannelRec *)Memory_calloc(_DMAN3_heapExt,
            sizeof(IDMA3_ChannelRec) * maxChans, sizeof(Int), NULL);

    if (dmaTab == NULL) {

        Log_print0(Diags_EXIT,
                "[+X] DMAN3_grantDmaChannels> Exit (status=DMAN3_EOUTOFMEMORY)");
        return (DMAN3_EOUTOFMEMORY);
    }

    alg = algHandle[0];
    dmaFxns = dmaFxnsArray[0];

    Assert_isTrue(alg != NULL, (Assert_Id)NULL);
    Assert_isTrue(dmaFxns != NULL, (Assert_Id)NULL);

    /*  alg and idma3 fxns must be from same implementation */
    Assert_isTrue(dmaFxns->implementationId == alg->fxns->implementationId,
            (Assert_Id)NULL);
    Log_print1(Diags_USER4, "[+4] DMAN3_grantDmaChannels> Alg 0x%x:", (IArg)alg);

    Assert_isTrue(dmaFxns->implementationId == alg->fxns->implementationId,
            (Assert_Id)NULL);

    numChans = dmaFxns->dmaGetChannels(alg, dmaTab);

    status = createChannels(alg, groupId, dmaTab, numChans);

    if ((status == DMAN3_SOK)) {

        if ((status = dmaFxns->dmaInit(alg, dmaTab)) != IALG_EOK) {

            /* If dmaInit fails, free channel resources for alg[i] */
            freeChannels(dmaTab, numChans);

            Log_print1(Diags_USER4,
                    "[+4] DMAN3_grantDmaChannels> Alg 0x%x dmaInit failed, "
                    "freeing channel resources", (IArg)alg);

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
                            (IArg)(((Uns)gtPaRamAddr - (Uns)_DMAN3_paRamAddr) /
                            PARAMSIZEMAUS), (IArg)gtPaRamAddr);

                    gtPaRamAddr -= (PARAMSIZE);
                }

                Log_print0(Diags_USER4,
                        "[+4] DMAN3_createChannels> Assigned Tcc(s):");

                for( j = 0; j < dmaTab[k].handle->numTccs; j++) {

                    Log_print1(Diags_USER4, "[+4] DMAN3_createChannels> %d",
                            (IArg)(dmaTab[k].handle->tccTable[j]));
                }
            }
        }
    }

    Memory_free(_DMAN3_heapExt, dmaTab, sizeof(IDMA3_ChannelRec) * maxChans);

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
    Int             status = DMAN3_SOK;
    Int             i;
    IDMA3_Handle    chan;
    DMAN3_Context   context;
    DMAN3_Channel   dmanChan;
    Void           *scratchEnv;
    Uns             paRamAddr;
    Uns             paRamIndex;
#ifndef xdc_runtime_Assert_DISABLE_ALL
    Bool            fRet;
#endif

    Assert_isTrue(numChan >= 0, (Assert_Id)NULL);
    Assert_isTrue((channelTab != NULL) || (numChan == 0), (Assert_Id)NULL);

    Log_print2(Diags_ENTRY, "[+E] DMAN3_freeChannels> Enter "
            " (channelTab=0x%x, numChan=%d)", (IArg)channelTab, (IArg)numChan);

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

        if (context->rmHandle != NULL) {

            paRamAddr = (Uns)(chan->paRamAddr);

            paRamIndex = ((paRamAddr - (Uns)_DMAN3_paRamAddr)/PARAMSIZEMAUS) -
                    chan->numPaRams + 1;

            freeResource(context->rmHandle, chan->qdmaChan,
                    chan->numTccs, chan->tccTable, chan->numPaRams, paRamIndex);

            freeResourceManager(context->rmHandle, context->algHandle,
                    context->groupId);

            context->rmHandle = NULL;
        }


        /* Release memory allocated for tcc Array and paRam array */
        Memory_free(_DMAN3_heapExt, chan->tccTable, chan->numTccs *
                sizeof(unsigned char));

        /* Free DMAN3 channel object memory */
        Memory_free(_DMAN3_heapIdma3, chan, sizeof(DMAN3_ChannelObj));

        freeContext(context);
    }

    externalRMInit -= numChan;

    if (0 == externalRMInit) {

        status = finalizeExternalRM();
    }

    Log_print0(Diags_EXIT, "[+X] DMAN3_freeChannels> Exit (status=DMAN3_SOK)");

    return (status);
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
    Uns                 nChans;
    Int                 i;
    Int                 maxChans = _DMAN3_MAXCHANS;

    Assert_isTrue(algs != NULL, (Assert_Id)NULL);
    Assert_isTrue(dmaFxnsArray != NULL, (Assert_Id)NULL);
    Assert_isTrue(numAlgs > 0, (Assert_Id)NULL);

    Log_print3(Diags_ENTRY, "[+E] DMAN3_releaseDmaChannels> "
            "Enter (algs=0x%x, dmaFxnsArray=0x%x, numAlgs=%d)",
            (IArg)algs, (IArg)dmaFxnsArray, (IArg)numAlgs);

    /* use dynamic allocation instead of stack to avoid large array on stack */
    dmaTab = (IDMA3_ChannelRec *)Memory_calloc(_DMAN3_heapExt,
            sizeof(IDMA3_ChannelRec) * maxChans, sizeof(Int), NULL);

    if (dmaTab == NULL) {
        Log_print0(Diags_EXIT,
                "[+X] DMAN3_releaseDmaChannels> Exit (status=DMAN3_EOUTOFMEMORY");
        return (DMAN3_EOUTOFMEMORY);
    }

    for (i = 0; i < numAlgs; i++) {
        dmaFxns = dmaFxnsArray[i];
        alg = algs[i];

        Assert_isTrue(dmaFxns->implementationId == alg->fxns->implementationId,
                (Assert_Id)NULL);

        /*
         * In debug build verify that algo is not using two many buffers,
         * in release build trust that contract is respected
         */

        nChans = dmaFxns->dmaGetChannels(alg, dmaTab);


        Log_print1(Diags_USER2, "[+2] DMAN3_releaseDmaChannels> Free %d channels",
                (IArg)nChans);

        freeChannels(dmaTab, nChans);

    }

    Memory_free(_DMAN3_heapExt, dmaTab, sizeof(IDMA3_ChannelRec) * maxChans);

    Log_print0(Diags_EXIT,
            "[+X] DMAN3_releaseDmaChannels> Exit (status=DMAN3_SOK)");

    return (DMAN3_SOK);
}


/*
 *  ======== createChannels ========
 *  One algorithm, multiple dmaTab(s).
 */
static Int  createChannels(IALG_Handle alg, Int groupId,
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
    Uns             qDmaChan = (Uns)-1;
    Uint8          *tccTablePtr;
    Uns            paRamAddr;
    Bool            fRet;
    Int             status = DMAN3_SOK;
    Uns             * gtPaRamAddr = NULL;
    DMAN3_Context   context;


    EDMA3_RM_Handle rmHandle = NULL;
    EDMA3_RM_Result rmStatus;
    EDMA3_RM_ResDesc resObj;

    Uns             qeesr = 0x0;
    Uns             *addr = 0x0;

    Assert_isTrue(dmaTab != NULL, (Assert_Id)NULL);

    Log_print4(Diags_ENTRY, "[+E] createChannels> Enter "
            "(alg=0x%x, groupId=%d, dmaTab=0x%x, numChans=%d)",
            (IArg)alg, (IArg)groupId, (IArg)dmaTab, (IArg)numChans);

    if (NULL == _DMAN3_systemRMHandle) {
        return (DMAN3_EFAIL);
    }

    /*
     *  Allocate array of memTab to be used if env can be allocated from
     *  shared scratch memory. Scratch memory for the alg has to be allocated
     *  all at once, so we need to collect the env memory requirements for
     *  each of the alg's channels. All sizes are initialized to 0 here.
     */

    memTab = (IALG_MemRec *)Memory_calloc(_DMAN3_heapExt,
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

        /* Get a new context. One is embedded in each handle. */
        status = getContext(&context, groupId, alg);

        dmaTab[i].handle = (IDMA3_Obj *)Memory_calloc(_DMAN3_heapIdma3,
                sizeof(DMAN3_ChannelObj), sizeof(Int), NULL);

        if (dmaTab[i].handle == NULL) {

            Log_print1(Diags_USER2, "[+2] createChannels> "
                    "Error allocating memory for channel %d", (IArg)i);

            /*
             *  If we failed to create the first channel, then freeChannels()
             */
            Log_print1(Diags_USER2, "[+2] createChannels> Freeing context 0x%x",
                    (IArg)context);

            freeContext(context);

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

                        ((DMAN3_ChannelObj *)(dmaTab[i].handle))->context = context;

            /* If persistent handles are requested, use system handle,
               if scratch group resources are requested, obtain RM handle */
            if ((dmaTab[i].persistent == TRUE) ||( groupId == -1)) {
                rmHandle = _DMAN3_systemRMHandle;
                //scratch = FALSE;
            }
            else {
                rmHandle = EDMA3_getResourceManager(alg, groupId);
            }

            if (NULL == rmHandle) {

                status = DMAN3_EFAIL;

                Log_print2(Diags_USER7,
                        "[+7] createChannels> Error obtaining resource manager "
                        "handle for alg 0x%x and group %d",
                        (IArg)alg, (IArg)groupId);

                /* Couldn't alloc RM resource or obtain RM handle */
                Memory_free(_DMAN3_heapIdma3, dmaTab[i].handle,
                        sizeof(DMAN3_ChannelObj));

                freeContext(context);

                /* free the channels created so far, including this one */
                freeChannels(dmaTab, i);

                Log_print1(Diags_USER2,
                        "[+2] createChannels> Free remaining scratch from group %d",
                        (IArg)groupId);

                freeScratch(groupId, memTab + i, numChans - i);

                goto createChannelsEnd;
            }

            j = ((context->nextQdmaChannel++ - context->qdmaBase) %
                    context->numQdmas) + context->qdmaBase;
            qDmaChan = DMAN3_QDMA[j].index;


            /* Enabling the QDMA event corresponding to this channel */
            qeesr = 0x0;
            qeesr |= (0x1 << qDmaChan);
            addr = (UInt32 *)((UInt32)_DMAN3_edma3Addr + QEESROFFSET);

            /* Queue Event Enable Set register */
            (*addr) = qeesr;

            resObj.type = EDMA3_RM_RES_TCC;

            /* TODO check for error here */
            tccTablePtr = (Uint8 *)Memory_calloc(_DMAN3_heapExt,
                    sizeof(Uint8) * dmaTab[i].numWaits, sizeof(Int), NULL);

            for (j = 0; j < dmaTab[i].numWaits; j++) {

                resObj.resId = EDMA3_RM_RES_ANY;

                rmStatus = EDMA3_RM_allocResource(rmHandle, &resObj);

                if (EDMA3_RM_SOK != rmStatus) {

                    status = DMAN3_EOUTOFTCCS;

                    Log_print1(Diags_USER7,
                            "[+7] createChannels> Error allocating %d Tccs",
                            (IArg)(dmaTab[i].numWaits));

                    freeResource(rmHandle, qDmaChan, j, tccTablePtr,
                            (Uns)-1, (Uns) -1);

                    Memory_free(_DMAN3_heapExt, tccTablePtr,
                            sizeof(Uint8) * dmaTab[i].numWaits);

                    /* Release the RM Handle */
                    freeResourceManager(rmHandle, context->algHandle,
                            context->groupId);

                    /* Couldn't alloc RM resource or obtain RM handle */
                    Memory_free(_DMAN3_heapIdma3, dmaTab[i].handle,
                            sizeof(DMAN3_ChannelObj));

                    freeContext(context);

                    /* free the channels created so far, including this one */
                    freeChannels(dmaTab, i);

                    Log_print1(Diags_USER2,
                            "[+2] createChannels> Free remaining scratch from "
                            "group %d", (IArg)groupId);

                    freeScratch(groupId, memTab + i, numChans - i);


                    goto createChannelsEnd;
                }

                tccTablePtr[j] = resObj.resId;
            }

            resObj.type = EDMA3_RM_RES_PARAM_SET;
            resObj.resId = EDMA3_RM_RES_ANY;

            rmStatus = EDMA3_RM_allocContiguousResource(rmHandle, &resObj,
                    dmaTab[i].numTransfers);

            if (EDMA3_RM_SOK != rmStatus) {

                status = DMAN3_EOUTOFPARAMS;

                Log_print1(Diags_USER7,
                        "[+7] createChannels> Error allocating %d PaRams",
                        (IArg)(dmaTab[i].numTransfers));

                freeResource(rmHandle, qDmaChan, dmaTab[i].numWaits,
                        tccTablePtr, (Uns)-1, (Uns)-1);

                /* Release the RM Handle */
                freeResourceManager(rmHandle, context->algHandle,
                        context->groupId);

                Memory_free(_DMAN3_heapExt, tccTablePtr,
                        sizeof(Uint8) * dmaTab[i].numWaits);

                /* Couldn't alloc RM resource or obtain RM handle */
                Memory_free(_DMAN3_heapIdma3, dmaTab[i].handle,
                        sizeof(DMAN3_ChannelObj));

                freeContext(context);

                /* free the channels created so far, including this one */
                freeChannels(dmaTab, i);

                Log_print1(Diags_USER2,
                        "[+2] createChannels> Free remaining scratch from group %d",
                        (IArg)groupId);

                freeScratch(groupId, memTab + i, numChans - i);


                goto createChannelsEnd;
            }

            if (EDMA3_RM_SOK != EDMA3_RM_getPaRAMPhyAddr(rmHandle, &resObj,
                    &paRamAddr)) {

                status = DMAN3_EFAIL;

                Log_print1(Diags_USER2,
                        "[+2] createChannels> Error obtaining physical address of "
                        "allocated PaRam %d", (IArg)(resObj.resId));

                /* Note:- freeResource expects a paRam Index, not a PaRam
                          Address */
                freeResource(rmHandle, qDmaChan, dmaTab[i].numWaits,
                        tccTablePtr, dmaTab[i].numTransfers, resObj.resId);

                /* Release the RM Handle */
                freeResourceManager(rmHandle, context->algHandle,
                        context->groupId);

                Memory_free(_DMAN3_heapExt, tccTablePtr,
                        sizeof(Uint8) * dmaTab[i].numWaits);

                /* Couldn't alloc RM resource or obtain RM handle */
                Memory_free(_DMAN3_heapIdma3, dmaTab[i].handle,
                        sizeof(DMAN3_ChannelObj));

                freeContext(context);

                /* free the channels created so far, including this one */
                freeChannels(dmaTab, i);

                Log_print1(Diags_USER2,
                        "[+2] createChannels> Free remaining scratch from group %d",
                        (IArg)groupId);

                freeScratch(groupId, memTab + i, numChans - i);


                goto createChannelsEnd;
            }

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

                env = Memory_calloc(seg, envSize, align, NULL);

            }
            else {

                env = NULL;
            }

            if ((envSize <= 0) || (env != NULL)) {
                //TODO: need for atomicity when reading/writing context? (nd)

                if (envSize > 0) {

                    Log_print5(Diags_USER4,
                            "[+4] createChannels> Env Allocated memTab[%d]: "
                            "size=0x%x, align=0x%x, heapId=0x%x, base=0x%x",
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
                        paRamAddr, qDmaChan, envSize, env, scratchEnv,
                        seg, context);

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

                    context->rmHandle = rmHandle;

                    externalRMInit ++;

                }
            }
            else {

                Log_print0(Diags_USER2, "[+2] createChannels> "
                        "Error allocating environment memory, freeing Channel "
                        "objects");

                /* Couldn't allocate env */
                Memory_free(_DMAN3_heapIdma3, dmaTab[i].handle,
                        sizeof(DMAN3_ChannelObj));

                freeResource(rmHandle, qDmaChan, dmaTab[i].numWaits,
                        tccTablePtr, dmaTab[i].numTransfers, resObj.resId);

                /* Release the RM Handle */
                freeResourceManager(rmHandle, context->algHandle,
                        context->groupId);

                Memory_free(_DMAN3_heapExt, tccTablePtr,
                        sizeof(Uint8) * dmaTab[i].numWaits);

                Log_print1(Diags_USER2, "[+2] createChannels> Free context 0x%x",
                        (IArg)context);

                freeContext(context);

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

createChannelsEnd:

    if (memTab) {
        Memory_free(_DMAN3_heapExt, memTab, sizeof(IALG_MemRec) * numChans);
    }

    Log_print1(Diags_EXIT, "[+X] createChannels> Exit (status=%d)", (IArg)status);

    return (status);
}


/*
 *  ======== createContext ========
 */
static Int createContext(DMAN3_Context *pContext, Int groupId)
{
    DMAN3_Context   context;
    Int             status = DMAN3_SOK;

    Log_print2(Diags_ENTRY, "[+E] createContext> Enter (pContext=0x%x, groupId=%d)",
            (IArg)pContext, (IArg)groupId);

    *pContext = NULL;

    Log_print0(Diags_USER2, "[+2] createContext> Allocate memory for the context");

    context = (DMAN3_Context)Memory_calloc(_DMAN3_heapExt,
            sizeof(DMAN3_ContextObj), sizeof(Int), NULL);

    if (context == NULL) {
        Log_print0(Diags_USER2, "[+2] createContext> Could "
                "not allocate memory for the context");
        status = DMAN3_EOUTOFMEMORY;
    }
    else {
        /* Initialize the context object */
        context->groupId = groupId;
        context->qdmaBase = _DMAN3_qdma(groupId);
        context->numQdmas =  _DMAN3_numQdmaGroup(groupId);
        if (ti_sdo_fc_dman3_DMAN3_useCustomDma) {
            if (groupId == -1) {
                //If original request was for persistent resources, need to
                //allocate discrete resources
                //Cannot reuse those resources
                ti_sdo_fc_dman3_DMAN3_numQdmaGroup[DMAN3_MAXGROUPS]--;
                _DMAN3_qdmaBase[DMAN3_MAXGROUPS]++;
            }
        }
        context->nextQdmaChannel = _DMAN3_qdmaCounter(groupId);
        _DMAN3_qdmaCounter(groupId)++;

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

    Log_print1(Diags_ENTRY, "[+E] _freeContext> Enter (context=0x%x)",
            (IArg)context);


    Memory_free(_DMAN3_heapExt, context, sizeof(DMAN3_ContextObj));

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
 * Cannot support allowUnShared here
 */
static Int getContext(DMAN3_Context *pContext, Int groupId,
        IALG_Handle algHandle)
{
    Int           scratchId = groupId;
    DMAN3_Context context   = NULL;
    Int status              = DMAN3_SOK;

    Log_print2(Diags_ENTRY, "[+E] getContext> Enter (pContext=0x%x, groupId=%d)",
            (IArg)pContext, (IArg)groupId);

    *pContext = NULL;

    status = createContext(&context, groupId);

    if (status != DMAN3_SOK) {

        Log_print1(Diags_EXIT, "[+X] getContext> Exit (status=%d)", (IArg)status);
        return (status);
    }

    context->scratchId = scratchId;
    context->algHandle = algHandle;
    context->rmHandle = NULL;

    Assert_isTrue(context != NULL, (Assert_Id)NULL);

    *pContext = context;

    Log_print0(Diags_EXIT, "[+X] getContext> Exit (status=DMAN3_SOK)");

    return (DMAN3_SOK);
}

/*
 *  ======== initHandle ========
 *  Initialize the IDMA3_Handle handle with resource allocation/channel state.
 */
static Bool initHandle(IDMA3_Handle handle, IDMA3_ChannelRec *dmaTab,
        Uint8 *tccList, Uns paRamAddr, Uns qdmaChannel, Int16 envSize,
        Void *env, Void *scratchEnv, xdc_runtime_IHeap_Handle seg,
        DMAN3_Context context)
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

    Log_print5(Diags_USER2, "[+2] initHandle> Initializing "
            "IDMA3 handle with %d tccs, %d PaRams, qdmaChannel %d, env 0x%x"
            "rmhandle 0x%x",
            (IArg)(handle->numTccs), (IArg)(handle->numPaRams),
            (IArg)(handle->qdmaChan), (IArg)env, (IArg)(context->rmHandle));

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
    handle->paRamAddr = (Uns *)((paRamAddr) +
            (PARAMSIZEMAUS * (dmaTab->numTransfers - 1)));
    /* handle->paRamAddr = (Uns *)paRamAddr;  */

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


static Void freeResource(EDMA3_RM_Handle rmHandle, Uns qdmaChan, Uns numTccs,
        unsigned char * tccTable, Uns numPaRams, Uns paRamIndex)
{
    Int j = 0;

    EDMA3_RM_ResDesc resObj;
    EDMA3_RM_Result rmStatus = EDMA3_RM_SOK;


    /* Release PaRams */
    if (numPaRams != (Uns)-1) {

        resObj.type  = EDMA3_RM_RES_PARAM_SET;

        /* The channel handle points to the last PaRam assigned to this handle*/
        resObj.resId = paRamIndex;
        rmStatus = EDMA3_RM_freeContiguousResource(rmHandle, &resObj,
                numPaRams);

        Assert_isTrue(EDMA3_RM_SOK == rmStatus, (Assert_Id)NULL);

        if (EDMA3_RM_SOK != rmStatus) {

            /* Report error */
            Log_print2(Diags_USER7,
                    "[+7] freeResource> Could not free %d PaRams starting at %d",
                    (IArg)numPaRams, (IArg)(resObj.resId));
        }
    }

    if (numTccs != (Uns)-1) {

        resObj.type  = EDMA3_RM_RES_TCC;

        for (j = 0; j < numTccs; j++) {

            resObj.resId = tccTable[j];

            rmStatus = EDMA3_RM_freeResource(rmHandle, &resObj);

            Assert_isTrue(EDMA3_RM_SOK == rmStatus, (Assert_Id)NULL);

            if (EDMA3_RM_SOK != rmStatus) {

                /* Report error */
                Log_print1(Diags_USER7, "[+7] freeResource> Could not free TCC %d",
                        (IArg)(resObj.resId));
            }
        }
    }
}


static inline Void freeResourceManager (EDMA3_RM_Handle rmHandle,
        IALG_Handle algHandle, Int groupId)
{
    EDMA3_RM_Result rmStatus = EDMA3_RM_SOK;

    /* Don't release the system handle, that is required to acquire/release
       RM resources. */
    if (_DMAN3_systemRMHandle != rmHandle) {

        /* Release the RM Handle */
        rmStatus = EDMA3_releaseResourceManager(algHandle, groupId);

        Assert_isTrue(EDMA3_RM_SOK == rmStatus, (Assert_Id)NULL);

        if (EDMA3_RM_SOK != rmStatus) {

            /* Report error */
            Log_print2(Diags_USER7,
                    "[+7] freeResourceManager> Could not free Resource "
                    "Manager handle corresponding to alg 0x%x in group %d",
                    (IArg)algHandle, (IArg)(groupId ));
        }
    }
}

//TODO: Fix these functions below
static inline Int finalizeExternalRM()
{
    Int status;

    Log_print0(Diags_ENTRY, "[+E] finalizeExternalRM> Enter\n");

    Memory_free(_DMAN3_heapExt, DMAN3_QDMA,
            sizeof(DMAN3_QdmaObj) * DMAN3_PARAMS.numQdmaChannels);

    if (EDMA3_SOK == EDMA3_releaseResourceManager(NULL, -1)) {
        status = DMAN3_SOK;
    }
    else {
        status = DMAN3_EFAIL;
    }

    _DMAN3_systemRMHandle = NULL;

    Log_print1(Diags_EXIT, "[+X] finalizeExternalRM> Exit "
            "(status=%d)\n", status);

    initialized = 0;

    return (status);
}

static inline Int initializeExternalRM()
{
    EDMA3_RM_ResDesc resObj;
    EDMA3_RM_Result  rmStatus = EDMA3_RM_SOK;
    Int i, chan;
    Uns cccfg = 0x0;
    Uns numQdma = 0;
    volatile Uns   *qchmap;
    Uns            *paRam;
    IArg            key;

    Log_print0(Diags_ENTRY, "[+E] initializeExternalRM> Enter\n"
            );

    _DMAN3_heapInt = DMAN3_PARAMS.heapInternal;
    _DMAN3_heapExt = DMAN3_PARAMS.heapExternal;

    _DMAN3_heapInt = (_DMAN3_heapInt == NULL) ?
            _DMAN3_heapExt : _DMAN3_heapInt;
    _DMAN3_heapExt = (_DMAN3_heapExt == NULL) ?
            _DMAN3_heapInt : _DMAN3_heapExt;
    _DMAN3_heapIdma3 = (DMAN3_PARAMS.idma3Internal) ?
            _DMAN3_heapInt : _DMAN3_heapExt;

    /* This is a fatal configuration error. */
     Assert_isTrue(_DMAN3_heapInt != NULL, (Assert_Id)NULL);

     key = IGateProvider_enter(DMAN3_gate);

    if (!(initialized)) {

        if (NULL != _DMAN3_systemRMHandle) {

            Log_print0(Diags_USER7, "[+7] initializeExternalRM>"
                    " DMAN3_systemRMHandle should be NULL when first alg is "
                    " granted resources!\n");

            Log_print0(Diags_EXIT, "[+X] initializeExternalRM>"
                    " (status=DMAN3_EFAIL)\n");

                IGateProvider_leave(DMAN3_gate, key);

            return (DMAN3_EFAIL);
        }

        _DMAN3_systemRMHandle = EDMA3_getResourceManager(NULL, -1);

        if (NULL == _DMAN3_systemRMHandle) {

                        IGateProvider_leave(DMAN3_gate, key);

            Log_print0(Diags_USER7, "[+7] initializeExternalRM>"
                    " DMAN3_systemRMHandle could not be opened\n");

            Log_print0(Diags_EXIT, "[+X] initializeExternalRM> "
                    "(status=DMAN3_EFAIL)\n");

                return (DMAN3_EFAIL);
        }

        EDMA3_RM_getBaseAddress(_DMAN3_systemRMHandle, EDMA3_RM_CC_PHY_ADDR,
                (unsigned int *)(&_DMAN3_edma3Addr));

        if (_DMAN3_edma3Addr == NULL) {

                IGateProvider_leave(DMAN3_gate, key);

            Log_print0(Diags_USER7, "[+7] initializeExternalRM>"
                    " DMAN3 base address could not be determined\n");

            Log_print0(Diags_EXIT, "[+X] initializeExternalRM> "
                    "(status=DMAN3_EFAIL)\n");

            return (DMAN3_EFAIL);
        }

        _DMAN3_paRamAddr = (Uns *)((Uns)_DMAN3_edma3Addr + PARAMOFFSET);

        /* Acquire a PaRam that will be the nullPaRamIndex */
        resObj.type = EDMA3_RM_RES_PARAM_SET;
        resObj.resId = EDMA3_RM_RES_ANY;

        rmStatus = EDMA3_RM_allocResource(_DMAN3_systemRMHandle, &resObj);

        if (EDMA3_RM_SOK != rmStatus) {

                IGateProvider_leave(DMAN3_gate, key);

            Log_print0(Diags_USER7, "[+7] initializeExternalRM>"
                    " EDMA3 LLD-RM could not allocate the NULL PaRam Index."
                    " Resource not available !\n");

            Log_print0(Diags_EXIT, "[+X] initializeExternalRM> "
                    "(status=DMAN3_EFAIL)\n");

            return (DMAN3_EFAIL);
        }

        _DMAN3_nullPaRam = resObj.resId;

        DMAN3_QDMA = (DMAN3_QdmaObj *)Memory_calloc(_DMAN3_heapExt,
                sizeof(DMAN3_QdmaObj) * DMAN3_PARAMS.numQdmaChannels,
                sizeof(Int), NULL);

        resObj.type = EDMA3_RM_RES_QDMA_CHANNEL;
        resObj.resId = EDMA3_RM_RES_ANY;

        for (i = 0; i < DMAN3_PARAMS.numQdmaChannels; i++) {
            resObj.resId = EDMA3_RM_RES_ANY;
            rmStatus = EDMA3_RM_allocResource(_DMAN3_systemRMHandle, &resObj);

            if (EDMA3_RM_SOK != rmStatus) {

                IGateProvider_leave(DMAN3_gate, key);

                Log_print0(Diags_USER7,
                        "[+7] initializeExternalRM> EDMA3 LLD-RM could not allocate "
                        "QDMA channels. Resource not available !\n");

                Log_print0(Diags_EXIT,
                        "[+X] initializeExternalRM> (status=DMAN3_EFAIL)\n");


                return (DMAN3_EFAIL);
            }

            DMAN3_QDMA[i].index = resObj.resId;
            DMAN3_QDMA[i].available = TRUE;

            /* Value of 0 implies this can be used as scratch or persistent
               Value of >=1 implies it is being used as scratch */
            DMAN3_QDMA[i].scratch = 0;
        }

        /* Set qchmap to address of first QCHMAP register */
        qchmap = (volatile Uns *)((Uns)_DMAN3_edma3Addr + QCHMAPOFFSET);

        /* If channel belongs to DMAN3, point it to null param */
        for (i = 0; i < DMAN3_PARAMS.numQdmaChannels; i++) {
            chan = DMAN3_QDMA[i].index;
            qchmap[chan] = (Uns)(_DMAN3_nullPaRam << 5);
        }

        /* CC configuration register */
        cccfg = _DMAN3_edma3Addr[1];

        /* Maximum number of QDMA channels on this device */
        numQdma = ((cccfg >>4) & 0x7) << 0x1;

        for (i = 0; i < numQdma; i++) {
            /* Even if channel doesnt' belong to DMAN3, but points to null param
               change trigger word to # 7 */
            if (_DMAN3_nullPaRam == ((*qchmap >> 5 ) & 0x1FF)) {
                Log_print1(Diags_USER2, "[+2] "
                        "_DMAN3_initImpl> Qdma channel %d is pointing to "
                        "the nullPaRam. Change its trigger word bit to 0x7 so "
                        "it doesn't get triggered when we modify the null "
                        "PaRam\n", i);
                *qchmap = *qchmap | (0x7 << 2);
            }
            qchmap++;
        }

        /*
         *  Set the static bit of opts field of the null PaRam, since
         *  QCHMAP may get set to this PaRam when the channel is
         *  activated/deactivated. (The opts field is the first word of the
         *  PaRam entry).
         */
        paRam = (Uns *)((Uns)_DMAN3_paRamAddr +
                (_DMAN3_nullPaRam * PARAMENTRYSIZE * sizeof(UInt32)));

        Log_print1(Diags_USER2, "[+2] _DMAN3_initImpl> "
                "Setting static bit of null paRam (address = 0x%x)\n",
                (IArg)paRam);

        *paRam |= 0x8;

        initialized = 1;
    }

    IGateProvider_leave(DMAN3_gate, key);

    Log_print0(Diags_EXIT, "[+X] initializeExternalRM> Exit "
            "(status=DMAN3_SOK)\n");

    return (DMAN3_SOK);
}
/*
 *  @(#) ti.sdo.fc.dman3; 1, 0, 4,4; 2-22-2012 18:03:19; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

