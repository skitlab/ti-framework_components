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
 *  ======== memmgr.c ========
 *
 */

#include <stdio.h>

#include "../memmgr/list_utils.h"
#include "../memmgr/memmgr.h"
#include "../memmgr/tiler.h"
#include "../memmgr/tilermem.h"
#include "../memmgr/tilermem_utils.h"
#include "../memmgr/tilermgr.h"
#include "../memmgr/utils.h"


void *MemMgr_Alloc(MemAllocBlock blocks[], int num_blocks)
{
    return NULL;
}

int MemMgr_Free(void *bufPtr)
{
    return -1;
}

bytes_t MemMgr_GetStride(void *ptr)
{
    return 0;
}
bool MemMgr_Is1DBlock(void *ptr)
{
    return 0;
}

bool MemMgr_Is2DBlock(void *ptr)
{
    return 0;
}

bool MemMgr_IsMapped(void *ptr)
{
    return 0;
}

void *MemMgr_Map(MemAllocBlock blocks[], int num_blocks)
{
    return NULL;
}

bytes_t MemMgr_PageSize()
{
    return PAGE_SIZE;
}

int MemMgr_UnMap(void *bufPtr)
{
    return -1;
}
/*
 *  @(#) ti.sdo.tiler; 1, 0, 0,4; 2-22-2012 18:10:48; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

