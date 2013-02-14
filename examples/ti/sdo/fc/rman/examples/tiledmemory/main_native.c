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
 *  ======== main_native.c ========
 */


#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Memory.h>

#include <ti/sdo/utils/trace/gt.h>

#include <ti/xdais/ires.h>

#include <ti/sdo/fc/rman/rman.h>
#include <ti/sdo/fc/ires/tiledmemory/iresman_tiledmemory.h>
#include <ti/sdo/fc/ires/tiledmemory/ires_tiledmemory.h>

#include <ti/sdo/utils/trace/gt.h>

#define CURTRACE ti_sdo_fc_rman_examples_tiledmemory
GT_Mask ti_sdo_fc_rman_examples_tiledmemory;


extern Void smain(Int argc, Char * argv[]);

IRESMAN_TiledmemoryParams configParams = {
    {0,      /* Size of this structure */
            /*
             * RMAN_PERSISTENTALLOCFXN,
             * RMAN_PERSISTENTFREEFXN,
             */
    NULL,
    NULL},
    1,      /* Number of resources to manage */
    NULL,   /* Rsvd for future use */
};


/*
 *  ======== main ========
 */
/* ARGSUSED */
int main(Int argc, Char * argv[])
{
    IRES_Status status;
    Int         size = 0;

    GT_init();
    GT_create(&CURTRACE, "ti.sdo.fc.rman.examples.tiledmemory");
        GT_set(MODNAME "=01234567");
        GT_set("ti.sdo.fc.rman" "=4567");
        GT_set("ti.sdo.fc.dskt2" "=67");
        GT_set("ti.sdo.fc.ires.tiledmemory" "=01234567");
/*      GT_set("ti.sdo.fc.dskt2" "=01234567");*/

    GT_0trace(CURTRACE, GT_ENTER, "_main> Enter \n");

    status = RMAN_init();
    if (IRES_OK != status) {
        GT_1trace(CURTRACE, GT_7CLASS, "main> RMAN_init() failed [%d]\n",
                status);
        return (-1);
    }

    /*
     * Supply initialization information for the RESMAN while registering
     */
    size = sizeof(IRESMAN_TiledmemoryParams);

    configParams.baseConfig.allocFxn = RMAN_PARAMS.allocFxn;
    configParams.baseConfig.freeFxn = RMAN_PARAMS.freeFxn;
    configParams.baseConfig.size = size;

    /* Register the TILEDMEMORY protocol/resource manager with the
     * generic resource manager */

    status = RMAN_register(&IRESMAN_TILEDMEMORY, (IRESMAN_Params *)&configParams);

    if (IRES_OK != status) {
        GT_1trace(CURTRACE, GT_7CLASS, "main> RMAN_register() failed [%d]\n",
                status);
        return (-1);
    }

    GT_0trace(CURTRACE, GT_ENTER, "main> Exit\n");

    return (rmanTask(argc, argv));
}
/*
 *  @(#) ti.sdo.fc.rman.examples; 1, 0, 0,4; 2-22-2012 18:07:15; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

