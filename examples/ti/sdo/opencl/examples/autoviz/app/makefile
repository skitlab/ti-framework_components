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

FC_INSTALL_DIR    ?= $(CCS_DIR)/framework_components_your_version_number
IPC_INSTALL_DIR   ?= $(CCS_DIR)/ipc_your_version_number
BIOS_INSTALL_DIR  ?= $(CCS_DIR)/bios_your_version_number
XDC_INSTALL_DIR   ?= $(CCS_DIR)/xdctools_your_version_number

TI_C6X_INSTALL_DIR ?= $(CCS_DIR)/ccsv5/compiler/c6000

#
#  ======== include path ========
#
INCPATH =   ../.. \
            $(FC_INSTALL_DIR)/packages/khronos/opencl \
            $(FC_INSTALL_DIR)/packages \
            $(IPC_INSTALL_DIR)/packages \
            $(BIOS_INSTALL_DIR)/packages \
            $(XDC_INSTALL_DIR)/packages

#
#  ======== toolchain macros ========
#
ifeq (e674,$(SUFFIX))
CGTOOLS = $(TI_C6X_INSTALL_DIR)

CC = $(CGTOOLS)/bin/cl6x -c -mv6740 --abi=eabi
AR = $(CGTOOLS)/bin/ar6x rq
LD = $(CGTOOLS)/bin/lnk6x --abi=eabi

CPPFLAGS = -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h
CFLAGS = -qq -pdsw225 $(CCPROFILE_$(PROFILE)) \
    -I. $(addprefix -I,$(INCPATH)) -I$(CGTOOLS)/include

LDFLAGS = -w -q -u _c_int00 -c -m $@.map
LDLIBS = -l $(CGTOOLS)/lib/rts6740_elf.lib

CCPROFILE_debug = -D_DEBUG_=1 --symdebug:dwarf
CCPROFILE_release = -O2
endif

#
#  ======== source files ========
#
App_srcs = AutoViz.c Tsr.c Pd.c
App_objs = \
    $(addprefix lib/$(PROFILE)/, \
    $(patsubst %.c,%.o$(SUFFIX),$(App_srcs)))

#
#  ======== make commands ========
#
all:
	$(MAKE) PROFILE=debug SUFFIX=e674 AutoViz.a
	$(MAKE) PROFILE=release SUFFIX=e674 AutoViz.a

#
#  ======== build rules ========
#
AutoViz.a: lib/$(PROFILE)/AutoViz.a$(SUFFIX)
lib/$(PROFILE)/AutoViz.a$(SUFFIX): $(App_objs)
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	$(AR) $@ $^

lib/$(PROFILE)/%.o$(SUFFIX): %.h
lib/$(PROFILE)/%.o$(SUFFIX): %.c
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	$(CC) $(CPPFLAGS) $(CFLAGS) --output_file=$@ -fc $<

clean::
	$(RMDIR) lib

#
#  ======== standard macros ========
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
ifeq (,$(wildcard lib/$(PROFILE)))
    $(shell $(MKDIR) -p lib/$(PROFILE))
endif
endif
endif
#
#  @(#) ti.sdo.opencl.examples.autoviz; 1, 0, 0,4; 2-22-2012 18:09:18; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

#

