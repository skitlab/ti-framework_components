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
/**
 *  @file       ti/sdo/fc/rman/examples/tiledmemory/ires_algorithm.c
 *
 *  @brief      Dummy implementation of the IRES interfaces by an algorithm
 *
 */

#include <xdc/std.h>
#include <stdio.h>

#include <ti/sdo/fc/ires/tiledmemory/ires_tiledmemory.h>
#include "ires_algorithm.h"
#include <ti/sysbios/knl/Task.h>

/*
 * TI's implementation of IALG
 */
Void IALG_ALGORITHM_activate(IALG_Handle handle);
Int IALG_ALGORITHM_alloc(const IALG_Params * params, IALG_Fxns ** fxns,
    IALG_MemRec memTab[]);
Int IALG_ALGORITHM_control(IALG_Handle handle, IALG_Cmd cmd,
    IALG_Status *status);
Void IALG_ALGORITHM_deactivate(IALG_Handle handle);
Int IALG_ALGORITHM_free(IALG_Handle handle, IALG_MemRec * memrec);
Int IALG_ALGORITHM_init(IALG_Handle handle1, const IALG_MemRec *memrecs,
    IALG_Handle handle2, const IALG_Params *params);
Void IALG_ALGORITHM_moved(IALG_Handle handle1, const IALG_MemRec *memrecs,
    IALG_Handle handle2, const IALG_Params *params);
Int IALG_ALGORITHM_numAlloc(Void);

static Void contextSave(IALG_Handle algHandle, Void *contextArgs);
static Void contextRestore(IALG_Handle algHandle, Void *contextArgs);

/* IALG_Fxns DUMALG_TI_IALG = */
#define IALGFXNS &DUMALG_TI_IALG,            \
    IALG_ALGORITHM_activate,    \
    IALG_ALGORITHM_alloc,       \
    IALG_ALGORITHM_control,     \
    IALG_ALGORITHM_deactivate,  \
    IALG_ALGORITHM_free,        \
    IALG_ALGORITHM_init,        \
    IALG_ALGORITHM_moved,       \
    IALG_ALGORITHM_numAlloc

