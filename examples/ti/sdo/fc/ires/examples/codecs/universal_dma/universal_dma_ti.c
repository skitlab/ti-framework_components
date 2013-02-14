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
 *  ======== universal_dma_ti.c ========
 *  This file contains an implementation of the IUNIVERSAL_Fxns interface, for
 *  a "copy" algorithm that uses the example IRES EDMA3CHAN resource.
 *  This algorithm implements the IRES_Fxns to allow the resources it uses
 *  to be granted and used by the algorithm. The IRES_Fxns implementation
 *  is in its own source file, separate from this file.
 */
#include <xdc/std.h>
#include <string.h>

#include <ti/xdais/trace.h>

#include <ti/xdais/dm/iuniversal.h>

#include <ti/xdais/ires.h>
#include <ti/sdo/fc/ecpy/ecpy.h>
#include <ti/sdo/fc/memutils/memutils.h>
#include <ti/sdo/fc/examples/dmaXfer/simpleDma.h>

#ifdef DMACHECK
#include <ti/sdo/fc/examples/dmaxferchecker/dmaxferchecker.h>
#endif

/* This define is to get rid of warnings related to unused static variable
   IRES_EDMA3CHAN_PROTOCOLREVISION in the ires_edma3Chan.h header */
#define ti_sdo_fc_ires_NOPROTOCOLREV

#include "universal_dma_ti.h"
#include "universal_dma_ti_priv.h"

extern IALG_Fxns UNIVERSAL_DMA_TI_IALG;

#define IALGFXNS  \
    &UNIVERSAL_DMA_TI_IALG,    /* module ID */                         \
    NULL,                      /* activate */                          \
    UNIVERSAL_DMA_TI_alloc,    /* alloc */                             \
    NULL,                      /* control (NULL => no control ops) */  \
    NULL,                      /* deactivate */                        \
    UNIVERSAL_DMA_TI_free,     /* free */                              \
    UNIVERSAL_DMA_TI_initObj,  /* init */                              \
    NULL,                      /* moved */                             \
    UNIVERSAL_DMA_TI_numalloc  /* numAlloc (NULL => IALG_MAXMEMRECS) */

#define BUFSIZE 0x400

static Void contextSave(IALG_Handle algHandle, Void *contextArgs);
static Void contextRestore(IALG_Handle algHandle, Void *contextArgs);

Int UNIVERSAL_DMA_TI_doCopy(IUNIVERSAL_Handle handle, unsigned int *src,
        unsigned int *dst, unsigned int size);

/*
 *  ======== UNIVERSAL_DMA_TI_CODECIRES ========
 *  This structure defines TI's implementation of the IUNIVERSAL interface
 *  for the UNIVERSAL_DMA_TI module.
 */
IUNIVERSAL_Fxns UNIVERSAL_DMA_TI_CODECIRES = {    /* module_vendor_interface */
    {IALGFXNS},
    UNIVERSAL_DMA_TI_process,
    UNIVERSAL_DMA_TI_control,
};

/*
 *  The XDAIS-required 'bare' IALG struct.
 */
IALG_Fxns UNIVERSAL_DMA_TI_IALG = {      /* module_vendor_interface */
    IALGFXNS
};

IUNIVERSAL_Params UNIVERSAL_DMA_TI_PARAMS = {
    sizeof(IUNIVERSAL_Params),
};

/*
 *  ======== UNIVERSAL_DMA_TI_numalloc ========
 */
/* ARGSUSED */
Int UNIVERSAL_DMA_TI_numalloc(const IALG_Params *algParams,
    IALG_Fxns **pf, IALG_MemRec memTab[])
{
    TRACE_3print( (IALG_Handle) NULL, TRACE_ENTER,
            "UNIVERSAL_DMA_TI_numalloc> Enter (algParams=0x%x, "
            "pf=0x%x, memTab=0x%x)\n", algParams, pf, memTab);

    TRACE_0print( (IALG_Handle) NULL, TRACE_ENTER,
            "UNIVERSAL_DMA_TI_numalloc> Exit\n");
    return 6;
}

/*
 *  ======== UNIVERSAL_DMA_TI_alloc ========
 */
