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
 *  ======== ishmalg.h ========
 *  ISHMALG Interface Header
 *
 */
#ifndef ti_sdo_fc_rman_examples_shmbuf_ISHMALG_
#define ti_sdo_fc_rman_examples_shmbuf_ISHMALG_

#include <ti/xdais/ialg.h>

#define SHMALG_SOK      0
#define SHMALG_EFAIL    -1
#define SHMALG_EMEMORY  -2


/*
 *  ======== ISHMALG_HANDLE ========
 *  This handle is used to reference all SHMALG instance objects
 */
typedef struct ISHMALG_Obj *ISHMALG_Handle;

/*
 *  ======== ISHMALG_Obj ========
 *  This structure must be the first field of all SHMALG instance objects
 */
typedef struct ISHMALG_Obj {
    struct ISHMALG_Fxns *fxns;
} ISHMALG_Obj;

/*
 *  ======== ISHMALG_Cmd ========
 *  The Cmd enumeration defines the control commands for the SHMALG
 *  control method.
 */
typedef enum ISHMALG_Cmd {
    ISHMALG_GET,      /* Get command */
    ISHMALG_SET       /* Set command */
} ISHMALG_Cmd;

/*
 *  ======== ISHMALG_Params ========
 *  This structure defines the creation parameters for all SHMALG objects
 */
typedef struct ISHMALG_Params {
    Int size;           /* must be first field of all params structures */
    Int fillVal;        /* Value to fill buffer with */
} ISHMALG_Params;

/*
 *  ======== ISHMALG_PARAMS ========
 *  Default parameter values for SHMALG instance objects
 */
extern ISHMALG_Params ISHMALG_PARAMS;

/*
 *  ======== ISHMALG_Fxns ========
 *  This structure defines all of the operations on SHMALG objects
 */
typedef struct ISHMALG_Fxns {
    IALG_Fxns   ialg;    /* ISHMALG extends IALG */
    Int         (*useBufs)(ISHMALG_Handle handle);
    Int         (*checkBufs)(ISHMALG_Handle handle);
} ISHMALG_Fxns;

#endif
/*
 *  @(#) ti.sdo.fc.rman.examples.shmbuf; 1, 0, 0,4; 2-22-2012 18:08:18; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

