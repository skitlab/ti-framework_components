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
 *  ======== edmacodec1_ti_priv.h ========
 *  Internal vendor specific (TI) interface header for EDMACODEC1
 *  algorithm. Only the implementation source files include
 *  this header; this header is not shipped as part of the
 *  algorithm.
 *
 *  This header contains declarations that are specific to
 *  this implementation and which do not need to be exposed
 *  in order for an application to use the EDMACODEC1 algorithm.
 */
#ifndef EDMACODEC1_TI_PRIV_
#define EDMACODEC1_TI_PRIV_


#include <ti/xdais/ires.h>
#include <ti/sdo/fc/ires/edma3chan/ires_edma3Chan.h> 

#define EDMACODEC1_TI_NUM_EDMACHANS 3

typedef struct EDMACODEC1_TI_CtxtArgs {
    Int size;           
} EDMACODEC1_TI_CtxtArgs;

typedef struct EDMACODEC1_TI_Obj {
    IALG_Obj       alg;            /* MUST be first field of all XDAS algs */

    /* IRES stuff */
    IRES_EDMA3CHAN2_Handle      edmaHandle[EDMACODEC1_TI_NUM_EDMACHANS];
    IRES_ProtocolRevision       edma3chanRev;   
    ECPY_Handle                 ecpyHandle[EDMACODEC1_TI_NUM_EDMACHANS];
    short                       paramArray[512];
    IRES_EDMA3CHAN_ProtocolArgs edmaArgs; 
    Bool                        resActive[2];   /* Is the resource active? */
    IRES_YieldFxn               yieldFxn;
    IRES_YieldArgs              yieldArgs;
    IRES_YieldContext           yieldContext;        
    EDMACODEC1_TI_CtxtArgs      contextArgs;
} EDMACODEC1_TI_Obj;

extern Int EDMACODEC1_TI_alloc(const IALG_Params *algParams, IALG_Fxns **pf,
    IALG_MemRec memTab[]);

extern Int EDMACODEC1_TI_free(IALG_Handle handle, IALG_MemRec memTab[]);

extern Int EDMACODEC1_TI_initObj(IALG_Handle handle, const IALG_MemRec memTab[],
        IALG_Handle parent, const IALG_Params *algParams);

extern XDAS_Int32 EDMACODEC1_TI_process(IEDMACODEC1_Handle h, XDM1_BufDesc *inBufs,
        XDM1_BufDesc *outBufs, IEDMACODEC1_InArgs *inArgs,
        IEDMACODEC1_OutArgs *outArgs);

extern XDAS_Int32 EDMACODEC1_TI_control(IEDMACODEC1_Handle handle, IEDMACODEC1_Cmd id,
    IEDMACODEC1_DynamicParams *dynParams, IEDMACODEC1_Status *status);

#endif /* EDMACODEC1_TI_PRIV_ */
/*
 *  @(#) ti.sdo.fc.ires.examples.codecs.edmacodec1; 1, 0, 0,4; 2-22-2012 18:05:44; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

