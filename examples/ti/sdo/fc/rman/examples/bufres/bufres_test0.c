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
 *  ======== bufres_test0.c ========
 *  Test the functionality of the Buffer Resource Manager, independent
 *  of the RMAN framework.
 */

#include <xdc/std.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/System.h>

#include <ti/sdo/fc/ires/iresman.h>

#include <ti/sdo/fc/ires/bufres/bufres.h>
#include "bufres_util.h"


extern Void smain(Int argc, Char * argv[]);

/*
 *  ======== smain ========
 */
/* ARGSUSED */
Void smain(Int argc, Char * argv[])
{
    BUFRES_Args        args;
    BUFRES_Handle      bufres[10];
    IRES_Status        status;
    Int                scratchId;
    Void              *base;
    Bool               passed = FALSE;
    IRES_ResourceDescriptor resDesc; 
    IRES_ProtocolRevision rev= {1,0,0};


    resDesc.resourceName = "BUFRES_PROTOCOLNAME";
    resDesc.revision = &rev;
    resDesc.protocolArgs = (IRES_ProtocolArgs *)&args;
    /* Allocate a bunch of resources */
    resDesc.protocolArgs->size = sizeof(BUFRES_Args);
    resDesc.protocolArgs->mode = IRES_SCRATCH;

    args.align = 8;
    args.length = 0x18;

    scratchId = 1;
    if ((bufres[0] = BUFRES_get((IALG_Handle)NULL, &resDesc, scratchId,
                 &status)) == NULL) {
        goto done;
    }
    else {
        base = bufres[0]->base;
        status = BUFRES_free((IALG_Handle)NULL, bufres[0], &resDesc,
                scratchId);
        bufres[0] = NULL;
        if (status != IRES_OK) {
            goto done;
        }
    }

    resDesc.protocolArgs->mode = IRES_PERSISTENT;
    if ((bufres[0] = BUFRES_get((IALG_Handle) NULL, &resDesc, scratchId,
                 &status)) == NULL) {
        goto done;
    }
    else {
        /* Should get the same base address as before */
        if (base != bufres[0]->base) {
            goto done;
        }
    }

    /* Should not be allowed to allocate another persistent buffer */
    resDesc.protocolArgs->mode = IRES_PERSISTENT;
    if ((bufres[1] = BUFRES_get((IALG_Handle)NULL, &resDesc, scratchId,
                 &status)) != NULL) {
        goto done;
    }

    /* Should not be allowed to allocate another scratch buffer */
    resDesc.protocolArgs->mode = IRES_PERSISTENT;
    bufres[1] = BUFRES_get((IALG_Handle)NULL, &resDesc, scratchId, &status);
    if (bufres[1] != NULL) {
        goto done;
    }

    status = BUFRES_free((IALG_Handle)NULL, bufres[0], &resDesc, scratchId);
    bufres[0] = NULL;
    if (status != IRES_OK) {
        goto done;
    }
    resDesc.protocolArgs->mode = IRES_SCRATCH;
    bufres[0] = BUFRES_get((IALG_Handle)NULL, &resDesc, scratchId, &status);
    if (bufres[0] == NULL) {
        goto done;
    }

    /* Should not be allowed to allocate scratch buffer in another group */
    resDesc.protocolArgs->mode = IRES_SCRATCH;
    bufres[1] = BUFRES_get((IALG_Handle)NULL, &resDesc, scratchId + 1, &status);
    if (bufres[1] != NULL) {
        goto done;
    }

    /* Allowed to allocate another scratch buffer in same group */
    bufres[1] = BUFRES_get((IALG_Handle)NULL, &resDesc, scratchId, &status);
    if (bufres[1] == NULL) {
        goto done;
    }
    if (bufres[1]->base != bufres[0]->base) {
        goto done;
    }
    BUFRES_free((IALG_Handle)NULL, bufres[0], &resDesc, scratchId);
    BUFRES_free((IALG_Handle)NULL, bufres[1], &resDesc, scratchId);
    bufres[0] = bufres[1] = NULL;

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
 *  @(#) ti.sdo.fc.rman.examples.bufres; 1, 0, 0,4; 2-22-2012 18:07:29; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

