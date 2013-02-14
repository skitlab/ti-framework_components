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
 *  ======== MemMgr_stub.c ========
 */

#include <xdc/std.h>
#include <xdc/runtime/Error.h>

#include <ti/ipc/MultiProc.h>
#include <ti/sdo/rcm/RcmClient.h>

#include <ti/sdo/tiler/MemMgr.h>
#include <ti/sdo/tiler/Settings.h>
#include <ti/sdo/tiler/src/memmgr/tilermem_utils.h>



/* local functions */
static Void rcm_initialize(Void);
// static uint32_t buf_cache_del(void *bufPtr, int buf_type);


/* global variables */
static RcmClient_Handle ghRcmClient = NULL;
static Error_Block ebObj;
static Error_Block *eb = &ebObj;

static UInt32 gfi_MemMgr_PageSize;
static UInt32 gfi_MemMgr_Alloc;
static UInt32 gfi_MemMgr_Free;
static UInt32 gfi_MemMgr_Map;
static UInt32 gfi_MemMgr_UnMap;
static UInt32 gfi_MemMgr_Is1DBlock;
static UInt32 gfi_MemMgr_Is2DBlock;
static UInt32 gfi_MemMgr_IsMapped;
static UInt32 gfi_MemMgr_GetStride;
static UInt32 gfi_TilerMem_GetStride;
static UInt32 gfi_TilerMem_VirtToPhys;

typedef struct {
    Ptr ssPtr;  /* system space ptr (tiler alias view) */
    Ptr vsPtr;  /* virtual space ptr (host process) */
} BufInfo;

#define ARY_MAX 16
static BufInfo gBlockAry[ARY_MAX];


bytes_t MemMgr_PageSize()
{
    return(PAGE_SIZE);
}


/*
 *  ======== MemMgr_Alloc (stub) ========
 *
 *
 *         RcmClient_Message
 *       ----------------------------------------------
 *  0000 | IN    gfi_MemMgr_Alloc                     | fxnIdx
 *  0004 | OUT   MemMgr_Alloc() return value          | result
 *  0008 | IN                                         | dataSize
 *  000C | IN    prodId                               | data[0]
 *  0010 | IN    numBlocks                            | data[1]
 *  0014 | INOUT block[0]                             | data[2]
 *       |       block[1]                             |
 *       |       :                                    | :
 *       |       block[n-1]                           | data[x]
 *       ----------------------------------------------
 */
void *MemMgr_Alloc(MemAllocBlock blocks[], int numBlocks)
{
    MemAllocBlock *blockPtr;
    UInt32 size;
    Int i;
    RcmClient_Message *msg = NULL;
    void *ptr = NULL;
    Int status = 0;

    /* initialize rcm */ 
    if (ghRcmClient == NULL) {
        rcm_initialize();
    }

    /* allocate a remote command message */
    size = (numBlocks * sizeof(MemAllocBlock)) + (2 *sizeof(int));
    status = RcmClient_alloc(ghRcmClient, size, &msg);

    if (status < 0) {
        goto leave;
    }

    /* marshal the arguments into the message */
    msg->fxnIdx = gfi_MemMgr_Alloc;
    *(int *)&msg->data[0] = MultiProc_self();
    *(int *)&msg->data[1] = numBlocks;
    blockPtr = (MemAllocBlock *)(&msg->data[2]);

    for (i = 0; i < numBlocks; i++) {
        *blockPtr++ = blocks[i];
    }

    /* execute the remote command message */
    status = RcmClient_exec(ghRcmClient, msg, &msg);

    if (status < 0) {
        goto leave;
    }

    /* unmarshal the return value */
    blockPtr = (MemAllocBlock *)(&msg->data[2]);

    for (i = 0; i < numBlocks; i++) {
        blocks[i] = *blockPtr++;
    }

    /* store buffer[0] in the registry */
    for (i = 0; i < ARY_MAX; i++) {
        if (gBlockAry[i].ssPtr == 0) {
            gBlockAry[i].ssPtr = (Ptr)blocks[0].reserved;
            gBlockAry[i].vsPtr = (Ptr)(msg->result);
            break;
        }
    }

    if (i == ARY_MAX) {
        /* TODO: error condition */
    }

    /* TODO: move this to skel code */
    /* translate stride to system space */
    for (i = 0; i < numBlocks; i++) {
        blocks[i].stride = 0x4000;
    }

    /* TODO: move this to skel code */
    /* unmarshal the return value */
//  ptr = (void *)msg->result;
    ptr = (void *)(blocks[0].reserved);

leave:
    /* return the message to the heap */
    if (msg != NULL) {
        RcmClient_free(ghRcmClient, msg);
    }

    return(ptr);
}


/*
 *  ======== MemMgr_Free (stub) ========
 *
 *         RcmClient_Message
 *       ----------------------------------------------
 *  0000 | IN    gfi_MemMgr_Free                      | fxnIdx
 *  0004 | OUT   MemMgr_Free() return value           | result
 *  0008 | IN                                         | dataSize
 *  000C | IN    prodId                               | data[0]
 *  0010 | IN    void *                               | data[1]
 *       ----------------------------------------------
 */
