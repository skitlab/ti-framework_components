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
 *  ======== universal_dma_ti_ires.c ========
 *  EDMA Codec1 algorithm's implementation of IRES_Fxns.
 */

#include <xdc/std.h>
#include <string.h>
#include <ti/xdais/trace.h>

#include <ti/xdais/dm/iuniversal.h>

#include <ti/xdais/ialg.h>
#include <ti/xdais/ires.h>

/* Header file for the resources used in this example. */
#include <ti/sdo/fc/ires/edma3chan/ires_edma3Chan.h>
#include <ti/sdo/fc/ecpy/ecpy.h>

#include "universal_dma_ti.h"
#include "universal_dma_ti_priv.h"

/* IRES Function Declarations */
static IRES_Status UNIVERSAL_DMA_TI_activateRes(IALG_Handle handle, IRES_Handle res);
static IRES_Status UNIVERSAL_DMA_TI_activateAllRes(IALG_Handle handle);
static IRES_Status UNIVERSAL_DMA_TI_deactivateRes(IALG_Handle h, IRES_Handle res);
static IRES_Status UNIVERSAL_DMA_TI_deactivateAllRes(IALG_Handle handle);
static Int32 UNIVERSAL_DMA_TI_numResources(IALG_Handle handle);
static IRES_Status UNIVERSAL_DMA_TI_getResources(IALG_Handle handle,
        IRES_ResourceDescriptor *desc);
static IRES_Status UNIVERSAL_DMA_TI_initResources(IALG_Handle h,
        IRES_ResourceDescriptor * desc, IRES_YieldFxn  yieldFxn,
        IRES_YieldArgs yieldArgs);
static IRES_Status UNIVERSAL_DMA_TI_deInitResources(IALG_Handle h,
        IRES_ResourceDescriptor *desc);
static IRES_Status UNIVERSAL_DMA_TI_reInitResources(IALG_Handle handle,
        IRES_ResourceDescriptor *desc, IRES_YieldFxn  yieldFxn,
        IRES_YieldArgs yieldArgs);

/*
 *  ======== UNIVERSAL_DMA_TI_IRES ========
 */
IRES_Fxns UNIVERSAL_DMA_TI_IRES = {
    &UNIVERSAL_DMA_TI_IRES,
    UNIVERSAL_DMA_TI_getResources,
    UNIVERSAL_DMA_TI_numResources,
    UNIVERSAL_DMA_TI_initResources,
    UNIVERSAL_DMA_TI_reInitResources,
    UNIVERSAL_DMA_TI_deInitResources,
    UNIVERSAL_DMA_TI_activateRes,
    UNIVERSAL_DMA_TI_activateAllRes,
    UNIVERSAL_DMA_TI_deactivateRes,
    UNIVERSAL_DMA_TI_deactivateAllRes
};


/*
 *  ======== UNIVERSAL_DMA_TI_activateAllRes ========
 */
static IRES_Status UNIVERSAL_DMA_TI_activateAllRes(IALG_Handle handle)
{
    /* Activate all resources - this example has only one. */
    /* Can be empty if no activation is necessary, or no IRES_SCRATCH resources
       were requested. */

    return (IRES_OK);
}

/*
 *  ======== UNIVERSAL_DMA_TI_activateRes ========
 */
static IRES_Status UNIVERSAL_DMA_TI_activateRes(IALG_Handle handle,
        IRES_Handle res)
{
    /* Check that res = alg->nullres */

    return (IRES_OK);
}

/*
 *  ======== UNIVERSAL_DMA_TI_deactivateAllRes ========
 */
static IRES_Status UNIVERSAL_DMA_TI_deactivateAllRes(IALG_Handle handle)
{
    /* Finalization or saving of state associated with IRES_SCRATCH resources
       can be done here. After this point, current codec no longer exclusively
       owns the scratch resources */

    return (IRES_OK);
}

/*
 *  ======== UNIVERSAL_DMA_TI_deactivateRes ========
 */
static IRES_Status UNIVERSAL_DMA_TI_deactivateRes(IALG_Handle h, IRES_Handle res)
{
    /* Check that res = alg->nullres */

    return (IRES_OK);
}

/*
 *  ======== UNIVERSAL_DMA_TI_deInitResources ========
 */
