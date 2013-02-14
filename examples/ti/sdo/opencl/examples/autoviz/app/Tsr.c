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
 *  ======== Tsr.c ========
 *
 */

/* this define must precede inclusion of any xdc header file */
#define Registry_CURDESC Tsr__Desc
#define MODULE_NAME "Tsr"

/* xdctools header files */
#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Registry.h>

/* package header files */

/* local header files */
#include "Tsr.h"


/* private data */
static Int      curInit = 0;
Registry_Desc   Registry_CURDESC;


/*
 *  ======== Tsr_init ========
 */
Void Tsr_init(Void)
{
    Registry_Result     result;


    if (curInit++ != 0) {
        return;  /* already initialized */
    }

    /* register with xdc.runtime to get a diags mask */
    result = Registry_addModule(&Registry_CURDESC, MODULE_NAME);
    Assert_isTrue(result == Registry_SUCCESS, (Assert_Id)NULL);
}


/*
 *  ======== Tsr_exit ========
 */
Void Tsr_exit(Void)
{
//  Registry_Result     result;


    if (curInit-- != 1) {
        return;  /* object still being used */
    }

    /* unregister from xdc.runtime */
//  result = Registry_removeModule(MODULE_NAME);
//  Assert_isTrue(result == Registry_SUCCESS, (Assert_Id)NULL);
}


/*
 *  ======== Tsr_process ========
 *  Traffic Sign Recognition processing function
 */
Void Tsr_local(UInt *workBuf, Int width, Int height)
{
    Int x, y;
    UInt *pa;
    UInt p;

    /* simulate a local processing function */
    for (y = 0; y < height; y+= 4) {
        for (x = 0; x < height; x += 4) {
            pa = workBuf + ((y * width) + x);
            p = *pa;
            p = p * 1;
            *pa = p;
        }
    }
}
/*
 *  @(#) ti.sdo.opencl.examples.autoviz; 1, 0, 0,4; 2-22-2012 18:09:18; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

