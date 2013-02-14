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
 *  ======== TIDevice.h ========
 */

#ifndef ti_sdo_opencl_TIDevice__include
#define ti_sdo_opencl_TIDevice__include

#include <CL/cl.h>

#if defined (__cplusplus)
extern "C" {
#endif

typedef struct {
    int             length;
    cl_device_id *  elem;
} ti_sdo_opencl_DeviceArray;

extern ti_sdo_opencl_DeviceArray ti_sdo_opencl_Devices;


/* TI extensions */

cl_command_queue_properties TIDevice_getCmdQueProps(cl_device_id device);
// cl_device_id TIDevice_getDeviceType(cl_device_type type, cl_device_id next);
cl_platform_id  TIDevice_getPlatform(cl_device_id device);
cl_device_type  TIDevice_getType(cl_device_id device);
cl_bool         TIDevice_isAvailable(cl_device_id device);


#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */
#endif /* ti_sdo_opencl_TIDevice__include */




#ifdef  ti_sdo_opencl_TIDevice__private
#ifndef ti_sdo_opencl_TIDevice__private_included
#define ti_sdo_opencl_TIDevice__private_included

#if defined (__cplusplus)
extern "C" {
#endif

struct _cl_device_id
{
    cl_device_type              type;
    cl_uint                     vendor_id;
    cl_uint                     max_compute_units;
    cl_uint                     max_work_item_dimensions;
    size_t                      max_work_item_sizes[3];
    size_t                      max_work_group_size;
    cl_uint                     preferred_vector_width_char;
    cl_uint                     preferred_vector_width_short;
    cl_uint                     preferred_vector_width_int;
    cl_uint                     preferred_vector_width_long;
    cl_uint                     preferred_vector_width_float;
    cl_uint                     preferred_vector_width_double;
    cl_uint                     max_clock_frequency;
    cl_uint                     address_bits;
    cl_ulong                    max_mem_alloc_size;
    cl_bool                     image_support;
    cl_uint                     max_read_image_args;
    cl_uint                     max_write_image_args;
    size_t                      image2d_max_width;
    size_t                      image2d_max_height;
    size_t                      image3d_max_width;
    size_t                      image3d_max_height;
    size_t                      image3d_max_depth;
    cl_uint                     max_samplers;
    size_t                      max_parameter_size;
    cl_uint                     mem_base_addr_align;
    cl_uint                     min_data_type_align_size;
    cl_device_fp_config         single_fp_config;
    cl_device_mem_cache_type    global_mem_cache_type;
    cl_uint                     global_mem_cacheline_size;
    cl_ulong                    global_mem_cache_size;
    cl_ulong                    global_mem_size;
    cl_ulong                    max_constant_buffer_size;
    cl_uint                     max_constant_args;
    cl_device_local_mem_type    local_mem_type;
    cl_ulong                    local_mem_size;
    cl_bool                     error_correction_support;
    size_t                      profiling_timer_resolution;
    cl_bool                     endian_little;
    cl_bool                     available;
    cl_bool                     compiler_available;
    cl_device_exec_capabilities execution_capabilities;
    cl_command_queue_properties queue_properties;
    cl_platform_id              platform;
    const char *                name;
    const char *                vendor;
    const char *                driver_version;
    const char *                profile;
    const char *                version;
    const char *                extensions;

#if 0
    class memory_system_impl*      memory_system;
    class device_connection_impl*  device_connection;
#endif
};


#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */

#endif  /* ti_sdo_opencl_TIDevice__private_included */
#endif  /* ti_sdo_opencl_TIDevice__private */
/*
 *  @(#) ti.sdo.opencl; 1, 0, 0,4; 2-22-2012 18:09:27; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

