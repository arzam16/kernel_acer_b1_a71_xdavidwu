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
 
/*
 *
 * (C) Copyright 2008 
 * MediaTek <www.mediatek.com>
 *
 * STK8312 driver for MT6573
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#ifndef STK8312_H
#define STK8312_H 
	 
#include <linux/ioctl.h>
	 
#define STK8312_I2C_SLAVE_ADDR		0x7A 
	 
	 /* STK8312 Register Map  (Please refer to STK8312 Specifications) */

#define STK831X_REG_DEVID			0x0B //use  device id = 0x3A
#define STK831X_REG_MODE    		0x07 //use
#define STK831X_REG_SRST    		0x04 
#define STK831X_REG_SR	   		0x08 
#define STK831X_REG_OFSX			0x0C //use
#define STK831X_REG_OFSY			0x0D //use
#define STK831X_REG_OFSZ			0x0E //use
#define STK831X_REG_XYZ_DATA_CFG		0x13 //use
#define STK831X_REG_INT    		0x06 //use
#define STK831X_REG_RESET    		0x20 //use
#define STK831X_REG_DATAX0			0x00 //use


//end define register


#define STK831X_FIXED_DEVID			0x58 //use
	 
#define STK831X_STANDBY_MODE 	0x00 //use	 
#define STK831X_ACTIVE_MODE		0x01 //use	
#define STK831X_MODE_MASK		0x07 //use	
	 
#define STK831X_RANGE_1_5G			0x00 //use
#define STK831X_RANGE_6G			0x01 //use
#define STK831X_RANGE_16G			0x02 //use

#define STK831X_6BIT_RES	        0x00
#define STK831X_8BIT_RES	        0x01	// 0x02

#define STK831X_SUCCESS						0
#define STK831X_ERR_I2C						-1
#define STK831X_ERR_STATUS					-3
#define STK831X_ERR_SETUP_FAILURE			-4
#define STK831X_ERR_GETGSENSORDATA			-5
#define STK831X_ERR_IDENTIFICATION			-6
	 
	 
	 
#define STK831X_BUFSIZE				256
const static int STK831X_SAMPLE_TIME[6] = {2500, 5000, 10000, 20000, 40000, 80000};
	 
#endif

