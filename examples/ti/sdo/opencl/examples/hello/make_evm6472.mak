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
#  ======== make_evm6472.mak ========
#
#  The following variables are used from the environment.
#
#  ECLIPSE_HOME         full path to the ccsv4 folder
#

#
#  ======== dependencies ========
#
CCS_DIR = $(subst /C:,C:,$(subst /ccsv4/eclipse/,,$(ECLIPSE_HOME)))

FC_INSTALL_DIR    = $(CCS_DIR)/framework_components_your_version_number
IPC_INSTALL_DIR   = $(CCS_DIR)/ipc_your_version_number
BIOS_INSTALL_DIR  = $(CCS_DIR)/bios_your_version_number
XDC_INSTALL_DIR   = $(CCS_DIR)/xdctools_your_version_number

CGT_CE64P_INSTALL_DIR ?= $(CCS_DIR)/ccsv4/tools/compiler/c6000

#
#  ======== include path ========
#
INCPATH =   $(FC_INSTALL_DIR)/packages \
            $(FC_INSTALL_DIR)/packages/khronos/opencl \
            $(IPC_INSTALL_DIR)/packages \
            $(BIOS_INSTALL_DIR)/packages \
            $(XDC_INSTALL_DIR)/packages

#
#  ======== toolchain macros ========
#
ifeq (e64P,$(SUFFIX))
CGTOOLS = $(CGT_CE64P_INSTALL_DIR)

CC = $(CGTOOLS)/bin/cl6x -c -mv64p --abi=elfabi
AR = $(CGTOOLS)/bin/ar6x rq
LD = $(CGTOOLS)/bin/lnk6x --abi=elfabi

CPPFLAGS = -Dxdc_target_name__=C64P -Dxdc_target_types__=ti/targets/elf/std.h \
    -DPlatform_SystemCfg_h=systemcfg_$(PLAT)/SystemCfg.h
CFLAGS = -qq -pdsw225 $(CCPROFILE_$(PROFILE)) \
    -I. $(addprefix -I,$(INCPATH)) -I$(CGTOOLS)/include

LDFLAGS = -w -q -u _c_int00 -c -m $@.map
LDLIBS = -l $(CGTOOLS)/lib/rts64plus_elf.lib

CCPROFILE_debug = -D_DEBUG_=1 --symdebug:dwarf
CCPROFILE_release = -O2
endif

#
#  ======== source files ========
#
PLAT = ti_platforms_evm6472

App_srcs = main_host_bios.c Hello.c
App_objs = \
    $(addprefix bin/$(PLAT)/$(PROFILE)/, \
    $(patsubst %.c,%.o$(SUFFIX),$(App_srcs)))
App_libs = \
    systemcfg_$(PLAT)/lib/$(PROFILE)/App_systemcfg.a$(SUFFIX) \
    systemcfg_$(PLAT)/configuro_App/linker.cmd

ComputeDevice_srcs = main_server_bios.c HelloKnl.c KernelTable.c
ComputeDevice_objs = \
    $(addprefix bin/$(PLAT)/$(PROFILE)/, \
    $(patsubst %.c,%.o$(SUFFIX),$(ComputeDevice_srcs)))
ComputeDevice_libs = \
    systemcfg_$(PLAT)/lib/$(PROFILE)/ComputeDevice_systemcfg.a$(SUFFIX) \
    systemcfg_$(PLAT)/configuro_ComputeDevice/linker.cmd

#
#  ======== make commands ========
#
.PHONY: all
.PHONY: systemcfg_ti_platforms_evm6472

all: systemcfg_ti_platforms_evm6472
	$(MAKE) -f make_evm6472.mak PROFILE=debug SUFFIX=e64P Hello_core0.x
#	$(MAKE) -f make_evm6472.mak PROFILE=release SUFFIX=e64P Hello_core0.x
	$(MAKE) -f make_evm6472.mak PROFILE=debug SUFFIX=e64P ComputeDevice_core1.x
#	$(MAKE) -f make_evm6472.mak PROFILE=release SUFFIX=e64P ComputeDevice_core1.x

#
#  ======== build rules ========
#
systemcfg_ti_platforms_evm6472:
	$(MAKE) -C $@ $(MAKEVARS) all

Hello_core0.x: bin/$(PLAT)/$(PROFILE)/Hello_core0.x$(SUFFIX)
bin/$(PLAT)/$(PROFILE)/Hello_core0.x$(SUFFIX): $(App_objs) $(App_libs)
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	$(LD) $(LDFLAGS) -o $@ $^ $(LDLIBS)

ComputeDevice_core1.x: bin/$(PLAT)/$(PROFILE)/ComputeDevice_core1.x$(SUFFIX)
bin/$(PLAT)/$(PROFILE)/ComputeDevice_core1.x$(SUFFIX): $(ComputeDevice_objs) $(ComputeDevice_libs)
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	$(LD) $(LDFLAGS) -o $@ $^ $(LDLIBS)

bin/$(PLAT)/$(PROFILE)/%.o$(SUFFIX): %.h
bin/$(PLAT)/$(PROFILE)/%.o$(SUFFIX): %.c
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	$(CC) $(CPPFLAGS) $(CFLAGS) --output_file=$@ -fc $<

clean::
	$(RMDIR) bin

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

# create the output directories
ifneq (clean,$(MAKECMDGOALS))
ifneq (,$(PROFILE))
ifeq (,$(wildcard bin/$(PLAT)/$(PROFILE)))
    $(shell $(MKDIR) -p bin/$(PLAT)/$(PROFILE))
endif
endif
endif
#
#  @(#) ti.sdo.opencl.examples.hello; 1, 0, 0,4; 2-22-2012 18:09:29; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

#

