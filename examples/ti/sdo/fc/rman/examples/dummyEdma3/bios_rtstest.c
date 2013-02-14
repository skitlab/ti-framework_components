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
 *  ======== bios_rtstest.c ========
 *
 *  This file contains implementation of test versions of non-BIOS MEM
 *  MEM_valloc() and MEM_free(). The test versions, MEM_tvalloc() and
 *  MEM_tfree(), take an extra parameter to be used for verification.
 *
 */

#ifdef _RTS_MODE

#include <std.h>
#include <stdlib.h>
#include <stdio.h>

#include <bios_rtstest.h>

#define PTRSIZE sizeof(Void *)

/*
 *  ======== MEM_tfree ========
 *  Test version of MEM_free
 */
Bool MEM_tfree(Int segid, Void * alignBuf, size_t size, Void **pAddr)
{
    LgUns *addrPtr;
    Void *buf;
    Uns remainBytes = 0;

    if ((PTRSIZE - 1) & size) {
        remainBytes = PTRSIZE - ((PTRSIZE - 1) & size);
    }

    addrPtr = (LgUns *)((LgUns)alignBuf + size + remainBytes);
    buf = (Void *)*addrPtr;

    /* This must be the same as the *pAddr set in MEM_tvalloc(). */
    *pAddr = buf;

    free(buf);

    return (TRUE);
}

/*
 *  ======== MEM_tvalloc ========
 *  Test version of MEM_valloc
 */
Void * MEM_tvalloc(Int segid, size_t size, size_t align, Char val,
        Void **pAddr)
{
    Uns     alignSize;
    Uns     alignBytes;
    Uns     remainBytes;
    Void   *buf;
    Void   *alignBuf;
    Uns     tmpAlign;
    LgUns  *addrPtr;


    /*
     *  Must at least align on 32-bit boundary since we're storing the
     *  32-bit address of the malloc'd buffer.
     */
    alignBytes = (align < PTRSIZE) ? PTRSIZE : align;

    /* alignment must be a power of 2 */
    DBC_require((alignBytes & (alignBytes - 1)) == 0);

    /*
     *  We will allocate a buffer larger than "size", to allow for alignment
     *  and to hold the address of the buffer returned by malloc() at the
     *  end of the buffer.
     *  Make size a multiple of 32-bits so it will be easier to find the
     *  address of the buffer returned by malloc().
     */
    alignSize = size;
    if ((remainBytes = alignSize & (PTRSIZE - 1)) != 0) {
        /* size is not a multiple of 32-bits */
        alignSize += PTRSIZE - remainBytes;
        remainBytes = PTRSIZE - remainBytes;
    }

    /* Add 32-bits to store pointer of allocated buffer */
    alignSize += PTRSIZE;

    alignSize += alignBytes;
    buf = malloc(alignSize);
    *pAddr = buf;

    tmpAlign = (Uns)buf & (alignBytes - 1);
    if (tmpAlign) {
        alignBuf = (Void *)((Uns)buf + alignBytes - tmpAlign);
    }
    else {
        alignBuf = buf;
    }

    /* Store the malloc'd address for freeing later. */
    addrPtr = (LgUns *)((LgUns)alignBuf + size + remainBytes);
    *addrPtr = (LgUns)buf;

    /* Initialize the aligned buffer with 'val' */
    memset(alignBuf, val, size);

    DBC_ensure(!((LgUns)alignBuf & (alignBytes - 1)));

    return (alignBuf);
}


/*
 *  ======== SYS_abort ========
 */
void SYS_abort(char *s, ...)
{
    printf("*** %s ***\n", s );
    exit(1);
}

#endif

/*
 *  @(#) ti.sdo.fc.rman.examples.dummyEdma3; 1, 0, 0,4; 2-22-2012 18:07:43; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

