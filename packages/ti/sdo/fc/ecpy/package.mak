#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#

unexport MAKEFILE_LIST
MK_NOGENDEPS := $(filter clean,$(MAKECMDGOALS))
override PKGDIR = ti/sdo/fc/ecpy
XDCINCS = -I. -I$(strip $(subst ;, -I,$(subst $(space),\$(space),$(XPKGPATH))))
XDCPKGS = $(call pkgsearch,ti/bios/include )
XDCINCS += $(if $(XDCPKGS),-I$(subst $(space), -I,$(XDCPKGS)))
IMPORTPATH += $(if $(XDCPKGS),;$(subst $(space),;,$(XDCPKGS)))
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

ti.targets.elf.C674.rootDir ?= /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/dsp-devkit/cgt6x_7_3_1
ti.targets.elf.packageBase ?= /swcoe/sdk/cm/netra/ti-ezsdk_dm816x-evm_5_05_01_04/component-sources/xdctools_3_23_03_53/packages/ti/targets/elf/
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

all,em3 .libraries,em3 .dlls,em3 .executables,em3 test,em3:;
all,v5T .libraries,v5T .dlls,v5T .executables,v5T test,v5T:;

all: .executables 
.executables: .libraries .dlls
.libraries: .interfaces

PKGCFGS := $(wildcard package.xs) package/build.cfg
.interfaces: package/package.xdc.inc package/package.defs.h package.xdc $(PKGCFGS)

-include package/package.xdc.dep
package/%.xdc.inc package/%_ti.sdo.fc.ecpy.c package/%.defs.h: %.xdc $(PKGCFGS)
	@$(MSG) generating interfaces for package ti.sdo.fc.ecpy" (because $@ is older than $(firstword $?))" ...
	$(XSRUN) -f xdc/services/intern/cmd/build.xs $(MK_IDLOPTS) -m package/package.xdc.dep -i package/package.xdc.inc package.xdc

ifeq (,$(MK_NOGENDEPS))
-include package/package.cfg.dep
endif

package/package.ext.xml: package/package.cfg.xdc.inc
package/package.cfg.xdc.inc: $(XDCROOT)/packages/xdc/cfg/cfginc.js package.xdc
	@$(MSG) generating schema include file list ...
	$(CONFIG) -f $(XDCROOT)/packages/xdc/cfg/cfginc.js ti.sdo.fc.ecpy $@

.libraries,e674 .libraries: lib/debug/ecpy.ae674

-include lib/debug/ecpy.ae674.mak
lib/debug/ecpy.ae674: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/debug/ecpy/package/package_ti.sdo.fc.ecpy.oe674 package/lib/lib/debug/ecpy/ecpy_init.oe674 package/lib/lib/debug/ecpy/ecpy_impl.oe674 package/lib/lib/debug/ecpy/ecpy_configure16.oe674 package/lib/lib/debug/ecpy/ecpy_configure32.oe674 package/lib/lib/debug/ecpy/ecpycfg.oe674 package/lib/lib/debug/ecpy/ecpy_wait.oe674 package/lib/lib/debug/ecpy/ecpy_directwait.oe674  into $@ ...
	$(ti.targets.elf.C674.rootDir)/bin/ar6x  rq $@   package/lib/lib/debug/ecpy/package/package_ti.sdo.fc.ecpy.oe674 package/lib/lib/debug/ecpy/ecpy_init.oe674 package/lib/lib/debug/ecpy/ecpy_impl.oe674 package/lib/lib/debug/ecpy/ecpy_configure16.oe674 package/lib/lib/debug/ecpy/ecpy_configure32.oe674 package/lib/lib/debug/ecpy/ecpycfg.oe674 package/lib/lib/debug/ecpy/ecpy_wait.oe674 package/lib/lib/debug/ecpy/ecpy_directwait.oe674 
lib/debug/ecpy.ae674: export C_DIR=
lib/debug/ecpy.ae674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

