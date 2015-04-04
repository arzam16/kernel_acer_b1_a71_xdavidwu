/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

#include <linux/module.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/cdev.h>
#include <linux/mm.h>
#include <asm/io.h>


/***************************************************************************** 
* MODULE DEFINITION 
*****************************************************************************/

#define MODULE_NAME	    "[devinfo]"
#define DEV_NAME        "devmap"
#define MAJOR_DEV_NUM	196


static struct cdev devinfo_cdev;
static dev_t devinfo_dev;
static int dev_open(struct inode *inode, struct file *filp);
static int dev_release(struct inode *inode, struct file *filp);
static int dev_mmap(struct file *filp, struct vm_area_struct *vma);

static struct file_operations mmap_fops = {        
    .open = dev_open,        
    .release = dev_release,        
    .mmap = dev_mmap,        
    .owner = THIS_MODULE,
    };


static int dev_open(struct inode *inode, struct file *filp){
    return 0;
}

static int dev_release(struct inode *inode, struct file *filp){        
    return 0;
}


/******************************************************************************
 * dev_mmap
 * 
 * DESCRIPTION: 
 *   mmap implementation for devinfo 
 * 
 * PARAMETERS: 
 *   filp: file pointer
 *   vma:virtual address range used to access the device
 * 
 * RETURNS: 
 *   0 for success.
 * 
 * NOTES: 
 *   None
 * 
 ******************************************************************************/
static int dev_mmap(struct file *filp, struct vm_area_struct *vma){
    int ret;
    long length = vma->vm_end - vma->vm_start;

    vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
    
    if ((ret = remap_pfn_range(vma,
                               vma->vm_start,
                               vma->vm_pgoff,
                               length,
                               vma->vm_page_prot)) < 0) {
        printk("[devinfo] map failed, ret:%d\n", ret);
        return ret;
    }
    return 0;
}



/******************************************************************************
 * devinfo_init
 * 
 * DESCRIPTION: 
 *   Init the device driver ! 
 * 
 * PARAMETERS: 
 *   None
 * 
 * RETURNS: 
 *   0 for success
 * 
 * NOTES: 
 *   None
 * 
 ******************************************************************************/
static int __init devinfo_init(void)
{
    int ret = 0;
    devinfo_dev = MKDEV(MAJOR_DEV_NUM, 0);

	printk("[devinfo] init\n");    

	ret = register_chrdev_region(devinfo_dev, 1, DEV_NAME );
	if (ret)    
	{        
	    printk("[%s] register device failed, ret:%d\n", MODULE_NAME, ret);
	    return ret;
    }

	/* initialize the device structure and register the device  */
    cdev_init(&devinfo_cdev, &mmap_fops);
    devinfo_cdev.owner = THIS_MODULE;
    if ((ret = cdev_add(&devinfo_cdev, devinfo_dev  , 1)) < 0) 
    {
        printk("[%s] could not allocate chrdev for the device, ret:%d\n", MODULE_NAME, ret);
        return ret;
    }
		
	return 0;
}

/******************************************************************************
 * devinfo_exit
 * 
 * DESCRIPTION: 
 *   Free the device driver ! 
 * 
 * PARAMETERS: 
 *   None
 * 
 * RETURNS: 
 *   None
 * 
 * NOTES: 
 *   None
 * 
 ******************************************************************************/
static void __exit devinfo_exit(void)
{
	cdev_del(&devinfo_cdev);        
	unregister_chrdev_region(devinfo_dev, 1);
}

module_init(devinfo_init);
module_exit(devinfo_exit);
