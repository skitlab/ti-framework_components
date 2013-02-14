#
#  ======== makefile ========
#

PROFILE = release

fc: $(LIBDIR)/ti/sdo/fc/acpy3/lib/$(PROFILE)/acpy3.av5T
fc: $(LIBDIR)/ti/sdo/fc/acpy3/lib/$(PROFILE)/acpy3cpu.av5T
fc: $(LIBDIR)/ti/sdo/fc/dman3/lib/$(PROFILE)/dman3.av5T
fc: $(LIBDIR)/ti/sdo/fc/dman3/lib/$(PROFILE)/dman3cpu.av5T
fc: $(LIBDIR)/ti/sdo/fc/dman3/lib/$(PROFILE)/dman3Cfg.av5T
fc: $(LIBDIR)/ti/sdo/fc/dman3/lib/$(PROFILE)/dman3cpuCfg.av5T
fc: $(LIBDIR)/ti/sdo/fc/global/lib/$(PROFILE)/fcsettings.av5T
fc: $(LIBDIR)/ti/sdo/fc/ires/bufres/lib/$(PROFILE)/bufres.av5T
fc: $(LIBDIR)/ti/sdo/fc/ires/hdvicp/lib/$(PROFILE)/hdvicp.av5T
fc: $(LIBDIR)/ti/sdo/fc/ires/nullresource/lib/$(PROFILE)/nullres.av5T
fc: $(LIBDIR)/ti/sdo/fc/ires/sdma/lib/$(PROFILE)/sdma.av5T
fc: $(LIBDIR)/ti/sdo/fc/ires/shmbuf/lib/$(PROFILE)/shmbuf.av5T
fc: $(LIBDIR)/ti/sdo/fc/memutils/lib/$(PROFILE)/memutils.av5T
fc: $(LIBDIR)/ti/sdo/fc/rman/lib/$(PROFILE)/rmanNoYield.av5T
fc: $(LIBDIR)/ti/sdo/fc/scpy/lib/$(PROFILE)/scpy.av5T
fc: $(LIBDIR)/ti/sdo/utils/trace/lib/$(PROFILE)/gt.av5T
fc: $(LIBDIR)/ti/sdo/fc/utils/lib/$(PROFILE)/rmm.av5T
fc: $(LIBDIR)/ti/sdo/fc/utils/api/lib/$(PROFILE)/api.av5T
fc: $(LIBDIR)/ti/sdo/fc/utils/gtinfra/lib/$(PROFILE)/gt_noOS.av5T
fc: $(LIBDIR)/ti/sdo/fc/utils/osal/lib/$(PROFILE)/sem.av5T
fc: $(LIBDIR)/ti/sdo/fc/utils/osal/noOS/lib/$(PROFILE)/noOS.av5T
fc: $(LIBDIR)/ti/sdo/fc/utils/osalsupport/lib/$(PROFILE)/osal_support.av5T
fc: $(LIBDIR)/ti/sdo/opencl/lib/$(PROFILE)/opencl_api_syslink.av5T
fc: $(LIBDIR)/ti/sdo/rcm/lib/$(PROFILE)/rcm.av5T
fc: $(LIBDIR)/ti/sdo/tiler/lib/$(PROFILE)/tiler_linux.av5T

PKGPATH = $(IPC_INSTALL_DIR)/packages;$(FC_INSTALL_DIR)/packages;$(OSAL_INSTALL_DIR)/sources;$(OSAL_INSTALL_DIR)/packages;$(LINK_INSTALL_DIR)/packages;$(XDAIS_INSTALL_DIR)/packages;$(CMEM_INSTALL_DIR)/packages


