#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.elf.C674{1,0,7.3,1
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.oe674.dep
endif

package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.oe674: | .interfaces
package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.oe674: package/package_ti.sdo.fc.utils.gtinfra.c lib/debug/gt_bios.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -D_DEBUG_=1 -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/debug/gt_bios/package -fr=./package/lib/lib/debug/gt_bios/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/gt_bios/package -s oe674 $< -C   -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -D_DEBUG_=1 -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/debug/gt_bios/package -fr=./package/lib/lib/debug/gt_bios/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.oe674: export C_DIR=
package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.oe674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.se674: | .interfaces
package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.se674: package/package_ti.sdo.fc.utils.gtinfra.c lib/debug/gt_bios.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 -n $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -D_DEBUG_=1 -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/debug/gt_bios/package -fr=./package/lib/lib/debug/gt_bios/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/gt_bios/package -s oe674 $< -C  -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -D_DEBUG_=1 -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/debug/gt_bios/package -fr=./package/lib/lib/debug/gt_bios/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.se674: export C_DIR=
package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.se674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/gt_bios/GT_config_BIOS.oe674.dep
endif

package/lib/lib/debug/gt_bios/GT_config_BIOS.oe674: | .interfaces
package/lib/lib/debug/gt_bios/GT_config_BIOS.oe674: GT_config_BIOS.c lib/debug/gt_bios.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -D_DEBUG_=1 -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/debug/gt_bios -fr=./package/lib/lib/debug/gt_bios -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/gt_bios -s oe674 $< -C   -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -D_DEBUG_=1 -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/debug/gt_bios -fr=./package/lib/lib/debug/gt_bios
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/gt_bios/GT_config_BIOS.oe674: export C_DIR=
package/lib/lib/debug/gt_bios/GT_config_BIOS.oe674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

package/lib/lib/debug/gt_bios/GT_config_BIOS.se674: | .interfaces
package/lib/lib/debug/gt_bios/GT_config_BIOS.se674: GT_config_BIOS.c lib/debug/gt_bios.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 -n $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -D_DEBUG_=1 -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/debug/gt_bios -fr=./package/lib/lib/debug/gt_bios -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/gt_bios -s oe674 $< -C  -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -D_DEBUG_=1 -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/debug/gt_bios -fr=./package/lib/lib/debug/gt_bios
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/gt_bios/GT_config_BIOS.se674: export C_DIR=
package/lib/lib/debug/gt_bios/GT_config_BIOS.se674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/debug/gt_bios/Trace.oe674.dep
endif

package/lib/lib/debug/gt_bios/Trace.oe674: | .interfaces
package/lib/lib/debug/gt_bios/Trace.oe674: Trace.c lib/debug/gt_bios.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -D_DEBUG_=1 -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/debug/gt_bios -fr=./package/lib/lib/debug/gt_bios -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/gt_bios -s oe674 $< -C   -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -D_DEBUG_=1 -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/debug/gt_bios -fr=./package/lib/lib/debug/gt_bios
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/gt_bios/Trace.oe674: export C_DIR=
package/lib/lib/debug/gt_bios/Trace.oe674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

package/lib/lib/debug/gt_bios/Trace.se674: | .interfaces
package/lib/lib/debug/gt_bios/Trace.se674: Trace.c lib/debug/gt_bios.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 -n $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -D_DEBUG_=1 -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/debug/gt_bios -fr=./package/lib/lib/debug/gt_bios -fc $<
	$(MKDEP) -a $@.dep -p package/lib/lib/debug/gt_bios -s oe674 $< -C  -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -D_DEBUG_=1 -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/lib/debug/gt_bios -fr=./package/lib/lib/debug/gt_bios
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/debug/gt_bios/Trace.se674: export C_DIR=
package/lib/lib/debug/gt_bios/Trace.se674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

clean,e674 ::
	-$(RM) package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.oe674
	-$(RM) package/lib/lib/debug/gt_bios/GT_config_BIOS.oe674
	-$(RM) package/lib/lib/debug/gt_bios/Trace.oe674
	-$(RM) package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.se674
	-$(RM) package/lib/lib/debug/gt_bios/GT_config_BIOS.se674
	-$(RM) package/lib/lib/debug/gt_bios/Trace.se674

lib/debug/gt_bios.ae674: package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.oe674 package/lib/lib/debug/gt_bios/GT_config_BIOS.oe674 package/lib/lib/debug/gt_bios/Trace.oe674 lib/debug/gt_bios.ae674.mak

clean::
	-$(RM) lib/debug/gt_bios.ae674.mak
