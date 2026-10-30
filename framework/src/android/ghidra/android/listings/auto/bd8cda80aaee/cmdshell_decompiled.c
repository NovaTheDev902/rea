/* Function: __cxa_begin_cleanup @ 00008564 */

void __cxa_begin_cleanup(void)

{
  (*(code *)PTR___cxa_begin_cleanup_0000ad48)();
  return;
}



/* Function: memcpy @ 00008570 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memcpy_0000ad4c)(__dest);
  return pvVar1;
}



/* Function: system @ 0000857c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int system(char *__command)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_system_0000ad50)(__command);
  return iVar1;
}



/* Function: abort @ 00008588 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
  (*(code *)PTR_abort_0000ad54)();
  return;
}



/* Function: __cxa_type_match @ 000085a0 */

void __cxa_type_match(void)

{
  (*(code *)PTR___cxa_type_match_0000ad5c)();
  return;
}



/* Function: setresuid @ 000085ac */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int setresuid(__uid_t __ruid,__uid_t __euid,__uid_t __suid)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_setresuid_0000ad60)(__ruid);
  return iVar1;
}



/* Function: __gnu_Unwind_Find_exidx @ 000085b8 */

void __gnu_Unwind_Find_exidx(void)

{
  (*(code *)PTR___gnu_Unwind_Find_exidx_0000ad64)();
  return;
}



/* Function: setresgid @ 000085c4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int setresgid(__gid_t __rgid,__gid_t __egid,__gid_t __sgid)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_setresgid_0000ad68)(__rgid);
  return iVar1;
}



/* Function: entry @ 000085d0 */

void processEntry entry(void)

{
  (*(code *)PTR___libc_init_0000ad58)();
  return;
}



/* Function: FUN_0000862c @ 0000862c */

undefined4 FUN_0000862c(int param_1,uint param_2,uint param_3,int param_4,undefined4 *param_5)

{
  bool bVar1;
  
  if (param_2 == 0) {
    bVar1 = param_3 == 0xf;
    if (param_3 < 0x10) {
      bVar1 = param_4 == 0;
    }
    if (bVar1) {
      *param_5 = *(undefined4 *)(param_1 + param_3 * 4 + 4);
      return 0;
    }
  }
  else if (param_2 < 5) {
    return 1;
  }
  return 2;
}



/* Function: FUN_00008678 @ 00008678 */

undefined4 FUN_00008678(int param_1,uint param_2,uint param_3,int param_4,undefined4 *param_5)

{
  bool bVar1;
  
  if (param_2 == 0) {
    bVar1 = param_3 == 0xf;
    if (param_3 < 0x10) {
      bVar1 = param_4 == 0;
    }
    if (bVar1) {
      *(undefined4 *)(param_1 + param_3 * 4 + 4) = *param_5;
      return 0;
    }
  }
  else if (param_2 < 5) {
    return 1;
  }
  return 2;
}



/* Function: FUN_000086c4 @ 000086c4 */

int FUN_000086c4(uint *param_1)

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



/* Function: __aeabi_unwind_cpp_pr2 @ 00008b9c */

/* WARNING: Removing unreachable block (ram,0x0000873c) */
/* WARNING: Removing unreachable block (ram,0x000087b8) */
/* WARNING: Removing unreachable block (ram,0x000087d8) */

