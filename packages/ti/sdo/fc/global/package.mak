#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#

unexport MAKEFILE_LIST
MK_NOGENDEPS := $(filter clean,$(MAKECMDGOALS))
override PKGDIR = ti/sdo/fc/global
XDCINCS = -I. -I$(strip $(subst ;, -I,$(subst $(space),\$(space),$(XPKGPATH))))
XDCCFGDIR = package/cfg/

#
# The following dependencies ensure package.mak is rebuilt
# in the event that some included BOM script changes.
#
ifneq (clean,$(MAKECMDGOALS))
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/include/utils.tci:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/include/utils.tci
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/xdc.tci:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/xdc.tci
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/template.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/template.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/om2.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/om2.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/xmlgen.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/xmlgen.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/xmlgen2.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/xmlgen2.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/IPackage.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/IPackage.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/package.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/package.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/services/global/Clock.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/services/global/Clock.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/services/global/Trace.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/services/global/Trace.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/bld.js:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/bld.js
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/BuildEnvironment.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/BuildEnvironment.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/PackageContents.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/PackageContents.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/_gen.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/_gen.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/Library.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/Library.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/Executable.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/Executable.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/Repository.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/Repository.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/Configuration.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/Configuration.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/Script.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/Script.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/Manifest.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/Manifest.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/Utils.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/Utils.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/ITarget.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/ITarget.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/ITarget2.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/ITarget2.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/ITargetFilter.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/ITargetFilter.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/package.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/xdc/bld/package.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/framework_components_3_22_01_07/framework_components.bld:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/framework_components_3_22_01_07/framework_components.bld
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/ti/targets/ITarget.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/ti/targets/ITarget.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/ti/targets/C28_large.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/ti/targets/C28_large.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/ti/targets/C28_float.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/ti/targets/C28_float.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/ti/targets/package.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/ti/targets/package.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/ti/targets/arm/IArm.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/ti/targets/arm/IArm.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/ti/targets/arm/package.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/ti/targets/arm/package.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/ti/targets/arm/elf/IArm.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/ti/targets/arm/elf/IArm.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/ti/targets/arm/elf/package.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/ti/targets/arm/elf/package.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/ti/targets/elf/ITarget.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/ti/targets/elf/ITarget.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/ti/targets/elf/TMS470.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/ti/targets/elf/TMS470.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/ti/targets/elf/package.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/ti/targets/elf/package.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/gnu/targets/ITarget.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/gnu/targets/ITarget.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/gnu/targets/Linux86.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/gnu/targets/Linux86.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/gnu/targets/Mingw.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/gnu/targets/Mingw.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/gnu/targets/MVArm9.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/gnu/targets/MVArm9.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/gnu/targets/UCArm9.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/gnu/targets/UCArm9.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/gnu/targets/package.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/gnu/targets/package.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/gnu/targets/arm/GCArmv6.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/gnu/targets/arm/GCArmv6.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/gnu/targets/arm/GCArmv7A.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/gnu/targets/arm/GCArmv7A.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/gnu/targets/arm/M3.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/gnu/targets/arm/M3.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/gnu/targets/arm/M4.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/gnu/targets/arm/M4.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/gnu/targets/arm/M4F.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/gnu/targets/arm/M4F.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/gnu/targets/arm/MVArm9.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/gnu/targets/arm/MVArm9.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/gnu/targets/arm/UCArm9.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/gnu/targets/arm/UCArm9.xs
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/gnu/targets/arm/package.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/gnu/targets/arm/package.xs
package.mak: package.bld
/swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/osal_1_22_01_09/packages/ti/sdo/tools/build/PackageBuildHelp.xs:
package.mak: /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/osal_1_22_01_09/packages/ti/sdo/tools/build/PackageBuildHelp.xs
endif

