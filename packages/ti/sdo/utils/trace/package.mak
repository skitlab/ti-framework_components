#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#

unexport MAKEFILE_LIST
MK_NOGENDEPS := $(filter clean,$(MAKECMDGOALS))
override PKGDIR = ti/sdo/utils/trace
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
package/%.xdc.inc package/%_ti.sdo.utils.trace.c package/%.defs.h: %.xdc $(PKGCFGS)
	@$(MSG) generating interfaces for package ti.sdo.utils.trace" (because $@ is older than $(firstword $?))" ...
	$(XSRUN) -f xdc/services/intern/cmd/build.xs $(MK_IDLOPTS) -m package/package.xdc.dep -i package/package.xdc.inc package.xdc

ifeq (,$(MK_NOGENDEPS))
-include package/package.cfg.dep
endif

package/package.ext.xml: package/package.cfg.xdc.inc
package/package.cfg.xdc.inc: $(XDCROOT)/packages/xdc/cfg/cfginc.js package.xdc
	@$(MSG) generating schema include file list ...
	$(CONFIG) -f $(XDCROOT)/packages/xdc/cfg/cfginc.js ti.sdo.utils.trace $@

.libraries,em3 .libraries: lib/debug/gt.aem3

-include lib/debug/gt.aem3.mak
lib/debug/gt.aem3: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/debug/gt/package/package_ti.sdo.utils.trace.oem3 package/lib/lib/debug/gt/gt.oem3 package/lib/lib/debug/gt/CBuf.oem3 package/lib/lib/debug/gt/gt_config.oem3  into $@ ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/ar470  rq $@   package/lib/lib/debug/gt/package/package_ti.sdo.utils.trace.oem3 package/lib/lib/debug/gt/gt.oem3 package/lib/lib/debug/gt/CBuf.oem3 package/lib/lib/debug/gt/gt_config.oem3 
lib/debug/gt.aem3: export C_DIR=
lib/debug/gt.aem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

clean,em3 clean::
	-$(RM) lib/debug/gt.aem3
.libraries,em3 .libraries: lib/release/gt.aem3

-include lib/release/gt.aem3.mak
lib/release/gt.aem3: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/release/gt/package/package_ti.sdo.utils.trace.oem3 package/lib/lib/release/gt/gt.oem3 package/lib/lib/release/gt/CBuf.oem3 package/lib/lib/release/gt/gt_config.oem3  into $@ ...
	$(ti.targets.arm.elf.M3.rootDir)/bin/ar470  rq $@   package/lib/lib/release/gt/package/package_ti.sdo.utils.trace.oem3 package/lib/lib/release/gt/gt.oem3 package/lib/lib/release/gt/CBuf.oem3 package/lib/lib/release/gt/gt_config.oem3 
lib/release/gt.aem3: export C_DIR=
lib/release/gt.aem3: PATH:=$(ti.targets.arm.elf.M3.rootDir)/bin/:$(PATH)

clean,em3 clean::
	-$(RM) lib/release/gt.aem3
.libraries,e674 .libraries: lib/debug/gt.ae674

-include lib/debug/gt.ae674.mak
lib/debug/gt.ae674: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/debug/gt/package/package_ti.sdo.utils.trace.oe674 package/lib/lib/debug/gt/gt.oe674 package/lib/lib/debug/gt/CBuf.oe674 package/lib/lib/debug/gt/gt_config.oe674  into $@ ...
	$(ti.targets.elf.C674.rootDir)/bin/ar6x  rq $@   package/lib/lib/debug/gt/package/package_ti.sdo.utils.trace.oe674 package/lib/lib/debug/gt/gt.oe674 package/lib/lib/debug/gt/CBuf.oe674 package/lib/lib/debug/gt/gt_config.oe674 
lib/debug/gt.ae674: export C_DIR=
lib/debug/gt.ae674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

clean,e674 clean::
	-$(RM) lib/debug/gt.ae674
