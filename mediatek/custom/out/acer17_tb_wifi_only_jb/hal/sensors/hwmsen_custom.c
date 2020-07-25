/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
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
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <hardware/sensors.h>
#include <linux/hwmsensor.h>
#include "hwmsen_custom.h"

struct sensor_t sSensorList[MAX_NUM_SENSORS] = 
{
/*    
	{ 
		.name       = "AMI304 Orientation sensor",
		.vendor     = "Aichi Steel",
		.version    = 1,
		.handle     = ID_ORIENTATION,
		.type       = SENSOR_TYPE_ORIENTATION,
		.maxRange   = 360.0f,
		.resolution = 1.0f,
		.power      = 0.25f,
		.reserved   = {}
	},
*/
/*
	{ 
		.name       = "AMI304 3-axis Magnetic Field sensor",
		.vendor     = "Aichi Steel",
		.version    = 1,
		.handle     = ID_MAGNETIC,
		.type       = SENSOR_TYPE_MAGNETIC_FIELD,
		.maxRange   = 600.0f,
		.resolution = 0.0016667f,
		.power      = 0.25f,
		.reserved   = {}
	}, 
*/
	
	{  
		.name       = "mc3210 3-axis Accelerometer",
		.vendor     = "mCube",
		.version    = 1,
		.handle     = ID_ACCELEROMETER,
		.type       = SENSOR_TYPE_ACCELEROMETER,
		.maxRange   = 32.0f,
		.resolution = 4.0f/1024.0f,
		.power      = 130.0f/1000.0f,
		.reserved   = {}
	},        
/*
	{ 
		.name       = "CM3623 Proximity Sensor",
		.vendor     = "Capella",
		.version    = 1,
		.handle     = ID_PROXIMITY,
		.type       = SENSOR_TYPE_PROXIMITY,
		.maxRange   = 1.00f,
		.resolution = 1.0f,
		.power      = 0.13f,
		.reserved   = {}
	},
*/
/*
	{ 
		.name       = "CM3623 Light Sensor",
		.vendor     = "Capella",
		.version    = 1,
		.handle     = ID_LIGHT,
		.type       = SENSOR_TYPE_LIGHT,
		.maxRange   = 10240.0f,
		.resolution = 1.0f,
		.power      = 0.13f,
		.reserved   = {}
	},
*/
/*	
	{ 
		.name       = "MPU3050c gyroscope Sensor",
		.vendor     = "Invensensor",
		.version    = 1,
		.handle     = ID_GYROSCOPE,
		.type       = SENSOR_TYPE_GYROSCOPE,
		.maxRange   = 34.91f,
		.resolution = 0.0107f,
		.power      = 6.1f,
		.reserved   = {}
	},
*/	
};

struct sensor_t sGsensorList1[MAX_NUM_SENSORS] =
{
       {
               .name       = "mc32x0 3-axis Accelerometer",
               .vendor     = "mCube",
               .version    = 1,
               .handle     = ID_ACCELEROMETER,
               .type       = SENSOR_TYPE_ACCELEROMETER,
               .maxRange   = 32.0f,
               .resolution = 4.0f/1024.0f,
               .power      = 130.0f/1000.0f,
               .reserved   = {}
        },
};

struct sensor_t sGsensorList2[MAX_NUM_SENSORS] =
{
        {
               .name       = "kxtik1004 3-axis Accelerometer",
               .vendor     = "kionix",
               .version    = 1,
               .handle     = ID_ACCELEROMETER,
               .type       = SENSOR_TYPE_ACCELEROMETER,
               .maxRange   = 32.0f,
               .resolution = 4.0f/4096.0f,
               .power      = 100.0f/1000.0f,
               .reserved   = {}
        },

};

struct sensor_t sGsensorList3[MAX_NUM_SENSORS] =
{
        {
               .name       = "STK831X 3-axis Accelerometer",
               .vendor     = "sitronix",
               .version    = 1,
               .handle     = ID_ACCELEROMETER,
               .type       = SENSOR_TYPE_ACCELEROMETER,
               .maxRange   = 19.62f,
               .resolution = 4.0f/1024.0f,
               .power      = 149.0f/1000.0f,
               .reserved   = {}
        },

};
