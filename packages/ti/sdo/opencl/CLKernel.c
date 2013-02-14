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
 *  ======== CLKernel.c ========
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <CL/cl.h>

#include <xdc/std.h>
#include <xdc/runtime/Memory.h>
#include <ti/sdo/rcm/RcmClient.h>

#include "TIProgram.h"
#include "ti_cl.h"

#define ti_sdo_opencl_TIKernel__private
#include "TIKernel.h"


/*
 *  ======== clCreateKernel ========
 */
cl_kernel clCreateKernel(
    cl_program          program,
    const char *        name,
    cl_int *            errcode_ret
)
{
    cl_kernel           kernel;
    Int                 status;
    RcmClient_Handle    rcmClientH;
    UInt32              dataSize;
    RcmClient_Message * rcmMsg;
    Char *              cp;


    /* allocate a cl_kernel object */
    kernel = (cl_kernel)Memory_calloc(NULL, sizeof(struct _cl_kernel),
        sizeof(Int), NULL);

    if (kernel == NULL) {
        if (errcode_ret != NULL) {
            *errcode_ret = CL_OUT_OF_HOST_MEMORY;
        }
        goto failure;
    }

    /* initialize cl_kernel object */
    kernel->refCount = 1;
    kernel->program = program;
    kernel->name = NULL;

    /* store the kernel string name */
    kernel->name = (char *)Memory_alloc(NULL,
        (strlen(name) + 1) * sizeof(char), sizeof(Int), NULL);

    if (kernel->name == NULL) {
        if (errcode_ret != NULL) {
            *errcode_ret = CL_OUT_OF_HOST_MEMORY;
        }
        goto failure;
    }
    strcpy(kernel->name, name);

    /* lookup the kernel function index */
    rcmClientH = TIProgram_getRcmClientHandle(kernel->program);
    dataSize = TIProgram_getRcmMsgDataSize(kernel->program);

    status = RcmClient_alloc(rcmClientH, dataSize, &rcmMsg);

    if (status < 0) {
        /* TODO handle error */
    }

    /* set message index, marshal kernel name into payload */
    rcmMsg->fxnIdx = TIProgram_getOpenCLSigIdx(kernel->program);
    cp = (Char *)(&rcmMsg->data[3]);
    strcpy(cp, kernel->name);

    /* execute the rcm message */
    status = RcmClient_exec(rcmClientH, rcmMsg, &rcmMsg);

    if (status < 0) {
        /* TODO handle error */
    }

    kernel->knlIdx = (Int)(rcmMsg->data[1]);
    kernel->numArgs = (Int)(rcmMsg->data[2]);

    /* free the rcm message */
    RcmClient_free(rcmClientH, rcmMsg);

    /* return success */
    if (errcode_ret != NULL) {
        *errcode_ret = CL_SUCCESS;
    }
    return(kernel);

failure:
    if (kernel != NULL) {
        if (kernel->name != NULL) {
            Memory_free(NULL, (Ptr)(kernel->name),
                (strlen(kernel->name) + 1 ) * sizeof(char));
        }
        Memory_free(NULL, (Ptr)kernel, sizeof(struct _cl_kernel));
    }

    return(NULL);
}

#if 0
cl_int clCreateKernelsInProgram(
        cl_program     program,
        cl_uint        num_kernels,
        cl_kernel *    kernels,
        cl_uint *      num_kernels_ret
)
{
    NOT_IMPLEMENTED_YET(__FUNCTION__);
    return CL_SUCCESS;
}
#endif


/*
 *  ======== clRetainKernel ========
 */
cl_int clRetainKernel(cl_kernel kernel)
{
    /* TODO: use xdc.runtime.knl.Atomic_inc() */
    kernel->refCount++;
    return(CL_SUCCESS);
}


/*
 *  ======== clReleaseKernel ========
 */
cl_int clReleaseKernel(cl_kernel kernel)
{

    /* TODO: use xdc.runtime.knl.Atomic_dec() */
    kernel->refCount--;

    if (kernel->refCount > 0) {
        return(CL_SUCCESS);
    }

    /* no longer in use, delete the object */
    if (kernel->name != NULL) {
        Memory_free(NULL, (Ptr)(kernel->name),
            (strlen(kernel->name) + 1 ) * sizeof(char));
    }
    Memory_free(NULL, (Ptr)kernel, sizeof(struct _cl_kernel));

    return(CL_SUCCESS);
}


/*
 *  ======== clSetKernelArg ========
 */
cl_int clSetKernelArg(
    cl_kernel           kernel,
    cl_uint             arg_index,
    size_t              arg_size,
    const void *        arg_value
)
{
    void *  dst;

    if (arg_size > sizeof(UInt32)) {
        return(-1);
    }

    dst = (void *)(&kernel->argVal[arg_index]);
    memcpy(dst, arg_value, arg_size);

    return(CL_SUCCESS);
}

#if 0
cl_int clGetKernelInfo(
        cl_kernel       kernel,
        cl_kernel_info  param_name,
        size_t          param_value_size,
        void *          param_value,
        size_t *        param_value_size_ret
)
{
    if (!verify(kernel)) return CL_INVALID_KERNEL;
    return kernel->info(param_name, param_value_size, param_value,
                         param_value_size_ret);
}

cl_int clGetKernelWorkGroupInfo(
        cl_kernel                  kernel,
        cl_device_id               device,
        cl_kernel_work_group_info  param_name,
        size_t                     param_value_size,
        void *                     param_value,
        size_t *                   param_value_size_ret
)
{
    NOT_IMPLEMENTED_YET(__FUNCTION__);
    return CL_SUCCESS;
}
#endif


/*
 *  ======== TIKernel_getNumArgs ========
 */
Int TIKernel_getNumArgs(cl_kernel kernel)
{
    return(kernel->numArgs);
}


/*
 *  ======== TIKernel_getArgVal ========
 */
UInt32 TIKernel_getArgVal(cl_kernel kernel, Int i)
{
    return(kernel->argVal[i]);
}


/*
 *  ======== TIKernel_getFxnIdx ========
 */
UInt TIKernel_getFxnIdx(cl_kernel kernel)
{
    return(kernel->knlIdx);
}


/*
 *  ======== TIKernel_getProgram ========
 */
cl_program TIKernel_getProgram(cl_kernel kernel)
{
    return(kernel->program);
}
/*
 *  @(#) ti.sdo.opencl; 1, 0, 0,4; 2-22-2012 18:09:26; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

