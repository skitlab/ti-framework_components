LOCAL_PATH:= $(call my-dir)
include $(LOCAL_PATH)/../config/mm_config.mk

# Library suffix name
SUFFIX := bnc

###############################################################################
# RCM
###############################################################################
include $(CLEAR_VARS)

LOCAL_MODULE        := timm_rcm_syslink
LOCAL_MODULE_SUFFIX := .a
LOCAL_MODULE_CLASS  := STATIC_LIBRARIES
LOCAL_MODULE_TAGS   := optional

LOCAL_SRC_FILES := android_binaries/$(LOCAL_MODULE)$(LOCAL_MODULE_SUFFIX)

# Specify variables to be exported to the sub-build
define $(LOCAL_MODULE)_set_config_vars
    $(call timm_set_config_var1,XDCPATH) \
    $(call timm_set_config_var2,XDCBUILDCFG,CONFIG_BLD) \
    $(call timm_set_config_var1,TOOLCHAIN_DIR) \
    $(call timm_set_config_var1,TOOLCHAIN_CC) \
    $(call timm_set_config_var2,ANDROID_CFLAGS,CFLAGS) \
    $(call timm_set_config_var2,CROSS_COMPILE,TOOLCHAIN_DIR)
endef

# Build against the Android stack
define $(LOCAL_MODULE)_rebuild
$(LOCAL_PATH)/$(LOCAL_SRC_FILES) :
	$(call $(LOCAL_MODULE)_set_config_vars) \
	$(timm_XDC_INSTALL_DIR)/xdc clean -P $(LOCAL_PATH)/packages/ti/sdo/rcm
	$(call $(LOCAL_MODULE)_set_config_vars) \
	$(timm_XDC_INSTALL_DIR)/xdc -P $(LOCAL_PATH)/packages/ti/sdo/rcm
	mkdir -p $$(dir $$@)
	cp -fp $(LOCAL_PATH)/packages/ti/sdo/rcm/lib/release/rcm_syslink.a$(SUFFIX) $$@
endef
$(eval $(call $(LOCAL_MODULE)_rebuild))

include $(BUILD_PREBUILT)

# Cleanup
$(LOCAL_MODULE)_set_config_vars  :=
$(LOCAL_MODULE)_rebuild          :=

###############################################################################
# MEMUTILS
###############################################################################
include $(CLEAR_VARS)

LOCAL_MODULE        := timm_memutils
LOCAL_MODULE_SUFFIX := .a
LOCAL_MODULE_CLASS  := STATIC_LIBRARIES
LOCAL_MODULE_TAGS   := optional

LOCAL_SRC_FILES := android_binaries/$(LOCAL_MODULE)$(LOCAL_MODULE_SUFFIX)

# Specify variables to be exported to the sub-build
define $(LOCAL_MODULE)_set_config_vars
    $(call timm_set_config_var1,XDCPATH) \
    $(call timm_set_config_var2,XDCBUILDCFG,CONFIG_BLD) \
    $(call timm_set_config_var1,TOOLCHAIN_DIR) \
    $(call timm_set_config_var1,TOOLCHAIN_CC) \
    $(call timm_set_config_var2,ANDROID_CFLAGS,CFLAGS) \
    $(call timm_set_config_var2,CROSS_COMPILE,TOOLCHAIN_DIR)
endef

# Build against the Android stack
define $(LOCAL_MODULE)_rebuild
$(LOCAL_PATH)/$(LOCAL_SRC_FILES) :
	$(call $(LOCAL_MODULE)_set_config_vars) \
	$(timm_XDC_INSTALL_DIR)/xdc clean -P $(LOCAL_PATH)/packages/ti/sdo/fc/memutils
	$(call $(LOCAL_MODULE)_set_config_vars) \
	$(timm_XDC_INSTALL_DIR)/xdc -P $(LOCAL_PATH)/packages/ti/sdo/fc/memutils
	mkdir -p $$(dir $$@)
	cp -fp $(LOCAL_PATH)/packages/ti/sdo/fc/memutils/lib/release/memutils.a$(SUFFIX) $$@