undefined4 __aeabi_unwind_cpp_pr2(uint param_1,uint param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  bool bVar11;
  uint uVar12;
  uint local_58;
  int local_3c;
  uint *local_38;
  undefined1 local_34;
  undefined1 local_33;
  uint local_30;
  int local_2c [2];
  
  uVar8 = param_1 & 3;
  local_38 = *(uint **)(param_2 + 0x4c) + 1;
  uVar5 = **(uint **)(param_2 + 0x4c);
  local_3c = uVar5 << 0x10;
  puVar9 = local_38 + (uVar5 >> 0x10 & 0xff);
  local_34 = 2;
  local_33 = (undefined1)(uVar5 >> 0x10);
  if (uVar8 == 2) {
    puVar9 = *(uint **)(param_2 + 0x38);
  }
  if ((*(uint *)(param_2 + 0x50) & 1) == 0) {
    iVar3 = param_2 + 0x58;
    bVar11 = false;
LAB_00008b00:
    do {
      while( true ) {
        uVar5 = *puVar9;
        if (uVar5 == 0) goto LAB_00008b0c;
        uVar10 = puVar9[1];
        puVar7 = puVar9 + 2;
        uVar12 = (uVar10 & 0xfffffffe) + *(int *)(param_2 + 0x48);
        FUN_0000862c(param_3,0,0xf,0,&local_30);
        if (local_30 < uVar12) {
          bVar1 = false;
        }
        else if (local_30 < uVar12 + (uVar5 & 0xfffffffe)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        uVar5 = uVar5 & 1 | (uVar10 & 1) << 1;
        if (uVar5 != 1) break;
        if (uVar8 == 0) {
          if (bVar1) {
            uVar5 = puVar9[3];
            if (uVar5 == 0xfffffffe) {
              return 9;
            }
            local_2c[0] = iVar3;
            if (uVar5 != 0xffffffff) {
              if (uVar5 == 0) {
                uVar4 = 0;
              }
              else {
                uVar4 = *(undefined4 *)((int)puVar9 + uVar5 + 0xc);
              }
              iVar2 = __cxa_type_match(param_2,uVar4,*puVar7 >> 0x1f,local_2c);
              if (iVar2 == 0) {
                local_2c[0] = 0;
              }
            }
            if (local_2c[0] != 0) {
LAB_00008a00:
              FUN_0000862c(param_3,0,0xd,0,&local_30);
              *(uint **)(param_2 + 0x28) = puVar7;
              *(uint *)(param_2 + 0x20) = local_30;
              *(int *)(param_2 + 0x24) = local_2c[0];
              return 6;
            }
          }
        }
        else {
          uVar5 = *(uint *)(param_2 + 0x20);
          FUN_0000862c(param_3,0,0xd,0,&local_30);
          if ((uVar5 == local_30) && (puVar7 == *(uint **)(param_2 + 0x28))) {
            local_30 = FUN_000086c4(puVar7);
            FUN_00008678(param_3,0,0xf,0,&local_30);
LAB_00008ac4:
            uVar4 = 0;
            local_30 = param_2;
            goto LAB_00008b80;
          }
        }
        puVar9 = puVar9 + 4;
      }
      if (uVar5 != 0) {
        if (uVar5 != 2) {
          return 9;
        }
        uVar5 = *puVar7 & 0x7fffffff;
        if (uVar8 == 0) {
          if ((bVar1) && ((param_1 & 8) == 0 || uVar5 == 0)) {
            local_58 = 0;
            puVar6 = puVar7;
            do {
              if (local_58 == uVar5) goto LAB_00008a00;
              puVar6 = puVar6 + 1;
              local_58 = local_58 + 1;
              uVar4 = 0;
              if (*puVar6 != 0) {
                uVar4 = *(undefined4 *)((int)puVar6 + *puVar6);
              }
              local_2c[0] = iVar3;
              iVar2 = __cxa_type_match(param_2,uVar4,0,local_2c);
            } while (iVar2 == 0);
          }
        }
        else {
          uVar10 = *(uint *)(param_2 + 0x20);
          FUN_0000862c(param_3,0,0xd,0,&local_30);
          if ((uVar10 == local_30) && (puVar7 == *(uint **)(param_2 + 0x28))) {
            *(uint **)(param_2 + 0x34) = puVar9 + 3;
            *(uint *)(param_2 + 0x28) = uVar5;
            *(undefined4 *)(param_2 + 0x2c) = 0;
            *(undefined4 *)(param_2 + 0x30) = 4;
            if (-1 < (int)*puVar7) {
              local_30 = FUN_000086c4(puVar7 + uVar5 + 1);
              FUN_00008678(param_3,0,0xf,0,&local_30);
              goto LAB_00008ac4;
            }
            bVar11 = true;
          }
        }
        if ((int)*puVar7 < 0) {
          puVar7 = puVar9 + 3;
        }
        puVar9 = puVar7 + uVar5 + 1;
        goto LAB_00008b00;
      }
      if (uVar8 == 0) {
        bVar1 = false;
      }
      puVar9 = puVar9 + 3;
    } while (!bVar1);
    uVar5 = FUN_000086c4(puVar7);
    *(uint **)(param_2 + 0x38) = puVar9;
    iVar3 = __cxa_begin_cleanup(param_2);
    if (iVar3 != 0) {
      uVar4 = 0xf;
      local_30 = uVar5;
      goto LAB_00008b80;
    }
  }
  else {
    bVar11 = false;
LAB_00008b0c:
    iVar3 = FUN_00009764(param_3,&local_3c);
    if (iVar3 == 0) {
      if (!bVar11) {
        return 8;
      }
      FUN_0000862c(param_3,0,0xf,0,&local_30);
      FUN_00008678(param_3,0,0xe,0,&local_30);
      uVar4 = 0xf;
      local_30 = *(uint *)(DAT_00008b98 + 0x8b70);
LAB_00008b80:
      FUN_00008678(param_3,0,uVar4,0,&local_30);
      return 7;
    }
  }
  return 9;
}



/* Function: __aeabi_unwind_cpp_pr1 @ 00008ba4 */

/* WARNING: Removing unreachable block (ram,0x0000873c) */
/* WARNING: Removing unreachable block (ram,0x000087bc) */
/* WARNING: Removing unreachable block (ram,0x000087d4) */

undefined4 __aeabi_unwind_cpp_pr1(uint param_1,uint param_2,undefined4 param_3)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  uint uVar9;
  uint *puVar10;
  bool bVar11;
  uint uVar12;
  uint uStack_58;
  int iStack_3c;
  uint *puStack_38;
  undefined1 uStack_34;
  undefined1 uStack_33;
  uint uStack_30;
  int aiStack_2c [2];
  
  uVar9 = param_1 & 3;
  puStack_38 = *(uint **)(param_2 + 0x4c) + 1;
  uVar6 = **(uint **)(param_2 + 0x4c);
  iStack_3c = uVar6 << 0x10;
  puVar10 = puStack_38 + (uVar6 >> 0x10 & 0xff);
  uStack_34 = 2;
  uStack_33 = (undefined1)(uVar6 >> 0x10);
  if (uVar9 == 2) {
    puVar10 = *(uint **)(param_2 + 0x38);
  }
  if ((*(uint *)(param_2 + 0x50) & 1) == 0) {
    iVar4 = param_2 + 0x58;
    bVar11 = false;
LAB_00008b00:
    do {
      while( true ) {
        if (*puVar10 == 0) goto LAB_00008b0c;
        uVar1 = *(ushort *)((int)puVar10 + 2);
        uVar6 = *puVar10;
        puVar8 = puVar10 + 1;
        uVar12 = (uVar1 & 0xfffffffe) + *(int *)(param_2 + 0x48);
        FUN_0000862c(param_3,0,0xf,0,&uStack_30);
        if (uStack_30 < uVar12) {
          bVar2 = false;
        }
        else if (uStack_30 < uVar12 + ((ushort)uVar6 & 0xfffffffe)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        uVar6 = (ushort)uVar6 & 1 | (uVar1 & 1) << 1;
        if (uVar6 != 1) break;
        if (uVar9 == 0) {
          if (bVar2) {
            uVar6 = puVar10[2];
            if (uVar6 == 0xfffffffe) {
              return 9;
            }
            aiStack_2c[0] = iVar4;
            if (uVar6 != 0xffffffff) {
              if (uVar6 == 0) {
                uVar5 = 0;
              }
              else {
                uVar5 = *(undefined4 *)((int)puVar10 + uVar6 + 8);
              }
              iVar3 = __cxa_type_match(param_2,uVar5,*puVar8 >> 0x1f,aiStack_2c);
              if (iVar3 == 0) {
                aiStack_2c[0] = 0;
              }
            }
            if (aiStack_2c[0] != 0) {
LAB_00008a00:
              FUN_0000862c(param_3,0,0xd,0,&uStack_30);
              *(uint **)(param_2 + 0x28) = puVar8;
              *(uint *)(param_2 + 0x20) = uStack_30;
              *(int *)(param_2 + 0x24) = aiStack_2c[0];
              return 6;
            }
          }
        }
        else {
          uVar6 = *(uint *)(param_2 + 0x20);
          FUN_0000862c(param_3,0,0xd,0,&uStack_30);
          if ((uVar6 == uStack_30) && (puVar8 == *(uint **)(param_2 + 0x28))) {
            uStack_30 = FUN_000086c4(puVar8);
            FUN_00008678(param_3,0,0xf,0,&uStack_30);
LAB_00008ac4:
            uVar5 = 0;
            uStack_30 = param_2;
            goto LAB_00008b80;
          }
        }
        puVar10 = puVar10 + 3;
      }
      if (uVar6 != 0) {
        if (uVar6 != 2) {
          return 9;
        }
        uVar6 = *puVar8 & 0x7fffffff;
        if (uVar9 == 0) {
          if ((bVar2) && ((param_1 & 8) == 0 || uVar6 == 0)) {
            uStack_58 = 0;
            puVar7 = puVar8;
            do {
              if (uStack_58 == uVar6) goto LAB_00008a00;
              puVar7 = puVar7 + 1;
              uStack_58 = uStack_58 + 1;
              uVar5 = 0;
              if (*puVar7 != 0) {
                uVar5 = *(undefined4 *)((int)puVar7 + *puVar7);
              }
              aiStack_2c[0] = iVar4;
              iVar3 = __cxa_type_match(param_2,uVar5,0,aiStack_2c);
            } while (iVar3 == 0);
          }
        }
        else {
          uVar12 = *(uint *)(param_2 + 0x20);
          FUN_0000862c(param_3,0,0xd,0,&uStack_30);
          if ((uVar12 == uStack_30) && (puVar8 == *(uint **)(param_2 + 0x28))) {
            *(uint **)(param_2 + 0x34) = puVar10 + 2;
            *(uint *)(param_2 + 0x28) = uVar6;
            *(undefined4 *)(param_2 + 0x2c) = 0;
            *(undefined4 *)(param_2 + 0x30) = 4;
            if (-1 < (int)*puVar8) {
              uStack_30 = FUN_000086c4(puVar8 + uVar6 + 1);
              FUN_00008678(param_3,0,0xf,0,&uStack_30);
              goto LAB_00008ac4;
            }
            bVar11 = true;
          }
        }
        if ((int)*puVar8 < 0) {
          puVar8 = puVar10 + 2;
        }
        puVar10 = puVar8 + uVar6 + 1;
        goto LAB_00008b00;
      }
      if (uVar9 == 0) {
        bVar2 = false;
      }
      puVar10 = puVar10 + 2;
    } while (!bVar2);
    uVar6 = FUN_000086c4(puVar8);
    *(uint **)(param_2 + 0x38) = puVar10;
    iVar4 = __cxa_begin_cleanup(param_2);
    if (iVar4 != 0) {
      uVar5 = 0xf;
      uStack_30 = uVar6;
      goto LAB_00008b80;
    }
  }
  else {
    bVar11 = false;
LAB_00008b0c:
    iVar4 = FUN_00009764(param_3,&iStack_3c);
    if (iVar4 == 0) {
      if (!bVar11) {
        return 8;
      }
      FUN_0000862c(param_3,0,0xf,0,&uStack_30);
      FUN_00008678(param_3,0,0xe,0,&uStack_30);
      uVar5 = 0xf;
      uStack_30 = *(uint *)(DAT_00008b98 + 0x8b70);
LAB_00008b80:
      FUN_00008678(param_3,0,uVar5,0,&uStack_30);
      return 7;
    }
  }
  return 9;
}



/* Function: __aeabi_unwind_cpp_pr0 @ 00008bac */

/* WARNING: Removing unreachable block (ram,0x00008758) */
/* WARNING: Removing unreachable block (ram,0x000087bc) */
/* WARNING: Removing unreachable block (ram,0x000087d4) */

undefined4 __aeabi_unwind_cpp_pr0(uint param_1,uint param_2,undefined4 param_3)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  bool bVar11;
  uint uVar12;
  uint uStack_58;
  int iStack_3c;
  uint *puStack_38;
  undefined1 uStack_34;
  undefined1 uStack_33;
  uint uStack_30;
  int aiStack_2c [2];
  
  uVar8 = param_1 & 3;
  puStack_38 = (uint *)(*(int **)(param_2 + 0x4c) + 1);
  iStack_3c = **(int **)(param_2 + 0x4c) << 8;
  uStack_34 = 3;
  uStack_33 = 0;
  puVar9 = puStack_38;
  if (uVar8 == 2) {
    puVar9 = *(uint **)(param_2 + 0x38);
  }
  if ((*(uint *)(param_2 + 0x50) & 1) == 0) {
    iVar4 = param_2 + 0x58;
    bVar11 = false;
LAB_00008b00:
    do {
      while( true ) {
        if (*puVar9 == 0) goto LAB_00008b0c;
        uVar1 = *(ushort *)((int)puVar9 + 2);
        uVar10 = *puVar9;
        puVar7 = puVar9 + 1;
        uVar12 = (uVar1 & 0xfffffffe) + *(int *)(param_2 + 0x48);
        FUN_0000862c(param_3,0,0xf,0,&uStack_30);
        if (uStack_30 < uVar12) {
          bVar2 = false;
        }
        else if (uStack_30 < uVar12 + ((ushort)uVar10 & 0xfffffffe)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        uVar10 = (ushort)uVar10 & 1 | (uVar1 & 1) << 1;
        if (uVar10 != 1) break;
        if (uVar8 == 0) {
          if (bVar2) {
            uVar10 = puVar9[2];
            if (uVar10 == 0xfffffffe) {
              return 9;
            }
            aiStack_2c[0] = iVar4;
            if (uVar10 != 0xffffffff) {
              if (uVar10 == 0) {
                uVar5 = 0;
              }
              else {
                uVar5 = *(undefined4 *)((int)puVar9 + uVar10 + 8);
              }
              iVar3 = __cxa_type_match(param_2,uVar5,*puVar7 >> 0x1f,aiStack_2c);
              if (iVar3 == 0) {
                aiStack_2c[0] = 0;
              }
            }
            if (aiStack_2c[0] != 0) {
LAB_00008a00:
              FUN_0000862c(param_3,0,0xd,0,&uStack_30);
              *(uint **)(param_2 + 0x28) = puVar7;
              *(uint *)(param_2 + 0x20) = uStack_30;
              *(int *)(param_2 + 0x24) = aiStack_2c[0];
              return 6;
            }
          }
        }
        else {
          uVar10 = *(uint *)(param_2 + 0x20);
          FUN_0000862c(param_3,0,0xd,0,&uStack_30);
          if ((uVar10 == uStack_30) && (puVar7 == *(uint **)(param_2 + 0x28))) {
            uStack_30 = FUN_000086c4(puVar7);
            FUN_00008678(param_3,0,0xf,0,&uStack_30);
LAB_00008ac4:
            uVar5 = 0;
            uStack_30 = param_2;
            goto LAB_00008b80;
          }
        }
        puVar9 = puVar9 + 3;
      }
      if (uVar10 != 0) {
        if (uVar10 != 2) {
          return 9;
        }
        uVar10 = *puVar7 & 0x7fffffff;
        if (uVar8 == 0) {
          if ((bVar2) && ((param_1 & 8) == 0 || uVar10 == 0)) {
            uStack_58 = 0;
            puVar6 = puVar7;
            do {
              if (uStack_58 == uVar10) goto LAB_00008a00;
              puVar6 = puVar6 + 1;
              uStack_58 = uStack_58 + 1;
              uVar5 = 0;
              if (*puVar6 != 0) {
                uVar5 = *(undefined4 *)((int)puVar6 + *puVar6);
              }
              aiStack_2c[0] = iVar4;
              iVar3 = __cxa_type_match(param_2,uVar5,0,aiStack_2c);
            } while (iVar3 == 0);
          }
        }
        else {
          uVar12 = *(uint *)(param_2 + 0x20);
          FUN_0000862c(param_3,0,0xd,0,&uStack_30);
          if ((uVar12 == uStack_30) && (puVar7 == *(uint **)(param_2 + 0x28))) {
            *(uint **)(param_2 + 0x34) = puVar9 + 2;
            *(uint *)(param_2 + 0x28) = uVar10;
            *(undefined4 *)(param_2 + 0x2c) = 0;
            *(undefined4 *)(param_2 + 0x30) = 4;
            if (-1 < (int)*puVar7) {
              uStack_30 = FUN_000086c4(puVar7 + uVar10 + 1);
              FUN_00008678(param_3,0,0xf,0,&uStack_30);
              goto LAB_00008ac4;
            }
            bVar11 = true;
          }
        }
        if ((int)*puVar7 < 0) {
          puVar7 = puVar9 + 2;
        }
        puVar9 = puVar7 + uVar10 + 1;
        goto LAB_00008b00;
      }
      if (uVar8 == 0) {
        bVar2 = false;
      }
      puVar9 = puVar9 + 2;
    } while (!bVar2);
    uVar8 = FUN_000086c4(puVar7);
    *(uint **)(param_2 + 0x38) = puVar9;
    iVar4 = __cxa_begin_cleanup(param_2);
    if (iVar4 != 0) {
      uVar5 = 0xf;
      uStack_30 = uVar8;
      goto LAB_00008b80;
    }
  }
  else {
    bVar11 = false;
LAB_00008b0c:
    iVar4 = FUN_00009764(param_3,&iStack_3c);
    if (iVar4 == 0) {
      if (!bVar11) {
        return 8;
      }
      FUN_0000862c(param_3,0,0xf,0,&uStack_30);
      FUN_00008678(param_3,0,0xe,0,&uStack_30);
      uVar5 = 0xf;
      uStack_30 = *(uint *)(DAT_00008b98 + 0x8b70);
LAB_00008b80:
      FUN_00008678(param_3,0,uVar5,0,&uStack_30);
      return 7;
    }
  }
  return 9;
}



/* Function: FUN_00008bb4 @ 00008bb4 */

undefined4 FUN_00008bb4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int local_2c [2];
  
  iVar8 = DAT_00008d68 + 0x8bc8;
  uVar9 = param_2 - 2;
  if (*(int *)(iVar8 + DAT_00008d6c) == 0) {
    iVar2 = *(int *)(iVar8 + DAT_00008d74);
    local_2c[0] = *(int *)(iVar8 + DAT_00008d70) - iVar2 >> 3;
  }
  else {
    iVar2 = __gnu_Unwind_Find_exidx(uVar9,local_2c);
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0x10) = 0;
      return 9;
    }
  }
  if (local_2c[0] != 0) {
    iVar6 = local_2c[0] + -1;
    iVar11 = 0;
    iVar12 = iVar6;
    do {
      while( true ) {
        iVar1 = (iVar12 + iVar11) / 2;
        iVar10 = iVar2 + iVar1 * 8;
        uVar3 = FUN_000086c4(iVar10);
        uVar7 = 0xffffffff;
        if (iVar1 != iVar6) {
          iVar4 = FUN_000086c4(iVar2 + (iVar1 + 1) * 8);
          uVar7 = iVar4 - 1;
        }
        if (uVar3 <= uVar9) break;
        iVar12 = iVar1 + -1;
        if (iVar1 == iVar11) goto LAB_00008d40;
      }
      iVar11 = iVar1 + 1;
    } while (uVar7 < uVar9);
    if (iVar10 != 0) {
      uVar5 = FUN_000086c4(iVar10);
      *(undefined4 *)(param_1 + 0x48) = uVar5;
      if (*(int *)(iVar10 + 4) == 1) {
        *(undefined4 *)(param_1 + 0x10) = 0;
        return 5;
      }
      if (*(int *)(iVar10 + 4) < 0) {
        *(int *)(param_1 + 0x4c) = iVar10 + 4;
        *(undefined4 *)(param_1 + 0x50) = 1;
      }
      else {
        uVar5 = FUN_000086c4();
        *(undefined4 *)(param_1 + 0x50) = 0;
        *(undefined4 *)(param_1 + 0x4c) = uVar5;
      }
      if (-1 < (int)**(uint **)(param_1 + 0x4c)) {
        uVar5 = FUN_000086c4();
        *(undefined4 *)(param_1 + 0x10) = uVar5;
        return 0;
      }
      uVar9 = **(uint **)(param_1 + 0x4c) >> 0x18 & 0xf;
      iVar2 = DAT_00008d78;
      if (((uVar9 == 0) || (iVar2 = DAT_00008d7c, uVar9 == 1)) || (iVar2 = DAT_00008d80, uVar9 == 2)
         ) {
        *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar8 + iVar2);
        return 0;
      }
    }
  }
