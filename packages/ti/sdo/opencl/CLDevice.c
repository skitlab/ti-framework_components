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
 *  ======== CLDevice.c ========
 */

#include <string.h>

#include <CL/cl.h>

#define ti_sdo_opencl_TIDevice__private
#include "TIDevice.h"


/*
 *  ======== clGetDeviceInfo ========
 */
cl_int clGetDeviceInfo(
    cl_device_id        device,
    cl_device_info      param_name,
    size_t              param_value_size,
    void *              param_value,
    size_t *            param_value_size_ret
)
{
    int             i;
    cl_uint         rvalUInt;
    int             fieldType;
    const char *    rvalStr;
    size_t *        workItemSize;
    size_t          rvalSizeT;
    cl_ulong        rvalULong;

    switch (param_name)
    {
        case CL_DEVICE_TYPE:
            fieldType = 1;
            break;
        case CL_DEVICE_VENDOR_ID:
            fieldType = 2;
            rvalUInt = device->vendor_id;
            break;
        case CL_DEVICE_MAX_COMPUTE_UNITS:
            fieldType = 2;
            rvalUInt = device->max_compute_units;
            break;
        case CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS:
            fieldType = 2;
            rvalUInt = device->max_work_item_dimensions;
            break;
        case CL_DEVICE_MAX_WORK_ITEM_SIZES:
            fieldType = 4;
            break;
        case CL_DEVICE_MAX_WORK_GROUP_SIZE: 
            fieldType = 5;
            rvalSizeT = device->max_work_group_size;
            break;
        case CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR:
            fieldType = 2;
            rvalUInt = device->preferred_vector_width_char;
            break;
        case CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT:
            fieldType = 2;
            rvalUInt = device->preferred_vector_width_short;
            break;
        case CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT:
            fieldType = 2;
            rvalUInt = device->preferred_vector_width_int;
            break;
        case CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG:
            fieldType = 2;
            rvalUInt = device->preferred_vector_width_long;
            break;
        case CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT:
            fieldType = 2;
            rvalUInt = device->preferred_vector_width_float;
            break;
        case CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE: 
            fieldType = 2;
            rvalUInt = device->preferred_vector_width_double;
            break;
        case CL_DEVICE_MAX_CLOCK_FREQUENCY:
            fieldType = 2;
            rvalUInt = device->max_clock_frequency;
            break;
        case CL_DEVICE_ADDRESS_BITS:
            fieldType = 2;
            rvalUInt = device->address_bits;
            break;
        case CL_DEVICE_MAX_MEM_ALLOC_SIZE:
            fieldType = 6;
            rvalULong = device->max_mem_alloc_size;
            break;
#if 0
        case CL_DEVICE_IMAGE_SUPPORT:        return aret(image_support);
        case CL_DEVICE_MAX_READ_IMAGE_ARGS:  return aret(max_read_image_args);
        case CL_DEVICE_MAX_WRITE_IMAGE_ARGS: return aret(max_write_image_args);
        case CL_DEVICE_IMAGE2D_MAX_WIDTH:    return aret(image2d_max_width);
        case CL_DEVICE_IMAGE2D_MAX_HEIGHT:   return aret(image2d_max_height);
        case CL_DEVICE_IMAGE3D_MAX_WIDTH:    return aret(image3d_max_width);
        case CL_DEVICE_IMAGE3D_MAX_HEIGHT:   return aret(image3d_max_height);
        case CL_DEVICE_IMAGE3D_MAX_DEPTH:    return aret(image3d_max_depth);
        case CL_DEVICE_MAX_SAMPLERS:         return aret(max_samplers);
        case CL_DEVICE_MAX_PARAMETER_SIZE:   return aret(max_parameter_size);
        case CL_DEVICE_MEM_BASE_ADDR_ALIGN:  return aret(mem_base_addr_align);

        case CL_DEVICE_MIN_DATA_TYPE_ALIGN_SIZE:
                return aret(min_data_type_align_size);

        case CL_DEVICE_SINGLE_FP_CONFIG: return aret(single_fp_config);

        case CL_DEVICE_GLOBAL_MEM_CACHE_TYPE:
                return aret(global_mem_cache_type);

        case CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE:
                return aret(global_mem_cacheline_size);

        case CL_DEVICE_GLOBAL_MEM_CACHE_SIZE:
                return aret(global_mem_cache_size);

        case CL_DEVICE_GLOBAL_MEM_SIZE: return aret(global_mem_size);

        case CL_DEVICE_MAX_CONSTANT_BUFFER_SIZE:
                return aret(max_constant_buffer_size);

        case CL_DEVICE_MAX_CONSTANT_ARGS: return aret(max_constant_args);
        case CL_DEVICE_LOCAL_MEM_TYPE:    return aret(local_mem_type);
        case CL_DEVICE_LOCAL_MEM_SIZE:    return aret(local_mem_size);

        case CL_DEVICE_ERROR_CORRECTION_SUPPORT:
                return aret(error_correction_support);

        case CL_DEVICE_PROFILING_TIMER_RESOLUTION:
                return aret(profiling_timer_resolution);

        case CL_DEVICE_ENDIAN_LITTLE:      return aret(endian_little);
        case CL_DEVICE_AVAILABLE:          return aret(available);
        case CL_DEVICE_COMPILER_AVAILABLE: return aret(compiler_available);

        case CL_DEVICE_EXECUTION_CAPABILITIES:
                return aret(execution_capabilities);

        case CL_DEVICE_QUEUE_PROPERTIES:   return aret(queue_properties);
        case CL_DEVICE_PLATFORM:           return aret(platform);
#endif
        case CL_DEVICE_NAME:
            fieldType = 3;
            rvalStr = device->name;
            break;
        case CL_DEVICE_VENDOR:
            fieldType = 3;
            rvalStr = device->vendor;
            break;
        case CL_DRIVER_VERSION:
            fieldType = 3;
            rvalStr = device->driver_version;
            break;
        case CL_DEVICE_PROFILE:
            fieldType = 3;
            rvalStr = device->profile;
            break;
        case CL_DEVICE_VERSION:
            fieldType = 3;
            rvalStr = device->version;
            break;
        case CL_DEVICE_EXTENSIONS:
            fieldType = 3;
            rvalStr = device->extensions;
            break;

        default:
            return(CL_INVALID_VALUE);
    }

    /* switch on param type, then copy param value into return buffer */
    switch (fieldType) {

        case 1:  /* (cl_device_type type) */
            if (param_value != NULL) {
                if (param_value_size < sizeof(cl_device_type)) {
                    return(CL_INVALID_VALUE);
                }
                *(cl_device_type *)param_value = device->type;
            }
            if (param_value_size_ret != NULL) {
                *param_value_size_ret = sizeof(cl_device_type);
            }
            break;

        case 2:  /* (cl_uint) */
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

        case 3:  /* (const char *) */
            if (param_value != NULL) {
                if (param_value_size < (strlen(rvalStr) + 1)) {
                    return(CL_INVALID_VALUE);
                }
                strcpy(param_value, rvalStr);
            }
            if (param_value_size_ret != NULL) {
                *param_value_size_ret = strlen(rvalStr) + 1;
            }
            break;

        case 4:  /* (size_t max_work_item_sizes[]) */
            if (param_value != NULL) {
                if (param_value_size < sizeof(device->max_work_item_sizes)) {
                    return(CL_INVALID_VALUE);
                }
                workItemSize = (size_t *)param_value;
                for (i = 0; i < device->max_work_item_dimensions; i++) {
                    *workItemSize++ = device->max_work_item_sizes[i];
                }
            }
            if (param_value_size_ret != NULL) {
                *param_value_size_ret = sizeof(device->max_work_item_sizes);
            }
            break;

        case 5:  /* (size_t) */
            if (param_value != NULL) {
                if (param_value_size < sizeof(size_t)) {
                    return(CL_INVALID_VALUE);
                }
                *(size_t *)param_value = rvalSizeT;
            }
            if (param_value_size_ret != NULL) {
                *param_value_size_ret = sizeof(size_t);
            }
            break;

        case 6:  /* (cl_ulong) */
            if (param_value != NULL) {
                if (param_value_size < sizeof(cl_ulong)) {
                    return(CL_INVALID_VALUE);
                }
                *(cl_ulong *)param_value = rvalULong;
            }
            if (param_value_size_ret != NULL) {
                *param_value_size_ret = sizeof(cl_ulong);
            }
            break;
    }

    return(CL_SUCCESS);
}


