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

#ifndef CUST_MATV_H
#define CUST_MATV_H

#include "kal_release.h"
#include "matvctrl.h"

/*
MATV default country
- TV_AFGHANISTAN,
- TV_ARGENTINA,
- TV_AUSTRALIA,
- TV_BRAZIL,
- TV_BURMA,
- TV_CAMBODIA,
- TV_CANADA,
- TV_CHILE,
- TV_CHINA,
- TV_CHINA_HONGKONG,
- TV_CHINA_SHENZHEN,
- TV_EUROPE_EASTERN,
- TV_EUROPE_WESTERN,
- TV_FRANCE,
- TV_FRENCH_COLONIE,
- TV_INDIA,
- TV_INDONESIA,
- TV_IRAN,
- TV_ITALY,
- TV_JAPAN,
- TV_KOREA,
- TV_LAOS,
- TV_MALAYSIA,
- TV_MEXICO,
- TV_NEWZEALAND,
- TV_PAKISTAN,
- TV_PARAGUAY,
- TV_PHILIPPINES,
- TV_PORTUGAL,
- TV_RUSSIA,
- TV_SINGAPORE,
- TV_SOUTHAFRICA,
- TV_SPAIN,
- TV_TAIWAN,
- TV_THAILAND,
- TV_TURKEY,
- TV_UNITED_ARAB_EMIRATES,
- TV_UNITED_KINGDOM,
- TV_USA,
- TV_URUGUAY,
- TV_VENEZUELA,
- TV_VIETNAM,
- TV_IRELAND,
- TV_MOROCCO,
*/

///#define ANALOG_AUDIO

#if 1
/*
 * MATV default channel number
 * (If value = 0, default country and channel select UI are used.)
 * (If value > 0, customized country and channel select UI are used.)
*/
#define MATV_TOATL_CH  0x06

//typedef struct 
//{
//	kal_uint32	freq; //khz
//	kal_uint8	sndsys;	/* reference sv_const.h, TV_AUD_SYS_T ...*/
//	kal_uint8	colsys;	/* reference sv_const.h, SV_CS_PAL_N, SV_CS_PAL,SV_CS_NTSC358...*/
//	kal_uint8	flag;
//} matv_ch_entry;
matv_ch_entry MATV_CH_TABLE[]=
{
    //China 4/5/10/12/44/47
    {77250, SV_PAL_DK_FMMONO, SV_CS_PAL , 1},
    {85250, SV_PAL_DK_FMMONO, SV_CS_PAL , 1},
    {200250, SV_PAL_DK_FMMONO, SV_CS_PAL , 1},
    {216250, SV_PAL_DK_FMMONO, SV_CS_PAL , 1},    
    {759250, SV_PAL_DK_FMMONO, SV_CS_PAL , 1},
    {783250, SV_PAL_DK_FMMONO, SV_CS_PAL , 1},
    {-1, NULL, NULL, NULL}
};
#else
/*
 * MATV default channel number
 * (If value = 0, default country and channel select UI are used.)
 * (If value > 0, customized country and channel select UI are used.)
*/
#define MATV_TOATL_CH  0x03

//typedef struct 
//{
//	kal_uint32	freq; //khz
//	kal_uint8	sndsys;	/* reference sv_const.h, TV_AUD_SYS_T ...*/
//	kal_uint8	colsys;	/* reference sv_const.h, SV_CS_PAL_N, SV_CS_PAL,SV_CS_NTSC358...*/
//	kal_uint8	flag;
//} matv_ch_entry;
matv_ch_entry MATV_CH_TABLE[]=
{
    //Taiwan Ch42/44/46
    {639250, SV_MTS, SV_CS_NTSC358 , 1},
    {651250, SV_MTS, SV_CS_NTSC358 , 1},
    {663250, SV_MTS, SV_CS_NTSC358 , 1},      
    {-1, NULL, NULL, NULL}
};
#endif
#endif /* CUST_FM_H */

