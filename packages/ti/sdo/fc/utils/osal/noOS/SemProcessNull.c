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
 *  ======== SemProcessNull.c ========
 */

#include <xdc/std.h>

#include <xdc/runtime/Error.h>

#include "package/internal/SemProcessNull.xdc.h"



/*
 *  ======== SemProcessNull_Instance_finalize ========
 */
//Void SemProcessNull_Instance_finalize(SemProcessNull_Object* sem, Int status)
//{
//}

/*
 *  ======== SemProcessNull_pend ========
 */
Int SemProcessNull_pend(SemProcessNull_Object* sem, UInt timeout,
        Error_Block* err)
{
    return (1);
}

/*
 *  ======== SemProcessNull_post ========
 */
Bool SemProcessNull_post(SemProcessNull_Object* sem, Error_Block* err)
{
    return (TRUE);
}
/*
 *  @(#) ti.sdo.fc.utils.osal.noOS; 1, 0, 0,4; 2-22-2012 18:09:01; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

