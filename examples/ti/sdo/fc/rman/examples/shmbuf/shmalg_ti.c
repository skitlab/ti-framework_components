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
 *  ======== shmalg_ti.c ========
 *  Implementation of the SHMALG_TI.h interface; TI's implementation
 *  of the ISHMALG interface.
 */

#include <xdc/std.h>
#include <xdc/runtime/System.h>

#include <ti/xdais/ialg.h>
#include <ti/xdais/ires.h>

/*
 * As this file uses the SHMBUF_PROTOCOL definitions, define this before
 * including "shmbuf.h"
 */
#define ti_sdo_fc_rman_examples_shmbuf_SHMBUF_ENABLEPROTOCOLREV
#include <ti/sdo/fc/ires/shmbuf/shmbuf.h>

#include "shmalg_ti_priv.h"
#include "shmalg_ti.h"

#ifdef __TI_COMPILER_VERSION__
#pragma CODE_SECTION(SHMALG_TI_alloc, ".text:algAlloc")
#pragma CODE_SECTION(SHMALG_TI_free, ".text:algFree")
#pragma CODE_SECTION(SHMALG_TI_initObj, ".text:algInit")
#pragma CODE_SECTION(SHMALG_TI_init, ".text:init")
#pragma CODE_SECTION(SHMALG_TI_exit, ".text:exit")
#endif

/* IRES Function Declarations */
static IRES_Status SHMALG_TI_activateRes(IALG_Handle handle, IRES_Handle res);
static IRES_Status SHMALG_TI_activateAllRes(IALG_Handle handle);
static IRES_Status SHMALG_TI_deactivateRes(IALG_Handle handle,IRES_Handle res);
static IRES_Status SHMALG_TI_deactivateAllRes(IALG_Handle handle);
static Int32 SHMALG_TI_numResources(IALG_Handle handle);
static IRES_Status SHMALG_TI_getResources(IALG_Handle handle,
        IRES_ResourceDescriptor *desc);
static IRES_Status SHMALG_TI_initResources(IALG_Handle h,
        IRES_ResourceDescriptor * desc, IRES_YieldFxn  yieldFxn,
        IRES_YieldArgs yieldArgs);
static IRES_Status SHMALG_TI_deInitResources(IALG_Handle h,
        IRES_ResourceDescriptor *desc);
static IRES_Status SHMALG_TI_reInitResources(IALG_Handle handle,
        IRES_ResourceDescriptor *desc,
        IRES_YieldFxn  yieldFxn, IRES_YieldArgs yieldArgs);

/*
 *  ======== SHMALG_TI_IRES ========
 */
IRES_Fxns SHMALG_TI_IRES = {
    &SHMALG_TI_IRES,
    SHMALG_TI_getResources,
    SHMALG_TI_numResources,
    SHMALG_TI_initResources,
    SHMALG_TI_reInitResources,
    SHMALG_TI_deInitResources,
    SHMALG_TI_activateRes,
    SHMALG_TI_activateAllRes,
    SHMALG_TI_deactivateRes,
    SHMALG_TI_deactivateAllRes
};

/*
 *  ======== SHMALG_PARAMS ========
 *  This structure defines the default creation parameters.
 */
ISHMALG_Params ISHMALG_PARAMS = {
    sizeof(ISHMALG_Params),
    0,                      /* fill value for buffer */
};


/*
 *  ======== SHMALG_TI_activate ========
 *  Fills the scratch buffers.
 */
/* ARGSUSED */
Void SHMALG_TI_activate(IALG_Handle handle)
{
//    SHMALG_TI_Obj     *alg = (Void *)handle;
}

/*
 *  ======== SHMALG_TI_alloc ========
 *  Return a table of memory descriptors that describe the memory needed
 *  to construct a SHMALG_TI_Obj structure.
 */
/* ARGSUSED */
Int SHMALG_TI_alloc(const IALG_Params *algParams, IALG_Fxns **fxns,
                  IALG_MemRec memTab[])
{
    const   ISHMALG_Params *params = (Void *)algParams;

    if (params == NULL) {
        params = &ISHMALG_PARAMS; /* set default parameters */
    }

    /* Request memory for SHMALG object */
    memTab[0].size = sizeof(SHMALG_TI_Obj);
    memTab[0].alignment = 0;
    memTab[0].space = IALG_DARAM0;
    memTab[0].attrs = IALG_PERSIST;

    return (NUMALLOC);
}

/*
 *  ======== SHMALG_TI_control ========
 *  Execute a control operation.
 */
/* ARGSUSED */
Int SHMALG_TI_control(IALG_Handle handle, IALG_Cmd cmd,
        IALG_Status * status)
{
    return (1);
}

/*
 *  ======== SHMALG_TI_deactivate ========
 *  Checks that the scratch buffers still hold the correct values.
 */
/* ARGSUSED */
Void SHMALG_TI_deactivate(IALG_Handle handle)
{
//    SHMALG_TI_Obj *alg = (Void *)handle;
}

