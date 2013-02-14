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
 *  ======== SystemCfg.h ========
 *  
 *
 */
#ifndef SystemCfg__include
#define SystemCfg__include

#include "App.h"


#if defined (__cplusplus)
extern "C" {
#endif


/* constants and types */
#define SystemCfg_S_SUCCESS     (0)
#define SystemCfg_E_FAIL        (-1)
#define SystemCfg_E_NOMEMORY    (-2)

typedef struct {
    String      remoteProcName;
} SystemCfg_Params;

typedef struct SystemCfg_Object_tag *SystemCfg_Handle;


/* module-wide functions */
Void SystemCfg_init(Void);
Void SystemCfg_exit(Void);
Void SystemCfg_Params_init(SystemCfg_Params *params);

/* per-instance functions */
Int SystemCfg_create(
        const SystemCfg_Params *params,
        SystemCfg_Handle *      handlePtr
    );

Int SystemCfg_delete(
        SystemCfg_Handle *      handlePtr
    );

Int SystemCfg_start(SystemCfg_Handle handle, String filePath);
// Int SystemCfg_startAck(SystemCfg_Handle handle);
Int SystemCfg_stop(SystemCfg_Handle handle);

Int SystemCfg_attach(SystemCfg_Handle handle);
Int SystemCfg_detach(SystemCfg_Handle handle);

Int SystemCfg_initializeResources(
        SystemCfg_Handle        handle,
        App_Fxn                 fxn,
        App_Handle              app
    );

Int SystemCfg_finalizeResources(
        SystemCfg_Handle        handle,
        App_Fxn                 fxn,
        App_Handle              app
    );

Void SystemCfg_sendStartup(SystemCfg_Handle handle);
Void SystemCfg_waitForStartup(SystemCfg_Handle handle);

Void SystemCfg_sendShutdown(SystemCfg_Handle handle);
Void SystemCfg_waitForShutdown(SystemCfg_Handle handle);


#if defined (__cplusplus)
}
#endif /* defined (__cplusplus) */
#endif /* SystemCfg__include */
/*
 *  @(#) ti.sdo.rcm.examples.appcfg; 1,0,0,4; 2-22-2012 18:09:44; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

