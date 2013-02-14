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
#  The following variable is used from the environment.
#
#  ECLIPSE_HOME         full path to the ccsv4 folder
#

#
#  ======== dependencies ========
#
CCS_DIR = $(subst /C:,C:,$(subst /ccsv4/eclipse/,,$(ECLIPSE_HOME)))

FC_INSTALL_DIR    ?= $(CCS_DIR)/framework_components_your_version_number
IPC_INSTALL_DIR   ?= $(CCS_DIR)/ipc_your_version_number
XDAIS_INSTALL_DIR ?= $(CCS_DIR)/xdais_your_version_number
BIOS_INSTALL_DIR  ?= $(CCS_DIR)/bios_your_version_number
XDC_INSTALL_DIR   ?= $(CCS_DIR)/xdctools_your_version_number

TI_C6X_INSTALL_DIR      ?= $(CCS_DIR)/ccsv5/compiler/c6000
TI_ARP32_INSTALL_DIR    ?= $(CCS_DIR)/ccsv5/compiler/arp32

#
#  ======== xdc path ========
#
unexport XDC_PATH
XDC_PATH := $(FC_INSTALL_DIR)/packages
XDC_PATH := $(XDC_PATH);$(IPC_INSTALL_DIR)/packages
XDC_PATH := $(XDC_PATH);$(XDAIS_INSTALL_DIR)/packages
XDC_PATH := $(XDC_PATH);$(BIOS_INSTALL_DIR)/packages

#
#  ======== include path ========
#
INCPATH =   $(FC_INSTALL_DIR)/packages/khronos/opencl \
            $(subst ;, ,$(XDC_PATH)) $(XDC_INSTALL_DIR)/packages

#
#  ======== toolchain macros ========
#
ifeq (e674,$(SUFFIX))
CGTOOLS = $(TI_C6X_INSTALL_DIR)

CC = $(CGTOOLS)/bin/cl6x -c -mv6740 --abi=elfabi
AR = $(CGTOOLS)/bin/ar6x rq
LD = $(CGTOOLS)/bin/lnk6x --abi=elfabi

CPPFLAGS = -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h
CFLAGS = -qq -pdsw225 $(CCPROFILE_$(PROFILE)) \
    -I. $(addprefix -I,$(INCPATH)) -I$(CGTOOLS)/include

LDFLAGS = -w -q -u _c_int00 -c -m $@.map
LDLIBS = -l $(CGTOOLS)/lib/rts6740_elf.lib

CCPROFILE_debug = -D_DEBUG_=1 --symdebug:dwarf
CCPROFILE_release = -O2
endif

ifeq (earp32,$(SUFFIX))
CGTOOLS = $(TI_ARP32_INSTALL_DIR)

CC = $(CGTOOLS)/bin/cl-arp32 -c --silicon_version=v210
AR = $(CGTOOLS)/bin/ar-arp32 rq
LD = $(CGTOOLS)/bin/lnk-arp32

CPPFLAGS = -Dxdc_target_name__=ARP32 \
    -Dxdc_target_types__=ti/targets/elf/arp32/std.h \
    -Dxdc_runtime_Log_DISABLE_ALL -Dxdc_runtime_Assert_DISABLE_ALL

CFLAGS = -qq -pdsw225 $(CCPROFILE_$(PROFILE)) \
    -I. $(addprefix -I,$(INCPATH)) -I$(CGTOOLS)/include

LDFLAGS = -w -q -u _c_int00 -c -m $@.map -c
LDLIBS = -l $(CGTOOLS)/lib/rtsarp32_v200.lib

CCPROFILE_debug = -D_DEBUG_=1 -g
CCPROFILE_release = -O2
endif

#
#  ======== source files ========
#
App_srcs = SystemCfg_host_bios.c
App_objs = $(addprefix lib/$(PROFILE)/, \
    $(patsubst %.c,%.o$(SUFFIX),$(App_srcs)))

ComputeDevice_srcs = SystemCfg.c
ComputeDevice_objs = $(addprefix lib/$(PROFILE)/, \
    $(patsubst %.c,%.o$(SUFFIX),$(ComputeDevice_srcs)))

#
#  ======== make commands ========
#
all:
	$(MAKE) SUFFIX=e674 configuro_App/linker.cmd
	$(MAKE) SUFFIX=earp32 configuro_ComputeDevice/linker.cmd
	$(MAKE) PROFILE=debug SUFFIX=e674 App_systemcfg.a
	$(MAKE) PROFILE=release SUFFIX=e674 App_systemcfg.a
	$(MAKE) PROFILE=debug SUFFIX=earp32 ComputeDevice_systemcfg.a
	$(MAKE) PROFILE=release SUFFIX=earp32 ComputeDevice_systemcfg.a

#
#  ======== build rules ========
#
App_systemcfg.a: lib/$(PROFILE)/App_systemcfg.a$(SUFFIX)
lib/$(PROFILE)/App_systemcfg.a$(SUFFIX): $(App_objs)
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	@$(RM) -f $@
	$(AR) $@ $^

ComputeDevice_systemcfg.a: lib/$(PROFILE)/ComputeDevice_systemcfg.a$(SUFFIX)
lib/$(PROFILE)/ComputeDevice_systemcfg.a$(SUFFIX): $(ComputeDevice_objs)
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	@$(RM) -f $@
	$(AR) $@ $^

configuro_App/linker.cmd: App.cfg config.bld Common.cfg.xs
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	$(XDC_INSTALL_DIR)/xs --xdcpath="$(XDC_PATH)" xdc.tools.configuro \
            -c $(CGTOOLS) -o configuro_App \
            -t ti.targets.elf.C674 -p ti.platforms.simArctic:dsp \
            -b ./config.bld -r release \
            --cfgArgs "{ procName: \"DSP\", hostProcName: \"DSP\" }" \
            App.cfg

configuro_ComputeDevice/linker.cmd: ComputeDevice.cfg config.bld Common.cfg.xs
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	$(XDC_INSTALL_DIR)/xs --xdcpath="$(XDC_PATH)" xdc.tools.configuro \
            -c $(CGTOOLS) -o configuro_ComputeDevice \
            -t ti.targets.elf.arp32.ARP32 -p ti.platforms.simArctic:arp32 \
            -b ./config.bld -r release \
            --cfgArgs "{ procName: \"ARP32\", hostProcName: \"DSP\" }" \
            ComputeDevice.cfg

lib/$(PROFILE)/%.o$(SUFFIX): %.c SystemCfg.h
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	$(CC) $(CPPFLAGS) $(CFLAGS) --output_file=$@ -fc $<

clean::
	$(RMDIR) lib
	$(RMDIR) configuro_App
	$(RMDIR) configuro_ComputeDevice

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
ifeq (,$(wildcard $(PROFILE)))
    $(shell $(MKDIR) -p lib/$(PROFILE))
endif
endif
endif
#
#  @(#) ti.sdo.opencl.examples.autoviz; 1, 0, 0,4; 2-22-2012 18:09:20; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

#

