/* Function: dlerror @ 00010bf8 */

void dlerror(void)

{
  (*(code *)PTR_dlerror_00013fdc)();
  return;
}



/* Function: dlopen @ 00010c04 */

void dlopen(void)

{
  (*(code *)PTR_dlopen_00013fe0)();
  return;
}



/* Function: dlsym @ 00010c10 */

void dlsym(void)

{
  (*(code *)PTR_dlsym_00013fe4)();
  return;
}



/* Function: __android_log_print @ 00010c1c */

void __android_log_print(void)

{
  (*(code *)PTR___android_log_print_00013fe8)();
  return;
}



/* Function: __gnu_Unwind_Find_exidx @ 00010c28 */

void __gnu_Unwind_Find_exidx(void)

{
  (*(code *)PTR___gnu_Unwind_Find_exidx_00013fec)();
  return;
}



/* Function: memcpy @ 00010c34 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memcpy_00013ff0)(__dest);
  return pvVar1;
}



/* Function: abort @ 00010c40 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
  (*(code *)PTR_abort_00013ff4)();
  return;
}



/* Function: __cxa_begin_cleanup @ 00010c4c */

void __cxa_begin_cleanup(void)

{
  (*(code *)PTR___cxa_begin_cleanup_00013ff8)();
  return;
}



/* Function: __cxa_type_match @ 00010c58 */

void __cxa_type_match(void)

{
  (*(code *)PTR___cxa_type_match_00013ffc)();
  return;
}



/* Function: _FINI_0 @ 00010c78 */

void _FINI_0(void)

{
  (*(code *)PTR___cxa_finalize_00013fd8)((int)&DAT_00010c84 + DAT_00010c84);
  return;
}



/* Function: kick @ 00010c88 */

undefined4 kick(undefined4 param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  dlerror();
  iVar1 = dlopen(DAT_00010cec + 0x10c98,0);
  if ((iVar1 == 0) || (iVar1 = dlopen(DAT_00010cf0 + 0x10ca6,0), iVar1 == 0)) {
    uVar3 = 0;
    dlerror();
  }
  else {
    pcVar2 = (code *)dlsym(iVar1,DAT_00010cf4 + 0x10cba);
    **(undefined4 **)(DAT_00010cf8 + 0x10cc4) = pcVar2;
    if (pcVar2 == (code *)0x0) {
      uVar3 = dlerror();
      __android_log_print(3,DAT_00010cfc + 0x10ce0,DAT_00010d00 + 0x10ce2,uVar3);
      uVar3 = 0;
    }
    else {
      (*pcVar2)(param_1);
      uVar3 = 1;
    }
  }
  return uVar3;
}



/* Function: FUN_00010d04 @ 00010d04 */

int FUN_00010d04(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if ((uVar1 & 0x40000000) == 0) {
    uVar1 = uVar1 & 0x7fffffff;
  }
  else {
    uVar1 = uVar1 | 0x80000000;
  }
  return (int)param_1 + uVar1;
}



/* Function: FUN_00010d1c @ 00010d1c */

undefined4 FUN_00010d1c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  bool bVar13;
  int local_2c [2];
  
  iVar8 = DAT_00010ed4 + 0x10d30;
  uVar9 = param_2 - 2;
  if (*(int *)(iVar8 + DAT_00010ed8) == 0) {
    iVar2 = *(int *)(iVar8 + DAT_00010ee0);
    local_2c[0] = *(int *)(iVar8 + DAT_00010edc) - iVar2 >> 3;
LAB_00010d78:
    if (local_2c[0] != 0) {
      iVar7 = local_2c[0] + -1;
      iVar11 = 0;
      iVar12 = iVar7;
      while( true ) {
        while( true ) {
          iVar1 = (iVar11 + iVar12) / 2;
          iVar10 = iVar2 + iVar1 * 8;
          uVar3 = FUN_00010d04(iVar10);
          if (iVar1 == iVar7) {
            uVar4 = 0xffffffff;
          }
          else {
            iVar5 = FUN_00010d04(iVar2 + (iVar1 + 1) * 8);
            uVar4 = iVar5 - 1;
          }
          if (uVar3 <= uVar9) break;
          if (iVar1 == iVar11) goto LAB_00010e0c;
          iVar12 = iVar1 + -1;
        }
        if (uVar9 <= uVar4) break;
        iVar11 = iVar1 + 1;
      }
      if (iVar10 != 0) {
        uVar6 = FUN_00010d04(iVar10);
        iVar2 = *(int *)(iVar10 + 4);
        bVar13 = iVar2 == 1;
        if (bVar13) {
          iVar2 = 0;
          *(undefined4 *)(param_1 + 0x10) = 0;
        }
        *(undefined4 *)(param_1 + 0x48) = uVar6;
        if (bVar13) {
          return 5;
        }
        if (iVar2 < 0) {
          *(int *)(param_1 + 0x4c) = iVar10 + 4;
        }
        else {
          uVar6 = FUN_00010d04();
          *(undefined4 *)(param_1 + 0x4c) = uVar6;
        }
        *(uint *)(param_1 + 0x50) = (uint)(iVar2 < 0);
        if (-1 < (int)**(uint **)(param_1 + 0x4c)) {
          uVar6 = FUN_00010d04();
          *(undefined4 *)(param_1 + 0x10) = uVar6;
          return 0;
        }
        uVar9 = **(uint **)(param_1 + 0x4c) >> 0x18 & 0xf;
        if (uVar9 == 0) {
          *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar8 + DAT_00010ee4);
          return 0;
        }
        iVar2 = DAT_00010ee8;
        if ((uVar9 == 1) || (iVar2 = DAT_00010eec, uVar9 == 2)) {
          *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar8 + iVar2);
          return 0;
        }
        goto LAB_00010eb8;
      }
    }
LAB_00010e0c:
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  else {
    iVar2 = __gnu_Unwind_Find_exidx(uVar9,local_2c);
    if (iVar2 != 0) goto LAB_00010d78;
LAB_00010eb8:
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return 9;
}



/* Function: FUN_00010ef0 @ 00010ef0 */

void FUN_00010ef0(uint *param_1)

{
  if ((*param_1 & 1) == 0) {
    if ((*param_1 & 2) == 0) {
      __gnu_Unwind_Restore_VFP(param_1 + 0x12);
    }
    else {
      __gnu_Unwind_Restore_VFP_D();
    }
  }
  if ((*param_1 & 4) == 0) {
    __gnu_Unwind_Restore_VFP_D_16_to_31(param_1 + 0x34);
  }
  if ((*param_1 & 8) == 0) {
    __gnu_Unwind_Restore_WMMXD(param_1 + 0x6c);
  }
  if ((*param_1 & 0x10) != 0) {
    return;
  }
  __gnu_Unwind_Restore_WMMXC(param_1 + 0x8c);
  return;
}



/* Function: FUN_00010f5c @ 00010f5c */

