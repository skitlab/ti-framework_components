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
 * ======== app.c ========
 */

#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>

#include <ti/sdo/fc/utils/api/alg.h>
#include <ti/sdo/fc/ires/iresman.h>
#include <ti/sdo/fc/rman/rman.h>
#include <ti/sdo/fc/ires/sdma/iresman_sdma.h>
#include <ti/sdo/fc/ires/sdma/ires_sdma.h>

#include <ti/sdo/fc/global/FCSettings.h>

#include <stdio.h>
#include <stdlib.h>

#include "ires_algorithm.h"


#define NUMTASKS 12
#define MAXTASKS 12

/*
 * Tasks
 */
extern Int rmanTask(Int argc, Char * argv[]);
extern Void myIdle();

/*
 * extern declaration
 */
extern Int smain(Int argc, Char * argv[]);

IRESMAN_Params configParams = {
    0,      /* Size of this structure */
    NULL,   /* RMAN_PERSISTENTALLOCFXN */
    NULL,   /* RMAN_PERSISTENTFREEFXN */
};
IDUMALG_Params params;


/*
 *  ======== main ========
 */
Int main(Int argc, String argv[])
{
    IRES_Status status;
    Int size = 0;

    /* Enable logging of FC modules by default */
    FCSettings_init();
    Diags_setMask(FCSETTINGS_MODNAME"+EX1234567");

    Diags_setMask("xdc.runtime.Main+EX1234567");

    Log_print0(Diags_ENTRY, "[+E] _main> Enter ");

    status = RMAN_init();
    if (IRES_OK != status) {
        Log_print0(Diags_USER7, "[+7] _main> RMAN Initialization failed ");
        return -1;
    }

    /*
     * Supply initialization information for the RESMAN while registering
     */
    size = sizeof(IRESMAN_Params);

    configParams.allocFxn = RMAN_PARAMS.allocFxn;
    configParams.freeFxn = RMAN_PARAMS.freeFxn;
    configParams.size = size;

    /*
     *  Register the SDMA protocol/resource manager with the  generic
     *  resource manager
     */
    status = RMAN_register(&IRESMAN_SDMA, (IRESMAN_Params *)&configParams);

    if (IRES_OK != status) {
        Log_print0(Diags_USER7, "[+7] _main> Protocol Initialization failed ");
        return -1;
    }


    Log_print0(Diags_EXIT, "[+X] _main> Exit ");

    return (rmanTask(argc, argv));
}
#if 0
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
    if (IRES_OK != RMAN_unregister(&IRESMAN_SDMA)) {

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
#endif

/*
 *  ======== rmanTask ========
 */
/* ARGSUSED */
Int rmanTask(Int argc, Char * argv[])
{
    Int scratchId = -1;
    Int priority = 2;
    Int taskId = 1;
    Int yieldFlag = FALSE;

    IALG_Fxns * algFxns = &DUMALG_TI_IALG;
    IRES_Fxns * resFxns = &DUMALG_TI_IRES;
    IDUMALG_Handle dumHandle = NULL;

    Log_print0(Diags_ENTRY, "[+E] _rmanTask> Enter ");

    params.size = sizeof(IDUMALG_Params);

    Log_print4(Diags_USER4, "[+4] _rmanTask> "
            "Task #%d: ScratchId %d, Priority %d Yield %d",
            (IArg)taskId, (IArg)scratchId, (IArg)priority, (IArg)yieldFlag);

    params.yieldFlag  = yieldFlag;
    params.taskId = taskId;

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
        (DUMALG_TI_IDUMALG).useSDMA(dumHandle, taskId);

    /* Deactivate All Resources */
    RMAN_deactivateAllResources((IALG_Handle)dumHandle, resFxns, scratchId);

    /* Deactivate algorithm */
    ALG_deactivate((IALG_Handle)dumHandle);

    /* Free resources assigned to this algorihtm */
    if (IRES_OK != RMAN_freeResources((IALG_Handle)(dumHandle),
                resFxns, scratchId)) {
        Log_print0(Diags_USER7, "[+7] _rmanTask> Free resource failed");
        return -1;
    }

    /* Free instance of the algorithm created */
    ALG_delete((IALG_Handle)dumHandle);

    ALG_exit();

    Log_print0(Diags_EXIT, "[+X] _rmanTask> Exit ");

    return (0);
}
/*
 *  @(#) ti.sdo.fc.rman.examples.sdma; 1, 0, 0,4; 2-22-2012 18:08:08; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

