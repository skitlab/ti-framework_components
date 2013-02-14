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
 *  ======== TsrKnl.c ========
 *
 */

/* this define must precede inclusion of any xdc header file */
#define Registry_CURDESC TsrKnl__Desc
#define MODULE_NAME "TsrKnl"

#include <string.h>

/* xdctools header files */
#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Registry.h>
#include <xdc/runtime/Timestamp.h>
#include <xdc/runtime/Types.h>

/* package header files */
#include <ti/sdo/fc/ecpy/ecpy.h>
#include <ti/sdo/fc/ires/edma3chan/edma3Chan2Lite.h>

/* local header files */
#include "TsrKnl.h"

#define BlkDimX 64              // 2D block transfer dimensions
#define BlkDimY 48

#define IRES_NumRes     1       // number of ires resources to allocate
#define RMAN_ResId      1       // unique resource id

/* configuration data */
#define TsrKnl_IBUFA_Base   0x40050000
#define TsrKnl_IBUFA_Len    0x8000
#define TsrKnl_IBUFB_Base   0x40070000
#define TsrKnl_IBUFB_Len    0x8000
#define TsrKnl_lumFloat     0

/* log string macros */
#define LOGSECT ".string.log.autoviz.compute"
#define mkpragma(x) _Pragma(#x)
#define mkdata(n,s) mkpragma(DATA_SECTION(n,s))
#define MKLOGSTR(i,s) mkdata(LogStr_##i, LOGSECT) \
static const char LogStr_##i[] = s
#define LOGSTR(i) (LogStr_##i)

/* define log strings */
#ifdef xdc_runtime_Log_DISABLE_ALL
#undef xdc_runtime_Log_DISABLE_ALL
#endif

#if xdc_runtime_Log_DISABLE_ALL == 0
MKLOGSTR( 1, "--> TsrKnl_process: (src=0x%x, dst=0x%x, dimX=%d, dimY=%d)");
MKLOGSTR( 2, "<-- TsrKnl_process:");
MKLOGSTR( 3, "--> TsrKnl_block: (0x%x --> 0x%x --> 0x%x, work=0x%x)");
MKLOGSTR( 4, "TsrKnl_block: size=%d, num=%d, imgStride=%d, bufStride=%d");
MKLOGSTR( 5, "TsrKnl_block: txBuf=0x%x --> dstImg=0x%x");
MKLOGSTR( 6, "TsrKnl_block: srcImg=0x%x --> txBuf=0x%x");
MKLOGSTR( 7, "TsrKnl_block: process buf=0x%x");
MKLOGSTR( 8, "TsrKnl_block: waited %d msec");
MKLOGSTR( 9, "<-- TsrKnl_block:");
MKLOGSTR(10, "TsrKnl_init: EDMA3CHAN2 allocateResources failed");
MKLOGSTR(11, "TsrKnl_init: ECPY_createHandle failed");
MKLOGSTR(12, "TsrKnl_exit: EDMA3CHAN2_freeHandle failed");
MKLOGSTR(13, "TsrKnl_process: image not even block size; dimX=%d, dimY=%d");
#endif

/* private functions */
static void TsrKnl_block(Void *srcImg, Void *dstImg,
        UShort elemSize, UShort numElem, Short imgStride, Short bufStride,
        Void *txBuf, Void *workBuf);

/* instance object */
typedef struct TsrKnl_Object_tag {
    IRES_EDMA3CHAN_ProtocolArgs protocolArgs[IRES_NumRes];
    IRES_ResourceDescriptor     resDesc[IRES_NumRes];
    IRES_ProtocolRevision       protocolRev;
    ECPY_Handle                 ecpy;
    ECPY_Params                 ecpyParams;
    Bits32                      cpuFreqMs;      // cpu cycles per millisecond
} TsrKnl_Object;

/* private data */
static Int              curInit = 0;
Registry_Desc           Registry_CURDESC;
static TsrKnl_Object    Mod_Obj;


/*
 *  ======== TsrKnl_init ========
 */
