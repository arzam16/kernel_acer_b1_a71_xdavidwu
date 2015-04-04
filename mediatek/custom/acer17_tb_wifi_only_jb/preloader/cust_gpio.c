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

#include <mt6577.h>
#include <mt6577_typedefs.h>
#include <mt6577_gpio.h>
#include <mt6577_key.h>
#include <mtk_timer.h>

void mt6577_gpio_init(void)
{
    /* KCOL0 ~ KCOL7: input + pull enable + pull up */
    mt_set_gpio_mode(GPIO42, GPIO_MODE_01);
    mt_set_gpio_mode(GPIO41, GPIO_MODE_01);
    mt_set_gpio_mode(GPIO40, GPIO_MODE_01);
    mt_set_gpio_mode(GPIO39, GPIO_MODE_01);
    mt_set_gpio_mode(GPIO38, GPIO_MODE_01);
    mt_set_gpio_mode(GPIO37, GPIO_MODE_01);
    mt_set_gpio_mode(GPIO36, GPIO_MODE_01);
    mt_set_gpio_mode(GPIO35, GPIO_MODE_01);

    mt_set_gpio_dir(GPIO42, GPIO_DIR_IN);
    mt_set_gpio_dir(GPIO41, GPIO_DIR_IN);
    mt_set_gpio_dir(GPIO40, GPIO_DIR_IN);
    mt_set_gpio_dir(GPIO39, GPIO_DIR_IN);
    mt_set_gpio_dir(GPIO38, GPIO_DIR_IN);
    mt_set_gpio_dir(GPIO37, GPIO_DIR_IN);
    mt_set_gpio_dir(GPIO36, GPIO_DIR_IN);
    mt_set_gpio_dir(GPIO35, GPIO_DIR_IN);

    mt_set_gpio_pull_enable(GPIO42, GPIO_PULL_ENABLE);
    mt_set_gpio_pull_enable(GPIO41, GPIO_PULL_ENABLE);
    mt_set_gpio_pull_enable(GPIO40, GPIO_PULL_ENABLE);
    mt_set_gpio_pull_enable(GPIO39, GPIO_PULL_ENABLE);
    mt_set_gpio_pull_enable(GPIO38, GPIO_PULL_ENABLE);
    mt_set_gpio_pull_enable(GPIO37, GPIO_PULL_ENABLE);
    mt_set_gpio_pull_enable(GPIO36, GPIO_PULL_ENABLE);
    mt_set_gpio_pull_enable(GPIO35, GPIO_PULL_ENABLE);

    mt_set_gpio_pull_select(GPIO42, GPIO_PULL_UP);
    mt_set_gpio_pull_select(GPIO41, GPIO_PULL_UP);
    mt_set_gpio_pull_select(GPIO40, GPIO_PULL_UP);
    mt_set_gpio_pull_select(GPIO39, GPIO_PULL_UP);
    mt_set_gpio_pull_select(GPIO38, GPIO_PULL_UP);
    mt_set_gpio_pull_select(GPIO37, GPIO_PULL_UP);
    mt_set_gpio_pull_select(GPIO36, GPIO_PULL_UP);
    mt_set_gpio_pull_select(GPIO35, GPIO_PULL_UP);

    /* KROW0 ~ KROW7: output + pull disable + pull down */
    mt_set_gpio_mode(GPIO50, GPIO_MODE_01);
    mt_set_gpio_mode(GPIO49, GPIO_MODE_01);
    mt_set_gpio_mode(GPIO48, GPIO_MODE_01);
    mt_set_gpio_mode(GPIO47, GPIO_MODE_01);
    mt_set_gpio_mode(GPIO46, GPIO_MODE_01);
    mt_set_gpio_mode(GPIO45, GPIO_MODE_01);
    mt_set_gpio_mode(GPIO44, GPIO_MODE_01);
    mt_set_gpio_mode(GPIO43, GPIO_MODE_01);

    mt_set_gpio_dir(GPIO50, GPIO_DIR_OUT);
    mt_set_gpio_dir(GPIO49, GPIO_DIR_OUT);
    mt_set_gpio_dir(GPIO48, GPIO_DIR_OUT);
    mt_set_gpio_dir(GPIO47, GPIO_DIR_OUT);
    mt_set_gpio_dir(GPIO46, GPIO_DIR_OUT);
    mt_set_gpio_dir(GPIO45, GPIO_DIR_OUT);
    mt_set_gpio_dir(GPIO44, GPIO_DIR_OUT);
    mt_set_gpio_dir(GPIO43, GPIO_DIR_OUT);

    mt_set_gpio_pull_enable(GPIO50, GPIO_PULL_DISABLE);
    mt_set_gpio_pull_enable(GPIO49, GPIO_PULL_DISABLE);
    mt_set_gpio_pull_enable(GPIO48, GPIO_PULL_DISABLE);
    mt_set_gpio_pull_enable(GPIO47, GPIO_PULL_DISABLE);
    mt_set_gpio_pull_enable(GPIO46, GPIO_PULL_DISABLE);
    mt_set_gpio_pull_enable(GPIO45, GPIO_PULL_DISABLE);
    mt_set_gpio_pull_enable(GPIO44, GPIO_PULL_DISABLE);
    mt_set_gpio_pull_enable(GPIO43, GPIO_PULL_DISABLE);

    mt_set_gpio_pull_select(GPIO50, GPIO_PULL_DOWN);
    mt_set_gpio_pull_select(GPIO49, GPIO_PULL_DOWN);
    mt_set_gpio_pull_select(GPIO48, GPIO_PULL_DOWN);
    mt_set_gpio_pull_select(GPIO47, GPIO_PULL_DOWN);
    mt_set_gpio_pull_select(GPIO46, GPIO_PULL_DOWN);
    mt_set_gpio_pull_select(GPIO45, GPIO_PULL_DOWN);
    mt_set_gpio_pull_select(GPIO44, GPIO_PULL_DOWN);
    mt_set_gpio_pull_select(GPIO43, GPIO_PULL_DOWN);

    /* set keypad debounce time and wait for stable state */
    DRV_WriteReg16(KP_DEBOUNCE, 0x400);
    mdelay(33);     /* delay 33 ms */
}