/*
 *  ======== SHMALG_TI_exit ========
 *  Exit the module as a whole.
 */
Void SHMALG_TI_exit(Void)
{
}

/*
 *  ======== SHMALG_TI_free ========
 *  Return a table of memory pointers that should be freed.  Note that
 *  this should include *all* memory requested in the alloc operation above.
 */
Int SHMALG_TI_free(IALG_Handle handle, IALG_MemRec memTab[])
{
    SHMALG_TI_Obj   *alg = (Void *)handle;
    Int             n;

   /* Get the memory attributes for the SHMALG object */
    n = SHMALG_TI_alloc(NULL, NULL, memTab);

    /* Set the memory bases */
    memTab[0].base = alg;

    return (n);
}

/*
 *  ======== SHMALG_TI_init ========
 *  Initialize the module as a whole.
 */
Void SHMALG_TI_init(Void)
{
}

/*
 *  ======== SHMALG_TI_initObj ========
 *  Initialize the memory allocated for our instance.
 */
/* ARGSUSED */
Int SHMALG_TI_initObj(IALG_Handle handle, const IALG_MemRec memTab[],
        IALG_Handle p, const IALG_Params *algParams)
{
    SHMALG_TI_Obj  *alg = (Void *)handle;
    ISHMALG_Params *params = (ISHMALG_Params *)algParams;
    Int             i;

    /* Initialize args for requesting resources */
    for (i = 0; i < NUMRES; i++) {
        alg->args[i].iresArgs.size = sizeof(SHMBUF_Args);
        alg->args[i].length = 0x20 * sizeof(Int);
        alg->args[i].align = 0;
    }
    alg->fillVal = params->fillVal;

    return (IALG_EOK);
}

/*
 *  ======== SHMALG_TI_numAlloc ========
 *  Return the maximum number memory blocks needed.
 */
Int SHMALG_TI_numAlloc(Void)
{
    return (NUMALLOC);
}

/*
 * ======== IRES_Fxns and other IRES stuff ========
 */

/*
 *  ======== SHMALG_TI_activateRes ========
 */
static IRES_Status SHMALG_TI_activateRes(IALG_Handle handle, IRES_Handle res)
{
    SHMALG_TI_Obj  *alg = (SHMALG_TI_Obj *)handle;
    Int            i;

    for (i = 0; i < NUMRES; i++) {
        if ((IRES_Handle)alg->res[i] == res) {
            /* Found it */
            break;
        }
    }

    if ((i < NUMRES) && (alg->resActive[i] == FALSE)) {
        /* Do whatever needs to be done before we start using this resource */
        alg->resActive[i] = TRUE;
        return (IRES_OK);
    }
    else {
        /* The resource was not found or was already active */
        return (IRES_ENORESOURCE);
    }
}


/*
 *  ======== SHMALG_TI_activateAllRes ========
 */
static IRES_Status SHMALG_TI_activateAllRes(IALG_Handle handle)
{
    SHMALG_TI_Obj  *alg = (SHMALG_TI_Obj *)handle;
    Int            i;
    IRES_Status    retVal;

    /* Activate all resources */
    for (i = 0; i < NUMRES; i++) {
        retVal = SHMALG_TI_activateRes(handle, (IRES_Handle)alg->res[i]);
        if (retVal != IRES_OK) {
            return (retVal);
        }
    }
    return (IRES_OK);
}

/*
 *  ======== SHMALG_TI_deactivateRes ========
 */
static IRES_Status SHMALG_TI_deactivateRes(IALG_Handle handle, IRES_Handle res)
{
    SHMALG_TI_Obj  *alg = (SHMALG_TI_Obj *)handle;
    Int            i;

    for (i = 0; i < NUMRES; i++) {
        if ((IRES_Handle)alg->res[i] == res) {
            /* Found it */
            break;
        }
    }

    if ((i < NUMRES) && (alg->resActive[i] == TRUE)) {
        /* Do what needs to be done when done using this resource */
        alg->resActive[i] = FALSE;
        return (IRES_OK);
    }
    else {
        /* The resource was not found or was already active */
        return (IRES_ENORESOURCE);
    }
}

/*
 *  ======== SHMALG_TI_deactivateAllRes ========
 */
static IRES_Status SHMALG_TI_deactivateAllRes(IALG_Handle handle)
{
    SHMALG_TI_Obj  *alg = (SHMALG_TI_Obj *)handle;
    Int            i;
    IRES_Status    retVal;
    IRES_Status    status = IRES_OK;

    for (i = 0; i < NUMRES; i++) {
        retVal = SHMALG_TI_deactivateRes(handle, (IRES_Handle)alg->res[i]);
        if (retVal != IRES_OK) {
            status = retVal;
        }
    }

    return (status);
}

/*
 *  ======== SHMALG_TI_numResources ========
 */
/* ARGSUSED */
static Int32 SHMALG_TI_numResources(IALG_Handle handle)
{
    return (NUMRES);
}

