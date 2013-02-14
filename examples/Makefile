#
#  Copyright (c) 2011, Texas Instruments Incorporated
#  All rights reserved.
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions
#  are met:
#
#  *  Redistributions of source code must retain the above copyright
#     notice, this list of conditions and the following disclaimer.
#
#  *  Redistributions in binary form must reproduce the above copyright
#     notice, this list of conditions and the following disclaimer in the
#     documentation and/or other materials provided with the distribution.
#
#  *  Neither the name of Texas Instruments Incorporated nor the names of
#     its contributors may be used to endorse or promote products derived
#     from this software without specific prior written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
#  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
#  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
#  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
#  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
#  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
#  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
#  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
#  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
#  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
#  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
#
#  ======== makefile ========
#  GNUmake-based makefile.
#

# define product install paths
EXAMPLES_ROOTDIR := .
include $(EXAMPLES_ROOTDIR)/xdcpaths.mak

# add the examples repository to the xdc path
XDC_PATH := $(EXAMPLES_ROOTDIR);$(XDC_PATH)

# build rules
include $(EXAMPLES_ROOTDIR)/buildutils/xdcrules.mak

# if we're building for v5T, $(CGTOOLS_V5T) will be set, and "all" needs to
# build the OSAL libraries for the RCM examples
ifneq (,$(CGTOOLS_V5T))
all: rcm
endif

rcm:
	$(MAKE) -C  ti/sdo/rcm/examples/minidist/linux/osal
	$(MAKE) -C  ti/sdo/rcm/examples/minidist/linux/client

clean:: .clean-rcm

.clean-rcm::
	$(MAKE) -C  ti/sdo/rcm/examples/minidist/linux/osal clean
	$(MAKE) -C  ti/sdo/rcm/examples/minidist/linux/client clean

dm365: edma_only vicp_only

edma_only:
	$(MAKE) -C  ti/sdo/fc/rman/examples/dummyEdma3 ti/sdo/fc/rman/examples/scratchEdma3

vicp_only:
	$(MAKE) -C ti/sdo/fc/rman/examples/vicp


