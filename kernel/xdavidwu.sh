mkimg="../mediatek/build/tools/mkimage"
#if [ "${KBUILD_OUTPUT_SUPPORT}" == "yes" ]; then
#  kernel_img="arch/arm/boot/Image"
#  kernel_zimg="arch/arm/boot/zImage"
#else
kernel_img="arch/arm/boot/Image"
kernel_zimg="arch/arm/boot/zImage"
#fi

if [ ! -x ${mkimg} ]; then chmod a+x ${mkimg}; fi

${mkimg} ${kernel_zimg} KERNEL > kernelFile
echo "**** Successfully built kernel ****"

echo "**** Copying kernel to /build_result/kernel/ ****"
mkdir -p ../build_result/kernel/
cp kernelFile ../build_result/kernel/kernel

echo "**** Copying all built modules (.ko) to /build_result/modules/ ****"
mkdir -p ../build_result/modules/
for file in $(find ../ -name *.ko); do
 cp $file ../build_result/modules/
done

echo "**** Patching all built modules (.ko) in /build_result/modules/ ****"
cd ..
find ./build_result/modules/ -type f -name '*.ko' | xargs -n 1 ${CROSS_COMPILE}strip --strip-unneeded

echo "####                          Finnish                                            ####"
echo ""

echo "####  You can find the zImage in the root folder: /build_result/kernel/          ####"
echo "####  You can find all kernel modules in the root folder: /build_result/modules/ ####"
echo ""
echo "####       Repack the zImage with the stock RamDisk, and your done               ####"
cp build_result/kernel/kernel /home/xdavidwu/桌面/boot4pda.img-kernel.img
datenow=$(date +%Y%m%d%H%M)
perl /home/xdavidwu/桌面/repack-MTK.pl -boot /home/xdavidwu/桌面/boot4pda.img-kernel.img /home/xdavidwu/桌面/boot4pda.img-ramdisk /home/xdavidwu/桌面/boot${datenow}.img
