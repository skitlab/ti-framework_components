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
 *  ======== CLProgram.c ========
 */
#include <stdlib.h>
#include <string.h>

#include <CL/cl.h>

#include <xdc/std.h>
#include <xdc/runtime/Memory.h>
#include <ti/sdo/rcm/RcmClient.h>


#define ti_sdo_opencl_TIProgram__private
#include "TIProgram.h"


/* private functions */
static Int CLProgram_getPropVal_P(String prop, const UChar *binary, Char *buf);

/* private data */
static cl_bool  RcmClient_init_flag = 0;


/*
 *  ======== clCreateProgramWithSource ========
 */
cl_program clCreateProgramWithSource(
    cl_context      context,
    cl_uint         count,
    const char **   strings,
    const size_t *  lengths,
    cl_int *        errcode_ret
)
{
//  NOT_IMPLEMENTED_OPTIONAL(__FUNCTION__);
    return(NULL);
}


/*
 *  ======== clCreateProgramWithBinary ========
 *
 *  Note: this implementation supports only one binary. This is a design
 *  decision to allow for early binding of the program to the corresponding
 *  RcmServer instance which hosts the OpenCL kernels for the given binary.
 */
cl_program clCreateProgramWithBinary(
    cl_context              context,
    cl_uint                 num_devices,
    const cl_device_id *    device_list,
    const size_t *          lengths,
    const unsigned char **  binaries,
    cl_int *                binary_status,
    cl_int *                errcode_ret
)
{
    cl_program          program;
    cl_int              rval = CL_SUCCESS;
    RcmClient_Params    rcmClientP;
    Binary *            bin;
    Char                buf[128];
    Char                name[64];
    Int                 i;
    Int                 status;

    /* currently only support one device */
    if (num_devices != 1) {
        if (errcode_ret != NULL) {
            *errcode_ret = CL_INVALID_VALUE;
        }
        return(NULL);
    }

    /* must have at least one device */
    if ((num_devices == 0) || (device_list == NULL)) {
        if (errcode_ret != NULL) {
            *errcode_ret = CL_INVALID_VALUE;
        }
        return(NULL);
    }

    /* must have a binary for each device */
    if ((lengths == 0) || (binaries == NULL)) {
        if (errcode_ret != NULL) {
            *errcode_ret = CL_INVALID_VALUE;
        }
        return(NULL);
    }

    for (i = 0; i < num_devices; i++) {
        if ((lengths[i] == 0) || (binaries[i] == NULL)) {
            if (binary_status != NULL) {
                binary_status[i] = CL_INVALID_VALUE;
            }
            rval = CL_INVALID_VALUE;
        }
        else {
            if (binary_status != NULL) {
                binary_status[i] = CL_SUCCESS;
            }
        }
    }

    if (rval != CL_SUCCESS) {
        if (errcode_ret != NULL) {
            *errcode_ret = rval;
        }
        return(NULL);
    }

#if 0  /* TODO: need to verify the binaries */
    for (i = 0; i < num_devices; ++i) {
        if (!device_list[i]->verify_binary(binaries[i], lengths[i])) {
            if (binary_status != NULL) {
                binary_status[i] = CL_INVALID_BINARY;
            }
            rval = CL_INVALID_BINARY;
        }
        else {
            if (binary_status != NULL) {
                binary_status[i] = CL_SUCCESS;
            }
        }
    }

    if (rval != CL_SUCCESS) {
        if (errcode_ret != NULL) {
            *errcode_ret = rval;
        }
        return(NULL);
    }
#endif

    /* allocate a program object */
    program = (cl_program)Memory_calloc(NULL, sizeof(struct _cl_program),
        sizeof(Int), NULL);

    if (program == NULL) {
        if (errcode_ret != NULL) {
            *errcode_ret = CL_OUT_OF_HOST_MEMORY;
        }
        goto failure;
    }

    /* initialize program object */
    program->refCount = 1;
    program->context = context;
    program->devices.length = 0;
    program->devices.elem = NULL;
    program->binaries.length = 0;
    program->binaries.elem = NULL;

    /* copy devices references */
    program->devices.length = num_devices;
    program->devices.elem = (cl_device_id *)Memory_calloc(NULL,
        num_devices * sizeof(cl_device_id), sizeof(Int), NULL);

    if (program->devices.elem == NULL) {
        if (errcode_ret != NULL) {
            *errcode_ret = CL_OUT_OF_HOST_MEMORY;
        }
        goto failure;
    }

    for (i = 0; i < num_devices; i++) {
        program->devices.elem[i] = device_list[i];
    }

    /* store data for each binary */
    program->binaries.length = num_devices;
    program->binaries.elem = (Binary *)Memory_calloc(NULL,
        num_devices * sizeof(Binary), sizeof(Int), NULL);

    if (program->binaries.elem == NULL) {
        if (errcode_ret != NULL) {
            *errcode_ret = CL_OUT_OF_HOST_MEMORY;
        }
        goto failure;
    }

    for (i = 0; i < num_devices; i++) {
        program->binaries.elem[i].length = lengths[i];
        program->binaries.elem[i].binary = binaries[i];
        program->binaries.elem[i].rcmClientH = NULL;
    }

    /* TODO: this needs to be in an init function, exit never called */
    if (!RcmClient_init_flag) {
        RcmClient_init_flag = CL_TRUE;
        RcmClient_init();
    }

    /* create an rcm client instance for each binary */
    for (i = 0; i < program->binaries.length; i++) {
        bin = &program->binaries.elem[i];

        RcmClient_Params_init(&rcmClientP);
        CLProgram_getPropVal_P("rcmServerHeapId", bin->binary, buf);
        rcmClientP.heapId = (UInt16)atoi(buf);
        CLProgram_getPropVal_P("rcmServerName", bin->binary, name);

        status = RcmClient_create(name, &rcmClientP, &bin->rcmClientH);

        if (status < 0) {
            if (errcode_ret != NULL) {
                *errcode_ret = CL_OUT_OF_RESOURCES;
            }
            goto failure;
        }

        CLProgram_getPropVal_P("rcmMsgDataSize", bin->binary, buf);
        bin->rcmMsgDataSize = (size_t)atoi(buf);
        
        /* get rcm message function index for opencl helpers */
        status = RcmClient_getSymbolIndex(bin->rcmClientH, "OpenCL_sig",
            &bin->opencl_sig);

        if (status < 0) {
            /* TODO handle error */
        }

        status = RcmClient_getSymbolIndex(bin->rcmClientH, "OpenCL_skel",
            &bin->opencl_skel);

        if (status < 0) {
            /* TODO handle error */
        }
    }

    /* TODO: add code here */

    /* return success */
    if (errcode_ret != NULL) {
        *errcode_ret = CL_SUCCESS;
    }
    return(program);

failure:
    if (program != NULL) {
        if (program->binaries.elem != NULL) {
            for (i = 0; i < program->binaries.length; i++) {
                if (program->binaries.elem[i].rcmClientH != NULL) {
                    RcmClient_delete(&(program->binaries.elem[i].rcmClientH));
                }
            }
            Memory_free(NULL, (Ptr)(program->binaries.elem),
                program->binaries.length * sizeof(Binary));
        }
        if (program->devices.elem != NULL) {
            Memory_free(NULL, (Ptr)(program->devices.elem),
                program->devices.length * sizeof(cl_device_id));
        }
        Memory_free(NULL, (Ptr)program, sizeof(struct _cl_program));
    }

    return(NULL);
}


