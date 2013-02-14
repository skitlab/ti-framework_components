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
 *  ======== MemMgr_skel.c ========
 */

#include <stdio.h>
#include <unistd.h>

#include <xdc/std.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Memory.h>
#include <ti/sdo/rcm/RcmServer.h>

#include <ti/sdo/tiler/MemMgr.h>
#include <ti/sdo/tiler/src/memmgr/tilermem_utils.h>


Int32 MemMgr_PageSize_skel(UInt32 size, UInt32 *data)
{
    return(0);
}


/*
 *  ======== MemMgr_Alloc_skel ========
 */
Int32 MemMgr_Alloc_skel(UInt32 size, UInt32 *data)
{
    MemAllocBlock *blockPtr;
    int numBlocks;
//  int i;
    void *ptr;
    UInt16 remoteProcId;

//  printf("--> MemMgr_Alloc_skel(size: %d, data: 0x%x)\n",
//      (int)size, (unsigned int)data);

    /* setup a call frame */
    remoteProcId = (UInt16)data[0];
    numBlocks = (int)data[1];
//  printf("numBlocks: %d\n", numBlocks);

    blockPtr = (MemAllocBlock *)&data[2];
//  printf("blockPtr: 0x%x\n", (unsigned int)blockPtr);

#if 0
    for (i = 0; i < numBlocks; i++) {
        if ((blockPtr + i)->pixelFormat == PIXEL_FMT_PAGE) {
            printf("blocks[%d].mode: %d\n", i, (blockPtr + i)->pixelFormat);
            printf("blocks[%d].len:  %d\n", i, (blockPtr + i)->dim.len);
        }
        else {
            printf("blocks[%d].mode:   %d\n", i, (blockPtr + i)->pixelFormat);
            printf("blocks[%d].width:  %d\n", i,
                (blockPtr + i)->dim.area.width);
            printf("blocks[%d].height: %d\n",
                i, (blockPtr + i)->dim.area.height);
        }
    }
#endif

    /* invoke the requested api */
    ptr = MemMgr_Alloc(blockPtr, numBlocks);

#if 0
    for (i = 0; i < numBlocks; i++) {
        printf("blocks[%d].stride:   %d\n", i, (blockPtr + i)->stride);
        printf("blocks[%d].ptr:      0x%x\n", i,
            (unsigned int)((blockPtr + i)->ptr));
        printf("blocks[%d].reserved: 0x%x\n", i,
            (unsigned int)((blockPtr + i)->reserved));
    }
#endif

//  printf("<-- MemMgr_Alloc_skel, 0x%x\n", (unsigned int)ptr);
    return((Int32)ptr);
}


/*
 *  ======== MemMgr_Free_skel ========
 */
Int32 MemMgr_Free_skel(UInt32 size, UInt32 *data)
{
    void *ptr;
    Int32 rval;
    UInt16 remoteProcId;

//  printf("--> MemMgr_Free_skel(size: %d, data: 0x%x)\n",
//      (int)size, (unsigned int)data);

    /* setup a call frame */
    remoteProcId = (UInt16)data[0];
    ptr = (void *)(data[1]);
//  printf("ptr: 0x%x\n", (unsigned int)ptr);

    /* invoke the requested api */
    rval = (Int32)MemMgr_Free(ptr);

//  printf("<-- MemMgr_Free_skel, %d\n", (int)rval);
    return(rval);
}

Int32 MemMgr_Map_skel(UInt32 size, UInt32 *data)
{
    return(0);
}

Int32 MemMgr_UnMap_skel(UInt32 size, UInt32 *data)
{
    return(0);
}

Int32 MemMgr_Is1DBlock_skel(UInt32 size, UInt32 *data)
{
    return(0);
}

Int32 MemMgr_Is2DBlock_skel(UInt32 size, UInt32 *data)
{
    return(0);
}

Int32 MemMgr_IsMapped_skel(UInt32 size, UInt32 *data)
{
    return(0);
}

Int32 MemMgr_GetStride_skel(UInt32 size, UInt32 *data)
{
    return(0);
}

Int32 TilerMem_GetStride_skel(UInt32 size, UInt32 *data)
{
    return(0);
}

Int32 TilerMem_VirtToPhys_skel(UInt32 size, UInt32 *data)
{
    return(0);
}

