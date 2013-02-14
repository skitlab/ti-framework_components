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
 *  ======== alg.h ========
 */
#ifndef ALG_
#define ALG_

#include <ti/xdais/ialg.h>

#ifdef __cplusplus
extern "C" {
#endif

#define ALG_GTNAME "ti.sdo.ce.alg"      /**< Name used to identify the GT
                                         *   module
                                         */


/*
 *  ======== ALG_Handle ========
 */
/**
 *  @brief      This handle type is used to reference all ALG instance objects.
 */
typedef IALG_Handle ALG_Handle;

/*
 *  ======== ALG_activate ========
 */
/**
 *  @brief      Restore all shared persistant data associated with algorithm
 *              object.
 *
 *  @param[in] groupId  Group which @c alg is associated with.
 *  @param[in] alg      Handle of algorithm to activate.
 *
 *  @todo       Typically handles are the first params passed to a fxn.
 *  @todo       Could we store the groupId in the alg handle at create time
 *              so we don't need to supply it to ALG_delete()?
 */
extern Void ALG_activate(Int groupId, ALG_Handle alg);

/*
 *  ======== ALG_control ========
 */
/**
 *  @brief      Control algorithm object.
 */
extern Int ALG_control(ALG_Handle alg, IALG_Cmd cmd, IALG_Status *sptr);

/*
 *  ======== ALG_create ========
 */
/**
 *  @brief      Create algorithm object and initialize its memory.
 */
extern ALG_Handle ALG_create(Int groupId, IALG_Fxns *fxns, IALG_Handle p,
        IALG_Params *prms);

/*
 *  ======== ALG_deactivate ========
 */
/**
 *  @brief      Save all shared persistant data associated with algorithm
 *              object to some non-shared persistant memory.
 *
 *  @param[in] groupId  Group which @c alg is associated with.
 *  @param[in] alg      Handle of algorithm to deactivate.
 *
 *  @todo       Typically handles are the first params passed to a fxn.
 *  @todo       Could we store the groupId in the alg handle at create time
 *              so we don't need to supply it to ALG_delete()?
 */
extern Void ALG_deactivate(Int groupId, ALG_Handle alg);

/*
 *  ======== ALG_delete ========
 */
/**
 *  @brief      Delete algorithm object and release its memory.
 *
 *  @param[in]  groupId         groupId which @c alg is associated with.
 *  @param[in]  alg             handle of algorithm to delete.
 *
 *  @todo       Typically handles are the first params passed to a fxn.
 *  @todo       Could we store the groupId in the alg handle at create time
 *              so we don't need to supply it to ALG_delete()?
 */
extern Void ALG_delete(Int groupId, ALG_Handle alg);

/*
 *  ======== ALG_exit ========
 *  Module finalization
 */
extern Void ALG_exit(Void);

/*
 *  ======== ALG_init ========
 *  Module initialization
 */
extern Void ALG_init(Void);

#ifdef __cplusplus
}
#endif

#endif  /* ALG_ */
/*
 *  @(#) ti.sdo.fc.rman.examples; 1, 0, 0,4; 2-22-2012 18:07:13; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

