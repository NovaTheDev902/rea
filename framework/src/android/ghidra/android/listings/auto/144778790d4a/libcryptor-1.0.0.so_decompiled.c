/* Function: strcpy @ 00010670 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strcpy_00015728)(__dest);
  return pcVar1;
}



/* Function: __cxa_begin_cleanup @ 0001067c */

void __cxa_begin_cleanup(void)

{
  (*(code *)PTR___cxa_begin_cleanup_0001572c)();
  return;
}



/* Function: memcpy @ 00010688 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memcpy_00015730)(__dest);
  return pvVar1;
}



/* Function: getuid @ 000106a0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__uid_t getuid(void)

{
  __uid_t _Var1;
  
  _Var1 = (*(code *)PTR_getuid_00015738)();
  return _Var1;
}



/* Function: malloc @ 000106ac */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_malloc_0001573c)(__size);
  return pvVar1;
}



/* Function: abort @ 000106b8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
  (*(code *)PTR_abort_00015740)();
  return;
}



/* Function: __stack_chk_fail @ 000106c4 */

void __stack_chk_fail(void)

{
  (*(code *)PTR___stack_chk_fail_00015744)();
  return;
}



/* Function: __cxa_type_match @ 000106d0 */

void __cxa_type_match(void)

{
  (*(code *)PTR___cxa_type_match_00015748)();
  return;
}



/* Function: memset @ 000106dc */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memset_0001574c)(__s);
  return pvVar1;
}



/* Function: strcmp @ 000106e8 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strcmp_00015750)(__s1);
  return iVar1;
}



/* Function: __gnu_Unwind_Find_exidx @ 000106f4 */

void __gnu_Unwind_Find_exidx(void)

{
  (*(code *)PTR___gnu_Unwind_Find_exidx_00015754)();
  return;
}



/* Function: sprintf @ 00010700 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_sprintf_00015758)(__s);
  return iVar1;
}



/* Function: raise @ 0001070c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int raise(int __sig)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_raise_0001575c)(__sig);
  return iVar1;
}



/* Function: free @ 00010718 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
  (*(code *)PTR_free_00015760)(__ptr);
  return;
}



/* Function: entry @ 00010724 */

void processEntry entry(void)

{
  (*(code *)PTR___cxa_finalize_00015734)(DAT_00010730);
  return;
}



/* Function: FUN_00010734 @ 00010734 */

void FUN_00010734(int *param_1)

{
  (**(code **)(*param_1 + 0x2ac))();
  return;
}



/* Function: FUN_00010744 @ 00010744 */

undefined4 FUN_00010744(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = (**(code **)(*param_1 + 0x18))(param_1,DAT_0001077c + 0x10752);
  iVar2 = (**(code **)(*param_1 + 0x3c))(param_1);
  if (iVar2 == 0) {
    uVar1 = (**(code **)(*param_1 + 0x35c))(param_1,uVar1,DAT_00010780 + 0x10774,3);
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



/* Function: Java_com_tencent_tccdb_TccCryptor_decrypt @ 00010784 */

undefined4
Java_com_tencent_tccdb_TccCryptor_decrypt
          (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  char *__dest;
  void *__ptr;
  undefined4 uVar3;
  undefined4 local_2c;
  
  iVar1 = FUN_00010ee8();
  if (iVar1 != 0) {
    iVar1 = FUN_00010734(param_1,param_4);
    uVar2 = (**(code **)(*param_1 + 0x2e0))(param_1,param_4,0);
    if (param_5 == 0) {
      __dest = malloc(0x16);
      strcpy(__dest,(char *)(DAT_00010874 + 0x107c4));
      local_2c = 0x15;
    }
    else {
      local_2c = FUN_00010734(param_1,param_5);
      __dest = (char *)(**(code **)(*param_1 + 0x2e0))(param_1,param_5,0);
    }
    __ptr = malloc(iVar1 + 8U);
    uVar3 = FUN_00012344(uVar2,iVar1,__dest,local_2c,__ptr,iVar1 + 8U);
    if (param_5 == 0) {
      free(__dest);
    }
    else {
      (**(code **)(*param_1 + 0x300))(param_1,param_5,__dest,0);
    }
    (**(code **)(*param_1 + 0x300))(param_1,param_4,uVar2,0);
    uVar2 = (**(code **)(*param_1 + 0x2c0))(param_1,uVar3);
    iVar1 = (**(code **)(*param_1 + 0x3c))(param_1);
    if (iVar1 == 0) {
      (**(code **)(*param_1 + 0x340))(param_1,uVar2,0,uVar3,__ptr);
      free(__ptr);
      return uVar2;
    }
  }
  return 0;
}



/* Function: Java_com_tencent_tccdb_TccCryptor_encrypt @ 00010878 */

undefined4
Java_com_tencent_tccdb_TccCryptor_encrypt
          (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  char *__dest;
  void *__ptr;
  undefined4 uVar3;
  undefined4 local_2c;
  
  iVar1 = FUN_00010ee8();
  if (iVar1 != 0) {
    iVar1 = FUN_00010734(param_1,param_4);
    uVar2 = (**(code **)(*param_1 + 0x2e0))(param_1,param_4,0);
    if (param_5 == 0) {
      __dest = malloc(0x16);
      strcpy(__dest,(char *)(DAT_00010968 + 0x108b8));
      local_2c = 0x15;
    }
    else {
      local_2c = FUN_00010734(param_1,param_5);
      __dest = (char *)(**(code **)(*param_1 + 0x2e0))(param_1,param_5,0);
    }
    __ptr = malloc(iVar1 + 8U);
    uVar3 = FUN_000124c8(uVar2,iVar1,__dest,local_2c,__ptr,iVar1 + 8U);
    if (param_5 == 0) {
      free(__dest);
    }
    else {
      (**(code **)(*param_1 + 0x300))(param_1,param_5,__dest,0);
    }
    (**(code **)(*param_1 + 0x300))(param_1,param_4,uVar2,0);
    uVar2 = (**(code **)(*param_1 + 0x2c0))(param_1,uVar3);
    iVar1 = (**(code **)(*param_1 + 0x3c))(param_1);
    if (iVar1 == 0) {
      (**(code **)(*param_1 + 0x340))(param_1,uVar2,0,uVar3,__ptr);
      free(__ptr);
      return uVar2;
    }
  }
  return 0;
}



/* Function: Java_com_tencent_tccdb_TccCryptor_makePassword @ 0001096c */

void Java_com_tencent_tccdb_TccCryptor_makePassword
               (int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  char *__dest;
  undefined4 uVar2;
  int local_34;
  undefined1 auStack_2c [16];
  int local_1c;
  
  local_1c = **(int **)(DAT_00010a3c + 0x1097a);
  iVar1 = FUN_00010ee8();
  if (iVar1 != 0) {
    if (param_4 == 0) {
      __dest = malloc(0x16);
      strcpy(__dest,(char *)(DAT_00010a40 + 0x10998));
      local_34 = 0x15;
    }
    else {
      local_34 = FUN_00010734(param_1,param_4);
      __dest = (char *)(**(code **)(*param_1 + 0x2e0))(param_1,param_4,0);
    }
    FUN_0001217c(__dest,local_34,auStack_2c);
    if (param_4 == 0) {
      free(__dest);
    }
    else {
      (**(code **)(*param_1 + 0x300))(param_1,param_4,__dest,0);
    }
    if (0x10 < local_34) {
      local_34 = 0x10;
    }
    uVar2 = (**(code **)(*param_1 + 0x2c0))(param_1,local_34);
    iVar1 = (**(code **)(*param_1 + 0x3c))(param_1);
    if (iVar1 == 0) {
      (**(code **)(*param_1 + 0x340))(param_1,uVar2,0,local_34,auStack_2c);
      goto LAB_00010a22;
    }
  }
  uVar2 = 0;
LAB_00010a22:
  if (local_1c != **(int **)(DAT_00010a44 + 0x10a2c)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



/* Function: FUN_00010a48 @ 00010a48 */

void FUN_00010a48(int *param_1)

{
  (**(code **)(*param_1 + 0x3c))();
  return;
}



/* Function: FUN_00010a54 @ 00010a54 */

void FUN_00010a54(int *param_1)

{
  (**(code **)(*param_1 + 0x7c))();
  return;
}



/* Function: FUN_00010a60 @ 00010a60 */

void FUN_00010a60(int *param_1)

{
  (**(code **)(*param_1 + 0x84))();
  return;
}



/* Function: FUN_00010af0 @ 00010af0 */

void FUN_00010af0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*param_1 + 0xf8))(param_1,param_2,param_3);
  return;
}



/* Function: FUN_00010b10 @ 00010b10 */

void FUN_00010b10(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_00010a54();
  iVar2 = FUN_00010a60(param_1,uVar1,DAT_00010b48 + 0x10b26,DAT_00010b4c + 0x10b28,param_4);
  if (iVar2 != 0) {
    FUN_00010af0(param_1,param_2,iVar2,param_3);
  }
  (**(code **)(*param_1 + 0x5c))(param_1,uVar1);
  return;
}



/* Function: FUN_00010b50 @ 00010b50 */

void FUN_00010b50(int *param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*param_1 + 0x8c))(param_1,param_2,param_3);
  return;
}



/* Function: FUN_00010b70 @ 00010b70 */

