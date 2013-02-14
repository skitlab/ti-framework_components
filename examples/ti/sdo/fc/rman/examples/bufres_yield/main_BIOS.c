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
 *  ======== main_BIOS.c ========
 */

#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Memory.h>

#include <ti/sysbios/BIOS.h>

#include <ti/xdais/ires.h>

#include <ti/sdo/fc/rman/rman.h>
#include <ti/sdo/fc/rman/examples/bufres_yield/bufres.h>
#include <ti/sdo/fc/dskt2/dskt2.h>

#include "bufres_util.h"

#define BUFSIZE 512
#define BUFALIGN 0

extern IRESMAN_PersistentAllocFxn DSKT2_allocPersistent;
extern IRESMAN_PersistentFreeFxn  DSKT2_freePersistent;

static Void *buf = NULL;


BUFRES_Params config;


extern Void smain(Int argc, Char * argv[]);

/*
 *  ======== main ========
 */
/* ARGSUSED */
Void main(Int argc, Char * argv[])
{
    BUFRES_Params      resmanConfig;
    IRES_Status        status;

    Diags_setMask("xdc.runtime.Main+EX1234567");

    status = RMAN_init();
    Diags_setMask(RMAN_MODNAME"+EX1234567");

    if (IRES_OK != status) {
        Log_print0(Diags_USER7, "[+7] main> RMAN initialization Failed ");
        System_abort("Aborting...\n");
    }

    buf = Memory_calloc(NULL, BUFSIZE, BUFALIGN, NULL);

    if (buf == NULL) {
        System_abort("Allocation of buffer for BUFRES failed. Aborting.\n");
    }

    /*
     *  Initialize the BUFRES resource manager.
     */
    resmanConfig.iresConfig.size = sizeof(BUFRES_Params);
    resmanConfig.iresConfig.allocFxn = DSKT2_allocPersistent;
    resmanConfig.iresConfig.freeFxn = DSKT2_freePersistent;

    resmanConfig.base = buf;
    resmanConfig.length = (UInt32)BUFSIZE;
    resmanConfig.fillValue = (UInt32 )0xCAFEC0FE;

    status = RMAN_register(&BUFRES_MGRFXNS, (IRESMAN_Params *)&resmanConfig);

    if (IRES_OK != status) {
        Log_print0(Diags_USER7, "[+7] main> Protocol Registration Failed ");
        System_abort("Aborting...\n");
    }

    if (status != IRES_OK) {
        /* Test failed */
        System_printf("BUFRES_init() failed [0x%x]\n", status);
        System_abort("Aborting.\n");
    }

    BIOS_start();
}
/*
 *  @(#) ti.sdo.fc.rman.examples.bufres_yield; 1, 0, 0,4; 2-22-2012 18:07:25; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