#
#  ======== makefile.GCArmv5T ========
#
$(LIBDIR)/ti/sdo/fc/acpy3/lib/$(PROFILE)/acpy3.av5T $(LIBDIR)ti/sdo/fc/acpy3/lib/$(PROFILE)/acpy3cpu.av5T:
	@echo "#"
	@echo "# Making $@..."
	$(MAKE) -C ti/sdo/fc/acpy3 -f simple_GCArmv5T.mak \
            PKG_PATH="$(PKGPATH)" \
            CGTOOLS_V5T=$(CGTOOLS_V5T) \
            CC_V5T=$(CC_V5T) \
            AR_V5T=$(AR_V5T) \
	    LIBDIR=$(LIBDIR)/ti/sdo/fc/acpy3/lib/$(PROFILE)
            $@

$(LIBDIR)/ti/sdo/fc/dman3/lib/$(PROFILE)/dman3.av5T $(LIBDIR)/ti/sdo/fc/dman3/lib/$(PROFILE)/dman3cpu.av5T $(LIBDIR)/ti/sdo/fc/dman3/lib/$(PROFILE)/dman3Cfg.av5T $(LIBDIR)/ti/sdo/fc/dman3/lib/$(PROFILE)/dman3cpuCfg.av5T:
	@echo "#"
	@echo "# Making $@..."
	$(MAKE) -C ti/sdo/fc/dman3 -f simple_GCArmv5T.mak \
            PKG_PATH="$(PKGPATH)" \
            CGTOOLS_V5T=$(CGTOOLS_V5T) \
            CC_V5T=$(CC_V5T) \
            AR_V5T=$(AR_V5T) \
	    LIBDIR=$(LIBDIR)/ti/sdo/fc/dman3/lib/$(PROFILE)
            $@

$(LIBDIR)/ti/sdo/fc/global/lib/$(PROFILE)/fcsettings.av5T:
	@echo "#"
	@echo "# Making $@..."
	$(MAKE) -C ti/sdo/fc/global -f simple_GCArmv5T.mak \
            PKG_PATH="$(PKGPATH)" \
            CGTOOLS_V5T=$(CGTOOLS_V5T) \
            CC_V5T=$(CC_V5T) \
            AR_V5T=$(AR_V5T) \
	    LIBDIR=$(LIBDIR)/ti/sdo/fc/global/lib/$(PROFILE)
            $@

$(LIBDIR)/ti/sdo/fc/ires/bufres/lib/$(PROFILE)/bufres.av5T:
	@echo "#"
	@echo "# Making $@..."
	$(MAKE) -C ti/sdo/fc/ires/bufres -f simple_GCArmv5T.mak \
            PKG_PATH="$(PKGPATH)" \
            CGTOOLS_V5T=$(CGTOOLS_V5T) \
            CC_V5T=$(CC_V5T) \
            AR_V5T=$(AR_V5T) \
	    LIBDIR=$(LIBDIR)/ti/sdo/fc/ires/bufres/lib/$(PROFILE)
            $@


$(LIBDIR)/ti/sdo/fc/ires/hdvicp/lib/$(PROFILE)/hdvicp.av5T:
	@echo "#"
	@echo "# Making $@..."
	$(MAKE) -C ti/sdo/fc/ires/hdvicp -f simple_GCArmv5T.mak \
            PKG_PATH="$(PKGPATH)" \
            CGTOOLS_V5T=$(CGTOOLS_V5T) \
            CC_V5T=$(CC_V5T) \
            AR_V5T=$(AR_V5T) \
	    LIBDIR=$(LIBDIR)/ti/sdo/fc/ires/hdvicp/lib/$(PROFILE)
            $@

$(LIBDIR)/ti/sdo/fc/ires/nullresource/lib/$(PROFILE)/nullres.av5T:
	@echo "#"
	@echo "# Making $@..."
	$(MAKE) -C ti/sdo/fc/ires/nullresource -f simple_GCArmv5T.mak \
            PKG_PATH="$(PKGPATH)" \
            CGTOOLS_V5T=$(CGTOOLS_V5T) \
            CC_V5T=$(CC_V5T) \
            AR_V5T=$(AR_V5T) \
	    LIBDIR=$(LIBDIR)/ti/sdo/fc/ires/nullresource/lib/$(PROFILE)
            $@

