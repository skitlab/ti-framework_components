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
 *  ======== CLContext.c ========
 */
#include <CL/cl.h>

#include <xdc/std.h>
#include <xdc/runtime/Memory.h>

#include "TIDevice.h"
#include "TIPlatform.h"

/* extend the OpenCL Context interface for friends */
#include "TIContext.h"

typedef void (*NotifyCB)(const char *, const void *, size_t, void *);

typedef struct {
    int                     length;
    cl_context_properties * elem;
} ContextPropertyArray;

struct _cl_context {
    cl_uint                     refCount;
    ContextPropertyArray        properties;
    ti_sdo_opencl_DeviceArray   devices;
    NotifyCB                    notifyCB;
    void *                      userData;
    void *                      heapH;
};


/*
 *  ======== clCreateContext ========
 */
cl_context clCreateContext(
    const cl_context_properties *   properties,
    cl_uint                         num_devices,
    const cl_device_id *            devices,
    void (*pfn_notify)(const char *, const void *, size_t, void *),
    void *                          user_data,
    cl_int *                        errcode_ret 
)
{
    cl_platform_id  selected_platform;
    cl_context      context;
    int             i;
    int             property_count = 0;

    /* validate input arguments */
    if ((num_devices == 0) ||(devices == NULL) ||
        ((pfn_notify == NULL) && (user_data != NULL))) {         
        if (errcode_ret != NULL) {
            *errcode_ret = CL_INVALID_VALUE;
        }
        return(NULL);
    }

    /* default to the platform of the first device specified */
    selected_platform = TIDevice_getPlatform(devices[0]);

    /* inspect the properties array */
    if (properties != NULL)
    {
        for (i = 0; properties[i] != 0; i += 2) {

            /* if a platform is specified in properties, use it */
            if (properties[i] == CL_CONTEXT_PLATFORM) {
                selected_platform = (cl_platform_id)properties[i+1];
            }

            /* must be an invalid property */
            else {
                if (errcode_ret != NULL) {
                    *errcode_ret = CL_INVALID_VALUE;
                }
                return(NULL);
            }
        }
        property_count = i;
    }

    /* verify that each device is in the platform and available */
    for (i = 0; i < num_devices; i++)
    {
        if (TIDevice_getPlatform(devices[i]) != selected_platform) {
            if (errcode_ret != NULL) {
                *errcode_ret = CL_INVALID_DEVICE;
            }
            return(NULL);
        }

        if (!TIDevice_isAvailable(devices[i])) {
            if (errcode_ret != NULL) {
                *errcode_ret = CL_DEVICE_NOT_AVAILABLE;
            }
            return(NULL);
        }
    }

    /* allocate a cl_context object */
    context = (cl_context)Memory_alloc(NULL, sizeof(struct _cl_context),
        sizeof(Int), NULL);

    if (context == NULL) {
        if (errcode_ret != NULL) {
            *errcode_ret = CL_OUT_OF_HOST_MEMORY;
        }
        goto failure;
    }

    /* initialize context */
    context->refCount = 1;
    context->notifyCB = pfn_notify;
    context->userData = user_data;
    context->heapH = TIPlatform_getHeapHandle(selected_platform);

    /* copy context create properties */
    if (properties != NULL)
    {
        context->properties.length = property_count;
        context->properties.elem = (cl_context_properties *)
            Memory_alloc(NULL, property_count * sizeof(cl_context_properties),
                sizeof(Int), NULL);

        if (context->properties.elem == NULL) {
            if (errcode_ret != NULL) {
                *errcode_ret = CL_OUT_OF_HOST_MEMORY;
            }
            goto failure;
        }

        for (i = 0; i < property_count; i++) {
            context->properties.elem[i] = properties[i];
        }
    }
    else {
        context->properties.length = 0;
        context->properties.elem = NULL;
    }

    /* copy devices references */
    context->devices.length = num_devices;
    context->devices.elem =
        (cl_device_id *)Memory_alloc(NULL, num_devices * sizeof(cl_device_id),
            sizeof(Int), NULL);

    if (context->devices.elem == NULL) {
        if (errcode_ret != NULL) {
            *errcode_ret = CL_OUT_OF_HOST_MEMORY;
        }
        goto failure;
    }

    for (i = 0; i < num_devices; i++) {
        context->devices.elem[i] = devices[i];
    }

    /* return success */
    if (errcode_ret != NULL) {
        *errcode_ret = CL_SUCCESS;
    }
    return(context);

failure:
    if ((context != NULL) && (context->devices.elem != NULL)) {
        Memory_free(NULL, (Ptr)(context->devices.elem),
            context->devices.length * sizeof(cl_device_id));
    }
    if ((context != NULL) && (context->properties.elem != NULL)) {
        Memory_free(NULL, (Ptr)(context->properties.elem),
            context->properties.length * sizeof(cl_context_properties));
    }
    if (context != NULL) {
        Memory_free(NULL, context, sizeof(struct _cl_context));
    }

    return(NULL);
}

/*
 *  ======== clCreateContextFromType ========
 */
