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
 *  ======== ComputeDevice.h ========
 *
 */
#ifndef ComputeDevice__include
#define ComputeDevice__include


#if defined (__cplusplus)
extern "C" {
#endif

typedef Void (*ComputeDevice_InitFxn)(Void);
typedef Void (*ComputeDevice_ExitFxn)(Void);

#define ti_cl_arg_type_Int              0x0001
#define ti_cl_arg_type_LocalPtr         0x0002
#define ti_cl_arg_type_GlobalPtr        0x0003
#define ti_cl_arg_type_SrPtr            0x0004

typedef struct {
    String      name;
    Fxn         addr;
    Int         numArgs;
    UInt *      args;
} ComputeDevice_FxnDesc;

typedef struct {
    ComputeDevice_InitFxn       initFxn;
    ComputeDevice_ExitFxn       exitFxn;
    Int                         numFxns;
    ComputeDevice_FxnDesc *     fxnTab;
} ComputeDevice_Unit;


/* IUnit interface */
Void ComputeDevice_init(Void);
Void ComputeDevice_exit(Void);

/* ISystemCfg interface */
typedef struct {
    String      rcmServerName;
} ComputeDevice_Cfg;

Int ComputeDevice_start(Ptr cfg);
Int ComputeDevice_exec(Ptr cfg);
Int ComputeDevice_stop(Ptr cfg);


#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */
#endif /* ComputeDevice__include */
/*
 *  @(#) ti.sdo.opencl; 1, 0, 0,4; 2-22-2012 18:09:27; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

