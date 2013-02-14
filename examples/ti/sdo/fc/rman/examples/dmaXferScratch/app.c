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
#include <ti/sdo/fc/memutils/memutils.h>
#include <ti/sysbios/knl/Task.h>

/* Algorithm */
#include <ti/sdo/fc/ires/examples/codecs/universal_dma/universal_dma_ti.h>

/* xdm */
#include <ti/xdais/dm/iuniversal.h>

#include <ti/sdo/fc/ires/edma3chan/iresman_edma3Chan.h>

extern cregister volatile Uns DNUM;

#ifdef MULTICORE

/* EDMA3 module can be configured at runtime if required */
#include <ti/sdo/fc/edma3/edma3_config.h>

#endif

#ifdef __TI_COMPILER_VERSION__
/* Placing the DMA buffers in INTERNAL/EXTERNAL memory as desired */
//#pragma DATA_SECTION(SRCBUFF,".EXTMEM_HEAP")
#pragma DATA_SECTION(SRCBUFF,".INTMEM_HEAP")
//#pragma DATA_SECTION(DSTBUFF,".INTMEM_HEAP")
#pragma DATA_SECTION(DSTBUFF,".EXTMEM_HEAP")
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
#define DMAXFER_BUFSIZE 0x100
#define NUMTASKS 1 /* 12 */
#define MAXTASKS 12
#define MAXCORES 16

#define CURTRACE ti_sdo_fc_rman_examples_dmaXferScratch

#ifdef MULTICORE

/* If you need to override the default configuration for edma resource
   assignment to regions, you will need to declare a structure initialized
   with the new assignments, and then assign it to EDMA3_PARAMS.regionConfig.

    #include <ti/sdo/fc/edma3/edma3_config.h>
    extern EDMA3_InstanceInitConfig overridingConfig[][8];
*/
#endif

unsigned int SRCBUFF[DMAXFER_BUFSIZE * NUMTASKS * MAXCORES];
unsigned int DSTBUFF[DMAXFER_BUFSIZE * NUMTASKS * MAXCORES];

/*
 * heapId in which to create the tasks
 */
extern Int EXTMEM_HEAP;
extern Int INTMEM_HEAP;

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
    IRES_Status status;
    IRESMAN_Edma3ChanParams initArgs;

    status = RMAN_init();

   if (IRES_OK != status) {
        Log_print0(Diags_USER7, "[+7] main> RMAN initialization Failed ");
        System_abort("Aborting...\n");
    }

    initArgs.baseConfig.size = sizeof(IRESMAN_Edma3ChanParams);
    initArgs.baseConfig.allocFxn = &DSKT2_allocPersistent;
    initArgs.baseConfig.freeFxn = &DSKT2_freePersistent;

    status = RMAN_register(&IRESMAN_EDMA3CHAN, (IRESMAN_Params *)&initArgs);

   if ((IRES_OK != status) && ( IRES_EEXISTS != status)){
        Log_print0(Diags_USER7, "[+7] main> IRES registration Failed ");
        System_abort("Aborting...\n");
    }


#ifdef MULTICORE

    /* If you'd like to override the default configuration for one/more
       cores, do it as follows
       EDMA3_PARAMS.regionConfig = overridingConfig[0][coreId];
    */

    /* If you'd like to use the existing default configuration for one/more
       cores, then associate each core with a different region
       EDMA3_PARAMS.regionId = coreId;
    */

#ifdef SHANNON
    /* For Shannon we need to use a distribution of different EDMA3 instances
       for apps built for different cores. This distribution coincides with
       the distribution of resources among different cores (in default config)*/
    if ((coreId == 0) || (coreId == 6) || (coreId == 7)) {
         ti_sdo_fc_edma3_EDMA3_physicalId = 2;
    }
    if ((coreId == 1) || (coreId == 2)) {
        ti_sdo_fc_edma3_EDMA3_physicalId = 0;
    }
    if ((coreId == 3) || (coreId == 4) || (coreId == 5)) {
        ti_sdo_fc_edma3_EDMA3_physicalId = 1;
    }
    EDMA3_PARAMS.regionId = coreId;
#endif

