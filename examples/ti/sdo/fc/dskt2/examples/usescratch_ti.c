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
 *  ======== usescratch_ti.c ========
 *  Implementation of the USESCRATCH_TI.h interface; TI's implementation
 *  of the IUSESCRATCH interface.
 */

#ifdef __TI_COMPILER_VERSION__
#pragma CODE_SECTION(USESCRATCH_TI_alloc, ".text:algAlloc")
#pragma CODE_SECTION(USESCRATCH_TI_free, ".text:algFree")
#pragma CODE_SECTION(USESCRATCH_TI_initObj, ".text:algInit")
#pragma CODE_SECTION(USESCRATCH_TI_init, ".text:init")
#pragma CODE_SECTION(USESCRATCH_TI_exit, ".text:exit")
#pragma CODE_SECTION(USESCRATCH_TI_useScratch, ".text:test")
#endif

#include <xdc/std.h>
#include <xdc/runtime/System.h>

#include "iusescratch.h"
#include "usescratch_ti_priv.h"
#include "usescratch_ti.h"


static Int verifyScratch(USESCRATCH_TI_Handle usescratch);


/*
 *  ======== USESCRATCH_TI_activate ========
 *  Fills the scratch buffers.
 */
Void USESCRATCH_TI_activate(IALG_Handle handle)
{
    USESCRATCH_TI_Obj *usescratch = (Void *)handle;
    Int               i, j;
    Uns               bufsize;
    Int               scratchVal;

    /* Fill each of the scratch buffers with a different value */
    for (i = 0; i < usescratch->numBufs; i++) {
        bufsize = usescratch->bufSizes[i];
        scratchVal = usescratch->value + i;

        for (j = 0; j < bufsize / sizeof(Int); j++) {
            usescratch->scratchBufs[i][j] = scratchVal;
        }
    }
}

/*
 *  ======== USESCRATCH_TI_alloc ========
 *  Return a table of memory descriptors that describe the memory needed
 *  to construct a USESCRATCH_TI_Obj structure.
 */
/* ARGSUSED */
Int USESCRATCH_TI_alloc(const IALG_Params *usescratchParams,
        IALG_Fxns **parentFxns, IALG_MemRec memTab[])
{
    const   IUSESCRATCH_Params *params = (Void *)usescratchParams;
    Int     i;
    IALG_Fxns *fxns = NULL;

    if (params == NULL) {
        params = &IUSESCRATCH_PARAMS; /* set default parameters */
    }

    fxns = params->fxns;

    /* Request memory for USESCRATCH object */
    memTab[0].size = sizeof(USESCRATCH_TI_Obj);
    memTab[0].alignment = 0;
    memTab[0].space = IALG_DARAM0;
    memTab[0].attrs = IALG_PERSIST;

    if ((params->memTab != NULL) && (params->numRecs > 0)) {
        /* Test is specifying memory requests */
        if (params->numRecs > MAXALLOC) {
            /* Error */
            return (0);
        }

        /* Override only the space for the object. */
        memTab[0].space = params->memTab[0].space;

        for (i = 1; i < params->numRecs; i++) {
            memTab[i] = params->memTab[i];
#ifndef xdc_target__isaCompatible_64P
            /*
             *  Linux86 build uses HeapStd, which will return an error
             *  for alignments greater than 4.
             */
            memTab[i].alignment = 0;
#endif
            /*
             *  Can't request scratch unless both activate() and deactivate()
             *  functions are non-NULL.
             */
            if ((fxns->algActivate == NULL) || (fxns->algDeactivate == NULL)) {
                memTab[i].attrs = IALG_PERSIST;
            }
        }
        return (params->numRecs);
    }
    else {
        /* Use defaults */
        /* Specify attributes of scratch buffers */
        for (i = 1; i <= NUMBUFS; i++) {
            memTab[i].size = params->scratchSize;
            //memTab[i].alignment = 128; // 0;
            memTab[i].alignment = 4; // 0;

            /*
             *  Can't request scratch unless both activate() and deactivate()
             *  functions are non-NULL.
             */
            if ((fxns->algActivate == NULL) || (fxns->algDeactivate == NULL)) {
                memTab[i].attrs = IALG_PERSIST;
            }
            else {
                memTab[i].attrs = IALG_SCRATCH;
            }
            if (i > (NUMBUFS / 2)) {
                /* Allocate second half the buffers in SARAM0 */
                memTab[i].space = IALG_SARAM0;
            }
            else {
                /* First half of buffers in DARAM0 */
                memTab[i].space = IALG_DARAM0;
            }
        }

        return (NUMALLOC);
    }
}

/*
 *  ======== USESCRATCH_TI_control ========
 *  Execute a control operation.
 */
/* ARGSUSED */
Int USESCRATCH_TI_control(IALG_Handle handle, IALG_Cmd cmd,
        IALG_Status * status)
{
    return (1);
}

/*
 *  ======== USESCRATCH_TI_deactivate ========
 *  Checks that the scratch buffers still hold the correct values.
 */