void FUN_00010b70(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  __uid_t _Var2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  char *__format;
  byte *pbVar13;
  int iVar14;
  int local_84;
  int local_80;
  char *local_78;
  char acStack_50 [32];
  undefined1 local_30;
  byte local_2c [16];
  int local_1c [2];
  
  uVar1 = 1;
  local_1c[0] = **(int **)(DAT_00010e88 + 0x10b7c);
  if (*(char *)(DAT_00010e8c + 0x10b8a) == '\0') {
    _Var2 = getuid();
    uVar1 = FUN_00010a54(param_1,param_2);
    iVar3 = FUN_00010a48(param_1);
    if (iVar3 == 0) {
      uVar1 = FUN_00010a60(param_1,uVar1,DAT_00010e90 + 0x10bb6,DAT_00010e94 + 0x10bb8);
      iVar3 = FUN_00010a48(param_1);
      if (iVar3 == 0) {
        uVar1 = FUN_00010b50(param_1,param_2,uVar1);
        iVar3 = FUN_00010a48(param_1);
        if (iVar3 == 0) {
          uVar4 = FUN_00010a54(param_1,uVar1);
          iVar3 = FUN_00010a48(param_1);
          if (iVar3 == 0) {
            uVar5 = FUN_00010a60(param_1,uVar4,DAT_00010e98 + 0x10c02,DAT_00010e9c + 0x10c04);
            iVar3 = FUN_00010a48(param_1);
            if (iVar3 == 0) {
              uVar5 = FUN_00010b50(param_1,uVar1,uVar5,_Var2);
              iVar3 = FUN_00010a48(param_1);
              if (iVar3 == 0) {
                iVar3 = (**(code **)(*param_1 + 0x2ac))(param_1,uVar5);
                __format = (char *)(DAT_00010ea0 + 0x10c48);
                for (local_80 = 0; local_80 < iVar3; local_80 = local_80 + 1) {
                  uVar6 = (**(code **)(*param_1 + 0x2b4))(param_1,uVar5,local_80);
                  iVar7 = FUN_00010a48(param_1);
                  if (iVar7 != 0) break;
                  uVar8 = (**(code **)(*param_1 + 0x2a4))(param_1,uVar6,0);
                  (**(code **)(*param_1 + 0x2a8))(param_1,uVar6,uVar8);
                  uVar8 = FUN_00010a60(param_1,uVar4,DAT_00010ea4 + 0x10c94,DAT_00010ea8 + 0x10c96);
                  iVar7 = FUN_00010a48(param_1);
                  if (iVar7 != 0) break;
                  uVar6 = FUN_00010b50(param_1,uVar1,uVar8,uVar6,0x40);
                  iVar7 = FUN_00010a48(param_1);
                  if (iVar7 != 0) break;
                  uVar8 = FUN_00010a54(param_1,uVar6);
                  iVar7 = FUN_00010a48(param_1);
                  if (iVar7 != 0) break;
                  uVar8 = (**(code **)(*param_1 + 0x178))
                                    (param_1,uVar8,DAT_00010eac + 0x10cea,DAT_00010eb0 + 0x10cec);
                  iVar7 = FUN_00010a48(param_1);
                  if (iVar7 != 0) break;
                  uVar6 = (**(code **)(*param_1 + 0x17c))(param_1,uVar6,uVar8);
                  iVar7 = FUN_00010a48(param_1);
                  if (iVar7 != 0) break;
                  iVar7 = (**(code **)(*param_1 + 0x2ac))(param_1,uVar6);
                  for (local_84 = 0; local_84 < iVar7; local_84 = local_84 + 1) {
                    uVar8 = (**(code **)(*param_1 + 0x2b4))(param_1,uVar6,local_84);
                    iVar9 = FUN_00010a48(param_1);
                    if (iVar9 != 0) goto LAB_00010e70;
                    uVar10 = FUN_00010a54(param_1,uVar8);
                    iVar9 = FUN_00010a48(param_1);
                    if (iVar9 != 0) goto LAB_00010e70;
                    uVar10 = FUN_00010a60(param_1,uVar10,DAT_00010eb4 + 0x10d70,
                                          DAT_00010eb8 + 0x10d72);
                    iVar9 = FUN_00010a48(param_1);
                    if (iVar9 != 0) goto LAB_00010e70;
                    uVar8 = FUN_00010b50(param_1,uVar8,uVar10);
                    iVar9 = FUN_00010a48(param_1);
                    if (iVar9 != 0) goto LAB_00010e70;
                    uVar10 = (**(code **)(*param_1 + 0x2e0))(param_1,uVar8,0);
                    uVar11 = (**(code **)(*param_1 + 0x2ac))(param_1,uVar8);
                    memset(local_2c,0,0x10);
                    iVar9 = DAT_00010ebc;
                    FUN_00011d40(uVar10,uVar11,local_2c);
                    iVar14 = 0;
                    do {
                      local_78 = acStack_50;
                      pbVar13 = local_2c;
                      do {
                        sprintf(local_78,__format,(uint)*pbVar13);
                        pbVar13 = pbVar13 + 1;
                        local_78 = local_78 + 2;
                      } while (pbVar13 != (byte *)local_1c);
                      local_30 = 0;
                      iVar12 = strcmp(acStack_50,(char *)(iVar9 + 0x10dd8 + iVar14 * 0x21));
                      if (iVar12 == 0) {
                        (**(code **)(*param_1 + 0x300))(param_1,uVar8,uVar10,0);
                        uVar1 = 1;
                        *(undefined1 *)(DAT_00010ec0 + 0x10e26) = 1;
                        goto LAB_00010e72;
                      }
                      iVar14 = iVar14 + 1;
                    } while (iVar14 != 0xb);
                    (**(code **)(*param_1 + 0x300))(param_1,uVar8,uVar10,0);
                  }
                }
              }
            }
          }
        }
      }
    }
LAB_00010e70:
    uVar1 = 0;
  }
LAB_00010e72:
  if (local_1c[0] == **(int **)(DAT_00010ec4 + 0x10e7a)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar1);
}



/* Function: FUN_00010ec8 @ 00010ec8 */

void FUN_00010ec8(int *param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*param_1 + 0x1d8))(param_1,param_2,param_3);
  return;
}



/* Function: FUN_00010ee8 @ 00010ee8 */

bool FUN_00010ee8(int *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = (**(code **)(*param_1 + 0x18))(param_1,DAT_00010f20 + 0x10ef6);
  uVar2 = (**(code **)(*param_1 + 0x1c4))
                    (param_1,uVar1,DAT_00010f24 + 0x10f0e,DAT_00010f28 + 0x10f08);
  iVar3 = FUN_00010ec8(param_1,uVar1,uVar2);
  return iVar3 == 1;
}



/* Function: FUN_00010f2c @ 00010f2c */

void FUN_00010f2c(undefined1 *param_1,undefined1 *param_2)

{
  *param_2 = param_1[3];
  param_2[1] = param_1[2];
  param_2[2] = param_1[1];
  param_2[3] = *param_1;
  return;
}



/* Function: FUN_00010f40 @ 00010f40 */

void FUN_00010f40(undefined4 param_1,undefined1 *param_2)

{
  *param_2 = (char)((uint)param_1 >> 0x18);
  param_2[1] = (char)((uint)param_1 >> 0x10);
  param_2[2] = (char)((uint)param_1 >> 8);
  param_2[3] = (char)param_1;
  return;
}



/* Function: FUN_00010f50 @ 00010f50 */

void FUN_00010f50(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  
  uVar1 = 0;
  do {
    uVar3 = 7;
    uVar2 = 0;
    uVar5 = uVar1;
    while( true ) {
      if ((uVar5 & 1) != 0) {
        uVar2 = uVar2 | 1 << (uVar3 & 0xff);
      }
      bVar6 = uVar3 == 0;
      uVar3 = uVar3 - 1;
      if (bVar6) break;
      uVar5 = uVar5 >> 1;
    }
    uVar2 = uVar2 << 0x18;
    *param_1 = uVar2;
    iVar4 = 0;
    do {
      uVar5 = 0;
      if ((int)uVar2 < 0) {
        uVar5 = DAT_00010fb0;
      }
      iVar4 = iVar4 + 1;
      uVar2 = uVar5 ^ uVar2 << 1;
    } while (iVar4 != 8);
    *param_1 = uVar2;
    uVar5 = 0x1f;
    uVar3 = 0;
    while( true ) {
      if ((uVar2 & 1) != 0) {
        uVar3 = uVar3 | 1 << (uVar5 & 0xff);
      }
      bVar6 = uVar5 == 0;
      uVar5 = uVar5 - 1;
      if (bVar6) break;
      uVar2 = uVar2 >> 1;
    }
    uVar1 = uVar1 + 1;
    *param_1 = uVar3;
    param_1 = param_1 + 1;
  } while (uVar1 != 0x100);
  return;
}



/* Function: FUN_00010fe0 @ 00010fe0 */

void FUN_00010fe0(int param_1,int *param_2,int param_3)

{
  int iVar1;
  uint local_20;
  uint local_1c [2];
  
  local_1c[0] = 0;
  local_20 = 0;
  FUN_00010f2c(param_1,local_1c);
  FUN_00010f2c(param_1 + 4,&local_20);
  iVar1 = 0;
  do {
    iVar1 = iVar1 + DAT_00011054;
    local_1c[0] = (local_20 * 0x10 + *param_2 ^ (local_20 >> 5) + param_2[1] ^ iVar1 + local_20) +
                  local_1c[0];
    local_20 = (param_2[3] + (local_1c[0] >> 5) ^ local_1c[0] * 0x10 + param_2[2] ^
               local_1c[0] + iVar1) + local_20;
  } while (iVar1 != DAT_00011050);
  FUN_00010f40(local_1c[0],param_3);
  FUN_00010f40(local_20,param_3 + 4);
  return;
}



/* Function: FUN_00011058 @ 00011058 */

void FUN_00011058(int param_1,int *param_2,int param_3)

{
  int iVar1;
  uint local_20;
  uint local_1c [2];
  
  local_1c[0] = 0;
  local_20 = 0;
  FUN_00010f2c(param_1,local_1c);
  FUN_00010f2c(param_1 + 4,&local_20);
  iVar1 = DAT_000110c4;
  do {
    local_20 = local_20 -
               (local_1c[0] * 0x10 + param_2[2] ^ (local_1c[0] >> 5) + param_2[3] ^
               iVar1 + local_1c[0]);
    local_1c[0] = local_1c[0] -
                  ((local_20 >> 5) + param_2[1] ^ local_20 * 0x10 + *param_2 ^ local_20 + iVar1);
    iVar1 = iVar1 + DAT_000110c8;
  } while (iVar1 != 0);
  FUN_00010f40(local_1c[0],param_3);
  FUN_00010f40(local_20,param_3 + 4);
  return;
}



/* Function: FUN_000110d4 @ 000110d4 */

void FUN_000110d4(undefined4 *param_1)

