#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.elf.C674{1,0,7.3,1
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/debug/rcm/package/package_ti.sdo.rcm.oe674.dep
endif

package/lib/debug/rcm/package/package_ti.sdo.rcm.oe674: | .interfaces
package/lib/debug/rcm/package/package_ti.sdo.rcm.oe674: package/package_ti.sdo.rcm.c lib/debug/rcm.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -D_DEBUG_=1 -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/debug/rcm/package -fr=./package/lib/debug/rcm/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/debug/rcm/package -s oe674 $< -C   -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -D_DEBUG_=1 -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/debug/rcm/package -fr=./package/lib/debug/rcm/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/debug/rcm/package/package_ti.sdo.rcm.oe674: export C_DIR=
package/lib/debug/rcm/package/package_ti.sdo.rcm.oe674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

package/lib/debug/rcm/package/package_ti.sdo.rcm.se674: | .interfaces
package/lib/debug/rcm/package/package_ti.sdo.rcm.se674: package/package_ti.sdo.rcm.c lib/debug/rcm.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 -n $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -D_DEBUG_=1 -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/debug/rcm/package -fr=./package/lib/debug/rcm/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/debug/rcm/package -s oe674 $< -C  -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -D_DEBUG_=1 -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/debug/rcm/package -fr=./package/lib/debug/rcm/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/debug/rcm/package/package_ti.sdo.rcm.se674: export C_DIR=
package/lib/debug/rcm/package/package_ti.sdo.rcm.se674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/debug/rcm/RcmClient.oe674.dep
endif

package/lib/debug/rcm/RcmClient.oe674: | .interfaces
package/lib/debug/rcm/RcmClient.oe674: RcmClient.c lib/debug/rcm.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -D_DEBUG_=1 -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/debug/rcm -fr=./package/lib/debug/rcm -fc $<
	$(MKDEP) -a $@.dep -p package/lib/debug/rcm -s oe674 $< -C   -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -D_DEBUG_=1 -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/debug/rcm -fr=./package/lib/debug/rcm
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/debug/rcm/RcmClient.oe674: export C_DIR=
package/lib/debug/rcm/RcmClient.oe674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

package/lib/debug/rcm/RcmClient.se674: | .interfaces
package/lib/debug/rcm/RcmClient.se674: RcmClient.c lib/debug/rcm.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 -n $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -D_DEBUG_=1 -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/debug/rcm -fr=./package/lib/debug/rcm -fc $<
	$(MKDEP) -a $@.dep -p package/lib/debug/rcm -s oe674 $< -C  -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -D_DEBUG_=1 -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/debug/rcm -fr=./package/lib/debug/rcm
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/debug/rcm/RcmClient.se674: export C_DIR=
package/lib/debug/rcm/RcmClient.se674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/debug/rcm/RcmServer.oe674.dep
endif

package/lib/debug/rcm/RcmServer.oe674: | .interfaces
package/lib/debug/rcm/RcmServer.oe674: RcmServer.c lib/debug/rcm.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -D_DEBUG_=1 -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/debug/rcm -fr=./package/lib/debug/rcm -fc $<
	$(MKDEP) -a $@.dep -p package/lib/debug/rcm -s oe674 $< -C   -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -D_DEBUG_=1 -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/debug/rcm -fr=./package/lib/debug/rcm
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/debug/rcm/RcmServer.oe674: export C_DIR=
package/lib/debug/rcm/RcmServer.oe674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

package/lib/debug/rcm/RcmServer.se674: | .interfaces
package/lib/debug/rcm/RcmServer.se674: RcmServer.c lib/debug/rcm.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 -n $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -D_DEBUG_=1 -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/debug/rcm -fr=./package/lib/debug/rcm -fc $<
	$(MKDEP) -a $@.dep -p package/lib/debug/rcm -s oe674 $< -C  -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -D_DEBUG_=1 -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/debug/rcm -fr=./package/lib/debug/rcm
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/debug/rcm/RcmServer.se674: export C_DIR=
package/lib/debug/rcm/RcmServer.se674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/debug/rcm/RcmUtils.oe674.dep
endif

package/lib/debug/rcm/RcmUtils.oe674: | .interfaces
package/lib/debug/rcm/RcmUtils.oe674: RcmUtils.c lib/debug/rcm.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -D_DEBUG_=1 -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/debug/rcm -fr=./package/lib/debug/rcm -fc $<
	$(MKDEP) -a $@.dep -p package/lib/debug/rcm -s oe674 $< -C   -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -D_DEBUG_=1 -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/debug/rcm -fr=./package/lib/debug/rcm
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/debug/rcm/RcmUtils.oe674: export C_DIR=
package/lib/debug/rcm/RcmUtils.oe674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

package/lib/debug/rcm/RcmUtils.se674: | .interfaces
package/lib/debug/rcm/RcmUtils.se674: RcmUtils.c lib/debug/rcm.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 -n $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -D_DEBUG_=1 -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/debug/rcm -fr=./package/lib/debug/rcm -fc $<
	$(MKDEP) -a $@.dep -p package/lib/debug/rcm -s oe674 $< -C  -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -D_DEBUG_=1 -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_debug -Dxdc_bld__vers_1_0_7_3_1 --symdebug:dwarf  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/debug/rcm -fr=./package/lib/debug/rcm
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/debug/rcm/RcmUtils.se674: export C_DIR=
package/lib/debug/rcm/RcmUtils.se674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

clean,e674 ::
	-$(RM) package/lib/debug/rcm/package/package_ti.sdo.rcm.oe674
	-$(RM) package/lib/debug/rcm/RcmClient.oe674
	-$(RM) package/lib/debug/rcm/RcmServer.oe674
	-$(RM) package/lib/debug/rcm/RcmUtils.oe674
	-$(RM) package/lib/debug/rcm/package/package_ti.sdo.rcm.se674
	-$(RM) package/lib/debug/rcm/RcmClient.se674
	-$(RM) package/lib/debug/rcm/RcmServer.se674
	-$(RM) package/lib/debug/rcm/RcmUtils.se674

lib/debug/rcm.ae674: package/lib/debug/rcm/package/package_ti.sdo.rcm.oe674 package/lib/debug/rcm/RcmClient.oe674 package/lib/debug/rcm/RcmServer.oe674 package/lib/debug/rcm/RcmUtils.oe674 lib/debug/rcm.ae674.mak

clean::
	-$(RM) lib/debug/rcm.ae674.mak