$(LIBDIR)/ti/sdo/fc/ires/sdma/lib/$(PROFILE)/sdma.av5T:
	@echo "#"
	@echo "# Making $@..."
	$(MAKE) -C ti/sdo/fc/ires/sdma -f simple_GCArmv5T.mak \
            PKG_PATH="$(PKGPATH)" \
            CGTOOLS_V5T=$(CGTOOLS_V5T) \
            CC_V5T=$(CC_V5T) \
            AR_V5T=$(AR_V5T) \
	    LIBDIR=$(LIBDIR)/ti/sdo/fc/ires/sdma/lib/$(PROFILE)
            $@

$(LIBDIR)/ti/sdo/fc/ires/shmbuf/lib/$(PROFILE)/shmbuf.av5T:
	@echo "#"
	@echo "# Making $@..."
	$(MAKE) -C ti/sdo/fc/ires/shmbuf -f simple_GCArmv5T.mak \
            PKG_PATH="$(PKGPATH)" \
            CGTOOLS_V5T=$(CGTOOLS_V5T) \
            CC_V5T=$(CC_V5T) \
            AR_V5T=$(AR_V5T) \
	    LIBDIR=$(LIBDIR)/ti/sdo/fc/ires/shmbuf/lib/$(PROFILE)
            $@

$(LIBDIR)/ti/sdo/fc/memutils/lib/$(PROFILE)/memutils.av5T:
	@echo "#"
	@echo "# Making $@..."
	$(MAKE) -C ti/sdo/fc/memutils -f simple_GCArmv5T.mak \
            PKG_PATH="$(PKGPATH)" \
            CGTOOLS_V5T=$(CGTOOLS_V5T) \
            CC_V5T=$(CC_V5T) \
            AR_V5T=$(AR_V5T) \
	    LIBDIR=$(LIBDIR)/ti/sdo/fc/memutils/lib/$(PROFILE)
            $@

$(LIBDIR)/ti/sdo/fc/rman/lib/$(PROFILE)/rmanNoYield.av5T:
	@echo "#"
	@echo "# Making $@..."
	$(MAKE) -C ti/sdo/fc/rman -f simple_GCArmv5T.mak \
            PKG_PATH="$(PKGPATH)" \
            CGTOOLS_V5T=$(CGTOOLS_V5T) \
            CC_V5T=$(CC_V5T) \
            AR_V5T=$(AR_V5T) \
	    LIBDIR=$(LIBDIR)/ti/sdo/fc/rman/lib/$(PROFILE)
            $@

$(LIBDIR)/ti/sdo/fc/scpy/lib/$(PROFILE)/scpy.av5T:
	@echo "#"
	@echo "# Making $@..."
	$(MAKE) -C ti/sdo/fc/scpy -f simple_GCArmv5T.mak \
            PKG_PATH="$(PKGPATH)" \
            CGTOOLS_V5T=$(CGTOOLS_V5T) \
            CC_V5T=$(CC_V5T) \
            AR_V5T=$(AR_V5T) \
	    LIBDIR=$(LIBDIR)/ti/sdo/fc/scpy/lib/$(PROFILE)
            $@

$(LIBDIR)/ti/sdo/utils/trace/lib/$(PROFILE)/gt.av5T:
	@echo "#"
	@echo "# Making $@..."
	$(MAKE) -C ti/sdo/utils/trace -f simple_GCArmv5T.mak \
            PKG_PATH="$(PKGPATH)" \
            CGTOOLS_V5T=$(CGTOOLS_V5T) \
            CC_V5T=$(CC_V5T) \
            AR_V5T=$(AR_V5T) \
	    LIBDIR=$(LIBDIR)/ti/sdo/utils/trace/lib/$(PROFILE)
            $@