ti.targets.arm.elf.M3.rootDir ?= /proj/productization/tools/cgt470/cgt470_4_9_2/
ti.targets.arm.elf.packageBase ?= /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/ti/targets/arm/elf/
ti.targets.elf.C674.rootDir ?= /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/dsp-devkit/cgt6x_7_3_1
ti.targets.elf.packageBase ?= /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/ti/targets/elf/
gnu.targets.arm.GCArmv5T.rootDir ?= /codesourcery/arm-2009q1/
gnu.targets.arm.packageBase ?= /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/gnu/targets/arm/
.PRECIOUS: $(XDCCFGDIR)/%.oem3
.PHONY: all,em3 .dlls,em3 .executables,em3 test,em3
all,em3: .executables,em3
.executables,em3: .libraries,em3
.executables,em3: .dlls,em3
.dlls,em3: .libraries,em3
.libraries,em3: .interfaces
	@$(RM) $@
	@$(TOUCH) "$@"

.help::
	@$(ECHO) xdc test,em3
	@$(ECHO) xdc .executables,em3
	@$(ECHO) xdc .libraries,em3
	@$(ECHO) xdc .dlls,em3

.PRECIOUS: $(XDCCFGDIR)/%.oe674
.PHONY: all,e674 .dlls,e674 .executables,e674 test,e674
all,e674: .executables,e674
.executables,e674: .libraries,e674
.executables,e674: .dlls,e674
.dlls,e674: .libraries,e674
.libraries,e674: .interfaces
	@$(RM) $@
	@$(TOUCH) "$@"

.help::
	@$(ECHO) xdc test,e674
	@$(ECHO) xdc .executables,e674
	@$(ECHO) xdc .libraries,e674
	@$(ECHO) xdc .dlls,e674

.PRECIOUS: $(XDCCFGDIR)/%.ov5T
.PHONY: all,v5T .dlls,v5T .executables,v5T test,v5T
all,v5T: .executables,v5T
.executables,v5T: .libraries,v5T
.executables,v5T: .dlls,v5T
.dlls,v5T: .libraries,v5T
.libraries,v5T: .interfaces
	@$(RM) $@
	@$(TOUCH) "$@"

.help::
	@$(ECHO) xdc test,v5T
	@$(ECHO) xdc .executables,v5T
	@$(ECHO) xdc .libraries,v5T
	@$(ECHO) xdc .dlls,v5T


all: .executables 
.executables: .libraries .dlls
.libraries: .interfaces

PKGCFGS := $(wildcard package.xs) package/build.cfg
.interfaces: package/package.xdc.inc package/package.defs.h package.xdc $(PKGCFGS)

-include package/package.xdc.dep
package/%.xdc.inc package/%_ti.sdo.fc.global.c package/%.defs.h: %.xdc $(PKGCFGS)
	@$(MSG) generating interfaces for package ti.sdo.fc.global" (because $@ is older than $(firstword $?))" ...
	$(XSRUN) -f xdc/services/intern/cmd/build.xs $(MK_IDLOPTS) -m package/package.xdc.dep -i package/package.xdc.inc package.xdc

ifeq (,$(MK_NOGENDEPS))
-include package/package.cfg.dep
endif

package/package.ext.xml: package/package.cfg.xdc.inc
package/package.cfg.xdc.inc: $(XDCROOT)/packages/xdc/cfg/cfginc.js package.xdc
	@$(MSG) generating schema include file list ...
	$(CONFIG) -f $(XDCROOT)/packages/xdc/cfg/cfginc.js ti.sdo.fc.global $@

.libraries,em3 .libraries: lib/debug/fcsettings.aem3

-include lib/debug/fcsettings.aem3.mak
lib/debug/fcsettings.aem3: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/debug/fcsettings/package/package_ti.sdo.fc.global.oem3 package/lib/lib/debug/fcsettings/FCSettings.oem3 package/lib/lib/debug/fcsettings/Settings.oem3 package/lib/lib/debug/fcsettings/gt_dais.oem3  into $@ ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/ar470  rq $@   package/lib/lib/debug/fcsettings/package/package_ti.sdo.fc.global.oem3 package/lib/lib/debug/fcsettings/FCSettings.oem3 package/lib/lib/debug/fcsettings/Settings.oem3 package/lib/lib/debug/fcsettings/gt_dais.oem3 
lib/debug/fcsettings.aem3: export C_DIR=
lib/debug/fcsettings.aem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