int FUN_00010f5c(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 local_4a0;
  undefined4 local_49c;
  undefined4 uStack_498;
  undefined4 uStack_494;
  undefined4 uStack_490;
  undefined4 local_48c;
  undefined4 uStack_488;
  undefined4 uStack_484;
  undefined4 uStack_480;
  undefined4 local_47c;
  undefined4 uStack_478;
  undefined4 uStack_474;
  undefined4 uStack_470;
  undefined4 local_46c;
  undefined4 local_468;
  undefined4 uStack_464;
  undefined4 local_460;
  undefined4 local_45c;
  undefined1 auStack_260 [56];
  undefined4 local_228;
  
  pcVar4 = *(code **)(param_1 + 0xc);
  uVar5 = *(undefined4 *)(param_1 + 0x18);
  local_49c = *(undefined4 *)(param_2 + 4);
  uStack_498 = *(undefined4 *)(param_2 + 8);
  uStack_494 = *(undefined4 *)(param_2 + 0xc);
  uStack_490 = *(undefined4 *)(param_2 + 0x10);
  local_48c = *(undefined4 *)(param_2 + 0x14);
  uStack_488 = *(undefined4 *)(param_2 + 0x18);
  uStack_484 = *(undefined4 *)(param_2 + 0x1c);
  uStack_480 = *(undefined4 *)(param_2 + 0x20);
  local_47c = *(undefined4 *)(param_2 + 0x24);
  uStack_478 = *(undefined4 *)(param_2 + 0x28);
  uStack_474 = *(undefined4 *)(param_2 + 0x2c);
  uStack_470 = *(undefined4 *)(param_2 + 0x30);
  local_46c = *(undefined4 *)(param_2 + 0x34);
  local_468 = *(undefined4 *)(param_2 + 0x38);
  uStack_464 = *(undefined4 *)(param_2 + 0x3c);
  local_460 = *(undefined4 *)(param_2 + 0x40);
  iVar3 = 0;
  local_4a0 = 0;
  do {
    iVar1 = FUN_00010d1c(param_1,local_460);
    if (param_3 == 0) {
      uVar6 = 9;
    }
    else {
      uVar6 = 10;
    }
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x14) = local_460;
      memcpy(auStack_260,&local_4a0,0x240);
      iVar3 = (**(code **)(param_1 + 0x10))(uVar6,param_1,auStack_260);
      local_45c = local_228;
    }
    else {
      uVar6 = uVar6 | 0x10;
      local_45c = local_468;
    }
    iVar2 = (*pcVar4)(1,uVar6,param_1,param_1,&local_4a0,uVar5);
    if (iVar2 != 0) {
      return 9;
    }
    if (iVar1 != 0) {
      return iVar1;
    }
    memcpy(&local_4a0,auStack_260,0x240);
    param_3 = 0;
  } while (iVar3 == 8);
  if (iVar3 == 7) {
    restore_core_regs(&local_49c);
  }
  return 9;
}



/* Function: FUN_00011070 @ 00011070 */

undefined4 FUN_00011070(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint extraout_r2;
  int extraout_r3;
  bool bVar3;
  ulonglong uVar4;
  
  do {
    iVar1 = FUN_00010d1c(param_1,*(undefined4 *)(param_2 + 0x40));
    if (iVar1 != 0) goto LAB_000110bc;
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_2 + 0x40);
    iVar1 = (**(code **)(param_1 + 0x10))(1,param_1,param_2);
  } while (iVar1 == 8);
  if (iVar1 == 7) {
    uVar4 = restore_core_regs(param_2 + 4);
    if ((int)(uVar4 >> 0x20) == 0) {
      bVar3 = extraout_r2 == 0xf;
      if (extraout_r2 < 0x10) {
        bVar3 = extraout_r3 == 0;
      }
      if (bVar3) {
        uVar2 = 0;
        *param_4 = *(undefined4 *)((int)uVar4 + extraout_r2 * 4 + 4);
      }
      else {
        uVar2 = 2;
      }
      return uVar2;
    }
    if (uVar4 < 0x500000000) {
      uVar2 = 1;
    }
    else {
      uVar2 = 2;
    }
    return uVar2;
  }
LAB_000110bc:
                    /* WARNING: Subroutine does not return */
  abort();
}



/* Function: _Unwind_VRS_Get @ 000110c8 */

undefined4 _Unwind_VRS_Get(int param_1,uint param_2,uint param_3,int param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  bool bVar2;
  
  if (param_2 == 0) {
    bVar2 = param_3 == 0xf;
    if (param_3 < 0x10) {
      bVar2 = param_4 == 0;
    }
    if (bVar2) {
      uVar1 = 0;
      *param_5 = *(undefined4 *)(param_1 + param_3 * 4 + 4);
    }
    else {
      uVar1 = 2;
    }
    return uVar1;
  }
  if (param_2 < 5) {
    uVar1 = 1;
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}



/* Function: FUN_0001110c @ 0001110c */

undefined4 FUN_0001110c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_c;
  
  local_c = param_4;
  _Unwind_VRS_Get(param_1,0,param_2,0,&local_c,param_2,param_3);
  return local_c;
}



/* Function: _Unwind_VRS_Set @ 00011134 */