clean,e674 clean::
	-$(RM) lib/debug/ecpy.ae674
.libraries,e674 .libraries: lib/release/ecpy.ae674

-include lib/release/ecpy.ae674.mak
lib/release/ecpy.ae674: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/release/ecpy/package/package_ti.sdo.fc.ecpy.oe674 package/lib/lib/release/ecpy/ecpy_init.oe674 package/lib/lib/release/ecpy/ecpy_impl.oe674 package/lib/lib/release/ecpy/ecpy_configure16.oe674 package/lib/lib/release/ecpy/ecpy_configure32.oe674 package/lib/lib/release/ecpy/ecpycfg.oe674 package/lib/lib/release/ecpy/ecpy_wait.oe674 package/lib/lib/release/ecpy/ecpy_directwait.oe674  into $@ ...
	$(ti.targets.elf.C674.rootDir)/bin/ar6x  rq $@   package/lib/lib/release/ecpy/package/package_ti.sdo.fc.ecpy.oe674 package/lib/lib/release/ecpy/ecpy_init.oe674 package/lib/lib/release/ecpy/ecpy_impl.oe674 package/lib/lib/release/ecpy/ecpy_configure16.oe674 package/lib/lib/release/ecpy/ecpy_configure32.oe674 package/lib/lib/release/ecpy/ecpycfg.oe674 package/lib/lib/release/ecpy/ecpy_wait.oe674 package/lib/lib/release/ecpy/ecpy_directwait.oe674 
lib/release/ecpy.ae674: export C_DIR=
lib/release/ecpy.ae674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

clean,e674 clean::
	-$(RM) lib/release/ecpy.ae674
.libraries,e674 .libraries: lib/debug/ecpy_cacheMode.ae674

-include lib/debug/ecpy_cacheMode.ae674.mak
lib/debug/ecpy_cacheMode.ae674: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/debug/ecpy_cacheMode/package/package_ti.sdo.fc.ecpy.oe674 package/lib/lib/debug/ecpy_cacheMode/ecpy_init.oe674 package/lib/lib/debug/ecpy_cacheMode/ecpy_impl.oe674 package/lib/lib/debug/ecpy_cacheMode/ecpy_configure16.oe674 package/lib/lib/debug/ecpy_cacheMode/ecpy_configure32.oe674 package/lib/lib/debug/ecpy_cacheMode/ecpycfg.oe674 package/lib/lib/debug/ecpy_cacheMode/ecpy_wait.oe674 package/lib/lib/debug/ecpy_cacheMode/ecpy_directwait.oe674  into $@ ...
	$(ti.targets.elf.C674.rootDir)/bin/ar6x  rq $@   package/lib/lib/debug/ecpy_cacheMode/package/package_ti.sdo.fc.ecpy.oe674 package/lib/lib/debug/ecpy_cacheMode/ecpy_init.oe674 package/lib/lib/debug/ecpy_cacheMode/ecpy_impl.oe674 package/lib/lib/debug/ecpy_cacheMode/ecpy_configure16.oe674 package/lib/lib/debug/ecpy_cacheMode/ecpy_configure32.oe674 package/lib/lib/debug/ecpy_cacheMode/ecpycfg.oe674 package/lib/lib/debug/ecpy_cacheMode/ecpy_wait.oe674 package/lib/lib/debug/ecpy_cacheMode/ecpy_directwait.oe674 
lib/debug/ecpy_cacheMode.ae674: export C_DIR=
lib/debug/ecpy_cacheMode.ae674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

clean,e674 clean::
	-$(RM) lib/debug/ecpy_cacheMode.ae674
.libraries,e674 .libraries: lib/release/ecpy_cacheMode.ae674

