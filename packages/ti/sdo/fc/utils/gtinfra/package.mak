#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#

unexport MAKEFILE_LIST
MK_NOGENDEPS := $(filter clean,$(MAKECMDGOALS))
override PKGDIR = ti/sdo/fc/utils/gtinfra
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
package/%.xdc.inc package/%_ti.sdo.fc.utils.gtinfra.c package/%.defs.h: %.xdc $(PKGCFGS)
	@$(MSG) generating interfaces for package ti.sdo.fc.utils.gtinfra" (because $@ is older than $(firstword $?))" ...
	$(XSRUN) -f xdc/services/intern/cmd/build.xs $(MK_IDLOPTS) -m package/package.xdc.dep -i package/package.xdc.inc package.xdc

ifeq (,$(MK_NOGENDEPS))
-include package/package.cfg.dep
endif

package/package.ext.xml: package/package.cfg.xdc.inc
package/package.cfg.xdc.inc: $(XDCROOT)/packages/xdc/cfg/cfginc.js package.xdc
	@$(MSG) generating schema include file list ...
	$(CONFIG) -f $(XDCROOT)/packages/xdc/cfg/cfginc.js ti.sdo.fc.utils.gtinfra $@

.libraries,em3 .libraries: lib/debug/gt_bios.aem3

-include lib/debug/gt_bios.aem3.mak
lib/debug/gt_bios.aem3: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.oem3 package/lib/lib/debug/gt_bios/GT_config_BIOS.oem3 package/lib/lib/debug/gt_bios/Trace.oem3  into $@ ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/ar470  rq $@   package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.oem3 package/lib/lib/debug/gt_bios/GT_config_BIOS.oem3 package/lib/lib/debug/gt_bios/Trace.oem3 
lib/debug/gt_bios.aem3: export C_DIR=
lib/debug/gt_bios.aem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

clean,em3 clean::
	-$(RM) lib/debug/gt_bios.aem3
.libraries,em3 .libraries: lib/release/gt_bios.aem3

-include lib/release/gt_bios.aem3.mak
lib/release/gt_bios.aem3: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/release/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.oem3 package/lib/lib/release/gt_bios/GT_config_BIOS.oem3 package/lib/lib/release/gt_bios/Trace.oem3  into $@ ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/ar470  rq $@   package/lib/lib/release/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.oem3 package/lib/lib/release/gt_bios/GT_config_BIOS.oem3 package/lib/lib/release/gt_bios/Trace.oem3 
lib/release/gt_bios.aem3: export C_DIR=
lib/release/gt_bios.aem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

clean,em3 clean::
	-$(RM) lib/release/gt_bios.aem3
.libraries,e674 .libraries: lib/debug/gt_bios.ae674

-include lib/debug/gt_bios.ae674.mak
lib/debug/gt_bios.ae674: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.oe674 package/lib/lib/debug/gt_bios/GT_config_BIOS.oe674 package/lib/lib/debug/gt_bios/Trace.oe674  into $@ ...
	$(ti.targets.elf.C674.rootDir)/bin/ar6x  rq $@   package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.oe674 package/lib/lib/debug/gt_bios/GT_config_BIOS.oe674 package/lib/lib/debug/gt_bios/Trace.oe674 
lib/debug/gt_bios.ae674: export C_DIR=
lib/debug/gt_bios.ae674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

clean,e674 clean::
	-$(RM) lib/debug/gt_bios.ae674
.libraries,e674 .libraries: lib/release/gt_bios.ae674

-include lib/release/gt_bios.ae674.mak
lib/release/gt_bios.ae674: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/release/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.oe674 package/lib/lib/release/gt_bios/GT_config_BIOS.oe674 package/lib/lib/release/gt_bios/Trace.oe674  into $@ ...
	$(ti.targets.elf.C674.rootDir)/bin/ar6x  rq $@   package/lib/lib/release/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.oe674 package/lib/lib/release/gt_bios/GT_config_BIOS.oe674 package/lib/lib/release/gt_bios/Trace.oe674 
lib/release/gt_bios.ae674: export C_DIR=
lib/release/gt_bios.ae674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

