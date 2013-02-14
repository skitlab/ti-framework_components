#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.arm.elf.M3{1,0,4.9,2
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.oem3.dep
endif

package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.oem3: | .interfaces
package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.oem3: package/package_ti.sdo.fc.utils.gtinfra.c lib/debug/gt_bios.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c  -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/gt_bios/package -fr=./package/lib/lib/debug/gt_bios/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/gt_bios/package -s oem3 $< -C   -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/gt_bios/package -fr=./package/lib/lib/debug/gt_bios/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.oem3: export C_DIR=
package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.oem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.sem3: | .interfaces
package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.sem3: package/package_ti.sdo.fc.utils.gtinfra.c lib/debug/gt_bios.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 -n $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/gt_bios/package -fr=./package/lib/lib/debug/gt_bios/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/gt_bios/package -s oem3 $< -C  -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/gt_bios/package -fr=./package/lib/lib/debug/gt_bios/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.sem3: export C_DIR=
package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.sem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/gt_bios/GT_config_BIOS.oem3.dep
endif

package/lib/lib/debug/gt_bios/GT_config_BIOS.oem3: | .interfaces
package/lib/lib/debug/gt_bios/GT_config_BIOS.oem3: GT_config_BIOS.c lib/debug/gt_bios.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c  -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/gt_bios -fr=./package/lib/lib/debug/gt_bios -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/gt_bios -s oem3 $< -C   -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/gt_bios -fr=./package/lib/lib/debug/gt_bios
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/gt_bios/GT_config_BIOS.oem3: export C_DIR=
package/lib/lib/debug/gt_bios/GT_config_BIOS.oem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

package/lib/lib/debug/gt_bios/GT_config_BIOS.sem3: | .interfaces
package/lib/lib/debug/gt_bios/GT_config_BIOS.sem3: GT_config_BIOS.c lib/debug/gt_bios.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 -n $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/gt_bios -fr=./package/lib/lib/debug/gt_bios -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/gt_bios -s oem3 $< -C  -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/gt_bios -fr=./package/lib/lib/debug/gt_bios
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/gt_bios/GT_config_BIOS.sem3: export C_DIR=
package/lib/lib/debug/gt_bios/GT_config_BIOS.sem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/gt_bios/Trace.oem3.dep
endif

package/lib/lib/debug/gt_bios/Trace.oem3: | .interfaces
package/lib/lib/debug/gt_bios/Trace.oem3: Trace.c lib/debug/gt_bios.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c  -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/gt_bios -fr=./package/lib/lib/debug/gt_bios -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/gt_bios -s oem3 $< -C   -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/gt_bios -fr=./package/lib/lib/debug/gt_bios
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/gt_bios/Trace.oem3: export C_DIR=
package/lib/lib/debug/gt_bios/Trace.oem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

package/lib/lib/debug/gt_bios/Trace.sem3: | .interfaces
package/lib/lib/debug/gt_bios/Trace.sem3: Trace.c lib/debug/gt_bios.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 -n $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/gt_bios -fr=./package/lib/lib/debug/gt_bios -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/gt_bios -s oem3 $< -C  -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/lib/debug/gt_bios -fr=./package/lib/lib/debug/gt_bios
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/gt_bios/Trace.sem3: export C_DIR=
package/lib/lib/debug/gt_bios/Trace.sem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

clean,em3 ::
	-$(RM) package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.oem3
	-$(RM) package/lib/lib/debug/gt_bios/GT_config_BIOS.oem3
	-$(RM) package/lib/lib/debug/gt_bios/Trace.oem3
	-$(RM) package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.sem3
	-$(RM) package/lib/lib/debug/gt_bios/GT_config_BIOS.sem3
	-$(RM) package/lib/lib/debug/gt_bios/Trace.sem3

lib/debug/gt_bios.aem3: package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.oem3 package/lib/lib/debug/gt_bios/GT_config_BIOS.oem3 package/lib/lib/debug/gt_bios/Trace.oem3 lib/debug/gt_bios.aem3.mak

clean::
	-$(RM) lib/debug/gt_bios.aem3.mak