static IRES_Status UNIVERSAL_DMA_TI_deInitResources(IALG_Handle h,
        IRES_ResourceDescriptor *desc)
{
    UNIVERSAL_DMA_TI_Obj  *alg = (UNIVERSAL_DMA_TI_Obj *)h;


    if (desc[0].handle == (IRES_Handle)alg->edmaHandle[0]) {
        ECPY_deleteHandle(alg->ecpyHandle[0]);

        alg->ecpyHandle[0] = NULL;
        alg->edmaHandle[0] = NULL;
        alg->resActive[0] = FALSE;
    }
    if (desc[1].handle == (IRES_Handle)alg->edmaHandle[1]) {
        ECPY_deleteHandle(alg->ecpyHandle[1]);

        alg->ecpyHandle[1] = NULL;
        alg->edmaHandle[1] = NULL;
        alg->resActive[1] = FALSE;
    }
    if (desc[2].handle == (IRES_Handle)alg->edmaHandle[2]) {
        ECPY_deleteHandle(alg->ecpyHandle[2]);

        alg->ecpyHandle[2] = NULL;
        alg->edmaHandle[2] = NULL;
        alg->resActive[2] = FALSE;
    }

    return (IRES_OK);
}

/*
 *  ======== UNIVERSAL_DMA_TI_getResources ========
 */
static IRES_Status UNIVERSAL_DMA_TI_getResources(IALG_Handle h,
        IRES_ResourceDescriptor *desc)
{
    UNIVERSAL_DMA_TI_Obj  *alg = (UNIVERSAL_DMA_TI_Obj *)h;

    TRACE_2print(h, TRACE_ENTER,"UNIVERSAL_DMA_TI_getResources> "
            "Enter (alg=0x%x, desc=0x%x)\n", h, desc);
    /*
     * This API could be called to query for resource requirements and after
     * having granted the resources, could also be queried for resource
     * holdings of the algorithm. The difference is that in the second case a
     * valid resource handle (that had been granted earlier) would be expected.
     */
    //Request IRES_EDMA3CHAN version 2.0.0 to use with ECPY
    IRES_EDMA3CHAN_SETPROTOCOLREVISION_2_0_0(&(alg->edmaRev));

    /* resource #1 */
    desc[0].resourceName = IRES_EDMA3CHAN_PROTOCOLNAME;
    desc[0].revision = &(alg->edmaRev);
    desc[0].protocolArgs = (IRES_ProtocolArgs *)&(alg->edmaArgs[0]);
    (alg->edmaArgs[0]).size = sizeof(IRES_EDMA3CHAN_ProtocolArgs);
    (alg->edmaArgs[0]).mode = IRES_SCRATCH;
    (alg->edmaArgs[0]).numPaRams = 3;
    (alg->edmaArgs[0]).paRamIndex = IRES_EDMA3CHAN_PARAM_ANY;
    (alg->edmaArgs[0]).tccIndex = IRES_EDMA3CHAN_TCC_ANY;
    (alg->edmaArgs[0]).numTccs = 1;
    (alg->edmaArgs[0]).qdmaChan = IRES_EDMA3CHAN_CHAN_NONE;
    (alg->edmaArgs[0]).edmaChan = IRES_EDMA3CHAN_EDMACHAN_ANY;
    (alg->edmaArgs[0]).contiguousAllocation = TRUE;
    (alg->edmaArgs[0]).shadowPaRamsAllocation = FALSE;
    desc[0].handle = (IRES_Handle)alg->edmaHandle[0];

    /* resource #2 */
    desc[1].resourceName = IRES_EDMA3CHAN_PROTOCOLNAME;
    desc[1].revision = &(alg->edmaRev);
    desc[1].protocolArgs = (IRES_ProtocolArgs *)&(alg->edmaArgs[1]);
    (alg->edmaArgs[1]).size = sizeof(IRES_EDMA3CHAN_ProtocolArgs);
    (alg->edmaArgs[1]).mode = IRES_SCRATCH;
    (alg->edmaArgs[1]).numPaRams = 6;
    (alg->edmaArgs[1]).paRamIndex = IRES_EDMA3CHAN_PARAM_ANY;
    (alg->edmaArgs[1]).tccIndex = IRES_EDMA3CHAN_TCC_ANY;
    (alg->edmaArgs[1]).numTccs = 1;
    (alg->edmaArgs[1]).qdmaChan = IRES_EDMA3CHAN_CHAN_NONE;
    (alg->edmaArgs[1]).edmaChan = IRES_EDMA3CHAN_EDMACHAN_ANY;
    (alg->edmaArgs[1]).contiguousAllocation = TRUE;
    (alg->edmaArgs[1]).shadowPaRamsAllocation = FALSE;
    desc[1].handle = (IRES_Handle)alg->edmaHandle[1];

    /* resource #3 */
    desc[2].resourceName = IRES_EDMA3CHAN_PROTOCOLNAME;
    desc[2].revision = &(alg->edmaRev);
    desc[2].protocolArgs = (IRES_ProtocolArgs *)&(alg->edmaArgs[2]);
    (alg->edmaArgs[2]).size = sizeof(IRES_EDMA3CHAN_ProtocolArgs);
    (alg->edmaArgs[2]).mode = IRES_SCRATCH;
    (alg->edmaArgs[2]).numPaRams = 6;
    (alg->edmaArgs[2]).paRamIndex = IRES_EDMA3CHAN_PARAM_ANY;
    (alg->edmaArgs[2]).tccIndex = IRES_EDMA3CHAN_TCC_ANY;
    (alg->edmaArgs[2]).numTccs = 1;
    (alg->edmaArgs[2]).qdmaChan = IRES_EDMA3CHAN_CHAN_NONE;
    (alg->edmaArgs[2]).edmaChan = IRES_EDMA3CHAN_EDMACHAN_ANY;
    (alg->edmaArgs[2]).contiguousAllocation = TRUE;
    (alg->edmaArgs[2]).shadowPaRamsAllocation = FALSE;
    desc[2].handle = (IRES_Handle)alg->edmaHandle[2];


    TRACE_1print(h,TRACE_4CLASS, "UNIVERSAL_DMA_TI_getResources> "
                "desc[0].handle = 0x%x\n", desc[0].handle);

    TRACE_0print( h,TRACE_ENTER, "UNIVERSAL_DMA_TI_getResources> Exit (status="
            "IRES_OK)\n");
    return (IRES_OK);
}

