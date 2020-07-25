## Introduction

This is the kernel source code for Acer Iconia B1-A71. It is based on the B1-710 source package (Linux 3.4.x), including patches to make it work. Thanks [superdragonpt](https://forum.xda-developers.com/member.php?u=5238428) from XDA Developers and [xdavidwu](https://github.com/xdavidwu) for your contributions.

## Building

After you clone the repository, do:

```
cd kernel_acer_b1_a71_xdavidwu/kernel
export CROSS_COMPILE=/path/to/your/toolchain/bin/arm-xxx-
export TARGET_PRODUCT=acer17_tb_wifi_only_jb
export MTK_ROOT_CUSTOM=../mediatek/custom/
make
```

## Toolchain

This kernel could be successfully built with GCC 4.6 toolchain from [Google Git](https://android.googlesource.com/platform/prebuilts/gcc/linux-x86/arm/arm-linux-androideabi-4.6/).

## Non-free (proprietary) code warning

This repository contains non-free (proprietary) code. You can find the list of non-free components in [non-free.txt](https://github.com/arzam16/kernel_acer_b1_a71_xdavidwu/blob/master/non-free.txt).