{
  *param_1 = DAT_000110f0;
  param_1[1] = DAT_000110f4;
  param_1[2] = DAT_000110f8;
  param_1[3] = DAT_000110fc;
  param_1[5] = 0;
  param_1[4] = 0;
  param_1[6] = 0;
  return;
}



/* Function: FUN_00011100 @ 00011100 */

void FUN_00011100(int *param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int *local_80;
  uint local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  int local_58 [16];
  int iStack_18;
  
  local_6c = param_3[1];
  local_70 = param_3[2];
  uVar4 = param_3[4];
  local_68 = *param_3;
  local_74 = param_3[3];
  param_3[4] = param_2 + uVar4;
  if (param_2 + uVar4 < param_2) {
    param_3[5] = param_3[5] + 1;
  }
  local_80 = param_1;
  while (local_80 < (int *)((int)param_1 + (param_2 & 0xfffffffc))) {
    piVar5 = local_58;
    piVar2 = local_80;
    do {
      iVar7 = *piVar2;
      piVar2 = piVar2 + 1;
      *piVar5 = iVar7;
      piVar5 = piVar5 + 1;
    } while (piVar5 != &iStack_18);
    local_80 = local_80 + 0x10;
    uVar6 = 0;
    uVar10 = local_6c;
    uVar9 = local_74;
    uVar4 = local_70;
    uVar8 = local_68;
    do {
      uVar1 = uVar4;
      uVar3 = uVar9;
      uVar4 = uVar10;
      uVar9 = *(int *)((int)&DAT_00011360 + uVar6 * 4 + DAT_00011364) +
              local_58[*(char *)(DAT_00011364 + 0x11320 + uVar6)] + uVar8 +
              ((uVar3 ^ uVar1) & uVar4 ^ uVar3);
      uVar10 = uVar6 & 3;
      uVar6 = uVar6 + 1;
      uVar10 = 0x20U - (int)*(char *)(DAT_00011348 + 0x1118e + uVar10) & 0x1f;
      uVar10 = (uVar9 >> uVar10 | uVar9 << 0x20 - uVar10) + uVar4;
      uVar9 = uVar1;
      uVar8 = uVar3;
    } while (uVar6 != 0x10);
    uVar9 = 0;
    do {
      uVar8 = uVar10;
      uVar6 = uVar1;
      uVar1 = uVar4;
      uVar10 = *(int *)(DAT_0001134c + uVar9 * 4 + 0x11228) +
               local_58[*(char *)(DAT_0001134c + uVar9 + 0x111b8)] + uVar3 +
               ((uVar1 ^ uVar8) & uVar6 ^ uVar1);
      uVar4 = uVar9 & 3;
      uVar9 = uVar9 + 1;
      uVar4 = 0x20U - (int)*(char *)(DAT_00011350 + uVar4 + 0x111f8) & 0x1f;
      uVar10 = (uVar10 >> uVar4 | uVar10 << 0x20 - uVar4) + uVar8;
      uVar4 = uVar8;
      uVar3 = uVar6;
    } while (uVar9 != 0x10);
    uVar4 = 0;
    do {
      uVar3 = uVar8;
      uVar8 = uVar10;
      uVar9 = uVar1;
      uVar6 = *(int *)(DAT_00011354 + uVar4 * 4 + 0x112e0) +
              local_58[*(char *)(DAT_00011354 + uVar4 + 0x11240)] + uVar6 + (uVar3 ^ uVar8 ^ uVar9);
      uVar10 = uVar4 & 3;
      uVar4 = uVar4 + 1;
      uVar10 = 0x20U - (int)*(char *)(DAT_00011358 + uVar10 + 0x11278) & 0x1f;
      uVar10 = (uVar6 >> uVar10 | uVar6 << 0x20 - uVar10) + uVar8;
      uVar1 = uVar3;
      uVar6 = uVar9;
    } while (uVar4 != 0x10);
    uVar4 = 0;
    do {
      uVar1 = uVar3;
      uVar6 = uVar10;
      uVar3 = uVar8;
      uVar9 = *(int *)((int)&DAT_0001138c + DAT_0001135c + uVar4 * 4 + 2) +
              local_58[*(char *)(DAT_0001135c + uVar4 + 0x112be)] + uVar9 +
              ((~uVar1 | uVar6) ^ uVar3);
      uVar10 = uVar4 & 3;
      uVar4 = uVar4 + 1;
      uVar10 = 0x20U - (int)*(char *)(DAT_00011360 + uVar10 + 0x112ea) & 0x1f;
      uVar10 = (uVar9 >> uVar10 | uVar9 << 0x20 - uVar10) + uVar6;
      uVar9 = uVar1;
      uVar8 = uVar6;
    } while (uVar4 != 0x10);
    local_68 = local_68 + uVar1;
    local_6c = local_6c + uVar10;
    local_74 = local_74 + uVar3;
    local_70 = local_70 + uVar6;
  }
  param_3[1] = local_6c;
  param_3[2] = local_70;
  param_3[3] = local_74;
  *param_3 = local_68;
  return;
}



/* Function: FUN_00011368 @ 00011368 */

void FUN_00011368(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_0001138c;
  param_1[5] = 0;
  *param_1 = uVar1;
  uVar1 = DAT_00011390;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[1] = uVar1;
  uVar1 = DAT_00011394;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[2] = uVar1;
  param_1[3] = DAT_00011398;
  param_1[4] = DAT_0001139c;
  return;
}



/* Function: FUN_000113a0 @ 000113a0 */

void FUN_000113a0(uint *param_1)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint local_158 [80];
  uint uStack_18;
  
  puVar7 = local_158;
  puVar8 = param_1 + 8;
  puVar4 = puVar7;
  do {
    uVar12 = *puVar8;
    pbVar1 = (byte *)((int)puVar8 + 1);
    pbVar2 = (byte *)((int)puVar8 + 3);
    pbVar3 = (byte *)((int)puVar8 + 2);
    puVar8 = puVar8 + 1;
    *puVar4 = (uint)*pbVar1 << 0x10 | (uint)(byte)uVar12 << 0x18 | (uint)*pbVar2 |
              (uint)*pbVar3 << 8;
    puVar4 = puVar4 + 1;
  } while (puVar4 != local_158 + 0x10);
  puVar4 = puVar7;
  do {
    puVar8 = puVar4 + 1;
    uVar12 = puVar4[0xd] ^ puVar4[8] ^ puVar4[2] ^ *puVar4;
    puVar4[0x10] = uVar12 >> 0x1f | uVar12 << 1;
    puVar4 = puVar8;
  } while (puVar8 != local_158 + 0x40);
  uVar12 = param_1[2];
  uVar5 = *param_1;
  uVar6 = param_1[1];
  uVar9 = param_1[3];
  uVar11 = param_1[4];
  do {
    uVar14 = uVar9;
    uVar10 = uVar5;
    uVar9 = uVar12;
    uVar12 = *puVar7;
    puVar7 = puVar7 + 1;
    uVar5 = uVar12 + DAT_00011528 + uVar11 + (uVar10 >> 0x1b | uVar10 << 5) +
            (uVar9 & uVar6 | uVar14 & ~uVar6);
    uVar12 = uVar6 >> 2 | uVar6 << 0x1e;
    uVar6 = uVar10;
    uVar11 = uVar14;
  } while (puVar7 != local_158 + 0x14);
  puVar7 = local_158 + 0x14;
  do {
    uVar11 = uVar9;
    uVar9 = uVar12;
    uVar6 = uVar5;
    uVar12 = *puVar7;
    puVar7 = puVar7 + 1;
    uVar5 = uVar12 + DAT_0001152c + uVar14 + (uVar6 >> 0x1b | uVar6 << 5) +
            (uVar9 ^ uVar10 ^ uVar11);
    uVar12 = uVar10 >> 2 | uVar10 << 0x1e;
    uVar10 = uVar6;
    uVar14 = uVar11;
  } while (puVar7 != local_158 + 0x28);
  puVar7 = local_158 + 0x28;
  do {
    uVar13 = uVar5;
    uVar14 = uVar12;
    uVar10 = uVar9;
    uVar12 = *puVar7;
    puVar7 = puVar7 + 1;
    uVar5 = uVar12 + DAT_00011530 + uVar11 + (uVar13 >> 0x1b | uVar13 << 5) +
            (uVar10 & uVar14 | (uVar10 | uVar14) & uVar6);
    uVar12 = uVar6 >> 2 | uVar6 << 0x1e;
    uVar6 = uVar13;
    uVar9 = uVar14;
    uVar11 = uVar10;
  } while (puVar7 != local_158 + 0x3c);
  puVar7 = local_158 + 0x3c;
  do {
    uVar11 = uVar12;
    uVar6 = uVar5;
    uVar9 = uVar14;
    uVar12 = *puVar7;
    puVar7 = puVar7 + 1;
    uVar5 = uVar12 + DAT_00011534 + uVar10 + (uVar6 >> 0x1b | uVar6 << 5) +
            (uVar11 ^ uVar13 ^ uVar9);
    uVar12 = uVar13 >> 2 | uVar13 << 0x1e;
    uVar10 = uVar9;
    uVar14 = uVar11;
    uVar13 = uVar6;
  } while (puVar7 != &uStack_18);
  *param_1 = *param_1 + uVar5;
  param_1[1] = param_1[1] + uVar6;
  param_1[2] = param_1[2] + uVar12;
  param_1[3] = param_1[3] + uVar11;
  param_1[4] = param_1[4] + uVar9;
  param_1[7] = 0;
  return;
}



/* Function: FUN_00011538 @ 00011538 */

void FUN_00011538(int param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  if (0 < param_3) {
    while ((bVar3 = param_3 != 0, param_3 = param_3 + -1, bVar3 && (*(int *)(param_1 + 100) == 0)))
    {
      iVar2 = *(int *)(param_1 + 0x1c);
      *(undefined1 *)(param_1 + iVar2 + 0x20) = *param_2;
      iVar2 = iVar2 + 1;
      *(int *)(param_1 + 0x1c) = iVar2;
      iVar1 = *(int *)(param_1 + 0x14) + 8;
      *(int *)(param_1 + 0x14) = iVar1;
      if ((iVar1 == 0) &&
         (iVar1 = *(int *)(param_1 + 0x18) + 1, *(int *)(param_1 + 0x18) = iVar1, iVar1 == 0)) {
        *(undefined4 *)(param_1 + 100) = 1;
      }
      if (iVar2 == 0x40) {
        FUN_000113a0(param_1);
      }
      param_2 = param_2 + 1;
    }
  }
  return;
}



