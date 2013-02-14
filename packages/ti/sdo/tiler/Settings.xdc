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
 *  ======== Settings.xdc ========
 *
 */

package ti.sdo.tiler;


/*!
 *  ======== Settings ========
 *  Global configuration settings for the ti.sdo.tiler package
 *
 */

@Template("./Settings.xdt")

metaonly module Settings
{

    // -------- Module Constants --------

    // -------- Module Types --------

    /*!
     *  Available tiler library implementations
     *
     *  @value(TilerLib_Stub) This library implements stub functions
     *  which make remote function calls to a tiler manager on another
     *  core. When using this value, you must also specify the
     *  {@link #tilerDaemon} config param.
     *
     *  @value(TilerLib_Skel) This library implements the skel
     *  functions which are the remote parts of the stub functions.
     *  Use this value when configuring the tiler daemon. When using
     *  this value, you must also specify the {@link #tilerManagerOS}
     *  config param.
     *
     *  @value(TilerLib_Direct) This library links in direct calls to
     *  the tiler manager. Use this value when configuring a program
     *  which is running on the same core as the tiler manager. When
     *  using this value, you must also specify the {@link #tilerManagerOS}
     *  config param.
     */
    enum TilerLib {
        TilerLib_Stub,
        TilerLib_Skel,
        TilerLib_Direct
    };

    /*!
     *  Operating systems used for hosting the tiler manager
     *
     *  @value(OperSys_Linux) The tiler manager is running on Linux.
     *
     *  @value(OperSys_WinCE) The tiler manager is running on WindowsCE.
     *
     *  @value(OperSys_RTOS) The tiler manager is running on a real-time
     *  operating system which does not make a distinction between
     *  user and kernel modes.
     */
    enum OperSys {
        OperSys_Linux,
        OperSys_WinCE,
        OperSys_RTOS
    };

    // -------- Module Parameters --------

    /*!
     *  Heap id to use for allocating messages
     *
     *  When using a remote tiler manager, the client application must
     *  send messages to execute the tiler manager functions. This config
     *  param is used by the underlying IPC layers to identify which heap
     *  should be used for allocating these messages.
     *
     *  If the executable is making direct (local) calls to the tiler
     *  manager, then leave this config param undefined.
     */
    config UInt16 heapId;

    /*!
     *  Specifies the name of the tiler daemon
     *
     *  When configuring an executable which is using a tiler manager
     *  that is running on another core, this config param must be set
     *  to the name of the tiler daemon.
     */
    config String tilerDaemonName = null;

    /*!
     *  Specify which tiler library implementation to use
     *
     *  This config param specifies which tiler library implementation to
     *  link into the program. There are several different versions:
     *
     *  @p(blist)
     *  - A tiler client program where the tiler manager is running
     *  on another core. Use {@link #TilerLib_Stub}.
     *
     *  - A tiler daemon program which is used to service remote
     *  tiler client programs. The daemon must be running on the same core
     *  as the tiler manager. Use {@link #TilerLib_Skel}.
     *
     *  - A tiler client program running on the same core as the
     *  tiler manager. Use {@link #TilerLib_Direct}.
     *  @p
     */
    config TilerLib tilerLib;

    /*!
     *  Specifies operating system on which the tiler manager is running
     *
     *  When configuring a program which is running on the same core
     *  as the tiler manager, set this config param to the host operating
     *  system. If the tiler manager is not part of the executable, then
     *  leave it undefined.
     *
     *  For example, if building an executable which is running on the same
     *  core as the tiler manager, (e.g. a local tiler client or the tiler
     *  daemon) then set this config param to the OS type. If building an
     *  executable which is making tiler calls to another core (e.g. a
     *  remote tiler client), then leave this config param undefined.
     */
    config OperSys tilerManagerOS;
}
/*
 *  @(#) ti.sdo.tiler; 1, 0, 0,4; 2-22-2012 18:10:47; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

 */