/*
 *  ======== clRetainProgram ========
 */
cl_int clRetainProgram(cl_program program)
{
    /* TODO: use xdc.runtime.knl.Atomic_inc() */
    program->refCount++;
    return(CL_SUCCESS);
}


/*
 *  ======== clReleaseProgram ========
 */
cl_int clReleaseProgram(cl_program program)
{
    Int i;

    /* TODO: use xdc.runtime.knl.Atomic_dec() */
    program->refCount--;

    if (program->refCount > 0) {
        return(CL_SUCCESS);
    }

    /* no longer in use, delete the program */
    if (program->binaries.elem != NULL) {
        for (i = 0; i < program->binaries.length; i++) {
            if (program->binaries.elem[i].rcmClientH != NULL) {
                RcmClient_delete(&(program->binaries.elem[i].rcmClientH));
            }
        }
        Memory_free(NULL, (Ptr)(program->binaries.elem),
            program->binaries.length * sizeof(Binary));
    }
    Memory_free(NULL, (Ptr)(program->devices.elem),
        program->devices.length * sizeof(cl_device_id));

    Memory_free(NULL, (Ptr)program, sizeof(struct _cl_program));

    return(CL_SUCCESS);
}


/*
 *  ======== clBuildProgram ========
 */
cl_int clBuildProgram(
    cl_program              program,
    cl_uint                 num_devices,
    const cl_device_id *    device_list,
    const char *            options,
    void                    (*pfn_notify)(cl_program, void *),
    void *                  user_data
)
{
//  NOT_IMPLEMENTED_OPTIONAL(__FUNCTION__);
    return(-1);
}


/*
 *  ======== clUnloadCompiler ========
 */
cl_int clUnloadCompiler(void)
{
//  NOT_IMPLEMENTED_OPTIONAL(__FUNCTION__);
    return(-1);
}


/*
 *  ======== clGetProgramInfo ========
 */
