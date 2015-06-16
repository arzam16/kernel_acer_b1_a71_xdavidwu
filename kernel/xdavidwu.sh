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
for file in $(find . -name *.ko); do
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
if [ "$1" == "test" ]; then
	echo "testing on real device selected";
	cd /home/xdavidwu/桌面/;
	echo "make zip...";
	cp boot${datenow}.img zip/boot.img;
	cd zip;
	zip -r ../test${datenow} * ;
	rm /home/xdavidwu/桌面/zip/boot.img;
	echo "reboot into recovery...";
	adb reboot recovery;
	echo "Go to sideload and press enter!";
	read thisisenter;
	adb sideload /home/xdavidwu/桌面/test${datenow}.zip;
	echo "Now installing your new kernel!";
	echo "After installing, press enter again! I'll reboot it!";
	read anotherenter;
	adb reboot;
	if [ "$2" == "clean" ]; then
		rm ../test${datenow}.zip;
		rm ../boot${datenow}.img;
	fi
elif [ "$1" == "release" ]; then
	echo "release the builded kernel";
	cd /home/xdavidwu/桌面/;
	echo "make zip...";
	cp boot${datenow}.img zip/boot.img;
	cd zip;
	zip -r ../B1-A71_kernel_${datenow} * ;
	rm /home/xdavidwu/桌面/zip/boot.img;
	echo "Flashable zip created: B1-A71_kernel_${datenow}.zip"
	if [ "$2" == "clean" ]; then
		rm ../boot${datenow}.img;
	fi
fi