cl_context clCreateContextFromType(
    const cl_context_properties *   properties,
    cl_device_type                  device_type,
    void (*pfn_notify)(const char *, const void *, size_t, void *),
    void *                          user_data,
    cl_int *                        errcode_ret
)
{
    cl_uint         num_devices;
    cl_device_id *  devices;
    cl_platform_id  platform;
    cl_context      context;
    cl_int          rstat;
    int             p;

    /* default to the first platform in the platforms array */
    platform = ti_sdo_opencl_Platforms.elem[0];

    /* inspect the properties array */
    if (properties != NULL) {

        for (p = 0; properties[p] != 0; p += 2) {

            /* if a platform is specified in properties, use it */
            if (properties[p] == CL_CONTEXT_PLATFORM) {
                platform = (cl_platform_id)properties[p+1];
            }

            /* must be an invalid property */
            else {
                if (errcode_ret != NULL) {
                    *errcode_ret = CL_INVALID_VALUE;
                }
                return(NULL);
            }
        }
    }

    /* find out how many devices of given type are available */
    rstat = clGetDeviceIDs(platform, device_type, 0, NULL, &num_devices);

    if (num_devices == 0) {
        if (errcode_ret != NULL) {
            *errcode_ret = CL_INVALID_DEVICE;
        }
        return(NULL);
    }

    devices = (cl_device_id*)Memory_alloc(NULL,
        num_devices * sizeof(cl_device_id), sizeof(Int), NULL);

    if (devices == NULL) {
        if (errcode_ret != NULL) {
            *errcode_ret = CL_OUT_OF_HOST_MEMORY;
        }
        return(NULL);
    }

    /* get the device ids */
    rstat = clGetDeviceIDs(platform, device_type, num_devices, devices, NULL);

    if (rstat != CL_SUCCESS) {
        if (errcode_ret != NULL) {
            *errcode_ret = rstat;
        }
        Memory_free(NULL, (Ptr)devices, num_devices * sizeof(cl_device_id));
        return(NULL);
    }

    /* create the context */
    context = clCreateContext(properties, num_devices, devices,
        pfn_notify, user_data, errcode_ret);

    /* free the devices array created above */
    Memory_free(NULL, (Ptr)devices, num_devices * sizeof(cl_device_id));

    return(context);
}


/*
 *  ======== clRetainContext ========
 */
cl_int clRetainContext(cl_context context)
{
    /* TODO: use xdc.runtime.knl.Atomic_inc() */
    context->refCount++;
    return(CL_SUCCESS);
}


/*
 *  ======== clReleaseContext ========
 */
cl_int clReleaseContext(cl_context context)
{
    /* TODO: use xdc.runtime.knl.Atomic_dec() */
    context->refCount--;

    if (context->refCount > 0) {
        return(CL_SUCCESS);
    }

    /* no longer in use, delete the context */
    Memory_free(NULL, (Ptr)(context->devices.elem),
        context->devices.length * sizeof(cl_device_id));

    if (context->properties.elem != NULL) {
        Memory_free(NULL, (Ptr)(context->properties.elem),
            context->properties.length * sizeof(cl_context_properties));
    }

    Memory_free(NULL, context, sizeof(struct _cl_context));

    return(CL_SUCCESS);
}


/*
 *  ======== clGetContextInfo ========
 */
cl_int clGetContextInfo(
    cl_context      context,
    cl_context_info param_name,
    size_t          param_value_size,
    void *          param_value,
    size_t *        param_value_size_ret
)
{
    cl_device_id *          device;
    cl_context_properties * property;
    cl_uint                 rvalUInt;
    int                     i, fieldType;
    size_t                  size;

#define FT_UINT         1
#define FT_DEVICES      2
#define FT_PROPERTIES   3

    switch (param_name) {
        case CL_CONTEXT_REFERENCE_COUNT:
            fieldType = FT_UINT;
            rvalUInt = context->refCount;
            break;
        case CL_CONTEXT_NUM_DEVICES:
            fieldType = FT_UINT;
            rvalUInt = context->devices.length;
            break;
        case CL_CONTEXT_DEVICES:
            fieldType = FT_DEVICES;
            break;
        case CL_CONTEXT_PROPERTIES:
            fieldType = FT_PROPERTIES;
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

        case FT_DEVICES:  /* (devices) */
            size = context->devices.length * sizeof(cl_device_id);
            if (param_value != NULL) {
                if (param_value_size < size) {
                    return(CL_INVALID_VALUE);
                }
                device = (cl_device_id *)param_value;
                for (i = 0; i < context->devices.length; i++) {
                    *device++ = context->devices.elem[i];
                }
            }
            if (param_value_size_ret != NULL) {
                *param_value_size_ret = size;
            }
            break;

        case FT_PROPERTIES:  /* (properties) */
            size = context->properties.length * sizeof(cl_context_properties);
            if (param_value != NULL) {
                if (param_value_size < size) {
                    return(CL_INVALID_VALUE);
                }
                property = (cl_context_properties *)param_value;
                for (i = 0; i < context->properties.length; i++) {
                    *property++ = context->properties.elem[i];
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
 *  ======== TIContext_getHeapHandle ========
 */
void *TIContext_getHeapHandle(cl_context context)
{
    return(context->heapH);
}


/*
 *  ======== TIContext_hasDevice ========
 */
cl_bool TIContext_hasDevice(cl_context context, cl_device_id device)
{
    int i;

    for (i = 0; i < context->devices.length; i++) {
        if (context->devices.elem[i] == device) {
            return(CL_TRUE);
        }
    }

    return(CL_FALSE);
}
/*
 *  @(#) ti.sdo.opencl; 1, 0, 0,4; 2-22-2012 18:09:26; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