/* Function: FUN_00011584 @ 00011584 */

void FUN_00011584(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  iVar2 = iVar1 + 1;
  if (iVar1 < 0x38) {
    *(undefined1 *)(param_1 + iVar1 + 0x20) = 0x80;
    *(int *)(param_1 + 0x1c) = iVar2;
    for (; iVar2 < 0x38; iVar2 = iVar2 + 1) {
      *(undefined1 *)(param_1 + iVar2 + 0x20) = 0;
    }
  }
  else {
    *(undefined1 *)(param_1 + iVar1 + 0x20) = 0x80;
    *(int *)(param_1 + 0x1c) = iVar2;
    for (; iVar2 < 0x40; iVar2 = iVar2 + 1) {
      *(undefined1 *)(param_1 + iVar2 + 0x20) = 0;
    }
    *(int *)(param_1 + 0x1c) = iVar2;
    FUN_000113a0(param_1);
    for (iVar2 = *(int *)(param_1 + 0x1c); iVar2 < 0x38; iVar2 = iVar2 + 1) {
      *(undefined1 *)(param_1 + iVar2 + 0x20) = 0;
    }
  }
  *(int *)(param_1 + 0x1c) = iVar2;
  *(undefined1 *)(param_1 + 0x58) = *(undefined1 *)(param_1 + 0x1b);
  *(char *)(param_1 + 0x59) = (char)*(undefined2 *)(param_1 + 0x1a);
  *(char *)(param_1 + 0x5a) = (char)((uint)*(undefined4 *)(param_1 + 0x18) >> 8);
  *(char *)(param_1 + 0x5b) = (char)*(undefined4 *)(param_1 + 0x18);
  *(undefined1 *)(param_1 + 0x5c) = *(undefined1 *)(param_1 + 0x17);
  *(char *)(param_1 + 0x5d) = (char)*(undefined2 *)(param_1 + 0x16);
  *(char *)(param_1 + 0x5e) = (char)((uint)*(undefined4 *)(param_1 + 0x14) >> 8);
  *(char *)(param_1 + 0x5f) = (char)*(undefined4 *)(param_1 + 0x14);
  FUN_000113a0(param_1);
  return;
}



/* Function: FUN_00011624 @ 00011624 */

void FUN_00011624(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0x60) == 0) {
    FUN_00011584();
    iVar2 = 0;
    do {
      iVar1 = param_1 + iVar2;
      iVar2 = iVar2 + 1;
      *(undefined1 *)(iVar1 + 0x20) = 0;
    } while (iVar2 != 0x40);
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x60) = 1;
  }
  uVar3 = 0;
  do {
    *(char *)(param_2 + uVar3) =
         (char)(*(uint *)(((int)uVar3 >> 2) * 4 + param_1) >> ((~uVar3 & 3) << 3));
    uVar3 = uVar3 + 1;
  } while (uVar3 != 0x14);
  return;
}



/* Function: FUN_0001166c @ 0001166c */