undefined4 _Unwind_VRS_Set(int param_1,uint param_2,uint param_3,int param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  bool bVar2;
  
  if (param_2 == 0) {
    bVar2 = param_3 == 0xf;
    if (param_3 < 0x10) {
      bVar2 = param_4 == 0;
    }
    if (bVar2) {
      uVar1 = 0;
      *(undefined4 *)(param_1 + param_3 * 4 + 4) = *param_5;
    }
    else {
      uVar1 = 2;
    }
    return uVar1;
  }
  if (param_2 < 5) {
    uVar1 = 1;
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}



/* Function: FUN_00011178 @ 00011178 */

void FUN_00011178(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_c;
  
  local_c = param_3;
  _Unwind_VRS_Set(param_1,0,param_2,0,&local_c,param_2,param_3);
  return;
}



/* Function: __aeabi_unwind_cpp_pr2 @ 00011538 */

/* WARNING: Removing unreachable block (ram,0x000111d8) */
/* WARNING: Removing unreachable block (ram,0x0001123c) */

undefined4 __aeabi_unwind_cpp_pr2(uint param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  int iVar12;
  uint uVar13;
  uint *puVar14;
  int iStack_38;
  int iStack_34;
  uint *puStack_30;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  
  puStack_30 = *(uint **)(param_2 + 0x4c) + 1;
  uVar7 = **(uint **)(param_2 + 0x4c);
  uVar10 = param_1 & 3;
  iStack_34 = uVar7 << 0x10;
  puVar8 = puStack_30 + (uVar7 >> 0x10 & 0xff);
  uStack_2b = (undefined1)(uVar7 >> 0x10);
  uStack_2c = 2;
  if (uVar10 == 2) {
    puVar8 = *(uint **)(param_2 + 0x38);
  }
  if ((*(uint *)(param_2 + 0x50) & 1) == 0) {
    iVar5 = param_2 + 0x58;
    bVar11 = false;
LAB_000114c4:
    do {
      while( true ) {
        uVar7 = *puVar8;
        if (uVar7 == 0) goto LAB_000114d0;
        uVar13 = puVar8[1];
        puVar4 = puVar8 + 2;
        uVar9 = (uVar13 & 0xfffffffe) + *(int *)(param_2 + 0x48);
        uVar2 = FUN_0001110c(param_3,0xf);
        if (uVar2 < uVar9) {
          bVar1 = false;
        }
        else if (uVar2 < uVar9 + (uVar7 & 0xfffffffe)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        uVar7 = uVar7 & 1 | (uVar13 & 1) << 1;
        if (uVar7 != 1) break;
        if (uVar10 == 0) {
          if (bVar1) {
            uVar7 = puVar8[3];
            if (uVar7 == 0xfffffffe) {
              return 9;
            }
            iStack_38 = iVar5;
            if (uVar7 != 0xffffffff) {
              if (uVar7 == 0) {
                uVar6 = 0;
              }
              else {
                uVar6 = *(undefined4 *)((int)puVar4 + uVar7 + 4);
              }
              iVar3 = __cxa_type_match(param_2,uVar6,*puVar4 >> 0x1f,&iStack_38);
              if (iVar3 == 0) {
                iStack_38 = 0;
              }
            }
            if (iStack_38 != 0) {
LAB_00011404:
              uVar6 = FUN_0001110c(param_3,0xd);
              *(int *)(param_2 + 0x24) = iStack_38;
              *(uint **)(param_2 + 0x28) = puVar4;
              *(undefined4 *)(param_2 + 0x20) = uVar6;
              return 6;
            }
          }
        }
        else {
          iVar12 = *(int *)(param_2 + 0x20);
          iVar3 = FUN_0001110c(param_3,0xd);
          if ((iVar12 == iVar3) && (puVar4 == *(uint **)(param_2 + 0x28))) {
LAB_0001147c:
            uVar6 = FUN_00010d04(puVar4);
            FUN_00011178(param_3,0xf,uVar6);
            uVar6 = 0;
            goto LAB_0001151c;
          }
        }
        puVar8 = puVar8 + 4;
      }
      if (uVar7 != 0) {
        if (uVar7 != 2) {
          return 9;
        }
        uVar7 = *puVar4 & 0x7fffffff;
        if (uVar10 == 0) {
          if ((bVar1) && ((param_1 & 8) == 0 || uVar7 == 0)) {
            uVar2 = 0;
            puVar14 = puVar4;
            do {
              uVar9 = uVar2;
              if (uVar9 == uVar7) goto LAB_00011404;
              puVar14 = puVar14 + 1;
              uVar6 = 0;
              if (*puVar14 != 0) {
                uVar6 = *(undefined4 *)(*puVar14 + (int)puVar14);
              }
              iStack_38 = iVar5;
              iVar3 = __cxa_type_match(param_2,uVar6,0,&iStack_38);
              uVar2 = uVar9 + 1;
            } while (iVar3 == 0);
            if (uVar9 == uVar7) goto LAB_00011404;
          }
        }
        else {
          iVar12 = *(int *)(param_2 + 0x20);
          iVar3 = FUN_0001110c(param_3,0xd);
          if ((iVar12 == iVar3) && (puVar4 == *(uint **)(param_2 + 0x28))) {
            *(undefined4 *)(param_2 + 0x30) = 4;
            *(uint *)(param_2 + 0x28) = uVar7;
            *(undefined4 *)(param_2 + 0x2c) = 0;
            *(uint **)(param_2 + 0x34) = puVar8 + 3;
            if (-1 < (int)*puVar4) {
              puVar4 = puVar4 + uVar7 + 1;
              goto LAB_0001147c;
            }
            bVar11 = true;
          }
        }
        if ((int)*puVar4 < 0) {
          puVar4 = puVar8 + 3;
        }
        puVar8 = puVar4 + uVar7 + 1;
        goto LAB_000114c4;
      }
      if (uVar10 == 0) {
        bVar1 = false;
      }
      puVar8 = puVar8 + 3;
    } while (!bVar1);
    FUN_00010d04(puVar4);
    *(uint **)(param_2 + 0x38) = puVar8;
    iVar5 = __cxa_begin_cleanup(param_2);
    if (iVar5 == 0) {
      return 9;
    }
    uVar6 = 0xf;
  }
  else {
    bVar11 = false;
LAB_000114d0:
    iVar5 = __gnu_unwind_execute(param_3,&iStack_34);
    if (iVar5 != 0) {
      return 9;
    }
    if (!bVar11) {
      return 8;
    }
    uVar6 = FUN_0001110c(param_3,0xf);
    FUN_00011178(param_3,0xe,uVar6);
    uVar6 = 0xf;
  }
LAB_0001151c:
  FUN_00011178(param_3,uVar6);
  return 7;
}



/* Function: __aeabi_unwind_cpp_pr1 @ 00011540 */

/* WARNING: Removing unreachable block (ram,0x000111d8) */
/* WARNING: Removing unreachable block (ram,0x00011238) */

undefined4 __aeabi_unwind_cpp_pr1(uint param_1,int param_2,undefined4 param_3)

{
  ushort uVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  int iVar13;
  uint *puVar14;
  int iStack_38;
  int iStack_34;
  uint *puStack_30;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  
  puStack_30 = *(uint **)(param_2 + 0x4c) + 1;
  uVar8 = **(uint **)(param_2 + 0x4c);
  uVar11 = param_1 & 3;
  iStack_34 = uVar8 << 0x10;
  puVar9 = puStack_30 + (uVar8 >> 0x10 & 0xff);
  uStack_2b = (undefined1)(uVar8 >> 0x10);
  uStack_2c = 2;
  if (uVar11 == 2) {
    puVar9 = *(uint **)(param_2 + 0x38);
  }
  if ((*(uint *)(param_2 + 0x50) & 1) == 0) {
    iVar6 = param_2 + 0x58;
    bVar12 = false;
LAB_000114c4:
    do {
      while( true ) {
        if (*puVar9 == 0) goto LAB_000114d0;
        uVar1 = *(ushort *)((int)puVar9 + 2);
        uVar8 = *puVar9;
        puVar5 = puVar9 + 1;
        uVar10 = (uVar1 & 0xfffffffe) + *(int *)(param_2 + 0x48);
        uVar3 = FUN_0001110c(param_3,0xf);
        if (uVar3 < uVar10) {
          bVar2 = false;
        }
        else if (uVar3 < uVar10 + ((ushort)uVar8 & 0xfffffffe)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        uVar8 = (ushort)uVar8 & 1 | (uVar1 & 1) << 1;
        if (uVar8 != 1) break;
        if (uVar11 == 0) {
          if (bVar2) {
            uVar8 = puVar9[2];
            if (uVar8 == 0xfffffffe) {
              return 9;
            }
            iStack_38 = iVar6;
            if (uVar8 != 0xffffffff) {
              if (uVar8 == 0) {
                uVar7 = 0;
              }
              else {
                uVar7 = *(undefined4 *)((int)puVar5 + uVar8 + 4);
              }
              iVar4 = __cxa_type_match(param_2,uVar7,*puVar5 >> 0x1f,&iStack_38);
              if (iVar4 == 0) {
                iStack_38 = 0;
              }
            }
            if (iStack_38 != 0) {
LAB_00011404:
              uVar7 = FUN_0001110c(param_3,0xd);
              *(int *)(param_2 + 0x24) = iStack_38;
              *(uint **)(param_2 + 0x28) = puVar5;
              *(undefined4 *)(param_2 + 0x20) = uVar7;
              return 6;
            }
          }
        }
        else {
          iVar13 = *(int *)(param_2 + 0x20);
          iVar4 = FUN_0001110c(param_3,0xd);
          if ((iVar13 == iVar4) && (puVar5 == *(uint **)(param_2 + 0x28))) {
LAB_0001147c:
            uVar7 = FUN_00010d04(puVar5);
            FUN_00011178(param_3,0xf,uVar7);
            uVar7 = 0;
            goto LAB_0001151c;
          }
        }
        puVar9 = puVar9 + 3;
      }
      if (uVar8 != 0) {
        if (uVar8 != 2) {
          return 9;
        }
        uVar8 = *puVar5 & 0x7fffffff;
        if (uVar11 == 0) {
          if ((bVar2) && ((param_1 & 8) == 0 || uVar8 == 0)) {
            uVar3 = 0;
            puVar14 = puVar5;
            do {
              uVar10 = uVar3;
              if (uVar10 == uVar8) goto LAB_00011404;
              puVar14 = puVar14 + 1;
              uVar7 = 0;
              if (*puVar14 != 0) {
                uVar7 = *(undefined4 *)(*puVar14 + (int)puVar14);
              }
              iStack_38 = iVar6;
              iVar4 = __cxa_type_match(param_2,uVar7,0,&iStack_38);
              uVar3 = uVar10 + 1;
            } while (iVar4 == 0);
            if (uVar10 == uVar8) goto LAB_00011404;
          }
        }
        else {
          iVar13 = *(int *)(param_2 + 0x20);
          iVar4 = FUN_0001110c(param_3,0xd);
          if ((iVar13 == iVar4) && (puVar5 == *(uint **)(param_2 + 0x28))) {
            *(undefined4 *)(param_2 + 0x30) = 4;
            *(uint *)(param_2 + 0x28) = uVar8;
            *(undefined4 *)(param_2 + 0x2c) = 0;
            *(uint **)(param_2 + 0x34) = puVar9 + 2;
            if (-1 < (int)*puVar5) {
              puVar5 = puVar5 + uVar8 + 1;
              goto LAB_0001147c;
            }
            bVar12 = true;
          }
        }
        if ((int)*puVar5 < 0) {
          puVar5 = puVar9 + 2;
        }
        puVar9 = puVar5 + uVar8 + 1;
        goto LAB_000114c4;
      }
      if (uVar11 == 0) {
        bVar2 = false;
      }
      puVar9 = puVar9 + 2;
    } while (!bVar2);
    FUN_00010d04(puVar5);
    *(uint **)(param_2 + 0x38) = puVar9;
    iVar6 = __cxa_begin_cleanup(param_2);
    if (iVar6 == 0) {
      return 9;
    }
    uVar7 = 0xf;
  }
  else {
    bVar12 = false;
LAB_000114d0:
    iVar6 = __gnu_unwind_execute(param_3,&iStack_34);
    if (iVar6 != 0) {
      return 9;
    }
    if (!bVar12) {
      return 8;
    }
    uVar7 = FUN_0001110c(param_3,0xf);
    FUN_00011178(param_3,0xe,uVar7);
    uVar7 = 0xf;
  }
LAB_0001151c:
  FUN_00011178(param_3,uVar7);
  return 7;
}



/* Function: __aeabi_unwind_cpp_pr0 @ 00011548 */

/* WARNING: Removing unreachable block (ram,0x000111f0) */
/* WARNING: Removing unreachable block (ram,0x00011238) */

undefined4 __aeabi_unwind_cpp_pr0(uint param_1,int param_2,undefined4 param_3)

{
  ushort uVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  undefined4 uVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  uint uVar12;
  int iVar13;
  uint *puVar14;
  int local_38;
  int local_34;
  uint *local_30;
  undefined1 local_2c;
  undefined1 local_2b;
  
  local_30 = (uint *)(*(int **)(param_2 + 0x4c) + 1);
  uVar10 = param_1 & 3;
  local_34 = **(int **)(param_2 + 0x4c) << 8;
  local_2b = 0;
  local_2c = 3;
  puVar8 = local_30;
  if (uVar10 == 2) {
    puVar8 = *(uint **)(param_2 + 0x38);
  }
  if ((*(uint *)(param_2 + 0x50) & 1) == 0) {
    iVar6 = param_2 + 0x58;
    bVar11 = false;
LAB_000114c4:
    do {
      while( true ) {
        if (*puVar8 == 0) goto LAB_000114d0;
        uVar1 = *(ushort *)((int)puVar8 + 2);
        uVar12 = *puVar8;
        puVar5 = puVar8 + 1;
        uVar9 = (uVar1 & 0xfffffffe) + *(int *)(param_2 + 0x48);
        uVar3 = FUN_0001110c(param_3,0xf);
        if (uVar3 < uVar9) {
          bVar2 = false;
        }
        else if (uVar3 < uVar9 + ((ushort)uVar12 & 0xfffffffe)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        uVar12 = (ushort)uVar12 & 1 | (uVar1 & 1) << 1;
        if (uVar12 != 1) break;
        if (uVar10 == 0) {
          if (bVar2) {
            uVar12 = puVar8[2];
            if (uVar12 == 0xfffffffe) {
              return 9;
            }
            local_38 = iVar6;
            if (uVar12 != 0xffffffff) {
              if (uVar12 == 0) {
                uVar7 = 0;
              }
              else {
                uVar7 = *(undefined4 *)((int)puVar5 + uVar12 + 4);
              }
              iVar4 = __cxa_type_match(param_2,uVar7,*puVar5 >> 0x1f,&local_38);
              if (iVar4 == 0) {
                local_38 = 0;
              }
            }
            if (local_38 != 0) {
LAB_00011404:
              uVar7 = FUN_0001110c(param_3,0xd);
              *(int *)(param_2 + 0x24) = local_38;
              *(uint **)(param_2 + 0x28) = puVar5;
              *(undefined4 *)(param_2 + 0x20) = uVar7;
              return 6;
            }
          }
        }
        else {
          iVar13 = *(int *)(param_2 + 0x20);
          iVar4 = FUN_0001110c(param_3,0xd);
          if ((iVar13 == iVar4) && (puVar5 == *(uint **)(param_2 + 0x28))) {
LAB_0001147c:
            uVar7 = FUN_00010d04(puVar5);
            FUN_00011178(param_3,0xf,uVar7);
            uVar7 = 0;
            goto LAB_0001151c;
          }
        }
        puVar8 = puVar8 + 3;
      }
      if (uVar12 != 0) {
        if (uVar12 != 2) {
          return 9;
        }
        uVar12 = *puVar5 & 0x7fffffff;
        if (uVar10 == 0) {
          if ((bVar2) && ((param_1 & 8) == 0 || uVar12 == 0)) {
            uVar3 = 0;
            puVar14 = puVar5;
            do {
              uVar9 = uVar3;
              if (uVar9 == uVar12) goto LAB_00011404;
              puVar14 = puVar14 + 1;
              uVar7 = 0;
              if (*puVar14 != 0) {
                uVar7 = *(undefined4 *)(*puVar14 + (int)puVar14);
              }
              local_38 = iVar6;
              iVar4 = __cxa_type_match(param_2,uVar7,0,&local_38);
              uVar3 = uVar9 + 1;
            } while (iVar4 == 0);
            if (uVar9 == uVar12) goto LAB_00011404;
          }
        }
        else {
          iVar13 = *(int *)(param_2 + 0x20);
          iVar4 = FUN_0001110c(param_3,0xd);
          if ((iVar13 == iVar4) && (puVar5 == *(uint **)(param_2 + 0x28))) {
            *(undefined4 *)(param_2 + 0x30) = 4;
            *(uint *)(param_2 + 0x28) = uVar12;
            *(undefined4 *)(param_2 + 0x2c) = 0;
            *(uint **)(param_2 + 0x34) = puVar8 + 2;
            if (-1 < (int)*puVar5) {
              puVar5 = puVar5 + uVar12 + 1;
              goto LAB_0001147c;
            }
            bVar11 = true;
          }
        }
        if ((int)*puVar5 < 0) {
          puVar5 = puVar8 + 2;
        }
        puVar8 = puVar5 + uVar12 + 1;
        goto LAB_000114c4;
      }
      if (uVar10 == 0) {
        bVar2 = false;
      }
      puVar8 = puVar8 + 2;
    } while (!bVar2);
    FUN_00010d04(puVar5);
    *(uint **)(param_2 + 0x38) = puVar8;
    iVar6 = __cxa_begin_cleanup(param_2);
    if (iVar6 == 0) {
      return 9;
    }
    uVar7 = 0xf;
  }
  else {
    bVar11 = false;
LAB_000114d0:
    iVar6 = __gnu_unwind_execute(param_3,&local_34);
    if (iVar6 != 0) {
      return 9;
    }
    if (!bVar11) {
      return 8;
    }
    uVar7 = FUN_0001110c(param_3,0xf);
    FUN_00011178(param_3,0xe,uVar7);
    uVar7 = 0xf;
  }
LAB_0001151c:
  FUN_00011178(param_3,uVar7);
  return 7;
}



/* Function: _Unwind_VRS_Pop @ 00011550 */

undefined4 _Unwind_VRS_Pop(uint *param_1,undefined4 param_2,uint param_3,int param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  undefined4 auStack_228 [28];
  undefined4 local_1b8 [4];
  undefined1 auStack_1a8 [128];
  undefined4 auStack_128 [32];
  undefined4 auStack_a8 [35];
  
  switch(param_2) {
  case 0:
    if (param_4 != 0) {
      return 2;
    }
    puVar3 = (uint *)param_1[0xe];
    uVar7 = 0;
    do {
      if ((param_3 & 0xffff & 1 << (uVar7 & 0xff)) != 0) {
        param_1[uVar7 + 1] = *puVar3;
        puVar3 = puVar3 + 1;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 != 0x10);
    if ((param_3 & 0x2000) != 0) {
      return 0;
    }
    param_1[0xe] = (uint)puVar3;
    return 0;
  case 1:
    if (param_4 != 1 && param_4 != 5) {
      return 2;
    }
    uVar7 = param_3 >> 0x10;
    param_3 = param_3 & 0xffff;
    uVar4 = param_3 + uVar7;
    if (param_4 == 1) {
      uVar1 = 0x10;
    }
    else {
      uVar1 = 0x20;
    }
    if (uVar1 < uVar4) {
      return 2;
    }
    bVar10 = param_4 == 1;
    if (uVar7 >= 0x10 && bVar10) {
      return 2;
    }
    uVar1 = param_3;
    if ((uVar7 < 0x10) && (uVar1 = 0, 0x10 < uVar4)) {
      uVar1 = uVar4 - 0x10;
    }
    bVar9 = uVar1 != 0;
    if (bVar9 && param_4 != 5) {
      return 2;
    }
    if ((uVar7 < 0x10) && (uVar4 = *param_1, (uVar4 & 1) != 0)) {
      *param_1 = uVar4 & 0xfffffffe;
      if (param_4 == 5) {
        *param_1 = uVar4 & 0xfffffffe | 2;
        __gnu_Unwind_Save_VFP_D();
      }
      else {
        *param_1 = uVar4 & 0xfffffffc;
        __gnu_Unwind_Save_VFP(param_1 + 0x12);
      }
    }
    if ((bVar9) && ((*param_1 & 4) != 0)) {
      *param_1 = *param_1 & 0xfffffffb;
      __gnu_Unwind_Save_VFP_D_16_to_31(param_1 + 0x34);
    }
    if (bVar10) {
      __gnu_Unwind_Save_VFP(auStack_a8);
      if (!bVar9) goto LAB_000116f0;
    }
    else {
      if (uVar7 < 0x10) {
        __gnu_Unwind_Save_VFP_D(auStack_a8);
      }
      if (!bVar9) goto LAB_000116f0;
      __gnu_Unwind_Save_VFP_D_16_to_31(auStack_1a8);
    }
    param_3 = 0x10 - uVar7;
LAB_000116f0:
    puVar5 = (undefined4 *)param_1[0xe];
    if (0 < (int)param_3) {
      iVar8 = param_3 * 2;
      puVar2 = auStack_a8 + uVar7 * 2;
      puVar6 = puVar5;
      while (bVar11 = iVar8 != 0, iVar8 = iVar8 + -1, bVar11) {
        *puVar2 = *puVar6;
        puVar2 = puVar2 + 1;
        puVar6 = puVar6 + 1;
      }
      puVar5 = puVar5 + param_3 * 2;
    }
    if (bVar9) {
      uVar4 = uVar7;
      if (uVar7 < 0x10) {
        uVar4 = 0x10;
      }
      iVar8 = uVar1 * 2;
      puVar2 = auStack_228 + uVar4 * 2;
      puVar6 = puVar5;
      while (bVar11 = iVar8 != 0, iVar8 = iVar8 + -1, bVar11) {
        *puVar2 = *puVar6;
        puVar2 = puVar2 + 1;
        puVar6 = puVar6 + 1;
      }
      puVar5 = puVar5 + uVar1 * 2;
    }
    if (bVar10) {
      puVar5 = puVar5 + 1;
    }
    param_1[0xe] = (uint)puVar5;
    if (bVar10) {
      __gnu_Unwind_Restore_VFP(auStack_a8);
    }
    else {
      if (uVar7 < 0x10) {
        __gnu_Unwind_Restore_VFP_D(auStack_a8);
      }
      if (!bVar9) {
        return 0;
      }
      __gnu_Unwind_Restore_VFP_D_16_to_31(auStack_1a8);
    }
    return 0;
  case 2:
    return 1;
  case 3:
    if (param_4 == 3) {
      uVar7 = param_3 & 0xffff;
      if (uVar7 + (param_3 >> 0x10) < 0x11) {
        if ((*param_1 & 8) != 0) {
          *param_1 = *param_1 & 0xfffffff7;
          __gnu_Unwind_Save_WMMXD(param_1 + 0x6c);
        }
        __gnu_Unwind_Save_WMMXD(auStack_128);
        puVar6 = (undefined4 *)param_1[0xe];
        puVar5 = puVar6;
        puVar2 = auStack_128 + (param_3 >> 0x10) * 2;
        for (iVar8 = uVar7 * 2; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar2 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar2 = puVar2 + 1;
        }
        param_1[0xe] = (uint)(puVar6 + uVar7 * 2);
        __gnu_Unwind_Restore_WMMXD(auStack_128);
        return 0;
      }
    }
    break;
  case 4:
    bVar10 = param_3 == 0x10;
    if (param_3 < 0x11) {
      bVar10 = param_4 == 0;
    }
    if (bVar10) {
      if ((*param_1 & 0x10) != 0) {
        *param_1 = *param_1 & 0xffffffef;
        __gnu_Unwind_Save_WMMXC(param_1 + 0x8c);
      }
      __gnu_Unwind_Save_WMMXC(local_1b8);
      puVar5 = (undefined4 *)param_1[0xe];
      uVar7 = 0;
      do {
        if ((param_3 & 1 << (uVar7 & 0xff)) != 0) {
          local_1b8[uVar7] = *puVar5;
          puVar5 = puVar5 + 1;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 != 4);
      param_1[0xe] = (uint)puVar5;
      __gnu_Unwind_Restore_WMMXC(local_1b8);
      return 0;
    }
  }
  return 2;
}



/* Function: _Unwind_GetCFA @ 000118a8 */

undefined4 _Unwind_GetCFA(int param_1)

{
  return *(undefined4 *)(param_1 + 0x44);
}



/* Function: __gnu_Unwind_RaiseException @ 000118b0 */

undefined4 __gnu_Unwind_RaiseException(int param_1,int param_2)

{
  int iVar1;
  undefined4 local_258;
  undefined4 local_254;
  undefined4 uStack_250;
  undefined4 uStack_24c;
  undefined4 uStack_248;
  undefined4 local_244;
  undefined4 uStack_240;
  undefined4 uStack_23c;
  undefined4 uStack_238;
  undefined4 local_234;
  undefined4 uStack_230;
  undefined4 uStack_22c;
  undefined4 uStack_228;
  undefined4 local_224;
  undefined4 uStack_220;
  undefined4 uStack_21c;
  undefined4 local_218;
  
  *(undefined4 *)(param_2 + 0x40) = *(undefined4 *)(param_2 + 0x3c);
  local_254 = *(undefined4 *)(param_2 + 4);
  uStack_250 = *(undefined4 *)(param_2 + 8);
  uStack_24c = *(undefined4 *)(param_2 + 0xc);
  uStack_248 = *(undefined4 *)(param_2 + 0x10);
  local_244 = *(undefined4 *)(param_2 + 0x14);
  uStack_240 = *(undefined4 *)(param_2 + 0x18);
  uStack_23c = *(undefined4 *)(param_2 + 0x1c);
  uStack_238 = *(undefined4 *)(param_2 + 0x20);
  local_234 = *(undefined4 *)(param_2 + 0x24);
  uStack_230 = *(undefined4 *)(param_2 + 0x28);
  uStack_22c = *(undefined4 *)(param_2 + 0x2c);
  uStack_228 = *(undefined4 *)(param_2 + 0x30);
  local_224 = *(undefined4 *)(param_2 + 0x34);
  uStack_220 = *(undefined4 *)(param_2 + 0x38);
  uStack_21c = *(undefined4 *)(param_2 + 0x3c);
  local_218 = *(undefined4 *)(param_2 + 0x40);
  local_258 = 0xffffffff;
  do {
    iVar1 = FUN_00010d1c(param_1,local_218);
    if (iVar1 != 0) {
      return 9;
    }
    iVar1 = (**(code **)(param_1 + 0x10))(0,param_1,&local_258);
  } while (iVar1 == 8);
  FUN_00010ef0(&local_258);
  if (iVar1 == 6) {
    FUN_00011070(param_1,param_2);
  }
  return 9;
}



/* Function: __gnu_Unwind_ForcedUnwind @ 00011954 */

void __gnu_Unwind_ForcedUnwind(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x18) = param_3;
  uVar1 = *(undefined4 *)(param_4 + 0x3c);
  *(undefined4 *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_4 + 0x40) = uVar1;
  FUN_00010f5c(param_1,param_4,0);
  return;
}



/* Function: __gnu_Unwind_Resume @ 00011970 */

void __gnu_Unwind_Resume(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  *(undefined4 *)(param_2 + 0x40) = *(undefined4 *)(param_1 + 0x14);
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar1 = (**(code **)(param_1 + 0x10))(2,param_1,param_2,*(code **)(param_1 + 0x10),param_4);
    if (iVar1 == 7) {
      restore_core_regs(param_2 + 4);
    }
    else if (iVar1 != 8) goto LAB_000119d8;
    FUN_00011070(param_1,param_2);
  }
  else {
    FUN_00010f5c(param_1,param_2,1);
  }
LAB_000119d8:
                    /* WARNING: Subroutine does not return */
  abort();
}



/* Function: __gnu_Unwind_Resume_or_Rethrow @ 000119dc */

void __gnu_Unwind_Resume_or_Rethrow(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0xc) == 0) {
    __gnu_Unwind_RaiseException();
    return;
  }
  *(undefined4 *)(param_2 + 0x40) = *(undefined4 *)(param_2 + 0x3c);
  FUN_00010f5c(param_1,param_2,0);
  return;
}



/* Function: _Unwind_Complete @ 000119fc */

void _Unwind_Complete(void)

{
  return;
}



/* Function: _Unwind_DeleteException @ 00011a00 */

void _Unwind_DeleteException(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(param_1 + 8);
  if (pcVar1 == (code *)0x0) {
    return;
  }
  (*pcVar1)(1,param_1,param_3,pcVar1,param_4);
  return;
}



/* Function: __gnu_Unwind_Backtrace @ 00011a20 */

int __gnu_Unwind_Backtrace(code *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 auStack_2a8 [16];
  code *local_298;
  undefined4 local_250;
  undefined4 local_24c;
  undefined4 uStack_248;
  undefined4 uStack_244;
  undefined4 uStack_240;
  undefined4 local_23c;
  undefined4 uStack_238;
  undefined4 uStack_234;
  undefined4 uStack_230;
  undefined4 local_22c;
  undefined4 uStack_228;
  undefined4 uStack_224;
  undefined4 uStack_220;
  undefined4 local_21c;
  undefined4 uStack_218;
  undefined4 uStack_214;
  undefined4 local_210;
  
  *(undefined4 *)(param_3 + 0x40) = *(undefined4 *)(param_3 + 0x3c);
  local_24c = *(undefined4 *)(param_3 + 4);
  uStack_248 = *(undefined4 *)(param_3 + 8);
  uStack_244 = *(undefined4 *)(param_3 + 0xc);
  uStack_240 = *(undefined4 *)(param_3 + 0x10);
  local_23c = *(undefined4 *)(param_3 + 0x14);
  uStack_238 = *(undefined4 *)(param_3 + 0x18);
  uStack_234 = *(undefined4 *)(param_3 + 0x1c);
  uStack_230 = *(undefined4 *)(param_3 + 0x20);
  local_22c = *(undefined4 *)(param_3 + 0x24);
  uStack_228 = *(undefined4 *)(param_3 + 0x28);
  uStack_224 = *(undefined4 *)(param_3 + 0x2c);
  uStack_220 = *(undefined4 *)(param_3 + 0x30);
  local_21c = *(undefined4 *)(param_3 + 0x34);
  uStack_218 = *(undefined4 *)(param_3 + 0x38);
  uStack_214 = *(undefined4 *)(param_3 + 0x3c);
  local_210 = *(undefined4 *)(param_3 + 0x40);
  local_250 = 0xffffffff;
  do {
    iVar1 = FUN_00010d1c(auStack_2a8,local_210);
    if (iVar1 != 0) {
LAB_00011ac8:
      iVar1 = 9;
      break;
    }
    FUN_00011178(&local_250,0xc,auStack_2a8);
    iVar1 = (*param_1)(&local_250,param_2);
    if (iVar1 != 0) goto LAB_00011ac8;
    iVar1 = (*local_298)(8,auStack_2a8,&local_250);
  } while (iVar1 != 9 && iVar1 != 5);
  FUN_00010ef0(&local_250);
  return iVar1;
}



/* Function: restore_core_regs @ 00011ae0 */

undefined8 restore_core_regs(undefined8 *param_1)

{
  return *param_1;
}



/* Function: __gnu_Unwind_Restore_VFP @ 00011af4 */

undefined4 __gnu_Unwind_Restore_VFP(undefined8 *param_1)

{
  return (int)*param_1;
}



/* Function: __gnu_Unwind_Save_VFP @ 00011afc */

void __gnu_Unwind_Save_VFP(undefined8 *param_1)

{
  undefined8 in_d0;
  undefined8 in_d1;
  undefined8 in_d2;
  undefined8 in_d3;
  undefined8 in_d4;
  undefined8 in_d5;
  undefined8 in_d6;
  undefined8 in_d7;
  undefined8 unaff_d8;
  undefined8 unaff_d9;
  undefined8 unaff_d10;
  undefined8 unaff_d11;
  undefined8 unaff_d12;
  undefined8 unaff_d13;
  undefined8 unaff_d14;
  undefined8 unaff_d15;
  
  *param_1 = in_d0;
  param_1[1] = in_d1;
  param_1[2] = in_d2;
  param_1[3] = in_d3;
  param_1[4] = in_d4;
  param_1[5] = in_d5;
  param_1[6] = in_d6;
  param_1[7] = in_d7;
  param_1[8] = unaff_d8;
  param_1[9] = unaff_d9;
  param_1[10] = unaff_d10;
  param_1[0xb] = unaff_d11;
  param_1[0xc] = unaff_d12;
  param_1[0xd] = unaff_d13;
  param_1[0xe] = unaff_d14;
  param_1[0xf] = unaff_d15;
  return;
}



/* Function: __gnu_Unwind_Restore_VFP_D @ 00011b04 */

undefined4 __gnu_Unwind_Restore_VFP_D(undefined8 *param_1)

{
  return (int)*param_1;
}



/* Function: __gnu_Unwind_Save_VFP_D @ 00011b0c */

void __gnu_Unwind_Save_VFP_D(undefined8 *param_1)

{
  undefined8 in_d0;
  undefined8 in_d1;
  undefined8 in_d2;
  undefined8 in_d3;
  undefined8 in_d4;
  undefined8 in_d5;
  undefined8 in_d6;
  undefined8 in_d7;
  undefined8 unaff_d8;
  undefined8 unaff_d9;
  undefined8 unaff_d10;
  undefined8 unaff_d11;
  undefined8 unaff_d12;
  undefined8 unaff_d13;
  undefined8 unaff_d14;
  undefined8 unaff_d15;
  
  *param_1 = in_d0;
  param_1[1] = in_d1;
  param_1[2] = in_d2;
  param_1[3] = in_d3;
  param_1[4] = in_d4;
  param_1[5] = in_d5;
  param_1[6] = in_d6;
  param_1[7] = in_d7;
  param_1[8] = unaff_d8;
  param_1[9] = unaff_d9;
  param_1[10] = unaff_d10;
  param_1[0xb] = unaff_d11;
  param_1[0xc] = unaff_d12;
  param_1[0xd] = unaff_d13;
  param_1[0xe] = unaff_d14;
  param_1[0xf] = unaff_d15;
  return;
}



/* Function: __gnu_Unwind_Restore_VFP_D_16_to_31 @ 00011b14 */

void __gnu_Unwind_Restore_VFP_D_16_to_31(void)

{
  return;
}



/* Function: __gnu_Unwind_Save_VFP_D_16_to_31 @ 00011b1c */

void __gnu_Unwind_Save_VFP_D_16_to_31(undefined8 *param_1)

{
  undefined8 in_d16;
  undefined8 in_d17;
  undefined8 in_d18;
  undefined8 in_d19;
  undefined8 in_d20;
  undefined8 in_d21;
  undefined8 in_d22;
  undefined8 in_d23;
  undefined8 in_d24;
  undefined8 in_d25;
  undefined8 in_d26;
  undefined8 in_d27;
  undefined8 in_d28;
  undefined8 in_d29;
  undefined8 in_d30;
  undefined8 in_d31;
  
  *param_1 = in_d16;
  param_1[1] = in_d17;
  param_1[2] = in_d18;
  param_1[3] = in_d19;
  param_1[4] = in_d20;
  param_1[5] = in_d21;
  param_1[6] = in_d22;
  param_1[7] = in_d23;
  param_1[8] = in_d24;
  param_1[9] = in_d25;
  param_1[10] = in_d26;
  param_1[0xb] = in_d27;
  param_1[0xc] = in_d28;
  param_1[0xd] = in_d29;
  param_1[0xe] = in_d30;
  param_1[0xf] = in_d31;
  return;
}



/* Function: __gnu_Unwind_Restore_WMMXD @ 00011b24 */

int __gnu_Unwind_Restore_WMMXD(int param_1)

{
  undefined4 in_cr0;
  undefined4 in_cr1;
  undefined4 in_cr2;
  undefined4 in_cr3;
  undefined4 in_cr4;
  undefined4 in_cr5;
  undefined4 in_cr6;
  undefined4 in_cr7;
  undefined4 in_cr8;
  undefined4 in_cr9;
  undefined4 in_cr10;
  undefined4 in_cr11;
  undefined4 in_cr12;
  undefined4 in_cr13;
  undefined4 in_cr14;
  undefined4 in_cr15;
  
  coprocessor_loadlong(1,in_cr0,param_1);
  coprocessor_loadlong(1,in_cr1,param_1 + 8);
  coprocessor_loadlong(1,in_cr2,param_1 + 0x10);
  coprocessor_loadlong(1,in_cr3,param_1 + 0x18);
  coprocessor_loadlong(1,in_cr4,param_1 + 0x20);
  coprocessor_loadlong(1,in_cr5,param_1 + 0x28);
  coprocessor_loadlong(1,in_cr6,param_1 + 0x30);
  coprocessor_loadlong(1,in_cr7,param_1 + 0x38);
  coprocessor_loadlong(1,in_cr8,param_1 + 0x40);
  coprocessor_loadlong(1,in_cr9,param_1 + 0x48);
  coprocessor_loadlong(1,in_cr10,param_1 + 0x50);
  coprocessor_loadlong(1,in_cr11,param_1 + 0x58);
  coprocessor_loadlong(1,in_cr12,param_1 + 0x60);
  coprocessor_loadlong(1,in_cr13,param_1 + 0x68);
  coprocessor_loadlong(1,in_cr14,param_1 + 0x70);
  coprocessor_loadlong(1,in_cr15,param_1 + 0x78);
  return param_1 + 0x80;
}



/* Function: __gnu_Unwind_Save_WMMXD @ 00011b68 */

int __gnu_Unwind_Save_WMMXD(int param_1)

{
  undefined4 in_cr0;
  undefined4 in_cr1;
  undefined4 in_cr2;
  undefined4 in_cr3;
  undefined4 in_cr4;
  undefined4 in_cr5;
  undefined4 in_cr6;
  undefined4 in_cr7;
  undefined4 in_cr8;
  undefined4 in_cr9;
  undefined4 in_cr10;
  undefined4 in_cr11;
  undefined4 in_cr12;
  undefined4 in_cr13;
  undefined4 in_cr14;
  undefined4 in_cr15;
  
  coprocessor_storelong(1,in_cr0,param_1);
  coprocessor_storelong(1,in_cr1,param_1 + 8);
  coprocessor_storelong(1,in_cr2,param_1 + 0x10);
  coprocessor_storelong(1,in_cr3,param_1 + 0x18);
  coprocessor_storelong(1,in_cr4,param_1 + 0x20);
  coprocessor_storelong(1,in_cr5,param_1 + 0x28);
  coprocessor_storelong(1,in_cr6,param_1 + 0x30);
  coprocessor_storelong(1,in_cr7,param_1 + 0x38);
  coprocessor_storelong(1,in_cr8,param_1 + 0x40);
  coprocessor_storelong(1,in_cr9,param_1 + 0x48);
  coprocessor_storelong(1,in_cr10,param_1 + 0x50);
  coprocessor_storelong(1,in_cr11,param_1 + 0x58);
  coprocessor_storelong(1,in_cr12,param_1 + 0x60);
  coprocessor_storelong(1,in_cr13,param_1 + 0x68);
  coprocessor_storelong(1,in_cr14,param_1 + 0x70);
  coprocessor_storelong(1,in_cr15,param_1 + 0x78);
  return param_1 + 0x80;
}



/* Function: __gnu_Unwind_Restore_WMMXC @ 00011bac */

int __gnu_Unwind_Restore_WMMXC(int param_1)

{
  undefined4 in_cr8;
  undefined4 in_cr9;
  undefined4 in_cr10;
  undefined4 in_cr11;
  
  coprocessor_load2(1,in_cr8,param_1);
  coprocessor_load2(1,in_cr9,param_1 + 4);
  coprocessor_load2(1,in_cr10,param_1 + 8);
  coprocessor_load2(1,in_cr11,param_1 + 0xc);
  return param_1 + 0x10;
}



/* Function: __gnu_Unwind_Save_WMMXC @ 00011bc0 */

int __gnu_Unwind_Save_WMMXC(int param_1)

{
  undefined4 in_cr8;
  undefined4 in_cr9;
  undefined4 in_cr10;
  undefined4 in_cr11;
  
  coprocessor_store2(1,in_cr8,param_1);
  coprocessor_store2(1,in_cr9,param_1 + 4);
  coprocessor_store2(1,in_cr10,param_1 + 8);
  coprocessor_store2(1,in_cr11,param_1 + 0xc);
  return param_1 + 0x10;
}



/* Function: _Unwind_RaiseException @ 00011bd4 */

void _Unwind_RaiseException
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  uStack_44 = 0;
  uStack_40 = param_1;
  uStack_3c = param_2;
  uStack_38 = param_3;
  uStack_34 = param_4;
  __gnu_Unwind_RaiseException(param_1,&uStack_44,param_3,0,param_3);
  return;
}



/* Function: _Unwind_Resume @ 00011bf8 */

void _Unwind_Resume(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  uStack_44 = 0;
  uStack_40 = param_1;
  uStack_3c = param_2;
  uStack_38 = param_3;
  uStack_34 = param_4;
  __gnu_Unwind_Resume(param_1,&uStack_44,param_3,0,param_3);
  return;
}



/* Function: _Unwind_Resume_or_Rethrow @ 00011c1c */

void _Unwind_Resume_or_Rethrow
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  uStack_44 = 0;
  uStack_40 = param_1;
  uStack_3c = param_2;
  uStack_38 = param_3;
  uStack_34 = param_4;
  __gnu_Unwind_Resume_or_Rethrow(param_1,&uStack_44,param_3,0,param_3);
  return;
}



