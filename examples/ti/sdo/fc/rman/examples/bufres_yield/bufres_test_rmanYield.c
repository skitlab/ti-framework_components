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
 *  ======== bufres_test.c ========
 *  Test algorithms using the Buffer Resources.
 */

#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/knl/SemThread.h>

#include <stdlib.h>
#include <string.h>

#include <ti/sdo/fc/dskt2/dskt2.h>
#include <ti/sysbios/knl/Task.h>

#include <ti/sdo/fc/ires/iresman.h>

#include <ti/sdo/fc/rman/rman.h>

#include <bufalg_ti.h>
#include <ti/sdo/fc/rman/examples/bufres_yield/bufres.h>
#include <bufres_util.h>


/* Globals defined in cfg file */
#include <xdc/cfg/global.h>

#define CURTRACE ti_sdo_fc_rman_examples_bufres_yield_GTMask


#define NUMTASKS 2
#define MAXTASKS 5

/*
 *  ======== ScratchTskAttrs ========
 */
typedef struct ScratchTskAttrs {
    Int         priority;       /* Priority of task */
    Uns         size;           /* Scratch buffer size */
    Uns         fillValue;      /* Value to fill scratch buffer with */
} ScratchTskAttrs;

/*
 * heapId in which to create the tasks
 */
extern const ti_sysbios_heaps_HeapMem_Handle EXTMEM_HEAP;


extern Int smain(Int argc, Char * argv[]);
extern Int rmanTask(UArg size, UArg fillValue, UArg taskId);
extern Void myIdle();
extern IRESMAN_PersistentAllocFxn DSKT2_allocPersistent;
extern IRESMAN_PersistentFreeFxn  DSKT2_freePersistent;


/* Scratch task parameters */
static ScratchTskAttrs attrsTable[MAXTASKS] = {
    /* priority    scratchSize    fillValue */
    3,             0x80,          0x201,
    3,             0x100,         0x202,
    3,             0x60,          0x203,
    3,             0x100,         0x204,
    4,             0x80,          0x301,
};

/* Gets posted by last task to finish */
static SemThread_Handle done = NULL;

/* Protect DSKT2_createAlg and DSKT2_freeAlg */
static SemThread_Handle mutex = NULL;


/*
 *  ======== myIdle ========
 *  Idle task can do the cleanup
 */
Void myIdle()
{
    IRES_Status status ;

    /* Unregister the protocol */
    status = RMAN_unregister(&BUFRES_MGRFXNS);
    if (status != IRES_OK) {
        Log_print1(Diags_USER7, "[+7] myIdle> RMAN_unregister Failed [%d] ",
                (IArg)status);

        System_abort("Aborting...\n");
    }

    status = RMAN_exit();
    if (IRES_OK != status) {
        Log_print0(Diags_USER7, "[+7] myIdle> RMAN Exit Failed ");
        System_abort("Aborting...\n");
    }
}


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

    SemThread_Params_init(&semParams);
    done = SemThread_create(0, &semParams, NULL);

    SemThread_Params_init(&semParams);
    mutex = SemThread_create(1, &semParams, NULL);

    if ((done == NULL) || (mutex == NULL)) {
        Log_print0(Diags_USER7, "[+7] smain> Semaphore creation failed");

        System_abort("SemThread_create failed \n");
    }

    Task_Params_init(&taskParams);
    /*
     *  Add the following line to have the stack allocated from the external
     *  heap:
     *      taskParams.stackHeap = (IHeap_Handle)EXTMEM_HEAP;
     */

    for (i = 0; i < NUMTASKS; i++) {
        Task_Params_init(&taskParams);
        taskParams.priority = attrsTable[i].priority;
        taskParams.stackHeap = (IHeap_Handle)EXTMEM_HEAP;      
        taskParams.arg0 = (UArg)(attrsTable[i].fillValue);
        taskParams.arg1 = (UArg)(i + 1);

        tsk = Task_create((ti_sysbios_knl_Task_FuncPtr)rmanTask,
                &taskParams, NULL);
        if (tsk == NULL) {

            Log_print1(Diags_USER7, "[+7] smain> Task_create of task %d failed",
                    (IArg)(i + 1));

            System_abort("Task_create() failed\n");
        }
    }

    for (i = 0; i < NUMTASKS; i++) {
        SemThread_pend(done, SemThread_FOREVER, NULL);
    }

    SemThread_delete(&mutex);
    SemThread_delete(&done);

    Log_print0(Diags_USER4, "[+4] smain> TEST COMPLETED");

    return (0);
}

/*
 *  ======== rmanTask ========
 */
Int rmanTask(UArg size, UArg fillValue, UArg taskId)
{
    IBUFALG_Handle     alg;
    IBUFALG_Fxns       fxns = BUFALG_TI_IBUFALG;  /* IALG implementation ? */
    IRES_Fxns          iresFxns = BUFALG_TI_IRES; /* IRES implementation */
    Int                scratchId = 1;
    IRES_Status        status;


    Log_print2(Diags_USER4, "[+4] rmanTask> Task Id %d fillValue 0x%x ",
            (IArg)taskId, (IArg)(fillValue ));


    SemThread_pend(mutex, SemThread_FOREVER, NULL);

    /* Create an instance of the algorithm using "algFxns" */
    alg = (IBUFALG_Handle)DSKT2_createAlg(scratchId,
            (IALG_Fxns *)&fxns, NULL,(IALG_Params *)NULL);

    if (alg == NULL) {
        Log_print0(Diags_USER7, "[+7] rmanTask> Alg creation failed");

        return (-1);
    }

    SemThread_post(mutex, NULL);

    /* Assign resources to the algorithm */
    status = RMAN_assignResources((IALG_Handle)alg, &iresFxns, scratchId);

    if (status != IRES_OK) {
        Log_print4(Diags_USER7, "[+7] rmanTask> Assign resources failed "
                "[%d] for alg 0x%x, scratchId %d IRES interface 0x%x",
                (IArg)status, (IArg)alg, (IArg)scratchId, (IArg)&iresFxns);

        return (-1);
    }

    DSKT2_activateAlg(scratchId, (IALG_Handle)alg);

    /* Activate All Resources */
    RMAN_activateAllResources((IALG_Handle)alg, &iresFxns, scratchId);

    alg->fxns->useBufs(alg, fillValue, taskId);

    /* Deactivate All Resources */
    RMAN_deactivateAllResources((IALG_Handle)alg, &iresFxns, scratchId);

    /* Deactivate algorithm */
    DSKT2_deactivateAlg(scratchId, (IALG_Handle)alg);

    /* Free resources assigned to this algorihtm */
    status = RMAN_freeResources((IALG_Handle)(alg), &iresFxns, scratchId);

    if (status != IRES_OK) {
        Log_print4(Diags_USER7, "[+7] rmanTask> Free resources failed [%d] "
                "for alg 0x%x, scratchId %d, IRES interface 0x%x",
                (IArg)status, (IArg)alg, (IArg)scratchId, (IArg)&iresFxns);

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
 *  @(#) ti.sdo.fc.rman.examples.bufres_yield; 1, 0, 0,4; 2-22-2012 18:07:24; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

