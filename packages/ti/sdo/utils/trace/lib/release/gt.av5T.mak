#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = gnu.targets.arm.GCArmv5T{1,0,4.3,3
#
ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/gt/package/package_ti.sdo.utils.trace.ov5T.dep
endif

package/lib/lib/release/gt/package/package_ti.sdo.utils.trace.ov5T: | .interfaces
package/lib/lib/release/gt/package/package_ti.sdo.utils.trace.ov5T: package/package_ti.sdo.utils.trace.c lib/release/gt.av5T.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clv5T $< ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/bin/arm-none-linux-gnueabi-gcc -c -MD -MF $@.dep -x c  -fPIC -Wunused -march=armv5t -Dfar=  -Wall -fno-strict-aliasing   -UGT_TRACE -DGT_TRACE=1 -UGT_ASSERT -DGT_ASSERT=1  -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_3_3 -O2 -ffunction-sections -fdata-sections  $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/gt/package/package_ti.sdo.utils.trace.ov5T: export LD_LIBRARY_PATH=

package/lib/lib/release/gt/package/package_ti.sdo.utils.trace.sv5T: | .interfaces
package/lib/lib/release/gt/package/package_ti.sdo.utils.trace.sv5T: package/package_ti.sdo.utils.trace.c lib/release/gt.av5T.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clv5T -S $< ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/bin/arm-none-linux-gnueabi-gcc -c -MD -MF $@.dep -x c -S -fPIC -Wunused -march=armv5t -Dfar=  -Wall -fno-strict-aliasing   -UGT_TRACE -DGT_TRACE=1 -UGT_ASSERT -DGT_ASSERT=1  -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_3_3 -O2 -ffunction-sections -fdata-sections  $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/gt/package/package_ti.sdo.utils.trace.sv5T: export LD_LIBRARY_PATH=

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/gt/gt.ov5T.dep
endif

package/lib/lib/release/gt/gt.ov5T: | .interfaces
package/lib/lib/release/gt/gt.ov5T: gt.c lib/release/gt.av5T.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clv5T $< ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/bin/arm-none-linux-gnueabi-gcc -c -MD -MF $@.dep -x c  -fPIC -Wunused -march=armv5t -Dfar=  -Wall -fno-strict-aliasing   -UGT_TRACE -DGT_TRACE=1 -UGT_ASSERT -DGT_ASSERT=1  -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_3_3 -O2 -ffunction-sections -fdata-sections  $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/gt/gt.ov5T: export LD_LIBRARY_PATH=

package/lib/lib/release/gt/gt.sv5T: | .interfaces
package/lib/lib/release/gt/gt.sv5T: gt.c lib/release/gt.av5T.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clv5T -S $< ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/bin/arm-none-linux-gnueabi-gcc -c -MD -MF $@.dep -x c -S -fPIC -Wunused -march=armv5t -Dfar=  -Wall -fno-strict-aliasing   -UGT_TRACE -DGT_TRACE=1 -UGT_ASSERT -DGT_ASSERT=1  -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_3_3 -O2 -ffunction-sections -fdata-sections  $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/gt/gt.sv5T: export LD_LIBRARY_PATH=

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/gt/CBuf.ov5T.dep
endif

package/lib/lib/release/gt/CBuf.ov5T: | .interfaces
package/lib/lib/release/gt/CBuf.ov5T: CBuf.c lib/release/gt.av5T.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clv5T $< ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/bin/arm-none-linux-gnueabi-gcc -c -MD -MF $@.dep -x c  -fPIC -Wunused -march=armv5t -Dfar=  -Wall -fno-strict-aliasing   -UGT_TRACE -DGT_TRACE=1 -UGT_ASSERT -DGT_ASSERT=1  -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_3_3 -O2 -ffunction-sections -fdata-sections  $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/gt/CBuf.ov5T: export LD_LIBRARY_PATH=

package/lib/lib/release/gt/CBuf.sv5T: | .interfaces
package/lib/lib/release/gt/CBuf.sv5T: CBuf.c lib/release/gt.av5T.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clv5T -S $< ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/bin/arm-none-linux-gnueabi-gcc -c -MD -MF $@.dep -x c -S -fPIC -Wunused -march=armv5t -Dfar=  -Wall -fno-strict-aliasing   -UGT_TRACE -DGT_TRACE=1 -UGT_ASSERT -DGT_ASSERT=1  -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_3_3 -O2 -ffunction-sections -fdata-sections  $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/gt/CBuf.sv5T: export LD_LIBRARY_PATH=

ifeq (,$(MK_NOGENDEPS))
-include package/lib/lib/release/gt/gt_config.ov5T.dep
endif

package/lib/lib/release/gt/gt_config.ov5T: | .interfaces
package/lib/lib/release/gt/gt_config.ov5T: gt_config.c lib/release/gt.av5T.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clv5T $< ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/bin/arm-none-linux-gnueabi-gcc -c -MD -MF $@.dep -x c  -fPIC -Wunused -march=armv5t -Dfar=  -Wall -fno-strict-aliasing   -UGT_TRACE -DGT_TRACE=1 -UGT_ASSERT -DGT_ASSERT=1  -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_3_3 -O2 -ffunction-sections -fdata-sections  $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/gt/gt_config.ov5T: export LD_LIBRARY_PATH=

package/lib/lib/release/gt/gt_config.sv5T: | .interfaces
package/lib/lib/release/gt/gt_config.sv5T: gt_config.c lib/release/gt.av5T.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clv5T -S $< ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/bin/arm-none-linux-gnueabi-gcc -c -MD -MF $@.dep -x c -S -fPIC -Wunused -march=armv5t -Dfar=  -Wall -fno-strict-aliasing   -UGT_TRACE -DGT_TRACE=1 -UGT_ASSERT -DGT_ASSERT=1  -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_3_3 -O2 -ffunction-sections -fdata-sections  $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/lib/lib/release/gt/gt_config.sv5T: export LD_LIBRARY_PATH=

clean,v5T ::
	-$(RM) package/lib/lib/release/gt/package/package_ti.sdo.utils.trace.ov5T
	-$(RM) package/lib/lib/release/gt/gt.ov5T
	-$(RM) package/lib/lib/release/gt/CBuf.ov5T
	-$(RM) package/lib/lib/release/gt/gt_config.ov5T
	-$(RM) package/lib/lib/release/gt/package/package_ti.sdo.utils.trace.sv5T
	-$(RM) package/lib/lib/release/gt/gt.sv5T
	-$(RM) package/lib/lib/release/gt/CBuf.sv5T
	-$(RM) package/lib/lib/release/gt/gt_config.sv5T

lib/release/gt.av5T: package/lib/lib/release/gt/package/package_ti.sdo.utils.trace.ov5T package/lib/lib/release/gt/gt.ov5T package/lib/lib/release/gt/CBuf.ov5T package/lib/lib/release/gt/gt_config.ov5T lib/release/gt.av5T.mak

clean::
	-$(RM) lib/release/gt.av5T.mak