Void TsrKnl_init(Void)
{
    Registry_Result             result;
    TsrKnl_Object *             mod = &Mod_Obj;
//  IRES_Status                 status;
    Types_FreqHz                freq;


    if (curInit++ != 0) {
        return;  /* already initialized */
    }

    /* register with xdc.runtime to get a diags mask */
    result = Registry_addModule(&Registry_CURDESC, MODULE_NAME);
    Assert_isTrue(result == Registry_SUCCESS, (Assert_Id)NULL);

    /* initialize module state */
    mod->ecpy = NULL;

    /* initialize modules */
    ECPY_init();

    /* request protocol version 2.0.0 */
    IRES_EDMA3CHAN_SETPROTOCOLREVISION_2_0_0(&mod->protocolRev);

    mod->resDesc[0].resourceName = IRES_EDMA3CHAN_PROTOCOLNAME;
    mod->resDesc[0].revision = &mod->protocolRev;

    /* set EDMA3 request descriptor protocol args */
    mod->protocolArgs[0].size = sizeof(IRES_EDMA3CHAN_ProtocolArgs);
    mod->protocolArgs[0].mode = IRES_PERSISTENT;
    mod->protocolArgs[0].numPaRams = 2;  // must match config script
    mod->protocolArgs[0].paRamIndex = IRES_EDMA3CHAN_PARAM_ANY;
    mod->protocolArgs[0].tccIndex = IRES_EDMA3CHAN_TCC_ANY;
    mod->protocolArgs[0].numTccs = 1;  // must match config script
    mod->protocolArgs[0].qdmaChan = IRES_EDMA3CHAN_CHAN_NONE;
    mod->protocolArgs[0].edmaChan = IRES_EDMA3CHAN_EDMACHAN_ANY;
    mod->protocolArgs[0].contiguousAllocation = FALSE;
    mod->protocolArgs[0].shadowPaRamsAllocation = FALSE;

    mod->resDesc[0].protocolArgs = (IRES_ProtocolArgs *)&(mod->protocolArgs[0]);
    mod->resDesc[0].handle = (IRES_Handle)NULL;

    mod->resDesc[0].handle = (IRES_Obj *)EDMA3CHAN2_createHandle(
            (IALG_Handle)RMAN_ResId, &mod->protocolArgs[0], 0 /* -1 */);
            //Using scratch grp 0. because of limitation of EDMA3CHANLITE

    if (NULL == mod->resDesc[0].handle) {
        Log_error0(LOGSTR(10));
    }

    mod->ecpy = ECPY_createHandle(
        (IRES_EDMA3CHAN2_Handle)(mod->resDesc[0].handle), (IALG_Handle)1);

    if (mod->ecpy == NULL) {
        Log_error0(LOGSTR(11));
        /* TODO need to fail back to the HOST processor */
    }

    ECPY_activate(mod->ecpy);

    /* define base transfer type */
    mod->ecpyParams.transferType = ECPY_2D2D;
    mod->ecpyParams.numFrames = 1;
    mod->ecpyParams.srcFrameIndex = 1;
    mod->ecpyParams.dstFrameIndex = 1;

    /* get the cpu frequency in hertz */
    Timestamp_getFreq(&freq);
    mod->cpuFreqMs = freq.lo / 1000;
}


/*
 *  ======== TsrKnl_exit ========
 */
Void TsrKnl_exit(Void)
{
//  Registry_Result     result;
    IRES_Status         status;
    TsrKnl_Object *     mod = &Mod_Obj;


    if (curInit-- != 1) {
        return;  /* object still being used */
    }

    ECPY_deactivate(mod->ecpy);
    ECPY_deleteHandle(mod->ecpy);

    status = EDMA3CHAN2_freeHandle((IALG_Handle)RMAN_ResId,
            (IRES_EDMA3CHAN2_Handle)mod->resDesc[0].handle,
            &mod->protocolArgs[0], -1);

    if (status != IRES_OK) {
        Log_error0(LOGSTR(12));
    }

    /* finalize modules */
    ECPY_exit();

    /* unregister from xdc.runtime */
//  result = Registry_removeModule(MODULE_NAME);
//  Assert_isTrue(result == Registry_SUCCESS, (Assert_Id)NULL);
}


/*
 *  ======== TsrKnl_process ========
 *  Traffic Sign Recognition OpenCL C kernel
 *
 *  This example OpenCL C kernel processes an input image and stores the
 *  result in an output image. The image data is transferred in 2D-blocks.
 *  Pipline processing is used to execute the data transfers in parallel
 *  with the block processing.
 */