/*
 *  ======== TIDevice_getCmdQueProps ========
 */
cl_command_queue_properties TIDevice_getCmdQueProps(cl_device_id device)
{
    return(device->queue_properties);
}


#if 0
/*
 *  ======== TIDevice_getDeviceType ========
 */
cl_device_id TIDevice_getDeviceType(cl_device_type type, cl_device_id next)
{
    int i = 0;

    if (next != NULL) {
        while (i < ti_sdo_opencl_Devices.length) {
            if (ti_sdo_opencl_Devices.elem[i++] == next) {
                break;
            }
        }
    }

    if (i == ti_sdo_opencl_Devices.length) {
        return(NULL);
    }

    while (i < ti_sdo_opencl_Devices.length) {
        if (TIDevice_getType(ti_sdo_opencl_Devices.elem[i]) & type) {
            return(ti_sdo_opencl_Devices.elem[i]);
        }
        i++;
    }

    return(NULL);
}
#endif


/*
 *  ======== TIDevice_getPlatform ========
 */
cl_platform_id TIDevice_getPlatform(cl_device_id device)
{
    return(device->platform);
}


/*
 *  ======== TIDevice_getType ========
 */
cl_device_type TIDevice_getType(cl_device_id device)
{
    return(device->type);
}


/*
 *  ======== TIDevice_isAvailable ========
 */
cl_bool TIDevice_isAvailable(cl_device_id device)
{
    return(device->available);
}
/*
 *  @(#) ti.sdo.opencl; 1, 0, 0,4; 2-22-2012 18:09:26; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

