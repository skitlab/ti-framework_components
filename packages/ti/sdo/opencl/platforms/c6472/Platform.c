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
 *  ======== Platform.c ========
 */

#include <CL/cl.h>
#include <ti/sdo/opencl/TIPlatform.h>
#include <ti/sdo/opencl/TIDevice.h>


/* package symbols */
extern struct _cl_device_id ti_sdo_opencl_platform_c6472_Device_core0;
extern struct _cl_device_id ti_sdo_opencl_platform_c6472_Device_core1;

static cl_device_id DeviceAry[] = {
    &ti_sdo_opencl_platform_c6472_Device_core0,
    &ti_sdo_opencl_platform_c6472_Device_core1
};

struct _cl_platform_id ti_sdo_opencl_platform_c6472_Platform = {
    "EMBEDDED_PROFILE",                 // CL_PLATFORM_PROFILE
    "OpenCL 1.1",                       // CL_PLATFORM_VERSION
    "TI OMAP3",                         // CL_PLATFORM_NAME
    "Texas Instruments",                // CL_PLATFORM_VENDOR
    " ",                                // CL_PLATFORM_EXTENSIONS
    {                                   // devices
        sizeof(DeviceAry)/sizeof(cl_device_id),
        &DeviceAry[0]
    },
    NULL                                // heap handle
};

static cl_platform_id PlatformAry[] = {
    &ti_sdo_opencl_platform_c6472_Platform
};

/* define the public symbol for this module */
ti_sdo_opencl_PlatformArray ti_sdo_opencl_Platforms = {
    sizeof(PlatformAry) / sizeof(cl_platform_id),
    &PlatformAry[0]
};
/*
 *  @(#) ti.sdo.opencl.platforms.c6472; 1, 0, 0,4; 2-22-2012 18:09:29; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