Void TsrKnl_process(UInt *srcImg, UInt *dstImg, Int imgDimX, Int imgDimY)
{
    Void *      nextSrc;
    Void *      prevDst;
    Void *      txBuf;
    Void *      workBuf;
    Void *      IBufAry[2];
    UInt        IBufIdx;
    Int         numBlks, numBlksX, numBlksY;
    Int         nextBlkX, nextBlkY;
    Int         prevBlkX, prevBlkY;
    Int         blk;


    Log_print4(Diags_ENTRY | Diags_INFO, LOGSTR(1),
        (IArg)srcImg, (IArg)dstImg, (IArg)imgDimX, (IArg)imgDimY);

    /* image resolution must be integral of block resolution */
    if (((imgDimX % BlkDimX) != 0) || ((imgDimY % BlkDimY) != 0)) {
        Log_error2(LOGSTR(13), (IArg)BlkDimX, (IArg)BlkDimY);
        goto leave;
    }

    /* define work buffer pool */
    IBufAry[0] = (Void *)TsrKnl_IBUFA_Base;
    IBufAry[1] = (Void *)TsrKnl_IBUFB_Base;
    IBufIdx = 0;

    /* compute number of blocks */
    numBlksX = imgDimX / BlkDimX;
    numBlksY = imgDimY / BlkDimY;
    numBlks  = numBlksX * numBlksY;

    /* prime the pipeline */
    txBuf = IBufAry[IBufIdx++ % 2];
    nextSrc = (Void *)srcImg;
    TsrKnl_block(nextSrc, NULL, BlkDimX * sizeof(UInt), BlkDimY,
        imgDimX * sizeof(UInt), BlkDimX * sizeof(UInt), txBuf, NULL);

    /* process block 0 */
    workBuf = txBuf;
    txBuf = IBufAry[IBufIdx++ % 2];
    nextSrc = (Void *)(srcImg + BlkDimX);
    TsrKnl_block(nextSrc, NULL, BlkDimX * sizeof(UInt), BlkDimY,
        imgDimX * sizeof(UInt), BlkDimX * sizeof(UInt), txBuf, workBuf);

    /* process block 1 */
    workBuf = txBuf;
    txBuf = IBufAry[IBufIdx++ % 2];
    nextSrc = (Void *)(srcImg + (2 * BlkDimX));
    prevDst = dstImg;
    TsrKnl_block(nextSrc, prevDst, BlkDimX * sizeof(UInt), BlkDimY,
        imgDimX * sizeof(UInt), BlkDimX * sizeof(UInt), txBuf, workBuf);

    /* process blocks 2 - (numBlks - 2) */
    for (blk = 2; blk <= (numBlks - 2); blk++) {
        workBuf = txBuf;
        txBuf = IBufAry[IBufIdx++ % 2];

        nextBlkY = (blk + 1) / numBlksX;
        nextBlkX = (blk + 1) - (nextBlkY * numBlksX);
        nextSrc = (Void *)(srcImg + (nextBlkY * imgDimX * BlkDimY)
            + (nextBlkX * BlkDimX));

        prevBlkY = (blk - 1) / numBlksX;
        prevBlkX = (blk - 1) - (prevBlkY * numBlksX);
        prevDst = (Void *)(dstImg + (prevBlkY * imgDimX * BlkDimY)
            + (prevBlkX * BlkDimX));

        TsrKnl_block(nextSrc, prevDst, BlkDimX * sizeof(UInt), BlkDimY,
            imgDimX * sizeof(UInt), BlkDimX * sizeof(UInt), txBuf, workBuf);
    }

    /* process last block */
    workBuf = txBuf;
    txBuf = IBufAry[IBufIdx++ % 2];
    prevBlkY = (numBlks - 2) / numBlksX;
    prevBlkX = (numBlks - 2) - (prevBlkY * numBlksX);
    prevDst = (Void *)(dstImg + (prevBlkY * imgDimX * BlkDimY)
        + (prevBlkX * BlkDimX));
    TsrKnl_block(NULL, prevDst, BlkDimX * sizeof(UInt), BlkDimY,
        imgDimX * sizeof(UInt), BlkDimX * sizeof(UInt), txBuf, workBuf);

    /* drain the pipeline */
    txBuf = IBufAry[IBufIdx++ % 2];
    prevBlkY = (numBlks - 1) / numBlksX;
    prevBlkX = (numBlks - 1) - (prevBlkY * numBlksX);
    prevDst = (Void *)(dstImg + (prevBlkY * imgDimX * BlkDimY)
        + (prevBlkX * BlkDimX));
    TsrKnl_block(NULL, prevDst, BlkDimX * sizeof(UInt), BlkDimY,
        imgDimX * sizeof(UInt), BlkDimX * sizeof(UInt), txBuf, NULL);

leave:
    Log_print0(Diags_EXIT, LOGSTR(2));
}


/*
 *  ======== TsrKnl_block ========
 *  Transfer and process data blocks in parallel
 *
 *  Two linked transfers are used to move data out of and into the
 *  transfer buffer. While the data transfer is in progress, the work
 *  buffer is processed. The function waits for the data transfers to
 *  complete before returning.
 */