-include lib/release/ecpy_cacheMode.ae674.mak
lib/release/ecpy_cacheMode.ae674: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/release/ecpy_cacheMode/package/package_ti.sdo.fc.ecpy.oe674 package/lib/lib/release/ecpy_cacheMode/ecpy_init.oe674 package/lib/lib/release/ecpy_cacheMode/ecpy_impl.oe674 package/lib/lib/release/ecpy_cacheMode/ecpy_configure16.oe674 package/lib/lib/release/ecpy_cacheMode/ecpy_configure32.oe674 package/lib/lib/release/ecpy_cacheMode/ecpycfg.oe674 package/lib/lib/release/ecpy_cacheMode/ecpy_wait.oe674 package/lib/lib/release/ecpy_cacheMode/ecpy_directwait.oe674  into $@ ...
	$(ti.targets.elf.C674.rootDir)/bin/ar6x  rq $@   package/lib/lib/release/ecpy_cacheMode/package/package_ti.sdo.fc.ecpy.oe674 package/lib/lib/release/ecpy_cacheMode/ecpy_init.oe674 package/lib/lib/release/ecpy_cacheMode/ecpy_impl.oe674 package/lib/lib/release/ecpy_cacheMode/ecpy_configure16.oe674 package/lib/lib/release/ecpy_cacheMode/ecpy_configure32.oe674 package/lib/lib/release/ecpy_cacheMode/ecpycfg.oe674 package/lib/lib/release/ecpy_cacheMode/ecpy_wait.oe674 package/lib/lib/release/ecpy_cacheMode/ecpy_directwait.oe674 
lib/release/ecpy_cacheMode.ae674: export C_DIR=
lib/release/ecpy_cacheMode.ae674: PATH:=$(ti.targets.elf.C674.rootDir)/bin/:$(PATH)

clean,e674 clean::
	-$(RM) lib/release/ecpy_cacheMode.ae674