cl_int clGetProgramInfo(
    cl_program      program,
    cl_program_info param_name,
    size_t          param_value_size,
    void *          param_value,
    size_t *        param_value_size_ret
)
{
    cl_device_id *          device;
    cl_uint                 rvalUInt;
    cl_context              rvalContext;
    int                     i, fieldType;
    size_t                  size;

#define FT_UINT         1
#define FT_CONTEXT      2
#define FT_DEVICES      3

    switch (param_name) {
        case CL_PROGRAM_REFERENCE_COUNT:
            fieldType = FT_UINT;
            rvalUInt = program->refCount;
            break;
        case CL_PROGRAM_CONTEXT:
            fieldType = FT_CONTEXT;
            rvalContext = program->context;
            break;
        case CL_PROGRAM_NUM_DEVICES:
            fieldType = FT_UINT;
            rvalUInt = program->devices.length;
            break;
        case CL_PROGRAM_DEVICES:
            fieldType = FT_DEVICES;
            break;
        default:
            return(CL_INVALID_VALUE);
    }

    /* switch on param type, then copy param value into return buffer */
    switch (fieldType) {

        case FT_UINT:  /* (cl_uint) */
            if (param_value != NULL) {
                if (param_value_size < sizeof(cl_uint)) {
                    return(CL_INVALID_VALUE);
                }
                *(cl_uint *)param_value = rvalUInt;
            }
            if (param_value_size_ret != NULL) {
                *param_value_size_ret = sizeof(cl_uint);
            }
            break;

        case FT_CONTEXT:  /* (cl_context) */
            if (param_value != NULL) {
                if (param_value_size < sizeof(cl_context)) {
                    return(CL_INVALID_VALUE);
                }
                *(cl_context *)param_value = rvalContext;
            }
            if (param_value_size_ret != NULL) {
                *param_value_size_ret = sizeof(cl_context);
            }
            break;

        case FT_DEVICES:  /* (devices) */
            size = program->devices.length * sizeof(cl_device_id);
            if (param_value != NULL) {
                if (param_value_size < size) {
                    return(CL_INVALID_VALUE);
                }
                device = (cl_device_id *)param_value;
                for (i = 0; i < program->devices.length; i++) {
                    *device++ = program->devices.elem[i];
                }
            }
            if (param_value_size_ret != NULL) {
                *param_value_size_ret = size;
            }
            break;
    }

    return(CL_SUCCESS);
}


/*
 *  ======== clGetProgramBuildInfo ========
 */
cl_int clGetProgramBuildInfo(
    cl_program              program,
    cl_device_id            device,
    cl_program_build_info   param_name,
    size_t                  param_value_size,
    void *                  param_value,
    size_t *                param_value_size_ret
)
{
//  NOT_IMPLEMENTED_OPTIONAL(__FUNCTION__);
    return(-1);
}


/*
 *  ======== CLProgram_getPropVal_P ========
 *  TODO: add outBuf size, check for overflow
 */
Int CLProgram_getPropVal_P(String prop, const UChar *inBuf, Char *outBuf)
{
    Char    workBuf[256];
    Char *  key;
    Char *  val;

    strcpy(workBuf, (const Char *)inBuf);

    key = strtok(workBuf, "=");

    while ((key != NULL) && (strcmp(key, prop) != 0)) {
        strtok(NULL, ";");
        key = strtok(NULL, "=");
    }

    if (key == NULL) {          // prop not found
        *outBuf = '\0';
        return(0);
    }

    val = strtok(NULL, ";");    // extract value
    strcpy(outBuf, val);

    return(strlen(outBuf));
}


/*
 *  ======== TIProgram_getOpenCLSigIdx ========
 */
UInt TIProgram_getOpenCLSigIdx(cl_program program)
{

    /* only support one binary */
    if (program->binaries.length > 1) {
        return(NULL);
    }

    return(program->binaries.elem[0].opencl_sig);
}


/*
 *  ======== TIProgram_getOpenCLSkelIdx ========
 */
UInt TIProgram_getOpenCLSkelIdx(cl_program program)
{

    /* only support one binary */
    if (program->binaries.length > 1) {
        return(NULL);
    }

    return(program->binaries.elem[0].opencl_skel);
}


/*
 *  ======== TIProgram_getRcmClientHandle ========
 *  Return the RcmClient_Handle associated with this program. Note that we
 *  currently only support one binary per program.
 */
RcmClient_Handle TIProgram_getRcmClientHandle(cl_program program)
{

    /* only support one binary */
    if (program->binaries.length > 1) {
        return(NULL);
    }

    return(program->binaries.elem[0].rcmClientH);
}


/*
 *  ======== TIProgram_getRcmMsgDataSize ========
 *  Return the rcm message data size associated with this program.
 *  Note that we currently only support one binary per program.
 */
size_t TIProgram_getRcmMsgDataSize(cl_program program)
{

    /* only support one binary */
    if (program->binaries.length > 1) {
        return(NULL);
    }

    return(program->binaries.elem[0].rcmMsgDataSize);
}
/*
 *  @(#) ti.sdo.opencl; 1, 0, 0,4; 2-22-2012 18:09:27; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

