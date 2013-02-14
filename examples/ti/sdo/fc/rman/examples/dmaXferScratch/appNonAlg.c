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
 *  ======== app.c ========
 */

#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/knl/SemThread.h>

#include <stdio.h>
#include <stdlib.h>

#include <ti/sdo/fc/rman/rman.h>
#include <ti/sdo/fc/dskt2/dskt2.h>
#include <ti/sdo/fc/ecpy/ecpy.h>
#include <ti/sdo/fc/memutils/memutils.h>
#include <ti/sysbios/knl/Task.h>

/* IRES resources */
#include <ti/sdo/fc/ires/edma3chan/iresman_edma3Chan.h>
#include <ti/sdo/fc/ires/edma3chan/ires_edma3Chan.h>

#ifdef __TI_COMPILER_VERSION__
/* Placing the DMA buffers in INTERNAL memory */ 
//#pragma DATA_SECTION(SRCBUFF,".EXTMEM_HEAP")
//#pragma DATA_SECTION(DSTBUFF,".EXTMEM_HEAP")
#endif

/*
 *  ======== ScratchTskAttrs ========
 */
typedef struct ScratchTskAttrs {
    Int         priority;       /* Priority of task */
    Int         scratchId;      /* Scratch group in which to create the task */
    Int         yieldFlag;
    Uns         fillValue;
} ScratchTskAttrs;


#define MOD_NAME "*"
#define DMAXFER_BUFSIZE 0x400
#define NUMTASKS 3 /* 12 */
#define MAXTASKS 12

#define CURTRACE ti_sdo_fc_rman_examples_dmaXferScratch


#define CONVERT_TO_GLOBALADDR(addr) ( (((Uns)(addr) & 0xFF000000) == 0)? \
        (void *)((1u << 28) | (DNUM << 24) | (Uns)(addr)) : \
        (void *)addr)


extern cregister volatile Uns DNUM;

#ifdef MULTICORE

/* If you need to override the default configuration for edma resource
   assignment to regions, you will need to declare a structure initialized
   with the new assignments, and then assign it to EDMA3_PARAMS.regionConfig. */
//#include <ti/sdo/fc/edma3/edma3_config.h>
//extern EDMA3_InstanceInitConfig overridingConfig[][8];
#endif

unsigned int SRCBUFF[DMAXFER_BUFSIZE * NUMTASKS];
unsigned int DSTBUFF[DMAXFER_BUFSIZE * NUMTASKS];

/*
 * heapId in which to create the tasks
 */
extern Int EXTMEM_HEAP;

/* Semaphores for the tasks */
static SemThread_Handle done = NULL;  /* Gets posted by last task to finish */

/* Protect DSKT2_createAlg and DSKT2_freeAlg */
static SemThread_Handle mutex = NULL;

/* Scratch task parameters */
static ScratchTskAttrs attrsTable[MAXTASKS] = {
    /* priority,    scratchGroup   yieldFlag somAttr */
    12,              1,      1,     0x1,
    13,              1,      0,     0x2,
        13,              1,      0,     0x3,
        13,              1,      0,     0x4,
        13,              1,      0,     0x5,
        13,              1,      0,     0x6,
        13,              1,      0,     0x7,
    12,              1,      1,     0x8,
        13,              1,      0,     0x9,
    12,              1,      1,     0xA,
        13,              1,      0,     0xB,
    12,              1,      1,     0xC
};

/*
 * extern declaration
 */
extern Int smain(Int argc, Char * argv[]);
extern Int rmanTask(UArg arg0, UArg arg1);

/*
 *  ======== smain ========
 */