typedef struct {
    RcmServer_Handle hRcmServer;
} MemMgr_Daemon_Object;


/*
 *  ======== MemMgr_createDaemon ========
 */
MemMgr_Daemon_Handle MemMgr_createDaemon(String name)
{
    Error_Block ebObj;
    Error_Block *eb = &ebObj;
    RcmServer_Params rcmServer_Params;
    MemMgr_Daemon_Object *obj = NULL;
    UInt32 unused;
    Int status = 0;

    Error_init(eb);

    /* allocate the daemon object */
    obj = (MemMgr_Daemon_Object *)Memory_alloc(NULL,
        sizeof(MemMgr_Daemon_Object), sizeof(Int), eb);

    if (Error_check(eb)) {
        goto leave;
    }
    obj->hRcmServer = NULL;

    /* create the RcmServer instance */
    RcmServer_Params_init(&rcmServer_Params);
    status = RcmServer_create(name, &rcmServer_Params, &obj->hRcmServer);

    if (status < 0) {
        goto leave;
    }

    /* install the function pointers */
    status = RcmServer_addSymbol(obj->hRcmServer,
        "MemMgr_PageSize_skel", MemMgr_PageSize_skel, &unused);
    if (status < 0) goto leave;

    status = RcmServer_addSymbol(obj->hRcmServer,
        "MemMgr_Alloc_skel", MemMgr_Alloc_skel, &unused);
    if (status < 0) goto leave;

    status = RcmServer_addSymbol(obj->hRcmServer,
        "MemMgr_Free_skel", MemMgr_Free_skel, &unused);
    if (status < 0) goto leave;

    status = RcmServer_addSymbol(obj->hRcmServer,
        "MemMgr_Map_skel", MemMgr_Map_skel, &unused);
    if (status < 0) goto leave;

    status = RcmServer_addSymbol(obj->hRcmServer,
        "MemMgr_UnMap_skel", MemMgr_UnMap_skel, &unused);
    if (status < 0) goto leave;

    status = RcmServer_addSymbol(obj->hRcmServer,
        "MemMgr_Is1DBlock_skel", MemMgr_Is1DBlock_skel, &unused);
    if (status < 0) goto leave;

    status = RcmServer_addSymbol(obj->hRcmServer,
        "MemMgr_Is2DBlock_skel", MemMgr_Is2DBlock_skel, &unused);
    if (status < 0) goto leave;

    status = RcmServer_addSymbol(obj->hRcmServer,
        "MemMgr_IsMapped_skel", MemMgr_IsMapped_skel, &unused);
    if (status < 0) goto leave;

    status = RcmServer_addSymbol(obj->hRcmServer,
        "MemMgr_GetStride_skel", MemMgr_GetStride_skel, &unused);
    if (status < 0) goto leave;

    status = RcmServer_addSymbol(obj->hRcmServer,
        "TilerMem_GetStride_skel", TilerMem_GetStride_skel, &unused);
    if (status < 0) goto leave;

    status = RcmServer_addSymbol(obj->hRcmServer,
        "TilerMem_VirtToPhys_skel", TilerMem_VirtToPhys_skel, &unused);
    if (status < 0) goto leave;

    /* start the server */
    RcmServer_start(obj->hRcmServer);

    /* pause to let server thread get going */
    usleep(20000);  /* 0.02 sec */

leave:
    if (Error_check(eb)) {
        Error_raise(eb, Error_E_generic, "MemMgr_createDeamon failed", 0);

        if (obj != NULL) {
            Memory_free(NULL, (Ptr)obj, sizeof(MemMgr_Daemon_Object));
            obj = NULL;
        }
    }

    return((MemMgr_Daemon_Handle)obj);
}


/*
 *  ======== MemMgr_deleteDaemon ========
 */
void MemMgr_deleteDaemon(MemMgr_Daemon_Handle *handle)
{
    MemMgr_Daemon_Object *obj = *(MemMgr_Daemon_Object **)handle;


    /* delete the rcm client instance */
    RcmServer_delete(&(obj->hRcmServer));

    Memory_free(NULL, (Ptr)obj, sizeof(MemMgr_Daemon_Object));
    *handle = NULL;
}
/*
 *  @(#) ti.sdo.tiler; 1, 0, 0,4; 2-22-2012 18:10:48; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

