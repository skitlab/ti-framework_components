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
 *  ======== CLCommandQueue.c ========
 */
#include <CL/cl.h>

#include <xdc/std.h>
#include <xdc/runtime/Memory.h>
#include <ti/sdo/rcm/RcmClient.h>

#include "TIContext.h"
#include "TIDevice.h"
#include "TIEvent.h"
#include "TIKernel.h"
#include "TIProgram.h"


#define ti_sdo_opencl_TICommandQueue__private
#include "TICommandQueue.h"


/*
 *  ======== clCreateCommandQueue ========
 */
cl_command_queue clCreateCommandQueue(
    cl_context                  context,
    cl_device_id                device,
    cl_command_queue_properties properties,
    cl_int *                    errcode_ret
)
{
    cl_command_queue    queue;


    /* context must contain the device */
    if (!TIContext_hasDevice(context, device)) {
        if (errcode_ret != NULL) {
            *errcode_ret = CL_INVALID_DEVICE;
        }
        goto failure;
    }

    /* Ensure that the properties for the command queue are compatible
     * with the properties that the device can handle for a command queue.
     */
    if ((properties & TIDevice_getCmdQueProps(device)) != properties) {
        if (errcode_ret != NULL) {
            *errcode_ret = CL_INVALID_QUEUE_PROPERTIES;
        }
        goto failure;
    }

    /* allocate a cl_command_queue object */
    queue = (cl_command_queue)Memory_calloc(NULL,
        sizeof(struct _cl_command_queue), sizeof(Int), NULL);

    if (queue == NULL) {
        if (errcode_ret != NULL) {
            *errcode_ret = CL_OUT_OF_HOST_MEMORY;
        }
        goto failure;
    }

    /* initialize command queue properties */
    queue->refCount = 1;
    queue->properties = properties;
    queue->context = context;
    queue->device = device;

    /* return success */
    return(queue);

failure:
    return(NULL);
}


/*
 *  ======== clRetainCommandQueue ========
 */
cl_int clRetainCommandQueue(cl_command_queue command_queue)
{
    /* TODO: use xdc.runtime.knl.Atomic_inc() */
    command_queue->refCount++;
    return(CL_SUCCESS);
}


/*
 *  ======== clReleaseCommandQueue ========
 */
cl_int clReleaseCommandQueue(cl_command_queue queue)
{
    /* TODO: use xdc.runtime.knl.Atomic_dec() */
    queue->refCount--;

    if (queue->refCount > 0) {
        return(CL_SUCCESS);
    }

    /* TODO: wait for all cmds in the cmd_queue to finish */
//  clFinish(queue);

    /* no longer in use, delete the object */
    Memory_free(NULL, (Ptr)queue, sizeof(struct _cl_command_queue));

    return(CL_SUCCESS);
}


/*
 *  ======== clGetCommandQueueInfo ========
 */