endef
$(eval $(call $(LOCAL_MODULE)_rebuild))

include $(BUILD_PREBUILT)

# Cleanup
$(LOCAL_MODULE)_set_config_vars  :=
$(LOCAL_MODULE)_rebuild          :=

###############################################################################
# TILER
###############################################################################
include $(CLEAR_VARS)

LOCAL_MODULE        := timm_tiler
LOCAL_MODULE_SUFFIX := .a
LOCAL_MODULE_CLASS  := STATIC_LIBRARIES
LOCAL_MODULE_TAGS   := optional

LOCAL_SRC_FILES := android_binaries/$(LOCAL_MODULE)$(LOCAL_MODULE_SUFFIX)

# Specify variables to be exported to the sub-build
define $(LOCAL_MODULE)_set_config_vars
    $(call timm_set_config_var1,XDCPATH) \
    $(call timm_set_config_var2,XDCBUILDCFG,CONFIG_BLD) \
    $(call timm_set_config_var1,TOOLCHAIN_DIR) \
    $(call timm_set_config_var1,TOOLCHAIN_CC) \
    $(call timm_set_config_var2,ANDROID_CFLAGS,CFLAGS) \
    $(call timm_set_config_var2,CROSS_COMPILE,TOOLCHAIN_DIR)
endef

# Build against the Android stack
define $(LOCAL_MODULE)_rebuild
$(LOCAL_PATH)/$(LOCAL_SRC_FILES) :
	$(call $(LOCAL_MODULE)_set_config_vars) \
	$(timm_XDC_INSTALL_DIR)/xdc clean -P $(LOCAL_PATH)/packages/ti/sdo/tiler
	$(call $(LOCAL_MODULE)_set_config_vars) \
	$(timm_XDC_INSTALL_DIR)/xdc -P $(LOCAL_PATH)/packages/ti/sdo/tiler
	mkdir -p $$(dir $$@)
	cp -fp $(LOCAL_PATH)/packages/ti/sdo/tiler/lib/release/tiler_linux.a$(SUFFIX) $$@
endef
$(eval $(call $(LOCAL_MODULE)_rebuild))

include $(BUILD_PREBUILT)

# Cleanup
$(LOCAL_MODULE)_set_config_vars  :=
$(LOCAL_MODULE)_rebuild          :=

###############################################################################
# FCSETTINGS
###############################################################################
include $(CLEAR_VARS)

LOCAL_MODULE        := timm_fcsettings
LOCAL_MODULE_SUFFIX := .a
LOCAL_MODULE_CLASS  := STATIC_LIBRARIES
LOCAL_MODULE_TAGS   := optional

LOCAL_SRC_FILES := android_binaries/$(LOCAL_MODULE)$(LOCAL_MODULE_SUFFIX)

# Specify variables to be exported to the sub-build
define $(LOCAL_MODULE)_set_config_vars
    $(call timm_set_config_var1,XDCPATH) \
    $(call timm_set_config_var2,XDCBUILDCFG,CONFIG_BLD) \
    $(call timm_set_config_var1,TOOLCHAIN_DIR) \
    $(call timm_set_config_var1,TOOLCHAIN_CC) \
    $(call timm_set_config_var2,ANDROID_CFLAGS,CFLAGS) \
    $(call timm_set_config_var2,CROSS_COMPILE,TOOLCHAIN_DIR)
endef

# Build against the Android stack
define $(LOCAL_MODULE)_rebuild
$(LOCAL_PATH)/$(LOCAL_SRC_FILES) :
	$(call $(LOCAL_MODULE)_set_config_vars) \
	$(timm_XDC_INSTALL_DIR)/xdc clean -P $(LOCAL_PATH)/packages/ti/sdo/fc/global
	$(call $(LOCAL_MODULE)_set_config_vars) \
	$(timm_XDC_INSTALL_DIR)/xdc -P $(LOCAL_PATH)/packages/ti/sdo/fc/global
	mkdir -p $$(dir $$@)
	cp -fp $(LOCAL_PATH)/packages/ti/sdo/fc/global/lib/release/fcsettings.a$(SUFFIX) $$@