/*
 * ===== IRES_ALGORITHM_numResourceDescriptors =====
 *
 * Returns number of different resource types the algorithm needs.
 * Part of IRES interface
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
Int32 IRES_ALGORITHM_numResourceDescriptors(IALG_Handle handle)
{
    return (NUM_RESOURCES);
}


/*
 * ===== IRES_ALGORITHM_activateResource =====
 *
 * Call to activate particular resource, identified by resourceHandle
 * Part of IRES interface
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
IRES_Status IRES_ALGORITHM_activateResource(IALG_Handle handle,
        IRES_Handle resourceHandle)
{
    DUMALG_TI_Handle algHandle = (DUMALG_TI_Handle)handle;
    Int i = 0;

    for (i = 0; i < NUM_RESOURCES; i++) {

        if ((IRES_Handle)algHandle->resourceHandles[i] == resourceHandle) {

            if (algHandle->resourceState[0] == 0) {
                algHandle->resourceState[0] = 1;
                return (IRES_OK);
            }
            else {
                return (IRES_EINIT);
            }
        }
    }
    return (IRES_OK);
}

/*
 * ===== IRES_ALGORITHM_activateAllResources =====
 *
 * Call to activate all resources
 * Part of IRES interface
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
IRES_Status IRES_ALGORITHM_activateAllResources(IALG_Handle handle)
{
    Int i = 0;
    DUMALG_TI_Handle algHandle = (DUMALG_TI_Handle)handle;

    for (i = 0; i < NUM_RESOURCES; i++) {

        if (algHandle->resourceState[i] == 0) {
            algHandle->resourceState[i] = 1;
        }
        else {
            return (IRES_EINIT);
        }
    }
    return (IRES_OK);
}

/*
 * ===== IRES_ALGORITHM_deactivateResource =====
 *
 * Call to deactivate a resource, identified by resourceHandle
 * Part of IRES interface
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
IRES_Status IRES_ALGORITHM_deactivateResource(IALG_Handle handle,
        IRES_Handle resourceHandle)
{
    DUMALG_TI_Handle algHandle = (DUMALG_TI_Handle)handle;
    Int i = 0;

    for (i = 0; i < NUM_RESOURCES; i++) {

        if ((IRES_Handle)algHandle->resourceHandles[i] == resourceHandle) {

            if (algHandle->resourceState[0] == 1) {
                algHandle->resourceState[0] = 0;
                return (IRES_OK);
            }
            else {
                return (IRES_ENORESOURCE);
            }
        }
    }
    return (IRES_OK);
}

/*
 * ===== IRES_ALGORITHM_deactivateAllResources =====
 *
 * Call to deactivate all resources
 * Part of IRES interface
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
IRES_Status IRES_ALGORITHM_deactivateAllResources(IALG_Handle handle)
{
    Int i = 0;

    DUMALG_TI_Handle algHandle = (DUMALG_TI_Handle)handle;

    for (i = 0; i < NUM_RESOURCES; i++) {

        if (algHandle->resourceState[i] == 1) {
            algHandle->resourceState[i] = 0;
        }
        else {
            return (IRES_ENORESOURCE);
        }
    }
    return (IRES_OK);
}

/*
 * ===== IRES_ALGORITHM_initResources =====
 *
 * Call to grant algorithm the resources it requested
 * Part of IRES interface
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
IRES_Status IRES_ALGORITHM_initResources(IALG_Handle handle,
    IRES_ResourceDescriptor * resourceDescriptor, IRES_YieldFxn  yieldFxn,
    IRES_YieldArgs yieldArgs)
{
    Int i = 0;

    DUMALG_TI_Handle algHandle = (DUMALG_TI_Handle)handle;

    for (i = 0; i < NUM_RESOURCES; i++) {

        IRES_TILEDMEMORY_Handle resHandle =
                (IRES_TILEDMEMORY_Handle)resourceDescriptor[i].handle;
        algHandle->resourceState[i] = 0;
        algHandle->resourceHandles[i] = resHandle;

        printf("Assigned resource[%d] = <memoryBaseAddress=%x, tilerBase=%x>"
               "isTiledMemory:%d\n",
                i, resHandle->memoryBaseAddress, resHandle->tilerBaseAddress,
                resHandle->isTiledMemory);
    }

    algHandle->yieldFxn =   yieldFxn;
    algHandle->yieldArgs =  yieldArgs;
    (algHandle->yieldContext).contextSave = contextSave;
    (algHandle->yieldContext).contextRestore = contextRestore;
    (algHandle->yieldContext).contextArgs = &(algHandle->contextArgs);
    (algHandle->yieldContext).algHandle = (IALG_Handle)algHandle;
    (algHandle->yieldContext).resourceHandle =
            (IRES_Handle)algHandle->resourceHandles[0];

    return (IRES_OK);
}

/*
 * ===== IRES_ALGORITHM_deinitResources =====
 *
 * Call to free resources that the algorithm had requested
 * Part of IRES interface
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
IRES_Status IRES_ALGORITHM_deinitResources(IALG_Handle handle,
    IRES_ResourceDescriptor * resourceDescriptor)
{
    Int i = 0;
    DUMALG_TI_Handle algHandle = (DUMALG_TI_Handle)handle;

    for (i = 0; i < NUM_RESOURCES; i++) {

        algHandle->resourceState[i] = 0;

        algHandle->resourceHandles[i] = (IRES_TILEDMEMORY_Handle)NULL;
    }

    return (IRES_OK);
}

/*
 * ===== IRES_ALGORITHM_reinitResources =====
 *
 * Call to change resource holdings of a particular algorithm
 * Part of IRES interface
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
IRES_Status IRES_ALGORITHM_reinitResources(IALG_Handle handle,
    IRES_ResourceDescriptor * resourceDescriptor,
    IRES_YieldFxn  yieldFxn, IRES_YieldArgs yieldArgs)
{
    Int i = 0;
    DUMALG_TI_Handle algHandle = (DUMALG_TI_Handle)handle;

    for (i = 0; i < NUM_RESOURCES; i++) {
        algHandle->resourceState[i] = 0;
    }

    return (IRES_OK);
}

/*
 * ===== IRES_ALGORITHM_getResourceDescriptors =====
 *
 * Call to query the resource requirements of an algoithm.
 * Once granted the resources, this call will return also the actual resouce
 * handles of the algorithm
 * Part of IRES interface
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
IRES_Status IRES_ALGORITHM_getResourceDescriptors(IALG_Handle handle,
    IRES_ResourceDescriptor *resourceDescriptors)
{
    Int i=0;
    DUMALG_TI_Handle algHandle = (DUMALG_TI_Handle)handle;

    for (i = 0; i < NUM_RESOURCES; i++) {

        resourceDescriptors[i].resourceName = IRES_TILEDMEMORY_PROTOCOLNAME;
        resourceDescriptors[i].revision = &IRES_TILEDMEMORY_PROTOCOLREVISION;

        resourceDescriptors[i].protocolArgs =
                    (IRES_ProtocolArgs *)&(algHandle->protocolArgs[i]);
        resourceDescriptors[i].handle =
                (IRES_Handle)algHandle->resourceHandles[i];
    }

    return(IRES_OK);
}

/*
 * IRES interface of the algorithm
 */
