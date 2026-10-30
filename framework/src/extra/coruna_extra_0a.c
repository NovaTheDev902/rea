/*
 * Coruna type-0x0a extra dylib — trace cleanup / sandbox utilities
 *
 * Purges caches, manipulates plist state, and hosts SVC syscall islands.
 * Entry: _startsc (Mach-O export).
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
typedef struct { uint64_t q0; uint64_t q1; } coruna_svc_regpack_t;




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



/* Extra 0x0a runtime constants (from Mach-O image) */
static uint64_t k_extra_mmap_anon_fd;
static uint64_t k_extra_ctx_slot_primary;
static uint64_t k_extra_ctx_slot_secondary;
static uint64_t k_extra_ctx_slot_tertiary;
static uint64_t k_extra_ctx_field_u32;
static uint64_t k_extra_ctx_field_u64;
static uint8_t k_extra_svc_flag_a = 0x00;
static uint8_t k_extra_svc_flag_b = 0x00;
static uint8_t k_extra_svc_flag_c = 0x00;
static uint8_t k_extra_svc_flag_d = 0x14;
static uint64_t k_extra_jsc_dispatch_word = 0x9000000058000000ULL;
static uint64_t k_extra_jsc_dispatch_mask = 0x000000a000000090ULL;
static uint64_t k_extra_jsc_callback_ctx = 0x0000000000000000ULL;
static uint64_t k_extra_jsc_callback_arg = 0x0000000000000000ULL;
static uint64_t k_extra_jsc_callback_fn = 0x0000000000000000ULL;
static uint64_t k_extra_cpu_cap_threshold = 0x4090ab3333333333ULL;
static uint64_t k_extra_loader_block_template = 0xf2982188b2704fe8ULL;
static uint64_t k_extra_loader_map_prot = 0x0000004000000000ULL;
static uint64_t k_extra_loader_region_hint = 0x52b2800952b28014ULL;
static uint64_t k_extra_loader_size_hint = 0x0000000052b28008ULL;
static uint64_t k_extra_icache_mode;
static uint64_t k_extra_md5_init_state = 0x3320646e61707865ULL;
static uint64_t k_extra_dsb_ctrl_a;
static uint64_t k_extra_dsb_ctrl_b;
static void *k_extra_sandbox_check_no_report_slot = (void *)0x400800000000000eULL;
static void *k_extra_chkstk_darwin_slot = (void *)0xc00000000000000fULL;
static void *k_extra_get_cpu_capabilities_slot = (void *)0x4008000000000011ULL;
static void *k_extra_kcfallocatordefault_slot = (void *)0x400800000000000dULL;
static void *k_extra_mach_task_self_slot = (void *)0x400800000000001cULL;
static void *k_extra_vm_page_mask_slot = (void *)0x4008000000000033ULL;
static void *k_extra_vm_page_shift_slot = (void *)0x4008000000000034ULL;
static void *k_extra_vm_page_size_slot = (void *)0x4008000000000035ULL;


uint64_t coruna_identity(uint64_t val)
{
  return val;
}





uint64_t coruna_identity_or_return(uint64_t val,uint64_t id_2)
{
  void (*ptr)(void);
  int err;
  uint64_t u;
  unsigned long unaff_x30;
  
  err = coruna_return_zero();
  if (err == 0) {
    return val;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  u = coruna_pacia(val,id_2);
  return u;
}





uint64_t coruna_identity_switch(uint64_t val,uint size,uint64_t id_2)
{
  void (*ptr)(void);
  int err;
  uint64_t u;
  unsigned long unaff_x30;
  
  err = coruna_return_zero();
  if ((err == 0) || (3 < size)) {
    return val;
  }
  switch(size) {
  case 1:
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
      return val;
    }
    ___stack_chk_fail();
case 2:
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
      return val;
    }
    ___stack_chk_fail();
case 3:
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
      return val;
    }
    ___stack_chk_fail();
}
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    u = coruna_pacia(val,id_2);
    return u;
  }
    ___stack_chk_fail();
}