endef
$(eval $(call $(LOCAL_MODULE)_rebuild))

include $(BUILD_PREBUILT)

# Cleanup
$(LOCAL_MODULE)_set_config_vars  :=
$(LOCAL_MODULE)_rebuild          :=

###############################################################################
# Other stuff
###############################################################################
include $(CLEAR_VARS)

LOCAL_MODULE        := timm_rman
LOCAL_MODULE_SUFFIX := .a
LOCAL_MODULE_CLASS  := STATIC_LIBRARIES
LOCAL_MODULE_TAGS   := optional

LOCAL_SRC_FILES := android_binaries/$(LOCAL_MODULE)$(LOCAL_MODULE_SUFFIX)

# Specify variables to be exported to the sub-build
define $(LOCAL_MODULE)_set_config_vars
    $(call timm_set_config_var1,XDCPATH) \
    $(call timm_set_config_var2,XDCBUILDCFG,CONFIG_BLD) \
    $(call timm_set_config_var1,TOOLCHAIN_DIR) \
    $(call timm_set_config_var1,TOOLCHAIN_CC) \
    $(call timm_set_config_var2,ANDROID_CFLAGS,CFLAGS) \
    $(call timm_set_config_var2,CROSS_COMPILE,TOOLCHAIN_DIR)
endef

# Build against the Android stack
define $(LOCAL_MODULE)_rebuild
$(LOCAL_PATH)/$(LOCAL_SRC_FILES) :
	$(call $(LOCAL_MODULE)_set_config_vars) \
	$(timm_XDC_INSTALL_DIR)/xdc clean -PR $(LOCAL_PATH)/packages/ti/sdo/fc/utils
	$(call $(LOCAL_MODULE)_set_config_vars) \
	$(timm_XDC_INSTALL_DIR)/xdc -PR $(LOCAL_PATH)/packages/ti/sdo/fc/utils
	$(call $(LOCAL_MODULE)_set_config_vars) \
	$(timm_XDC_INSTALL_DIR)/xdc clean -P $(LOCAL_PATH)/packages/ti/sdo/fc/acpy3
	$(call $(LOCAL_MODULE)_set_config_vars) \
	$(timm_XDC_INSTALL_DIR)/xdc -P $(LOCAL_PATH)/packages/ti/sdo/fc/acpy3
	$(call $(LOCAL_MODULE)_set_config_vars) \
	$(timm_XDC_INSTALL_DIR)/xdc clean -P $(LOCAL_PATH)/packages/ti/sdo/fc/dman3
	$(call $(LOCAL_MODULE)_set_config_vars) \
	$(timm_XDC_INSTALL_DIR)/xdc -P $(LOCAL_PATH)/packages/ti/sdo/fc/dman3
	$(call $(LOCAL_MODULE)_set_config_vars) \
	$(timm_XDC_INSTALL_DIR)/xdc clean -P $(LOCAL_PATH)/packages/ti/sdo/fc/rman
	$(call $(LOCAL_MODULE)_set_config_vars) \
	$(timm_XDC_INSTALL_DIR)/xdc -P $(LOCAL_PATH)/packages/ti/sdo/fc/rman
	$(call $(LOCAL_MODULE)_set_config_vars) \
	$(timm_XDC_INSTALL_DIR)/xdc clean -PR $(LOCAL_PATH)/packages/ti/sdo/fc/ires
	$(call $(LOCAL_MODULE)_set_config_vars) \
	$(timm_XDC_INSTALL_DIR)/xdc -PR $(LOCAL_PATH)/packages/ti/sdo/fc/ires
	mkdir -p $$(dir $$@)
	cp -fp $(LOCAL_PATH)/packages/ti/sdo/fc/global/lib/release/fcsettings.a$(SUFFIX) $$@
endef
$(eval $(call $(LOCAL_MODULE)_rebuild))

include $(BUILD_PREBUILT)

# Cleanup
$(LOCAL_MODULE)_set_config_vars  :=
$(LOCAL_MODULE)_rebuild          :=

include $(LOCAL_PATH)/../config/mm_config_cleanup.mk

