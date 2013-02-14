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
#  ======== ti.sdo.rcm.examples.minidist.linux.client/makefile ========
#

# define product install paths
EXAMPLES_ROOTDIR := $(CURDIR)/../../../../../../..
-include $(EXAMPLES_ROOTDIR)/xdcpaths.mak

# repositories needed by this example
REPO_PATH ?= \
    $(FC_INSTALL_DIR)/packages \
    $(SYSLINK_INSTALL_DIR) \
    $(IPC_INSTALL_DIR)/packages \
    $(OSAL_INSTALL_DIR)/sources \
    $(EXAMPLES_ROOTDIR)

#
#  ======== standard macros ========
#
ECHO    ?= echo
MKDIR   ?= mkdir
RM      ?= rm -f
RMDIR   ?= rm -rf

ifneq (clean,$(MAKECMDGOALS))
ifneq (,$(PROFILE))
ifeq (,$(wildcard bin/$(PLAT)/$(PROFILE)))
    $(shell $(MKDIR) -p bin/$(PLAT)/$(PROFILE))
endif
endif
endif

.PHONY: nothing

#
#  ======== toolchain macros ========
#
CGTOOLS_V5T ?= <__your_CGTOOLS_V5T__>
CC_V5T ?= <__your_CC_V5T__>
SUFFIX = v5T
CC = $(CGTOOLS_V5T)/$(CC_V5T)

CCPROFILE.debug = -g -D_DEBUG_=1 
CCPROFILE.release = -O2
CFLAGS = -fPIC -Wall -fno-strict-aliasing $(CCPROFILE.$(PROFILE)) \
    -I. $(addprefix -I,$(REPO_PATH))
CPPFLAGS = -Dxdc_target_name__=GCArmv5T \
    -Dxdc_target_types__=gnu/targets/arm/std.h

LNKPROFILE.debug = -g
LNKPROFILE.release =
LDFLAGS = $(LNKPROFILE.$(PROFILE))
LDLIBS = -lpthread -lrt

#
#  ======== example sources ========
#
APP.srcs = App.c SystemCfg_host.c main_host_HLOS.c
APP.objs = $(addprefix bin/$(PLAT)/$(PROFILE)/, \
    $(patsubst %.c,%.o$(SUFFIX),$(APP.srcs)))

#
#  ======== external libraries ========
#
EXTLIBS ?=  \
    $(FC_INSTALL_DIR)/packages/ti/sdo/rcm/lib/$(PROFILE)/rcm_syslink.a$(SUFFIX)\
    $(SYSLINK_INSTALL_DIR)/ti/syslink/lib/syslink.a_release \
    ../osal/$(PROFILE)/lib/osal.a \
    ../osal/$(PROFILE)/lib/cstubs.a

#
#  ======== compute build goals from DEVICES and PROGRAMS ========
#
ifneq (,$(findstring OMAP3530,$(DEVICES)))
ifneq (,$(findstring APP_CLIENT,$(PROGRAMS)))
GOALS := $(GOALS) OMAP3530_APP_CLIENT
endif
endif

ifneq (,$(findstring TI816X,$(DEVICES)))
ifneq (,$(findstring APP_CLIENT,$(PROGRAMS)))
GOALS := $(GOALS) TI816X_APP_CLIENT
endif
endif

ifeq (,$(GOALS))
GOALS = nothing
endif

#
#  ======== make commands ========
#
all:
	$(MAKE) $(GOALS)

OMAP3530_APP_CLIENT:
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	$(MAKE) PLAT=ti_platforms_evm3530/linux PROFILE=debug \
            bin/ti_platforms_evm3530/linux/debug/ClientApp.xv5T

TI816X_APP_CLIENT:
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	$(MAKE) PLAT=ti_platforms_evmTI816X/linux PROFILE=debug \
            bin/ti_platforms_evmTI816X/linux/debug/ClientApp.xv5T

SIMTI816X_APP_CLIENT:
	$(MAKE) PLAT=ti_platforms_simTI816X/linux PROFILE=debug \
            bin/ti_platforms_simTI816X/linux/debug/ClientApp.xv5T

nothing:
	@$(ECHO) "Nothing to build for the given devices and programs"
	@$(ECHO) "    DEVICES=\"$(DEVICES)\""
	@$(ECHO) "    PROGRAMS=\"$(PROGRAMS)\""

#
#  ======== build rules ========
#
bin/$(PLAT)/$(PROFILE)/%.x$(SUFFIX): $(APP.objs) $(EXTLIBS)
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

.SECONDARY:
bin/$(PLAT)/$(PROFILE)/%.o$(SUFFIX): %.h
bin/$(PLAT)/$(PROFILE)/%.o$(SUFFIX): %.c
	@$(ECHO) "#GUNP Making the .o from .cs"
	@$(ECHO) "#"
	@$(ECHO) "# Making $@ ..."
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ -c $<

#
#  ======== clean ========
#
clean::
	$(RMDIR) bin
#
#  @(#) ti.sdo.rcm.examples.minidist.linux.client; 1,0,0,4; 2-22-2012 18:10:10; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

#

