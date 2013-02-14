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
 *  ======== MEMUTILS_cmem.c ========
 */

/* This difine must precede inclusion of any xdc header files */
#define Registry_CURDESC ti_sdo_fc_memutils_desc

#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Registry.h>

#include <ti/sdo/fc/global/FCSettings.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <ti/sdo/linuxutils/cmem/include/cmem.h>

#include "memutils.h"


static Int regInit = 0;  /* Registry_addModule() called */

Registry_Desc ti_sdo_fc_memutils_desc;

static Void addModule();

/*
 *  ======== MEMUTILS_getPhysicalAddr ========
 *  Converts user virtual address to physical address,
 *  Returns 0 on failure, physical address on success.
 */
Void * MEMUTILS_getPhysicalAddr(Ptr addr)
{
    UInt32 physicalAddress = 0;

    if (!regInit) {
        addModule();
    }

    CMEM_init();

    physicalAddress = CMEM_getPhys(addr);
    Log_print2(Diags_USER1, "[+1] MEMUTILS_getPhysicalAddr> "
            "CMEM_getPhys(0x%x) = 0x%x.", (IArg)addr, (IArg)physicalAddress);

    Log_print1(Diags_ENTRY, "[+E] MEMUTILS_getPhysicalAddr> return (0x%x)",
            (IArg)physicalAddress);

    CMEM_exit();

    return ((Void *)physicalAddress);
}


/*
 *  ======== MEMUTILS_cacheInv ========
 */
Void MEMUTILS_cacheInv(Ptr addr, Int sizeInBytes)
{
    if (!regInit) {
        addModule();
    }

    CMEM_init();
    CMEM_cacheInv(addr, sizeInBytes);
    CMEM_exit();
}


/*
 *  ======== MEMUTILS_cacheWb ========
 */
Void MEMUTILS_cacheWb(Ptr addr, Int sizeInBytes)
{
    if (!regInit) {
        addModule();
    }

    CMEM_init();
    CMEM_cacheWb(addr, sizeInBytes);
    CMEM_exit();
}


/*
 *  ======== MEMUTILS_cacheWbInv ========
 */
Void MEMUTILS_cacheWbInv(Ptr addr, Int sizeInBytes)
{
    if (!regInit) {
        addModule();
    }

    CMEM_init();
    CMEM_cacheWbInv(addr, sizeInBytes);
    CMEM_exit();
}

/*
 *  ======== addModule ========
 */
static Void addModule()
{
    Registry_Result result;

    result = Registry_addModule(&ti_sdo_fc_memutils_desc,
            MEMUTILS_MODNAME);
    Assert_isTrue(result == Registry_SUCCESS, (Assert_Id)NULL);

    if (result == Registry_SUCCESS) {
        /* Set the diags mask to the FC default */
        FCSettings_init();
        FCSettings_setDiags(MEMUTILS_MODNAME);
    }
    regInit = 1;
}
/*
 *  @(#) ti.sdo.fc.memutils; 1, 0, 0,4; 2-22-2012 18:07:03; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