void FUN_0001166c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined1 auStack_84 [104];
  int local_1c;
  
  piVar1 = *(int **)(DAT_000116ac + 0x11678);
  local_1c = *piVar1;
  FUN_00011368(auStack_84);
  FUN_00011538(auStack_84,param_1,param_2);
  FUN_00011624(auStack_84,param_3);
  if (local_1c != *piVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



/* Function: FUN_000116b0 @ 000116b0 */

void FUN_000116b0(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  byte *pbVar2;
  byte local_54 [20];
  byte abStack_40 [44];
  int local_14;
  
  local_14 = **(int **)(DAT_00011740 + 0x116bc);
  if (param_3 < 0x41) {
    for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 1) {
      local_54[iVar1] = *(byte *)(param_2 + iVar1) ^ 0x36;
    }
  }
  else {
    FUN_00011368();
    pbVar2 = local_54;
    FUN_00011538(param_1,param_2,param_3);
    FUN_00011624(param_1,pbVar2);
    do {
      *pbVar2 = *pbVar2 ^ 0x36;
      pbVar2 = pbVar2 + 1;
    } while (pbVar2 != abStack_40);
    iVar1 = 0x14;
  }
  for (; iVar1 < 0x40; iVar1 = iVar1 + 1) {
    local_54[iVar1] = 0x36;
  }
  FUN_00011368(param_1);
  FUN_00011538(param_1,local_54,0x40);
  if (local_14 == **(int **)(DAT_00011744 + 0x11730)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



/* Function: FUN_00011854 @ 00011854 */

void FUN_00011854(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_00011884;
  param_1[8] = 0;
  *param_1 = uVar1;
  uVar1 = DAT_00011888;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[1] = uVar1;
  uVar1 = DAT_0001188c;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[2] = uVar1;
  param_1[3] = DAT_00011890;
  param_1[4] = DAT_00011894;
  param_1[5] = DAT_00011898;
  param_1[6] = DAT_0001189c;
  param_1[7] = DAT_000118a0;
  return;
}



/* Function: FUN_000118a4 @ 000118a4 */

void FUN_000118a4(uint *param_1)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint local_134;
  uint local_128;
  uint local_124;
  uint local_118 [65];
  
  puVar11 = param_1 + 0xb;
  puVar8 = local_118;
  do {
    uVar9 = *puVar11;
    pbVar1 = (byte *)((int)puVar11 + 1);
    pbVar2 = (byte *)((int)puVar11 + 3);
    pbVar3 = (byte *)((int)puVar11 + 2);
    puVar11 = puVar11 + 1;
    *puVar8 = (uint)*pbVar1 << 0x10 | (uint)(byte)uVar9 << 0x18 | (uint)*pbVar2 | (uint)*pbVar3 << 8
    ;
    puVar8 = puVar8 + 1;
  } while (puVar8 != local_118 + 0x10);
  puVar8 = local_118;
  do {
    uVar9 = puVar8[0xe];
    uVar12 = puVar8[1];
    puVar11 = puVar8 + 1;
    puVar8[0x10] = *puVar8 + puVar8[9] +
                   ((uVar9 >> 0x13 | uVar9 << 0xd) ^ (uVar9 >> 0x11 | uVar9 << 0xf) ^ uVar9 >> 10) +
                   ((uVar12 >> 0x12 | uVar12 << 0xe) ^ (uVar12 >> 7 | uVar12 << 0x19) ^ uVar12 >> 3)
    ;
    puVar8 = puVar11;
  } while (puVar11 != local_118 + 0x30);
  local_134 = param_1[7];
  iVar16 = 0;
  uVar9 = param_1[2];
  uVar12 = *param_1;
  uVar7 = param_1[4];
  uVar13 = param_1[1];
  uVar14 = param_1[5];
  uVar17 = param_1[6];
  local_124 = param_1[3];
  do {
    local_128 = uVar17;
    uVar17 = uVar14;
    uVar15 = uVar13;
    uVar14 = uVar7;
    uVar13 = uVar12;
    uVar10 = uVar9;
    piVar4 = (int *)(DAT_00011a18 + 0x11980 + iVar16);
    piVar5 = (int *)((int)local_118 + iVar16);
    iVar16 = iVar16 + 4;
    iVar6 = local_134 +
            ((uVar14 >> 0x19 | uVar14 << 7) ^
            (uVar14 >> 0xb | uVar14 << 0x15) ^ (uVar14 >> 6 | uVar14 << 0x1a)) +
            (local_128 & ~uVar14 ^ uVar17 & uVar14) + *piVar4 + *piVar5;
    uVar12 = ((uVar15 ^ uVar10) & uVar13 ^ uVar10 & uVar15) +
             ((uVar13 >> 0x16 | uVar13 << 10) ^
             (uVar13 >> 0xd | uVar13 << 0x13) ^ (uVar13 >> 2 | uVar13 << 0x1e)) + iVar6;
    uVar7 = iVar6 + local_124;
    local_134 = local_128;
    uVar9 = uVar15;
    local_124 = uVar10;
  } while (iVar16 != 0x100);
  *param_1 = uVar12 + *param_1;
  param_1[1] = param_1[1] + uVar13;
  param_1[2] = param_1[2] + uVar15;
  param_1[3] = param_1[3] + uVar10;
  param_1[4] = param_1[4] + uVar7;
  param_1[5] = param_1[5] + uVar14;
  param_1[6] = param_1[6] + uVar17;
  param_1[7] = param_1[7] + local_128;
  param_1[10] = 0;
  return;
}



/* Function: FUN_00011a1c @ 00011a1c */

void FUN_00011a1c(int param_1,undefined1 *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  
  if (0 < param_3) {
    while ((bVar5 = param_3 != 0, param_3 = param_3 + -1, bVar5 && (*(int *)(param_1 + 0x70) == 0)))
    {
      iVar3 = *(int *)(param_1 + 0x28);
      *(undefined1 *)(param_1 + iVar3 + 0x2c) = *param_2;
      *(int *)(param_1 + 0x28) = iVar3 + 1;
      uVar4 = *(uint *)(param_1 + 0x20);
      uVar1 = uVar4 + 8;
      *(uint *)(param_1 + 0x20) = uVar1;
      if (uVar1 < uVar4) {
        iVar2 = 1;
        iVar3 = *(int *)(param_1 + 0x24) + 1;
        *(int *)(param_1 + 0x24) = iVar3;
        if (iVar3 != 0) goto LAB_00011a36;
      }
      else {
LAB_00011a36:
        iVar2 = 0;
      }
      *(int *)(param_1 + 0x70) = iVar2;
      if ((iVar2 == 0) && (*(int *)(param_1 + 0x28) == 0x40)) {
        FUN_000118a4(param_1);
      }
      param_2 = param_2 + 1;
    }
  }
  return;
}



/* Function: FUN_00011a7c @ 00011a7c */

void FUN_00011a7c(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = param_1[4];
  uVar2 = param_1[6];
  param_1[4] = uVar2 + iVar1;
  if (uVar2 + iVar1 < uVar2) {
    param_1[5] = param_1[5] + 1;
  }
  iVar1 = 0x78;
  if (uVar2 < 0x38) {
    iVar1 = 0x38;
  }
  memset((void *)((int)param_1 + uVar2 + 0x1c),0,iVar1 - uVar2);
  *(undefined1 *)((int)param_1 + uVar2 + 0x1c) = 0x80;
  iVar3 = (iVar1 - uVar2) + uVar2;
  iVar1 = (int)param_1 + iVar3;
  *(undefined4 *)(iVar1 + 0x1c) = param_1[4] << 3;
  *(uint *)(iVar1 + 0x20) = param_1[5] << 3 | (uint)param_1[4] >> 0x1d;
  FUN_00011100(param_1 + 7,iVar3 + 8,param_1,iVar1,param_4);
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  param_2[2] = param_1[2];
  param_2[3] = param_1[3];
  return;
}



/* Function: FUN_00011ae8 @ 00011ae8 */

void FUN_00011ae8(int param_1,void *param_2,uint param_3)

{
  int iVar1;
  uint __n;
  uint uVar2;
  
  if ((param_3 & 0x3f) == 0) {
    FUN_00011100(param_2,param_3,param_1);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x18);
    if (iVar1 != 0) {
      __n = param_3;
      if (0x80U - iVar1 < param_3) {
        __n = 0x80U - iVar1;
      }
      memcpy((void *)(param_1 + iVar1 + 0x1c),param_2,__n);
      uVar2 = __n + iVar1;
      *(uint *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + __n;
      if (0x40 < uVar2) {
        FUN_00011100((void *)(param_1 + 0x1c),uVar2 & 0xffffffc0,param_1);
        memcpy((void *)(param_1 + 0x1c),(void *)(param_1 + (uVar2 & 0xffffffc0) + 0x1c),uVar2 & 0x3f
              );
        *(uint *)(param_1 + 0x18) = uVar2 & 0x3f;
      }
      param_2 = (void *)((int)param_2 + __n);
      param_3 = param_3 - __n;
    }
    if (0x40 < (int)param_3) {
      FUN_00011100(param_2,param_3 & 0xffffffc0,param_1);
      param_2 = (void *)((int)param_2 + (param_3 & 0xffffffc0));
      param_3 = param_3 & 0x3f;
    }
    if (0 < (int)param_3) {
      memcpy((void *)(param_1 + 0x1c),param_2,param_3);
      *(uint *)(param_1 + 0x18) = param_3;
    }
  }
  return;
}



/* Function: FUN_00011b9c @ 00011b9c */

void FUN_00011b9c(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  byte *pbVar2;
  byte local_5c [16];
  byte abStack_4c [48];
  int local_1c;
  
  local_1c = **(int **)(DAT_00011c48 + 0x11baa);
  FUN_00011a7c(param_1,param_4);
  if (param_3 < 0x41) {
    for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 1) {
      local_5c[iVar1] = *(byte *)(param_2 + iVar1) ^ 0x5c;
    }
  }
  else {
    FUN_000110d4(param_1);
    pbVar2 = local_5c;
    FUN_00011ae8(param_1,param_2,param_3);
    FUN_00011a7c(param_1,pbVar2);
    do {
      *pbVar2 = *pbVar2 ^ 0x5c;
      pbVar2 = pbVar2 + 1;
    } while (pbVar2 != abStack_4c);
    iVar1 = 0x10;
  }
  for (; iVar1 < 0x40; iVar1 = iVar1 + 1) {
    local_5c[iVar1] = 0x5c;
  }
  FUN_000110d4(param_1);
  FUN_00011ae8(param_1,local_5c,0x40);
  FUN_00011ae8(param_1,param_4,0x10);
  FUN_00011a7c(param_1,param_4);
  if (local_1c == **(int **)(DAT_00011c4c + 0x11c38)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



/* Function: FUN_00011d40 @ 00011d40 */

void FUN_00011d40(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined1 auStack_b8 [156];
  int local_1c;
  
  piVar1 = *(int **)(DAT_00011d80 + 0x11d4c);
  local_1c = *piVar1;
  FUN_000110d4(auStack_b8);
  FUN_00011ae8(auStack_b8,param_1,param_2);
  FUN_00011a7c(auStack_b8,param_3);
  if (local_1c != *piVar1) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



/* Function: FUN_00011d84 @ 00011d84 */

void FUN_00011d84(void *param_1,size_t param_2,uint *param_3)

{
  uint *puVar1;
  uint uVar2;
  
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  if (0x10 < (int)param_2) {
    param_2 = 0x10;
  }
  memcpy(param_3,param_1,param_2);
  puVar1 = param_3 + 4;
  do {
    uVar2 = *param_3;
    *param_3 = uVar2 >> 0x18 | uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | (uVar2 & 0xff0000) >> 8;
    param_3 = param_3 + 1;
  } while (param_3 != puVar1);
  return;
}



/* Function: FUN_0001217c @ 0001217c */

void FUN_0001217c(void *param_1,size_t param_2,void *param_3)

{
  undefined1 auStack_b8 [156];
  int local_1c;
  
  local_1c = **(int **)(DAT_000121ec + 0x12188);
  memset(param_3,0,0x10);
  if (((int)param_2 < 0x11) || (param_1 == (void *)0x0)) {
    if ((0 < (int)param_2) && (param_1 != (void *)0x0)) {
      memcpy(param_3,param_1,param_2);
    }
  }
  else {
    FUN_000110d4(auStack_b8);
    FUN_00011ae8(auStack_b8,param_1,param_2);
    FUN_00011a7c(auStack_b8,param_3);
  }
  if (local_1c != **(int **)(DAT_000121f0 + 0x121dc)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



/* Function: FUN_000121f4 @ 000121f4 */

uint FUN_000121f4(uint *param_1,uint param_2,undefined4 param_3,undefined4 param_4,uint *param_5,
                 int param_6)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int local_48;
  uint local_2c;
  uint auStack_28 [5];
  
  if (((int)param_2 < 1) || (param_1 == (uint *)0x0)) {
    uVar8 = 0;
  }
  else {
    uVar8 = DAT_00012330;
    if ((((param_2 & 3) == 0) && (uVar8 = param_2, param_5 != (uint *)0x0)) &&
       (uVar8 = DAT_00012330, (int)param_2 <= param_6)) {
      if (param_5 != param_1) {
        memcpy(param_5,param_1,param_2);
      }
      uVar8 = param_2 >> 2;
      FUN_0001217c(param_3,param_4,auStack_28);
      uVar3 = uVar8 - 1;
      uVar7 = *param_5;
      if ((int)uVar3 < 1) {
        puVar4 = auStack_28 + 3;
        do {
          uVar8 = *puVar4;
          puVar4 = puVar4 + -1;
          uVar7 = uVar7 - (uVar8 ^ DAT_00012334);
          uVar7 = (uVar7 >> 0x10 | uVar7 * 0x10000) ^ DAT_00012340;
        } while (puVar4 != &local_2c);
        *param_5 = uVar7;
        uVar8 = param_2;
      }
      else {
        iVar1 = FUN_00012794(0x34,uVar8);
        uVar5 = (iVar1 + 6) * DAT_00012334;
        iVar9 = uVar8 + DAT_00012338;
        for (local_48 = 0; uVar8 = param_2, local_48 != iVar1 + 6; local_48 = local_48 + 1) {
          uVar10 = uVar5 >> 2 & 3;
          puVar4 = param_5 + iVar9;
          uVar8 = uVar3;
          do {
            uVar6 = uVar8 & 3;
            puVar2 = puVar4 + -1;
            uVar8 = uVar8 - 1;
            uVar7 = *puVar4 - ((uVar7 >> 3 ^ *puVar2 << 4) + (uVar7 << 2 ^ *puVar2 >> 5) ^
                              (*puVar2 ^ auStack_28[uVar6 ^ uVar10]) + (uVar7 ^ uVar5));
            *puVar4 = uVar7;
            puVar4 = puVar2;
          } while (uVar8 != 0);
          uVar8 = param_5[uVar3];
          uVar7 = *param_5 -
                  ((uVar8 << 4 ^ uVar7 >> 3) + (uVar8 >> 5 ^ uVar7 * 4) ^
                  (uVar7 ^ uVar5) + (uVar8 ^ auStack_28[uVar10]));
          *param_5 = uVar7;
          uVar5 = uVar5 + DAT_0001233c;
        }
      }
    }
  }
  return uVar8;
}



/* Function: FUN_00012344 @ 00012344 */

int FUN_00012344(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_stack_00000000;
  
  iVar1 = FUN_000121f4();
  iVar2 = iVar1;
  if ((((0 < iVar1) && (in_stack_00000000 != 0)) &&
      (iVar3 = *(int *)(in_stack_00000000 + iVar1 + -4), iVar2 = DAT_0001237c, -1 < iVar3)) &&
     (iVar3 < iVar1 + -3)) {
    *(undefined1 *)(in_stack_00000000 + iVar3) = 0;
    iVar2 = iVar3;
  }
  return iVar2;
}



/* Function: FUN_00012380 @ 00012380 */

uint FUN_00012380(uint *param_1,size_t param_2,undefined4 param_3,undefined4 param_4,uint *param_5,
                 int param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  uint local_28 [4];
  uint uStack_18;
  
  if (((int)param_2 < 1) || (param_1 == (uint *)0x0)) {
    uVar10 = 0;
  }
  else {
    uVar8 = param_2 + 3 & 0xfffffffc;
    uVar10 = uVar8;
    if ((param_5 != (uint *)0x0) && (uVar10 = DAT_000124bc, (int)uVar8 <= param_6)) {
      if (param_5 != param_1) {
        memcpy(param_5,param_1,param_2);
      }
      for (; (int)param_2 < (int)uVar8; param_2 = param_2 + 1) {
        *(undefined1 *)((int)param_5 + param_2) = 0;
      }
      puVar4 = local_28;
      FUN_0001217c(param_3,param_4,puVar4);
      uVar8 = (param_2 >> 2) - 1;
      puVar11 = param_5 + uVar8;
      uVar9 = *puVar11;
      uVar6 = *param_5;
      uVar10 = param_2;
      if ((int)uVar8 < 1) {
        do {
          uVar8 = *puVar4;
          puVar4 = puVar4 + 1;
          uVar6 = ((uVar6 >> 0x10 | uVar6 << 0x10) ^ DAT_000124c0) + (uVar8 ^ DAT_000124c0);
        } while (puVar4 != &uStack_18);
        *param_5 = uVar6;
      }
      else {
        iVar1 = FUN_00012794(0x34);
        uVar6 = iVar1 * DAT_000124c0 + DAT_000124c4;
        uVar7 = 0;
        while (uVar7 != uVar6) {
          uVar7 = uVar7 + DAT_000124c0;
          uVar2 = uVar7 >> 2 & 3;
          uVar5 = 0;
          puVar4 = param_5;
          do {
            uVar3 = uVar5 & 3;
            uVar5 = uVar5 + 1;
            uVar9 = ((puVar4[1] >> 3 ^ uVar9 << 4) + (uVar9 >> 5 ^ puVar4[1] << 2) ^
                    (local_28[uVar3 ^ uVar2] ^ uVar9) + (puVar4[1] ^ uVar7)) + *puVar4;
            *puVar4 = uVar9;
            puVar4 = puVar4 + 1;
          } while (uVar5 != uVar8);
          uVar5 = *param_5;
          uVar9 = ((uVar5 >> 3 ^ uVar9 * 0x10) + (uVar5 << 2 ^ uVar9 >> 5) ^
                  (uVar9 ^ local_28[uVar2 ^ uVar8 & 3]) + (uVar5 ^ uVar7)) + *puVar11;
          *puVar11 = uVar9;
        }
      }
    }
  }
  return uVar10;
}



/* Function: FUN_000124c8 @ 000124c8 */

int FUN_000124c8(void *param_1,size_t param_2,undefined4 param_3,undefined4 param_4,void *param_5,
                int param_6)

{
  size_t sVar1;
  int iVar2;
  
  iVar2 = (param_2 + 3 & 0xfffffffc) + 4;
  if (param_5 != (void *)0x0) {
    if (param_6 < iVar2) {
      iVar2 = -1;
    }
    else {
      sVar1 = param_2;
      if (param_5 != param_1) {
        memcpy(param_5,param_1,param_2);
      }
      for (; (int)sVar1 < iVar2; sVar1 = sVar1 + 1) {
        *(undefined1 *)((int)param_5 + sVar1) = 0;
      }
      *(size_t *)((((int)sVar1 >> 2) + -1) * 4 + (int)param_5) = param_2;
      iVar2 = FUN_00012380(param_5,sVar1,param_3,param_4,param_5,sVar1);
    }
  }
  return iVar2;
}



/* Function: FUN_00012528 @ 00012528 */

void FUN_00012528(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0x6c) == 0) {
    iVar1 = *(int *)(param_1 + 0x28);
    iVar2 = iVar1 + 1;
    if (iVar1 < 0x38) {
      *(undefined1 *)(param_1 + iVar1 + 0x2c) = 0x80;
      *(int *)(param_1 + 0x28) = iVar2;
    }
    else {
      *(undefined1 *)(param_1 + iVar1 + 0x2c) = 0x80;
      *(int *)(param_1 + 0x28) = iVar2;
      for (; iVar2 < 0x40; iVar2 = iVar2 + 1) {
        *(undefined1 *)(param_1 + iVar2 + 0x2c) = 0;
      }
      *(int *)(param_1 + 0x28) = iVar2;
      FUN_000118a4(param_1);
    }
    for (iVar1 = *(int *)(param_1 + 0x28); iVar1 < 0x38; iVar1 = iVar1 + 1) {
      *(undefined1 *)(param_1 + iVar1 + 0x2c) = 0;
    }
    *(int *)(param_1 + 0x28) = iVar1;
    *(char *)(param_1 + 100) = (char)((uint)*(undefined4 *)(param_1 + 0x24) >> 0x18);
    *(char *)(param_1 + 0x65) = (char)*(undefined2 *)(param_1 + 0x26);
    *(char *)(param_1 + 0x66) = (char)((uint)*(undefined4 *)(param_1 + 0x24) >> 8);
    *(char *)(param_1 + 0x67) = (char)*(undefined4 *)(param_1 + 0x24);
    *(char *)(param_1 + 0x68) = (char)((uint)*(undefined4 *)(param_1 + 0x20) >> 0x18);
    *(char *)(param_1 + 0x69) = (char)*(undefined2 *)(param_1 + 0x22);
    *(char *)(param_1 + 0x6a) = (char)((uint)*(undefined4 *)(param_1 + 0x20) >> 8);
    *(char *)(param_1 + 0x6b) = (char)*(undefined4 *)(param_1 + 0x20);
    FUN_000118a4(param_1);
    iVar1 = 0;
    do {
      iVar2 = param_1 + iVar1;
      iVar1 = iVar1 + 1;
      *(undefined1 *)(iVar2 + 0x2c) = 0;
    } while (iVar1 != 0x40);
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x6c) = 1;
  }
  uVar3 = 0;
  do {
    *(char *)(param_2 + uVar3) =
         (char)(*(uint *)(((int)uVar3 >> 2) * 4 + param_1) >> ((~uVar3 & 3) << 3));
    uVar3 = uVar3 + 1;
  } while (uVar3 != 0x20);
  return;
}



/* Function: FUN_000125f8 @ 000125f8 */

void FUN_000125f8(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  byte *pbVar2;
  byte local_54 [32];
  byte abStack_34 [32];
  int local_14;
  
  local_14 = **(int **)(DAT_00012688 + 0x12604);
  if (param_3 < 0x41) {
    for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 1) {
      local_54[iVar1] = *(byte *)(param_2 + iVar1) ^ 0x36;
    }
  }
  else {
    FUN_00011854();
    pbVar2 = local_54;
    FUN_00011a1c(param_1,param_2,param_3);
    FUN_00012528(param_1,pbVar2);
    do {
      *pbVar2 = *pbVar2 ^ 0x36;
      pbVar2 = pbVar2 + 1;
    } while (pbVar2 != abStack_34);
    iVar1 = 0x20;
  }
  for (; iVar1 < 0x40; iVar1 = iVar1 + 1) {
    local_54[iVar1] = 0x36;
  }
  FUN_00011854(param_1);
  FUN_00011a1c(param_1,local_54,0x40);
  if (local_14 == **(int **)(DAT_0001268c + 0x12678)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



/* Function: FUN_00012690 @ 00012690 */

void FUN_00012690(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  byte *pbVar2;
  byte local_5c [32];
  byte abStack_3c [32];
  int local_1c;
  
  local_1c = **(int **)(DAT_0001273c + 0x1269e);
  FUN_00012528(param_1,param_4);
  if (param_3 < 0x41) {
    for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 1) {
      local_5c[iVar1] = *(byte *)(param_2 + iVar1) ^ 0x5c;
    }
  }
  else {
    FUN_00011854(param_1);
    pbVar2 = local_5c;
    FUN_00011a1c(param_1,param_2,param_3);
    FUN_00012528(param_1,pbVar2);
    do {
      *pbVar2 = *pbVar2 ^ 0x5c;
      pbVar2 = pbVar2 + 1;
    } while (pbVar2 != abStack_3c);
    iVar1 = 0x20;
  }
  for (; iVar1 < 0x40; iVar1 = iVar1 + 1) {
    local_5c[iVar1] = 0x5c;
  }
  FUN_00011854(param_1);
  FUN_00011a1c(param_1,local_5c,0x40);
  FUN_00011a1c(param_1,param_4,0x20);
  FUN_00012528(param_1,param_4);
  if (local_1c == **(int **)(DAT_00012740 + 0x1272c)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



/* Function: FUN_00012794 @ 00012794 */

uint FUN_00012794(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  uVar5 = param_1 ^ param_2;
  if (param_2 == 0) {
    FUN_00012888();
    return 0;
  }
  uVar2 = param_2;
  if ((int)param_2 < 0) {
    uVar2 = -param_2;
  }
  if (uVar2 - 1 == 0) {
    if ((int)param_2 < 0) {
      param_1 = -param_1;
    }
    return param_1;
  }
  uVar4 = param_1;
  if ((int)param_1 < 0) {
    uVar4 = -param_1;
  }
  if (uVar4 <= uVar2) {
    if (uVar4 < uVar2) {
      param_1 = 0;
    }
    if (uVar4 == uVar2) {
      param_1 = (int)uVar5 >> 0x1f | 1;
    }
    return param_1;
  }
  if ((uVar2 & uVar2 - 1) == 0) {
    uVar4 = uVar4 >> (0x1fU - LZCOUNT(uVar2) & 0xff);
    if ((int)uVar5 < 0) {
      uVar4 = -uVar4;
    }
    return uVar4;
  }
  uVar3 = uVar2 << (LZCOUNT(uVar2) - LZCOUNT(uVar4) & 0xffU);
  uVar2 = 1 << (LZCOUNT(uVar2) - LZCOUNT(uVar4) & 0xffU);
  uVar1 = 0;
  while( true ) {
    if (uVar3 <= uVar4) {
      uVar4 = uVar4 - uVar3;
      uVar1 = uVar1 | uVar2;
    }
    if (uVar3 >> 1 <= uVar4) {
      uVar4 = uVar4 - (uVar3 >> 1);
      uVar1 = uVar1 | uVar2 >> 1;
    }
    if (uVar3 >> 2 <= uVar4) {
      uVar4 = uVar4 - (uVar3 >> 2);
      uVar1 = uVar1 | uVar2 >> 2;
    }
    if (uVar3 >> 3 <= uVar4) {
      uVar4 = uVar4 - (uVar3 >> 3);
      uVar1 = uVar1 | uVar2 >> 3;
    }
    bVar6 = uVar4 == 0;
    if (!bVar6) {
      uVar2 = uVar2 >> 4;
      bVar6 = uVar2 == 0;
    }
    if (bVar6) break;
    uVar3 = uVar3 >> 4;
  }
  if ((int)uVar5 < 0) {
    uVar1 = -uVar1;
  }
  return uVar1;
}



/* Function: FUN_00012870 @ 00012870 */

void FUN_00012870(void)

{
  FUN_00012794();
  return;
}



/* Function: FUN_00012888 @ 00012888 */

void FUN_00012888(void)

{
  raise(8);
  return;
}



/* Function: FUN_00012898 @ 00012898 */

undefined4 FUN_00012898(int param_1,uint param_2,uint param_3,int param_4,undefined4 *param_5)

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



/* Function: FUN_000128e4 @ 000128e4 */

undefined4 FUN_000128e4(int param_1,uint param_2,uint param_3,int param_4,undefined4 *param_5)

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



/* Function: FUN_00012930 @ 00012930 */

int FUN_00012930(uint *param_1)

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



/* Function: FUN_00012974 @ 00012974 */

undefined4 FUN_00012974(uint param_1,uint param_2,undefined4 param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  bool bVar9;
  uint uVar10;
  uint local_58;
  int local_3c;
  uint *local_38;
  undefined1 local_34;
  undefined1 local_33;
  uint local_30;
  int local_2c [2];
  
  uVar7 = param_1 & 3;
  local_38 = *(uint **)(param_2 + 0x4c) + 1;
  uVar5 = **(uint **)(param_2 + 0x4c);
  if (param_4 == 0) {
    local_3c = uVar5 << 8;
    local_34 = 3;
    local_33 = 0;
    puVar8 = local_38;
  }
  else {
    local_3c = uVar5 << 0x10;
    puVar8 = local_38 + (uVar5 >> 0x10 & 0xff);
    local_34 = 2;
    local_33 = (undefined1)(uVar5 >> 0x10);
  }
  if (uVar7 == 2) {
    puVar8 = *(uint **)(param_2 + 0x38);
  }
  if ((*(uint *)(param_2 + 0x50) & 1) == 0) {
    iVar3 = param_2 + 0x58;
    bVar9 = false;
LAB_00012d6c:
    do {
      while( true ) {
        local_58 = *puVar8;
        if (local_58 == 0) goto LAB_00012d78;
        if (param_4 != 2) {
          uVar5 = (uint)*(ushort *)((int)puVar8 + 2);
          local_58 = (uint)(ushort)*puVar8;
        }
        else {
          uVar5 = puVar8[1];
        }
        if (param_4 != 2) {
          puVar6 = puVar8 + 1;
        }
        else {
          puVar6 = puVar8 + 2;
        }
        uVar10 = (uVar5 & 0xfffffffe) + *(int *)(param_2 + 0x48);
        FUN_00012898(param_3,0,0xf,0,&local_30);
        if (local_30 < uVar10) {
          bVar1 = false;
        }
        else if (local_30 < uVar10 + (local_58 & 0xfffffffe)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        uVar5 = local_58 & 1 | (uVar5 & 1) << 1;
        if (uVar5 != 1) break;
        if (uVar7 == 0) {
          if (bVar1) {
            uVar5 = puVar6[1];
            if (uVar5 == 0xfffffffe) {
              return 9;
            }
            local_2c[0] = iVar3;
            if (uVar5 != 0xffffffff) {
              if (uVar5 == 0) {
                uVar4 = 0;
              }
              else {
                uVar4 = *(undefined4 *)((int)puVar6 + uVar5 + 4);
              }
              iVar2 = __cxa_type_match(param_2,uVar4,*puVar6 >> 0x1f,local_2c);
              if (iVar2 == 0) {
                local_2c[0] = 0;
              }
            }
            if (local_2c[0] != 0) {
LAB_00012c6c:
              FUN_00012898(param_3,0,0xd,0,&local_30);
              *(uint **)(param_2 + 0x28) = puVar6;
              *(uint *)(param_2 + 0x20) = local_30;
              *(int *)(param_2 + 0x24) = local_2c[0];
              return 6;
            }
          }
        }
        else {
          uVar5 = *(uint *)(param_2 + 0x20);
          FUN_00012898(param_3,0,0xd,0,&local_30);
          if ((uVar5 == local_30) && (puVar6 == *(uint **)(param_2 + 0x28))) {
            local_30 = FUN_00012930(puVar6);
            FUN_000128e4(param_3,0,0xf,0,&local_30);
LAB_00012d30:
            uVar4 = 0;
            local_30 = param_2;
            goto LAB_00012dec;
          }
        }
        puVar8 = puVar6 + 2;
      }
      if (uVar5 != 0) {
        if (uVar5 != 2) {
          return 9;
        }
        uVar5 = *puVar6 & 0x7fffffff;
        if (uVar7 == 0) {
          if ((bVar1) && ((param_1 & 8) == 0 || uVar5 == 0)) {
            local_58 = 0;
            puVar8 = puVar6;
            do {
              if (local_58 == uVar5) goto LAB_00012c6c;
              puVar8 = puVar8 + 1;
              local_58 = local_58 + 1;
              uVar4 = 0;
              if (*puVar8 != 0) {
                uVar4 = *(undefined4 *)((int)puVar8 + *puVar8);
              }
              local_2c[0] = iVar3;
              iVar2 = __cxa_type_match(param_2,uVar4,0,local_2c);
            } while (iVar2 == 0);
          }
        }
        else {
          uVar10 = *(uint *)(param_2 + 0x20);
          FUN_00012898(param_3,0,0xd,0,&local_30);
          if ((uVar10 == local_30) && (puVar6 == *(uint **)(param_2 + 0x28))) {
            *(uint **)(param_2 + 0x34) = puVar6 + 1;
            *(uint *)(param_2 + 0x28) = uVar5;
            *(undefined4 *)(param_2 + 0x2c) = 0;
            *(undefined4 *)(param_2 + 0x30) = 4;
            if (-1 < (int)*puVar6) {
              local_30 = FUN_00012930(puVar6 + uVar5 + 1);
              FUN_000128e4(param_3,0,0xf,0,&local_30);
              goto LAB_00012d30;
            }
            bVar9 = true;
          }
        }
        if ((int)*puVar6 < 0) {
          puVar6 = puVar6 + 1;
        }
        puVar8 = puVar6 + uVar5 + 1;
        goto LAB_00012d6c;
      }
      if (uVar7 == 0) {
        bVar1 = false;
      }
      puVar8 = puVar6 + 1;
    } while (!bVar1);
    uVar5 = FUN_00012930(puVar6);
    *(uint **)(param_2 + 0x38) = puVar8;
    iVar3 = __cxa_begin_cleanup(param_2);
    if (iVar3 != 0) {
      uVar4 = 0xf;
      local_30 = uVar5;
      goto LAB_00012dec;
    }
  }
  else {
    bVar9 = false;
LAB_00012d78:
    iVar3 = FUN_000139d0(param_3,&local_3c);
    if (iVar3 == 0) {
      if (!bVar9) {
        return 8;
      }
      FUN_00012898(param_3,0,0xf,0,&local_30);
      FUN_000128e4(param_3,0,0xe,0,&local_30);
      uVar4 = 0xf;
      local_30 = *(uint *)(DAT_00012e04 + 0x12ddc);
LAB_00012dec:
      FUN_000128e4(param_3,0,uVar4,0,&local_30);
      return 7;
    }
  }
  return 9;
}



/* Function: FUN_00012e20 @ 00012e20 */

undefined4 FUN_00012e20(int param_1,int param_2)

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
  
  iVar8 = DAT_00012fd4 + 0x12e34;
  uVar9 = param_2 - 2;
  if (*(int *)(iVar8 + DAT_00012fd8) == 0) {
    iVar2 = *(int *)(iVar8 + DAT_00012fe0);
    local_2c[0] = *(int *)(iVar8 + DAT_00012fdc) - iVar2 >> 3;
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
        uVar3 = FUN_00012930(iVar10);
        uVar7 = 0xffffffff;
        if (iVar1 != iVar6) {
          iVar4 = FUN_00012930(iVar2 + (iVar1 + 1) * 8);
          uVar7 = iVar4 - 1;
        }
        if (uVar3 <= uVar9) break;
        iVar12 = iVar1 + -1;
        if (iVar1 == iVar11) goto LAB_00012fac;
      }
      iVar11 = iVar1 + 1;
    } while (uVar7 < uVar9);
    if (iVar10 != 0) {
      uVar5 = FUN_00012930(iVar10);
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
        uVar5 = FUN_00012930();
        *(undefined4 *)(param_1 + 0x50) = 0;
        *(undefined4 *)(param_1 + 0x4c) = uVar5;
      }
      if (-1 < (int)**(uint **)(param_1 + 0x4c)) {
        uVar5 = FUN_00012930();
        *(undefined4 *)(param_1 + 0x10) = uVar5;
        return 0;
      }
      uVar9 = **(uint **)(param_1 + 0x4c) >> 0x18 & 0xf;
      iVar2 = DAT_00012fe4;
      if (((uVar9 == 0) || (iVar2 = DAT_00012fe8, uVar9 == 1)) || (iVar2 = DAT_00012fec, uVar9 == 2)
         ) {
        *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar8 + iVar2);
        return 0;
      }
    }
  }