Void USESCRATCH_TI_deactivate(IALG_Handle handle)
{
    USESCRATCH_TI_Obj *usescratch = (Void *)handle;

    if (verifyScratch(usescratch) != USESCRATCH_SOK) {
        usescratch->status = USESCRATCH_EFAIL;
        //SYS_abort("Scratch test failed, aborting...\n");
    }
}

/*
 *  ======== USESCRATCH_TI_exit ========
 *  Exit the USESCRATCH_TI module as a whole.
 */
Void USESCRATCH_TI_exit(Void)
{
}

/*
 *  ======== USESCRATCH_TI_free ========
 *  Return a table of memory pointers that should be freed.  Note
 *  that this should include *all* memory requested in the
 *  USESCRATCH_TI_alloc operation above.
 */
Int USESCRATCH_TI_free(IALG_Handle handle, IALG_MemRec memTab[])
{
    USESCRATCH_TI_Obj *usescratch = (Void *)handle;
    Int             i;
    Int             n;

   /* Get the memory attributes for the USESCRATCH object */
    n = USESCRATCH_TI_alloc(NULL, NULL, memTab);

    /* Set the memory bases */
    memTab[0].base = usescratch;
    for (i = 1; i < n; i++) {
        memTab[i].base = usescratch->scratchBufs[i - 1];
    }

    return (n);
}

/*
 *  ======== USESCRATCH_TI_init ========
 *  Initialize the USESCRATCH_TI module as a whole.
 */
Void USESCRATCH_TI_init(Void)
{
}

/*
 *  ======== USESCRATCH_TI_initObj ========
 *  Initialize the memory allocated for our instance.
 */
/* ARGSUSED */
Int USESCRATCH_TI_initObj(IALG_Handle handle, const IALG_MemRec memTab[],
        IALG_Handle p, const IALG_Params *usescratchParams)
{
    USESCRATCH_TI_Obj         *usescratch = (Void *)handle;
    const IUSESCRATCH_Params  *params = (Void *)usescratchParams;
    Int                       i;
    Int                       numBufs;

    numBufs = (params->numRecs > 0) ? params->numRecs - 1 : NUMBUFS;

    for (i = 0; i < numBufs; i++) {
        usescratch->scratchBufs[i] = memTab[i + 1].base;
        usescratch->bufSizes[i] = memTab[i + 1].size;

        /* Save memTab */
        usescratch->memTab[i + 1] = memTab[i + 1];
    }

    usescratch->memTab[0] = memTab[0];

    usescratch->value = params->value;
    usescratch->bufSize = params->scratchSize;
    usescratch->scratchGroup = params->scratchGroup;
    usescratch->id = params->id;
    usescratch->numRecs = numBufs + 1;
    usescratch->numBufs = numBufs;

    return (IALG_EOK);
}

/*
 *  ======== USESCRATCH_TI_getBufs ========
 *  Fill in memTab[] with values that were allocated to the algorithm.
 */
Int USESCRATCH_TI_getBufs(const IALG_Handle alg, IALG_MemRec memTab[],
        Int numRecs)
{
    USESCRATCH_TI_Obj *usescratch = (Void *)alg;
    Int               i;

    if (numRecs < usescratch->numRecs) {
        return (-1);
    }

    for (i = 0; i < usescratch->numRecs; i++) {
        memTab[i] = usescratch->memTab[i];
    }

    return (usescratch->numRecs);
}

/*
 *  ======== USESCRATCH_TI_numAlloc ========
 *  Return the maximum number memory blocks needed.
 */
Int USESCRATCH_TI_numAlloc(Void)
{
    return (MAXALLOC);
}

/*
 *  ======== USESCRATCH_TI_useScratch ========
 *  Does the usescratch.
 */
Int USESCRATCH_TI_useScratch(IALG_Handle handle)
{
    USESCRATCH_TI_Obj *usescratch = (Void *)handle;
    Int               status = USESCRATCH_SOK;

    if ((status = usescratch->status) == USESCRATCH_SOK) {
        status = verifyScratch(usescratch);
    }

    return (status);
}

/*
 *  ======== verifyScratch ========
 */
static Int verifyScratch(USESCRATCH_TI_Handle usescratch)
{
    Int     expectedVal;
    Int     i, j;

    /* Check the scratch buffers */
    for (i = 0; i < usescratch->numBufs; i++) {
        expectedVal = usescratch->value + i;
        for (j = 0; j < usescratch->bufSizes[i] / sizeof(Int); j++) {
            if (usescratch->scratchBufs[i][j] != expectedVal) {
                System_printf("Scratch buffer[%d][%x] corrupted: 0x%x "
                        "Expected 0x%x\n", i, j, usescratch->scratchBufs[i][j],
                        expectedVal);
                return (USESCRATCH_EFAIL);
            }
        }
    }

    return (USESCRATCH_SOK);
}
/*
 *  @(#) ti.sdo.fc.dskt2.examples; 1, 0, 0,4; 2-22-2012 18:03:54; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

