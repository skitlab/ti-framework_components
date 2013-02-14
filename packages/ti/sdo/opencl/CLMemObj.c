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
 *  ======== CLMemObj.c ========
 */
#include <CL/cl.h>

#include <xdc/std.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/runtime/Memory.h>

#if defined(OpenCL_ti_sdo_ipc)

#elif defined(OpenCL_ti_syslink)
#include "CLMemObj_syslink.h"

#else
#error "undefined ipc binding"
#endif

#include "TIContext.h"


#define ti_sdo_opencl_TIMem__private
#include "TIMem.h"


/*
 *  ======== clCreateBuffer ========
 */
cl_mem clCreateBuffer(
    cl_context          context,
    cl_mem_flags        flags,
    size_t              size,
    void *              host_ptr,
    cl_int *            errcode_ret
)
{
    cl_mem              buffer;

    /* allocate a cl_mem object */
    buffer = (cl_mem)Memory_alloc(NULL, sizeof(struct _cl_mem),
        sizeof(Int), NULL);

    if (buffer == NULL) {
        if (errcode_ret != NULL) {
            *errcode_ret = CL_OUT_OF_HOST_MEMORY;
        }
        goto failure;
    }

    /* initialize cl_mem object */
    buffer->refCount = 1;
    buffer->object_type = CL_MEM_OBJECT_BUFFER;
    buffer->flags = flags;
    buffer->size = size;
    buffer->heapH = TIContext_getHeapHandle(context);

    /* use host pre-allocated memory */
    if (flags & CL_MEM_USE_HOST_PTR) {
        buffer->host_ptr = host_ptr;
        buffer->storage = host_ptr;
    }
    /* allocate host accessible memory */
    else if (flags & CL_MEM_ALLOC_HOST_PTR) {
        buffer->host_ptr = NULL;

#if defined(OpenCL_ti_sdo_ipc)
        /* TODO use error block? */
        buffer->storage = (void *)Memory_alloc(
            (IHeap_Handle)(buffer->heapH), size, sizeof(int), NULL);
#elif defined(OpenCL_ti_syslink)
        buffer->storage = (void *)ti_syslink_Memory_alloc(
            (Ptr)(buffer->heapH), size, sizeof(int), NULL);
#endif

        if (buffer->storage == NULL) {
            if (errcode_ret != NULL) {
                *errcode_ret = CL_OUT_OF_HOST_MEMORY;
            }
            goto failure;
        }
    }

    /* not yet implemented */
    else {
        /* TODO */
        if (errcode_ret != NULL) {
            *errcode_ret = CL_OUT_OF_RESOURCES;
        }
        goto failure;
    }

    /* return success */
    if (errcode_ret != NULL) {
        *errcode_ret = CL_SUCCESS;
    }
    return(buffer);

failure:
    if ((buffer != NULL) &&
        (buffer->storage != NULL) && (flags & CL_MEM_ALLOC_HOST_PTR)) {

#if defined(OpenCL_ti_sdo_ipc)
        Memory_free((IHeap_Handle)(buffer->heapH), (Ptr)(buffer->storage),
            (SizeT)(buffer->size));
#elif defined(OpenCL_ti_syslink)
        ti_syslink_Memory_free((Ptr)(buffer->heapH), (Ptr)(buffer->storage),
            (SizeT)(buffer->size));
#endif
    }

    if (buffer != NULL) {
        Memory_free(NULL, (Ptr)buffer, (SizeT)(buffer->size));
    }

    return(NULL);
}


/*
 *  ======== clRetainMemObject ========
 */
cl_int clRetainMemObject(cl_mem memobj)
{
    /* TODO: use xdc.runtime.knl.Atomic_inc() */
    memobj->refCount++;
    return(CL_SUCCESS);
}


/*
 *  ======== clReleaseMemObject ========
 */
cl_int clReleaseMemObject(cl_mem memobj)
{
    /* TODO: wait for all queued cmds that use memobj to finish */

    /* TODO: use xdc.runtime.knl.Atomic_dec() */
    memobj->refCount--;

    if (memobj->refCount > 0) {
        return(CL_SUCCESS);
    }

    /* nothing to free if host pre-allocated memory */
    if (memobj->flags & CL_MEM_USE_HOST_PTR) {
        memobj->host_ptr = NULL;
        memobj->storage = NULL;
    }

    /* free host accessible memory */
    else if (memobj->flags & CL_MEM_ALLOC_HOST_PTR) {
#if defined(OpenCL_ti_sdo_ipc)
        Memory_free((IHeap_Handle)(memobj->heapH),
            (Ptr)(memobj->storage), (SizeT)(memobj->size));
#elif defined(OpenCL_ti_syslink)
        ti_syslink_Memory_free((Ptr)(memobj->heapH), (Ptr)(memobj->storage),
            (SizeT)(memobj->size));
#endif
        memobj->storage = NULL;
    }

    /* not yet implemented */
    else {
        /* raise an error */
    }

    Memory_free(NULL, (Ptr)memobj, (SizeT)(memobj->size));

    return(CL_SUCCESS);
}


#if 0
cl_int clGetMemObjectInfo(
        cl_mem           memobj,
        cl_mem_info      param_name,
        size_t           param_value_size,
        void *           param_value,
        size_t *         param_value_size_ret
)
{
    if (!verify(memobj)) return CL_INVALID_MEM_OBJECT;
    return memobj->info(param_name, param_value_size, param_value, 
                        param_value_size_ret);
}

