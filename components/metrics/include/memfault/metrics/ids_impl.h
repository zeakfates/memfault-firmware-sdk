#pragma once

//! @file
//!
//! Copyright (c) 2019-Present Memfault, Inc.
//! See License.txt for details
//!
//! NOTE: The internals of the metric APIs make use of "X-Macros" to enable more flexibility
//! improving and extending the internal implementation without impacting the externally facing API

#ifdef __cplusplus
extern "C" {
#endif

//! Generate extern const char * declarations for all IDs (used in key names):
#define MEMFAULT_METRICS_KEY_DEFINE(key_name, value_type) \
extern const char * const g_memfault_metrics_id_##key_name;
#include "memfault_metrics_heartbeat_config.def"
#undef MEMFAULT_METRICS_KEY_DEFINE

#define _MEMFAULT_METRICS_KEY_DEFINE(key_name, value_type) \
  MEMFAULT_STATIC_ASSERT(false, "MEMFAULT_METRICS_KEY_DEFINE should only be used in memfault_metrics_heartbeat_config.def!")

//! NOTE: Currently, there's only an implementation that uses constant C strings for keys.
//!
//! A future implementation may use smaller representations (for example, an index into an off-line
//! string lookup table) to reduce code size as well as reduce the size of packets that go over the
//! wire.
//!
//! Access to a key should _always_ be made via the MEMFAULT_METRICS_KEY() macro to ensure source
//! code compatibility with future APIs updates
//!
//! The struct wrapper does not have any function, except for preventing one from passing a C
//! string to the API:
typedef struct {
  const char *_impl;  // Please refrain from using / relying on this directly!
} MemfaultMetricId;

#define _MEMFAULT_METRICS_ID_CREATE(id) \
  ((MemfaultMetricId) { MEMFAULT_EXPAND_AND_QUOTE(id) })

#define _MEMFAULT_METRICS_ID(id) \
  ((MemfaultMetricId) { ._impl = g_memfault_metrics_id_##id })

#ifdef __cplusplus
}
#endif