/* ARGSUSED */
Int UNIVERSAL_DMA_TI_alloc(const IALG_Params *algParams,
    IALG_Fxns **pf, IALG_MemRec memTab[])
{
    TRACE_3print( (IALG_Handle) NULL, TRACE_ENTER,
            "UNIVERSAL_DMA_TI_alloc> Enter (algParams=0x%x, "
            "pf=0x%x, memTab=0x%x)\n", algParams, pf, memTab);
    /* Request memory for my object */
    memTab[0].size = sizeof(UNIVERSAL_DMA_TI_Obj);
    memTab[0].alignment = 0;
    memTab[0].space = IALG_EXTERNAL;
    memTab[0].attrs = IALG_PERSIST;

    TRACE_1print( (IALG_Handle) NULL,TRACE_4CLASS,
            "UNIVERSAL_DMA_TI_alloc> Allocation of type "
            "IALG_EXTERNAL IALG_PERSIST of size 0x%x\n",memTab[0].size);
    /* Request memory for my object */
    memTab[1].size = BUFSIZE;
    memTab[1].alignment = 0;
    memTab[1].space = IALG_EXTERNAL;
    memTab[1].attrs = IALG_PERSIST;

    TRACE_1print( (IALG_Handle) NULL,TRACE_4CLASS,
            "UNIVERSAL_DMA_TI_alloc> Allocation of type "
            "IALG_EXTERNAL IALG_PERSIST of size 0x%x\n",memTab[1].size);

    memTab[2].size = BUFSIZE;
    memTab[2].alignment = 0;
    memTab[2].space = IALG_EXTERNAL;
    memTab[2].attrs = IALG_PERSIST;

    TRACE_1print( (IALG_Handle) NULL,TRACE_4CLASS,
            "UNIVERSAL_DMA_TI_alloc> Allocation of type "
            "IALG_EXTERNAL IALG_PERSIST of size 0x%x\n",memTab[2].size);

    memTab[3].size = 256;
    memTab[3].alignment = 0;
    memTab[3].space = IALG_DARAM0;
    memTab[3].attrs = IALG_SCRATCH;

    memTab[4].size = 128;
    memTab[4].alignment = 0;
    memTab[4].space = IALG_DARAM0;
    memTab[4].attrs = IALG_SCRATCH;

    memTab[5].size = 128;
    memTab[5].alignment = 0;
    memTab[5].space = IALG_SARAM0;
    memTab[5].attrs = IALG_SCRATCH;


    TRACE_0print( (IALG_Handle) NULL, TRACE_ENTER,
            "UNIVERSAL_DMA_TI_alloc> Exit (status=1)\n");
    return (6);
}

/*
 *  ======== UNIVERSAL_DMA_TI_free ========
 */
/* ARGSUSED */
Int UNIVERSAL_DMA_TI_free(IALG_Handle handle, IALG_MemRec memTab[])
{
    return (UNIVERSAL_DMA_TI_alloc(NULL, NULL, memTab));
}

/*
 *  ======== UNIVERSAL_DMA_TI_initObj ========
 */
/* ARGSUSED */
Int UNIVERSAL_DMA_TI_initObj(IALG_Handle handle, const IALG_MemRec memTab[],
    IALG_Handle p, const IALG_Params *algParams)
{
    UNIVERSAL_DMA_TI_Obj *obj = (UNIVERSAL_DMA_TI_Obj *)handle;
    const IUNIVERSAL_Params *params = (IUNIVERSAL_Params *)algParams;

    /*
     * In lieu of xDM defined default params, use our codec-specific ones.
     * Note that these default values _should_ be documented in your algorithm
     * documentation so users know what to expect.
     */
    if (params == NULL) {
        params = &UNIVERSAL_DMA_TI_PARAMS;
    }

    /*
     * Also save the context save restore functions in the algorithm instance
     * This can be done any time after the algorithm instance is created.
     * Not necessary to do it here
     */
    (obj->yieldContext).contextSave = contextSave;
    (obj->yieldContext).contextRestore = contextRestore;
    (obj->yieldContext).contextArgs = &(obj->contextArgs);

    (obj->srcBuf) = memTab[1].base;
    (obj->dstBuf) = memTab[2].base;

    return (IALG_EOK);
}