clean,e674 clean::
	-$(RM) lib/release/gt_bios.ae674
.libraries,em3 .libraries: lib/debug/gt_noOS.aem3

-include lib/debug/gt_noOS.aem3.mak
lib/debug/gt_noOS.aem3: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/debug/gt_noOS/package/package_ti.sdo.fc.utils.gtinfra.oem3 package/lib/lib/debug/gt_noOS/GT_config_noOS.oem3 package/lib/lib/debug/gt_noOS/Trace.oem3  into $@ ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/ar470  rq $@   package/lib/lib/debug/gt_noOS/package/package_ti.sdo.fc.utils.gtinfra.oem3 package/lib/lib/debug/gt_noOS/GT_config_noOS.oem3 package/lib/lib/debug/gt_noOS/Trace.oem3 
lib/debug/gt_noOS.aem3: export C_DIR=
lib/debug/gt_noOS.aem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

clean,em3 clean::
	-$(RM) lib/debug/gt_noOS.aem3
.libraries,em3 .libraries: lib/release/gt_noOS.aem3

-include lib/release/gt_noOS.aem3.mak
lib/release/gt_noOS.aem3: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/release/gt_noOS/package/package_ti.sdo.fc.utils.gtinfra.oem3 package/lib/lib/release/gt_noOS/GT_config_noOS.oem3 package/lib/lib/release/gt_noOS/Trace.oem3  into $@ ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/ar470  rq $@   package/lib/lib/release/gt_noOS/package/package_ti.sdo.fc.utils.gtinfra.oem3 package/lib/lib/release/gt_noOS/GT_config_noOS.oem3 package/lib/lib/release/gt_noOS/Trace.oem3 
lib/release/gt_noOS.aem3: export C_DIR=
lib/release/gt_noOS.aem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

clean,em3 clean::
	-$(RM) lib/release/gt_noOS.aem3
.libraries,e674 .libraries: lib/debug/gt_noOS.ae674

-include lib/debug/gt_noOS.ae674.mak
lib/debug/gt_noOS.ae674: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/debug/gt_noOS/package/package_ti.sdo.fc.utils.gtinfra.oe674 package/lib/lib/debug/gt_noOS/GT_config_noOS.oe674 package/lib/lib/debug/gt_noOS/Trace.oe674  into $@ ...
	$(ti.targets.elf.C674.rootDir)/bin/ar6x  rq $@   package/lib/lib/debug/gt_noOS/package/package_ti.sdo.fc.utils.gtinfra.oe674 package/lib/lib/debug/gt_noOS/GT_config_noOS.oe674 package/lib/lib/debug/gt_noOS/Trace.oe674 
lib/debug/gt_noOS.ae674: export C_DIR=
lib/debug/gt_noOS.ae674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

clean,e674 clean::
	-$(RM) lib/debug/gt_noOS.ae674
.libraries,e674 .libraries: lib/release/gt_noOS.ae674

-include lib/release/gt_noOS.ae674.mak
lib/release/gt_noOS.ae674: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/release/gt_noOS/package/package_ti.sdo.fc.utils.gtinfra.oe674 package/lib/lib/release/gt_noOS/GT_config_noOS.oe674 package/lib/lib/release/gt_noOS/Trace.oe674  into $@ ...
	$(ti.targets.elf.C674.rootDir)/bin/ar6x  rq $@   package/lib/lib/release/gt_noOS/package/package_ti.sdo.fc.utils.gtinfra.oe674 package/lib/lib/release/gt_noOS/GT_config_noOS.oe674 package/lib/lib/release/gt_noOS/Trace.oe674 
lib/release/gt_noOS.ae674: export C_DIR=
lib/release/gt_noOS.ae674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

clean,e674 clean::
	-$(RM) lib/release/gt_noOS.ae674
.libraries,v5T .libraries: lib/debug/gt_noOS.av5T

