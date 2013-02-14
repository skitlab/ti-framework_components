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
 *  ======== app.dm6446.c ========
 */

/* FOR DM6446 */
#include <xdc/std.h>
#include <ti/sdo/fc/rman/RMAN.h>
#include <ti/sdo/fc/dskt2/dskt2.h>
#include <ti/sdo/fc/ires/iresman.h>
#include <ti/sdo/fc/ires/edma3Chan/iresman_edma3Chan.h>
#include <ti/sdo/fc/ires/edma3Chan/ires_edma3Chan.h>
#include <ires_algorithm.h>
#include <stdio.h>

#include <ti/sdo/utils/trace/gt.h>
/* #define MOD_NAME "ti.sdo.fc.rman"*/
#define MOD_NAME "*"


/*
 * extern declaration
 */
extern Int smain(Int argc, Char * argv[]);


/*
 * global declarations
 */
IRESMAN_Edma3ChanParams configParams = {

    /*
     * The base IRESMAN configuration information
     */
    0,

    /*
    RMAN_PERSISTENTALLOCFXN,
    RMAN_PERSISTENTFREEFXN,
    */
    NULL,
    NULL,

};

EDMA3_RM_InstanceInitConfig resmanEdma3InstanceInit;

EDMA3_RM_GblErrCallbackParams callback = {
    (EDMA3_RM_GblErrCallback)NULL,
    NULL
};

void main()
{
/*     GT_set(MOD_NAME "=234567");*/
    GT_set("*" "=01234567");
}

/* ARGSUSED - this line tells the compiler to not generate compiler warnings
 * for unused arguments */
Int smain(Int argc, Char * argv[])
{

    IRES_Status status;
    Int size = 0;
    Int scratchId = 1;
    IALG_Status algStatus;
    IALG_Fxns * algFxns = &DUMRES_TI_IALG;
    IRES_Fxns * resFxns = &DUMRES_TI_IRES;
    DUMRES_TI_Handle dumHandle = NULL;


    status = RMAN_init();
    if (IRES_OK != status) {
        printf("RMAN initialization Failed \n");
        return -1;
    }

    /*
     * Create an instance of the algorithm using "algFxns"
     */
    dumHandle = (DUMRES_TI_Handle)DSKT2_createAlg(scratchId,
            (IALG_Fxns *)algFxns, NULL,(IALG_Params *)NULL);
    if (dumHandle == NULL) {
        printf("Alg creation failed \n");
        return -1;
    }

    /*
     * Supply initialization information for the EDMA3 RESMAN while registering
     */
    size = sizeof(IRESMAN_Edma3ChanParams);

    configParams.baseConfig.allocFxn = RMAN_PARAMS.allocFxn;
    configParams.baseConfig.freeFxn = RMAN_PARAMS.freeFxn;
    configParams.baseConfig.size = size;

    /* Register the EDMA3 Linked transfer protocol/resource manager with the
     * generic resource manager */

    status = RMAN_register(&IRESMAN_EDMA3CHAN, (IRESMAN_Params *)&configParams);

    if (IRES_OK != status) {
        printf("Protocol Registration Failed \n");
        return -1;
    }

    /* Create an instance of an algorithm that implements IALG and IRES_Fxns */
    if (IRES_OK != RMAN_assignResources((IALG_Handle)dumHandle,
                resFxns,-1)) {
        printf("Assign Resource Failed \n");
        return -1;
    }


    /*
     * Activate the Algorithm
     */
    DSKT2_activateAlg(scratchId, (IALG_Handle)dumHandle);

    /*
     * Activate All Resources
     */
    RMAN_activateAllResources((IALG_Handle)dumHandle, resFxns, -1);

    /*
     * Use IALG interfaces to do something
     */
    DSKT2_controlAlg((IALG_Handle)dumHandle, (IALG_Cmd)NULL, &algStatus);

    /*
     * Deactivate All Resources
     */
    RMAN_deactivateAllResources((IALG_Handle)dumHandle, resFxns, -1);

    /*
     * Deactivate algorithm
     */
    DSKT2_deactivateAlg(scratchId, (IALG_Handle)dumHandle);

    /*
     * Free resources assigned to this algorihtm
     */
    if (IRES_OK != RMAN_freeResources((IALG_Handle)(dumHandle),
                resFxns, -1)) {
        printf("Free Resource Failed \n");
        return -1;
    }

    /*
     * Free instance of the algorithm created
     */
    DSKT2_freeAlg(scratchId, (IALG_Handle)dumHandle);

    /*
     * Unregister the protocol
     */
    if (IRES_OK != RMAN_unregister(&IRESMAN_EDMA3CHAN)) {
            printf("Unregister Protocol Failed \n");
            return -1;
    }

    RMAN_exit();

    return 0;
}
/*
 *  @(#) ti.sdo.fc.rman.examples.dummyEdma3; 1, 0, 0,4; 2-22-2012 18:07:43; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

