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
 *  @file       ti/sdo/fc/rman/examples/hdvicp/ires_algorithm.c 
 *
 *  @brief      Dummy implementation of the IRES interfaces by an algorithm  
 *
 */

#include <xdc/std.h>
#include <stdio.h>

#ifdef _DUCATI
#include <ti/sdo/fc/ires/hdvicp/ires_hdvicp2.h>
#else
#include <ti/sdo/fc/ires/hdvicp/ires_hdvicp.h>
#endif
#include "ires_algorithm.h"
#include <ti/sysbios/knl/Task.h>

#define MODE IRES_LATEACQUIRE

extern GT_Mask CURTRACE;

/*
 * TI's implementation of IALG 
 */
Void IALG_ALGORITHM_Activate(IALG_Handle handle);
Int IALG_ALGORITHM_Alloc(const IALG_Params * params, IALG_Fxns ** fxns, 
    IALG_MemRec memTab[]);
Int IALG_ALGORITHM_Control(IALG_Handle handle, IALG_Cmd cmd,
    IALG_Status *status); 
Void IALG_ALGORITHM_Deactivate(IALG_Handle handle);
Int IALG_ALGORITHM_Free(IALG_Handle handle, IALG_MemRec * memrec);
Int IALG_ALGORITHM_Init(IALG_Handle handle1, const IALG_MemRec *memrecs,
    IALG_Handle handle2, const IALG_Params *params);
Void IALG_ALGORITHM_Moved(IALG_Handle handle1, const IALG_MemRec *memrecs,
    IALG_Handle handle2, const IALG_Params *params);
Int IALG_ALGORITHM_NumAlloc(Void);

static Void contextSave(IALG_Handle algHandle, Void *contextArgs);
static Void contextRestore(IALG_Handle algHandle, Void *contextArgs);