LAB_00008d40:
  *(undefined4 *)(param_1 + 0x10) = 0;
  return 9;
}



/* Function: FUN_00008d84 @ 00008d84 */

void FUN_00008d84(uint *param_1)

{
  if ((*param_1 & 1) == 0) {
    if ((*param_1 & 2) == 0) {
      FUN_00009504(param_1 + 0x12);
    }
    else {
      FUN_00009514();
    }
  }
  if ((*param_1 & 4) == 0) {
    FUN_00009524(param_1 + 0x34);
  }
  if ((*param_1 & 8) == 0) {
    FUN_00009534(param_1 + 0x6c);
  }
  if ((*param_1 & 0x10) != 0) {
    return;
  }
  FUN_000095bc(param_1 + 0x8c);
  return;
}



/* Function: FUN_00008df0 @ 00008df0 */

int FUN_00008df0(code *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 local_2c0;
  undefined4 local_2bc;
  undefined4 uStack_2b8;
  undefined4 uStack_2b4;
  undefined4 uStack_2b0;
  undefined4 local_2ac;
  undefined4 uStack_2a8;
  undefined4 uStack_2a4;
  undefined4 uStack_2a0;
  undefined4 local_29c;
  undefined4 uStack_298;
  undefined4 uStack_294;
  undefined4 uStack_290;
  undefined4 local_28c;
  undefined4 uStack_288;
  undefined4 uStack_284;
  undefined4 local_280;
  undefined1 auStack_80 [16];
  code *local_70;
  undefined1 *local_24 [2];
  
  *(undefined4 *)(param_3 + 0x40) = *(undefined4 *)(param_3 + 0x3c);
  local_2bc = *(undefined4 *)(param_3 + 4);
  uStack_2b8 = *(undefined4 *)(param_3 + 8);
  uStack_2b4 = *(undefined4 *)(param_3 + 0xc);
  uStack_2b0 = *(undefined4 *)(param_3 + 0x10);
  local_2ac = *(undefined4 *)(param_3 + 0x14);
  uStack_2a8 = *(undefined4 *)(param_3 + 0x18);
  uStack_2a4 = *(undefined4 *)(param_3 + 0x1c);
  uStack_2a0 = *(undefined4 *)(param_3 + 0x20);
  local_29c = *(undefined4 *)(param_3 + 0x24);
  uStack_298 = *(undefined4 *)(param_3 + 0x28);
  uStack_294 = *(undefined4 *)(param_3 + 0x2c);
  uStack_290 = *(undefined4 *)(param_3 + 0x30);
  local_28c = *(undefined4 *)(param_3 + 0x34);
  uStack_288 = *(undefined4 *)(param_3 + 0x38);
  uStack_284 = *(undefined4 *)(param_3 + 0x3c);
  local_280 = *(undefined4 *)(param_3 + 0x40);
  local_2c0 = 0xffffffff;
  do {
    iVar1 = FUN_00008bb4(auStack_80,local_280);
    if (iVar1 != 0) {
LAB_00008eac:
      iVar1 = 9;
      break;
    }
    local_24[0] = auStack_80;
    FUN_00008678(&local_2c0,0,0xc,0,local_24);
    iVar1 = (*param_1)(&local_2c0,param_2);
    if (iVar1 != 0) goto LAB_00008eac;
    iVar1 = (*local_70)(8,auStack_80,&local_2c0);
  } while (iVar1 != 9 && iVar1 != 5);
  FUN_00008d84(&local_2c0);
  return iVar1;
}



