#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.elf.C674{1,0,7.3,1
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/release/rcm/package/package_ti.sdo.rcm.oe674.dep
endif

package/lib/release/rcm/package/package_ti.sdo.rcm.oe674: | .interfaces
package/lib/release/rcm/package/package_ti.sdo.rcm.oe674: package/package_ti.sdo.rcm.c lib/release/rcm.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_3_1 -O2  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/release/rcm/package -fr=./package/lib/release/rcm/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/release/rcm/package -s oe674 $< -C   -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_3_1 -O2  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/release/rcm/package -fr=./package/lib/release/rcm/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/release/rcm/package/package_ti.sdo.rcm.oe674: export C_DIR=
package/lib/release/rcm/package/package_ti.sdo.rcm.oe674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

package/lib/release/rcm/package/package_ti.sdo.rcm.se674: | .interfaces
package/lib/release/rcm/package/package_ti.sdo.rcm.se674: package/package_ti.sdo.rcm.c lib/release/rcm.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 -n $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_3_1 -O2  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/release/rcm/package -fr=./package/lib/release/rcm/package -fc $<
	$(MKDEP) -a $@.dep -p package/lib/release/rcm/package -s oe674 $< -C  -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_3_1 -O2  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/release/rcm/package -fr=./package/lib/release/rcm/package
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/release/rcm/package/package_ti.sdo.rcm.se674: export C_DIR=
package/lib/release/rcm/package/package_ti.sdo.rcm.se674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/release/rcm/RcmClient.oe674.dep
endif

package/lib/release/rcm/RcmClient.oe674: | .interfaces
package/lib/release/rcm/RcmClient.oe674: RcmClient.c lib/release/rcm.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_3_1 -O2  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/release/rcm -fr=./package/lib/release/rcm -fc $<
	$(MKDEP) -a $@.dep -p package/lib/release/rcm -s oe674 $< -C   -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_3_1 -O2  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/release/rcm -fr=./package/lib/release/rcm
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/release/rcm/RcmClient.oe674: export C_DIR=
package/lib/release/rcm/RcmClient.oe674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

package/lib/release/rcm/RcmClient.se674: | .interfaces
package/lib/release/rcm/RcmClient.se674: RcmClient.c lib/release/rcm.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 -n $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_3_1 -O2  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/release/rcm -fr=./package/lib/release/rcm -fc $<
	$(MKDEP) -a $@.dep -p package/lib/release/rcm -s oe674 $< -C  -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_3_1 -O2  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/release/rcm -fr=./package/lib/release/rcm
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/release/rcm/RcmClient.se674: export C_DIR=
package/lib/release/rcm/RcmClient.se674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/release/rcm/RcmServer.oe674.dep
endif

package/lib/release/rcm/RcmServer.oe674: | .interfaces
package/lib/release/rcm/RcmServer.oe674: RcmServer.c lib/release/rcm.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_3_1 -O2  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/release/rcm -fr=./package/lib/release/rcm -fc $<
	$(MKDEP) -a $@.dep -p package/lib/release/rcm -s oe674 $< -C   -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_3_1 -O2  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/release/rcm -fr=./package/lib/release/rcm
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/release/rcm/RcmServer.oe674: export C_DIR=
package/lib/release/rcm/RcmServer.oe674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

package/lib/release/rcm/RcmServer.se674: | .interfaces
package/lib/release/rcm/RcmServer.se674: RcmServer.c lib/release/rcm.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 -n $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_3_1 -O2  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/release/rcm -fr=./package/lib/release/rcm -fc $<
	$(MKDEP) -a $@.dep -p package/lib/release/rcm -s oe674 $< -C  -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_3_1 -O2  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/release/rcm -fr=./package/lib/release/rcm
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/release/rcm/RcmServer.se674: export C_DIR=
package/lib/release/rcm/RcmServer.se674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

ifeq (,$(MK_NOGENDEPS))
-include package/lib/release/rcm/RcmUtils.oe674.dep
endif

package/lib/release/rcm/RcmUtils.oe674: | .interfaces
package/lib/release/rcm/RcmUtils.oe674: RcmUtils.c lib/release/rcm.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c  -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_3_1 -O2  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/release/rcm -fr=./package/lib/release/rcm -fc $<
	$(MKDEP) -a $@.dep -p package/lib/release/rcm -s oe674 $< -C   -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_3_1 -O2  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/release/rcm -fr=./package/lib/release/rcm
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/release/rcm/RcmUtils.oe674: export C_DIR=
package/lib/release/rcm/RcmUtils.oe674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

package/lib/release/rcm/RcmUtils.se674: | .interfaces
package/lib/release/rcm/RcmUtils.se674: RcmUtils.c lib/release/rcm.ae674.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle674 -n $< ...
	$(ti.targets.elf.C674.rootDir)/bin/cl6x -c -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_3_1 -O2  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/release/rcm -fr=./package/lib/release/rcm -fc $<
	$(MKDEP) -a $@.dep -p package/lib/release/rcm -s oe674 $< -C  -n -s --symdebug:none -qq -pdsw225 -mv6740 --abi=eabi -eo.oe674 -ea.se674  -pdr -pden -pds=880 -pds=238 -pds452 -pds195 -mi10 -mo -g  -DRCM_ti_sdo_ipc -Dxdc_target_name__=C674 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_3_1 -O2  $(XDCINCS) -I$(ti.targets.elf.C674.rootDir)/include -fs=./package/lib/release/rcm -fr=./package/lib/release/rcm
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/release/rcm/RcmUtils.se674: export C_DIR=
package/lib/release/rcm/RcmUtils.se674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

clean,e674 ::
	-$(RM) package/lib/release/rcm/package/package_ti.sdo.rcm.oe674
	-$(RM) package/lib/release/rcm/RcmClient.oe674
	-$(RM) package/lib/release/rcm/RcmServer.oe674
	-$(RM) package/lib/release/rcm/RcmUtils.oe674
	-$(RM) package/lib/release/rcm/package/package_ti.sdo.rcm.se674
	-$(RM) package/lib/release/rcm/RcmClient.se674
	-$(RM) package/lib/release/rcm/RcmServer.se674
	-$(RM) package/lib/release/rcm/RcmUtils.se674

lib/release/rcm.ae674: package/lib/release/rcm/package/package_ti.sdo.rcm.oe674 package/lib/release/rcm/RcmClient.oe674 package/lib/release/rcm/RcmServer.oe674 package/lib/release/rcm/RcmUtils.oe674 lib/release/rcm.ae674.mak

clean::
	-$(RM) lib/release/rcm.ae674.mak
