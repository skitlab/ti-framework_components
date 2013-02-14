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

#include <ti/sysbios/knl/Task.h>

#include <ti/sdo/fc/dskt2/dskt2.h>

#include <ti/sdo/fc/rman/rman.h>
#include <ti/sdo/fc/ires/hdvicp/iresman_hdvicp.h>
#include <ti/sdo/fc/ires/hdvicp/ires_hdvicp.h>

#include <stdlib.h>

#include "ires_algorithm.h"


#define CURTRACE ti_sdo_fc_rman_examples_hdvicp

#define NUMTASKS 12
#define MAXTASKS 12
#define MODNAME "ti.sdo.fc.rman.examples.hdvicp"

/*
 *  ======== ScratchTskAttrs ========
 */
typedef struct ScratchTskAttrs {
    Int         priority;       /* Priority of task */
    Int         scratchId;      /* Scratch group in which to create the task */
    IRES_HDVICP_RequestType id[NUM_RESOURCES];
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

/* Scratch task parameters */
static ScratchTskAttrs attrsTable[MAXTASKS] = {
    /* priority,    scratchGroup    resources                       yieldFlag */
    12,              1,      {IRES_HDVICP_ID_0,     IRES_HDVICP_ID_1},   1,
    13,              1,      {IRES_HDVICP_ID_ANY,   IRES_HDVICP_ID_ANY}, 0,
    13,              1,      {IRES_HDVICP_ID_ANY,   IRES_HDVICP_ID_ANY}, 0,
    13,              1,      {IRES_HDVICP_ID_ANY,   IRES_HDVICP_ID_ANY}, 0,
    13,              1,      {IRES_HDVICP_ID_ANY,   IRES_HDVICP_ID_ANY}, 0,
    13,              1,      {IRES_HDVICP_ID_ANY,   IRES_HDVICP_ID_ANY}, 0,
    13,              1,      {IRES_HDVICP_ID_ANY,   IRES_HDVICP_ID_ANY}, 0,
    12,              1,      {IRES_HDVICP_ID_ANY,   IRES_HDVICP_ID_ANY}, 1,
    13,              1,      {IRES_HDVICP_ID_ANY,   IRES_HDVICP_ID_ANY}, 0,
    12,              1,      {IRES_HDVICP_ID_ANY,   IRES_HDVICP_ID_ANY}, 1,
    13,              1,      {IRES_HDVICP_ID_ANY,   IRES_HDVICP_ID_ANY}, 0,
    12,              1,      {IRES_HDVICP_ID_0,     IRES_HDVICP_ID_1},   1,
/*
  13,              1,      {IRES_HDVICP_ID_1,       IRES_HDVICP_ID_ANY}, 1,
  13,              3,      {IRES_HDVICP_ID_0,       IRES_HDVICP_ID_ANY}, 0,
  14,              3,      {IRES_HDVICP_ID_1,       IRES_HDVICP_ID_ANY}, 1,
  13,                3,      {IRES_HDVICP_ID_1,     IRES_HDVICP_ID_ANY}, 1
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

    Log_print0(Diags_ENTRY, "[+E] smain> Enter ");

    SemThread_Params_init(&semParams);
    done = SemThread_create(0, &semParams, NULL);

    SemThread_Params_init(&semParams);
    mutex = SemThread_create(1, &semParams, NULL);

    if ((done == NULL) || (mutex == NULL)) {
        Log_print0(Diags_USER7, "[+7] smain> SemThread creation failed");

        System_abort("SemThread_create failed \n");
    }

    Task_Params_init(&taskParams);
    /*
     *  Add the following line to have the stack allocated from the external
     *  heap:
     *      taskParams.stackHeap = (IHeap_Handle)EXTMEM_HEAP;
     */

    taskParams.stackSize = 0x1000;

    for (i = 0; i < NUMTASKS; i++) {
        Task_Params_init(&taskParams);
        taskParams.priority = attrsTable[i].priority;

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

    SemThread_delete(&mutex);
    SemThread_delete(&done);

    Log_print0(Diags_USER4, "[+4] smain> TEST PASSED ");

    Log_print0(Diags_EXIT, "[+X] smain> Exit ");
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
    Arg            resourceId = (Arg)(&(attrsTable[index].id));
    Int            i;
    IRES_Status    status;

    Log_print0(Diags_ENTRY, "[+E] rmanTask> Enter ");

    params.size = sizeof(IDUMALG_Params);

    Log_print4(Diags_USER4, "[+4] rmanTask> "
            "Task #%d: ScratchId %d, Priority %d Yield %d",
            (IArg)taskId, (IArg)scratchId, (IArg)priority, (IArg)yieldFlag);

    params.yieldFlag  = yieldFlag;
    params.taskId = taskId;

    for (i = 0; i < NUM_RESOURCES; i++) {
        params.hdvicp[i] = *((IRES_HDVICP_RequestType *)resourceId + i);
        Log_print1(Diags_USER4, "[+4] rmanTask> "
                "Requesting resource %d (2 => ANY)",
                (IArg)((Int)params.hdvicp[i]));
    }

    /*
     * Create an instance of the algorithm using "algFxns"
     */
    SemThread_pend(mutex, SemThread_FOREVER, NULL);
    dumHandle = (IDUMALG_Handle)DSKT2_createAlg((Int)scratchId,
            (IALG_Fxns *)algFxns, NULL,(IALG_Params *)&params);

    if (dumHandle == NULL) {
        Log_print0(Diags_USER7, "[+7] rmanTask> Alg creation failed");
        System_abort("DSKT2_createAlg() failed, aborting...\n");
    }

    SemThread_post(mutex, NULL);

    /* Assign resources to the algorithm */
    status = RMAN_assignResources((IALG_Handle)dumHandle, resFxns, scratchId);
    if (status != IRES_OK) {
        Log_print1(Diags_USER7, "[+7] rmanTask> Assign resource failed [%d]",
                (IArg)status);
        System_abort("RMAN_assignResources() failed, aborting...\n");
    }


    /* Activate the Algorithm */
    DSKT2_activateAlg(scratchId, (IALG_Handle)dumHandle);

    /* Activate All Resources */
    RMAN_activateAllResources((IALG_Handle)dumHandle, resFxns, scratchId);

    /* Use IALG interfaces to do something */
    dumHandle->fxns->useHDVICP(dumHandle, taskId);

    /* Deactivate All Resources */
    RMAN_deactivateAllResources((IALG_Handle)dumHandle, resFxns, scratchId);

    /* Deactivate algorithm */
    DSKT2_deactivateAlg(scratchId, (IALG_Handle)dumHandle);

    /* Free resources assigned to this algorihtm */
    status = RMAN_freeResources((IALG_Handle)(dumHandle), resFxns, scratchId);
    if (status != IRES_OK) {
        Log_print1(Diags_USER7, "[+7] rmanTask> Free resource failed [%d]",
                (IArg)status);
        System_abort("RMAN_freeResources() failed, aborting...\n");
    }

    /*
     * Free instance of the algorithm created
     */
    SemThread_pend(mutex, SemThread_FOREVER, NULL);
    DSKT2_freeAlg(scratchId, (IALG_Handle)dumHandle);
    SemThread_post(mutex, NULL);

    SemThread_post(done, NULL);

    Log_print0(Diags_EXIT, "[+X] rmanTask> Exit ");
}

/*
 *  ======== myIdle ========
 *  Idle task can do the cleanup ?
 */
Void myIdle()
{
    IRES_Status status ;

    Log_print0(Diags_ENTRY, "[+E] myIdle> Enter ");

    /* Unregister the protocol */
    status = RMAN_unregister(&IRESMAN_HDVICP);
    if (status != IRES_OK) {
        Log_print1(Diags_USER7, "[+7] myIdle> Unregister protocol failed [%d]",
                (IArg)status);
        System_abort("RMAN_unregister failed, aborting...\n");
    }

    status = RMAN_exit();
    if (IRES_OK != status) {
        Log_print0(Diags_USER7, "[+7] myIdle> RMAN exit failed ");

        System_abort("RMAN_exit() failed, aborting...\n");
    }

    Log_print0(Diags_EXIT, "[+X] myIdle> Exit ");
}

/*
 *  @(#) ti.sdo.fc.rman.examples.hdvicp; 1, 0, 0,4; 2-22-2012 18:07:39; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