/* Function: FUN_00008ec4 @ 00008ec4 */

int FUN_00008ec4(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined1 auStack_4a8 [56];
  undefined4 local_470;
  undefined4 local_268;
  undefined4 local_264;
  undefined4 uStack_260;
  undefined4 uStack_25c;
  undefined4 uStack_258;
  undefined4 local_254;
  undefined4 uStack_250;
  undefined4 uStack_24c;
  undefined4 uStack_248;
  undefined4 local_244;
  undefined4 uStack_240;
  undefined4 uStack_23c;
  undefined4 uStack_238;
  undefined4 local_234;
  undefined4 local_230;
  undefined4 uStack_22c;
  undefined4 local_228;
  undefined4 local_224;
  
  local_264 = *(undefined4 *)(param_2 + 4);
  uStack_260 = *(undefined4 *)(param_2 + 8);
  uStack_25c = *(undefined4 *)(param_2 + 0xc);
  uStack_258 = *(undefined4 *)(param_2 + 0x10);
  local_254 = *(undefined4 *)(param_2 + 0x14);
  uStack_250 = *(undefined4 *)(param_2 + 0x18);
  uStack_24c = *(undefined4 *)(param_2 + 0x1c);
  uStack_248 = *(undefined4 *)(param_2 + 0x20);
  local_244 = *(undefined4 *)(param_2 + 0x24);
  uStack_240 = *(undefined4 *)(param_2 + 0x28);
  uStack_23c = *(undefined4 *)(param_2 + 0x2c);
  uStack_238 = *(undefined4 *)(param_2 + 0x30);
  local_234 = *(undefined4 *)(param_2 + 0x34);
  local_230 = *(undefined4 *)(param_2 + 0x38);
  uStack_22c = *(undefined4 *)(param_2 + 0x3c);
  local_228 = *(undefined4 *)(param_2 + 0x40);
  iVar3 = 0;
  pcVar4 = *(code **)(param_1 + 0xc);
  uVar6 = *(undefined4 *)(param_1 + 0x18);
  local_268 = 0;
  do {
    iVar1 = FUN_00008bb4(param_1,local_228);
    if (param_3 == 0) {
      uVar5 = 9;
    }
    else {
      uVar5 = 10;
    }
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x14) = local_228;
      memcpy(auStack_4a8,&local_268,0x240);
      iVar3 = (**(code **)(param_1 + 0x10))(uVar5,param_1,auStack_4a8);
      local_224 = local_470;
    }
    else {
      uVar5 = uVar5 | 0x10;
      local_224 = local_230;
    }
    iVar2 = (*pcVar4)(1,uVar5,param_1,param_1,&local_268,uVar6);
    if (iVar2 != 0) {
      return 9;
    }
    if (iVar1 != 0) {
      return iVar1;
    }
    memcpy(&local_268,auStack_4a8,0x240);
    param_3 = 0;
  } while (iVar3 == 8);
  if (iVar3 == 7) {
    FUN_000094f0(&local_264);
  }
  return 9;
}



