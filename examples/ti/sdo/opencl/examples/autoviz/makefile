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
FC_INSTALL_DIR    = /framework_components_install_folder
IPC_INSTALL_DIR   = /ipc_install_folder
XDAIS_INSTALL_DIR = /xdais_install_folder
BIOS_INSTALL_DIR  = /bios_install_folder
XDC_INSTALL_DIR   = /xdctools_install_folder

TI_C6X_INSTALL_DIR      ?= $(CCS_DIR)/ccsv5/compiler/c6000
TI_ARP32_INSTALL_DIR    ?= $(CCS_DIR)/ccsv5/compiler/arp32

MAKEVARS = \
    FC_INSTALL_DIR=$(FC_INSTALL_DIR) \
    XDAIS_INSTALL_DIR=$(XDAIS_INSTALL_DIR) \
    IPC_INSTALL_DIR=$(IPC_INSTALL_DIR) \
    BIOS_INSTALL_DIR=$(BIOS_INSTALL_DIR) \
    XDC_INSTALL_DIR=$(XDC_INSTALL_DIR) \
    TI_C6X_INSTALL_DIR=$(TI_C6X_INSTALL_DIR) \
    TI_ARP32_INSTALL_DIR=$(TI_ARP32_INSTALL_DIR)

.PHONY: prog_ComputeDevice prog_App
.PHONY: all app compute
.PHONY: systemcfg_ti_platforms_simArctic

all: prog_ComputeDevice prog_App

prog_ComputeDevice: systemcfg_ti_platforms_simArctic compute
	$(MAKE) -C $@ $(MAKEVARS) all

prog_App: app systemcfg_ti_platforms_simArctic
	$(MAKE) -C $@ $(MAKEVARS) all

compute:
	$(MAKE) -C $@ $(MAKEVARS) all

app:
	$(MAKE) -C $@ $(MAKEVARS) all

systemcfg_ti_platforms_simArctic:
	$(MAKE) -C $@ $(MAKEVARS) all

clean::
	$(MAKE) -C prog_ComputeDevice clean
	$(MAKE) -C prog_App clean
	$(MAKE) -C compute clean
	$(MAKE) -C app clean
	$(MAKE) -C systemcfg_ti_platforms_simArctic clean
#
#  @(#) ti.sdo.opencl.examples.autoviz; 1, 0, 0,4; 2-22-2012 18:09:18; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

#