/* Function: _Unwind_ForcedUnwind @ 00011c40 */

void _Unwind_ForcedUnwind(void)

{
  __gnu_Unwind_ForcedUnwind();
  return;
}



/* Function: _Unwind_Backtrace @ 00011c64 */

void _Unwind_Backtrace(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  uStack_44 = 0;
  uStack_40 = param_1;
  uStack_3c = param_2;
  uStack_38 = param_3;
  uStack_34 = param_4;
  __gnu_Unwind_Backtrace(param_1,param_2,&uStack_44,0,param_3);
  return;
}



/* Function: FUN_00011c88 @ 00011c88 */

uint FUN_00011c88(uint *param_1)

{
  char cVar1;
  uint uVar2;
  
  if ((char)param_1[2] == '\0') {
    if (*(char *)((int)param_1 + 9) == '\0') {
      return 0xb0;
    }
    *(char *)((int)param_1 + 9) = *(char *)((int)param_1 + 9) + -1;
    *param_1 = *(uint *)param_1[1];
    param_1[1] = (uint)((uint *)param_1[1] + 1);
    cVar1 = '\x03';
  }
  else {
    cVar1 = (char)param_1[2] + -1;
  }
  *(char *)(param_1 + 2) = cVar1;
  uVar2 = *param_1;
  *param_1 = uVar2 << 8;
  return uVar2 >> 0x18;
}