-include lib/debug/gt_noOS.av5T.mak
lib/debug/gt_noOS.av5T: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/debug/gt_noOS/package/package_ti.sdo.fc.utils.gtinfra.ov5T package/lib/lib/debug/gt_noOS/GT_config_noOS.ov5T package/lib/lib/debug/gt_noOS/Trace.ov5T  into $@ ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/arm-none-linux-gnueabi/bin/ar  cr $@   package/lib/lib/debug/gt_noOS/package/package_ti.sdo.fc.utils.gtinfra.ov5T package/lib/lib/debug/gt_noOS/GT_config_noOS.ov5T package/lib/lib/debug/gt_noOS/Trace.ov5T 
lib/debug/gt_noOS.av5T: export LD_LIBRARY_PATH=

clean,v5T clean::
	-$(RM) lib/debug/gt_noOS.av5T
.libraries,v5T .libraries: lib/release/gt_noOS.av5T

-include lib/release/gt_noOS.av5T.mak
lib/release/gt_noOS.av5T: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/release/gt_noOS/package/package_ti.sdo.fc.utils.gtinfra.ov5T package/lib/lib/release/gt_noOS/GT_config_noOS.ov5T package/lib/lib/release/gt_noOS/Trace.ov5T  into $@ ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/arm-none-linux-gnueabi/bin/ar  cr $@   package/lib/lib/release/gt_noOS/package/package_ti.sdo.fc.utils.gtinfra.ov5T package/lib/lib/release/gt_noOS/GT_config_noOS.ov5T package/lib/lib/release/gt_noOS/Trace.ov5T 
lib/release/gt_noOS.av5T: export LD_LIBRARY_PATH=

clean,v5T clean::
	-$(RM) lib/release/gt_noOS.av5T