.libraries,e674 .libraries: lib/release/gt.ae674

-include lib/release/gt.ae674.mak
lib/release/gt.ae674: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/release/gt/package/package_ti.sdo.utils.trace.oe674 package/lib/lib/release/gt/gt.oe674 package/lib/lib/release/gt/CBuf.oe674 package/lib/lib/release/gt/gt_config.oe674  into $@ ...
	$(ti.targets.elf.C674.rootDir)/bin/ar6x  rq $@   package/lib/lib/release/gt/package/package_ti.sdo.utils.trace.oe674 package/lib/lib/release/gt/gt.oe674 package/lib/lib/release/gt/CBuf.oe674 package/lib/lib/release/gt/gt_config.oe674 
lib/release/gt.ae674: export C_DIR=
lib/release/gt.ae674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

clean,e674 clean::
	-$(RM) lib/release/gt.ae674
.libraries,v5T .libraries: lib/debug/gt.av5T

-include lib/debug/gt.av5T.mak
lib/debug/gt.av5T: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/debug/gt/package/package_ti.sdo.utils.trace.ov5T package/lib/lib/debug/gt/gt.ov5T package/lib/lib/debug/gt/CBuf.ov5T package/lib/lib/debug/gt/gt_config.ov5T  into $@ ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/arm-none-linux-gnueabi/bin/ar  cr $@   package/lib/lib/debug/gt/package/package_ti.sdo.utils.trace.ov5T package/lib/lib/debug/gt/gt.ov5T package/lib/lib/debug/gt/CBuf.ov5T package/lib/lib/debug/gt/gt_config.ov5T 
lib/debug/gt.av5T: export LD_LIBRARY_PATH=

clean,v5T clean::
	-$(RM) lib/debug/gt.av5T
.libraries,v5T .libraries: lib/release/gt.av5T

-include lib/release/gt.av5T.mak
lib/release/gt.av5T: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/release/gt/package/package_ti.sdo.utils.trace.ov5T package/lib/lib/release/gt/gt.ov5T package/lib/lib/release/gt/CBuf.ov5T package/lib/lib/release/gt/gt_config.ov5T  into $@ ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/arm-none-linux-gnueabi/bin/ar  cr $@   package/lib/lib/release/gt/package/package_ti.sdo.utils.trace.ov5T package/lib/lib/release/gt/gt.ov5T package/lib/lib/release/gt/CBuf.ov5T package/lib/lib/release/gt/gt_config.ov5T 
lib/release/gt.av5T: export LD_LIBRARY_PATH=

clean,v5T clean::
	-$(RM) lib/release/gt.av5T
