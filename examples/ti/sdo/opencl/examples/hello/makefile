# 
#  Copyright (c) 2012, Texas Instruments Incorporated
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
#
#  The following variables are used from the environment.
#
#  ECLIPSE_HOME         full path to the ccsv4 folder
#

#
#  ======== dependencies ========
#
CCS_DIR = $(subst /C:,C:,$(subst /ccsv4/eclipse/,,$(ECLIPSE_HOME)))

FC_INSTALL_DIR    = $(CCS_DIR)/framework_components_install_folder
IPC_INSTALL_DIR   = $(CCS_DIR)/ipc_install_folder
BIOS_INSTALL_DIR  = $(CCS_DIR)/bios_install_folder
XDC_INSTALL_DIR   = $(CCS_DIR)/xdctools_install_folder

CGT_CE64P_INSTALL_DIR   = $(CCS_DIR)/ccsv4/tools/compiler/c6000
CGT_CE674_INSTALL_DIR   = $(CCS_DIR)/ccsv4/tools/compiler/c6000
TI_ARP32_INSTALL_DIR    = $(CCS_DIR)/ccsv5/compiler/arp32

MAKEVARS = \
    FC_INSTALL_DIR=$(FC_INSTALL_DIR) \
    IPC_INSTALL_DIR=$(IPC_INSTALL_DIR) \
    BIOS_INSTALL_DIR=$(BIOS_INSTALL_DIR) \
    XDC_INSTALL_DIR=$(XDC_INSTALL_DIR) \
    CGT_CE64P_INSTALL_DIR=$(CGT_CE64P_INSTALL_DIR) \
    CGT_CE674_INSTALL_DIR=$(CGT_CE674_INSTALL_DIR) \
    TI_ARP32_INSTALL_DIR=$(TI_ARP32_INSTALL_DIR)

.PHONY: all simArctic evm6472

# all: simArctic evm6472
all: simArctic

simArctic:
	$(MAKE) -f make_simArctic.mak $(MAKEVARS) all

evm6472:
	$(MAKE) -f make_evm6472.mak $(MAKEVARS) all

clean::
	$(RMDIR) bin
	$(MAKE) -C systemcfg_ti_platforms_evm6472 clean
	$(MAKE) -C systemcfg_ti_platforms_simArctic clean

#
#  ======== standard macros ========
#  XDCtools provides commands for Windows; use native commands elsewhere.
#
ifneq (,$(wildcard $(XDC_INSTALL_DIR)/bin/echo.exe))
ECHO    = $(XDC_INSTALL_DIR)/bin/echo
MKDIR   = $(XDC_INSTALL_DIR)/bin/mkdir -p
RM      = $(XDC_INSTALL_DIR)/bin/rm -f
RMDIR   = $(XDC_INSTALL_DIR)/bin/rm -rf
else
ECHO    = echo
MKDIR   = mkdir -p
RM      = rm -f
RMDIR   = rm -rf
endif
#
#  @(#) ti.sdo.opencl.examples.hello; 1, 0, 0,4; 2-22-2012 18:09:29; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

#