/* ARGSUSED */
Int smain(Int argc, Char * argv[])
{
    SemThread_Params semParams;
    Task_Params      taskParams;
    Task_Handle      tsk;
    Int              i;
    Int coreId = DNUM;

#ifdef MULTICORE
    /* If you'd like to override the default configuration for one/more  
       cores, do it as follows */
    //EDMA3_PARAMS.regionConfig = overridingConfig[0][coreId]; 
#endif
    /* Populate SRCBUF with data */
    
    for (i = 0; i < (DMAXFER_BUFSIZE * NUMTASKS); i++) {
        SRCBUFF[i] = 0x8C0FFEE8;
        DSTBUFF[i] = 0xDEADBEEF;
    }

    MEMUTILS_cacheWb(SRCBUFF, DMAXFER_BUFSIZE * NUMTASKS * 4);
    MEMUTILS_cacheWb(DSTBUFF, DMAXFER_BUFSIZE * NUMTASKS * 4);
   

    SemThread_Params_init(&semParams);
    done = SemThread_create(0, &semParams, NULL);

    SemThread_Params_init(&semParams);
    mutex = SemThread_create(1, &semParams, NULL);

    if ((done == NULL) || (mutex == NULL)) {
        Log_print0(Diags_USER7, "[+7] smain> Semaphore creation failed");

        System_abort("SemThread_create failed \n");
    }

    Task_Params_init(&taskParams);

    for (i = 0; i < NUMTASKS; i++) {
        Task_Params_init(&taskParams);
        taskParams.priority = attrsTable[i].priority;
        taskParams.stackSize = 0x5000;
        taskParams.stackHeap = (IHeap_Handle)EXTMEM_HEAP;
        taskParams.arg0 = i + 1; /* task id */
        taskParams.arg1 = i;     /* index into attrsTable */
        tsk = Task_create((Task_FuncPtr)rmanTask, &taskParams, NULL);

        if (tsk == NULL) {

            Log_print1(Diags_USER7, "[+7] smain> Task_create of task %d failed",
                    (IArg)(i + 1));

            System_abort("Task_create() failed\n");
        }
    }

    for (i = 0; i < NUMTASKS; i++) {
        SemThread_pend(done, SemThread_FOREVER, NULL);
    }


    MEMUTILS_cacheInv(DSTBUFF, DMAXFER_BUFSIZE * NUMTASKS * 4);
    for (i = 0; i < (DMAXFER_BUFSIZE * NUMTASKS); i++) {
        if (SRCBUFF[i] != DSTBUFF[i]) {
            System_abort(" smain> TEST FAILED******");
        }
    }
    

    SemThread_delete(&mutex);
    SemThread_delete(&done);

    Log_print0(Diags_USER4, "[+4] smain> TEST PASSED");
    printf(" smain> TEST PASSED\n");

    return (0);
}

/*
 *  ======== rmanTask ========
 */
