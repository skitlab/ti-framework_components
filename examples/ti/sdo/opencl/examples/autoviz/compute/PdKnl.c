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
 *  ======== PdKnl.c ========
 *
 */

/* this define must precede inclusion of any xdc header file */
#define Registry_CURDESC PdKnl__Desc
#define MODULE_NAME "PdKnl"

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
#include "PdKnl.h"

#define DMAXFER_BUFSIZE 0x400
#define BUFSIZE 512
#define BUFALIGN 0
// #define BLOCK_SIZE (15 * 0x400)      // 320x240 image
#define BLOCK_SIZE (12 * 0x400)         // 192x144 image

#define IRES_NumRes     1       // number of ires resources to allocate
#define RMAN_ResId      2       // unique resource id

/* log string macros */
#define LOGSECT ".string.log.autoviz.compute"
#define mkpragma(x) _Pragma(#x)
#define mkdata(n,s) mkpragma(DATA_SECTION(n,s))
#define MKLOGSTR(i,s) mkdata(LogStr_##i, LOGSECT) \
static const char LogStr_##i[] = s
#define LOGSTR(i) (LogStr_##i)

/* define log strings */
#if xdc_runtime_Log_DISABLE_ALL == 0
MKLOGSTR( 1, "--> PdKnl_process: (src=0x%x, dst=0x%x, dimX=%d, dimY=%d)");
MKLOGSTR( 2, "PdKnl_process: image not even block size, img=0x%x, blk=0x%x");
MKLOGSTR( 3, "<-- PdKnl_process:");
MKLOGSTR( 4, "--> PdKnl_block: (0x%x --> 0x%x --> 0x%x, work=0x%x, size=0x%x)");
MKLOGSTR( 5, "PdKnl_block: txBuf=0x%x --> outDst=0x%x");
MKLOGSTR( 6, "PdKnl_block: inSrc=0x%x --> txBuf=0x%x");
MKLOGSTR( 7, "PdKnl_block: process buf=0x%x");
MKLOGSTR( 8, "PdKnl_block: waited %d msec");
MKLOGSTR( 9, "<-- PdKnl_block:");
MKLOGSTR(10, "PdKnl_init: EDMA3CHAN2 allocateResources failed");
MKLOGSTR(11, "PdKnl_init: ECPY_createHandle failed");
MKLOGSTR(12, "PdKnl_exit: EDMA3CHAN2_freeHandle failed");
#endif

/* private functions */
static void PdKnl_block(void *inSrc, void *outDst, void *txBuf,
        void *workBuf, int bufSize);

/* instance object */
typedef struct PdKnl_Object_tag {
    IRES_EDMA3CHAN_ProtocolArgs protocolArgs[IRES_NumRes];
    IRES_ResourceDescriptor     resDesc[IRES_NumRes];
    IRES_ProtocolRevision       protocolRev;
    ECPY_Handle                 ecpy;
    ECPY_Params                 ecpyParams;
    Bits32                      cpuFreqMs;      // cpu cycles per millisecond
} PdKnl_Object;


/* configuration data */
#define PdKnl_IBUFA_Base    0x40050000
#define PdKnl_IBUFA_Len     0x8000
#define PdKnl_IBUFB_Base    0x40070000
#define PdKnl_IBUFB_Len     0x8000
#define PdKnl_lumFloat      0


/* private data */
static Int              curInit = 0;
Registry_Desc           Registry_CURDESC;
static PdKnl_Object    Mod_Obj;


/*
 *  ======== PdKnl_init ========
 */
