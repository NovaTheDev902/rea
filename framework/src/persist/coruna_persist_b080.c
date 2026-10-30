/*
 * Coruna persist dylib (persistb080) — hand-reconstructed native C
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



/* Persist module runtime constants (from Mach-O image) */
static uint64_t k_persist_mmap_anon_fd;
static uint64_t k_persist_slot_4e20;
static uint64_t k_persist_slot_a030 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_1cf38 = 0xa9024ff4d10103ffULL;
static uint64_t k_persist_rodata_word_1ec90 = 0x0000002000000013ULL;
static uint64_t k_persist_rodata_word_1ecc0 = 0x0000000500000000ULL;
static uint64_t k_persist_rodata_word_1ecc8 = 0x408f400000000000ULL;
static uint64_t k_persist_rodata_word_1ecd0 = 0x0000002800000000ULL;
static uint64_t k_persist_rodata_word_1ecd8 = 0x0000002000000000ULL;
static uint64_t k_persist_rodata_word_1ece0 = 0x0000000042000000ULL;
static uint64_t k_persist_rodata_word_1ed00 = 0x408a980000000000ULL;
static uint64_t k_persist_rodata_word_1ed08 = 0x0000000400000001ULL;
static uint64_t k_persist_rodata_word_1ed10 = 0x0000013400000013ULL;
static uint64_t k_persist_rodata_word_1ed28 = 0x0000001800000013ULL;
static uint64_t k_persist_rodata_word_1ed50 = 0x0000002800001513ULL;
static uint64_t k_persist_rodata_word_1ed68 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_1ed70 = 0x408a900000000000ULL;
static uint64_t k_persist_rodata_word_1ed78 = 0x0000000401000000ULL;
static uint64_t k_persist_rodata_word_1ed98 = 0x0000000040000000ULL;
static uint64_t k_persist_rodata_word_1eda0 = 0x4090ab3333333333ULL;
static uint64_t k_persist_rodata_word_1edb0 = 0x0000000500000020ULL;
static uint64_t k_persist_rodata_word_20068 = 0x0000000000024880ULL;
static uint64_t k_persist_rodata_word_20070 = 0x000000000001ee5fULL;
static uint64_t k_persist_rodata_word_20218 = 0x000000000001ef55ULL;
static uint64_t k_persist_rodata_word_20228 = 0x000000000001ef55ULL;
static uint64_t k_persist_rodata_word_20238 = 0x000000000001ef79ULL;
static uint64_t k_persist_rodata_word_203d0 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_20400 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_20430 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_20460 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_20480 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_204b0 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_204d0 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_204f0 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_20510 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_20530 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_20560 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_20590 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_205c0 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_205e0 = 0x0000000000016e7cULL;
static uint64_t k_persist_rodata_word_20660 = 0x00000000000155a0ULL;
static uint64_t k_persist_rodata_word_20680 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_206b0 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_206d0 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_206f0 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_20710 = 0x0000000000018ec0ULL;
static uint64_t k_persist_rodata_word_20798 = 0x0000000000016e7cULL;
static uint64_t k_persist_rodata_word_207b0 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_20860 = 0x00000000000193e8ULL;
static uint64_t k_persist_rodata_word_20878 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_24398 = 0x00000000000187bcULL;
static uint8_t k_persist_rodata_word_243b0 = 0x00;
static uint8_t k_persist_rodata_word_243b1 = 0x00;
static uint64_t k_persist_rodata_word_243b2 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_243b8 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_243c0 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_243c8 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_243d0 = 0x0000000032aaaba7ULL;
static uint64_t k_persist_rodata_word_24410 = 0x0000000032aaaba7ULL;
static uint64_t k_persist_rodata_word_24450 = 0x0100000cfeedfacfULL;
static uint64_t k_persist_rodata_word_24458 = 0x0000000600000000ULL;
static uint64_t k_persist_rodata_word_24460 = 0x0000069800000011ULL;
static uint64_t k_persist_rodata_word_24468 = 0x0000000000100085ULL;
static uint64_t k_persist_rodata_word_24470 = 0x0000027800000019ULL;
static uint64_t k_persist_rodata_word_24870 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_24878 = 0x0000415441445f5fULL;
static uint64_t k_persist_rodata_word_24880 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_24888 = 0x0000000000024390ULL;
static uint64_t k_persist_rodata_word_24890 = 0x00000000000000c0ULL;
static uint64_t k_persist_rodata_word_24898 = 0x0000000300024390ULL;
static uint64_t k_persist_rodata_word_248a0 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_248a8 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_248b0 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_248b8 = 0x0000007373625f5fULL;
static uint64_t k_persist_rodata_word_248c0 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_248c8 = 0x0000415441445f5fULL;
static uint64_t k_persist_rodata_word_248d0 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_248d8 = 0x0000000000024450ULL;
static uint64_t k_persist_rodata_word_248e0 = 0x00000000000004e0ULL;
static uint64_t k_persist_rodata_word_248e8 = 0x0000000400000000ULL;
static uint64_t k_persist_rodata_word_248f0 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_248f8 = 0x0000000000000001ULL;
static uint64_t k_persist_rodata_word_24900 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_24908 = 0x0000004800000019ULL;
static uint64_t k_persist_rodata_word_24910 = 0x44454b4e494c5f5fULL;
static uint64_t k_persist_rodata_word_24918 = 0x0000000000005449ULL;
static uint64_t k_persist_rodata_word_24920 = 0x0000000000028000ULL;
static uint64_t k_persist_rodata_word_24928 = 0x0000000000008000ULL;
static uint64_t k_persist_rodata_word_1eca0 = 0xffffffffffffffffULL;
static uint64_t k_persist_rodata_word_1ecb0 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_1ecf0 = 0x0000000e00000001ULL;
static uint64_t k_persist_rodata_word_1ed30 = 0x0000000000000008ULL;
static uint64_t k_persist_rodata_word_1ed40 = 0x000000000000000aULL;
static uint64_t k_persist_rodata_word_1ed58 = 0x0000000000001000ULL;
static uint64_t k_persist_rodata_word_24458 = 0x0000000600000000ULL;
static uint64_t k_persist_rodata_word_24468 = 0x0000000000100085ULL;
static void *k_persist_nsconcreteglobalblock_slot = (void *)0x0000000000000000ULL;
static void *k_persist_nsconcreteglobalblock_slot = (void *)0x0000000000000000ULL;
static void *k_persist_nsconcretestackblock_slot = (void *)0x0000000000000000ULL;
static void *k_persist_chkstk_darwin_slot = (void *)0x0000000000000000ULL;
static void *k_persist_cxa_finalize_ranges_slot = (void *)0x0000000000000000ULL;
static void *k_persist_stack_chk_guard_slot = (void *)0x0000000000000000ULL;
static void *k_persist_dladdr_slot = (void *)0x0000000000000000ULL;
static void *k_persist_dlsym_slot = (void *)0x0000000000000000ULL;
static void *k_persist_dyldversionnumber_slot = (void *)0x0000000000000000ULL;
static void *k_persist_mach_task_self_slot = (void *)0x0000000000000000ULL;
static void *k_persist_strcmp_slot = (void *)0x0000000000000000ULL;
static void *k_persist_task_get_exc_guard_behavior_slot = (void *)0x0000000000000000ULL;
static void *k_persist_task_set_exc_guard_behavior_slot = (void *)0x0000000000000000ULL;
static void *k_persist_vm_page_mask_slot = (void *)0x0000000000000000ULL;
coruna_svc_regpack_t coruna_bsdthread_create(uint64_t arg)

{
  bool in_CY;
  uint64_t u;
  uint8_t u[16];
  uint64_t size;
  
  CallSupervisor(0x80);
  u = arg;
  size = 0;
  if (in_CY) {
    u = 0xffffffffffffffff;
    size = arg;
  }
  u = size;
  u = u;
  return u;
}



coruna_svc_regpack_t coruna_bsdthread_terminate(uint64_t arg)

{
  bool in_CY;
  uint64_t u;
  uint8_t u[16];
  uint64_t size;
  
  CallSupervisor(0x80);
  u = arg;
  size = 0;
  if (in_CY) {
    u = 0xffffffffffffffff;
    size = arg;
  }
  u = size;
  u = u;
  return u;
}





void coruna_mach_port_construct(void)
{
  CallSupervisor(0x80);
  return;
}





void coruna_mach_port_construct_2(void)
{
  CallSupervisor(0x80);
  return;
}





void coruna_mach_port_construct_3(void)
{
  CallSupervisor(0x80);
  return;
}





void coruna_mach_port_construct_4(void)
{
  CallSupervisor(0x80);
  return;
}





void coruna_mach_port_construct_5(void)
{
  CallSupervisor(0x80);
  return;
}





void coruna_mach_port_construct_6(void)
{
  CallSupervisor(0x80);
  return;
}





void coruna_mach_port_construct_7(void)
{
  CallSupervisor(0x80);
  return;
}





void coruna_mach_port_construct_8(void)
{
  CallSupervisor(0x80);
  return;
}





void coruna_mach_port_construct_9(void)
{
  CallSupervisor(0x80);
  return;
}





uint64_t coruna_persistb080_residual_124(uint64_t *val)
{
  void (*ptr)(void);
  uint64_t u;
  unsigned long size;
  
  if (val == (uint64_t *)0x0) {
    u = 0xad001;
  }
  else if (*(char *)(val + 0x13) == '\0') {
    u = 0;
  }
  else {
    if (*(int *)(val + 0xd) != 0) {
      size = 0;
      do {
        ptr = (void (*)coruna_persistb080_via_pacia(*(uint64_t *)(val[0xc] + size * 8),0);
        (*ptr)();
        size = size + 1;
      } while (size < *(uint *)(val + 0xd));
    }
    coruna_persistb080_residual_138(*val,*(uint32_t *)(val + 1));
    u = 0;
    *(uint8_t *)(val + 0x13) = 0;
  }
  return u;
}





char * coruna_persistb080_str_goto_lab_000073d8(long *handle,uint64_t val,uint64_t id_2,uint64_t size_3,
                   uint32_t *size)
{
  uint64_t *ptr;
  uint u;
  uint32_t *buf;
  char err;
  int err;
  char *ptr;
  long handle;
  void (*buf)(void);
  long *ptr;
  long addr;
  long off;
  unsigned long size;
  long base;
  long ctx_val;
  uint32_t scratch;
  long bootargs;
  uint64_t thread_attr;
  uint32_t *host_info;
  uint64_t *serial_buf;
  uint64_t *action;
  uint64_t block_ctx;
  
  if (handle == (long *)0x0) {
    return (char *)0xad001;
  }
  err = coruna_buf_valid(val);
  if (err == 0) {
    return (char *)0xad001;
  }
  err = coruna_slice_valid(id_2);
  if (err == 0) {
    return (char *)0xad001;
  }
  bootargs = 0;
  buf = &scratch;
  if (size != (uint32_t *)0x0) {
    buf = size;
  }
  *buf = 4;
  ptr = (char *)coruna_persistb080_str_plvar7_0x10_0_plvar7_0x11(&bootargs,val,id_2,size_3);
  if ((int)ptr != 0) {
    return ptr;
  }
  *buf = 5;
  addr = bootargs;
  if (bootargs == 0) {
fail:
    ptr = (char *)0xad001;
  }
  else {
    if (*(int *)(bootargs + 0x28) == 0) {
      *buf = 6;
    }
    else {
      off = 0;
      size = 0;
      do {
        base = *(long *)(addr + 0x20);
        handle = coruna_persistb080_residual_128(*(uint64_t *)(base + off),8);
        ctx_val = bootargs;
        if (handle == 0) {
          ptr = "wnd";
          coruna_ctx_clear_8c84(bootargs);
          return ptr;
        }
        *(long *)(base + off + 8) = handle;
        size = size + 1;
        off = off + 0x10;
      } while (size < *(uint *)(addr + 0x28));
      *buf = 6;
      addr = ctx_val;
      if (ctx_val == 0) goto fail;
    }
    if (*(int *)(addr + 0x38) != 0) {
      off = 0;
      size = 0;
      do {
        ctx_val = *(long *)(addr + 0x30);
        if (ctx_val == 0) goto fail;
        handle = *(long *)(*(long *)(ctx_val + off + 0x20) + 8);
        if (handle == 0) {
          ptr = "nd";
          coruna_ctx_clear_8c84(bootargs);
          return ptr;
        }
        ptr = *(char **)(ctx_val + off + 0x10);
        if (*ptr == '_') {
          ptr = ptr + 1;
        }
        handle = coruna_persistb080_residual_129(handle,ptr);
        if (handle == 0) {
          if (*(char *)(ctx_val + off + 0x28) == '\0') {
            ptr = "d";
            coruna_ctx_clear_8c84(bootargs);
            return ptr;
          }
          handle = 0;
        }
        else {
          handle = *(long *)(ctx_val + off + 0x18) + handle;
        }
        ptr = *(long **)(ctx_val + off);
        err = *(char *)((uint64_t *)(ctx_val + off) + 1);
        if (err == '\x03') {
          *(int *)ptr = ((int)handle - (int)ptr) + -4;
        }
        else if (err == '\x02') {
          *(int *)ptr = (int)handle;
        }
        else {
          if (err != '\x01') {
            ptr = (char *)0x91000e;
            coruna_ctx_clear_8c84(bootargs);
            return ptr;
          }
          *ptr = handle;
        }
        size = size + 1;
        off = off + 0x30;
      } while (size < *(uint *)(addr + 0x38));
    }
    if (*(int *)(addr + 0x48) == 0) {
      ptr = (char *)coruna_persistb080_str_if_uvar6_uvar3(bootargs);
      if ((int)ptr == 0) {
        coruna_log_msg(id_2);
        *buf = 7;
        addr = bootargs;
        ptr = (char *)0xad001;
        if (bootargs != 0) {
          if (*(int *)(bootargs + 0x58) != 0) {
            size = 0;
            ptr = (uint64_t *)(bootargs + 0x70);
            do {
              host_info = *(uint32_t **)(addr + 0x78);
              thread_attr = *ptr;
              action = *(uint64_t **)(addr + 0x88);
              serial_buf = *(uint64_t **)(addr + 0x80);
              block_ctx = *(uint64_t *)(addr + 0x90);
              buf = (void (*)coruna_persistb080_via_pacia(*(uint64_t *)(*(long *)(addr + 0x50) + size * 8),0
                                           );
              (*buf)(*host_info,*serial_buf,*action,0,&thread_attr);
              size = size + 1;
            } while (size < *(uint *)(addr + 0x58));
          }
          *(uint8_t *)(addr + 0x98) = 1;
          *handle = bootargs;
          return (char *)0x0;
        }
      }
    }
    else {
      u = 0xad001;
      if (*(long *)(addr + 0x40) != 0) {
        u = 0x1f042;
      }
      ptr = (char *)(unsigned long)u;
    }
  }
done:
  coruna_ctx_clear_8c84(bootargs);
  return ptr;
}





void coruna_ret_stub(void)
{
  coruna_persistb080_via_cf_bundle();
  return;
}





void coruna_persist_residual_41(void)
{
  coruna_implant_trampoline_fn indirect_target;
  (*indirect_target)();
  return;
}





void coruna_persistb080_residual_125(void)
{
  void (*ptr)(void);
  ptr = (void (*)UndefinedInstructionException(0x11,0x10);
  (*ptr)();
}





bool coruna_cf_bundle(void)
{
  bool err;
  uint u;
  int err;
  long handle;
  unsigned long size;
  uint version;
  char scratch [8];
  char scratch [8];
  
  u = coruna_persistb080_residual_139();
  if (u == 0) {
    err = false;
  }
  else {
    err = false;
    version = 0;
    do {
      handle = coruna_persistb080_residual_140(version);
      if (handle == 0) {
fail:
        if (err) {
          return true;
        }
      }
      else {
        err = coruna_driver_copy_port_1918(handle,"CoreFoundation");
        if (err == 0) {
          return true;
        }
        scratch[0] = s__CoreFoundation_0001ede4[8];
        scratch[1] = s__CoreFoundation_0001ede4[9];
        scratch[2] = s__CoreFoundation_0001ede4[10];
        scratch[3] = s__CoreFoundation_0001ede4[0xb];
        scratch[4] = s__CoreFoundation_0001ede4[0xc];
        scratch[5] = s__CoreFoundation_0001ede4[0xd];
        scratch[6] = s__CoreFoundation_0001ede4[0xe];
        scratch[7] = s__CoreFoundation_0001ede4[0xf];
        scratch[0] = s__CoreFoundation_0001ede4[0];
        scratch[1] = s__CoreFoundation_0001ede4[1];
        scratch[2] = s__CoreFoundation_0001ede4[2];
        scratch[3] = s__CoreFoundation_0001ede4[3];
        scratch[4] = s__CoreFoundation_0001ede4[4];
        scratch[5] = s__CoreFoundation_0001ede4[5];
        scratch[6] = s__CoreFoundation_0001ede4[6];
        scratch[7] = s__CoreFoundation_0001ede4[7];
        size = coruna_driver_free_ctx(handle);
        if (0xe < size) {
          err = coruna_driver_copy_port_1918(size + handle + -0xf,scratch);
          err = err == 0;
          goto fail;
        }
        err = false;
      }
      version = version + 1;
    } while (version < u);
  }
  return err;
}





char * coruna_load_libdyld(unsigned long arg,long *handle)
{
  int *err;
  long handle;
  uint u;
  unsigned long size;
  byte err;
  int *status;
  int *flags;
  int *count;
  bool status;
  byte flags;
  int err;
  int status;
  char *ptr;
  char *buf;
  uint version;
  byte *ptr;
  byte *buf;
  uint *ptr;
  uint *buf;
  int *idx;
  long *str;
  byte *copy;
  long addr;
  int *i;
  int *j;
  unsigned long port;
  unsigned long tag;
  unsigned long kind;
  unsigned long type_id;
  int *scratch;
  int *bootargs;
  long thread_attr;
  unsigned long host_info;
  uint64_t serial_buf;
  int sym_match;
  
  sym_match = 0;
  if (handle == (long *)0x0) {
    return "CredentialManagerDaemon";
  }
  if ((arg & 1) == 0) {
    serial_buf = (byte *)0x0;
    err = coruna_persistb080_str_credentialmanagerdaemon(0,&serial_buf);
    if (((err == 0) && (copy = *(byte **)((long)serial_buf + 0x20), copy != (byte *)0x0)) &&
       (*(int *)copy == -0x1120531)) {
      ptr = copy + 0x20;
      buf = ptr + *(uint *)(copy + 0x14);
      if ((0x47 < *(uint *)(copy + 0x14) && ptr < buf) && (ptr <= buf + -0x48)) {
        err = 0;
        type_id = 0;
        tag = 0;
        do {
          port = type_id;
          kind = tag;
          if ((*(int *)ptr == 0x19) &&
             (err = coruna_driver_copy_port_1918(ptr + 8,"__PAGEZERO"), err != 0)) {
            size = *(unsigned long *)(ptr + 0x18);
            status = (bool)(size < tag | err ^ 1);
            err = status | err;
            kind = size;
            if (!status) {
              kind = tag;
            }
            port = *(long *)(ptr + 0x20) + size;
            if (*(long *)(ptr + 0x20) + size <= type_id) {
              port = type_id;
            }
          }
          ptr = ptr + *(uint *)(ptr + 4);
          type_id = port;
          tag = kind;
        } while (ptr <= buf + -0x48);
        type_id = port - kind;
        if (((bool)(err & (kind <= port && type_id != 0))) && (type_id < 0xffffffff)) {
          version = (uint)type_id;
          if (version < 0xe) {
            /* fall through to done */
          }
          else {
            if (0x16 < version) {
              serial_buf = copy;
              if (copy < copy + (version - 0x16) + 1) {
                do {
                  if (*serial_buf == 0x5f) {
                    addr = 1;
                    while (serial_buf[addr] == "__dyld_dlsym_internal"[addr]) {
                      addr = addr + 1;
                      if (addr == 0x16) {
                        sym_match = 1;
                        break;
                      }
                    }
                    if (sym_match != 0) break;
                  }
                  status = serial_buf < copy + (version - 0x16);
                  serial_buf = serial_buf + 1;
                } while (status);
              }
            }
            if (sym_match == 0) {
              serial_buf = copy;
              if (copy < copy + (version - 0xd) + 1) {
                do {
                  if (*serial_buf == 0x5f) {
                    addr = 1;
                    while (serial_buf[addr] == "__dyld_dlsym"[addr]) {
                      addr = addr + 1;
                      if (addr == 0xd) {
                        sym_match = 1;
                        break;
                      }
                    }
                    if (sym_match != 0) break;
                  }
                  status = serial_buf < copy + (version - 0xd);
                  serial_buf = serial_buf + 1;
                } while (status);
              }
            }
          }
        }
      }
    }
  }
  if (sym_match != 0) {
    if (8 < version) {
      ptr = copy + (unsigned long)(version - 8) + 1;
      for (; copy < ptr; copy = copy + 8) {
        if ((uint)*copy == ((uint)serial_buf & 0xff)) {
          addr = 1;
          while (copy[addr] == *(byte *)((long)&serial_buf + addr)) {
            addr = addr + 1;
            if (addr == 8) {
              if (!((*(void (**)(copy + 8) == (void (*)0x0) ||
                    (addr = (**(void (**)(copy + 8))(0xfffffffffffffffe,"dlsym",0), addr == 0)))) {
                *handle = addr;
                return (char *)0x0;
              }
              break;
            }
          }
        }
      }
    }
  }
done:
  serial_buf = (byte *)0x0;
  ptr = (char *)coruna_persistb080_str_credentialmanagerdaemon(arg,&serial_buf);
  if ((int)ptr != 0) {
    return ptr;
  }
  version = *(uint *)((long)serial_buf + 4);
  if (version == 0) {
    return "dentialManagerDaemon";
  }
  str = *(long **)((long)serial_buf + 8);
  if (str == (long *)0x0) {
    return "entialManagerDaemon";
  }
  type_id = 1;
  do {
    if (((*str == 0) || (str[1] == 0)) ||
       (err = coruna_driver_copy_port_1918(str[1],"/usr/lib/system/libdyld.dylib"), err != 0)) {
      addr = 0;
    }
    else {
      addr = *str;
      if (addr != 0) break;
    }
    str = str + 3;
    status = type_id < version;
    type_id = type_id + 1;
  } while (status);
  if (addr == 0) {
    return "redentialManagerDaemon";
  }
  j = (int *)(addr + 0x20);
  err = (int *)((long)j + (unsigned long)*(uint *)(addr + 0x14));
  if (err <= j) {
    return "n";
  }
  scratch = (int *)0x0;
  bootargs = (int *)0x0;
  idx = (int *)0x0;
  i = (int *)0x0;
  ptr = "on";
  do {
    status = j + 2;
    if (err < status) {
      return ptr;
    }
    version = j[1];
    if (version < 8 || err < (int *)((long)j + (unsigned long)version)) {
      return ptr;
    }
    err = *j;
    flags = scratch;
    count = bootargs;
    if (err < 0x19) {
      if (err == -0x7fffffde) {
skip:
        u = 0x1f02d;
        if (0x2f < version) {
          u = 0;
        }
        buf = (char *)(unsigned long)u;
        idx = j;
      }
      else {
        u = 0x1f02d;
        if (0xf < version) {
          u = 0;
        }
        status = j;
        if (err != -0x7fffffcd) {
          u = 0;
          status = i;
        }
        i = status;
        buf = (char *)(unsigned long)u;
      }
    }
    else {
      if (err == 0x22) goto skip;
      if (err == 0x19) {
        if (version < 0x48) {
          return ptr;
        }
        buf = (char *)coruna_driver_copy_port_1918(status,"__TEXT");
        flags = j;
        if ((int)buf != 0) {
          err = coruna_driver_copy_port_1918(status,"__LINKEDIT");
          buf = (char *)0x0;
          flags = scratch;
          count = j;
          if (err != 0) {
            count = bootargs;
          }
        }
      }
      else {
        buf = (char *)0x0;
      }
    }
    bootargs = count;
    scratch = flags;
  } while (((int)buf == 0) &&
          (j = (int *)((long)j + (unsigned long)(uint)j[1]), j < err));
  if ((int)buf != 0) {
    return buf;
  }
  if (scratch == (int *)0x0) {
    return "n";
  }
  if (bootargs == (int *)0x0) {
    return "";
  }
  if ((idx == (int *)0x0) && (i == (int *)0x0)) {
    return "peakpowermanagerd";
  }
  type_id = *(unsigned long *)(bootargs + 8);
  if (idx == (int *)0x0) {
    return "powermanagerd";
    buf = (uint *)(i + 2);
    ptr = (uint *)(i + 3);
  }
  else {
    buf = (uint *)(idx + 10);
    ptr = (uint *)(idx + 0xb);
  }
  version = *ptr;
  if (version != 0) {
    ptr = "kpowermanagerd";
    tag = (unsigned long)*buf - *(unsigned long *)(bootargs + 10);
    if ((unsigned long)*buf < *(unsigned long *)(bootargs + 10) || tag == 0) {
      return ptr;
    }
    if (type_id <= tag) {
      return ptr;
    }
    if (type_id < version) {
      return ptr;
    }
    kind = tag + version;
    if (type_id < kind) {
      return ptr;
    }
    handle = (addr - *(long *)(scratch + 6)) + *(long *)(bootargs + 6);
    if ((handle != 0) && ((long)tag < (long)kind)) {
      host_info = 0;
      err = 0;
      copy = (byte *)(handle + kind);
      ptr = "_dlsym";
      while (serial_buf = (byte *)(handle + tag + host_info), serial_buf < copy) {
        host_info = 0;
        status = coruna_return_zero_6d64(&serial_buf,copy,&host_info);
        if (status == 0) break;
        if (host_info == 0) {
          buf = (byte *)0x0;
          ptr = (byte *)0x0;
        }
        else {
          if ((long)host_info < 0) break;
          ptr = serial_buf + host_info;
          buf = serial_buf;
        }
        serial_buf = serial_buf + host_info;
        if (copy <= serial_buf) break;
        if (*ptr == '\0') {
          if (buf == (byte *)0x0) break;
          host_info = 0;
          if (ptr <= copy) {
            copy = ptr;
          }
          thread_attr = 0;
          serial_buf = buf;
          err = coruna_return_zero_6d64(&serial_buf,copy,&host_info);
          if ((err == 0) ||
             (type_id = coruna_return_zero_6d64(&serial_buf,copy,&thread_attr), (type_id & 1) == 0)) break;
          if (1 < (host_info & 3)) {
            if ((host_info & 3) != 2) break;
            addr = 0;
          }
          if (thread_attr == 0) {
            return "akpowermanagerd";
          }
          addr = addr + thread_attr;
          if (addr == 0) {
            return "eakpowermanagerd";
          }
check_ok:
          *handle = addr;
          return (char *)0x0;
        }
        err = *serial_buf;
        serial_buf = serial_buf + 1;
        if (err == 0 || copy <= serial_buf) break;
        version = 0;
        while( true ) {
          type_id = 0;
          status = true;
          ptr = serial_buf;
          while( true ) {
            if (*ptr == 0) break;
            if (status == false) {
              status = false;
            }
            else {
              status = *ptr == ptr[type_id];
            }
            type_id = (unsigned long)((int)type_id + 1);
            ptr = serial_buf + type_id;
            if (copy <= ptr) goto retry;
          }
          serial_buf = serial_buf + ((int)type_id + 1);
          host_info = 0;
          flags = coruna_return_zero_6d64(&serial_buf,copy,&host_info);
          if ((flags & status) != 0) break;
          version = version + 1;
          if ((flags & version < err) != 1 || copy <= serial_buf) goto retry;
        }
        ptr = ptr + type_id;
        err = err + 1;
        if (err == 0x65) break;
      }
    }
retry:
    return "akpowermanagerd";
  }
next:
  return "powermanagerd";
}





char * coruna_persistb080_str_credentialmanagerdaemon(uint64_t val,long *handle)
{
  int err;
  uint64_t u;
  char *ptr;
  int scratch;
  long bootargs [2];
  uint32_t thread_attr;
  
  ptr = "ppleCredentialManagerDaemon";
  if (handle == (long *)0x0) {
    ptr = "CredentialManagerDaemon";
  }
  else {
    u = coruna_persistb080_via_mach_port_construct_5();
    if ((int)u + 1U < 2) {
      ptr = "eCredentialManagerDaemon";
    }
    else {
      bootargs[0] = 0;
      bootargs[1] = 0;
      thread_attr = 0;
      scratch = 5;
      err = coruna_persistb080_via_memcpy(u,0x11,bootargs,&scratch,val);
      if (err == 0) {
        if (scratch == 5) {
          if (bootargs[0] != 0) {
            ptr = (char *)0x0;
            *handle = bootargs[0];
          }
        }
        else {
          ptr = "pleCredentialManagerDaemon";
        }
      }
      else {
        ptr = "leCredentialManagerDaemon";
      }
    }
  }
  return ptr;
}





uint8_t coruna_return_zero_6d64(uint64_t *val,byte *arg,unsigned long *arg_x)
{
  byte err;
  uint8_t u;
  unsigned long size;
  byte *ptr;
  unsigned long version;
  byte *buf;
  
  u = 0;
  if (val != (uint64_t *)0x0) {
    ptr = (byte *)*val;
    if (ptr == (byte *)0x0 || arg == (byte *)0x0) {
      return 0;
    }
    if (ptr < arg) {
      version = 0;
      size = 0;
      do {
        buf = ptr + 1;
        err = *ptr;
        size = ((unsigned long)err & 0x7f) << (version & 0x3f) | size;
        if ((-1 < (char)err) || (arg <= buf)) {
          if ((char)err < '\0') goto fail;
          u = 1;
          goto done;
        }
        version = version + 7;
        ptr = buf;
      } while ((int)version - 7U < 0x39);
      u = 0;
      if (-1 < (char)err) {
done:
        *val = buf;
        if (arg_x != (unsigned long *)0x0) {
          *arg_x = size;
        }
      }
    }
    else {
fail:
      u = 0;
    }
  }
  return u;
}





char * coruna_persistb080_str_credentialmanagerdaemon_2(long handle,long addr_2,uint64_t val,uint64_t *id_2,
                   uint64_t size_3)
{
  int err;
  char *ptr;
  uint64_t scratch;
  
  ptr = "CredentialManagerDaemon";
  if (((handle != 0) && (addr_2 != 0)) && (id_2 != (uint64_t *)0x0)) {
    err = coruna_buf_valid();
    if (err == 0) {
      if (*(int *)(handle + 8) == 0) {
        ptr = (char *)0x0;
        *id_2 = 0;
      }
      else {
        ptr = "rmanagerd";
      }
    }
    else {
      scratch = 0;
      ptr = (char *)coruna_persistb080_str_goto_lab_000073d8(&scratch,handle,addr_2,val,size_3);
      if ((int)ptr == 0) {
        *id_2 = scratch;
      }
    }
  }
  return ptr;
}





void coruna_persistb080_via_ctx_clear_8c84(long handle)
{
  if (handle != 0) {
    coruna_ctx_clear_8c84();
    return;
  }
  return;
}





bool coruna_buf_valid(unsigned long *arg)
{
  bool err;
  unsigned long u;
  
  err = false;
  if (arg != (unsigned long *)0x0) {
    u = *arg;
    if (u == 0) {
      return false;
    }
    err = false;
    if ((uint)arg[1] != 0) {
      err = u < u + (uint)arg[1];
    }
  }
  return err;
}





bool coruna_slice_valid(long *handle)
{
  bool err;
  
  err = false;
  if (handle != (long *)0x0) {
    if (*handle == 0) {
      return false;
    }
    err = (int)handle[1] != 0;
  }
  return err;
}





uint64_t coruna_log_msg(long *handle)
{
  uint64_t u;
  
  u = 0;
  if (handle != (long *)0x0) {
    if (((int)handle[1] != 0) && (*handle != 0)) {
      coruna_memset(*handle,0);
    }
    u = 1;
  }
  return u;
}





uint32_t coruna_persistb080_via_mach_port_construct_8(long *handle,int flags)
{
  int err;
  uint64_t u;
  uint32_t size;
  
  size = 0x1f018;
  if (handle != (long *)0x0) {
    if ((*handle == 0) || ((int)handle[1] == 0)) {
      size = 0;
    }
    else {
      if (flags != 0) {
        coruna_memset(*handle,0);
      }
      u = coruna_persistb080_via_mach_port_construct_5();
      err = coruna_mach_port_construct_8(u,*handle,(int)handle[1]);
      size = 0;
      if (err != 0) {
        size = 0x1f035;
      }
    }
  }
  return size;
}





uint64_t coruna_persistb080_via_mach_port_construct_8_2(long handle)
{
  uint64_t u;
  
  if (handle != 0) {
    coruna_persistb080_residual_143(2);
    coruna_persistb080_residual_143();
    coruna_persistb080_residual_143();
    u = coruna_persistb080_via_mach_port_construct_5();
    coruna_mach_port_construct_8(u,handle,0x4000);
  }
  return 0;
}





uint64_t coruna_persistb080_via_cf_bundle(uint64_t val,uint64_t id_2,long handle)
{
  int err;
  int status;
  char *ptr;
  uint64_t u;
  long handle;
  long addr;
  void (*buf)(void);
  unsigned long size;
  uint64_t scratch;
  long *bootargs;
  uint32_t thread_attr;
  long host_info;
  unsigned long serial_buf;
  
  if (handle != 0) {
    host_info = 0;
    serial_buf = 0;
    thread_attr = 2;
    err = *(int *)(handle + 0x50);
    size = *(unsigned long *)(handle + 0x58) >> 1 & 1;
    *(uint32_t *)(handle + 0x50) = 0;
    ptr = (char *)coruna_persistb080_via_load_libdyld(size);
    if ((int)ptr == 0) {
      if (*(long *)(handle + 0x80) != 0) {
        coruna_persistb080_via_mach_port_construct_8_2();
        *(uint64_t *)(handle + 0x80) = 0;
      }
      if (((*(byte *)(handle + 0x58) & 1) == 0) && (status = coruna_cf_bundle(), status == 0)) {
        ptr = "d";
      }
      else {
        bootargs = (long *)0x0;
        thread_attr = 4;
        ptr = (char *)coruna_persistb080_str_else_pcvar5(&bootargs,handle);
        if ((int)ptr == 0) {
          *(uint64_t *)(handle + 0x20) = 0;
          *(uint32_t *)(handle + 0x28) = 0;
          coruna_persistb080_via_persistb080_via_mach_port_construct_8(handle,&host_info);
          handle = host_info;
          scratch = 0;
          addr = *bootargs;
          thread_attr = 3;
          ptr = (char *)coruna_persistb080_str_credentialmanagerdaemon_2(bootargs,bootargs + 2,addr != host_info,&scratch,&thread_attr)
          ;
          if ((int)ptr == 0) {
            handle = bootargs[4];
            coruna_persistb080_str_credentialmanagerdaemon_5(bootargs + 2);
            coruna_persistb080_residual_126(err,3,0,size);
            thread_attr = 0x10;
            if (handle == 0) {
              ptr = (char *)0x0;
            }
            else {
              u = coruna_identity_6080(handle);
              buf = (void (*)coruna_persistb080_via_pacia(u,0);
              ptr = (char *)(*buf)(bootargs[5],(int)bootargs[6],*bootargs,(int)bootargs[1],
                                         err);
            }
            coruna_persistb080_via_ctx_clear_8c84(scratch);
          }
          else if (addr != handle) {
            coruna_persistb080_via_mach_port_construct_8(bootargs,0);
          }
          coruna_persistb080_via_persistb080_str_credentialmanagerdaemon_5(bootargs);
          handle = 0;
        }
      }
    }
    if (1 < err + 1U) {
      coruna_persistb080_residual_126(err,thread_attr,ptr,size);
      u = coruna_persistb080_via_mach_port_construct_5();
      coruna_mach_port_construct_5(u,err);
    }
    if (handle != 0) {
      coruna_persistb080_via_persistb080_via_mach_port_construct_8(handle,&host_info);
    }
    if ((host_info != 0) && ((int)serial_buf != 0)) {
      handle = coruna_ret_stub_2();
      addr = coruna_ret_stub_3();
      if ((handle == 0) || (addr == 0)) {
        coruna_bsdthread_terminate(host_info,serial_buf & 0xffffffff,0,0);
      }
      else {
        u = coruna_persistb080_via_mach_port_construct_5();
        coruna_persist_residual_41(u,host_info,serial_buf & 0xffffffff,handle,addr,val);
      }
    }
  }
  return 0;
}





void coruna_persistb080_via_persistb080_via_mach_port_construct_8(long *handle,long *addr_2)
{
  uint64_t u;
  long handle;
  long scratch;
  long bootargs;
  
  if (handle != (long *)0x0) {
    bootargs = handle[3];
    scratch = handle[2];
    if (addr_2 != (long *)0x0) {
      handle = *handle;
      addr_2[1] = handle[1];
      *addr_2 = handle;
    }
    if (1 < (int)handle[10] + 1U) {
      u = coruna_persistb080_via_mach_port_construct_5();
      coruna_mach_port_construct_5(u,(int)handle[10]);
    }
    if (handle[4] != *handle) {
      coruna_persistb080_via_mach_port_construct_8(handle + 4,0);
    }
    coruna_persistb080_via_mach_port_construct_8(&scratch,1);
  }
  return;
}





void coruna_persistb080_residual_126(int flags,uint32_t size,uint32_t flags_2,int count_2)
{
  uint64_t scratch;
  int bootargs;
  uint64_t thread_attr;
  uint32_t host_info;
  uint32_t scratch;
  uint32_t serial_buf;
  
  if (1 < flags + 1U) {
    thread_attr = 0;
    scratch = k_persist_rodata_word_1ec90;
    host_info = 5;
    bootargs = flags;
    scratch = size;
    serial_buf = flags_2;
    if (count_2 == 0) {
      coruna_persistb080_via_mach_port_construct_6(&scratch,0x11,0x20,100,0,100,0);
    }
    else {
      coruna_persistb080_via_mach_port_construct_7(&scratch,0x400000011,0x2000000013,flags,0x500000000,0,0,100);
    }
  }
  return;
}





uint64_t coruna_persistb080_residual_127(long handle)
{
  int err;
  uint64_t scratch;
  
  if (handle != 0) {
    err = coruna_persistb080_via_load_libdyld(*(unsigned long *)(handle + 0x58) >> 1 & 1);
    if ((err == 0) && (err = coruna_persistb080_residual_141(&scratch,0,coruna_ret_stub,handle), err == 0)) {
      coruna_persistb080_residual_142(scratch);
    }
  }
  return 0;
}
void coruna_persistb080_via_identity_6080(long handle,uint size,uint64_t val,uint32_t size_x,uint64_t id_2
                 ,uint32_t flags_2)
{
  long handle;
  uint8_t size[16];
  uint8_t u[16];
  int err;
  uint64_t u;
  void (*ptr)(void);
  uint64_t size;
  long addr;
  long unaff_x19;
  uint64_t unaff_x20;
  uint32_t unaff_w21;
  long *unaff_x22;
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t bootargs;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t action;
  uint8_t thread_attr[16];
  uint64_t host_info;
  uint32_t serial_buf;
  
  thread_attr = k_persist_rodata_word_0001eca8;
  thread_attr = k_persist_rodata_word_1eca0;
  u = k_persist_rodata_word_0001eca8;
  u = k_persist_rodata_word_1eca0;
  size = k_persist_rodata_word_0001eca8;
  size = k_persist_rodata_word_1eca0;
  host_info = id_2;
  serial_buf = flags_2;
  if ((handle != 0) && (0x8f < size)) {
    unaff_x22 = (long *)(handle + 0x60);
    if (((*unaff_x22 != 0) && (*(long *)(handle + 0x70) != 0)) && (*(int *)(handle + 0x78) != 0))
    goto fail;
    u = coruna_identity_6080(coruna_persistb080_residual_127);
    u = coruna_persistb080_via_pacia(u,0);
    thread_attr = coruna_bsdthread_create(u,handle,0x80000,0,0x4000000);
    *(long *)(handle + 0x80) = thread_attr;
    do {
      addr = thread_attr;
      if (thread_attr == -1) {
        scratch = 0;
        scratch = 0;
        handle = -addr;
        if (-1 < addr) {
          handle = addr;
        }
        coruna_persistb080_residual_126(*(uint32_t *)(handle + 0x50),1,(uint)handle | 0x40000000,
                     *(unsigned long *)(handle + 0x58) >> 1 & 1);
        coruna_persistb080_via_persistb080_via_mach_port_construct_8(handle,&scratch);
        unaff_x20 = id_2;
        u = thread_attr;
done:
        id_2 = unaff_x20;
        thread_attr = u;
        coruna_persistb080_via_persistb080_str_credentialmanagerdaemon_4(&host_info,&scratch);
      }
      coruna_bsdthread_terminate(id_2,flags_2,0,0);
      coruna_persistb080_via_bsdthread_terminate();
      size = thread_attr;
fail:
      host_info = 0;
      bootargs = 0;
      action = 0;
      serial_buf = 0;
      scratch = 0;
      scratch = 0;
      thread_attr = 0;
      bootargs = 0;
      thread_attr = size;
      u = coruna_identity_6080();
      ptr = (void (*)coruna_persistb080_via_pacia(u,0);
      u = coruna_identity_6080(coruna_ret_stub);
      u = coruna_persistb080_via_pacia(u,0);
      coruna_memcpy(&scratch,*(uint64_t *)(handle + 0x70),*(uint32_t *)(handle + 0x78));
      size = coruna_persistb080_via_mach_port_construct_5();
      coruna_mach_port_construct_8(size,*(uint64_t *)(handle + 0x70),*(uint32_t *)(handle + 0x78));
      coruna_memset(unaff_x22,0,0x20);
      err = (*ptr)(thread_attr,&scratch,u,handle);
      thread_attr = (long)err;
    } while( true );
  }
  scratch = coruna_u64_pack((scratch), (size_x));
  handle = unaff_x19;
  scratch = val;
  flags_2 = unaff_w21;
  goto done;
}
void coruna_persistb080_via_bsdthread_terminate(void)
{
  long *ptr;
  long *buf;
  unsigned long u;
  unsigned long extraout_x8;
  long handle;
  long extraout_x9;
  uint8_t version[16];
  
  coruna_bsdthread_terminate(0,0,0,0);
  version = coruna_persistb080_residual_125();
  buf = version;
  ptr = version;
  if ((ptr != (long *)0x0) && (((int)ptr[1] == 0 || (*ptr == 0)))) {
    *(uint32_t *)(ptr + 1) = 0;
    *ptr = 0;
  }
  if (buf != (long *)0x0) {
    u = (unsigned long)*(uint *)(buf + 1);
    if ((*(uint *)(buf + 1) != 0) && (handle = *buf, handle != 0)) goto fail;
    *(uint32_t *)(buf + 1) = 0;
    *buf = 0;
  }
  handle = *ptr;
  u = (unsigned long)*(uint *)(ptr + 1);
  do {
    coruna_bsdthread_terminate(handle,u,0,0);
    version = coruna_persistb080_via_bsdthread_terminate();
    u = extraout_x8;
    handle = extraout_x9;
fail:
    ptr = version;
  } while (*ptr == 0);
  k_persist_rodata_word_24458 = ptr[1];
  k_persist_rodata_word_24450 = *ptr;
  k_persist_rodata_word_24468 = version[1];
  k_persist_rodata_word_24460 = *version;
  coruna_memset(&k_persist_rodata_word_24470,0,0x400);
  coruna_persistb080_str_credentialmanagerdaemon_4();
  return;
}
void coruna_persistb080_via_persistb080_str_credentialmanagerdaemon_4(long *handle,long *addr_2)
{
  long *ptr;
  unsigned long u;
  unsigned long extraout_x8;
  long handle;
  long extraout_x9;
  uint8_t port[16];
  
  port = addr_2;
  port = handle;
  if ((handle != (long *)0x0) && (((int)handle[1] == 0 || (*handle == 0)))) {
    *(uint32_t *)(handle + 1) = 0;
    *handle = 0;
  }
  if (addr_2 != (long *)0x0) {
    u = (unsigned long)*(uint *)(addr_2 + 1);
    if ((*(uint *)(addr_2 + 1) != 0) && (handle = *addr_2, handle != 0)) goto fail;
    *(uint32_t *)(addr_2 + 1) = 0;
    *addr_2 = 0;
  }
  handle = *handle;
  u = (unsigned long)*(uint *)(handle + 1);
  do {
    coruna_bsdthread_terminate(handle,u,0,0);
    port = coruna_persistb080_via_bsdthread_terminate();
    u = extraout_x8;
    handle = extraout_x9;
fail:
    ptr = port;
  } while (*ptr == 0);
  k_persist_rodata_word_24458 = ptr[1];
  k_persist_rodata_word_24450 = *ptr;
  k_persist_rodata_word_24468 = port[1];
  k_persist_rodata_word_24460 = *port;
  coruna_memset(&k_persist_rodata_word_24470,0,0x400);
  coruna_persistb080_str_credentialmanagerdaemon_4();
  return;
}





char * coruna_persistb080_str_credentialmanagerdaemon_3(void)
{
  uint64_t u;
  long *ptr;
  long handle;
  
  coruna_persistb080_via_bsdthread_terminate();
  if (k_persist_rodata_word_24458 != 0 && k_persist_rodata_word_24450 != 0) {
    coruna_memset(k_persist_rodata_word_24450,0);
    u = coruna_persistb080_via_mach_port_construct_5();
    if (1 < (int)u + 1U) {
      coruna_mach_port_construct_8(u,k_persist_rodata_word_24450,k_persist_rodata_word_24458);
    }
  }
  coruna_bsdthread_terminate(k_persist_rodata_word_24460,k_persist_rodata_word_24468,0,0);
  ptr = (long *)coruna_persistb080_via_bsdthread_terminate();
  if (ptr != (long *)0x0) {
    handle = *ptr;
    if (handle != 0) {
      if ((int)ptr[1] != 0) {
        coruna_memset(handle,0);
        handle = *ptr;
      }
      coruna_persistb080_residual_132(handle);
    }
    *(uint32_t *)(ptr + 1) = 0;
    *ptr = 0;
    return (char *)0x0;
  }
  return "CredentialManagerDaemon";
}





char * coruna_persistb080_str_credentialmanagerdaemon_4(void)
{
  uint64_t u;
  long *ptr;
  long handle;
  
  if (k_persist_rodata_word_24458 != 0 && k_persist_rodata_word_24450 != 0) {
    coruna_memset(k_persist_rodata_word_24450,0);
    u = coruna_persistb080_via_mach_port_construct_5();
    if (1 < (int)u + 1U) {
      coruna_mach_port_construct_8(u,k_persist_rodata_word_24450,k_persist_rodata_word_24458);
    }
  }
  coruna_bsdthread_terminate(k_persist_rodata_word_24460,k_persist_rodata_word_24468,0,0);
  ptr = (long *)coruna_persistb080_via_bsdthread_terminate();
  if (ptr != (long *)0x0) {
    handle = *ptr;
    if (handle != 0) {
      if ((int)ptr[1] != 0) {
        coruna_memset(handle,0);
        handle = *ptr;
      }
      coruna_persistb080_residual_132(handle);
    }
    *(uint32_t *)(ptr + 1) = 0;
    *ptr = 0;
    return (char *)0x0;
  }
  return "CredentialManagerDaemon";
}





char * coruna_persistb080_str_credentialmanagerdaemon_5(long *handle)
{
  long handle;
  
  if (handle != (long *)0x0) {
    handle = *handle;
    if (handle != 0) {
      if ((int)handle[1] != 0) {
        coruna_memset(handle,0);
        handle = *handle;
      }
      coruna_persistb080_residual_132(handle);
    }
    *(uint32_t *)(handle + 1) = 0;
    *handle = 0;
    return (char *)0x0;
  }
  return "CredentialManagerDaemon";
}





char * coruna_persistb080_str_else_pcvar5(long *handle,long *addr_2)
{
  uint u;
  uint size;
  uint version;
  long *ptr;
  char *ptr;
  long handle;
  
  ptr = "CredentialManagerDaemon";
  if ((handle != (long *)0x0) && (addr_2 != (long *)0x0)) {
    if (((int)addr_2[5] == 0) || (addr_2[4] != 0)) {
      if (((int)addr_2[1] == 0) || (*addr_2 != 0)) {
        size = *(uint *)(addr_2 + 3);
        if ((size == 0) || (addr_2[2] != 0)) {
          if (*(int *)((long)addr_2 + 0x34) != 0) {
            version = *(uint *)(addr_2 + 6);
            if ((size <= version) || (u = version + *(int *)((long)addr_2 + 0x34), u <= version)
               ) {
              return "managerd";
            }
            if (size < u) {
              return "managerd";
            }
          }
          if (*(int *)((long)addr_2 + 0x4c) != 0) {
            version = *(uint *)(addr_2 + 9);
            if (size <= version) {
              return "nagerd";
            }
            u = version + *(int *)((long)addr_2 + 0x4c);
            if (u <= version) {
              return "nagerd";
            }
            if (size < u) {
              return "nagerd";
            }
          }
          ptr = (long *)coruna_persistb080_residual_131(1,0x40);
          if (ptr == (long *)0x0) {
            ptr = (char *)0xad009;
          }
          else {
            handle = addr_2[4];
            ptr[1] = addr_2[5];
            *ptr = handle;
            ptr = (char *)coruna_persistb080_str_credentialmanagerdaemon_6(ptr + 2,addr_2 + 6,addr_2 + 2);
            if ((int)ptr == 0) {
              ptr[4] = addr_2[8];
              ptr = (char *)coruna_persistb080_str_credentialmanagerdaemon_6(ptr + 5,addr_2 + 9,addr_2 + 2);
              if ((int)ptr == 0) {
                *handle = (long)ptr;
                return ptr;
              }
              coruna_persistb080_str_credentialmanagerdaemon_5(ptr + 2);
            }
            coruna_persistb080_residual_132(ptr);
          }
        }
        else {
          ptr = "rd";
        }
      }
      else {
        ptr = "erd";
      }
    }
    else {
      ptr = "rmanagerd";
    }
  }
  return ptr;
}





char * coruna_persistb080_str_credentialmanagerdaemon_6(long *handle,uint *size,long *addr_2)
{
  uint u;
  long handle;
  uint size;
  
  if (handle == (long *)0x0) {
    return "CredentialManagerDaemon";
  }
  if (size == (uint *)0x0) {
    return "CredentialManagerDaemon";
  }
  if (addr_2 == (long *)0x0) {
    return "CredentialManagerDaemon";
  }
  if (size[1] == 0) {
    size = 0;
    *handle = 0;
  }
  else {
    size = *size;
    if ((*(uint *)(addr_2 + 1) <= size) || (u = size + size[1], u <= size)) {
      return "agerd";
    }
    if (*(uint *)(addr_2 + 1) < u) {
      return "agerd";
    }
    handle = coruna_persistb080_residual_131(1);
    if (handle == 0) {
      return (char *)0xad009;
    }
    coruna_memcpy(handle,*addr_2 + (unsigned long)*size,size[1]);
    *handle = handle;
    size = size[1];
  }
  *(uint *)(handle + 1) = size;
  return (char *)0x0;
}





int coruna_persistb080_via_persistb080_str_credentialmanagerdaemon_5(long handle)
{
  int err;
  int status;
  
  if (handle == 0) {
    status = 0x1f018;
  }
  else {
    err = coruna_persistb080_str_credentialmanagerdaemon_5(handle + 0x28);
    status = coruna_persistb080_str_credentialmanagerdaemon_5(handle + 0x10);
    if (err != 0) {
      status = err;
    }
    coruna_memset(handle,0,0x40);
    coruna_persistb080_residual_132(handle);
  }
  return status;
}





unsigned long coruna_persistb080_via_mach_port_construct_5(void)

{
  unsigned long u;
  
  u = (unsigned long)k_persist_rodata_word_24870;
  if (k_persist_rodata_word_24870 == 0) {
    u = coruna_mach_port_construct_4();
    if ((uint)u != 0) {
      k_persist_rodata_word_24870 = (uint)u;
      coruna_mach_port_construct_5(u,u);
    }
  }
  return u;
}





uint64_t coruna_persistb080_residual_128(void)
{
  uint64_t u;
  
  if (k_persist_rodata_word_24880 != (void (*)0x0) {
    u = (*k_persist_rodata_word_24880)();
    return u;
  }
  return 0;
}





uint64_t coruna_persistb080_residual_129(void)
{
  uint64_t u;
  
  if (k_persist_rodata_word_24888 != (void (*)0x0) {
    u = (*k_persist_rodata_word_24888)();
    return u;
  }
  return 0;
}





uint64_t coruna_persistb080_residual_130(void)
{
  uint64_t u;
  
  if (k_persist_rodata_word_24890 != (void (*)0x0) {
    u = (*k_persist_rodata_word_24890)();
    return u;
  }
  return 0xffffffff;
}





uint64_t coruna_persistb080_residual_131(void)
{
  uint64_t u;
  
  if (k_persist_rodata_word_24898 != (void (*)0x0) {
    u = (*k_persist_rodata_word_24898)();
    return u;
  }
  return 0;
}





void coruna_persistb080_residual_132(long handle)
{
  if (k_persist_rodata_word_248a0 == (void (*)0x0 || handle == 0) {
    return;
  }
  (*k_persist_rodata_word_248a0)();
  return;
}





void coruna_persistb080_residual_133(void)
{
  if (k_persist_rodata_word_248b8 != (void (*)0x0) {
    (*k_persist_rodata_word_248b8)();
    return;
  }
  return;
}





void coruna_persistb080_residual_134(void)
{
  if (k_persist_rodata_word_248c0 != (void (*)0x0) {
    (*k_persist_rodata_word_248c0)();
    return;
  }
  return;
}





void coruna_persistb080_residual_135(void)
{
  if (k_persist_rodata_word_248c8 != (void (*)0x0) {
    (*k_persist_rodata_word_248c8)();
    return;
  }
  return;
}





void coruna_persistb080_residual_136(void)
{
  if (k_persist_rodata_word_248d0 != (void (*)0x0) {
    (*k_persist_rodata_word_248d0)();
    return;
  }
  return;
}





void coruna_persistb080_residual_137(void)
{
  if (k_persist_rodata_word_248d8 != (void (*)0x0) {
    (*k_persist_rodata_word_248d8)();
    return;
  }
  return;
}





void coruna_persistb080_residual_138(uint64_t val,uint64_t id_2)
{
  uint64_t scratch;
  uint64_t scratch;
  
  if (k_persist_rodata_word_248e8 == (void (*)0x0) {
    if (k_persist_rodata_word_248e0 != (void (*)0x0) {
      (*k_persist_rodata_word_248e0)();
      return;
    }
  }
  else {
    scratch = val;
    scratch = id_2;
    (*k_persist_rodata_word_248e8)(&scratch,1);
  }
  return;
}





void coruna_persistb080_residual_139(void)
{
  if (k_persist_rodata_word_248f0 != (void (*)0x0) {
    (*k_persist_rodata_word_248f0)();
    return;
  }
  return;
}





uint64_t coruna_persistb080_residual_140(uint64_t val)
{
  uint u;
  uint64_t size;
  
  if (((k_persist_rodata_word_248f8 != (void (*)0x0) && (k_persist_rodata_word_248f0 != (void (*)0x0)) &&
     (u = (*k_persist_rodata_word_248f0)(), (uint)val < u)) {
    size = (*k_persist_rodata_word_248f8)(val);
    return size;
  }
  return 0;
}





char * coruna_persistb080_via_load_libdyld(uint64_t val)
{
  long handle;
  char *ptr;
  long addr;
  void (*scratch)(void);
  
  if (k_persist_rodata_word_24878 == '\0') {
    scratch = k_persist_rodata_word_24888;
    if ((k_persist_rodata_word_24888 != (void (*)0x0) ||
       (ptr = (char *)coruna_load_libdyld(val,&scratch), (int)ptr == 0)) {
      addr = 0;
      ptr = (char *)0x0;
      k_persist_rodata_word_24888 = scratch;
      while( true ) {
        handle = (*scratch)(0xfffffffffffffffe,*(uint64_t *)((long)&k_persist_rodata_word_20070 + addr));
        if ((handle == 0) && (addr != 0x120)) {
          ptr = "";
        }
        else {
          **(long **)((long)&k_persist_rodata_word_20068 + addr) = handle;
        }
        if (addr == 0x198) break;
        addr = addr + 0x18;
      }
      k_persist_rodata_word_24878 = (int)ptr == 0;
    }
  }
  else {
    ptr = (char *)0x0;
  }
  return ptr;
}





uint64_t coruna_ret_stub_2(void)
{
  return k_persist_rodata_word_248a8;
}





uint64_t coruna_ret_stub_3(void)
{
  return k_persist_rodata_word_248b0;
}





uint64_t coruna_persistb080_residual_141(void)
{
  uint64_t u;
  
  if (k_persist_rodata_word_24900 != (void (*)0x0) {
    u = (*k_persist_rodata_word_24900)();
    return u;
  }
  return 0xffffffff;
}





uint64_t coruna_persistb080_residual_142(void)
{
  uint64_t u;
  
  if (k_persist_rodata_word_24908 != (void (*)0x0) {
    u = (*k_persist_rodata_word_24908)();
    return u;
  }
  return 0xffffffff;
}





uint64_t coruna_persistb080_residual_143(void)
{
  uint64_t u;
  
  if (k_persist_rodata_word_24910 != (void (*)0x0) {
    u = (*k_persist_rodata_word_24910)();
    return u;
  }
  return 0;
}
uint64_t coruna_persistb080_str_if_uvar6_uvar3(long handle)
{
  uint u;
  unsigned long size;
  unsigned long version;
  uint64_t *ptr;
  unsigned long port;
  unsigned long tag;
  
  if (handle != 0) {
    if (*(long *)(handle + 0x30) != 0) {
      coruna_persistb080_residual_132();
    }
    *(uint64_t *)(handle + 0x30) = 0;
    *(uint32_t *)(handle + 0x38) = 0;
    u = *(uint *)(handle + 0x28);
    if (u != 0) {
      size = (unsigned long)u + 1 & 0x1fffffffe;
      version = (unsigned long)u - 1;
      ptr = (uint64_t *)(*(long *)(handle + 0x20) + 0x10);
      port = k_persist_rodata_word_1ecb0;
      tag = k_persist_rodata_word_0001ecb8;
      do {
        if (port <= version) {
          ptr[-2] = "";
        }
        if (tag <= version) {
          *ptr = "";
        }
        port = port + 2;
        tag = tag + 2;
        ptr = ptr + 4;
        size = size - 2;
      } while (size != 0);
    }
    *(uint64_t *)(handle + 0x10) = 0;
    *(uint32_t *)(handle + 0x18) = 0;
    return 0;
  }
  return 0xad001;
}





unsigned long coruna_ctx_clear_8c84(uint64_t *arg)

{
  int err;
  unsigned long size;
  uint64_t version;
  long handle;
  uint port;
  uint tag;
  unsigned long kind;
  long addr;
  
  if (arg == (uint64_t *)0x0) {
    size = 0xad001;
  }
  else {
    size = coruna_persistb080_residual_124();
    if (*(char *)((long)arg + 0x99) != '\0') {
      version = coruna_persistb080_via_mach_port_construct_5();
      err = coruna_mach_port_construct_8(version,*arg,*(uint32_t *)(arg + 1));
      tag = (uint)size;
      port = 0x1f03d;
      if (tag != 0) {
        port = tag;
      }
      if (err != 0) {
        tag = port;
      }
      size = (unsigned long)tag;
    }
    handle = arg[4];
    if (handle != 0) {
      port = *(uint *)(arg + 5);
      if (port != 0) {
        kind = 0;
        addr = 8;
        do {
          if (*(long *)(handle + addr) != 0) {
            coruna_persistb080_residual_130(*(long *)(handle + addr));
            handle = arg[4];
            *(uint64_t *)(handle + addr) = 0;
            port = *(uint *)(arg + 5);
          }
          kind = kind + 1;
          addr = addr + 0x10;
        } while (kind < port);
      }
      coruna_persistb080_residual_132();
    }
    arg[4] = 0;
    *(uint32_t *)(arg + 5) = 0;
    if (arg[6] != 0) {
      coruna_persistb080_residual_132();
    }
    arg[6] = 0;
    *(uint32_t *)(arg + 7) = 0;
    if (arg[10] != 0) {
      coruna_persistb080_residual_132();
    }
    arg[10] = 0;
    *(uint32_t *)(arg + 0xb) = 0;
    if (arg[0xc] != 0) {
      coruna_persistb080_residual_132();
    }
    arg[0xc] = 0;
    *(uint32_t *)(arg + 0xd) = 0;
    if (arg[8] != 0) {
      coruna_persistb080_residual_132();
    }
    arg[8] = 0;
    *(uint32_t *)(arg + 9) = 0;
    coruna_memset(arg,0,0xa0);
    coruna_persistb080_residual_132(arg);
  }
  return size;
}





char * coruna_persistb080_str_plvar7_0x10_0_plvar7_0x11(long *handle,long *addr_2,long *off_3,uint8_t buf)
{
  long *ptr;
  long handle;
  long *buf;
  long *str;
  uint u;
  int err;
  long *copy;
  long addr;
  long off;
  long base;
  uint8_t *ptr;
  char *ptr;
  long ctx_val;
  long serial;
  uint size;
  unsigned long version;
  unsigned long scratch;
  long bootargs;
  unsigned long scratch;
  long thread_attr;
  unsigned long host_info;
  long serial_buf;
  unsigned long bootargs;
  long action;
  unsigned long block_ctx;
  long stack_guard;
  unsigned long thread_attr;
  long sa_saved;
  unsigned long sa_new;
  uint path_buf;
  uint tmp_buf;
  uint region;
  uint plist;
  uint url_buf;
  uint json_buf;
  uint frame;
  uint work;
  uint cache;
  uint cache_20;
  uint cache_21;
  uint cache_22;
  uint cache_23;
  uint cache_24;
  uint cache_25;
  byte cache_26;
  uint8_t host_info;
  uint8_t serial_buf;
  uint8_t action;
  long cache_27;
  
  if (handle == (long *)0x0) {
    return "ckdownd";
  }
  err = coruna_slice_valid(off_3);
  if (err == 0) {
fail:
    return "ckdownd";
  }
  err = coruna_buf_valid(addr_2);
  if (err == 0) {
    return "d";
  }
  return "ckdownd";
}





char * coruna_persistb080_str_verkitd(long *handle,long *addr_2,long off_3,uint size)
{
  long handle;
  char *ptr;
  unsigned long u;
  uint scratch;
  
  ptr = (char *)0xad001;
  if (((handle != (long *)0x0) && (addr_2 != (long *)0x0)) && ((size == 0 || (off_3 != 0))))
  {
    coruna_memset(handle,0,0x10);
    if (size == 0) {
      ptr = (char *)0x0;
      *handle = 0;
      *(uint32_t *)(handle + 1) = 0;
    }
    else {
      handle = coruna_persistb080_residual_131((unsigned long)size,8);
      if (handle == 0) {
        ptr = (char *)0xad009;
      }
      else {
        u = 0;
        do {
          scratch = 0;
          coruna_memcpy(&scratch,off_3,4);
          if (*(uint *)(addr_2 + 1) <= scratch) {
            coruna_persistb080_residual_132(handle);
            return "verkitd";
          }
          *(unsigned long *)(handle + u * 8) = *addr_2 + (unsigned long)scratch;
          u = u + 1;
          off_3 = off_3 + 4;
        } while (u < size);
        ptr = (char *)0x0;
        *handle = handle;
        *(uint *)(handle + 1) = size;
      }
    }
  }
  return ptr;
}





void coruna_pacia(void)
{
  return;
}





void coruna_helper_4188_94cc(void)
{
  return;
}





void coruna_helper_4188_94d4(void)
{
  return;
}





void coruna_helper_4188_94dc(void)
{
  return;
}
uint64_t coruna_return_zero(void)
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





uint64_t coruna_return_zero_8000(long handle,long addr_2)
{
  uint64_t u;
  
  if (((handle != 0) && (addr_2 != 0)) && (k_persist_slot_a030 != (void (*)0x0)) {
    u = (*k_persist_slot_a030)();
    return u;
  }
  return 0xffffffffffffffff;
}





uint64_t coruna_return_minus_one(void)
{
  return 0xffffffffffffffff;
}





uint64_t coruna_pad_stub(void)
{
  return 0;
}





uint8_t * _end(void)
{
  uint8_t *ptr;
  short *lps2;
  int err;
  pid_t pid;
  uint u;
  long handle;
  unsigned long size;
  uint64_t in_x4;
  mach_port_name_t name;
  uint8_t *buf;
  uint8_t tag[16];
  uint64_t scratch;
  long bootargs;
  long thread_attr;
  short *host_info;
  long serial_buf;
  long action;
  short *block_ctx;
  long stack_guard;
  uint64_t sa_saved;
  void *sa_new;
  short *path_buf;
  long *tmp_buf;
  void (*region)(void);
  uint plist;
  pthread_t url_buf;
  short *json_buf;
  void *frame;
  void (*work)(void);
  uint cache;
  void (*cache_20)(void);
  long cache_21;
  uint64_t cache_22;
  uint32_t cache_23;
  uint64_t cache_24;
  uint32_t cache_25;
  long cache_26;
  short *cache_27;
  long cache_28;
  long cache_29;
  
  tag = (*(void (*)k_persist_chkstk_darwin_slot)();
  cache_29 = *(long *)k_persist_stack_chk_guard_slot;
  handle = _dlopen("/usr/lib/libSystem.B.dylib",0x10);
  size = 0;
  if (handle != 0) {
    size = _dlsym(handle,"vsyslog");
  }
  ptr = k_persist_mach_task_self_slot;
  buf = (uint8_t *)0x1e039;
  bootargs = 0;
  scratch = 0;
  host_info = (short *)0x0;
  thread_attr = 0;
  action = 0;
  serial_buf = 0;
  stack_guard = 0;
  block_ctx = (short *)0x0;
  sa_saved = 0;
  name = (mach_port_name_t)in_x4;
  k_persist_rodata_word_24918 = size;
  if (name + 1 < 2) goto fail;
  buf = (uint8_t *)0x1e042;
  u = 0;
  if ((tag != 0) && (tag != 0)) {
    buf = (uint8_t *)coruna_persistb080_via_persistb080_via_pthread_rwlock_init((unsigned long)&scratch | 8,tag,tag);
    if ((int)buf == 0) {
      work = (void (*)0x0;
      json_buf = (short *)((unsigned long)json_buf & 0xffffffff00000000);
      scratch = coruna_u64_pack((8), (name));
      buf = (uint8_t *)coruna_mach_msg_destroy_b8f0(in_x4,&work,&json_buf);
      if ((int)buf == 0) {
        sa_saved = *(uint64_t *)(work + 0x30);
        if (*(int *)(work + 0x1c) + 1U < 2) {
          thread_attr = 0;
          host_info = (short *)0x0;
done:
          buf = (uint8_t *)coruna_persistb080_via_ctx_free_18dac(&serial_buf,host_info,0,0,0,1);
          if ((int)buf != 0) goto cleanup;
          _bzero(&cache_21,0x1000);
          pid = _getpid();
          err = _proc_name(pid,&cache_21,0x1000);
          if (0 < err) {
            handle = 0;
            do {
              err = _strcasecmp((char *)&cache_21,*(char **)((long)&k_persist_rodata_word_20238 + handle));
              if (err == 0) {
                buf = (uint8_t *)0xad001;
                if (bootargs == 0 || serial_buf == 0) goto cleanup;
                path_buf = (short *)0x0;
                frame = (void *)((unsigned long)frame & 0xffffffff00000000);
                buf = (uint8_t *)
                         (**(void (**)(bootargs + 0x18))
                                   (bootargs,0x90000,&path_buf,&frame);
                if (((int)buf == 0) &&
                   (buf = (uint8_t *)
                             (**(void (**)(serial_buf + 0x30))
                                       (serial_buf,path_buf,(unsigned long)frame & 0xffffffff,4,
                                        &action), (int)buf == 0)) {
                  cache_20 = (void (*)0x0;
                  buf = (uint8_t *)
                           (**(void (**)(action + 0x30))(action,"_driver",&cache_20);
                  if (((int)buf == 0) &&
                     (buf = (uint8_t *)(*cache_20)(&block_ctx), (int)buf == 0)) {
                    if (((block_ctx != (short *)0x0) && (*block_ctx == 2)) &&
                       (1 < (ushort)block_ctx[1])) {
                      buf = (uint8_t *)coruna_persistb080_via_ctx_free_18dac(&stack_guard,block_ctx,0,bootargs,0,1);
                      if ((int)buf == 0) {
                        /* fall through to check_ok */
                      }
                      else {
                        goto cleanup;
                      }
                    }
                    block_ctx = (short *)0x0;
                    buf = (uint8_t *)0xad00a;
                  }
                }
                if ((int)buf == 0x7003) {
                  /* fall through to check_ok */
                }
                else {
                  goto cleanup;
                }
              }
              handle = handle + 8;
            } while (handle != 400);
          }
          block_ctx = (short *)0x0;
check_ok:
          handle = stack_guard;
          if ((stack_guard == 0) && (handle = serial_buf, serial_buf == 0)) {
            buf = (uint8_t *)0xad022;
            handle = 0;
          }
          else {
            cache_21 = 0;
            buf = (uint8_t *)
                     (**(void (**)(handle + 0x30))
                               (handle,work + 0x40,*(uint32_t *)(work + 0x3c),
                                *(uint64_t *)(work + 0x30),&cache_21);
            handle = cache_21;
            if ((int)buf != 0) {
              handle = 0;
            }
          }
        }
        else {
          cache_21 = 0;
          buf = (uint8_t *)
                   coruna_mach_port_mod_refs(&cache_21,*(int *)(work + 0x1c),
                                *(uint32_t *)(work + 0x38));
          if ((int)buf == 0) {
            path_buf = (short *)0x0;
            buf = (uint8_t *)coruna_persistb080_residual_147(cache_21,&path_buf);
            if ((int)buf == 0) {
              host_info = path_buf;
              thread_attr = cache_21;
              goto done;
            }
            if (cache_21 != 0) {
              coruna_mach_port_deallocate_1132c();
            }
          }
cleanup:
          handle = 0;
        }
        if (1 < *(mach_port_name_t *)(work + 0x1c) + 1) {
          _mach_port_deallocate(*(ipc_space_t *)ptr,*(mach_port_name_t *)(work + 0x1c));
        }
        _bzero(work + 0x40,(unsigned long)*(uint *)(work + 0x3c));
        _free(work);
        if ((int)buf == 0) {
          if (handle == 0) {
            buf = (uint8_t *)0xad001;
          }
          else {
            cache_20 = (void (*)0x0;
            cache = 0;
            frame = (void *)0x0;
            work = (void (*)0x0;
            cache_21 = coruna_u64_pack((cache_21), (0x10001));
            cache_22 = *(uint64_t *)(handle + 0x10);
            cache_23 = *(uint32_t *)(handle + 0x18);
            cache_24 = *(uint64_t *)(handle + 0x20);
            cache_26 = serial_buf;
            if (stack_guard != 0) {
              cache_26 = stack_guard;
            }
            cache_27 = host_info;
            if (block_ctx != (short *)0x0) {
              cache_27 = block_ctx;
            }
            size = scratch & 0xffffffff;
            cache_25 = (uint32_t)scratch;
            cache_28 = bootargs;
            scratch = coruna_u64_pack((9), ((uint32_t))scratch);
            buf = (uint8_t *)
                     coruna_mach_msg_destroy_b9e4(size,&cache_20,&cache,&frame,&work);
            if ((int)buf == 0) {
              json_buf = (short *)0x0;
              err = (**(void (**)(handle + 0x30))(handle,frame,&json_buf);
              lps2 = json_buf;
              buf = &UNK_00005005;
              if ((err == 0) && (json_buf != (short *)0x0)) {
                u = *(uint *)(cache_20 + 0x1c);
                _bzero(frame,(unsigned long)*(uint *)(cache_20 + 0x18));
                if (u != 0) {
                  _memmove(cache_20,work,(unsigned long)u);
                  work = cache_20;
                }
                coruna_mach_port_deallocate_b80c(scratch & 0xffffffff,0,10,0,0);
                url_buf = (pthread_t)0x0;
                tmp_buf = &cache_21;
                path_buf = lps2;
                region = (void (*)0x0;
                if (u != 0) {
                  region = work;
                }
                plist = u;
                err = _pthread_create(&url_buf,(pthread_attr_t *)0x0,(void **)coruna_nop_stub,
                                        &path_buf);
                u = 0x1d002;
                if (err == 0) {
                  sa_new = (void *)0x0;
                  err = _pthread_join(url_buf,&sa_new);
                  u = (uint)sa_new;
                  if (err != 0) {
                    u = 0x1d003;
                  }
                }
                buf = (uint8_t *)(unsigned long)u;
                scratch = coruna_u64_pack((0x10), ((uint32_t))scratch);
              }
              _bzero(cache_20,(unsigned long)cache);
              _free(cache_20);
            }
          }
          if (((byte)sa_saved >> 5 & 1) == 0) {
            (**(void (**)(handle + 0x28))(handle);
          }
        }
      }
      if (stack_guard != 0) {
        (**(void (**)(stack_guard + 0x10))();
      }
      if (block_ctx != (short *)0x0) {
        (**(void (**)(block_ctx + 8))();
      }
      if (action != 0) {
        (**(void (**)(action + 0x28))();
      }
      if (serial_buf != 0) {
        (**(void (**)(serial_buf + 0x10))();
      }
      if (host_info != (short *)0x0) {
        (**(void (**)(host_info + 8))();
      }
      if (thread_attr != 0) {
        coruna_mach_port_deallocate_1132c();
      }
      coruna_ctx_free_1c8fc(bootargs);
      u = scratch;
      bootargs = 0;
      host_info = (short *)0x0;
      thread_attr = 0;
      action = 0;
      serial_buf = 0;
      stack_guard = 0;
      block_ctx = (short *)0x0;
      sa_saved = 0;
      scratch = (unsigned long)scratch << 0x20;
    }
    else {
      u = scratch;
    }
  }
  coruna_mach_port_deallocate_b80c(in_x4,0,u,buf,1);
  u = _mach_port_deallocate(*(ipc_space_t *)ptr,name);
  size = (unsigned long)u;
fail:
  if (*(long *)k_persist_stack_chk_guard_slot == cache_29) {
    return buf;
  }
  ___stack_chk_fail(size);
}





long coruna_nop_stub(uint64_t *val)
{
  int err;
  long handle;
  
  handle = 0xad001;
  if (val != (uint64_t *)0x0) {
    if ((void (*)*val == (void (*)0x0) {
      handle = 0xad014;
    }
    else {
      err = (*(void (*)*val)(val[1],val[2],*(uint32_t *)(val + 3));
      handle = (long)err;
    }
  }
  return handle;
}





unsigned long coruna_mach_port_allocate_b6a8(uint64_t arg,uint64_t val,uint64_t n,uint64_t *m,
                  uint32_t *p)

{
  uint u;
  uint size;
  uint8_t *ptr;
  mach_port_name_t lm4;
  kern_return_t lk5;
  unsigned long tag;
  mach_port_name_t scratch;
  uint32_t bootargs;
  uint64_t thread_attr;
  
  ptr = k_persist_mach_task_self_slot;
  u = (int)arg + 1;
  if ((u < 2 || m == (uint64_t *)0x0) || p == (uint32_t *)0x0) {
    size = 0xad001;
    if (u < 2) {
      size = 0x1e039;
    }
    tag = (unsigned long)size;
  }
  else {
    scratch = 0;
    lk5 = _mach_port_allocate(*(ipc_space_t *)k_persist_mach_task_self_slot,1,&scratch);
    tag = 0x1e023;
    if (lk5 == 0) {
      tag = coruna_mach_port_deallocate_b80c(arg,scratch,val,n,0);
      lm4 = scratch;
      if ((int)tag == 0) {
        if (scratch + 1 < 2) {
          tag = 0xad001;
        }
        else {
          thread_attr = 0;
          bootargs = 0;
          tag = coruna_mach_msg_destroy_bb10(scratch,0x18,4,30000,&thread_attr,&bootargs);
          if ((int)tag == 0x1e03b) {
            tag = coruna_mach_msg_destroy_bb10(lm4,bootargs,0,0,&thread_attr,&bootargs);
          }
          if ((int)tag == 0) {
            *m = thread_attr;
            *p = bootargs;
          }
        }
      }
      _mach_port_mod_refs(*(ipc_space_t *)ptr,scratch,1,-1);
    }
  }
  return tag;
}





uint32_t
void coruna_mach_port_deallocate_b80c(mach_port_t port,mach_port_name_t arg,uint32_t size,uint32_t flags_2)
{
  mach_msg_return_t lm1;
  uint32_t u;
  mach_msg_header_t scratch;
  uint32_t bootargs;
  uint32_t scratch;
  
  if (port + 1 < 2) {
    u = 0x1e039;
  }
  else {
    scratch.msgh_bits = 0x1413;
    if (arg + 1 < 2) {
      scratch.msgh_bits = 0x13;
    }
    scratch = k_persist_rodata_word_1ecc0;
    scratch.msgh_size = 0x20;
    scratch.msgh_remote_port = port;
    scratch.msgh_local_port = arg;
    bootargs = size;
    scratch = flags_2;
    lm1 = _mach_msg(&scratch,0x11,0x20,100,0,100,0);
    if (lm1 == 0) {
      u = 0;
    }
    else if (lm1 == 0x10) {
      u = 0x1f037;
      if (1 < arg + 1) {
        _mach_port_deallocate(*(ipc_space_t *)k_persist_mach_task_self_slot,arg);
      }
    }
    else {
      u = 0x1f037;
      if (lm1 == 0x10000003) {
        u = 0x1f036;
      }
    }
  }
  return u;
}





uint64_t coruna_mach_msg_destroy_b8f0(uint64_t val,uint64_t *id_2,uint *size)
{
  uint u;
  uint64_t size;
  uint scratch;
  mach_msg_header_t *bootargs;
  
  bootargs = (mach_msg_header_t *)0x0;
  scratch = 0;
  size = 0xad001;
  if (((id_2 != (uint64_t *)0x0) && (size != (uint *)0x0)) &&
     (size = coruna_mach_port_allocate_b6a8(val,8,0,&bootargs,&scratch), (int)size == 0)) {
    size = 0x1e03a;
    if (scratch < 0x40) {
      if (bootargs == (mach_msg_header_t *)0x0) {
        return 0x1e03a;
      }
    }
    else if (((((bootargs->msgh_id == 1) && ((int)bootargs->msgh_bits < 0)) &&
              ((bootargs[2].msgh_local_port != 0 &&
               ((bootargs[1].msgh_bits == 1 &&
                (*(char *)((long)&bootargs[1].msgh_local_port + 3) == '\0')))))) &&
             (u = bootargs[2].msgh_local_port + 0x40, 0x40 < u)) && (u <= scratch)) {
      *id_2 = bootargs;
      *size = scratch;
      return 0;
    }
    _mach_msg_destroy(bootargs);
    _bzero(bootargs,(unsigned long)scratch);
    _free(bootargs);
  }
  return size;
}





uint64_t
void coruna_mach_msg_destroy_b9e4(uint64_t val,uint64_t *id_2,uint *size,long *handle,long *addr_2)
{
  uint u;
  mach_port_t *lpm2;
  long handle;
  uint size;
  uint version;
  uint64_t port;
  uint scratch;
  mach_msg_header_t *bootargs;
  
  bootargs = (mach_msg_header_t *)0x0;
  scratch = 0;
  port = 0xad001;
  if (((id_2 != (uint64_t *)0x0) && (size != (uint *)0x0)) &&
     (port = coruna_mach_port_allocate_b6a8(val,9,0,&bootargs,&scratch), (int)port == 0)) {
    port = 0x1e03a;
    if (scratch < 0x20) {
      if (bootargs == (mach_msg_header_t *)0x0) {
        return 0x1e03a;
      }
    }
    else if ((bootargs->msgh_id == 2) && (-1 < (int)bootargs->msgh_bits)) {
      size = bootargs[1].msgh_bits;
      if ((1 < size) && (u = size + 0x20, 0x20 < u)) {
        version = bootargs[1].msgh_size;
        if ((!CARRY4(version,u)) && (version + u <= scratch)) {
          lpm2 = &bootargs[1].msgh_remote_port;
          handle = 0;
          if (version != 0) {
            handle = (long)lpm2 + (unsigned long)size;
          }
          if (*(char *)((long)lpm2 + (unsigned long)(size - 1)) == '\0') {
            *id_2 = bootargs;
            *size = scratch;
            if (handle != (long *)0x0) {
              *handle = (long)lpm2;
            }
            if (addr_2 == (long *)0x0) {
              return 0;
            }
            *addr_2 = handle;
            return 0;
          }
        }
      }
    }
    _mach_msg_destroy(bootargs);
    _bzero(bootargs,(unsigned long)scratch);
    _free(bootargs);
  }
  return port;
}





uint64_t
void coruna_mach_msg_destroy_bb10(mach_port_name_t arg,uint size,uint flags_2,mach_msg_timeout_t arg_x,
            uint64_t *val,uint *count_3)
{
  uint rcv_size;
  uint u;
  mach_msg_header_t *msg;
  uint64_t size;
  
  if (size < 0x18) {
    return 0xad001;
  }
  if (val == (uint64_t *)0x0) {
    return 0xad001;
  }
  if (count_3 == (uint *)0x0) {
    return 0xad001;
  }
  rcv_size = size + 8;
  msg = _calloc(1,(unsigned long)rcv_size);
  if (msg == (mach_msg_header_t *)0x0) {
    return 0xad009;
  }
  size = 0x1e021;
  u = _mach_msg(msg,flags_2 | 0x102,0,rcv_size,arg,arg_x,0);
  if (u == 0x10004004) {
    u = msg->msgh_size;
    if (u - 0x18 < 0x63fffe9) {
      *val = 0;
      *count_3 = u;
      size = 0x1e03b;
      _bzero(msg,(unsigned long)rcv_size);
      _free(msg);
      return size;
    }
    _mach_msg(msg,0x102,0,rcv_size,arg,0,0);
  }
  else {
    _bzero(msg,(unsigned long)rcv_size);
    _free(msg);
    return size;
    if (u != 0) {
      if ((u & 0xfffffffb) == 0x10004008) {
        _mach_msg_destroy(msg);
      }
      _bzero(msg,(unsigned long)rcv_size);
      _free(msg);
      return size;
    }
    u = msg->msgh_size;
    if ((0x17 < u) && (u <= size)) {
      *val = msg;
      *count_3 = u;
      return 0;
    }
    _mach_msg_destroy(msg);
  }
  size = 0x1e03a;
fail:
  _bzero(msg,(unsigned long)rcv_size);
  _free(msg);
  return size;
}





uint64_t coruna_mach_port_deallocate(uint64_t *val)
{
  uint64_t u;
  
  if (val == (uint64_t *)0x0) {
    u = 0xad001;
  }
  else {
    u = coruna_persistb080_via_mach_vm_deallocate_11e48(val[1]);
    if (1 < *(mach_port_name_t *)((long)val + 0x1c) + 1) {
      _mach_port_destroy(*(ipc_space_t *)k_persist_mach_task_self_slot,
                         *(mach_port_name_t *)((long)val + 0x1c));
    }
    if (1 < *(mach_port_name_t *)(val + 4) + 1) {
      _mach_port_deallocate(*(ipc_space_t *)(val + 2),*(mach_port_name_t *)(val + 4));
    }
    val[4] = 0;
    val[1] = 0;
    *val = 0;
    val[3] = 0;
    val[2] = 0;
    _free(val);
  }
  return u;
}





unsigned long coruna_mach_port_deallocate_17b60(uint64_t *arg,long val,uint64_t n,long m,int p,
                  uint32_t q)

{
  uint u;
  uint size;
  long *ptr;
  ipc_space_t task;
  unsigned long type_id;
  uint64_t host_info;
  long serial_buf;
  uint32_t action;
  unsigned long block_ctx;
  
  type_id = 0xad001;
  if (((arg != (uint64_t *)0x0) && (val != 0)) && (m != 0)) {
    task = (ipc_space_t)n;
    if (task + 1 < 2) {
      type_id = 0x1e009;
    }
    else {
      if (p + 1U < 2) {
        block_ctx = block_ctx & 0xffffffffffffff00;
        size = coruna_csops_128d4(&block_ctx);
        if (size != 0) {
          u = 0x1e037;
          if (size != 0x12017) {
            u = size;
          }
          return (unsigned long)u;
        }
        if ((char)block_ctx != '\0') {
          return 0x1e037;
        }
      }
      ptr = _calloc(1,0x28);
      if (ptr == (long *)0x0) {
        type_id = 0xad009;
      }
      else {
        host_info = 0;
        type_id = coruna_mach_port_destroy((long)&host_info + 4,n,&host_info);
        if ((int)type_id == 0) {
          block_ctx = 0;
          action = 0;
          type_id = (**(void (**)(m + 0x18))(m,0xf0000,&block_ctx,&action);
          if ((int)type_id == 0) {
            serial_buf = 0;
            type_id = coruna_persistb080_via_macho_open_image_2(val,n,block_ctx,action,0,&serial_buf);
            if ((int)type_id == 0) {
              *ptr = m;
              ptr[1] = serial_buf;
              *(mach_port_name_t *)((long)ptr + 0x1c) = host_info;
              *(mach_port_name_t *)(ptr + 4) = (mach_port_name_t)host_info;
              *(ipc_space_t *)(ptr + 2) = task;
              *(int *)((long)ptr + 0x14) = p;
              *(uint32_t *)(ptr + 3) = q;
              *arg = ptr;
              return type_id;
            }
          }
          _mach_port_deallocate(task,(mach_port_name_t)host_info);
          if (1 < host_info + 1) {
            _mach_port_destroy(*(ipc_space_t *)k_persist_mach_task_self_slot,host_info);
          }
        }
        _free(ptr);
      }
    }
  }
  return type_id;
}





unsigned long coruna_pthread_attr_setdetachstate(long *arg,long val,int n,unsigned long m,char *p,long q,
                  int r,uint32_t *s)

{
  uint dataCnt;
  uint u;
  uint32_t size;
  uint8_t *ptr;
  int status;
  uint port;
  int flags;
  kern_return_t lk7;
  unsigned long type_id_8;
  long off;
  uint64_t *data;
  void *buf;
  size_t ls11;
  unsigned long type_id_9;
  uint64_t type_id_10;
  unsigned long type_id_11;
  long *str;
  long stack_guard;
  mach_vm_address_t sa_saved;
  uint32_t sa_new;
  mach_vm_address_t path_buf;
  mach_vm_address_t tmp_buf;
  uint region;
  void *plist;
  uint url_buf;
  void *json_buf;
  long frame;
  long work;
  pthread_attr_t cache;
  long cache_20;
  
  cache_20 = *(long *)k_persist_stack_chk_guard_slot;
  if (((((arg == (long *)0x0) || (val == 0)) || (n == 0)) ||
      ((p == (char *)0x0 || (*p == '\0')))) || ((q == 0) == (r != 0))) {
    type_id_8 = 0xad001;
    if (*(long *)k_persist_stack_chk_guard_slot == cache_20) {
    return type_id_8;
    }
    ___stack_chk_fail();
  }
  sa_new = 0;
  type_id_9 = m >> 3 & 1;
  if (k_persist_rodata_word_1ecc8 <= *(double *)k_persist_dyldversionnumber_slot) {
    type_id_9 = m >> 3 & 1 | 2;
  }
  status = coruna_pid_for_task((int)arg[2],0xffffffec,&sa_new);
  type_id_8 = coruna_mach_port_kernel_object((int)arg[2]);
  if (((int)type_id_8 == 0) && (type_id_8 = coruna_task_get_exc_guard_behavior((int)arg[2]), (int)type_id_8 == 0)) {
    frame = 0;
    work = 0;
    port = coruna_persistb080_residual_152(arg[1],"_last",&work);
    if (port == 0) {
      port = coruna_persistb080_residual_152(arg[1],"_end",&frame);
    }
    if (((port == 0) && (work != 0)) && (frame != 0)) {
      off = arg[1];
      if (off == 0) {
        type_id_8 = 0xad001;
      }
      else {
        type_id_10 = *(uint64_t *)(off + 0x40);
        size = *(uint32_t *)(off + 0x48);
        json_buf = (void *)0x0;
        url_buf = 0;
        cache.__sig = 0;
        plist = (void *)((unsigned long)plist & 0xffffffff00000000);
        type_id_8 = coruna_persistb080_residual_155(off,&cache,&plist);
        if ((int)type_id_8 == 0) {
          off = arg[1];
          type_id_8 = 0xad001;
          if (off != 0) {
            type_id_8 = coruna_persistb080_via_persistb080_via_persistb080_trampoline_00010c24(*(uint64_t *)(off + 0x40),*(uint32_t *)(off + 0x48),
                                 cache.__sig,(unsigned long)plist & 0xffffffff,
                                 *(uint64_t *)(off + 0xd8),*(uint32_t *)(off + 0xe0),
                                 *(uint64_t *)(off + 200),*(uint32_t *)(off + 0xd0),
                                 *(uint64_t *)(off + 0x140),&json_buf,&url_buf);
          }
          if ((void *)cache.__sig != (void *)0x0) {
            _free((void *)cache.__sig);
          }
          if ((int)type_id_8 == 0) {
            plist = (void *)0x0;
            region = 0;
            type_id_8 = (**(void (**)(*arg + 0x20))(*arg,&plist,&region);
            u = url_buf;
            port = region;
            if ((int)type_id_8 == 0) {
              dataCnt = url_buf + region + 0x90;
              type_id_11 = (unsigned long)dataCnt;
              data = _calloc(1,type_id_11);
              if (data == (uint64_t *)0x0) {
                stack_guard = 0;
                sa_saved = 0;
                dataCnt = 0;
                type_id_8 = 0xad009;
              }
              else {
                path_buf = 0;
                tmp_buf = 0;
                coruna_persistb080_trampoline_00010c24(data + 0x12,json_buf,u);
                coruna_persistb080_trampoline_00010c24((long)data + (unsigned long)(url_buf + 0x90),plist,region);
                *data = type_id_10;
                *(uint32_t *)(data + 1) = size;
                data[2] = 0;
                *(uint *)(data + 3) = dataCnt;
                data[4] = type_id_10;
                *(uint32_t *)(data + 5) = size;
                *(uint32_t *)(data + 6) = 0x90;
                *(uint *)((long)data + 0x34) = url_buf;
                off = arg[4];
                data[8] = frame;
                *(uint *)(data + 9) = url_buf + 0x90;
                *(uint *)((long)data + 0x4c) = region;
                *(int *)(data + 10) = (int)off;
                data[0xb] = type_id_9;
                off = _dlsym(0xfffffffffffffffe,"pthread_create_from_mach_thread");
                str = data + 0xc;
                *str = off;
                if (off == 0) {
                  type_id_8 = 0x12001;
done:
                  if (data[2] != 0) {
                    coruna_mach_vm_deallocate_1b998((int)arg[2],tmp_buf,type_id_11,1);
                  }
                  if (*str != 0) {
                    coruna_mach_vm_deallocate_1b998((int)arg[2],path_buf,0x38,1);
                  }
                  stack_guard = 0;
                  sa_saved = 0;
                  dataCnt = 0;
                }
                else {
                  type_id_8 = coruna_persistb080_via_dladdr_1bd4c(arg[1],str);
                  if (((int)type_id_8 != 0) ||
                     (type_id_8 = coruna_mach_vm_allocate((int)arg[2],0x38,1,&path_buf), (int)type_id_8 != 0))
                  goto done;
                  cache.__opaque[0x20] = '\0';
                  cache.__opaque[0x21] = '\0';
                  cache.__opaque[0x22] = '\0';
                  cache.__opaque[0x23] = '\0';
                  cache.__opaque[0x24] = '\0';
                  cache.__opaque[0x25] = '\0';
                  cache.__opaque[0x26] = '\0';
                  cache.__opaque[0x27] = '\0';
                  cache.__opaque[0x18] = '\0';
                  cache.__opaque[0x19] = '\0';
                  cache.__opaque[0x1a] = '\0';
                  cache.__opaque[0x1b] = '\0';
                  cache.__opaque[0x1c] = '\0';
                  cache.__opaque[0x1d] = '\0';
                  cache.__opaque[0x1e] = '\0';
                  cache.__opaque[0x1f] = '\0';
                  cache.__opaque[0x30] = '\0';
                  cache.__opaque[0x31] = '\0';
                  cache.__opaque[0x32] = '\0';
                  cache.__opaque[0x33] = '\0';
                  cache.__opaque[0x34] = '\0';
                  cache.__opaque[0x35] = '\0';
                  cache.__opaque[0x36] = '\0';
                  cache.__opaque[0x37] = '\0';
                  cache.__opaque[0x28] = '\0';
                  cache.__opaque[0x29] = '\0';
                  cache.__opaque[0x2a] = '\0';
                  cache.__opaque[0x2b] = '\0';
                  cache.__opaque[0x2c] = '\0';
                  cache.__opaque[0x2d] = '\0';
                  cache.__opaque[0x2e] = '\0';
                  cache.__opaque[0x2f] = '\0';
                  cache.__opaque[0] = '\0';
                  cache.__opaque[1] = '\0';
                  cache.__opaque[2] = '\0';
                  cache.__opaque[3] = '\0';
                  cache.__opaque[4] = '\0';
                  cache.__opaque[5] = '\0';
                  cache.__opaque[6] = '\0';
                  cache.__opaque[7] = '\0';
                  cache.__sig = 0;
                  cache.__opaque[0x10] = '\0';
                  cache.__opaque[0x11] = '\0';
                  cache.__opaque[0x12] = '\0';
                  cache.__opaque[0x13] = '\0';
                  cache.__opaque[0x14] = '\0';
                  cache.__opaque[0x15] = '\0';
                  cache.__opaque[0x16] = '\0';
                  cache.__opaque[0x17] = '\0';
                  cache.__opaque[8] = '\0';
                  cache.__opaque[9] = '\0';
                  cache.__opaque[10] = '\0';
                  cache.__opaque[0xb] = '\0';
                  cache.__opaque[0xc] = '\0';
                  cache.__opaque[0xd] = '\0';
                  cache.__opaque[0xe] = '\0';
                  cache.__opaque[0xf] = '\0';
                  _pthread_attr_init(&cache);
                  flags = _pthread_attr_setdetachstate(&cache,2);
                  if ((flags != 0) ||
                     (lk7 = _mach_vm_write(*(vm_map_t *)(arg + 2),path_buf,
                                             (vm_offset_t)&cache,0x38), lk7 != 0)) {
                    _pthread_attr_destroy(&cache);
                    type_id_8 = 0xad00b;
                    goto done;
                  }
                  data[0xe] = path_buf;
                  *(uint32_t *)(data + 0xf) = 0x38;
                  _pthread_attr_destroy(&cache);
                  type_id_8 = coruna_mach_vm_allocate((int)arg[2],type_id_11,0x3000001,&tmp_buf);
                  if ((int)type_id_8 != 0) goto done;
                  data[2] = tmp_buf;
                  lk7 = _mach_vm_write(*(vm_map_t *)(arg + 2),tmp_buf,(vm_offset_t)data,
                                         dataCnt);
                  if (lk7 != 0) {
                    type_id_8 = 0x1e01a;
                    goto done;
                  }
                  type_id_8 = 0;
                  sa_saved = tmp_buf;
                  stack_guard = work;
                }
                _bzero(data,type_id_11);
                _free(data);
                port = region;
              }
              _bzero(plist,(unsigned long)port);
              _free(plist);
            }
            else {
              stack_guard = 0;
              sa_saved = 0;
              dataCnt = 0;
            }
            _bzero(json_buf,(unsigned long)url_buf);
            _free(json_buf);
            if ((int)type_id_8 == 0) {
              type_id_8 = coruna_persistb080_via_mach_vm_allocate(arg[1],stack_guard,sa_saved,dataCnt,(int)arg[4]);
              if ((int)type_id_8 == 0) {
                if (arg[1] != 0) {
                  *(uint8_t *)(arg[1] + 0xfb) = 0;
                }
                *(uint32_t *)(arg + 4) = 0;
                type_id_8 = coruna_mach_port_deallocate_1857c(arg,&k_persist_slot_4e20,3,0);
                if ((int)type_id_8 == 0) {
                  cache.__sig = cache.__sig & 0xffffffff00000000;
                  type_id_8 = coruna_mach_port_deallocate_1857c(arg,30000,8,&cache);
                  if ((int)type_id_8 == 0) {
                    type_id_9 = (unsigned long)(n + 0x43U & 0xfffffffc);
                    buf = _calloc(1,type_id_9);
                    if (buf == (void *)0x0) {
                      type_id_8 = 0xad009;
                    }
                    else {
                      *(uint64_t *)((long)buf + 0x14) = 0x100000001;
                      flags = *(int *)((long)arg + 0x14);
                      if (1 < flags + 1U) {
                        *(uint32_t *)((long)buf + 0x24) = 0x130000;
                        *(int *)((long)buf + 0x1c) = flags;
                      }
                      *(int *)((long)buf + 0x38) = (int)arg[3];
                      *(int *)((long)buf + 0x3c) = n;
                      *(unsigned long *)((long)buf + 0x30) = m;
                      coruna_persistb080_trampoline_00010c24((long)buf + 0x40,val,n);
                      type_id_8 = coruna_mach_msg_destroy(cache.__sig & 0xffffffff,buf,type_id_9,30000,1);
                      _bzero(buf,type_id_9);
                      _free(buf);
                    }
                    ptr = k_persist_mach_task_self_slot;
                    _mach_port_deallocate
                              (*(ipc_space_t *)k_persist_mach_task_self_slot,
                               (mach_port_name_t)cache.__sig);
                    if (((int)type_id_8 == 0) && ((r == 0 || (type_id_8 = 0xad001, q != 0)))) {
                      ls11 = _strlen(p);
                      if (ls11 - 1 < 0x3fe) {
                        cache.__sig = cache.__sig & 0xffffffff00000000;
                        type_id_8 = coruna_mach_port_deallocate_1857c(arg,30000,9,&cache);
                        if ((int)type_id_8 == 0) {
                          type_id_9 = (unsigned long)(r + (int)ls11 + 0x24U & 0xfffffffc);
                          buf = _calloc(1,type_id_9);
                          if (buf == (void *)0x0) {
                            type_id_8 = 0xad009;
                          }
                          else {
                            *(uint32_t *)((long)buf + 0x14) = 2;
                            *(int *)((long)buf + 0x18) = (int)(ls11 + 1);
                            *(int *)((long)buf + 0x1c) = r;
                            coruna_persistb080_trampoline_00010c24((long)buf + 0x20,p,ls11 + 1);
                            if (r != 0) {
                              coruna_persistb080_trampoline_00010c24((long)buf + ls11 + 0x21,q,r);
                            }
                            type_id_8 = coruna_mach_msg_destroy(cache.__sig & 0xffffffff,buf,type_id_9,30000,0)
                            ;
                            _bzero(buf,type_id_9);
                            _free(buf);
                          }
                          _mach_port_deallocate
                                    (*(ipc_space_t *)ptr,(mach_port_name_t)cache.__sig);
                          if (((int)type_id_8 == 0) &&
                             (type_id_8 = coruna_mach_port_deallocate_1857c(arg,&k_persist_slot_4e20,10,0), (int)type_id_8 == 0)) {
                            if (s == (uint32_t *)0x0) {
                              _mach_port_mod_refs(*(ipc_space_t *)ptr,
                                                  *(mach_port_name_t *)((long)arg + 0x1c),1,-1);
                            }
                            else {
                              *s = *(uint32_t *)((long)arg + 0x1c);
                            }
                            type_id_8 = 0;
                            *(uint32_t *)((long)arg + 0x1c) = 0;
                          }
                        }
                      }
                      else {
                        type_id_8 = 0x1e010;
                      }
                    }
                  }
                }
              }
              else {
                coruna_mach_vm_deallocate_1b998((int)arg[2],sa_saved,dataCnt,1);
              }
            }
          }
        }
      }
    }
    else {
      u = 0x12001;
      if (port != 0) {
        u = port;
      }
      type_id_8 = (unsigned long)u;
    }
  }
  if (status == 0) {
    coruna_pid_for_task((int)arg[2],sa_new,0);
  }
fail:
  if (*(long *)k_persist_stack_chk_guard_slot == cache_20) {
    return type_id_8;
  }
  ___stack_chk_fail();
}





uint coruna_pid_for_task(mach_port_name_t arg,int flags,int *count_2)
{
  uint u;
  int err;
  int status;
  int *err;
  uint *ptr;
  id_t scratch;
  
  scratch = 0xffffffff;
  u = 0xad001;
  if (((1 < arg + 1) && (-0x15 < flags)) && (flags < 0x15)) {
    u = _pid_for_task(arg,(int *)&scratch);
    if (u == 0) {
      err = ___error();
      *err = 0;
      err = _getpriority(0,scratch);
      err = ___error();
      if (((*err == 0) || (err != -1)) &&
         (status = _setpriority(0,scratch,flags), status == 0)) {
        u = 0;
        if (count_2 != (int *)0x0) {
          *count_2 = err;
        }
      }
      else {
        err = ___error();
        err = *err;
        ptr = (uint *)___error();
        u = -*ptr;
        if (-1 < err) {
          u = *ptr;
        }
        u = u | 0x40000000;
      }
    }
    else {
      u = u | 0x80000000;
    }
  }
  return u;
}





unsigned long coruna_mach_port_deallocate_1857c(long arg,uint64_t val,int n,mach_port_name_t *m)

{
  uint u;
  mach_port_name_t *lpm2;
  unsigned long version;
  mach_port_name_t cache_21;
  uint64_t cache_22;
  
  if (arg == 0) {
    version = 0xad001;
  }
  else {
    cache_22 = 0;
    cache_21 = 0;
    lpm2 = (mach_port_name_t *)0x0;
    if (m != (mach_port_name_t *)0x0) {
      lpm2 = &cache_21;
    }
    version = coruna_mach_port_deallocate_1865c(*(uint32_t *)(arg + 0x1c),val,(long)&cache_22 + 4,&cache_22,
                         lpm2);
    if ((int)version == 0) {
      version = cache_22 & 0xffffffff;
      if ((int)cache_22 == 0) {
        u = 0x1e040;
        if (cache_22 == n) {
          u = 0;
        }
        version = (unsigned long)u;
        if ((cache_22 == n) && (m != (mach_port_name_t *)0x0)) {
          version = 0x1e036;
          if (1 < cache_21 + 1) {
            version = 0;
            *m = cache_21;
            cache_21 = 0;
          }
        }
      }
      if (1 < cache_21 + 1) {
        _mach_port_deallocate(*(ipc_space_t *)k_persist_mach_task_self_slot,cache_21);
      }
    }
  }
  return version;
}





uint64_t
void coruna_mach_port_deallocate_1865c(uint64_t val,uint64_t id_2,uint32_t *size,uint32_t *flags_2,
            uint32_t *version_3)
{
  void *ptr;
  uint64_t u;
  
  if ((int)val + 1U < 2) {
    u = 0x1e01b;
  }
  else {
    ptr = _calloc(1,0x28);
    if (ptr == (void *)0x0) {
      u = 0xad009;
    }
    else {
      u = coruna_mach_msg_destroy_19b70(val,5,0x28,ptr,id_2);
      if ((int)u == 0) {
        if (*(int *)((long)ptr + 0x14) == 5) {
          u = 0x1e038;
          if (*(int *)((long)ptr + 4) == 0x20) {
            if (size != (uint32_t *)0x0) {
              *size = *(uint32_t *)((long)ptr + 0x18);
            }
            if (flags_2 != (uint32_t *)0x0) {
              *flags_2 = *(uint32_t *)((long)ptr + 0x1c);
            }
            u = 0;
            if (version_3 != (uint32_t *)0x0) {
              *version_3 = *(uint32_t *)((long)ptr + 8);
              *(uint32_t *)((long)ptr + 8) = 0;
            }
          }
        }
        else {
          u = 0x1e038;
        }
      }
      if (1 < *(mach_port_name_t *)((long)ptr + 8) + 1) {
        _mach_port_deallocate
                  (*(ipc_space_t *)k_persist_mach_task_self_slot,
                   *(mach_port_name_t *)((long)ptr + 8));
      }
      _free(ptr);
    }
  }
  return u;
}





uint64_t coruna_mach_port_destroy(mach_port_name_t *arg,uint64_t val,long handle)
{
  uint64_t u;
  mach_port_name_t scratch;
  
  u = 0xad001;
  if ((arg != (mach_port_name_t *)0x0) && (handle != 0)) {
    if ((int)val + 1U < 2) {
      u = 0x1e009;
    }
    else {
      scratch = 0;
      u = coruna_mach_port_allocate(&scratch,5);
      if ((int)u == 0) {
        u = coruna_mach_port_insert_right(scratch,val,handle);
        if ((int)u == 0) {
          *arg = scratch;
        }
        else if (1 < scratch + 1) {
          _mach_port_destroy(*(ipc_space_t *)k_persist_mach_task_self_slot,scratch);
        }
      }
    }
  }
  return u;
}
unsigned long coruna_realpath(uint64_t arg,uint64_t val,uint32_t *n)

{
  uint u;
  uint64_t size;
  uint8_t *ptr;
  bool err;
  int count;
  char *ptr;
  char *buf;
  size_t ls8;
  void *copy;
  char *str;
  unsigned long type_id_12;
  unsigned long type_id_9;
  long base;
  unsigned long type_id_11;
  uint8_t kind[16];
  uint8_t *cache_23;
  uint64_t cache_24;
  void (*cache_25)(void);
  uint8_t *cache_26;
  uint64_t *cache_27;
  uint64_t *cache_28;
  uint64_t *cache_29;
  char *cache_30;
  byte cache_31;
  byte cache_32;
  byte cache_33;
  uint64_t cache_34;
  uint64_t *cache_35;
  uint64_t cache_36;
  uint32_t cache_37;
  uint64_t cache_38;
  uint64_t *cache_39;
  uint64_t cache_40;
  uint32_t cache_41;
  uint64_t cache_42;
  uint64_t *cache_43;
  uint64_t cache_44;
  uint64_t cache_45;
  uint64_t scratch;
  uint8_t *cache_46;
  uint64_t cache_47;
  void (*cache_48)(void);
  uint8_t *cache_49;
  uint8_t **cache_50;
  uint8_t *cache_51;
  size_t cache_52;
  uint8_t cache_53[4096];
  uint64_t cache_54;
  uint64_t bootargs;
  long serial_buf;
  
  kind = (*(void (*)k_persist_chkstk_darwin_slot)();
  ptr = kind;
  serial_buf = *(long *)k_persist_stack_chk_guard_slot;
  if ((ptr == (char *)0x0) || (*ptr == '\0' || n == (uint32_t *)0x0)) {
    u = 0xad001;
    if (n != (uint32_t *)0x0) {
      u = 0x1e03f;
    }
    type_id_12 = (unsigned long)u;
    if (*(long *)k_persist_stack_chk_guard_slot == serial_buf) {
    return type_id_12;
    }
    ___stack_chk_fail();
  }
  if ((kind & 1) == 0) {
    buf = _strrchr(ptr,0x2f);
    if (buf != (char *)0x0) {
      ptr = buf + 1;
    }
    if (*ptr == '\0') {
check_ok:
      type_id_12 = 0x1e03f;
      if (*(long *)k_persist_stack_chk_guard_slot == serial_buf) {
      return type_id_12;
      }
      ___stack_chk_fail();
    }
    str = (char *)0x0;
    buf = ptr;
  }
  else {
    str = (char *)_realpath_DARWIN_EXTSN(ptr,0);
    buf = str;
    if (str == (char *)0x0) {
      if (*ptr == '\0') goto check_ok;
      str = (char *)0x0;
      buf = ptr;
    }
  }
  ptr = k_persist_nsconcretestackblock_slot;
  size = k_persist_rodata_word_1ece0;
  cache_31 = ~kind[8] & 1;
  cache_28 = &cache_42;
  cache_42 = 0;
  u = kind & 0xff;
  cache_44 = k_persist_rodata_word_1ecd0;
  cache_33 = ((byte)(u >> 2) ^ 0xff) & 1;
  cache_32 = ((byte)(u >> 1) ^ 0xff) & 1;
  cache_45 = 0;
  scratch = 0;
  cache_29 = &cache_38;
  cache_38 = 0;
  cache_40 = k_persist_rodata_word_1ecd8;
  cache_41 = 0;
  cache_27 = &cache_34;
  cache_34 = 0;
  cache_36 = k_persist_rodata_word_1ecd8;
  cache_37 = 0;
  cache_23 = k_persist_nsconcretestackblock_slot;
  cache_24 = k_persist_rodata_word_1ece0;
  cache_25 = coruna_strrchr;
  cache_26 = &k_persist_rodata_word_203d0;
  cache_30 = buf;
  cache_35 = cache_27;
  cache_39 = cache_29;
  cache_43 = cache_28;
  _bzero(cache_53,0x1000);
  cache_46 = ptr;
  cache_47 = size;
  cache_48 = coruna_proc_pidpath;
  cache_49 = &k_persist_rodata_word_20400;
  cache_50 = &cache_23;
  bootargs = k_persist_rodata_word_0001ecf8;
  cache_54 = k_persist_rodata_word_1ecf0;
  cache_52 = 0;
  cache_51 = cache_53;
  count = _sysctl((int *)&cache_54,4,(void *)0x0,&cache_52,(void *)0x0,0);
  if ((count == 0) && (cache_52 != 0)) {
    cache_52 = cache_52 << 1;
    copy = _malloc(cache_52);
    if (copy == (void *)0x0) goto skip;
    count = _sysctl((int *)&cache_54,4,copy,&cache_52,(void *)0x0,0);
    if ((count == 0) && (cache_52 != 0)) {
      type_id_9 = cache_52 / 0x288;
      if ((int)type_id_9 == 0) {
        type_id_12 = 0;
      }
      else {
        type_id_12 = coruna_proc_pidpath(&cache_46,copy);
        if (((((int)type_id_12 == 0) && (type_id_9 = type_id_9 & 0xffffffff, 1 < type_id_9)) &&
            (type_id_12 = coruna_proc_pidpath(&cache_46,(long)copy + 0x288), (int)type_id_12 == 0)) &&
           (2 < type_id_9)) {
          base = (long)copy + 0x510;
          type_id_11 = 3;
          do {
            type_id_12 = (*cache_48)(&cache_46,base);
            base = base + 0x288;
            err = type_id_11 < type_id_9;
            type_id_11 = type_id_11 + 1;
          } while ((int)type_id_12 == 0 && err);
        }
      }
    }
    else {
      type_id_12 = 0xad00b;
    }
    _bzero(copy,cache_52);
    _free(copy);
    if ((int)type_id_12 == 0) {
      if (*(int *)(cache_35 + 3) == 0) {
        type_id_12 = 0xad011;
      }
      else {
        type_id_12 = 0;
        *n = *(uint32_t *)(cache_39 + 3);
      }
    }
  }
  else {
skip:
    type_id_12 = 0xad00b;
  }
  __Block_object_dispose(&cache_34,8);
  __Block_object_dispose(&cache_38,8);
  __Block_object_dispose(&cache_42,8);
  if (str != (char *)0x0) {
    ls8 = _strlen(str);
    if (ls8 != 0) {
      _bzero(str,ls8);
    }
    _free(str);
  }
cleanup:
  if (*(long *)k_persist_stack_chk_guard_slot == serial_buf) {
    return type_id_12;
  }
  ___stack_chk_fail();
}





uint64_t coruna_strrchr(long handle,long *addr_2,char *path)
{
  int err;
  char *ptr;
  long handle;
  long addr;
  long off;
  
  if (*(char *)(handle + 0x40) != '\0') {
    if (path == (char *)0x0) {
      return 0;
    }
    ptr = _strrchr(path,0x2f);
    if (ptr != (char *)0x0) {
      path = ptr + 1;
    }
  }
  if (path == (char *)0x0) {
    return 0;
  }
  if (addr_2 == (long *)0x0) {
    return 0;
  }
  err = _strcmp(*(char **)(handle + 0x38),path);
  if ((err == 0) && (0 < (int)addr_2[5])) {
    handle = *(long *)(*(long *)(handle + 0x20) + 8);
    *(int *)(handle + 0x18) = *(int *)(handle + 0x18) + 1;
    if ((1 < *(uint *)(*(long *)(*(long *)(handle + 0x20) + 8) + 0x18)) &&
       (*(char *)(handle + 0x41) == '\0')) {
      return 0x1e03e;
    }
    if (*(char *)(handle + 0x42) == '\0') {
      handle = *(long *)(*(long *)(handle + 0x28) + 8);
      off = *(long *)(handle + 0x18);
      if ((off == 0) && (*(int *)(handle + 0x20) == 0)) {
        addr = *addr_2;
      }
      else {
        addr = *addr_2;
        if (off <= addr) {
          if (addr != off) {
            return 0;
          }
          addr = off;
          if (*(int *)(handle + 0x20) <= (int)addr_2[1]) {
            return 0;
          }
        }
      }
    }
    else {
      addr = *addr_2;
      handle = *(long *)(*(long *)(handle + 0x28) + 8);
      if (addr <= *(long *)(handle + 0x18)) {
        if (addr != *(long *)(handle + 0x18)) {
          return 0;
        }
        if ((int)addr_2[1] <= *(int *)(handle + 0x20)) {
          return 0;
        }
      }
    }
    *(long *)(handle + 0x18) = addr;
    *(int *)(*(long *)(*(long *)(handle + 0x28) + 8) + 0x20) = (int)addr_2[1];
    *(int *)(*(long *)(*(long *)(handle + 0x30) + 8) + 0x18) = (int)addr_2[5];
    return 0;
  }
  return 0;
}





void coruna_block_assign_11358(long handle,long addr_2)
{
  __Block_object_assign((void *)(handle + 0x20),*(void **)(addr_2 + 0x20),8);
  __Block_object_assign((void *)(handle + 0x28),*(void **)(addr_2 + 0x28),8);
  __Block_object_assign((void *)(handle + 0x30),*(void **)(addr_2 + 0x30),8);
  return;
}





void coruna_block_dispose_113a4(long handle)
{
  __Block_object_dispose(*(void **)(handle + 0x30),8);
  __Block_object_dispose(*(void **)(handle + 0x28),8);
  __Block_object_dispose(*(void **)(handle + 0x20),8);
  return;
}





uint64_t coruna_proc_pidpath(long handle,long addr_2)
{
  int err;
  uint64_t u;
  uint64_t *ptr;
  uint64_t size;
  
  if (0 < *(int *)(addr_2 + 0x28)) {
    err = _proc_pidpath(*(int *)(addr_2 + 0x28),*(void **)(handle + 0x28),0x1000);
    if (0 < err) {
      u = (**(void (**)(*(long *)(handle + 0x20) + 0x10))
                        (*(long *)(handle + 0x20),addr_2,*(uint64_t *)(handle + 0x28));
      return u;
    }
    ptr = *(uint64_t **)(handle + 0x28);
    size = *(uint64_t *)(addr_2 + 0xfb);
    u = *(uint64_t *)(addr_2 + 0xf3);
    *(uint8_t *)(ptr + 2) = *(uint8_t *)(addr_2 + 0x103);
    ptr[1] = size;
    *ptr = u;
    *(uint8_t *)(*(long *)(handle + 0x28) + 0x11) = 0;
  }
  return 0;
}





void coruna_block_assign_fe28(long handle,long addr_2)
{
  __Block_object_assign((void *)(handle + 0x20),*(void **)(addr_2 + 0x20),7);
  return;
}





void coruna_block_dispose_fe38(long handle)
{
  __Block_object_dispose(*(void **)(handle + 0x20),7);
  return;
}





int coruna_ctx_free_18dac(uint64_t *val)
{
  int err;
  int status;
  void *ptr;
  
  if (val == (uint64_t *)0x0) {
    err = 0xad001;
  }
  else {
    ptr = (void *)val[6];
    if (ptr != (void *)0x0) {
      coruna_objc_msgsend_19a08(ptr);
      _free(ptr);
    }
    err = coruna_rwlock_iface_destroy(val[5]);
    status = coruna_mach_port_deallocate_1adbc(val[3]);
    if (err != 0) {
      status = err;
    }
    err = status;
    if ((*(char *)(val + 1) != '\0') && (err = coruna_ctx_free_129d0(*val), status != 0)) {
      err = status;
    }
    val[6] = 0;
    val[3] = 0;
    val[2] = 0;
    val[5] = 0;
    val[4] = 0;
    val[1] = 0;
    *val = 0;
    _free(val);
  }
  return err;
}





unsigned long coruna_csops_18e40(uint64_t *arg,short *val,long n,short *m)

{
  uint u;
  pid_t lp2;
  int idx;
  unsigned long type_id;
  int *err;
  uint *buf;
  long *data;
  uint64_t *str;
  int i;
  unsigned long host_info;
  uint32_t serial_buf;
  uint8_t cache_55[4];
  int *cache_20;
  uint64_t thread_attr;
  uint32_t scratch;
  long thread_attr;
  
  thread_attr = *(long *)k_persist_stack_chk_guard_slot;
  serial_buf = 0;
  host_info = 0;
  type_id = coruna_host_kernel_version(&host_info);
  if (*(long *)k_persist_stack_chk_guard_slot == thread_attr) {
  return type_id;
  }
  ___stack_chk_fail();
  _getpid();
  cache_20 = (int *)0x0;
  thread_attr = 0;
  scratch = 0;
  {
    int csops_ok = 0;
    if (k_persist_rodata_word_1ed00 <= *(double *)k_persist_dyldversionnumber_slot) {
      lp2 = _getpid();
      idx = _csops(lp2,0,cache_55,4);
      if (-1 < idx) {
        csops_ok = 1;
      }
    }
    else {
      lp2 = _getpid();
      idx = _csops(lp2,5,&cache_20,0x14);
      if ((-1 < idx) || (err = ___error(), *err == 0x55)) {
        csops_ok = 1;
      }
    }
    if (csops_ok) {
      type_id = 0xad001;
      if ((arg == (uint64_t *)0x0) ||
         if (*(long *)k_persist_stack_chk_guard_slot == thread_attr) {
         return type_id;
         }
         ___stack_chk_fail();
      cache_20 = (int *)0x0;
      host_info = host_info & 0xffffffff00000000;
      idx = (**(void (**)(val + 0xc))(val,0xf0000,&cache_20,&host_info);
      if (*(long *)k_persist_stack_chk_guard_slot == thread_attr) {
      return type_id;
      }
      ___stack_chk_fail();
      idx = *cache_20;
      if (idx < -0x30051202) {
        if ((idx != -0x41450136) && (idx != -0x35014542)) {
          i = -0x31051202;
          if (*(long *)k_persist_stack_chk_guard_slot == thread_attr) {
          return type_id;
          }
          ___stack_chk_fail();
        }
      }
      else if (1 < idx + 0x1120532U) {
        i = -0x30051202;
        if (*(long *)k_persist_stack_chk_guard_slot == thread_attr) {
          return type_id;
        }
        ___stack_chk_fail();
      }
      if (*(long *)k_persist_stack_chk_guard_slot == thread_attr) {
      return type_id;
      }
      ___stack_chk_fail();
      if (((m == (short *)0x0) || (*m != 2)) || ((ushort)m[1] < 2)) {
        cache_20 = (int *)((unsigned long)cache_20 & 0xffffffffffffff00);
        idx = coruna_csops_128d4(&cache_20);
        if ((idx != 0) || ((char)cache_20 != '\0')) {
          type_id = 0x1e037;
          if (*(long *)k_persist_stack_chk_guard_slot == thread_attr) {
          return type_id;
          }
          ___stack_chk_fail();
        }
        data = _calloc(1,0x38);
        if (data != (long *)0x0) {
          if (m == (short *)0x0) {
            _free(data);
            if (*(long *)k_persist_stack_chk_guard_slot == thread_attr) {
            return type_id;
            }
            ___stack_chk_fail();
          }
          str = _calloc(1,0x10);
          if (str == (uint64_t *)0x0) {
            type_id = 0xad009;
          }
          else {
            *str = m;
            cache_20 = (int *)0x0;
            type_id = coruna_mach_port_set_attributes_1af18(&cache_20,m);
            if ((int)type_id == 0) {
              host_info = 0;
              idx = coruna_calloc(&host_info);
              if (idx != 0) {
                data[6] = host_info;
              }
              type_id = 0;
              *data = n;
              data[2] = (long)val;
              data[3] = (long)cache_20;
              data[4] = (long)m;
              data[5] = (long)str;
              *arg = data;
              if (*(long *)k_persist_stack_chk_guard_slot == thread_attr) {
              return type_id;
              }
              ___stack_chk_fail();
            }
            coruna_rwlock_iface_destroy(str);
          }
          _free(data);
          if (*(long *)k_persist_stack_chk_guard_slot == thread_attr) {
          return type_id;
          }
          ___stack_chk_fail();
        }
      }
      else {
        data = _calloc(1,0x38);
        if (data != (long *)0x0) {
          str = _calloc(1,0x10);
          if (str == (uint64_t *)0x0) {
            type_id = 0xad009;
          }
          else {
            *str = m;
            cache_20 = (int *)0x0;
            type_id = coruna_mach_port_set_attributes_1af18(&cache_20,m);
            if ((int)type_id == 0) {
              host_info = 0;
              idx = coruna_calloc(&host_info);
              if (idx != 0) {
                data[6] = host_info;
              }
              type_id = 0;
              *data = n;
              data[2] = (long)val;
              data[3] = (long)cache_20;
              data[4] = (long)m;
              data[5] = (long)str;
              *arg = data;
              if (*(long *)k_persist_stack_chk_guard_slot == thread_attr) {
              return type_id;
              }
              ___stack_chk_fail();
            }
            coruna_rwlock_iface_destroy(str);
          }
          _free(data);
          if (*(long *)k_persist_stack_chk_guard_slot == thread_attr) {
          return type_id;
          }
          ___stack_chk_fail();
        }
      }
    }
  }
  err = ___error();
  idx = *err;
  buf = (uint *)___error();
  u = -*buf;
  if (-1 < idx) {
    u = *buf;
  }
  type_id = (unsigned long)(u | 0x40000000);
next:
  if (*(long *)k_persist_stack_chk_guard_slot == thread_attr) {
    return type_id;
  }
  ___stack_chk_fail();
}
int * coruna_mach_port_deallocate_19110(int *flags,char *path,uint64_t val,long handle,uint64_t id_2,
                  char *str_2,long addr_2,uint64_t size_3,uint64_t off_4,
                  uint64_t off_5,mach_port_name_t *arg,uint32_t *size)
{
  uint u;
  int *err;
  long *ptr;
  int *status;
  mach_port_name_t scratch;
  unsigned long bootargs;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  long thread_attr;
  
  thread_attr = *(long *)k_persist_stack_chk_guard_slot;
  status = (int *)0xad001;
  err = flags;
  if (flags != (int *)0x0) {
    if (path == (char *)0x0) {
      status = (int *)0x1e03f;
    }
    else {
      status = (int *)0x1e03f;
      if ((((*path != '\0') && (status = (int *)0x1e01c, handle != 0)) && ((int)id_2 != 0))
         && ((status = (int *)0x1e01d, str_2 != (char *)0x0 && (*str_2 != '\0')))) {
        if (((int)size_3 == 0) || (addr_2 != 0)) {
          ptr = *(long **)(flags + 10);
          status = (int *)0xad001;
          if (ptr != (long *)0x0) {
            scratch = k_persist_rodata_word_0001ed38;
            bootargs = k_persist_rodata_word_1ed30;
            thread_attr = k_persist_rodata_word_0001ed48;
            bootargs = k_persist_rodata_word_1ed40;
            status = (int *)(**(void (**)(*ptr + 0x40))(*ptr,ptr + 1,&bootargs,2,0);
            err = status;
            if ((int)status == 0) {
              bootargs = bootargs & 0xffffffff00000000;
              status = (int *)coruna_realpath(path,val,&bootargs);
              err = status;
              if ((int)status == 0) {
                scratch = 0;
                status = (int *)coruna_task_for_pid(*(uint64_t *)(flags + 10),bootargs & 0xffffffff,
                                             &scratch);
                if ((uint)status == 0) {
                  status = (int *)coruna_objc_msgsend(flags,scratch,handle,id_2,str_2,addr_2,
                                               size_3,off_4,off_5);
                  if ((int)status == 0) {
                    if (arg != (mach_port_name_t *)0x0) {
                      *arg = scratch;
                      scratch = 0;
                    }
                    if (size != (uint32_t *)0x0) {
                      *size = (uint32_t)bootargs;
                    }
                  }
                  err = status;
                  if (1 < scratch + 1) {
                    u = *(uint *)k_persist_mach_task_self_slot;
                    err = (int *)(unsigned long)u;
                    if (u != scratch) {
                      u = _mach_port_deallocate(u,scratch);
                      err = (int *)(unsigned long)u;
                    }
                  }
                }
                else {
                  err = (int *)_csops_audittoken(bootargs & 0xffffffff,0,0,0,1);
                  if ((int)err != 0) {
                    err = ___error();
                    u = 0x1e03f;
                    if (*err != 3) {
                      u = (uint)status;
                    }
                    status = (int *)(unsigned long)u;
                  }
                }
              }
              ptr = *(long **)(flags + 10);
              if ((ptr != (long *)0x0) && (ptr[1] != 0)) {
                err = (int *)(**(void (**)(*ptr + 0x30))();
              }
            }
          }
        }
        else {
          status = (int *)0x1e01e;
        }
      }
    }
  }
  if (*(long *)k_persist_stack_chk_guard_slot == thread_attr) {
    return status;
  }
  ___stack_chk_fail(err);
}





uint64_t
void coruna_objc_msgsend(uint64_t *val,uint64_t id_2,long handle,uint64_t size_3,char *path,
            long addr_2,uint64_t off_4,uint64_t off_5,uint64_t off_6)
{
  kern_return_t lk1;
  int err;
  pid_t lp3;
  int status;
  uint64_t u;
  mach_port_name_t t;
  long handle;
  uint32_t scratch;
  int bootargs;
  unsigned long thread_attr;
  uint64_t host_info;
  uint32_t serial_buf;
  
  bootargs = -1;
  if (val == (uint64_t *)0x0) {
    return 0xad001;
  }
  t = (mach_port_name_t)id_2;
  if (t + 1 < 2) {
    return 0x1e009;
  }
  if (handle == 0) {
    return 0x1e01c;
  }
  if ((int)size_3 == 0) {
    return 0x1e01c;
  }
  if (path == (char *)0x0) {
    return 0x1e01d;
  }
  if (*path == '\0') {
    return 0x1e01d;
  }
  if (((int)off_4 != 0) && (addr_2 == 0)) {
    return 0x1e01e;
  }
  lk1 = _pid_for_task(t,&bootargs);
  status = bootargs;
  if (lk1 == 0) {
    serial_buf = 0;
    host_info = 0;
    err = coruna_host_kernel_version(&host_info);
    if ((err == 0) && (0 < status)) {
      lp3 = _getpid();
      if (lp3 != status) {
        thread_attr = 0;
        status = _proc_pidinfo(status,0x13,0,&thread_attr,8);
        if (status != 8) {
          return 0x1e03f;
        }
        if ((int)thread_attr != 0x100000c) {
          return 0x1e03f;
        }
        if ((thread_attr & 0xfffffe00000000) != 0) {
          return 0x1e03f;
        }
      }
      u = coruna_persistb080_via_macho_open_image_3(*val,id_2,handle,size_3);
      if ((int)u != 0) {
        return u;
      }
      host_info = coruna_u64_pack((host_info), (0xffffffff));
      lk1 = _pid_for_task(t,(int *)&host_info);
      if ((((lk1 == 0) && (0 < (int)host_info)) && (handle = val[6], handle != 0)) &&
         (((*(long *)(handle + 8) != 0 && (*(long *)(handle + 0x18) != 0)) &&
          (status = _objc_msgSend(), status == 2)))) {
        return 0x1e041;
      }
      thread_attr = thread_attr & 0xffffffff00000000;
      scratch = 0;
      u = coruna_pthread_create(val[3],&thread_attr,&scratch);
      if ((int)u != 0) {
        return u;
      }
      u = coruna_persistb080_residual_144(val[5],id_2);
      if ((int)u == 0) {
        host_info = 0;
        u = coruna_mach_port_deallocate_17b60(&host_info,*val,id_2,val[2],thread_attr & 0xffffffff,scratch);
        if ((int)u == 0) {
          u = coruna_pthread_attr_setdetachstate(host_info,handle,size_3,off_5,path,addr_2,off_4,off_6);
          coruna_mach_port_deallocate(host_info);
          return u;
        }
        return u;
      }
      return u;
    }
  }
  return 0x1e03f;
}
int * coruna_mach_port_deallocate_19584(int *flags,uint64_t val,long handle,uint64_t id_2,char *path,
                  long addr_2,uint64_t size_3,uint64_t off_4,uint64_t off_5,
                  mach_port_name_t *arg)
{
  uint u;
  int *err;
  long *ptr;
  int *status;
  unsigned long scratch;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  long bootargs;
  
  bootargs = *(long *)k_persist_stack_chk_guard_slot;
  status = (int *)0xad001;
  err = flags;
  if (*(long *)k_persist_stack_chk_guard_slot == bootargs) {
  return status;
  }
  ___stack_chk_fail(err);
  if ((int)val < 1) {
    status = (int *)0x1e03f;
    if (*(long *)k_persist_stack_chk_guard_slot == bootargs) {
    return status;
    }
    ___stack_chk_fail(err);
  }
  status = (int *)0x1e01c;
  if (*(long *)k_persist_stack_chk_guard_slot == bootargs) {
  return status;
  }
  ___stack_chk_fail(err);
  if (path == (char *)0x0) {
    status = (int *)0x1e01d;
    if (*(long *)k_persist_stack_chk_guard_slot == bootargs) {
    return status;
    }
    ___stack_chk_fail(err);
  }
  status = (int *)0x1e01d;
  if (*(long *)k_persist_stack_chk_guard_slot == bootargs) {
  return status;
  }
  ___stack_chk_fail(err);
  if (((int)size_3 != 0) && (addr_2 == 0)) {
    status = (int *)0x1e01e;
    if (*(long *)k_persist_stack_chk_guard_slot == bootargs) {
    return status;
    }
    ___stack_chk_fail(err);
  }
  ptr = *(long **)(flags + 10);
  status = (int *)0xad001;
  if (*(long *)k_persist_stack_chk_guard_slot == bootargs) {
  return status;
  }
  ___stack_chk_fail(err);
  scratch = k_persist_rodata_word_0001ed38;
  scratch = k_persist_rodata_word_1ed30;
  thread_attr = k_persist_rodata_word_0001ed48;
  bootargs = k_persist_rodata_word_1ed40;
  status = (int *)(**(void (**)(*ptr + 0x40))(*ptr,ptr + 1,&scratch,2,0);
  err = status;
  if (*(long *)k_persist_stack_chk_guard_slot == bootargs) {
  return status;
  }
  ___stack_chk_fail(err);
  scratch = scratch & 0xffffffff00000000;
  status = (int *)coruna_task_for_pid(*(uint64_t *)(flags + 10),val,&scratch);
  if ((uint)status == 0) {
    status = (int *)coruna_objc_msgsend(flags,scratch & 0xffffffff,handle,id_2,path,addr_2,
                                 size_3,off_4,off_5);
    err = status;
    if (((int)status == 0) && (arg != (mach_port_name_t *)0x0)) {
      *arg = (mach_port_name_t)scratch;
      status = (int *)0x0;
done:
      scratch = scratch & 0xffffffff00000000;
    }
    else if (1 < (mach_port_name_t)scratch + 1) {
      u = *(uint *)k_persist_mach_task_self_slot;
      err = (int *)(unsigned long)u;
      if (u != (mach_port_name_t)scratch) {
        u = _mach_port_deallocate(u,(mach_port_name_t)scratch);
        err = (int *)(unsigned long)u;
        goto done;
      }
    }
  }
  else {
    err = (int *)_csops_audittoken(val,0,0,0,1);
    if ((int)err != 0) {
      err = ___error();
      u = 0x1e03f;
      if (*err != 3) {
        u = (uint)status;
      }
      status = (int *)(unsigned long)u;
    }
  }
  ptr = *(long **)(flags + 10);
  if ((ptr != (long *)0x0) && (ptr[1] != 0)) {
    err = (int *)(**(void (**)(*ptr + 0x30))();
  }
fail:
  if (*(long *)k_persist_stack_chk_guard_slot == bootargs) {
    return status;
  }
  ___stack_chk_fail(err);
}





uint32_t coruna_host_kernel_version(void)
{
  mach_port_t host;
  kern_return_t lk1;
  int err;
  char *ptr;
  uint32_t u;
  uint64_t scratch;
  size_t bootargs;
  char thread_attr [520];
  long host_info;
  
  host_info = *(long *)k_persist_stack_chk_guard_slot;
  u = 0xad011;
  thread_attr[0x1e8] = '\0';
  thread_attr[0x1e9] = '\0';
  thread_attr[0x1ea] = '\0';
  thread_attr[0x1eb] = '\0';
  thread_attr[0x1ec] = '\0';
  thread_attr[0x1ed] = '\0';
  thread_attr[0x1ee] = '\0';
  thread_attr[0x1ef] = '\0';
  thread_attr[0x1e0] = '\0';
  thread_attr[0x1e1] = '\0';
  thread_attr[0x1e2] = '\0';
  thread_attr[0x1e3] = '\0';
  thread_attr[0x1e4] = '\0';
  thread_attr[0x1e5] = '\0';
  thread_attr[0x1e6] = '\0';
  thread_attr[0x1e7] = '\0';
  thread_attr[0x1f8] = '\0';
  thread_attr[0x1f9] = '\0';
  thread_attr[0x1fa] = '\0';
  thread_attr[0x1fb] = '\0';
  thread_attr[0x1fc] = '\0';
  thread_attr[0x1fd] = '\0';
  thread_attr[0x1fe] = '\0';
  thread_attr[0x1ff] = '\0';
  thread_attr[0x1f0] = '\0';
  thread_attr[0x1f1] = '\0';
  thread_attr[0x1f2] = '\0';
  thread_attr[499] = '\0';
  thread_attr[500] = '\0';
  thread_attr[0x1f5] = '\0';
  thread_attr[0x1f6] = '\0';
  thread_attr[0x1f7] = '\0';
  thread_attr[0x1c8] = '\0';
  thread_attr[0x1c9] = '\0';
  thread_attr[0x1ca] = '\0';
  thread_attr[0x1cb] = '\0';
  thread_attr[0x1cc] = '\0';
  thread_attr[0x1cd] = '\0';
  thread_attr[0x1ce] = '\0';
  thread_attr[0x1cf] = '\0';
  thread_attr[0x1c0] = '\0';
  thread_attr[0x1c1] = '\0';
  thread_attr[0x1c2] = '\0';
  thread_attr[0x1c3] = '\0';
  thread_attr[0x1c4] = '\0';
  thread_attr[0x1c5] = '\0';
  thread_attr[0x1c6] = '\0';
  thread_attr[0x1c7] = '\0';
  thread_attr[0x1d8] = '\0';
  thread_attr[0x1d9] = '\0';
  thread_attr[0x1da] = '\0';
  thread_attr[0x1db] = '\0';
  thread_attr[0x1dc] = '\0';
  thread_attr[0x1dd] = '\0';
  thread_attr[0x1de] = '\0';
  thread_attr[0x1df] = '\0';
  thread_attr[0x1d0] = '\0';
  thread_attr[0x1d1] = '\0';
  thread_attr[0x1d2] = '\0';
  thread_attr[0x1d3] = '\0';
  thread_attr[0x1d4] = '\0';
  thread_attr[0x1d5] = '\0';
  thread_attr[0x1d6] = '\0';
  thread_attr[0x1d7] = '\0';
  thread_attr[0x1a8] = '\0';
  thread_attr[0x1a9] = '\0';
  thread_attr[0x1aa] = '\0';
  thread_attr[0x1ab] = '\0';
  thread_attr[0x1ac] = '\0';
  thread_attr[0x1ad] = '\0';
  thread_attr[0x1ae] = '\0';
  thread_attr[0x1af] = '\0';
  thread_attr[0x1a0] = '\0';
  thread_attr[0x1a1] = '\0';
  thread_attr[0x1a2] = '\0';
  thread_attr[0x1a3] = '\0';
  thread_attr[0x1a4] = '\0';
  thread_attr[0x1a5] = '\0';
  thread_attr[0x1a6] = '\0';
  thread_attr[0x1a7] = '\0';
  thread_attr[0x1b8] = '\0';
  thread_attr[0x1b9] = '\0';
  thread_attr[0x1ba] = '\0';
  thread_attr[0x1bb] = '\0';
  thread_attr[0x1bc] = '\0';
  thread_attr[0x1bd] = '\0';
  thread_attr[0x1be] = '\0';
  thread_attr[0x1bf] = '\0';
  thread_attr[0x1b0] = '\0';
  thread_attr[0x1b1] = '\0';
  thread_attr[0x1b2] = '\0';
  thread_attr[0x1b3] = '\0';
  thread_attr[0x1b4] = '\0';
  thread_attr[0x1b5] = '\0';
  thread_attr[0x1b6] = '\0';
  thread_attr[0x1b7] = '\0';
  thread_attr[0x188] = '\0';
  thread_attr[0x189] = '\0';
  thread_attr[0x18a] = '\0';
  thread_attr[0x18b] = '\0';
  thread_attr[0x18c] = '\0';
  thread_attr[0x18d] = '\0';
  thread_attr[0x18e] = '\0';
  thread_attr[399] = '\0';
  thread_attr[0x180] = '\0';
  thread_attr[0x181] = '\0';
  thread_attr[0x182] = '\0';
  thread_attr[0x183] = '\0';
  thread_attr[0x184] = '\0';
  thread_attr[0x185] = '\0';
  thread_attr[0x186] = '\0';
  thread_attr[0x187] = '\0';
  thread_attr[0x198] = '\0';
  thread_attr[0x199] = '\0';
  thread_attr[0x19a] = '\0';
  thread_attr[0x19b] = '\0';
  thread_attr[0x19c] = '\0';
  thread_attr[0x19d] = '\0';
  thread_attr[0x19e] = '\0';
  thread_attr[0x19f] = '\0';
  thread_attr[400] = '\0';
  thread_attr[0x191] = '\0';
  thread_attr[0x192] = '\0';
  thread_attr[0x193] = '\0';
  thread_attr[0x194] = '\0';
  thread_attr[0x195] = '\0';
  thread_attr[0x196] = '\0';
  thread_attr[0x197] = '\0';
  thread_attr[0x168] = '\0';
  thread_attr[0x169] = '\0';
  thread_attr[0x16a] = '\0';
  thread_attr[0x16b] = '\0';
  thread_attr[0x16c] = '\0';
  thread_attr[0x16d] = '\0';
  thread_attr[0x16e] = '\0';
  thread_attr[0x16f] = '\0';
  thread_attr[0x160] = '\0';
  thread_attr[0x161] = '\0';
  thread_attr[0x162] = '\0';
  thread_attr[0x163] = '\0';
  thread_attr[0x164] = '\0';
  thread_attr[0x165] = '\0';
  thread_attr[0x166] = '\0';
  thread_attr[0x167] = '\0';
  thread_attr[0x178] = '\0';
  thread_attr[0x179] = '\0';
  thread_attr[0x17a] = '\0';
  thread_attr[0x17b] = '\0';
  thread_attr[0x17c] = '\0';
  thread_attr[0x17d] = '\0';
  thread_attr[0x17e] = '\0';
  thread_attr[0x17f] = '\0';
  thread_attr[0x170] = '\0';
  thread_attr[0x171] = '\0';
  thread_attr[0x172] = '\0';
  thread_attr[0x173] = '\0';
  thread_attr[0x174] = '\0';
  thread_attr[0x175] = '\0';
  thread_attr[0x176] = '\0';
  thread_attr[0x177] = '\0';
  thread_attr[0x148] = '\0';
  thread_attr[0x149] = '\0';
  thread_attr[0x14a] = '\0';
  thread_attr[0x14b] = '\0';
  thread_attr[0x14c] = '\0';
  thread_attr[0x14d] = '\0';
  thread_attr[0x14e] = '\0';
  thread_attr[0x14f] = '\0';
  thread_attr[0x140] = '\0';
  thread_attr[0x141] = '\0';
  thread_attr[0x142] = '\0';
  thread_attr[0x143] = '\0';
  thread_attr[0x144] = '\0';
  thread_attr[0x145] = '\0';
  thread_attr[0x146] = '\0';
  thread_attr[0x147] = '\0';
  thread_attr[0x158] = '\0';
  thread_attr[0x159] = '\0';
  thread_attr[0x15a] = '\0';
  thread_attr[0x15b] = '\0';
  thread_attr[0x15c] = '\0';
  thread_attr[0x15d] = '\0';
  thread_attr[0x15e] = '\0';
  thread_attr[0x15f] = '\0';
  thread_attr[0x150] = '\0';
  thread_attr[0x151] = '\0';
  thread_attr[0x152] = '\0';
  thread_attr[0x153] = '\0';
  thread_attr[0x154] = '\0';
  thread_attr[0x155] = '\0';
  thread_attr[0x156] = '\0';
  thread_attr[0x157] = '\0';
  thread_attr[0x128] = '\0';
  thread_attr[0x129] = '\0';
  thread_attr[0x12a] = '\0';
  thread_attr[299] = '\0';
  thread_attr[300] = '\0';
  thread_attr[0x12d] = '\0';
  thread_attr[0x12e] = '\0';
  thread_attr[0x12f] = '\0';
  thread_attr[0x120] = '\0';
  thread_attr[0x121] = '\0';
  thread_attr[0x122] = '\0';
  thread_attr[0x123] = '\0';
  thread_attr[0x124] = '\0';
  thread_attr[0x125] = '\0';
  thread_attr[0x126] = '\0';
  thread_attr[0x127] = '\0';
  thread_attr[0x138] = '\0';
  thread_attr[0x139] = '\0';
  thread_attr[0x13a] = '\0';
  thread_attr[0x13b] = '\0';
  thread_attr[0x13c] = '\0';
  thread_attr[0x13d] = '\0';
  thread_attr[0x13e] = '\0';
  thread_attr[0x13f] = '\0';
  thread_attr[0x130] = '\0';
  thread_attr[0x131] = '\0';
  thread_attr[0x132] = '\0';
  thread_attr[0x133] = '\0';
  thread_attr[0x134] = '\0';
  thread_attr[0x135] = '\0';
  thread_attr[0x136] = '\0';
  thread_attr[0x137] = '\0';
  thread_attr[0x108] = '\0';
  thread_attr[0x109] = '\0';
  thread_attr[0x10a] = '\0';
  thread_attr[0x10b] = '\0';
  thread_attr[0x10c] = '\0';
  thread_attr[0x10d] = '\0';
  thread_attr[0x10e] = '\0';
  thread_attr[0x10f] = '\0';
  thread_attr[0x100] = '\0';
  thread_attr[0x101] = '\0';
  thread_attr[0x102] = '\0';
  thread_attr[0x103] = '\0';
  thread_attr[0x104] = '\0';
  thread_attr[0x105] = '\0';
  thread_attr[0x106] = '\0';
  thread_attr[0x107] = '\0';
  thread_attr[0x118] = '\0';
  thread_attr[0x119] = '\0';
  thread_attr[0x11a] = '\0';
  thread_attr[0x11b] = '\0';
  thread_attr[0x11c] = '\0';
  thread_attr[0x11d] = '\0';
  thread_attr[0x11e] = '\0';
  thread_attr[0x11f] = '\0';
  thread_attr[0x110] = '\0';
  thread_attr[0x111] = '\0';
  thread_attr[0x112] = '\0';
  thread_attr[0x113] = '\0';
  thread_attr[0x114] = '\0';
  thread_attr[0x115] = '\0';
  thread_attr[0x116] = '\0';
  thread_attr[0x117] = '\0';
  thread_attr[0xe8] = '\0';
  thread_attr[0xe9] = '\0';
  thread_attr[0xea] = '\0';
  thread_attr[0xeb] = '\0';
  thread_attr[0xec] = '\0';
  thread_attr[0xed] = '\0';
  thread_attr[0xee] = '\0';
  thread_attr[0xef] = '\0';
  thread_attr[0xe0] = '\0';
  thread_attr[0xe1] = '\0';
  thread_attr[0xe2] = '\0';
  thread_attr[0xe3] = '\0';
  thread_attr[0xe4] = '\0';
  thread_attr[0xe5] = '\0';
  thread_attr[0xe6] = '\0';
  thread_attr[0xe7] = '\0';
  thread_attr[0xf8] = '\0';
  thread_attr[0xf9] = '\0';
  thread_attr[0xfa] = '\0';
  thread_attr[0xfb] = '\0';
  thread_attr[0xfc] = '\0';
  thread_attr[0xfd] = '\0';
  thread_attr[0xfe] = '\0';
  thread_attr[0xff] = '\0';
  thread_attr[0xf0] = '\0';
  thread_attr[0xf1] = '\0';
  thread_attr[0xf2] = '\0';
  thread_attr[0xf3] = '\0';
  thread_attr[0xf4] = '\0';
  thread_attr[0xf5] = '\0';
  thread_attr[0xf6] = '\0';
  thread_attr[0xf7] = '\0';
  thread_attr[200] = '\0';
  thread_attr[0xc9] = '\0';
  thread_attr[0xca] = '\0';
  thread_attr[0xcb] = '\0';
  thread_attr[0xcc] = '\0';
  thread_attr[0xcd] = '\0';
  thread_attr[0xce] = '\0';
  thread_attr[0xcf] = '\0';
  thread_attr[0xc0] = '\0';
  thread_attr[0xc1] = '\0';
  thread_attr[0xc2] = '\0';
  thread_attr[0xc3] = '\0';
  thread_attr[0xc4] = '\0';
  thread_attr[0xc5] = '\0';
  thread_attr[0xc6] = '\0';
  thread_attr[199] = '\0';
  thread_attr[0xd8] = '\0';
  thread_attr[0xd9] = '\0';
  thread_attr[0xda] = '\0';
  thread_attr[0xdb] = '\0';
  thread_attr[0xdc] = '\0';
  thread_attr[0xdd] = '\0';
  thread_attr[0xde] = '\0';
  thread_attr[0xdf] = '\0';
  thread_attr[0xd0] = '\0';
  thread_attr[0xd1] = '\0';
  thread_attr[0xd2] = '\0';
  thread_attr[0xd3] = '\0';
  thread_attr[0xd4] = '\0';
  thread_attr[0xd5] = '\0';
  thread_attr[0xd6] = '\0';
  thread_attr[0xd7] = '\0';
  thread_attr[0xa8] = '\0';
  thread_attr[0xa9] = '\0';
  thread_attr[0xaa] = '\0';
  thread_attr[0xab] = '\0';
  thread_attr[0xac] = '\0';
  thread_attr[0xad] = '\0';
  thread_attr[0xae] = '\0';
  thread_attr[0xaf] = '\0';
  thread_attr[0xa0] = '\0';
  thread_attr[0xa1] = '\0';
  thread_attr[0xa2] = '\0';
  thread_attr[0xa3] = '\0';
  thread_attr[0xa4] = '\0';
  thread_attr[0xa5] = '\0';
  thread_attr[0xa6] = '\0';
  thread_attr[0xa7] = '\0';
  thread_attr[0xb8] = '\0';
  thread_attr[0xb9] = '\0';
  thread_attr[0xba] = '\0';
  thread_attr[0xbb] = '\0';
  thread_attr[0xbc] = '\0';
  thread_attr[0xbd] = '\0';
  thread_attr[0xbe] = '\0';
  thread_attr[0xbf] = '\0';
  thread_attr[0xb0] = '\0';
  thread_attr[0xb1] = '\0';
  thread_attr[0xb2] = '\0';
  thread_attr[0xb3] = '\0';
  thread_attr[0xb4] = '\0';
  thread_attr[0xb5] = '\0';
  thread_attr[0xb6] = '\0';
  thread_attr[0xb7] = '\0';
  thread_attr[0x88] = '\0';
  thread_attr[0x89] = '\0';
  thread_attr[0x8a] = '\0';
  thread_attr[0x8b] = '\0';
  thread_attr[0x8c] = '\0';
  thread_attr[0x8d] = '\0';
  thread_attr[0x8e] = '\0';
  thread_attr[0x8f] = '\0';
  thread_attr[0x80] = '\0';
  thread_attr[0x81] = '\0';
  thread_attr[0x82] = '\0';
  thread_attr[0x83] = '\0';
  thread_attr[0x84] = '\0';
  thread_attr[0x85] = '\0';
  thread_attr[0x86] = '\0';
  thread_attr[0x87] = '\0';
  thread_attr[0x98] = '\0';
  thread_attr[0x99] = '\0';
  thread_attr[0x9a] = '\0';
  thread_attr[0x9b] = '\0';
  thread_attr[0x9c] = '\0';
  thread_attr[0x9d] = '\0';
  thread_attr[0x9e] = '\0';
  thread_attr[0x9f] = '\0';
  thread_attr[0x90] = '\0';
  thread_attr[0x91] = '\0';
  thread_attr[0x92] = '\0';
  thread_attr[0x93] = '\0';
  thread_attr[0x94] = '\0';
  thread_attr[0x95] = '\0';
  thread_attr[0x96] = '\0';
  thread_attr[0x97] = '\0';
  thread_attr[0x68] = '\0';
  thread_attr[0x69] = '\0';
  thread_attr[0x6a] = '\0';
  thread_attr[0x6b] = '\0';
  thread_attr[0x6c] = '\0';
  thread_attr[0x6d] = '\0';
  thread_attr[0x6e] = '\0';
  thread_attr[0x6f] = '\0';
  thread_attr[0x60] = '\0';
  thread_attr[0x61] = '\0';
  thread_attr[0x62] = '\0';
  thread_attr[99] = '\0';
  thread_attr[100] = '\0';
  thread_attr[0x65] = '\0';
  thread_attr[0x66] = '\0';
  thread_attr[0x67] = '\0';
  thread_attr[0x78] = '\0';
  thread_attr[0x79] = '\0';
  thread_attr[0x7a] = '\0';
  thread_attr[0x7b] = '\0';
  thread_attr[0x7c] = '\0';
  thread_attr[0x7d] = '\0';
  thread_attr[0x7e] = '\0';
  thread_attr[0x7f] = '\0';
  thread_attr[0x70] = '\0';
  thread_attr[0x71] = '\0';
  thread_attr[0x72] = '\0';
  thread_attr[0x73] = '\0';
  thread_attr[0x74] = '\0';
  thread_attr[0x75] = '\0';
  thread_attr[0x76] = '\0';
  thread_attr[0x77] = '\0';
  thread_attr[0x48] = '\0';
  thread_attr[0x49] = '\0';
  thread_attr[0x4a] = '\0';
  thread_attr[0x4b] = '\0';
  thread_attr[0x4c] = '\0';
  thread_attr[0x4d] = '\0';
  thread_attr[0x4e] = '\0';
  thread_attr[0x4f] = '\0';
  thread_attr[0x40] = '\0';
  thread_attr[0x41] = '\0';
  thread_attr[0x42] = '\0';
  thread_attr[0x43] = '\0';
  thread_attr[0x44] = '\0';
  thread_attr[0x45] = '\0';
  thread_attr[0x46] = '\0';
  thread_attr[0x47] = '\0';
  thread_attr[0x58] = '\0';
  thread_attr[0x59] = '\0';
  thread_attr[0x5a] = '\0';
  thread_attr[0x5b] = '\0';
  thread_attr[0x5c] = '\0';
  thread_attr[0x5d] = '\0';
  thread_attr[0x5e] = '\0';
  thread_attr[0x5f] = '\0';
  thread_attr[0x50] = '\0';
  thread_attr[0x51] = '\0';
  thread_attr[0x52] = '\0';
  thread_attr[0x53] = '\0';
  thread_attr[0x54] = '\0';
  thread_attr[0x55] = '\0';
  thread_attr[0x56] = '\0';
  thread_attr[0x57] = '\0';
  thread_attr[0x28] = '\0';
  thread_attr[0x29] = '\0';
  thread_attr[0x2a] = '\0';
  thread_attr[0x2b] = '\0';
  thread_attr[0x2c] = '\0';
  thread_attr[0x2d] = '\0';
  thread_attr[0x2e] = '\0';
  thread_attr[0x2f] = '\0';
  thread_attr[0x20] = '\0';
  thread_attr[0x21] = '\0';
  thread_attr[0x22] = '\0';
  thread_attr[0x23] = '\0';
  thread_attr[0x24] = '\0';
  thread_attr[0x25] = '\0';
  thread_attr[0x26] = '\0';
  thread_attr[0x27] = '\0';
  thread_attr[0x38] = '\0';
  thread_attr[0x39] = '\0';
  thread_attr[0x3a] = '\0';
  thread_attr[0x3b] = '\0';
  thread_attr[0x3c] = '\0';
  thread_attr[0x3d] = '\0';
  thread_attr[0x3e] = '\0';
  thread_attr[0x3f] = '\0';
  thread_attr[0x30] = '\0';
  thread_attr[0x31] = '\0';
  thread_attr[0x32] = '\0';
  thread_attr[0x33] = '\0';
  thread_attr[0x34] = '\0';
  thread_attr[0x35] = '\0';
  thread_attr[0x36] = '\0';
  thread_attr[0x37] = '\0';
  thread_attr[8] = '\0';
  thread_attr[9] = '\0';
  thread_attr[10] = '\0';
  thread_attr[0xb] = '\0';
  thread_attr[0xc] = '\0';
  thread_attr[0xd] = '\0';
  thread_attr[0xe] = '\0';
  thread_attr[0xf] = '\0';
  thread_attr[0] = '\0';
  thread_attr[1] = '\0';
  thread_attr[2] = '\0';
  thread_attr[3] = '\0';
  thread_attr[4] = '\0';
  thread_attr[5] = '\0';
  thread_attr[6] = '\0';
  thread_attr[7] = '\0';
  thread_attr[0x18] = '\0';
  thread_attr[0x19] = '\0';
  thread_attr[0x1a] = '\0';
  thread_attr[0x1b] = '\0';
  thread_attr[0x1c] = '\0';
  thread_attr[0x1d] = '\0';
  thread_attr[0x1e] = '\0';
  thread_attr[0x1f] = '\0';
  thread_attr[0x10] = '\0';
  thread_attr[0x11] = '\0';
  thread_attr[0x12] = '\0';
  thread_attr[0x13] = '\0';
  thread_attr[0x14] = '\0';
  thread_attr[0x15] = '\0';
  thread_attr[0x16] = '\0';
  thread_attr[0x17] = '\0';
  host = _mach_host_self();
  lk1 = _host_kernel_version(host,thread_attr);
  if (lk1 != 0) {
    if (*(long *)k_persist_stack_chk_guard_slot != host_info) {
    ___stack_chk_fail();
    }
    return u;
    scratch = k_persist_rodata_word_1ed08;
    bootargs = 0x200;
    err = _sysctl((int *)&scratch,2,thread_attr,&bootargs,(void *)0x0,0);
    if (*(long *)k_persist_stack_chk_guard_slot != host_info) {
    ___stack_chk_fail();
    }
    return u;
  }
  ptr = _strstr(thread_attr,"xnu-");
  if (ptr != (char *)0x0) {
    err = _sscanf(ptr + 4,"%u.%u.%u");
    u = 0;
    if (err != 3) {
      u = 0xad011;
    }
  }
fail:
  if (*(long *)k_persist_stack_chk_guard_slot != host_info) {
    ___stack_chk_fail();
  }
  return u;
}





uint64_t coruna_class_respondstoselector(long *handle)
{
  int err;
  long handle;
  long addr;
  long off;
  long base;
  long ctx_val;
  long serial;
  uint64_t u;
  
  u = 0;
  if (handle != (long *)0x0) {
    handle[1] = 0;
    *handle = 0;
    handle[3] = 0;
    handle[2] = 0;
    handle = _dlopen("/System/Library/PrivateFrameworks/AssertionServices.framework/AssertionServices"
                    ,10);
    if (handle == 0) {
      u = 1;
    }
    else {
      addr = _objc_getClass("BKSApplicationStateMonitor");
      off = _sel_registerName("alloc");
      base = _sel_registerName("init");
      ctx_val = _sel_registerName("release");
      serial = _sel_registerName("mostElevatedApplicationStateForPID:");
      if ((((((addr != 0) && (off != 0)) && (base != 0)) && ((ctx_val != 0 && (serial != 0)))) &&
          ((err = _class_respondsToSelector(addr,base), err != 0 &&
           ((err = _class_respondsToSelector(addr,serial), err != 0 &&
            (err = _class_respondsToSelector(addr,ctx_val), err != 0)))))) &&
         (addr = _objc_msgSend(addr,off), addr != 0)) {
        off = _objc_msgSend(addr,base);
        if (off != 0) {
          *handle = handle;
          handle[1] = addr;
          handle[2] = ctx_val;
          handle[3] = serial;
          return 1;
        }
        _objc_msgSend(addr,ctx_val);
      }
      _dlclose(handle);
      u = 0;
    }
  }
  return u;
}





bool coruna_objc_msgsend_19a08(long *handle)
{
  if (handle != (long *)0x0) {
    if ((handle[1] != 0) && (handle[2] != 0)) {
      _objc_msgSend();
    }
    if (*handle != 0) {
      _dlclose();
    }
    handle[1] = 0;
    *handle = 0;
    handle[3] = 0;
    handle[2] = 0;
  }
  return handle != (long *)0x0;
}





uint64_t coruna_calloc(uint64_t *val)
{
  int err;
  void *ptr;
  uint64_t u;
  
  u = 0;
  if ((val != (uint64_t *)0x0) && (ptr = _calloc(1,0x20), u = 0, ptr != (void *)0x0)
     ) {
    err = coruna_class_respondstoselector();
    if (err == 0) {
      _free(ptr);
      u = 0;
    }
    else {
      *val = ptr;
      u = 1;
    }
  }
  return u;
}





uint32_t
void coruna_mach_msg_destroy(mach_port_t port,mach_msg_header_t *arg,mach_msg_size_t arg_x,
            mach_msg_timeout_t arg_x_x,int flags)
{
  mach_msg_return_t lm1;
  uint32_t u;
  
  u = 0xad001;
  if (((arg != (mach_msg_header_t *)0x0) && (arg_x != 0)) &&
     (u = 0x1e01b, 1 < port + 1)) {
    arg->msgh_bits = 0x13;
    arg->msgh_size = arg_x;
    arg->msgh_local_port = 0;
    arg->msgh_reserved = 0;
    arg->msgh_remote_port = port;
    if (flags != 0) {
      arg->msgh_bits = 0x80000013;
    }
    lm1 = _mach_msg(arg,0x11,arg_x,0,0,arg_x_x,0);
    if (lm1 == 0) {
      u = 0;
    }
    else if (lm1 == 0x10000004) {
      _mach_msg_destroy(arg);
      u = 0x1e030;
    }
    else {
      u = 0x1e025;
      if (lm1 == 0x10000003) {
        u = 0x1e02f;
      }
    }
  }
  return u;
}





uint32_t
void coruna_mach_msg_destroy_19b70(mach_port_name_t arg,int flags,uint size,mach_msg_header_t *arg_x,
            mach_msg_timeout_t arg_x_x)
{
  uint u;
  uint32_t size;
  
  if (arg_x == (mach_msg_header_t *)0x0) {
    return 0xad001;
  }
  if (size == 0) {
    return 0xad001;
  }
  size = 0x1e021;
  if (arg + 1 < 2) {
    return 0x1e01b;
  }
  _bzero(arg_x,(unsigned long)size);
  arg_x->msgh_remote_port = arg;
  arg_x->msgh_local_port = arg;
  arg_x->msgh_bits = 0x13;
  arg_x->msgh_size = size;
  u = _mach_msg(arg_x,0x102,0,size,arg,arg_x_x,0);
  if ((int)u < 0x10004003) {
    if (u == 0) {
      if (arg_x->msgh_id == flags) {
        if (-1 < (int)arg_x->msgh_bits) {
          return 0;
        }
        size = 0x1e019;
      }
      else {
        size = 0x1e03d;
      }
      _mach_msg_destroy(arg_x);
      return size;
    }
    if (u == 0x10004002) {
      return 0x1e031;
    }
  }
  else {
    if (u == 0x10004003) {
      return 0x1e02a;
    }
    if (u == 0x10004004) {
      if (arg_x->msgh_id == flags) {
        return 0x1e021;
      }
      return 0x1e03d;
    }
  }
  if ((u & 0xfffffffb) != 0x10004008) {
    return 0x1e021;
  }
fail:
  _mach_msg_destroy(arg_x);
  return size;
}





uint64_t coruna_mach_port_allocate(mach_port_name_t *arg,uint64_t val)
{
  uint8_t *ptr;
  kern_return_t lk2;
  uint64_t u;
  mach_port_name_t scratch;
  
  ptr = k_persist_mach_task_self_slot;
  if (arg == (mach_port_name_t *)0x0) {
    u = 0xad001;
  }
  else {
    scratch = 0;
    lk2 = _mach_port_allocate(*(ipc_space_t *)k_persist_mach_task_self_slot,1,&scratch);
    if (lk2 == 0) {
      if (((int)val == 0) || (u = coruna_mach_port_set_attributes(scratch,val), (int)u == 0)) {
        u = 0;
        *arg = scratch;
      }
      else {
        _mach_port_mod_refs(*(ipc_space_t *)ptr,scratch,1,-1);
      }
    }
    else {
      u = 0x1e023;
    }
  }
  return u;
}





uint32_t coruna_mach_port_set_attributes(mach_port_name_t arg,integer_t arg_x)
{
  uint32_t u;
  kern_return_t lk2;
  integer_t scratch [2];
  
  u = 0x1e01b;
  if (1 < arg + 1) {
    scratch[0] = arg_x;
    lk2 = _mach_port_set_attributes
                      (*(ipc_space_t *)k_persist_mach_task_self_slot,arg,1,scratch,1);
    u = 0;
    if (lk2 != 0) {
      u = 0x1e032;
    }
  }
  return u;
}





uint64_t coruna_mach_port_insert_right(mach_port_t port,ipc_space_t arg,mach_port_name_t *arg_x)
{
  uint8_t *ptr;
  mach_port_name_t lm2;
  kern_return_t lk3;
  uint64_t u;
  int err;
  mach_port_name_t scratch;
  
  ptr = k_persist_mach_task_self_slot;
  if (arg_x == (mach_port_name_t *)0x0) {
    u = 0xad001;
  }
  else {
    u = 0x1e009;
    if (port + 1 < 2) {
      u = 0x1e01b;
    }
    else if (1 < arg + 1) {
      err = 8;
      do {
        scratch = 0;
        lm2 = port;
        if (*(ipc_space_t *)ptr != arg) {
          lk3 = _mach_port_allocate(arg,1,&scratch);
          if (lk3 != 0) {
            return 0x1e035;
          }
          lk3 = _mach_port_destroy(arg,scratch);
          lm2 = scratch;
          if (lk3 != 0) {
            return 0x1e034;
          }
        }
        scratch = lm2;
        lk3 = _mach_port_insert_right(arg,scratch,port,0x14);
        if ((lk3 == 0) || (*(ipc_space_t *)ptr == arg && lk3 == 0x15)) {
          *arg_x = scratch;
          return 0;
        }
        _usleep(100);
        err = err + -1;
      } while (err != 0);
      u = 0x1e033;
    }
  }
  return u;
}





int coruna_ctx_clear_19f00(uint64_t *val)
{
  int err;
  int status;
  
  if (val != (uint64_t *)0x0) {
    err = coruna_bzero_15cc8(val + 2,1);
    status = coruna_bzero_15cc8(val + 6,0x10);
    if (err != 0) {
      status = err;
    }
    err = coruna_bzero_15cc8(val + 4,4);
    if (status != 0) {
      err = status;
    }
    status = coruna_bzero_15cc8(val + 8,4);
    if (err != 0) {
      status = err;
    }
    err = coruna_bzero_15cc8(val + 10,4);
    if (status != 0) {
      err = status;
    }
    status = coruna_bzero_15cc8(val + 0xc,0x18);
    val[1] = 0;
    *val = 0;
    val[3] = 0;
    val[2] = 0;
    if (err != 0) {
      status = err;
    }
    val[5] = 0;
    val[4] = 0;
    val[7] = 0;
    val[6] = 0;
    val[9] = 0;
    val[8] = 0;
    val[0xb] = 0;
    val[10] = 0;
    val[0xd] = 0;
    val[0xc] = 0;
    return status;
  }
  return 0xad001;
}
uint64_t
void coruna_persistb080_via_u64_pack(unsigned long *arg,unsigned long arg,unsigned long val,long handle,uint size,long addr_2,
            uint64_t val,long off_3,int flags,long *ctx_4)
{
  uint64_t *ptr;
  int err;
  uint64_t u;
  char *ptr;
  int *err;
  unsigned long size;
  long *ptr;
  int status;
  unsigned long version;
  unsigned long port;
  long handle;
  long addr;
  unsigned long scratch;
  unsigned long scratch;
  unsigned long bootargs;
  unsigned long thread_attr;
  unsigned long bootargs;
  unsigned long host_info;
  unsigned long serial_buf;
  unsigned long thread_attr;
  unsigned long action;
  unsigned long host_info;
  unsigned long block_ctx;
  unsigned long stack_guard;
  unsigned long serial_buf;
  unsigned long sa_saved;
  int action;
  uint32_t sa_new;
  uint32_t path_buf;
  uint8_t tmp_buf;
  uint8_t region;
  byte block_ctx;
  uint8_t plist;
  
  if (arg == (unsigned long *)0x0) {
    return 0xad001;
  }
  if (arg == 0) {
    return 0xad001;
  }
  if ((int)val == 0) {
    return 0xad001;
  }
  if ((handle == 0) && (size != 0)) {
    return 0xad001;
  }
  if ((addr_2 == 0) && ((int)val != 0)) {
    return 0xad001;
  }
  if ((off_3 == 0) && (flags != 0)) {
    return 0xad001;
  }
  bootargs = 0;
  bootargs = 0;
  thread_attr = 0;
  sa_saved = 0;
  block_ctx = 0;
  host_info = 0;
  serial_buf = 0;
  stack_guard = 0;
  serial_buf = 0;
  host_info = 0;
  action = 0;
  thread_attr = 0;
  scratch = val & 0xffffffff;
  scratch = arg;
  u = coruna_persistb080_via_bzero(&action,addr_2,val,arg,val);
  if (((int)u != 0) ||
     (u = coruna_persistb080_via_bzero(&block_ctx,off_3,flags,arg,val), (int)u != 0))
  coruna_ctx_clear_19f00(&scratch);
  return u;
}





uint64_t coruna_persistb080_via_bzero(long *handle,unsigned long *arg,uint size,unsigned long arg,uint flags_2)
{
  uint u;
  uint64_t size;
  unsigned long version;
  unsigned long port;
  
  size = 0xad001;
  if ((handle != (long *)0x0) && ((arg != (unsigned long *)0x0 || (size == 0)))) {
    if (size != 0) {
      version = (unsigned long)size;
      do {
        port = *arg;
        if (port < arg || arg + flags_2 <= port) {
          return 0x1e007;
        }
        size = coruna_bzero(handle,1,4);
        if ((int)size != 0) {
          return size;
        }
        u = *(uint *)(handle + 1);
        *(uint *)(handle + 1) = u + 1;
        *(int *)(*handle + (unsigned long)u * 4) = (int)port - (int)arg;
        arg = arg + 1;
        version = version - 1;
      } while (version != 0);
    }
    size = 0;
  }
  return size;
}





uint64_t coruna_persistb080_via_persistb080_trampoline_00010c24(long handle,uint64_t *val,uint *size)
{
  uint64_t u;
  unsigned long *ptr;
  int err;
  uint size;
  uint version;
  uint port;
  uint64_t tag;
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t thread_attr;
  
  tag = 0xad01d;
  u = 0xad001;
  if (((handle != 0) && (val != (uint64_t *)0x0)) && (size != (uint *)0x0)) {
    bootargs = 0;
    bootargs = 0;
    thread_attr = 0;
    thread_attr = 0;
    scratch = 0;
    scratch = 0;
    size = *(uint *)(handle + 0x18);
    u = tag;
    if (size < 0xffffffd0) {
      err = 0x30;
      if (size != 0) {
        scratch = coruna_u64_pack((size), (0x30));
        if (0xffffffc8 < size) {
          return 0xad01d;
        }
        err = size + 0x30;
      }
      if (((*(uint *)(handle + 0x28) & 0xc0000000) == 0) &&
         (size = *(uint *)(handle + 0x28) * 4, size <= (-err - 8U | 7))) {
        port = err + 7U & 0xfffffff8;
        if (size != 0) {
          scratch = coruna_u64_pack((size), (err + 7U)) & 0xfffffffffffffff8;
          port = size + port;
        }
        if ((*(uint *)(handle + 0x38) & 0xf0000000) == 0) {
          version = *(uint *)(handle + 0x38) * 0x10;
          size = ~port;
          if (version <= size) {
            if (version != 0) {
              bootargs = coruna_u64_pack((version), (port));
              port = version + port;
              size = ~port;
            }
            if (((*(uint *)(handle + 0x48) & 0xc0000000) == 0) &&
               (version = *(uint *)(handle + 0x48) * 4, version <= size)) {
              if (version != 0) {
                bootargs = coruna_u64_pack((version), (port));
                port = version + port;
                size = ~port;
              }
              if (((*(uint *)(handle + 0x58) & 0xc0000000) == 0) &&
                 (version = *(uint *)(handle + 0x58) * 4, version <= size)) {
                if (version != 0) {
                  thread_attr = coruna_u64_pack((version), (port));
                  port = version + port;
                  size = ~port;
                }
                if ((((unsigned long)*(uint *)(handle + 0x68) * 0x18 & 0xffffffff00000000) == 0) &&
                   (version = *(uint *)(handle + 0x68) * 0x18, version <= size)) {
                  if (version != 0) {
                    thread_attr = coruna_u64_pack((version), (port));
                    port = version + port;
                  }
                  ptr = _calloc(1,(unsigned long)port);
                  if (ptr == (unsigned long *)0x0) {
                    u = 0xad009;
                  }
                  else {
                    ptr[1] = scratch;
                    *ptr = scratch;
                    ptr[3] = bootargs;
                    ptr[2] = bootargs;
                    ptr[5] = thread_attr;
                    ptr[4] = thread_attr;
                    if (scratch != 0) {
                      coruna_persistb080_trampoline_00010c24((long)ptr + (scratch & 0xffffffff),
                                         *(uint64_t *)(handle + 0x10));
                    }
                    if (scratch != 0) {
                      coruna_persistb080_trampoline_00010c24((long)ptr + (scratch & 0xffffffff),
                                         *(uint64_t *)(handle + 0x20));
                    }
                    if (bootargs != 0) {
                      coruna_persistb080_trampoline_00010c24((long)ptr + (bootargs & 0xffffffff),
                                         *(uint64_t *)(handle + 0x30));
                    }
                    if (bootargs != 0) {
                      coruna_persistb080_trampoline_00010c24((long)ptr + (bootargs & 0xffffffff),
                                         *(uint64_t *)(handle + 0x40));
                    }
                    if (thread_attr != 0) {
                      coruna_persistb080_trampoline_00010c24((long)ptr + (thread_attr & 0xffffffff),
                                         *(uint64_t *)(handle + 0x50));
                    }
                    if (thread_attr != 0) {
                      coruna_persistb080_trampoline_00010c24((long)ptr + (thread_attr & 0xffffffff),
                                         *(uint64_t *)(handle + 0x60));
                    }
                    u = 0;
                    *val = ptr;
                    *size = port;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return u;
}





uint64_t
void coruna_persistb080_via_persistb080_via_persistb080_trampoline_00010c24(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4,
            uint64_t off_5,uint64_t off_6,uint64_t off_7,uint32_t size,
            uint64_t off_8,long handle,long addr_2)
{
  uint64_t u;
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
  uint64_t sa_saved;
  uint64_t sa_new;
  
  if (handle == 0 || addr_2 == 0) {
    u = 0xad001;
  }
  else {
    stack_guard = 0;
    host_info = 0;
    sa_new = 0;
    sa_saved = 0;
    serial_buf = 0;
    thread_attr = 0;
    block_ctx = 0;
    action = 0;
    bootargs = 0;
    bootargs = 0;
    host_info = 0;
    thread_attr = 0;
    scratch = 0;
    scratch = 0;
    u = coruna_persistb080_via_u64_pack(&scratch,val,id_2,size_3,off_4,off_5,off_6,off_7,size,
                         off_8);
    if ((int)u == 0) {
      u = coruna_persistb080_via_persistb080_trampoline_00010c24(&scratch,handle,addr_2);
      coruna_ctx_clear_19f00(&scratch);
    }
  }
  return u;
}





uint64_t coruna_bzero(long *handle,uint size,uint flags_2)
{
  uint u;
  uint size;
  void *ptr;
  void *buf;
  uint64_t version;
  
  version = 0xad01d;
  if (handle == (long *)0x0) {
    version = 0xad001;
  }
  else {
    u = *(uint *)(handle + 1);
    if ((unsigned long)*(uint *)((long)handle + 0xc) < (unsigned long)u + (unsigned long)size) {
      size = u + size * 10;
      if ((size != 0xffffffff) && (((unsigned long)flags_2 * (unsigned long)size & 0xffffffff00000000) == 0)) {
        ptr = _calloc(1,(unsigned long)flags_2 * (unsigned long)size & 0xffffffff);
        if (ptr == (void *)0x0) {
          version = 0xad009;
        }
        else {
          buf = (void *)*handle;
          if (buf != (void *)0x0) {
            u = u * flags_2;
            if (u != 0) {
              coruna_persistb080_trampoline_00010c24(ptr,buf,(unsigned long)u);
              _bzero((void *)*handle,(unsigned long)u);
              buf = (void *)*handle;
            }
            _free(buf);
          }
          version = 0;
          *handle = (long)ptr;
          *(uint *)((long)handle + 0xc) = size;
        }
      }
    }
    else {
      version = 0;
    }
  }
  return version;
}





uint64_t coruna_bzero_15cc8(uint64_t *val,int flags)
{
  void *ptr;
  
  if (val != (uint64_t *)0x0) {
    ptr = (void *)*val;
    if (ptr != (void *)0x0) {
      if (*(int *)(val + 1) != 0) {
        _bzero(ptr,(unsigned long)(uint)(*(int *)(val + 1) * flags));
        ptr = (void *)*val;
      }
      _free(ptr);
    }
    *val = 0;
    val[1] = 0;
    return 0;
  }
  return 0xad001;
}





uint64_t coruna_persistb080_via_persistb080_trampoline_00010c24_2(long *handle,long addr_2,unsigned long arg,uint32_t *size)
{
  uint64_t u;
  
  u = 0xad001;
  if ((handle != (long *)0x0) && (addr_2 != 0)) {
    if ((int)arg == 0) {
      u = 0;
      if (size != (uint32_t *)0x0) {
        *size = 0;
      }
    }
    else {
      u = coruna_bzero(handle,arg,1);
      if ((int)u == 0) {
        coruna_persistb080_trampoline_00010c24(*handle + (unsigned long)*(uint *)(handle + 1),addr_2,arg & 0xffffffff);
        if (size != (uint32_t *)0x0) {
          *size = (int)handle[1];
        }
        u = 0;
        *(int *)(handle + 1) = (int)handle[1] + (int)arg;
      }
    }
  }
  return u;
}





uint64_t coruna_memmem(int *flags,char *path,int *count_2)
{
  uint64_t u;
  size_t ls2;
  void *ptr;
  
  u = 0xad001;
  if (((flags != (int *)0x0) && (path != (char *)0x0)) && (count_2 != (int *)0x0)) {
    ls2 = _strlen(path);
    if ((flags[2] == 0) ||
       (ptr = _memmem(*(void **)flags,(unsigned long)(uint)flags[2],path,ls2 + 1),
       ptr == (void *)0x0)) {
      u = coruna_persistb080_via_persistb080_trampoline_00010c24_2(flags,path,ls2 + 1,count_2);
      return u;
    }
    u = 0;
    *count_2 = (int)ptr - *flags;
  }
  return u;
}





unsigned long coruna_mach_msg(long arg,unsigned long val,mach_msg_id_t *n,uint m,uint p,
                  mach_port_t q)

{
  uint32_t u;
  mach_msg_id_t lm2;
  mach_msg_id_t *lpm3;
  mach_msg_id_t *lpm4;
  size_t ls5;
  long ctx_val;
  uint64_t kind;
  uint64_t type_id_8;
  uint8_t *copy;
  uint type_id_13;
  void (*copy)(void);
  int j;
  unsigned long type_id_10;
  unsigned long type_id_11;
  unsigned long cache_56;
  mach_msg_id_t *cache_57;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t cache_58;
  uint64_t action;
  uint8_t cache_59[12];
  mach_port_t cache_60;
  mach_msg_size_t cache_61;
  mach_msg_id_t cache_62;
  mach_msg_id_t cache_63;
  uint8_t block_ctx;
  uint8_t stack_guard;
  uint16_t sa_saved;
  uint32_t sa_new;
  uint16_t path_buf;
  uint16_t tmp_buf;
  uint32_t region;
  uint32_t cache_64;
  int cache_65;
  uint64_t plist;
  uint64_t cache_66;
  uint64_t url_buf;
  uint64_t cache_67;
  uint64_t json_buf;
  uint64_t cache_68;
  uint64_t frame;
  uint64_t cache_69;
  uint64_t work;
  uint64_t cache_70;
  uint64_t cache;
  uint64_t cache_71;
  uint64_t cache_20;
  uint64_t cache_72;
  uint64_t cache_21;
  uint64_t sa_new;
  uint64_t cache_22;
  uint64_t cache_73;
  uint64_t cache_23;
  uint64_t cache_74;
  uint64_t cache_24;
  uint64_t cache_75;
  uint64_t cache_25;
  uint64_t cache_76;
  uint64_t cache_26;
  uint64_t cache_77;
  uint64_t cache_27;
  uint64_t cache_78;
  uint64_t cache_28;
  uint64_t cache_29;
  uint64_t cache_30;
  uint64_t cache_55;
  long block_ctx;
  
  block_ctx = *(long *)k_persist_stack_chk_guard_slot;
  type_id_11 = 0xad001;
  unique0x1000053e = (mach_msg_id_t *)coruna_u64_pack((cache_60), (cache_59));
  if ((arg == 0) ||
     ((n == (mach_msg_id_t *)0x0 &&
      (unique0x10000546 = (mach_msg_id_t *)coruna_u64_pack((cache_60), (cache_59)), m != 0))))
  if (*(long *)k_persist_stack_chk_guard_slot != block_ctx) {
  ___stack_chk_fail();
  }
  return type_id_11;
  j = (int)val;
  _bzero(&cache_56,0x800);
  lpm4 = (mach_msg_id_t *)coruna_u64_pack((cache_60), (cache_59));
  lpm3 = (mach_msg_id_t *)coruna_u64_pack((cache_60), (cache_59));
  if (((val & 0xfffffff7) != 0) && (p + 1 < 2)) {
exit_ok:
    val = 0;
    type_id_10 = 0;
    type_id_11 = 0x1e020;
    unique0x10000516 = lpm3;
    break;
  }
  type_id_10 = val;
  type_id_11 = val;
  unique0x1000051e = (mach_msg_id_t *)coruna_u64_pack((cache_60), (cache_59));
  switch(val & 0xffffffff) {
  case 0:
    break;
  case 1:
  case 2:
    val = 0;
    type_id_10 = 0;
    type_id_11 = 0x1e020;
    unique0x10000516 = lpm3;
    break;
    type_id_10 = 0;
    val = 0;
    type_id_11 = 0xad001;
    unique0x10000536 = lpm4;
    break;
    block_ctx = (uint8_t)n[5];
    cache_63 = n[4];
    unique0x00048400 = *(mach_msg_id_t **)n;
    cache_59 = p;
    cache_61 = (mach_msg_size_t)*(uint64_t *)(n + 2);
    cache_62 = (mach_msg_id_t)((unsigned long)*(uint64_t *)(n + 2) >> 0x20);
    stack_guard = 0;
    ctx_val = *(long *)(arg + 0x18);
    kind = *(uint64_t *)(arg + 0x20);
    u = 0x4000000e;
    if (j != 1) {
      u = 0x40000012;
    }
    copy = *(void (**)(ctx_val + 0x28);
load_ok:
    type_id_11 = (*copy)(ctx_val,kind,u,cache_59);
    (**(void (**)(*(long *)(arg + 0x18) + 0x28))
              (*(long *)(arg + 0x18),*(uint64_t *)(arg + 0x20),0xc,p);
load_ok_15:
    type_id_10 = 0;
    val = 0;
    break;
  case 3:
  case 4:
    if ((m < 5) ||
       (unique0x00023700 = n + 1,
       val = 0;
       type_id_10 = 0;
       type_id_11 = 0x1e020;
       unique0x10000516 = lpm3;
       break;
    if (1 < p + 1) {
      lm2 = *n;
      cache_59 = p;
      ls5 = _strlen((char *)unique0x00023700);
      cache_61 = (mach_msg_size_t)ls5;
      ctx_val = *(long *)(arg + 0x18);
      kind = *(uint64_t *)(arg + 0x20);
      copy = *(void (**)(ctx_val + 0x28);
      u = 0x40000011;
      cache_62 = lm2;
      if (j != 3) {
        u = 0x40000010;
      }
      type_id_11 = (*copy)(ctx_val,kind,u,cache_59);
      (**(void (**)(*(long *)(arg + 0x18) + 0x28))
      (*(long *)(arg + 0x18),*(uint64_t *)(arg + 0x20),0xc,p);
      type_id_10 = 0;
      val = 0;
      break;
    }
    type_id_10 = 0;
    val = 0;
    type_id_11 = 0xad001;
    unique0x10000536 = lpm4;
    break;
  case 5:
    val = 0;
    type_id_10 = 0;
    type_id_11 = 0x1e020;
    unique0x10000516 = lpm3;
    break;
    if (1 < p + 1) {
      ctx_val = *(long *)(arg + 0x18);
      kind = *(uint64_t *)(arg + 0x20);
      copy = *(void (**)(ctx_val + 0x28);
      copy = (uint8_t *)(unsigned long)p;
      type_id_8 = 0xc;
load_ok_16:
      type_id_11 = (*copy)(ctx_val,kind,type_id_8,copy);
      type_id_10 = 0;
      val = 0;
      break;
    }
    type_id_10 = 0;
    val = 0;
    type_id_11 = 0xad001;
    unique0x10000536 = lpm4;
    break;
  case 6:
    val = 0;
    type_id_10 = 0;
    type_id_11 = 0x1e020;
    unique0x10000516 = lpm3;
    break;
    if (1 < p + 1) {
      ctx_val = *(long *)(arg + 0x18);
      kind = *(uint64_t *)(arg + 0x20);
      copy = *(void (**)(ctx_val + 0x28);
      copy = (uint8_t *)(unsigned long)p;
      type_id_8 = 0x16;
      type_id_11 = (*copy)(ctx_val,kind,type_id_8,copy);
      type_id_10 = 0;
      val = 0;
      break;
    }
    type_id_10 = 0;
    val = 0;
    type_id_11 = 0xad001;
    unique0x10000536 = lpm4;
    break;
  case 7:
    val = 0;
    type_id_10 = 0;
    type_id_11 = 0x1e020;
    unique0x10000516 = lpm3;
    break;
    if (1 < p + 1) {
      ctx_val = *(long *)(arg + 0x18);
      kind = *(uint64_t *)(arg + 0x20);
      copy = *(void (**)(ctx_val + 0x28);
      copy = (uint8_t *)(unsigned long)p;
      type_id_8 = 0x1a;
      type_id_11 = (*copy)(ctx_val,kind,type_id_8,copy);
      type_id_10 = 0;
      val = 0;
      break;
    }
    type_id_10 = 0;
    val = 0;
    type_id_11 = 0xad001;
    unique0x10000536 = lpm4;
    break;
  case 8:
    val = 0;
    type_id_10 = 0;
    type_id_11 = 0x1e020;
    unique0x10000516 = lpm3;
    break;
    cache_59 = 0;
    cache_59 = p;
    type_id_11 = (**(void (**)(*(long *)(arg + 0x18) + 0x28))
                       (*(long *)(arg + 0x18),*(uint64_t *)(arg + 0x20),0xc0000020,
                        cache_59);
    val = 0;
    type_id_13 = cache_59;
    if ((int)type_id_11 != 0) {
      type_id_13 = 0;
    }
    type_id_10 = (unsigned long)type_id_13;
    break;
  case 9:
    val = 0;
    type_id_10 = 0;
    type_id_11 = 0x1e020;
    unique0x10000516 = lpm3;
    break;
    if (1 < p + 1) {
      block_ctx = (uint8_t)n[5];
      cache_63 = n[4];
      cache_59 = p;
      cache_59 = (uint32_t)*(uint64_t *)n;
      cache_60 = (mach_port_t)((unsigned long)*(uint64_t *)n >> 0x20);
      cache_61 = (mach_msg_size_t)*(uint64_t *)(n + 2);
      cache_62 = (mach_msg_id_t)((unsigned long)*(uint64_t *)(n + 2) >> 0x20);
      stack_guard = 0;
      ctx_val = *(long *)(arg + 0x18);
      kind = *(uint64_t *)(arg + 0x20);
      type_id_8 = 0x40000021;
      copy = *(void (**)(ctx_val + 0x28);
      copy = cache_59;
      type_id_11 = (*copy)(ctx_val,kind,type_id_8,copy);
      type_id_10 = 0;
      val = 0;
      break;
    }
parse_ok:
    type_id_10 = 0;
    val = 0;
    type_id_11 = 0xad001;
    unique0x10000536 = lpm4;
    break;
  case 10:
  case 0xb:
    val = 0;
    type_id_10 = 0;
    type_id_11 = 0x1e020;
    unique0x10000516 = lpm3;
    break;
    type_id_10 = 0;
    val = 0;
    type_id_11 = 0xad001;
    unique0x10000536 = lpm4;
    break;
    cache_59 = p;
    cache_59 = (uint32_t)*(uint64_t *)n;
    cache_60 = (mach_port_t)((unsigned long)*(uint64_t *)n >> 0x20);
    cache_61 = (mach_msg_size_t)*(uint64_t *)(n + 2);
    cache_62 = (mach_msg_id_t)((unsigned long)*(uint64_t *)(n + 2) >> 0x20);
    cache_63 = coruna_cat(cache_63._1_3_,(char)n[4]);
    path_buf = 0;
    tmp_buf = 0;
    region = 0;
    block_ctx = 0;
    stack_guard = 0;
    sa_saved = 0;
    sa_new = 0;
    u = 0xc0000023;
    if (j != 10) {
      u = 0x40000023;
    }
    type_id_11 = (**(void (**)(*(long *)(arg + 0x18) + 0x28))
                       (*(long *)(arg + 0x18),*(uint64_t *)(arg + 0x20),u,cache_59);
    type_id_10 = 0;
    cache_57 = (mach_msg_id_t *)coruna_u64_pack((cache_60), (cache_59));
    cache_56 = cache_59;
    serial_buf = coruna_cat(sa_saved,coruna_cat(stack_guard,coruna_u64_pack14((block_ctx), (cache_63))));
    host_info = coruna_u64_pack((cache_62), (cache_61));
    action = coruna_u64_pack((cache_64), (region));
    cache_58 = coruna_cat(tmp_buf,coruna_cat(path_buf,sa_new));
    type_id_13 = 0x30;
    if ((int)type_id_11 != 0) {
      type_id_13 = 0;
    }
    val = (unsigned long)type_id_13;
    unique0x1000052e = cache_57;
    break;
  default:
    type_id_10 = 0;
    val = 0;
    type_id_11 = 0x1e026;
    unique0x10000526 = (mach_msg_id_t *)coruna_u64_pack((cache_60), (cache_59));
  }
switchD_0000ed84_caseD_0:
  if (1 < q + 1) {
    cache_55 = 0;
    cache_28 = 0;
    cache_78 = 0;
    cache_30 = 0;
    cache_29 = 0;
    cache_27 = 0;
    cache_77 = 0;
    cache_26 = 0;
    cache_76 = 0;
    cache_25 = 0;
    cache_75 = 0;
    cache_24 = 0;
    cache_74 = 0;
    cache_23 = 0;
    cache_73 = 0;
    cache_22 = 0;
    sa_new = 0;
    cache_21 = 0;
    cache_72 = 0;
    cache_20 = 0;
    cache_71 = 0;
    cache = 0;
    cache_70 = 0;
    work = 0;
    cache_69 = 0;
    frame = 0;
    cache_68 = 0;
    json_buf = 0;
    cache_67 = 0;
    url_buf = 0;
    cache_66 = 0;
    plist = 0;
    cache_65 = 0;
    path_buf = 0;
    tmp_buf = 0;
    region = 0;
    block_ctx = 0;
    stack_guard = 0;
    sa_saved = 0;
    sa_new = 0;
    cache_63 = 0;
    cache_60 = 0;
    cache_61 = 0;
    cache_59 = k_persist_rodata_word_1ed10;
    cache_62 = -5;
    cache_64 = (uint32_t)type_id_11;
    cache_59 = q;
    if ((int)val != 0) {
      cache_65 = (int)val;
      ___memcpy_chk(&plist,&cache_56,val & 0xffffffff,0x100);
    }
    if (1 < (int)type_id_10 + 1U) {
      cache_59 = cache_59 | 0x80000000;
      cache_63 = 1;
      block_ctx = (uint8_t)type_id_10;
      stack_guard = (uint8_t)(type_id_10 >> 8);
      sa_saved = (uint16_t)(type_id_10 >> 0x10);
      tmp_buf = 0x13;
    }
    _mach_msg((mach_msg_header_t *)cache_59,0x11,0x134,0,0,0,0);
  }
again:
  if (*(long *)k_persist_stack_chk_guard_slot != block_ctx) {
    ___stack_chk_fail();
  }
  return type_id_11;
}





unsigned long coruna_mach_port_deallocate_1adbc(mach_port_name_t *arg)

{
  uint8_t *data;
  kern_return_t lk2;
  uint version;
  unsigned long type_id;
  uint port;
  
  if (arg == (mach_port_name_t *)0x0) {
    type_id = 0xad001;
  }
  else {
    type_id = coruna_pthread_join();
    data = k_persist_mach_task_self_slot;
    if (1 < *arg + 1) {
      lk2 = _mach_port_deallocate(*(ipc_space_t *)k_persist_mach_task_self_slot,*arg);
      port = (uint)type_id;
      version = 0x1e024;
      if (port != 0) {
        version = port;
      }
      if (lk2 != 0) {
        port = version;
      }
      lk2 = _mach_port_mod_refs(*(ipc_space_t *)data,*arg,1,-1);
      version = 0x1e024;
      if (port != 0) {
        version = port;
      }
      if (lk2 != 0) {
        port = version;
      }
      type_id = (unsigned long)port;
    }
    if ((*(long *)(arg + 6) != 0) && (*(long *)(arg + 8) != 0)) {
      version = (**(void (**)(*(long *)(arg + 6) + 0x20))();
      if ((uint)type_id != 0) {
        version = (uint)type_id;
      }
      type_id = (unsigned long)version;
    }
    arg[6] = 0;
    arg[7] = 0;
    arg[4] = 0;
    arg[5] = 0;
    arg[10] = 0;
    arg[0xb] = 0;
    arg[8] = 0;
    arg[9] = 0;
    arg[2] = 0;
    arg[3] = 0;
    arg[0] = 0;
    arg[1] = 0;
    _free(arg);
  }
  return type_id;
}





uint64_t coruna_pthread_join(long handle)
{
  int err;
  uint64_t u;
  void *scratch;
  
  if (handle == 0) {
    u = 0xad001;
  }
  else if (*(char *)(handle + 8) == '\0') {
    u = 0;
  }
  else {
    *(uint8_t *)(handle + 9) = 1;
    if (*(long *)(handle + 0x18) != 0) {
      coruna_mach_msg_destroy_1b0cc(handle);
      scratch = (void *)0x0;
      err = _pthread_join(*(pthread_t *)(handle + 0x10),&scratch);
      if (err == 0) {
        coruna_mach_msg_destroy_1b0cc(handle);
      }
      else {
        ___error();
      }
      *(uint64_t *)(handle + 0x10) = 0;
    }
    u = 0;
    *(uint8_t *)(handle + 8) = 0;
  }
  return u;
}





unsigned long coruna_mach_port_set_attributes_1af18(uint64_t *arg,long val)

{
  uint8_t *data;
  mach_port_name_t name;
  uint size;
  kern_return_t lk3;
  mach_port_name_t lm4;
  int count;
  mach_port_name_t *lpm6;
  unsigned long kind;
  uint64_t cache_79;
  mach_port_name_t cache_80 [2];
  
  if (arg == (uint64_t *)0x0) {
    return 0xad001;
  }
  lpm6 = _calloc(1,0x30);
  if (lpm6 == (mach_port_name_t *)0x0) {
    return 0xad009;
  }
  cache_79 = 0;
  if (val == 0) {
    kind = 0;
    *arg = lpm6;
  }
  else {
    kind = (**(void (**)(val + 0x18))(val,0,&cache_79);
    data = k_persist_mach_task_self_slot;
    if ((int)kind == 0) {
      cache_80[0] = 0;
      size = _mach_port_allocate(*(ipc_space_t *)k_persist_mach_task_self_slot,1,cache_80);
      name = cache_80[0];
      if (size == 0) {
        cache_80[0] = 1;
        lk3 = _mach_port_set_attributes
                          (*(ipc_space_t *)data,name,1,(mach_port_info_t)cache_80,1);
        if ((lk3 == 0) &&
           (lk3 = _mach_port_insert_right(*(ipc_space_t *)data,name,name,0x14), lk3 == 0)) {
          *lpm6 = name;
          lm4 = coruna_srandomdev();
          lpm6[1] = lm4;
          *(uint16_t *)(lpm6 + 2) = 0x100;
          lpm6[4] = 0;
          lpm6[5] = 0;
          *(long *)(lpm6 + 6) = val;
          *(uint64_t *)(lpm6 + 8) = cache_79;
          count = coruna_mach_msg_destroy_1b0cc(lpm6);
          if (count == 0) {
            kind = 0;
            *arg = lpm6;
          }
          else {
          _mach_port_mod_refs(*(ipc_space_t *)data,name,0,-1);
          }
        }
        _mach_port_destroy(*(ipc_space_t *)data,name);
        size = 0x1e023;
      }
      else {
        size = size | 0x80000000;
      }
      kind = (unsigned long)size;
      (**(void (**)(val + 0x20))(val,cache_79);
    }
    _free(lpm6);
  }
  return kind;
}





uint coruna_srandomdev(void)
{
  uint u;
  unsigned long size;
  
  _srandomdev();
  size = _random();
  u = (uint)size;
  if ((size & 0x7fffffff) == 0) {
    size = _random();
    u = (int)k_persist_dlsym_slot << 0xe ^ 0x3cb9;
    if ((size & 0x7fffffff) != 0) {
      u = (uint)size;
    }
  }
  return u & 0x7fffffff;
}





uint32_t coruna_mach_msg_destroy_1b0cc(mach_port_t *port)
{
  mach_msg_return_t lm1;
  mach_msg_header_t scratch;
  
  if (port == (mach_port_t *)0x0) {
    return 0xad001;
  }
  if (*(long *)(port + 6) != 0) {
    scratch.msgh_local_port = 0;
    scratch.msgh_reserved = 0;
    scratch.msgh_remote_port = *port;
    scratch.msgh_id = port[1];
    scratch = k_persist_rodata_word_1ed28;
    lm1 = _mach_msg(&scratch,0x11,0x18,0,0,1,0);
    if (lm1 == 0) {
      return 0;
    }
    if (lm1 != 0x10000004) {
      return 0x1e025;
    }
    _mach_msg_destroy(&scratch);
  }
  return 0;
}





uint64_t coruna_pthread_create(uint32_t *size,uint32_t *flags_2,uint32_t *version_3)
{
  int err;
  uint64_t u;
  
  if (size == (uint32_t *)0x0) {
    u = 0xad001;
  }
  else if (((*(char *)(size + 2) == '\0') &&
           (*(uint16_t *)(size + 2) = 1, *(long *)(size + 6) != 0)) &&
          (err = _pthread_create((pthread_t *)(size + 4),(pthread_attr_t *)0x0,
                                   (void **)coruna_mach_msg_1b208,size), err != 0)) {
    ___error();
    *(uint8_t *)(size + 2) = 0;
    *(uint64_t *)(size + 4) = 0;
    u = 0x1e01f;
  }
  else {
    if (flags_2 != (uint32_t *)0x0) {
      *flags_2 = *size;
    }
    u = 0;
    if (version_3 != (uint32_t *)0x0) {
      *version_3 = size[1];
    }
  }
  return u;
}





uint64_t coruna_mach_msg_1b208(mach_port_name_t *arg)
{
  size_t ls1;
  mach_port_name_t rcv_name;
  mach_msg_return_t lm2;
  int err;
  mach_msg_header_t *msg;
  mach_msg_header_t *msg_00;
  
  if ((arg != (mach_port_name_t *)0x0) &&
     (msg = _calloc(1,0x13c), msg != (mach_msg_header_t *)0x0)) {
    do {
      while( true ) {
        if ((*(char *)((long)arg + 9) != '\0') || (rcv_name = *arg, rcv_name + 1 < 2))
        goto fail;
        msg[0xb].msgh_reserved = 0;
        msg[0xb].msgh_id = 0;
        msg[0xb].msgh_remote_port = 0;
        msg[0xb].msgh_local_port = 0;
        msg[0xc].msgh_remote_port = 0;
        msg[0xc].msgh_local_port = 0;
        msg[0xc].msgh_bits = 0;
        msg[0xc].msgh_size = 0;
        msg[10].msgh_remote_port = 0;
        msg[10].msgh_local_port = 0;
        msg[10].msgh_bits = 0;
        msg[10].msgh_size = 0;
        msg[0xb].msgh_bits = 0;
        msg[0xb].msgh_size = 0;
        msg[10].msgh_reserved = 0;
        msg[10].msgh_id = 0;
        msg[9].msgh_bits = 0;
        msg[9].msgh_size = 0;
        msg[8].msgh_reserved = 0;
        msg[8].msgh_id = 0;
        msg[9].msgh_reserved = 0;
        msg[9].msgh_id = 0;
        msg[9].msgh_remote_port = 0;
        msg[9].msgh_local_port = 0;
        msg[7].msgh_reserved = 0;
        msg[7].msgh_id = 0;
        msg[7].msgh_remote_port = 0;
        msg[7].msgh_local_port = 0;
        msg[8].msgh_remote_port = 0;
        msg[8].msgh_local_port = 0;
        msg[8].msgh_bits = 0;
        msg[8].msgh_size = 0;
        msg[6].msgh_remote_port = 0;
        msg[6].msgh_local_port = 0;
        msg[6].msgh_bits = 0;
        msg[6].msgh_size = 0;
        msg[7].msgh_bits = 0;
        msg[7].msgh_size = 0;
        msg[6].msgh_reserved = 0;
        msg[6].msgh_id = 0;
        msg[5].msgh_bits = 0;
        msg[5].msgh_size = 0;
        msg[4].msgh_reserved = 0;
        msg[4].msgh_id = 0;
        msg[5].msgh_reserved = 0;
        msg[5].msgh_id = 0;
        msg[5].msgh_remote_port = 0;
        msg[5].msgh_local_port = 0;
        msg[3].msgh_reserved = 0;
        msg[3].msgh_id = 0;
        msg[3].msgh_remote_port = 0;
        msg[3].msgh_local_port = 0;
        msg[4].msgh_remote_port = 0;
        msg[4].msgh_local_port = 0;
        msg[4].msgh_bits = 0;
        msg[4].msgh_size = 0;
        msg[2].msgh_remote_port = 0;
        msg[2].msgh_local_port = 0;
        msg[2].msgh_bits = 0;
        msg[2].msgh_size = 0;
        msg[3].msgh_bits = 0;
        msg[3].msgh_size = 0;
        msg[2].msgh_reserved = 0;
        msg[2].msgh_id = 0;
        msg[1].msgh_bits = 0;
        msg[1].msgh_size = 0;
        msg->msgh_reserved = 0;
        msg->msgh_id = 0;
        msg[1].msgh_reserved = 0;
        msg[1].msgh_id = 0;
        msg[1].msgh_remote_port = 0;
        msg[1].msgh_local_port = 0;
        msg->msgh_remote_port = 0;
        msg->msgh_local_port = 0;
        msg->msgh_bits = 0;
        msg->msgh_size = 0;
        *(uint64_t *)&msg[0xc].msgh_id = 0;
        msg[0xc].msgh_local_port = 0;
        msg[0xc].msgh_reserved = 0;
        lm2 = _mach_msg(msg,0x106,0,0x13c,rcv_name,10000,0);
        if (lm2 == 0x10004004) break;
        if (lm2 == 0) {
          coruna_mach_port_get_refs(arg,msg,0x13c);
          lm2 = 0;
        }
done:
        err = coruna_mach_msg_destroy_1b580(lm2,msg,0x13c);
        if (err != 0) goto fail;
      }
      if (0x1fffe8 < msg->msgh_size - 0x18) {
        lm2 = _mach_msg(msg,2,0,0x13c,*arg,0,0);
        goto done;
      }
      ls1 = (unsigned long)msg->msgh_size + 8;
      msg_00 = _calloc(1,ls1);
      if (msg_00 == (mach_msg_header_t *)0x0) break;
      lm2 = _mach_msg(msg_00,2,0,(mach_msg_size_t)ls1,*arg,0,0);
      if (lm2 == 0) {
        coruna_mach_port_get_refs(arg,msg_00,ls1);
        lm2 = 0;
      }
      err = coruna_mach_msg_destroy_1b580(lm2,msg_00,ls1);
      _free(msg_00);
    } while (err == 0);
fail:
    _free(msg);
  }
  return 0;
}





void coruna_mach_port_get_refs(long handle,int *flags,uint size)
{
  long handle;
  uint u;
  int err;
  uint size;
  mach_port_urefs_t lm5;
  kern_return_t lk6;
  mach_port_urefs_t lm7;
  int status;
  uint version;
  mach_port_urefs_t *lpm10;
  mach_port_urefs_t scratch;
  uint bootargs;
  
  if (((handle != 0) && (flags != (int *)0x0)) && (0x17 < size)) {
    err = flags[5];
    size = *(uint *)(handle + 4);
    if ((unsigned long)size <= (unsigned long)(long)err && (unsigned long)(long)err < (unsigned long)size + 0xc) {
      u = flags[1];
      version = 0x18;
      if (*flags < 0) {
        version = 0x2c;
      }
      if (version <= u && u < size) {
        if (*flags < 0) {
          if (flags[6] != 1) {
            return;
          }
          lpm10 = *(mach_port_urefs_t **)(flags + 7);
          if ((uint)flags[9] >> 0x18 == 0) {
            if ((mach_port_name_t)lpm10 + 1 < 2) {
              return;
            }
            scratch = 0;
            lk6 = _mach_port_get_refs(*(ipc_space_t *)k_persist_mach_task_self_slot,
                                        (mach_port_name_t)lpm10,0,&scratch);
            if (lk6 != 0) {
              return;
            }
            if (scratch == 0) {
              return;
            }
          }
          else {
            if ((uint)flags[9] >> 0x18 != 1) {
              return;
            }
            if (lpm10 == (mach_port_urefs_t *)0x0) {
              return;
            }
            if (flags[10] != 4) {
              return;
            }
            lm5 = *lpm10;
            lm7 = _getpid();
            if (lm5 == lm7) {
              lpm10 = (mach_port_urefs_t *)(unsigned long)*(uint *)k_persist_mach_task_self_slot;
            }
            else {
              if ((*(mach_port_urefs_t *)(handle + 0x28) == lm5) &&
                 (1 < *(mach_port_name_t *)(handle + 0x2c) + 1)) {
                scratch = 0;
                lk6 = _mach_port_get_refs(*(ipc_space_t *)k_persist_mach_task_self_slot,
                                            *(mach_port_name_t *)(handle + 0x2c),0,&scratch);
                lpm10 = (mach_port_urefs_t *)0x0;
                status = 0x1e020;
                if ((lk6 == 0) && (scratch != 0)) {
                  status = 0;
                  lpm10 = (mach_port_urefs_t *)(unsigned long)*(uint *)(handle + 0x2c);
                }
              }
              else {
                bootargs = 0;
                scratch = lm5;
                status = (**(void (**)(*(long *)(handle + 0x18) + 0x28))
                                  (*(long *)(handle + 0x18),*(uint64_t *)(handle + 0x20),
                                   0xc000001d,&scratch);
                lpm10 = (mach_port_urefs_t *)0x0;
                if (status == 0) {
                  lpm10 = (mach_port_urefs_t *)(unsigned long)bootargs;
                  *(mach_port_urefs_t *)(handle + 0x28) = lm5;
                  *(uint *)(handle + 0x2c) = bootargs;
                }
              }
              if (status != 0) {
                return;
              }
            }
          }
        }
        else {
          lpm10 = (mach_port_urefs_t *)0x0;
        }
        handle = 0;
        if (u - version != 0) {
          handle = (long)flags + (unsigned long)version;
        }
        coruna_mach_msg(handle,err - size,handle,u - version,lpm10,flags[2]);
      }
    }
  }
  return;
}





uint64_t coruna_mach_msg_destroy_1b580(int flags,mach_msg_header_t *arg,uint size)
{
  uint u;
  uint size;
  uint64_t version;
  
  if (arg == (mach_msg_header_t *)0x0) {
    return 0xad001;
  }
  if (size == 0) {
    return 0xad001;
  }
  u = flags + 0xefffbffe;
  if (u < 0xb) {
    size = 1 << (unsigned long)(u & 0x1f);
    if ((size & 0x22e) == 0) {
      if ((size & 0x91) != 0) {
        version = 0x1e01b;
        _bzero(arg,(unsigned long)size);
        return version;
      }
      if (flags != 0) {
      version = 0x1e021;
      _bzero(arg,(unsigned long)size);
      return version;
      }
      goto cleanup;
    }
  }
  else {
done:
    if (flags != 0) {
      version = 0x1e021;
      _bzero(arg,(unsigned long)size);
      return version;
    }
cleanup:
    arg->msgh_remote_port = 0;
    _mach_msg_destroy(arg);
  }
  version = 0;
fail:
  _bzero(arg,(unsigned long)size);
  return version;
}





uint coruna_task_get_exc_guard_behavior(uint64_t val)
{
  uint u;
  uint size;
  uint scratch;
  
  u = 0xad001;
  if ((1 < (int)val + 1U) &&
     (u = 0,
     k_persist_task_get_exc_guard_behavior_slot != (uint8_t *)0x0 &&
     k_persist_task_set_exc_guard_behavior_slot != (uint8_t *)0x0)) {
    scratch = 0;
    u = _task_get_exc_guard_behavior(val,&scratch);
    if (u == 0) {
      if ((scratch & 0x88) == 0) {
        u = 0;
      }
      else {
        scratch = scratch & 0xffffff77;
        size = _task_set_exc_guard_behavior(val);
        u = 0;
        if (size != 0) {
          u = size | 0x80000000;
        }
      }
    }
    else {
      u = u | 0x80000000;
    }
  }
  return u;
}





uint32_t coruna_mach_port_kernel_object(uint64_t val)
{
  mach_port_name_t name;
  bool err;
  ipc_space_t task;
  kern_return_t lk2;
  long handle;
  mach_msg_type_number_t lm4;
  uint32_t u;
  int err;
  uint size;
  unsigned long version;
  uint scratch;
  uint bootargs;
  mach_msg_type_number_t thread_attr;
  ipc_info_tree_name_array_t host_info;
  mach_msg_type_number_t serial_buf;
  ipc_info_name_array_t action;
  ipc_info_space_t block_ctx;
  uint64_t stack_guard;
  uint64_t sa_saved;
  uint64_t sa_new;
  kern_return_t path_buf;
  
  u = 0xad025;
  task = (ipc_space_t)val;
  if (task + 1 < 2) {
    u = 0xad001;
  }
  else {
    path_buf = 5;
    stack_guard = 0;
    sa_saved = 0;
    sa_new = 0;
    err = 0x19;
    do {
      handle = __dyld_process_info_create(val,0,&path_buf);
      if (handle != 0) {
        sa_saved = 0;
        stack_guard = 0;
        sa_new = 0xff;
        __dyld_process_info_get_state(handle,&stack_guard);
        size = (uint)(byte)sa_new;
        if (size - 0x30 < 0x21) {
          __dyld_process_info_release(handle);
          return 0;
        }
        __dyld_process_info_release(handle);
        if (size == 0) {
          return 0xad025;
        }
        break;
      }
      _usleep(100000);
      err = err + -1;
    } while (err != 0);
    block_ctx.iis_genno_mask = 0;
    block_ctx.iis_table_size = 0;
    block_ctx.iis_table_next = 0;
    block_ctx.iis_tree_size = 0;
    block_ctx.iis_tree_small = 0;
    block_ctx.iis_tree_hash = 0;
    action = (ipc_info_name_array_t)0x0;
    serial_buf = 0;
    host_info = (ipc_info_tree_name_array_t)0x0;
    thread_attr = 0;
    lk2 = _mach_port_space_info(task,&block_ctx,&action,&serial_buf,&host_info,&thread_attr);
    if (lk2 == 0) {
      path_buf = 0;
      if (serial_buf != 0) {
        handle = 0;
        err = false;
        version = 1;
        lm4 = serial_buf;
        do {
          scratch = 0;
          bootargs = 0;
          name = *(mach_port_name_t *)((long)&action->iin_name + handle);
          if (1 < name + 1) {
            path_buf = _mach_port_kernel_object(task,name,&bootargs,&scratch);
            err = (bool)((path_buf == 0 && bootargs == 0x19) | err);
            lm4 = serial_buf;
          }
          if (lm4 <= version) break;
          version = version + 1;
          handle = handle + 0x1c;
        } while (!err);
        u = 0;
        if (!err) {
          u = 0xad025;
        }
        if ((action != (ipc_info_name_array_t)0x0) && (lm4 != 0)) {
          _mach_vm_deallocate(*(vm_map_t *)k_persist_mach_task_self_slot,(mach_vm_address_t)action
                              ,(unsigned long)lm4 * 0x1c);
        }
      }
      if ((host_info != (ipc_info_tree_name_array_t)0x0) && (thread_attr != 0)) {
        _mach_vm_deallocate(*(vm_map_t *)k_persist_mach_task_self_slot,(mach_vm_address_t)host_info,
                            (unsigned long)thread_attr * 0x24);
      }
    }
  }
  return u;
}





uint64_t
void coruna_mach_vm_allocate(uint64_t val,mach_vm_size_t arg,int flags,mach_vm_address_t *arg_x)
{
  vm_map_t target;
  kern_return_t lk1;
  uint64_t u;
  mach_vm_address_t scratch;
  
  u = 0xad001;
  if ((arg_x != (mach_vm_address_t *)0x0) && (arg != 0)) {
    u = 0x1e009;
    target = (vm_map_t)val;
    if (1 < target + 1) {
      scratch = 0;
      lk1 = _mach_vm_allocate(target,&scratch,arg,flags);
      if (lk1 == 0) {
        lk1 = _mach_vm_protect(target,scratch,arg,0,3);
        if (lk1 == 0) {
          u = 0;
          *arg_x = scratch;
        }
        else {
          coruna_mach_vm_deallocate_1b998(val,scratch,arg,0);
          u = 0x1e00d;
        }
      }
      else {
        u = 0x1e00a;
      }
    }
  }
  return u;
}





uint32_t coruna_mach_vm_deallocate_1b998(uint64_t val,mach_vm_address_t arg,unsigned long arg_x,int flags)
{
  kern_return_t lk1;
  uint32_t u;
  
  if ((arg == 0) && ((int)arg_x != 0)) {
    u = 0xad001;
  }
  else {
    u = 0x1e009;
    if ((1 < (vm_map_t)val + 1) && (u = 0, (int)arg_x != 0)) {
      if (flags != 0) {
        coruna_mach_vm_write(val,arg,arg_x);
      }
      lk1 = _mach_vm_deallocate((vm_map_t)val,arg,arg_x & 0xffffffff);
      u = 0;
      if (lk1 != 0) {
        u = 0x1e00b;
      }
    }
  }
  return u;
}





uint64_t coruna_sysctlnametomib(mach_port_name_t arg,uint32_t *size,uint *size_x)
{
  kern_return_t lk1;
  int err;
  uint u;
  uint64_t *ptr;
  uint64_t size;
  size_t scratch;
  size_t bootargs;
  uint64_t thread_attr;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t serial_buf;
  int action [14];
  long block_ctx;
  
  block_ctx = *(long *)k_persist_stack_chk_guard_slot;
  serial_buf = 0;
  if (arg + 1 < 2 || size == (uint32_t *)0x0) {
    size = 0xad001;
  }
  else {
    size = 0x1e002;
    lk1 = _pid_for_task(arg,(int *)((long)&serial_buf + 4));
    if (lk1 == 0) {
      host_info = 0;
      scratch = 0;
      thread_attr = 0;
      thread_attr = 0;
      bootargs = 0;
      err = _proc_pidinfo(serial_buf,0x13,0,&thread_attr,8);
      if (err == 8) {
        ptr = &thread_attr;
        u = thread_attr & 0xffffff;
      }
      else {
        action[6] = 0;
        action[7] = 0;
        action[4] = 0;
        action[5] = 0;
        action[10] = 0;
        action[0xb] = 0;
        action[8] = 0;
        action[9] = 0;
        action[2] = 0;
        action[3] = 0;
        action[0] = 0;
        action[1] = 0;
        bootargs = 0xc;
        err = _sysctlnametomib("sysctl.proc_cputype",action,&bootargs);
        if (*(long *)k_persist_stack_chk_guard_slot == block_ctx) {
        return size;
        }
        ___stack_chk_fail();
        action[bootargs] = serial_buf;
        bootargs = bootargs + 1;
        scratch = 4;
        err = _sysctl(action,(u_int)bootargs,&serial_buf,&scratch,(void *)0x0,0);
        if (*(long *)k_persist_stack_chk_guard_slot == block_ctx) {
        return size;
        }
        ___stack_chk_fail();
        u = 0;
        ptr = &serial_buf;
      }
      *size = *(uint32_t *)ptr;
      size = 0;
      if (size_x != (uint *)0x0) {
        *size_x = u;
      }
    }
  }
fail:
  if (*(long *)k_persist_stack_chk_guard_slot == block_ctx) {
    return size;
  }
  ___stack_chk_fail();
}





uint64_t coruna_mach_vm_read_overwrite_1bb8c(uint64_t val,long *handle,uint64_t id_2)
{
  bool err;
  task_name_t target_task;
  long handle;
  uint64_t u;
  long addr;
  bool status;
  mach_vm_size_t scratch;
  mach_msg_type_number_t bootargs;
  mach_vm_address_t thread_attr [2];
  uint32_t host_info;
  kern_return_t serial_buf;
  uint64_t action;
  uint64_t scratch;
  long block_ctx;
  uint64_t stack_guard;
  uint64_t sa_saved;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t sa_new;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t block_ctx;
  uint64_t path_buf;
  uint64_t stack_guard;
  uint64_t tmp_buf;
  uint64_t sa_saved;
  uint64_t sa_new;
  uint64_t path_buf;
  uint64_t region;
  uint64_t tmp_buf;
  uint64_t region;
  uint64_t plist;
  long plist;
  uint64_t url_buf;
  uint64_t json_buf;
  uint64_t frame;
  uint64_t url_buf;
  uint64_t work;
  uint64_t cache;
  uint64_t cache_20;
  uint64_t json_buf;
  uint64_t cache_21;
  uint64_t cache_22;
  uint64_t cache_23;
  uint64_t frame;
  uint64_t cache_24;
  uint64_t cache_25;
  uint64_t cache_26;
  uint64_t work;
  uint64_t cache_27;
  uint64_t cache_28;
  uint64_t cache_29;
  uint64_t cache;
  uint64_t cache_30;
  uint64_t cache_31;
  uint64_t cache_32;
  long cache_20;
  
  cache_20 = *(long *)k_persist_stack_chk_guard_slot;
  u = 0xad001;
  target_task = (task_name_t)val;
  if (*(long *)k_persist_stack_chk_guard_slot == cache_20) {
  return u;
  }
  ___stack_chk_fail();
  thread_attr[0] = 0;
  thread_attr[1] = 0;
  host_info = 0;
  bootargs = 5;
  serial_buf = _task_info(target_task,0x11,(task_info_t)thread_attr,&bootargs);
  if ((serial_buf == 0) && (thread_attr[0] != 0)) {
    cache_30 = 0;
    cache = 0;
    cache_32 = 0;
    cache_31 = 0;
    cache_27 = 0;
    work = 0;
    cache_29 = 0;
    cache_28 = 0;
    cache_24 = 0;
    frame = 0;
    cache_26 = 0;
    cache_25 = 0;
    cache_21 = 0;
    json_buf = 0;
    cache_23 = 0;
    cache_22 = 0;
    work = 0;
    url_buf = 0;
    cache_20 = 0;
    cache = 0;
    url_buf = 0;
    plist = 0;
    frame = 0;
    json_buf = 0;
    tmp_buf = 0;
    region = 0;
    plist = 0;
    region = 0;
    sa_saved = 0;
    tmp_buf = 0;
    path_buf = 0;
    sa_new = 0;
    stack_guard = 0;
    path_buf = 0;
    serial_buf = 0;
    sa_new = 0;
    block_ctx = 0;
    action = 0;
    bootargs = 0;
    sa_saved = 0;
    host_info = 0;
    thread_attr = 0;
    scratch = 0;
    action = 0;
    stack_guard = 0;
    block_ctx = 0;
    scratch = 0;
    serial_buf = _mach_vm_read_overwrite
                          (target_task,thread_attr[0],0x170,(mach_vm_address_t)&action,&scratch);
    handle = __dyld_process_info_create(val,0,&serial_buf);
    if (handle != 0) {
    scratch = 0;
    action = 0;
    stack_guard = 0;
    block_ctx = 0;
    __dyld_process_info_get_cache(handle,&action);
    status = block_ctx != 0 && (char)stack_guard == '\0';
    addr = block_ctx;
    if (block_ctx == 0 || (char)stack_guard != '\0') {
    addr = 0;
    }
    __dyld_process_info_release(handle);
    err = addr == 0;
    u = 0xad022;
    if (*(long *)k_persist_stack_chk_guard_slot == cache_20) {
    return u;
    }
    ___stack_chk_fail();
    status = false;
    }
    u = 0;
    *handle = addr;
    *(bool *)id_2 = status;
    if (*(long *)k_persist_stack_chk_guard_slot == cache_20) {
    return u;
    }
    ___stack_chk_fail();
    status = true;
    addr = plist;
cleanup:
    err = addr == 0;
    u = 0xad022;
    if (*(long *)k_persist_stack_chk_guard_slot == cache_20) {
    return u;
    }
    ___stack_chk_fail();
    status = false;
    }
    u = 0;
    *handle = addr;
    *(bool *)id_2 = status;
    fail:
    if (*(long *)k_persist_stack_chk_guard_slot == cache_20) {
    return u;
  }
  else {
done:
    handle = __dyld_process_info_create(val,0,&serial_buf);
    if (handle != 0) {
      scratch = 0;
      action = 0;
      stack_guard = 0;
      block_ctx = 0;
      __dyld_process_info_get_cache(handle,&action);
      status = block_ctx != 0 && (char)stack_guard == '\0';
      addr = block_ctx;
      if (block_ctx == 0 || (char)stack_guard != '\0') {
        addr = 0;
      }
      __dyld_process_info_release(handle);
      err = addr == 0;
      u = 0xad022;
      if (*(long *)k_persist_stack_chk_guard_slot == cache_20) {
      return u;
      }
      ___stack_chk_fail();
      status = false;
      }
      u = 0;
      *handle = addr;
      *(bool *)id_2 = status;
      fail:
      if (*(long *)k_persist_stack_chk_guard_slot == cache_20) {
      return u;
    }
    status = false;
    addr = 0;
    err = true;
check_ok:
    u = 0xad022;
    if (*(long *)k_persist_stack_chk_guard_slot == cache_20) {
    return u;
    }
    ___stack_chk_fail();
    status = false;
  }
  u = 0;
  *handle = addr;
  *(bool *)id_2 = status;
fail:
  if (*(long *)k_persist_stack_chk_guard_slot == cache_20) {
    return u;
  }
  ___stack_chk_fail();
}





uint64_t coruna_dladdr_1bd4c(uint64_t val,long handle,long *addr_2)
{
  int err;
  uint64_t u;
  long handle;
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  uint64_t *serial_buf;
  uint64_t *action;
  char *block_ctx;
  long stack_guard;
  uint64_t sa_saved;
  uint64_t scratch;
  uint64_t sa_new;
  uint64_t *path_buf;
  uint64_t tmp_buf;
  uint8_t region;
  uint64_t plist;
  uint64_t *url_buf;
  uint64_t json_buf;
  uint64_t frame;
  uint32_t work;
  char *cache;
  long cache_20;
  uint64_t bootargs;
  uint64_t thread_attr;
  
  u = 0xad001;
  if (((1 < (int)val + 1U) && (handle != 0)) && (addr_2 != (long *)0x0)) {
    cache_20 = 0;
    cache = (char *)0x0;
    thread_attr = 0;
    bootargs = 0;
    err = _dladdr(handle,&cache);
    if (err == 0) {
      u = 0xad00b;
    }
    else {
      u = 0xad014;
      if ((cache != (char *)0x0) && (*cache != '\0' && cache_20 != 0)) {
        work = 5;
        handle = __dyld_process_info_create(val,0,&work);
        u = 0xad00b;
        if (handle != 0) {
          action = &plist;
          plist = 0;
          json_buf = k_persist_rodata_word_1ecd8;
          frame = 0;
          serial_buf = &sa_new;
          sa_new = 0;
          tmp_buf = k_persist_rodata_word_1ecd8;
          region = 0;
          scratch = k_persist_nsconcretestackblock_slot;
          bootargs = k_persist_rodata_word_1ece0;
          thread_attr = coruna_wire_bind_sym;
          host_info = &k_persist_rodata_word_20430;
          stack_guard = cache_20;
          block_ctx = cache;
          scratch = thread_attr;
          sa_saved = bootargs;
          path_buf = serial_buf;
          url_buf = action;
          __dyld_process_info_for_each_image(handle,&scratch);
          u = 0xad011;
          if ((*(char *)(path_buf + 3) != '\0') && (url_buf[3] != 0)) {
            u = 0;
            *addr_2 = (url_buf[3] + handle) - cache_20;
          }
          __dyld_process_info_release(handle);
          __Block_object_dispose(&sa_new,8);
          __Block_object_dispose(&plist,8);
        }
      }
    }
  }
  return u;
}





void coruna_wire_bind_sym(long handle,uint64_t val,uint64_t id_2,char *path)
{
  int err;
  
  if (((*(char *)(*(long *)(*(long *)(handle + 0x20) + 8) + 0x18) == '\0' && path != (char *)0x0
       ) && (*path != '\0')) && (err = _strcmp(path,*(char **)(handle + 0x30)), err == 0)
     ) {
    *(uint64_t *)(*(long *)(*(long *)(handle + 0x28) + 8) + 0x18) = val;
    *(uint8_t *)(*(long *)(*(long *)(handle + 0x20) + 8) + 0x18) = 1;
  }
  return;
}





void coruna_block_assign_1bf3c(long handle,long addr_2)
{
  __Block_object_assign((void *)(handle + 0x20),*(void **)(addr_2 + 0x20),8);
  __Block_object_assign((void *)(handle + 0x28),*(void **)(addr_2 + 0x28),8);
  return;
}





void coruna_block_dispose_1bf78(long handle)
{
  __Block_object_dispose(*(void **)(handle + 0x28),8);
  __Block_object_dispose(*(void **)(handle + 0x20),8);
  return;
}





uint64_t coruna_task_info_1bfa8(task_name_t arg,long handle)
{
  kern_return_t lk1;
  uint64_t u;
  mach_msg_type_number_t scratch;
  long bootargs;
  unsigned long thread_attr;
  uint host_info;
  
  bootargs = 0;
  thread_attr = 0;
  host_info = 0;
  scratch = 5;
  if (handle == 0) {
    u = 0xad001;
  }
  else if (arg + 1 < 2) {
    u = 0x1e009;
  }
  else {
    lk1 = _task_info(arg,0x11,(task_info_t)&bootargs,&scratch);
    u = 0x1e002;
    if ((lk1 == 0) && (scratch == 5)) {
      if ((bootargs == 0) || (0xc800 < thread_attr)) {
        u = 0x1e001;
      }
      else {
        u = 0x1e001;
        if (host_info < 2) {
          u = 0;
          *(bool *)handle = host_info == 1;
          *(bool *)(handle + 1) = host_info == 1;
          *(long *)(handle + 8) = bootargs;
          *(unsigned long *)(handle + 0x10) = thread_attr;
        }
      }
    }
  }
  return u;
}





uint32_t coruna_mach_vm_write(vm_map_t arg,mach_vm_address_t arg_x,uint size)
{
  uint dataCnt;
  kern_return_t lk1;
  void *data;
  uint u;
  uint32_t size;
  int err;
  
  if ((((arg_x != 0) || (size = 0xad001, size == 0)) && (size = 0x1e009, 1 < arg + 1)) &&
     (size = 0, size != 0)) {
    u = size;
    if (0xfff < size) {
      u = 0x1000;
    }
    data = _calloc((unsigned long)size,1);
    if (data == (void *)0x0) {
      size = 0xad009;
    }
    else {
      err = 0;
      do {
        dataCnt = size;
        if (u <= size) {
          dataCnt = u;
        }
        lk1 = _mach_vm_write(arg,arg_x,(vm_offset_t)data,dataCnt);
        if (lk1 != 0) {
          err = lk1;
        }
        arg_x = arg_x + dataCnt;
        size = size - dataCnt;
      } while (size != 0);
      size = 0;
      if (err != 0) {
        size = 0x1e00f;
      }
      _free(data);
    }
  }
  return size;
}





uint64_t
void coruna_ctx_free_12e04(short *arg,long handle,vm_map_t arg_x,int flags,uint64_t val,
            unsigned long *arg_x_x,unsigned long arg,uint size)
{
  uint u;
  int err;
  kern_return_t lk3;
  uint32_t size;
  uint64_t version;
  unsigned long scratch;
  unsigned long scratch;
  unsigned long bootargs;
  unsigned long bootargs;
  unsigned long thread_attr;
  unsigned long thread_attr;
  unsigned long host_info;
  unsigned long host_info;
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
  uint64_t url_buf;
  uint64_t stack_guard;
  uint64_t json_buf;
  uint64_t frame;
  uint64_t work;
  uint64_t sa_saved;
  uint64_t cache;
  uint64_t cache_20;
  uint64_t cache_21;
  unsigned long sa_new;
  long path_buf;
  unsigned long cache_22;
  uint64_t cache_23;
  uint64_t tmp_buf;
  uint64_t region;
  uint8_t *plist;
  uint32_t url_buf;
  long json_buf;
  
  json_buf = *(long *)k_persist_stack_chk_guard_slot;
  version = 0xad00a;
  if (((arg != (short *)0x0) && (*arg == 2)) && (1 < (ushort)arg[1] && handle != 0)) {
    version = 0x1e011;
    if (arg_x + 1 < 2) {
      version = 0x1e009;
    }
    else if (flags + 1U < 2) {
      version = 0x1e014;
    }
    else {
      err = coruna_port_name_valid(arg_x_x,val);
      if (err == 0) {
        version = 0x1e010;
      }
      else if (((arg != 0) &&
               (((uint)(arg >> 0x20 != 0) & ((uint)val ^ 0xffffffff)) == 0)) &&
              (0x24f < size)) {
        path_buf = 0;
        sa_new = 0;
        cache_23 = 0;
        cache_22 = 0;
        cache = 0;
        sa_saved = 0;
        cache_21 = 0;
        cache_20 = 0;
        json_buf = 0;
        stack_guard = 0;
        work = 0;
        frame = 0;
        region = 0;
        block_ctx = 0;
        url_buf = 0;
        plist = 0;
        sa_new = 0;
        action = 0;
        tmp_buf = 0;
        path_buf = 0;
        block_ctx = 0;
        serial_buf = 0;
        sa_saved = 0;
        stack_guard = 0;
        action = 0;
        serial_buf = 0;
        bootargs = 0;
        bootargs = 0;
        thread_attr = 0;
        thread_attr = 0;
        if ((uint)val == 0) {
          tmp_buf = coruna_u64_pack(((int)arg_x_x[7]), (int)arg_x_x[6]);
          region = coruna_u64_pack(((int)arg_x_x[9]), (int)arg_x_x[8]);
          u = (size + (int)arg) - 0x110;
          scratch = coruna_u64_pack(((int)arg_x_x[3]), (int)arg_x_x[2]);
          scratch = coruna_u64_pack(((int)arg_x_x[5]), (int)arg_x_x[4]);
          host_info = (unsigned long)u << 0x20;
          size = (uint32_t)*arg_x_x;
          host_info = NEON_rev64(coruna_u64_pack(((int)arg_x_x[1]), (size)),4);
          if ((*arg_x_x & 1) != 0) {
            host_info = coruna_u64_pack((size), ((uint32_t))host_info) & 0xfffffffeffffffff;
            serial_buf = 0x20;
          }
          lk3 = _mach_vm_write(arg_x,(unsigned long)u,(vm_offset_t)&tmp_buf,0x10);
          if (lk3 != 0) {
            version = 0x1e00e;
            if (*(long *)k_persist_stack_chk_guard_slot == json_buf) {
            return version;
            }
            ___stack_chk_fail();
          }
          size = 1;
          url_buf = 0x11;
        }
        else {
          scratch = arg_x_x[3];
          scratch = arg_x_x[2];
          bootargs = arg_x_x[5];
          bootargs = arg_x_x[4];
          path_buf = arg + size + -0x180;
          thread_attr = arg_x_x[7];
          thread_attr = arg_x_x[6];
          host_info = arg_x_x[9];
          host_info = arg_x_x[8];
          cache_22 = *arg_x_x;
          sa_new = arg_x_x[1];
          size = 6;
          url_buf = 0x44;
        }
        tmp_buf = coruna_u64_pack((flags), (arg_x));
        region = coruna_u64_pack((region), (size));
        plist = (uint8_t *)&scratch;
        version = (**(void (**)(arg + 0x14))(arg,handle,0x4000001e,&tmp_buf);
      }
    }
  }
fail:
  if (*(long *)k_persist_stack_chk_guard_slot == json_buf) {
    return version;
  }
  ___stack_chk_fail();
}





bool coruna_port_name_valid(unsigned long *arg,uint size)
{
  unsigned long u;
  
  if (arg != (unsigned long *)0x0) {
    u = *arg;
    if (u == 0) {
      return false;
    }
    if ((size & 1) != 0) {
      return u != 0;
    }
    if ((((((u >> 0x20 == 0) && (*(int *)((long)arg + 0xc) == 0)) &&
          (*(int *)((long)arg + 0x14) == 0)) &&
         ((*(int *)((long)arg + 0x1c) == 0 && (*(int *)((long)arg + 0x24) == 0)))) &&
        ((*(int *)((long)arg + 0x2c) == 0 &&
         ((*(int *)((long)arg + 0x34) == 0 && (*(int *)((long)arg + 0x3c) == 0)))))) &&
       (*(int *)((long)arg + 0x44) == 0)) {
      return *(int *)((long)arg + 0x4c) == 0;
    }
  }
  return false;
}





uint64_t
void coruna_mach_port_deallocate_1c3fc(short *arg,long handle,uint64_t val,uint64_t id_2,uint64_t size_3,
            unsigned long arg_x,uint64_t off_4)
{
  int err;
  kern_return_t lk2;
  uint64_t u;
  thread_act_t scratch [3];
  
  if (arg == (short *)0x0) {
    return 0xad00a;
  }
  if (*arg != 2) {
    return 0xad00a;
  }
  if ((ushort)arg[1] < 2 || handle == 0) {
    return 0xad00a;
  }
  if ((task_t)val + 1 < 2) {
    return 0x1e009;
  }
  err = coruna_port_name_valid(size_3,id_2);
  if (err == 0) {
    return 0x1e010;
  }
  if (arg_x == 0) {
    return 0x1e011;
  }
  if (((uint)(arg_x >> 0x20 != 0) & ((uint)id_2 ^ 0xffffffff)) != 0) {
    return 0x1e011;
  }
  if ((uint)off_4 < 0x250) {
    return 0x1e011;
  }
  scratch[0] = 0;
  lk2 = _thread_create((task_t)val,scratch);
  if (lk2 != 0) {
    return 0x1e00c;
  }
  if (scratch[0] + 1 < 2) {
    return 0x1e00c;
  }
  u = coruna_ctx_free_12e04(arg,handle,val,scratch[0],id_2,size_3,arg_x,off_4);
  if ((int)u == 0) {
    scratch[1] = 0x7f;
    if (1 < scratch[0] + 1) {
      _thread_policy_set(scratch[0],3,(thread_policy_t)(scratch + 1),1);
    }
    lk2 = _thread_resume(scratch[0]);
    if (lk2 == 0) {
      u = 0;
      _mach_port_deallocate(*(ipc_space_t *)k_persist_mach_task_self_slot,scratch[0]);
      return u;
    }
    u = 0x1e013;
  }
  _thread_terminate(scratch[0]);
code_r0x00010798:
  _mach_port_deallocate(*(ipc_space_t *)k_persist_mach_task_self_slot,scratch[0]);
  return u;
}





void coruna_task_for_pid(long *handle,int flags,uint32_t *size)
{
  pid_t lp1;
  uint64_t u;
  uint32_t size;
  int scratch;
  uint32_t bootargs;
  uint32_t thread_attr[2];
  uint8_t *host_info;
  long serial_buf;
  
  serial_buf = *(long *)k_persist_stack_chk_guard_slot;
  u = 0xad001;
  if (((handle != (long *)0x0) && (0 < flags)) && (size != (uint32_t *)0x0)) {
    lp1 = _getpid();
    if (lp1 == flags) {
      u = 0;
      size = *(uint32_t *)k_persist_mach_task_self_slot;
    }
    else {
      bootargs = 0;
      thread_attr[0] = 0xc000001d;
      scratch = flags;
      host_info = (uint8_t *)&scratch;
      u = (**(void (**)(*handle + 0x40))(*handle,handle + 1,thread_attr,1,0);
      size = bootargs;
      if (*(long *)k_persist_stack_chk_guard_slot != serial_buf) {
      ___stack_chk_fail(u);
      }
      return;
    }
    *size = size;
  }
fail:
  if (*(long *)k_persist_stack_chk_guard_slot != serial_buf) {
    ___stack_chk_fail(u);
  }
  return;
}





void coruna_persistb080_residual_144(long *handle,uint size)
{
  uint64_t u;
  uint32_t scratch[2];
  unsigned long bootargs;
  uint32_t thread_attr;
  unsigned long host_info;
  uint32_t serial_buf;
  unsigned long action;
  uint32_t block_ctx;
  unsigned long stack_guard;
  long sa_saved;
  
  sa_saved = *(long *)k_persist_stack_chk_guard_slot;
  u = 0xad001;
  if (((handle != (long *)0x0) && (size != 0)) && (size != 0xffffffff)) {
    scratch[0] = 0x15;
    bootargs = (unsigned long)size;
    thread_attr = 0x1f;
    serial_buf = 0x22;
    block_ctx = 0x17;
    host_info = bootargs;
    action = bootargs;
    stack_guard = bootargs;
    u = (**(void (**)(*handle + 0x40))(*handle,handle + 1,scratch,4,0);
  }
  if (*(long *)k_persist_stack_chk_guard_slot == sa_saved) {
    return;
  }
  ___stack_chk_fail(u);
}





int coruna_rwlock_iface_destroy(long *handle)
{
  int err;
  int status;
  
  if (handle == (long *)0x0) {
    status = 0xad001;
  }
  else {
    if (handle[1] == 0) {
      status = 0;
    }
    else {
      err = (**(void (**)(*handle + 0x30))();
      status = (**(void (**)(*handle + 0x20))(*handle,handle[1]);
      if (err != 0) {
        status = err;
      }
    }
    *handle = 0;
    handle[1] = 0;
    _free(handle);
  }
  return status;
}





uint64_t
void coruna_persistb080_via_mach_port_construct_6(long handle,uint size,uint64_t val,uint64_t id_2,uint64_t size_3,
            uint64_t off_4,uint64_t off_5)
{
  bool err;
  uint64_t u;
  int err;
  
  if (handle == 0) {
    u = 4;
  }
  else {
    u = coruna_mach_port_construct_6(handle,size & 0xfffffbbf);
    if ((int)u != 0) {
      if (((size >> 6 & 1) == 0) && ((int)u == 0x10000007)) {
        err = -0xfff;
        do {
          u = coruna_mach_port_construct_6(handle,size & 0xfffffbbf,val,id_2,size_3,off_4,off_5)
          ;
          if ((int)u != 0x10000007) break;
          err = err != 0;
          err = err + 1;
        } while (err);
      }
      if (((size >> 10 & 1) == 0) && ((int)u == 0x10004005)) {
        err = -0xfff;
        do {
          u = coruna_mach_port_construct_6(handle,size & 0xfffffbbe,0,id_2,size_3,off_4,off_5);
          if ((int)u != 0x10004005) {
            return u;
          }
          err = err != 0;
          err = err + 1;
        } while (err);
      }
    }
  }
  return u;
}





uint64_t
void coruna_persistb080_via_mach_port_construct_7(long handle,unsigned long arg,unsigned long arg,uint64_t val,uint64_t id_2,
            uint64_t size_3,uint64_t off_4,uint64_t off_5)
{
  bool err;
  uint64_t u;
  int err;
  
  if (handle == 0) {
    u = 4;
  }
  else {
    u = coruna_mach_port_construct_7();
    if ((int)u != 0) {
      if ((((uint)arg >> 6 & 1) == 0) && ((int)u == 0x10000007)) {
        err = -0xfff;
        do {
          u = coruna_mach_port_construct_7(handle,arg & 0xfffffffffffffbbf,arg,val,id_2,size_3,
                               off_4,off_5);
          if ((int)u != 0x10000007) break;
          err = err != 0;
          err = err + 1;
        } while (err);
      }
      if ((((uint)arg >> 10 & 1) == 0) && ((int)u == 0x10004005)) {
        err = -0xfff;
        do {
          u = coruna_mach_port_construct_7(handle,arg & 0xfffffffffffffbbe,arg & 0xffffffff,val,
                               id_2,size_3,off_4,off_5);
          if ((int)u != 0x10004005) {
            return u;
          }
          err = err != 0;
          err = err + 1;
        } while (err);
      }
    }
  }
  return u;
}





long coruna_memcpy(long handle,long addr_2,unsigned long arg)
{
  unsigned long scratch;
  
  if (((handle != 0) && (addr_2 != 0)) && (arg != 0)) {
    for (scratch = 0; scratch < arg; scratch = scratch + 1) {
      *(uint8_t *)(handle + scratch) = *(uint8_t *)(addr_2 + scratch);
    }
  }
  return handle;
}





long coruna_memset(long handle,uint8_t buf,unsigned long arg)
{
  unsigned long scratch;
  
  if ((handle != 0) && (arg != 0)) {
    for (scratch = 0; scratch < arg; scratch = scratch + 1) {
      *(uint8_t *)(handle + scratch) = buf;
    }
  }
  return handle;
}
unsigned long coruna_persistb080_via_memcpy(unsigned long arg,uint val,long n,uint *m,int p)

{
  uint u;
  uint size;
  int idx;
  unsigned long type_id;
  uint64_t cache_81;
  uint64_t cache_31;
  uint64_t cache_82;
  uint32_t cache_83;
  uint cache_84;
  uint cache_85;
  uint8_t cache_86[372];
  uint cache_87;
  
  type_id = 4;
  if ((((n != 0) && (m != (uint *)0x0)) && (idx = (int)arg, idx != 0)) &&
     (idx != -1)) {
    cache_87 = 0;
    cache_31 = k_persist_rodata_word_0001ed60;
    cache_81 = k_persist_rodata_word_1ed58;
    cache_82 = k_persist_rodata_word_1ed68;
    type_id = coruna_mach_port_construct(arg,&cache_81,0,&cache_87);
    size = cache_87;
    if ((int)type_id == 0) {
      if (cache_87 + 1 < 2) {
        type_id = 0x11;
      }
      else {
        coruna_memset(&cache_81,0,400);
        cache_82 = coruna_u64_pack((0xd4d), ((uint32_t))cache_82);
        cache_83 = 0x100;
        cache_85 = *m;
        if (0x59 < cache_85) {
          cache_85 = 0x5a;
        }
        cache_81 = k_persist_rodata_word_1ed50;
        cache_31 = coruna_u64_pack((size), (idx));
        cache_84 = val;
        if (p == 0) {
          type_id = coruna_persistb080_via_mach_port_construct_6(&cache_81,3,0x28,400,size,0,0);
        }
        else {
          type_id = coruna_persistb080_via_mach_port_construct_7(&cache_81,0x200000003,0x2800001513,
                               arg & 0xffffffff | (unsigned long)size << 0x20,0xd4d00000000,
                               (unsigned long)size << 0x20,400,0);
        }
        if ((int)type_id == 0) {
          if (cache_82 == 0x47) {
            type_id = 0xfffffecc;
          }
          else if (cache_82 == 0xdb1) {
            type_id = 0xfffffed4;
            if (-1 < (int)cache_81) {
              if (((0x27 < cache_81) && (cache_81 < 0x191)) &&
                 (type_id = (unsigned long)cache_84, cache_84 == 0)) {
                if ((cache_85 < 0x5b) &&
                   ((unsigned long)cache_85 * 4 - (unsigned long)(cache_81 - 0x28) == 0)) {
                  u = *m;
                  if (u < cache_85) {
                    if (u != 0) {
                      coruna_memcpy(n,cache_86,(unsigned long)u << 2);
                    }
                    *m = cache_85;
                    type_id = 0xfffffecd;
                  }
                  else {
                    coruna_memcpy(n,cache_86);
                    type_id = 0;
                    *m = cache_85;
                  }
                }
                else {
                  type_id = 0xfffffed4;
                }
              }
            }
          }
          else {
            type_id = 0xfffffed3;
          }
        }
        coruna_mach_port_construct_9(arg,size,1,0xffffffff);
      }
    }
  }
  return type_id;
}





uint coruna_driver_copy_port_1918(char *path,char *str_2)
{
  char err;
  char status;
  uint u;
  
  if (path == (char *)0x0) {
    return 1;
  }
  if (str_2 != (char *)0x0) {
    do {
      err = *path;
      status = *str_2;
      path = path + 1;
      str_2 = str_2 + 1;
    } while (err != '\0' && err == status);
    u = 0xffffffff;
    if (status <= err) {
      u = (uint)(status < err);
    }
    return u;
  }
  return 0xffffffff;
}





long coruna_driver_free_ctx(long handle)
{
  long handle;
  long addr;
  
  addr = 0;
  if (handle != 0) {
    handle = 0;
    do {
      addr = handle;
      handle = addr + 1;
    } while (*(char *)(handle + addr) != '\0');
  }
  return addr;
}





uint64_t coruna_ctx_free_bc88(uint64_t *val)
{
  if (val != (uint64_t *)0x0) {
    val[7] = 0;
    val[6] = 0;
    val[9] = 0;
    val[8] = 0;
    val[3] = 0;
    val[2] = 0;
    val[5] = 0;
    val[4] = 0;
    val[1] = 0;
    *val = 0;
    _free(val);
    return 0;
  }
  return 0xad001;
}





uint64_t coruna_ctx_free_bc8c(uint64_t *val)
{
  val[7] = 0;
  val[6] = 0;
  val[9] = 0;
  val[8] = 0;
  val[3] = 0;
  val[2] = 0;
  val[5] = 0;
  val[4] = 0;
  val[1] = 0;
  *val = 0;
  _free(val);
  return 0;
}





uint64_t coruna_persist_residual_45(long handle,int flags,uint64_t *val)
{
  uint64_t u;
  
  u = 0xad001;
  if ((handle != 0) && (val != (uint64_t *)0x0)) {
    if (flags != 0) {
      return 0x1e028;
    }
    u = 0;
    *val = 0xdeaddead;
  }
  return u;
}





uint32_t coruna_dyld_port_index(long handle,long addr_2)
{
  uint32_t u;
  
  u = 0;
  if (addr_2 != 0xdeaddead || handle == 0) {
    u = 0xad001;
  }
  return u;
}





uint64_t coruna_persistb080_residual_145(long handle,long addr_2,uint64_t val,uint64_t id_2)
{
  uint64_t u;
  
  if ((handle != 0) && (addr_2 == 0xdeaddead)) {
    u = coruna_persistb080_via_mach_port_extract_right(*(uint64_t *)(handle + 8),val,id_2);
    return u;
  }
  return 0xad001;
}





int coruna_persistb080_residual_146(long handle,long *addr_2,long off_3,uint size,unsigned long arg)
{
  int err;
  int status;
  uint64_t u;
  unsigned long size;
  uint64_t *ptr;
  
  status = 0xad001;
  if ((((handle != 0) && (addr_2 != (long *)0x0)) && ((off_3 != 0 || (size == 0)))) &&
     (*addr_2 == 0xdeaddead || *addr_2 == 0)) {
    if (size != 0) {
      u = *(uint64_t *)(handle + 8);
      size = (unsigned long)size;
      ptr = (uint64_t *)(off_3 + 8);
      status = 0;
      do {
        if (((arg & 1) == 0) && (status != 0)) {
          return status;
        }
        err = coruna_persistb080_via_mach_port_extract_right(u,*(uint32_t *)(ptr + -1),*ptr);
        if (status != 0) {
          err = status;
        }
        size = size - 1;
        ptr = ptr + 2;
        status = err;
      } while (size != 0);
      if (err != 0) {
        return err;
      }
    }
    status = 0;
    *addr_2 = 0xdeaddead;
  }
  return status;
}





uint32_t coruna_dyld_port_index(long handle,long addr_2)
{
  uint32_t u;
  
  u = 0;
  if (addr_2 != 0xdeaddead || handle == 0) {
    u = 0xad001;
  }
  return u;
}





uint32_t coruna_free_ctx(long handle,long addr_2,long off_3)
{
  uint32_t u;
  
  u = 0x1e028;
  if ((off_3 == 0 || addr_2 != 0xdeaddead) || handle == 0) {
    u = 0xad001;
  }
  return u;
}





uint32_t coruna_dyld_port_index(long handle,long addr_2)
{
  uint32_t u;
  
  u = 0x1e028;
  if (addr_2 == 0 || handle == 0) {
    u = 0xad001;
  }
  return u;
}





uint64_t coruna_persistb080_residual_147(long handle,uint64_t *val)
{
  uint32_t *ptr;
  uint64_t u;
  
  u = 0xad001;
  if ((handle != 0) && (val != (uint64_t *)0x0)) {
    ptr = _calloc(1,0x50);
    if (ptr == (uint32_t *)0x0) {
      u = 0xad009;
    }
    else {
      u = 0;
      *ptr = 0x20002;
      *(long *)(ptr + 2) = handle;
      ((void (**)(void *, long, uint64_t))(ptr + 4))[0] = coruna_ctx_free_bc88;
      ((void (**)(void *, long, uint64_t))(ptr + 6))[0] = coruna_persist_residual_45;
      ((void (**)(void *, long, uint64_t))(ptr + 8))[0] = coruna_dyld_port_index;
      ((void (**)(void *, long, uint64_t))(ptr + 10))[0] = coruna_persistb080_residual_145;
      ((void (**)(void *, long, uint64_t))(ptr + 0xc))[0] = coruna_dyld_port_index;
      ((void (**)(void *, long, uint64_t))(ptr + 0xe))[0] = coruna_free_ctx;
      ((void (**)(void *, long, uint64_t))(ptr + 0x10))[0] = coruna_persistb080_residual_146;
      ((void (**)(void *, long, uint64_t))(ptr + 0x12))[0] = coruna_dyld_port_index;
      *val = ptr;
    }
  }
  return u;
}





uint64_t coruna_mach_port_mod_refs(uint64_t *val,mach_port_name_t arg,uint32_t size)
{
  kern_return_t lk1;
  uint32_t *ptr;
  uint64_t u;
  
  u = 0xad001;
  if (val != (uint64_t *)0x0) {
    if (arg + 1 < 2) {
      u = 0x1e027;
    }
    else {
      ptr = _calloc(1,0x14);
      if (ptr == (uint32_t *)0x0) {
        u = 0xad009;
      }
      else {
        lk1 = _mach_port_mod_refs(*(ipc_space_t *)k_persist_mach_task_self_slot,arg,0,1);
        if (lk1 == 0) {
          u = 0;
          *ptr = size;
          ptr[1] = arg;
          *(uint64_t *)(ptr + 2) = 0x753000007530;
          ptr[4] = 0;
          *val = ptr;
        }
        else {
          _free(ptr);
          u = 0x1e01b;
        }
      }
    }
  }
  return u;
}





uint64_t coruna_mach_port_deallocate_1132c(uint64_t *val)
{
  if (val != (uint64_t *)0x0) {
    if (1 < *(mach_port_name_t *)((long)val + 4) + 1) {
      _mach_port_deallocate
                (*(ipc_space_t *)k_persist_mach_task_self_slot,
                 *(mach_port_name_t *)((long)val + 4));
    }
    if (1 < *(mach_port_name_t *)(val + 2) + 1) {
      _mach_port_deallocate
                (*(ipc_space_t *)k_persist_mach_task_self_slot,*(mach_port_name_t *)(val + 2));
    }
    *val = 0;
    val[1] = 0;
    *(uint32_t *)(val + 2) = 0;
    _free(val);
    return 0;
  }
  return 0xad001;
}





int coruna_persistb080_via_mach_port_extract_right(long handle,unsigned long arg,unsigned long *arg)
{
  uint32_t u;
  int err;
  uint size;
  uint32_t version;
  int *err;
  int scratch;
  int bootargs;
  unsigned long thread_attr;
  unsigned long *host_info;
  uint64_t serial_buf;
  uint64_t scratch;
  uint64_t bootargs;
  unsigned long action;
  
  if (handle == 0) {
    return 0xad001;
  }
  scratch = 0xad00b;
  err = (int)arg;
  if (0x40000003 < err) {
    if (err < 0x40000012) {
      if (err + 0xbffffffcU < 2) {
        size = 3;
        if (err == 0x40000005) {
          size = 4;
        }
        arg = (unsigned long)size;
        version = *(uint32_t *)k_persist_mach_task_self_slot;
        host_info = arg;
fail:
        thread_attr = coruna_u64_pack((thread_attr), (version));
        serial_buf = 0;
        version = *(uint32_t *)(handle + 8);
        arg = &thread_attr;
      }
      else {
        if (1 < err + 0xbffffff0U) {
          if (err != 0x4000000e) {
            return 0x1e028;
          }
          version = 1;
          if (err != 0x4000000e) {
          version = 2;
          }
          u = *(uint32_t *)(handle + 8);
          }
          else {
          version = 10;
          if (err != -0x3fffffdd) {
          version = 0xb;
          }
          err = coruna_persistb080_via_mach_port_extract_right_3(handle,version,arg,*(uint32_t *)(handle + 8),&scratch);
          if (err != 0) {
          scratch = err;
          }
          return scratch;
        }
        size = 3;
        if (err == 0x40000010) {
          size = 4;
        }
        arg = (unsigned long)size;
        version = *(uint32_t *)(handle + 8);
      }
      err = coruna_persistb080_via_mach_port_extract_right_4(handle,arg,arg,version,&scratch);
    }
    else {
      if (err == 0x40000012) {
done:
        version = 1;
        if (err != 0x4000000e) {
          version = 2;
        }
        u = *(uint32_t *)(handle + 8);
      }
      else {
        version = 10;
        if (err != -0x3fffffdd) {
        version = 0xb;
        }
        err = coruna_persistb080_via_mach_port_extract_right_3(handle,version,arg,*(uint32_t *)(handle + 8),&scratch);
        if (err != 0) {
        scratch = err;
        }
        return scratch;
        if (err != 0x40000021) {
          return 0x1e028;
        }
        u = *(uint32_t *)(handle + 8);
        version = 9;
      }
      err = coruna_persistb080_via_mach_port_extract_right_2(handle,version,arg,u,&scratch);
    }
    if (err != 0) {
    scratch = err;
    }
    return scratch;
  }
  if (err < 0xc) {
    if (err < 3) {
      if (err == -0x7fffffe4) {
        if (arg == (unsigned long *)0x0) {
          return 0xad001;
        }
        bootargs = 0xad00b;
        err = (int *)(handle + 0x10);
        if (*err + 1U < 2) {
          scratch = 0;
          serial_buf = 0;
          bootargs = 0;
          host_info = (unsigned long *)0x0;
          thread_attr = 8;
          action = (unsigned long)*(uint *)k_persist_mach_task_self_slot;
          err = coruna_mach_port_extract_right(handle,&thread_attr,*(uint32_t *)(handle + 8),&bootargs,err,0);
          if (err != 0) {
          scratch = err;
          }
          return scratch;
        }
        else {
          bootargs = 0;
        }
        err = 0;
        *(int *)arg = *err;
        scratch = bootargs;
        if (err != 0) {
        scratch = err;
        }
        return scratch;
      }
      if (err != -0x3fffffdd) {
        return 0x1e028;
      }
cleanup:
      version = 10;
      if (err != -0x3fffffdd) {
        version = 0xb;
      }
      err = coruna_persistb080_via_mach_port_extract_right_3(handle,version,arg,*(uint32_t *)(handle + 8),&scratch);
      if (err != 0) {
      scratch = err;
      }
      return scratch;
    }
    if (err == 3) {
      version = *(uint32_t *)k_persist_mach_task_self_slot;
      host_info = (unsigned long *)0x1f322;
      thread_attr = coruna_u64_pack((thread_attr), (version));
      serial_buf = 0;
      version = *(uint32_t *)(handle + 8);
      arg = &thread_attr;
      }
      else {
      if (1 < err + 0xbffffff0U) {
      if (err != 0x4000000e) {
      return 0x1e028;
      }
      version = 1;
      if (err != 0x4000000e) {
      version = 2;
      }
      u = *(uint32_t *)(handle + 8);
      }
      else {
      version = 10;
      if (err != -0x3fffffdd) {
      version = 0xb;
      }
      err = coruna_persistb080_via_mach_port_extract_right_3(handle,version,arg,*(uint32_t *)(handle + 8),&scratch);
      if (err != 0) {
      scratch = err;
      }
      return scratch;
      }
      size = 3;
      if (err == 0x40000010) {
      size = 4;
      }
      arg = (unsigned long)size;
      version = *(uint32_t *)(handle + 8);
      }
      err = coruna_persistb080_via_mach_port_extract_right_4(handle,arg,arg,version,&scratch);
      }
      else {
      if (err == 0x40000012) {
      version = 1;
      if (err != 0x4000000e) {
      version = 2;
      }
      u = *(uint32_t *)(handle + 8);
      }
      else {
      version = 10;
      if (err != -0x3fffffdd) {
      version = 0xb;
      }
      err = coruna_persistb080_via_mach_port_extract_right_3(handle,version,arg,*(uint32_t *)(handle + 8),&scratch);
      if (err != 0) {
      scratch = err;
      }
      return scratch;
    }
    if (err != 9) {
      return 0x1e028;
    }
skip:
    version = *(uint32_t *)(handle + 8);
    size = 7;
  }
  else {
    if (0x15 < err) {
      if (err == 0x16) {
        version = *(uint32_t *)(handle + 8);
        size = 6;
      }
      else if (err == 0x1a) {
        version = *(uint32_t *)(handle + 8);
        size = 7;
      }
      else {
        return 0x1e028;
      }
    }
    else if (err == 0xc) {
      version = *(uint32_t *)(handle + 8);
      size = 5;
    }
    else {
      if (err != 0xd) {
        return 0x1e028;
      }
      version = *(uint32_t *)(handle + 8);
      size = 6;
    }
  }
  bootargs = 0;
  scratch = 0;
  serial_buf = 0;
  host_info = (unsigned long *)0x0;
  thread_attr = (unsigned long)size;
  size = (uint)arg;
  if (size == 0) {
    size = *(uint *)k_persist_mach_task_self_slot;
  }
  action = (unsigned long)size;
  err = coruna_mach_port_extract_right(handle,&thread_attr,version,&scratch,0,0);
check_ok:
  if (err != 0) {
    scratch = err;
  }
  return scratch;
}





uint64_t
void coruna_persistb080_via_mach_port_extract_right_2(long handle,uint32_t size,int *flags,uint64_t val,long addr_2)
{
  uint64_t u;
  uint32_t scratch[2];
  uint32_t bootargs;
  uint64_t *thread_attr;
  uint64_t host_info;
  uint64_t scratch;
  int serial_buf;
  uint64_t action;
  uint64_t bootargs;
  int block_ctx;
  uint8_t stack_guard;
  
  u = 0xad001;
  if (((handle != 0) && (flags != (int *)0x0)) && (addr_2 != 0)) {
    bootargs = *(uint64_t *)(flags + 4);
    action = *(uint64_t *)(flags + 2);
    block_ctx = flags[6];
    stack_guard = (uint8_t)flags[7];
    bootargs = 0x18;
    thread_attr = &action;
    host_info = 0;
    scratch = 0;
    serial_buf = *flags;
    if (serial_buf == 0) {
      serial_buf = *(int *)k_persist_mach_task_self_slot;
    }
    scratch[0] = size;
    u = coruna_mach_port_extract_right(handle,scratch,val,addr_2,0,0);
  }
  return u;
}
uint coruna_mach_port_extract_right(int *flags,int *count_2,mach_msg_timeout_t arg,int *fd_3,
                 mach_port_name_t *arg_x,long handle)
{
  bool err;
  mach_port_t *lpm2;
  uint u;
  uint size;
  mach_msg_return_t lm5;
  kern_return_t lk6;
  mach_msg_header_t *msg;
  int err;
  mach_port_name_t lm8;
  unsigned long version;
  unsigned long port;
  ipc_space_t *err;
  mach_msg_header_t *scratch;
  mach_port_name_t bootargs;
  mach_msg_type_name_t thread_attr;
  mach_port_t host_info;
  mach_msg_header_t serial_buf;
  int action;
  uint64_t scratch;
  uint block_ctx;
  uint32_t bootargs;
  int stack_guard;
  uint64_t sa_saved;
  uint64_t thread_attr;
  uint64_t sa_new;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t path_buf;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t sa_saved;
  uint64_t tmp_buf;
  uint64_t sa_new;
  uint64_t region;
  uint64_t path_buf;
  uint64_t tmp_buf;
  uint64_t region;
  uint64_t plist;
  uint64_t plist;
  uint64_t url_buf;
  uint64_t json_buf;
  uint64_t url_buf;
  uint64_t frame;
  uint64_t work;
  uint64_t cache;
  uint64_t json_buf;
  uint64_t cache_20;
  uint64_t cache_21;
  uint64_t cache_22;
  uint64_t frame;
  uint64_t cache_23;
  uint64_t cache_24;
  uint32_t cache_25;
  uint32_t work;
  uint32_t cache_26;
  uint64_t cache_27;
  long cache;
  
  err = (ipc_space_t *)k_persist_mach_task_self_slot;
  cache = *(long *)k_persist_stack_chk_guard_slot;
  size = 0xad001;
  scratch = (mach_port_t *)coruna_u64_pack((scratch), ((mach_port_name_t))scratch);
  if ((((flags == (int *)0x0) ||
       (scratch = (mach_port_t *)coruna_u64_pack((scratch), ((mach_port_name_t))scratch),
       count_2 == (int *)0x0)) ||
      ((*(long *)(count_2 + 4) == 0 &&
       (scratch = (mach_port_t *)coruna_u64_pack((scratch), ((mach_port_name_t))scratch),
       count_2[2] != 0)))) ||
     (((*(long *)(count_2 + 8) == 0 &&
       (scratch = (mach_port_t *)coruna_u64_pack((scratch), ((mach_port_name_t))scratch),
       count_2[6] != 0)) ||
      (scratch = (mach_port_t *)coruna_u64_pack((scratch), ((mach_port_name_t))scratch),
      if (*(long *)k_persist_stack_chk_guard_slot != cache) {
      ___stack_chk_fail(flags);
      }
      return size;
  bootargs = 0;
  u = _mach_port_allocate(*(ipc_space_t *)k_persist_mach_task_self_slot,1,&bootargs);
  if (u != 0) {
    size = 0x1e01b;
    flags = (int *)(unsigned long)u;
    if (*(long *)k_persist_stack_chk_guard_slot != cache) {
    ___stack_chk_fail(flags);
    }
    return size;
  }
  if (((*(long *)(count_2 + 4) != 0) || (count_2[2] == 0)) &&
     ((*(long *)(count_2 + 8) != 0 ||
      (scratch = (mach_port_t *)coruna_u64_pack((scratch), ((mach_port_name_t))scratch),
      count_2[6] == 0)))) {
    serial_buf.msgh_bits = 0x1413;
    serial_buf.msgh_remote_port = flags[1];
    serial_buf.msgh_id = *count_2 + *flags;
    scratch = 0;
    scratch = 0;
    action = 0;
    serial_buf.msgh_reserved = 0;
    serial_buf.msgh_size = 0;
    block_ctx = 0;
    bootargs = 0;
    serial_buf.msgh_local_port = bootargs;
    lm8 = count_2[10];
    lpm2 = (mach_port_t *)(unsigned long)lm8;
    if (lm8 + 1 < 2) {
      port = 0x18;
      lpm2 = (mach_port_t *)0x0;
    }
    else {
      action = 1;
      if (*(double *)k_persist_dyldversionnumber_slot <= k_persist_rodata_word_1ed70) {
        block_ctx = 0x130000;
      }
      else {
        host_info = 0xffffffff;
        lpm2 = &host_info;
        size = _pid_for_task(lm8,(int *)&host_info);
        if (size != 0) {
          size = size | 0x80000000;
          scratch = (mach_port_t *)coruna_u64_pack((scratch), ((mach_port_name_t))scratch);
          u = _mach_port_destroy(*err,bootargs);
          flags = (int *)(unsigned long)u;
          if (*(long *)k_persist_stack_chk_guard_slot != cache) {
          ___stack_chk_fail(flags);
          }
          return size;
        }
        block_ctx = (uint)k_persist_rodata_word_1ed78;
        bootargs = (uint32_t)((unsigned long)k_persist_rodata_word_1ed78 >> 0x20);
      }
      serial_buf.msgh_bits = 0x80001413;
      port = 0x2c;
    }
    scratch = lpm2;
    if (count_2[2] == 0 && count_2[6] == 0) {
      scratch = (mach_msg_header_t *)0x0;
      msg = &serial_buf;
      version = port;
    }
    else {
      version = (unsigned long)(((uint)port | 3) + count_2[2] + count_2[6] & 0xfffffffc);
      msg = _calloc(1,version);
      if (msg == (mach_msg_header_t *)0x0) {
        size = 0xad009;
        err = (ipc_space_t *)k_persist_mach_task_self_slot;
        u = _mach_port_destroy(*err,bootargs);
        flags = (int *)(unsigned long)u;
        if (*(long *)k_persist_stack_chk_guard_slot != cache) {
        ___stack_chk_fail(flags);
        }
        return size;
      }
      coruna_persistb080_trampoline_00010c24(msg,&serial_buf);
      if (count_2[2] != 0) {
        coruna_persistb080_trampoline_00010c24((long)&msg->msgh_bits + port,*(uint64_t *)(count_2 + 4));
        port = (unsigned long)(count_2[2] + (uint)port);
      }
      scratch = msg;
      if (count_2[6] != 0) {
        coruna_persistb080_trampoline_00010c24((long)&msg->msgh_bits + port,*(uint64_t *)(count_2 + 8));
      }
    }
    msg->msgh_size = (mach_msg_size_t)version;
    lm5 = _mach_msg(msg,0x11,(mach_msg_size_t)version,0,0,arg,0);
    if (lm5 < 0x10000004) {
      if (lm5 == 0) {
        err = true;
        size = 0;
      }
      else {
        if (lm5 != 0x10000003) goto cleanup;
        err = false;
        size = 0x1e02c;
      }
    }
    else if (lm5 == 0x10000004) {
      _mach_msg_destroy(msg);
      err = false;
      size = 0x1e02d;
    }
    else {
cleanup:
      err = false;
      size = 0x1e025;
    }
    _bzero(msg,version);
    if (scratch != (mach_msg_header_t *)0x0) {
      _free(scratch);
    }
    err = (ipc_space_t *)k_persist_mach_task_self_slot;
    if (err) {
      if (bootargs + 1 < 2) {
        size = 0x1e02b;
      }
      else {
        cache_27 = 0;
        cache_26 = 0;
        cache_23 = 0;
        frame = 0;
        cache_25 = 0;
        work = 0;
        cache_24 = 0;
        cache_20 = 0;
        json_buf = 0;
        cache_22 = 0;
        cache_21 = 0;
        frame = 0;
        url_buf = 0;
        cache = 0;
        work = 0;
        plist = 0;
        plist = 0;
        json_buf = 0;
        url_buf = 0;
        path_buf = 0;
        region = 0;
        region = 0;
        tmp_buf = 0;
        sa_new = 0;
        tmp_buf = 0;
        block_ctx = 0;
        path_buf = 0;
        sa_saved = 0;
        stack_guard = 0;
        host_info = 0;
        sa_new = 0;
        action = 0;
        serial_buf = 0;
        bootargs = 0;
        stack_guard = 0;
        scratch = 0;
        block_ctx = 0;
        thread_attr = 0;
        sa_saved = 0;
        serial_buf.msgh_remote_port = 0;
        serial_buf.msgh_local_port = 0;
        serial_buf.msgh_bits = 0;
        serial_buf.msgh_size = 0;
        action = 0;
        scratch = 0;
        serial_buf.msgh_reserved = 0;
        serial_buf.msgh_id = 0;
        lm5 = _mach_msg(&serial_buf,0x102,0,0x13c,bootargs,flags[3],0);
        lm8 = (mach_port_name_t)scratch;
        size = 0x1e021;
        if (lm5 < 0x10004008) {
          if (lm5 != 0) {
            scratch = (mach_port_t *)coruna_u64_pack((scratch), ((mach_port_name_t))scratch);
            if (lm5 == 0x10004003) {
              size = 0x1e02e;
              scratch = (mach_port_t *)coruna_u64_pack((scratch), ((mach_port_name_t))scratch);
            }
            u = _mach_port_destroy(*err,bootargs);
            flags = (int *)(unsigned long)u;
            if (*(long *)k_persist_stack_chk_guard_slot != cache) {
            ___stack_chk_fail(flags);
            }
            return size;
          }
          if ((serial_buf.msgh_size != 0x134) || (serial_buf.msgh_id != -5)) {
            size = 0x1e029;
            _mach_msg_destroy(&serial_buf);
            scratch = (mach_port_t *)coruna_u64_pack((scratch), ((mach_port_name_t))scratch);
          }
          else {
          err = stack_guard;
          if (stack_guard == 0) {
            if ((arg_x == (mach_port_name_t *)0x0) && (handle == 0)) {
              err = 0;
            }
            else {
              if (arg_x == (mach_port_name_t *)0x0) {
                size = 0;
                if (handle != 0) {
                  if ((int)sa_saved == 0) {
                    size = 0xad014;
                    _mach_msg_destroy(&serial_buf);
                    scratch = (mach_port_t *)coruna_u64_pack((scratch), ((mach_port_name_t))scratch);
                  }
                  else {
                  coruna_persistb080_trampoline_00010c24(handle,(long)&sa_saved + 4);
                  err = stack_guard;
                  size = 0;
                  *fd_3 = err;
                  }
                }
              }
              else {
                if (((action != 1) || (block_ctx >> 0x18 != 0)) ||
                   ((mach_port_name_t)scratch + 1 < 2)) {
                  size = 0x1e029;
                  _mach_msg_destroy(&serial_buf);
                  scratch = (mach_port_t *)coruna_u64_pack((scratch), ((mach_port_name_t))scratch);
                }
                else {
                host_info = (mach_port_name_t)scratch;
                u = block_ctx >> 0x10 & 0xff;
                if (u - 0x11 < 2) {
                  scratch = 0;
                  size = 0;
                  *arg_x = lm8;
                }
                else if (u == 0x14) {
                  lk6 = _mach_port_insert_right
                                    (*err,(mach_port_name_t)scratch,
                                     (mach_port_name_t)scratch,0x14);
                  if (lk6 == 0) {
                    scratch = 0;
                    size = 0;
                    *arg_x = lm8;
                  }
                  else {
                  size = 0xad00b;
                  }
                }
                else {
                  size = 0x1e029;
                  if (u == 0x15) {
                    thread_attr = 0;
                    lk6 = _mach_port_extract_right
                                      (*err,(mach_port_name_t)scratch,0x15,&host_info,
                                       &thread_attr);
                    lm8 = host_info;
                    if (lk6 != 0) {
                      size = 0xad00b;
                    }
                    else {
                      scratch = 0;
                      size = 0;
                      *arg_x = lm8;
                    }
                  }
                }
                if (size == 0) {
                  size = 0;
                  if (handle != 0) {
                    if ((int)sa_saved == 0) {
                      size = 0xad014;
                      _mach_msg_destroy(&serial_buf);
                      scratch = (mach_port_t *)coruna_u64_pack((scratch), ((mach_port_name_t))scratch);
                    }
                    else {
                    coruna_persistb080_trampoline_00010c24(handle,(long)&sa_saved + 4);
                    err = stack_guard;
                    size = 0;
                    *fd_3 = err;
                    }
                  }
                }
                err = stack_guard;
                if (size != 0) {
                  _mach_msg_destroy(&serial_buf);
                  scratch = (mach_port_t *)coruna_u64_pack((scratch), ((mach_port_name_t))scratch);
                }
                }
              }
              if (size == 0 && fd_3 != (int *)0x0) {
                size = 0;
                *fd_3 = err;
              }
            }
          }
          else {
          size = 0;
          *fd_3 = err;
          }
          }
        }
        u = _mach_port_destroy(*err,bootargs);
        flags = (int *)(unsigned long)u;
        if (*(long *)k_persist_stack_chk_guard_slot != cache) {
        ___stack_chk_fail(flags);
        }
        return size;
      }
    }
  }
done:
  u = _mach_port_destroy(*err,bootargs);
  flags = (int *)(unsigned long)u;
fail:
  if (*(long *)k_persist_stack_chk_guard_slot != cache) {
    ___stack_chk_fail(flags);
  }
  return size;
}





uint64_t
void coruna_persistb080_via_mach_port_extract_right_3(long handle,uint32_t size,int *flags,uint64_t val,long addr_2)
{
  int err;
  uint64_t u;
  uint32_t scratch[2];
  uint32_t bootargs;
  uint64_t *thread_attr;
  uint64_t host_info;
  uint64_t scratch;
  int serial_buf;
  uint64_t action;
  uint64_t bootargs;
  uint8_t block_ctx;
  
  u = 0xad001;
  if (((handle != 0) && (flags != (int *)0x0)) && (addr_2 != 0)) {
    err = *flags;
    bootargs = *(uint64_t *)(flags + 4);
    action = *(uint64_t *)(flags + 2);
    block_ctx = (uint8_t)flags[6];
    bootargs = 0x18;
    thread_attr = &action;
    host_info = 0;
    scratch = 0;
    serial_buf = err;
    if (err == 0) {
      serial_buf = *(int *)k_persist_mach_task_self_slot;
    }
    scratch[0] = size;
    u = coruna_mach_port_extract_right(handle,scratch,val,addr_2,0,flags);
    *flags = err;
  }
  return u;
}





uint64_t
void coruna_persistb080_via_mach_port_extract_right_4(long handle,uint32_t size,int *flags,uint64_t val,long addr_2)
{
  size_t ls1;
  uint64_t u;
  uint32_t scratch[2];
  uint32_t bootargs;
  int *thread_attr;
  uint64_t host_info;
  char *serial_buf;
  int action;
  int block_ctx [2];
  
  u = 0xad001;
  if (((handle != 0) && (flags != (int *)0x0)) &&
     (serial_buf = *(char **)(flags + 2), serial_buf != (char *)0x0 && addr_2 != 0)) {
    block_ctx[0] = flags[5];
    bootargs = 4;
    thread_attr = block_ctx;
    host_info = 0;
    action = *flags;
    if (action == 0) {
      action = *(int *)k_persist_mach_task_self_slot;
    }
    scratch[0] = size;
    ls1 = _strlen(serial_buf);
    host_info = coruna_u64_pack((host_info), (int)ls1 + 1);
    u = coruna_mach_port_extract_right(handle,scratch,val,addr_2,0,0);
  }
  return u;
}





uint64_t
void coruna_persistb080_via_ctx_free_18dac(uint64_t *val,short *arg,uint64_t id_2,short *arg,uint64_t size_3
            ,int flags)
{
  uint64_t *ptr;
  uint32_t *buf;
  uint64_t u;
  
  u = 0xad001;
  if (((val != (uint64_t *)0x0) &&
      ((arg == (short *)0x0 || ((*arg == 2 && (1 < (ushort)arg[1])))))) &&
     ((arg == (short *)0x0 || ((*arg == 1 && (arg[1] != 0)))))) {
    ptr = _calloc(1,0x20);
    if (ptr == (uint64_t *)0x0) {
      u = 0xad009;
    }
    else {
      ptr[1] = arg;
      ptr[2] = arg;
      u = coruna_resolve_libcache_sym(ptr,arg,id_2,size_3);
      if ((int)u == 0) {
        if ((flags == 0) || (u = coruna_persistb080_via_csops_18e40(ptr), (int)u == 0)) {
          buf = _calloc(1,0x70);
          if (buf != (uint32_t *)0x0) {
            *buf = 0x10003;
            *(uint64_t **)(buf + 2) = ptr;
            *(void (**)(buf + 4) = coruna_ctx_free_c54c;
            *(void (**)(buf + 6) = coruna_persistb080_via_persistb080_via_csops_18e40;
            *(void (**)(buf + 8) = coruna_return_zero_c668;
            *(void (**)(buf + 10) = coruna_call_csops_12bb0;
            *(void (**)(buf + 0xc) = coruna_persistb080_via_ctx_free_c9d4;
            *(void (**)(buf + 0xe) = coruna_call_realpath;
            *(void (**)(buf + 0x10) = coruna_call_objc_msgsend;
            *(void (**)(buf + 0x12) = coruna_call_mach_port_deallocate_19584;
            *(void (**)(buf + 0x14) = coruna_call_mach_port_deallocate_19110;
            *(void (**)(buf + 0x16) = coruna_call_mach_port_deallocate_1865c;
            *(void (**)(buf + 0x18) = coruna_call_realpath_c878;
            *(void (**)(buf + 0x1a) = coruna_loader_iface_get;
            *val = buf;
            return 0;
          }
          u = 0xad009;
          if (ptr[3] != 0) {
            coruna_ctx_free_18dac();
            ptr[3] = 0;
          }
        }
        coruna_ctx_free_129d0(*ptr);
        *ptr = 0;
      }
      _free(ptr);
    }
  }
  return u;
}





uint64_t coruna_persistb080_via_csops_18e40(uint64_t *val)
{
  int err;
  uint64_t u;
  long *ptr;
  
  if (val == (uint64_t *)0x0) {
    u = 0xad001;
  }
  else {
    ptr = val + 3;
    if ((*ptr == 0) && (val[2] != 0)) {
      u = coruna_csops_18e40(ptr,val[2],*val,val[1]);
      err = (int)u;
      if ((err != 0) && ((err == 0x7003 || ((val[1] == 0 && (err == 0x1e037)))))) {
        u = 0;
        *ptr = 0;
      }
    }
    else {
      u = 0;
    }
  }
  return u;
}





uint64_t coruna_ctx_free_c54c(uint64_t *val)
{
  uint64_t u;
  uint64_t size;
  uint64_t *ptr;
  
  if (val == (uint64_t *)0x0) {
    return 0xad001;
  }
  ptr = (uint64_t *)val[1];
  if (ptr[3] == 0) {
    size = coruna_ctx_free_129d0(*ptr);
  }
  else {
    u = coruna_ctx_free_18dac();
    size = coruna_ctx_free_129d0(*ptr);
    ptr[1] = 0;
    *ptr = 0;
    ptr[3] = 0;
    ptr[2] = 0;
    _free(ptr);
    val[0xb] = 0;
    val[10] = 0;
    val[0xd] = 0;
    val[0xc] = 0;
    val[7] = 0;
    val[6] = 0;
    val[9] = 0;
    val[8] = 0;
    val[3] = 0;
    val[2] = 0;
    val[5] = 0;
    val[4] = 0;
    val[1] = 0;
    *val = 0;
    _free(val);
    return u;
  }
  u = size;
fail:
  ptr[1] = 0;
  *ptr = 0;
  ptr[3] = 0;
  ptr[2] = 0;
  _free(ptr);
  val[0xb] = 0;
  val[10] = 0;
  val[0xd] = 0;
  val[0xc] = 0;
  val[7] = 0;
  val[6] = 0;
  val[9] = 0;
  val[8] = 0;
  val[3] = 0;
  val[2] = 0;
  val[5] = 0;
  val[4] = 0;
  val[1] = 0;
  *val = 0;
  _free(val);
  return u;
}





unsigned long coruna_persistb080_via_persistb080_via_csops_18e40(long arg,short *val)

{
  uint u;
  unsigned long size;
  uint64_t *ptr;
  
  size = 0xad001;
  if ((((arg != 0) && (val != (short *)0x0)) && (*val == 2)) && (1 < (ushort)val[1])
     ) {
    ptr = *(uint64_t **)(arg + 8);
    if ((short *)ptr[1] == (short *)0x0) {
      size = coruna_persistb080_via_helper_17398_1d538(*ptr,val);
      if ((int)size == 0) {
        ptr[1] = val;
        size = coruna_persistb080_via_csops_18e40(ptr);
        if ((int)size != 0) {
          ptr[1] = 0;
        }
      }
    }
    else {
      u = 0;
      if ((short *)ptr[1] != val) {
        u = 0xad005;
      }
      size = (unsigned long)u;
    }
  }
  return size;
}





uint64_t coruna_return_zero_c668(long handle)
{
  uint64_t u;
  long handle;
  uint64_t size;
  uint64_t *ptr;
  long *ptr;
  
  size = 0xad001;
  if (handle == 0) {
    return 0xad001;
  }
  ptr = *(uint64_t **)(handle + 8);
  if (ptr[1] == 0) {
    return 0;
  }
  if (ptr[3] == 0) {
    ptr = (long *)*ptr;
    if (ptr != (long *)0x0) {
      handle = *ptr;
      if ((handle != 0) && ((char)ptr[2] != '\0')) {
        (**(void (**)(handle + 0x20))(handle,ptr[1]);
      }
      size = 0;
      *ptr = 0;
      ptr[1] = 0;
      *(uint8_t *)(ptr + 2) = 0;
    }
  }
  else {
    u = coruna_ctx_free_18dac();
    ptr[3] = 0;
    ptr = (long *)*ptr;
    if (ptr != (long *)0x0) {
      handle = *ptr;
      if ((handle != 0) && ((char)ptr[2] != '\0')) {
        (**(void (**)(handle + 0x20))(handle,ptr[1]);
      }
      size = 0;
      *ptr = 0;
      ptr[1] = 0;
      *(uint8_t *)(ptr + 2) = 0;
    }
    ptr[1] = 0;
    return u;
  }
  u = size;
fail:
  ptr[1] = 0;
  return u;
}





uint64_t coruna_call_csops_12bb0(long handle)
{
  uint64_t u;
  
  if (handle != 0) {
    u = coruna_csops_12bb0(**(uint64_t **)(handle + 8));
    return u;
  }
  return 0xad001;
}





uint64_t
void coruna_persistb080_via_ctx_free_c9d4(long handle,long addr_2,uint64_t val,uint64_t id_2,uint64_t *size_3)
{
  uint64_t u;
  uint64_t size;
  uint16_t *ptr;
  uint64_t version;
  uint64_t *buf;
  long scratch;
  
  version = 0xad001;
  if ((((handle != 0) && (addr_2 != 0)) && ((int)val != 0)) && (size_3 != (uint64_t *)0x0))
  {
    buf = *(uint64_t **)(handle + 8);
    ptr = _calloc(1,0x40);
    if (ptr == (uint16_t *)0x0) {
      version = 0xad009;
    }
    else {
      *ptr = 1;
      ((void (**)(void *, long, uint64_t))(ptr + 0x14))[0] = coruna_ctx_free_c9d4;
      ((void (**)(void *, long, uint64_t))(ptr + 0x18))[0] = coruna_persistb080_residual_148;
      ((void (**)(void *, long, uint64_t))(ptr + 0x1c))[0] = coruna_persistb080_residual_149;
      scratch = 0;
      version = coruna_persistb080_via_parse_xnu_processors(*buf,addr_2,val,id_2,&scratch);
      if ((int)version == 0) {
        u = *(uint64_t *)(scratch + 8);
        size = *(uint64_t *)(scratch + 0x10);
        *(long *)(ptr + 4) = scratch;
        *(uint64_t *)(ptr + 8) = u;
        *(int *)(ptr + 0xc) = (int)size;
        *(uint64_t *)(ptr + 0x10) = *(uint64_t *)(scratch + 0x18);
        *size_3 = ptr;
      }
      else {
        coruna_ctx_free_c9d4(ptr);
      }
    }
  }
  return version;
}





unsigned long coruna_call_realpath(long arg,uint64_t val)

{
  uint u;
  unsigned long size;
  
  u = 0xad001;
  if (arg != 0) {
    if (*(long *)(*(long *)(arg + 8) + 0x18) != 0) {
      size = coruna_realpath(val,3);
      return size;
    }
    u = 0xad010;
  }
  return (unsigned long)u;
}





unsigned long coruna_call_realpath_c878(long arg,uint64_t val,uint64_t n,uint64_t m)

{
  uint u;
  unsigned long size;
  
  u = 0xad001;
  if (arg != 0) {
    if (*(long *)(*(long *)(arg + 8) + 0x18) != 0) {
      size = coruna_realpath(val,n,m);
      return size;
    }
    u = 0xad010;
  }
  return (unsigned long)u;
}





unsigned long coruna_call_objc_msgsend(long arg)

{
  uint u;
  unsigned long size;
  long serial;
  
  u = 0xad001;
  if (arg != 0) {
    serial = *(long *)(*(long *)(arg + 8) + 0x18);
    if (serial != 0) {
      size = coruna_objc_msgsend(serial);
      return size;
    }
    u = 0xad010;
  }
  return (unsigned long)u;
}





uint64_t coruna_call_mach_port_deallocate_19584(long handle)
{
  uint64_t u;
  long handle;
  
  u = 0xad001;
  if (handle != 0) {
    handle = *(long *)(*(long *)(handle + 8) + 0x18);
    if (handle == 0) {
      u = 0xad010;
    }
    else {
      u = coruna_mach_port_deallocate_19584(handle);
    }
  }
  return u;
}





uint64_t coruna_call_mach_port_deallocate_19110(long handle)
{
  uint64_t u;
  long handle;
  
  u = 0xad001;
  if (handle != 0) {
    handle = *(long *)(*(long *)(handle + 8) + 0x18);
    if (handle == 0) {
      u = 0xad010;
    }
    else {
      u = coruna_mach_port_deallocate_19110(handle);
    }
  }
  return u;
}





uint64_t coruna_call_mach_port_deallocate_1865c(long handle,uint64_t val,uint64_t id_2,long addr_2)
{
  uint64_t u;
  
  if ((((handle != 0) && ((int)val != 0)) && ((int)val != -1)) && (addr_2 != 0)) {
    u = coruna_mach_port_deallocate_1865c(val,id_2,0,addr_2,0);
    return u;
  }
  return 0xad001;
}





uint64_t coruna_loader_iface_get(long handle)
{
  uint64_t u;
  long handle;
  
  u = 0;
  if (handle != 0) {
    if ((*(long **)(handle + 8) == (long *)0x0) || (handle = **(long **)(handle + 8), handle == 0))
    {
      return 0;
    }
    u = *(uint64_t *)(handle + 8);
  }
  return u;
}





uint64_t coruna_ctx_free_c9d4(uint64_t *val)
{
  uint64_t u;
  
  if (val == (uint64_t *)0x0) {
    u = 0xad001;
  }
  else {
    if (val[1] == 0) {
      u = 0;
    }
    else {
      u = coruna_persistb080_via_mach_vm_deallocate_11e48();
    }
    val[5] = 0;
    val[4] = 0;
    val[7] = 0;
    val[6] = 0;
    val[1] = 0;
    *val = 0;
    val[3] = 0;
    val[2] = 0;
    _free(val);
  }
  return u;
}





uint64_t coruna_persistb080_residual_148(long handle,long addr_2,long off_3)
{
  uint64_t u;
  
  if ((((handle != 0) && (addr_2 != 0)) && (off_3 != 0)) && (*(long *)(handle + 8) != 0)) {
    u = coruna_persistb080_residual_152();
    return u;
  }
  return 0xad001;
}





uint64_t coruna_persistb080_residual_149(long handle)
{
  uint64_t u;
  
  if ((handle != 0) && (*(long *)(handle + 8) != 0)) {
    u = coruna_persistb080_via_macho_foreach_loadcmd_8();
    return u;
  }
  return 0xad001;
}





uint64_t coruna_persistb080_via_csops_18e40_2(long handle)
{
  uint *ptr;
  long *ptr;
  unsigned long *buf;
  unsigned long *str;
  unsigned long *copy;
  unsigned long *data;
  uint u;
  byte err;
  long handle;
  uint *obj;
  unsigned long *block;
  uint *entry;
  unsigned long size;
  int *err;
  int err;
  uint *entry_9;
  unsigned long version;
  uint port;
  unsigned long tag;
  int *status;
  uint kind;
  uint64_t type_id;
  long addr;
  long off;
  unsigned long type_id_8;
  long base;
  uint *entry_10;
  int *flags;
  long ctx_val;
  long serial;
  long scratch;
  
  if (handle == 0) {
    type_id = 0xad001;
  }
  else {
    ctx_val = *(long *)(handle + 0x120);
    if ((((ctx_val == 0) || (base = *(long *)(handle + 0x1b0), base == 0)) ||
        (entry_10 = *(uint **)(handle + 8), entry_10 == (uint *)0x0)) ||
       ((serial = *(long *)(handle + 0x10), serial == 0 ||
        (addr = *(long *)(handle + 0x170), addr == 0)))) {
      type_id = 0x930009;
    }
    else {
      type_id = 0x930009;
      if (*(long *)(handle + 0x1a8) != 0) {
        off = *(long *)(handle + 0x50);
        port = *(uint *)(base + 0x4c);
        handle = coruna_fixup_slide_base(handle);
        type_id = 0x930008;
        if (handle != 0) {
          if (port != 0) {
            obj = (uint *)(ctx_val + (unsigned long)*(uint *)(base + 0x48));
            if (obj < entry_10) {
              return 0x930003;
            }
            ptr = (uint *)(serial + (long)entry_10);
            if (ptr <= obj) {
              return 0x930003;
            }
            entry = obj + (unsigned long)port * 2;
            entry_9 = (uint *)((long)entry - 1);
            if (entry_9 < entry_10) {
              return 0x930003;
            }
            if (ptr <= entry_9) {
              return 0x930003;
            }
            do {
              port = *obj;
              tag = (unsigned long)port;
              if ((int)port < 0) {
                if ((~port & 0x30000000) != 0) {
                  return 0x930002;
                }
                if ((port & 0xf000000) != 0) {
                  return 0x930002;
                }
                tag = tag & 0xffffff;
fail:
                ptr = (long *)(handle + tag);
                if (ptr < *(long **)(handle + 8) ||
                    (long *)(*(long *)(handle + 0x10) + (long)*(long **)(handle + 8)) <= ptr) {
                  return 0x930001;
                }
                *ptr = *ptr + off;
              }
              else if ((obj[1] & 0xffffff) != 0) {
                if ((obj[1] & 0xf6000000) != 0x6000000) {
                  return 0x930002;
                }
                goto fail;
              }
              obj = obj + 2;
            } while (obj < entry);
            ctx_val = *(long *)(handle + 0x120);
            if (ctx_val == 0) {
              return 0x910012;
            }
            entry_10 = *(uint **)(handle + 8);
            if (entry_10 == (uint *)0x0) {
              return 0x910012;
            }
          }
          if (*(long *)(handle + 0x10) == 0) {
            type_id = 0x910012;
          }
          else {
            port = *(uint *)(base + 0x44);
            if (port != 0) {
              obj = (uint *)(ctx_val + (unsigned long)*(uint *)(base + 0x40));
              if (obj < entry_10) {
                return 0x91000a;
              }
              ptr = (uint *)(*(long *)(handle + 0x10) + (long)entry_10);
              if (ptr <= obj) {
                return 0x91000a;
              }
              entry = (uint *)((long)obj + (unsigned long)port * 8 + -1);
              if (entry < entry_10) {
                return 0x91000a;
              }
              if (ptr <= entry) {
                return 0x91000a;
              }
              u = *(uint *)(addr + 0x18);
              ctx_val = coruna_fixup_slide_base(handle);
              if (ctx_val == 0) {
                return 0x930008;
              }
              tag = 0;
              scratch = 0;
              block = (unsigned long *)0x0;
              do {
                if ((obj[tag * 2 + 1] & 0xf6000000) != 0x6000000) {
                  return 0x910002;
                }
                buf = (unsigned long *)(ctx_val + (int)obj[tag * 2]);
                data = *(unsigned long **)(handle + 8);
                str = (unsigned long *)(*(long *)(handle + 0x10) + (long)data);
                if (buf < data || str <= buf) {
                  return 0x910002;
                }
                base = *(long *)(handle + 0x1a8);
                version = (unsigned long)obj[tag * 2 + 1] & 0xffffff;
                copy = (unsigned long *)(base + version * 0x10);
                if (copy < data || str <= copy) {
                  return 0x910002;
                }
                size = *buf;
                type_id_8 = size;
                if ((u >> 4 & 1) != 0) {
                  serial = base + version * 0x10;
                  if (((~*(byte *)(serial + 4) & 0xe) == 0) &&
                     ((*(ushort *)(serial + 6) >> 7 & 1) != 0)) {
                    base = base + version * 0x10;
                    version = size - *(long *)(base + 8);
                    type_id_8 = version;
                    if (version != 0) {
                      err = *(int *)(*(long *)(handle + 0x170) + 0x10);
                      if (err == 0) {
done:
                        type_id_8 = 0;
                      }
                      else {
                        err = *(byte *)(base + 5);
                        status = (int *)(*(long *)(handle + 0x148) + 0x20);
                        kind = 1;
                        do {
                          if (*status == 0x19) {
                            if (((kind & 0xff) <= (uint)err) &&
                               ((uint)err < status[0x10] + (kind & 0xff))) {
                              err = (uint)err - (kind & 0xff);
                              if ((size < *(unsigned long *)(status + (long)err * 0x14 + 0x1a)) ||
                                 (type_id_8 = version,
                                 *(long *)(status + (long)err * 0x14 + 0x1c) +
                                 *(unsigned long *)(status + (long)err * 0x14 + 0x1a) <= size))
                              goto done;
                              break;
                            }
                            kind = kind + status[0x10];
                          }
                          status = (int *)((long)status + (unsigned long)(uint)status[1]);
                          err = err + -1;
                          type_id_8 = 0;
                        } while (err != 0);
                      }
                    }
                  }
                  else {
                    type_id_8 = size - *(long *)(serial + 8);
                  }
                }
                if ((copy != block) &&
                   (type_id = coruna_csops_18e40_2(handle,copy,&scratch,0), (int)type_id != 0)) {
                  return type_id;
                }
                if (((u >> 4 & 1) == 0) || (*buf != scratch + type_id_8)) {
                  *buf = scratch + type_id_8;
                }
                tag = tag + 1;
                block = copy;
              } while (tag != port);
            }
            if ((((*(long *)(handle + 0x148) == 0) || (*(long *)(handle + 0x120) == 0)) ||
                (*(long *)(handle + 0x1b0) == 0)) ||
               ((*(long *)(handle + 8) == 0 || (*(long *)(handle + 0x10) == 0)))) {
              type_id = 0x910011;
            }
            else {
              type_id = 0x910011;
              if (*(long *)(handle + 0x1a8) != 0) {
                ctx_val = *(long *)(handle + 0x170);
                if (*(int *)(ctx_val + 0x10) == 0) {
                  type_id = 0;
                }
                else {
                  port = 0;
                  base = *(long *)(handle + 0x120) +
                           (unsigned long)*(uint *)(*(long *)(handle + 0x1b0) + 0x38);
                  serial = *(long *)(handle + 8) - *(long *)(handle + 0x168);
                  status = (int *)(*(long *)(handle + 0x148) + 0x20);
                  do {
                    if (*status == 0x19) {
                      flags = status + 0x12;
                      err = flags + (unsigned long)(uint)status[0x10] * 0x14;
                      if (flags < err) {
cleanup:
                        if ((flags[0x10] & 0xfeU) != 6 || *(unsigned long *)(flags + 10) < 8) {
                          type_id = 0;
check_ok:
                          flags = flags + 0x14;
                          if ((err <= flags) || ((int)type_id != 0)) goto skip;
                          goto cleanup;
                        }
                        u = flags[0x11];
                        tag = base + (unsigned long)u * 4;
                        type_id_8 = *(unsigned long *)(handle + 8);
                        version = *(long *)(handle + 0x10) + type_id_8;
                        if ((type_id_8 <= tag && tag < version) &&
                           (size = *(unsigned long *)(flags + 10) >> 3,
                           tag = (base + (size + u) * 4) - 4,
                           type_id_8 <= tag && tag < version)) {
                          tag = 0;
                          ctx_val = *(long *)(flags + 8) + serial;
                          do {
                            kind = *(uint *)(base + (unsigned long)(u + (int)tag) * 4);
                            if (kind == 0x40000000) {
                              type_id = 0;
                            }
                            else if (kind == 0x80000000) {
                              type_id = 0;
                              *(long *)(ctx_val + tag * 8) =
                                   *(long *)(ctx_val + tag * 8) + serial;
                            }
                            else {
                              version = *(long *)(handle + 0x1a8) + (unsigned long)kind * 0x10;
                              if (version < *(unsigned long *)(handle + 8) ||
                                  *(long *)(handle + 0x10) + *(unsigned long *)(handle + 8) <= version) {
                                type_id = 0x910004;
                                goto skip;
                              }
                              scratch = 0;
                              type_id = coruna_csops_18e40_2(handle,version,&scratch,1);
                              if ((int)type_id == 0) {
                                *(long *)(ctx_val + tag * 8) = scratch;
                              }
                            }
                            tag = tag + 1;
                          } while (((tag & 0xffffffff) < size) && ((int)type_id == 0));
                          goto check_ok;
                        }
                        type_id = 0x910005;
skip:
                        ctx_val = *(long *)(handle + 0x170);
                      }
                      else {
                        type_id = 0;
                      }
                    }
                    else {
                      type_id = 0;
                    }
                    status = (int *)((long)status + (unsigned long)(uint)status[1]);
                    port = port + 1;
                  } while (port < *(uint *)(ctx_val + 0x10) && (int)type_id == 0);
                }
              }
            }
          }
        }
      }
    }
  }
  return type_id;
}





long coruna_fixup_slide_base(long handle)
{
  long handle;
  int *err;
  int err;
  
  if (handle == 0) {
fail:
    handle = 0;
  }
  else {
    err = (int *)(*(long *)(handle + 0x148) + 0x20);
    err = *(int *)(*(long *)(handle + 0x170) + 0x10) + 1;
    do {
      err = err + -1;
      if (err == 0) goto fail;
      if ((*err == 0x19) && ((*(byte *)(err + 0xf) >> 1 & 1) != 0)) {
        handle = *(long *)(handle + 0x18) + *(long *)(err + 6);
      }
      else {
        handle = 0;
      }
      err = (int *)((long)err + (unsigned long)(uint)err[1]);
    } while (handle == 0);
  }
  return handle;
}





unsigned long coruna_csops_18e40_2(long arg,uint *val,unsigned long *n,int m)

{
  uint u;
  ushort size;
  unsigned long version;
  unsigned long type_id;
  unsigned long cache_88;
  
  version = 0xad001;
  u = 0x910003;
  if (m == 0) {
    u = 0x910001;
  }
  type_id = (unsigned long)u;
  if (((arg != 0) && (val != (uint *)0x0)) && (n != (unsigned long *)0x0)) {
    if (((~(byte)val[1] & 0xe) == 0) &&
       (size = *(ushort *)((long)val + 6),
       ((byte)val[1] & 0x10) != 0 || (size & 0x80) != 0)) {
      version = *(long *)(arg + 8) + *(long *)(val + 2);
      *n = version;
      if ((size >> 3 & 1) == 0) {
        version = 0;
      }
      else {
        *n = version | 1;
        version = 0;
      }
    }
    else {
      version = type_id;
      if (*(long *)(arg + 0x1b8) != 0) {
        type_id = *(long *)(arg + 0x1b8) + (unsigned long)*val;
        if ((*(unsigned long *)(arg + 8) <= type_id) &&
           (type_id < *(long *)(arg + 0x10) + *(unsigned long *)(arg + 8))) {
          cache_88 = 0;
          type_id = coruna_objc_empty_vtable_162d8(arg,0,type_id,0,0,&cache_88);
          if (((int)type_id != 0x910006) && (version = type_id, (int)type_id == 0)) {
            *n = cache_88;
          }
        }
      }
    }
  }
  return version;
}





uint64_t coruna_persistb080_via_macho_seg19_offset(long handle)
{
  unsigned long *ptr;
  byte *ptr;
  long *buf;
  uint *buf;
  uint *str;
  uint *copy;
  uint *data;
  uint *obj;
  void (*ptr)(void);
  long *str;
  uint *block;
  byte err;
  short ls13;
  uint *entry;
  bool status;
  long *copy;
  uint64_t u;
  void *data;
  uint size;
  uint version;
  unsigned long port;
  unsigned long tag;
  unsigned long kind;
  long handle;
  uint type_id;
  byte *obj;
  uint64_t type_id_8;
  unsigned long type_id_9;
  int err;
  long addr;
  long off;
  void *block;
  byte *entry;
  byte *entry_9;
  unsigned long type_id_10;
  long base;
  int status;
  unsigned long scratch;
  uint *bootargs;
  
  type_id_8 = 0xad001;
  if (handle == 0) {
    return 0xad001;
  }
  handle = *(long *)(handle + 0x188);
  if (handle != 0) {
    off = *(long *)(handle + 0x120);
    if (off == 0) {
      return 0xad001;
    }
    addr = *(long *)(handle + 0x40);
    base = *(long *)(handle + 0x168);
    size = *(uint *)(handle + 8);
    type_id = *(uint *)(handle + 0xc);
    copy = (long *)coruna_macho_seg19_offset(handle,0,0);
    if (copy == (long *)0x0) {
      return 0x930004;
    }
    if (type_id == 0) {
switchD_00012d88_caseD_0:
      ptr = coruna_persistb080_via_objc_empty_vtable_162d8;
      if (*(char *)(handle + 0x138) != '\0') {
        ptr = coruna_persistb080_residual_150;
      }
      type_id_8 = coruna_persistb080_via_block_dispose_157f4(handle,ptr,0);
      if ((int)type_id_8 == 0) {
        if ((*(ushort *)(handle + 0x1c0) >> 7 & 1) == 0) {
          type_id_8 = coruna_helper_dc18_137d8(handle,ptr,0);
          return type_id_8;
        }
        return 0;
      }
      return type_id_8;
    }
    addr = addr - base;
    entry_9 = (byte *)(off + (unsigned long)size);
    ptr = entry_9 + type_id;
    type_id_9 = 1;
fail:
    entry = entry_9 + 1;
    err = *entry_9 >> 4;
    if (8 < err) {
      return 0x930005;
    }
    port = (unsigned long)*entry_9 & 0xf;
    status = (int)type_id_9;
    err = (int)addr;
    type_id_10 = port;
    entry_9 = entry;
    switch(err) {
    case 0:
      break;
    case 1:
      break;
    case 2:
      copy = (long *)coruna_macho_seg19_offset(handle,port,0);
      if (copy == (long *)0x0) {
        return 0x930004;
      }
      port = 0;
      type_id_10 = 0;
      obj = entry;
      do {
        port = 0;
        entry_9 = entry;
        copy = (long *)(port + (long)copy);
        type_id_10 = type_id_9;
        entry_9 = obj + 1;
        err = *obj;
        kind = ((unsigned long)err & 0x7f) << (type_id_10 & 0x3f);
        if (0x3f < (uint)type_id_10) {
          kind = 0;
        }
        port = kind | port;
        type_id_10 = (unsigned long)((uint)type_id_10 + 7);
        obj = entry_9;
      } while ((char)err < '\0');
      copy = (long *)(port + (long)copy);
      type_id_10 = type_id_9;
    case 3:
      port = 0;
      type_id_10 = 0;
      obj = entry;
      do {
        port = 0;
        entry_9 = entry;
        copy = (long *)(port + (long)copy);
        type_id_10 = type_id_9;
        entry_9 = obj + 1;
        err = *obj;
        kind = ((unsigned long)err & 0x7f) << (type_id_10 & 0x3f);
        if (0x3f < (uint)type_id_10) {
          kind = 0;
        }
        port = kind | port;
        type_id_10 = (unsigned long)((uint)type_id_10 + 7);
        obj = entry_9;
      } while ((char)err < '\0');
      copy = (long *)(port + (long)copy);
      type_id_10 = type_id_9;
    case 4:
      copy = copy + port;
      type_id_10 = type_id_9;
      break;
    case 5:
      size = (uint)port;
      while (type_id_10 = type_id_9, size != 0) {
        str = *(long **)(handle + 8);
        buf = (long *)(*(long *)(handle + 0x10) + (long)str);
        if ((buf < str || copy < str) || buf <= copy) {
          return 0x930003;
        }
        if (status == 2) {
          *(int *)copy = (int)*copy + err;
        }
        else {
          if (status != 1) {
            return 0x930007;
          }
          *copy = *copy + addr;
        }
        copy = copy + 1;
        size = (int)port - 1;
        port = (unsigned long)size;
      }
      break;
    case 6:
      port = 0;
      kind = 0;
      obj = entry;
      do {
        type_id_10 = type_id_9;
        entry_9 = entry;
        break;
        entry_9 = obj + 1;
        err = *obj;
        type_id_10 = ((unsigned long)err & 0x7f) << (kind & 0x3f);
        if (0x3f < (uint)kind) {
          type_id_10 = 0;
        }
        port = type_id_10 | port;
        kind = (unsigned long)((uint)kind + 7);
        obj = entry_9;
      } while ((char)err < '\0');
      if (0xfffffffe < port) {
        return 0x930006;
      }
      type_id_10 = type_id_9;
      if (port != 0) {
        kind = 2;
        do {
          str = *(long **)(handle + 8);
          buf = (long *)(*(long *)(handle + 0x10) + (long)str);
          if ((buf < str || copy < str) || buf <= copy) {
            return 0x930003;
          }
          if (status == 2) {
            *(int *)copy = (int)*copy + err;
          }
          else {
            if (status != 1) {
              return 0x930007;
            }
            *copy = *copy + addr;
          }
          copy = copy + 1;
          status = kind <= port;
          kind = (unsigned long)((int)kind + 1);
        } while (status);
      }
      break;
    case 7:
      str = *(long **)(handle + 8);
      buf = (long *)(*(long *)(handle + 0x10) + (long)str);
      if ((buf < str || copy < str) || buf <= copy) {
        return 0x930003;
      }
      if (status == 2) {
        *(int *)copy = (int)*copy + err;
      }
      else {
        if (status != 1) {
          return 0x930007;
        }
        *copy = *copy + addr;
      }
      port = 0;
      type_id_10 = 0;
      obj = entry;
      do {
        if (ptr <= obj) {
          port = 0;
          entry_9 = entry;
          break;
        }
        entry_9 = obj + 1;
        err = *obj;
        kind = ((unsigned long)err & 0x7f) << (type_id_10 & 0x3f);
        if (0x3f < (uint)type_id_10) {
          kind = 0;
        }
        port = kind | port;
        type_id_10 = (unsigned long)((uint)type_id_10 + 7);
        obj = entry_9;
      } while ((char)err < '\0');
      copy = (long *)((long)copy + port + 8);
      type_id_10 = type_id_9;
      break;
    case 8:
      port = 0;
      type_id_10 = 0;
      do {
        if (ptr <= entry_9) {
          port = 0;
          obj = entry;
          break;
        }
        obj = entry_9 + 1;
        err = *entry_9;
        kind = ((unsigned long)err & 0x7f) << (type_id_10 & 0x3f);
        if (0x3f < (uint)type_id_10) {
          kind = 0;
        }
        port = kind | port;
        type_id_10 = (unsigned long)((uint)type_id_10 + 7);
        entry_9 = obj;
      } while ((char)err < '\0');
      kind = 0;
      type_id_10 = 0;
      entry = obj;
      do {
        if (ptr <= entry) {
          kind = 0;
          entry_9 = obj;
          break;
        }
        entry_9 = entry + 1;
        err = *entry;
        tag = ((unsigned long)err & 0x7f) << (type_id_10 & 0x3f);
        if (0x3f < (uint)type_id_10) {
          tag = 0;
        }
        kind = tag | kind;
        type_id_10 = (unsigned long)((uint)type_id_10 + 7);
        entry = entry_9;
      } while ((char)err < '\0');
      if (0xfffffffe < port) {
        return 0x930006;
      }
      type_id_10 = type_id_9;
      if (port != 0) {
        tag = 2;
        do {
          str = *(long **)(handle + 8);
          buf = (long *)(*(long *)(handle + 0x10) + (long)str);
          if ((buf < str || copy < str) || buf <= copy) {
            return 0x930003;
          }
          if (status == 2) {
            *(int *)copy = (int)*copy + err;
          }
          else {
            if (status != 1) {
              return 0x930007;
            }
            *copy = *copy + addr;
          }
          status = tag <= port;
          tag = (unsigned long)((int)tag + 1);
          copy = (long *)((long)copy + kind + 8);
        } while (status);
      }
    }
    break;
  }
  if (*(long *)(handle + 0x198) == 0) {
    return 0x910010;
  }
  bootargs = (uint *)0x0;
  u = coruna_block_dispose_157f4(handle,*(uint32_t *)(*(long *)(handle + 0x198) + 8),&bootargs);
  entry = bootargs;
  if ((int)u != 0) {
    return u;
  }
  block = *(uint **)(handle + 8);
  buf = (uint *)(*(long *)(handle + 0x10) + (long)block);
  if (buf < block) {
    return 0x920006;
  }
  if (bootargs < block) {
    return 0x920006;
  }
  if (buf <= bootargs) {
    return 0x920006;
  }
  size = *(uint *)(*(long *)(handle + 0x198) + 0xc);
  str = (uint *)((unsigned long)size + (long)bootargs);
  if ((str < bootargs || str < block) || buf < str) {
    return 0x920006;
  }
  if (((*bootargs == 0) && (0x1b < bootargs[1])) && (bootargs[1] < size)) {
    type_id = bootargs[4];
    type_id_9 = (unsigned long)type_id;
    if (type_id == 0) {
      if (bootargs[6] != 0) {
        return 0x920003;
      }
      type_id_9 = 0;
      data = (void *)0x0;
joined_r0x000133a0:
      bootargs = entry;
      if ((entry != (uint *)0x0) && (size != 0)) {
        buf = (uint *)((long)entry + (unsigned long)entry[1]);
        type_id = *buf;
        if (type_id == 0) {
          type_id_8 = 0;
        }
        else {
          scratch = 0;
          block = (uint *)((long)entry + (unsigned long)size);
          do {
            if (buf[scratch + 1] != 0) {
              type_id_8 = 0x920006;
              if ((block < entry) ||
                 (str = (uint *)((long)buf + (unsigned long)buf[scratch + 1]),
                 (((str < entry || block <= str) || (uint *)0xffffffffffffffe7 < str)
                 || str + 6 < entry) || block < str + 6)) break;
              copy = (uint *)((unsigned long)*str + (long)str);
              if ((copy < str || copy < entry) || block < copy) {
check_ok:
                type_id_8 = 0x920006;
                break;
              }
              port = 0;
              while (port < (ushort)str[5]) {
                copy = (uint *)((long)str + port * 2 + 0x16);
                data = (uint *)((unsigned long)*str + (long)str);
                if (((((data < str || copy < str) || data <= copy) ||
                     (uint *)0xfffffffffffffffc < copy) &&
                     (((data < str || copy < str) || data <= copy) ||
                     copy != (uint *)0xfffffffffffffffd) || (uint *)((long)copy + 2U) < str)
                    type_id_8 = 0x920006;
                    break;
                ls13 = (short)*copy;
                if (ls13 == -1) {
                  type_id_8 = 0;
                }
                else if (ls13 < 0) {
                  obj = (uint *)((long)str + ((long)ls13 & 0x7fffU) * 2 + 0x16);
                  copy = (uint *)((long)obj + 2);
                  if ((((obj < str || data <= obj) || (uint *)0xfffffffffffffffd < obj
                       type_id_8 = 0x920006;
                       break;
                  while( true ) {
                    size = *obj;
                    type_id_8 = coruna_return_zero_e288(handle,data,(uint)type_id_9 & 0xffff,str,port,
                                          (ushort)size & 0x7fff);
                    if (((int)type_id_8 != 0) || ((short)(ushort)size < 0)) break;
                    data = (uint *)((unsigned long)*str + (long)str);
                    type_id_8 = 0x920006;
                    break;
                  }
                }
                else {
                  type_id_8 = coruna_return_zero_e288(handle,data,(uint)type_id_9 & 0xffff,str,port,ls13);
                }
                port = port + 1;
                if ((int)type_id_8 != 0) goto skip;
              }
              type_id = *buf;
            }
            type_id_8 = 0;
            scratch = scratch + 1;
          } while (scratch < type_id);
        }
      }
skip:
      if (data == (void *)0x0) {
        return type_id_8;
      }
      if ((type_id_9 & 0xffff) == 0) {
        return type_id_8;
      }
      type_id_9 = type_id_9 & 0xffff;
      u = type_id_8;
    }
    else {
      if (((bootargs[2] < 0x1c) || (size <= bootargs[2])) ||
         ((bootargs[3] < 0x1c || (size <= bootargs[3])))) goto next;
      if (bootargs[6] != 0) {
        return 0x920003;
      }
      if (type_id >> 0x10 != 0) {
        return 0xad001;
      }
      data = _calloc(type_id_9,8);
      if (data == (void *)0x0) {
        return 0xad009;
      }
      type_id_10 = 0;
      size = entry[3];
      block = data;
      port = 1;
      do {
        type_id = entry[5];
        if (type_id == 3) {
          ptr = (unsigned long *)((long)entry + type_id_10 + entry[2]);
          kind = *ptr;
          tag = ptr[1];
          type_id = (uint)kind & 0xffff;
          version = (int)(short)kind;
          if (type_id < 0xfff1) {
            version = type_id;
          }
          handle = (long)entry + (kind >> 0x20) + (unsigned long)size;
          kind = kind >> 0x10 & 1;
          err = 0x10;
        }
        else if (type_id == 2) {
          buf = (uint *)((long)entry + type_id_10 + entry[2]);
          type_id = *buf;
          tag = (unsigned long)(int)buf[1];
          version = (int)(char)type_id;
          if ((type_id & 0xff) < 0xf1) {
            version = type_id & 0xff;
          }
          handle = (long)entry + (unsigned long)(type_id >> 9) + (unsigned long)size;
          kind = (unsigned long)(type_id >> 8 & 1);
          err = 8;
        }
        else {
          if (type_id != 1) {
            u = 0x920004;
            goto retry;
          }
          tag = 0;
          type_id = *(uint *)((long)entry + type_id_10 + entry[2]);
          version = (int)(char)type_id;
          if ((type_id & 0xff) < 0xf1) {
            version = type_id & 0xff;
          }
          handle = (long)entry + (unsigned long)(type_id >> 9) + (unsigned long)size;
          kind = (unsigned long)(type_id >> 8 & 1);
          err = 4;
        }
        u = coruna_objc_empty_vtable_162d8(handle,version,handle,tag,kind,block);
        if ((int)u != 0) goto retry;
        u = coruna_persistb080_via_dladdr_1bd4c(handle,block);
        if ((int)u != 0) break;
        type_id_10 = (unsigned long)(uint)(err + (int)type_id_10);
        block = (void *)((long)block + 8);
        status = port < type_id_9;
        port = port + 1;
      } while (status);
      if ((int)u == 0) {
        size = *(uint *)(*(long *)(handle + 0x198) + 0xc);
        entry = bootargs;
        goto joined_r0x000133a0;
      }
    }
retry:
    _bzero(data,type_id_9 << 3);
    _free(data);
  }
  else {
next:
    u = 0x920003;
  }
  return u;
}





uint64_t coruna_persistb080_residual_150(long handle,long addr_2)
{
  uint64_t u;
  
  if (((handle != 0) && (addr_2 != 0)) && (*(long *)(addr_2 + 8) != 0)) {
    u = coruna_persistb080_residual_154();
    return u;
  }
  return 0xad001;
}





uint64_t coruna_persistb080_via_objc_empty_vtable_162d8(long handle,uint64_t *val)
{
  int *err;
  int *status;
  char err;
  uint64_t u;
  int *flags;
  int *count;
  uint64_t scratch;
  
  u = 0xad001;
  scratch = 0;
  if ((((handle != 0) && (val != (uint64_t *)0x0)) && (val[1] != 0)) &&
     (u = coruna_objc_empty_vtable_162d8(handle,*(uint32_t *)((long)val + 0x24),val[1],val[3],
                           *(byte *)(val + 2) & 1,&scratch), (int)u == 0)) {
    count = (int *)*val;
    status = *(int **)(handle + 0x40);
    err = (int *)(*(long *)(handle + 0x48) + (long)status);
    if (((((*(ushort *)(handle + 0x1c0) >> 7 & 1) == 0) ||
         (flags = (int *)val[5], flags == (int *)0x0)) ||
        ((*(uint *)(val + 6) == 0 ||
         ((flags + (unsigned long)*(uint *)(val + 6) * 2 < flags || (count < flags)))))) ||
       (flags + (unsigned long)*(uint *)(val + 6) * 2 <= count)) {
      if ((err < status || count < status) || err <= count) {
        return 0x910007;
      }
    }
    else {
      u = coruna_persistb080_via_dladdr_1bd4c(handle,&scratch);
      if ((int)u != 0) {
        return u;
      }
    }
    err = *(char *)(val + 4);
    if (err == '\x03') {
      u = 0;
      *count = ((int)scratch - (int)count) + -4;
    }
    else if (err == '\x02') {
      u = 0;
      *count = (int)scratch;
    }
    else if (err == '\x01') {
      u = 0;
      *(uint64_t *)count = scratch;
    }
    else {
      u = 0x91000e;
    }
  }
  return u;
}





uint64_t coruna_persistb080_via_block_dispose_157f4(long handle,long addr_2,uint64_t val)
{
  uint64_t u;
  long handle;
  long scratch;
  
  u = 0xad001;
  if ((handle != 0) && (handle = *(long *)(handle + 0x188), handle != 0 && addr_2 != 0)) {
    if (*(int *)(handle + 0x14) == 0) {
      u = 0;
    }
    else {
      scratch = 0;
      u = coruna_block_dispose_157f4(handle,*(uint32_t *)(handle + 0x10),&scratch);
      if ((int)u == 0) {
        u = coruna_persistb080_via_u64_pack_2(handle,0,scratch,
                             scratch + (unsigned long)*(uint *)(*(long *)(handle + 0x188) + 0x14),addr_2,
                             val);
      }
    }
  }
  return u;
}





uint64_t coruna_helper_dc18_137d8(long handle,long addr_2,uint64_t val)
{
  uint64_t u;
  long handle;
  long scratch;
  
  u = 0xad001;
  if ((handle != 0) && (handle = *(long *)(handle + 0x188), handle != 0 && addr_2 != 0)) {
    if (*(int *)(handle + 0x24) == 0) {
      u = 0;
    }
    else {
      scratch = 0;
      u = coruna_block_dispose_157f4(handle,*(uint32_t *)(handle + 0x20),&scratch);
      if ((int)u == 0) {
        u = coruna_persistb080_via_u64_pack_2(handle,1,scratch,
                             scratch + (unsigned long)*(uint *)(*(long *)(handle + 0x188) + 0x24),addr_2,
                             val);
      }
    }
  }
  return u;
}





uint64_t coruna_persistb080_via_persistb080_via_block_dispose_157f4(long handle,long addr_2,uint64_t val)
{
  uint64_t u;
  
  u = 0xad001;
  if ((handle != 0) && (addr_2 != 0)) {
    if (*(long *)(handle + 0x188) == 0) {
      u = 0;
    }
    else {
      u = coruna_persistb080_via_block_dispose_157f4(handle,addr_2);
      if ((int)u == 0) {
        u = coruna_helper_dc18_137d8(handle,addr_2,val);
        return u;
      }
    }
  }
  return u;
}





unsigned long coruna_persistb080_via_u64_pack_2(long arg,byte val,byte *n,byte *m,void (*p,
                  uint64_t q)

{
  bool status;
  uint size;
  byte flags;
  long handle;
  uint32_t port;
  byte *obj;
  byte *block;
  unsigned long type_id_8;
  unsigned long type_id_14;
  byte *entry;
  unsigned long type_id_12;
  unsigned long type_id_9;
  byte count;
  long cache_89;
  byte *cache_90;
  uint64_t cache_54;
  unsigned long bootargs;
  uint64_t host_info;
  void *serial_buf;
  unsigned long cache_20;
  
  type_id_12 = 0xad001;
  if ((((arg != 0) && (n != (byte *)0x0)) && (m != (byte *)0x0)) &&
     ((n <= m && (p != (void (*)0x0)))) {
    bootargs = 0;
    cache_54 = 0;
    serial_buf = (void *)0x0;
    cache_90 = (byte *)0x0;
    cache_89 = 0;
    host_info = 1;
    cache_20 = (unsigned long)val << 0x20;
    if (n < m) {
      handle = 0;
      count = 0;
      do {
        entry = n + 1;
        flags = *n;
        if (0xc < flags >> 4) {
          type_id_12 = 0x91000d;
          if (serial_buf == (void *)0x0) {
          return type_id_12;
          }
          _bzero(serial_buf,(cache_20 & 0xffffffff) << 3);
          _free(serial_buf);
          return type_id_12;
        }
        type_id_9 = (unsigned long)flags & 0xf;
        n = entry;
        switch(flags >> 4) {
        case 0:
          type_id_12 = 0;
          count = val ^ 1 | count;
          break;
        case 1:
          type_id_12 = 0;
          host_info = coruna_u64_pack(((int)type_id_9), ((uint32_t))host_info);
          break;
        case 2:
          type_id_12 = 0;
          type_id_9 = 0;
          obj = entry;
          do {
            if (m <= obj) {
              port = 0;
              n = entry;
              break;
            }
            n = obj + 1;
            flags = *obj;
            type_id_8 = ((unsigned long)flags & 0x7f) << (type_id_9 & 0x3f);
            if (0x3f < (uint)type_id_9) {
              type_id_8 = 0;
            }
            type_id_12 = type_id_8 | type_id_12;
            port = (uint32_t)type_id_12;
            type_id_9 = (unsigned long)((uint)type_id_9 + 7);
            obj = n;
          } while ((char)flags < '\0');
          host_info = coruna_u64_pack((port), ((uint32_t))host_info);
          type_id_12 = 0;
          break;
        case 3:
          type_id_12 = 0;
          if ((int)type_id_9 == 0) {
            host_info = host_info & 0xffffffff;
          }
          else {
            host_info = coruna_u64_pack(((int)(char)flags), ((uint32_t))host_info) | 0xfffffff000000000;
          }
          break;
        case 4:
          obj = entry;
          do {
            if (obj == m) {
              n = entry;
              entry = (byte *)0x0;
              break;
            }
            n = obj + 1;
            flags = *obj;
            obj = n;
          } while (flags != 0);
          cache_54 = coruna_u64_pack71((cache_54), ((char))type_id_9);
          size = 0x91000c;
          if (entry != (byte *)0x0) {
            size = 0;
          }
          type_id_12 = (unsigned long)size;
          cache_90 = entry;
          break;
        case 5:
          type_id_12 = 0;
          host_info = coruna_u64_pack71((host_info), ((char))type_id_9);
          break;
        case 6:
          bootargs = 0;
          type_id_12 = 0;
          obj = entry;
          do {
            if (m <= obj) {
              bootargs = 0;
              n = entry;
              type_id_12 = 0;
              break;
            }
            n = obj + 1;
            flags = *obj;
            type_id_9 = ((unsigned long)flags & 0x7f) << (type_id_12 & 0x3f);
            if (0x3f < (uint)type_id_12) {
              type_id_9 = 0;
            }
            bootargs = type_id_9 | bootargs;
            type_id_12 = (unsigned long)((uint)type_id_12 + 7);
            obj = n;
          } while ((char)flags < '\0');
          if ((flags & 0x40) != 0) {
            bootargs = 0xffffffffffffffff;
          }
load_ok_20:
          type_id_12 = 0;
          break;
        case 7:
          handle = coruna_macho_seg19_offset(arg,type_id_9,1);
          if (handle != 0) {
            type_id_12 = 0;
            type_id_9 = 0;
            obj = entry;
            do {
              if (m <= obj) {
                type_id_12 = 0;
                n = entry;
                break;
              }
              n = obj + 1;
              flags = *obj;
              type_id_8 = ((unsigned long)flags & 0x7f) << (type_id_9 & 0x3f);
              if (0x3f < (uint)type_id_9) {
                type_id_8 = 0;
              }
              type_id_12 = type_id_8 | type_id_12;
              type_id_9 = (unsigned long)((uint)type_id_9 + 7);
              obj = n;
            } while ((char)flags < '\0');
            handle = type_id_12 + handle;
            type_id_12 = 0;
            cache_89 = handle;
            break;
          }
          type_id_12 = 0x910009;
load_ok_18:
          if (serial_buf == (void *)0x0) {
            return type_id_12;
          }
          _bzero(serial_buf,(cache_20 & 0xffffffff) << 3);
          _free(serial_buf);
          return type_id_12;
        case 8:
          type_id_12 = 0;
          type_id_9 = 0;
          obj = entry;
          do {
            if (m <= obj) {
              type_id_12 = 0;
              n = entry;
              break;
            }
            n = obj + 1;
            flags = *obj;
            type_id_8 = ((unsigned long)flags & 0x7f) << (type_id_9 & 0x3f);
            if (0x3f < (uint)type_id_9) {
              type_id_8 = 0;
            }
            type_id_12 = type_id_8 | type_id_12;
            type_id_9 = (unsigned long)((uint)type_id_9 + 7);
            obj = n;
          } while ((char)flags < '\0');
          handle = handle + type_id_12;
          cache_89 = handle;
load_ok_19:
          type_id_12 = 0;
          break;
        case 9:
          type_id_12 = (*p)(arg,&cache_89,q);
          handle = cache_89 + 8;
          cache_89 = handle;
          break;
        case 10:
          type_id_12 = (*p)(arg,&cache_89,q);
          if (serial_buf == (void *)0x0) {
          return type_id_12;
          }
          _bzero(serial_buf,(cache_20 & 0xffffffff) << 3);
          _free(serial_buf);
          return type_id_12;
          type_id_12 = 0;
          type_id_9 = 0;
          obj = entry;
          do {
            if (m <= obj) {
              type_id_12 = 0;
              n = entry;
              break;
            }
            n = obj + 1;
            flags = *obj;
            type_id_8 = ((unsigned long)flags & 0x7f) << (type_id_9 & 0x3f);
            if (0x3f < (uint)type_id_9) {
              type_id_8 = 0;
            }
            type_id_12 = type_id_8 | type_id_12;
            type_id_9 = (unsigned long)((uint)type_id_9 + 7);
            obj = n;
          } while ((char)flags < '\0');
          handle = type_id_12 + cache_89 + 8;
load_ok_21:
          type_id_12 = 0;
          cache_89 = handle;
          break;
        case 0xb:
          type_id_12 = (*p)(arg,&cache_89,q);
          cache_89 = cache_89 + type_id_9 * 8;
load_ok_22:
          handle = cache_89 + 8;
          cache_89 = handle;
          break;
        case 0xc:
          type_id_9 = 0;
          type_id_12 = 0;
          obj = entry;
          do {
            if (m <= obj) {
              type_id_9 = 0;
              block = entry;
              break;
            }
            block = obj + 1;
            flags = *obj;
            type_id_8 = ((unsigned long)flags & 0x7f) << (type_id_12 & 0x3f);
            if (0x3f < (uint)type_id_12) {
              type_id_8 = 0;
            }
            type_id_9 = type_id_8 | type_id_9;
            type_id_12 = (unsigned long)((uint)type_id_12 + 7);
            obj = block;
          } while ((char)flags < '\0');
          type_id_8 = 0;
          type_id_12 = 0;
          entry = block;
          do {
            if (m <= entry) {
              type_id_8 = 0;
              n = block;
              break;
            }
            n = entry + 1;
            flags = *entry;
            type_id_14 = ((unsigned long)flags & 0x7f) << (type_id_12 & 0x3f);
            if (0x3f < (uint)type_id_12) {
              type_id_14 = 0;
            }
            type_id_8 = type_id_14 | type_id_8;
            type_id_12 = (unsigned long)((uint)type_id_12 + 7);
            entry = n;
          } while ((char)flags < '\0');
          if (0xfffffffe < type_id_9) {
            type_id_12 = 0x91000f;
            if (serial_buf == (void *)0x0) {
            return type_id_12;
            }
            _bzero(serial_buf,(cache_20 & 0xffffffff) << 3);
            _free(serial_buf);
            return type_id_12;
          }
          if (type_id_9 == 0) {
            type_id_12 = 0;
          }
          else {
            type_id_14 = 1;
            do {
              type_id_12 = (*p)(arg,&cache_89,q);
              handle = type_id_8 + 8 + cache_89;
              cache_89 = handle;
              if ((int)type_id_12 != 0) break;
              status = type_id_14 < type_id_9;
              type_id_14 = (unsigned long)((int)type_id_14 + 1);
            } while (status);
          }
        }
        if (serial_buf == (void *)0x0) {
        return type_id_12;
        }
        _bzero(serial_buf,(cache_20 & 0xffffffff) << 3);
        _free(serial_buf);
        return type_id_12;
      } while( true );
    }
    type_id_12 = 0;
  }
  return type_id_12;
}





uint64_t
void coruna_return_zero_e288(long handle,long addr_2,uint size,long off_3,int flags,uint flags_2)
{
  unsigned long *ptr;
  unsigned long *buf;
  ushort u;
  bool err;
  uint64_t size;
  uint64_t version;
  unsigned long port;
  unsigned long tag;
  long handle;
  unsigned long *scratch [2];
  
  size = 0xad001;
  if ((handle != 0) && (off_3 != 0)) {
    scratch[0] = (unsigned long *)0x0;
    size = coruna_block_dispose_157f4(handle,*(long *)(off_3 + 8) + (unsigned long)flags_2 +
                                 (unsigned long)((uint)*(ushort *)(off_3 + 4) * flags),scratch);
    if ((int)size == 0) {
      version = 0x920006;
      u = *(ushort *)(off_3 + 6);
      if ((u | 4) == 6) {
        size = 0xad001;
        if (scratch[0] != (unsigned long *)0x0) {
          buf = *(unsigned long **)(handle + 8);
          ptr = (unsigned long *)(*(long *)(handle + 0x10) + (long)buf);
          size = version;
          if ((((buf <= ptr) && (buf <= scratch[0])) && (scratch[0] < ptr)) &&
             (((scratch[0] < (unsigned long *)0xfffffffffffffff8 && (buf <= scratch[0] + 1)) &&
              (scratch[0] + 1 <= ptr)))) {
            do {
              port = *scratch[0];
              if ((long)port < 0) {
                if (size <= (uint)(port & 0xffffff)) {
                  return 0x920001;
                }
                tag = *(long *)(addr_2 + (port & 0xffffff) * 8) + (port >> 0x18 & 0xff);
              }
              else {
                if (u == 2) {
                  handle = *(long *)(handle + 0x50);
                }
                else {
                  handle = *(long *)(handle + 0x40);
                }
                tag = handle + (port & 0xfffffffff | (port >> 0x24) << 0x38);
              }
              *scratch[0] = tag;
              if ((port >> 0x33 & 0xfff) == 0) {
                return 0;
              }
              buf = *(unsigned long **)(handle + 8);
              ptr = (unsigned long *)(*(long *)(handle + 0x10) + (long)buf);
              if (ptr < buf) {
                return 0x920006;
              }
              scratch[0] = (unsigned long *)((long)scratch[0] +
                                     (unsigned long)(((uint)(port >> 0x33) & 0xfff) << 2));
              err = scratch[0] < buf;
            } while (((((!err && scratch[0] <= ptr) && (err || ptr != scratch[0])) &&
                       scratch[0] < (unsigned long *)0xfffffffffffffff7 ||
                      ((!err && scratch[0] <= ptr) && (err || ptr != scratch[0])) &&
                      scratch[0] == (unsigned long *)0xfffffffffffffff7) && buf <= scratch[0] + 1) &&
                     scratch[0] + 1 <= ptr);
          }
        }
      }
      else {
        size = 0x920005;
      }
    }
  }
  return size;
}





uint64_t coruna_persistb080_via_macho_text_seg(long handle,long addr_2,int flags)
{
  uint64_t u;
  long handle;
  uint64_t size;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t scratch;
  
  u = 0xad001;
  if ((((handle != 0) && (handle = *(long *)(handle + 0x38), handle != 0)) &&
      (*(long *)(handle + 0x40) != 0)) && ((*(long *)(handle + 0x48) != 0 && (addr_2 != 0)))) {
    if ((flags == 0x3c) || (flags == 0x28)) {
      size = *(uint64_t *)(addr_2 + 8);
      bootargs = 0;
      scratch = 0;
      scratch = size;
      if (((*(int *)(handle + 0x50) != 2) || (flags != 0x28)) ||
         (u = coruna_persistb080_via_ctx_free_11dc8(handle,handle,handle + 0x58), (int)u == 0)) {
        if (flags == 0x28) {
          (**(void (**)(handle + 0x40))(1,&bootargs,&scratch);
          if (*(int *)(handle + 0x50) == 1) {
            coruna_macho_text_seg(handle);
          }
        }
        else {
          (**(void (**)(handle + 0x48))(0,size);
        }
        u = 0;
      }
    }
    else {
      u = 0x1800b;
    }
  }
  return u;
}





uint32_t coruna_macho_text_seg(long handle)
{
  int err;
  byte err;
  int status;
  uint32_t u;
  long handle;
  long addr;
  int *err;
  unsigned long size;
  int flags;
  int *status;
  
  if (handle == 0) {
    u = 0xad001;
  }
  else {
    err = *(int *)(handle + 0x10);
    u = 0x18006;
    if (err != 0) {
      err = 0;
      flags = 0;
      handle = 0;
      addr = 0;
      status = (int *)(handle + 0x20);
      do {
        if (*status == 0x19) {
          status = _strcmp((char *)(status + 2),"__TEXT");
          if (status == 0) {
            handle = handle - *(long *)(status + 6);
            err = 1;
          }
          else {
            status = _strcmp((char *)(status + 2),"__DATA_DIRTY");
            if ((status == 0) && (size = (unsigned long)(uint)status[0x10], status[0x10] != 0)) {
              err = status + 0x12;
              do {
                status = _strcmp((char *)err,"__common");
                if (status == 0) {
                  addr = handle + *(long *)(err + 8);
                }
                err = err + 0x14;
                size = size - 1;
              } while (size != 0);
            }
          }
        }
        status = (int *)((long)status + (unsigned long)(uint)status[1]);
        flags = flags + 1;
      } while (flags != err);
      u = 0x1800c;
      if (!(bool)(err & addr != 0)) {
        u = 0x18006;
      }
    }
  }
  return u;
}

static uint64_t coruna_persist_libobjc_close(long handle, uint64_t rc, unsigned long host5)
{
  coruna_ctx_free_11dc8(host5);
  _dlclose(handle);
  return rc;
}

static uint64_t coruna_persist_libobjc_commit(long handle, uint port, unsigned long kind,
    unsigned long bootargs, unsigned long scratch, unsigned long host5)
{
  if (port < 0xf0000) {
    uint64_t rc = coruna_macho_text_seg(kind);
    if ((int)rc == 0x1800c) {
      *(uint32_t *)(handle + 0x50) = 2;
      rc = coruna_pthread_mutex_init(handle, handle + 0x58);
    }
    return coruna_persist_libobjc_close(handle, rc, host5);
  }
  *(uint32_t *)(handle + 0x50) = 0;
  *(long *)(handle + 0x28) = handle;
  *(uint *)(handle + 0x30) = port;
  *(unsigned long *)(handle + 0x38) = kind;
  *(unsigned long *)(handle + 0x40) = bootargs;
  *(unsigned long *)(handle + 0x48) = scratch;
  return 0;
}

static uint64_t coruna_persist_libobjc_bind_after_flush(long handle, uint port, unsigned long kind,
    unsigned long tag, long addr, unsigned long scratch, unsigned long host5)
{
  uint32_t type_id_11;
  uint64_t type_id_9;
  unsigned long bootargs;
  unsigned long *serial_buf;

  if (port >> 0x14 == 0) {
    type_id_11 = 5;
    if (0x3c0 < port >> 10) {
      type_id_11 = 6;
    }
    if (port < 0xf0000) {
      if (port < 0xe0000) {
        type_id_11 = 8;
        if (port >> 9 < 0x681) {
          type_id_11 = 4;
        }
      }
      else {
        type_id_11 = 0xc;
      }
    }
  }
  else {
    type_id_11 = 8;
  }
  type_id_9 = coruna_persistb080_residual_152(host5, "__objc_flush_caches", &serial_buf);
  if ((int)type_id_9 != 0) {
    return coruna_persist_libobjc_close(handle, type_id_9, host5);
  }
  type_id_9 = coruna_dladdr(serial_buf, type_id_11, tag, addr, &bootargs);
  coruna_ctx_free_11dc8(host5);
  if ((int)type_id_9 == 0) {
    return coruna_persist_libobjc_commit(handle, port, kind, bootargs, scratch, host5);
  }
  return coruna_persist_libobjc_close(handle, type_id_9, host5);
}

static int coruna_persist_libobjc_port_rebind(uint port)
{
  if ((int)port < 0xf0800) {
    return 1;
  }
  if (0x1002ff < (int)port) {
    return 1;
  }
  if (0x1000ff < (int)port) {
    return 1;
  }
  if ((port == 0xf0800) || (port == 0x100000)) {
    return 1;
  }
  return 0;
}

uint64_t coruna_load_libobjc_path(long handle)
{
  unsigned long u;
  unsigned long size;
  uint32_t version;
  char *ptr;
  uint port;
  unsigned long tag;
  unsigned long kind;
  bool err;
  bool status;
  bool flags;
  int err;
  long handle;
  long addr;
  unsigned long type_id;
  unsigned long type_id_8;
  uint64_t type_id_9;
  uint type_id_10;
  uint32_t type_id_11;
  int *err;
  unsigned long *ptr;
  long off;
  unsigned long *buf;
  unsigned long type_id_12;
  unsigned long type_id_13;
  uint64_t type_id_14;
  unsigned long scratch;
  unsigned long bootargs;
  long thread_attr;
  unsigned long host_info [6];
  unsigned long *serial_buf;
  
  if (handle == 0) {
    return 0xad001;
  }
  type_id_14 = 0x18008;
  handle = _dlopen("/usr/lib/libobjc.A.dylib",2);
  if (handle == 0) {
    return 0x18004;
  }
  host_info[2] = 0;
  host_info[1] = 0;
  host_info[4] = 0;
  host_info[3] = 0;
  addr = _dlsym(handle,"object_getClass");
  type_id = _dlsym(handle,"_objc_patch_root_of_class");
  type_id_8 = _dlsym(handle,"_objc_map_images");
  if (addr == 0) {
    type_id_9 = 0x18002;
  }
  else {
    err = _dladdr(addr,host_info + 1);
    kind = host_info[2];
    type_id_9 = 0x18003;
    if ((err != 0) && (host_info[2] != 0)) {
      thread_attr = 0;
      host_info[0] = 0;
      type_id_9 = coruna_macho_text_seg_14dfc("__TEXT","__text",host_info[2],host_info,&thread_attr);
      tag = host_info[0];
      addr = thread_attr;
      if ((int)type_id_9 == 0) {
        err = *(int *)(kind + 0x10);
        if (err != 0) {
          err = (int *)(kind + 0x20);
          do {
            if (*err == 0x25) {
              off = 8;
fail:
              port = *(uint *)((long)err + off);
              scratch = 0;
              bootargs = 0;
              status = host_info[0] == 0;
              flags = thread_attr == 0;
              type_id_12 = bootargs;
              bootargs = type_id_12;
              host_info[5] = 0;
              type_id_9 = 0xad001;
              if ((status || flags) ||
              (type_id_9 = coruna_persistb080_via_macho_open_image(handle,kind,0,0x10,host_info + 5), (int)type_id_9 != 0))
              _dlclose(handle);
              return type_id_9;
              host_info[5] = 0;
              serial_buf = (unsigned long *)0x0;
              err = coruna_macho_text_seg_14dfc("__AUTH_CONST","__const",kind,&serial_buf,host_info + 5);
              if (err == 0x18006) {
                err = coruna_macho_text_seg_14dfc("__DATA_CONST","__const",kind,&serial_buf,host_info + 5);
              }
              type_id_12 = bootargs;
              if ((((err != 0) || (serial_buf == (unsigned long *)0x0)) || (host_info[5] < 0x19)) ||
                 bootargs = type_id_12;
                 host_info[5] = 0;
                 type_id_9 = 0xad001;
                 if ((status || flags) ||
                 (type_id_9 = coruna_persistb080_via_macho_open_image(handle,kind,0,0x10,host_info + 5), (int)type_id_9 != 0))
                 _dlclose(handle);
                 return type_id_9;
              size = tag + addr;
              buf = serial_buf + 3;
              ptr = serial_buf;
              do {
              if ((*buf == type_id) && (-1 < addr)) {
              type_id_12 = *ptr;
              type_id_13 = ptr[2];
              u = type_id_12 + 8;
              err = type_id_12 < tag;
              if (((((((((!err && type_id_12 <= size) && (err || size != type_id_12)) && tag <= u) &&
              u <= size) && tag <= type_id_13) && type_id_13 <= size) &&
              (((((err || (type_id_12 > size || size == type_id_12)) || tag > u) || size < u) ||
              tag > type_id_13) || size != type_id_13)) && tag <= type_id_13 + 8) && type_id_13 + 8 <= size) {
              scratch = type_id_13;
              bootargs = type_id_8;
              if (type_id_8 != 0) {
              return coruna_persist_libobjc_commit(handle, port, kind, bootargs, scratch, host_info[5]);
              }
              break;
              }
              }
              buf = buf + 1;
              ptr = ptr + 1;
              type_id_12 = bootargs;
              } while (buf <= (unsigned long *)((long)serial_buf + (host_info[5] - 8)));
              bootargs = type_id_12;
              host_info[5] = 0;
              type_id_9 = 0xad001;
              if ((status || flags) ||
              (type_id_9 = coruna_persistb080_via_macho_open_image(handle,kind,0,0x10,host_info + 5), (int)type_id_9 != 0))
              _dlclose(handle);
              return type_id_9;
            }
            if (*err == 0x32) {
              off = 0xc;
              port = *(uint *)((long)err + off);
              scratch = 0;
              bootargs = 0;
              status = host_info[0] == 0;
              flags = thread_attr == 0;
              type_id_12 = bootargs;
              bootargs = type_id_12;
              host_info[5] = 0;
              type_id_9 = 0xad001;
              if ((status || flags) ||
              (type_id_9 = coruna_persistb080_via_macho_open_image(handle,kind,0,0x10,host_info + 5), (int)type_id_9 != 0))
              _dlclose(handle);
              return type_id_9;
            }
            err = (int *)((long)err + (unsigned long)(uint)err[1]);
            err = err + -1;
          } while (err != 0);
        }
        type_id_9 = 0x18009;
      }
    }
  }
  _dlclose(handle);
  return type_id_9;
cleanup:
  do {
    if ((*buf == type_id) && (-1 < addr)) {
      type_id_12 = *ptr;
      type_id_13 = ptr[2];
      u = type_id_12 + 8;
      err = type_id_12 < tag;
      if (((((((((!err && type_id_12 <= size) && (err || size != type_id_12)) && tag <= u) &&
              u <= size) && tag <= type_id_13) && type_id_13 <= size) &&
           (((((err || (type_id_12 > size || size == type_id_12)) || tag > u) || size < u) ||
            tag > type_id_13) || size != type_id_13)) && tag <= type_id_13 + 8) && type_id_13 + 8 <= size) {
        scratch = type_id_13;
        bootargs = type_id_8;
        if (type_id_8 != 0) {
          return coruna_persist_libobjc_commit(handle, port, kind, bootargs, scratch, host_info[5]);
        }
        break;
      }
    }
    buf = buf + 1;
    ptr = ptr + 1;
    type_id_12 = bootargs;
  } while (buf <= (unsigned long *)((long)serial_buf + (host_info[5] - 8)));
done:
  bootargs = type_id_12;
  host_info[5] = 0;
  type_id_9 = 0xad001;
  if ((status || flags) ||
     (type_id_9 = coruna_persistb080_via_macho_open_image(handle,kind,0,0x10,host_info + 5), (int)type_id_9 != 0))
  _dlclose(handle);
  return type_id_9;
  serial_buf = (unsigned long *)0x0;
  if ((int)port < 0xf0000) {
    if ((int)port < 0xe0000) {
      if ((int)port < 0xd0400) {
        if ((int)port < 0xd0200) {
          if (port != 0xd0000) {
            type_id_10 = 0x100 | 0xd0000;
            if (port != type_id_10) return coruna_persist_libobjc_close(handle, 0x18008, host_info[5]);
          }
        }
        else if (port != 0xd0200) {
          type_id_10 = 0x300 | 0xd0000;
          if (port != type_id_10) return coruna_persist_libobjc_close(handle, 0x18008, host_info[5]);
        }
      }
      else if ((int)port < 0xd0600) {
        if (port != 0xd0400) {
          type_id_10 = 0x500 | 0xd0000;
          if (port != type_id_10) return coruna_persist_libobjc_close(handle, 0x18008, host_info[5]);
        }
      }
      else if (port != 0xd0600) {
        type_id_10 = 0x700 | 0xd0000;
        if (port != type_id_10) return coruna_persist_libobjc_close(handle, 0x18008, host_info[5]);
      }
    }
    else if ((int)port < 0xe0400) {
      if ((int)port < 0xe0200) {
        if (port != 0xe0000) {
          type_id_10 = 0x100 | 0xe0000;
          if (port != type_id_10) return coruna_persist_libobjc_close(handle, 0x18008, host_info[5]);
        }
      }
      else if (port != 0xe0200) {
        type_id_10 = 0x300 | 0xe0000;
        if (port != type_id_10) return coruna_persist_libobjc_close(handle, 0x18008, host_info[5]);
      }
    }
    else if ((int)port < 0xe0600) {
      if (port != 0xe0400) {
        type_id_10 = 0x500 | 0xe0000;
        if (port != type_id_10) return coruna_persist_libobjc_close(handle, 0x18008, host_info[5]);
      }
    }
    else if ((port != 0xe0600) && (port != 0xe0700)) {
      type_id_10 = 0x800 | 0xe0000;
      if (port != type_id_10) return coruna_persist_libobjc_close(handle, 0x18008, host_info[5]);
    }
  }
invalid:
    ptr = "_objc_retainAutorelease";
    if (port < 0xf0000) {
      ptr = "__objc_flush_caches";
    }
    type_id_9 = coruna_persistb080_residual_152(host_info[5],ptr,&serial_buf);
    if ((int)type_id_9 == 0) {
      type_id_10 = 0xfffff;
      if (port < 0xf0000) {
        type_id_10 = 0xdffff;
      }
      type_id_11 = 6;
      if (port < 0xf0000) {
        type_id_11 = 1;
      }
      version = 5;
      if (port <= type_id_10) {
        version = type_id_11;
      }
      type_id_9 = coruna_dladdr(serial_buf,version,tag,addr,&bootargs);
      if ((int)type_id_9 == 0) {
        serial_buf = (unsigned long *)0x0;
        if ((int)port < 0xf0000) {
          if ((int)port < 0xe0000) {
            if ((int)port < 0xd0400) {
              if ((int)port < 0xd0200) {
                if (port != 0xd0000) {
                  type_id_10 = 0x100 | 0xd0000;
                  coruna_ctx_free_11dc8(host_info[5]);
                  type_id_9 = type_id_14;
                  _dlclose(handle);
                  return type_id_9;
                }
              }
              else if (port != 0xd0200) {
                type_id_10 = 0x300 | 0xd0000;
                coruna_ctx_free_11dc8(host_info[5]);
                type_id_9 = type_id_14;
                _dlclose(handle);
                return type_id_9;
              }
            }
            else if ((int)port < 0xd0600) {
              if (port != 0xd0400) {
                type_id_10 = 0x500 | 0xd0000;
                coruna_ctx_free_11dc8(host_info[5]);
                type_id_9 = type_id_14;
                _dlclose(handle);
                return type_id_9;
              }
            }
            else if (port != 0xd0600) {
              type_id_10 = 0x700 | 0xd0000;
              coruna_ctx_free_11dc8(host_info[5]);
              type_id_9 = type_id_14;
              _dlclose(handle);
              return type_id_9;
            }
          }
          else if ((int)port < 0xe0400) {
            if ((int)port < 0xe0200) {
              if (port != 0xe0000) {
                type_id_10 = 0x100 | 0xe0000;
                coruna_ctx_free_11dc8(host_info[5]);
                type_id_9 = type_id_14;
                _dlclose(handle);
                return type_id_9;
              }
            }
            else if (port != 0xe0200) {
              type_id_10 = 0x300 | 0xe0000;
              coruna_ctx_free_11dc8(host_info[5]);
              type_id_9 = type_id_14;
              _dlclose(handle);
              return type_id_9;
            }
          }
          else if ((int)port < 0xe0600) {
            if (port != 0xe0400) {
              type_id_10 = 0x500 | 0xe0000;
              coruna_ctx_free_11dc8(host_info[5]);
              type_id_9 = type_id_14;
              _dlclose(handle);
              return type_id_9;
            }
          }
          else if ((port != 0xe0600) && (port != 0xe0700)) {
            type_id_10 = 0x800 | 0xe0000;
            coruna_ctx_free_11dc8(host_info[5]);
            type_id_9 = type_id_14;
            _dlclose(handle);
            return type_id_9;
          }
          return coruna_persist_libobjc_bind_after_flush(handle, port, kind, tag, addr, scratch,
              host_info[5]);
        }
        else {
          if ((int)port < 0xf0800) {
            if ((int)port < 0xf0400) {
              if ((int)port < 0xf0200) {
                if (port != 0xf0000) {
                  type_id_10 = 0x100 | 0xf0000;
                  coruna_ctx_free_11dc8(host_info[5]);
                  type_id_9 = type_id_14;
                  _dlclose(handle);
                  return type_id_9;
                }
              }
              else if (port != 0xf0200) {
                type_id_10 = 0x300 | 0xf0000;
                coruna_ctx_free_11dc8(host_info[5]);
                type_id_9 = type_id_14;
                _dlclose(handle);
                return type_id_9;
              }
            }
            else if ((int)port < 0xf0600) {
              if (port != 0xf0400) {
                type_id_10 = 0x500 | 0xf0000;
                coruna_ctx_free_11dc8(host_info[5]);
                type_id_9 = type_id_14;
                _dlclose(handle);
                return type_id_9;
              }
            }
            else if (port != 0xf0600) {
              type_id_10 = 0x700 | 0xf0000;
              coruna_ctx_free_11dc8(host_info[5]);
              type_id_9 = type_id_14;
              _dlclose(handle);
              return type_id_9;
            }
            return coruna_persist_libobjc_bind_after_flush(handle, port, kind, tag, addr, scratch,
                host_info[5]);
          }
          if (0x1002ff < (int)port) {
            if ((int)port < 0x100500) {
              if (port != 0x100300) {
                type_id_10 = 0x400 | 0x100000;
                coruna_ctx_free_11dc8(host_info[5]);
                type_id_9 = type_id_14;
                _dlclose(handle);
                return type_id_9;
              }
            }
            else if ((port != 0x100500) && (port != 0x100700)) {
              type_id_10 = 0x600 | 0x100000;
              coruna_ctx_free_11dc8(host_info[5]);
              type_id_9 = type_id_14;
              _dlclose(handle);
              return type_id_9;
            }
            return coruna_persist_libobjc_bind_after_flush(handle, port, kind, tag, addr, scratch,
                host_info[5]);
          }
          if (0x1000ff < (int)port) {
            if (port != 0x100100) {
              type_id_10 = 0x200 | 0x100000;
              coruna_ctx_free_11dc8(host_info[5]);
              type_id_9 = type_id_14;
              _dlclose(handle);
              return type_id_9;
            }
            return coruna_persist_libobjc_bind_after_flush(handle, port, kind, tag, addr, scratch,
                host_info[5]);
          }
          if ((port == 0xf0800) || (port == 0x100000)) {
            return coruna_persist_libobjc_bind_after_flush(handle, port, kind, tag, addr, scratch,
                host_info[5]);
          }
        }
load_ok:
        coruna_ctx_free_11dc8(host_info[5]);
        type_id_9 = type_id_14;
        _dlclose(handle);
        return type_id_9;
      }
    }
  else {
    if (coruna_persist_libobjc_port_rebind(port)) goto invalid;
    type_id_9 = 0x18008;
  }
  coruna_ctx_free_11dc8(host_info[5]);
check_ok:
  _dlclose(handle);
  return type_id_9;
}






uint64_t coruna_pthread_mutex_destroy(long handle)
{
  if (handle != 0) {
    if (*(int *)(handle + 0x50) == 2) {
      _pthread_mutex_destroy((pthread_mutex_t *)(handle + 0x58));
      *(uint64_t *)(handle + 0x60) = 0;
      *(uint64_t *)(handle + 0x58) = 0;
      *(uint64_t *)(handle + 0x70) = 0;
      *(uint64_t *)(handle + 0x68) = 0;
      *(uint64_t *)(handle + 0x80) = 0;
      *(uint64_t *)(handle + 0x78) = 0;
      *(uint64_t *)(handle + 0x90) = 0;
      *(uint64_t *)(handle + 0x88) = 0;
      *(uint64_t *)(handle + 0xa0) = 0;
      *(uint64_t *)(handle + 0x98) = 0;
      *(uint64_t *)(handle + 0xa8) = 0;
    }
    *(uint64_t *)(handle + 0xa8) = 0;
    *(uint64_t *)(handle + 0x90) = 0;
    *(uint64_t *)(handle + 0x88) = 0;
    *(uint64_t *)(handle + 0xa0) = 0;
    *(uint64_t *)(handle + 0x98) = 0;
    *(uint64_t *)(handle + 0x70) = 0;
    *(uint64_t *)(handle + 0x68) = 0;
    *(uint64_t *)(handle + 0x80) = 0;
    *(uint64_t *)(handle + 0x78) = 0;
    *(uint64_t *)(handle + 0x50) = 0;
    *(uint64_t *)(handle + 0x48) = 0;
    *(uint64_t *)(handle + 0x60) = 0;
    *(uint64_t *)(handle + 0x58) = 0;
    *(uint64_t *)(handle + 0x30) = 0;
    *(uint64_t *)(handle + 0x28) = 0;
    *(uint64_t *)(handle + 0x40) = 0;
    *(uint64_t *)(handle + 0x38) = 0;
    return 0;
  }
  return 0xad001;
}





uint64_t coruna_objc_metaclass_prefix(long *handle)
{
  int err;
  int status;
  uint64_t u;
  long handle;
  char *ptr;
  long addr;
  unsigned long size;
  long off;
  
  if (handle == (long *)0x0) {
    u = 0xad001;
  }
  else {
    addr = 0;
    handle = *handle;
    size = 0xffffffffffffffff;
    do {
      size = size + 1;
      if (*(uint *)(handle + 0x16) <= size) {
        return 0;
      }
      off = handle[0x15];
      ptr = *(char **)(off + addr);
      err = _strncmp(ptr,"_OBJC_CLASS_$_",0xe);
      if ((err == 0) || (status = _strncmp(ptr,"_OBJC_METACLASS_$_",0x12), status == 0)) {
        u = coruna_dlsym(handle,handle + 0x28,*(uint64_t *)(off + addr + 8),err != 0);
      }
      else {
        u = 0;
      }
      addr = addr + 0x10;
    } while ((int)u == 0);
  }
  return u;
}





int coruna_dlsym(long handle,long *addr_2,uint64_t *val,unsigned long arg)
{
  uint64_t *ptr;
  unsigned long *buf;
  uint64_t *str;
  uint64_t *copy;
  unsigned long u;
  uint64_t size;
  int err;
  uint64_t version;
  long handle;
  unsigned long port;
  
  err = 0xad001;
  if (((handle != 0) && (addr_2 != (long *)0x0)) &&
     (*addr_2 != 0 && val != (uint64_t *)0x0)) {
    handle = 0;
    port = 0;
    ptr = val + 5;
    err = 0xad011;
    while (err == 0xad011) {
      if (*(uint *)(handle + 0x88) <= port) {
        return 0xad011;
      }
      buf = (unsigned long *)(*(long *)(handle + 0x80) + handle);
      copy = (uint64_t *)*buf;
      u = buf[1];
      str = (uint64_t *)((long)copy + u);
      port = port + 1;
      err = 0;
      if (((((ptr > str || copy > ptr) || str <= val) || copy > val) ||
          u == 0xffffffffffffffff) ||
          (((ptr <= str && copy <= ptr) && val < str) && copy <= val) &&
          (long)u < -1) {
        err = 0xad011;
      }
      handle = handle + 0x18;
    }
    if (err == 0) {
      size = _dlsym(*addr_2,"OBJC_METACLASS_$_NSObject");
      *val = size;
      if ((arg & 1) == 0) {
        size = _dlsym(*addr_2,"OBJC_CLASS_$_NSObject");
      }
      val[1] = size;
      size = _dlsym(*addr_2,"_objc_empty_cache");
      val[2] = size;
      size = _dlsym(*addr_2,"_objc_empty_vtable");
      err = 0;
      version = *(uint64_t *)(handle + 8);
      val[3] = size;
      val[4] = version;
    }
  }
  return err;
}





uint64_t coruna_persistb080_via_macho_foreach_loadcmd(long handle,long addr_2)
{
  uint64_t u;
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  long serial_buf;
  
  u = 0xad001;
  if (((((handle != 0) && (*(long *)(handle + 0x38) != 0)) && (*(long *)(handle + 0x40) != 0)) &&
      ((*(long *)(handle + 0x48) != 0 && (addr_2 != 0)))) &&
     ((*(char *)(addr_2 + 0xfc) != '\0' &&
      ((u = 0, (*(ushort *)(addr_2 + 0x1c0) >> 8 & 1) != 0 &&
       (*(uint *)(handle + 0x30) >> 0x11 < 7)))))) {
    scratch = k_persist_nsconcretestackblock_slot;
    bootargs = k_persist_rodata_word_1ed98;
    thread_attr = coruna_macho_objc_sect;
    host_info = &k_persist_rodata_word_20460;
    serial_buf = addr_2;
    u = coruna_macho_foreach_loadcmd(addr_2,0x19,&scratch);
  }
  return u;
}





uint64_t coruna_macho_text_seg_14dfc(char *path,char *str_2,long handle,long *addr_2,uint64_t *val)
{
  uint64_t u;
  int err;
  int status;
  uint64_t size;
  int *err;
  int *status;
  int flags;
  int *flags;
  unsigned long version;
  int *count;
  int *idx;
  
  size = 0x18006;
  err = *(int *)(handle + 0x10);
  if (err != 0) {
    err = (int *)0x0;
    flags = 0;
    flags = (int *)(handle + 0x20);
    count = (int *)0x0;
    do {
      idx = count;
      if ((count != (int *)0x0) && (err != (int *)0x0)) break;
      if (*flags == 0x19) {
        status = _strcmp((char *)(flags + 2),"__TEXT");
        idx = flags;
        if (status != 0) {
          idx = count;
        }
        if (err == (int *)0x0) {
          status = _strcmp((char *)(flags + 2),path);
          if ((status == 0) && (version = (unsigned long)(uint)flags[0x10], flags[0x10] != 0)) {
            count = flags + 0x12;
            status = (int *)0x0;
            do {
              status = _strcmp((char *)count,str_2);
              err = count;
              if (status != 0) {
                err = status;
              }
              count = count + 0x14;
              version = version - 1;
              status = err;
            } while (version != 0);
          }
          else {
            err = (int *)0x0;
          }
        }
      }
      flags = (int *)((long)flags + (unsigned long)(uint)flags[1]);
      flags = flags + 1;
      count = idx;
    } while (flags != err);
    size = 0x18006;
    if ((idx != (int *)0x0) && (err != (int *)0x0)) {
      size = 0;
      u = *(uint64_t *)(err + 10);
      *addr_2 = (handle - *(long *)(idx + 6)) + *(long *)(err + 8);
      *val = u;
    }
  }
  return size;
}





uint64_t coruna_dladdr(unsigned long arg,int flags,long handle,long addr_2,unsigned long *arg)
{
  int err;
  unsigned long u;
  uint64_t size;
  unsigned long version;
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  unsigned long bootargs;
  
  size = 0xad001;
  if (((arg != 0) && (handle != 0)) && (arg != (unsigned long *)0x0)) {
    size = 0x18005;
    scratch = 0;
    scratch = 0;
    bootargs = 0;
    bootargs = 0;
    u = arg;
    while (arg < (unsigned long)(handle + addr_2)) {
      err = _dladdr(arg,&scratch);
      version = arg;
      if ((err != 0) && (u != bootargs)) {
        flags = flags + -1;
        if (flags == 0) {
          *arg = bootargs;
          return 0;
        }
        u = bootargs;
        version = bootargs;
        if (bootargs <= arg) {
          version = arg;
        }
      }
      arg = version + 1;
    }
  }
  return size;
}
uint coruna_macho_objc_sect(long handle,long addr_2)
{
  uint u;
  bool err;
  int err;
  unsigned long size;
  unsigned long version;
  
  err = _strcmp((char *)(addr_2 + 8),"__TEXT");
  if ((err == 0) &&
     (size = addr_2 + 0x48U + (unsigned long)*(uint *)(addr_2 + 0x40) * 0x50, addr_2 + 0x48U < size)) {
    version = addr_2 + 0x98;
    do {
      err = _strcmp((char *)(version - 0x50),"__objc_methlist");
      if ((err == 0) &&
         (u = *(int *)(*(long *)(*(long *)(handle + 0x20) + 0x18) + *(long *)(version - 0x30)) >>
                  0x1f & 0x18014, u != 0)) {
        return u;
      }
      err = version < size;
      version = version + 0x50;
    } while (err);
  }
  return 0;
}





uint coruna_mach_vm_region_recurse(vm_map_t arg,mach_vm_address_t arg_x,long handle,uint *size,
                 uint8_t *buf,long addr_2)
{
  uint u;
  bool err;
  uint size;
  kern_return_t lk4;
  uint8_t version;
  natural_t scratch;
  mach_msg_type_number_t bootargs;
  unsigned long thread_attr [5];
  short host_info;
  uint64_t scratch;
  mach_vm_size_t serial_buf;
  mach_vm_address_t action;
  
  serial_buf = 0;
  thread_attr[3] = 0;
  thread_attr[2] = 0;
  scratch = 0;
  thread_attr[4] = 0;
  thread_attr[1] = 0;
  thread_attr[0] = 0;
  bootargs = 0xc;
  size = 0xad001;
  if (((size != (uint *)0x0) && (buf != (uint8_t *)0x0)) && (addr_2 != 0)) {
    scratch = 1;
    action = arg_x;
    size = _mach_vm_region_recurse
                      (arg,&action,&serial_buf,&scratch,(vm_region_recurse_info_t)thread_attr,
                       &bootargs);
    if (size == 0) {
      u = (uint)thread_attr[0];
      err = host_info != 0;
      size = (uint)thread_attr[0] >> 2 & 1;
      version = (uint8_t)size;
      if ((serial_buf + action < handle + arg_x) && (((uint)thread_attr[0] >> 2 & 1) == 0)) {
        do {
          version = (uint8_t)size;
          scratch = 1;
          bootargs = 0xc;
          lk4 = _mach_vm_region_recurse
                            (arg,&action,&serial_buf,&scratch,
                             (vm_region_recurse_info_t)thread_attr,&bootargs);
          if (lk4 != 0) break;
          size = (uint)thread_attr[0] >> 2 & 1;
          version = (uint8_t)size;
          action = action + serial_buf;
        } while (action + serial_buf < handle + arg_x && (thread_attr[0] & 4) == 0);
      }
      size = 0;
      *size = u;
      *buf = version;
      *(bool *)addr_2 = err;
    }
    else {
      size = size | 0x80000000;
    }
  }
  return size;
}





unsigned long coruna_mach_vm_protect(long arg,long val,unsigned long n,mach_vm_address_t m,
                  mach_vm_size_t p,uint q)

{
  uint32_t u;
  uint size;
  unsigned long version;
  void (*data)(void);
  vm_map_t target_task;
  unsigned long cache_54;
  mach_vm_address_t cache_91;
  mach_vm_size_t host_info;
  uint serial_buf;
  uint32_t cache_55;
  uint32_t cache_32;
  uint64_t action;
  uint16_t cache_92;
  uint cache_87;
  
  if (arg == 0) {
    return 0xad001;
  }
  if (*(long *)(arg + 0x28) == 0 || val == 0) {
    return 0xad001;
  }
  cache_87 = 0;
  cache_92 = 0;
  version = coruna_mach_vm_region_recurse(n,m,p,&cache_87,(long)&cache_92 + 1,&cache_92);
  if ((int)version != 0) {
    return version;
  }
  target_task = (vm_map_t)n;
  if ((q >> 2 & 1) == 0) {
    if (cache_92 != '\0') {
      data = *(void (**)(arg + 0x28);
      if (data == (void (*)0x0) {
        version = 0xad001;
        (**(void (**)(arg + 0x28))(arg,val,0xc,n & 0xffffffff);
        return version;
      }
      serial_buf = 0;
      u = 0x40000012;
      cache_55 = 1;
      cache_54 = n & 0xffffffff;
      cache_91 = m;
      host_info = p;
      version = (*data)(arg,val,u,&cache_54);
      (**(void (**)(arg + 0x28))(arg,val,0xc,n & 0xffffffff);
      return version;
    }
    size = _mach_vm_protect(target_task,m,p,0,q);
    version = (unsigned long)(size | 0x80000000);
    (**(void (**)(arg + 0x28))(arg,val,0xc,n & 0xffffffff);
    return version;
load_ok_26:
    version = 0;
  }
  else {
    serial_buf = cache_87;
    data = *(void (**)(arg + 0x28);
    u = 0x40000021;
load_ok_24:
    cache_55 = 1;
    cache_54 = n & 0xffffffff;
    cache_91 = m;
    host_info = p;
    version = (*data)(arg,val,u,&cache_54);
    (**(void (**)(arg + 0x28))(arg,val,0xc,n & 0xffffffff);
    return version;
    size = _mach_vm_protect(target_task,m,p,0,q);
    if (size != 0) {
load_ok_25:
      version = (unsigned long)(size | 0x80000000);
      (**(void (**)(arg + 0x28))(arg,val,0xc,n & 0xffffffff);
      return version;
    }
    version = 0;
    }
    else {
    serial_buf = cache_87;
    data = *(void (**)(arg + 0x28);
    u = 0x40000021;
    cache_55 = 1;
    cache_54 = n & 0xffffffff;
    cache_91 = m;
    host_info = p;
    version = (*data)(arg,val,u,&cache_54);
    (**(void (**)(arg + 0x28))(arg,val,0xc,n & 0xffffffff);
    return version;
    version = 0xad001;
    (**(void (**)(arg + 0x28))(arg,val,0xc,n & 0xffffffff);
    return version;
    cache_54 = n & 0xffffffff;
    cache_55 = 1;
    cache_91 = m;
    host_info = p;
    serial_buf = q;
    version = (**(void (**)(arg + 0x28))(arg,val,0x4000000e,&cache_54);
  }
  if (k_persist_rodata_word_1eda0 <= *(double *)k_persist_dyldversionnumber_slot && (int)version == 0) {
    cache_54 = coruna_u64_pack((cache_54), (target_task));
    serial_buf = serial_buf & 0xffffff00;
    action = 0;
    cache_55 = 0;
    cache_32 = 0;
    cache_91 = m;
    host_info = p;
    version = (**(void (**)(arg + 0x28))(arg,val,0xc0000023,&cache_54);
    if ((int)version == 0) {
      if ((char)serial_buf == '\0') {
        version = 0;
      }
      else {
        serial_buf = serial_buf & 0xffffff00;
        version = (**(void (**)(arg + 0x28))(arg,val,0x40000023,&cache_54);
      }
    }
  }
load_ok_23:
  (**(void (**)(arg + 0x28))(arg,val,0xc,n & 0xffffffff);
  return version;
}





uint64_t
void coruna_persistb080_via_mach_vm_region_recurse(long handle,long addr_2,unsigned long arg,uint64_t val,uint64_t id_2)
{
  uint64_t u;
  uint64_t size;
  uint16_t scratch;
  uint bootargs;
  unsigned long thread_attr;
  uint64_t scratch;
  uint64_t bootargs;
  unsigned long host_info;
  
  size = 0xad001;
  u = size;
  if ((handle != 0) && (*(void (**)(handle + 0x28) != (void (*)0x0 && addr_2 != 0)) {
    bootargs = 0;
    scratch = 0;
    u = (**(void (**)(handle + 0x28))(handle,addr_2,0xc,arg & 0xffffffff);
    if (((int)u == 0) &&
       (u = coruna_mach_vm_region_recurse(arg,val,id_2,&bootargs,(long)&scratch + 1,&scratch),
       (int)u == 0)) {
      if (scratch == '\0') {
        u = 0;
      }
      else {
        if ((char)scratch == '\0') {
          size = 0x12013;
        }
        else if (*(void (**)(handle + 0x28) != (void (*)0x0) {
          thread_attr = arg & 0xffffffff;
          host_info = (unsigned long)bootargs;
          scratch = val;
          bootargs = id_2;
          size = (**(void (**)(handle + 0x28))(handle,addr_2,0x4000000e,&thread_attr);
        }
        (**(void (**)(handle + 0x28))(handle,addr_2,0xc,arg & 0xffffffff);
        u = size;
      }
    }
  }
  return u;
}





int coruna_persistb080_residual_151(long *handle)
{
  ushort u;
  ushort size;
  ushort version;
  uint port;
  int *err;
  
  if (((handle != (long *)0x0) && (err = (int *)handle[0x29], err != (int *)0x0)) &&
     (*handle != 0)) {
    if ((unsigned long)handle[0x2a] < 0x20) {
      return 0x13001;
    }
    if (*err == -0x1120531) {
      if ((unsigned long)handle[0x2a] < (unsigned long)(uint)err[5] + 0x20) {
        port = 0x6002;
      }
      else if (err[1] == 0x100000c) {
        port = err[2] & 0xffffff;
        if (((port < 2) && ((int)port <= *(int *)(*handle + 0x18))) ||
           (*(char *)((long)handle + 0x1c2) != '\0')) {
          if ((((uint)err[6] >> 0x17 & 1) == 0) || (*(char *)((long)handle + 0x1c2) != '\0')) {
            u = *(ushort *)(handle + 0x38);
            version = u & 0x1f | (ushort)(((uint)err[6] >> 5 & 1) << 5);
            size = u & 0xffc0 | version;
            *(ushort *)(handle + 0x38) = size;
            if (1 < port) {
              *(ushort *)(handle + 0x38) = size | 0x80;
              *(uint8_t *)(handle + 0x22) = 1;
              *(ushort *)(handle + 0x38) =
                   (ushort)((uint)err[2] >> 0x17) & 0x100 | u & 0xfec0 | version | 0x80;
            }
            handle[0x2e] = (long)err;
            handle[0x21] = (unsigned long)(uint)err[5] + 0x20;
            return 0;
          }
          port = 0x6006;
        }
        else {
          port = 0x6004;
        }
      }
      else {
        port = 0x6003;
      }
    }
    else {
      port = 0x6001;
    }
    return (port | 0xfff60000) + 0xad001;
  }
  return 0xad001;
}





uint64_t coruna_macho_foreach_loadcmd(long handle,int flags,long addr_2)
{
  int *err;
  uint u;
  uint64_t size;
  int *status;
  int *flags;
  long handle;
  int *count;
  uint version;
  
  size = 0xad001;
  if ((((handle != 0) && (*(long *)(handle + 0x170) != 0)) &&
      (flags = *(int **)(handle + 0x148), flags != (int *)0x0)) &&
     ((handle = *(long *)(handle + 0x150), handle != 0 && (addr_2 != 0)))) {
    u = *(uint *)(*(long *)(handle + 0x170) + 0x10);
    if (u == 0) {
      size = 0;
    }
    else {
      if (((-1 < handle) && (status = flags + 8, flags <= status)) &&
         ((count = (int *)((long)flags + handle), status < count &&
          ((flags <= flags + 10 && (flags + 10 <= count)))))) {
        version = 1;
        while (err = (int *)((long)status + (unsigned long)(uint)status[1]),
              flags <= err && err <= count) {
          if ((flags == 0) || (*status == flags)) {
            size = (**(void (**)(addr_2 + 0x10))(addr_2);
            if ((int)size != 0) {
              return size;
            }
          }
          else {
            size = 0;
          }
          if (u <= version) {
            return size;
          }
          if ((((*(long *)(handle + 0x150) < 0) ||
               (flags = *(int **)(handle + 0x148), err < flags)) ||
              (count = (int *)((long)flags + *(long *)(handle + 0x150)), count <= err)) ||
             ((err + 2 < flags || (version = version + 1, status = err, count < err + 2))))
          break;
        }
      }
      size = 0x14009;
    }
  }
  return size;
}





int coruna_block_dispose_157f4(long handle,uint64_t val,uint64_t *id_2)
{
  int err;
  int status;
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  uint64_t *serial_buf;
  uint64_t scratch;
  long action;
  uint64_t block_ctx;
  uint64_t *stack_guard;
  uint64_t sa_saved;
  uint64_t sa_new;
  
  status = 0xad001;
  if ((handle != 0) && (id_2 != (uint64_t *)0x0)) {
    serial_buf = &block_ctx;
    block_ctx = 0;
    sa_saved = k_persist_rodata_word_1ecd8;
    sa_new = 0;
    scratch = k_persist_nsconcretestackblock_slot;
    bootargs = k_persist_rodata_word_1ece0;
    thread_attr = coruna_macho_pagezero;
    host_info = &k_persist_rodata_word_20480;
    scratch = val;
    action = handle;
    stack_guard = serial_buf;
    err = coruna_macho_foreach_loadcmd(handle,0x19,&scratch);
    if (err == 0xad017) {
      *id_2 = stack_guard[3];
      status = 0;
    }
    else {
      status = 0xad011;
      if (err != 0) {
        status = err;
      }
    }
    __Block_object_dispose(&block_ctx,8);
  }
  return status;
}





uint32_t coruna_macho_pagezero(long handle,long addr_2)
{
  unsigned long u;
  int err;
  unsigned long size;
  
  size = *(unsigned long *)(addr_2 + 0x30);
  if (size != 0) {
    err = _strncmp((char *)(addr_2 + 8),"__PAGEZERO",0xb);
    if (err == 0) {
      return 0;
    }
    u = *(unsigned long *)(handle + 0x28) - *(unsigned long *)(addr_2 + 0x28);
    if ((*(unsigned long *)(addr_2 + 0x28) <= *(unsigned long *)(handle + 0x28)) && (u < size)) {
      *(unsigned long *)(*(long *)(*(long *)(handle + 0x20) + 8) + 0x18) =
           *(long *)(addr_2 + 0x18) + u + *(long *)(*(long *)(handle + 0x30) + 0x18);
      return 0xad017;
    }
  }
  return 0;
}





void coruna_block_assign_fe28_1594c(long handle,long addr_2)
{
  __Block_object_assign((void *)(handle + 0x20),*(void **)(addr_2 + 0x20),8);
  return;
}





void coruna_block_dispose_fe38_1595c(long handle)
{
  __Block_object_dispose(*(void **)(handle + 0x20),8);
  return;
}





uint64_t
void coruna_persistb080_via_persistb080_via_mach_vm_region_recurse(long *handle,uint64_t val,uint64_t id_2,uint64_t size_3,
            uint8_t *buf)
{
  uint64_t u;
  uint8_t size;
  
  if (handle == (long *)0x0) {
    return 0xad001;
  }
  if (*(char *)((long)handle + 0x1d) == '\0') {
    u = 0;
  }
  else {
    if ((*handle == 0) || (handle[1] == 0)) {
      size = 0;
      u = 0;
      if (buf != (uint8_t *)0x0) {
      u = 0;
      *buf = size;
      }
      return u;
    }
    u = coruna_persistb080_via_mach_vm_region_recurse(*handle,handle[1],val,id_2,size_3);
  }
  size = 1;
  if ((int)u != 0) {
    return u;
  }
fail:
  if (buf != (uint8_t *)0x0) {
    u = 0;
    *buf = size;
  }
  return u;
}





unsigned long coruna_mach_vm_protect_fec8(long *arg,uint64_t val,mach_vm_address_t n,mach_vm_size_t m
                  ,uint64_t p,uint8_t *q)

{
  char err;
  bool idx;
  uint version;
  uint type_id;
  int count;
  unsigned long tag;
  int *status;
  uint *str;
  vm_map_t target_task;
  
  if (arg == (long *)0x0) {
    return 0xad001;
  }
  if (*arg == 0) {
    err = *(char *)((long)arg + 0x1d);
    idx = err == '\0';
  }
  else {
    err = *(char *)((long)arg + 0x1d);
    idx = err == '\0';
    if (!idx && arg[1] != 0) {
      tag = coruna_mach_vm_protect(*arg,arg[1],val,n,m,p);
      idx = true;
      version = (uint)tag;
      if ((version == 0) && (q != (uint8_t *)0x0)) {
      tag = 0;
      *q = idx;
      }
      return tag;
    }
  }
  target_task = (vm_map_t)val;
  if ((idx) || (((uint)p >> 2 & 1) == 0)) {
    idx = err != '\x01';
  }
  else {
    if ((target_task != 0) && (*(vm_map_t *)k_persist_mach_task_self_slot != target_task)) {
      return 0x14010;
    }
    count = _mlock(n,m);
    if (count != 0) {
      status = ___error();
      count = *status;
      str = (uint *)___error();
      version = -*str;
      if (-1 < count) {
        version = *str;
      }
      return (unsigned long)(version | 0x40000000);
    }
    _madvise(n,m,6);
    idx = false;
  }
  type_id = _mach_vm_protect(target_task,n,m,0,(uint)p);
  version = 0;
  if (type_id != 0) {
    version = type_id | 0x80000000;
  }
  tag = (unsigned long)version;
joined_r0x00015acc:
  if ((version == 0) && (q != (uint8_t *)0x0)) {
    tag = 0;
    *q = idx;
  }
  return tag;
}





uint64_t coruna_persistb080_via_macho_foreach_loadcmd_2(long handle)
{
  uint64_t u;
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  long serial_buf;
  
  if (handle != 0) {
    scratch = k_persist_nsconcretestackblock_slot;
    bootargs = k_persist_rodata_word_1ed98;
    thread_attr = coruna_macho_pagezero_15b9c;
    host_info = &k_persist_rodata_word_204b0;
    serial_buf = handle;
    u = coruna_macho_foreach_loadcmd(handle,0x19,&scratch);
    return u;
  }
  return 0xad001;
}





unsigned long coruna_macho_pagezero_15b9c(long arg,long val)

{
  mach_vm_address_t address;
  int err;
  uint size;
  unsigned long version;
  uint64_t *obj;
  vm_machine_attribute_val_t cache_93;
  
  size = _strncmp((char *)(val + 8),"__PAGEZERO",0xb);
  version = (unsigned long)size;
  if (size != 0) {
    obj = *(uint64_t **)(arg + 0x20);
    address = obj[10] + *(long *)(val + 0x18);
    err = *(int *)(val + 0x3c);
    if (err == 0) {
      err = 1;
    }
    version = coruna_mach_vm_protect_fec8(*obj,*(uint32_t *)(obj + 0xb),address,
                         *(uint64_t *)(val + 0x20),err,0);
    if ((int)version == 0) {
      cache_93 = 6;
      _mach_vm_machine_attribute
                (*(vm_map_t *)(*(long *)(arg + 0x20) + 0x58),address,
                 *(mach_vm_size_t *)(val + 0x20),1,&cache_93);
      version = 0;
    }
  }
  return version;
}





uint64_t coruna_persist_residual_47(long handle,long addr_2,uint64_t val)
{
  uint64_t *ptr;
  void *ptr;
  uint64_t u;
  
  u = 0x1200a;
  if (((handle != 0) && (addr_2 != 0)) &&
     (ptr = _realloc(*(void **)(handle + 0x98),(unsigned long)(*(int *)(handle + 0xa0) * 0x10 + 0x20)),
     ptr != (void *)0x0)) {
    u = 0;
    *(void **)(handle + 0x98) = ptr;
    ptr = (uint64_t *)((long)ptr + (unsigned long)*(uint *)(handle + 0xa0) * 0x10);
    *(uint *)(handle + 0xa0) = *(uint *)(handle + 0xa0) + 1;
    *ptr = val;
    ptr[1] = addr_2;
  }
  return u;
}





uint64_t coruna_persistb080_via_mach_vm_deallocate(long handle)
{
  uint64_t u;
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  long serial_buf;
  
  if (handle == 0) {
    u = 0xad001;
  }
  else {
    u = coruna_mach_vm_deallocate();
    scratch = k_persist_nsconcretestackblock_slot;
    if ((int)u == 0) {
      *(uint8_t *)(handle + 0x78) = 1;
      bootargs = k_persist_rodata_word_1ed98;
      thread_attr = coruna_macho_unwind_info;
      host_info = &k_persist_rodata_word_204d0;
      serial_buf = handle;
      u = coruna_macho_foreach_loadcmd(handle,0,&scratch);
    }
  }
  return u;
}





uint64_t coruna_mach_vm_deallocate(long handle)
{
  uint u;
  kern_return_t lk2;
  uint64_t size;
  mach_vm_size_t size;
  uint64_t *ptr;
  byte err;
  long handle;
  mach_vm_address_t scratch;
  mach_vm_address_t bootargs;
  uint8_t *thread_attr;
  uint64_t host_info;
  void (*serial_buf)(void);
  uint8_t *action;
  uint64_t *block_ctx;
  uint64_t *stack_guard;
  uint64_t *sa_saved;
  uint64_t sa_new;
  uint64_t *path_buf;
  uint64_t tmp_buf;
  uint64_t region;
  uint64_t plist;
  uint64_t *url_buf;
  uint64_t json_buf;
  uint64_t frame;
  uint64_t work;
  uint64_t *cache;
  uint64_t cache_20;
  uint64_t cache_21;
  
  cache = &work;
  work = 0;
  cache_20 = k_persist_rodata_word_1ecd8;
  cache_21 = 0;
  url_buf = &plist;
  plist = 0;
  json_buf = k_persist_rodata_word_1ecd8;
  frame = 0;
  path_buf = &sa_new;
  sa_new = 0;
  tmp_buf = k_persist_rodata_word_1ecd8;
  region = 0;
  if (handle == 0) {
    size = 0xad000;
  }
  else {
    thread_attr = k_persist_nsconcretestackblock_slot;
    host_info = k_persist_rodata_word_1ece0;
    serial_buf = coruna_macho_text_seg_186f4;
    action = &k_persist_rodata_word_20680;
    block_ctx = cache;
    stack_guard = url_buf;
    sa_saved = path_buf;
    size = coruna_macho_foreach_loadcmd(handle,0x19,&thread_attr);
    ptr = url_buf;
    if ((int)size == 0) {
      bootargs = url_buf[3];
      if ((bootargs == 0) && (bootargs = 0, path_buf[3] != 0)) {
        bootargs = *(mach_vm_address_t *)(path_buf[3] + 0x18);
        url_buf[3] = bootargs;
      }
      if (*(char *)(handle + 0x1c2) == '\0') {
        size = cache[3];
        if (*(char *)(handle + 0x138) != '\0') {
          size = (long)(int)~(uint)*(long *)k_persist_vm_page_mask_slot &
                 *(long *)k_persist_vm_page_mask_slot + size;
          cache[3] = size;
        }
        lk2 = _mach_vm_allocate(*(vm_map_t *)k_persist_mach_task_self_slot,&bootargs,size,1);
        if (lk2 != 0) {
          size = 0x14004;
          __Block_object_dispose(&sa_new,8);
          __Block_object_dispose(&plist,8);
          __Block_object_dispose(&work,8);
          return size;
        }
        err = *(byte *)(handle + 0x1c2) ^ 1;
        ptr = url_buf;
      }
      else {
        err = 0;
        bootargs = *(mach_vm_address_t *)(handle + 0x148);
        cache[3] = *(uint64_t *)(handle + 0x150);
      }
      handle = ptr[3];
      *(mach_vm_address_t *)(handle + 8) = bootargs;
      *(long *)(handle + 0x168) = handle;
      u = *(uint *)(cache + 3);
      handle = bootargs - handle;
      *(unsigned long *)(handle + 0x10) = (unsigned long)u;
      *(long *)(handle + 0x18) = handle;
      *(byte *)(handle + 0xfa) = err;
      if (*(char *)(handle + 0x138) == '\0') {
        size = 0;
        *(unsigned long *)(handle + 0x48) = (unsigned long)u;
        *(long *)(handle + 0x50) = handle;
        *(mach_vm_address_t *)(handle + 0x40) = bootargs;
        *(uint8_t *)(handle + 0xfb) = 0;
      }
      else {
        scratch = 0;
        lk2 = _mach_vm_allocate(*(vm_map_t *)(handle + 0x58),&scratch,cache[3],1);
        if (lk2 == 0) {
          size = 0;
          *(mach_vm_address_t *)(handle + 0x40) = scratch;
          *(uint64_t *)(handle + 0x48) = cache[3];
          *(mach_vm_address_t *)(handle + 0x50) = scratch - *(long *)(handle + 0x168);
          *(uint8_t *)(handle + 0xfb) = 1;
        }
        else {
          size = 0x1400f;
          if (*(char *)(handle + 0x1c2) == '\0') {
            _mach_vm_deallocate(*(vm_map_t *)k_persist_mach_task_self_slot,bootargs,cache[3]);
            *(mach_vm_address_t *)(handle + 8) = 0;
            *(uint64_t *)(handle + 0x10) = 0;
          }
        }
      }
    }
  }
fail:
  __Block_object_dispose(&sa_new,8);
  __Block_object_dispose(&plist,8);
  __Block_object_dispose(&work,8);
  return size;
}





uint coruna_macho_unwind_info(long handle,int *flags)
{
  long handle;
  unsigned long u;
  unsigned long size;
  int *err;
  int *status;
  char err;
  int err;
  uint version;
  void *ptr;
  ushort port;
  long addr;
  unsigned long tag;
  long off;
  unsigned long *ptr;
  unsigned long kind;
  unsigned long type_id;
  unsigned long type_id_8;
  int *flags;
  int *count;
  unsigned long type_id_9;
  uint64_t *buf;
  
  if (*flags != 0x19) {
    return 0;
  }
  buf = *(uint64_t **)(handle + 0x20);
  if (buf == (uint64_t *)0x0) {
    return 0xad001;
  }
  err = _strncmp((char *)(flags + 2),"__PAGEZERO",0xb);
  if (err == 0) {
    return 0;
  }
  err = _strncmp((char *)(flags + 2),"__LINKEDIT",0xb);
  addr = *(long *)(flags + 6);
  if (err == 0) {
    off = *(long *)(flags + 10);
    handle = buf[3] + addr;
    buf[0x23] = handle;
    buf[0x24] = handle - off;
    type_id_8 = *(unsigned long *)(flags + 8);
    buf[0x25] = type_id_8;
  }
  else {
    off = *(long *)(flags + 10);
    type_id_8 = *(unsigned long *)(flags + 8);
  }
  type_id = buf[3] + addr;
  tag = buf[1];
  if (tag == 0) {
    return 0x14006;
  }
  if (!CARRY8(type_id,type_id_8)) {
    type_id_9 = *(unsigned long *)(flags + 0xc);
    if ((type_id_9 <= type_id_8) && (-1 < (long)buf[0x2a])) {
      kind = buf[0x29];
      u = kind + off;
      if (((kind <= u) &&
          ((((size = kind + buf[0x2a], u < size && (-1 < (long)type_id_9)) &&
            (kind <= u + type_id_9)) && ((u + type_id_9 <= size && (-1 < (long)buf[2]))))))
         && ((tag <= type_id &&
             (((kind = tag + buf[2], type_id < kind && (-1 < (long)type_id_8)) &&
              (tag <= type_id + type_id_8)))))) {
        if (kind < type_id + type_id_8) {
          return 0x14007;
        }
        err = coruna_mach_vm_protect_fec8(*buf,*(uint32_t *)k_persist_mach_task_self_slot,type_id,type_id_8,3,0
                            );
        if (err != 0) {
          return 0x14008;
        }
        coruna_persistb080_trampoline_00010c24(type_id,u,type_id_9);
        _bzero((void *)(type_id_9 + type_id),type_id_8 - type_id_9);
        ptr = _realloc((void *)buf[0x10],(unsigned long)(*(int *)(buf + 0x11) * 0x18 + 0x30));
        if (ptr != (void *)0x0) {
          buf[0x10] = ptr;
          ptr = (unsigned long *)((long)ptr + (unsigned long)*(uint *)(buf + 0x11) * 0x18);
          *(uint *)(buf + 0x11) = *(uint *)(buf + 0x11) + 1;
          ptr[1] = type_id_8;
          ptr[2] = 0;
          *ptr = type_id;
          if (*(long *)(flags + 10) == 0) {
            buf[0x20] = buf[3] + *(long *)(flags + 6);
          }
          version = flags[0x10];
          if (version == 0) {
            return 0;
          }
          type_id_8 = 0;
          status = (int *)buf[0x29];
          addr = buf[0x2a];
          err = (int *)((long)status + addr);
          flags = flags + 0x26;
          do {
            if (addr < 0) {
              return 0x1400a;
            }
            count = flags + -0x14;
            if (count < status) {
              return 0x1400a;
            }
            if (err <= count) {
              return 0x1400a;
            }
            if (flags < status) {
              return 0x1400a;
            }
            if (err < flags) {
              return 0x1400a;
            }
            err = (char)flags[-4];
            port = 1;
            if ((err == '\t') || (err == '\x16')) {
fail:
              *(ushort *)(buf + 0x38) = *(ushort *)(buf + 0x38) | port;
              version = flags[0x10];
            }
            else {
              if (err == '\n') {
                port = 2;
                goto fail;
              }
              err = _strncmp((char *)count,"__eh_frame",0xb);
              if (err == 0) {
                port = 8;
                goto fail;
              }
              err = _strncmp((char *)count,"__unwind_info",0xe);
              if (err == 0) {
                port = 0x10;
                goto fail;
              }
            }
            type_id_8 = type_id_8 + 1;
            flags = flags + 0x14;
            if (version <= type_id_8) {
              return 0;
            }
          } while( true );
        }
        version = 0x2015;
        return version | 0x10000;
      }
    }
  }
  version = 0x4007;
done:
  return version | 0x10000;
}





bool coruna_objc_empty_vtable(char *path)
{
  bool err;
  int err;
  
  err = false;
  if (path != (char *)0x0) {
    err = _strcmp(path,"dyld_stub_binder");
    if ((err == 0) || (err = _strcmp(path,"__objc_empty_vtable"), err == 0)) {
      err = true;
    }
    else {
      err = _strcmp(path,"_objc_readClassPair");
      err = err == 0;
    }
  }
  return err;
}





uint64_t
void coruna_objc_empty_vtable_162d8(long *handle,uint size,char *path,uint64_t val,int flags,unsigned long *arg)
{
  int err;
  unsigned long u;
  long handle;
  long addr;
  
  if (handle == (long *)0x0) {
    return 0xad001;
  }
  addr = *handle;
  if ((addr == 0 || path == (char *)0x0) || arg == (unsigned long *)0x0) {
    return 0xad001;
  }
  if (((*(void (**)(addr + 0xb0) != (void (*)0x0) &&
      (err = (**(void (**)(addr + 0xb0))(*(uint64_t *)(addr + 0xb8),path,val,arg),
      err == 0)) ||
     ((*(char *)(addr + 0x1c) != '\0' &&
      ((*(char *)((long)handle + 0x1c3) != '\0' &&
       *arg = *arg & 0x7fffffffff;
       return 0;
}





uint64_t coruna_dlerror(uint64_t val,long handle,char *path,long addr_2,long *off_3)
{
  char err;
  long handle;
  uint64_t u;
  
  u = 0x910006;
  if (((path != (char *)0x0) && (handle != 0)) && (off_3 != (long *)0x0)) {
    err = *path;
    _dlerror();
    if (err == '_') {
      path = path + 1;
    }
    handle = _dlsym(handle,path);
    _dlerror();
    *off_3 = 0;
    if (handle != 0) {
      u = 0;
      *off_3 = handle + addr_2;
    }
  }
  return u;
}





long coruna_macho_seg19_offset(long handle,int flags,int count_2)
{
  long handle;
  int err;
  int status;
  int *err;
  
  err = *(int *)(*(long *)(handle + 0x170) + 0x10);
  if (err != 0) {
    status = 0;
    err = (int *)(*(long *)(handle + 0x148) + 0x20);
    do {
      if (*err == 0x19) {
        if (status == flags) {
          handle = 0x50;
          if (count_2 == 0) {
            handle = 0x18;
          }
          return *(long *)(handle + handle) + *(long *)(err + 6);
        }
        status = status + 1;
      }
      err = (int *)((long)err + (unsigned long)(uint)err[1]);
      err = err + -1;
    } while (err != 0);
  }
  return 0;
}





uint64_t coruna_persistb080_via_macho_foreach_loadcmd_3(long handle)
{
  uint8_t *ptr;
  uint64_t u;
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  long serial_buf;
  uint8_t *action;
  uint64_t block_ctx;
  void (*stack_guard)(void);
  uint8_t *sa_saved;
  long sa_new;
  
  ptr = k_persist_nsconcretestackblock_slot;
  if (handle == 0) {
    u = 0x17000;
  }
  else {
    if (*(long *)(handle + 0x120) == 0) {
      action = k_persist_nsconcretestackblock_slot;
      block_ctx = k_persist_rodata_word_1ed98;
      stack_guard = coruna_macho_linkedit;
      sa_saved = &k_persist_rodata_word_204f0;
      sa_new = handle;
      u = coruna_macho_foreach_loadcmd(handle,0x19,&action);
      if ((int)u != 0) {
        return u;
      }
    }
    scratch = ptr;
    bootargs = k_persist_rodata_word_1ed98;
    thread_attr = coruna_persistb080_via_persist_residual_47;
    host_info = &k_persist_rodata_word_20510;
    serial_buf = handle;
    u = coruna_macho_foreach_loadcmd(handle,0,&scratch);
  }
  return u;
}





uint64_t coruna_macho_linkedit(long handle,long addr_2)
{
  long handle;
  uint64_t u;
  int err;
  long addr;
  long off;
  
  err = _strncmp((char *)(addr_2 + 8),"__LINKEDIT",0xb);
  if (err == 0) {
    addr = *(long *)(handle + 0x20);
    u = *(uint64_t *)(addr_2 + 0x20);
    handle = *(long *)(addr + 0x18) + *(long *)(addr_2 + 0x18);
    off = *(long *)(addr_2 + 0x28);
    *(long *)(addr + 0x118) = handle;
    *(long *)(addr + 0x120) = handle - off;
    *(uint64_t *)(addr + 0x128) = u;
  }
  return 0;
}





unsigned long coruna_persistb080_via_persist_residual_47(long arg,int *val)

{
  char *obj;
  unsigned long size;
  bool flags;
  int status;
  long serial_7;
  ushort tag;
  long serial_8;
  unsigned long type_id_8;
  unsigned long type_id_14;
  uint type_id_13;
  unsigned long type_id_12;
  long *entry_9;
  uint64_t *block;
  uint64_t **lppu14;
  uint64_t cache_91;
  uint64_t *host_info;
  uint64_t *serial_buf;
  uint8_t *cache_20;
  long block_ctx;
  
  type_id_12 = 0;
  block_ctx = *(long *)k_persist_stack_chk_guard_slot;
  status = *val;
  if (status < 0xb) {
    if (-0x7fffffce < status) {
      if (status == -0x7fffffcd) {
        type_id_12 = 0;
        *(int **)(*(long *)(arg + 0x20) + 400) = val;
      }
      else if (status == -0x7fffffcc) {
        type_id_12 = 0;
        *(int **)(*(long *)(arg + 0x20) + 0x198) = val;
      }
      else if (status == 2) {
        type_id_12 = 0x17001;
        if (*(long *)(*(long *)(arg + 0x20) + 0x120) == 0) {
          type_id_12 = 0x17000;
        }
        else {
          *(int **)(*(long *)(arg + 0x20) + 0x1a0) = val;
          serial_7 = *(long *)(arg + 0x20);
          *(unsigned long *)(serial_7 + 0x1b8) =
               *(long *)(serial_7 + 0x120) + (unsigned long)*(uint *)(*(long *)(serial_7 + 0x1a0) + 0x10);
          serial_7 = *(long *)(arg + 0x20);
          if (*(char *)(serial_7 + 0x1c2) == '\0') {
            if (*(long *)k_persist_stack_chk_guard_slot != block_ctx) {
            ___stack_chk_fail();
            }
            return type_id_12;
            type_id_8 = *(unsigned long *)(serial_7 + 0x1b8);
            type_id_14 = *(unsigned long *)(serial_7 + 8);
            if (((type_id_8 < type_id_14) || (size = type_id_14 + *(long *)(serial_7 + 0x10), size <= type_id_8)) ||
               (serial_8 = *(long *)(serial_7 + 0x1a0), type_id_8 = type_id_8 + *(uint *)(serial_8 + 0x14),
               if (*(long *)k_persist_stack_chk_guard_slot != block_ctx) {
               ___stack_chk_fail();
               }
               return type_id_12;
          }
          else {
            serial_8 = *(long *)(serial_7 + 0x1a0);
          }
          *(unsigned long *)(serial_7 + 0x1a8) = *(long *)(serial_7 + 0x120) + (unsigned long)*(uint *)(serial_8 + 8);
          serial_7 = *(long *)(arg + 0x20);
          if (*(char *)(serial_7 + 0x1c2) == '\0') {
            type_id_13 = 0;
            if (*(long *)(serial_7 + 0x10) + *(unsigned long *)(serial_7 + 8) <= *(unsigned long *)(serial_7 + 0x1a8) ||
                *(unsigned long *)(serial_7 + 0x1a8) < *(unsigned long *)(serial_7 + 8)) {
              type_id_13 = 0x17001;
            }
            type_id_12 = (unsigned long)type_id_13;
          }
          else {
            type_id_12 = 0;
          }
        }
      }
      if (*(long *)k_persist_stack_chk_guard_slot != block_ctx) {
      ___stack_chk_fail();
      }
      return type_id_12;
    }
    if (status != -0x7fffffe8) {
      if (*(long *)k_persist_stack_chk_guard_slot != block_ctx) {
      ___stack_chk_fail();
      }
      return type_id_12;
      type_id_12 = 0;
      *(int **)(*(long *)(arg + 0x20) + 0x188) = val;
      break;
    }
switchD_0001678c_caseD_c:
    type_id_12 = 0x17001;
    obj = (char *)((long)val + (unsigned long)(uint)val[2]);
    entry_9 = *(long **)(arg + 0x20);
    if ((char *)entry_9[0x29] <= obj && obj < (char *)entry_9[0x29] + entry_9[0x2a]) {
      type_id_12 = 0x17004;
      if (*entry_9 != 0) {
        block = (uint64_t *)0x0;
        serial_buf = *(uint64_t **)(*entry_9 + 0xc0);
        cache_20 = &k_persist_rodata_word_24398;
        cache_91 = 0;
        host_info = &k_persist_rodata_word_20860;
        flags = (char)entry_9[0x27] != '\0';
        lppu14 = &serial_buf;
        if (flags) {
          lppu14 = &host_info;
        }
        serial_7 = 1;
        if (!flags) {
          serial_7 = 2;
        }
        do {
          if ((int)type_id_12 == 0x1200d) break;
          if (serial_7 == 0) {
            if ((int)type_id_12 != 0) break;
            break;
          }
          block = *lppu14;
          if (block != (uint64_t *)0x0) {
            cache_91 = 0;
            type_id_12 = (*(void (*)*block)(block,obj,2,&cache_91);
          }
          lppu14 = lppu14 + 1;
          serial_7 = serial_7 + -1;
        } while ((int)type_id_12 != 0);
        type_id_12 = coruna_persist_residual_47(entry_9,block,cache_91);
        if ((int)type_id_12 == 0) {
          serial_7 = *(long *)(arg + 0x20);
          if ((*(char *)(serial_7 + 0x138) == '\0') &&
             (status = _strncmp(obj,"/usr/lib/libobjc.A.d",0x14), status == 0)) {
            type_id_12 = 0;
            *(uint8_t *)(serial_7 + 0x79) = 1;
            *(uint8_t *)(serial_7 + 0x130) = 1;
            *(uint8_t *)(serial_7 + 0x110) = 1;
            if (*(long *)k_persist_stack_chk_guard_slot != block_ctx) {
            ___stack_chk_fail();
            }
            return type_id_12;
          }
          type_id_12 = 0;
        }
        else {
          (*(void (*)block[1])(block,cache_91);
        }
      }
load_ok_28:
      if (*val == -0x7fffffe8) {
        status = _strncmp(obj,"/usr/local/lib/libobjc-env.dylib",0x20);
        type_id_13 = 0;
        if (status != 0) {
          type_id_13 = (uint)type_id_12;
        }
        type_id_12 = (unsigned long)type_id_13;
      }
    }
    if (*(long *)k_persist_stack_chk_guard_slot != block_ctx) {
    ___stack_chk_fail();
    }
    return type_id_12;
  }
  switch(status) {
  case 0xb:
    type_id_12 = 0;
    *(int **)(*(long *)(arg + 0x20) + 0x1b0) = val;
    break;
  case 0xc:
    break;
  case 0xd:
    type_id_12 = 0;
    *(int **)(*(long *)(arg + 0x20) + 0x180) = val;
    break;
  case 0xe:
    break;
  case 0xf:
    serial_7 = *(long *)(arg + 0x20);
    tag = *(ushort *)(serial_7 + 0x1c0) | 0x40;
    type_id_12 = 0;
    *(ushort *)(serial_7 + 0x1c0) = tag;
    break;
  default:
    if (status != 0x1a) {
      if (status != 0x22) break;
      type_id_12 = 0;
      *(int **)(*(long *)(arg + 0x20) + 0x188) = val;
      break;
    }
    serial_7 = *(long *)(arg + 0x20);
    tag = *(ushort *)(serial_7 + 0x1c0) | 4;
    type_id_12 = 0;
    *(ushort *)(serial_7 + 0x1c0) = tag;
  }
switchD_0001678c_caseD_e:
  if (*(long *)k_persist_stack_chk_guard_slot != block_ctx) {
    ___stack_chk_fail();
  }
  return type_id_12;
}





unsigned long coruna_plist_dict(long *arg)

{
  int *flags;
  int *count;
  uint version;
  int status;
  char *block;
  char *ptr;
  char *buf;
  char *entry;
  size_t ls9;
  long *entry_10;
  char *copy;
  unsigned long type_id_9;
  unsigned long type_id_10;
  long serial_9;
  unsigned long type_id_15;
  uint8_t *cache_94;
  uint64_t cache_95;
  void (*cache_96)(void);
  uint8_t *cache_97;
  uint64_t *stack_guard;
  uint64_t *cache_98;
  uint64_t *sa_saved;
  uint64_t cache_99;
  uint64_t *path_buf;
  uint64_t tmp_buf;
  uint32_t cache_100;
  uint64_t plist;
  uint64_t *cache_101;
  uint64_t json_buf;
  uint32_t frame;
  uint64_t work;
  uint64_t *cache;
  uint64_t cache_102;
  uint8_t cache_89;
  uint32_t cache_90[2];
  char *cache_54;
  uint32_t cache_91;
  uint32_t cache_29;
  uint32_t host_info[2];
  uint32_t *serial_buf;
  long cache_20;
  
  cache_20 = *(long *)k_persist_stack_chk_guard_slot;
  type_id_9 = 0xad001;
  if ((arg == (long *)0x0) || (entry_10 = (long *)*arg, entry_10 == (long *)0x0))
  if (*(long *)k_persist_stack_chk_guard_slot == cache_20) {
  return type_id_9;
  }
  ___stack_chk_fail();
  if ((*entry_10 == 0) ||
     ((*(char *)((long)entry_10 + 0x1d) == '\0' || entry_10[1] == 0 || (arg[0x23] == 0)))) {
    type_id_9 = 0;
    if (*(long *)k_persist_stack_chk_guard_slot == cache_20) {
    return type_id_9;
    }
    ___stack_chk_fail();
  }
  stack_guard = &work;
  work = 0;
  cache_102 = k_persist_rodata_word_1ecd8;
  cache_89 = 0;
  cache_98 = &plist;
  plist = 0;
  json_buf = k_persist_rodata_word_1ecd8;
  frame = 0;
  sa_saved = &cache_99;
  cache_99 = 0;
  tmp_buf = k_persist_rodata_word_1ecd8;
  cache_100 = 0;
  cache_94 = k_persist_nsconcretestackblock_slot;
  cache_95 = k_persist_rodata_word_1ece0;
  cache_96 = coruna_wire_store_u32_pair;
  cache_97 = &k_persist_rodata_word_20530;
  path_buf = sa_saved;
  cache_101 = cache_98;
  cache = stack_guard;
  status = coruna_macho_foreach_loadcmd(arg,0x1d,&cache_94);
  type_id_9 = 0;
  if (status == 0) {
    if (*(char *)(cache + 3) == '\0') {
      type_id_9 = 0;
    }
    else {
      type_id_9 = 0xad014;
      if ((*(uint *)(cache_101 + 3) != 0) && (*(int *)(path_buf + 3) != 0)) {
        flags = (int *)((unsigned long)*(uint *)(cache_101 + 3) + arg[0x29]);
        if (*flags != -0x3ff32106) {
          type_id_9 = 0;
        }
        else {
        type_id_15 = 0;
        do {
          version = (flags[2] & 0xff00ff00U) >> 8 | (flags[2] & 0xff00ffU) << 8;
          if ((version >> 0x10 | version << 0x10) <= type_id_15) {
            type_id_9 = 0;
            break;
          }
          if (flags[type_id_15 * 2 + 3] == 0x5000000) {
            version = (flags[type_id_15 * 2 + 4] & 0xff00ff00U) >> 8 |
                    (flags[type_id_15 * 2 + 4] & 0xff00ffU) << 8;
            count = (int *)((long)flags + (unsigned long)(version >> 0x10 | version << 0x10));
            version = (count[1] & 0xff00ff00U) >> 8 | (count[1] & 0xff00ffU) << 8;
            version = version >> 0x10 | version << 0x10;
            if (*count != 0x7171defa || version < 9) {
              type_id_9 = 0xad014;
              break;
            }
            type_id_10 = (unsigned long)(version - 8);
            block = _strndup((char *)(count + 2),type_id_10);
            if (block == (char *)0x0) {
              type_id_9 = 0xad009;
              break;
            }
            ptr = _strstr(block,"<dict>");
            if (ptr == (char *)0x0) {
              ptr = (char *)0x0;
              version = 0xad014;
            }
            else {
              entry = (char *)0x0;
              copy = ptr;
              do {
                buf = entry;
                entry = _strstr(copy,"</dict>");
                copy = entry + 1;
              } while (entry != (char *)0x0);
              if (buf == (char *)0x0) {
                ptr = (char *)0x0;
                version = 0xad014;
              }
              else {
              buf[7] = '\0';
              ptr = _strdup(ptr);
              version = 0xad009;
              if (ptr != (char *)0x0) {
                version = 0;
              }
              }
            }
            type_id_9 = (unsigned long)version;
            _bzero(block,type_id_10);
            _free(block);
            if (version != 0) break;
            type_id_9 = 0xad001;
            if ((ptr != (char *)0x0) && (type_id_9 = 0xad001, *ptr != '\0')) {
              entry_10 = (long *)*arg;
              type_id_9 = 0xad001;
              if (entry_10 != (long *)0x0) {
                serial_9 = *entry_10;
                type_id_9 = 0xad001;
                if (serial_9 != 0) {
                  cache_90[0] = (uint32_t)arg[0xb];
                  cache_54 = ptr;
                  ls9 = _strlen(ptr);
                  cache_91 = (uint32_t)ls9;
                  cache_29 = 1;
                  host_info[0] = 0x40000010;
                  serial_buf = cache_90;
                  type_id_9 = (**(void (**)(serial_9 + 0x40))(serial_9,entry_10 + 1,host_info,1,0);
                }
              }
            }
            ls9 = _strlen(ptr);
            _bzero(ptr,ls9);
            _free(ptr);
          }
          else {
            type_id_9 = 0;
          }
          type_id_15 = type_id_15 + 1;
        } while ((int)type_id_9 == 0);
        }
      }
    }
  }
  __Block_object_dispose(&cache_99,8);
  __Block_object_dispose(&plist,8);
  __Block_object_dispose(&work,8);
load_ok_30:
  if (*(long *)k_persist_stack_chk_guard_slot == cache_20) {
    return type_id_9;
  }
  ___stack_chk_fail();
}





uint64_t coruna_wire_store_u32_pair(long handle,long addr_2)
{
  *(uint8_t *)(*(long *)(*(long *)(handle + 0x20) + 8) + 0x18) = 1;
  *(uint32_t *)(*(long *)(*(long *)(handle + 0x28) + 8) + 0x18) = *(uint32_t *)(addr_2 + 8);
  *(uint32_t *)(*(long *)(*(long *)(handle + 0x30) + 8) + 0x18) = *(uint32_t *)(addr_2 + 0xc);
  return 0;
}





uint64_t coruna_getattrlistbulk_paths(long *handle)
{
  int *err;
  long handle;
  int *status;
  long addr;
  uint u;
  uint size;
  unsigned long version;
  uint64_t port;
  unsigned long tag;
  int *flags;
  unsigned long kind;
  long off;
  unsigned long type_id;
  uint type_id_8;
  unsigned long type_id_9;
  int *count;
  
  port = 0xad001;
  if ((((handle != (long *)0x0) && (flags = (int *)handle[0x29], flags != (int *)0x0)) &&
      (kind = handle[0x2a], kind != 0)) && ((*handle != 0 && (8 < kind)))) {
    if (*flags == -0x35014542 || *flags == -0x41450136) {
      port = 0x12006;
      u = flags[1];
      if (u != 0) {
        type_id_8 = 0;
        type_id = 0;
        off = 0;
        u = (u & 0xff00ff00) >> 8 | (u & 0xff00ff) << 8;
        type_id_9 = (unsigned long)(u >> 0x10 | u << 0x10);
        err = (int *)((long)flags + kind);
        count = flags + 7;
        do {
          if ((long)kind < 0) {
            return 0x12004;
          }
          if (count + -5 < flags) {
            return 0x12004;
          }
          if (err <= count + -5) {
            return 0x12004;
          }
          if (count < flags) {
            return 0x12004;
          }
          if (err < count) {
            return 0x12004;
          }
          u = (count[-3] & 0xff00ff00U) >> 8 | (count[-3] & 0xff00ffU) << 8;
          tag = (unsigned long)(u >> 0x10 | u << 0x10);
          if ((long)kind <= (long)tag) {
            return 0x12005;
          }
          u = (count[-2] & 0xff00ff00U) >> 8 | (count[-2] & 0xff00ffU) << 8;
          version = (unsigned long)(u >> 0x10 | u << 0x10);
          handle = (long)flags + tag;
          status = (int *)(handle + version);
          if (status < flags || err < status) {
            return 0x12005;
          }
          if (count[-5] == 0xc000001) {
            u = (count[-4] & 0xff00ff00U) >> 8;
            u = (u | (count[-4] & 0xff0000U) << 8) >> 0x10 | u << 0x10;
            addr = off;
            tag = type_id;
            size = type_id_8;
            if (type_id_8 <= u) {
              addr = handle;
              tag = version;
              size = u;
            }
            if ((int)u <= *(int *)(*handle + 0x18)) {
              off = addr;
              type_id = tag;
              type_id_8 = size;
            }
          }
          count = count + 5;
          type_id_9 = type_id_9 - 1;
        } while (type_id_9 != 0);
        port = 0x12006;
        if (off != 0) {
          port = 0;
          handle[0x29] = off;
          handle[0x2a] = type_id;
          handle[0x2c] = 0;
        }
      }
    }
    else {
      port = 0;
    }
  }
  return port;
}





uint64_t coruna_bzero_2(long handle)
{
  long *ptr;
  char err;
  byte err;
  ushort u;
  void *buf;
  void *str;
  long *copy;
  void *data;
  unsigned long size;
  uint version;
  long handle;
  unsigned long port;
  unsigned long tag;
  unsigned long kind;
  long addr;
  
  if (handle == 0) {
    return 0x12011;
  }
  addr = *(long *)(handle + 0x1a8);
  if (((addr != 0) && (data = *(void **)(handle + 0x1b8), data != (void *)0x0)) &&
     (handle = *(long *)(handle + 0x1a0), handle != 0)) {
    version = *(uint *)(handle + 0xc);
    kind = (unsigned long)version;
    if ((version != 0) && (*(int *)(handle + 0x14) - 1U < 0x1fffffff)) {
      size = (unsigned long)(version << 4);
      buf = _calloc(size,1);
      if (buf == (void *)0x0) {
        return 0xad009;
      }
      version = *(uint *)(handle + 0x14);
      port = (unsigned long)version;
      str = data;
      if (*(char *)(handle + 0x1c2) == '\0') {
        str = _malloc(port);
        if (str == (void *)0x0) {
          _bzero(buf,size);
          _free(buf);
          return 0xad009;
        }
        coruna_persistb080_trampoline_00010c24(str,data,port);
      }
      tag = 0;
      err = *(char *)(handle + 0x1c4);
      copy = (long *)(addr + 8);
      do {
        err = *(byte *)((long)copy + -4);
        if (((err != '\0') || ((err & 1) != 0)) && ((err & 0xe) != 0 && (err & 0xe0) == 0))
        {
          addr = *copy;
          handle = *(long *)(handle + 0x50);
          u = *(ushort *)((long)copy + -2);
          ptr = (long *)((long)buf + tag * 0x10);
          *ptr = (long)str + (unsigned long)*(uint *)(copy + -1);
          ptr[1] = handle + addr | (unsigned long)(u >> 3) & 1;
          tag = (unsigned long)((int)tag + 1);
        }
        copy = copy + 2;
        kind = kind - 1;
      } while (kind != 0);
      if ((*(uint *)(handle + 0xb0) != 0) && (*(void **)(handle + 0xa8) != (void *)0x0)) {
        _bzero(*(void **)(handle + 0xa8),(unsigned long)*(uint *)(handle + 0xb0) << 4);
        _free(*(void **)(handle + 0xa8));
      }
      if (((*(char *)(handle + 0xc4) == '\0') && (*(uint *)(handle + 0xc0) != 0)) &&
         (*(void **)(handle + 0xb8) != (void *)0x0)) {
        _bzero(*(void **)(handle + 0xb8),(unsigned long)*(uint *)(handle + 0xc0));
        _free(*(void **)(handle + 0xb8));
      }
      if ((int)tag == 0) {
        if (*(char *)(handle + 0x1c2) == '\0') {
          _bzero(str,port);
          _free(str);
        }
        _bzero(buf,size);
        _free(buf);
        buf = (void *)0x0;
        version = 0;
        str = (void *)0x0;
      }
      *(int *)(handle + 0xb0) = (int)tag;
      *(void **)(handle + 0xa8) = buf;
      *(void **)(handle + 0xb8) = str;
      *(uint *)(handle + 0xc0) = version;
      *(uint8_t *)(handle + 0xc4) = *(uint8_t *)(handle + 0x1c2);
      return 0;
    }
  }
  return 0;
}





uint32_t coruna_persistb080_residual_152(long handle,char *path,uint64_t *val)
{
  int err;
  uint32_t u;
  unsigned long size;
  uint64_t *ptr;
  
  u = 0x12011;
  if (((handle != 0) && (path != (char *)0x0)) && (val != (uint64_t *)0x0)) {
    size = (unsigned long)*(uint *)(handle + 0xb0);
    if (*(uint *)(handle + 0xb0) != 0) {
      ptr = (uint64_t *)(*(long *)(handle + 0xa8) + 8);
      do {
        err = _strcmp((char *)ptr[-1],path);
        if (err == 0) {
          *val = *ptr;
          return 0;
        }
        ptr = ptr + 2;
        size = size - 1;
      } while (size != 0);
    }
    u = 0x12001;
  }
  return u;
}





uint64_t coruna_persistb080_via_macho_foreach_loadcmd_4(long *handle,uint64_t val)
{
  uint64_t u;
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  uint64_t serial_buf;
  long *action;
  
  u = 0xad001;
  if ((handle != (long *)0x0) && (*handle != 0)) {
    if ((*(ushort *)(handle + 0x38) & 1) == 0) {
      u = 0;
    }
    else {
      scratch = k_persist_nsconcretestackblock_slot;
      bootargs = k_persist_rodata_word_1ece0;
      thread_attr = coruna_run_starti;
      host_info = &k_persist_rodata_word_20560;
      serial_buf = val;
      action = handle;
      u = coruna_macho_foreach_loadcmd(handle,0x19,&scratch);
    }
  }
  return u;
}





uint64_t coruna_run_starti(long handle,long addr_2)
{
  uint *ptr;
  uint64_t u;
  long handle;
  long addr;
  unsigned long size;
  unsigned long version;
  unsigned long port;
  unsigned long tag;
  unsigned long kind;
  unsigned long type_id;
  
  port = addr_2 + 0x48;
  tag = port + (unsigned long)*(uint *)(addr_2 + 0x40) * 0x50;
  if (port < tag) {
    do {
      if (*(char *)(port + 0x40) == '\x16') {
        kind = *(unsigned long *)(port + 0x28);
        if (kind < 4) goto fail;
        addr = *(long *)(handle + 0x28);
        ptr = (uint *)(*(long *)(addr + 0x18) + *(long *)(port + 0x20));
        type_id = *(unsigned long *)(addr + 0x40);
        version = type_id + *ptr;
        if (version < type_id || *(long *)(addr + 0x48) + type_id <= version) {
          return 0x12008;
        }
        version = 1;
        while (u = (**(void (**)(*(long *)(handle + 0x20) + 0x10))(),
              (int)u == 0 && version < kind >> 2) {
          size = *(unsigned long *)(*(long *)(handle + 0x28) + 0x40);
          type_id = size + ptr[version];
          version = (unsigned long)((int)version + 1);
          if (type_id < size || *(long *)(*(long *)(handle + 0x28) + 0x48) + size <= type_id) {
            return 0x12008;
          }
        }
      }
      else {
        if (*(char *)(port + 0x40) == '\t') {
          handle = *(long *)(handle + 0x28);
          addr = 2;
          if (*(char *)(handle + 0x90) != '\0') {
            addr = 3;
          }
          kind = *(unsigned long *)(port + 0x28) >> addr;
          if (kind != 0) {
            version = 0;
            addr = *(long *)(handle + 0x18) + *(long *)(port + 0x20);
            type_id = 1;
            if (*(char *)(handle + 0x90) == '\0') goto done;
            do {
              size = *(unsigned long *)(addr + version * 8);
              version = type_id;
              while( true ) {
                if (size < *(unsigned long *)(handle + 0x40) ||
                    *(long *)(handle + 0x48) + *(unsigned long *)(handle + 0x40) <= size) {
                  return 0x12008;
                }
                u = (**(void (**)(*(long *)(handle + 0x20) + 0x10))();
                if ((int)u != 0 || kind <= version) goto cleanup;
                handle = *(long *)(handle + 0x28);
                type_id = (unsigned long)((int)version + 1);
                if (*(char *)(handle + 0x90) != '\0') break;
done:
                size = (unsigned long)*(uint *)(addr + version * 4);
                version = type_id;
              }
            } while( true );
          }
        }
fail:
        u = 0;
      }
cleanup:
      port = port + 0x50;
    } while ((int)u == 0 && port < tag);
  }
  else {
    u = 0;
  }
  return u;
}





uint64_t coruna_persistb080_via_macho_foreach_loadcmd_5(long *handle,uint64_t val)
{
  uint32_t u;
  uint64_t size;
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  uint64_t serial_buf;
  long *action;
  
  size = 0xad001;
  if ((handle != (long *)0x0) && (*handle != 0)) {
    if ((*(ushort *)(handle + 0x38) >> 2 & 1) == 0) {
      size = 0;
    }
    else {
      u = 0x11;
      if ((char)handle[0x12] != '\0') {
        u = 0x1a;
      }
      scratch = k_persist_nsconcretestackblock_slot;
      bootargs = k_persist_rodata_word_1ece0;
      thread_attr = coruna_persist_residual_48;
      host_info = &k_persist_rodata_word_20590;
      serial_buf = val;
      action = handle;
      size = coruna_macho_foreach_loadcmd(handle,u,&scratch);
    }
  }
  return size;
}





uint64_t coruna_persist_residual_48(long handle,long addr_2)
{
  uint64_t u;
  long handle;
  unsigned long size;
  
  handle = *(long *)(handle + 0x28);
  if (*(char *)(handle + 0x90) == '\0') {
    size = (unsigned long)*(uint *)(addr_2 + 8);
  }
  else {
    size = *(unsigned long *)(addr_2 + 8);
  }
  size = *(long *)(handle + 0x50) + size;
  if (size < *(unsigned long *)(handle + 0x40) ||
      *(long *)(handle + 0x48) + *(unsigned long *)(handle + 0x40) <= size) {
    return 0x12008;
  }
  u = (**(void (**)(*(long *)(handle + 0x20) + 0x10))();
  return u;
}





uint64_t coruna_persistb080_via_macho_foreach_loadcmd_6(long handle)
{
  uint64_t u;
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  long serial_buf;
  
  if (handle == 0) {
    u = 0xad001;
  }
  else if ((*(ushort *)(handle + 0x1c0) & 0x42) == 2) {
    scratch = k_persist_nsconcretestackblock_slot;
    bootargs = k_persist_rodata_word_1ed98;
    thread_attr = coruna_return_zero_11b5c;
    host_info = &k_persist_rodata_word_205c0;
    serial_buf = handle;
    u = coruna_macho_foreach_loadcmd(handle,0x19,&scratch);
  }
  else {
    u = 0;
  }
  return u;
}





uint64_t coruna_return_zero_11b5c(long handle,long addr_2)
{
  unsigned long u;
  unsigned long size;
  unsigned long version;
  void *ptr;
  unsigned long port;
  uint tag;
  unsigned long kind;
  long handle;
  unsigned long type_id;
  
  u = addr_2 + 0x48;
  kind = u + (unsigned long)*(uint *)(addr_2 + 0x40) * 0x50;
  do {
    if (kind <= u) {
      return 0;
    }
    if ((*(char *)(u + 0x40) == '\n') && (type_id = *(unsigned long *)(u + 0x28), 7 < type_id)) {
      handle = *(long *)(handle + 0x20);
      if (*(long *)(handle + 0x10) < 0) {
        return 0x12009;
      }
      size = *(long *)(handle + 0x18) + *(long *)(u + 0x20);
      port = *(unsigned long *)(handle + 8);
      version = port + *(long *)(handle + 0x10);
      if (size < port || version <= size) {
        return 0x12009;
      }
      if ((long)type_id < 0) {
        return 0x12009;
      }
      if (size + type_id < port || version < size + type_id) {
        return 0x12009;
      }
      if (size == 0) {
        return 0xad001;
      }
      ptr = _realloc(*(void **)(handle + 200),
                        (type_id & 0xfffffffffffffff8) + (unsigned long)(uint)(*(int *)(handle + 0xd0) << 3));
      if (ptr == (void *)0x0) {
        return 0xad009;
      }
      type_id = type_id >> 3;
      *(void **)(handle + 200) = ptr;
      tag = *(uint *)(handle + 0xd0) + 1;
      *(uint64_t *)((long)ptr + (unsigned long)*(uint *)(handle + 0xd0) * 8) =
           *(uint64_t *)(size + (type_id - 1) * 8);
      if (type_id - 1 != 0) {
        do {
          *(uint64_t *)(*(long *)(handle + 200) + (unsigned long)tag * 8) =
               *(uint64_t *)((size - 0x10) + type_id * 8);
          tag = tag + 1;
          type_id = type_id - 1;
        } while (type_id != 1);
      }
      *(uint *)(handle + 0xd0) = tag;
    }
    u = u + 0x50;
  } while( true );
}





uint64_t coruna_persistb080_via_persistb080_via_macho_seg19_offset(long handle)
{
  uint64_t u;
  
  if (handle == 0) {
    return 0xad001;
  }
  if ((*(long *)(handle + 0x188) == 0) && (*(long *)(handle + 0x198) == 0)) {
    if (*(char *)(handle + 0x138) != '\0') {
      return 0x910016;
    }
    u = coruna_persistb080_via_csops_18e40_2();
    return u;
  }
  u = coruna_persistb080_via_macho_seg19_offset();
  return u;
}





uint32_t coruna_persistb080_residual_153(long handle)
{
  uint32_t u;
  
  u = 0xad001;
  if (handle != 0) {
    u = 0;
  }
  return u;
}





uint64_t coruna_bzero_19b24(long handle)
{
  uint64_t u;
  
  if (handle == 0) {
    u = 0xad001;
  }
  else {
    if (((*(char *)(handle + 0x110) == '\0') && (*(void **)(handle + 0x100) != (void *)0x0)) &&
       (*(size_t *)(handle + 0x108) != 0)) {
      _bzero(*(void **)(handle + 0x100),*(size_t *)(handle + 0x108));
    }
    u = 0;
  }
  return u;
}





long * coruna_macho_open_image(long handle,uint size,long addr_2,int flags,uint8_t buf)
{
  long *ptr;
  
  ptr = (long *)0x0;
  if ((((handle != 0) && (size != 0)) && (addr_2 != 0)) &&
     (((flags != 0 && (flags != -1)) && (ptr = _calloc(0x1c8,1), ptr != (long *)0x0)))) {
    ptr[0x29] = handle;
    ptr[0x2a] = (unsigned long)size;
    *ptr = addr_2;
    *(int *)(ptr + 0xb) = flags;
    *(uint32_t *)(ptr + 4) = *(uint32_t *)k_persist_mach_task_self_slot;
    *(uint8_t *)(ptr + 0x27) = buf;
    *(uint8_t *)((long)ptr + 0xfc) = 1;
    *(uint8_t *)((long)ptr + 0x1c3) = 1;
    *(uint8_t *)(ptr + 0x12) = 1;
  }
  return ptr;
}





uint64_t coruna_ctx_free_11dc8(uint64_t *val)
{
  uint64_t u;
  
  if (val != (uint64_t *)0x0) {
    u = coruna_mach_vm_deallocate_11e48();
    val[1] = 0;
    *val = 0;
    val[3] = 0;
    val[2] = 0;
    val[5] = 0;
    val[4] = 0;
    val[7] = 0;
    val[6] = 0;
    val[9] = 0;
    val[8] = 0;
    val[0xb] = 0;
    val[10] = 0;
    val[0xd] = 0;
    val[0xc] = 0;
    val[0xf] = 0;
    val[0xe] = 0;
    val[0x11] = 0;
    val[0x10] = 0;
    val[0x13] = 0;
    val[0x12] = 0;
    val[0x15] = 0;
    val[0x14] = 0;
    val[0x17] = 0;
    val[0x16] = 0;
    val[0x19] = 0;
    val[0x18] = 0;
    val[0x1b] = 0;
    val[0x1a] = 0;
    val[0x1d] = 0;
    val[0x1c] = 0;
    val[0x1f] = 0;
    val[0x1e] = 0;
    val[0x21] = 0;
    val[0x20] = 0;
    val[0x23] = 0;
    val[0x22] = 0;
    val[0x25] = 0;
    val[0x24] = 0;
    val[0x27] = 0;
    val[0x26] = 0;
    val[0x29] = 0;
    val[0x28] = 0;
    val[0x2b] = 0;
    val[0x2a] = 0;
    val[0x2d] = 0;
    val[0x2c] = 0;
    val[0x2f] = 0;
    val[0x2e] = 0;
    val[0x31] = 0;
    val[0x30] = 0;
    val[0x33] = 0;
    val[0x32] = 0;
    val[0x35] = 0;
    val[0x34] = 0;
    val[0x37] = 0;
    val[0x36] = 0;
    val[0x38] = 0;
    _free(val);
    return u;
  }
  return 0xad001;
}





int coruna_mach_vm_deallocate_11e48(long *handle)
{
  int err;
  void (*ptr)(void);
  bool err;
  uint8_t *ptr;
  kern_return_t lk5;
  int status;
  int flags;
  int count;
  int idx;
  long handle;
  void (*buf)(void);
  long *ptr;
  long addr;
  unsigned long u;
  long off;
  unsigned long size;
  unsigned long scratch;
  long bootargs;
  
  idx = 0xad001;
  if ((handle == (long *)0x0) || (*handle == 0)) {
    return 0xad001;
  }
  if ((char)handle[0x27] != '\0') {
    if (((*(char *)((long)handle + 0xfb) == '\0') || (handle[8] == 0)) || (handle[9] == 0)) {
      status = 0;
    }
    else {
      lk5 = _mach_vm_deallocate(*(vm_map_t *)(handle + 0xb),handle[8],handle[9]);
      status = 0;
      if (lk5 != 0) {
        status = 0x14011;
      }
    }
    goto fail;
  }
  if (*(char *)((long)handle + 0xf9) == '\0') {
done:
    status = 0;
    err = true;
  }
  else {
    if (k_persist_cxa_finalize_ranges_slot == (uint8_t *)0x0) {
      ___cxa_finalize(handle[8]);
    }
    else {
      scratch = handle[8];
      bootargs = handle[9];
      ___cxa_finalize_ranges(&scratch,1);
    }
    if ((int)handle[0x1a] == 0) goto done;
    size = 0;
    do {
      buf = *(void (**)(handle[0x19] + size * 8);
      ptr = (void (*)handle[1];
      err = ptr <= buf && buf < ptr + handle[2];
      if (ptr > buf || buf >= ptr + handle[2]) {
        status = 0x12009;
        flags = status;
        if (((char)handle[0x1f] != '\0') && (flags = coruna_persistb080_via_macho_text_seg(*handle,handle,0x3c), !err)) {
        flags = status;
        }
        status = coruna_munmap(handle);
        if (flags != 0) {
        status = flags;
        }
      }
      (*buf)();
      size = size + 1;
    } while (size < *(uint *)(handle + 0x1a));
    status = 0;
  }
cleanup:
  flags = status;
  if (((char)handle[0x1f] != '\0') && (flags = coruna_persistb080_via_macho_text_seg(*handle,handle,0x3c), !err)) {
    flags = status;
  }
  status = coruna_munmap(handle);
  if (flags != 0) {
    status = flags;
  }
fail:
  ptr = k_persist_mach_task_self_slot;
  flags = status;
  if (((*(char *)((long)handle + 0xfa) != '\0') && (handle[1] != 0)) && (handle[2] != 0)) {
    if ((int)handle[0x11] == 0) {
      flags = 0;
    }
    else {
      off = 0;
      size = 0;
      count = 0;
      do {
        scratch = scratch & 0xffffffffffffff00;
        flags = coruna_mach_vm_protect_fec8(*handle,*(uint32_t *)ptr,*(uint64_t *)(handle[0x10] + off),
                             ((uint64_t *)(handle[0x10] + off))[1],3,&scratch);
        err = 0x1400e;
        if ((char)scratch != '\0') {
          err = 0;
        }
        if (flags != 0) {
          err = flags;
        }
        flags = err;
        if (count != 0) {
          flags = count;
        }
        if (err != 0) break;
        _bzero(*(void **)(handle[0x10] + off),((uint64_t *)(handle[0x10] + off))[1]);
        size = size + 1;
        off = off + 0x18;
        count = flags;
      } while (size < *(uint *)(handle + 0x11));
    }
    count = flags;
    if ((char)handle[0xf] == '\0') {
      if (((char)handle[0x1f] != '\0') && (count = coruna_objc_metaclass_prefix(handle), flags != 0)) {
        count = flags;
      }
    }
    else {
      lk5 = _mach_vm_deallocate(*(vm_map_t *)ptr,handle[1],handle[2]);
      err = 0x1400c;
      if (flags != 0) {
        err = flags;
      }
      if (lk5 != 0) {
        count = err;
      }
    }
    *(uint8_t *)(handle + 0xf) = 0;
    *(uint8_t *)((long)handle + 0xfa) = 0;
    handle[1] = 0;
    handle[2] = 0;
    ptr = (long *)*handle;
    if (ptr != (long *)0x0) {
      off = *ptr;
      if (((off == 0) || (*(void (**)(off + 0x28) == (void (*)0x0)) || (ptr[1] == 0)) {
        idx = 0;
      }
      else {
        idx = (**(void (**)(off + 0x28))(off,ptr[1],0xc,(int)handle[0xb]);
      }
    }
    if (count != 0) {
      idx = count;
    }
    flags = idx;
    if (status != 0) {
      flags = status;
    }
    if ((void *)handle[0x10] != (void *)0x0) {
      _free((void *)handle[0x10]);
    }
  }
  if ((*(uint *)(handle + 0x16) != 0) && ((void *)handle[0x15] != (void *)0x0)) {
    _bzero((void *)handle[0x15],(unsigned long)*(uint *)(handle + 0x16) << 4);
    _free((void *)handle[0x15]);
  }
  *(uint32_t *)(handle + 0x16) = 0;
  handle[0x15] = 0;
  if (((*(char *)((long)handle + 0xc4) == '\0') && (*(uint *)(handle + 0x18) != 0)) &&
     ((void *)handle[0x17] != (void *)0x0)) {
    _bzero((void *)handle[0x17],(unsigned long)*(uint *)(handle + 0x18));
    _free((void *)handle[0x17]);
  }
  handle[0x17] = 0;
  *(uint32_t *)(handle + 0x18) = 0;
  *(uint8_t *)((long)handle + 0xc4) = 0;
  if ((void *)handle[0x19] != (void *)0x0) {
    _free((void *)handle[0x19]);
  }
  ptr = (long *)handle[0x1b];
  if (ptr != (long *)0x0) {
    _free(ptr);
  }
  while ((ptr = (long *)handle[0x28]) != (long *)0x0) {
    handle[0x28] = *ptr;
    ptr[1] = 0;
    *ptr = 0;
    ptr[3] = 0;
    ptr[2] = 0;
    _free(ptr);
  }
  size = (unsigned long)*(uint *)(handle + 0x14);
  if ((*(uint *)(handle + 0x14) != 0) && (off = handle[0x13], off != 0)) {
    addr = 0;
    u = 1;
    while( true ) {
      handle = *(long *)(off + addr + 8);
      if ((handle != 0) && (*(void (**)(handle + 8) != (void (*)0x0)) {
        (**(void (**)(handle + 8))(handle,*(uint64_t *)(off + addr));
        size = (unsigned long)*(uint *)(handle + 0x14);
      }
      if (size <= u) break;
      off = handle[0x13];
      u = u + 1;
      addr = addr + 0x10;
    }
    _free((void *)handle[0x13]);
  }
  handle[0x28] = 0;
  handle[0x25] = 0;
  handle[0x24] = 0;
  handle[0x27] = 0;
  handle[0x26] = 0;
  handle[0x21] = 0;
  handle[0x20] = 0;
  handle[0x23] = 0;
  handle[0x22] = 0;
  handle[0x1d] = 0;
  handle[0x1c] = 0;
  handle[0x1f] = 0;
  handle[0x1e] = 0;
  handle[0x19] = 0;
  handle[0x18] = 0;
  handle[0x1b] = 0;
  handle[0x1a] = 0;
  handle[0x15] = 0;
  handle[0x14] = 0;
  handle[0x17] = 0;
  handle[0x16] = 0;
  handle[0x11] = 0;
  handle[0x10] = 0;
  handle[0x13] = 0;
  handle[0x12] = 0;
  handle[0xd] = 0;
  handle[0xc] = 0;
  handle[0xf] = 0;
  handle[0xe] = 0;
  handle[9] = 0;
  handle[8] = 0;
  handle[0xb] = 0;
  handle[10] = 0;
  handle[5] = 0;
  handle[4] = 0;
  handle[7] = 0;
  handle[6] = 0;
  handle[1] = 0;
  *handle = 0;
  handle[3] = 0;
  handle[2] = 0;
  return flags;
}





uint64_t coruna_persistb080_via_mach_vm_protect_fec8(uint64_t *val)
{
  int err;
  
  if (val != (uint64_t *)0x0) {
    if ((((*(char *)(val + 0x26) == '\0') && (val[0x25] != 0)) && (val[0x23] != 0)) &&
       (err = coruna_mach_vm_protect_fec8(*val,*(uint32_t *)k_persist_mach_task_self_slot,val[0x23],
                             val[0x25],3,0), err == 0)) {
      _bzero((void *)val[0x23],val[0x25]);
      val[0x23] = 0;
      val[0x24] = 0;
      val[0x25] = 0;
    }
    val[0x36] = 0;
    val[0x35] = 0;
    val[0x38] = 0;
    val[0x37] = 0;
    val[0x32] = 0;
    val[0x31] = 0;
    val[0x34] = 0;
    val[0x33] = 0;
    val[0x2e] = 0;
    val[0x2d] = 0;
    val[0x30] = 0;
    val[0x2f] = 0;
    val[0x2a] = 0;
    val[0x29] = 0;
    val[0x2c] = 0;
    val[0x2b] = 0;
    *(uint8_t *)((long)val + 0xfc) = 0;
    return 0;
  }
  return 0xad001;
}





uint64_t coruna_persistb080_via_parse_xnu_processors(long handle,long addr_2,uint64_t val,uint size,long *off_3)
{
  unsigned long u;
  unsigned long size;
  long handle;
  unsigned long version;
  uint64_t port;
  char scratch;
  
  port = 0xad001;
  if ((((handle != 0) && (addr_2 != 0)) && ((int)val != 0)) && (off_3 != (long *)0x0)) {
    scratch = '\x01';
    port = coruna_parse_xnu_processors(&scratch);
    if ((int)port == 0) {
      if (scratch == '\0') {
        handle = coruna_macho_open_image(addr_2,val,handle,*(uint32_t *)k_persist_mach_task_self_slot,0)
        ;
        if (handle == 0) {
          port = 0x12002;
        }
        else {
          version = 0;
          *(byte *)(handle + 0x110) = (byte)size & 1;
          *(bool *)(handle + 0x130) = (size & 5) != 0;
          *(byte *)(handle + 0x1c3) = ((byte)((size & 0xff) >> 1) ^ 0xff) & 1;
          *(byte *)(handle + 0x1c4) = (byte)((size & 0xff) >> 4) & 1;
          size = 0xf;
          if ((size & 4) == 0) {
            size = 0x10;
          }
          do {
            u = version + 1;
            port = (*(void (*)(&k_persist_rodata_word_205e0)[version])(handle);
            version = u;
          } while ((int)port == 0 && u < size);
          if ((int)port == 0) {
            *off_3 = handle;
          }
          else {
            coruna_ctx_free_11dc8(handle);
          }
        }
      }
      else {
        port = 0xad008;
      }
    }
  }
  return port;
}





uint64_t coruna_persistb080_via_persistb080_via_macho_text_seg(long *handle)
{
  uint64_t u;
  
  u = 0xad001;
  if ((handle != (long *)0x0) && (*handle != 0)) {
    if (*(char *)((long)handle + 0x79) == '\0') {
      u = 0;
    }
    else {
      u = coruna_persistb080_via_macho_foreach_loadcmd(*handle,handle);
      if ((int)u == 0) {
        u = coruna_persistb080_via_macho_text_seg(*handle,handle,0x28);
        *(bool *)(handle + 0x1f) = (int)u == 0;
        *(uint8_t *)(handle + 0xf) = 0;
      }
    }
  }
  return u;
}





uint64_t coruna_persistb080_via_macho_foreach_loadcmd_7(long *handle)
{
  ushort u;
  uint64_t size;
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  long *serial_buf;
  long *action;
  
  if (handle == (long *)0x0) {
    return 0xad001;
  }
  if (*handle == 0) {
fail:
    size = 0xad001;
  }
  else {
    u = *(ushort *)(handle + 0x38);
    if ((u >> 2 & 1) != 0) {
      scratch = k_persist_nsconcretestackblock_slot;
      bootargs = k_persist_rodata_word_1ed98;
      thread_attr = coruna_persist_residual_49;
      host_info = &k_persist_rodata_word_206b0;
      serial_buf = handle;
      size = coruna_macho_foreach_loadcmd(handle,0x1a,&scratch);
      if ((int)size != 0) {
        return size;
      }
      if (*handle == 0) goto fail;
      u = *(ushort *)(handle + 0x38);
    }
    if ((u & 1) != 0) {
      serial_buf = (long *)handle[3];
      scratch = k_persist_nsconcretestackblock_slot;
      bootargs = k_persist_rodata_word_1ed98;
      thread_attr = coruna_return_zero_12e78;
      host_info = &k_persist_rodata_word_206d0;
      action = handle;
      size = coruna_macho_foreach_loadcmd(handle,0x19,&scratch);
      if ((int)size != 0) {
        return size;
      }
    }
    size = 0;
    *(uint8_t *)((long)handle + 0xf9) = 1;
  }
  return size;
}





uint64_t coruna_persistb080_via_macho_open_image(long handle,long addr_2,int flags,uint size,long *off_3)
{
  int err;
  bool err;
  long handle;
  uint64_t u;
  unsigned long size;
  
  u = 0xad001;
  if (((handle != 0) && (addr_2 != 0)) && (off_3 != (long *)0x0)) {
    err = 0xfffffff;
    if (flags != 0) {
      err = flags;
    }
    handle = coruna_macho_open_image(addr_2,err,handle,*(uint32_t *)k_persist_mach_task_self_slot,0);
    if (handle == 0) {
      u = 0x12002;
    }
    else {
      *(uint16_t *)(handle + 0x1c2) = 1;
      *(uint8_t *)(handle + 0x110) = 1;
      *(uint8_t *)(handle + 0x130) = 1;
      *(byte *)(handle + 0x1c4) = (byte)(size >> 4) & 1;
      size = 0;
      do {
        u = (*(void (*)(&k_persist_rodata_word_20660)[size])(handle);
        err = size < 3;
        size = size + 1;
      } while ((int)u == 0 && err);
      if ((int)u == 0) {
        *off_3 = handle;
      }
      else {
        coruna_ctx_free_11dc8(handle);
      }
    }
  }
  return u;
}





uint64_t coruna_persistb080_via_mach_vm_deallocate_11e48(void *ctx)
{
  uint64_t u;
  
  if (ctx == (void *)0x0) {
    u = 0xad001;
  }
  else {
    if (*(char *)((long)ctx + 0xfc) == '\0') {
      coruna_mach_vm_deallocate_11e48(ctx);
      _free(ctx);
    }
    else {
      coruna_ctx_free_11dc8(ctx);
    }
    u = 0;
  }
  return u;
}





uint64_t coruna_resolve_libcache_sym(uint64_t *val,short *arg,long handle,char *path)
{
  char *ptr;
  int *err;
  bool err;
  bool status;
  int err;
  uint64_t *ptr;
  long handle;
  long addr;
  long off;
  long base;
  long ctx_val;
  int *status;
  uint64_t u;
  long scratch;
  
  u = 0xad001;
  if ((val != (uint64_t *)0x0) &&
     ((arg == (short *)0x0 || ((*arg == 2 && (1 < (ushort)arg[1])))))) {
    ptr = "\x01";
    if (path != (char *)0x0) {
      ptr = path;
    }
    ptr = _calloc(1,0x178);
    if (ptr == (uint64_t *)0x0) {
      u = 0xad009;
    }
    else {
      handle = __NSGetMachExecuteHeader();
      ptr[0x19] = handle;
      addr = __NSGetArgc();
      ptr[0x1a] = addr;
      off = __NSGetArgv();
      ptr[0x1b] = off;
      base = __NSGetEnviron();
      ptr[0x1c] = base;
      ctx_val = __NSGetProgname();
      ptr[0x1d] = ctx_val;
      if ((((handle == 0) || (addr == 0)) || (off == 0)) || (base == 0)) {
        u = 0x1200f;
      }
      else {
        u = 0x1200f;
        if ((ctx_val != 0) && (u = coruna_csops_128d4((long)ptr + 0x1d), (int)u == 0)) {
          if ((*ptr == '\0') || (err = coruna_dladdr_142c0(), err != 0)) {
            err = (int *)((unsigned long)k_persist_dladdr_slot & 0xfffffffffffff000);
            do {
              status = err;
              err = status + -0x400;
            } while (*status != -0x1120531);
            *(uint *)(ptr + 3) = status[2] & 0xffffff;
            err = arg != (short *)0x0;
            status = handle == 0;
            scratch = handle;
            if ((!err || !status) ||
               (u = (**(void (**)(arg + 0xc))(arg,0,&scratch), (int)u == 0)) {
              *ptr = arg;
              ptr[1] = scratch;
              *(bool *)(ptr + 2) = err && status;
              *(char *)((long)ptr + 0x1c) = *ptr;
              u = _dlopen("/usr/lib/system/libcache.dylib",0x12);
              ptr[4] = u;
              u = coruna_load_libobjc_path(ptr);
              if ((int)u == 0) {
                u = coruna_task_info(ptr);
                if ((int)u == 0) {
                  *val = ptr;
                  return u;
                }
                coruna_pthread_mutex_destroy(ptr);
              }
              if (err && status) {
                (**(void (**)(arg + 0x10))(arg,ptr[1]);
                ptr[1] = 0;
              }
            }
          }
          else {
            u = 0x12010;
          }
        }
      }
      _free(ptr);
    }
  }
  return u;
}





void coruna_csops_128d4(byte *arg)
{
  pid_t lp1;
  int err;
  uint u;
  int *err;
  uint *ptr;
  byte err;
  uint8_t scratch[3];
  byte bootargs;
  uint64_t thread_attr;
  uint64_t scratch;
  uint32_t host_info;
  long serial_buf;
  
  serial_buf = *(long *)k_persist_stack_chk_guard_slot;
  thread_attr = 0;
  scratch = 0;
  host_info = 0;
  if (k_persist_rodata_word_1ed00 <= *(double *)k_persist_dyldversionnumber_slot) {
    lp1 = _getpid();
    err = _csops(lp1,0,scratch,4);
    if (err < 0) goto fail;
    err = bootargs >> 5 & 1;
  }
  else {
    lp1 = _getpid();
    err = _csops(lp1,5,&thread_attr,0x14);
    if (err < 0) {
      err = ___error();
      if (*err == 0x55) {
        u = 0;
        *arg = 0;
        if (*(long *)k_persist_stack_chk_guard_slot == serial_buf) {
        return;
        }
        ___stack_chk_fail(u);
      }
fail:
      err = ___error();
      err = *err;
      ptr = (uint *)___error();
      u = -*ptr;
      if (-1 < err) {
        u = *ptr;
      }
      u = u | 0x40000000;
      if (*(long *)k_persist_stack_chk_guard_slot == serial_buf) {
      return;
      }
      ___stack_chk_fail(u);
    }
    err = 1;
  }
  u = 0;
  *arg = err;
done:
  if (*(long *)k_persist_stack_chk_guard_slot == serial_buf) {
    return;
  }
  ___stack_chk_fail(u);
}





unsigned long coruna_ctx_free_129d0(long *arg)

{
  uint u;
  unsigned long size;
  long serial;
  
  if (arg == (long *)0x0) {
    size = 0xad001;
  }
  else {
    size = coruna_pthread_mutex_destroy();
    if (((char)arg[2] != '\0') && (serial = *arg, serial != 0)) {
      u = (**(void (**)(serial + 0x20))(serial,arg[1]);
      if ((uint)size != 0) {
        u = (uint)size;
      }
      size = (unsigned long)u;
    }
    arg[0x2e] = 0;
    arg[0x2b] = 0;
    arg[0x2a] = 0;
    arg[0x2d] = 0;
    arg[0x2c] = 0;
    arg[0x27] = 0;
    arg[0x26] = 0;
    arg[0x29] = 0;
    arg[0x28] = 0;
    arg[0x23] = 0;
    arg[0x22] = 0;
    arg[0x25] = 0;
    arg[0x24] = 0;
    arg[0x1f] = 0;
    arg[0x1e] = 0;
    arg[0x21] = 0;
    arg[0x20] = 0;
    arg[0x1b] = 0;
    arg[0x1a] = 0;
    arg[0x1d] = 0;
    arg[0x1c] = 0;
    arg[0x17] = 0;
    arg[0x16] = 0;
    arg[0x19] = 0;
    arg[0x18] = 0;
    arg[0x13] = 0;
    arg[0x12] = 0;
    arg[0x15] = 0;
    arg[0x14] = 0;
    arg[0xf] = 0;
    arg[0xe] = 0;
    arg[0x11] = 0;
    arg[0x10] = 0;
    arg[0xb] = 0;
    arg[10] = 0;
    arg[0xd] = 0;
    arg[0xc] = 0;
    arg[7] = 0;
    arg[6] = 0;
    arg[9] = 0;
    arg[8] = 0;
    arg[3] = 0;
    arg[2] = 0;
    arg[5] = 0;
    arg[4] = 0;
    arg[1] = 0;
    *arg = 0;
    _free(arg);
  }
  return size;
}





uint64_t coruna_persistb080_via_helper_17398_1d538(long *handle,long addr_2,long off_3)
{
  uint64_t u;
  long handle;
  long scratch;
  
  u = 0xad001;
  if ((handle != (long *)0x0) && (addr_2 != 0)) {
    scratch = off_3;
    if ((off_3 != 0) ||
       (u = (**(void (**)(addr_2 + 0x18))(addr_2,0,&scratch), (int)u == 0)) {
      handle = *handle;
      if ((handle != 0) && ((char)handle[2] != '\0')) {
        (**(void (**)(handle + 0x20))(handle,handle[1]);
      }
      *handle = addr_2;
      handle[1] = scratch;
      *(bool *)(handle + 2) = off_3 == 0;
      if (((int)handle[10] != 2) || (u = coruna_persistb080_via_persistb080_via_persistb080_via_mach_vm_region_recurse(handle,handle + 0xb), (int)u == 0))
      {
        if ((int)handle[0x23] == 1) {
          u = coruna_helper_17398_1d538(handle,handle + 0x24);
        }
        else {
          u = 0;
        }
      }
    }
  }
  return u;
}





uint64_t coruna_persistb080_via_macho_foreach_loadcmd_8(long handle)
{
  uint64_t u;
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  long serial_buf;
  
  if (handle == 0) {
    u = 0xad001;
  }
  else if (*(char *)(handle + 0xfc) == '\0') {
    u = 0x12012;
  }
  else {
    scratch = k_persist_nsconcretestackblock_slot;
    bootargs = k_persist_rodata_word_1ed98;
    thread_attr = coruna_macho_pagezero_18a8c;
    host_info = &k_persist_rodata_word_206f0;
    serial_buf = handle;
    u = coruna_macho_foreach_loadcmd(handle,0x19,&scratch);
  }
  return u;
}





uint64_t coruna_csops_12bb0(long *handle)
{
  pid_t lp1;
  int err;
  uint64_t u;
  uint64_t scratch;
  uint64_t scratch;
  uint32_t bootargs;
  long thread_attr;
  
  thread_attr = *(long *)k_persist_stack_chk_guard_slot;
  u = 0xad00a;
  if (handle == (long *)0x0) {
    u = 0xad001;
  }
  else if (((*handle != 0) && (*(long *)(*handle + 0x28) != 0)) && (handle[1] != 0)) {
    scratch = 0;
    scratch = 0;
    bootargs = 0;
    lp1 = _getpid();
    err = _csops(lp1,5,&scratch,0x14);
    if (err < 0) {
      u = 0xad00b;
    }
    else {
      u = (**(void (**)(*handle + 0x28))(*handle,handle[1],0x40000105,&scratch);
    }
  }
  if (*(long *)k_persist_stack_chk_guard_slot == thread_attr) {
    return u;
  }
  ___stack_chk_fail();
}





uint64_t coruna_macho_text_seg_186f4(long handle,long addr_2)
{
  int err;
  long handle;
  uint64_t u;
  unsigned long size;
  
  u = 0x14002;
  size = *(unsigned long *)(addr_2 + 0x20);
  if (!CARRY8(*(unsigned long *)(*(long *)(*(long *)(handle + 0x20) + 8) + 0x18),size)) {
    if ((*(long *)(addr_2 + 0x28) == 0) && (*(long *)(addr_2 + 0x30) != 0)) {
      handle = *(long *)(*(long *)(handle + 0x28) + 8);
      if (*(long *)(handle + 0x18) == 0) {
        u = 0;
        *(uint64_t *)(handle + 0x18) = *(uint64_t *)(addr_2 + 0x18);
      }
      else {
        u = 0x14003;
      }
    }
    else {
      u = 0;
    }
    err = _strcmp((char *)(addr_2 + 8),"__TEXT");
    if (err == 0) {
      *(long *)(*(long *)(*(long *)(handle + 0x30) + 8) + 0x18) = addr_2;
    }
    if (size < 0xffffffff) {
      handle = *(long *)(*(long *)(handle + 0x20) + 8);
      *(unsigned long *)(handle + 0x18) = *(long *)(handle + 0x18) + size;
    }
  }
  return u;
}





uint64_t coruna_dlopen(uint64_t val,char *path,uint64_t id_2,long *handle)
{
  int err;
  long handle;
  uint64_t u;
  
  u = 0x1200b;
  if ((path != (char *)0x0) && (handle != (long *)0x0)) {
    handle = _dlopen(path,id_2);
    if (handle == 0) {
      err = _strncmp(path,"@rpath",6);
      if (err != 0) {
        return 0x17004;
      }
      handle = _dlopen(path + 6,id_2);
      if (handle == 0) {
        return 0x17004;
      }
    }
    u = 0;
    *handle = handle;
  }
  return u;
}





uint64_t coruna_dlclose(uint64_t val,long handle)
{
  if (handle != 0) {
    _dlclose(handle);
    return 0;
  }
  return 0x1200c;
}





uint64_t coruna_dlclose_12dcc(uint64_t val,uint64_t id_2)
{
  _dlclose(id_2);
  return 0;
}





uint64_t coruna_persist_residual_49(long handle,long addr_2)
{
  void (*ptr)(void);
  uint64_t u;
  long *ptr;
  long handle;
  void (*buf)(void);
  uint64_t scratch;
  uint32_t *bootargs;
  uint64_t *thread_attr;
  uint64_t *host_info;
  uint64_t serial_buf;
  
  ptr = *(long **)(handle + 0x20);
  ptr = (void (*)(ptr[3] + *(long *)(addr_2 + 8));
  buf = (void (*)ptr[1];
  if ((ptr >= buf && ptr <= buf + ptr[2]) &&
      (ptr < buf || buf + ptr[2] != ptr)) {
    handle = *ptr;
    bootargs = *(uint32_t **)(handle + 0xd0);
    scratch = *(uint64_t *)(handle + 200);
    serial_buf = *(uint64_t *)(handle + 0xe8);
    host_info = *(uint64_t **)(handle + 0xe0);
    thread_attr = *(uint64_t **)(handle + 0xd8);
    (*ptr)(*bootargs,*thread_attr,*host_info,0,&scratch);
    u = 0;
  }
  else {
    u = 0x12008;
  }
  return u;
}





uint64_t coruna_return_zero_12e78(long handle,long addr_2)
{
  bool err;
  unsigned long u;
  void (*ptr)(void);
  void (*buf)(void);
  unsigned long size;
  long *ptr;
  long handle;
  long addr;
  long off;
  unsigned long version;
  unsigned long port;
  uint64_t scratch;
  uint32_t *bootargs;
  uint64_t *thread_attr;
  uint64_t *host_info;
  uint64_t serial_buf;
  unsigned long tag;
  
  u = addr_2 + 0x48;
  version = u + (unsigned long)*(uint *)(addr_2 + 0x40) * 0x50;
  do {
    if (version <= u) {
      return 0;
    }
    if (*(char *)(u + 0x40) == '\x16') {
      size = *(unsigned long *)(u + 0x28);
      if (3 < size) {
        addr = *(long *)(u + 0x20);
        off = *(long *)(handle + 0x20);
        tag = 0;
        port = 1;
        do {
          ptr = *(long **)(handle + 0x28);
          ptr = (void (*)ptr[1];
          buf = ptr + *(uint *)(off + addr + tag * 4);
          if (buf < ptr || ptr + ptr[2] <= buf) {
            return 0x12008;
          }
          handle = *ptr;
          bootargs = *(uint32_t **)(handle + 0xd0);
          scratch = *(uint64_t *)(handle + 200);
          serial_buf = *(uint64_t *)(handle + 0xe8);
          host_info = *(uint64_t **)(handle + 0xe0);
          thread_attr = *(uint64_t **)(handle + 0xd8);
          (*buf)(*bootargs,*thread_attr,*host_info,0,&scratch);
          err = port < size >> 2;
          tag = port;
          port = (unsigned long)((int)port + 1);
        } while (err);
      }
    }
    else if ((*(char *)(u + 0x40) == '\t') && (size = *(unsigned long *)(u + 0x28), 7 < size)) {
      addr = *(long *)(u + 0x20);
      off = *(long *)(handle + 0x20);
      tag = 0;
      port = 1;
      do {
        buf = *(void (**)(off + addr + tag * 8);
        ptr = *(long **)(handle + 0x28);
        if (buf < (void (*)ptr[1] || (void (*)ptr[1] + ptr[2] <= buf) {
          return 0x12008;
        }
        handle = *ptr;
        bootargs = *(uint32_t **)(handle + 0xd0);
        scratch = *(uint64_t *)(handle + 200);
        serial_buf = *(uint64_t *)(handle + 0xe8);
        host_info = *(uint64_t **)(handle + 0xe0);
        thread_attr = *(uint64_t **)(handle + 0xd8);
        (*buf)(*bootargs,*thread_attr,*host_info,0,&scratch);
        err = port < size >> 3;
        tag = port;
        port = (unsigned long)((int)port + 1);
      } while (err);
    }
    u = u + 0x50;
  } while( true );
}





void coruna_macho_pagezero_18a8c(long handle,long addr_2)
{
  int err;
  uint64_t *ptr;
  uint8_t scratch;
  
  err = _strncmp((char *)(addr_2 + 8),"__PAGEZERO",0xb);
  if (err != 0) {
    ptr = *(uint64_t **)(handle + 0x20);
    scratch = 0;
    coruna_persistb080_via_persistb080_via_mach_vm_region_recurse(*ptr,*(uint32_t *)(ptr + 0xb),ptr[10] + *(long *)(addr_2 + 0x18),
                 *(uint64_t *)(addr_2 + 0x20),&scratch);
  }
  return;
}





uint64_t coruna_persistb080_residual_154(long handle,unsigned long *arg)
{
  unsigned long u;
  unsigned long size;
  uint64_t version;
  unsigned long port;
  uint64_t scratch;
  
  version = 0xad001;
  if ((((handle != 0) && (arg != (unsigned long *)0x0)) && (arg[1] != 0)) &&
     (port = *arg, port != 0)) {
    version = 0x910007;
    if ((byte)arg[4] - 1 < 3) {
      size = *(unsigned long *)(handle + 0x40);
      u = *(long *)(handle + 0x48) + size;
      if ((((size <= u) && (size <= port)) &&
          ((port < u && ((port < 0xfffffffffffffff8 && (size <= port + 8)))))) &&
         (port + 8 <= u)) {
        scratch = 0;
        version = coruna_persistb080_residual_157(*(uint64_t *)(handle + 0x98),*(uint32_t *)(handle + 0xa0),
                             *(uint32_t *)((long)arg + 0x24),&scratch);
        if ((int)version == 0) {
          version = coruna_persistb080_via_objc_empty_vtable(scratch,arg);
        }
      }
    }
    else {
      version = 0x91000e;
    }
  }
  return version;
}





uint64_t coruna_persistb080_residual_155(long handle,uint64_t *val,int *flags)
{
  void *ptr;
  unsigned long u;
  uint64_t *ptr;
  char *ptr;
  uint64_t size;
  unsigned long version;
  
  size = 0xad001;
  if (((handle != 0) && (val != (uint64_t *)0x0)) && (flags != (int *)0x0)) {
    version = (unsigned long)*(uint *)(handle + 0xa0);
    if (*(uint *)(handle + 0xa0) == 0) {
      size = 0;
      *val = 0;
      *flags = 0;
    }
    else {
      ptr = _calloc(version,8);
      if (ptr == (void *)0x0) {
        size = 0xad009;
      }
      else {
        u = 0;
        ptr = (uint64_t *)(*(long *)(handle + 0x98) + 8);
        do {
          ptr = (char *)ptr[-1];
          if ((ptr == (char *)0x0) || ((uint64_t *)*ptr != &k_persist_rodata_word_20860)) {
            size = 0x910014;
            goto fail;
          }
          if ((*ptr == '\0') || (*(long *)(ptr + 0x10) != 0)) {
            *(char **)((long)ptr + u * 8) = ptr;
            u = (unsigned long)((int)u + 1);
          }
          ptr = ptr + 2;
          version = version - 1;
        } while (version != 0);
        size = 0;
        if ((int)u == 0) {
          *val = 0;
          *flags = 0;
fail:
          _free(ptr);
        }
        else {
          *val = ptr;
          *flags = (int)u;
        }
      }
    }
  }
  return size;
}





uint64_t coruna_persistb080_via_mach_vm_allocate(uint64_t *val,long handle,long addr_2,uint size,unsigned long arg)
{
  long handle;
  uint64_t u;
  long scratch [3];
  unsigned long scratch;
  uint64_t bootargs;
  uint64_t bootargs;
  long thread_attr;
  uint64_t thread_attr;
  unsigned long host_info;
  uint64_t host_info;
  
  u = 0xad001;
  if ((val != (uint64_t *)0x0) && ((addr_2 != 0 || (size == 0)))) {
    if (handle == 0) {
      u = 0x1e010;
    }
    else {
      scratch[0] = 0;
      u = coruna_mach_vm_allocate(*(uint32_t *)(val + 0xb),0x80000,0x1e000001,scratch);
      handle = scratch[0];
      if ((int)u == 0) {
        scratch[1] = 0;
        scratch = (unsigned long)size;
        bootargs = val[9];
        bootargs = val[8];
        thread_attr = scratch[0];
        thread_attr = 0x80000;
        host_info = arg & 0xffffffff;
        host_info = 0;
        scratch[0] = handle;
        scratch[2] = addr_2;
        u = coruna_mach_port_deallocate_1c3fc(*(uint64_t *)*val,((uint64_t *)*val)[1],
                             *(uint32_t *)(val + 0xb),*(uint8_t *)(val + 0x12),scratch
                             ,handle,0x80000);
        if ((int)u != 0) {
          coruna_mach_vm_deallocate_1b998(*(uint32_t *)(val + 0xb),handle,0x80000,0);
        }
      }
    }
  }
  return u;
}





uint64_t coruna_persistb080_residual_156(long handle)
{
  uint64_t u;
  
  if (handle != 0) {
    u = coruna_persistb080_residual_158();
    return u;
  }
  return 0xad001;
}





uint64_t
void coruna_persistb080_via_macho_open_image_2(long handle,uint64_t val,long addr_2,uint64_t id_2,byte arg,
            long *off_3)
{
  unsigned long u;
  unsigned long size;
  long handle;
  unsigned long version;
  uint64_t port;
  
  port = 0xad001;
  if ((((handle != 0) && ((int)val != 0)) && ((int)val != -1)) &&
     (((addr_2 != 0 && ((int)id_2 != 0)) && (off_3 != (long *)0x0)))) {
    handle = coruna_macho_open_image(addr_2,id_2,handle,val,1);
    if (handle == 0) {
      port = 0x12002;
    }
    else {
      version = 0;
      *(byte *)(handle + 0x110) = arg & 1;
      *(bool *)(handle + 0x130) = (arg & 5) != 0;
      *(uint16_t *)(handle + 0x1c3) = 0;
      size = 0x10;
      if ((arg & 4) == 0) {
        size = 0x11;
      }
      do {
        u = version + 1;
        port = (*(void (*)(&k_persist_rodata_word_20710)[version])(handle);
        version = u;
      } while ((int)port == 0 && u < size);
      if ((int)port == 0) {
        *off_3 = handle;
      }
      else {
        coruna_ctx_free_11dc8(handle);
      }
    }
  }
  return port;
}





uint64_t coruna_persistb080_via_sysctlnametomib(long handle)
{
  uint64_t u;
  
  if (handle == 0) {
    u = 0xad001;
  }
  else {
    u = coruna_mach_vm_read_overwrite_1bb8c(*(uint32_t *)(handle + 0x20),handle + 0x30,handle + 0x38);
    if ((((int)u == 0) &&
        (u = coruna_mach_vm_read_overwrite_1bb8c(*(uint32_t *)(handle + 0x58),handle + 0x68,handle + 0x70),
        (int)u == 0)) &&
       (u = coruna_sysctlnametomib(*(uint32_t *)(handle + 0x20),handle + 0x24,handle + 0x28),
       (int)u == 0)) {
      u = coruna_sysctlnametomib(*(uint32_t *)(handle + 0x58),handle + 0x5c,handle + 0x60);
      return u;
    }
  }
  return u;
}





void coruna_block_dispose_191e8_stub(uint64_t val)
{
  coruna_block_dispose_191e8(val,1);
  return;
}





uint64_t coruna_persistb080_via_persistb080_via_macho_foreach_loadcmd_5(long handle)
{
  uint64_t u;
  
  if (handle == 0) {
    u = 0xad001;
  }
  else {
    u = coruna_persistb080_via_macho_foreach_loadcmd_5(handle,&k_persist_nsconcreteglobalblock_slot);
    if ((int)u == 0) {
      u = coruna_persistb080_via_macho_foreach_loadcmd_4(handle,&k_persist_nsconcreteglobalblock_slot);
      return u;
    }
  }
  return u;
}





uint32_t coruna_mach_vm_protect_13514(long handle)
{
  kern_return_t lk1;
  uint32_t u;
  
  if (handle == 0) {
    u = 0xad001;
  }
  else {
    u = 0x910016;
    if (((*(mach_vm_address_t *)(handle + 8) != 0) && (*(long *)(handle + 0x40) != 0)) &&
       (*(mach_vm_size_t *)(handle + 0x10) == *(mach_vm_size_t *)(handle + 0x48))) {
      lk1 = _mach_vm_protect(*(vm_map_t *)k_persist_mach_task_self_slot,
                               *(mach_vm_address_t *)(handle + 8),
                               *(mach_vm_size_t *)(handle + 0x10),0,3);
      if (lk1 == 0) {
        lk1 = _mach_vm_protect(*(vm_map_t *)(handle + 0x58),
                                 *(mach_vm_address_t *)(handle + 0x40),
                                 *(mach_vm_size_t *)(handle + 0x48),0,3);
        if (lk1 == 0) {
          lk1 = _mach_vm_write(*(vm_map_t *)(handle + 0x58),
                                 *(mach_vm_address_t *)(handle + 0x40),
                                 *(vm_offset_t *)(handle + 8),
                                 *(mach_msg_type_number_t *)(handle + 0x48));
          u = 0;
          if (lk1 != 0) {
            u = 0x1e015;
          }
        }
        else {
          u = 0x1e017;
        }
      }
      else {
        u = 0x1e016;
      }
    }
  }
  return u;
}





uint64_t coruna_persistb080_via_macho_open_image_3(long handle,uint64_t val,long addr_2,uint64_t id_2)
{
  bool err;
  long handle;
  uint64_t u;
  unsigned long size;
  
  u = 0xad001;
  if ((((handle != 0) && ((int)val != 0)) && ((int)val != -1)) &&
     ((addr_2 != 0 && ((int)id_2 != 0)))) {
    handle = coruna_macho_open_image(addr_2,id_2,handle,val,1);
    if (handle == 0) {
      u = 0x12002;
    }
    else {
      size = 0;
      do {
        u = (*(void (*)(&k_persist_rodata_word_20798)[size])(handle);
        err = size < 2;
        size = size + 1;
      } while ((int)u == 0 && err);
      coruna_ctx_free_11dc8(handle);
    }
  }
  return u;
}





void coruna_helper_134bc_19108(uint64_t val)
{
  coruna_block_dispose_191e8(val,0);
  return;
}
uint64_t coruna_persistb080_via_dladdr_1bd4c(long handle,long *addr_2)
{
  uint64_t u;
  long scratch;
  
  u = 0xad001;
  if ((handle != 0) && (addr_2 != (long *)0x0)) {
    scratch = *addr_2;
    if ((scratch != 0) && (*(char *)(handle + 0x138) != '\0')) {
      if ((*(char *)(handle + 0x38) == '\0') || (*(char *)(handle + 0x70) == '\0')) {
        u = coruna_dladdr_1bd4c(*(uint32_t *)(handle + 0x58),scratch,&scratch);
        if ((int)u != 0) {
          return u;
        }
      }
      else if (*(long *)(handle + 0x68) != *(long *)(handle + 0x30)) {
        scratch = (scratch - *(long *)(handle + 0x30)) + *(long *)(handle + 0x68);
      }
    }
    u = 0;
    *addr_2 = scratch;
  }
  return u;
}





unsigned long coruna_block_dispose_191e8(long *arg,unsigned long val)

{
  uint u;
  uint size;
  unsigned long version;
  long *entry_11;
  uint64_t cache_54;
  uint64_t bootargs;
  uint64_t host_info;
  uint8_t *serial_buf;
  uint64_t cache_20;
  void (*block_ctx)(void);
  uint8_t *scratch;
  uint64_t *thread_attr;
  uint64_t cache_79;
  uint64_t *cache_80;
  uint64_t cache_103;
  uint8_t cache_22;
  
  if (arg == (long *)0x0) {
    return 0xad001;
  }
  entry_11 = (long *)*arg;
  if (entry_11 == (long *)0x0) {
    return 0x1e004;
  }
  if ((*(char *)((long)entry_11 + 0x1d) != '\0') && (*entry_11 == 0)) {
    return 0x1e004;
  }
  cache_80 = &cache_79;
  cache_79 = 0;
  cache_103 = k_persist_rodata_word_1ecd8;
  cache_22 = 0;
  if ((val & 1) == 0) {
    cache_22 = 1;
  }
  else {
    serial_buf = k_persist_nsconcretestackblock_slot;
    cache_20 = k_persist_rodata_word_1ece0;
    block_ctx = coruna_wire_export_on_err;
    scratch = &k_persist_rodata_word_207b0;
    thread_attr = cache_80;
    version = coruna_macho_foreach_loadcmd(arg,0,&serial_buf);
    __Block_object_dispose(&cache_79,8);
    return version;
    if (*(char *)(cache_80 + 3) == '\0') {
      version = 0x910016;
      __Block_object_dispose(&cache_79,8);
      return version;
    }
  }
  cache_54 = 0;
  bootargs = 0;
  host_info = 0;
  size = coruna_task_info_1bfa8((int)arg[0xb],&cache_54);
  u = 0x1e003;
  if (cache_54 != '\0') {
    u = 0;
  }
  if (size != 0) {
    u = size;
  }
  version = (unsigned long)u;
load_ok_33:
  __Block_object_dispose(&cache_79,8);
  return version;
}





uint64_t coruna_wire_export_on_err(long handle,int *flags)
{
  int err;
  
  err = *flags;
  if ((err == -0x7fffffde) || (err == 0x22 || err == -0x7fffffcc)) {
    *(uint8_t *)(*(long *)(*(long *)(handle + 0x20) + 8) + 0x18) = 1;
  }
  return 0;
}





void coruna_persistb080_via_wire_read_u32(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4)
{
  coruna_wire_read_u32(id_2,off_4);
  return;
}





uint64_t coruna_wire_read_u32(long handle,uint64_t val)
{
  uint u;
  int err;
  void *ptr;
  uint64_t size;
  
  size = 0xad001;
  if (handle != 0) {
    err = *(uint *)(handle + 0xe0) * 8;
    if (*(uint *)(handle + 0xe0) >> 0x1d == 0 && err != -8) {
      ptr = _realloc(*(void **)(handle + 0xd8),(unsigned long)(err + 8));
      if (ptr == (void *)0x0) {
        size = 0xad009;
      }
      else {
        size = 0;
        *(void **)(handle + 0xd8) = ptr;
        u = *(uint *)(handle + 0xe0);
        *(uint64_t *)((long)ptr + (unsigned long)u * 8) = val;
        *(uint *)(handle + 0xe0) = u + 1;
      }
    }
    else {
      size = 0xad01d;
    }
  }
  return size;
}





void coruna_helper_138c0_193dc(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4)
{
  coruna_wire_read_u32(id_2,off_4);
  return;
}





uint64_t coruna_persist_via_strdup(uint64_t val,char *path,uint64_t id_2,uint64_t *size_3)
{
  void *ptr;
  char *ptr;
  uint64_t u;
  
  u = 0x1200b;
  if ((path != (char *)0x0) && (size_3 != (uint64_t *)0x0)) {
    u = 0xad009;
    ptr = _calloc(1,0x58);
    if (ptr != (void *)0x0) {
      *(long *)((long)ptr + 0x50) = (long)ptr + 0x10;
      ptr = _strdup(path);
      *(char **)((long)ptr + 8) = ptr;
      if (ptr == (char *)0x0) {
        _free(ptr);
      }
      else {
        u = 0;
        *size_3 = ptr;
      }
    }
  }
  return u;
}





uint64_t coruna_persistb080_via_wire_export_free(uint64_t val,long handle)
{
  uint64_t u;
  
  if (handle != 0) {
    u = coruna_wire_export_free(handle);
    return u;
  }
  return 0x1200c;
}





uint64_t coruna_helper_5024_19484(void)
{
  return 0x910006;
}





uint64_t coruna_persistb080_residual_157(long *handle,uint size,int flags,long *addr_2)
{
  uint64_t u;
  uint64_t *ptr;
  long handle;
  
  if (size != 0 && handle == (long *)0x0 || addr_2 == (long *)0x0) {
    return 0xad001;
  }
  u = 0x910014;
  if (flags == 0) {
    return 0x910013;
  }
  if ((flags < 1) || (size < flags + 2U)) {
    if (flags != -1) {
      if (flags != -2) {
        return 0x910015;
      }
      if (size < 2) {
        return 0x910017;
      }
      handle = handle[2];
      if (handle == 0) {
        return u;
      }
      ptr = (uint64_t *)handle[3];
      if (ptr != &k_persist_rodata_word_20860) {
      return u;
      }
      *addr_2 = handle;
      return 0;
    }
    if (size < 2) {
      return 0x910017;
    }
    if (handle == (long *)0x0) {
      return u;
    }
    handle = *handle;
    if (handle == 0) {
      return u;
    }
  }
  else {
    if (handle == (long *)0x0) {
      return u;
    }
    handle = handle[(long)(flags + 1) * 2];
    if (handle == 0) {
      return u;
    }
    handle = handle + (long)(flags + 1) * 2;
  }
  ptr = (uint64_t *)handle[1];
fail:
  if (ptr != &k_persist_rodata_word_20860) {
    return u;
  }
  *addr_2 = handle;
  return 0;
}





uint64_t coruna_persistb080_via_objc_empty_vtable(long handle,uint64_t *val)
{
  int err;
  uint64_t u;
  void *ptr;
  char *ptr;
  char *buf;
  uint64_t *ptr;
  uint64_t size;
  uint64_t version;
  
  u = 0xad001;
  if (((handle != 0) && (val != (uint64_t *)0x0)) &&
     (ptr = *(uint64_t **)(handle + 0x50), ptr != (uint64_t *)0x0)) {
    buf = (char *)val[1];
    if ((buf != (char *)0x0) && (ptr = _calloc(1,0x40), ptr != (void *)0x0)) {
      u = *val;
      version = val[3];
      size = val[2];
      *(uint64_t *)((long)ptr + 0x10) = val[1];
      *(uint64_t *)((long)ptr + 8) = u;
      *(uint64_t *)((long)ptr + 0x20) = version;
      *(uint64_t *)((long)ptr + 0x18) = size;
      u = val[4];
      *(uint64_t *)((long)ptr + 0x30) = val[5];
      *(uint64_t *)((long)ptr + 0x28) = u;
      *(uint64_t *)((long)ptr + 0x38) = val[6];
      ptr = _strdup(buf);
      *(char **)((long)ptr + 0x10) = ptr;
      if (ptr != (char *)0x0) {
        err = coruna_objc_empty_vtable(buf);
        if (err != 0) {
          *(byte *)((long)ptr + 0x18) = *(byte *)((long)ptr + 0x18) | 1;
        }
        *ptr = ptr;
        *(void **)(handle + 0x50) = ptr;
        return 0;
      }
      _free(ptr);
    }
    u = 0xad009;
  }
  return u;
}





unsigned long coruna_persistb080_residual_158(long arg)

{
  uint u;
  unsigned long size;
  
  if (arg == 0) {
    size = 0xad001;
  }
  else {
    size = coruna_persistb080_via_persist_residual_47_2(arg,0,0xfffffffffffffffb);
    if (((int)size == 0) && (size = coruna_persistb080_via_persist_residual_47_2(arg,1,0xfffffffffffffffe), (int)size == 0))
    {
      u = 0;
      if (*(int *)(arg + 0xa0) != 2) {
        u = 0x1e018;
      }
      size = (unsigned long)u;
    }
  }
  return size;
}





uint64_t coruna_persistb080_via_persist_residual_47_2(long handle,int flags,uint64_t val)
{
  uint8_t *ptr;
  uint64_t u;
  
  u = 0xad001;
  if (handle != 0) {
    if (*(int *)(handle + 0xa0) == flags) {
      ptr = _calloc(1,0x58);
      if (ptr == (uint8_t *)0x0) {
        u = 0xad009;
      }
      else {
        *(uint8_t **)(ptr + 0x50) = ptr + 0x10;
        *ptr = 1;
        *(uint64_t *)(ptr + 8) = val;
        u = coruna_persist_residual_47(handle,&k_persist_rodata_word_20860,ptr);
        if ((int)u != 0) {
          coruna_wire_export_free(ptr);
        }
      }
    }
    else {
      u = 0x1e018;
    }
  }
  return u;
}





uint64_t coruna_wire_export_free(char *path)
{
  uint64_t *ptr;
  uint64_t u;
  void *ptr;
  
  if (path == (char *)0x0) {
    u = 0xad001;
  }
  else {
    if ((*path == '\0') && (*(void **)(path + 8) != (void *)0x0)) {
      _free(*(void **)(path + 8));
    }
    ptr = *(void **)(path + 0x10);
    while (ptr != (void *)0x0) {
      ptr = (void *)*ptr;
      if ((void *)ptr[2] != (void *)0x0) {
        _free((void *)ptr[2]);
      }
      _free(ptr);
      ptr = ptr;
    }
    u = 0;
  }
  return u;
}





uint coruna_parse_xnu_processors(uint8_t *buf)
{
  natural_t ln1;
  mach_port_t lm2;
  uint u;
  pid_t lp4;
  int err;
  kern_return_t lk6;
  int *err;
  uint *ptr;
  uint *buf;
  char *ptr;
  bool err;
  unsigned long size;
  unsigned long version;
  uint port;
  uint64_t scratch;
  uint64_t bootargs;
  uint32_t thread_attr;
  unsigned long host_info;
  processor_info_array_t serial_buf [64];
  long action;
  
  action = *(long *)k_persist_stack_chk_guard_slot;
  if (buf == (uint8_t *)0x0) {
    u = 0xad001;
    if (*(long *)k_persist_stack_chk_guard_slot == action) {
    return u;
    }
    ___stack_chk_fail();
  }
  bootargs = bootargs & 0xffffffff00000000;
  serial_buf[0] = (processor_info_array_t)0x0;
  host_info = host_info & 0xffffffff00000000;
  lm2 = _mach_host_self();
  u = _host_processor_info
                    (lm2,1,(natural_t *)&bootargs,serial_buf,(mach_msg_type_number_t *)&host_info)
  ;
  if (u != 0) {
    u = u | 0x80000000;
    if (*(long *)k_persist_stack_chk_guard_slot == action) {
    return u;
    }
    ___stack_chk_fail();
  }
  ln1 = (natural_t)bootargs;
  if ((natural_t)bootargs == 0) {
    port = 0;
    u = 0xad014;
  }
  else {
    u = 0;
    port = serial_buf[0][1] & 0xffffff;
  }
  _vm_deallocate(*(vm_map_t *)k_persist_mach_task_self_slot,(vm_address_t)serial_buf[0],
                 (host_info & 0xffffffff) << 2);
  if (*(long *)k_persist_stack_chk_guard_slot == action) {
  return u;
  }
  ___stack_chk_fail();
  if (port < 2) {
done:
    u = 0;
    *buf = 0;
    if (*(long *)k_persist_stack_chk_guard_slot == action) {
    return u;
    }
    ___stack_chk_fail();
  }
  if (k_persist_rodata_word_1ed00 <= *(double *)k_persist_dyldversionnumber_slot) {
    lp4 = _getpid();
    err = _csops(lp4,0,serial_buf,4);
    if (err < 0) {
      err = ___error();
      err = *err;
      ptr = (uint *)___error();
      u = -*ptr;
      if (-1 < err) {
        u = *ptr;
      }
      u = u | 0x40000000;
      if (*(long *)k_persist_stack_chk_guard_slot == action) {
      return u;
      }
      ___stack_chk_fail();
    }
    if (((uint)serial_buf[0] >> 7 & 1) != 0) goto done;
  }
  scratch = 0;
  lp4 = _getpid();
  err = _csops(lp4,10,&scratch,8);
  if (err != -1) {
    u = 0;
    *buf = 0;
    if (*(long *)k_persist_stack_chk_guard_slot == action) {
    return u;
    }
    ___stack_chk_fail();
  }
  err = ___error();
  if (*err != 0x22) {
    err = ___error();
    err = *err;
    ptr = (uint *)___error();
    u = -*ptr;
    if (-1 < err) {
      u = *ptr;
    }
    u = u | 0x40000000;
    if (*(long *)k_persist_stack_chk_guard_slot == action) {
    return u;
    }
    ___stack_chk_fail();
  }
  port = scratch;
  u = (scratch & 0xff00ff00) >> 8 | (scratch & 0xff00ff) << 8;
  version = (unsigned long)(u >> 0x10 | u << 0x10);
  ptr = _malloc(version);
  if (ptr == (uint *)0x0) {
    u = 0xad009;
    if (*(long *)k_persist_stack_chk_guard_slot == action) {
    return u;
    }
    ___stack_chk_fail();
  }
  lp4 = _getpid();
  err = _csops(lp4,10,ptr,version);
  if (err == 0) {
    u = 0xad001;
    if (port != 0) {
      port = (*ptr & 0xff00ff00) >> 8 | (*ptr & 0xff00ff) << 8;
      port = port >> 0x10 | port << 0x10;
      if (port == 0xfade0c02) {
        u = (ptr[2] & 0xff00ff00) >> 8 | (ptr[2] & 0xff00ff) << 8;
        u = u >> 0x10 | u << 0x10;
        buf = ptr;
cleanup:
        if (0x80 < u >> 10) {
          size = *(unsigned long *)(buf + 0x14) >> 0x38;
          goto check_ok;
        }
        u = 0xad008;
      }
      else if (port == 0xfade0cc0) {
        port = ptr[2];
        if (port != 0) {
          port = (port & 0xff00ff00) >> 8 | (port & 0xff00ff) << 8;
          port = port >> 0x10 | port << 0x10;
          if (port < 2) {
            port = 1;
          }
          size = (unsigned long)port;
          buf = ptr + 4;
          do {
            port = (buf[-1] & 0xff00ff00) >> 8 | (buf[-1] & 0xff00ff) << 8;
            port = port >> 0x10 | port << 0x10;
            if (port - 0x1000 < 5 || port == 0) {
              port = (*buf & 0xff00ff00) >> 8 | (*buf & 0xff00ff) << 8;
              buf = (uint *)((long)ptr + (unsigned long)(port >> 0x10 | port << 0x10));
              if (*buf != 0x20cdefa) goto skip;
              _bzero(ptr,version);
              _free(ptr);
              u = (buf[2] & 0xff00ff00) >> 8 | (buf[2] & 0xff00ff) << 8;
              u = u >> 0x10 | u << 0x10;
              goto cleanup;
            }
            buf = buf + 2;
            size = size - 1;
          } while (size != 0);
        }
        size = 0;
check_ok:
        lm2 = _mach_host_self();
        lk6 = _host_kernel_version(lm2,(char *)serial_buf);
        if (lk6 == 0) {
retry:
          ptr = _strstr((char *)serial_buf,"xnu-");
          if (ptr != (char *)0x0) {
            thread_attr = 0;
            bootargs = 0;
            err = _sscanf(ptr,"xnu-%u.%u.%u%*s");
            if (err == 3) {
              if (((uint)size >> 4 & 1) == 0) {
                err = ((size & 0x40) == 0 || (natural_t)bootargs != 0x1327) ||
                         0xdd < bootargs;
              }
              else {
                err = false;
              }
              *buf = err;
              u = 0;
              _bzero(ptr,version);
              _free(ptr);
            }
          }
        }
        else if (lk6 == 0x35) {
          host_info = k_persist_rodata_word_1ed08;
          bootargs = 0x200;
          err = _sysctl((int *)&host_info,2,serial_buf,&bootargs,(void *)0x0,0);
          if (err == 0) goto retry;
        }
        u = 0xad00b;
      }
      else {
skip:
        u = 0xad014;
      }
    }
  }
  else {
    err = ___error();
    err = *err;
    buf = (uint *)___error();
    u = -*buf;
    if (-1 < err) {
      u = *buf;
    }
    u = u | 0x40000000;
  }
next:
  _bzero(ptr,version);
  _free(ptr);
fail:
  if (*(long *)k_persist_stack_chk_guard_slot == action) {
    return u;
  }
  ___stack_chk_fail();
}





uint64_t
void coruna_vasprintf(uint64_t val,uint64_t id_2,int flags,char *path,va_list arg)
{
  int err;
  uint64_t u;
  char *scratch;
  uint64_t bootargs;
  char thread_attr;
  uint32_t scratch;
  long host_info;
  
  host_info = *(long *)k_persist_stack_chk_guard_slot;
  scratch = (char *)0x0;
  err = _vasprintf(&scratch,path,arg);
  if (err == -1 || scratch == (char *)0x0) {
    u = 0xffffffff;
  }
  else {
    if (k_persist_rodata_word_243b0 == '\0' || (k_persist_rodata_word_243b2 & 1) == 0) {
      u = 0xffffffff;
    }
    else {
      bootargs = (uint64_t)0;
      _cStack_31 = coruna_cat(0x737d,SUB81(0,7));
      err = (uint)(flags == 7) << 1;
      if (flags == 6) {
        err = 1;
      }
      (*k_persist_rodata_word_243c0)(k_persist_rodata_word_243b8,k_persist_rodata_word_243c8,err,&bootargs);
      u = 0;
    }
    _free(scratch);
  }
  if (*(long *)k_persist_stack_chk_guard_slot == host_info) {
    return u;
  }
  ___stack_chk_fail();
}





uint64_t coruna_return_zero_14200(char *path,uint64_t *val)
{
  int err;
  uint64_t u;
  void (*ptr)(void);
  
  if (path == (char *)0x0) {
    return 0;
  }
  if (val == (uint64_t *)0x0) {
    return 0;
  }
  if (k_persist_rodata_word_243b0 == '\0' || (k_persist_rodata_word_243b2 & 1) == 0) {
fail:
    u = 0;
  }
  else {
    err = _strcmp(path,"_asl_vlog");
    if (err == 0) {
      ptr = coruna_vasprintf;
    }
    else {
      err = _strcmp(path,"_asl_log");
      if (err != 0) goto fail;
      ptr = coruna_call_vasprintf;
    }
    *val = ptr;
    u = 1;
  }
  return u;
}





void coruna_call_vasprintf(void)
{
  coruna_vasprintf();
  return;
}





bool coruna_dladdr_142c0(void)
{
  char err;
  int err;
  long handle;
  long addr;
  long off;
  uint64_t scratch;
  long bootargs;
  uint64_t scratch;
  uint64_t bootargs;
  
  err = _pthread_mutex_lock((pthread_mutex_t *)&k_persist_rodata_word_243d0);
  if (err != 0) {
    return false;
  }
  err = k_persist_rodata_word_243b1;
  _pthread_mutex_unlock((pthread_mutex_t *)&k_persist_rodata_word_243d0);
  return err != '\0';
}





uint64_t coruna_identity_6080(uint64_t val)
{
  return val;
}





uint64_t coruna_persistb080_via_pacia(uint64_t val,uint64_t id_2)
{
  int err;
  uint64_t u;
  
  err = coruna_return_zero();
  if (err != 0) {
    u = coruna_pacia(val,id_2);
    return u;
  }
  return val;
}





uint64_t coruna_persistb080_via_macho_foreach_loadcmd_9(long handle)
{
  uint64_t u;
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  long serial_buf;
  
  if (handle == 0) {
    u = 0xad001;
  }
  else if ((*(ushort *)(handle + 0x1c0) & 0x18) == 0) {
    u = 0;
  }
  else {
    scratch = k_persist_nsconcretestackblock_slot;
    bootargs = k_persist_rodata_word_1ed98;
    thread_attr = coruna_macho_unwind_info_19f54;
    host_info = &k_persist_rodata_word_20878;
    serial_buf = handle;
    u = coruna_macho_foreach_loadcmd(handle,0x19,&scratch);
  }
  return u;
}





uint64_t coruna_macho_unwind_info_19f54(long handle,long addr_2)
{
  char *ptr;
  long *ptr;
  int err;
  uint64_t u;
  long handle;
  unsigned long size;
  long addr;
  char *buf;
  void *scratch;
  long bootargs;
  void *thread_attr;
  uint64_t host_info;
  
  ptr = (char *)(addr_2 + 0x48);
  buf = ptr + (unsigned long)*(uint *)(addr_2 + 0x40) * 0x50;
  do {
    if (buf <= ptr) {
      return 0;
    }
    err = _strncmp(ptr,"__eh_frame",0xb);
    if (err == 0) {
      u = coruna_vec_push_pair(*(long *)(handle + 0x20) + 0xe8,*(long *)(handle + 0x20) + 0xf0);
      if ((int)u != 0) {
        return u;
      }
      handle = *(long *)(handle + 0x20);
      if (*(long *)(handle + 0xe8) == 0) {
        return 0xad001;
      }
      size = *(unsigned long *)(ptr + 0x28);
      if (4 < size >> 0x15) {
        return 0xad014;
      }
      ptr = (long *)(*(long *)(handle + 0xe8) + (unsigned long)(*(int *)(handle + 0xf0) - 1) * 0x10);
      *ptr = *(long *)(ptr + 0x20) + *(long *)(handle + 0x18);
      *(int *)(ptr + 1) = (int)size;
      *(uint8_t *)((long)ptr + 0xc) = 0;
      handle = *(long *)(handle + 0x20);
fail:
      *(uint8_t *)(handle + 0xfd) = 1;
    }
    else {
      err = _strncmp(ptr,"__unwind_info",0xe);
      if (err == 0) {
        addr = *(long *)(handle + 0x20);
        host_info = 0;
        scratch = (void *)0x0;
        handle = *(long *)(ptr + 0x20) + *(long *)(addr + 0x18);
        u = coruna_return_zero_15dbc(handle,coruna_reallocf,&scratch);
        if ((int)u != 0) {
          return u;
        }
        thread_attr = scratch;
        bootargs = addr;
        u = coruna_return_zero_15dbc(handle,coruna_bzero_3,&bootargs);
        _free(scratch);
        if ((int)u != 0) {
          return u;
        }
        handle = *(long *)(handle + 0x20);
        if (*(int *)(handle + 0xf0) != 0) goto fail;
      }
    }
    ptr = ptr + 0x50;
  } while( true );
}





uint64_t coruna_vec_push_pair(uint64_t *val,uint *size)
{
  uint64_t *ptr;
  uint u;
  void *ptr;
  uint64_t size;
  
  size = 0xad001;
  if ((size != (uint *)0x0) && (val != (uint64_t *)0x0)) {
    u = *size;
    ptr = _realloc((void *)*val,(unsigned long)(u + 1) << 4);
    if (ptr == (void *)0x0) {
      size = 0xad009;
    }
    else {
      size = 0;
      ptr = (uint64_t *)((long)ptr + (unsigned long)*size * 0x10);
      *ptr = 0;
      ptr[1] = 0;
      *val = ptr;
      *size = u + 1;
    }
  }
  return size;
}
unsigned long coruna_strnlen(long *arg)

{
  int *fde;
  long *entry_12;
  uint size;
  uint version;
  uint type_id;
  int count;
  uint tag;
  uint64_t kind;
  uint8_t type_id_8;
  uint type_id_14;
  uint type_id_13;
  long serial_10;
  unsigned long type_id_9;
  size_t ls13;
  byte *entry_13;
  byte *entry_14;
  void *entry_15;
  void *entry_16;
  int ret;
  long serial_11;
  long *entry_17;
  unsigned long type_id_16;
  uint64_t *entry;
  long serial_12;
  long serial_13;
  unsigned long type_id_17;
  long serial_14;
  byte *entry_18;
  uint *entry_9;
  unsigned long type_id_18;
  unsigned long type_id_19;
  long serial_15;
  byte *entry_19;
  byte *entry_20;
  char *entry_9;
  long *entry_21;
  int *idx;
  uint64_t cache_33;
  uint64_t cache_34;
  uint64_t cache_35;
  uint64_t sa_saved;
  uint64_t cache_36;
  long path_buf;
  uint64_t tmp_buf;
  char *cache_100;
  uint64_t cache_37;
  uint64_t cache_38;
  unsigned long json_buf [2];
  uint64_t cache_39;
  uint64_t *cache;
  uint64_t cache_102;
  long cache_89;
  uint32_t cache_104;
  uint cache_91;
  uint cache_105;
  uint64_t host_info[2];
  
  if (arg == (long *)0x0) {
    type_id_9 = 0xad001;
  }
  else if (*(char *)((long)arg + 0xfd) == '\0') {
    type_id_9 = 0;
  }
  else {
    serial_10 = *arg;
    if ((*(int *)(serial_10 + 0x118) != 1) ||
       (type_id_9 = coruna_macho_data_seg(serial_10,*(uint64_t *)(serial_10 + 0x110),serial_10 + 0x120),
       (int)type_id_9 == 0)) {
      serial_10 = k_persist_rodata_word_1edb0;
      serial_11 = arg[0x1d];
      type_id_9 = 0xad00f;
      if ((serial_11 != 0) && ((int)arg[0x1e] != 0)) {
        type_id_9 = 0;
        type_id_19 = 0;
        do {
          type_id_14 = 0xad00f;
          if ((serial_11 != 0) && (serial_13 = *(long *)(serial_11 + type_id_9 * 0x10), serial_13 != 0)) {
            type_id = *(uint *)(serial_11 + type_id_9 * 0x10 + 8);
            if (type_id == 0) {
              type_id_14 = 0xad00f;
            }
            else {
              type_id_17 = 0;
              do {
                while( true ) {
                  fde = (int *)(serial_13 + type_id_17);
                  count = *fde;
                  if (fde[1] != 0) break;
                  type_id_14 = (int)type_id_17 + count + 4;
                  type_id_17 = (unsigned long)type_id_14;
                  if (type_id <= type_id_14) goto load_ok_34;
                }
                cache_89 = 0;
                cache_39 = 0;
                json_buf[1] = 0;
                cache_102 = 0;
                cache = (uint64_t *)0x0;
                cache_37 = 0;
                json_buf[0] = 0;
                cache_38 = 0;
                cache_36 = 0;
                sa_saved = 0;
                path_buf = 0;
                cache_33 = 0;
                cache_35 = 0;
                cache_34 = 0;
                type_id_14 = 0xad001;
                break;
                type_id_13 = *fde + 4;
                cache_104 = 0;
                cache_91 = 8;
                idx = (int *)((long)(fde + 1) - (unsigned long)(uint)fde[1]);
                if (idx[1] != 0) {
load_ok_36:
                  type_id_14 = 0xad014;
                  break;
                }
                tmp_buf = (unsigned long)coruna_u64_pack14((*(byte *)(idx + 2)), (*idx + 4));
                if ((*(byte *)(idx + 2) | 2) != 3) {
load_ok_37:
                  type_id_14 = 0xad008;
                  break;
                }
                cache_100 = (char *)((long)idx + 9);
                ls13 = _strnlen(cache_100,5);
                type_id_14 = 0xad014;
                break;
                cache_105 = (int)ls13 + 10;
                host_info[0] = 0;
                if ((idx == (int *)0x0) || ((uint)tmp_buf <= cache_105)) {
load_ok_35:
                  type_id_14 = 0xad001;
                  break;
                }
                type_id_14 = coruna_read_uleb128(&cache_37,host_info,idx,&cache_105);
                if ((type_id_14 != 0) ||
                   (type_id_14 = coruna_sign_extend_uleb(&cache_38,idx,&cache_105,tmp_buf & 0xffffffff),
                   break;
                if (tmp_buf == '\x03') {
                  host_info[0] = 0;
                  type_id_14 = 0xad001;
                  break;
                  type_id_14 = coruna_read_uleb128(json_buf,host_info,idx,&cache_105);
                  break;
                }
                else {
                  type_id_14 = 0xad014;
                  break;
                  json_buf[0] = (unsigned long)*(byte *)((long)idx + (unsigned long)cache_105);
                  cache_105 = cache_105 + 1;
                }
                entry_9 = cache_100;
                if (*cache_100 == 'z') {
                  host_info[0] = 0;
                  type_id_14 = 0xad001;
                  break;
                  type_id_14 = coruna_read_uleb128(json_buf + 1,host_info,idx,&cache_105);
                  break;
                  entry_9 = entry_9 + 1;
                }
                cache_39 = -1;
                cache_102 = coruna_cat(cache_102,0xffff);
                while( true ) {
                  kind = cache_102;
                  if (*entry_9 == 0) break;
                  type_id_14 = 0xad008;
                  switch((int)*entry_9) {
                  case 0x4c:
                    cache_102 = coruna_u64_pack71((cache_102), (*(uint8_t *))((long)idx + (unsigned long)cache_105));
                    type_id_14 = 0;
                    cache_105 = cache_105 + 1;
                    break;
                  default:
                    break;
                  case 0x50:
                    cache_39 = *(char *)((long)idx + (unsigned long)cache_105);
                    cache_105 = cache_105 + 1;
                    type_id_14 = coruna_persistb080_via_sign_extend_uleb(&cache,(char)cache_39,idx,&cache_105,
                                         tmp_buf & 0xffffffff,0);
                    break;
                  case 0x52:
                    cache_102 =
                         coruna_cat(*(uint8_t *)((long)idx + (unsigned long)cache_105),
                                  (uint8_t)cache_102);
load_ok_38:
                    type_id_14 = 0;
                    cache_105 = cache_105 + 1;
                    break;
                  case 0x53:
                    type_id_14 = 0;
                    cache_102 = coruna_cat(1,(uint16_t)cache_102);
                  }
                  entry_9 = entry_9 + 1;
                  break;
                }
                cache_102 = coruna_u64_pack(((uint)tmp_buf - cache_105), ((uint32_t))cache_102);
                type_id_16 = cache_102;
                cache_89 = (long)idx + (unsigned long)cache_105;
                cache_102 = SUB81(kind,1);
                type_id_8 = cache_102;
                cache_102 = type_id_16;
                type_id_14 = coruna_persistb080_via_sign_extend_uleb(&cache_33,type_id_8,fde,&cache_91,type_id_13,0);
                break;
                type_id_14 = coruna_persistb080_via_sign_extend_uleb(&cache_34,cache_102,fde,&cache_91,type_id_13,1);
                break;
                if (*cache_100 == 'z') {
                  host_info[0] = 0;
                  type_id_14 = 0xad001;
                  break;
                  type_id_14 = coruna_read_uleb128(&cache_35,host_info,fde,&cache_91);
                  break;
                }
                type_id_14 = coruna_persistb080_via_sign_extend_uleb(&sa_saved,cache_102 & 0xff,fde,&cache_91,type_id_13,0);
                break;
                cache_36 = coruna_u64_pack((cache_36), (type_id_13 - cache_91));
                path_buf = (long)fde + (unsigned long)cache_91;
                if (cache != (uint64_t *)0x0) {
                  type_id_14 = 0xad008;
                  break;
                  type_id_13 = _pthread_mutex_lock((pthread_mutex_t *)&k_persist_rodata_word_24410);
                  if (type_id_13 == 0) {
                    if (k_persist_rodata_word_24920 != (byte *)0x0) {
                      ret = (uint)sa_saved * 0x1000000 + -0x61c88647 +
                               (uint)sa_saved * 0x10000 + (uint)sa_saved * 0x100 +
                               (uint)sa_saved;
                      type_id_14 = (((uint)sa_saved * 0x1000000 + -0x60b6453e) - ret) +
                              (uint)sa_saved * 0x10000 + (uint)sa_saved * 0x100 +
                              (uint)(byte)sa_saved ^ 0x7f76d;
                      type_id_13 = (ret + 0x1124109) - type_id_14 ^ type_id_14 << 8;
                      version = 0xfeedbef7 - (type_id_14 + type_id_13) ^ type_id_13 >> 0xd;
                      type_id_14 = type_id_14 - (type_id_13 + version) ^ version >> 0xc;
                      type_id_13 = type_id_13 - (version + type_id_14) ^ type_id_14 << 0x10;
                      version = version - (type_id_14 + type_id_13) ^ type_id_13 >> 5;
                      type_id_14 = type_id_14 - (type_id_13 + version) ^ version >> 3;
                      type_id_13 = type_id_13 - (version + type_id_14) ^ type_id_14 << 10;
                      type_id_14 = version - (type_id_14 + type_id_13) ^ type_id_13 >> 0xf;
                      entry_17 = *(long **)(k_persist_rodata_word_24920 + 0x18);
                      serial_11 = *(long *)(*entry_17 + (unsigned long)((int)entry_17[1] - 1U & type_id_14) * 0x10);
                      if (serial_11 != 0) {
                        do {
                          serial_11 = serial_11 - entry_17[4];
                          if (((*(uint *)(serial_11 + 0x4c) == type_id_14) && (*(int *)(serial_11 + 0x48) == 8)
                              ) && (**(long **)(serial_11 + 0x40) == sa_saved)) {
                            if (cache == *(uint64_t **)(serial_11 + 0x10)) goto load_ok_39;
                            type_id_14 = 0xad008;
                            goto load_ok_40;
                          }
                          serial_11 = *(long *)(serial_11 + 0x38);
                        } while (serial_11 != 0);
                      }
                    }
                    if ((char)cache_39 < '\0') {
                      entry_13 = _calloc(1,0x50);
                      entry = cache;
                      if (entry_13 == (byte *)0x0) {
                        type_id_14 = 0xad009;
                      }
                      else {
                        serial_11 = arg[0x20];
                        *(long *)entry_13 = sa_saved;
                        *(long *)(entry_13 + 8) = serial_11;
                        *(uint64_t **)(entry_13 + 0x10) = cache;
                        if (k_persist_rodata_word_24928 != (byte *)0x0) {
                          type_id_14 = (uint)((unsigned long)cache >> 0x20);
                          ret = (type_id_14 & 0xff000000) + 0x9e3779b9 + (type_id_14 & 0xff0000) +
                                   (type_id_14 & 0xff00) + (type_id_14 & 0xff);
                          type_id_14 = (uint)cache;
                          type_id_14 = ((type_id_14 & 0xff000000) + 0x9f49bac2 + (type_id_14 & 0xff0000) +
                                   (type_id_14 & 0xff00) + (type_id_14 & 0xff)) - ret ^ 0x7f76d;
                          type_id_13 = (ret + 0x1124109) - type_id_14 ^ type_id_14 << 8;
                          version = 0xfeedbef7 - (type_id_14 + type_id_13) ^ type_id_13 >> 0xd;
                          type_id_14 = type_id_14 - (type_id_13 + version) ^ version >> 0xc;
                          type_id_13 = type_id_13 - (version + type_id_14) ^ type_id_14 << 0x10;
                          version = version - (type_id_14 + type_id_13) ^ type_id_13 >> 5;
                          type_id_14 = type_id_14 - (type_id_13 + version) ^ version >> 3;
                          type_id_13 = type_id_13 - (version + type_id_14) ^ type_id_14 << 10;
                          type_id_14 = version - (type_id_14 + type_id_13) ^ type_id_13 >> 0xf;
                          entry_17 = *(long **)(k_persist_rodata_word_24928 + 0x10);
                          serial_11 = *(long *)(*entry_17 + (unsigned long)((int)entry_17[1] - 1U & type_id_14) * 0x10
                                            );
                          if (serial_11 != 0) {
                            do {
                              serial_11 = serial_11 - entry_17[4];
                              if (((*(uint *)(serial_11 + 0x44) == type_id_14) &&
                                  (*(int *)(serial_11 + 0x40) == 8)) &&
                                 (**(long **)(serial_11 + 0x38) == *(long *)(entry_13 + 0x10)))
                              goto load_ok_41;
                              serial_11 = *(long *)(serial_11 + 0x30);
                            } while (serial_11 != 0);
                          }
                        }
                        entry_14 = _calloc(1,0x48);
                        if (entry_14 != (byte *)0x0) {
                          *(uint64_t **)entry_14 = entry;
                          *(uint64_t *)(entry_14 + 8) = *entry;
                          *entry = coruna_unw_get_proc_info;
                          ret = (uint)entry_14[7] * 0x1000000 + -0x61c88647 +
                                   (uint)entry_14[6] * 0x10000 + (uint)entry_14[5] * 0x100 +
                                   (uint)entry_14[4];
                          type_id_14 = (((uint)entry_14[3] * 0x1000000 + -0x60b6453e) - ret) +
                                  (uint)entry_14[2] * 0x10000 + (uint)entry_14[1] * 0x100 +
                                  (uint)*entry_14 ^ 0x7f76d;
                          type_id_13 = (ret + 0x1124109) - type_id_14 ^ type_id_14 << 8;
                          version = 0xfeedbef7 - (type_id_14 + type_id_13) ^ type_id_13 >> 0xd;
                          type_id_14 = type_id_14 - (type_id_13 + version) ^ version >> 0xc;
                          type_id_13 = type_id_13 - (version + type_id_14) ^ type_id_14 << 0x10;
                          version = version - (type_id_14 + type_id_13) ^ type_id_13 >> 5;
                          type_id_14 = type_id_14 - (type_id_13 + version) ^ version >> 3;
                          type_id_13 = type_id_13 - (version + type_id_14) ^ type_id_14 << 10;
                          type_id_14 = version - (type_id_14 + type_id_13) ^ type_id_13 >> 0xf;
                          entry_18 = entry_14 + 0x10;
                          *(byte **)(entry_14 + 0x38) = entry_14;
                          entry_14[0x40] = 8;
                          entry_14[0x41] = 0;
                          entry_14[0x42] = 0;
                          entry_14[0x43] = 0;
                          *(uint *)(entry_14 + 0x44) = type_id_14;
                          entry_20 = k_persist_rodata_word_24928;
                          if (k_persist_rodata_word_24928 == (byte *)0x0) {
                            entry_17 = _calloc(1,0x40);
                            entry_14[0x18] = 0;
                            entry_14[0x19] = 0;
                            entry_14[0x1a] = 0;
                            entry_14[0x1b] = 0;
                            entry_14[0x1c] = 0;
                            entry_14[0x1d] = 0;
                            entry_14[0x1e] = 0;
                            entry_14[0x1f] = 0;
                            entry_14[0x20] = 0;
                            entry_14[0x21] = 0;
                            entry_14[0x22] = 0;
                            entry_14[0x23] = 0;
                            entry_14[0x24] = 0;
                            entry_14[0x25] = 0;
                            entry_14[0x26] = 0;
                            entry_14[0x27] = 0;
                            *(long **)(entry_14 + 0x10) = entry_17;
                            if (entry_17 != (long *)0x0) {
                              entry_17[1] = serial_10;
                              entry_17[3] = (long)entry_18;
                              entry_17[4] = 0x10;
                              entry_15 = _calloc(1,0x200);
                              *entry_17 = (long)entry_15;
                              *(uint32_t *)(entry_17 + 7) = 0xa0111fe1;
                              if (entry_15 != (void *)0x0) {
                                serial_14 = 0;
                                ret = 0x20;
                                serial_11 = 0x10;
                                entry_20 = entry_14;
                                entry_21 = entry_17;
                                k_persist_rodata_word_24928 = entry_14;
                                goto load_ok_42;
                              }
                              _free(entry_17);
                            }
                            entry_18[0] = 0;
                            entry_18[1] = 0;
                            entry_18[2] = 0;
                            entry_18[3] = 0;
                            entry_18[4] = 0;
                            entry_18[5] = 0;
                            entry_18[6] = 0;
                            entry_18[7] = 0;
                          }
                          else {
                            entry_21 = *(long **)(k_persist_rodata_word_24928 + 0x10);
                            *(long **)(entry_14 + 0x10) = entry_21;
                            entry_14[0x20] = 0;
                            entry_14[0x21] = 0;
                            entry_14[0x22] = 0;
                            entry_14[0x23] = 0;
                            entry_14[0x24] = 0;
                            entry_14[0x25] = 0;
                            entry_14[0x26] = 0;
                            entry_14[0x27] = 0;
                            entry_17 = *(long **)(entry_20 + 0x10);
                            serial_12 = entry_17[3];
                            serial_11 = entry_17[4];
                            serial_14 = serial_12 - serial_11;
                            *(long *)(entry_14 + 0x18) = serial_14;
                            *(byte **)(serial_12 + 0x10) = entry_14;
                            entry_17[3] = (long)entry_18;
                            ret = (int)entry_17[1];
load_ok_42:
                            *(int *)(entry_17 + 2) = (int)entry_17[2] + 1;
                            type_id_16 = (unsigned long)(ret - 1U & type_id_14);
                            serial_12 = *entry_17;
                            entry_12 = (long *)(serial_12 + type_id_16 * 0x10);
                            entry_9 = (uint *)(entry_12 + 1);
                            type_id_13 = *entry_9 + 1;
                            *entry_9 = type_id_13;
                            serial_15 = *entry_12;
                            entry_19 = entry_14 + 0x28;
                            entry_19[0] = 0;
                            entry_19[1] = 0;
                            entry_19[2] = 0;
                            entry_19[3] = 0;
                            entry_19[4] = 0;
                            entry_19[5] = 0;
                            entry_19[6] = 0;
                            entry_19[7] = 0;
                            *(long *)(entry_14 + 0x30) = serial_15;
                            if (serial_15 != 0) {
                              *(byte **)(serial_15 + 0x18) = entry_18;
                            }
                            *entry_12 = (long)entry_18;
                            if ((*(int *)(serial_12 + type_id_16 * 0x10 + 0xc) * 10 + 10U <= type_id_13) &&
                               (*(int *)((long)entry_21 + 0x34) == 0)) {
                              version = *(uint *)(entry_21 + 1);
                              entry_15 = _malloc((unsigned long)version << 5);
                              if (entry_15 == (void *)0x0) {
                                *entry_12 = serial_15;
                                serial_12 = *(long *)entry_19;
                                if (serial_12 != 0) {
                                  *(long *)(serial_12 + 0x20) = serial_15;
                                  serial_15 = *(long *)(entry_14 + 0x30);
                                }
                                if (serial_15 != 0) {
                                  *(long *)(serial_15 + 0x18) = serial_12;
                                }
                                *entry_9 = type_id_13;
                                entry_19[0] = 0;
                                entry_19[1] = 0;
                                entry_19[2] = 0;
                                entry_19[3] = 0;
                                entry_19[4] = 0;
                                entry_19[5] = 0;
                                entry_19[6] = 0;
                                entry_19[7] = 0;
                                entry_14[0x30] = 0;
                                entry_14[0x31] = 0;
                                entry_14[0x32] = 0;
                                entry_14[0x33] = 0;
                                entry_14[0x34] = 0;
                                entry_14[0x35] = 0;
                                entry_14[0x36] = 0;
                                entry_14[0x37] = 0;
                                if (serial_14 == 0) {
                                  entry_14 = *(byte **)(entry_14 + 0x20);
                                  if (entry_14 != (byte *)0x0) {
                                    entry_17[3] = serial_11;
                                    entry_17 = *(long **)(entry_14 + 0x10);
                                    k_persist_rodata_word_24928 = entry_14;
                                    goto load_ok_43;
                                  }
                                  _free((void *)**(uint64_t **)(entry_20 + 0x10));
                                  _free(*(void **)(entry_20 + 0x10));
                                  k_persist_rodata_word_24928 = (byte *)0x0;
                                }
                                else {
                                  entry_17[3] = serial_14 + serial_11;
                                  *(uint64_t *)(serial_14 + serial_11 + 0x10) =
                                       *(uint64_t *)(entry_14 + 0x20);
                                  entry_14 = *(byte **)(entry_14 + 0x20);
                                  entry_17 = *(long **)(entry_20 + 0x10);
                                  if (entry_14 != (byte *)0x0) {
load_ok_43:
                                    *(long *)(entry_14 + entry_17[4] + 8) = serial_14;
                                  }
                                  entry = (uint64_t *)
                                            (*entry_17 + (unsigned long)((int)entry_17[1] - 1U & type_id_14) * 0x10
                                            );
                                  *(int *)(entry + 1) = *(int *)(entry + 1) + -1;
                                  if ((byte *)*entry == entry_18) {
                                    *entry = 0;
                                  }
                                  *(int *)(entry_17 + 2) = (int)entry_17[2] + -1;
                                }
                                entry_18[0] = 0;
                                entry_18[1] = 0;
                                entry_18[2] = 0;
                                entry_18[3] = 0;
                                entry_18[4] = 0;
                                entry_18[5] = 0;
                                entry_18[6] = 0;
                                entry_18[7] = 0;
                              }
                              else {
                                _bzero(entry_15,(unsigned long)version << 5);
                                entry_17 = *(long **)entry_18;
                                type_id_13 = *(uint *)(entry_17 + 1);
                                type_id_14 = *(uint *)(entry_17 + 2) >>
                                        (unsigned long)(*(int *)((long)entry_17 + 0xc) + 1U & 0x1f);
                                version = type_id_13 * 2 - 1;
                                if ((version & *(uint *)(entry_17 + 2)) != 0) {
                                  type_id_14 = type_id_14 + 1;
                                }
                                *(uint *)(entry_17 + 5) = type_id_14;
                                *(uint32_t *)((long)entry_17 + 0x2c) = 0;
                                if (type_id_13 == 0) {
                                  entry_16 = (void *)*entry_17;
                                }
                                else {
                                  ret = 0;
                                  type_id_16 = 0;
                                  entry_16 = (void *)*entry_17;
                                  do {
                                    serial_11 = *(long *)((long)entry_16 + type_id_16 * 0x10);
                                    while (serial_11 != 0) {
                                      serial_14 = *(long *)(serial_11 + 0x20);
                                      type_id_18 = (unsigned long)(*(uint *)(serial_11 + 0x34) & version);
                                      size = *(int *)((long)entry_15 + type_id_18 * 0x10 + 8) + 1;
                                      *(uint *)((long)entry_15 + type_id_18 * 0x10 + 8) = size;
                                      if (type_id_14 < size) {
                                        ret = ret + 1;
                                        *(int *)((long)entry_17 + 0x2c) = ret;
                                        tag = 0;
                                        if (type_id_14 != 0) {
                                          tag = size / type_id_14;
                                        }
                                        *(uint *)((long)entry_15 + type_id_18 * 0x10 + 0xc) = tag;
                                      }
                                      *(uint64_t *)(serial_11 + 0x18) = 0;
                                      entry_21 = (long *)((long)entry_15 + type_id_18 * 0x10);
                                      serial_12 = *entry_21;
                                      *(long *)(serial_11 + 0x20) = serial_12;
                                      if (serial_12 != 0) {
                                        *(long *)(serial_12 + 0x18) = serial_11;
                                      }
                                      *entry_21 = serial_11;
                                      serial_11 = serial_14;
                                    }
                                    type_id_16 = type_id_16 + 1;
                                  } while (type_id_16 != type_id_13);
                                }
                                _free(entry_16);
                                entry = *(uint64_t **)entry_18;
                                *(int *)(entry + 1) = *(int *)(entry + 1) << 1;
                                *(int *)((long)entry + 0xc) = *(int *)((long)entry + 0xc) + 1;
                                *entry = entry_15;
                                if (*(uint *)(entry + 2) >> 1 < *(uint *)((long)entry + 0x2c)) {
                                  ret = *(int *)(entry + 6);
                                  *(uint *)(entry + 6) = ret + 1U;
                                  if (1 < ret + 1U) {
                                    *(uint32_t *)((long)entry + 0x34) = 1;
                                  }
                                }
                                else {
                                  *(uint32_t *)(entry + 6) = 0;
                                }
                              }
                            }
                          }
load_ok_41:
                          ret = (uint)entry_13[7] * 0x1000000 + -0x61c88647 +
                                   (uint)entry_13[6] * 0x10000 + (uint)entry_13[5] * 0x100 +
                                   (uint)entry_13[4];
                          type_id_14 = (((uint)entry_13[3] * 0x1000000 + -0x60b6453e) - ret) +
                                  (uint)entry_13[2] * 0x10000 + (uint)entry_13[1] * 0x100 +
                                  (uint)*entry_13 ^ 0x7f76d;
                          type_id_13 = (ret + 0x1124109) - type_id_14 ^ type_id_14 << 8;
                          version = 0xfeedbef7 - (type_id_14 + type_id_13) ^ type_id_13 >> 0xd;
                          type_id_14 = type_id_14 - (type_id_13 + version) ^ version >> 0xc;
                          type_id_13 = type_id_13 - (version + type_id_14) ^ type_id_14 << 0x10;
                          version = version - (type_id_14 + type_id_13) ^ type_id_13 >> 5;
                          type_id_14 = type_id_14 - (type_id_13 + version) ^ version >> 3;
                          type_id_13 = type_id_13 - (version + type_id_14) ^ type_id_14 << 10;
                          type_id_14 = version - (type_id_14 + type_id_13) ^ type_id_13 >> 0xf;
                          entry_14 = entry_13 + 0x18;
                          *(byte **)(entry_13 + 0x40) = entry_13;
                          entry_13[0x48] = 8;
                          entry_13[0x49] = 0;
                          entry_13[0x4a] = 0;
                          entry_13[0x4b] = 0;
                          *(uint *)(entry_13 + 0x4c) = type_id_14;
                          entry_18 = k_persist_rodata_word_24920;
                          if (k_persist_rodata_word_24920 == (byte *)0x0) {
                            entry_17 = _calloc(1,0x40);
                            entry_13[0x20] = 0;
                            entry_13[0x21] = 0;
                            entry_13[0x22] = 0;
                            entry_13[0x23] = 0;
                            entry_13[0x24] = 0;
                            entry_13[0x25] = 0;
                            entry_13[0x26] = 0;
                            entry_13[0x27] = 0;
                            entry_13[0x28] = 0;
                            entry_13[0x29] = 0;
                            entry_13[0x2a] = 0;
                            entry_13[0x2b] = 0;
                            entry_13[0x2c] = 0;
                            entry_13[0x2d] = 0;
                            entry_13[0x2e] = 0;
                            entry_13[0x2f] = 0;
                            *(long **)(entry_13 + 0x18) = entry_17;
                            if (entry_17 != (long *)0x0) {
                              entry_17[1] = serial_10;
                              entry_17[3] = (long)entry_14;
                              entry_17[4] = 0x18;
                              entry_15 = _calloc(1,0x200);
                              *entry_17 = (long)entry_15;
                              *(uint32_t *)(entry_17 + 7) = 0xa0111fe1;
                              if (entry_15 != (void *)0x0) {
                                serial_14 = 0;
                                ret = 0x20;
                                serial_11 = 0x18;
                                entry_18 = entry_13;
                                entry_21 = entry_17;
                                k_persist_rodata_word_24920 = entry_13;
                                goto load_ok_44;
                              }
                              _free(entry_17);
                            }
                            entry_14[0] = 0;
                            entry_14[1] = 0;
                            entry_14[2] = 0;
                            entry_14[3] = 0;
                            entry_14[4] = 0;
                            entry_14[5] = 0;
                            entry_14[6] = 0;
                            entry_14[7] = 0;
                          }
                          else {
                            entry_21 = *(long **)(k_persist_rodata_word_24920 + 0x18);
                            *(long **)(entry_13 + 0x18) = entry_21;
                            entry_13[0x28] = 0;
                            entry_13[0x29] = 0;
                            entry_13[0x2a] = 0;
                            entry_13[0x2b] = 0;
                            entry_13[0x2c] = 0;
                            entry_13[0x2d] = 0;
                            entry_13[0x2e] = 0;
                            entry_13[0x2f] = 0;
                            entry_17 = *(long **)(entry_18 + 0x18);
                            serial_12 = entry_17[3];
                            serial_11 = entry_17[4];
                            serial_14 = serial_12 - serial_11;
                            *(long *)(entry_13 + 0x20) = serial_14;
                            *(byte **)(serial_12 + 0x10) = entry_13;
                            entry_17[3] = (long)entry_14;
                            ret = (int)entry_17[1];
load_ok_44:
                            *(int *)(entry_17 + 2) = (int)entry_17[2] + 1;
                            type_id_16 = (unsigned long)(ret - 1U & type_id_14);
                            serial_12 = *entry_17;
                            entry_12 = (long *)(serial_12 + type_id_16 * 0x10);
                            entry_9 = (uint *)(entry_12 + 1);
                            type_id_13 = *entry_9 + 1;
                            *entry_9 = type_id_13;
                            serial_15 = *entry_12;
                            entry_20 = entry_13 + 0x30;
                            entry_20[0] = 0;
                            entry_20[1] = 0;
                            entry_20[2] = 0;
                            entry_20[3] = 0;
                            entry_20[4] = 0;
                            entry_20[5] = 0;
                            entry_20[6] = 0;
                            entry_20[7] = 0;
                            *(long *)(entry_13 + 0x38) = serial_15;
                            if (serial_15 != 0) {
                              *(byte **)(serial_15 + 0x18) = entry_14;
                            }
                            *entry_12 = (long)entry_14;
                            if ((*(int *)(serial_12 + type_id_16 * 0x10 + 0xc) * 10 + 10U <= type_id_13) &&
                               (*(int *)((long)entry_21 + 0x34) == 0)) {
                              version = *(uint *)(entry_21 + 1);
                              entry_15 = _malloc((unsigned long)version << 5);
                              if (entry_15 == (void *)0x0) {
                                *entry_12 = serial_15;
                                serial_12 = *(long *)entry_20;
                                if (serial_12 != 0) {
                                  *(long *)(serial_12 + 0x20) = serial_15;
                                  serial_15 = *(long *)(entry_13 + 0x38);
                                }
                                if (serial_15 != 0) {
                                  *(long *)(serial_15 + 0x18) = serial_12;
                                }
                                *entry_9 = type_id_13;
                                entry_20[0] = 0;
                                entry_20[1] = 0;
                                entry_20[2] = 0;
                                entry_20[3] = 0;
                                entry_20[4] = 0;
                                entry_20[5] = 0;
                                entry_20[6] = 0;
                                entry_20[7] = 0;
                                entry_13[0x38] = 0;
                                entry_13[0x39] = 0;
                                entry_13[0x3a] = 0;
                                entry_13[0x3b] = 0;
                                entry_13[0x3c] = 0;
                                entry_13[0x3d] = 0;
                                entry_13[0x3e] = 0;
                                entry_13[0x3f] = 0;
                                if (serial_14 == 0) {
                                  entry_13 = *(byte **)(entry_13 + 0x28);
                                  if (entry_13 != (byte *)0x0) {
                                    entry_17[3] = serial_11;
                                    entry_17 = *(long **)(entry_13 + 0x18);
                                    k_persist_rodata_word_24920 = entry_13;
                                    goto load_ok_45;
                                  }
                                  _free((void *)**(uint64_t **)(entry_18 + 0x18));
                                  _free(*(void **)(entry_18 + 0x18));
                                  k_persist_rodata_word_24920 = (byte *)0x0;
                                }
                                else {
                                  entry_17[3] = serial_14 + serial_11;
                                  *(uint64_t *)(serial_14 + serial_11 + 0x10) =
                                       *(uint64_t *)(entry_13 + 0x28);
                                  entry_13 = *(byte **)(entry_13 + 0x28);
                                  entry_17 = *(long **)(entry_18 + 0x18);
                                  if (entry_13 != (byte *)0x0) {
load_ok_45:
                                    *(long *)(entry_13 + entry_17[4] + 8) = serial_14;
                                  }
                                  entry = (uint64_t *)
                                            (*entry_17 + (unsigned long)((int)entry_17[1] - 1U & type_id_14) * 0x10
                                            );
                                  *(int *)(entry + 1) = *(int *)(entry + 1) + -1;
                                  if ((byte *)*entry == entry_14) {
                                    *entry = 0;
                                  }
                                  *(int *)(entry_17 + 2) = (int)entry_17[2] + -1;
                                }
                                entry_14[0] = 0;
                                entry_14[1] = 0;
                                entry_14[2] = 0;
                                entry_14[3] = 0;
                                entry_14[4] = 0;
                                entry_14[5] = 0;
                                entry_14[6] = 0;
                                entry_14[7] = 0;
                              }
                              else {
                                _bzero(entry_15,(unsigned long)version << 5);
                                entry_17 = *(long **)entry_14;
                                type_id_13 = *(uint *)(entry_17 + 1);
                                type_id_14 = *(uint *)(entry_17 + 2) >>
                                        (unsigned long)(*(int *)((long)entry_17 + 0xc) + 1U & 0x1f);
                                version = type_id_13 * 2 - 1;
                                if ((version & *(uint *)(entry_17 + 2)) != 0) {
                                  type_id_14 = type_id_14 + 1;
                                }
                                *(uint *)(entry_17 + 5) = type_id_14;
                                *(uint32_t *)((long)entry_17 + 0x2c) = 0;
                                if (type_id_13 == 0) {
                                  entry_16 = (void *)*entry_17;
                                }
                                else {
                                  ret = 0;
                                  type_id_16 = 0;
                                  entry_16 = (void *)*entry_17;
                                  do {
                                    serial_11 = *(long *)((long)entry_16 + type_id_16 * 0x10);
                                    while (serial_11 != 0) {
                                      serial_14 = *(long *)(serial_11 + 0x20);
                                      type_id_18 = (unsigned long)(*(uint *)(serial_11 + 0x34) & version);
                                      size = *(int *)((long)entry_15 + type_id_18 * 0x10 + 8) + 1;
                                      *(uint *)((long)entry_15 + type_id_18 * 0x10 + 8) = size;
                                      if (type_id_14 < size) {
                                        ret = ret + 1;
                                        *(int *)((long)entry_17 + 0x2c) = ret;
                                        tag = 0;
                                        if (type_id_14 != 0) {
                                          tag = size / type_id_14;
                                        }
                                        *(uint *)((long)entry_15 + type_id_18 * 0x10 + 0xc) = tag;
                                      }
                                      *(uint64_t *)(serial_11 + 0x18) = 0;
                                      entry_21 = (long *)((long)entry_15 + type_id_18 * 0x10);
                                      serial_12 = *entry_21;
                                      *(long *)(serial_11 + 0x20) = serial_12;
                                      if (serial_12 != 0) {
                                        *(long *)(serial_12 + 0x18) = serial_11;
                                      }
                                      *entry_21 = serial_11;
                                      serial_11 = serial_14;
                                    }
                                    type_id_16 = type_id_16 + 1;
                                  } while (type_id_16 != type_id_13);
                                }
                                _free(entry_16);
                                entry = *(uint64_t **)entry_14;
                                *(int *)(entry + 1) = *(int *)(entry + 1) << 1;
                                *(int *)((long)entry + 0xc) = *(int *)((long)entry + 0xc) + 1;
                                *entry = entry_15;
                                if (*(uint *)(entry + 2) >> 1 < *(uint *)((long)entry + 0x2c)) {
                                  ret = *(int *)(entry + 6);
                                  *(uint *)(entry + 6) = ret + 1U;
                                  if (1 < ret + 1U) {
                                    *(uint32_t *)((long)entry + 0x34) = 1;
                                  }
                                }
                                else {
                                  *(uint32_t *)(entry + 6) = 0;
                                }
                              }
                            }
                          }
load_ok_39:
                          _pthread_mutex_unlock((pthread_mutex_t *)&k_persist_rodata_word_24410);
                          goto load_ok_46;
                        }
                        _free(entry_13);
                        type_id_14 = 0xad009;
                      }
                    }
                    else {
                      type_id_14 = 0xad008;
                    }
load_ok_40:
                    _pthread_mutex_unlock((pthread_mutex_t *)&k_persist_rodata_word_24410);
                  }
                  else {
                    type_id_14 = -type_id_13;
                    if (-1 < (int)type_id_13) {
                      type_id_14 = type_id_13;
                    }
                    type_id_14 = type_id_14 | 0x40000000;
                  }
                  break;
                }
load_ok_46:
                ___register_frame(fde);
                type_id_14 = (int)type_id_17 + count + 4;
                type_id_17 = (unsigned long)type_id_14;
              } while (type_id_14 < type_id);
load_ok_34:
              type_id_14 = 0;
              *(uint8_t *)(arg + 0x22) = 1;
              *(uint8_t *)(arg + 0x26) = 1;
            }
          }
switchD_0001a42c_caseD_4d:
          if ((uint)type_id_19 != 0) {
            type_id_14 = (uint)type_id_19;
          }
          type_id_19 = (unsigned long)type_id_14;
          type_id_9 = type_id_9 + 1;
          if (*(uint *)(arg + 0x1e) <= type_id_9) {
            return type_id_19;
          }
          serial_11 = arg[0x1d];
        } while( true );
      }
    }
  }
  return type_id_9;
}





uint coruna_munmap(long handle)
{
  int *fde;
  long *ptr;
  uint u;
  int err;
  uint size;
  uint version;
  uint64_t *ptr;
  long *buf;
  long handle;
  void *str;
  void *copy;
  unsigned long port;
  long addr;
  void *data;
  uint tag;
  unsigned long kind;
  long off;
  
  if (handle == 0) {
    return 0xad001;
  }
  if (*(char *)(handle + 0xfd) == '\0') {
    return 0;
  }
  addr = *(long *)(handle + 0xe8);
  if (addr == 0) {
    return 0xad00f;
  }
  if (*(int *)(handle + 0xf0) == 0) {
    return 0xad00f;
  }
  port = 0;
  version = 0;
  if (addr == 0) goto fail;
  do {
    ptr = (long *)(addr + port * 0x10);
    off = *ptr;
    size = *(uint *)(ptr + 1);
    tag = 0xad001;
    if (off != 0 && size != 0) {
      kind = 0;
      do {
        fde = (int *)(off + kind);
        err = *fde;
        if (fde[1] != 0) {
          if (fde == (int *)0x0) {
            tag = 0xad001;
            goto done;
          }
          ___deregister_frame(fde);
        }
        tag = (int)kind + err + 4;
        kind = (unsigned long)tag;
      } while (tag < size);
      tag = 0;
    }
done:
    if (*(char *)(addr + port * 0x10 + 0xc) != '\0') {
      _bzero((void *)*ptr,(unsigned long)*(uint *)(ptr + 1));
      _munmap(*ptr,0x4000);
      *ptr = 0;
      ptr[1] = 0;
    }
    while( true ) {
      if (version != 0) {
        tag = version;
      }
      port = port + 1;
      if (*(uint *)(handle + 0xf0) <= port) {
        _bzero(*(void **)(handle + 0xe8),(unsigned long)*(uint *)(handle + 0xf0) << 4);
        _free(*(void **)(handle + 0xe8));
        *(uint64_t *)(handle + 0xe8) = 0;
        *(uint32_t *)(handle + 0xf0) = 0;
        if (k_persist_rodata_word_24920 == (void *)0x0) {
          return tag;
        }
        version = _pthread_mutex_lock((pthread_mutex_t *)&k_persist_rodata_word_24410);
        if (version != 0) {
          tag = -version;
          if (-1 < (int)version) {
            tag = version;
          }
          return tag | 0x40000000;
        }
        copy = k_persist_rodata_word_24920;
        if (k_persist_rodata_word_24920 != (void *)0x0) goto cleanup;
        _pthread_mutex_unlock((pthread_mutex_t *)&k_persist_rodata_word_24410);
        return tag;
      }
      addr = *(long *)(handle + 0xe8);
      version = tag;
      if (addr != 0) break;
fail:
      tag = 0xad00f;
    }
  } while( true );
cleanup:
  addr = k_persist_rodata_word_24928;
  data = *(void **)((long)copy + 0x28);
  if (*(long *)((long)copy + 8) == *(long *)(handle + 0x100)) {
    if (k_persist_rodata_word_24928 != 0) {
      err = *(int *)((long)copy + 0x14) + -0x61c88647;
      version = ((uint)*(byte *)((long)copy + 0x13) * 0x1000000 - err) +
              (uint)*(byte *)((long)copy + 0x12) * 0x10000 +
              (uint)*(byte *)((long)copy + 0x11) * 0x100 + (uint)*(byte *)((long)copy + 0x10)
              + 0x9f49bac2 ^ 0x7f76d;
      size = (err - version) + 0x1124109 ^ version << 8;
      u = 0xfeedbef7 - (version + size) ^ size >> 0xd;
      version = version - (size + u) ^ u >> 0xc;
      size = size - (u + version) ^ version << 0x10;
      u = u - (version + size) ^ size >> 5;
      version = version - (size + u) ^ u >> 3;
      size = size - (u + version) ^ version << 10;
      version = u - (version + size) ^ size >> 0xf;
      ptr = *(uint64_t **)(k_persist_rodata_word_24928 + 0x10);
      off = *(long *)((long)*ptr + (unsigned long)(*(int *)(ptr + 1) - 1U & version) * 0x10);
      if (off != 0) {
        handle = ptr[4];
        do {
          str = (void *)(off - handle);
          if (((*(uint *)((long)str + 0x44) == version) && (*(int *)((long)str + 0x40) == 8)) &&
             (**(long **)((long)str + 0x38) == *(long *)((long)copy + 0x10))) {
            off = *(long *)((long)str + 0x18);
            if ((off == 0) && (*(long *)((long)str + 0x20) == 0)) {
              _free((void *)*ptr);
              _free(*(void **)(addr + 0x10));
              k_persist_rodata_word_24928 = 0;
            }
            else {
              if (ptr[3] == (long)str + 0x10) {
                ptr[3] = off + handle;
              }
              if (off == 0) {
                addr = *(long *)((long)str + 0x20);
                k_persist_rodata_word_24928 = addr;
              }
              else {
                *(uint64_t *)(off + handle + 0x10) = *(uint64_t *)((long)str + 0x20);
                addr = *(long *)((long)str + 0x20);
              }
              if (addr != 0) {
                *(long *)(addr + *(long *)(*(long *)(k_persist_rodata_word_24928 + 0x10) + 0x20) + 8) = off;
              }
              buf = *(long **)(k_persist_rodata_word_24928 + 0x10);
              ptr = (long *)(*buf + (unsigned long)((int)buf[1] - 1U & version) * 0x10);
              *(int *)(ptr + 1) = (int)ptr[1] + -1;
              if (*ptr == (long)str + 0x10) {
                *ptr = *(long *)((long)str + 0x30);
              }
              addr = *(long *)((long)str + 0x28);
              if (addr != 0) {
                *(uint64_t *)(addr + 0x20) = *(uint64_t *)((long)str + 0x30);
              }
              if (*(long *)((long)str + 0x30) != 0) {
                *(long *)(*(long *)((long)str + 0x30) + 0x18) = addr;
              }
              *(int *)(buf + 2) = (int)buf[2] + -1;
            }
            _free(str);
            break;
          }
          off = *(long *)((long)str + 0x30);
        } while (off != 0);
      }
    }
    str = k_persist_rodata_word_24920;
    addr = *(long *)((long)copy + 0x20);
    if ((addr == 0) && (*(long *)((long)copy + 0x28) == 0)) {
      _free((void *)**(uint64_t **)((long)k_persist_rodata_word_24920 + 0x18));
      _free(*(void **)((long)str + 0x18));
      k_persist_rodata_word_24920 = (void *)0x0;
    }
    else {
      off = *(long *)((long)k_persist_rodata_word_24920 + 0x18);
      if ((long)copy + 0x18 == *(long *)(off + 0x18)) {
        *(long *)(off + 0x18) = addr + *(long *)(off + 0x20);
        if (addr != 0) goto skip;
next:
        str = *(void **)((long)copy + 0x28);
        k_persist_rodata_word_24920 = str;
      }
      else {
        if (addr == 0) goto next;
skip:
        *(uint64_t *)(addr + *(long *)(off + 0x20) + 0x10) =
             *(uint64_t *)((long)copy + 0x28);
        str = *(void **)((long)copy + 0x28);
      }
      if (str != (void *)0x0) {
        *(long *)((long)str + *(long *)(*(long *)((long)k_persist_rodata_word_24920 + 0x18) + 0x20) + 8) =
             addr;
      }
      buf = *(long **)((long)k_persist_rodata_word_24920 + 0x18);
      ptr = (long *)(*buf +
                       (unsigned long)((int)buf[1] - 1U & *(uint *)((long)copy + 0x4c)) * 0x10);
      *(int *)(ptr + 1) = (int)ptr[1] + -1;
      if (*ptr == (long)copy + 0x18) {
        *ptr = *(long *)((long)copy + 0x38);
      }
      addr = *(long *)((long)copy + 0x30);
      if (addr != 0) {
        *(uint64_t *)(addr + 0x20) = *(uint64_t *)((long)copy + 0x38);
      }
      if (*(long *)((long)copy + 0x38) != 0) {
        *(long *)(*(long *)((long)copy + 0x38) + 0x18) = addr;
      }
      *(int *)(buf + 2) = (int)buf[2] + -1;
    }
    _free(copy);
  }
  copy = data;
  if (data == (void *)0x0) {
check_ok:
    _pthread_mutex_unlock((pthread_mutex_t *)&k_persist_rodata_word_24410);
    return tag;
  }
  goto cleanup;
}





uint64_t coruna_task_info(long handle)
{
  kern_return_t lk1;
  int err;
  long handle;
  uint64_t u;
  int *err;
  uint64_t size;
  long addr;
  unsigned long version;
  uint64_t *ptr;
  mach_msg_type_number_t scratch;
  long bootargs [2];
  uint32_t thread_attr;
  
  size = 0xad011;
  if (handle == 0) {
    return 0xad001;
  }
  handle = _dlopen("/usr/lib/system/libunwind.dylib",2);
  if (handle == 0) {
    return 0x18004;
  }
  bootargs[0] = 0;
  bootargs[1] = 0;
  thread_attr = 0;
  scratch = 5;
  lk1 = _task_info(*(task_name_t *)k_persist_mach_task_self_slot,0x11,(task_info_t)bootargs,
                     &scratch);
  if (lk1 == 0 && scratch == 5) {
    u = 0xad014;
    if ((bootargs[0] != 0) && (*(long *)(bootargs[0] + 8) != 0)) {
      version = (unsigned long)*(uint *)(bootargs[0] + 4);
      if (*(uint *)(bootargs[0] + 4) == 0) {
        u = 0xad014;
      }
      else {
        ptr = (uint64_t *)(*(long *)(bootargs[0] + 8) + 8);
        do {
          if (((char *)*ptr != (char *)0x0) &&
             (err = _strcmp((char *)*ptr,"/usr/lib/system/libunwind.dylib"), err == 0)) {
            addr = ptr[-1];
            u = 0xad001;
            if ((addr != 0) && (err = *(int *)(addr + 0x10), u = size, err != 0)) {
              err = (int *)(addr + 0x20);
              goto fail;
            }
            break;
          }
          ptr = ptr + 3;
          version = version - 1;
          u = size;
        } while (version != 0);
      }
    }
  }
  else {
    u = 0xad00b;
  }
  _dlclose(handle);
  return u;
  while( true ) {
    err = (int *)((long)err + (unsigned long)(uint)err[1]);
    err = err + -1;
    if (err == 0) break;
fail:
    if (*err == 0x2a) {
      size = *(uint64_t *)(err + 2);
      bootargs[0] = 0;
      u = coruna_persistb080_via_macho_open_image(handle,addr,0,0x10,bootargs);
      if ((int)u == 0) {
        *(uint32_t *)(handle + 0x118) = 0;
        *(long *)(handle + 0x100) = handle;
        *(uint64_t *)(handle + 0x108) = size;
        *(long *)(handle + 0x110) = addr;
        return u;
      }
      break;
    }
  }
done:
  _dlclose(handle);
  return u;
}





uint64_t coruna_return_zero_15dbc(int *flags,void (*val,uint64_t val)
{
  int *err;
  uint u;
  uint size;
  unsigned long version;
  uint32_t *ptr;
  int *status;
  uint64_t port;
  unsigned long tag;
  unsigned long kind;
  
  port = 0xad001;
  if ((flags != (int *)0x0) && (arg != (void (*)0x0)) {
    if ((((unsigned long)flags & 3) == 0) && (*flags == 1)) {
      tag = 0;
      do {
        if ((uint)flags[6] <= tag) {
          return 0;
        }
        status = (int *)((long)flags + tag * 0xc + (unsigned long)(uint)flags[5]);
        if (status == (int *)0x0) {
          return 0xad001;
        }
        if (((unsigned long)status & 3) != 0) goto fail;
        version = (unsigned long)(uint)status[1];
        if (status[1] == 0) {
          port = (*arg)(*status,0,0,0,1,val);
        }
        else {
          err = (int *)((long)flags + version);
          if (*err == 3) {
            if (err == (int *)0x0) {
              return 0xad001;
            }
            if (((unsigned long)err & 3) != 0) goto fail;
            kind = 0;
            while (kind < *(ushort *)((long)err + 6)) {
              u = *(uint *)((long)flags + kind * 4 + *(ushort *)(err + 1) + version);
              size = u >> 0x18;
              if (size < (uint)flags[2]) {
                ptr = (uint32_t *)((long)flags + (unsigned long)size * 4 + (unsigned long)(uint)flags[1]);
              }
              else {
                ptr = (uint32_t *)
                         ((long)err +
                         (unsigned long)(size - flags[2]) * 4 + (unsigned long)*(ushort *)(err + 2));
              }
              port = coruna_persistb080_residual_159(flags,status,(u & 0xffffff) + *status,*ptr,arg,
                                   val);
              kind = kind + 1;
              if ((int)port != 0) {
                return port;
              }
            }
          }
          else {
            if (*err != 2) goto fail;
            if (err == (int *)0x0) {
              return 0xad001;
            }
            if (((unsigned long)err & 3) != 0) goto fail;
            kind = 0xffffffffffffffff;
            while (kind = kind + 1, kind < *(ushort *)((long)err + 6)) {
              if (((int)flags + (int)version + (uint)*(ushort *)(err + 1) & 3) != 0)
              goto fail;
              ptr = (uint32_t *)((long)flags + version + *(ushort *)(err + 1));
              port = coruna_persistb080_residual_159(flags,status,*ptr,ptr[1],arg,val);
              version = version + 8;
              if ((int)port != 0) {
                return port;
              }
            }
          }
          port = 0;
        }
        tag = tag + 1;
      } while ((int)port == 0);
    }
    else {
fail:
      port = 0xad014;
    }
  }
  return port;
}





uint64_t coruna_reallocf(int flags)
{
  long handle;
  uint64_t u;
  uint32_t *ptr;
  void *ptr;
  uint64_t *in_x5;
  long addr;
  
  u = 0xad001;
  if ((flags != 0) && (in_x5 != (uint64_t *)0x0)) {
    ptr = (uint32_t *)*in_x5;
    if (ptr == (uint32_t *)0x0) {
      ptr = _malloc(4);
      *in_x5 = ptr;
      if (ptr == (uint32_t *)0x0) {
        return 0xad009;
      }
      *ptr = 0;
    }
    handle = 0;
    do {
      addr = handle;
      handle = addr + 4;
    } while (*(int *)((long)ptr + addr) != 0);
    ptr = _reallocf(ptr,addr + 8);
    *in_x5 = ptr;
    u = 0xad009;
    if (ptr != (void *)0x0) {
      u = 0;
      ptr = (uint32_t *)((long)ptr + addr + 4);
      ptr[-1] = flags;
      *ptr = 0;
    }
  }
  return u;
}





void coruna_bzero_3(uint size,uint flags_2,uint count_3,uint version_4,uint version_5,long *handle)
{
  uint u;
  bool err;
  bool status;
  bool flags;
  void *ptr;
  uint32_t size;
  uint version;
  unsigned long port;
  unsigned long tag;
  long *buf;
  long handle;
  uint kind;
  uint type_id;
  uint type_id_8;
  char err;
  uint type_id_9;
  uint32_t *ptr;
  uint *buf;
  uint scratch;
  uint8_t bootargs[3];
  uint8_t scratch;
  uint32_t bootargs;
  uint64_t thread_attr;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t host_info;
  uint64_t sa_saved;
  uint64_t sa_new;
  uint64_t path_buf;
  uint64_t serial_buf;
  uint64_t tmp_buf;
  uint64_t region;
  uint64_t plist;
  long action;
  uint *str;
  
  action = *(long *)k_persist_stack_chk_guard_slot;
  tmp_buf = 0;
  serial_buf = 0;
  plist = 0;
  region = 0;
  sa_saved = 0;
  host_info = 0;
  path_buf = 0;
  sa_new = 0;
  action = 0;
  serial_buf = 0;
  stack_guard = 0;
  block_ctx = 0;
  thread_attr = 0;
  _local_b0 = 0;
  host_info = 0;
  thread_attr = 0;
  if (((((((version_5 != 0) || (size == 0)) || (flags_2 == 0)) ||
        ((handle == (long *)0x0 || (*handle == 0)))) ||
       ((handle[1] == 0 ||
        (((int)version_4 < 0 || (port = *(unsigned long *)(*handle + 0x10), port <= size)))))) ||
      (port <= count_3)) || (port <= version_4)) {
    type_id_8 = 0;
    if (flags_2 != 0) {
      type_id_8 = 0xad001;
    }
    kind = 0;
    if ((version_5 & 1) == 0) {
      kind = type_id_8;
    }
    port = (unsigned long)kind;
    if (*(long *)k_persist_stack_chk_guard_slot == action) {
    return;
    }
    ___stack_chk_fail(port);
  }
  _local_b0 = 0;
  bootargs = 0;
  thread_attr = 1;
  if (count_3 == 0 && version_4 == 0) {
    thread_attr = 0x527a01;
    port = 0xc;
  }
  else {
    if ((count_3 == 0) && (version_4 != 0)) {
      size = 0x52507a;
      thread_attr = (unsigned long)coruna_cat(size,1);
      port = 0xd;
    }
    else if ((count_3 == 0) || (version_4 != 0)) {
      *(uint8_t *)((uint32_t *)((unsigned long)bootargs | 9) + 1) = 0;
      *(uint32_t *)((unsigned long)bootargs | 9) = 0x524c507a;
      port = 0xe;
    }
    else {
      size = 0x524c7a;
      thread_attr = (unsigned long)coruna_cat(size,1);
      port = 0xd;
    }
  }
done:
  *(uint32_t *)((unsigned long)bootargs | port) = 0x1e7801;
  type_id_8 = (int)port + 3;
  if (version_4 == 0) {
    tag = 1;
  }
  else {
    bootargs[(unsigned long)type_id_8 + 1] = 0x84;
    *(unsigned long *)(bootargs + (unsigned long)type_id_8 + 2) = *(long *)(*handle + 0x100) + (unsigned long)version_4;
    tag = 10;
  }
  if (count_3 != 0) {
    bootargs[tag + type_id_8] = 4;
    tag = (unsigned long)((int)tag + 1);
  }
  bootargs[tag + type_id_8] = 4;
  kind = 0xad001;
  scratch = type_id_8;
  if (type_id_8 < 0x80) {
    kind = 0;
    bootargs[type_id_8] = (char)tag;
    scratch = (int)port + 4;
  }
  scratch = scratch + (int)tag;
  port = (unsigned long)scratch;
  u = flags_2 & 0xf000000;
  if (u == 0x4000000 || u == 0x2000000) {
    if (scratch < 0x7e) {
      err = false;
      type_id_9 = 0;
      bootargs[(unsigned long)scratch + 2] = 0;
      *(uint16_t *)(bootargs + scratch) = 0x1f0c;
      scratch = scratch + 3;
      port = (unsigned long)scratch;
    }
    else {
      err = false;
      type_id_9 = 0xad00c;
    }
  }
  else if (u == 0x3000000) {
    type_id_9 = 0;
    err = true;
  }
  else {
    err = false;
    type_id_9 = 0xad014;
  }
  version = (uint)port;
  if (0x7f < type_id_8) {
    type_id_9 = kind;
  }
  ptr = (uint32_t *)(bootargs + port);
  if (ptr < (uint32_t *)((unsigned long)(bootargs + port + 7) & 0xfffffffffffffff8)) {
    port = (unsigned long)scratch;
    do {
      *(uint8_t *)ptr = 0;
      version = (int)port + 1;
      port = (unsigned long)version;
      ptr = (uint32_t *)(bootargs + port);
      scratch = version;
    } while (ptr < (uint32_t *)((unsigned long)(bootargs + port + 7) & 0xfffffffffffffff8));
  }
  _local_b0 = coruna_u64_pack((bootargs), (version - 4));
  *ptr = 0;
  *(uint *)(bootargs + (scratch + 4)) = scratch + 4;
  buf = (uint *)handle[1];
  port = *(long *)(*handle + 0x100) + (unsigned long)size;
  *(unsigned long *)(bootargs + (scratch + 8)) = port;
  do {
    str = buf + 1;
    type_id_8 = *buf;
    buf = str;
  } while (type_id_8 != 0 && type_id_8 != size);
  if (((type_id_8 == 0) ||
      (type_id_8 = *str, kind = type_id_8 - size, tag = (unsigned long)kind, type_id = type_id_9,
      type_id_8 < size || kind == 0)) && (tag = port, type_id = 0xad014, type_id_9 != 0)) {
    type_id = type_id_9;
  }
  *(unsigned long *)(bootargs + (scratch + 0x10)) = tag;
  type_id_8 = scratch + 0x18;
  if (count_3 == 0) {
    if (type_id_8 < 0x80) {
      kind = 0;
      bootargs[type_id_8] = 0;
      type_id_8 = scratch + 0x19;
    }
    else {
      kind = 0xad001;
    }
    scratch = type_id_8;
    if (type_id != 0) {
      kind = type_id;
    }
  }
  else {
    if (type_id_8 < 0x80) {
      kind = 0;
      bootargs[type_id_8] = 8;
      type_id_8 = scratch + 0x19;
    }
    else {
      kind = 0xad001;
    }
    if (type_id != 0) {
      kind = type_id;
    }
    *(unsigned long *)(bootargs + type_id_8) = *(long *)(*handle + 0x100) + (unsigned long)count_3;
    scratch = type_id_8 + 8;
  }
  if (u == 0x2000000) {
    bootargs[scratch] = 0xe;
    type_id_8 = scratch + 1;
    if (type_id_8 < 0x80) {
      type_id_9 = flags_2 >> 8 & 0xfff0;
      port = (unsigned long)type_id_9;
      type_id = flags_2 >> 8 & 0x70;
      tag = (unsigned long)type_id;
      bootargs[type_id_8] = (char)type_id;
      scratch = scratch + 2;
      status = 0x7f < type_id_9;
      if ((status) && (type_id_8 = scratch, scratch != 0x80)) {
        do {
          bootargs[type_id_8 - 1] = (byte)tag | 0x80;
          tag = port >> 7 & 0x7f;
          bootargs[type_id_8] = (char)tag;
          scratch = type_id_8 + 1;
          status = 0x3fff < port;
          if (!status) break;
          port = port >> 7;
          flags = type_id_8 != 0x7f;
          type_id_8 = scratch;
        } while (flags);
      }
      type_id_8 = 0;
      if (status) {
        type_id_8 = 0xad00c;
      }
      err = '\x01';
      goto check_ok;
    }
    goto skip;
  }
  if (u == 0x4000000) {
    if (scratch < 0x7a) {
      *(uint32_t *)(bootargs + (unsigned long)scratch + 3) = 0x29d019e;
      *(uint32_t *)(bootargs + scratch) = 0x9e101d0c;
      scratch = scratch + 7;
      err = '\x03';
next:
      if ((flags_2 & 1) == 0) {
retry:
        if ((flags_2 >> 1 & 1) == 0) {
found:
          if ((flags_2 >> 2 & 1) == 0) {
nomem:
            if ((flags_2 >> 3 & 1) == 0) {
invalid:
              if ((flags_2 >> 4 & 1) == 0) {
                if ((flags_2 >> 8 & 1) == 0) {
again:
                  if ((flags_2 >> 9 & 1) == 0) {
exit_ok:
                    if ((flags_2 >> 10 & 1) == 0) {
joined_r0x0001c340:
                      if ((flags_2 >> 0xb & 1) == 0) {
                        type_id_8 = 0;
                        u = 0;
                        if (type_id_8 != 0xad005) {
                        u = type_id_8;
                        }
                        if (kind != 0) {
                        u = kind;
                        }
                        port = (unsigned long)u;
                        *(uint *)(bootargs + (unsigned long)(version - 4) + 4) = (scratch - version) + -4;
                        if (*(long *)k_persist_stack_chk_guard_slot == action) {
                        return;
                        }
                        ___stack_chk_fail(port);
                        buf = (long *)handle[2];
                        if ((buf == (long *)0x0) ||
                        ((handle = *buf, handle == 0 ||
                        (port = (unsigned long)*(uint *)(buf + 1), 0x4000 < scratch + *(uint *)(buf + 1))))) {
                        port = coruna_vec_push_pair(*handle + 0xe8,*handle + 0xf0);
                        if (*(long *)k_persist_stack_chk_guard_slot == action) {
                        return;
                        }
                        ___stack_chk_fail(port);
                        handle[2] = *(long *)(*handle + 0xe8) + (unsigned long)(*(int *)(*handle + 0xf0) - 1) * 0x10;
                        ptr = (void *)_mmap(0,0x4000,3,&k_persist_mmap_anon_fd,0xffffffff,0);
                        *(void **)handle[2] = ptr;
                        if (ptr == (void *)0xffffffffffffffff) {
                        port = 0xad009;
                        if (*(long *)k_persist_stack_chk_guard_slot == action) {
                        return;
                        }
                        ___stack_chk_fail(port);
                        }
                        _bzero(ptr,0x4000);
                        port = 0;
                        buf = (long *)handle[2];
                        *(uint32_t *)(buf + 1) = 0;
                        *(uint8_t *)((long)buf + 0xc) = 1;
                        handle = *buf;
                        }
                        coruna_persistb080_trampoline_00010c24(handle + port,bootargs,scratch);
                        port = 0;
                        *(uint *)(handle[2] + 8) = *(int *)(handle[2] + 8) + scratch;
                        if (*(long *)k_persist_stack_chk_guard_slot == action) {
                        return;
                        }
                        ___stack_chk_fail(port);
                      }
                      bootargs[scratch] = 0xce;
                      type_id_8 = scratch + 1;
                      if (type_id_8 < scratch + 2) {
                        bootargs[type_id_8] = err;
                        bootargs[scratch + 2] = 0xcf;
                        type_id_8 = scratch + 3;
                        scratch = scratch + 4;
                        if (type_id_8 < scratch) {
                          bootargs[type_id_8] = err + '\x01';
                          type_id_8 = 0;
                          u = 0;
                          if (type_id_8 != 0xad005) {
                          u = type_id_8;
                          }
                          if (kind != 0) {
                          u = kind;
                          }
                          port = (unsigned long)u;
                          *(uint *)(bootargs + (unsigned long)(version - 4) + 4) = (scratch - version) + -4;
                          if (*(long *)k_persist_stack_chk_guard_slot == action) {
                          return;
                          }
                          ___stack_chk_fail(port);
                          buf = (long *)handle[2];
                          if ((buf == (long *)0x0) ||
                          ((handle = *buf, handle == 0 ||
                          (port = (unsigned long)*(uint *)(buf + 1), 0x4000 < scratch + *(uint *)(buf + 1))))) {
                          port = coruna_vec_push_pair(*handle + 0xe8,*handle + 0xf0);
                          if (*(long *)k_persist_stack_chk_guard_slot == action) {
                          return;
                          }
                          ___stack_chk_fail(port);
                          handle[2] = *(long *)(*handle + 0xe8) + (unsigned long)(*(int *)(*handle + 0xf0) - 1) * 0x10;
                          ptr = (void *)_mmap(0,0x4000,3,&k_persist_mmap_anon_fd,0xffffffff,0);
                          *(void **)handle[2] = ptr;
                          if (ptr == (void *)0xffffffffffffffff) {
                          port = 0xad009;
                          if (*(long *)k_persist_stack_chk_guard_slot == action) {
                          return;
                          }
                          ___stack_chk_fail(port);
                          }
                          _bzero(ptr,0x4000);
                          port = 0;
                          buf = (long *)handle[2];
                          *(uint32_t *)(buf + 1) = 0;
                          *(uint8_t *)((long)buf + 0xc) = 1;
                          handle = *buf;
                          }
                          coruna_persistb080_trampoline_00010c24(handle + port,bootargs,scratch);
                          port = 0;
                          *(uint *)(handle[2] + 8) = *(int *)(handle[2] + 8) + scratch;
                          if (*(long *)k_persist_stack_chk_guard_slot == action) {
                          return;
                          }
                          ___stack_chk_fail(port);
                        }
                      }
                    }
                    else {
                      bootargs[scratch] = 0xcc;
                      type_id_8 = scratch + 1;
                      if (type_id_8 < scratch + 2) {
                        bootargs[type_id_8] = err;
                        bootargs[scratch + 2] = 0xcd;
                        type_id_8 = scratch + 3;
                        scratch = scratch + 4;
                        if (type_id_8 < scratch) {
                          bootargs[type_id_8] = err + '\x01';
                          err = err + '\x02';
                          goto joined_r0x0001c340;
                        }
                      }
                    }
                  }
                  else {
                    bootargs[scratch] = 0xca;
                    type_id_8 = scratch + 1;
                    if (type_id_8 < scratch + 2) {
                      bootargs[type_id_8] = err;
                      bootargs[scratch + 2] = 0xcb;
                      type_id_8 = scratch + 3;
                      scratch = scratch + 4;
                      if (type_id_8 < scratch) {
                        bootargs[type_id_8] = err + '\x01';
                        err = err + '\x02';
                        goto exit_ok;
                      }
                    }
                  }
                }
                else {
load_ok:
                  bootargs[scratch] = 200;
                  type_id_8 = scratch + 1;
                  if (type_id_8 < scratch + 2) {
                    bootargs[type_id_8] = err;
                    bootargs[scratch + 2] = 0xc9;
                    type_id_8 = scratch + 3;
                    scratch = scratch + 4;
                    if (type_id_8 < scratch) {
                      bootargs[type_id_8] = err + '\x01';
                      err = err + '\x02';
                      goto again;
                    }
                  }
                }
              }
              else {
                bootargs[scratch] = 0x9b;
                type_id_8 = scratch + 1;
                if (type_id_8 < scratch + 2) {
                  bootargs[type_id_8] = err;
                  bootargs[scratch + 2] = 0x9c;
                  type_id_8 = scratch + 3;
                  scratch = scratch + 4;
                  if (type_id_8 < scratch) {
                    bootargs[type_id_8] = err + '\x01';
                    err = err + '\x02';
                    if ((flags_2 >> 8 & 1) != 0) goto load_ok;
                    goto again;
                  }
                }
              }
            }
            else {
              bootargs[scratch] = 0x99;
              type_id_8 = scratch + 1;
              if (type_id_8 < scratch + 2) {
                bootargs[type_id_8] = err;
                bootargs[scratch + 2] = 0x9a;
                type_id_8 = scratch + 3;
                scratch = scratch + 4;
                if (type_id_8 < scratch) {
                  bootargs[type_id_8] = err + '\x01';
                  err = err + '\x02';
                  goto invalid;
                }
              }
            }
          }
          else {
            bootargs[scratch] = 0x97;
            type_id_8 = scratch + 1;
            if (type_id_8 < scratch + 2) {
              bootargs[type_id_8] = err;
              bootargs[scratch + 2] = 0x98;
              type_id_8 = scratch + 3;
              scratch = scratch + 4;
              if (type_id_8 < scratch) {
                bootargs[type_id_8] = err + '\x01';
                err = err + '\x02';
                goto nomem;
              }
            }
          }
        }
        else {
          bootargs[scratch] = 0x95;
          type_id_8 = scratch + 1;
          if (type_id_8 < scratch + 2) {
            bootargs[type_id_8] = err;
            bootargs[scratch + 2] = 0x96;
            type_id_8 = scratch + 3;
            scratch = scratch + 4;
            if (type_id_8 < scratch) {
              bootargs[type_id_8] = err + '\x01';
              err = err + '\x02';
              goto found;
            }
          }
        }
      }
      else {
        bootargs[scratch] = 0x93;
        type_id_8 = scratch + 1;
        if (type_id_8 < scratch + 2) {
          bootargs[type_id_8] = err;
          bootargs[scratch + 2] = 0x94;
          type_id_8 = scratch + 3;
          scratch = scratch + 4;
          if (type_id_8 < scratch) {
            bootargs[type_id_8] = err + '\x01';
            err = err + '\x02';
            goto retry;
          }
        }
      }
skip:
      scratch = type_id_8;
      type_id_8 = 0xad001;
    }
    else {
      type_id_8 = 0xad00c;
    }
  }
  else {
    err = '\0';
    type_id_8 = 0;
check_ok:
    if ((u == 0x4000000) || (u == 0x2000000)) {
      if (type_id_8 == 0) goto next;
    }
    else {
      type_id_8 = 0xad005;
      if (u != 0x3000000) {
        type_id_8 = 0xad014;
      }
    }
  }
parse_ok:
  u = 0;
  if (type_id_8 != 0xad005) {
    u = type_id_8;
  }
  if (kind != 0) {
    u = kind;
  }
  port = (unsigned long)u;
  *(uint *)(bootargs + (unsigned long)(version - 4) + 4) = (scratch - version) + -4;
  if (*(long *)k_persist_stack_chk_guard_slot == action) {
  return;
  }
  ___stack_chk_fail(port);
  buf = (long *)handle[2];
  if ((buf == (long *)0x0) ||
     ((handle = *buf, handle == 0 ||
      (port = (unsigned long)*(uint *)(buf + 1), 0x4000 < scratch + *(uint *)(buf + 1))))) {
    port = coruna_vec_push_pair(*handle + 0xe8,*handle + 0xf0);
    if (*(long *)k_persist_stack_chk_guard_slot == action) {
    return;
    }
    ___stack_chk_fail(port);
    handle[2] = *(long *)(*handle + 0xe8) + (unsigned long)(*(int *)(*handle + 0xf0) - 1) * 0x10;
    ptr = (void *)_mmap(0,0x4000,3,&k_persist_mmap_anon_fd,0xffffffff,0);
    *(void **)handle[2] = ptr;
    if (ptr == (void *)0xffffffffffffffff) {
      port = 0xad009;
      if (*(long *)k_persist_stack_chk_guard_slot == action) {
      return;
      }
      ___stack_chk_fail(port);
    }
    _bzero(ptr,0x4000);
    port = 0;
    buf = (long *)handle[2];
    *(uint32_t *)(buf + 1) = 0;
    *(uint8_t *)((long)buf + 0xc) = 1;
    handle = *buf;
  }
  coruna_persistb080_trampoline_00010c24(handle + port,bootargs,scratch);
  port = 0;
  *(uint *)(handle[2] + 8) = *(int *)(handle[2] + 8) + scratch;
fail:
  if (*(long *)k_persist_stack_chk_guard_slot == action) {
    return;
  }
  ___stack_chk_fail(port);
}





uint64_t
void coruna_persistb080_residual_159(long handle,long addr_2,uint64_t val,uint64_t id_2,
            void (*indirect_target)
{
  uint32_t u;
  uint size;
  int *err;
  uint64_t version;
  int err;
  int *status;
  
  if (handle == 0) {
    return 0xad001;
  }
  if (indirect_target == (void (*)0x0) {
    return 0xad001;
  }
  if (((uint)id_2 >> 0x1e & 1) != 0) {
    if (*(int *)(handle + 0x18) != 0) {
      err = (int *)(handle + (unsigned long)*(uint *)(addr_2 + 8));
      do {
        status = err;
        err = status + 2;
      } while (*status != (int)val &&
               status < (int *)(handle +
                               (unsigned long)*(uint *)(handle + (unsigned long)*(uint *)(handle + 0x14) +
                                                (unsigned long)(*(int *)(handle + 0x18) - 1) * 0xc + 8)));
      if (*status == (int)val) {
        err = status[1];
        size = (uint)id_2 >> 0x1c & 3;
        u = 0;
        if (size != 0) {
        size = size - 1;
        if (*(uint *)(handle + 0x10) <= size) {
        return 0xad014;
        }
        u = *(uint32_t *)(handle + (unsigned long)*(uint *)(handle + 0xc) + (unsigned long)size * 4);
        }
        version = (*indirect_target)(val,id_2,err,u,0);
        return version;
      }
    }
    return 0xad014;
  }
  err = 0;
fail:
  size = (uint)id_2 >> 0x1c & 3;
  u = 0;
  if (size != 0) {
    size = size - 1;
    if (*(uint *)(handle + 0x10) <= size) {
      return 0xad014;
    }
    u = *(uint32_t *)(handle + (unsigned long)*(uint *)(handle + 0xc) + (unsigned long)size * 4);
  }
  version = (*indirect_target)(val,id_2,err,u,0);
  return version;
}





uint64_t
void coruna_unw_get_proc_info(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4,
            unw_cursor_t *arg)
{
  uint u;
  uint size;
  uint version;
  int err;
  unw_word_t *ptr;
  uint64_t port;
  long handle;
  long *ptr;
  long addr;
  void (*ptr)(void);
  unw_proc_info_t scratch;
  unw_word_t bootargs;
  
  if (arg == (unw_cursor_t *)0x0) {
    return 0;
  }
  scratch.extra = 0;
  scratch.flags = 0;
  scratch.gp = 0;
  scratch.unwind_info = 0;
  scratch.format = 0;
  scratch.unwind_info_size = 0;
  scratch.end_ip = 0;
  scratch.start_ip = 0;
  scratch.handler = 0;
  scratch.lsda = 0;
  err = _unw_get_proc_info(arg,&scratch);
  if (err != 0) {
    return 0;
  }
  err = _pthread_mutex_lock((pthread_mutex_t *)&k_persist_rodata_word_24410);
  if (err != 0) {
    return 0;
  }
  bootargs = scratch.lsda;
  if (k_persist_rodata_word_24920 != 0) {
    err = (int)(scratch.lsda >> 0x20);
    u = ((int)scratch.lsda + -0x60b6453e) - (err + -0x61c88647) ^ 0x7f76d;
    size = (err + -0x60b6453e) - u ^ u << 8;
    version = 0xfeedbef7 - (u + size) ^ size >> 0xd;
    u = u - (size + version) ^ version >> 0xc;
    size = size - (version + u) ^ u << 0x10;
    version = version - (u + size) ^ size >> 5;
    u = u - (size + version) ^ version >> 3;
    size = size - (version + u) ^ u << 10;
    u = version - (u + size) ^ size >> 0xf;
    ptr = *(long **)(k_persist_rodata_word_24920 + 0x18);
    addr = *(long *)(*ptr + (unsigned long)((int)ptr[1] - 1U & u) * 0x10);
    if (addr != 0) {
      do {
        addr = addr - ptr[4];
        if (((*(uint *)(addr + 0x4c) == u) && (*(int *)(addr + 0x48) == 8)) &&
           (**(unw_word_t **)(addr + 0x40) == scratch.lsda)) {
          if (k_persist_rodata_word_24928 != 0) {
            err = (uint)*(byte *)(addr + 0x17) * 0x1000000 + -0x61c88647 +
                    (uint)*(byte *)(addr + 0x16) * 0x10000 + (uint)*(byte *)(addr + 0x15) * 0x100
                    + (uint)*(byte *)(addr + 0x14);
            u = (((uint)*(byte *)(addr + 0x13) * 0x1000000 + -0x60b6453e) - err) +
                    (uint)*(byte *)(addr + 0x12) * 0x10000 + (uint)*(byte *)(addr + 0x11) * 0x100
                    + (uint)*(byte *)(addr + 0x10) ^ 0x7f76d;
            size = (err + 0x1124109) - u ^ u << 8;
            version = 0xfeedbef7 - (u + size) ^ size >> 0xd;
            u = u - (size + version) ^ version >> 0xc;
            size = size - (version + u) ^ u << 0x10;
            version = version - (u + size) ^ size >> 5;
            u = u - (size + version) ^ version >> 3;
            size = size - (version + u) ^ u << 10;
            u = version - (u + size) ^ size >> 0xf;
            ptr = *(long **)(k_persist_rodata_word_24928 + 0x10);
            handle = *(long *)(*ptr + (unsigned long)((int)ptr[1] - 1U & u) * 0x10);
            if (handle != 0) {
              goto fail;
            }
          }
          break;
        }
        addr = *(long *)(addr + 0x38);
      } while (addr != 0);
    }
  }
  _pthread_mutex_unlock((pthread_mutex_t *)&k_persist_rodata_word_24410);
  return 0;
  while (handle = *(long *)(handle + 0x30), handle != 0) {
fail:
    handle = handle - ptr[4];
    if (((*(uint *)(handle + 0x44) == u) && (*(int *)(handle + 0x40) == 8)) &&
       (**(long **)(handle + 0x38) == *(long *)(addr + 0x10))) {
      if (scratch.extra == 0) {
        ptr = _memmem(arg,0x598,&scratch,0x48);
        if (ptr == (unw_word_t *)0x0) break;
        scratch.extra = *(unw_word_t *)(addr + 8);
        ptr[5] = scratch.flags;
        ptr[4] = scratch.gp;
        ptr[7] = scratch.unwind_info;
        ptr[6] = scratch;
        ptr[3] = scratch.handler;
        ptr[2] = scratch.lsda;
        ptr[1] = scratch.end_ip;
        *ptr = scratch.start_ip;
        ptr[8] = scratch.extra;
      }
      ptr = *(void (**)(handle + 8);
      _pthread_mutex_unlock((pthread_mutex_t *)&k_persist_rodata_word_24410);
      port = (*ptr)(val,id_2,size_3,off_4,arg);
      return port;
    }
  }
done:
  _pthread_mutex_unlock((pthread_mutex_t *)&k_persist_rodata_word_24410);
  return 0;
}





uint64_t coruna_sign_extend_uleb(unsigned long *arg,long handle,uint *size,unsigned long arg)
{
  uint64_t u;
  unsigned long scratch;
  unsigned long bootargs;
  
  scratch = 0;
  bootargs = 0;
  u = 0xad001;
  if ((((arg != (unsigned long *)0x0) && (handle != 0)) && (size != (uint *)0x0)) &&
     ((*size < arg &&
      (u = coruna_read_uleb128(&bootargs,&scratch,handle,size,arg), (int)u == 0)))) {
    if ((*(byte *)(handle + (unsigned long)(*size - 1)) >> 6 & 1) == 0) {
      u = 0;
    }
    else {
      u = 0;
      *arg = bootargs | -1L << (scratch & 0x3f);
    }
  }
  return u;
}





uint64_t
void coruna_persistb080_via_sign_extend_uleb(unsigned long *arg,uint size,long handle,uint *flags_2,unsigned long arg,int flags)
{
  unsigned long *ptr;
  uint u;
  unsigned long size;
  bool err;
  uint64_t version;
  uint port;
  unsigned long scratch;
  unsigned long bootargs;
  
  if (arg == (unsigned long *)0x0) {
    return 0xad001;
  }
  if (handle == 0) {
    return 0xad001;
  }
  if (flags_2 == (uint *)0x0) {
    return 0xad001;
  }
  port = *flags_2;
  if (arg <= port) {
    return 0xad001;
  }
  if (size == 0xff) {
    bootargs = 0;
    version = 0;
    *arg = bootargs;
  }
  u = size & 0xf;
  version = 0xad008;
  if (0xc < u) {
    return 0xad008;
  }
  ptr = (unsigned long *)(handle + (unsigned long)port);
  switch(u) {
  case 0:
  case 4:
    scratch = *ptr;
    port = port + 8;
    break;
  case 1:
    scratch = 0;
    bootargs = 0;
    version = coruna_read_uleb128(&scratch,&bootargs);
    err = false;
    bootargs = 0;
    goto done;
  case 2:
    scratch = (unsigned long)(ushort)*ptr;
    port = port + 2;
    break;
  case 3:
    scratch = (unsigned long)(uint)*ptr;
    port = port + 4;
    break;
  default:
    return version;
done:
    if ((int)version != 0) {
      return version;
    }
    port = 0;
    if (flags == 0) {
    port = size & 0x70;
    }
    if (port == 0x10) {
    size = scratch;
    if (!(bool)(u == 0 & (err ^ 1U))) {
    size = bootargs;
    }
    if (u != 0 && !err) {
    size = scratch;
    }
    bootargs = size + (long)ptr;
    }
    else {
    if (port != 0) {
    return 0xad008;
    }
    if (!err) {
    bootargs = scratch;
    }
    }
    version = 0;
    *arg = bootargs;
  case 10:
    bootargs = (unsigned long)(short)*ptr;
    port = port + 2;
    goto cleanup;
  case 0xb:
    bootargs = (unsigned long)(int)(uint)*ptr;
    port = port + 4;
cleanup:
    scratch = 0;
    *flags_2 = port;
    err = true;
    port = 0;
    if (flags == 0) {
    port = size & 0x70;
    }
    if (port == 0x10) {
    size = scratch;
    if (!(bool)(u == 0 & (err ^ 1U))) {
    size = bootargs;
    }
    if (u != 0 && !err) {
    size = scratch;
    }
    bootargs = size + (long)ptr;
    }
    else {
    if (port != 0) {
    return 0xad008;
    }
    if (!err) {
    bootargs = scratch;
    }
    }
    version = 0;
    *arg = bootargs;
  }
  err = false;
  bootargs = 0;
  *flags_2 = port;
check_ok:
  port = 0;
  if (flags == 0) {
    port = size & 0x70;
  }
  if (port == 0x10) {
    size = scratch;
    if (!(bool)(u == 0 & (err ^ 1U))) {
      size = bootargs;
    }
    if (u != 0 && !err) {
      size = scratch;
    }
    bootargs = size + (long)ptr;
  }
  else {
    if (port != 0) {
      return 0xad008;
    }
    if (!err) {
      bootargs = scratch;
    }
  }
fail:
  version = 0;
  *arg = bootargs;
switchD_0001c9d4_caseD_5:
  return version;
}





uint64_t coruna_read_uleb128(unsigned long *arg,unsigned long *arg,long handle,uint *size,unsigned long val)
{
  byte err;
  byte status;
  unsigned long u;
  uint64_t size;
  unsigned long version;
  byte flags;
  uint port;
  unsigned long tag;
  unsigned long kind;
  
  size = 0xad001;
  if (((arg != (unsigned long *)0x0) && (handle != 0)) && (size != (uint *)0x0)) {
    port = *size;
    kind = (unsigned long)port;
    if (kind < arg) {
      version = 0;
      u = 0;
      flags = 1;
      do {
        tag = u;
        port = port + 1;
        status = *(byte *)(handle + kind);
        version = version | (long)(int)((status & 0x7f) << (unsigned long)((uint)tag & 0x1f));
        err = status >> 7;
        if (0x32 < tag) {
          err = flags;
        }
        *size = port;
      } while ((tag < 0x33) &&
              (kind = (unsigned long)port, u = tag + 7, flags = err,
              (status & 0x80) != 0 && kind < arg));
      if (0x32 < tag || err != 0) {
        return 0xad014;
      }
      size = 0;
      *arg = version;
      *val = tag + 7;
    }
  }
  return size;
}





uint64_t coruna_persistb080_via_ctx_free_11dc8(long handle,uint64_t val,pthread_mutex_t *arg)
{
  uint64_t *ptr;
  unsigned long u;
  uint size;
  uint version;
  bool err;
  int err;
  uint64_t port;
  unsigned long tag;
  long handle;
  unsigned long kind;
  uint64_t type_id;
  long scratch;
  pthread_mutex_t *bootargs;
  char thread_attr;
  long host_info;
  uint64_t serial_buf;
  
  type_id = 0xad001;
  if ((handle != 0) && (arg != (pthread_mutex_t *)0x0)) {
    err = _pthread_mutex_lock(arg);
    if (err == 0) {
      if ((char)arg[1].__sig == '\0') {
        arg[1].__opaque[0xc] = '\x01';
        arg[1].__opaque[0] = '\0';
        arg[1].__opaque[1] = '\0';
        arg[1].__opaque[2] = '\0';
        arg[1].__opaque[3] = '\0';
        arg[1].__opaque[4] = '\0';
        arg[1].__opaque[5] = '\0';
        arg[1].__opaque[6] = '\0';
        arg[1].__opaque[7] = '\0';
        arg[1].__opaque[8] = '\0';
        arg[1].__opaque[9] = '\0';
        arg[1].__opaque[10] = '\0';
        arg[1].__opaque[0xb] = '\0';
        host_info = 0;
        port = coruna_persistb080_via_macho_open_image(handle,val,0,0,&host_info);
        if ((int)port == 0) {
          thread_attr = '\0';
          scratch = handle;
          bootargs = arg;
          if (host_info != 0) {
            if ((*(ushort *)(host_info + 0x1c0) >> 7 & 1) == 0) {
              type_id = coruna_persistb080_via_persistb080_via_block_dispose_157f4(host_info,&k_persist_rodata_word_1cf38,&scratch);
              err = (int)type_id;
joined_r0x0001ce30:
              if (err == 0) {
                if (thread_attr == '\0') {
                  type_id = 0x18012;
                }
                else {
                  type_id = 0;
                  *(uint8_t *)&arg[1].__sig = 1;
                }
              }
            }
            else {
              handle = *(long *)(host_info + 8);
              tag = 0;
              do {
                if (*(long *)(handle + tag) == -0x55fdfc1e55fefc20) {
                  size = *(uint *)(handle + tag + 8);
                  if ((size & 0x7c000000) == 0x14000000) {
                    u = (unsigned long)(size & 0x1ffffff);
                    if ((size & 0x2000000) != 0) {
                      u = (unsigned long)size | 0xfffffffffe000000;
                    }
                    size = *(uint *)(handle + u * 4 + tag + 8);
                    if (((size & 0x9f000000) == 0x90000000) &&
                       (version = *(uint *)(handle + u * 4 + tag + 0xc),
                       (version & 0x7f000000) == 0x11000000)) {
                      kind = (unsigned long)(version >> 10) & 0xfff;
                      if ((version & 0xc00000) != 0) {
                        kind = kind << 0xc;
                      }
                      ptr = (uint64_t *)
                               ((handle + u * 4 + tag + 8 & 0xfffffffffffff000) +
                                (long)(int)(size >> 0x11 & 0x3000 | (size >> 5) << 0xe) + kind);
                      if (ptr == (uint64_t *)0x0) goto fail;
                      if (k_persist_strcmp_slot == (uint8_t *)*ptr) {
                        serial_buf = 0;
                        type_id = coruna_mach_vm_machine_attribute(arg,handle,&serial_buf);
                        port = serial_buf;
                        if ((int)type_id == 0) {
                          err = coruna_return_zero();
                          if (err != 0) {
                            port = coruna_pacia(port,ptr);
                          }
                          serial_buf = port;
                          type_id = coruna_vm_protect(ptr,port);
                        }
                      }
                      else {
                        type_id = 0;
                      }
                      thread_attr = '\x01';
                      err = (int)type_id;
                      goto joined_r0x0001ce30;
                    }
                  }
                }
                err = tag < 0x7ffc;
                tag = tag + 4;
              } while (err);
              type_id = 0xad000;
            }
          }
fail:
          coruna_ctx_free_11dc8(host_info);
          port = type_id;
        }
      }
      else {
        port = 0;
      }
      type_id = port;
      _pthread_mutex_unlock(arg);
    }
    else {
      type_id = 0x18013;
    }
  }
  return type_id;
}





uint32_t coruna_pthread_mutex_init(long handle,pthread_mutex_t *arg)
{
  int err;
  uint32_t u;
  
  u = 0xad001;
  if ((handle != 0) && (arg != (pthread_mutex_t *)0x0)) {
    arg[1].__opaque[8] = '\0';
    arg[1].__opaque[9] = '\0';
    arg[1].__opaque[10] = '\0';
    arg[1].__opaque[0xb] = '\0';
    arg[1].__opaque[0xc] = '\0';
    arg[1].__opaque[0xd] = '\0';
    arg[1].__opaque[0xe] = '\0';
    arg[1].__opaque[0xf] = '\0';
    arg->__opaque[0x30] = '\0';
    arg->__opaque[0x31] = '\0';
    arg->__opaque[0x32] = '\0';
    arg->__opaque[0x33] = '\0';
    arg->__opaque[0x34] = '\0';
    arg->__opaque[0x35] = '\0';
    arg->__opaque[0x36] = '\0';
    arg->__opaque[0x37] = '\0';
    arg->__opaque[0x28] = '\0';
    arg->__opaque[0x29] = '\0';
    arg->__opaque[0x2a] = '\0';
    arg->__opaque[0x2b] = '\0';
    arg->__opaque[0x2c] = '\0';
    arg->__opaque[0x2d] = '\0';
    arg->__opaque[0x2e] = '\0';
    arg->__opaque[0x2f] = '\0';
    arg[1].__opaque[0] = '\0';
    arg[1].__opaque[1] = '\0';
    arg[1].__opaque[2] = '\0';
    arg[1].__opaque[3] = '\0';
    arg[1].__opaque[4] = '\0';
    arg[1].__opaque[5] = '\0';
    arg[1].__opaque[6] = '\0';
    arg[1].__opaque[7] = '\0';
    arg[1].__sig = 0;
    arg->__opaque[0x10] = '\0';
    arg->__opaque[0x11] = '\0';
    arg->__opaque[0x12] = '\0';
    arg->__opaque[0x13] = '\0';
    arg->__opaque[0x14] = '\0';
    arg->__opaque[0x15] = '\0';
    arg->__opaque[0x16] = '\0';
    arg->__opaque[0x17] = '\0';
    arg->__opaque[8] = '\0';
    arg->__opaque[9] = '\0';
    arg->__opaque[10] = '\0';
    arg->__opaque[0xb] = '\0';
    arg->__opaque[0xc] = '\0';
    arg->__opaque[0xd] = '\0';
    arg->__opaque[0xe] = '\0';
    arg->__opaque[0xf] = '\0';
    arg->__opaque[0x20] = '\0';
    arg->__opaque[0x21] = '\0';
    arg->__opaque[0x22] = '\0';
    arg->__opaque[0x23] = '\0';
    arg->__opaque[0x24] = '\0';
    arg->__opaque[0x25] = '\0';
    arg->__opaque[0x26] = '\0';
    arg->__opaque[0x27] = '\0';
    arg->__opaque[0x18] = '\0';
    arg->__opaque[0x19] = '\0';
    arg->__opaque[0x1a] = '\0';
    arg->__opaque[0x1b] = '\0';
    arg->__opaque[0x1c] = '\0';
    arg->__opaque[0x1d] = '\0';
    arg->__opaque[0x1e] = '\0';
    arg->__opaque[0x1f] = '\0';
    arg->__opaque[0] = '\0';
    arg->__opaque[1] = '\0';
    arg->__opaque[2] = '\0';
    arg->__opaque[3] = '\0';
    arg->__opaque[4] = '\0';
    arg->__opaque[5] = '\0';
    arg->__opaque[6] = '\0';
    arg->__opaque[7] = '\0';
    arg->__sig = 0;
    err = _pthread_mutex_init(arg,(pthread_mutexattr_t *)0x0);
    u = 0;
    if (err != 0) {
      u = 0x18013;
    }
  }
  return u;
}





uint64_t coruna_persistb080_via_persistb080_via_persistb080_via_mach_vm_region_recurse(long handle,pthread_mutex_t *arg)
{
  int err;
  uint64_t u;
  
  u = 0xad001;
  if ((handle != 0) && (arg != (pthread_mutex_t *)0x0)) {
    err = _pthread_mutex_lock(arg);
    if (err == 0) {
      if (((char)arg[1].__sig == '\0') || (arg[1].__opaque[0xc] != '\0')) {
        u = 0;
      }
      else if (*(long *)arg[1].__opaque == 0) {
        u = 0;
        arg[1].__opaque[0xc] = '\x01';
      }
      else {
        u = coruna_persistb080_via_persistb080_via_mach_vm_region_recurse(handle,*(uint32_t *)k_persist_mach_task_self_slot,
                             *(long *)arg[1].__opaque,*(uint32_t *)(arg[1].__opaque + 8));
      }
      _pthread_mutex_unlock(arg);
    }
    else {
      u = 0x18013;
    }
  }
  return u;
}





uint64_t coruna_mach_vm_machine_attribute(long handle,long addr_2,mach_vm_address_t *arg)
{
  uint8_t *ptr;
  int err;
  mach_vm_address_t address;
  uint64_t u;
  vm_machine_attribute_val_t scratch;
  uint8_t bootargs;
  
  u = 0xad001;
  if ((handle != 0) && (arg != (mach_vm_address_t *)0x0)) {
    if (*(mach_vm_address_t *)(handle + 0x48) == 0) {
      if (addr_2 != 0) {
        u = 0x18011;
        address = _mmap(0,0x38,3,&k_persist_mmap_anon_fd,0xffffffff,0);
        if (address != 0xffffffffffffffff) {
          coruna_persistb080_trampoline_00010c24(address,coruna_return_zero_8000,0x38);
          *(uint8_t **)(address + 0x30) = k_persist_strcmp_slot;
          ptr = k_persist_mach_task_self_slot;
          bootargs = 0;
          err = coruna_mach_vm_protect_fec8(addr_2,*(uint32_t *)k_persist_mach_task_self_slot,address,0x38,5,
                               &bootargs);
          if (err == 0) {
            scratch = 6;
            _mach_vm_machine_attribute(*(vm_map_t *)ptr,address,0x38,1,&scratch);
            u = 0;
            *(mach_vm_address_t *)(handle + 0x48) = address;
            *(uint32_t *)(handle + 0x50) = 0x38;
            *(uint8_t *)(handle + 0x54) = bootargs;
            *arg = address;
          }
          else {
            _munmap(address,0x38);
          }
        }
      }
    }
    else {
      u = 0;
      *arg = *(mach_vm_address_t *)(handle + 0x48);
    }
  }
  return u;
}





unsigned long coruna_vm_protect(uint64_t *arg,uint64_t val)

{
  uint8_t *data;
  uint size;
  uint version;
  unsigned long type_id;
  uint8_t cache_40;
  uint8_t cache_41;
  vm_prot_t cache_93;
  
  data = k_persist_mach_task_self_slot;
  if (arg != (uint64_t *)0x0) {
    type_id = coruna_mach_vm_region_recurse(*(uint32_t *)k_persist_mach_task_self_slot,arg,8,&cache_93,&cache_41
                         ,&cache_40);
    if ((int)type_id == 0) {
      if (((byte)cache_93 >> 1 & 1) == 0) {
        size = _vm_protect(*(vm_map_t *)data,(vm_address_t)arg,8,0,3);
        if (size == 0) {
          *arg = val;
          version = _vm_protect(*(vm_map_t *)data,(vm_address_t)arg,8,0,cache_93);
          size = 0;
          if (version != 0) {
            size = version | 0x80000000;
          }
          type_id = (unsigned long)size;
        }
        else {
          type_id = (unsigned long)(size | 0x80000000);
        }
      }
      else {
        type_id = 0;
        *arg = val;
      }
    }
    return type_id;
  }
  return 0xad001;
}





unsigned long coruna_macho_data_seg(long arg,uint64_t val,pthread_mutex_t *n)

{
  mach_vm_address_t *address;
  uint8_t *data;
  int n;
  uint version;
  char *data;
  unsigned long port;
  byte *obj;
  unsigned long kind;
  mach_vm_address_t address_00;
  uint8_t cache_106;
  unsigned long cache_20;
  unsigned long block_ctx;
  
  kind = 0xad00b;
  if (arg == 0) {
    return 0xad001;
  }
  if (n == (pthread_mutex_t *)0x0) {
    return 0xad001;
  }
  n = _pthread_mutex_lock(n);
  if (n != 0) {
    return 0xad00b;
  }
  if ((char)n[1].__sig != '\0') {
    kind = 0;
    _pthread_mutex_unlock(n);
    return kind;
  }
  n[1].__opaque[0xc] = '\x01';
  n[1].__opaque[0] = '\0';
  n[1].__opaque[1] = '\0';
  n[1].__opaque[2] = '\0';
  n[1].__opaque[3] = '\0';
  n[1].__opaque[4] = '\0';
  n[1].__opaque[5] = '\0';
  n[1].__opaque[6] = '\0';
  n[1].__opaque[7] = '\0';
  n[1].__opaque[8] = '\0';
  n[1].__opaque[9] = '\0';
  n[1].__opaque[10] = '\0';
  n[1].__opaque[0xb] = '\0';
  block_ctx = 0;
  data = _getsectdatafromFramework("libunwind.dylib","__DATA","__bss",&block_ctx);
  _pthread_mutex_unlock(n);
  return kind;
  obj = (byte *)(data + 1);
  if (*obj < 3) {
    port = __NSGetMachExecuteHeader();
    _pthread_mutex_unlock(n);
    return kind;
    address_00 = *(mach_vm_address_t *)n[1].__opaque;
    if (address_00 == 0) {
      block_ctx = (unsigned long)obj & 0xfffffffffffff000;
      cache_20 = port;
      address_00 = _mmap(0,0x78,3,&k_persist_mmap_anon_fd,0xffffffff,0);
      _pthread_mutex_unlock(n);
      return kind;
      coruna_persistb080_trampoline_00010c24(address_00,coruna_pad_stub,0x78);
      *(unsigned long *)(address_00 + 0x68) = block_ctx;
      *(unsigned long *)(address_00 + 0x70) = cache_20;
      data = k_persist_mach_task_self_slot;
      cache_20 = cache_20 & 0xffffffffffffff00;
      n = coruna_mach_vm_protect_fec8(arg,*(uint32_t *)k_persist_mach_task_self_slot,address_00,0x78,5,
                           &cache_20);
      if (n != 0) {
        _munmap(address_00,0x78);
        _pthread_mutex_unlock(n);
        return kind;
      }
      block_ctx = coruna_u64_pack((block_ctx), (6));
      _mach_vm_machine_attribute
                (*(vm_map_t *)data,address_00,0x78,1,(vm_machine_attribute_val_t *)&block_ctx);
      *(mach_vm_address_t *)n[1].__opaque = address_00;
      n[1].__opaque[8] = 'x';
      n[1].__opaque[9] = '\0';
      n[1].__opaque[10] = '\0';
      n[1].__opaque[0xb] = '\0';
      n[1].__opaque[0xc] = (char)cache_20;
    }
    data = k_persist_mach_task_self_slot;
    address = (mach_vm_address_t *)(data + 8);
    kind = 0xad001;
    _pthread_mutex_unlock(n);
    return kind;
    block_ctx = block_ctx & 0xffffffff00000000;
    cache_20 = cache_20 & 0xffffffffffffff00;
    cache_106 = 0;
    kind = coruna_mach_vm_region_recurse(*(uint32_t *)k_persist_mach_task_self_slot,address,8,&block_ctx,&cache_20,
                         &cache_106);
    _pthread_mutex_unlock(n);
    return kind;
    if (((byte)block_ctx >> 1 & 1) == 0) {
      version = _vm_protect(*(vm_map_t *)data,(vm_address_t)address,8,0,3);
      if (version == 0) {
        n = coruna_return_zero();
        if (n != 0) {
          address_00 = coruna_pacia(address_00,0);
        }
        *address = address_00;
        version = _vm_protect(*(vm_map_t *)data,(vm_address_t)address,8,0,(vm_prot_t)block_ctx);
        if (version == 0) goto load_ok_48;
      }
      kind = (unsigned long)(version | 0x80000000);
      _pthread_mutex_unlock(n);
      return kind;
    }
    n = coruna_return_zero();
    if (n != 0) {
      address_00 = coruna_pacia(address_00,0);
    }
    *address = address_00;
load_ok_48:
    *obj = 3;
  }
  *(uint8_t *)&n[1].__sig = 1;
  kind = 0;
load_ok_47:
  _pthread_mutex_unlock(n);
  return kind;
}





uint64_t coruna_helper_17398_1d538(long handle,pthread_mutex_t *arg)
{
  int err;
  uint64_t u;
  
  u = 0xad001;
  if ((handle != 0) && (arg != (pthread_mutex_t *)0x0)) {
    err = _pthread_mutex_lock(arg);
    if (err == 0) {
      if (((char)arg[1].__sig == '\0') || (arg[1].__opaque[0xc] != '\0')) {
        u = 0;
      }
      else if (*(long *)arg[1].__opaque == 0) {
        u = 0;
        arg[1].__opaque[0xc] = '\x01';
      }
      else {
        u = coruna_persistb080_via_persistb080_via_mach_vm_region_recurse(handle,*(uint32_t *)k_persist_mach_task_self_slot,
                             *(long *)arg[1].__opaque,*(uint32_t *)(arg[1].__opaque + 8));
      }
      _pthread_mutex_unlock(arg);
    }
    else {
      u = 0x18013;
    }
  }
  return u;
}





uint64_t coruna_persistb080_via_pthread_rwlock_init(uint64_t *val)
{
  uint64_t u;
  uint32_t *ptr;
  uint64_t scratch;
  
  if (val == (uint64_t *)0x0) {
    u = 0xad001;
  }
  else {
    scratch = 0;
    u = coruna_pthread_rwlock_init(&scratch);
    if ((int)u == 0) {
      ptr = _calloc(1,0x38);
      if (ptr == (uint32_t *)0x0) {
        coruna_pthread_rwlock_destroy(scratch);
        u = 0xad009;
      }
      else {
        u = 0;
        *ptr = 0x10001;
        *(uint64_t *)(ptr + 2) = scratch;
        ((void (**)(void *, long, uint64_t))(ptr + 4))[0] = coruna_pthread_rwlock_unlock_1cbc8;
        ((void (**)(void *, long, uint64_t))(ptr + 6))[0] = coruna_pthread_rwlock_rdlock;
        ((void (**)(void *, long, uint64_t))(ptr + 8))[0] = coruna_pthread_rwlock_rdlock_1cd00;
        ((void (**)(void *, long, uint64_t))(ptr + 10))[0] = coruna_pthread_rwlock_rdlock_1cd7c;
        ((void (**)(void *, long, uint64_t))(ptr + 0xc))[0] = coruna_pthread_rwlock_unlock;
        *val = ptr;
      }
    }
  }
  return u;
}





uint64_t coruna_persistb080_via_persistb080_via_pthread_rwlock_init(long *handle,int *flags,unsigned long arg)
{
  uint64_t u;
  long scratch;
  
  scratch = 0;
  u = 0xad001;
  if (((handle != (long *)0x0) && (flags != (int *)0x0)) && ((uint)arg != 0)) {
    if ((((uint)arg < 9) || (*flags != -0xff24111)) ||
       ((flags[1] == 0 || ((arg & 0xffffffff) <= ((unsigned long)(uint)flags[1] << 4 | 8))))) {
      u = 0x700b;
    }
    else {
      u = coruna_persistb080_via_pthread_rwlock_init(&scratch);
      if ((int)u == 0) {
        u = (**(void (**)(scratch + 0x10))(scratch,flags,arg);
        if ((int)u == 0) {
          *handle = scratch;
        }
        else {
          coruna_ctx_free_1c8fc();
        }
      }
    }
  }
  return u;
}





uint64_t coruna_ctx_free_1c8fc(uint64_t *val)
{
  uint64_t u;
  
  if ((val == (uint64_t *)0x0) || (val[1] == 0)) {
    u = 0xad001;
  }
  else {
    u = coruna_pthread_rwlock_destroy();
    val[1] = 0;
    *val = 0;
    val[3] = 0;
    val[2] = 0;
    val[5] = 0;
    val[4] = 0;
    val[6] = 0;
    _free(val);
  }
  return u;
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
            size = coruna_ipc_resolve_entry(ptr,ptr,addr_2,off_3);
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
      u = coruna_bzero_4(ptr,addr_2,off_3);
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
        size = coruna_ipc_resolve_entry(ptr,ptr,&bootargs,&scratch);
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





uint64_t coruna_pthread_rwlock_unlock(long handle,uint64_t val,long addr_2,uint size)
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
    if (((ptr != (pthread_rwlock_t *)0x0 && (uint)val != 0) && addr_2 != 0) && size != 0)
    {
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
                coruna_persistb080_trampoline_00010c24(ptr,addr_2,(unsigned long)size);
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
                  size = coruna_bzero_4(ptr,&bootargs,&scratch);
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





uint64_t coruna_ipc_resolve_entry(long handle,long addr_2,long *off_3,uint32_t *size)
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
  int *count;
  int idx;
  uint type_id;
  unsigned long port;
  unsigned long tag;
  long serial_8;
  unsigned long type_id_8;
  int *i;
  uint *entry_10;
  unsigned long type_id_12;
  uint *entry_11;
  uint action;
  void *block_ctx;
  
  if (((arg == 0) || (n == (int *)0x0)) || (m == 0)) {
load_ok_49:
    port = 0xad001;
  }
  else {
    if ((7 < m) && (*n == -0xff24111)) {
      type_id = n[1];
      if ((type_id != 0) && (port = (unsigned long)type_id << 4 | 8, port <= m)) {
        idx = *(int *)(arg + 0xe8);
        if ((uint)(*(int *)(arg + 0xe4) - idx) < type_id) {
          return 0xad009;
        }
        type_id_8 = 0;
        do {
          count = n + type_id_8 * 4 + 2;
          if (*count == 0) {
            return 0x700c;
          }
          entry_11 = (uint *)(count + 2);
          type_id = *entry_11;
          if (type_id < (uint)port) {
            return 0x700c;
          }
          entry_10 = (uint *)(n + type_id_8 * 4 + 5);
          if (*entry_10 == 0) {
            return 0x700c;
          }
          u = *entry_10 + type_id;
          if (u <= type_id || m < u) {
            return 0x700c;
          }
          type_id_12 = 0xffffffffffffffff;
          i = (int *)(arg + 0xf0);
          do {
            type_id = *(uint *)(arg + 0xe8);
            type_id_12 = type_id_12 + 1;
            if (type_id <= type_id_12) {
              if (val == 2) {
                tag = (unsigned long)(uint)(idx + (int)type_id_8);
                serial_8 = arg + tag * 0x20;
                *(uint64_t *)(serial_8 + 0xf0) = *(uint64_t *)count;
                *(uint8_t *)(serial_8 + 0xf8) = 2;
                type_id_12 = (long)n + (unsigned long)*entry_11;
              }
              else {
                if (val != 1) goto load_ok_49;
                tag = (unsigned long)(uint)(idx + (int)type_id_8);
                serial_8 = arg + tag * 0x20;
                *(uint64_t *)(serial_8 + 0xf0) = *(uint64_t *)count;
                *(uint8_t *)(serial_8 + 0xf8) = 1;
                type_id_12 = (unsigned long)*entry_11;
              }
              *(unsigned long *)(serial_8 + 0x100) = type_id_12;
              *(uint *)(arg + tag * 0x20 + 0x108) = *entry_10;
              *(uint *)(arg + 0xe8) = type_id + 1;
              goto load_ok_50;
            }
            if (*count == *i) {
              block_ctx = (void *)0x0;
              action = 0;
              tag = coruna_ipc_resolve_entry(arg,i,&block_ctx,&action);
              if ((int)tag == 0) {
                if (block_ctx == (void *)((long)n + (unsigned long)*entry_11) && action == *entry_10) {
                  tag = 0;
                }
                else {
                  if (action == *entry_10) {
                    type_id = _memcmp(block_ctx,(void *)((long)n + (unsigned long)*entry_11),
                                    (unsigned long)action);
                    tag = (unsigned long)type_id;
                    i = i + 8;
                    } while ((int)tag == 0x7003);
                    if ((int)tag != 0) {
                    return tag;
                  }
                  tag = 0x700a;
                }
              }
            }
            else {
              tag = 0x7003;
            }
load_ok_51:
            i = i + 8;
          } while ((int)tag == 0x7003);
          if ((int)tag != 0) {
            return tag;
          }
load_ok_50:
          type_id_8 = type_id_8 + 1;
          if ((uint)n[1] <= type_id_8) {
            return 0;
          }
        } while( true );
      }
    }
    port = 0x700b;
  }
  return port;
}





uint64_t coruna_bzero_4(long handle,uint64_t *val,uint *size)
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
  int *err;
  int scratch;
  uint64_t bootargs;
  
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
        bootargs = 0;
        scratch = 0;
        version = coruna_ipc_resolve_entry(handle,handle,&bootargs,&scratch);
        if ((int)version != 0) {
          return version;
        }
        port = port + 1;
        u = (scratch + 0x1fU & 0xffffffe0) + (int)size;
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
          err = ptr + 5;
          buf = (uint64_t *)(handle + 0xf0);
          do {
            bootargs = 0;
            scratch = 0;
            version = coruna_ipc_resolve_entry(handle,buf,&bootargs,&scratch);
            if ((int)version != 0) {
              _bzero(ptr,size);
              _free(ptr);
              return version;
            }
            err[-1] = (int)tag;
            *err = scratch;
            *(uint64_t *)(err + -3) = *buf;
            coruna_persistb080_trampoline_00010c24((long)ptr + tag,bootargs);
            tag = (unsigned long)((scratch + 0x1fU & 0xffffffe0) + (int)tag);
            port = port + 1;
            err = err + 4;
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

