# Copyright Statement:
#
# This software/firmware and related documentation ("MediaTek Software") are
# protected under relevant copyright laws. The information contained herein
# is confidential and proprietary to MediaTek Inc. and/or its licensors.
# Without the prior written permission of MediaTek inc. and/or its licensors,
# any reproduction, modification, use or disclosure of MediaTek Software,
# and information contained herein, in whole or in part, shall be strictly prohibited.

# MediaTek Inc. (C) 2010. All rights reserved.
#
# BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
# THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
# RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
# AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
# NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
# SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
# SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
# THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
# THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
# CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
# SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
# STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
# CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
# AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
# OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
# MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
# The following software/firmware and/or related documentation ("MediaTek Software")
# have been modified by MediaTek Inc. All revisions are subject to any receiver's
# applicable license agreements with MediaTek Inc.


LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

TARGET_PROVIDES_INIT_RC := true

# add your file here (as target) and place the file in this directory
PRODUCT_COPY_FILES += $(LOCAL_PATH)/mtk-kpd.kl:system/usr/keylayout/mtk-kpd.kl \
                      $(LOCAL_PATH)/mtk-kpd.kcm:system/usr/keychars/mtk-kpd.kcm \
                      $(LOCAL_PATH)/init.rc:root/init.rc \
                      $(LOCAL_PATH)/init.usb.rc:root/init.usb.rc \
                      $(LOCAL_PATH)/init.xlog.rc:root/init.xlog.rc \
                      $(LOCAL_PATH)/vold.fstab:system/etc/vold.fstab \
                      $(LOCAL_PATH)/vold.fstab.nand:system/etc/vold.fstab.nand \
                      $(LOCAL_PATH)/player.cfg:system/etc/player.cfg \
                      $(LOCAL_PATH)/mtk_omx_core.cfg:system/etc/mtk_omx_core.cfg \
                      $(LOCAL_PATH)/media_codecs.xml:system/etc/media_codecs.xml \
                      $(LOCAL_PATH)/advanced_meta_init.rc:root/advanced_meta_init.rc \
                      $(LOCAL_PATH)/meta_init.rc:root/meta_init.rc \
                      $(LOCAL_PATH)/mpeg4_venc_parameter.cfg:system/etc/mpeg4_venc_parameter.cfg \
                      $(LOCAL_PATH)/audio_policy.conf:system/etc/audio_policy.conf \
                      $(LOCAL_PATH)/ACCDET.kl:system/usr/keylayout/ACCDET.kl \
                      $(LOCAL_PATH)/fstab:root/fstab


_init_project_rc := $(MTK_ROOT_CONFIG_OUT)/init.project.rc
ifneq ($(wildcard $(_init_project_rc)),)
PRODUCT_COPY_FILES += $(_init_project_rc):root/init.project.rc
endif

_meta_init_project_rc := $(MTK_ROOT_CONFIG_OUT)/meta_init.project.rc
ifneq ($(wildcard $(_meta_init_project_rc)),)
PRODUCT_COPY_FILES += $(_meta_init_project_rc):root/meta_init.project.rc
endif

_advanced_meta_init_project_rc := $(MTK_ROOT_CONFIG_OUT)/advanced_meta_init.project.rc
ifneq ($(wildcard $(_advanced_meta_init_project_rc)),)
PRODUCT_COPY_FILES += $(_advanced_meta_init_project_rc):root/advanced_meta_init.project.rc
endif

