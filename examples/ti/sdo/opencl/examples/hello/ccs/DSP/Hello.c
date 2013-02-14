/* 
 * Copyright (c) 2011, Texas Instruments Incorporated
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
 *  ======== Hello.c ========
 *
 */
#include <string.h>

#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <ti/sysbios/hal/Cache.h>

#include <CL/opencl.h>

#define BUF_SIZE 64

static Char     cbuf[BUF_SIZE];
static Ptr      bufBase = cbuf;
static Int      bufSize = BUF_SIZE;


/* application main(), called from main_host_bios.c */
Int main_app(Char *progConfig)
{
    cl_platform_id          platformAry[1];
    cl_device_id            deviceAry[1];
    cl_context              context;
    cl_command_queue        cmdQue;
    cl_context_properties   contextPropertyAry[8];
    cl_program              program;
    size_t                  progLenAry[1];
    const unsigned char *   progBinAry[1];
    cl_kernel               helloKnl;
    Int                     ctrl;       // kernel control argument


    /*
     *  ======== Create Phase ========
     */

    /* get a platform, default platform has all available devices */
    clGetPlatformIDs(1, platformAry, NULL);

    /* get an accelerator device */
    clGetDeviceIDs(platformAry[0], CL_DEVICE_TYPE_ACCELERATOR,
        1, deviceAry, NULL);

    /* create a context for the accelerator device */
    contextPropertyAry[0] = CL_CONTEXT_PLATFORM;
    contextPropertyAry[1] = (cl_context_properties)platformAry[0];
    contextPropertyAry[2] = 0;
    context = clCreateContext(contextPropertyAry, 1, deviceAry,
        NULL, NULL, NULL);

    /* create a command-queue for the accelerator device */
    cmdQue = clCreateCommandQueue(context, deviceAry[0], NULL, NULL);

    /* create program from binary, load it on the accelerator device */
    progLenAry[0] = strlen(progConfig);
    progBinAry[0] = (const unsigned char *)progConfig;

    program = clCreateProgramWithBinary(context, 1, deviceAry,
        progLenAry, progBinAry, NULL, NULL);

    /* create a handle to the compiled OpenCL function (kernel) */
    helloKnl = clCreateKernel(program, "HelloKnl_funcA", NULL);


    /*
     *  ======== Execute Phase ========
     */

    /* assign the kernel arguments */
    clSetKernelArg(helloKnl, 0, sizeof(Ptr), (const void *)&bufBase);
    clSetKernelArg(helloKnl, 1, sizeof(Int), (const void *)&bufSize);

    ctrl = 0;
    clSetKernelArg(helloKnl, 2, sizeof(Int), (const void *)&ctrl);

    /* invoke the hello world kernel */
    clEnqueueTask(cmdQue, helloKnl, 0, NULL, NULL);

    /* view the return data */
    Cache_inv(bufBase, bufSize, Cache_Type_L1D|Cache_Type_L2, TRUE);
    System_printf("%s\n", (Char *)bufBase);

    /* invoke the kernel again with different control argument */
    ctrl = 1;
    clSetKernelArg(helloKnl, 2, sizeof(Int), (const void *)&ctrl);
    clEnqueueTask(cmdQue, helloKnl, 0, NULL, NULL);

    /* view the return data */
    Cache_inv(bufBase, bufSize, Cache_Type_L1D|Cache_Type_L2, TRUE);
    System_printf("%s\n", (Char *)bufBase);


    /*
     *  ======== Delete Phase ========
     */

    clReleaseKernel(helloKnl);
    clReleaseProgram(program);
    clReleaseCommandQueue(cmdQue);
    clReleaseContext(context);

    return(0);
}
/*
 *  @(#) ti.sdo.opencl.examples.hello; 1, 0, 0,1; 1-26-2011 22:23:32; /db/atree/library/trees/fc/fc.git/src/ fc-o11
 */

