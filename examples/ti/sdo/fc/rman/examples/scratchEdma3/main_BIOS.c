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
#include <ti/sdo/fc/global/FCSettings.h>

/* IRES resources */
#include <ti/sdo/fc/ires/edma3chan/iresman_edma3Chan.h>
#include <ti/sdo/fc/edma3/edma3_config.h>


#include "memutils.h"  /* For checking for memory leaks */

/*
#define DMA_CHANNEL_TO_EVENT_MAPPING_0          (0x30FF1FF0u)
#define DMA_CHANNEL_TO_EVENT_MAPPING_1          (0x003F07FFu)
*/
#define DMA_CHANNEL_TO_EVENT_MAPPING_0          (0x0)
#define DMA_CHANNEL_TO_EVENT_MAPPING_1          (0x0)


/* #define MOD_NAME "ti.sdo.fc.rman"*/
#define MOD_NAME "*"



extern Void _DSKT2_init();

/*
 *  ======== DM6467_config ========
 */
EDMA3_InstanceInitConfig DM6467_config =
{
    /* Resources owned by Region 1 */
    /* ownPaRAMSets */
    {0x0u, 0x0u, 0x0u, 0x0u,
     0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu,
     0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu,
     0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu, 0xFFFFFFFFu},

    /* ownDmaChannels */
    {0xCF00E00Fu, 0xFF00F800u},

    /* ownQdmaChannels */
    {0x0000007Fu},

    /* ownTccs */
/*             {0xCF00E00Fu, 0xFF00F800u},*/
    {0xC0FF10F0u, 0xFF00F800u},

    /* Resources reserved by Region 1 */
    /* resvdPaRAMSets */
    {0x0u, 0x0u, 0x0u, 0x0u,
     0x0u, 0x0u, 0x0u, 0x0u,
     0x0u, 0x0u, 0x0u, 0x0u,
     0x0u, 0x0u, 0x0u, 0x0u},

    /* resvdDmaChannels */
    {DMA_CHANNEL_TO_EVENT_MAPPING_0, DMA_CHANNEL_TO_EVENT_MAPPING_1},

    /* resvdQdmaChannels */
    {0x0u},

    /* resvdTccs */
    {DMA_CHANNEL_TO_EVENT_MAPPING_0, DMA_CHANNEL_TO_EVENT_MAPPING_1},
};

/*
 *  ======== main ========
 */
/* ARGSUSED */
Int main(Int argc, Char * argv[])
{
    IRESMAN_Edma3ChanParams configParams;
    IRES_Status status;
    Int         size = 0;

    /*
     *  Set default Diags mask for FC modules. Only use levels 6 and 7
     *  until we get through _DSKT2_init(), since logging takes forever
     *  on simulator.
     */
    FCSettings_init();
    Diags_setMask("ti.sdo.fc.global.FCSettings+67");

    Diags_setMask("xdc.runtime.Main+EX1234567");

    /*
     *  Call to _DSKT2_init is required as it leaks memory.
     *  Call it before you get the first Memory stats.
     */
    System_printf("Testing for Memory Leaks\n");
    _DSKT2_init();

    /*
     *  Set default to all trace levels. This will not affect DSKT2, since
     *  it has already been initialized.
     */
    Diags_setMask("ti.sdo.fc.global.FCSettings+EX1234567");

    Log_print0(Diags_ENTRY, "[+E] main> Enter ");

    /* Turn on some BIOS tracing */
    Diags_setMask("ti.sysbios.knl.%+EX");

    /* Get the current memory usage */
#if 0
    MemUtils_initStats();
#endif

    status = RMAN_init();
    if (IRES_OK != status) {
        System_printf("RMAN initialization Failed [%d]\n", status);
        System_abort("RMAN_init() failed, aborting...\n");
    }

    /*
     * Supply initialization information for the EDMA3 RESMAN while registering
     */
    size = sizeof(IRESMAN_Edma3ChanParams);

    configParams.baseConfig.allocFxn = RMAN_PARAMS.allocFxn;
    configParams.baseConfig.freeFxn = RMAN_PARAMS.freeFxn;
    configParams.baseConfig.size = size;

    status = RMAN_register(&IRESMAN_EDMA3CHAN,
            (IRESMAN_Params *)&configParams);

    if ((status != IRES_EEXISTS) && (IRES_OK != status)) {
        System_printf("Protocol Registration Failed [%d]\n");
        System_abort("RMAN_register() failed, aborting...\n");
    }

    Log_print0(Diags_EXIT, "[+X] main> Exit");

    BIOS_start();

    return(0);
}
/*
 *  @(#) ti.sdo.fc.rman.examples.scratchEdma3; 1, 0, 0,4; 2-22-2012 18:08:03; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