LAB_00012fac:
  *(undefined4 *)(param_1 + 0x10) = 0;
  return 9;
}



/* Function: FUN_00012ff0 @ 00012ff0 */

void FUN_00012ff0(uint *param_1)

{
  if ((*param_1 & 1) == 0) {
    if ((*param_1 & 2) == 0) {
      FUN_00013770(param_1 + 0x12);
    }
    else {
      FUN_00013780();
    }
  }
  if ((*param_1 & 4) == 0) {
    FUN_00013790(param_1 + 0x34);
  }
  if ((*param_1 & 8) == 0) {
    FUN_000137a0(param_1 + 0x6c);
  }
  if ((*param_1 & 0x10) != 0) {
    return;
  }
  FUN_00013828(param_1 + 0x8c);
  return;
}



/* Function: FUN_0001305c @ 0001305c */

int FUN_0001305c(code *param_1,undefined4 param_2,int param_3)

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
    iVar1 = FUN_00012e20(auStack_80,local_280);
    if (iVar1 != 0) {
LAB_00013118:
      iVar1 = 9;
      break;
    }
    local_24[0] = auStack_80;
    FUN_000128e4(&local_2c0,0,0xc,0,local_24);
    iVar1 = (*param_1)(&local_2c0,param_2);
    if (iVar1 != 0) goto LAB_00013118;
    iVar1 = (*local_70)(8,auStack_80,&local_2c0);
  } while (iVar1 != 9 && iVar1 != 5);
  FUN_00012ff0(&local_2c0);
  return iVar1;
}



