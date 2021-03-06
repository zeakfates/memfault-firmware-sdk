//! @file
//!
//! Copyright (c) 2019-Present Memfault, Inc.
//! See License.txt for details
//!
//! @brief
//! Command definitions for the minimal shell/console implementation.

#include "memfault_demo_shell_commands.h"

#include "memfault/core/math.h"
#include "memfault/demo/cli.h"

#include <stddef.h>

static const sMemfaultShellCommand s_memfault_shell_commands[] = {
  {"get_core", memfault_demo_cli_cmd_get_core, "Get coredump info"},
  {"clear_core", memfault_demo_cli_cmd_clear_core, "Clear an existing coredump"},
  {"print_chunk", memfault_demo_cli_cmd_print_chunk, "Get next Memfault data chunk to send and print as a curl command"},
  {"crash", memfault_demo_cli_cmd_crash, "Trigger a crash"},

  {"get_device_info", memfault_demo_cli_cmd_get_device_info, "Get device info"},

  {"help", memfault_shell_help_handler, "Lists all commands"},
};

const sMemfaultShellCommand *const g_memfault_shell_commands = s_memfault_shell_commands;
const size_t g_memfault_num_shell_commands = MEMFAULT_ARRAY_SIZE(s_memfault_shell_commands);
