#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.arm.elf.M3{1,0,4.9,2
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/debug/opencl_platform_c6472/package/package_ti.sdo.opencl.platforms.c6472.oem3.dep
endif

package/lib/debug/opencl_platform_c6472/package/package_ti.sdo.opencl.platforms.c6472.oem3: | .interfaces
package/lib/debug/opencl_platform_c6472/package/package_ti.sdo.opencl.platforms.c6472.oem3: package/package_ti.sdo.opencl.platforms.c6472.c lib/debug/opencl_platform_c6472.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c  -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf -I/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/framework_components_3_22_01_07/packages/khronos/opencl/ $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/debug/opencl_platform_c6472/package -fr=./package/lib/debug/opencl_platform_c6472/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/debug/opencl_platform_c6472/package -s oem3 $< -C   -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf -I/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/framework_components_3_22_01_07/packages/khronos/opencl/ $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/debug/opencl_platform_c6472/package -fr=./package/lib/debug/opencl_platform_c6472/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/debug/opencl_platform_c6472/package/package_ti.sdo.opencl.platforms.c6472.oem3: export C_DIR=
package/lib/debug/opencl_platform_c6472/package/package_ti.sdo.opencl.platforms.c6472.oem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

package/lib/debug/opencl_platform_c6472/package/package_ti.sdo.opencl.platforms.c6472.sem3: | .interfaces
package/lib/debug/opencl_platform_c6472/package/package_ti.sdo.opencl.platforms.c6472.sem3: package/package_ti.sdo.opencl.platforms.c6472.c lib/debug/opencl_platform_c6472.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 -n $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf -I/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/framework_components_3_22_01_07/packages/khronos/opencl/ $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/debug/opencl_platform_c6472/package -fr=./package/lib/debug/opencl_platform_c6472/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/debug/opencl_platform_c6472/package -s oem3 $< -C  -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf -I/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/framework_components_3_22_01_07/packages/khronos/opencl/ $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/debug/opencl_platform_c6472/package -fr=./package/lib/debug/opencl_platform_c6472/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/debug/opencl_platform_c6472/package/package_ti.sdo.opencl.platforms.c6472.sem3: export C_DIR=
package/lib/debug/opencl_platform_c6472/package/package_ti.sdo.opencl.platforms.c6472.sem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/debug/opencl_platform_c6472/Device.oem3.dep
endif

package/lib/debug/opencl_platform_c6472/Device.oem3: | .interfaces
package/lib/debug/opencl_platform_c6472/Device.oem3: Device.c lib/debug/opencl_platform_c6472.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c  -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf -I/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/framework_components_3_22_01_07/packages/khronos/opencl/ $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/debug/opencl_platform_c6472 -fr=./package/lib/debug/opencl_platform_c6472 -fc $<
	$(MKDEP) -a $@.dep -p package/lib/debug/opencl_platform_c6472 -s oem3 $< -C   -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf -I/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/framework_components_3_22_01_07/packages/khronos/opencl/ $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/debug/opencl_platform_c6472 -fr=./package/lib/debug/opencl_platform_c6472
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/debug/opencl_platform_c6472/Device.oem3: export C_DIR=
package/lib/debug/opencl_platform_c6472/Device.oem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

package/lib/debug/opencl_platform_c6472/Device.sem3: | .interfaces
package/lib/debug/opencl_platform_c6472/Device.sem3: Device.c lib/debug/opencl_platform_c6472.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 -n $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf -I/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/framework_components_3_22_01_07/packages/khronos/opencl/ $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/debug/opencl_platform_c6472 -fr=./package/lib/debug/opencl_platform_c6472 -fc $<
	$(MKDEP) -a $@.dep -p package/lib/debug/opencl_platform_c6472 -s oem3 $< -C  -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf -I/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/framework_components_3_22_01_07/packages/khronos/opencl/ $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/debug/opencl_platform_c6472 -fr=./package/lib/debug/opencl_platform_c6472
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/debug/opencl_platform_c6472/Device.sem3: export C_DIR=
package/lib/debug/opencl_platform_c6472/Device.sem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/debug/opencl_platform_c6472/Platform.oem3.dep
endif

package/lib/debug/opencl_platform_c6472/Platform.oem3: | .interfaces
package/lib/debug/opencl_platform_c6472/Platform.oem3: Platform.c lib/debug/opencl_platform_c6472.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c  -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf -I/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/framework_components_3_22_01_07/packages/khronos/opencl/ $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/debug/opencl_platform_c6472 -fr=./package/lib/debug/opencl_platform_c6472 -fc $<
	$(MKDEP) -a $@.dep -p package/lib/debug/opencl_platform_c6472 -s oem3 $< -C   -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf -I/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/framework_components_3_22_01_07/packages/khronos/opencl/ $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/debug/opencl_platform_c6472 -fr=./package/lib/debug/opencl_platform_c6472
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/debug/opencl_platform_c6472/Platform.oem3: export C_DIR=
package/lib/debug/opencl_platform_c6472/Platform.oem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

package/lib/debug/opencl_platform_c6472/Platform.sem3: | .interfaces
package/lib/debug/opencl_platform_c6472/Platform.sem3: Platform.c lib/debug/opencl_platform_c6472.aem3.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clem3 -n $< ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/cl470 -c -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf -I/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/framework_components_3_22_01_07/packages/khronos/opencl/ $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/debug/opencl_platform_c6472 -fr=./package/lib/debug/opencl_platform_c6472 -fc $<
	$(MKDEP) -a $@.dep -p package/lib/debug/opencl_platform_c6472 -s oem3 $< -C  -n -s --symdebug:none -qq -pdsw225 --endian=little -mv7M3 --abi=eabi -eo.oem3 -ea.sem3  -ms -g  -D_DEBUG_=1 -Dxdc_target_name__=M3 -Dxdc_target_types__=ti/targets/arm/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_4_9_2 --symdebug:dwarf -I/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/framework_components_3_22_01_07/packages/khronos/opencl/ $(XDCINCS) -I$(ti.targets.arm.elf.M3.rootDir)/include/rts -I$(ti.targets.arm.elf.M3.rootDir)/include  -fs=./package/lib/debug/opencl_platform_c6472 -fr=./package/lib/debug/opencl_platform_c6472
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/debug/opencl_platform_c6472/Platform.sem3: export C_DIR=
package/lib/debug/opencl_platform_c6472/Platform.sem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

clean,em3 ::
	-$(RM) package/lib/debug/opencl_platform_c6472/package/package_ti.sdo.opencl.platforms.c6472.oem3
	-$(RM) package/lib/debug/opencl_platform_c6472/Device.oem3
	-$(RM) package/lib/debug/opencl_platform_c6472/Platform.oem3
	-$(RM) package/lib/debug/opencl_platform_c6472/package/package_ti.sdo.opencl.platforms.c6472.sem3
	-$(RM) package/lib/debug/opencl_platform_c6472/Device.sem3
	-$(RM) package/lib/debug/opencl_platform_c6472/Platform.sem3

lib/debug/opencl_platform_c6472.aem3: package/lib/debug/opencl_platform_c6472/package/package_ti.sdo.opencl.platforms.c6472.oem3 package/lib/debug/opencl_platform_c6472/Device.oem3 package/lib/debug/opencl_platform_c6472/Platform.oem3 lib/debug/opencl_platform_c6472.aem3.mak

clean::
	-$(RM) lib/debug/opencl_platform_c6472.aem3.mak