IRES_Fxns DUMALG_TI_IRES = {
    (void *)&DUMALG_TI_IRES,
    IRES_ALGORITHM_getResourceDescriptors,
    IRES_ALGORITHM_numResourceDescriptors,
    IRES_ALGORITHM_initResources,
    IRES_ALGORITHM_reinitResources,
    IRES_ALGORITHM_deinitResources,
    IRES_ALGORITHM_activateResource,
    IRES_ALGORITHM_activateAllResources,
    IRES_ALGORITHM_deactivateResource,
    IRES_ALGORITHM_deactivateAllResources
};

/*
 * ===== IALG_ALGORITHM_alloc ======
 *
 * Returns algorithms memory requirements in the memTab structure
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
Int IALG_ALGORITHM_alloc(const IALG_Params * algParams, IALG_Fxns ** fxns,
    IALG_MemRec memTab[])
{
    const IDUMALG_Params * params = (Void *)algParams;

    memTab[0].size = sizeof(DUMALG_TI_Obj);
    memTab[0].alignment = 4;
    memTab[0].space = IALG_DARAM0;
    memTab[0].attrs = IALG_PERSIST;

    if (NULL == params) {
        params = &IDUMALG_PARAMS;
    }

    return (NUM_ALLOC);
}

/*
 * ===== IALG_ALGORITHM_deactivate ======
 *
 * Deactivates the algorithm
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
Void IALG_ALGORITHM_deactivate(IALG_Handle handle)
{
    GT_1trace(ti_sdo_fc_rman_examples_tiledmemory, GT_4CLASS,
            "IALG_ALGORITHM_deactivate> Called Deactivate for task %d\n",
            ((DUMALG_TI_Handle)handle)->taskId);
    return;
}

/*
 * ===== IALG_ALGORITHM_numAlloc ======
 *
 * Returns the number of memTab structures required to specify algorithms
 * memory requirements
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
Int IALG_ALGORITHM_numAlloc(Void)
{
        return (NUM_ALLOC);
}

/*
 * ===== IALG_ALGORITHM_control ======
 *
 * Control commands for the algorithm to perform certain tasks
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
Int IALG_ALGORITHM_control(IALG_Handle handle, IALG_Cmd cmd,
    IALG_Status *status)
{
    return (0);
}

/*
 * ===== IALG_ALGORITHM_activate ======
 *
 * Activate the algorithm
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
Void IALG_ALGORITHM_activate(IALG_Handle handle)
{
    GT_1trace(ti_sdo_fc_rman_examples_tiledmemory, GT_4CLASS,
            "IALG_ALGORITHM_activate> Called Activate for task %d\n",
            ((DUMALG_TI_Handle)handle)->taskId);
    return;
}

/*
 * ===== IALG_ALGORITHM_free ======
 *
 * Free the memory allocated to the algorithsm
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
Int IALG_ALGORITHM_free(IALG_Handle handle, IALG_MemRec * memrec)
{
    DUMALG_TI_Handle alg = (Void *)handle;
    memrec[0].base = alg;
    return (NUM_ALLOC);
}

/*
 * ===== IALG_ALGORITHM_init ======
 *
 * Initialize the algorithm
 * We know there is only one resource request
 * Use the passed param to determine which TILEDMEMORY resource the algorithm requires
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
Int IALG_ALGORITHM_init(IALG_Handle handle, const IALG_MemRec *memrecs,
    IALG_Handle parent, const IALG_Params *params)
{
    Int i;
    IDUMALG_Params * myParams  = (IDUMALG_Params *)params;
    DUMALG_TI_Handle dumHandle = (DUMALG_TI_Handle)handle;

    for (i = 0; i < NUM_RESOURCES; i++) {

        dumHandle->protocolArgs[i].base.size =
                sizeof(IRES_TILEDMEMORY_ProtocolArgs);
        dumHandle->protocolArgs[i].base.mode = IRES_SCRATCH;
        dumHandle->protocolArgs[i].accessDimension = myParams->accessDimension;
        dumHandle->protocolArgs[i].accessUnit = myParams->accessUnit;
        dumHandle->protocolArgs[i].sizeDim0 =   myParams->sizeDim0;
        dumHandle->protocolArgs[i].sizeDim1 =   myParams->sizeDim1;
        dumHandle->protocolArgs[i].alignment =  myParams->alignment;

        printf("IALG::algInit setting this->protocolArgs[%d] with:\n  "
               ">> 1D/2D:[%d] 8/16/32b:[%d] dim0:%d, dim1:%d align=%x\n", i,
               dumHandle->protocolArgs[i].accessDimension,
               dumHandle->protocolArgs[i].accessUnit,
               dumHandle->protocolArgs[i].sizeDim0,
               dumHandle->protocolArgs[i].sizeDim1,
               dumHandle->protocolArgs[i].alignment);
    }
    dumHandle->yieldFlag = myParams->yieldFlag;
    dumHandle->taskId = myParams->taskId;

    return 0;
}


/*
 * ===== IALG_ALGORITHM_moved ======
 *
 * Indicates that the algoirthm has moved in memory, performs initializations
 * as required
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
Void IALG_ALGORITHM_moved(IALG_Handle handle1, const IALG_MemRec *memrecs,
    IALG_Handle handle2, const IALG_Params *params)
{
    return;
}

/* IBUFALG functions */