/* Function: __gnu_unwind_execute @ 00011ce0 */

undefined4 __gnu_unwind_execute(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  bool bVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int local_24;
  
  bVar4 = false;
  piVar6 = param_1;
  uVar7 = param_2;
  local_24 = param_4;
LAB_00011cf8:
  do {
    while( true ) {
      uVar1 = FUN_00011c88(param_2);
      if (uVar1 == 0xb0) {
        if (bVar4) {
          return 0;
        }
        _Unwind_VRS_Get(param_1,0,0xe,0,&local_24,uVar7,param_3);
        _Unwind_VRS_Set(param_1,0,0xf,0,&local_24);
        return 0;
      }
      if ((uVar1 & 0x80) != 0) break;
      _Unwind_VRS_Get(param_1,0,0xd,0,&local_24,uVar7,param_3);
      iVar5 = (uVar1 & 0x3f) * 4 + 4;
      if ((uVar1 & 0x40) != 0) {
        iVar5 = -iVar5;
      }
      local_24 = local_24 + iVar5;
LAB_00011e34:
      piVar6 = &local_24;
      _Unwind_VRS_Set(param_1,0,0xd,0);
    }
    uVar3 = uVar1 & 0xf0;
    if (uVar3 == 0x80) {
      uVar3 = FUN_00011c88(param_2);
      uVar3 = uVar3 | uVar1 << 8;
      if (uVar3 == 0x8000) {
        return 9;
      }
      iVar5 = _Unwind_VRS_Pop(param_1,0,(uVar3 & 0xfff) << 4,0,piVar6);
      if (iVar5 != 0) {
        return 9;
      }
      if ((uVar3 & 0x800) != 0) {
        bVar4 = true;
      }
      goto LAB_00011cf8;
    }
    if (uVar3 == 0x90) {
      uVar1 = uVar1 & 0xf;
      if (uVar1 == 0xd || uVar1 == 0xf) {
        return 9;
      }
      _Unwind_VRS_Get(param_1,0,uVar1,0,&local_24,uVar7,param_3);
      goto LAB_00011e34;
    }
    if (uVar3 == 0xa0) {
      uVar2 = 0;
    }
    else if (uVar3 == 0xb0) {
      if (uVar1 == 0xb1) {
        uVar1 = FUN_00011c88(param_2);
        if (uVar1 == 0) {
          return 9;
        }
        if ((uVar1 & 0xf0) != 0) {
          return 9;
        }
        uVar2 = 0;
      }
      else {
        if (uVar1 == 0xb2) {
          _Unwind_VRS_Get(param_1,0,0xd,0,&local_24,uVar7,param_3);
          uVar1 = FUN_00011c88(param_2);
          uVar3 = 2;
          while ((uVar1 & 0x80) != 0) {
            local_24 = local_24 + ((uVar1 & 0x7f) << (uVar3 & 0xff));
            uVar3 = uVar3 + 7;
            uVar1 = FUN_00011c88(param_2);
          }
          local_24 = local_24 + 0x204 + ((uVar1 & 0x7f) << (uVar3 & 0xff));
          goto LAB_00011e34;
        }
        if (uVar1 == 0xb3) {
          FUN_00011c88(param_2);
          uVar2 = 1;
        }
        else if ((uVar1 & 0xfc) == 0xb4) {
          uVar2 = 2;
        }
        else {
          uVar2 = 1;
        }
      }
    }
    else if (uVar3 == 0xc0) {
      if (uVar1 == 0xc6) {
        FUN_00011c88(param_2);
        uVar2 = 3;
      }
      else if (uVar1 == 199) {
        uVar1 = FUN_00011c88(param_2);
        if (uVar1 == 0) {
          return 9;
        }
        if ((uVar1 & 0xf0) != 0) {
          return 9;
        }
        uVar2 = 4;
      }
      else {
        if ((uVar1 & 0xf8) != 0xc0) {
          if (uVar1 == 200) {
            FUN_00011c88(param_2);
          }
          else {
            if (uVar1 != 0xc9) {
              return 9;
            }
            FUN_00011c88(param_2);
          }
          goto LAB_00012058;
        }
        uVar2 = 3;
      }
    }
    else {
      if ((uVar1 & 0xf8) != 0xd0) {
        return 9;
      }
LAB_00012058:
      uVar2 = 1;
    }
    iVar5 = _Unwind_VRS_Pop(param_1,uVar2);
    if (iVar5 != 0) {
      return 9;
    }
  } while( true );
}



