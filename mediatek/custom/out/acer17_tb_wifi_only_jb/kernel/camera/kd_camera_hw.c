#include <linux/videodev2.h>
#include <linux/i2c.h>
#include <linux/platform_device.h>
#include <linux/delay.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <asm/atomic.h>

#include "kd_camera_hw.h"

#include "kd_imgsensor.h"
#include "kd_imgsensor_define.h"
#include "kd_camera_feature.h"

/******************************************************************************
 * Debug configuration
******************************************************************************/
#define PFX "[kd_camera_hw]"
#define PK_DBG_NONE(fmt, arg...)    do {} while (0)
#define PK_DBG_FUNC(fmt, arg...)    printk(KERN_INFO PFX "%s: " fmt, __FUNCTION__ ,##arg)

#define DEBUG_CAMERA_HW_K
#ifdef DEBUG_CAMERA_HW_K
#define PK_DBG PK_DBG_FUNC
#define PK_ERR(fmt, arg...)         printk(KERN_ERR PFX "%s: " fmt, __FUNCTION__ ,##arg)
#else
#define PK_DBG(a,...)
#define PK_ERR(a,...)
#endif

 


int kdCISModulePowerOn(CAMERA_DUAL_CAMERA_SENSOR_ENUM SensorIdx, char *currSensorName, BOOL On, char* mode_name)
{
u32 pinSetIdx = 0;//default main sensor

#define IDX_PS_CMRST 0
#define IDX_PS_CMPDN 4

#define IDX_PS_MODE 1
#define IDX_PS_ON   2
#define IDX_PS_OFF  3
u32 pinSet[3][8] = {
                    //for main sensor 
                    {
				GPIO_CAMERA_CMRST_PIN,
				GPIO_CAMERA_CMRST_PIN_M_GPIO,   /* mode */
				GPIO_OUT_ONE,                   /* ON state */
				GPIO_OUT_ZERO,                  /* OFF state */
				GPIO_CAMERA_CMPDN_PIN,
				GPIO_CAMERA_CMPDN_PIN_M_GPIO,
				GPIO_OUT_ZERO,
				GPIO_OUT_ONE,
                    },
                    //for sub sensor 
			{
				GPIO_CAMERA_CMRST1_PIN,
				GPIO_CAMERA_CMRST1_PIN_M_GPIO,
				GPIO_OUT_ONE,
				GPIO_OUT_ZERO,
				GPIO_CAMERA_CMPDN1_PIN,
				GPIO_CAMERA_CMPDN1_PIN_M_GPIO,
				GPIO_OUT_ONE,
				GPIO_OUT_ZERO,
                    },
                    //for main_2 sensor 
                    {
				GPIO_CAMERA_2_CMRST_PIN,
				GPIO_CAMERA_2_CMRST_PIN_M_GPIO,   /* mode */
				GPIO_OUT_ONE,                   /* ON state */
				GPIO_OUT_ZERO,                  /* OFF state */
				GPIO_CAMERA_2_CMPDN_PIN,
				GPIO_CAMERA_2_CMPDN_PIN_M_GPIO,
				GPIO_OUT_ZERO,
				GPIO_OUT_ONE,
                    }
                   };

    if (DUAL_CAMERA_MAIN_SENSOR == SensorIdx){
        pinSetIdx = 0;
    }
    else if (DUAL_CAMERA_SUB_SENSOR == SensorIdx) {
        pinSetIdx = 1;
    }
    else if (DUAL_CAMERA_MAIN_SECOND_SENSOR == SensorIdx) {
        pinSetIdx = 2;
    }

    //power ON
    if (On) {
	if(mt_set_gpio_mode(GPIO228, GPIO_MODE_00))	printk("[CAMERA LENS] set gpio mode failed!! \n");
	if(mt_set_gpio_dir(GPIO228, GPIO_DIR_OUT))	printk("[CAMERA LENS] set gpio dir failed!! \n");
	if(mt_set_gpio_out(GPIO228, GPIO_OUT_ONE))	printk("[CAMERA LENS] set gpio failed!! \n");
	if(pinSetIdx == 1)
	{
		//For P3 Demo board
		//if(mt_set_gpio_mode(GPIO220, GPIO_MODE_00))	printk("[CAMERA LENS] set gpio mode failed!! \n");
		//if(mt_set_gpio_dir(GPIO220, GPIO_DIR_OUT))	printk("[CAMERA LENS] set gpio dir failed!! \n");
		//if(mt_set_gpio_out(GPIO220, GPIO_OUT_ONE))	printk("[CAMERA LENS] set gpio failed!! \n");
		//For Acer Pcb
		mdelay(5);
		
		if(TRUE != hwPowerOn(CAMERA_POWER_VCAM_D2, VOL_1800,mode_name))
		{
			PK_DBG("[CAMERA SENSOR] Fail to enable digital power\n");
			//return -EIO;
			goto _kdCISModulePowerOn_exit_;
		}
		mdelay(2); 
		if(TRUE != hwPowerOn(CAMERA_POWER_VCAM_A, VOL_2800,mode_name))
		{
			PK_DBG("[CAMERA SENSOR] Fail to enable analog power\n");
			//return -EIO;
			goto _kdCISModulePowerOn_exit_;
		}                    
		// wait power to be stable 
		mdelay(5);

		//For P3 Demo board
		//if(mt_set_gpio_out(GPIO220, GPIO_OUT_ZERO))	printk("[CAMERA LENS] set gpio failed!! \n");
		//For Acer Pcb
		if(mt_set_gpio_out(GPIO228, GPIO_OUT_ZERO))	printk("[CAMERA LENS] set gpio failed!! \n");
	}
    }
    else {//power OFF
	if(pinSetIdx == 1)
	{
		//For P3 Demo board
		//if(mt_set_gpio_mode(GPIO220, GPIO_MODE_00))	printk("[CAMERA LENS] set gpio mode failed!! \n");
		//if(mt_set_gpio_dir(GPIO220, GPIO_DIR_OUT))	printk("[CAMERA LENS] set gpio dir failed!! \n");
		//if(mt_set_gpio_out(GPIO220, GPIO_OUT_ONE))	printk("[CAMERA LENS] set gpio failed!! \n");
		//For Acer Pcb
		if(mt_set_gpio_mode(GPIO228, GPIO_MODE_00))	printk("[CAMERA LENS] set gpio mode failed!! \n");
		if(mt_set_gpio_dir(GPIO228, GPIO_DIR_OUT))	printk("[CAMERA LENS] set gpio dir failed!! \n");
		if(mt_set_gpio_out(GPIO228, GPIO_OUT_ONE))	printk("[CAMERA LENS] set gpio failed!! \n");

		if(TRUE != hwPowerDown(CAMERA_POWER_VCAM_A,mode_name)) {
			PK_DBG("[CAMERA SENSOR] Fail to OFF analog power\n");
			//return -EIO;
			goto _kdCISModulePowerOn_exit_;
		}
		if(TRUE != hwPowerDown(CAMERA_POWER_VCAM_D2,mode_name))
		{
			PK_DBG("[CAMERA SENSOR] Fail to enable digital power\n");
			//return -EIO;
			goto _kdCISModulePowerOn_exit_;
		}                    
	}
    }//

	return 0;

_kdCISModulePowerOn_exit_:
    return -EIO;
}

EXPORT_SYMBOL(kdCISModulePowerOn);



