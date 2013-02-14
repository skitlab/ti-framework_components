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
#include <stdio.h>

#include <xdc/runtime/System.h>
#include <xdc/runtime/knl/SemThread.h>

#include <ti/sysbios/knl/Task.h>

#include <ti/sdo/fc/dskt2/dskt2.h>

#include <ti/sdo/fc/rman/rman.h> 
#include <ti/sdo/fc/ires/hdvicp/iresman_hdvicp.h>

#include <stdlib.h>

#include "ires_algorithm.h"

#include <ti/sdo/utils/trace/gt.h>

extern GT_Mask CURTRACE;

#define NUMTASKS 12 
#define MAXTASKS 12  
#define MODNAME "ti.sdo.fc.rman.examples.hdvicp"
#define NUMIVAHD 3

/*
 *  ======== ScratchTskAttrs ========
 */
typedef struct ScratchTskAttrs {
    Int         priority;       /* Priority of task */
    Int         scratchId;      /* Scratch group in which to create the task */
    Int         id[2]; 
    Int         yieldFlag;
} ScratchTskAttrs;

/*
 * heapId in which to create the tasks 
 */
extern Int EXTMEM_HEAP;

/*
 * Tasks 
 */
extern Void smain(UArg arg0, UArg arg1);

extern Void rmanTask(UArg arg0, UArg arg1);
extern Void myIdle();

IRES_Status getIVAHD(Int *Id, IALG_Handle alg, IRES_HDVICP2_Handle handle);

IRES_Status freeIVAHD(Int Id, IALG_Handle alg, IRES_HDVICP2_Handle handle);

static Int rrcounter = 0;
static Int busyStatus[NUMIVAHD] = {0,0,0};

/* Scratch task parameters */
static ScratchTskAttrs attrsTable[MAXTASKS] = {
/* priority,    scratchGroup    resources                       yieldFlag */
LOWPRI,         1,      {IRES_HDVICP2_ID_LATE_ACQUIRE,  IRES_HDVICP2_ID_ANY}, 0,
HIGHESTPRI,         1,      {IRES_HDVICP2_ID_LATE_ACQUIRE,      
            IRES_HDVICP2_ID_LATE_ACQUIRE}, 0,
LOWPRI,         1,      {IRES_HDVICP2_ID_LATE_ACQUIRE,  IRES_HDVICP2_ID_ANY}, 0,
HIGHESTPRI,         1,      {IRES_HDVICP2_ID_LATE_ACQUIRE,      IRES_HDVICP2_ID_ANY}, 0,
LOWPRI,         1,      {IRES_HDVICP2_ID_ANY,   IRES_HDVICP2_ID_ANY}, 0,
HIGHESTPRI,         2,      {IRES_HDVICP2_ID_ANY,       IRES_HDVICP2_ID_ANY}, 0,
LOWPRI,         1,      {IRES_HDVICP2_ID_ANY,   IRES_HDVICP2_ID_ANY}, 0,
LOWESTPRI,         2,      {IRES_HDVICP2_ID_ANY,        IRES_HDVICP2_ID_ANY}, 1,
LOWPRI,         1,      {IRES_HDVICP2_ID_ANY,   IRES_HDVICP2_ID_ANY}, 0,
LOWESTPRI,         2,      {IRES_HDVICP2_ID_ANY,        IRES_HDVICP2_ID_ANY}, 1,
LOWPRI,         3,      {IRES_HDVICP2_ID_ANY,   IRES_HDVICP2_ID_ANY}, 0,
LOWESTPRI,         1,      {0,          1},   1,
/*
    LOWPRI,              1,      {1,            IRES_HDVICP2_ID_ANY}, 1,
    LOWPRI,              3,      {0,            IRES_HDVICP2_ID_ANY}, 0,
    HIGHESTPRI,              3,      {1,                IRES_HDVICP2_ID_ANY}, 1,
        LOWPRI,                          3,      {1,            IRES_HDVICP2_ID_ANY}, 1
 */
};

static SemThread_Handle done = NULL;  /* Gets posted by last task to finish */

/* Protect DSKT2_createAlg and DSKT2_freeAlg */
static SemThread_Handle mutex = NULL;

/* ARGSUSED - this line tells the compiler to not generate compiler warnings 
 * for unused arguments */ 
/*
 *  ======== smain ========
 */
