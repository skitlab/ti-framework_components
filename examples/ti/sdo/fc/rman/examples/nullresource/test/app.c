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
#include <stdio.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sdo/fc/dskt2/dskt2.h>

#include <ti/sdo/fc/rman/rman.h>

/* Required for registration of NULLRES protocol */
#include <ti/sdo/fc/ires/nullresource/iresman_nullres.h>

/* Required to create an algorithm of this type */
#include <ti/sdo/fc/ires/examples/codecs/template/template_ti.h>


/*
 * extern declaration
 */
extern Int smain(Int argc, Char * argv[]);


IRESMAN_Params configParams = {
    0,      /* Size of this structure */
    NULL,   /* RMAN_PERSISTENTALLOCFXN */
    NULL    /* RMAN_PERSISTENTFREEFXN */
};

/*
 *  ======== smain ========
 */
/* ARGSUSED - this line tells the compiler to not generate compiler warnings
 * for unused arguments */
Int smain(Int argc, Char * argv[])
{
    IRES_Status status;
    Int size = 0;
    Int scratchId = 2;
    IALG_Fxns * algFxns = (IALG_Fxns *)&TEMPLATE_TI_CODECIRES;
    IRES_Fxns * resFxns = &TEMPLATE_TI_IRES;
    IALG_Handle dumHandle = NULL;
    ITEMPLATE_Status algStatus;

    /*
     * Create an instance of the algorithm using "algFxns"
     */
    dumHandle = DSKT2_createAlg(scratchId, (IALG_Fxns *)algFxns, NULL,
            (IALG_Params *)NULL);

    if (dumHandle == NULL) {
        printf("Alg creation failed \n");
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
     *  Register the NULL protocol/resource manager with the generic resource
     *  manager
     */
    status = RMAN_register(&IRESMAN_NULLRES, (IRESMAN_Params *)&configParams);

    if (IRES_EEXISTS == status) {
        printf("Protocol Already Registered\n");
    }

    /* Create an instance of an algorithm that implements IALG and IRES_Fxns */
    if (IRES_OK != RMAN_assignResources((IALG_Handle)dumHandle,
                resFxns,scratchId)) {
        printf("Assign Resource Failed \n");
        return (-1);
    }

    /* Activate the Algorithm */
    DSKT2_activateAlg(scratchId, (IALG_Handle)dumHandle);

    /* Activate All Resources */
    RMAN_activateAllResources((IALG_Handle)dumHandle, resFxns, -1);

    /* Use IALG interfaces to do something */
    ((ITEMPLATE_Handle)dumHandle)->fxns->process((ITEMPLATE_Handle)dumHandle,
            (ITEMPLATE_InArgs *)NULL, (ITEMPLATE_OutArgs *)NULL);

    ((ITEMPLATE_Handle)dumHandle)->fxns->control((ITEMPLATE_Handle)dumHandle,
            (ITEMPLATE_Cmd )0, (ITEMPLATE_DynamicParams *)NULL, &algStatus);

    /* Deactivate All Resources */
    RMAN_deactivateAllResources((IALG_Handle)dumHandle, resFxns, -1);

    /* Deactivate algorithm */
    DSKT2_deactivateAlg(scratchId, (IALG_Handle)dumHandle);

    /* Free resources assigned to this algorihtm */
    if (IRES_OK != RMAN_freeResources((IALG_Handle)(dumHandle),
                resFxns, -1)) {
        printf("Free Resource Failed\n");
        return (-1);
    }

    /* Free instance of the algorithm created */
    DSKT2_freeAlg(scratchId, (IALG_Handle)dumHandle);

    /* Unregister the protocol */
    if (IRES_OK != RMAN_unregister(&IRESMAN_NULLRES)) {
        printf("Unregister Protocol Failed\n");
        return (-1);
    }

    RMAN_exit();

    return (0);
}
/*
 *  @(#) ti.sdo.fc.rman.examples.nullresource.test; 1, 0, 0,4; 2-22-2012 18:08:07; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