test:;
%,copy:
	@$(if $<,,$(MSG) don\'t know how to build $*; exit 1)
	@$(MSG) cp $< $@
	$(RM) $@
	$(CP) $< $@
.PHONY: package_ti.sdo.utils.trace.oem3,copy
package_ti.sdo.utils.trace.oem3,copy : package_ti.sdo.utils.trace.oem3,0,copy package_ti.sdo.utils.trace.oem3,1,copy 
	@

package_ti.sdo.utils.trace.oem3,0,copy : package/lib/lib/debug/gt/package/package_ti.sdo.utils.trace.oem3
package_ti.sdo.utils.trace.oem3,1,copy : package/lib/lib/release/gt/package/package_ti.sdo.utils.trace.oem3
.PHONY: package_ti.sdo.utils.trace.sem3,copy
package_ti.sdo.utils.trace.sem3,copy : package_ti.sdo.utils.trace.sem3,0,copy package_ti.sdo.utils.trace.sem3,1,copy 
	@

package_ti.sdo.utils.trace.sem3,0,copy : package/lib/lib/debug/gt/package/package_ti.sdo.utils.trace.sem3
package_ti.sdo.utils.trace.sem3,1,copy : package/lib/lib/release/gt/package/package_ti.sdo.utils.trace.sem3
.PHONY: gt.oem3,copy
gt.oem3,copy : gt.oem3,0,copy gt.oem3,1,copy 
	@

gt.oem3,0,copy : package/lib/lib/debug/gt/gt.oem3
gt.oem3,1,copy : package/lib/lib/release/gt/gt.oem3
.PHONY: gt.sem3,copy
gt.sem3,copy : gt.sem3,0,copy gt.sem3,1,copy 
	@

gt.sem3,0,copy : package/lib/lib/debug/gt/gt.sem3
gt.sem3,1,copy : package/lib/lib/release/gt/gt.sem3
.PHONY: CBuf.oem3,copy
CBuf.oem3,copy : CBuf.oem3,0,copy CBuf.oem3,1,copy 
	@

CBuf.oem3,0,copy : package/lib/lib/debug/gt/CBuf.oem3
CBuf.oem3,1,copy : package/lib/lib/release/gt/CBuf.oem3
.PHONY: CBuf.sem3,copy
CBuf.sem3,copy : CBuf.sem3,0,copy CBuf.sem3,1,copy 
	@

CBuf.sem3,0,copy : package/lib/lib/debug/gt/CBuf.sem3
CBuf.sem3,1,copy : package/lib/lib/release/gt/CBuf.sem3
.PHONY: gt_config.oem3,copy
gt_config.oem3,copy : gt_config.oem3,0,copy gt_config.oem3,1,copy 
	@

gt_config.oem3,0,copy : package/lib/lib/debug/gt/gt_config.oem3
gt_config.oem3,1,copy : package/lib/lib/release/gt/gt_config.oem3
.PHONY: gt_config.sem3,copy
gt_config.sem3,copy : gt_config.sem3,0,copy gt_config.sem3,1,copy 
	@

gt_config.sem3,0,copy : package/lib/lib/debug/gt/gt_config.sem3
gt_config.sem3,1,copy : package/lib/lib/release/gt/gt_config.sem3
.PHONY: package_ti.sdo.utils.trace.oe674,copy
package_ti.sdo.utils.trace.oe674,copy : package_ti.sdo.utils.trace.oe674,0,copy package_ti.sdo.utils.trace.oe674,1,copy 
	@

package_ti.sdo.utils.trace.oe674,0,copy : package/lib/lib/debug/gt/package/package_ti.sdo.utils.trace.oe674
package_ti.sdo.utils.trace.oe674,1,copy : package/lib/lib/release/gt/package/package_ti.sdo.utils.trace.oe674
.PHONY: package_ti.sdo.utils.trace.se674,copy
package_ti.sdo.utils.trace.se674,copy : package_ti.sdo.utils.trace.se674,0,copy package_ti.sdo.utils.trace.se674,1,copy 
	@

package_ti.sdo.utils.trace.se674,0,copy : package/lib/lib/debug/gt/package/package_ti.sdo.utils.trace.se674
package_ti.sdo.utils.trace.se674,1,copy : package/lib/lib/release/gt/package/package_ti.sdo.utils.trace.se674
.PHONY: gt.oe674,copy
gt.oe674,copy : gt.oe674,0,copy gt.oe674,1,copy 
	@

gt.oe674,0,copy : package/lib/lib/debug/gt/gt.oe674
gt.oe674,1,copy : package/lib/lib/release/gt/gt.oe674
.PHONY: gt.se674,copy
gt.se674,copy : gt.se674,0,copy gt.se674,1,copy 
	@

gt.se674,0,copy : package/lib/lib/debug/gt/gt.se674
gt.se674,1,copy : package/lib/lib/release/gt/gt.se674
.PHONY: CBuf.oe674,copy
CBuf.oe674,copy : CBuf.oe674,0,copy CBuf.oe674,1,copy 
	@

CBuf.oe674,0,copy : package/lib/lib/debug/gt/CBuf.oe674
CBuf.oe674,1,copy : package/lib/lib/release/gt/CBuf.oe674
.PHONY: CBuf.se674,copy
CBuf.se674,copy : CBuf.se674,0,copy CBuf.se674,1,copy 
	@

CBuf.se674,0,copy : package/lib/lib/debug/gt/CBuf.se674
CBuf.se674,1,copy : package/lib/lib/release/gt/CBuf.se674
.PHONY: gt_config.oe674,copy
gt_config.oe674,copy : gt_config.oe674,0,copy gt_config.oe674,1,copy 
	@

gt_config.oe674,0,copy : package/lib/lib/debug/gt/gt_config.oe674
gt_config.oe674,1,copy : package/lib/lib/release/gt/gt_config.oe674
.PHONY: gt_config.se674,copy
gt_config.se674,copy : gt_config.se674,0,copy gt_config.se674,1,copy 
	@

gt_config.se674,0,copy : package/lib/lib/debug/gt/gt_config.se674
gt_config.se674,1,copy : package/lib/lib/release/gt/gt_config.se674
.PHONY: package_ti.sdo.utils.trace.ov5T,copy
package_ti.sdo.utils.trace.ov5T,copy : package_ti.sdo.utils.trace.ov5T,0,copy package_ti.sdo.utils.trace.ov5T,1,copy 
	@

package_ti.sdo.utils.trace.ov5T,0,copy : package/lib/lib/debug/gt/package/package_ti.sdo.utils.trace.ov5T
package_ti.sdo.utils.trace.ov5T,1,copy : package/lib/lib/release/gt/package/package_ti.sdo.utils.trace.ov5T
.PHONY: package_ti.sdo.utils.trace.sv5T,copy
package_ti.sdo.utils.trace.sv5T,copy : package_ti.sdo.utils.trace.sv5T,0,copy package_ti.sdo.utils.trace.sv5T,1,copy 
	@

package_ti.sdo.utils.trace.sv5T,0,copy : package/lib/lib/debug/gt/package/package_ti.sdo.utils.trace.sv5T
package_ti.sdo.utils.trace.sv5T,1,copy : package/lib/lib/release/gt/package/package_ti.sdo.utils.trace.sv5T
.PHONY: gt.ov5T,copy
gt.ov5T,copy : gt.ov5T,0,copy gt.ov5T,1,copy 
	@

gt.ov5T,0,copy : package/lib/lib/debug/gt/gt.ov5T
gt.ov5T,1,copy : package/lib/lib/release/gt/gt.ov5T
.PHONY: gt.sv5T,copy
gt.sv5T,copy : gt.sv5T,0,copy gt.sv5T,1,copy 
	@

gt.sv5T,0,copy : package/lib/lib/debug/gt/gt.sv5T
gt.sv5T,1,copy : package/lib/lib/release/gt/gt.sv5T
.PHONY: CBuf.ov5T,copy
CBuf.ov5T,copy : CBuf.ov5T,0,copy CBuf.ov5T,1,copy 
	@

CBuf.ov5T,0,copy : package/lib/lib/debug/gt/CBuf.ov5T
CBuf.ov5T,1,copy : package/lib/lib/release/gt/CBuf.ov5T
.PHONY: CBuf.sv5T,copy
CBuf.sv5T,copy : CBuf.sv5T,0,copy CBuf.sv5T,1,copy 
	@

CBuf.sv5T,0,copy : package/lib/lib/debug/gt/CBuf.sv5T
CBuf.sv5T,1,copy : package/lib/lib/release/gt/CBuf.sv5T
.PHONY: gt_config.ov5T,copy
gt_config.ov5T,copy : gt_config.ov5T,0,copy gt_config.ov5T,1,copy 
	@

gt_config.ov5T,0,copy : package/lib/lib/debug/gt/gt_config.ov5T
gt_config.ov5T,1,copy : package/lib/lib/release/gt/gt_config.ov5T
.PHONY: gt_config.sv5T,copy
gt_config.sv5T,copy : gt_config.sv5T,0,copy gt_config.sv5T,1,copy 
	@

gt_config.sv5T,0,copy : package/lib/lib/debug/gt/gt_config.sv5T
gt_config.sv5T,1,copy : package/lib/lib/release/gt/gt_config.sv5T

$(XDCCFGDIR)%.c $(XDCCFGDIR)%.h $(XDCCFGDIR)%.xdl: $(XDCCFGDIR)%.cfg .interfaces $(XDCROOT)/packages/xdc/cfg/Main.xs
	@$(MSG) "configuring $(_PROG_NAME) from $< ..."
	$(CONFIG) $(_PROG_XSOPTS) xdc.cfg $(_PROG_NAME) $(XDCCFGDIR)$*.cfg $(XDCCFGDIR)$*

.PHONY: release,ti_sdo_utils_trace
ti_sdo_utils_trace.tar: package/package.bld.xml
ti_sdo_utils_trace.tar: package/package.ext.xml
ti_sdo_utils_trace.tar: package/package.rel.dot
ti_sdo_utils_trace.tar: package/build.cfg
ti_sdo_utils_trace.tar: package/package.xdc.inc
ti_sdo_utils_trace.tar: gt.h
ti_sdo_utils_trace.tar: CBuf.h
ti_sdo_utils_trace.tar: package.bld
ti_sdo_utils_trace.tar: simple_GCArmv5T.mak
ti_sdo_utils_trace.tar: package/package.cfg.xdc.inc
ti_sdo_utils_trace.tar: lib/debug/gt.aem3
ti_sdo_utils_trace.tar: lib/release/gt.aem3
ti_sdo_utils_trace.tar: lib/debug/gt.ae674
ti_sdo_utils_trace.tar: lib/release/gt.ae674
ti_sdo_utils_trace.tar: lib/debug/gt.av5T
ti_sdo_utils_trace.tar: lib/release/gt.av5T
ifeq (,$(MK_NOGENDEPS))
-include package/rel/ti_sdo_utils_trace.tar.dep
endif
package/rel/ti_sdo_utils_trace/ti/sdo/utils/trace/package/package.rel.xml:

ti_sdo_utils_trace.tar: package/rel/ti_sdo_utils_trace.xdc.inc package/rel/ti_sdo_utils_trace/ti/sdo/utils/trace/package/package.rel.xml
	@$(MSG) making release file $@ "(because of $(firstword $?))" ...
	-$(RM) $@
	$(call MKRELTAR,package/rel/ti_sdo_utils_trace.xdc.inc,package/rel/ti_sdo_utils_trace.tar.dep)


release release,ti_sdo_utils_trace: all ti_sdo_utils_trace.tar
clean:: .clean
	-$(RM) ti_sdo_utils_trace.tar
	-$(RM) package/rel/ti_sdo_utils_trace.xdc.inc
	-$(RM) package/rel/ti_sdo_utils_trace.tar.dep

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
ifeq (,$(wildcard package/lib/lib/debug/gt))
    $(shell $(MKDIR) package/lib/lib/debug/gt)
endif
ifeq (,$(wildcard package/lib/lib/debug/gt/package))
    $(shell $(MKDIR) package/lib/lib/debug/gt/package)
endif
ifeq (,$(wildcard package/lib/lib/release))
    $(shell $(MKDIR) package/lib/lib/release)
endif
ifeq (,$(wildcard package/lib/lib/release/gt))
    $(shell $(MKDIR) package/lib/lib/release/gt)
endif
ifeq (,$(wildcard package/lib/lib/release/gt/package))
    $(shell $(MKDIR) package/lib/lib/release/gt/package)
endif
endif
clean::
	-$(RMDIR) package


clean:: 
	-$(RM) package/ti.sdo.utils.trace.pjt