test:;
%,copy:
	@$(if $<,,$(MSG) don\'t know how to build $*; exit 1)
	@$(MSG) cp $< $@
	$(RM) $@
	$(CP) $< $@
.PHONY: package_ti.sdo.fc.utils.gtinfra.oem3,copy
package_ti.sdo.fc.utils.gtinfra.oem3,copy : package_ti.sdo.fc.utils.gtinfra.oem3,0,copy package_ti.sdo.fc.utils.gtinfra.oem3,1,copy package_ti.sdo.fc.utils.gtinfra.oem3,2,copy package_ti.sdo.fc.utils.gtinfra.oem3,3,copy 
	@

package_ti.sdo.fc.utils.gtinfra.oem3,0,copy : package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.oem3
package_ti.sdo.fc.utils.gtinfra.oem3,1,copy : package/lib/lib/debug/gt_noOS/package/package_ti.sdo.fc.utils.gtinfra.oem3
package_ti.sdo.fc.utils.gtinfra.oem3,2,copy : package/lib/lib/release/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.oem3
package_ti.sdo.fc.utils.gtinfra.oem3,3,copy : package/lib/lib/release/gt_noOS/package/package_ti.sdo.fc.utils.gtinfra.oem3
.PHONY: package_ti.sdo.fc.utils.gtinfra.sem3,copy
package_ti.sdo.fc.utils.gtinfra.sem3,copy : package_ti.sdo.fc.utils.gtinfra.sem3,0,copy package_ti.sdo.fc.utils.gtinfra.sem3,1,copy package_ti.sdo.fc.utils.gtinfra.sem3,2,copy package_ti.sdo.fc.utils.gtinfra.sem3,3,copy 
	@

package_ti.sdo.fc.utils.gtinfra.sem3,0,copy : package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.sem3
package_ti.sdo.fc.utils.gtinfra.sem3,1,copy : package/lib/lib/debug/gt_noOS/package/package_ti.sdo.fc.utils.gtinfra.sem3
package_ti.sdo.fc.utils.gtinfra.sem3,2,copy : package/lib/lib/release/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.sem3
package_ti.sdo.fc.utils.gtinfra.sem3,3,copy : package/lib/lib/release/gt_noOS/package/package_ti.sdo.fc.utils.gtinfra.sem3
.PHONY: GT_config_BIOS.oem3,copy
GT_config_BIOS.oem3,copy : GT_config_BIOS.oem3,0,copy GT_config_BIOS.oem3,1,copy 
	@

GT_config_BIOS.oem3,0,copy : package/lib/lib/debug/gt_bios/GT_config_BIOS.oem3
GT_config_BIOS.oem3,1,copy : package/lib/lib/release/gt_bios/GT_config_BIOS.oem3
.PHONY: GT_config_BIOS.sem3,copy
GT_config_BIOS.sem3,copy : GT_config_BIOS.sem3,0,copy GT_config_BIOS.sem3,1,copy 
	@

GT_config_BIOS.sem3,0,copy : package/lib/lib/debug/gt_bios/GT_config_BIOS.sem3
GT_config_BIOS.sem3,1,copy : package/lib/lib/release/gt_bios/GT_config_BIOS.sem3
.PHONY: Trace.oem3,copy
Trace.oem3,copy : Trace.oem3,0,copy Trace.oem3,1,copy Trace.oem3,2,copy Trace.oem3,3,copy 
	@

Trace.oem3,0,copy : package/lib/lib/debug/gt_bios/Trace.oem3
Trace.oem3,1,copy : package/lib/lib/debug/gt_noOS/Trace.oem3
Trace.oem3,2,copy : package/lib/lib/release/gt_bios/Trace.oem3
Trace.oem3,3,copy : package/lib/lib/release/gt_noOS/Trace.oem3
.PHONY: Trace.sem3,copy
Trace.sem3,copy : Trace.sem3,0,copy Trace.sem3,1,copy Trace.sem3,2,copy Trace.sem3,3,copy 
	@

Trace.sem3,0,copy : package/lib/lib/debug/gt_bios/Trace.sem3
Trace.sem3,1,copy : package/lib/lib/debug/gt_noOS/Trace.sem3
Trace.sem3,2,copy : package/lib/lib/release/gt_bios/Trace.sem3
Trace.sem3,3,copy : package/lib/lib/release/gt_noOS/Trace.sem3
.PHONY: package_ti.sdo.fc.utils.gtinfra.oe674,copy
package_ti.sdo.fc.utils.gtinfra.oe674,copy : package_ti.sdo.fc.utils.gtinfra.oe674,0,copy package_ti.sdo.fc.utils.gtinfra.oe674,1,copy package_ti.sdo.fc.utils.gtinfra.oe674,2,copy package_ti.sdo.fc.utils.gtinfra.oe674,3,copy 
	@

package_ti.sdo.fc.utils.gtinfra.oe674,0,copy : package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.oe674
package_ti.sdo.fc.utils.gtinfra.oe674,1,copy : package/lib/lib/debug/gt_noOS/package/package_ti.sdo.fc.utils.gtinfra.oe674
package_ti.sdo.fc.utils.gtinfra.oe674,2,copy : package/lib/lib/release/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.oe674
package_ti.sdo.fc.utils.gtinfra.oe674,3,copy : package/lib/lib/release/gt_noOS/package/package_ti.sdo.fc.utils.gtinfra.oe674
.PHONY: package_ti.sdo.fc.utils.gtinfra.se674,copy
package_ti.sdo.fc.utils.gtinfra.se674,copy : package_ti.sdo.fc.utils.gtinfra.se674,0,copy package_ti.sdo.fc.utils.gtinfra.se674,1,copy package_ti.sdo.fc.utils.gtinfra.se674,2,copy package_ti.sdo.fc.utils.gtinfra.se674,3,copy 
	@

package_ti.sdo.fc.utils.gtinfra.se674,0,copy : package/lib/lib/debug/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.se674
package_ti.sdo.fc.utils.gtinfra.se674,1,copy : package/lib/lib/debug/gt_noOS/package/package_ti.sdo.fc.utils.gtinfra.se674
package_ti.sdo.fc.utils.gtinfra.se674,2,copy : package/lib/lib/release/gt_bios/package/package_ti.sdo.fc.utils.gtinfra.se674
package_ti.sdo.fc.utils.gtinfra.se674,3,copy : package/lib/lib/release/gt_noOS/package/package_ti.sdo.fc.utils.gtinfra.se674
.PHONY: GT_config_BIOS.oe674,copy
GT_config_BIOS.oe674,copy : GT_config_BIOS.oe674,0,copy GT_config_BIOS.oe674,1,copy 
	@

GT_config_BIOS.oe674,0,copy : package/lib/lib/debug/gt_bios/GT_config_BIOS.oe674
GT_config_BIOS.oe674,1,copy : package/lib/lib/release/gt_bios/GT_config_BIOS.oe674
.PHONY: GT_config_BIOS.se674,copy
GT_config_BIOS.se674,copy : GT_config_BIOS.se674,0,copy GT_config_BIOS.se674,1,copy 
	@

GT_config_BIOS.se674,0,copy : package/lib/lib/debug/gt_bios/GT_config_BIOS.se674
GT_config_BIOS.se674,1,copy : package/lib/lib/release/gt_bios/GT_config_BIOS.se674
.PHONY: Trace.oe674,copy
Trace.oe674,copy : Trace.oe674,0,copy Trace.oe674,1,copy Trace.oe674,2,copy Trace.oe674,3,copy 
	@

Trace.oe674,0,copy : package/lib/lib/debug/gt_bios/Trace.oe674
Trace.oe674,1,copy : package/lib/lib/debug/gt_noOS/Trace.oe674
Trace.oe674,2,copy : package/lib/lib/release/gt_bios/Trace.oe674
Trace.oe674,3,copy : package/lib/lib/release/gt_noOS/Trace.oe674
.PHONY: Trace.se674,copy
Trace.se674,copy : Trace.se674,0,copy Trace.se674,1,copy Trace.se674,2,copy Trace.se674,3,copy 
	@

Trace.se674,0,copy : package/lib/lib/debug/gt_bios/Trace.se674
Trace.se674,1,copy : package/lib/lib/debug/gt_noOS/Trace.se674
Trace.se674,2,copy : package/lib/lib/release/gt_bios/Trace.se674
Trace.se674,3,copy : package/lib/lib/release/gt_noOS/Trace.se674
.PHONY: GT_config_noOS.oem3,copy
GT_config_noOS.oem3,copy : GT_config_noOS.oem3,0,copy GT_config_noOS.oem3,1,copy 
	@

GT_config_noOS.oem3,0,copy : package/lib/lib/debug/gt_noOS/GT_config_noOS.oem3
GT_config_noOS.oem3,1,copy : package/lib/lib/release/gt_noOS/GT_config_noOS.oem3
.PHONY: GT_config_noOS.sem3,copy
GT_config_noOS.sem3,copy : GT_config_noOS.sem3,0,copy GT_config_noOS.sem3,1,copy 
	@

GT_config_noOS.sem3,0,copy : package/lib/lib/debug/gt_noOS/GT_config_noOS.sem3
GT_config_noOS.sem3,1,copy : package/lib/lib/release/gt_noOS/GT_config_noOS.sem3
.PHONY: GT_config_noOS.oe674,copy
GT_config_noOS.oe674,copy : GT_config_noOS.oe674,0,copy GT_config_noOS.oe674,1,copy 
	@

GT_config_noOS.oe674,0,copy : package/lib/lib/debug/gt_noOS/GT_config_noOS.oe674
GT_config_noOS.oe674,1,copy : package/lib/lib/release/gt_noOS/GT_config_noOS.oe674
.PHONY: GT_config_noOS.se674,copy
GT_config_noOS.se674,copy : GT_config_noOS.se674,0,copy GT_config_noOS.se674,1,copy 
	@

GT_config_noOS.se674,0,copy : package/lib/lib/debug/gt_noOS/GT_config_noOS.se674
GT_config_noOS.se674,1,copy : package/lib/lib/release/gt_noOS/GT_config_noOS.se674
.PHONY: package_ti.sdo.fc.utils.gtinfra.ov5T,copy
package_ti.sdo.fc.utils.gtinfra.ov5T,copy : package_ti.sdo.fc.utils.gtinfra.ov5T,0,copy package_ti.sdo.fc.utils.gtinfra.ov5T,1,copy 
	@

package_ti.sdo.fc.utils.gtinfra.ov5T,0,copy : package/lib/lib/debug/gt_noOS/package/package_ti.sdo.fc.utils.gtinfra.ov5T
package_ti.sdo.fc.utils.gtinfra.ov5T,1,copy : package/lib/lib/release/gt_noOS/package/package_ti.sdo.fc.utils.gtinfra.ov5T
.PHONY: package_ti.sdo.fc.utils.gtinfra.sv5T,copy
package_ti.sdo.fc.utils.gtinfra.sv5T,copy : package_ti.sdo.fc.utils.gtinfra.sv5T,0,copy package_ti.sdo.fc.utils.gtinfra.sv5T,1,copy 
	@

package_ti.sdo.fc.utils.gtinfra.sv5T,0,copy : package/lib/lib/debug/gt_noOS/package/package_ti.sdo.fc.utils.gtinfra.sv5T
package_ti.sdo.fc.utils.gtinfra.sv5T,1,copy : package/lib/lib/release/gt_noOS/package/package_ti.sdo.fc.utils.gtinfra.sv5T
.PHONY: GT_config_noOS.ov5T,copy
GT_config_noOS.ov5T,copy : GT_config_noOS.ov5T,0,copy GT_config_noOS.ov5T,1,copy 
	@

GT_config_noOS.ov5T,0,copy : package/lib/lib/debug/gt_noOS/GT_config_noOS.ov5T
GT_config_noOS.ov5T,1,copy : package/lib/lib/release/gt_noOS/GT_config_noOS.ov5T
.PHONY: GT_config_noOS.sv5T,copy
GT_config_noOS.sv5T,copy : GT_config_noOS.sv5T,0,copy GT_config_noOS.sv5T,1,copy 
	@

GT_config_noOS.sv5T,0,copy : package/lib/lib/debug/gt_noOS/GT_config_noOS.sv5T
GT_config_noOS.sv5T,1,copy : package/lib/lib/release/gt_noOS/GT_config_noOS.sv5T
.PHONY: Trace.ov5T,copy
Trace.ov5T,copy : Trace.ov5T,0,copy Trace.ov5T,1,copy 
	@

Trace.ov5T,0,copy : package/lib/lib/debug/gt_noOS/Trace.ov5T
Trace.ov5T,1,copy : package/lib/lib/release/gt_noOS/Trace.ov5T
.PHONY: Trace.sv5T,copy
Trace.sv5T,copy : Trace.sv5T,0,copy Trace.sv5T,1,copy 
	@

Trace.sv5T,0,copy : package/lib/lib/debug/gt_noOS/Trace.sv5T
Trace.sv5T,1,copy : package/lib/lib/release/gt_noOS/Trace.sv5T

$(XDCCFGDIR)%.c $(XDCCFGDIR)%.h $(XDCCFGDIR)%.xdl: $(XDCCFGDIR)%.cfg .interfaces $(XDCROOT)/packages/xdc/cfg/Main.xs
	@$(MSG) "configuring $(_PROG_NAME) from $< ..."
	$(CONFIG) $(_PROG_XSOPTS) xdc.cfg $(_PROG_NAME) $(XDCCFGDIR)$*.cfg $(XDCCFGDIR)$*

.PHONY: release,ti_sdo_fc_utils_gtinfra
ti_sdo_fc_utils_gtinfra.tar: package/package.bld.xml
ti_sdo_fc_utils_gtinfra.tar: package/package.ext.xml
ti_sdo_fc_utils_gtinfra.tar: package/package.rel.dot
ti_sdo_fc_utils_gtinfra.tar: package/build.cfg
ti_sdo_fc_utils_gtinfra.tar: package/package.xdc.inc
ti_sdo_fc_utils_gtinfra.tar: Trace.h
ti_sdo_fc_utils_gtinfra.tar: link.xdt
ti_sdo_fc_utils_gtinfra.tar: package.bld
ti_sdo_fc_utils_gtinfra.tar: simple_GCArmv5T.mak
ti_sdo_fc_utils_gtinfra.tar: package/package.cfg.xdc.inc
ti_sdo_fc_utils_gtinfra.tar: lib/debug/gt_bios.aem3
ti_sdo_fc_utils_gtinfra.tar: package/package_ti.sdo.fc.utils.gtinfra.c
ti_sdo_fc_utils_gtinfra.tar: GT_config_BIOS.c
ti_sdo_fc_utils_gtinfra.tar: Trace.c
ti_sdo_fc_utils_gtinfra.tar: lib/release/gt_bios.aem3
ti_sdo_fc_utils_gtinfra.tar: lib/debug/gt_bios.ae674
ti_sdo_fc_utils_gtinfra.tar: lib/release/gt_bios.ae674
ti_sdo_fc_utils_gtinfra.tar: lib/debug/gt_noOS.aem3
ti_sdo_fc_utils_gtinfra.tar: GT_config_noOS.c
ti_sdo_fc_utils_gtinfra.tar: lib/release/gt_noOS.aem3
ti_sdo_fc_utils_gtinfra.tar: lib/debug/gt_noOS.ae674
ti_sdo_fc_utils_gtinfra.tar: lib/release/gt_noOS.ae674
ti_sdo_fc_utils_gtinfra.tar: lib/debug/gt_noOS.av5T
ti_sdo_fc_utils_gtinfra.tar: lib/release/gt_noOS.av5T
ifeq (,$(MK_NOGENDEPS))
-include package/rel/ti_sdo_fc_utils_gtinfra.tar.dep
endif
package/rel/ti_sdo_fc_utils_gtinfra/ti/sdo/fc/utils/gtinfra/package/package.rel.xml:

ti_sdo_fc_utils_gtinfra.tar: package/rel/ti_sdo_fc_utils_gtinfra.xdc.inc package/rel/ti_sdo_fc_utils_gtinfra/ti/sdo/fc/utils/gtinfra/package/package.rel.xml
	@$(MSG) making release file $@ "(because of $(firstword $?))" ...
	-$(RM) $@
	$(call MKRELTAR,package/rel/ti_sdo_fc_utils_gtinfra.xdc.inc,package/rel/ti_sdo_fc_utils_gtinfra.tar.dep)


release release,ti_sdo_fc_utils_gtinfra: all ti_sdo_fc_utils_gtinfra.tar
clean:: .clean
	-$(RM) ti_sdo_fc_utils_gtinfra.tar
	-$(RM) package/rel/ti_sdo_fc_utils_gtinfra.xdc.inc
	-$(RM) package/rel/ti_sdo_fc_utils_gtinfra.tar.dep

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
ifeq (,$(wildcard package/lib/lib/debug/gt_bios))
    $(shell $(MKDIR) package/lib/lib/debug/gt_bios)
endif
ifeq (,$(wildcard package/lib/lib/debug/gt_bios/package))
    $(shell $(MKDIR) package/lib/lib/debug/gt_bios/package)
endif
ifeq (,$(wildcard package/lib/lib/release))
    $(shell $(MKDIR) package/lib/lib/release)
endif
ifeq (,$(wildcard package/lib/lib/release/gt_bios))
    $(shell $(MKDIR) package/lib/lib/release/gt_bios)
endif
ifeq (,$(wildcard package/lib/lib/release/gt_bios/package))
    $(shell $(MKDIR) package/lib/lib/release/gt_bios/package)
endif
ifeq (,$(wildcard package/lib/lib/debug/gt_noOS))
    $(shell $(MKDIR) package/lib/lib/debug/gt_noOS)
endif
ifeq (,$(wildcard package/lib/lib/debug/gt_noOS/package))
    $(shell $(MKDIR) package/lib/lib/debug/gt_noOS/package)
endif
ifeq (,$(wildcard package/lib/lib/release/gt_noOS))
    $(shell $(MKDIR) package/lib/lib/release/gt_noOS)
endif
ifeq (,$(wildcard package/lib/lib/release/gt_noOS/package))
    $(shell $(MKDIR) package/lib/lib/release/gt_noOS/package)
endif
endif
clean::
	-$(RMDIR) package


clean:: 
	-$(RM) package/ti.sdo.fc.utils.gtinfra.pjt
