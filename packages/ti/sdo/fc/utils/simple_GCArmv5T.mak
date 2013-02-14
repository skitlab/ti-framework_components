#
#  Copyright 2012 by Texas Instruments Incorporated.
#  
#

# Generated by build.filter.Make on Tue Feb 21 2012 15:26:37 GMT-0800 (PST)
#
# SEARCHPATH is a semicolon-delimited directory list of dependencies
#
SEARCHPATH ?= $(PKG_PATH)

#
# Set LIBDIR to the directory where libraries are created
#
LIBDIR ?= .objs

#
# Macro definitions referenced below
#
empty =
space =$(empty) $(empty)
INCS = -I. -I$(strip $(subst ;, -I,$(subst $(space),\$(space),$(SEARCHPATH))))
RM = rm -f
MKDIR = mkdir -p
RMDIR = rm -rf

.PHONY: all clean initialize

all: initialize
initialize:
	-@$(MKDIR) .objs
ifneq (.objs,$(LIBDIR))
	-@$(MKDIR) $(LIBDIR)
endif

clean::
	-$(RMDIR) .objs
clean::
	-$(RMDIR) $(LIBDIR)
gnu.targets.arm.GCArmv5T.rootDir ?= $(CGT_ARM_INSTALL_DIR)

.objs/shmMp_shmmp.ov5T: shmmp.c
	 $(CGTOOLS_V5T)/$(CC_V5T) -c -MD -MF $@.dep -x c  -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -Dfar=   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1    -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_2_0 -O2 -ffunction-sections  $(INCS)  -o $@ $<
	 
all: .objs/shmMp_shmmp.ov5T
clean::
	-$(RM) .objs/shmMp_shmmp.ov5T

$(LIBDIR)/shmMp.av5T: .objs/shmMp_shmmp.ov5T 
	 $(CGTOOLS_V5T)/$(AR_V5T) cr $@ $^
all: $(LIBDIR)/shmMp.av5T
clean::
	-$(RM) $(LIBDIR)/shmMp.av5T

.objs/rmm_rmm.ov5T: rmm.c
	 $(CGTOOLS_V5T)/$(CC_V5T) -c -MD -MF $@.dep -x c  -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -Dfar=   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1   -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_2_0 -O2 -ffunction-sections  $(INCS)  -o $@ $<
	 
all: .objs/rmm_rmm.ov5T
clean::
	-$(RM) .objs/rmm_rmm.ov5T

.objs/rmm_bios_rts.ov5T: bios_rts.c
	 $(CGTOOLS_V5T)/$(CC_V5T) -c -MD -MF $@.dep -x c  -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -Dfar=   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1   -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_2_0 -O2 -ffunction-sections  $(INCS)  -o $@ $<
	 
all: .objs/rmm_bios_rts.ov5T
clean::
	-$(RM) .objs/rmm_bios_rts.ov5T

$(LIBDIR)/rmm.av5T: .objs/rmm_rmm.ov5T .objs/rmm_bios_rts.ov5T 
	 $(CGTOOLS_V5T)/$(AR_V5T) cr $@ $^
all: $(LIBDIR)/rmm.av5T
clean::
	-$(RM) $(LIBDIR)/rmm.av5T

.objs/rmmp_rmmp.ov5T: rmmp.c
	 $(CGTOOLS_V5T)/$(CC_V5T) -c -MD -MF $@.dep -x c  -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -Dfar=   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1   -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_2_0 -O2 -ffunction-sections  $(INCS)  -o $@ $<
	 
all: .objs/rmmp_rmmp.ov5T
clean::
	-$(RM) .objs/rmmp_rmmp.ov5T

.objs/rmmp_rmm.ov5T: rmm.c
	 $(CGTOOLS_V5T)/$(CC_V5T) -c -MD -MF $@.dep -x c  -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -Dfar=   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1   -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_2_0 -O2 -ffunction-sections  $(INCS)  -o $@ $<
	 
all: .objs/rmmp_rmm.ov5T
clean::
	-$(RM) .objs/rmmp_rmm.ov5T

$(LIBDIR)/rmmp.av5T: .objs/rmmp_rmmp.ov5T .objs/rmmp_rmm.ov5T 
	 $(CGTOOLS_V5T)/$(AR_V5T) cr $@ $^
all: $(LIBDIR)/rmmp.av5T
clean::
	-$(RM) $(LIBDIR)/rmmp.av5T

.objs/smgrmp_smgrmp.ov5T: smgrmp.c
	 $(CGTOOLS_V5T)/$(CC_V5T) -c -MD -MF $@.dep -x c  -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -Dfar=   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1   -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_2_0 -O2 -ffunction-sections  $(INCS)  -o $@ $<
	 
all: .objs/smgrmp_smgrmp.ov5T
clean::
	-$(RM) .objs/smgrmp_smgrmp.ov5T

.objs/smgrmp_smgr.ov5T: smgr.c
	 $(CGTOOLS_V5T)/$(CC_V5T) -c -MD -MF $@.dep -x c  -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -Dfar=   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1   -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_2_0 -O2 -ffunction-sections  $(INCS)  -o $@ $<
	 
all: .objs/smgrmp_smgr.ov5T
clean::
	-$(RM) .objs/smgrmp_smgr.ov5T

$(LIBDIR)/smgrmp.av5T: .objs/smgrmp_smgrmp.ov5T .objs/smgrmp_smgr.ov5T 
	 $(CGTOOLS_V5T)/$(AR_V5T) cr $@ $^
all: $(LIBDIR)/smgrmp.av5T
clean::
	-$(RM) $(LIBDIR)/smgrmp.av5T

.objs/smgr_smgr.ov5T: smgr.c
	 $(CGTOOLS_V5T)/$(CC_V5T) -c -MD -MF $@.dep -x c  -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -Dfar=   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1   -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_2_0 -O2 -ffunction-sections  $(INCS)  -o $@ $<
	 
all: .objs/smgr_smgr.ov5T
clean::
	-$(RM) .objs/smgr_smgr.ov5T

$(LIBDIR)/smgr.av5T: .objs/smgr_smgr.ov5T 
	 $(CGTOOLS_V5T)/$(AR_V5T) cr $@ $^
all: $(LIBDIR)/smgr.av5T
clean::
	-$(RM) $(LIBDIR)/smgr.av5T

.objs/shmNonMp_shm.ov5T: shm.c
	 $(CGTOOLS_V5T)/$(CC_V5T) -c -MD -MF $@.dep -x c  -fPIC -Wunused -Wall -fno-strict-aliasing  -march=armv5t -Dfar=   -DDBC_ASSERTS=0 -Dxdc_runtime_Assert_DISABLE_ALL=1    -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_2_0 -O2 -ffunction-sections  $(INCS)  -o $@ $<
	 
all: .objs/shmNonMp_shm.ov5T
clean::
	-$(RM) .objs/shmNonMp_shm.ov5T

$(LIBDIR)/shmNonMp.av5T: .objs/shmNonMp_shm.ov5T 
	 $(CGTOOLS_V5T)/$(AR_V5T) cr $@ $^
all: $(LIBDIR)/shmNonMp.av5T
clean::
	-$(RM) $(LIBDIR)/shmNonMp.av5T
#
#  @(#) ti.sdo.fc.utils; 1, 0, 3,4; 2-22-2012 18:08:42; /db/atree/library/trees/fc/fc-q07/src/ xlibrary

#