Void PdKnl_init(Void)
{
    Registry_Result             result;
    PdKnl_Object *              mod = &Mod_Obj;
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

    /* set EDMA3 Request Descriptor's protocol args */
    mod->protocolArgs[0].size = sizeof(IRES_EDMA3CHAN_ProtocolArgs);
    mod->protocolArgs[0].mode = IRES_PERSISTENT;
    mod->protocolArgs[0].numPaRams = 2;
    mod->protocolArgs[0].paRamIndex = IRES_EDMA3CHAN_PARAM_ANY;
    mod->protocolArgs[0].tccIndex = IRES_EDMA3CHAN_TCC_ANY;
    mod->protocolArgs[0].numTccs = 1;
    mod->protocolArgs[0].qdmaChan = IRES_EDMA3CHAN_CHAN_NONE;
    mod->protocolArgs[0].edmaChan = IRES_EDMA3CHAN_EDMACHAN_ANY;
    mod->protocolArgs[0].contiguousAllocation = FALSE;
    mod->protocolArgs[0].shadowPaRamsAllocation = FALSE;

    mod->resDesc[0].protocolArgs = (IRES_ProtocolArgs *)&(mod->protocolArgs[0]);
    mod->resDesc[0].handle = (IRES_Handle)NULL;

    /* using scratch group 0 because of EDMA3CHANLITE limitation */
    mod->resDesc[0].handle = (IRES_Obj *)EDMA3CHAN2_createHandle(
            (IALG_Handle)RMAN_ResId, &mod->protocolArgs[0], 0 /* -1 */);

    if (NULL == mod->resDesc[0].handle) {
        Log_error0(LOGSTR(10));
        /* TODO need to fail back to the HOST processor */
    }

    mod->ecpy = ECPY_createHandle(
        (IRES_EDMA3CHAN2_Handle)mod->resDesc[0].handle, (IALG_Handle)1);

    if (mod->ecpy == NULL) {
        Log_error0(LOGSTR(11));
        /* TODO need to fail back to the HOST processor */
    }

    ECPY_activate(mod->ecpy);

    /* define base transfer type */
    /* TODO init function? */
    mod->ecpyParams.transferType = ECPY_1D1D;
    mod->ecpyParams.numElements = 1;
    mod->ecpyParams.numFrames = 1;

    /* get the cpu frequency in hertz */
    Timestamp_getFreq(&freq);
    mod->cpuFreqMs = freq.lo / 1000;
}


/*
 *  ======== PdKnl_exit ========
 */
