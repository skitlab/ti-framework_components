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
#include <xdc/runtime/System.h>
#include <xdc/runtime/Memory.h>

#include <ti/xdais/ires.h>
#include <ti/sdo/fc/ires/bufres/bufres.h>
#include <ti/sdo/fc/dskt2/dskt2.h>

#include <ti/sdo/fc/global/FCSettings.h>

#include "bufalg_ti.h"
#include "bufres_util.h"

#define BUFSIZE 512
#define BUFALIGN 0

static Void *buf = NULL;

BUFRES_Params config;

extern Void smain(Int argc, Char * argv[]);

/*
 *  ======== main ========
 */
/* ARGSUSED */
int main(Int argc, Char * argv[])
{
    IRES_Status        status;

    /* Set default Diags mask to all, to get trace for init() functions */
    FCSettings_init();
    Diags_setMask(FCSETTINGS_MODNAME"+EX1234567");

    buf = Memory_calloc(NULL, BUFSIZE, BUFALIGN, NULL);

    if (buf == NULL) {
        System_abort("Allocation of buffer for BUFRES failed. Aborting.\n");
    }

    config.iresConfig.size = sizeof(BUFRES_Params);
    config.iresConfig.allocFxn = DSKT2_allocPersistent;
    config.iresConfig.freeFxn = DSKT2_freePersistent;

    config.base = buf;
    config.length = (UInt32)BUFSIZE;

    status = BUFRES_init(&config);

    if (status != IRES_OK) {
        /* Test failed */
        System_printf("BUFRES_init() failed [0x%x]\n", status);
        System_abort("Aborting.\n");
        return (-1);
    }

    smain(argc, argv);

    return (0);
}
/*
 *  @(#) ti.sdo.fc.rman.examples.bufres_yield; 1, 0, 0,4; 2-22-2012 18:07:25; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

