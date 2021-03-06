#pragma once

//! @file
//!
//! Copyright (c) 2019-Present Memfault, Inc.
//! See License.txt for details
//!
//! @brief
//! Internal helper functions that are used when serializing Memfault Event based data
//! A user of the sdk should never have to call these routines directly

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct MemfaultCborEncoder sMemfaultCborEncoder;

bool memfault_serializer_helper_encode_version_info(sMemfaultCborEncoder *encoder);

bool memfault_serializer_helper_encode_uint32_kv_pair(
    sMemfaultCborEncoder *encoder, uint32_t key, uint32_t value);

#ifdef __cplusplus
}
#endif