clean,em3 clean::
	-$(RM) lib/debug/fcsettings.aem3
.libraries,em3 .libraries: lib/release/fcsettings.aem3

-include lib/release/fcsettings.aem3.mak
lib/release/fcsettings.aem3: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/release/fcsettings/package/package_ti.sdo.fc.global.oem3 package/lib/lib/release/fcsettings/FCSettings.oem3 package/lib/lib/release/fcsettings/Settings.oem3 package/lib/lib/release/fcsettings/gt_dais.oem3  into $@ ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/ar470  rq $@   package/lib/lib/release/fcsettings/package/package_ti.sdo.fc.global.oem3 package/lib/lib/release/fcsettings/FCSettings.oem3 package/lib/lib/release/fcsettings/Settings.oem3 package/lib/lib/release/fcsettings/gt_dais.oem3 
lib/release/fcsettings.aem3: export C_DIR=
lib/release/fcsettings.aem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

clean,em3 clean::
	-$(RM) lib/release/fcsettings.aem3
.libraries,e674 .libraries: lib/debug/fcsettings.ae674

-include lib/debug/fcsettings.ae674.mak
lib/debug/fcsettings.ae674: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/debug/fcsettings/package/package_ti.sdo.fc.global.oe674 package/lib/lib/debug/fcsettings/FCSettings.oe674 package/lib/lib/debug/fcsettings/Settings.oe674 package/lib/lib/debug/fcsettings/gt_dais.oe674  into $@ ...
	$(ti.targets.elf.C674.rootDir)/bin/ar6x  rq $@   package/lib/lib/debug/fcsettings/package/package_ti.sdo.fc.global.oe674 package/lib/lib/debug/fcsettings/FCSettings.oe674 package/lib/lib/debug/fcsettings/Settings.oe674 package/lib/lib/debug/fcsettings/gt_dais.oe674 
lib/debug/fcsettings.ae674: export C_DIR=
lib/debug/fcsettings.ae674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

clean,e674 clean::
	-$(RM) lib/debug/fcsettings.ae674
.libraries,e674 .libraries: lib/release/fcsettings.ae674

-include lib/release/fcsettings.ae674.mak
lib/release/fcsettings.ae674: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/release/fcsettings/package/package_ti.sdo.fc.global.oe674 package/lib/lib/release/fcsettings/FCSettings.oe674 package/lib/lib/release/fcsettings/Settings.oe674 package/lib/lib/release/fcsettings/gt_dais.oe674  into $@ ...
	$(ti.targets.elf.C674.rootDir)/bin/ar6x  rq $@   package/lib/lib/release/fcsettings/package/package_ti.sdo.fc.global.oe674 package/lib/lib/release/fcsettings/FCSettings.oe674 package/lib/lib/release/fcsettings/Settings.oe674 package/lib/lib/release/fcsettings/gt_dais.oe674 
lib/release/fcsettings.ae674: export C_DIR=
lib/release/fcsettings.ae674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

clean,e674 clean::
	-$(RM) lib/release/fcsettings.ae674
.libraries,v5T .libraries: lib/debug/fcsettings.av5T

-include lib/debug/fcsettings.av5T.mak
lib/debug/fcsettings.av5T: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/debug/fcsettings/package/package_ti.sdo.fc.global.ov5T package/lib/lib/debug/fcsettings/FCSettings.ov5T package/lib/lib/debug/fcsettings/Settings.ov5T package/lib/lib/debug/fcsettings/gt_dais.ov5T  into $@ ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/arm-none-linux-gnueabi/bin/ar  cr $@   package/lib/lib/debug/fcsettings/package/package_ti.sdo.fc.global.ov5T package/lib/lib/debug/fcsettings/FCSettings.ov5T package/lib/lib/debug/fcsettings/Settings.ov5T package/lib/lib/debug/fcsettings/gt_dais.ov5T 
lib/debug/fcsettings.av5T: export LD_LIBRARY_PATH=

clean,v5T clean::
	-$(RM) lib/debug/fcsettings.av5T