/* ARGSUSED */
Void smain(UArg arg0, UArg arg1)
{
    SemThread_Params semParams;
    Task_Params      taskParams;
    Task_Handle      tsk;
    Int              i;

    GT_0trace(CURTRACE, GT_ENTER, "smain> Enter \n");

    SemThread_Params_init(&semParams);
    done = SemThread_create(0, &semParams, NULL);

    SemThread_Params_init(&semParams);
    mutex = SemThread_create(1, &semParams, NULL);

    if ((done == NULL) || (mutex == NULL)) {
        GT_0trace(CURTRACE, GT_7CLASS, "smain> Semaphore creation failed\n");

        System_abort("SemThread_create failed \n");
    }

    Task_Params_init(&taskParams);
    /*
     *  Add the following line to have the stack allocated from the external
     *  heap:
     *      taskParams.stackHeap = (IHeap_Handle)EXTMEM_HEAP;
     */

    //taskParams.stackSize = 0x400;

    for (i = 0; i < NUMTASKS; i++) {
        Task_Params_init(&taskParams);
        taskParams.priority = attrsTable[i].priority;

        taskParams.arg0 = i + 1; /* task id */
        taskParams.arg1 = i;     /* index into attrsTable */
        tsk = Task_create((Task_FuncPtr)rmanTask, &taskParams, NULL);

        if (tsk == NULL) {

            GT_1trace(CURTRACE, GT_7CLASS, "smain> Task_create of task "
                    "%d failed\n", i + 1);

            System_abort("Task_create() failed\n"); 
        }
    }

    for (i = 0; i < NUMTASKS; i++) {
        SemThread_pend(done, SemThread_FOREVER, NULL);
    }

    SemThread_delete(&mutex);
    SemThread_delete(&done);

    GT_0trace(CURTRACE, GT_4CLASS, "smain> TEST PASSED \n");

    GT_0trace(CURTRACE, GT_ENTER, "smain> Exit \n");
}

/*
 *  ======== rmanTask ========
 */
Void rmanTask(UArg arg0, UArg arg1)
{
    Int            taskId = (Int)arg0;
    Int            index = (Int)arg1;  /* index into attrsTable */
    IALG_Fxns    * algFxns = (IALG_Fxns *)&DUMALG_TI_IDUMALG;
    IRES_Fxns    * resFxns = &DUMALG_TI_IRES;
    IDUMALG_Handle dumHandle = NULL; 
    IDUMALG_Params params;
    Int            scratchId = attrsTable[index].scratchId;
    Int            yieldFlag = attrsTable[index].yieldFlag;
    Int            priority = attrsTable[index].priority;
    UArg            resourceId = (UArg)(&(attrsTable[index].id));
    Int            i;
    IRES_Status    status;

    GT_1trace(CURTRACE, GT_ENTER, "rmanTask> Task #%d: Enter \n", taskId);

    params.size = sizeof(IDUMALG_Params);

    GT_4trace(CURTRACE, GT_4CLASS, "rmanTask> "
            "Task #%d: ScratchId %d, Priority %d Yield %d\n",taskId, scratchId,
            priority, yieldFlag);

    params.yieldFlag  = yieldFlag;
    params.taskId = taskId; 

    for (i = 0; i < NUM_RESOURCES; i++) {
        params.hdvicp[i] = *((Int *)resourceId + i);
        GT_2trace(CURTRACE, GT_4CLASS, "rmanTask> Task #%d: "
                "Requesting resource %d \n", taskId, (Int)params.hdvicp[i]);
    }

    /*
     * Create an instance of the algorithm using "algFxns" 
     */
    SemThread_pend(mutex, SemThread_FOREVER, NULL);
    dumHandle = (IDUMALG_Handle)DSKT2_createAlg((Int)scratchId, 
            (IALG_Fxns *)algFxns, NULL,(IALG_Params *)&params);

    if (dumHandle == NULL) {
        GT_0trace(CURTRACE, GT_7CLASS, "rmanTask> Alg creation failed\n");
        System_abort("DSKT2_createAlg() failed, aborting...\n");
    } 

    SemThread_post(mutex, NULL);

    /* Assign resources to the algorithm */
    status = RMAN_assignResources((IALG_Handle)dumHandle, resFxns, scratchId);
    if (status != IRES_OK) {
        GT_1trace(CURTRACE, GT_7CLASS,
                "rmanTask>  Assign resource failed [%d]\n", status);
        printf("Task #%d:", arg0);
        System_abort("%d: RMAN_assignResources() failed, aborting...\n");
    }

    GT_1trace(CURTRACE, GT_4CLASS,
                "rmanTask> Task #%d: Activating \n", arg0);

    /* Activate the Algorithm */
    DSKT2_activateAlg(scratchId, (IALG_Handle)dumHandle);

    GT_1trace(CURTRACE, GT_4CLASS,
                "rmanTask> Task #%d: Activated \n", arg0);

    /* Activate All Resources */
    RMAN_activateAllResources((IALG_Handle)dumHandle, resFxns, scratchId);

    /* Change priority of task2 to a lower priority to test late acquire/yield*/
    if (taskId == 2) {

        GT_2trace(CURTRACE, GT_4CLASS,
                "rmanTask> Task #%d: Changing priority to %d\n", arg0, LOWPRI);

        Task_setPri(Task_self(), LOWPRI);
    }

    /* Use IALG interfaces to do something */
        dumHandle->fxns->useHDVICP(dumHandle, taskId, scratchId);
    
    /* Deactivate All Resources */
    RMAN_deactivateAllResources((IALG_Handle)dumHandle, resFxns, scratchId);

    /* Deactivate algorithm */
    DSKT2_deactivateAlg(scratchId, (IALG_Handle)dumHandle);

    /* Free resources assigned to this algorihtm */
    status = RMAN_freeResources((IALG_Handle)(dumHandle), resFxns, scratchId);
    if (status != IRES_OK) {
        GT_1trace(CURTRACE, GT_7CLASS,
                "rmanTask> Free resource failed [%d]\n", status);
        System_abort("RMAN_freeResources() failed, aborting...\n");
    }

    /*
     * Free instance of the algorithm created
     */
    SemThread_pend(mutex, SemThread_FOREVER, NULL);
    DSKT2_freeAlg(scratchId, (IALG_Handle)dumHandle);
    SemThread_post(mutex, NULL);

    SemThread_post(done, NULL);

    GT_0trace(CURTRACE, GT_ENTER, "rmanTask> Exit \n");
}

