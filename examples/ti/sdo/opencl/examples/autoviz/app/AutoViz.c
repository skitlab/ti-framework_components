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
 *  ======== AutoViz.c ========
 *
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <CL/opencl.h>

/* this define must precede inclusion of any xdc header file */
#define Registry_CURDESC AutoViz__Desc
#define MODULE_NAME "AutoViz"

#include <xdc/std.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Registry.h>
#include <xdc/runtime/System.h>
#include <ti/ipc/SharedRegion.h>
#include <ti/sysbios/hal/Cache.h>


/* local header files */
#include "AutoViz.h"
#include "Pd.h"
#include "Tsr.h"

// #define IMG_DIM_X       320          // QVGA resolution
// #define IMG_DIM_Y       240

#define IMG_DIM_X       192             // even smaller for simulator
#define IMG_DIM_Y       144


/* configuration data */
#define AutoViz_clearBuffer 0


/* private data */
static Int              curInit = 0;
Registry_Desc           Registry_CURDESC;

static cl_context       context;
static cl_command_queue cmdQue;
static cl_program       program;
static cl_kernel        pdKnl;
static cl_kernel        tsrKnl;


/*
 *  ======== AutoViz_init ========
 */
Void AutoViz_init(Void)
{
    Registry_Result     result;


    if (curInit++ != 0) {
        return;  /* already initialized */
    }

    /* register with xdc.runtime to get a diags mask */
    result = Registry_addModule(&Registry_CURDESC, MODULE_NAME);
    Assert_isTrue(result == Registry_SUCCESS, (Assert_Id)NULL);

    /* initialize modules */
}


/*
 *  ======== AutoViz_exit ========
 */
Void AutoViz_exit(Void)
{
//  Registry_Result result;


    if (curInit-- != 1) {
        return;  /* object still being used */
    }

    /* finalize modules */

    /* unregister from xdc.runtime */
//  result = Registry_removeModule(MODULE_NAME);
//  Assert_isTrue(result == Registry_SUCCESS, (Assert_Id)NULL);
}


/*
 *  ======== AutoViz_start ========
 */
Int AutoViz_start(Ptr ctx)
{
    AutoViz_Cfg *           AutoVizCfg = (AutoViz_Cfg *)ctx;
    cl_platform_id          platformAry[1];
    cl_device_id            deviceAry[1];
    cl_context_properties   contextPropertyAry[8];
    size_t                  progLenAry[1];
    const unsigned char *   progBinAry[1];


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
    progLenAry[0] = strlen((const char *)AutoVizCfg->program);
    progBinAry[0] = (const unsigned char *)(AutoVizCfg->program);

    program = clCreateProgramWithBinary(context, 1, deviceAry,
        progLenAry, progBinAry, NULL, NULL);

    /* create a handle to the compiled OpenCL functions (kernels) */
    pdKnl = clCreateKernel(program, "PdKnl_process", NULL);
    tsrKnl = clCreateKernel(program, "TsrKnl_process", NULL);

    return(0);
}


/*
 *  ======== AutoViz_stop ========
 */
Int AutoViz_stop(Ptr ctx)
{
//  AutoViz_Cfg *       AutoVizCfg = (AutoViz_Cfg *)ctx;


    /* free allocated resources */
    clReleaseKernel(pdKnl);
    clReleaseKernel(tsrKnl);

    clReleaseProgram(program);
    clReleaseCommandQueue(cmdQue);
    clReleaseContext(context);

    return(0);
}


/*
 *  ======== AutoViz_exec ========
 */
#define FXNN "Autoviz_exec"
Int AutoViz_exec(Ptr ctx)
{
    Int                 status = 0;
    UInt *              srcBufBase;     // source buffer base address
    UInt *              pdBufBase;      // pd destination buffer
    UInt *              tsrBufBase;     // tsr destination buffer
    UInt                frameSize;      // frame size in bytes
    UInt                imgPixX;        // image pixel x-dimention
    UInt                imgPixY;        // image pixel y-dimention
    Int                 imgNum;
    SharedRegion_Entry  entry;
    Ptr                 sr1Addr;
    cl_event            tsrEvt;
    cl_event            pdEvt;


    Log_print0(Diags_ENTRY, "--> "FXNN":");

    /* get base address of SR#1 */
    status = SharedRegion_getEntry(1, &entry);

    if (status < 0) {
        goto leave;
    }

    sr1Addr = entry.base;

    /* compute frame size (bytes) */
    frameSize = IMG_DIM_X * IMG_DIM_Y * sizeof(UInt);
    imgPixX = IMG_DIM_X;
    imgPixY = IMG_DIM_Y;

    /* assign buffer for source image */
    srcBufBase = (UInt *)sr1Addr;
    sr1Addr = (Ptr)(((Bits8 *)sr1Addr) + frameSize);

    /* assign TSR destination buffer */
    tsrBufBase = (UInt *)sr1Addr;
    sr1Addr = (Ptr)(((Bits8 *)sr1Addr) + frameSize);

    /* assign PD destination buffer */
    pdBufBase = (UInt *)sr1Addr;
    sr1Addr = (Ptr)(((Bits8 *)sr1Addr) + frameSize);

    /* frame based processing loop */
    for (imgNum = 1; imgNum <= 1; imgNum++) {

        /* queue the tsr kernel for execution */
        clSetKernelArg(tsrKnl, 0, sizeof(UInt *), (const void *)&srcBufBase);
        clSetKernelArg(tsrKnl, 1, sizeof(UInt *), (const void *)&tsrBufBase);
        clSetKernelArg(tsrKnl, 2, sizeof(Int), (const void *)&imgPixX);
        clSetKernelArg(tsrKnl, 3, sizeof(Int), (const void *)&imgPixY);

        clEnqueueTask(cmdQue, tsrKnl, 0, NULL, &tsrEvt);

        /* queue the pd kernel for execution */
        clSetKernelArg(pdKnl, 0, sizeof(UInt *), (const void *)&srcBufBase);
        clSetKernelArg(pdKnl, 1, sizeof(UInt *), (const void *)&pdBufBase);
        clSetKernelArg(pdKnl, 2, sizeof(Int), (const void *)&imgPixX);
        clSetKernelArg(pdKnl, 3, sizeof(Int), (const void *)&imgPixY);

        clEnqueueTask(cmdQue, pdKnl, 0, NULL, &pdEvt);

        /* wait for the tsr kernel to complete */
        clWaitForEvents(1, &tsrEvt);
        clReleaseEvent(tsrEvt);

        /* local processing of tsr buffer */
        Tsr_local(tsrBufBase, IMG_DIM_X, IMG_DIM_Y);

        /* wait for the pd kernel to complete */
        clWaitForEvents(1, &pdEvt);
        clReleaseEvent(pdEvt);

        /* local processing of pd buffer */
        Pd_local(pdBufBase, IMG_DIM_X, IMG_DIM_Y);
    }

leave:
    if (status < 0) {
        Log_error0(FXNN": encountered an error");
    }

    Log_print1(Diags_EXIT, "<-- "FXNN": %d", (IArg)status);
    return(status);
}
#undef FXNN
/*
 *  @(#) ti.sdo.opencl.examples.autoviz; 1, 0, 0,4; 2-22-2012 18:09:17; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

