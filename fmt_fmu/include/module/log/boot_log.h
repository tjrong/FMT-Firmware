/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#ifndef __BOOT_LOG_H__
#define __BOOT_LOG_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

uint32_t boot_log_push(const char* content, uint32_t len);
fmt_err boot_log_dump(void);
fmt_err boot_log_init(void);

#ifdef __cplusplus
}
#endif

#endif