.libraries,v5T .libraries: lib/release/fcsettings.av5T

-include lib/release/fcsettings.av5T.mak
lib/release/fcsettings.av5T: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/release/fcsettings/package/package_ti.sdo.fc.global.ov5T package/lib/lib/release/fcsettings/FCSettings.ov5T package/lib/lib/release/fcsettings/Settings.ov5T package/lib/lib/release/fcsettings/gt_dais.ov5T  into $@ ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/arm-none-linux-gnueabi/bin/ar  cr $@   package/lib/lib/release/fcsettings/package/package_ti.sdo.fc.global.ov5T package/lib/lib/release/fcsettings/FCSettings.ov5T package/lib/lib/release/fcsettings/Settings.ov5T package/lib/lib/release/fcsettings/gt_dais.ov5T 
lib/release/fcsettings.av5T: export LD_LIBRARY_PATH=

clean,v5T clean::
	-$(RM) lib/release/fcsettings.av5T
test:;
%,copy:
	@$(if $<,,$(MSG) don\'t know how to build $*; exit 1)
	@$(MSG) cp $< $@
	$(RM) $@
	$(CP) $< $@
.PHONY: package_ti.sdo.fc.global.oem3,copy
package_ti.sdo.fc.global.oem3,copy : package_ti.sdo.fc.global.oem3,0,copy package_ti.sdo.fc.global.oem3,1,copy 
	@

package_ti.sdo.fc.global.oem3,0,copy : package/lib/lib/debug/fcsettings/package/package_ti.sdo.fc.global.oem3
package_ti.sdo.fc.global.oem3,1,copy : package/lib/lib/release/fcsettings/package/package_ti.sdo.fc.global.oem3
.PHONY: package_ti.sdo.fc.global.sem3,copy
package_ti.sdo.fc.global.sem3,copy : package_ti.sdo.fc.global.sem3,0,copy package_ti.sdo.fc.global.sem3,1,copy 
	@

package_ti.sdo.fc.global.sem3,0,copy : package/lib/lib/debug/fcsettings/package/package_ti.sdo.fc.global.sem3
package_ti.sdo.fc.global.sem3,1,copy : package/lib/lib/release/fcsettings/package/package_ti.sdo.fc.global.sem3
.PHONY: FCSettings.oem3,copy
FCSettings.oem3,copy : FCSettings.oem3,0,copy FCSettings.oem3,1,copy 
	@

FCSettings.oem3,0,copy : package/lib/lib/debug/fcsettings/FCSettings.oem3
FCSettings.oem3,1,copy : package/lib/lib/release/fcsettings/FCSettings.oem3
.PHONY: FCSettings.sem3,copy
FCSettings.sem3,copy : FCSettings.sem3,0,copy FCSettings.sem3,1,copy 
	@

FCSettings.sem3,0,copy : package/lib/lib/debug/fcsettings/FCSettings.sem3
FCSettings.sem3,1,copy : package/lib/lib/release/fcsettings/FCSettings.sem3
.PHONY: Settings.oem3,copy
Settings.oem3,copy : Settings.oem3,0,copy Settings.oem3,1,copy 
	@

Settings.oem3,0,copy : package/lib/lib/debug/fcsettings/Settings.oem3
Settings.oem3,1,copy : package/lib/lib/release/fcsettings/Settings.oem3
.PHONY: Settings.sem3,copy
Settings.sem3,copy : Settings.sem3,0,copy Settings.sem3,1,copy 
	@

Settings.sem3,0,copy : package/lib/lib/debug/fcsettings/Settings.sem3
Settings.sem3,1,copy : package/lib/lib/release/fcsettings/Settings.sem3
.PHONY: gt_dais.oem3,copy
gt_dais.oem3,copy : gt_dais.oem3,0,copy gt_dais.oem3,1,copy 
	@

gt_dais.oem3,0,copy : package/lib/lib/debug/fcsettings/gt_dais.oem3
gt_dais.oem3,1,copy : package/lib/lib/release/fcsettings/gt_dais.oem3
.PHONY: gt_dais.sem3,copy
gt_dais.sem3,copy : gt_dais.sem3,0,copy gt_dais.sem3,1,copy 
	@

gt_dais.sem3,0,copy : package/lib/lib/debug/fcsettings/gt_dais.sem3
gt_dais.sem3,1,copy : package/lib/lib/release/fcsettings/gt_dais.sem3
.PHONY: package_ti.sdo.fc.global.oe674,copy
package_ti.sdo.fc.global.oe674,copy : package_ti.sdo.fc.global.oe674,0,copy package_ti.sdo.fc.global.oe674,1,copy 
	@

package_ti.sdo.fc.global.oe674,0,copy : package/lib/lib/debug/fcsettings/package/package_ti.sdo.fc.global.oe674
package_ti.sdo.fc.global.oe674,1,copy : package/lib/lib/release/fcsettings/package/package_ti.sdo.fc.global.oe674
.PHONY: package_ti.sdo.fc.global.se674,copy
package_ti.sdo.fc.global.se674,copy : package_ti.sdo.fc.global.se674,0,copy package_ti.sdo.fc.global.se674,1,copy 
	@

package_ti.sdo.fc.global.se674,0,copy : package/lib/lib/debug/fcsettings/package/package_ti.sdo.fc.global.se674
package_ti.sdo.fc.global.se674,1,copy : package/lib/lib/release/fcsettings/package/package_ti.sdo.fc.global.se674
.PHONY: FCSettings.oe674,copy
FCSettings.oe674,copy : FCSettings.oe674,0,copy FCSettings.oe674,1,copy 
	@

FCSettings.oe674,0,copy : package/lib/lib/debug/fcsettings/FCSettings.oe674
FCSettings.oe674,1,copy : package/lib/lib/release/fcsettings/FCSettings.oe674
.PHONY: FCSettings.se674,copy
FCSettings.se674,copy : FCSettings.se674,0,copy FCSettings.se674,1,copy 
	@

FCSettings.se674,0,copy : package/lib/lib/debug/fcsettings/FCSettings.se674
FCSettings.se674,1,copy : package/lib/lib/release/fcsettings/FCSettings.se674
.PHONY: Settings.oe674,copy
Settings.oe674,copy : Settings.oe674,0,copy Settings.oe674,1,copy 
	@

Settings.oe674,0,copy : package/lib/lib/debug/fcsettings/Settings.oe674
Settings.oe674,1,copy : package/lib/lib/release/fcsettings/Settings.oe674
.PHONY: Settings.se674,copy
Settings.se674,copy : Settings.se674,0,copy Settings.se674,1,copy 
	@

Settings.se674,0,copy : package/lib/lib/debug/fcsettings/Settings.se674
Settings.se674,1,copy : package/lib/lib/release/fcsettings/Settings.se674
.PHONY: gt_dais.oe674,copy
gt_dais.oe674,copy : gt_dais.oe674,0,copy gt_dais.oe674,1,copy 
	@

gt_dais.oe674,0,copy : package/lib/lib/debug/fcsettings/gt_dais.oe674
gt_dais.oe674,1,copy : package/lib/lib/release/fcsettings/gt_dais.oe674
.PHONY: gt_dais.se674,copy
gt_dais.se674,copy : gt_dais.se674,0,copy gt_dais.se674,1,copy 
	@

gt_dais.se674,0,copy : package/lib/lib/debug/fcsettings/gt_dais.se674
gt_dais.se674,1,copy : package/lib/lib/release/fcsettings/gt_dais.se674
.PHONY: package_ti.sdo.fc.global.ov5T,copy
package_ti.sdo.fc.global.ov5T,copy : package_ti.sdo.fc.global.ov5T,0,copy package_ti.sdo.fc.global.ov5T,1,copy 
	@

package_ti.sdo.fc.global.ov5T,0,copy : package/lib/lib/debug/fcsettings/package/package_ti.sdo.fc.global.ov5T
package_ti.sdo.fc.global.ov5T,1,copy : package/lib/lib/release/fcsettings/package/package_ti.sdo.fc.global.ov5T
.PHONY: package_ti.sdo.fc.global.sv5T,copy
package_ti.sdo.fc.global.sv5T,copy : package_ti.sdo.fc.global.sv5T,0,copy package_ti.sdo.fc.global.sv5T,1,copy 
	@

package_ti.sdo.fc.global.sv5T,0,copy : package/lib/lib/debug/fcsettings/package/package_ti.sdo.fc.global.sv5T
package_ti.sdo.fc.global.sv5T,1,copy : package/lib/lib/release/fcsettings/package/package_ti.sdo.fc.global.sv5T
.PHONY: FCSettings.ov5T,copy
FCSettings.ov5T,copy : FCSettings.ov5T,0,copy FCSettings.ov5T,1,copy 
	@

FCSettings.ov5T,0,copy : package/lib/lib/debug/fcsettings/FCSettings.ov5T
FCSettings.ov5T,1,copy : package/lib/lib/release/fcsettings/FCSettings.ov5T
.PHONY: FCSettings.sv5T,copy
FCSettings.sv5T,copy : FCSettings.sv5T,0,copy FCSettings.sv5T,1,copy 
	@

FCSettings.sv5T,0,copy : package/lib/lib/debug/fcsettings/FCSettings.sv5T
FCSettings.sv5T,1,copy : package/lib/lib/release/fcsettings/FCSettings.sv5T
.PHONY: Settings.ov5T,copy
Settings.ov5T,copy : Settings.ov5T,0,copy Settings.ov5T,1,copy 
	@

Settings.ov5T,0,copy : package/lib/lib/debug/fcsettings/Settings.ov5T
Settings.ov5T,1,copy : package/lib/lib/release/fcsettings/Settings.ov5T
.PHONY: Settings.sv5T,copy
Settings.sv5T,copy : Settings.sv5T,0,copy Settings.sv5T,1,copy 
	@

Settings.sv5T,0,copy : package/lib/lib/debug/fcsettings/Settings.sv5T
Settings.sv5T,1,copy : package/lib/lib/release/fcsettings/Settings.sv5T
.PHONY: gt_dais.ov5T,copy
gt_dais.ov5T,copy : gt_dais.ov5T,0,copy gt_dais.ov5T,1,copy 
	@

gt_dais.ov5T,0,copy : package/lib/lib/debug/fcsettings/gt_dais.ov5T
gt_dais.ov5T,1,copy : package/lib/lib/release/fcsettings/gt_dais.ov5T
.PHONY: gt_dais.sv5T,copy
gt_dais.sv5T,copy : gt_dais.sv5T,0,copy gt_dais.sv5T,1,copy 
	@

gt_dais.sv5T,0,copy : package/lib/lib/debug/fcsettings/gt_dais.sv5T
gt_dais.sv5T,1,copy : package/lib/lib/release/fcsettings/gt_dais.sv5T

$(XDCCFGDIR)%.c $(XDCCFGDIR)%.h $(XDCCFGDIR)%.xdl: $(XDCCFGDIR)%.cfg .interfaces $(XDCROOT)/packages/xdc/cfg/Main.xs
	@$(MSG) "configuring $(_PROG_NAME) from $< ..."
	$(CONFIG) $(_PROG_XSOPTS) xdc.cfg $(_PROG_NAME) $(XDCCFGDIR)$*.cfg $(XDCCFGDIR)$*

.PHONY: release,ti_sdo_fc_global
ti_sdo_fc_global.tar: package/package.bld.xml
ti_sdo_fc_global.tar: package/package.ext.xml
ti_sdo_fc_global.tar: package/package.rel.dot
ti_sdo_fc_global.tar: package/build.cfg
ti_sdo_fc_global.tar: package/package.xdc.inc
ti_sdo_fc_global.tar: package.bld
ti_sdo_fc_global.tar: FCSettings.h
ti_sdo_fc_global.tar: Settings.h
ti_sdo_fc_global.tar: gt_dais.h
ti_sdo_fc_global.tar: simple_GCArmv5T.mak
ti_sdo_fc_global.tar: package/package.cfg.xdc.inc
ti_sdo_fc_global.tar: lib/debug/fcsettings.aem3
ti_sdo_fc_global.tar: package/package_ti.sdo.fc.global.c
ti_sdo_fc_global.tar: FCSettings.c
ti_sdo_fc_global.tar: Settings.c
ti_sdo_fc_global.tar: gt_dais.c
ti_sdo_fc_global.tar: lib/release/fcsettings.aem3
ti_sdo_fc_global.tar: lib/debug/fcsettings.ae674
ti_sdo_fc_global.tar: lib/release/fcsettings.ae674
ti_sdo_fc_global.tar: lib/debug/fcsettings.av5T
ti_sdo_fc_global.tar: lib/release/fcsettings.av5T
ifeq (,$(MK_NOGENDEPS))
-include package/rel/ti_sdo_fc_global.tar.dep
endif
package/rel/ti_sdo_fc_global/ti/sdo/fc/global/package/package.rel.xml:

ti_sdo_fc_global.tar: package/rel/ti_sdo_fc_global.xdc.inc package/rel/ti_sdo_fc_global/ti/sdo/fc/global/package/package.rel.xml
	@$(MSG) making release file $@ "(because of $(firstword $?))" ...
	-$(RM) $@
	$(call MKRELTAR,package/rel/ti_sdo_fc_global.xdc.inc,package/rel/ti_sdo_fc_global.tar.dep)


release release,ti_sdo_fc_global: all ti_sdo_fc_global.tar
clean:: .clean
	-$(RM) ti_sdo_fc_global.tar
	-$(RM) package/rel/ti_sdo_fc_global.xdc.inc
	-$(RM) package/rel/ti_sdo_fc_global.tar.dep

clean:: .clean
	-$(RM) .libraries .libraries,*
clean:: 
	-$(RM) .dlls .dlls,*
#
# The following clean rule removes user specified
# generated files or directories.
#
	-$(RMDIR) lib/

ifneq (clean,$(MAKECMDGOALS))
ifeq (,$(wildcard lib))
    $(shell $(MKDIR) lib)
endif
ifeq (,$(wildcard lib/debug))
    $(shell $(MKDIR) lib/debug)
endif
ifeq (,$(wildcard lib/release))
    $(shell $(MKDIR) lib/release)
endif
ifeq (,$(wildcard package))
    $(shell $(MKDIR) package)
endif
ifeq (,$(wildcard package/cfg))
    $(shell $(MKDIR) package/cfg)
endif
ifeq (,$(wildcard package/lib))
    $(shell $(MKDIR) package/lib)
endif
ifeq (,$(wildcard package/rel))
    $(shell $(MKDIR) package/rel)
endif
ifeq (,$(wildcard package/internal))
    $(shell $(MKDIR) package/internal)
endif
ifeq (,$(wildcard package/external))
    $(shell $(MKDIR) package/external)
endif
ifeq (,$(wildcard package/lib/lib))
    $(shell $(MKDIR) package/lib/lib)
endif
ifeq (,$(wildcard package/lib/lib/debug))
    $(shell $(MKDIR) package/lib/lib/debug)
endif
ifeq (,$(wildcard package/lib/lib/debug/fcsettings))
    $(shell $(MKDIR) package/lib/lib/debug/fcsettings)
endif
ifeq (,$(wildcard package/lib/lib/debug/fcsettings/package))
    $(shell $(MKDIR) package/lib/lib/debug/fcsettings/package)
endif
ifeq (,$(wildcard package/lib/lib/release))
    $(shell $(MKDIR) package/lib/lib/release)
endif
ifeq (,$(wildcard package/lib/lib/release/fcsettings))
    $(shell $(MKDIR) package/lib/lib/release/fcsettings)
endif
ifeq (,$(wildcard package/lib/lib/release/fcsettings/package))
    $(shell $(MKDIR) package/lib/lib/release/fcsettings/package)
endif
endif
clean::
	-$(RMDIR) package


clean:: 
	-$(RM) package/ti.sdo.fc.global.pjt
