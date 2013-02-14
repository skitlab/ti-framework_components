#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.arm.elf.M3{1,0,4.9,2
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/release/tiler_stub/package/package_ti.sdo.tiler.oem3.dep
endif

package/lib/release/tiler_stub/package/package_ti.sdo.tiler.oem3: | .interfaces
package/lib/release/tiler_stub/package/package_ti.sdo.tiler.oem3: package/package_ti.sdo.tiler.c lib/release/tiler_stub.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c  -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_9_2 -O2 -I src/memmgr  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/release/tiler_stub/package -fr=./package/lib/release/tiler_stub/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/release/tiler_stub/package -s oem3 $< -C   -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_9_2 -O2 -I src/memmgr  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/release/tiler_stub/package -fr=./package/lib/release/tiler_stub/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/release/tiler_stub/package/package_ti.sdo.tiler.oem3: export C_DIR=
package/lib/release/tiler_stub/package/package_ti.sdo.tiler.oem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

package/lib/release/tiler_stub/package/package_ti.sdo.tiler.sem3: | .interfaces
package/lib/release/tiler_stub/package/package_ti.sdo.tiler.sem3: package/package_ti.sdo.tiler.c lib/release/tiler_stub.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 -n $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_9_2 -O2 -I src/memmgr  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/release/tiler_stub/package -fr=./package/lib/release/tiler_stub/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/release/tiler_stub/package -s oem3 $< -C  -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_9_2 -O2 -I src/memmgr  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/release/tiler_stub/package -fr=./package/lib/release/tiler_stub/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/release/tiler_stub/package/package_ti.sdo.tiler.sem3: export C_DIR=
package/lib/release/tiler_stub/package/package_ti.sdo.tiler.sem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/release/tiler_stub/src/remote/MemMgr_stub.oem3.dep
endif

package/lib/release/tiler_stub/src/remote/MemMgr_stub.oem3: | .interfaces
package/lib/release/tiler_stub/src/remote/MemMgr_stub.oem3: src/remote/MemMgr_stub.c lib/release/tiler_stub.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c  -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_9_2 -O2 -I src/memmgr  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/release/tiler_stub/src/remote -fr=./package/lib/release/tiler_stub/src/remote -fc $<
	$(MKDEP) -a $@.dep -p package/lib/release/tiler_stub/src/remote -s oem3 $< -C   -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_9_2 -O2 -I src/memmgr  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/release/tiler_stub/src/remote -fr=./package/lib/release/tiler_stub/src/remote
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/release/tiler_stub/src/remote/MemMgr_stub.oem3: export C_DIR=
package/lib/release/tiler_stub/src/remote/MemMgr_stub.oem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

package/lib/release/tiler_stub/src/remote/MemMgr_stub.sem3: | .interfaces
package/lib/release/tiler_stub/src/remote/MemMgr_stub.sem3: src/remote/MemMgr_stub.c lib/release/tiler_stub.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 -n $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_9_2 -O2 -I src/memmgr  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/release/tiler_stub/src/remote -fr=./package/lib/release/tiler_stub/src/remote -fc $<
	$(MKDEP) -a $@.dep -p package/lib/release/tiler_stub/src/remote -s oem3 $< -C  -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_9_2 -O2 -I src/memmgr  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/release/tiler_stub/src/remote -fr=./package/lib/release/tiler_stub/src/remote
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/release/tiler_stub/src/remote/MemMgr_stub.sem3: export C_DIR=
package/lib/release/tiler_stub/src/remote/MemMgr_stub.sem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/release/tiler_stub/Settings.oem3.dep
endif

package/lib/release/tiler_stub/Settings.oem3: | .interfaces
package/lib/release/tiler_stub/Settings.oem3: Settings.c lib/release/tiler_stub.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c  -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_9_2 -O2 -I src/memmgr  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/release/tiler_stub -fr=./package/lib/release/tiler_stub -fc $<
	$(MKDEP) -a $@.dep -p package/lib/release/tiler_stub -s oem3 $< -C   -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_9_2 -O2 -I src/memmgr  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/release/tiler_stub -fr=./package/lib/release/tiler_stub
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/release/tiler_stub/Settings.oem3: export C_DIR=
package/lib/release/tiler_stub/Settings.oem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

package/lib/release/tiler_stub/Settings.sem3: | .interfaces
package/lib/release/tiler_stub/Settings.sem3: Settings.c lib/release/tiler_stub.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 -n $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_9_2 -O2 -I src/memmgr  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/release/tiler_stub -fr=./package/lib/release/tiler_stub -fc $<
	$(MKDEP) -a $@.dep -p package/lib/release/tiler_stub -s oem3 $< -C  -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_9_2 -O2 -I src/memmgr  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/release/tiler_stub -fr=./package/lib/release/tiler_stub
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/release/tiler_stub/Settings.sem3: export C_DIR=
package/lib/release/tiler_stub/Settings.sem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

clean,em3 ::
	-$(RM) package/lib/release/tiler_stub/package/package_ti.sdo.tiler.oem3
	-$(RM) package/lib/release/tiler_stub/src/remote/MemMgr_stub.oem3
	-$(RM) package/lib/release/tiler_stub/Settings.oem3
	-$(RM) package/lib/release/tiler_stub/package/package_ti.sdo.tiler.sem3
	-$(RM) package/lib/release/tiler_stub/src/remote/MemMgr_stub.sem3
	-$(RM) package/lib/release/tiler_stub/Settings.sem3

lib/release/tiler_stub.aem3: package/lib/release/tiler_stub/package/package_ti.sdo.tiler.oem3 package/lib/release/tiler_stub/src/remote/MemMgr_stub.oem3 package/lib/release/tiler_stub/Settings.oem3 lib/release/tiler_stub.aem3.mak

clean::
	-$(RM) lib/release/tiler_stub.aem3.mak