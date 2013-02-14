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
 *  ======== shmbuf_test2.c ========
 *  Test the functionality of the shared memory Buffer Resource Manager. The
 *  buffer is created as sharable, so 2 instances of this program can be run
 *  simultaneously.
 *
 *  This test creates an algorithm and assigns it the shmbuf resource. When
 *  the algorithm is activated, its useBufs() function is called, which writes
 *  the fillValue into the shared buffer resource. The test then sleeps while
 *  the algorithm is still activated (to give another instance a chance to try
 *  to use the resource). When the test wakes up, the alg's checkBufs()
 *  function is called to verify that the buffer still contains the fillValue.
 *  If the DSKT2 semaphores really work, the fillValue should not change when
 *  two algorithms with different fill values are run concurrently.
 *
 *  Usage: shmbuf_test2.x86U [fillValue]
 */

#include <xdc/std.h>
#include <xdc/runtime/System.h>

#include <ti/sdo/fc/ires/iresman.h>
#include <ti/sdo/fc/rman/rman.h>

#include <ti/sdo/fc/dskt2/dskt2.h>

#include <ti/sdo/fc/ires/shmbuf/shmbuf.h>

#include "shmalg_ti.h"
#include "shmbuf_util.h"

#define SHMBUFSIZE 0x400

extern Int smain(Int argc, Char * argv[]);

static Char *getError(IRES_Status err);

/*
 *  ======== smain ========
 */
Int smain(Int argc, Char * argv[])
{
    ISHMALG_Handle     alg;
    ISHMALG_Fxns       fxns = SHMALG_TI_ISHMALG;
    ISHMALG_Params     params = ISHMALG_PARAMS;
    IRES_Fxns          iresFxns = SHMALG_TI_IRES;
    IRES_Status        status;
    Int                scratchId;
    Bool               passed = FALSE;
    Bool               retVal = TRUE;
    Int                fillVal = 1;

    if (argc > 1) {
        fillVal = atoi(argv[1]);
    }
    params.fillVal = fillVal;

    System_printf("shmbuf_test2> Started. buffer fill value: %d\n", fillVal);

    /* Initialize and register resource manager */
    System_printf("Calling RMAN_init()...\n");
    status = RMAN_init();

    if (status != IRES_OK) {
        /* Test failed */
        System_printf("RMAN_init() failed: %s [%d]\n", getError(status),
                status);
        goto done;
    }

    SHMBUF_PARAMS.bufsize = SHMBUFSIZE;
    SHMBUF_PARAMS.isScratch = TRUE;      /* Make the buffer sharable */

    System_printf("Calling RMAN_register()...\n");
    status = RMAN_register(&SHMBUF_MGRFXNS, (IRESMAN_Params *)&SHMBUF_PARAMS);
    if (status != IRES_OK) {
        /* Test failed */
        System_printf("RMAN_register() failed %s [%d]\n", getError(status),
                status);
        goto done;
    }

    scratchId = 1;
    System_printf("Calling DSKT2_createAlg()...\n");
    alg = (ISHMALG_Handle)DSKT2_createAlg(scratchId, (IALG_Fxns *)&fxns,
            NULL, (IALG_Params *)&params);
    if (alg == NULL) {
        System_printf("DSKT2_createAlg() failed\n");
        goto done;
    }

    /* Assign resources to the algorithm */
    System_printf("Calling RMAN_assignResources()...\n");
    status = RMAN_assignResources((IALG_Handle)alg, &iresFxns, scratchId);

    if (status != IRES_OK) {
        System_printf("RMAN_assignResources() failed %s [%d]\n",
                getError(status), status);
        goto done;
    }

    System_printf("Calling DSKT2_activateAlg()...\n");
    DSKT2_activateAlg(scratchId, (IALG_Handle)alg);

    /* Activate All Resources */
    System_printf("Calling RMAN_activateAllResources()...\n");
    status = RMAN_activateAllResources((IALG_Handle)alg, &iresFxns, scratchId);
    if (status != IRES_OK) {
        System_printf("RMAN_activateAllResourceRMAN_unregister(&SHMBUF_MGRFXNS);s() failed %s [%d]\n",
                getError(status), status);
        goto done;
    }

    /* Use the buffer */
    alg->fxns->useBufs(alg);

    /* Hold onto the resource for awhile */
    System_printf("Sleeping...\n");

    sleep(10);

    /* Check contents of the buffer */
    if (!(retVal = alg->fxns->checkBufs(alg))) {
        System_printf("Buffer overwritten by another alg.\n");
    }

    /* Deactivate All Resources */
    System_printf("Calling RMAN_deactivateAllResources()...\n");
    status = RMAN_deactivateAllResources((IALG_Handle)alg, &iresFxns,
            scratchId);
    if (status != IRES_OK) {
        System_printf("RMAN_deactivateAllResources() failed %s [%d]\n",
                getError(status), status);
        goto done;
    }

    /* Deactivate algorithm */
    System_printf("Calling DSKT2_deactivateAlg()...\n");
    DSKT2_deactivateAlg(scratchId, (IALG_Handle)alg);

    /* Free resources assigned to this algorihtm */
    System_printf("Calling RMAN_freeResources()...\n");
    status = RMAN_freeResources((IALG_Handle)(alg), &iresFxns, scratchId);
    if (status != IRES_OK) {
        System_printf("RMAN_freeResources() failed %s [%d]\n",
                getError(status), status);
        goto done;
    }

    /* Free instance of the algorithm created */
    System_printf("Calling DSKT2_freeAlg()...\n");
    DSKT2_freeAlg(scratchId, (IALG_Handle)alg);

    System_printf("Calling RMAN_unregister()...\n");
    status = RMAN_unregister(&SHMBUF_MGRFXNS);
    if (status != IRES_OK) {
        System_printf("RMAN_unregister() failed %s [%d]\n", getError(status),
                status);
        goto done;
    }

    System_printf("Calling RMAN_exit()...\n");
    status = RMAN_exit();
    if (status != IRES_OK) {
        System_printf("RMAN_exit() failed %s [%d]\n", getError(status),
                status);
        goto done;
    }
    else {
        if (retVal) {
            passed = TRUE;
        }
    }

done:

    RMAN_exit();

    if (passed) {
        System_printf("TEST PASSED\n");
    }
    else {
        System_printf("TEST FAILED\n");
    }

    return (0);
}

/*
 *  ======== getError ========
 */
static Char *getError(IRES_Status err)
{
    switch (err) {
        case IRES_OK:
            return ("IRES_OK");
        case IRES_EALG:
            return ("IRES_EALG");
        case IRES_EEXISTS:
            return ("IRES_EEXISTS");
        case IRES_EFAIL:
            return ("IRES_EFAIL");
        case IRES_EINIT:
            return ("IRES_EINIT");
        case IRES_ENOINIT:
            return ("IRES_ENOINIT");
        case IRES_ENOMEM:
            return ("IRES_ENOMEM");
        case IRES_ENORESOURCE:
            return ("IRES_ENORESOURCE");
        case IRES_ENOTFOUND:
            return ("IRES_ENOTFOUND");
        default:
            return ("UNKNOWN ERROR");
    }
}
/*
 *  @(#) ti.sdo.fc.rman.examples.shmbuf; 1, 0, 0,4; 2-22-2012 18:08:20; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