/* Function: FUN_00008ffc @ 00008ffc */

void FUN_00008ffc(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 local_268;
  undefined4 local_264;
  undefined4 uStack_260;
  undefined4 uStack_25c;
  undefined4 uStack_258;
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
  undefined4 local_228;
  int iStack_24;
  int iStack_20;
  
  do {
    iVar1 = FUN_00008bb4(param_1,*(undefined4 *)(param_2 + 0x40));
    if (iVar1 != 0) goto LAB_00009048;
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_2 + 0x40);
    iVar1 = (**(code **)(param_1 + 0x10))(1,param_1,param_2);
  } while (iVar1 == 8);
  if (iVar1 != 7) {
LAB_00009048:
                    /* WARNING: Subroutine does not return */
    abort();
  }
  uVar4 = FUN_000094f0(param_2 + 4);
  iVar3 = (int)((ulonglong)uVar4 >> 0x20);
  iVar1 = (int)uVar4;
  *(undefined4 *)(iVar3 + 0x40) = *(undefined4 *)(iVar3 + 0x3c);
  local_264 = *(undefined4 *)(iVar3 + 4);
  uStack_260 = *(undefined4 *)(iVar3 + 8);
  uStack_25c = *(undefined4 *)(iVar3 + 0xc);
  uStack_258 = *(undefined4 *)(iVar3 + 0x10);
  local_254 = *(undefined4 *)(iVar3 + 0x14);
  uStack_250 = *(undefined4 *)(iVar3 + 0x18);
  uStack_24c = *(undefined4 *)(iVar3 + 0x1c);
  uStack_248 = *(undefined4 *)(iVar3 + 0x20);
  local_244 = *(undefined4 *)(iVar3 + 0x24);
  uStack_240 = *(undefined4 *)(iVar3 + 0x28);
  uStack_23c = *(undefined4 *)(iVar3 + 0x2c);
  uStack_238 = *(undefined4 *)(iVar3 + 0x30);
  local_234 = *(undefined4 *)(iVar3 + 0x34);
  uStack_230 = *(undefined4 *)(iVar3 + 0x38);
  uStack_22c = *(undefined4 *)(iVar3 + 0x3c);
  local_228 = *(undefined4 *)(iVar3 + 0x40);
  local_268 = 0xffffffff;
  iStack_24 = param_2;
  iStack_20 = param_1;
  do {
    iVar2 = FUN_00008bb4(iVar1,local_228);
    if (iVar2 != 0) goto LAB_000090ec;
    iVar2 = (**(code **)(iVar1 + 0x10))(0,iVar1,&local_268);
  } while (iVar2 == 8);
  FUN_00008d84(&local_268);
  if (iVar2 == 6) {
    FUN_00008ffc(iVar1,iVar3);
  }