PRODUCT_COPY_FILES += $(strip \
                        $(foreach file,$(call wildcard2, $(LOCAL_PATH)/*.xml), \
                          $(addprefix $(LOCAL_PATH)/$(notdir $(file)):system/etc/permissions/,$(notdir $(file))) \
                         ) \
                       )

ifeq ($(HAVE_AEE_FEATURE),yes)
ifeq ($(PARTIAL_BUILD),true)
PRODUCT_COPY_FILES += $(LOCAL_PATH)/init.aee.customer.rc:root/init.aee.customer.rc
else
PRODUCT_COPY_FILES += $(LOCAL_PATH)/init.aee.mtk.rc:root/init.aee.mtk.rc
endif
endif

ifeq ($(strip $(HAVE_SRSAUDIOEFFECT_FEATURE)),yes)
  PRODUCT_COPY_FILES += $(LOCAL_PATH)/srs_processing.cfg:system/data/srs_processing.cfg
endif

ifeq ($(MTK_SHARED_SDCARD),yes)
  PRODUCT_COPY_FILES += $(LOCAL_PATH)/init.sdcard.rc:root/init.sdcard.rc
endif

include $(CLEAR_VARS)
LOCAL_SRC_FILES := mtk-kpd.kcm
LOCAL_MODULE_TAGS := user
include $(BUILD_KEY_CHAR_MAP)

$(call config-custom-folder,modem:modem)
##### INSTALL MODEM FIRMWARE #####

include $(CLEAR_VARS)
LOCAL_MODULE := modem.img
LOCAL_MODULE_TAGS := user
LOCAL_MODULE_CLASS := ETC
LOCAL_MODULE_PATH := $(TARGET_OUT_ETC)/firmware
LOCAL_SRC_FILES := modem/$(LOCAL_MODULE)
include $(BUILD_PREBUILT)

##################################
##INSTALL MODEM DATABASE##
ifeq ($(strip $(MTK_INCLUDE_MODEM_DB_IN_IMAGE)), yes)
  ifeq ($(filter generic banyan_addon,$(PROJECT)),)
    MD_DATABASE_FILE := $(if $(wildcard mediatek/custom/common/modem/$(strip $(CUSTOM_MODEM))/BPLGUInfoCustomAppSrcP_*), $(wildcard mediatek/custom/common/modem/$(strip $(CUSTOM_MODEM))/BPLGUInfoCustomAppSrcP_*), $(wildcard mediatek/custom/common/modem/$(strip $(CUSTOM_MODEM))/BPLGUInfoCustomApp_*))
    ifneq ($(words $(MD_DATABASE_FILE)),1)
      $(error More than one modem database file: $(MD_DATABASE_FILE)!!)
    endif
    MD_DATABASE_FILENAME := $(notdir $(MD_DATABASE_FILE))
    PRODUCT_COPY_FILES += $(strip $(MD_DATABASE_FILE)):system/etc/mddb/$(strip $(MD_DATABASE_FILENAME))
  endif
endif
##########################
## INSTALL catcher_filter.bin ##

ifeq ($(MTK_MDLOGGER_SUPPORT),yes)
include $(CLEAR_VARS)
LOCAL_MODULE := catcher_filter.bin
LOCAL_MODULE_TAGS := user
LOCAL_MODULE_CLASS := ETC
LOCAL_MODULE_PATH := $(TARGET_OUT_ETC)/firmware
LOCAL_SRC_FILES := modem/catcher_filter.bin
include $(BUILD_PREBUILT)
endif

## Install ext catcher_filter.bin ##

ifeq ($(MTK_DT_SUPPORT),yes)
ifneq ($(EVDO_DT_SUPPORT),yes)
include $(CLEAR_VARS)
LOCAL_MODULE := catcher_filter_ext.bin
LOCAL_MODULE_TAGS := user
LOCAL_MODULE_CLASS := ETC
LOCAL_MODULE_PATH := $(TARGET_OUT_ETC)/firmware
LOCAL_SRC_FILES := modem/ExtModem/catcher_filter.bin
include $(BUILD_PREBUILT)
endif
endif

#################################
####INSTALL EXT MODEM DATABASE###
ifeq ($(strip $(MTK_INCLUDE_EXT_MODEM_DB_IN_IMAGE)), yes)
  ifeq ($(filter generic banyan_addon,$(PROJECT)),)
    MD_DATABASE_FILE := $(if $(wildcard mediatek/custom/common/modem/$(strip $(CUSTOM_MODEM))/ExtModem/BPLGUInfoCustomAppSrcP_*), $(wildcard mediatek/custom/common/modem/$(strip $(CUSTOM_MODEM))/ExtModem/BPLGUInfoCustomAppSrcP_*), $(wildcard mediatek/custom/common/modem/$(strip $(CUSTOM_MODEM))/ExtModem/BPLGUInfoCustomApp_*))
    ifneq ($(words $(MD_DATABASE_FILE)),1)
      $(error More than one modem database file: $(MD_DATABASE_FILE)!!)
    endif
    MD_DATABASE_FILENAME := $(notdir $(MD_DATABASE_FILE))
    PRODUCT_COPY_FILES += $(strip $(MD_DATABASE_FILE)):system/etc/extmddb/$(strip $(MD_DATABASE_FILENAME))
  endif
endif
#################################
##### INSTALL DSP FIRMWARE #####

include $(CLEAR_VARS)
LOCAL_MODULE := DSP_ROM
LOCAL_MODULE_TAGS := user
LOCAL_MODULE_CLASS := ETC
LOCAL_MODULE_PATH := $(TARGET_OUT_ETC)/firmware
LOCAL_SRC_FILES := modem/$(LOCAL_MODULE)
include $(BUILD_PREBUILT)

PRODUCT_COPY_FILES += $(LOCAL_PATH)/modem/DSP_BL:DSP_BL
##################################

##### INSTALL mtofn.idc ##########

ifeq ($(CUSTOM_KERNEL_OFN),ofn1090)
PRODUCT_COPY_FILES += $(LOCAL_PATH)/mtofn.idc:system/usr/idc/mtofn.idc
endif

##################################

##### INSTALL ht120.mtc ##########

_ht120_mtc := $(MTK_ROOT_CONFIG_OUT)/configs/ht120.mtc
ifneq ($(wildcard $(_ht120_mtc)),)
PRODUCT_COPY_FILES += $(_ht120_mtc):system/etc/.tp/.ht120.mtc
endif

##################################

##### INSTALL thermal.conf ##########

_thermal_conf := $(MTK_ROOT_CONFIG_OUT)/configs/thermal.conf
ifneq ($(wildcard $(_thermal_conf)),)
PRODUCT_COPY_FILES += $(_thermal_conf):system/etc/.tp/thermal.conf
endif

##################################

##### INSTALL thermal.off.conf ##########

_thermal_off_conf := $(MTK_ROOT_CONFIG_OUT)/configs/thermal.off.conf
ifneq ($(wildcard $(_thermal_off_conf)),)
PRODUCT_COPY_FILES += $(_thermal_off_conf):system/etc/.tp/thermal.off.conf
endif

##################################

##### INSTALL local.prop #########
ifeq ($(strip $(MTK_BSP_PACKAGE)),yes)
ifeq ($(TARGET_BUILD_VARIANT),eng)
PRODUCT_COPY_FILES += $(LOCAL_PATH)/local.prop:data/local.prop
endif
endif
##################################
