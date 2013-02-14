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
 *  ======== iusescratch.c ========
 *  This file defines the default parameter structure for iusescratch.h
 */

#include <xdc/std.h>
#include "iusescratch.h"

/*
 *  ======== USESCRATCH_PARAMS ========
 *  This structure defines the default parameters for dmantest objects.
 */
IUSESCRATCH_Params IUSESCRATCH_PARAMS = {
    sizeof(IUSESCRATCH_Params),
    -1,                         /* Scratch group */
    256,                        /* Scratch buffer size */
    0,                          /* Scratch buffer fill value */
    0,                          /* Task ID */
    NULL,                       /* Array of memory requests */
    0,                          /* Size of array of memory requests */
    NULL,                       /* Pointer to IALG_Fxns */
};

/*
 *  @(#) ti.sdo.fc.dskt2.examples; 1, 0, 0,4; 2-22-2012 18:03:53; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