cl_int clGetCommandQueueInfo(
    cl_command_queue            command_queue,
    cl_command_queue_info       param_name,
    size_t                      param_value_size,
    void *                      param_value,
    size_t *                    param_value_size_ret
)
{
    int         fieldType;
    cl_uint     rvalUInt;

#define FT_CONTEXT      1
#define FT_DEVICE_ID    2
#define FT_UINT         3
#define FT_PROPERTIES   4

    switch (param_name) {
        case CL_QUEUE_CONTEXT:
            fieldType = FT_CONTEXT;
            break;
        case CL_QUEUE_DEVICE:
            fieldType = FT_DEVICE_ID;
            break;
        case CL_QUEUE_REFERENCE_COUNT:
            fieldType = FT_UINT;
            rvalUInt = command_queue->refCount;
            break;
        case CL_QUEUE_PROPERTIES:
            fieldType = FT_PROPERTIES;
            break;
        default:
            return(CL_INVALID_VALUE);
    }

    /* switch on param type, then copy param value into return buffer */
    switch (fieldType) {

        case FT_CONTEXT:  /* cl_context */
            if (param_value != NULL) {
                if (param_value_size < sizeof(cl_context)) {
                    return(CL_INVALID_VALUE);
                }
                *(cl_context *)param_value = command_queue->context;
            }
            if (param_value_size_ret != NULL) {
                *param_value_size_ret = sizeof(cl_context);
            }
            break;

        case FT_DEVICE_ID:  /* cl_device_id */
            if (param_value != NULL) {
                if (param_value_size < sizeof(cl_device_id)) {
                    return(CL_INVALID_VALUE);
                }
                *(cl_device_id *)param_value = command_queue->device;
            }
            if (param_value_size_ret != NULL) {
                *param_value_size_ret = sizeof(cl_device_id);
            }
            break;

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

        case FT_PROPERTIES:  /* (properties) */
            if (param_value != NULL) {
                if (param_value_size < sizeof(cl_command_queue_properties)) {
                    return(CL_INVALID_VALUE);
                }
                *(cl_command_queue_properties *)param_value =
                    command_queue->properties;
            }
            if (param_value_size_ret != NULL) {
                *param_value_size_ret = sizeof(cl_command_queue_properties);
            }
            break;
    }

    return(CL_SUCCESS);
}


/*
 *  ======== clEnqueueTask ========
 */
cl_int clEnqueueTask(
    cl_command_queue    command_queue,
    cl_kernel           kernel,
    cl_uint             num_events_in_wait_list,
    const cl_event *    event_wait_list,
    cl_event *          event
)
{
    Int                 status;
    cl_program          program;
    RcmClient_Handle    rcmClientH;
    UInt32              dataSize;
    RcmClient_Message * rcmMsg;
    Int                 argNum;
    Int                 i;
    UInt16              msgId;
    cl_context          context;


    /* TODO: add argument validation */

    /* TODO: add event_wait_list processing */

    /* get the program handle */
    program = TIKernel_getProgram(kernel);

    /* allocate an rcm message */
    rcmClientH = TIProgram_getRcmClientHandle(program);
    dataSize = TIProgram_getRcmMsgDataSize(program);

    status = RcmClient_alloc(rcmClientH, dataSize, &rcmMsg);

    if (status < 0) {
        rcmMsg = NULL;
        goto failure;
    }

    /* fill in the rcm message */
    rcmMsg->fxnIdx = TIProgram_getOpenCLSkelIdx(program);
    rcmMsg->data[1] = (UInt32)TIKernel_getFxnIdx(kernel);

    /* marshal the arguments */
    argNum = TIKernel_getNumArgs(kernel);

    for (i = 0; i < argNum; i++) {
        rcmMsg->data[i+2] = TIKernel_getArgVal(kernel, i);
    }

    /* if event object not requested, use RcmClient_execCmd() */
    if (event == NULL) {
        status = RcmClient_execCmd(rcmClientH, rcmMsg);

        if (status < 0) {
            goto failure;
        }
    }

    /* create an event object, use RcmClient_execNoWait() */
    else {
        clGetCommandQueueInfo(command_queue, CL_QUEUE_CONTEXT,
            sizeof(cl_context), &context, NULL);
        *event = TIEvent_create(context, command_queue, CL_COMMAND_TASK,
                (void *)rcmClientH);

        if (*event == NULL) {
            goto failure;
        }

        status = RcmClient_execNoWait(rcmClientH, rcmMsg, &msgId);

        if (status < 0) {
            goto failure;
        }

        /* store msgId in event object for future delivery notification */
        TIEvent_setMsgId(*event, (cl_uint)msgId);
    }

    return(CL_SUCCESS);

failure:
    /* TODO free the rcm message */

    /* return proper error code */
    return(-1);
}
/*
 *  @(#) ti.sdo.opencl; 1, 0, 0,4; 2-22-2012 18:09:26; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

