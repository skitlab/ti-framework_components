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
 *  @file       ti/sdo/fc/rman/examples/hdvicp/appLinux.c
 *
 *  @brief      Test app for HDVICP-requesting algorithms
 *
 */
#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>

#include <ti/sdo/fc/rman/rman.h>
#include <ti/sdo/fc/ires/hdvicp/iresman_hdvicp.h>
#include <ti/sdo/fc/ires/hdvicp/ires_hdvicp.h>

#include <stdio.h>
#include <stdlib.h>

#include <ti/sdo/fc/utils/api/alg.h>     /* local ALG implementation for scratch support */
#include "ires_algorithm.h"



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

/* heapId in which to create the tasks */
//extern Int EXTMEM_HEAP;

extern Int smain(Int argc, Char * argv[]);
extern Int rmanTask(Int argc, Char * argv[]);
extern Void myIdle();

/* Scratch task parameters */
static ScratchTskAttrs attrsTable[MAXTASKS] = {
    /* priority,  scratchGroup  resources                       yieldFlag */
    {12,        1,      {IRES_HDVICP_ID_0,      IRES_HDVICP_ID_1},   1},
    {13,        1,      {IRES_HDVICP_ID_ANY,    IRES_HDVICP_ID_ANY}, 0},
    {13,        1,      {IRES_HDVICP_ID_ANY,    IRES_HDVICP_ID_ANY}, 0},
    {13,        1,      {IRES_HDVICP_ID_ANY,    IRES_HDVICP_ID_ANY}, 0},
    {13,        1,      {IRES_HDVICP_ID_ANY,    IRES_HDVICP_ID_ANY}, 0},
    {13,        1,      {IRES_HDVICP_ID_ANY,    IRES_HDVICP_ID_ANY}, 0},
    {13,        1,      {IRES_HDVICP_ID_ANY,    IRES_HDVICP_ID_ANY}, 0},
    {12,        1,      {IRES_HDVICP_ID_ANY,    IRES_HDVICP_ID_ANY}, 1},
    {13,        1,      {IRES_HDVICP_ID_ANY,    IRES_HDVICP_ID_ANY}, 0},
    {12,        1,      {IRES_HDVICP_ID_ANY,    IRES_HDVICP_ID_ANY}, 1},
    {13,        1,      {IRES_HDVICP_ID_ANY,    IRES_HDVICP_ID_ANY}, 0},
    {12,        1,      {IRES_HDVICP_ID_0,      IRES_HDVICP_ID_1},   1},
/*
    {13,        1,      {IRES_HDVICP_ID_1,      IRES_HDVICP_ID_ANY}, 1},
    {13,        3,      {IRES_HDVICP_ID_0,      IRES_HDVICP_ID_ANY}, 0},
    {14,        3,      {IRES_HDVICP_ID_1,      IRES_HDVICP_ID_ANY}, 1},
    {13,        3,      {IRES_HDVICP_ID_1,      IRES_HDVICP_ID_ANY}, 1}
 */
};

/*
 * extern declaration
 */
extern Int smain(Int argc, Char * argv[]);

/*
 * Idle task can do the cleanup ?
 */
Void myIdle()
{
    IRES_Status status ;

    Log_print0(Diags_ENTRY, "[+E] _myIdle> Enter ");
    /*
     * Unregister the protocol
     */
    if (IRES_OK != RMAN_unregister(&IRESMAN_HDVICP)) {
        Log_print0(Diags_USER7, "[+7] _myIdle> Unregister protocol failed ");

        exit(-1);
    }


    status = RMAN_exit();
    if (IRES_OK != status) {

        Log_print0(Diags_USER7, "[+7] _myIdle> RMAN exit failed ");

        exit(-1);
    }

    Log_print0(Diags_EXIT, "[+X] _myIdle> Exit ");

    exit(0);
}


/* ARGSUSED */
Int rmanTask(Int argc, Char * argv[])
{
    Int i;
    IALG_Fxns * algFxns = (IALG_Fxns *)&DUMALG_TI_IDUMALG;
    IRES_Fxns * resFxns = &DUMALG_TI_IRES;
    IDUMALG_Handle dumHandle = NULL;
    IDUMALG_Params params;
    Int taskId = 1;
    Int scratchId = -1;

    Log_print0(Diags_ENTRY, "[+E] _rmanTask> Enter");

    params.size = sizeof(IDUMALG_Params);

    params.yieldFlag  = FALSE;
    params.taskId = taskId;

    /* Configure the params to indicate the HDVICP requirements of each alg */
    for (i = 0; i < NUM_RESOURCES; i++) {
        params.hdvicp[i] = *((IRES_HDVICP_RequestType *)&attrsTable[0].id[i]);
        Log_print1(Diags_USER4, "[+4] _rmanTask> "
                "Requesting resource %d (2 => ANY)",
                (IArg)((Int)params.hdvicp[i]));
    }

    ALG_init();

    /* Create an instance of the algorithm using "algFxns" */
    dumHandle = (IDUMALG_Handle)ALG_create((IALG_Fxns *)algFxns,
            (IALG_Handle)NULL, (IALG_Params *)&params);
    if (dumHandle == NULL) {
        Log_print0(Diags_USER7, "[+7] _rmanTask> Alg creation failed");
        return -1;
    }

    /* Assign resources to the algorithm */
    if (IRES_OK != RMAN_assignResources((IALG_Handle)dumHandle,
                resFxns, scratchId)) {
        Log_print0(Diags_USER7, "[+7] _rmanTask> Assign resource failed");
        return -1;
    }


    /* Activate the Algorithm */
    ALG_activate((IALG_Handle)dumHandle);

    /* Activate All Resources */
    RMAN_activateAllResources((IALG_Handle)dumHandle, resFxns, scratchId);

    /* Use IALG interfaces to do something */
    dumHandle->fxns->useHDVICP(dumHandle, taskId);

    /* Deactivate All Resources */
    RMAN_deactivateAllResources((IALG_Handle)dumHandle, resFxns, scratchId);

    /* Deactivate the algorithm */
    ALG_deactivate((IALG_Handle)dumHandle);

    /* Free resources assigned to this algorithm */
    if (IRES_OK != RMAN_freeResources((IALG_Handle)(dumHandle),
                resFxns, scratchId)) {
        Log_print0(Diags_USER7, "[+7] _rmanTask> Free resource failed");
        return -1;
    }

    /* Free instance of the algorithm created */
    ALG_delete((IALG_Handle)dumHandle);

    Log_print0(Diags_EXIT, "[+X] _rmanTask> Exit ");

    return 0;
}
/*
 *  @(#) ti.sdo.fc.rman.examples.hdvicp; 1, 0, 0,4; 2-22-2012 18:07:39; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