/* Function: FUN_00013130 @ 00013130 */

int FUN_00013130(int param_1,int param_2,int param_3)

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
    iVar1 = FUN_00012e20(param_1,local_228);
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
    FUN_0001375c(&local_264);
  }
  return 9;
}



/* Function: FUN_00013268 @ 00013268 */

void FUN_00013268(int param_1,int param_2)

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
    iVar1 = FUN_00012e20(param_1,*(undefined4 *)(param_2 + 0x40));
    if (iVar1 != 0) goto LAB_000132b4;
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_2 + 0x40);
    iVar1 = (**(code **)(param_1 + 0x10))(1,param_1,param_2);
  } while (iVar1 == 8);
  if (iVar1 != 7) {
LAB_000132b4:
                    /* WARNING: Subroutine does not return */
    abort();
  }
  uVar4 = FUN_0001375c(param_2 + 4);
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
    iVar2 = FUN_00012e20(iVar1,local_228);
    if (iVar2 != 0) goto LAB_00013358;
    iVar2 = (**(code **)(iVar1 + 0x10))(0,iVar1,&local_268);
  } while (iVar2 == 8);
  FUN_00012ff0(&local_268);
  if (iVar2 == 6) {
    FUN_00013268(iVar1,iVar3);
  }
LAB_00013358:
                    /* WARNING: Could not recover jumptable at 0x00013360. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)0x132c0)(9);
  return;
}



/* Function: FUN_000133f0 @ 000133f0 */