$(LIBDIR)/ti/sdo/fc/utils/lib/$(PROFILE)/rmm.av5T:
	@echo "#"
	@echo "# Making $@..."
	$(MAKE) -C ti/sdo/fc/utils -f simple_GCArmv5T.mak \
            PKG_PATH="$(PKGPATH)" \
            CGTOOLS_V5T=$(CGTOOLS_V5T) \
            CC_V5T=$(CC_V5T) \
            AR_V5T=$(AR_V5T) \
	    LIBDIR=$(LIBDIR)/ti/sdo/fc/utils/lib/$(PROFILE)
            $@

$(LIBDIR)/ti/sdo/fc/utils/api/lib/$(PROFILE)/api.av5T:
	@echo "#"
	@echo "# Making $@..."
	$(MAKE) -C ti/sdo/fc/utils/api -f simple_GCArmv5T.mak \
            PKG_PATH="$(PKGPATH)" \
            CGTOOLS_V5T=$(CGTOOLS_V5T) \
            CC_V5T=$(CC_V5T) \
            AR_V5T=$(AR_V5T) \
	    LIBDIR=$(LIBDIR)/ti/sdo/fc/utils/api/lib/$(PROFILE)/
            $@

$(LIBDIR)/ti/sdo/fc/utils/gtinfra/lib/$(PROFILE)/gt_noOS.av5T:
	@echo "#"
	@echo "# Making $@..."
	$(MAKE) -C ti/sdo/fc/utils/gtinfra -f simple_GCArmv5T.mak \
            PKG_PATH="$(PKGPATH)" \
            CGTOOLS_V5T=$(CGTOOLS_V5T) \
            CC_V5T=$(CC_V5T) \
            AR_V5T=$(AR_V5T) \
	    LIBDIR=$(LIBDIR)/ti/sdo/fc/utils/gtinfra/lib/$(PROFILE)
            $@

$(LIBDIR)/ti/sdo/fc/utils/osal/lib/$(PROFILE)/sem.av5T:
	@echo "#"
	@echo "# Making $@..."
	$(MAKE) -C ti/sdo/fc/utils/osal -f simple_GCArmv5T.mak \
            PKG_PATH="$(PKGPATH)" \
            CGTOOLS_V5T=$(CGTOOLS_V5T) \
            CC_V5T=$(CC_V5T) \
            AR_V5T=$(AR_V5T) \
	    LIBDIR=$(LIBDIR)/ti/sdo/fc/utils/osal/lib/$(PROFILE)/
            $@

$(LIBDIR)/ti/sdo/fc/utils/osal/noOS/lib/$(PROFILE)/noOS.av5T:
	@echo "#"
	@echo "# Making $@..."
	$(MAKE) -C ti/sdo/fc/utils/osal/noOS -f simple_GCArmv5T.mak \
            PKG_PATH="$(PKGPATH)" \
            CGTOOLS_V5T=$(CGTOOLS_V5T) \
            CC_V5T=$(CC_V5T) \
            AR_V5T=$(AR_V5T) \
	    LIBDIR=$(LIBDIR)/ti/sdo/fc/utils/osal/noOS/lib/$(PROFILE)/
            $@

$(LIBDIR)/ti/sdo/fc/utils/osalsupport/lib/$(PROFILE)/osal_support.av5T:
	@echo "#"
	@echo "# Making $@..."
	$(MAKE) -C ti/sdo/fc/utils/osalsupport -f simple_GCArmv5T.mak \
            PKG_PATH="$(PKGPATH)" \
            CGTOOLS_V5T=$(CGTOOLS_V5T) \
            CC_V5T=$(CC_V5T) \
            AR_V5T=$(AR_V5T) \
	    LIBDIR=$(LIBDIR)/ti/sdo/fc/utils/osalsupport/lib/$(PROFILE)
            $@

