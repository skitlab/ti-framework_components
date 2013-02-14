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
 *  ======== TIEvent.h ========
 */

#ifndef ti_sdo_opencl_TIEvent__include
#define ti_sdo_opencl_TIEvent__include

#include <CL/cl.h>

#if defined (__cplusplus)
extern "C" {
#endif

/* TI extensions */

cl_event        TIEvent_create(cl_context context, cl_command_queue queue,
                    cl_command_type cmdType, void *rcmClientH);
void            TIEvent_setMsgId(cl_event event, cl_int msgId);
cl_int          TIEvent_wait(cl_event event);


#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */
#endif /* ti_sdo_opencl_TIEvent__include */




#ifdef  ti_sdo_opencl_TIEvent__private
#ifndef ti_sdo_opencl_TIEvent__private_included
#define ti_sdo_opencl_TIEvent__private_included

#if defined (__cplusplus)
extern "C" {
#endif

struct _cl_event
{
    cl_uint             refCount;       /* object reference count       */
    cl_context          context;        /* associated context           */
    cl_command_queue    queue;          /* associated command queue     */
    cl_command_type     cmdType;        /* command type                 */
    volatile cl_int     status;         /* command execution status     */
    void *              rcmClientH;     /* rcm client handle            */
    cl_uint             msgId;          /* rcm message id               */
};


#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */

#endif  /* ti_sdo_opencl_TIEvent__private_included */
#endif  /* ti_sdo_opencl_TIEvent__private */
/*
 *  @(#) ti.sdo.opencl; 1, 0, 0,4; 2-22-2012 18:09:27; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