IDUMALG_Params IDUMALG_PARAMS = {
    sizeof(IDUMALG_Params),
/* Store what kind of TILEDMEMORY request is to be made */
    IRES_TILEDMEMORY_2D, IRES_TILEDMEMORY_16BIT, 0,0,
    0,
    0
};

/*
 * ===== useTILEDMEMORY ======
 *
 *
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
Int DUMALG_TI_useTILEDMEMORY(IDUMALG_Handle handle,unsigned int Id, unsigned int grp,
        unsigned int sleepTime)
{
    return 0;
}

/* ARGSUSED - this line tells the compiler not to warn about unused args. */
static Void contextSave(IALG_Handle algHandle, Void *contextArgs)
{
    GT_1trace(ti_sdo_fc_rman_examples_tiledmemory, GT_4CLASS,
            "contextSave> Saving TILEDMEMORY context for task %d\n",
            ((DUMALG_TI_Handle)algHandle)->taskId);
}

/* ARGSUSED - this line tells the compiler not to warn about unused args. */
static Void contextRestore(IALG_Handle algHandle, Void *contextArgs)
{
    GT_1trace(ti_sdo_fc_rman_examples_tiledmemory, GT_4CLASS,
            "contextRestore> Restoring TILEDMEMORY context for task %d\n",
            ((DUMALG_TI_Handle)algHandle)->taskId);
}

/*
 * TI's implementation of IDUMALG
 */
IDUMALG_Fxns DUMALG_TI_IDUMALG = {
    {
    IALGFXNS
    },
    DUMALG_TI_useTILEDMEMORY
};

/*
 * DUMALG_TI_IALG
 * This structure defines TI's implementation of IALG interface
 */
#ifdef xdc_target__isaCompatible_64P
 asm("_DUMALG_TI_IALG .set _DUMALG_TI_IDUMALG");
#else
IALG_Fxns DUMALG_TI_IALG =  {
    IALGFXNS,
};
#endif
/*
 *  @(#) ti.sdo.fc.rman.examples; 1, 0, 0,4; 2-22-2012 18:07:14; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