#endif
    /* Populate SRCBUF, and DSTBUF with data */

    for (i = 0; i < (DMAXFER_BUFSIZE * NUMTASKS); i++) {
        SRCBUFF[i + coreId * DMAXFER_BUFSIZE * NUMTASKS] = 0x8C0FFEE0 | coreId;
        DSTBUFF[i + coreId * DMAXFER_BUFSIZE * NUMTASKS] = 0xDEADBEE0 | coreId;
    }

    MEMUTILS_cacheWb(&SRCBUFF[coreId * DMAXFER_BUFSIZE * NUMTASKS],
            DMAXFER_BUFSIZE * NUMTASKS * 4);
    MEMUTILS_cacheWb(&DSTBUFF[coreId * DMAXFER_BUFSIZE * NUMTASKS],
            DMAXFER_BUFSIZE * NUMTASKS * 4);

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
        taskParams.stackSize = 0x8000;

#ifdef SINGLEIMAGE
/* For the singleImage builds, we take care to keep everything in internal
   memory */
        taskParams.stackHeap = (IHeap_Handle)INTMEM_HEAP;
#else
        taskParams.stackHeap = (IHeap_Handle)EXTMEM_HEAP;
#endif
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
        if (SRCBUFF[i + coreId * DMAXFER_BUFSIZE * NUMTASKS] !=
                DSTBUFF[i + coreId * DMAXFER_BUFSIZE * NUMTASKS]) {
            printf("*** Address mismatch at index %d, 0x%x != 0x%x\n",
                    i, SRCBUFF[i + coreId * DMAXFER_BUFSIZE * NUMTASKS] ,
                    DSTBUFF[i + coreId * DMAXFER_BUFSIZE * NUMTASKS]);
            System_abort(" smain> TEST FAILED******");
        }
    }


    SemThread_delete(&mutex);
    SemThread_delete(&done);

    Log_print0(Diags_USER4, "[+4] smain> TEST PASSED");
    printf(" smain> TEST PASSED\n");

    return (0);
}
void Log_printr0(int i, char *s){}
/*
 *  ======== rmanTask ========
 */