$(LIBDIR)/ti/sdo/opencl/lib/$(PROFILE)/opencl_api_syslink.av5T:
	@echo "#"
	@echo "# Making $@..."
	$(MAKE) -C ti/sdo/opencl -f simple_GCArmv5T.mak \
            PKG_PATH="$(PKGPATH)" \
            CGTOOLS_V5T=$(CGTOOLS_V5T) \
            CC_V5T=$(CC_V5T) \
            AR_V5T=$(AR_V5T) \
	    LIBDIR=$(LIBDIR)/ti/sdo/opencl/lib/$(PROFILE)
            $@

$(LIBDIR)/ti/sdo/rcm/lib/$(PROFILE)/rcm.av5T:
	@echo "#"
	@echo "# Making $@..."
	$(MAKE) -C ti/sdo/rcm -f simple_GCArmv5T.mak \
            PKG_PATH="$(PKGPATH)" \
            CGTOOLS_V5T=$(CGTOOLS_V5T) \
            CC_V5T=$(CC_V5T) \
            AR_V5T=$(AR_V5T) \
	    LIBDIR=$(LIBDIR)/ti/sdo/rcm/lib/$(PROFILE)
            $@

$(LIBDIR)/ti/sdo/tiler/lib/$(PROFILE)/tiler_linux.av5T:
	@echo "#"
	@echo "# Making $@..."
	$(MAKE) -C ti/sdo/tiler -f simple_GCArmv5T.mak \
            PKG_PATH="$(PKGPATH)" \
            CGTOOLS_V5T=$(CGTOOLS_V5T) \
            CC_V5T=$(CC_V5T) \
            AR_V5T=$(AR_V5T) \
	    LIBDIR=$(LIBDIR)/ti/sdo/tiler/lib/$(PROFILE)
            $@

#
#  ======== clean ========
#
clean::
	@echo "#"
	@echo "# Cleaning packages..."
	$(MAKE) -C ti/sdo/fc/acpy3 -f simple_GCArmv5T.mak clean
	$(MAKE) -C ti/sdo/fc/dman3 -f simple_GCArmv5T.mak clean
	$(MAKE) -C ti/sdo/fc/global -f simple_GCArmv5T.mak clean
	$(MAKE) -C ti/sdo/fc/ires/bufres -f simple_GCArmv5T.mak clean
	$(MAKE) -C ti/sdo/fc/ires/hdvicp -f simple_GCArmv5T.mak clean
	$(MAKE) -C ti/sdo/fc/ires/nullresource -f simple_GCArmv5T.mak clean
	$(MAKE) -C ti/sdo/fc/ires/sdma -f simple_GCArmv5T.mak clean
	$(MAKE) -C ti/sdo/fc/ires/shmbuf -f simple_GCArmv5T.mak clean
	$(MAKE) -C ti/sdo/fc/memutils -f simple_GCArmv5T.mak clean
	$(MAKE) -C ti/sdo/fc/rman -f simple_GCArmv5T.mak clean
	$(MAKE) -C ti/sdo/fc/scpy -f simple_GCArmv5T.mak clean
	$(MAKE) -C ti/sdo/utils/trace -f simple_GCArmv5T.mak clean
	$(MAKE) -C ti/sdo/fc/utils -f simple_GCArmv5T.mak clean
	$(MAKE) -C ti/sdo/fc/utils/api -f simple_GCArmv5T.mak clean
	$(MAKE) -C ti/sdo/fc/utils/gtinfra -f simple_GCArmv5T.mak clean
	$(MAKE) -C ti/sdo/fc/utils/osal -f simple_GCArmv5T.mak clean
	$(MAKE) -C ti/sdo/fc/utils/osal/noOS -f simple_GCArmv5T.mak clean
	$(MAKE) -C ti/sdo/fc/utils/osalsupport -f simple_GCArmv5T.mak clean
	$(MAKE) -C ti/sdo/opencl -f simple_GCArmv5T.mak clean
	$(MAKE) -C ti/sdo/rcm -f simple_GCArmv5T.mak clean
	$(MAKE) -C ti/sdo/tiler -f simple_GCArmv5T.mak clean