/* ARGSUSED */
Int rmanTask(UArg taskId, UArg index)
{
    Int         scratchId;
    IRES_Status status;

    XDAS_Int8 *                 buffSrc;
    XDAS_Int8 *                 buffDest;

#define NUM_IRES_RESOURCES 2
    IRES_ResourceDescriptor resourceDesc[NUM_IRES_RESOURCES];
    IRES_EDMA3CHAN_ProtocolArgs edmaProtocolArgs[NUM_IRES_RESOURCES];
    IRES_ProtocolRevision       edmaProtocolRev;  //{2,0,0} Version of resource;
    ECPY_Handle dmaHandle0;
    ECPY_Params p;
    int size, frameSize;
    unsigned char *src, *dst;

    buffSrc = (XDAS_Int8 *)(SRCBUFF + index * DMAXFER_BUFSIZE);
    buffDest = (XDAS_Int8 *)(DSTBUFF + index * DMAXFER_BUFSIZE);

    scratchId = attrsTable[index].scratchId;

    SemThread_pend(mutex, SemThread_FOREVER, NULL);

    /* call _DSKT2_init() here until DSKT2 fix to call it from DSKT2 allocation
     * function used by RMAN.
     */
    _DSKT2_init();

    /* Request IRES_EDMA3CHAN version 2.0.0 to use with ECPY */
    resourceDesc[0].resourceName = IRES_EDMA3CHAN_PROTOCOLNAME;
    IRES_EDMA3CHAN_SETPROTOCOLREVISION_2_0_0(&edmaProtocolRev);
    resourceDesc[0].revision = &edmaProtocolRev;
    
    /* set EDMA3 Request Descriptor's protocol args */
    edmaProtocolArgs[0].size = sizeof(IRES_EDMA3CHAN_ProtocolArgs);
    edmaProtocolArgs[0].mode = IRES_SCRATCH;
    edmaProtocolArgs[0].numPaRams = 3;
    edmaProtocolArgs[0].paRamIndex = IRES_EDMA3CHAN_PARAM_ANY;
    edmaProtocolArgs[0].tccIndex = IRES_EDMA3CHAN_TCC_ANY;
    edmaProtocolArgs[0].numTccs = 1;
    edmaProtocolArgs[0].qdmaChan = IRES_EDMA3CHAN_CHAN_NONE;
    edmaProtocolArgs[0].edmaChan = IRES_EDMA3CHAN_EDMACHAN_ANY;
    edmaProtocolArgs[0].contiguousAllocation = TRUE;
    edmaProtocolArgs[0].shadowPaRamsAllocation = FALSE;
    resourceDesc[0].protocolArgs = (IRES_ProtocolArgs *)&edmaProtocolArgs[0];

    resourceDesc[0].handle = (IRES_Handle)NULL;
    scratchId = attrsTable[index].scratchId;

    status = RMAN_allocateResources( taskId /* set requestId to this->taskId */,
             resourceDesc, 1, scratchId);

    if (status != IRES_OK) {
        System_printf("RMAN Allocate Resources Failed [%d]\n", status);
        return (-1);
    }
             
    dmaHandle0 = ECPY_createHandle((IRES_EDMA3CHAN2_Handle)
            resourceDesc[0].handle, (IALG_Handle) taskId);
            
    ECPY_activate(dmaHandle0);
   
    size = DMAXFER_BUFSIZE * 4;
    src = CONVERT_TO_GLOBALADDR(buffSrc); 
    dst = CONVERT_TO_GLOBALADDR(buffDest); 
    
    /* Define base transfer type as 2D2D of 4 elements x 4-byte element size */
    p.transferType = ECPY_2D2D;
    p.elementSize = 4;
    p.numElements = 4;

    /* Each transfer will skip alternating elemenr-size blocks. */
    p.srcElementIndex = 2 * 4;
    p.dstElementIndex = 2 * 4;

    /* Each Frame has elemensize holes between elements.No gap between frames */
    frameSize = 4 * 4 * 2;
    p.srcFrameIndex = frameSize;
    p.dstFrameIndex = frameSize;

    /* Two transfers will end up copying half the data each */
    p.numFrames = size / frameSize;

    ECPY_directConfigure(dmaHandle0, &p, 1);

    ECPY_directConfigure32(dmaHandle0, ECPY_PARAMFIELD_SRCADDR,
            (unsigned int)src, 1);
    ECPY_directConfigure32(dmaHandle0, ECPY_PARAMFIELD_DSTADDR,
            (unsigned int)dst, 1);

    /* prepare second transfer of the linked transfer, to fill
     * the gaps in the striped element block shaped frames of first 3D transfer
     */
    ECPY_directConfigure(dmaHandle0, &p, 2);
    ECPY_directConfigure32(dmaHandle0, ECPY_PARAMFIELD_SRCADDR, 
            (unsigned int)src + p.elementSize, 2);
    ECPY_directConfigure32(dmaHandle0, ECPY_PARAMFIELD_DSTADDR, 
            (unsigned int)dst + p.elementSize, 2);
    
    /* submit as a two linked 3D transfers */
    ECPY_directSetFinal(dmaHandle0, 2);
    
    ECPY_directStartEdma(dmaHandle0);
    ECPY_directWait(dmaHandle0);
    
    /* Free allocated resources using the same requestId */
    status = RMAN_freeAllocatedResources( taskId, resourceDesc, 1, scratchId);

    SemThread_post(mutex, NULL);

    SemThread_pend(mutex, SemThread_FOREVER, NULL);

    SemThread_post(mutex, NULL);

    SemThread_post(done, NULL);

    Log_print1(Diags_USER4, "[+4] rmanTask> Completed task %d", (IArg)taskId);

    return (0);
}

/*
 *  ======== myIdle ========
 *  Idle task can do the cleanup ?
 */
Void myIdle()
{
    IRES_Status status ;

    status = RMAN_exit();

    if (IRES_OK != status) {

        Log_print0(Diags_USER7, "[+7] _myIdle> RMAN Exit Failed ");

        exit(-1);
    }

    exit(0);
}
/*
 *  @(#) ti.sdo.fc.rman.examples.dmaXferScratch; 1, 0, 0,4; 2-22-2012 18:07:47; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