LAB_000090ec:
                    /* WARNING: Could not recover jumptable at 0x000090f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)0x9054)(9);
  return;
}



/* Function: FUN_00009184 @ 00009184 */

undefined4 FUN_00009184(uint *param_1,undefined4 param_2,uint param_3,int param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  bool bVar8;
  bool bVar9;
  undefined4 auStack_1b8 [34];
  undefined4 auStack_130 [32];
  undefined4 local_b0 [32];
  undefined4 local_30 [5];
  
  switch(param_2) {
  case 0:
    if (param_4 != 0) {
      return 2;
    }
    puVar1 = (uint *)param_1[0xe];
    uVar6 = 0;
    do {
      if ((param_3 & 0xffff & 1 << (uVar6 & 0xff)) != 0) {
        param_1[uVar6 + 1] = *puVar1;
        puVar1 = puVar1 + 1;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 != 0x10);
    if ((param_3 & 0x2000) != 0) {
      return 0;
    }
    param_1[0xe] = (uint)puVar1;
    return 0;
  case 1:
    if (param_4 != 1 && param_4 != 5) {
      return 2;
    }
    uVar6 = param_3 & 0xffff;
    param_3 = param_3 >> 0x10;
    if (param_4 == 1) {
      uVar3 = 0x10;
    }
    else {
      uVar3 = 0x20;
    }
    uVar2 = uVar6 + param_3;
    if (uVar3 < uVar2) {
      return 2;
    }
    bVar8 = param_4 == 1;
    if (param_3 >= 0x10 && bVar8) {
      return 2;
    }
    uVar3 = uVar6;
    if ((param_3 < 0x10) && (uVar3 = 0, 0x10 < uVar2)) {
      uVar3 = uVar2 - 0x10;
    }
    if (uVar3 != 0 && param_4 != 5) {
      return 2;
    }
    if ((param_3 < 0x10) && (uVar2 = *param_1, (uVar2 & 1) != 0)) {
      *param_1 = uVar2 & 0xfffffffe;
      if (param_4 == 5) {
        *param_1 = uVar2 & 0xfffffffe | 2;
        FUN_0000951c();
      }
      else {
        *param_1 = uVar2 & 0xfffffffc;
        FUN_0000950c(param_1 + 0x12);
      }
    }
    if ((0 < (int)uVar3) && ((*param_1 & 4) != 0)) {
      *param_1 = *param_1 & 0xfffffffb;
      FUN_0000952c(param_1 + 0x34);
    }
    if (bVar8) {
      FUN_0000950c(auStack_1b8);
    }
    else {
      if (param_3 < 0x10) {
        FUN_0000951c(auStack_1b8);
      }
      if (uVar3 == 0) goto LAB_00009320;
      FUN_0000952c(local_b0);
    }
    if (0 < (int)uVar3) {
      uVar6 = 0x10 - param_3;
    }
LAB_00009320:
    uVar2 = param_1[0xe];
    if (0 < (int)uVar6) {
      iVar7 = uVar6 * 2;
      iVar5 = 0;
      while (bVar9 = iVar7 != 0, iVar7 = iVar7 + -1, bVar9) {
        *(undefined4 *)((int)auStack_1b8 + iVar5 + param_3 * 8) = *(undefined4 *)(iVar5 + uVar2);
        iVar5 = iVar5 + 4;
      }
      uVar2 = uVar2 + uVar6 * 8;
    }
    if (0 < (int)uVar3) {
      uVar6 = param_3;
      if (param_3 < 0x10) {
        uVar6 = 0x10;
      }
      iVar7 = uVar3 * 2;
      iVar5 = 0;
      while (bVar9 = iVar7 != 0, iVar7 = iVar7 + -1, bVar9) {
        *(undefined4 *)((int)local_b0 + iVar5 + (uVar6 - 0x10) * 8) = *(undefined4 *)(uVar2 + iVar5)
        ;
        iVar5 = iVar5 + 4;
      }
      uVar2 = uVar2 + uVar3 * 8;
    }
    if (bVar8) {
      uVar2 = uVar2 + 4;
    }
    param_1[0xe] = uVar2;
    if (bVar8) {
      FUN_00009504(auStack_1b8);
    }
    else {
      if (param_3 < 0x10) {
        FUN_00009514(auStack_1b8);
      }
      if (0 < (int)uVar3) {
        FUN_00009524(local_b0);
      }
    }
    return 0;
  case 2:
    return 1;
  case 3:
    if (param_4 == 3) {
      uVar6 = param_3 & 0xffff;
      if (uVar6 + (param_3 >> 0x10) < 0x11) {
        if ((*param_1 & 8) != 0) {
          *param_1 = *param_1 & 0xfffffff7;
          FUN_00009578(param_1 + 0x6c);
        }
        FUN_00009578(auStack_130);
        uVar3 = param_1[0xe];
        iVar5 = 0;
        for (iVar7 = uVar6 * 2; iVar7 != 0; iVar7 = iVar7 + -1) {
          *(undefined4 *)((int)auStack_130 + iVar5 + (param_3 >> 0x10) * 8) =
               *(undefined4 *)(iVar5 + uVar3);
          iVar5 = iVar5 + 4;
        }
        param_1[0xe] = uVar3 + uVar6 * 8;
        FUN_00009534(auStack_130);
        return 0;
      }
    }
    break;
  case 4:
    bVar8 = param_3 == 0x10;
    if (param_3 < 0x11) {
      bVar8 = param_4 == 0;
    }
    if (bVar8) {
      if ((*param_1 & 0x10) != 0) {
        *param_1 = *param_1 & 0xffffffef;
        FUN_000095d0(param_1 + 0x8c);
      }
      FUN_000095d0(local_30);
      puVar4 = (undefined4 *)param_1[0xe];
      uVar6 = 0;
      do {
        if ((param_3 & 1 << (uVar6 & 0xff)) != 0) {
          local_30[uVar6] = *puVar4;
          puVar4 = puVar4 + 1;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 != 4);
      param_1[0xe] = (uint)puVar4;
      FUN_000095bc(local_30);
      return 0;
    }
  }
  return 2;
}



/* Function: FUN_000094f0 @ 000094f0 */

undefined8 FUN_000094f0(undefined8 *param_1)

{
  return *param_1;
}



/* Function: FUN_00009504 @ 00009504 */

undefined4 FUN_00009504(undefined8 *param_1)

{
  return (int)*param_1;
}



/* Function: FUN_0000950c @ 0000950c */

void FUN_0000950c(undefined8 *param_1)

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



/* Function: FUN_00009514 @ 00009514 */

undefined4 FUN_00009514(undefined8 *param_1)

{
  return (int)*param_1;
}



/* Function: FUN_0000951c @ 0000951c */

void FUN_0000951c(undefined8 *param_1)

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



/* Function: FUN_00009524 @ 00009524 */

void FUN_00009524(void)

{
  return;
}



/* Function: FUN_0000952c @ 0000952c */

void FUN_0000952c(undefined8 *param_1)

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



/* Function: FUN_00009534 @ 00009534 */

int FUN_00009534(int param_1)

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



/* Function: FUN_00009578 @ 00009578 */

int FUN_00009578(int param_1)

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



/* Function: FUN_000095bc @ 000095bc */

int FUN_000095bc(int param_1)

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



/* Function: FUN_000095d0 @ 000095d0 */

int FUN_000095d0(int param_1)

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



/* Function: FUN_00009698 @ 00009698 */

uint FUN_00009698(uint *param_1)

{
  uint uVar1;
  char cVar2;
  
  if ((char)param_1[2] == '\0') {
    if (*(char *)((int)param_1 + 9) == '\0') {
      return 0xb0;
    }
    *(char *)((int)param_1 + 9) = *(char *)((int)param_1 + 9) + -1;
    *param_1 = *(uint *)param_1[1];
    param_1[1] = (uint)((uint *)param_1[1] + 1);
    cVar2 = '\x03';
  }
  else {
    cVar2 = (char)param_1[2] + -1;
  }
  uVar1 = *param_1;
  *(char *)(param_1 + 2) = cVar2;
  *param_1 = uVar1 << 8;
  return uVar1 >> 0x18;
}



/* Function: FUN_000096f0 @ 000096f0 */

void FUN_000096f0(void)

{
                    /* WARNING: Subroutine does not return */
  abort();
}



/* Function: FUN_00009738 @ 00009738 */

undefined4 FUN_00009738(void)

{
  int in_r3;
  
  FUN_0000862c();
  return *(undefined4 *)(in_r3 + 0x48);
}



/* Function: FUN_00009764 @ 00009764 */

undefined4 FUN_00009764(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

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
LAB_0000977c:
  do {
    while( true ) {
      uVar1 = FUN_00009698(param_2);
      if (uVar1 == 0xb0) {
        if (bVar4) {
          return 0;
        }
        FUN_0000862c(param_1,0,0xe,0,&local_24,uVar7,param_3);
        FUN_00008678(param_1,0,0xf,0,&local_24);
        return 0;
      }
      if ((uVar1 & 0x80) != 0) break;
      FUN_0000862c(param_1,0,0xd,0,&local_24,uVar7,param_3);
      iVar5 = (uVar1 & 0x3f) * 4 + 4;
      if ((uVar1 & 0x40) != 0) {
        iVar5 = -iVar5;
      }
      local_24 = local_24 + iVar5;
LAB_000098b4:
      piVar6 = &local_24;
      FUN_00008678(param_1,0,0xd,0);
    }
    uVar3 = uVar1 & 0xf0;
    if (uVar3 == 0x80) {
      uVar3 = FUN_00009698(param_2);
      uVar3 = uVar3 | uVar1 << 8;
      if (uVar3 == 0x8000) {
        return 9;
      }
      iVar5 = FUN_00009184(param_1,0,(uVar3 & 0xfff) << 4,0,piVar6);
      if (iVar5 != 0) {
        return 9;
      }
      if ((uVar3 & 0x800) != 0) {
        bVar4 = true;
      }
      goto LAB_0000977c;
    }
    if (uVar3 == 0x90) {
      uVar1 = uVar1 & 0xf;
      if (uVar1 == 0xd || uVar1 == 0xf) {
        return 9;
      }
      FUN_0000862c(param_1,0,uVar1,0,&local_24,uVar7,param_3);
      goto LAB_000098b4;
    }
    if (uVar3 == 0xa0) {
      uVar2 = 0;
    }
    else if (uVar3 == 0xb0) {
      if (uVar1 == 0xb1) {
        uVar1 = FUN_00009698(param_2);
        if (uVar1 == 0) {
          return 9;
        }
        uVar2 = 0;
        if ((uVar1 & 0xf0) != 0) {
          return 9;
        }
      }
      else {
        if (uVar1 == 0xb2) {
          uVar1 = 2;
          FUN_0000862c(param_1,0,0xd,0,&local_24,uVar7,param_3);
          while( true ) {
            uVar3 = FUN_00009698(param_2);
            if ((uVar3 & 0x80) == 0) break;
            local_24 = local_24 + ((uVar3 & 0x7f) << (uVar1 & 0xff));
            uVar1 = uVar1 + 7;
          }
          local_24 = local_24 + 0x204 + ((uVar3 & 0x7f) << (uVar1 & 0xff));
          goto LAB_000098b4;
        }
        if (uVar1 == 0xb3) {
          FUN_00009698(param_2);
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
        FUN_00009698(param_2);
        uVar2 = 3;
      }
      else if (uVar1 == 199) {
        uVar1 = FUN_00009698(param_2);
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
            FUN_00009698(param_2);
          }
          else {
            if (uVar1 != 0xc9) {
              return 9;
            }
            FUN_00009698(param_2);
          }
          goto LAB_00009ab8;
        }
        uVar2 = 3;
      }
    }
    else {
      if ((uVar1 & 0xf8) != 0xd0) {
        return 9;
      }
LAB_00009ab8:
      uVar2 = 1;
    }
    iVar5 = FUN_00009184(param_1,uVar2);
    if (iVar5 != 0) {
      return 9;
    }
  } while( true );
}



/* Function: FUN_00009adc @ 00009adc */

void FUN_00009adc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  FUN_00009764(param_2,&local_14,*(undefined1 *)(iVar1 + 7),local_10,param_1);
  return;
}



/* Function: __cxa_begin_cleanup @ 0000b000 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_begin_cleanup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_call_unexpected @ 0000b004 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_call_unexpected(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: memcpy @ 0000b008 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: system @ 0000b00c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int system(char *__command)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: abort @ 0000b010 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __libc_init @ 0000b014 */

/* WARNING: Control flow encountered bad instruction data */

void __libc_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_type_match @ 0000b018 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_type_match(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: setresuid @ 0000b01c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int setresuid(__uid_t __ruid,__uid_t __euid,__uid_t __suid)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __gnu_Unwind_Find_exidx @ 0000b020 */

/* WARNING: Control flow encountered bad instruction data */

void __gnu_Unwind_Find_exidx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: setresgid @ 0000b024 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int setresgid(__gid_t __rgid,__gid_t __egid,__gid_t __sgid)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



