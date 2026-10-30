/*
 * Implant FUN_* role names from verbatim Ghidra C.
 * Proven FUN_* → coruna_* only; all other FUN_* stay as-is.
 * Rebuild: python lab/scripts/rebuild_refined_proven.py
 */
#ifndef NAMES_H
#define NAMES_H

#define FUN_0000f594  coruna_cfhttp_get_post
#define FUN_0000fd2c  coruna_c2_http_json
#define FUN_0000fe28  coruna_c2_json_body
#define FUN_0000fed4  coruna_cfhttp_stream_client
#define FUN_0000ffdc  coruna_vsnprintf_alloc
#define FUN_0000efb0  coruna_webbookmarks_delete
#define FUN_0000e59c  coruna_resolve_asl_oslog
#define FUN_0000e8f8  coruna_asl_vlog_hook
#define FUN_0000e954  coruna_asl_log_hook
#define FUN_0000f154  coruna_lzfse_decode
#define FUN_0000ecf8  coruna_macho_find_section
#define FUN_000120a8  coruna_parse_xnu_release
#define FUN_00012f04  coruna_check_softwareupdate
#define FUN_000130fc  coruna_get_platform_serial
#define FUN_0001c000  coruna_is_asl_symbol
#define FUN_00021c1c  coruna_bks_app_state
#define FUN_0000a308  coruna_log_msg
#define FUN_0000a060  coruna_cleanup_crash_paths
#define FUN_00019384  coruna_lookup_export
#define FUN_0001da8c  coruna_init_libunwind
#define FUN_0001f258  coruna_find_libunwind_image
#define FUN_0001fa0c  coruna_hook_libunwind_bss
#define FUN_00024b78  coruna_apply_iosurface_entitlement
#define FUN_00020024  coruna_run_end_last
#define FUN_00011850  coruna_chdir_tmp
#define FUN_00015f44  coruna_objc_flush_caches
#define FUN_000187e4  coruna_load_libobjc
#define FUN_00023e84  coruna_sysctl_proc_cputype
#define FUN_000100e8  coruna_flush_caches
#define FUN_0001302c  coruna_host_get_special_port
#define FUN_00018598  coruna_dlerror
#define FUN_0001bef4  coruna_vasprintf
#define FUN_0002105c  coruna_proc_pidpath
#define FUN_00020b58  coruna_realpath
#define FUN_000234a4  coruna_srandomdev
#define FUN_000237ec  coruna_port_get_refs
#define FUN_00023b4c  coruna_port_kernel_object
#define FUN_00024914  coruna_thread_create_resume
#define FUN_00025ce4  coruna_rwlock_destroy
#define FUN_00025da4  coruna_rwlock_init
#define FUN_000168d4  coruna_mutex_destroy
#define FUN_0001711c  coruna_vm_region_recurse
#define FUN_00017a68  coruna_mlock_range
#define FUN_000207b0  coruna_set_priority
#define FUN_0000de74  coruna_resolve_pthread_create
#define FUN_00016a40  coruna_objc_nsobject_pair
#define FUN_00015dfc  coruna_find_data_dirty
#define FUN_0001705c  coruna_find_objc_methlist
#define FUN_00012524  coruna_run_startm
#define FUN_00012b6c  coruna_run_starti
#define FUN_0001dde8  coruna_reallocf
#define FUN_00026900  coruna_sel_urlwithstring
#define FUN_00026920  coruna_sel_allprofileidentifiers
#define FUN_00026940  coruna_sel_deletesafariwebsitedatarecord
#define FUN_00026960  coruna_sel_ephemeraltabgroupmanager
#define FUN_00026980  coruna_sel_host
#define FUN_000269a0  coruna_sel_stringwithcstring_encoding
#define FUN_000269c0  coruna_sel_websitedatarecordwithdomain
#define FUN_000269e0  coruna_sel_websitedatarecordwithdomain_profile
#define FUN_0001f6d4  coruna_hook_strcmp
#define FUN_0001ac0c  coruna_dlopen_rpath
#define FUN_0001c0cc  coruna_init_os_log
#define FUN_0001a54c  coruna_load_libcache
#define FUN_00023a90  coruna_task_exc_guard
#define FUN_00021ae8  coruna_parse_xnu_version
#define FUN_00024458  coruna_task_dyld_info
#define FUN_00008e84  coruna_run_startx
#define FUN_00010278  coruna_chmod_dir_walk
#define FUN_000159dc  coruna_check_objc_section
#define FUN_000107ec  coruna_load_driver
#define FUN_000094e8  coruna_startl_thread
#define FUN_00006000  coruna_write
#define FUN_0000601c  coruna_open
#define FUN_00006038  coruna_close
#define FUN_00006054  coruna_getpid
#define FUN_00006070  coruna_ptrace
#define FUN_0000608c  coruna_munmap
#define FUN_000060a8  coruna_mprotect
#define FUN_000060c4  coruna_csops
#define FUN_000060e0  coruna_stat
#define FUN_000060fc  coruna_fstat
#define FUN_00006118  coruna_mmap
#define FUN_00006134  coruna_mlock
#define FUN_00006150  coruna_munlock
#define FUN_0000616c  coruna_shared_region_check_np
#define FUN_00006188  coruna_pacia
#define FUN_00006198  coruna_pacib
#define FUN_00018358  coruna_readclass_from_image

#endif
