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
 *  ======== CLPlatform.c ========
 */

#include <string.h>

#include <CL/cl.h>

#include "TIPlatform.h"


/*
 *  ======== clGetDeviceIDs ========
 */
cl_int clGetDeviceIDs(
    cl_platform_id      platform,
    cl_device_type      device_type,
    cl_uint             num_entries,
    cl_device_id *      devices,
    cl_uint *           num_devices
)
{
    int i;
    cl_uint devices_populated = 0;
    cl_uint devices_matching  = 0;


    /* must specify num_entries if passing in a platform array */
    if ((devices != NULL) && (num_entries == 0)) {
        return(CL_INVALID_VALUE);
    }

    /* devices array or num_devices cannot both be null */
    if ((devices == NULL) && (num_devices == NULL)) {
        return(CL_INVALID_VALUE);
    }

    if (platform == NULL) {
        return(CL_INVALID_VALUE);
    }

    for (i = 0; i < platform->devices.length; i++) {
        if (TIDevice_getType(platform->devices.elem[i]) & device_type) {
            if ((devices_matching++ < num_entries) && (devices != NULL)) {
                devices[devices_populated++] = platform->devices.elem[i];
            }
        }
    }

    if (num_devices != NULL) {
        *num_devices = devices_matching;
    }

    if (devices_matching == 0) {
        return(CL_DEVICE_NOT_FOUND);
    }

    return(CL_SUCCESS);
}


/*
 *  ======== clGetPlatformIDs ========
 */
cl_int clGetPlatformIDs(
    cl_uint             num_entries,
    cl_platform_id *    platforms,
    cl_uint *           num_platforms
)
{
    cl_uint platforms_available;
    cl_uint platforms_populated;
    int i;


    /* must specify num_entries if passing in a platform array */
    if ((platforms != NULL) && (num_entries == 0)) {
        return(CL_INVALID_VALUE);
    }

    /* platform array or num_platforms cannot both be null */
    if ((platforms == NULL) && (num_platforms == NULL)) {
        return(CL_INVALID_VALUE);
    }

    
    platforms_available = ti_sdo_opencl_Platforms.length;

    if (platforms != NULL) {
        platforms_populated = (num_entries < platforms_available ?
            num_entries : platforms_available);

        for (i = 0; i < platforms_populated; i++) {
            platforms[i] = ti_sdo_opencl_Platforms.elem[i];
        }
    }

    if (num_platforms != NULL) {
        *num_platforms = platforms_available;
    }

    return(CL_SUCCESS);
}


/*
 *  ======== clGetPlatformInfo ========
 */
cl_int clGetPlatformInfo(
    cl_platform_id      platform,
    cl_platform_info    param_name,
    size_t              param_value_size,
    void *              param_value,
    size_t *            param_value_size_ret
)
{
    const char *rval = NULL;

    if (platform == NULL) {
        return(CL_INVALID_VALUE);
    }

    switch (param_name)
    {
        case CL_PLATFORM_PROFILE:
            rval = platform->profile;
            break;
        case CL_PLATFORM_VERSION:
            rval = platform->version;
            break;
        case CL_PLATFORM_NAME:
            rval = platform->name;
            break;
        case CL_PLATFORM_VENDOR:
            rval = platform->vendor;
            break;
        case CL_PLATFORM_EXTENSIONS:
            rval = platform->extensions;
            break;
        default:
            return(CL_INVALID_VALUE);
    }

    /* copy param value into return buffer */
    if (rval != NULL) {
        if (param_value != NULL) {
            if (param_value_size < (strlen(rval) + 1)) {
                return(CL_INVALID_VALUE);
            }
            strcpy(param_value, rval);
        }
        if (param_value_size_ret != NULL) {
            *param_value_size_ret = strlen(rval) + 1;
        }
    }

    return(CL_SUCCESS);
}


/*
 *  ======== TIPlatform_getHeapHandle ========
 */
void *TIPlatform_getHeapHandle(cl_platform_id platform)
{
    return(platform->heapH);
}


/*
 *  ======== TIPlatform_setHeapHandle ========
 */
int TIPlatform_setHeapHandle(cl_platform_id platform, void *heapH)
{
    if (platform->heapH != NULL) {
        return(-1);
    }

    platform->heapH = heapH;
    return(0);
}
/*
 *  @(#) ti.sdo.opencl; 1, 0, 0,4; 2-22-2012 18:09:26; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