/* ARGSUSED */
static Void contextSave(IALG_Handle algHandle, Void *contextArgs)
{
    /* UNIVERSAL_DMA_TI_Obj  *alg = (UNIVERSAL_DMA_TI_Obj *)algHandle;*/
    /* UNIVERSAL_DMA_TI_CtxtArgs *ctxt = (UNIVERSAL_DMA_TI_CtxtArgs *)contextArgs;*/
    /*
     * Add code here to save context of the algorithm object
     * Could involve something like copying scratch Memory contents into
     * permanent etc
     * Contents will depend on where in algorithms execution it "yields" to
     * another algorithm
     */
}


/* ARGSUSED */
static Void contextRestore(IALG_Handle algHandle, Void *contextArgs)
{
    /* UNIVERSAL_DMA_TI_Obj  *alg = (UNIVERSAL_DMA_TI_Obj *)algHandle;*/
    /* UNIVERSAL_DMA_TI_CtxtArgs * ctxt = (UNIVERSAL_DMA_TI_CtxtArgs *)contextArgs;*/
    /*
     * Add code here to restore context of the algorithm object
     * During the yield of this algorithm, another algorithm ran and might have
     * messed up the scratch state of this algorithm
     */
}

/* ARGSUSED */
Int UNIVERSAL_DMA_TI_doCopy(IUNIVERSAL_Handle handle, unsigned int *src,
        unsigned int *dst, unsigned int size)
{
    /* Extract channel granted to this alg */
    UNIVERSAL_DMA_TI_Obj * algHandle = (UNIVERSAL_DMA_TI_Obj *)handle;

#ifndef CUSTOM_EDMAXFERUTIL
    ECPY_Params p;
    int size1D1D = 0;
    int frameSize;
    ECPY_Handle dmaHandle0 = algHandle->ecpyHandle[0];
    ECPY_Handle dmaHandle1 = algHandle->ecpyHandle[1];
    ECPY_Handle dmaHandle2 = algHandle->ecpyHandle[2];
#endif

#if defined(CUSTOM_EDMAXFERUTIL) || defined(DMACHECK)
    Int channel0 = algHandle->edmaHandle[0]->assignedEdmaChannelIndex;
#endif

#ifdef CUSTOM_EDMAXFERUTIL

    /* Do 1D DMA on channel # 1 */
    do1DDma((unsigned int)src, (unsigned int)dst, size, channel0);
#else
    ECPY_activate(dmaHandle0);
    ECPY_activate(dmaHandle1);
    ECPY_activate(dmaHandle2);

    /* Setting up the parameters for the first transfer (data grp 1) */
    p.transferType = ECPY_1D1D;

    p.dstAddr = (void *)dst;
    p.srcAddr = (void *)src;
    p.elementSize = size;
    p.numElements = 1;
        p.numFrames = 1;
    /*
            p.srcElementIndex = 16 * 4;
            p.srcFrameIndex = 1;
            p.dstFrameIndex = 1;
    i*/

    /*
     * Configure transfer number 1 on the active DMA handle with the
     * parameters set up above
     */
    ECPY_configure(dmaHandle0, &p, 1);
    //ECPY_configure16(dmaHandle0, ECPY_PARAMFIELD_ELEMENTSIZE, size/8, 1);

    size1D1D= size/32;
    ECPY_configure16(dmaHandle0, ECPY_PARAMFIELD_ELEMENTSIZE, size1D1D, 1);
    ECPY_configure16(dmaHandle0, ECPY_PARAMFIELD_FRAMEINDEX_SRC, size1D1D, 1);
    ECPY_configure16(dmaHandle0, ECPY_PARAMFIELD_FRAMEINDEX_DST, size1D1D, 1);
    ECPY_configure16(dmaHandle0, ECPY_PARAMFIELD_NUMFRAMES, 4, 1);

    ECPY_configure(dmaHandle0, &p, 2);
    ECPY_configure16(dmaHandle0, ECPY_PARAMFIELD_ELEMENTSIZE, size/8, 2);
    ECPY_configure32(dmaHandle0, ECPY_PARAMFIELD_SRCADDR,
            (unsigned int)src + size/8, 2);
    ECPY_configure32(dmaHandle0, ECPY_PARAMFIELD_DSTADDR,
            (unsigned int)dst + size/8, 2);

    ECPY_configure(dmaHandle0, &p, 3);
    ECPY_configure16(dmaHandle0, ECPY_PARAMFIELD_ELEMENTSIZE, size/4, 3);
    ECPY_configure32(dmaHandle0, ECPY_PARAMFIELD_SRCADDR,
            (unsigned int)src + size/4, 3);
    ECPY_configure32(dmaHandle0, ECPY_PARAMFIELD_DSTADDR,
            (unsigned int)dst + size/4, 3);

    ECPY_setDestinationMemoryMode(dmaHandle0, INTMEMORY1);
    ECPY_setDestinationMemoryMode(dmaHandle0, EXTMEMORY0);

    ECPY_setFinal(dmaHandle0, 1);
    ECPY_start(dmaHandle0);
    ECPY_wait(dmaHandle0);

    ECPY_setFinal(dmaHandle0, 2);
    ECPY_start(dmaHandle0);
    ECPY_wait(dmaHandle0);

    ECPY_setFinal(dmaHandle0, 3);
    ECPY_start(dmaHandle0);
    ECPY_wait(dmaHandle0);

    p.transferType = ECPY_2D2D;
    p.elementSize = 4;
    p.numElements = 4;

    /* Each transfer will skip alternating elemenr-size blocks. */
    p.srcElementIndex = 2 * 4;
    p.dstElementIndex = 2 * 4;

    /* Each Frame has elemensize holes between elements.No gap between frames */
    frameSize = 4 * 4 * 2;
    p.srcFrameIndex = frameSize;
    p.dstFrameIndex = frameSize;

    /* No gap between frames */
    p.numFrames = (size/8) / frameSize;

    ECPY_directConfigure(dmaHandle0, &p, 1);

//  ECPY_directConfigure16(dmaHandle0, ECPY_PARAMFIELD_ELEMENTSIZE,size/8, 1);
    ECPY_directConfigure32(dmaHandle0, ECPY_PARAMFIELD_SRCADDR,
            (unsigned int)src + size/2, 1);
    ECPY_directConfigure32(dmaHandle0, ECPY_PARAMFIELD_DSTADDR,
            (unsigned int)dst + size/2, 1);

    /* submit as a single 3D transfer */
    ECPY_directSetFinal(dmaHandle0, 1);
    ECPY_directStartEdma(dmaHandle0);
    ECPY_directWait(dmaHandle0);

    /* prepare linked transfer, where the 1st one gets configured to fill
     * the gaps in the striped element block shaped frames of previous transfer
     */
    ECPY_directConfigure(dmaHandle1, &p, 1);
    ECPY_directConfigure32(dmaHandle1, ECPY_PARAMFIELD_SRCADDR,
            (unsigned int)src + size/2 + p.elementSize, 1);
    ECPY_directConfigure32(dmaHandle1, ECPY_PARAMFIELD_DSTADDR,
            (unsigned int)dst + size/2 + p.elementSize, 1);


    p.transferType = ECPY_1D1D;
    p.numFrames = 1;

    ECPY_directConfigure(dmaHandle1, &p, 2);
    ECPY_directConfigure16(dmaHandle1, ECPY_PARAMFIELD_ELEMENTSIZE,size/4, 2);
    ECPY_directConfigure32(dmaHandle1, ECPY_PARAMFIELD_SRCADDR,
            (unsigned int)src + (size/2 + size/8), 2);
    ECPY_directConfigure32(dmaHandle1, ECPY_PARAMFIELD_DSTADDR,
            (unsigned int)dst + (size/2 + size/8), 2);


    ECPY_directConfigure(dmaHandle1, &p, 3);
    ECPY_directConfigure16(dmaHandle1, ECPY_PARAMFIELD_ELEMENTSIZE,size/16,3);

    ECPY_directConfigure32(dmaHandle1, ECPY_PARAMFIELD_SRCADDR,
            (unsigned int)src + (size/2 + size/8 + size/4), 3);
    ECPY_directConfigure32(dmaHandle1, ECPY_PARAMFIELD_DSTADDR,
            (unsigned int)dst + (size/2 + size/8 + size/4), 3);

#ifdef DMACHECK
    checkEdmaXfer(channel0);
#endif
    ECPY_directSetFinal(dmaHandle1, 3);
    ECPY_directStartEdma(dmaHandle1);

    ECPY_directWait(dmaHandle1);

    /* 1st PaRAM must be reconfigured since prev transfer was linked */
    ECPY_directConfigure(dmaHandle1, &p, 1);

    ECPY_directConfigure16(dmaHandle1, ECPY_PARAMFIELD_ELEMENTSIZE,size/32,1);
    ECPY_directConfigure32(dmaHandle1, ECPY_PARAMFIELD_SRCADDR,
            (unsigned int)src + (size/2 + size/8 + size/4 + size/16), 1);
    ECPY_directConfigure32(dmaHandle1, ECPY_PARAMFIELD_DSTADDR,
            (unsigned int)dst + (size/2 + size/8 + size/4 + size/16), 1);

    ECPY_directConfigure16(dmaHandle1, ECPY_PARAMFIELD_ELEMENTSIZE,size/32,2);
    ECPY_directConfigure32(dmaHandle1, ECPY_PARAMFIELD_SRCADDR,
            (unsigned int)src + (size/2 + size/8 + size/4 + size/16 + size/32),
            2);
    ECPY_directConfigure32(dmaHandle1, ECPY_PARAMFIELD_DSTADDR,
            (unsigned int)dst + (size/2 + size/8 + size/4 + size/16 + size/32),
            2);

    ECPY_directSetFinal(dmaHandle1, 2);

    ECPY_directStartEdma(dmaHandle1);
    ECPY_directWait(dmaHandle1);

    ECPY_deactivate(dmaHandle0);
    ECPY_deactivate(dmaHandle1);
    ECPY_deactivate(dmaHandle2);

#ifdef DMACHECK
    checkEdmaXfer(channel0);
#endif

#endif

    return (0);
}

