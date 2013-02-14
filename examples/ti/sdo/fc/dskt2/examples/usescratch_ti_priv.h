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
 *  ======== usescratch_ti_priv.h ========
 *
 *  Private internal vendor specific interface.
 *
 */

#ifndef USESCRATCH_TI_PRIV_
#define USESCRATCH_TI_PRIV_

#include <ti/xdais/ialg.h>
#include "iusescratch.h"

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/

#define NUMBUFS 2
#define NUMALLOC NUMBUFS + 1

/* Maximum number of buffers to alloc */
#define MAXALLOC 16

/*
 *  ======== USESCRATCH_TI_Obj ========
 */
typedef struct USESCRATCH_TI_Obj {
    IALG_Obj     alg;           /* Alogorithm handle    */

    /* Scratch buffer base and sizes */
    Uns        *scratchBufs[MAXALLOC - 1];
    Uns         bufSizes[MAXALLOC - 1];

    Int         numBufs;   /* # of bufs allocated, not including object */
    Int         numRecs;   /* Total number of buffers allocated */
    IALG_MemRec memTab[MAXALLOC]; /* Keep track of memory assignment */
    Int         scratchGroup;
    Int         bufSize;
    Uns         value;
    Int         status;
    Int         id;
} USESCRATCH_TI_Obj;


/* Function declarations */
extern Void USESCRATCH_TI_activate(IALG_Handle);

extern Int USESCRATCH_TI_alloc(const IALG_Params *, struct IALG_Fxns **,
        IALG_MemRec *);

extern Int USESCRATCH_TI_control(IALG_Handle, IALG_Cmd, IALG_Status *);

extern Void USESCRATCH_TI_deactivate(IALG_Handle);

extern Int USESCRATCH_TI_free(IALG_Handle, IALG_MemRec *);

extern Int USESCRATCH_TI_initObj(IALG_Handle, const IALG_MemRec *, IALG_Handle,
        const IALG_Params *);

extern Void USESCRATCH_TI_moved(IALG_Handle, const IALG_MemRec *, IALG_Handle,
        const IALG_Params *);

extern Int USESCRATCH_TI_numAlloc(Void);

extern Int USESCRATCH_TI_getBufs(const IALG_Handle, IALG_MemRec *, Int);

extern Int USESCRATCH_TI_useScratch(IALG_Handle handle);


#ifdef _cplusplus
}
#endif /* _cplusplus */

#endif /* USESCRATCH_TI_PRIV_ */
/*
 *  @(#) ti.sdo.fc.dskt2.examples; 1, 0, 0,4; 2-22-2012 18:03:54; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

