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
 *  ======== test0.c ========
 *
 *  Create and run algorithm that use DSKT2 to allocate persistent and
 *  scratch memory.
 */


#include <xdc/std.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/System.h>

#include <ti/sdo/fc/dskt2/dskt2.h>

#include "usescratch_ti.h"

#define MOD_NAME DSKT2_MODNAME

#define BUFSIZE 0x40


/*
 *  ======== TestAttrs ========
 */
typedef struct TestAttrs {
    Int         priority;       /* Priority of task */
    Uns         scratchSize;    /* Scratch buffer size */
    Uns         fillValue;      /* Value to fill scratch buffer with */
} TestAttrs;

extern Void smain(Int argc, Char * argv[]);

/*
 *  ======== smain ========
 */
/* ARGSUSED */
Void smain(Int argc, Char * argv[])
{
    IUSESCRATCH_Handle  alg;
    IUSESCRATCH_Params  params = IUSESCRATCH_PARAMS;
    IALG_Fxns          *fxns;
    Int                 scratchId = 1;
    Int                 status = USESCRATCH_SOK;


    System_printf("test0> Started.\n");

    fxns = (IALG_Fxns *)&USESCRATCH_TI_IUSESCRATCH;
    params.value = 1;           /* Value to put in scratch memory */
    params.fxns = fxns;

    /* Create, activate, and run alg */
    alg = (IUSESCRATCH_Handle)DSKT2_createAlg(scratchId, fxns, NULL,
            (IALG_Params *)&params);

    /* Set trace for DSKT2 module */
    Diags_setMask(MOD_NAME"+4567");
    Diags_setMask(MOD_NAME"-EX123");

    //System_printf("test0> alg = 0x%x\n", alg);

    if (alg == NULL) {
        status = USESCRATCH_EMEMORY;
    }
    else {
        DSKT2_activateAlg(scratchId, (IALG_Handle)alg);

        status = alg->fxns->useScratch((IALG_Handle)alg);

        DSKT2_deactivateAlg(scratchId, (IALG_Handle)alg);

        /* Free alg */
        DSKT2_freeAlg(scratchId, (IALG_Handle)alg);
    }

    if (status != USESCRATCH_SOK) {
        System_printf("======== TEST FAILED ========\n");
    }
    else {
        System_printf("======== TEST PASSED ========\n");
    }

    /* If System is configured with SysMin, need to flush to see output */
    //System_flush();
}
/*
 *  @(#) ti.sdo.fc.dskt2.examples; 1, 0, 0,4; 2-22-2012 18:03:54; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

