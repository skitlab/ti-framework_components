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
 *  ======== memutils.c ========
 */

#include <xdc/std.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Memory.h>

#include <xdc/runtime/IHeap.h>

#ifndef xdc_target__os_Linux

/* Assume BIOS os */
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/heaps/HeapMem.h>

#else  // xdc_target__os_Linux

#if USE_XDC_HEAPSTD
#include <xdc/runtime/HeapStd.h>
#else
#include <xdcruntime/heaps/HeapStdAlign.h>
#endif

#endif // xdc_target__os_Linux


/* Arbitrarily chosen to be greater than the number of memory heaps. */
#define MAXMEMSEGMENTS 20

#define HEAP_LABEL(h, l) IHeap_Handle_label((IHeap_Handle)h, &l)

# ifdef xdc_target__os_Linux

#if USE_XDC_HEAPSTD
#define HEAP_OBJECT_COUNT() HeapStd_Object_count()
#define HEAP_OBJECT_GET(array, i) HeapStd_Object_get(array, i)
#define HEAP_NAME(h) HeapStd_Handle_name((HeapStd_Handle)h)

#else
#define HEAP_OBJECT_COUNT() HeapStdAlign_Object_count()
#define HEAP_OBJECT_GET(array, i) HeapStdAlign_Object_get(array, i)
#define HEAP_NAME(h) HeapStdAlign_Handle_name((HeapStdAlign_Handle)h)

#endif

#else

/* BIOS HeapMem */
#define HEAP_OBJECT_COUNT() HeapMem_Object_count()
#define HEAP_OBJECT_GET(array, i) HeapMem_Object_get(array, i)
#define HEAP_NAME(h) HeapMem_Handle_name((HeapMem_Handle)h)

# endif

IHeap_Handle        heaps[MAXMEMSEGMENTS];
Memory_Stats        memStat[MAXMEMSEGMENTS];
Int                 numHeaps = 0;

/*
 *  ======== MemUtils_initStats ========
 */
Void MemUtils_initStats()
{
    Types_Label     label;
    String          name;
    Int             i;

    numHeaps = HEAP_OBJECT_COUNT();
    numHeaps = (numHeaps > MAXMEMSEGMENTS) ? MAXMEMSEGMENTS : numHeaps;

    System_printf("Number of heaps: %d\n", numHeaps);

    for (i = 0; i < numHeaps; i++) {
        heaps[i] = (IHeap_Handle)HEAP_OBJECT_GET(NULL, i);
        //name = HEAP_NAME(heaps[i]);
        HEAP_LABEL(heaps[i], label); // Another way to get the name.
        name = label.iname;
        System_printf("Heap[%d] name: %s\n", i, name /*label.iname */);
        Memory_getStats(heaps[i], &(memStat[i]));
    }
}

/*
 *  ======== MemUtils_checkMem ========
 */
Bool MemUtils_checkMem()
{
    Int             i;
    UInt32          used;
    UInt32          initialUsed;
    String          name;
    Memory_Stats    stat;
    Types_Label     label;
    Bool            status = TRUE;

    for (i = 0; i < numHeaps; i++) {
        Memory_getStats(heaps[i], &stat);
        if (memStat[i].totalFreeSize != stat.totalFreeSize) {
            //name = HEAP_NAME(heaps[i]);
            HEAP_LABEL(heaps[i], label); // Another way to get the name.
            name = label.iname;
            initialUsed = memStat[i].totalSize - memStat[i].totalFreeSize;
            used = stat.totalSize - stat.totalFreeSize;
            System_printf("%s [heap %d]: orig used = 0x%x, curr used = 0x%x\n",
                    name, i, initialUsed, used);
            status = FALSE;
        }
    }

    return (status);
}
/*
 *  @(#) ti.sdo.fc.rman.examples.scratchEdma3; 1, 0, 0,4; 2-22-2012 18:08:03; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