/*
 *  ======== myIdle ========
 *  Idle task can do the cleanup ? 
 */
Void myIdle()
{
    IRES_Status status ;

    GT_0trace(CURTRACE, GT_ENTER, "myIdle> Enter \n");

    /* Unregister the protocol */
    status = RMAN_unregister(&IRESMAN_HDVICP);
    if (status != IRES_OK) {
        GT_1trace(CURTRACE, GT_7CLASS,
                "myIdle> Unregister protocol failed [%d]\n", status);
        System_abort("RMAN_unregister failed, aborting...\n");
    }

    status = RMAN_exit();
    if (IRES_OK != status) {
        GT_0trace(CURTRACE, GT_7CLASS, "myIdle> RMAN exit failed \n");

        System_abort("RMAN_exit() failed, aborting...\n");
    }

    GT_0trace(CURTRACE, GT_ENTER, "myIdle> Exit \n");
}


IRES_Status getIVAHD(Int *Id, IALG_Handle alg, IRES_HDVICP2_Handle handle)
{
    /* return IVAHDs using a round robin counter and a busy array */
    int count;
    int i = rrcounter; 


    if ((*Id == IRES_HDVICP2_ID_ANY) || (*Id == IRES_HDVICP2_ID_LATE_ACQUIRE)) {
    
        for (count = 0 ; count < NUMIVAHD; count++) {
            i = i%3;
            if (!(busyStatus[i])) {
                busyStatus[i] = 1;
                *Id = i;
                rrcounter = ((i+1)%NUMIVAHD); 
                return (IRES_OK); 
            } 
            i++;
        }
        return (IRES_EFAIL); 
    }
    else {
        GT_assert(CURTRACE, ((*Id < 3) && (*Id >= 0)));
        if (!(busyStatus[*Id])) {
            busyStatus[*Id] = 1;
            return (IRES_OK); 
        }
        else {
            return (IRES_EFAIL); 
        }
    }
}


IRES_Status freeIVAHD(Int Id, IALG_Handle alg, IRES_HDVICP2_Handle handle)
{
    if (busyStatus[Id]) {
        busyStatus[Id] = 0;
        rrcounter = Id;
        return (IRES_OK);
    } 
    else {
        return (IRES_EFAIL); 
    }
}



/*
 *  @(#) ti.sdo.fc.rman.examples.plugin; 1, 0, 0,4; 2-22-2012 18:08:04; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

