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
 *  ======== HelloKnl.c ========
 *
 */

#include <xdc/std.h>
#include <ti/sdo/opencl/ComputeDevice.h>

#define HelloWorld_MSG          "Hello World!"
#define HelloUniverse_MSG       "Hello Universe!"

/*
 *  ======== HelloKnl_funcA ========
 *  Copy the message into the given buffer
 */
void HelloKnl_funcA(char *buffer, int size, int ctrl)
{
    char *      src;
    char *      dst = buffer;
    int         count = size;

    if (size <= 0) {
        return;
    }

    switch (ctrl) {
        case 0:
            src = HelloWorld_MSG;
            break;
        case 1:
            src = HelloUniverse_MSG;
            break;
    }

    /* copy string into buffer */
    while ((count-- > 0) && (*dst++ = *src++));

    /* ensure buffer is null terminated */
    buffer[size-1] = '\0';
}


/* HelloKnl argument types */
UInt HelloKnl_funcA_args[] = {
    ti_cl_arg_type_GlobalPtr,
    ti_cl_arg_type_Int,
    ti_cl_arg_type_Int
};

/* kernel function table */
ComputeDevice_FxnDesc HelloKnl_fxnTab[] = {
    {
        "HelloKnl_funcA",       /* fxn name */
        (Fxn)HelloKnl_funcA,    /* fxn address */
        3,                      /* num args */
        HelloKnl_funcA_args     /* arg types */
    }
};
/*
 *  @(#) ti.sdo.opencl.examples.hello; 1, 0, 0,4; 2-22-2012 18:09:29; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