/*
 *  ======== SHMALG_TI_getResources ========
 */
static IRES_Status SHMALG_TI_getResources(IALG_Handle h,
        IRES_ResourceDescriptor *desc)
{
    SHMALG_TI_Obj  *alg = (SHMALG_TI_Obj *)h;
    Int            i;

    for (i = 0; i < NUMRES; i++) {
        desc[i].resourceName = SHMBUF_PROTOCOLNAME;
        desc[i].revision = &SHMBUF_PROTOCOLVERSION;
        desc[i].protocolArgs = (IRES_ProtocolArgs *)&(alg->args[i]);
        desc[i].protocolArgs->mode = IRES_SCRATCH;

        if (alg != NULL) {
            desc[i].handle = (IRES_Handle)(alg->res[i]);
        }
        else {
            desc[i].handle = NULL;
        }
    }
    //desc[1].resourceName = "JUNK";

    return (IRES_OK);
}

/*
 *  ======== SHMALG_TI_initResources ========
 */
static IRES_Status SHMALG_TI_initResources(IALG_Handle h,
        IRES_ResourceDescriptor *desc, IRES_YieldFxn  yieldFxn,
        IRES_YieldArgs yieldArgs)
{
    SHMALG_TI_Obj  *alg = (SHMALG_TI_Obj *)h;
    Int            i;

    for (i = 0; i < NUMRES; i++) {
        alg->res[i] = (SHMBUF_Handle)desc[i].handle;
    }

    alg->yieldFxn = yieldFxn;
    alg->yieldArgs = yieldArgs;

    return (IRES_OK);
}

/*
 *  ======== SHMALG_TI_deInitResources ========
 */
/* ARGSUSED */
static IRES_Status SHMALG_TI_deInitResources(IALG_Handle h,
        IRES_ResourceDescriptor *desc)
{
    SHMALG_TI_Obj  *alg = (SHMALG_TI_Obj *)h;
    Int            i;

    for (i = 0; i < NUMRES; i++) {
        alg->resActive[i] = FALSE;
                alg->res[i] = NULL;
/*              desc[i].handle = NULL;    Don't do this*/
    }

    return (IRES_OK);
}

/*
 *  ======== SHMALG_TI_reInitResources ========
 */
static IRES_Status SHMALG_TI_reInitResources(IALG_Handle handle,
        IRES_ResourceDescriptor *desc, IRES_YieldFxn  yieldFxn,
        IRES_YieldArgs yieldArgs)
{
    SHMALG_TI_Obj  *alg = (SHMALG_TI_Obj *)handle;
    Int            i;

    for (i = 0; i < NUMRES; i++) {
        alg->yieldFxn = yieldFxn;
        alg->yieldArgs = yieldArgs;
        alg->res[i] = (SHMBUF_Handle)desc[i].handle;
        alg->resActive[i] = FALSE;
    }
    return (IRES_OK);
}

/*
 *  Other ISHMALG functions.
 */

/*
 *  ======== SHMALG_TI_checkBufs ========
 *  Compare buffer values with fillVal. SHMBUF_Obj is the following structure:
 *
 *  typedef struct SHMBUF_Obj {
 *      IRES_Obj        ires;
 *
 *      // Fields specific to this resource
 *      Void   *base;    // Base address of assigned memory chunk
 *      Int     length;  // Length of assigned memory chunk
 *  } SHMBUF_Obj;
 */
/* ARGSUSED */
Int SHMALG_TI_checkBufs(ISHMALG_Handle handle)
{
    SHMALG_TI_Obj  *alg = (SHMALG_TI_Obj *)handle;
    Int            *buf = (Int *)(alg->res[0]->base);
    Int             i;

    for (i = 0; i < alg->args[0].length; i++) {
        if (buf[i] != alg->fillVal) {
            System_printf("buf[%d] = %d, should be %d\n", i, buf[i],
                    alg->fillVal);
            return (0);
        }
    }

    return (1);
}

/*
 *  ======== SHMALG_TI_useBufs ========
 *  Write to the buffer resource. SHMBUF_Obj is the following structure:
 *
 *  typedef struct SHMBUF_Obj {
 *      IRES_Obj        ires;
 *
 *      // Fields specific to this resource
 *      Void   *base;    // Base address of assigned memory chunk
 *      Int     length;  // Length of assigned memory chunk
 *  } SHMBUF_Obj;
 */
/* ARGSUSED */
Int SHMALG_TI_useBufs(ISHMALG_Handle handle)
{
    SHMALG_TI_Obj  *alg = (SHMALG_TI_Obj *)handle;
    Int            *buf = (Int *)(alg->res[0]->base);
    Int             i;

    for (i = 0; i < alg->args[0].length; i++) {
        buf[i] = alg->fillVal;
    }

    return (0);
}
/*
 *  @(#) ti.sdo.fc.rman.examples.shmbuf; 1, 0, 0,4; 2-22-2012 18:08:19; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

