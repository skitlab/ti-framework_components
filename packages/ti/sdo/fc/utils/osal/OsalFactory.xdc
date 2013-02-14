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
 *  ======== OsalFactory.xdc ========
 */

import xdc.runtime.Error;
import xdc.runtime.knl.ISemaphore;

/*!
 *  ======== OsalFactory ========
 *  Factory to create osal objects.
 *
 *  createSem() creates either a SemaphoreMP or a Semaphore object, depending
 *  on ti.sdo.fc.Settings.multiProcess. This function returns the Semaphore
 *  or SemaphoreMP handle cast as an ISemaphore handle. This allows
 *  the caller to use the ISemaphore functions (eg, pend(), post()),
 *  without having to make a check on whether to use Semaphore functions
 *  or SemaphoreMP functions on the handle.
 */

module OsalFactory {

    /*!
     *  ======== createSem ========
     *  Create a SemaphoreMP object if ti.sdo.fc.Settings.multiProcess is true,
     *  otherwise create a Semaphore object.
     *
     *  @param(count)   The count to initialize the semaphore with
     *  @param(key)     A key for multi-process semaphore (if needed).
     *  @a(returns)     The Semaphore or SemaphoreMP handle, cast as an
     *                  ISemaphore handle.
     */
    ISemaphore.Handle createSem(Int count, Int key, Error.Block *eb);

    /*!
     *  ======== deleteSem ========
     *  Delete the semaphore created in createSem().
     *
     *  @param(h)       Handle returned by createSem().
     */
    Void deleteSem(ISemaphore.Handle h);
}
/*
 *  @(#) ti.sdo.fc.utils.osal; 1, 0, 0,4; 2-22-2012 18:08:52; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

