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
 *  ======== Device.c ========
 */

#include <CL/cl.h>
#include <ti/sdo/opencl/TIPlatform.h>

#define ti_sdo_opencl_TIDevice__private
#include <ti/sdo/opencl/TIDevice.h>

//#include "ti_platform.h"
//#include "ti_device.h"
//#include "ti_defines.h"
//#include "p_memory_system_cmem.h"
//#include "p_memory_system_cpu.h"
//#include "p_device_connection_dsp.h"
//#include "p_device_connection_arm.h"
//#include "u_apiret.h"
//#include <sys/stat.h>


/* package symbols */
extern struct _cl_platform_id ti_sdo_opencl_platform_c6472_Platform;


#if 0
memory_system_cmem    static_memory_system_cmem;
memory_system_cpu     static_memory_system_cpu;
device_connection_dsp static_connection_dsp(0);
device_connection_arm static_connection_arm;
#endif

struct _cl_device_id ti_sdo_opencl_platform_c6472_Device_core0 = {
    CL_DEVICE_TYPE_CPU,                 // type;
    1,                                  // vendor_id;
    1,                                  // max_compute_units;
    3,                                  // max_work_item_dimensions
    {1,1,1},                            // max_work_item_sizes[];
    1,                                  // max_work_group_size;
    8,                                  // preferred_vector_width_char;
    4,                                  // preferred_vector_width_short;
    2,                                  // preferred_vector_width_int;
    1,                                  // preferred_vector_width_long;
    1,                                  // preferred_vector_width_float;
    0,                                  // preferred_vector_width_double;
    600,                                // max_clock_frequency (Mhz);
    32,                                 // address_bits;
    4 * 1024 * 1024,                    // max_mem_alloc_size (globalsz/4);  ???
    CL_FALSE,                           // image_support;
    0,                                  // max_read_image_args;
    0,                                  // max_write_image_args;
    0,                                  // image2d_max_width;
    0,                                  // image2d_max_height;
    0,                                  // image3d_max_width;
    0,                                  // image3d_max_height;
    0,                                  // image3d_max_depth;
    0,                                  // max_samplers;
    256,                                // max_parameter_size;               min
    64,                                 // mem_base_addr_align;
    1,                                  // min_data_type_align_size;
    CL_FP_ROUND_TO_NEAREST|CL_FP_INF_NAN, // single_fp_config;               min
    CL_NONE,                            // global_mem_cache_type;            ???
    0,                                  // global_mem_cacheline_size;        ???
    0,                                  // global_mem_cache_size;            ???
    16 * 1024 * 1024,                   // global_mem_size (bytes);          ???
    64 * 1024,                          // max_constant_buffer_size (bytes); min
    8,                                  // max_constant_args;                min
    CL_GLOBAL,                          // local_mem_type;                   ???
    16 * 1024,                          // local_mem_size (bytes);           min
    CL_FALSE,                           // error_correction_support;
    30517,                              // profiling_timer_resolution (ns); 
    CL_TRUE,                            // endian_little;
    CL_TRUE,                            // available;
    CL_FALSE,                           // compiler_available;
    CL_EXEC_KERNEL|CL_EXEC_NATIVE_KERNEL,// execution_capabilities;
    CL_QUEUE_PROFILING_ENABLE,          // queue_properties;
    &ti_sdo_opencl_platform_c6472_Platform, // platform;
    "ARM Cortex A8 CPU",                // name
    "Texas Instruments",                // vendor
    "0.1.0",                            // driver_version
    "EMBEDDED PROFILE",                 // profile
    "OpenCL 1.1",                       // version
    " "                                 // extensions

#if 0
    &static_memory_system_cpu,          // memory_system
    &static_connection_arm              // arm connection
#endif
};

struct _cl_device_id ti_sdo_opencl_platform_c6472_Device_core1 = {
    CL_DEVICE_TYPE_ACCELERATOR |        // type
        CL_DEVICE_TYPE_DEFAULT,
    1,                                  // vendor_id;
    1,                                  // max_compute_units;
    3,                                  // max_work_item_dimensions
    {1,1,1},                            // max_work_item_sizes[];
    1,                                  // max_work_group_size;
    8,                                  // preferred_vector_width_char;
    4,                                  // preferred_vector_width_short;
    2,                                  // preferred_vector_width_int;
    1,                                  // preferred_vector_width_long;
    1,                                  // preferred_vector_width_float;
    0,                                  // preferred_vector_width_double;
    430,                                // max_clock_frequency (Mhz);
    32,                                 // address_bits;
    4 * 1024 * 1024,                    // max_mem_alloc_size (globalsz/4);  ???
    CL_FALSE,                           // image_support;
    0,                                  // max_read_image_args;
    0,                                  // max_write_image_args;
    0,                                  // image2d_max_width;
    0,                                  // image2d_max_height;
    0,                                  // image3d_max_width;
    0,                                  // image3d_max_height;
    0,                                  // image3d_max_depth;
    0,                                  // max_samplers;
    256,                                // max_parameter_size;               min
    64,                                 // mem_base_addr_align;
    1,                                  // min_data_type_align_size;
    CL_FP_ROUND_TO_NEAREST|CL_FP_INF_NAN, // single_fp_config;               min
    CL_NONE,                            // global_mem_cache_type;            ???
    0,                                  // global_mem_cacheline_size;        ???
    0,                                  // global_mem_cache_size;            ???
    16 * 1024 * 1024,                   // global_mem_size (bytes);          ???
    64 * 1024,                          // max_constant_buffer_size (bytes); min
    8,                                  // max_constant_args;                min
    CL_GLOBAL,                          // local_mem_type;                   ???
    16 * 1024,                          // local_mem_size (bytes);           min
    CL_FALSE,                           // error_correction_support;
    30517,                              // profiling_timer_resolution (ns); 
    CL_TRUE,                            // endian_little;
    CL_TRUE,                            // available;
    CL_FALSE,                           // compiler_available;
    CL_EXEC_KERNEL,                     // execution_capabilities;
    CL_QUEUE_PROFILING_ENABLE,          // queue_properties;
    &ti_sdo_opencl_platform_c6472_Platform, // platform; TODO remove this
    "CORE1"                             // name
    "Texas Instruments",                // vendor
    "0.1.0",                            // driver_version
    "EMBEDDED PROFILE",                 // profile
    "OpenCL 1.1",                       // version
    " "                                 // extensions

#if 0
    &static_memory_system_cmem,         // memory_system
    &static_connection_dsp              // device_connection
#endif
};
/*
 *  @(#) ti.sdo.opencl.platforms.c6472; 1, 0, 0,4; 2-22-2012 18:09:29; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

