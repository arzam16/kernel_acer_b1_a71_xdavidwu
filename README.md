# Warning! 

This repository contains non-free (proprietary) components. You can find the list of them in [non-free.txt](https://github.com/arzam16/kernel_acer_b1_a71_xdavidwu/blob/master/non-free.txt).

## Introduction

This is the kernel source code for Acer Iconia B1-A71. It is based on the B1-710 source package (Linux 3.4.x), including patches to make it work. Thanks [superdragonpt](https://forum.xda-developers.com/member.php?u=5238428) from XDA Developers and [xdavidwu](https://github.com/xdavidwu) for your contributions.

## Toolchain

The kernel with its default configuration could be successfully built with GCC 7.5.0 toolchain from [Linaro](https://releases.linaro.org/components/toolchain/binaries/latest-7/arm-linux-gnueabihf/).

## Building

After you clone the repository, do:

```
cd kernel_acer_b1_a71_xdavidwu/kernel
export ARCH=arm
export CROSS_COMPILE=/path/to/your/toolchain/bin/arm-xxx-
export TARGET_PRODUCT=acer17_tb_wifi_only_jb
make
```

## Creating boot.img

After you build the zImage, you can create the flashable boot.img.
Please note that *you'll need some ramdisk*, the one from the stock RC05RV05 firmware works great.
You'll also need an `mkimage` program to append MediaTek headers to both kernel and ramdisk.
`mkbootimg` utility usually could be installed from your OS' package manager.

```
mkimage arch/arm/boot/zImage KERNEL > kernel.mtk
mkimage /path/to/your/ramdisk ROOTFS > ramdisk.mtk
mkbootimg --kernel kernel.mtk --ramdisk ramdisk.mtk -o boot.img
```
