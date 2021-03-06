#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.arm.elf.M3{1,0,4.9,2
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/memutils_std/package/package_ti.sdo.fc.memutils.oem3.dep
endif

package/lib/lib/debug/memutils_std/package/package_ti.sdo.fc.memutils.oem3: | .interfaces
package/lib/lib/debug/memutils_std/package/package_ti.sdo.fc.memutils.oem3: package/package_ti.sdo.fc.memutils.c lib/debug/memutils_std.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c  -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/memutils_std/package -fr=./package/lib/lib/debug/memutils_std/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/memutils_std/package -s oem3 $< -C   -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/memutils_std/package -fr=./package/lib/lib/debug/memutils_std/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/memutils_std/package/package_ti.sdo.fc.memutils.oem3: export C_DIR=
package/lib/lib/debug/memutils_std/package/package_ti.sdo.fc.memutils.oem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

package/lib/lib/debug/memutils_std/package/package_ti.sdo.fc.memutils.sem3: | .interfaces
package/lib/lib/debug/memutils_std/package/package_ti.sdo.fc.memutils.sem3: package/package_ti.sdo.fc.memutils.c lib/debug/memutils_std.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 -n $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/memutils_std/package -fr=./package/lib/lib/debug/memutils_std/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/memutils_std/package -s oem3 $< -C  -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/memutils_std/package -fr=./package/lib/lib/debug/memutils_std/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/memutils_std/package/package_ti.sdo.fc.memutils.sem3: export C_DIR=
package/lib/lib/debug/memutils_std/package/package_ti.sdo.fc.memutils.sem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/memutils_std/memutils_std.oem3.dep
endif

package/lib/lib/debug/memutils_std/memutils_std.oem3: | .interfaces
package/lib/lib/debug/memutils_std/memutils_std.oem3: memutils_std.c lib/debug/memutils_std.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c  -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/memutils_std -fr=./package/lib/lib/debug/memutils_std -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/memutils_std -s oem3 $< -C   -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/memutils_std -fr=./package/lib/lib/debug/memutils_std
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/memutils_std/memutils_std.oem3: export C_DIR=
package/lib/lib/debug/memutils_std/memutils_std.oem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

package/lib/lib/debug/memutils_std/memutils_std.sem3: | .interfaces
package/lib/lib/debug/memutils_std/memutils_std.sem3: memutils_std.c lib/debug/memutils_std.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 -n $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/memutils_std -fr=./package/lib/lib/debug/memutils_std -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/memutils_std -s oem3 $< -C  -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/memutils_std -fr=./package/lib/lib/debug/memutils_std
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/memutils_std/memutils_std.sem3: export C_DIR=
package/lib/lib/debug/memutils_std/memutils_std.sem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

clean,em3 ::
	-$(RM) package/lib/lib/debug/memutils_std/package/package_ti.sdo.fc.memutils.oem3
	-$(RM) package/lib/lib/debug/memutils_std/memutils_std.oem3
	-$(RM) package/lib/lib/debug/memutils_std/package/package_ti.sdo.fc.memutils.sem3
	-$(RM) package/lib/lib/debug/memutils_std/memutils_std.sem3

lib/debug/memutils_std.aem3: package/lib/lib/debug/memutils_std/package/package_ti.sdo.fc.memutils.oem3 package/lib/lib/debug/memutils_std/memutils_std.oem3 lib/debug/memutils_std.aem3.mak

clean::
	-$(RM) lib/debug/memutils_std.aem3.mak
