. $1

make \
 XDAIS_INSTALL_DIR=$THIRD_PARTY_DIR/xdais \
 XDC_INSTALL_DIR=$THIRD_PARTY_DIR/xdctools \
 BIOS_INSTALL_DIR=$THIRD_PARTY_DIR/bios \
 CMEM_INSTALL_DIR=$THIRD_PARTY_DIR/linuxutils \
 OSAL_INSTALL_DIR=$THIRD_PARTY_DIR/osal \
 EDMA3_LLD_INSTALL_DIR=$THIRD_PARTY_DIR/edma3lld \
 IPC_INSTALL_DIR=$THIRD_PARTY_DIR/ipc \
 LINK_INSTALL_DIR=$THIRD_PARTY_DIR/syslink \
 DESTDIR=$THIRD_PARTY_DIR/devkit \
 CGTOOLS_V5T=$CROSSCOMPILER_DIR/../ \
 CC_V5T=bin/${CROSS_COMPILE}gcc \
 -f framework_components.mak \
all install

# ti.targets.C64P= \
# ti.targets.C674= \
# ti.targets.elf.C64P= \
# ti.targets.elf.C64T= \
# ti.targets.elf.C66= \
# ti.targets.elf.C674= \
# ti.targets.arm.elf.M3= \