/* Function: __gnu_unwind_frame @ 00012074 */

void __gnu_unwind_frame(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int local_14;
  int local_10;
  undefined1 local_c;
  undefined1 local_b;
  undefined2 uStack_a;
  
  iVar1 = *(int *)(param_1 + 0x4c);
  local_14 = *(int *)(iVar1 + 4) << 8;
  local_10 = iVar1 + 8;
  uStack_a = (undefined2)((uint)param_4 >> 0x10);
  _local_c = CONCAT11(*(undefined1 *)(iVar1 + 7),3);
  __gnu_unwind_execute(param_2,&local_14,3,*(undefined1 *)(iVar1 + 7),param_1);
  return;
}



/* Function: _Unwind_GetRegionStart @ 000120b4 */

undefined4
_Unwind_GetRegionStart(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int local_c;
  
  local_c = param_4;
  _Unwind_VRS_Get(param_1,0,0xc,0,&local_c,param_2,param_3);
  return *(undefined4 *)(local_c + 0x48);
}



/* Function: _Unwind_GetLanguageSpecificData @ 000120e0 */

int _Unwind_GetLanguageSpecificData
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int local_c;
  
  local_c = param_4;
  _Unwind_VRS_Get(param_1,0,0xc,0,&local_c,param_2,param_3);
  return *(int *)(local_c + 0x4c) + (uint)*(byte *)(*(int *)(local_c + 0x4c) + 7) * 4 + 8;
}