undefined4 FUN_000133f0(uint *param_1,undefined4 param_2,uint param_3,int param_4)

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
        FUN_00013788();
      }
      else {
        *param_1 = uVar2 & 0xfffffffc;
        FUN_00013778(param_1 + 0x12);
      }
    }
    if ((0 < (int)uVar3) && ((*param_1 & 4) != 0)) {
      *param_1 = *param_1 & 0xfffffffb;
      FUN_00013798(param_1 + 0x34);
    }
    if (bVar8) {
      FUN_00013778(auStack_1b8);
    }
    else {
      if (param_3 < 0x10) {
        FUN_00013788(auStack_1b8);
      }
      if (uVar3 == 0) goto LAB_0001358c;
      FUN_00013798(local_b0);
    }
    if (0 < (int)uVar3) {
      uVar6 = 0x10 - param_3;
    }
LAB_0001358c:
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
      FUN_00013770(auStack_1b8);
    }
    else {
      if (param_3 < 0x10) {
        FUN_00013780(auStack_1b8);
      }
      if (0 < (int)uVar3) {
        FUN_00013790(local_b0);
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
          FUN_000137e4(param_1 + 0x6c);
        }
        FUN_000137e4(auStack_130);
        uVar3 = param_1[0xe];
        iVar5 = 0;
        for (iVar7 = uVar6 * 2; iVar7 != 0; iVar7 = iVar7 + -1) {
          *(undefined4 *)((int)auStack_130 + iVar5 + (param_3 >> 0x10) * 8) =
               *(undefined4 *)(iVar5 + uVar3);
          iVar5 = iVar5 + 4;
        }
        param_1[0xe] = uVar3 + uVar6 * 8;
        FUN_000137a0(auStack_130);
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
        FUN_0001383c(param_1 + 0x8c);
      }
      FUN_0001383c(local_30);
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
      FUN_00013828(local_30);
      return 0;
    }
  }
  return 2;
}



/* Function: FUN_0001375c @ 0001375c */

undefined8 FUN_0001375c(undefined8 *param_1)

{
  return *param_1;
}



/* Function: FUN_00013770 @ 00013770 */

undefined4 FUN_00013770(undefined8 *param_1)

{
  return (int)*param_1;
}



/* Function: FUN_00013778 @ 00013778 */

void FUN_00013778(undefined8 *param_1)

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



/* Function: FUN_00013780 @ 00013780 */

undefined4 FUN_00013780(undefined8 *param_1)

{
  return (int)*param_1;
}



/* Function: FUN_00013788 @ 00013788 */

void FUN_00013788(undefined8 *param_1)

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



/* Function: FUN_00013790 @ 00013790 */

void FUN_00013790(void)

{
  return;
}



/* Function: FUN_00013798 @ 00013798 */

void FUN_00013798(undefined8 *param_1)

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



/* Function: FUN_000137a0 @ 000137a0 */

int FUN_000137a0(int param_1)

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



/* Function: FUN_000137e4 @ 000137e4 */

int FUN_000137e4(int param_1)

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



/* Function: FUN_00013828 @ 00013828 */

int FUN_00013828(int param_1)

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



/* Function: FUN_0001383c @ 0001383c */

int FUN_0001383c(int param_1)

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



/* Function: FUN_00013904 @ 00013904 */

uint FUN_00013904(uint *param_1)

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



/* Function: FUN_0001395c @ 0001395c */

void FUN_0001395c(void)

{
                    /* WARNING: Subroutine does not return */
  abort();
}



/* Function: FUN_000139a4 @ 000139a4 */

undefined4 FUN_000139a4(void)

{
  int in_r3;
  
  FUN_00012898();
  return *(undefined4 *)(in_r3 + 0x48);
}



/* Function: FUN_000139d0 @ 000139d0 */

undefined4 FUN_000139d0(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

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
LAB_000139e8:
  do {
    while( true ) {
      uVar1 = FUN_00013904(param_2);
      if (uVar1 == 0xb0) {
        if (bVar4) {
          return 0;
        }
        FUN_00012898(param_1,0,0xe,0,&local_24,uVar7,param_3);
        FUN_000128e4(param_1,0,0xf,0,&local_24);
        return 0;
      }
      if ((uVar1 & 0x80) != 0) break;
      FUN_00012898(param_1,0,0xd,0,&local_24,uVar7,param_3);
      iVar5 = (uVar1 & 0x3f) * 4 + 4;
      if ((uVar1 & 0x40) != 0) {
        iVar5 = -iVar5;
      }
      local_24 = local_24 + iVar5;
LAB_00013b20:
      piVar6 = &local_24;
      FUN_000128e4(param_1,0,0xd,0);
    }
    uVar3 = uVar1 & 0xf0;
    if (uVar3 == 0x80) {
      uVar3 = FUN_00013904(param_2);
      uVar3 = uVar3 | uVar1 << 8;
      if (uVar3 == 0x8000) {
        return 9;
      }
      iVar5 = FUN_000133f0(param_1,0,(uVar3 & 0xfff) << 4,0,piVar6);
      if (iVar5 != 0) {
        return 9;
      }
      if ((uVar3 & 0x800) != 0) {
        bVar4 = true;
      }
      goto LAB_000139e8;
    }
    if (uVar3 == 0x90) {
      uVar1 = uVar1 & 0xf;
      if (uVar1 == 0xd || uVar1 == 0xf) {
        return 9;
      }
      FUN_00012898(param_1,0,uVar1,0,&local_24,uVar7,param_3);
      goto LAB_00013b20;
    }
    if (uVar3 == 0xa0) {
      uVar2 = 0;
    }
    else if (uVar3 == 0xb0) {
      if (uVar1 == 0xb1) {
        uVar1 = FUN_00013904(param_2);
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
          FUN_00012898(param_1,0,0xd,0,&local_24,uVar7,param_3);
          while( true ) {
            uVar3 = FUN_00013904(param_2);
            if ((uVar3 & 0x80) == 0) break;
            local_24 = local_24 + ((uVar3 & 0x7f) << (uVar1 & 0xff));
            uVar1 = uVar1 + 7;
          }
          local_24 = local_24 + 0x204 + ((uVar3 & 0x7f) << (uVar1 & 0xff));
          goto LAB_00013b20;
        }
        if (uVar1 == 0xb3) {
          FUN_00013904(param_2);
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
        FUN_00013904(param_2);
        uVar2 = 3;
      }
      else if (uVar1 == 199) {
        uVar1 = FUN_00013904(param_2);
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
            FUN_00013904(param_2);
          }
          else {
            if (uVar1 != 0xc9) {
              return 9;
            }
            FUN_00013904(param_2);
          }
          goto LAB_00013d24;
        }
        uVar2 = 3;
      }
    }
    else {
      if ((uVar1 & 0xf8) != 0xd0) {
        return 9;
      }
LAB_00013d24:
      uVar2 = 1;
    }
    iVar5 = FUN_000133f0(param_1,uVar2);
    if (iVar5 != 0) {
      return 9;
    }
  } while( true );
}



/* Function: FUN_00013d48 @ 00013d48 */

void FUN_00013d48(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  FUN_000139d0(param_2,&local_14,*(undefined1 *)(iVar1 + 7),local_10,param_1);
  return;
}



/* Function: strcpy @ 00016000 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_begin_cleanup @ 00016008 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_begin_cleanup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_call_unexpected @ 0001600c */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_call_unexpected(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: memcpy @ 00016010 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_finalize @ 00016014 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_finalize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: getuid @ 00016018 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

__uid_t getuid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: malloc @ 0001601c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * malloc(size_t __size)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: abort @ 00016020 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void abort(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __stack_chk_fail @ 00016024 */

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __cxa_type_match @ 00016028 */

/* WARNING: Control flow encountered bad instruction data */

void __cxa_type_match(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: memset @ 0001602c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: strcmp @ 00016030 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: __gnu_Unwind_Find_exidx @ 00016034 */

/* WARNING: Control flow encountered bad instruction data */

void __gnu_Unwind_Find_exidx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: sprintf @ 00016038 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: raise @ 0001603c */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int raise(int __sig)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Function: free @ 00016040 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void free(void *__ptr)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



