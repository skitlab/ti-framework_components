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
#include <xdc/runtime/System.h>

#include <string.h>

#include <ti/sdo/fc/dskt2/dskt2.h>
#include <ti/sdo/fc/ires/iresman.h>

#include <ti/sdo/fc/ires/bufres/bufres.h>
#include "bufalg_ti.h"
#include "bufres_util.h"

#define MAXDESCS 10
#define NUMBUFS 8

typedef struct ResTabEntry {
    String        name;
    IRESMAN_Fxns *fxns;
} ResTabEntry;

ResTabEntry resourceTab[] = {
    {BUFRES_PROTOCOLNAME, &BUFRES_MGRFXNS}
};

extern Void smain(Int argc, Char * argv[]);

extern IRESMAN_PersistentAllocFxn DSKT2_allocPersistent;
extern IRESMAN_PersistentFreeFxn  DSKT2_freePersistent;


static Bool freeAlgResources(BUFALG_TI_Handle alg, IRES_Fxns *fxns,
        Int scratchId);
static Void freeResources(IALG_Handle h, IRES_ResourceDescriptor *desc,
        Int numDesc, Int scratchId);
static Bool getResources(BUFALG_TI_Handle alg, IRES_Fxns *fxns, Int scratchId);
static Bool init();

/*
 *  ======== smain ========
 */
/* ARGSUSED */
Void smain(Int argc, Char * argv[])
{
    BUFALG_TI_Handle   alg;
    IBUFALG_Fxns       fxns = BUFALG_TI_IBUFALG;
    IRES_Fxns          iresFxns = BUFALG_TI_IRES;
    Int                scratchId;
    Bool               passed = FALSE;

    scratchId = 1;
    alg = (BUFALG_TI_Handle)DSKT2_createAlg(scratchId, (IALG_Fxns *)&fxns,
            NULL, NULL);
    if (alg == NULL) {
        System_printf("Alg creation failed\n");
        goto done;
    }

    if (!getResources(alg, &iresFxns, scratchId)) {
        goto done;
    }

    if (!freeAlgResources(alg, &iresFxns, scratchId)) {
        goto done;
    }

    DSKT2_freeAlg(scratchId, (IALG_Handle)alg);

    passed = TRUE;

done:
    if (passed) {
        System_printf("TEST PASSED\n");
    }
    else {
        System_printf("TEST FAILED\n");
    }
}


/*
 *  ======== freeAlgResources ========
 */
static Bool freeAlgResources(BUFALG_TI_Handle alg, IRES_Fxns *fxns,
        Int scratchId)
{
    IRES_ResourceDescriptor desc[MAXDESCS];
    IALG_Handle             h = (IALG_Handle)alg;
    Int                     numRes;
    Int                     status;

    numRes = (fxns->numResourceDescriptors)(h);
    if (numRes > MAXDESCS) {
        System_printf("Too many resources: %d\n", numRes);
        return (FALSE);
    }

    System_printf("Number of resources: %d\n", numRes);

    status = (fxns->getResourceDescriptors)(h, desc);

    if (status != IRES_OK) {
        System_printf("Failed to get resource descriptors\n");
        return (FALSE);
    }

    freeResources(h, desc, numRes, scratchId);

    return (TRUE);
}

/*
 *  ======== freeResources ========
 */
static Void freeResources(IALG_Handle h, IRES_ResourceDescriptor *desc,
        Int numDesc, Int scratchId)
{
    IRESMAN_Fxns   *rFxns;
    IRES_Status     ret;
    Int             i, j;
    Int             tabSize;

    tabSize = sizeof(resourceTab) / sizeof(ResTabEntry);

    for (i = 0; i < numDesc; i++) {
        for (j = 0; j < tabSize; j++) {
            if (!strcmp(desc[i].resourceName, resourceTab[j].name)) {
                /* Found the match */
                rFxns = resourceTab[j].fxns;

                if (desc[i].handle != NULL) {
                    ret = (rFxns->freeHandle)(h, desc[i].handle, &desc[i], 
                            scratchId);
                    desc[i].handle = NULL;
//                    DBC_assert(ret == IRES_OK);
                }
                break;
            }
//            DBC_assert(j < tabSize);
        }
    }
}

/*
 *  ======== getResources ========
 */
static Bool getResources(BUFALG_TI_Handle alg, IRES_Fxns *fxns, Int scratchId)
{
    IRES_ResourceDescriptor desc[MAXDESCS];
    IALG_Handle             h = (IALG_Handle)alg;
    Int                     numRes;
    Int                     tabSize;
    Int                     i, j;
    IRESMAN_Fxns           *rFxns;
    IRES_Status             status;
    IRES_Status             ret;

    numRes = (fxns->numResourceDescriptors)(h);
    if (numRes > MAXDESCS) {
        System_printf("Too many resources: %d\n", numRes);
        return (FALSE);
    }

    System_printf("Number of resources requested: %d\n", numRes);

    status = (fxns->getResourceDescriptors)(h, desc);

    if (status != IRES_OK) {
        System_printf("Failed to get resource descriptors\n");
        return (FALSE);
    }

    /* Initialize resource handle to NULL */
    for (i = 0; i < numRes; i++) {
        desc[i].handle = NULL;
    }

    tabSize = sizeof(resourceTab) / sizeof(ResTabEntry);
    //System_printf("Resource table size = %d\n", tabSize);

    for (i = 0; i < numRes; i++) {
        ret = IRES_OK;

        for (j = 0; j < tabSize; j++) {
            if (strcmp(desc[i].resourceName, resourceTab[j].name) == 0) {
                /* Found a match in the table */
                System_printf("Found resource: %s\n", resourceTab[j].name);
                rFxns = resourceTab[j].fxns;
                desc[i].handle = rFxns->getHandle(h, &desc[i], scratchId, &ret);
                break;
            }
        }

        if (desc[i].handle == NULL) {
            System_printf("Resource [%s]: allocation failed [%d]\n",
                    desc[i].resourceName, ret);

            /* Free everything allocated so far. */
            freeResources(h, desc, i, scratchId);

            return (FALSE);
        }
    }

    //System_printf("num resources: %d\n", numRes);
    return (TRUE);
}
/*
 *  @(#) ti.sdo.fc.rman.examples.bufres; 1, 0, 0,4; 2-22-2012 18:07:29; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

