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
 *  ======== TIProgram.h ========
 */

#ifndef ti_sdo_opencl_TIProgram__include
#define ti_sdo_opencl_TIProgram__include

#include <CL/cl.h>
#include <ti/sdo/rcm/RcmClient.h>

#if defined (__cplusplus)
extern "C" {
#endif


/* TI extensions */

UInt    TIProgram_getOpenCLSigIdx(cl_program program);
UInt    TIProgram_getOpenCLSkelIdx(cl_program program);
RcmClient_Handle    TIProgram_getRcmClientHandle(cl_program program);
size_t  TIProgram_getRcmMsgDataSize(cl_program program);


#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */
#endif /* ti_sdo_opencl_TIProgram__include */




#ifdef  ti_sdo_opencl_TIProgram__private
#ifndef ti_sdo_opencl_TIProgram__private_included
#define ti_sdo_opencl_TIProgram__private_included

#include <ti/sdo/rcm/RcmClient.h>
#include "TIDevice.h"

#if defined (__cplusplus)
extern "C" {
#endif


typedef struct {
    size_t                  length;
    const unsigned char *   binary;
    RcmClient_Handle        rcmClientH;
    size_t                  rcmMsgDataSize;
    UInt32                  opencl_sig;
    UInt32                  opencl_skel;
} Binary;


typedef struct {
    int         length;
    Binary *    elem;
} ti_sdo_opencl_Program_BinaryArray;

struct _cl_program {
    cl_uint                             refCount;
    cl_context                          context;
    ti_sdo_opencl_DeviceArray           devices;
    ti_sdo_opencl_Program_BinaryArray   binaries;
};


#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */

#endif  /* ti_sdo_opencl_TIProgram__private_included */
#endif  /* ti_sdo_opencl_TIProgram__private */
/*
 *  @(#) ti.sdo.opencl; 1, 0, 0,4; 2-22-2012 18:09:28; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