void coruna_libsystem_vtable_init(long handle)
{
  *(void (**)(handle + 0x30) = coruna_init_libsystem;
  *(void (**)(handle + 0x38) = coruna_libsystem_rebase;
  *(void (**)(handle + 0x130) = coruna_libsystem_fixup;
  return;
}





unsigned long coruna_init_libsystem(uint64_t *arg,int *val,uint n,uint64_t *m)

{
  unsigned long u;
  uint64_t *ptr;
  uint *buf;
  byte *ptr;
  uint32_t size;
  char *ptr;
  ushort version;
  ushort port;
  uint tag;
  bool err;
  uint *str;
  bool status;
  uint kind;
  int err;
  long handle;
  void (*buf)(void);
  double *buf;
  long *str;
  unsigned long type_id;
  long addr;
  uint64_t type_id_8;
  long *copy;
  void (*str)(void);
  void (*copy)(void);
  void (*data)(void);
  void (*obj)(void);
  byte flags;
  uint type_id_9;
  uint32_t type_id_10;
  long *data;
  int *err;
  byte *obj;
  int *status;
  long *block;
  int *flags;
  unsigned long type_id_11;
  unsigned long type_id_12;
  unsigned long type_id_13;
  long off;
  int *count;
  uint type_id_14;
  unsigned long type_id_15;
  uint *copy;
  long base;
  uint type_id_16;
  byte *entry;
  byte *entry_9;
  unsigned long scratch;
  int *bootargs;
  long *thread_attr;
  long host_info [64];
  uint serial_buf;
  long action;
  void (*block_ctx)(void);
  long stack_guard;
  unsigned long scratch;
  uint *sa_saved;
  long sa_new [3];
  unsigned long path_buf;
  long tmp_buf [2];
  
  coruna_memset_pattern(host_info,0,0x208);
  if (*(char *)((long)arg + 0x5c2) != '\0') {
    handle = (*(void (*)*arg)("/usr/lib/system/libdyld.dylib",0x10);
    if (handle == 0) {
      return 0x1200b;
    }
    buf = (void (*)(*(void (*)arg[1])(handle,"dyld_get_program_sdk_version");
    if (buf == (void (*)0x0) {
      type_id_15 = 0x12001;
fail:
      (*(void (*)arg[3])(handle);
      return type_id_15;
    }
    buf = (double *)(*(void (*)arg[1])(handle,"dyldVersionNumber");
    type_id_15 = 0x12001;
    if ((((buf == (double *)0x0) || (type_id_15 = 0xad008, *buf < k_extra_cpu_cap_threshold)) ||
        (kind = (*buf)(), kind < 0x100000)) || ((k_extra_icache_mode & 0xfe) != 2))
    goto fail;
    (*(void (*)arg[3])(handle);
  }
  if (((arg[5] == 0 || m == (uint64_t *)0x0) || val == (int *)0x0) || n == 0)
  {
    return 0x12002;
  }
  str = (long *)coruna_anon_mmap(arg,0x120);
  if (str == (long *)0x0) {
    return 0x12002;
  }
  type_id_15 = (unsigned long)n;
  coruna_memset_pattern(str,0,0x120);
  str[0xd] = (long)val;
  str[0x14] = type_id_15;
  handle = arg[2];
  if (handle == 0) {
    kind = 0xff;
  }
  else {
    type_id_15 = coruna_identity(handle);
    err = (int *)(type_id_15 & 0xfffffffffffff000);
    do {
      count = err;
      err = count + -0x400;
    } while (*count != -0x1120531);
    kind = count[2] & 0xffffff;
    val = (int *)str[0xd];
    type_id_15 = str[0x14];
  }
  if (*val == -0x35014542 || *val == -0x41450136) {
    type_id_9 = val[1];
    if (type_id_9 == 0) {
      return 0x12006;
    }
    scratch = 0;
    type_id_16 = 0;
    type_id_14 = 0;
    bootargs = (int *)0x0;
    err = (int *)((long)val + type_id_15);
    type_id_9 = (type_id_9 & 0xff00ff00) >> 8 | (type_id_9 & 0xff00ff) << 8;
    type_id_9 = type_id_9 >> 0x10 | type_id_9 << 0x10;
    if (type_id_9 < 2) {
      type_id_9 = 1;
    }
    do {
      type_id = coruna_extra0a_stub(0x14,type_id_16);
      count = (int *)((long)val + (type_id & 0xffffffff) + 8);
      if (count < val || err <= count) {
        return 0x12004;
      }
      if ((int *)((long)count + 0x13U) < val || err <= (int *)((long)count + 0x13U)) {
        return 0x12004;
      }
      tag = (count[2] & 0xff00ff00U) >> 8 | (count[2] & 0xff00ffU) << 8;
      type_id = (unsigned long)(tag >> 0x10 | tag << 0x10);
      if ((long)type_id_15 <= (long)type_id) {
        return 0x12005;
      }
      status = (int *)((long)val + type_id);
      tag = (count[3] & 0xff00ff00U) >> 8 | (count[3] & 0xff00ffU) << 8;
      type_id = (unsigned long)(tag >> 0x10 | tag << 0x10);
      flags = (int *)((long)status + (type_id - 1));
      if (flags < val || err <= flags) {
        return 0x12005;
      }
      if ((*count == 0xc000001) &&
         (tag = (count[1] & 0xff00ff00U) >> 8,
         tag = (tag | (count[1] & 0xff0000U) << 8) >> 0x10 | tag << 0x10,
         tag <= kind && type_id_14 <= tag)) {
        scratch = type_id;
        bootargs = status;
        type_id_14 = tag;
      }
      type_id_16 = type_id_16 + 1;
    } while (type_id_9 != type_id_16);
    if (bootargs == (int *)0x0) {
      return 0x12006;
    }
    str[0x14] = scratch;
    str[0xd] = (long)bootargs;
    val = bootargs;
    type_id_15 = scratch;
  }
  if (type_id_15 < 0x20) {
    return 0x13001;
  }
  if (*val != -0x1120531) {
    return 0x13002;
  }
  if (type_id_15 < (unsigned long)(uint)val[5] + 0x20) {
    return 0x13003;
  }
  if ((handle == 0) && (val[3] != 7)) {
    return 0x13006;
  }
  if (val[1] != 0x100000c) {
    return 0x13004;
  }
  type_id_9 = val[2] & 0xffffff;
  if (kind < type_id_9) {
    kind = 0x3005;
    goto done;
  }
  if (type_id_9 == 2) {
    flags = *(byte *)((long)str + 0xac) | 0x40;
    *(byte *)((long)str + 0xac) = flags;
  }
  else {
    if (type_id_9 < 2) {
      return 0x13005;
    }
    flags = *(byte *)((long)str + 0xac);
  }
  *(byte *)((long)str + 0xac) = *(byte *)(val + 6) >> 2 & 8 | flags & 0xf7;
  *str = (long)val;
  err = val[4];
  if (err == 0) {
    type_id = 0;
    handle = 0;
  }
  else {
    handle = 0;
    type_id = 0;
    err = val + 8;
    do {
      if (err < val) {
        return 0x14001;
      }
      if ((int *)((long)val + type_id_15) <= err) {
        return 0x14001;
      }
      if (*err == 0x19) {
        type_id_13 = *(unsigned long *)(err + 8);
        if (CARRY8(type_id,type_id_13)) {
          return 0x14002;
        }
        if ((*(long *)(err + 10) == 0) && (*(long *)(err + 0xc) != 0)) {
          if (handle != 0) {
            return 0x14003;
          }
          handle = *(long *)(err + 6);
        }
        if (0xfffffffe < type_id_13) {
          type_id_13 = 0;
        }
        type_id = type_id_13 + type_id;
      }
      err = (int *)((long)err + (unsigned long)(uint)err[1]);
      err = err + -1;
    } while (err != 0);
  }
  if (*(char *)((long)arg + 0x5c2) == '\0') {
    off = coruna_map_size_round(arg,type_id,1);
    if (off == -1) {
      return 0x14004;
    }
  }
  else {
    addr = coruna_mmap(0,type_id,3,&k_extra_mmap_anon_fd,0,0);
    off = 0;
    if (addr != -1) {
      off = addr;
    }
  }
  str[10] = handle;
  str[0xb] = off;
  *(int *)(str + 0x15) = (int)type_id;
  if ((arg[0xba] != 0) && (arg[0xbb] != 0)) {
    off = arg[0xba] + (off - arg[0xbb]);
  }
  str[0xc] = off;
  if (*(int *)(*str + 0x10) != 0) {
    if (str[0x14] < 0x21) {
      return 0x14009;
    }
    kind = 0;
    err = (int *)(str[0xd] + 0x20);
    do {
      err = *err;
      if (err < 0xf) {
        if (err < 2) {
          if (err == -0x7fffffde) {
cleanup:
            str[4] = (long)err;
          }
          else if (err == -0x7fffffcc) {
            *(byte *)((long)str + 0xac) = *(byte *)((long)str + 0xac) | 0x40;
            str[5] = (long)err;
          }
        }
        else if (err == 2) {
          str[6] = (long)err;
        }
        else if (err == 0xd) {
          str[3] = (long)err;
        }
      }
      else if (err < 0x1a) {
        if (err == 0xf) {
          flags = *(byte *)((long)str + 0xac) | 0x10;
check_ok:
          *(byte *)((long)str + 0xac) = flags;
        }
        else if (err == 0x19) {
          count = err + 2;
          err = coruna_strcmp(count,"__PAGEZERO");
          if (err != 0) {
            err = coruna_strcmp(count,"__TEXT");
            if (err == 0) {
              err = false;
              status = true;
            }
            else {
              err = coruna_strcmp(count,"__DATA");
              if (err == 0) {
                status = false;
                err = true;
              }
              else {
                err = coruna_strcmp(count,"__LINKEDIT");
                if (err == 0) {
                  status = false;
                  err = false;
                  str[1] = ((str[0xb] - str[10]) + *(long *)(err + 6)) -
                               *(long *)(err + 10);
                }
                else {
                  status = false;
                  err = false;
                }
              }
            }
            type_id_15 = str[0xb];
            type_id = *(unsigned long *)(err + 0xc);
            handle = 0;
            if (type_id != 0) {
              handle = type_id - 1;
            }
            if (type_id_15 == 0) {
              return 0x14006;
            }
            type_id_13 = *(unsigned long *)(err + 8);
            if ((((-1 < (long)type_id_13) && (type_id <= type_id_13)) &&
                (off = *(long *)(err + 10), -1 < off)) && (off < str[0x14])) {
              type_id_11 = str[0xd];
              type_id_12 = type_id_11 + off + handle;
              if ((((type_id_11 <= type_id_12) && (type_id_12 < type_id_11 + str[0x14])) &&
                  ((type_id_12 = *(long *)(err + 6) + (type_id_15 - str[10]), type_id_15 <= type_id_12 &&
                   ((type_id_12 < type_id_15 + *(uint *)(str + 0x15) &&
                    (u = (type_id_12 - 1) + type_id_13, type_id_15 <= u)))))) &&
                 (u < type_id_15 + *(uint *)(str + 0x15))) {
                err = coruna_mach_memory_entry(arg,type_id_12,type_id_13,3);
                if (err != 0) {
                  return 0x14008;
                }
                coruna_memcpy_bytes(type_id_12,type_id_11 + off,type_id);
                coruna_memset_pattern(type_id_12 + type_id,0,type_id_13 - type_id);
                if (err[0x10] != 0) {
                  type_id_9 = 0;
                  do {
                    type_id_15 = coruna_extra0a_stub(0x50,type_id_9);
                    type_id_15 = (long)err + (type_id_15 & 0xffffffff) + 0x48;
                    if (type_id_15 < (unsigned long)str[0xd] ||
                        (unsigned long)(str[0xd] + str[0x14]) <= type_id_15) {
                      return 0x1400a;
                    }
                    if (*(char *)(type_id_15 + 0x40) == '\n') {
                      flags = *(byte *)((long)str + 0xac) | 2;
skip:
                      *(byte *)((long)str + 0xac) = flags;
                    }
                    else {
                      if (*(char *)(type_id_15 + 0x40) == '\t') {
                        flags = *(byte *)((long)str + 0xac) | 1;
                        goto skip;
                      }
                      if (status) {
                        err = coruna_strcmp(type_id_15,"__eh_frame");
                        if (err == 0) {
                          *(int *)(str + 0x16) = (int)type_id_15 - (int)err;
                        }
                        else {
                          err = coruna_strcmp(type_id_15,"__unwind_info");
                          if (err == 0) {
                            *(int *)((long)str + 0xb4) = (int)type_id_15 - (int)err;
                          }
                          else {
                            err = coruna_strcmp(type_id_15,"__x");
                            if (err == 0) {
                              str[0x1d] =
                                   (str[0xb] - str[10]) + *(long *)(type_id_15 + 0x20);
                            }
                            else {
                              err = coruna_strcmp(type_id_15,"__stubs");
                              if (err == 0) {
                                str[0x1e] =
                                     (str[0xb] - str[10]) + *(long *)(type_id_15 + 0x20);
                                str[0x1f] = *(long *)(type_id_15 + 0x28);
                              }
                              else {
                                err = coruna_strcmp(type_id_15,"__auth_stubs");
                                if (err == 0) {
                                  str[0x20] =
                                       (str[0xb] - str[10]) + *(long *)(type_id_15 + 0x20);
                                  str[0x21] = *(long *)(type_id_15 + 0x28);
                                }
                                else {
                                  err = coruna_strcmp(type_id_15,"__objc_stubs");
                                  if (err == 0) {
                                    str[0x22] =
                                         (str[0xb] - str[10]) + *(long *)(type_id_15 + 0x20);
                                    str[0x23] = *(long *)(type_id_15 + 0x28);
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                      else if ((err) && (err = coruna_strcmp(type_id_15,"__internal"), err == 0)
                              ) {
                        flags = *(byte *)((long)str + 0xac) | 0x20;
                        goto skip;
                      }
                    }
                    type_id_9 = type_id_9 + 1;
                  } while (type_id_9 < (uint)err[0x10]);
                }
                goto next;
              }
            }
            kind = 0x4007;
            goto done;
          }
        }
      }
      else {
        if (err == 0x1a) {
          flags = *(byte *)((long)str + 0xac) | 4;
          goto check_ok;
        }
        if (err == 0x22) goto cleanup;
      }
next:
      kind = kind + 1;
      if (*(uint *)(*str + 0x10) <= kind) {
        err = (int *)str[0xd];
        serial_buf = 0;
        if (*(uint *)(*str + 0x10) == 0) goto retry;
        if (str[0x14] < 0x21) {
          return 0x17001;
        }
        kind = 0;
        status = (int *)((long)err + str[0x14]);
        count = err + 8;
        goto found;
      }
      err = (int *)((long)err + (unsigned long)(uint)err[1]);
      if (err < (int *)str[0xd]) {
        return 0x14009;
      }
      if ((int *)(str[0xd] + str[0x14]) <= err) {
        return 0x14009;
      }
    } while( true );
  }
  serial_buf = 0;
retry:
  thread_attr = str + 0xf;
  handle = str[5];
  if ((handle == 0) || (*(int *)(handle + 8) == 0)) {
    type_id_15 = 0xad008;
    handle = str[4];
    if ((handle == 0) || (*(int *)(handle + 0x10) == 0)) goto nomem;
    if ((*(byte *)((long)str + 0xac) >> 6 & 1) == 0) {
      type_id_15 = 0x930003;
      addr = str[0xc];
      base = str[10];
      off = str[1];
      kind = *(uint *)(handle + 8);
      type_id_9 = *(uint *)(handle + 0xc);
      copy = (long *)coruna_macho_seg_by_index(0);
      if (copy == (long *)0x0) {
invalid:
        type_id_15 = 0x930004;
        goto nomem;
      }
      if (type_id_9 != 0) {
        addr = addr - base;
        entry_9 = (byte *)(off + (unsigned long)kind);
        ptr = entry_9 + type_id_9;
        kind = 1;
        do {
          entry = entry_9 + 1;
          flags = *entry_9;
          data = copy;
          entry_9 = entry;
          if (flags >> 4 < 9) {
            type_id_9 = flags & 0xf;
            err = (int)addr;
            switch(flags >> 4) {
            default:
              goto again;
            case 1:
              kind = type_id_9;
              break;
            case 2:
              handle = coruna_macho_seg_by_index(type_id_9,str);
              if (handle == 0) goto invalid;
              type_id = 0;
              type_id_13 = 0;
              obj = entry;
              do {
                if (ptr <= obj) {
                  type_id = 0;
                  entry_9 = entry;
                  break;
                }
                entry_9 = obj + 1;
                flags = *obj;
                type_id_12 = ((unsigned long)flags & 0x7f) << (type_id_13 & 0x3f);
                if (0x3f < (uint)type_id_13) {
                  type_id_12 = 0;
                }
                type_id = type_id_12 | type_id;
                type_id_13 = (unsigned long)((uint)type_id_13 + 7);
                obj = entry_9;
              } while ((char)flags < '\0');
              data = (long *)(handle + type_id);
              break;
            case 3:
              type_id = 0;
              type_id_13 = 0;
              obj = entry;
              do {
                if (ptr <= obj) {
                  type_id = 0;
                  entry_9 = entry;
                  break;
                }
                entry_9 = obj + 1;
                flags = *obj;
                type_id_12 = ((unsigned long)flags & 0x7f) << (type_id_13 & 0x3f);
                if (0x3f < (uint)type_id_13) {
                  type_id_12 = 0;
                }
                type_id = type_id_12 | type_id;
                type_id_13 = (unsigned long)((uint)type_id_13 + 7);
                obj = entry_9;
              } while ((char)flags < '\0');
              data = (long *)((long)copy + type_id);
              break;
            case 4:
              type_id = coruna_extra0a_stub(type_id_9,8);
              data = (long *)((long)copy + (type_id & 0xffffffff));
              break;
            case 5:
              if ((flags & 0xf) != 0) {
                block = (long *)str[0xb];
                do {
                  if ((copy < block) ||
                     ((long *)((long)block + (unsigned long)*(uint *)(str + 0x15)) <= data))
                  goto nomem;
                  if (kind == 2) {
                    *(int *)data = (int)*data + err;
                  }
                  else if (kind == 1) {
                    *data = *data + addr;
                  }
                  data = data + 1;
                  type_id_9 = type_id_9 - 1;
                } while (type_id_9 != 0);
              }
              break;
            case 6:
              type_id = 0;
              type_id_13 = 0;
              obj = entry;
              do {
                entry_9 = entry;
                if (ptr <= obj) goto exit_ok;
                entry_9 = obj + 1;
                flags = *obj;
                type_id_12 = ((unsigned long)flags & 0x7f) << (type_id_13 & 0x3f);
                if (0x3f < (uint)type_id_13) {
                  type_id_12 = 0;
                }
                type_id = type_id_12 | type_id;
                type_id_13 = (unsigned long)((uint)type_id_13 + 7);
                obj = entry_9;
              } while ((char)flags < '\0');
              if (type_id != 0) {
                block = (long *)str[0xb];
                type_id_13 = 2;
                do {
                  if ((copy < block) ||
                     ((long *)((long)block + (unsigned long)*(uint *)(str + 0x15)) <= data))
                  goto nomem;
                  if (kind == 2) {
                    *(int *)data = (int)*data + err;
                  }
                  else if (kind == 1) {
                    *data = *data + addr;
                  }
                  data = data + 1;
                  status = type_id_13 <= type_id;
                  type_id_13 = (unsigned long)((int)type_id_13 + 1);
                } while (status);
              }
              break;
            case 7:
              if (copy < (long *)str[0xb] ||
                  (long *)(str[0xb] + (unsigned long)*(uint *)(str + 0x15)) <= copy)
              goto nomem;
              if (kind == 2) {
                *(int *)copy = (int)*copy + err;
              }
              else if (kind == 1) {
                *copy = *copy + addr;
              }
              type_id = 0;
              type_id_13 = 0;
              obj = entry;
              do {
                if (ptr <= obj) {
                  type_id = 0;
                  entry_9 = entry;
                  break;
                }
                entry_9 = obj + 1;
                flags = *obj;
                type_id_12 = ((unsigned long)flags & 0x7f) << (type_id_13 & 0x3f);
                if (0x3f < (uint)type_id_13) {
                  type_id_12 = 0;
                }
                type_id = type_id_12 | type_id;
                type_id_13 = (unsigned long)((uint)type_id_13 + 7);
                obj = entry_9;
              } while ((char)flags < '\0');
              data = (long *)((long)copy + type_id + 8);
              break;
            case 8:
              type_id = 0;
              type_id_13 = 0;
              do {
                if (ptr <= entry_9) {
                  type_id = 0;
                  obj = entry;
                  break;
                }
                obj = entry_9 + 1;
                flags = *entry_9;
                type_id_12 = ((unsigned long)flags & 0x7f) << (type_id_13 & 0x3f);
                if (0x3f < (uint)type_id_13) {
                  type_id_12 = 0;
                }
                type_id = type_id_12 | type_id;
                type_id_13 = (unsigned long)((uint)type_id_13 + 7);
                entry_9 = obj;
              } while ((char)flags < '\0');
              type_id_13 = 0;
              type_id_12 = 0;
              entry = obj;
              do {
                if (ptr <= entry) {
                  type_id_13 = 0;
                  entry_9 = obj;
                  break;
                }
                entry_9 = entry + 1;
                flags = *entry;
                type_id_11 = ((unsigned long)flags & 0x7f) << (type_id_12 & 0x3f);
                if (0x3f < (uint)type_id_12) {
                  type_id_11 = 0;
                }
                type_id_13 = type_id_11 | type_id_13;
                type_id_12 = (unsigned long)((uint)type_id_12 + 7);
                entry = entry_9;
              } while ((char)flags < '\0');
              if (type_id != 0) {
                block = (long *)str[0xb];
                type_id_12 = 2;
                do {
                  if ((copy < block) ||
                     ((long *)((long)block + (unsigned long)*(uint *)(str + 0x15)) <= copy))
                  goto nomem;
                  if (kind == 2) {
                    *(int *)copy = (int)*copy + err;
                  }
                  else if (kind == 1) {
                    *copy = *copy + addr;
                  }
                  copy = (long *)((long)copy + type_id_13 + 8);
                  status = type_id_12 <= type_id;
                  type_id_12 = (unsigned long)((int)type_id_12 + 1);
                  data = copy;
                } while (status);
              }
            }
          }
exit_ok:
          copy = data;
        } while (entry_9 < ptr);
      }
again:
      type_id_15 = coruna_memmem_scan(0,str,host_info,arg);
      if ((int)type_id_15 != 0) goto nomem;
      type_id_8 = 1;
    }
    else {
      type_id_8 = 0;
    }
    type_id = coruna_memmem_scan(type_id_8,str,host_info,arg);
  }
  else {
    type_id_15 = 0xad008;
    if (((*(byte *)((long)str + 0xac) >> 6 & 1) == 0) ||
       (type_id_15 = 0xad001, *(int *)(handle + 0xc) == 0)) goto nomem;
    sa_saved = (uint *)0x0;
    type_id = coruna_macho_walk_segments(str,*(int *)(handle + 8),&sa_saved);
    buf = sa_saved;
    if ((((int)type_id == 0) &&
        (((type_id = 0x920003, *sa_saved == 0 && (0x1b < sa_saved[1])) && (0x1b < sa_saved[2])))) &&
       (0x1b < sa_saved[3])) {
      kind = sa_saved[4];
      if ((kind != 0) && (sa_saved[6] == 0)) {
        if ((arg == (uint64_t *)0x0) || (kind >> 0x10 != 0)) {
          type_id = 0xad001;
        }
        else {
          err = (kind & 0xffff) << 3;
          handle = coruna_anon_mmap(arg);
          if (handle == 0) {
            type_id = 0xad009;
          }
          else {
            coruna_memset_pattern(handle,0,err);
            off = 0;
            type_id_9 = buf[3];
            copy = buf;
            do {
              if (buf[5] != 1) {
                type_id = 0x920004;
                goto parse_ok;
              }
              type_id_14 = *(uint *)((long)copy + (unsigned long)buf[2]);
              type_id_16 = (int)(char)type_id_14;
              if ((type_id_14 & 0xff) < 0xf1) {
                type_id_16 = type_id_14 & 0xff;
              }
              ptr = (uint64_t *)(handle + off);
              type_id = coruna_init_libcache((long)buf + (unsigned long)(type_id_14 >> 9) + (unsigned long)type_id_9,host_info,
                                    arg,ptr,type_id_16);
              if ((int)type_id == 0x910006 && (type_id_14 & 0x100) != 0) {
                type_id_8 = 0;
                *ptr = 0;
              }
              else {
                if ((int)type_id != 0) goto parse_ok;
                type_id_8 = *ptr;
              }
              type_id_8 = coruna_identity(type_id_8);
              str = sa_saved;
              *ptr = type_id_8;
              copy = copy + 1;
              off = off + 8;
            } while ((unsigned long)kind << 3 != off);
            if (sa_saved != (uint *)0x0) {
              buf = (uint *)((long)sa_saved + (unsigned long)sa_saved[1]);
              type_id_15 = 0x920001;
              if (sa_saved <= buf && sa_saved[1] < *(uint *)(str[5] + 0xc)) {
                type_id_9 = *buf;
                if (type_id_9 == 0) {
                  type_id_15 = 0;
                }
                else {
                  type_id = 0;
                  do {
                    if (buf[type_id + 1] != 0) {
                      copy = (uint *)((long)buf + (unsigned long)buf[type_id + 1]);
                      if (copy < str ||
                          (uint *)((long)str + (unsigned long)*(uint *)(str[5] + 0xc)) <= copy) {
                        type_id_15 = 0x920001;
                        break;
                      }
                      type_id_13 = 0;
                      while (type_id_13 < (ushort)copy[5]) {
                        version = *(ushort *)((long)copy + type_id_13 * 2 + 0x16);
                        if ((unsigned long)version == 0xffff) {
                          type_id_15 = 0;
                        }
                        else if ((short)version < 0) {
                          do {
                            port = *(ushort *)((long)copy + ((unsigned long)version & 0x7fff) * 2 + 0x16);
                            type_id_15 = coruna_macho_reloc_apply(str,handle,kind & 0xffff,copy,type_id_13,
                                                  port & 0x7fff);
                            if ((int)type_id_15 != 0) break;
                          } while (-1 < (short)port);
                        }
                        else {
                          type_id_15 = coruna_macho_reloc_apply(str,handle,kind & 0xffff,copy,type_id_13);
                        }
                        type_id_13 = type_id_13 + 1;
                        if ((int)type_id_15 != 0) goto load_ok;
                      }
                      type_id_9 = *buf;
                    }
                    type_id_15 = 0;
                    type_id = type_id + 1;
                  } while (type_id < type_id_9);
                }
              }
            }
load_ok:
            type_id = type_id_15;
            if ((kind & 0xffff) != 0) {
parse_ok:
              coruna_wipe_and_map(arg,handle,err);
            }
          }
        }
      }
    }
  }
  type_id_15 = type_id;
  if (((int)type_id_15 != 0) || (type_id_15 = coruna_load_javascriptcore(str,arg), (int)type_id_15 != 0))
  goto nomem;
  if (*thread_attr != 0) {
    action = 0;
    block_ctx = (void (*)0x0;
    coruna_memset_pattern(&sa_saved,0,0x20);
    handle = (*(void (*)arg[1])(*thread_attr,"object_getClass");
    off = (*(void (*)arg[1])(*thread_attr,"_objc_patch_root_of_class");
    buf = (void (*)(*(void (*)arg[1])(*thread_attr,"_objc_map_images");
    if (handle == 0) {
      return 0x18002;
    }
    err = (*(void (*)arg[2])(handle,&sa_saved);
    handle = sa_new[0];
    if (err == 0) {
      return 0x18003;
    }
    type_id_15 = coruna_macho_find_section("__TEXT","__text",sa_new[0],&scratch,&stack_guard);
    if ((int)type_id_15 != 0) {
      return type_id_15;
    }
    err = *(int *)(sa_new[0] + 0x10);
    if (err != 0) {
      err = (int *)(sa_new[0] + 0x20);
      do {
        if (*err == 0x25) {
          addr = 8;
load_ok_15:
          kind = *(uint *)((long)err + addr);
          if ((off == 0) || (kind < 0x110000)) goto load_ok_16;
          err = coruna_macho_find_section("__AUTH_CONST","__const",sa_new[0],tmp_buf,&path_buf);
          if (err == 0x18006) {
            err = coruna_macho_find_section("__DATA_CONST","__const",sa_new[0],tmp_buf,&path_buf);
          }
          if ((((err != 0) || (tmp_buf[0] == 0)) || (path_buf < 0x19)) ||
             ((0xfffffffe < path_buf || ((long)path_buf < 0x20)))) goto load_ok_16;
          copy = (long *)(tmp_buf[0] + 0x18);
          goto load_ok_17;
        }
        if (*err == 0x32) {
          addr = 0xc;
          goto load_ok_15;
        }
        err = (int *)((long)err + (unsigned long)(uint)err[1]);
        err = err + -1;
      } while (err != 0);
    }
    return 0x18009;
  }
  goto load_ok_18;
found:
  err = *count;
  if (err < 0xb) {
    if (err == -0x7fffffe8) {
load_ok_19:
      flags = (int *)((long)count + (unsigned long)(uint)count[2]);
      if (flags < err || status <= flags) {
        return 0x17001;
      }
      err = coruna_strncmp(flags,"@rpath",6);
      handle = 6;
      if (err != 0) {
        handle = 0;
      }
      off = (*(void (*)*arg)((long)flags + handle,2);
      if (off == 0) {
        return 0x17004;
      }
      type_id_15 = (unsigned long)serial_buf;
      if (serial_buf == 0x40) {
        return 0x17005;
      }
      serial_buf = serial_buf + 1;
      host_info[type_id_15] = off;
      err = coruna_strcmp((long)flags + handle,"/usr/lib/libobjc.A.dylib");
      if (err == 0) {
        str[0xf] = off;
      }
    }
    else if (err == 2) {
      str[6] = (long)count;
      type_id_15 = str[1] + (unsigned long)(uint)count[4];
      str[9] = type_id_15;
      type_id = str[0xb];
      if (type_id_15 < type_id || type_id + *(uint *)(str + 0x15) <= type_id_15) {
        return 0x17001;
      }
      type_id_15 = str[1] + (unsigned long)(uint)count[2];
      str[7] = type_id_15;
      if (type_id_15 < type_id || type_id + *(uint *)(str + 0x15) <= type_id_15) {
        return 0x17001;
      }
    }
  }
  else {
    if (err == 0xc) goto load_ok_19;
    if (err == 0xb) {
      str[8] = (long)count;
    }
  }
  kind = kind + 1;
  if (*(uint *)(*str + 0x10) <= kind) goto retry;
  count = (int *)((long)count + (unsigned long)(uint)count[1]);
  err = (int *)str[0xd];
  status = (int *)((long)err + str[0x14]);
  if (count < err || status <= count) {
    return 0x17001;
  }
  goto found;
load_ok_20:
  type_id_15 = 0x12008;
  goto nomem;
  while (copy = copy + 1, copy <= (long *)((path_buf + tmp_buf[0]) - 8)) {
load_ok_17:
    if (*copy == off) {
      str = (void (*)copy[-3];
      off = copy[-1];
      type_id_15 = coruna_identity(str);
      type_id = coruna_identity(off);
      if ((((scratch <= type_id_15 && type_id_15 < scratch + stack_guard) && scratch <= type_id) &&
           type_id < scratch + stack_guard) &&
         (action = off, block_ctx = str, buf != (void (*)0x0)) goto load_ok_21;
      break;
    }
  }
load_ok_16:
  if ((int)kind < 0xf0000) {
    if ((int)kind < 0xe0000) {
      if ((int)kind < 0xd0400) {
        if ((int)kind < 0xd0200) {
          if (kind != 0xd0000) {
            type_id_9 = 0x100;
load_ok_22:
            type_id_9 = type_id_9 | 0xd0000;
            goto load_ok_23;
          }
        }
        else if (kind != 0xd0200) {
          type_id_9 = 0x300;
          goto load_ok_22;
        }
      }
      else if ((int)kind < 0xd0600) {
        if (kind != 0xd0400) {
          type_id_9 = 0x500;
          goto load_ok_22;
        }
      }
      else if (kind != 0xd0600) {
        type_id_9 = 0x700;
        goto load_ok_22;
      }
    }
    else if ((int)kind < 0xe0400) {
      if ((int)kind < 0xe0200) {
        if (kind != 0xe0000) {
          type_id_9 = 0x100;
          goto load_ok_24;
        }
      }
      else if (kind != 0xe0200) {
        type_id_9 = 0x300;
        goto load_ok_24;
      }
    }
    else if ((int)kind < 0xe0600) {
      if (kind != 0xe0400) {
        type_id_9 = 0x500;
        goto load_ok_24;
      }
    }
    else if ((kind != 0xe0600) && (kind != 0xe0700)) {
      type_id_9 = 0x800;
load_ok_24:
      type_id_9 = type_id_9 | 0xe0000;
load_ok_23:
      if (kind != type_id_9) goto load_ok_25;
    }
  }
  else if ((int)kind < 0xf0800) {
    if ((int)kind < 0xf0400) {
      if ((int)kind < 0xf0200) {
        if (kind != 0xf0000) {
          type_id_9 = 0x100;
load_ok_26:
          type_id_9 = type_id_9 | 0xf0000;
          goto load_ok_23;
        }
      }
      else if (kind != 0xf0200) {
        type_id_9 = 0x300;
        goto load_ok_26;
      }
    }
    else if ((int)kind < 0xf0600) {
      if (kind != 0xf0400) {
        type_id_9 = 0x500;
        goto load_ok_26;
      }
    }
    else if (kind != 0xf0600) {
      type_id_9 = 0x700;
      goto load_ok_26;
    }
  }
  else if ((int)kind < 0x100300) {
    if ((int)kind < 0x100100) {
      if ((kind != 0xf0800) && (kind != 0x100000)) {
load_ok_25:
        kind = 0x8008;
done:
        return (unsigned long)(kind | 0x10000);
      }
    }
    else if (kind != 0x100100) {
      type_id_9 = 0x200;
      goto load_ok_27;
    }
  }
  else if ((int)kind < 0x100500) {
    if (kind != 0x100300) {
      type_id_9 = 0x400;
      goto load_ok_27;
    }
  }
  else if ((kind != 0x100500) && (kind != 0x100700)) {
    type_id_9 = 0x600;
load_ok_27:
    type_id_9 = type_id_9 | 0x100000;
    goto load_ok_23;
  }
  type_id_9 = 0xfffff;
  if (kind < 0xf0000) {
    type_id_9 = 0xdffff;
  }
  type_id_10 = 6;
  if (kind < 0xf0000) {
    type_id_10 = 1;
  }
  ptr = "objc_retainAutorelease";
  if (kind < 0xf0000) {
    ptr = "_objc_flush_caches";
  }
  size = 5;
  if (kind <= type_id_9) {
    size = type_id_10;
  }
  type_id_15 = coruna_vm_map_fixup(arg,ptr,size,scratch,stack_guard,&block_ctx);
  if ((int)type_id_15 != 0) {
    return type_id_15;
  }
  if ((int)kind < 0xf0000) {
    if ((int)kind < 0xe0000) {
      if ((int)kind < 0xd0400) {
        if ((int)kind < 0xd0200) {
          if (kind != 0xd0000) {
            type_id_9 = 0x100;
load_ok_28:
            type_id_9 = type_id_9 | 0xd0000;
            goto load_ok_29;
          }
        }
        else if (kind != 0xd0200) {
          type_id_9 = 0x300;
          goto load_ok_28;
        }
      }
      else if ((int)kind < 0xd0600) {
        if (kind != 0xd0400) {
          type_id_9 = 0x500;
          goto load_ok_28;
        }
      }
      else if (kind != 0xd0600) {
        type_id_9 = 0x700;
        goto load_ok_28;
      }
    }
    else if ((int)kind < 0xe0400) {
      if ((int)kind < 0xe0200) {
        if (kind != 0xe0000) {
          type_id_9 = 0x100;
          goto load_ok_30;
        }
      }
      else if (kind != 0xe0200) {
        type_id_9 = 0x300;
        goto load_ok_30;
      }
    }
    else if ((int)kind < 0xe0600) {
      if (kind != 0xe0400) {
        type_id_9 = 0x500;
        goto load_ok_30;
      }
    }
    else if ((kind != 0xe0600) && (kind != 0xe0700)) {
      type_id_9 = 0x800;
load_ok_30:
      type_id_9 = type_id_9 | 0xe0000;
load_ok_29:
      if (kind != type_id_9) {
        return 0x18008;
      }
    }
  }
  else if ((int)kind < 0xf0800) {
    if ((int)kind < 0xf0400) {
      if ((int)kind < 0xf0200) {
        if (kind != 0xf0000) {
          type_id_9 = 0x100;
load_ok_31:
          type_id_9 = type_id_9 | 0xf0000;
          goto load_ok_29;
        }
      }
      else if (kind != 0xf0200) {
        type_id_9 = 0x300;
        goto load_ok_31;
      }
    }
    else if ((int)kind < 0xf0600) {
      if (kind != 0xf0400) {
        type_id_9 = 0x500;
        goto load_ok_31;
      }
    }
    else if (kind != 0xf0600) {
      type_id_9 = 0x700;
      goto load_ok_31;
    }
  }
  else if ((int)kind < 0x100300) {
    if ((int)kind < 0x100100) {
      if ((kind != 0xf0800) && (kind != 0x100000)) {
        return 0x18008;
      }
    }
    else if (kind != 0x100100) {
      type_id_9 = 0x200;
      goto load_ok_32;
    }
  }
  else if ((int)kind < 0x100500) {
    if (kind != 0x100300) {
      type_id_9 = 0x400;
      goto load_ok_32;
    }
  }
  else if ((kind != 0x100500) && (kind != 0x100700)) {
    type_id_9 = 0x600;
load_ok_32:
    type_id_9 = type_id_9 | 0x100000;
    goto load_ok_29;
  }
  if (kind >> 0x14 == 0) {
    type_id_10 = 5;
    if (0x3c0 < kind >> 10) {
      type_id_10 = 6;
    }
    if (kind < 0xf0000) {
      if (kind < 0xe0000) {
        type_id_10 = 8;
        if (kind >> 9 < 0x681) {
          type_id_10 = 4;
        }
      }
      else {
        type_id_10 = 0xc;
      }
    }
  }
  else {
    type_id_10 = 8;
  }
  type_id_15 = coruna_vm_map_fixup(arg,"_objc_flush_caches",type_id_10,scratch,stack_guard,&action);
  buf = block_ctx;
  if ((int)type_id_15 != 0) {
    return type_id_15;
  }
load_ok_21:
  *(uint *)(str + 0x11) = kind;
  str[0x10] = handle;
  str[0x12] = (long)buf;
  str[0x13] = action;
  sa_saved = (uint *)str[0xb];
  sa_new[0] = 0;
  sa_new[1] = 0;
  (*buf)(1,sa_new,&sa_saved);
  type_id_15 = coruna_load_javascriptcore(str,arg);
  if ((int)type_id_15 != 0) {
    return type_id_15;
  }
load_ok_18:
  if (*(int *)(*str + 0x10) != 0) {
    kind = 0;
    off = str[10];
    handle = str[0xc];
    err = (int *)(str[0xd] + 0x20);
    do {
      if ((*err == 0x19) && (err = coruna_strcmp(err + 2,"__PAGEZERO"), err != 0)) {
        err = err[0xf];
        if (err == 0) {
          err = 1;
        }
        if (*(char *)((long)arg + 0x5c5) != '\0') {
          err = *(int *)(arg + 0xb9);
        }
        err = coruna_mach_memory_entry(arg,(handle - off) + *(long *)(err + 6),
                              *(uint64_t *)(err + 8),err);
        if (err != 0) {
          type_id_15 = 0x14005;
          goto nomem;
        }
      }
      err = (int *)((long)err + (unsigned long)(uint)err[1]);
      kind = kind + 1;
    } while (kind < *(uint *)(*str + 0x10));
  }
  flags = *(byte *)((long)str + 0xac);
  if ((flags >> 4 & 1) == 0) {
    type_id_15 = 0x1a001;
    if (((void (*)*arg == (void (*)0x0) || (arg[1] == 0)) goto nomem;
    if ((flags & 5) != 0) {
      handle = (*(void (*)*arg)("/usr/lib/libSystem.dylib",0x11);
      if (handle == 0) {
        kind = 0xd001;
      }
      else {
        buf = (void (*)(*(void (*)arg[1])(handle,"_NSGetMachExecuteHeader");
        if ((((buf != (void (*)0x0) &&
             (str = (void (*)(*(void (*)arg[1])(handle,"_NSGetArgc"), str != (void (*)0x0))
            && (copy = (void (*)(*(void (*)arg[1])(handle,"_NSGetArgv"), copy != (void (*)0x0
               )) && ((data = (void (*)(*(void (*)arg[1])(handle,"_NSGetEnviron"),
                      data != (void (*)0x0 &&
                      (obj = (void (*)(*(void (*)arg[1])(handle,"_NSGetProgname"),
                      obj != (void (*)0x0)))) {
          off = (*buf)();
          str[0x17] = off;
          off = (*str)();
          str[0x18] = off;
          off = (*copy)();
          str[0x19] = off;
          off = (*data)();
          str[0x1a] = off;
          off = (*obj)();
          str[0x1b] = off;
          (*(void (*)arg[3])(handle);
          flags = *(byte *)((long)str + 0xac);
          goto load_ok_33;
        }
        (*(void (*)arg[3])(handle);
        kind = 0xd002;
      }
      type_id_15 = (unsigned long)((kind | 0xfff60000) + 0xad001);
      goto nomem;
    }
load_ok_33:
    handle = str[10];
    if ((flags >> 2 & 1) != 0) {
      off = *str;
      if (*(int *)(off + 0x10) != 0) {
        kind = 0;
        addr = str[0xc];
        err = (int *)(str[0xd] + 0x20);
        do {
          if (*err == 0x1a) {
            type_id_15 = (addr - handle) + *(long *)(err + 2);
            if (type_id_15 < (unsigned long)str[0xc] ||
                str[0xc] + (unsigned long)*(uint *)(str + 0x15) <= type_id_15) goto load_ok_20;
            buf = (void (*)coruna_identity_or_return(type_id_15,0);
            (*buf)(*(uint32_t *)str[0x18],*(uint64_t *)str[0x19],
                       *(uint64_t *)str[0x1a],0,str + 0x17);
            off = *str;
          }
          err = (int *)((long)err + (unsigned long)(uint)err[1]);
          kind = kind + 1;
        } while (kind < *(uint *)(off + 0x10));
        handle = str[10];
        flags = *(byte *)((long)str + 0xac);
      }
    }
    if ((flags & 1) != 0) {
      off = *str;
      if (*(int *)(off + 0x10) != 0) {
        kind = 0;
        addr = str[0xb];
        err = (int *)(str[0xd] + 0x20);
        do {
          if (*err == 0x19) {
            count = err + 0x12;
            status = count + (unsigned long)(uint)err[0x10] * 0x14;
            if (count < status) {
              do {
                if (((char)count[0x10] == '\t') && (7 < *(unsigned long *)(count + 10))) {
                  off = *(long *)(count + 8);
                  type_id_15 = 0;
                  type_id = 1;
                  do {
                    type_id_15 = *(unsigned long *)((addr - handle) + off + type_id_15 * 8);
                    if (type_id_15 < (unsigned long)str[0xb] ||
                        str[0xb] + (unsigned long)*(uint *)(str + 0x15) <= type_id_15)
                    goto load_ok_20;
                    buf = (void (*)coruna_identity_or_return(type_id_15,0);
                    (*buf)(*(uint32_t *)str[0x18],*(uint64_t *)str[0x19],
                               *(uint64_t *)str[0x1a],0,str + 0x17);
                    status = type_id < *(unsigned long *)(count + 10) >> 3;
                    type_id_15 = type_id;
                    type_id = (unsigned long)((int)type_id + 1);
                  } while (status);
                }
                count = count + 0x14;
              } while (count < status);
              off = *str;
            }
          }
          type_id_15 = 0;
          err = (int *)((long)err + (unsigned long)(uint)err[1]);
          kind = kind + 1;
        } while (kind < *(uint *)(off + 0x10));
        goto nomem;
      }
    }
  }
  type_id_15 = 0;
nomem:
  *m = str;
  return type_id_15;
}





uint64_t coruna_libsystem_rebase(uint64_t val,long *handle,long addr_2,unsigned long *arg)
{
  unsigned long u;
  int err;
  long handle;
  long addr;
  int *err;
  int *status;
  long *ptr;
  unsigned long size;
  
  if (addr_2 == 0) {
    return 0xad001;
  }
  if (arg == (unsigned long *)0x0) {
    return 0xad001;
  }
  if (handle == (long *)0x0) {
    return 0xad001;
  }
  addr = handle[7];
  if (addr == 0) {
    return 0xad001;
  }
  if (handle[9] == 0) {
    return 0xad001;
  }
  *arg = 0;
  handle = handle[6];
  if (*(int *)(handle + 0xc) == 0) {
    return 0x12001;
  }
  size = 0;
  ptr = (long *)(addr + 8);
  do {
    if ((*(byte *)((long)ptr + -4) & 0xe1) == 1) {
      err = coruna_strcmp(addr_2,handle[9] + (unsigned long)*(uint *)(ptr + -1));
      if (err == 0) {
        size = (handle[0xc] - handle[10]) + *ptr;
        *arg = size;
        err = *(int *)(*handle + 0x10);
        if (err != 0) {
          status = (int *)(handle[0xd] + 0x20);
          while (((*status != 0x19 ||
                  (u = *(long *)(status + 6) + (handle[0xc] - handle[10]), size < u)) ||
                 (*(long *)(status + 8) + u <= size))) {
            status = (int *)((long)status + (unsigned long)(uint)status[1]);
            err = err + -1;
            if (err == 0) {
              return 0;
            }
          }
          err = status + 0x12;
          status = err + (unsigned long)(uint)status[0x10] * 0x14;
          if (err < status) {
            while ((u = *(long *)(err + 8) + (handle[0xc] - handle[10]), size < u ||
                   (*(long *)(err + 10) + u <= size))) {
              err = err + 0x14;
              if (status <= err) {
                return 0;
              }
            }
            if ((err[0x10] & 0x80000400U) != 0) {
              size = coruna_identity_or_return(size,0);
              *arg = size;
              return 0;
            }
          }
        }
        return 0;
      }
      handle = handle[6];
    }
    size = size + 1;
    ptr = ptr + 2;
  } while (size < *(uint *)(handle + 0xc));
  return 0x12001;
}





uint64_t coruna_libsystem_fixup(long handle,long *addr_2)
{
  long handle;
  long addr;
  byte err;
  int err;
  unsigned long u;
  void (*ptr)(void);
  long off;
  long base;
  uint size;
  uint64_t version;
  int *err;
  int *status;
  int *flags;
  
  err = *(byte *)((long)addr_2 + 0xac);
  if (-1 < (char)err) {
    if ((((err >> 4 & 1) == 0) && ((err >> 1 & 1) != 0)) &&
       (off = *addr_2, *(int *)(off + 0x10) != 0)) {
      size = 0;
      handle = addr_2[10];
      addr = addr_2[0xb];
      err = (int *)(addr_2[0xd] + 0x20);
      do {
        if (*err == 0x19) {
          status = err + 0x12;
          flags = status + (unsigned long)(uint)err[0x10] * 0x14;
          if (status < flags) {
            do {
              if (((char)status[0x10] == '\n') && ((int)(*(unsigned long *)(status + 10) >> 3) != 0)) {
                base = *(long *)(status + 8);
                off = (*(unsigned long *)(status + 10) >> 3 & 0xffffffff) << 3;
                do {
                  u = *(unsigned long *)((addr - handle) + base + -8 + off);
                  if (u < (unsigned long)addr_2[0xb] ||
                      addr_2[0xb] + (unsigned long)*(uint *)(addr_2 + 0x15) <= u) {
                    return 0x12009;
                  }
                  ptr = (void (*)coruna_identity_or_return(u,0);
                  (*ptr)();
                  off = off + -8;
                } while (off != 0);
              }
              status = status + 0x14;
            } while (status < flags);
            off = *addr_2;
          }
        }
        err = (int *)((long)err + (unsigned long)(uint)err[1]);
        size = size + 1;
      } while (size < *(uint *)(off + 0x10));
    }
    if (addr_2[0xf] != 0) {
      (*(void (*)addr_2[0x13])(0,addr_2[0xb]);
    }
    if (*(char *)(handle + 0x5c2) == '\0') {
      err = coruna_mach_memory_entry(handle,addr_2[0xb],(int)addr_2[0x15],3);
      if (err == 0) {
        coruna_memset_pattern(addr_2[0xb],0,(int)addr_2[0x15]);
        goto fail;
      }
done:
      version = 0x1400b;
      goto cleanup;
    }
fail:
    if (addr_2[0xf] == 0) {
      u = (unsigned long)*(uint *)(addr_2 + 0x15);
      if (*(char *)(handle + 0x5c2) == '\0') {
        if (*(char *)(handle + 0x5c5) == '\0') {
          if (*(void (**)(handle + 0xb0) == (void (*)0x0) goto check_ok;
          err = (**(void (**)(handle + 0xb0))(handle);
        }
        else {
          off = 0;
          if ((*(uint *)(addr_2 + 0x15) & 0x3fff) != 0) {
            off = 0x4000 - (u & 0x3fff);
          }
          err = coruna_mach_memory_entry(handle,addr_2[0xb],off + u,*(uint32_t *)(handle + 0x5c8));
        }
      }
      else {
        err = coruna_munmap(addr_2[0xb],u);
      }
      if (err != 0) {
        version = 0x1400c;
        goto cleanup;
      }
    }
    else if ((*(char *)(handle + 0x5c5) != '\0') &&
            (err = coruna_mach_memory_entry(handle,addr_2[0xb],(int)addr_2[0x15],
                                  *(uint32_t *)(handle + 0x5c8)), err != 0)) goto done;
  }
check_ok:
  version = 0;
cleanup:
  coruna_memset_pattern(addr_2,0,0x120);
  coruna_wipe_and_map(handle,addr_2,0x120);
  return version;
}





void coruna_memcpy_bytes(long handle,long addr_2,unsigned long arg)
{
  uint64_t scratch;
  
  for (scratch = 0; scratch < arg; scratch = scratch + 1) {
    *(uint8_t *)(handle + scratch) = *(uint8_t *)(addr_2 + scratch);
  }
  return;
}





long coruna_memscan_match(long handle,long addr_2,long off_3,unsigned long arg)
{
  bool err;
  char err;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  
  bootargs = 0;
  do {
    if (addr_2 - arg <= bootargs) {
      err = '\x02';
fail:
      if (err != '\x01') {
        thread_attr = 0;
      }
      return thread_attr;
    }
    err = true;
    for (scratch = 0; scratch < arg; scratch = scratch + 4) {
      if (*(int *)(handle + bootargs + scratch) != *(int *)(off_3 + scratch)) {
        err = false;
        break;
      }
    }
    if (err) {
      thread_attr = handle + bootargs;
      err = '\x01';
      goto fail;
    }
    bootargs = bootargs + 4;
  } while( true );
}





void coruna_memset_pattern(long handle,char path,unsigned long arg)
{
  uint64_t scratch;
  
  for (scratch = 0; scratch < arg; scratch = scratch + 1) {
    *(char *)(handle + scratch) = path + '\x01';
  }
  for (scratch = 0; scratch < arg; scratch = scratch + 1) {
    *(char *)(handle + scratch) = path;
  }
  return;
}





uint32_t coruna_strcmp(char *path,char *str_2)
{
  char err;
  char *scratch;
  char *bootargs;
  
  scratch = str_2;
  bootargs = path;
  do {
    err = *scratch;
    if (*bootargs != err) {
      return 1;
    }
    scratch = scratch + 1;
    bootargs = bootargs + 1;
  } while (err != '\0');
  return 0;
}





uint32_t coruna_strncmp(long handle,long addr_2,unsigned long arg)
{
  unsigned long scratch;
  
  scratch = 0;
  while( true ) {
    if (arg <= scratch) {
      return 0;
    }
    if (*(char *)(addr_2 + scratch) != *(char *)(handle + scratch)) break;
    if (*(char *)(addr_2 + scratch) == '\0') {
      return 0;
    }
    scratch = scratch + 1;
  }
  return 1;
}





int coruna_extra0a_stub(int flags,int count_2)
{
  return flags * count_2;
}





void coruna_store_pair(uint32_t size,uint32_t *flags_2,uint64_t val,uint64_t *id_2)
{
  if ((flags_2 != (uint32_t *)0x0) && (id_2 != (uint64_t *)0x0)) {
    *flags_2 = size;
    *id_2 = val;
  }
  return;
}





unsigned long coruna_memmem_scan(int arg,long val,uint64_t n,uint64_t m)

{
  bool count;
  byte *entry_10;
  uint type_id_17;
  byte idx;
  byte i;
  unsigned long type_id_18;
  byte *entry_11;
  unsigned long tag;
  unsigned long type_id_19;
  unsigned long type_id_20;
  byte *entry_12;
  byte *entry_13;
  uint32_t type_id_21;
  unsigned long type_id_22;
  long ctx_val;
  unsigned long type_id_23;
  long serial;
  uint64_t region;
  byte *plist;
  uint url_buf;
  uint *data;
  
  if (arg == 1) {
    entry_13 = (byte *)(*(long *)(val + 0x68) +
                      (unsigned long)*(uint *)(*(long *)(val + 0x20) + 0x20));
    data = (uint *)(*(long *)(val + 0x20) + 0x24);
  }
  else {
    if (arg != 0) {
      return 0x910008;
    }
    entry_13 = (byte *)(*(long *)(val + 0x68) +
                      (unsigned long)*(uint *)(*(long *)(val + 0x20) + 0x10));
    data = (uint *)(*(long *)(val + 0x20) + 0x14);
  }
  type_id_18 = (unsigned long)*data;
  if (*data != 0) {
    region = 0;
    plist = (byte *)0x0;
    ctx_val = 0;
    type_id_22 = 0;
    type_id_23 = 0;
    serial = 0;
    entry_10 = entry_13 + type_id_18;
    url_buf = 1;
    do {
      entry_12 = entry_13 + 1;
      idx = *entry_13;
      entry_13 = entry_12;
      if ((idx >> 4) - 1 < 0xd) {
        type_id_17 = idx & 0xf;
        type_id_18 = (unsigned long)type_id_17;
        type_id_21 = (uint32_t)type_id_22;
        switch((uint)(idx >> 4)) {
        default:
          type_id_22 = type_id_18;
          break;
        case 2:
          type_id_22 = 0;
          type_id_18 = 0;
          entry_11 = entry_12;
          do {
            if (entry_10 <= entry_11) {
              type_id_22 = 0;
              entry_13 = entry_12;
              break;
            }
            entry_13 = entry_11 + 1;
            idx = *entry_11;
            type_id_20 = ((unsigned long)idx & 0x7f) << (type_id_18 & 0x3f);
            if (0x3f < (uint)type_id_18) {
              type_id_20 = 0;
            }
            type_id_22 = type_id_20 | type_id_22;
            type_id_18 = (unsigned long)((uint)type_id_18 + 7);
            entry_11 = entry_13;
          } while ((char)idx < '\0');
          break;
        case 3:
          type_id_17 = 0;
          if ((idx & 0xf) != 0) {
            type_id_17 = (int)(char)idx | 0xfffffff0;
          }
          type_id_22 = (unsigned long)type_id_17;
          break;
        case 4:
          entry_11 = entry_12;
          do {
            if (entry_11 == entry_10) {
              plist = (byte *)0x0;
              entry_13 = entry_12;
              break;
            }
            entry_13 = entry_11 + 1;
            i = *entry_11;
            entry_11 = entry_13;
            plist = entry_12;
          } while (i != 0);
          region = (unsigned long)coruna_u64_pack14((idx), ((uint32_t))region) & 0xfffffffff;
          break;
        case 5:
          url_buf = type_id_17;
          break;
        case 6:
          type_id_23 = 0;
          type_id_18 = 0;
          entry_11 = entry_12;
          do {
            if (entry_10 <= entry_11) {
              type_id_23 = 0;
              entry_13 = entry_12;
              goto load_ok_34;
            }
            entry_13 = entry_11 + 1;
            idx = *entry_11;
            type_id_20 = ((unsigned long)idx & 0x7f) << (type_id_18 & 0x3f);
            if (0x3f < (uint)type_id_18) {
              type_id_20 = 0;
            }
            type_id_23 = type_id_20 | type_id_23;
            type_id_18 = (unsigned long)((uint)type_id_18 + 7);
            entry_11 = entry_13;
          } while ((char)idx < '\0');
          if ((idx & 0x40) != 0) {
            type_id_23 = 0xffffffffffffffff;
          }
          break;
        case 7:
          serial = coruna_macho_seg_by_index(type_id_18,val);
          if (serial == 0) {
            return 0x910009;
          }
          type_id_18 = 0;
          type_id_20 = 0;
          entry_11 = entry_12;
          do {
            if (entry_10 <= entry_11) {
              type_id_18 = 0;
              entry_13 = entry_12;
              break;
            }
            entry_13 = entry_11 + 1;
            idx = *entry_11;
            tag = ((unsigned long)idx & 0x7f) << (type_id_20 & 0x3f);
            if (0x3f < (uint)type_id_20) {
              tag = 0;
            }
            type_id_18 = tag | type_id_18;
            type_id_20 = (unsigned long)((uint)type_id_20 + 7);
            entry_11 = entry_13;
          } while ((char)idx < '\0');
          serial = serial + type_id_18;
          break;
        case 8:
          type_id_18 = 0;
          type_id_20 = 0;
          entry_11 = entry_12;
          do {
            if (entry_10 <= entry_11) {
              type_id_18 = 0;
              entry_13 = entry_12;
              break;
            }
            entry_13 = entry_11 + 1;
            idx = *entry_11;
            tag = ((unsigned long)idx & 0x7f) << (type_id_20 & 0x3f);
            if (0x3f < (uint)type_id_20) {
              tag = 0;
            }
            type_id_18 = tag | type_id_18;
            type_id_20 = (unsigned long)((uint)type_id_20 + 7);
            entry_11 = entry_13;
          } while ((char)idx < '\0');
          serial = serial + type_id_18;
          break;
        case 9:
          type_id_18 = coruna_libcache_init_dispatch(serial,plist,region,url_buf,type_id_23,n,m,
                               val,type_id_21);
          if ((int)type_id_18 != 0) {
            return type_id_18;
          }
          serial = serial + 8;
          break;
        case 10:
          type_id_18 = coruna_libcache_init_dispatch(serial,plist,region,url_buf,type_id_23,n,m,
                               val,type_id_21);
          if ((int)type_id_18 != 0) {
            return type_id_18;
          }
          type_id_18 = 0;
          type_id_20 = 0;
          entry_11 = entry_12;
          do {
            if (entry_10 <= entry_11) {
              type_id_18 = 0;
              entry_13 = entry_12;
              break;
            }
            entry_13 = entry_11 + 1;
            idx = *entry_11;
            tag = ((unsigned long)idx & 0x7f) << (type_id_20 & 0x3f);
            if (0x3f < (uint)type_id_20) {
              tag = 0;
            }
            type_id_18 = tag | type_id_18;
            type_id_20 = (unsigned long)((uint)type_id_20 + 7);
            entry_11 = entry_13;
          } while ((char)idx < '\0');
          serial = type_id_18 + serial + 8;
          break;
        case 0xb:
          type_id_20 = coruna_libcache_init_dispatch(serial,plist,region,url_buf,type_id_23,n,m,
                                val,type_id_21);
          if ((int)type_id_20 != 0) {
            return type_id_20;
          }
          type_id_18 = coruna_extra0a_stub(type_id_18,8);
          serial = serial + (type_id_18 & 0xffffffff) + 8;
          break;
        case 0xc:
          type_id_20 = 0;
          type_id_18 = 0;
          do {
            if (entry_10 <= entry_13) {
              type_id_20 = 0;
              entry_11 = entry_12;
              break;
            }
            entry_11 = entry_13 + 1;
            idx = *entry_13;
            tag = ((unsigned long)idx & 0x7f) << (type_id_18 & 0x3f);
            if (0x3f < (uint)type_id_18) {
              tag = 0;
            }
            type_id_20 = tag | type_id_20;
            type_id_18 = (unsigned long)((uint)type_id_18 + 7);
            entry_13 = entry_11;
          } while ((char)idx < '\0');
          type_id_18 = 0;
          tag = 0;
          entry_12 = entry_11;
          do {
            if (entry_10 <= entry_12) {
              type_id_18 = 0;
              entry_13 = entry_11;
              break;
            }
            entry_13 = entry_12 + 1;
            idx = *entry_12;
            type_id_19 = ((unsigned long)idx & 0x7f) << (tag & 0x3f);
            if (0x3f < (uint)tag) {
              type_id_19 = 0;
            }
            type_id_18 = type_id_19 | type_id_18;
            tag = (unsigned long)((uint)tag + 7);
            entry_12 = entry_13;
          } while ((char)idx < '\0');
          if (type_id_20 != 0) {
            tag = 1;
            do {
              type_id_19 = coruna_libcache_init_dispatch(serial,plist,region,url_buf,type_id_23,n,m
                                    ,val,type_id_21);
              if ((int)type_id_19 != 0) {
                return type_id_19;
              }
              serial = serial + type_id_18 + 8;
              count = tag < type_id_20;
              tag = (unsigned long)((int)tag + 1);
            } while (count);
          }
          break;
        case 0xd:
          if (type_id_17 == 1) {
            if (ctx_val == 0) {
              return 0x910018;
            }
            type_id_18 = coruna_atomic_cas_ptr(val,serial,ctx_val,region & 0xffffffff);
            if ((int)type_id_18 != 0) {
              return type_id_18;
            }
          }
          else {
            if ((idx & 0xf) != 0) {
              return 0x91000d;
            }
            type_id_20 = 0;
            entry_11 = entry_12;
            do {
              if (entry_10 <= entry_11) {
                type_id_20 = 0;
                entry_13 = entry_12;
                goto joined_r0x00007c84;
              }
              entry_13 = entry_11 + 1;
              idx = *entry_11;
              tag = ((unsigned long)idx & 0x7f) << (type_id_18 & 0x3f);
              if (0x3f < (uint)type_id_18) {
                tag = 0;
              }
              type_id_20 = tag | type_id_20;
              type_id_18 = (unsigned long)((uint)type_id_18 + 7);
              entry_11 = entry_13;
            } while ((char)idx < '\0');
            if (type_id_20 >> 0x10 != 0) {
              return 0x91000f;
            }
joined_r0x00007c84:
            if (ctx_val != 0) {
              coruna_wipe_and_map(m,ctx_val,(region & 0xffffffff) << 3);
              region = (unsigned long)region << 0x20;
            }
            if (type_id_20 == 0) {
              serial = 0;
              ctx_val = 0;
            }
            else {
              ctx_val = coruna_anon_mmap(m,type_id_20 << 3);
              if (ctx_val == 0) {
                return 0xad009;
              }
              coruna_memset_pattern(ctx_val,0,type_id_20 << 3);
              region = coruna_u64_pack((region), (int)type_id_20);
              serial = ctx_val;
            }
          }
        }
      }
load_ok_34:
    } while (entry_13 < entry_10);
    if (ctx_val != 0) {
      coruna_wipe_and_map(m,ctx_val,(region & 0xffffffff) << 3);
    }
    type_id_18 = 0;
  }
  return type_id_18;
}





unsigned long coruna_load_javascriptcore(long arg,long val)

{
  int *idx;
  uint8_t *ptr;
  int status;
  bool idx;
  void (*block)(void);
  int flags;
  unsigned long version;
  int *i;
  uint tag;
  int *j;
  long serial_7;
  long serial_8;
  uint kind;
  uint64_t type_id_21;
  long handle;
  long ctx_val;
  uint64_t sa_saved[2];
  void (*region)(void);
  uint64_t plist;
  void (*path_buf)(void);
  
  if (arg == 0) {
    return 0xad001;
  }
  if (val == 0) {
    return 0xad001;
  }
  if (*(char *)(val + 0x5c7) == '\0') {
    return 0;
  }
  serial_8 = *(long *)(val + 0x5d8);
  if (serial_8 == 0) {
    return 0xad001;
  }
  if (*(long *)(val + 0x5d0) == 0) {
    return 0xad001;
  }
  tag = *(uint *)(arg + 0xa8);
  ctx_val = *(long *)(arg + 0x58);
  sa_saved[0] = 0;
  version = coruna_dlsym_resolve(val,"/System/Library/Frameworks/JavaScriptCore.framework/JavaScriptCore",
                       "JSEvaluateScript",sa_saved);
  block = k_extra_loader_block_template;
  if ((int)version != 0) {
    return version;
  }
  handle = 0;
  kind = 0;
  ctx_val = ctx_val - serial_8;
  region = k_extra_loader_region_hint;
  plist = coruna_u64_pack((plist), (k_extra_loader_size_hint));
  do {
    serial_8 = coruna_identity(sa_saved[0]);
    idx = (int *)(serial_8 + 0xc00000);
    i = (int *)coruna_identity(sa_saved[0]);
    if (i < idx && i != (int *)0x0) {
      while (i = (int *)coruna_memscan_match(i,(long)idx - (long)i,
                                          (long)&region + handle * 4,4), i != (int *)0x0) {
        path_buf = block;
        serial_8 = coruna_memscan_match(i,0x1000,&path_buf,8);
        if (serial_8 != 0) {
          if (handle == 0) {
            path_buf = (void (*)0x0;
            version = coruna_dlsym_resolve(val,"/usr/lib/system/libsystem_c.dylib","sigaction",&path_buf);
            if ((int)version != 0) {
              return version;
            }
            handle = coruna_mmap(0,0x8000,3,&k_extra_mmap_anon_fd,0,0);
            if (handle == -1) {
              return 0x15001;
            }
            flags = *(int *)(val + 0xe0);
            if (((flags == -0x789a1216) || (flags == -0x25cc27c3)) || (flags == 0x2876f5b5)) {
              type_id_21 = 0xb;
              idx = true;
load_ok_35:
              block = path_buf;
              coruna_memset_pattern(&region,0,0x10);
              region = coruna_libsystem_copy_state;
              plist = k_extra_loader_map_prot;
              flags = (*block)(type_id_21,&region,sa_saved);
              if (flags == 0) {
                ptr = &k_extra_ctx_slot_tertiary;
                if (idx) {
                  serial_7 = 0;
                }
                else {
                  ptr = &k_extra_ctx_slot_primary;
                  serial_7 = *(long *)(val + 0x5d0);
                }
                *(long *)(handle + 0x330) = serial_8;
                *(uint64_t *)(handle + 0x338) = *(uint64_t *)(val + 0x5d0);
                if (tag == 0) goto load_ok_36;
                version = 0;
                serial_8 = *(long *)(val + 0x5d0);
                goto load_ok_37;
              }
              tag = 0x8002;
            }
            else {
              flags = coruna_mprotect(handle + 0x4000,0x4000,0);
              if (flags == 0) {
                idx = false;
                type_id_21 = 10;
                goto load_ok_35;
              }
              tag = 0x8001;
            }
            tag = (tag | 0xfff60000) + 0xad001;
            goto load_ok_38;
          }
          version = 0;
          j = i;
          do {
            if (j[-1] == -0x2efebc01) {
              if (*j == -0x56fda80a) {
                if ((i[2] & 0xffc001e0U) == 0xb90001e0) {
                  kind = (uint)i[2] >> 8 & 0x3ffc;
                  flags = 3;
load_ok_39:
                  if (tag == 0) {
                    return 0;
                  }
                  version = 0;
                  handle = *(long *)(val + 0x5d0);
                  do {
                    status = *(int *)(*(long *)(val + 0x5d8) + ctx_val + version);
                    i = (int *)(handle + ctx_val + version);
                    if (status != *i) {
                      if (flags - 1U < 4) {
                        switch(flags) {
                        default:
                          coruna_svc_indirect_extra_0(serial_8,status);
                          break;
                        case 2:
                          coruna_svc_indirect_extra_3(serial_8,status,i,kind);
                          break;
                        case 3:
                          coruna_svc_indirect_extra_4(serial_8,status,i,kind);
                          break;
                        case 4:
                          coruna_svc_indirect_extra_1(serial_8,status,i,kind);
                        }
                      }
                      handle = *(long *)(val + 0x5d0);
                      if (status != *(int *)(handle + ctx_val + version)) {
                        return 0x15005;
                      }
                    }
                    version = version + 4;
                    if (tag <= version) {
                      return 0;
                    }
                  } while( true );
                }
                break;
              }
              if (*j == -0x56fea008) {
                if ((i[2] & 0xffc001e0U) == 0xb90001e0) {
                  kind = (uint)i[2] >> 8 & 0x3ffc;
                  flags = 2;
                  goto load_ok_39;
                }
                break;
              }
            }
            else if (j[-1] == -0x2efefc01) {
              if (*j == -0x56fea80a) {
                kind = 0;
                flags = 1;
                goto load_ok_39;
              }
              if (*j == -0x56fdb00c) {
                if ((i[2] & 0xffc001e0U) == 0xb90001e0) {
                  kind = (uint)i[2] >> 8 & 0x3ffc;
                  flags = 4;
                  goto load_ok_39;
                }
                break;
              }
            }
            version = version + 4;
            j = j + -1;
          } while (version < 0xed);
        }
        i = i + 1;
        if ((idx <= i) || (i == (int *)0x0)) break;
      }
      kind = 0x15004;
    }
    handle = handle + 1;
    if (handle == 3) {
      tag = 0x15006;
      if (kind != 0) {
        tag = kind;
      }
      return (unsigned long)tag;
    }
  } while( true );
load_ok_37:
  do {
    flags = *(int *)(*(long *)(val + 0x5d8) + ctx_val + version);
    if (flags != *(int *)(serial_8 + ctx_val + version)) {
      coruna_store_pair(flags,serial_7 + ctx_val + version,ptr,handle);
      serial_8 = *(long *)(val + 0x5d0);
      if (flags != *(int *)(serial_8 + ctx_val + version)) {
        tag = 0x15005;
        goto load_ok_40;
      }
    }
    version = version + 4;
  } while (version < tag);
load_ok_36:
  tag = 0;
load_ok_40:
  flags = (*block)(type_id_21,sa_saved,0);
  if (flags != 0) {
    tag = 0x15003;
  }
load_ok_38:
  coruna_munmap(handle,0x8000);
  return (unsigned long)tag;
}





void coruna_wipe_and_map(long handle,uint64_t val,unsigned long arg)
{
  long handle;
  void (*ptr)(void);
  unsigned long unaff_x30;
  
  if (*(char *)(handle + 0x5c2) != '\0') {
    coruna_memset_pattern(val,0,arg);
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
    coruna_munmap(val,arg);
    return;
  }
  if (*(char *)(handle + 0x5c5) != '\0') {
    handle = 0;
    if ((arg & 0x3fff) != 0) {
      handle = 0x4000 - (arg & 0x3fff);
    }
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
    coruna_mach_memory_entry(handle,val,handle + arg,*(uint32_t *)(handle + 0x5c8));
    return;
  }
  if (*(void (**)(handle + 0xb0) == (void (*)0x0) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  (**(void (**)(handle + 0xb0))(handle,val,arg);
  return;
}





long coruna_anon_mmap(long handle,uint64_t val)
{
  void (*ptr)(void);
  long handle;
  long addr;
  unsigned long unaff_x30;
  
  if (*(char *)(handle + 0x5c2) != '\0') {
    handle = coruna_mmap(0,val,3,&k_extra_mmap_anon_fd,0,0);
    addr = 0;
    if (handle != -1) {
      addr = handle;
    }
    return addr;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  addr = coruna_map_size_round(handle,val,0);
  return addr;
}





unsigned long coruna_map_size_round(long arg,unsigned long val,unsigned long n)

{
  long serial_9;
  int count;
  unsigned long type_id_17;
  unsigned long type_id_24;
  
  type_id_24 = val;
  if ((*(char *)(arg + 0x5c2) == '\0') &&
     (((n & 1) != 0 || (*(char *)(arg + 0x5c5) != '\0')))) {
    type_id_24 = val + 0x4000;
  }
  while (type_id_17 = (**(void (**)(arg + 0x28))(arg,type_id_24), type_id_17 == 0) {
    if ((*(void (**)(arg + 0x128) == (void (*)0x0) ||
       (count = (**(void (**)(arg + 0x128))(arg,type_id_24), count != 0)) {
      return -(n & 1);
    }
  }
  if (*(char *)(arg + 0x5c2) != '\0') {
    return type_id_17;
  }
  if ((((n & 1) != 0) || (*(char *)(arg + 0x5c5) != '\0')) && ((type_id_17 & 0x3fff) != 0)) {
    type_id_17 = type_id_17 + 0x4000 & 0xffffffffffffc000;
  }
  if (*(char *)(arg + 0x5c5) == '\0') {
    return type_id_17;
  }
  serial_9 = 0;
  if ((val & 0x3fff) != 0) {
    serial_9 = 0x4000 - (val & 0x3fff);
  }
  count = coruna_mach_memory_entry(arg,type_id_17,serial_9 + val,3);
  if (count == 0) {
    return type_id_17;
  }
  return -(n & 1);
}





uint64_t coruna_mach_memory_entry(uint64_t *val,long handle,unsigned long arg,uint64_t id_2)
{
  uint32_t u;
  int err;
  long handle;
  uint32_t *ptr;
  void (*ptr)(void);
  void (*buf)(void);
  void (*str)(void);
  void (*copy)(void);
  void (*data)(void);
  long addr;
  uint64_t size;
  unsigned long unaff_x30;
  uint32_t scratch;
  unsigned long bootargs;
  uint64_t thread_attr;
  long host_info;
  unsigned long serial_buf;
  
  if (*(char *)((long)val + 0x5c2) == '\0') {
    if (*(char *)((long)val + 0x5c5) == '\0') {
      if (*(char *)((long)val + 0x5c1) == '\0') {
        return 0;
      }
      if (*(char *)((long)val + 0x5c4) != '\0') {
        return 0;
      }
      if (*(char *)((long)val + 0x5c7) != '\0') {
        return 0;
      }
      if (((uint)id_2 >> 2 & 1) != 0) {
        return 0;
      }
      id_2 = 3;
    }
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
      size = coruna_mprotect(handle,arg,id_2);
      return size;
    }
    ___stack_chk_fail();
}
  if (((uint)id_2 >> 2 & 1) == 0) {
    return 0;
  }
  bootargs = 0;
  thread_attr = 0;
  scratch = 0;
  if (handle == 0) {
    return 0xfffffffe;
  }
  if (arg == 0) {
    return 0xfffffffe;
  }
  handle = (*(void (*)*val)("/usr/lib/system/libsystem_kernel.dylib",1);
  if (handle == 0) {
    return 0xfffffffd;
  }
  ptr = (uint32_t *)(*(void (*)val[1])(handle,"mach_task_self_");
  if (ptr == (uint32_t *)0x0) {
    size = 0xfffffffc;
  }
  else {
    ptr = (void (*)(*(void (*)val[1])(handle,"mach_make_memory_entry_64");
    if (ptr == (void (*)0x0) {
      size = 0xfffffffb;
    }
    else {
      buf = (void (*)(*(void (*)val[1])(handle,"vm_map");
      if (buf == (void (*)0x0) {
        size = 0xfffffffa;
      }
      else {
        str = (void (*)(*(void (*)val[1])(handle,"vm_deallocate");
        if (str == (void (*)0x0) {
          size = 0xfffffff9;
        }
        else {
          copy = (void (*)(*(void (*)val[1])(handle,"mach_port_deallocate");
          if (copy == (void (*)0x0) {
            size = 0xfffffff8;
          }
          else {
            data = (void (*)(*(void (*)val[1])(handle,"posix_madvise");
            if (data == (void (*)0x0) {
              size = 0xfffffff7;
            }
            else {
              u = *ptr;
              serial_buf = arg;
              err = (*ptr)(u,&serial_buf,handle,3,&scratch,0);
              if (err == 0) {
                host_info = handle;
                err = (*buf)(u,&host_info,arg,0,&fail,scratch,0,0,0x300000003,1
                                 );
                if (err == 0) {
                  (*data)(host_info,arg,3);
                  err = (*buf)(u,&thread_attr,arg,0,1,scratch,0,1,0x300000003,1);
                  if (err == 0) {
                    err = (*buf)(u,&bootargs,arg,0,1,scratch,0,0,0x100000001,1);
                    if (err == 0) {
                      err = coruna_mlock(bootargs,arg);
                      if (err == 0) {
                        addr = 0;
                        do {
                          if (*(long *)((long)val + addr + 0x600) == 0) {
                            *(unsigned long *)((long)val + addr + 0x600) = bootargs | arg >> 0xe;
                            break;
                          }
                          addr = addr + 8;
                        } while (addr != 0x40);
                        (*str)(u,thread_attr,arg);
                        (*copy)(u,scratch);
                        size = 0;
                      }
                      else {
                        size = 0xfffffff2;
                      }
                    }
                    else {
                      size = 0xfffffff3;
                    }
                  }
                  else {
                    size = 0xfffffff4;
                  }
                }
                else {
                  size = 0xfffffff5;
                }
              }
              else {
                size = 0xfffffff6;
              }
            }
          }
        }
      }
    }
  }
  (*(void (*)val[3])(handle);
  return size;
}





uint64_t coruna_macho_walk_segments(long *handle,unsigned long arg,long *addr_2)
{
  long handle;
  long addr;
  int err;
  uint64_t u;
  unsigned long size;
  uint version;
  int *err;
  
  u = 0xad001;
  if ((handle != (long *)0x0) && (addr_2 != (long *)0x0)) {
    if (*(int *)(*handle + 0x10) != 0) {
      version = 0;
      handle = handle[10];
      addr = handle[0xb];
      err = (int *)(handle[0xd] + 0x20);
      do {
        if ((((*err == 0x19) && (*(long *)(err + 0xc) != 0)) &&
            (err = coruna_strncmp(err + 2,"__PAGEZERO",0xb), err != 0)) &&
           ((*(unsigned long *)(err + 10) <= arg &&
            (size = arg - *(unsigned long *)(err + 10), size < *(unsigned long *)(err + 0xc))))) {
          *addr_2 = (addr - handle) + size + *(long *)(err + 6);
          return 0;
        }
        err = (int *)((long)err + (unsigned long)(uint)err[1]);
        version = version + 1;
      } while (version < *(uint *)(*handle + 0x10));
    }
    u = 0xad011;
  }
  return u;
}





uint64_t coruna_init_libcache(char *path,long handle,uint64_t *val,long *addr_2,uint size)
{
  char *ptr;
  uint u;
  uint size;
  bool err;
  int err;
  long handle;
  long addr;
  uint version;
  
  if (((((path != (char *)0x0) && (handle != 0)) && (val != (uint64_t *)0x0)) &&
      ((addr_2 != (long *)0x0 && (size != 0)))) && (size != 0xfffffffe)) {
    if (size == 0xffffffff) {
      addr = -5;
    }
    else if ((((int)size < 1) || (*(uint *)(handle + 0x200) < size)) ||
            (addr = *(long *)(handle + (unsigned long)(size - 1) * 8), addr == 0)) goto fail;
    (*(void (*)val[4])();
    ptr = path;
    if (*path == '_') {
      ptr = path + 1;
    }
    addr = (*(void (*)val[1])(addr,ptr);
    (*(void (*)val[4])();
    *addr_2 = addr;
    if (addr != 0) {
      return 0;
    }
  }
fail:
  addr = (*(void (*)*val)("/usr/lib/system/libcache.dylib",0x12);
  if (addr != 0) {
    (*(void (*)val[4])();
    ptr = path;
    if (*path == '_') {
      ptr = path + 1;
    }
    handle = (*(void (*)val[1])(addr,ptr);
    (*(void (*)val[4])();
    (*(void (*)val[3])(addr);
    if (handle != 0) goto done;
  }
  u = *(uint *)(handle + 0x204);
  size = *(uint *)(handle + 0x200);
  version = u;
  if (size <= u) {
    version = 0;
  }
  if (version < size) {
    err = u < size;
    do {
      addr = *(long *)(handle + (unsigned long)version * 8);
      if (addr != 0) {
        (*(void (*)val[4])();
        ptr = path;
        if (*path == '_') {
          ptr = path + 1;
        }
        handle = (*(void (*)val[1])(addr,ptr);
        (*(void (*)val[4])();
        if (handle != 0) {
          *(uint *)(handle + 0x204) = version;
          goto done;
        }
      }
      if (err) {
        version = (uint)(version == 0);
        *(uint32_t *)(handle + 0x204) = 0;
      }
      else {
        version = version + 1;
      }
      err = false;
    } while (version < *(uint *)(handle + 0x200));
  }
  err = coruna_strcmp(path,"dyld_stub_binder");
  if (err == 0) {
    handle = 0xdeadbeef;
  }
  else {
    err = coruna_strcmp(path,"__objc_empty_vtable");
    if ((err != 0) && (err = coruna_strcmp(path,"_objc_readClassPair"), err != 0)) {
      return 0x910006;
    }
    handle = 0;
  }
done:
  *addr_2 = handle;
  return 0;
}





uint64_t
uint64_t coruna_macho_reloc_apply(int64_t arg,int64_t arg,uint64_t val,int64_t val,int flags,uint size)
{
  unsigned long u;
  short ls2;
  uint64_t size;
  unsigned long version;
  unsigned long port;
  uint64_t tag;
  unsigned long scratch;
  unsigned long bootargs;
  long thread_attr;
  
  size = 0xad001;
  if ((arg != 0) && (arg != 0)) {
    scratch = 0;
    size = coruna_macho_walk_segments(arg,*(long *)(arg + 8) + (unsigned long)size +
                                 (unsigned long)((uint)*(ushort *)(arg + 4) * flags),&scratch);
    if ((int)size == 0) {
      tag = 0x920006;
      ls2 = *(short *)(arg + 6);
      if ((ls2 == 6) || (ls2 == 2)) {
        size = 0xad001;
        if ((scratch != 0) &&
           ((size = tag, *(unsigned long *)(arg + 0x58) <= scratch &&
            (port = scratch,
            scratch < *(unsigned long *)(arg + 0x58) + (unsigned long)*(uint *)(arg + 0xa8))))) {
          do {
            thread_attr = 0;
            coruna_memcpy_bytes(&bootargs,port,8);
            if ((long)bootargs < 0) {
              if ((uint)val <= ((uint)bootargs & 0xffffff)) {
                return 0x920001;
              }
              thread_attr = *(long *)(val + (bootargs & 0xffffff) * 8) + (bootargs >> 0x18 & 0xff);
            }
            else {
              u = bootargs & 0xfffffffff | (bootargs >> 0x24) << 0x38;
              if (ls2 == 2) {
                thread_attr = (u + *(long *)(arg + 0x60)) - *(long *)(arg + 0x50);
              }
              else {
                thread_attr = u + *(long *)(arg + 0x60);
              }
            }
            coruna_memcpy_bytes(port,&thread_attr,8);
            if ((bootargs >> 0x33 & 0xfff) == 0) {
              return 0;
            }
            port = port + (((uint)(bootargs >> 0x33) & 0xfff) << 2);
            version = *(unsigned long *)(arg + 0x58);
            u = version + *(uint *)(arg + 0xa8);
          } while ((port >= version && port <= u) && (port < version || u != port));
        }
      }
      else if (ls2 == 1) {
        size = coruna_atomic_cas_ptr(arg,scratch,val,val);
      }
      else {
        size = 0x920005;
      }
    }
  }
  return size;
}





uint64_t coruna_atomic_cas_ptr(long handle,unsigned long *arg,long addr_2,uint size)
{
  unsigned long *ptr;
  unsigned long u;
  long handle;
  unsigned long size;
  
  do {
    size = *arg;
    handle = *(long *)(handle + 0x60);
    ptr = arg;
    if (handle != *(long *)(handle + 0x58)) {
      ptr = (unsigned long *)((long)arg + (handle - *(long *)(handle + 0x58)));
    }
    if ((long)size < 0) {
      if ((size >> 0x3e & 1) == 0) {
        handle = handle + (size & 0xffffffff);
      }
      else {
        if (size <= ((uint)size & 0xffff)) {
          return 0x920001;
        }
        handle = *(long *)(addr_2 + (size & 0xffff) * 8);
        u = 0;
        if (handle == 0) goto fail;
      }
      u = size >> 0x20 & 0xffff;
      if ((size & 0x1000000000000) != 0) {
        u = (unsigned long)ptr & 0xffffffffffff | (size >> 0x20) << 0x30;
      }
      u = coruna_identity_switch(handle,size >> 0x31 & 3,u);
    }
    else if ((size >> 0x3e & 1) == 0) {
      u = ((size & 0x7f80000000000) * 0x2000 + handle +
              ((long)(size << 0x15) >> 0x15 & 0xffffffffffffffU)) - *(long *)(handle + 0x50);
    }
    else {
      if (size <= ((uint)size & 0xffff)) {
        return 0x920001;
      }
      u = size >> 0x20 & 0x7ffff;
      if ((size & 0x40000) != 0) {
        u = size >> 0x20 | 0xfffffffffffc0000;
      }
      u = *(long *)(addr_2 + (size & 0xffff) * 8) + u;
    }
fail:
    *arg = u;
    if ((size >> 0x33 & 0x7ff) == 0) {
      return 0;
    }
    arg = arg + ((uint)(size >> 0x33) & 0x7ff);
  } while( true );
}





long coruna_macho_seg_by_index(int flags,long *handle)
{
  int err;
  int status;
  int *err;
  
  err = *(int *)(*handle + 0x10);
  if (err != 0) {
    status = 0;
    err = (int *)(handle[0xd] + 0x20);
    do {
      if (*err == 0x19) {
        if (status == flags) {
          return (handle[0xb] - handle[10]) + *(long *)(err + 6);
        }
        status = status + 1;
      }
      err = (int *)((long)err + (unsigned long)(uint)err[1]);
      err = err + -1;
    } while (err != 0);
  }
  return 0;
}





uint64_t
uint64_t coruna_libcache_init_dispatch(int64_t *arg,int64_t arg,uint size,int flags,int64_t val,uint64_t val, uint64_t id_2,int64_t n,uint32_t size_x)
{
  byte err;
  uint64_t u;
  long scratch;
  
  scratch = 0;
  if (arg == 0) {
    u = 0x91000c;
  }
  else {
    u = coruna_init_libcache(arg,val,id_2,&scratch,size_x);
    if ((int)u == 0x910006 && (size & 1) != 0) {
      val = 0;
      scratch = 0;
    }
    else if ((int)u != 0) {
      return u;
    }
    err = *(byte *)(n + 0xac);
    if ((err >> 6 & 1) != 0) {
      scratch = coruna_identity(scratch);
      err = *(byte *)(n + 0xac);
    }
    if ((err >> 6 & 1) == 0) {
      if (arg < *(long **)(n + 0x58)) {
        return 0x910007;
      }
      if ((long *)((long)*(long **)(n + 0x58) + (unsigned long)*(uint *)(n + 0xa8)) <= arg)
      {
        return 0x910007;
      }
    }
    if (flags == 3) {
      scratch = (((int)val + (int)scratch) - (int)arg) + -4;
    }
    else {
      if (flags != 2) {
        if (flags == 1) {
          *arg = val + scratch;
          return 0;
        }
        return 0;
      }
      scratch = (int)val + (int)scratch;
    }
    u = 0;
    *(int *)arg = (int)scratch;
  }
  return u;
}





uint64_t coruna_dlsym_resolve(uint64_t *val,long handle,long addr_2,long *off_3)
{
  long handle;
  long addr;
  uint64_t u;
  
  u = 0xad001;
  if ((((val != (uint64_t *)0x0) && (handle != 0)) && (addr_2 != 0)) &&
     (off_3 != (long *)0x0)) {
    handle = (*(void (*)*val)(handle,1);
    if (handle == 0) {
      u = 0x1200b;
    }
    else {
      addr = (*(void (*)val[1])(handle,addr_2);
      if (addr == 0) {
        u = 0x12001;
      }
      else {
        u = 0;
        *off_3 = addr;
      }
      (*(void (*)val[3])(handle);
    }
  }
  return u;
}





void coruna_libsystem_copy_state(uint64_t val,uint64_t id_2,long handle)
{
  uint32_t u;
  uint64_t size;
  long handle;
  long addr;
  uint64_t version;
  uint8_t *ptr;
  long off;
  
  handle = *(long *)(handle + 0x30);
  ptr = *(uint8_t **)(handle + 0x20);
  if (ptr != &k_extra_ctx_slot_tertiary) {
    if (ptr == &k_extra_ctx_slot_secondary) {
      if (*(long *)(handle + 0x28) == 0) {
        return;
      }
      coruna_memcpy_bytes(handle,*(long *)(handle + 0x28),0x330);
      addr = coruna_identity(*(uint64_t *)(handle + 0x110));
      *(long *)(handle + 0x110) = addr + 4;
      return;
    }
    if (ptr != &k_extra_ctx_slot_primary) {
      return;
    }
  }
  addr = *(long *)(handle + 0x28);
  if (addr != 0) {
    coruna_memcpy_bytes(addr,handle,0x330);
    version = *(uint64_t *)(addr + 0x330);
    *(uint8_t **)(handle + 0x20) = &k_extra_ctx_slot_secondary;
    *(long *)(handle + 0x108) = addr + 0x3fe0;
    u = *(uint32_t *)(handle + 0x10);
    *(uint32_t *)(addr + 0x3ffc) = u;
    *(uint32_t *)(&k_extra_ctx_field_u32 + addr) = u;
    if (ptr == &k_extra_ctx_slot_tertiary) {
      off = *(long *)(addr + 0x338);
      size = coruna_identity_switch(0x1000,1,&UNK_00004030 + addr);
      *(uint64_t *)(&k_extra_ctx_field_u64 + addr) = size;
      off = *(long *)(handle + 0x18) + off;
    }
    else {
      off = *(long *)(handle + 0x18);
    }
    *(long *)(handle + 0xa8) = off;
    *(uint64_t *)(handle + 0x110) = version;
  }
  return;
}





uint64_t
uint64_t coruna_macho_find_section(uint64_t val,uint64_t id_2,int64_t arg,int64_t *arg,uint64_t *size_3)
{
  uint64_t u;
  int err;
  uint64_t size;
  unsigned long version;
  int *err;
  int *status;
  int *flags;
  int *count;
  int *idx;
  uint port;
  
  size = 0x18006;
  if (*(int *)(arg + 0x10) != 0) {
    status = (int *)0x0;
    port = 0;
    err = (int *)(arg + 0x20);
    count = (int *)0x0;
    do {
      idx = count;
      if ((count != (int *)0x0) && (status != (int *)0x0)) break;
      if (*err == 0x19) {
        err = coruna_strcmp(err + 2,"__TEXT");
        idx = err;
        if (err != 0) {
          idx = count;
        }
        if (status == (int *)0x0) {
          err = coruna_strcmp(err + 2,val);
          if ((err == 0) && (err[0x10] != 0)) {
            version = 0;
            count = err + 0x12;
            flags = (int *)0x0;
            do {
              err = coruna_strcmp(count,id_2);
              status = count;
              if (err != 0) {
                status = flags;
              }
              version = version + 1;
              count = count + 0x14;
              flags = status;
            } while (version < (uint)err[0x10]);
          }
          else {
            status = (int *)0x0;
          }
        }
      }
      err = (int *)((long)err + (unsigned long)(uint)err[1]);
      port = port + 1;
      count = idx;
    } while (port < *(uint *)(arg + 0x10));
    size = 0x18006;
    if ((idx != (int *)0x0) && (status != (int *)0x0)) {
      size = 0;
      u = *(uint64_t *)(status + 10);
      *arg = (arg - *(long *)(idx + 6)) + *(long *)(status + 8);
      *size_3 = u;
    }
  }
  return size;
}
uint64_t
uint64_t coruna_vm_map_fixup(int64_t arg,uint64_t val,uint size,uint64_t id_2,int64_t arg,uint64_t *size_3)
{
  unsigned long u;
  unsigned long size;
  int err;
  long handle;
  long addr;
  unsigned long *ptr;
  unsigned long version;
  unsigned long port;
  uint64_t scratch;
  unsigned long scratch [2];
  unsigned long *bootargs;
  long thread_attr;
  uint8_t host_info[16];
  long serial_buf;
  unsigned long action;
  
  handle = (unsigned long)(size + 1) << 3;
  (*(void (*)k_extra_chkstk_darwin_slot)();
  ptr = (unsigned long *)((long)scratch - (handle + 0xfU & 0xffffffff0));
  coruna_memset_pattern(ptr,0);
  version = (id_2 + arg) - 1;
  if (id_2 <= version) {
    port = 0;
    scratch[1] = (unsigned long)size;
    handle = scratch[1] << 3;
    bootargs = size_3;
    thread_attr = (long)scratch;
    do {
      err = (**(void (**)(arg + 0x10))(version,host_info);
      size = action;
      if ((err != 0) && (action != port)) {
        addr = handle;
        if (size != 0) {
          do {
            *(uint64_t *)((long)ptr + addr) = ((uint64_t *)((long)ptr + addr))[-1];
            addr = addr + -8;
          } while (addr != 0);
        }
        *ptr = size;
        if ((serial_buf != 0) && (err = coruna_strcmp(serial_buf,val), err == 0)) {
          *bootargs = ptr[scratch[1]];
          return 0;
        }
        port = version;
        if (size < id_2 + arg && id_2 <= size) {
          port = size;
        }
        u = version;
        if (size < version) {
          u = port;
        }
        port = 0;
        if (size != 0) {
          version = u;
          port = size;
        }
      }
      version = version - 1;
    } while (id_2 <= version);
  }
  return 0x18005;
}





uint8_t * coruna_stack_probe(long handle,long *addr_2)
{
  uint8_t *ptr;
  long scratch;
  
  ptr = (uint8_t *)(**(void (**)(handle + 0xf8))(handle,0x80000);
  if (((int)ptr == 0) &&
     (ptr = (uint8_t *)(**(void (**)(handle + 0x108))(handle,0x80000,&scratch),
     (int)ptr == 0)) {
    if (scratch == 0) {
      ptr = &fail;
    }
    else {
      *addr_2 = scratch;
      if (*(void (**)(handle + 0x120) != (void (*)0x0) {
        (**(void (**)(handle + 0x120))
                  (handle,*(uint64_t *)(scratch + 0x58),*(uint32_t *)(scratch + 0xa8));
      }
      ptr = (uint8_t *)0x0;
    }
  }
  return ptr;
}





uint8_t * coruna_run_start(long handle,uint64_t val,uint32_t *size)
{
  uint32_t u;
  uint8_t *ptr;
  uint32_t scratch;
  uint64_t bootargs;
  uint32_t thread_attr;
  uint64_t host_info;
  uint64_t serial_buf;
  void (*action)(void);
  
  ptr = (uint8_t *)0xad001;
  host_info = 0;
  serial_buf = 0;
  thread_attr = 0;
  bootargs = 0;
  scratch = 0;
  if (*(long *)(handle + 0x68) != 0) {
    if (((*(int *)(handle + 0x70) != 0) && (*(long *)(handle + 0xb8) != 0)) &&
       (*(long *)(handle + 0x58) != 0)) {
      if (*(long *)(handle + 0x98) != 0) {
        coruna_extra_teardown_helper();
      }
      ptr = (uint8_t *)coruna_lzfse_decode((long *)(handle + 0x68),(int *)(handle + 0x70));
      if ((((((int)ptr == 0) &&
            (ptr = (uint8_t *)
                      (**(void (**)(handle + 0xe8))
                                (handle,0,*(uint64_t *)(handle + 0x68),
                                 *(uint32_t *)(handle + 0x70)), (int)ptr == 0)) &&
           ((ptr = (uint8_t *)
                      (**(void (**)(handle + 0x110))(handle,0xa0003,&host_info,&thread_attr),
            (int)ptr == 0 &&
            ((ptr = (uint8_t *)
                       (**(void (**)(handle + 0x110))(handle,0xa0004,&bootargs,&scratch),
             (int)ptr == 0 &&
             (ptr = (uint8_t *)coruna_vm_map_memory_entry(*(uint64_t *)(handle + 0x58),bootargs,scratch)
             , (int)ptr == 0)))))) &&
          (ptr = (uint8_t *)coruna_vm_map_memory_entry(*(uint64_t *)(handle + 0xb8),host_info,thread_attr),
          (int)ptr == 0)) &&
         ((ptr = (uint8_t *)coruna_stack_probe(handle,&serial_buf), (int)ptr == 0 &&
          (ptr = (uint8_t *)(**(void (**)(handle + 0x38))(handle,serial_buf,"_start",&action)
          , (int)ptr == 0)))) {
        if (action == (void (*)0x0) {
          ptr = &LAB_00005004_1;
        }
        else {
          u = (*action)(handle);
          (**(void (**)(handle + 0x100))(handle,0x80000);
          ptr = (uint8_t *)0x0;
          *size = u;
        }
      }
    }
  }
  return ptr;
}





int _process(void *ctx)
{
  int err;
  uint u;
  int status;
  int flags;
  uint64_t *ptr;
  char *ptr;
  uint64_t *buf;
  void *ptr;
  uint64_t size;
  long handle;
  uint64_t *str;
  void *buf;
  uint64_t version;
  uint64_t port;
  pthread_t p_Stack_98;
  pthread_attr_t scratch;
  
  if (ctx == (void *)0x0) {
    return 0xad001;
  }
  handle = *(long *)((long)ctx + 0x88);
  if (handle == 0) {
    return 0xad001;
  }
  err = *(int *)((long)ctx + 0x90);
  if (err == 0) {
    return 0xad001;
  }
  *(uint64_t *)((long)ctx + 0x88) = 0;
  *(uint32_t *)((long)ctx + 0x90) = 0;
  status = coruna_extra_bind_helper(ctx);
  if (((status == 0) && (status = coruna_find_webcontent(ctx), status == 0)) &&
     (status = coruna_is_mobilestore_ua(ctx), status == 0)) {
    flags = 0xad009;
    ptr = _malloc(0x648);
    status = 0xad009;
    if (ptr != (uint64_t *)0x0) {
      _memcpy(ptr,ctx,0x648);
      status = flags;
      if ((char *)ptr[0x10] != (char *)0x0) {
        ptr = _strdup((char *)ptr[0x10]);
        if (ptr == (char *)0x0) goto fail;
        ptr[0x10] = ptr;
      }
      str = (uint64_t *)ptr[0x13];
      if (str != (uint64_t *)0x0) {
        buf = _malloc(0x20);
        if (buf == (uint64_t *)0x0) goto fail;
        size = *str;
        port = str[3];
        version = str[2];
        buf[1] = str[1];
        *buf = size;
        buf[3] = port;
        buf[2] = version;
        ptr[0x13] = buf;
      }
      if ((char *)ptr[0xf] != (char *)0x0) {
        ptr = _strdup((char *)ptr[0xf]);
        if (ptr == (char *)0x0) goto fail;
        ptr[0xf] = ptr;
      }
      if ((char *)ptr[0x14] != (char *)0x0) {
        ptr = _strdup((char *)ptr[0x14]);
        if (ptr == (char *)0x0) goto fail;
        ptr[0x14] = ptr;
      }
      if ((char *)ptr[0x15] != (char *)0x0) {
        ptr = _strdup((char *)ptr[0x15]);
        if (ptr == (char *)0x0) goto fail;
        ptr[0x15] = ptr;
      }
      buf = (void *)ptr[0xd];
      if ((buf != (void *)0x0) && (u = *(uint *)(ptr + 0xe), u != 0)) {
        ptr = _malloc((unsigned long)u);
        if (ptr == (void *)0x0) goto fail;
        _memcpy(ptr,buf,(unsigned long)u);
        ptr[0xd] = ptr;
      }
      coruna_libsystem_vtable_init(ptr);
      size = coruna_identity(ptr[1]);
      ptr[1] = size;
      size = coruna_identity(ptr[2]);
      ptr[2] = size;
      size = coruna_identity(*ptr);
      *ptr = size;
      size = coruna_identity(ptr[3]);
      ptr[3] = size;
      size = coruna_identity(ptr[4]);
      ptr[4] = size;
      flags = _pthread_attr_init(&scratch);
      status = 0x1d001;
      if (flags == 0) {
        flags = _pthread_attr_setdetachstate(&scratch,2);
        status = 0x1d001;
        if (flags == 0) {
          flags = _pthread_create(&p_Stack_98,&scratch,(void **)coruna_run_start_dispatch,ptr);
          status = 0;
          if (flags != 0) {
            status = 0x1d002;
          }
        }
        _pthread_attr_destroy(&scratch);
      }
    }
  }
fail:
  scratch.__sig = err;
  flags = coruna_vm_map_memory_entry(handle,&scratch,4);
  err = flags;
  if (status != 0) {
    err = status;
  }
  if (flags != 0) {
    status = err;
  }
  return status;
}





int coruna_run_start_dispatch(long handle,uint64_t val)
{
  uint8_t *ptr;
  uint8_t *buf;
  uint8_t *str;
  int err;
  int status;
  unsigned long u;
  long handle;
  int scratch;
  
  scratch = 0xad000;
  if ((*(long *)(handle + 0x68) == 0) || (*(int *)(handle + 0x70) == 0)) {
    status = 0;
  }
  else {
    err = coruna_run_start(handle,val,&scratch);
    status = scratch;
    str = k_extra_vm_page_shift_slot;
    buf = k_extra_vm_page_mask_slot;
    ptr = k_extra_mach_task_self_slot;
    handle = 0;
    do {
      u = *(unsigned long *)(handle + 0x600 + handle);
      if (u != 0) {
        _vm_deallocate(*(vm_map_t *)ptr,u & (*(unsigned long *)buf ^ 0xffffffffffffffff),
                       (*(unsigned long *)buf & u) << ((unsigned long)*(uint *)str & 0x3f));
        *(uint64_t *)(handle + 0x600 + handle) = 0;
      }
      handle = handle + 8;
    } while (handle != 0x40);
    if (err != 0) {
      status = err;
    }
  }
  if (*(char *)(handle + 0x5ec) != '\0') {
    _exit(0);
  }
  return status;
}



coruna_svc_regpack_t coruna_extra0a_svc_pack(uint64_t arg)

{
  bool in_CY;
  uint64_t u;
  uint8_t u[16];
  uint64_t type_id_25;
  
  CallSupervisor(0x80);
  u = arg;
  type_id_25 = 0;
  if (in_CY) {
    u = 0xffffffffffffffff;
    type_id_25 = arg;
  }
  u = type_id_25;
  u = u;
  return u;
}



coruna_svc_regpack_t coruna_extra0a_svc_pack_2(uint64_t arg)

{
  bool in_CY;
  uint64_t u;
  uint8_t u[16];
  uint64_t type_id_25;
  
  CallSupervisor(0x80);
  u = arg;
  type_id_25 = 0;
  if (in_CY) {
    u = 0xffffffffffffffff;
    type_id_25 = arg;
  }
  u = type_id_25;
  u = u;
  return u;
}



coruna_svc_regpack_t coruna_extra0a_svc_pack_3(uint64_t arg)

{
  bool in_CY;
  uint64_t u;
  uint8_t u[16];
  uint64_t type_id_25;
  
  CallSupervisor(0x80);
  u = arg;
  type_id_25 = 0;
  if (in_CY) {
    u = 0xffffffffffffffff;
    type_id_25 = arg;
  }
  u = type_id_25;
  u = u;
  return u;
}



coruna_svc_regpack_t coruna_extra0a_svc_pack_4(uint64_t arg)

{
  bool in_CY;
  uint64_t u;
  uint8_t u[16];
  uint64_t type_id_25;
  
  CallSupervisor(0x80);
  u = arg;
  type_id_25 = 0;
  if (in_CY) {
    u = 0xffffffffffffffff;
    type_id_25 = arg;
  }
  u = type_id_25;
  u = u;
  return u;
}



coruna_svc_regpack_t coruna_extra0a_svc_pack_5(uint64_t arg)

{
  bool in_CY;
  uint64_t u;
  uint8_t u[16];
  uint64_t type_id_25;
  
  CallSupervisor(0x80);
  u = arg;
  type_id_25 = 0;
  if (in_CY) {
    u = 0xffffffffffffffff;
    type_id_25 = arg;
  }
  u = type_id_25;
  u = u;
  return u;
}



coruna_svc_regpack_t coruna_munmap(uint64_t arg)

{
  bool in_CY;
  uint64_t u;
  uint8_t u[16];
  uint64_t type_id_25;
  
  CallSupervisor(0x80);
  u = arg;
  type_id_25 = 0;
  if (in_CY) {
    u = 0xffffffffffffffff;
    type_id_25 = arg;
  }
  u = type_id_25;
  u = u;
  return u;
}



coruna_svc_regpack_t coruna_mprotect(uint64_t arg)

{
  bool in_CY;
  uint64_t u;
  uint8_t u[16];
  uint64_t type_id_25;
  
  CallSupervisor(0x80);
  u = arg;
  type_id_25 = 0;
  if (in_CY) {
    u = 0xffffffffffffffff;
    type_id_25 = arg;
  }
  u = type_id_25;
  u = u;
  return u;
}



coruna_svc_regpack_t coruna_extra0a_svc_pack_8(uint64_t arg)

{
  bool in_CY;
  uint64_t u;
  uint8_t u[16];
  uint64_t type_id_25;
  
  CallSupervisor(0x80);
  u = arg;
  type_id_25 = 0;
  if (in_CY) {
    u = 0xffffffffffffffff;
    type_id_25 = arg;
  }
  u = type_id_25;
  u = u;
  return u;
}



coruna_svc_regpack_t coruna_extra0a_svc_pack_9(uint64_t arg)

{
  bool in_CY;
  uint64_t u;
  uint8_t u[16];
  uint64_t type_id_25;
  
  CallSupervisor(0x80);
  u = arg;
  type_id_25 = 0;
  if (in_CY) {
    u = 0xffffffffffffffff;
    type_id_25 = arg;
  }
  u = type_id_25;
  u = u;
  return u;
}



coruna_svc_regpack_t coruna_extra0a_svc_pack_10(uint64_t arg)

{
  bool in_CY;
  uint64_t u;
  uint8_t u[16];
  uint64_t type_id_25;
  
  CallSupervisor(0x80);
  u = arg;
  type_id_25 = 0;
  if (in_CY) {
    u = 0xffffffffffffffff;
    type_id_25 = arg;
  }
  u = type_id_25;
  u = u;
  return u;
}



coruna_svc_regpack_t coruna_mmap(uint64_t arg)

{
  bool in_CY;
  uint64_t u;
  uint8_t u[16];
  uint64_t type_id_25;
  
  CallSupervisor(0x80);
  u = arg;
  type_id_25 = 0;
  if (in_CY) {
    u = 0xffffffffffffffff;
    type_id_25 = arg;
  }
  u = type_id_25;
  u = u;
  return u;
}



coruna_svc_regpack_t coruna_mlock(uint64_t arg)

{
  bool in_CY;
  uint64_t u;
  uint8_t u[16];
  uint64_t type_id_25;
  
  CallSupervisor(0x80);
  u = arg;
  type_id_25 = 0;
  if (in_CY) {
    u = 0xffffffffffffffff;
    type_id_25 = arg;
  }
  u = type_id_25;
  u = u;
  return u;
}



coruna_svc_regpack_t coruna_extra0a_svc_pack_13(uint64_t arg)

{
  bool in_CY;
  uint64_t u;
  uint8_t u[16];
  uint64_t type_id_25;
  
  CallSupervisor(0x80);
  u = arg;
  type_id_25 = 0;
  if (in_CY) {
    u = 0xffffffffffffffff;
    type_id_25 = arg;
  }
  u = type_id_25;
  u = u;
  return u;
}



coruna_svc_regpack_t coruna_extra0a_svc_pack_14(uint64_t arg)

{
  bool in_CY;
  uint64_t u;
  uint8_t u[16];
  uint64_t type_id_25;
  
  CallSupervisor(0x80);
  u = arg;
  type_id_25 = 0;
  if (in_CY) {
    u = 0xffffffffffffffff;
    type_id_25 = arg;
  }
  u = type_id_25;
  u = u;
  return u;
}





uint64_t coruna_read_product_version(uint *out_version)
{
  int err;
  long handle;
  long addr;
  long off;
  long base;
  long ctx_val;
  uint64_t u;
  char scratch [32];
  uint scratch;
  int bootargs;
  int thread_attr;
  
  scratch = 0;
  handle = coruna_plist_from_file("/System/Cryptexes/OS/System/Library/CoreServices/SystemVersion.plist");
  if ((handle != 0) ||
     (handle = coruna_plist_from_file("/System/Library/CoreServices/SystemVersion.plist"), handle != 0)) {
    addr = _CFStringCreateWithCString
                      (*(uint64_t *)k_extra_kcfallocatordefault_slot,"ProductVersion",0x8000100);
    if (addr != 0) {
      off = _CFDictionaryGetValue(handle,addr);
      if (off != 0) {
        base = _CFGetTypeID();
        ctx_val = _CFStringGetTypeID();
        if (base == ctx_val) {
          u = _CFStringGetSystemEncoding();
          err = _CFStringGetCString(off,scratch,0x20,u);
          _CFRelease(addr);
          _CFRelease(handle);
          if (err == 0) {
            return 0xffffffff;
          }
          err = _sscanf(scratch,"%d.%d.%d");
          if (1 < err) {
            *out_version = bootargs << 8 | thread_attr << 0x10 | scratch;
            return 0;
          }
          return 0xfffffffe;
        }
      }
      _CFRelease(addr);
    }
    _CFRelease(handle);
  }
  return 0xffffffff;
}





uint64_t coruna_get_platform_serial(long out_serial)
{
  unsigned long u;
  bool err;
  int err;
  pid_t lp4;
  long handle;
  uint32_t *ptr;
  void (*ptr)(void);
  void (*buf)(void);
  void (*str)(void);
  uint64_t size;
  long addr;
  long off;
  long base;
  long ctx_val;
  uint version;
  unsigned long port;
  uint64_t tag;
  stat scratch;
  long bootargs;
  unsigned long scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t action;
  
  if (out_serial == 0) {
    return 0xffffffff;
  }
  host_info = 0;
  thread_attr = 0;
  action = 0;
  serial_buf = 0;
  scratch = 0;
  bootargs = 0;
  thread_attr = 0;
  bootargs = 0;
  scratch.st_gen = 0;
  scratch.st_lspare = 0;
  scratch.st_blksize = 0;
  scratch.st_flags = 0;
  scratch.st_qspare[1] = 0;
  scratch.st_qspare[0] = 0;
  scratch.st_birthtimespec.tv_nsec = 0;
  scratch.st_birthtimespec.tv_sec = 0;
  scratch.st_blocks = 0;
  scratch.st_size = 0;
  scratch.st_mtimespec.tv_nsec = 0;
  scratch.st_mtimespec.tv_sec = 0;
  scratch.st_ctimespec.tv_nsec = 0;
  scratch.st_ctimespec.tv_sec = 0;
  scratch.st_rdev = 0;
  scratch = 0;
  scratch.st_uid = 0;
  scratch.st_gid = 0;
  scratch.st_atimespec.tv_nsec = 0;
  scratch.st_atimespec.tv_sec = 0;
  scratch.st_ino = 0;
  scratch.st_dev = 0;
  scratch.st_mode = 0;
  scratch.st_nlink = 0;
  err = _stat("/usr/libexec/corelliumd",&scratch);
  if (err == 0) {
    err = false;
    goto fail;
  }
  lp4 = _getpid();
  err = _sandbox_check(lp4,"iokit-get-properties",
                         *(uint32_t *)k_extra_sandbox_check_no_report_slot);
  if ((err < 1) &&
     (handle = _dlopen("/System/Library/Frameworks/IOKit.framework/Versions/A/IOKit",1), handle != 0))
  {
    ptr = (uint32_t *)_dlsym(handle,"kIOMasterPortDefault");
    ptr = (void (*)_dlsym(handle,"IORegistryEntryFromPath");
    buf = (void (*)_dlsym(handle,"IORegistryEntryCreateCFProperty");
    str = (void (*)_dlsym(handle,"IOObjectRelease");
    if (((ptr == (void (*)0x0) ||
        (((buf == (void (*)0x0 || (str == (void (*)0x0)) || (ptr == (uint32_t *)0x0)))) ||
       (size = (*ptr)(*ptr,"IODeviceTree:/"), (int)size == 0)) {
      _dlclose(handle);
    }
    else {
      tag = *(uint64_t *)k_extra_kcfallocatordefault_slot;
      addr = _CFStringCreateWithCString(tag,"IOPlatformSerialNumber",0x8000100);
      if (addr == 0) {
        err = -1;
      }
      else {
        off = (*buf)(size,addr,tag,0);
        if (off == 0) {
done:
          err = -1;
        }
        else {
          base = _CFStringGetTypeID();
          ctx_val = _CFGetTypeID(off);
          if (base != ctx_val) goto done;
          err = _CFStringGetCString(off,&bootargs,0x40,0x8000100);
          err = -(uint)(err == 0);
          _CFRelease(off);
        }
        _CFRelease(addr);
      }
      (*str)(size);
      _dlclose(handle);
      handle = bootargs;
      if (err == 0) {
        port = scratch & 0xff;
        host_info = 0;
        thread_attr = 0;
        action = 0;
        serial_buf = 0;
        scratch = 0;
        bootargs = 0;
        thread_attr = 0;
        bootargs = 0;
        err = false;
        if (handle == 0x55494c4c45524f43 && port == 0x4d) goto fail;
      }
    }
  }
  handle = coruna_identity(k_extra_get_cpu_capabilities_slot);
  port = *(unsigned long *)(handle + 0xc) & 0xffffffffffffff00;
  if (port == 0) {
    return 0xffffffff;
  }
  handle = coruna_identity(k_extra_get_cpu_capabilities_slot);
  u = *(unsigned long *)(handle + 0xc) & 0xffffffffffffff00;
  version = 0;
  if (u != 0) {
    err = *(int *)(u + 0x80);
    if ((err == -0x6d04c838 || err == 0x37a09642) || err == 0x2c91a47e) {
      version = *(uint *)(port + 0x10) >> 0x1a & 1;
    }
    else {
      version = (uint)(*(short *)(port + 0x26) != 0x80);
    }
  }
  err = version == 0;
fail:
  *(bool *)out_serial = err;
  return 0;
}





uint64_t coruna_cpu_cap_check_extra_a(uint8_t *buf)
{
  unsigned long u;
  bool err;
  int err;
  long handle;
  uint64_t size;
  uint8_t version;
  int status;
  uint8_t scratch;
  
  if (buf == (uint8_t *)0x0) {
    return 0xffffffff;
  }
  scratch = 0;
  handle = coruna_identity(k_extra_get_cpu_capabilities_slot);
  u = *(unsigned long *)(handle + 0xc) & 0xffffffffffffff00;
  if (u == 0) {
    size = 0xfffffffe;
  }
  else {
    err = *(int *)(u + 0x80);
    if (err < 0x1b588bb3) {
      err = err == -0x789a1216;
      status = -0x25cc27c3;
    }
    else {
      err = err == 0x1b588bb3 || err == 0x462504d2;
      status = 0x2876f5b5;
    }
    version = 0;
    if ((err || err == status) && (err = coruna_get_platform_serial(&scratch), version = scratch, err != 0)
       ) {
      size = 0xfffffffd;
    }
    else {
      size = 0;
      *buf = version;
    }
  }
  return size;
}





uint64_t coruna_cpu_cap_check_extra_b(uint8_t *buf)
{
  unsigned long u;
  int err;
  long handle;
  uint64_t size;
  uint8_t scratch;
  
  if (buf == (uint8_t *)0x0) {
    return 0xffffffff;
  }
  handle = coruna_identity(k_extra_get_cpu_capabilities_slot);
  u = *(unsigned long *)(handle + 0xc) & 0xffffffffffffff00;
  if (u == 0) {
    size = 0xfffffffe;
  }
  else {
    err = *(int *)(u + 0x80);
    if (err == 0x7d34b9f || err == -0x17e1810a) {
      scratch = 1;
      err = coruna_get_platform_serial(&scratch);
      if (err != 0) {
        return 0xfffffffd;
      }
    }
    else {
      scratch = 0;
    }
    size = 0;
    *buf = scratch;
  }
  return size;
}





uint64_t coruna_find_webcontent(long ctx)
{
  uint u;
  unsigned long size;
  int err;
  bool err;
  kern_return_t lk5;
  int status;
  mach_port_t host;
  char *ptr;
  uint64_t version;
  bool status;
  long handle;
  uint scratch;
  uint bootargs;
  uint64_t thread_attr;
  unsigned long host_info;
  size_t serial_buf;
  long action;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t block_ctx;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t stack_guard;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t sa_saved;
  uint64_t sa_saved;
  uint64_t sa_new;
  uint64_t path_buf;
  uint64_t tmp_buf;
  uint64_t sa_new;
  uint64_t region;
  uint64_t plist;
  uint64_t url_buf;
  uint64_t path_buf;
  uint64_t json_buf;
  uint64_t frame;
  uint64_t work;
  uint64_t tmp_buf;
  uint64_t cache;
  uint64_t cache_20;
  uint64_t cache_21;
  uint64_t region;
  uint64_t cache_22;
  uint64_t cache_23;
  uint64_t cache_24;
  uint64_t plist;
  uint64_t cache_25;
  uint64_t cache_26;
  uint64_t cache_27;
  uint64_t url_buf;
  uint64_t cache_28;
  uint64_t cache_29;
  uint64_t cache_30;
  uint64_t json_buf;
  uint64_t cache_31;
  uint64_t cache_32;
  uint64_t cache_33;
  uint64_t frame;
  uint64_t cache_34;
  uint64_t cache_35;
  uint64_t cache_36;
  uint64_t work;
  uint64_t cache_37;
  uint64_t cache_38;
  uint64_t cache_39;
  uint64_t cache;
  uint64_t cache_40;
  uint64_t cache_41;
  uint64_t cache_42;
  uint64_t cache_20;
  uint64_t cache_43;
  uint64_t cache_44;
  uint64_t cache_45;
  uint64_t cache_21;
  uint64_t cache_46;
  uint64_t cache_47;
  uint64_t cache_48;
  
  serial_buf = coruna_u64_pack((serial_buf), (5));
  lk5 = _task_info(*(task_name_t *)k_extra_mach_task_self_slot,0x11,(task_info_t)&action,
                     (mach_msg_type_number_t *)&serial_buf);
  if ((lk5 == 0 && action != 0) && (handle = *(long *)(action + 0x20), handle != 0)) {
    err = *(int *)(handle + 4);
    u = *(uint *)(handle + 8) & 0xffffff;
    *(int *)(ctx + 0xd8) = err;
    *(uint *)(ctx + 0xdc) = u;
    status = *(int *)(action + 4);
    if ((status != 0) && (handle = *(long *)(action + 8), handle != 0)) {
      ptr = _strstr(*(char **)(handle + 8),"WebContent");
      if (ptr == (char *)0x0) {
        ptr = _strstr(*(char **)(handle + (unsigned long)(status - 1) * 0x18 + 8),"WebContent");
        err = ptr != (char *)0x0;
      }
      else {
        err = true;
      }
      *(bool *)(ctx + 0x5fc) = err;
      handle = coruna_identity(k_extra_get_cpu_capabilities_slot);
      size = *(unsigned long *)(handle + 0xc) & 0xffffffffffffff00;
      if (size != 0) {
        *(uint32_t *)(ctx + 0xe0) = *(uint32_t *)(size + 0x80);
        handle = coruna_identity(k_extra_get_cpu_capabilities_slot);
        size = *(unsigned long *)(handle + 0xc) & 0xffffffffffffff00;
        if (size != 0) {
          *(uint64_t *)(ctx + 0x640) = *(uint64_t *)(size + 0x38);
          version = coruna_read_product_version(&scratch);
          if ((int)version != 0) {
            return version;
          }
          *(uint *)(ctx + 0xc0) = scratch;
          cache_46 = 0;
          cache_21 = 0;
          cache_48 = 0;
          cache_47 = 0;
          cache_43 = 0;
          cache_20 = 0;
          cache_45 = 0;
          cache_44 = 0;
          cache_40 = 0;
          cache = 0;
          cache_42 = 0;
          cache_41 = 0;
          cache_37 = 0;
          work = 0;
          cache_39 = 0;
          cache_38 = 0;
          cache_34 = 0;
          frame = 0;
          cache_36 = 0;
          cache_35 = 0;
          cache_31 = 0;
          json_buf = 0;
          cache_33 = 0;
          cache_32 = 0;
          cache_28 = 0;
          url_buf = 0;
          cache_30 = 0;
          cache_29 = 0;
          cache_25 = 0;
          plist = 0;
          cache_27 = 0;
          cache_26 = 0;
          cache_22 = 0;
          region = 0;
          cache_24 = 0;
          cache_23 = 0;
          cache = 0;
          tmp_buf = 0;
          cache_21 = 0;
          cache_20 = 0;
          json_buf = 0;
          path_buf = 0;
          work = 0;
          frame = 0;
          region = 0;
          sa_new = 0;
          url_buf = 0;
          plist = 0;
          sa_new = 0;
          sa_saved = 0;
          tmp_buf = 0;
          path_buf = 0;
          block_ctx = 0;
          stack_guard = 0;
          sa_saved = 0;
          stack_guard = 0;
          host_info = 0;
          block_ctx = 0;
          action = 0;
          serial_buf = 0;
          scratch = 0;
          action = 0;
          thread_attr = 0;
          bootargs = 0;
          if ((scratch & 0xfe0000) < 0xd0001) {
            host = _mach_host_self();
            status = _host_kernel_version(host,(char *)&action);
          }
          else {
            host_info = 0x400000001;
            serial_buf = 0x200;
            status = _sysctl((int *)&host_info,2,&action,&serial_buf,(void *)0x0,0);
          }
          if (status != 0) {
            return 0xfffffffe;
          }
          ptr = _strstr((char *)&action,"RELEASE");
          if (ptr == (char *)0x0) {
            return 0xfffffffd;
          }
          ptr = _strstr((char *)&action,"xnu-");
          if (ptr != (char *)0x0) {
            serial_buf = serial_buf & 0xffffffff00000000;
            host_info = host_info & 0xffffffff00000000;
            thread_attr = 0;
            bootargs = 0;
            status = _sscanf(ptr,"xnu-%d.%d.%d.%d.%d%*s");
            if (status < 3) {
              return 0xfffffffb;
            }
            *(uint *)(ctx + 200) =
                 (uint)serial_buf << 0x12 | ((uint)host_info & 0x1ff) << 9 | thread_attr & 0x1ff;
            *(unsigned long *)(ctx + 0xd0) =
                 (unsigned long)(uint)((int)thread_attr << 10) & 0xffc00 |
                 ((unsigned long)((uint)serial_buf & 0x7fff) << 0x14 |
                  (unsigned long)((uint)host_info << 10) & 0xfffff | (unsigned long)thread_attr & 0x3ff) << 0x14
                 | (unsigned long)bootargs & 0x3ff;
            version = coruna_cpu_cap_check_extra_b(&action);
            if ((int)version != 0) {
              return version;
            }
            *(uint8_t *)(ctx + 0x5c0) = (uint8_t)action;
            version = coruna_cpu_cap_check_extra_a(&serial_buf);
            if ((int)version != 0) {
              return version;
            }
            status = false;
            *(char *)(ctx + 0x5c1) = (char)serial_buf;
            if ((err == 0x100000c) && (1 < u)) {
              u = scratch >> 0x10 & 0xff;
              if (u < 0xd) {
                status = u == 0xc && (scratch & 0xff00) != 0;
              }
              else {
                status = true;
              }
            }
            *(bool *)(ctx + 0x5c3) = status;
            if ((((char)serial_buf == '\0') || (*(uint *)(ctx + 0xc0) >> 10 < 0x3c1)) ||
               ((err = *(int *)(ctx + 0xe0), err != -0x789a1216 &&
                ((err != -0x25cc27c3 && (err != 0x2876f5b5)))))) {
              err = false;
            }
            *(bool *)(ctx + 0x5e9) = err;
            return 0;
          }
          return 0xfffffffc;
        }
      }
    }
  }
  return 0xffffffff;
}





long coruna_plist_from_file(char *path)
{
  int err;
  size_t ls2;
  long handle;
  long addr;
  long off;
  uint64_t u;
  long scratch;
  
  scratch = 0;
  u = *(uint64_t *)k_extra_kcfallocatordefault_slot;
  ls2 = _strlen(path);
  handle = _CFURLCreateFromFileSystemRepresentation(u,path,ls2,0);
  if (handle != 0) {
    addr = _CFReadStreamCreateWithFile(u,handle);
    if (addr != 0) {
      err = _CFReadStreamOpen();
      if (err == 0) {
        off = 0;
      }
      else {
        off = _CFPropertyListCreateWithStream(u,addr,0,0,0,&scratch);
        if (off == 0 && scratch != 0) {
          _CFRelease();
        }
        _CFReadStreamClose(addr);
      }
      _CFRelease(handle);
      _CFRelease(addr);
      return off;
    }
    _CFRelease(handle);
  }
  return 0;
}





uint64_t coruna_lzfse_decode(uint64_t *dst,uint *src)
{
  uint u;
  uint size;
  void *ptr;
  unsigned long version;
  uint64_t port;
  int *err;
  unsigned long tag;
  
  port = 0xad001;
  if (((dst != (uint64_t *)0x0) &&
      (err = (int *)*dst, err != (int *)0x0 && src != (uint *)0x0)) &&
     (u = *src, u != 0)) {
    if ((7 < u) && (*err == 0xbedf00d)) {
      size = err[1];
      tag = (unsigned long)size;
      if ((size != 0) && (u - 8 < size)) {
        ptr = _malloc(tag + 1);
        if (ptr == (void *)0x0) {
          return 0xad009;
        }
        _memset_s(ptr,tag,0,tag);
        version = _compression_decode_buffer(ptr,tag + 1,err + 2,u - 8,0,0x306);
        if (version == tag) {
          _memset_s(err,u,0,u);
          _free(err);
          *dst = ptr;
          *src = size;
          return 0;
        }
        _memset_s(ptr,tag,0,tag);
        _free(ptr);
        return 0xad00b;
      }
    }
    port = 0;
  }
  return port;
}





bool coruna_sysctl_hw_model(long handle)
{
  uint u;
  int err;
  int status;
  size_t scratch;
  uint64_t bootargs;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  
  if (handle == 0) {
    return false;
  }
  u = *(uint *)(handle + 0xc0);
  if (0x1006ff < u) {
    return true;
  }
  if (0x100400 < u) {
    err = *(int *)(handle + 0xe0);
    if (err < 0x1b588bb3) {
      if (err == -0x789a1216) {
        return false;
      }
      status = -0x25cc27c3;
    }
    else {
      if (err == 0x1b588bb3) {
        return false;
      }
      status = 0x462504d2;
    }
    if (err == status) {
      return false;
    }
    return true;
  }
  if (u - 0xf0707 < 0xf8f9) {
    return true;
  }
  if (0x7e < u - 0xf0200 >> 9) {
    return false;
  }
  scratch = 0;
  bootargs = 0;
  thread_attr = 0;
  bootargs = 0;
  scratch = 0x20;
  err = _sysctlbyname("hw.model",&bootargs,&scratch,(void *)0x0,0);
  if (err != 0) {
    return false;
  }
  if (((byte)bootargs & 0xdf) != 0x4a) {
    return false;
  }
  return *(long *)(handle + 0x640) - 0x40000001U >> 0x1e == 0;
}
uint coruna_vm_map_memory_entry(void *ctx,void *scratch,size_t len)
{
  vm_size_t size;
  long handle;
  unsigned long u;
  uint8_t *ptr;
  int err;
  uint size;
  unsigned long version;
  long addr;
  uint port;
  unsigned long tag;
  unsigned long kind;
  unsigned long type_id;
  mach_port_t scratch;
  vm_inherit_t inheritance;
  vm_size_t lv12;
  vm_address_t bootargs;
  
  tag = *(unsigned long *)k_extra_vm_page_mask_slot;
  type_id = tag & (unsigned long)ctx;
  kind = type_id + len;
  version = *(unsigned long *)k_extra_vm_page_size_slot;
  u = 0;
  if (version != 0) {
    u = kind / version;
  }
  addr = kind - u * version;
  handle = 0;
  if (addr != 0) {
    handle = version - addr;
  }
  size = handle + kind;
  bootargs = 0;
  scratch = 0;
  lv12 = size;
  err = _memcmp(ctx,scratch,len);
  inheritance = (vm_inherit_t)lv12;
  if (err == 0) {
    port = 0;
  }
  else {
    kind = (unsigned long)ctx & (tag ^ 0xffffffffffffffff);
    port = 0xad00b;
    err = coruna_memcpy_chk(kind,size);
    ptr = k_extra_mach_task_self_slot;
    if (err != 0) {
      size = _mach_make_memory_entry_64
                        (*(vm_map_t *)k_extra_mach_task_self_slot,
                         (memory_object_size_t *)&ghidra_stack_0,kind,1,&scratch,0);
      if ((size == 0) &&
         (size = _vm_map(*(vm_map_t *)ptr,&bootargs,size,0,0x1001,scratch,0,0,1,1,inheritance),
         size == 0)) {
        err = coruna_memcpy_chk(bootargs,size);
        if ((err != 0) && ((k_extra_icache_mode & 0xfe) == 2)) {
          UnkSytemRegWrite(3,6,0xf,1,5,k_extra_dsb_ctrl_a);
          InstructionSynchronizationBarrier();
          _memcpy((void *)(bootargs + type_id),scratch,len);
          DataSynchronizationBarrier(3,3,0);
          if ((k_extra_icache_mode & 0xfe) == 2) {
            UnkSytemRegWrite(3,6,0xf,1,5,k_extra_dsb_ctrl_b);
            InstructionSynchronizationBarrier();
            _sys_icache_invalidate(ctx,len);
            _sys_dcache_flush(ctx,len);
            err = _memcmp(ctx,scratch,len);
            port = 0;
            if (err != 0) {
              port = 0xad00b;
            }
          }
        }
      }
      else {
        port = size | 0x80000000;
      }
    }
  }
  if (bootargs != 0) {
    _vm_deallocate(*(vm_map_t *)k_extra_mach_task_self_slot,bootargs,size);
  }
  if (1 < scratch + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_extra_mach_task_self_slot,scratch);
  }
  return port;
}





bool coruna_memcpy_chk(long handle,size_t len)
{
  void *ptr;
  long handle;
  uint8_t scratch;
  
  scratch = false;
  if ((handle != 0) && (len != 0)) {
    ptr = _malloc(len);
    if (ptr != (void *)0x0) {
      handle = ___memcpy_chk(ptr,handle,len,0xffffffffffffffff);
      scratch = handle != 0;
      _free(ptr);
    }
  }
  return scratch;
}





void coruna_extra0a_stub_3(void)
{
  CallSupervisor(0x80);
  return;
}





void coruna_extra0a_stub_4(void)
{
  CallSupervisor(0x80);
  return;
}





void coruna_extra0a_stub_5(void)
{
  CallSupervisor(0x80);
  return;
}





void coruna_pacia(void)
{
  return;
}





void coruna_nop_4(void)
{
  return;
}





void coruna_nop_4_2(void)
{
  return;
}





void coruna_nop_4_3(void)
{
  return;
}
uint64_t coruna_return_zero(void)
{
  return 0;
}





void coruna_svc_indirect_extra_0(void (*indirect_target)
{
  (*indirect_target)();
  return;
}





void coruna_svc_indirect_extra_1(void (*indirect_target,uint32_t size,uint64_t val,long handle)
{
  uint32_t scratch[8];
  
  *(uint32_t *)((long)scratch + handle) = size;
  (*indirect_target)();
  return;
}





void coruna_svc_indirect_extra_2(void (*indirect_target,uint32_t size,uint64_t val,long handle)
{
  uint32_t scratch[12];
  
  *(uint32_t *)((long)scratch + handle) = size;
  (*indirect_target)();
  return;
}





void coruna_svc_indirect_extra_3(void (*indirect_target,uint32_t size,uint64_t val,long handle)
{
  uint32_t scratch[4];
  
  *(uint32_t *)((long)scratch + handle) = size;
  (*indirect_target)();
  return;
}





void coruna_svc_indirect_extra_4(void (*indirect_target,uint32_t size,uint64_t val,long handle)
{
  uint32_t scratch[8];
  
  *(uint32_t *)((long)scratch + handle) = size;
  (*indirect_target)();
  return;
}





uint8_t * coruna_extra_slot_helper(long handle,int flags,int *count_2,uint size)
{
  int *err;
  long handle;
  uint u;
  int err;
  uint size;
  int status;
  unsigned long version;
  long addr;
  uint64_t port;
  
  if (handle == 0) {
    return (uint8_t *)0xad001;
  }
  if (count_2 == (int *)0x0) {
    return (uint8_t *)0xad001;
  }
  if (size == 0) {
    return (uint8_t *)0xad001;
  }
  if (3 < size) {
    if (*count_2 == -0xff24111) {
      if (size < 9) goto fail;
      size = count_2[1];
      if ((int)size < 1) {
        return (uint8_t *)0x0;
      }
      version = 0;
      while( true ) {
        err = count_2 + version * 4 + 2;
        if (err < count_2 || (int *)((long)count_2 + (unsigned long)size) <= err) {
          return &k_extra_jsc_dispatch_word;
        }
        port = *(uint64_t *)err;
        status = (int)port;
        if (status == 0) break;
        addr = 0;
        u = err[2];
        err = err[3];
        while (handle = handle + addr,
              *(int *)(handle + 0x140) != 0 && *(int *)(handle + 0x140) != status) {
          addr = addr + 0x30;
          if (addr == 0x480) {
            return (uint8_t *)0xad009;
          }
        }
        *(uint64_t *)(handle + 0x148) = 0;
        *(uint64_t *)(handle + 0x140) = 0;
        *(uint64_t *)(handle + 0x158) = 0;
        *(uint64_t *)(handle + 0x150) = 0;
        *(uint64_t *)(handle + 0x168) = 0;
        *(uint64_t *)(handle + 0x160) = 0;
        *(uint64_t *)(handle + 0x140) = port;
        *(unsigned long *)(handle + 0x148) = (unsigned long)u + (long)count_2;
        version = version + 1;
        *(int *)(handle + 0x150) = err;
        if (version == size) {
          return (uint8_t *)0x0;
        }
      }
    }
    else if (flags != 0) {
      addr = 0;
      do {
        handle = handle + addr;
        if (*(int *)(handle + 0x140) == 0 || *(int *)(handle + 0x140) == flags) {
          *(uint64_t *)(handle + 0x148) = 0;
          *(uint64_t *)(handle + 0x140) = 0;
          *(uint64_t *)(handle + 0x158) = 0;
          *(uint64_t *)(handle + 0x150) = 0;
          *(uint64_t *)(handle + 0x168) = 0;
          *(uint64_t *)(handle + 0x160) = 0;
          *(int *)(handle + 0x140) = flags;
          *(uint32_t *)(handle + 0x144) = 1;
          *(int **)(handle + 0x148) = count_2;
          *(uint *)(handle + 0x150) = size;
          return (uint8_t *)0x0;
        }
        addr = addr + 0x30;
      } while (addr != 0x480);
      return (uint8_t *)0xad009;
    }
    return &k_extra_jsc_dispatch_mask;
  }
fail:
  return &k_extra_svc_flag_d;
}





uint64_t coruna_extra_ctx_helper(long handle)
{
  long handle;
  uint64_t u;
  long addr;
  long scratch;
  
  addr = 0;
  do {
    if (((*(int *)(handle + addr + 0x140) != 0) && (*(int *)(handle + addr + 0x144) != 0)) &&
       (handle = handle + addr, *(long *)(handle + 0x168) == 0)) {
      scratch = 0;
      u = (**(void (**)(handle + 0x30))
                        (handle,*(uint64_t *)(handle + 0x148),*(uint32_t *)(handle + 0x150),
                         &scratch);
      if ((int)u != 0) {
        return u;
      }
      *(long *)(handle + 0x168) = scratch;
      *(uint64_t *)(handle + addr + 0x158) = *(uint64_t *)(scratch + 0x58);
      *(uint32_t *)(handle + addr + 0x160) = *(uint32_t *)(scratch + 0xa8);
    }
    addr = addr + 0x30;
  } while (addr != 0x480);
  return 0;
}





uint8_t * coruna_svc_indirect_extra_5(long handle,int flags)
{
  long handle;
  int err;
  uint8_t *ptr;
  long addr;
  long off;
  long scratch;
  
  ptr = (uint8_t *)0xad001;
  if ((handle != 0) && (*(void (**)(handle + 0x30) != (void (*)0x0 && flags != 0)) {
    off = 0;
    do {
      handle = handle + off;
      if (*(int *)(handle + 0x140) == flags) {
        if (*(long *)(handle + 0x168) != 0) {
          return &k_extra_svc_flag_a;
        }
        addr = *(long *)(handle + off + 0x148);
        if ((addr != 0) && (err = *(int *)(handle + off + 0x150), err != 0)) {
          scratch = 0;
          ptr = (uint8_t *)(**(void (**)(handle + 0x30))(handle,addr,err,&scratch);
          if ((int)ptr != 0) {
            return ptr;
          }
          *(long *)(handle + 0x168) = scratch;
          *(uint64_t *)(handle + off + 0x158) = *(uint64_t *)(scratch + 0x58);
          *(uint32_t *)(handle + off + 0x160) = *(uint32_t *)(scratch + 0xa8);
          return ptr;
        }
        return &k_extra_svc_flag_b;
      }
      off = off + 0x30;
    } while (off != 0x480);
    ptr = &k_extra_svc_flag_c;
  }
  return ptr;
}





uint8_t * coruna_svc_indirect_extra_6(long handle,int flags)
{
  long handle;
  uint8_t *ptr;
  long addr;
  
  ptr = (uint8_t *)0xad001;
  if ((handle != 0) && (*(void (**)(handle + 0x130) != (void (*)0x0 && flags != 0)) {
    addr = 0;
    do {
      handle = handle + addr;
      if (*(int *)(handle + 0x140) == flags) {
        if ((*(long *)(handle + 0x168) != 0) &&
           (ptr = (uint8_t *)(**(void (**)(handle + 0x130))(handle), (int)ptr != 0)) {
          return ptr;
        }
        *(uint64_t *)(handle + 0x168) = 0;
        *(uint64_t *)(handle + addr + 0x158) = 0;
        *(uint32_t *)(handle + addr + 0x160) = 0;
        return (uint8_t *)0x0;
      }
      addr = addr + 0x30;
    } while (addr != 0x480);
    ptr = &k_extra_svc_flag_c;
  }
  return ptr;
}





uint8_t * coruna_extra_reloc_helper(long handle,int flags,long *addr_2)
{
  long handle;
  uint8_t *ptr;
  long addr;
  
  ptr = (uint8_t *)0xad001;
  if (((handle != 0) && (addr_2 != (long *)0x0)) && (*addr_2 = 0, flags != 0)) {
    addr = 0;
    do {
      handle = handle + addr;
      if (*(int *)(handle + 0x140) == flags) {
        addr = *(long *)(handle + 0x168);
        if (addr == 0) {
          ptr = (uint8_t *)coruna_svc_indirect_extra_5();
          if ((int)ptr != 0) {
            return ptr;
          }
          addr = *(long *)(handle + 0x168);
        }
        *addr_2 = addr;
        return (uint8_t *)0x0;
      }
      addr = addr + 0x30;
    } while (addr != 0x480);
    ptr = &k_extra_svc_flag_c;
  }
  return ptr;
}





uint8_t * coruna_extra_map_helper(long handle,int flags,long *addr_2,int *count_2)
{
  int err;
  uint8_t *ptr;
  long handle;
  long addr;
  
  ptr = (uint8_t *)0xad001;
  if (((handle != 0) && (addr_2 != (long *)0x0)) && (count_2 != (int *)0x0)) {
    *addr_2 = 0;
    *count_2 = 0;
    if (flags != 0) {
      handle = 0;
      while (*(int *)(handle + handle + 0x140) != flags) {
        handle = handle + 0x30;
        if (handle == 0x480) {
          return &k_extra_svc_flag_c;
        }
      }
      addr = *(long *)(handle + handle + 0x148);
      if ((addr == 0) || (err = *(int *)(handle + handle + 0x150), err == 0)) {
        return &k_extra_svc_flag_b;
      }
      ptr = (uint8_t *)0x0;
      *addr_2 = addr;
      *count_2 = err;
    }
  }
  return ptr;
}





uint64_t coruna_extra_bind_helper(long handle)
{
  uint64_t *ptr;
  long handle;
  
  handle = 0x140;
  do {
    ptr = (uint64_t *)(handle + handle);
    ptr[3] = 0;
    ptr[2] = 0;
    ptr[5] = 0;
    ptr[4] = 0;
    ptr[1] = 0;
    *ptr = 0;
    handle = handle + 0x30;
  } while (handle != 0x5c0);
  *(void (**)(handle + 0xe8) = coruna_extra_slot_helper;
  *(void (**)(handle + 0xf0) = coruna_extra_ctx_helper;
  *(void (**)(handle + 0xf8) = coruna_svc_indirect_extra_5;
  *(void (**)(handle + 0x100) = coruna_svc_indirect_extra_6;
  *(void (**)(handle + 0x110) = coruna_extra_map_helper;
  *(void (**)(handle + 0x108) = coruna_extra_reloc_helper;
  return 0;
}





uint64_t coruna_iokit_open_service(long handle,long addr_2)
{
  uint u;
  pid_t lp2;
  int err;
  uint64_t size;
  unsigned long version;
  bool err;
  
  size = 0xad001;
  if ((handle != 0) && (addr_2 != 0)) {
    version = coruna_sysctl_hw_model(handle);
    if (((version & 1) == 0) && (u = *(uint *)(handle + 0xc0), u < 0x100501)) {
      err = false;
      if ((0xfffff < u) && (0xf8f8 < u - 0xf0707)) {
        lp2 = _getpid();
        err = _sandbox_check(lp2,"iokit-open-service",
                               *(uint32_t *)k_extra_sandbox_check_no_report_slot);
        err = 0 < err;
      }
    }
    else {
      err = false;
    }
    size = 0;
    *(bool *)addr_2 = err;
  }
  return size;
}





uint64_t coruna_is_mobilestore_ua(long handle)
{
  bool err;
  int err;
  uint64_t u;
  uint8_t scratch;
  
  if (handle == 0) {
    u = 0xad001;
  }
  else {
    scratch = 0;
    u = coruna_iokit_open_service(handle,&scratch);
    if ((int)u == 0) {
      *(uint8_t *)(handle + 0x5e8) = scratch;
      if (*(char **)(handle + 0xa0) == (char *)0x0) {
        err = false;
      }
      else {
        err = _strncasecmp("MobileStore/1.0",*(char **)(handle + 0xa0),0xf);
        err = err == 0;
      }
      *(bool *)(handle + 0x5ec) = err;
    }
  }
  return u;
}
void coruna_extra_teardown_helper(uint *size,long handle,long addr_2)
{
  uint u;
  uint size;
  uint version;
  uint port;
  uint64_t tag;
  uint64_t kind;
  uint type_id;
  uint type_id_8;
  uint type_id_9;
  uint type_id_10;
  uint type_id_11;
  uint type_id_12;
  long handle;
  byte err;
  int err;
  unsigned long type_id_13;
  uint type_id_14;
  uint type_id_15;
  uint type_id_16;
  uint type_id_17;
  uint type_id_18;
  long addr;
  uint32_t scratch;
  uint scratch;
  uint64_t bootargs;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t thread_attr;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t block_ctx;
  int stack_guard [9];
  uint64_t sa_saved;
  uint64_t host_info;
  
  kind = k_extra_slot_0000b968;
  tag = k_extra_md5_init_state;
  if (((handle != 0) && (addr_2 != 0)) && (size != (uint *)0x0)) {
    handle = 0;
    thread_attr = 0;
    host_info = 0;
    action = 0;
    serial_buf = 0;
    bootargs = 0;
    thread_attr = 0;
    bootargs = 0;
    stack_guard[1] = *size;
    stack_guard[6] = (int)*(uint64_t *)(size + 5);
    stack_guard[7] = (int)((unsigned long)*(uint64_t *)(size + 5) >> 0x20);
    block_ctx = k_extra_md5_init_state;
    stack_guard[4] = (int)*(uint64_t *)(size + 3);
    stack_guard[5] = (int)((unsigned long)*(uint64_t *)(size + 3) >> 0x20);
    stack_guard[2] = (int)*(uint64_t *)(size + 1);
    stack_guard[3] = (int)((unsigned long)*(uint64_t *)(size + 1) >> 0x20);
    stack_guard[8] = size[7];
    sa_saved = 0;
    host_info = 0;
    type_id_13 = 0x40;
    do {
      if (type_id_13 < 0x40) {
        err = *(byte *)((long)&scratch + type_id_13);
      }
      else {
        scratch = (uint)tag;
        scratch = (uint)((unsigned long)tag >> 0x20);
        serial_buf = (uint)sa_saved;
        type_id = (uint)serial_buf;
        serial_buf = (uint)((unsigned long)sa_saved >> 0x20);
        type_id_8 = serial_buf;
        bootargs = (uint)kind;
        bootargs = (uint)((unsigned long)kind >> 0x20);
        action = 0;
        action = 0;
        err = 10;
        type_id_18 = stack_guard[1];
        type_id_14 = stack_guard[2];
        type_id_16 = stack_guard[5];
        type_id_17 = stack_guard[6];
        type_id_10 = stack_guard[3];
        type_id_12 = stack_guard[4];
        type_id_11 = (uint)bootargs;
        type_id_15 = stack_guard[7];
        type_id_9 = stack_guard[8];
        do {
          serial_buf = (uint)serial_buf ^ scratch + type_id_18;
          type_id_16 = ((uint)serial_buf >> 0x10 | (uint)serial_buf << 0x10) + type_id_16;
          u = type_id_16 ^ type_id_18;
          scratch = (u >> 0x14 | u << 0xc) + scratch + type_id_18;
          type_id_18 = scratch ^ ((uint)serial_buf >> 0x10 | (uint)serial_buf << 0x10);
          type_id_16 = (type_id_18 >> 0x18 | type_id_18 << 8) + type_id_16;
          u = type_id_16 ^ (u >> 0x14 | u << 0xc);
          serial_buf = serial_buf ^ scratch + type_id_14;
          type_id_17 = (serial_buf >> 0x10 | serial_buf << 0x10) + type_id_17;
          size = type_id_17 ^ type_id_14;
          scratch = (size >> 0x14 | size << 0xc) + scratch + type_id_14;
          version = scratch ^ (serial_buf >> 0x10 | serial_buf << 0x10);
          type_id_17 = (version >> 0x18 | version << 8) + type_id_17;
          type_id_14 = type_id_17 ^ (size >> 0x14 | size << 0xc);
          action = (uint)action ^ type_id_11 + type_id_10;
          type_id_15 = ((uint)action >> 0x10 | (uint)action << 0x10) + type_id_15;
          size = type_id_15 ^ type_id_10;
          type_id_11 = (size >> 0x14 | size << 0xc) + type_id_11 + type_id_10;
          port = type_id_11 ^ ((uint)action >> 0x10 | (uint)action << 0x10);
          type_id_15 = (port >> 0x18 | port << 8) + type_id_15;
          type_id_10 = type_id_15 ^ (size >> 0x14 | size << 0xc);
          action = action ^ bootargs + type_id_12;
          type_id_9 = (action >> 0x10 | action << 0x10) + type_id_9;
          size = type_id_9 ^ type_id_12;
          bootargs = (size >> 0x14 | size << 0xc) + bootargs + type_id_12;
          type_id_12 = bootargs ^ (action >> 0x10 | action << 0x10);
          type_id_9 = (type_id_12 >> 0x18 | type_id_12 << 8) + type_id_9;
          size = type_id_9 ^ (size >> 0x14 | size << 0xc);
          scratch = (type_id_14 >> 0x19 | type_id_14 << 7) + scratch;
          type_id_12 = scratch ^ (type_id_12 >> 0x18 | type_id_12 << 8);
          type_id_15 = (type_id_12 >> 0x10 | type_id_12 << 0x10) + type_id_15;
          type_id_14 = type_id_15 ^ (type_id_14 >> 0x19 | type_id_14 << 7);
          scratch = (type_id_14 >> 0x14 | type_id_14 << 0xc) + scratch;
          type_id_12 = scratch ^ (type_id_12 >> 0x10 | type_id_12 << 0x10);
          action = type_id_12 >> 0x18 | type_id_12 << 8;
          type_id_15 = action + type_id_15;
          type_id_14 = type_id_15 ^ (type_id_14 >> 0x14 | type_id_14 << 0xc);
          type_id_14 = type_id_14 >> 0x19 | type_id_14 << 7;
          scratch = (type_id_10 >> 0x19 | type_id_10 << 7) + scratch;
          type_id_12 = scratch ^ (type_id_18 >> 0x18 | type_id_18 << 8);
          type_id_9 = (type_id_12 >> 0x10 | type_id_12 << 0x10) + type_id_9;
          type_id_10 = type_id_9 ^ (type_id_10 >> 0x19 | type_id_10 << 7);
          scratch = (type_id_10 >> 0x14 | type_id_10 << 0xc) + scratch;
          type_id_12 = scratch ^ (type_id_12 >> 0x10 | type_id_12 << 0x10);
          serial_buf = type_id_12 >> 0x18 | type_id_12 << 8;
          type_id_9 = (uint)serial_buf + type_id_9;
          type_id_10 = type_id_9 ^ (type_id_10 >> 0x14 | type_id_10 << 0xc);
          type_id_10 = type_id_10 >> 0x19 | type_id_10 << 7;
          type_id_11 = (size >> 0x19 | size << 7) + type_id_11;
          type_id_12 = type_id_11 ^ (version >> 0x18 | version << 8);
          type_id_16 = (type_id_12 >> 0x10 | type_id_12 << 0x10) + type_id_16;
          type_id_18 = type_id_16 ^ (size >> 0x19 | size << 7);
          type_id_11 = (type_id_18 >> 0x14 | type_id_18 << 0xc) + type_id_11;
          type_id_12 = type_id_11 ^ (type_id_12 >> 0x10 | type_id_12 << 0x10);
          serial_buf = type_id_12 >> 0x18 | type_id_12 << 8;
          type_id_16 = serial_buf + type_id_16;
          type_id_12 = type_id_16 ^ (type_id_18 >> 0x14 | type_id_18 << 0xc);
          type_id_12 = type_id_12 >> 0x19 | type_id_12 << 7;
          bootargs = bootargs + (u >> 0x19 | u << 7);
          type_id_18 = bootargs ^ (port >> 0x18 | port << 8);
          type_id_17 = (type_id_18 >> 0x10 | type_id_18 << 0x10) + type_id_17;
          u = type_id_17 ^ (u >> 0x19 | u << 7);
          bootargs = (u >> 0x14 | u << 0xc) + bootargs;
          type_id_18 = bootargs ^ (type_id_18 >> 0x10 | type_id_18 << 0x10);
          action = type_id_18 >> 0x18 | type_id_18 << 8;
          type_id_17 = (uint)action + type_id_17;
          type_id_18 = type_id_17 ^ (u >> 0x14 | u << 0xc);
          type_id_18 = type_id_18 >> 0x19 | type_id_18 << 7;
          err = err + -1;
        } while (err != 0);
        addr = 0;
        bootargs = coruna_u64_pack((type_id_14), (type_id_18));
        host_info = coruna_u64_pack((type_id_17), (type_id_16));
        thread_attr = coruna_u64_pack((type_id_12), (type_id_10));
        thread_attr = coruna_u64_pack((type_id_9), (type_id_15));
        err = (char)tag + (char)scratch;
        bootargs = coruna_u64_pack((bootargs), ((uint))bootargs + type_id_11);
        do {
          *(int *)((long)&bootargs + addr + 4) =
               *(int *)((long)stack_guard + addr) + *(int *)((long)&bootargs + addr + 4);
          addr = addr + 4;
        } while (addr != 0x34);
        sa_saved = coruna_u64_pack((type_id_8), (type_id + 1));
        type_id_13 = 0;
        if (type_id == 0xffffffff) {
          sa_saved = (unsigned long)(type_id_8 + 1) << 0x20;
        }
      }
      *(byte *)(handle + handle) = *(byte *)(handle + handle) ^ err;
      type_id_13 = type_id_13 + 1;
      handle = handle + 1;
    } while (handle != addr_2);
  }
  return;
}





void coruna_nop_extra_0_wrapper(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4,
                 uint64_t off_5)
{
  coruna_implant_trampoline_fn indirect_target;
  
  if (k_extra_jsc_callback_fn != 0) {
    coruna_nop_extra_0();
    coruna_svc_indirect_extra_8(val,id_2,size_3,off_4,off_5);
    return;
  }
  (*indirect_target)();
  return;
}





void coruna_loader_run_extra(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4,
                 uint64_t off_5)
{
  coruna_implant_trampoline_fn indirect_target;
  
  if (k_extra_jsc_callback_fn != 0) {
    coruna_nop_extra_0();
    coruna_svc_indirect_extra_8(val,id_2,size_3,off_4,off_5);
    return;
  }
  (*indirect_target)();
  return;
}
void coruna_nop_extra_0(void)
{
  return;
}
void coruna_nop_extra_1(void)
{
  return;
}
void coruna_nop_extra_2(void)
{
  return;
}
void coruna_nop_extra_3(void)
{
  return;
}





void coruna_svc_indirect_extra_7(uint64_t val,uint64_t id_2)
{
  (*k_extra_jsc_callback_fn)(0xb389,val,id_2,k_extra_jsc_callback_ctx);
  return;
}





void coruna_svc_indirect_extra_8(uint64_t val,uint64_t id_2)
{
  (*k_extra_jsc_callback_fn)(0xb389,val,id_2,k_extra_jsc_callback_arg);
  return;
}