/*
 *  ======== UNIVERSAL_DMA_TI_initResources ========
 */
static IRES_Status UNIVERSAL_DMA_TI_initResources(IALG_Handle h,
        IRES_ResourceDescriptor *desc, IRES_YieldFxn  yieldFxn,
        IRES_YieldArgs yieldArgs)
{
    UNIVERSAL_DMA_TI_Obj  *alg = (UNIVERSAL_DMA_TI_Obj *)h;
    ECPY_init();

    /*
     * Resource manager has returned a resource handle. Save it in the
     * algorithm's instance object
     */
    alg->edmaHandle[0] = (IRES_EDMA3CHAN2_Handle)desc[0].handle;
    alg->ecpyHandle[0] =
            ECPY_createHandle((IRES_EDMA3CHAN2_Handle)desc[0].handle, h);

    alg->edmaHandle[1] = (IRES_EDMA3CHAN2_Handle)desc[1].handle;
    alg->ecpyHandle[1] =
            ECPY_createHandle((IRES_EDMA3CHAN2_Handle)desc[1].handle, h);

    alg->edmaHandle[2] = (IRES_EDMA3CHAN2_Handle)desc[2].handle;
    alg->ecpyHandle[2] =
            ECPY_createHandle((IRES_EDMA3CHAN2_Handle)desc[2].handle, h);

    /*
     * Resource Manager also provides yield functions and yield Args alongwith
     * the resource handle.
     */
    alg->yieldFxn = yieldFxn;
    alg->yieldArgs = yieldArgs;

    return (IRES_OK);
}

/*
 *  ======== UNIVERSAL_DMA_TI_numResources ========
 */
/* ARGSUSED */
static Int32 UNIVERSAL_DMA_TI_numResources(IALG_Handle handle)
{
    return (UNIVERSAL_DMA_TI_NUM_EDMACHANS);
}

/*
 *  ======== UNIVERSAL_DMA_TI_reInitResources ========
 */
static IRES_Status UNIVERSAL_DMA_TI_reInitResources(IALG_Handle handle,
        IRES_ResourceDescriptor *desc, IRES_YieldFxn  yieldFxn,
        IRES_YieldArgs yieldArgs)
{
    UNIVERSAL_DMA_TI_Obj  *alg = (UNIVERSAL_DMA_TI_Obj *)handle;

    alg->yieldFxn = yieldFxn;
    alg->yieldArgs = yieldArgs;

    /*
     * This function implies that the resource holdings of the algorithms have
     * been changed.
     * Update them in the algorithm instance object.
     */
    alg->edmaHandle[0] = (IRES_EDMA3CHAN2_Handle)desc[0].handle;
    alg->edmaHandle[1] = (IRES_EDMA3CHAN2_Handle)desc[1].handle;
    alg->edmaHandle[2] = (IRES_EDMA3CHAN2_Handle)desc[2].handle;
    alg->yieldFxn = yieldFxn;
    alg->yieldArgs = yieldArgs;
    alg->resActive[0] = FALSE;
    alg->resActive[1] = FALSE;
    alg->resActive[2] = FALSE;

    return (IRES_OK);
}
/*
 *  @(#) ti.sdo.fc.ires.examples.codecs.universal_dma; 1, 0, 0,4; 2-22-2012 18:06:01; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