/* ARGSUSED */
Int rmanTask(UArg taskId, UArg index)
{
    Int         scratchId;
    IALG_Fxns * algFxns = (IALG_Fxns *)&UNIVERSAL_DMA_TI_CODECIRES;
    IRES_Fxns * resFxns = &UNIVERSAL_DMA_TI_IRES;
    IUNIVERSAL_Handle alg = NULL;
    IRES_Status status;

    XDM1_BufDesc                inBufDesc;
    XDM1_BufDesc                outBufDesc;
    XDM1_BufDesc                inOutBufDesc;
    XDAS_Int8 *                 buffSrc;
    XDAS_Int8 *                 buffDest;

    UNIVERSAL_DMA_InArgs           decInArgs;
    IUNIVERSAL_OutArgs             decOutArgs;

    inBufDesc.numBufs = outBufDesc.numBufs = 1;
    inOutBufDesc.numBufs = 0;
    inBufDesc.descs[0].bufSize = outBufDesc.descs[0].bufSize = DMAXFER_BUFSIZE;
    decInArgs.numBytes = DMAXFER_BUFSIZE * 4;
    buffSrc = (XDAS_Int8 *)&SRCBUFF[(DNUM * NUMTASKS + index) *
            DMAXFER_BUFSIZE];
    buffDest = (XDAS_Int8 *)&DSTBUFF[(DNUM * NUMTASKS + index) *
            DMAXFER_BUFSIZE];
    /* For multicore devices, peripherals such as the the EDMA hardware do not
       recognize internal memory addresses (generated by the platform), these
       addresses have to be convered into h/w specific addresses that DMA
       understands. */
    inBufDesc.descs[0].buf = MEMUTILS_getPhysicalAddr(buffSrc);
    outBufDesc.descs[0].buf = MEMUTILS_getPhysicalAddr(buffDest);

    /* initialize all "sized" fields */
    decInArgs.size    = sizeof(decInArgs);
    decOutArgs.size   = sizeof(decOutArgs);

    scratchId = attrsTable[index].scratchId;

    SemThread_pend(mutex, SemThread_FOREVER, NULL);

    /* Create an instance of the algorithm using "algFxns" */
    alg = (IUNIVERSAL_Handle)DSKT2_createAlg(scratchId,
            (IALG_Fxns *)algFxns, NULL,(IALG_Params *)NULL);
    if (alg == NULL) {
        System_printf("Alg creation failed for alg\n");
        return (-1);
    }
    {
        IUNIVERSAL_Handle alg2;
        IUNIVERSAL_Handle alg3;
        IUNIVERSAL_Handle alg4;
        IALG_MemRec memTab[1];
        extern Bool DSKT2_allocScratch2(IALG_Handle alg, Int mutexId,
                IALG_MemRec *memTab, Int numRecs);

        alg2 = (IUNIVERSAL_Handle)DSKT2_createAlg(1,
                (IALG_Fxns *)algFxns, NULL,(IALG_Params *)NULL);
        alg3 = (IUNIVERSAL_Handle)DSKT2_createAlg(2,
                (IALG_Fxns *)algFxns, NULL,(IALG_Params *)NULL);
        alg4 = (IUNIVERSAL_Handle)DSKT2_createAlg(1,
                (IALG_Fxns *)algFxns, NULL,(IALG_Params *)NULL);

        memTab[0].size = 100;
        memTab[0].alignment = 4;
        memTab[0].space = IALG_DARAM0;
        memTab[0].attrs = IALG_SCRATCH;
        memTab[0].base = (void *) NULL;

        DSKT2_allocScratch2((IALG_Handle)alg, scratchId, memTab, 1);
        memTab[0].size = 50;
        memTab[0].base = (void *) NULL;
        DSKT2_allocScratch2((IALG_Handle)alg, scratchId, memTab, 1);
        memTab[0].size = 200;
        memTab[0].base = (void *) NULL;
        DSKT2_allocScratch2((IALG_Handle)alg3, 2, memTab, 1);

        memTab[0].size = 50;
        memTab[0].base = (void *) NULL;
        /* try non-alg context allocation from shared scratch */
        DSKT2_allocScratch2((IALG_Handle)NULL, scratchId, memTab, 1);

        DSKT2_getScratchId((IALG_Handle)alg);
        DSKT2_getScratchId((IALG_Handle)alg2);
        DSKT2_getScratchId((IALG_Handle)alg3);
        DSKT2_getScratchId((IALG_Handle)alg4);
    }
    SemThread_post(mutex, NULL);

    /* Assign resources to the algorithm */
    status = RMAN_assignResources((IALG_Handle)alg, resFxns, scratchId);
    if (status != IRES_OK) {
        System_printf("Assign Resource Failed [%d]\n", status);
        return (-1);
    }

    /*
     * Activate the Algorithm
     */
    DSKT2_activateAlg(scratchId, (IALG_Handle)alg);

    /*
     * Activate All Resources
     */
    RMAN_activateAllResources((IALG_Handle)alg, resFxns, scratchId);

    /*
     * Use IALG interfaces to call the process API that performs the DMA
     * transfer.
     */
    if (IUNIVERSAL_EOK != alg->fxns->process(alg, &inBufDesc, &outBufDesc,
            &inOutBufDesc, (IUNIVERSAL_InArgs *)&decInArgs, &decOutArgs)) {
            System_abort(" rmanTask> TEST FAILED****** in Task Id " + taskId);
    }

    /*
     * Deactivate All Resources
     */
    RMAN_deactivateAllResources((IALG_Handle)alg, resFxns, scratchId);

    /*
     * Deactivate algorithm
     */
    DSKT2_deactivateAlg(scratchId, (IALG_Handle)alg);

    /*
     * Free resources assigned to this algorihtm
     */
    status = RMAN_freeResources((IALG_Handle)(alg), resFxns, scratchId);
    if (IRES_OK != status) {
        System_printf("Free Resource Failed [%d]\n", status);
        return (-1);
    }

    SemThread_pend(mutex, SemThread_FOREVER, NULL);

    /* Free instance of the algorithm created */
    DSKT2_freeAlg(scratchId, (IALG_Handle)alg);

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

