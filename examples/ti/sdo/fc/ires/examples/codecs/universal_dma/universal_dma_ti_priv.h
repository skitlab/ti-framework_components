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
 *  ======== universal_dma_ti_priv.h ========
 *  Internal vendor specific (TI) interface header for UNIVERSAL_DMA
 *  algorithm. Only the implementation source files include
 *  this header; this header is not shipped as part of the
 *  algorithm.
 *
 *  This header contains declarations that are specific to
 *  this implementation and which do not need to be exposed
 *  in order for an application to use the UNIVERSAL_DMA algorithm.
 */
#ifndef UNIVERSAL_DMA_TI_PRIV_
#define UNIVERSAL_DMA_TI_PRIV_


#include <ti/xdais/ires.h>
#include <ti/sdo/fc/ires/edma3chan/ires_edma3Chan.h>

#define UNIVERSAL_DMA_TI_NUM_EDMACHANS 3

typedef struct UNIVERSAL_DMA_TI_CtxtArgs {
    Int size;
} UNIVERSAL_DMA_TI_CtxtArgs;

typedef struct UNIVERSAL_DMA_TI_Obj {
    IALG_Obj       alg;            /* MUST be first field of all XDAS algs */

    /* IRES stuff */
    IRES_EDMA3CHAN2_Handle      edmaHandle[UNIVERSAL_DMA_TI_NUM_EDMACHANS];
    IRES_ProtocolRevision       edmaRev;  //{2,0,0} Version of resource;
    ECPY_Handle                 ecpyHandle[UNIVERSAL_DMA_TI_NUM_EDMACHANS];
    short                       paramArray[512];
    IRES_EDMA3CHAN_ProtocolArgs edmaArgs[UNIVERSAL_DMA_TI_NUM_EDMACHANS];
    Bool                        resActive[3];   /* Is the resource active? */
    unsigned int *              srcBuf;
    unsigned int *              dstBuf;
    IRES_YieldFxn               yieldFxn;
    IRES_YieldArgs              yieldArgs;
    IRES_YieldContext           yieldContext;
    UNIVERSAL_DMA_TI_CtxtArgs   contextArgs;
} UNIVERSAL_DMA_TI_Obj;

extern Int UNIVERSAL_DMA_TI_alloc(const IALG_Params *algParams, IALG_Fxns **pf,
        IALG_MemRec memTab[]);

extern Int UNIVERSAL_DMA_TI_numalloc(const IALG_Params *algParams,
    IALG_Fxns **pf, IALG_MemRec memTab[]);


extern Int UNIVERSAL_DMA_TI_free(IALG_Handle handle, IALG_MemRec memTab[]);

extern Int UNIVERSAL_DMA_TI_initObj(IALG_Handle handle,
        const IALG_MemRec memTab[], IALG_Handle parent,
        const IALG_Params *algParams);

extern XDAS_Int32 UNIVERSAL_DMA_TI_process(IUNIVERSAL_Handle h,
        XDM1_BufDesc *inBufs, XDM1_BufDesc *outBufs, XDM1_BufDesc *inOutBufs,
        IUNIVERSAL_InArgs *inArgs, IUNIVERSAL_OutArgs *outArgs);

extern XDAS_Int32 UNIVERSAL_DMA_TI_control(IUNIVERSAL_Handle handle,
        IUNIVERSAL_Cmd id, IUNIVERSAL_DynamicParams *dynParams,
        IUNIVERSAL_Status *status);

#endif /* UNIVERSAL_DMA_TI_PRIV_ */
/*
 *  @(#) ti.sdo.fc.ires.examples.codecs.universal_dma; 1, 0, 0,4; 2-22-2012 18:06:01; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