void TsrKnl_block(Void *srcImg, Void *dstImg,
        UShort elemSize, UShort numElem, Short imgStride, Short bufStride,
        Void *txBuf, Void *workBuf)
{
    TsrKnl_Object *     mod = &Mod_Obj;
    Bits32              time0;
    Bits32              time1;
    Bits32              waitCycles;
    UInt                waitTimeMs;
    Short               bx, by;
    UInt                data;
    UChar               lum;
    UInt *              elemPtr;
    Short               txNum = 0;


    Log_print4(Diags_ENTRY | Diags_INFO, LOGSTR(3),
        (IArg)srcImg, (IArg)txBuf, (IArg)dstImg, (IArg)workBuf);
    Log_print4(Diags_INFO, LOGSTR(4),
        (IArg)elemSize, (IArg)numElem, (IArg)imgStride, (IArg)bufStride);

    /* transfer out previous block */
    if (dstImg != NULL) {
        Log_print2(Diags_USER1, LOGSTR(5), (IArg)txBuf, (IArg)dstImg);

        txNum++;
        mod->ecpyParams.srcAddr = txBuf;
        mod->ecpyParams.dstAddr = dstImg;
        mod->ecpyParams.elementSize = elemSize;
        mod->ecpyParams.numElements = numElem;
        mod->ecpyParams.srcElementIndex = bufStride;
        mod->ecpyParams.dstElementIndex = imgStride;
        ECPY_directConfigure(mod->ecpy, &mod->ecpyParams, txNum);
    }

    /* transfer in next block */
    if (srcImg != NULL) {
        Log_print2(Diags_USER1, LOGSTR(6), (IArg)srcImg, (IArg)txBuf);

        txNum++;
        mod->ecpyParams.srcAddr = srcImg;
        mod->ecpyParams.dstAddr = txBuf;
        mod->ecpyParams.elementSize = elemSize;
        mod->ecpyParams.numElements = numElem;
        mod->ecpyParams.srcElementIndex = imgStride;
        mod->ecpyParams.dstElementIndex = bufStride;
        ECPY_directConfigure(mod->ecpy, &mod->ecpyParams, txNum);
    }

    /* start the data transfer in background */
    if (txNum > 0) {
        ECPY_directSetFinal(mod->ecpy, txNum);
        ECPY_directStartEdma(mod->ecpy);
    }

    /* process current block in parallel with data transfer */
    if (workBuf != NULL) {
        Log_print1(Diags_USER1, LOGSTR(7), (IArg)workBuf);

        /* convert to gray scale for demo purposes */
        for (by = 0; by < BlkDimY; by++) {
            for (bx = 0; bx < BlkDimX; bx++) {
                elemPtr = (UInt *)workBuf + (by * BlkDimX) + bx;
                data = *elemPtr;

                if (TsrKnl_lumFloat) {
                    /* lum = 0.30 red + 0.59 green + 0.11 blue */
                    lum = (UChar)
                        (((float)((0xFF & data)) * 0.30) +
                        ((float)((0xFF00 & data) >> 8) * 0.59) +
                        ((float)((0xFF0000 & data) >>  16) * 0.11));
                    *elemPtr = 0xFF000000 | (lum << 16)| (lum << 8) | lum;
                }
                else {
                    /* lum = 0.30 red + 0.59 green + 0.11 blue (fast) */
                    lum = (UChar)
                        (((0xFF & data) * 3 / 10) +
                        (((0xFF00 & data) >> 8) * 6 / 10) +
                        (((0xFF0000 & data) >>  16) / 10));
                    *elemPtr = 0xFF000000 | (lum << 16)| (lum << 8) | lum;
                }
            }
        }
    }

    /* latch start count */
    time0 = Timestamp_get32();

    /* wait for data transfers to complete */
    if (txNum > 0) {
        ECPY_directWait(mod->ecpy);
    }

    /* latch stop count */
    time1 = Timestamp_get32();

    /* compute wait time in milliseconds */
    waitCycles = time1 - time0;
    waitTimeMs = waitCycles / mod->cpuFreqMs;
    waitTimeMs += (waitCycles%mod->cpuFreqMs) >= (mod->cpuFreqMs>>1) ? 1 : 0;
    Log_print1(Diags_USER1, LOGSTR(8), (IArg)waitTimeMs);

    Log_print0(Diags_EXIT, LOGSTR(9));
}


/* TsrKnl_process() argument types */
UInt TsrKnl_process_args[] = {
    ti_cl_arg_type_GlobalPtr,
    ti_cl_arg_type_GlobalPtr,
    ti_cl_arg_type_Int,
    ti_cl_arg_type_Int
};

/* kernel function table */
ComputeDevice_FxnDesc TsrKnl_fxnTab[] = {
    {
        "TsrKnl_process",       /* fxn name     */
        (Fxn)TsrKnl_process,    /* fxn address  */
        4,                      /* num args     */
        TsrKnl_process_args     /* arg types    */
    }
};
/*
 *  @(#) ti.sdo.opencl.examples.autoviz; 1, 0, 0,4; 2-22-2012 18:09:18; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