cl_int clEnqueueReadBuffer(
        cl_command_queue    command_queue,
        cl_mem              buffer,
        cl_bool             blocking_read,
        size_t              offset,
        size_t              cb,
        void *              ptr,
        cl_uint             num_events_in_wait_list,
        const cl_event *    event_wait_list,
        cl_event *          event
)
{
    if (!verify(command_queue))   return CL_INVALID_COMMAND_QUEUE;
    if (!verify(buffer))          return CL_INVALID_MEM_OBJECT;

    if (command_queue->get_context() != buffer->get_context()) 
        return CL_INVALID_CONTEXT;

    if (ptr == NULL || !buffer->verify_bounds(offset, cb))
        return CL_INVALID_VALUE;

    if ((event_wait_list == NULL && num_events_in_wait_list > 0)  ||
        (event_wait_list != NULL && num_events_in_wait_list == 0))
        return CL_INVALID_EVENT_WAIT_LIST;

    for (cl_uint i = 0; i < num_events_in_wait_list; ++i)
    {
        if (!verify(event_wait_list[i]))
            return CL_INVALID_EVENT_WAIT_LIST;

        if (command_queue->get_context() != 
            event_wait_list[i]->get_queue()->get_context())
            return CL_INVALID_CONTEXT;
    }

    return command_queue->add_copy_command(event, num_events_in_wait_list, 
                                           event_wait_list,
                                           blocking_read, 
                                           CL_COMMAND_READ_BUFFER, ptr, 
                                           (char *)buffer->get_storage()+offset,
                                           cb);
}
                            
cl_int clEnqueueWriteBuffer(
        cl_command_queue   command_queue,
        cl_mem             buffer,
        cl_bool            blocking_write,
        size_t             offset,
        size_t             cb,
        const void *       ptr,
        cl_uint            num_events_in_wait_list,
        const cl_event *   event_wait_list,
        cl_event *         event
)
{
    if (!verify(command_queue))   return CL_INVALID_COMMAND_QUEUE;
    if (!verify(buffer))          return CL_INVALID_MEM_OBJECT;

    if (command_queue->get_context() != buffer->get_context()) 
        return CL_INVALID_CONTEXT;

    if (ptr == NULL || !buffer->verify_bounds(offset, cb))
        return CL_INVALID_VALUE;

    if ((event_wait_list == NULL && num_events_in_wait_list > 0)  ||
        (event_wait_list != NULL && num_events_in_wait_list == 0))
        return CL_INVALID_EVENT_WAIT_LIST;

    for (cl_uint i = 0; i < num_events_in_wait_list; ++i)
    {
        if (!verify(event_wait_list[i]))
            return CL_INVALID_EVENT_WAIT_LIST;

        if (command_queue->get_context() != 
            event_wait_list[i]->get_queue()->get_context())
            return CL_INVALID_CONTEXT;
    }

    return command_queue->add_copy_command(event, num_events_in_wait_list, 
                                           event_wait_list, blocking_write, 
                                           CL_COMMAND_WRITE_BUFFER,
                                           (char *)buffer->get_storage()+offset,
                                           ptr, cb);
}
                            
cl_int clEnqueueCopyBuffer(
        cl_command_queue    command_queue,
        cl_mem              src_buffer,
        cl_mem              dst_buffer,
        size_t              src_offset,
        size_t              dst_offset,
        size_t              cb,
        cl_uint             num_events_in_wait_list,
        const cl_event *    event_wait_list,
        cl_event *          event
)
{
    NOT_IMPLEMENTED_YET(__FUNCTION__);
    return 0;
}

void *clEnqueueMapBuffer(
        cl_command_queue command_queue,
        cl_mem           buffer,
        cl_bool          blocking_map,
        cl_map_flags     map_flags,
        size_t           offset,
        size_t           cb,
        cl_uint          num_events_in_wait_list,
        const cl_event * event_wait_list,
        cl_event *       event,
        cl_int *         errcode_ret
)
{
    NOT_IMPLEMENTED_YET(__FUNCTION__);
    return NULL;
}

cl_int clEnqueueUnmapMemObject(
        cl_command_queue  command_queue,
        cl_mem            memobj,
        void *            mapped_ptr,
        cl_uint           num_events_in_wait_list,
        const cl_event *  event_wait_list,
        cl_event *        event
)
{
    NOT_IMPLEMENTED_YET(__FUNCTION__);
    return 0;
}

static cl_int verify_buffer_flags(cl_mem_flags flags, void *host_ptr)
{
     cl_mem_flags rw_mask =
        (CL_MEM_READ_WRITE | CL_MEM_WRITE_ONLY | CL_MEM_READ_ONLY);

    cl_mem_flags host_ptr_mask =
        (CL_MEM_USE_HOST_PTR | CL_MEM_ALLOC_HOST_PTR | CL_MEM_COPY_HOST_PTR);

    switch (flags & rw_mask)
    {
        case 0: 
        case CL_MEM_READ_WRITE:
        case CL_MEM_WRITE_ONLY:
        case CL_MEM_READ_ONLY: break;

        default: return CL_INVALID_VALUE;
    }

    switch (flags & host_ptr_mask)
    {
        case 0:
        case CL_MEM_ALLOC_HOST_PTR:
            if (host_ptr) return CL_INVALID_HOST_PTR;
            break;

        case CL_MEM_USE_HOST_PTR:
        case CL_MEM_COPY_HOST_PTR:
        case CL_MEM_ALLOC_HOST_PTR | CL_MEM_COPY_HOST_PTR:
            if (!host_ptr) return CL_INVALID_HOST_PTR;
            break;

        default: return CL_INVALID_VALUE;
    }

    if (flags & ~(host_ptr_mask | rw_mask)) return CL_INVALID_VALUE;

    return CL_SUCCESS;
}
#endif
/*
 *  @(#) ti.sdo.opencl; 1, 0, 0,4; 2-22-2012 18:09:26; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