test:;
%,copy:
	@$(if $<,,$(MSG) don\'t know how to build $*; exit 1)
	@$(MSG) cp $< $@
	$(RM) $@
	$(CP) $< $@
.PHONY: package_ti.sdo.fc.ecpy.oe674,copy
package_ti.sdo.fc.ecpy.oe674,copy : package_ti.sdo.fc.ecpy.oe674,0,copy package_ti.sdo.fc.ecpy.oe674,1,copy package_ti.sdo.fc.ecpy.oe674,2,copy package_ti.sdo.fc.ecpy.oe674,3,copy 
	@

package_ti.sdo.fc.ecpy.oe674,0,copy : package/lib/lib/debug/ecpy/package/package_ti.sdo.fc.ecpy.oe674
package_ti.sdo.fc.ecpy.oe674,1,copy : package/lib/lib/debug/ecpy_cacheMode/package/package_ti.sdo.fc.ecpy.oe674
package_ti.sdo.fc.ecpy.oe674,2,copy : package/lib/lib/release/ecpy/package/package_ti.sdo.fc.ecpy.oe674
package_ti.sdo.fc.ecpy.oe674,3,copy : package/lib/lib/release/ecpy_cacheMode/package/package_ti.sdo.fc.ecpy.oe674
.PHONY: package_ti.sdo.fc.ecpy.se674,copy
package_ti.sdo.fc.ecpy.se674,copy : package_ti.sdo.fc.ecpy.se674,0,copy package_ti.sdo.fc.ecpy.se674,1,copy package_ti.sdo.fc.ecpy.se674,2,copy package_ti.sdo.fc.ecpy.se674,3,copy 
	@

package_ti.sdo.fc.ecpy.se674,0,copy : package/lib/lib/debug/ecpy/package/package_ti.sdo.fc.ecpy.se674
package_ti.sdo.fc.ecpy.se674,1,copy : package/lib/lib/debug/ecpy_cacheMode/package/package_ti.sdo.fc.ecpy.se674
package_ti.sdo.fc.ecpy.se674,2,copy : package/lib/lib/release/ecpy/package/package_ti.sdo.fc.ecpy.se674
package_ti.sdo.fc.ecpy.se674,3,copy : package/lib/lib/release/ecpy_cacheMode/package/package_ti.sdo.fc.ecpy.se674
.PHONY: ecpy_init.oe674,copy
ecpy_init.oe674,copy : ecpy_init.oe674,0,copy ecpy_init.oe674,1,copy ecpy_init.oe674,2,copy ecpy_init.oe674,3,copy 
	@

ecpy_init.oe674,0,copy : package/lib/lib/debug/ecpy/ecpy_init.oe674
ecpy_init.oe674,1,copy : package/lib/lib/debug/ecpy_cacheMode/ecpy_init.oe674
ecpy_init.oe674,2,copy : package/lib/lib/release/ecpy/ecpy_init.oe674
ecpy_init.oe674,3,copy : package/lib/lib/release/ecpy_cacheMode/ecpy_init.oe674
.PHONY: ecpy_init.se674,copy
ecpy_init.se674,copy : ecpy_init.se674,0,copy ecpy_init.se674,1,copy ecpy_init.se674,2,copy ecpy_init.se674,3,copy 
	@

ecpy_init.se674,0,copy : package/lib/lib/debug/ecpy/ecpy_init.se674
ecpy_init.se674,1,copy : package/lib/lib/debug/ecpy_cacheMode/ecpy_init.se674
ecpy_init.se674,2,copy : package/lib/lib/release/ecpy/ecpy_init.se674
ecpy_init.se674,3,copy : package/lib/lib/release/ecpy_cacheMode/ecpy_init.se674
.PHONY: ecpy_impl.oe674,copy
ecpy_impl.oe674,copy : ecpy_impl.oe674,0,copy ecpy_impl.oe674,1,copy ecpy_impl.oe674,2,copy ecpy_impl.oe674,3,copy 
	@

ecpy_impl.oe674,0,copy : package/lib/lib/debug/ecpy/ecpy_impl.oe674
ecpy_impl.oe674,1,copy : package/lib/lib/debug/ecpy_cacheMode/ecpy_impl.oe674
ecpy_impl.oe674,2,copy : package/lib/lib/release/ecpy/ecpy_impl.oe674
ecpy_impl.oe674,3,copy : package/lib/lib/release/ecpy_cacheMode/ecpy_impl.oe674
.PHONY: ecpy_impl.se674,copy
ecpy_impl.se674,copy : ecpy_impl.se674,0,copy ecpy_impl.se674,1,copy ecpy_impl.se674,2,copy ecpy_impl.se674,3,copy 
	@

ecpy_impl.se674,0,copy : package/lib/lib/debug/ecpy/ecpy_impl.se674
ecpy_impl.se674,1,copy : package/lib/lib/debug/ecpy_cacheMode/ecpy_impl.se674
ecpy_impl.se674,2,copy : package/lib/lib/release/ecpy/ecpy_impl.se674
ecpy_impl.se674,3,copy : package/lib/lib/release/ecpy_cacheMode/ecpy_impl.se674
.PHONY: ecpy_configure16.oe674,copy
ecpy_configure16.oe674,copy : ecpy_configure16.oe674,0,copy ecpy_configure16.oe674,1,copy ecpy_configure16.oe674,2,copy ecpy_configure16.oe674,3,copy 
	@

ecpy_configure16.oe674,0,copy : package/lib/lib/debug/ecpy/ecpy_configure16.oe674
ecpy_configure16.oe674,1,copy : package/lib/lib/debug/ecpy_cacheMode/ecpy_configure16.oe674
ecpy_configure16.oe674,2,copy : package/lib/lib/release/ecpy/ecpy_configure16.oe674
ecpy_configure16.oe674,3,copy : package/lib/lib/release/ecpy_cacheMode/ecpy_configure16.oe674
.PHONY: ecpy_configure16.se674,copy
ecpy_configure16.se674,copy : ecpy_configure16.se674,0,copy ecpy_configure16.se674,1,copy ecpy_configure16.se674,2,copy ecpy_configure16.se674,3,copy 
	@

ecpy_configure16.se674,0,copy : package/lib/lib/debug/ecpy/ecpy_configure16.se674
ecpy_configure16.se674,1,copy : package/lib/lib/debug/ecpy_cacheMode/ecpy_configure16.se674
ecpy_configure16.se674,2,copy : package/lib/lib/release/ecpy/ecpy_configure16.se674
ecpy_configure16.se674,3,copy : package/lib/lib/release/ecpy_cacheMode/ecpy_configure16.se674
.PHONY: ecpy_configure32.oe674,copy
ecpy_configure32.oe674,copy : ecpy_configure32.oe674,0,copy ecpy_configure32.oe674,1,copy ecpy_configure32.oe674,2,copy ecpy_configure32.oe674,3,copy 
	@

ecpy_configure32.oe674,0,copy : package/lib/lib/debug/ecpy/ecpy_configure32.oe674
ecpy_configure32.oe674,1,copy : package/lib/lib/debug/ecpy_cacheMode/ecpy_configure32.oe674
ecpy_configure32.oe674,2,copy : package/lib/lib/release/ecpy/ecpy_configure32.oe674
ecpy_configure32.oe674,3,copy : package/lib/lib/release/ecpy_cacheMode/ecpy_configure32.oe674
.PHONY: ecpy_configure32.se674,copy
ecpy_configure32.se674,copy : ecpy_configure32.se674,0,copy ecpy_configure32.se674,1,copy ecpy_configure32.se674,2,copy ecpy_configure32.se674,3,copy 
	@

ecpy_configure32.se674,0,copy : package/lib/lib/debug/ecpy/ecpy_configure32.se674
ecpy_configure32.se674,1,copy : package/lib/lib/debug/ecpy_cacheMode/ecpy_configure32.se674
ecpy_configure32.se674,2,copy : package/lib/lib/release/ecpy/ecpy_configure32.se674
ecpy_configure32.se674,3,copy : package/lib/lib/release/ecpy_cacheMode/ecpy_configure32.se674
.PHONY: ecpycfg.oe674,copy
ecpycfg.oe674,copy : ecpycfg.oe674,0,copy ecpycfg.oe674,1,copy ecpycfg.oe674,2,copy ecpycfg.oe674,3,copy 
	@

ecpycfg.oe674,0,copy : package/lib/lib/debug/ecpy/ecpycfg.oe674
ecpycfg.oe674,1,copy : package/lib/lib/debug/ecpy_cacheMode/ecpycfg.oe674
ecpycfg.oe674,2,copy : package/lib/lib/release/ecpy/ecpycfg.oe674
ecpycfg.oe674,3,copy : package/lib/lib/release/ecpy_cacheMode/ecpycfg.oe674
.PHONY: ecpycfg.se674,copy
ecpycfg.se674,copy : ecpycfg.se674,0,copy ecpycfg.se674,1,copy ecpycfg.se674,2,copy ecpycfg.se674,3,copy 
	@

ecpycfg.se674,0,copy : package/lib/lib/debug/ecpy/ecpycfg.se674
ecpycfg.se674,1,copy : package/lib/lib/debug/ecpy_cacheMode/ecpycfg.se674
ecpycfg.se674,2,copy : package/lib/lib/release/ecpy/ecpycfg.se674
ecpycfg.se674,3,copy : package/lib/lib/release/ecpy_cacheMode/ecpycfg.se674
.PHONY: ecpy_wait.oe674,copy
ecpy_wait.oe674,copy : ecpy_wait.oe674,0,copy ecpy_wait.oe674,1,copy ecpy_wait.oe674,2,copy ecpy_wait.oe674,3,copy 
	@

ecpy_wait.oe674,0,copy : package/lib/lib/debug/ecpy/ecpy_wait.oe674
ecpy_wait.oe674,1,copy : package/lib/lib/debug/ecpy_cacheMode/ecpy_wait.oe674
ecpy_wait.oe674,2,copy : package/lib/lib/release/ecpy/ecpy_wait.oe674
ecpy_wait.oe674,3,copy : package/lib/lib/release/ecpy_cacheMode/ecpy_wait.oe674
.PHONY: ecpy_wait.se674,copy
ecpy_wait.se674,copy : ecpy_wait.se674,0,copy ecpy_wait.se674,1,copy ecpy_wait.se674,2,copy ecpy_wait.se674,3,copy 
	@

ecpy_wait.se674,0,copy : package/lib/lib/debug/ecpy/ecpy_wait.se674
ecpy_wait.se674,1,copy : package/lib/lib/debug/ecpy_cacheMode/ecpy_wait.se674
ecpy_wait.se674,2,copy : package/lib/lib/release/ecpy/ecpy_wait.se674
ecpy_wait.se674,3,copy : package/lib/lib/release/ecpy_cacheMode/ecpy_wait.se674
.PHONY: ecpy_directwait.oe674,copy
ecpy_directwait.oe674,copy : ecpy_directwait.oe674,0,copy ecpy_directwait.oe674,1,copy ecpy_directwait.oe674,2,copy ecpy_directwait.oe674,3,copy 
	@

ecpy_directwait.oe674,0,copy : package/lib/lib/debug/ecpy/ecpy_directwait.oe674
ecpy_directwait.oe674,1,copy : package/lib/lib/debug/ecpy_cacheMode/ecpy_directwait.oe674
ecpy_directwait.oe674,2,copy : package/lib/lib/release/ecpy/ecpy_directwait.oe674
ecpy_directwait.oe674,3,copy : package/lib/lib/release/ecpy_cacheMode/ecpy_directwait.oe674
.PHONY: ecpy_directwait.se674,copy
ecpy_directwait.se674,copy : ecpy_directwait.se674,0,copy ecpy_directwait.se674,1,copy ecpy_directwait.se674,2,copy ecpy_directwait.se674,3,copy 
	@

ecpy_directwait.se674,0,copy : package/lib/lib/debug/ecpy/ecpy_directwait.se674
ecpy_directwait.se674,1,copy : package/lib/lib/debug/ecpy_cacheMode/ecpy_directwait.se674
ecpy_directwait.se674,2,copy : package/lib/lib/release/ecpy/ecpy_directwait.se674
ecpy_directwait.se674,3,copy : package/lib/lib/release/ecpy_cacheMode/ecpy_directwait.se674

$(XDCCFGDIR)%.c $(XDCCFGDIR)%.h $(XDCCFGDIR)%.xdl: $(XDCCFGDIR)%.cfg .interfaces $(XDCROOT)/packages/xdc/cfg/Main.xs
	@$(MSG) "configuring $(_PROG_NAME) from $< ..."
	$(CONFIG) $(_PROG_XSOPTS) xdc.cfg $(_PROG_NAME) $(XDCCFGDIR)$*.cfg $(XDCCFGDIR)$*

.PHONY: release,ti_sdo_fc_ecpy
ti_sdo_fc_ecpy.tar: package/package.bld.xml
ti_sdo_fc_ecpy.tar: package/package.ext.xml
ti_sdo_fc_ecpy.tar: package/package.rel.dot
ti_sdo_fc_ecpy.tar: package/build.cfg
ti_sdo_fc_ecpy.tar: package/package.xdc.inc
ti_sdo_fc_ecpy.tar: ecpy.h
ti_sdo_fc_ecpy.tar: ecpy_wait.h
ti_sdo_fc_ecpy.tar: ecpy_configure32.h
ti_sdo_fc_ecpy.tar: ecpy_util.h
ti_sdo_fc_ecpy.tar: ecpy_configure16.h
ti_sdo_fc_ecpy.tar: ecpy_directwait.h
ti_sdo_fc_ecpy.tar: package.bld
ti_sdo_fc_ecpy.tar: package/package.cfg.xdc.inc
ti_sdo_fc_ecpy.tar: lib/debug/ecpy.ae674
ti_sdo_fc_ecpy.tar: package/package_ti.sdo.fc.ecpy.c
ti_sdo_fc_ecpy.tar: ecpy_init.c
ti_sdo_fc_ecpy.tar: ecpy_impl.c
ti_sdo_fc_ecpy.tar: ecpy_configure16.c
ti_sdo_fc_ecpy.tar: ecpy_configure32.c
ti_sdo_fc_ecpy.tar: ecpycfg.c
ti_sdo_fc_ecpy.tar: ecpy_wait.c
ti_sdo_fc_ecpy.tar: ecpy_directwait.c
ti_sdo_fc_ecpy.tar: lib/release/ecpy.ae674
ti_sdo_fc_ecpy.tar: lib/debug/ecpy_cacheMode.ae674
ti_sdo_fc_ecpy.tar: lib/release/ecpy_cacheMode.ae674
ifeq (,$(MK_NOGENDEPS))
-include package/rel/ti_sdo_fc_ecpy.tar.dep
endif
package/rel/ti_sdo_fc_ecpy/ti/sdo/fc/ecpy/package/package.rel.xml:

ti_sdo_fc_ecpy.tar: package/rel/ti_sdo_fc_ecpy.xdc.inc package/rel/ti_sdo_fc_ecpy/ti/sdo/fc/ecpy/package/package.rel.xml
	@$(MSG) making release file $@ "(because of $(firstword $?))" ...
	-$(RM) $@
	$(call MKRELTAR,package/rel/ti_sdo_fc_ecpy.xdc.inc,package/rel/ti_sdo_fc_ecpy.tar.dep)


release release,ti_sdo_fc_ecpy: all ti_sdo_fc_ecpy.tar
clean:: .clean
	-$(RM) ti_sdo_fc_ecpy.tar
	-$(RM) package/rel/ti_sdo_fc_ecpy.xdc.inc
	-$(RM) package/rel/ti_sdo_fc_ecpy.tar.dep

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
ifeq (,$(wildcard package/lib/lib/debug/ecpy))
    $(shell $(MKDIR) package/lib/lib/debug/ecpy)
endif
ifeq (,$(wildcard package/lib/lib/debug/ecpy/package))
    $(shell $(MKDIR) package/lib/lib/debug/ecpy/package)
endif
ifeq (,$(wildcard package/lib/lib/release))
    $(shell $(MKDIR) package/lib/lib/release)
endif
ifeq (,$(wildcard package/lib/lib/release/ecpy))
    $(shell $(MKDIR) package/lib/lib/release/ecpy)
endif
ifeq (,$(wildcard package/lib/lib/release/ecpy/package))
    $(shell $(MKDIR) package/lib/lib/release/ecpy/package)
endif
ifeq (,$(wildcard package/lib/lib/debug/ecpy_cacheMode))
    $(shell $(MKDIR) package/lib/lib/debug/ecpy_cacheMode)
endif
ifeq (,$(wildcard package/lib/lib/debug/ecpy_cacheMode/package))
    $(shell $(MKDIR) package/lib/lib/debug/ecpy_cacheMode/package)
endif
ifeq (,$(wildcard package/lib/lib/release/ecpy_cacheMode))
    $(shell $(MKDIR) package/lib/lib/release/ecpy_cacheMode)
endif
ifeq (,$(wildcard package/lib/lib/release/ecpy_cacheMode/package))
    $(shell $(MKDIR) package/lib/lib/release/ecpy_cacheMode/package)
endif
endif
clean::
	-$(RMDIR) package


clean:: 
	-$(RM) package/ti.sdo.fc.ecpy.pjt