/*
 *  ======== UNIVERSAL_DMA_TI_process ========
 */
/* ARGSUSED Tells the compiler not to warn about unused arguments */
XDAS_Int32 UNIVERSAL_DMA_TI_process(IUNIVERSAL_Handle handle,
        XDM1_BufDesc *inBufs, XDM1_BufDesc *outBufs, XDM1_BufDesc *inOutArgs,
        IUNIVERSAL_InArgs *inArgs, IUNIVERSAL_OutArgs *outArgs)
{
    XDAS_Int32       numInBytes;
    UNIVERSAL_DMA_InArgs * args = (UNIVERSAL_DMA_InArgs *)inArgs;

    numInBytes = args->numBytes;

    /* everything looks good, do the 'encode', set outArgs and return */
    UNIVERSAL_DMA_TI_doCopy(handle, (unsigned int *)inBufs->descs[0].buf,
            (unsigned int *)outBufs->descs[0].buf, numInBytes);

    /* report _how_ we accessed the in/out data buffers */
    /* didn't use CPU to access either inBuf or outBufs */
    XDM_CLEARACCESSMODE_WRITE(inBufs->descs[0].accessMask);
    XDM_CLEARACCESSMODE_READ(inBufs->descs[0].accessMask);
    // XDM_SETACCESSMODE_READ(inBufs->descs[0].accessMask);

    XDM_CLEARACCESSMODE_READ(outBufs->descs[0].accessMask);
    XDM_CLEARACCESSMODE_WRITE(outBufs->descs[0].accessMask);
    //XDM_SETACCESSMODE_WRITE(outBufs->descs[0].accessMask);

    return (IUNIVERSAL_EOK);
}

/*
 *  ======== UNIVERSAL_DMA_TI_control ========
 */
/* ARGSUSED Tells the compiler not to warn about unused arguments */
XDAS_Int32 UNIVERSAL_DMA_TI_control(IUNIVERSAL_Handle handle, IUNIVERSAL_Cmd id,
    IUNIVERSAL_DynamicParams *dynParams, IUNIVERSAL_Status *status)
{
    return (IUNIVERSAL_EOK);
}

/*
 *  @(#) ti.sdo.fc.ires.examples.codecs.universal_dma; 1, 0, 0,4; 2-22-2012 18:06:01; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

