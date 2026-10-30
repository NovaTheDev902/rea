/*
 * Bootstrap.dylib role names from verbatim Ghidra C.
 * Proven FUN_* → coruna_* only; all other FUN_* stay as-is.
 * Rebuild: python tools/rebuild_refined_proven.py
 */
#ifndef BOOTSTRAP_NAMES_H
#define BOOTSTRAP_NAMES_H

#define FUN_0000ad8c  coruna_chacha20
#define FUN_00008430  coruna_lzfse_decode
#define FUN_00008b5c  coruna_c2_http
#define FUN_00009398  coruna_c2_json_http
#define FUN_000094b4  coruna_c2_json_body
#define FUN_00009790  coruna_c2_http_client
#define FUN_00009a34  coruna_c2_sprintf
#define FUN_00005dc8  coruna_flush_caches
#define FUN_00007090  coruna_read_product_version
#define FUN_000071fc  coruna_get_platform_serial
#define FUN_000089cc  coruna_iokit_open_service
#define FUN_00008ab8  coruna_is_mobilestore_ua
#define FUN_00009b60  coruna_sysctl_hw_model
#define FUN_00007a98  coruna_plist_from_file
#define FUN_000096f8  coruna_semaphore_create
#define FUN_0000987c  coruna_semaphore_wait_signal
#define FUN_00009cb8  coruna_uname
#define FUN_00008298  coruna_proc_vm_region
#define FUN_0000bb20  coruna_sel_beginbackgroundtask
#define FUN_0000bb40  coruna_sel_endbackgroundtask
#define FUN_00007ba0  coruna_pacia

#endif