/* Function: _Unwind_GetDataRelBase @ 00012118 */

void _Unwind_GetDataRelBase(void)

{
                    /* WARNING: Subroutine does not return */
  abort();
}



/* Function: _Unwind_GetTextRelBase @ 00012120 */

void _Unwind_GetTextRelBase(void)

{
                    /* WARNING: Subroutine does not return */
  abort();
}



/* Function: __cxa_finalize @ 00015000 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_finalize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_atexit @ 00015004 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_atexit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: dlerror @ 00015008 */

/* WARNING: Control flow encountered bad instruction data */

void dlerror(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: dlopen @ 0001500c */

/* WARNING: Control flow encountered bad instruction data */

void dlopen(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: dlsym @ 00015010 */

/* WARNING: Control flow encountered bad instruction data */

void dlsym(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __android_log_print @ 00015014 */

/* WARNING: Control flow encountered bad instruction data */

void __android_log_print(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __gnu_Unwind_Find_exidx @ 00015018 */

/* WARNING: Control flow encountered bad instruction data */

void __gnu_Unwind_Find_exidx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: memcpy @ 0001501c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: abort @ 00015020 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_begin_cleanup @ 00015024 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_begin_cleanup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_type_match @ 00015028 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_type_match(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_call_unexpected @ 0001502c */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_call_unexpected(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