Void PdKnl_exit(Void)
{
//  Registry_Result     result;
    IRES_Status         status;
    PdKnl_Object *      mod = &Mod_Obj;


    if (curInit-- != 1) {
        return;  /* object still being used */
    }

    ECPY_deactivate(mod->ecpy);
    ECPY_deleteHandle(mod->ecpy);

    /* free allocated resources using the same requestId */
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
 *  ======== PdKnl_process ========
 *  Traffic Sign Recognition OpenCL C kernel
 */
Void PdKnl_process(UInt *srcImg, UInt *dstImg, Int dimX, Int dimY)
{
    UInt *              nextSrc;
    UInt *              prevDst;
    UInt *              txBuf;
    UInt *              workBuf;
    UInt *              IBufAry[2];
    UInt                IBufIdx;
    UInt                imgSize;
    Int                 numBlks;
    Int                 block;


    Log_print4(Diags_ENTRY | Diags_INFO, LOGSTR(1),
        (IArg)srcImg, (IArg)dstImg, (IArg)dimX, (IArg)dimY);

    /* make sure image size is integral of block size */
    imgSize = dimX * dimY * sizeof(UInt);

    if ((imgSize % BLOCK_SIZE) != 0) {
        Log_error2(LOGSTR(2), (IArg)imgSize, (IArg)BLOCK_SIZE);
        goto leave;
    }

    /* define work buffer pool */
    IBufAry[0] = (UInt *)PdKnl_IBUFA_Base;
    IBufAry[1] = (UInt *)PdKnl_IBUFB_Base;
    IBufIdx = 0;

    /* compute number of blocks */
    numBlks = imgSize / BLOCK_SIZE;

    /* prime the pipeline */
    txBuf = IBufAry[IBufIdx++ % 2];
    nextSrc = srcImg;
    PdKnl_block(nextSrc, NULL, txBuf, NULL, BLOCK_SIZE);

    /* process block 1 */
    workBuf = txBuf;
    txBuf = IBufAry[IBufIdx++ % 2];
    nextSrc = (UInt *)((Char *)nextSrc + BLOCK_SIZE);
    PdKnl_block(nextSrc, NULL, txBuf, workBuf, BLOCK_SIZE);

    /* process block 2 */
    workBuf = txBuf;
    txBuf = IBufAry[IBufIdx++ % 2];
    nextSrc = (UInt *)((Char *)nextSrc + BLOCK_SIZE);
    prevDst = dstImg;
    PdKnl_block(nextSrc, prevDst, txBuf, workBuf, BLOCK_SIZE);

    /* process blocks 3 - (numBlks-1) */
    for (block = 3; block < numBlks; block++) {
        workBuf = txBuf;
        txBuf = IBufAry[IBufIdx++ % 2];
        nextSrc = (UInt *)((Char *)nextSrc + BLOCK_SIZE);
        prevDst = (UInt *)((Char *)prevDst + BLOCK_SIZE);
        PdKnl_block(nextSrc, prevDst, txBuf, workBuf, BLOCK_SIZE);
    }

    /* process block last block */
    workBuf = txBuf;
    txBuf = IBufAry[IBufIdx++ % 2];
    prevDst = (Ptr)((Char *)prevDst + BLOCK_SIZE);
    PdKnl_block(NULL, prevDst, txBuf, workBuf, BLOCK_SIZE);

    /* drain the pipeline */
    txBuf = IBufAry[IBufIdx++ % 2];
    prevDst = (Ptr)((Char *)prevDst + BLOCK_SIZE);
    PdKnl_block(NULL, prevDst, txBuf, NULL, BLOCK_SIZE);

leave:
    Log_print0(Diags_EXIT, LOGSTR(3));
}


/*
 *  ======== PdKnl_block ========
 *  Transfer blocks in/out and process work buffer
 */
void PdKnl_block(void *inSrc, void *outDst, void *txBuf, void *workBuf,
    int bufSize)
{
    PdKnl_Object *      mod = &Mod_Obj;
    Bits32              time0;
    Bits32              time1;
    Bits32              waitCycles;
    UInt                waitTimeMs;
    UInt                data;
    UChar               lum;
    UInt *              elemPtr;
    Int                 i;
    Short               txNum = 0;


    Log_print5(Diags_ENTRY | Diags_INFO, LOGSTR(4),
        (IArg)inSrc, (IArg)txBuf, (IArg)outDst, (IArg)workBuf, (IArg)bufSize);

    /* transfer out previous block */
    if (outDst != NULL) {
        Log_print2(Diags_USER1, LOGSTR(5), (IArg)txBuf, (IArg)outDst);

        txNum++;
        mod->ecpyParams.srcAddr = txBuf;
        mod->ecpyParams.dstAddr = outDst;
        mod->ecpyParams.elementSize = bufSize;
        ECPY_directConfigure(mod->ecpy, &mod->ecpyParams, txNum);
    }

    /* transfer in next block */
    if (inSrc != NULL) {
        Log_print2(Diags_USER1, LOGSTR(6), (IArg)inSrc, (IArg)txBuf);

        txNum++;
        mod->ecpyParams.srcAddr = inSrc;
        mod->ecpyParams.dstAddr = txBuf;
        mod->ecpyParams.elementSize = bufSize;
        ECPY_directConfigure(mod->ecpy, &mod->ecpyParams, txNum);
    }

    /* start the data transfer */
    if (txNum > 0) {
        ECPY_directSetFinal(mod->ecpy, txNum);
        ECPY_directStartEdma(mod->ecpy);
    }

    /* process current block in parallel with data transfer */
    if (workBuf != NULL) {
        Log_print1(Diags_USER1, LOGSTR(7), (IArg)workBuf);

        /* convert to gray scale for demo purposes */
        for (i = 0; i < (bufSize / sizeof(UInt)); i++) {
            elemPtr = (UInt *)workBuf + i;
            data = *elemPtr;

            if (PdKnl_lumFloat) {
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


/* PdKnl_process() argument types */
UInt PdKnl_process_args[] = {
    ti_cl_arg_type_GlobalPtr,
    ti_cl_arg_type_GlobalPtr,
    ti_cl_arg_type_Int,
    ti_cl_arg_type_Int
};

/* kernel function table */
ComputeDevice_FxnDesc PdKnl_fxnTab[] = {
    {
        "PdKnl_process",        /* fxn name     */
        (Fxn)PdKnl_process,     /* fxn address  */
        4,                      /* num args     */
        PdKnl_process_args      /* arg types    */
    }
};
/*
 *  @(#) ti.sdo.opencl.examples.autoviz; 1, 0, 0,4; 2-22-2012 18:09:18; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

