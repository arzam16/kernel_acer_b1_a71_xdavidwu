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

/********************************************************************************************
 *     LEGAL DISCLAIMER
 *
 *     (Header of MediaTek Software/Firmware Release or Documentation)
 *
 *     BY OPENING OR USING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 *     THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") RECEIVED
 *     FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON AN "AS-IS" BASIS
 *     ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED,
 *     INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR
 *     A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY
 *     WHATSOEVER WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 *     INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK
 *     ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 *     NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S SPECIFICATION
 *     OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *
 *     BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH
 *     RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION,
TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
 ************************************************************************************************/
#define LOG_TAG "feature_custom"
//
#include <utils/Errors.h>
#include <cutils/log.h>
//
#define USE_CAMERA_FEATURE_MACRO 1  //define before "camera_feature.h"
#include "camera_feature.h"


/*******************************************************************************
* MACRO Define: Scene Independent
*******************************************************************************/
#define GETFINFO_RAW_MAIN()      \
        _GETFINFO_SCENE_INDEP("[Custom RAW Main]")
#define END_GETFINFO_RAW_MAIN()  \
    _END_GETFINFO_SCENE_INDEP("[Custom RAW Main]")
#define GETFINFO_RAW_SUB()      \
        _GETFINFO_SCENE_INDEP("[Custom RAW Sub]")
#define END_GETFINFO_RAW_SUB()  \
    _END_GETFINFO_SCENE_INDEP("[Custom RAW Sub]")
#define GETFINFO_YUV_MAIN()      \
        _GETFINFO_SCENE_INDEP("[Custom YUV Main]")
#define END_GETFINFO_YUV_MAIN()  \
    _END_GETFINFO_SCENE_INDEP("[Custom YUV Main]")
#define GETFINFO_YUV_SUB()      \
        _GETFINFO_SCENE_INDEP("[Custom YUV Sub]")
#define END_GETFINFO_YUV_SUB()  \
    _END_GETFINFO_SCENE_INDEP("[Custom YUV Sub]")
#define GETFINFO_N3D_YUV_MAIN()      \
        _GETFINFO_SCENE_INDEP("[Custom N3D_YUV Main]")
#define END_GETFINFO_N3D_YUV_MAIN()  \
    _END_GETFINFO_SCENE_INDEP("[Custom N3D_YUV Main]")
#define GETFINFO_B3D_YUV_MAIN()      \
        _GETFINFO_SCENE_INDEP("[Custom B3D_YUV Main]")
#define END_GETFINFO_B3D_YUV_MAIN()  \
    _END_GETFINFO_SCENE_INDEP("[Custom B3D_YUV Main]")


/*******************************************************************************
* MACRO Define: Config Feature
*******************************************************************************/
#define CHECK_FID_SI
#define CONFIG_FEATURE  CONFIG_FEATURE_SI


namespace NSFeature {
namespace NSCustom  {


#include "cfg_ftbl_custom_raw_main.h"
PF_GETFINFO_SCENE_INDEP_T
GetFInfo_RAW_Main()
{
#ifndef CUSTOM_FEATURE_RAW_MAIN
    #define CUSTOM_FEATURE_RAW_MAIN 0
#endif
#if (CUSTOM_FEATURE_RAW_MAIN==0)
    return  NULL;
#else
    return  NSRAW::NSMain::GetFInfo;
#endif
}


#include "cfg_ftbl_custom_raw_sub.h"
PF_GETFINFO_SCENE_INDEP_T
GetFInfo_RAW_Sub()
{
#ifndef CUSTOM_FEATURE_RAW_SUB
    #define CUSTOM_FEATURE_RAW_SUB 0
#endif
#if (CUSTOM_FEATURE_RAW_SUB==0)
    return  NULL;
#else
    return  NSRAW::NSSub::GetFInfo;
#endif
}


#include "cfg_ftbl_custom_yuv_main.h"
PF_GETFINFO_SCENE_INDEP_T
GetFInfo_YUV_Main()
{
#ifndef CUSTOM_FEATURE_YUV_MAIN
    #define CUSTOM_FEATURE_YUV_MAIN 0
#endif
#if (CUSTOM_FEATURE_YUV_MAIN==0)
    return  NULL;
#else
    return  NSYUV::NSMain::GetFInfo;
#endif
}


#include "cfg_ftbl_custom_yuv_sub.h"
PF_GETFINFO_SCENE_INDEP_T
GetFInfo_YUV_Sub()
{
#ifndef CUSTOM_FEATURE_YUV_SUB
    #define CUSTOM_FEATURE_YUV_SUB 0
#endif
#if (CUSTOM_FEATURE_YUV_SUB==0)
    return  NULL;
#else
    return  NSYUV::NSSub::GetFInfo;
#endif
}


#include "cfg_ftbl_custom_n3d_yuv_main.h"
PF_GETFINFO_SCENE_INDEP_T
GetFInfo_N3D_YUV_Main()
{
#ifndef CUSTOM_FEATURE_N3D_YUV_MAIN
    #define CUSTOM_FEATURE_N3D_YUV_MAIN 0
#endif
#if (CUSTOM_FEATURE_N3D_YUV_MAIN==0)
    return  NULL;
#else
    return  NSN3D::NSYUV::NSMain::GetFInfo;
#endif
}

#include "cfg_ftbl_custom_b3d_yuv_main.h"
PF_GETFINFO_SCENE_INDEP_T
GetFInfo_B3D_YUV_Main()
{
#ifndef CUSTOM_FEATURE_B3D_YUV_MAIN
    #define CUSTOM_FEATURE_B3D_YUV_MAIN 0
#endif
#if (CUSTOM_FEATURE_B3D_YUV_MAIN==0)
    return  NULL;
#else
    return  NSB3D::NSYUV::NSMain::GetFInfo;
#endif
}

};  //  namespace NSCustom
};  //  namespace NSFeature

