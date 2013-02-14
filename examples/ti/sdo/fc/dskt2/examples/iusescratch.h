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
 *  ======== iusescratch.h ========
 *  IUSESCRATCH Interface Header
 *
 */
#ifndef IUSESCRATCH_
#define IUSESCRATCH_

#include <ti/xdais/ialg.h>
#include <ti/xdais/idma2.h>

#define USESCRATCH_SOK      0
#define USESCRATCH_EFAIL    -1
#define USESCRATCH_EMEMORY  -2


/*
 *  ======== IUSESCRATCH_HANDLE ========
 *  This handle is used to reference all USESCRATCH instance objects
 */
typedef struct IUSESCRATCH_Obj *IUSESCRATCH_Handle;

/*
 *  ======== IUSESCRATCH_Obj ========
 *  This structure must be the first field of all USESCRATCH instance objects
 */
typedef struct IUSESCRATCH_Obj {
    struct IUSESCRATCH_Fxns *fxns;
} IUSESCRATCH_Obj;

/*
 *  ======== IUSESCRATCH_Cmd ========
 *  The Cmd enumeration defines the control commands for the USESCRATCH
 *  control method.
 */
typedef enum IUSESCRATCH_Cmd {
    IUSESCRATCH_GETUSESCRATCH,      /* Get command */
    IUSESCRATCH_SETUSESCRATCH       /* Set command */
} IUSESCRATCH_Cmd;

/*
 *  ======== IUSESCRATCH_Params ========
 *  This structure defines the creation parameters for all USESCRATCH objects
 */
typedef struct IUSESCRATCH_Params {
    Int size;           /* must be first field of all params structures */
    Int scratchGroup;   /* Scratch group the algorithm belongs to */
    Uns scratchSize;    /* size of scratch memory buffer to request */
    Uns value;          /* value to put in scratch memory */
    Int id;             /* ID of task the created the alg */
    IALG_MemRec *memTab; /* Array of memory requests specified by framework */
    Int numRecs;        /* Number of records in memRec */
    IALG_Fxns *fxns;    /* Pointer to IALG_Fxns (so we can check in algAlloc
                         * if algActivate() and algDeactivate() are non-NULL.
                         * (Can't use scratch if one of these is NULL).
                         */
} IUSESCRATCH_Params;

/*
 *  ======== IUSESCRATCH_PARAMS ========
 *  Default parameter values for USESCRATCH instance objects
 */
extern IUSESCRATCH_Params IUSESCRATCH_PARAMS;

/*
 *  ======== IUSESCRATCH_Fxns ========
 *  This structure defines all of the operations on USESCRATCH objects
 */
typedef struct IUSESCRATCH_Fxns {
    IALG_Fxns   ialg;    /* IUSESCRATCH extends IALG */
    Int         (* useScratch)(IALG_Handle alg);
    Int         (* getBufs)(IALG_Handle alg, IALG_MemRec *memTab, Int nRecs);
} IUSESCRATCH_Fxns;

#endif  /* IUSESCRATCH_Fxns */
/*
 *  @(#) ti.sdo.fc.dskt2.examples; 1, 0, 0,4; 2-22-2012 18:03:53; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

