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

#include <ti/sdo/fc/rman/rman.h>
#include <ti/sdo/fc/ires/edma3chan/iresman_edma3Chan.h>
#include <ti/sdo/fc/ires/edma3chan/ires_edma3Chan.h>
#include <ti/sdo/fc/edma3/edma3_config.h>
#include <stdio.h>
#include <stdlib.h>

#include <ti/sdo/fc/utils/api/alg.h>
#include "ires_algorithm.h"
#include <ti/sdo/utils/trace/gt.h>
GT_Mask ti_sdo_fc_rman_examples_scratchEdma3_GTMask;
/* #define MOD_NAME "ti.sdo.fc.rman"*/
#define MOD_NAME "*"

/*
 * extern declaration 
 */
extern Int smain(Int argc, Char * argv[]);


/*
 *  ======== smain ========
 */
/* ARGSUSED - this line tells the compiler to not generate compiler warnings 
 * for unused arguments */ 
Int smain(Int argc, String argv[])
{

    Int                scratchId1 = 0;
    Int                scratchId2 = 1;
    IALG_Status        algStatus;
    IALG_Fxns        * algFxns = &DUMRES_TI_IALG;
    IRES_Fxns        * resFxns = &DUMRES_TI_IRES;
    DUMRES_TI_Handle   alg1 = NULL;
    DUMRES_TI_Handle   alg2 = NULL;
    EDMA3_Handle    rmHandle = NULL;
    EDMA3_ResDesc   resObj;
    Bool status = TRUE; 
    IDUMRES_Params params;

    if (argc > 1) {
        scratchId1 = atoi(argv[1]);
    }
 
    if (argc > 2) {
        scratchId2 = atoi(argv[2]);
    }
    ALG_init();
    /*
     * Create an instance of the algorithm using "algFxns" 
     */
    params.algNum = 1;
    alg1 = (DUMRES_TI_Handle)ALG_create((IALG_Fxns *)algFxns,
            (IALG_Handle)NULL, (IALG_Params *)&params);
    if (alg1 == NULL) {
        printf("Alg1 creation failed \n");
        return -1;
    } 

    params.algNum = 2;
    alg2 = (DUMRES_TI_Handle)ALG_create((IALG_Fxns *)algFxns,
            (IALG_Handle)NULL, (IALG_Params *)&params);
    if (alg2 == NULL) {
        printf("Alg2 creation failed \n");
        return -1;
    } 

    /* Create an instance of an algorithm that implements IALG and IRES_Fxns */
    if (IRES_OK != RMAN_assignResources((IALG_Handle)alg1,
                resFxns, scratchId1)) {
        System_printf("Assign Resource Failed\n");
        status = FALSE;
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
    //TODO: DSKT2_controlAlg((IALG_Handle)alg1, (IALG_Cmd)NULL, &algStatus);

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
    ALG_deactivate((IALG_Handle)alg1);

    /* Activate alg 2 */
    ALG_activate((IALG_Handle)alg2);

    /* Activate All Resources for alg 2 */
    RMAN_activateAllResources((IALG_Handle)alg2, resFxns, scratchId2);

    /* Free resources assigned to alg 1 */
    status = RMAN_freeResources((IALG_Handle)(alg1), resFxns, scratchId1);
    if (status != IRES_OK) {
        System_printf("Free Resource Failed [%d]\n", status);
        System_abort("Aborting...\n");
    }

    /* Acquire the EDMA3 handle first */           
    rmHandle = EDMA3_getResourceManager((IALG_Handle)NULL, (Int)-1);
    
    if (NULL == rmHandle) {
        System_abort("Error obtaining SYSTEM resource Manager Handle \n");
    }
    else {
        System_printf("EDMA3_getResourceManager() succeeded\n");
    }

    resObj.resId = 65; 
    resObj.type = EDMA3_RES_PARAM_SET;
    

    if (EDMA3_SOK != EDMA3_allocResource(rmHandle, &resObj)) {
        printf("Note, could not allocate this resource.\n");
    }

    resObj.resId = 126; 
    if (EDMA3_SOK != EDMA3_allocResource(rmHandle, &resObj)) {
        System_printf("Note, could not allocate resource %d\n", resObj.resId);
    }

    if (EDMA3_SOK != EDMA3_releaseResourceManager(NULL, -1)) {
        System_printf("Note, releasing system resource manager handle\n");
    }

    /* Deactivate All Resources for alg 2 */
    RMAN_deactivateAllResources((IALG_Handle)alg2, resFxns, scratchId2);

    /* Deactivate alg 2 */
    ALG_deactivate((IALG_Handle)alg2);

    /* Free resources assigned to this alg 2 */
    status = RMAN_freeResources((IALG_Handle)(alg2), resFxns, scratchId2);
    if (status != IRES_OK) {
        System_printf("Free Resource Failed [%d]\n", status);
        System_abort("Aborting...\n");
    }

AppEnd1:
    /* Free algorithm instances */
    ALG_delete((IALG_Handle)alg1);

    /*
     * Free instance of the algorithm created
     */
    ALG_delete((IALG_Handle)alg2);

    RMAN_exit();

    if (status)
        System_printf("Application exiting normally\n");

    return (0);
}
/*
 *  @(#) ti.sdo.fc.rman.examples.scratchEdma3; 1, 0, 0,4; 2-22-2012 18:08:02; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

