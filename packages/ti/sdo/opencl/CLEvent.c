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
 *  ======== CLEvent.c ========
 */
#include <CL/cl.h>

#include <xdc/std.h>
#include <xdc/runtime/Memory.h>
#include <ti/sdo/rcm/RcmClient.h>


#define ti_sdo_opencl_TIEvent__private
#include "TIEvent.h"


/*
 *  ======== clWaitForEvents ========
 */
cl_int clWaitForEvents(
    cl_uint             num_events,
    const cl_event *    event_list
)
{
    cl_uint     i;
    cl_int      status;


    /* validate arguments */
    if (num_events == 0) {
        return(CL_INVALID_VALUE);
    }

    /* validate the event objects */
    for (i = 1; i < num_events; i++) {
        if (event_list[0]->context != event_list[i]->context) {
            return(CL_INVALID_CONTEXT);
        }
    }

    /* wait for each event object to complete */
    for (i = 0; i < num_events; i++) {
        status = TIEvent_wait(event_list[i]);

        if (status < 0) {
            /* TODO */
        }
    }

    return(CL_SUCCESS);
}


/*
 *  ======== clGetEventInfo ========
 */
cl_int clGetEventInfo(
    cl_event            event,
    cl_event_info       param_name,
    size_t              param_value_size,
    void *              param_value,
    size_t *            param_value_size_ret
)
{
#if 0
    if (!verify(event)) return CL_INVALID_EVENT;
    return event->info(param_name, param_value_size, param_value,
                       param_value_size_ret);
#else
    /* TODO */
    return(-1);
#endif
}
                            

/*
 *  ======== clRetainEvent ========
 */
cl_int clRetainEvent(cl_event event)
{
//  if (!verify(event)) return CL_INVALID_EVENT;

    /* TODO: use xdc.runtime.knl.Atomic_inc() */
    event->refCount++;
    return(CL_SUCCESS);
}


/*
 *  ======== clReleaseEvent ========
 */
cl_int clReleaseEvent(cl_event event)
{

//  if (!verify(event)) return CL_INVALID_EVENT;

    /* TODO: use xdc.runtime.knl.Atomic_dec() */
    event->refCount--;

    if (event->refCount > 0) {
        return(CL_SUCCESS);
    }

    /* no longer in use, delete the object */
    Memory_free(NULL, (Ptr)event, sizeof(struct _cl_event));

    return(CL_SUCCESS);
}


/*
 *  ======== clgetEventProfilingInfo ========
 */
cl_int clGetEventProfilingInfo(
    cl_event            event,
    cl_profiling_info   param_name,
    size_t              param_value_size,
    void *              param_value,
    size_t *            param_value_size_ret
)
{
#if 0
    if (!verify(event)) return CL_INVALID_EVENT;
    return event->profile_info(param_name, param_value_size, param_value,
                                 param_value_size_ret);
#endif
    /* TODO */
    return(-1);
}


/*
 *  ======== TIEvent_create ========
 */
cl_event TIEvent_create(
    cl_context          context,
    cl_command_queue    queue,
    cl_command_type     cmdType,
    void *              rcmClientH)
{
    cl_event    event;


    /* allocate a cl_event object */
    event = (cl_event)Memory_alloc(NULL, sizeof(struct _cl_event),
        sizeof(Int), NULL);

    if (event == NULL) {
        goto failure;
    }

    /* initialize cl_event object */
    event->refCount = 1;
    event->context = context;
    event->queue = queue;
    event->cmdType = cmdType;
    event->status = CL_QUEUED;
    event->rcmClientH = rcmClientH;
    event->msgId = 0;

    /* return success */
    return(event);

failure:
    return(NULL);
}


/*
 *  ======== TIEvent_setMsgId ========
 */
void TIEvent_setMsgId(cl_event event, cl_int msgId)
{
    event->msgId = msgId;
}


/*
 *  ======== TIEvent_wait ========
 */
cl_int TIEvent_wait(cl_event event)
{
    RcmClient_Handle    rcmH = (RcmClient_Handle)(event->rcmClientH);
    UInt16              msgId = (UInt16)(0xFF & (UInt)(event->msgId));
    RcmClient_Message * msg;
    Int                 status;


    /* check if event has already completed */
    if (event->status == CL_COMPLETE) {
        return(CL_SUCCESS);
    }

    /* check if event terminated with error */
    /* TODO */

    /* event still pending, wait for command to complete */
    status = RcmClient_waitUntilDone(rcmH, msgId, &msg);

    if (status < 0) {
        /* TODO */
    }

    /* extract any return value from message? */
    /* TODO */

    /* free the rcm message */
    RcmClient_free(rcmH, msg);

    event->status = CL_COMPLETE;

    return(CL_COMPLETE);
}
/*
 *  @(#) ti.sdo.opencl; 1, 0, 0,4; 2-22-2012 18:09:26; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

