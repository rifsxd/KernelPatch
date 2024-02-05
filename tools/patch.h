/* SPDX-License-Identifier: GPL-2.0-or-later */
/* 
 * Copyright (C) 2024 bmax121. All Rights Reserved.
 */

#ifndef _KP_TOOL_PATCH_H_
#define _KP_TOOL_PATCH_H_

#include <stdint.h>
#include <string.h>

#include "preset.h"
#include "image.h"

#define INFO_KERNEL_IMG_SESSION "[kernel]"
#define INFO_KP_IMG_SESSION "[kpimg]"
#define INFO_ADDITIONAL_SESSION "[additional]"
#define INFO_EXTRA_SESSION "[extra]"
#define INFO_EXTRA_SESSION_N "[extra %d]"

#define EXTRA_ITEM_MAX_NUM 32

typedef struct
{
    const char *kimg;
    int kimg_len;
    const char *banner;
    int ori_kimg_len;
    kernel_info_t kinfo;
    preset_t *preset;
    int embed_item_num;
    patch_extra_item_t *embed_item[EXTRA_ITEM_MAX_NUM];
} patched_kimg_t;

preset_t *get_preset(const char *kimg, int kimg_len);

uint32_t get_kpimg_version(const char *kpimg_path);
int patch_update_img(const char *kimg_path, const char *kpimg_path, const char *out_path, const char *superkey,
                     const char *kpatch_path, const char **embed_kpm_path, const char **embed_kpm_args,
                     const char **detach_kpm_names, const char **additional);
int unpatch_img(const char *kimg_path, const char *out_path);
int reset_key(const char *kimg_path, const char *out_path, const char *key);
int dump_kallsym(const char *kimg_path);

int print_kp_image_info_path(const char *kpimg_path);
int print_image_patch_info(patched_kimg_t *pimg);
int print_image_patch_info_path(const char *kimg_path);

#endif
