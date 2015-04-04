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


#ifndef _CFG_BT_FILE_H
#define _CFG_BT_FILE_H


// the record structure define of bt nvram file
#ifdef MTK_COMBO_SUPPORT
typedef struct
{
    unsigned char addr[6];            // BT address
    unsigned char Voice[2];           // Voice setting for SCO connection
    unsigned char Codec[4];           // PCM codec setting
    unsigned char Radio[6];           // RF configuration
    unsigned char Sleep[7];           // Sleep mode configuration
    unsigned char BtFTR[2];           // Other feature setting
    unsigned char TxPWOffset[3];      // TX power channel offset compensation
} ap_nvram_btradio_mt6610_struct;
#else
// MT661x is phased out, current for MT662x
typedef struct
{
    unsigned char addr[6];                   /*0*/
    unsigned char CapId[1];                  /*6*/
    unsigned char LinkKeyType[1];            /*7*/
    unsigned char UintKey[16];               /*8*/
    unsigned char Encryption[3];             /*24*/
    unsigned char PinCodeType[1];            /*27*/
    unsigned char Voice[2];                  /*28*/
    unsigned char Codec[4];                  /*30*/
    unsigned char Radio[6];                  /*34*/
    unsigned char Sleep[7];                  /*40*/
    unsigned char BtFTR[2];                  /*47*/
    unsigned char TxPWOffset[3];             /*49*/
    unsigned char ECLK_SEL[1];               /*52*/
    unsigned char Reserved1[1];              /*53*/
    unsigned char Reserved2[2];              /*54*/
    unsigned char Reserved3[4];              /*56*/
    unsigned char Reserved4[4];              /*60*/
    unsigned char Reserved5[16];             /*64*/
    unsigned char Reserved6[16];             /*80*/
} ap_nvram_btradio_mt6610_struct;
#endif

//the record size and number of bt nvram file
#define CFG_FILE_BT_ADDR_REC_SIZE    sizeof(ap_nvram_btradio_mt6610_struct)
#define CFG_FILE_BT_ADDR_REC_TOTAL   1

#endif