int MemMgr_Free(void *bufPtr)
{
    Int i;
    UInt32 size;
    int rval;
    RcmClient_Message *msg = NULL;
    int status = 0;

    /* initialize rcm */ 
    if (ghRcmClient == NULL) {
        rcm_initialize();
    }

    /* find the buffer in the registry */
    for (i = 0; i < ARY_MAX; i++) {
        if (gBlockAry[i].ssPtr == (Ptr)bufPtr) {
            bufPtr = (void *)(gBlockAry[i].vsPtr);
            gBlockAry[i].ssPtr = 0;
            gBlockAry[i].vsPtr = 0;
            break;
        }
    }

    if (i == ARY_MAX) {
        /* TODO: error condition */
    }

    /* allocate a remote command message */
    size = sizeof(void *) + sizeof(int);
    status = RcmClient_alloc(ghRcmClient, size, &msg);

    if (status < 0) {
        goto leave;
    }

    /* marshal the arguments into the message */
    msg->fxnIdx = gfi_MemMgr_Free;
    *(int *)&msg->data[0] = MultiProc_self();
    *(void **)(&msg->data[1]) = bufPtr;

    /* execute the remote command message */
    status = RcmClient_exec(ghRcmClient, msg, &msg);

    if (status < 0) {
        goto leave;
    }

    /* unmarshal the return value */
    rval = (int)(msg->result);

leave:
    /* return the message to the heap */
    if (msg != NULL) {
        RcmClient_free(ghRcmClient, msg);
    }

    return(rval);
}

void *MemMgr_Map(MemAllocBlock blocks[], int num_blocks)
{
    return(NULL);
}

int MemMgr_UnMap(void *bufPtr)
{
    return(0);
}

bool MemMgr_Is1DBlock(void *ptr)
{
    return(FALSE);
}

bool MemMgr_Is2DBlock(void *ptr)
{
    return(FALSE);
}

bool MemMgr_IsMapped(void *ptr)
{
    return(FALSE);
}

bytes_t MemMgr_GetStride(void *ptr)
{
    return(0);
}

bytes_t TilerMem_GetStride(SSPtr ssptr)
{
    return(0);
}

SSPtr TilerMem_VirtToPhys(void *ptr)
{
    return(NULL);
}


/*
 *  ======== rcm_initialize ========
 */
Void rcm_initialize(Void)
{
    Int i;
    RcmClient_Params rcmClientParams;
    Int status = 0;


    /* guard against multiple inits */
    if (ghRcmClient != NULL) {
        return;
    }

    /* must initialize the error block before using it */
    Error_init(eb);

    /* initialize the buffer info registry */
    for (i = 0; i < ARY_MAX; i++) {
        gBlockAry[i].ssPtr = 0;
        gBlockAry[i].vsPtr = 0;
    }

    /* initialize the instance create parameters */
    RcmClient_Params_init(&rcmClientParams);
    rcmClientParams.heapId = ti_sdo_tiler_Settings_heapId;

    /* loop in case remote server has not yet been created */
    while (ghRcmClient == NULL) {
        status = RcmClient_create(ti_sdo_tiler_Settings_tilerDaemonName,
                &rcmClientParams, &ghRcmClient);

        if (status < 0) {
            if (status == RcmClient_E_SERVERNOTFOUND) {
                /* try again */
            }
            else {
                goto leave;
            }
        }
    }

    /* interrogate the function pointer indices */
    status = RcmClient_getSymbolIndex(
        ghRcmClient, "MemMgr_PageSize_skel", &gfi_MemMgr_PageSize);
    if (status < 0) goto leave;

    status = RcmClient_getSymbolIndex(
        ghRcmClient, "MemMgr_Alloc_skel", &gfi_MemMgr_Alloc);
    if (status < 0) goto leave;

    status = RcmClient_getSymbolIndex(
        ghRcmClient, "MemMgr_Free_skel", &gfi_MemMgr_Free);
    if (status < 0) goto leave;

    status = RcmClient_getSymbolIndex(
        ghRcmClient, "MemMgr_Map_skel", &gfi_MemMgr_Map);
    if (status < 0) goto leave;

    status = RcmClient_getSymbolIndex(
        ghRcmClient, "MemMgr_UnMap_skel", &gfi_MemMgr_UnMap);
    if (status < 0) goto leave;

    status = RcmClient_getSymbolIndex(
        ghRcmClient, "MemMgr_Is1DBlock_skel", &gfi_MemMgr_Is1DBlock);
    if (status < 0) goto leave;

    status = RcmClient_getSymbolIndex(
        ghRcmClient, "MemMgr_Is2DBlock_skel", &gfi_MemMgr_Is2DBlock);
    if (status < 0) goto leave;

    status = RcmClient_getSymbolIndex(
        ghRcmClient, "MemMgr_IsMapped_skel", &gfi_MemMgr_IsMapped);
    if (status < 0) goto leave;

    status = RcmClient_getSymbolIndex(
        ghRcmClient, "MemMgr_GetStride_skel", &gfi_MemMgr_GetStride);
    if (status < 0) goto leave;

    status = RcmClient_getSymbolIndex(
        ghRcmClient, "TilerMem_GetStride_skel", &gfi_TilerMem_GetStride);
    if (status < 0) goto leave;

    status = RcmClient_getSymbolIndex(
        ghRcmClient, "TilerMem_VirtToPhys_skel", &gfi_TilerMem_VirtToPhys);
    if (status < 0) goto leave;

leave:
    if (status < 0) {
        Error_raise(eb, Error_E_generic, "MemMgr startup failure", 0);
    }
}
/*
 *  @(#) ti.sdo.tiler; 1, 0, 0,4; 2-22-2012 18:10:48; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

