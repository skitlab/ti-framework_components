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
 *  ======== RcmTypes.h ========
 *
 */

#ifndef ti_sdo_rcm_RcmTypes_h
#define ti_sdo_rcm_RcmTypes_h

#include <ti/ipc/MessageQ.h>
#include <ti/sdo/rcm/RcmClient.h>


/*
 *  ======== RcmClient_Packet ========
 *
 *  RcmClient_Packet.desc: the package descriptor field. Note that the
 *  format is different for out-bound and in-bound messages.
 *
 *  out-bound message descriptor
 *
 *  Bits    Description
 *  --------------------------------------------------------------------
 *  [15:12] reserved
 *  [11:8]  message type
 *  [7:0]   client protocol version
 *
 *
 *  in-bound message descriptor
 *
 *  Bits    Description
 *  --------------------------------------------------------------------
 *  [15:12] reserved
 *  [11:8]  server status code
 *  [7:0]   server protocol version
 */

/* message type values */
#define RcmClient_Desc_RCM_MSG    0x1       // client exec message
#define RcmClient_Desc_DPC        0x2       // deferred procedure call
#define RcmClient_Desc_SYM_ADD    0x3       // symbol add message
#define RcmClient_Desc_SYM_IDX    0x4       // query symbox index
#define RcmClient_Desc_CMD        0x5       // cmd message (one-way)
#define RcmClient_Desc_JOB_ACQ    0x6       // acquire a job id
#define RcmClient_Desc_JOB_REL    0x7       // release a job id
#define RcmClient_Desc_TYPE_MASK  0x0F00    // field mask
#define RcmClient_Desc_TYPE_SHIFT 8         // field shift width

/* server status codes must be 0 - 15, it has to fit in a 4-bit field */
#define RcmServer_Status_SUCCESS          ((UInt16)0) // success
#define RcmServer_Status_INVALID_FXN      ((UInt16)1) // invalid fxn index
#define RcmServer_Status_SYMBOL_NOT_FOUND ((UInt16)2) // symbol not found
#define RcmServer_Status_INVALID_MSG_TYPE ((UInt16)3) // invalid msg type
#define RcmServer_Status_MSG_FXN_ERR      ((UInt16)4) // msg function error
#define RcmServer_Status_Error            ((UInt16)5) // general failure
#define RcmServer_Status_Unprocessed      ((UInt16)6) // unprocessed message
#define RcmServer_Status_JobNotFound      ((UInt16)7) // job id not found
#define RcmServer_Status_PoolNotFound     ((UInt16)8) // pool id not found

/* the packet structure (actual message send to server) */
typedef struct {
    MessageQ_MsgHeader msgqHeader;  // MessageQ header (8 words)
    UInt16 desc;                    // protocol, descriptor, status
    UInt16 msgId;                   // message id
    RcmClient_Message message;      // client message body (5 words + payload)
} RcmClient_Packet;


/* string functions */
Void *_memset(Void *s, Int c, Int n);
Int _strcmp(Char *s, Char *t);
Void _strcpy(Char *s, Char *t);
Int _strlen(const Char *s);

#endif /* ti_sdo_rcm_RcmTypes_h */
/*
 *  @(#) ti.sdo.rcm; 2, 0, 0,4; 2-22-2012 18:09:55; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

