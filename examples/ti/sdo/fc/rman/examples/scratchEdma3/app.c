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
#include <xdc/std.h>
#include <xdc/runtime/System.h>

#include <ti/sdo/fc/rman/rman.h>
#include <ti/sdo/fc/dskt2/dskt2.h>

#include <ti/sdo/fc/ires/iresman.h>
#include <ti/sdo/fc/ires/edma3chan/iresman_edma3Chan.h>
#include <ti/sdo/fc/ires/edma3chan/ires_edma3Chan.h>

#include <ti/sdo/fc/edma3/edma3_config.h>
#include <ti/sdo/edma3/rm/edma3_rm.h>

#include <ti/sdo/utils/trace/gt.h>

#include "ires_algorithm.h"
#if 0
#include "memutils.h"  /* For checking for memory leaks */
#endif

#define CURTRACE ti_sdo_fc_rman_examples_scratchEdma3_GTMask


/*
 * extern declaration
 */
extern Void smain(UArg arg0, UArg arg1);

/*
 *  ======== smain ========
 */
/* ARGSUSED - this line tells the compiler to not generate compiler warnings
 * for unused arguments */
Void smain(UArg arg0, UArg arg1)
{
    Int                scratchId1 = 0;
    Int                scratchId2 = 0;
    IALG_Status        algStatus;
    IALG_Fxns        * algFxns = &DUMRES_TI_IALG;
    IRES_Fxns        * resFxns = &DUMRES_TI_IRES;
    IRES_Status        status;
    DUMRES_TI_Handle   alg1 = NULL;
    DUMRES_TI_Handle   alg2 = NULL;
    EDMA3_Handle    rmHandle = NULL;
    EDMA3_ResDesc   resObj;


    System_printf("smain> App started...\n");

    /* Create 2 instances of the algorithm using "algFxns" */
    alg1 = (DUMRES_TI_Handle)DSKT2_createAlg(scratchId1,
            (IALG_Fxns *)algFxns, NULL,(IALG_Params *)NULL);

    if (alg1 == NULL) {
        System_abort("Alg creation failed for alg 1, aborting...\n");
    }

    alg2 = (DUMRES_TI_Handle)DSKT2_createAlg(scratchId2,
            (IALG_Fxns *)algFxns, NULL,(IALG_Params *)NULL);

    if (alg2 == NULL) {
        System_abort("Alg creation failed for alg 2, aborting...\n");
    }
    else {
        System_printf("Alg creation succeeded\n");
    }

    /* Assign resources to the algorithm */
    status = RMAN_assignResources((IALG_Handle)alg1, resFxns, scratchId1);
    if (status != IRES_OK) {
        System_printf("Assign Resource Failed\n");
        goto AppEnd1; /* Inconsistent with alg 2 failure */
    }
    else {
        System_printf("RMAN_assignResources() for alg1 succeeded\n");
    }

    /* Activate alg 1 */
    DSKT2_activateAlg(scratchId1, (IALG_Handle)alg1);

    /* Activate All Resources for alg 1 */
    RMAN_activateAllResources((IALG_Handle)alg1, resFxns, scratchId1);

    /* Use IALG interfaces to do something for alg 1 */
    DSKT2_controlAlg((IALG_Handle)alg1, (IALG_Cmd)NULL, &algStatus);

    /* Assign resources to alg 2 */
    status = RMAN_assignResources((IALG_Handle)alg2, resFxns, scratchId2);
    if (status != IRES_OK) {
        System_printf("Assign Resource Failed [%d]\n", status);
        System_abort("Aborting...\n"); /* Inconsistent with alg 1 failure */
    }
    else {
        System_printf("RMAN_assignResources() for alg2 succeeded\n");
    }

    /* Deactivate All Resources of alg 1 */
    RMAN_deactivateAllResources((IALG_Handle)alg1, resFxns, scratchId1);

    /* Deactivate alg 1 */
    DSKT2_deactivateAlg(scratchId1, (IALG_Handle)alg1);

    /* Activate alg 2 */
    DSKT2_activateAlg(scratchId2, (IALG_Handle)alg2);

    /* Activate All Resources for alg 2 */
    RMAN_activateAllResources((IALG_Handle)alg2, resFxns, scratchId2);

    /* Free resources assigned to alg 1 */
    status = RMAN_freeResources((IALG_Handle)(alg1), resFxns, scratchId1);
    if (status != IRES_OK) {
        System_printf("Free Resource Failed [%d]\n", status);
        System_abort("Aborting...\n");
    }

    /* Acquire the EDMA3 handle first */           
    rmHandle = EDMA3_getResourceManager(NULL, -1);

    if (NULL == rmHandle) {
        System_abort("Error obtaining SYSTEM resource Manager Handle \n");
    }
    else {
        System_printf("EDMA3_getResourceManager() succeeded\n");
    }

    resObj.resId = 151;
    resObj.type = EDMA3_RES_PARAM_SET;


    if (EDMA3_SOK != EDMA3_allocResource(rmHandle, &resObj)) {
        System_printf("Could not allocate this resource, as it is already "
                "owned by the algorithm\n");
    }

    resObj.resId = 256;
    if (EDMA3_SOK != EDMA3_allocResource(rmHandle, &resObj)) {
        System_printf("Error, could not allocate resource %d\n"
                "ERROR for 6467, OK for 6446\n", resObj.resId);
    }

    if (EDMA3_SOK != EDMA3_releaseResourceManager(NULL, -1)) {
        System_printf("Error releasing system resource manager handle\n");
    }

    /* Deactivate All Resources for alg 2 */
    RMAN_deactivateAllResources((IALG_Handle)alg2, resFxns, scratchId2);

    /* Deactivate alg 2 */
    DSKT2_deactivateAlg(scratchId2, (IALG_Handle)alg2);

    /* Free resources assigned to this alg 2 */
    status = RMAN_freeResources((IALG_Handle)(alg2), resFxns, scratchId2);
    if (status != IRES_OK) {
        System_printf("Free Resource Failed [%d]\n", status);
        System_abort("Aborting...\n");
    }

AppEnd1:
    /* Free algorithm instances */
    DSKT2_freeAlg(scratchId1, (IALG_Handle)alg1);
    DSKT2_freeAlg(scratchId2, (IALG_Handle)alg2);

    /*
     * Unregister the protocol
     */
    status = RMAN_unregister(&IRESMAN_EDMA3CHAN);
    if (status != IRES_OK) {
        System_printf("Unregister Protocol Failed [%d]\n");
        System_abort("Aborting...\n");
    }

#if 0
    if (!MemUtils_checkMem()) {
        System_printf("Memory leak detected\n");
    }
#endif

        RMAN_exit();
}
/*
 *  @(#) ti.sdo.fc.rman.examples.scratchEdma3; 1, 0, 0,4; 2-22-2012 18:08:02; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