/* IALG_Fxns DUMALG_TI_IALG = */
#define IALGFXNS &DUMALG_TI_IALG,            \
    IALG_ALGORITHM_Activate,    \
    IALG_ALGORITHM_Alloc,       \
    IALG_ALGORITHM_Control,     \
    IALG_ALGORITHM_Deactivate,  \
    IALG_ALGORITHM_Free,        \
    IALG_ALGORITHM_Init,        \
    IALG_ALGORITHM_Moved,       \
    IALG_ALGORITHM_NumAlloc

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

    if (MODE == IRES_LATEACQUIRE)
    for (i = 0; i < NUM_RESOURCES; i++) {
        if ((IRES_Handle)algHandle->resourceHandles[i] == resourceHandle) {
            printf("Alg 0x%x: Activate on resource 0x%x\n", algHandle,
                    algHandle->resourceHandles[i]->id); 
            if (algHandle->resourceState[0] == 0) {
                algHandle->resourceState[0] = 1;
                return (IRES_OK);
            }
            else {
                printf("Hmm, resource 0x%x already active\n", 
                        algHandle->resourceHandles[i]->id); 
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
    
    printf("Alg 0x%x: Activate all resources \n", algHandle);
    if (MODE != IRES_LATEACQUIRE) {
    for (i = 0; i < NUM_RESOURCES; i++) {
    
        if (algHandle->resourceState[i] == 0) {
            algHandle->resourceState[i] = 1;
        }
        else {
            return (IRES_EINIT);
        }
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

    if (MODE == IRES_LATEACQUIRE)
    for (i = 0; i < NUM_RESOURCES; i++) {
        if ((IRES_Handle)algHandle->resourceHandles[i] == resourceHandle) {
            printf("Alg 0x%x: Deactivate on resource 0x%x\n", algHandle,
                        algHandle->resourceHandles[i]->id); 
            if (algHandle->resourceState[0] == 1) {
                algHandle->resourceState[0] = 0;
                return (IRES_OK);
            }
            else {
                printf("Hmmm... already deactivated 0x%x\n", 
                        algHandle->resourceHandles[i]->id); 
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
    printf("Alg 0x%x: Deactivate all resources \n", algHandle);
    if (MODE != IRES_LATEACQUIRE) {
    for (i = 0; i < NUM_RESOURCES; i++) {
        if (algHandle->resourceState[i] == 1) {
            algHandle->resourceState[i] = 0;
        }
        else {
            return (IRES_ENORESOURCE);
        }
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
        algHandle->resourceState[i] = 0;
        algHandle->resourceHandles[i] =
#ifdef _DUCATI
            (IRES_HDVICP2_Handle)resourceDescriptor[i].handle;
                algHandle->hdvicp[i] = 
                ((IRES_HDVICP2_Handle)resourceDescriptor[i].handle)->id;
#else
            (IRES_HDVICP_Handle)resourceDescriptor[i].handle;
                algHandle->hdvicp[i] = (IRES_HDVICP_RequestType) 
                ((IRES_HDVICP_Handle)resourceDescriptor[i].handle)->id;
#endif
        //printf("Assigned resource[%d] = %d\n",i, algHandle->hdvicp[i]); 
    }

    algHandle->yieldFxn =   yieldFxn;
    algHandle->yieldArgs =  yieldArgs;
    (algHandle->yieldContext).contextSave = contextSave;
    (algHandle->yieldContext).contextRestore = contextRestore;
    (algHandle->yieldContext).contextArgs = &(algHandle->contextArgs);
        (algHandle->yieldContext).algHandle = (IALG_Handle)algHandle;
        (algHandle->yieldContext).resourceHandle = (IRES_Handle)algHandle->resourceHandles[0];
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

#ifdef _DUCATI
        algHandle->resourceHandles[i] = (IRES_HDVICP2_Handle)NULL;
#else
        algHandle->resourceHandles[i] = (IRES_HDVICP_Handle)NULL;
#endif

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
#ifdef _DUCATI
        resourceDescriptors[i].resourceName = IRES_HDVICP2_PROTOCOLNAME;
        resourceDescriptors[i].revision = &IRES_HDVICP2_PROTOCOLREVISION;
        algHandle->protocolArgs[i].base.size = 
                sizeof(IRES_HDVICP2_ProtocolArgs);
#else
        resourceDescriptors[i].resourceName = IRES_HDVICP_PROTOCOLNAME;
        resourceDescriptors[i].revision = &IRES_HDVICP_PROTOCOLREVISION;
        algHandle->protocolArgs[i].base.size = sizeof(IRES_HDVICP_ProtocolArgs);
#endif
        algHandle->protocolArgs[i].base.mode = MODE; 
        algHandle->protocolArgs[i].id = algHandle->hdvicp[i];
        /*
        printf("Requested resource[%d] = %d\n",i, algHandle->hdvicp[i]); 
        */
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
 * ===== IALG_ALGORITHM_Alloc ======
 *
 * Returns algorithms memory requirements in the memTab structure   
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
Int IALG_ALGORITHM_Alloc(const IALG_Params * algParams, IALG_Fxns ** fxns, 
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
 * ===== IALG_ALGORITHM_Deactivate ======
 *
 * Deactivates the algorithm 
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
Void IALG_ALGORITHM_Deactivate(IALG_Handle handle)
{
    GT_1trace(CURTRACE, GT_4CLASS,
            "IALG_ALGORITHM_Deactivate> Called Deactivate for task %d\n", 
            ((DUMALG_TI_Handle)handle)->taskId);
    return;
}


/*
 * ===== IALG_ALGORITHM_NumAlloc ======
 *
 * Returns the number of memTab structures required to specify algorithms
 * memory requirements 
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
Int IALG_ALGORITHM_NumAlloc(Void)
{
        return (NUM_ALLOC);
}


/*
 * ===== IALG_ALGORITHM_Control ======
 *
 * Control commands for the algorithm to perform certain tasks 
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
Int IALG_ALGORITHM_Control(IALG_Handle handle, IALG_Cmd cmd,
    IALG_Status *status) 
{
#ifndef _DUCATI
    DUMALG_TI_Handle algHandle = (DUMALG_TI_Handle)handle;

    IRES_HDVICP_Properties resourceProperties;

    (*(IRES_Handle)(algHandle->resourceHandles[0])).getStaticProperties(
            (IRES_Handle)algHandle->resourceHandles[0],
                    (IRES_Properties *)&resourceProperties);
#endif
    return (0);
}


/*
 * ===== IALG_ALGORITHM_Activate ======
 *
 * Activate the algorithm 
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
Void IALG_ALGORITHM_Activate(IALG_Handle handle)
{
    GT_1trace(CURTRACE, GT_4CLASS,
            "IALG_ALGORITHM_Activate> Called Activate for task %d\n", 
            ((DUMALG_TI_Handle)handle)->taskId);
    return;
}

/*
 * ===== IALG_ALGORITHM_Free ======
 *
 * Free the memory allocated to the algorithsm  
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
Int IALG_ALGORITHM_Free(IALG_Handle handle, IALG_MemRec * memrec)
{
    DUMALG_TI_Handle alg = (Void *)handle; 
    memrec[0].base = alg;
    return (NUM_ALLOC);
}


/*
 * ===== IALG_ALGORITHM_Init ======
 *
 * Initialize the algorithm 
 * We know there is only one resource request
 * Use the passed param to determine which HDVICP resource the algorithm requires
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
Int IALG_ALGORITHM_Init(IALG_Handle handle, const IALG_MemRec *memrecs,
     IALG_Handle parent, const IALG_Params *params)
{
    Int i;
    IDUMALG_Params * myParams  = (IDUMALG_Params *)params;
    DUMALG_TI_Handle dumHandle = (DUMALG_TI_Handle)handle;

    for (i = 0; i < NUM_RESOURCES; i++) {
        dumHandle->hdvicp[i] = myParams->hdvicp[i];
    }
    dumHandle->yieldFlag = myParams->yieldFlag;
    dumHandle->taskId = myParams->taskId;
    
    return 0;
}


/*
 * ===== IALG_ALGORITHM_Moved ======
 *
 * Indicates that the algoirthm has moved in memory, performs initializations
 * as required
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
Void IALG_ALGORITHM_Moved(IALG_Handle handle1, const IALG_MemRec *memrecs,
    IALG_Handle handle2, const IALG_Params *params)
{
    return;
} 

/* IBUFALG functions */

IDUMALG_Params IDUMALG_PARAMS = {
    sizeof(IDUMALG_Params),
#ifdef _DUCATI
    //{IRES_HDVICP2_ID_ANY,IRES_HDVICP2_ID_LATE_ACQUIRE},
    {IRES_HDVICP2_ID_ANY},
#else
    {IRES_HDVICP_ID_ANY,IRES_HDVICP_ID_ANY},
#endif
/* Store what kind of HDVICP request is to be made */
    0,
    0
};

/*
 * ===== useHDVICP ======
 *
 * 
 */
/* ARGSUSED - this line tells the compiler not to warn about unused args. */
Int DUMALG_TI_useHDVICP(IDUMALG_Handle handle,unsigned int Id, unsigned int grp)
{
        Int i,j,k;
    DUMALG_TI_Obj * dumalg = (DUMALG_TI_Handle)handle; 
    XDAS_UInt32 reloadHDVICP;
    Int modeId;
        unsigned int sleepTime = 2;

#ifdef _DUCATI
    IRES_YieldContext yieldCtxt;
    yieldCtxt.algHandle = (IALG_Handle)dumalg;
    yieldCtxt.resourceHandle = NULL; 
    yieldCtxt.contextSave = NULL;
    yieldCtxt.contextRestore = NULL;      
    yieldCtxt.contextArgs = NULL; 

    printf("Task %d: Alg 0x%x Scratch Group %d\n", Id, handle, grp); 


    for (i = 0; i < 4; i++) { 

        for (j = 0; j < NUM_RESOURCES; j++) {

            if (NULL != dumalg->resourceHandles[j]->acquire) {

                printf("Task %d: (Scratch Grp %d) HDVICP2 alg about to (late) "
                        "acquire %d\n", Id,grp,  ((IRES_HDVICP2_Handle)
                        (dumalg->resourceHandles[j]))->id);
   
                /* Use this to acquire and release the IVA HD resource */
                (dumalg->resourceHandles[j])->acquire((IALG_Handle)handle, 
                        (IRES_HDVICP2_Handle)(dumalg->resourceHandles[j]),
                        &yieldCtxt, &reloadHDVICP, (Void *)&modeId,
                        IRES_HDVICP2_UNKNOWNLATEACQUIREARG);

                /* Print the resource */
                printf("Task %d: (Scratch Grp %d) HDVICP2 alg acquired %d "
                        "reload required %d\n", Id,grp,  
                        ((IRES_HDVICP2_Handle)(dumalg->resourceHandles[j]))->id,
                        reloadHDVICP);
                /* Use the resource */
                for (k = 0; k < 1; k++) {
    
                    printf("Task %d: (Scratch Grp %d) HDVICP2 alg 0x%x "
                            "configuring "
                            "IVAHD %d\n", Id, grp, handle,
                            ((IRES_HDVICP2_Handle)
                            (dumalg->resourceHandles[j]))->id);
    
                    /* Configure and use the resource */
                    (dumalg->resourceHandles[j])->configure((IALG_Handle)dumalg,
                            dumalg->resourceHandles[j],
                            (IRES_HDVICP2_CallbackFxn)
                            NULL, (Void *)grp /* For testing purposes change 
                            this NULL to the groupId */);
    
                    /* Fire off IVAHD and do something else, or simply sleep */
                    printf("Task %d: (Scratch Grp %d) HDVICP2 alg 0x%x "
                            "configured "
                            "IVAHD %d and doing some task on it\n", Id, grp, 
                            handle,
                            ((IRES_HDVICP2_Handle)
                            (dumalg->resourceHandles[j]))->id);
    
                    //Task_sleep(sleepTime);
    
                    printf("Task %d: (Scratch Grp %d) HDVICP2 alg 0x%x calling "
                            "WAIT\n", Id, grp, handle);
    
                    (dumalg->resourceHandles[j])->wait((IALG_Handle)dumalg,
                            dumalg->resourceHandles[j], &yieldCtxt);
    
                    printf("Task %d: (Scratch Grp %d) HDVICP2 alg 0x%x back "
                            "from WAIT\n", Id, grp, handle);
    
                }

                /* After using the resources, I'm going to increase my 
                   priority if my taskId is > 6 */ 
                if (Id <= 6) {
                    Task_setPri(Task_self(), LOWESTPRI);
                }
    
                
                (dumalg->resourceHandles[j])->release((IALG_Handle)handle, 
                        (IRES_HDVICP2_Handle)(dumalg->resourceHandles[j])); 
        
                printf("Task %d: (Scratch Grp %d) HDVICP2 alg released %d\n",Id,
                        grp,  ((IRES_HDVICP2_Handle)
                        (dumalg->resourceHandles[j]))->id);
            }
        }
    }


#else

    if (dumalg->yieldFlag) {

            for (i = 0; i < NUM_RESOURCES; i++) {
            GT_2trace(CURTRACE, GT_4CLASS,
                    "_DUMALG_TI_useHDVICP> Task #%d: Yielding HDVICP resource "
                    "%d\n", Id, (Int)(dumalg->hdvicp[i]));
            }
                
        dumalg->yieldFxn((IRES_YieldResourceType)IRES_ALL,&dumalg->yieldContext,
                dumalg->yieldArgs);

            for (i = 0; i < NUM_RESOURCES; i++) {
            GT_2trace(CURTRACE, GT_4CLASS,
                    "_DUMALG_TI_useHDVICP> Task #%d: HDVICP resource %d "
                    "re-acquired\n", Id, (Int)(dumalg->hdvicp[i]));     
            }

    }
    else {
            for (i = 0; i < NUM_RESOURCES; i++) {
            GT_2trace(CURTRACE, GT_4CLASS,
                    "_DUMALG_TI_useHDVICP> Task #%d: Not yielding HDVICP "
                    "resource %d\n", Id, (Int)(dumalg->hdvicp[i]));     
            }
    }

#endif

    return 0;
}

/* ARGSUSED - this line tells the compiler not to warn about unused args. */
static Void contextSave(IALG_Handle algHandle, Void *contextArgs)
{
    GT_1trace(CURTRACE, GT_4CLASS,
            "contextSave> Saving HDVICP context for task %d\n", 
            ((DUMALG_TI_Handle)algHandle)->taskId);
}

/* ARGSUSED - this line tells the compiler not to warn about unused args. */
static Void contextRestore(IALG_Handle algHandle, Void *contextArgs)
{
    GT_1trace(CURTRACE, GT_4CLASS,
            "contextRestore> Restoring HDVICP context for task %d\n", 
            ((DUMALG_TI_Handle)algHandle)->taskId);
}

/*
 * TI's implementation of IDUMALG 
 */
IDUMALG_Fxns DUMALG_TI_IDUMALG = {
    {
    IALGFXNS
    },
    DUMALG_TI_useHDVICP
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
 *  @(#) ti.sdo.fc.rman.examples.plugin; 1, 0, 0,4; 2-22-2012 18:08:05; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

